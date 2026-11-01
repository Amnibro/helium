# Generates small glTF test assets from scratch (struct packing per the glTF 2.0 spec).
import json, struct, base64, zlib, sys
def png_bytes(w,h,rgba):
    def chunk(t,d): return struct.pack(">I",len(d))+t+d+struct.pack(">I",zlib.crc32(t+d)&0xffffffff)
    raw=b"".join(b"\x00"+bytes(rgba[y*w*4:(y+1)*w*4]) for y in range(h))
    return b"\x89PNG\r\n\x1a\n"+chunk(b"IHDR",struct.pack(">IIBBBBB",w,h,8,6,0,0,0))+chunk(b"IDAT",zlib.compress(raw))+chunk(b"IEND",b"")
class B:
    def __init__(s): s.bin=bytearray(); s.views=[]; s.accs=[]
    def view(s,data,stride=None,target=None):
        while len(s.bin)%4: s.bin.append(0)
        v={"buffer":0,"byteOffset":len(s.bin),"byteLength":len(data)}
        if stride: v["byteStride"]=stride
        s.bin+=data; s.views.append(v); return len(s.views)-1
    def acc(s,fmt,ctype,typ,vals,minmax=False,normalized=False,stride=None):
        n={"SCALAR":1,"VEC2":2,"VEC3":3,"VEC4":4,"MAT4":16}[typ]
        data=b"".join(struct.pack("<"+fmt*n,*v) if n>1 else struct.pack("<"+fmt,v) for v in vals)
        a={"bufferView":s.view(data),"componentType":ctype,"count":len(vals),"type":typ}
        if normalized: a["normalized"]=True
        if minmax and n == 1: a["min"]=[min(vals)]; a["max"]=[max(vals)]
        elif minmax:
            a["min"]=[min(v[i] for v in vals) for i in range(n)]; a["max"]=[max(v[i] for v in vals) for i in range(n)]
        s.accs.append(a); return len(s.accs)-1
b=B()
# cube: 24 verts
faces=[((1,0,0),(0,0,-1)),((-1,0,0),(0,0,1)),((0,1,0),(1,0,0)),((0,-1,0),(1,0,0)),((0,0,1),(1,0,0)),((0,0,-1),(-1,0,0))]
P=[];N=[];T=[];UV=[];I=[]
for nrm,tan in faces:
    n=nrm; t=tan; bt=(n[1]*t[2]-n[2]*t[1],n[2]*t[0]-n[0]*t[2],n[0]*t[1]-n[1]*t[0])
    base=len(P)
    for (u,v) in [(0,0),(1,0),(1,1),(0,1)]:
        su,sv=u*2-1,v*2-1
        P.append(tuple(0.5*(n[i]+su*t[i]+sv*bt[i]) for i in range(3))); N.append(n); T.append(t+(1.0,)); UV.append((u,1-v))
    I+= [base,base+1,base+2,base,base+2,base+3]
pos=b.acc("f",5126,"VEC3",P,True); nrm=b.acc("f",5126,"VEC3",N); tan=b.acc("f",5126,"VEC4",T); uv=b.acc("H",5123,"VEC2",[(int(u*65535),int(v*65535)) for u,v in UV],normalized=True)
idx=b.acc("H",5123,"SCALAR",I)
# texture 4x4 checker
px=[]
for y in range(4):
    for x in range(4): px+= [255,64,32,255] if (x+y)%2 else [240,240,240,255]
img=b.view(png_bytes(4,4,px))
# skinned strip: 2 joints, 6 verts, triangle strip, no normals (flat path), colors vec3 ubyte normalized
SP=[(x*0.5,y,0.0) for y in (0.0,1.0,2.0) for x in (-1,1)]
sp=b.acc("f",5126,"VEC3",SP,True)
sj=b.acc("B",5121,"VEC4",[(0,1,0,0)]*6)
sw=b.acc("B",5121,"VEC4",[(255,0,0,0),(255,0,0,0),(128,127,0,0),(128,127,0,0),(0,255,0,0),(0,255,0,0)],normalized=True)
sc=b.acc("B",5121,"VEC3",[(255,0,0)]*6,normalized=True)
# morph target position deltas via sparse accessor without bufferView
ivw=b.view(struct.pack("<2H",4,5)); vvw=b.view(struct.pack("<6f",0,0.5,0,0,0.5,0))
b.accs.append({"componentType":5126,"count":6,"type":"VEC3","sparse":{"count":2,"indices":{"bufferView":ivw,"componentType":5123},"values":{"bufferView":vvw}}}); morph=len(b.accs)-1
ibm=b.acc("f",5126,"MAT4",[tuple([1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1]),tuple([1,0,0,0, 0,1,0,0, 0,0,1,0, 0,-1,0,1])])
times=b.acc("f",5126,"SCALAR",[0.0,1.0,2.0],True)
rots=b.acc("h",5122,"VEC4",[(0,0,0,32767),(0,0,23170,23170),(0,0,32767,0)],normalized=True)
tr=b.acc("f",5126,"VEC3",[(0,0,0),(0,1,0),(0,2,0)])
# cubic: in-tangent, value, out-tangent per key
sc3=b.acc("f",5126,"VEC3",[(0,0,0),(1,1,1),(0,0,0), (0,0,0),(2,2,2),(0,0,0), (0,0,0),(1,1,1),(0,0,0)])
wt=b.acc("f",5126,"SCALAR",[0.0,1.0,0.0])
g={"asset":{"version":"2.0","generator":"helium gfx test"},"scene":0,
 "scenes":[{"nodes":[0,1,3]}],
 "nodes":[{"name":"cube","mesh":0,"translation":[0,0.5,0]},
          {"name":"root","children":[2]},
          {"name":"bone","translation":[0,1,0],"rotation":[0,0,0,1]},
          {"name":"strip","mesh":1,"skin":0,"weights":[0.25]}],
 "meshes":[{"name":"cube","primitives":[{"attributes":{"POSITION":pos,"NORMAL":nrm,"TANGENT":tan,"TEXCOORD_0":uv},"indices":idx,"material":0}]},
           {"name":"strip","weights":[0.0],"primitives":[{"attributes":{"POSITION":sp,"JOINTS_0":sj,"WEIGHTS_0":sw,"COLOR_0":sc},"mode":5,"material":1,"targets":[{"POSITION":morph}]},{"attributes":{"POSITION":sp},"mode":1}]}],
 "materials":[{"name":"checker","pbrMetallicRoughness":{"baseColorTexture":{"index":0},"metallicFactor":0.0,"roughnessFactor":0.6}},
              {"name":"glow","pbrMetallicRoughness":{"baseColorFactor":[1,0.5,0.2,0.5]},"emissiveFactor":[1,0.5,0],"alphaMode":"BLEND","doubleSided":True,"extensions":{"KHR_materials_emissive_strength":{"emissiveStrength":4.0}}}],
 "textures":[{"source":0,"sampler":0}],"samplers":[{"magFilter":9728,"minFilter":9728,"wrapS":33071}],
 "images":[{"bufferView":img,"mimeType":"image/png"}],
 "skins":[{"name":"rig","joints":[1,2],"inverseBindMatrices":ibm,"skeleton":1}],
 "animations":[{"name":"wave","samplers":[{"input":times,"output":rots},{"input":times,"output":tr,"interpolation":"STEP"},{"input":times,"output":sc3,"interpolation":"CUBICSPLINE"},{"input":times,"output":wt}],
   "channels":[{"sampler":0,"target":{"node":2,"path":"rotation"}},{"sampler":1,"target":{"node":1,"path":"translation"}},{"sampler":2,"target":{"node":0,"path":"scale"}},{"sampler":3,"target":{"node":3,"path":"weights"}}]}],
 "bufferViews":b.views,"accessors":b.accs}
def glb(g,binb):
    g=dict(g); g["buffers"]=[{"byteLength":len(binb)}]
    js=json.dumps(g,separators=(",",":")).encode()
    while len(js)%4: js+=b" "
    bb=bytes(binb)
    while len(bb)%4: bb+=b"\0"
    body=struct.pack("<II",len(js),0x4E4F534A)+js+struct.pack("<II",len(bb),0x004E4942)+bb
    return struct.pack("<III",0x46546C67,2,12+len(body))+body
out=sys.argv[1]
open(out+"/scene.glb","wb").write(glb(g,b.bin))
g2=dict(g); g2["buffers"]=[{"byteLength":len(b.bin),"uri":"data:application/octet-stream;base64,"+base64.b64encode(bytes(b.bin)).decode()}]
open(out+"/scene_datauri.gltf","w").write(json.dumps(g2))
g3=dict(g); g3["buffers"]=[{"byteLength":len(b.bin),"uri":"scene%20data.bin"}]
open(out+"/scene_ext.gltf","w").write(json.dumps(g3)); open(out+"/scene data.bin","wb").write(bytes(b.bin))
print(len(glb(g,b.bin)))
