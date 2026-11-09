import ctypes as C, sys
hb=C.CDLL('libharfbuzz.so.0')
class Info(C.Structure): _fields_=[('codepoint',C.c_uint32),('mask',C.c_uint32),('cluster',C.c_uint32),('v1',C.c_uint32),('v2',C.c_uint32)]
class Pos(C.Structure): _fields_=[('xa',C.c_int32),('ya',C.c_int32),('xo',C.c_int32),('yo',C.c_int32),('v',C.c_uint32)]
class Feat(C.Structure): _fields_=[('tag',C.c_uint32),('value',C.c_uint32),('start',C.c_uint),('end',C.c_uint)]
for f in ['hb_blob_create_from_file','hb_face_create','hb_font_create','hb_buffer_create']: getattr(hb,f).restype=C.c_void_p
hb.hb_buffer_get_glyph_infos.restype=C.POINTER(Info); hb.hb_buffer_get_glyph_positions.restype=C.POINTER(Pos)
blob=hb.hb_blob_create_from_file(sys.argv[1].encode()); face=hb.hb_face_create(C.c_void_p(blob),0); font=hb.hb_font_create(C.c_void_p(face))
fs=(Feat*7)()
for i,t in enumerate([b'-calt',b'-liga',b'-clig',b'-dlig',b'-ccmp',b'-locl',b'kern']): hb.hb_feature_from_string(t,-1,C.byref(fs[i]))
def run(t):
	b=hb.hb_buffer_create(); hb.hb_buffer_add_utf8(C.c_void_p(b),t.encode(),-1,0,-1); hb.hb_buffer_guess_segment_properties(C.c_void_p(b))
	hb.hb_shape(C.c_void_p(font),C.c_void_p(b),fs,7); n=C.c_uint(); inf=hb.hb_buffer_get_glyph_infos(C.c_void_p(b),C.byref(n)); pos=hb.hb_buffer_get_glyph_positions(C.c_void_p(b),C.byref(n))
	r=[(inf[i].codepoint,pos[i].xa,pos[i].xo) for i in range(n.value)]; hb.hb_buffer_destroy(C.c_void_p(b)); return r
chars=[chr(c) for c in list(range(33,127))+list(range(161,384)) if c!=173]
for a in chars:
	single=run(a)
	for b in chars:
		r=run(a+b)
		if len(r)!=2 or r[0][0]!=single[0][0]: continue
		k=r[0][1]-single[0][1]+r[1][2]
		if k: print(ord(a),ord(b),k)
