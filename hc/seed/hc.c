#include "hrt.h"
typedef struct A25 A25;
typedef struct A62 A62;
typedef struct A101 A101;
typedef struct S0 S0;
typedef struct S1 S1;
typedef struct S2 S2;
typedef struct S4 S4;
typedef struct L49 L49;
typedef struct S3 S3;
typedef struct A39 A39;
typedef struct S5 S5;
typedef struct S6 S6;
typedef struct M56 M56;
typedef struct S8 S8;
typedef struct S9 S9;
typedef struct L66 L66;
typedef struct M55 M55;
typedef struct M57 M57;
typedef struct S10 S10;
typedef struct S7 S7;
typedef struct L73 L73;
typedef struct S11 S11;
typedef struct M78 M78;
typedef struct S12 S12;
typedef struct S13 S13;
typedef struct L84 L84;
typedef struct S14 S14;
typedef struct L88 L88;
typedef struct L89 L89;
typedef struct S15 S15;
typedef struct M94 M94;
typedef struct L97 L97;
typedef struct L98 L98;
typedef struct L100 L100;
typedef struct L99 L99;
#pragma pack(push, 1)
struct A25 { hsl e[49]; };
struct A62 { hsl e[8]; };
struct A101 { double e[23]; };
struct S0 { int32_t s_; int32_t n_; };
struct S1 { uint8_t k_; uint8_t s_; uint16_t fl_; int32_t a_; int32_t c_; int32_t l_; int32_t n_; int64_t b_; };
struct S2 { int32_t s_; int32_t n_; int32_t name_; bool amni_; };
struct S4 { uint8_t k_; uint8_t op_; uint16_t fl_; int32_t t_; int32_t a_; int32_t b_; int32_t c_; int32_t d_; int32_t e_; int32_t s_; int32_t l_; int32_t n_; };
struct L49 { uint16_t n; uint8_t e[1024]; };
struct S3 { uint8_t k_; bool ml_; bool uns_; uint16_t f_; int32_t line_; int32_t s_; int32_t n_; int32_t w_; int64_t v_; };
struct A39 { hsl e[51]; };
struct S5 { uint8_t k_; int32_t node_; int32_t file_; int32_t next_; int32_t name_; };
struct S6 { int32_t node_; int32_t lo_; int32_t hi_; int32_t ab_; int32_t par_; int32_t cfn_; int32_t g0_; int32_t gn_; int32_t ret_; int32_t p0_; int32_t pn_; uint8_t st_; bool lr_; int32_t blk_; int32_t bown_; int32_t name_; uint16_t fl_; bool rinf_; bool tg_; };
struct M56 { int64_t r0; bool r1; };
struct S8 { int32_t node_; int32_t ta_; int32_t tn_; int32_t v0_; int32_t vnum_; uint8_t cls_; uint8_t done_; uint8_t tagsz_; bool flat_; int64_t size_; int32_t name_; };
struct S9 { int32_t name_; int32_t f0_; int32_t fnum_; int32_t si_; int64_t size_; bool haspay_; };
struct L66 { uint8_t n; int32_t e[16]; };
struct M55 { int64_t r0; int64_t r1; };
struct M57 { int64_t r0; int64_t r1; bool r2; };
struct S10 { int32_t node_; int32_t ta_; int32_t tn_; int32_t f0_; int32_t fnum_; uint8_t cls_; uint8_t done_; bool flat_; bool zero_; int64_t size_; int32_t name_; };
struct S7 { int32_t name_; int32_t ty_; };
struct S11 { int32_t name_; int32_t ty_; int32_t def_; uint16_t fl_; int32_t padn_; int64_t off_; };
struct L73 { uint16_t n; S11 e[256]; };
struct M78 { int64_t r0; bool r1; bool r2; };
struct S12 { int32_t name_; int32_t ty_; uint16_t fl_; int32_t cfn_; int32_t own_; int32_t node_; int32_t cnt_; };
struct S13 { int32_t inst_; int32_t lv_; };
struct L84 { uint8_t n; int32_t e[1]; };
struct S14 { int32_t name_; int32_t node_; int32_t inst_; int32_t own_; };
struct L88 { uint8_t n; int32_t e[128]; };
struct L89 { uint8_t n; int32_t e[64]; };
struct S15 { int32_t caller_; int32_t callee_; };
struct M94 { int64_t r0; int64_t r1; int64_t r2; };
struct L97 { uint16_t n; uint8_t e[256]; };
struct L98 { uint8_t n; uint8_t e[128]; };
struct L100 { uint8_t n; uint8_t e[64]; };
struct L99 { uint8_t n; uint8_t e[32]; };
#pragma pack(pop)
static void f1_main(void);
static bool f5_load_program(hsl root_3);
static void f6_parse_init(void);
static void f7_lex_init(void);
static int64_t f8_intern(hsl s_5);
static uint64_t f9_hash(hsl s_9);
static hsl f10_nm(int64_t id_15);
static void f11_types_init(void);
static int64_t f12_tsimple(int64_t k_18, int64_t s_19);
static int64_t f13_tmk(S1 t_20);
static uint64_t f14_th(S1 t_24);
static uint64_t f15_hash_mix(uint64_t x_25);
static bool f16_teq(S1 x_32, S1 y_33);
static int64_t f17_t_int(int64_t s_35);
static int64_t f18_t_slice(int64_t e_36, bool cq_37);
static int64_t f19_try_load(hsl path_39);
static bool f21_parse_file(hsl path_44);
static bool f22_lex_file(hsl path_46);
static void f23_put(int64_t k_54, int64_t s_55, int64_t e_56, int64_t *c48, int64_t *c53);
static bool f25_lerr(int64_t f_60, int64_t line_61, hsl m_62);
static bool f26_dig(uint8_t c_66);
static bool f27_hexd(uint8_t c_68);
static int64_t f28_hexv(uint8_t c_72);
static bool f29_idc(uint8_t c_77);
static int64_t f30_esc(int64_t* p_80, int64_t f_81, int64_t line_82);
static int64_t f31_tk(void);
static void f32_ptop(void);
static void f33_nx(void);
static int64_t f34_ident(hsl ctx_106);
static hsl f35_cur_text(void);
static hsl f36_tok_text(int64_t t_109);
static hsl f37_tname(int64_t k_111);
static void f38_perr(hsl m_113);
static void f39_ex(int64_t k_116, hsl ctx_117);
static int64_t f40_mk(int64_t k_119, int64_t t_120);
static bool f41_is(int64_t k_122);
static bool f42_at_from(void);
static bool f43_at_word(int64_t w_125);
static int64_t f44_tkat(int64_t i_126);
static int64_t f45_min(int64_t a_127, int64_t b_128);
static bool f46_at_inline(void);
static bool f47_at_checkfree(void);
static bool f48_at_lut(void);
static int64_t f49_pfn(bool nested_130, int64_t cname_131, int64_t dylib_132);
static int64_t f50_declname(hsl ctx_137);
static int64_t f51_pgenerics(void);
static int64_t f52_wbeg(void);
static int64_t f53_ptype(void);
static int64_t f54_ptype_prim(void);
static bool f55_prim_tok(int64_t k_147);
static int64_t f56_qname(hsl ctx_150);
static int64_t f57_qcat(int64_t a_151, int64_t b_152);
static void f58_close_angle(hsl ctx_160);
static void f59_setl(int64_t n_161, int64_t m_162);
static int64_t f60_wend(int64_t m_164);
static int64_t f61_pexpr(void);
static int64_t f62_pif(void);
static int64_t f63_pscrut(void);
static int64_t f64_sub_begin(bool nosl_184);
static void f65_sub_end(int64_t s_188);
static int64_t f66_pblock(hsl ctx_190);
static void f67_pbody(int64_t b_193);
static bool f68_pstmt(int64_t b_196);
static int64_t f69_pcfor(int64_t mode_198);
static void f70_pinits(int64_t n_208, bool frag_209);
static void f71_parms(int64_t n_215);
static int64_t f72_ppattern(void);
static int64_t f73_pbound(void);
static int64_t f74_pvdecl(bool glob_238);
static bool f75_amni_type(void);
static void f76_pguard(int64_t b_248);
static int64_t f77_pmulti(int64_t first_260, int64_t st_261);
static int64_t f78_pmatch(void);
static int64_t f79_pfor(void);
static int64_t f80_pbin(int64_t minp_304);
static int64_t f81_pun(void);
static int64_t f82_ppost(void);
static int64_t f83_pprim(void);
static int64_t f84_parray(void);
static int64_t f85_try_tyargs(void);
static int64_t f86_pcall(int64_t callee_333, int64_t tyargs_334, int64_t st_335);
static int64_t f87_pfunval(void);
static void f88_set_end(int64_t n_350);
static int64_t f89_pslit(int64_t ty_355, int64_t st_356);
static int64_t f90_kid(int64_t n_361, int64_t i_362);
static int64_t f91_pindex(int64_t obj_369);
static int64_t f92_binprec(int64_t k_384);
static int64_t f93_lenstore(void);
static int64_t f94_pstruct(void);
static void f95_pfields(int64_t n_418, hsl ctx_419);
static int64_t f96_penum(void);
static void f97_collect(int64_t file_440, int64_t t0_441, int64_t t1_442);
static int64_t f98_qual(int64_t ns_447, int64_t name_448);
static void f99_dadd(int64_t k_450, int64_t node_451, int64_t file_452, int64_t name_453);
static L49 f100_lib_path(hsl name_459);
static int64_t f101_load_import(int64_t name_463, int64_t from_464, int64_t t_465);
static void f102_derr(int64_t t_470, hsl m_471);
static int64_t f103_max(int64_t a_472, int64_t b_473);
static bool f104_check_program(void);
static int64_t f105_new_inst(int64_t node_477, int64_t lo_478, int64_t hi_479, int64_t par_480);
static int64_t f106_lookup(int64_t name_483, int64_t ns_484, int64_t k_485);
static int64_t f107_dmap(int64_t name_486);
static void f108_cerr(int64_t n_490, hsl m_491);
static int64_t f109_global_type(int64_t d_495);
static int64_t f110_ns_of(int64_t n_501);
static int64_t f111_node_file(int64_t n_502);
static int64_t f112_file_ns(int64_t f_503);
static int64_t f113_rtype(int64_t n_504, int64_t ns_505);
static int64_t f114_prim_type(int64_t k_508);
static int64_t f115_int_storage_of_tok(int64_t k_509);
static int64_t f116_lookup_q(int64_t q_515, int64_t ns_516, int64_t k_517);
static M55 f117_split_q(int64_t q_518);
static int64_t f118_t_rel(int64_t e_525, int64_t fl_526, int64_t w_527, int64_t pool_528);
static int64_t f119_t_ref(int64_t e_529, int64_t fl_530);
static M56 f120_ceval(int64_t n_533, int64_t ns_534);
static M57 f121_ceval3(int64_t n_535, int64_t ns_536);
static int64_t f122_cwrap(int64_t v_543, int64_t c_544);
static int64_t f123_t_arr(int64_t e_585, int64_t ak_586, int64_t size_587, int64_t ls_588);
static int64_t f124_lim_lenstore(int64_t cap_591);
static int64_t f125_t_variant(int64_t ei_596, int64_t vi_597);
static hrv f126_ty_name(int64_t t_599);
static void f127_ty_name_into(int64_t t_601, hrv* out_602);
static void f128_ls_kind_name(int64_t s_605, hrv* out_606);
static void f129_targs_into(int64_t l_608, int64_t n_609, hrv* out_610);
static int64_t f130_gb_find(int64_t name_615);
static int64_t f131_inst_struct(int64_t node_622, hsl args_623);
static void f132_gen_names(int64_t gl_631, L66* out_632);
static int64_t f133_fields_into(int64_t node_636, int64_t ns_637);
static int64_t f134_t_struct(int64_t si_645);
static int64_t f135_inst_enum(int64_t node_646, hsl args_647);
static int64_t f136_t_enum(int64_t ei_666, bool vm_667);
static int64_t f137_ck(int64_t n_671, int64_t want_672);
static int64_t f138_set_t(int64_t n_675, int64_t t_676);
static int64_t f139_aix(int64_t n_677);
static bool f140_conv(int64_t n_681, int64_t t_682);
static int64_t f141_at(int64_t n_683);
static void f142_set_cv(int64_t n_687, int64_t t_688);
static int64_t f143_tclass(int64_t t_689);
static void f144_si_layout(int64_t si_692);
static bool f145_tflat(int64_t t_702);
static void f146_ei_layout(int64_t ei_705);
static int64_t f147_pad_align(int64_t t_721);
static int64_t f148_isz(int64_t s_724);
static int64_t f149_tsize(int64_t t_727);
static int64_t f150_cv(int64_t n_736);
static bool f151_conv_ok(int64_t f_737, int64_t t_738, int64_t n_739);
static bool f152_widens(int64_t f_742, int64_t t_743);
static bool f153_is_signed(int64_t t_746);
static int64_t f154_ibits(int64_t t_749);
static M78 f155_cval(int64_t n_750);
static int64_t f156_rk(int64_t n_756);
static int64_t f157_rv(int64_t n_757);
static bool f158_int_fits(int64_t v_768, bool uns_769, int64_t t_770);
static int64_t f159_int_min(int64_t t_771);
static uint64_t f160_int_max_u(int64_t t_773);
static hrv f161_tn(int64_t t_777);
static void f162_commit(int64_t n_778, int64_t t_779);
static bool f163_is_pending(int64_t t_783);
static bool f164_is_byte_arr(int64_t t_789);
static bool f165_is_opt(int64_t t_792);
static int64_t f166_ck_id(int64_t n_793, int64_t want_794);
static int64_t f167_find_lv(int64_t name_796);
static bool f168_visible(int64_t own_799);
static bool f169_visible_in(int64_t own_800, int64_t cur_801);
static void f170_set_r(int64_t n_804, int64_t k_805, int64_t v_806);
static void f171_note_cap(int64_t v_808);
static bool f172_add_cap_one(int64_t cf_811, int64_t v_812);
static int64_t f173_const_of(int64_t d_817);
static bool f174_all_int(int64_t n_825);
static void f175_set_x(int64_t n_830, int64_t v_831);
static int64_t f176_ck_bin(int64_t n_833, int64_t want_834);
static void f177_narrow_push(int64_t c_840);
static void f178_narrow_pop(int64_t m_845);
static int64_t f179_deref(int64_t t_851);
static int64_t f180_leaf_kind(int64_t t_856);
static int64_t f181_leaf_type(int64_t t_866);
static int64_t f182_unify(int64_t n_875, int64_t a_876, int64_t b_877);
static int64_t f183_ck_un(int64_t n_889, int64_t want_890);
static int64_t f184_default_t(int64_t n_895);
static int64_t f185_ck_dot(int64_t n_916, int64_t want_917);
static int64_t f186_rtype_name_enum(int64_t de_923);
static int64_t f187_sfield(int64_t si_935, int64_t name_936);
static int64_t f188_decode_rel(int64_t ft_940);
static int64_t f189_ck_idx(int64_t n_944, int64_t want_945);
static int64_t f190_ck_slice(int64_t n_953, int64_t want_954);
static int64_t f191_ck_as(int64_t n_960, int64_t want_961);
static int64_t f192_ck_arr(int64_t n_966, int64_t want_967);
static int64_t f193_ck_block(int64_t n_975, int64_t want_976);
static int64_t f194_pre_decl_block_fns(int64_t b_980);
static void f195_sig_inst(int64_t i_985);
static int64_t f196_upname(int64_t p_995);
static int64_t f197_tlist(int64_t k_1001, hsl xs_1002, int64_t a_1003);
static bool f198_surely_void(int64_t fnode_1005);
static bool f199_has_valret(int64_t n_1009);
static void f200_cstmt(int64_t n_1015);
static void f201_ck_vdecl(int64_t n_1018);
static int64_t f202_fin_t(int64_t n_1031);
static int64_t f203_add_lv(int64_t name_1033, int64_t t_1034, int64_t fl_1035, int64_t node_1036);
static bool f204_is_fixed(int64_t t_1044);
static void f205_ck_assign(int64_t n_1046);
static void f206_decl_nested(int64_t n_1063);
static void f207_check_inst(int64_t i_1066);
static int64_t f208_ptype_of(int64_t i_1078, int64_t j_1079);
static bool f209_ends(int64_t n_1088);
static bool f210_has_break(int64_t n_1091);
static void f211_pop_block_fns(int64_t m_1099);
static int64_t f212_ck_if(int64_t n_1102, int64_t want_1103);
static int64_t f213_ck_while(int64_t n_1113);
static int64_t f214_ck_loop(int64_t n_1117, int64_t want_1118);
static int64_t f215_ck_for(int64_t n_1120);
static bool f216_is_bytes(int64_t t_1130);
static int64_t f217_ax(int64_t n_1134);
static int64_t f218_ck_match(int64_t n_1135, int64_t want_1136);
static int64_t f219_ck_ret(int64_t n_1169);
static int64_t f220_find_from_fn(int64_t name_1171);
static int64_t f221_ret_fn(void);
static int64_t f222_ck_break(int64_t n_1184);
static int64_t f223_ck_call(int64_t n_1188, int64_t want_1189);
static int64_t f224_find_nest(int64_t name_1195);
static int64_t f225_call_nested(int64_t n_1198, int64_t nf_1199);
static int64_t f226_ck_args(int64_t n_1201, int64_t a0n_1202, int64_t first_1203);
static void f227_pop_args(int64_t s_1210);
static void f228_note_caps_of(int64_t i_1211);
static void f229_note_edge(int64_t callee_1214);
static int64_t f230_block_binding(int64_t name_1216);
static int64_t f231_blk_gen(int64_t fnode_1220);
static int64_t f232_gen_list(int64_t fnode_1221);
static bool f233_is_blockparam(int64_t fnode_1225, int64_t gname_1226);
static bool f234_mentions(int64_t t_1229, int64_t g_1230);
static int64_t f235_call_block(int64_t n_1235, int64_t inst_1236);
static int64_t f236_deref_val(int64_t a_1243);
static int64_t f237_builtin_of(hsl name_1263);
static bool f238_user_format(int64_t n_1265);
static bool f239_is_grow(int64_t t_1267);
static int64_t f240_ck_builtin(int64_t n_1268, int64_t b_1269, int64_t recv_1270, int64_t want_1271);
static int64_t f241_arg(int64_t i_1274, int64_t *c1270, int64_t *c1268);
static void f242_hook_walk(int64_t t_1279);
static int64_t f243_hook_of(int64_t t_1283);
static M94 f244_resolve(int64_t n_1287, int64_t name_1288, int64_t ns_1289, int64_t a0_1290, int64_t an_1291, int64_t blk_1292, int64_t tyargs_1293, bool report_1294);
static void f245_cands_add(int64_t name_1296, int64_t ns_1297);
static bool f246_match_ty(int64_t tn0_1326, int64_t t0_1327, int64_t g0_1328);
static int64_t f247_pend_default(int64_t a_1341);
static int64_t f248_arg_rank(int64_t n_1354, int64_t a_1355, int64_t p_1356);
static bool f249_is_construct(int64_t n_1364);
static bool f250_untyped_any(int64_t f_1367);
static bool f251_is_std_node(int64_t node_1369);
static int64_t f252_get_inst(int64_t node_1380, int64_t b0_1381, int64_t bn_1382, int64_t blk_1383, int64_t bown_1384);
static bool f253_same_binds(int64_t i_1388, int64_t b0_1389, int64_t bn_1390);
static int64_t f254_call_fn(int64_t n_1426, int64_t name_1427, int64_t recv_1428, int64_t want_1429);
static int64_t f255_member_of(hsl name_1448);
static int64_t f256_ck_slit(int64_t n_1451, int64_t want_1452);
static bool f257_ORD_HAS(int64_t d_1475);
static void f258_propagate_calls(void);
static bool f259_gen_program(hrv* out_1487);
static void f260_ow(hsl s_1491);
static void f261_ct(int64_t t_1492);
static void f262_cbody(int64_t t_1493);
static void f263_cn_grow(void);
static hsl f264_cn(int64_t t_1496);
static void f265_cn_make(int64_t t_1497);
static void f266_fwd(int64_t s0_1506);
static void f267_fname_into(hrv* b_1518, int64_t name_1519);
static bool f268_is_res(int64_t t_1539);
static void f269_gxo(int64_t n_1540);
static void f270_gcv(int64_t n_1543, int64_t f_1544, int64_t t_1545);
static void f271_gx1(int64_t n_1546);
static bool f272_is_place(int64_t n_1547);
static int64_t f273_tmp(int64_t t_1552, bool clean_1553);
static void f274_ot(int64_t k_1555);
static void f275_gx0(int64_t n_1556);
static int64_t f276_fin_lit(int64_t n_1559);
static void f277_oint(int64_t v_1561, bool uns_1562, int64_t t_1563);
static void f278_gstr(int64_t n_1566);
static int64_t f279_fin(int64_t n_1567);
static hsl f280_tok_str(int64_t t_1571);
static void f281_cstr_lit(hsl s_1575);
static bool f282_is_fix(int64_t t_1577);
static bool f283_is_lim(int64_t t_1578);
static void f284_lv_expr(int64_t v_1580);
static bool f285_lv_isptr(int64_t v_1581);
static void f286_lv_name(int64_t v_1583);
static void f287_gerr(int64_t n_1585, hsl m_1586);
static void f288_gbin(int64_t n_1588);
static void f289_gx(int64_t n_1593);
static hsl f290_cmp_op(int64_t o_1600);
static void f291_gas(int64_t n_1601);
static void f292_gsl(int64_t n_1604, int64_t f_1605);
static int64_t f293_nt(void);
static void f294_oi(int64_t v_1609);
static void f295_gen_heq(int64_t t_1615);
static void f296_comp_pre(int64_t t_1619, bool fmt_1620);
static void f297_comp_one(int64_t t_1626, bool fmt_1627);
static bool f298_need_helper(int64_t t_1629);
static void f299_gen_hf(int64_t t_1631);
static void f300_hf_pre(int64_t t_1635);
static void f301_hh(hsl s_1638);
static void f302_fn_cname_to(hrv* b_1645, int64_t i_1646);
static void f303_hf_val(int64_t t_1657, hsl e_1658);
static void f304_heq_val(int64_t t_1701, hsl a_1702, hsl b_1703);
static bool f305_hsl_ty(int64_t t_1714);
static void f306_gxas(int64_t n_1715, int64_t t_1716);
static void f307_garith(int64_t o_1719, int64_t t0_1720, int64_t a_1721, int64_t b_1722, int64_t tv_1723, int64_t loc_1724);
static void f308_gopnd(int64_t n_1730, int64_t tv_1731);
static void f309_gen_hop(int64_t t_1732, int64_t o_1733, int64_t bt_1734);
static void f310_hop_body(int64_t t_1740, int64_t o_1741, hsl r_1742, hsl a_1743, hsl b_1744, bool sc_1745);
static hsl f311_ar_op(int64_t o_1747);
static void f312_wloc(int64_t n_1761);
static void f313_gun(int64_t n_1764);
static void f314_gen_hneg(int64_t t_1769);
static void f315_gidx(int64_t n_1783);
static void f316_gslice(int64_t n_1791);
static void f317_garr(int64_t n_1799);
static void f318_gslit(int64_t n_1806);
static void f319_gcall(int64_t n_1818);
static void f320_gbuiltin(int64_t n_1820);
static int64_t f321_arg(int64_t i_1826, int64_t *c1824, int64_t *c1820);
static void f322_gfmt(hsl o_1830, int64_t n_1831, int64_t t_1832, bool top_1833);
static void f323_fn_cname(int64_t i_1838);
static void f324_gaddr(int64_t n_1839);
static void f325_grecv_ptr(int64_t r_1846);
static void f326_esz(int64_t t_1860);
static void f327_heq_val_o(int64_t e_1870, int64_t p_1871);
static void f328_heq_o(int64_t e_1874, hsl a_1875, hsl b_1876);
static void f329_heq_pre(int64_t t_1877);
static bool f330_scalar_ty(int64_t t_1878);
static void f331_heq_val_s(int64_t e_1881, int64_t p_1882);
static void f332_heq_val_r(int64_t e_1885, int64_t p_1886);
static void f333_gblkcall(int64_t n_1889);
static void f334_gstmt(int64_t n_1901);
static void f335_gvdecl(int64_t n_1907);
static void f336_decl_lv(int64_t v_1915);
static void f337_gstmt1(int64_t n_1926);
static void f338_gassign(int64_t n_1929);
static int64_t f339_base_op(int64_t o_1942);
static void f340_gif(int64_t n_1945, int64_t res_1946);
static void f341_gblk(int64_t b_1950, int64_t res_1951, bool val_1952);
static void f342_gtail(int64_t tl_1954, int64_t res_1955);
static void f343_gwhile(int64_t n_1958);
static int64_t f344_lbl_push(int64_t res_1960);
static void f345_lbl_pop(int64_t l_1963);
static void f346_gloop(int64_t n_1964, int64_t res_1965);
static void f347_gfor(int64_t n_1967);
static void f348_gmatch(int64_t n_1982, int64_t res_1983);
static void f349_geblock(int64_t n_2005, int64_t res_2006);
static void f350_gret(int64_t n_2008);
static void f351_gmove(int64_t c_2014);
static bool f352_movable_local(int64_t c_2015);
static void f353_gdummy(void);
static void f354_gbreak(int64_t n_2026);
static bool f355_owned(int64_t n_2030);
static bool f356_is_ext(int64_t i_2034);
static void f357_ext_name(int64_t i_2039);
static void f358_gcall_args(int64_t n_2043, int64_t inst_2044, int64_t recv_2045);
static void f359_lv_addr(int64_t v_2057);
static void f360_glrcheck(void);
static void f361_gen_fn(int64_t i_2073);
static void f362_gsig(int64_t i_2076);
static hrv g492;
static hrv g910;
static A25 g853;
static hrv g911;
static hrv g908;
static int64_t g720;
static int64_t g721;
static int64_t g722;
static int64_t g723;
static int64_t g724;
static int64_t g725;
static int64_t g726;
static int64_t g727;
static int64_t g728;
static int64_t g729;
static hrv g550;
static int64_t g574;
static hrv g552;
static hrv g551;
static int64_t g557;
static int64_t g558;
static int64_t g559;
static int64_t g560;
static int64_t g561;
static int64_t g562;
static int64_t g563;
static int64_t g564;
static int64_t g565;
static int64_t g566;
static int64_t g567;
static int64_t g568;
static int64_t g569;
static int64_t g570;
static int64_t g571;
static int64_t g572;
static int64_t g573;
static int64_t g576;
static int64_t g577;
static int64_t g575;
static hrv g491;
static hrv g912;
static hrv g706;
static hrv g913;
static hrv g914;
static hrv g907;
static hrv g909;
static hrv g709;
static int64_t g708;
static int64_t g716;
static int64_t g715;
static int64_t g710;
static bool g711;
static hrv g703;
static hrv g705;
static bool g755;
static hrv g717;
static hrv g704;
static bool g712;
static bool g713;
static bool g714;
static hrv g718;
static hrv g707;
static hrv g494;
static hrv g495;
static hrv g489;
static hrv g488;
static hrv g493;
static int64_t g402;
static hrv g387;
static hrv g394;
static hrv g393;
static hrv g395;
static hrv g396;
static hrv g397;
static hrv g398;
static int64_t g400;
static int64_t g401;
static int64_t g404;
static hrv g403;
static hrv g449;
static hrv g450;
static hrv g555;
static hrv g556;
static hrv g553;
static hrv g490;
static hrv g554;
static hrv g435;
static hrv g389;
static hrv g388;
static hrv g391;
static hrv g436;
static hrv g390;
static hrv g311;
static int64_t g406;
static hrv g467;
static hrv g407;
static hrv g315;
static hrv g392;
static hrv g348;
static hrv g349;
static int64_t g350;
static hrv g312;
static hrv g313;
static hrv g408;
static hrv g163;
static hrv g171;
static hrv g172;
static hrv g173;
static hrv g174;
static hrv g175;
static hrv g170;
static A62 g183;
static hrv g164;
static hrv g165;
static hrv g167;
static int64_t g179;
static int64_t g178;
static hrv g176;
static hrv g182;
static hrv g166;
static hrv g169;
static hrv g240;
static hrv g243;
static hrv g180;
static hrv g181;
static hrv g177;
static hrv g168;
static A101 g114;
static hrv g154;
static int64_t g289;
static int64_t g290;
static int64_t g291;
static int64_t g292;
static int64_t g293;
static int64_t g294;
static int64_t g295;
static int64_t g296;
static int64_t g297;
static int64_t g298;
static int64_t g299;
static int64_t g300;
static int64_t g301;
static int64_t g302;
static int64_t g303;
static int64_t g304;
static int64_t g305;
static int64_t g306;
static int64_t g307;
static int64_t g308;
static int64_t g309;
static hrv g314;
static int64_t g361;
static int64_t g362;
static int64_t g363;
static int64_t g364;
static int64_t g365;
static int64_t g366;
static int64_t g367;
static int64_t g368;
static int64_t g369;
static int64_t g370;
static int64_t g371;
static int64_t g372;
static int64_t g373;
static int64_t g374;
static int64_t g375;
static int64_t g376;
static int64_t g377;
static int64_t g378;
static int64_t g379;
static int64_t g380;
static int64_t g381;
static int64_t g382;
static int64_t g399;
static int64_t g405;
static int64_t g481;
static int64_t g482;
static int64_t g483;
static int64_t g484;
static int64_t g485;
static int64_t g520;
static int64_t g521;
static int64_t g522;
static int64_t g523;
static int64_t g524;
static int64_t g525;
static int64_t g526;
static int64_t g527;
static int64_t g528;
static int64_t g529;
static int64_t g530;
static int64_t g531;
static int64_t g532;
static int64_t g533;
static int64_t g534;
static int64_t g535;
static int64_t g536;
static int64_t g537;
static int64_t g538;
static int64_t g539;
static int64_t g540;
static int64_t g541;
static int64_t g542;
static int64_t g543;
static int64_t g544;
static int64_t g617;
static int64_t g625;
static int64_t g626;
static int64_t g627;
static int64_t g628;
static int64_t g629;
static int64_t g630;
static int64_t g631;
static int64_t g632;
static int64_t g633;
static int64_t g634;
static int64_t g635;
static int64_t g636;
static int64_t g637;
static int64_t g638;
static int64_t g639;
static int64_t g640;
static int64_t g641;
static int64_t g642;
static int64_t g643;
static int64_t g644;
static int64_t g645;
static int64_t g646;
static int64_t g647;
static int64_t g648;
static int64_t g649;
static int64_t g650;
static int64_t g651;
static int64_t g652;
static int64_t g653;
static int64_t g654;
static int64_t g655;
static int64_t g656;
static int64_t g657;
static int64_t g658;
static int64_t g659;
static int64_t g660;
static int64_t g661;
static int64_t g662;
static int64_t g663;
static int64_t g664;
static int64_t g665;
static int64_t g666;
static int64_t g667;
static int64_t g668;
static int64_t g669;
static int64_t g670;
static int64_t g671;
static int64_t g672;
static int64_t g673;
static int64_t g674;
static int64_t g675;
static int64_t g676;
static int64_t g677;
static int64_t g678;
static int64_t g679;
static int64_t g680;
static int64_t g681;
static int64_t g682;
static int64_t g683;
static int64_t g684;
static int64_t g685;
static int64_t g686;
static int64_t g687;
static int64_t g688;
static int64_t g689;
static int64_t g690;
static int64_t g691;
static int64_t g692;
static int64_t g693;
static int64_t g694;
static int64_t g695;
static int64_t g696;
static int64_t g697;
static int64_t g698;
static int64_t g699;
static int64_t g700;
static int64_t g701;
static int64_t g796;
static int64_t g797;
static int64_t g798;
static int64_t g799;
static int64_t g800;
static int64_t g801;
static int64_t g802;
static int64_t g803;
static int64_t g804;
static int64_t g805;
static int64_t g806;
static int64_t g807;
static int64_t g808;
static int64_t g809;
static int64_t g810;
static int64_t g811;
static int64_t g812;
static int64_t g813;
static int64_t g814;
static int64_t g815;
static int64_t g816;
static int64_t g817;
static int64_t g818;
static int64_t g819;
static int64_t g820;
static int64_t g821;
static int64_t g822;
static int64_t g823;
static int64_t g824;
static int64_t g825;
static int64_t g826;
static int64_t g827;
static int64_t g828;
static int64_t g829;
static int64_t g830;
static int64_t g831;
static int64_t g832;
static int64_t g833;
static int64_t g834;
static int64_t g835;
static int64_t g836;
static int64_t g837;
static int64_t g838;
static int64_t g839;
static int64_t g840;
static int64_t g841;
static int64_t g842;
static int64_t g843;
static int64_t g844;
static int64_t g845;
static int64_t g846;
static int64_t g847;
static int64_t g848;
static int64_t g849;
static int64_t g850;
static int64_t g851;
static int64_t g852;
static int64_t g854;
static int64_t g855;
static int64_t g856;
static int64_t g857;
static int64_t g858;
static int64_t g859;
static int64_t g860;
static int64_t g861;
static int64_t g862;
static int64_t g863;
static int64_t g864;
static int64_t g865;
static int64_t g866;
static int64_t g867;
static int64_t g868;
static int64_t g869;
static int64_t g870;
static int64_t g871;
static int64_t g872;
static int64_t g873;
static int64_t g874;
static int64_t g875;
static int64_t g876;
static int64_t g877;
static int64_t g878;
static int64_t g879;
static int64_t g880;
static int64_t g881;
static int64_t g882;
static int64_t g883;
static int64_t g884;
static int64_t g885;
static int64_t g886;
static int64_t g887;
static int64_t g888;
static int64_t g889;
static int64_t g890;
static int64_t g891;
static int64_t g892;
static int64_t g893;
static int64_t g894;
static int64_t g895;
static int64_t g896;
static int64_t g897;
static int64_t g898;
static int64_t g899;
static int64_t g900;
static int64_t g901;
static int64_t g902;
static int64_t g903;
static void f1_main(void) {
hrv a_0 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
hrv o_1 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if (((hr_os_arg_count()) < (((int64_t)3LL)))) { (void)(({ hr_fs(&hr_ob, hr_str("usage: hc file.amni out.c", 25)); hr_println(); }));
(void)(hr_exit(((int64_t)2LL)));
 }
(void)(hr_os_arg(((int64_t)1LL), (&(a_0))));
(void)(hr_os_arg(((int64_t)2LL), (&(o_1))));
hrv lib_2 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(hr_os_getenv(hr_str("HC_LIB", 6), (&(lib_2)))))) { (void)(({ hrv *_v14 = &(lib_2); hsl _s14 = hr_str("hc/lib", 6); hr_append(_v14, _s14.p, _s14.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v15 = &(g492); hsl _s15 = hr_sl(lib_2); hr_append(_v15, _s15.p, _s15.n, sizeof(uint8_t)); }));
if ((!(f5_load_program(hr_sl(a_0))))) { (void)(({ hr_fs(&hr_ob, hr_sl(g494)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((!(f104_check_program()))) { (void)(({ hr_fs(&hr_ob, hr_sl(g403)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((((g494).n) > (((int64_t)0LL)))) { (void)(({ hr_fs(&hr_ob, hr_sl(g494)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
hrv c_1486 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(f259_gen_program((&(c_1486)))))) { (void)(({ hr_fs(&hr_ob, hr_sl(g182)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((!(hr_os_write_file(hr_sl(o_1), hr_sl(c_1486))))) { (void)(({ hr_fs(&hr_ob, hr_str("cannot write ", 13)); hr_fs(&hr_ob, hr_sl(o_1)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
}
static bool f5_load_program(hsl root_3) {
(void)(f6_parse_init());
(void)(f11_types_init());
int64_t d_38 = (root_3).n; 
while ((((d_38) > (((int64_t)0LL))) && (((*({ hsl _t34 = root_3; int64_t _i34 = ((int64_t)((int64_t)d_38 - (int64_t)((int64_t)1LL))); (uint8_t*)_t34.p + hr_ix(_i34, _t34.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:68"); }))) != (((uint8_t)47LL))))) { d_38--;
 } _bk33:; 
(void)(({ hrv *_v35 = &(g491); _v35->n = 0; }));
(void)(({ hrv *_v36 = &(g491); hsl _s36 = ({ hsl _r37; if (((d_38) > (((int64_t)0LL)))) { _r37 = ({ hsl _t38 = root_3; int64_t _l38 = 0, _h38 = ((int64_t)((int64_t)d_38 - (int64_t)((int64_t)1LL))); if (_l38 < 0 || _h38 < _l38 || _h38 > _t38.n) hr_slerr(_l38, _h38, _t38.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:69"); (hsl){ _t38.p + _l38 * (int64_t)sizeof(uint8_t), _h38 - _l38 }; });  } else { _r37 = hr_str(".", 1);  } _r37; }); hr_append(_v36, _s36.p, _s36.n, sizeof(uint8_t)); }));
return (((f19_try_load(root_3)) >= (((int64_t)0LL))) && (((g494).n) == (((int64_t)0LL))));
}
static void f6_parse_init(void) {
(void)(f7_lex_init());
if (((g720) < (((int64_t)0LL)))) { g720 = f8_intern(hr_str("from", 4));
g721 = f8_intern(hr_str("inline", 6));
g722 = f8_intern(hr_str("checkfree", 9));
g723 = f8_intern(hr_str("lut", 3));
g724 = f8_intern(hr_str("_", 1));
g725 = f8_intern(hr_str("upto", 4));
g726 = f8_intern(hr_str("fields", 6));
g727 = f8_intern(hr_str("types", 5));
g728 = f8_intern(hr_str("variants", 8));
g729 = f8_intern(hr_str("std", 3));
 }
}
static void f7_lex_init(void) {
if ((((g910).n) == (((int64_t)0LL)))) { { hsl _v52 = ({ A25 *_t53 = &(g853); (hsl){ (uint8_t*)_t53->e, 49 }; }); for (int64_t _k52 = 0; _k52 < _v52.n; _k52++) { hsl k_4 = ((hsl*)_v52.p)[_k52]; (void)(f8_intern(k_4));
 } } _bk51:; 
 }
}
static int64_t f8_intern(hsl s_5) {
if ((((g911).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v55 = &(g911); int64_t _k55 = ((int64_t)((((int64_t)1LL)) << ((((int64_t)16LL)) & 63))); if (_k55 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:32"); int32_t _x55 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o55 = _v55->n; hr_resize(_v55, _k55, sizeof _x55); for (int64_t _j = _o55; _j < _k55; _j++) ((int32_t*)_v55->b)[_j] = _x55; }));
 }
if (((((int64_t)((int64_t)(g910).n * (int64_t)((int64_t)2LL)))) >= ((g911).n))) { int64_t n_6 = ((int64_t)((int64_t)(g911).n * (int64_t)((int64_t)2LL))); 
(void)(({ hrv *_v56 = &(g911); _v56->n = 0; }));
(void)(({ hrv *_v57 = &(g911); int64_t _k57 = n_6; if (_k57 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:35"); int32_t _x57 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o57 = _v57->n; hr_resize(_v57, _k57, sizeof _x57); for (int64_t _j = _o57; _j < _k57; _j++) ((int32_t*)_v57->b)[_j] = _x57; }));
{ hrv *_v59 = &(g910); for (int64_t _k59 = 0; _k59 < _v59->n; _k59++) { S0 x_7 = ((S0*)_v59->b)[_k59]; int64_t i_8 = (int64_t)_k59; int64_t j_12 = ((int64_t)((int64_t)((int64_t)(f9_hash(({ hsl _t61 = hr_sl(g908); int64_t _l61 = ((int64_t)((x_7).s_)), _h61 = ((int64_t)(((int32_t)((int64_t)(x_7).s_ + (int64_t)(x_7).n_)))); if (_l61 < 0 || _h61 < _l61 || _h61 > _t61.n) hr_slerr(_l61, _h61, _t61.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:36"); (hsl){ _t61.p + _l61 * (int64_t)sizeof(uint8_t), _h61 - _l61 }; })))) & (int64_t)((int64_t)((int64_t)n_6 - (int64_t)((int64_t)1LL))))); 
while ((((*({ hrv *_t63 = &(g911); int64_t _i63 = j_12; (int32_t*)_t63->b + hr_ix(_i63, _t63->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:36"); }))) >= (((int32_t)0LL)))) { j_12 = ((int64_t)((int64_t)((int64_t)((int64_t)j_12 + (int64_t)((int64_t)1LL))) & (int64_t)((int64_t)((int64_t)n_6 - (int64_t)((int64_t)1LL)))));
 } _bk62:; 
{ int32_t *_t64 = &((*({ hrv *_t65 = &(g911); int64_t _i65 = j_12; (int32_t*)_t65->b + hr_ix(_i65, _t65->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:36"); }))); *_t64 = ((int32_t)(i_8)); }
 } } _bk58:; 
 }
int64_t m_13 = ((int64_t)((int64_t)(g911).n - (int64_t)((int64_t)1LL))); 
int64_t j_14 = ((int64_t)((int64_t)((int64_t)(f9_hash(s_5))) & (int64_t)m_13)); 
while ((((*({ hrv *_t68 = &(g911); int64_t _i68 = j_14; (int32_t*)_t68->b + hr_ix(_i68, _t68->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:40"); }))) >= (((int32_t)0LL)))) { if (hr_streq(f10_nm(((int64_t)((*({ hrv *_t70 = &(g911); int64_t _i70 = j_14; (int32_t*)_t70->b + hr_ix(_i70, _t70->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:40"); }))))), s_5)) { return ((int64_t)((*({ hrv *_t71 = &(g911); int64_t _i71 = j_14; (int32_t*)_t71->b + hr_ix(_i71, _t71->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:40"); }))));
 }
j_14 = ((int64_t)((int64_t)((int64_t)((int64_t)j_14 + (int64_t)((int64_t)1LL))) & (int64_t)m_13));
 } _bk67:; 
int64_t id_17 = (g910).n; 
(void)(({ hrv *_v72 = &(g910); S0 _x72 = ((S0){ .s_ = ((int32_t)((g908).n)), .n_ = ((int32_t)((s_5).n)), }); S0 *_p72 = (S0*)hr_grow(_v72, 1, sizeof _x72); *_p72 = _x72; _p72; }));
(void)(({ hrv *_v73 = &(g908); hsl _s73 = s_5; hr_append(_v73, _s73.p, _s73.n, sizeof(uint8_t)); }));
{ int32_t *_t74 = &((*({ hrv *_t75 = &(g911); int64_t _i75 = j_14; (int32_t*)_t75->b + hr_ix(_i75, _t75->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:44"); }))); *_t74 = ((int32_t)(id_17)); }
return id_17;
}
static uint64_t f9_hash(hsl s_9) {
uint64_t h_10 = ((uint64_t)1469598103934665603LL); 
{ hsl _v77 = s_9; for (int64_t _k77 = 0; _k77 < _v77.n; _k77++) { uint8_t c_11 = ((uint8_t*)_v77.p)[_k77]; h_10 = ((uint64_t)((uint64_t)((uint64_t)((uint64_t)h_10 ^ (uint64_t)((uint64_t)(c_11)))) * (uint64_t)((uint64_t)1099511628211LL)));
 } } _bk76:; 
return h_10;
}
static hsl f10_nm(int64_t id_15) {
S0 x_16 = (*({ hrv *_t78 = &(g910); int64_t _i78 = id_15; (S0*)_t78->b + hr_ix(_i78, _t78->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:29"); })); 
return ({ hsl _t79 = hr_sl(g908); int64_t _l79 = ((int64_t)((x_16).s_)), _h79 = ((int64_t)(((int32_t)((int64_t)(x_16).s_ + (int64_t)(x_16).n_)))); if (_l79 < 0 || _h79 < _l79 || _h79 > _t79.n) hr_slerr(_l79, _h79, _t79.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:29"); (hsl){ _t79.p + _l79 * (int64_t)sizeof(uint8_t), _h79 - _l79 }; });
}
static void f11_types_init(void) {
if ((((g550).n) > (((int64_t)0LL)))) { return;
 }
g574 = f12_tsimple(((int64_t)0LL), ((int64_t)0LL));
g557 = f12_tsimple(((int64_t)1LL), ((int64_t)0LL));
g558 = f12_tsimple(((int64_t)2LL), ((int64_t)0LL));
g559 = f17_t_int(((int64_t)0LL));
g560 = f17_t_int(((int64_t)1LL));
g561 = f17_t_int(((int64_t)2LL));
g562 = f17_t_int(((int64_t)3LL));
g563 = f17_t_int(((int64_t)4LL));
g564 = f17_t_int(((int64_t)5LL));
g565 = f17_t_int(((int64_t)6LL));
g566 = f17_t_int(((int64_t)7LL));
g567 = f12_tsimple(((int64_t)4LL), ((int64_t)4LL));
g568 = f12_tsimple(((int64_t)4LL), ((int64_t)8LL));
g569 = f12_tsimple(((int64_t)11LL), ((int64_t)0LL));
g570 = f12_tsimple(((int64_t)12LL), ((int64_t)0LL));
g571 = f12_tsimple(((int64_t)13LL), ((int64_t)0LL));
g572 = f12_tsimple(((int64_t)18LL), ((int64_t)0LL));
g573 = f12_tsimple(((int64_t)17LL), ((int64_t)0LL));
g576 = f12_tsimple(((int64_t)19LL), ((int64_t)0LL));
g577 = f12_tsimple(((int64_t)15LL), ((int64_t)0LL));
g575 = f18_t_slice(g563, true);
}
static int64_t f12_tsimple(int64_t k_18, int64_t s_19) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(k_18)), .s_ = ((uint8_t)(s_19)), .a_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f13_tmk(S1 t_20) {
if ((((g552).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v102 = &(g552); int64_t _k102 = ((int64_t)((((int64_t)1LL)) << ((((int64_t)14LL)) & 63))); if (_k102 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:27"); int32_t _x102 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o102 = _v102->n; hr_resize(_v102, _k102, sizeof _x102); for (int64_t _j = _o102; _j < _k102; _j++) ((int32_t*)_v102->b)[_j] = _x102; }));
 }
if (((((int64_t)((int64_t)(g550).n * (int64_t)((int64_t)2LL)))) >= ((g552).n))) { int64_t n_21 = ((int64_t)((int64_t)(g552).n * (int64_t)((int64_t)2LL))); 
(void)(({ hrv *_v103 = &(g552); _v103->n = 0; }));
(void)(({ hrv *_v104 = &(g552); int64_t _k104 = n_21; if (_k104 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:29"); int32_t _x104 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o104 = _v104->n; hr_resize(_v104, _k104, sizeof _x104); for (int64_t _j = _o104; _j < _k104; _j++) ((int32_t*)_v104->b)[_j] = _x104; }));
{ hrv *_v106 = &(g550); for (int64_t _k106 = 0; _k106 < _v106->n; _k106++) { S1 x_22 = ((S1*)_v106->b)[_k106]; int64_t i_23 = (int64_t)_k106; int64_t j_29 = ((int64_t)((int64_t)((int64_t)(f14_th(x_22))) & (int64_t)((int64_t)((int64_t)n_21 - (int64_t)((int64_t)1LL))))); 
while ((((*({ hrv *_t109 = &(g552); int64_t _i109 = j_29; (int32_t*)_t109->b + hr_ix(_i109, _t109->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:30"); }))) >= (((int32_t)0LL)))) { j_29 = ((int64_t)((int64_t)((int64_t)((int64_t)j_29 + (int64_t)((int64_t)1LL))) & (int64_t)((int64_t)((int64_t)n_21 - (int64_t)((int64_t)1LL)))));
 } _bk108:; 
{ int32_t *_t110 = &((*({ hrv *_t111 = &(g552); int64_t _i111 = j_29; (int32_t*)_t111->b + hr_ix(_i111, _t111->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:30"); }))); *_t110 = ((int32_t)(i_23)); }
 } } _bk105:; 
 }
int64_t m_30 = ((int64_t)((int64_t)(g552).n - (int64_t)((int64_t)1LL))); 
int64_t j_31 = ((int64_t)((int64_t)((int64_t)(f14_th(t_20))) & (int64_t)m_30)); 
while ((((*({ hrv *_t114 = &(g552); int64_t _i114 = j_31; (int32_t*)_t114->b + hr_ix(_i114, _t114->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); }))) >= (((int32_t)0LL)))) { if (f16_teq((*({ hrv *_t116 = &(g550); int64_t _i116 = (*({ hrv *_t117 = &(g552); int64_t _i117 = j_31; (int32_t*)_t117->b + hr_ix(_i117, _t117->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); })); (S1*)_t116->b + hr_ix(_i116, _t116->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); })), t_20)) { return ((int64_t)((*({ hrv *_t118 = &(g552); int64_t _i118 = j_31; (int32_t*)_t118->b + hr_ix(_i118, _t118->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); }))));
 }
j_31 = ((int64_t)((int64_t)((int64_t)((int64_t)j_31 + (int64_t)((int64_t)1LL))) & (int64_t)m_30));
 } _bk113:; 
(void)(({ hrv *_v119 = &(g550); S1 _x119 = t_20; S1 *_p119 = (S1*)hr_grow(_v119, 1, sizeof _x119); *_p119 = _x119; _p119; }));
{ int32_t *_t120 = &((*({ hrv *_t121 = &(g552); int64_t _i121 = j_31; (int32_t*)_t121->b + hr_ix(_i121, _t121->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:35"); }))); *_t120 = ((int32_t)(((int64_t)((int64_t)(g550).n - (int64_t)((int64_t)1LL))))); }
return ((int64_t)((int64_t)(g550).n - (int64_t)((int64_t)1LL)));
}
static uint64_t f14_th(S1 t_24) {
uint64_t h_27 = f15_hash_mix(((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((t_24).k_)) | (uint64_t)((uint64_t)((((uint64_t)((t_24).s_))) << ((((uint64_t)8LL)) & 63))))) | (uint64_t)((uint64_t)((((uint64_t)((t_24).fl_))) << ((((uint64_t)16LL)) & 63))))) | (uint64_t)((uint64_t)((((uint64_t)((t_24).a_))) << ((((uint64_t)32LL)) & 63)))))); 
h_27 = f15_hash_mix(((uint64_t)((uint64_t)((uint64_t)((uint64_t)h_27 ^ (uint64_t)((uint64_t)((t_24).c_)))) ^ (uint64_t)((uint64_t)((((uint64_t)((t_24).b_))) << ((((uint64_t)20LL)) & 63))))));
{ int32_t _e125 = (t_24).n_; for (int32_t _k125 = 0; _k125 < _e125; _k125++) { int32_t i_28 = (int32_t)_k125; h_27 = f15_hash_mix(((uint64_t)((uint64_t)h_27 ^ (uint64_t)((uint64_t)((*({ hrv *_t127 = &(g551); int64_t _i127 = ((int64_t)((int64_t)((int64_t)((t_24).l_)) + (int64_t)((int64_t)(i_28)))); (int32_t*)_t127->b + hr_ix(_i127, _t127->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:20"); })))))));
 } } _bk124:; 
return h_27;
}
static uint64_t f15_hash_mix(uint64_t x_25) {
uint64_t h_26 = ((uint64_t)((uint64_t)x_25 * (uint64_t)((uint64_t)11400714819323198485ULL))); 
h_26 = ((uint64_t)((uint64_t)h_26 ^ (uint64_t)((uint64_t)((h_26) >> ((((uint64_t)32LL)) & 63)))));
return h_26;
}
static bool f16_teq(S1 x_32, S1 y_33) {
if ((((((((((x_32).k_) != ((y_33).k_)) || (((x_32).s_) != ((y_33).s_))) || (((x_32).fl_) != ((y_33).fl_))) || (((x_32).a_) != ((y_33).a_))) || (((x_32).c_) != ((y_33).c_))) || (((x_32).b_) != ((y_33).b_))) || (((x_32).n_) != ((y_33).n_)))) { return false;
 }
{ int32_t _e129 = (x_32).n_; for (int32_t _k129 = 0; _k129 < _e129; _k129++) { int32_t i_34 = (int32_t)_k129; if ((((*({ hrv *_t130 = &(g551); int64_t _i130 = ((int64_t)((int64_t)((int64_t)((x_32).l_)) + (int64_t)((int64_t)(i_34)))); (int32_t*)_t130->b + hr_ix(_i130, _t130->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:23"); }))) != ((*({ hrv *_t131 = &(g551); int64_t _i131 = ((int64_t)((int64_t)((int64_t)((y_33).l_)) + (int64_t)((int64_t)(i_34)))); (int32_t*)_t131->b + hr_ix(_i131, _t131->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:23"); }))))) { return false;
 }
 } } _bk128:; 
return true;
}
static int64_t f17_t_int(int64_t s_35) {
return f12_tsimple(((int64_t)3LL), s_35);
}
static int64_t f18_t_slice(int64_t e_36, bool cq_37) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)9LL))), .a_ = ((int32_t)(e_36)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f19_try_load(hsl path_39) {
int64_t id_40 = f8_intern(path_39); 
{ hrv *_v136 = &(g912); for (int64_t _k136 = 0; _k136 < _v136->n; _k136++) { S2 f_41 = ((S2*)_v136->b)[_k136]; int64_t i_42 = (int64_t)_k136; if (((((int64_t)((f_41).name_))) == (id_40))) { return i_42;
 }
 } } _bk135:; 
if ((!(hr_os_file_exists(path_39)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t t0_43 = (g706).n; 
if ((!(f21_parse_file(path_39)))) { (void)(({ hrv *_v139 = &(g494); hsl _s139 = hr_sl(g709); hr_append(_v139, _s139.p, _s139.n, sizeof(uint8_t)); }));
return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
int64_t f_439 = ((int64_t)((int64_t)(g912).n - (int64_t)((int64_t)1LL))); 
while ((((g495).n) < ((g912).n))) { (void)(({ hrv *_v141 = &(g495); int32_t _x141 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p141 = (int32_t*)hr_grow(_v141, 1, sizeof _x141); *_p141 = _x141; _p141; }));
 } _bk140:; 
{ int32_t *_t142 = &((*({ hrv *_t143 = &(g495); int64_t _i143 = f_439; (int32_t*)_t143->b + hr_ix(_i143, _t143->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:45"); }))); *_t142 = (*({ hrv *_t144 = &(g707); int64_t _i144 = ((int64_t)((int64_t)(g707).n - (int64_t)((int64_t)1LL))); (int32_t*)_t144->b + hr_ix(_i144, _t144->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:45"); })); }
(void)(f97_collect(f_439, t0_43, (g706).n));
int64_t t1_455 = (g706).n; 
int64_t im0_456 = (g493).n; 
{ int64_t _e147 = t1_455; for (int64_t _k147 = t0_43; _k147 < _e147; _k147++) { int64_t i_457 = (int64_t)_k147; if (((((*({ hrv *_t148 = &(g703); int64_t _i148 = (*({ hrv *_t149 = &(g706); int64_t _i149 = i_457; (int32_t*)_t149->b + hr_ix(_i149, _t149->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:49"); })); (S4*)_t148->b + hr_ix(_i148, _t148->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:49"); }))).k_) == (((uint8_t)54LL)))) { (void)(({ hrv *_v150 = &(g493); int32_t _x150 = (*({ hrv *_t151 = &(g706); int64_t _i151 = i_457; (int32_t*)_t151->b + hr_ix(_i151, _t151->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:49"); })); int32_t *_p150 = (int32_t*)hr_grow(_v150, 1, sizeof _x150); *_p150 = _x150; _p150; }));
 }
 } } _bk146:; 
int64_t im1_458 = (g493).n; 
L49 sp_461 = f100_lib_path(hr_str("std", 3)); 
bool isstd_462 = hr_streq(path_39, ({ hsl _t153 = ({ L49 *_t154 = &(sp_461); (hsl){ (uint8_t*)_t154->e, _t154->n }; }); int64_t _l153 = 0, _h153 = _t153.n; if (_l153 < 0 || _h153 < _l153 || _h153 > _t153.n) hr_slerr(_l153, _h153, _t153.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:51"); (hsl){ _t153.p + _l153 * (int64_t)sizeof(uint8_t), _h153 - _l153 }; })); 
if ((((*({ hrv *_t155 = &(g912); int64_t _i155 = f_439; (S2*)_t155->b + hr_ix(_i155, _t155->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:52"); }))).amni_ && (!(isstd_462)))) { if (((f101_load_import(g729, f_439, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
 }
{ int64_t _e158 = im1_458; for (int64_t _k158 = im0_456; _k158 < _e158; _k158++) { int64_t q_475 = (int64_t)_k158; int64_t n_476 = ((int64_t)((*({ hrv *_t159 = &(g493); int64_t _i159 = q_475; (int32_t*)_t159->b + hr_ix(_i159, _t159->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:53"); })))); 
if (((f101_load_import(((int64_t)(((*({ hrv *_t161 = &(g703); int64_t _i161 = n_476; (S4*)_t161->b + hr_ix(_i161, _t161->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:53"); }))).s_)), f_439, ((int64_t)(((*({ hrv *_t162 = &(g703); int64_t _i162 = n_476; (S4*)_t162->b + hr_ix(_i162, _t162->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:53"); }))).t_)))) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
 } } _bk157:; 
return f_439;
}
static bool f21_parse_file(hsl path_44) {
(void)(f6_parse_init());
int64_t t0_45 = (g913).n; 
if ((!(f22_lex_file(path_44)))) { (void)(({ hrv *_v165 = &(g709); hsl _s165 = hr_sl(g914); hr_append(_v165, _s165.p, _s165.n, sizeof(uint8_t)); }));
return false;
 }
g708 = t0_45;
g716 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
while ((((f31_tk()) != (((int64_t)0LL))) && (((g709).n) == (((int64_t)0LL))))) { (void)(f32_ptop());
 } _bk166:; 
(void)(({ hrv *_v169 = &(g707); int32_t _x169 = ((int32_t)(g716)); int32_t *_p169 = (int32_t*)hr_grow(_v169, 1, sizeof _x169); *_p169 = _x169; _p169; }));
return (((g709).n) == (((int64_t)0LL)));
}
static bool f22_lex_file(hsl path_46) {
(void)(f7_lex_init());
hrv body_47 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(hr_os_read_file(path_46, (&(body_47)))))) { (void)(({ hrv *_v173 = &(g914); hsl _s173 = hr_str("cannot read ", 12); hr_append(_v173, _s173.p, _s173.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v174 = &(g914); hsl _s174 = path_46; hr_append(_v174, _s174.p, _s174.n, sizeof(uint8_t)); }));
return false;
 }
int64_t f_48 = (g912).n; 
int64_t base_49 = (g907).n; 
int64_t skip_50 = ({ int64_t _r175; if (((((((body_47).n) >= (((int64_t)3LL))) && (((*({ hrv *_t176 = &(body_47); int64_t _i176 = ((int64_t)0LL); (uint8_t*)_t176->b + hr_ix(_i176, _t176->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:69"); }))) == (((uint8_t)239LL)))) && (((*({ hrv *_t177 = &(body_47); int64_t _i177 = ((int64_t)1LL); (uint8_t*)_t177->b + hr_ix(_i177, _t177->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:69"); }))) == (((uint8_t)187LL)))) && (((*({ hrv *_t178 = &(body_47); int64_t _i178 = ((int64_t)2LL); (uint8_t*)_t178->b + hr_ix(_i178, _t178->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:69"); }))) == (((uint8_t)191LL))))) { _r175 = ((int64_t)3LL);  } else { _r175 = ((int64_t)0LL);  } _r175; }); 
(void)(({ hrv *_v179 = &(g907); hsl _s179 = ({ hsl _t180 = hr_sl(body_47); int64_t _l180 = skip_50, _h180 = _t180.n; if (_l180 < 0 || _h180 < _l180 || _h180 > _t180.n) hr_slerr(_l180, _h180, _t180.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:70"); (hsl){ _t180.p + _l180 * (int64_t)sizeof(uint8_t), _h180 - _l180 }; }); hr_append(_v179, _s179.p, _s179.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v181 = &(g907); uint8_t _x181 = ((uint8_t)0LL); uint8_t *_p181 = (uint8_t*)hr_grow(_v181, 1, sizeof _x181); *_p181 = _x181; _p181; }));
(void)(({ hrv *_v182 = &(g907); uint8_t _x182 = ((uint8_t)0LL); uint8_t *_p182 = (uint8_t*)hr_grow(_v182, 1, sizeof _x182); *_p182 = _x182; _p182; }));
(void)(({ hrv *_v183 = &(g907); uint8_t _x183 = ((uint8_t)0LL); uint8_t *_p183 = (uint8_t*)hr_grow(_v183, 1, sizeof _x183); *_p183 = _x183; _p183; }));
(void)(({ hrv *_v184 = &(g907); uint8_t _x184 = ((uint8_t)0LL); uint8_t *_p184 = (uint8_t*)hr_grow(_v184, 1, sizeof _x184); *_p184 = _x184; _p184; }));
(void)(({ hrv *_v185 = &(g912); S2 _x185 = ((S2){ .s_ = ((int32_t)(base_49)), .n_ = ((int32_t)(((int64_t)((int64_t)(body_47).n - (int64_t)skip_50)))), .name_ = ((int32_t)(f8_intern(path_46))), .amni_ = ((((path_46).n) > (((int64_t)5LL))) && hr_streq(({ hsl _t187 = path_46; int64_t _l187 = _t187.n - ((int64_t)5LL), _h187 = _t187.n; if (_l187 < 0 || _h187 < _l187 || _h187 > _t187.n) hr_slerr(_l187, _h187, _t187.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:71"); (hsl){ _t187.p + _l187 * (int64_t)sizeof(uint8_t), _h187 - _l187 }; }), hr_str(".amni", 5))), }); S2 *_p185 = (S2*)hr_grow(_v185, 1, sizeof _x185); *_p185 = _x185; _p185; }));
bool amni_51 = ((*({ hrv *_t188 = &(g912); int64_t _i188 = f_48; (S2*)_t188->b + hr_ix(_i188, _t188->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:72"); }))).amni_; 
int64_t p_52 = base_49; 
int64_t line_53 = ((int64_t)1LL); 

for (;;) { uint8_t c_57 = (*({ hrv *_t190 = &(g907); int64_t _i190 = p_52; (uint8_t*)_t190->b + hr_ix(_i190, _t190->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:77"); })); 
while ((((((c_57) == (((uint8_t)32LL))) || ((c_57) == (((uint8_t)9LL)))) || ((c_57) == (((uint8_t)13LL)))) || ((c_57) == (((uint8_t)10LL))))) { if (((c_57) == (((uint8_t)10LL)))) { line_53++;
 }
p_52++;
c_57 = (*({ hrv *_t192 = &(g907); int64_t _i192 = p_52; (uint8_t*)_t192->b + hr_ix(_i192, _t192->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:78"); }));
 } _bk191:; 
if ((((c_57) == (((uint8_t)47LL))) && (((*({ hrv *_t193 = &(g907); int64_t _i193 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t193->b + hr_ix(_i193, _t193->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:79"); }))) == (((uint8_t)47LL))))) { while (((((*({ hrv *_t195 = &(g907); int64_t _i195 = p_52; (uint8_t*)_t195->b + hr_ix(_i195, _t195->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:79"); }))) != (((uint8_t)10LL))) && (((*({ hrv *_t196 = &(g907); int64_t _i196 = p_52; (uint8_t*)_t196->b + hr_ix(_i196, _t196->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:79"); }))) != (((uint8_t)0LL))))) { p_52++;
 } _bk194:; 
continue;
 }
if ((((c_57) == (((uint8_t)47LL))) && (((*({ hrv *_t197 = &(g907); int64_t _i197 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t197->b + hr_ix(_i197, _t197->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:80"); }))) == (((uint8_t)42LL))))) { { int64_t *_t198 = &(p_52); *_t198 = ((int64_t)((int64_t)(*_t198) + (int64_t)((int64_t)2LL))); }
int64_t nest_58 = ((int64_t)1LL); 
while (((nest_58) > (((int64_t)0LL)))) { uint8_t d_59 = (*({ hrv *_t200 = &(g907); int64_t _i200 = p_52; (uint8_t*)_t200->b + hr_ix(_i200, _t200->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:82"); })); 
if (((d_59) == (((uint8_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("unterminated /* comment", 23));
 }
if (((d_59) == (((uint8_t)10LL)))) { line_53++;
 }
if ((((d_59) == (((uint8_t)42LL))) && (((*({ hrv *_t202 = &(g907); int64_t _i202 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t202->b + hr_ix(_i202, _t202->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:82"); }))) == (((uint8_t)47LL))))) { nest_58--;
p_52++;
 } else { if ((((d_59) == (((uint8_t)47LL))) && (((*({ hrv *_t203 = &(g907); int64_t _i203 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t203->b + hr_ix(_i203, _t203->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:82"); }))) == (((uint8_t)42LL))))) { nest_58++;
p_52++;
 }
 }
p_52++;
 } _bk199:; 
continue;
 }
int64_t s_63 = p_52; 
uint8_t n1_64 = (*({ hrv *_t204 = &(g907); int64_t _i204 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t204->b + hr_ix(_i204, _t204->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:86"); })); 
uint8_t n2_65 = (*({ hrv *_t205 = &(g907); int64_t _i205 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t205->b + hr_ix(_i205, _t205->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:86"); })); 
if (((c_57) == (((uint8_t)0LL)))) { (void)(f23_put(((int64_t)0LL), s_63, s_63, &f_48, &line_53));
return true;
 }
if (f26_dig(c_57)) { if ((((c_57) == (((uint8_t)48LL))) && (((n1_64) == (((uint8_t)120LL))) || ((n1_64) == (((uint8_t)88LL)))))) { { int64_t *_t208 = &(p_52); *_t208 = ((int64_t)((int64_t)(*_t208) + (int64_t)((int64_t)2LL))); }
int64_t ds_67 = p_52; 
while (f27_hexd((*({ hrv *_t211 = &(g907); int64_t _i211 = p_52; (uint8_t*)_t211->b + hr_ix(_i211, _t211->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:90"); })))) { p_52++;
 } _bk209:; 
bool hf_69 = false; 
if (((((*({ hrv *_t212 = &(g907); int64_t _i212 = p_52; (uint8_t*)_t212->b + hr_ix(_i212, _t212->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:92"); }))) == (((uint8_t)46LL))) && f27_hexd((*({ hrv *_t214 = &(g907); int64_t _i214 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t214->b + hr_ix(_i214, _t214->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:92"); }))))) { hf_69 = true;
p_52++;
while (f27_hexd((*({ hrv *_t217 = &(g907); int64_t _i217 = p_52; (uint8_t*)_t217->b + hr_ix(_i217, _t217->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:92"); })))) { p_52++;
 } _bk215:; 
 }
if (((((*({ hrv *_t218 = &(g907); int64_t _i218 = p_52; (uint8_t*)_t218->b + hr_ix(_i218, _t218->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)112LL))) || (((*({ hrv *_t219 = &(g907); int64_t _i219 = p_52; (uint8_t*)_t219->b + hr_ix(_i219, _t219->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)80LL))))) { hf_69 = true;
p_52++;
if (((((*({ hrv *_t220 = &(g907); int64_t _i220 = p_52; (uint8_t*)_t220->b + hr_ix(_i220, _t220->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)43LL))) || (((*({ hrv *_t221 = &(g907); int64_t _i221 = p_52; (uint8_t*)_t221->b + hr_ix(_i221, _t221->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)45LL))))) { p_52++;
 }
while (f26_dig((*({ hrv *_t224 = &(g907); int64_t _i224 = p_52; (uint8_t*)_t224->b + hr_ix(_i224, _t224->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); })))) { p_52++;
 } _bk222:; 
 }
if (hf_69) { (void)(f23_put(((int64_t)3LL), s_63, p_52, &f_48, &line_53));
continue;
 }
if (((((int64_t)((int64_t)p_52 - (int64_t)ds_67))) > (((int64_t)16LL)))) { return f25_lerr(f_48, line_53, hr_str("hex literal too large for 64 bits", 33));
 }
uint64_t v_70 = ((uint64_t)0LL); 
{ int64_t _e228 = p_52; for (int64_t _k228 = ds_67; _k228 < _e228; _k228++) { int64_t q_71 = (int64_t)_k228; v_70 = ((uint64_t)((uint64_t)((uint64_t)((v_70) << ((((uint64_t)4LL)) & 63))) | (uint64_t)((uint64_t)(f28_hexv((*({ hrv *_t230 = &(g907); int64_t _i230 = q_71; (uint8_t*)_t230->b + hr_ix(_i230, _t230->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:96"); })))))));
 } } _bk227:; 
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t232 = &(((*({ hrv *_t233 = &(g913); int64_t _i233 = ((int64_t)((int64_t)(g913).n - (int64_t)((int64_t)1LL))); (S3*)_t233->b + hr_ix(_i233, _t233->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:97"); }))).v_); *_t232 = ((int64_t)(v_70)); }
{ bool *_t234 = &(((*({ hrv *_t235 = &(g913); int64_t _i235 = ((int64_t)((int64_t)(g913).n - (int64_t)((int64_t)1LL))); (S3*)_t235->b + hr_ix(_i235, _t235->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:97"); }))).uns_); *_t234 = ((v_70) > (((uint64_t)9223372036854775807LL))); }
continue;
 }
while (f26_dig((*({ hrv *_t238 = &(g907); int64_t _i238 = p_52; (uint8_t*)_t238->b + hr_ix(_i238, _t238->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:99"); })))) { p_52++;
 } _bk236:; 
bool fl_73 = false; 
if (((((*({ hrv *_t239 = &(g907); int64_t _i239 = p_52; (uint8_t*)_t239->b + hr_ix(_i239, _t239->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:101"); }))) == (((uint8_t)46LL))) && f26_dig((*({ hrv *_t241 = &(g907); int64_t _i241 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t241->b + hr_ix(_i241, _t241->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:101"); }))))) { fl_73 = true;
p_52++;
while (f26_dig((*({ hrv *_t244 = &(g907); int64_t _i244 = p_52; (uint8_t*)_t244->b + hr_ix(_i244, _t244->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:101"); })))) { p_52++;
 } _bk242:; 
 }
if ((((((*({ hrv *_t245 = &(g907); int64_t _i245 = p_52; (uint8_t*)_t245->b + hr_ix(_i245, _t245->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)101LL))) || (((*({ hrv *_t246 = &(g907); int64_t _i246 = p_52; (uint8_t*)_t246->b + hr_ix(_i246, _t246->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)69LL)))) && (f26_dig((*({ hrv *_t248 = &(g907); int64_t _i248 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t248->b + hr_ix(_i248, _t248->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) || (((((*({ hrv *_t249 = &(g907); int64_t _i249 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t249->b + hr_ix(_i249, _t249->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)43LL))) || (((*({ hrv *_t250 = &(g907); int64_t _i250 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t250->b + hr_ix(_i250, _t250->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)45LL)))) && f26_dig((*({ hrv *_t252 = &(g907); int64_t _i252 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t252->b + hr_ix(_i252, _t252->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))))))) { fl_73 = true;
{ int64_t *_t253 = &(p_52); *_t253 = ((int64_t)((int64_t)(*_t253) + (int64_t)((int64_t)2LL))); }
while (f26_dig((*({ hrv *_t256 = &(g907); int64_t _i256 = p_52; (uint8_t*)_t256->b + hr_ix(_i256, _t256->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); })))) { p_52++;
 } _bk254:; 
 }
if (fl_73) { (void)(f23_put(((int64_t)3LL), s_63, p_52, &f_48, &line_53));
continue;
 }
uint64_t v_74 = ((uint64_t)0LL); 
{ int64_t _e259 = p_52; for (int64_t _k259 = s_63; _k259 < _e259; _k259++) { int64_t q_75 = (int64_t)_k259; uint64_t d_76 = ((uint64_t)(((uint8_t)((uint64_t)(*({ hrv *_t260 = &(g907); int64_t _i260 = q_75; (uint8_t*)_t260->b + hr_ix(_i260, _t260->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:105"); })) - (uint64_t)((uint8_t)48LL))))); 
if (((v_74) > (HR_UDIV(uint64_t, ((uint64_t)((uint64_t)((uint64_t)18446744073709551615ULL) - (uint64_t)d_76)), ((uint64_t)10LL), "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:105")))) { return f25_lerr(f_48, line_53, hr_str("integer literal too large for 64 bits", 37));
 }
v_74 = ((uint64_t)((uint64_t)((uint64_t)((uint64_t)v_74 * (uint64_t)((uint64_t)10LL))) + (uint64_t)d_76));
 } } _bk258:; 
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t263 = &(((*({ hrv *_t264 = &(g913); int64_t _i264 = ((int64_t)((int64_t)(g913).n - (int64_t)((int64_t)1LL))); (S3*)_t264->b + hr_ix(_i264, _t264->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:106"); }))).v_); *_t263 = ((int64_t)(v_74)); }
{ bool *_t265 = &(((*({ hrv *_t266 = &(g913); int64_t _i266 = ((int64_t)((int64_t)(g913).n - (int64_t)((int64_t)1LL))); (S3*)_t266->b + hr_ix(_i266, _t266->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:106"); }))).uns_); *_t265 = ((v_74) > (((uint64_t)9223372036854775807LL))); }
continue;
 }
if (f29_idc(c_57)) { while (f29_idc((*({ hrv *_t270 = &(g907); int64_t _i270 = p_52; (uint8_t*)_t270->b + hr_ix(_i270, _t270->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:109"); })))) { p_52++;
 } _bk268:; 
int64_t id_78 = f8_intern(({ hsl _t272 = hr_sl(g907); int64_t _l272 = s_63, _h272 = p_52; if (_l272 < 0 || _h272 < _l272 || _h272 > _t272.n) hr_slerr(_l272, _h272, _t272.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:110"); (hsl){ _t272.p + _l272 * (int64_t)sizeof(uint8_t), _h272 - _l272 }; })); 
int64_t k_79 = ({ int64_t _r273; if (((id_78) < (((int64_t)49LL)))) { _r273 = ((int64_t)((int64_t)((int64_t)56LL) + (int64_t)id_78));  } else { _r273 = ((int64_t)1LL);  } _r273; }); 
if (((!(amni_51)) && ((k_79) >= (((int64_t)101LL))))) { k_79 = ((int64_t)1LL);
 }
(void)(f23_put(k_79, s_63, p_52, &f_48, &line_53));
{ int64_t *_t275 = &(((*({ hrv *_t276 = &(g913); int64_t _i276 = ((int64_t)((int64_t)(g913).n - (int64_t)((int64_t)1LL))); (S3*)_t276->b + hr_ix(_i276, _t276->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:113"); }))).v_); *_t275 = id_78; }
continue;
 }
if (((c_57) == (((uint8_t)39LL)))) { p_52++;
int64_t v_86 = f30_esc((&(p_52)), f_48, line_53); 
if (((v_86) < (((int64_t)0LL)))) { return false;
 }
if ((((*({ hrv *_t278 = &(g907); int64_t _i278 = p_52; (uint8_t*)_t278->b + hr_ix(_i278, _t278->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:119"); }))) != (((uint8_t)39LL)))) { return f25_lerr(f_48, line_53, hr_str("expected closing ' of character literal", 39));
 }
p_52++;
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t281 = &(((*({ hrv *_t282 = &(g913); int64_t _i282 = ((int64_t)((int64_t)(g913).n - (int64_t)((int64_t)1LL))); (S3*)_t282->b + hr_ix(_i282, _t282->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:120"); }))).v_); *_t281 = v_86; }
continue;
 }
if (((c_57) == (((uint8_t)34LL)))) { int64_t ss_87 = (g909).n; 
bool ml_88 = false; 
if ((((n1_64) == (((uint8_t)34LL))) && ((n2_65) == (((uint8_t)34LL))))) { { int64_t *_t283 = &(p_52); *_t283 = ((int64_t)((int64_t)(*_t283) + (int64_t)((int64_t)3LL))); }
int64_t q_89 = p_52; 
while ((((((*({ hrv *_t285 = &(g907); int64_t _i285 = q_89; (uint8_t*)_t285->b + hr_ix(_i285, _t285->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:127"); }))) == (((uint8_t)32LL))) || (((*({ hrv *_t286 = &(g907); int64_t _i286 = q_89; (uint8_t*)_t286->b + hr_ix(_i286, _t286->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:127"); }))) == (((uint8_t)9LL)))) || (((*({ hrv *_t287 = &(g907); int64_t _i287 = q_89; (uint8_t*)_t287->b + hr_ix(_i287, _t287->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:127"); }))) == (((uint8_t)13LL))))) { q_89++;
 } _bk284:; 
if ((((*({ hrv *_t288 = &(g907); int64_t _i288 = q_89; (uint8_t*)_t288->b + hr_ix(_i288, _t288->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:128"); }))) != (((uint8_t)10LL)))) { while ((!((((((*({ hrv *_t290 = &(g907); int64_t _i290 = p_52; (uint8_t*)_t290->b + hr_ix(_i290, _t290->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)34LL))) && (((*({ hrv *_t291 = &(g907); int64_t _i291 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t291->b + hr_ix(_i291, _t291->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)34LL)))) && (((*({ hrv *_t292 = &(g907); int64_t _i292 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t292->b + hr_ix(_i292, _t292->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)34LL))))))) { if (((((*({ hrv *_t293 = &(g907); int64_t _i293 = p_52; (uint8_t*)_t293->b + hr_ix(_i293, _t293->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)0LL))) || (((*({ hrv *_t294 = &(g907); int64_t _i294 = p_52; (uint8_t*)_t294->b + hr_ix(_i294, _t294->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)10LL))))) { return f25_lerr(f_48, line_53, hr_str("unterminated \"\"\" string", 23));
 }
(void)(({ hrv *_v296 = &(g909); uint8_t _x296 = (*({ hrv *_t297 = &(g907); int64_t _i297 = p_52; (uint8_t*)_t297->b + hr_ix(_i297, _t297->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); })); uint8_t *_p296 = (uint8_t*)hr_grow(_v296, 1, sizeof _x296); *_p296 = _x296; _p296; }));
p_52++;
 } _bk289:; 
{ int64_t *_t298 = &(p_52); *_t298 = ((int64_t)((int64_t)(*_t298) + (int64_t)((int64_t)3LL))); }
 } else { ml_88 = true;
int64_t first_90 = ((int64_t)((int64_t)q_89 + (int64_t)((int64_t)1LL))); 
int64_t close_91 = first_90; 
while ((!((((((*({ hrv *_t300 = &(g907); int64_t _i300 = close_91; (uint8_t*)_t300->b + hr_ix(_i300, _t300->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)34LL))) && (((*({ hrv *_t301 = &(g907); int64_t _i301 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)1LL))); (uint8_t*)_t301->b + hr_ix(_i301, _t301->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)34LL)))) && (((*({ hrv *_t302 = &(g907); int64_t _i302 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)2LL))); (uint8_t*)_t302->b + hr_ix(_i302, _t302->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)34LL))))))) { if ((((*({ hrv *_t303 = &(g907); int64_t _i303 = close_91; (uint8_t*)_t303->b + hr_ix(_i303, _t303->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("unterminated \"\"\" string", 23));
 }
close_91++;
 } _bk299:; 
int64_t cs_92 = close_91; 
while ((((cs_92) > (first_90)) && (((*({ hrv *_t306 = &(g907); int64_t _i306 = ((int64_t)((int64_t)cs_92 - (int64_t)((int64_t)1LL))); (uint8_t*)_t306->b + hr_ix(_i306, _t306->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:136"); }))) != (((uint8_t)10LL))))) { cs_92--;
 } _bk305:; 
int64_t mg_93 = ((int64_t)((int64_t)close_91 - (int64_t)cs_92)); 
{ int64_t _e308 = close_91; for (int64_t _k308 = cs_92; _k308 < _e308; _k308++) { int64_t q2_94 = (int64_t)_k308; if (((((*({ hrv *_t309 = &(g907); int64_t _i309 = q2_94; (uint8_t*)_t309->b + hr_ix(_i309, _t309->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:138"); }))) != (((uint8_t)32LL))) && (((*({ hrv *_t310 = &(g907); int64_t _i310 = q2_94; (uint8_t*)_t310->b + hr_ix(_i310, _t310->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:138"); }))) != (((uint8_t)9LL))))) { return f25_lerr(f_48, line_53, hr_str("only indentation may come before the closing \"\"\" of a multi-line string", 71));
 }
 } } _bk307:; 
int64_t l_95 = first_90; 
while (((l_95) < (cs_92))) { int64_t e_96 = l_95; 
while ((((*({ hrv *_t314 = &(g907); int64_t _i314 = e_96; (uint8_t*)_t314->b + hr_ix(_i314, _t314->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:141"); }))) != (((uint8_t)10LL)))) { e_96++;
 } _bk313:; 
int64_t te_97 = e_96; 
if ((((te_97) > (l_95)) && (((*({ hrv *_t315 = &(g907); int64_t _i315 = ((int64_t)((int64_t)te_97 - (int64_t)((int64_t)1LL))); (uint8_t*)_t315->b + hr_ix(_i315, _t315->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:142"); }))) == (((uint8_t)13LL))))) { te_97--;
 }
if (((l_95) != (first_90))) { (void)(({ hrv *_v316 = &(g909); uint8_t _x316 = ((uint8_t)10LL); uint8_t *_p316 = (uint8_t*)hr_grow(_v316, 1, sizeof _x316); *_p316 = _x316; _p316; }));
 }
bool ok_98 = ((((int64_t)((int64_t)te_97 - (int64_t)l_95))) >= (mg_93)); 
if (ok_98) { { int64_t _e318 = mg_93; for (int64_t _k318 = 0; _k318 < _e318; _k318++) { int64_t k_99 = (int64_t)_k318; if ((((*({ hrv *_t319 = &(g907); int64_t _i319 = ((int64_t)((int64_t)l_95 + (int64_t)k_99)); (uint8_t*)_t319->b + hr_ix(_i319, _t319->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:144"); }))) != ((*({ hrv *_t320 = &(g907); int64_t _i320 = ((int64_t)((int64_t)cs_92 + (int64_t)k_99)); (uint8_t*)_t320->b + hr_ix(_i320, _t320->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:144"); }))))) { ok_98 = false;
 }
 } } _bk317:; 
 }
if (ok_98) { (void)(({ hrv *_v321 = &(g909); hsl _s321 = ({ hsl _t322 = hr_sl(g907); int64_t _l322 = ((int64_t)((int64_t)l_95 + (int64_t)mg_93)), _h322 = te_97; if (_l322 < 0 || _h322 < _l322 || _h322 > _t322.n) hr_slerr(_l322, _h322, _t322.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:145"); (hsl){ _t322.p + _l322 * (int64_t)sizeof(uint8_t), _h322 - _l322 }; }); hr_append(_v321, _s321.p, _s321.n, sizeof(uint8_t)); }));
 } else { { int64_t _e324 = te_97; for (int64_t _k324 = l_95; _k324 < _e324; _k324++) { int64_t k_100 = (int64_t)_k324; if (((((*({ hrv *_t325 = &(g907); int64_t _i325 = k_100; (uint8_t*)_t325->b + hr_ix(_i325, _t325->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:145"); }))) != (((uint8_t)32LL))) && (((*({ hrv *_t326 = &(g907); int64_t _i326 = k_100; (uint8_t*)_t326->b + hr_ix(_i326, _t326->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:145"); }))) != (((uint8_t)9LL))))) { return f25_lerr(f_48, line_53, hr_str("a line of a multi-line string must start with the indentation of its closing \"\"\"", 80));
 }
 } } _bk323:; 
 }
l_95 = ((int64_t)((int64_t)e_96 + (int64_t)((int64_t)1LL)));
 } _bk312:; 
{ int64_t _e329 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)3LL))); for (int64_t _k329 = p_52; _k329 < _e329; _k329++) { int64_t k_101 = (int64_t)_k329; if ((((*({ hrv *_t330 = &(g907); int64_t _i330 = k_101; (uint8_t*)_t330->b + hr_ix(_i330, _t330->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:148"); }))) == (((uint8_t)10LL)))) { line_53++;
 }
 } } _bk328:; 
p_52 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)3LL)));
 }
 } else { p_52++;
while ((((*({ hrv *_t332 = &(g907); int64_t _i332 = p_52; (uint8_t*)_t332->b + hr_ix(_i332, _t332->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:153"); }))) != (((uint8_t)34LL)))) { if (((((*({ hrv *_t333 = &(g907); int64_t _i333 = p_52; (uint8_t*)_t333->b + hr_ix(_i333, _t333->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:153"); }))) == (((uint8_t)10LL))) || (((*({ hrv *_t334 = &(g907); int64_t _i334 = p_52; (uint8_t*)_t334->b + hr_ix(_i334, _t334->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:153"); }))) == (((uint8_t)0LL))))) { return f25_lerr(f_48, line_53, hr_str("unterminated string literal", 27));
 }
int64_t v_102 = f30_esc((&(p_52)), f_48, line_53); 
if (((v_102) < (((int64_t)0LL)))) { return false;
 }
(void)(({ hrv *_v337 = &(g909); uint8_t _x337 = ((uint8_t)(v_102)); uint8_t *_p337 = (uint8_t*)hr_grow(_v337, 1, sizeof _x337); *_p337 = _x337; _p337; }));
 } _bk331:; 
p_52++;
 }
(void)(f23_put(((int64_t)4LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t339 = &(((*({ hrv *_t340 = &(g913); int64_t _i340 = ((int64_t)((int64_t)(g913).n - (int64_t)((int64_t)1LL))); (S3*)_t340->b + hr_ix(_i340, _t340->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:156"); }))).v_); *_t339 = ss_87; }
{ int32_t *_t341 = &(((*({ hrv *_t342 = &(g913); int64_t _i342 = ((int64_t)((int64_t)(g913).n - (int64_t)((int64_t)1LL))); (S3*)_t342->b + hr_ix(_i342, _t342->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:156"); }))).w_); *_t341 = ((int32_t)(((int64_t)((int64_t)(g909).n - (int64_t)ss_87)))); }
{ bool *_t343 = &(((*({ hrv *_t344 = &(g913); int64_t _i344 = ((int64_t)((int64_t)(g913).n - (int64_t)((int64_t)1LL))); (S3*)_t344->b + hr_ix(_i344, _t344->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:156"); }))).ml_); *_t343 = ml_88; }
continue;
 }
p_52++;
int64_t k_103 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((c_57) == (((uint8_t)40LL)))) { k_103 = ((int64_t)5LL);
 } else { if (((c_57) == (((uint8_t)41LL)))) { k_103 = ((int64_t)6LL);
 } else { if (((c_57) == (((uint8_t)91LL)))) { k_103 = ((int64_t)7LL);
 } else { if (((c_57) == (((uint8_t)93LL)))) { k_103 = ((int64_t)8LL);
 } else { if (((c_57) == (((uint8_t)123LL)))) { k_103 = ((int64_t)9LL);
 } else { if (((c_57) == (((uint8_t)125LL)))) { k_103 = ((int64_t)10LL);
 } else { if (((c_57) == (((uint8_t)44LL)))) { k_103 = ((int64_t)11LL);
 } else { if (((c_57) == (((uint8_t)59LL)))) { k_103 = ((int64_t)12LL);
 } else { if (((c_57) == (((uint8_t)63LL)))) { k_103 = ((int64_t)14LL);
 } else { if (((c_57) == (((uint8_t)126LL)))) { k_103 = ((int64_t)48LL);
 }
 }
 }
 }
 }
 }
 }
 }
 }
 }
if (((c_57) == (((uint8_t)58LL)))) { if (((n1_64) == (((uint8_t)58LL)))) { p_52++;
k_103 = ((int64_t)15LL);
 } else { k_103 = ((int64_t)13LL);
 }
 }
if (((c_57) == (((uint8_t)46LL)))) { if (((n1_64) == (((uint8_t)46LL)))) { p_52++;
k_103 = ((int64_t)17LL);
 } else { if ((((n1_64) == (((uint8_t)61LL))) && ((n2_65) == (((uint8_t)61LL))))) { { int64_t *_t345 = &(p_52); *_t345 = ((int64_t)((int64_t)(*_t345) + (int64_t)((int64_t)2LL))); }
k_103 = ((int64_t)19LL);
 } else { if ((((n1_64) == (((uint8_t)33LL))) && ((n2_65) == (((uint8_t)61LL))))) { { int64_t *_t346 = &(p_52); *_t346 = ((int64_t)((int64_t)(*_t346) + (int64_t)((int64_t)2LL))); }
k_103 = ((int64_t)20LL);
 } else { if (((n1_64) == (((uint8_t)61LL)))) { p_52++;
k_103 = ((int64_t)18LL);
 } else { k_103 = ((int64_t)16LL);
 }
 }
 }
 }
 }
if (((c_57) == (((uint8_t)43LL)))) { if (((n1_64) == (((uint8_t)43LL)))) { p_52++;
k_103 = ((int64_t)34LL);
 } else { if (((n1_64) == (((uint8_t)61LL)))) { p_52++;
k_103 = ((int64_t)26LL);
 } else { k_103 = ((int64_t)21LL);
 }
 }
 }
if (((c_57) == (((uint8_t)45LL)))) { if (((n1_64) == (((uint8_t)45LL)))) { p_52++;
k_103 = ((int64_t)35LL);
 } else { if (((n1_64) == (((uint8_t)61LL)))) { p_52++;
k_103 = ((int64_t)27LL);
 } else { if (((n1_64) == (((uint8_t)62LL)))) { p_52++;
k_103 = ((int64_t)54LL);
 } else { k_103 = ((int64_t)22LL);
 }
 }
 }
 }
if (((c_57) == (((uint8_t)42LL)))) { if (((n1_64) == (((uint8_t)61LL)))) { p_52++;
k_103 = ((int64_t)28LL);
 } else { k_103 = ((int64_t)23LL);
 }
 }
if (((c_57) == (((uint8_t)47LL)))) { if (((n1_64) == (((uint8_t)61LL)))) { p_52++;
k_103 = ((int64_t)29LL);
 } else { k_103 = ((int64_t)24LL);
 }
 }
if (((c_57) == (((uint8_t)37LL)))) { if (((n1_64) == (((uint8_t)61LL)))) { p_52++;
k_103 = ((int64_t)30LL);
 } else { k_103 = ((int64_t)25LL);
 }
 }
if (((c_57) == (((uint8_t)61LL)))) { if (((n1_64) == (((uint8_t)61LL)))) { p_52++;
k_103 = ((int64_t)37LL);
 } else { if (((n1_64) == (((uint8_t)62LL)))) { p_52++;
k_103 = ((int64_t)55LL);
 } else { k_103 = ((int64_t)36LL);
 }
 }
 }
if (((c_57) == (((uint8_t)33LL)))) { if (((n1_64) == (((uint8_t)61LL)))) { p_52++;
k_103 = ((int64_t)38LL);
 } else { k_103 = ((int64_t)47LL);
 }
 }
if (((c_57) == (((uint8_t)60LL)))) { if (((n1_64) == (((uint8_t)61LL)))) { p_52++;
k_103 = ((int64_t)41LL);
 } else { if ((((n1_64) == (((uint8_t)60LL))) && ((n2_65) == (((uint8_t)61LL))))) { { int64_t *_t347 = &(p_52); *_t347 = ((int64_t)((int64_t)(*_t347) + (int64_t)((int64_t)2LL))); }
k_103 = ((int64_t)45LL);
 } else { if (((n1_64) == (((uint8_t)60LL)))) { p_52++;
k_103 = ((int64_t)43LL);
 } else { k_103 = ((int64_t)39LL);
 }
 }
 }
 }
if (((c_57) == (((uint8_t)62LL)))) { if (((n1_64) == (((uint8_t)61LL)))) { p_52++;
k_103 = ((int64_t)42LL);
 } else { if ((((n1_64) == (((uint8_t)62LL))) && ((n2_65) == (((uint8_t)61LL))))) { { int64_t *_t348 = &(p_52); *_t348 = ((int64_t)((int64_t)(*_t348) + (int64_t)((int64_t)2LL))); }
k_103 = ((int64_t)46LL);
 } else { if (((n1_64) == (((uint8_t)62LL)))) { p_52++;
k_103 = ((int64_t)44LL);
 } else { k_103 = ((int64_t)40LL);
 }
 }
 }
 }
if (((c_57) == (((uint8_t)38LL)))) { if (((n1_64) == (((uint8_t)38LL)))) { p_52++;
k_103 = ((int64_t)52LL);
 } else { if (((n1_64) == (((uint8_t)61LL)))) { p_52++;
k_103 = ((int64_t)31LL);
 } else { k_103 = ((int64_t)49LL);
 }
 }
 }
if (((c_57) == (((uint8_t)124LL)))) { if (((n1_64) == (((uint8_t)124LL)))) { p_52++;
k_103 = ((int64_t)53LL);
 } else { if (((n1_64) == (((uint8_t)61LL)))) { p_52++;
k_103 = ((int64_t)32LL);
 } else { k_103 = ((int64_t)50LL);
 }
 }
 }
if (((c_57) == (((uint8_t)94LL)))) { if (((n1_64) == (((uint8_t)61LL)))) { p_52++;
k_103 = ((int64_t)33LL);
 } else { k_103 = ((int64_t)51LL);
 }
 }
if (((k_103) < (((int64_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("illegal character", 17));
 }
(void)(f23_put(k_103, s_63, p_52, &f_48, &line_53));
 } _bk189:; 
return true;
}
static void f23_put(int64_t k_54, int64_t s_55, int64_t e_56, int64_t *c48, int64_t *c53) {
(void)(({ hrv *_v351 = &(g913); S3 _x351 = ((S3){ .k_ = ((uint8_t)(k_54)), .f_ = ((uint16_t)((*c48))), .line_ = ((int32_t)((*c53))), .s_ = ((int32_t)(s_55)), .n_ = ((int32_t)(((int64_t)((int64_t)e_56 - (int64_t)s_55)))), }); S3 *_p351 = (S3*)hr_grow(_v351, 1, sizeof _x351); *_p351 = _x351; _p351; }));
}
static bool f25_lerr(int64_t f_60, int64_t line_61, hsl m_62) {
if ((((g914).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v352 = &(g914); hsl _s352 = f10_nm(((int64_t)(((*({ hrv *_t354 = &(g912); int64_t _i354 = f_60; (S2*)_t354->b + hr_ix(_i354, _t354->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:52"); }))).name_))); hr_append(_v352, _s352.p, _s352.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o355 = &(g914); hr_fs(_o355, hr_str(":", 1)); hr_fi(_o355, line_61); hr_fs(_o355, hr_str(": error: ", 9)); hr_fs(_o355, m_62); }));
 }
return false;
}
static bool f26_dig(uint8_t c_66) {
return (((c_66) >= (((uint8_t)48LL))) && ((c_66) <= (((uint8_t)57LL))));
}
static bool f27_hexd(uint8_t c_68) {
return ((f26_dig(c_68) || (((c_68) >= (((uint8_t)97LL))) && ((c_68) <= (((uint8_t)102LL))))) || (((c_68) >= (((uint8_t)65LL))) && ((c_68) <= (((uint8_t)70LL)))));
}
static int64_t f28_hexv(uint8_t c_72) {
return ({ int64_t _r357; if (((c_72) <= (((uint8_t)57LL)))) { _r357 = ((int64_t)(((uint8_t)((uint64_t)c_72 - (uint64_t)((uint8_t)48LL)))));  } else { _r357 = ((int64_t)((int64_t)((int64_t)(((uint8_t)((uint64_t)((uint8_t)((uint64_t)c_72 | (uint64_t)((uint8_t)32LL))) - (uint64_t)((uint8_t)97LL))))) + (int64_t)((int64_t)10LL)));  } _r357; });
}
static bool f29_idc(uint8_t c_77) {
return ((((((c_77) >= (((uint8_t)97LL))) && ((c_77) <= (((uint8_t)122LL)))) || (((c_77) >= (((uint8_t)65LL))) && ((c_77) <= (((uint8_t)90LL))))) || ((c_77) == (((uint8_t)95LL)))) || (((c_77) >= (((uint8_t)48LL))) && ((c_77) <= (((uint8_t)57LL)))));
}
static int64_t f30_esc(int64_t* p_80, int64_t f_81, int64_t line_82) {
uint8_t c_83 = (*({ hrv *_t358 = &(g907); int64_t _i358 = (*p_80); (uint8_t*)_t358->b + hr_ix(_i358, _t358->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:54"); })); 
(*p_80)++;
if (((c_83) != (((uint8_t)92LL)))) { return ((int64_t)(c_83));
 }
uint8_t e_84 = (*({ hrv *_t359 = &(g907); int64_t _i359 = (*p_80); (uint8_t*)_t359->b + hr_ix(_i359, _t359->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:56"); })); 
(*p_80)++;
if (((e_84) == (((uint8_t)110LL)))) { return ((int64_t)10LL);
 }
if (((e_84) == (((uint8_t)116LL)))) { return ((int64_t)9LL);
 }
if (((e_84) == (((uint8_t)114LL)))) { return ((int64_t)13LL);
 }
if (((e_84) == (((uint8_t)48LL)))) { return ((int64_t)0LL);
 }
if (((((e_84) == (((uint8_t)92LL))) || ((e_84) == (((uint8_t)34LL)))) || ((e_84) == (((uint8_t)39LL))))) { return ((int64_t)(e_84));
 }
if (((((e_84) == (((uint8_t)120LL))) && f27_hexd((*({ hrv *_t361 = &(g907); int64_t _i361 = (*p_80); (uint8_t*)_t361->b + hr_ix(_i361, _t361->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); })))) && f27_hexd((*({ hrv *_t363 = &(g907); int64_t _i363 = ((int64_t)((int64_t)(*p_80) + (int64_t)((int64_t)1LL))); (uint8_t*)_t363->b + hr_ix(_i363, _t363->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); }))))) { int64_t v_85 = ((int64_t)((int64_t)((int64_t)((int64_t)f28_hexv((*({ hrv *_t365 = &(g907); int64_t _i365 = (*p_80); (uint8_t*)_t365->b + hr_ix(_i365, _t365->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); }))) * (int64_t)((int64_t)16LL))) + (int64_t)f28_hexv((*({ hrv *_t367 = &(g907); int64_t _i367 = ((int64_t)((int64_t)(*p_80) + (int64_t)((int64_t)1LL))); (uint8_t*)_t367->b + hr_ix(_i367, _t367->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); }))))); 
{ int64_t *_t368 = p_80; *_t368 = ((int64_t)((int64_t)(*_t368) + (int64_t)((int64_t)2LL))); }
return v_85;
 }
(void)(f25_lerr(f_81, line_82, hr_str("unknown escape sequence", 23)));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f31_tk(void) {
return ((int64_t)(((*({ hrv *_t370 = &(g913); int64_t _i370 = g708; (S3*)_t370->b + hr_ix(_i370, _t370->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:32"); }))).k_));
}
static void f32_ptop(void) {
int64_t st_104 = g708; 
g715 = g716;
int64_t k_105 = f31_tk(); 
if (((k_105) == (((int64_t)57LL)))) { (void)(f33_nx());
g716 = f34_ident(hr_str("namespace declaration", 21));
g715 = g716;
(void)(f39_ex(((int64_t)12LL), hr_str("namespace declaration", 21)));
return;
 }
if (((k_105) == (((int64_t)56LL)))) { (void)(f33_nx());
int64_t n_121 = f40_mk(((int64_t)54LL), st_104); 
if (f41_is(((int64_t)16LL))) { { uint16_t *_t378 = &(((*({ hrv *_t379 = &(g703); int64_t _i379 = n_121; (S4*)_t379->b + hr_ix(_i379, _t379->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:699"); }))).fl_); *_t378 = ((uint16_t)1LL); }
 }
hrv path_123 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v381 = &(path_123); hsl _s381 = f10_nm(f34_ident(hr_str("import", 6))); hr_append(_v381, _s381.p, _s381.n, sizeof(uint8_t)); }));
while (f41_is(((int64_t)16LL))) { (void)(({ hrv *_v386 = &(path_123); uint8_t _x386 = ((uint8_t)47LL); uint8_t *_p386 = (uint8_t*)hr_grow(_v386, 1, sizeof _x386); *_p386 = _x386; _p386; }));
(void)(({ hrv *_v387 = &(path_123); hsl _s387 = f10_nm(f34_ident(hr_str("import", 6))); hr_append(_v387, _s387.p, _s387.n, sizeof(uint8_t)); }));
 } _bk384:; 
{ int64_t q__124 = f8_intern(hr_sl(path_123)); 
{ int32_t *_t391 = &(((*({ hrv *_t392 = &(g703); int64_t _i392 = n_121; (S4*)_t392->b + hr_ix(_i392, _t392->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:703"); }))).s_); *_t391 = ((int32_t)(q__124)); }
 }
if ((f42_at_from() || f43_at_word(g720))) { (void)(f33_nx());
if (((f31_tk()) != (((int64_t)4LL)))) { (void)(f38_perr(hr_str("expected the package's source, a string, after from", 51)));
 }
{ int32_t *_t398 = &(((*({ hrv *_t399 = &(g703); int64_t _i399 = n_121; (S4*)_t399->b + hr_ix(_i399, _t399->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:704"); }))).a_); *_t398 = ((int32_t)(g708)); }
(void)(f33_nx());
 }
(void)(f39_ex(((int64_t)12LL), hr_str("import", 6)));
(void)(({ hrv *_v402 = &(g706); int32_t _x402 = ((int32_t)(n_121)); int32_t *_p402 = (int32_t*)hr_grow(_v402, 1, sizeof _x402); *_p402 = _x402; _p402; }));
return;
 }
if (((f46_at_inline() || f47_at_checkfree()) || f48_at_lut())) { (void)(({ hrv *_v406 = &(g706); int32_t _x406 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p406 = (int32_t*)hr_grow(_v406, 1, sizeof _x406); *_p406 = _x406; _p406; }));
return;
 }
if (((k_105) == (((int64_t)58LL)))) { (void)(({ hrv *_v408 = &(g706); int32_t _x408 = ((int32_t)(f94_pstruct())); int32_t *_p408 = (int32_t*)hr_grow(_v408, 1, sizeof _x408); *_p408 = _x408; _p408; }));
return;
 }
if (((k_105) == (((int64_t)59LL)))) { (void)(({ hrv *_v410 = &(g706); int32_t _x410 = ((int32_t)(f96_penum())); int32_t *_p410 = (int32_t*)hr_grow(_v410, 1, sizeof _x410); *_p410 = _x410; _p410; }));
return;
 }
if (((k_105) == (((int64_t)60LL)))) { (void)(f33_nx());
int64_t n_433 = f40_mk(((int64_t)53LL), st_104); 
{ int64_t q__434 = f50_declname(hr_str("type alias", 10)); 
{ int32_t *_t415 = &(((*({ hrv *_t416 = &(g703); int64_t _i416 = n_433; (S4*)_t416->b + hr_ix(_i416, _t416->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:712"); }))).s_); *_t415 = ((int32_t)(q__434)); }
 }
{ int32_t *_t417 = &(((*({ hrv *_t418 = &(g703); int64_t _i418 = n_433; (S4*)_t418->b + hr_ix(_i418, _t418->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:712"); }))).a_); *_t417 = ((int32_t)(g715)); }
(void)(f39_ex(((int64_t)36LL), hr_str("type alias", 10)));
{ int64_t q__435 = f53_ptype(); 
{ int32_t *_t421 = &(((*({ hrv *_t422 = &(g703); int64_t _i422 = n_433; (S4*)_t422->b + hr_ix(_i422, _t422->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:712"); }))).b_); *_t421 = ((int32_t)(q__435)); }
 }
(void)(f39_ex(((int64_t)12LL), hr_str("type alias", 10)));
(void)(({ hrv *_v424 = &(g706); int32_t _x424 = ((int32_t)(n_433)); int32_t *_p424 = (int32_t*)hr_grow(_v424, 1, sizeof _x424); *_p424 = _x424; _p424; }));
return;
 }
if (((k_105) == (((int64_t)68LL)))) { (void)(f33_nx());
int64_t cs_436 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((f31_tk()) == (((int64_t)4LL)))) { cs_436 = g708;
(void)(f33_nx());
 }
if (((f31_tk()) == (((int64_t)9LL)))) { if (((cs_436) < (((int64_t)0LL)))) { (void)(f38_perr(hr_str("an extern block names the library it binds from: extern \"lib\" {", 63)));
 }
(void)(f33_nx());
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v434 = &(g706); int32_t _x434 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), cs_436))); int32_t *_p434 = (int32_t*)hr_grow(_v434, 1, sizeof _x434); *_p434 = _x434; _p434; }));
 } _bk431:; 
(void)(f39_ex(((int64_t)10LL), hr_str("extern block", 12)));
return;
 }
g708--;
if (((cs_436) >= (((int64_t)0LL)))) { g708--;
 }
(void)(({ hrv *_v437 = &(g706); int32_t _x437 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p437 = (int32_t*)hr_grow(_v437, 1, sizeof _x437); *_p437 = _x437; _p437; }));
return;
 }
if (((((((k_105) == (((int64_t)65LL))) || ((k_105) == (((int64_t)61LL)))) || ((k_105) == (((int64_t)62LL)))) || ((k_105) == (((int64_t)63LL)))) || ((k_105) == (((int64_t)64LL))))) { (void)(({ hrv *_v439 = &(g706); int32_t _x439 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p439 = (int32_t*)hr_grow(_v439, 1, sizeof _x439); *_p439 = _x439; _p439; }));
return;
 }
if ((((((k_105) == (((int64_t)71LL))) || ((k_105) == (((int64_t)66LL)))) || ((k_105) == (((int64_t)67LL)))) || ((k_105) == (((int64_t)69LL))))) { int64_t v_437 = f74_pvdecl(true); 
(void)(f39_ex(((int64_t)12LL), hr_str("global declaration", 18)));
(void)(({ hrv *_v443 = &(g706); int32_t _x443 = ((int32_t)(v_437)); int32_t *_p443 = (int32_t*)hr_grow(_v443, 1, sizeof _x443); *_p443 = _x443; _p443; }));
return;
 }
hrv m_438 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o445 = &(m_438); hr_fs(_o445, hr_str("top-level declaration expected, found '", 39)); hr_fs(_o445, f35_cur_text()); hr_fs(_o445, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_438)));
}
static void f33_nx(void) {
if (((((*({ hrv *_t448 = &(g913); int64_t _i448 = g708; (S3*)_t448->b + hr_ix(_i448, _t448->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:34"); }))).k_) != (((uint8_t)0LL)))) { g708++;
 }
}
static int64_t f34_ident(hsl ctx_106) {
if (((f31_tk()) != (((int64_t)1LL)))) { hrv m_107 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o451 = &(m_107); hr_fs(_o451, hr_str("expected identifier in ", 23)); hr_fs(_o451, ctx_106); hr_fs(_o451, hr_str(", found '", 9)); hr_fs(_o451, f35_cur_text()); hr_fs(_o451, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_107)));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t v_115 = ((int64_t)(((*({ hrv *_t454 = &(g913); int64_t _i454 = g708; (S3*)_t454->b + hr_ix(_i454, _t454->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:51"); }))).v_)); 
(void)(f33_nx());
return v_115;
}
static hsl f35_cur_text(void) {
int64_t k_108 = f31_tk(); 
return ({ hsl _r457; if (((((k_108) == (((int64_t)1LL))) || ((k_108) == (((int64_t)2LL)))) || ((k_108) == (((int64_t)3LL))))) { _r457 = f36_tok_text(g708);  } else { _r457 = f37_tname(k_108);  } _r457; });
}
static hsl f36_tok_text(int64_t t_109) {
S3 x_110 = (*({ hrv *_t460 = &(g913); int64_t _i460 = t_109; (S3*)_t460->b + hr_ix(_i460, _t460->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:181"); })); 
return ({ hsl _t461 = hr_sl(g907); int64_t _l461 = ((int64_t)((x_110).s_)), _h461 = ((int64_t)(((int32_t)((int64_t)(x_110).s_ + (int64_t)(x_110).n_)))); if (_l461 < 0 || _h461 < _l461 || _h461 > _t461.n) hr_slerr(_l461, _h461, _t461.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:181"); (hsl){ _t461.p + _l461 * (int64_t)sizeof(uint8_t), _h461 - _l461 }; });
}
static hsl f37_tname(int64_t k_111) {
A39 pu_112 = ({ A39 _t462; _t462.e[0] = hr_str("(", 1); _t462.e[1] = hr_str(")", 1); _t462.e[2] = hr_str("[", 1); _t462.e[3] = hr_str("]", 1); _t462.e[4] = hr_str("{", 1); _t462.e[5] = hr_str("}", 1); _t462.e[6] = hr_str(",", 1); _t462.e[7] = hr_str(";", 1); _t462.e[8] = hr_str(":", 1); _t462.e[9] = hr_str("\077", 1); _t462.e[10] = hr_str("::", 2); _t462.e[11] = hr_str(".", 1); _t462.e[12] = hr_str("..", 2); _t462.e[13] = hr_str(".=", 2); _t462.e[14] = hr_str(".==", 3); _t462.e[15] = hr_str(".!=", 3); _t462.e[16] = hr_str("+", 1); _t462.e[17] = hr_str("-", 1); _t462.e[18] = hr_str("*", 1); _t462.e[19] = hr_str("/", 1); _t462.e[20] = hr_str("%", 1); _t462.e[21] = hr_str("+=", 2); _t462.e[22] = hr_str("-=", 2); _t462.e[23] = hr_str("*=", 2); _t462.e[24] = hr_str("/=", 2); _t462.e[25] = hr_str("%=", 2); _t462.e[26] = hr_str("&=", 2); _t462.e[27] = hr_str("|=", 2); _t462.e[28] = hr_str("^=", 2); _t462.e[29] = hr_str("++", 2); _t462.e[30] = hr_str("--", 2); _t462.e[31] = hr_str("=", 1); _t462.e[32] = hr_str("==", 2); _t462.e[33] = hr_str("!=", 2); _t462.e[34] = hr_str("<", 1); _t462.e[35] = hr_str(">", 1); _t462.e[36] = hr_str("<=", 2); _t462.e[37] = hr_str(">=", 2); _t462.e[38] = hr_str("<<", 2); _t462.e[39] = hr_str(">>", 2); _t462.e[40] = hr_str("<<=", 3); _t462.e[41] = hr_str(">>=", 3); _t462.e[42] = hr_str("!", 1); _t462.e[43] = hr_str("~", 1); _t462.e[44] = hr_str("&", 1); _t462.e[45] = hr_str("|", 1); _t462.e[46] = hr_str("^", 1); _t462.e[47] = hr_str("&&", 2); _t462.e[48] = hr_str("||", 2); _t462.e[49] = hr_str("->", 2); _t462.e[50] = hr_str("=>", 2); _t462; }); 
if (((k_111) == (((int64_t)0LL)))) { return hr_str("end of file", 11);
 }
if (((k_111) == (((int64_t)1LL)))) { return hr_str("identifier", 10);
 }
if (((k_111) == (((int64_t)2LL)))) { return hr_str("integer literal", 15);
 }
if (((k_111) == (((int64_t)3LL)))) { return hr_str("float literal", 13);
 }
if (((k_111) == (((int64_t)4LL)))) { return hr_str("string literal", 14);
 }
if (((k_111) >= (((int64_t)56LL)))) { return f10_nm(((int64_t)((int64_t)k_111 - (int64_t)((int64_t)56LL))));
 }
return (pu_112).e[hr_ix(((int64_t)((int64_t)k_111 - (int64_t)((int64_t)5LL))), 51, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:40")];
}
static void f38_perr(hsl m_113) {
if (((g710) > (((int64_t)0LL)))) { g711 = true;
g708 = ((int64_t)((int64_t)(g913).n - (int64_t)((int64_t)1LL)));
return;
 }
if ((((g709).n) > (((int64_t)0LL)))) { return;
 }
S3 t_114 = (*({ hrv *_t465 = &(g913); int64_t _i465 = g708; (S3*)_t465->b + hr_ix(_i465, _t465->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:45"); })); 
(void)(({ hrv *_v466 = &(g709); hsl _s466 = f10_nm(((int64_t)(((*({ hrv *_t468 = &(g912); int64_t _i468 = (t_114).f_; (S2*)_t468->b + hr_ix(_i468, _t468->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:46"); }))).name_))); hr_append(_v466, _s466.p, _s466.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o469 = &(g709); hr_fs(_o469, hr_str(":", 1)); hr_fi(_o469, (t_114).line_); hr_fs(_o469, hr_str(": error: ", 9)); hr_fs(_o469, m_113); }));
g708 = ((int64_t)((int64_t)(g913).n - (int64_t)((int64_t)1LL)));
}
static void f39_ex(int64_t k_116, hsl ctx_117) {
if (((f31_tk()) != (k_116))) { hrv m_118 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o472 = &(m_118); hr_fs(_o472, hr_str("expected '", 10)); hr_fs(_o472, f37_tname(k_116)); hr_fs(_o472, hr_str("' in ", 5)); hr_fs(_o472, ctx_117); hr_fs(_o472, hr_str(", found '", 9)); hr_fs(_o472, f35_cur_text()); hr_fs(_o472, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_118)));
return;
 }
(void)(f33_nx());
}
static int64_t f40_mk(int64_t k_119, int64_t t_120) {
(void)(({ hrv *_v477 = &(g703); S4 _x477 = ((S4){ .k_ = ((uint8_t)(k_119)), .t_ = ((int32_t)(t_120)), .a_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .b_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .d_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .e_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .s_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .l_ = ((int32_t)0LL), .n_ = ((int32_t)0LL), }); S4 *_p477 = (S4*)hr_grow(_v477, 1, sizeof _x477); *_p477 = _x477; _p477; }));
return ((int64_t)((int64_t)(g703).n - (int64_t)((int64_t)1LL)));
}
static bool f41_is(int64_t k_122) {
if (((f31_tk()) == (k_122))) { (void)(f33_nx());
return true;
 }
return false;
}
static bool f42_at_from(void) {
return (f43_at_word(g720) && (((f44_tkat(((int64_t)((int64_t)g708 + (int64_t)((int64_t)1LL))))) == (((int64_t)1LL))) || ((f44_tkat(((int64_t)((int64_t)g708 + (int64_t)((int64_t)1LL))))) == (((int64_t)15LL)))));
}
static bool f43_at_word(int64_t w_125) {
return (((f31_tk()) == (((int64_t)1LL))) && ((((*({ hrv *_t484 = &(g913); int64_t _i484 = g708; (S3*)_t484->b + hr_ix(_i484, _t484->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:69"); }))).v_) == (w_125)));
}
static int64_t f44_tkat(int64_t i_126) {
return ((int64_t)(((*({ hrv *_t485 = &(g913); int64_t _i485 = f45_min(i_126, ((int64_t)((int64_t)(g913).n - (int64_t)((int64_t)1LL)))); (S3*)_t485->b + hr_ix(_i485, _t485->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:33"); }))).k_));
}
static int64_t f45_min(int64_t a_127, int64_t b_128) {
if (((b_128) < (a_127))) { return b_128;
 }
return a_127;
}
static bool f46_at_inline(void) {
return (f43_at_word(g721) && ((((f44_tkat(((int64_t)((int64_t)g708 + (int64_t)((int64_t)1LL))))) == (((int64_t)61LL))) || ((f44_tkat(((int64_t)((int64_t)g708 + (int64_t)((int64_t)1LL))))) == (((int64_t)65LL)))) || ((f44_tkat(((int64_t)((int64_t)g708 + (int64_t)((int64_t)1LL))))) == (((int64_t)62LL)))));
}
static bool f47_at_checkfree(void) {
int64_t n_129 = f44_tkat(((int64_t)((int64_t)g708 + (int64_t)((int64_t)1LL)))); 
return (f43_at_word(g722) && (((((((n_129) == (((int64_t)61LL))) || ((n_129) == (((int64_t)65LL)))) || ((n_129) == (((int64_t)62LL)))) || ((n_129) == (((int64_t)64LL)))) || ((n_129) == (((int64_t)68LL)))) || ((n_129) == (((int64_t)1LL)))));
}
static bool f48_at_lut(void) {
return (f43_at_word(g723) && ((f44_tkat(((int64_t)((int64_t)g708 + (int64_t)((int64_t)1LL))))) == (((int64_t)61LL))));
}
static int64_t f49_pfn(bool nested_130, int64_t cname_131, int64_t dylib_132) {
int64_t st_133 = g708; 
int64_t n_134 = f40_mk(((int64_t)50LL), st_133); 
int64_t fl_135 = ({ int64_t _r496; if (nested_130) { _r496 = ((int64_t)128LL);  } else { _r496 = ((int64_t)0LL);  } _r496; }); 
int64_t cn_136 = cname_131; 
if ((((cname_131) >= (((int64_t)0LL))) || ((dylib_132) >= (((int64_t)0LL))))) { { int64_t *_t497 = &(fl_135); *_t497 = ((int64_t)((int64_t)(*_t497) | (int64_t)((int64_t)1LL))); }
 }
if (f48_at_lut()) { (void)(f33_nx());
{ int64_t *_t500 = &(fl_135); *_t500 = ((int64_t)((int64_t)(*_t500) | (int64_t)((int64_t)256LL))); }
 }
if (f47_at_checkfree()) { (void)(f33_nx());
{ int64_t *_t503 = &(fl_135); *_t503 = ((int64_t)((int64_t)(*_t503) | (int64_t)((int64_t)64LL))); }
 }
if (f41_is(((int64_t)63LL))) { { int64_t *_t505 = &(fl_135); *_t505 = ((int64_t)((int64_t)(*_t505) | (int64_t)((int64_t)2LL))); }
if (((f31_tk()) == (((int64_t)4LL)))) { cn_136 = g708;
(void)(f33_nx());
 }
 }
if (f41_is(((int64_t)68LL))) { { int64_t *_t509 = &(fl_135); *_t509 = ((int64_t)((int64_t)(*_t509) | (int64_t)((int64_t)1LL))); }
if (((f31_tk()) == (((int64_t)4LL)))) { cn_136 = g708;
(void)(f33_nx());
 }
 }
if (f47_at_checkfree()) { (void)(f33_nx());
{ int64_t *_t514 = &(fl_135); *_t514 = ((int64_t)((int64_t)(*_t514) | (int64_t)((int64_t)64LL))); }
 }
if (f41_is(((int64_t)64LL))) { { int64_t *_t516 = &(fl_135); *_t516 = ((int64_t)((int64_t)(*_t516) | (int64_t)((int64_t)4LL))); }
 }
if (f46_at_inline()) { (void)(f33_nx());
{ int64_t *_t519 = &(fl_135); *_t519 = ((int64_t)((int64_t)(*_t519) | (int64_t)((int64_t)8LL))); }
 }
if (f41_is(((int64_t)65LL))) { { int64_t *_t521 = &(fl_135); *_t521 = ((int64_t)((int64_t)(*_t521) | (int64_t)((int64_t)16LL))); }
 }
if (f41_is(((int64_t)62LL))) { { int64_t *_t523 = &(fl_135); *_t523 = ((int64_t)((int64_t)(*_t523) | (int64_t)((int64_t)32LL))); }
 } else { (void)(f39_ex(((int64_t)61LL), hr_str("function declaration", 20)));
 }
{ int64_t q__139 = ({ int64_t _r525; if (nested_130) { _r525 = f34_ident(hr_str("function declaration", 20));  } else { _r525 = f50_declname(hr_str("function declaration", 20));  } _r525; }); 
{ int32_t *_t528 = &(((*({ hrv *_t529 = &(g703); int64_t _i529 = n_134; (S4*)_t529->b + hr_ix(_i529, _t529->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:657"); }))).s_); *_t528 = ((int32_t)(q__139)); }
 }
{ int32_t *_t530 = &(((*({ hrv *_t531 = &(g703); int64_t _i531 = n_134; (S4*)_t531->b + hr_ix(_i531, _t531->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:658"); }))).a_); *_t530 = ((int32_t)(g715)); }
{ int64_t q__403 = f51_pgenerics(); 
{ int32_t *_t533 = &(((*({ hrv *_t534 = &(g703); int64_t _i534 = n_134; (S4*)_t534->b + hr_ix(_i534, _t534->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:659"); }))).d_); *_t533 = ((int32_t)(q__403)); }
 }
(void)(f39_ex(((int64_t)5LL), hr_str("function declaration", 20)));
int64_t m_404 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t p_405 = f40_mk(((int64_t)32LL), g708); 
if (f41_is(((int64_t)67LL))) { { uint16_t *_t542 = &(((*({ hrv *_t543 = &(g703); int64_t _i543 = p_405; (S4*)_t543->b + hr_ix(_i543, _t543->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:664"); }))).fl_); *_t542 = ((uint16_t)1LL); }
 }
{ int64_t q__406 = f34_ident(hr_str("parameter list", 14)); 
{ int32_t *_t545 = &(((*({ hrv *_t546 = &(g703); int64_t _i546 = p_405; (S4*)_t546->b + hr_ix(_i546, _t546->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:665"); }))).s_); *_t545 = ((int32_t)(q__406)); }
 }
if ((f41_is(((int64_t)13LL)) || f75_amni_type())) { { int64_t q__407 = f53_ptype(); 
{ int32_t *_t550 = &(((*({ hrv *_t551 = &(g703); int64_t _i551 = p_405; (S4*)_t551->b + hr_ix(_i551, _t551->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:666"); }))).a_); *_t550 = ((int32_t)(q__407)); }
 }
 }
if (f41_is(((int64_t)36LL))) { { int64_t q__408 = f61_pexpr(); 
{ int32_t *_t554 = &(((*({ hrv *_t555 = &(g703); int64_t _i555 = p_405; (S4*)_t555->b + hr_ix(_i555, _t555->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:667"); }))).b_); *_t554 = ((int32_t)(q__408)); }
 }
 }
(void)(({ hrv *_v556 = &(g705); int32_t _x556 = ((int32_t)(p_405)); int32_t *_p556 = (int32_t*)hr_grow(_v556, 1, sizeof _x556); *_p556 = _x556; _p556; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk537; }
 }
 } _bk537:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function declaration", 20)));
(void)(f59_setl(n_134, m_404));
if ((f41_is(((int64_t)54LL)) || f75_amni_type())) { { int64_t *_t562 = &(fl_135); *_t562 = ((int64_t)((int64_t)(*_t562) | (int64_t)((int64_t)512LL))); }
int64_t r_409 = f40_mk(((int64_t)36LL), g708); 
int64_t m2_410 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v566 = &(g705); int32_t _x566 = ((int32_t)(f53_ptype())); int32_t *_p566 = (int32_t*)hr_grow(_v566, 1, sizeof _x566); *_p566 = _x566; _p566; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk565; }
 }
 } _bk565:; 
(void)(f59_setl(r_409, m2_410));
{ int32_t *_t570 = &(((*({ hrv *_t571 = &(g703); int64_t _i571 = n_134; (S4*)_t571->b + hr_ix(_i571, _t571->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:677"); }))).b_); *_t570 = ((int32_t)(r_409)); }
 }
if (((((int64_t)((int64_t)fl_135 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)))) { if (f41_is(((int64_t)36LL))) { if (((f31_tk()) != (((int64_t)4LL)))) { (void)(f38_perr(hr_str("an extern fn's symbol is a string: fn name(...) = \"symbol\"; (\302\2477.10)", 68)));
 }
cn_136 = g708;
(void)(f33_nx());
 }
(void)(f39_ex(((int64_t)12LL), hr_str("extern declaration", 18)));
int64_t x_411 = f40_mk(((int64_t)58LL), st_133); 
{ int32_t *_t578 = &(((*({ hrv *_t579 = &(g703); int64_t _i579 = x_411; (S4*)_t579->b + hr_ix(_i579, _t579->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:682"); }))).a_); *_t578 = ((int32_t)(cn_136)); }
{ int32_t *_t580 = &(((*({ hrv *_t581 = &(g703); int64_t _i581 = x_411; (S4*)_t581->b + hr_ix(_i581, _t581->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:682"); }))).b_); *_t580 = ((int32_t)(dylib_132)); }
{ int32_t *_t582 = &(((*({ hrv *_t583 = &(g703); int64_t _i583 = n_134; (S4*)_t583->b + hr_ix(_i583, _t583->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:682"); }))).e_); *_t582 = ((int32_t)(x_411)); }
 } else { if (((((int64_t)((int64_t)fl_135 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { int64_t x_412 = f40_mk(((int64_t)58LL), st_133); 
{ int32_t *_t585 = &(((*({ hrv *_t586 = &(g703); int64_t _i586 = x_412; (S4*)_t586->b + hr_ix(_i586, _t586->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:684"); }))).a_); *_t585 = ((int32_t)(cn_136)); }
{ int32_t *_t587 = &(((*({ hrv *_t588 = &(g703); int64_t _i588 = n_134; (S4*)_t588->b + hr_ix(_i588, _t588->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:684"); }))).e_); *_t587 = ((int32_t)(x_412)); }
 }
{ int64_t q__413 = f66_pblock(hr_str("function body", 13)); 
{ int32_t *_t590 = &(((*({ hrv *_t591 = &(g703); int64_t _i591 = n_134; (S4*)_t591->b + hr_ix(_i591, _t591->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:685"); }))).c_); *_t590 = ((int32_t)(q__413)); }
 }
 }
{ uint16_t *_t592 = &(((*({ hrv *_t593 = &(g703); int64_t _i593 = n_134; (S4*)_t593->b + hr_ix(_i593, _t593->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:687"); }))).fl_); *_t592 = ((uint16_t)(fl_135)); }
(void)(f88_set_end(n_134));
return n_134;
}
static int64_t f50_declname(hsl ctx_137) {
int64_t a_138 = ({ int64_t _r595; if (((f31_tk()) == (((int64_t)15LL)))) { _r595 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r595 = f34_ident(ctx_137);  } _r595; }); 
if (f41_is(((int64_t)15LL))) { g715 = a_138;
return f34_ident(ctx_137);
 }
return a_138;
}
static int64_t f51_pgenerics(void) {
if ((!(f41_is(((int64_t)39LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t l_140 = f40_mk(((int64_t)36LL), g708); 
int64_t m_141 = f52_wbeg(); 
for (;;) { int64_t g_142 = f40_mk(((int64_t)57LL), g708); 
{ int64_t q__143 = f34_ident(hr_str("generic parameter list", 22)); 
{ int32_t *_t606 = &(((*({ hrv *_t607 = &(g703); int64_t _i607 = g_142; (S4*)_t607->b + hr_ix(_i607, _t607->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:587"); }))).s_); *_t606 = ((int32_t)(q__143)); }
 }
if (f41_is(((int64_t)13LL))) { { int64_t q__402 = f53_ptype(); 
{ int32_t *_t610 = &(((*({ hrv *_t611 = &(g703); int64_t _i611 = g_142; (S4*)_t611->b + hr_ix(_i611, _t611->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:588"); }))).a_); *_t610 = ((int32_t)(q__402)); }
 }
 }
(void)(({ hrv *_v612 = &(g705); int32_t _x612 = ((int32_t)(g_142)); int32_t *_p612 = (int32_t*)hr_grow(_v612, 1, sizeof _x612); *_p612 = _x612; _p612; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk603; }
 }
if ((((f31_tk()) == (((int64_t)40LL))) || ((f31_tk()) == (((int64_t)44LL))))) { { goto _bk603; }
 }
 } _bk603:; 
(void)(f58_close_angle(hr_str("generic parameter list", 22)));
(void)(f59_setl(l_140, m_141));
return l_140;
}
static int64_t f52_wbeg(void) {
return (g705).n;
}
static int64_t f53_ptype(void) {
bool cq_144 = f41_is(((int64_t)69LL)); 
int64_t t_175 = f54_ptype_prim(); 
bool q_176 = cq_144; 
for (;;) { int64_t st_177 = g708; 
if (f41_is(((int64_t)7LL))) { if (f41_is(((int64_t)13LL))) { (void)(f39_ex(((int64_t)8LL), hr_str("slice type", 10)));
int64_t n_178 = f40_mk(((int64_t)43LL), st_177); 
{ int32_t *_t625 = &(((*({ hrv *_t626 = &(g703); int64_t _i626 = n_178; (S4*)_t626->b + hr_ix(_i626, _t626->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:84"); }))).a_); *_t625 = ((int32_t)(t_175)); }
if (q_176) { { uint16_t *_t627 = &(((*({ hrv *_t628 = &(g703); int64_t _i628 = n_178; (S4*)_t628->b + hr_ix(_i628, _t628->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:84"); }))).fl_); *_t627 = ((uint16_t)1LL); }
q_176 = false;
 }
t_175 = n_178;
continue;
 }
int64_t n_179 = f40_mk(((int64_t)42LL), st_177); 
{ int32_t *_t630 = &(((*({ hrv *_t631 = &(g703); int64_t _i631 = n_179; (S4*)_t631->b + hr_ix(_i631, _t631->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:85"); }))).a_); *_t630 = ((int32_t)(t_175)); }
if (f41_is(((int64_t)8LL))) { { uint8_t *_t633 = &(((*({ hrv *_t634 = &(g703); int64_t _i634 = n_179; (S4*)_t634->b + hr_ix(_i634, _t634->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:86"); }))).op_); *_t633 = ((uint8_t)(((uint8_t)2LL))); }
t_175 = n_179;
continue;
 }
if (f41_is(((int64_t)17LL))) { { uint8_t *_t636 = &(((*({ hrv *_t637 = &(g703); int64_t _i637 = n_179; (S4*)_t637->b + hr_ix(_i637, _t637->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:87"); }))).op_); *_t636 = ((uint8_t)(((uint8_t)3LL))); }
if (((f31_tk()) != (((int64_t)8LL)))) { { int64_t q__391 = f61_pexpr(); 
{ int32_t *_t640 = &(((*({ hrv *_t641 = &(g703); int64_t _i641 = n_179; (S4*)_t641->b + hr_ix(_i641, _t641->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:87"); }))).b_); *_t640 = ((int32_t)(q__391)); }
 }
 }
 } else { if (f41_is(((int64_t)40LL))) { (void)(f39_ex(((int64_t)17LL), hr_str("resizable array type", 20)));
{ uint8_t *_t644 = &(((*({ hrv *_t645 = &(g703); int64_t _i645 = n_179; (S4*)_t645->b + hr_ix(_i645, _t645->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:88"); }))).op_); *_t644 = ({ uint8_t _r646; if (f41_is(((int64_t)39LL))) { _r646 = ((uint8_t)(((uint8_t)5LL)));  } else { _r646 = ((uint8_t)(((uint8_t)4LL)));  } _r646; }); }
 } else { if (f55_prim_tok(f31_tk())) { { uint8_t *_t650 = &(((*({ hrv *_t651 = &(g703); int64_t _i651 = n_179; (S4*)_t651->b + hr_ix(_i651, _t651->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:89"); }))).op_); *_t650 = ((uint8_t)(((uint8_t)2LL))); }
{ int64_t q__393 = f93_lenstore(); 
{ int32_t *_t653 = &(((*({ hrv *_t654 = &(g703); int64_t _i654 = n_179; (S4*)_t654->b + hr_ix(_i654, _t654->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:89"); }))).c_); *_t653 = ((int32_t)(q__393)); }
 }
 } else { { uint8_t *_t655 = &(((*({ hrv *_t656 = &(g703); int64_t _i656 = n_179; (S4*)_t656->b + hr_ix(_i656, _t656->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:90"); }))).op_); *_t655 = ((uint8_t)(((uint8_t)1LL))); }
{ int64_t q__394 = f61_pexpr(); 
{ int32_t *_t658 = &(((*({ hrv *_t659 = &(g703); int64_t _i659 = n_179; (S4*)_t659->b + hr_ix(_i659, _t659->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:90"); }))).b_); *_t658 = ((int32_t)(q__394)); }
 }
 }
 }
 }
(void)(f39_ex(((int64_t)8LL), hr_str("array type", 10)));
t_175 = n_179;
continue;
 }
if (f41_is(((int64_t)49LL))) { int64_t n_395 = f40_mk(((int64_t)44LL), st_177); 
{ int32_t *_t663 = &(((*({ hrv *_t664 = &(g703); int64_t _i664 = n_395; (S4*)_t664->b + hr_ix(_i664, _t664->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:95"); }))).a_); *_t663 = ((int32_t)(t_175)); }
if (q_176) { { uint16_t *_t665 = &(((*({ hrv *_t666 = &(g703); int64_t _i666 = n_395; (S4*)_t666->b + hr_ix(_i666, _t666->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:95"); }))).fl_); *_t665 = ((uint16_t)1LL); }
q_176 = false;
 }
if (f41_is(((int64_t)39LL))) { { int64_t q__396 = f93_lenstore(); 
{ int32_t *_t669 = &(((*({ hrv *_t670 = &(g703); int64_t _i670 = n_395; (S4*)_t670->b + hr_ix(_i670, _t670->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:96"); }))).c_); *_t669 = ((int32_t)(q__396)); }
 }
if (f41_is(((int64_t)76LL))) { { int64_t q__397 = f56_qname(hr_str("relative reference pool", 23)); 
{ int32_t *_t673 = &(((*({ hrv *_t674 = &(g703); int64_t _i674 = n_395; (S4*)_t674->b + hr_ix(_i674, _t674->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:96"); }))).s_); *_t673 = ((int32_t)(q__397)); }
 }
 }
(void)(f58_close_angle(hr_str("relative reference width", 24)));
 }
t_175 = n_395;
continue;
 }
if (f41_is(((int64_t)14LL))) { if (((((*({ hrv *_t677 = &(g703); int64_t _i677 = t_175; (S4*)_t677->b + hr_ix(_i677, _t677->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).k_) == (((uint8_t)44LL)))) { { uint16_t *_t678 = &(((*({ hrv *_t679 = &(g703); int64_t _i679 = t_175; (S4*)_t679->b + hr_ix(_i679, _t679->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).fl_); *_t678 = ((uint16_t)((uint64_t)(*_t678) | (uint64_t)((uint16_t)2LL))); }
 } else { int64_t n_398 = f40_mk(((int64_t)44LL), st_177); 
{ int32_t *_t681 = &(((*({ hrv *_t682 = &(g703); int64_t _i682 = n_398; (S4*)_t682->b + hr_ix(_i682, _t682->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).a_); *_t681 = ((int32_t)(t_175)); }
{ uint16_t *_t683 = &(((*({ hrv *_t684 = &(g703); int64_t _i684 = n_398; (S4*)_t684->b + hr_ix(_i684, _t684->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).fl_); *_t683 = ((uint16_t)2LL); }
if (q_176) { { uint16_t *_t685 = &(((*({ hrv *_t686 = &(g703); int64_t _i686 = n_398; (S4*)_t686->b + hr_ix(_i686, _t686->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).fl_); *_t685 = ((uint16_t)((uint64_t)(*_t685) | (uint64_t)((uint16_t)1LL))); }
q_176 = false;
 }
t_175 = n_398;
 }
continue;
 }
if (((f31_tk()) == (((int64_t)17LL)))) { (void)(f33_nx());
if (((((*({ hrv *_t689 = &(g703); int64_t _i689 = t_175; (S4*)_t689->b + hr_ix(_i689, _t689->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:103"); }))).k_) == (((uint8_t)41LL)))) { { uint16_t *_t690 = &(((*({ hrv *_t691 = &(g703); int64_t _i691 = t_175; (S4*)_t691->b + hr_ix(_i691, _t691->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:103"); }))).fl_); *_t690 = ((uint16_t)((uint64_t)(*_t690) | (uint64_t)((uint16_t)1LL))); }
 } else { (void)(f38_perr(hr_str("variable mode (..) applies only to ADT type names", 49)));
 }
continue;
 }
if (f41_is(((int64_t)16LL))) { int64_t n_399 = f40_mk(((int64_t)46LL), st_177); 
{ int32_t *_t695 = &(((*({ hrv *_t696 = &(g703); int64_t _i696 = n_399; (S4*)_t696->b + hr_ix(_i696, _t696->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:104"); }))).a_); *_t695 = ((int32_t)(t_175)); }
{ int64_t q__400 = f34_ident(hr_str("variant type", 12)); 
{ int32_t *_t698 = &(((*({ hrv *_t699 = &(g703); int64_t _i699 = n_399; (S4*)_t699->b + hr_ix(_i699, _t699->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:104"); }))).s_); *_t698 = ((int32_t)(q__400)); }
 }
t_175 = n_399;
continue;
 }
if (q_176) { int64_t n_401 = f40_mk(((int64_t)48LL), st_177); 
{ int32_t *_t701 = &(((*({ hrv *_t702 = &(g703); int64_t _i702 = n_401; (S4*)_t702->b + hr_ix(_i702, _t702->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:105"); }))).a_); *_t701 = ((int32_t)(t_175)); }
t_175 = n_401;
 }
return t_175;
 } _bk620:; 
}
static int64_t f54_ptype_prim(void) {
int64_t st_145 = g708; 
int64_t k_146 = f31_tk(); 
if (f55_prim_tok(k_146)) { (void)(f33_nx());
bool up_148 = f43_at_word(g725); 
if (((((((((k_146) >= (((int64_t)91LL))) && ((k_146) <= (((int64_t)98LL)))) || ((k_146) == (((int64_t)103LL)))) || ((k_146) == (((int64_t)102LL)))) || ((k_146) == (((int64_t)101LL)))) && (!(g755))) && (((f31_tk()) == (((int64_t)76LL))) || up_148))) { (void)(f33_nx());
int64_t n_149 = f40_mk(((int64_t)47LL), st_145); 
{ uint8_t *_t710 = &(((*({ hrv *_t711 = &(g703); int64_t _i711 = n_149; (S4*)_t711->b + hr_ix(_i711, _t711->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:116"); }))).op_); *_t710 = ((uint8_t)(k_146)); }
{ uint16_t *_t712 = &(((*({ hrv *_t713 = &(g703); int64_t _i713 = n_149; (S4*)_t713->b + hr_ix(_i713, _t713->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:116"); }))).fl_); *_t712 = ({ uint16_t _r714; if (up_148) { _r714 = ((uint16_t)1LL);  } else { _r714 = ((uint16_t)0LL);  } _r714; }); }
{ int64_t q__155 = f56_qname(hr_str("index type", 10)); 
{ int32_t *_t716 = &(((*({ hrv *_t717 = &(g703); int64_t _i717 = n_149; (S4*)_t717->b + hr_ix(_i717, _t717->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:116"); }))).s_); *_t716 = ((int32_t)(q__155)); }
 }
return n_149;
 }
int64_t n_156 = f40_mk(((int64_t)40LL), st_145); 
{ uint8_t *_t719 = &(((*({ hrv *_t720 = &(g703); int64_t _i720 = n_156; (S4*)_t720->b + hr_ix(_i720, _t720->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:118"); }))).op_); *_t719 = ((uint8_t)(k_146)); }
return n_156;
 }
if ((((k_146) == (((int64_t)1LL))) || ((k_146) == (((int64_t)15LL))))) { int64_t n_157 = f40_mk(((int64_t)41LL), st_145); 
{ int64_t q__158 = f56_qname(hr_str("type", 4)); 
{ int32_t *_t723 = &(((*({ hrv *_t724 = &(g703); int64_t _i724 = n_157; (S4*)_t724->b + hr_ix(_i724, _t724->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:121"); }))).s_); *_t723 = ((int32_t)(q__158)); }
 }
if (f41_is(((int64_t)39LL))) { int64_t m_159 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v728 = &(g705); int32_t _x728 = ((int32_t)(f53_ptype())); int32_t *_p728 = (int32_t*)hr_grow(_v728, 1, sizeof _x728); *_p728 = _x728; _p728; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk727; }
 }
if ((((f31_tk()) == (((int64_t)40LL))) || ((f31_tk()) == (((int64_t)44LL))))) { { goto _bk727; }
 }
 } _bk727:; 
(void)(f58_close_angle(hr_str("type argument list", 18)));
(void)(f59_setl(n_157, m_159));
 }
return n_157;
 }
if (f41_is(((int64_t)61LL))) { int64_t n_168 = f40_mk(((int64_t)45LL), st_145); 
if (f41_is(((int64_t)5LL))) { { uint16_t *_t738 = &(((*({ hrv *_t739 = &(g703); int64_t _i739 = n_168; (S4*)_t739->b + hr_ix(_i739, _t739->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:128"); }))).fl_); *_t738 = ((uint16_t)1LL); }
int64_t m_169 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v744 = &(g705); int32_t _x744 = ((int32_t)(f53_ptype())); int32_t *_p744 = (int32_t*)hr_grow(_v744, 1, sizeof _x744); *_p744 = _x744; _p744; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk741; }
 }
 } _bk741:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function type", 13)));
(void)(f59_setl(n_168, m_169));
if (f41_is(((int64_t)54LL))) { int64_t r_170 = f40_mk(((int64_t)36LL), g708); 
int64_t m2_171 = f52_wbeg(); 
if (f41_is(((int64_t)5LL))) { while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v756 = &(g705); int32_t _x756 = ((int32_t)(f53_ptype())); int32_t *_p756 = (int32_t*)hr_grow(_v756, 1, sizeof _x756); *_p756 = _x756; _p756; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk753; }
 }
 } _bk753:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function type return list", 25)));
 } else { (void)(({ hrv *_v760 = &(g705); int32_t _x760 = ((int32_t)(f53_ptype())); int32_t *_p760 = (int32_t*)hr_grow(_v760, 1, sizeof _x760); *_p760 = _x760; _p760; }));
 }
(void)(f59_setl(r_170, m2_171));
{ int32_t *_t763 = &(((*({ hrv *_t764 = &(g703); int64_t _i764 = n_168; (S4*)_t764->b + hr_ix(_i764, _t764->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:133"); }))).b_); *_t763 = ((int32_t)(r_170)); }
 }
 }
return n_168;
 }
if (f41_is(((int64_t)5LL))) { bool fb_172 = g755; 
g755 = false;
int64_t t_173 = f53_ptype(); 
g755 = fb_172;
(void)(f39_ex(((int64_t)6LL), hr_str("parenthesized type", 18)));
return t_173;
 }
hrv m_174 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o769 = &(m_174); hr_fs(_o769, hr_str("type expected, found '", 22)); hr_fs(_o769, f35_cur_text()); hr_fs(_o769, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_174)));
return f40_mk(((int64_t)40LL), st_145);
}
static bool f55_prim_tok(int64_t k_147) {
return (((k_147) >= (((int64_t)89LL))) && ((k_147) <= (((int64_t)104LL))));
}
static int64_t f56_qname(hsl ctx_150) {
if (f41_is(((int64_t)15LL))) { return f57_qcat(((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), f34_ident(ctx_150));
 }
int64_t a_154 = f34_ident(ctx_150); 
if ((!(f41_is(((int64_t)15LL))))) { return a_154;
 }
return f57_qcat(a_154, f34_ident(ctx_150));
}
static int64_t f57_qcat(int64_t a_151, int64_t b_152) {
hrv s_153 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if (((a_151) >= (((int64_t)0LL)))) { (void)(({ hrv *_v781 = &(s_153); hsl _s781 = f10_nm(a_151); hr_append(_v781, _s781.p, _s781.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v783 = &(s_153); hsl _s783 = hr_str("::", 2); hr_append(_v783, _s783.p, _s783.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v784 = &(s_153); hsl _s784 = f10_nm(b_152); hr_append(_v784, _s784.p, _s784.n, sizeof(uint8_t)); }));
return f8_intern(hr_sl(s_153));
}
static void f58_close_angle(hsl ctx_160) {
if (((f31_tk()) == (((int64_t)44LL)))) { (void)(({ hrv *_v788 = &(g717); int64_t _x788 = g708; int64_t *_p788 = (int64_t*)hr_grow(_v788, 1, sizeof _x788); *_p788 = _x788; _p788; }));
{ uint8_t *_t789 = &(((*({ hrv *_t790 = &(g913); int64_t _i790 = g708; (S3*)_t790->b + hr_ix(_i790, _t790->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:52"); }))).k_); *_t789 = ((uint8_t)(((uint8_t)40LL))); }
return;
 }
(void)(f39_ex(((int64_t)40LL), ctx_160));
}
static void f59_setl(int64_t n_161, int64_t m_162) {
int64_t c_163 = ((int64_t)((int64_t)(g705).n - (int64_t)m_162)); 
{ int64_t q__167 = f60_wend(m_162); 
{ int32_t *_t793 = &(((*({ hrv *_t794 = &(g703); int64_t _i794 = n_161; (S4*)_t794->b + hr_ix(_i794, _t794->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:55"); }))).l_); *_t793 = ((int32_t)(q__167)); }
 }
{ int32_t *_t795 = &(((*({ hrv *_t796 = &(g703); int64_t _i796 = n_161; (S4*)_t796->b + hr_ix(_i796, _t796->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:55"); }))).n_); *_t795 = ((int32_t)(c_163)); }
}
static int64_t f60_wend(int64_t m_164) {
int64_t l_165 = (g704).n; 
{ int64_t _e798 = (g705).n; for (int64_t _k798 = m_164; _k798 < _e798; _k798++) { int64_t i_166 = (int64_t)_k798; (void)(({ hrv *_v799 = &(g704); int32_t _x799 = (*({ hrv *_t800 = &(g705); int64_t _i800 = i_166; (int32_t*)_t800->b + hr_ix(_i800, _t800->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:54"); })); int32_t *_p799 = (int32_t*)hr_grow(_v799, 1, sizeof _x799); *_p799 = _x799; _p799; }));
 } } _bk797:; 
(void)(({ hrv *_v801 = &(g705); int64_t _k801 = ((int64_t)((int64_t)(g705).n - (int64_t)m_164)); if (_k801 < 0 || _k801 > _v801->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:54"); _v801->n -= _k801; }));
return l_165;
}
static int64_t f61_pexpr(void) {
int64_t st_180 = g708; 
int64_t k_181 = f31_tk(); 
if (((k_181) == (((int64_t)72LL)))) { int64_t e_270 = f62_pif(); 
if (g713) { g714 = true;
 }
return e_270;
 }
if (((k_181) == (((int64_t)80LL)))) { int64_t e_274 = f78_pmatch(); 
if (g713) { g714 = true;
 }
return e_274;
 }
if (((k_181) == (((int64_t)78LL)))) { (void)(f33_nx());
int64_t e_275 = f40_mk(((int64_t)24LL), st_180); 
{ int64_t q__276 = f66_pblock(hr_str("block expression", 16)); 
{ int32_t *_t808 = &(((*({ hrv *_t809 = &(g703); int64_t _i809 = e_275; (S4*)_t809->b + hr_ix(_i809, _t809->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:147"); }))).a_); *_t808 = ((int32_t)(q__276)); }
 }
if (g713) { g714 = true;
 }
return e_275;
 }
if (((k_181) == (((int64_t)9LL)))) { int64_t e_277 = f66_pblock(hr_str("block", 5)); 
if (g713) { g714 = true;
 }
return e_277;
 }
if (((k_181) == (((int64_t)74LL)))) { (void)(f33_nx());
int64_t e_278 = f40_mk(((int64_t)25LL), st_180); 
{ int64_t q__279 = f63_pscrut(); 
{ int32_t *_t814 = &(((*({ hrv *_t815 = &(g703); int64_t _i815 = e_278; (S4*)_t815->b + hr_ix(_i815, _t815->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:149"); }))).a_); *_t814 = ((int32_t)(q__279)); }
 }
{ int64_t q__280 = f66_pblock(hr_str("while body", 10)); 
{ int32_t *_t817 = &(((*({ hrv *_t818 = &(g703); int64_t _i818 = e_278; (S4*)_t818->b + hr_ix(_i818, _t818->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:149"); }))).b_); *_t817 = ((int32_t)(q__280)); }
 }
if (g713) { g714 = true;
 }
return e_278;
 }
if (((k_181) == (((int64_t)77LL)))) { (void)(f33_nx());
int64_t e_281 = f40_mk(((int64_t)26LL), st_180); 
{ int64_t q__282 = f66_pblock(hr_str("loop body", 9)); 
{ int32_t *_t822 = &(((*({ hrv *_t823 = &(g703); int64_t _i823 = e_281; (S4*)_t823->b + hr_ix(_i823, _t823->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:150"); }))).a_); *_t822 = ((int32_t)(q__282)); }
 }
if (g713) { g714 = true;
 }
return e_281;
 }
if (((k_181) == (((int64_t)75LL)))) { int64_t e_294 = f79_pfor(); 
if (g713) { g714 = true;
 }
return e_294;
 }
if (((k_181) == (((int64_t)79LL)))) { (void)(f38_perr(hr_str("guard is a statement: it guards the rest of the block it is in", 62)));
return f40_mk(((int64_t)6LL), st_180);
 }
if (((k_181) == (((int64_t)81LL)))) { (void)(f33_nx());
bool sl_295 = g713; 
bool se_296 = g714; 
g713 = false;
g714 = false;
int64_t r_297 = f40_mk(((int64_t)28LL), st_180); 
if (((((f31_tk()) != (((int64_t)12LL))) && ((f31_tk()) != (((int64_t)10LL)))) && (!(f42_at_from())))) { int64_t m_298 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v834 = &(g705); int32_t _x834 = ((int32_t)(f61_pexpr())); int32_t *_p834 = (int32_t*)hr_grow(_v834, 1, sizeof _x834); *_p834 = _x834; _p834; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk833; }
 }
 } _bk833:; 
(void)(f59_setl(r_297, m_298));
 }
if (f42_at_from()) { (void)(f33_nx());
{ int64_t q__299 = f56_qname(hr_str("return from", 11)); 
{ int32_t *_t841 = &(((*({ hrv *_t842 = &(g703); int64_t _i842 = r_297; (S4*)_t842->b + hr_ix(_i842, _t842->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:158"); }))).s_); *_t841 = ((int32_t)(q__299)); }
 }
 }
g713 = sl_295;
g714 = se_296;
return r_297;
 }
if (((k_181) == (((int64_t)82LL)))) { (void)(f33_nx());
bool sl_300 = g713; 
bool se_301 = g714; 
g713 = false;
g714 = false;
int64_t r_302 = f40_mk(((int64_t)29LL), st_180); 
if ((((f31_tk()) != (((int64_t)12LL))) && ((f31_tk()) != (((int64_t)10LL))))) { { int64_t q__303 = f61_pexpr(); 
{ int32_t *_t848 = &(((*({ hrv *_t849 = &(g703); int64_t _i849 = r_302; (S4*)_t849->b + hr_ix(_i849, _t849->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:166"); }))).a_); *_t848 = ((int32_t)(q__303)); }
 }
 }
g713 = sl_300;
g714 = se_301;
return r_302;
 }
if (((k_181) == (((int64_t)83LL)))) { (void)(f33_nx());
return f40_mk(((int64_t)30LL), st_180);
 }
return f80_pbin(((int64_t)1LL));
}
static int64_t f62_pif(void) {
int64_t st_182 = g708; 
(void)(f33_nx());
int64_t n_183 = f40_mk(((int64_t)19LL), st_182); 
{ int64_t q__189 = f63_pscrut(); 
{ int32_t *_t856 = &(((*({ hrv *_t857 = &(g703); int64_t _i857 = n_183; (S4*)_t857->b + hr_ix(_i857, _t857->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:180"); }))).a_); *_t856 = ((int32_t)(q__189)); }
 }
{ int64_t q__268 = f66_pblock(hr_str("if body", 7)); 
{ int32_t *_t859 = &(((*({ hrv *_t860 = &(g703); int64_t _i860 = n_183; (S4*)_t860->b + hr_ix(_i860, _t860->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:181"); }))).b_); *_t859 = ((int32_t)(q__268)); }
 }
if (f41_is(((int64_t)73LL))) { { int64_t q__269 = ({ int64_t _r862; if (((f31_tk()) == (((int64_t)72LL)))) { _r862 = f62_pif();  } else { _r862 = f66_pblock(hr_str("else body", 9));  } _r862; }); 
{ int32_t *_t866 = &(((*({ hrv *_t867 = &(g703); int64_t _i867 = n_183; (S4*)_t867->b + hr_ix(_i867, _t867->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:182"); }))).c_); *_t866 = ((int32_t)(q__269)); }
 }
 }
return n_183;
}
static int64_t f63_pscrut(void) {
int64_t s_186 = f64_sub_begin(true); 
int64_t e_187 = f61_pexpr(); 
(void)(f65_sub_end(s_186));
return e_187;
}
static int64_t f64_sub_begin(bool nosl_184) {
int64_t s_185 = ((int64_t)((int64_t)((int64_t)((int64_t)({ int64_t _r871; if (g712) { _r871 = ((int64_t)1LL);  } else { _r871 = ((int64_t)0LL);  } _r871; }) | (int64_t)({ int64_t _r872; if (g713) { _r872 = ((int64_t)2LL);  } else { _r872 = ((int64_t)0LL);  } _r872; }))) | (int64_t)({ int64_t _r873; if (g714) { _r873 = ((int64_t)4LL);  } else { _r873 = ((int64_t)0LL);  } _r873; }))); 
g712 = nosl_184;
g713 = false;
g714 = false;
return s_185;
}
static void f65_sub_end(int64_t s_188) {
g712 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)));
g713 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)));
g714 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL)));
}
static int64_t f66_pblock(hsl ctx_190) {
int64_t st_191 = g708; 
(void)(f39_ex(((int64_t)9LL), ctx_190));
int64_t b_192 = f40_mk(((int64_t)23LL), st_191); 
(void)(f67_pbody(b_192));
return b_192;
}
static void f67_pbody(int64_t b_193) {
int64_t s_194 = f64_sub_begin(false); 
int64_t m_195 = f52_wbeg(); 
for (;;) { g713 = false;
g714 = false;
if (f41_is(((int64_t)10LL))) { { goto _bk879; }
 }
if (((f31_tk()) == (((int64_t)0LL)))) { (void)(f38_perr(hr_str("expected '}' before end of file", 31)));
{ goto _bk879; }
 }
if ((!(f68_pstmt(b_193)))) { { goto _bk879; }
 }
 } _bk879:; 
(void)(f59_setl(b_193, m_195));
(void)(f65_sub_end(s_194));
}
static bool f68_pstmt(int64_t b_196) {
int64_t k_197 = f31_tk(); 
if (((((((((f46_at_inline() || f47_at_checkfree()) || f48_at_lut()) || ((k_197) == (((int64_t)65LL)))) || ((k_197) == (((int64_t)61LL)))) || ((k_197) == (((int64_t)62LL)))) || ((k_197) == (((int64_t)68LL)))) || ((k_197) == (((int64_t)63LL)))) || ((k_197) == (((int64_t)64LL))))) { (void)(({ hrv *_v890 = &(g705); int32_t _x890 = ((int32_t)(f49_pfn(true, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p890 = (int32_t*)hr_grow(_v890, 1, sizeof _x890); *_p890 = _x890; _p890; }));
return true;
 }
if ((((((k_197) == (((int64_t)66LL))) || ((k_197) == (((int64_t)67LL)))) || ((k_197) == (((int64_t)69LL)))) || ((k_197) == (((int64_t)71LL))))) { if ((((k_197) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g708 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v893 = &(g705); int32_t _x893 = ((int32_t)(f69_pcfor(((int64_t)0LL)))); int32_t *_p893 = (int32_t*)hr_grow(_v893, 1, sizeof _x893); *_p893 = _x893; _p893; }));
return true;
 }
int64_t v_247 = f74_pvdecl(false); 
(void)(f39_ex(((int64_t)12LL), hr_str("variable declaration", 20)));
(void)(({ hrv *_v897 = &(g705); int32_t _x897 = ((int32_t)(v_247)); int32_t *_p897 = (int32_t*)hr_grow(_v897, 1, sizeof _x897); *_p897 = _x897; _p897; }));
return true;
 }
if (((k_197) == (((int64_t)79LL)))) { (void)(f76_pguard(b_196));
return false;
 }
g713 = true;
int64_t e_254 = f61_pexpr(); 
g713 = false;
int64_t st_255 = g708; 
if ((!(g714))) { int64_t o_256 = f31_tk(); 
if ((((((((((((((o_256) == (((int64_t)36LL))) || ((o_256) == (((int64_t)18LL)))) || ((o_256) == (((int64_t)26LL)))) || ((o_256) == (((int64_t)27LL)))) || ((o_256) == (((int64_t)28LL)))) || ((o_256) == (((int64_t)29LL)))) || ((o_256) == (((int64_t)30LL)))) || ((o_256) == (((int64_t)31LL)))) || ((o_256) == (((int64_t)32LL)))) || ((o_256) == (((int64_t)33LL)))) || ((o_256) == (((int64_t)45LL)))) || ((o_256) == (((int64_t)46LL))))) { (void)(f33_nx());
int64_t r_257 = f61_pexpr(); 
(void)(f39_ex(((int64_t)12LL), hr_str("assignment statement", 20)));
int64_t n_258 = f40_mk(((int64_t)34LL), st_255); 
{ uint8_t *_t905 = &(((*({ hrv *_t906 = &(g703); int64_t _i906 = n_258; (S4*)_t906->b + hr_ix(_i906, _t906->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:528"); }))).op_); *_t905 = ((uint8_t)(o_256)); }
{ int32_t *_t907 = &(((*({ hrv *_t908 = &(g703); int64_t _i908 = n_258; (S4*)_t908->b + hr_ix(_i908, _t908->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:528"); }))).a_); *_t907 = ((int32_t)(e_254)); }
{ int32_t *_t909 = &(((*({ hrv *_t910 = &(g703); int64_t _i910 = n_258; (S4*)_t910->b + hr_ix(_i910, _t910->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:528"); }))).b_); *_t909 = ((int32_t)(r_257)); }
(void)(({ hrv *_v911 = &(g705); int32_t _x911 = ((int32_t)(n_258)); int32_t *_p911 = (int32_t*)hr_grow(_v911, 1, sizeof _x911); *_p911 = _x911; _p911; }));
return true;
 }
if ((((o_256) == (((int64_t)34LL))) || ((o_256) == (((int64_t)35LL))))) { (void)(f33_nx());
(void)(f39_ex(((int64_t)12LL), hr_str("increment statement", 19)));
int64_t n_259 = f40_mk(((int64_t)35LL), st_255); 
{ uint8_t *_t915 = &(((*({ hrv *_t916 = &(g703); int64_t _i916 = n_259; (S4*)_t916->b + hr_ix(_i916, _t916->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:530"); }))).op_); *_t915 = ((uint8_t)(o_256)); }
{ int32_t *_t917 = &(((*({ hrv *_t918 = &(g703); int64_t _i918 = n_259; (S4*)_t918->b + hr_ix(_i918, _t918->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:530"); }))).a_); *_t917 = ((int32_t)(e_254)); }
(void)(({ hrv *_v919 = &(g705); int32_t _x919 = ((int32_t)(n_259)); int32_t *_p919 = (int32_t*)hr_grow(_v919, 1, sizeof _x919); *_p919 = _x919; _p919; }));
return true;
 }
if (((o_256) == (((int64_t)11LL)))) { (void)(({ hrv *_v920 = &(g705); int32_t _x920 = ((int32_t)(f77_pmulti(e_254, st_255))); int32_t *_p920 = (int32_t*)hr_grow(_v920, 1, sizeof _x920); *_p920 = _x920; _p920; }));
return true;
 }
 }
if (f41_is(((int64_t)12LL))) { (void)(({ hrv *_v923 = &(g705); int32_t _x923 = ((int32_t)(e_254)); int32_t *_p923 = (int32_t*)hr_grow(_v923, 1, sizeof _x923); *_p923 = _x923; _p923; }));
return true;
 }
if (f41_is(((int64_t)10LL))) { { int32_t *_t925 = &(((*({ hrv *_t926 = &(g703); int64_t _i926 = b_196; (S4*)_t926->b + hr_ix(_i926, _t926->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:534"); }))).a_); *_t925 = ((int32_t)(e_254)); }
return false;
 }
if (g714) { (void)(({ hrv *_v927 = &(g705); int32_t _x927 = ((int32_t)(e_254)); int32_t *_p927 = (int32_t*)hr_grow(_v927, 1, sizeof _x927); *_p927 = _x927; _p927; }));
return true;
 }
hrv m_267 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o929 = &(m_267); hr_fs(_o929, hr_str("';' expected after expression, found '", 38)); hr_fs(_o929, f35_cur_text()); hr_fs(_o929, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_267)));
return false;
}
static int64_t f69_pcfor(int64_t mode_198) {
int64_t cf_199 = f40_mk(((int64_t)37LL), g708); 
(void)(f39_ex(((int64_t)69LL), hr_str("const for", 9)));
(void)(f39_ex(((int64_t)75LL), hr_str("const for", 9)));
(void)(f39_ex(((int64_t)39LL), hr_str("const for bindings", 18)));
int64_t nb_200 = f40_mk(((int64_t)36LL), g708); 
int64_t m_201 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v939 = &(g705); int32_t _x939 = ((int32_t)(f34_ident(hr_str("const for binding", 17)))); int32_t *_p939 = (int32_t*)hr_grow(_v939, 1, sizeof _x939); *_p939 = _x939; _p939; }));
if (((!(f41_is(((int64_t)11LL)))) || ((f31_tk()) == (((int64_t)40LL))))) { { goto _bk938; }
 }
 } _bk938:; 
(void)(f59_setl(nb_200, m_201));
(void)(f58_close_angle(hr_str("const for bindings", 18)));
(void)(f39_ex(((int64_t)76LL), hr_str("const for", 9)));
{ int32_t *_t946 = &(((*({ hrv *_t947 = &(g703); int64_t _i947 = cf_199; (S4*)_t947->b + hr_ix(_i947, _t947->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:426"); }))).a_); *_t946 = ((int32_t)(nb_200)); }
int64_t src_202 = f40_mk(((int64_t)36LL), g708); 
if (f41_is(((int64_t)7LL))) { { uint8_t *_t950 = &(((*({ hrv *_t951 = &(g703); int64_t _i951 = cf_199; (S4*)_t951->b + hr_ix(_i951, _t951->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:429"); }))).op_); *_t950 = ((uint8_t)1LL); }
int64_t s_203 = f64_sub_begin(false); 
int64_t m2_204 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)8LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v957 = &(g705); int32_t _x957 = ((int32_t)(f61_pexpr())); int32_t *_p957 = (int32_t*)hr_grow(_v957, 1, sizeof _x957); *_p957 = _x957; _p957; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk954; }
 }
 } _bk954:; 
(void)(f39_ex(((int64_t)8LL), hr_str("const for constant list", 23)));
(void)(f59_setl(src_202, m2_204));
(void)(f65_sub_end(s_203));
 } else { int64_t q_205 = f34_ident(hr_str("const for source", 16)); 
{ uint8_t *_t964 = &(((*({ hrv *_t965 = &(g703); int64_t _i965 = cf_199; (S4*)_t965->b + hr_ix(_i965, _t965->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:435"); }))).op_); *_t964 = ((uint8_t)(({ uint8_t _r966; if (((q_205) == (g726))) { _r966 = ((uint8_t)2LL);  } else { _r966 = ({ uint8_t _r967; if (((q_205) == (g728))) { _r967 = ((uint8_t)3LL);  } else { _r967 = ({ uint8_t _r968; if (((q_205) == (g727))) { _r968 = ((uint8_t)4LL);  } else { _r968 = ((uint8_t)0LL);  } _r968; });  } _r967; });  } _r966; }))); }
if (((((*({ hrv *_t969 = &(g703); int64_t _i969 = cf_199; (S4*)_t969->b + hr_ix(_i969, _t969->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:436"); }))).op_) == (((uint8_t)0LL)))) { (void)(f38_perr(hr_str("const for source must be fields<T>, variants<E>, types<...>, or [constants]", 75)));
 }
(void)(f39_ex(((int64_t)39LL), hr_str("const for source", 16)));
int64_t m2_206 = f52_wbeg(); 
while (((((f31_tk()) != (((int64_t)40LL))) && ((f31_tk()) != (((int64_t)44LL)))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v977 = &(g705); int32_t _x977 = ((int32_t)(f53_ptype())); int32_t *_p977 = (int32_t*)hr_grow(_v977, 1, sizeof _x977); *_p977 = _x977; _p977; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk973; }
 }
 } _bk973:; 
(void)(f58_close_angle(hr_str("const for source", 16)));
(void)(f59_setl(src_202, m2_206));
 }
{ int32_t *_t982 = &(((*({ hrv *_t983 = &(g703); int64_t _i983 = cf_199; (S4*)_t983->b + hr_ix(_i983, _t983->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:440"); }))).b_); *_t982 = ((int32_t)(src_202)); }
{ uint16_t *_t984 = &(((*({ hrv *_t985 = &(g703); int64_t _i985 = cf_199; (S4*)_t985->b + hr_ix(_i985, _t985->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:441"); }))).fl_); *_t984 = ((uint16_t)(mode_198)); }
if (((mode_198) == (((int64_t)1LL)))) { int64_t il_207 = f40_mk(((int64_t)36LL), g708); 
(void)(f70_pinits(il_207, true));
{ int32_t *_t988 = &(((*({ hrv *_t989 = &(g703); int64_t _i989 = cf_199; (S4*)_t989->b + hr_ix(_i989, _t989->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:442"); }))).c_); *_t988 = ((int32_t)(il_207)); }
 } else { if (((mode_198) == (((int64_t)2LL)))) { (void)(f39_ex(((int64_t)9LL), hr_str("const for arms", 14)));
int64_t al_214 = f40_mk(((int64_t)36LL), g708); 
(void)(f71_parms(al_214));
(void)(f39_ex(((int64_t)10LL), hr_str("const for arms", 14)));
{ int32_t *_t994 = &(((*({ hrv *_t995 = &(g703); int64_t _i995 = cf_199; (S4*)_t995->b + hr_ix(_i995, _t995->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:443"); }))).c_); *_t994 = ((int32_t)(al_214)); }
 } else { { int64_t q__237 = f66_pblock(hr_str("const for body", 14)); 
{ int32_t *_t997 = &(((*({ hrv *_t998 = &(g703); int64_t _i998 = cf_199; (S4*)_t998->b + hr_ix(_i998, _t998->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:443"); }))).c_); *_t997 = ((int32_t)(q__237)); }
 }
 }
 }
return cf_199;
}
static void f70_pinits(int64_t n_208, bool frag_209) {
(void)(f39_ex(((int64_t)9LL), hr_str("constructor initializers", 24)));
int64_t s_210 = f64_sub_begin(false); 
int64_t m_211 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { if (f41_is(((int64_t)17LL))) { if (frag_209) { (void)(f38_perr(hr_str("trailing .. belongs to the whole constructor, not a const for fragment", 70)));
 }
{ uint16_t *_t1007 = &(((*({ hrv *_t1008 = &(g703); int64_t _i1008 = n_208; (S4*)_t1008->b + hr_ix(_i1008, _t1008->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:451"); }))).fl_); *_t1007 = ((uint16_t)((uint64_t)(*_t1007) | (uint64_t)((uint16_t)1LL))); }
{ goto _bk1002; }
 }
if ((((f31_tk()) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g708 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v1011 = &(g705); int32_t _x1011 = ((int32_t)(f69_pcfor(((int64_t)1LL)))); int32_t *_p1011 = (int32_t*)hr_grow(_v1011, 1, sizeof _x1011); *_p1011 = _x1011; _p1011; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1002; }
 }
continue;
 }
int64_t fi_212 = f40_mk(((int64_t)18LL), g708); 
if ((((f31_tk()) == (((int64_t)1LL))) && ((f44_tkat(((int64_t)((int64_t)g708 + (int64_t)((int64_t)1LL))))) == (((int64_t)13LL))))) { { int32_t *_t1017 = &(((*({ hrv *_t1018 = &(g703); int64_t _i1018 = fi_212; (S4*)_t1018->b + hr_ix(_i1018, _t1018->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:454"); }))).s_); *_t1017 = ((int32_t)(((*({ hrv *_t1019 = &(g913); int64_t _i1019 = g708; (S3*)_t1019->b + hr_ix(_i1019, _t1019->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:454"); }))).v_)); }
(void)(f33_nx());
(void)(f33_nx());
 }
{ int64_t q__213 = f61_pexpr(); 
{ int32_t *_t1023 = &(((*({ hrv *_t1024 = &(g703); int64_t _i1024 = fi_212; (S4*)_t1024->b + hr_ix(_i1024, _t1024->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:455"); }))).a_); *_t1023 = ((int32_t)(q__213)); }
 }
(void)(({ hrv *_v1025 = &(g705); int32_t _x1025 = ((int32_t)(fi_212)); int32_t *_p1025 = (int32_t*)hr_grow(_v1025, 1, sizeof _x1025); *_p1025 = _x1025; _p1025; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1002; }
 }
 } _bk1002:; 
(void)(f39_ex(((int64_t)10LL), hr_str("struct literal", 14)));
(void)(f59_setl(n_208, m_211));
(void)(f65_sub_end(s_210));
}
static void f71_parms(int64_t n_215) {
int64_t s_216 = f64_sub_begin(g712); 
int64_t m_217 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { if ((((f31_tk()) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g708 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v1037 = &(g705); int32_t _x1037 = ((int32_t)(f69_pcfor(((int64_t)2LL)))); int32_t *_p1037 = (int32_t*)hr_grow(_v1037, 1, sizeof _x1037); *_p1037 = _x1037; _p1037; }));
 } else { int64_t a_235 = f72_ppattern(); 
(void)(f39_ex(((int64_t)55LL), hr_str("match arm", 9)));
{ int64_t q__236 = f61_pexpr(); 
{ int32_t *_t1042 = &(((*({ hrv *_t1043 = &(g703); int64_t _i1043 = a_235; (S4*)_t1043->b + hr_ix(_i1043, _t1043->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:218"); }))).b_); *_t1042 = ((int32_t)(q__236)); }
 }
(void)(({ hrv *_v1044 = &(g705); int32_t _x1044 = ((int32_t)(a_235)); int32_t *_p1044 = (int32_t*)hr_grow(_v1044, 1, sizeof _x1044); *_p1044 = _x1044; _p1044; }));
 }
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1032; }
 }
 } _bk1032:; 
(void)(f59_setl(n_215, m_217));
(void)(f65_sub_end(s_216));
}
static int64_t f72_ppattern(void) {
int64_t a_218 = f40_mk(((int64_t)21LL), g708); 
if (f43_at_word(g724)) { (void)(f33_nx());
{ uint16_t *_t1051 = &(((*({ hrv *_t1052 = &(g703); int64_t _i1052 = a_218; (S4*)_t1052->b + hr_ix(_i1052, _t1052->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:226"); }))).fl_); *_t1051 = ((uint16_t)1LL); }
if (((f31_tk()) == (((int64_t)11LL)))) { (void)(f38_perr(hr_str("_ cannot be listed with other patterns", 38)));
 }
return a_218;
 }
int64_t m_219 = f52_wbeg(); 
for (;;) { int64_t it_220 = f40_mk(((int64_t)22LL), g708); 
{ int64_t q__229 = f73_pbound(); 
{ int32_t *_t1059 = &(((*({ hrv *_t1060 = &(g703); int64_t _i1060 = it_220; (S4*)_t1060->b + hr_ix(_i1060, _t1060->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:230"); }))).a_); *_t1059 = ((int32_t)(q__229)); }
 }
if (f41_is(((int64_t)17LL))) { { int64_t q__230 = f73_pbound(); 
{ int32_t *_t1063 = &(((*({ hrv *_t1064 = &(g703); int64_t _i1064 = it_220; (S4*)_t1064->b + hr_ix(_i1064, _t1064->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:231"); }))).b_); *_t1063 = ((int32_t)(q__230)); }
 }
 }
(void)(({ hrv *_v1065 = &(g705); int32_t _x1065 = ((int32_t)(it_220)); int32_t *_p1065 = (int32_t*)hr_grow(_v1065, 1, sizeof _x1065); *_p1065 = _x1065; _p1065; }));
int64_t lo_231 = ((int64_t)(((*({ hrv *_t1066 = &(g703); int64_t _i1066 = it_220; (S4*)_t1066->b + hr_ix(_i1066, _t1066->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:233"); }))).a_)); 
if (((((((*({ hrv *_t1067 = &(g703); int64_t _i1067 = lo_231; (S4*)_t1067->b + hr_ix(_i1067, _t1067->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:234"); }))).k_) == (((uint8_t)8LL))) && ((((*({ hrv *_t1068 = &(g703); int64_t _i1068 = it_220; (S4*)_t1068->b + hr_ix(_i1068, _t1068->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:234"); }))).b_) < (((int32_t)0LL)))) && (((f31_tk()) == (((int64_t)49LL))) || ((f31_tk()) == (((int64_t)1LL)))))) { bool hasq_232 = false; 
{ hsl _v1072 = f10_nm(((int64_t)(((*({ hrv *_t1074 = &(g703); int64_t _i1074 = lo_231; (S4*)_t1074->b + hr_ix(_i1074, _t1074->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:235"); }))).s_))); for (int64_t _k1072 = 0; _k1072 < _v1072.n; _k1072++) { uint8_t c_233 = ((uint8_t*)_v1072.p)[_k1072]; if (((c_233) == (((uint8_t)58LL)))) { hasq_232 = true;
 }
 } } _bk1071:; 
if ((!(hasq_232))) { if (((((int64_t)((int64_t)(g705).n - (int64_t)m_219))) > (((int64_t)1LL)))) { (void)(f38_perr(hr_str("a list of patterns binds no payload: give the variant an arm of its own", 71)));
 }
if (f41_is(((int64_t)49LL))) { { uint16_t *_t1077 = &(((*({ hrv *_t1078 = &(g703); int64_t _i1078 = a_218; (S4*)_t1078->b + hr_ix(_i1078, _t1078->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:238"); }))).fl_); *_t1077 = ((uint16_t)((uint64_t)(*_t1077) | (uint64_t)((uint16_t)2LL))); }
 }
{ int64_t q__234 = f34_ident(hr_str("match binding", 13)); 
{ int32_t *_t1080 = &(((*({ hrv *_t1081 = &(g703); int64_t _i1081 = a_218; (S4*)_t1081->b + hr_ix(_i1081, _t1081->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:239"); }))).s_); *_t1080 = ((int32_t)(q__234)); }
 }
if (((f31_tk()) == (((int64_t)11LL)))) { (void)(f38_perr(hr_str("a list of patterns binds no payload: give the variant an arm of its own", 71)));
 }
(void)(f59_setl(a_218, m_219));
return a_218;
 }
 }
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1056; }
 }
if (f43_at_word(g724)) { (void)(f38_perr(hr_str("_ cannot be listed with other patterns", 38)));
 }
 } _bk1056:; 
(void)(f59_setl(a_218, m_219));
return a_218;
}
static int64_t f73_pbound(void) {
int64_t st_221 = g708; 
bool neg_222 = f41_is(((int64_t)22LL)); 
if ((((f31_tk()) == (((int64_t)1LL))) || ((f31_tk()) == (((int64_t)15LL))))) { int64_t n_223 = f40_mk(((int64_t)8LL), g708); 
{ int64_t q__224 = f56_qname(hr_str("match pattern", 13)); 
{ int32_t *_t1094 = &(((*({ hrv *_t1095 = &(g703); int64_t _i1095 = n_223; (S4*)_t1095->b + hr_ix(_i1095, _t1095->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:254"); }))).s_); *_t1094 = ((int32_t)(q__224)); }
 }
if (neg_222) { int64_t u_225 = f40_mk(((int64_t)10LL), st_221); 
{ uint8_t *_t1097 = &(((*({ hrv *_t1098 = &(g703); int64_t _i1098 = u_225; (S4*)_t1098->b + hr_ix(_i1098, _t1098->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:254"); }))).op_); *_t1097 = ((uint8_t)(((uint8_t)22LL))); }
{ int32_t *_t1099 = &(((*({ hrv *_t1100 = &(g703); int64_t _i1100 = u_225; (S4*)_t1100->b + hr_ix(_i1100, _t1100->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:254"); }))).a_); *_t1099 = ((int32_t)(n_223)); }
return u_225;
 }
return n_223;
 }
if (((f31_tk()) != (((int64_t)2LL)))) { hrv m_226 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1103 = &(m_226); hr_fs(_o1103, hr_str("integer constant expected in match pattern, found '", 51)); hr_fs(_o1103, f35_cur_text()); hr_fs(_o1103, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_226)));
return f40_mk(((int64_t)1LL), st_221);
 }
int64_t n_227 = f40_mk(((int64_t)1LL), g708); 
(void)(f33_nx());
if (neg_222) { int64_t u_228 = f40_mk(((int64_t)10LL), st_221); 
{ uint8_t *_t1110 = &(((*({ hrv *_t1111 = &(g703); int64_t _i1111 = u_228; (S4*)_t1111->b + hr_ix(_i1111, _t1111->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:257"); }))).op_); *_t1110 = ((uint8_t)(((uint8_t)22LL))); }
{ int32_t *_t1112 = &(((*({ hrv *_t1113 = &(g703); int64_t _i1113 = u_228; (S4*)_t1113->b + hr_ix(_i1113, _t1113->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:257"); }))).a_); *_t1112 = ((int32_t)(n_227)); }
return u_228;
 }
return n_227;
}
static int64_t f74_pvdecl(bool glob_238) {
int64_t st_239 = g708; 
int64_t fl_240 = ({ int64_t _r1114; if (glob_238) { _r1114 = ((int64_t)8LL);  } else { _r1114 = ((int64_t)0LL);  } _r1114; }); 
if (f41_is(((int64_t)71LL))) { { int64_t *_t1116 = &(fl_240); *_t1116 = ((int64_t)((int64_t)(*_t1116) | (int64_t)((int64_t)16LL))); }
if (f41_is(((int64_t)7LL))) { (void)(f39_ex(((int64_t)8LL), hr_str("reusable[]", 10)));
{ int64_t *_t1119 = &(fl_240); *_t1119 = ((int64_t)((int64_t)(*_t1119) | (int64_t)((int64_t)32LL))); }
 }
 }
if (f41_is(((int64_t)67LL))) { { int64_t *_t1121 = &(fl_240); *_t1121 = ((int64_t)((int64_t)(*_t1121) | (int64_t)((int64_t)1LL))); }
 } else { if (f41_is(((int64_t)66LL))) {  } else { if (f41_is(((int64_t)69LL))) { { int64_t *_t1124 = &(fl_240); *_t1124 = ((int64_t)((int64_t)(*_t1124) | (int64_t)((int64_t)2LL))); }
 } else { (void)(f38_perr(hr_str("let, var or const expected", 26)));
 }
 }
 }
int64_t v_241 = f40_mk(((int64_t)33LL), st_239); 
int64_t m_242 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v1129 = &(g705); int32_t _x1129 = ((int32_t)(({ int64_t _r1130; if (glob_238) { _r1130 = f50_declname(hr_str("global declaration", 18));  } else { _r1130 = f34_ident(hr_str("variable declaration", 20));  } _r1130; }))); int32_t *_p1129 = (int32_t*)hr_grow(_v1129, 1, sizeof _x1129); *_p1129 = _x1129; _p1129; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1128; }
 }
 } _bk1128:; 
(void)(f59_setl(v_241, m_242));
{ int32_t *_t1135 = &(((*({ hrv *_t1136 = &(g703); int64_t _i1136 = v_241; (S4*)_t1136->b + hr_ix(_i1136, _t1136->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:571"); }))).c_); *_t1135 = ((int32_t)(g715)); }
if ((f41_is(((int64_t)13LL)) || f75_amni_type())) { { int64_t q__244 = f53_ptype(); 
{ int32_t *_t1140 = &(((*({ hrv *_t1141 = &(g703); int64_t _i1141 = v_241; (S4*)_t1141->b + hr_ix(_i1141, _t1141->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:572"); }))).a_); *_t1140 = ((int32_t)(q__244)); }
 }
 }
if (f41_is(((int64_t)18LL))) { { int64_t *_t1143 = &(fl_240); *_t1143 = ((int64_t)((int64_t)(*_t1143) | (int64_t)((int64_t)4LL))); }
 }
if ((((((int64_t)((int64_t)fl_240 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL))) || f41_is(((int64_t)36LL)))) { int64_t il_245 = f40_mk(((int64_t)36LL), g708); 
int64_t m2_246 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v1148 = &(g705); int32_t _x1148 = ((int32_t)(f61_pexpr())); int32_t *_p1148 = (int32_t*)hr_grow(_v1148, 1, sizeof _x1148); *_p1148 = _x1148; _p1148; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1147; }
 }
 } _bk1147:; 
(void)(f59_setl(il_245, m2_246));
{ int32_t *_t1152 = &(((*({ hrv *_t1153 = &(g703); int64_t _i1153 = v_241; (S4*)_t1153->b + hr_ix(_i1153, _t1153->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:574"); }))).b_); *_t1152 = ((int32_t)(il_245)); }
 }
{ uint16_t *_t1154 = &(((*({ hrv *_t1155 = &(g703); int64_t _i1155 = v_241; (S4*)_t1155->b + hr_ix(_i1155, _t1155->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:575"); }))).fl_); *_t1154 = ((uint16_t)(fl_240)); }
if (glob_238) { if ((((((*({ hrv *_t1156 = &(g703); int64_t _i1156 = v_241; (S4*)_t1156->b + hr_ix(_i1156, _t1156->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:577"); }))).b_) < (((int32_t)0LL))) && ((((int64_t)((int64_t)fl_240 & (int64_t)((int64_t)1LL)))) == (((int64_t)0LL))))) { (void)(f38_perr(hr_str("let and const global declarations require an initializer", 56)));
 }
if (((((*({ hrv *_t1158 = &(g703); int64_t _i1158 = v_241; (S4*)_t1158->b + hr_ix(_i1158, _t1158->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:578"); }))).n_) != (((int32_t)1LL)))) { (void)(f38_perr(hr_str("global declarations declare a single name", 41)));
 }
 }
return v_241;
}
static bool f75_amni_type(void) {
int64_t k_243 = f31_tk(); 
return (((*({ hrv *_t1161 = &(g912); int64_t _i1161 = ((*({ hrv *_t1162 = &(g913); int64_t _i1162 = g708; (S3*)_t1162->b + hr_ix(_i1162, _t1162->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:74"); }))).f_; (S2*)_t1161->b + hr_ix(_i1161, _t1161->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:74"); }))).amni_ && (((((f55_prim_tok(k_243) || ((k_243) == (((int64_t)1LL)))) || ((k_243) == (((int64_t)15LL)))) || ((k_243) == (((int64_t)61LL)))) || ((k_243) == (((int64_t)5LL)))) || ((k_243) == (((int64_t)69LL)))));
}
static void f76_pguard(int64_t b_248) {
int64_t st_249 = g708; 
(void)(f33_nx());
int64_t c_250 = f63_pscrut(); 
int64_t eb_251 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (f41_is(((int64_t)73LL))) { eb_251 = f66_pblock(hr_str("guard else", 10));
(void)(f41_is(((int64_t)12LL)));
 } else { (void)(f39_ex(((int64_t)12LL), hr_str("guard", 5)));
 }
int64_t rest_252 = f40_mk(((int64_t)23LL), st_249); 
(void)(f67_pbody(rest_252));
int64_t i_253 = f40_mk(((int64_t)19LL), st_249); 
{ int32_t *_t1173 = &(((*({ hrv *_t1174 = &(g703); int64_t _i1174 = i_253; (S4*)_t1174->b + hr_ix(_i1174, _t1174->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).a_); *_t1173 = ((int32_t)(c_250)); }
{ int32_t *_t1175 = &(((*({ hrv *_t1176 = &(g703); int64_t _i1176 = i_253; (S4*)_t1176->b + hr_ix(_i1176, _t1176->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).b_); *_t1175 = ((int32_t)(rest_252)); }
{ int32_t *_t1177 = &(((*({ hrv *_t1178 = &(g703); int64_t _i1178 = i_253; (S4*)_t1178->b + hr_ix(_i1178, _t1178->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).c_); *_t1177 = ((int32_t)(eb_251)); }
{ uint16_t *_t1179 = &(((*({ hrv *_t1180 = &(g703); int64_t _i1180 = i_253; (S4*)_t1180->b + hr_ix(_i1180, _t1180->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).fl_); *_t1179 = ((uint16_t)1LL); }
if (((((*({ hrv *_t1181 = &(g703); int64_t _i1181 = rest_252; (S4*)_t1181->b + hr_ix(_i1181, _t1181->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:560"); }))).a_) >= (((int32_t)0LL)))) { { int32_t *_t1182 = &(((*({ hrv *_t1183 = &(g703); int64_t _i1183 = b_248; (S4*)_t1183->b + hr_ix(_i1183, _t1183->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:560"); }))).a_); *_t1182 = ((int32_t)(i_253)); }
 } else { (void)(({ hrv *_v1184 = &(g705); int32_t _x1184 = ((int32_t)(i_253)); int32_t *_p1184 = (int32_t*)hr_grow(_v1184, 1, sizeof _x1184); *_p1184 = _x1184; _p1184; }));
 }
}
static int64_t f77_pmulti(int64_t first_260, int64_t st_261) {
int64_t tl_262 = f40_mk(((int64_t)36LL), st_261); 
int64_t m_263 = f52_wbeg(); 
(void)(({ hrv *_v1187 = &(g705); int32_t _x1187 = ((int32_t)(first_260)); int32_t *_p1187 = (int32_t*)hr_grow(_v1187, 1, sizeof _x1187); *_p1187 = _x1187; _p1187; }));
while (f41_is(((int64_t)11LL))) { (void)(({ hrv *_v1190 = &(g705); int32_t _x1190 = ((int32_t)(f61_pexpr())); int32_t *_p1190 = (int32_t*)hr_grow(_v1190, 1, sizeof _x1190); *_p1190 = _x1190; _p1190; }));
 } _bk1188:; 
(void)(f59_setl(tl_262, m_263));
int64_t o_264 = f31_tk(); 
if (((((((((((((o_264) == (((int64_t)18LL))) || ((o_264) == (((int64_t)26LL)))) || ((o_264) == (((int64_t)27LL)))) || ((o_264) == (((int64_t)28LL)))) || ((o_264) == (((int64_t)29LL)))) || ((o_264) == (((int64_t)30LL)))) || ((o_264) == (((int64_t)31LL)))) || ((o_264) == (((int64_t)32LL)))) || ((o_264) == (((int64_t)33LL)))) || ((o_264) == (((int64_t)45LL)))) || ((o_264) == (((int64_t)46LL))))) { (void)(f38_perr(hr_str("several targets take a call's results with `=` alone (\302\2477.1)", 60)));
 }
if (((f31_tk()) != (((int64_t)36LL)))) { (void)(f38_perr(hr_str("several values exist only in `return a, b;` and in a call's results, so a block or branch cannot end in `a, b`: return from each branch instead (\302\2477.1)", 151)));
 }
(void)(f33_nx());
int64_t n_265 = f40_mk(((int64_t)34LL), st_261); 
{ uint8_t *_t1199 = &(((*({ hrv *_t1200 = &(g703); int64_t _i1200 = n_265; (S4*)_t1200->b + hr_ix(_i1200, _t1200->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:548"); }))).op_); *_t1199 = ((uint8_t)(((uint8_t)11LL))); }
{ int32_t *_t1201 = &(((*({ hrv *_t1202 = &(g703); int64_t _i1202 = n_265; (S4*)_t1202->b + hr_ix(_i1202, _t1202->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:548"); }))).a_); *_t1201 = ((int32_t)(tl_262)); }
{ int64_t q__266 = f61_pexpr(); 
{ int32_t *_t1204 = &(((*({ hrv *_t1205 = &(g703); int64_t _i1205 = n_265; (S4*)_t1205->b + hr_ix(_i1205, _t1205->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:548"); }))).b_); *_t1204 = ((int32_t)(q__266)); }
 }
(void)(f39_ex(((int64_t)12LL), hr_str("assignment statement", 20)));
return n_265;
}
static int64_t f78_pmatch(void) {
int64_t st_271 = g708; 
(void)(f33_nx());
int64_t n_272 = f40_mk(((int64_t)20LL), st_271); 
{ int64_t q__273 = f63_pscrut(); 
{ int32_t *_t1210 = &(((*({ hrv *_t1211 = &(g703); int64_t _i1211 = n_272; (S4*)_t1211->b + hr_ix(_i1211, _t1211->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:206"); }))).a_); *_t1210 = ((int32_t)(q__273)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("match expression", 16)));
(void)(f71_parms(n_272));
(void)(f39_ex(((int64_t)10LL), hr_str("match expression", 16)));
if ((((((*({ hrv *_t1215 = &(g703); int64_t _i1215 = n_272; (S4*)_t1215->b + hr_ix(_i1215, _t1215->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:210"); }))).n_) == (((int32_t)0LL))) && (((g709).n) == (((int64_t)0LL))))) { (void)(f38_perr(hr_str("match must have at least one arm", 32)));
 }
return n_272;
}
static int64_t f79_pfor(void) {
int64_t st_283 = g708; 
(void)(f33_nx());
int64_t n_284 = f40_mk(((int64_t)27LL), st_283); 
if (f41_is(((int64_t)49LL))) { { uint16_t *_t1220 = &(((*({ hrv *_t1221 = &(g703); int64_t _i1221 = n_284; (S4*)_t1221->b + hr_ix(_i1221, _t1221->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:188"); }))).fl_); *_t1220 = ((uint16_t)1LL); }
 }
{ int64_t q__285 = f34_ident(hr_str("for binding", 11)); 
{ int32_t *_t1223 = &(((*({ hrv *_t1224 = &(g703); int64_t _i1224 = n_284; (S4*)_t1224->b + hr_ix(_i1224, _t1224->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:189"); }))).s_); *_t1223 = ((int32_t)(q__285)); }
 }
bool fb_286 = g755; 
g755 = true;
{ int32_t *_t1225 = &(((*({ hrv *_t1226 = &(g703); int64_t _i1226 = n_284; (S4*)_t1226->b + hr_ix(_i1226, _t1226->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:191"); }))).l_); *_t1225 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
{ int32_t *_t1227 = &(((*({ hrv *_t1228 = &(g703); int64_t _i1228 = n_284; (S4*)_t1228->b + hr_ix(_i1228, _t1228->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:191"); }))).n_); *_t1227 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
if (f41_is(((int64_t)13LL))) { { int64_t q__287 = f53_ptype(); 
{ int32_t *_t1231 = &(((*({ hrv *_t1232 = &(g703); int64_t _i1232 = n_284; (S4*)_t1232->b + hr_ix(_i1232, _t1232->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:192"); }))).l_); *_t1231 = ((int32_t)(q__287)); }
 }
 }
if (f41_is(((int64_t)11LL))) { { int64_t q__288 = f34_ident(hr_str("for index binding", 17)); 
{ int32_t *_t1235 = &(((*({ hrv *_t1236 = &(g703); int64_t _i1236 = n_284; (S4*)_t1236->b + hr_ix(_i1236, _t1236->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:193"); }))).c_); *_t1235 = ((int32_t)(q__288)); }
 }
if (f41_is(((int64_t)13LL))) { { int64_t q__289 = f53_ptype(); 
{ int32_t *_t1239 = &(((*({ hrv *_t1240 = &(g703); int64_t _i1240 = n_284; (S4*)_t1240->b + hr_ix(_i1240, _t1240->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:193"); }))).n_); *_t1239 = ((int32_t)(q__289)); }
 }
 }
 }
g755 = fb_286;
(void)(f39_ex(((int64_t)76LL), hr_str("for statement", 13)));
int64_t s_290 = f64_sub_begin(true); 
{ int64_t q__291 = f61_pexpr(); 
{ int32_t *_t1244 = &(((*({ hrv *_t1245 = &(g703); int64_t _i1245 = n_284; (S4*)_t1245->b + hr_ix(_i1245, _t1245->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:197"); }))).a_); *_t1244 = ((int32_t)(q__291)); }
 }
if (f41_is(((int64_t)17LL))) { { int64_t q__292 = f61_pexpr(); 
{ int32_t *_t1248 = &(((*({ hrv *_t1249 = &(g703); int64_t _i1249 = n_284; (S4*)_t1249->b + hr_ix(_i1249, _t1249->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:198"); }))).b_); *_t1248 = ((int32_t)(q__292)); }
 }
 }
(void)(f65_sub_end(s_290));
{ int64_t q__293 = f66_pblock(hr_str("for body", 8)); 
{ int32_t *_t1252 = &(((*({ hrv *_t1253 = &(g703); int64_t _i1253 = n_284; (S4*)_t1253->b + hr_ix(_i1253, _t1253->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:200"); }))).d_); *_t1252 = ((int32_t)(q__293)); }
 }
return n_284;
}
static int64_t f80_pbin(int64_t minp_304) {
int64_t l_383 = f81_pun(); 
for (;;) { if (g714) { return l_383;
 }
int64_t pr_385 = f92_binprec(f31_tk()); 
if ((((pr_385) < (minp_304)) || ((pr_385) == (((int64_t)0LL))))) { return l_383;
 }
int64_t op_386 = f31_tk(); 
int64_t st_387 = g708; 
(void)(f33_nx());
int64_t s_388 = f64_sub_begin(g712); 
int64_t r_389 = f80_pbin(((int64_t)((int64_t)pr_385 + (int64_t)((int64_t)1LL)))); 
(void)(f65_sub_end(s_388));
int64_t n_390 = f40_mk(((int64_t)9LL), st_387); 
{ uint8_t *_t1264 = &(((*({ hrv *_t1265 = &(g703); int64_t _i1265 = n_390; (S4*)_t1265->b + hr_ix(_i1265, _t1265->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:280"); }))).op_); *_t1264 = ((uint8_t)(op_386)); }
{ int32_t *_t1266 = &(((*({ hrv *_t1267 = &(g703); int64_t _i1267 = n_390; (S4*)_t1267->b + hr_ix(_i1267, _t1267->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:280"); }))).a_); *_t1266 = ((int32_t)(l_383)); }
{ int32_t *_t1268 = &(((*({ hrv *_t1269 = &(g703); int64_t _i1269 = n_390; (S4*)_t1269->b + hr_ix(_i1269, _t1269->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:280"); }))).b_); *_t1268 = ((int32_t)(r_389)); }
l_383 = n_390;
 } _bk1255:; 
}
static int64_t f81_pun(void) {
int64_t k_305 = f31_tk(); 
if ((((((k_305) == (((int64_t)22LL))) || ((k_305) == (((int64_t)47LL)))) || ((k_305) == (((int64_t)48LL)))) || ((k_305) == (((int64_t)49LL))))) { int64_t st_306 = g708; 
(void)(f33_nx());
int64_t s_307 = f64_sub_begin(g712); 
int64_t a_308 = f81_pun(); 
(void)(f65_sub_end(s_307));
int64_t n_309 = f40_mk(((int64_t)10LL), st_306); 
{ uint8_t *_t1276 = &(((*({ hrv *_t1277 = &(g703); int64_t _i1277 = n_309; (S4*)_t1277->b + hr_ix(_i1277, _t1277->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:291"); }))).op_); *_t1276 = ((uint8_t)(k_305)); }
{ int32_t *_t1278 = &(((*({ hrv *_t1279 = &(g703); int64_t _i1279 = n_309; (S4*)_t1279->b + hr_ix(_i1279, _t1279->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:291"); }))).a_); *_t1278 = ((int32_t)(a_308)); }
return n_309;
 }
return f82_ppost();
}
static int64_t f82_ppost(void) {
int64_t e_367 = f83_pprim(); 
for (;;) { if (g714) { return e_367;
 }
int64_t st_368 = g708; 
if (f41_is(((int64_t)5LL))) { e_367 = f86_pcall(e_367, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), st_368);
continue;
 }
if (((f31_tk()) == (((int64_t)7LL)))) { e_367 = f91_pindex(e_367);
continue;
 }
if (f41_is(((int64_t)16LL))) { int64_t nmid_377 = f34_ident(hr_str("field access", 12)); 
if (((((f31_tk()) == (((int64_t)9LL))) && (!(g712))) && ((((*({ hrv *_t1290 = &(g703); int64_t _i1290 = e_367; (S4*)_t1290->b + hr_ix(_i1290, _t1290->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:305"); }))).k_) == (((uint8_t)8LL))))) { int64_t b_378 = f40_mk(((int64_t)41LL), ((int64_t)(((*({ hrv *_t1292 = &(g703); int64_t _i1292 = e_367; (S4*)_t1292->b + hr_ix(_i1292, _t1292->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:306"); }))).t_))); 
{ int32_t *_t1293 = &(((*({ hrv *_t1294 = &(g703); int64_t _i1294 = b_378; (S4*)_t1294->b + hr_ix(_i1294, _t1294->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:306"); }))).s_); *_t1293 = ((*({ hrv *_t1295 = &(g703); int64_t _i1295 = e_367; (S4*)_t1295->b + hr_ix(_i1295, _t1295->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:306"); }))).s_; }
int64_t v_379 = f40_mk(((int64_t)46LL), st_368); 
{ int32_t *_t1297 = &(((*({ hrv *_t1298 = &(g703); int64_t _i1298 = v_379; (S4*)_t1298->b + hr_ix(_i1298, _t1298->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:307"); }))).a_); *_t1297 = ((int32_t)(b_378)); }
{ int32_t *_t1299 = &(((*({ hrv *_t1300 = &(g703); int64_t _i1300 = v_379; (S4*)_t1300->b + hr_ix(_i1300, _t1300->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:307"); }))).s_); *_t1299 = ((int32_t)(nmid_377)); }
e_367 = f89_pslit(v_379, st_368);
 } else { int64_t d_380 = f40_mk(((int64_t)14LL), st_368); 
{ int32_t *_t1303 = &(((*({ hrv *_t1304 = &(g703); int64_t _i1304 = d_380; (S4*)_t1304->b + hr_ix(_i1304, _t1304->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:309"); }))).a_); *_t1303 = ((int32_t)(e_367)); }
{ int32_t *_t1305 = &(((*({ hrv *_t1306 = &(g703); int64_t _i1306 = d_380; (S4*)_t1306->b + hr_ix(_i1306, _t1306->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:309"); }))).s_); *_t1305 = ((int32_t)(nmid_377)); }
e_367 = d_380;
 }
continue;
 }
if (f41_is(((int64_t)84LL))) { int64_t n_381 = f40_mk(((int64_t)15LL), st_368); 
{ uint16_t *_t1309 = &(((*({ hrv *_t1310 = &(g703); int64_t _i1310 = n_381; (S4*)_t1310->b + hr_ix(_i1310, _t1310->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:312"); }))).fl_); *_t1309 = ({ uint16_t _r1311; if (f41_is(((int64_t)47LL))) { _r1311 = ((uint16_t)1LL);  } else { _r1311 = ((uint16_t)0LL);  } _r1311; }); }
{ int32_t *_t1313 = &(((*({ hrv *_t1314 = &(g703); int64_t _i1314 = n_381; (S4*)_t1314->b + hr_ix(_i1314, _t1314->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:312"); }))).a_); *_t1313 = ((int32_t)(e_367)); }
{ int64_t q__382 = f53_ptype(); 
{ int32_t *_t1316 = &(((*({ hrv *_t1317 = &(g703); int64_t _i1317 = n_381; (S4*)_t1317->b + hr_ix(_i1317, _t1317->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:312"); }))).b_); *_t1316 = ((int32_t)(q__382)); }
 }
e_367 = n_381;
continue;
 }
return e_367;
 } _bk1282:; 
}
static int64_t f83_pprim(void) {
int64_t st_310 = g708; 
int64_t k_311 = f31_tk(); 
if (((k_311) == (((int64_t)2LL)))) { (void)(f33_nx());
return f40_mk(((int64_t)1LL), st_310);
 }
if (((k_311) == (((int64_t)3LL)))) { (void)(f33_nx());
return f40_mk(((int64_t)2LL), st_310);
 }
if (((k_311) == (((int64_t)4LL)))) { (void)(f33_nx());
return f40_mk(((int64_t)3LL), st_310);
 }
if (((k_311) == (((int64_t)85LL)))) { (void)(f33_nx());
return f40_mk(((int64_t)4LL), st_310);
 }
if (((k_311) == (((int64_t)86LL)))) { (void)(f33_nx());
return f40_mk(((int64_t)5LL), st_310);
 }
if (((k_311) == (((int64_t)87LL)))) { (void)(f33_nx());
return f40_mk(((int64_t)6LL), st_310);
 }
if (((k_311) == (((int64_t)88LL)))) { (void)(f33_nx());
return f40_mk(((int64_t)7LL), st_310);
 }
if (((k_311) == (((int64_t)5LL)))) { (void)(f33_nx());
int64_t s_312 = f64_sub_begin(false); 
int64_t e_313 = f61_pexpr(); 
(void)(f39_ex(((int64_t)6LL), hr_str("parenthesized expression", 24)));
(void)(f65_sub_end(s_312));
return e_313;
 }
if (((k_311) == (((int64_t)7LL)))) { return f84_parray();
 }
if ((((k_311) == (((int64_t)1LL))) || ((k_311) == (((int64_t)15LL))))) { int64_t name_321 = f56_qname(hr_str("expression", 10)); 
if (((f31_tk()) == (((int64_t)39LL)))) { int64_t ta_331 = f85_try_tyargs(); 
if (((ta_331) >= (((int64_t)0LL)))) { if (f41_is(((int64_t)5LL))) { int64_t id_332 = f40_mk(((int64_t)8LL), st_310); 
{ int32_t *_t1344 = &(((*({ hrv *_t1345 = &(g703); int64_t _i1345 = id_332; (S4*)_t1345->b + hr_ix(_i1345, _t1345->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:364"); }))).s_); *_t1344 = ((int32_t)(name_321)); }
return f86_pcall(id_332, ta_331, st_310);
 }
int64_t t_352 = f40_mk(((int64_t)41LL), st_310); 
{ int32_t *_t1348 = &(((*({ hrv *_t1349 = &(g703); int64_t _i1349 = t_352; (S4*)_t1349->b + hr_ix(_i1349, _t1349->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).s_); *_t1348 = ((int32_t)(name_321)); }
{ int32_t *_t1350 = &(((*({ hrv *_t1351 = &(g703); int64_t _i1351 = t_352; (S4*)_t1351->b + hr_ix(_i1351, _t1351->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).l_); *_t1350 = ((*({ hrv *_t1352 = &(g703); int64_t _i1352 = ta_331; (S4*)_t1352->b + hr_ix(_i1352, _t1352->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).l_; }
{ int32_t *_t1353 = &(((*({ hrv *_t1354 = &(g703); int64_t _i1354 = t_352; (S4*)_t1354->b + hr_ix(_i1354, _t1354->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).n_); *_t1353 = ((*({ hrv *_t1355 = &(g703); int64_t _i1355 = ta_331; (S4*)_t1355->b + hr_ix(_i1355, _t1355->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).n_; }
if (f41_is(((int64_t)16LL))) { int64_t v_353 = f40_mk(((int64_t)46LL), st_310); 
{ int32_t *_t1358 = &(((*({ hrv *_t1359 = &(g703); int64_t _i1359 = v_353; (S4*)_t1359->b + hr_ix(_i1359, _t1359->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:366"); }))).a_); *_t1358 = ((int32_t)(t_352)); }
{ int64_t q__354 = f34_ident(hr_str("variant literal", 15)); 
{ int32_t *_t1361 = &(((*({ hrv *_t1362 = &(g703); int64_t _i1362 = v_353; (S4*)_t1362->b + hr_ix(_i1362, _t1362->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:366"); }))).s_); *_t1361 = ((int32_t)(q__354)); }
 }
return f89_pslit(v_353, st_310);
 }
return f89_pslit(t_352, st_310);
 }
 }
if ((((f31_tk()) == (((int64_t)9LL))) && (!(g712)))) { int64_t t_364 = f40_mk(((int64_t)41LL), st_310); 
{ int32_t *_t1367 = &(((*({ hrv *_t1368 = &(g703); int64_t _i1368 = t_364; (S4*)_t1368->b + hr_ix(_i1368, _t1368->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:370"); }))).s_); *_t1367 = ((int32_t)(name_321)); }
return f89_pslit(t_364, st_310);
 }
int64_t id_365 = f40_mk(((int64_t)8LL), st_310); 
{ int32_t *_t1371 = &(((*({ hrv *_t1372 = &(g703); int64_t _i1372 = id_365; (S4*)_t1372->b + hr_ix(_i1372, _t1372->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:371"); }))).s_); *_t1371 = ((int32_t)(name_321)); }
return id_365;
 }
hrv m_366 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1374 = &(m_366); hr_fs(_o1374, hr_str("expression expected, found '", 28)); hr_fs(_o1374, f35_cur_text()); hr_fs(_o1374, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_366)));
return f40_mk(((int64_t)6LL), st_310);
}
static int64_t f84_parray(void) {
int64_t st_314 = g708; 
(void)(f33_nx());
int64_t a_315 = f40_mk(((int64_t)16LL), st_314); 
int64_t s_316 = f64_sub_begin(false); 
if (f41_is(((int64_t)17LL))) { { int64_t q__317 = f61_pexpr(); 
{ int32_t *_t1383 = &(((*({ hrv *_t1384 = &(g703); int64_t _i1384 = a_315; (S4*)_t1384->b + hr_ix(_i1384, _t1384->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:406"); }))).c_); *_t1383 = ((int32_t)(q__317)); }
 }
 } else { if (((f31_tk()) != (((int64_t)8LL)))) { int64_t first_318 = f61_pexpr(); 
if (f41_is(((int64_t)12LL))) { { int32_t *_t1388 = &(((*({ hrv *_t1389 = &(g703); int64_t _i1389 = a_315; (S4*)_t1389->b + hr_ix(_i1389, _t1389->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:410"); }))).a_); *_t1388 = ((int32_t)(first_318)); }
{ int64_t q__319 = f61_pexpr(); 
{ int32_t *_t1391 = &(((*({ hrv *_t1392 = &(g703); int64_t _i1392 = a_315; (S4*)_t1392->b + hr_ix(_i1392, _t1392->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:410"); }))).b_); *_t1391 = ((int32_t)(q__319)); }
 }
 } else { int64_t m_320 = f52_wbeg(); 
(void)(({ hrv *_v1394 = &(g705); int32_t _x1394 = ((int32_t)(first_318)); int32_t *_p1394 = (int32_t*)hr_grow(_v1394, 1, sizeof _x1394); *_p1394 = _x1394; _p1394; }));
while ((f41_is(((int64_t)11LL)) && ((f31_tk()) != (((int64_t)8LL))))) { (void)(({ hrv *_v1398 = &(g705); int32_t _x1398 = ((int32_t)(f61_pexpr())); int32_t *_p1398 = (int32_t*)hr_grow(_v1398, 1, sizeof _x1398); *_p1398 = _x1398; _p1398; }));
 } _bk1395:; 
(void)(f59_setl(a_315, m_320));
 }
 }
 }
(void)(f39_ex(((int64_t)8LL), hr_str("array literal", 13)));
(void)(f65_sub_end(s_316));
return a_315;
}
static int64_t f85_try_tyargs(void) {
int64_t save_322 = g708; 
int64_t nd0_323 = (g703).n; 
int64_t ls0_324 = (g704).n; 
int64_t sp0_325 = (g717).n; 
int64_t ws0_326 = (g705).n; 
g710++;
(void)(f33_nx());
int64_t l_327 = f40_mk(((int64_t)36LL), save_322); 
int64_t m_328 = f52_wbeg(); 
bool ok_329 = false; 
for (;;) { (void)(({ hrv *_v1407 = &(g705); int32_t _x1407 = ((int32_t)(f53_ptype())); int32_t *_p1407 = (int32_t*)hr_grow(_v1407, 1, sizeof _x1407); *_p1407 = _x1407; _p1407; }));
if ((g711 || (!(f41_is(((int64_t)11LL)))))) { { goto _bk1406; }
 }
if ((((f31_tk()) == (((int64_t)40LL))) || ((f31_tk()) == (((int64_t)44LL))))) { { goto _bk1406; }
 }
 } _bk1406:; 
if ((!(g711))) { if (((f31_tk()) == (((int64_t)44LL)))) { (void)(({ hrv *_v1413 = &(g717); int64_t _x1413 = g708; int64_t *_p1413 = (int64_t*)hr_grow(_v1413, 1, sizeof _x1413); *_p1413 = _x1413; _p1413; }));
{ uint8_t *_t1414 = &(((*({ hrv *_t1415 = &(g913); int64_t _i1415 = g708; (S3*)_t1415->b + hr_ix(_i1415, _t1415->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:386"); }))).k_); *_t1414 = ((uint8_t)(((uint8_t)40LL))); }
ok_329 = true;
 } else { if (((f31_tk()) == (((int64_t)40LL)))) { (void)(f33_nx());
ok_329 = true;
 }
 }
if (ok_329) { ok_329 = false;
if ((((f31_tk()) == (((int64_t)5LL))) || (((f31_tk()) == (((int64_t)9LL))) && (!(g712))))) { ok_329 = true;
 }
if ((((((f31_tk()) == (((int64_t)16LL))) && (!(g712))) && ((f44_tkat(((int64_t)((int64_t)g708 + (int64_t)((int64_t)1LL))))) == (((int64_t)1LL)))) && ((f44_tkat(((int64_t)((int64_t)g708 + (int64_t)((int64_t)2LL))))) == (((int64_t)9LL))))) { ok_329 = true;
 }
 }
 }
g710--;
if ((ok_329 && (!(g711)))) { (void)(f59_setl(l_327, m_328));
return l_327;
 }
g711 = false;
while ((((g717).n) > (sp0_325))) { int64_t q_330 = ({ hrv *_v1425 = &(g717); if (!_v1425->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:396"); ((int64_t*)_v1425->b)[--_v1425->n]; }); 
{ uint8_t *_t1426 = &(((*({ hrv *_t1427 = &(g913); int64_t _i1427 = q_330; (S3*)_t1427->b + hr_ix(_i1427, _t1427->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:396"); }))).k_); *_t1426 = ((uint8_t)(((uint8_t)44LL))); }
 } _bk1424:; 
if ((((g705).n) > (ws0_326))) { (void)(({ hrv *_v1428 = &(g705); int64_t _k1428 = ((int64_t)((int64_t)(g705).n - (int64_t)ws0_326)); if (_k1428 < 0 || _k1428 > _v1428->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:397"); _v1428->n -= _k1428; }));
 }
(void)(({ hrv *_v1429 = &(g703); int64_t _k1429 = nd0_323; if (_k1429 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:398"); S4 _x1429 = ((S4){ 0}); int64_t _o1429 = _v1429->n; hr_resize(_v1429, _k1429, sizeof _x1429); for (int64_t _j = _o1429; _j < _k1429; _j++) ((S4*)_v1429->b)[_j] = _x1429; }));
(void)(({ hrv *_v1430 = &(g704); int64_t _k1430 = ls0_324; if (_k1430 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:398"); int32_t _x1430 = ((int32_t)0LL); int64_t _o1430 = _v1430->n; hr_resize(_v1430, _k1430, sizeof _x1430); for (int64_t _j = _o1430; _j < _k1430; _j++) ((int32_t*)_v1430->b)[_j] = _x1430; }));
g708 = save_322;
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f86_pcall(int64_t callee_333, int64_t tyargs_334, int64_t st_335) {
int64_t c_336 = f40_mk(((int64_t)11LL), st_335); 
{ int32_t *_t1432 = &(((*({ hrv *_t1433 = &(g703); int64_t _i1433 = c_336; (S4*)_t1433->b + hr_ix(_i1433, _t1433->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:317"); }))).a_); *_t1432 = ((int32_t)(callee_333)); }
{ int32_t *_t1434 = &(((*({ hrv *_t1435 = &(g703); int64_t _i1435 = c_336; (S4*)_t1435->b + hr_ix(_i1435, _t1435->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:317"); }))).c_); *_t1434 = ((int32_t)(tyargs_334)); }
int64_t s_337 = f64_sub_begin(false); 
int64_t m_338 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v1441 = &(g705); int32_t _x1441 = ((int32_t)(f61_pexpr())); int32_t *_p1441 = (int32_t*)hr_grow(_v1441, 1, sizeof _x1441); *_p1441 = _x1441; _p1441; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1438; }
 }
 } _bk1438:; 
(void)(f39_ex(((int64_t)6LL), hr_str("call arguments", 14)));
(void)(f59_setl(c_336, m_338));
(void)(f65_sub_end(s_337));
if ((((f31_tk()) == (((int64_t)9LL))) && (!(g712)))) { { int64_t q__351 = f87_pfunval(); 
{ int32_t *_t1449 = &(((*({ hrv *_t1450 = &(g703); int64_t _i1450 = c_336; (S4*)_t1450->b + hr_ix(_i1450, _t1450->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:324"); }))).b_); *_t1449 = ((int32_t)(q__351)); }
 }
if (g713) { g714 = true;
 }
 }
return c_336;
}
static int64_t f87_pfunval(void) {
int64_t st_339 = g708; 
(void)(f39_ex(((int64_t)9LL), hr_str("function value", 14)));
int64_t fv_340 = f40_mk(((int64_t)31LL), st_339); 
int64_t b_341 = f40_mk(((int64_t)23LL), st_339); 
{ int32_t *_t1454 = &(((*({ hrv *_t1455 = &(g703); int64_t _i1455 = fv_340; (S4*)_t1455->b + hr_ix(_i1455, _t1455->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:476"); }))).a_); *_t1454 = ((int32_t)(b_341)); }
if ((((f31_tk()) == (((int64_t)1LL))) || ((f31_tk()) == (((int64_t)67LL))))) { int64_t save_342 = g708; 
int64_t nd0_343 = (g703).n; 
int64_t ws0_344 = (g705).n; 
g710++;
bool ok_345 = true; 
int64_t m_346 = f52_wbeg(); 
for (;;) { bool pv_347 = f41_is(((int64_t)67LL)); 
if (((f31_tk()) != (((int64_t)1LL)))) { ok_345 = false;
{ goto _bk1459; }
 }
int64_t p_348 = f40_mk(((int64_t)32LL), g708); 
{ int32_t *_t1463 = &(((*({ hrv *_t1464 = &(g703); int64_t _i1464 = p_348; (S4*)_t1464->b + hr_ix(_i1464, _t1464->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:485"); }))).s_); *_t1463 = ((int32_t)(((*({ hrv *_t1465 = &(g913); int64_t _i1465 = g708; (S3*)_t1465->b + hr_ix(_i1465, _t1465->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:485"); }))).v_)); }
if (pv_347) { { uint16_t *_t1466 = &(((*({ hrv *_t1467 = &(g703); int64_t _i1467 = p_348; (S4*)_t1467->b + hr_ix(_i1467, _t1467->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:485"); }))).fl_); *_t1466 = ((uint16_t)1LL); }
 }
(void)(f33_nx());
if (f41_is(((int64_t)13LL))) { { int64_t q__349 = f53_ptype(); 
{ int32_t *_t1471 = &(((*({ hrv *_t1472 = &(g703); int64_t _i1472 = p_348; (S4*)_t1472->b + hr_ix(_i1472, _t1472->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:486"); }))).a_); *_t1471 = ((int32_t)(q__349)); }
 }
 }
(void)(({ hrv *_v1473 = &(g705); int32_t _x1473 = ((int32_t)(p_348)); int32_t *_p1473 = (int32_t*)hr_grow(_v1473, 1, sizeof _x1473); *_p1473 = _x1473; _p1473; }));
if ((g711 || (!(f41_is(((int64_t)11LL)))))) { { goto _bk1459; }
 }
 } _bk1459:; 
if (((g711 || (!(ok_345))) || (!(f41_is(((int64_t)55LL)))))) { ok_345 = false;
 }
g710--;
if (ok_345) { (void)(f59_setl(fv_340, m_346));
{ uint16_t *_t1477 = &(((*({ hrv *_t1478 = &(g703); int64_t _i1478 = fv_340; (S4*)_t1478->b + hr_ix(_i1478, _t1478->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:492"); }))).fl_); *_t1477 = ((uint16_t)1LL); }
 } else { g711 = false;
if ((((g705).n) > (ws0_344))) { (void)(({ hrv *_v1479 = &(g705); int64_t _k1479 = ((int64_t)((int64_t)(g705).n - (int64_t)ws0_344)); if (_k1479 < 0 || _k1479 > _v1479->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:493"); _v1479->n -= _k1479; }));
 }
(void)(({ hrv *_v1480 = &(g703); int64_t _k1480 = nd0_343; if (_k1480 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:493"); S4 _x1480 = ((S4){ 0}); int64_t _o1480 = _v1480->n; hr_resize(_v1480, _k1480, sizeof _x1480); for (int64_t _j = _o1480; _j < _k1480; _j++) ((S4*)_v1480->b)[_j] = _x1480; }));
g708 = save_342;
 }
 }
(void)(f67_pbody(b_341));
(void)(f88_set_end(fv_340));
return fv_340;
}
static void f88_set_end(int64_t n_350) {
while ((((g718).n) < ((g703).n))) { (void)(({ hrv *_v1484 = &(g718); int32_t _x1484 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1484 = (int32_t*)hr_grow(_v1484, 1, sizeof _x1484); *_p1484 = _x1484; _p1484; }));
 } _bk1483:; 
{ int32_t *_t1485 = &((*({ hrv *_t1486 = &(g718); int64_t _i1486 = n_350; (int32_t*)_t1486->b + hr_ix(_i1486, _t1486->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:28"); }))); *_t1485 = ((int32_t)((g703).n)); }
}
static int64_t f89_pslit(int64_t ty_355, int64_t st_356) {
int64_t n_357 = f40_mk(((int64_t)17LL), st_356); 
{ int32_t *_t1488 = &(((*({ hrv *_t1489 = &(g703); int64_t _i1489 = n_357; (S4*)_t1489->b + hr_ix(_i1489, _t1489->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:464"); }))).a_); *_t1488 = ((int32_t)(ty_355)); }
(void)(f70_pinits(n_357, false));
int64_t named_358 = ((int64_t)0LL); 
bool cf_359 = false; 
{ int32_t _e1492 = ((*({ hrv *_t1493 = &(g703); int64_t _i1493 = n_357; (S4*)_t1493->b + hr_ix(_i1493, _t1493->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:467"); }))).n_; for (int32_t _k1492 = 0; _k1492 < _e1492; _k1492++) { int32_t i_360 = (int32_t)_k1492; int64_t fi_363 = f90_kid(n_357, ((int64_t)(i_360))); 
if (((((*({ hrv *_t1495 = &(g703); int64_t _i1495 = fi_363; (S4*)_t1495->b + hr_ix(_i1495, _t1495->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:467"); }))).k_) == (((uint8_t)37LL)))) { cf_359 = true;
 } else { if (((((*({ hrv *_t1496 = &(g703); int64_t _i1496 = fi_363; (S4*)_t1496->b + hr_ix(_i1496, _t1496->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:467"); }))).s_) >= (((int32_t)0LL)))) { named_358++;
 }
 }
 } } _bk1491:; 
if ((((!(cf_359)) && ((named_358) > (((int64_t)0LL)))) && ((named_358) != (((int64_t)(((*({ hrv *_t1497 = &(g703); int64_t _i1497 = n_357; (S4*)_t1497->b + hr_ix(_i1497, _t1497->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:468"); }))).n_)))))) { (void)(f38_perr(hr_str("struct literal mixes named and positional initializers", 54)));
 }
return n_357;
}
static int64_t f90_kid(int64_t n_361, int64_t i_362) {
return ((int64_t)((*({ hrv *_t1499 = &(g704); int64_t _i1499 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1500 = &(g703); int64_t _i1500 = n_361; (S4*)_t1500->b + hr_ix(_i1500, _t1500->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:56"); }))).l_)) + (int64_t)i_362)); (int32_t*)_t1499->b + hr_ix(_i1499, _t1499->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:56"); }))));
}
static int64_t f91_pindex(int64_t obj_369) {
int64_t st_370 = g708; 
(void)(f33_nx());
int64_t s_371 = f64_sub_begin(false); 
int64_t lo_372 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
bool lfe_373 = false; 
bool sl_374 = ((f31_tk()) == (((int64_t)17LL))); 
if ((!(sl_374))) { lfe_373 = f41_is(((int64_t)51LL));
lo_372 = f61_pexpr();
sl_374 = ((f31_tk()) == (((int64_t)17LL)));
 }
int64_t r_375 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (sl_374) { (void)(f33_nx());
r_375 = f40_mk(((int64_t)13LL), st_370);
{ int32_t *_t1509 = &(((*({ hrv *_t1510 = &(g703); int64_t _i1510 = r_375; (S4*)_t1510->b + hr_ix(_i1510, _t1510->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:336"); }))).a_); *_t1509 = ((int32_t)(obj_369)); }
{ int32_t *_t1511 = &(((*({ hrv *_t1512 = &(g703); int64_t _i1512 = r_375; (S4*)_t1512->b + hr_ix(_i1512, _t1512->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:336"); }))).b_); *_t1511 = ((int32_t)(lo_372)); }
if (lfe_373) { { uint16_t *_t1513 = &(((*({ hrv *_t1514 = &(g703); int64_t _i1514 = r_375; (S4*)_t1514->b + hr_ix(_i1514, _t1514->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:337"); }))).fl_); *_t1513 = ((uint16_t)1LL); }
 }
if (((f31_tk()) != (((int64_t)8LL)))) { if (f41_is(((int64_t)51LL))) { { uint16_t *_t1517 = &(((*({ hrv *_t1518 = &(g703); int64_t _i1518 = r_375; (S4*)_t1518->b + hr_ix(_i1518, _t1518->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:338"); }))).fl_); *_t1517 = ((uint16_t)((uint64_t)(*_t1517) | (uint64_t)((uint16_t)2LL))); }
 }
{ int64_t q__376 = f61_pexpr(); 
{ int32_t *_t1520 = &(((*({ hrv *_t1521 = &(g703); int64_t _i1521 = r_375; (S4*)_t1521->b + hr_ix(_i1521, _t1521->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:338"); }))).c_); *_t1520 = ((int32_t)(q__376)); }
 }
 }
 } else { if (lfe_373) { (void)(f38_perr(hr_str("'^' bounds are only valid in slices", 35)));
 }
r_375 = f40_mk(((int64_t)12LL), st_370);
{ int32_t *_t1524 = &(((*({ hrv *_t1525 = &(g703); int64_t _i1525 = r_375; (S4*)_t1525->b + hr_ix(_i1525, _t1525->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:341"); }))).a_); *_t1524 = ((int32_t)(obj_369)); }
{ int32_t *_t1526 = &(((*({ hrv *_t1527 = &(g703); int64_t _i1527 = r_375; (S4*)_t1527->b + hr_ix(_i1527, _t1527->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:341"); }))).b_); *_t1526 = ((int32_t)(lo_372)); }
 }
(void)(f39_ex(((int64_t)8LL), hr_str("indexing", 8)));
(void)(f65_sub_end(s_371));
return r_375;
}
static int64_t f92_binprec(int64_t k_384) {
if (((((k_384) == (((int64_t)23LL))) || ((k_384) == (((int64_t)24LL)))) || ((k_384) == (((int64_t)25LL))))) { return ((int64_t)10LL);
 }
if ((((k_384) == (((int64_t)21LL))) || ((k_384) == (((int64_t)22LL))))) { return ((int64_t)9LL);
 }
if ((((k_384) == (((int64_t)43LL))) || ((k_384) == (((int64_t)44LL))))) { return ((int64_t)8LL);
 }
if (((k_384) == (((int64_t)49LL)))) { return ((int64_t)7LL);
 }
if (((k_384) == (((int64_t)51LL)))) { return ((int64_t)6LL);
 }
if (((k_384) == (((int64_t)50LL)))) { return ((int64_t)5LL);
 }
if ((((((k_384) == (((int64_t)39LL))) || ((k_384) == (((int64_t)40LL)))) || ((k_384) == (((int64_t)41LL)))) || ((k_384) == (((int64_t)42LL))))) { return ((int64_t)4LL);
 }
if ((((((k_384) == (((int64_t)37LL))) || ((k_384) == (((int64_t)38LL)))) || ((k_384) == (((int64_t)19LL)))) || ((k_384) == (((int64_t)20LL))))) { return ((int64_t)3LL);
 }
if (((k_384) == (((int64_t)52LL)))) { return ((int64_t)2LL);
 }
if (((k_384) == (((int64_t)53LL)))) { return ((int64_t)1LL);
 }
return ((int64_t)0LL);
}
static int64_t f93_lenstore(void) {
int64_t k_392 = f31_tk(); 
if (((((((((k_392) == (((int64_t)95LL))) || ((k_392) == (((int64_t)96LL)))) || ((k_392) == (((int64_t)97LL)))) || ((k_392) == (((int64_t)98LL)))) || ((k_392) == (((int64_t)90LL)))) || ((k_392) == (((int64_t)103LL)))) || ((k_392) == (((int64_t)102LL))))) { (void)(f33_nx());
return k_392;
 }
(void)(f38_perr(hr_str("unsigned integer storage type or varint expected", 48)));
return ((int64_t)0LL);
}
static int64_t f94_pstruct(void) {
int64_t st_414 = g708; 
(void)(f33_nx());
int64_t n_415 = f40_mk(((int64_t)51LL), st_414); 
{ int64_t q__416 = f50_declname(hr_str("struct declaration", 18)); 
{ int32_t *_t1536 = &(((*({ hrv *_t1537 = &(g703); int64_t _i1537 = n_415; (S4*)_t1537->b + hr_ix(_i1537, _t1537->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:618"); }))).s_); *_t1536 = ((int32_t)(q__416)); }
 }
{ int32_t *_t1538 = &(((*({ hrv *_t1539 = &(g703); int64_t _i1539 = n_415; (S4*)_t1539->b + hr_ix(_i1539, _t1539->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:618"); }))).a_); *_t1538 = ((int32_t)(g715)); }
{ int64_t q__417 = f51_pgenerics(); 
{ int32_t *_t1541 = &(((*({ hrv *_t1542 = &(g703); int64_t _i1542 = n_415; (S4*)_t1542->b + hr_ix(_i1542, _t1542->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:619"); }))).d_); *_t1541 = ((int32_t)(q__417)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("struct declaration", 18)));
(void)(f95_pfields(n_415, hr_str("struct body", 11)));
(void)(f39_ex(((int64_t)10LL), hr_str("struct declaration", 18)));
return n_415;
}
static void f95_pfields(int64_t n_418, hsl ctx_419) {
int64_t m_420 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t f_421 = f40_mk(((int64_t)55LL), g708); 
if (f41_is(((int64_t)70LL))) { { uint16_t *_t1552 = &(((*({ hrv *_t1553 = &(g703); int64_t _i1553 = f_421; (S4*)_t1553->b + hr_ix(_i1553, _t1553->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:601"); }))).fl_); *_t1552 = ((uint16_t)4LL); }
if (((f31_tk()) == (((int64_t)2LL)))) { { int32_t *_t1555 = &(((*({ hrv *_t1556 = &(g703); int64_t _i1556 = f_421; (S4*)_t1556->b + hr_ix(_i1556, _t1556->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:601"); }))).c_); *_t1555 = ((int32_t)(((*({ hrv *_t1557 = &(g913); int64_t _i1557 = g708; (S3*)_t1557->b + hr_ix(_i1557, _t1557->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:601"); }))).v_)); }
(void)(f33_nx());
 }
 } else { bool cq_422 = f41_is(((int64_t)69LL)); 
if ((cq_422 || f41_is(((int64_t)66LL)))) { { uint16_t *_t1561 = &(((*({ hrv *_t1562 = &(g703); int64_t _i1562 = f_421; (S4*)_t1562->b + hr_ix(_i1562, _t1562->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:604"); }))).fl_); *_t1561 = ({ uint16_t _r1563; if (cq_422) { _r1563 = ((uint16_t)3LL);  } else { _r1563 = ((uint16_t)1LL);  } _r1563; }); }
 }
{ int64_t q__423 = f34_ident(ctx_419); 
{ int32_t *_t1565 = &(((*({ hrv *_t1566 = &(g703); int64_t _i1566 = f_421; (S4*)_t1566->b + hr_ix(_i1566, _t1566->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:605"); }))).s_); *_t1565 = ((int32_t)(q__423)); }
 }
if ((!(f75_amni_type()))) { (void)(f39_ex(((int64_t)13LL), ctx_419));
 }
{ int64_t q__424 = f53_ptype(); 
{ int32_t *_t1570 = &(((*({ hrv *_t1571 = &(g703); int64_t _i1571 = f_421; (S4*)_t1571->b + hr_ix(_i1571, _t1571->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:607"); }))).a_); *_t1570 = ((int32_t)(q__424)); }
 }
if (f41_is(((int64_t)36LL))) { { int64_t q__425 = f61_pexpr(); 
{ int32_t *_t1574 = &(((*({ hrv *_t1575 = &(g703); int64_t _i1575 = f_421; (S4*)_t1575->b + hr_ix(_i1575, _t1575->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:608"); }))).b_); *_t1574 = ((int32_t)(q__425)); }
 }
 }
 }
(void)(({ hrv *_v1576 = &(g705); int32_t _x1576 = ((int32_t)(f_421)); int32_t *_p1576 = (int32_t*)hr_grow(_v1576, 1, sizeof _x1576); *_p1576 = _x1576; _p1576; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1547; }
 }
 } _bk1547:; 
(void)(f59_setl(n_418, m_420));
}
static int64_t f96_penum(void) {
int64_t st_426 = g708; 
(void)(f33_nx());
int64_t n_427 = f40_mk(((int64_t)52LL), st_426); 
{ int64_t q__428 = f50_declname(hr_str("enum declaration", 16)); 
{ int32_t *_t1582 = &(((*({ hrv *_t1583 = &(g703); int64_t _i1583 = n_427; (S4*)_t1583->b + hr_ix(_i1583, _t1583->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:628"); }))).s_); *_t1582 = ((int32_t)(q__428)); }
 }
{ int32_t *_t1584 = &(((*({ hrv *_t1585 = &(g703); int64_t _i1585 = n_427; (S4*)_t1585->b + hr_ix(_i1585, _t1585->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:628"); }))).a_); *_t1584 = ((int32_t)(g715)); }
{ int64_t q__429 = f51_pgenerics(); 
{ int32_t *_t1587 = &(((*({ hrv *_t1588 = &(g703); int64_t _i1588 = n_427; (S4*)_t1588->b + hr_ix(_i1588, _t1588->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:629"); }))).d_); *_t1587 = ((int32_t)(q__429)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("enum declaration", 16)));
int64_t m_430 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t v_431 = f40_mk(((int64_t)56LL), g708); 
{ int64_t q__432 = f34_ident(hr_str("enum variant", 12)); 
{ int32_t *_t1596 = &(((*({ hrv *_t1597 = &(g703); int64_t _i1597 = v_431; (S4*)_t1597->b + hr_ix(_i1597, _t1597->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:633"); }))).s_); *_t1596 = ((int32_t)(q__432)); }
 }
if (f41_is(((int64_t)9LL))) { { uint16_t *_t1599 = &(((*({ hrv *_t1600 = &(g703); int64_t _i1600 = v_431; (S4*)_t1600->b + hr_ix(_i1600, _t1600->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:634"); }))).fl_); *_t1599 = ((uint16_t)1LL); }
(void)(f95_pfields(v_431, hr_str("variant body", 12)));
(void)(f39_ex(((int64_t)10LL), hr_str("enum variant", 12)));
 }
(void)(({ hrv *_v1603 = &(g705); int32_t _x1603 = ((int32_t)(v_431)); int32_t *_p1603 = (int32_t*)hr_grow(_v1603, 1, sizeof _x1603); *_p1603 = _x1603; _p1603; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1591; }
 }
 } _bk1591:; 
(void)(f59_setl(n_427, m_430));
(void)(f39_ex(((int64_t)10LL), hr_str("enum declaration", 16)));
return n_427;
}
static void f97_collect(int64_t file_440, int64_t t0_441, int64_t t1_442) {
{ int64_t _e1608 = t1_442; for (int64_t _k1608 = t0_441; _k1608 < _e1608; _k1608++) { int64_t i_443 = (int64_t)_k1608; int64_t n_444 = ((int64_t)((*({ hrv *_t1609 = &(g706); int64_t _i1609 = i_443; (int32_t*)_t1609->b + hr_ix(_i1609, _t1609->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:27"); })))); 
S4 x_445 = (*({ hrv *_t1610 = &(g703); int64_t _i1610 = n_444; (S4*)_t1610->b + hr_ix(_i1610, _t1610->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:28"); })); 
int64_t k_446 = ((int64_t)((x_445).k_)); 
if (((k_446) == (((int64_t)51LL)))) { (void)(f99_dadd(((int64_t)1LL), n_444, file_440, f98_qual(((int64_t)((x_445).a_)), ((int64_t)((x_445).s_)))));
 }
if (((k_446) == (((int64_t)52LL)))) { (void)(f99_dadd(((int64_t)2LL), n_444, file_440, f98_qual(((int64_t)((x_445).a_)), ((int64_t)((x_445).s_)))));
 }
if (((k_446) == (((int64_t)53LL)))) { (void)(f99_dadd(((int64_t)3LL), n_444, file_440, f98_qual(((int64_t)((x_445).a_)), ((int64_t)((x_445).s_)))));
 }
if (((k_446) == (((int64_t)50LL)))) { if ((!((hr_streq(f10_nm(((int64_t)((x_445).s_))), hr_str("main", 4)) && ((file_440) != (((int64_t)0LL))))))) { (void)(f99_dadd(((int64_t)4LL), n_444, file_440, f98_qual(((int64_t)((x_445).a_)), ((int64_t)((x_445).s_)))));
 }
 }
if (((k_446) == (((int64_t)33LL)))) { (void)(f99_dadd(((int64_t)5LL), n_444, file_440, f98_qual(((int64_t)((x_445).c_)), ((int64_t)((*({ hrv *_t1622 = &(g704); int64_t _i1622 = (x_445).l_; (int32_t*)_t1622->b + hr_ix(_i1622, _t1622->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:34"); })))))));
 }
 } } _bk1607:; 
}
static int64_t f98_qual(int64_t ns_447, int64_t name_448) {
return ({ int64_t _r1623; if (((ns_447) < (((int64_t)0LL)))) { _r1623 = name_448;  } else { hrv s_449 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v1625 = &(s_449); hsl _s1625 = f10_nm(ns_447); hr_append(_v1625, _s1625.p, _s1625.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1627 = &(s_449); hsl _s1627 = hr_str("::", 2); hr_append(_v1627, _s1627.p, _s1627.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1628 = &(s_449); hsl _s1628 = f10_nm(name_448); hr_append(_v1628, _s1628.p, _s1628.n, sizeof(uint8_t)); }));
_r1623 = f8_intern(hr_sl(s_449));  } _r1623; });
}
static void f99_dadd(int64_t k_450, int64_t node_451, int64_t file_452, int64_t name_453) {
while ((((g489).n) <= (name_453))) { (void)(({ hrv *_v1632 = &(g489); int32_t _x1632 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1632 = (int32_t*)hr_grow(_v1632, 1, sizeof _x1632); *_p1632 = _x1632; _p1632; }));
 } _bk1631:; 
int64_t i_454 = (g488).n; 
(void)(({ hrv *_v1633 = &(g488); S5 _x1633 = ((S5){ .k_ = ((uint8_t)(k_450)), .node_ = ((int32_t)(node_451)), .file_ = ((int32_t)(file_452)), .next_ = (*({ hrv *_t1634 = &(g489); int64_t _i1634 = name_453; (int32_t*)_t1634->b + hr_ix(_i1634, _t1634->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:19"); })), .name_ = ((int32_t)(name_453)), }); S5 *_p1633 = (S5*)hr_grow(_v1633, 1, sizeof _x1633); *_p1633 = _x1633; _p1633; }));
{ int32_t *_t1635 = &((*({ hrv *_t1636 = &(g489); int64_t _i1636 = name_453; (int32_t*)_t1636->b + hr_ix(_i1636, _t1636->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:20"); }))); *_t1635 = ((int32_t)(i_454)); }
}
static L49 f100_lib_path(hsl name_459) {
L49 p_460 = ({ L49 _t1637; memset(&_t1637, 0, sizeof _t1637); _t1637.n = 0; _t1637; }); 
(void)(({ L49 *_v1638 = &(p_460); hsl _s1638 = hr_sl(g492); if (_v1638->n + _s1638.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); memmove(_v1638->e + _v1638->n, _s1638.p, (size_t)_s1638.n * sizeof _v1638->e[0]); _v1638->n += _s1638.n; }));
(void)(({ L49 *_v1639 = &(p_460); uint8_t _x1639 = ((uint8_t)47LL); if (_v1639->n >= 1024) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); _v1639->e[_v1639->n] = _x1639; &_v1639->e[_v1639->n++]; }));
(void)(({ L49 *_v1640 = &(p_460); hsl _s1640 = name_459; if (_v1640->n + _s1640.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); memmove(_v1640->e + _v1640->n, _s1640.p, (size_t)_s1640.n * sizeof _v1640->e[0]); _v1640->n += _s1640.n; }));
(void)(({ L49 *_v1641 = &(p_460); hsl _s1641 = hr_str(".amni", 5); if (_v1641->n + _s1641.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); memmove(_v1641->e + _v1641->n, _s1641.p, (size_t)_s1641.n * sizeof _v1641->e[0]); _v1641->n += _s1641.n; }));
return p_460;
}
static int64_t f101_load_import(int64_t name_463, int64_t from_464, int64_t t_465) {
L49 p_466 = ({ L49 _t1642; memset(&_t1642, 0, sizeof _t1642); _t1642.n = 0; _t1642; }); 
(void)(({ L49 *_v1643 = &(p_466); hsl _s1643 = hr_sl(g491); if (_v1643->n + _s1643.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:59"); memmove(_v1643->e + _v1643->n, _s1643.p, (size_t)_s1643.n * sizeof _v1643->e[0]); _v1643->n += _s1643.n; }));
(void)(({ L49 *_v1644 = &(p_466); uint8_t _x1644 = ((uint8_t)47LL); if (_v1644->n >= 1024) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:59"); _v1644->e[_v1644->n] = _x1644; &_v1644->e[_v1644->n++]; }));
(void)(({ L49 *_v1645 = &(p_466); hsl _s1645 = f10_nm(name_463); if (_v1645->n + _s1645.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:59"); memmove(_v1645->e + _v1645->n, _s1645.p, (size_t)_s1645.n * sizeof _v1645->e[0]); _v1645->n += _s1645.n; }));
(void)(({ L49 *_v1647 = &(p_466); hsl _s1647 = hr_str(".amni", 5); if (_v1647->n + _s1647.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:59"); memmove(_v1647->e + _v1647->n, _s1647.p, (size_t)_s1647.n * sizeof _v1647->e[0]); _v1647->n += _s1647.n; }));
int64_t r_467 = f19_try_load(({ hsl _t1649 = ({ L49 *_t1650 = &(p_466); (hsl){ (uint8_t*)_t1650->e, _t1650->n }; }); int64_t _l1649 = 0, _h1649 = _t1649.n; if (_l1649 < 0 || _h1649 < _l1649 || _h1649 > _t1649.n) hr_slerr(_l1649, _h1649, _t1649.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:60"); (hsl){ _t1649.p + _l1649 * (int64_t)sizeof(uint8_t), _h1649 - _l1649 }; })); 
if (((r_467) == (((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))) { L49 lp_468 = f100_lib_path(f10_nm(name_463)); 
r_467 = f19_try_load(({ hsl _t1654 = ({ L49 *_t1655 = &(lp_468); (hsl){ (uint8_t*)_t1655->e, _t1655->n }; }); int64_t _l1654 = 0, _h1654 = _t1654.n; if (_l1654 < 0 || _h1654 < _l1654 || _h1654 > _t1654.n) hr_slerr(_l1654, _h1654, _t1654.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:61"); (hsl){ _t1654.p + _l1654 * (int64_t)sizeof(uint8_t), _h1654 - _l1654 }; }));
 }
if (((r_467) == (((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))) { hrv m_469 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1657 = &(m_469); hr_fs(_o1657, hr_str("cannot find module ", 19)); hr_fs(_o1657, f10_nm(name_463)); }));
(void)(f102_derr(t_465, hr_sl(m_469)));
return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
return r_467;
}
static void f102_derr(int64_t t_470, hsl m_471) {
if ((((g494).n) > (((int64_t)0LL)))) { return;
 }
S3 x_474 = (*({ hrv *_t1660 = &(g913); int64_t _i1660 = f103_max(t_470, ((int64_t)0LL)); (S3*)_t1660->b + hr_ix(_i1660, _t1660->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:14"); })); 
(void)(({ hrv *_v1662 = &(g494); hsl _s1662 = f10_nm(((int64_t)(((*({ hrv *_t1664 = &(g912); int64_t _i1664 = (x_474).f_; (S2*)_t1664->b + hr_ix(_i1664, _t1664->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:14"); }))).name_))); hr_append(_v1662, _s1662.p, _s1662.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o1665 = &(g494); hr_fs(_o1665, hr_str(":", 1)); hr_fi(_o1665, (x_474).line_); hr_fs(_o1665, hr_str(": error: ", 9)); hr_fs(_o1665, m_471); }));
}
static int64_t f103_max(int64_t a_472, int64_t b_473) {
if (((a_472) < (b_473))) { return b_473;
 }
return a_472;
}
static bool f104_check_program(void) {
g402 = f105_new_inst(((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)0LL), (g703).n, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
{ uint8_t *_t1667 = &(((*({ hrv *_t1668 = &(g387); int64_t _i1668 = g402; (S6*)_t1668->b + hr_ix(_i1668, _t1668->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:495"); }))).st_); *_t1667 = ((uint8_t)2LL); }
g400 = g402;
g401 = g402;
int64_t md_489 = f106_lookup(f8_intern(hr_str("main", 4)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)4LL)); 
if (((md_489) < (((int64_t)0LL)))) { (void)(f108_cerr(((int64_t)0LL), hr_str("no main function", 16)));
return false;
 }
{ hrv *_v1673 = &(g488); for (int64_t _k1673 = 0; _k1673 < _v1673->n; _k1673++) { S5 d_493 = ((S5*)_v1673->b)[_k1673]; int64_t i_494 = (int64_t)_k1673; if ((((((int64_t)((d_493).k_))) == (((int64_t)5LL))) && (((d_493).file_) == (((int32_t)0LL))))) { (void)(f109_global_type(i_494));
 }
 } } _bk1672:; 
int64_t mi_1477 = f252_get_inst(((int64_t)(((*({ hrv *_t1676 = &(g488); int64_t _i1676 = md_489; (S5*)_t1676->b + hr_ix(_i1676, _t1676->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:500"); }))).node_)), (g313).n, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
{ hrv *_v1678 = &(g488); for (int64_t _k1678 = 0; _k1678 < _v1678->n; _k1678++) { S5 d_1478 = ((S5*)_v1678->b)[_k1678]; int64_t i_1479 = (int64_t)_k1678; if (((((int64_t)((d_1478).k_))) == (((int64_t)5LL)))) { (void)(f109_global_type(i_1479));
 }
 } } _bk1677:; 
(void)(f258_propagate_calls());
return ((g404) == (((int64_t)0LL)));
}
static int64_t f105_new_inst(int64_t node_477, int64_t lo_478, int64_t hi_479, int64_t par_480) {
int64_t i_481 = (g387).n; 
(void)(({ hrv *_v1681 = &(g387); S6 _x1681 = ((S6){ .node_ = ((int32_t)(node_477)), .lo_ = ((int32_t)(lo_478)), .hi_ = ((int32_t)(hi_479)), .ab_ = ((int32_t)((g394).n)), .par_ = ((int32_t)(par_480)), .cfn_ = ((int32_t)(i_481)), .g0_ = ((int32_t)((g393).n)), .gn_ = ((int32_t)0LL), .ret_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .p0_ = ((int32_t)0LL), .pn_ = ((int32_t)0LL), .st_ = ((uint8_t)0LL), .blk_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .bown_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .name_ = ({ int32_t _r1682; if (((node_477) >= (((int64_t)0LL)))) { _r1682 = ((*({ hrv *_t1683 = &(g703); int64_t _i1683 = node_477; (S4*)_t1683->b + hr_ix(_i1683, _t1683->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:30"); }))).s_;  } else { _r1682 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));  } _r1682; }), }); S6 *_p1681 = (S6*)hr_grow(_v1681, 1, sizeof _x1681); *_p1681 = _x1681; _p1681; }));
int64_t n_482 = ((int64_t)((int64_t)hi_479 - (int64_t)lo_478)); 
(void)(({ hrv *_v1684 = &(g394); int64_t _k1684 = ((int64_t)((int64_t)(g394).n + (int64_t)n_482)); if (_k1684 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1684 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1684 = _v1684->n; hr_resize(_v1684, _k1684, sizeof _x1684); for (int64_t _j = _o1684; _j < _k1684; _j++) ((int32_t*)_v1684->b)[_j] = _x1684; }));
(void)(({ hrv *_v1685 = &(g395); int64_t _k1685 = ((int64_t)((int64_t)(g395).n + (int64_t)n_482)); if (_k1685 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1685 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1685 = _v1685->n; hr_resize(_v1685, _k1685, sizeof _x1685); for (int64_t _j = _o1685; _j < _k1685; _j++) ((int32_t*)_v1685->b)[_j] = _x1685; }));
(void)(({ hrv *_v1686 = &(g396); int64_t _k1686 = ((int64_t)((int64_t)(g396).n + (int64_t)n_482)); if (_k1686 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); uint8_t _x1686 = ((uint8_t)0LL); int64_t _o1686 = _v1686->n; hr_resize(_v1686, _k1686, sizeof _x1686); for (int64_t _j = _o1686; _j < _k1686; _j++) ((uint8_t*)_v1686->b)[_j] = _x1686; }));
(void)(({ hrv *_v1687 = &(g397); int64_t _k1687 = ((int64_t)((int64_t)(g397).n + (int64_t)n_482)); if (_k1687 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1687 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1687 = _v1687->n; hr_resize(_v1687, _k1687, sizeof _x1687); for (int64_t _j = _o1687; _j < _k1687; _j++) ((int32_t*)_v1687->b)[_j] = _x1687; }));
(void)(({ hrv *_v1688 = &(g398); int64_t _k1688 = ((int64_t)((int64_t)(g398).n + (int64_t)n_482)); if (_k1688 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1688 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1688 = _v1688->n; hr_resize(_v1688, _k1688, sizeof _x1688); for (int64_t _j = _o1688; _j < _k1688; _j++) ((int32_t*)_v1688->b)[_j] = _x1688; }));
return i_481;
}
static int64_t f106_lookup(int64_t name_483, int64_t ns_484, int64_t k_485) {
if (((ns_484) >= (((int64_t)0LL)))) { int64_t d_487 = f107_dmap(f98_qual(ns_484, name_483)); 
while (((d_487) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1692 = &(g488); int64_t _i1692 = d_487; (S5*)_t1692->b + hr_ix(_i1692, _t1692->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:74"); }))).k_))) == (k_485))) { return d_487;
 }
d_487 = ((int64_t)(((*({ hrv *_t1693 = &(g488); int64_t _i1693 = d_487; (S5*)_t1693->b + hr_ix(_i1693, _t1693->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:74"); }))).next_));
 } _bk1691:; 
 }
int64_t d_488 = f107_dmap(name_483); 
while (((d_488) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1696 = &(g488); int64_t _i1696 = d_488; (S5*)_t1696->b + hr_ix(_i1696, _t1696->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:76"); }))).k_))) == (k_485))) { return d_488;
 }
d_488 = ((int64_t)(((*({ hrv *_t1697 = &(g488); int64_t _i1697 = d_488; (S5*)_t1697->b + hr_ix(_i1697, _t1697->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:76"); }))).next_));
 } _bk1695:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f107_dmap(int64_t name_486) {
return ({ int64_t _r1698; if ((((name_486) < (((int64_t)0LL))) || ((name_486) >= ((g489).n)))) { _r1698 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1698 = ((int64_t)((*({ hrv *_t1699 = &(g489); int64_t _i1699 = name_486; (int32_t*)_t1699->b + hr_ix(_i1699, _t1699->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:15"); }))));  } _r1698; });
}
static void f108_cerr(int64_t n_490, hsl m_491) {
g404++;
if ((((g403).n) > (((int64_t)0LL)))) { return;
 }
S3 x_492 = (*({ hrv *_t1700 = &(g913); int64_t _i1700 = ((*({ hrv *_t1701 = &(g703); int64_t _i1701 = f103_max(n_490, ((int64_t)0LL)); (S4*)_t1701->b + hr_ix(_i1701, _t1701->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:27"); }))).t_; (S3*)_t1700->b + hr_ix(_i1700, _t1700->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:27"); })); 
(void)(({ hrv *_v1703 = &(g403); hsl _s1703 = f10_nm(((int64_t)(((*({ hrv *_t1705 = &(g912); int64_t _i1705 = (x_492).f_; (S2*)_t1705->b + hr_ix(_i1705, _t1705->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:27"); }))).name_))); hr_append(_v1703, _s1703.p, _s1703.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o1706 = &(g403); hr_fs(_o1706, hr_str(":", 1)); hr_fi(_o1706, (x_492).line_); hr_fs(_o1706, hr_str(": error: ", 9)); hr_fs(_o1706, m_491); }));
}
static int64_t f109_global_type(int64_t d_495) {
while ((((g449).n) < ((g488).n))) { (void)(({ hrv *_v1708 = &(g449); int32_t _x1708 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1708 = (int32_t*)hr_grow(_v1708, 1, sizeof _x1708); *_p1708 = _x1708; _p1708; }));
(void)(({ hrv *_v1709 = &(g450); uint8_t _x1709 = ((uint8_t)0LL); uint8_t *_p1709 = (uint8_t*)hr_grow(_v1709, 1, sizeof _x1709); *_p1709 = _x1709; _p1709; }));
 } _bk1707:; 
if ((((*({ hrv *_t1710 = &(g449); int64_t _i1710 = d_495; (int32_t*)_t1710->b + hr_ix(_i1710, _t1710->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:380"); }))) >= (((int32_t)0LL)))) { return ((int64_t)((*({ hrv *_t1711 = &(g449); int64_t _i1711 = d_495; (int32_t*)_t1711->b + hr_ix(_i1711, _t1711->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:380"); }))));
 }
int64_t g_496 = ((int64_t)(((*({ hrv *_t1712 = &(g488); int64_t _i1712 = d_495; (S5*)_t1712->b + hr_ix(_i1712, _t1712->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:381"); }))).node_)); 
S4 x_497 = (*({ hrv *_t1713 = &(g703); int64_t _i1713 = g_496; (S4*)_t1713->b + hr_ix(_i1713, _t1713->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:382"); })); 
int64_t saved_498 = g400; 
int64_t sc_499 = g401; 
g400 = g402;
g401 = g402;
int64_t t_500 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((x_497).a_) >= (((int32_t)0LL)))) { t_500 = f113_rtype(((int64_t)((x_497).a_)), f110_ns_of(g_496));
{ int32_t *_t1716 = &((*({ hrv *_t1717 = &(g449); int64_t _i1717 = d_495; (int32_t*)_t1717->b + hr_ix(_i1717, _t1717->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:386"); }))); *_t1716 = ((int32_t)(t_500)); }
if ((((x_497).b_) >= (((int32_t)0LL)))) { int64_t iv_670 = f90_kid(((int64_t)((x_497).b_)), ((int64_t)0LL)); 
(void)(f137_ck(iv_670, t_500));
(void)(f140_conv(iv_670, t_500));
 }
 } else { if ((((*({ hrv *_t1721 = &(g450); int64_t _i1721 = d_495; (uint8_t*)_t1721->b + hr_ix(_i1721, _t1721->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:388"); }))) == (((uint8_t)1LL)))) { (void)(f108_cerr(g_496, hr_str("global initializer depends on itself", 36)));
g400 = saved_498;
g401 = sc_499;
return g574;
 }
{ uint8_t *_t1723 = &((*({ hrv *_t1724 = &(g450); int64_t _i1724 = d_495; (uint8_t*)_t1724->b + hr_ix(_i1724, _t1724->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:389"); }))); *_t1723 = ((uint8_t)1LL); }
int64_t iv_1474 = f90_kid(((int64_t)((x_497).b_)), ((int64_t)0LL)); 
(void)(f137_ck(iv_1474, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
t_500 = f184_default_t(iv_1474);
if (((((*({ hrv *_t1728 = &(g550); int64_t _i1728 = t_500; (S1*)_t1728->b + hr_ix(_i1728, _t1728->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:393"); }))).k_) == (((uint8_t)18LL)))) { t_500 = g575;
 }
if (((((((*({ hrv *_t1729 = &(g550); int64_t _i1729 = t_500; (S1*)_t1729->b + hr_ix(_i1729, _t1729->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:394"); }))).k_) == (((uint8_t)7LL))) && (((((*({ hrv *_t1730 = &(g703); int64_t _i1730 = iv_1474; (S4*)_t1730->b + hr_ix(_i1730, _t1730->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:394"); }))).k_) == (((uint8_t)14LL))) || ((((*({ hrv *_t1731 = &(g703); int64_t _i1731 = iv_1474; (S4*)_t1731->b + hr_ix(_i1731, _t1731->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:394"); }))).k_) == (((uint8_t)17LL))))) && ((((uint16_t)((uint64_t)(x_497).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))))) { t_500 = f136_t_enum(((int64_t)(((*({ hrv *_t1733 = &(g550); int64_t _i1733 = t_500; (S1*)_t1733->b + hr_ix(_i1733, _t1733->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:394"); }))).a_)), false);
(void)(f142_set_cv(iv_1474, t_500));
 }
{ int32_t *_t1735 = &((*({ hrv *_t1736 = &(g449); int64_t _i1736 = d_495; (int32_t*)_t1736->b + hr_ix(_i1736, _t1736->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:395"); }))); *_t1735 = ((int32_t)(t_500)); }
 }
if ((!(f257_ORD_HAS(d_495)))) { (void)(({ hrv *_v1738 = &(g408); int32_t _x1738 = ((int32_t)(d_495)); int32_t *_p1738 = (int32_t*)hr_grow(_v1738, 1, sizeof _x1738); *_p1738 = _x1738; _p1738; }));
 }
g400 = saved_498;
g401 = sc_499;
return t_500;
}
static int64_t f110_ns_of(int64_t n_501) {
return f112_file_ns(f111_node_file(n_501));
}
static int64_t f111_node_file(int64_t n_502) {
return ((int64_t)(((*({ hrv *_t1741 = &(g913); int64_t _i1741 = ((*({ hrv *_t1742 = &(g703); int64_t _i1742 = n_502; (S4*)_t1742->b + hr_ix(_i1742, _t1742->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:23"); }))).t_; (S3*)_t1741->b + hr_ix(_i1741, _t1741->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:23"); }))).f_));
}
static int64_t f112_file_ns(int64_t f_503) {
return ({ int64_t _r1743; if (((f_503) < ((g495).n))) { _r1743 = ((int64_t)((*({ hrv *_t1744 = &(g495); int64_t _i1744 = f_503; (int32_t*)_t1744->b + hr_ix(_i1744, _t1744->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:24"); }))));  } else { _r1743 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1743; });
}
static int64_t f113_rtype(int64_t n_504, int64_t ns_505) {
if (((n_504) < (((int64_t)0LL)))) { return g557;
 }
S4 x_506 = (*({ hrv *_t1745 = &(g703); int64_t _i1745 = n_504; (S4*)_t1745->b + hr_ix(_i1745, _t1745->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:93"); })); 
int64_t k_507 = ((int64_t)((x_506).k_)); 
if (((k_507) == (((int64_t)40LL)))) { return f114_prim_type(((int64_t)((x_506).op_)));
 }
if (((k_507) == (((int64_t)48LL)))) { return f113_rtype(((int64_t)((x_506).a_)), ns_505);
 }
if (((k_507) == (((int64_t)47LL)))) { return f114_prim_type(((int64_t)((x_506).op_)));
 }
if (((k_507) == (((int64_t)43LL)))) { int64_t e_511 = f113_rtype(((int64_t)((x_506).a_)), ns_505); 
return f18_t_slice(e_511, ((((uint16_t)((uint64_t)(x_506).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))));
 }
if (((k_507) == (((int64_t)44LL)))) { int64_t e_512 = f113_rtype(((int64_t)((x_506).a_)), ns_505); 
int64_t fl_513 = ((int64_t)((int64_t)((int64_t)(((uint16_t)((uint64_t)(x_506).fl_ & (uint64_t)((uint16_t)1LL))))) | (int64_t)((int64_t)(((uint16_t)((uint64_t)(x_506).fl_ & (uint64_t)((uint16_t)2LL))))))); 
if ((((x_506).c_) >= (((int32_t)0LL)))) { int64_t w_514 = ({ int64_t _r1752; if (((((int64_t)((x_506).c_))) == (((int64_t)90LL)))) { _r1752 = ((int64_t)8LL);  } else { _r1752 = f115_int_storage_of_tok(((int64_t)((x_506).c_)));  } _r1752; }); 
int64_t pd_524 = ({ int64_t _r1754; if ((((x_506).s_) >= (((int32_t)0LL)))) { _r1754 = f116_lookup_q(((int64_t)((x_506).s_)), ns_505, ((int64_t)5LL));  } else { _r1754 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1754; }); 
return f118_t_rel(e_512, fl_513, w_514, ((int64_t)(pd_524)));
 }
if ((((((*({ hrv *_t1757 = &(g550); int64_t _i1757 = e_512; (S1*)_t1757->b + hr_ix(_i1757, _t1757->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t1758 = &(g550); int64_t _i1758 = e_512; (S1*)_t1758->b + hr_ix(_i1758, _t1758->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).c_) < (((int32_t)0LL))))) { if (((((int64_t)((int64_t)fl_513 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { return f119_t_ref(((int64_t)(((*({ hrv *_t1760 = &(g550); int64_t _i1760 = e_512; (S1*)_t1760->b + hr_ix(_i1760, _t1760->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).a_)), ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1761 = &(g550); int64_t _i1761 = e_512; (S1*)_t1761->b + hr_ix(_i1761, _t1761->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).fl_)) | (int64_t)((int64_t)2LL))));
 }
return e_512;
 }
return f119_t_ref(e_512, fl_513);
 }
if (((k_507) == (((int64_t)42LL)))) { int64_t e_531 = f113_rtype(((int64_t)((x_506).a_)), ns_505); 
int64_t a_532 = ((int64_t)((x_506).op_)); 
if (((a_532) == (((int64_t)1LL)))) { M56 _t1764 = f120_ceval(((int64_t)((x_506).b_)), ns_505); int64_t v_583 = _t1764.r0; bool ok_584 = _t1764.r1; 
if ((!(ok_584))) { (void)(f102_derr(((int64_t)((x_506).t_)), hr_str("array size must be a constant", 29)));
 }
return f123_t_arr(e_531, ((int64_t)1LL), v_583, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
 }
if (((a_532) == (((int64_t)3LL)))) { if ((((x_506).b_) < (((int32_t)0LL)))) { return f123_t_arr(e_531, ((int64_t)3LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)6LL));
 }
M56 _t1769 = f120_ceval(((int64_t)((x_506).b_)), ns_505); int64_t v_589 = _t1769.r0; bool ok_590 = _t1769.r1; 
if ((!(ok_590))) { (void)(f102_derr(((int64_t)((x_506).t_)), hr_str("capacity must be a constant", 27)));
 }
return f123_t_arr(e_531, ((int64_t)3LL), v_589, f124_lim_lenstore(v_589));
 }
if (((a_532) == (((int64_t)2LL)))) { int64_t ls_592 = ({ int64_t _r1774; if ((((x_506).c_) < (((int32_t)0LL)))) { _r1774 = ((int64_t)6LL);  } else { _r1774 = ({ int64_t _r1775; if (((((int64_t)((x_506).c_))) == (((int64_t)90LL)))) { _r1775 = ((int64_t)8LL);  } else { _r1775 = f115_int_storage_of_tok(((int64_t)((x_506).c_)));  } _r1775; });  } _r1774; }); 
return f123_t_arr(e_531, ((int64_t)2LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ls_592);
 }
return f123_t_arr(e_531, a_532, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
 }
if (((k_507) == (((int64_t)46LL)))) { int64_t b_593 = f113_rtype(((int64_t)((x_506).a_)), ns_505); 
if (((((*({ hrv *_t1780 = &(g550); int64_t _i1780 = b_593; (S1*)_t1780->b + hr_ix(_i1780, _t1780->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:120"); }))).k_) != (((uint8_t)6LL)))) { (void)(f102_derr(((int64_t)((x_506).t_)), hr_str("variant type of a non-enum", 26)));
return g574;
 }
int64_t ei_594 = ((int64_t)(((*({ hrv *_t1782 = &(g550); int64_t _i1782 = b_593; (S1*)_t1782->b + hr_ix(_i1782, _t1782->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:121"); }))).a_)); 
{ int32_t _e1784 = ((*({ hrv *_t1785 = &(g555); int64_t _i1785 = ei_594; (S8*)_t1785->b + hr_ix(_i1785, _t1785->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:122"); }))).vnum_; for (int32_t _k1784 = 0; _k1784 < _e1784; _k1784++) { int32_t i_595 = (int32_t)_k1784; if (((((*({ hrv *_t1786 = &(g556); int64_t _i1786 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1787 = &(g555); int64_t _i1787 = ei_594; (S8*)_t1787->b + hr_ix(_i1787, _t1787->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:122"); }))).v0_)) + (int64_t)((int64_t)(i_595)))); (S9*)_t1786->b + hr_ix(_i1786, _t1786->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:122"); }))).name_) == ((x_506).s_))) { return f125_t_variant(ei_594, ((int64_t)(i_595)));
 }
 } } _bk1783:; 
hrv m_598 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1792 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1790 = &(m_598); hr_fs(_o1790, hr_str("no variant ", 11)); hr_fs(_o1790, f10_nm(((int64_t)((x_506).s_)))); hr_fs(_o1790, hr_str(" in ", 4)); hr_fs(_o1790, hr_sl(*hr_tmp(&_t1792, f126_ty_name(b_593)))); }));
}
(void)(f102_derr(((int64_t)((x_506).t_)), hr_sl(m_598)));
return g574;
 }
if (((k_507) == (((int64_t)45LL)))) { return g577;
 }
if (((k_507) == (((int64_t)41LL)))) { int64_t name_614 = ((int64_t)((x_506).s_)); 
if ((((x_506).n_) == (((int32_t)0LL)))) { int64_t g_617 = f130_gb_find(name_614); 
if (((g_617) >= (((int64_t)0LL)))) { return g_617;
 }
 }
L66 args_618 = ({ L66 _t1796; memset(&_t1796, 0, sizeof _t1796); _t1796.n = 0; _t1796; }); 
{ int32_t _e1798 = (x_506).n_; for (int32_t _k1798 = 0; _k1798 < _e1798; _k1798++) { int32_t i_619 = (int32_t)_k1798; int64_t at0_620 = f113_rtype(f90_kid(n_504, ((int64_t)(i_619))), ns_505); 
(void)(({ L66 *_v1801 = &(args_618); int32_t _x1801 = ((int32_t)(at0_620)); if (_v1801->n >= 16) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:131"); _v1801->e[_v1801->n] = _x1801; &_v1801->e[_v1801->n++]; }));
 } } _bk1797:; 
int64_t d_621 = f116_lookup_q(name_614, ns_505, ((int64_t)1LL)); 
if (((d_621) >= (((int64_t)0LL)))) { return f134_t_struct(f131_inst_struct(((int64_t)(((*({ hrv *_t1805 = &(g488); int64_t _i1805 = d_621; (S5*)_t1805->b + hr_ix(_i1805, _t1805->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:133"); }))).node_)), ({ hsl _t1806 = ({ L66 *_t1807 = &(args_618); (hsl){ (uint8_t*)_t1807->e, _t1807->n }; }); int64_t _l1806 = 0, _h1806 = _t1806.n; if (_l1806 < 0 || _h1806 < _l1806 || _h1806 > _t1806.n) hr_slerr(_l1806, _h1806, _t1806.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:133"); (hsl){ _t1806.p + _l1806 * (int64_t)sizeof(int32_t), _h1806 - _l1806 }; })));
 }
d_621 = f116_lookup_q(name_614, ns_505, ((int64_t)2LL));
if (((d_621) >= (((int64_t)0LL)))) { return f136_t_enum(f135_inst_enum(((int64_t)(((*({ hrv *_t1811 = &(g488); int64_t _i1811 = d_621; (S5*)_t1811->b + hr_ix(_i1811, _t1811->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:135"); }))).node_)), ({ hsl _t1812 = ({ L66 *_t1813 = &(args_618); (hsl){ (uint8_t*)_t1813->e, _t1813->n }; }); int64_t _l1812 = 0, _h1812 = _t1812.n; if (_l1812 < 0 || _h1812 < _l1812 || _h1812 > _t1812.n) hr_slerr(_l1812, _h1812, _t1812.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:135"); (hsl){ _t1812.p + _l1812 * (int64_t)sizeof(int32_t), _h1812 - _l1812 }; })), ((((uint16_t)((uint64_t)(x_506).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))));
 }
d_621 = f116_lookup_q(name_614, ns_505, ((int64_t)3LL));
if (((d_621) >= (((int64_t)0LL)))) { int64_t an_668 = ((int64_t)(((*({ hrv *_t1815 = &(g488); int64_t _i1815 = d_621; (S5*)_t1815->b + hr_ix(_i1815, _t1815->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:137"); }))).node_)); 
return f113_rtype(((int64_t)(((*({ hrv *_t1817 = &(g703); int64_t _i1817 = an_668; (S4*)_t1817->b + hr_ix(_i1817, _t1817->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:137"); }))).b_)), f110_ns_of(an_668));
 }
hrv m_669 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1820 = &(m_669); hr_fs(_o1820, hr_str("unknown type ", 13)); hr_fs(_o1820, f10_nm(name_614)); }));
(void)(f102_derr(((int64_t)((x_506).t_)), hr_sl(m_669)));
return g574;
 }
(void)(f102_derr(((int64_t)((x_506).t_)), hr_str("bad type", 8)));
return g574;
}
static int64_t f114_prim_type(int64_t k_508) {
if (((k_508) == (((int64_t)89LL)))) { return g558;
 }
if (((k_508) == (((int64_t)90LL)))) { return g573;
 }
if (((k_508) == (((int64_t)99LL)))) { return g567;
 }
if ((((k_508) == (((int64_t)100LL))) || ((k_508) == (((int64_t)104LL))))) { return g568;
 }
int64_t s_510 = f115_int_storage_of_tok(k_508); 
return ({ int64_t _r1825; if (((s_510) >= (((int64_t)0LL)))) { _r1825 = f17_t_int(s_510);  } else { _r1825 = g574;  } _r1825; });
}
static int64_t f115_int_storage_of_tok(int64_t k_509) {
if (((k_509) == (((int64_t)91LL)))) { return ((int64_t)0LL);
 }
if (((k_509) == (((int64_t)92LL)))) { return ((int64_t)1LL);
 }
if (((k_509) == (((int64_t)93LL)))) { return ((int64_t)2LL);
 }
if ((((k_509) == (((int64_t)94LL))) || ((k_509) == (((int64_t)101LL))))) { return ((int64_t)3LL);
 }
if ((((k_509) == (((int64_t)95LL))) || ((k_509) == (((int64_t)103LL))))) { return ((int64_t)4LL);
 }
if (((k_509) == (((int64_t)96LL)))) { return ((int64_t)5LL);
 }
if (((k_509) == (((int64_t)97LL)))) { return ((int64_t)6LL);
 }
if ((((k_509) == (((int64_t)98LL))) || ((k_509) == (((int64_t)102LL))))) { return ((int64_t)7LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f116_lookup_q(int64_t q_515, int64_t ns_516, int64_t k_517) {
M55 _t1827 = f117_split_q(q_515); int64_t a_521 = _t1827.r0; int64_t b_522 = _t1827.r1; 
if (((a_521) == (((int64_t)(0 - (uint64_t)(((int64_t)2LL))))))) { return f106_lookup(b_522, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), k_517);
 }
if (((a_521) >= (((int64_t)0LL)))) { int64_t d_523 = f107_dmap(q_515); 
while (((d_523) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1832 = &(g488); int64_t _i1832 = d_523; (S5*)_t1832->b + hr_ix(_i1832, _t1832->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:87"); }))).k_))) == (k_517))) { return d_523;
 }
d_523 = ((int64_t)(((*({ hrv *_t1833 = &(g488); int64_t _i1833 = d_523; (S5*)_t1833->b + hr_ix(_i1833, _t1833->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:87"); }))).next_));
 } _bk1831:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
return f106_lookup(b_522, ns_516, k_517);
}
static M55 f117_split_q(int64_t q_518) {
hsl s_519 = f10_nm(q_518); 
{ int64_t _e1837 = (s_519).n; for (int64_t _k1837 = 0; _k1837 < _e1837; _k1837++) { int64_t i_520 = (int64_t)_k1837; if ((((((*({ hsl _t1838 = s_519; int64_t _i1838 = i_520; (uint8_t*)_t1838.p + hr_ix(_i1838, _t1838.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:81"); }))) == (((uint8_t)58LL))) && ((((int64_t)((int64_t)i_520 + (int64_t)((int64_t)1LL)))) < ((s_519).n))) && (((*({ hsl _t1839 = s_519; int64_t _i1839 = ((int64_t)((int64_t)i_520 + (int64_t)((int64_t)1LL))); (uint8_t*)_t1839.p + hr_ix(_i1839, _t1839.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:81"); }))) == (((uint8_t)58LL))))) { if (((i_520) == (((int64_t)0LL)))) { return (M55){ ((int64_t)(0 - (uint64_t)(((int64_t)2LL)))), f8_intern(({ hsl _t1841 = s_519; int64_t _l1841 = ((int64_t)2LL), _h1841 = _t1841.n; if (_l1841 < 0 || _h1841 < _l1841 || _h1841 > _t1841.n) hr_slerr(_l1841, _h1841, _t1841.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:81"); (hsl){ _t1841.p + _l1841 * (int64_t)sizeof(uint8_t), _h1841 - _l1841 }; })) };
 }
return (M55){ f8_intern(({ hsl _t1843 = s_519; int64_t _l1843 = 0, _h1843 = i_520; if (_l1843 < 0 || _h1843 < _l1843 || _h1843 > _t1843.n) hr_slerr(_l1843, _h1843, _t1843.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:81"); (hsl){ _t1843.p + _l1843 * (int64_t)sizeof(uint8_t), _h1843 - _l1843 }; })), f8_intern(({ hsl _t1845 = s_519; int64_t _l1845 = ((int64_t)((int64_t)i_520 + (int64_t)((int64_t)2LL))), _h1845 = _t1845.n; if (_l1845 < 0 || _h1845 < _l1845 || _h1845 > _t1845.n) hr_slerr(_l1845, _h1845, _t1845.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:81"); (hsl){ _t1845.p + _l1845 * (int64_t)sizeof(uint8_t), _h1845 - _l1845 }; })) };
 }
 } } _bk1836:; 
return (M55){ ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), q_518 };
}
static int64_t f118_t_rel(int64_t e_525, int64_t fl_526, int64_t w_527, int64_t pool_528) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)10LL))), .fl_ = ((uint16_t)(fl_526)), .a_ = ((int32_t)(e_525)), .c_ = ((int32_t)(w_527)), .b_ = pool_528, }));
}
static int64_t f119_t_ref(int64_t e_529, int64_t fl_530) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)10LL))), .fl_ = ((uint16_t)(((int64_t)((int64_t)fl_530 & (int64_t)((int64_t)2LL))))), .a_ = ((int32_t)(e_529)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static M56 f120_ceval(int64_t n_533, int64_t ns_534) {
M57 _t1848 = f121_ceval3(n_533, ns_534); int64_t v_580 = _t1848.r0; int64_t c_581 = _t1848.r1; bool ok_582 = _t1848.r2; 
return (M56){ v_580, ok_582 };
}
static M57 f121_ceval3(int64_t n_535, int64_t ns_536) {
if (((n_535) < (((int64_t)0LL)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
S4 x_537 = (*({ hrv *_t1850 = &(g703); int64_t _i1850 = n_535; (S4*)_t1850->b + hr_ix(_i1850, _t1850->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:205"); })); 
int64_t k_538 = ((int64_t)((x_537).k_)); 
if (((k_538) == (((int64_t)1LL)))) { return (M57){ ((*({ hrv *_t1851 = &(g913); int64_t _i1851 = (x_537).t_; (S3*)_t1851->b + hr_ix(_i1851, _t1851->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:207"); }))).v_, ({ int64_t _r1852; if (((*({ hrv *_t1853 = &(g913); int64_t _i1853 = (x_537).t_; (S3*)_t1853->b + hr_ix(_i1853, _t1853->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:207"); }))).uns_) { _r1852 = ((int64_t)7LL);  } else { _r1852 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1852; }), true };
 }
if (((k_538) == (((int64_t)10LL)))) { M57 _t1854 = f121_ceval3(((int64_t)((x_537).a_)), ns_536); int64_t v_539 = _t1854.r0; int64_t c_540 = _t1854.r1; bool ok_541 = _t1854.r2; 
if (((((int64_t)((x_537).op_))) == (((int64_t)22LL)))) { int64_t c2_542 = ({ int64_t _r1856; if ((((c_540) == (((int64_t)7LL))) && ((((*({ hrv *_t1857 = &(g703); int64_t _i1857 = (x_537).a_; (S4*)_t1857->b + hr_ix(_i1857, _t1857->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:210"); }))).k_) == (((uint8_t)1LL))))) { _r1856 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1856 = c_540;  } _r1856; }); 
return (M57){ f122_cwrap(((int64_t)((int64_t)((int64_t)0LL) - (int64_t)v_539)), c2_542), c2_542, ok_541 };
 }
if (((((int64_t)((x_537).op_))) == (((int64_t)48LL)))) { return (M57){ f122_cwrap(((int64_t)~(v_539)), c_540), c_540, ok_541 };
 }
return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
if (((k_538) == (((int64_t)9LL)))) { M57 _t1860 = f121_ceval3(((int64_t)((x_537).a_)), ns_536); int64_t a_547 = _t1860.r0; int64_t ca_548 = _t1860.r1; bool oa_549 = _t1860.r2; 
M57 _t1862 = f121_ceval3(((int64_t)((x_537).b_)), ns_536); int64_t b_550 = _t1862.r0; int64_t cb_551 = _t1862.r1; bool ob_552 = _t1862.r2; 
if (((!(oa_549)) || (!(ob_552)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
int64_t o_553 = ((int64_t)((x_537).op_)); 
int64_t c_554 = ({ int64_t _r1864; if ((((o_553) == (((int64_t)43LL))) || ((o_553) == (((int64_t)44LL))))) { _r1864 = ca_548;  } else { _r1864 = ({ int64_t _r1865; if (((ca_548) >= (((int64_t)0LL)))) { _r1865 = ca_548;  } else { _r1865 = cb_551;  } _r1865; });  } _r1864; }); 
bool un_555 = ((c_554) >= (((int64_t)4LL))); 
uint64_t ua_556 = ((uint64_t)(a_547)); 
uint64_t ub_557 = ((uint64_t)(b_550)); 
uint64_t sh_558 = ({ uint64_t _r1866; if (((c_554) >= (((int64_t)0LL)))) { _r1866 = ((uint64_t)(((uint64_t)((uint64_t)((uint64_t)((((uint64_t)8LL)) << ((((int64_t)(((int64_t)((int64_t)c_554 & (int64_t)((int64_t)3LL)))))) & 63))) - (uint64_t)((uint64_t)1LL)))));  } else { _r1866 = ((uint64_t)63LL);  } _r1866; }); 
if (((o_553) == (((int64_t)21LL)))) { return (M57){ f122_cwrap(((int64_t)((int64_t)a_547 + (int64_t)b_550)), c_554), c_554, true };
 }
if (((o_553) == (((int64_t)22LL)))) { return (M57){ f122_cwrap(((int64_t)((int64_t)a_547 - (int64_t)b_550)), c_554), c_554, true };
 }
if (((o_553) == (((int64_t)23LL)))) { return (M57){ f122_cwrap(((int64_t)((int64_t)a_547 * (int64_t)b_550)), c_554), c_554, true };
 }
if (((o_553) == (((int64_t)24LL)))) { if (((b_550) == (((int64_t)0LL)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
if (un_555) { return (M57){ f122_cwrap(((int64_t)(HR_UDIV(uint64_t, ua_556, ub_557, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:224"))), c_554), c_554, true };
 }
if (((b_550) == (((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))) { return (M57){ f122_cwrap(((int64_t)((int64_t)((int64_t)0LL) - (int64_t)a_547)), c_554), c_554, true };
 }
return (M57){ f122_cwrap(HR_SDIV(int64_t, a_547, b_550, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:224"), c_554), c_554, true };
 }
if (((o_553) == (((int64_t)25LL)))) { if (((b_550) == (((int64_t)0LL)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
if (un_555) { return (M57){ f122_cwrap(((int64_t)(HR_UDIV_MOD(uint64_t, ua_556, ub_557, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:225"))), c_554), c_554, true };
 }
if ((((b_550) == (((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))) || ((b_550) == (((int64_t)1LL))))) { return (M57){ ((int64_t)0LL), c_554, true };
 }
int64_t r_559 = HR_SMOD(int64_t, a_547, b_550, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:225"); 
return (M57){ f122_cwrap(({ int64_t _r1875; if (((r_559) < (((int64_t)0LL)))) { _r1875 = ({ int64_t _r1876; if (((b_550) < (((int64_t)0LL)))) { _r1876 = ((int64_t)((int64_t)r_559 - (int64_t)b_550));  } else { _r1876 = ((int64_t)((int64_t)r_559 + (int64_t)b_550));  } _r1876; });  } else { _r1875 = r_559;  } _r1875; }), c_554), c_554, true };
 }
if (((o_553) == (((int64_t)43LL)))) { return (M57){ f122_cwrap(((int64_t)((a_547) << ((((uint64_t)((uint64_t)ub_557 & (uint64_t)sh_558))) & 63))), c_554), c_554, true };
 }
if (((o_553) == (((int64_t)44LL)))) { if (un_555) { uint64_t w_560 = ({ uint64_t _r1878; if ((((c_554) >= (((int64_t)0LL))) && ((((int64_t)((int64_t)c_554 & (int64_t)((int64_t)3LL)))) != (((int64_t)3LL))))) { _r1878 = ((uint64_t)((uint64_t)((uint64_t)(a_547)) & (uint64_t)((uint64_t)((uint64_t)((uint64_t)((((uint64_t)1LL)) << ((((uint64_t)((uint64_t)sh_558 + (uint64_t)((uint64_t)1LL)))) & 63))) - (uint64_t)((uint64_t)1LL)))));  } else { _r1878 = ua_556;  } _r1878; }); 
return (M57){ f122_cwrap(((int64_t)(((uint64_t)((w_560) >> ((((uint64_t)((uint64_t)ub_557 & (uint64_t)sh_558))) & 63))))), c_554), c_554, true };
 }
return (M57){ f122_cwrap(((int64_t)((a_547) >> ((((uint64_t)((uint64_t)ub_557 & (uint64_t)sh_558))) & 63))), c_554), c_554, true };
 }
if (((o_553) == (((int64_t)49LL)))) { return (M57){ f122_cwrap(((int64_t)((int64_t)a_547 & (int64_t)b_550)), c_554), c_554, true };
 }
if (((o_553) == (((int64_t)50LL)))) { return (M57){ f122_cwrap(((int64_t)((int64_t)a_547 | (int64_t)b_550)), c_554), c_554, true };
 }
if (((o_553) == (((int64_t)51LL)))) { return (M57){ f122_cwrap(((int64_t)((int64_t)a_547 ^ (int64_t)b_550)), c_554), c_554, true };
 }
return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
if (((k_538) == (((int64_t)15LL)))) { M57 _t1884 = f121_ceval3(((int64_t)((x_537).a_)), ns_536); int64_t v_561 = _t1884.r0; int64_t c_562 = _t1884.r1; bool ok_563 = _t1884.r2; 
int64_t tn0_564 = ((int64_t)((x_537).b_)); 
if (((((*({ hrv *_t1886 = &(g703); int64_t _i1886 = tn0_564; (S4*)_t1886->b + hr_ix(_i1886, _t1886->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:231"); }))).k_) == (((uint8_t)40LL)))) { int64_t tc_565 = f115_int_storage_of_tok(((int64_t)(((*({ hrv *_t1888 = &(g703); int64_t _i1888 = tn0_564; (S4*)_t1888->b + hr_ix(_i1888, _t1888->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:231"); }))).op_))); 
if (((tc_565) >= (((int64_t)0LL)))) { return (M57){ f122_cwrap(v_561, tc_565), tc_565, ok_563 };
 }
 }
return (M57){ v_561, c_562, ok_563 };
 }
if (((k_538) == (((int64_t)8LL)))) { int64_t d_566 = f116_lookup_q(((int64_t)((x_537).s_)), ns_536, ((int64_t)5LL)); 
if (((d_566) < (((int64_t)0LL)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
int64_t g_567 = ((int64_t)(((*({ hrv *_t1891 = &(g488); int64_t _i1891 = d_566; (S5*)_t1891->b + hr_ix(_i1891, _t1891->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:235"); }))).node_)); 
if ((((((uint16_t)((uint64_t)((*({ hrv *_t1892 = &(g703); int64_t _i1892 = g_567; (S4*)_t1892->b + hr_ix(_i1892, _t1892->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:236"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || ((((*({ hrv *_t1893 = &(g703); int64_t _i1893 = g_567; (S4*)_t1893->b + hr_ix(_i1893, _t1893->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:236"); }))).b_) < (((int32_t)0LL))))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
M57 _t1894 = f121_ceval3(f90_kid(((int64_t)(((*({ hrv *_t1897 = &(g703); int64_t _i1897 = g_567; (S4*)_t1897->b + hr_ix(_i1897, _t1897->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:237"); }))).b_)), ((int64_t)0LL)), f110_ns_of(g_567)); int64_t v_568 = _t1894.r0; int64_t c_569 = _t1894.r1; bool ok_570 = _t1894.r2; 
int64_t tn0_571 = ((int64_t)(((*({ hrv *_t1899 = &(g703); int64_t _i1899 = g_567; (S4*)_t1899->b + hr_ix(_i1899, _t1899->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:238"); }))).a_)); 
if ((((tn0_571) >= (((int64_t)0LL))) && ((((*({ hrv *_t1900 = &(g703); int64_t _i1900 = tn0_571; (S4*)_t1900->b + hr_ix(_i1900, _t1900->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:239"); }))).k_) == (((uint8_t)40LL))))) { int64_t tc_572 = f115_int_storage_of_tok(((int64_t)(((*({ hrv *_t1902 = &(g703); int64_t _i1902 = tn0_571; (S4*)_t1902->b + hr_ix(_i1902, _t1902->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:239"); }))).op_))); 
if (((tc_572) >= (((int64_t)0LL)))) { return (M57){ f122_cwrap(v_568, tc_572), tc_572, ok_570 };
 }
 }
return (M57){ v_568, c_569, ok_570 };
 }
if (((((k_538) == (((int64_t)14LL))) && hr_streq(f10_nm(((int64_t)((x_537).s_))), hr_str("len", 3))) && ((((*({ hrv *_t1905 = &(g703); int64_t _i1905 = (x_537).a_; (S4*)_t1905->b + hr_ix(_i1905, _t1905->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:242"); }))).k_) == (((uint8_t)8LL))))) { int64_t d_573 = f116_lookup_q(((int64_t)(((*({ hrv *_t1907 = &(g703); int64_t _i1907 = (x_537).a_; (S4*)_t1907->b + hr_ix(_i1907, _t1907->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:243"); }))).s_)), ns_536, ((int64_t)5LL)); 
if (((d_573) < (((int64_t)0LL)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
int64_t g_574 = ((int64_t)(((*({ hrv *_t1908 = &(g488); int64_t _i1908 = d_573; (S5*)_t1908->b + hr_ix(_i1908, _t1908->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:245"); }))).node_)); 
if (((((*({ hrv *_t1909 = &(g703); int64_t _i1909 = g_574; (S4*)_t1909->b + hr_ix(_i1909, _t1909->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).a_) >= (((int32_t)0LL)))) { int64_t t_575 = f113_rtype(((int64_t)(((*({ hrv *_t1911 = &(g703); int64_t _i1911 = g_574; (S4*)_t1911->b + hr_ix(_i1911, _t1911->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).a_)), f110_ns_of(g_574)); 
if ((((((*({ hrv *_t1913 = &(g550); int64_t _i1913 = t_575; (S1*)_t1913->b + hr_ix(_i1913, _t1913->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).k_) == (((uint8_t)8LL))) && ((((*({ hrv *_t1914 = &(g550); int64_t _i1914 = t_575; (S1*)_t1914->b + hr_ix(_i1914, _t1914->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).s_) == (((uint8_t)(((uint8_t)1LL))))))) { return (M57){ ((*({ hrv *_t1915 = &(g550); int64_t _i1915 = t_575; (S1*)_t1915->b + hr_ix(_i1915, _t1915->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).b_, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
 }
 }
if (((((*({ hrv *_t1916 = &(g703); int64_t _i1916 = g_574; (S4*)_t1916->b + hr_ix(_i1916, _t1916->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_) >= (((int32_t)0LL)))) { int64_t iv_576 = f90_kid(((int64_t)(((*({ hrv *_t1918 = &(g703); int64_t _i1918 = g_574; (S4*)_t1918->b + hr_ix(_i1918, _t1918->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_)), ((int64_t)0LL)); 
if (((((*({ hrv *_t1919 = &(g703); int64_t _i1919 = iv_576; (S4*)_t1919->b + hr_ix(_i1919, _t1919->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).k_) == (((uint8_t)16LL)))) { if (((((*({ hrv *_t1920 = &(g703); int64_t _i1920 = iv_576; (S4*)_t1920->b + hr_ix(_i1920, _t1920->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_) >= (((int32_t)0LL)))) { M57 _t1921 = f121_ceval3(((int64_t)(((*({ hrv *_t1923 = &(g703); int64_t _i1923 = iv_576; (S4*)_t1923->b + hr_ix(_i1923, _t1923->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_)), f110_ns_of(g_574)); int64_t v_577 = _t1921.r0; int64_t c_578 = _t1921.r1; bool ok_579 = _t1921.r2; 
return (M57){ v_577, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ok_579 };
 }
return (M57){ ((int64_t)(((*({ hrv *_t1925 = &(g703); int64_t _i1925 = iv_576; (S4*)_t1925->b + hr_ix(_i1925, _t1925->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).n_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
 }
if (((((*({ hrv *_t1926 = &(g703); int64_t _i1926 = iv_576; (S4*)_t1926->b + hr_ix(_i1926, _t1926->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).k_) == (((uint8_t)3LL)))) { return (M57){ ((int64_t)(((*({ hrv *_t1927 = &(g913); int64_t _i1927 = ((*({ hrv *_t1928 = &(g703); int64_t _i1928 = iv_576; (S4*)_t1928->b + hr_ix(_i1928, _t1928->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).t_; (S3*)_t1927->b + hr_ix(_i1927, _t1927->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).w_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
 }
 }
return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
}
static int64_t f122_cwrap(int64_t v_543, int64_t c_544) {
if ((((c_544) < (((int64_t)0LL))) || ((((int64_t)((int64_t)c_544 & (int64_t)((int64_t)3LL)))) == (((int64_t)3LL))))) { return v_543;
 }
int64_t b_545 = ((int64_t)((((int64_t)8LL)) << ((((int64_t)(((int64_t)((int64_t)c_544 & (int64_t)((int64_t)3LL)))))) & 63))); 
uint64_t u_546 = ((uint64_t)((uint64_t)((uint64_t)(v_543)) & (uint64_t)((uint64_t)((uint64_t)((uint64_t)((((uint64_t)1LL)) << ((((uint64_t)(b_545))) & 63))) - (uint64_t)((uint64_t)1LL))))); 
if ((((c_544) < (((int64_t)4LL))) && ((u_546) >= (((uint64_t)((((uint64_t)1LL)) << ((((uint64_t)(((int64_t)((int64_t)b_545 - (int64_t)((int64_t)1LL)))))) & 63))))))) { return ((int64_t)((int64_t)((int64_t)(u_546)) - (int64_t)((int64_t)((((int64_t)1LL)) << ((b_545) & 63)))));
 }
return ((int64_t)(u_546));
}
static int64_t f123_t_arr(int64_t e_585, int64_t ak_586, int64_t size_587, int64_t ls_588) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)8LL))), .s_ = ((uint8_t)(ak_586)), .a_ = ((int32_t)(e_585)), .c_ = ((int32_t)(ls_588)), .b_ = size_587, }));
}
static int64_t f124_lim_lenstore(int64_t cap_591) {
return ({ int64_t _r1930; if (((cap_591) < (((int64_t)256LL)))) { _r1930 = ((int64_t)4LL);  } else { _r1930 = ({ int64_t _r1931; if (((cap_591) < (((int64_t)65536LL)))) { _r1931 = ((int64_t)5LL);  } else { _r1931 = ({ int64_t _r1932; if (((cap_591) < (((int64_t)4294967296LL)))) { _r1932 = ((int64_t)6LL);  } else { _r1932 = ((int64_t)7LL);  } _r1932; });  } _r1931; });  } _r1930; });
}
static int64_t f125_t_variant(int64_t ei_596, int64_t vi_597) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)7LL))), .a_ = ((int32_t)(ei_596)), .c_ = ((int32_t)(vi_597)), }));
}
static hrv f126_ty_name(int64_t t_599) {
hrv s_600 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(f127_ty_name_into(t_599, (&(s_600))));
return ({ hrv _mv1936 = s_600; s_600.b = 0; s_600.n = 0; _mv1936; });
}
static void f127_ty_name_into(int64_t t_601, hrv* out_602) {
S1 x_603 = (*({ hrv *_t1937 = &(g550); int64_t _i1937 = t_601; (S1*)_t1937->b + hr_ix(_i1937, _t1937->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:199"); })); 
int64_t k_604 = ((int64_t)((x_603).k_)); 
if (((k_604) == (((int64_t)0LL)))) { (void)(({ hrv *_v1938 = out_602; hsl _s1938 = hr_str("<error>", 7); hr_append(_v1938, _s1938.p, _s1938.n, sizeof(uint8_t)); }));
return;
 }
if (((k_604) == (((int64_t)1LL)))) { (void)(({ hrv *_v1939 = out_602; hsl _s1939 = hr_str("void", 4); hr_append(_v1939, _s1939.p, _s1939.n, sizeof(uint8_t)); }));
return;
 }
if (((k_604) == (((int64_t)2LL)))) { (void)(({ hrv *_v1940 = out_602; hsl _s1940 = hr_str("bool", 4); hr_append(_v1940, _s1940.p, _s1940.n, sizeof(uint8_t)); }));
return;
 }
if (((k_604) == (((int64_t)3LL)))) { (void)(f128_ls_kind_name(((int64_t)((x_603).s_)), out_602));
return;
 }
if (((k_604) == (((int64_t)4LL)))) { (void)(({ hrv *_v1942 = out_602; hsl _s1942 = ({ hsl _r1943; if ((((x_603).s_) == (((uint8_t)4LL)))) { _r1943 = hr_str("f32", 3);  } else { _r1943 = hr_str("f64", 3);  } _r1943; }); hr_append(_v1942, _s1942.p, _s1942.n, sizeof(uint8_t)); }));
return;
 }
if (((k_604) == (((int64_t)17LL)))) { (void)(({ hrv *_v1944 = out_602; hsl _s1944 = hr_str("varint", 6); hr_append(_v1944, _s1944.p, _s1944.n, sizeof(uint8_t)); }));
return;
 }
if (((k_604) == (((int64_t)11LL)))) { (void)(({ hrv *_v1945 = out_602; hsl _s1945 = hr_str("null", 4); hr_append(_v1945, _s1945.p, _s1945.n, sizeof(uint8_t)); }));
return;
 }
if (((k_604) == (((int64_t)12LL)))) { (void)(({ hrv *_v1946 = out_602; hsl _s1946 = hr_str("integer constant", 16); hr_append(_v1946, _s1946.p, _s1946.n, sizeof(uint8_t)); }));
return;
 }
if (((k_604) == (((int64_t)13LL)))) { (void)(({ hrv *_v1947 = out_602; hsl _s1947 = hr_str("float constant", 14); hr_append(_v1947, _s1947.p, _s1947.n, sizeof(uint8_t)); }));
return;
 }
if (((k_604) == (((int64_t)18LL)))) { (void)(({ hrv *_v1948 = out_602; hsl _s1948 = hr_str("const u8[:]", 11); hr_append(_v1948, _s1948.p, _s1948.n, sizeof(uint8_t)); }));
return;
 }
if (((k_604) == (((int64_t)16LL)))) { (void)(({ hrv *_v1949 = out_602; hsl _s1949 = f10_nm(((int64_t)((x_603).a_))); hr_append(_v1949, _s1949.p, _s1949.n, sizeof(uint8_t)); }));
return;
 }
if (((k_604) == (((int64_t)5LL)))) { (void)(({ hrv *_v1951 = out_602; hsl _s1951 = f10_nm(((int64_t)(((*({ hrv *_t1953 = &(g553); int64_t _i1953 = (x_603).a_; (S10*)_t1953->b + hr_ix(_i1953, _t1953->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:212"); }))).name_))); hr_append(_v1951, _s1951.p, _s1951.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1955 = &(g553); int64_t _i1955 = (x_603).a_; (S10*)_t1955->b + hr_ix(_i1955, _t1955->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:212"); }))).ta_)), ((int64_t)(((*({ hrv *_t1956 = &(g553); int64_t _i1956 = (x_603).a_; (S10*)_t1956->b + hr_ix(_i1956, _t1956->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:212"); }))).tn_)), out_602));
return;
 }
if (((k_604) == (((int64_t)6LL)))) { (void)(({ hrv *_v1957 = out_602; hsl _s1957 = f10_nm(((int64_t)(((*({ hrv *_t1959 = &(g555); int64_t _i1959 = (x_603).a_; (S8*)_t1959->b + hr_ix(_i1959, _t1959->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:213"); }))).name_))); hr_append(_v1957, _s1957.p, _s1957.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1961 = &(g555); int64_t _i1961 = (x_603).a_; (S8*)_t1961->b + hr_ix(_i1961, _t1961->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:213"); }))).ta_)), ((int64_t)(((*({ hrv *_t1962 = &(g555); int64_t _i1962 = (x_603).a_; (S8*)_t1962->b + hr_ix(_i1962, _t1962->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:213"); }))).tn_)), out_602));
if (((((uint16_t)((uint64_t)(x_603).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v1963 = out_602; hsl _s1963 = hr_str("..", 2); hr_append(_v1963, _s1963.p, _s1963.n, sizeof(uint8_t)); }));
 }
return;
 }
if (((k_604) == (((int64_t)7LL)))) { (void)(({ hrv *_v1964 = out_602; hsl _s1964 = f10_nm(((int64_t)(((*({ hrv *_t1966 = &(g555); int64_t _i1966 = (x_603).a_; (S8*)_t1966->b + hr_ix(_i1966, _t1966->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).name_))); hr_append(_v1964, _s1964.p, _s1964.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1968 = &(g555); int64_t _i1968 = (x_603).a_; (S8*)_t1968->b + hr_ix(_i1968, _t1968->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).ta_)), ((int64_t)(((*({ hrv *_t1969 = &(g555); int64_t _i1969 = (x_603).a_; (S8*)_t1969->b + hr_ix(_i1969, _t1969->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).tn_)), out_602));
(void)(({ hrv *_v1970 = out_602; uint8_t _x1970 = ((uint8_t)46LL); uint8_t *_p1970 = (uint8_t*)hr_grow(_v1970, 1, sizeof _x1970); *_p1970 = _x1970; _p1970; }));
(void)(({ hrv *_v1971 = out_602; hsl _s1971 = f10_nm(((int64_t)(((*({ hrv *_t1973 = &(g556); int64_t _i1973 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1974 = &(g555); int64_t _i1974 = (x_603).a_; (S8*)_t1974->b + hr_ix(_i1974, _t1974->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).v0_)) + (int64_t)((int64_t)((x_603).c_)))); (S9*)_t1973->b + hr_ix(_i1973, _t1973->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).name_))); hr_append(_v1971, _s1971.p, _s1971.n, sizeof(uint8_t)); }));
return;
 }
if (((k_604) == (((int64_t)9LL)))) { if (((((uint16_t)((uint64_t)(x_603).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v1975 = out_602; hsl _s1975 = hr_str("const ", 6); hr_append(_v1975, _s1975.p, _s1975.n, sizeof(uint8_t)); }));
 }
(void)(f127_ty_name_into(((int64_t)((x_603).a_)), out_602));
(void)(({ hrv *_v1977 = out_602; hsl _s1977 = hr_str("[:]", 3); hr_append(_v1977, _s1977.p, _s1977.n, sizeof(uint8_t)); }));
return;
 }
if (((k_604) == (((int64_t)10LL)))) { if (((((uint16_t)((uint64_t)(x_603).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v1978 = out_602; hsl _s1978 = hr_str("const ", 6); hr_append(_v1978, _s1978.p, _s1978.n, sizeof(uint8_t)); }));
 }
(void)(f127_ty_name_into(((int64_t)((x_603).a_)), out_602));
if ((((x_603).c_) >= (((int32_t)0LL)))) { (void)(({ hrv *_v1980 = out_602; hsl _s1980 = hr_str("&<", 2); hr_append(_v1980, _s1980.p, _s1980.n, sizeof(uint8_t)); }));
if ((((x_603).c_) == (((int32_t)8LL)))) { (void)(({ hrv *_v1981 = out_602; hsl _s1981 = hr_str("varint", 6); hr_append(_v1981, _s1981.p, _s1981.n, sizeof(uint8_t)); }));
 } else { (void)(f128_ls_kind_name(((int64_t)((x_603).c_)), out_602));
 }
(void)(({ hrv *_v1983 = out_602; uint8_t _x1983 = ((uint8_t)62LL); uint8_t *_p1983 = (uint8_t*)hr_grow(_v1983, 1, sizeof _x1983); *_p1983 = _x1983; _p1983; }));
if (((((uint16_t)((uint64_t)(x_603).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v1984 = out_602; uint8_t _x1984 = ((uint8_t)63LL); uint8_t *_p1984 = (uint8_t*)hr_grow(_v1984, 1, sizeof _x1984); *_p1984 = _x1984; _p1984; }));
 }
return;
 }
(void)(({ hrv *_v1985 = out_602; hsl _s1985 = ({ hsl _r1986; if (((((uint16_t)((uint64_t)(x_603).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) { _r1986 = hr_str("\077", 1);  } else { _r1986 = hr_str("&", 1);  } _r1986; }); hr_append(_v1985, _s1985.p, _s1985.n, sizeof(uint8_t)); }));
return;
 }
if (((k_604) == (((int64_t)8LL)))) { (void)(f127_ty_name_into(((int64_t)((x_603).a_)), out_602));
int64_t a_612 = ((int64_t)((x_603).s_)); 
if (((a_612) == (((int64_t)1LL)))) { (void)(({ hrv *_o1988 = out_602; hr_fs(_o1988, hr_str("[", 1)); hr_fi(_o1988, (x_603).b_); hr_fs(_o1988, hr_str("]", 1)); }));
 }
if (((a_612) == (((int64_t)2LL)))) { (void)(({ hrv *_v1989 = out_602; hsl _s1989 = ({ hsl _r1990; if (((((x_603).c_) >= (((int32_t)0LL))) && (((x_603).c_) != (((int32_t)6LL))))) { _r1990 = hr_str("[", 1);  } else { _r1990 = hr_str("[]", 2);  } _r1990; }); hr_append(_v1989, _s1989.p, _s1989.n, sizeof(uint8_t)); }));
if (((((x_603).c_) >= (((int32_t)0LL))) && (((x_603).c_) != (((int32_t)6LL))))) { if ((((x_603).c_) == (((int32_t)8LL)))) { (void)(({ hrv *_v1991 = out_602; hsl _s1991 = hr_str("varint", 6); hr_append(_v1991, _s1991.p, _s1991.n, sizeof(uint8_t)); }));
 } else { (void)(f128_ls_kind_name(((int64_t)((x_603).c_)), out_602));
 }
(void)(({ hrv *_v1993 = out_602; uint8_t _x1993 = ((uint8_t)93LL); uint8_t *_p1993 = (uint8_t*)hr_grow(_v1993, 1, sizeof _x1993); *_p1993 = _x1993; _p1993; }));
 }
 }
if (((a_612) == (((int64_t)3LL)))) { if ((((x_603).b_) >= (((int64_t)0LL)))) { (void)(({ hrv *_o1994 = out_602; hr_fs(_o1994, hr_str("[..", 3)); hr_fi(_o1994, (x_603).b_); hr_fs(_o1994, hr_str("]", 1)); }));
 } else { (void)(({ hrv *_v1995 = out_602; hsl _s1995 = hr_str("[..]", 4); hr_append(_v1995, _s1995.p, _s1995.n, sizeof(uint8_t)); }));
 }
 }
if (((a_612) == (((int64_t)4LL)))) { (void)(({ hrv *_v1996 = out_602; hsl _s1996 = hr_str("[>..]", 5); hr_append(_v1996, _s1996.p, _s1996.n, sizeof(uint8_t)); }));
 }
if (((a_612) == (((int64_t)5LL)))) { (void)(({ hrv *_v1997 = out_602; hsl _s1997 = hr_str("[>..<]", 6); hr_append(_v1997, _s1997.p, _s1997.n, sizeof(uint8_t)); }));
 }
return;
 }
if (((k_604) == (((int64_t)14LL)))) { { int32_t _e1999 = (x_603).n_; for (int32_t _k1999 = 0; _k1999 < _e1999; _k1999++) { int32_t i_613 = (int32_t)_k1999; if (((i_613) > (((int32_t)0LL)))) { (void)(({ hrv *_v2000 = out_602; hsl _s2000 = hr_str(", ", 2); hr_append(_v2000, _s2000.p, _s2000.n, sizeof(uint8_t)); }));
 }
(void)(f127_ty_name_into(((int64_t)((*({ hrv *_t2002 = &(g551); int64_t _i2002 = ((int64_t)((int64_t)((int64_t)((x_603).l_)) + (int64_t)((int64_t)(i_613)))); (int32_t*)_t2002->b + hr_ix(_i2002, _t2002->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:232"); })))), out_602));
 } } _bk1998:; 
return;
 }
(void)(({ hrv *_v2003 = out_602; hsl _s2003 = hr_str("fn", 2); hr_append(_v2003, _s2003.p, _s2003.n, sizeof(uint8_t)); }));
}
static void f128_ls_kind_name(int64_t s_605, hrv* out_606) {
A62 names_607 = ({ A62 _t2004; _t2004.e[0] = hr_str("i8", 2); _t2004.e[1] = hr_str("i16", 3); _t2004.e[2] = hr_str("i32", 3); _t2004.e[3] = hr_str("i64", 3); _t2004.e[4] = hr_str("u8", 2); _t2004.e[5] = hr_str("u16", 3); _t2004.e[6] = hr_str("u32", 3); _t2004.e[7] = hr_str("u64", 3); _t2004; }); 
(void)(({ hrv *_v2005 = out_606; hsl _s2005 = (names_607).e[hr_ix(((int64_t)((int64_t)s_605 & (int64_t)((int64_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:197")]; hr_append(_v2005, _s2005.p, _s2005.n, sizeof(uint8_t)); }));
}
static void f129_targs_into(int64_t l_608, int64_t n_609, hrv* out_610) {
if (((n_609) == (((int64_t)0LL)))) { return;
 }
(void)(({ hrv *_v2007 = out_610; uint8_t _x2007 = ((uint8_t)60LL); uint8_t *_p2007 = (uint8_t*)hr_grow(_v2007, 1, sizeof _x2007); *_p2007 = _x2007; _p2007; }));
{ int64_t _e2009 = n_609; for (int64_t _k2009 = 0; _k2009 < _e2009; _k2009++) { int64_t i_611 = (int64_t)_k2009; if (((i_611) > (((int64_t)0LL)))) { (void)(({ hrv *_v2010 = out_610; hsl _s2010 = hr_str(", ", 2); hr_append(_v2010, _s2010.p, _s2010.n, sizeof(uint8_t)); }));
 }
(void)(f127_ty_name_into(((int64_t)((*({ hrv *_t2012 = &(g551); int64_t _i2012 = ((int64_t)((int64_t)l_608 + (int64_t)i_611)); (int32_t*)_t2012->b + hr_ix(_i2012, _t2012->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:235"); })))), out_610));
 } } _bk2008:; 
(void)(({ hrv *_v2013 = out_610; uint8_t _x2013 = ((uint8_t)62LL); uint8_t *_p2013 = (uint8_t*)hr_grow(_v2013, 1, sizeof _x2013); *_p2013 = _x2013; _p2013; }));
}
static int64_t f130_gb_find(int64_t name_615) {
int64_t i_616 = ((int64_t)((int64_t)(g490).n - (int64_t)((int64_t)1LL))); 
while (((i_616) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t2015 = &(g490); int64_t _i2015 = i_616; (S7*)_t2015->b + hr_ix(_i2015, _t2015->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:72"); }))).name_))) == (name_615))) { return ((int64_t)(((*({ hrv *_t2016 = &(g490); int64_t _i2016 = i_616; (S7*)_t2016->b + hr_ix(_i2016, _t2016->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:72"); }))).ty_));
 }
i_616--;
 } _bk2014:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f131_inst_struct(int64_t node_622, hsl args_623) {
{ hrv *_v2018 = &(g553); for (int64_t _k2018 = 0; _k2018 < _v2018->n; _k2018++) { S10 s_624 = ((S10*)_v2018->b)[_k2018]; int64_t i_625 = (int64_t)_k2018; if ((((((int64_t)((s_624).node_))) == (node_622)) && ((((int64_t)((s_624).tn_))) == ((args_623).n)))) { bool same_626 = true; 
{ int64_t _e2020 = (args_623).n; for (int64_t _k2020 = 0; _k2020 < _e2020; _k2020++) { int64_t j_627 = (int64_t)_k2020; if ((((*({ hrv *_t2021 = &(g551); int64_t _i2021 = ((int64_t)((int64_t)((int64_t)((s_624).ta_)) + (int64_t)j_627)); (int32_t*)_t2021->b + hr_ix(_i2021, _t2021->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:146"); }))) != ((*({ hsl _t2022 = args_623; int64_t _i2022 = j_627; (int32_t*)_t2022.p + hr_ix(_i2022, _t2022.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:146"); }))))) { same_626 = false;
 }
 } } _bk2019:; 
if (same_626) { return i_625;
 }
 }
 } } _bk2017:; 
int64_t ta_628 = (g551).n; 
(void)(({ hrv *_v2023 = &(g551); hsl _s2023 = args_623; hr_append(_v2023, _s2023.p, _s2023.n, sizeof(int32_t)); }));
int64_t si_629 = (g553).n; 
(void)(({ hrv *_v2024 = &(g553); S10 _x2024 = ((S10){ .node_ = ((int32_t)(node_622)), .ta_ = ((int32_t)(ta_628)), .tn_ = ((int32_t)((args_623).n)), .f0_ = ((int32_t)((g554).n)), .fnum_ = ((int32_t)0LL), .name_ = ((*({ hrv *_t2025 = &(g703); int64_t _i2025 = node_622; (S4*)_t2025->b + hr_ix(_i2025, _t2025->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:149"); }))).s_, }); S10 *_p2024 = (S10*)hr_grow(_v2024, 1, sizeof _x2024); *_p2024 = _x2024; _p2024; }));
L66 gn_630 = ({ L66 _t2026; memset(&_t2026, 0, sizeof _t2026); _t2026.n = 0; _t2026; }); 
(void)(f132_gen_names(((int64_t)(((*({ hrv *_t2028 = &(g703); int64_t _i2028 = node_622; (S4*)_t2028->b + hr_ix(_i2028, _t2028->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:150"); }))).d_)), (&(gn_630))));
if (((((int64_t)(gn_630).n)) != ((args_623).n))) { (void)(f102_derr(((int64_t)(((*({ hrv *_t2030 = &(g703); int64_t _i2030 = node_622; (S4*)_t2030->b + hr_ix(_i2030, _t2030->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:151"); }))).t_)), hr_str("wrong number of type arguments", 30)));
 }
int64_t g0_634 = (g490).n; 
{ int64_t _e2032 = f45_min(((int64_t)(gn_630).n), (args_623).n); for (int64_t _k2032 = 0; _k2032 < _e2032; _k2032++) { int64_t i_635 = (int64_t)_k2032; (void)(({ hrv *_v2034 = &(g490); S7 _x2034 = ((S7){ .name_ = (*({ L66 *_t2035 = &(gn_630); int64_t _i2035 = i_635; _t2035->e + hr_ix(_i2035, _t2035->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:153"); })), .ty_ = (*({ hsl _t2036 = args_623; int64_t _i2036 = i_635; (int32_t*)_t2036.p + hr_ix(_i2036, _t2036.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:153"); })), }); S7 *_p2034 = (S7*)hr_grow(_v2034, 1, sizeof _x2034); *_p2034 = _x2034; _p2034; }));
 } } _bk2031:; 
int64_t f0_644 = f133_fields_into(node_622, f110_ns_of(node_622)); 
{ int32_t *_t2039 = &(((*({ hrv *_t2040 = &(g553); int64_t _i2040 = si_629; (S10*)_t2040->b + hr_ix(_i2040, _t2040->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:155"); }))).f0_); *_t2039 = ((int32_t)(f0_644)); }
{ int32_t *_t2041 = &(((*({ hrv *_t2042 = &(g553); int64_t _i2042 = si_629; (S10*)_t2042->b + hr_ix(_i2042, _t2042->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:155"); }))).fnum_); *_t2041 = ((int32_t)(((int64_t)((int64_t)(g554).n - (int64_t)f0_644)))); }
(void)(({ hrv *_v2043 = &(g490); int64_t _k2043 = ((int64_t)((int64_t)(g490).n - (int64_t)g0_634)); if (_k2043 < 0 || _k2043 > _v2043->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:156"); _v2043->n -= _k2043; }));
return si_629;
}
static void f132_gen_names(int64_t gl_631, L66* out_632) {
if (((gl_631) >= (((int64_t)0LL)))) { { int32_t _e2045 = ((*({ hrv *_t2046 = &(g703); int64_t _i2046 = gl_631; (S4*)_t2046->b + hr_ix(_i2046, _t2046->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:144"); }))).n_; for (int32_t _k2045 = 0; _k2045 < _e2045; _k2045++) { int32_t i_633 = (int32_t)_k2045; (void)(({ L66 *_v2047 = out_632; int32_t _x2047 = ((*({ hrv *_t2048 = &(g703); int64_t _i2048 = f90_kid(gl_631, ((int64_t)(i_633))); (S4*)_t2048->b + hr_ix(_i2048, _t2048->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:144"); }))).s_; if (_v2047->n >= 16) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:144"); _v2047->e[_v2047->n] = _x2047; &_v2047->e[_v2047->n++]; }));
 } } _bk2044:; 
 }
}
static int64_t f133_fields_into(int64_t node_636, int64_t ns_637) {
L73 buf_638 = ({ L73 _t2050; memset(&_t2050, 0, sizeof _t2050); _t2050.n = 0; _t2050; }); 
{ int32_t _e2052 = ((*({ hrv *_t2053 = &(g703); int64_t _i2053 = node_636; (S4*)_t2053->b + hr_ix(_i2053, _t2053->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:161"); }))).n_; for (int32_t _k2052 = 0; _k2052 < _e2052; _k2052++) { int32_t i_639 = (int32_t)_k2052; int64_t f_640 = f90_kid(node_636, ((int64_t)(i_639))); 
S4 x_641 = (*({ hrv *_t2055 = &(g703); int64_t _i2055 = f_640; (S4*)_t2055->b + hr_ix(_i2055, _t2055->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:163"); })); 
if (((((uint16_t)((uint64_t)(x_641).fl_ & (uint64_t)((uint16_t)4LL)))) != (((uint16_t)0LL)))) { (void)(({ L73 *_v2056 = &(buf_638); S11 _x2056 = ((S11){ .name_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .def_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .fl_ = (x_641).fl_, .padn_ = (x_641).c_, .off_ = ((int64_t)0LL), }); if (_v2056->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:164"); _v2056->e[_v2056->n] = _x2056; &_v2056->e[_v2056->n++]; }));
continue;
 }
int64_t ft_642 = f113_rtype(((int64_t)((x_641).a_)), ns_637); 
(void)(({ L73 *_v2058 = &(buf_638); S11 _x2058 = ((S11){ .name_ = (x_641).s_, .ty_ = ((int32_t)(ft_642)), .def_ = (x_641).b_, .fl_ = (x_641).fl_, .padn_ = ((int32_t)0LL), .off_ = ((int64_t)0LL), }); if (_v2058->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:166"); _v2058->e[_v2058->n] = _x2058; &_v2058->e[_v2058->n++]; }));
 } } _bk2051:; 
int64_t f0_643 = (g554).n; 
(void)(({ hrv *_v2059 = &(g554); hsl _s2059 = ({ hsl _t2060 = ({ L73 *_t2061 = &(buf_638); (hsl){ (uint8_t*)_t2061->e, _t2061->n }; }); int64_t _l2060 = 0, _h2060 = _t2060.n; if (_l2060 < 0 || _h2060 < _l2060 || _h2060 > _t2060.n) hr_slerr(_l2060, _h2060, _t2060.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:169"); (hsl){ _t2060.p + _l2060 * (int64_t)sizeof(S11), _h2060 - _l2060 }; }); hr_append(_v2059, _s2059.p, _s2059.n, sizeof(S11)); }));
return f0_643;
}
static int64_t f134_t_struct(int64_t si_645) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)5LL))), .a_ = ((int32_t)(si_645)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f135_inst_enum(int64_t node_646, hsl args_647) {
{ hrv *_v2064 = &(g555); for (int64_t _k2064 = 0; _k2064 < _v2064->n; _k2064++) { S8 s_648 = ((S8*)_v2064->b)[_k2064]; int64_t i_649 = (int64_t)_k2064; if ((((((int64_t)((s_648).node_))) == (node_646)) && ((((int64_t)((s_648).tn_))) == ((args_647).n)))) { bool same_650 = true; 
{ int64_t _e2066 = (args_647).n; for (int64_t _k2066 = 0; _k2066 < _e2066; _k2066++) { int64_t j_651 = (int64_t)_k2066; if ((((*({ hrv *_t2067 = &(g551); int64_t _i2067 = ((int64_t)((int64_t)((int64_t)((s_648).ta_)) + (int64_t)j_651)); (int32_t*)_t2067->b + hr_ix(_i2067, _t2067->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:173"); }))) != ((*({ hsl _t2068 = args_647; int64_t _i2068 = j_651; (int32_t*)_t2068.p + hr_ix(_i2068, _t2068.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:173"); }))))) { same_650 = false;
 }
 } } _bk2065:; 
if (same_650) { return i_649;
 }
 }
 } } _bk2063:; 
int64_t ta_652 = (g551).n; 
(void)(({ hrv *_v2069 = &(g551); hsl _s2069 = args_647; hr_append(_v2069, _s2069.p, _s2069.n, sizeof(int32_t)); }));
int64_t ei_653 = (g555).n; 
int64_t nv_654 = ((int64_t)(((*({ hrv *_t2070 = &(g703); int64_t _i2070 = node_646; (S4*)_t2070->b + hr_ix(_i2070, _t2070->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:176"); }))).n_)); 
(void)(({ hrv *_v2071 = &(g555); S8 _x2071 = ((S8){ .node_ = ((int32_t)(node_646)), .ta_ = ((int32_t)(ta_652)), .tn_ = ((int32_t)((args_647).n)), .v0_ = ((int32_t)((g556).n)), .vnum_ = ((int32_t)(nv_654)), .name_ = ((*({ hrv *_t2072 = &(g703); int64_t _i2072 = node_646; (S4*)_t2072->b + hr_ix(_i2072, _t2072->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:177"); }))).s_, }); S8 *_p2071 = (S8*)hr_grow(_v2071, 1, sizeof _x2071); *_p2071 = _x2071; _p2071; }));
int64_t v0_655 = (g556).n; 
{ int64_t _e2074 = nv_654; for (int64_t _k2074 = 0; _k2074 < _e2074; _k2074++) { int64_t i_656 = (int64_t)_k2074; int64_t v_657 = f90_kid(node_646, i_656); 
(void)(({ hrv *_v2076 = &(g556); S9 _x2076 = ((S9){ .name_ = ((*({ hrv *_t2077 = &(g703); int64_t _i2077 = v_657; (S4*)_t2077->b + hr_ix(_i2077, _t2077->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:179"); }))).s_, .f0_ = ((int32_t)0LL), .fnum_ = ((int32_t)0LL), .si_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .size_ = ((int64_t)0LL), .haspay_ = ((((uint16_t)((uint64_t)((*({ hrv *_t2078 = &(g703); int64_t _i2078 = v_657; (S4*)_t2078->b + hr_ix(_i2078, _t2078->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:179"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))), }); S9 *_p2076 = (S9*)hr_grow(_v2076, 1, sizeof _x2076); *_p2076 = _x2076; _p2076; }));
 } } _bk2073:; 
L66 gn_658 = ({ L66 _t2079; memset(&_t2079, 0, sizeof _t2079); _t2079.n = 0; _t2079; }); 
(void)(f132_gen_names(((int64_t)(((*({ hrv *_t2081 = &(g703); int64_t _i2081 = node_646; (S4*)_t2081->b + hr_ix(_i2081, _t2081->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:180"); }))).d_)), (&(gn_658))));
int64_t g0_659 = (g490).n; 
{ int64_t _e2083 = f45_min(((int64_t)(gn_658).n), (args_647).n); for (int64_t _k2083 = 0; _k2083 < _e2083; _k2083++) { int64_t i_660 = (int64_t)_k2083; (void)(({ hrv *_v2085 = &(g490); S7 _x2085 = ((S7){ .name_ = (*({ L66 *_t2086 = &(gn_658); int64_t _i2086 = i_660; _t2086->e + hr_ix(_i2086, _t2086->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:182"); })), .ty_ = (*({ hsl _t2087 = args_647; int64_t _i2087 = i_660; (int32_t*)_t2087.p + hr_ix(_i2087, _t2087.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:182"); })), }); S7 *_p2085 = (S7*)hr_grow(_v2085, 1, sizeof _x2085); *_p2085 = _x2085; _p2085; }));
 } } _bk2082:; 
int64_t ns_661 = f110_ns_of(node_646); 
{ int64_t _e2090 = nv_654; for (int64_t _k2090 = 0; _k2090 < _e2090; _k2090++) { int64_t i_662 = (int64_t)_k2090; int64_t v_663 = f90_kid(node_646, i_662); 
int64_t si_664 = (g553).n; 
(void)(({ hrv *_v2092 = &(g553); S10 _x2092 = ((S10){ .node_ = ((int32_t)(v_663)), .ta_ = ((int32_t)(ta_652)), .tn_ = ((int32_t)((args_647).n)), .f0_ = ((int32_t)((g554).n)), .fnum_ = ((int32_t)0LL), .name_ = ((*({ hrv *_t2093 = &(g703); int64_t _i2093 = v_663; (S4*)_t2093->b + hr_ix(_i2093, _t2093->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:187"); }))).s_, }); S10 *_p2092 = (S10*)hr_grow(_v2092, 1, sizeof _x2092); *_p2092 = _x2092; _p2092; }));
int64_t f0_665 = f133_fields_into(v_663, ns_661); 
{ int32_t *_t2095 = &(((*({ hrv *_t2096 = &(g553); int64_t _i2096 = si_664; (S10*)_t2096->b + hr_ix(_i2096, _t2096->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:189"); }))).f0_); *_t2095 = ((int32_t)(f0_665)); }
{ int32_t *_t2097 = &(((*({ hrv *_t2098 = &(g553); int64_t _i2098 = si_664; (S10*)_t2098->b + hr_ix(_i2098, _t2098->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:189"); }))).fnum_); *_t2097 = ((int32_t)(((int64_t)((int64_t)(g554).n - (int64_t)f0_665)))); }
{ int32_t *_t2099 = &(((*({ hrv *_t2100 = &(g556); int64_t _i2100 = ((int64_t)((int64_t)v0_655 + (int64_t)i_662)); (S9*)_t2100->b + hr_ix(_i2100, _t2100->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:190"); }))).si_); *_t2099 = ((int32_t)(si_664)); }
 } } _bk2089:; 
(void)(({ hrv *_v2101 = &(g490); int64_t _k2101 = ((int64_t)((int64_t)(g490).n - (int64_t)g0_659)); if (_k2101 < 0 || _k2101 > _v2101->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:192"); _v2101->n -= _k2101; }));
return ei_653;
}
static int64_t f136_t_enum(int64_t ei_666, bool vm_667) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)6LL))), .fl_ = ({ uint16_t _r2103; if (vm_667) { _r2103 = ((uint16_t)1LL);  } else { _r2103 = ((uint16_t)0LL);  } _r2103; }), .a_ = ((int32_t)(ei_666)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f137_ck(int64_t n_671, int64_t want_672) {
if (((n_671) < (((int64_t)0LL)))) { return g557;
 }
S4 x_673 = (*({ hrv *_t2104 = &(g703); int64_t _i2104 = n_671; (S4*)_t2104->b + hr_ix(_i2104, _t2104->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:670"); })); 
int64_t k_674 = ((int64_t)((x_673).k_)); 
if (((k_674) == (((int64_t)1LL)))) { if ((((want_672) >= (((int64_t)0LL))) && ((((((*({ hrv *_t2105 = &(g550); int64_t _i2105 = want_672; (S1*)_t2105->b + hr_ix(_i2105, _t2105->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:672"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2106 = &(g550); int64_t _i2106 = want_672; (S1*)_t2106->b + hr_ix(_i2106, _t2106->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:672"); }))).k_) == (((uint8_t)4LL)))) || ((((*({ hrv *_t2107 = &(g550); int64_t _i2107 = want_672; (S1*)_t2107->b + hr_ix(_i2107, _t2107->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:672"); }))).k_) == (((uint8_t)17LL)))))) { (void)(f138_set_t(n_671, g570));
(void)(f140_conv(n_671, want_672));
return want_672;
 }
return f138_set_t(n_671, g570);
 }
if (((k_674) == (((int64_t)2LL)))) { if ((((want_672) >= (((int64_t)0LL))) && ((((*({ hrv *_t2111 = &(g550); int64_t _i2111 = want_672; (S1*)_t2111->b + hr_ix(_i2111, _t2111->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:673"); }))).k_) == (((uint8_t)4LL))))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g571);
 }
if (((k_674) == (((int64_t)3LL)))) { if ((((want_672) >= (((int64_t)0LL))) && f164_is_byte_arr(want_672))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g572);
 }
if ((((k_674) == (((int64_t)4LL))) || ((k_674) == (((int64_t)5LL))))) { return f138_set_t(n_671, g558);
 }
if (((k_674) == (((int64_t)6LL)))) { if ((((want_672) >= (((int64_t)0LL))) && f165_is_opt(want_672))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g569);
 }
if (((k_674) == (((int64_t)7LL)))) { return f138_set_t(n_671, ({ int64_t _r2122; if (((want_672) >= (((int64_t)0LL)))) { _r2122 = want_672;  } else { _r2122 = g574;  } _r2122; }));
 }
if (((k_674) == (((int64_t)8LL)))) { return f166_ck_id(n_671, want_672);
 }
if (((k_674) == (((int64_t)9LL)))) { int64_t t_888 = f176_ck_bin(n_671, want_672); 
if (((((want_672) >= (((int64_t)0LL))) && f163_is_pending(t_888)) && (((((*({ hrv *_t2126 = &(g550); int64_t _i2126 = want_672; (S1*)_t2126->b + hr_ix(_i2126, _t2126->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:679"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2127 = &(g550); int64_t _i2127 = want_672; (S1*)_t2127->b + hr_ix(_i2127, _t2127->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:679"); }))).k_) == (((uint8_t)4LL)))))) { (void)(f140_conv(n_671, want_672));
return want_672;
 }
return t_888;
 }
if (((k_674) == (((int64_t)10LL)))) { int64_t t_915 = f183_ck_un(n_671, want_672); 
if (((((want_672) >= (((int64_t)0LL))) && f163_is_pending(t_915)) && (((((*({ hrv *_t2131 = &(g550); int64_t _i2131 = want_672; (S1*)_t2131->b + hr_ix(_i2131, _t2131->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:680"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2132 = &(g550); int64_t _i2132 = want_672; (S1*)_t2132->b + hr_ix(_i2132, _t2132->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:680"); }))).k_) == (((uint8_t)4LL)))))) { (void)(f140_conv(n_671, want_672));
return want_672;
 }
return t_915;
 }
if (((k_674) == (((int64_t)14LL)))) { return f185_ck_dot(n_671, want_672);
 }
if (((k_674) == (((int64_t)12LL)))) { return f189_ck_idx(n_671, want_672);
 }
if (((k_674) == (((int64_t)13LL)))) { return f190_ck_slice(n_671, want_672);
 }
if (((k_674) == (((int64_t)15LL)))) { return f191_ck_as(n_671, want_672);
 }
if (((k_674) == (((int64_t)16LL)))) { return f192_ck_arr(n_671, want_672);
 }
if (((k_674) == (((int64_t)23LL)))) { return f193_ck_block(n_671, want_672);
 }
if (((k_674) == (((int64_t)24LL)))) { (void)(({ hrv *_v2140 = &(g467); int32_t _x2140 = ({ int32_t _r2141; if ((((want_672) >= (((int64_t)0LL))) && ((want_672) != (g557)))) { _r2141 = ((int32_t)(want_672));  } else { _r2141 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));  } _r2141; }); int32_t *_p2140 = (int32_t*)hr_grow(_v2140, 1, sizeof _x2140); *_p2140 = _x2140; _p2140; }));
int64_t bt_1100 = f137_ck(((int64_t)((x_673).a_)), want_672); 
int64_t t_1101 = ((int64_t)(({ hrv *_v2143 = &(g467); if (!_v2143->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:687"); ((int32_t*)_v2143->b)[--_v2143->n]; }))); 
if ((((bt_1100) != (g557)) && (!(f163_is_pending(bt_1100))))) { return f138_set_t(n_671, bt_1100);
 }
if (((t_1101) >= (((int64_t)0LL)))) { (void)(f140_conv(((int64_t)((x_673).a_)), t_1101));
return f138_set_t(n_671, t_1101);
 }
return f138_set_t(n_671, bt_1100);
 }
if (((k_674) == (((int64_t)19LL)))) { return f212_ck_if(n_671, want_672);
 }
if (((k_674) == (((int64_t)25LL)))) { return f213_ck_while(n_671);
 }
if (((k_674) == (((int64_t)26LL)))) { return f214_ck_loop(n_671, want_672);
 }
if (((k_674) == (((int64_t)27LL)))) { return f215_ck_for(n_671);
 }
if (((k_674) == (((int64_t)20LL)))) { return f218_ck_match(n_671, want_672);
 }
if (((k_674) == (((int64_t)28LL)))) { return f219_ck_ret(n_671);
 }
if (((k_674) == (((int64_t)29LL)))) { return f222_ck_break(n_671);
 }
if (((k_674) == (((int64_t)30LL)))) { return f138_set_t(n_671, g557);
 }
if (((k_674) == (((int64_t)11LL)))) { return f223_ck_call(n_671, want_672);
 }
if (((k_674) == (((int64_t)17LL)))) { return f256_ck_slit(n_671, want_672);
 }
if (((k_674) == (((int64_t)31LL)))) { return f138_set_t(n_671, g577);
 }
(void)(f108_cerr(n_671, hr_str("unsupported expression", 22)));
return f138_set_t(n_671, g574);
}
static int64_t f138_set_t(int64_t n_675, int64_t t_676) {
{ int32_t *_t2162 = &((*({ hrv *_t2163 = &(g394); int64_t _i2163 = f139_aix(n_675); (int32_t*)_t2163->b + hr_ix(_i2163, _t2163->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:42"); }))); *_t2162 = ((int32_t)(t_676)); }
return t_676;
}
static int64_t f139_aix(int64_t n_677) {
int64_t i_678 = g400; 
while (((i_678) >= (((int64_t)0LL)))) { S6 f_679 = (*({ hrv *_t2166 = &(g387); int64_t _i2166 = i_678; (S6*)_t2166->b + hr_ix(_i2166, _t2166->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:37"); })); 
if ((((n_677) >= (((int64_t)((f_679).lo_)))) && ((n_677) < (((int64_t)((f_679).hi_)))))) { return ((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((f_679).ab_)) + (int64_t)n_677)) - (int64_t)((int64_t)((f_679).lo_))));
 }
i_678 = ((int64_t)((f_679).par_));
 } _bk2165:; 
S6 g_680 = (*({ hrv *_t2167 = &(g387); int64_t _i2167 = g402; (S6*)_t2167->b + hr_ix(_i2167, _t2167->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:38"); })); 
return ((int64_t)((int64_t)((int64_t)((g_680).ab_)) + (int64_t)n_677));
}
static bool f140_conv(int64_t n_681, int64_t t_682) {
if ((((t_682) < (((int64_t)0LL))) || ((n_681) < (((int64_t)0LL))))) { return true;
 }
int64_t f_684 = f141_at(n_681); 
if (((f_684) < (((int64_t)0LL)))) { return true;
 }
if (((f_684) == (t_682))) { return true;
 }
int64_t fk_685 = ((int64_t)(((*({ hrv *_t2169 = &(g550); int64_t _i2169 = f_684; (S1*)_t2169->b + hr_ix(_i2169, _t2169->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:148"); }))).k_)); 
int64_t tkd_686 = ((int64_t)(((*({ hrv *_t2170 = &(g550); int64_t _i2170 = t_682; (S1*)_t2170->b + hr_ix(_i2170, _t2170->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:149"); }))).k_)); 
if ((((tkd_686) == (((int64_t)0LL))) || ((fk_685) == (((int64_t)0LL))))) { return true;
 }
if (((((tkd_686) == (((int64_t)2LL))) && ((fk_685) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2171 = &(g550); int64_t _i2171 = f_684; (S1*)_t2171->b + hr_ix(_i2171, _t2171->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:151"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f142_set_cv(n_681, g558));
return true;
 }
if ((((((tkd_686) == (((int64_t)10LL))) && ((((*({ hrv *_t2173 = &(g550); int64_t _i2173 = t_682; (S1*)_t2173->b + hr_ix(_i2173, _t2173->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:152"); }))).c_) < (((int32_t)0LL)))) && ((fk_685) != (((int64_t)11LL)))) && ((fk_685) != (((int64_t)10LL))))) { if (((f143_tclass(t_682)) >= (((int64_t)0LL)))) { bool ok_735 = f140_conv(n_681, ((int64_t)(((*({ hrv *_t2176 = &(g550); int64_t _i2176 = t_682; (S1*)_t2176->b + hr_ix(_i2176, _t2176->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:152"); }))).a_))); 
if ((ok_735 && ((f150_cv(n_681)) < (((int64_t)0LL))))) { (void)(f142_set_cv(n_681, t_682));
 }
return ok_735;
 }
 }
if (((((fk_685) == (((int64_t)10LL))) && ((((*({ hrv *_t2179 = &(g550); int64_t _i2179 = f_684; (S1*)_t2179->b + hr_ix(_i2179, _t2179->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:153"); }))).c_) < (((int32_t)0LL)))) && ((tkd_686) != (((int64_t)10LL))))) { if (f151_conv_ok(((int64_t)(((*({ hrv *_t2181 = &(g550); int64_t _i2181 = f_684; (S1*)_t2181->b + hr_ix(_i2181, _t2181->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:153"); }))).a_)), t_682, n_681)) { (void)(f142_set_cv(n_681, t_682));
return true;
 }
 }
if (((fk_685) == (((int64_t)12LL)))) { M78 _t2183 = f155_cval(n_681); int64_t v_765 = _t2183.r0; bool u_766 = _t2183.r1; bool ok_767 = _t2183.r2; 
if (((tkd_686) == (((int64_t)3LL)))) { if ((ok_767 && (!(f158_int_fits(v_765, u_766, t_682))))) { hrv m_776 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2188 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2187 = &(m_776); hr_fs(_o2187, hr_str("constant ", 9)); hr_fi(_o2187, v_765); hr_fs(_o2187, hr_str(" does not fit in ", 17)); hr_fs(_o2187, hr_sl(*hr_tmp(&_t2188, f161_tn(t_682)))); }));
}
(void)(f108_cerr(n_681, hr_sl(m_776)));
return false;
 }
(void)(f162_commit(n_681, t_682));
return true;
 }
if ((((tkd_686) == (((int64_t)4LL))) || ((tkd_686) == (((int64_t)17LL))))) { (void)(f162_commit(n_681, t_682));
return true;
 }
 }
if ((((fk_685) == (((int64_t)13LL))) && ((tkd_686) == (((int64_t)4LL))))) { (void)(f162_commit(n_681, t_682));
return true;
 }
if ((((fk_685) == (((int64_t)18LL))) && (f164_is_byte_arr(t_682) || (((tkd_686) == (((int64_t)10LL))) && f164_is_byte_arr(((int64_t)(((*({ hrv *_t2196 = &(g550); int64_t _i2196 = t_682; (S1*)_t2196->b + hr_ix(_i2196, _t2196->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:160"); }))).a_))))))) { (void)(f162_commit(n_681, ({ int64_t _r2198; if (((tkd_686) == (((int64_t)10LL)))) { _r2198 = ((int64_t)(((*({ hrv *_t2199 = &(g550); int64_t _i2199 = t_682; (S1*)_t2199->b + hr_ix(_i2199, _t2199->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:160"); }))).a_));  } else { _r2198 = t_682;  } _r2198; })));
return true;
 }
if ((((fk_685) == (((int64_t)19LL))) && (((tkd_686) == (((int64_t)8LL))) || ((tkd_686) == (((int64_t)9LL)))))) { (void)(f162_commit(n_681, t_682));
return true;
 }
if (((((fk_685) == (((int64_t)11LL))) && ((tkd_686) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2201 = &(g550); int64_t _i2201 = t_682; (S1*)_t2201->b + hr_ix(_i2201, _t2201->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:162"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f162_commit(n_681, t_682));
return true;
 }
if (f151_conv_ok(f_684, t_682, n_681)) { (void)(f142_set_cv(n_681, t_682));
return true;
 }
hrv m_791 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2207 __attribute__((cleanup(hr_rdrop))) = {0}; hrv _t2209 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2206 = &(m_791); hr_fs(_o2206, hr_str("cannot convert ", 15)); hr_fs(_o2206, hr_sl(*hr_tmp(&_t2207, f161_tn(f_684)))); hr_fs(_o2206, hr_str(" to ", 4)); hr_fs(_o2206, hr_sl(*hr_tmp(&_t2209, f161_tn(t_682)))); }));
}
(void)(f108_cerr(n_681, hr_sl(m_791)));
return false;
}
static int64_t f141_at(int64_t n_683) {
return ((int64_t)((*({ hrv *_t2212 = &(g394); int64_t _i2212 = f139_aix(n_683); (int32_t*)_t2212->b + hr_ix(_i2212, _t2212->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:41"); }))));
}
static void f142_set_cv(int64_t n_687, int64_t t_688) {
{ int32_t *_t2214 = &((*({ hrv *_t2215 = &(g395); int64_t _i2215 = f139_aix(n_687); (int32_t*)_t2215->b + hr_ix(_i2215, _t2215->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:48"); }))); *_t2214 = ((int32_t)(t_688)); }
}
static int64_t f143_tclass(int64_t t_689) {
S1 x_690 = (*({ hrv *_t2217 = &(g550); int64_t _i2217 = t_689; (S1*)_t2217->b + hr_ix(_i2217, _t2217->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:83"); })); 
int64_t k_691 = ((int64_t)((x_690).k_)); 
if (((k_691) == (((int64_t)5LL)))) { (void)(f144_si_layout(((int64_t)((x_690).a_))));
return ((int64_t)(((*({ hrv *_t2219 = &(g553); int64_t _i2219 = (x_690).a_; (S10*)_t2219->b + hr_ix(_i2219, _t2219->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:85"); }))).cls_));
 }
if (((k_691) == (((int64_t)7LL)))) { (void)(f146_ei_layout(((int64_t)((x_690).a_))));
S9 v_732 = (*({ hrv *_t2221 = &(g556); int64_t _i2221 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2222 = &(g555); int64_t _i2222 = (x_690).a_; (S8*)_t2222->b + hr_ix(_i2222, _t2222->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:86"); }))).v0_)) + (int64_t)((int64_t)((x_690).c_)))); (S9*)_t2221->b + hr_ix(_i2221, _t2221->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:86"); })); 
if ((((v_732).si_) >= (((int32_t)0LL)))) { (void)(f144_si_layout(((int64_t)((v_732).si_))));
return ((int64_t)(((*({ hrv *_t2224 = &(g553); int64_t _i2224 = (v_732).si_; (S10*)_t2224->b + hr_ix(_i2224, _t2224->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:86"); }))).cls_));
 }
return ((int64_t)0LL);
 }
if (((k_691) == (((int64_t)6LL)))) { (void)(f146_ei_layout(((int64_t)((x_690).a_))));
if (((((uint16_t)((uint64_t)(x_690).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) { return ((int64_t)0LL);
 }
return ((int64_t)1LL);
 }
if (((k_691) == (((int64_t)8LL)))) { int64_t a_733 = ((int64_t)((x_690).s_)); 
if ((((a_733) == (((int64_t)4LL))) || ((a_733) == (((int64_t)5LL))))) { return ((int64_t)2LL);
 }
if (((a_733) == (((int64_t)2LL)))) { return ((int64_t)1LL);
 }
if ((((a_733) == (((int64_t)3LL))) && (((x_690).b_) < (((int64_t)0LL))))) { return ((int64_t)1LL);
 }
int64_t ec_734 = f143_tclass(((int64_t)((x_690).a_))); 
return ({ int64_t _r2227; if (((ec_734) > (((int64_t)0LL)))) { _r2227 = ((int64_t)1LL);  } else { _r2227 = ((int64_t)0LL);  } _r2227; });
 }
if ((((k_691) == (((int64_t)17LL))) || (((k_691) == (((int64_t)10LL))) && (((x_690).c_) == (((int32_t)8LL)))))) { return ((int64_t)1LL);
 }
return ((int64_t)0LL);
}
static void f144_si_layout(int64_t si_692) {
if (((((*({ hrv *_t2228 = &(g553); int64_t _i2228 = si_692; (S10*)_t2228->b + hr_ix(_i2228, _t2228->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:127"); }))).done_) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t2229 = &(((*({ hrv *_t2230 = &(g553); int64_t _i2230 = si_692; (S10*)_t2230->b + hr_ix(_i2230, _t2230->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:128"); }))).done_); *_t2229 = ((uint8_t)1LL); }
int64_t off_693 = ((int64_t)0LL); 
int64_t cls_694 = ((int64_t)0LL); 
bool flat_695 = true; 
int64_t f0_696 = ((int64_t)(((*({ hrv *_t2231 = &(g553); int64_t _i2231 = si_692; (S10*)_t2231->b + hr_ix(_i2231, _t2231->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:130"); }))).f0_)); 
int64_t fnum_697 = ((int64_t)(((*({ hrv *_t2232 = &(g553); int64_t _i2232 = si_692; (S10*)_t2232->b + hr_ix(_i2232, _t2232->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:130"); }))).fnum_)); 
{ int64_t _e2234 = fnum_697; for (int64_t _k2234 = 0; _k2234 < _e2234; _k2234++) { int64_t i_698 = (int64_t)_k2234; int64_t fi_699 = ((int64_t)((int64_t)f0_696 + (int64_t)i_698)); 
int64_t ft_700 = ((int64_t)(((*({ hrv *_t2235 = &(g554); int64_t _i2235 = fi_699; (S11*)_t2235->b + hr_ix(_i2235, _t2235->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:133"); }))).ty_)); 
if (((ft_700) >= (((int64_t)0LL)))) { int64_t c_701 = f143_tclass(ft_700); 
if (((c_701) > (cls_694))) { cls_694 = c_701;
 }
if ((!(f145_tflat(ft_700)))) { flat_695 = false;
 }
 }
 } } _bk2233:; 
bool cur_var_715 = false; 
{ int64_t _e2239 = fnum_697; for (int64_t _k2239 = 0; _k2239 < _e2239; _k2239++) { int64_t i_716 = (int64_t)_k2239; int64_t fi_717 = ((int64_t)((int64_t)f0_696 + (int64_t)i_716)); 
int64_t ft_718 = ((int64_t)(((*({ hrv *_t2240 = &(g554); int64_t _i2240 = fi_717; (S11*)_t2240->b + hr_ix(_i2240, _t2240->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:143"); }))).ty_)); 
if (((ft_718) < (((int64_t)0LL)))) { if (((((*({ hrv *_t2241 = &(g554); int64_t _i2241 = fi_717; (S11*)_t2241->b + hr_ix(_i2241, _t2241->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:145"); }))).padn_) < (((int32_t)0LL)))) { if (((cls_694) == (((int64_t)0LL)))) { int64_t a_719 = ((int64_t)1LL); 
{ int64_t _e2243 = fnum_697; for (int64_t _k2243 = ((int64_t)((int64_t)i_716 + (int64_t)((int64_t)1LL))); _k2243 < _e2243; _k2243++) { int64_t j_720 = (int64_t)_k2243; if (((((*({ hrv *_t2244 = &(g554); int64_t _i2244 = ((int64_t)((int64_t)f0_696 + (int64_t)j_720)); (S11*)_t2244->b + hr_ix(_i2244, _t2244->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:148"); }))).ty_) >= (((int32_t)0LL)))) { a_719 = f147_pad_align(((int64_t)(((*({ hrv *_t2246 = &(g554); int64_t _i2246 = ((int64_t)((int64_t)f0_696 + (int64_t)j_720)); (S11*)_t2246->b + hr_ix(_i2246, _t2246->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:148"); }))).ty_)));
{ goto _bk2242; }
 }
 } } _bk2242:; 
int64_t next_off_725 = ((int64_t)((int64_t)HR_SDIV(int64_t, ((int64_t)((int64_t)((int64_t)((int64_t)off_693 + (int64_t)a_719)) - (int64_t)((int64_t)1LL))), a_719, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:149") * (int64_t)a_719)); 
{ int32_t *_t2247 = &(((*({ hrv *_t2248 = &(g554); int64_t _i2248 = fi_717; (S11*)_t2248->b + hr_ix(_i2248, _t2248->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:150"); }))).padn_); *_t2247 = ((int32_t)(((int64_t)((int64_t)next_off_725 - (int64_t)off_693)))); }
{ int64_t *_t2249 = &(((*({ hrv *_t2250 = &(g554); int64_t _i2250 = fi_717; (S11*)_t2250->b + hr_ix(_i2250, _t2250->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:151"); }))).off_); *_t2249 = off_693; }
off_693 = next_off_725;
 } else { { int32_t *_t2251 = &(((*({ hrv *_t2252 = &(g554); int64_t _i2252 = fi_717; (S11*)_t2252->b + hr_ix(_i2252, _t2252->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:154"); }))).padn_); *_t2251 = ((int32_t)0LL); }
{ int64_t *_t2253 = &(((*({ hrv *_t2254 = &(g554); int64_t _i2254 = fi_717; (S11*)_t2254->b + hr_ix(_i2254, _t2254->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:155"); }))).off_); *_t2253 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); }
 }
 } else { { int64_t *_t2255 = &(((*({ hrv *_t2256 = &(g554); int64_t _i2256 = fi_717; (S11*)_t2256->b + hr_ix(_i2256, _t2256->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:158"); }))).off_); *_t2255 = ({ int64_t _r2257; if ((!(cur_var_715))) { _r2257 = off_693;  } else { _r2257 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2257; }); }
if ((!(cur_var_715))) { { int64_t *_t2258 = &(off_693); *_t2258 = ((int64_t)((int64_t)(*_t2258) + (int64_t)((int64_t)(((*({ hrv *_t2259 = &(g554); int64_t _i2259 = fi_717; (S11*)_t2259->b + hr_ix(_i2259, _t2259->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:159"); }))).padn_)))); }
 }
 }
continue;
 }
int64_t c_726 = f143_tclass(ft_718); 
if (((c_726) != (((int64_t)0LL)))) { cur_var_715 = true;
 }
{ int64_t *_t2261 = &(((*({ hrv *_t2262 = &(g554); int64_t _i2262 = fi_717; (S11*)_t2262->b + hr_ix(_i2262, _t2262->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:165"); }))).off_); *_t2261 = ({ int64_t _r2263; if ((!(cur_var_715))) { _r2263 = off_693;  } else { _r2263 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2263; }); }
if ((!(cur_var_715))) { { int64_t *_t2264 = &(off_693); *_t2264 = ((int64_t)((int64_t)(*_t2264) + (int64_t)f149_tsize(ft_718))); }
 }
 } } _bk2238:; 
{ uint8_t *_t2266 = &(((*({ hrv *_t2267 = &(g553); int64_t _i2267 = si_692; (S10*)_t2267->b + hr_ix(_i2267, _t2267->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:168"); }))).cls_); *_t2266 = ((uint8_t)(cls_694)); }
{ bool *_t2268 = &(((*({ hrv *_t2269 = &(g553); int64_t _i2269 = si_692; (S10*)_t2269->b + hr_ix(_i2269, _t2269->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:168"); }))).flat_); *_t2268 = flat_695; }
{ int64_t *_t2270 = &(((*({ hrv *_t2271 = &(g553); int64_t _i2271 = si_692; (S10*)_t2271->b + hr_ix(_i2271, _t2271->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:169"); }))).size_); *_t2270 = ({ int64_t _r2272; if (((cls_694) == (((int64_t)0LL)))) { _r2272 = f103_max(off_693, ((int64_t)1LL));  } else { _r2272 = off_693;  } _r2272; }); }
{ bool *_t2274 = &(((*({ hrv *_t2275 = &(g553); int64_t _i2275 = si_692; (S10*)_t2275->b + hr_ix(_i2275, _t2275->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:170"); }))).zero_); *_t2274 = (((cls_694) == (((int64_t)0LL))) && ((off_693) == (((int64_t)0LL)))); }
{ uint8_t *_t2276 = &(((*({ hrv *_t2277 = &(g553); int64_t _i2277 = si_692; (S10*)_t2277->b + hr_ix(_i2277, _t2277->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:171"); }))).done_); *_t2276 = ((uint8_t)2LL); }
}
static bool f145_tflat(int64_t t_702) {
S1 x_703 = (*({ hrv *_t2278 = &(g550); int64_t _i2278 = t_702; (S1*)_t2278->b + hr_ix(_i2278, _t2278->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:118"); })); 
int64_t k_704 = ((int64_t)((x_703).k_)); 
if ((((k_704) == (((int64_t)10LL))) || ((k_704) == (((int64_t)9LL))))) { return false;
 }
if (((k_704) == (((int64_t)5LL)))) { (void)(f144_si_layout(((int64_t)((x_703).a_))));
return ((*({ hrv *_t2280 = &(g553); int64_t _i2280 = (x_703).a_; (S10*)_t2280->b + hr_ix(_i2280, _t2280->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:120"); }))).flat_;
 }
if ((((k_704) == (((int64_t)6LL))) || ((k_704) == (((int64_t)7LL))))) { (void)(f146_ei_layout(((int64_t)((x_703).a_))));
return ((*({ hrv *_t2282 = &(g555); int64_t _i2282 = (x_703).a_; (S8*)_t2282->b + hr_ix(_i2282, _t2282->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:121"); }))).flat_;
 }
if (((k_704) == (((int64_t)8LL)))) { return f145_tflat(((int64_t)((x_703).a_)));
 }
return true;
}
static void f146_ei_layout(int64_t ei_705) {
if (((((*({ hrv *_t2284 = &(g555); int64_t _i2284 = ei_705; (S8*)_t2284->b + hr_ix(_i2284, _t2284->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:174"); }))).done_) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t2285 = &(((*({ hrv *_t2286 = &(g555); int64_t _i2286 = ei_705; (S8*)_t2286->b + hr_ix(_i2286, _t2286->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:175"); }))).done_); *_t2285 = ((uint8_t)1LL); }
int64_t nv_706 = ((int64_t)(((*({ hrv *_t2287 = &(g555); int64_t _i2287 = ei_705; (S8*)_t2287->b + hr_ix(_i2287, _t2287->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:176"); }))).vnum_)); 
int64_t tz_707 = ({ int64_t _r2288; if (((nv_706) <= (((int64_t)256LL)))) { _r2288 = ((int64_t)1LL);  } else { _r2288 = ((int64_t)2LL);  } _r2288; }); 
{ uint8_t *_t2289 = &(((*({ hrv *_t2290 = &(g555); int64_t _i2290 = ei_705; (S8*)_t2290->b + hr_ix(_i2290, _t2290->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:178"); }))).tagsz_); *_t2289 = ((uint8_t)(tz_707)); }
int64_t mx_708 = ((int64_t)0LL); 
int64_t cls_709 = ((int64_t)0LL); 
bool flat_710 = true; 
{ int64_t _e2292 = nv_706; for (int64_t _k2292 = 0; _k2292 < _e2292; _k2292++) { int64_t i_711 = (int64_t)_k2292; int64_t v_712 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2293 = &(g555); int64_t _i2293 = ei_705; (S8*)_t2293->b + hr_ix(_i2293, _t2293->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:181"); }))).v0_)) + (int64_t)i_711)); 
if (((((*({ hrv *_t2294 = &(g556); int64_t _i2294 = v_712; (S9*)_t2294->b + hr_ix(_i2294, _t2294->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:182"); }))).si_) >= (((int32_t)0LL)))) { int64_t si_713 = ((int64_t)(((*({ hrv *_t2295 = &(g556); int64_t _i2295 = v_712; (S9*)_t2295->b + hr_ix(_i2295, _t2295->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:183"); }))).si_)); 
(void)(f144_si_layout(si_713));
if (((((int64_t)(((*({ hrv *_t2297 = &(g553); int64_t _i2297 = si_713; (S10*)_t2297->b + hr_ix(_i2297, _t2297->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:185"); }))).cls_))) > (cls_709))) { cls_709 = ((int64_t)(((*({ hrv *_t2298 = &(g553); int64_t _i2298 = si_713; (S10*)_t2298->b + hr_ix(_i2298, _t2298->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:185"); }))).cls_));
 }
if ((!(((*({ hrv *_t2299 = &(g553); int64_t _i2299 = si_713; (S10*)_t2299->b + hr_ix(_i2299, _t2299->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:186"); }))).flat_))) { flat_710 = false;
 }
int64_t ps_714 = ({ int64_t _r2300; if (((*({ hrv *_t2301 = &(g553); int64_t _i2301 = si_713; (S10*)_t2301->b + hr_ix(_i2301, _t2301->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:187"); }))).zero_) { _r2300 = ((int64_t)0LL);  } else { _r2300 = ((*({ hrv *_t2302 = &(g553); int64_t _i2302 = si_713; (S10*)_t2302->b + hr_ix(_i2302, _t2302->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:187"); }))).size_;  } _r2300; }); 
{ int64_t *_t2303 = &(((*({ hrv *_t2304 = &(g556); int64_t _i2304 = v_712; (S9*)_t2304->b + hr_ix(_i2304, _t2304->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:188"); }))).size_); *_t2303 = ps_714; }
if (((ps_714) > (mx_708))) { mx_708 = ps_714;
 }
 }
 } } _bk2291:; 
{ uint8_t *_t2305 = &(((*({ hrv *_t2306 = &(g555); int64_t _i2306 = ei_705; (S8*)_t2306->b + hr_ix(_i2306, _t2306->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:192"); }))).cls_); *_t2305 = ((uint8_t)(cls_709)); }
{ bool *_t2307 = &(((*({ hrv *_t2308 = &(g555); int64_t _i2308 = ei_705; (S8*)_t2308->b + hr_ix(_i2308, _t2308->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:192"); }))).flat_); *_t2307 = flat_710; }
{ int64_t *_t2309 = &(((*({ hrv *_t2310 = &(g555); int64_t _i2310 = ei_705; (S8*)_t2310->b + hr_ix(_i2310, _t2310->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:193"); }))).size_); *_t2309 = ((int64_t)((int64_t)((int64_t)(tz_707)) + (int64_t)mx_708)); }
{ uint8_t *_t2311 = &(((*({ hrv *_t2312 = &(g555); int64_t _i2312 = ei_705; (S8*)_t2312->b + hr_ix(_i2312, _t2312->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:194"); }))).done_); *_t2311 = ((uint8_t)2LL); }
}
static int64_t f147_pad_align(int64_t t_721) {
S1 x_722 = (*({ hrv *_t2313 = &(g550); int64_t _i2313 = t_721; (S1*)_t2313->b + hr_ix(_i2313, _t2313->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:96"); })); 
int64_t k_723 = ((int64_t)((x_722).k_)); 
if (((k_723) == (((int64_t)3LL)))) { return f148_isz(((int64_t)((x_722).s_)));
 }
if (((k_723) == (((int64_t)4LL)))) { return ((int64_t)((x_722).s_));
 }
if (((k_723) == (((int64_t)10LL)))) { if ((((x_722).c_) >= (((int32_t)0LL)))) { return ({ int64_t _r2315; if ((((x_722).c_) == (((int32_t)8LL)))) { _r2315 = ((int64_t)1LL);  } else { _r2315 = f148_isz(((int64_t)((x_722).c_)));  } _r2315; });
 }
return ((int64_t)8LL);
 }
if (((k_723) == (((int64_t)9LL)))) { return ((int64_t)8LL);
 }
return ((int64_t)1LL);
}
static int64_t f148_isz(int64_t s_724) {
return ((int64_t)((((int64_t)1LL)) << ((((int64_t)(((int64_t)((int64_t)s_724 & (int64_t)((int64_t)3LL)))))) & 63)));
}
static int64_t f149_tsize(int64_t t_727) {
S1 x_728 = (*({ hrv *_t2317 = &(g550); int64_t _i2317 = t_727; (S1*)_t2317->b + hr_ix(_i2317, _t2317->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:104"); })); 
int64_t k_729 = ((int64_t)((x_728).k_)); 
if (((k_729) == (((int64_t)2LL)))) { return ((int64_t)1LL);
 }
if (((k_729) == (((int64_t)3LL)))) { return f148_isz(((int64_t)((x_728).s_)));
 }
if (((k_729) == (((int64_t)4LL)))) { return ((int64_t)((x_728).s_));
 }
if (((k_729) == (((int64_t)10LL)))) { if ((((x_728).c_) >= (((int32_t)0LL)))) { return f148_isz(((int64_t)((x_728).c_)));
 }
return ((int64_t)8LL);
 }
if (((k_729) == (((int64_t)9LL)))) { return ((int64_t)16LL);
 }
if (((k_729) == (((int64_t)5LL)))) { (void)(f144_si_layout(((int64_t)((x_728).a_))));
return ((*({ hrv *_t2321 = &(g553); int64_t _i2321 = (x_728).a_; (S10*)_t2321->b + hr_ix(_i2321, _t2321->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:111"); }))).size_;
 }
if (((k_729) == (((int64_t)7LL)))) { (void)(f146_ei_layout(((int64_t)((x_728).a_))));
S9 v_730 = (*({ hrv *_t2323 = &(g556); int64_t _i2323 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2324 = &(g555); int64_t _i2324 = (x_728).a_; (S8*)_t2324->b + hr_ix(_i2324, _t2324->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:112"); }))).v0_)) + (int64_t)((int64_t)((x_728).c_)))); (S9*)_t2323->b + hr_ix(_i2323, _t2323->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:112"); })); 
return (v_730).size_;
 }
if (((k_729) == (((int64_t)6LL)))) { (void)(f146_ei_layout(((int64_t)((x_728).a_))));
return ((*({ hrv *_t2326 = &(g555); int64_t _i2326 = (x_728).a_; (S8*)_t2326->b + hr_ix(_i2326, _t2326->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:113"); }))).size_;
 }
if (((k_729) == (((int64_t)8LL)))) { int64_t a_731 = ((int64_t)((x_728).s_)); 
if (((a_731) == (((int64_t)1LL)))) { return ((int64_t)((int64_t)f103_max((x_728).b_, ((int64_t)1LL)) * (int64_t)f149_tsize(((int64_t)((x_728).a_)))));
 }
if (((a_731) == (((int64_t)3LL)))) { return ((int64_t)((int64_t)f148_isz(((int64_t)((x_728).c_))) + (int64_t)((int64_t)((int64_t)f103_max((x_728).b_, ((int64_t)1LL)) * (int64_t)f149_tsize(((int64_t)((x_728).a_)))))));
 }
 }
return ((int64_t)0LL);
}
static int64_t f150_cv(int64_t n_736) {
return ((int64_t)((*({ hrv *_t2332 = &(g395); int64_t _i2332 = f139_aix(n_736); (int32_t*)_t2332->b + hr_ix(_i2332, _t2332->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:49"); }))));
}
static bool f151_conv_ok(int64_t f_737, int64_t t_738, int64_t n_739) {
if (((f_737) == (t_738))) { return true;
 }
S1 a_740 = (*({ hrv *_t2334 = &(g550); int64_t _i2334 = f_737; (S1*)_t2334->b + hr_ix(_i2334, _t2334->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:169"); })); 
S1 b_741 = (*({ hrv *_t2335 = &(g550); int64_t _i2335 = t_738; (S1*)_t2335->b + hr_ix(_i2335, _t2335->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:169"); })); 
if (f152_widens(f_737, t_738)) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)2LL))) && (((a_740).k_) == (((uint8_t)10LL)))) && ((((uint16_t)((uint64_t)(a_740).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)9LL))) && ((((a_740).k_) == (((uint8_t)8LL))) || (((a_740).k_) == (((uint8_t)9LL))))) && (((a_740).a_) == ((b_741).a_)))) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)9LL))) && (((a_740).k_) == (((uint8_t)18LL)))) && ((((int64_t)((b_741).a_))) == (g563)))) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)10LL))) && (((a_740).k_) == (((uint8_t)10LL)))) && (((((uint16_t)((uint64_t)(b_741).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))) || ((((uint16_t)((uint64_t)(a_740).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))))) { if ((((a_740).a_) == ((b_741).a_))) { return true;
 }
if (((((((*({ hrv *_t2337 = &(g550); int64_t _i2337 = (b_741).a_; (S1*)_t2337->b + hr_ix(_i2337, _t2337->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:176"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t2338 = &(g550); int64_t _i2338 = (a_740).a_; (S1*)_t2338->b + hr_ix(_i2338, _t2338->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:176"); }))).k_) == (((uint8_t)7LL)))) && ((((*({ hrv *_t2339 = &(g550); int64_t _i2339 = (a_740).a_; (S1*)_t2339->b + hr_ix(_i2339, _t2339->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:176"); }))).a_) == (((*({ hrv *_t2340 = &(g550); int64_t _i2340 = (b_741).a_; (S1*)_t2340->b + hr_ix(_i2340, _t2340->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:176"); }))).a_)))) { return true;
 }
if (((((((*({ hrv *_t2341 = &(g550); int64_t _i2341 = (b_741).a_; (S1*)_t2341->b + hr_ix(_i2341, _t2341->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:177"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t2342 = &(g550); int64_t _i2342 = (a_740).a_; (S1*)_t2342->b + hr_ix(_i2342, _t2342->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:177"); }))).k_) == (((uint8_t)6LL)))) && ((((*({ hrv *_t2343 = &(g550); int64_t _i2343 = (a_740).a_; (S1*)_t2343->b + hr_ix(_i2343, _t2343->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:177"); }))).a_) == (((*({ hrv *_t2344 = &(g550); int64_t _i2344 = (b_741).a_; (S1*)_t2344->b + hr_ix(_i2344, _t2344->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:177"); }))).a_)))) { return true;
 }
 }
if (((((b_741).k_) == (((uint8_t)10LL))) && ((((int64_t)((b_741).a_))) == (f_737)))) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)6LL))) && (((a_740).k_) == (((uint8_t)7LL)))) && (((a_740).a_) == ((b_741).a_)))) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)6LL))) && (((a_740).k_) == (((uint8_t)6LL)))) && (((a_740).a_) == ((b_741).a_)))) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)8LL))) && (((a_740).k_) == (((uint8_t)8LL)))) && (((a_740).a_) == ((b_741).a_)))) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)8LL))) && (((a_740).k_) == (((uint8_t)9LL)))) && (((a_740).a_) == ((b_741).a_)))) { return true;
 }
return false;
}
static bool f152_widens(int64_t f_742, int64_t t_743) {
if (((f_742) == (t_743))) { return true;
 }
S1 a_744 = (*({ hrv *_t2345 = &(g550); int64_t _i2345 = f_742; (S1*)_t2345->b + hr_ix(_i2345, _t2345->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:115"); })); 
S1 b_745 = (*({ hrv *_t2346 = &(g550); int64_t _i2346 = t_743; (S1*)_t2346->b + hr_ix(_i2346, _t2346->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:115"); })); 
if (((((a_744).k_) == (((uint8_t)3LL))) && (((b_745).k_) == (((uint8_t)3LL))))) { bool fs_747 = f153_is_signed(f_742); 
bool ts_748 = f153_is_signed(t_743); 
if (((fs_747) == (ts_748))) { return ((f154_ibits(t_743)) > (f154_ibits(f_742)));
 }
return (((!(fs_747)) && ts_748) && ((f154_ibits(t_743)) > (f154_ibits(f_742))));
 }
if (((((a_744).k_) == (((uint8_t)3LL))) && (((b_745).k_) == (((uint8_t)4LL))))) { return true;
 }
if (((((a_744).k_) == (((uint8_t)4LL))) && (((b_745).k_) == (((uint8_t)4LL))))) { return (((b_745).s_) > ((a_744).s_));
 }
if (((((a_744).k_) == (((uint8_t)3LL))) && (((b_745).k_) == (((uint8_t)17LL))))) { return (!((((f154_ibits(f_742)) == (((int64_t)64LL))) && (!(f153_is_signed(f_742))))));
 }
if (((((a_744).k_) == (((uint8_t)17LL))) && (((b_745).k_) == (((uint8_t)3LL))))) { return ((t_743) == (g562));
 }
return false;
}
static bool f153_is_signed(int64_t t_746) {
return ((((*({ hrv *_t2355 = &(g550); int64_t _i2355 = t_746; (S1*)_t2355->b + hr_ix(_i2355, _t2355->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:60"); }))).s_) < (((uint8_t)4LL)));
}
static int64_t f154_ibits(int64_t t_749) {
return ((int64_t)((((int64_t)8LL)) << ((((int64_t)(((uint8_t)((uint64_t)((*({ hrv *_t2356 = &(g550); int64_t _i2356 = t_749; (S1*)_t2356->b + hr_ix(_i2356, _t2356->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:61"); }))).s_ & (uint64_t)((uint8_t)3LL)))))) & 63)));
}
static M78 f155_cval(int64_t n_750) {
S4 x_751 = (*({ hrv *_t2357 = &(g703); int64_t _i2357 = n_750; (S4*)_t2357->b + hr_ix(_i2357, _t2357->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:124"); })); 
int64_t k_752 = ((int64_t)((x_751).k_)); 
if (((k_752) == (((int64_t)1LL)))) { return (M78){ ((*({ hrv *_t2358 = &(g913); int64_t _i2358 = (x_751).t_; (S3*)_t2358->b + hr_ix(_i2358, _t2358->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:125"); }))).v_, ((*({ hrv *_t2359 = &(g913); int64_t _i2359 = (x_751).t_; (S3*)_t2359->b + hr_ix(_i2359, _t2359->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:125"); }))).uns_, true };
 }
if (((k_752) == (((int64_t)10LL)))) { M78 _t2360 = f155_cval(((int64_t)((x_751).a_))); int64_t v_753 = _t2360.r0; bool u_754 = _t2360.r1; bool ok_755 = _t2360.r2; 
if ((!(ok_755))) { return (M78){ ((int64_t)0LL), false, false };
 }
if (((((int64_t)((x_751).op_))) == (((int64_t)22LL)))) { return (M78){ ((int64_t)(0 - (uint64_t)(v_753))), false, true };
 }
if (((((int64_t)((x_751).op_))) == (((int64_t)48LL)))) { return (M78){ ((int64_t)~(v_753)), false, true };
 }
return (M78){ ((int64_t)0LL), false, false };
 }
if ((((k_752) == (((int64_t)8LL))) && ((f156_rk(n_750)) == (((int64_t)6LL))))) { return (M78){ (*({ hrv *_t2363 = &(g435); int64_t _i2363 = f157_rv(n_750); (int64_t*)_t2363->b + hr_ix(_i2363, _t2363->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:127"); })), false, true };
 }
if (((k_752) == (((int64_t)9LL)))) { M78 _t2365 = f155_cval(((int64_t)((x_751).a_))); int64_t a_758 = _t2365.r0; bool ua_759 = _t2365.r1; bool oa_760 = _t2365.r2; 
M78 _t2367 = f155_cval(((int64_t)((x_751).b_))); int64_t b_761 = _t2367.r0; bool ub_762 = _t2367.r1; bool ob_763 = _t2367.r2; 
if (((!(oa_760)) || (!(ob_763)))) { return (M78){ ((int64_t)0LL), false, false };
 }
int64_t o_764 = ((int64_t)((x_751).op_)); 
if (((o_764) == (((int64_t)21LL)))) { return (M78){ ((int64_t)((int64_t)a_758 + (int64_t)b_761)), false, true };
 }
if (((o_764) == (((int64_t)22LL)))) { return (M78){ ((int64_t)((int64_t)a_758 - (int64_t)b_761)), false, true };
 }
if (((o_764) == (((int64_t)23LL)))) { return (M78){ ((int64_t)((int64_t)a_758 * (int64_t)b_761)), false, true };
 }
if (((o_764) == (((int64_t)24LL)))) { if (((b_761) == (((int64_t)0LL)))) { return (M78){ ((int64_t)0LL), false, false };
 }
return (M78){ HR_SDIV(int64_t, a_758, b_761, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:133"), false, true };
 }
if (((o_764) == (((int64_t)25LL)))) { if (((b_761) == (((int64_t)0LL)))) { return (M78){ ((int64_t)0LL), false, false };
 }
return (M78){ HR_SMOD(int64_t, ((int64_t)((int64_t)HR_SMOD(int64_t, a_758, b_761, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:134") + (int64_t)b_761)), b_761, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:134"), false, true };
 }
if (((o_764) == (((int64_t)43LL)))) { return (M78){ ((int64_t)((a_758) << ((b_761) & 63))), false, true };
 }
if (((o_764) == (((int64_t)44LL)))) { return (M78){ ((int64_t)((a_758) >> ((b_761) & 63))), false, true };
 }
if (((o_764) == (((int64_t)49LL)))) { return (M78){ ((int64_t)((int64_t)a_758 & (int64_t)b_761)), false, true };
 }
if (((o_764) == (((int64_t)50LL)))) { return (M78){ ((int64_t)((int64_t)a_758 | (int64_t)b_761)), false, true };
 }
if (((o_764) == (((int64_t)51LL)))) { return (M78){ ((int64_t)((int64_t)a_758 ^ (int64_t)b_761)), false, true };
 }
 }
if ((((k_752) == (((int64_t)19LL))) || ((k_752) == (((int64_t)23LL))))) { return (M78){ ((int64_t)0LL), false, false };
 }
return (M78){ ((int64_t)0LL), false, false };
}
static int64_t f156_rk(int64_t n_756) {
return ((int64_t)((*({ hrv *_t2369 = &(g396); int64_t _i2369 = f139_aix(n_756); (uint8_t*)_t2369->b + hr_ix(_i2369, _t2369->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:44"); }))));
}
static int64_t f157_rv(int64_t n_757) {
return ((int64_t)((*({ hrv *_t2371 = &(g397); int64_t _i2371 = f139_aix(n_757); (int32_t*)_t2371->b + hr_ix(_i2371, _t2371->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:45"); }))));
}
static bool f158_int_fits(int64_t v_768, bool uns_769, int64_t t_770) {
if (((((*({ hrv *_t2373 = &(g550); int64_t _i2373 = t_770; (S1*)_t2373->b + hr_ix(_i2373, _t2373->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:108"); }))).k_) != (((uint8_t)3LL)))) { return false;
 }
if (uns_769) { return ((!(f153_is_signed(t_770))) && ((f154_ibits(t_770)) == (((int64_t)64LL))));
 }
if (((v_768) < (((int64_t)0LL)))) { return (f153_is_signed(t_770) && ((v_768) >= (f159_int_min(t_770))));
 }
return ((((uint64_t)(v_768))) <= (f160_int_max_u(t_770)));
}
static int64_t f159_int_min(int64_t t_771) {
if ((!(f153_is_signed(t_771)))) { return ((int64_t)0LL);
 }
int64_t b_772 = f154_ibits(t_771); 
return ({ int64_t _r2381; if (((b_772) == (((int64_t)64LL)))) { _r2381 = ((int64_t)((int64_t)((int64_t)(0 - (uint64_t)(((int64_t)9223372036854775807LL)))) - (int64_t)((int64_t)1LL)));  } else { _r2381 = ((int64_t)(0 - (uint64_t)(((int64_t)((((int64_t)1LL)) << ((((int64_t)((int64_t)b_772 - (int64_t)((int64_t)1LL)))) & 63))))));  } _r2381; });
}
static uint64_t f160_int_max_u(int64_t t_773) {
int64_t b_774 = f154_ibits(t_773); 
bool sg_775 = f153_is_signed(t_773); 
return ({ uint64_t _r2384; if (((b_774) == (((int64_t)64LL)))) { _r2384 = ({ uint64_t _r2385; if (sg_775) { _r2385 = ((uint64_t)9223372036854775807LL);  } else { _r2385 = ((uint64_t)18446744073709551615ULL);  } _r2385; });  } else { _r2384 = ({ uint64_t _r2386; if (sg_775) { _r2386 = ((uint64_t)((uint64_t)((uint64_t)((((uint64_t)1LL)) << ((((int64_t)((int64_t)b_774 - (int64_t)((int64_t)1LL)))) & 63))) - (uint64_t)((uint64_t)1LL)));  } else { _r2386 = ((uint64_t)((uint64_t)((uint64_t)((((uint64_t)1LL)) << ((b_774) & 63))) - (uint64_t)((uint64_t)1LL)));  } _r2386; });  } _r2384; });
}
static hrv f161_tn(int64_t t_777) {
return f126_ty_name(t_777);
}
static void f162_commit(int64_t n_778, int64_t t_779) {
if (((n_778) < (((int64_t)0LL)))) { return;
 }
S4 x_780 = (*({ hrv *_t2388 = &(g703); int64_t _i2388 = n_778; (S4*)_t2388->b + hr_ix(_i2388, _t2388->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:189"); })); 
int64_t k_781 = ((int64_t)((x_780).k_)); 
int64_t f_782 = f141_at(n_778); 
if ((((f_782) >= (((int64_t)0LL))) && (!(f163_is_pending(f_782))))) { if ((((f_782) != (t_779)) && f151_conv_ok(f_782, t_779, n_778))) { (void)(f142_set_cv(n_778, t_779));
 }
return;
 }
(void)(f138_set_t(n_778, t_779));
if (((k_781) == (((int64_t)10LL)))) { (void)(f162_commit(((int64_t)((x_780).a_)), t_779));
return;
 }
if (((k_781) == (((int64_t)9LL)))) { int64_t o_785 = ((int64_t)((x_780).op_)); 
if ((((o_785) == (((int64_t)43LL))) || ((o_785) == (((int64_t)44LL))))) { (void)(f162_commit(((int64_t)((x_780).a_)), t_779));
return;
 }
if (((f92_binprec(o_785)) >= (((int64_t)5LL)))) { (void)(f162_commit(((int64_t)((x_780).a_)), t_779));
(void)(f162_commit(((int64_t)((x_780).b_)), t_779));
 }
return;
 }
if (((k_781) == (((int64_t)19LL)))) { (void)(f162_commit(((int64_t)((x_780).b_)), t_779));
if ((((x_780).c_) >= (((int32_t)0LL)))) { (void)(f162_commit(((int64_t)((x_780).c_)), t_779));
 }
return;
 }
if (((k_781) == (((int64_t)23LL)))) { if ((((x_780).a_) >= (((int32_t)0LL)))) { (void)(f162_commit(((int64_t)((x_780).a_)), t_779));
 }
return;
 }
if (((k_781) == (((int64_t)24LL)))) { (void)(f162_commit(((int64_t)((x_780).a_)), t_779));
return;
 }
if (((k_781) == (((int64_t)20LL)))) { { int32_t _e2404 = (x_780).n_; for (int32_t _k2404 = 0; _k2404 < _e2404; _k2404++) { int32_t i_786 = (int32_t)_k2404; (void)(f162_commit(((int64_t)(((*({ hrv *_t2406 = &(g703); int64_t _i2406 = f90_kid(n_778, ((int64_t)(i_786))); (S4*)_t2406->b + hr_ix(_i2406, _t2406->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:203"); }))).b_)), t_779));
 } } _bk2403:; 
return;
 }
if (((k_781) == (((int64_t)16LL)))) { int64_t e_787 = ({ int64_t _r2408; if ((((((*({ hrv *_t2409 = &(g550); int64_t _i2409 = t_779; (S1*)_t2409->b + hr_ix(_i2409, _t2409->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:205"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2410 = &(g550); int64_t _i2410 = t_779; (S1*)_t2410->b + hr_ix(_i2410, _t2410->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:205"); }))).k_) == (((uint8_t)9LL))))) { _r2408 = ((int64_t)(((*({ hrv *_t2411 = &(g550); int64_t _i2411 = t_779; (S1*)_t2411->b + hr_ix(_i2411, _t2411->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:205"); }))).a_));  } else { _r2408 = g574;  } _r2408; }); 
if ((((x_780).a_) >= (((int32_t)0LL)))) { (void)(f140_conv(((int64_t)((x_780).a_)), e_787));
(void)(f140_conv(((int64_t)((x_780).b_)), g562));
 }
{ int32_t _e2415 = (x_780).n_; for (int32_t _k2415 = 0; _k2415 < _e2415; _k2415++) { int32_t i_788 = (int32_t)_k2415; (void)(f140_conv(f90_kid(n_778, ((int64_t)(i_788))), e_787));
 } } _bk2414:; 
if (((((*({ hrv *_t2418 = &(g550); int64_t _i2418 = t_779; (S1*)_t2418->b + hr_ix(_i2418, _t2418->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:208"); }))).k_) == (((uint8_t)9LL)))) { (void)(f138_set_t(n_778, f123_t_arr(e_787, ((int64_t)1LL), f103_max(((int64_t)((x_780).n_)), ((int64_t)1LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f142_set_cv(n_778, t_779));
 }
return;
 }
}
static bool f163_is_pending(int64_t t_783) {
int64_t k_784 = ((int64_t)(((*({ hrv *_t2423 = &(g550); int64_t _i2423 = t_783; (S1*)_t2423->b + hr_ix(_i2423, _t2423->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:106"); }))).k_)); 
return ((((((k_784) == (((int64_t)12LL))) || ((k_784) == (((int64_t)13LL)))) || ((k_784) == (((int64_t)18LL)))) || ((k_784) == (((int64_t)19LL)))) || ((k_784) == (((int64_t)11LL))));
}
static bool f164_is_byte_arr(int64_t t_789) {
uint8_t k_790 = ((*({ hrv *_t2424 = &(g550); int64_t _i2424 = t_789; (S1*)_t2424->b + hr_ix(_i2424, _t2424->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:68"); }))).k_; 
return ((((k_790) == (((uint8_t)8LL))) || ((k_790) == (((uint8_t)9LL)))) && ((((int64_t)(((*({ hrv *_t2425 = &(g550); int64_t _i2425 = t_789; (S1*)_t2425->b + hr_ix(_i2425, _t2425->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:68"); }))).a_))) == (g563)));
}
static bool f165_is_opt(int64_t t_792) {
return (((((*({ hrv *_t2426 = &(g550); int64_t _i2426 = t_792; (S1*)_t2426->b + hr_ix(_i2426, _t2426->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:66"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2427 = &(g550); int64_t _i2427 = t_792; (S1*)_t2427->b + hr_ix(_i2427, _t2427->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:66"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))));
}
static int64_t f166_ck_id(int64_t n_793, int64_t want_794) {
int64_t name_795 = ((int64_t)(((*({ hrv *_t2428 = &(g703); int64_t _i2428 = n_793; (S4*)_t2428->b + hr_ix(_i2428, _t2428->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:338"); }))).s_)); 
int64_t v_803 = f167_find_lv(name_795); 
if (((v_803) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_793, ((int64_t)1LL), v_803));
(void)(f171_note_cap(v_803));
return f138_set_t(n_793, ((int64_t)(((*({ hrv *_t2433 = &(g388); int64_t _i2433 = v_803; (S12*)_t2433->b + hr_ix(_i2433, _t2433->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:340"); }))).ty_)));
 }
int64_t ns_814 = f110_ns_of(n_793); 
int64_t d_815 = f116_lookup_q(name_795, ns_814, ((int64_t)5LL)); 
if (((d_815) >= (((int64_t)0LL)))) { int64_t g_816 = ((int64_t)(((*({ hrv *_t2436 = &(g488); int64_t _i2436 = d_815; (S5*)_t2436->b + hr_ix(_i2436, _t2436->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:344"); }))).node_)); 
int64_t ci_829 = f173_const_of(d_815); 
if (((ci_829) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_793, ((int64_t)6LL), ci_829));
return f138_set_t(n_793, g570);
 }
(void)(f170_set_r(n_793, ((int64_t)2LL), d_815));
return f138_set_t(n_793, f109_global_type(d_815));
 }
d_815 = f116_lookup_q(name_795, ns_814, ((int64_t)4LL));
if (((d_815) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_793, ((int64_t)3LL), d_815));
(void)(f175_set_x(n_793, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_793, g577);
 }
hrv m_832 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o2448 = &(m_832); hr_fs(_o2448, hr_str("unknown name: ", 14)); hr_fs(_o2448, f10_nm(name_795)); }));
(void)(f108_cerr(n_793, hr_sl(m_832)));
return f138_set_t(n_793, g574);
}
static int64_t f167_find_lv(int64_t name_796) {
int64_t i_797 = ((int64_t)((int64_t)(g389).n - (int64_t)((int64_t)1LL))); 
while (((i_797) >= (((int64_t)0LL)))) { int64_t v_798 = ((int64_t)((*({ hrv *_t2453 = &(g389); int64_t _i2453 = i_797; (int32_t*)_t2453->b + hr_ix(_i2453, _t2453->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:60"); })))); 
if ((((((int64_t)(((*({ hrv *_t2454 = &(g388); int64_t _i2454 = v_798; (S12*)_t2454->b + hr_ix(_i2454, _t2454->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:60"); }))).name_))) == (name_796)) && f168_visible(((int64_t)(((*({ hrv *_t2456 = &(g388); int64_t _i2456 = v_798; (S12*)_t2456->b + hr_ix(_i2456, _t2456->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:60"); }))).own_))))) { return v_798;
 }
i_797--;
 } _bk2452:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f168_visible(int64_t own_799) {
return f169_visible_in(own_799, g400);
}
static bool f169_visible_in(int64_t own_800, int64_t cur_801) {
int64_t i_802 = cur_801; 
while (((i_802) >= (((int64_t)0LL)))) { if (((i_802) == (own_800))) { return true;
 }
i_802 = ((int64_t)(((*({ hrv *_t2459 = &(g387); int64_t _i2459 = i_802; (S6*)_t2459->b + hr_ix(_i2459, _t2459->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:56"); }))).par_));
 } _bk2458:; 
return false;
}
static void f170_set_r(int64_t n_804, int64_t k_805, int64_t v_806) {
int64_t i_807 = f139_aix(n_804); 
{ uint8_t *_t2461 = &((*({ hrv *_t2462 = &(g396); int64_t _i2462 = i_807; (uint8_t*)_t2462->b + hr_ix(_i2462, _t2462->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:43"); }))); *_t2461 = ((uint8_t)(k_805)); }
{ int32_t *_t2463 = &((*({ hrv *_t2464 = &(g397); int64_t _i2464 = i_807; (int32_t*)_t2464->b + hr_ix(_i2464, _t2464->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:43"); }))); *_t2463 = ((int32_t)(v_806)); }
}
static void f171_note_cap(int64_t v_808) {
int64_t own_809 = ((int64_t)(((*({ hrv *_t2465 = &(g388); int64_t _i2465 = v_808; (S12*)_t2465->b + hr_ix(_i2465, _t2465->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:70"); }))).own_)); 
int64_t a_810 = g400; 
while ((((a_810) >= (((int64_t)0LL))) && ((a_810) != (own_809)))) { (void)(f172_add_cap_one(((int64_t)(((*({ hrv *_t2468 = &(g387); int64_t _i2468 = a_810; (S6*)_t2468->b + hr_ix(_i2468, _t2468->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:73"); }))).cfn_)), v_808));
a_810 = ((int64_t)(((*({ hrv *_t2469 = &(g387); int64_t _i2469 = a_810; (S6*)_t2469->b + hr_ix(_i2469, _t2469->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:74"); }))).par_));
 } _bk2466:; 
}
static bool f172_add_cap_one(int64_t cf_811, int64_t v_812) {
if ((((cf_811) < (((int64_t)0LL))) || ((cf_811) == (((int64_t)(((*({ hrv *_t2470 = &(g388); int64_t _i2470 = v_812; (S12*)_t2470->b + hr_ix(_i2470, _t2470->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:64"); }))).cfn_)))))) { return false;
 }
{ hrv *_v2472 = &(g391); for (int64_t _k2472 = 0; _k2472 < _v2472->n; _k2472++) { S13 x_813 = ((S13*)_v2472->b)[_k2472]; if ((((((int64_t)((x_813).inst_))) == (cf_811)) && ((((int64_t)((x_813).lv_))) == (v_812)))) { return false;
 }
 } } _bk2471:; 
(void)(({ hrv *_v2473 = &(g391); S13 _x2473 = ((S13){ .inst_ = ((int32_t)(cf_811)), .lv_ = ((int32_t)(v_812)), }); S13 *_p2473 = (S13*)hr_grow(_v2473, 1, sizeof _x2473); *_p2473 = _x2473; _p2473; }));
return true;
}
static int64_t f173_const_of(int64_t d_817) {
{ hrv *_v2475 = &(g436); for (int64_t _k2475 = 0; _k2475 < _v2475->n; _k2475++) { int32_t c_818 = ((int32_t*)_v2475->b)[_k2475]; int64_t i_819 = (int64_t)_k2475; if (((((int64_t)(c_818))) == (d_817))) { return i_819;
 }
 } } _bk2474:; 
int64_t g_820 = ((int64_t)(((*({ hrv *_t2476 = &(g488); int64_t _i2476 = d_817; (S5*)_t2476->b + hr_ix(_i2476, _t2476->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:359"); }))).node_)); 
S4 x_821 = (*({ hrv *_t2477 = &(g703); int64_t _i2477 = g_820; (S4*)_t2477->b + hr_ix(_i2477, _t2477->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:360"); })); 
if (((((((uint16_t)((uint64_t)(x_821).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || (((x_821).a_) >= (((int32_t)0LL)))) || (((x_821).b_) < (((int32_t)0LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t iv_822 = f90_kid(((int64_t)((x_821).b_)), ((int64_t)0LL)); 
M56 _t2479 = f120_ceval(iv_822, f110_ns_of(g_820)); int64_t v_823 = _t2479.r0; bool ok_824 = _t2479.r1; 
if ((!(ok_824))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if ((!(f174_all_int(iv_822)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
(void)(({ hrv *_v2483 = &(g436); int32_t _x2483 = ((int32_t)(d_817)); int32_t *_p2483 = (int32_t*)hr_grow(_v2483, 1, sizeof _x2483); *_p2483 = _x2483; _p2483; }));
(void)(({ hrv *_v2484 = &(g435); int64_t _x2484 = v_823; int64_t *_p2484 = (int64_t*)hr_grow(_v2484, 1, sizeof _x2484); *_p2484 = _x2484; _p2484; }));
return ((int64_t)((int64_t)(g436).n - (int64_t)((int64_t)1LL)));
}
static bool f174_all_int(int64_t n_825) {
S4 x_826 = (*({ hrv *_t2485 = &(g703); int64_t _i2485 = n_825; (S4*)_t2485->b + hr_ix(_i2485, _t2485->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:370"); })); 
int64_t k_827 = ((int64_t)((x_826).k_)); 
if (((k_827) == (((int64_t)1LL)))) { return true;
 }
if (((k_827) == (((int64_t)10LL)))) { return f174_all_int(((int64_t)((x_826).a_)));
 }
if (((k_827) == (((int64_t)9LL)))) { return (f174_all_int(((int64_t)((x_826).a_))) && f174_all_int(((int64_t)((x_826).b_))));
 }
if (((k_827) == (((int64_t)8LL)))) { int64_t d_828 = f116_lookup_q(((int64_t)((x_826).s_)), f110_ns_of(n_825), ((int64_t)5LL)); 
if (((d_828) < (((int64_t)0LL)))) { return false;
 }
return ((f173_const_of(d_828)) >= (((int64_t)0LL)));
 }
if (((k_827) == (((int64_t)14LL)))) { return hr_streq(f10_nm(((int64_t)((x_826).s_))), hr_str("len", 3));
 }
return false;
}
static void f175_set_x(int64_t n_830, int64_t v_831) {
{ int32_t *_t2493 = &((*({ hrv *_t2494 = &(g398); int64_t _i2494 = f139_aix(n_830); (int32_t*)_t2494->b + hr_ix(_i2494, _t2494->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:46"); }))); *_t2493 = ((int32_t)(v_831)); }
}
static int64_t f176_ck_bin(int64_t n_833, int64_t want_834) {
S4 x_835 = (*({ hrv *_t2496 = &(g703); int64_t _i2496 = n_833; (S4*)_t2496->b + hr_ix(_i2496, _t2496->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:275"); })); 
int64_t o_836 = ((int64_t)((x_835).op_)); 
int64_t a_837 = ((int64_t)((x_835).a_)); 
int64_t b_838 = ((int64_t)((x_835).b_)); 
if (((o_836) == (((int64_t)52LL)))) { (void)(f137_ck(a_837, g558));
(void)(f140_conv(a_837, g558));
int64_t nm0_839 = (g390).n; 
(void)(f177_narrow_push(a_837));
(void)(f137_ck(b_838, g558));
(void)(f140_conv(b_838, g558));
(void)(f178_narrow_pop(nm0_839));
return f138_set_t(n_833, g558);
 }
if (((o_836) == (((int64_t)53LL)))) { (void)(f137_ck(a_837, g558));
(void)(f140_conv(a_837, g558));
(void)(f137_ck(b_838, g558));
(void)(f140_conv(b_838, g558));
return f138_set_t(n_833, g558);
 }
if ((((o_836) == (((int64_t)19LL))) || ((o_836) == (((int64_t)20LL))))) { (void)(f137_ck(a_837, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
(void)(f137_ck(b_838, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_833, g558);
 }
bool cmp_848 = (((((((o_836) == (((int64_t)37LL))) || ((o_836) == (((int64_t)38LL)))) || ((o_836) == (((int64_t)39LL)))) || ((o_836) == (((int64_t)40LL)))) || ((o_836) == (((int64_t)41LL)))) || ((o_836) == (((int64_t)42LL)))); 
int64_t w_849 = ({ int64_t _r2512; if (cmp_848) { _r2512 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2512 = want_834;  } _r2512; }); 
int64_t ta_850 = f137_ck(a_837, w_849); 
int64_t tb_852 = f137_ck(b_838, ({ int64_t _r2515; if (f163_is_pending(ta_850)) { _r2515 = w_849;  } else { _r2515 = f179_deref(ta_850);  } _r2515; })); 
if ((((o_836) == (((int64_t)43LL))) || ((o_836) == (((int64_t)44LL))))) { if (((((*({ hrv *_t2518 = &(g550); int64_t _i2518 = tb_852; (S1*)_t2518->b + hr_ix(_i2518, _t2518->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:291"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(b_838, g562));
 } else { if (((((*({ hrv *_t2520 = &(g550); int64_t _i2520 = f179_deref(tb_852); (S1*)_t2520->b + hr_ix(_i2520, _t2520->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:291"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(b_838, hr_str("shift count must be an integer", 30)));
 }
 }
int64_t da_853 = f179_deref(ta_850); 
if (((((*({ hrv *_t2524 = &(g550); int64_t _i2524 = da_853; (S1*)_t2524->b + hr_ix(_i2524, _t2524->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:293"); }))).k_) == (((uint8_t)12LL)))) { if ((((want_834) >= (((int64_t)0LL))) && ((((*({ hrv *_t2525 = &(g550); int64_t _i2525 = want_834; (S1*)_t2525->b + hr_ix(_i2525, _t2525->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:293"); }))).k_) == (((uint8_t)3LL))))) { (void)(f140_conv(a_837, want_834));
return f138_set_t(n_833, want_834);
 }
return f138_set_t(n_833, g570);
 }
if (((((*({ hrv *_t2529 = &(g550); int64_t _i2529 = da_853; (S1*)_t2529->b + hr_ix(_i2529, _t2529->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:294"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(a_837, hr_str("shift of a non-integer", 22)));
 }
if (((ta_850) != (da_853))) { (void)(f142_set_cv(a_837, da_853));
 }
return f138_set_t(n_833, da_853);
 }
int64_t da_854 = f179_deref(ta_850); 
int64_t db_855 = f179_deref(tb_852); 
int64_t la_864 = f180_leaf_kind(da_854); 
int64_t lb_865 = f180_leaf_kind(db_855); 
if (((((la_864) >= (((int64_t)4LL))) || ((lb_865) >= (((int64_t)4LL)))) && (!(cmp_848)))) { if (((da_854) == (db_855))) { if (((ta_850) != (da_854))) { (void)(f142_set_cv(a_837, da_854));
 }
if (((tb_852) != (db_855))) { (void)(f142_set_cv(b_838, db_855));
 }
return f138_set_t(n_833, da_854);
 }
if ((((la_864) >= (((int64_t)4LL))) && (((o_836) == (((int64_t)23LL))) || ((o_836) == (((int64_t)24LL)))))) { (void)(f140_conv(b_838, f181_leaf_type(da_854)));
if (((ta_850) != (da_854))) { (void)(f142_set_cv(a_837, da_854));
 }
return f138_set_t(n_833, da_854);
 }
if ((((lb_865) >= (((int64_t)4LL))) && ((o_836) == (((int64_t)23LL))))) { (void)(f140_conv(a_837, f181_leaf_type(db_855)));
if (((tb_852) != (db_855))) { (void)(f142_set_cv(b_838, db_855));
 }
return f138_set_t(n_833, db_855);
 }
if ((((lb_865) >= (((int64_t)4LL))) && ((o_836) == (((int64_t)24LL))))) { (void)(f140_conv(a_837, f181_leaf_type(db_855)));
if (((tb_852) != (db_855))) { (void)(f142_set_cv(b_838, db_855));
 }
return f138_set_t(n_833, db_855);
 }
 }
if ((((((cmp_848 && (((((*({ hrv *_t2552 = &(g550); int64_t _i2552 = da_854; (S1*)_t2552->b + hr_ix(_i2552, _t2552->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:306"); }))).k_) == (((uint8_t)3LL))) && ((((*({ hrv *_t2553 = &(g550); int64_t _i2553 = db_855; (S1*)_t2553->b + hr_ix(_i2553, _t2553->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:306"); }))).k_) == (((uint8_t)3LL))))) && ((f153_is_signed(da_854)) != (f153_is_signed(db_855)))) && (((f154_ibits(da_854)) == (((int64_t)64LL))) || ((f154_ibits(db_855)) == (((int64_t)64LL))))) && (!(f152_widens(da_854, db_855)))) && (!(f152_widens(db_855, da_854))))) { (void)(f175_set_x(n_833, ((int64_t)1LL)));
return f138_set_t(n_833, g558);
 }
if ((cmp_848 && (((o_836) == (((int64_t)37LL))) || ((o_836) == (((int64_t)38LL)))))) { int64_t ka_873 = ((int64_t)(((*({ hrv *_t2562 = &(g550); int64_t _i2562 = da_854; (S1*)_t2562->b + hr_ix(_i2562, _t2562->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:311"); }))).k_)); 
int64_t kb_874 = ((int64_t)(((*({ hrv *_t2563 = &(g550); int64_t _i2563 = db_855; (S1*)_t2563->b + hr_ix(_i2563, _t2563->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:311"); }))).k_)); 
if ((((ka_873) == (((int64_t)11LL))) || ((kb_874) == (((int64_t)11LL))))) { if ((((ka_873) == (((int64_t)11LL))) && ((kb_874) == (((int64_t)11LL))))) { return f138_set_t(n_833, g558);
 }
if (((ka_873) == (((int64_t)11LL)))) { (void)(f138_set_t(a_837, tb_852));
 } else { (void)(f138_set_t(b_838, ta_850));
 }
return f138_set_t(n_833, g558);
 }
if (((((ka_873) == (((int64_t)18LL))) || ((kb_874) == (((int64_t)18LL)))) || (f164_is_byte_arr(da_854) && f164_is_byte_arr(db_855)))) { if (((ka_873) == (((int64_t)18LL)))) { (void)(f138_set_t(a_837, g575));
 }
if (((kb_874) == (((int64_t)18LL)))) { (void)(f138_set_t(b_838, g575));
 }
(void)(f175_set_x(n_833, ((int64_t)2LL)));
return f138_set_t(n_833, g558);
 }
if ((((((((ka_873) == (((int64_t)5LL))) || ((ka_873) == (((int64_t)8LL)))) || ((ka_873) == (((int64_t)6LL)))) || ((ka_873) == (((int64_t)7LL)))) || ((ka_873) == (((int64_t)9LL)))) && ((da_854) == (db_855)))) { (void)(f175_set_x(n_833, ((int64_t)3LL)));
return f138_set_t(n_833, g558);
 }
if (((((ka_873) == (((int64_t)6LL))) && ((kb_874) == (((int64_t)7LL)))) || (((ka_873) == (((int64_t)7LL))) && ((kb_874) == (((int64_t)6LL)))))) { (void)(f175_set_x(n_833, ((int64_t)3LL)));
return f138_set_t(n_833, g558);
 }
if ((((ka_873) == (((int64_t)19LL))) || ((kb_874) == (((int64_t)19LL))))) { if (((ka_873) == (((int64_t)19LL)))) { (void)(f140_conv(a_837, db_855));
 } else { (void)(f140_conv(b_838, da_854));
 }
(void)(f175_set_x(n_833, ((int64_t)3LL)));
return f138_set_t(n_833, g558);
 }
 }
int64_t u_886 = f182_unify(n_833, a_837, b_838); 
if (cmp_848) { if (((((*({ hrv *_t2583 = &(g550); int64_t _i2583 = u_886; (S1*)_t2583->b + hr_ix(_i2583, _t2583->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:319"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(a_837, g562));
(void)(f140_conv(b_838, g562));
 }
if (((((*({ hrv *_t2586 = &(g550); int64_t _i2586 = u_886; (S1*)_t2586->b + hr_ix(_i2586, _t2586->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:319"); }))).k_) == (((uint8_t)13LL)))) { (void)(f140_conv(a_837, g568));
(void)(f140_conv(b_838, g568));
 }
return f138_set_t(n_833, g558);
 }
int64_t uk_887 = ((int64_t)(((*({ hrv *_t2590 = &(g550); int64_t _i2590 = u_886; (S1*)_t2590->b + hr_ix(_i2590, _t2590->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:320"); }))).k_)); 
if (((((((((o_836) == (((int64_t)49LL))) || ((o_836) == (((int64_t)50LL)))) || ((o_836) == (((int64_t)51LL)))) && ((uk_887) != (((int64_t)3LL)))) && ((uk_887) != (((int64_t)12LL)))) && ((uk_887) != (((int64_t)2LL)))) && ((uk_887) != (((int64_t)0LL))))) { (void)(f108_cerr(n_833, hr_str("bitwise operator on a non-integer", 33)));
 }
if ((((((uk_887) == (((int64_t)2LL))) && ((o_836) != (((int64_t)49LL)))) && ((o_836) != (((int64_t)50LL)))) && ((o_836) != (((int64_t)51LL))))) { (void)(f108_cerr(n_833, hr_str("arithmetic on bool", 18)));
 }
return f138_set_t(n_833, u_886);
}
static void f177_narrow_push(int64_t c_840) {
if (((c_840) < (((int64_t)0LL)))) { return;
 }
S4 x_841 = (*({ hrv *_t2594 = &(g703); int64_t _i2594 = c_840; (S4*)_t2594->b + hr_ix(_i2594, _t2594->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:84"); })); 
int64_t k_842 = ((int64_t)((x_841).k_)); 
if ((((k_842) == (((int64_t)8LL))) && ((f156_rk(c_840)) == (((int64_t)1LL))))) { int64_t v_843 = f157_rv(c_840); 
int64_t t_844 = ((int64_t)(((*({ hrv *_t2597 = &(g388); int64_t _i2597 = v_843; (S12*)_t2597->b + hr_ix(_i2597, _t2597->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:87"); }))).ty_)); 
if ((((((*({ hrv *_t2598 = &(g550); int64_t _i2598 = t_844; (S1*)_t2598->b + hr_ix(_i2598, _t2598->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:88"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2599 = &(g550); int64_t _i2599 = t_844; (S1*)_t2599->b + hr_ix(_i2599, _t2599->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:88"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(({ hrv *_v2600 = &(g390); int32_t _x2600 = ((int32_t)(v_843)); int32_t *_p2600 = (int32_t*)hr_grow(_v2600, 1, sizeof _x2600); *_p2600 = _x2600; _p2600; }));
(void)(({ hrv *_v2601 = &(g390); int32_t _x2601 = ((int32_t)(t_844)); int32_t *_p2601 = (int32_t*)hr_grow(_v2601, 1, sizeof _x2601); *_p2601 = _x2601; _p2601; }));
{ int32_t *_t2602 = &(((*({ hrv *_t2603 = &(g388); int64_t _i2603 = v_843; (S12*)_t2603->b + hr_ix(_i2603, _t2603->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:90"); }))).ty_); *_t2602 = ((int32_t)(f119_t_ref(((int64_t)(((*({ hrv *_t2605 = &(g550); int64_t _i2605 = t_844; (S1*)_t2605->b + hr_ix(_i2605, _t2605->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:90"); }))).a_)), ((int64_t)0LL)))); }
 }
return;
 }
if ((((k_842) == (((int64_t)9LL))) && ((((int64_t)((x_841).op_))) == (((int64_t)52LL))))) { (void)(f177_narrow_push(((int64_t)((x_841).a_))));
(void)(f177_narrow_push(((int64_t)((x_841).b_))));
 }
}
static void f178_narrow_pop(int64_t m_845) {
while ((((g390).n) > (m_845))) { int32_t old_t_846 = ({ hrv *_v2609 = &(g390); if (!_v2609->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:101"); ((int32_t*)_v2609->b)[--_v2609->n]; }); 
int64_t v_847 = ((int64_t)(({ hrv *_v2610 = &(g390); if (!_v2610->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:102"); ((int32_t*)_v2610->b)[--_v2610->n]; }))); 
{ int32_t *_t2611 = &(((*({ hrv *_t2612 = &(g388); int64_t _i2612 = v_847; (S12*)_t2612->b + hr_ix(_i2612, _t2612->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:103"); }))).ty_); *_t2611 = old_t_846; }
 } _bk2608:; 
}
static int64_t f179_deref(int64_t t_851) {
return ({ int64_t _r2613; if ((((((*({ hrv *_t2614 = &(g550); int64_t _i2614 = t_851; (S1*)_t2614->b + hr_ix(_i2614, _t2614->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:67"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2615 = &(g550); int64_t _i2615 = t_851; (S1*)_t2615->b + hr_ix(_i2615, _t2615->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:67"); }))).c_) < (((int32_t)0LL))))) { _r2613 = ((int64_t)(((*({ hrv *_t2616 = &(g550); int64_t _i2616 = t_851; (S1*)_t2616->b + hr_ix(_i2616, _t2616->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:67"); }))).a_));  } else { _r2613 = t_851;  } _r2613; });
}
static int64_t f180_leaf_kind(int64_t t_856) {
S1 x_857 = (*({ hrv *_t2617 = &(g550); int64_t _i2617 = t_856; (S1*)_t2617->b + hr_ix(_i2617, _t2617->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:261"); })); 
int64_t k_858 = ((int64_t)((x_857).k_)); 
if (((k_858) == (((int64_t)3LL)))) { return ((int64_t)1LL);
 }
if (((k_858) == (((int64_t)4LL)))) { return ((int64_t)2LL);
 }
if (((k_858) == (((int64_t)5LL)))) { int64_t r_859 = ((int64_t)0LL); 
{ int32_t _e2619 = ((*({ hrv *_t2620 = &(g553); int64_t _i2620 = (x_857).a_; (S10*)_t2620->b + hr_ix(_i2620, _t2620->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:263"); }))).fnum_; for (int32_t _k2619 = 0; _k2619 < _e2619; _k2619++) { int32_t i_860 = (int32_t)_k2619; S11 f_861 = (*({ hrv *_t2621 = &(g554); int64_t _i2621 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2622 = &(g553); int64_t _i2622 = (x_857).a_; (S10*)_t2622->b + hr_ix(_i2622, _t2622->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:263"); }))).f0_)) + (int64_t)((int64_t)(i_860)))); (S11*)_t2621->b + hr_ix(_i2621, _t2621->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:263"); })); 
if ((((f_861).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t l_862 = f180_leaf_kind(((int64_t)((f_861).ty_))); 
if ((((l_862) == (((int64_t)0LL))) || (((r_859) != (((int64_t)0LL))) && ((r_859) != (l_862))))) { return ((int64_t)0LL);
 }
r_859 = l_862;
 } } _bk2618:; 
return ((int64_t)((int64_t)r_859 + (int64_t)((int64_t)4LL)));
 }
if ((((k_858) == (((int64_t)8LL))) && (((x_857).s_) == (((uint8_t)(((uint8_t)1LL))))))) { int64_t l_863 = f180_leaf_kind(((int64_t)((x_857).a_))); 
if (((l_863) == (((int64_t)0LL)))) { return ((int64_t)0LL);
 }
return ((int64_t)((int64_t)((int64_t)((int64_t)l_863 & (int64_t)((int64_t)3LL))) + (int64_t)((int64_t)4LL)));
 }
return ((int64_t)0LL);
}
static int64_t f181_leaf_type(int64_t t_866) {
S1 x_867 = (*({ hrv *_t2625 = &(g550); int64_t _i2625 = t_866; (S1*)_t2625->b + hr_ix(_i2625, _t2625->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:268"); })); 
int64_t k_868 = ((int64_t)((x_867).k_)); 
if ((((k_868) == (((int64_t)3LL))) || ((k_868) == (((int64_t)4LL))))) { return t_866;
 }
if (((k_868) == (((int64_t)5LL)))) { int64_t r_869 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e2627 = ((*({ hrv *_t2628 = &(g553); int64_t _i2628 = (x_867).a_; (S10*)_t2628->b + hr_ix(_i2628, _t2628->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:270"); }))).fnum_; for (int32_t _k2627 = 0; _k2627 < _e2627; _k2627++) { int32_t i_870 = (int32_t)_k2627; S11 f_871 = (*({ hrv *_t2629 = &(g554); int64_t _i2629 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2630 = &(g553); int64_t _i2630 = (x_867).a_; (S10*)_t2630->b + hr_ix(_i2630, _t2630->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:270"); }))).f0_)) + (int64_t)((int64_t)(i_870)))); (S11*)_t2629->b + hr_ix(_i2629, _t2629->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:270"); })); 
if ((((f_871).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t l_872 = f181_leaf_type(((int64_t)((f_871).ty_))); 
if ((((l_872) < (((int64_t)0LL))) || (((r_869) >= (((int64_t)0LL))) && ((r_869) != (l_872))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
r_869 = l_872;
 } } _bk2626:; 
return r_869;
 }
if ((((k_868) == (((int64_t)8LL))) && (((x_867).s_) == (((uint8_t)(((uint8_t)1LL))))))) { return f181_leaf_type(((int64_t)((x_867).a_)));
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f182_unify(int64_t n_875, int64_t a_876, int64_t b_877) {
int64_t ta_878 = f141_at(a_876); 
int64_t tb_879 = f141_at(b_877); 
if ((((ta_878) < (((int64_t)0LL))) || ((tb_879) < (((int64_t)0LL))))) { return g574;
 }
int64_t da_880 = f179_deref(ta_878); 
int64_t db_881 = f179_deref(tb_879); 
int64_t ka_882 = ((int64_t)(((*({ hrv *_t2637 = &(g550); int64_t _i2637 = da_880; (S1*)_t2637->b + hr_ix(_i2637, _t2637->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:237"); }))).k_)); 
int64_t kb_883 = ((int64_t)(((*({ hrv *_t2638 = &(g550); int64_t _i2638 = db_881; (S1*)_t2638->b + hr_ix(_i2638, _t2638->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:237"); }))).k_)); 
if ((((ka_882) == (((int64_t)0LL))) || ((kb_883) == (((int64_t)0LL))))) { return g574;
 }
if ((((ka_882) == (((int64_t)12LL))) && ((kb_883) == (((int64_t)12LL))))) { return g570;
 }
if (((((ka_882) == (((int64_t)12LL))) || ((ka_882) == (((int64_t)13LL)))) && ((kb_883) == (((int64_t)13LL))))) { return g571;
 }
if ((((ka_882) == (((int64_t)13LL))) && ((kb_883) == (((int64_t)12LL))))) { return g571;
 }
if ((((ka_882) == (((int64_t)18LL))) && ((kb_883) == (((int64_t)18LL))))) { (void)(f138_set_t(a_876, g575));
(void)(f138_set_t(b_877, g575));
return g575;
 }
if (((((ka_882) == (((int64_t)18LL))) || ((ka_882) == (((int64_t)19LL)))) || ((ka_882) == (((int64_t)11LL))))) { (void)(f140_conv(a_876, db_881));
return db_881;
 }
if (((((kb_883) == (((int64_t)18LL))) || ((kb_883) == (((int64_t)19LL)))) || ((kb_883) == (((int64_t)11LL))))) { (void)(f140_conv(b_877, da_880));
return da_880;
 }
if (((ka_882) == (((int64_t)12LL)))) { (void)(f140_conv(a_876, db_881));
return db_881;
 }
if (((kb_883) == (((int64_t)12LL)))) { (void)(f140_conv(b_877, da_880));
return da_880;
 }
if (((ka_882) == (((int64_t)13LL)))) { if (((kb_883) == (((int64_t)4LL)))) { (void)(f140_conv(a_876, db_881));
return db_881;
 }
if (((kb_883) == (((int64_t)3LL)))) { return g571;
 }
 }
if (((kb_883) == (((int64_t)13LL)))) { if (((ka_882) == (((int64_t)4LL)))) { (void)(f140_conv(b_877, da_880));
return da_880;
 }
if (((ka_882) == (((int64_t)3LL)))) { return g571;
 }
 }
if (((da_880) == (db_881))) { if (((ta_878) != (da_880))) { (void)(f142_set_cv(a_876, da_880));
 }
if (((tb_879) != (db_881))) { (void)(f142_set_cv(b_877, db_881));
 }
return da_880;
 }
if ((f152_widens(da_880, db_881) && (!((((ka_882) == (((int64_t)4LL))) && ((kb_883) == (((int64_t)3LL)))))))) { (void)(f142_set_cv(a_876, db_881));
if (((tb_879) != (db_881))) { (void)(f142_set_cv(b_877, db_881));
 }
return db_881;
 }
if ((f152_widens(db_881, da_880) && (!((((kb_883) == (((int64_t)4LL))) && ((ka_882) == (((int64_t)3LL)))))))) { (void)(f142_set_cv(b_877, da_880));
if (((ta_878) != (da_880))) { (void)(f142_set_cv(a_876, da_880));
 }
return da_880;
 }
if ((((ka_882) == (((int64_t)3LL))) && ((kb_883) == (((int64_t)4LL))))) { (void)(f142_set_cv(a_876, db_881));
return db_881;
 }
if ((((kb_883) == (((int64_t)3LL))) && ((ka_882) == (((int64_t)4LL))))) { (void)(f142_set_cv(b_877, da_880));
return da_880;
 }
if (((((ka_882) == (((int64_t)7LL))) && ((kb_883) == (((int64_t)7LL)))) && ((((*({ hrv *_t2657 = &(g550); int64_t _i2657 = da_880; (S1*)_t2657->b + hr_ix(_i2657, _t2657->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:254"); }))).a_) == (((*({ hrv *_t2658 = &(g550); int64_t _i2658 = db_881; (S1*)_t2658->b + hr_ix(_i2658, _t2658->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:254"); }))).a_)))) { int64_t et_884 = f136_t_enum(((int64_t)(((*({ hrv *_t2660 = &(g550); int64_t _i2660 = da_880; (S1*)_t2660->b + hr_ix(_i2660, _t2660->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:254"); }))).a_)), false); 
(void)(f142_set_cv(a_876, et_884));
(void)(f142_set_cv(b_877, et_884));
return et_884;
 }
if (((((ka_882) == (((int64_t)6LL))) && ((kb_883) == (((int64_t)7LL)))) && ((((*({ hrv *_t2663 = &(g550); int64_t _i2663 = da_880; (S1*)_t2663->b + hr_ix(_i2663, _t2663->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:255"); }))).a_) == (((*({ hrv *_t2664 = &(g550); int64_t _i2664 = db_881; (S1*)_t2664->b + hr_ix(_i2664, _t2664->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:255"); }))).a_)))) { (void)(f142_set_cv(b_877, da_880));
if (((ta_878) != (da_880))) { (void)(f142_set_cv(a_876, da_880));
 }
return da_880;
 }
if (((((kb_883) == (((int64_t)6LL))) && ((ka_882) == (((int64_t)7LL)))) && ((((*({ hrv *_t2667 = &(g550); int64_t _i2667 = da_880; (S1*)_t2667->b + hr_ix(_i2667, _t2667->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:256"); }))).a_) == (((*({ hrv *_t2668 = &(g550); int64_t _i2668 = db_881; (S1*)_t2668->b + hr_ix(_i2668, _t2668->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:256"); }))).a_)))) { (void)(f142_set_cv(a_876, db_881));
if (((tb_879) != (db_881))) { (void)(f142_set_cv(b_877, db_881));
 }
return db_881;
 }
hrv m_885 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2673 __attribute__((cleanup(hr_rdrop))) = {0}; hrv _t2675 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2672 = &(m_885); hr_fs(_o2672, hr_str("operands of types ", 18)); hr_fs(_o2672, hr_sl(*hr_tmp(&_t2673, f161_tn(da_880)))); hr_fs(_o2672, hr_str(" and ", 5)); hr_fs(_o2672, hr_sl(*hr_tmp(&_t2675, f161_tn(db_881)))); hr_fs(_o2672, hr_str(" need a cast to a common type", 29)); }));
}
(void)(f108_cerr(n_875, hr_sl(m_885)));
return g574;
}
static int64_t f183_ck_un(int64_t n_889, int64_t want_890) {
S4 x_891 = (*({ hrv *_t2678 = &(g703); int64_t _i2678 = n_889; (S4*)_t2678->b + hr_ix(_i2678, _t2678->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:326"); })); 
int64_t o_892 = ((int64_t)((x_891).op_)); 
int64_t a_893 = ((int64_t)((x_891).a_)); 
if (((o_892) == (((int64_t)47LL)))) { (void)(f137_ck(a_893, g558));
(void)(f140_conv(a_893, g558));
return f138_set_t(n_889, g558);
 }
if (((o_892) == (((int64_t)49LL)))) { int64_t t_894 = f137_ck(a_893, ({ int64_t _r2683; if ((((want_890) >= (((int64_t)0LL))) && ((((*({ hrv *_t2684 = &(g550); int64_t _i2684 = want_890; (S1*)_t2684->b + hr_ix(_i2684, _t2684->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:329"); }))).k_) == (((uint8_t)10LL))))) { _r2683 = ((int64_t)(((*({ hrv *_t2685 = &(g550); int64_t _i2685 = want_890; (S1*)_t2685->b + hr_ix(_i2685, _t2685->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:329"); }))).a_));  } else { _r2683 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2683; })); 
if (f163_is_pending(t_894)) { (void)(f184_default_t(a_893));
 }
(void)(f175_set_x(n_889, ((int64_t)1LL)));
return f138_set_t(n_889, f141_at(a_893));
 }
int64_t t_913 = f137_ck(a_893, want_890); 
int64_t d_914 = f179_deref(t_913); 
if (((t_913) != (d_914))) { (void)(f142_set_cv(a_893, d_914));
 }
if (((((o_892) == (((int64_t)22LL))) && ((((*({ hrv *_t2694 = &(g550); int64_t _i2694 = d_914; (S1*)_t2694->b + hr_ix(_i2694, _t2694->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:333"); }))).k_) == (((uint8_t)3LL)))) && (!(f153_is_signed(d_914))))) { (void)(f108_cerr(n_889, hr_str("unary - of an unsigned integer", 30)));
 }
return f138_set_t(n_889, d_914);
}
static int64_t f184_default_t(int64_t n_895) {
int64_t t_896 = f141_at(n_895); 
if (((t_896) < (((int64_t)0LL)))) { return g557;
 }
int64_t k_897 = ((int64_t)(((*({ hrv *_t2699 = &(g550); int64_t _i2699 = t_896; (S1*)_t2699->b + hr_ix(_i2699, _t2699->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:215"); }))).k_)); 
if (((k_897) == (((int64_t)12LL)))) { M78 _t2700 = f155_cval(n_895); int64_t v_898 = _t2700.r0; bool u_899 = _t2700.r1; bool ok_900 = _t2700.r2; 
int64_t d_901 = ({ int64_t _r2702; if ((ok_900 && u_899)) { _r2702 = g566;  } else { _r2702 = g562;  } _r2702; }); 
(void)(f162_commit(n_895, d_901));
return d_901;
 }
if (((k_897) == (((int64_t)13LL)))) { (void)(f162_commit(n_895, g568));
return g568;
 }
if (((k_897) == (((int64_t)18LL)))) { (void)(f138_set_t(n_895, g575));
return g575;
 }
if (((k_897) == (((int64_t)19LL)))) { S4 x_902 = (*({ hrv *_t2706 = &(g703); int64_t _i2706 = n_895; (S4*)_t2706->b + hr_ix(_i2706, _t2706->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:220"); })); 
int64_t e_903 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((x_902).a_) >= (((int32_t)0LL)))) { e_903 = f184_default_t(((int64_t)((x_902).a_)));
M78 _t2708 = f155_cval(((int64_t)((x_902).b_))); int64_t cnt_904 = _t2708.r0; bool u0_905 = _t2708.r1; bool ok_906 = _t2708.r2; 
(void)(f140_conv(((int64_t)((x_902).b_)), g562));
int64_t a_907 = f123_t_arr(e_903, ((int64_t)1LL), cnt_904, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f138_set_t(n_895, a_907));
return a_907;
 }
{ int32_t _e2714 = (x_902).n_; for (int32_t _k2714 = 0; _k2714 < _e2714; _k2714++) { int32_t i_908 = (int32_t)_k2714; int64_t c_909 = f90_kid(n_895, ((int64_t)(i_908))); 
int64_t ct_910 = f141_at(c_909); 
if ((!(f163_is_pending(ct_910)))) { e_903 = ct_910;
 }
 } } _bk2713:; 
if ((((e_903) < (((int64_t)0LL))) && (((x_902).n_) > (((int32_t)0LL))))) { e_903 = f184_default_t(f90_kid(n_895, ((int64_t)0LL)));
 }
if (((e_903) < (((int64_t)0LL)))) { (void)(f108_cerr(n_895, hr_str("an empty [] has no element type here", 36)));
return g574;
 }
{ int32_t _e2722 = (x_902).n_; for (int32_t _k2722 = 0; _k2722 < _e2722; _k2722++) { int32_t i_911 = (int32_t)_k2722; (void)(f140_conv(f90_kid(n_895, ((int64_t)(i_911))), e_903));
 } } _bk2721:; 
int64_t a_912 = f123_t_arr(e_903, ((int64_t)1LL), ((int64_t)((x_902).n_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f138_set_t(n_895, a_912));
return a_912;
 }
return t_896;
}
static int64_t f185_ck_dot(int64_t n_916, int64_t want_917) {
S4 x_918 = (*({ hrv *_t2727 = &(g703); int64_t _i2727 = n_916; (S4*)_t2727->b + hr_ix(_i2727, _t2727->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:405"); })); 
int64_t a_919 = ((int64_t)((x_918).a_)); 
int64_t name_920 = ((int64_t)((x_918).s_)); 
if ((((((*({ hrv *_t2728 = &(g703); int64_t _i2728 = a_919; (S4*)_t2728->b + hr_ix(_i2728, _t2728->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:408"); }))).k_) == (((uint8_t)8LL))) && ((f167_find_lv(((int64_t)(((*({ hrv *_t2730 = &(g703); int64_t _i2730 = a_919; (S4*)_t2730->b + hr_ix(_i2730, _t2730->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:408"); }))).s_)))) < (((int64_t)0LL))))) { int64_t ns_921 = f110_ns_of(a_919); 
int64_t de_922 = f116_lookup_q(((int64_t)(((*({ hrv *_t2733 = &(g703); int64_t _i2733 = a_919; (S4*)_t2733->b + hr_ix(_i2733, _t2733->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:410"); }))).s_)), ns_921, ((int64_t)2LL)); 
if ((((de_922) >= (((int64_t)0LL))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t2735 = &(g703); int64_t _i2735 = a_919; (S4*)_t2735->b + hr_ix(_i2735, _t2735->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:411"); }))).s_)), ns_921, ((int64_t)5LL))) < (((int64_t)0LL))))) { int64_t et_926 = f186_rtype_name_enum(de_922); 
int64_t ei_927 = ((int64_t)(((*({ hrv *_t2737 = &(g550); int64_t _i2737 = et_926; (S1*)_t2737->b + hr_ix(_i2737, _t2737->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:413"); }))).a_)); 
{ int32_t _e2739 = ((*({ hrv *_t2740 = &(g555); int64_t _i2740 = ei_927; (S8*)_t2740->b + hr_ix(_i2740, _t2740->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:414"); }))).vnum_; for (int32_t _k2739 = 0; _k2739 < _e2739; _k2739++) { int32_t i_928 = (int32_t)_k2739; if (((((int64_t)(((*({ hrv *_t2741 = &(g556); int64_t _i2741 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2742 = &(g555); int64_t _i2742 = ei_927; (S8*)_t2742->b + hr_ix(_i2742, _t2742->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:414"); }))).v0_)) + (int64_t)((int64_t)(i_928)))); (S9*)_t2741->b + hr_ix(_i2741, _t2741->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:414"); }))).name_))) == (name_920))) { (void)(f170_set_r(n_916, ((int64_t)7LL), ((int64_t)(i_928))));
return f138_set_t(n_916, f125_t_variant(ei_927, ((int64_t)(i_928))));
 }
 } } _bk2738:; 
hrv m_929 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2749 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2747 = &(m_929); hr_fs(_o2747, hr_str("no variant ", 11)); hr_fs(_o2747, f10_nm(name_920)); hr_fs(_o2747, hr_str(" in ", 4)); hr_fs(_o2747, hr_sl(*hr_tmp(&_t2749, f161_tn(et_926)))); }));
}
(void)(f108_cerr(n_916, hr_sl(m_929)));
return f138_set_t(n_916, g574);
 }
 }
int64_t t0_930 = f137_ck(a_919, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t t_931 = t0_930; 
if (((((*({ hrv *_t2754 = &(g550); int64_t _i2754 = t_931; (S1*)_t2754->b + hr_ix(_i2754, _t2754->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:420"); }))).k_) == (((uint8_t)18LL)))) { t_931 = g575;
(void)(f138_set_t(a_919, g575));
 }
if (((((*({ hrv *_t2756 = &(g550); int64_t _i2756 = t_931; (S1*)_t2756->b + hr_ix(_i2756, _t2756->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:421"); }))).k_) == (((uint8_t)19LL)))) { t_931 = f184_default_t(a_919);
 }
int64_t d_932 = f179_deref(t_931); 
int64_t k_933 = ((int64_t)(((*({ hrv *_t2759 = &(g550); int64_t _i2759 = d_932; (S1*)_t2759->b + hr_ix(_i2759, _t2759->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:423"); }))).k_)); 
if (((((k_933) == (((int64_t)8LL))) || ((k_933) == (((int64_t)9LL)))) && hr_streq(f10_nm(name_920), hr_str("len", 3)))) { (void)(f170_set_r(n_916, ((int64_t)8LL), ((int64_t)1LL)));
return f138_set_t(n_916, g562);
 }
if ((((k_933) == (((int64_t)8LL))) && hr_streq(f10_nm(name_920), hr_str("cap", 3)))) { (void)(f170_set_r(n_916, ((int64_t)8LL), ((int64_t)2LL)));
return f138_set_t(n_916, g562);
 }
if (((k_933) == (((int64_t)5LL)))) { int64_t si_934 = ((int64_t)(((*({ hrv *_t2766 = &(g550); int64_t _i2766 = d_932; (S1*)_t2766->b + hr_ix(_i2766, _t2766->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:427"); }))).a_)); 
int64_t fi_938 = f187_sfield(si_934, name_920); 
if (((fi_938) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_916, ((int64_t)5LL), fi_938));
int64_t ft_939 = ((int64_t)(((*({ hrv *_t2769 = &(g554); int64_t _i2769 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2770 = &(g553); int64_t _i2770 = si_934; (S10*)_t2770->b + hr_ix(_i2770, _t2770->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:429"); }))).f0_)) + (int64_t)fi_938)); (S11*)_t2769->b + hr_ix(_i2769, _t2769->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:429"); }))).ty_)); 
return f138_set_t(n_916, f188_decode_rel(ft_939));
 }
 }
if (((k_933) == (((int64_t)7LL)))) { S9 v_941 = (*({ hrv *_t2773 = &(g556); int64_t _i2773 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2774 = &(g555); int64_t _i2774 = ((*({ hrv *_t2775 = &(g550); int64_t _i2775 = d_932; (S1*)_t2775->b + hr_ix(_i2775, _t2775->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:432"); }))).a_; (S8*)_t2774->b + hr_ix(_i2774, _t2774->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:432"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t2776 = &(g550); int64_t _i2776 = d_932; (S1*)_t2776->b + hr_ix(_i2776, _t2776->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:432"); }))).c_)))); (S9*)_t2773->b + hr_ix(_i2773, _t2773->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:432"); })); 
if ((((v_941).si_) >= (((int32_t)0LL)))) { int64_t fi_942 = f187_sfield(((int64_t)((v_941).si_)), name_920); 
if (((fi_942) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_916, ((int64_t)5LL), fi_942));
(void)(f175_set_x(n_916, ((int64_t)((v_941).si_))));
return f138_set_t(n_916, f188_decode_rel(((int64_t)(((*({ hrv *_t2782 = &(g554); int64_t _i2782 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2783 = &(g553); int64_t _i2783 = (v_941).si_; (S10*)_t2783->b + hr_ix(_i2783, _t2783->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:433"); }))).f0_)) + (int64_t)fi_942)); (S11*)_t2782->b + hr_ix(_i2782, _t2782->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:433"); }))).ty_))));
 }
 }
 }
hrv m_943 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2787 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2785 = &(m_943); hr_fs(_o2785, hr_str("no field ", 9)); hr_fs(_o2785, f10_nm(name_920)); hr_fs(_o2785, hr_str(" in ", 4)); hr_fs(_o2785, hr_sl(*hr_tmp(&_t2787, f161_tn(d_932)))); }));
}
(void)(f108_cerr(n_916, hr_sl(m_943)));
return f138_set_t(n_916, g574);
}
static int64_t f186_rtype_name_enum(int64_t de_923) {
int64_t node_924 = ((int64_t)(((*({ hrv *_t2791 = &(g488); int64_t _i2791 = de_923; (S5*)_t2791->b + hr_ix(_i2791, _t2791->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:438"); }))).node_)); 
L84 none_925 = ({ L84 _t2792; memset(&_t2792, 0, sizeof _t2792); _t2792.n = 0; _t2792; }); 
return f136_t_enum(f135_inst_enum(node_924, ({ hsl _t2795 = ({ L84 *_t2796 = &(none_925); (hsl){ (uint8_t*)_t2796->e, _t2796->n }; }); int64_t _l2795 = 0, _h2795 = _t2795.n; if (_l2795 < 0 || _h2795 < _l2795 || _h2795 > _t2795.n) hr_slerr(_l2795, _h2795, _t2795.n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:438"); (hsl){ _t2795.p + _l2795 * (int64_t)sizeof(int32_t), _h2795 - _l2795 }; })), false);
}
static int64_t f187_sfield(int64_t si_935, int64_t name_936) {
{ int32_t _e2798 = ((*({ hrv *_t2799 = &(g553); int64_t _i2799 = si_935; (S10*)_t2799->b + hr_ix(_i2799, _t2799->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:196"); }))).fnum_; for (int32_t _k2798 = 0; _k2798 < _e2798; _k2798++) { int32_t i_937 = (int32_t)_k2798; if (((((int64_t)(((*({ hrv *_t2800 = &(g554); int64_t _i2800 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2801 = &(g553); int64_t _i2801 = si_935; (S10*)_t2801->b + hr_ix(_i2801, _t2801->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:196"); }))).f0_)) + (int64_t)((int64_t)(i_937)))); (S11*)_t2800->b + hr_ix(_i2800, _t2800->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:196"); }))).name_))) == (name_936))) { return ((int64_t)(i_937));
 }
 } } _bk2797:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f188_decode_rel(int64_t ft_940) {
return ({ int64_t _r2802; if ((((((*({ hrv *_t2803 = &(g550); int64_t _i2803 = ft_940; (S1*)_t2803->b + hr_ix(_i2803, _t2803->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:403"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2804 = &(g550); int64_t _i2804 = ft_940; (S1*)_t2804->b + hr_ix(_i2804, _t2804->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:403"); }))).c_) >= (((int32_t)0LL))))) { _r2802 = f119_t_ref(((int64_t)(((*({ hrv *_t2806 = &(g550); int64_t _i2806 = ft_940; (S1*)_t2806->b + hr_ix(_i2806, _t2806->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:403"); }))).a_)), ((int64_t)(((*({ hrv *_t2807 = &(g550); int64_t _i2807 = ft_940; (S1*)_t2807->b + hr_ix(_i2807, _t2807->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:403"); }))).fl_)));  } else { _r2802 = ft_940;  } _r2802; });
}
static int64_t f189_ck_idx(int64_t n_944, int64_t want_945) {
S4 x_946 = (*({ hrv *_t2808 = &(g703); int64_t _i2808 = n_944; (S4*)_t2808->b + hr_ix(_i2808, _t2808->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:440"); })); 
int64_t t_947 = f137_ck(((int64_t)((x_946).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t2810 = &(g550); int64_t _i2810 = t_947; (S1*)_t2810->b + hr_ix(_i2810, _t2810->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:442"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_946).a_)), g575));
t_947 = g575;
 }
if (((((*({ hrv *_t2812 = &(g550); int64_t _i2812 = t_947; (S1*)_t2812->b + hr_ix(_i2812, _t2812->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:443"); }))).k_) == (((uint8_t)19LL)))) { t_947 = f184_default_t(((int64_t)((x_946).a_)));
 }
int64_t d_948 = f179_deref(t_947); 
int64_t ti_949 = f137_ck(((int64_t)((x_946).b_)), g562); 
if (((((*({ hrv *_t2816 = &(g550); int64_t _i2816 = ti_949; (S1*)_t2816->b + hr_ix(_i2816, _t2816->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:446"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_946).b_)), g562));
 } else { int64_t di_950 = f179_deref(ti_949); 
if ((((((*({ hrv *_t2819 = &(g550); int64_t _i2819 = di_950; (S1*)_t2819->b + hr_ix(_i2819, _t2819->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:446"); }))).k_) != (((uint8_t)3LL))) && ((((*({ hrv *_t2820 = &(g550); int64_t _i2820 = di_950; (S1*)_t2820->b + hr_ix(_i2820, _t2820->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:446"); }))).k_) != (((uint8_t)17LL))))) { (void)(f108_cerr(((int64_t)((x_946).b_)), hr_str("index must be an integer", 24)));
 } else { if (((di_950) != (ti_949))) { (void)(f142_set_cv(((int64_t)((x_946).b_)), di_950));
 }
 }
 }
int64_t k_951 = ((int64_t)(((*({ hrv *_t2823 = &(g550); int64_t _i2823 = d_948; (S1*)_t2823->b + hr_ix(_i2823, _t2823->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:447"); }))).k_)); 
if ((((k_951) == (((int64_t)8LL))) || ((k_951) == (((int64_t)9LL))))) { return f138_set_t(n_944, f188_decode_rel(((int64_t)(((*({ hrv *_t2826 = &(g550); int64_t _i2826 = d_948; (S1*)_t2826->b + hr_ix(_i2826, _t2826->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:448"); }))).a_))));
 }
hrv m_952 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2829 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2828 = &(m_952); hr_fs(_o2828, hr_str("cannot index ", 13)); hr_fs(_o2828, hr_sl(*hr_tmp(&_t2829, f161_tn(d_948)))); }));
}
(void)(f108_cerr(n_944, hr_sl(m_952)));
return f138_set_t(n_944, g574);
}
static int64_t f190_ck_slice(int64_t n_953, int64_t want_954) {
S4 x_955 = (*({ hrv *_t2833 = &(g703); int64_t _i2833 = n_953; (S4*)_t2833->b + hr_ix(_i2833, _t2833->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:453"); })); 
int64_t t_956 = f137_ck(((int64_t)((x_955).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t2835 = &(g550); int64_t _i2835 = t_956; (S1*)_t2835->b + hr_ix(_i2835, _t2835->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:455"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_955).a_)), g575));
t_956 = g575;
 }
if (((((*({ hrv *_t2837 = &(g550); int64_t _i2837 = t_956; (S1*)_t2837->b + hr_ix(_i2837, _t2837->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:456"); }))).k_) == (((uint8_t)19LL)))) { t_956 = f184_default_t(((int64_t)((x_955).a_)));
 }
int64_t d_957 = f179_deref(t_956); 
if ((((x_955).b_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_955).b_)), g562));
(void)(f140_conv(((int64_t)((x_955).b_)), g562));
 }
if ((((x_955).c_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_955).c_)), g562));
(void)(f140_conv(((int64_t)((x_955).c_)), g562));
 }
int64_t k_958 = ((int64_t)(((*({ hrv *_t2844 = &(g550); int64_t _i2844 = d_957; (S1*)_t2844->b + hr_ix(_i2844, _t2844->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:460"); }))).k_)); 
if (((k_958) == (((int64_t)8LL)))) { return f138_set_t(n_953, f18_t_slice(((int64_t)(((*({ hrv *_t2847 = &(g550); int64_t _i2847 = d_957; (S1*)_t2847->b + hr_ix(_i2847, _t2847->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:461"); }))).a_)), false));
 }
if (((k_958) == (((int64_t)9LL)))) { return f138_set_t(n_953, d_957);
 }
hrv m_959 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2851 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2850 = &(m_959); hr_fs(_o2850, hr_str("cannot slice ", 13)); hr_fs(_o2850, hr_sl(*hr_tmp(&_t2851, f161_tn(d_957)))); }));
}
(void)(f108_cerr(n_953, hr_sl(m_959)));
return f138_set_t(n_953, g574);
}
static int64_t f191_ck_as(int64_t n_960, int64_t want_961) {
S4 x_962 = (*({ hrv *_t2855 = &(g703); int64_t _i2855 = n_960; (S4*)_t2855->b + hr_ix(_i2855, _t2855->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:467"); })); 
int64_t t_963 = f113_rtype(((int64_t)((x_962).b_)), f110_ns_of(n_960)); 
int64_t f_964 = f137_ck(((int64_t)((x_962).a_)), ({ int64_t _r2859; if ((((((*({ hrv *_t2860 = &(g550); int64_t _i2860 = t_963; (S1*)_t2860->b + hr_ix(_i2860, _t2860->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:469"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2861 = &(g550); int64_t _i2861 = t_963; (S1*)_t2861->b + hr_ix(_i2861, _t2861->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:469"); }))).k_) == (((uint8_t)4LL))))) { _r2859 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2859 = t_963;  } _r2859; })); 
int64_t df_965 = f179_deref(f_964); 
if ((((((*({ hrv *_t2863 = &(g550); int64_t _i2863 = df_965; (S1*)_t2863->b + hr_ix(_i2863, _t2863->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:471"); }))).k_) == (((uint8_t)12LL))) || ((((*({ hrv *_t2864 = &(g550); int64_t _i2864 = df_965; (S1*)_t2864->b + hr_ix(_i2864, _t2864->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:471"); }))).k_) == (((uint8_t)13LL))))) { (void)(f140_conv(((int64_t)((x_962).a_)), ({ int64_t _r2866; if ((((((*({ hrv *_t2867 = &(g550); int64_t _i2867 = t_963; (S1*)_t2867->b + hr_ix(_i2867, _t2867->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:471"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2868 = &(g550); int64_t _i2868 = t_963; (S1*)_t2868->b + hr_ix(_i2868, _t2868->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:471"); }))).k_) == (((uint8_t)4LL))))) { _r2866 = t_963;  } else { _r2866 = g562;  } _r2866; })));
 } else { if (((df_965) != (f_964))) { (void)(f142_set_cv(((int64_t)((x_962).a_)), df_965));
 }
 }
return f138_set_t(n_960, t_963);
}
static int64_t f192_ck_arr(int64_t n_966, int64_t want_967) {
S4 x_968 = (*({ hrv *_t2871 = &(g703); int64_t _i2871 = n_966; (S4*)_t2871->b + hr_ix(_i2871, _t2871->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:703"); })); 
int64_t e_969 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((want_967) >= (((int64_t)0LL))) && (((((*({ hrv *_t2872 = &(g550); int64_t _i2872 = want_967; (S1*)_t2872->b + hr_ix(_i2872, _t2872->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:705"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2873 = &(g550); int64_t _i2873 = want_967; (S1*)_t2873->b + hr_ix(_i2873, _t2873->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:705"); }))).k_) == (((uint8_t)9LL)))))) { e_969 = ((int64_t)(((*({ hrv *_t2874 = &(g550); int64_t _i2874 = want_967; (S1*)_t2874->b + hr_ix(_i2874, _t2874->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:705"); }))).a_));
 }
if ((((x_968).c_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_968).c_)), g562));
(void)(f140_conv(((int64_t)((x_968).c_)), g562));
if (((want_967) >= (((int64_t)0LL)))) { return f138_set_t(n_966, want_967);
 }
return f138_set_t(n_966, g576);
 }
if ((((x_968).a_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_968).a_)), e_969));
(void)(f137_ck(((int64_t)((x_968).b_)), g562));
if (((e_969) >= (((int64_t)0LL)))) { (void)(f140_conv(((int64_t)((x_968).a_)), e_969));
(void)(f140_conv(((int64_t)((x_968).b_)), g562));
if (((((*({ hrv *_t2883 = &(g550); int64_t _i2883 = want_967; (S1*)_t2883->b + hr_ix(_i2883, _t2883->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:707"); }))).k_) == (((uint8_t)9LL)))) { M78 _t2884 = f155_cval(((int64_t)((x_968).b_))); int64_t cnt_970 = _t2884.r0; bool u0_971 = _t2884.r1; bool ok_972 = _t2884.r2; 
(void)(f138_set_t(n_966, f123_t_arr(e_969, ((int64_t)1LL), cnt_970, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f142_set_cv(n_966, want_967));
return want_967;
 }
return f138_set_t(n_966, want_967);
 }
return f138_set_t(n_966, g576);
 }
{ int32_t _e2892 = (x_968).n_; for (int32_t _k2892 = 0; _k2892 < _e2892; _k2892++) { int32_t i_973 = (int32_t)_k2892; (void)(f137_ck(f90_kid(n_966, ((int64_t)(i_973))), e_969));
 } } _bk2891:; 
if (((e_969) >= (((int64_t)0LL)))) { { int32_t _e2896 = (x_968).n_; for (int32_t _k2896 = 0; _k2896 < _e2896; _k2896++) { int32_t i_974 = (int32_t)_k2896; (void)(f140_conv(f90_kid(n_966, ((int64_t)(i_974))), e_969));
 } } _bk2895:; 
if (((((*({ hrv *_t2899 = &(g550); int64_t _i2899 = want_967; (S1*)_t2899->b + hr_ix(_i2899, _t2899->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:711"); }))).k_) == (((uint8_t)9LL)))) { (void)(f138_set_t(n_966, f123_t_arr(e_969, ((int64_t)1LL), f103_max(((int64_t)((x_968).n_)), ((int64_t)1LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f142_set_cv(n_966, want_967));
return want_967;
 }
return f138_set_t(n_966, want_967);
 }
return f138_set_t(n_966, g576);
}
static int64_t f193_ck_block(int64_t n_975, int64_t want_976) {
S4 x_977 = (*({ hrv *_t2906 = &(g703); int64_t _i2906 = n_975; (S4*)_t2906->b + hr_ix(_i2906, _t2906->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:476"); })); 
int64_t m_978 = (g389).n; 
int64_t nm0_979 = (g390).n; 
int64_t nf0_1013 = f194_pre_decl_block_fns(n_975); 
{ int32_t _e2909 = (x_977).n_; for (int32_t _k2909 = 0; _k2909 < _e2909; _k2909++) { int32_t i_1014 = (int32_t)_k2909; (void)(f200_cstmt(f90_kid(n_975, ((int64_t)(i_1014)))));
 } } _bk2908:; 
int64_t t_1098 = g557; 
if ((((x_977).a_) >= (((int32_t)0LL)))) { t_1098 = f137_ck(((int64_t)((x_977).a_)), want_976);
 }
(void)(f211_pop_block_fns(nf0_1013));
(void)(f178_narrow_pop(nm0_979));
(void)(({ hrv *_v2915 = &(g389); int64_t _k2915 = ((int64_t)((int64_t)(g389).n - (int64_t)m_978)); if (_k2915 < 0 || _k2915 > _v2915->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:485"); _v2915->n -= _k2915; }));
return f138_set_t(n_975, t_1098);
}
static int64_t f194_pre_decl_block_fns(int64_t b_980) {
int64_t m_981 = (g311).n; 
{ int32_t _e2918 = ((*({ hrv *_t2919 = &(g703); int64_t _i2919 = b_980; (S4*)_t2919->b + hr_ix(_i2919, _t2919->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); }))).n_; for (int32_t _k2918 = 0; _k2918 < _e2918; _k2918++) { int32_t q_982 = (int32_t)_k2918; int64_t c_983 = f90_kid(b_980, ((int64_t)(q_982))); 
if (((((int64_t)(((*({ hrv *_t2921 = &(g703); int64_t _i2921 = c_983; (S4*)_t2921->b + hr_ix(_i2921, _t2921->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); }))).k_))) == (((int64_t)50LL)))) { int64_t i_984 = f105_new_inst(c_983, c_983, ((int64_t)((*({ hrv *_t2923 = &(g718); int64_t _i2923 = c_983; (int32_t*)_t2923->b + hr_ix(_i2923, _t2923->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); })))), g400); 
(void)(({ hrv *_v2924 = &(g311); S14 _x2924 = ((S14){ .name_ = ((*({ hrv *_t2925 = &(g703); int64_t _i2925 = c_983; (S4*)_t2925->b + hr_ix(_i2925, _t2925->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); }))).s_, .node_ = ((int32_t)(c_983)), .inst_ = ((int32_t)(i_984)), .own_ = ((int32_t)(g400)), }); S14 *_p2924 = (S14*)hr_grow(_v2924, 1, sizeof _x2924); *_p2924 = _x2924; _p2924; }));
(void)(f195_sig_inst(i_984));
 }
 } } _bk2917:; 
return m_981;
}
static void f195_sig_inst(int64_t i_985) {
int64_t node_986 = ((int64_t)(((*({ hrv *_t2927 = &(g387); int64_t _i2927 = i_985; (S6*)_t2927->b + hr_ix(_i2927, _t2927->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:106"); }))).node_)); 
int64_t ns_987 = f110_ns_of(node_986); 
int64_t g0_988 = (g490).n; 
{ int32_t _e2930 = ((*({ hrv *_t2931 = &(g387); int64_t _i2931 = i_985; (S6*)_t2931->b + hr_ix(_i2931, _t2931->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:109"); }))).gn_; for (int32_t _k2930 = 0; _k2930 < _e2930; _k2930++) { int32_t j_989 = (int32_t)_k2930; (void)(({ hrv *_v2932 = &(g490); S7 _x2932 = (*({ hrv *_t2933 = &(g393); int64_t _i2933 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2934 = &(g387); int64_t _i2934 = i_985; (S6*)_t2934->b + hr_ix(_i2934, _t2934->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:109"); }))).g0_)) + (int64_t)((int64_t)(j_989)))); (S7*)_t2933->b + hr_ix(_i2933, _t2933->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:109"); })); S7 *_p2932 = (S7*)hr_grow(_v2932, 1, sizeof _x2932); *_p2932 = _x2932; _p2932; }));
 } } _bk2929:; 
int64_t p0_990 = (g551).n; 
L88 pts_991 = ({ L88 _t2935; memset(&_t2935, 0, sizeof _t2935); _t2935.n = 0; _t2935; }); 
{ int32_t _e2937 = ((*({ hrv *_t2938 = &(g703); int64_t _i2938 = node_986; (S4*)_t2938->b + hr_ix(_i2938, _t2938->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:112"); }))).n_; for (int32_t _k2937 = 0; _k2937 < _e2937; _k2937++) { int32_t j_992 = (int32_t)_k2937; int64_t p_993 = f90_kid(node_986, ((int64_t)(j_992))); 
int64_t t_994 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((*({ hrv *_t2940 = &(g703); int64_t _i2940 = p_993; (S4*)_t2940->b + hr_ix(_i2940, _t2940->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:115"); }))).a_) >= (((int32_t)0LL)))) { t_994 = f113_rtype(((int64_t)(((*({ hrv *_t2942 = &(g703); int64_t _i2942 = p_993; (S4*)_t2942->b + hr_ix(_i2942, _t2942->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:115"); }))).a_)), ns_987);
 } else { t_994 = f130_gb_find(f196_upname(p_993));
if (((t_994) < (((int64_t)0LL)))) { t_994 = g574;
 }
 }
(void)(({ L88 *_v2945 = &(pts_991); int32_t _x2945 = ((int32_t)(t_994)); if (_v2945->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:116"); _v2945->e[_v2945->n] = _x2945; &_v2945->e[_v2945->n++]; }));
 } } _bk2936:; 
{ int32_t *_t2946 = &(((*({ hrv *_t2947 = &(g387); int64_t _i2947 = i_985; (S6*)_t2947->b + hr_ix(_i2947, _t2947->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:118"); }))).p0_); *_t2946 = ((int32_t)((g551).n)); }
(void)(({ hrv *_v2948 = &(g551); hsl _s2948 = ({ hsl _t2949 = ({ L88 *_t2950 = &(pts_991); (hsl){ (uint8_t*)_t2950->e, _t2950->n }; }); int64_t _l2949 = 0, _h2949 = _t2949.n; if (_l2949 < 0 || _h2949 < _l2949 || _h2949 > _t2949.n) hr_slerr(_l2949, _h2949, _t2949.n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:118"); (hsl){ _t2949.p + _l2949 * (int64_t)sizeof(int32_t), _h2949 - _l2949 }; }); hr_append(_v2948, _s2948.p, _s2948.n, sizeof(int32_t)); }));
{ int32_t *_t2951 = &(((*({ hrv *_t2952 = &(g387); int64_t _i2952 = i_985; (S6*)_t2952->b + hr_ix(_i2952, _t2952->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:118"); }))).pn_); *_t2951 = ((int32_t)(((int64_t)(pts_991).n))); }
if (((((*({ hrv *_t2953 = &(g703); int64_t _i2953 = node_986; (S4*)_t2953->b + hr_ix(_i2953, _t2953->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:119"); }))).b_) >= (((int32_t)0LL)))) { int64_t rl_997 = ((int64_t)(((*({ hrv *_t2954 = &(g703); int64_t _i2954 = node_986; (S4*)_t2954->b + hr_ix(_i2954, _t2954->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:120"); }))).b_)); 
if (((((*({ hrv *_t2955 = &(g703); int64_t _i2955 = rl_997; (S4*)_t2955->b + hr_ix(_i2955, _t2955->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:121"); }))).n_) == (((int32_t)1LL)))) { { int32_t *_t2956 = &(((*({ hrv *_t2957 = &(g387); int64_t _i2957 = i_985; (S6*)_t2957->b + hr_ix(_i2957, _t2957->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:121"); }))).ret_); *_t2956 = ((int32_t)(f113_rtype(f90_kid(rl_997, ((int64_t)0LL)), ns_987))); }
 } else { L89 rs_998 = ({ L89 _t2960; memset(&_t2960, 0, sizeof _t2960); _t2960.n = 0; _t2960; }); 
{ int32_t _e2962 = ((*({ hrv *_t2963 = &(g703); int64_t _i2963 = rl_997; (S4*)_t2963->b + hr_ix(_i2963, _t2963->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); }))).n_; for (int32_t _k2962 = 0; _k2962 < _e2962; _k2962++) { int32_t j_999 = (int32_t)_k2962; int64_t r0_1000 = f113_rtype(f90_kid(rl_997, ((int64_t)(j_999))), ns_987); 
(void)(({ L89 *_v2966 = &(rs_998); int32_t _x2966 = ((int32_t)(r0_1000)); if (_v2966->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); _v2966->e[_v2966->n] = _x2966; &_v2966->e[_v2966->n++]; }));
 } } _bk2961:; 
{ int32_t *_t2967 = &(((*({ hrv *_t2968 = &(g387); int64_t _i2968 = i_985; (S6*)_t2968->b + hr_ix(_i2968, _t2968->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); }))).ret_); *_t2967 = ((int32_t)(f197_tlist(((int64_t)14LL), ({ hsl _t2970 = ({ L89 *_t2971 = &(rs_998); (hsl){ (uint8_t*)_t2971->e, _t2971->n }; }); int64_t _l2970 = 0, _h2970 = _t2970.n; if (_l2970 < 0 || _h2970 < _l2970 || _h2970 > _t2970.n) hr_slerr(_l2970, _h2970, _t2970.n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); (hsl){ _t2970.p + _l2970 * (int64_t)sizeof(int32_t), _h2970 - _l2970 }; }), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); }
 }
 } else { { int32_t *_t2972 = &(((*({ hrv *_t2973 = &(g387); int64_t _i2973 = i_985; (S6*)_t2973->b + hr_ix(_i2973, _t2973->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).ret_); *_t2972 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
{ bool *_t2974 = &(((*({ hrv *_t2975 = &(g387); int64_t _i2975 = i_985; (S6*)_t2975->b + hr_ix(_i2975, _t2975->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).rinf_); *_t2974 = true; }
if ((((((uint16_t)((uint64_t)((*({ hrv *_t2976 = &(g703); int64_t _i2976 = node_986; (S4*)_t2976->b + hr_ix(_i2976, _t2976->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || f198_surely_void(node_986))) { { int32_t *_t2978 = &(((*({ hrv *_t2979 = &(g387); int64_t _i2979 = i_985; (S6*)_t2979->b + hr_ix(_i2979, _t2979->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).ret_); *_t2978 = ((int32_t)(g557)); }
{ bool *_t2980 = &(((*({ hrv *_t2981 = &(g387); int64_t _i2981 = i_985; (S6*)_t2981->b + hr_ix(_i2981, _t2981->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).rinf_); *_t2980 = false; }
 }
 }
(void)(({ hrv *_v2982 = &(g490); int64_t _k2982 = ((int64_t)((int64_t)(g490).n - (int64_t)g0_988)); if (_k2982 < 0 || _k2982 > _v2982->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:124"); _v2982->n -= _k2982; }));
}
static int64_t f196_upname(int64_t p_995) {
hrv s_996 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v2984 = &(s_996); uint8_t _x2984 = ((uint8_t)36LL); uint8_t *_p2984 = (uint8_t*)hr_grow(_v2984, 1, sizeof _x2984); *_p2984 = _x2984; _p2984; }));
(void)(({ hrv *_v2985 = &(s_996); hsl _s2985 = f10_nm(((int64_t)(((*({ hrv *_t2987 = &(g703); int64_t _i2987 = p_995; (S4*)_t2987->b + hr_ix(_i2987, _t2987->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:60"); }))).s_))); hr_append(_v2985, _s2985.p, _s2985.n, sizeof(uint8_t)); }));
return f8_intern(hr_sl(s_996));
}
static int64_t f197_tlist(int64_t k_1001, hsl xs_1002, int64_t a_1003) {
int64_t l_1004 = (g551).n; 
(void)(({ hrv *_v2989 = &(g551); hsl _s2989 = xs_1002; hr_append(_v2989, _s2989.p, _s2989.n, sizeof(int32_t)); }));
return f13_tmk(((S1){ .k_ = ((uint8_t)(k_1001)), .a_ = ((int32_t)(a_1003)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .l_ = ((int32_t)(l_1004)), .n_ = ((int32_t)((xs_1002).n)), }));
}
static bool f198_surely_void(int64_t fnode_1005) {
int64_t body_1006 = ((int64_t)(((*({ hrv *_t2991 = &(g703); int64_t _i2991 = fnode_1005; (S4*)_t2991->b + hr_ix(_i2991, _t2991->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:127"); }))).c_)); 
if (((body_1006) < (((int64_t)0LL)))) { return true;
 }
int64_t tl_1007 = ((int64_t)(((*({ hrv *_t2992 = &(g703); int64_t _i2992 = body_1006; (S4*)_t2992->b + hr_ix(_i2992, _t2992->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:129"); }))).a_)); 
if (((tl_1007) >= (((int64_t)0LL)))) { int64_t k_1008 = ((int64_t)(((*({ hrv *_t2993 = &(g703); int64_t _i2993 = tl_1007; (S4*)_t2993->b + hr_ix(_i2993, _t2993->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:130"); }))).k_)); 
if ((!((((((((k_1008) == (((int64_t)25LL))) || ((k_1008) == (((int64_t)27LL)))) || ((k_1008) == (((int64_t)28LL)))) || ((k_1008) == (((int64_t)29LL)))) || ((k_1008) == (((int64_t)30LL)))) || (((k_1008) == (((int64_t)19LL))) && ((((*({ hrv *_t2994 = &(g703); int64_t _i2994 = tl_1007; (S4*)_t2994->b + hr_ix(_i2994, _t2994->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:130"); }))).c_) < (((int32_t)0LL)))))))) { return false;
 }
 }
return (!(f199_has_valret(body_1006)));
}
static bool f199_has_valret(int64_t n_1009) {
if (((n_1009) < (((int64_t)0LL)))) { return false;
 }
S4 x_1010 = (*({ hrv *_t2996 = &(g703); int64_t _i2996 = n_1009; (S4*)_t2996->b + hr_ix(_i2996, _t2996->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:135"); })); 
int64_t k_1011 = ((int64_t)((x_1010).k_)); 
if (((k_1011) == (((int64_t)28LL)))) { return ((((x_1010).n_) > (((int32_t)0LL))) && (((x_1010).s_) < (((int32_t)0LL))));
 }
if (((k_1011) == (((int64_t)50LL)))) { return false;
 }
if ((((((k_1011) == (((int64_t)1LL))) || ((k_1011) == (((int64_t)2LL)))) || ((k_1011) == (((int64_t)3LL)))) || ((k_1011) == (((int64_t)8LL))))) { return false;
 }
if ((((k_1011) >= (((int64_t)40LL))) && ((k_1011) < (((int64_t)50LL))))) { return false;
 }
if ((((f199_has_valret(((int64_t)((x_1010).a_))) || f199_has_valret(((int64_t)((x_1010).b_)))) || f199_has_valret(((int64_t)((x_1010).c_)))) || f199_has_valret(((int64_t)((x_1010).d_))))) { return true;
 }
if ((((((((((k_1011) == (((int64_t)23LL))) || ((k_1011) == (((int64_t)11LL)))) || ((k_1011) == (((int64_t)20LL)))) || ((k_1011) == (((int64_t)21LL)))) || ((k_1011) == (((int64_t)36LL)))) || ((k_1011) == (((int64_t)16LL)))) || ((k_1011) == (((int64_t)17LL)))) || ((k_1011) == (((int64_t)28LL))))) { { int32_t _e3002 = (x_1010).n_; for (int32_t _k3002 = 0; _k3002 < _e3002; _k3002++) { int32_t i_1012 = (int32_t)_k3002; if (f199_has_valret(f90_kid(n_1009, ((int64_t)(i_1012))))) { return true;
 }
 } } _bk3001:; 
 }
return false;
}
static void f200_cstmt(int64_t n_1015) {
S4 x_1016 = (*({ hrv *_t3005 = &(g703); int64_t _i3005 = n_1015; (S4*)_t3005->b + hr_ix(_i3005, _t3005->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:717"); })); 
int64_t k_1017 = ((int64_t)((x_1016).k_)); 
if (((k_1017) == (((int64_t)33LL)))) { (void)(f201_ck_vdecl(n_1015));
return;
 }
if (((k_1017) == (((int64_t)34LL)))) { (void)(f205_ck_assign(n_1015));
return;
 }
if (((k_1017) == (((int64_t)35LL)))) { int64_t t_1062 = f137_ck(((int64_t)((x_1016).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if ((((((*({ hrv *_t3009 = &(g550); int64_t _i3009 = f179_deref(t_1062); (S1*)_t3009->b + hr_ix(_i3009, _t3009->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:721"); }))).k_) != (((uint8_t)3LL))) && ((((*({ hrv *_t3011 = &(g550); int64_t _i3011 = f179_deref(t_1062); (S1*)_t3011->b + hr_ix(_i3011, _t3011->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:721"); }))).k_) != (((uint8_t)17LL))))) { (void)(f108_cerr(n_1015, hr_str("++/-- needs an integer", 22)));
 }
return;
 }
if (((k_1017) == (((int64_t)50LL)))) { (void)(f206_decl_nested(n_1015));
return;
 }
int64_t t_1097 = f137_ck(n_1015, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f163_is_pending(t_1097)) { (void)(f184_default_t(n_1015));
 }
}
static void f201_ck_vdecl(int64_t n_1018) {
S4 x_1019 = (*({ hrv *_t3018 = &(g703); int64_t _i3018 = n_1018; (S4*)_t3018->b + hr_ix(_i3018, _t3018->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:728"); })); 
int64_t fl_1020 = ((int64_t)((x_1019).fl_)); 
int64_t ns_1021 = f110_ns_of(n_1018); 
bool byref_1022 = ((((int64_t)((int64_t)fl_1020 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL))); 
int64_t dt_1023 = ({ int64_t _r3020; if ((((x_1019).a_) >= (((int32_t)0LL)))) { _r3020 = f113_rtype(((int64_t)((x_1019).a_)), ns_1021);  } else { _r3020 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3020; }); 
int64_t lf_1024 = ((int64_t)((int64_t)((int64_t)((int64_t)({ int64_t _r3022; if (((((int64_t)((int64_t)fl_1020 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)))) { _r3022 = ((int64_t)1LL);  } else { _r3022 = ((int64_t)0LL);  } _r3022; }) | (int64_t)({ int64_t _r3023; if (((((int64_t)((int64_t)fl_1020 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { _r3023 = ((int64_t)2LL);  } else { _r3023 = ((int64_t)0LL);  } _r3023; }))) | (int64_t)({ int64_t _r3024; if (byref_1022) { _r3024 = ((int64_t)8LL);  } else { _r3024 = ((int64_t)0LL);  } _r3024; }))); 
if ((((x_1019).n_) > (((int32_t)1LL)))) { if ((((x_1019).b_) < (((int32_t)0LL)))) { (void)(f108_cerr(n_1018, hr_str("several names need a call's results", 35)));
return;
 }
int64_t init_1025 = f90_kid(((int64_t)((x_1019).b_)), ((int64_t)0LL)); 
int64_t t_1026 = f137_ck(init_1025, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3028 = &(g550); int64_t _i3028 = t_1026; (S1*)_t3028->b + hr_ix(_i3028, _t3028->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:738"); }))).k_) != (((uint8_t)14LL)))) { if (((((int64_t)(((*({ hrv *_t3029 = &(g703); int64_t _i3029 = (x_1019).b_; (S4*)_t3029->b + hr_ix(_i3029, _t3029->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:738"); }))).n_))) == (((int64_t)((x_1019).n_))))) { { int32_t _e3031 = (x_1019).n_; for (int32_t _k3031 = ((int32_t)1LL); _k3031 < _e3031; _k3031++) { int32_t i_1027 = (int32_t)_k3031; int64_t iv_1028 = f90_kid(((int64_t)((x_1019).b_)), ((int64_t)(i_1027))); 
(void)(f137_ck(iv_1028, dt_1023));
if (((dt_1023) >= (((int64_t)0LL)))) { (void)(f140_conv(iv_1028, dt_1023));
 } else { (void)(f184_default_t(iv_1028));
 }
 } } _bk3030:; 
if (((dt_1023) >= (((int64_t)0LL)))) { (void)(f140_conv(init_1025, dt_1023));
 } else { (void)(f184_default_t(init_1025));
 }
{ int32_t _e3039 = (x_1019).n_; for (int32_t _k3039 = 0; _k3039 < _e3039; _k3039++) { int32_t i_1029 = (int32_t)_k3039; int64_t iv_1030 = f90_kid(((int64_t)((x_1019).b_)), ((int64_t)(i_1029))); 
int64_t v_1037 = f203_add_lv(((int64_t)((*({ hrv *_t3042 = &(g704); int64_t _i3042 = ((int64_t)((int64_t)((int64_t)((x_1019).l_)) + (int64_t)((int64_t)(i_1029)))); (int32_t*)_t3042->b + hr_ix(_i3042, _t3042->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:738"); })))), ({ int64_t _r3043; if (((dt_1023) >= (((int64_t)0LL)))) { _r3043 = dt_1023;  } else { _r3043 = f202_fin_t(iv_1030);  } _r3043; }), lf_1024, n_1018); 
if (((i_1029) == (((int32_t)0LL)))) { (void)(f170_set_r(n_1018, ((int64_t)1LL), v_1037));
 }
 } } _bk3038:; 
(void)(f175_set_x(n_1018, ((int64_t)1LL)));
return;
 }
(void)(f108_cerr(n_1018, hr_str("several names need a call with as many results", 46)));
return;
 }
if (((((*({ hrv *_t3048 = &(g550); int64_t _i3048 = t_1026; (S1*)_t3048->b + hr_ix(_i3048, _t3048->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:739"); }))).n_) != ((x_1019).n_))) { (void)(f108_cerr(n_1018, hr_str("result count does not match the names", 37)));
 }
{ int32_t _e3051 = (x_1019).n_; for (int32_t _k3051 = 0; _k3051 < _e3051; _k3051++) { int32_t i_1038 = (int32_t)_k3051; int64_t et_1039 = ({ int64_t _r3052; if (((((int64_t)(i_1038))) < (((int64_t)(((*({ hrv *_t3053 = &(g550); int64_t _i3053 = t_1026; (S1*)_t3053->b + hr_ix(_i3053, _t3053->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:740"); }))).n_))))) { _r3052 = ((int64_t)((*({ hrv *_t3054 = &(g551); int64_t _i3054 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3055 = &(g550); int64_t _i3055 = t_1026; (S1*)_t3055->b + hr_ix(_i3055, _t3055->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:740"); }))).l_)) + (int64_t)((int64_t)(i_1038)))); (int32_t*)_t3054->b + hr_ix(_i3054, _t3054->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:740"); }))));  } else { _r3052 = g574;  } _r3052; }); 
int64_t v_1040 = f203_add_lv(((int64_t)((*({ hrv *_t3057 = &(g704); int64_t _i3057 = ((int64_t)((int64_t)((int64_t)((x_1019).l_)) + (int64_t)((int64_t)(i_1038)))); (int32_t*)_t3057->b + hr_ix(_i3057, _t3057->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:740"); })))), et_1039, lf_1024, n_1018); 
if (((i_1038) == (((int32_t)0LL)))) { (void)(f170_set_r(n_1018, ((int64_t)1LL), v_1040));
 }
 } } _bk3050:; 
return;
 }
int64_t t_1041 = dt_1023; 
if ((((x_1019).b_) >= (((int32_t)0LL)))) { int64_t init_1042 = f90_kid(((int64_t)((x_1019).b_)), ((int64_t)0LL)); 
if (((((((dt_1023) < (((int64_t)0LL))) && ((((*({ hrv *_t3060 = &(g703); int64_t _i3060 = init_1042; (S4*)_t3060->b + hr_ix(_i3060, _t3060->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:746"); }))).k_) == (((uint8_t)16LL)))) && ((((*({ hrv *_t3061 = &(g703); int64_t _i3061 = init_1042; (S4*)_t3061->b + hr_ix(_i3061, _t3061->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:746"); }))).n_) == (((int32_t)0LL)))) && ((((*({ hrv *_t3062 = &(g703); int64_t _i3062 = init_1042; (S4*)_t3062->b + hr_ix(_i3062, _t3062->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:746"); }))).a_) < (((int32_t)0LL)))) && ((((*({ hrv *_t3063 = &(g703); int64_t _i3063 = init_1042; (S4*)_t3063->b + hr_ix(_i3063, _t3063->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:746"); }))).c_) < (((int32_t)0LL))))) { t_1041 = f123_t_arr(g574, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
(void)(f138_set_t(init_1042, t_1041));
 } else { int64_t it_1043 = f137_ck(init_1042, dt_1023); 
if (((dt_1023) >= (((int64_t)0LL)))) { if (byref_1022) { if ((!(((((*({ hrv *_t3067 = &(g550); int64_t _i3067 = dt_1023; (S1*)_t3067->b + hr_ix(_i3067, _t3067->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:751"); }))).k_) == (((uint8_t)10LL)))))) { (void)(f140_conv(init_1042, dt_1023));
 }
 } else { (void)(f140_conv(init_1042, dt_1023));
 }
 } else { t_1041 = f184_default_t(init_1042);
if (((((*({ hrv *_t3071 = &(g550); int64_t _i3071 = t_1041; (S1*)_t3071->b + hr_ix(_i3071, _t3071->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:754"); }))).k_) == (((uint8_t)14LL)))) { t_1041 = ((int64_t)((*({ hrv *_t3072 = &(g551); int64_t _i3072 = ((*({ hrv *_t3073 = &(g550); int64_t _i3073 = t_1041; (S1*)_t3073->b + hr_ix(_i3073, _t3073->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:754"); }))).l_; (int32_t*)_t3072->b + hr_ix(_i3072, _t3072->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:754"); }))));
 }
if (((((((*({ hrv *_t3074 = &(g550); int64_t _i3074 = t_1041; (S1*)_t3074->b + hr_ix(_i3074, _t3074->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:755"); }))).k_) == (((uint8_t)7LL))) && (((((*({ hrv *_t3075 = &(g703); int64_t _i3075 = init_1042; (S4*)_t3075->b + hr_ix(_i3075, _t3075->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:755"); }))).k_) == (((uint8_t)14LL))) || ((((*({ hrv *_t3076 = &(g703); int64_t _i3076 = init_1042; (S4*)_t3076->b + hr_ix(_i3076, _t3076->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:755"); }))).k_) == (((uint8_t)17LL))))) && ((((int64_t)((int64_t)lf_1024 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL))))) { t_1041 = f136_t_enum(((int64_t)(((*({ hrv *_t3078 = &(g550); int64_t _i3078 = t_1041; (S1*)_t3078->b + hr_ix(_i3078, _t3078->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:755"); }))).a_)), false);
(void)(f142_set_cv(init_1042, t_1041));
 }
if ((byref_1022 || (((((*({ hrv *_t3080 = &(g703); int64_t _i3080 = init_1042; (S4*)_t3080->b + hr_ix(_i3080, _t3080->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:756"); }))).k_) == (((uint8_t)10LL))) && ((((int64_t)(((*({ hrv *_t3081 = &(g703); int64_t _i3081 = init_1042; (S4*)_t3081->b + hr_ix(_i3081, _t3081->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:756"); }))).op_))) == (((int64_t)49LL)))))) { if (((((*({ hrv *_t3082 = &(g550); int64_t _i3082 = t_1041; (S1*)_t3082->b + hr_ix(_i3082, _t3082->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:756"); }))).k_) != (((uint8_t)10LL)))) { t_1041 = f119_t_ref(t_1041, ((int64_t)0LL));
 }
 } else { if ((((((((*({ hrv *_t3084 = &(g550); int64_t _i3084 = t_1041; (S1*)_t3084->b + hr_ix(_i3084, _t3084->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:757"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t3085 = &(g550); int64_t _i3085 = t_1041; (S1*)_t3085->b + hr_ix(_i3085, _t3085->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:757"); }))).c_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t3086 = &(g550); int64_t _i3086 = t_1041; (S1*)_t3086->b + hr_ix(_i3086, _t3086->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:757"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))) && f204_is_fixed(((int64_t)(((*({ hrv *_t3088 = &(g550); int64_t _i3088 = t_1041; (S1*)_t3088->b + hr_ix(_i3088, _t3088->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:757"); }))).a_))))) { t_1041 = ((int64_t)(((*({ hrv *_t3089 = &(g550); int64_t _i3089 = t_1041; (S1*)_t3089->b + hr_ix(_i3089, _t3089->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:757"); }))).a_));
(void)(f142_set_cv(init_1042, t_1041));
 }
 }
 }
 }
 } else { if (((t_1041) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1018, hr_str("a declaration needs a type or an initializer", 44)));
t_1041 = g574;
 }
 }
if ((byref_1022 && ((((*({ hrv *_t3092 = &(g550); int64_t _i3092 = t_1041; (S1*)_t3092->b + hr_ix(_i3092, _t3092->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:763"); }))).k_) != (((uint8_t)10LL))))) { t_1041 = f119_t_ref(t_1041, ((int64_t)0LL));
 }
int64_t v_1045 = f203_add_lv(((int64_t)((*({ hrv *_t3095 = &(g704); int64_t _i3095 = (x_1019).l_; (int32_t*)_t3095->b + hr_ix(_i3095, _t3095->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:764"); })))), t_1041, lf_1024, n_1018); 
(void)(f170_set_r(n_1018, ((int64_t)1LL), v_1045));
}
static int64_t f202_fin_t(int64_t n_1031) {
int64_t c_1032 = f150_cv(n_1031); 
return ({ int64_t _r3098; if (((c_1032) >= (((int64_t)0LL)))) { _r3098 = c_1032;  } else { _r3098 = f141_at(n_1031);  } _r3098; });
}
static int64_t f203_add_lv(int64_t name_1033, int64_t t_1034, int64_t fl_1035, int64_t node_1036) {
(void)(({ hrv *_v3100 = &(g388); S12 _x3100 = ((S12){ .name_ = ((int32_t)(name_1033)), .ty_ = ((int32_t)(t_1034)), .fl_ = ((uint16_t)(fl_1035)), .cfn_ = ((int32_t)(g401)), .own_ = ((int32_t)(g400)), .node_ = ((int32_t)(node_1036)), .cnt_ = ((int32_t)0LL), }); S12 *_p3100 = (S12*)hr_grow(_v3100, 1, sizeof _x3100); *_p3100 = _x3100; _p3100; }));
(void)(({ hrv *_v3101 = &(g389); int32_t _x3101 = ((int32_t)(((int64_t)((int64_t)(g388).n - (int64_t)((int64_t)1LL))))); int32_t *_p3101 = (int32_t*)hr_grow(_v3101, 1, sizeof _x3101); *_p3101 = _x3101; _p3101; }));
return ((int64_t)((int64_t)(g388).n - (int64_t)((int64_t)1LL)));
}
static bool f204_is_fixed(int64_t t_1044) {
return ((f143_tclass(t_1044)) == (((int64_t)0LL)));
}
static void f205_ck_assign(int64_t n_1046) {
S4 x_1047 = (*({ hrv *_t3103 = &(g703); int64_t _i3103 = n_1046; (S4*)_t3103->b + hr_ix(_i3103, _t3103->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:768"); })); 
int64_t o_1048 = ((int64_t)((x_1047).op_)); 
if (((o_1048) == (((int64_t)11LL)))) { int64_t t_1049 = f137_ck(((int64_t)((x_1047).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t tl_1050 = ((int64_t)((x_1047).a_)); 
{ int32_t _e3106 = ((*({ hrv *_t3107 = &(g703); int64_t _i3107 = tl_1050; (S4*)_t3107->b + hr_ix(_i3107, _t3107->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:773"); }))).n_; for (int32_t _k3106 = 0; _k3106 < _e3106; _k3106++) { int32_t i_1051 = (int32_t)_k3106; int64_t tg_1052 = f90_kid(tl_1050, ((int64_t)(i_1051))); 
int64_t tt_1053 = f137_ck(tg_1052, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
 } } _bk3105:; 
return;
 }
if (((o_1048) == (((int64_t)18LL)))) { int64_t tt_1054 = f137_ck(((int64_t)((x_1047).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t rt_1055 = f137_ck(((int64_t)((x_1047).b_)), tt_1054); 
if (f163_is_pending(rt_1055)) { if ((((((*({ hrv *_t3113 = &(g550); int64_t _i3113 = rt_1055; (S1*)_t3113->b + hr_ix(_i3113, _t3113->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:780"); }))).k_) == (((uint8_t)11LL))) && ((((*({ hrv *_t3114 = &(g550); int64_t _i3114 = tt_1054; (S1*)_t3114->b + hr_ix(_i3114, _t3114->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:780"); }))).k_) == (((uint8_t)10LL))))) { (void)(f138_set_t(((int64_t)((x_1047).b_)), f119_t_ref(((int64_t)(((*({ hrv *_t3117 = &(g550); int64_t _i3117 = tt_1054; (S1*)_t3117->b + hr_ix(_i3117, _t3117->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:780"); }))).a_)), ((int64_t)2LL))));
 } else { (void)(f184_default_t(((int64_t)((x_1047).b_))));
 }
 }
if ((((((*({ hrv *_t3119 = &(g703); int64_t _i3119 = (x_1047).a_; (S4*)_t3119->b + hr_ix(_i3119, _t3119->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:783"); }))).k_) == (((uint8_t)8LL))) && ((f156_rk(((int64_t)((x_1047).a_)))) == (((int64_t)1LL))))) { int64_t v_1056 = f157_rv(((int64_t)((x_1047).a_))); 
if ((f165_is_opt(f141_at(((int64_t)((x_1047).b_)))) || ((((*({ hrv *_t3124 = &(g550); int64_t _i3124 = f141_at(((int64_t)((x_1047).b_))); (S1*)_t3124->b + hr_ix(_i3124, _t3124->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:785"); }))).k_) == (((uint8_t)11LL))))) { { int32_t *_t3126 = &(((*({ hrv *_t3127 = &(g388); int64_t _i3127 = v_1056; (S12*)_t3127->b + hr_ix(_i3127, _t3127->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:786"); }))).ty_); *_t3126 = ((int32_t)(f119_t_ref(((int64_t)(((*({ hrv *_t3129 = &(g550); int64_t _i3129 = ((*({ hrv *_t3130 = &(g388); int64_t _i3130 = v_1056; (S12*)_t3130->b + hr_ix(_i3130, _t3130->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:786"); }))).ty_; (S1*)_t3129->b + hr_ix(_i3129, _t3129->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:786"); }))).a_)), ((int64_t)2LL)))); }
 }
 }
return;
 }
int64_t tt_1057 = f137_ck(((int64_t)((x_1047).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t d_1058 = f179_deref(tt_1057); 
if (((o_1048) == (((int64_t)36LL)))) { if ((((((*({ hrv *_t3133 = &(g550); int64_t _i3133 = tt_1057; (S1*)_t3133->b + hr_ix(_i3133, _t3133->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:794"); }))).k_) == (((uint8_t)10LL))) && f165_is_opt(tt_1057))) { int64_t rt_1059 = f137_ck(((int64_t)((x_1047).b_)), tt_1057); 
if (((((*({ hrv *_t3136 = &(g550); int64_t _i3136 = rt_1059; (S1*)_t3136->b + hr_ix(_i3136, _t3136->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:796"); }))).k_) == (((uint8_t)11LL)))) { (void)(f162_commit(((int64_t)((x_1047).b_)), tt_1057));
return;
 }
if (((((*({ hrv *_t3138 = &(g550); int64_t _i3138 = rt_1059; (S1*)_t3138->b + hr_ix(_i3138, _t3138->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:797"); }))).k_) == (((uint8_t)10LL)))) { (void)(f140_conv(((int64_t)((x_1047).b_)), tt_1057));
return;
 }
 }
(void)(f137_ck(((int64_t)((x_1047).b_)), d_1058));
(void)(f140_conv(((int64_t)((x_1047).b_)), d_1058));
return;
 }
int64_t lk_1060 = f180_leaf_kind(d_1058); 
int64_t rt_1061 = f137_ck(((int64_t)((x_1047).b_)), ({ int64_t _r3144; if ((((lk_1060) >= (((int64_t)4LL))) && (((o_1048) == (((int64_t)28LL))) || ((o_1048) == (((int64_t)29LL)))))) { _r3144 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r3144 = d_1058;  } _r3144; })); 
if (((((lk_1060) >= (((int64_t)4LL))) && (((o_1048) == (((int64_t)28LL))) || ((o_1048) == (((int64_t)29LL))))) && ((f179_deref(rt_1061)) != (d_1058)))) { (void)(f140_conv(((int64_t)((x_1047).b_)), f181_leaf_type(d_1058)));
return;
 }
if ((((o_1048) == (((int64_t)45LL))) || ((o_1048) == (((int64_t)46LL))))) { if (f163_is_pending(rt_1061)) { (void)(f140_conv(((int64_t)((x_1047).b_)), g562));
 }
return;
 }
(void)(f140_conv(((int64_t)((x_1047).b_)), d_1058));
}
static void f206_decl_nested(int64_t n_1063) {
int64_t i_1064 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v3152 = &(g311); for (int64_t _k3152 = 0; _k3152 < _v3152->n; _k3152++) { S14 f_1065 = ((S14*)_v3152->b)[_k3152]; if ((((((int64_t)((f_1065).node_))) == (n_1063)) && ((((int64_t)((f_1065).own_))) == (g400)))) { i_1064 = ((int64_t)((f_1065).inst_));
 }
 } } _bk3151:; 
if (((i_1064) < (((int64_t)0LL)))) { i_1064 = f105_new_inst(n_1063, n_1063, ((int64_t)((*({ hrv *_t3154 = &(g718); int64_t _i3154 = n_1063; (int32_t*)_t3154->b + hr_ix(_i3154, _t3154->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:27"); })))), g400);
(void)(({ hrv *_v3155 = &(g311); S14 _x3155 = ((S14){ .name_ = ((*({ hrv *_t3156 = &(g703); int64_t _i3156 = n_1063; (S4*)_t3156->b + hr_ix(_i3156, _t3156->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:27"); }))).s_, .node_ = ((int32_t)(n_1063)), .inst_ = ((int32_t)(i_1064)), .own_ = ((int32_t)(g400)), }); S14 *_p3155 = (S14*)hr_grow(_v3155, 1, sizeof _x3155); *_p3155 = _x3155; _p3155; }));
(void)(f195_sig_inst(i_1064));
 }
(void)(f207_check_inst(i_1064));
}
static void f207_check_inst(int64_t i_1066) {
if (((((*({ hrv *_t3159 = &(g387); int64_t _i3159 = i_1066; (S6*)_t3159->b + hr_ix(_i3159, _t3159->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:146"); }))).st_) != (((uint8_t)0LL)))) { return;
 }
int64_t node_1067 = ((int64_t)(((*({ hrv *_t3160 = &(g387); int64_t _i3160 = i_1066; (S6*)_t3160->b + hr_ix(_i3160, _t3160->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:147"); }))).node_)); 
{ uint8_t *_t3161 = &(((*({ hrv *_t3162 = &(g387); int64_t _i3162 = i_1066; (S6*)_t3162->b + hr_ix(_i3162, _t3162->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:148"); }))).st_); *_t3161 = ((uint8_t)1LL); }
if (((((uint16_t)((uint64_t)((*({ hrv *_t3163 = &(g703); int64_t _i3163 = node_1067; (S4*)_t3163->b + hr_ix(_i3163, _t3163->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:149"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { uint8_t *_t3164 = &(((*({ hrv *_t3165 = &(g387); int64_t _i3165 = i_1066; (S6*)_t3165->b + hr_ix(_i3165, _t3165->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:149"); }))).st_); *_t3164 = ((uint8_t)2LL); }
return;
 }
int64_t sa_1068 = g400; 
int64_t sc_1069 = g401; 
int64_t sm_1070 = (g389).n; 
int64_t ld_1071 = g406; 
int64_t bt_1072 = (g467).n; 
int64_t nm0_1073 = (g311).n; 
g400 = i_1066;
g401 = i_1066;
g406 = ((int64_t)0LL);
int64_t g0_1074 = (g490).n; 
{ int32_t _e3167 = ((*({ hrv *_t3168 = &(g387); int64_t _i3168 = i_1066; (S6*)_t3168->b + hr_ix(_i3168, _t3168->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:153"); }))).gn_; for (int32_t _k3167 = 0; _k3167 < _e3167; _k3167++) { int32_t j_1075 = (int32_t)_k3167; (void)(({ hrv *_v3169 = &(g490); S7 _x3169 = (*({ hrv *_t3170 = &(g393); int64_t _i3170 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3171 = &(g387); int64_t _i3171 = i_1066; (S6*)_t3171->b + hr_ix(_i3171, _t3171->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:153"); }))).g0_)) + (int64_t)((int64_t)(j_1075)))); (S7*)_t3170->b + hr_ix(_i3170, _t3170->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:153"); })); S7 *_p3169 = (S7*)hr_grow(_v3169, 1, sizeof _x3169); *_p3169 = _x3169; _p3169; }));
 } } _bk3166:; 
{ int32_t _e3173 = ((*({ hrv *_t3174 = &(g703); int64_t _i3174 = node_1067; (S4*)_t3174->b + hr_ix(_i3174, _t3174->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:154"); }))).n_; for (int32_t _k3173 = 0; _k3173 < _e3173; _k3173++) { int32_t j_1076 = (int32_t)_k3173; int64_t p_1077 = f90_kid(node_1067, ((int64_t)(j_1076))); 
if (((((*({ hrv *_t3176 = &(g703); int64_t _i3176 = p_1077; (S4*)_t3176->b + hr_ix(_i3176, _t3176->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:154"); }))).b_) >= (((int32_t)0LL)))) { int64_t pt_1080 = f208_ptype_of(i_1066, ((int64_t)(j_1076))); 
(void)(f137_ck(((int64_t)(((*({ hrv *_t3179 = &(g703); int64_t _i3179 = p_1077; (S4*)_t3179->b + hr_ix(_i3179, _t3179->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:154"); }))).b_)), pt_1080));
(void)(f140_conv(((int64_t)(((*({ hrv *_t3181 = &(g703); int64_t _i3181 = p_1077; (S4*)_t3181->b + hr_ix(_i3181, _t3181->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:154"); }))).b_)), pt_1080));
 }
 } } _bk3172:; 
{ int32_t _e3183 = ((*({ hrv *_t3184 = &(g703); int64_t _i3184 = node_1067; (S4*)_t3184->b + hr_ix(_i3184, _t3184->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:155"); }))).n_; for (int32_t _k3183 = 0; _k3183 < _e3183; _k3183++) { int32_t j_1081 = (int32_t)_k3183; int64_t p_1082 = f90_kid(node_1067, ((int64_t)(j_1081))); 
int64_t v_1083 = f203_add_lv(((int64_t)(((*({ hrv *_t3187 = &(g703); int64_t _i3187 = p_1082; (S4*)_t3187->b + hr_ix(_i3187, _t3187->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:155"); }))).s_)), f208_ptype_of(i_1066, ((int64_t)(j_1081))), ((int64_t)((int64_t)((int64_t)4LL) | (int64_t)({ int64_t _r3189; if (((((uint16_t)((uint64_t)((*({ hrv *_t3190 = &(g703); int64_t _i3190 = p_1082; (S4*)_t3190->b + hr_ix(_i3190, _t3190->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:155"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { _r3189 = ((int64_t)1LL);  } else { _r3189 = ((int64_t)0LL);  } _r3189; }))), p_1082); 
(void)(f170_set_r(p_1082, ((int64_t)1LL), v_1083));
 } } _bk3182:; 
int64_t body_1084 = ((int64_t)(((*({ hrv *_t3192 = &(g703); int64_t _i3192 = node_1067; (S4*)_t3192->b + hr_ix(_i3192, _t3192->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:156"); }))).c_)); 
int64_t rt_1085 = ((int64_t)(((*({ hrv *_t3193 = &(g387); int64_t _i3193 = i_1066; (S6*)_t3193->b + hr_ix(_i3193, _t3193->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:157"); }))).ret_)); 
int64_t t_1086 = f137_ck(body_1084, ({ int64_t _r3195; if (((rt_1085) >= (((int64_t)0LL)))) { _r3195 = rt_1085;  } else { _r3195 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3195; })); 
int64_t tail_1087 = ((int64_t)(((*({ hrv *_t3196 = &(g703); int64_t _i3196 = body_1084; (S4*)_t3196->b + hr_ix(_i3196, _t3196->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:159"); }))).a_)); 
if (((rt_1085) >= (((int64_t)0LL)))) { if ((((((tail_1087) >= (((int64_t)0LL))) && ((rt_1085) != (g557))) && ((t_1086) != (g557))) && (!(f209_ends(tail_1087))))) { (void)(f140_conv(tail_1087, rt_1085));
 }
 } else { if (((((*({ hrv *_t3199 = &(g387); int64_t _i3199 = i_1066; (S6*)_t3199->b + hr_ix(_i3199, _t3199->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:162"); }))).ret_) < (((int32_t)0LL)))) { if ((((tail_1087) >= (((int64_t)0LL))) && ((t_1086) != (g557)))) { { int32_t *_t3200 = &(((*({ hrv *_t3201 = &(g387); int64_t _i3201 = i_1066; (S6*)_t3201->b + hr_ix(_i3201, _t3201->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:162"); }))).ret_); *_t3200 = ((int32_t)(f184_default_t(tail_1087))); }
 } else { { int32_t *_t3203 = &(((*({ hrv *_t3204 = &(g387); int64_t _i3204 = i_1066; (S6*)_t3204->b + hr_ix(_i3204, _t3204->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:162"); }))).ret_); *_t3203 = ((int32_t)(g557)); }
 }
 } else { if (((((tail_1087) >= (((int64_t)0LL))) && ((t_1086) != (g557))) && ((((int64_t)(((*({ hrv *_t3205 = &(g387); int64_t _i3205 = i_1066; (S6*)_t3205->b + hr_ix(_i3205, _t3205->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:163"); }))).ret_))) != (g557)))) { (void)(f140_conv(tail_1087, ((int64_t)(((*({ hrv *_t3207 = &(g387); int64_t _i3207 = i_1066; (S6*)_t3207->b + hr_ix(_i3207, _t3207->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:163"); }))).ret_))));
 }
 }
 }
(void)(({ hrv *_v3208 = &(g490); int64_t _k3208 = ((int64_t)((int64_t)(g490).n - (int64_t)g0_1074)); if (_k3208 < 0 || _k3208 > _v3208->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:165"); _v3208->n -= _k3208; }));
(void)(({ hrv *_v3209 = &(g389); int64_t _k3209 = ((int64_t)((int64_t)(g389).n - (int64_t)sm_1070)); if (_k3209 < 0 || _k3209 > _v3209->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:166"); _v3209->n -= _k3209; }));
(void)(({ hrv *_v3210 = &(g311); int64_t _k3210 = ((int64_t)((int64_t)(g311).n - (int64_t)nm0_1073)); if (_k3210 < 0 || _k3210 > _v3210->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:166"); _v3210->n -= _k3210; }));
while ((((g467).n) > (bt_1072))) { (void)(({ hrv *_v3212 = &(g467); if (!_v3212->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:167"); ((int32_t*)_v3212->b)[--_v3212->n]; }));
 } _bk3211:; 
g400 = sa_1068;
g401 = sc_1069;
g406 = ld_1071;
{ uint8_t *_t3213 = &(((*({ hrv *_t3214 = &(g387); int64_t _i3214 = i_1066; (S6*)_t3214->b + hr_ix(_i3214, _t3214->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:169"); }))).st_); *_t3213 = ((uint8_t)2LL); }
}
static int64_t f208_ptype_of(int64_t i_1078, int64_t j_1079) {
return ((int64_t)((*({ hrv *_t3215 = &(g551); int64_t _i3215 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3216 = &(g387); int64_t _i3216 = i_1078; (S6*)_t3216->b + hr_ix(_i3216, _t3216->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:144"); }))).p0_)) + (int64_t)j_1079)); (int32_t*)_t3215->b + hr_ix(_i3215, _t3215->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:144"); }))));
}
static bool f209_ends(int64_t n_1088) {
if (((n_1088) < (((int64_t)0LL)))) { return false;
 }
int64_t k_1089 = ((int64_t)(((*({ hrv *_t3217 = &(g703); int64_t _i3217 = n_1088; (S4*)_t3217->b + hr_ix(_i3217, _t3217->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:490"); }))).k_)); 
if (((((k_1089) == (((int64_t)28LL))) || ((k_1089) == (((int64_t)29LL)))) || ((k_1089) == (((int64_t)30LL))))) { return true;
 }
if ((((k_1089) == (((int64_t)11LL))) && ((((*({ hrv *_t3218 = &(g703); int64_t _i3218 = ((*({ hrv *_t3219 = &(g703); int64_t _i3219 = n_1088; (S4*)_t3219->b + hr_ix(_i3219, _t3219->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:492"); }))).a_; (S4*)_t3218->b + hr_ix(_i3218, _t3218->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:492"); }))).k_) == (((uint8_t)8LL))))) { hsl s_1090 = f10_nm(((int64_t)(((*({ hrv *_t3221 = &(g703); int64_t _i3221 = ((*({ hrv *_t3222 = &(g703); int64_t _i3222 = n_1088; (S4*)_t3222->b + hr_ix(_i3222, _t3222->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:492"); }))).a_; (S4*)_t3221->b + hr_ix(_i3221, _t3221->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:492"); }))).s_))); 
if ((hr_streq(s_1090, hr_str("abort", 5)) || hr_streq(s_1090, hr_str("exit", 4)))) { return true;
 }
 }
if (((k_1089) == (((int64_t)23LL)))) { if (((((*({ hrv *_t3223 = &(g703); int64_t _i3223 = n_1088; (S4*)_t3223->b + hr_ix(_i3223, _t3223->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:493"); }))).a_) >= (((int32_t)0LL)))) { return f209_ends(((int64_t)(((*({ hrv *_t3225 = &(g703); int64_t _i3225 = n_1088; (S4*)_t3225->b + hr_ix(_i3225, _t3225->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:493"); }))).a_)));
 }
if (((((*({ hrv *_t3226 = &(g703); int64_t _i3226 = n_1088; (S4*)_t3226->b + hr_ix(_i3226, _t3226->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:493"); }))).n_) > (((int32_t)0LL)))) { return f209_ends(f90_kid(n_1088, ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3229 = &(g703); int64_t _i3229 = n_1088; (S4*)_t3229->b + hr_ix(_i3229, _t3229->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:493"); }))).n_)) - (int64_t)((int64_t)1LL)))));
 }
return false;
 }
if (((k_1089) == (((int64_t)19LL)))) { return ((((((*({ hrv *_t3230 = &(g703); int64_t _i3230 = n_1088; (S4*)_t3230->b + hr_ix(_i3230, _t3230->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:494"); }))).c_) >= (((int32_t)0LL))) && f209_ends(((int64_t)(((*({ hrv *_t3232 = &(g703); int64_t _i3232 = n_1088; (S4*)_t3232->b + hr_ix(_i3232, _t3232->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:494"); }))).b_)))) && f209_ends(((int64_t)(((*({ hrv *_t3234 = &(g703); int64_t _i3234 = n_1088; (S4*)_t3234->b + hr_ix(_i3234, _t3234->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:494"); }))).c_))));
 }
if (((k_1089) == (((int64_t)26LL)))) { return (!(f210_has_break(((int64_t)(((*({ hrv *_t3236 = &(g703); int64_t _i3236 = n_1088; (S4*)_t3236->b + hr_ix(_i3236, _t3236->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:495"); }))).a_)))));
 }
return false;
}
static bool f210_has_break(int64_t n_1091) {
if (((n_1091) < (((int64_t)0LL)))) { return false;
 }
S4 x_1092 = (*({ hrv *_t3237 = &(g703); int64_t _i3237 = n_1091; (S4*)_t3237->b + hr_ix(_i3237, _t3237->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:500"); })); 
int64_t k_1093 = ((int64_t)((x_1092).k_)); 
if (((k_1093) == (((int64_t)29LL)))) { return true;
 }
if (((((((k_1093) == (((int64_t)25LL))) || ((k_1093) == (((int64_t)26LL)))) || ((k_1093) == (((int64_t)27LL)))) || ((k_1093) == (((int64_t)50LL)))) || ((k_1093) == (((int64_t)31LL))))) { return false;
 }
if ((((k_1093) >= (((int64_t)40LL))) && ((k_1093) < (((int64_t)50LL))))) { return false;
 }
if (((k_1093) == (((int64_t)33LL)))) { return f210_has_break(((int64_t)((x_1092).b_)));
 }
if (((k_1093) == (((int64_t)11LL)))) { if (f210_has_break(((int64_t)((x_1092).a_)))) { return true;
 }
{ int32_t _e3241 = (x_1092).n_; for (int32_t _k3241 = 0; _k3241 < _e3241; _k3241++) { int32_t i_1094 = (int32_t)_k3241; if (f210_has_break(f90_kid(n_1091, ((int64_t)(i_1094))))) { return true;
 }
 } } _bk3240:; 
return false;
 }
if ((((f210_has_break(((int64_t)((x_1092).a_))) || f210_has_break(((int64_t)((x_1092).b_)))) || f210_has_break(((int64_t)((x_1092).c_)))) || f210_has_break(((int64_t)((x_1092).d_))))) { return true;
 }
if ((((((((k_1093) == (((int64_t)23LL))) || ((k_1093) == (((int64_t)20LL)))) || ((k_1093) == (((int64_t)36LL)))) || ((k_1093) == (((int64_t)16LL)))) || ((k_1093) == (((int64_t)17LL)))) || ((k_1093) == (((int64_t)28LL))))) { { int32_t _e3249 = (x_1092).n_; for (int32_t _k3249 = 0; _k3249 < _e3249; _k3249++) { int32_t i_1095 = (int32_t)_k3249; int64_t c_1096 = f90_kid(n_1091, ((int64_t)(i_1095))); 
if (f210_has_break(c_1096)) { return true;
 }
if ((((k_1093) == (((int64_t)20LL))) && f210_has_break(((int64_t)(((*({ hrv *_t3253 = &(g703); int64_t _i3253 = c_1096; (S4*)_t3253->b + hr_ix(_i3253, _t3253->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:511"); }))).b_))))) { return true;
 }
 } } _bk3248:; 
 }
return false;
}
static void f211_pop_block_fns(int64_t m_1099) {
if ((((g311).n) > (m_1099))) { (void)(({ hrv *_v3254 = &(g311); int64_t _k3254 = ((int64_t)((int64_t)(g311).n - (int64_t)m_1099)); if (_k3254 < 0 || _k3254 > _v3254->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:35"); _v3254->n -= _k3254; }));
 }
}
static int64_t f212_ck_if(int64_t n_1102, int64_t want_1103) {
S4 x_1104 = (*({ hrv *_t3255 = &(g703); int64_t _i3255 = n_1102; (S4*)_t3255->b + hr_ix(_i3255, _t3255->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:517"); })); 
int64_t c_1105 = f137_ck(((int64_t)((x_1104).a_)), g558); 
(void)(f140_conv(((int64_t)((x_1104).a_)), g558));
int64_t m_1106 = (g389).n; 
int64_t nm0_1107 = (g390).n; 
(void)(f177_narrow_push(((int64_t)((x_1104).a_))));
int64_t tb_1108 = f137_ck(((int64_t)((x_1104).b_)), want_1103); 
(void)(f178_narrow_pop(nm0_1107));
(void)(({ hrv *_v3261 = &(g389); int64_t _k3261 = ((int64_t)((int64_t)(g389).n - (int64_t)m_1106)); if (_k3261 < 0 || _k3261 > _v3261->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:525"); _v3261->n -= _k3261; }));
if ((((x_1104).c_) < (((int32_t)0LL)))) { return f138_set_t(n_1102, g557);
 }
int64_t tc_1109 = f137_ck(((int64_t)((x_1104).c_)), want_1103); 
bool eb_1110 = f209_ends(((int64_t)((x_1104).b_))); 
bool ec_1111 = f209_ends(((int64_t)((x_1104).c_))); 
if ((eb_1110 && (!(ec_1111)))) { return f138_set_t(n_1102, tc_1109);
 }
if ((ec_1111 && (!(eb_1110)))) { return f138_set_t(n_1102, tb_1108);
 }
if ((eb_1110 && ec_1111)) { return f138_set_t(n_1102, tb_1108);
 }
if ((((tb_1108) == (g557)) || ((tc_1109) == (g557)))) { return f138_set_t(n_1102, g557);
 }
if (((tb_1108) == (tc_1109))) { return f138_set_t(n_1102, tb_1108);
 }
if ((((((want_1103) >= (((int64_t)0LL))) && ((want_1103) != (g557))) && (f163_is_pending(tb_1108) || f151_conv_ok(tb_1108, want_1103, ((int64_t)((x_1104).b_))))) && (f163_is_pending(tc_1109) || f151_conv_ok(tc_1109, want_1103, ((int64_t)((x_1104).c_)))))) { (void)(f140_conv(((int64_t)((x_1104).b_)), want_1103));
(void)(f140_conv(((int64_t)((x_1104).c_)), want_1103));
return f138_set_t(n_1102, want_1103);
 }
int64_t u_1112 = f182_unify(n_1102, ((int64_t)((x_1104).b_)), ((int64_t)((x_1104).c_))); 
return f138_set_t(n_1102, u_1112);
}
static int64_t f213_ck_while(int64_t n_1113) {
S4 x_1114 = (*({ hrv *_t3280 = &(g703); int64_t _i3280 = n_1113; (S4*)_t3280->b + hr_ix(_i3280, _t3280->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:539"); })); 
int64_t c_1115 = f137_ck(((int64_t)((x_1114).a_)), g558); 
(void)(f140_conv(((int64_t)((x_1114).a_)), g558));
int64_t nm0_1116 = (g390).n; 
(void)(f177_narrow_push(((int64_t)((x_1114).a_))));
g406++;
(void)(f137_ck(((int64_t)((x_1114).b_)), g557));
g406--;
(void)(f178_narrow_pop(nm0_1116));
return f138_set_t(n_1113, g557);
}
static int64_t f214_ck_loop(int64_t n_1117, int64_t want_1118) {
(void)(({ hrv *_v3287 = &(g467); int32_t _x3287 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p3287 = (int32_t*)hr_grow(_v3287, 1, sizeof _x3287); *_p3287 = _x3287; _p3287; }));
g406++;
(void)(f137_ck(((int64_t)(((*({ hrv *_t3289 = &(g703); int64_t _i3289 = n_1117; (S4*)_t3289->b + hr_ix(_i3289, _t3289->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:554"); }))).a_)), g557));
g406--;
int64_t t_1119 = ((int64_t)(({ hrv *_v3290 = &(g467); if (!_v3290->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:556"); ((int32_t*)_v3290->b)[--_v3290->n]; }))); 
return f138_set_t(n_1117, ({ int64_t _r3292; if (((t_1119) < (((int64_t)0LL)))) { _r3292 = g557;  } else { _r3292 = t_1119;  } _r3292; }));
}
static int64_t f215_ck_for(int64_t n_1120) {
S4 x_1121 = (*({ hrv *_t3293 = &(g703); int64_t _i3293 = n_1120; (S4*)_t3293->b + hr_ix(_i3293, _t3293->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:560"); })); 
int64_t m_1122 = (g389).n; 
int64_t et_1123 = g562; 
if ((((x_1121).b_) >= (((int32_t)0LL)))) { int64_t ta_1124 = f137_ck(((int64_t)((x_1121).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t tb_1125 = f137_ck(((int64_t)((x_1121).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t u_1126 = f182_unify(n_1120, ((int64_t)((x_1121).a_)), ((int64_t)((x_1121).b_))); 
et_1123 = ({ int64_t _r3297; if (((((*({ hrv *_t3298 = &(g550); int64_t _i3298 = u_1126; (S1*)_t3298->b + hr_ix(_i3298, _t3298->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:566"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1121).a_)), g562));
(void)(f140_conv(((int64_t)((x_1121).b_)), g562));
_r3297 = g562;  } else { _r3297 = u_1126;  } _r3297; });
(void)(f175_set_x(n_1120, ((int64_t)0LL)));
 } else { int64_t t_1127 = f137_ck(((int64_t)((x_1121).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3303 = &(g550); int64_t _i3303 = t_1127; (S1*)_t3303->b + hr_ix(_i3303, _t3303->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:570"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_1121).a_)), g575));
t_1127 = g575;
 }
if (((((*({ hrv *_t3305 = &(g550); int64_t _i3305 = t_1127; (S1*)_t3305->b + hr_ix(_i3305, _t3305->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:571"); }))).k_) == (((uint8_t)19LL)))) { t_1127 = f184_default_t(((int64_t)((x_1121).a_)));
 }
int64_t d_1128 = f179_deref(t_1127); 
if (((((*({ hrv *_t3308 = &(g550); int64_t _i3308 = d_1128; (S1*)_t3308->b + hr_ix(_i3308, _t3308->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:573"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1121).a_)), g562));
et_1123 = g562;
(void)(f175_set_x(n_1120, ((int64_t)0LL)));
 } else { if ((((((*({ hrv *_t3311 = &(g550); int64_t _i3311 = d_1128; (S1*)_t3311->b + hr_ix(_i3311, _t3311->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:574"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t3312 = &(g550); int64_t _i3312 = d_1128; (S1*)_t3312->b + hr_ix(_i3312, _t3312->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:574"); }))).k_) == (((uint8_t)17LL))))) { et_1123 = ({ int64_t _r3313; if (((((*({ hrv *_t3314 = &(g550); int64_t _i3314 = d_1128; (S1*)_t3314->b + hr_ix(_i3314, _t3314->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:574"); }))).k_) == (((uint8_t)17LL)))) { _r3313 = g562;  } else { _r3313 = d_1128;  } _r3313; });
if (((et_1123) != (t_1127))) { (void)(f142_set_cv(((int64_t)((x_1121).a_)), et_1123));
 }
(void)(f175_set_x(n_1120, ((int64_t)0LL)));
 } else { if ((((((*({ hrv *_t3317 = &(g550); int64_t _i3317 = d_1128; (S1*)_t3317->b + hr_ix(_i3317, _t3317->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:575"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3318 = &(g550); int64_t _i3318 = d_1128; (S1*)_t3318->b + hr_ix(_i3318, _t3318->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:575"); }))).k_) == (((uint8_t)9LL))))) { et_1123 = f188_decode_rel(((int64_t)(((*({ hrv *_t3320 = &(g550); int64_t _i3320 = d_1128; (S1*)_t3320->b + hr_ix(_i3320, _t3320->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:575"); }))).a_)));
(void)(f175_set_x(n_1120, ((int64_t)1LL)));
 } else { hrv mm_1129 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t3324 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o3323 = &(mm_1129); hr_fs(_o3323, hr_str("cannot iterate over ", 20)); hr_fs(_o3323, hr_sl(*hr_tmp(&_t3324, f161_tn(d_1128)))); }));
}
(void)(f108_cerr(n_1120, hr_sl(mm_1129)));
 }
 }
 }
 }
if ((((x_1121).l_) >= (((int32_t)0LL)))) { et_1123 = f113_rtype(((int64_t)((x_1121).l_)), f110_ns_of(n_1120));
 }
bool byref_1131 = (((((uint16_t)((uint64_t)(x_1121).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || f216_is_bytes(et_1123)); 
int64_t v_1132 = f203_add_lv(((int64_t)((x_1121).s_)), ({ int64_t _r3331; if (byref_1131) { _r3331 = f119_t_ref(et_1123, ((int64_t)0LL));  } else { _r3331 = et_1123;  } _r3331; }), ((int64_t)((int64_t)((int64_t)16LL) | (int64_t)({ int64_t _r3333; if (byref_1131) { _r3333 = ((int64_t)8LL);  } else { _r3333 = ((int64_t)0LL);  } _r3333; }))), n_1120); 
(void)(f170_set_r(n_1120, ((int64_t)1LL), v_1132));
if ((((x_1121).c_) >= (((int32_t)0LL)))) { int64_t iv_1133 = f203_add_lv(((int64_t)((x_1121).c_)), ({ int64_t _r3336; if ((((x_1121).n_) >= (((int32_t)0LL)))) { _r3336 = f113_rtype(((int64_t)((x_1121).n_)), f110_ns_of(n_1120));  } else { _r3336 = g562;  } _r3336; }), ((int64_t)16LL), n_1120); 
(void)(f175_set_x(n_1120, ((int64_t)((int64_t)f217_ax(n_1120) | (int64_t)((int64_t)((iv_1133) << ((((int64_t)2LL)) & 63)))))));
 }
g406++;
(void)(f137_ck(((int64_t)((x_1121).d_)), g557));
g406--;
(void)(({ hrv *_v3342 = &(g389); int64_t _k3342 = ((int64_t)((int64_t)(g389).n - (int64_t)m_1122)); if (_k3342 < 0 || _k3342 > _v3342->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:586"); _v3342->n -= _k3342; }));
return f138_set_t(n_1120, g557);
}
static bool f216_is_bytes(int64_t t_1130) {
return ((((f143_tclass(t_1130)) == (((int64_t)1LL))) && ((((*({ hrv *_t3345 = &(g550); int64_t _i3345 = t_1130; (S1*)_t3345->b + hr_ix(_i3345, _t3345->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:93"); }))).k_) != (((uint8_t)17LL)))) && ((((*({ hrv *_t3346 = &(g550); int64_t _i3346 = t_1130; (S1*)_t3346->b + hr_ix(_i3346, _t3346->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:93"); }))).k_) != (((uint8_t)10LL))));
}
static int64_t f217_ax(int64_t n_1134) {
return ((int64_t)((*({ hrv *_t3347 = &(g398); int64_t _i3347 = f139_aix(n_1134); (int32_t*)_t3347->b + hr_ix(_i3347, _t3347->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:47"); }))));
}
static int64_t f218_ck_match(int64_t n_1135, int64_t want_1136) {
S4 x_1137 = (*({ hrv *_t3349 = &(g703); int64_t _i3349 = n_1135; (S4*)_t3349->b + hr_ix(_i3349, _t3349->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:590"); })); 
int64_t st_1138 = f137_ck(((int64_t)((x_1137).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3351 = &(g550); int64_t _i3351 = st_1138; (S1*)_t3351->b + hr_ix(_i3351, _t3351->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:592"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1137).a_)), g562));
st_1138 = g562;
 }
if (((((*({ hrv *_t3353 = &(g550); int64_t _i3353 = st_1138; (S1*)_t3353->b + hr_ix(_i3353, _t3353->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:593"); }))).k_) == (((uint8_t)7LL)))) { st_1138 = f136_t_enum(((int64_t)(((*({ hrv *_t3355 = &(g550); int64_t _i3355 = st_1138; (S1*)_t3355->b + hr_ix(_i3355, _t3355->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:593"); }))).a_)), false);
(void)(f142_set_cv(((int64_t)((x_1137).a_)), st_1138));
 }
int64_t d_1139 = f179_deref(st_1138); 
int64_t rt_1140 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
bool allv_1141 = true; 
{ int32_t _e3359 = (x_1137).n_; for (int32_t _k3359 = 0; _k3359 < _e3359; _k3359++) { int32_t i_1142 = (int32_t)_k3359; int64_t arm_1143 = f90_kid(n_1135, ((int64_t)(i_1142))); 
int64_t m_1144 = (g389).n; 
S4 ax0_1145 = (*({ hrv *_t3361 = &(g703); int64_t _i3361 = arm_1143; (S4*)_t3361->b + hr_ix(_i3361, _t3361->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:600"); })); 
if (((((uint16_t)((uint64_t)(ax0_1145).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) { { int32_t _e3363 = (ax0_1145).n_; for (int32_t _k3363 = 0; _k3363 < _e3363; _k3363++) { int32_t j_1146 = (int32_t)_k3363; int64_t it_1147 = f90_kid(arm_1143, ((int64_t)(j_1146))); 
int64_t lo_1148 = ((int64_t)(((*({ hrv *_t3365 = &(g703); int64_t _i3365 = it_1147; (S4*)_t3365->b + hr_ix(_i3365, _t3365->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:604"); }))).a_)); 
if ((((((*({ hrv *_t3366 = &(g550); int64_t _i3366 = d_1139; (S1*)_t3366->b + hr_ix(_i3366, _t3366->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:605"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t3367 = &(g703); int64_t _i3367 = lo_1148; (S4*)_t3367->b + hr_ix(_i3367, _t3367->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:605"); }))).k_) == (((uint8_t)8LL))))) { int64_t ei_1149 = ((int64_t)(((*({ hrv *_t3368 = &(g550); int64_t _i3368 = d_1139; (S1*)_t3368->b + hr_ix(_i3368, _t3368->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:606"); }))).a_)); 
int64_t found_1150 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e3370 = ((*({ hrv *_t3371 = &(g555); int64_t _i3371 = ei_1149; (S8*)_t3371->b + hr_ix(_i3371, _t3371->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:608"); }))).vnum_; for (int32_t _k3370 = 0; _k3370 < _e3370; _k3370++) { int32_t q_1151 = (int32_t)_k3370; if (((((*({ hrv *_t3372 = &(g556); int64_t _i3372 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3373 = &(g555); int64_t _i3373 = ei_1149; (S8*)_t3373->b + hr_ix(_i3373, _t3373->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:608"); }))).v0_)) + (int64_t)((int64_t)(q_1151)))); (S9*)_t3372->b + hr_ix(_i3372, _t3372->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:608"); }))).name_) == (((*({ hrv *_t3374 = &(g703); int64_t _i3374 = lo_1148; (S4*)_t3374->b + hr_ix(_i3374, _t3374->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:608"); }))).s_))) { found_1150 = ((int64_t)(q_1151));
 }
 } } _bk3369:; 
if (((found_1150) < (((int64_t)0LL)))) { hrv mm_1152 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t3379 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o3376 = &(mm_1152); hr_fs(_o3376, hr_str("no variant ", 11)); hr_fs(_o3376, f10_nm(((int64_t)(((*({ hrv *_t3378 = &(g703); int64_t _i3378 = lo_1148; (S4*)_t3378->b + hr_ix(_i3378, _t3378->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:609"); }))).s_)))); hr_fs(_o3376, hr_str(" in ", 4)); hr_fs(_o3376, hr_sl(*hr_tmp(&_t3379, f161_tn(d_1139)))); }));
}
(void)(f108_cerr(lo_1148, hr_sl(mm_1152)));
 }
(void)(f170_set_r(lo_1148, ((int64_t)7LL), found_1150));
(void)(f138_set_t(lo_1148, d_1139));
if (((((ax0_1145).s_) >= (((int32_t)0LL))) && ((found_1150) >= (((int64_t)0LL))))) { int64_t vt_1153 = f125_t_variant(ei_1149, found_1150); 
bool byr_1154 = (((((uint16_t)((uint64_t)(ax0_1145).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))) || f216_is_bytes(vt_1153)); 
int64_t v_1155 = f203_add_lv(((int64_t)((ax0_1145).s_)), ({ int64_t _r3387; if (byr_1154) { _r3387 = f119_t_ref(vt_1153, ((int64_t)0LL));  } else { _r3387 = vt_1153;  } _r3387; }), ({ int64_t _r3389; if (byr_1154) { _r3389 = ((int64_t)8LL);  } else { _r3389 = ((int64_t)0LL);  } _r3389; }), arm_1143); 
(void)(f170_set_r(arm_1143, ((int64_t)1LL), v_1155));
 }
 } else { (void)(f137_ck(lo_1148, d_1139));
(void)(f140_conv(lo_1148, d_1139));
if (((((*({ hrv *_t3393 = &(g703); int64_t _i3393 = it_1147; (S4*)_t3393->b + hr_ix(_i3393, _t3393->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:614"); }))).b_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)(((*({ hrv *_t3395 = &(g703); int64_t _i3395 = it_1147; (S4*)_t3395->b + hr_ix(_i3395, _t3395->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:614"); }))).b_)), d_1139));
(void)(f140_conv(((int64_t)(((*({ hrv *_t3397 = &(g703); int64_t _i3397 = it_1147; (S4*)_t3397->b + hr_ix(_i3397, _t3397->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:614"); }))).b_)), d_1139));
 }
 }
 } } _bk3362:; 
 }
int64_t bt_1156 = f137_ck(((int64_t)((ax0_1145).b_)), want_1136); 
(void)(({ hrv *_v3399 = &(g389); int64_t _k3399 = ((int64_t)((int64_t)(g389).n - (int64_t)m_1144)); if (_k3399 < 0 || _k3399 > _v3399->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:619"); _v3399->n -= _k3399; }));
if (((bt_1156) == (g557))) { allv_1141 = false;
 } else { if ((!(f209_ends(((int64_t)((ax0_1145).b_)))))) { if ((((rt_1140) < (((int64_t)0LL))) || f163_is_pending(rt_1140))) { rt_1140 = bt_1156;
 }
 }
 }
 } } _bk3358:; 
if (((!(allv_1141)) || ((rt_1140) < (((int64_t)0LL))))) { return f138_set_t(n_1135, g557);
 }
bool allw_1157 = (((want_1136) >= (((int64_t)0LL))) && ((want_1136) != (g557))); 
if (allw_1157) { { int32_t _e3404 = (x_1137).n_; for (int32_t _k3404 = 0; _k3404 < _e3404; _k3404++) { int32_t i_1158 = (int32_t)_k3404; int64_t b_1159 = ((int64_t)(((*({ hrv *_t3405 = &(g703); int64_t _i3405 = f90_kid(n_1135, ((int64_t)(i_1158))); (S4*)_t3405->b + hr_ix(_i3405, _t3405->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:624"); }))).b_)); 
int64_t bt_1160 = f141_at(b_1159); 
if ((((!(f209_ends(b_1159))) && (!(f163_is_pending(bt_1160)))) && (!(f151_conv_ok(bt_1160, want_1136, b_1159))))) { allw_1157 = false;
 }
 } } _bk3403:; 
 }
if (allw_1157) { { int32_t _e3412 = (x_1137).n_; for (int32_t _k3412 = 0; _k3412 < _e3412; _k3412++) { int32_t i_1161 = (int32_t)_k3412; int64_t b_1162 = ((int64_t)(((*({ hrv *_t3413 = &(g703); int64_t _i3413 = f90_kid(n_1135, ((int64_t)(i_1161))); (S4*)_t3413->b + hr_ix(_i3413, _t3413->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:625"); }))).b_)); 
if ((!(f209_ends(b_1162)))) { (void)(f140_conv(b_1162, want_1136));
 }
 } } _bk3411:; 
return f138_set_t(n_1135, want_1136);
 }
if (f163_is_pending(rt_1140)) { { int32_t _e3420 = (x_1137).n_; for (int32_t _k3420 = 0; _k3420 < _e3420; _k3420++) { int32_t i_1163 = (int32_t)_k3420; int64_t b_1164 = ((int64_t)(((*({ hrv *_t3421 = &(g703); int64_t _i3421 = f90_kid(n_1135, ((int64_t)(i_1163))); (S4*)_t3421->b + hr_ix(_i3421, _t3421->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:626"); }))).b_)); 
int64_t bt_1165 = f141_at(b_1164); 
if (((!(f163_is_pending(bt_1165))) && (!(f209_ends(b_1164))))) { rt_1140 = bt_1165;
 }
 } } _bk3419:; 
 }
if (f163_is_pending(rt_1140)) { int64_t b_1166 = ((int64_t)(((*({ hrv *_t3427 = &(g703); int64_t _i3427 = f90_kid(n_1135, ((int64_t)0LL)); (S4*)_t3427->b + hr_ix(_i3427, _t3427->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:627"); }))).b_)); 
rt_1140 = f184_default_t(b_1166);
 }
{ int32_t _e3431 = (x_1137).n_; for (int32_t _k3431 = 0; _k3431 < _e3431; _k3431++) { int32_t i_1167 = (int32_t)_k3431; int64_t b_1168 = ((int64_t)(((*({ hrv *_t3432 = &(g703); int64_t _i3432 = f90_kid(n_1135, ((int64_t)(i_1167))); (S4*)_t3432->b + hr_ix(_i3432, _t3432->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:628"); }))).b_)); 
if ((!(f209_ends(b_1168)))) { (void)(f140_conv(b_1168, rt_1140));
 }
 } } _bk3430:; 
return f138_set_t(n_1135, rt_1140);
}
static int64_t f219_ck_ret(int64_t n_1169) {
S4 x_1170 = (*({ hrv *_t3437 = &(g703); int64_t _i3437 = n_1169; (S4*)_t3437->b + hr_ix(_i3437, _t3437->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:640"); })); 
int64_t f_1174 = ({ int64_t _r3438; if ((((x_1170).s_) >= (((int32_t)0LL)))) { _r3438 = f220_find_from_fn(((int64_t)((x_1170).s_)));  } else { _r3438 = f221_ret_fn();  } _r3438; }); 
if (((f_1174) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1169, hr_str("return outside a function", 25)));
return g557;
 }
if (((f_1174) != (g401))) { { bool *_t3442 = &(((*({ hrv *_t3443 = &(g387); int64_t _i3443 = g401; (S6*)_t3443->b + hr_ix(_i3443, _t3443->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:643"); }))).lr_); *_t3442 = true; }
{ bool *_t3444 = &(((*({ hrv *_t3445 = &(g387); int64_t _i3445 = f_1174; (S6*)_t3445->b + hr_ix(_i3445, _t3445->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:643"); }))).tg_); *_t3444 = true; }
(void)(f175_set_x(n_1169, f_1174));
 } else { (void)(f175_set_x(n_1169, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
int64_t rt_1175 = ((int64_t)(((*({ hrv *_t3448 = &(g387); int64_t _i3448 = f_1174; (S6*)_t3448->b + hr_ix(_i3448, _t3448->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:644"); }))).ret_)); 
if ((((x_1170).n_) == (((int32_t)0LL)))) { if (((((rt_1175) >= (((int64_t)0LL))) && ((rt_1175) != (g557))) && (!(((*({ hrv *_t3449 = &(g387); int64_t _i3449 = f_1174; (S6*)_t3449->b + hr_ix(_i3449, _t3449->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:645"); }))).rinf_)))) { (void)(f108_cerr(n_1169, hr_str("return needs a value", 20)));
 }
if (((rt_1175) < (((int64_t)0LL)))) { { int32_t *_t3451 = &(((*({ hrv *_t3452 = &(g387); int64_t _i3452 = f_1174; (S6*)_t3452->b + hr_ix(_i3452, _t3452->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:645"); }))).ret_); *_t3451 = ((int32_t)(g557)); }
 }
return f138_set_t(n_1169, g557);
 }
if (((((rt_1175) >= (((int64_t)0LL))) && ((((*({ hrv *_t3454 = &(g550); int64_t _i3454 = rt_1175; (S1*)_t3454->b + hr_ix(_i3454, _t3454->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:646"); }))).k_) == (((uint8_t)14LL)))) && (((x_1170).n_) == (((int32_t)1LL))))) { int64_t c_1176 = f90_kid(n_1169, ((int64_t)0LL)); 
(void)(f137_ck(c_1176, rt_1175));
return f138_set_t(n_1169, g557);
 }
if ((((x_1170).n_) > (((int32_t)1LL)))) { if (((rt_1175) < (((int64_t)0LL)))) { L89 ts_1177 = ({ L89 _t3458; memset(&_t3458, 0, sizeof _t3458); _t3458.n = 0; _t3458; }); 
{ int32_t _e3460 = (x_1170).n_; for (int32_t _k3460 = 0; _k3460 < _e3460; _k3460++) { int32_t i_1178 = (int32_t)_k3460; (void)(f137_ck(f90_kid(n_1169, ((int64_t)(i_1178))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
int64_t dt0_1179 = f184_default_t(f90_kid(n_1169, ((int64_t)(i_1178)))); 
(void)(({ L89 *_v3465 = &(ts_1177); int32_t _x3465 = ((int32_t)(dt0_1179)); if (_v3465->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:648"); _v3465->e[_v3465->n] = _x3465; &_v3465->e[_v3465->n++]; }));
 } } _bk3459:; 
{ int32_t *_t3466 = &(((*({ hrv *_t3467 = &(g387); int64_t _i3467 = f_1174; (S6*)_t3467->b + hr_ix(_i3467, _t3467->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:648"); }))).ret_); *_t3466 = ((int32_t)(f197_tlist(((int64_t)14LL), ({ hsl _t3469 = ({ L89 *_t3470 = &(ts_1177); (hsl){ (uint8_t*)_t3470->e, _t3470->n }; }); int64_t _l3469 = 0, _h3469 = _t3469.n; if (_l3469 < 0 || _h3469 < _l3469 || _h3469 > _t3469.n) hr_slerr(_l3469, _h3469, _t3469.n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:648"); (hsl){ _t3469.p + _l3469 * (int64_t)sizeof(int32_t), _h3469 - _l3469 }; }), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); }
return f138_set_t(n_1169, g557);
 }
{ int32_t _e3473 = (x_1170).n_; for (int32_t _k3473 = 0; _k3473 < _e3473; _k3473++) { int32_t i_1180 = (int32_t)_k3473; int64_t et_1181 = ({ int64_t _r3474; if ((((((*({ hrv *_t3475 = &(g550); int64_t _i3475 = rt_1175; (S1*)_t3475->b + hr_ix(_i3475, _t3475->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:649"); }))).k_) == (((uint8_t)14LL))) && ((((int64_t)(i_1180))) < (((int64_t)(((*({ hrv *_t3476 = &(g550); int64_t _i3476 = rt_1175; (S1*)_t3476->b + hr_ix(_i3476, _t3476->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:649"); }))).n_)))))) { _r3474 = ((int64_t)((*({ hrv *_t3477 = &(g551); int64_t _i3477 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3478 = &(g550); int64_t _i3478 = rt_1175; (S1*)_t3478->b + hr_ix(_i3478, _t3478->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:649"); }))).l_)) + (int64_t)((int64_t)(i_1180)))); (int32_t*)_t3477->b + hr_ix(_i3477, _t3477->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:649"); }))));  } else { _r3474 = g574;  } _r3474; }); 
(void)(f137_ck(f90_kid(n_1169, ((int64_t)(i_1180))), et_1181));
(void)(f140_conv(f90_kid(n_1169, ((int64_t)(i_1180))), et_1181));
 } } _bk3472:; 
return f138_set_t(n_1169, g557);
 }
int64_t c_1182 = f90_kid(n_1169, ((int64_t)0LL)); 
if (((rt_1175) < (((int64_t)0LL)))) { (void)(f137_ck(c_1182, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
int64_t t_1183 = f184_default_t(c_1182); 
{ int32_t *_t3487 = &(((*({ hrv *_t3488 = &(g387); int64_t _i3488 = f_1174; (S6*)_t3488->b + hr_ix(_i3488, _t3488->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:653"); }))).ret_); *_t3487 = ((int32_t)(t_1183)); }
return f138_set_t(n_1169, g557);
 }
(void)(f137_ck(c_1182, rt_1175));
(void)(f140_conv(c_1182, rt_1175));
return f138_set_t(n_1169, g557);
}
static int64_t f220_find_from_fn(int64_t name_1171) {
int64_t i_1172 = g400; 
while (((i_1172) >= (((int64_t)0LL)))) { if (((((((*({ hrv *_t3494 = &(g387); int64_t _i3494 = i_1172; (S6*)_t3494->b + hr_ix(_i3494, _t3494->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:634"); }))).node_) >= (((int32_t)0LL))) && ((((*({ hrv *_t3495 = &(g703); int64_t _i3495 = ((*({ hrv *_t3496 = &(g387); int64_t _i3496 = i_1172; (S6*)_t3496->b + hr_ix(_i3496, _t3496->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:634"); }))).node_; (S4*)_t3495->b + hr_ix(_i3495, _t3495->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:634"); }))).k_) == (((uint8_t)50LL)))) && ((((int64_t)(((*({ hrv *_t3497 = &(g387); int64_t _i3497 = i_1172; (S6*)_t3497->b + hr_ix(_i3497, _t3497->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:634"); }))).name_))) == (name_1171)))) { return i_1172;
 }
i_1172 = ({ int64_t _r3498; if (((((*({ hrv *_t3499 = &(g387); int64_t _i3499 = i_1172; (S6*)_t3499->b + hr_ix(_i3499, _t3499->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:635"); }))).bown_) >= (((int32_t)0LL)))) { _r3498 = ((int64_t)(((*({ hrv *_t3500 = &(g387); int64_t _i3500 = i_1172; (S6*)_t3500->b + hr_ix(_i3500, _t3500->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:635"); }))).bown_));  } else { _r3498 = ((int64_t)(((*({ hrv *_t3501 = &(g387); int64_t _i3501 = i_1172; (S6*)_t3501->b + hr_ix(_i3501, _t3501->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:635"); }))).par_));  } _r3498; });
 } _bk3493:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f221_ret_fn(void) {
int64_t i_1173 = g400; 
while (((i_1173) >= (((int64_t)0LL)))) { if ((((((*({ hrv *_t3503 = &(g387); int64_t _i3503 = i_1173; (S6*)_t3503->b + hr_ix(_i3503, _t3503->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:657"); }))).node_) >= (((int32_t)0LL))) && ((((*({ hrv *_t3504 = &(g703); int64_t _i3504 = ((*({ hrv *_t3505 = &(g387); int64_t _i3505 = i_1173; (S6*)_t3505->b + hr_ix(_i3505, _t3505->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:657"); }))).node_; (S4*)_t3504->b + hr_ix(_i3504, _t3504->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:657"); }))).k_) == (((uint8_t)50LL))))) { return i_1173;
 }
i_1173 = ((int64_t)(((*({ hrv *_t3506 = &(g387); int64_t _i3506 = i_1173; (S6*)_t3506->b + hr_ix(_i3506, _t3506->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:657"); }))).par_));
 } _bk3502:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f222_ck_break(int64_t n_1184) {
S4 x_1185 = (*({ hrv *_t3507 = &(g703); int64_t _i3507 = n_1184; (S4*)_t3507->b + hr_ix(_i3507, _t3507->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:659"); })); 
if ((((x_1185).a_) >= (((int32_t)0LL)))) { if ((((g467).n) == (((int64_t)0LL)))) { (void)(f108_cerr(n_1184, hr_str("break with a value outside loop or block", 40)));
return g557;
 }
int64_t w_1186 = ((int64_t)((*({ hrv *_t3509 = &(g467); int64_t _i3509 = ((int64_t)((int64_t)(g467).n - (int64_t)((int64_t)1LL))); (int32_t*)_t3509->b + hr_ix(_i3509, _t3509->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:662"); })))); 
int64_t t_1187 = f137_ck(((int64_t)((x_1185).a_)), ({ int64_t _r3511; if (((w_1186) >= (((int64_t)0LL)))) { _r3511 = w_1186;  } else { _r3511 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3511; })); 
if (((w_1186) < (((int64_t)0LL)))) { { int32_t *_t3512 = &((*({ hrv *_t3513 = &(g467); int64_t _i3513 = ((int64_t)((int64_t)(g467).n - (int64_t)((int64_t)1LL))); (int32_t*)_t3513->b + hr_ix(_i3513, _t3513->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:664"); }))); *_t3512 = ((int32_t)(f184_default_t(((int64_t)((x_1185).a_))))); }
 } else { (void)(f140_conv(((int64_t)((x_1185).a_)), w_1186));
 }
 }
return f138_set_t(n_1184, g557);
}
static int64_t f223_ck_call(int64_t n_1188, int64_t want_1189) {
S4 x_1190 = (*({ hrv *_t3517 = &(g703); int64_t _i3517 = n_1188; (S4*)_t3517->b + hr_ix(_i3517, _t3517->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:256"); })); 
int64_t cal_1191 = ((int64_t)((x_1190).a_)); 
int64_t ck__1192 = ((int64_t)(((*({ hrv *_t3518 = &(g703); int64_t _i3518 = cal_1191; (S4*)_t3518->b + hr_ix(_i3518, _t3518->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:258"); }))).k_)); 
if (((ck__1192) == (((int64_t)8LL)))) { int64_t name_1193 = ((int64_t)(((*({ hrv *_t3519 = &(g703); int64_t _i3519 = cal_1191; (S4*)_t3519->b + hr_ix(_i3519, _t3519->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:260"); }))).s_)); 
int64_t v_1194 = f167_find_lv(name_1193); 
int64_t nf_1197 = f224_find_nest(name_1193); 
if ((((v_1194) < (((int64_t)0LL))) && ((nf_1197) >= (((int64_t)0LL))))) { return f225_call_nested(n_1188, nf_1197);
 }
if (((v_1194) < (((int64_t)0LL)))) { int64_t bg_1234 = f230_block_binding(name_1193); 
if (((bg_1234) >= (((int64_t)0LL)))) { return f235_call_block(n_1188, bg_1234);
 }
int64_t b_1264 = f237_builtin_of(f10_nm(name_1193)); 
if (((((b_1264) >= (((int64_t)0LL))) && (!((((b_1264) == (((int64_t)3LL))) && f238_user_format(n_1188))))) && (!((((b_1264) == (((int64_t)9LL))) && false))))) { return f240_ck_builtin(n_1188, b_1264, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), want_1189);
 }
return f254_call_fn(n_1188, name_1193, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), want_1189);
 }
 }
if (((ck__1192) == (((int64_t)14LL)))) { int64_t obj_1444 = ((int64_t)(((*({ hrv *_t3530 = &(g703); int64_t _i3530 = cal_1191; (S4*)_t3530->b + hr_ix(_i3530, _t3530->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:273"); }))).a_)); 
int64_t name_1445 = ((int64_t)(((*({ hrv *_t3531 = &(g703); int64_t _i3531 = cal_1191; (S4*)_t3531->b + hr_ix(_i3531, _t3531->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:274"); }))).s_)); 
if ((((((((*({ hrv *_t3532 = &(g703); int64_t _i3532 = obj_1444; (S4*)_t3532->b + hr_ix(_i3532, _t3532->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:275"); }))).k_) == (((uint8_t)8LL))) && ((f167_find_lv(((int64_t)(((*({ hrv *_t3534 = &(g703); int64_t _i3534 = obj_1444; (S4*)_t3534->b + hr_ix(_i3534, _t3534->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:275"); }))).s_)))) < (((int64_t)0LL)))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t3536 = &(g703); int64_t _i3536 = obj_1444; (S4*)_t3536->b + hr_ix(_i3536, _t3536->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:275"); }))).s_)), f110_ns_of(obj_1444), ((int64_t)2LL))) >= (((int64_t)0LL)))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t3539 = &(g703); int64_t _i3539 = obj_1444; (S4*)_t3539->b + hr_ix(_i3539, _t3539->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:275"); }))).s_)), f110_ns_of(obj_1444), ((int64_t)5LL))) < (((int64_t)0LL))))) { (void)(f108_cerr(n_1188, hr_str("a variant is constructed with { }", 33)));
return f138_set_t(n_1188, g574);
 }
int64_t ot_1446 = f137_ck(obj_1444, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3544 = &(g550); int64_t _i3544 = ot_1446; (S1*)_t3544->b + hr_ix(_i3544, _t3544->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:277"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(obj_1444, g575));
ot_1446 = g575;
 }
int64_t d_1447 = f179_deref(ot_1446); 
int64_t mb_1449 = f255_member_of(f10_nm(name_1445)); 
if ((((mb_1449) >= (((int64_t)0LL))) && (((((*({ hrv *_t3549 = &(g550); int64_t _i3549 = d_1447; (S1*)_t3549->b + hr_ix(_i3549, _t3549->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:280"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3550 = &(g550); int64_t _i3550 = d_1447; (S1*)_t3550->b + hr_ix(_i3550, _t3550->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:280"); }))).k_) == (((uint8_t)9LL)))))) { return f240_ck_builtin(n_1188, mb_1449, obj_1444, want_1189);
 }
if (((((((*({ hrv *_t3552 = &(g550); int64_t _i3552 = ot_1446; (S1*)_t3552->b + hr_ix(_i3552, _t3552->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:281"); }))).k_) == (((uint8_t)19LL))) || ((((*({ hrv *_t3553 = &(g550); int64_t _i3553 = ot_1446; (S1*)_t3553->b + hr_ix(_i3553, _t3553->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:281"); }))).k_) == (((uint8_t)12LL)))) || ((((*({ hrv *_t3554 = &(g550); int64_t _i3554 = ot_1446; (S1*)_t3554->b + hr_ix(_i3554, _t3554->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:281"); }))).k_) == (((uint8_t)13LL))))) { (void)(f184_default_t(obj_1444));
 }
int64_t b_1450 = f237_builtin_of(f10_nm(name_1445)); 
if ((((((b_1450) == (((int64_t)3LL))) || ((b_1450) == (((int64_t)30LL)))) || ((b_1450) == (((int64_t)31LL)))) || ((b_1450) == (((int64_t)7LL))))) { return f240_ck_builtin(n_1188, b_1450, obj_1444, want_1189);
 }
(void)(f175_set_x(n_1188, ((int64_t)1LL)));
return f254_call_fn(n_1188, name_1445, obj_1444, want_1189);
 }
(void)(f108_cerr(n_1188, hr_str("this call's callee is not supported yet", 39)));
return f138_set_t(n_1188, g574);
}
static int64_t f224_find_nest(int64_t name_1195) {
int64_t i_1196 = ((int64_t)((int64_t)(g311).n - (int64_t)((int64_t)1LL))); 
while (((i_1196) >= (((int64_t)0LL)))) { if ((((((int64_t)(((*({ hrv *_t3564 = &(g311); int64_t _i3564 = i_1196; (S14*)_t3564->b + hr_ix(_i3564, _t3564->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:23"); }))).name_))) == (name_1195)) && f168_visible(((int64_t)(((*({ hrv *_t3566 = &(g311); int64_t _i3566 = i_1196; (S14*)_t3566->b + hr_ix(_i3566, _t3566->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:23"); }))).own_))))) { return i_1196;
 }
i_1196--;
 } _bk3563:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f225_call_nested(int64_t n_1198, int64_t nf_1199) {
int64_t i_1200 = ((int64_t)(((*({ hrv *_t3567 = &(g311); int64_t _i3567 = nf_1199; (S14*)_t3567->b + hr_ix(_i3567, _t3567->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:372"); }))).inst_)); 
int64_t s_1207 = f226_ck_args(n_1198, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
{ int32_t _e3570 = ((*({ hrv *_t3571 = &(g703); int64_t _i3571 = n_1198; (S4*)_t3571->b + hr_ix(_i3571, _t3571->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:374"); }))).n_; for (int32_t _k3570 = 0; _k3570 < _e3570; _k3570++) { int32_t j_1208 = (int32_t)_k3570; int64_t c_1209 = f90_kid(n_1198, ((int64_t)(j_1208))); 
if (((((int64_t)(j_1208))) < (((int64_t)(((*({ hrv *_t3573 = &(g387); int64_t _i3573 = i_1200; (S6*)_t3573->b + hr_ix(_i3573, _t3573->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:374"); }))).pn_))))) { (void)(f140_conv(c_1209, f208_ptype_of(i_1200, ((int64_t)(j_1208)))));
 }
 } } _bk3569:; 
(void)(f227_pop_args(s_1207));
(void)(f228_note_caps_of(i_1200));
(void)(f229_note_edge(i_1200));
(void)(f170_set_r(n_1198, ((int64_t)3LL), i_1200));
return f138_set_t(n_1198, ({ int64_t _r3581; if (((((*({ hrv *_t3582 = &(g387); int64_t _i3582 = i_1200; (S6*)_t3582->b + hr_ix(_i3582, _t3582->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:378"); }))).ret_) >= (((int32_t)0LL)))) { _r3581 = ((int64_t)(((*({ hrv *_t3583 = &(g387); int64_t _i3583 = i_1200; (S6*)_t3583->b + hr_ix(_i3583, _t3583->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:378"); }))).ret_));  } else { _r3581 = g557;  } _r3581; }));
}
static int64_t f226_ck_args(int64_t n_1201, int64_t a0n_1202, int64_t first_1203) {
int64_t start_1204 = (g407).n; 
if (((first_1203) >= (((int64_t)0LL)))) { (void)(({ hrv *_v3584 = &(g407); int32_t _x3584 = ((int32_t)(f141_at(first_1203))); int32_t *_p3584 = (int32_t*)hr_grow(_v3584, 1, sizeof _x3584); *_p3584 = _x3584; _p3584; }));
(void)(({ hrv *_v3586 = &(g315); int32_t _x3586 = ((int32_t)(first_1203)); int32_t *_p3586 = (int32_t*)hr_grow(_v3586, 1, sizeof _x3586); *_p3586 = _x3586; _p3586; }));
 }
{ int32_t _e3588 = ((*({ hrv *_t3589 = &(g703); int64_t _i3589 = n_1201; (S4*)_t3589->b + hr_ix(_i3589, _t3589->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:251"); }))).n_; for (int32_t _k3588 = 0; _k3588 < _e3588; _k3588++) { int32_t i_1205 = (int32_t)_k3588; int64_t c_1206 = f90_kid(n_1201, ((int64_t)(i_1205))); 
(void)(({ hrv *_v3591 = &(g407); int32_t _x3591 = ((int32_t)(f137_ck(c_1206, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p3591 = (int32_t*)hr_grow(_v3591, 1, sizeof _x3591); *_p3591 = _x3591; _p3591; }));
(void)(({ hrv *_v3593 = &(g315); int32_t _x3593 = ((int32_t)(c_1206)); int32_t *_p3593 = (int32_t*)hr_grow(_v3593, 1, sizeof _x3593); *_p3593 = _x3593; _p3593; }));
 } } _bk3587:; 
return start_1204;
}
static void f227_pop_args(int64_t s_1210) {
(void)(({ hrv *_v3594 = &(g407); int64_t _k3594 = ((int64_t)((int64_t)(g407).n - (int64_t)s_1210)); if (_k3594 < 0 || _k3594 > _v3594->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:254"); _v3594->n -= _k3594; }));
(void)(({ hrv *_v3595 = &(g315); int64_t _k3595 = ((int64_t)((int64_t)(g315).n - (int64_t)s_1210)); if (_k3595 < 0 || _k3595 > _v3595->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:254"); _v3595->n -= _k3595; }));
}
static void f228_note_caps_of(int64_t i_1211) {
{ hrv *_v3597 = &(g391); for (int64_t _k3597 = 0; _k3597 < _v3597->n; _k3597++) { S13 c_1212 = ((S13*)_v3597->b)[_k3597]; if (((((int64_t)((c_1212).inst_))) == (i_1211))) { int64_t v_1213 = ((int64_t)((c_1212).lv_)); 
if (((((int64_t)(((*({ hrv *_t3598 = &(g388); int64_t _i3598 = v_1213; (S12*)_t3598->b + hr_ix(_i3598, _t3598->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:381"); }))).cfn_))) != (g401))) { (void)(f171_note_cap(v_1213));
 }
 }
 } } _bk3596:; 
}
static void f229_note_edge(int64_t callee_1214) {
if (((((g401) < (((int64_t)0LL))) || ((callee_1214) < (((int64_t)0LL)))) || ((g401) == (callee_1214)))) { return;
 }
{ hrv *_v3601 = &(g392); for (int64_t _k3601 = 0; _k3601 < _v3601->n; _k3601++) { S15 e_1215 = ((S15*)_v3601->b)[_k3601]; if ((((((int64_t)((e_1215).caller_))) == (g401)) && ((((int64_t)((e_1215).callee_))) == (callee_1214)))) { return;
 }
 } } _bk3600:; 
(void)(({ hrv *_v3602 = &(g392); S15 _x3602 = ((S15){ .caller_ = ((int32_t)(g401)), .callee_ = ((int32_t)(callee_1214)), }); S15 *_p3602 = (S15*)hr_grow(_v3602, 1, sizeof _x3602); *_p3602 = _x3602; _p3602; }));
}
static int64_t f230_block_binding(int64_t name_1216) {
int64_t i_1217 = g400; 
while (((i_1217) >= (((int64_t)0LL)))) { S6 f_1218 = (*({ hrv *_t3604 = &(g387); int64_t _i3604 = i_1217; (S6*)_t3604->b + hr_ix(_i3604, _t3604->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:334"); })); 
if ((((f_1218).blk_) >= (((int32_t)0LL)))) { int64_t fnode_1219 = ((int64_t)((f_1218).node_)); 
if (((f231_blk_gen(fnode_1219)) == (name_1216))) { return i_1217;
 }
 }
i_1217 = ((int64_t)((f_1218).par_));
 } _bk3603:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f231_blk_gen(int64_t fnode_1220) {
int64_t gl_1222 = f232_gen_list(fnode_1220); 
if (((gl_1222) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
{ int32_t _e3608 = ((*({ hrv *_t3609 = &(g703); int64_t _i3609 = gl_1222; (S4*)_t3609->b + hr_ix(_i3609, _t3609->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:59"); }))).n_; for (int32_t _k3608 = 0; _k3608 < _e3608; _k3608++) { int32_t i_1223 = (int32_t)_k3608; int64_t g_1224 = ((int64_t)(((*({ hrv *_t3610 = &(g703); int64_t _i3610 = f90_kid(gl_1222, ((int64_t)(i_1223))); (S4*)_t3610->b + hr_ix(_i3610, _t3610->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:59"); }))).s_)); 
if (f233_is_blockparam(fnode_1220, g_1224)) { return g_1224;
 }
 } } _bk3607:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f232_gen_list(int64_t fnode_1221) {
return ((int64_t)(((*({ hrv *_t3613 = &(g703); int64_t _i3613 = fnode_1221; (S4*)_t3613->b + hr_ix(_i3613, _t3613->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:47"); }))).d_));
}
static bool f233_is_blockparam(int64_t fnode_1225, int64_t gname_1226) {
{ int32_t _e3615 = ((*({ hrv *_t3616 = &(g703); int64_t _i3616 = fnode_1225; (S4*)_t3616->b + hr_ix(_i3616, _t3616->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:49"); }))).n_; for (int32_t _k3615 = 0; _k3615 < _e3615; _k3615++) { int32_t i_1227 = (int32_t)_k3615; int64_t p_1228 = f90_kid(fnode_1225, ((int64_t)(i_1227))); 
if ((((((*({ hrv *_t3618 = &(g703); int64_t _i3618 = p_1228; (S4*)_t3618->b + hr_ix(_i3618, _t3618->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:49"); }))).a_) >= (((int32_t)0LL))) && f234_mentions(((int64_t)(((*({ hrv *_t3620 = &(g703); int64_t _i3620 = p_1228; (S4*)_t3620->b + hr_ix(_i3620, _t3620->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:49"); }))).a_)), gname_1226))) { return false;
 }
 } } _bk3614:; 
return true;
}
static bool f234_mentions(int64_t t_1229, int64_t g_1230) {
if (((t_1229) < (((int64_t)0LL)))) { return false;
 }
S4 x_1231 = (*({ hrv *_t3621 = &(g703); int64_t _i3621 = t_1229; (S4*)_t3621->b + hr_ix(_i3621, _t3621->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:54"); })); 
int64_t k_1232 = ((int64_t)((x_1231).k_)); 
if (((k_1232) == (((int64_t)41LL)))) { if (((((int64_t)((x_1231).s_))) == (g_1230))) { return true;
 }
{ int32_t _e3623 = (x_1231).n_; for (int32_t _k3623 = 0; _k3623 < _e3623; _k3623++) { int32_t i_1233 = (int32_t)_k3623; if (f234_mentions(f90_kid(t_1229, ((int64_t)(i_1233))), g_1230)) { return true;
 }
 } } _bk3622:; 
return false;
 }
if (((((((k_1232) == (((int64_t)42LL))) || ((k_1232) == (((int64_t)43LL)))) || ((k_1232) == (((int64_t)44LL)))) || ((k_1232) == (((int64_t)48LL)))) || ((k_1232) == (((int64_t)46LL))))) { return f234_mentions(((int64_t)((x_1231).a_)), g_1230);
 }
return false;
}
static int64_t f235_call_block(int64_t n_1235, int64_t inst_1236) {
int64_t fv_1237 = ((int64_t)(((*({ hrv *_t3627 = &(g387); int64_t _i3627 = inst_1236; (S6*)_t3627->b + hr_ix(_i3627, _t3627->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:341"); }))).blk_)); 
int64_t own_1238 = ((int64_t)(((*({ hrv *_t3628 = &(g387); int64_t _i3628 = inst_1236; (S6*)_t3628->b + hr_ix(_i3628, _t3628->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:342"); }))).bown_)); 
int64_t s_1239 = f226_ck_args(n_1235, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t na_1240 = ((int64_t)(((*({ hrv *_t3630 = &(g703); int64_t _i3630 = n_1235; (S4*)_t3630->b + hr_ix(_i3630, _t3630->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:344"); }))).n_)); 
{ int64_t _e3632 = na_1240; for (int64_t _k3632 = 0; _k3632 < _e3632; _k3632++) { int64_t j_1241 = (int64_t)_k3632; int64_t c_1242 = f90_kid(n_1235, j_1241); 
if (f163_is_pending(f141_at(c_1242))) { { int32_t *_t3636 = &((*({ hrv *_t3637 = &(g407); int64_t _i3637 = ((int64_t)((int64_t)s_1239 + (int64_t)j_1241)); (int32_t*)_t3637->b + hr_ix(_i3637, _t3637->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:345"); }))); *_t3636 = ((int32_t)(f184_default_t(c_1242))); }
 } else { { int32_t *_t3639 = &((*({ hrv *_t3640 = &(g407); int64_t _i3640 = ((int64_t)((int64_t)s_1239 + (int64_t)j_1241)); (int32_t*)_t3640->b + hr_ix(_i3640, _t3640->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:345"); }))); *_t3639 = ((int32_t)(f236_deref_val(f141_at(c_1242)))); }
 }
 } } _bk3631:; 
int64_t bi_1245 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v3644 = &(g387); for (int64_t _k3644 = 0; _k3644 < _v3644->n; _k3644++) { S6 f_1246 = ((S6*)_v3644->b)[_k3644]; int64_t i_1247 = (int64_t)_k3644; if (((((((int64_t)((f_1246).node_))) == (fv_1237)) && ((((int64_t)((f_1246).par_))) == (own_1238))) && (((f_1246).blk_) == (((int32_t)(inst_1236)))))) { bi_1245 = i_1247;
 }
 } } _bk3643:; 
if (((bi_1245) < (((int64_t)0LL)))) { bi_1245 = f105_new_inst(fv_1237, fv_1237, ((int64_t)((*({ hrv *_t3646 = &(g718); int64_t _i3646 = fv_1237; (int32_t*)_t3646->b + hr_ix(_i3646, _t3646->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:349"); })))), own_1238);
{ int32_t *_t3647 = &(((*({ hrv *_t3648 = &(g387); int64_t _i3648 = bi_1245; (S6*)_t3648->b + hr_ix(_i3648, _t3648->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:350"); }))).blk_); *_t3647 = ((int32_t)(inst_1236)); }
{ int32_t *_t3649 = &(((*({ hrv *_t3650 = &(g387); int64_t _i3650 = bi_1245; (S6*)_t3650->b + hr_ix(_i3650, _t3650->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:350"); }))).bown_); *_t3649 = ((int32_t)(own_1238)); }
{ int32_t *_t3651 = &(((*({ hrv *_t3652 = &(g387); int64_t _i3652 = bi_1245; (S6*)_t3652->b + hr_ix(_i3652, _t3652->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:351"); }))).cfn_); *_t3651 = ((int32_t)(g401)); }
int64_t sa_1248 = g400; 
int64_t sm_1249 = (g389).n; 
int64_t bt_1250 = (g467).n; 
int64_t ld_1251 = g406; 
g400 = bi_1245;
g406 = ((int64_t)0LL);
int64_t np_1252 = ((int64_t)(((*({ hrv *_t3653 = &(g703); int64_t _i3653 = fv_1237; (S4*)_t3653->b + hr_ix(_i3653, _t3653->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:354"); }))).n_)); 
if (((((uint16_t)((uint64_t)((*({ hrv *_t3654 = &(g703); int64_t _i3654 = fv_1237; (S4*)_t3654->b + hr_ix(_i3654, _t3654->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:355"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { int64_t _e3656 = np_1252; for (int64_t _k3656 = 0; _k3656 < _e3656; _k3656++) { int64_t j_1253 = (int64_t)_k3656; int64_t p_1254 = f90_kid(fv_1237, j_1253); 
int64_t pt_1255 = ({ int64_t _r3658; if (((j_1253) < (na_1240))) { _r3658 = ((int64_t)((*({ hrv *_t3659 = &(g407); int64_t _i3659 = ((int64_t)((int64_t)s_1239 + (int64_t)j_1253)); (int32_t*)_t3659->b + hr_ix(_i3659, _t3659->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:355"); }))));  } else { _r3658 = g574;  } _r3658; }); 
int64_t v_1256 = f203_add_lv(((int64_t)(((*({ hrv *_t3661 = &(g703); int64_t _i3661 = p_1254; (S4*)_t3661->b + hr_ix(_i3661, _t3661->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:355"); }))).s_)), pt_1255, ((int64_t)32LL), p_1254); 
(void)(f170_set_r(p_1254, ((int64_t)1LL), v_1256));
 } } _bk3655:; 
 } else { if (((na_1240) >= (((int64_t)1LL)))) { int64_t v_1257 = f203_add_lv(f8_intern(hr_str("it", 2)), ((int64_t)((*({ hrv *_t3665 = &(g407); int64_t _i3665 = s_1239; (int32_t*)_t3665->b + hr_ix(_i3665, _t3665->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:356"); })))), ((int64_t)32LL), fv_1237); 
(void)(f170_set_r(fv_1237, ((int64_t)1LL), v_1257));
 }
 }
int64_t body_1258 = ((int64_t)(((*({ hrv *_t3667 = &(g703); int64_t _i3667 = fv_1237; (S4*)_t3667->b + hr_ix(_i3667, _t3667->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:357"); }))).a_)); 
int64_t bt0_1259 = f137_ck(body_1258, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t rt_1260 = g557; 
if ((((((*({ hrv *_t3669 = &(g703); int64_t _i3669 = body_1258; (S4*)_t3669->b + hr_ix(_i3669, _t3669->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:360"); }))).a_) >= (((int32_t)0LL))) && ((bt0_1259) != (g557)))) { rt_1260 = ({ int64_t _r3670; if (f163_is_pending(bt0_1259)) { _r3670 = f184_default_t(((int64_t)(((*({ hrv *_t3673 = &(g703); int64_t _i3673 = body_1258; (S4*)_t3673->b + hr_ix(_i3673, _t3673->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:360"); }))).a_)));  } else { _r3670 = bt0_1259;  } _r3670; });
 }
{ int32_t *_t3674 = &(((*({ hrv *_t3675 = &(g387); int64_t _i3675 = bi_1245; (S6*)_t3675->b + hr_ix(_i3675, _t3675->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:361"); }))).ret_); *_t3674 = ((int32_t)(rt_1260)); }
(void)(({ hrv *_v3676 = &(g389); int64_t _k3676 = ((int64_t)((int64_t)(g389).n - (int64_t)sm_1249)); if (_k3676 < 0 || _k3676 > _v3676->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:362"); _v3676->n -= _k3676; }));
while ((((g467).n) > (bt_1250))) { (void)(({ hrv *_v3678 = &(g467); if (!_v3678->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:362"); ((int32_t*)_v3678->b)[--_v3678->n]; }));
 } _bk3677:; 
g400 = sa_1248;
g406 = ld_1251;
{ uint8_t *_t3679 = &(((*({ hrv *_t3680 = &(g387); int64_t _i3680 = bi_1245; (S6*)_t3680->b + hr_ix(_i3680, _t3680->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:364"); }))).st_); *_t3679 = ((uint8_t)2LL); }
 }
{ int64_t _e3682 = na_1240; for (int64_t _k3682 = 0; _k3682 < _e3682; _k3682++) { int64_t j_1261 = (int64_t)_k3682; int64_t c_1262 = f90_kid(n_1235, j_1261); 
if (f163_is_pending(f141_at(c_1262))) { (void)(f184_default_t(c_1262));
 }
 } } _bk3681:; 
(void)(f227_pop_args(s_1239));
(void)(f170_set_r(n_1235, ((int64_t)10LL), bi_1245));
return f138_set_t(n_1235, ((int64_t)(((*({ hrv *_t3690 = &(g387); int64_t _i3690 = bi_1245; (S6*)_t3690->b + hr_ix(_i3690, _t3690->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:369"); }))).ret_)));
}
static int64_t f236_deref_val(int64_t a_1243) {
int64_t d_1244 = f179_deref(a_1243); 
return ({ int64_t _r3692; if (((((*({ hrv *_t3693 = &(g550); int64_t _i3693 = d_1244; (S1*)_t3693->b + hr_ix(_i3693, _t3693->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:246"); }))).k_) == (((uint8_t)18LL)))) { _r3692 = g575;  } else { _r3692 = ({ int64_t _r3694; if (((((*({ hrv *_t3695 = &(g550); int64_t _i3695 = d_1244; (S1*)_t3695->b + hr_ix(_i3695, _t3695->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:246"); }))).k_) == (((uint8_t)7LL)))) { _r3694 = f136_t_enum(((int64_t)(((*({ hrv *_t3697 = &(g550); int64_t _i3697 = d_1244; (S1*)_t3697->b + hr_ix(_i3697, _t3697->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:246"); }))).a_)), false);  } else { _r3694 = d_1244;  } _r3694; });  } _r3692; });
}
static int64_t f237_builtin_of(hsl name_1263) {
if (hr_streq(name_1263, hr_str("print", 5))) { return ((int64_t)1LL);
 }
if (hr_streq(name_1263, hr_str("str", 3))) { return ((int64_t)2LL);
 }
if (hr_streq(name_1263, hr_str("format", 6))) { return ((int64_t)3LL);
 }
if (hr_streq(name_1263, hr_str("assert", 6))) { return ((int64_t)4LL);
 }
if (hr_streq(name_1263, hr_str("abort", 5))) { return ((int64_t)5LL);
 }
if (hr_streq(name_1263, hr_str("exit", 4))) { return ((int64_t)6LL);
 }
if (hr_streq(name_1263, hr_str("copy", 4))) { return ((int64_t)7LL);
 }
if (hr_streq(name_1263, hr_str("default", 7))) { return ((int64_t)8LL);
 }
if (hr_streq(name_1263, hr_str("to_bytes", 8))) { return ((int64_t)30LL);
 }
if (hr_streq(name_1263, hr_str("bytes_of", 8))) { return ((int64_t)31LL);
 }
if (hr_streq(name_1263, hr_str("from_bytes", 10))) { return ((int64_t)32LL);
 }
if (hr_streq(name_1263, hr_str("embed_file", 10))) { return ((int64_t)33LL);
 }
if (hr_streq(name_1263, hr_str("len", 3))) { return ((int64_t)9LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f238_user_format(int64_t n_1265) {
if (((((*({ hrv *_t3698 = &(g703); int64_t _i3698 = n_1265; (S4*)_t3698->b + hr_ix(_i3698, _t3698->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:290"); }))).n_) == (((int32_t)0LL)))) { return false;
 }
int64_t t_1266 = f179_deref(f137_ck(f90_kid(n_1265, ((int64_t)0LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))); 
return (!(((((((*({ hrv *_t3702 = &(g550); int64_t _i3702 = t_1266; (S1*)_t3702->b + hr_ix(_i3702, _t3702->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:290"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t3703 = &(g550); int64_t _i3703 = t_1266; (S1*)_t3703->b + hr_ix(_i3703, _t3703->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:290"); }))).a_))) == (g563))) && (f239_is_grow(t_1266) || ((((int64_t)(((*({ hrv *_t3705 = &(g550); int64_t _i3705 = t_1266; (S1*)_t3705->b + hr_ix(_i3705, _t3705->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:290"); }))).s_))) == (((int64_t)3LL)))))));
}
static bool f239_is_grow(int64_t t_1267) {
return (((((int64_t)(((*({ hrv *_t3706 = &(g550); int64_t _i3706 = t_1267; (S1*)_t3706->b + hr_ix(_i3706, _t3706->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:291"); }))).s_))) == (((int64_t)4LL))) || ((((int64_t)(((*({ hrv *_t3707 = &(g550); int64_t _i3707 = t_1267; (S1*)_t3707->b + hr_ix(_i3707, _t3707->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:291"); }))).s_))) == (((int64_t)5LL))));
}
static int64_t f240_ck_builtin(int64_t n_1268, int64_t b_1269, int64_t recv_1270, int64_t want_1271) {
S4 x_1272 = (*({ hrv *_t3708 = &(g703); int64_t _i3708 = n_1268; (S4*)_t3708->b + hr_ix(_i3708, _t3708->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:408"); })); 
(void)(f170_set_r(n_1268, ((int64_t)4LL), b_1269));
(void)(f175_set_x(n_1268, ({ int64_t _r3711; if (((recv_1270) >= (((int64_t)0LL)))) { _r3711 = ((int64_t)1LL);  } else { _r3711 = ((int64_t)0LL);  } _r3711; })));
int64_t na_1273 = ((int64_t)((x_1272).n_)); 

int64_t total_1275 = ((int64_t)((int64_t)na_1273 + (int64_t)({ int64_t _r3712; if (((recv_1270) >= (((int64_t)0LL)))) { _r3712 = ((int64_t)1LL);  } else { _r3712 = ((int64_t)0LL);  } _r3712; }))); 
if ((((b_1269) == (((int64_t)1LL))) || ((b_1269) == (((int64_t)2LL))))) { { int64_t _e3714 = na_1273; for (int64_t _k3714 = 0; _k3714 < _e3714; _k3714++) { int64_t i_1276 = (int64_t)_k3714; int64_t c_1277 = f90_kid(n_1268, i_1276); 
int64_t t_1278 = f137_ck(c_1277, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f163_is_pending(t_1278)) { (void)(f184_default_t(c_1277));
 }
(void)(f242_hook_walk(f202_fin_t(c_1277)));
 } } _bk3713:; 
return f138_set_t(n_1268, ({ int64_t _r3722; if (((b_1269) == (((int64_t)2LL)))) { _r3722 = f123_t_arr(g563, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));  } else { _r3722 = g557;  } _r3722; }));
 }
if (((b_1269) == (((int64_t)3LL)))) { int64_t o_1404 = f241_arg(((int64_t)0LL), &recv_1270, &n_1268); 
if (((recv_1270) < (((int64_t)0LL)))) { (void)(f137_ck(o_1404, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
{ int64_t _e3727 = total_1275; for (int64_t _k3727 = ((int64_t)1LL); _k3727 < _e3727; _k3727++) { int64_t i_1405 = (int64_t)_k3727; int64_t c_1406 = f241_arg(i_1405, &recv_1270, &n_1268); 
int64_t t_1407 = f137_ck(c_1406, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f163_is_pending(t_1407)) { (void)(f184_default_t(c_1406));
 }
(void)(f242_hook_walk(f202_fin_t(c_1406)));
 } } _bk3726:; 
return f138_set_t(n_1268, g557);
 }
if (((b_1269) == (((int64_t)4LL)))) { (void)(f137_ck(f241_arg(((int64_t)0LL), &recv_1270, &n_1268), g558));
(void)(f140_conv(f241_arg(((int64_t)0LL), &recv_1270, &n_1268), g558));
return f138_set_t(n_1268, g557);
 }
if (((b_1269) == (((int64_t)5LL)))) { int64_t t_1408 = f137_ck(f241_arg(((int64_t)0LL), &recv_1270, &n_1268), g575); 
if (f163_is_pending(t_1408)) { (void)(f184_default_t(f241_arg(((int64_t)0LL), &recv_1270, &n_1268)));
 }
return f138_set_t(n_1268, g557);
 }
if (((b_1269) == (((int64_t)6LL)))) { (void)(f137_ck(f241_arg(((int64_t)0LL), &recv_1270, &n_1268), g562));
(void)(f140_conv(f241_arg(((int64_t)0LL), &recv_1270, &n_1268), g562));
return f138_set_t(n_1268, g557);
 }
if (((b_1269) == (((int64_t)8LL)))) { int64_t ta_1409 = ((int64_t)((x_1272).c_)); 
if (((ta_1409) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1268, hr_str("default needs a type: default<T>()", 34)));
return f138_set_t(n_1268, g574);
 }
return f138_set_t(n_1268, f113_rtype(f90_kid(ta_1409, ((int64_t)0LL)), f110_ns_of(n_1268)));
 }
if (((b_1269) == (((int64_t)7LL)))) { int64_t c_1410 = f241_arg(((int64_t)0LL), &recv_1270, &n_1268); 
if (((recv_1270) < (((int64_t)0LL)))) { (void)(f137_ck(c_1410, want_1271));
 }
int64_t t_1411 = f141_at(c_1410); 
if (f163_is_pending(t_1411)) { t_1411 = f184_default_t(c_1410);
 }
int64_t d_1412 = f179_deref(t_1411); 
int64_t k_1413 = ((int64_t)(((*({ hrv *_t3763 = &(g550); int64_t _i3763 = d_1412; (S1*)_t3763->b + hr_ix(_i3763, _t3763->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:434"); }))).k_)); 
if (((k_1413) == (((int64_t)9LL)))) { return f138_set_t(n_1268, f123_t_arr(((int64_t)(((*({ hrv *_t3766 = &(g550); int64_t _i3766 = d_1412; (S1*)_t3766->b + hr_ix(_i3766, _t3766->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:435"); }))).a_)), ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
return f138_set_t(n_1268, d_1412);
 }
if (((b_1269) == (((int64_t)9LL)))) { int64_t c_1414 = f241_arg(((int64_t)0LL), &recv_1270, &n_1268); 
if (((recv_1270) < (((int64_t)0LL)))) { (void)(f137_ck(c_1414, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (((((*({ hrv *_t3770 = &(g550); int64_t _i3770 = f141_at(c_1414); (S1*)_t3770->b + hr_ix(_i3770, _t3770->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:438"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(c_1414, g575));
 }
return f138_set_t(n_1268, g562);
 }
if (((b_1269) == (((int64_t)31LL)))) { int64_t c_1415 = f241_arg(((int64_t)0LL), &recv_1270, &n_1268); 
if (((recv_1270) < (((int64_t)0LL)))) { (void)(f137_ck(c_1415, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (f163_is_pending(f141_at(c_1415))) { (void)(f184_default_t(c_1415));
 }
return f138_set_t(n_1268, g575);
 }
if (((b_1269) == (((int64_t)30LL)))) { int64_t c_1416 = f241_arg(((int64_t)0LL), &recv_1270, &n_1268); 
if (((recv_1270) < (((int64_t)0LL)))) { (void)(f137_ck(c_1416, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (f163_is_pending(f141_at(c_1416))) { (void)(f184_default_t(c_1416));
 }
if (((total_1275) > (((int64_t)1LL)))) { (void)(f137_ck(f241_arg(((int64_t)1LL), &recv_1270, &n_1268), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_1268, g557);
 }
return f138_set_t(n_1268, f123_t_arr(g563, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (((b_1269) == (((int64_t)32LL)))) { int64_t ta_1417 = ((int64_t)((x_1272).c_)); 
int64_t t_1418 = ({ int64_t _r3790; if (((ta_1417) >= (((int64_t)0LL)))) { _r3790 = f113_rtype(f90_kid(ta_1417, ((int64_t)0LL)), f110_ns_of(n_1268));  } else { _r3790 = g574;  } _r3790; }); 
(void)(f137_ck(f241_arg(((int64_t)0LL), &recv_1270, &n_1268), g575));
if (f163_is_pending(f141_at(f241_arg(((int64_t)0LL), &recv_1270, &n_1268)))) { (void)(f184_default_t(f241_arg(((int64_t)0LL), &recv_1270, &n_1268)));
 }
return f138_set_t(n_1268, t_1418);
 }
if (((b_1269) == (((int64_t)33LL)))) { (void)(f137_ck(f241_arg(((int64_t)0LL), &recv_1270, &n_1268), g575));
(void)(f184_default_t(f241_arg(((int64_t)0LL), &recv_1270, &n_1268)));
return f138_set_t(n_1268, g575);
 }
int64_t r_1419 = recv_1270; 
int64_t rt_1420 = f179_deref(f141_at(r_1419)); 
int64_t e_1421 = ((int64_t)(((*({ hrv *_t3809 = &(g550); int64_t _i3809 = rt_1420; (S1*)_t3809->b + hr_ix(_i3809, _t3809->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:445"); }))).a_)); 
if (((b_1269) == (((int64_t)20LL)))) { if (((total_1275) != (((int64_t)2LL)))) { (void)(f108_cerr(n_1268, hr_str("push takes one value", 20)));
return f138_set_t(n_1268, g574);
 }
int64_t c_1422 = f241_arg(((int64_t)1LL), &recv_1270, &n_1268); 
(void)(f137_ck(c_1422, e_1421));
(void)(f140_conv(c_1422, e_1421));
return f138_set_t(n_1268, f119_t_ref(e_1421, ((int64_t)0LL)));
 }
if (((b_1269) == (((int64_t)21LL)))) { int64_t c_1423 = f241_arg(((int64_t)1LL), &recv_1270, &n_1268); 
int64_t t_1424 = f137_ck(c_1423, f18_t_slice(e_1421, true)); 
if (((((*({ hrv *_t3820 = &(g550); int64_t _i3820 = t_1424; (S1*)_t3820->b + hr_ix(_i3820, _t3820->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:447"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(c_1423, g575));
 } else { if (((((*({ hrv *_t3822 = &(g550); int64_t _i3822 = t_1424; (S1*)_t3822->b + hr_ix(_i3822, _t3822->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:447"); }))).k_) == (((uint8_t)19LL)))) { (void)(f140_conv(c_1423, f123_t_arr(e_1421, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
 } else { int64_t dt_1425 = f179_deref(t_1424); 
if (((((((*({ hrv *_t3826 = &(g550); int64_t _i3826 = dt_1425; (S1*)_t3826->b + hr_ix(_i3826, _t3826->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:447"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3827 = &(g550); int64_t _i3827 = dt_1425; (S1*)_t3827->b + hr_ix(_i3827, _t3827->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:447"); }))).k_) == (((uint8_t)9LL)))) && ((((int64_t)(((*({ hrv *_t3828 = &(g550); int64_t _i3828 = dt_1425; (S1*)_t3828->b + hr_ix(_i3828, _t3828->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:447"); }))).a_))) != (e_1421)))) { (void)(f108_cerr(c_1423, hr_str("append of a different element type", 34)));
 }
 }
 }
return f138_set_t(n_1268, g557);
 }
if (((b_1269) == (((int64_t)22LL)))) { return f138_set_t(n_1268, e_1421);
 }
if (((b_1269) == (((int64_t)23LL)))) { (void)(f137_ck(f241_arg(((int64_t)1LL), &recv_1270, &n_1268), g562));
(void)(f140_conv(f241_arg(((int64_t)1LL), &recv_1270, &n_1268), g562));
return f138_set_t(n_1268, g557);
 }
if (((b_1269) == (((int64_t)24LL)))) { (void)(f137_ck(f241_arg(((int64_t)1LL), &recv_1270, &n_1268), g562));
(void)(f140_conv(f241_arg(((int64_t)1LL), &recv_1270, &n_1268), g562));
if (((total_1275) > (((int64_t)2LL)))) { (void)(f137_ck(f241_arg(((int64_t)2LL), &recv_1270, &n_1268), e_1421));
(void)(f140_conv(f241_arg(((int64_t)2LL), &recv_1270, &n_1268), e_1421));
 }
return f138_set_t(n_1268, g557);
 }
if (((b_1269) == (((int64_t)25LL)))) { return f138_set_t(n_1268, g557);
 }
if (((b_1269) == (((int64_t)26LL)))) { (void)(f137_ck(f241_arg(((int64_t)1LL), &recv_1270, &n_1268), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_1268, g562);
 }
return f138_set_t(n_1268, g574);
}
static int64_t f241_arg(int64_t i_1274, int64_t *c1270, int64_t *c1268) {
return ({ int64_t _r3851; if ((((*c1270)) >= (((int64_t)0LL)))) { _r3851 = ({ int64_t _r3852; if (((i_1274) == (((int64_t)0LL)))) { _r3852 = (*c1270);  } else { _r3852 = f90_kid((*c1268), ((int64_t)((int64_t)i_1274 - (int64_t)((int64_t)1LL))));  } _r3852; });  } else { _r3851 = f90_kid((*c1268), i_1274);  } _r3851; });
}
static void f242_hook_walk(int64_t t_1279) {
while ((((g348).n) < ((g550).n))) { (void)(({ hrv *_v3856 = &(g348); int32_t _x3856 = ((int32_t)(0 - (uint64_t)(((int32_t)2LL)))); int32_t *_p3856 = (int32_t*)hr_grow(_v3856, 1, sizeof _x3856); *_p3856 = _x3856; _p3856; }));
(void)(({ hrv *_v3857 = &(g349); uint8_t _x3857 = ((uint8_t)0LL); uint8_t *_p3857 = (uint8_t*)hr_grow(_v3857, 1, sizeof _x3857); *_p3857 = _x3857; _p3857; }));
 } _bk3855:; 
if ((((t_1279) < (((int64_t)0LL))) || (((*({ hrv *_t3858 = &(g349); int64_t _i3858 = t_1279; (uint8_t*)_t3858->b + hr_ix(_i3858, _t3858->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:321"); }))) != (((uint8_t)0LL))))) { return;
 }
{ uint8_t *_t3859 = &((*({ hrv *_t3860 = &(g349); int64_t _i3860 = t_1279; (uint8_t*)_t3860->b + hr_ix(_i3860, _t3860->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:322"); }))); *_t3859 = ((uint8_t)1LL); }
S1 x_1280 = (*({ hrv *_t3861 = &(g550); int64_t _i3861 = t_1279; (S1*)_t3861->b + hr_ix(_i3861, _t3861->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:323"); })); 
int64_t k_1281 = ((int64_t)((x_1280).k_)); 
if (((k_1281) == (((int64_t)10LL)))) { (void)(f242_hook_walk(((int64_t)((x_1280).a_))));
return;
 }
if ((((k_1281) == (((int64_t)8LL))) || ((k_1281) == (((int64_t)9LL))))) { (void)(f242_hook_walk(((int64_t)((x_1280).a_))));
return;
 }
if (((k_1281) == (((int64_t)14LL)))) { { int32_t _e3865 = (x_1280).n_; for (int32_t _k3865 = 0; _k3865 < _e3865; _k3865++) { int32_t i_1282 = (int32_t)_k3865; (void)(f242_hook_walk(((int64_t)((*({ hrv *_t3867 = &(g551); int64_t _i3867 = ((int64_t)((int64_t)((int64_t)((x_1280).l_)) + (int64_t)((int64_t)(i_1282)))); (int32_t*)_t3867->b + hr_ix(_i3867, _t3867->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:326"); }))))));
 } } _bk3864:; 
return;
 }
if (((k_1281) == (((int64_t)5LL)))) { (void)(f243_hook_of(t_1279));
int64_t si_1396 = ((int64_t)((x_1280).a_)); 
{ int32_t _e3870 = ((*({ hrv *_t3871 = &(g553); int64_t _i3871 = si_1396; (S10*)_t3871->b + hr_ix(_i3871, _t3871->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:327"); }))).fnum_; for (int32_t _k3870 = 0; _k3870 < _e3870; _k3870++) { int32_t i_1397 = (int32_t)_k3870; S11 f_1398 = (*({ hrv *_t3872 = &(g554); int64_t _i3872 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3873 = &(g553); int64_t _i3873 = si_1396; (S10*)_t3873->b + hr_ix(_i3873, _t3873->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:327"); }))).f0_)) + (int64_t)((int64_t)(i_1397)))); (S11*)_t3872->b + hr_ix(_i3872, _t3872->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:327"); })); 
if ((((f_1398).ty_) >= (((int32_t)0LL)))) { (void)(f242_hook_walk(((int64_t)((f_1398).ty_))));
 }
 } } _bk3869:; 
return;
 }
if (((k_1281) == (((int64_t)7LL)))) { (void)(f243_hook_of(t_1279));
S9 v_1399 = (*({ hrv *_t3876 = &(g556); int64_t _i3876 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3877 = &(g555); int64_t _i3877 = (x_1280).a_; (S8*)_t3877->b + hr_ix(_i3877, _t3877->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:328"); }))).v0_)) + (int64_t)((int64_t)((x_1280).c_)))); (S9*)_t3876->b + hr_ix(_i3876, _t3876->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:328"); })); 
if ((((v_1399).si_) >= (((int32_t)0LL)))) { { int32_t _e3879 = ((*({ hrv *_t3880 = &(g553); int64_t _i3880 = (v_1399).si_; (S10*)_t3880->b + hr_ix(_i3880, _t3880->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:328"); }))).fnum_; for (int32_t _k3879 = 0; _k3879 < _e3879; _k3879++) { int32_t i_1400 = (int32_t)_k3879; S11 f_1401 = (*({ hrv *_t3881 = &(g554); int64_t _i3881 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3882 = &(g553); int64_t _i3882 = (v_1399).si_; (S10*)_t3882->b + hr_ix(_i3882, _t3882->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:328"); }))).f0_)) + (int64_t)((int64_t)(i_1400)))); (S11*)_t3881->b + hr_ix(_i3881, _t3881->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:328"); })); 
if ((((f_1401).ty_) >= (((int32_t)0LL)))) { (void)(f242_hook_walk(((int64_t)((f_1401).ty_))));
 }
 } } _bk3878:; 
 }
return;
 }
if (((k_1281) == (((int64_t)6LL)))) { (void)(f243_hook_of(t_1279));
int64_t ei_1402 = ((int64_t)((x_1280).a_)); 
{ int32_t _e3886 = ((*({ hrv *_t3887 = &(g555); int64_t _i3887 = ei_1402; (S8*)_t3887->b + hr_ix(_i3887, _t3887->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:329"); }))).vnum_; for (int32_t _k3886 = 0; _k3886 < _e3886; _k3886++) { int32_t i_1403 = (int32_t)_k3886; (void)(f242_hook_walk(f125_t_variant(ei_1402, ((int64_t)(i_1403)))));
 } } _bk3885:; 
 }
}
static int64_t f243_hook_of(int64_t t_1283) {
while ((((g348).n) < ((g550).n))) { (void)(({ hrv *_v3891 = &(g348); int32_t _x3891 = ((int32_t)(0 - (uint64_t)(((int32_t)2LL)))); int32_t *_p3891 = (int32_t*)hr_grow(_v3891, 1, sizeof _x3891); *_p3891 = _x3891; _p3891; }));
(void)(({ hrv *_v3892 = &(g349); uint8_t _x3892 = ((uint8_t)0LL); uint8_t *_p3892 = (uint8_t*)hr_grow(_v3892, 1, sizeof _x3892); *_p3892 = _x3892; _p3892; }));
 } _bk3890:; 
if ((((*({ hrv *_t3893 = &(g348); int64_t _i3893 = t_1283; (int32_t*)_t3893->b + hr_ix(_i3893, _t3893->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:297"); }))) != (((int32_t)(0 - (uint64_t)(((int32_t)2LL))))))) { return ((int64_t)((*({ hrv *_t3894 = &(g348); int64_t _i3894 = t_1283; (int32_t*)_t3894->b + hr_ix(_i3894, _t3894->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:297"); }))));
 }
{ int32_t *_t3895 = &((*({ hrv *_t3896 = &(g348); int64_t _i3896 = t_1283; (int32_t*)_t3896->b + hr_ix(_i3896, _t3896->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:298"); }))); *_t3895 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
int64_t k_1284 = ((int64_t)(((*({ hrv *_t3897 = &(g550); int64_t _i3897 = t_1283; (S1*)_t3897->b + hr_ix(_i3897, _t3897->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:299"); }))).k_)); 
if (((((((k_1284) == (((int64_t)0LL))) || ((k_1284) == (((int64_t)1LL)))) || ((k_1284) == (((int64_t)10LL)))) || ((k_1284) == (((int64_t)14LL)))) || f163_is_pending(t_1283))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t node_1285 = ({ int64_t _r3899; if (((k_1284) == (((int64_t)5LL)))) { _r3899 = ((int64_t)(((*({ hrv *_t3900 = &(g553); int64_t _i3900 = ((*({ hrv *_t3901 = &(g550); int64_t _i3901 = t_1283; (S1*)_t3901->b + hr_ix(_i3901, _t3901->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:301"); }))).a_; (S10*)_t3900->b + hr_ix(_i3900, _t3900->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:301"); }))).node_));  } else { _r3899 = ({ int64_t _r3902; if ((((k_1284) == (((int64_t)6LL))) || ((k_1284) == (((int64_t)7LL))))) { _r3902 = ((int64_t)(((*({ hrv *_t3903 = &(g555); int64_t _i3903 = ((*({ hrv *_t3904 = &(g550); int64_t _i3904 = t_1283; (S1*)_t3904->b + hr_ix(_i3904, _t3904->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:301"); }))).a_; (S8*)_t3903->b + hr_ix(_i3903, _t3903->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:301"); }))).node_));  } else { _r3902 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3902; });  } _r3899; }); 
if (((g350) < (((int64_t)0LL)))) { g350 = f8_intern(hr_str("format", 6));
 }
int64_t s_1286 = (g407).n; 
(void)(({ hrv *_v3906 = &(g407); int32_t _x3906 = ((int32_t)(f119_t_ref(f123_t_arr(g563, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))), ((int64_t)0LL)))); int32_t *_p3906 = (int32_t*)hr_grow(_v3906, 1, sizeof _x3906); *_p3906 = _x3906; _p3906; }));
(void)(({ hrv *_v3909 = &(g315); int32_t _x3909 = ((int32_t)0LL); int32_t *_p3909 = (int32_t*)hr_grow(_v3909, 1, sizeof _x3909); *_p3909 = _x3909; _p3909; }));
(void)(({ hrv *_v3910 = &(g407); int32_t _x3910 = ((int32_t)(t_1283)); int32_t *_p3910 = (int32_t*)hr_grow(_v3910, 1, sizeof _x3910); *_p3910 = _x3910; _p3910; }));
(void)(({ hrv *_v3911 = &(g315); int32_t _x3911 = ((int32_t)0LL); int32_t *_p3911 = (int32_t*)hr_grow(_v3911, 1, sizeof _x3911); *_p3911 = _x3911; _p3911; }));
M94 _t3912 = f244_resolve(((int64_t)0LL), g350, ({ int64_t _r3914; if (((node_1285) >= (((int64_t)0LL)))) { _r3914 = f110_ns_of(node_1285);  } else { _r3914 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3914; }), s_1286, ((int64_t)2LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false); int64_t fnode_1375 = _t3912.r0; int64_t b0_1376 = _t3912.r1; int64_t bn_1377 = _t3912.r2; 
(void)(f227_pop_args(s_1286));
if (((((fnode_1375) < (((int64_t)0LL))) || ((((*({ hrv *_t3917 = &(g703); int64_t _i3917 = fnode_1375; (S4*)_t3917->b + hr_ix(_i3917, _t3917->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:308"); }))).n_) != (((int32_t)2LL)))) || f251_is_std_node(fnode_1375))) { (void)(({ hrv *_v3919 = &(g313); int64_t _k3919 = ((int64_t)((int64_t)(g313).n - (int64_t)b0_1376)); if (_k3919 < 0 || _k3919 > _v3919->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:308"); _v3919->n -= _k3919; }));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t sa_1378 = g400; 
int64_t sc_1379 = g401; 
g400 = g402;
g401 = g402;
int64_t inst_1394 = f252_get_inst(fnode_1375, b0_1376, bn_1377, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
g400 = sa_1378;
g401 = sc_1379;
(void)(({ hrv *_v3921 = &(g313); int64_t _k3921 = ((int64_t)((int64_t)(g313).n - (int64_t)b0_1376)); if (_k3921 < 0 || _k3921 > _v3921->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:312"); _v3921->n -= _k3921; }));
while ((((g348).n) < ((g550).n))) { (void)(({ hrv *_v3923 = &(g348); int32_t _x3923 = ((int32_t)(0 - (uint64_t)(((int32_t)2LL)))); int32_t *_p3923 = (int32_t*)hr_grow(_v3923, 1, sizeof _x3923); *_p3923 = _x3923; _p3923; }));
(void)(({ hrv *_v3924 = &(g349); uint8_t _x3924 = ((uint8_t)0LL); uint8_t *_p3924 = (uint8_t*)hr_grow(_v3924, 1, sizeof _x3924); *_p3924 = _x3924; _p3924; }));
 } _bk3922:; 
int64_t pd_1395 = f179_deref(f208_ptype_of(inst_1394, ((int64_t)1LL))); 
if ((((pd_1395) != (t_1283)) && (!((((k_1284) == (((int64_t)7LL))) && ((((*({ hrv *_t3927 = &(g550); int64_t _i3927 = pd_1395; (S1*)_t3927->b + hr_ix(_i3927, _t3927->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:315"); }))).k_) == (((uint8_t)6LL)))))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
{ int32_t *_t3928 = &((*({ hrv *_t3929 = &(g348); int64_t _i3929 = t_1283; (int32_t*)_t3929->b + hr_ix(_i3929, _t3929->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:316"); }))); *_t3928 = ((int32_t)(inst_1394)); }
return inst_1394;
}
static M94 f244_resolve(int64_t n_1287, int64_t name_1288, int64_t ns_1289, int64_t a0_1290, int64_t an_1291, int64_t blk_1292, int64_t tyargs_1293, bool report_1294) {
int64_t c0_1295 = (g312).n; 
(void)(f245_cands_add(name_1288, ns_1289));
int64_t best_1304 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
int64_t bestr_1305 = ((int64_t)99LL); 
int64_t bestb0_1306 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
int64_t bestbn_1307 = ((int64_t)0LL); 
bool tie_1308 = false; 
bool bestuser_1309 = false; 
int64_t nb0_1310 = (g313).n; 
{ int64_t _e3932 = (g312).n; for (int64_t _k3932 = c0_1295; _k3932 < _e3932; _k3932++) { int64_t ci_1311 = (int64_t)_k3932; int64_t fnode_1312 = ((int64_t)(((*({ hrv *_t3933 = &(g488); int64_t _i3933 = (*({ hrv *_t3934 = &(g312); int64_t _i3934 = ci_1311; (int32_t*)_t3934->b + hr_ix(_i3934, _t3934->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:203"); })); (S5*)_t3933->b + hr_ix(_i3933, _t3933->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:203"); }))).node_)); 
int64_t np_1313 = ((int64_t)(((*({ hrv *_t3935 = &(g703); int64_t _i3935 = fnode_1312; (S4*)_t3935->b + hr_ix(_i3935, _t3935->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:204"); }))).n_)); 
int64_t nreq_1314 = ((int64_t)0LL); 
{ int64_t _e3937 = np_1313; for (int64_t _k3937 = 0; _k3937 < _e3937; _k3937++) { int64_t j_1315 = (int64_t)_k3937; if (((((*({ hrv *_t3938 = &(g703); int64_t _i3938 = f90_kid(fnode_1312, j_1315); (S4*)_t3938->b + hr_ix(_i3938, _t3938->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:206"); }))).b_) < (((int32_t)0LL)))) { nreq_1314 = ((int64_t)((int64_t)j_1315 + (int64_t)((int64_t)1LL)));
 }
 } } _bk3936:; 
if ((((an_1291) > (np_1313)) || ((an_1291) < (nreq_1314)))) { continue;
 }
int64_t bg_1316 = f231_blk_gen(fnode_1312); 
if ((((((blk_1292) >= (((int64_t)0LL)))) != (((bg_1316) >= (((int64_t)0LL))))) && (!(((((blk_1292) < (((int64_t)0LL))) && ((bg_1316) >= (((int64_t)0LL)))) && ((tyargs_1293) >= (((int64_t)0LL)))))))) { continue;
 }
int64_t b0_1317 = (g313).n; 
int64_t gl_1318 = f232_gen_list(fnode_1312); 
if (((gl_1318) >= (((int64_t)0LL)))) { { int32_t _e3943 = ((*({ hrv *_t3944 = &(g703); int64_t _i3944 = gl_1318; (S4*)_t3944->b + hr_ix(_i3944, _t3944->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:212"); }))).n_; for (int32_t _k3943 = 0; _k3943 < _e3943; _k3943++) { int32_t j_1319 = (int32_t)_k3943; (void)(({ hrv *_v3945 = &(g313); S7 _x3945 = ((S7){ .name_ = ((*({ hrv *_t3946 = &(g703); int64_t _i3946 = f90_kid(gl_1318, ((int64_t)(j_1319))); (S4*)_t3946->b + hr_ix(_i3946, _t3946->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:212"); }))).s_, .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }); S7 *_p3945 = (S7*)hr_grow(_v3945, 1, sizeof _x3945); *_p3945 = _x3945; _p3945; }));
 } } _bk3942:; 
 }
{ int64_t _e3949 = np_1313; for (int64_t _k3949 = 0; _k3949 < _e3949; _k3949++) { int64_t j_1320 = (int64_t)_k3949; int64_t p_1321 = f90_kid(fnode_1312, j_1320); 
if (((((*({ hrv *_t3951 = &(g703); int64_t _i3951 = p_1321; (S4*)_t3951->b + hr_ix(_i3951, _t3951->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:213"); }))).a_) < (((int32_t)0LL)))) { (void)(({ hrv *_v3952 = &(g313); S7 _x3952 = ((S7){ .name_ = ((int32_t)(f196_upname(p_1321))), .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }); S7 *_p3952 = (S7*)hr_grow(_v3952, 1, sizeof _x3952); *_p3952 = _x3952; _p3952; }));
 }
 } } _bk3948:; 
if (((tyargs_1293) >= (((int64_t)0LL)))) { { int64_t _e3955 = f45_min(((int64_t)(((*({ hrv *_t3957 = &(g703); int64_t _i3957 = tyargs_1293; (S4*)_t3957->b + hr_ix(_i3957, _t3957->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:214"); }))).n_)), ((int64_t)((int64_t)(g313).n - (int64_t)b0_1317))); for (int64_t _k3955 = 0; _k3955 < _e3955; _k3955++) { int64_t j_1322 = (int64_t)_k3955; { int32_t *_t3958 = &(((*({ hrv *_t3959 = &(g313); int64_t _i3959 = ((int64_t)((int64_t)b0_1317 + (int64_t)j_1322)); (S7*)_t3959->b + hr_ix(_i3959, _t3959->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:214"); }))).ty_); *_t3958 = ((int32_t)(f113_rtype(f90_kid(tyargs_1293, j_1322), ns_1289))); }
 } } _bk3954:; 
 }
{ int64_t _e3963 = an_1291; for (int64_t _k3963 = 0; _k3963 < _e3963; _k3963++) { int64_t j_1323 = (int64_t)_k3963; int64_t p_1324 = f90_kid(fnode_1312, j_1323); 
int64_t a_1325 = ((int64_t)((*({ hrv *_t3965 = &(g407); int64_t _i3965 = ((int64_t)((int64_t)a0_1290 + (int64_t)j_1323)); (int32_t*)_t3965->b + hr_ix(_i3965, _t3965->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:215"); })))); 
if ((!(f163_is_pending(a_1325)))) { if (((((*({ hrv *_t3967 = &(g703); int64_t _i3967 = p_1324; (S4*)_t3967->b + hr_ix(_i3967, _t3967->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:215"); }))).a_) >= (((int32_t)0LL)))) { (void)(f246_match_ty(((int64_t)(((*({ hrv *_t3969 = &(g703); int64_t _i3969 = p_1324; (S4*)_t3969->b + hr_ix(_i3969, _t3969->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:215"); }))).a_)), a_1325, b0_1317));
 } else { { int64_t _e3971 = (g313).n; for (int64_t _k3971 = b0_1317; _k3971 < _e3971; _k3971++) { int64_t q_1337 = (int64_t)_k3971; if ((((((int64_t)(((*({ hrv *_t3972 = &(g313); int64_t _i3972 = q_1337; (S7*)_t3972->b + hr_ix(_i3972, _t3972->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:215"); }))).name_))) == (f196_upname(p_1324))) && ((((*({ hrv *_t3974 = &(g313); int64_t _i3974 = q_1337; (S7*)_t3974->b + hr_ix(_i3974, _t3974->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:215"); }))).ty_) < (((int32_t)0LL))))) { { int32_t *_t3975 = &(((*({ hrv *_t3976 = &(g313); int64_t _i3976 = q_1337; (S7*)_t3976->b + hr_ix(_i3976, _t3976->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:215"); }))).ty_); *_t3975 = ((int32_t)(f236_deref_val(a_1325))); }
 }
 } } _bk3970:; 
 }
 }
 } } _bk3962:; 
{ int64_t _e3979 = an_1291; for (int64_t _k3979 = 0; _k3979 < _e3979; _k3979++) { int64_t j_1338 = (int64_t)_k3979; int64_t p_1339 = f90_kid(fnode_1312, j_1338); 
int64_t a_1340 = ((int64_t)((*({ hrv *_t3981 = &(g407); int64_t _i3981 = ((int64_t)((int64_t)a0_1290 + (int64_t)j_1338)); (int32_t*)_t3981->b + hr_ix(_i3981, _t3981->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:216"); })))); 
if (f163_is_pending(a_1340)) { int64_t dt_1343 = f247_pend_default(a_1340); 
if (((((*({ hrv *_t3984 = &(g703); int64_t _i3984 = p_1339; (S4*)_t3984->b + hr_ix(_i3984, _t3984->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:216"); }))).a_) >= (((int32_t)0LL)))) { (void)(f246_match_ty(((int64_t)(((*({ hrv *_t3986 = &(g703); int64_t _i3986 = p_1339; (S4*)_t3986->b + hr_ix(_i3986, _t3986->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:216"); }))).a_)), dt_1343, b0_1317));
 } else { { int64_t _e3988 = (g313).n; for (int64_t _k3988 = b0_1317; _k3988 < _e3988; _k3988++) { int64_t q_1344 = (int64_t)_k3988; if ((((((int64_t)(((*({ hrv *_t3989 = &(g313); int64_t _i3989 = q_1344; (S7*)_t3989->b + hr_ix(_i3989, _t3989->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:216"); }))).name_))) == (f196_upname(p_1339))) && ((((*({ hrv *_t3991 = &(g313); int64_t _i3991 = q_1344; (S7*)_t3991->b + hr_ix(_i3991, _t3991->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:216"); }))).ty_) < (((int32_t)0LL))))) { { int32_t *_t3992 = &(((*({ hrv *_t3993 = &(g313); int64_t _i3993 = q_1344; (S7*)_t3993->b + hr_ix(_i3993, _t3993->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:216"); }))).ty_); *_t3992 = ((int32_t)(dt_1343)); }
 }
 } } _bk3987:; 
 }
 }
 } } _bk3978:; 
bool ok_1345 = true; 
{ int64_t _e3995 = (g313).n; for (int64_t _k3995 = b0_1317; _k3995 < _e3995; _k3995++) { int64_t q_1346 = (int64_t)_k3995; if (((((*({ hrv *_t3996 = &(g313); int64_t _i3996 = q_1346; (S7*)_t3996->b + hr_ix(_i3996, _t3996->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:218"); }))).ty_) < (((int32_t)0LL)))) { if ((((bg_1316) >= (((int64_t)0LL))) && ((((int64_t)(((*({ hrv *_t3997 = &(g313); int64_t _i3997 = q_1346; (S7*)_t3997->b + hr_ix(_i3997, _t3997->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:218"); }))).name_))) == (bg_1316)))) { { int32_t *_t3998 = &(((*({ hrv *_t3999 = &(g313); int64_t _i3999 = q_1346; (S7*)_t3999->b + hr_ix(_i3999, _t3999->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:218"); }))).ty_); *_t3998 = ((int32_t)(g577)); }
 } else { ok_1345 = false;
 }
 }
 } } _bk3994:; 
if ((!(ok_1345))) { (void)(({ hrv *_v4000 = &(g313); int64_t _k4000 = ((int64_t)((int64_t)(g313).n - (int64_t)b0_1317)); if (_k4000 < 0 || _k4000 > _v4000->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:219"); _v4000->n -= _k4000; }));
continue;
 }
int64_t g0_1347 = (g490).n; 
{ int64_t _e4002 = (g313).n; for (int64_t _k4002 = b0_1317; _k4002 < _e4002; _k4002++) { int64_t q_1348 = (int64_t)_k4002; (void)(({ hrv *_v4003 = &(g490); S7 _x4003 = (*({ hrv *_t4004 = &(g313); int64_t _i4004 = q_1348; (S7*)_t4004->b + hr_ix(_i4004, _t4004->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:221"); })); S7 *_p4003 = (S7*)hr_grow(_v4003, 1, sizeof _x4003); *_p4003 = _x4003; _p4003; }));
 } } _bk4001:; 
int64_t fns_1349 = f110_ns_of(fnode_1312); 
int64_t worst_1350 = ((int64_t)0LL); 
{ int64_t _e4007 = an_1291; for (int64_t _k4007 = 0; _k4007 < _e4007; _k4007++) { int64_t j_1351 = (int64_t)_k4007; int64_t p_1352 = f90_kid(fnode_1312, j_1351); 
int64_t pt_1353 = ({ int64_t _r4009; if (((((*({ hrv *_t4010 = &(g703); int64_t _i4010 = p_1352; (S4*)_t4010->b + hr_ix(_i4010, _t4010->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:226"); }))).a_) >= (((int32_t)0LL)))) { _r4009 = f113_rtype(((int64_t)(((*({ hrv *_t4012 = &(g703); int64_t _i4012 = p_1352; (S4*)_t4012->b + hr_ix(_i4012, _t4012->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:226"); }))).a_)), fns_1349);  } else { _r4009 = f130_gb_find(f196_upname(p_1352));  } _r4009; }); 
int64_t r_1366 = f248_arg_rank(((int64_t)((*({ hrv *_t4016 = &(g315); int64_t _i4016 = ((int64_t)((int64_t)a0_1290 + (int64_t)j_1351)); (int32_t*)_t4016->b + hr_ix(_i4016, _t4016->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:227"); })))), ((int64_t)((*({ hrv *_t4017 = &(g407); int64_t _i4017 = ((int64_t)((int64_t)a0_1290 + (int64_t)j_1351)); (int32_t*)_t4017->b + hr_ix(_i4017, _t4017->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:227"); })))), pt_1353); 
if (((r_1366) < (((int64_t)0LL)))) { worst_1350 = ((int64_t)99LL);
{ goto _bk4006; }
 }
if (((r_1366) > (worst_1350))) { worst_1350 = r_1366;
 }
 } } _bk4006:; 
(void)(({ hrv *_v4018 = &(g490); int64_t _k4018 = ((int64_t)((int64_t)(g490).n - (int64_t)g0_1347)); if (_k4018 < 0 || _k4018 > _v4018->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:231"); _v4018->n -= _k4018; }));
if ((((worst_1350) < (((int64_t)2LL))) && (((gl_1318) >= (((int64_t)0LL))) || (((np_1313) > (((int64_t)0LL))) && f250_untyped_any(fnode_1312))))) { worst_1350 = f103_max(worst_1350, ((int64_t)1LL));
 }
if (((worst_1350) == (((int64_t)99LL)))) { (void)(({ hrv *_v4021 = &(g313); int64_t _k4021 = ((int64_t)((int64_t)(g313).n - (int64_t)b0_1317)); if (_k4021 < 0 || _k4021 > _v4021->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:233"); _v4021->n -= _k4021; }));
continue;
 }
bool user_1372 = (!(f251_is_std_node(fnode_1312))); 
if ((((worst_1350) < (bestr_1305)) || ((((worst_1350) == (bestr_1305)) && user_1372) && (!(bestuser_1309))))) { best_1304 = fnode_1312;
bestr_1305 = worst_1350;
bestb0_1306 = b0_1317;
bestbn_1307 = ((int64_t)((int64_t)(g313).n - (int64_t)b0_1317));
tie_1308 = false;
bestuser_1309 = user_1372;
 } else { if ((((worst_1350) == (bestr_1305)) && ((user_1372) == (bestuser_1309)))) { tie_1308 = true;
 }
 }
 } } _bk3931:; 
(void)(({ hrv *_v4023 = &(g312); int64_t _k4023 = ((int64_t)((int64_t)(g312).n - (int64_t)c0_1295)); if (_k4023 < 0 || _k4023 > _v4023->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:238"); _v4023->n -= _k4023; }));
if (((best_1304) < (((int64_t)0LL)))) { (void)(({ hrv *_v4024 = &(g313); int64_t _k4024 = ((int64_t)((int64_t)(g313).n - (int64_t)nb0_1310)); if (_k4024 < 0 || _k4024 > _v4024->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:239"); _v4024->n -= _k4024; }));
return (M94){ ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)0LL), ((int64_t)0LL) };
 }
if ((tie_1308 && report_1294)) { hrv m_1373 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o4026 = &(m_1373); hr_fs(_o4026, hr_str("ambiguous call to ", 18)); hr_fs(_o4026, f10_nm(name_1288)); }));
(void)(f108_cerr(n_1287, hr_sl(m_1373)));
 }
if (((bestb0_1306) > (nb0_1310))) { { int64_t _e4030 = bestbn_1307; for (int64_t _k4030 = ((int64_t)0LL); _k4030 < _e4030; _k4030++) { int64_t q_1374 = (int64_t)_k4030; { S7 *_t4031 = &((*({ hrv *_t4032 = &(g313); int64_t _i4032 = ((int64_t)((int64_t)nb0_1310 + (int64_t)q_1374)); (S7*)_t4032->b + hr_ix(_i4032, _t4032->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:241"); }))); *_t4031 = (*({ hrv *_t4033 = &(g313); int64_t _i4033 = ((int64_t)((int64_t)bestb0_1306 + (int64_t)q_1374)); (S7*)_t4033->b + hr_ix(_i4033, _t4033->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:241"); })); }
 } } _bk4029:; 
 }
(void)(({ hrv *_v4034 = &(g313); int64_t _k4034 = ((int64_t)((int64_t)((int64_t)((int64_t)(g313).n - (int64_t)nb0_1310)) - (int64_t)bestbn_1307)); if (_k4034 < 0 || _k4034 > _v4034->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:242"); _v4034->n -= _k4034; }));
return (M94){ best_1304, nb0_1310, bestbn_1307 };
}
static void f245_cands_add(int64_t name_1296, int64_t ns_1297) {
M55 _t4035 = f117_split_q(name_1296); int64_t a_1298 = _t4035.r0; int64_t b_1299 = _t4035.r1; 
if (((a_1298) >= (((int64_t)0LL)))) { int64_t d_1300 = f107_dmap(name_1296); 
while (((d_1300) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4039 = &(g488); int64_t _i4039 = d_1300; (S5*)_t4039->b + hr_ix(_i4039, _t4039->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:190"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4040 = &(g312); int32_t _x4040 = ((int32_t)(d_1300)); int32_t *_p4040 = (int32_t*)hr_grow(_v4040, 1, sizeof _x4040); *_p4040 = _x4040; _p4040; }));
 }
d_1300 = ((int64_t)(((*({ hrv *_t4041 = &(g488); int64_t _i4041 = d_1300; (S5*)_t4041->b + hr_ix(_i4041, _t4041->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:190"); }))).next_));
 } _bk4038:; 
return;
 }
if (((a_1298) == (((int64_t)(0 - (uint64_t)(((int64_t)2LL))))))) { int64_t d_1301 = f107_dmap(b_1299); 
while (((d_1301) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4044 = &(g488); int64_t _i4044 = d_1301; (S5*)_t4044->b + hr_ix(_i4044, _t4044->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:191"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4045 = &(g312); int32_t _x4045 = ((int32_t)(d_1301)); int32_t *_p4045 = (int32_t*)hr_grow(_v4045, 1, sizeof _x4045); *_p4045 = _x4045; _p4045; }));
 }
d_1301 = ((int64_t)(((*({ hrv *_t4046 = &(g488); int64_t _i4046 = d_1301; (S5*)_t4046->b + hr_ix(_i4046, _t4046->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:191"); }))).next_));
 } _bk4043:; 
return;
 }
if (((ns_1297) >= (((int64_t)0LL)))) { int64_t d_1302 = f107_dmap(f98_qual(ns_1297, name_1296)); 
while (((d_1302) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4050 = &(g488); int64_t _i4050 = d_1302; (S5*)_t4050->b + hr_ix(_i4050, _t4050->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:192"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4051 = &(g312); int32_t _x4051 = ((int32_t)(d_1302)); int32_t *_p4051 = (int32_t*)hr_grow(_v4051, 1, sizeof _x4051); *_p4051 = _x4051; _p4051; }));
 }
d_1302 = ((int64_t)(((*({ hrv *_t4052 = &(g488); int64_t _i4052 = d_1302; (S5*)_t4052->b + hr_ix(_i4052, _t4052->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:192"); }))).next_));
 } _bk4049:; 
 }
int64_t d_1303 = f107_dmap(name_1296); 
while (((d_1303) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4055 = &(g488); int64_t _i4055 = d_1303; (S5*)_t4055->b + hr_ix(_i4055, _t4055->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:194"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4056 = &(g312); int32_t _x4056 = ((int32_t)(d_1303)); int32_t *_p4056 = (int32_t*)hr_grow(_v4056, 1, sizeof _x4056); *_p4056 = _x4056; _p4056; }));
 }
d_1303 = ((int64_t)(((*({ hrv *_t4057 = &(g488); int64_t _i4057 = d_1303; (S5*)_t4057->b + hr_ix(_i4057, _t4057->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:194"); }))).next_));
 } _bk4054:; 
}
static bool f246_match_ty(int64_t tn0_1326, int64_t t0_1327, int64_t g0_1328) {
if (((tn0_1326) < (((int64_t)0LL)))) { return true;
 }
S4 x_1329 = (*({ hrv *_t4058 = &(g703); int64_t _i4058 = tn0_1326; (S4*)_t4058->b + hr_ix(_i4058, _t4058->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:63"); })); 
int64_t k_1330 = ((int64_t)((x_1329).k_)); 
int64_t t_1331 = f179_deref(t0_1327); 
if (((k_1330) == (((int64_t)41LL)))) { if ((((x_1329).n_) == (((int32_t)0LL)))) { { int64_t _e4061 = (g313).n; for (int64_t _k4061 = g0_1328; _k4061 < _e4061; _k4061++) { int64_t i_1332 = (int64_t)_k4061; if (((((*({ hrv *_t4062 = &(g313); int64_t _i4062 = i_1332; (S7*)_t4062->b + hr_ix(_i4062, _t4062->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:67"); }))).name_) == ((x_1329).s_))) { if (((((*({ hrv *_t4063 = &(g313); int64_t _i4063 = i_1332; (S7*)_t4063->b + hr_ix(_i4063, _t4063->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:67"); }))).ty_) < (((int32_t)0LL)))) { { int32_t *_t4064 = &(((*({ hrv *_t4065 = &(g313); int64_t _i4065 = i_1332; (S7*)_t4065->b + hr_ix(_i4065, _t4065->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:67"); }))).ty_); *_t4064 = ((int32_t)(f236_deref_val(t_1331))); }
 }
return true;
 }
 } } _bk4060:; 
return true;
 }
if (((((*({ hrv *_t4067 = &(g550); int64_t _i4067 = t_1331; (S1*)_t4067->b + hr_ix(_i4067, _t4067->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).k_) == (((uint8_t)5LL)))) { int64_t si_1333 = ((int64_t)(((*({ hrv *_t4068 = &(g550); int64_t _i4068 = t_1331; (S1*)_t4068->b + hr_ix(_i4068, _t4068->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).a_)); 
if (((((*({ hrv *_t4069 = &(g553); int64_t _i4069 = si_1333; (S10*)_t4069->b + hr_ix(_i4069, _t4069->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).tn_) == ((x_1329).n_))) { { int32_t _e4071 = (x_1329).n_; for (int32_t _k4071 = 0; _k4071 < _e4071; _k4071++) { int32_t i_1334 = (int32_t)_k4071; (void)(f246_match_ty(f90_kid(tn0_1326, ((int64_t)(i_1334))), ((int64_t)((*({ hrv *_t4074 = &(g551); int64_t _i4074 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4075 = &(g553); int64_t _i4075 = si_1333; (S10*)_t4075->b + hr_ix(_i4075, _t4075->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).ta_)) + (int64_t)((int64_t)(i_1334)))); (int32_t*)_t4074->b + hr_ix(_i4074, _t4074->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); })))), g0_1328));
 } } _bk4070:; 
 }
 }
if (((((*({ hrv *_t4076 = &(g550); int64_t _i4076 = t_1331; (S1*)_t4076->b + hr_ix(_i4076, _t4076->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).k_) == (((uint8_t)6LL)))) { int64_t ei_1335 = ((int64_t)(((*({ hrv *_t4077 = &(g550); int64_t _i4077 = t_1331; (S1*)_t4077->b + hr_ix(_i4077, _t4077->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).a_)); 
if (((((*({ hrv *_t4078 = &(g555); int64_t _i4078 = ei_1335; (S8*)_t4078->b + hr_ix(_i4078, _t4078->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).tn_) == ((x_1329).n_))) { { int32_t _e4080 = (x_1329).n_; for (int32_t _k4080 = 0; _k4080 < _e4080; _k4080++) { int32_t i_1336 = (int32_t)_k4080; (void)(f246_match_ty(f90_kid(tn0_1326, ((int64_t)(i_1336))), ((int64_t)((*({ hrv *_t4083 = &(g551); int64_t _i4083 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4084 = &(g555); int64_t _i4084 = ei_1335; (S8*)_t4084->b + hr_ix(_i4084, _t4084->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).ta_)) + (int64_t)((int64_t)(i_1336)))); (int32_t*)_t4083->b + hr_ix(_i4083, _t4083->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); })))), g0_1328));
 } } _bk4079:; 
 }
 }
return true;
 }
if ((((k_1330) == (((int64_t)42LL))) || ((k_1330) == (((int64_t)43LL))))) { if ((((((*({ hrv *_t4085 = &(g550); int64_t _i4085 = t_1331; (S1*)_t4085->b + hr_ix(_i4085, _t4085->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t4086 = &(g550); int64_t _i4086 = t_1331; (S1*)_t4086->b + hr_ix(_i4086, _t4086->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).k_) == (((uint8_t)9LL))))) { return f246_match_ty(((int64_t)((x_1329).a_)), ((int64_t)(((*({ hrv *_t4088 = &(g550); int64_t _i4088 = t_1331; (S1*)_t4088->b + hr_ix(_i4088, _t4088->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).a_)), g0_1328);
 }
if (((((*({ hrv *_t4089 = &(g550); int64_t _i4089 = t_1331; (S1*)_t4089->b + hr_ix(_i4089, _t4089->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).k_) == (((uint8_t)18LL)))) { return f246_match_ty(((int64_t)((x_1329).a_)), g563, g0_1328);
 }
return true;
 }
if (((k_1330) == (((int64_t)44LL)))) { if (((((*({ hrv *_t4091 = &(g550); int64_t _i4091 = t0_1327; (S1*)_t4091->b + hr_ix(_i4091, _t4091->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:75"); }))).k_) == (((uint8_t)10LL)))) { return f246_match_ty(((int64_t)((x_1329).a_)), ((int64_t)(((*({ hrv *_t4093 = &(g550); int64_t _i4093 = t0_1327; (S1*)_t4093->b + hr_ix(_i4093, _t4093->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:75"); }))).a_)), g0_1328);
 }
return f246_match_ty(((int64_t)((x_1329).a_)), t_1331, g0_1328);
 }
if (((k_1330) == (((int64_t)48LL)))) { return f246_match_ty(((int64_t)((x_1329).a_)), t0_1327, g0_1328);
 }
return true;
}
static int64_t f247_pend_default(int64_t a_1341) {
int64_t k_1342 = ((int64_t)(((*({ hrv *_t4096 = &(g550); int64_t _i4096 = a_1341; (S1*)_t4096->b + hr_ix(_i4096, _t4096->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:247"); }))).k_)); 
return ({ int64_t _r4097; if (((k_1342) == (((int64_t)12LL)))) { _r4097 = g562;  } else { _r4097 = ({ int64_t _r4098; if (((k_1342) == (((int64_t)13LL)))) { _r4098 = g568;  } else { _r4098 = ({ int64_t _r4099; if (((k_1342) == (((int64_t)18LL)))) { _r4099 = g575;  } else { _r4099 = a_1341;  } _r4099; });  } _r4098; });  } _r4097; });
}
static int64_t f248_arg_rank(int64_t n_1354, int64_t a_1355, int64_t p_1356) {
if (((p_1356) < (((int64_t)0LL)))) { return ((int64_t)1LL);
 }
if (((a_1355) == (p_1356))) { return ((int64_t)0LL);
 }
int64_t ak_1357 = ((int64_t)(((*({ hrv *_t4100 = &(g550); int64_t _i4100 = a_1355; (S1*)_t4100->b + hr_ix(_i4100, _t4100->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:82"); }))).k_)); 
int64_t pk_1358 = ((int64_t)(((*({ hrv *_t4101 = &(g550); int64_t _i4101 = p_1356; (S1*)_t4101->b + hr_ix(_i4101, _t4101->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:82"); }))).k_)); 
if ((((pk_1358) == (((int64_t)0LL))) || ((ak_1357) == (((int64_t)0LL))))) { return ((int64_t)0LL);
 }
if (((((pk_1358) == (((int64_t)10LL))) && ((((*({ hrv *_t4102 = &(g550); int64_t _i4102 = p_1356; (S1*)_t4102->b + hr_ix(_i4102, _t4102->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:84"); }))).c_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4103 = &(g550); int64_t _i4103 = p_1356; (S1*)_t4103->b + hr_ix(_i4103, _t4103->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:84"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL))))) { int64_t tgt_1359 = ((int64_t)(((*({ hrv *_t4104 = &(g550); int64_t _i4104 = p_1356; (S1*)_t4104->b + hr_ix(_i4104, _t4104->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:84"); }))).a_)); 
if (((f179_deref(a_1355)) == (tgt_1359))) { return ((int64_t)0LL);
 }
if ((((ak_1357) == (((int64_t)12LL))) || ((ak_1357) == (((int64_t)13LL))))) { return f248_arg_rank(n_1354, a_1355, tgt_1359);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if ((((ak_1357) == (((int64_t)10LL))) && ((((*({ hrv *_t4107 = &(g550); int64_t _i4107 = a_1355; (S1*)_t4107->b + hr_ix(_i4107, _t4107->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).c_) < (((int32_t)0LL))))) { int64_t d_1360 = ((int64_t)(((*({ hrv *_t4108 = &(g550); int64_t _i4108 = a_1355; (S1*)_t4108->b + hr_ix(_i4108, _t4108->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).a_)); 
if (((d_1360) == (p_1356))) { return ((int64_t)0LL);
 }
if (((((pk_1358) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4109 = &(g550); int64_t _i4109 = p_1356; (S1*)_t4109->b + hr_ix(_i4109, _t4109->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && ((((*({ hrv *_t4110 = &(g550); int64_t _i4110 = p_1356; (S1*)_t4110->b + hr_ix(_i4110, _t4110->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).a_) == (((*({ hrv *_t4111 = &(g550); int64_t _i4111 = a_1355; (S1*)_t4111->b + hr_ix(_i4111, _t4111->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).a_)))) { return ((int64_t)0LL);
 }
return f248_arg_rank(n_1354, d_1360, p_1356);
 }
if (((ak_1357) == (((int64_t)12LL)))) { M78 _t4113 = f155_cval(n_1354); int64_t v_1361 = _t4113.r0; bool u_1362 = _t4113.r1; bool ok_1363 = _t4113.r2; 
if (((pk_1358) == (((int64_t)3LL)))) { if (((!(ok_1363)) || f158_int_fits(v_1361, u_1362, p_1356))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((pk_1358) == (((int64_t)4LL)))) { return ((int64_t)3LL);
 }
if (((pk_1358) == (((int64_t)17LL)))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1357) == (((int64_t)13LL)))) { if (((pk_1358) == (((int64_t)4LL)))) { return ({ int64_t _r4116; if (((((*({ hrv *_t4117 = &(g550); int64_t _i4117 = p_1356; (S1*)_t4117->b + hr_ix(_i4117, _t4117->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:93"); }))).s_) == (((uint8_t)8LL)))) { _r4116 = ((int64_t)1LL);  } else { _r4116 = ((int64_t)2LL);  } _r4116; });
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1357) == (((int64_t)18LL)))) { if ((((pk_1358) == (((int64_t)9LL))) && ((((int64_t)(((*({ hrv *_t4118 = &(g550); int64_t _i4118 = p_1356; (S1*)_t4118->b + hr_ix(_i4118, _t4118->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:94"); }))).a_))) == (g563)))) { return ((int64_t)0LL);
 }
if (f164_is_byte_arr(p_1356)) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1357) == (((int64_t)19LL)))) { if ((((pk_1358) == (((int64_t)8LL))) || ((pk_1358) == (((int64_t)9LL))))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1357) == (((int64_t)11LL)))) { if ((((pk_1358) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4120 = &(g550); int64_t _i4120 = p_1356; (S1*)_t4120->b + hr_ix(_i4120, _t4120->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:96"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { return ((int64_t)0LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((((pk_1358) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4121 = &(g550); int64_t _i4121 = p_1356; (S1*)_t4121->b + hr_ix(_i4121, _t4121->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:97"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && ((((int64_t)(((*({ hrv *_t4122 = &(g550); int64_t _i4122 = p_1356; (S1*)_t4122->b + hr_ix(_i4122, _t4122->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:97"); }))).a_))) == (a_1355)))) { return ((int64_t)0LL);
 }
if ((((ak_1357) == (((int64_t)3LL))) && ((pk_1358) == (((int64_t)4LL))))) { return ((int64_t)3LL);
 }
if (f152_widens(a_1355, p_1356)) { return ((int64_t)2LL);
 }
if (((((pk_1358) == (((int64_t)9LL))) && (((ak_1357) == (((int64_t)8LL))) || ((ak_1357) == (((int64_t)9LL))))) && ((((*({ hrv *_t4124 = &(g550); int64_t _i4124 = a_1355; (S1*)_t4124->b + hr_ix(_i4124, _t4124->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:100"); }))).a_) == (((*({ hrv *_t4125 = &(g550); int64_t _i4125 = p_1356; (S1*)_t4125->b + hr_ix(_i4125, _t4125->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:100"); }))).a_)))) { return ((int64_t)2LL);
 }
if (((((pk_1358) == (((int64_t)6LL))) && ((ak_1357) == (((int64_t)7LL)))) && ((((*({ hrv *_t4126 = &(g550); int64_t _i4126 = a_1355; (S1*)_t4126->b + hr_ix(_i4126, _t4126->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:101"); }))).a_) == (((*({ hrv *_t4127 = &(g550); int64_t _i4127 = p_1356; (S1*)_t4127->b + hr_ix(_i4127, _t4127->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:101"); }))).a_)))) { return ((int64_t)2LL);
 }
if ((((((pk_1358) == (((int64_t)8LL))) && (((ak_1357) == (((int64_t)8LL))) || ((ak_1357) == (((int64_t)9LL))))) && ((((*({ hrv *_t4128 = &(g550); int64_t _i4128 = a_1355; (S1*)_t4128->b + hr_ix(_i4128, _t4128->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:102"); }))).a_) == (((*({ hrv *_t4129 = &(g550); int64_t _i4129 = p_1356; (S1*)_t4129->b + hr_ix(_i4129, _t4129->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:102"); }))).a_))) && f249_is_construct(n_1354))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f249_is_construct(int64_t n_1364) {
int64_t k_1365 = ((int64_t)(((*({ hrv *_t4131 = &(g703); int64_t _i4131 = n_1364; (S4*)_t4131->b + hr_ix(_i4131, _t4131->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:186"); }))).k_)); 
return ((((k_1365) == (((int64_t)11LL))) || ((k_1365) == (((int64_t)16LL)))) || ((k_1365) == (((int64_t)3LL))));
}
static bool f250_untyped_any(int64_t f_1367) {
{ int32_t _e4133 = ((*({ hrv *_t4134 = &(g703); int64_t _i4134 = f_1367; (S4*)_t4134->b + hr_ix(_i4134, _t4134->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:245"); }))).n_; for (int32_t _k4133 = 0; _k4133 < _e4133; _k4133++) { int32_t j_1368 = (int32_t)_k4133; if (((((*({ hrv *_t4135 = &(g703); int64_t _i4135 = f90_kid(f_1367, ((int64_t)(j_1368))); (S4*)_t4135->b + hr_ix(_i4135, _t4135->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:245"); }))).a_) < (((int32_t)0LL)))) { return true;
 }
 } } _bk4132:; 
return false;
}
static bool f251_is_std_node(int64_t node_1369) {
int64_t f_1370 = f111_node_file(node_1369); 
L49 sp_1371 = f100_lib_path(hr_str("std", 3)); 
return hr_streq(f10_nm(((int64_t)(((*({ hrv *_t4140 = &(g912); int64_t _i4140 = f_1370; (S2*)_t4140->b + hr_ix(_i4140, _t4140->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:196"); }))).name_))), ({ hsl _t4141 = ({ L49 *_t4142 = &(sp_1371); (hsl){ (uint8_t*)_t4142->e, _t4142->n }; }); int64_t _l4141 = 0, _h4141 = _t4141.n; if (_l4141 < 0 || _h4141 < _l4141 || _h4141 > _t4141.n) hr_slerr(_l4141, _h4141, _t4141.n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:196"); (hsl){ _t4141.p + _l4141 * (int64_t)sizeof(uint8_t), _h4141 - _l4141 }; }));
}
static int64_t f252_get_inst(int64_t node_1380, int64_t b0_1381, int64_t bn_1382, int64_t blk_1383, int64_t bown_1384) {
int64_t par_1385 = ({ int64_t _r4143; if (((((uint16_t)((uint64_t)((*({ hrv *_t4144 = &(g703); int64_t _i4144 = node_1380; (S4*)_t4144->b + hr_ix(_i4144, _t4144->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:177"); }))).fl_ & (uint64_t)((uint16_t)128LL)))) != (((uint16_t)0LL)))) { _r4143 = g400;  } else { _r4143 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r4143; }); 
if (((blk_1383) < (((int64_t)0LL)))) { { hrv *_v4146 = &(g387); for (int64_t _k4146 = 0; _k4146 < _v4146->n; _k4146++) { S6 f_1386 = ((S6*)_v4146->b)[_k4146]; int64_t i_1387 = (int64_t)_k4146; if ((((((((int64_t)((f_1386).node_))) == (node_1380)) && (((f_1386).blk_) < (((int32_t)0LL)))) && ((((int64_t)((f_1386).par_))) == (par_1385))) && f253_same_binds(i_1387, b0_1381, bn_1382))) { return i_1387;
 }
 } } _bk4145:; 
 }
int64_t i_1392 = f105_new_inst(node_1380, node_1380, ((int64_t)((*({ hrv *_t4149 = &(g718); int64_t _i4149 = node_1380; (int32_t*)_t4149->b + hr_ix(_i4149, _t4149->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:179"); })))), par_1385); 
{ int32_t *_t4150 = &(((*({ hrv *_t4151 = &(g387); int64_t _i4151 = i_1392; (S6*)_t4151->b + hr_ix(_i4151, _t4151->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:180"); }))).g0_); *_t4150 = ((int32_t)((g393).n)); }
{ int64_t _e4153 = bn_1382; for (int64_t _k4153 = 0; _k4153 < _e4153; _k4153++) { int64_t j_1393 = (int64_t)_k4153; (void)(({ hrv *_v4154 = &(g393); S7 _x4154 = (*({ hrv *_t4155 = &(g313); int64_t _i4155 = ((int64_t)((int64_t)b0_1381 + (int64_t)j_1393)); (S7*)_t4155->b + hr_ix(_i4155, _t4155->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:181"); })); S7 *_p4154 = (S7*)hr_grow(_v4154, 1, sizeof _x4154); *_p4154 = _x4154; _p4154; }));
 } } _bk4152:; 
{ int32_t *_t4156 = &(((*({ hrv *_t4157 = &(g387); int64_t _i4157 = i_1392; (S6*)_t4157->b + hr_ix(_i4157, _t4157->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:182"); }))).gn_); *_t4156 = ((int32_t)(bn_1382)); }
{ int32_t *_t4158 = &(((*({ hrv *_t4159 = &(g387); int64_t _i4159 = i_1392; (S6*)_t4159->b + hr_ix(_i4159, _t4159->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:183"); }))).blk_); *_t4158 = ((int32_t)(blk_1383)); }
{ int32_t *_t4160 = &(((*({ hrv *_t4161 = &(g387); int64_t _i4161 = i_1392; (S6*)_t4161->b + hr_ix(_i4161, _t4161->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:183"); }))).bown_); *_t4160 = ((int32_t)(bown_1384)); }
(void)(f195_sig_inst(i_1392));
(void)(f207_check_inst(i_1392));
return i_1392;
}
static bool f253_same_binds(int64_t i_1388, int64_t b0_1389, int64_t bn_1390) {
if (((((int64_t)(((*({ hrv *_t4164 = &(g387); int64_t _i4164 = i_1388; (S6*)_t4164->b + hr_ix(_i4164, _t4164->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:172"); }))).gn_))) != (bn_1390))) { return false;
 }
{ int64_t _e4166 = bn_1390; for (int64_t _k4166 = 0; _k4166 < _e4166; _k4166++) { int64_t j_1391 = (int64_t)_k4166; if ((((((*({ hrv *_t4167 = &(g393); int64_t _i4167 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4168 = &(g387); int64_t _i4168 = i_1388; (S6*)_t4168->b + hr_ix(_i4168, _t4168->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); }))).g0_)) + (int64_t)j_1391)); (S7*)_t4167->b + hr_ix(_i4167, _t4167->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); }))).ty_) != (((*({ hrv *_t4169 = &(g313); int64_t _i4169 = ((int64_t)((int64_t)b0_1389 + (int64_t)j_1391)); (S7*)_t4169->b + hr_ix(_i4169, _t4169->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); }))).ty_)) || ((((*({ hrv *_t4170 = &(g393); int64_t _i4170 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4171 = &(g387); int64_t _i4171 = i_1388; (S6*)_t4171->b + hr_ix(_i4171, _t4171->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); }))).g0_)) + (int64_t)j_1391)); (S7*)_t4170->b + hr_ix(_i4170, _t4170->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); }))).name_) != (((*({ hrv *_t4172 = &(g313); int64_t _i4172 = ((int64_t)((int64_t)b0_1389 + (int64_t)j_1391)); (S7*)_t4172->b + hr_ix(_i4172, _t4172->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); }))).name_)))) { return false;
 }
 } } _bk4165:; 
return true;
}
static int64_t f254_call_fn(int64_t n_1426, int64_t name_1427, int64_t recv_1428, int64_t want_1429) {
int64_t s_1430 = f226_ck_args(n_1426, ((int64_t)0LL), recv_1428); 
int64_t an_1431 = ((int64_t)((int64_t)(g407).n - (int64_t)s_1430)); 
int64_t blk_1432 = ((int64_t)(((*({ hrv *_t4174 = &(g703); int64_t _i4174 = n_1426; (S4*)_t4174->b + hr_ix(_i4174, _t4174->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:386"); }))).b_)); 
M94 _t4175 = f244_resolve(n_1426, name_1427, f110_ns_of(n_1426), s_1430, an_1431, blk_1432, ((int64_t)(((*({ hrv *_t4178 = &(g703); int64_t _i4178 = n_1426; (S4*)_t4178->b + hr_ix(_i4178, _t4178->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:387"); }))).c_)), true); int64_t fnode_1433 = _t4175.r0; int64_t b0_1434 = _t4175.r1; int64_t bn_1435 = _t4175.r2; 
if (((fnode_1433) < (((int64_t)0LL)))) { hrv m_1436 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o4180 = &(m_1436); hr_fs(_o4180, hr_str("no function ", 12)); hr_fs(_o4180, f10_nm(name_1427)); hr_fs(_o4180, hr_str(" matches (", 10)); }));
{ int64_t _e4183 = an_1431; for (int64_t _k4183 = 0; _k4183 < _e4183; _k4183++) { int64_t j_1437 = (int64_t)_k4183; if (((j_1437) > (((int64_t)0LL)))) { (void)(({ hrv *_v4184 = &(m_1436); hsl _s4184 = hr_str(", ", 2); hr_append(_v4184, _s4184.p, _s4184.n, sizeof(uint8_t)); }));
 }
{ hrv _t4186 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_v4185 = &(m_1436); hsl _s4185 = hr_sl(*hr_tmp(&_t4186, f161_tn(((int64_t)((*({ hrv *_t4188 = &(g407); int64_t _i4188 = ((int64_t)((int64_t)s_1430 + (int64_t)j_1437)); (int32_t*)_t4188->b + hr_ix(_i4188, _t4188->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:390"); }))))))); hr_append(_v4185, _s4185.p, _s4185.n, sizeof(uint8_t)); }));
}
 } } _bk4182:; 
(void)(({ hrv *_v4189 = &(m_1436); hsl _s4189 = hr_str(")", 1); hr_append(_v4189, _s4189.p, _s4189.n, sizeof(uint8_t)); }));
(void)(f108_cerr(n_1426, hr_sl(m_1436)));
(void)(f227_pop_args(s_1430));
(void)(({ hrv *_v4192 = &(g313); int64_t _k4192 = ((int64_t)((int64_t)(g313).n - (int64_t)b0_1434)); if (_k4192 < 0 || _k4192 > _v4192->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:394"); _v4192->n -= _k4192; }));
return f138_set_t(n_1426, g574);
 }
int64_t inst_1438 = f252_get_inst(fnode_1433, b0_1434, bn_1435, blk_1432, g400); 
(void)(({ hrv *_v4195 = &(g313); int64_t _k4195 = ((int64_t)((int64_t)(g313).n - (int64_t)b0_1434)); if (_k4195 < 0 || _k4195 > _v4195->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:398"); _v4195->n -= _k4195; }));
{ int64_t _e4197 = an_1431; for (int64_t _k4197 = 0; _k4197 < _e4197; _k4197++) { int64_t j_1439 = (int64_t)_k4197; int64_t c_1440 = ((int64_t)((*({ hrv *_t4198 = &(g315); int64_t _i4198 = ((int64_t)((int64_t)s_1430 + (int64_t)j_1439)); (int32_t*)_t4198->b + hr_ix(_i4198, _t4198->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:399"); })))); 
int64_t pt_1441 = f208_ptype_of(inst_1438, j_1439); 
if ((((((pt_1441) >= (((int64_t)0LL))) && ((((*({ hrv *_t4200 = &(g550); int64_t _i4200 = pt_1441; (S1*)_t4200->b + hr_ix(_i4200, _t4200->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:399"); }))).k_) == (((uint8_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4201 = &(g550); int64_t _i4201 = pt_1441; (S1*)_t4201->b + hr_ix(_i4201, _t4201->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:399"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))) && ((((*({ hrv *_t4202 = &(g550); int64_t _i4202 = pt_1441; (S1*)_t4202->b + hr_ix(_i4202, _t4202->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:399"); }))).c_) < (((int32_t)0LL))))) { if (f163_is_pending(f141_at(c_1440))) { (void)(f140_conv(c_1440, ((int64_t)(((*({ hrv *_t4206 = &(g550); int64_t _i4206 = pt_1441; (S1*)_t4206->b + hr_ix(_i4206, _t4206->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:399"); }))).a_))));
 }
 } else { (void)(f140_conv(c_1440, pt_1441));
 }
 } } _bk4196:; 
(void)(f227_pop_args(s_1430));
(void)(f228_note_caps_of(inst_1438));
(void)(f229_note_edge(inst_1438));
(void)(f170_set_r(n_1426, ((int64_t)3LL), inst_1438));
int64_t rt_1442 = ((int64_t)(((*({ hrv *_t4212 = &(g387); int64_t _i4212 = inst_1438; (S6*)_t4212->b + hr_ix(_i4212, _t4212->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:403"); }))).ret_)); 
if (((rt_1442) < (((int64_t)0LL)))) { if (((((*({ hrv *_t4213 = &(g387); int64_t _i4213 = inst_1438; (S6*)_t4213->b + hr_ix(_i4213, _t4213->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:404"); }))).st_) == (((uint8_t)1LL)))) { hrv m_1443 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o4215 = &(m_1443); hr_fs(_o4215, hr_str("recursive call to ", 18)); hr_fs(_o4215, f10_nm(name_1427)); hr_fs(_o4215, hr_str(" needs its result type written", 30)); }));
(void)(f108_cerr(n_1426, hr_sl(m_1443)));
 }
return f138_set_t(n_1426, g574);
 }
return f138_set_t(n_1426, rt_1442);
}
static int64_t f255_member_of(hsl name_1448) {
if (hr_streq(name_1448, hr_str("push", 4))) { return ((int64_t)20LL);
 }
if (hr_streq(name_1448, hr_str("append", 6))) { return ((int64_t)21LL);
 }
if (hr_streq(name_1448, hr_str("pop", 3))) { return ((int64_t)22LL);
 }
if (hr_streq(name_1448, hr_str("pop_n", 5))) { return ((int64_t)23LL);
 }
if (hr_streq(name_1448, hr_str("resize", 6))) { return ((int64_t)24LL);
 }
if (hr_streq(name_1448, hr_str("clear", 5))) { return ((int64_t)25LL);
 }
if (hr_streq(name_1448, hr_str("index_of", 8))) { return ((int64_t)26LL);
 }
if (hr_streq(name_1448, hr_str("len", 3))) { return ((int64_t)9LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f256_ck_slit(int64_t n_1451, int64_t want_1452) {
S4 x_1453 = (*({ hrv *_t4220 = &(g703); int64_t _i4220 = n_1451; (S4*)_t4220->b + hr_ix(_i4220, _t4220->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:456"); })); 
int64_t tnode_1454 = ((int64_t)((x_1453).a_)); 
int64_t ns_1455 = f110_ns_of(n_1451); 
int64_t t_1456 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((((*({ hrv *_t4222 = &(g703); int64_t _i4222 = tnode_1454; (S4*)_t4222->b + hr_ix(_i4222, _t4222->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:460"); }))).k_) == (((uint8_t)41LL))) && ((((*({ hrv *_t4223 = &(g703); int64_t _i4223 = tnode_1454; (S4*)_t4223->b + hr_ix(_i4223, _t4223->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:460"); }))).n_) == (((int32_t)0LL)))) && ((f130_gb_find(((int64_t)(((*({ hrv *_t4225 = &(g703); int64_t _i4225 = tnode_1454; (S4*)_t4225->b + hr_ix(_i4225, _t4225->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:460"); }))).s_)))) < (((int64_t)0LL))))) { int64_t d_1457 = f116_lookup_q(((int64_t)(((*({ hrv *_t4227 = &(g703); int64_t _i4227 = tnode_1454; (S4*)_t4227->b + hr_ix(_i4227, _t4227->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:461"); }))).s_)), ns_1455, ((int64_t)1LL)); 
if ((((d_1457) >= (((int64_t)0LL))) && ((((*({ hrv *_t4228 = &(g703); int64_t _i4228 = ((*({ hrv *_t4229 = &(g488); int64_t _i4229 = d_1457; (S5*)_t4229->b + hr_ix(_i4229, _t4229->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:462"); }))).node_; (S4*)_t4228->b + hr_ix(_i4228, _t4228->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:462"); }))).d_) >= (((int32_t)0LL))))) { if (((((want_1452) >= (((int64_t)0LL))) && ((((*({ hrv *_t4230 = &(g550); int64_t _i4230 = want_1452; (S1*)_t4230->b + hr_ix(_i4230, _t4230->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:462"); }))).k_) == (((uint8_t)5LL)))) && ((((*({ hrv *_t4231 = &(g553); int64_t _i4231 = ((*({ hrv *_t4232 = &(g550); int64_t _i4232 = want_1452; (S1*)_t4232->b + hr_ix(_i4232, _t4232->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:462"); }))).a_; (S10*)_t4231->b + hr_ix(_i4231, _t4231->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:462"); }))).node_) == (((*({ hrv *_t4233 = &(g488); int64_t _i4233 = d_1457; (S5*)_t4233->b + hr_ix(_i4233, _t4233->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:462"); }))).node_)))) { t_1456 = want_1452;
 }
 }
 }
if (((t_1456) < (((int64_t)0LL)))) { t_1456 = f113_rtype(tnode_1454, ns_1455);
 }
int64_t si_1458 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((*({ hrv *_t4235 = &(g550); int64_t _i4235 = t_1456; (S1*)_t4235->b + hr_ix(_i4235, _t4235->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:466"); }))).k_) == (((uint8_t)5LL)))) { si_1458 = ((int64_t)(((*({ hrv *_t4236 = &(g550); int64_t _i4236 = t_1456; (S1*)_t4236->b + hr_ix(_i4236, _t4236->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:466"); }))).a_));
 }
if (((((*({ hrv *_t4237 = &(g550); int64_t _i4237 = t_1456; (S1*)_t4237->b + hr_ix(_i4237, _t4237->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:467"); }))).k_) == (((uint8_t)7LL)))) { si_1458 = ((int64_t)(((*({ hrv *_t4238 = &(g556); int64_t _i4238 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4239 = &(g555); int64_t _i4239 = ((*({ hrv *_t4240 = &(g550); int64_t _i4240 = t_1456; (S1*)_t4240->b + hr_ix(_i4240, _t4240->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:467"); }))).a_; (S8*)_t4239->b + hr_ix(_i4239, _t4239->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:467"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t4241 = &(g550); int64_t _i4241 = t_1456; (S1*)_t4241->b + hr_ix(_i4241, _t4241->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:467"); }))).c_)))); (S9*)_t4238->b + hr_ix(_i4238, _t4238->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:467"); }))).si_));
 }
if (((si_1458) < (((int64_t)0LL)))) { if (((((*({ hrv *_t4242 = &(g550); int64_t _i4242 = t_1456; (S1*)_t4242->b + hr_ix(_i4242, _t4242->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:468"); }))).k_) != (((uint8_t)0LL)))) { (void)(f108_cerr(n_1451, hr_str("not a struct type", 17)));
 }
return f138_set_t(n_1451, g574);
 }
int64_t nf_1459 = ((int64_t)(((*({ hrv *_t4245 = &(g553); int64_t _i4245 = si_1458; (S10*)_t4245->b + hr_ix(_i4245, _t4245->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:469"); }))).fnum_)); 
bool named_1460 = ((((x_1453).n_) > (((int32_t)0LL))) && ((((*({ hrv *_t4246 = &(g703); int64_t _i4246 = f90_kid(n_1451, ((int64_t)0LL)); (S4*)_t4246->b + hr_ix(_i4246, _t4246->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:470"); }))).s_) >= (((int32_t)0LL)))); 
int64_t fpos_1461 = ((int64_t)0LL); 
{ int32_t _e4249 = (x_1453).n_; for (int32_t _k4249 = 0; _k4249 < _e4249; _k4249++) { int32_t i_1462 = (int32_t)_k4249; int64_t fi_1463 = f90_kid(n_1451, ((int64_t)(i_1462))); 
int64_t idx_1464 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (named_1460) { idx_1464 = f187_sfield(si_1458, ((int64_t)(((*({ hrv *_t4252 = &(g703); int64_t _i4252 = fi_1463; (S4*)_t4252->b + hr_ix(_i4252, _t4252->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:475"); }))).s_)));
if (((idx_1464) < (((int64_t)0LL)))) { hrv m_1465 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t4257 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o4254 = &(m_1465); hr_fs(_o4254, hr_str("no field ", 9)); hr_fs(_o4254, f10_nm(((int64_t)(((*({ hrv *_t4256 = &(g703); int64_t _i4256 = fi_1463; (S4*)_t4256->b + hr_ix(_i4256, _t4256->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:475"); }))).s_)))); hr_fs(_o4254, hr_str(" in ", 4)); hr_fs(_o4254, hr_sl(*hr_tmp(&_t4257, f161_tn(t_1456)))); }));
}
(void)(f108_cerr(fi_1463, hr_sl(m_1465)));
continue;
 }
 } else { while ((((fpos_1461) < (nf_1459)) && ((((*({ hrv *_t4261 = &(g554); int64_t _i4261 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4262 = &(g553); int64_t _i4262 = si_1458; (S10*)_t4262->b + hr_ix(_i4262, _t4262->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:476"); }))).f0_)) + (int64_t)fpos_1461)); (S11*)_t4261->b + hr_ix(_i4261, _t4261->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:476"); }))).ty_) < (((int32_t)0LL))))) { fpos_1461++;
 } _bk4260:; 
idx_1464 = fpos_1461;
fpos_1461++;
if (((idx_1464) >= (nf_1459))) { (void)(f108_cerr(fi_1463, hr_str("too many initializers", 21)));
continue;
 }
 }
int64_t ft_1466 = ((int64_t)(((*({ hrv *_t4264 = &(g554); int64_t _i4264 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4265 = &(g553); int64_t _i4265 = si_1458; (S10*)_t4265->b + hr_ix(_i4265, _t4265->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:477"); }))).f0_)) + (int64_t)idx_1464)); (S11*)_t4264->b + hr_ix(_i4264, _t4264->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:477"); }))).ty_)); 
(void)(f170_set_r(fi_1463, ((int64_t)5LL), idx_1464));
int64_t v_1467 = ((int64_t)(((*({ hrv *_t4267 = &(g703); int64_t _i4267 = fi_1463; (S4*)_t4267->b + hr_ix(_i4267, _t4267->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:479"); }))).a_)); 
(void)(f137_ck(v_1467, ft_1466));
(void)(f140_conv(v_1467, ft_1466));
 } } _bk4248:; 
{ int64_t _e4271 = nf_1459; for (int64_t _k4271 = 0; _k4271 < _e4271; _k4271++) { int64_t j_1468 = (int64_t)_k4271; S11 f_1469 = (*({ hrv *_t4272 = &(g554); int64_t _i4272 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4273 = &(g553); int64_t _i4273 = si_1458; (S10*)_t4273->b + hr_ix(_i4273, _t4273->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:483"); }))).f0_)) + (int64_t)j_1468)); (S11*)_t4272->b + hr_ix(_i4272, _t4272->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:483"); })); 
if ((((f_1469).ty_) < (((int32_t)0LL)))) { continue;
 }
bool given_1470 = false; 
{ int32_t _e4275 = (x_1453).n_; for (int32_t _k4275 = 0; _k4275 < _e4275; _k4275++) { int32_t i_1471 = (int32_t)_k4275; if (((f157_rv(f90_kid(n_1451, ((int64_t)(i_1471))))) == (j_1468))) { given_1470 = true;
 }
 } } _bk4274:; 
if (((!(given_1470)) && (((f_1469).def_) >= (((int32_t)0LL))))) { int64_t sa_1472 = g400; 
g400 = g402;
(void)(f137_ck(((int64_t)((f_1469).def_)), ((int64_t)((f_1469).ty_))));
(void)(f140_conv(((int64_t)((f_1469).def_)), ((int64_t)((f_1469).ty_))));
g400 = sa_1472;
 }
if (((((!(given_1470)) && (((f_1469).def_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)(x_1453).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) && (!(f165_is_opt(((int64_t)((f_1469).ty_))))))) { hrv m_1473 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t4284 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o4282 = &(m_1473); hr_fs(_o4282, hr_str("missing field ", 14)); hr_fs(_o4282, f10_nm(((int64_t)((f_1469).name_)))); hr_fs(_o4282, hr_str(" in ", 4)); hr_fs(_o4282, hr_sl(*hr_tmp(&_t4284, f161_tn(t_1456)))); }));
}
(void)(f108_cerr(n_1451, hr_sl(m_1473)));
 }
 } } _bk4270:; 
(void)(f170_set_r(n_1451, ((int64_t)9LL), si_1458));
return f138_set_t(n_1451, t_1456);
}
static bool f257_ORD_HAS(int64_t d_1475) {
{ hrv *_v4290 = &(g408); for (int64_t _k4290 = 0; _k4290 < _v4290->n; _k4290++) { int32_t o_1476 = ((int32_t*)_v4290->b)[_k4290]; if (((((int64_t)(o_1476))) == (d_1475))) { return true;
 }
 } } _bk4289:; 
return false;
}
static void f258_propagate_calls(void) {
bool changed_1480 = true; 
while (changed_1480) { changed_1480 = false;
{ hrv *_v4293 = &(g392); for (int64_t _k4293 = 0; _k4293 < _v4293->n; _k4293++) { S15 e_1481 = ((S15*)_v4293->b)[_k4293]; int64_t cr_1482 = ((int64_t)((e_1481).caller_)); 
int64_t ce_1483 = ((int64_t)((e_1481).callee_)); 
if ((((*({ hrv *_t4294 = &(g387); int64_t _i4294 = ce_1483; (S6*)_t4294->b + hr_ix(_i4294, _t4294->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:42"); }))).lr_ && (!(((*({ hrv *_t4295 = &(g387); int64_t _i4295 = cr_1482; (S6*)_t4295->b + hr_ix(_i4295, _t4295->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:42"); }))).lr_)))) { { bool *_t4296 = &(((*({ hrv *_t4297 = &(g387); int64_t _i4297 = cr_1482; (S6*)_t4297->b + hr_ix(_i4297, _t4297->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:42"); }))).lr_); *_t4296 = true; }
changed_1480 = true;
 }
{ hrv *_v4299 = &(g391); for (int64_t _k4299 = 0; _k4299 < _v4299->n; _k4299++) { S13 c_1484 = ((S13*)_v4299->b)[_k4299]; if (((((int64_t)((c_1484).inst_))) == (ce_1483))) { int64_t v_1485 = ((int64_t)((c_1484).lv_)); 
if ((f169_visible_in(((int64_t)(((*({ hrv *_t4301 = &(g388); int64_t _i4301 = v_1485; (S12*)_t4301->b + hr_ix(_i4301, _t4301->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:43"); }))).own_)), cr_1482) || ((((int64_t)(((*({ hrv *_t4302 = &(g388); int64_t _i4302 = v_1485; (S12*)_t4302->b + hr_ix(_i4302, _t4302->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:43"); }))).cfn_))) != (cr_1482)))) { if (f172_add_cap_one(cr_1482, v_1485)) { changed_1480 = true;
 }
 }
 }
 } } _bk4298:; 
 } } _bk4292:; 
 } _bk4291:; 
}
static bool f259_gen_program(hrv* out_1487) {
(void)(({ hrv *_v4304 = &(g163); _v4304->n = 0; }));
{ hrv *_v4306 = &(g387); for (int64_t _k4306 = 0; _k4306 < _v4306->n; _k4306++) { S6 f_1488 = ((S6*)_v4306->b)[_k4306]; int64_t i_1489 = (int64_t)_k4306; if ((((f_1488).tg_ && (((f_1488).ret_) >= (((int32_t)0LL)))) && ((((int64_t)((f_1488).ret_))) != (g557)))) { int64_t sv_1490 = (g163).n; 
(void)(f260_ow(hr_str("static __thread ", 16)));
(void)(f261_ct(((int64_t)((f_1488).ret_))));
(void)(({ hrv *_o4309 = &(g163); hr_fs(_o4309, hr_str(" _lrv", 5)); hr_fi(_o4309, i_1489); hr_fs(_o4309, hr_str(";\012", 2)); }));
(void)(({ hrv *_v4310 = &(g167); hsl _s4310 = ({ hsl _t4311 = hr_sl(g163); int64_t _l4311 = sv_1490, _h4311 = _t4311.n; if (_l4311 < 0 || _h4311 < _l4311 || _h4311 > _t4311.n) hr_slerr(_l4311, _h4311, _t4311.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1104"); (hsl){ _t4311.p + _l4311 * (int64_t)sizeof(uint8_t), _h4311 - _l4311 }; }); hr_append(_v4310, _s4310.p, _s4310.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4312 = &(g163); int64_t _k4312 = sv_1490; if (_k4312 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1104"); hr_resize(_v4312, _k4312, sizeof(uint8_t)); }));
 }
 } } _bk4305:; 
{ hrv *_v4314 = &(g408); for (int64_t _k4314 = 0; _k4314 < _v4314->n; _k4314++) { int32_t d_1531 = ((int32_t*)_v4314->b)[_k4314]; int64_t di_1532 = ((int64_t)(d_1531)); 
int64_t t_1533 = ((int64_t)((*({ hrv *_t4315 = &(g449); int64_t _i4315 = di_1532; (int32_t*)_t4315->b + hr_ix(_i4315, _t4315->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1107"); })))); 
int64_t g_1534 = ((int64_t)(((*({ hrv *_t4316 = &(g488); int64_t _i4316 = di_1532; (S5*)_t4316->b + hr_ix(_i4316, _t4316->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1108"); }))).node_)); 
if ((((f173_const_of(di_1532)) >= (((int64_t)0LL))) && ((((*({ hrv *_t4318 = &(g550); int64_t _i4318 = t_1533; (S1*)_t4318->b + hr_ix(_i4318, _t4318->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1109"); }))).k_) == (((uint8_t)12LL))))) { continue;
 }
int64_t sv_1535 = (g163).n; 
g400 = g402;
g179 = g402;
(void)(f260_ow(hr_str("static ", 7)));
(void)(f261_ct(t_1533));
(void)(({ hrv *_o4321 = &(g163); hr_fs(_o4321, hr_str(" g", 2)); hr_fi(_o4321, di_1532); hr_fs(_o4321, hr_str(";\012", 2)); }));
(void)(({ hrv *_v4322 = &(g167); hsl _s4322 = ({ hsl _t4323 = hr_sl(g163); int64_t _l4323 = sv_1535, _h4323 = _t4323.n; if (_l4323 < 0 || _h4323 < _l4323 || _h4323 > _t4323.n) hr_slerr(_l4323, _h4323, _t4323.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1113"); (hsl){ _t4323.p + _l4323 * (int64_t)sizeof(uint8_t), _h4323 - _l4323 }; }); hr_append(_v4322, _s4322.p, _s4322.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4324 = &(g163); int64_t _k4324 = sv_1535; if (_k4324 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1113"); hr_resize(_v4324, _k4324, sizeof(uint8_t)); }));
S4 x_1536 = (*({ hrv *_t4325 = &(g703); int64_t _i4325 = g_1534; (S4*)_t4325->b + hr_ix(_i4325, _t4325->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1114"); })); 
if ((((x_1536).b_) >= (((int32_t)0LL)))) { int64_t iv_1537 = f90_kid(((int64_t)((x_1536).b_)), ((int64_t)0LL)); 
int64_t sp_1538 = (g163).n; 
(void)(({ hrv *_o4327 = &(g163); hr_fs(_o4327, hr_str("g", 1)); hr_fi(_o4327, di_1532); hr_fs(_o4327, hr_str(" = ", 3)); }));
if (f268_is_res(t_1533)) { (void)(f269_gxo(iv_1537));
 } else { (void)(f289_gx(iv_1537));
 }
(void)(f260_ow(hr_str(";\012", 2)));
if ((((g176).n) > (((int64_t)0LL)))) { (void)(({ hrv *_v4332 = &(g177); _v4332->n = 0; }));
(void)(({ hrv *_v4333 = &(g177); hsl _s4333 = ({ hsl _t4334 = hr_sl(g163); int64_t _l4334 = sp_1538, _h4334 = _t4334.n; if (_l4334 < 0 || _h4334 < _l4334 || _h4334 > _t4334.n) hr_slerr(_l4334, _h4334, _t4334.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1121"); (hsl){ _t4334.p + _l4334 * (int64_t)sizeof(uint8_t), _h4334 - _l4334 }; }); hr_append(_v4333, _s4333.p, _s4333.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4335 = &(g163); int64_t _k4335 = sp_1538; if (_k4335 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1121"); hr_resize(_v4335, _k4335, sizeof(uint8_t)); }));
(void)(f260_ow(hr_str("{ ", 2)));
(void)(({ hrv *_v4337 = &(g163); hsl _s4337 = ({ hsl _t4338 = hr_sl(g176); int64_t _l4338 = 0, _h4338 = _t4338.n; if (_l4338 < 0 || _h4338 < _l4338 || _h4338 > _t4338.n) hr_slerr(_l4338, _h4338, _t4338.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1121"); (hsl){ _t4338.p + _l4338 * (int64_t)sizeof(uint8_t), _h4338 - _l4338 }; }); hr_append(_v4337, _s4337.p, _s4337.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4339 = &(g176); _v4339->n = 0; }));
(void)(({ hrv *_v4340 = &(g163); hsl _s4340 = ({ hsl _t4341 = hr_sl(g177); int64_t _l4341 = 0, _h4341 = _t4341.n; if (_l4341 < 0 || _h4341 < _l4341 || _h4341 > _t4341.n) hr_slerr(_l4341, _h4341, _t4341.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1121"); (hsl){ _t4341.p + _l4341 * (int64_t)sizeof(uint8_t), _h4341 - _l4341 }; }); hr_append(_v4340, _s4340.p, _s4340.n, sizeof(uint8_t)); }));
(void)(f260_ow(hr_str("}\012", 2)));
 }
(void)(({ hrv *_v4343 = &(g168); hsl _s4343 = ({ hsl _t4344 = hr_sl(g163); int64_t _l4344 = sp_1538, _h4344 = _t4344.n; if (_l4344 < 0 || _h4344 < _l4344 || _h4344 > _t4344.n) hr_slerr(_l4344, _h4344, _t4344.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1122"); (hsl){ _t4344.p + _l4344 * (int64_t)sizeof(uint8_t), _h4344 - _l4344 }; }); hr_append(_v4343, _s4343.p, _s4343.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4345 = &(g163); int64_t _k4345 = sp_1538; if (_k4345 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1122"); hr_resize(_v4345, _k4345, sizeof(uint8_t)); }));
 }
 } } _bk4313:; 
int64_t mi_2069 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v4347 = &(g387); for (int64_t _k4347 = 0; _k4347 < _v4347->n; _k4347++) { S6 f_2070 = ((S6*)_v4347->b)[_k4347]; int64_t i_2071 = (int64_t)_k4347; if (((((f_2070).node_) < (((int32_t)0LL))) || (((f_2070).st_) != (((uint8_t)2LL))))) { continue;
 }
int64_t node_2072 = ((int64_t)((f_2070).node_)); 
if ((((((*({ hrv *_t4348 = &(g703); int64_t _i4348 = node_2072; (S4*)_t4348->b + hr_ix(_i4348, _t4348->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1129"); }))).k_) != (((uint8_t)50LL))) || ((((uint16_t)((uint64_t)((*({ hrv *_t4349 = &(g703); int64_t _i4349 = node_2072; (S4*)_t4349->b + hr_ix(_i4349, _t4349->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1129"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))))) { continue;
 }
if (((((f_2070).par_) < (((int32_t)0LL))) && hr_streq(f10_nm(((int64_t)((f_2070).name_))), hr_str("main", 4)))) { mi_2069 = i_2071;
 }
(void)(f361_gen_fn(i_2071));
if ((((g182).n) > (((int64_t)0LL)))) { return false;
 }
 } } _bk4346:; 
(void)(({ hrv *_v4352 = out_1487; hsl _s4352 = hr_str("#include \"hrt.h\"\012", 17); hr_append(_v4352, _s4352.p, _s4352.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4353 = out_1487; hsl _s4353 = hr_sl(g164); hr_append(_v4353, _s4353.p, _s4353.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4354 = out_1487; hsl _s4354 = hr_str("#pragma pack(push, 1)\012", 22); hr_append(_v4354, _s4354.p, _s4354.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4355 = out_1487; hsl _s4355 = hr_sl(g165); hr_append(_v4355, _s4355.p, _s4355.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4356 = out_1487; hsl _s4356 = hr_str("#pragma pack(pop)\012", 18); hr_append(_v4356, _s4356.p, _s4356.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4357 = out_1487; hsl _s4357 = hr_sl(g166); hr_append(_v4357, _s4357.p, _s4357.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4358 = out_1487; hsl _s4358 = hr_sl(g167); hr_append(_v4358, _s4358.p, _s4358.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4359 = out_1487; hsl _s4359 = ({ hsl _t4360 = hr_sl(g169); int64_t _l4360 = 0, _h4360 = _t4360.n; if (_l4360 < 0 || _h4360 < _l4360 || _h4360 > _t4360.n) hr_slerr(_l4360, _h4360, _t4360.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1141"); (hsl){ _t4360.p + _l4360 * (int64_t)sizeof(uint8_t), _h4360 - _l4360 }; }); hr_append(_v4359, _s4359.p, _s4359.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4361 = out_1487; hsl _s4361 = ({ hsl _t4362 = hr_sl(g163); int64_t _l4362 = 0, _h4362 = _t4362.n; if (_l4362 < 0 || _h4362 < _l4362 || _h4362 > _t4362.n) hr_slerr(_l4362, _h4362, _t4362.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1142"); (hsl){ _t4362.p + _l4362 * (int64_t)sizeof(uint8_t), _h4362 - _l4362 }; }); hr_append(_v4361, _s4361.p, _s4361.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4363 = out_1487; hsl _s4363 = hr_str("static void hr_init_globals(void) {\012", 36); hr_append(_v4363, _s4363.p, _s4363.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4364 = out_1487; hsl _s4364 = hr_sl(g168); hr_append(_v4364, _s4364.p, _s4364.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4365 = out_1487; hsl _s4365 = hr_str("}\012", 2); hr_append(_v4365, _s4365.p, _s4365.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4366 = out_1487; hsl _s4366 = hr_str("static void hr_main(void) { ", 28); hr_append(_v4366, _s4366.p, _s4366.n, sizeof(uint8_t)); }));
if (((mi_2069) >= (((int64_t)0LL)))) { int64_t rt_2096 = ((int64_t)(((*({ hrv *_t4367 = &(g387); int64_t _i4367 = mi_2069; (S6*)_t4367->b + hr_ix(_i4367, _t4367->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1145"); }))).ret_)); 
if ((((rt_2096) >= (((int64_t)0LL))) && ((((*({ hrv *_t4368 = &(g550); int64_t _i4368 = rt_2096; (S1*)_t4368->b + hr_ix(_i4368, _t4368->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1145"); }))).k_) == (((uint8_t)3LL))))) { (void)(({ hrv *_v4369 = out_1487; hsl _s4369 = hr_str("hr_flush(); exit((int)", 22); hr_append(_v4369, _s4369.p, _s4369.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4370 = &(g163); _v4370->n = 0; }));
(void)(f323_fn_cname(mi_2069));
(void)(({ hrv *_v4372 = out_1487; hsl _s4372 = ({ hsl _t4373 = hr_sl(g163); int64_t _l4373 = 0, _h4373 = _t4373.n; if (_l4373 < 0 || _h4373 < _l4373 || _h4373 > _t4373.n) hr_slerr(_l4373, _h4373, _t4373.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1145"); (hsl){ _t4373.p + _l4373 * (int64_t)sizeof(uint8_t), _h4373 - _l4373 }; }); hr_append(_v4372, _s4372.p, _s4372.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4374 = out_1487; hsl _s4374 = hr_str("()", 2); hr_append(_v4374, _s4374.p, _s4374.n, sizeof(uint8_t)); }));
if ((((rt_2096) >= (((int64_t)0LL))) && ((((*({ hrv *_t4375 = &(g550); int64_t _i4375 = rt_2096; (S1*)_t4375->b + hr_ix(_i4375, _t4375->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1145"); }))).k_) == (((uint8_t)3LL))))) { (void)(({ hrv *_v4376 = out_1487; hsl _s4376 = hr_str(")", 1); hr_append(_v4376, _s4376.p, _s4376.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4377 = out_1487; hsl _s4377 = hr_str("; ", 2); hr_append(_v4377, _s4377.p, _s4377.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4378 = out_1487; hsl _s4378 = hr_str("}\012", 2); hr_append(_v4378, _s4378.p, _s4378.n, sizeof(uint8_t)); }));
return (((g182).n) == (((int64_t)0LL)));
}
static void f260_ow(hsl s_1491) {
(void)(({ hrv *_v4379 = &(g163); hsl _s4379 = s_1491; hr_append(_v4379, _s4379.p, _s4379.n, sizeof(uint8_t)); }));
}
static void f261_ct(int64_t t_1492) {
(void)(f262_cbody(t_1492));
(void)(f260_ow(f264_cn(t_1492)));
}
static void f262_cbody(int64_t t_1493) {
(void)(f263_cn_grow());
S1 x_1494 = (*({ hrv *_t4384 = &(g550); int64_t _i4384 = t_1493; (S1*)_t4384->b + hr_ix(_i4384, _t4384->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:51"); })); 
int64_t k_1495 = ((int64_t)((x_1494).k_)); 
if ((((k_1495) == (((int64_t)10LL))) || (((*({ hrv *_t4385 = &(g173); int64_t _i4385 = t_1493; (uint8_t*)_t4385->b + hr_ix(_i4385, _t4385->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:52"); }))) != (((uint8_t)0LL))))) { (void)(f264_cn(t_1493));
return;
 }
{ uint8_t *_t4387 = &((*({ hrv *_t4388 = &(g173); int64_t _i4388 = t_1493; (uint8_t*)_t4388->b + hr_ix(_i4388, _t4388->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:53"); }))); *_t4387 = ((uint8_t)1LL); }
(void)(f264_cn(t_1493));
if (((k_1495) == (((int64_t)7LL)))) { S9 v_1509 = (*({ hrv *_t4390 = &(g556); int64_t _i4390 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4391 = &(g555); int64_t _i4391 = (x_1494).a_; (S8*)_t4391->b + hr_ix(_i4391, _t4391->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:55"); }))).v0_)) + (int64_t)((int64_t)((x_1494).c_)))); (S9*)_t4390->b + hr_ix(_i4390, _t4390->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:55"); })); 
if ((((v_1509).si_) >= (((int32_t)0LL)))) { (void)(f262_cbody(f134_t_struct(((int64_t)((v_1509).si_)))));
 }
return;
 }
if (((k_1495) == (((int64_t)5LL)))) { int64_t si_1510 = ((int64_t)((x_1494).a_)); 
(void)(f144_si_layout(si_1510));
int64_t f0_1511 = ((int64_t)(((*({ hrv *_t4395 = &(g553); int64_t _i4395 = si_1510; (S10*)_t4395->b + hr_ix(_i4395, _t4395->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:58"); }))).f0_)); 
int64_t fnum_1512 = ((int64_t)(((*({ hrv *_t4396 = &(g553); int64_t _i4396 = si_1510; (S10*)_t4396->b + hr_ix(_i4396, _t4396->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:58"); }))).fnum_)); 
{ int64_t _e4398 = fnum_1512; for (int64_t _k4398 = 0; _k4398 < _e4398; _k4398++) { int64_t i_1513 = (int64_t)_k4398; int32_t ft_1514 = ((*({ hrv *_t4399 = &(g554); int64_t _i4399 = ((int64_t)((int64_t)f0_1511 + (int64_t)i_1513)); (S11*)_t4399->b + hr_ix(_i4399, _t4399->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:59"); }))).ty_; 
if (((ft_1514) >= (((int32_t)0LL)))) { (void)(f262_cbody(((int64_t)(ft_1514))));
 }
 } } _bk4397:; 
(void)(({ hrv *_v4401 = &(g165); hsl _s4401 = hr_str("struct ", 7); hr_append(_v4401, _s4401.p, _s4401.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4402 = &(g165); hsl _s4402 = f264_cn(t_1493); hr_append(_v4402, _s4402.p, _s4402.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4404 = &(g165); hsl _s4404 = hr_str(" { ", 3); hr_append(_v4404, _s4404.p, _s4404.n, sizeof(uint8_t)); }));
bool any_1515 = false; 
{ int64_t _e4406 = fnum_1512; for (int64_t _k4406 = 0; _k4406 < _e4406; _k4406++) { int64_t i_1516 = (int64_t)_k4406; S11 f_1517 = (*({ hrv *_t4407 = &(g554); int64_t _i4407 = ((int64_t)((int64_t)f0_1511 + (int64_t)i_1516)); (S11*)_t4407->b + hr_ix(_i4407, _t4407->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:63"); })); 
if ((((f_1517).ty_) < (((int32_t)0LL)))) { if ((((f_1517).padn_) > (((int32_t)0LL)))) { (void)(({ hrv *_o4408 = &(g165); hr_fs(_o4408, hr_str("uint8_t _p", 10)); hr_fi(_o4408, i_1516); hr_fs(_o4408, hr_str("[", 1)); hr_fi(_o4408, (f_1517).padn_); hr_fs(_o4408, hr_str("]; ", 3)); }));
any_1515 = true;
 }
continue;
 }
(void)(({ hrv *_v4409 = &(g165); hsl _s4409 = f264_cn(((int64_t)((f_1517).ty_))); hr_append(_v4409, _s4409.p, _s4409.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4411 = &(g165); uint8_t _x4411 = ((uint8_t)32LL); uint8_t *_p4411 = (uint8_t*)hr_grow(_v4411, 1, sizeof _x4411); *_p4411 = _x4411; _p4411; }));
(void)(f267_fname_into((&(g165)), ((int64_t)((f_1517).name_))));
(void)(({ hrv *_v4413 = &(g165); hsl _s4413 = hr_str("; ", 2); hr_append(_v4413, _s4413.p, _s4413.n, sizeof(uint8_t)); }));
any_1515 = true;
 } } _bk4405:; 
if ((!(any_1515))) { (void)(({ hrv *_v4414 = &(g165); hsl _s4414 = hr_str("uint8_t _e; ", 12); hr_append(_v4414, _s4414.p, _s4414.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4415 = &(g165); hsl _s4415 = hr_str("};\012", 3); hr_append(_v4415, _s4415.p, _s4415.n, sizeof(uint8_t)); }));
return;
 }
if (((k_1495) == (((int64_t)6LL)))) { int64_t ei_1521 = ((int64_t)((x_1494).a_)); 
(void)(f146_ei_layout(ei_1521));
int64_t v0_1522 = ((int64_t)(((*({ hrv *_t4417 = &(g555); int64_t _i4417 = ei_1521; (S8*)_t4417->b + hr_ix(_i4417, _t4417->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:73"); }))).v0_)); 
bool pay_1523 = false; 
{ int32_t _e4419 = ((*({ hrv *_t4420 = &(g555); int64_t _i4420 = ei_1521; (S8*)_t4420->b + hr_ix(_i4420, _t4420->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:75"); }))).vnum_; for (int32_t _k4419 = 0; _k4419 < _e4419; _k4419++) { int32_t i_1524 = (int32_t)_k4419; S9 v_1525 = (*({ hrv *_t4421 = &(g556); int64_t _i4421 = ((int64_t)((int64_t)v0_1522 + (int64_t)((int64_t)(i_1524)))); (S9*)_t4421->b + hr_ix(_i4421, _t4421->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:75"); })); 
if (((((v_1525).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4422 = &(g553); int64_t _i4422 = (v_1525).si_; (S10*)_t4422->b + hr_ix(_i4422, _t4422->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:75"); }))).zero_)))) { (void)(f262_cbody(f134_t_struct(((int64_t)((v_1525).si_)))));
pay_1523 = true;
 }
 } } _bk4418:; 
(void)(({ hrv *_v4425 = &(g165); hsl _s4425 = hr_str("struct ", 7); hr_append(_v4425, _s4425.p, _s4425.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4426 = &(g165); hsl _s4426 = f264_cn(t_1493); hr_append(_v4426, _s4426.p, _s4426.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4428 = &(g165); hsl _s4428 = ({ hsl _r4429; if (((((*({ hrv *_t4430 = &(g555); int64_t _i4430 = ei_1521; (S8*)_t4430->b + hr_ix(_i4430, _t4430->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:76"); }))).tagsz_) == (((uint8_t)1LL)))) { _r4429 = hr_str(" { uint8_t tag; ", 16);  } else { _r4429 = hr_str(" { uint16_t tag; ", 17);  } _r4429; }); hr_append(_v4428, _s4428.p, _s4428.n, sizeof(uint8_t)); }));
if (pay_1523) { (void)(({ hrv *_v4431 = &(g165); hsl _s4431 = hr_str("union { ", 8); hr_append(_v4431, _s4431.p, _s4431.n, sizeof(uint8_t)); }));
{ int32_t _e4433 = ((*({ hrv *_t4434 = &(g555); int64_t _i4434 = ei_1521; (S8*)_t4434->b + hr_ix(_i4434, _t4434->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:77"); }))).vnum_; for (int32_t _k4433 = 0; _k4433 < _e4433; _k4433++) { int32_t i_1526 = (int32_t)_k4433; S9 v_1527 = (*({ hrv *_t4435 = &(g556); int64_t _i4435 = ((int64_t)((int64_t)v0_1522 + (int64_t)((int64_t)(i_1526)))); (S9*)_t4435->b + hr_ix(_i4435, _t4435->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:77"); })); 
if (((((v_1527).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4436 = &(g553); int64_t _i4436 = (v_1527).si_; (S10*)_t4436->b + hr_ix(_i4436, _t4436->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:77"); }))).zero_)))) { (void)(({ hrv *_v4437 = &(g165); hsl _s4437 = f264_cn(f134_t_struct(((int64_t)((v_1527).si_)))); hr_append(_v4437, _s4437.p, _s4437.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4440 = &(g165); hr_fs(_o4440, hr_str(" v", 2)); hr_fi(_o4440, i_1526); hr_fs(_o4440, hr_str("; ", 2)); }));
 }
 } } _bk4432:; 
(void)(({ hrv *_v4441 = &(g165); hsl _s4441 = hr_str("} u; ", 5); hr_append(_v4441, _s4441.p, _s4441.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4442 = &(g165); hsl _s4442 = hr_str("};\012", 3); hr_append(_v4442, _s4442.p, _s4442.n, sizeof(uint8_t)); }));
return;
 }
if (((k_1495) == (((int64_t)8LL)))) { int64_t a_1528 = ((int64_t)((x_1494).s_)); 
if ((((a_1528) == (((int64_t)1LL))) || (((a_1528) == (((int64_t)3LL))) && (((x_1494).b_) >= (((int64_t)0LL)))))) { (void)(f262_cbody(((int64_t)((x_1494).a_))));
(void)(({ hrv *_v4444 = &(g165); hsl _s4444 = hr_str("struct ", 7); hr_append(_v4444, _s4444.p, _s4444.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4445 = &(g165); hsl _s4445 = f264_cn(t_1493); hr_append(_v4445, _s4445.p, _s4445.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4447 = &(g165); hsl _s4447 = hr_str(" { ", 3); hr_append(_v4447, _s4447.p, _s4447.n, sizeof(uint8_t)); }));
if (((a_1528) == (((int64_t)3LL)))) { (void)(({ hrv *_v4448 = &(g165); hsl _s4448 = (g183).e[hr_ix(((int64_t)((int64_t)f124_lim_lenstore((x_1494).b_) & (int64_t)((int64_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:86")]; hr_append(_v4448, _s4448.p, _s4448.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4451 = &(g165); hsl _s4451 = hr_str(" n; ", 4); hr_append(_v4451, _s4451.p, _s4451.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4452 = &(g165); hsl _s4452 = f264_cn(((int64_t)((x_1494).a_))); hr_append(_v4452, _s4452.p, _s4452.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4454 = &(g165); hr_fs(_o4454, hr_str(" e[", 3)); hr_fi(_o4454, f103_max((x_1494).b_, ((int64_t)1LL))); hr_fs(_o4454, hr_str("]; };\012", 6)); }));
 }
return;
 }
if (((k_1495) == (((int64_t)14LL)))) { { int32_t _e4457 = (x_1494).n_; for (int32_t _k4457 = 0; _k4457 < _e4457; _k4457++) { int32_t i_1529 = (int32_t)_k4457; (void)(f262_cbody(((int64_t)((*({ hrv *_t4459 = &(g551); int64_t _i4459 = ((int64_t)((int64_t)((int64_t)((x_1494).l_)) + (int64_t)((int64_t)(i_1529)))); (int32_t*)_t4459->b + hr_ix(_i4459, _t4459->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:92"); }))))));
 } } _bk4456:; 
(void)(({ hrv *_v4460 = &(g165); hsl _s4460 = hr_str("struct ", 7); hr_append(_v4460, _s4460.p, _s4460.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4461 = &(g165); hsl _s4461 = f264_cn(t_1493); hr_append(_v4461, _s4461.p, _s4461.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4463 = &(g165); hsl _s4463 = hr_str(" { ", 3); hr_append(_v4463, _s4463.p, _s4463.n, sizeof(uint8_t)); }));
{ int32_t _e4465 = (x_1494).n_; for (int32_t _k4465 = 0; _k4465 < _e4465; _k4465++) { int32_t i_1530 = (int32_t)_k4465; (void)(({ hrv *_v4466 = &(g165); hsl _s4466 = f264_cn(((int64_t)((*({ hrv *_t4468 = &(g551); int64_t _i4468 = ((int64_t)((int64_t)((int64_t)((x_1494).l_)) + (int64_t)((int64_t)(i_1530)))); (int32_t*)_t4468->b + hr_ix(_i4468, _t4468->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:94"); }))))); hr_append(_v4466, _s4466.p, _s4466.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4469 = &(g165); hr_fs(_o4469, hr_str(" r", 2)); hr_fi(_o4469, i_1530); hr_fs(_o4469, hr_str("; ", 2)); }));
 } } _bk4464:; 
(void)(({ hrv *_v4470 = &(g165); hsl _s4470 = hr_str("};\012", 3); hr_append(_v4470, _s4470.p, _s4470.n, sizeof(uint8_t)); }));
 }
}
static void f263_cn_grow(void) {
while ((((g171).n) < ((g550).n))) { (void)(({ hrv *_v4472 = &(g171); int32_t _x4472 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p4472 = (int32_t*)hr_grow(_v4472, 1, sizeof _x4472); *_p4472 = _x4472; _p4472; }));
(void)(({ hrv *_v4473 = &(g172); int32_t _x4473 = ((int32_t)0LL); int32_t *_p4473 = (int32_t*)hr_grow(_v4473, 1, sizeof _x4473); *_p4473 = _x4473; _p4473; }));
(void)(({ hrv *_v4474 = &(g173); uint8_t _x4474 = ((uint8_t)0LL); uint8_t *_p4474 = (uint8_t*)hr_grow(_v4474, 1, sizeof _x4474); *_p4474 = _x4474; _p4474; }));
(void)(({ hrv *_v4475 = &(g174); uint8_t _x4475 = ((uint8_t)0LL); uint8_t *_p4475 = (uint8_t*)hr_grow(_v4475, 1, sizeof _x4475); *_p4475 = _x4475; _p4475; }));
(void)(({ hrv *_v4476 = &(g175); uint8_t _x4476 = ((uint8_t)0LL); uint8_t *_p4476 = (uint8_t*)hr_grow(_v4476, 1, sizeof _x4476); *_p4476 = _x4476; _p4476; }));
 } _bk4471:; 
}
static hsl f264_cn(int64_t t_1496) {
(void)(f263_cn_grow());
if ((((*({ hrv *_t4478 = &(g171); int64_t _i4478 = t_1496; (int32_t*)_t4478->b + hr_ix(_i4478, _t4478->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:23"); }))) < (((int32_t)0LL)))) { (void)(f265_cn_make(t_1496));
 }
int64_t o_1508 = ((int64_t)((*({ hrv *_t4480 = &(g171); int64_t _i4480 = t_1496; (int32_t*)_t4480->b + hr_ix(_i4480, _t4480->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:24"); })))); 
return ({ hsl _t4481 = hr_sl(g170); int64_t _l4481 = o_1508, _h4481 = ((int64_t)((int64_t)o_1508 + (int64_t)((int64_t)((*({ hrv *_t4482 = &(g172); int64_t _i4482 = t_1496; (int32_t*)_t4482->b + hr_ix(_i4482, _t4482->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:25"); })))))); if (_l4481 < 0 || _h4481 < _l4481 || _h4481 > _t4481.n) hr_slerr(_l4481, _h4481, _t4481.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:25"); (hsl){ _t4481.p + _l4481 * (int64_t)sizeof(uint8_t), _h4481 - _l4481 }; });
}
static void f265_cn_make(int64_t t_1497) {
S1 x_1498 = (*({ hrv *_t4483 = &(g550); int64_t _i4483 = t_1497; (S1*)_t4483->b + hr_ix(_i4483, _t4483->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:28"); })); 
int64_t k_1499 = ((int64_t)((x_1498).k_)); 
if ((((k_1499) == (((int64_t)10LL))) && (((x_1498).c_) < (((int32_t)0LL))))) { hsl e_1500 = f264_cn(((int64_t)((x_1498).a_))); 
int64_t s0_1501 = (g170).n; 
(void)(({ hrv *_v4485 = &(g170); hsl _s4485 = e_1500; hr_append(_v4485, _s4485.p, _s4485.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4486 = &(g170); uint8_t _x4486 = ((uint8_t)42LL); uint8_t *_p4486 = (uint8_t*)hr_grow(_v4486, 1, sizeof _x4486); *_p4486 = _x4486; _p4486; }));
{ int32_t *_t4487 = &((*({ hrv *_t4488 = &(g171); int64_t _i4488 = t_1497; (int32_t*)_t4488->b + hr_ix(_i4488, _t4488->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:29"); }))); *_t4487 = ((int32_t)(s0_1501)); }
{ int32_t *_t4489 = &((*({ hrv *_t4490 = &(g172); int64_t _i4490 = t_1497; (int32_t*)_t4490->b + hr_ix(_i4490, _t4490->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:29"); }))); *_t4489 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1501)))); }
return;
 }
if (((k_1499) == (((int64_t)7LL)))) { S9 v_1502 = (*({ hrv *_t4491 = &(g556); int64_t _i4491 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4492 = &(g555); int64_t _i4492 = (x_1498).a_; (S8*)_t4492->b + hr_ix(_i4492, _t4492->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:30"); }))).v0_)) + (int64_t)((int64_t)((x_1498).c_)))); (S9*)_t4491->b + hr_ix(_i4491, _t4491->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:30"); })); 
if ((((v_1502).si_) >= (((int32_t)0LL)))) { hsl e_1503 = f264_cn(f134_t_struct(((int64_t)((v_1502).si_)))); 
int64_t s0_1504 = (g170).n; 
(void)(({ hrv *_v4495 = &(g170); hsl _s4495 = e_1503; hr_append(_v4495, _s4495.p, _s4495.n, sizeof(uint8_t)); }));
{ int32_t *_t4496 = &((*({ hrv *_t4497 = &(g171); int64_t _i4497 = t_1497; (int32_t*)_t4497->b + hr_ix(_i4497, _t4497->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:30"); }))); *_t4496 = ((int32_t)(s0_1504)); }
{ int32_t *_t4498 = &((*({ hrv *_t4499 = &(g172); int64_t _i4499 = t_1497; (int32_t*)_t4499->b + hr_ix(_i4499, _t4499->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:30"); }))); *_t4498 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1504)))); }
return;
 }
 }
int64_t s0_1505 = (g170).n; 
if (((k_1499) == (((int64_t)3LL)))) { (void)(({ hrv *_v4500 = &(g170); hsl _s4500 = (g183).e[hr_ix(((uint8_t)((uint64_t)(x_1498).s_ & (uint64_t)((uint8_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:32")]; hr_append(_v4500, _s4500.p, _s4500.n, sizeof(uint8_t)); }));
 } else { if (((k_1499) == (((int64_t)10LL)))) { (void)(({ hrv *_v4502 = &(g170); hsl _s4502 = (g183).e[hr_ix(((int32_t)((int64_t)((int32_t)((int64_t)(x_1498).c_ & (int64_t)((int32_t)3LL))) + (int64_t)((int32_t)4LL))), 8, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:33")]; hr_append(_v4502, _s4502.p, _s4502.n, sizeof(uint8_t)); }));
 } else { if (((k_1499) == (((int64_t)2LL)))) { (void)(({ hrv *_v4504 = &(g170); hsl _s4504 = hr_str("bool", 4); hr_append(_v4504, _s4504.p, _s4504.n, sizeof(uint8_t)); }));
 } else { if (((k_1499) == (((int64_t)4LL)))) { (void)(({ hrv *_v4505 = &(g170); hsl _s4505 = ({ hsl _r4506; if ((((x_1498).s_) == (((uint8_t)4LL)))) { _r4506 = hr_str("float", 5);  } else { _r4506 = hr_str("double", 6);  } _r4506; }); hr_append(_v4505, _s4505.p, _s4505.n, sizeof(uint8_t)); }));
 } else { if (((k_1499) == (((int64_t)1LL)))) { (void)(({ hrv *_v4507 = &(g170); hsl _s4507 = hr_str("void", 4); hr_append(_v4507, _s4507.p, _s4507.n, sizeof(uint8_t)); }));
 } else { if (((k_1499) == (((int64_t)5LL)))) { (void)(({ hrv *_o4508 = &(g170); hr_fs(_o4508, hr_str("S", 1)); hr_fi(_o4508, (x_1498).a_); }));
(void)(f266_fwd(s0_1505));
 } else { if (((k_1499) == (((int64_t)6LL)))) { (void)(({ hrv *_o4510 = &(g170); hr_fs(_o4510, hr_str("E", 1)); hr_fi(_o4510, (x_1498).a_); }));
(void)(f266_fwd(s0_1505));
 } else { if (((k_1499) == (((int64_t)7LL)))) { (void)(({ hrv *_v4512 = &(g170); hsl _s4512 = hr_str("hr_unit", 7); hr_append(_v4512, _s4512.p, _s4512.n, sizeof(uint8_t)); }));
 } else { if (((k_1499) == (((int64_t)8LL)))) { int64_t a_1507 = ((int64_t)((x_1498).s_)); 
if ((((a_1507) == (((int64_t)4LL))) || ((a_1507) == (((int64_t)5LL))))) { (void)(({ hrv *_v4513 = &(g170); hsl _s4513 = hr_str("hrv", 3); hr_append(_v4513, _s4513.p, _s4513.n, sizeof(uint8_t)); }));
 } else { if (((a_1507) == (((int64_t)1LL)))) { (void)(({ hrv *_o4514 = &(g170); hr_fs(_o4514, hr_str("A", 1)); hr_fi(_o4514, t_1497); }));
(void)(f266_fwd(s0_1505));
 } else { if ((((a_1507) == (((int64_t)3LL))) && (((x_1498).b_) >= (((int64_t)0LL))))) { (void)(({ hrv *_o4516 = &(g170); hr_fs(_o4516, hr_str("L", 1)); hr_fi(_o4516, t_1497); }));
(void)(f266_fwd(s0_1505));
 } else { (void)(({ hrv *_v4518 = &(g170); hsl _s4518 = hr_str("uint8_t*", 8); hr_append(_v4518, _s4518.p, _s4518.n, sizeof(uint8_t)); }));
 }
 }
 }
 } else { if (((((k_1499) == (((int64_t)9LL))) || ((k_1499) == (((int64_t)18LL)))) || ((k_1499) == (((int64_t)19LL))))) { (void)(({ hrv *_v4519 = &(g170); hsl _s4519 = hr_str("hsl", 3); hr_append(_v4519, _s4519.p, _s4519.n, sizeof(uint8_t)); }));
 } else { if (((k_1499) == (((int64_t)14LL)))) { (void)(({ hrv *_o4520 = &(g170); hr_fs(_o4520, hr_str("M", 1)); hr_fi(_o4520, t_1497); }));
(void)(f266_fwd(s0_1505));
 } else { if ((((k_1499) == (((int64_t)12LL))) || ((k_1499) == (((int64_t)17LL))))) { (void)(({ hrv *_v4522 = &(g170); hsl _s4522 = hr_str("int64_t", 7); hr_append(_v4522, _s4522.p, _s4522.n, sizeof(uint8_t)); }));
 } else { if (((k_1499) == (((int64_t)13LL)))) { (void)(({ hrv *_v4523 = &(g170); hsl _s4523 = hr_str("double", 6); hr_append(_v4523, _s4523.p, _s4523.n, sizeof(uint8_t)); }));
 } else { (void)(({ hrv *_v4524 = &(g170); hsl _s4524 = hr_str("void*", 5); hr_append(_v4524, _s4524.p, _s4524.n, sizeof(uint8_t)); }));
 }
 }
 }
 }
 }
 }
 }
 }
 }
 }
 }
 }
 }
{ int32_t *_t4525 = &((*({ hrv *_t4526 = &(g171); int64_t _i4526 = t_1497; (int32_t*)_t4526->b + hr_ix(_i4526, _t4526->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:46"); }))); *_t4525 = ((int32_t)(s0_1505)); }
{ int32_t *_t4527 = &((*({ hrv *_t4528 = &(g172); int64_t _i4528 = t_1497; (int32_t*)_t4528->b + hr_ix(_i4528, _t4528->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:46"); }))); *_t4527 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1505)))); }
}
static void f266_fwd(int64_t s0_1506) {
(void)(({ hrv *_v4529 = &(g164); hsl _s4529 = hr_str("typedef struct ", 15); hr_append(_v4529, _s4529.p, _s4529.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4530 = &(g164); hsl _s4530 = ({ hsl _t4531 = hr_sl(g170); int64_t _l4531 = s0_1506, _h4531 = _t4531.n; if (_l4531 < 0 || _h4531 < _l4531 || _h4531 > _t4531.n) hr_slerr(_l4531, _h4531, _t4531.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:17"); (hsl){ _t4531.p + _l4531 * (int64_t)sizeof(uint8_t), _h4531 - _l4531 }; }); hr_append(_v4530, _s4530.p, _s4530.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4532 = &(g164); uint8_t _x4532 = ((uint8_t)32LL); uint8_t *_p4532 = (uint8_t*)hr_grow(_v4532, 1, sizeof _x4532); *_p4532 = _x4532; _p4532; }));
(void)(({ hrv *_v4533 = &(g164); hsl _s4533 = ({ hsl _t4534 = hr_sl(g170); int64_t _l4534 = s0_1506, _h4534 = _t4534.n; if (_l4534 < 0 || _h4534 < _l4534 || _h4534 > _t4534.n) hr_slerr(_l4534, _h4534, _t4534.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:17"); (hsl){ _t4534.p + _l4534 * (int64_t)sizeof(uint8_t), _h4534 - _l4534 }; }); hr_append(_v4533, _s4533.p, _s4533.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4535 = &(g164); hsl _s4535 = hr_str(";\012", 2); hr_append(_v4535, _s4535.p, _s4535.n, sizeof(uint8_t)); }));
}
static void f267_fname_into(hrv* b_1518, int64_t name_1519) {
{ hsl _v4537 = f10_nm(name_1519); for (int64_t _k4537 = 0; _k4537 < _v4537.n; _k4537++) { uint8_t c_1520 = ((uint8_t*)_v4537.p)[_k4537]; (void)(({ hrv *_v4539 = b_1518; uint8_t _x4539 = ({ uint8_t _r4540; if (((c_1520) == (((uint8_t)58LL)))) { _r4540 = ((uint8_t)95LL);  } else { _r4540 = c_1520;  } _r4540; }); uint8_t *_p4539 = (uint8_t*)hr_grow(_v4539, 1, sizeof _x4539); *_p4539 = _x4539; _p4539; }));
 } } _bk4536:; 
(void)(({ hrv *_v4541 = b_1518; uint8_t _x4541 = ((uint8_t)95LL); uint8_t *_p4541 = (uint8_t*)hr_grow(_v4541, 1, sizeof _x4541); *_p4541 = _x4541; _p4541; }));
}
static bool f268_is_res(int64_t t_1539) {
return (((((*({ hrv *_t4542 = &(g550); int64_t _i4542 = t_1539; (S1*)_t4542->b + hr_ix(_i4542, _t4542->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:18"); }))).k_) == (((uint8_t)8LL))) && (((((int64_t)(((*({ hrv *_t4543 = &(g550); int64_t _i4543 = t_1539; (S1*)_t4543->b + hr_ix(_i4543, _t4543->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:18"); }))).s_))) == (((int64_t)4LL))) || ((((int64_t)(((*({ hrv *_t4544 = &(g550); int64_t _i4544 = t_1539; (S1*)_t4544->b + hr_ix(_i4544, _t4544->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:18"); }))).s_))) == (((int64_t)5LL)))));
}
static void f269_gxo(int64_t n_1540) {
int64_t c_1541 = f150_cv(n_1540); 
int64_t t_1542 = f141_at(n_1540); 
if ((((c_1541) >= (((int64_t)0LL))) && ((c_1541) != (t_1542)))) { if (f268_is_res(c_1541)) { (void)(f270_gcv(n_1540, t_1542, c_1541));
return;
 }
(void)(f289_gx(n_1540));
return;
 }
if ((f268_is_res(t_1542) && f272_is_place(n_1540))) { (void)(f260_ow(hr_str("hr_rdup(", 8)));
(void)(f275_gx0(n_1540));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f326_esz(((int64_t)(((*({ hrv *_t4556 = &(g550); int64_t _i4556 = t_1542; (S1*)_t4556->b + hr_ix(_i4556, _t4556->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:160"); }))).a_))));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
(void)(f275_gx0(n_1540));
}
static void f270_gcv(int64_t n_1543, int64_t f_1544, int64_t t_1545) {
if (((f_1544) == (t_1545))) { (void)(f271_gx1(n_1543));
return;
 }
int64_t fk_2061 = ((int64_t)(((*({ hrv *_t4560 = &(g550); int64_t _i4560 = f_1544; (S1*)_t4560->b + hr_ix(_i4560, _t4560->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:200"); }))).k_)); 
int64_t tk0_2062 = ((int64_t)(((*({ hrv *_t4561 = &(g550); int64_t _i4561 = t_1545; (S1*)_t4561->b + hr_ix(_i4561, _t4561->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:200"); }))).k_)); 
if (((((tk0_2062) == (((int64_t)2LL))) && ((fk_2061) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4562 = &(g550); int64_t _i4562 = f_1544; (S1*)_t4562->b + hr_ix(_i4562, _t4562->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:201"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f271_gx1(n_1543));
(void)(f260_ow(hr_str(") != 0)", 7)));
return;
 }
if (((((fk_2061) == (((int64_t)10LL))) && ((((*({ hrv *_t4566 = &(g550); int64_t _i4566 = f_1544; (S1*)_t4566->b + hr_ix(_i4566, _t4566->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:202"); }))).c_) < (((int32_t)0LL)))) && ((tk0_2062) != (((int64_t)10LL))))) { int64_t m_2063 = ((int64_t)(((*({ hrv *_t4567 = &(g550); int64_t _i4567 = f_1544; (S1*)_t4567->b + hr_ix(_i4567, _t4567->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:203"); }))).a_)); 
if (((m_2063) == (t_1545))) { (void)(f260_ow(hr_str("(*", 2)));
(void)(f271_gx1(n_1543));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if ((((tk0_2062) == (((int64_t)9LL))) && (((((*({ hrv *_t4571 = &(g550); int64_t _i4571 = m_2063; (S1*)_t4571->b + hr_ix(_i4571, _t4571->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:205"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t4572 = &(g550); int64_t _i4572 = m_2063; (S1*)_t4572->b + hr_ix(_i4572, _t4572->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:205"); }))).k_) == (((uint8_t)9LL)))))) { (void)(f292_gsl(n_1543, f_1544));
return;
 }
if ((((tk0_2062) == (((int64_t)3LL))) || ((tk0_2062) == (((int64_t)4LL))))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1545));
(void)(f260_ow(hr_str(")(*", 3)));
(void)(f271_gx1(n_1543));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (f268_is_res(t_1545)) { (void)(f260_ow(hr_str("hr_rfrom(", 9)));
(void)(f292_gsl(n_1543, f_1544));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f326_esz(((int64_t)(((*({ hrv *_t4584 = &(g550); int64_t _i4584 = t_1545; (S1*)_t4584->b + hr_ix(_i4584, _t4584->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:207"); }))).a_))));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
(void)(f260_ow(hr_str("(*", 2)));
(void)(f271_gx1(n_1543));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((((tk0_2062) == (((int64_t)3LL))) || ((tk0_2062) == (((int64_t)4LL)))) && ((((fk_2061) == (((int64_t)3LL))) || ((fk_2061) == (((int64_t)4LL)))) || ((fk_2061) == (((int64_t)2LL)))))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1545));
(void)(f260_ow(hr_str(")(", 2)));
(void)(f271_gx1(n_1543));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (((tk0_2062) == (((int64_t)9LL)))) { (void)(f292_gsl(n_1543, f_1544));
return;
 }
if ((((tk0_2062) == (((int64_t)6LL))) && ((fk_2061) == (((int64_t)7LL))))) { int64_t vi_2064 = ((int64_t)(((*({ hrv *_t4595 = &(g550); int64_t _i4595 = f_1544; (S1*)_t4595->b + hr_ix(_i4595, _t4595->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:213"); }))).c_)); 
int64_t ei_2065 = ((int64_t)(((*({ hrv *_t4596 = &(g550); int64_t _i4596 = f_1544; (S1*)_t4596->b + hr_ix(_i4596, _t4596->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:213"); }))).a_)); 
S9 v_2066 = (*({ hrv *_t4597 = &(g556); int64_t _i4597 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4598 = &(g555); int64_t _i4598 = ei_2065; (S8*)_t4598->b + hr_ix(_i4598, _t4598->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:213"); }))).v0_)) + (int64_t)vi_2064)); (S9*)_t4597->b + hr_ix(_i4597, _t4597->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:213"); })); 
int64_t p_2067 = f293_nt(); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(t_1545));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_2067));
(void)(f260_ow(hr_str("; memset(&_t", 12)));
(void)(f294_oi(p_2067));
(void)(f260_ow(hr_str(", 0, sizeof _t", 14)));
(void)(f294_oi(p_2067));
(void)(f260_ow(hr_str("); _t", 5)));
(void)(f294_oi(p_2067));
(void)(({ hrv *_o4610 = &(g163); hr_fs(_o4610, hr_str(".tag = ", 7)); hr_fi(_o4610, vi_2064); hr_fs(_o4610, hr_str("; ", 2)); }));
if (((((v_2066).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4611 = &(g553); int64_t _i4611 = (v_2066).si_; (S10*)_t4611->b + hr_ix(_i4611, _t4611->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:216"); }))).zero_)))) { (void)(f260_ow(hr_str("_t", 2)));
(void)(f294_oi(p_2067));
(void)(({ hrv *_o4614 = &(g163); hr_fs(_o4614, hr_str(".u.v", 4)); hr_fi(_o4614, vi_2064); hr_fs(_o4614, hr_str(" = ", 3)); }));
(void)(f271_gx1(n_1543));
(void)(f260_ow(hr_str("; ", 2)));
 } else { (void)(f260_ow(hr_str("(void)(", 7)));
(void)(f271_gx1(n_1543));
(void)(f260_ow(hr_str("); ", 3)));
 }
(void)(f260_ow(hr_str("_t", 2)));
(void)(f294_oi(p_2067));
(void)(f260_ow(hr_str("; })", 4)));
return;
 }
if (((tk0_2062) == (((int64_t)10LL)))) { if (((fk_2061) == (((int64_t)10LL)))) { (void)(f271_gx1(n_1543));
return;
 }
(void)(f324_gaddr(n_1543));
return;
 }
if (f268_is_res(t_1545)) { (void)(f260_ow(hr_str("hr_rfrom(", 9)));
(void)(f292_gsl(n_1543, f_1544));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f326_esz(((int64_t)(((*({ hrv *_t4630 = &(g550); int64_t _i4630 = t_1545; (S1*)_t4630->b + hr_ix(_i4630, _t4630->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:221"); }))).a_))));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if ((f282_is_fix(t_1545) || f283_is_lim(t_1545))) { int64_t p_2068 = f293_nt(); 
(void)(f260_ow(hr_str("({ hsl _t", 9)));
(void)(f294_oi(p_2068));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f292_gsl(n_1543, f_1544));
(void)(f260_ow(hr_str("; ", 2)));
(void)(f261_ct(t_1545));
(void)(f260_ow(hr_str(" _r", 3)));
(void)(f294_oi(p_2068));
(void)(f260_ow(hr_str("; ", 2)));
if (f282_is_fix(t_1545)) { (void)(({ hrv *_o4645 = &(g163); hr_fs(_o4645, hr_str("if (_t", 6)); hr_fi(_o4645, p_2068); hr_fs(_o4645, hr_str(".n != ", 6)); hr_fi(_o4645, ((*({ hrv *_t4646 = &(g550); int64_t _i4646 = t_1545; (S1*)_t4646->b + hr_ix(_i4646, _t4646->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:225"); }))).b_); hr_fs(_o4645, hr_str(") hr_die(\"array length mismatch\", ", 34)); }));
(void)(f312_wloc(n_1543));
(void)(f260_ow(hr_str("); ", 3)));
 } else { (void)(({ hrv *_o4649 = &(g163); hr_fs(_o4649, hr_str("if (_t", 6)); hr_fi(_o4649, p_2068); hr_fs(_o4649, hr_str(".n > ", 5)); hr_fi(_o4649, ((*({ hrv *_t4650 = &(g550); int64_t _i4650 = t_1545; (S1*)_t4650->b + hr_ix(_i4650, _t4650->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:226"); }))).b_); hr_fs(_o4649, hr_str(") hr_die(\"too many elements for a limited array\", ", 50)); }));
(void)(f312_wloc(n_1543));
(void)(({ hrv *_o4652 = &(g163); hr_fs(_o4652, hr_str("); _r", 5)); hr_fi(_o4652, p_2068); hr_fs(_o4652, hr_str(".n = _t", 7)); hr_fi(_o4652, p_2068); hr_fs(_o4652, hr_str(".n; ", 4)); }));
 }
(void)(({ hrv *_o4653 = &(g163); hr_fs(_o4653, hr_str("memcpy(_r", 9)); hr_fi(_o4653, p_2068); hr_fs(_o4653, hr_str(".e, _t", 6)); hr_fi(_o4653, p_2068); hr_fs(_o4653, hr_str(".p, (size_t)_t", 14)); hr_fi(_o4653, p_2068); hr_fs(_o4653, hr_str(".n * sizeof _r", 14)); hr_fi(_o4653, p_2068); hr_fs(_o4653, hr_str(".e[0]); _r", 10)); hr_fi(_o4653, p_2068); hr_fs(_o4653, hr_str("; })", 4)); }));
return;
 }
(void)(f271_gx1(n_1543));
}
static void f271_gx1(int64_t n_1546) {
if ((f268_is_res(f141_at(n_1546)) && (!(f272_is_place(n_1546))))) { int64_t k_1554 = f273_tmp(f141_at(n_1546), true); 
(void)(f260_ow(hr_str("(*hr_tmp(&", 10)));
(void)(f274_ot(k_1554));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f275_gx0(n_1546));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
(void)(f275_gx0(n_1546));
}
static bool f272_is_place(int64_t n_1547) {
S4 x_1548 = (*({ hrv *_t4666 = &(g703); int64_t _i4666 = n_1547; (S4*)_t4666->b + hr_ix(_i4666, _t4666->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:122"); })); 
int64_t k_1549 = ((int64_t)((x_1548).k_)); 
if (((k_1549) == (((int64_t)8LL)))) { int64_t r_1550 = f156_rk(n_1547); 
return (((r_1550) == (((int64_t)1LL))) || ((r_1550) == (((int64_t)2LL))));
 }
if (((k_1549) == (((int64_t)14LL)))) { return (((f156_rk(n_1547)) == (((int64_t)5LL))) && (f272_is_place(((int64_t)((x_1548).a_))) || ((((*({ hrv *_t4670 = &(g550); int64_t _i4670 = f141_at(((int64_t)((x_1548).a_))); (S1*)_t4670->b + hr_ix(_i4670, _t4670->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:124"); }))).k_) == (((uint8_t)10LL)))));
 }
if (((k_1549) == (((int64_t)12LL)))) { int64_t bt_1551 = f141_at(((int64_t)((x_1548).a_))); 
return ((((((*({ hrv *_t4673 = &(g550); int64_t _i4673 = f179_deref(bt_1551); (S1*)_t4673->b + hr_ix(_i4673, _t4673->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:125"); }))).k_) == (((uint8_t)9LL))) || f272_is_place(((int64_t)((x_1548).a_)))) || ((((*({ hrv *_t4676 = &(g550); int64_t _i4676 = bt_1551; (S1*)_t4676->b + hr_ix(_i4676, _t4676->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:125"); }))).k_) == (((uint8_t)10LL))));
 }
if ((((k_1549) == (((int64_t)10LL))) && ((((int64_t)((x_1548).op_))) == (((int64_t)49LL))))) { return f272_is_place(((int64_t)((x_1548).a_)));
 }
if (((((k_1549) == (((int64_t)11LL))) && ((f156_rk(n_1547)) == (((int64_t)4LL)))) && ((f157_rv(n_1547)) == (((int64_t)20LL))))) { return true;
 }
return false;
}
static int64_t f273_tmp(int64_t t_1552, bool clean_1553) {
(void)(f262_cbody(t_1552));
g178++;
(void)(({ hrv *_v4681 = &(g176); hsl _s4681 = f264_cn(t_1552); hr_append(_v4681, _s4681.p, _s4681.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4683 = &(g176); hr_fs(_o4683, hr_str(" _t", 3)); hr_fi(_o4683, g178); }));
if (clean_1553) { (void)(({ hrv *_v4684 = &(g176); hsl _s4684 = hr_str(" __attribute__((cleanup(hr_rdrop)))", 35); hr_append(_v4684, _s4684.p, _s4684.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4685 = &(g176); hsl _s4685 = hr_str(" = {0}; ", 8); hr_append(_v4685, _s4685.p, _s4685.n, sizeof(uint8_t)); }));
return g178;
}
static void f274_ot(int64_t k_1555) {
(void)(({ hrv *_o4686 = &(g163); hr_fs(_o4686, hr_str("_t", 2)); hr_fi(_o4686, k_1555); }));
}
static void f275_gx0(int64_t n_1556) {
S4 x_1557 = (*({ hrv *_t4687 = &(g703); int64_t _i4687 = n_1556; (S4*)_t4687->b + hr_ix(_i4687, _t4687->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:711"); })); 
int64_t k_1558 = ((int64_t)((x_1557).k_)); 
if (((k_1558) == (((int64_t)1LL)))) { (void)(f277_oint(((*({ hrv *_t4689 = &(g913); int64_t _i4689 = (x_1557).t_; (S3*)_t4689->b + hr_ix(_i4689, _t4689->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:713"); }))).v_, ((*({ hrv *_t4690 = &(g913); int64_t _i4690 = (x_1557).t_; (S3*)_t4690->b + hr_ix(_i4690, _t4690->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:713"); }))).uns_, f276_fin_lit(n_1556)));
return;
 }
if (((k_1558) == (((int64_t)2LL)))) { int64_t t_1565 = f276_fin_lit(n_1556); 
(void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(({ int64_t _r4695; if (((((*({ hrv *_t4696 = &(g550); int64_t _i4696 = t_1565; (S1*)_t4696->b + hr_ix(_i4696, _t4696->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:714"); }))).k_) == (((uint8_t)4LL)))) { _r4695 = t_1565;  } else { _r4695 = g568;  } _r4695; })));
(void)(f260_ow(hr_str(")", 1)));
(void)(f260_ow(f36_tok_text(((int64_t)((x_1557).t_)))));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((k_1558) == (((int64_t)3LL)))) { (void)(f278_gstr(n_1556));
return;
 }
if (((k_1558) == (((int64_t)4LL)))) { (void)(f260_ow(hr_str("true", 4)));
return;
 }
if (((k_1558) == (((int64_t)5LL)))) { (void)(f260_ow(hr_str("false", 5)));
return;
 }
if (((k_1558) == (((int64_t)6LL)))) { (void)(f260_ow(hr_str("((void*)0)", 10)));
return;
 }
if (((k_1558) == (((int64_t)8LL)))) { int64_t r_1579 = f156_rk(n_1556); 
if (((r_1579) == (((int64_t)1LL)))) { (void)(f284_lv_expr(f157_rv(n_1556)));
return;
 }
if (((r_1579) == (((int64_t)2LL)))) { (void)(({ hrv *_o4708 = &(g163); hr_fs(_o4708, hr_str("g", 1)); hr_fi(_o4708, f157_rv(n_1556)); }));
return;
 }
if (((r_1579) == (((int64_t)6LL)))) { (void)(f277_oint((*({ hrv *_t4711 = &(g435); int64_t _i4711 = f157_rv(n_1556); (int64_t*)_t4711->b + hr_ix(_i4711, _t4711->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:723"); })), false, f276_fin_lit(n_1556)));
return;
 }
(void)(f287_gerr(n_1556, hr_str("unsupported name use", 20)));
return;
 }
if (((k_1558) == (((int64_t)9LL)))) { (void)(f288_gbin(n_1556));
return;
 }
if (((k_1558) == (((int64_t)10LL)))) { (void)(f313_gun(n_1556));
return;
 }
if (((k_1558) == (((int64_t)14LL)))) { int64_t r_1772 = f156_rk(n_1556); 
int64_t a_1773 = ((int64_t)((x_1557).a_)); 
if ((((r_1772) == (((int64_t)7LL))) && ((((*({ hrv *_t4718 = &(g550); int64_t _i4718 = f141_at(n_1556); (S1*)_t4718->b + hr_ix(_i4718, _t4718->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:731"); }))).k_) == (((uint8_t)7LL))))) { int64_t t_1774 = f141_at(n_1556); 
S9 v_1775 = (*({ hrv *_t4721 = &(g556); int64_t _i4721 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4722 = &(g555); int64_t _i4722 = ((*({ hrv *_t4723 = &(g550); int64_t _i4723 = t_1774; (S1*)_t4723->b + hr_ix(_i4723, _t4723->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:731"); }))).a_; (S8*)_t4722->b + hr_ix(_i4722, _t4722->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:731"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t4724 = &(g550); int64_t _i4724 = t_1774; (S1*)_t4724->b + hr_ix(_i4724, _t4724->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:731"); }))).c_)))); (S9*)_t4721->b + hr_ix(_i4721, _t4721->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:731"); })); 
if ((((v_1775).si_) >= (((int32_t)0LL)))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1774));
(void)(f260_ow(hr_str("){0})", 5)));
 } else { (void)(f260_ow(hr_str("((hr_unit)0)", 12)));
 }
return;
 }
if (((r_1772) == (((int64_t)7LL)))) { int64_t t_1776 = f141_at(n_1556); 
int64_t p_1777 = f293_nt(); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(t_1776));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_1777));
(void)(({ hrv *_o4735 = &(g163); hr_fs(_o4735, hr_str("; memset(&_t", 12)); hr_fi(_o4735, p_1777); hr_fs(_o4735, hr_str(", 0, sizeof _t", 14)); hr_fi(_o4735, p_1777); hr_fs(_o4735, hr_str("); _t", 5)); hr_fi(_o4735, p_1777); hr_fs(_o4735, hr_str(".tag = ", 7)); hr_fi(_o4735, f157_rv(n_1556)); hr_fs(_o4735, hr_str("; _t", 4)); hr_fi(_o4735, p_1777); hr_fs(_o4735, hr_str("; })", 4)); }));
return;
 }
if (((r_1772) == (((int64_t)8LL)))) { int64_t d_1778 = f179_deref(f141_at(a_1773)); 
if (((f157_rv(n_1556)) == (((int64_t)2LL)))) { (void)(({ hrv *_o4740 = &(g163); hr_fs(_o4740, hr_str("((int64_t)", 10)); hr_fi(_o4740, ((*({ hrv *_t4741 = &(g550); int64_t _i4741 = d_1778; (S1*)_t4741->b + hr_ix(_i4741, _t4741->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:735"); }))).b_); hr_fs(_o4740, hr_str(")", 1)); }));
return;
 }
if (f282_is_fix(d_1778)) { (void)(({ hrv *_o4743 = &(g163); hr_fs(_o4743, hr_str("((int64_t)", 10)); hr_fi(_o4743, ((*({ hrv *_t4744 = &(g550); int64_t _i4744 = d_1778; (S1*)_t4744->b + hr_ix(_i4744, _t4744->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:736"); }))).b_); hr_fs(_o4743, hr_str(")", 1)); }));
return;
 }
if (f283_is_lim(d_1778)) { (void)(f260_ow(hr_str("((int64_t)(", 11)));
if (((((*({ hrv *_t4747 = &(g550); int64_t _i4747 = f141_at(a_1773); (S1*)_t4747->b + hr_ix(_i4747, _t4747->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:737"); }))).k_) == (((uint8_t)10LL)))) { (void)(f275_gx0(a_1773));
(void)(f260_ow(hr_str(")->n)", 5)));
 } else { (void)(f289_gx(a_1773));
(void)(f260_ow(hr_str(").n)", 4)));
 }
return;
 }
if (((((*({ hrv *_t4753 = &(g550); int64_t _i4753 = f141_at(a_1773); (S1*)_t4753->b + hr_ix(_i4753, _t4753->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:738"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f275_gx0(a_1773));
(void)(f260_ow(hr_str(")->n)", 5)));
return;
 }
(void)(f260_ow(hr_str("(", 1)));
(void)(f289_gx(a_1773));
(void)(f260_ow(hr_str(").n", 3)));
return;
 }
if (((r_1772) == (((int64_t)5LL)))) { int64_t bt_1779 = f141_at(a_1773); 
int64_t st_1780 = f179_deref(bt_1779); 
int64_t si_1781 = ({ int64_t _r4763; if (((((*({ hrv *_t4764 = &(g550); int64_t _i4764 = st_1780; (S1*)_t4764->b + hr_ix(_i4764, _t4764->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:744"); }))).k_) == (((uint8_t)5LL)))) { _r4763 = ((int64_t)(((*({ hrv *_t4765 = &(g550); int64_t _i4765 = st_1780; (S1*)_t4765->b + hr_ix(_i4765, _t4765->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:744"); }))).a_));  } else { _r4763 = f217_ax(n_1556);  } _r4763; }); 
S11 f_1782 = (*({ hrv *_t4767 = &(g554); int64_t _i4767 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4768 = &(g553); int64_t _i4768 = si_1781; (S10*)_t4768->b + hr_ix(_i4768, _t4768->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:745"); }))).f0_)) + (int64_t)f157_rv(n_1556))); (S11*)_t4767->b + hr_ix(_i4767, _t4767->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:745"); })); 
(void)(f260_ow(hr_str("(", 1)));
if (((((*({ hrv *_t4771 = &(g550); int64_t _i4771 = bt_1779; (S1*)_t4771->b + hr_ix(_i4771, _t4771->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:747"); }))).k_) == (((uint8_t)10LL)))) { (void)(f275_gx0(a_1773));
(void)(f260_ow(hr_str(")->", 3)));
 } else { (void)(f289_gx(a_1773));
(void)(f260_ow(hr_str(").", 2)));
 }
(void)(f267_fname_into((&(g163)), ((int64_t)((f_1782).name_))));
return;
 }
(void)(f287_gerr(n_1556, hr_str("unsupported member", 18)));
return;
 }
if (((k_1558) == (((int64_t)12LL)))) { (void)(f315_gidx(n_1556));
return;
 }
if (((k_1558) == (((int64_t)13LL)))) { (void)(f316_gslice(n_1556));
return;
 }
if (((k_1558) == (((int64_t)15LL)))) { int64_t t_1797 = f141_at(n_1556); 
int64_t ft_1798 = ((int64_t)(((*({ hrv *_t4781 = &(g550); int64_t _i4781 = f279_fin(((int64_t)((x_1557).a_))); (S1*)_t4781->b + hr_ix(_i4781, _t4781->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:755"); }))).k_)); 
if ((((((*({ hrv *_t4783 = &(g550); int64_t _i4783 = t_1797; (S1*)_t4783->b + hr_ix(_i4783, _t4783->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:755"); }))).k_) == (((uint8_t)3LL))) && (((ft_1798) == (((int64_t)4LL))) || ((ft_1798) == (((int64_t)13LL)))))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1797));
(void)(f260_ow(hr_str(")hr_f2i(", 8)));
(void)(f289_gx(((int64_t)((x_1557).a_))));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
(void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1797));
(void)(f260_ow(hr_str(")(", 2)));
(void)(f289_gx(((int64_t)((x_1557).a_))));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (((k_1558) == (((int64_t)16LL)))) { (void)(f317_garr(n_1556));
return;
 }
if (((k_1558) == (((int64_t)17LL)))) { (void)(f318_gslit(n_1556));
return;
 }
if (((k_1558) == (((int64_t)11LL)))) { (void)(f319_gcall(n_1556));
return;
 }
if (((k_1558) == (((int64_t)23LL)))) { (void)(f260_ow(hr_str("({ ", 3)));
(void)(f341_gblk(n_1556, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((f141_at(n_1556)) != (g557))));
(void)(f260_ow(hr_str(" })", 3)));
return;
 }
if ((((((k_1558) == (((int64_t)19LL))) || ((k_1558) == (((int64_t)20LL)))) || ((k_1558) == (((int64_t)24LL)))) || ((k_1558) == (((int64_t)26LL))))) { int64_t t_2059 = f141_at(n_1556); 
if ((((t_2059) == (g557)) || ((t_2059) < (((int64_t)0LL))))) { (void)(f260_ow(hr_str("({ ", 3)));
(void)(f334_gstmt(n_1556));
(void)(f260_ow(hr_str(" })", 3)));
return;
 }
int64_t r_2060 = f293_nt(); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(t_2059));
(void)(f260_ow(hr_str(" _r", 3)));
(void)(f294_oi(r_2060));
(void)(f260_ow(hr_str("; ", 2)));
if (((k_1558) == (((int64_t)19LL)))) { (void)(f340_gif(n_1556, r_2060));
 } else { if (((k_1558) == (((int64_t)20LL)))) { (void)(f348_gmatch(n_1556, r_2060));
 } else { if (((k_1558) == (((int64_t)24LL)))) { (void)(f349_geblock(n_1556, r_2060));
 } else { (void)(f346_gloop(n_1556, r_2060));
 }
 }
 }
(void)(f260_ow(hr_str(" _r", 3)));
(void)(f294_oi(r_2060));
(void)(f260_ow(hr_str("; })", 4)));
return;
 }
if (((((((k_1558) == (((int64_t)28LL))) || ((k_1558) == (((int64_t)29LL)))) || ((k_1558) == (((int64_t)30LL)))) || ((k_1558) == (((int64_t)25LL)))) || ((k_1558) == (((int64_t)27LL))))) { (void)(f260_ow(hr_str("({ ", 3)));
(void)(f334_gstmt(n_1556));
(void)(f260_ow(hr_str(" })", 3)));
return;
 }
(void)(f287_gerr(n_1556, hr_str("unsupported expression in codegen", 33)));
}
static int64_t f276_fin_lit(int64_t n_1559) {
int64_t t_1560 = f141_at(n_1559); 
return ({ int64_t _r4823; if ((((t_1560) < (((int64_t)0LL))) || ((((*({ hrv *_t4824 = &(g550); int64_t _i4824 = t_1560; (S1*)_t4824->b + hr_ix(_i4824, _t4824->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:774"); }))).k_) == (((uint8_t)12LL))))) { _r4823 = g562;  } else { _r4823 = ({ int64_t _r4825; if (((((*({ hrv *_t4826 = &(g550); int64_t _i4826 = t_1560; (S1*)_t4826->b + hr_ix(_i4826, _t4826->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:774"); }))).k_) == (((uint8_t)13LL)))) { _r4825 = g568;  } else { _r4825 = t_1560;  } _r4825; });  } _r4823; });
}
static void f277_oint(int64_t v_1561, bool uns_1562, int64_t t_1563) {
int64_t k_1564 = ((int64_t)(((*({ hrv *_t4827 = &(g550); int64_t _i4827 = t_1563; (S1*)_t4827->b + hr_ix(_i4827, _t4827->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:140"); }))).k_)); 
if (((k_1564) == (((int64_t)4LL)))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1563));
(void)(f260_ow(hr_str(")", 1)));
if (uns_1562) { (void)(({ hrv *_o4831 = &(g163); hr_fu(_o4831, ((uint64_t)(v_1561))); hr_fs(_o4831, hr_str(".0", 2)); }));
 } else { (void)(({ hrv *_o4832 = &(g163); hr_fi(_o4832, v_1561); hr_fs(_o4832, hr_str(".0", 2)); }));
 }
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((k_1564) == (((int64_t)2LL)))) { (void)(f260_ow(({ hsl _r4835; if (((v_1561) != (((int64_t)0LL)))) { _r4835 = hr_str("true", 4);  } else { _r4835 = hr_str("false", 5);  } _r4835; })));
return;
 }
(void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(({ int64_t _r4838; if (((k_1564) == (((int64_t)3LL)))) { _r4838 = t_1563;  } else { _r4838 = g562;  } _r4838; })));
(void)(f260_ow(hr_str(")", 1)));
if (uns_1562) { (void)(({ hrv *_o4840 = &(g163); hr_fu(_o4840, ((uint64_t)(v_1561))); hr_fs(_o4840, hr_str("ULL)", 4)); }));
return;
 }
if (((v_1561) == (((int64_t)((int64_t)((int64_t)(0 - (uint64_t)(((int64_t)9223372036854775807LL)))) - (int64_t)((int64_t)1LL)))))) { (void)(f260_ow(hr_str("(-9223372036854775807LL-1))", 27)));
return;
 }
(void)(({ hrv *_o4842 = &(g163); hr_fi(_o4842, v_1561); hr_fs(_o4842, hr_str("LL)", 3)); }));
}
static void f278_gstr(int64_t n_1566) {
int64_t t_1570 = f279_fin(n_1566); 
hsl s_1573 = f280_tok_str(((int64_t)(((*({ hrv *_t4845 = &(g703); int64_t _i4845 = n_1566; (S4*)_t4845->b + hr_ix(_i4845, _t4845->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:338"); }))).t_))); 
int64_t a_1574 = f141_at(n_1566); 
if (f268_is_res(a_1574)) { (void)(f260_ow(hr_str("hr_rfrom(hr_str(", 16)));
(void)(f281_cstr_lit(s_1573));
(void)(({ hrv *_o4850 = &(g163); hr_fs(_o4850, hr_str(", ", 2)); hr_fi(_o4850, (s_1573).n); hr_fs(_o4850, hr_str("), 1)", 5)); }));
return;
 }
if (f282_is_fix(a_1574)) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(a_1574));
(void)(f260_ow(hr_str("){ ", 3)));
(void)(f281_cstr_lit(s_1573));
(void)(f260_ow(hr_str(" })", 3)));
return;
 }
if (f283_is_lim(a_1574)) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(a_1574));
(void)(({ hrv *_o4860 = &(g163); hr_fs(_o4860, hr_str("){ ", 3)); hr_fi(_o4860, (s_1573).n); hr_fs(_o4860, hr_str(", ", 2)); }));
(void)(f281_cstr_lit(s_1573));
(void)(f260_ow(hr_str(" })", 3)));
return;
 }
(void)(f260_ow(hr_str("hr_str(", 7)));
(void)(f281_cstr_lit(s_1573));
(void)(({ hrv *_o4865 = &(g163); hr_fs(_o4865, hr_str(", ", 2)); hr_fi(_o4865, (s_1573).n); hr_fs(_o4865, hr_str(")", 1)); }));
}
static int64_t f279_fin(int64_t n_1567) {
int64_t c_1568 = f150_cv(n_1567); 
return ({ int64_t _r4867; if (((c_1568) >= (((int64_t)0LL)))) { _r4867 = c_1568;  } else { int64_t t_1569 = f141_at(n_1567); 
_r4867 = ({ int64_t _r4869; if (((t_1569) < (((int64_t)0LL)))) { _r4869 = g557;  } else { _r4869 = t_1569;  } _r4869; });  } _r4867; });
}
static hsl f280_tok_str(int64_t t_1571) {
S3 x_1572 = (*({ hrv *_t4870 = &(g913); int64_t _i4870 = t_1571; (S3*)_t4870->b + hr_ix(_i4870, _t4870->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:182"); })); 
return ({ hsl _t4871 = hr_sl(g909); int64_t _l4871 = ((int64_t)((x_1572).v_)), _h4871 = ((int64_t)((int64_t)((int64_t)((x_1572).v_)) + (int64_t)((int64_t)((x_1572).w_)))); if (_l4871 < 0 || _h4871 < _l4871 || _h4871 > _t4871.n) hr_slerr(_l4871, _h4871, _t4871.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:182"); (hsl){ _t4871.p + _l4871 * (int64_t)sizeof(uint8_t), _h4871 - _l4871 }; });
}
static void f281_cstr_lit(hsl s_1575) {
(void)(({ hrv *_v4872 = &(g163); uint8_t _x4872 = ((uint8_t)34LL); uint8_t *_p4872 = (uint8_t*)hr_grow(_v4872, 1, sizeof _x4872); *_p4872 = _x4872; _p4872; }));
{ hsl _v4874 = s_1575; for (int64_t _k4874 = 0; _k4874 < _v4874.n; _k4874++) { uint8_t c_1576 = ((uint8_t*)_v4874.p)[_k4874]; if ((((c_1576) == (((uint8_t)34LL))) || ((c_1576) == (((uint8_t)92LL))))) { (void)(({ hrv *_v4875 = &(g163); uint8_t _x4875 = ((uint8_t)92LL); uint8_t *_p4875 = (uint8_t*)hr_grow(_v4875, 1, sizeof _x4875); *_p4875 = _x4875; _p4875; }));
(void)(({ hrv *_v4876 = &(g163); uint8_t _x4876 = c_1576; uint8_t *_p4876 = (uint8_t*)hr_grow(_v4876, 1, sizeof _x4876); *_p4876 = _x4876; _p4876; }));
 } else { if (((((c_1576) >= (((uint8_t)32LL))) && ((c_1576) < (((uint8_t)127LL)))) && ((c_1576) != (((uint8_t)63LL))))) { (void)(({ hrv *_v4877 = &(g163); uint8_t _x4877 = c_1576; uint8_t *_p4877 = (uint8_t*)hr_grow(_v4877, 1, sizeof _x4877); *_p4877 = _x4877; _p4877; }));
 } else { (void)(({ hrv *_v4878 = &(g163); uint8_t _x4878 = ((uint8_t)92LL); uint8_t *_p4878 = (uint8_t*)hr_grow(_v4878, 1, sizeof _x4878); *_p4878 = _x4878; _p4878; }));
(void)(({ hrv *_v4879 = &(g163); uint8_t _x4879 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)((uint8_t)((c_1576) >> ((((uint8_t)6LL)) & 7))) & (uint64_t)((uint8_t)7LL))))); uint8_t *_p4879 = (uint8_t*)hr_grow(_v4879, 1, sizeof _x4879); *_p4879 = _x4879; _p4879; }));
(void)(({ hrv *_v4880 = &(g163); uint8_t _x4880 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)((uint8_t)((c_1576) >> ((((uint8_t)3LL)) & 7))) & (uint64_t)((uint8_t)7LL))))); uint8_t *_p4880 = (uint8_t*)hr_grow(_v4880, 1, sizeof _x4880); *_p4880 = _x4880; _p4880; }));
(void)(({ hrv *_v4881 = &(g163); uint8_t _x4881 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)c_1576 & (uint64_t)((uint8_t)7LL))))); uint8_t *_p4881 = (uint8_t*)hr_grow(_v4881, 1, sizeof _x4881); *_p4881 = _x4881; _p4881; }));
 }
 }
 } } _bk4873:; 
(void)(({ hrv *_v4882 = &(g163); uint8_t _x4882 = ((uint8_t)34LL); uint8_t *_p4882 = (uint8_t*)hr_grow(_v4882, 1, sizeof _x4882); *_p4882 = _x4882; _p4882; }));
}
static bool f282_is_fix(int64_t t_1577) {
return (((((*({ hrv *_t4883 = &(g550); int64_t _i4883 = t_1577; (S1*)_t4883->b + hr_ix(_i4883, _t4883->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:20"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t4884 = &(g550); int64_t _i4884 = t_1577; (S1*)_t4884->b + hr_ix(_i4884, _t4884->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:20"); }))).s_))) == (((int64_t)1LL))));
}
static bool f283_is_lim(int64_t t_1578) {
return (((((*({ hrv *_t4885 = &(g550); int64_t _i4885 = t_1578; (S1*)_t4885->b + hr_ix(_i4885, _t4885->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:19"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t4886 = &(g550); int64_t _i4886 = t_1578; (S1*)_t4886->b + hr_ix(_i4886, _t4886->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:19"); }))).s_))) == (((int64_t)3LL))));
}
static void f284_lv_expr(int64_t v_1580) {
bool p_1582 = f285_lv_isptr(v_1580); 
if (((((int64_t)(((*({ hrv *_t4888 = &(g388); int64_t _i4888 = v_1580; (S12*)_t4888->b + hr_ix(_i4888, _t4888->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:115"); }))).cfn_))) != (g179))) { (void)(f260_ow(({ hsl _r4890; if (p_1582) { _r4890 = hr_str("(**c", 4);  } else { _r4890 = hr_str("(*c", 3);  } _r4890; })));
(void)(({ hrv *_o4891 = &(g163); hr_fi(_o4891, v_1580); hr_fs(_o4891, hr_str(")", 1)); }));
return;
 }
if (p_1582) { (void)(f260_ow(hr_str("(*", 2)));
(void)(f286_lv_name(v_1580));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
(void)(f286_lv_name(v_1580));
}
static bool f285_lv_isptr(int64_t v_1581) {
return (((((uint16_t)((uint64_t)((*({ hrv *_t4896 = &(g388); int64_t _i4896 = v_1581; (S12*)_t4896->b + hr_ix(_i4896, _t4896->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:112"); }))).fl_ & (uint64_t)((uint16_t)8LL)))) != (((uint16_t)0LL))) && ((((*({ hrv *_t4897 = &(g550); int64_t _i4897 = ((*({ hrv *_t4898 = &(g388); int64_t _i4898 = v_1581; (S12*)_t4898->b + hr_ix(_i4898, _t4898->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:112"); }))).ty_; (S1*)_t4897->b + hr_ix(_i4897, _t4897->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:112"); }))).k_) != (((uint8_t)10LL))));
}
static void f286_lv_name(int64_t v_1583) {
{ hsl _v4900 = f10_nm(((int64_t)(((*({ hrv *_t4902 = &(g388); int64_t _i4902 = v_1583; (S12*)_t4902->b + hr_ix(_i4902, _t4902->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:111"); }))).name_))); for (int64_t _k4900 = 0; _k4900 < _v4900.n; _k4900++) { uint8_t c_1584 = ((uint8_t*)_v4900.p)[_k4900]; (void)(({ hrv *_v4903 = &(g163); uint8_t _x4903 = ({ uint8_t _r4904; if ((((c_1584) == (((uint8_t)36LL))) || ((c_1584) == (((uint8_t)58LL))))) { _r4904 = ((uint8_t)95LL);  } else { _r4904 = c_1584;  } _r4904; }); uint8_t *_p4903 = (uint8_t*)hr_grow(_v4903, 1, sizeof _x4903); *_p4903 = _x4903; _p4903; }));
 } } _bk4899:; 
(void)(({ hrv *_o4905 = &(g163); hr_fs(_o4905, hr_str("_", 1)); hr_fi(_o4905, v_1583); }));
}
static void f287_gerr(int64_t n_1585, hsl m_1586) {
if ((((g182).n) > (((int64_t)0LL)))) { return;
 }
S3 x_1587 = (*({ hrv *_t4906 = &(g913); int64_t _i4906 = ((*({ hrv *_t4907 = &(g703); int64_t _i4907 = f103_max(n_1585, ((int64_t)0LL)); (S4*)_t4907->b + hr_ix(_i4907, _t4907->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:15"); }))).t_; (S3*)_t4906->b + hr_ix(_i4906, _t4906->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:15"); })); 
(void)(({ hrv *_v4909 = &(g182); hsl _s4909 = f10_nm(((int64_t)(((*({ hrv *_t4911 = &(g912); int64_t _i4911 = (x_1587).f_; (S2*)_t4911->b + hr_ix(_i4911, _t4911->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:15"); }))).name_))); hr_append(_v4909, _s4909.p, _s4909.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4912 = &(g182); hr_fs(_o4912, hr_str(":", 1)); hr_fi(_o4912, (x_1587).line_); hr_fs(_o4912, hr_str(": error: ", 9)); hr_fs(_o4912, m_1586); }));
}
static void f288_gbin(int64_t n_1588) {
S4 x_1589 = (*({ hrv *_t4913 = &(g703); int64_t _i4913 = n_1588; (S4*)_t4913->b + hr_ix(_i4913, _t4913->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:256"); })); 
int64_t o_1590 = ((int64_t)((x_1589).op_)); 
int64_t a_1591 = ((int64_t)((x_1589).a_)); 
int64_t b_1592 = ((int64_t)((x_1589).b_)); 
if ((((o_1590) == (((int64_t)52LL))) || ((o_1590) == (((int64_t)53LL))))) { (void)(f260_ow(hr_str("(", 1)));
(void)(f289_gx(a_1591));
(void)(f260_ow(({ hsl _r4917; if (((o_1590) == (((int64_t)52LL)))) { _r4917 = hr_str(" && ", 4);  } else { _r4917 = hr_str(" || ", 4);  } _r4917; })));
(void)(f289_gx(b_1592));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
bool cmp_1596 = (((((((o_1590) == (((int64_t)37LL))) || ((o_1590) == (((int64_t)38LL)))) || ((o_1590) == (((int64_t)39LL)))) || ((o_1590) == (((int64_t)40LL)))) || ((o_1590) == (((int64_t)41LL)))) || ((o_1590) == (((int64_t)42LL)))); 
if (cmp_1596) { int64_t m_1597 = f217_ax(n_1588); 
int64_t ta_1598 = f279_fin(a_1591); 
int64_t tb_1599 = f279_fin(b_1592); 
if (((m_1597) == (((int64_t)1LL)))) { (void)(f260_ow(hr_str("((uint64_t)(", 12)));
(void)(f289_gx(a_1591));
(void)(f260_ow(hr_str(") ", 2)));
(void)(f260_ow(f290_cmp_op(o_1590)));
(void)(f260_ow(hr_str(" (uint64_t)(", 12)));
(void)(f289_gx(b_1592));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (((m_1597) == (((int64_t)2LL)))) { if (((o_1590) == (((int64_t)38LL)))) { (void)(f260_ow(hr_str("!", 1)));
 }
(void)(f260_ow(hr_str("hr_streq(", 9)));
(void)(f291_gas(a_1591));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f291_gas(b_1592));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((m_1597) == (((int64_t)3LL)))) { int64_t et_1614 = ({ int64_t _r4937; if ((((((*({ hrv *_t4938 = &(g550); int64_t _i4938 = ta_1598; (S1*)_t4938->b + hr_ix(_i4938, _t4938->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:264"); }))).k_) == (((uint8_t)7LL))) || ((((*({ hrv *_t4939 = &(g550); int64_t _i4939 = ta_1598; (S1*)_t4939->b + hr_ix(_i4939, _t4939->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:264"); }))).k_) == (((uint8_t)19LL))))) { _r4937 = tb_1599;  } else { _r4937 = ta_1598;  } _r4937; }); 
(void)(f295_gen_heq(et_1614));
if (((o_1590) == (((int64_t)38LL)))) { (void)(f260_ow(hr_str("!", 1)));
 }
(void)(f260_ow(hr_str("heq", 3)));
(void)(f294_oi(et_1614));
(void)(f260_ow(hr_str("(", 1)));
if (f305_hsl_ty(et_1614)) { (void)(f291_gas(a_1591));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f291_gas(b_1592));
 } else { (void)(f306_gxas(a_1591, et_1614));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f306_gxas(b_1592, et_1614));
 }
(void)(f260_ow(hr_str(")", 1)));
return;
 }
int64_t ka_1718 = ((int64_t)(((*({ hrv *_t4953 = &(g550); int64_t _i4953 = ta_1598; (S1*)_t4953->b + hr_ix(_i4953, _t4953->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:265"); }))).k_)); 
if (((((ka_1718) == (((int64_t)10LL))) || ((ka_1718) == (((int64_t)11LL)))) || ((((*({ hrv *_t4954 = &(g550); int64_t _i4954 = tb_1599; (S1*)_t4954->b + hr_ix(_i4954, _t4954->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:266"); }))).k_) == (((uint8_t)10LL))))) { (void)(f260_ow(hr_str("((void*)(", 9)));
(void)(f289_gx(a_1591));
(void)(f260_ow(hr_str(") ", 2)));
(void)(f260_ow(f290_cmp_op(o_1590)));
(void)(f260_ow(hr_str(" (void*)(", 9)));
(void)(f289_gx(b_1592));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
(void)(f260_ow(hr_str("((", 2)));
(void)(f289_gx(a_1591));
(void)(f260_ow(hr_str(") ", 2)));
(void)(f260_ow(f290_cmp_op(o_1590)));
(void)(f260_ow(hr_str(" (", 2)));
(void)(f289_gx(b_1592));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
(void)(f307_garith(o_1590, f279_fin(n_1588), a_1591, b_1592, ((int64_t)0LL), n_1588));
}
static void f289_gx(int64_t n_1593) {
int64_t c_1594 = f150_cv(n_1593); 
int64_t t_1595 = f141_at(n_1593); 
if ((((c_1594) < (((int64_t)0LL))) || ((c_1594) == (t_1595)))) { (void)(f271_gx1(n_1593));
return;
 }
(void)(f270_gcv(n_1593, t_1595, c_1594));
}
static hsl f290_cmp_op(int64_t o_1600) {
if (((o_1600) == (((int64_t)37LL)))) { return hr_str("==", 2);
 }
if (((o_1600) == (((int64_t)38LL)))) { return hr_str("!=", 2);
 }
if (((o_1600) == (((int64_t)39LL)))) { return hr_str("<", 1);
 }
if (((o_1600) == (((int64_t)40LL)))) { return hr_str(">", 1);
 }
if (((o_1600) == (((int64_t)41LL)))) { return hr_str("<=", 2);
 }
if (((o_1600) == (((int64_t)42LL)))) { return hr_str(">=", 2);
 }
return hr_str("\077", 1);
}
static void f291_gas(int64_t n_1601) {
int64_t c_1602 = f150_cv(n_1601); 
int64_t t_1603 = f141_at(n_1601); 
if (((((c_1602) >= (((int64_t)0LL))) && ((c_1602) != (t_1603))) && ((((*({ hrv *_t4979 = &(g550); int64_t _i4979 = c_1602; (S1*)_t4979->b + hr_ix(_i4979, _t4979->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:194"); }))).k_) == (((uint8_t)9LL))))) { (void)(f292_gsl(n_1601, t_1603));
return;
 }
if ((((c_1602) >= (((int64_t)0LL))) && ((c_1602) != (t_1603)))) { int64_t p_1613 = f293_nt(); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(c_1602));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_1613));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(n_1601));
(void)(f260_ow(hr_str("; ", 2)));
if (f268_is_res(c_1602)) { (void)(f260_ow(hr_str("hr_sl(_t", 8)));
(void)(f294_oi(p_1613));
(void)(f260_ow(hr_str(")", 1)));
 } else { if (f282_is_fix(c_1602)) { (void)(f260_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f294_oi(p_1613));
(void)(({ hrv *_o4996 = &(g163); hr_fs(_o4996, hr_str(".e, ", 4)); hr_fi(_o4996, ((*({ hrv *_t4997 = &(g550); int64_t _i4997 = c_1602; (S1*)_t4997->b + hr_ix(_i4997, _t4997->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:195"); }))).b_); hr_fs(_o4996, hr_str(" }", 2)); }));
 } else { if (((((*({ hrv *_t4998 = &(g550); int64_t _i4998 = c_1602; (S1*)_t4998->b + hr_ix(_i4998, _t4998->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:195"); }))).k_) == (((uint8_t)9LL)))) { (void)(f260_ow(hr_str("_t", 2)));
(void)(f294_oi(p_1613));
 } else { (void)(f260_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f294_oi(p_1613));
(void)(f260_ow(hr_str(".e, _t", 6)));
(void)(f294_oi(p_1613));
(void)(f260_ow(hr_str(".n }", 4)));
 }
 }
 }
(void)(f260_ow(hr_str("; })", 4)));
return;
 }
(void)(f292_gsl(n_1601, t_1603));
}
static void f292_gsl(int64_t n_1604, int64_t f_1605) {
int64_t d_1606 = f179_deref(f_1605); 
int64_t k_1607 = ((int64_t)(((*({ hrv *_t5009 = &(g550); int64_t _i5009 = d_1606; (S1*)_t5009->b + hr_ix(_i5009, _t5009->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:171"); }))).k_)); 
if ((((((*({ hrv *_t5010 = &(g550); int64_t _i5010 = f_1605; (S1*)_t5010->b + hr_ix(_i5010, _t5010->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:172"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t5011 = &(g550); int64_t _i5011 = f_1605; (S1*)_t5011->b + hr_ix(_i5011, _t5011->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:172"); }))).c_) < (((int32_t)0LL))))) { int64_t p_1608 = f293_nt(); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(f_1605));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_1608));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f275_gx0(n_1604));
(void)(f260_ow(hr_str("; ", 2)));
if (((k_1607) == (((int64_t)9LL)))) { (void)(f260_ow(hr_str("*_t", 3)));
(void)(f294_oi(p_1608));
 } else { if (f268_is_res(d_1606)) { (void)(f260_ow(hr_str("hr_sl(*_t", 9)));
(void)(f294_oi(p_1608));
(void)(f260_ow(hr_str(")", 1)));
 } else { if (f282_is_fix(d_1606)) { (void)(f260_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f294_oi(p_1608));
(void)(({ hrv *_o5029 = &(g163); hr_fs(_o5029, hr_str("->e, ", 5)); hr_fi(_o5029, ((*({ hrv *_t5030 = &(g550); int64_t _i5030 = d_1606; (S1*)_t5030->b + hr_ix(_i5030, _t5030->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:177"); }))).b_); hr_fs(_o5029, hr_str(" }", 2)); }));
 } else { (void)(f260_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f294_oi(p_1608));
(void)(f260_ow(hr_str("->e, _t", 7)));
(void)(f294_oi(p_1608));
(void)(f260_ow(hr_str("->n }", 5)));
 }
 }
 }
(void)(f260_ow(hr_str("; })", 4)));
return;
 }
if ((((k_1607) == (((int64_t)9LL))) || ((k_1607) == (((int64_t)18LL))))) { (void)(f275_gx0(n_1604));
return;
 }
if (f268_is_res(d_1606)) { (void)(f260_ow(hr_str("hr_sl(", 6)));
if (f272_is_place(n_1604)) { (void)(f275_gx0(n_1604));
 } else { int64_t tk0_1610 = f273_tmp(d_1606, true); 
(void)(f260_ow(hr_str("*hr_tmp(&", 9)));
(void)(f274_ot(tk0_1610));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f275_gx0(n_1604));
(void)(f260_ow(hr_str(")", 1)));
 }
(void)(f260_ow(hr_str(")", 1)));
return;
 }
int64_t p_1611 = f293_nt(); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(d_1606));
(void)(f260_ow(hr_str(" *_t", 4)));
(void)(f294_oi(p_1611));
(void)(f260_ow(hr_str(" = ", 3)));
if (f272_is_place(n_1604)) { (void)(f260_ow(hr_str("&(", 2)));
(void)(f275_gx0(n_1604));
(void)(f260_ow(hr_str(")", 1)));
 } else { int64_t tk0_1612 = f273_tmp(d_1606, false); 
(void)(f260_ow(hr_str("(", 1)));
(void)(f274_ot(tk0_1612));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f275_gx0(n_1604));
(void)(f260_ow(hr_str(", &", 3)));
(void)(f274_ot(tk0_1612));
(void)(f260_ow(hr_str(")", 1)));
 }
(void)(f260_ow(hr_str("; ", 2)));
if (f282_is_fix(d_1606)) { (void)(f260_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f294_oi(p_1611));
(void)(({ hrv *_o5071 = &(g163); hr_fs(_o5071, hr_str("->e, ", 5)); hr_fi(_o5071, ((*({ hrv *_t5072 = &(g550); int64_t _i5072 = d_1606; (S1*)_t5072->b + hr_ix(_i5072, _t5072->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:188"); }))).b_); hr_fs(_o5071, hr_str(" }", 2)); }));
 } else { (void)(f260_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f294_oi(p_1611));
(void)(f260_ow(hr_str("->e, _t", 7)));
(void)(f294_oi(p_1611));
(void)(f260_ow(hr_str("->n }", 5)));
 }
(void)(f260_ow(hr_str("; })", 4)));
}
static int64_t f293_nt(void) {
g178++;
return g178;
}
static void f294_oi(int64_t v_1609) {
(void)(({ hrv *_o5079 = &(g163); hr_fi(_o5079, v_1609); }));
}
static void f295_gen_heq(int64_t t_1615) {
(void)(f263_cn_grow());
if ((((*({ hrv *_t5081 = &(g175); int64_t _i5081 = t_1615; (uint8_t*)_t5081->b + hr_ix(_i5081, _t5081->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:478"); }))) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t5082 = &((*({ hrv *_t5083 = &(g175); int64_t _i5083 = t_1615; (uint8_t*)_t5083->b + hr_ix(_i5083, _t5083->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:479"); }))); *_t5082 = ((uint8_t)1LL); }
S1 x_1616 = (*({ hrv *_t5084 = &(g550); int64_t _i5084 = t_1615; (S1*)_t5084->b + hr_ix(_i5084, _t5084->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:480"); })); 
int64_t k_1617 = ((int64_t)((x_1616).k_)); 
(void)(f262_cbody(t_1615));
bool sl_1618 = (((k_1617) == (((int64_t)9LL))) || ((((k_1617) == (((int64_t)8LL))) && (!(f282_is_fix(t_1615)))) && (!(f283_is_lim(t_1615))))); 
(void)(f296_comp_pre(t_1615, false));
L97 sig_1692 = ({ L97 _t5089; memset(&_t5089, 0, sizeof _t5089); _t5089.n = 0; _t5089; }); 
(void)(({ L97 *_l5090 = &(sig_1692); hrv _o5090 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5090, hr_str("static bool heq", 15)); hr_fi(&_o5090, t_1615); hr_fs(&_o5090, hr_str("(", 1)); if (_l5090->n + _o5090.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:485"); memcpy(_l5090->e + _l5090->n, _o5090.b, (size_t)_o5090.n); _l5090->n += _o5090.n; }));
hsl c_1693 = ({ hsl _r5091; if (sl_1618) { _r5091 = hr_str("hsl", 3);  } else { _r5091 = f264_cn(t_1615);  } _r5091; }); 
(void)(({ L97 *_v5093 = &(sig_1692); hsl _s5093 = c_1693; if (_v5093->n + _s5093.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:487"); memmove(_v5093->e + _v5093->n, _s5093.p, (size_t)_s5093.n * sizeof _v5093->e[0]); _v5093->n += _s5093.n; }));
(void)(({ L97 *_v5094 = &(sig_1692); hsl _s5094 = hr_str(" a, ", 4); if (_v5094->n + _s5094.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:487"); memmove(_v5094->e + _v5094->n, _s5094.p, (size_t)_s5094.n * sizeof _v5094->e[0]); _v5094->n += _s5094.n; }));
(void)(({ L97 *_v5095 = &(sig_1692); hsl _s5095 = c_1693; if (_v5095->n + _s5095.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:487"); memmove(_v5095->e + _v5095->n, _s5095.p, (size_t)_s5095.n * sizeof _v5095->e[0]); _v5095->n += _s5095.n; }));
(void)(({ L97 *_v5096 = &(sig_1692); hsl _s5096 = hr_str(" b)", 3); if (_v5096->n + _s5096.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:487"); memmove(_v5096->e + _v5096->n, _s5096.p, (size_t)_s5096.n * sizeof _v5096->e[0]); _v5096->n += _s5096.n; }));
(void)(({ hrv *_v5097 = &(g166); hsl _s5097 = ({ hsl _t5098 = ({ L97 *_t5099 = &(sig_1692); (hsl){ (uint8_t*)_t5099->e, _t5099->n }; }); int64_t _l5098 = 0, _h5098 = _t5098.n; if (_l5098 < 0 || _h5098 < _l5098 || _h5098 > _t5098.n) hr_slerr(_l5098, _h5098, _t5098.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:488"); (hsl){ _t5098.p + _l5098 * (int64_t)sizeof(uint8_t), _h5098 - _l5098 }; }); hr_append(_v5097, _s5097.p, _s5097.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5100 = &(g166); hsl _s5100 = hr_str(";\012", 2); hr_append(_v5100, _s5100.p, _s5100.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5101 = &(g169); hsl _s5101 = ({ hsl _t5102 = ({ L97 *_t5103 = &(sig_1692); (hsl){ (uint8_t*)_t5103->e, _t5103->n }; }); int64_t _l5102 = 0, _h5102 = _t5102.n; if (_l5102 < 0 || _h5102 < _l5102 || _h5102 > _t5102.n) hr_slerr(_l5102, _h5102, _t5102.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:489"); (hsl){ _t5102.p + _l5102 * (int64_t)sizeof(uint8_t), _h5102 - _l5102 }; }); hr_append(_v5101, _s5101.p, _s5101.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" { ", 3)));
if ((((k_1617) == (((int64_t)5LL))) || ((k_1617) == (((int64_t)7LL))))) { int64_t si_1694 = ({ int64_t _r5105; if (((k_1617) == (((int64_t)5LL)))) { _r5105 = ((int64_t)((x_1616).a_));  } else { _r5105 = ((int64_t)(((*({ hrv *_t5106 = &(g556); int64_t _i5106 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5107 = &(g555); int64_t _i5107 = (x_1616).a_; (S8*)_t5107->b + hr_ix(_i5107, _t5107->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:491"); }))).v0_)) + (int64_t)((int64_t)((x_1616).c_)))); (S9*)_t5106->b + hr_ix(_i5106, _t5106->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:491"); }))).si_));  } _r5105; }); 
(void)(f301_hh(hr_str("return true", 11)));
if (((si_1694) >= (((int64_t)0LL)))) { int64_t f0_1695 = ((int64_t)(((*({ hrv *_t5109 = &(g553); int64_t _i5109 = si_1694; (S10*)_t5109->b + hr_ix(_i5109, _t5109->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); }))).f0_)); 
{ int32_t _e5111 = ((*({ hrv *_t5112 = &(g553); int64_t _i5112 = si_1694; (S10*)_t5112->b + hr_ix(_i5112, _t5112->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); }))).fnum_; for (int32_t _k5111 = 0; _k5111 < _e5111; _k5111++) { int32_t i_1696 = (int32_t)_k5111; S11 f_1697 = (*({ hrv *_t5113 = &(g554); int64_t _i5113 = ((int64_t)((int64_t)f0_1695 + (int64_t)((int64_t)(i_1696)))); (S11*)_t5113->b + hr_ix(_i5113, _t5113->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); })); 
if ((((f_1697).ty_) < (((int32_t)0LL)))) { continue;
 }
L98 ea_1698 = ({ L98 _t5114; memset(&_t5114, 0, sizeof _t5114); _t5114.n = 0; _t5114; }); 
L98 eb_1699 = ({ L98 _t5115; memset(&_t5115, 0, sizeof _t5115); _t5115.n = 0; _t5115; }); 
(void)(({ L98 *_v5116 = &(ea_1698); hsl _s5116 = hr_str("a.", 2); if (_v5116->n + _s5116.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); memmove(_v5116->e + _v5116->n, _s5116.p, (size_t)_s5116.n * sizeof _v5116->e[0]); _v5116->n += _s5116.n; }));
(void)(({ L98 *_v5117 = &(eb_1699); hsl _s5117 = hr_str("b.", 2); if (_v5117->n + _s5117.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); memmove(_v5117->e + _v5117->n, _s5117.p, (size_t)_s5117.n * sizeof _v5117->e[0]); _v5117->n += _s5117.n; }));
{ hsl _v5119 = f10_nm(((int64_t)((f_1697).name_))); for (int64_t _k5119 = 0; _k5119 < _v5119.n; _k5119++) { uint8_t ch_1700 = ((uint8_t*)_v5119.p)[_k5119]; (void)(({ L98 *_v5121 = &(ea_1698); uint8_t _x5121 = ch_1700; if (_v5121->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); _v5121->e[_v5121->n] = _x5121; &_v5121->e[_v5121->n++]; }));
(void)(({ L98 *_v5122 = &(eb_1699); uint8_t _x5122 = ch_1700; if (_v5122->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); _v5122->e[_v5122->n] = _x5122; &_v5122->e[_v5122->n++]; }));
 } } _bk5118:; 
(void)(({ L98 *_v5123 = &(ea_1698); uint8_t _x5123 = ((uint8_t)95LL); if (_v5123->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); _v5123->e[_v5123->n] = _x5123; &_v5123->e[_v5123->n++]; }));
(void)(({ L98 *_v5124 = &(eb_1699); uint8_t _x5124 = ((uint8_t)95LL); if (_v5124->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); _v5124->e[_v5124->n] = _x5124; &_v5124->e[_v5124->n++]; }));
(void)(f301_hh(hr_str(" && ", 4)));
(void)(f304_heq_val(((int64_t)((f_1697).ty_)), ({ hsl _t5127 = ({ L98 *_t5128 = &(ea_1698); (hsl){ (uint8_t*)_t5128->e, _t5128->n }; }); int64_t _l5127 = 0, _h5127 = _t5127.n; if (_l5127 < 0 || _h5127 < _l5127 || _h5127 > _t5127.n) hr_slerr(_l5127, _h5127, _t5127.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); (hsl){ _t5127.p + _l5127 * (int64_t)sizeof(uint8_t), _h5127 - _l5127 }; }), ({ hsl _t5129 = ({ L98 *_t5130 = &(eb_1699); (hsl){ (uint8_t*)_t5130->e, _t5130->n }; }); int64_t _l5129 = 0, _h5129 = _t5129.n; if (_l5129 < 0 || _h5129 < _l5129 || _h5129 > _t5129.n) hr_slerr(_l5129, _h5129, _t5129.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); (hsl){ _t5129.p + _l5129 * (int64_t)sizeof(uint8_t), _h5129 - _l5129 }; })));
 } } _bk5110:; 
 }
(void)(f301_hh(hr_str("; ", 2)));
 }
if (((k_1617) == (((int64_t)6LL)))) { int64_t ei_1705 = ((int64_t)((x_1616).a_)); 
int64_t v0_1706 = ((int64_t)(((*({ hrv *_t5132 = &(g555); int64_t _i5132 = ei_1705; (S8*)_t5132->b + hr_ix(_i5132, _t5132->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:497"); }))).v0_)); 
(void)(f301_hh(hr_str("if (a.tag != b.tag) return false; ", 34)));
{ int32_t _e5135 = ((*({ hrv *_t5136 = &(g555); int64_t _i5136 = ei_1705; (S8*)_t5136->b + hr_ix(_i5136, _t5136->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:499"); }))).vnum_; for (int32_t _k5135 = 0; _k5135 < _e5135; _k5135++) { int32_t i_1707 = (int32_t)_k5135; S9 v_1708 = (*({ hrv *_t5137 = &(g556); int64_t _i5137 = ((int64_t)((int64_t)v0_1706 + (int64_t)((int64_t)(i_1707)))); (S9*)_t5137->b + hr_ix(_i5137, _t5137->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:499"); })); 
if (((((v_1708).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t5138 = &(g553); int64_t _i5138 = (v_1708).si_; (S10*)_t5138->b + hr_ix(_i5138, _t5138->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:499"); }))).zero_)))) { L100 ea_1709 = ({ L100 _t5139; memset(&_t5139, 0, sizeof _t5139); _t5139.n = 0; _t5139; }); 
L100 eb_1710 = ({ L100 _t5140; memset(&_t5140, 0, sizeof _t5140); _t5140.n = 0; _t5140; }); 
(void)(({ L100 *_l5141 = &(ea_1709); hrv _o5141 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5141, hr_str("a.u.v", 5)); hr_fi(&_o5141, i_1707); if (_l5141->n + _o5141.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:499"); memcpy(_l5141->e + _l5141->n, _o5141.b, (size_t)_o5141.n); _l5141->n += _o5141.n; }));
(void)(({ L100 *_l5142 = &(eb_1710); hrv _o5142 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5142, hr_str("b.u.v", 5)); hr_fi(&_o5142, i_1707); if (_l5142->n + _o5142.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:499"); memcpy(_l5142->e + _l5142->n, _o5142.b, (size_t)_o5142.n); _l5142->n += _o5142.n; }));
(void)(({ hrv *_o5143 = &(g169); hr_fs(_o5143, hr_str("if (a.tag == ", 13)); hr_fi(_o5143, i_1707); hr_fs(_o5143, hr_str(") return ", 9)); }));
(void)(f304_heq_val(f125_t_variant(ei_1705, ((int64_t)(i_1707))), ({ hsl _t5146 = ({ L100 *_t5147 = &(ea_1709); (hsl){ (uint8_t*)_t5147->e, _t5147->n }; }); int64_t _l5146 = 0, _h5146 = _t5146.n; if (_l5146 < 0 || _h5146 < _l5146 || _h5146 > _t5146.n) hr_slerr(_l5146, _h5146, _t5146.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:499"); (hsl){ _t5146.p + _l5146 * (int64_t)sizeof(uint8_t), _h5146 - _l5146 }; }), ({ hsl _t5148 = ({ L100 *_t5149 = &(eb_1710); (hsl){ (uint8_t*)_t5149->e, _t5149->n }; }); int64_t _l5148 = 0, _h5148 = _t5148.n; if (_l5148 < 0 || _h5148 < _l5148 || _h5148 > _t5148.n) hr_slerr(_l5148, _h5148, _t5148.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:499"); (hsl){ _t5148.p + _l5148 * (int64_t)sizeof(uint8_t), _h5148 - _l5148 }; })));
(void)(f301_hh(hr_str("; ", 2)));
 }
 } } _bk5134:; 
(void)(f301_hh(hr_str("return true; ", 13)));
 }
if ((((k_1617) == (((int64_t)8LL))) || ((k_1617) == (((int64_t)9LL))))) { int64_t e_1711 = ((int64_t)((x_1616).a_)); 
L98 ea_1712 = ({ L98 _t5152; memset(&_t5152, 0, sizeof _t5152); _t5152.n = 0; _t5152; }); 
L98 eb_1713 = ({ L98 _t5153; memset(&_t5153, 0, sizeof _t5153); _t5153.n = 0; _t5153; }); 
if (f282_is_fix(t_1615)) { (void)(({ hrv *_o5155 = &(g169); hr_fs(_o5155, hr_str("for (int64_t i = 0; i < ", 24)); hr_fi(_o5155, (x_1616).b_); hr_fs(_o5155, hr_str("; i++) if (!(", 13)); }));
(void)(({ L98 *_v5156 = &(ea_1712); hsl _s5156 = hr_str("a.e[i]", 6); if (_v5156->n + _s5156.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:505"); memmove(_v5156->e + _v5156->n, _s5156.p, (size_t)_s5156.n * sizeof _v5156->e[0]); _v5156->n += _s5156.n; }));
(void)(({ L98 *_v5157 = &(eb_1713); hsl _s5157 = hr_str("b.e[i]", 6); if (_v5157->n + _s5157.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:505"); memmove(_v5157->e + _v5157->n, _s5157.p, (size_t)_s5157.n * sizeof _v5157->e[0]); _v5157->n += _s5157.n; }));
 } else { if (f283_is_lim(t_1615)) { (void)(f301_hh(hr_str("if (a.n != b.n) return false; for (int64_t i = 0; i < a.n; i++) if (!(", 70)));
(void)(({ L98 *_v5160 = &(ea_1712); hsl _s5160 = hr_str("a.e[i]", 6); if (_v5160->n + _s5160.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); memmove(_v5160->e + _v5160->n, _s5160.p, (size_t)_s5160.n * sizeof _v5160->e[0]); _v5160->n += _s5160.n; }));
(void)(({ L98 *_v5161 = &(eb_1713); hsl _s5161 = hr_str("b.e[i]", 6); if (_v5161->n + _s5161.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); memmove(_v5161->e + _v5161->n, _s5161.p, (size_t)_s5161.n * sizeof _v5161->e[0]); _v5161->n += _s5161.n; }));
 } else { (void)(f301_hh(hr_str("if (a.n != b.n) return false; for (int64_t i = 0; i < a.n; i++) if (!(", 70)));
(void)(({ L98 *_v5163 = &(ea_1712); hsl _s5163 = hr_str("((", 2); if (_v5163->n + _s5163.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:507"); memmove(_v5163->e + _v5163->n, _s5163.p, (size_t)_s5163.n * sizeof _v5163->e[0]); _v5163->n += _s5163.n; }));
(void)(({ L98 *_v5164 = &(ea_1712); hsl _s5164 = f264_cn(e_1711); if (_v5164->n + _s5164.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:507"); memmove(_v5164->e + _v5164->n, _s5164.p, (size_t)_s5164.n * sizeof _v5164->e[0]); _v5164->n += _s5164.n; }));
(void)(({ L98 *_v5166 = &(ea_1712); hsl _s5166 = hr_str("*)a.p)[i]", 9); if (_v5166->n + _s5166.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:507"); memmove(_v5166->e + _v5166->n, _s5166.p, (size_t)_s5166.n * sizeof _v5166->e[0]); _v5166->n += _s5166.n; }));
(void)(({ L98 *_v5167 = &(eb_1713); hsl _s5167 = hr_str("((", 2); if (_v5167->n + _s5167.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:507"); memmove(_v5167->e + _v5167->n, _s5167.p, (size_t)_s5167.n * sizeof _v5167->e[0]); _v5167->n += _s5167.n; }));
(void)(({ L98 *_v5168 = &(eb_1713); hsl _s5168 = f264_cn(e_1711); if (_v5168->n + _s5168.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:507"); memmove(_v5168->e + _v5168->n, _s5168.p, (size_t)_s5168.n * sizeof _v5168->e[0]); _v5168->n += _s5168.n; }));
(void)(({ L98 *_v5170 = &(eb_1713); hsl _s5170 = hr_str("*)b.p)[i]", 9); if (_v5170->n + _s5170.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:507"); memmove(_v5170->e + _v5170->n, _s5170.p, (size_t)_s5170.n * sizeof _v5170->e[0]); _v5170->n += _s5170.n; }));
 }
 }
(void)(f304_heq_val(e_1711, ({ hsl _t5172 = ({ L98 *_t5173 = &(ea_1712); (hsl){ (uint8_t*)_t5173->e, _t5173->n }; }); int64_t _l5172 = 0, _h5172 = _t5172.n; if (_l5172 < 0 || _h5172 < _l5172 || _h5172 > _t5172.n) hr_slerr(_l5172, _h5172, _t5172.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:508"); (hsl){ _t5172.p + _l5172 * (int64_t)sizeof(uint8_t), _h5172 - _l5172 }; }), ({ hsl _t5174 = ({ L98 *_t5175 = &(eb_1713); (hsl){ (uint8_t*)_t5175->e, _t5175->n }; }); int64_t _l5174 = 0, _h5174 = _t5174.n; if (_l5174 < 0 || _h5174 < _l5174 || _h5174 > _t5174.n) hr_slerr(_l5174, _h5174, _t5174.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:508"); (hsl){ _t5174.p + _l5174 * (int64_t)sizeof(uint8_t), _h5174 - _l5174 }; })));
(void)(f301_hh(hr_str(")) return false; return true; ", 30)));
 }
if (((k_1617) == (((int64_t)14LL)))) { (void)(f301_hh(hr_str("return true; ", 13)));
 }
(void)(f301_hh(hr_str("}\012", 2)));
}
static void f296_comp_pre(int64_t t_1619, bool fmt_1620) {
S1 x_1621 = (*({ hrv *_t5179 = &(g550); int64_t _i5179 = t_1619; (S1*)_t5179->b + hr_ix(_i5179, _t5179->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:393"); })); 
int64_t k_1622 = ((int64_t)((x_1621).k_)); 
if (((k_1622) == (((int64_t)5LL)))) { int64_t si_1623 = ((int64_t)((x_1621).a_)); 
{ int32_t _e5181 = ((*({ hrv *_t5182 = &(g553); int64_t _i5182 = si_1623; (S10*)_t5182->b + hr_ix(_i5182, _t5182->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:394"); }))).fnum_; for (int32_t _k5181 = 0; _k5181 < _e5181; _k5181++) { int32_t i_1624 = (int32_t)_k5181; S11 f_1625 = (*({ hrv *_t5183 = &(g554); int64_t _i5183 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5184 = &(g553); int64_t _i5184 = si_1623; (S10*)_t5184->b + hr_ix(_i5184, _t5184->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:394"); }))).f0_)) + (int64_t)((int64_t)(i_1624)))); (S11*)_t5183->b + hr_ix(_i5183, _t5183->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:394"); })); 
if ((((f_1625).ty_) >= (((int32_t)0LL)))) { (void)(f297_comp_one(((int64_t)((f_1625).ty_)), fmt_1620));
 }
 } } _bk5180:; 
 }
if (((k_1622) == (((int64_t)7LL)))) { S9 v_1683 = (*({ hrv *_t5186 = &(g556); int64_t _i5186 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5187 = &(g555); int64_t _i5187 = (x_1621).a_; (S8*)_t5187->b + hr_ix(_i5187, _t5187->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:395"); }))).v0_)) + (int64_t)((int64_t)((x_1621).c_)))); (S9*)_t5186->b + hr_ix(_i5186, _t5186->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:395"); })); 
if ((((v_1683).si_) >= (((int32_t)0LL)))) { { int32_t _e5189 = ((*({ hrv *_t5190 = &(g553); int64_t _i5190 = (v_1683).si_; (S10*)_t5190->b + hr_ix(_i5190, _t5190->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:395"); }))).fnum_; for (int32_t _k5189 = 0; _k5189 < _e5189; _k5189++) { int32_t i_1684 = (int32_t)_k5189; S11 f_1685 = (*({ hrv *_t5191 = &(g554); int64_t _i5191 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5192 = &(g553); int64_t _i5192 = (v_1683).si_; (S10*)_t5192->b + hr_ix(_i5192, _t5192->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:395"); }))).f0_)) + (int64_t)((int64_t)(i_1684)))); (S11*)_t5191->b + hr_ix(_i5191, _t5191->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:395"); })); 
if ((((f_1685).ty_) >= (((int32_t)0LL)))) { (void)(f297_comp_one(((int64_t)((f_1685).ty_)), fmt_1620));
 }
 } } _bk5188:; 
 }
 }
if (((k_1622) == (((int64_t)6LL)))) { int64_t ei_1686 = ((int64_t)((x_1621).a_)); 
{ int32_t _e5195 = ((*({ hrv *_t5196 = &(g555); int64_t _i5196 = ei_1686; (S8*)_t5196->b + hr_ix(_i5196, _t5196->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:396"); }))).vnum_; for (int32_t _k5195 = 0; _k5195 < _e5195; _k5195++) { int32_t i_1687 = (int32_t)_k5195; S9 v_1688 = (*({ hrv *_t5197 = &(g556); int64_t _i5197 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5198 = &(g555); int64_t _i5198 = ei_1686; (S8*)_t5198->b + hr_ix(_i5198, _t5198->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:396"); }))).v0_)) + (int64_t)((int64_t)(i_1687)))); (S9*)_t5197->b + hr_ix(_i5197, _t5197->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:396"); })); 
if (((((v_1688).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t5199 = &(g553); int64_t _i5199 = (v_1688).si_; (S10*)_t5199->b + hr_ix(_i5199, _t5199->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:396"); }))).zero_)))) { if (fmt_1620) { { int32_t _e5201 = ((*({ hrv *_t5202 = &(g553); int64_t _i5202 = (v_1688).si_; (S10*)_t5202->b + hr_ix(_i5202, _t5202->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:396"); }))).fnum_; for (int32_t _k5201 = 0; _k5201 < _e5201; _k5201++) { int32_t j_1689 = (int32_t)_k5201; S11 f_1690 = (*({ hrv *_t5203 = &(g554); int64_t _i5203 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5204 = &(g553); int64_t _i5204 = (v_1688).si_; (S10*)_t5204->b + hr_ix(_i5204, _t5204->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:396"); }))).f0_)) + (int64_t)((int64_t)(j_1689)))); (S11*)_t5203->b + hr_ix(_i5203, _t5203->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:396"); })); 
if ((((f_1690).ty_) >= (((int32_t)0LL)))) { (void)(f297_comp_one(((int64_t)((f_1690).ty_)), fmt_1620));
 }
 } } _bk5200:; 
 } else { (void)(f295_gen_heq(f125_t_variant(ei_1686, ((int64_t)(i_1687)))));
 }
 }
 } } _bk5194:; 
 }
if ((((k_1622) == (((int64_t)8LL))) || ((k_1622) == (((int64_t)9LL))))) { (void)(f297_comp_one(((int64_t)((x_1621).a_)), fmt_1620));
 }
if (((k_1622) == (((int64_t)14LL)))) { { int32_t _e5210 = (x_1621).n_; for (int32_t _k5210 = 0; _k5210 < _e5210; _k5210++) { int32_t i_1691 = (int32_t)_k5210; (void)(f297_comp_one(((int64_t)((*({ hrv *_t5212 = &(g551); int64_t _i5212 = ((int64_t)((int64_t)((int64_t)((x_1621).l_)) + (int64_t)((int64_t)(i_1691)))); (int32_t*)_t5212->b + hr_ix(_i5212, _t5212->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:398"); })))), fmt_1620));
 } } _bk5209:; 
 }
}
static void f297_comp_one(int64_t t_1626, bool fmt_1627) {
int64_t u_1628 = ({ int64_t _r5213; if (((((*({ hrv *_t5214 = &(g550); int64_t _i5214 = t_1626; (S1*)_t5214->b + hr_ix(_i5214, _t5214->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:391"); }))).k_) == (((uint8_t)10LL)))) { _r5213 = ((int64_t)(((*({ hrv *_t5215 = &(g550); int64_t _i5215 = t_1626; (S1*)_t5215->b + hr_ix(_i5215, _t5215->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:391"); }))).a_));  } else { _r5213 = t_1626;  } _r5213; }); 
if ((((((*({ hrv *_t5216 = &(g550); int64_t _i5216 = t_1626; (S1*)_t5216->b + hr_ix(_i5216, _t5216->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:391"); }))).k_) == (((uint8_t)10LL))) && (!(fmt_1627)))) { return;
 }
if (f298_need_helper(u_1628)) { if (fmt_1627) { (void)(f299_gen_hf(u_1628));
 } else { (void)(f295_gen_heq(u_1628));
 }
 }
}
static bool f298_need_helper(int64_t t_1629) {
int64_t k_1630 = ((int64_t)(((*({ hrv *_t5220 = &(g550); int64_t _i5220 = t_1629; (S1*)_t5220->b + hr_ix(_i5220, _t5220->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:390"); }))).k_)); 
if (f164_is_byte_arr(t_1629)) { return false;
 }
if (((k_1630) == (((int64_t)10LL)))) { return f298_need_helper(((int64_t)(((*({ hrv *_t5223 = &(g550); int64_t _i5223 = t_1629; (S1*)_t5223->b + hr_ix(_i5223, _t5223->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:390"); }))).a_)));
 }
return (((((((k_1630) == (((int64_t)5LL))) || ((k_1630) == (((int64_t)6LL)))) || ((k_1630) == (((int64_t)7LL)))) || ((k_1630) == (((int64_t)8LL)))) || ((k_1630) == (((int64_t)9LL)))) || ((k_1630) == (((int64_t)14LL))));
}
static void f299_gen_hf(int64_t t_1631) {
(void)(f263_cn_grow());
if ((((*({ hrv *_t5225 = &(g174); int64_t _i5225 = t_1631; (uint8_t*)_t5225->b + hr_ix(_i5225, _t5225->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:413"); }))) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t5226 = &((*({ hrv *_t5227 = &(g174); int64_t _i5227 = t_1631; (uint8_t*)_t5227->b + hr_ix(_i5227, _t5227->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:414"); }))); *_t5226 = ((uint8_t)1LL); }
S1 x_1632 = (*({ hrv *_t5228 = &(g550); int64_t _i5228 = t_1631; (S1*)_t5228->b + hr_ix(_i5228, _t5228->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:415"); })); 
int64_t k_1633 = ((int64_t)((x_1632).k_)); 
(void)(f262_cbody(t_1631));
bool sl_1634 = (((k_1633) == (((int64_t)9LL))) || ((((k_1633) == (((int64_t)8LL))) && (!(f282_is_fix(t_1631)))) && (!(f283_is_lim(t_1631))))); 
(void)(f300_hf_pre(t_1631));
L97 sig_1636 = ({ L97 _t5233; memset(&_t5233, 0, sizeof _t5233); _t5233.n = 0; _t5233; }); 
(void)(({ L97 *_l5234 = &(sig_1636); hrv _o5234 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5234, hr_str("static void hf", 14)); hr_fi(&_o5234, t_1631); hr_fs(&_o5234, hr_str("(hrv *o, ", 9)); if (_l5234->n + _o5234.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:420"); memcpy(_l5234->e + _l5234->n, _o5234.b, (size_t)_o5234.n); _l5234->n += _o5234.n; }));
(void)(({ L97 *_v5235 = &(sig_1636); hsl _s5235 = ({ hsl _r5236; if (sl_1634) { _r5236 = hr_str("hsl", 3);  } else { _r5236 = f264_cn(t_1631);  } _r5236; }); if (_v5235->n + _s5235.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:421"); memmove(_v5235->e + _v5235->n, _s5235.p, (size_t)_s5235.n * sizeof _v5235->e[0]); _v5235->n += _s5235.n; }));
(void)(({ L97 *_v5238 = &(sig_1636); hsl _s5238 = hr_str(" v)", 3); if (_v5238->n + _s5238.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:422"); memmove(_v5238->e + _v5238->n, _s5238.p, (size_t)_s5238.n * sizeof _v5238->e[0]); _v5238->n += _s5238.n; }));
(void)(({ hrv *_v5239 = &(g166); hsl _s5239 = ({ hsl _t5240 = ({ L97 *_t5241 = &(sig_1636); (hsl){ (uint8_t*)_t5241->e, _t5241->n }; }); int64_t _l5240 = 0, _h5240 = _t5240.n; if (_l5240 < 0 || _h5240 < _l5240 || _h5240 > _t5240.n) hr_slerr(_l5240, _h5240, _t5240.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:423"); (hsl){ _t5240.p + _l5240 * (int64_t)sizeof(uint8_t), _h5240 - _l5240 }; }); hr_append(_v5239, _s5239.p, _s5239.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5242 = &(g166); hsl _s5242 = hr_str(";\012", 2); hr_append(_v5242, _s5242.p, _s5242.n, sizeof(uint8_t)); }));
int64_t s0_1637 = (g169).n; 
(void)(({ hrv *_v5243 = &(g169); hsl _s5243 = ({ hsl _t5244 = ({ L97 *_t5245 = &(sig_1636); (hsl){ (uint8_t*)_t5245->e, _t5245->n }; }); int64_t _l5244 = 0, _h5244 = _t5244.n; if (_l5244 < 0 || _h5244 < _l5244 || _h5244 > _t5244.n) hr_slerr(_l5244, _h5244, _t5244.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:425"); (hsl){ _t5244.p + _l5244 * (int64_t)sizeof(uint8_t), _h5244 - _l5244 }; }); hr_append(_v5243, _s5243.p, _s5243.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" { ", 3)));
int64_t hk_1639 = ({ int64_t _r5247; if (((t_1631) < ((g348).n))) { _r5247 = ((int64_t)((*({ hrv *_t5248 = &(g348); int64_t _i5248 = t_1631; (int32_t*)_t5248->b + hr_ix(_i5248, _t5248->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:426"); }))));  } else { _r5247 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r5247; }); 
if (((hk_1639) >= (((int64_t)0LL)))) { int64_t pt_1640 = f208_ptype_of(hk_1639, ((int64_t)1LL)); 
bool byr_1641 = ((((*({ hrv *_t5250 = &(g550); int64_t _i5250 = pt_1640; (S1*)_t5250->b + hr_ix(_i5250, _t5250->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:429"); }))).k_) == (((uint8_t)10LL))); 
int64_t dp_1642 = f179_deref(pt_1640); 
if (((((dp_1642) != (t_1631)) && ((((*({ hrv *_t5252 = &(g550); int64_t _i5252 = dp_1642; (S1*)_t5252->b + hr_ix(_i5252, _t5252->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:431"); }))).k_) == (((uint8_t)6LL)))) && ((k_1633) == (((int64_t)7LL))))) { int64_t vi_1643 = ((int64_t)((x_1632).c_)); 
S9 vv_1644 = (*({ hrv *_t5253 = &(g556); int64_t _i5253 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5254 = &(g555); int64_t _i5254 = (x_1632).a_; (S8*)_t5254->b + hr_ix(_i5254, _t5254->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:431"); }))).v0_)) + (int64_t)vi_1643)); (S9*)_t5253->b + hr_ix(_i5253, _t5253->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:431"); })); 
(void)(({ hrv *_v5255 = &(g169); hsl _s5255 = f264_cn(dp_1642); hr_append(_v5255, _s5255.p, _s5255.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" e; memset(&e, 0, sizeof e); ", 29)));
(void)(({ hrv *_o5258 = &(g169); hr_fs(_o5258, hr_str("e.tag = ", 8)); hr_fi(_o5258, vi_1643); hr_fs(_o5258, hr_str("; ", 2)); }));
if (((((vv_1644).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t5259 = &(g553); int64_t _i5259 = (vv_1644).si_; (S10*)_t5259->b + hr_ix(_i5259, _t5259->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:431"); }))).zero_)))) { (void)(({ hrv *_o5260 = &(g169); hr_fs(_o5260, hr_str("e.u.v", 5)); hr_fi(_o5260, vi_1643); hr_fs(_o5260, hr_str(" = v; ", 6)); }));
 }
(void)(f302_fn_cname_to((&(g169)), hk_1639));
(void)(f301_hh(({ hsl _r5263; if (byr_1641) { _r5263 = hr_str("(o, &e); }\012", 11);  } else { _r5263 = hr_str("(o, e); }\012", 10);  } _r5263; })));
return;
 }
(void)(f302_fn_cname_to((&(g169)), hk_1639));
(void)(f301_hh(({ hsl _r5266; if (byr_1641) { _r5266 = hr_str("(o, &v); }\012", 11);  } else { _r5266 = hr_str("(o, v); }\012", 10);  } _r5266; })));
return;
 }
if (((k_1633) == (((int64_t)5LL)))) { int64_t si_1649 = ((int64_t)((x_1632).a_)); 
int64_t f0_1650 = ((int64_t)(((*({ hrv *_t5267 = &(g553); int64_t _i5267 = si_1649; (S10*)_t5267->b + hr_ix(_i5267, _t5267->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:436"); }))).f0_)); 
(void)(f301_hh(hr_str("hr_fc(o, \"", 10)));
hrv tnm_1651 __attribute__((cleanup(hr_rdrop))) = f126_ty_name(t_1631); 
(void)(({ hrv *_v5270 = &(g169); hsl _s5270 = ({ hsl _t5271 = hr_sl(tnm_1651); int64_t _l5271 = 0, _h5271 = _t5271.n; if (_l5271 < 0 || _h5271 < _l5271 || _h5271 > _t5271.n) hr_slerr(_l5271, _h5271, _t5271.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:437"); (hsl){ _t5271.p + _l5271 * (int64_t)sizeof(uint8_t), _h5271 - _l5271 }; }); hr_append(_v5270, _s5270.p, _s5270.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" { \"); ", 7)));
bool first_1652 = true; 
{ int32_t _e5274 = ((*({ hrv *_t5275 = &(g553); int64_t _i5275 = si_1649; (S10*)_t5275->b + hr_ix(_i5275, _t5275->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:439"); }))).fnum_; for (int32_t _k5274 = 0; _k5274 < _e5274; _k5274++) { int32_t i_1653 = (int32_t)_k5274; S11 f_1654 = (*({ hrv *_t5276 = &(g554); int64_t _i5276 = ((int64_t)((int64_t)f0_1650 + (int64_t)((int64_t)(i_1653)))); (S11*)_t5276->b + hr_ix(_i5276, _t5276->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:439"); })); 
if ((((f_1654).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1652))) { (void)(f301_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1652 = false;
L98 e_1655 = ({ L98 _t5278; memset(&_t5278, 0, sizeof _t5278); _t5278.n = 0; _t5278; }); 
(void)(({ L98 *_v5279 = &(e_1655); hsl _s5279 = hr_str("v.", 2); if (_v5279->n + _s5279.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:439"); memmove(_v5279->e + _v5279->n, _s5279.p, (size_t)_s5279.n * sizeof _v5279->e[0]); _v5279->n += _s5279.n; }));
{ hsl _v5281 = f10_nm(((int64_t)((f_1654).name_))); for (int64_t _k5281 = 0; _k5281 < _v5281.n; _k5281++) { uint8_t c_1656 = ((uint8_t*)_v5281.p)[_k5281]; (void)(({ L98 *_v5283 = &(e_1655); uint8_t _x5283 = c_1656; if (_v5283->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:439"); _v5283->e[_v5283->n] = _x5283; &_v5283->e[_v5283->n++]; }));
 } } _bk5280:; 
(void)(({ L98 *_v5284 = &(e_1655); uint8_t _x5284 = ((uint8_t)95LL); if (_v5284->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:439"); _v5284->e[_v5284->n] = _x5284; &_v5284->e[_v5284->n++]; }));
(void)(f303_hf_val(((int64_t)((f_1654).ty_)), ({ hsl _t5286 = ({ L98 *_t5287 = &(e_1655); (hsl){ (uint8_t*)_t5287->e, _t5287->n }; }); int64_t _l5286 = 0, _h5286 = _t5286.n; if (_l5286 < 0 || _h5286 < _l5286 || _h5286 > _t5286.n) hr_slerr(_l5286, _h5286, _t5286.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:439"); (hsl){ _t5286.p + _l5286 * (int64_t)sizeof(uint8_t), _h5286 - _l5286 }; })));
 } } _bk5273:; 
(void)(f301_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 }
if (((k_1633) == (((int64_t)6LL)))) { int64_t ei_1661 = ((int64_t)((x_1632).a_)); 
int64_t v0_1662 = ((int64_t)(((*({ hrv *_t5289 = &(g555); int64_t _i5289 = ei_1661; (S8*)_t5289->b + hr_ix(_i5289, _t5289->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:443"); }))).v0_)); 
{ int32_t _e5291 = ((*({ hrv *_t5292 = &(g555); int64_t _i5292 = ei_1661; (S8*)_t5292->b + hr_ix(_i5292, _t5292->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:444"); }))).vnum_; for (int32_t _k5291 = 0; _k5291 < _e5291; _k5291++) { int32_t i_1663 = (int32_t)_k5291; S9 v_1664 = (*({ hrv *_t5293 = &(g556); int64_t _i5293 = ((int64_t)((int64_t)v0_1662 + (int64_t)((int64_t)(i_1663)))); (S9*)_t5293->b + hr_ix(_i5293, _t5293->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:445"); })); 
(void)(({ hrv *_o5294 = &(g169); hr_fs(_o5294, hr_str("if (v.tag == ", 13)); hr_fi(_o5294, i_1663); hr_fs(_o5294, hr_str(") { ", 4)); }));
if (((((v_1664).si_) >= (((int32_t)0LL))) && ((((*({ hrv *_t5295 = &(g553); int64_t _i5295 = (v_1664).si_; (S10*)_t5295->b + hr_ix(_i5295, _t5295->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:447"); }))).fnum_) > (((int32_t)0LL))))) { (void)(f301_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f301_hh(f10_nm(((int64_t)((v_1664).name_)))));
(void)(f301_hh(hr_str(" { \"); ", 7)));
bool first_1665 = true; 
int64_t sf0_1666 = ((int64_t)(((*({ hrv *_t5300 = &(g553); int64_t _i5300 = (v_1664).si_; (S10*)_t5300->b + hr_ix(_i5300, _t5300->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:447"); }))).f0_)); 
{ int32_t _e5302 = ((*({ hrv *_t5303 = &(g553); int64_t _i5303 = (v_1664).si_; (S10*)_t5303->b + hr_ix(_i5303, _t5303->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:447"); }))).fnum_; for (int32_t _k5302 = 0; _k5302 < _e5302; _k5302++) { int32_t j_1667 = (int32_t)_k5302; S11 f_1668 = (*({ hrv *_t5304 = &(g554); int64_t _i5304 = ((int64_t)((int64_t)sf0_1666 + (int64_t)((int64_t)(j_1667)))); (S11*)_t5304->b + hr_ix(_i5304, _t5304->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:447"); })); 
if ((((f_1668).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1665))) { (void)(f301_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1665 = false;
L98 e_1669 = ({ L98 _t5306; memset(&_t5306, 0, sizeof _t5306); _t5306.n = 0; _t5306; }); 
(void)(({ L98 *_l5307 = &(e_1669); hrv _o5307 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5307, hr_str("v.u.v", 5)); hr_fi(&_o5307, i_1663); hr_fs(&_o5307, hr_str(".", 1)); if (_l5307->n + _o5307.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:447"); memcpy(_l5307->e + _l5307->n, _o5307.b, (size_t)_o5307.n); _l5307->n += _o5307.n; }));
{ hsl _v5309 = f10_nm(((int64_t)((f_1668).name_))); for (int64_t _k5309 = 0; _k5309 < _v5309.n; _k5309++) { uint8_t c_1670 = ((uint8_t*)_v5309.p)[_k5309]; (void)(({ L98 *_v5311 = &(e_1669); uint8_t _x5311 = c_1670; if (_v5311->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:447"); _v5311->e[_v5311->n] = _x5311; &_v5311->e[_v5311->n++]; }));
 } } _bk5308:; 
(void)(({ L98 *_v5312 = &(e_1669); uint8_t _x5312 = ((uint8_t)95LL); if (_v5312->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:447"); _v5312->e[_v5312->n] = _x5312; &_v5312->e[_v5312->n++]; }));
(void)(f303_hf_val(((int64_t)((f_1668).ty_)), ({ hsl _t5314 = ({ L98 *_t5315 = &(e_1669); (hsl){ (uint8_t*)_t5315->e, _t5315->n }; }); int64_t _l5314 = 0, _h5314 = _t5314.n; if (_l5314 < 0 || _h5314 < _l5314 || _h5314 > _t5314.n) hr_slerr(_l5314, _h5314, _t5314.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:447"); (hsl){ _t5314.p + _l5314 * (int64_t)sizeof(uint8_t), _h5314 - _l5314 }; })));
 } } _bk5301:; 
(void)(f301_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 } else { (void)(f301_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f301_hh(f10_nm(((int64_t)(((*({ hrv *_t5320 = &(g555); int64_t _i5320 = ei_1661; (S8*)_t5320->b + hr_ix(_i5320, _t5320->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:448"); }))).name_)))));
(void)(f301_hh(hr_str(".", 1)));
(void)(f301_hh(f10_nm(((int64_t)((v_1664).name_)))));
(void)(f301_hh(hr_str("\"); ", 4)));
 }
(void)(f301_hh(hr_str("} ", 2)));
 } } _bk5290:; 
 }
if (((k_1633) == (((int64_t)7LL)))) { int64_t ei_1671 = ((int64_t)((x_1632).a_)); 
S9 v_1672 = (*({ hrv *_t5326 = &(g556); int64_t _i5326 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5327 = &(g555); int64_t _i5327 = ei_1671; (S8*)_t5327->b + hr_ix(_i5327, _t5327->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:453"); }))).v0_)) + (int64_t)((int64_t)((x_1632).c_)))); (S9*)_t5326->b + hr_ix(_i5326, _t5326->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:453"); })); 
if (((((v_1672).si_) >= (((int32_t)0LL))) && ((((*({ hrv *_t5328 = &(g553); int64_t _i5328 = (v_1672).si_; (S10*)_t5328->b + hr_ix(_i5328, _t5328->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); }))).fnum_) > (((int32_t)0LL))))) { (void)(f301_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f301_hh(f10_nm(((int64_t)((v_1672).name_)))));
(void)(f301_hh(hr_str(" { \"); ", 7)));
bool first_1673 = true; 
int64_t sf0_1674 = ((int64_t)(((*({ hrv *_t5333 = &(g553); int64_t _i5333 = (v_1672).si_; (S10*)_t5333->b + hr_ix(_i5333, _t5333->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); }))).f0_)); 
{ int32_t _e5335 = ((*({ hrv *_t5336 = &(g553); int64_t _i5336 = (v_1672).si_; (S10*)_t5336->b + hr_ix(_i5336, _t5336->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); }))).fnum_; for (int32_t _k5335 = 0; _k5335 < _e5335; _k5335++) { int32_t j_1675 = (int32_t)_k5335; S11 f_1676 = (*({ hrv *_t5337 = &(g554); int64_t _i5337 = ((int64_t)((int64_t)sf0_1674 + (int64_t)((int64_t)(j_1675)))); (S11*)_t5337->b + hr_ix(_i5337, _t5337->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); })); 
if ((((f_1676).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1673))) { (void)(f301_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1673 = false;
L98 e_1677 = ({ L98 _t5339; memset(&_t5339, 0, sizeof _t5339); _t5339.n = 0; _t5339; }); 
(void)(({ L98 *_v5340 = &(e_1677); hsl _s5340 = hr_str("v.", 2); if (_v5340->n + _s5340.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); memmove(_v5340->e + _v5340->n, _s5340.p, (size_t)_s5340.n * sizeof _v5340->e[0]); _v5340->n += _s5340.n; }));
{ hsl _v5342 = f10_nm(((int64_t)((f_1676).name_))); for (int64_t _k5342 = 0; _k5342 < _v5342.n; _k5342++) { uint8_t c_1678 = ((uint8_t*)_v5342.p)[_k5342]; (void)(({ L98 *_v5344 = &(e_1677); uint8_t _x5344 = c_1678; if (_v5344->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); _v5344->e[_v5344->n] = _x5344; &_v5344->e[_v5344->n++]; }));
 } } _bk5341:; 
(void)(({ L98 *_v5345 = &(e_1677); uint8_t _x5345 = ((uint8_t)95LL); if (_v5345->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); _v5345->e[_v5345->n] = _x5345; &_v5345->e[_v5345->n++]; }));
(void)(f303_hf_val(((int64_t)((f_1676).ty_)), ({ hsl _t5347 = ({ L98 *_t5348 = &(e_1677); (hsl){ (uint8_t*)_t5348->e, _t5348->n }; }); int64_t _l5347 = 0, _h5347 = _t5347.n; if (_l5347 < 0 || _h5347 < _l5347 || _h5347 > _t5347.n) hr_slerr(_l5347, _h5347, _t5347.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); (hsl){ _t5347.p + _l5347 * (int64_t)sizeof(uint8_t), _h5347 - _l5347 }; })));
 } } _bk5334:; 
(void)(f301_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 } else { (void)(f301_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f301_hh(f10_nm(((int64_t)(((*({ hrv *_t5353 = &(g555); int64_t _i5353 = ei_1671; (S8*)_t5353->b + hr_ix(_i5353, _t5353->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:455"); }))).name_)))));
(void)(f301_hh(hr_str(".", 1)));
(void)(f301_hh(f10_nm(((int64_t)((v_1672).name_)))));
(void)(f301_hh(hr_str("\"); ", 4)));
 }
 }
if ((((k_1633) == (((int64_t)8LL))) || ((k_1633) == (((int64_t)9LL))))) { int64_t e_1679 = ((int64_t)((x_1632).a_)); 
(void)(f262_cbody(e_1679));
(void)(f301_hh(hr_str("hr_fb(o, '['); ", 15)));
if (f282_is_fix(t_1631)) { (void)(({ hrv *_o5361 = &(g169); hr_fs(_o5361, hr_str("for (int64_t i = 0; i < ", 24)); hr_fi(_o5361, (x_1632).b_); hr_fs(_o5361, hr_str("; i++) { if (i) hr_fc(o, \", \"); ", 32)); }));
(void)(f303_hf_val(e_1679, hr_str("v.e[i]", 6)));
(void)(f301_hh(hr_str("} ", 2)));
 } else { if (f283_is_lim(t_1631)) { (void)(f301_hh(hr_str("for (int64_t i = 0; i < v.n; i++) { if (i) hr_fc(o, \", \"); ", 59)));
(void)(f303_hf_val(e_1679, hr_str("v.e[i]", 6)));
(void)(f301_hh(hr_str("} ", 2)));
 } else { (void)(f301_hh(hr_str("for (int64_t i = 0; i < v.n; i++) { if (i) hr_fc(o, \", \"); ", 59)));
L98 ex_1680 = ({ L98 _t5369; memset(&_t5369, 0, sizeof _t5369); _t5369.n = 0; _t5369; }); 
(void)(({ L98 *_v5370 = &(ex_1680); hsl _s5370 = hr_str("((", 2); if (_v5370->n + _s5370.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:463"); memmove(_v5370->e + _v5370->n, _s5370.p, (size_t)_s5370.n * sizeof _v5370->e[0]); _v5370->n += _s5370.n; }));
(void)(({ L98 *_v5371 = &(ex_1680); hsl _s5371 = f264_cn(e_1679); if (_v5371->n + _s5371.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:463"); memmove(_v5371->e + _v5371->n, _s5371.p, (size_t)_s5371.n * sizeof _v5371->e[0]); _v5371->n += _s5371.n; }));
(void)(({ L98 *_v5373 = &(ex_1680); hsl _s5373 = hr_str("*)v.p)[i]", 9); if (_v5373->n + _s5373.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:463"); memmove(_v5373->e + _v5373->n, _s5373.p, (size_t)_s5373.n * sizeof _v5373->e[0]); _v5373->n += _s5373.n; }));
(void)(f303_hf_val(e_1679, ({ hsl _t5375 = ({ L98 *_t5376 = &(ex_1680); (hsl){ (uint8_t*)_t5376->e, _t5376->n }; }); int64_t _l5375 = 0, _h5375 = _t5375.n; if (_l5375 < 0 || _h5375 < _l5375 || _h5375 > _t5375.n) hr_slerr(_l5375, _h5375, _t5375.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:463"); (hsl){ _t5375.p + _l5375 * (int64_t)sizeof(uint8_t), _h5375 - _l5375 }; })));
(void)(f301_hh(hr_str("} ", 2)));
 }
 }
(void)(f301_hh(hr_str("hr_fb(o, ']'); ", 15)));
 }
if (((k_1633) == (((int64_t)14LL)))) { { int32_t _e5380 = (x_1632).n_; for (int32_t _k5380 = 0; _k5380 < _e5380; _k5380++) { int32_t i_1681 = (int32_t)_k5380; if (((i_1681) > (((int32_t)0LL)))) { (void)(f301_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
L99 e_1682 = ({ L99 _t5382; memset(&_t5382, 0, sizeof _t5382); _t5382.n = 0; _t5382; }); 
(void)(({ L99 *_l5383 = &(e_1682); hrv _o5383 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5383, hr_str("v.r", 3)); hr_fi(&_o5383, i_1681); if (_l5383->n + _o5383.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:466"); memcpy(_l5383->e + _l5383->n, _o5383.b, (size_t)_o5383.n); _l5383->n += _o5383.n; }));
(void)(f303_hf_val(((int64_t)((*({ hrv *_t5385 = &(g551); int64_t _i5385 = ((int64_t)((int64_t)((int64_t)((x_1632).l_)) + (int64_t)((int64_t)(i_1681)))); (int32_t*)_t5385->b + hr_ix(_i5385, _t5385->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:466"); })))), ({ hsl _t5386 = ({ L99 *_t5387 = &(e_1682); (hsl){ (uint8_t*)_t5387->e, _t5387->n }; }); int64_t _l5386 = 0, _h5386 = _t5386.n; if (_l5386 < 0 || _h5386 < _l5386 || _h5386 > _t5386.n) hr_slerr(_l5386, _h5386, _t5386.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:466"); (hsl){ _t5386.p + _l5386 * (int64_t)sizeof(uint8_t), _h5386 - _l5386 }; })));
 } } _bk5379:; 
 }
(void)(f301_hh(hr_str("}\012", 2)));
}
static void f300_hf_pre(int64_t t_1635) {
(void)(f296_comp_pre(t_1635, true));
}
static void f301_hh(hsl s_1638) {
(void)(({ hrv *_v5390 = &(g169); hsl _s5390 = s_1638; hr_append(_v5390, _s5390.p, _s5390.n, sizeof(uint8_t)); }));
}
static void f302_fn_cname_to(hrv* b_1645, int64_t i_1646) {
(void)(({ hrv *_o5391 = b_1645; hr_fs(_o5391, hr_str("f", 1)); hr_fi(_o5391, i_1646); hr_fs(_o5391, hr_str("_", 1)); }));
int64_t s_1647 = ((int64_t)(((*({ hrv *_t5392 = &(g387); int64_t _i5392 = i_1646; (S6*)_t5392->b + hr_ix(_i5392, _t5392->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:566"); }))).name_)); 
if (((s_1647) >= (((int64_t)0LL)))) { { hsl _v5394 = f10_nm(s_1647); for (int64_t _k5394 = 0; _k5394 < _v5394.n; _k5394++) { uint8_t c_1648 = ((uint8_t*)_v5394.p)[_k5394]; (void)(({ hrv *_v5396 = b_1645; uint8_t _x5396 = ({ uint8_t _r5397; if (((c_1648) == (((uint8_t)58LL)))) { _r5397 = ((uint8_t)95LL);  } else { _r5397 = c_1648;  } _r5397; }); uint8_t *_p5396 = (uint8_t*)hr_grow(_v5396, 1, sizeof _x5396); *_p5396 = _x5396; _p5396; }));
 } } _bk5393:; 
 }
}
static void f303_hf_val(int64_t t_1657, hsl e_1658) {
int64_t k_1659 = ((int64_t)(((*({ hrv *_t5398 = &(g550); int64_t _i5398 = t_1657; (S1*)_t5398->b + hr_ix(_i5398, _t5398->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:402"); }))).k_)); 
if (f164_is_byte_arr(t_1657)) { if (f282_is_fix(t_1657)) { (void)(({ hrv *_o5401 = &(g169); hr_fs(_o5401, hr_str("hr_fq(o, (hsl){ (uint8_t*)(", 27)); hr_fs(_o5401, e_1658); hr_fs(_o5401, hr_str(").e, ", 5)); hr_fi(_o5401, ((*({ hrv *_t5402 = &(g550); int64_t _i5402 = t_1657; (S1*)_t5402->b + hr_ix(_i5402, _t5402->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).b_); hr_fs(_o5401, hr_str(" }); ", 5)); }));
return;
 }
if (f283_is_lim(t_1657)) { (void)(({ hrv *_o5404 = &(g169); hr_fs(_o5404, hr_str("hr_fq(o, (hsl){ (uint8_t*)(", 27)); hr_fs(_o5404, e_1658); hr_fs(_o5404, hr_str(").e, (", 6)); hr_fs(_o5404, e_1658); hr_fs(_o5404, hr_str(").n }); ", 8)); }));
return;
 }
if (((((*({ hrv *_t5405 = &(g550); int64_t _i5405 = t_1657; (S1*)_t5405->b + hr_ix(_i5405, _t5405->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).k_) == (((uint8_t)9LL)))) { (void)(({ hrv *_o5406 = &(g169); hr_fs(_o5406, hr_str("hr_fq(o, ", 9)); hr_fs(_o5406, e_1658); hr_fs(_o5406, hr_str("); ", 3)); }));
return;
 }
(void)(({ hrv *_o5407 = &(g169); hr_fs(_o5407, hr_str("hr_fq(o, hr_sl(", 15)); hr_fs(_o5407, e_1658); hr_fs(_o5407, hr_str(")); ", 4)); }));
return;
 }
if (((k_1659) == (((int64_t)3LL)))) { (void)(({ hrv *_o5408 = &(g169); hr_fs(_o5408, ({ hsl _r5409; if (f153_is_signed(t_1657)) { _r5409 = hr_str("hr_fi(o, ", 9);  } else { _r5409 = hr_str("hr_fu(o, ", 9);  } _r5409; })); hr_fs(_o5408, e_1658); hr_fs(_o5408, hr_str("); ", 3)); }));
return;
 }
if (((k_1659) == (((int64_t)4LL)))) { (void)(({ hrv *_o5411 = &(g169); hr_fs(_o5411, ({ hsl _r5412; if (((((*({ hrv *_t5413 = &(g550); int64_t _i5413 = t_1657; (S1*)_t5413->b + hr_ix(_i5413, _t5413->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:405"); }))).s_) == (((uint8_t)4LL)))) { _r5412 = hr_str("hr_ff(o, ", 9);  } else { _r5412 = hr_str("hr_fd(o, ", 9);  } _r5412; })); hr_fs(_o5411, e_1658); hr_fs(_o5411, hr_str("); ", 3)); }));
return;
 }
if (((k_1659) == (((int64_t)2LL)))) { (void)(({ hrv *_o5414 = &(g169); hr_fs(_o5414, hr_str("hr_fc(o, (", 10)); hr_fs(_o5414, e_1658); hr_fs(_o5414, hr_str(") \077 \"true\" : \"false\"); ", 23)); }));
return;
 }
if (((k_1659) == (((int64_t)10LL)))) { if (((((*({ hrv *_t5415 = &(g550); int64_t _i5415 = t_1657; (S1*)_t5415->b + hr_ix(_i5415, _t5415->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:407"); }))).c_) >= (((int32_t)0LL)))) { (void)(({ hrv *_o5416 = &(g169); hr_fs(_o5416, hr_str("hr_fu(o, ", 9)); hr_fs(_o5416, e_1658); hr_fs(_o5416, hr_str("); ", 3)); }));
return;
 }
L97 pe_1660 = ({ L97 _t5417; memset(&_t5417, 0, sizeof _t5417); _t5417.n = 0; _t5417; }); 
(void)(({ L97 *_l5418 = &(pe_1660); hrv _o5418 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5418, hr_str("(*(", 3)); hr_fs(&_o5418, e_1658); hr_fs(&_o5418, hr_str("))", 2)); if (_l5418->n + _o5418.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:407"); memcpy(_l5418->e + _l5418->n, _o5418.b, (size_t)_o5418.n); _l5418->n += _o5418.n; }));
(void)(({ hrv *_o5419 = &(g169); hr_fs(_o5419, hr_str("if (", 4)); hr_fs(_o5419, e_1658); hr_fs(_o5419, hr_str(") { ", 4)); }));
(void)(f303_hf_val(((int64_t)(((*({ hrv *_t5421 = &(g550); int64_t _i5421 = t_1657; (S1*)_t5421->b + hr_ix(_i5421, _t5421->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:407"); }))).a_)), ({ hsl _t5422 = ({ L97 *_t5423 = &(pe_1660); (hsl){ (uint8_t*)_t5423->e, _t5423->n }; }); int64_t _l5422 = 0, _h5422 = _t5422.n; if (_l5422 < 0 || _h5422 < _l5422 || _h5422 > _t5422.n) hr_slerr(_l5422, _h5422, _t5422.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:407"); (hsl){ _t5422.p + _l5422 * (int64_t)sizeof(uint8_t), _h5422 - _l5422 }; })));
(void)(f301_hh(hr_str("} else hr_fc(o, \"null\"); ", 25)));
return;
 }
if (((((k_1659) == (((int64_t)8LL))) && (!(f282_is_fix(t_1657)))) && (!(f283_is_lim(t_1657))))) { (void)(({ hrv *_o5427 = &(g169); hr_fs(_o5427, hr_str("hf", 2)); hr_fi(_o5427, t_1657); hr_fs(_o5427, hr_str("(o, hr_sl(", 10)); hr_fs(_o5427, e_1658); hr_fs(_o5427, hr_str(")); ", 4)); }));
return;
 }
(void)(({ hrv *_o5428 = &(g169); hr_fs(_o5428, hr_str("hf", 2)); hr_fi(_o5428, t_1657); hr_fs(_o5428, hr_str("(o, ", 4)); hr_fs(_o5428, e_1658); hr_fs(_o5428, hr_str("); ", 3)); }));
}
static void f304_heq_val(int64_t t_1701, hsl a_1702, hsl b_1703) {
int64_t k_1704 = ((int64_t)(((*({ hrv *_t5429 = &(g550); int64_t _i5429 = t_1701; (S1*)_t5429->b + hr_ix(_i5429, _t5429->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:470"); }))).k_)); 
if ((((((k_1704) == (((int64_t)3LL))) || ((k_1704) == (((int64_t)4LL)))) || ((k_1704) == (((int64_t)2LL)))) || ((k_1704) == (((int64_t)10LL))))) { (void)(({ hrv *_o5430 = &(g169); hr_fs(_o5430, hr_str("(", 1)); hr_fs(_o5430, a_1702); hr_fs(_o5430, hr_str(") == (", 6)); hr_fs(_o5430, b_1703); hr_fs(_o5430, hr_str(")", 1)); }));
return;
 }
(void)(f295_gen_heq(t_1701));
if ((((k_1704) == (((int64_t)9LL))) || ((((k_1704) == (((int64_t)8LL))) && (!(f282_is_fix(t_1701)))) && (!(f283_is_lim(t_1701)))))) { (void)(({ hrv *_o5434 = &(g169); hr_fs(_o5434, hr_str("heq", 3)); hr_fi(_o5434, t_1701); hr_fs(_o5434, hr_str("(hr_sl(", 7)); hr_fs(_o5434, a_1702); hr_fs(_o5434, hr_str("), hr_sl(", 9)); hr_fs(_o5434, b_1703); hr_fs(_o5434, hr_str("))", 2)); }));
return;
 }
(void)(({ hrv *_o5435 = &(g169); hr_fs(_o5435, hr_str("heq", 3)); hr_fi(_o5435, t_1701); hr_fs(_o5435, hr_str("(", 1)); hr_fs(_o5435, a_1702); hr_fs(_o5435, hr_str(", ", 2)); hr_fs(_o5435, b_1703); hr_fs(_o5435, hr_str(")", 1)); }));
}
static bool f305_hsl_ty(int64_t t_1714) {
return (((((*({ hrv *_t5436 = &(g550); int64_t _i5436 = t_1714; (S1*)_t5436->b + hr_ix(_i5436, _t5436->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:772"); }))).k_) == (((uint8_t)9LL))) || ((((((*({ hrv *_t5437 = &(g550); int64_t _i5437 = t_1714; (S1*)_t5437->b + hr_ix(_i5437, _t5437->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:772"); }))).k_) == (((uint8_t)8LL))) && (!(f282_is_fix(t_1714)))) && (!(f283_is_lim(t_1714)))));
}
static void f306_gxas(int64_t n_1715, int64_t t_1716) {
int64_t f_1717 = f279_fin(n_1715); 
if (((f_1717) == (t_1716))) { (void)(f289_gx(n_1715));
return;
 }
(void)(f270_gcv(n_1715, f141_at(n_1715), t_1716));
}
static void f307_garith(int64_t o_1719, int64_t t0_1720, int64_t a_1721, int64_t b_1722, int64_t tv_1723, int64_t loc_1724) {
int64_t t_1725 = ({ int64_t _r5444; if (((((*({ hrv *_t5445 = &(g550); int64_t _i5445 = t0_1720; (S1*)_t5445->b + hr_ix(_i5445, _t5445->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:237"); }))).k_) == (((uint8_t)12LL)))) { _r5444 = g562;  } else { _r5444 = ({ int64_t _r5446; if (((((*({ hrv *_t5447 = &(g550); int64_t _i5447 = t0_1720; (S1*)_t5447->b + hr_ix(_i5447, _t5447->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:237"); }))).k_) == (((uint8_t)13LL)))) { _r5446 = g568;  } else { _r5446 = t0_1720;  } _r5446; });  } _r5444; }); 
int64_t k_1726 = ((int64_t)(((*({ hrv *_t5448 = &(g550); int64_t _i5448 = t_1725; (S1*)_t5448->b + hr_ix(_i5448, _t5448->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:238"); }))).k_)); 
int64_t lk_1727 = f180_leaf_kind(t_1725); 
if (((lk_1727) >= (((int64_t)4LL)))) { int64_t ta_1728 = ({ int64_t _r5450; if (((a_1721) >= (((int64_t)0LL)))) { _r5450 = f279_fin(a_1721);  } else { _r5450 = t_1725;  } _r5450; }); 
int64_t tb_1729 = ({ int64_t _r5452; if (((b_1722) >= (((int64_t)0LL)))) { _r5452 = f279_fin(b_1722);  } else { _r5452 = t_1725;  } _r5452; }); 
if (((ta_1728) != (t_1725))) { if (((o_1719) != (((int64_t)23LL)))) { (void)(f287_gerr(loc_1724, hr_str("only * takes a scalar on the left of a struct or array", 54)));
return;
 }
(void)(f260_ow(hr_str("hop", 3)));
(void)(f294_oi(t_1725));
(void)(f260_ow(hr_str("_", 1)));
(void)(f294_oi(o_1719));
(void)(f260_ow(hr_str("(", 1)));
(void)(f308_gopnd(b_1722, tv_1723));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f308_gopnd(a_1721, tv_1723));
(void)(f260_ow(hr_str(")", 1)));
(void)(f309_gen_hop(t_1725, o_1719, ta_1728));
return;
 }
(void)(f260_ow(hr_str("hop", 3)));
(void)(f294_oi(t_1725));
(void)(f260_ow(hr_str("_", 1)));
(void)(f294_oi(o_1719));
(void)(f260_ow(hr_str("(", 1)));
(void)(f308_gopnd(a_1721, tv_1723));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f308_gopnd(b_1722, tv_1723));
(void)(f260_ow(hr_str(")", 1)));
(void)(f309_gen_hop(t_1725, o_1719, tb_1729));
return;
 }
if (((k_1726) == (((int64_t)4LL)))) { if (((o_1719) == (((int64_t)25LL)))) { (void)(f260_ow(({ hsl _r5476; if (((((*({ hrv *_t5477 = &(g550); int64_t _i5477 = t_1725; (S1*)_t5477->b + hr_ix(_i5477, _t5477->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:245"); }))).s_) == (((uint8_t)4LL)))) { _r5476 = hr_str("fmodf(", 6);  } else { _r5476 = hr_str("fmod(", 5);  } _r5476; })));
(void)(f308_gopnd(a_1721, tv_1723));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f308_gopnd(b_1722, tv_1723));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
(void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1725));
(void)(f260_ow(hr_str(")(", 2)));
(void)(f308_gopnd(a_1721, tv_1723));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f260_ow(f311_ar_op(o_1719)));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f308_gopnd(b_1722, tv_1723));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (((k_1726) == (((int64_t)2LL)))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f308_gopnd(a_1721, tv_1723));
(void)(f260_ow(hr_str(") ", 2)));
(void)(f260_ow(f311_ar_op(o_1719)));
(void)(f260_ow(hr_str(" (", 2)));
(void)(f308_gopnd(b_1722, tv_1723));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
bool sg_1760 = (((k_1726) == (((int64_t)3LL))) && f153_is_signed(t_1725)); 
if ((((o_1719) == (((int64_t)24LL))) || ((o_1719) == (((int64_t)25LL))))) { (void)(f260_ow(({ hsl _r5502; if (((o_1719) == (((int64_t)24LL)))) { _r5502 = ({ hsl _r5503; if (sg_1760) { _r5503 = hr_str("HR_SDIV(", 8);  } else { _r5503 = hr_str("HR_UDIV(", 8);  } _r5503; });  } else { _r5502 = ({ hsl _r5504; if (sg_1760) { _r5504 = hr_str("HR_SMOD(", 8);  } else { _r5504 = hr_str("HR_UDIV_MOD(", 12);  } _r5504; });  } _r5502; })));
(void)(f261_ct(t_1725));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f308_gopnd(a_1721, tv_1723));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f308_gopnd(b_1722, tv_1723));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f312_wloc(loc_1724));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if ((((o_1719) == (((int64_t)43LL))) || ((o_1719) == (((int64_t)44LL))))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1725));
(void)(f260_ow(hr_str(")((", 3)));
(void)(f308_gopnd(a_1721, tv_1723));
(void)(f260_ow(hr_str(") ", 2)));
(void)(f260_ow(f311_ar_op(o_1719)));
(void)(f260_ow(hr_str(" ((", 3)));
(void)(f308_gopnd(b_1722, tv_1723));
(void)(({ hrv *_o5522 = &(g163); hr_fs(_o5522, hr_str(") & ", 4)); hr_fi(_o5522, ((int64_t)((int64_t)f154_ibits(t_1725) - (int64_t)((int64_t)1LL)))); hr_fs(_o5522, hr_str(")))", 3)); }));
return;
 }
(void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1725));
(void)(f260_ow(hr_str(")(", 2)));
if (sg_1760) { (void)(f260_ow(hr_str("(int64_t)", 9)));
 } else { (void)(f260_ow(hr_str("(uint64_t)", 10)));
 }
(void)(f308_gopnd(a_1721, tv_1723));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f260_ow(f311_ar_op(o_1719)));
(void)(f260_ow(hr_str(" ", 1)));
if (sg_1760) { (void)(f260_ow(hr_str("(int64_t)", 9)));
 } else { (void)(f260_ow(hr_str("(uint64_t)", 10)));
 }
(void)(f308_gopnd(b_1722, tv_1723));
(void)(f260_ow(hr_str("))", 2)));
}
static void f308_gopnd(int64_t n_1730, int64_t tv_1731) {
if (((n_1730) >= (((int64_t)0LL)))) { (void)(f289_gx(n_1730));
 } else { (void)(({ hrv *_o5539 = &(g163); hr_fs(_o5539, hr_str("(*_t", 4)); hr_fi(_o5539, tv_1731); hr_fs(_o5539, hr_str(")", 1)); }));
 }
}
static void f309_gen_hop(int64_t t_1732, int64_t o_1733, int64_t bt_1734) {
int64_t key_1735 = ((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)(t_1732)) * (int64_t)((int64_t)4096LL))) + (int64_t)((int64_t)((int64_t)((int64_t)(o_1733)) * (int64_t)((int64_t)64LL))))) + (int64_t)({ int64_t _r5540; if (((bt_1734) == (t_1732))) { _r5540 = ((int64_t)0LL);  } else { _r5540 = ((int64_t)1LL);  } _r5540; }))); 
{ hrv *_v5542 = &(g240); for (int64_t _k5542 = 0; _k5542 < _v5542->n; _k5542++) { int64_t h_1736 = ((int64_t*)_v5542->b)[_k5542]; if (((h_1736) == (key_1735))) { return;
 }
 } } _bk5541:; 
(void)(({ hrv *_v5543 = &(g240); int64_t _x5543 = key_1735; int64_t *_p5543 = (int64_t*)hr_grow(_v5543, 1, sizeof _x5543); *_p5543 = _x5543; _p5543; }));
(void)(f262_cbody(t_1732));
int64_t lt_1737 = f181_leaf_type(t_1732); 
bool sc_1738 = ((bt_1734) != (t_1732)); 
L97 sig_1739 = ({ L97 _t5546; memset(&_t5546, 0, sizeof _t5546); _t5546.n = 0; _t5546; }); 
(void)(({ L97 *_l5547 = &(sig_1739); hrv _o5547 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5547, hr_str("static ", 7)); if (_l5547->n + _o5547.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:523"); memcpy(_l5547->e + _l5547->n, _o5547.b, (size_t)_o5547.n); _l5547->n += _o5547.n; }));
(void)(({ L97 *_v5548 = &(sig_1739); hsl _s5548 = f264_cn(t_1732); if (_v5548->n + _s5548.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:523"); memmove(_v5548->e + _v5548->n, _s5548.p, (size_t)_s5548.n * sizeof _v5548->e[0]); _v5548->n += _s5548.n; }));
(void)(({ L97 *_l5550 = &(sig_1739); hrv _o5550 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5550, hr_str(" hop", 4)); hr_fi(&_o5550, t_1732); hr_fs(&_o5550, hr_str("_", 1)); hr_fi(&_o5550, o_1733); hr_fs(&_o5550, hr_str("(", 1)); if (_l5550->n + _o5550.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:523"); memcpy(_l5550->e + _l5550->n, _o5550.b, (size_t)_o5550.n); _l5550->n += _o5550.n; }));
(void)(({ L97 *_v5551 = &(sig_1739); hsl _s5551 = f264_cn(t_1732); if (_v5551->n + _s5551.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:524"); memmove(_v5551->e + _v5551->n, _s5551.p, (size_t)_s5551.n * sizeof _v5551->e[0]); _v5551->n += _s5551.n; }));
(void)(({ L97 *_v5553 = &(sig_1739); hsl _s5553 = hr_str(" a, ", 4); if (_v5553->n + _s5553.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:524"); memmove(_v5553->e + _v5553->n, _s5553.p, (size_t)_s5553.n * sizeof _v5553->e[0]); _v5553->n += _s5553.n; }));
(void)(({ L97 *_v5554 = &(sig_1739); hsl _s5554 = f264_cn(({ int64_t _r5556; if (sc_1738) { _r5556 = bt_1734;  } else { _r5556 = t_1732;  } _r5556; })); if (_v5554->n + _s5554.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:524"); memmove(_v5554->e + _v5554->n, _s5554.p, (size_t)_s5554.n * sizeof _v5554->e[0]); _v5554->n += _s5554.n; }));
(void)(({ L97 *_v5557 = &(sig_1739); hsl _s5557 = hr_str(" b)", 3); if (_v5557->n + _s5557.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:524"); memmove(_v5557->e + _v5557->n, _s5557.p, (size_t)_s5557.n * sizeof _v5557->e[0]); _v5557->n += _s5557.n; }));
(void)(({ hrv *_v5558 = &(g166); hsl _s5558 = ({ hsl _t5559 = ({ L97 *_t5560 = &(sig_1739); (hsl){ (uint8_t*)_t5560->e, _t5560->n }; }); int64_t _l5559 = 0, _h5559 = _t5559.n; if (_l5559 < 0 || _h5559 < _l5559 || _h5559 > _t5559.n) hr_slerr(_l5559, _h5559, _t5559.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:525"); (hsl){ _t5559.p + _l5559 * (int64_t)sizeof(uint8_t), _h5559 - _l5559 }; }); hr_append(_v5558, _s5558.p, _s5558.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5561 = &(g166); hsl _s5561 = hr_str(";\012", 2); hr_append(_v5561, _s5561.p, _s5561.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5562 = &(g169); hsl _s5562 = ({ hsl _t5563 = ({ L97 *_t5564 = &(sig_1739); (hsl){ (uint8_t*)_t5564->e, _t5564->n }; }); int64_t _l5563 = 0, _h5563 = _t5563.n; if (_l5563 < 0 || _h5563 < _l5563 || _h5563 > _t5563.n) hr_slerr(_l5563, _h5563, _t5563.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:526"); (hsl){ _t5563.p + _l5563 * (int64_t)sizeof(uint8_t), _h5563 - _l5563 }; }); hr_append(_v5562, _s5562.p, _s5562.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" { ", 3)));
(void)(({ hrv *_v5566 = &(g169); hsl _s5566 = f264_cn(t_1732); hr_append(_v5566, _s5566.p, _s5566.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" r; ", 4)));
(void)(f310_hop_body(t_1732, o_1733, hr_str("r", 1), hr_str("a", 1), hr_str("b", 1), sc_1738));
(void)(f301_hh(hr_str("return r; }\012", 12)));
}
static void f310_hop_body(int64_t t_1740, int64_t o_1741, hsl r_1742, hsl a_1743, hsl b_1744, bool sc_1745) {
int64_t k_1746 = ((int64_t)(((*({ hrv *_t5571 = &(g550); int64_t _i5571 = t_1740; (S1*)_t5571->b + hr_ix(_i5571, _t5571->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:531"); }))).k_)); 
if ((((k_1746) == (((int64_t)3LL))) || ((k_1746) == (((int64_t)4LL))))) { (void)(({ hrv *_o5572 = &(g169); hr_fs(_o5572, r_1742); hr_fs(_o5572, hr_str(" = (", 4)); }));
(void)(({ hrv *_v5573 = &(g169); hsl _s5573 = f264_cn(t_1740); hr_append(_v5573, _s5573.p, _s5573.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o5575 = &(g169); hr_fs(_o5575, hr_str(")((", 3)); hr_fs(_o5575, a_1743); hr_fs(_o5575, hr_str(") ", 2)); hr_fs(_o5575, f311_ar_op(o_1741)); hr_fs(_o5575, hr_str(" (", 2)); hr_fs(_o5575, b_1744); hr_fs(_o5575, hr_str(")); ", 4)); }));
return;
 }
if (((k_1746) == (((int64_t)5LL)))) { int64_t si_1748 = ((int64_t)(((*({ hrv *_t5577 = &(g550); int64_t _i5577 = t_1740; (S1*)_t5577->b + hr_ix(_i5577, _t5577->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:534"); }))).a_)); 
int64_t f0_1749 = ((int64_t)(((*({ hrv *_t5578 = &(g553); int64_t _i5578 = si_1748; (S10*)_t5578->b + hr_ix(_i5578, _t5578->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:534"); }))).f0_)); 
{ int32_t _e5580 = ((*({ hrv *_t5581 = &(g553); int64_t _i5581 = si_1748; (S10*)_t5581->b + hr_ix(_i5581, _t5581->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:535"); }))).fnum_; for (int32_t _k5580 = 0; _k5580 < _e5580; _k5580++) { int32_t i_1750 = (int32_t)_k5580; S11 f_1751 = (*({ hrv *_t5582 = &(g554); int64_t _i5582 = ((int64_t)((int64_t)f0_1749 + (int64_t)((int64_t)(i_1750)))); (S11*)_t5582->b + hr_ix(_i5582, _t5582->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:536"); })); 
if ((((f_1751).ty_) < (((int32_t)0LL)))) { continue;
 }
L97 rr_1752 = ({ L97 _t5583; memset(&_t5583, 0, sizeof _t5583); _t5583.n = 0; _t5583; }); 
L97 aa_1753 = ({ L97 _t5584; memset(&_t5584, 0, sizeof _t5584); _t5584.n = 0; _t5584; }); 
L97 bb_1754 = ({ L97 _t5585; memset(&_t5585, 0, sizeof _t5585); _t5585.n = 0; _t5585; }); 
(void)(({ L97 *_v5586 = &(rr_1752); hsl _s5586 = r_1742; if (_v5586->n + _s5586.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:538"); memmove(_v5586->e + _v5586->n, _s5586.p, (size_t)_s5586.n * sizeof _v5586->e[0]); _v5586->n += _s5586.n; }));
(void)(({ L97 *_v5587 = &(rr_1752); uint8_t _x5587 = ((uint8_t)46LL); if (_v5587->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:538"); _v5587->e[_v5587->n] = _x5587; &_v5587->e[_v5587->n++]; }));
(void)(({ L97 *_v5588 = &(aa_1753); hsl _s5588 = a_1743; if (_v5588->n + _s5588.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:538"); memmove(_v5588->e + _v5588->n, _s5588.p, (size_t)_s5588.n * sizeof _v5588->e[0]); _v5588->n += _s5588.n; }));
(void)(({ L97 *_v5589 = &(aa_1753); uint8_t _x5589 = ((uint8_t)46LL); if (_v5589->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:538"); _v5589->e[_v5589->n] = _x5589; &_v5589->e[_v5589->n++]; }));
(void)(({ L97 *_v5590 = &(bb_1754); hsl _s5590 = b_1744; if (_v5590->n + _s5590.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:538"); memmove(_v5590->e + _v5590->n, _s5590.p, (size_t)_s5590.n * sizeof _v5590->e[0]); _v5590->n += _s5590.n; }));
if ((!(sc_1745))) { (void)(({ L97 *_v5591 = &(bb_1754); uint8_t _x5591 = ((uint8_t)46LL); if (_v5591->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:538"); _v5591->e[_v5591->n] = _x5591; &_v5591->e[_v5591->n++]; }));
 }
{ hsl _v5593 = f10_nm(((int64_t)((f_1751).name_))); for (int64_t _k5593 = 0; _k5593 < _v5593.n; _k5593++) { uint8_t ch_1755 = ((uint8_t*)_v5593.p)[_k5593]; (void)(({ L97 *_v5595 = &(rr_1752); uint8_t _x5595 = ch_1755; if (_v5595->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:539"); _v5595->e[_v5595->n] = _x5595; &_v5595->e[_v5595->n++]; }));
(void)(({ L97 *_v5596 = &(aa_1753); uint8_t _x5596 = ch_1755; if (_v5596->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:539"); _v5596->e[_v5596->n] = _x5596; &_v5596->e[_v5596->n++]; }));
if ((!(sc_1745))) { (void)(({ L97 *_v5597 = &(bb_1754); uint8_t _x5597 = ch_1755; if (_v5597->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:539"); _v5597->e[_v5597->n] = _x5597; &_v5597->e[_v5597->n++]; }));
 }
 } } _bk5592:; 
(void)(({ L97 *_v5598 = &(rr_1752); uint8_t _x5598 = ((uint8_t)95LL); if (_v5598->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:540"); _v5598->e[_v5598->n] = _x5598; &_v5598->e[_v5598->n++]; }));
(void)(({ L97 *_v5599 = &(aa_1753); uint8_t _x5599 = ((uint8_t)95LL); if (_v5599->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:540"); _v5599->e[_v5599->n] = _x5599; &_v5599->e[_v5599->n++]; }));
if ((!(sc_1745))) { (void)(({ L97 *_v5600 = &(bb_1754); uint8_t _x5600 = ((uint8_t)95LL); if (_v5600->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:540"); _v5600->e[_v5600->n] = _x5600; &_v5600->e[_v5600->n++]; }));
 }
(void)(f310_hop_body(((int64_t)((f_1751).ty_)), o_1741, ({ hsl _t5602 = ({ L97 *_t5603 = &(rr_1752); (hsl){ (uint8_t*)_t5603->e, _t5603->n }; }); int64_t _l5602 = 0, _h5602 = _t5602.n; if (_l5602 < 0 || _h5602 < _l5602 || _h5602 > _t5602.n) hr_slerr(_l5602, _h5602, _t5602.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:541"); (hsl){ _t5602.p + _l5602 * (int64_t)sizeof(uint8_t), _h5602 - _l5602 }; }), ({ hsl _t5604 = ({ L97 *_t5605 = &(aa_1753); (hsl){ (uint8_t*)_t5605->e, _t5605->n }; }); int64_t _l5604 = 0, _h5604 = _t5604.n; if (_l5604 < 0 || _h5604 < _l5604 || _h5604 > _t5604.n) hr_slerr(_l5604, _h5604, _t5604.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:541"); (hsl){ _t5604.p + _l5604 * (int64_t)sizeof(uint8_t), _h5604 - _l5604 }; }), ({ hsl _t5606 = ({ L97 *_t5607 = &(bb_1754); (hsl){ (uint8_t*)_t5607->e, _t5607->n }; }); int64_t _l5606 = 0, _h5606 = _t5606.n; if (_l5606 < 0 || _h5606 < _l5606 || _h5606 > _t5606.n) hr_slerr(_l5606, _h5606, _t5606.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:541"); (hsl){ _t5606.p + _l5606 * (int64_t)sizeof(uint8_t), _h5606 - _l5606 }; }), sc_1745));
 } } _bk5579:; 
return;
 }
if (f282_is_fix(t_1740)) { int64_t p_1756 = f293_nt(); 
(void)(({ hrv *_o5610 = &(g169); hr_fs(_o5610, hr_str("for (int64_t _i", 15)); hr_fi(_o5610, p_1756); hr_fs(_o5610, hr_str(" = 0; _i", 8)); hr_fi(_o5610, p_1756); hr_fs(_o5610, hr_str(" < ", 3)); hr_fi(_o5610, ((*({ hrv *_t5611 = &(g550); int64_t _i5611 = t_1740; (S1*)_t5611->b + hr_ix(_i5611, _t5611->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:547"); }))).b_); hr_fs(_o5610, hr_str("; _i", 4)); hr_fi(_o5610, p_1756); hr_fs(_o5610, hr_str("++) { ", 6)); }));
L97 rr_1757 = ({ L97 _t5612; memset(&_t5612, 0, sizeof _t5612); _t5612.n = 0; _t5612; }); 
L97 aa_1758 = ({ L97 _t5613; memset(&_t5613, 0, sizeof _t5613); _t5613.n = 0; _t5613; }); 
L97 bb_1759 = ({ L97 _t5614; memset(&_t5614, 0, sizeof _t5614); _t5614.n = 0; _t5614; }); 
(void)(({ L97 *_l5615 = &(rr_1757); hrv _o5615 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5615, r_1742); hr_fs(&_o5615, hr_str(".e[_i", 5)); hr_fi(&_o5615, p_1756); hr_fs(&_o5615, hr_str("]", 1)); if (_l5615->n + _o5615.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:549"); memcpy(_l5615->e + _l5615->n, _o5615.b, (size_t)_o5615.n); _l5615->n += _o5615.n; }));
(void)(({ L97 *_l5616 = &(aa_1758); hrv _o5616 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5616, a_1743); hr_fs(&_o5616, hr_str(".e[_i", 5)); hr_fi(&_o5616, p_1756); hr_fs(&_o5616, hr_str("]", 1)); if (_l5616->n + _o5616.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:549"); memcpy(_l5616->e + _l5616->n, _o5616.b, (size_t)_o5616.n); _l5616->n += _o5616.n; }));
if (sc_1745) { (void)(({ L97 *_v5617 = &(bb_1759); hsl _s5617 = b_1744; if (_v5617->n + _s5617.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:549"); memmove(_v5617->e + _v5617->n, _s5617.p, (size_t)_s5617.n * sizeof _v5617->e[0]); _v5617->n += _s5617.n; }));
 } else { (void)(({ L97 *_l5618 = &(bb_1759); hrv _o5618 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5618, b_1744); hr_fs(&_o5618, hr_str(".e[_i", 5)); hr_fi(&_o5618, p_1756); hr_fs(&_o5618, hr_str("]", 1)); if (_l5618->n + _o5618.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:549"); memcpy(_l5618->e + _l5618->n, _o5618.b, (size_t)_o5618.n); _l5618->n += _o5618.n; }));
 }
(void)(f310_hop_body(((int64_t)(((*({ hrv *_t5620 = &(g550); int64_t _i5620 = t_1740; (S1*)_t5620->b + hr_ix(_i5620, _t5620->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:550"); }))).a_)), o_1741, ({ hsl _t5621 = ({ L97 *_t5622 = &(rr_1757); (hsl){ (uint8_t*)_t5622->e, _t5622->n }; }); int64_t _l5621 = 0, _h5621 = _t5621.n; if (_l5621 < 0 || _h5621 < _l5621 || _h5621 > _t5621.n) hr_slerr(_l5621, _h5621, _t5621.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:550"); (hsl){ _t5621.p + _l5621 * (int64_t)sizeof(uint8_t), _h5621 - _l5621 }; }), ({ hsl _t5623 = ({ L97 *_t5624 = &(aa_1758); (hsl){ (uint8_t*)_t5624->e, _t5624->n }; }); int64_t _l5623 = 0, _h5623 = _t5623.n; if (_l5623 < 0 || _h5623 < _l5623 || _h5623 > _t5623.n) hr_slerr(_l5623, _h5623, _t5623.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:550"); (hsl){ _t5623.p + _l5623 * (int64_t)sizeof(uint8_t), _h5623 - _l5623 }; }), ({ hsl _t5625 = ({ L97 *_t5626 = &(bb_1759); (hsl){ (uint8_t*)_t5626->e, _t5626->n }; }); int64_t _l5625 = 0, _h5625 = _t5625.n; if (_l5625 < 0 || _h5625 < _l5625 || _h5625 > _t5625.n) hr_slerr(_l5625, _h5625, _t5625.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:550"); (hsl){ _t5625.p + _l5625 * (int64_t)sizeof(uint8_t), _h5625 - _l5625 }; }), sc_1745));
(void)(f301_hh(hr_str("} ", 2)));
 }
}
static hsl f311_ar_op(int64_t o_1747) {
if ((((o_1747) == (((int64_t)21LL))) || ((o_1747) == (((int64_t)26LL))))) { return hr_str("+", 1);
 }
if ((((o_1747) == (((int64_t)22LL))) || ((o_1747) == (((int64_t)27LL))))) { return hr_str("-", 1);
 }
if ((((o_1747) == (((int64_t)23LL))) || ((o_1747) == (((int64_t)28LL))))) { return hr_str("*", 1);
 }
if ((((o_1747) == (((int64_t)24LL))) || ((o_1747) == (((int64_t)29LL))))) { return hr_str("/", 1);
 }
if ((((o_1747) == (((int64_t)25LL))) || ((o_1747) == (((int64_t)30LL))))) { return hr_str("%", 1);
 }
if ((((o_1747) == (((int64_t)49LL))) || ((o_1747) == (((int64_t)31LL))))) { return hr_str("&", 1);
 }
if ((((o_1747) == (((int64_t)50LL))) || ((o_1747) == (((int64_t)32LL))))) { return hr_str("|", 1);
 }
if ((((o_1747) == (((int64_t)51LL))) || ((o_1747) == (((int64_t)33LL))))) { return hr_str("^", 1);
 }
if ((((o_1747) == (((int64_t)43LL))) || ((o_1747) == (((int64_t)45LL))))) { return hr_str("<<", 2);
 }
if ((((o_1747) == (((int64_t)44LL))) || ((o_1747) == (((int64_t)46LL))))) { return hr_str(">>", 2);
 }
return hr_str("\077", 1);
}
static void f312_wloc(int64_t n_1761) {
S3 x_1762 = (*({ hrv *_t5628 = &(g913); int64_t _i5628 = ((*({ hrv *_t5629 = &(g703); int64_t _i5629 = f103_max(n_1761, ((int64_t)0LL)); (S4*)_t5629->b + hr_ix(_i5629, _t5629->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:100"); }))).t_; (S3*)_t5628->b + hr_ix(_i5628, _t5628->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:100"); })); 
(void)(f260_ow(hr_str("\"", 1)));
{ hsl _v5633 = f10_nm(((int64_t)(((*({ hrv *_t5635 = &(g912); int64_t _i5635 = (x_1762).f_; (S2*)_t5635->b + hr_ix(_i5635, _t5635->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:100"); }))).name_))); for (int64_t _k5633 = 0; _k5633 < _v5633.n; _k5633++) { uint8_t c_1763 = ((uint8_t*)_v5633.p)[_k5633]; if ((((c_1763) == (((uint8_t)34LL))) || ((c_1763) == (((uint8_t)92LL))))) { (void)(({ hrv *_v5636 = &(g163); uint8_t _x5636 = ((uint8_t)92LL); uint8_t *_p5636 = (uint8_t*)hr_grow(_v5636, 1, sizeof _x5636); *_p5636 = _x5636; _p5636; }));
 }
(void)(({ hrv *_v5637 = &(g163); uint8_t _x5637 = c_1763; uint8_t *_p5637 = (uint8_t*)hr_grow(_v5637, 1, sizeof _x5637); *_p5637 = _x5637; _p5637; }));
 } } _bk5632:; 
(void)(({ hrv *_o5638 = &(g163); hr_fs(_o5638, hr_str(":", 1)); hr_fi(_o5638, (x_1762).line_); hr_fs(_o5638, hr_str("\"", 1)); }));
}
static void f313_gun(int64_t n_1764) {
S4 x_1765 = (*({ hrv *_t5639 = &(g703); int64_t _i5639 = n_1764; (S4*)_t5639->b + hr_ix(_i5639, _t5639->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:272"); })); 
int64_t o_1766 = ((int64_t)((x_1765).op_)); 
int64_t a_1767 = ((int64_t)((x_1765).a_)); 
if (((o_1766) == (((int64_t)47LL)))) { (void)(f260_ow(hr_str("(!(", 3)));
(void)(f289_gx(a_1767));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (((o_1766) == (((int64_t)49LL)))) { (void)(f289_gx(a_1767));
return;
 }
int64_t t_1768 = f279_fin(n_1764); 
if (((o_1766) == (((int64_t)22LL)))) { if (((((*({ hrv *_t5645 = &(g550); int64_t _i5645 = t_1768; (S1*)_t5645->b + hr_ix(_i5645, _t5645->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:276"); }))).k_) == (((uint8_t)4LL)))) { (void)(f260_ow(hr_str("(-(", 3)));
(void)(f289_gx(a_1767));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (((f180_leaf_kind(t_1768)) >= (((int64_t)4LL)))) { (void)(f260_ow(hr_str("hneg", 4)));
(void)(f294_oi(t_1768));
(void)(f260_ow(hr_str("(", 1)));
(void)(f289_gx(a_1767));
(void)(f260_ow(hr_str(")", 1)));
(void)(f314_gen_hneg(t_1768));
return;
 }
(void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1768));
(void)(f260_ow(hr_str(")(0 - (uint64_t)(", 17)));
(void)(f289_gx(a_1767));
(void)(f260_ow(hr_str(")))", 3)));
return;
 }
if (((o_1766) == (((int64_t)48LL)))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1768));
(void)(f260_ow(hr_str(")~(", 3)));
(void)(f289_gx(a_1767));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (((o_1766) == (((int64_t)23LL)))) { (void)(f260_ow(hr_str("(*", 2)));
(void)(f289_gx(a_1767));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((o_1766) == (((int64_t)21LL)))) { (void)(f289_gx(a_1767));
return;
 }
(void)(f287_gerr(n_1764, hr_str("unsupported unary operator", 26)));
}
static void f314_gen_hneg(int64_t t_1769) {
{ hrv *_v5672 = &(g243); for (int64_t _k5672 = 0; _k5672 < _v5672->n; _k5672++) { int32_t h_1770 = ((int32_t*)_v5672->b)[_k5672]; if (((((int64_t)(h_1770))) == (t_1769))) { return;
 }
 } } _bk5671:; 
(void)(({ hrv *_v5673 = &(g243); int32_t _x5673 = ((int32_t)(t_1769)); int32_t *_p5673 = (int32_t*)hr_grow(_v5673, 1, sizeof _x5673); *_p5673 = _x5673; _p5673; }));
(void)(f262_cbody(t_1769));
L97 sig_1771 = ({ L97 _t5675; memset(&_t5675, 0, sizeof _t5675); _t5675.n = 0; _t5675; }); 
(void)(({ L97 *_l5676 = &(sig_1771); hrv _o5676 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5676, hr_str("static ", 7)); if (_l5676->n + _o5676.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:560"); memcpy(_l5676->e + _l5676->n, _o5676.b, (size_t)_o5676.n); _l5676->n += _o5676.n; }));
(void)(({ L97 *_v5677 = &(sig_1771); hsl _s5677 = f264_cn(t_1769); if (_v5677->n + _s5677.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:560"); memmove(_v5677->e + _v5677->n, _s5677.p, (size_t)_s5677.n * sizeof _v5677->e[0]); _v5677->n += _s5677.n; }));
(void)(({ L97 *_l5679 = &(sig_1771); hrv _o5679 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5679, hr_str(" hneg", 5)); hr_fi(&_o5679, t_1769); hr_fs(&_o5679, hr_str("(", 1)); if (_l5679->n + _o5679.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:560"); memcpy(_l5679->e + _l5679->n, _o5679.b, (size_t)_o5679.n); _l5679->n += _o5679.n; }));
(void)(({ L97 *_v5680 = &(sig_1771); hsl _s5680 = f264_cn(t_1769); if (_v5680->n + _s5680.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:560"); memmove(_v5680->e + _v5680->n, _s5680.p, (size_t)_s5680.n * sizeof _v5680->e[0]); _v5680->n += _s5680.n; }));
(void)(({ L97 *_v5682 = &(sig_1771); hsl _s5682 = hr_str(" a)", 3); if (_v5682->n + _s5682.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:560"); memmove(_v5682->e + _v5682->n, _s5682.p, (size_t)_s5682.n * sizeof _v5682->e[0]); _v5682->n += _s5682.n; }));
(void)(({ hrv *_v5683 = &(g166); hsl _s5683 = ({ hsl _t5684 = ({ L97 *_t5685 = &(sig_1771); (hsl){ (uint8_t*)_t5685->e, _t5685->n }; }); int64_t _l5684 = 0, _h5684 = _t5684.n; if (_l5684 < 0 || _h5684 < _l5684 || _h5684 > _t5684.n) hr_slerr(_l5684, _h5684, _t5684.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:561"); (hsl){ _t5684.p + _l5684 * (int64_t)sizeof(uint8_t), _h5684 - _l5684 }; }); hr_append(_v5683, _s5683.p, _s5683.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5686 = &(g166); hsl _s5686 = hr_str(";\012", 2); hr_append(_v5686, _s5686.p, _s5686.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5687 = &(g169); hsl _s5687 = ({ hsl _t5688 = ({ L97 *_t5689 = &(sig_1771); (hsl){ (uint8_t*)_t5689->e, _t5689->n }; }); int64_t _l5688 = 0, _h5688 = _t5688.n; if (_l5688 < 0 || _h5688 < _l5688 || _h5688 > _t5688.n) hr_slerr(_l5688, _h5688, _t5688.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:562"); (hsl){ _t5688.p + _l5688 * (int64_t)sizeof(uint8_t), _h5688 - _l5688 }; }); hr_append(_v5687, _s5687.p, _s5687.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" { ", 3)));
(void)(({ hrv *_v5691 = &(g169); hsl _s5691 = f264_cn(t_1769); hr_append(_v5691, _s5691.p, _s5691.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" z; memset(&z, 0, sizeof z); ", 29)));
(void)(({ hrv *_v5694 = &(g169); hsl _s5694 = f264_cn(t_1769); hr_append(_v5694, _s5694.p, _s5694.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" r; ", 4)));
(void)(f310_hop_body(t_1769, ((int64_t)22LL), hr_str("r", 1), hr_str("z", 1), hr_str("a", 1), false));
(void)(f301_hh(hr_str("return r; }\012", 12)));
}
static void f315_gidx(int64_t n_1783) {
S4 x_1784 = (*({ hrv *_t5699 = &(g703); int64_t _i5699 = n_1783; (S4*)_t5699->b + hr_ix(_i5699, _t5699->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:283"); })); 
int64_t a_1785 = ((int64_t)((x_1784).a_)); 
int64_t bt_1786 = f141_at(a_1785); 
int64_t d_1787 = f179_deref(bt_1786); 
int64_t e_1788 = ((int64_t)(((*({ hrv *_t5702 = &(g550); int64_t _i5702 = d_1787; (S1*)_t5702->b + hr_ix(_i5702, _t5702->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:287"); }))).a_)); 
int64_t p_1789 = f293_nt(); 
if ((f282_is_fix(d_1787) && ((((*({ hrv *_t5705 = &(g550); int64_t _i5705 = bt_1786; (S1*)_t5705->b + hr_ix(_i5705, _t5705->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:289"); }))).k_) != (((uint8_t)10LL))))) { (void)(f260_ow(hr_str("(", 1)));
(void)(f289_gx(a_1785));
(void)(f260_ow(hr_str(").e[hr_ix(", 10)));
(void)(f289_gx(((int64_t)((x_1784).b_))));
(void)(({ hrv *_o5710 = &(g163); hr_fs(_o5710, hr_str(", ", 2)); hr_fi(_o5710, ((*({ hrv *_t5711 = &(g550); int64_t _i5711 = d_1787; (S1*)_t5711->b + hr_ix(_i5711, _t5711->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:290"); }))).b_); hr_fs(_o5710, hr_str(", ", 2)); }));
(void)(f312_wloc(n_1783));
(void)(f260_ow(hr_str(")]", 2)));
return;
 }
(void)(f260_ow(hr_str("(*({ ", 5)));
if (((((*({ hrv *_t5715 = &(g550); int64_t _i5715 = d_1787; (S1*)_t5715->b + hr_ix(_i5715, _t5715->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:293"); }))).k_) == (((uint8_t)9LL)))) { (void)(f260_ow(hr_str("hsl _t", 6)));
(void)(f294_oi(p_1789));
(void)(f260_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t5719 = &(g550); int64_t _i5719 = bt_1786; (S1*)_t5719->b + hr_ix(_i5719, _t5719->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:293"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_ow(hr_str("*", 1)));
(void)(f275_gx0(a_1785));
 } else { (void)(f289_gx(a_1785));
 }
(void)(f260_ow(hr_str("; int64_t _i", 12)));
(void)(f294_oi(p_1789));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1784).b_))));
(void)(f260_ow(hr_str("; (", 3)));
(void)(f261_ct(e_1788));
(void)(f260_ow(hr_str("*)_t", 4)));
(void)(f294_oi(p_1789));
(void)(({ hrv *_o5731 = &(g163); hr_fs(_o5731, hr_str(".p + hr_ix(_i", 13)); hr_fi(_o5731, p_1789); hr_fs(_o5731, hr_str(", _t", 4)); hr_fi(_o5731, p_1789); hr_fs(_o5731, hr_str(".n, ", 4)); }));
(void)(f312_wloc(n_1783));
(void)(f260_ow(hr_str("); }))", 6)));
return;
 }
(void)(f261_ct(d_1787));
(void)(f260_ow(hr_str(" *_t", 4)));
(void)(f294_oi(p_1789));
(void)(f260_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t5738 = &(g550); int64_t _i5738 = bt_1786; (S1*)_t5738->b + hr_ix(_i5738, _t5738->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:295"); }))).k_) == (((uint8_t)10LL)))) { (void)(f275_gx0(a_1785));
 } else { if (f272_is_place(a_1785)) { (void)(f260_ow(hr_str("&(", 2)));
(void)(f289_gx(a_1785));
(void)(f260_ow(hr_str(")", 1)));
 } else { int64_t k_1790 = f273_tmp(d_1787, f268_is_res(d_1787)); 
(void)(f260_ow(hr_str("(", 1)));
(void)(f274_ot(k_1790));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f269_gxo(a_1785));
(void)(f260_ow(hr_str(", &", 3)));
(void)(f274_ot(k_1790));
(void)(f260_ow(hr_str(")", 1)));
 }
 }
(void)(f260_ow(hr_str("; int64_t _i", 12)));
(void)(f294_oi(p_1789));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1784).b_))));
(void)(f260_ow(hr_str("; ", 2)));
if (f268_is_res(d_1787)) { (void)(f260_ow(hr_str("(", 1)));
(void)(f261_ct(e_1788));
(void)(f260_ow(hr_str("*)_t", 4)));
(void)(f294_oi(p_1789));
(void)(({ hrv *_o5763 = &(g163); hr_fs(_o5763, hr_str("->b + hr_ix(_i", 14)); hr_fi(_o5763, p_1789); hr_fs(_o5763, hr_str(", _t", 4)); hr_fi(_o5763, p_1789); hr_fs(_o5763, hr_str("->n, ", 5)); }));
(void)(f312_wloc(n_1783));
(void)(f260_ow(hr_str("); }))", 6)));
return;
 }
if (f282_is_fix(d_1787)) { (void)(({ hrv *_o5767 = &(g163); hr_fs(_o5767, hr_str("_t", 2)); hr_fi(_o5767, p_1789); hr_fs(_o5767, hr_str("->e + hr_ix(_i", 14)); hr_fi(_o5767, p_1789); hr_fs(_o5767, hr_str(", ", 2)); hr_fi(_o5767, ((*({ hrv *_t5768 = &(g550); int64_t _i5768 = d_1787; (S1*)_t5768->b + hr_ix(_i5768, _t5768->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:298"); }))).b_); hr_fs(_o5767, hr_str(", ", 2)); }));
(void)(f312_wloc(n_1783));
(void)(f260_ow(hr_str("); }))", 6)));
return;
 }
(void)(({ hrv *_o5771 = &(g163); hr_fs(_o5771, hr_str("_t", 2)); hr_fi(_o5771, p_1789); hr_fs(_o5771, hr_str("->e + hr_ix(_i", 14)); hr_fi(_o5771, p_1789); hr_fs(_o5771, hr_str(", _t", 4)); hr_fi(_o5771, p_1789); hr_fs(_o5771, hr_str("->n, ", 5)); }));
(void)(f312_wloc(n_1783));
(void)(f260_ow(hr_str("); }))", 6)));
}
static void f316_gslice(int64_t n_1791) {
S4 x_1792 = (*({ hrv *_t5774 = &(g703); int64_t _i5774 = n_1791; (S4*)_t5774->b + hr_ix(_i5774, _t5774->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:302"); })); 
int64_t a_1793 = ((int64_t)((x_1792).a_)); 
int64_t d_1794 = f179_deref(f141_at(a_1793)); 
int64_t e_1795 = ((int64_t)(((*({ hrv *_t5777 = &(g550); int64_t _i5777 = d_1794; (S1*)_t5777->b + hr_ix(_i5777, _t5777->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:305"); }))).a_)); 
int64_t p_1796 = f293_nt(); 
(void)(f260_ow(hr_str("({ hsl _t", 9)));
(void)(f294_oi(p_1796));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f292_gsl(a_1793, f141_at(a_1793)));
(void)(f260_ow(hr_str("; int64_t _l", 12)));
(void)(f294_oi(p_1796));
(void)(f260_ow(hr_str(" = ", 3)));
if ((((x_1792).b_) >= (((int32_t)0LL)))) { if (((((uint16_t)((uint64_t)(x_1792).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_o5787 = &(g163); hr_fs(_o5787, hr_str("_t", 2)); hr_fi(_o5787, p_1796); hr_fs(_o5787, hr_str(".n - ", 5)); }));
 }
(void)(f289_gx(((int64_t)((x_1792).b_))));
 } else { (void)(f260_ow(hr_str("0", 1)));
 }
(void)(f260_ow(hr_str(", _h", 4)));
(void)(f294_oi(p_1796));
(void)(f260_ow(hr_str(" = ", 3)));
if ((((x_1792).c_) >= (((int32_t)0LL)))) { if (((((uint16_t)((uint64_t)(x_1792).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_o5793 = &(g163); hr_fs(_o5793, hr_str("_t", 2)); hr_fi(_o5793, p_1796); hr_fs(_o5793, hr_str(".n - ", 5)); }));
 }
(void)(f289_gx(((int64_t)((x_1792).c_))));
 } else { (void)(({ hrv *_o5795 = &(g163); hr_fs(_o5795, hr_str("_t", 2)); hr_fi(_o5795, p_1796); hr_fs(_o5795, hr_str(".n", 2)); }));
 }
(void)(({ hrv *_o5796 = &(g163); hr_fs(_o5796, hr_str("; if (_l", 8)); hr_fi(_o5796, p_1796); hr_fs(_o5796, hr_str(" < 0 || _h", 10)); hr_fi(_o5796, p_1796); hr_fs(_o5796, hr_str(" < _l", 5)); hr_fi(_o5796, p_1796); hr_fs(_o5796, hr_str(" || _h", 6)); hr_fi(_o5796, p_1796); hr_fs(_o5796, hr_str(" > _t", 5)); hr_fi(_o5796, p_1796); hr_fs(_o5796, hr_str(".n) hr_slerr(_l", 15)); hr_fi(_o5796, p_1796); hr_fs(_o5796, hr_str(", _h", 4)); hr_fi(_o5796, p_1796); hr_fs(_o5796, hr_str(", _t", 4)); hr_fi(_o5796, p_1796); hr_fs(_o5796, hr_str(".n, ", 4)); }));
(void)(f312_wloc(n_1791));
(void)(({ hrv *_o5798 = &(g163); hr_fs(_o5798, hr_str("); (hsl){ _t", 12)); hr_fi(_o5798, p_1796); hr_fs(_o5798, hr_str(".p + _l", 7)); hr_fi(_o5798, p_1796); hr_fs(_o5798, hr_str(" * (int64_t)sizeof(", 19)); }));
(void)(f261_ct(e_1795));
(void)(({ hrv *_o5800 = &(g163); hr_fs(_o5800, hr_str("), _h", 5)); hr_fi(_o5800, p_1796); hr_fs(_o5800, hr_str(" - _l", 5)); hr_fi(_o5800, p_1796); hr_fs(_o5800, hr_str(" }; })", 6)); }));
}
static void f317_garr(int64_t n_1799) {
S4 x_1800 = (*({ hrv *_t5801 = &(g703); int64_t _i5801 = n_1799; (S4*)_t5801->b + hr_ix(_i5801, _t5801->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:315"); })); 
int64_t t_1801 = f141_at(n_1799); 
int64_t e_1802 = ((int64_t)(((*({ hrv *_t5803 = &(g550); int64_t _i5803 = t_1801; (S1*)_t5803->b + hr_ix(_i5803, _t5803->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:317"); }))).a_)); 
int64_t p_1803 = f293_nt(); 
if (f268_is_res(t_1801)) { if (((((x_1800).n_) == (((int32_t)0LL))) && (((x_1800).a_) < (((int32_t)0LL))))) { (void)(f260_ow(hr_str("((hrv){0})", 10)));
return;
 }
(void)(f260_ow(hr_str("({ hrv _t", 9)));
(void)(f294_oi(p_1803));
(void)(f260_ow(hr_str(" = {0}; ", 8)));
if ((((x_1800).a_) >= (((int32_t)0LL)))) { (void)(f260_ow(hr_str("int64_t _c", 10)));
(void)(f294_oi(p_1803));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1800).b_))));
(void)(f260_ow(hr_str("; ", 2)));
(void)(f261_ct(e_1802));
(void)(f260_ow(hr_str(" _v", 3)));
(void)(f294_oi(p_1803));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1800).a_))));
(void)(f260_ow(hr_str("; ", 2)));
(void)(f261_ct(e_1802));
(void)(f260_ow(hr_str(" *_p", 4)));
(void)(f294_oi(p_1803));
(void)(f260_ow(hr_str(" = (", 4)));
(void)(f261_ct(e_1802));
(void)(({ hrv *_o5826 = &(g163); hr_fs(_o5826, hr_str("*)hr_grow(&_t", 13)); hr_fi(_o5826, p_1803); hr_fs(_o5826, hr_str(", _c", 4)); hr_fi(_o5826, p_1803); hr_fs(_o5826, hr_str(", sizeof _v", 11)); hr_fi(_o5826, p_1803); hr_fs(_o5826, hr_str("); for (int64_t _k = 0; _k < _c", 31)); hr_fi(_o5826, p_1803); hr_fs(_o5826, hr_str("; _k++) _p", 10)); hr_fi(_o5826, p_1803); hr_fs(_o5826, hr_str("[_k] = _v", 9)); hr_fi(_o5826, p_1803); hr_fs(_o5826, hr_str("; ", 2)); }));
 } else { (void)(f261_ct(e_1802));
(void)(f260_ow(hr_str(" *_p", 4)));
(void)(f294_oi(p_1803));
(void)(f260_ow(hr_str(" = (", 4)));
(void)(f261_ct(e_1802));
(void)(({ hrv *_o5832 = &(g163); hr_fs(_o5832, hr_str("*)hr_grow(&_t", 13)); hr_fi(_o5832, p_1803); hr_fs(_o5832, hr_str(", ", 2)); hr_fi(_o5832, (x_1800).n_); hr_fs(_o5832, hr_str(", sizeof(", 9)); }));
(void)(f261_ct(e_1802));
(void)(f260_ow(hr_str(")); ", 4)));
{ int32_t _e5836 = (x_1800).n_; for (int32_t _k5836 = 0; _k5836 < _e5836; _k5836++) { int32_t i_1804 = (int32_t)_k5836; (void)(({ hrv *_o5837 = &(g163); hr_fs(_o5837, hr_str("_p", 2)); hr_fi(_o5837, p_1803); hr_fs(_o5837, hr_str("[", 1)); hr_fi(_o5837, i_1804); hr_fs(_o5837, hr_str("] = ", 4)); }));
(void)(f289_gx(f90_kid(n_1799, ((int64_t)(i_1804)))));
(void)(f260_ow(hr_str("; ", 2)));
 } } _bk5835:; 
 }
(void)(f260_ow(hr_str("_t", 2)));
(void)(f294_oi(p_1803));
(void)(f260_ow(hr_str("; })", 4)));
return;
 }
if ((f282_is_fix(t_1801) || f283_is_lim(t_1801))) { (void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(t_1801));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_1803));
(void)(f260_ow(hr_str("; ", 2)));
if ((((x_1800).a_) >= (((int32_t)0LL)))) { (void)(f261_ct(e_1802));
(void)(f260_ow(hr_str(" _v", 3)));
(void)(f294_oi(p_1803));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1800).a_))));
(void)(({ hrv *_o5856 = &(g163); hr_fs(_o5856, hr_str("; for (int64_t _k = 0; _k < ", 28)); hr_fi(_o5856, ({ int64_t _r5857; if (f282_is_fix(t_1801)) { _r5857 = ((*({ hrv *_t5859 = &(g550); int64_t _i5859 = t_1801; (S1*)_t5859->b + hr_ix(_i5859, _t5859->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:329"); }))).b_;  } else { _r5857 = ((int64_t)0LL);  } _r5857; })); hr_fs(_o5856, hr_str("; _k++) _t", 10)); hr_fi(_o5856, p_1803); hr_fs(_o5856, hr_str(".e[_k] = _v", 11)); hr_fi(_o5856, p_1803); hr_fs(_o5856, hr_str("; ", 2)); }));
if (f283_is_lim(t_1801)) { (void)(f260_ow(hr_str("int64_t _c", 10)));
(void)(f294_oi(p_1803));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1800).b_))));
(void)(({ hrv *_o5865 = &(g163); hr_fs(_o5865, hr_str("; for (int64_t _k = 0; _k < _c", 30)); hr_fi(_o5865, p_1803); hr_fs(_o5865, hr_str("; _k++) _t", 10)); hr_fi(_o5865, p_1803); hr_fs(_o5865, hr_str(".e[_k] = _v", 11)); hr_fi(_o5865, p_1803); hr_fs(_o5865, hr_str("; _t", 4)); hr_fi(_o5865, p_1803); hr_fs(_o5865, hr_str(".n = _c", 7)); hr_fi(_o5865, p_1803); hr_fs(_o5865, hr_str("; ", 2)); }));
 }
 } else { if (f283_is_lim(t_1801)) { (void)(({ hrv *_o5867 = &(g163); hr_fs(_o5867, hr_str("memset(&_t", 10)); hr_fi(_o5867, p_1803); hr_fs(_o5867, hr_str(", 0, sizeof _t", 14)); hr_fi(_o5867, p_1803); hr_fs(_o5867, hr_str("); _t", 5)); hr_fi(_o5867, p_1803); hr_fs(_o5867, hr_str(".n = ", 5)); hr_fi(_o5867, (x_1800).n_); hr_fs(_o5867, hr_str("; ", 2)); }));
 }
{ int32_t _e5869 = (x_1800).n_; for (int32_t _k5869 = 0; _k5869 < _e5869; _k5869++) { int32_t i_1805 = (int32_t)_k5869; (void)(({ hrv *_o5870 = &(g163); hr_fs(_o5870, hr_str("_t", 2)); hr_fi(_o5870, p_1803); hr_fs(_o5870, hr_str(".e[", 3)); hr_fi(_o5870, i_1805); hr_fs(_o5870, hr_str("] = ", 4)); }));
(void)(f289_gx(f90_kid(n_1799, ((int64_t)(i_1805)))));
(void)(f260_ow(hr_str("; ", 2)));
 } } _bk5868:; 
 }
(void)(f260_ow(hr_str("_t", 2)));
(void)(f294_oi(p_1803));
(void)(f260_ow(hr_str("; })", 4)));
return;
 }
(void)(f287_gerr(n_1799, hr_str("unsupported array literal type", 30)));
}
static void f318_gslit(int64_t n_1806) {
S4 x_1807 = (*({ hrv *_t5878 = &(g703); int64_t _i5878 = n_1806; (S4*)_t5878->b + hr_ix(_i5878, _t5878->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:346"); })); 
int64_t t_1808 = f141_at(n_1806); 
int64_t si_1809 = f157_rv(n_1806); 
int64_t f0_1810 = ((int64_t)(((*({ hrv *_t5881 = &(g553); int64_t _i5881 = si_1809; (S10*)_t5881->b + hr_ix(_i5881, _t5881->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:349"); }))).f0_)); 
(void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1808));
(void)(f260_ow(hr_str("){ ", 3)));
bool any_1811 = false; 
{ int32_t _e5886 = ((*({ hrv *_t5887 = &(g553); int64_t _i5887 = si_1809; (S10*)_t5887->b + hr_ix(_i5887, _t5887->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:352"); }))).fnum_; for (int32_t _k5886 = 0; _k5886 < _e5886; _k5886++) { int32_t j_1812 = (int32_t)_k5886; S11 f_1813 = (*({ hrv *_t5888 = &(g554); int64_t _i5888 = ((int64_t)((int64_t)f0_1810 + (int64_t)((int64_t)(j_1812)))); (S11*)_t5888->b + hr_ix(_i5888, _t5888->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:353"); })); 
if ((((f_1813).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t given_1814 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e5890 = (x_1807).n_; for (int32_t _k5890 = 0; _k5890 < _e5890; _k5890++) { int32_t i_1815 = (int32_t)_k5890; if (((f157_rv(f90_kid(n_1806, ((int64_t)(i_1815))))) == (((int64_t)(j_1812))))) { given_1814 = f90_kid(n_1806, ((int64_t)(i_1815)));
 }
 } } _bk5889:; 
if ((((given_1814) < (((int64_t)0LL))) && (((f_1813).def_) < (((int32_t)0LL))))) { continue;
 }
(void)(f260_ow(hr_str(".", 1)));
(void)(f267_fname_into((&(g163)), ((int64_t)((f_1813).name_))));
(void)(f260_ow(hr_str(" = ", 3)));
if (((given_1814) >= (((int64_t)0LL)))) { int64_t v_1816 = ((int64_t)(((*({ hrv *_t5897 = &(g703); int64_t _i5897 = given_1814; (S4*)_t5897->b + hr_ix(_i5897, _t5897->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:359"); }))).a_)); 
if (f268_is_res(((int64_t)((f_1813).ty_)))) { (void)(f269_gxo(v_1816));
 } else { (void)(f289_gx(v_1816));
 }
 } else { int64_t sa_1817 = g400; 
g400 = g402;
(void)(f289_gx(((int64_t)((f_1813).def_))));
g400 = sa_1817;
 }
(void)(f260_ow(hr_str(", ", 2)));
any_1811 = true;
 } } _bk5885:; 
if ((!(any_1811))) { (void)(f260_ow(hr_str("0", 1)));
 }
(void)(f260_ow(hr_str("})", 2)));
}
static void f319_gcall(int64_t n_1818) {
int64_t r_1819 = f156_rk(n_1818); 
if (((r_1819) == (((int64_t)4LL)))) { (void)(f320_gbuiltin(n_1818));
return;
 }
if (((r_1819) == (((int64_t)10LL)))) { (void)(f333_gblkcall(n_1818));
return;
 }
if (((r_1819) != (((int64_t)3LL)))) { (void)(f287_gerr(n_1818, hr_str("unsupported call", 16)));
return;
 }
int64_t inst_2032 = f157_rv(n_1818); 
int64_t recv_2033 = ({ int64_t _r5910; if ((((f217_ax(n_1818)) == (((int64_t)1LL))) && ((((*({ hrv *_t5912 = &(g703); int64_t _i5912 = ((*({ hrv *_t5913 = &(g703); int64_t _i5913 = n_1818; (S4*)_t5913->b + hr_ix(_i5913, _t5913->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:607"); }))).a_; (S4*)_t5912->b + hr_ix(_i5912, _t5912->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:607"); }))).k_) == (((uint8_t)14LL))))) { _r5910 = ((int64_t)(((*({ hrv *_t5914 = &(g703); int64_t _i5914 = ((*({ hrv *_t5915 = &(g703); int64_t _i5915 = n_1818; (S4*)_t5915->b + hr_ix(_i5915, _t5915->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:607"); }))).a_; (S4*)_t5914->b + hr_ix(_i5914, _t5914->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:607"); }))).a_));  } else { _r5910 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r5910; }); 
bool lrw_2035 = ((!(f356_is_ext(inst_2032))) && ((*({ hrv *_t5917 = &(g387); int64_t _i5917 = inst_2032; (S6*)_t5917->b + hr_ix(_i5917, _t5917->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:608"); }))).lr_); 
int64_t rt_2036 = ((int64_t)(((*({ hrv *_t5918 = &(g387); int64_t _i5918 = inst_2032; (S6*)_t5918->b + hr_ix(_i5918, _t5918->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:609"); }))).ret_)); 
bool vd_2037 = (((rt_2036) < (((int64_t)0LL))) || ((rt_2036) == (g557))); 
int64_t q_2038 = f293_nt(); 
if (lrw_2035) { (void)(f260_ow(hr_str("({ ", 3)));
if ((!(vd_2037))) { (void)(f261_ct(rt_2036));
(void)(({ hrv *_o5922 = &(g163); hr_fs(_o5922, hr_str(" _c", 3)); hr_fi(_o5922, q_2038); hr_fs(_o5922, hr_str(" = ", 3)); }));
 }
 }
if (f356_is_ext(inst_2032)) { (void)(f357_ext_name(inst_2032));
 } else { (void)(f323_fn_cname(inst_2032));
 }
(void)(f260_ow(hr_str("(", 1)));
(void)(f358_gcall_args(n_1818, inst_2032, recv_2033));
(void)(f260_ow(hr_str(")", 1)));
if (lrw_2035) { (void)(f260_ow(hr_str("; ", 2)));
(void)(f360_glrcheck());
if ((!(vd_2037))) { (void)(({ hrv *_o5931 = &(g163); hr_fs(_o5931, hr_str("_c", 2)); hr_fi(_o5931, q_2038); hr_fs(_o5931, hr_str("; ", 2)); }));
 }
(void)(f260_ow(hr_str("})", 2)));
 }
}
static void f320_gbuiltin(int64_t n_1820) {
S4 x_1821 = (*({ hrv *_t5933 = &(g703); int64_t _i5933 = n_1820; (S4*)_t5933->b + hr_ix(_i5933, _t5933->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:646"); })); 
int64_t b_1822 = f157_rv(n_1820); 
bool hasr_1823 = ((f217_ax(n_1820)) == (((int64_t)1LL))); 
int64_t recv_1824 = ({ int64_t _r5936; if (hasr_1823) { _r5936 = ((int64_t)(((*({ hrv *_t5937 = &(g703); int64_t _i5937 = (x_1821).a_; (S4*)_t5937->b + hr_ix(_i5937, _t5937->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:649"); }))).a_));  } else { _r5936 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r5936; }); 
int64_t total_1825 = ((int64_t)((int64_t)((int64_t)((x_1821).n_)) + (int64_t)({ int64_t _r5938; if (hasr_1823) { _r5938 = ((int64_t)1LL);  } else { _r5938 = ((int64_t)0LL);  } _r5938; }))); 

int64_t p_1827 = f293_nt(); 
if (((b_1822) == (((int64_t)1LL)))) { (void)(f260_ow(hr_str("({ ", 3)));
{ int32_t _e5942 = (x_1821).n_; for (int32_t _k5942 = 0; _k5942 < _e5942; _k5942++) { int32_t i_1828 = (int32_t)_k5942; int64_t c_1829 = f90_kid(n_1820, ((int64_t)(i_1828))); 
(void)(f322_gfmt(hr_str("&hr_ob", 6), c_1829, f279_fin(c_1829), true));
(void)(f260_ow(hr_str("; ", 2)));
 } } _bk5941:; 
(void)(f260_ow(hr_str("hr_println(); })", 16)));
return;
 }
if (((b_1822) == (((int64_t)2LL)))) { (void)(f260_ow(hr_str("({ hrv _o", 9)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" = {0}; ", 8)));
L99 nmo_1842 = ({ L99 _t5951; memset(&_t5951, 0, sizeof _t5951); _t5951.n = 0; _t5951; }); 
(void)(({ L99 *_l5952 = &(nmo_1842); hrv _o5952 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5952, hr_str("&_o", 3)); hr_fi(&_o5952, p_1827); if (_l5952->n + _o5952.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:654"); memcpy(_l5952->e + _l5952->n, _o5952.b, (size_t)_o5952.n); _l5952->n += _o5952.n; }));
{ int32_t _e5954 = (x_1821).n_; for (int32_t _k5954 = 0; _k5954 < _e5954; _k5954++) { int32_t i_1843 = (int32_t)_k5954; int64_t c_1844 = f90_kid(n_1820, ((int64_t)(i_1843))); 
(void)(f322_gfmt(({ hsl _t5957 = ({ L99 *_t5958 = &(nmo_1842); (hsl){ (uint8_t*)_t5958->e, _t5958->n }; }); int64_t _l5957 = 0, _h5957 = _t5957.n; if (_l5957 < 0 || _h5957 < _l5957 || _h5957 > _t5957.n) hr_slerr(_l5957, _h5957, _t5957.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:654"); (hsl){ _t5957.p + _l5957 * (int64_t)sizeof(uint8_t), _h5957 - _l5957 }; }), c_1844, f279_fin(c_1844), true));
(void)(f260_ow(hr_str("; ", 2)));
 } } _bk5953:; 
(void)(f260_ow(hr_str("_o", 2)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str("; })", 4)));
return;
 }
if ((((b_1822) == (((int64_t)3LL))) && f283_is_lim(f179_deref(f141_at(f321_arg(((int64_t)0LL), &recv_1824, &n_1820)))))) { int64_t lt_1845 = f179_deref(f141_at(f321_arg(((int64_t)0LL), &recv_1824, &n_1820))); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(lt_1845));
(void)(f260_ow(hr_str(" *_l", 4)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f325_grecv_ptr(f321_arg(((int64_t)0LL), &recv_1824, &n_1820)));
(void)(f260_ow(hr_str("; hrv _o", 8)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" __attribute__((cleanup(hr_rdrop))) = {0}; ", 43)));
L99 nmo_1849 = ({ L99 _t5981; memset(&_t5981, 0, sizeof _t5981); _t5981.n = 0; _t5981; }); 
(void)(({ L99 *_l5982 = &(nmo_1849); hrv _o5982 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5982, hr_str("&_o", 3)); hr_fi(&_o5982, p_1827); if (_l5982->n + _o5982.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:658"); memcpy(_l5982->e + _l5982->n, _o5982.b, (size_t)_o5982.n); _l5982->n += _o5982.n; }));
{ int64_t _e5984 = total_1825; for (int64_t _k5984 = ((int64_t)1LL); _k5984 < _e5984; _k5984++) { int64_t i_1850 = (int64_t)_k5984; int64_t c_1851 = f321_arg(i_1850, &recv_1824, &n_1820); 
(void)(f322_gfmt(({ hsl _t5987 = ({ L99 *_t5988 = &(nmo_1849); (hsl){ (uint8_t*)_t5988->e, _t5988->n }; }); int64_t _l5987 = 0, _h5987 = _t5987.n; if (_l5987 < 0 || _h5987 < _l5987 || _h5987 > _t5987.n) hr_slerr(_l5987, _h5987, _t5987.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:659"); (hsl){ _t5987.p + _l5987 * (int64_t)sizeof(uint8_t), _h5987 - _l5987 }; }), c_1851, f279_fin(c_1851), true));
(void)(f260_ow(hr_str("; ", 2)));
 } } _bk5983:; 
(void)(({ hrv *_o5991 = &(g163); hr_fs(_o5991, hr_str("if (_l", 6)); hr_fi(_o5991, p_1827); hr_fs(_o5991, hr_str("->n + _o", 8)); hr_fi(_o5991, p_1827); hr_fs(_o5991, hr_str(".n > ", 5)); hr_fi(_o5991, ((*({ hrv *_t5992 = &(g550); int64_t _i5992 = lt_1845; (S1*)_t5992->b + hr_ix(_i5992, _t5992->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:660"); }))).b_); hr_fs(_o5991, hr_str(") hr_die(\"format past a limited array's capacity\", ", 51)); }));
(void)(f312_wloc(n_1820));
(void)(({ hrv *_o5994 = &(g163); hr_fs(_o5994, hr_str("); memcpy(_l", 12)); hr_fi(_o5994, p_1827); hr_fs(_o5994, hr_str("->e + _l", 8)); hr_fi(_o5994, p_1827); hr_fs(_o5994, hr_str("->n, _o", 7)); hr_fi(_o5994, p_1827); hr_fs(_o5994, hr_str(".b, (size_t)_o", 14)); hr_fi(_o5994, p_1827); hr_fs(_o5994, hr_str(".n); _l", 7)); hr_fi(_o5994, p_1827); hr_fs(_o5994, hr_str("->n += _o", 9)); hr_fi(_o5994, p_1827); hr_fs(_o5994, hr_str(".n; })", 6)); }));
return;
 }
if (((b_1822) == (((int64_t)3LL)))) { (void)(f260_ow(hr_str("({ hrv *_o", 10)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f325_grecv_ptr(f321_arg(((int64_t)0LL), &recv_1824, &n_1820)));
(void)(f260_ow(hr_str("; ", 2)));
L99 nmo_1852 = ({ L99 _t6001; memset(&_t6001, 0, sizeof _t6001); _t6001.n = 0; _t6001; }); 
(void)(({ L99 *_l6002 = &(nmo_1852); hrv _o6002 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6002, hr_str("_o", 2)); hr_fi(&_o6002, p_1827); if (_l6002->n + _o6002.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:663"); memcpy(_l6002->e + _l6002->n, _o6002.b, (size_t)_o6002.n); _l6002->n += _o6002.n; }));
{ int64_t _e6004 = total_1825; for (int64_t _k6004 = ((int64_t)1LL); _k6004 < _e6004; _k6004++) { int64_t i_1853 = (int64_t)_k6004; int64_t c_1854 = f321_arg(i_1853, &recv_1824, &n_1820); 
(void)(f322_gfmt(({ hsl _t6007 = ({ L99 *_t6008 = &(nmo_1852); (hsl){ (uint8_t*)_t6008->e, _t6008->n }; }); int64_t _l6007 = 0, _h6007 = _t6007.n; if (_l6007 < 0 || _h6007 < _l6007 || _h6007 > _t6007.n) hr_slerr(_l6007, _h6007, _t6007.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:663"); (hsl){ _t6007.p + _l6007 * (int64_t)sizeof(uint8_t), _h6007 - _l6007 }; }), c_1854, f279_fin(c_1854), true));
(void)(f260_ow(hr_str("; ", 2)));
 } } _bk6003:; 
(void)(f260_ow(hr_str("})", 2)));
return;
 }
if (((b_1822) == (((int64_t)4LL)))) { (void)(f260_ow(hr_str("({ if (!(", 9)));
(void)(f289_gx(f321_arg(((int64_t)0LL), &recv_1824, &n_1820)));
(void)(f260_ow(hr_str(")) hr_assert_fail(", 18)));
(void)(f312_wloc(n_1820));
(void)(f260_ow(hr_str("); })", 5)));
return;
 }
if (((b_1822) == (((int64_t)5LL)))) { (void)(f260_ow(hr_str("hr_abort(", 9)));
(void)(f291_gas(f321_arg(((int64_t)0LL), &recv_1824, &n_1820)));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((b_1822) == (((int64_t)6LL)))) { (void)(f260_ow(hr_str("hr_exit(", 8)));
(void)(f289_gx(f321_arg(((int64_t)0LL), &recv_1824, &n_1820)));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((b_1822) == (((int64_t)8LL)))) { int64_t t_1855 = f141_at(n_1820); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(t_1855));
(void)(f260_ow(hr_str(" _d", 3)));
(void)(f294_oi(p_1827));
(void)(({ hrv *_o6031 = &(g163); hr_fs(_o6031, hr_str("; memset(&_d", 12)); hr_fi(_o6031, p_1827); hr_fs(_o6031, hr_str(", 0, sizeof _d", 14)); hr_fi(_o6031, p_1827); hr_fs(_o6031, hr_str("); _d", 5)); hr_fi(_o6031, p_1827); hr_fs(_o6031, hr_str("; })", 4)); }));
return;
 }
if (((b_1822) == (((int64_t)9LL)))) { int64_t c_1856 = f321_arg(((int64_t)0LL), &recv_1824, &n_1820); 
int64_t t_1857 = f179_deref(f279_fin(c_1856)); 
if (f282_is_fix(t_1857)) { (void)(({ hrv *_o6036 = &(g163); hr_fs(_o6036, hr_str("((int64_t)", 10)); hr_fi(_o6036, ((*({ hrv *_t6037 = &(g550); int64_t _i6037 = t_1857; (S1*)_t6037->b + hr_ix(_i6037, _t6037->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:668"); }))).b_); hr_fs(_o6036, hr_str(")", 1)); }));
return;
 }
(void)(f260_ow(hr_str("(", 1)));
(void)(f291_gas(c_1856));
(void)(f260_ow(hr_str(").n", 3)));
return;
 }
if (((b_1822) == (((int64_t)7LL)))) { int64_t c_1858 = f321_arg(((int64_t)0LL), &recv_1824, &n_1820); 
int64_t t_1859 = f179_deref(f279_fin(c_1858)); 
if ((((((*({ hrv *_t6044 = &(g550); int64_t _i6044 = t_1859; (S1*)_t6044->b + hr_ix(_i6044, _t6044->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:669"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t6045 = &(g550); int64_t _i6045 = t_1859; (S1*)_t6045->b + hr_ix(_i6045, _t6045->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:669"); }))).k_) == (((uint8_t)9LL))))) { (void)(f260_ow(hr_str("hr_rfrom(", 9)));
(void)(f291_gas(c_1858));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f326_esz(((int64_t)(((*({ hrv *_t6050 = &(g550); int64_t _i6050 = t_1859; (S1*)_t6050->b + hr_ix(_i6050, _t6050->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:669"); }))).a_))));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((f279_fin(c_1858)) != (t_1859))) { (void)(f260_ow(hr_str("(*", 2)));
(void)(f289_gx(c_1858));
(void)(f260_ow(hr_str(")", 1)));
 } else { (void)(f289_gx(c_1858));
 }
return;
 }
if (((b_1822) == (((int64_t)31LL)))) { int64_t c_1861 = f321_arg(((int64_t)0LL), &recv_1824, &n_1820); 
int64_t t_1862 = f179_deref(f279_fin(c_1861)); 
if ((((((*({ hrv *_t6060 = &(g550); int64_t _i6060 = t_1862; (S1*)_t6060->b + hr_ix(_i6060, _t6060->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:670"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t6061 = &(g550); int64_t _i6061 = t_1862; (S1*)_t6061->b + hr_ix(_i6061, _t6061->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:670"); }))).k_) == (((uint8_t)9LL))))) { int64_t q_1863 = f293_nt(); 
(void)(f260_ow(hr_str("({ hsl _s", 9)));
(void)(f294_oi(q_1863));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f291_gas(c_1861));
(void)(({ hrv *_o6067 = &(g163); hr_fs(_o6067, hr_str("; (hsl){ _s", 11)); hr_fi(_o6067, q_1863); hr_fs(_o6067, hr_str(".p, _s", 6)); hr_fi(_o6067, q_1863); hr_fs(_o6067, hr_str(".n * (int64_t)sizeof(", 21)); }));
(void)(f261_ct(((int64_t)(((*({ hrv *_t6069 = &(g550); int64_t _i6069 = t_1862; (S1*)_t6069->b + hr_ix(_i6069, _t6069->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:670"); }))).a_))));
(void)(f260_ow(hr_str(") }; })", 7)));
return;
 }
(void)(f260_ow(hr_str("((hsl){ (uint8_t*)", 18)));
(void)(f324_gaddr(c_1861));
(void)(f260_ow(hr_str(", sizeof(", 9)));
(void)(f261_ct(t_1862));
(void)(f260_ow(hr_str(") })", 4)));
return;
 }
if (((b_1822) == (((int64_t)30LL)))) { int64_t c_1864 = f321_arg(((int64_t)0LL), &recv_1824, &n_1820); 
int64_t t_1865 = f179_deref(f279_fin(c_1864)); 
(void)(f260_ow(hr_str("hr_rfrom(", 9)));
if ((((((*({ hrv *_t6080 = &(g550); int64_t _i6080 = t_1865; (S1*)_t6080->b + hr_ix(_i6080, _t6080->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:671"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t6081 = &(g550); int64_t _i6081 = t_1865; (S1*)_t6081->b + hr_ix(_i6081, _t6081->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:671"); }))).k_) == (((uint8_t)9LL))))) { int64_t q_1866 = f293_nt(); 
(void)(f260_ow(hr_str("({ hsl _s", 9)));
(void)(f294_oi(q_1866));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f291_gas(c_1864));
(void)(({ hrv *_o6087 = &(g163); hr_fs(_o6087, hr_str("; (hsl){ _s", 11)); hr_fi(_o6087, q_1866); hr_fs(_o6087, hr_str(".p, _s", 6)); hr_fi(_o6087, q_1866); hr_fs(_o6087, hr_str(".n * (int64_t)sizeof(", 21)); }));
(void)(f261_ct(((int64_t)(((*({ hrv *_t6089 = &(g550); int64_t _i6089 = t_1865; (S1*)_t6089->b + hr_ix(_i6089, _t6089->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:671"); }))).a_))));
(void)(f260_ow(hr_str(") }; })", 7)));
 } else { (void)(f260_ow(hr_str("((hsl){ (uint8_t*)", 18)));
(void)(f324_gaddr(c_1864));
(void)(f260_ow(hr_str(", sizeof(", 9)));
(void)(f261_ct(t_1865));
(void)(f260_ow(hr_str(") })", 4)));
 }
(void)(f260_ow(hr_str(", 1)", 4)));
return;
 }
if (((b_1822) == (((int64_t)32LL)))) { int64_t t_1867 = f141_at(n_1820); 
(void)(f260_ow(hr_str("({ hsl _s", 9)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f291_gas(f321_arg(((int64_t)0LL), &recv_1824, &n_1820)));
(void)(f260_ow(hr_str("; ", 2)));
(void)(f261_ct(t_1867));
(void)(({ hrv *_o6105 = &(g163); hr_fs(_o6105, hr_str(" _d", 3)); hr_fi(_o6105, p_1827); hr_fs(_o6105, hr_str("; if (_s", 8)); hr_fi(_o6105, p_1827); hr_fs(_o6105, hr_str(".n != sizeof _d", 15)); hr_fi(_o6105, p_1827); hr_fs(_o6105, hr_str(") hr_die(\"from_bytes: wrong byte count\", ", 41)); }));
(void)(f312_wloc(n_1820));
(void)(({ hrv *_o6107 = &(g163); hr_fs(_o6107, hr_str("); memcpy(&_d", 13)); hr_fi(_o6107, p_1827); hr_fs(_o6107, hr_str(", _s", 4)); hr_fi(_o6107, p_1827); hr_fs(_o6107, hr_str(".p, sizeof _d", 13)); hr_fi(_o6107, p_1827); hr_fs(_o6107, hr_str("); _d", 5)); hr_fi(_o6107, p_1827); hr_fs(_o6107, hr_str("; })", 4)); }));
return;
 }
int64_t rt_1868 = f179_deref(f141_at(recv_1824)); 
int64_t e_1869 = ((int64_t)(((*({ hrv *_t6110 = &(g550); int64_t _i6110 = rt_1868; (S1*)_t6110->b + hr_ix(_i6110, _t6110->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:674"); }))).a_)); 
if (f283_is_lim(rt_1868)) { (void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(rt_1868));
(void)(f260_ow(hr_str(" *_v", 4)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f325_grecv_ptr(recv_1824));
(void)(f260_ow(hr_str("; ", 2)));
if (((b_1822) == (((int64_t)20LL)))) { (void)(f261_ct(e_1869));
(void)(f260_ow(hr_str(" _x", 3)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1824, &n_1820)));
(void)(({ hrv *_o6125 = &(g163); hr_fs(_o6125, hr_str("; if (_v", 8)); hr_fi(_o6125, p_1827); hr_fs(_o6125, hr_str("->n >= ", 7)); hr_fi(_o6125, ((*({ hrv *_t6126 = &(g550); int64_t _i6126 = rt_1868; (S1*)_t6126->b + hr_ix(_i6126, _t6126->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:677"); }))).b_); hr_fs(_o6125, hr_str(") hr_die(\"push past a limited array's capacity\", ", 49)); }));
(void)(f312_wloc(n_1820));
(void)(({ hrv *_o6128 = &(g163); hr_fs(_o6128, hr_str("); _v", 5)); hr_fi(_o6128, p_1827); hr_fs(_o6128, hr_str("->e[_v", 6)); hr_fi(_o6128, p_1827); hr_fs(_o6128, hr_str("->n] = _x", 9)); hr_fi(_o6128, p_1827); hr_fs(_o6128, hr_str("; &_v", 5)); hr_fi(_o6128, p_1827); hr_fs(_o6128, hr_str("->e[_v", 6)); hr_fi(_o6128, p_1827); hr_fs(_o6128, hr_str("->n++]; })", 10)); }));
return;
 }
if (((b_1822) == (((int64_t)21LL)))) { (void)(({ hrv *_o6129 = &(g163); hr_fs(_o6129, hr_str("hsl _s", 6)); hr_fi(_o6129, p_1827); hr_fs(_o6129, hr_str(" = ", 3)); }));
(void)(f291_gas(f321_arg(((int64_t)1LL), &recv_1824, &n_1820)));
(void)(({ hrv *_o6132 = &(g163); hr_fs(_o6132, hr_str("; if (_v", 8)); hr_fi(_o6132, p_1827); hr_fs(_o6132, hr_str("->n + _s", 8)); hr_fi(_o6132, p_1827); hr_fs(_o6132, hr_str(".n > ", 5)); hr_fi(_o6132, ((*({ hrv *_t6133 = &(g550); int64_t _i6133 = rt_1868; (S1*)_t6133->b + hr_ix(_i6133, _t6133->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:678"); }))).b_); hr_fs(_o6132, hr_str(") hr_die(\"append past a limited array's capacity\", ", 51)); }));
(void)(f312_wloc(n_1820));
(void)(({ hrv *_o6135 = &(g163); hr_fs(_o6135, hr_str("); memmove(_v", 13)); hr_fi(_o6135, p_1827); hr_fs(_o6135, hr_str("->e + _v", 8)); hr_fi(_o6135, p_1827); hr_fs(_o6135, hr_str("->n, _s", 7)); hr_fi(_o6135, p_1827); hr_fs(_o6135, hr_str(".p, (size_t)_s", 14)); hr_fi(_o6135, p_1827); hr_fs(_o6135, hr_str(".n * sizeof _v", 14)); hr_fi(_o6135, p_1827); hr_fs(_o6135, hr_str("->e[0]); _v", 11)); hr_fi(_o6135, p_1827); hr_fs(_o6135, hr_str("->n += _s", 9)); hr_fi(_o6135, p_1827); hr_fs(_o6135, hr_str(".n; })", 6)); }));
return;
 }
if (((b_1822) == (((int64_t)22LL)))) { (void)(({ hrv *_o6136 = &(g163); hr_fs(_o6136, hr_str("if (!_v", 7)); hr_fi(_o6136, p_1827); hr_fs(_o6136, hr_str("->n) hr_die(\"pop of an empty array\", ", 37)); }));
(void)(f312_wloc(n_1820));
(void)(({ hrv *_o6138 = &(g163); hr_fs(_o6138, hr_str("); _v", 5)); hr_fi(_o6138, p_1827); hr_fs(_o6138, hr_str("->e[--_v", 8)); hr_fi(_o6138, p_1827); hr_fs(_o6138, hr_str("->n]; })", 8)); }));
return;
 }
if (((b_1822) == (((int64_t)23LL)))) { (void)(({ hrv *_o6139 = &(g163); hr_fs(_o6139, hr_str("int64_t _k", 10)); hr_fi(_o6139, p_1827); hr_fs(_o6139, hr_str(" = ", 3)); }));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1824, &n_1820)));
(void)(({ hrv *_o6142 = &(g163); hr_fs(_o6142, hr_str("; if (_k", 8)); hr_fi(_o6142, p_1827); hr_fs(_o6142, hr_str(" < 0 || _k", 10)); hr_fi(_o6142, p_1827); hr_fs(_o6142, hr_str(" > _v", 5)); hr_fi(_o6142, p_1827); hr_fs(_o6142, hr_str("->n) hr_die(\"pop_n past the length\", ", 37)); }));
(void)(f312_wloc(n_1820));
(void)(({ hrv *_o6144 = &(g163); hr_fs(_o6144, hr_str("); _v", 5)); hr_fi(_o6144, p_1827); hr_fs(_o6144, hr_str("->n -= _k", 9)); hr_fi(_o6144, p_1827); hr_fs(_o6144, hr_str("; })", 4)); }));
return;
 }
if (((b_1822) == (((int64_t)25LL)))) { (void)(({ hrv *_o6145 = &(g163); hr_fs(_o6145, hr_str("_v", 2)); hr_fi(_o6145, p_1827); hr_fs(_o6145, hr_str("->n = 0; })", 11)); }));
return;
 }
if (((b_1822) == (((int64_t)24LL)))) { (void)(({ hrv *_o6146 = &(g163); hr_fs(_o6146, hr_str("int64_t _k", 10)); hr_fi(_o6146, p_1827); hr_fs(_o6146, hr_str(" = ", 3)); }));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1824, &n_1820)));
(void)(({ hrv *_o6149 = &(g163); hr_fs(_o6149, hr_str("; if (_k", 8)); hr_fi(_o6149, p_1827); hr_fs(_o6149, hr_str(" < 0 || _k", 10)); hr_fi(_o6149, p_1827); hr_fs(_o6149, hr_str(" > ", 3)); hr_fi(_o6149, ((*({ hrv *_t6150 = &(g550); int64_t _i6150 = rt_1868; (S1*)_t6150->b + hr_ix(_i6150, _t6150->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:682"); }))).b_); hr_fs(_o6149, hr_str(") hr_die(\"resize past a limited array's capacity\", ", 51)); }));
(void)(f312_wloc(n_1820));
(void)(({ hrv *_o6152 = &(g163); hr_fs(_o6152, hr_str("); for (int64_t _j = _v", 23)); hr_fi(_o6152, p_1827); hr_fs(_o6152, hr_str("->n; _j < _k", 12)); hr_fi(_o6152, p_1827); hr_fs(_o6152, hr_str("; _j++) memset(&_v", 18)); hr_fi(_o6152, p_1827); hr_fs(_o6152, hr_str("->e[_j], 0, sizeof _v", 21)); hr_fi(_o6152, p_1827); hr_fs(_o6152, hr_str("->e[0]); ", 9)); }));
if (((total_1825) > (((int64_t)2LL)))) { (void)(({ hrv *_o6153 = &(g163); hr_fs(_o6153, hr_str("for (int64_t _j = _v", 20)); hr_fi(_o6153, p_1827); hr_fs(_o6153, hr_str("->n; _j < _k", 12)); hr_fi(_o6153, p_1827); hr_fs(_o6153, hr_str("; _j++) _v", 10)); hr_fi(_o6153, p_1827); hr_fs(_o6153, hr_str("->e[_j] = ", 10)); }));
(void)(f289_gx(f321_arg(((int64_t)2LL), &recv_1824, &n_1820)));
(void)(f260_ow(hr_str("; ", 2)));
 }
(void)(({ hrv *_o6157 = &(g163); hr_fs(_o6157, hr_str("_v", 2)); hr_fi(_o6157, p_1827); hr_fs(_o6157, hr_str("->n = _k", 8)); hr_fi(_o6157, p_1827); hr_fs(_o6157, hr_str("; })", 4)); }));
return;
 }
if (((b_1822) == (((int64_t)26LL)))) { (void)(f261_ct(e_1869));
(void)(f260_ow(hr_str(" _x", 3)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1824, &n_1820)));
(void)(({ hrv *_o6164 = &(g163); hr_fs(_o6164, hr_str("; int64_t _r", 12)); hr_fi(_o6164, p_1827); hr_fs(_o6164, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6164, p_1827); hr_fs(_o6164, hr_str("->n; _j++) if (", 15)); }));
(void)(f327_heq_val_o(e_1869, p_1827));
(void)(({ hrv *_o6166 = &(g163); hr_fs(_o6166, hr_str(") { _r", 6)); hr_fi(_o6166, p_1827); hr_fs(_o6166, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6166, p_1827); hr_fs(_o6166, hr_str("; })", 4)); }));
return;
 }
(void)(f287_gerr(n_1820, hr_str("unsupported limited-array operation", 35)));
return;
 }
if ((((((*({ hrv *_t6168 = &(g550); int64_t _i6168 = rt_1868; (S1*)_t6168->b + hr_ix(_i6168, _t6168->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:686"); }))).k_) == (((uint8_t)9LL))) || f282_is_fix(rt_1868))) { if (((b_1822) == (((int64_t)26LL)))) { (void)(f260_ow(hr_str("({ hsl _v", 9)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f291_gas(recv_1824));
(void)(f260_ow(hr_str("; ", 2)));
(void)(f261_ct(e_1869));
(void)(f260_ow(hr_str(" _x", 3)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1824, &n_1820)));
(void)(({ hrv *_o6181 = &(g163); hr_fs(_o6181, hr_str("; int64_t _r", 12)); hr_fi(_o6181, p_1827); hr_fs(_o6181, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6181, p_1827); hr_fs(_o6181, hr_str(".n; _j++) if (", 14)); }));
(void)(f331_heq_val_s(e_1869, p_1827));
(void)(({ hrv *_o6183 = &(g163); hr_fs(_o6183, hr_str(") { _r", 6)); hr_fi(_o6183, p_1827); hr_fs(_o6183, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6183, p_1827); hr_fs(_o6183, hr_str("; })", 4)); }));
return;
 }
(void)(f287_gerr(n_1820, hr_str("this operation needs a resizable array", 38)));
return;
 }
(void)(f260_ow(hr_str("({ hrv *_v", 10)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f325_grecv_ptr(recv_1824));
(void)(f260_ow(hr_str("; ", 2)));
if (((b_1822) == (((int64_t)20LL)))) { (void)(f261_ct(e_1869));
(void)(f260_ow(hr_str(" _x", 3)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1824, &n_1820)));
(void)(f260_ow(hr_str("; ", 2)));
(void)(f261_ct(e_1869));
(void)(f260_ow(hr_str(" *_p", 4)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" = (", 4)));
(void)(f261_ct(e_1869));
(void)(({ hrv *_o6202 = &(g163); hr_fs(_o6202, hr_str("*)hr_grow(_v", 12)); hr_fi(_o6202, p_1827); hr_fs(_o6202, hr_str(", 1, sizeof _x", 14)); hr_fi(_o6202, p_1827); hr_fs(_o6202, hr_str("); *_p", 6)); hr_fi(_o6202, p_1827); hr_fs(_o6202, hr_str(" = _x", 5)); hr_fi(_o6202, p_1827); hr_fs(_o6202, hr_str("; _p", 4)); hr_fi(_o6202, p_1827); hr_fs(_o6202, hr_str("; })", 4)); }));
return;
 }
if (((b_1822) == (((int64_t)21LL)))) { (void)(({ hrv *_o6203 = &(g163); hr_fs(_o6203, hr_str("hsl _s", 6)); hr_fi(_o6203, p_1827); hr_fs(_o6203, hr_str(" = ", 3)); }));
(void)(f291_gas(f321_arg(((int64_t)1LL), &recv_1824, &n_1820)));
(void)(({ hrv *_o6206 = &(g163); hr_fs(_o6206, hr_str("; hr_append(_v", 14)); hr_fi(_o6206, p_1827); hr_fs(_o6206, hr_str(", _s", 4)); hr_fi(_o6206, p_1827); hr_fs(_o6206, hr_str(".p, _s", 6)); hr_fi(_o6206, p_1827); hr_fs(_o6206, hr_str(".n, sizeof(", 11)); }));
(void)(f261_ct(e_1869));
(void)(f260_ow(hr_str(")); })", 6)));
return;
 }
if (((b_1822) == (((int64_t)22LL)))) { (void)(({ hrv *_o6209 = &(g163); hr_fs(_o6209, hr_str("if (!_v", 7)); hr_fi(_o6209, p_1827); hr_fs(_o6209, hr_str("->n) hr_die(\"pop of an empty array\", ", 37)); }));
(void)(f312_wloc(n_1820));
(void)(({ hrv *_o6211 = &(g163); hr_fs(_o6211, hr_str("); ((", 5)); }));
(void)(f261_ct(e_1869));
(void)(({ hrv *_o6213 = &(g163); hr_fs(_o6213, hr_str("*)_v", 4)); hr_fi(_o6213, p_1827); hr_fs(_o6213, hr_str("->b)[--_v", 9)); hr_fi(_o6213, p_1827); hr_fs(_o6213, hr_str("->n]; })", 8)); }));
return;
 }
if (((b_1822) == (((int64_t)23LL)))) { (void)(({ hrv *_o6214 = &(g163); hr_fs(_o6214, hr_str("int64_t _k", 10)); hr_fi(_o6214, p_1827); hr_fs(_o6214, hr_str(" = ", 3)); }));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1824, &n_1820)));
(void)(({ hrv *_o6217 = &(g163); hr_fs(_o6217, hr_str("; if (_k", 8)); hr_fi(_o6217, p_1827); hr_fs(_o6217, hr_str(" < 0 || _k", 10)); hr_fi(_o6217, p_1827); hr_fs(_o6217, hr_str(" > _v", 5)); hr_fi(_o6217, p_1827); hr_fs(_o6217, hr_str("->n) hr_die(\"pop_n past the length\", ", 37)); }));
(void)(f312_wloc(n_1820));
(void)(({ hrv *_o6219 = &(g163); hr_fs(_o6219, hr_str("); _v", 5)); hr_fi(_o6219, p_1827); hr_fs(_o6219, hr_str("->n -= _k", 9)); hr_fi(_o6219, p_1827); hr_fs(_o6219, hr_str("; })", 4)); }));
return;
 }
if (((b_1822) == (((int64_t)25LL)))) { (void)(({ hrv *_o6220 = &(g163); hr_fs(_o6220, hr_str("_v", 2)); hr_fi(_o6220, p_1827); hr_fs(_o6220, hr_str("->n = 0; })", 11)); }));
return;
 }
if (((b_1822) == (((int64_t)24LL)))) { (void)(({ hrv *_o6221 = &(g163); hr_fs(_o6221, hr_str("int64_t _k", 10)); hr_fi(_o6221, p_1827); hr_fs(_o6221, hr_str(" = ", 3)); }));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1824, &n_1820)));
(void)(({ hrv *_o6224 = &(g163); hr_fs(_o6224, hr_str("; if (_k", 8)); hr_fi(_o6224, p_1827); hr_fs(_o6224, hr_str(" < 0) hr_die(\"resize to a negative length\", ", 44)); }));
(void)(f312_wloc(n_1820));
(void)(f260_ow(hr_str("); ", 3)));
if (((total_1825) > (((int64_t)2LL)))) { (void)(f261_ct(e_1869));
(void)(f260_ow(hr_str(" _x", 3)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f321_arg(((int64_t)2LL), &recv_1824, &n_1820)));
(void)(({ hrv *_o6233 = &(g163); hr_fs(_o6233, hr_str("; int64_t _o", 12)); hr_fi(_o6233, p_1827); hr_fs(_o6233, hr_str(" = _v", 5)); hr_fi(_o6233, p_1827); hr_fs(_o6233, hr_str("->n; hr_resize(_v", 17)); hr_fi(_o6233, p_1827); hr_fs(_o6233, hr_str(", _k", 4)); hr_fi(_o6233, p_1827); hr_fs(_o6233, hr_str(", sizeof _x", 11)); hr_fi(_o6233, p_1827); hr_fs(_o6233, hr_str("); for (int64_t _j = _o", 23)); hr_fi(_o6233, p_1827); hr_fs(_o6233, hr_str("; _j < _k", 9)); hr_fi(_o6233, p_1827); hr_fs(_o6233, hr_str("; _j++) ((", 10)); }));
(void)(f261_ct(e_1869));
(void)(({ hrv *_o6235 = &(g163); hr_fs(_o6235, hr_str("*)_v", 4)); hr_fi(_o6235, p_1827); hr_fs(_o6235, hr_str("->b)[_j] = _x", 13)); hr_fi(_o6235, p_1827); hr_fs(_o6235, hr_str("; })", 4)); }));
return;
 }
(void)(({ hrv *_o6236 = &(g163); hr_fs(_o6236, hr_str("hr_resize(_v", 12)); hr_fi(_o6236, p_1827); hr_fs(_o6236, hr_str(", _k", 4)); hr_fi(_o6236, p_1827); hr_fs(_o6236, hr_str(", sizeof(", 9)); }));
(void)(f261_ct(e_1869));
(void)(f260_ow(hr_str(")); })", 6)));
return;
 }
if (((b_1822) == (((int64_t)26LL)))) { (void)(f261_ct(e_1869));
(void)(f260_ow(hr_str(" _x", 3)));
(void)(f294_oi(p_1827));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1824, &n_1820)));
(void)(({ hrv *_o6245 = &(g163); hr_fs(_o6245, hr_str("; int64_t _r", 12)); hr_fi(_o6245, p_1827); hr_fs(_o6245, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6245, p_1827); hr_fs(_o6245, hr_str("->n; _j++) if (", 15)); }));
(void)(f332_heq_val_r(e_1869, p_1827));
(void)(({ hrv *_o6247 = &(g163); hr_fs(_o6247, hr_str(") { _r", 6)); hr_fi(_o6247, p_1827); hr_fs(_o6247, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6247, p_1827); hr_fs(_o6247, hr_str("; })", 4)); }));
return;
 }
(void)(f287_gerr(n_1820, hr_str("unsupported array operation", 27)));
}
static int64_t f321_arg(int64_t i_1826, int64_t *c1824, int64_t *c1820) {
return ({ int64_t _r6249; if ((((*c1824)) >= (((int64_t)0LL)))) { _r6249 = ({ int64_t _r6250; if (((i_1826) == (((int64_t)0LL)))) { _r6250 = (*c1824);  } else { _r6250 = f90_kid((*c1820), ((int64_t)((int64_t)i_1826 - (int64_t)((int64_t)1LL))));  } _r6250; });  } else { _r6249 = f90_kid((*c1820), i_1826);  } _r6249; });
}
static void f322_gfmt(hsl o_1830, int64_t n_1831, int64_t t_1832, bool top_1833) {
int64_t d_1834 = f179_deref(t_1832); 
int64_t k_1835 = ((int64_t)(((*({ hrv *_t6254 = &(g550); int64_t _i6254 = d_1834; (S1*)_t6254->b + hr_ix(_i6254, _t6254->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:368"); }))).k_)); 
int64_t hk_1836 = ({ int64_t _r6255; if (((d_1834) < ((g348).n))) { _r6255 = ((int64_t)((*({ hrv *_t6256 = &(g348); int64_t _i6256 = d_1834; (int32_t*)_t6256->b + hr_ix(_i6256, _t6256->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:369"); }))));  } else { _r6255 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r6255; }); 
if ((((hk_1836) >= (((int64_t)0LL))) && ((f179_deref(f208_ptype_of(hk_1836, ((int64_t)1LL)))) == (d_1834)))) { int64_t pt_1837 = f208_ptype_of(hk_1836, ((int64_t)1LL)); 
(void)(f323_fn_cname(hk_1836));
(void)(f260_ow(hr_str("(", 1)));
(void)(f260_ow(o_1830));
(void)(f260_ow(hr_str(", ", 2)));
if (((((*({ hrv *_t6264 = &(g550); int64_t _i6264 = pt_1837; (S1*)_t6264->b + hr_ix(_i6264, _t6264->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:373"); }))).k_) == (((uint8_t)10LL)))) { if (((((*({ hrv *_t6265 = &(g550); int64_t _i6265 = t_1832; (S1*)_t6265->b + hr_ix(_i6265, _t6265->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:373"); }))).k_) == (((uint8_t)10LL)))) { (void)(f289_gx(n_1831));
 } else { (void)(f324_gaddr(n_1831));
 }
 } else { if (((((*({ hrv *_t6268 = &(g550); int64_t _i6268 = t_1832; (S1*)_t6268->b + hr_ix(_i6268, _t6268->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:373"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_ow(hr_str("*", 1)));
 }
(void)(f289_gx(n_1831));
 }
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if ((((k_1835) == (((int64_t)18LL))) || f164_is_byte_arr(d_1834))) { if (top_1833) { (void)(f260_ow(hr_str("hr_fs(", 6)));
 } else { (void)(f260_ow(hr_str("hr_fq(", 6)));
 }
(void)(f260_ow(o_1830));
(void)(f260_ow(hr_str(", ", 2)));
if (((((*({ hrv *_t6277 = &(g550); int64_t _i6277 = f141_at(n_1831); (S1*)_t6277->b + hr_ix(_i6277, _t6277->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:377"); }))).k_) == (((uint8_t)18LL)))) { (void)(f289_gx(n_1831));
 } else { (void)(f291_gas(n_1831));
 }
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((k_1835) == (((int64_t)3LL)))) { (void)(f260_ow(({ hsl _r6283; if (f153_is_signed(d_1834)) { _r6283 = hr_str("hr_fi(", 6);  } else { _r6283 = hr_str("hr_fu(", 6);  } _r6283; })));
(void)(f260_ow(o_1830));
(void)(f260_ow(hr_str(", ", 2)));
if (((d_1834) != (t_1832))) { (void)(f260_ow(hr_str("*", 1)));
 }
(void)(f289_gx(n_1831));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((k_1835) == (((int64_t)12LL)))) { (void)(f260_ow(hr_str("hr_fi(", 6)));
(void)(f260_ow(o_1830));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f289_gx(n_1831));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((k_1835) == (((int64_t)4LL)))) { (void)(f260_ow(({ hsl _r6296; if (((((*({ hrv *_t6297 = &(g550); int64_t _i6297 = d_1834; (S1*)_t6297->b + hr_ix(_i6297, _t6297->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:380"); }))).s_) == (((uint8_t)4LL)))) { _r6296 = hr_str("hr_ff(", 6);  } else { _r6296 = hr_str("hr_fd(", 6);  } _r6296; })));
(void)(f260_ow(o_1830));
(void)(f260_ow(hr_str(", ", 2)));
if (((d_1834) != (t_1832))) { (void)(f260_ow(hr_str("*", 1)));
 }
(void)(f289_gx(n_1831));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((k_1835) == (((int64_t)13LL)))) { (void)(f260_ow(hr_str("hr_fd(", 6)));
(void)(f260_ow(o_1830));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f289_gx(n_1831));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((k_1835) == (((int64_t)2LL)))) { (void)(f260_ow(hr_str("hr_fc(", 6)));
(void)(f260_ow(o_1830));
(void)(f260_ow(hr_str(", (", 3)));
if (((d_1834) != (t_1832))) { (void)(f260_ow(hr_str("*", 1)));
 }
(void)(f289_gx(n_1831));
(void)(f260_ow(hr_str(") \077 \"true\" : \"false\")", 21)));
return;
 }
(void)(f260_ow(hr_str("hf", 2)));
(void)(f294_oi(d_1834));
(void)(f260_ow(hr_str("(", 1)));
(void)(f260_ow(o_1830));
(void)(f260_ow(hr_str(", ", 2)));
if (((d_1834) != (t_1832))) { (void)(f260_ow(hr_str("*", 1)));
 }
if ((((((k_1835) == (((int64_t)8LL))) && (!(f282_is_fix(d_1834)))) && (!(f283_is_lim(d_1834)))) || ((k_1835) == (((int64_t)9LL))))) { (void)(f292_gsl(n_1831, t_1832));
 } else { (void)(f289_gx(n_1831));
 }
(void)(f260_ow(hr_str(")", 1)));
(void)(f299_gen_hf(d_1834));
}
static void f323_fn_cname(int64_t i_1838) {
(void)(f302_fn_cname_to((&(g163)), i_1838));
}
static void f324_gaddr(int64_t n_1839) {
if (f272_is_place(n_1839)) { (void)(f260_ow(hr_str("(&(", 3)));
(void)(f275_gx0(n_1839));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
int64_t t_1840 = f141_at(n_1839); 
int64_t k_1841 = f273_tmp(t_1840, f268_is_res(t_1840)); 
(void)(f260_ow(hr_str("(", 1)));
(void)(f274_ot(k_1841));
(void)(f260_ow(hr_str(" = (", 4)));
(void)(f269_gxo(n_1839));
(void)(f260_ow(hr_str("), &", 4)));
(void)(f274_ot(k_1841));
(void)(f260_ow(hr_str(")", 1)));
}
static void f325_grecv_ptr(int64_t r_1846) {
int64_t t_1847 = f141_at(r_1846); 
if (((((*({ hrv *_t6342 = &(g550); int64_t _i6342 = t_1847; (S1*)_t6342->b + hr_ix(_i6342, _t6342->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:641"); }))).k_) == (((uint8_t)10LL)))) { (void)(f275_gx0(r_1846));
return;
 }
if (f272_is_place(r_1846)) { (void)(f260_ow(hr_str("&(", 2)));
(void)(f275_gx0(r_1846));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
int64_t k_1848 = f273_tmp(t_1847, f268_is_res(t_1847)); 
(void)(f260_ow(hr_str("(", 1)));
(void)(f274_ot(k_1848));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f269_gxo(r_1846));
(void)(f260_ow(hr_str(", &", 3)));
(void)(f274_ot(k_1848));
(void)(f260_ow(hr_str(")", 1)));
}
static void f326_esz(int64_t t_1860) {
(void)(f260_ow(hr_str("sizeof(", 7)));
(void)(f261_ct(t_1860));
(void)(f260_ow(hr_str(")", 1)));
}
static void f327_heq_val_o(int64_t e_1870, int64_t p_1871) {
L100 a_1872 = ({ L100 _t6360; memset(&_t6360, 0, sizeof _t6360); _t6360.n = 0; _t6360; }); 
L100 b_1873 = ({ L100 _t6361; memset(&_t6361, 0, sizeof _t6361); _t6361.n = 0; _t6361; }); 
(void)(({ L100 *_l6362 = &(a_1872); hrv _o6362 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6362, hr_str("_v", 2)); hr_fi(&_o6362, p_1871); hr_fs(&_o6362, hr_str("->e[_j]", 7)); if (_l6362->n + _o6362.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:707"); memcpy(_l6362->e + _l6362->n, _o6362.b, (size_t)_o6362.n); _l6362->n += _o6362.n; }));
(void)(({ L100 *_l6363 = &(b_1873); hrv _o6363 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6363, hr_str("_x", 2)); hr_fi(&_o6363, p_1871); if (_l6363->n + _o6363.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:707"); memcpy(_l6363->e + _l6363->n, _o6363.b, (size_t)_o6363.n); _l6363->n += _o6363.n; }));
(void)(f328_heq_o(e_1870, ({ hsl _t6365 = ({ L100 *_t6366 = &(a_1872); (hsl){ (uint8_t*)_t6366->e, _t6366->n }; }); int64_t _l6365 = 0, _h6365 = _t6365.n; if (_l6365 < 0 || _h6365 < _l6365 || _h6365 > _t6365.n) hr_slerr(_l6365, _h6365, _t6365.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:707"); (hsl){ _t6365.p + _l6365 * (int64_t)sizeof(uint8_t), _h6365 - _l6365 }; }), ({ hsl _t6367 = ({ L100 *_t6368 = &(b_1873); (hsl){ (uint8_t*)_t6368->e, _t6368->n }; }); int64_t _l6367 = 0, _h6367 = _t6367.n; if (_l6367 < 0 || _h6367 < _l6367 || _h6367 > _t6367.n) hr_slerr(_l6367, _h6367, _t6367.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:707"); (hsl){ _t6367.p + _l6367 * (int64_t)sizeof(uint8_t), _h6367 - _l6367 }; })));
}
static void f328_heq_o(int64_t e_1874, hsl a_1875, hsl b_1876) {
(void)(f329_heq_pre(e_1874));
int64_t s0_1880 = (g169).n; 
(void)(f304_heq_val(e_1874, a_1875, b_1876));
(void)(({ hrv *_v6371 = &(g163); hsl _s6371 = ({ hsl _t6372 = hr_sl(g169); int64_t _l6372 = s0_1880, _h6372 = _t6372.n; if (_l6372 < 0 || _h6372 < _l6372 || _h6372 > _t6372.n) hr_slerr(_l6372, _h6372, _t6372.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:704"); (hsl){ _t6372.p + _l6372 * (int64_t)sizeof(uint8_t), _h6372 - _l6372 }; }); hr_append(_v6371, _s6371.p, _s6371.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6373 = &(g169); int64_t _k6373 = s0_1880; if (_k6373 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:704"); hr_resize(_v6373, _k6373, sizeof(uint8_t)); }));
}
static void f329_heq_pre(int64_t t_1877) {
if ((!(f330_scalar_ty(t_1877)))) { (void)(f295_gen_heq(t_1877));
 }
}
static bool f330_scalar_ty(int64_t t_1878) {
int64_t k_1879 = ((int64_t)(((*({ hrv *_t6376 = &(g550); int64_t _i6376 = t_1878; (S1*)_t6376->b + hr_ix(_i6376, _t6376->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:705"); }))).k_)); 
return (((((k_1879) == (((int64_t)3LL))) || ((k_1879) == (((int64_t)4LL)))) || ((k_1879) == (((int64_t)2LL)))) || ((k_1879) == (((int64_t)10LL))));
}
static void f331_heq_val_s(int64_t e_1881, int64_t p_1882) {
L98 a_1883 = ({ L98 _t6377; memset(&_t6377, 0, sizeof _t6377); _t6377.n = 0; _t6377; }); 
L100 b_1884 = ({ L100 _t6378; memset(&_t6378, 0, sizeof _t6378); _t6378.n = 0; _t6378; }); 
(void)(({ L98 *_v6379 = &(a_1883); hsl _s6379 = hr_str("((", 2); if (_v6379->n + _s6379.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:708"); memmove(_v6379->e + _v6379->n, _s6379.p, (size_t)_s6379.n * sizeof _v6379->e[0]); _v6379->n += _s6379.n; }));
(void)(({ L98 *_v6380 = &(a_1883); hsl _s6380 = f264_cn(e_1881); if (_v6380->n + _s6380.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:708"); memmove(_v6380->e + _v6380->n, _s6380.p, (size_t)_s6380.n * sizeof _v6380->e[0]); _v6380->n += _s6380.n; }));
(void)(({ L98 *_l6382 = &(a_1883); hrv _o6382 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6382, hr_str("*)_v", 4)); hr_fi(&_o6382, p_1882); hr_fs(&_o6382, hr_str(".p)[_j]", 7)); if (_l6382->n + _o6382.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:708"); memcpy(_l6382->e + _l6382->n, _o6382.b, (size_t)_o6382.n); _l6382->n += _o6382.n; }));
(void)(({ L100 *_l6383 = &(b_1884); hrv _o6383 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6383, hr_str("_x", 2)); hr_fi(&_o6383, p_1882); if (_l6383->n + _o6383.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:708"); memcpy(_l6383->e + _l6383->n, _o6383.b, (size_t)_o6383.n); _l6383->n += _o6383.n; }));
(void)(f328_heq_o(e_1881, ({ hsl _t6385 = ({ L98 *_t6386 = &(a_1883); (hsl){ (uint8_t*)_t6386->e, _t6386->n }; }); int64_t _l6385 = 0, _h6385 = _t6385.n; if (_l6385 < 0 || _h6385 < _l6385 || _h6385 > _t6385.n) hr_slerr(_l6385, _h6385, _t6385.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:708"); (hsl){ _t6385.p + _l6385 * (int64_t)sizeof(uint8_t), _h6385 - _l6385 }; }), ({ hsl _t6387 = ({ L100 *_t6388 = &(b_1884); (hsl){ (uint8_t*)_t6388->e, _t6388->n }; }); int64_t _l6387 = 0, _h6387 = _t6387.n; if (_l6387 < 0 || _h6387 < _l6387 || _h6387 > _t6387.n) hr_slerr(_l6387, _h6387, _t6387.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:708"); (hsl){ _t6387.p + _l6387 * (int64_t)sizeof(uint8_t), _h6387 - _l6387 }; })));
}
static void f332_heq_val_r(int64_t e_1885, int64_t p_1886) {
L98 a_1887 = ({ L98 _t6389; memset(&_t6389, 0, sizeof _t6389); _t6389.n = 0; _t6389; }); 
L100 b_1888 = ({ L100 _t6390; memset(&_t6390, 0, sizeof _t6390); _t6390.n = 0; _t6390; }); 
(void)(({ L98 *_v6391 = &(a_1887); hsl _s6391 = hr_str("((", 2); if (_v6391->n + _s6391.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:709"); memmove(_v6391->e + _v6391->n, _s6391.p, (size_t)_s6391.n * sizeof _v6391->e[0]); _v6391->n += _s6391.n; }));
(void)(({ L98 *_v6392 = &(a_1887); hsl _s6392 = f264_cn(e_1885); if (_v6392->n + _s6392.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:709"); memmove(_v6392->e + _v6392->n, _s6392.p, (size_t)_s6392.n * sizeof _v6392->e[0]); _v6392->n += _s6392.n; }));
(void)(({ L98 *_l6394 = &(a_1887); hrv _o6394 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6394, hr_str("*)_v", 4)); hr_fi(&_o6394, p_1886); hr_fs(&_o6394, hr_str("->b)[_j]", 8)); if (_l6394->n + _o6394.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:709"); memcpy(_l6394->e + _l6394->n, _o6394.b, (size_t)_o6394.n); _l6394->n += _o6394.n; }));
(void)(({ L100 *_l6395 = &(b_1888); hrv _o6395 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6395, hr_str("_x", 2)); hr_fi(&_o6395, p_1886); if (_l6395->n + _o6395.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:709"); memcpy(_l6395->e + _l6395->n, _o6395.b, (size_t)_o6395.n); _l6395->n += _o6395.n; }));
(void)(f328_heq_o(e_1885, ({ hsl _t6397 = ({ L98 *_t6398 = &(a_1887); (hsl){ (uint8_t*)_t6398->e, _t6398->n }; }); int64_t _l6397 = 0, _h6397 = _t6397.n; if (_l6397 < 0 || _h6397 < _l6397 || _h6397 > _t6397.n) hr_slerr(_l6397, _h6397, _t6397.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:709"); (hsl){ _t6397.p + _l6397 * (int64_t)sizeof(uint8_t), _h6397 - _l6397 }; }), ({ hsl _t6399 = ({ L100 *_t6400 = &(b_1888); (hsl){ (uint8_t*)_t6400->e, _t6400->n }; }); int64_t _l6399 = 0, _h6399 = _t6399.n; if (_l6399 < 0 || _h6399 < _l6399 || _h6399 > _t6399.n) hr_slerr(_l6399, _h6399, _t6399.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:709"); (hsl){ _t6399.p + _l6399 * (int64_t)sizeof(uint8_t), _h6399 - _l6399 }; })));
}
static void f333_gblkcall(int64_t n_1889) {
int64_t bi_1890 = f157_rv(n_1889); 
int64_t fv_1891 = ((int64_t)(((*({ hrv *_t6402 = &(g387); int64_t _i6402 = bi_1890; (S6*)_t6402->b + hr_ix(_i6402, _t6402->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:621"); }))).node_)); 
int64_t sa_1892 = g400; 
(void)(f260_ow(hr_str("({ ", 3)));
int64_t np_1893 = ((int64_t)(((*({ hrv *_t6404 = &(g703); int64_t _i6404 = fv_1891; (S4*)_t6404->b + hr_ix(_i6404, _t6404->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:624"); }))).n_)); 
int64_t na_1894 = ((int64_t)(((*({ hrv *_t6405 = &(g703); int64_t _i6405 = n_1889; (S4*)_t6405->b + hr_ix(_i6405, _t6405->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:625"); }))).n_)); 
if (((((uint16_t)((uint64_t)((*({ hrv *_t6406 = &(g703); int64_t _i6406 = fv_1891; (S4*)_t6406->b + hr_ix(_i6406, _t6406->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:626"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { int64_t _e6408 = np_1893; for (int64_t _k6408 = 0; _k6408 < _e6408; _k6408++) { int64_t j_1895 = (int64_t)_k6408; int64_t p_1896 = f90_kid(fv_1891, j_1895); 
g400 = bi_1890;
int64_t v_1897 = f157_rv(p_1896); 
g400 = sa_1892;
if (((j_1895) < (na_1894))) { (void)(f261_ct(((int64_t)(((*({ hrv *_t6412 = &(g388); int64_t _i6412 = v_1897; (S12*)_t6412->b + hr_ix(_i6412, _t6412->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:627"); }))).ty_))));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f286_lv_name(v_1897));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f90_kid(n_1889, j_1895)));
(void)(f260_ow(hr_str("; ", 2)));
 }
 } } _bk6407:; 
 } else { if (((na_1894) >= (((int64_t)1LL)))) { g400 = bi_1890;
int64_t v_1898 = f157_rv(fv_1891); 
g400 = sa_1892;
if (((v_1898) >= (((int64_t)0LL)))) { (void)(f261_ct(((int64_t)(((*({ hrv *_t6421 = &(g388); int64_t _i6421 = v_1898; (S12*)_t6421->b + hr_ix(_i6421, _t6421->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:629"); }))).ty_))));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f286_lv_name(v_1898));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f90_kid(n_1889, ((int64_t)0LL))));
(void)(f260_ow(hr_str("; ", 2)));
 } else { (void)(f260_ow(hr_str("(void)(", 7)));
(void)(f289_gx(f90_kid(n_1889, ((int64_t)0LL))));
(void)(f260_ow(hr_str("); ", 3)));
 }
 }
 }
g400 = bi_1890;
int64_t body_1899 = ((int64_t)(((*({ hrv *_t6432 = &(g703); int64_t _i6432 = fv_1891; (S4*)_t6432->b + hr_ix(_i6432, _t6432->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:632"); }))).a_)); 
{ int32_t _e6434 = ((*({ hrv *_t6435 = &(g703); int64_t _i6435 = body_1899; (S4*)_t6435->b + hr_ix(_i6435, _t6435->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:633"); }))).n_; for (int32_t _k6434 = 0; _k6434 < _e6434; _k6434++) { int32_t i_1900 = (int32_t)_k6434; (void)(f334_gstmt(f90_kid(body_1899, ((int64_t)(i_1900)))));
 } } _bk6433:; 
int64_t tl_2031 = ((int64_t)(((*({ hrv *_t6438 = &(g703); int64_t _i6438 = body_1899; (S4*)_t6438->b + hr_ix(_i6438, _t6438->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:634"); }))).a_)); 
if (((tl_2031) >= (((int64_t)0LL)))) { if ((((((int64_t)(((*({ hrv *_t6439 = &(g387); int64_t _i6439 = bi_1890; (S6*)_t6439->b + hr_ix(_i6439, _t6439->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:635"); }))).ret_))) != (g557)) && (!(f209_ends(tl_2031))))) { (void)(f289_gx(tl_2031));
(void)(f260_ow(hr_str("; ", 2)));
 } else { (void)(f334_gstmt(tl_2031));
 }
 }
g400 = sa_1892;
(void)(f260_ow(hr_str(" })", 3)));
}
static void f334_gstmt(int64_t n_1901) {
if (((n_1901) < (((int64_t)0LL)))) { return;
 }
int64_t sp_1902 = (g163).n; 
int64_t td_1903 = (g176).n; 
S4 x_1904 = (*({ hrv *_t6445 = &(g703); int64_t _i6445 = n_1901; (S4*)_t6445->b + hr_ix(_i6445, _t6445->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1025"); })); 
int64_t k_1905 = ((int64_t)((x_1904).k_)); 
bool decl_1906 = ((k_1905) == (((int64_t)33LL))); 
if (((k_1905) == (((int64_t)33LL)))) { (void)(f335_gvdecl(n_1901));
 } else { (void)(f337_gstmt1(n_1901));
 }
(void)(f260_ow(hr_str("\012", 1)));
if ((((g176).n) > (td_1903))) { (void)(({ hrv *_v6449 = &(g177); _v6449->n = 0; }));
(void)(({ hrv *_v6450 = &(g177); hsl _s6450 = ({ hsl _t6451 = hr_sl(g163); int64_t _l6451 = sp_1902, _h6451 = _t6451.n; if (_l6451 < 0 || _h6451 < _l6451 || _h6451 > _t6451.n) hr_slerr(_l6451, _h6451, _t6451.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1031"); (hsl){ _t6451.p + _l6451 * (int64_t)sizeof(uint8_t), _h6451 - _l6451 }; }); hr_append(_v6450, _s6450.p, _s6450.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6452 = &(g163); int64_t _k6452 = sp_1902; if (_k6452 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1031"); hr_resize(_v6452, _k6452, sizeof(uint8_t)); }));
if ((!(decl_1906))) { (void)(f260_ow(hr_str("{ ", 2)));
 }
(void)(({ hrv *_v6454 = &(g163); hsl _s6454 = ({ hsl _t6455 = hr_sl(g176); int64_t _l6455 = td_1903, _h6455 = _t6455.n; if (_l6455 < 0 || _h6455 < _l6455 || _h6455 > _t6455.n) hr_slerr(_l6455, _h6455, _t6455.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1033"); (hsl){ _t6455.p + _l6455 * (int64_t)sizeof(uint8_t), _h6455 - _l6455 }; }); hr_append(_v6454, _s6454.p, _s6454.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6456 = &(g176); int64_t _k6456 = td_1903; if (_k6456 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1033"); hr_resize(_v6456, _k6456, sizeof(uint8_t)); }));
(void)(({ hrv *_v6457 = &(g163); hsl _s6457 = ({ hsl _t6458 = hr_sl(g177); int64_t _l6458 = 0, _h6458 = _t6458.n; if (_l6458 < 0 || _h6458 < _l6458 || _h6458 > _t6458.n) hr_slerr(_l6458, _h6458, _t6458.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1034"); (hsl){ _t6458.p + _l6458 * (int64_t)sizeof(uint8_t), _h6458 - _l6458 }; }); hr_append(_v6457, _s6457.p, _s6457.n, sizeof(uint8_t)); }));
if ((!(decl_1906))) { (void)(f260_ow(hr_str("}\012", 2)));
 }
 }
}
static void f335_gvdecl(int64_t n_1907) {
S4 x_1908 = (*({ hrv *_t6460 = &(g703); int64_t _i6460 = n_1907; (S4*)_t6460->b + hr_ix(_i6460, _t6460->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:913"); })); 
if ((((x_1908).n_) > (((int32_t)1LL)))) { if (((f217_ax(n_1907)) == (((int64_t)1LL)))) { L89 ids_1909 = ({ L89 _t6462; memset(&_t6462, 0, sizeof _t6462); _t6462.n = 0; _t6462; }); 
{ int32_t _e6464 = (x_1908).n_; for (int32_t _k6464 = 0; _k6464 < _e6464; _k6464++) { int32_t i_1910 = (int32_t)_k6464; int64_t iv_1911 = f90_kid(((int64_t)((x_1908).b_)), ((int64_t)(i_1910))); 
int64_t p_1912 = f293_nt(); 
(void)(({ L89 *_v6467 = &(ids_1909); int32_t _x6467 = ((int32_t)(p_1912)); if (_v6467->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:917"); _v6467->e[_v6467->n] = _x6467; &_v6467->e[_v6467->n++]; }));
(void)(f261_ct(f279_fin(iv_1911)));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_1912));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(iv_1911));
(void)(f260_ow(hr_str("; ", 2)));
 } } _bk6463:; 
int64_t v0_1913 = f157_rv(n_1907); 
{ int32_t _e6477 = (x_1908).n_; for (int32_t _k6477 = 0; _k6477 < _e6477; _k6477++) { int32_t i_1914 = (int32_t)_k6477; (void)(f336_decl_lv(((int64_t)((int64_t)v0_1913 + (int64_t)((int64_t)(i_1914))))));
(void)(({ hrv *_o6479 = &(g163); hr_fs(_o6479, hr_str(" = _t", 5)); hr_fi(_o6479, (*({ L89 *_t6480 = &(ids_1909); int64_t _i6480 = i_1914; _t6480->e + hr_ix(_i6480, _t6480->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:919"); }))); hr_fs(_o6479, hr_str("; ", 2)); }));
 } } _bk6476:; 
return;
 }
int64_t init_1917 = f90_kid(((int64_t)((x_1908).b_)), ((int64_t)0LL)); 
int64_t p_1918 = f293_nt(); 
(void)(f261_ct(f141_at(init_1917)));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_1918));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(init_1917));
(void)(f260_ow(hr_str("; ", 2)));
int64_t v0_1919 = f157_rv(n_1907); 
{ int32_t _e6492 = (x_1908).n_; for (int32_t _k6492 = 0; _k6492 < _e6492; _k6492++) { int32_t i_1920 = (int32_t)_k6492; (void)(f336_decl_lv(((int64_t)((int64_t)v0_1919 + (int64_t)((int64_t)(i_1920))))));
(void)(({ hrv *_o6494 = &(g163); hr_fs(_o6494, hr_str(" = _t", 5)); hr_fi(_o6494, p_1918); hr_fs(_o6494, hr_str(".r", 2)); hr_fi(_o6494, i_1920); hr_fs(_o6494, hr_str("; ", 2)); }));
 } } _bk6491:; 
return;
 }
int64_t v_1921 = f157_rv(n_1907); 
int64_t t_1922 = ((int64_t)(((*({ hrv *_t6496 = &(g388); int64_t _i6496 = v_1921; (S12*)_t6496->b + hr_ix(_i6496, _t6496->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:930"); }))).ty_)); 
(void)(f336_decl_lv(v_1921));
(void)(f260_ow(hr_str(" = ", 3)));
if ((((x_1908).b_) < (((int32_t)0LL)))) { (void)(f260_ow(hr_str("{0}; ", 5)));
return;
 }
int64_t init_1923 = f90_kid(((int64_t)((x_1908).b_)), ((int64_t)0LL)); 
if (((((*({ hrv *_t6501 = &(g550); int64_t _i6501 = t_1922; (S1*)_t6501->b + hr_ix(_i6501, _t6501->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:935"); }))).k_) == (((uint8_t)10LL)))) { int64_t it_1924 = f279_fin(init_1923); 
if ((((((*({ hrv *_t6503 = &(g550); int64_t _i6503 = it_1924; (S1*)_t6503->b + hr_ix(_i6503, _t6503->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:935"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t6504 = &(g550); int64_t _i6504 = it_1924; (S1*)_t6504->b + hr_ix(_i6504, _t6504->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:935"); }))).k_) == (((uint8_t)11LL))))) { (void)(f289_gx(init_1923));
 } else { (void)(f324_gaddr(init_1923));
 }
(void)(f260_ow(hr_str("; ", 2)));
return;
 }
if (f268_is_res(t_1922)) { (void)(f269_gxo(init_1923));
(void)(f260_ow(hr_str("; ", 2)));
return;
 }
int64_t it_1925 = f141_at(init_1923); 
if (((((*({ hrv *_t6512 = &(g550); int64_t _i6512 = it_1925; (S1*)_t6512->b + hr_ix(_i6512, _t6512->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:938"); }))).k_) == (((uint8_t)14LL)))) { (void)(f289_gx(init_1923));
(void)(({ hrv *_o6514 = &(g163); hr_fs(_o6514, hr_str(".r0; ", 5)); }));
return;
 }
(void)(f289_gx(init_1923));
(void)(f260_ow(hr_str("; ", 2)));
}
static void f336_decl_lv(int64_t v_1915) {
int64_t t_1916 = ((int64_t)(((*({ hrv *_t6517 = &(g388); int64_t _i6517 = v_1915; (S12*)_t6517->b + hr_ix(_i6517, _t6517->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:942"); }))).ty_)); 
(void)(f261_ct(t_1916));
(void)(f260_ow(hr_str(" ", 1)));
if (f285_lv_isptr(v_1915)) { (void)(f260_ow(hr_str("*", 1)));
 }
(void)(f286_lv_name(v_1915));
if ((f268_is_res(t_1916) && (!(f285_lv_isptr(v_1915))))) { (void)(f260_ow(hr_str(" __attribute__((cleanup(hr_rdrop)))", 35)));
 }
}
static void f337_gstmt1(int64_t n_1926) {
S4 x_1927 = (*({ hrv *_t6526 = &(g703); int64_t _i6526 = n_1926; (S4*)_t6526->b + hr_ix(_i6526, _t6526->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1039"); })); 
int64_t k_1928 = ((int64_t)((x_1927).k_)); 
if (((k_1928) == (((int64_t)34LL)))) { (void)(f338_gassign(n_1926));
return;
 }
if (((k_1928) == (((int64_t)35LL)))) { int64_t a_1943 = ((int64_t)((x_1927).a_)); 
int64_t tt_1944 = f141_at(a_1943); 
if (((((*({ hrv *_t6529 = &(g550); int64_t _i6529 = tt_1944; (S1*)_t6529->b + hr_ix(_i6529, _t6529->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1042"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_ow(hr_str("(*", 2)));
(void)(f275_gx0(a_1943));
(void)(f260_ow(hr_str(")", 1)));
 } else { (void)(f289_gx(a_1943));
 }
(void)(f260_ow(({ hsl _r6535; if (((((int64_t)((x_1927).op_))) == (((int64_t)34LL)))) { _r6535 = hr_str("++;", 3);  } else { _r6535 = hr_str("--;", 3);  } _r6535; })));
return;
 }
if (((k_1928) == (((int64_t)50LL)))) { return;
 }
if (((k_1928) == (((int64_t)19LL)))) { (void)(f340_gif(n_1926, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1928) == (((int64_t)25LL)))) { (void)(f343_gwhile(n_1926));
return;
 }
if (((k_1928) == (((int64_t)26LL)))) { (void)(f346_gloop(n_1926, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1928) == (((int64_t)27LL)))) { (void)(f347_gfor(n_1926));
return;
 }
if (((k_1928) == (((int64_t)20LL)))) { (void)(f348_gmatch(n_1926, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1928) == (((int64_t)24LL)))) { (void)(f349_geblock(n_1926, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1928) == (((int64_t)23LL)))) { (void)(f260_ow(hr_str("{ ", 2)));
(void)(f341_gblk(n_1926, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f260_ow(hr_str(" }", 2)));
return;
 }
if (((k_1928) == (((int64_t)28LL)))) { (void)(f350_gret(n_1926));
return;
 }
if (((k_1928) == (((int64_t)29LL)))) { (void)(f354_gbreak(n_1926));
return;
 }
if (((k_1928) == (((int64_t)30LL)))) { (void)(f260_ow(hr_str("continue;", 9)));
return;
 }
if (((k_1928) == (((int64_t)37LL)))) { (void)(f287_gerr(n_1926, hr_str("const for is not supported by the self-hosted compiler yet", 58)));
return;
 }
if (f355_owned(n_1926)) { (void)(f260_ow(hr_str("hr_rgive(", 9)));
(void)(f275_gx0(n_1926));
(void)(f260_ow(hr_str(");", 2)));
return;
 }
(void)(f260_ow(hr_str("(void)(", 7)));
(void)(f289_gx(n_1926));
(void)(f260_ow(hr_str(");", 2)));
}
static void f338_gassign(int64_t n_1929) {
S4 x_1930 = (*({ hrv *_t6556 = &(g703); int64_t _i6556 = n_1929; (S4*)_t6556->b + hr_ix(_i6556, _t6556->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:949"); })); 
int64_t o_1931 = ((int64_t)((x_1930).op_)); 
if (((o_1931) == (((int64_t)11LL)))) { int64_t p_1932 = f293_nt(); 
(void)(f260_ow(hr_str("{ ", 2)));
(void)(f261_ct(f141_at(((int64_t)((x_1930).b_)))));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_1932));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1930).b_))));
(void)(f260_ow(hr_str("; ", 2)));
int64_t tl_1933 = ((int64_t)((x_1930).a_)); 
{ int32_t _e6567 = ((*({ hrv *_t6568 = &(g703); int64_t _i6568 = tl_1933; (S4*)_t6568->b + hr_ix(_i6568, _t6568->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:955"); }))).n_; for (int32_t _k6567 = 0; _k6567 < _e6567; _k6567++) { int32_t i_1934 = (int32_t)_k6567; int64_t tg_1935 = f90_kid(tl_1933, ((int64_t)(i_1934))); 
(void)(f289_gx(tg_1935));
(void)(({ hrv *_o6571 = &(g163); hr_fs(_o6571, hr_str(" = _t", 5)); hr_fi(_o6571, p_1932); hr_fs(_o6571, hr_str(".r", 2)); hr_fi(_o6571, i_1934); hr_fs(_o6571, hr_str("; ", 2)); }));
 } } _bk6566:; 
(void)(f260_ow(hr_str("}", 1)));
return;
 }
int64_t a_1936 = ((int64_t)((x_1930).a_)); 
int64_t tt_1937 = f141_at(a_1936); 
int64_t d_1938 = f179_deref(tt_1937); 
if ((((o_1931) == (((int64_t)18LL))) && ((((*({ hrv *_t6575 = &(g550); int64_t _i6575 = tt_1937; (S1*)_t6575->b + hr_ix(_i6575, _t6575->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:962"); }))).k_) == (((uint8_t)10LL))))) { int64_t b_1939 = ((int64_t)((x_1930).b_)); 
(void)(f275_gx0(a_1936));
(void)(f260_ow(hr_str(" = ", 3)));
if ((((((*({ hrv *_t6578 = &(g550); int64_t _i6578 = f279_fin(b_1939); (S1*)_t6578->b + hr_ix(_i6578, _t6578->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:965"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t6580 = &(g550); int64_t _i6580 = f279_fin(b_1939); (S1*)_t6580->b + hr_ix(_i6580, _t6580->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:965"); }))).k_) == (((uint8_t)11LL))))) { (void)(f289_gx(b_1939));
 } else { (void)(f324_gaddr(b_1939));
 }
(void)(f260_ow(hr_str(";", 1)));
return;
 }
if ((((o_1931) == (((int64_t)36LL))) || ((o_1931) == (((int64_t)18LL))))) { if (f268_is_res(d_1938)) { (void)(f260_ow(hr_str("hr_rset(", 8)));
if (((((*({ hrv *_t6587 = &(g550); int64_t _i6587 = tt_1937; (S1*)_t6587->b + hr_ix(_i6587, _t6587->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:970"); }))).k_) == (((uint8_t)10LL)))) { (void)(f275_gx0(a_1936));
 } else { (void)(f260_ow(hr_str("&(", 2)));
(void)(f289_gx(a_1936));
(void)(f260_ow(hr_str(")", 1)));
 }
(void)(f260_ow(hr_str(", ", 2)));
(void)(f269_gxo(((int64_t)((x_1930).b_))));
(void)(f260_ow(hr_str(");", 2)));
return;
 }
if ((((((((*({ hrv *_t6595 = &(g550); int64_t _i6595 = tt_1937; (S1*)_t6595->b + hr_ix(_i6595, _t6595->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:971"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t6596 = &(g550); int64_t _i6596 = f141_at(((int64_t)((x_1930).b_))); (S1*)_t6596->b + hr_ix(_i6596, _t6596->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:971"); }))).k_) != (((uint8_t)10LL)))) && ((((*({ hrv *_t6598 = &(g550); int64_t _i6598 = f279_fin(((int64_t)((x_1930).b_))); (S1*)_t6598->b + hr_ix(_i6598, _t6598->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:971"); }))).k_) != (((uint8_t)10LL)))) && ((((*({ hrv *_t6600 = &(g550); int64_t _i6600 = f141_at(((int64_t)((x_1930).b_))); (S1*)_t6600->b + hr_ix(_i6600, _t6600->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:971"); }))).k_) != (((uint8_t)11LL))))) { (void)(f260_ow(hr_str("*", 1)));
(void)(f275_gx0(a_1936));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1930).b_))));
(void)(f260_ow(hr_str(";", 1)));
return;
 }
if (((((*({ hrv *_t6607 = &(g703); int64_t _i6607 = a_1936; (S4*)_t6607->b + hr_ix(_i6607, _t6607->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:972"); }))).k_) == (((uint8_t)8LL)))) { (void)(f289_gx(a_1936));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1930).b_))));
(void)(f260_ow(hr_str(";", 1)));
return;
 }
int64_t q_1940 = f293_nt(); 
(void)(f260_ow(hr_str("{ ", 2)));
(void)(f261_ct(d_1938));
(void)(f260_ow(hr_str(" *_t", 4)));
(void)(f294_oi(q_1940));
(void)(f260_ow(hr_str(" = &(", 5)));
(void)(f289_gx(a_1936));
(void)(f260_ow(hr_str("); *_t", 6)));
(void)(f294_oi(q_1940));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1930).b_))));
(void)(f260_ow(hr_str("; }", 3)));
return;
 }
int64_t p_1941 = f293_nt(); 
(void)(f260_ow(hr_str("{ ", 2)));
(void)(f261_ct(d_1938));
(void)(f260_ow(hr_str(" *_t", 4)));
(void)(f294_oi(p_1941));
(void)(f260_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t6630 = &(g550); int64_t _i6630 = tt_1937; (S1*)_t6630->b + hr_ix(_i6630, _t6630->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:979"); }))).k_) == (((uint8_t)10LL)))) { (void)(f275_gx0(a_1936));
 } else { (void)(f260_ow(hr_str("&(", 2)));
(void)(f289_gx(a_1936));
(void)(f260_ow(hr_str(")", 1)));
 }
(void)(f260_ow(hr_str("; *_t", 5)));
(void)(f294_oi(p_1941));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f307_garith(f339_base_op(o_1931), d_1938, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)((x_1930).b_)), p_1941, n_1929));
(void)(f260_ow(hr_str("; }", 3)));
}
static int64_t f339_base_op(int64_t o_1942) {
if (((o_1942) == (((int64_t)26LL)))) { return ((int64_t)21LL);
 }
if (((o_1942) == (((int64_t)27LL)))) { return ((int64_t)22LL);
 }
if (((o_1942) == (((int64_t)28LL)))) { return ((int64_t)23LL);
 }
if (((o_1942) == (((int64_t)29LL)))) { return ((int64_t)24LL);
 }
if (((o_1942) == (((int64_t)30LL)))) { return ((int64_t)25LL);
 }
if (((o_1942) == (((int64_t)31LL)))) { return ((int64_t)49LL);
 }
if (((o_1942) == (((int64_t)32LL)))) { return ((int64_t)50LL);
 }
if (((o_1942) == (((int64_t)33LL)))) { return ((int64_t)51LL);
 }
if (((o_1942) == (((int64_t)45LL)))) { return ((int64_t)43LL);
 }
if (((o_1942) == (((int64_t)46LL)))) { return ((int64_t)44LL);
 }
return o_1942;
}
static void f340_gif(int64_t n_1945, int64_t res_1946) {
S4 x_1947 = (*({ hrv *_t6641 = &(g703); int64_t _i6641 = n_1945; (S4*)_t6641->b + hr_ix(_i6641, _t6641->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:796"); })); 
(void)(f260_ow(hr_str("if (", 4)));
int64_t m_1948 = f217_ax(n_1945); 
if ((((m_1948) != (((int64_t)0LL))) && ((m_1948) != (((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))))) { (void)(f260_ow(hr_str("(", 1)));
(void)(f275_gx0(((int64_t)((x_1947).a_))));
(void)(f260_ow(hr_str(") != 0", 6)));
 } else { (void)(f289_gx(((int64_t)((x_1947).a_))));
 }
(void)(f260_ow(hr_str(") { ", 4)));
if (((m_1948) > (((int64_t)1LL)))) { int64_t v_1949 = ((int64_t)((int64_t)m_1948 & (int64_t)((int64_t)((int64_t)((int64_t)((((int64_t)1LL)) << ((((int64_t)30LL)) & 63))) - (int64_t)((int64_t)1LL))))); 
(void)(f261_ct(((int64_t)(((*({ hrv *_t6650 = &(g388); int64_t _i6650 = v_1949; (S12*)_t6650->b + hr_ix(_i6650, _t6650->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:801"); }))).ty_))));
(void)(f260_ow(hr_str(" *", 2)));
(void)(f286_lv_name(v_1949));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f275_gx0(((int64_t)((x_1947).a_))));
(void)(f260_ow(hr_str("; ", 2)));
 }
(void)(f341_gblk(((int64_t)((x_1947).b_)), res_1946, false));
(void)(f260_ow(hr_str(" }", 2)));
if ((((x_1947).c_) >= (((int32_t)0LL)))) { (void)(f260_ow(hr_str(" else { ", 8)));
if (((((*({ hrv *_t6659 = &(g703); int64_t _i6659 = (x_1947).c_; (S4*)_t6659->b + hr_ix(_i6659, _t6659->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:804"); }))).k_) == (((uint8_t)19LL)))) { (void)(f340_gif(((int64_t)((x_1947).c_)), res_1946));
 } else { (void)(f341_gblk(((int64_t)((x_1947).c_)), res_1946, false));
 }
(void)(f260_ow(hr_str(" }", 2)));
 }
}
static void f341_gblk(int64_t b_1950, int64_t res_1951, bool val_1952) {
S4 x_1953 = (*({ hrv *_t6663 = &(g703); int64_t _i6663 = b_1950; (S4*)_t6663->b + hr_ix(_i6663, _t6663->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:785"); })); 
if (((((int64_t)((x_1953).k_))) != (((int64_t)23LL)))) { if (((res_1951) >= (((int64_t)0LL)))) { (void)(f342_gtail(b_1950, res_1951));
 } else { if (val_1952) { (void)(f289_gx(b_1950));
(void)(f260_ow(hr_str(";", 1)));
 } else { (void)(f334_gstmt(b_1950));
 }
 }
return;
 }
{ int32_t _e6669 = (x_1953).n_; for (int32_t _k6669 = 0; _k6669 < _e6669; _k6669++) { int32_t i_1956 = (int32_t)_k6669; (void)(f334_gstmt(f90_kid(b_1950, ((int64_t)(i_1956)))));
 } } _bk6668:; 
if ((((x_1953).a_) >= (((int32_t)0LL)))) { int64_t tl_1957 = ((int64_t)((x_1953).a_)); 
if (((res_1951) >= (((int64_t)0LL)))) { (void)(f342_gtail(tl_1957, res_1951));
return;
 }
if (((val_1952 && ((f141_at(tl_1957)) != (g557))) && (!(f209_ends(tl_1957))))) { (void)(f289_gx(tl_1957));
(void)(f260_ow(hr_str("; ", 2)));
return;
 }
(void)(f334_gstmt(tl_1957));
 }
}
static void f342_gtail(int64_t tl_1954, int64_t res_1955) {
if ((((res_1955) >= (((int64_t)0LL))) && (!(f209_ends(tl_1954))))) { (void)(f260_ow(hr_str("_r", 2)));
(void)(f294_oi(res_1955));
(void)(f260_ow(hr_str(" = ", 3)));
if (f268_is_res(f279_fin(tl_1954))) { (void)(f269_gxo(tl_1954));
 } else { (void)(f289_gx(tl_1954));
 }
(void)(f260_ow(hr_str("; ", 2)));
return;
 }
(void)(f334_gstmt(tl_1954));
}
static void f343_gwhile(int64_t n_1958) {
S4 x_1959 = (*({ hrv *_t6688 = &(g703); int64_t _i6688 = n_1958; (S4*)_t6688->b + hr_ix(_i6688, _t6688->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:819"); })); 
int64_t l_1962 = f344_lbl_push(((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f260_ow(hr_str("while (", 7)));
if (((f217_ax(n_1958)) == (((int64_t)1LL)))) { (void)(f260_ow(hr_str("(", 1)));
(void)(f275_gx0(((int64_t)((x_1959).a_))));
(void)(f260_ow(hr_str(") != 0", 6)));
 } else { (void)(f289_gx(((int64_t)((x_1959).a_))));
 }
(void)(f260_ow(hr_str(") { ", 4)));
(void)(f341_gblk(((int64_t)((x_1959).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f260_ow(hr_str(" }", 2)));
(void)(f345_lbl_pop(l_1962));
}
static int64_t f344_lbl_push(int64_t res_1960) {
int64_t l_1961 = f293_nt(); 
(void)(({ hrv *_v6701 = &(g180); int32_t _x6701 = ((int32_t)(l_1961)); int32_t *_p6701 = (int32_t*)hr_grow(_v6701, 1, sizeof _x6701); *_p6701 = _x6701; _p6701; }));
(void)(({ hrv *_v6702 = &(g181); int32_t _x6702 = ((int32_t)(res_1960)); int32_t *_p6702 = (int32_t*)hr_grow(_v6702, 1, sizeof _x6702); *_p6702 = _x6702; _p6702; }));
return l_1961;
}
static void f345_lbl_pop(int64_t l_1963) {
(void)(({ hrv *_v6703 = &(g180); if (!_v6703->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:807"); ((int32_t*)_v6703->b)[--_v6703->n]; }));
(void)(({ hrv *_v6704 = &(g181); if (!_v6704->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:807"); ((int32_t*)_v6704->b)[--_v6704->n]; }));
(void)(({ hrv *_o6705 = &(g163); hr_fs(_o6705, hr_str(" _bk", 4)); hr_fi(_o6705, l_1963); hr_fs(_o6705, hr_str(":; ", 3)); }));
}
static void f346_gloop(int64_t n_1964, int64_t res_1965) {
int64_t l_1966 = f344_lbl_push(res_1965); 
(void)(f260_ow(hr_str("for (;;) { ", 11)));
(void)(f341_gblk(((int64_t)(((*({ hrv *_t6709 = &(g703); int64_t _i6709 = n_1964; (S4*)_t6709->b + hr_ix(_i6709, _t6709->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:810"); }))).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f260_ow(hr_str(" }", 2)));
(void)(f345_lbl_pop(l_1966));
}
static void f347_gfor(int64_t n_1967) {
S4 x_1968 = (*({ hrv *_t6712 = &(g703); int64_t _i6712 = n_1967; (S4*)_t6712->b + hr_ix(_i6712, _t6712->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:827"); })); 
int64_t v_1969 = f157_rv(n_1967); 
int64_t m_1970 = f217_ax(n_1967); 
int64_t iv_1971 = ({ int64_t _r6715; if ((((x_1968).c_) >= (((int32_t)0LL)))) { _r6715 = ((int64_t)((m_1970) >> ((((int64_t)2LL)) & 63)));  } else { _r6715 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r6715; }); 
int64_t l_1972 = f344_lbl_push(((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t p_1973 = f293_nt(); 
int64_t et_1974 = ((int64_t)(((*({ hrv *_t6718 = &(g388); int64_t _i6718 = v_1969; (S12*)_t6718->b + hr_ix(_i6718, _t6718->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:833"); }))).ty_)); 
if (((((int64_t)((int64_t)m_1970 & (int64_t)((int64_t)3LL)))) == (((int64_t)0LL)))) { int64_t rt0_1975 = f279_fin(({ int64_t _r6720; if ((((x_1968).b_) >= (((int32_t)0LL)))) { _r6720 = ((int64_t)((x_1968).b_));  } else { _r6720 = ((int64_t)((x_1968).a_));  } _r6720; })); 
int64_t ctt_1976 = ({ int64_t _r6721; if (((((*({ hrv *_t6722 = &(g550); int64_t _i6722 = rt0_1975; (S1*)_t6722->b + hr_ix(_i6722, _t6722->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:836"); }))).k_) == (((uint8_t)3LL)))) { _r6721 = rt0_1975;  } else { _r6721 = g562;  } _r6721; }); 
(void)(f260_ow(hr_str("{ ", 2)));
(void)(f261_ct(ctt_1976));
(void)(f260_ow(hr_str(" _e", 3)));
(void)(f294_oi(p_1973));
(void)(f260_ow(hr_str(" = ", 3)));
if ((((x_1968).b_) >= (((int32_t)0LL)))) { (void)(f289_gx(((int64_t)((x_1968).b_))));
 } else { (void)(f289_gx(((int64_t)((x_1968).a_))));
 }
(void)(f260_ow(hr_str("; for (", 7)));
(void)(f261_ct(ctt_1976));
(void)(({ hrv *_o6732 = &(g163); hr_fs(_o6732, hr_str(" _k", 3)); hr_fi(_o6732, p_1973); hr_fs(_o6732, hr_str(" = ", 3)); }));
if ((((x_1968).b_) >= (((int32_t)0LL)))) { (void)(f289_gx(((int64_t)((x_1968).a_))));
 } else { (void)(f260_ow(hr_str("0", 1)));
 }
(void)(({ hrv *_o6735 = &(g163); hr_fs(_o6735, hr_str("; _k", 4)); hr_fi(_o6735, p_1973); hr_fs(_o6735, hr_str(" < _e", 5)); hr_fi(_o6735, p_1973); hr_fs(_o6735, hr_str("; _k", 4)); hr_fi(_o6735, p_1973); hr_fs(_o6735, hr_str("++) { ", 6)); }));
(void)(f261_ct(et_1974));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f286_lv_name(v_1969));
(void)(({ hrv *_o6739 = &(g163); hr_fs(_o6739, hr_str(" = (", 4)); }));
(void)(f261_ct(et_1974));
(void)(({ hrv *_o6741 = &(g163); hr_fs(_o6741, hr_str(")_k", 3)); hr_fi(_o6741, p_1973); hr_fs(_o6741, hr_str("; ", 2)); }));
if (((iv_1971) >= (((int64_t)0LL)))) { (void)(f261_ct(((int64_t)(((*({ hrv *_t6743 = &(g388); int64_t _i6743 = iv_1971; (S12*)_t6743->b + hr_ix(_i6743, _t6743->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:842"); }))).ty_))));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f286_lv_name(iv_1971));
(void)(f260_ow(hr_str(" = (", 4)));
(void)(f261_ct(((int64_t)(((*({ hrv *_t6748 = &(g388); int64_t _i6748 = iv_1971; (S12*)_t6748->b + hr_ix(_i6748, _t6748->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:842"); }))).ty_))));
(void)(({ hrv *_o6749 = &(g163); hr_fs(_o6749, hr_str(")_k", 3)); hr_fi(_o6749, p_1973); hr_fs(_o6749, hr_str("; ", 2)); }));
 }
(void)(f341_gblk(((int64_t)((x_1968).d_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f260_ow(hr_str(" } }", 4)));
(void)(f345_lbl_pop(l_1972));
return;
 }
int64_t a_1977 = ((int64_t)((x_1968).a_)); 
int64_t bt_1978 = f141_at(a_1977); 
int64_t d_1979 = f179_deref(bt_1978); 
int64_t e_1980 = ((int64_t)(((*({ hrv *_t6755 = &(g550); int64_t _i6755 = d_1979; (S1*)_t6755->b + hr_ix(_i6755, _t6755->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:851"); }))).a_)); 
bool byref_1981 = ((((uint16_t)((uint64_t)(x_1968).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))); 
if (f268_is_res(d_1979)) { (void)(f260_ow(hr_str("{ hrv *_v", 9)));
(void)(f294_oi(p_1973));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f325_grecv_ptr(a_1977));
(void)(({ hrv *_o6761 = &(g163); hr_fs(_o6761, hr_str("; for (int64_t _k", 17)); hr_fi(_o6761, p_1973); hr_fs(_o6761, hr_str(" = 0; _k", 8)); hr_fi(_o6761, p_1973); hr_fs(_o6761, hr_str(" < _v", 5)); hr_fi(_o6761, p_1973); hr_fs(_o6761, hr_str("->n; _k", 7)); hr_fi(_o6761, p_1973); hr_fs(_o6761, hr_str("++) { ", 6)); }));
(void)(f261_ct(e_1980));
(void)(f260_ow(({ hsl _r6764; if (byref_1981) { _r6764 = hr_str(" *", 2);  } else { _r6764 = hr_str(" ", 1);  } _r6764; })));
(void)(f286_lv_name(v_1969));
(void)(f260_ow(({ hsl _r6767; if (byref_1981) { _r6767 = hr_str(" = &((", 6);  } else { _r6767 = hr_str(" = ((", 5);  } _r6767; })));
(void)(f261_ct(e_1980));
(void)(({ hrv *_o6769 = &(g163); hr_fs(_o6769, hr_str("*)_v", 4)); hr_fi(_o6769, p_1973); hr_fs(_o6769, hr_str("->b)[_k", 7)); hr_fi(_o6769, p_1973); hr_fs(_o6769, hr_str("]; ", 3)); }));
 } else { (void)(f260_ow(hr_str("{ hsl _v", 8)));
(void)(f294_oi(p_1973));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f292_gsl(a_1977, bt_1978));
(void)(({ hrv *_o6774 = &(g163); hr_fs(_o6774, hr_str("; for (int64_t _k", 17)); hr_fi(_o6774, p_1973); hr_fs(_o6774, hr_str(" = 0; _k", 8)); hr_fi(_o6774, p_1973); hr_fs(_o6774, hr_str(" < _v", 5)); hr_fi(_o6774, p_1973); hr_fs(_o6774, hr_str(".n; _k", 6)); hr_fi(_o6774, p_1973); hr_fs(_o6774, hr_str("++) { ", 6)); }));
(void)(f261_ct(e_1980));
(void)(f260_ow(({ hsl _r6777; if (byref_1981) { _r6777 = hr_str(" *", 2);  } else { _r6777 = hr_str(" ", 1);  } _r6777; })));
(void)(f286_lv_name(v_1969));
(void)(f260_ow(({ hsl _r6780; if (byref_1981) { _r6780 = hr_str(" = &((", 6);  } else { _r6780 = hr_str(" = ((", 5);  } _r6780; })));
(void)(f261_ct(e_1980));
(void)(({ hrv *_o6782 = &(g163); hr_fs(_o6782, hr_str("*)_v", 4)); hr_fi(_o6782, p_1973); hr_fs(_o6782, hr_str(".p)[_k", 6)); hr_fi(_o6782, p_1973); hr_fs(_o6782, hr_str("]; ", 3)); }));
 }
if (((iv_1971) >= (((int64_t)0LL)))) { (void)(f261_ct(((int64_t)(((*({ hrv *_t6784 = &(g388); int64_t _i6784 = iv_1971; (S12*)_t6784->b + hr_ix(_i6784, _t6784->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:860"); }))).ty_))));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f286_lv_name(iv_1971));
(void)(f260_ow(hr_str(" = (", 4)));
(void)(f261_ct(((int64_t)(((*({ hrv *_t6789 = &(g388); int64_t _i6789 = iv_1971; (S12*)_t6789->b + hr_ix(_i6789, _t6789->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:860"); }))).ty_))));
(void)(({ hrv *_o6790 = &(g163); hr_fs(_o6790, hr_str(")_k", 3)); hr_fi(_o6790, p_1973); hr_fs(_o6790, hr_str("; ", 2)); }));
 }
(void)(f341_gblk(((int64_t)((x_1968).d_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f260_ow(hr_str(" } }", 4)));
(void)(f345_lbl_pop(l_1972));
}
static void f348_gmatch(int64_t n_1982, int64_t res_1983) {
S4 x_1984 = (*({ hrv *_t6794 = &(g703); int64_t _i6794 = n_1982; (S4*)_t6794->b + hr_ix(_i6794, _t6794->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:866"); })); 
int64_t a_1985 = ((int64_t)((x_1984).a_)); 
int64_t st_1986 = f141_at(a_1985); 
int64_t d_1987 = f179_deref(st_1986); 
int64_t p_1988 = f293_nt(); 
bool isenum_1989 = ((((*({ hrv *_t6798 = &(g550); int64_t _i6798 = d_1987; (S1*)_t6798->b + hr_ix(_i6798, _t6798->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:871"); }))).k_) == (((uint8_t)6LL))); 
(void)(f260_ow(hr_str("{ ", 2)));
if (isenum_1989) { (void)(f261_ct(d_1987));
(void)(f260_ow(hr_str(" *_m", 4)));
(void)(f294_oi(p_1988));
(void)(f260_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t6804 = &(g550); int64_t _i6804 = st_1986; (S1*)_t6804->b + hr_ix(_i6804, _t6804->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:873"); }))).k_) == (((uint8_t)10LL)))) { (void)(f275_gx0(a_1985));
 } else { if (f272_is_place(a_1985)) { (void)(f260_ow(hr_str("&(", 2)));
(void)(f289_gx(a_1985));
(void)(f260_ow(hr_str(")", 1)));
 } else { int64_t k0_1990 = f273_tmp(d_1987, false); 
(void)(f260_ow(hr_str("(", 1)));
(void)(f274_ot(k0_1990));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f269_gxo(a_1985));
(void)(f260_ow(hr_str(", &", 3)));
(void)(f274_ot(k0_1990));
(void)(f260_ow(hr_str(")", 1)));
 }
 }
(void)(f260_ow(hr_str("; ", 2)));
 } else { (void)(f261_ct(d_1987));
(void)(f260_ow(hr_str(" _m", 3)));
(void)(f294_oi(p_1988));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(a_1985));
(void)(f260_ow(hr_str("; ", 2)));
 }
bool first_1991 = true; 
{ int32_t _e6826 = (x_1984).n_; for (int32_t _k6826 = 0; _k6826 < _e6826; _k6826++) { int32_t i_1992 = (int32_t)_k6826; int64_t arm_1993 = f90_kid(n_1982, ((int64_t)(i_1992))); 
S4 ar_1994 = (*({ hrv *_t6828 = &(g703); int64_t _i6828 = arm_1993; (S4*)_t6828->b + hr_ix(_i6828, _t6828->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:878"); })); 
if ((!(first_1991))) { (void)(f260_ow(hr_str(" else ", 6)));
 }
first_1991 = false;
if (((((uint16_t)((uint64_t)(ar_1994).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(f260_ow(hr_str("{ ", 2)));
(void)(f341_gblk(((int64_t)((ar_1994).b_)), res_1983, false));
(void)(f260_ow(hr_str(" }", 2)));
continue;
 }
(void)(f260_ow(hr_str("if (", 4)));
{ int32_t _e6835 = (ar_1994).n_; for (int32_t _k6835 = 0; _k6835 < _e6835; _k6835++) { int32_t j_1995 = (int32_t)_k6835; if (((j_1995) > (((int32_t)0LL)))) { (void)(f260_ow(hr_str(" || ", 4)));
 }
int64_t it_1996 = f90_kid(arm_1993, ((int64_t)(j_1995))); 
int64_t lo_1997 = ((int64_t)(((*({ hrv *_t6838 = &(g703); int64_t _i6838 = it_1996; (S4*)_t6838->b + hr_ix(_i6838, _t6838->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:886"); }))).a_)); 
if (isenum_1989) { (void)(({ hrv *_o6839 = &(g163); hr_fs(_o6839, hr_str("_m", 2)); hr_fi(_o6839, p_1988); hr_fs(_o6839, hr_str("->tag == ", 9)); hr_fi(_o6839, f157_rv(lo_1997)); }));
 } else { if (((((*({ hrv *_t6841 = &(g703); int64_t _i6841 = it_1996; (S4*)_t6841->b + hr_ix(_i6841, _t6841->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:889"); }))).b_) >= (((int32_t)0LL)))) { (void)(({ hrv *_o6842 = &(g163); hr_fs(_o6842, hr_str("(_m", 3)); hr_fi(_o6842, p_1988); hr_fs(_o6842, hr_str(" >= ", 4)); }));
(void)(f289_gx(lo_1997));
(void)(({ hrv *_o6844 = &(g163); hr_fs(_o6844, hr_str(" && _m", 6)); hr_fi(_o6844, p_1988); hr_fs(_o6844, hr_str(" < ", 3)); }));
(void)(f289_gx(((int64_t)(((*({ hrv *_t6846 = &(g703); int64_t _i6846 = it_1996; (S4*)_t6846->b + hr_ix(_i6846, _t6846->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:889"); }))).b_))));
(void)(f260_ow(hr_str(")", 1)));
 } else { if (((((f180_leaf_kind(d_1987)) == (((int64_t)0LL))) && ((((*({ hrv *_t6849 = &(g550); int64_t _i6849 = d_1987; (S1*)_t6849->b + hr_ix(_i6849, _t6849->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:890"); }))).k_) != (((uint8_t)3LL)))) && ((((*({ hrv *_t6850 = &(g550); int64_t _i6850 = d_1987; (S1*)_t6850->b + hr_ix(_i6850, _t6850->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:890"); }))).k_) != (((uint8_t)2LL))))) { (void)(f260_ow(hr_str("heq", 3)));
(void)(f294_oi(d_1987));
(void)(({ hrv *_o6853 = &(g163); hr_fs(_o6853, hr_str("(_m", 3)); hr_fi(_o6853, p_1988); hr_fs(_o6853, hr_str(", ", 2)); }));
(void)(f289_gx(lo_1997));
(void)(f260_ow(hr_str(")", 1)));
(void)(f295_gen_heq(d_1987));
 } else { (void)(({ hrv *_o6857 = &(g163); hr_fs(_o6857, hr_str("_m", 2)); hr_fi(_o6857, p_1988); hr_fs(_o6857, hr_str(" == ", 4)); }));
(void)(f289_gx(lo_1997));
 }
 }
 }
 } } _bk6834:; 
(void)(f260_ow(hr_str(") { ", 4)));
if (((((ar_1994).s_) >= (((int32_t)0LL))) && isenum_1989)) { int64_t v_1998 = f157_rv(arm_1993); 
int64_t vi_1999 = f157_rv(((int64_t)(((*({ hrv *_t6862 = &(g703); int64_t _i6862 = f90_kid(arm_1993, ((int64_t)0LL)); (S4*)_t6862->b + hr_ix(_i6862, _t6862->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:896"); }))).a_))); 
int64_t lt_2000 = ((int64_t)(((*({ hrv *_t6864 = &(g388); int64_t _i6864 = v_1998; (S12*)_t6864->b + hr_ix(_i6864, _t6864->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:897"); }))).ty_)); 
int64_t vt_2001 = f179_deref(lt_2000); 
int64_t ei_2002 = ((int64_t)(((*({ hrv *_t6866 = &(g550); int64_t _i6866 = d_1987; (S1*)_t6866->b + hr_ix(_i6866, _t6866->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:899"); }))).a_)); 
S9 vv_2003 = (*({ hrv *_t6867 = &(g556); int64_t _i6867 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t6868 = &(g555); int64_t _i6868 = ei_2002; (S8*)_t6868->b + hr_ix(_i6868, _t6868->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:900"); }))).v0_)) + (int64_t)vi_1999)); (S9*)_t6867->b + hr_ix(_i6867, _t6867->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:900"); })); 
bool has_2004 = ((((vv_2003).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t6869 = &(g553); int64_t _i6869 = (vv_2003).si_; (S10*)_t6869->b + hr_ix(_i6869, _t6869->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:901"); }))).zero_))); 
(void)(f261_ct(lt_2000));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f286_lv_name(v_1998));
(void)(f260_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t6874 = &(g550); int64_t _i6874 = lt_2000; (S1*)_t6874->b + hr_ix(_i6874, _t6874->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:903"); }))).k_) == (((uint8_t)10LL)))) { if (has_2004) { (void)(({ hrv *_o6875 = &(g163); hr_fs(_o6875, hr_str("&_m", 3)); hr_fi(_o6875, p_1988); hr_fs(_o6875, hr_str("->u.v", 5)); hr_fi(_o6875, vi_1999); hr_fs(_o6875, hr_str("; ", 2)); }));
 } else { (void)(f260_ow(hr_str("0; ", 3)));
 }
 } else { if (has_2004) { (void)(({ hrv *_o6877 = &(g163); hr_fs(_o6877, hr_str("_m", 2)); hr_fi(_o6877, p_1988); hr_fs(_o6877, hr_str("->u.v", 5)); hr_fi(_o6877, vi_1999); hr_fs(_o6877, hr_str("; ", 2)); }));
 } else { (void)(f260_ow(hr_str("0; ", 3)));
 }
 }
 }
(void)(f341_gblk(((int64_t)((ar_1994).b_)), res_1983, false));
(void)(f260_ow(hr_str(" }", 2)));
 } } _bk6825:; 
(void)(f260_ow(hr_str(" }", 2)));
}
static void f349_geblock(int64_t n_2005, int64_t res_2006) {
int64_t l_2007 = f344_lbl_push(res_2006); 
(void)(f260_ow(hr_str("{ ", 2)));
(void)(f341_gblk(((int64_t)(((*({ hrv *_t6885 = &(g703); int64_t _i6885 = n_2005; (S4*)_t6885->b + hr_ix(_i6885, _t6885->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:815"); }))).a_)), res_2006, false));
(void)(f260_ow(hr_str(" }", 2)));
(void)(f345_lbl_pop(l_2007));
}
static void f350_gret(int64_t n_2008) {
S4 x_2009 = (*({ hrv *_t6888 = &(g703); int64_t _i6888 = n_2008; (S4*)_t6888->b + hr_ix(_i6888, _t6888->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:996"); })); 
int64_t lt_2010 = f217_ax(n_2008); 
if ((((lt_2010) >= (((int64_t)0LL))) && ((lt_2010) != (g179)))) { int64_t rt0_2011 = ((int64_t)(((*({ hrv *_t6890 = &(g387); int64_t _i6890 = lt_2010; (S6*)_t6890->b + hr_ix(_i6890, _t6890->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:999"); }))).ret_)); 
(void)(f260_ow(hr_str("{ ", 2)));
if ((((x_2009).n_) > (((int32_t)1LL)))) { (void)(({ hrv *_o6892 = &(g163); hr_fs(_o6892, hr_str("_lrv", 4)); hr_fi(_o6892, lt_2010); hr_fs(_o6892, hr_str(" = (", 4)); }));
(void)(f261_ct(rt0_2011));
(void)(f260_ow(hr_str("){ ", 3)));
{ int32_t _e6896 = (x_2009).n_; for (int32_t _k6896 = 0; _k6896 < _e6896; _k6896++) { int32_t i_2012 = (int32_t)_k6896; if (((i_2012) > (((int32_t)0LL)))) { (void)(f260_ow(hr_str(", ", 2)));
 }
int64_t c_2013 = f90_kid(n_2008, ((int64_t)(i_2012))); 
if (f268_is_res(f279_fin(c_2013))) { (void)(f351_gmove(c_2013));
 } else { (void)(f289_gx(c_2013));
 }
 } } _bk6895:; 
(void)(f260_ow(hr_str(" }; ", 4)));
 } else { if ((((x_2009).n_) == (((int32_t)1LL)))) { (void)(({ hrv *_o6904 = &(g163); hr_fs(_o6904, hr_str("_lrv", 4)); hr_fi(_o6904, lt_2010); hr_fs(_o6904, hr_str(" = ", 3)); }));
int64_t c_2019 = f90_kid(n_2008, ((int64_t)0LL)); 
if (f268_is_res(rt0_2011)) { (void)(f351_gmove(c_2019));
 } else { (void)(f289_gx(c_2019));
 }
(void)(f260_ow(hr_str("; ", 2)));
 }
 }
(void)(({ hrv *_o6910 = &(g163); hr_fs(_o6910, hr_str("hr_lr = ", 8)); hr_fi(_o6910, ((int64_t)((int64_t)lt_2010 + (int64_t)((int64_t)1LL)))); hr_fs(_o6910, hr_str("; ", 2)); }));
(void)(f353_gdummy());
(void)(f260_ow(hr_str(" }", 2)));
return;
 }
if ((((x_2009).n_) == (((int32_t)0LL)))) { (void)(f260_ow(hr_str("return;", 7)));
return;
 }
int64_t f_2021 = ({ int64_t _r6914; if (((lt_2010) >= (((int64_t)0LL)))) { _r6914 = lt_2010;  } else { _r6914 = f221_ret_fn();  } _r6914; }); 
int64_t rt_2022 = ((int64_t)(((*({ hrv *_t6916 = &(g387); int64_t _i6916 = f_2021; (S6*)_t6916->b + hr_ix(_i6916, _t6916->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1008"); }))).ret_)); 
if ((((x_2009).n_) > (((int32_t)1LL)))) { (void)(f260_ow(hr_str("return (", 8)));
(void)(f261_ct(rt_2022));
(void)(f260_ow(hr_str("){ ", 3)));
{ int32_t _e6921 = (x_2009).n_; for (int32_t _k6921 = 0; _k6921 < _e6921; _k6921++) { int32_t i_2023 = (int32_t)_k6921; if (((i_2023) > (((int32_t)0LL)))) { (void)(f260_ow(hr_str(", ", 2)));
 }
int64_t c_2024 = f90_kid(n_2008, ((int64_t)(i_2023))); 
if (f268_is_res(f279_fin(c_2024))) { (void)(f351_gmove(c_2024));
 } else { (void)(f289_gx(c_2024));
 }
 } } _bk6920:; 
(void)(f260_ow(hr_str(" };", 3)));
return;
 }
int64_t c_2025 = f90_kid(n_2008, ((int64_t)0LL)); 
(void)(f260_ow(hr_str("return ", 7)));
if (f268_is_res(rt_2022)) { (void)(f351_gmove(c_2025));
 } else { (void)(f289_gx(c_2025));
 }
(void)(f260_ow(hr_str(";", 1)));
}
static void f351_gmove(int64_t c_2014) {
if (f352_movable_local(c_2014)) { int64_t v_2017 = f157_rv(c_2014); 
int64_t p_2018 = f293_nt(); 
(void)(f260_ow(hr_str("({ hrv _mv", 10)));
(void)(f294_oi(p_2018));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f286_lv_name(v_2017));
(void)(f260_ow(hr_str("; ", 2)));
(void)(f286_lv_name(v_2017));
(void)(f260_ow(hr_str(".b = 0; ", 8)));
(void)(f286_lv_name(v_2017));
(void)(({ hrv *_o6946 = &(g163); hr_fs(_o6946, hr_str(".n = 0; _mv", 11)); hr_fi(_o6946, p_2018); hr_fs(_o6946, hr_str("; })", 4)); }));
return;
 }
(void)(f269_gxo(c_2014));
}
static bool f352_movable_local(int64_t c_2015) {
if ((((((*({ hrv *_t6948 = &(g703); int64_t _i6948 = c_2015; (S4*)_t6948->b + hr_ix(_i6948, _t6948->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:990"); }))).k_) != (((uint8_t)8LL))) || ((f156_rk(c_2015)) != (((int64_t)1LL))))) { return false;
 }
int64_t v_2016 = f157_rv(c_2015); 
return (((((((int64_t)(((*({ hrv *_t6951 = &(g388); int64_t _i6951 = v_2016; (S12*)_t6951->b + hr_ix(_i6951, _t6951->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:990"); }))).cfn_))) == (g179)) && (!(f285_lv_isptr(v_2016)))) && ((((*({ hrv *_t6953 = &(g550); int64_t _i6953 = ((*({ hrv *_t6954 = &(g388); int64_t _i6954 = v_2016; (S12*)_t6954->b + hr_ix(_i6954, _t6954->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:990"); }))).ty_; (S1*)_t6953->b + hr_ix(_i6953, _t6953->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:990"); }))).k_) != (((uint8_t)10LL)))) && (((f150_cv(c_2015)) < (((int64_t)0LL))) || ((f150_cv(c_2015)) == (f141_at(c_2015)))));
}
static void f353_gdummy(void) {
int64_t rt_2020 = ((int64_t)(((*({ hrv *_t6958 = &(g387); int64_t _i6958 = g179; (S6*)_t6958->b + hr_ix(_i6958, _t6958->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:984"); }))).ret_)); 
if ((((rt_2020) < (((int64_t)0LL))) || ((rt_2020) == (g557)))) { (void)(f260_ow(hr_str("return;", 7)));
return;
 }
(void)(f260_ow(hr_str("{ ", 2)));
(void)(f261_ct(rt_2020));
(void)(f260_ow(hr_str(" _z; memset(&_z, 0, sizeof _z); return _z; }", 44)));
}
static void f354_gbreak(int64_t n_2026) {
S4 x_2027 = (*({ hrv *_t6963 = &(g703); int64_t _i6963 = n_2026; (S4*)_t6963->b + hr_ix(_i6963, _t6963->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1014"); })); 
if ((((g180).n) == (((int64_t)0LL)))) { (void)(f287_gerr(n_2026, hr_str("break outside a loop", 20)));
return;
 }
int64_t l_2028 = ((int64_t)((*({ hrv *_t6965 = &(g180); int64_t _i6965 = ((int64_t)((int64_t)(g180).n - (int64_t)((int64_t)1LL))); (int32_t*)_t6965->b + hr_ix(_i6965, _t6965->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1016"); })))); 
int64_t r_2029 = ((int64_t)((*({ hrv *_t6966 = &(g181); int64_t _i6966 = ((int64_t)((int64_t)(g181).n - (int64_t)((int64_t)1LL))); (int32_t*)_t6966->b + hr_ix(_i6966, _t6966->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1017"); })))); 
(void)(f260_ow(hr_str("{ ", 2)));
if ((((x_2027).a_) >= (((int32_t)0LL)))) { if (((r_2029) >= (((int64_t)0LL)))) { (void)(f260_ow(hr_str("_r", 2)));
(void)(f294_oi(r_2029));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_2027).a_))));
(void)(f260_ow(hr_str("; ", 2)));
 } else { (void)(f260_ow(hr_str("(void)(", 7)));
(void)(f289_gx(((int64_t)((x_2027).a_))));
(void)(f260_ow(hr_str("); ", 3)));
 }
 }
(void)(({ hrv *_o6976 = &(g163); hr_fs(_o6976, hr_str("goto _bk", 8)); hr_fi(_o6976, l_2028); hr_fs(_o6976, hr_str("; }", 3)); }));
}
static bool f355_owned(int64_t n_2030) {
return (f268_is_res(f279_fin(n_2030)) && (!(f272_is_place(n_2030))));
}
static bool f356_is_ext(int64_t i_2034) {
return ((((uint16_t)((uint64_t)((*({ hrv *_t6980 = &(g703); int64_t _i6980 = ((*({ hrv *_t6981 = &(g387); int64_t _i6981 = i_2034; (S6*)_t6981->b + hr_ix(_i6981, _t6981->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:574"); }))).node_; (S4*)_t6980->b + hr_ix(_i6980, _t6980->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:574"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)));
}
static void f357_ext_name(int64_t i_2039) {
int64_t node_2040 = ((int64_t)(((*({ hrv *_t6982 = &(g387); int64_t _i6982 = i_2039; (S6*)_t6982->b + hr_ix(_i6982, _t6982->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:569"); }))).node_)); 
int64_t x_2041 = ((int64_t)(((*({ hrv *_t6983 = &(g703); int64_t _i6983 = node_2040; (S4*)_t6983->b + hr_ix(_i6983, _t6983->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:570"); }))).e_)); 
if ((((x_2041) >= (((int64_t)0LL))) && ((((*({ hrv *_t6984 = &(g703); int64_t _i6984 = x_2041; (S4*)_t6984->b + hr_ix(_i6984, _t6984->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:571"); }))).a_) >= (((int32_t)0LL))))) { hsl s_2042 = f280_tok_str(((int64_t)(((*({ hrv *_t6986 = &(g703); int64_t _i6986 = x_2041; (S4*)_t6986->b + hr_ix(_i6986, _t6986->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:571"); }))).a_))); 
if (((((((s_2042).n) > (((int64_t)3LL))) && (((*({ hsl _t6987 = s_2042; int64_t _i6987 = ((int64_t)0LL); (uint8_t*)_t6987.p + hr_ix(_i6987, _t6987.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:571"); }))) == (((uint8_t)103LL)))) && (((*({ hsl _t6988 = s_2042; int64_t _i6988 = ((int64_t)1LL); (uint8_t*)_t6988.p + hr_ix(_i6988, _t6988.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:571"); }))) == (((uint8_t)115LL)))) && (((*({ hsl _t6989 = s_2042; int64_t _i6989 = ((int64_t)2LL); (uint8_t*)_t6989.p + hr_ix(_i6989, _t6989.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:571"); }))) == (((uint8_t)95LL))))) { (void)(f260_ow(hr_str("hr_", 3)));
(void)(f260_ow(({ hsl _t6992 = s_2042; int64_t _l6992 = ((int64_t)3LL), _h6992 = _t6992.n; if (_l6992 < 0 || _h6992 < _l6992 || _h6992 > _t6992.n) hr_slerr(_l6992, _h6992, _t6992.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:571"); (hsl){ _t6992.p + _l6992 * (int64_t)sizeof(uint8_t), _h6992 - _l6992 }; })));
return;
 }
(void)(f260_ow(s_2042));
return;
 }
(void)(f260_ow(f10_nm(((int64_t)(((*({ hrv *_t6996 = &(g703); int64_t _i6996 = node_2040; (S4*)_t6996->b + hr_ix(_i6996, _t6996->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:572"); }))).s_)))));
}
static void f358_gcall_args(int64_t n_2043, int64_t inst_2044, int64_t recv_2045) {
S4 x_2046 = (*({ hrv *_t6997 = &(g703); int64_t _i6997 = n_2043; (S4*)_t6997->b + hr_ix(_i6997, _t6997->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:576"); })); 
int64_t np_2047 = ((int64_t)(((*({ hrv *_t6998 = &(g703); int64_t _i6998 = ((*({ hrv *_t6999 = &(g387); int64_t _i6999 = inst_2044; (S6*)_t6999->b + hr_ix(_i6999, _t6999->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:577"); }))).node_; (S4*)_t6998->b + hr_ix(_i6998, _t6998->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:577"); }))).n_)); 
int64_t na_2048 = ((int64_t)((int64_t)((int64_t)((x_2046).n_)) + (int64_t)({ int64_t _r7000; if (((recv_2045) >= (((int64_t)0LL)))) { _r7000 = ((int64_t)1LL);  } else { _r7000 = ((int64_t)0LL);  } _r7000; }))); 
bool first_2049 = true; 
{ int64_t _e7002 = np_2047; for (int64_t _k7002 = 0; _k7002 < _e7002; _k7002++) { int64_t j_2050 = (int64_t)_k7002; int64_t pt_2051 = f208_ptype_of(inst_2044, j_2050); 
if ((!(first_2049))) { (void)(f260_ow(hr_str(", ", 2)));
 }
first_2049 = false;
if (((j_2050) >= (na_2048))) { int64_t p_2052 = f90_kid(((int64_t)(((*({ hrv *_t7006 = &(g387); int64_t _i7006 = inst_2044; (S6*)_t7006->b + hr_ix(_i7006, _t7006->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:585"); }))).node_)), j_2050); 
int64_t sa_2053 = g400; 
g400 = inst_2044;
(void)(f289_gx(((int64_t)(((*({ hrv *_t7008 = &(g703); int64_t _i7008 = p_2052; (S4*)_t7008->b + hr_ix(_i7008, _t7008->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:586"); }))).b_))));
g400 = sa_2053;
continue;
 }
int64_t c_2054 = ({ int64_t _r7009; if (((recv_2045) >= (((int64_t)0LL)))) { _r7009 = ({ int64_t _r7010; if (((j_2050) == (((int64_t)0LL)))) { _r7010 = recv_2045;  } else { _r7010 = f90_kid(n_2043, ((int64_t)((int64_t)j_2050 - (int64_t)((int64_t)1LL))));  } _r7010; });  } else { _r7009 = f90_kid(n_2043, j_2050);  } _r7009; }); 
int64_t ct0_2055 = f279_fin(c_2054); 
if ((((((*({ hrv *_t7014 = &(g550); int64_t _i7014 = pt_2051; (S1*)_t7014->b + hr_ix(_i7014, _t7014->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:591"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t7015 = &(g550); int64_t _i7015 = pt_2051; (S1*)_t7015->b + hr_ix(_i7015, _t7015->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:591"); }))).c_) < (((int32_t)0LL))))) { if ((((((*({ hrv *_t7016 = &(g550); int64_t _i7016 = ct0_2055; (S1*)_t7016->b + hr_ix(_i7016, _t7016->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:592"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t7017 = &(g550); int64_t _i7017 = ct0_2055; (S1*)_t7017->b + hr_ix(_i7017, _t7017->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:592"); }))).k_) == (((uint8_t)11LL))))) { (void)(f289_gx(c_2054));
 } else { (void)(f324_gaddr(c_2054));
 }
continue;
 }
if (f268_is_res(pt_2051)) { (void)(f269_gxo(c_2054));
continue;
 }
if (((((*({ hrv *_t7022 = &(g550); int64_t _i7022 = pt_2051; (S1*)_t7022->b + hr_ix(_i7022, _t7022->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:596"); }))).k_) == (((uint8_t)9LL)))) { (void)(f291_gas(c_2054));
continue;
 }
(void)(f289_gx(c_2054));
 } } _bk7001:; 
{ hrv *_v7026 = &(g391); for (int64_t _k7026 = 0; _k7026 < _v7026->n; _k7026++) { S13 cp_2056 = ((S13*)_v7026->b)[_k7026]; if (((((int64_t)((cp_2056).inst_))) == (inst_2044))) { if ((!(first_2049))) { (void)(f260_ow(hr_str(", ", 2)));
 }
first_2049 = false;
(void)(f359_lv_addr(((int64_t)((cp_2056).lv_))));
 }
 } } _bk7025:; 
}
static void f359_lv_addr(int64_t v_2057) {
if (((((int64_t)(((*({ hrv *_t7029 = &(g388); int64_t _i7029 = v_2057; (S12*)_t7029->b + hr_ix(_i7029, _t7029->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:119"); }))).cfn_))) != (g179))) { (void)(({ hrv *_o7030 = &(g163); hr_fs(_o7030, hr_str("c", 1)); hr_fi(_o7030, v_2057); }));
return;
 }
(void)(f260_ow(hr_str("&", 1)));
(void)(f286_lv_name(v_2057));
}
static void f360_glrcheck(void) {
(void)(f260_ow(hr_str("if (HR_UNLIKELY(hr_lr)) { ", 26)));
if (((*({ hrv *_t7034 = &(g387); int64_t _i7034 = g179; (S6*)_t7034->b + hr_ix(_i7034, _t7034->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:987"); }))).tg_) { int64_t rt_2058 = ((int64_t)(((*({ hrv *_t7035 = &(g387); int64_t _i7035 = g179; (S6*)_t7035->b + hr_ix(_i7035, _t7035->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:987"); }))).ret_)); 
(void)(({ hrv *_o7036 = &(g163); hr_fs(_o7036, hr_str("if (hr_lr == ", 13)); hr_fi(_o7036, ((int64_t)((int64_t)g179 + (int64_t)((int64_t)1LL)))); hr_fs(_o7036, hr_str(") { hr_lr = 0; ", 15)); }));
if ((((rt_2058) < (((int64_t)0LL))) || ((rt_2058) == (g557)))) { (void)(f260_ow(hr_str("return; } ", 10)));
 } else { (void)(({ hrv *_o7038 = &(g163); hr_fs(_o7038, hr_str("return _lrv", 11)); hr_fi(_o7038, g179); hr_fs(_o7038, hr_str("; } ", 4)); }));
 }
 }
(void)(f353_gdummy());
(void)(f260_ow(hr_str(" } ", 3)));
}
static void f361_gen_fn(int64_t i_2073) {
int64_t node_2074 = ((int64_t)(((*({ hrv *_t7041 = &(g387); int64_t _i7041 = i_2073; (S6*)_t7041->b + hr_ix(_i7041, _t7041->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1080"); }))).node_)); 
g400 = i_2073;
g179 = i_2073;
(void)(({ hrv *_v7042 = &(g180); _v7042->n = 0; }));
(void)(({ hrv *_v7043 = &(g181); _v7043->n = 0; }));
int64_t s0_2075 = (g163).n; 
(void)(f362_gsig(i_2073));
(void)(({ hrv *_v7045 = &(g166); hsl _s7045 = ({ hsl _t7046 = hr_sl(g163); int64_t _l7046 = s0_2075, _h7046 = _t7046.n; if (_l7046 < 0 || _h7046 < _l7046 || _h7046 > _t7046.n) hr_slerr(_l7046, _h7046, _t7046.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1085"); (hsl){ _t7046.p + _l7046 * (int64_t)sizeof(uint8_t), _h7046 - _l7046 }; }); hr_append(_v7045, _s7045.p, _s7045.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v7047 = &(g166); hsl _s7047 = hr_str(";\012", 2); hr_append(_v7047, _s7047.p, _s7047.n, sizeof(uint8_t)); }));
(void)(f260_ow(hr_str(" {\012", 3)));
{ int32_t _e7050 = ((*({ hrv *_t7051 = &(g703); int64_t _i7051 = node_2074; (S4*)_t7051->b + hr_ix(_i7051, _t7051->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1087"); }))).n_; for (int32_t _k7050 = 0; _k7050 < _e7050; _k7050++) { int32_t j_2087 = (int32_t)_k7050; int64_t p_2088 = f90_kid(node_2074, ((int64_t)(j_2087))); 
int64_t v_2089 = f157_rv(p_2088); 
if (f268_is_res(f208_ptype_of(i_2073, ((int64_t)(j_2087))))) { (void)(f260_ow(hr_str("hrv ", 4)));
(void)(f286_lv_name(v_2089));
(void)(f260_ow(hr_str(" __attribute__((cleanup(hr_rdrop))) = ", 38)));
(void)(f286_lv_name(v_2089));
(void)(f260_ow(hr_str("_in;\012", 5)));
 }
 } } _bk7049:; 
int64_t body_2090 = ((int64_t)(((*({ hrv *_t7061 = &(g703); int64_t _i7061 = node_2074; (S4*)_t7061->b + hr_ix(_i7061, _t7061->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1088"); }))).c_)); 
int64_t rt_2091 = ((int64_t)(((*({ hrv *_t7062 = &(g387); int64_t _i7062 = i_2073; (S6*)_t7062->b + hr_ix(_i7062, _t7062->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1089"); }))).ret_)); 
int64_t tl_2092 = ((int64_t)(((*({ hrv *_t7063 = &(g703); int64_t _i7063 = body_2090; (S4*)_t7063->b + hr_ix(_i7063, _t7063->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1090"); }))).a_)); 
{ int32_t _e7065 = ((*({ hrv *_t7066 = &(g703); int64_t _i7066 = body_2090; (S4*)_t7066->b + hr_ix(_i7066, _t7066->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1091"); }))).n_; for (int32_t _k7065 = 0; _k7065 < _e7065; _k7065++) { int32_t q_2093 = (int32_t)_k7065; (void)(f334_gstmt(f90_kid(body_2090, ((int64_t)(q_2093)))));
 } } _bk7064:; 
if (((tl_2092) >= (((int64_t)0LL)))) { if ((((((rt_2091) >= (((int64_t)0LL))) && ((rt_2091) != (g557))) && ((f141_at(tl_2092)) != (g557))) && (!(f209_ends(tl_2092))))) { int64_t sp_2094 = (g163).n; 
int64_t td_2095 = (g176).n; 
if ((((((*({ hrv *_t7071 = &(g550); int64_t _i7071 = rt_2091; (S1*)_t7071->b + hr_ix(_i7071, _t7071->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1095"); }))).k_) == (((uint8_t)14LL))) && ((((*({ hrv *_t7072 = &(g703); int64_t _i7072 = tl_2092; (S4*)_t7072->b + hr_ix(_i7072, _t7072->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1095"); }))).k_) == (((uint8_t)11LL))))) { (void)(f260_ow(hr_str("return ", 7)));
(void)(f289_gx(tl_2092));
(void)(f260_ow(hr_str(";\012", 2)));
 } else { (void)(f260_ow(hr_str("return ", 7)));
if (f268_is_res(rt_2091)) { (void)(f351_gmove(tl_2092));
 } else { (void)(f289_gx(tl_2092));
 }
(void)(f260_ow(hr_str(";\012", 2)));
 }
if ((((g176).n) > (td_2095))) { (void)(({ hrv *_v7081 = &(g177); _v7081->n = 0; }));
(void)(({ hrv *_v7082 = &(g177); hsl _s7082 = ({ hsl _t7083 = hr_sl(g163); int64_t _l7083 = sp_2094, _h7083 = _t7083.n; if (_l7083 < 0 || _h7083 < _l7083 || _h7083 > _t7083.n) hr_slerr(_l7083, _h7083, _t7083.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1097"); (hsl){ _t7083.p + _l7083 * (int64_t)sizeof(uint8_t), _h7083 - _l7083 }; }); hr_append(_v7082, _s7082.p, _s7082.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v7084 = &(g163); int64_t _k7084 = sp_2094; if (_k7084 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1097"); hr_resize(_v7084, _k7084, sizeof(uint8_t)); }));
(void)(f260_ow(hr_str("{ ", 2)));
(void)(({ hrv *_v7086 = &(g163); hsl _s7086 = ({ hsl _t7087 = hr_sl(g176); int64_t _l7087 = td_2095, _h7087 = _t7087.n; if (_l7087 < 0 || _h7087 < _l7087 || _h7087 > _t7087.n) hr_slerr(_l7087, _h7087, _t7087.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1097"); (hsl){ _t7087.p + _l7087 * (int64_t)sizeof(uint8_t), _h7087 - _l7087 }; }); hr_append(_v7086, _s7086.p, _s7086.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v7088 = &(g176); int64_t _k7088 = td_2095; if (_k7088 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1097"); hr_resize(_v7088, _k7088, sizeof(uint8_t)); }));
(void)(({ hrv *_v7089 = &(g163); hsl _s7089 = ({ hsl _t7090 = hr_sl(g177); int64_t _l7090 = 0, _h7090 = _t7090.n; if (_l7090 < 0 || _h7090 < _l7090 || _h7090 > _t7090.n) hr_slerr(_l7090, _h7090, _t7090.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1097"); (hsl){ _t7090.p + _l7090 * (int64_t)sizeof(uint8_t), _h7090 - _l7090 }; }); hr_append(_v7089, _s7089.p, _s7089.n, sizeof(uint8_t)); }));
(void)(f260_ow(hr_str("}\012", 2)));
 }
 } else { (void)(f334_gstmt(tl_2092));
 }
 }
(void)(f260_ow(hr_str("}\012", 2)));
}
static void f362_gsig(int64_t i_2076) {
int64_t rt_2077 = ((int64_t)(((*({ hrv *_t7094 = &(g387); int64_t _i7094 = i_2076; (S6*)_t7094->b + hr_ix(_i7094, _t7094->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1059"); }))).ret_)); 
(void)(f260_ow(hr_str("static ", 7)));
if (((rt_2077) < (((int64_t)0LL)))) { (void)(f260_ow(hr_str("void", 4)));
 } else { (void)(f261_ct(rt_2077));
 }
(void)(f260_ow(hr_str(" ", 1)));
(void)(f323_fn_cname(i_2076));
(void)(f260_ow(hr_str("(", 1)));
int64_t node_2078 = ((int64_t)(((*({ hrv *_t7101 = &(g387); int64_t _i7101 = i_2076; (S6*)_t7101->b + hr_ix(_i7101, _t7101->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1063"); }))).node_)); 
bool first_2079 = true; 
int64_t sa_2080 = g400; 
g400 = i_2076;
{ int32_t _e7103 = ((*({ hrv *_t7104 = &(g703); int64_t _i7104 = node_2078; (S4*)_t7104->b + hr_ix(_i7104, _t7104->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1066"); }))).n_; for (int32_t _k7103 = 0; _k7103 < _e7103; _k7103++) { int32_t j_2081 = (int32_t)_k7103; int64_t p_2082 = f90_kid(node_2078, ((int64_t)(j_2081))); 
int64_t v_2083 = f157_rv(p_2082); 
if ((!(first_2079))) { (void)(f260_ow(hr_str(", ", 2)));
 }
first_2079 = false;
int64_t t_2084 = f208_ptype_of(i_2076, ((int64_t)(j_2081))); 
(void)(f261_ct(t_2084));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f286_lv_name(v_2083));
if (f268_is_res(t_2084)) { (void)(f260_ow(hr_str("_in", 3)));
 }
 } } _bk7102:; 
g400 = sa_2080;
{ hrv *_v7115 = &(g391); for (int64_t _k7115 = 0; _k7115 < _v7115->n; _k7115++) { S13 cp_2085 = ((S13*)_v7115->b)[_k7115]; if (((((int64_t)((cp_2085).inst_))) == (i_2076))) { if ((!(first_2079))) { (void)(f260_ow(hr_str(", ", 2)));
 }
first_2079 = false;
int64_t v_2086 = ((int64_t)((cp_2085).lv_)); 
(void)(f261_ct(((int64_t)(((*({ hrv *_t7118 = &(g388); int64_t _i7118 = v_2086; (S12*)_t7118->b + hr_ix(_i7118, _t7118->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1075"); }))).ty_))));
(void)(f260_ow(({ hsl _r7120; if (f285_lv_isptr(v_2086)) { _r7120 = hr_str(" **c", 4);  } else { _r7120 = hr_str(" *c", 3);  } _r7120; })));
(void)(f294_oi(v_2086));
 }
 } } _bk7114:; 
if (first_2079) { (void)(f260_ow(hr_str("void", 4)));
 }
(void)(f260_ow(hr_str(")", 1)));
}
static void hr_init_globals(void) {
g853 = ({ A25 _t1; _t1.e[0] = hr_str("import", 6); _t1.e[1] = hr_str("namespace", 9); _t1.e[2] = hr_str("struct", 6); _t1.e[3] = hr_str("enum", 4); _t1.e[4] = hr_str("type", 4); _t1.e[5] = hr_str("fn", 2); _t1.e[6] = hr_str("thread_fn", 9); _t1.e[7] = hr_str("export", 6); _t1.e[8] = hr_str("simd", 4); _t1.e[9] = hr_str("recursive", 9); _t1.e[10] = hr_str("let", 3); _t1.e[11] = hr_str("var", 3); _t1.e[12] = hr_str("extern", 6); _t1.e[13] = hr_str("const", 5); _t1.e[14] = hr_str("pad", 3); _t1.e[15] = hr_str("reusable", 8); _t1.e[16] = hr_str("if", 2); _t1.e[17] = hr_str("else", 4); _t1.e[18] = hr_str("while", 5); _t1.e[19] = hr_str("for", 3); _t1.e[20] = hr_str("in", 2); _t1.e[21] = hr_str("loop", 4); _t1.e[22] = hr_str("block", 5); _t1.e[23] = hr_str("guard", 5); _t1.e[24] = hr_str("match", 5); _t1.e[25] = hr_str("return", 6); _t1.e[26] = hr_str("break", 5); _t1.e[27] = hr_str("continue", 8); _t1.e[28] = hr_str("as", 2); _t1.e[29] = hr_str("true", 4); _t1.e[30] = hr_str("false", 5); _t1.e[31] = hr_str("null", 4); _t1.e[32] = hr_str("self", 4); _t1.e[33] = hr_str("bool", 4); _t1.e[34] = hr_str("varint", 6); _t1.e[35] = hr_str("i8", 2); _t1.e[36] = hr_str("i16", 3); _t1.e[37] = hr_str("i32", 3); _t1.e[38] = hr_str("i64", 3); _t1.e[39] = hr_str("u8", 2); _t1.e[40] = hr_str("u16", 3); _t1.e[41] = hr_str("u32", 3); _t1.e[42] = hr_str("u64", 3); _t1.e[43] = hr_str("f32", 3); _t1.e[44] = hr_str("f64", 3); _t1.e[45] = hr_str("int", 3); _t1.e[46] = hr_str("uint", 4); _t1.e[47] = hr_str("byte", 4); _t1.e[48] = hr_str("real", 4); _t1; });
g720 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g721 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g722 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g723 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g724 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g725 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g726 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g727 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g728 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g729 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g716 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g715 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g402 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g400 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g401 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g350 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g183 = ({ A62 _t2; _t2.e[0] = hr_str("int8_t", 6); _t2.e[1] = hr_str("int16_t", 7); _t2.e[2] = hr_str("int32_t", 7); _t2.e[3] = hr_str("int64_t", 7); _t2.e[4] = hr_str("uint8_t", 7); _t2.e[5] = hr_str("uint16_t", 8); _t2.e[6] = hr_str("uint32_t", 8); _t2.e[7] = hr_str("uint64_t", 8); _t2; });
g179 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g114 = ({ A101 _t3; _t3.e[0] = ((double)1e0); _t3.e[1] = ((double)1e1); _t3.e[2] = ((double)1e2); _t3.e[3] = ((double)1e3); _t3.e[4] = ((double)1e4); _t3.e[5] = ((double)1e5); _t3.e[6] = ((double)1e6); _t3.e[7] = ((double)1e7); _t3.e[8] = ((double)1e8); _t3.e[9] = ((double)1e9); _t3.e[10] = ((double)1e10); _t3.e[11] = ((double)1e11); _t3.e[12] = ((double)1e12); _t3.e[13] = ((double)1e13); _t3.e[14] = ((double)1e14); _t3.e[15] = ((double)1e15); _t3.e[16] = ((double)1e16); _t3.e[17] = ((double)1e17); _t3.e[18] = ((double)1e18); _t3.e[19] = ((double)1e19); _t3.e[20] = ((double)1e20); _t3.e[21] = ((double)1e21); _t3.e[22] = ((double)1e22); _t3; });
g154 = ((hrv){0});
g289 = ((int64_t)1LL);
g290 = ((int64_t)2LL);
g291 = ((int64_t)3LL);
g292 = ((int64_t)4LL);
g293 = ((int64_t)5LL);
g294 = ((int64_t)6LL);
g295 = ((int64_t)7LL);
g296 = ((int64_t)8LL);
g297 = ((int64_t)9LL);
g298 = ((int64_t)20LL);
g299 = ((int64_t)21LL);
g300 = ((int64_t)22LL);
g301 = ((int64_t)23LL);
g302 = ((int64_t)24LL);
g303 = ((int64_t)25LL);
g304 = ((int64_t)26LL);
g305 = ((int64_t)27LL);
g306 = ((int64_t)30LL);
g307 = ((int64_t)31LL);
g308 = ((int64_t)32LL);
g309 = ((int64_t)33LL);
g361 = ((int64_t)0LL);
g362 = ((int64_t)1LL);
g363 = ((int64_t)2LL);
g364 = ((int64_t)3LL);
g365 = ((int64_t)4LL);
g366 = ((int64_t)5LL);
g367 = ((int64_t)6LL);
g368 = ((int64_t)7LL);
g369 = ((int64_t)8LL);
g370 = ((int64_t)9LL);
g371 = ((int64_t)10LL);
g372 = ((int64_t)11LL);
g373 = ((int64_t)12LL);
g374 = ((int64_t)13LL);
g375 = ((int64_t)14LL);
g376 = ((int64_t)1LL);
g377 = ((int64_t)2LL);
g378 = ((int64_t)4LL);
g379 = ((int64_t)8LL);
g380 = ((int64_t)16LL);
g381 = ((int64_t)32LL);
g382 = ((int64_t)2LL);
g399 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g405 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g481 = ((int64_t)1LL);
g482 = ((int64_t)2LL);
g483 = ((int64_t)3LL);
g484 = ((int64_t)4LL);
g485 = ((int64_t)5LL);
g520 = ((int64_t)0LL);
g521 = ((int64_t)1LL);
g522 = ((int64_t)2LL);
g523 = ((int64_t)3LL);
g524 = ((int64_t)4LL);
g525 = ((int64_t)5LL);
g526 = ((int64_t)6LL);
g527 = ((int64_t)7LL);
g528 = ((int64_t)8LL);
g529 = ((int64_t)9LL);
g530 = ((int64_t)10LL);
g531 = ((int64_t)11LL);
g532 = ((int64_t)12LL);
g533 = ((int64_t)13LL);
g534 = ((int64_t)14LL);
g535 = ((int64_t)15LL);
g536 = ((int64_t)16LL);
g537 = ((int64_t)17LL);
g538 = ((int64_t)18LL);
g539 = ((int64_t)19LL);
g540 = ((int64_t)1LL);
g541 = ((int64_t)2LL);
g542 = ((int64_t)0LL);
g543 = ((int64_t)1LL);
g544 = ((int64_t)2LL);
g625 = ((int64_t)1LL);
g626 = ((int64_t)2LL);
g627 = ((int64_t)3LL);
g628 = ((int64_t)4LL);
g629 = ((int64_t)5LL);
g630 = ((int64_t)6LL);
g631 = ((int64_t)7LL);
g632 = ((int64_t)8LL);
g633 = ((int64_t)9LL);
g634 = ((int64_t)10LL);
g635 = ((int64_t)11LL);
g636 = ((int64_t)12LL);
g637 = ((int64_t)13LL);
g638 = ((int64_t)14LL);
g639 = ((int64_t)15LL);
g640 = ((int64_t)16LL);
g641 = ((int64_t)17LL);
g642 = ((int64_t)18LL);
g643 = ((int64_t)19LL);
g644 = ((int64_t)20LL);
g645 = ((int64_t)21LL);
g646 = ((int64_t)22LL);
g647 = ((int64_t)23LL);
g648 = ((int64_t)24LL);
g649 = ((int64_t)25LL);
g650 = ((int64_t)26LL);
g651 = ((int64_t)27LL);
g652 = ((int64_t)28LL);
g653 = ((int64_t)29LL);
g654 = ((int64_t)30LL);
g655 = ((int64_t)31LL);
g656 = ((int64_t)32LL);
g657 = ((int64_t)33LL);
g658 = ((int64_t)34LL);
g659 = ((int64_t)35LL);
g660 = ((int64_t)36LL);
g661 = ((int64_t)37LL);
g662 = ((int64_t)40LL);
g663 = ((int64_t)41LL);
g664 = ((int64_t)42LL);
g665 = ((int64_t)43LL);
g666 = ((int64_t)44LL);
g667 = ((int64_t)45LL);
g668 = ((int64_t)46LL);
g669 = ((int64_t)47LL);
g670 = ((int64_t)48LL);
g671 = ((int64_t)50LL);
g672 = ((int64_t)51LL);
g673 = ((int64_t)52LL);
g674 = ((int64_t)53LL);
g675 = ((int64_t)54LL);
g676 = ((int64_t)55LL);
g677 = ((int64_t)56LL);
g678 = ((int64_t)57LL);
g679 = ((int64_t)58LL);
g680 = ((int64_t)1LL);
g681 = ((int64_t)2LL);
g682 = ((int64_t)3LL);
g683 = ((int64_t)4LL);
g684 = ((int64_t)5LL);
g685 = ((int64_t)1LL);
g686 = ((int64_t)2LL);
g687 = ((int64_t)4LL);
g688 = ((int64_t)8LL);
g689 = ((int64_t)16LL);
g690 = ((int64_t)32LL);
g691 = ((int64_t)64LL);
g692 = ((int64_t)128LL);
g693 = ((int64_t)256LL);
g694 = ((int64_t)512LL);
g695 = ((int64_t)1LL);
g696 = ((int64_t)2LL);
g697 = ((int64_t)4LL);
g698 = ((int64_t)8LL);
g699 = ((int64_t)16LL);
g700 = ((int64_t)32LL);
g701 = ((int64_t)64LL);
g796 = ((int64_t)0LL);
g797 = ((int64_t)1LL);
g798 = ((int64_t)2LL);
g799 = ((int64_t)3LL);
g800 = ((int64_t)4LL);
g801 = ((int64_t)5LL);
g802 = ((int64_t)6LL);
g803 = ((int64_t)7LL);
g804 = ((int64_t)8LL);
g805 = ((int64_t)9LL);
g806 = ((int64_t)10LL);
g807 = ((int64_t)11LL);
g808 = ((int64_t)12LL);
g809 = ((int64_t)13LL);
g810 = ((int64_t)14LL);
g811 = ((int64_t)15LL);
g812 = ((int64_t)16LL);
g813 = ((int64_t)17LL);
g814 = ((int64_t)18LL);
g815 = ((int64_t)19LL);
g816 = ((int64_t)20LL);
g817 = ((int64_t)21LL);
g818 = ((int64_t)22LL);
g819 = ((int64_t)23LL);
g820 = ((int64_t)24LL);
g821 = ((int64_t)25LL);
g822 = ((int64_t)26LL);
g823 = ((int64_t)27LL);
g824 = ((int64_t)28LL);
g825 = ((int64_t)29LL);
g826 = ((int64_t)30LL);
g827 = ((int64_t)31LL);
g828 = ((int64_t)32LL);
g829 = ((int64_t)33LL);
g830 = ((int64_t)34LL);
g831 = ((int64_t)35LL);
g832 = ((int64_t)36LL);
g833 = ((int64_t)37LL);
g834 = ((int64_t)38LL);
g835 = ((int64_t)39LL);
g836 = ((int64_t)40LL);
g837 = ((int64_t)41LL);
g838 = ((int64_t)42LL);
g839 = ((int64_t)43LL);
g840 = ((int64_t)44LL);
g841 = ((int64_t)45LL);
g842 = ((int64_t)46LL);
g843 = ((int64_t)47LL);
g844 = ((int64_t)48LL);
g845 = ((int64_t)49LL);
g846 = ((int64_t)50LL);
g847 = ((int64_t)51LL);
g848 = ((int64_t)52LL);
g849 = ((int64_t)53LL);
g850 = ((int64_t)54LL);
g851 = ((int64_t)55LL);
g852 = ((int64_t)56LL);
g854 = ((int64_t)56LL);
g855 = ((int64_t)57LL);
g856 = ((int64_t)58LL);
g857 = ((int64_t)59LL);
g858 = ((int64_t)60LL);
g859 = ((int64_t)61LL);
g860 = ((int64_t)62LL);
g861 = ((int64_t)63LL);
g862 = ((int64_t)64LL);
g863 = ((int64_t)65LL);
g864 = ((int64_t)66LL);
g865 = ((int64_t)67LL);
g866 = ((int64_t)68LL);
g867 = ((int64_t)69LL);
g868 = ((int64_t)70LL);
g869 = ((int64_t)71LL);
g870 = ((int64_t)72LL);
g871 = ((int64_t)73LL);
g872 = ((int64_t)74LL);
g873 = ((int64_t)75LL);
g874 = ((int64_t)76LL);
g875 = ((int64_t)77LL);
g876 = ((int64_t)78LL);
g877 = ((int64_t)79LL);
g878 = ((int64_t)80LL);
g879 = ((int64_t)81LL);
g880 = ((int64_t)82LL);
g881 = ((int64_t)83LL);
g882 = ((int64_t)84LL);
g883 = ((int64_t)85LL);
g884 = ((int64_t)86LL);
g885 = ((int64_t)87LL);
g886 = ((int64_t)88LL);
g887 = ((int64_t)89LL);
g888 = ((int64_t)90LL);
g889 = ((int64_t)91LL);
g890 = ((int64_t)92LL);
g891 = ((int64_t)93LL);
g892 = ((int64_t)94LL);
g893 = ((int64_t)95LL);
g894 = ((int64_t)96LL);
g895 = ((int64_t)97LL);
g896 = ((int64_t)98LL);
g897 = ((int64_t)99LL);
g898 = ((int64_t)100LL);
g899 = ((int64_t)101LL);
g900 = ((int64_t)102LL);
g901 = ((int64_t)103LL);
g902 = ((int64_t)104LL);
g903 = ((int64_t)49LL);
}
static void hr_main(void) { f1_main(); }
