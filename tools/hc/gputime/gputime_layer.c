// gputime_layer.c: a minimal Vulkan layer that measures GPU time per queue submit with
// timestamp queries, for hc/test/gfx timing (SDL3's GPU API has no timestamp queries).
//
// Every primary command buffer gets a top-of-pipe timestamp when it begins and a
// bottom-of-pipe timestamp when it ends. When the application waits (vkWaitForFences,
// vkQueueWaitIdle, vkDeviceWaitIdle) the layer reads the timestamps of every submit made
// since the last wait and appends one line per submit to the file named by
// HELIUM_GPUTIME:
//     submit <command buffers> <gpu ns from first begin to last end>
// Single device, single process, test use only. Written for Helium from the Vulkan
// specification (layer interface, VkQueryPool, vkCmdWriteTimestamp).
#include <vulkan/vulkan.h>
#include <vulkan/vk_layer.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXPORT __attribute__((visibility("default")))
#define SLOTS 4096
#define PEND 4096
#define MAXCB 64

static pthread_mutex_t mu = PTHREAD_MUTEX_INITIALIZER;
static PFN_vkGetInstanceProcAddr next_gipa;
static PFN_vkGetDeviceProcAddr next_gdpa;
static PFN_vkDestroyInstance next_destroy_instance;
static PFN_vkGetPhysicalDeviceProperties next_props;
static PFN_vkDestroyDevice next_destroy_device;
static PFN_vkAllocateCommandBuffers next_alloc;
static PFN_vkBeginCommandBuffer next_begin;
static PFN_vkEndCommandBuffer next_end;
static PFN_vkQueueSubmit next_submit;
static PFN_vkQueueSubmit2 next_submit2;
static PFN_vkQueueSubmit2 next_submit2khr;
static PFN_vkWaitForFences next_wait_fences;
static PFN_vkQueueWaitIdle next_queue_idle;
static PFN_vkDeviceWaitIdle next_device_idle;
static PFN_vkCmdResetQueryPool cmd_reset;
static PFN_vkCmdWriteTimestamp cmd_stamp;
static PFN_vkGetQueryPoolResults get_results;
static PFN_vkDestroyQueryPool destroy_pool;

static VkDevice dev;
static VkQueryPool pool;
static double period = 1.0;  // ns per tick
static unsigned next_slot;
static FILE *out;

// command buffer -> slot (open addressing), secondaries marked with slot -2
static VkCommandBuffer cb_key[SLOTS * 2];
static int cb_slot[SLOTS * 2];
static int cb_find(VkCommandBuffer cb, int insert) {
	size_t h = ((size_t)cb >> 4) * 2654435761u % (SLOTS * 2);
	for (int n = 0; n < SLOTS * 2; n++, h = (h + 1) % (SLOTS * 2)) {
		if (cb_key[h] == cb) return (int)h;
		if (cb_key[h] == 0) { if (!insert) return -1; cb_key[h] = cb; cb_slot[h] = -1; return (int)h; }
	}
	return -1;
}

// submits waiting to be read: their slots in order
static int pend_n[PEND];
static int pend_slot[PEND][MAXCB];
static int pend_count;

static void drain(void) {
	for (int p = 0; p < pend_count; p++) {
		unsigned long long lo = ~0ull, hi = 0;
		int ok = 0;
		for (int i = 0; i < pend_n[p]; i++) {
			unsigned long long t[2] = {0, 0};
			if (get_results(dev, pool, (uint32_t)pend_slot[p][i] * 2, 2, sizeof t, t, sizeof t[0], VK_QUERY_RESULT_64_BIT | VK_QUERY_RESULT_WAIT_BIT) != VK_SUCCESS) continue;
			if (t[0] < lo) lo = t[0];
			if (t[1] > hi) hi = t[1];
			ok = 1;
		}
		if (out && ok && pend_n[p] > 0) fprintf(out, "submit %d %.0f\n", pend_n[p], (double)(hi - lo) * period);
	}
	pend_count = 0;
	if (out) fflush(out);
}

static void add_submit(uint32_t n, const VkCommandBuffer *cbs, const VkCommandBufferSubmitInfo *infos) {
	if (pend_count == PEND) drain();
	int k = 0;
	for (uint32_t i = 0; i < n && k < MAXCB; i++) {
		VkCommandBuffer cb = cbs ? cbs[i] : infos[i].commandBuffer;
		int h = cb_find(cb, 0);
		if (h >= 0 && cb_slot[h] >= 0) pend_slot[pend_count][k++] = cb_slot[h];
	}
	pend_n[pend_count++] = k;
}

static VKAPI_ATTR VkResult VKAPI_CALL l_AllocateCommandBuffers(VkDevice d, const VkCommandBufferAllocateInfo *ai, VkCommandBuffer *cbs) {
	VkResult r = next_alloc(d, ai, cbs);
	if (r == VK_SUCCESS && ai->level == VK_COMMAND_BUFFER_LEVEL_SECONDARY) {
		pthread_mutex_lock(&mu);
		for (uint32_t i = 0; i < ai->commandBufferCount; i++) { int h = cb_find(cbs[i], 1); if (h >= 0) cb_slot[h] = -2; }
		pthread_mutex_unlock(&mu);
	}
	return r;
}

static VKAPI_ATTR VkResult VKAPI_CALL l_BeginCommandBuffer(VkCommandBuffer cb, const VkCommandBufferBeginInfo *bi) {
	VkResult r = next_begin(cb, bi);
	if (r != VK_SUCCESS || !pool) return r;
	pthread_mutex_lock(&mu);
	int h = cb_find(cb, 1);
	if (h >= 0 && cb_slot[h] != -2) {
		int s = (int)(next_slot++ % SLOTS);
		cb_slot[h] = s;
		cmd_reset(cb, pool, (uint32_t)s * 2, 2);
		cmd_stamp(cb, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, pool, (uint32_t)s * 2);
	}
	pthread_mutex_unlock(&mu);
	return r;
}

static VKAPI_ATTR VkResult VKAPI_CALL l_EndCommandBuffer(VkCommandBuffer cb) {
	if (pool) {
		pthread_mutex_lock(&mu);
		int h = cb_find(cb, 0);
		if (h >= 0 && cb_slot[h] >= 0) cmd_stamp(cb, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, pool, (uint32_t)cb_slot[h] * 2 + 1);
		pthread_mutex_unlock(&mu);
	}
	return next_end(cb);
}

static VKAPI_ATTR VkResult VKAPI_CALL l_QueueSubmit(VkQueue q, uint32_t n, const VkSubmitInfo *si, VkFence f) {
	pthread_mutex_lock(&mu);
	for (uint32_t i = 0; i < n; i++) add_submit(si[i].commandBufferCount, si[i].pCommandBuffers, NULL);
	pthread_mutex_unlock(&mu);
	return next_submit(q, n, si, f);
}

static VkResult submit2(PFN_vkQueueSubmit2 next, VkQueue q, uint32_t n, const VkSubmitInfo2 *si, VkFence f) {
	pthread_mutex_lock(&mu);
	for (uint32_t i = 0; i < n; i++) add_submit(si[i].commandBufferInfoCount, NULL, si[i].pCommandBufferInfos);
	pthread_mutex_unlock(&mu);
	return next(q, n, si, f);
}
static VKAPI_ATTR VkResult VKAPI_CALL l_QueueSubmit2(VkQueue q, uint32_t n, const VkSubmitInfo2 *si, VkFence f) { return submit2(next_submit2, q, n, si, f); }
static VKAPI_ATTR VkResult VKAPI_CALL l_QueueSubmit2KHR(VkQueue q, uint32_t n, const VkSubmitInfo2 *si, VkFence f) { return submit2(next_submit2khr, q, n, si, f); }

static VKAPI_ATTR VkResult VKAPI_CALL l_WaitForFences(VkDevice d, uint32_t n, const VkFence *f, VkBool32 all, uint64_t timeout) {
	VkResult r = next_wait_fences(d, n, f, all, timeout);
	if (r == VK_SUCCESS) { pthread_mutex_lock(&mu); drain(); pthread_mutex_unlock(&mu); }
	return r;
}
static VKAPI_ATTR VkResult VKAPI_CALL l_QueueWaitIdle(VkQueue q) {
	VkResult r = next_queue_idle(q);
	if (r == VK_SUCCESS) { pthread_mutex_lock(&mu); drain(); pthread_mutex_unlock(&mu); }
	return r;
}
static VKAPI_ATTR VkResult VKAPI_CALL l_DeviceWaitIdle(VkDevice d) {
	VkResult r = next_device_idle(d);
	if (r == VK_SUCCESS) { pthread_mutex_lock(&mu); drain(); pthread_mutex_unlock(&mu); }
	return r;
}

static VKAPI_ATTR void VKAPI_CALL l_DestroyDevice(VkDevice d, const VkAllocationCallbacks *a) {
	pthread_mutex_lock(&mu);
	if (d == dev && pool) { destroy_pool(d, pool, NULL); pool = 0; pend_count = 0; }
	if (out) { fclose(out); out = NULL; }
	pthread_mutex_unlock(&mu);
	next_destroy_device(d, a);
}

static VKAPI_ATTR VkResult VKAPI_CALL l_CreateInstance(const VkInstanceCreateInfo *ci, const VkAllocationCallbacks *a, VkInstance *inst) {
	VkLayerInstanceCreateInfo *li = (VkLayerInstanceCreateInfo *)ci->pNext;
	while (li && !(li->sType == VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO && li->function == VK_LAYER_LINK_INFO)) li = (VkLayerInstanceCreateInfo *)li->pNext;
	if (!li) return VK_ERROR_INITIALIZATION_FAILED;
	next_gipa = li->u.pLayerInfo->pfnNextGetInstanceProcAddr;
	li->u.pLayerInfo = li->u.pLayerInfo->pNext;
	PFN_vkCreateInstance create = (PFN_vkCreateInstance)next_gipa(VK_NULL_HANDLE, "vkCreateInstance");
	VkResult r = create(ci, a, inst);
	if (r != VK_SUCCESS) return r;
	next_destroy_instance = (PFN_vkDestroyInstance)next_gipa(*inst, "vkDestroyInstance");
	next_props = (PFN_vkGetPhysicalDeviceProperties)next_gipa(*inst, "vkGetPhysicalDeviceProperties");
	return r;
}

static VKAPI_ATTR VkResult VKAPI_CALL l_CreateDevice(VkPhysicalDevice pd, const VkDeviceCreateInfo *ci, const VkAllocationCallbacks *a, VkDevice *d) {
	VkLayerDeviceCreateInfo *li = (VkLayerDeviceCreateInfo *)ci->pNext;
	while (li && !(li->sType == VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO && li->function == VK_LAYER_LINK_INFO)) li = (VkLayerDeviceCreateInfo *)li->pNext;
	if (!li) return VK_ERROR_INITIALIZATION_FAILED;
	PFN_vkGetInstanceProcAddr gipa = li->u.pLayerInfo->pfnNextGetInstanceProcAddr;
	next_gdpa = li->u.pLayerInfo->pfnNextGetDeviceProcAddr;
	li->u.pLayerInfo = li->u.pLayerInfo->pNext;
	PFN_vkCreateDevice create = (PFN_vkCreateDevice)gipa(VK_NULL_HANDLE, "vkCreateDevice");
	VkResult r = create(pd, ci, a, d);
	if (r != VK_SUCCESS) return r;
#define G(var, name) var = (void *)next_gdpa(*d, name)
	G(next_destroy_device, "vkDestroyDevice");
	G(next_alloc, "vkAllocateCommandBuffers");
	G(next_begin, "vkBeginCommandBuffer");
	G(next_end, "vkEndCommandBuffer");
	G(next_submit, "vkQueueSubmit");
	G(next_submit2, "vkQueueSubmit2");
	G(next_submit2khr, "vkQueueSubmit2KHR");
	G(next_wait_fences, "vkWaitForFences");
	G(next_queue_idle, "vkQueueWaitIdle");
	G(next_device_idle, "vkDeviceWaitIdle");
	G(cmd_reset, "vkCmdResetQueryPool");
	G(cmd_stamp, "vkCmdWriteTimestamp");
	G(get_results, "vkGetQueryPoolResults");
	G(destroy_pool, "vkDestroyQueryPool");
	PFN_vkCreateQueryPool create_pool = (PFN_vkCreateQueryPool)next_gdpa(*d, "vkCreateQueryPool");
	VkPhysicalDeviceProperties p;
	next_props(pd, &p);
	period = p.limits.timestampPeriod;
	pthread_mutex_lock(&mu);
	if (!dev) {
		dev = *d;
		VkQueryPoolCreateInfo qi = {VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO, NULL, 0, VK_QUERY_TYPE_TIMESTAMP, SLOTS * 2, 0};
		if (create_pool(*d, &qi, NULL, &pool) != VK_SUCCESS) pool = 0;
		const char *path = getenv("HELIUM_GPUTIME");
		if (path && *path) out = fopen(path, "a");
		if (out) { fprintf(out, "device %s timestampPeriod %g ns\n", p.deviceName, (double)period); fflush(out); }
	}
	pthread_mutex_unlock(&mu);
	return r;
}

static PFN_vkVoidFunction device_hook(const char *n) {
#define H(name) if (!strcmp(n, "vk" #name)) return (PFN_vkVoidFunction)l_##name
	H(DestroyDevice); H(AllocateCommandBuffers); H(BeginCommandBuffer); H(EndCommandBuffer);
	H(QueueSubmit); H(QueueSubmit2); H(QueueSubmit2KHR); H(WaitForFences); H(QueueWaitIdle); H(DeviceWaitIdle);
	return NULL;
}

EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL helium_gputime_GetDeviceProcAddr(VkDevice d, const char *n) {
	PFN_vkVoidFunction f = device_hook(n);
	if (f) {
		// only hand out hooks for functions the driver provides
		if ((!strcmp(n, "vkQueueSubmit2") && !next_submit2) || (!strcmp(n, "vkQueueSubmit2KHR") && !next_submit2khr)) return next_gdpa(d, n);
		return f;
	}
	return next_gdpa(d, n);
}

EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL helium_gputime_GetInstanceProcAddr(VkInstance i, const char *n) {
	if (!strcmp(n, "vkGetInstanceProcAddr")) return (PFN_vkVoidFunction)helium_gputime_GetInstanceProcAddr;
	if (!strcmp(n, "vkGetDeviceProcAddr")) return (PFN_vkVoidFunction)helium_gputime_GetDeviceProcAddr;
	if (!strcmp(n, "vkCreateInstance")) return (PFN_vkVoidFunction)l_CreateInstance;
	if (!strcmp(n, "vkCreateDevice")) return (PFN_vkVoidFunction)l_CreateDevice;
	PFN_vkVoidFunction f = device_hook(n);
	if (f) return f;
	return next_gipa ? next_gipa(i, n) : NULL;
}
