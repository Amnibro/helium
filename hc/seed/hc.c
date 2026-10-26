#include "hrt.h"
typedef struct A25 A25;
typedef struct A62 A62;
typedef struct A102 A102;
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
typedef struct L101 L101;
#pragma pack(push, 1)
struct A25 { hsl e[49]; };
struct A62 { hsl e[8]; };
struct A102 { double e[23]; };
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
struct L101 { uint16_t n; uint8_t e[4096]; };
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
static int64_t f208_ptype_of(int64_t i_1072, int64_t j_1073);
static bool f209_ends(int64_t n_1093);
static bool f210_has_break(int64_t n_1096);
static void f211_pop_block_fns(int64_t m_1104);
static int64_t f212_ck_if(int64_t n_1107, int64_t want_1108);
static int64_t f213_ck_while(int64_t n_1118);
static int64_t f214_ck_loop(int64_t n_1122, int64_t want_1123);
static int64_t f215_ck_for(int64_t n_1125);
static bool f216_is_bytes(int64_t t_1135);
static int64_t f217_ax(int64_t n_1139);
static int64_t f218_ck_match(int64_t n_1140, int64_t want_1141);
static int64_t f219_ck_ret(int64_t n_1174);
static int64_t f220_find_from_fn(int64_t name_1176);
static int64_t f221_ret_fn(void);
static int64_t f222_ck_break(int64_t n_1189);
static int64_t f223_ck_call(int64_t n_1193, int64_t want_1194);
static int64_t f224_find_nest(int64_t name_1200);
static int64_t f225_call_nested(int64_t n_1203, int64_t nf_1204);
static int64_t f226_ck_args(int64_t n_1206, int64_t a0n_1207, int64_t first_1208);
static void f227_pop_args(int64_t s_1215);
static void f228_note_caps_of(int64_t i_1216);
static void f229_note_edge(int64_t callee_1219);
static int64_t f230_block_binding(int64_t name_1221);
static int64_t f231_blk_gen(int64_t fnode_1225);
static int64_t f232_gen_list(int64_t fnode_1226);
static bool f233_is_blockparam(int64_t fnode_1230, int64_t gname_1231);
static bool f234_mentions(int64_t t_1234, int64_t g_1235);
static int64_t f235_call_block(int64_t n_1240, int64_t inst_1241);
static int64_t f236_deref_val(int64_t a_1248);
static int64_t f237_builtin_of(hsl name_1268);
static bool f238_user_format(int64_t n_1270);
static bool f239_is_grow(int64_t t_1272);
static int64_t f240_ck_builtin(int64_t n_1273, int64_t b_1274, int64_t recv_1275, int64_t want_1276);
static int64_t f241_arg(int64_t i_1279, int64_t *c1275, int64_t *c1273);
static void f242_hook_walk(int64_t t_1285);
static int64_t f243_hook_of(int64_t t_1289);
static M94 f244_resolve(int64_t n_1293, int64_t name_1294, int64_t ns_1295, int64_t a0_1296, int64_t an_1297, int64_t blk_1298, int64_t tyargs_1299, bool report_1300);
static void f245_cands_add(int64_t name_1302, int64_t ns_1303);
static bool f246_match_ty(int64_t tn0_1332, int64_t t0_1333, int64_t g0_1334);
static int64_t f247_pend_default(int64_t a_1347);
static int64_t f248_arg_rank(int64_t n_1360, int64_t a_1361, int64_t p_1362);
static bool f249_is_construct(int64_t n_1370);
static bool f250_untyped_any(int64_t f_1373);
static bool f251_is_std_node(int64_t node_1375);
static int64_t f252_get_inst(int64_t node_1386, int64_t b0_1387, int64_t bn_1388, int64_t blk_1389, int64_t bown_1390);
static bool f253_same_binds(int64_t i_1394, int64_t b0_1395, int64_t bn_1396);
static int64_t f254_call_fn(int64_t n_1432, int64_t name_1433, int64_t recv_1434, int64_t want_1435);
static int64_t f255_member_of(hsl name_1454);
static int64_t f256_ck_slit(int64_t n_1457, int64_t want_1458);
static bool f257_ORD_HAS(int64_t d_1482);
static void f258_propagate_calls(void);
static bool f259_gen_program(hrv* out_1494);
static void f260_ow(hsl s_1498);
static void f261_ct(int64_t t_1499);
static void f262_cbody(int64_t t_1500);
static void f263_cn_grow(void);
static hsl f264_cn(int64_t t_1503);
static void f265_cn_make(int64_t t_1504);
static void f266_fwd(int64_t s0_1513);
static void f267_fname_into(hrv* b_1525, int64_t name_1526);
static bool f268_is_res(int64_t t_1546);
static void f269_gxo(int64_t n_1547);
static void f270_gcv(int64_t n_1550, int64_t f_1551, int64_t t_1552);
static void f271_gx1(int64_t n_1553);
static bool f272_is_place(int64_t n_1554);
static int64_t f273_tmp(int64_t t_1559, bool clean_1560);
static void f274_ot(int64_t k_1562);
static void f275_gx0(int64_t n_1563);
static int64_t f276_fin_lit(int64_t n_1566);
static void f277_oint(int64_t v_1568, bool uns_1569, int64_t t_1570);
static void f278_gstr(int64_t n_1573);
static int64_t f279_fin(int64_t n_1574);
static hsl f280_tok_str(int64_t t_1578);
static void f281_cstr_lit(hsl s_1582);
static bool f282_is_fix(int64_t t_1584);
static bool f283_is_lim(int64_t t_1585);
static void f284_lv_expr(int64_t v_1587);
static bool f285_lv_isptr(int64_t v_1588);
static void f286_lv_name(int64_t v_1590);
static void f287_gerr(int64_t n_1592, hsl m_1593);
static void f288_gbin(int64_t n_1595);
static void f289_gx(int64_t n_1600);
static hsl f290_cmp_op(int64_t o_1607);
static void f291_gas(int64_t n_1608);
static void f292_gsl(int64_t n_1611, int64_t f_1612);
static int64_t f293_nt(void);
static void f294_oi(int64_t v_1616);
static void f295_gen_heq(int64_t t_1622);
static void f296_comp_pre(int64_t t_1626, bool fmt_1627);
static void f297_comp_one(int64_t t_1633, bool fmt_1634);
static bool f298_need_helper(int64_t t_1636);
static void f299_gen_hf(int64_t t_1638);
static void f300_hf_pre(int64_t t_1642);
static void f301_hh(hsl s_1645);
static void f302_fn_cname_to(hrv* b_1652, int64_t i_1653);
static void f303_hf_val(int64_t t_1664, hsl e_1665);
static void f304_heq_val(int64_t t_1708, hsl a_1709, hsl b_1710);
static bool f305_hsl_ty(int64_t t_1721);
static void f306_gxas(int64_t n_1722, int64_t t_1723);
static void f307_garith(int64_t o_1726, int64_t t0_1727, int64_t a_1728, int64_t b_1729, int64_t tv_1730, int64_t loc_1731);
static void f308_gopnd(int64_t n_1737, int64_t tv_1738);
static void f309_gen_hop(int64_t t_1739, int64_t o_1740, int64_t bt_1741);
static void f310_hop_body(int64_t t_1747, int64_t o_1748, hsl r_1749, hsl a_1750, hsl b_1751, bool sc_1752);
static hsl f311_ar_op(int64_t o_1754);
static void f312_wloc(int64_t n_1768);
static void f313_gun(int64_t n_1771);
static void f314_gen_hneg(int64_t t_1776);
static void f315_gidx(int64_t n_1790);
static void f316_gslice(int64_t n_1798);
static void f317_garr(int64_t n_1806);
static void f318_gslit(int64_t n_1813);
static void f319_gcall(int64_t n_1825);
static void f320_gbuiltin(int64_t n_1827);
static int64_t f321_arg(int64_t i_1833, int64_t *c1831, int64_t *c1827);
static void f322_gfmt(hsl o_1837, int64_t n_1838, int64_t t_1839, bool top_1840);
static void f323_fn_cname(int64_t i_1845);
static void f324_gaddr(int64_t n_1846);
static void f325_grecv_ptr(int64_t r_1856);
static void f326_esz(int64_t t_1870);
static void f327_gembed(int64_t n_1877, int64_t a_1878);
static void f328_heq_val_o(int64_t e_1888, int64_t p_1889);
static void f329_heq_o(int64_t e_1892, hsl a_1893, hsl b_1894);
static void f330_heq_pre(int64_t t_1895);
static bool f331_scalar_ty(int64_t t_1896);
static void f332_heq_val_s(int64_t e_1899, int64_t p_1900);
static void f333_heq_val_r(int64_t e_1903, int64_t p_1904);
static void f334_gblkcall(int64_t n_1907);
static void f335_gstmt(int64_t n_1919);
static void f336_gvdecl(int64_t n_1925);
static void f337_decl_lv(int64_t v_1933);
static void f338_gstmt1(int64_t n_1944);
static void f339_gassign(int64_t n_1947);
static int64_t f340_base_op(int64_t o_1960);
static void f341_gif(int64_t n_1963, int64_t res_1964);
static void f342_gblk(int64_t b_1968, int64_t res_1969, bool val_1970);
static void f343_gtail(int64_t tl_1972, int64_t res_1973);
static void f344_gwhile(int64_t n_1976);
static int64_t f345_lbl_push(int64_t res_1978);
static void f346_lbl_pop(int64_t l_1981);
static void f347_gloop(int64_t n_1982, int64_t res_1983);
static void f348_gfor(int64_t n_1985);
static void f349_gmatch(int64_t n_2000, int64_t res_2001);
static void f350_geblock(int64_t n_2023, int64_t res_2024);
static void f351_gret(int64_t n_2026);
static void f352_gmove(int64_t c_2032);
static bool f353_movable_local(int64_t c_2033);
static void f354_gdummy(void);
static void f355_gbreak(int64_t n_2044);
static bool f356_owned(int64_t n_2048);
static bool f357_is_ext(int64_t i_2052);
static void f358_ext_name(int64_t i_2057);
static void f359_gcall_args(int64_t n_2061, int64_t inst_2062, int64_t recv_2063);
static void f360_lv_addr(int64_t v_2075);
static void f361_glrcheck(void);
static void f362_gen_fn(int64_t i_2091);
static void f363_gsig(int64_t i_2094);
static hrv g493;
static hrv g911;
static A25 g854;
static hrv g912;
static hrv g909;
static int64_t g721;
static int64_t g722;
static int64_t g723;
static int64_t g724;
static int64_t g725;
static int64_t g726;
static int64_t g727;
static int64_t g728;
static int64_t g729;
static int64_t g730;
static hrv g551;
static int64_t g575;
static hrv g553;
static hrv g552;
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
static int64_t g574;
static int64_t g577;
static int64_t g578;
static int64_t g576;
static hrv g492;
static hrv g913;
static hrv g707;
static hrv g914;
static hrv g915;
static hrv g908;
static hrv g910;
static hrv g710;
static int64_t g709;
static int64_t g717;
static int64_t g716;
static int64_t g711;
static bool g712;
static hrv g704;
static hrv g706;
static bool g756;
static hrv g718;
static hrv g705;
static bool g713;
static bool g714;
static bool g715;
static hrv g719;
static hrv g708;
static hrv g495;
static hrv g496;
static hrv g490;
static hrv g489;
static hrv g494;
static int64_t g403;
static hrv g388;
static hrv g395;
static hrv g394;
static hrv g396;
static hrv g397;
static hrv g398;
static hrv g399;
static int64_t g401;
static int64_t g402;
static int64_t g405;
static hrv g404;
static hrv g450;
static hrv g451;
static hrv g556;
static hrv g557;
static hrv g554;
static hrv g491;
static hrv g555;
static hrv g436;
static hrv g390;
static hrv g389;
static hrv g392;
static hrv g437;
static hrv g391;
static hrv g312;
static int64_t g407;
static hrv g468;
static hrv g408;
static hrv g316;
static hrv g393;
static hrv g349;
static hrv g350;
static int64_t g351;
static hrv g313;
static hrv g314;
static hrv g409;
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
static A102 g114;
static hrv g154;
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
static int64_t g310;
static hrv g315;
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
static int64_t g383;
static int64_t g400;
static int64_t g406;
static int64_t g482;
static int64_t g483;
static int64_t g484;
static int64_t g485;
static int64_t g486;
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
static int64_t g545;
static int64_t g618;
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
static int64_t g702;
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
static int64_t g853;
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
static int64_t g904;
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
(void)(({ hrv *_v15 = &(g493); hsl _s15 = hr_sl(lib_2); hr_append(_v15, _s15.p, _s15.n, sizeof(uint8_t)); }));
if ((!(f5_load_program(hr_sl(a_0))))) { (void)(({ hr_fs(&hr_ob, hr_sl(g495)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((!(f104_check_program()))) { (void)(({ hr_fs(&hr_ob, hr_sl(g404)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((((g495).n) > (((int64_t)0LL)))) { (void)(({ hr_fs(&hr_ob, hr_sl(g495)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
hrv c_1493 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(f259_gen_program((&(c_1493)))))) { (void)(({ hr_fs(&hr_ob, hr_sl(g182)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((!(hr_os_write_file(hr_sl(o_1), hr_sl(c_1493))))) { (void)(({ hr_fs(&hr_ob, hr_str("cannot write ", 13)); hr_fs(&hr_ob, hr_sl(o_1)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
}
static bool f5_load_program(hsl root_3) {
(void)(f6_parse_init());
(void)(f11_types_init());
int64_t d_38 = (root_3).n; 
while ((((d_38) > (((int64_t)0LL))) && (((*({ hsl _t34 = root_3; int64_t _i34 = ((int64_t)((int64_t)d_38 - (int64_t)((int64_t)1LL))); (uint8_t*)_t34.p + hr_ix(_i34, _t34.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:68"); }))) != (((uint8_t)47LL))))) { d_38--;
 } _bk33:; 
(void)(({ hrv *_v35 = &(g492); _v35->n = 0; }));
(void)(({ hrv *_v36 = &(g492); hsl _s36 = ({ hsl _r37; if (((d_38) > (((int64_t)0LL)))) { _r37 = ({ hsl _t38 = root_3; int64_t _l38 = 0, _h38 = ((int64_t)((int64_t)d_38 - (int64_t)((int64_t)1LL))); if (_l38 < 0 || _h38 < _l38 || _h38 > _t38.n) hr_slerr(_l38, _h38, _t38.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:69"); (hsl){ _t38.p + _l38 * (int64_t)sizeof(uint8_t), _h38 - _l38 }; });  } else { _r37 = hr_str(".", 1);  } _r37; }); hr_append(_v36, _s36.p, _s36.n, sizeof(uint8_t)); }));
return (((f19_try_load(root_3)) >= (((int64_t)0LL))) && (((g495).n) == (((int64_t)0LL))));
}
static void f6_parse_init(void) {
(void)(f7_lex_init());
if (((g721) < (((int64_t)0LL)))) { g721 = f8_intern(hr_str("from", 4));
g722 = f8_intern(hr_str("inline", 6));
g723 = f8_intern(hr_str("checkfree", 9));
g724 = f8_intern(hr_str("lut", 3));
g725 = f8_intern(hr_str("_", 1));
g726 = f8_intern(hr_str("upto", 4));
g727 = f8_intern(hr_str("fields", 6));
g728 = f8_intern(hr_str("types", 5));
g729 = f8_intern(hr_str("variants", 8));
g730 = f8_intern(hr_str("std", 3));
 }
}
static void f7_lex_init(void) {
if ((((g911).n) == (((int64_t)0LL)))) { { hsl _v52 = ({ A25 *_t53 = &(g854); (hsl){ (uint8_t*)_t53->e, 49 }; }); for (int64_t _k52 = 0; _k52 < _v52.n; _k52++) { hsl k_4 = ((hsl*)_v52.p)[_k52]; (void)(f8_intern(k_4));
 } } _bk51:; 
 }
}
static int64_t f8_intern(hsl s_5) {
if ((((g912).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v55 = &(g912); int64_t _k55 = ((int64_t)((((int64_t)1LL)) << ((((int64_t)16LL)) & 63))); if (_k55 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:32"); int32_t _x55 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o55 = _v55->n; hr_resize(_v55, _k55, sizeof _x55); for (int64_t _j = _o55; _j < _k55; _j++) ((int32_t*)_v55->b)[_j] = _x55; }));
 }
if (((((int64_t)((int64_t)(g911).n * (int64_t)((int64_t)2LL)))) >= ((g912).n))) { int64_t n_6 = ((int64_t)((int64_t)(g912).n * (int64_t)((int64_t)2LL))); 
(void)(({ hrv *_v56 = &(g912); _v56->n = 0; }));
(void)(({ hrv *_v57 = &(g912); int64_t _k57 = n_6; if (_k57 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:35"); int32_t _x57 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o57 = _v57->n; hr_resize(_v57, _k57, sizeof _x57); for (int64_t _j = _o57; _j < _k57; _j++) ((int32_t*)_v57->b)[_j] = _x57; }));
{ hrv *_v59 = &(g911); for (int64_t _k59 = 0; _k59 < _v59->n; _k59++) { S0 x_7 = ((S0*)_v59->b)[_k59]; int64_t i_8 = (int64_t)_k59; int64_t j_12 = ((int64_t)((int64_t)((int64_t)(f9_hash(({ hsl _t61 = hr_sl(g909); int64_t _l61 = ((int64_t)((x_7).s_)), _h61 = ((int64_t)(((int32_t)((int64_t)(x_7).s_ + (int64_t)(x_7).n_)))); if (_l61 < 0 || _h61 < _l61 || _h61 > _t61.n) hr_slerr(_l61, _h61, _t61.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:36"); (hsl){ _t61.p + _l61 * (int64_t)sizeof(uint8_t), _h61 - _l61 }; })))) & (int64_t)((int64_t)((int64_t)n_6 - (int64_t)((int64_t)1LL))))); 
while ((((*({ hrv *_t63 = &(g912); int64_t _i63 = j_12; (int32_t*)_t63->b + hr_ix(_i63, _t63->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:36"); }))) >= (((int32_t)0LL)))) { j_12 = ((int64_t)((int64_t)((int64_t)((int64_t)j_12 + (int64_t)((int64_t)1LL))) & (int64_t)((int64_t)((int64_t)n_6 - (int64_t)((int64_t)1LL)))));
 } _bk62:; 
{ int32_t *_t64 = &((*({ hrv *_t65 = &(g912); int64_t _i65 = j_12; (int32_t*)_t65->b + hr_ix(_i65, _t65->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:36"); }))); *_t64 = ((int32_t)(i_8)); }
 } } _bk58:; 
 }
int64_t m_13 = ((int64_t)((int64_t)(g912).n - (int64_t)((int64_t)1LL))); 
int64_t j_14 = ((int64_t)((int64_t)((int64_t)(f9_hash(s_5))) & (int64_t)m_13)); 
while ((((*({ hrv *_t68 = &(g912); int64_t _i68 = j_14; (int32_t*)_t68->b + hr_ix(_i68, _t68->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:40"); }))) >= (((int32_t)0LL)))) { if (hr_streq(f10_nm(((int64_t)((*({ hrv *_t70 = &(g912); int64_t _i70 = j_14; (int32_t*)_t70->b + hr_ix(_i70, _t70->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:40"); }))))), s_5)) { return ((int64_t)((*({ hrv *_t71 = &(g912); int64_t _i71 = j_14; (int32_t*)_t71->b + hr_ix(_i71, _t71->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:40"); }))));
 }
j_14 = ((int64_t)((int64_t)((int64_t)((int64_t)j_14 + (int64_t)((int64_t)1LL))) & (int64_t)m_13));
 } _bk67:; 
int64_t id_17 = (g911).n; 
(void)(({ hrv *_v72 = &(g911); S0 _x72 = ((S0){ .s_ = ((int32_t)((g909).n)), .n_ = ((int32_t)((s_5).n)), }); S0 *_p72 = (S0*)hr_grow(_v72, 1, sizeof _x72); *_p72 = _x72; _p72; }));
(void)(({ hrv *_v73 = &(g909); hsl _s73 = s_5; hr_append(_v73, _s73.p, _s73.n, sizeof(uint8_t)); }));
{ int32_t *_t74 = &((*({ hrv *_t75 = &(g912); int64_t _i75 = j_14; (int32_t*)_t75->b + hr_ix(_i75, _t75->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:44"); }))); *_t74 = ((int32_t)(id_17)); }
return id_17;
}
static uint64_t f9_hash(hsl s_9) {
uint64_t h_10 = ((uint64_t)1469598103934665603LL); 
{ hsl _v77 = s_9; for (int64_t _k77 = 0; _k77 < _v77.n; _k77++) { uint8_t c_11 = ((uint8_t*)_v77.p)[_k77]; h_10 = ((uint64_t)((uint64_t)((uint64_t)((uint64_t)h_10 ^ (uint64_t)((uint64_t)(c_11)))) * (uint64_t)((uint64_t)1099511628211LL)));
 } } _bk76:; 
return h_10;
}
static hsl f10_nm(int64_t id_15) {
S0 x_16 = (*({ hrv *_t78 = &(g911); int64_t _i78 = id_15; (S0*)_t78->b + hr_ix(_i78, _t78->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:29"); })); 
return ({ hsl _t79 = hr_sl(g909); int64_t _l79 = ((int64_t)((x_16).s_)), _h79 = ((int64_t)(((int32_t)((int64_t)(x_16).s_ + (int64_t)(x_16).n_)))); if (_l79 < 0 || _h79 < _l79 || _h79 > _t79.n) hr_slerr(_l79, _h79, _t79.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:29"); (hsl){ _t79.p + _l79 * (int64_t)sizeof(uint8_t), _h79 - _l79 }; });
}
static void f11_types_init(void) {
if ((((g551).n) > (((int64_t)0LL)))) { return;
 }
g575 = f12_tsimple(((int64_t)0LL), ((int64_t)0LL));
g558 = f12_tsimple(((int64_t)1LL), ((int64_t)0LL));
g559 = f12_tsimple(((int64_t)2LL), ((int64_t)0LL));
g560 = f17_t_int(((int64_t)0LL));
g561 = f17_t_int(((int64_t)1LL));
g562 = f17_t_int(((int64_t)2LL));
g563 = f17_t_int(((int64_t)3LL));
g564 = f17_t_int(((int64_t)4LL));
g565 = f17_t_int(((int64_t)5LL));
g566 = f17_t_int(((int64_t)6LL));
g567 = f17_t_int(((int64_t)7LL));
g568 = f12_tsimple(((int64_t)4LL), ((int64_t)4LL));
g569 = f12_tsimple(((int64_t)4LL), ((int64_t)8LL));
g570 = f12_tsimple(((int64_t)11LL), ((int64_t)0LL));
g571 = f12_tsimple(((int64_t)12LL), ((int64_t)0LL));
g572 = f12_tsimple(((int64_t)13LL), ((int64_t)0LL));
g573 = f12_tsimple(((int64_t)18LL), ((int64_t)0LL));
g574 = f12_tsimple(((int64_t)17LL), ((int64_t)0LL));
g577 = f12_tsimple(((int64_t)19LL), ((int64_t)0LL));
g578 = f12_tsimple(((int64_t)15LL), ((int64_t)0LL));
g576 = f18_t_slice(g564, true);
}
static int64_t f12_tsimple(int64_t k_18, int64_t s_19) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(k_18)), .s_ = ((uint8_t)(s_19)), .a_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f13_tmk(S1 t_20) {
if ((((g553).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v102 = &(g553); int64_t _k102 = ((int64_t)((((int64_t)1LL)) << ((((int64_t)14LL)) & 63))); if (_k102 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:27"); int32_t _x102 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o102 = _v102->n; hr_resize(_v102, _k102, sizeof _x102); for (int64_t _j = _o102; _j < _k102; _j++) ((int32_t*)_v102->b)[_j] = _x102; }));
 }
if (((((int64_t)((int64_t)(g551).n * (int64_t)((int64_t)2LL)))) >= ((g553).n))) { int64_t n_21 = ((int64_t)((int64_t)(g553).n * (int64_t)((int64_t)2LL))); 
(void)(({ hrv *_v103 = &(g553); _v103->n = 0; }));
(void)(({ hrv *_v104 = &(g553); int64_t _k104 = n_21; if (_k104 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:29"); int32_t _x104 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o104 = _v104->n; hr_resize(_v104, _k104, sizeof _x104); for (int64_t _j = _o104; _j < _k104; _j++) ((int32_t*)_v104->b)[_j] = _x104; }));
{ hrv *_v106 = &(g551); for (int64_t _k106 = 0; _k106 < _v106->n; _k106++) { S1 x_22 = ((S1*)_v106->b)[_k106]; int64_t i_23 = (int64_t)_k106; int64_t j_29 = ((int64_t)((int64_t)((int64_t)(f14_th(x_22))) & (int64_t)((int64_t)((int64_t)n_21 - (int64_t)((int64_t)1LL))))); 
while ((((*({ hrv *_t109 = &(g553); int64_t _i109 = j_29; (int32_t*)_t109->b + hr_ix(_i109, _t109->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:30"); }))) >= (((int32_t)0LL)))) { j_29 = ((int64_t)((int64_t)((int64_t)((int64_t)j_29 + (int64_t)((int64_t)1LL))) & (int64_t)((int64_t)((int64_t)n_21 - (int64_t)((int64_t)1LL)))));
 } _bk108:; 
{ int32_t *_t110 = &((*({ hrv *_t111 = &(g553); int64_t _i111 = j_29; (int32_t*)_t111->b + hr_ix(_i111, _t111->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:30"); }))); *_t110 = ((int32_t)(i_23)); }
 } } _bk105:; 
 }
int64_t m_30 = ((int64_t)((int64_t)(g553).n - (int64_t)((int64_t)1LL))); 
int64_t j_31 = ((int64_t)((int64_t)((int64_t)(f14_th(t_20))) & (int64_t)m_30)); 
while ((((*({ hrv *_t114 = &(g553); int64_t _i114 = j_31; (int32_t*)_t114->b + hr_ix(_i114, _t114->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); }))) >= (((int32_t)0LL)))) { if (f16_teq((*({ hrv *_t116 = &(g551); int64_t _i116 = (*({ hrv *_t117 = &(g553); int64_t _i117 = j_31; (int32_t*)_t117->b + hr_ix(_i117, _t117->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); })); (S1*)_t116->b + hr_ix(_i116, _t116->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); })), t_20)) { return ((int64_t)((*({ hrv *_t118 = &(g553); int64_t _i118 = j_31; (int32_t*)_t118->b + hr_ix(_i118, _t118->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); }))));
 }
j_31 = ((int64_t)((int64_t)((int64_t)((int64_t)j_31 + (int64_t)((int64_t)1LL))) & (int64_t)m_30));
 } _bk113:; 
(void)(({ hrv *_v119 = &(g551); S1 _x119 = t_20; S1 *_p119 = (S1*)hr_grow(_v119, 1, sizeof _x119); *_p119 = _x119; _p119; }));
{ int32_t *_t120 = &((*({ hrv *_t121 = &(g553); int64_t _i121 = j_31; (int32_t*)_t121->b + hr_ix(_i121, _t121->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:35"); }))); *_t120 = ((int32_t)(((int64_t)((int64_t)(g551).n - (int64_t)((int64_t)1LL))))); }
return ((int64_t)((int64_t)(g551).n - (int64_t)((int64_t)1LL)));
}
static uint64_t f14_th(S1 t_24) {
uint64_t h_27 = f15_hash_mix(((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((t_24).k_)) | (uint64_t)((uint64_t)((((uint64_t)((t_24).s_))) << ((((uint64_t)8LL)) & 63))))) | (uint64_t)((uint64_t)((((uint64_t)((t_24).fl_))) << ((((uint64_t)16LL)) & 63))))) | (uint64_t)((uint64_t)((((uint64_t)((t_24).a_))) << ((((uint64_t)32LL)) & 63)))))); 
h_27 = f15_hash_mix(((uint64_t)((uint64_t)((uint64_t)((uint64_t)h_27 ^ (uint64_t)((uint64_t)((t_24).c_)))) ^ (uint64_t)((uint64_t)((((uint64_t)((t_24).b_))) << ((((uint64_t)20LL)) & 63))))));
{ int32_t _e125 = (t_24).n_; for (int32_t _k125 = 0; _k125 < _e125; _k125++) { int32_t i_28 = (int32_t)_k125; h_27 = f15_hash_mix(((uint64_t)((uint64_t)h_27 ^ (uint64_t)((uint64_t)((*({ hrv *_t127 = &(g552); int64_t _i127 = ((int64_t)((int64_t)((int64_t)((t_24).l_)) + (int64_t)((int64_t)(i_28)))); (int32_t*)_t127->b + hr_ix(_i127, _t127->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:20"); })))))));
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
{ int32_t _e129 = (x_32).n_; for (int32_t _k129 = 0; _k129 < _e129; _k129++) { int32_t i_34 = (int32_t)_k129; if ((((*({ hrv *_t130 = &(g552); int64_t _i130 = ((int64_t)((int64_t)((int64_t)((x_32).l_)) + (int64_t)((int64_t)(i_34)))); (int32_t*)_t130->b + hr_ix(_i130, _t130->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:23"); }))) != ((*({ hrv *_t131 = &(g552); int64_t _i131 = ((int64_t)((int64_t)((int64_t)((y_33).l_)) + (int64_t)((int64_t)(i_34)))); (int32_t*)_t131->b + hr_ix(_i131, _t131->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:23"); }))))) { return false;
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
{ hrv *_v136 = &(g913); for (int64_t _k136 = 0; _k136 < _v136->n; _k136++) { S2 f_41 = ((S2*)_v136->b)[_k136]; int64_t i_42 = (int64_t)_k136; if (((((int64_t)((f_41).name_))) == (id_40))) { return i_42;
 }
 } } _bk135:; 
if ((!(hr_os_file_exists(path_39)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t t0_43 = (g707).n; 
if ((!(f21_parse_file(path_39)))) { (void)(({ hrv *_v139 = &(g495); hsl _s139 = hr_sl(g710); hr_append(_v139, _s139.p, _s139.n, sizeof(uint8_t)); }));
return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
int64_t f_439 = ((int64_t)((int64_t)(g913).n - (int64_t)((int64_t)1LL))); 
while ((((g496).n) < ((g913).n))) { (void)(({ hrv *_v141 = &(g496); int32_t _x141 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p141 = (int32_t*)hr_grow(_v141, 1, sizeof _x141); *_p141 = _x141; _p141; }));
 } _bk140:; 
{ int32_t *_t142 = &((*({ hrv *_t143 = &(g496); int64_t _i143 = f_439; (int32_t*)_t143->b + hr_ix(_i143, _t143->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:45"); }))); *_t142 = (*({ hrv *_t144 = &(g708); int64_t _i144 = ((int64_t)((int64_t)(g708).n - (int64_t)((int64_t)1LL))); (int32_t*)_t144->b + hr_ix(_i144, _t144->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:45"); })); }
(void)(f97_collect(f_439, t0_43, (g707).n));
int64_t t1_455 = (g707).n; 
int64_t im0_456 = (g494).n; 
{ int64_t _e147 = t1_455; for (int64_t _k147 = t0_43; _k147 < _e147; _k147++) { int64_t i_457 = (int64_t)_k147; if (((((*({ hrv *_t148 = &(g704); int64_t _i148 = (*({ hrv *_t149 = &(g707); int64_t _i149 = i_457; (int32_t*)_t149->b + hr_ix(_i149, _t149->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:49"); })); (S4*)_t148->b + hr_ix(_i148, _t148->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:49"); }))).k_) == (((uint8_t)54LL)))) { (void)(({ hrv *_v150 = &(g494); int32_t _x150 = (*({ hrv *_t151 = &(g707); int64_t _i151 = i_457; (int32_t*)_t151->b + hr_ix(_i151, _t151->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:49"); })); int32_t *_p150 = (int32_t*)hr_grow(_v150, 1, sizeof _x150); *_p150 = _x150; _p150; }));
 }
 } } _bk146:; 
int64_t im1_458 = (g494).n; 
L49 sp_461 = f100_lib_path(hr_str("std", 3)); 
bool isstd_462 = hr_streq(path_39, ({ hsl _t153 = ({ L49 *_t154 = &(sp_461); (hsl){ (uint8_t*)_t154->e, _t154->n }; }); int64_t _l153 = 0, _h153 = _t153.n; if (_l153 < 0 || _h153 < _l153 || _h153 > _t153.n) hr_slerr(_l153, _h153, _t153.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:51"); (hsl){ _t153.p + _l153 * (int64_t)sizeof(uint8_t), _h153 - _l153 }; })); 
if ((((*({ hrv *_t155 = &(g913); int64_t _i155 = f_439; (S2*)_t155->b + hr_ix(_i155, _t155->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:52"); }))).amni_ && (!(isstd_462)))) { if (((f101_load_import(g730, f_439, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
 }
{ int64_t _e158 = im1_458; for (int64_t _k158 = im0_456; _k158 < _e158; _k158++) { int64_t q_475 = (int64_t)_k158; int64_t n_476 = ((int64_t)((*({ hrv *_t159 = &(g494); int64_t _i159 = q_475; (int32_t*)_t159->b + hr_ix(_i159, _t159->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:53"); })))); 
if (((f101_load_import(((int64_t)(((*({ hrv *_t161 = &(g704); int64_t _i161 = n_476; (S4*)_t161->b + hr_ix(_i161, _t161->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:53"); }))).s_)), f_439, ((int64_t)(((*({ hrv *_t162 = &(g704); int64_t _i162 = n_476; (S4*)_t162->b + hr_ix(_i162, _t162->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:53"); }))).t_)))) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
 } } _bk157:; 
return f_439;
}
static bool f21_parse_file(hsl path_44) {
(void)(f6_parse_init());
int64_t t0_45 = (g914).n; 
if ((!(f22_lex_file(path_44)))) { (void)(({ hrv *_v165 = &(g710); hsl _s165 = hr_sl(g915); hr_append(_v165, _s165.p, _s165.n, sizeof(uint8_t)); }));
return false;
 }
g709 = t0_45;
g717 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
while ((((f31_tk()) != (((int64_t)0LL))) && (((g710).n) == (((int64_t)0LL))))) { (void)(f32_ptop());
 } _bk166:; 
(void)(({ hrv *_v169 = &(g708); int32_t _x169 = ((int32_t)(g717)); int32_t *_p169 = (int32_t*)hr_grow(_v169, 1, sizeof _x169); *_p169 = _x169; _p169; }));
return (((g710).n) == (((int64_t)0LL)));
}
static bool f22_lex_file(hsl path_46) {
(void)(f7_lex_init());
hrv body_47 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(hr_os_read_file(path_46, (&(body_47)))))) { (void)(({ hrv *_v173 = &(g915); hsl _s173 = hr_str("cannot read ", 12); hr_append(_v173, _s173.p, _s173.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v174 = &(g915); hsl _s174 = path_46; hr_append(_v174, _s174.p, _s174.n, sizeof(uint8_t)); }));
return false;
 }
int64_t f_48 = (g913).n; 
int64_t base_49 = (g908).n; 
int64_t skip_50 = ({ int64_t _r175; if (((((((body_47).n) >= (((int64_t)3LL))) && (((*({ hrv *_t176 = &(body_47); int64_t _i176 = ((int64_t)0LL); (uint8_t*)_t176->b + hr_ix(_i176, _t176->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:69"); }))) == (((uint8_t)239LL)))) && (((*({ hrv *_t177 = &(body_47); int64_t _i177 = ((int64_t)1LL); (uint8_t*)_t177->b + hr_ix(_i177, _t177->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:69"); }))) == (((uint8_t)187LL)))) && (((*({ hrv *_t178 = &(body_47); int64_t _i178 = ((int64_t)2LL); (uint8_t*)_t178->b + hr_ix(_i178, _t178->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:69"); }))) == (((uint8_t)191LL))))) { _r175 = ((int64_t)3LL);  } else { _r175 = ((int64_t)0LL);  } _r175; }); 
(void)(({ hrv *_v179 = &(g908); hsl _s179 = ({ hsl _t180 = hr_sl(body_47); int64_t _l180 = skip_50, _h180 = _t180.n; if (_l180 < 0 || _h180 < _l180 || _h180 > _t180.n) hr_slerr(_l180, _h180, _t180.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:70"); (hsl){ _t180.p + _l180 * (int64_t)sizeof(uint8_t), _h180 - _l180 }; }); hr_append(_v179, _s179.p, _s179.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v181 = &(g908); uint8_t _x181 = ((uint8_t)0LL); uint8_t *_p181 = (uint8_t*)hr_grow(_v181, 1, sizeof _x181); *_p181 = _x181; _p181; }));
(void)(({ hrv *_v182 = &(g908); uint8_t _x182 = ((uint8_t)0LL); uint8_t *_p182 = (uint8_t*)hr_grow(_v182, 1, sizeof _x182); *_p182 = _x182; _p182; }));
(void)(({ hrv *_v183 = &(g908); uint8_t _x183 = ((uint8_t)0LL); uint8_t *_p183 = (uint8_t*)hr_grow(_v183, 1, sizeof _x183); *_p183 = _x183; _p183; }));
(void)(({ hrv *_v184 = &(g908); uint8_t _x184 = ((uint8_t)0LL); uint8_t *_p184 = (uint8_t*)hr_grow(_v184, 1, sizeof _x184); *_p184 = _x184; _p184; }));
(void)(({ hrv *_v185 = &(g913); S2 _x185 = ((S2){ .s_ = ((int32_t)(base_49)), .n_ = ((int32_t)(((int64_t)((int64_t)(body_47).n - (int64_t)skip_50)))), .name_ = ((int32_t)(f8_intern(path_46))), .amni_ = ((((path_46).n) > (((int64_t)5LL))) && hr_streq(({ hsl _t187 = path_46; int64_t _l187 = _t187.n - ((int64_t)5LL), _h187 = _t187.n; if (_l187 < 0 || _h187 < _l187 || _h187 > _t187.n) hr_slerr(_l187, _h187, _t187.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:71"); (hsl){ _t187.p + _l187 * (int64_t)sizeof(uint8_t), _h187 - _l187 }; }), hr_str(".amni", 5))), }); S2 *_p185 = (S2*)hr_grow(_v185, 1, sizeof _x185); *_p185 = _x185; _p185; }));
bool amni_51 = ((*({ hrv *_t188 = &(g913); int64_t _i188 = f_48; (S2*)_t188->b + hr_ix(_i188, _t188->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:72"); }))).amni_; 
int64_t p_52 = base_49; 
int64_t line_53 = ((int64_t)1LL); 

for (;;) { uint8_t c_57 = (*({ hrv *_t190 = &(g908); int64_t _i190 = p_52; (uint8_t*)_t190->b + hr_ix(_i190, _t190->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:77"); })); 
while ((((((c_57) == (((uint8_t)32LL))) || ((c_57) == (((uint8_t)9LL)))) || ((c_57) == (((uint8_t)13LL)))) || ((c_57) == (((uint8_t)10LL))))) { if (((c_57) == (((uint8_t)10LL)))) { line_53++;
 }
p_52++;
c_57 = (*({ hrv *_t192 = &(g908); int64_t _i192 = p_52; (uint8_t*)_t192->b + hr_ix(_i192, _t192->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:78"); }));
 } _bk191:; 
if ((((c_57) == (((uint8_t)47LL))) && (((*({ hrv *_t193 = &(g908); int64_t _i193 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t193->b + hr_ix(_i193, _t193->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:79"); }))) == (((uint8_t)47LL))))) { while (((((*({ hrv *_t195 = &(g908); int64_t _i195 = p_52; (uint8_t*)_t195->b + hr_ix(_i195, _t195->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:79"); }))) != (((uint8_t)10LL))) && (((*({ hrv *_t196 = &(g908); int64_t _i196 = p_52; (uint8_t*)_t196->b + hr_ix(_i196, _t196->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:79"); }))) != (((uint8_t)0LL))))) { p_52++;
 } _bk194:; 
continue;
 }
if ((((c_57) == (((uint8_t)47LL))) && (((*({ hrv *_t197 = &(g908); int64_t _i197 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t197->b + hr_ix(_i197, _t197->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:80"); }))) == (((uint8_t)42LL))))) { { int64_t *_t198 = &(p_52); *_t198 = ((int64_t)((int64_t)(*_t198) + (int64_t)((int64_t)2LL))); }
int64_t nest_58 = ((int64_t)1LL); 
while (((nest_58) > (((int64_t)0LL)))) { uint8_t d_59 = (*({ hrv *_t200 = &(g908); int64_t _i200 = p_52; (uint8_t*)_t200->b + hr_ix(_i200, _t200->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:82"); })); 
if (((d_59) == (((uint8_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("unterminated /* comment", 23));
 }
if (((d_59) == (((uint8_t)10LL)))) { line_53++;
 }
if ((((d_59) == (((uint8_t)42LL))) && (((*({ hrv *_t202 = &(g908); int64_t _i202 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t202->b + hr_ix(_i202, _t202->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:82"); }))) == (((uint8_t)47LL))))) { nest_58--;
p_52++;
 } else { if ((((d_59) == (((uint8_t)47LL))) && (((*({ hrv *_t203 = &(g908); int64_t _i203 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t203->b + hr_ix(_i203, _t203->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:82"); }))) == (((uint8_t)42LL))))) { nest_58++;
p_52++;
 }
 }
p_52++;
 } _bk199:; 
continue;
 }
int64_t s_63 = p_52; 
uint8_t n1_64 = (*({ hrv *_t204 = &(g908); int64_t _i204 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t204->b + hr_ix(_i204, _t204->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:86"); })); 
uint8_t n2_65 = (*({ hrv *_t205 = &(g908); int64_t _i205 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t205->b + hr_ix(_i205, _t205->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:86"); })); 
if (((c_57) == (((uint8_t)0LL)))) { (void)(f23_put(((int64_t)0LL), s_63, s_63, &f_48, &line_53));
return true;
 }
if (f26_dig(c_57)) { if ((((c_57) == (((uint8_t)48LL))) && (((n1_64) == (((uint8_t)120LL))) || ((n1_64) == (((uint8_t)88LL)))))) { { int64_t *_t208 = &(p_52); *_t208 = ((int64_t)((int64_t)(*_t208) + (int64_t)((int64_t)2LL))); }
int64_t ds_67 = p_52; 
while (f27_hexd((*({ hrv *_t211 = &(g908); int64_t _i211 = p_52; (uint8_t*)_t211->b + hr_ix(_i211, _t211->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:90"); })))) { p_52++;
 } _bk209:; 
bool hf_69 = false; 
if (((((*({ hrv *_t212 = &(g908); int64_t _i212 = p_52; (uint8_t*)_t212->b + hr_ix(_i212, _t212->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:92"); }))) == (((uint8_t)46LL))) && f27_hexd((*({ hrv *_t214 = &(g908); int64_t _i214 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t214->b + hr_ix(_i214, _t214->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:92"); }))))) { hf_69 = true;
p_52++;
while (f27_hexd((*({ hrv *_t217 = &(g908); int64_t _i217 = p_52; (uint8_t*)_t217->b + hr_ix(_i217, _t217->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:92"); })))) { p_52++;
 } _bk215:; 
 }
if (((((*({ hrv *_t218 = &(g908); int64_t _i218 = p_52; (uint8_t*)_t218->b + hr_ix(_i218, _t218->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)112LL))) || (((*({ hrv *_t219 = &(g908); int64_t _i219 = p_52; (uint8_t*)_t219->b + hr_ix(_i219, _t219->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)80LL))))) { hf_69 = true;
p_52++;
if (((((*({ hrv *_t220 = &(g908); int64_t _i220 = p_52; (uint8_t*)_t220->b + hr_ix(_i220, _t220->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)43LL))) || (((*({ hrv *_t221 = &(g908); int64_t _i221 = p_52; (uint8_t*)_t221->b + hr_ix(_i221, _t221->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)45LL))))) { p_52++;
 }
while (f26_dig((*({ hrv *_t224 = &(g908); int64_t _i224 = p_52; (uint8_t*)_t224->b + hr_ix(_i224, _t224->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); })))) { p_52++;
 } _bk222:; 
 }
if (hf_69) { (void)(f23_put(((int64_t)3LL), s_63, p_52, &f_48, &line_53));
continue;
 }
if (((((int64_t)((int64_t)p_52 - (int64_t)ds_67))) > (((int64_t)16LL)))) { return f25_lerr(f_48, line_53, hr_str("hex literal too large for 64 bits", 33));
 }
uint64_t v_70 = ((uint64_t)0LL); 
{ int64_t _e228 = p_52; for (int64_t _k228 = ds_67; _k228 < _e228; _k228++) { int64_t q_71 = (int64_t)_k228; v_70 = ((uint64_t)((uint64_t)((uint64_t)((v_70) << ((((uint64_t)4LL)) & 63))) | (uint64_t)((uint64_t)(f28_hexv((*({ hrv *_t230 = &(g908); int64_t _i230 = q_71; (uint8_t*)_t230->b + hr_ix(_i230, _t230->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:96"); })))))));
 } } _bk227:; 
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t232 = &(((*({ hrv *_t233 = &(g914); int64_t _i233 = ((int64_t)((int64_t)(g914).n - (int64_t)((int64_t)1LL))); (S3*)_t233->b + hr_ix(_i233, _t233->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:97"); }))).v_); *_t232 = ((int64_t)(v_70)); }
{ bool *_t234 = &(((*({ hrv *_t235 = &(g914); int64_t _i235 = ((int64_t)((int64_t)(g914).n - (int64_t)((int64_t)1LL))); (S3*)_t235->b + hr_ix(_i235, _t235->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:97"); }))).uns_); *_t234 = ((v_70) > (((uint64_t)9223372036854775807LL))); }
continue;
 }
while (f26_dig((*({ hrv *_t238 = &(g908); int64_t _i238 = p_52; (uint8_t*)_t238->b + hr_ix(_i238, _t238->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:99"); })))) { p_52++;
 } _bk236:; 
bool fl_73 = false; 
if (((((*({ hrv *_t239 = &(g908); int64_t _i239 = p_52; (uint8_t*)_t239->b + hr_ix(_i239, _t239->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:101"); }))) == (((uint8_t)46LL))) && f26_dig((*({ hrv *_t241 = &(g908); int64_t _i241 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t241->b + hr_ix(_i241, _t241->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:101"); }))))) { fl_73 = true;
p_52++;
while (f26_dig((*({ hrv *_t244 = &(g908); int64_t _i244 = p_52; (uint8_t*)_t244->b + hr_ix(_i244, _t244->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:101"); })))) { p_52++;
 } _bk242:; 
 }
if ((((((*({ hrv *_t245 = &(g908); int64_t _i245 = p_52; (uint8_t*)_t245->b + hr_ix(_i245, _t245->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)101LL))) || (((*({ hrv *_t246 = &(g908); int64_t _i246 = p_52; (uint8_t*)_t246->b + hr_ix(_i246, _t246->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)69LL)))) && (f26_dig((*({ hrv *_t248 = &(g908); int64_t _i248 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t248->b + hr_ix(_i248, _t248->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) || (((((*({ hrv *_t249 = &(g908); int64_t _i249 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t249->b + hr_ix(_i249, _t249->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)43LL))) || (((*({ hrv *_t250 = &(g908); int64_t _i250 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t250->b + hr_ix(_i250, _t250->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)45LL)))) && f26_dig((*({ hrv *_t252 = &(g908); int64_t _i252 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t252->b + hr_ix(_i252, _t252->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))))))) { fl_73 = true;
{ int64_t *_t253 = &(p_52); *_t253 = ((int64_t)((int64_t)(*_t253) + (int64_t)((int64_t)2LL))); }
while (f26_dig((*({ hrv *_t256 = &(g908); int64_t _i256 = p_52; (uint8_t*)_t256->b + hr_ix(_i256, _t256->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); })))) { p_52++;
 } _bk254:; 
 }
if (fl_73) { (void)(f23_put(((int64_t)3LL), s_63, p_52, &f_48, &line_53));
continue;
 }
uint64_t v_74 = ((uint64_t)0LL); 
{ int64_t _e259 = p_52; for (int64_t _k259 = s_63; _k259 < _e259; _k259++) { int64_t q_75 = (int64_t)_k259; uint64_t d_76 = ((uint64_t)(((uint8_t)((uint64_t)(*({ hrv *_t260 = &(g908); int64_t _i260 = q_75; (uint8_t*)_t260->b + hr_ix(_i260, _t260->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:105"); })) - (uint64_t)((uint8_t)48LL))))); 
if (((v_74) > (HR_UDIV(uint64_t, ((uint64_t)((uint64_t)((uint64_t)18446744073709551615ULL) - (uint64_t)d_76)), ((uint64_t)10LL), "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:105")))) { return f25_lerr(f_48, line_53, hr_str("integer literal too large for 64 bits", 37));
 }
v_74 = ((uint64_t)((uint64_t)((uint64_t)((uint64_t)v_74 * (uint64_t)((uint64_t)10LL))) + (uint64_t)d_76));
 } } _bk258:; 
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t263 = &(((*({ hrv *_t264 = &(g914); int64_t _i264 = ((int64_t)((int64_t)(g914).n - (int64_t)((int64_t)1LL))); (S3*)_t264->b + hr_ix(_i264, _t264->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:106"); }))).v_); *_t263 = ((int64_t)(v_74)); }
{ bool *_t265 = &(((*({ hrv *_t266 = &(g914); int64_t _i266 = ((int64_t)((int64_t)(g914).n - (int64_t)((int64_t)1LL))); (S3*)_t266->b + hr_ix(_i266, _t266->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:106"); }))).uns_); *_t265 = ((v_74) > (((uint64_t)9223372036854775807LL))); }
continue;
 }
if (f29_idc(c_57)) { while (f29_idc((*({ hrv *_t270 = &(g908); int64_t _i270 = p_52; (uint8_t*)_t270->b + hr_ix(_i270, _t270->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:109"); })))) { p_52++;
 } _bk268:; 
int64_t id_78 = f8_intern(({ hsl _t272 = hr_sl(g908); int64_t _l272 = s_63, _h272 = p_52; if (_l272 < 0 || _h272 < _l272 || _h272 > _t272.n) hr_slerr(_l272, _h272, _t272.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:110"); (hsl){ _t272.p + _l272 * (int64_t)sizeof(uint8_t), _h272 - _l272 }; })); 
int64_t k_79 = ({ int64_t _r273; if (((id_78) < (((int64_t)49LL)))) { _r273 = ((int64_t)((int64_t)((int64_t)56LL) + (int64_t)id_78));  } else { _r273 = ((int64_t)1LL);  } _r273; }); 
if (((!(amni_51)) && ((k_79) >= (((int64_t)101LL))))) { k_79 = ((int64_t)1LL);
 }
(void)(f23_put(k_79, s_63, p_52, &f_48, &line_53));
{ int64_t *_t275 = &(((*({ hrv *_t276 = &(g914); int64_t _i276 = ((int64_t)((int64_t)(g914).n - (int64_t)((int64_t)1LL))); (S3*)_t276->b + hr_ix(_i276, _t276->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:113"); }))).v_); *_t275 = id_78; }
continue;
 }
if (((c_57) == (((uint8_t)39LL)))) { p_52++;
int64_t v_86 = f30_esc((&(p_52)), f_48, line_53); 
if (((v_86) < (((int64_t)0LL)))) { return false;
 }
if ((((*({ hrv *_t278 = &(g908); int64_t _i278 = p_52; (uint8_t*)_t278->b + hr_ix(_i278, _t278->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:119"); }))) != (((uint8_t)39LL)))) { return f25_lerr(f_48, line_53, hr_str("expected closing ' of character literal", 39));
 }
p_52++;
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t281 = &(((*({ hrv *_t282 = &(g914); int64_t _i282 = ((int64_t)((int64_t)(g914).n - (int64_t)((int64_t)1LL))); (S3*)_t282->b + hr_ix(_i282, _t282->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:120"); }))).v_); *_t281 = v_86; }
continue;
 }
if (((c_57) == (((uint8_t)34LL)))) { int64_t ss_87 = (g910).n; 
bool ml_88 = false; 
if ((((n1_64) == (((uint8_t)34LL))) && ((n2_65) == (((uint8_t)34LL))))) { { int64_t *_t283 = &(p_52); *_t283 = ((int64_t)((int64_t)(*_t283) + (int64_t)((int64_t)3LL))); }
int64_t q_89 = p_52; 
while ((((((*({ hrv *_t285 = &(g908); int64_t _i285 = q_89; (uint8_t*)_t285->b + hr_ix(_i285, _t285->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:127"); }))) == (((uint8_t)32LL))) || (((*({ hrv *_t286 = &(g908); int64_t _i286 = q_89; (uint8_t*)_t286->b + hr_ix(_i286, _t286->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:127"); }))) == (((uint8_t)9LL)))) || (((*({ hrv *_t287 = &(g908); int64_t _i287 = q_89; (uint8_t*)_t287->b + hr_ix(_i287, _t287->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:127"); }))) == (((uint8_t)13LL))))) { q_89++;
 } _bk284:; 
if ((((*({ hrv *_t288 = &(g908); int64_t _i288 = q_89; (uint8_t*)_t288->b + hr_ix(_i288, _t288->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:128"); }))) != (((uint8_t)10LL)))) { while ((!((((((*({ hrv *_t290 = &(g908); int64_t _i290 = p_52; (uint8_t*)_t290->b + hr_ix(_i290, _t290->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)34LL))) && (((*({ hrv *_t291 = &(g908); int64_t _i291 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t291->b + hr_ix(_i291, _t291->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)34LL)))) && (((*({ hrv *_t292 = &(g908); int64_t _i292 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t292->b + hr_ix(_i292, _t292->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)34LL))))))) { if (((((*({ hrv *_t293 = &(g908); int64_t _i293 = p_52; (uint8_t*)_t293->b + hr_ix(_i293, _t293->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)0LL))) || (((*({ hrv *_t294 = &(g908); int64_t _i294 = p_52; (uint8_t*)_t294->b + hr_ix(_i294, _t294->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)10LL))))) { return f25_lerr(f_48, line_53, hr_str("unterminated \"\"\" string", 23));
 }
(void)(({ hrv *_v296 = &(g910); uint8_t _x296 = (*({ hrv *_t297 = &(g908); int64_t _i297 = p_52; (uint8_t*)_t297->b + hr_ix(_i297, _t297->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); })); uint8_t *_p296 = (uint8_t*)hr_grow(_v296, 1, sizeof _x296); *_p296 = _x296; _p296; }));
p_52++;
 } _bk289:; 
{ int64_t *_t298 = &(p_52); *_t298 = ((int64_t)((int64_t)(*_t298) + (int64_t)((int64_t)3LL))); }
 } else { ml_88 = true;
int64_t first_90 = ((int64_t)((int64_t)q_89 + (int64_t)((int64_t)1LL))); 
int64_t close_91 = first_90; 
while ((!((((((*({ hrv *_t300 = &(g908); int64_t _i300 = close_91; (uint8_t*)_t300->b + hr_ix(_i300, _t300->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)34LL))) && (((*({ hrv *_t301 = &(g908); int64_t _i301 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)1LL))); (uint8_t*)_t301->b + hr_ix(_i301, _t301->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)34LL)))) && (((*({ hrv *_t302 = &(g908); int64_t _i302 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)2LL))); (uint8_t*)_t302->b + hr_ix(_i302, _t302->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)34LL))))))) { if ((((*({ hrv *_t303 = &(g908); int64_t _i303 = close_91; (uint8_t*)_t303->b + hr_ix(_i303, _t303->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("unterminated \"\"\" string", 23));
 }
close_91++;
 } _bk299:; 
int64_t cs_92 = close_91; 
while ((((cs_92) > (first_90)) && (((*({ hrv *_t306 = &(g908); int64_t _i306 = ((int64_t)((int64_t)cs_92 - (int64_t)((int64_t)1LL))); (uint8_t*)_t306->b + hr_ix(_i306, _t306->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:136"); }))) != (((uint8_t)10LL))))) { cs_92--;
 } _bk305:; 
int64_t mg_93 = ((int64_t)((int64_t)close_91 - (int64_t)cs_92)); 
{ int64_t _e308 = close_91; for (int64_t _k308 = cs_92; _k308 < _e308; _k308++) { int64_t q2_94 = (int64_t)_k308; if (((((*({ hrv *_t309 = &(g908); int64_t _i309 = q2_94; (uint8_t*)_t309->b + hr_ix(_i309, _t309->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:138"); }))) != (((uint8_t)32LL))) && (((*({ hrv *_t310 = &(g908); int64_t _i310 = q2_94; (uint8_t*)_t310->b + hr_ix(_i310, _t310->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:138"); }))) != (((uint8_t)9LL))))) { return f25_lerr(f_48, line_53, hr_str("only indentation may come before the closing \"\"\" of a multi-line string", 71));
 }
 } } _bk307:; 
int64_t l_95 = first_90; 
while (((l_95) < (cs_92))) { int64_t e_96 = l_95; 
while ((((*({ hrv *_t314 = &(g908); int64_t _i314 = e_96; (uint8_t*)_t314->b + hr_ix(_i314, _t314->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:141"); }))) != (((uint8_t)10LL)))) { e_96++;
 } _bk313:; 
int64_t te_97 = e_96; 
if ((((te_97) > (l_95)) && (((*({ hrv *_t315 = &(g908); int64_t _i315 = ((int64_t)((int64_t)te_97 - (int64_t)((int64_t)1LL))); (uint8_t*)_t315->b + hr_ix(_i315, _t315->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:142"); }))) == (((uint8_t)13LL))))) { te_97--;
 }
if (((l_95) != (first_90))) { (void)(({ hrv *_v316 = &(g910); uint8_t _x316 = ((uint8_t)10LL); uint8_t *_p316 = (uint8_t*)hr_grow(_v316, 1, sizeof _x316); *_p316 = _x316; _p316; }));
 }
bool ok_98 = ((((int64_t)((int64_t)te_97 - (int64_t)l_95))) >= (mg_93)); 
if (ok_98) { { int64_t _e318 = mg_93; for (int64_t _k318 = 0; _k318 < _e318; _k318++) { int64_t k_99 = (int64_t)_k318; if ((((*({ hrv *_t319 = &(g908); int64_t _i319 = ((int64_t)((int64_t)l_95 + (int64_t)k_99)); (uint8_t*)_t319->b + hr_ix(_i319, _t319->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:144"); }))) != ((*({ hrv *_t320 = &(g908); int64_t _i320 = ((int64_t)((int64_t)cs_92 + (int64_t)k_99)); (uint8_t*)_t320->b + hr_ix(_i320, _t320->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:144"); }))))) { ok_98 = false;
 }
 } } _bk317:; 
 }
if (ok_98) { (void)(({ hrv *_v321 = &(g910); hsl _s321 = ({ hsl _t322 = hr_sl(g908); int64_t _l322 = ((int64_t)((int64_t)l_95 + (int64_t)mg_93)), _h322 = te_97; if (_l322 < 0 || _h322 < _l322 || _h322 > _t322.n) hr_slerr(_l322, _h322, _t322.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:145"); (hsl){ _t322.p + _l322 * (int64_t)sizeof(uint8_t), _h322 - _l322 }; }); hr_append(_v321, _s321.p, _s321.n, sizeof(uint8_t)); }));
 } else { { int64_t _e324 = te_97; for (int64_t _k324 = l_95; _k324 < _e324; _k324++) { int64_t k_100 = (int64_t)_k324; if (((((*({ hrv *_t325 = &(g908); int64_t _i325 = k_100; (uint8_t*)_t325->b + hr_ix(_i325, _t325->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:145"); }))) != (((uint8_t)32LL))) && (((*({ hrv *_t326 = &(g908); int64_t _i326 = k_100; (uint8_t*)_t326->b + hr_ix(_i326, _t326->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:145"); }))) != (((uint8_t)9LL))))) { return f25_lerr(f_48, line_53, hr_str("a line of a multi-line string must start with the indentation of its closing \"\"\"", 80));
 }
 } } _bk323:; 
 }
l_95 = ((int64_t)((int64_t)e_96 + (int64_t)((int64_t)1LL)));
 } _bk312:; 
{ int64_t _e329 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)3LL))); for (int64_t _k329 = p_52; _k329 < _e329; _k329++) { int64_t k_101 = (int64_t)_k329; if ((((*({ hrv *_t330 = &(g908); int64_t _i330 = k_101; (uint8_t*)_t330->b + hr_ix(_i330, _t330->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:148"); }))) == (((uint8_t)10LL)))) { line_53++;
 }
 } } _bk328:; 
p_52 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)3LL)));
 }
 } else { p_52++;
while ((((*({ hrv *_t332 = &(g908); int64_t _i332 = p_52; (uint8_t*)_t332->b + hr_ix(_i332, _t332->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:153"); }))) != (((uint8_t)34LL)))) { if (((((*({ hrv *_t333 = &(g908); int64_t _i333 = p_52; (uint8_t*)_t333->b + hr_ix(_i333, _t333->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:153"); }))) == (((uint8_t)10LL))) || (((*({ hrv *_t334 = &(g908); int64_t _i334 = p_52; (uint8_t*)_t334->b + hr_ix(_i334, _t334->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:153"); }))) == (((uint8_t)0LL))))) { return f25_lerr(f_48, line_53, hr_str("unterminated string literal", 27));
 }
int64_t v_102 = f30_esc((&(p_52)), f_48, line_53); 
if (((v_102) < (((int64_t)0LL)))) { return false;
 }
(void)(({ hrv *_v337 = &(g910); uint8_t _x337 = ((uint8_t)(v_102)); uint8_t *_p337 = (uint8_t*)hr_grow(_v337, 1, sizeof _x337); *_p337 = _x337; _p337; }));
 } _bk331:; 
p_52++;
 }
(void)(f23_put(((int64_t)4LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t339 = &(((*({ hrv *_t340 = &(g914); int64_t _i340 = ((int64_t)((int64_t)(g914).n - (int64_t)((int64_t)1LL))); (S3*)_t340->b + hr_ix(_i340, _t340->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:156"); }))).v_); *_t339 = ss_87; }
{ int32_t *_t341 = &(((*({ hrv *_t342 = &(g914); int64_t _i342 = ((int64_t)((int64_t)(g914).n - (int64_t)((int64_t)1LL))); (S3*)_t342->b + hr_ix(_i342, _t342->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:156"); }))).w_); *_t341 = ((int32_t)(((int64_t)((int64_t)(g910).n - (int64_t)ss_87)))); }
{ bool *_t343 = &(((*({ hrv *_t344 = &(g914); int64_t _i344 = ((int64_t)((int64_t)(g914).n - (int64_t)((int64_t)1LL))); (S3*)_t344->b + hr_ix(_i344, _t344->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:156"); }))).ml_); *_t343 = ml_88; }
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
(void)(({ hrv *_v351 = &(g914); S3 _x351 = ((S3){ .k_ = ((uint8_t)(k_54)), .f_ = ((uint16_t)((*c48))), .line_ = ((int32_t)((*c53))), .s_ = ((int32_t)(s_55)), .n_ = ((int32_t)(((int64_t)((int64_t)e_56 - (int64_t)s_55)))), }); S3 *_p351 = (S3*)hr_grow(_v351, 1, sizeof _x351); *_p351 = _x351; _p351; }));
}
static bool f25_lerr(int64_t f_60, int64_t line_61, hsl m_62) {
if ((((g915).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v352 = &(g915); hsl _s352 = f10_nm(((int64_t)(((*({ hrv *_t354 = &(g913); int64_t _i354 = f_60; (S2*)_t354->b + hr_ix(_i354, _t354->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:52"); }))).name_))); hr_append(_v352, _s352.p, _s352.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o355 = &(g915); hr_fs(_o355, hr_str(":", 1)); hr_fi(_o355, line_61); hr_fs(_o355, hr_str(": error: ", 9)); hr_fs(_o355, m_62); }));
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
uint8_t c_83 = (*({ hrv *_t358 = &(g908); int64_t _i358 = (*p_80); (uint8_t*)_t358->b + hr_ix(_i358, _t358->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:54"); })); 
(*p_80)++;
if (((c_83) != (((uint8_t)92LL)))) { return ((int64_t)(c_83));
 }
uint8_t e_84 = (*({ hrv *_t359 = &(g908); int64_t _i359 = (*p_80); (uint8_t*)_t359->b + hr_ix(_i359, _t359->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:56"); })); 
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
if (((((e_84) == (((uint8_t)120LL))) && f27_hexd((*({ hrv *_t361 = &(g908); int64_t _i361 = (*p_80); (uint8_t*)_t361->b + hr_ix(_i361, _t361->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); })))) && f27_hexd((*({ hrv *_t363 = &(g908); int64_t _i363 = ((int64_t)((int64_t)(*p_80) + (int64_t)((int64_t)1LL))); (uint8_t*)_t363->b + hr_ix(_i363, _t363->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); }))))) { int64_t v_85 = ((int64_t)((int64_t)((int64_t)((int64_t)f28_hexv((*({ hrv *_t365 = &(g908); int64_t _i365 = (*p_80); (uint8_t*)_t365->b + hr_ix(_i365, _t365->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); }))) * (int64_t)((int64_t)16LL))) + (int64_t)f28_hexv((*({ hrv *_t367 = &(g908); int64_t _i367 = ((int64_t)((int64_t)(*p_80) + (int64_t)((int64_t)1LL))); (uint8_t*)_t367->b + hr_ix(_i367, _t367->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); }))))); 
{ int64_t *_t368 = p_80; *_t368 = ((int64_t)((int64_t)(*_t368) + (int64_t)((int64_t)2LL))); }
return v_85;
 }
(void)(f25_lerr(f_81, line_82, hr_str("unknown escape sequence", 23)));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f31_tk(void) {
return ((int64_t)(((*({ hrv *_t370 = &(g914); int64_t _i370 = g709; (S3*)_t370->b + hr_ix(_i370, _t370->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:32"); }))).k_));
}
static void f32_ptop(void) {
int64_t st_104 = g709; 
g716 = g717;
int64_t k_105 = f31_tk(); 
if (((k_105) == (((int64_t)57LL)))) { (void)(f33_nx());
g717 = f34_ident(hr_str("namespace declaration", 21));
g716 = g717;
(void)(f39_ex(((int64_t)12LL), hr_str("namespace declaration", 21)));
return;
 }
if (((k_105) == (((int64_t)56LL)))) { (void)(f33_nx());
int64_t n_121 = f40_mk(((int64_t)54LL), st_104); 
if (f41_is(((int64_t)16LL))) { { uint16_t *_t378 = &(((*({ hrv *_t379 = &(g704); int64_t _i379 = n_121; (S4*)_t379->b + hr_ix(_i379, _t379->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:699"); }))).fl_); *_t378 = ((uint16_t)1LL); }
 }
hrv path_123 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v381 = &(path_123); hsl _s381 = f10_nm(f34_ident(hr_str("import", 6))); hr_append(_v381, _s381.p, _s381.n, sizeof(uint8_t)); }));
while (f41_is(((int64_t)16LL))) { (void)(({ hrv *_v386 = &(path_123); uint8_t _x386 = ((uint8_t)47LL); uint8_t *_p386 = (uint8_t*)hr_grow(_v386, 1, sizeof _x386); *_p386 = _x386; _p386; }));
(void)(({ hrv *_v387 = &(path_123); hsl _s387 = f10_nm(f34_ident(hr_str("import", 6))); hr_append(_v387, _s387.p, _s387.n, sizeof(uint8_t)); }));
 } _bk384:; 
{ int64_t q__124 = f8_intern(hr_sl(path_123)); 
{ int32_t *_t391 = &(((*({ hrv *_t392 = &(g704); int64_t _i392 = n_121; (S4*)_t392->b + hr_ix(_i392, _t392->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:703"); }))).s_); *_t391 = ((int32_t)(q__124)); }
 }
if ((f42_at_from() || f43_at_word(g721))) { (void)(f33_nx());
if (((f31_tk()) != (((int64_t)4LL)))) { (void)(f38_perr(hr_str("expected the package's source, a string, after from", 51)));
 }
{ int32_t *_t398 = &(((*({ hrv *_t399 = &(g704); int64_t _i399 = n_121; (S4*)_t399->b + hr_ix(_i399, _t399->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:704"); }))).a_); *_t398 = ((int32_t)(g709)); }
(void)(f33_nx());
 }
(void)(f39_ex(((int64_t)12LL), hr_str("import", 6)));
(void)(({ hrv *_v402 = &(g707); int32_t _x402 = ((int32_t)(n_121)); int32_t *_p402 = (int32_t*)hr_grow(_v402, 1, sizeof _x402); *_p402 = _x402; _p402; }));
return;
 }
if (((f46_at_inline() || f47_at_checkfree()) || f48_at_lut())) { (void)(({ hrv *_v406 = &(g707); int32_t _x406 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p406 = (int32_t*)hr_grow(_v406, 1, sizeof _x406); *_p406 = _x406; _p406; }));
return;
 }
if (((k_105) == (((int64_t)58LL)))) { (void)(({ hrv *_v408 = &(g707); int32_t _x408 = ((int32_t)(f94_pstruct())); int32_t *_p408 = (int32_t*)hr_grow(_v408, 1, sizeof _x408); *_p408 = _x408; _p408; }));
return;
 }
if (((k_105) == (((int64_t)59LL)))) { (void)(({ hrv *_v410 = &(g707); int32_t _x410 = ((int32_t)(f96_penum())); int32_t *_p410 = (int32_t*)hr_grow(_v410, 1, sizeof _x410); *_p410 = _x410; _p410; }));
return;
 }
if (((k_105) == (((int64_t)60LL)))) { (void)(f33_nx());
int64_t n_433 = f40_mk(((int64_t)53LL), st_104); 
{ int64_t q__434 = f50_declname(hr_str("type alias", 10)); 
{ int32_t *_t415 = &(((*({ hrv *_t416 = &(g704); int64_t _i416 = n_433; (S4*)_t416->b + hr_ix(_i416, _t416->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:712"); }))).s_); *_t415 = ((int32_t)(q__434)); }
 }
{ int32_t *_t417 = &(((*({ hrv *_t418 = &(g704); int64_t _i418 = n_433; (S4*)_t418->b + hr_ix(_i418, _t418->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:712"); }))).a_); *_t417 = ((int32_t)(g716)); }
(void)(f39_ex(((int64_t)36LL), hr_str("type alias", 10)));
{ int64_t q__435 = f53_ptype(); 
{ int32_t *_t421 = &(((*({ hrv *_t422 = &(g704); int64_t _i422 = n_433; (S4*)_t422->b + hr_ix(_i422, _t422->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:712"); }))).b_); *_t421 = ((int32_t)(q__435)); }
 }
(void)(f39_ex(((int64_t)12LL), hr_str("type alias", 10)));
(void)(({ hrv *_v424 = &(g707); int32_t _x424 = ((int32_t)(n_433)); int32_t *_p424 = (int32_t*)hr_grow(_v424, 1, sizeof _x424); *_p424 = _x424; _p424; }));
return;
 }
if (((k_105) == (((int64_t)68LL)))) { (void)(f33_nx());
int64_t cs_436 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((f31_tk()) == (((int64_t)4LL)))) { cs_436 = g709;
(void)(f33_nx());
 }
if (((f31_tk()) == (((int64_t)9LL)))) { if (((cs_436) < (((int64_t)0LL)))) { (void)(f38_perr(hr_str("an extern block names the library it binds from: extern \"lib\" {", 63)));
 }
(void)(f33_nx());
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v434 = &(g707); int32_t _x434 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), cs_436))); int32_t *_p434 = (int32_t*)hr_grow(_v434, 1, sizeof _x434); *_p434 = _x434; _p434; }));
 } _bk431:; 
(void)(f39_ex(((int64_t)10LL), hr_str("extern block", 12)));
return;
 }
g709--;
if (((cs_436) >= (((int64_t)0LL)))) { g709--;
 }
(void)(({ hrv *_v437 = &(g707); int32_t _x437 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p437 = (int32_t*)hr_grow(_v437, 1, sizeof _x437); *_p437 = _x437; _p437; }));
return;
 }
if (((((((k_105) == (((int64_t)65LL))) || ((k_105) == (((int64_t)61LL)))) || ((k_105) == (((int64_t)62LL)))) || ((k_105) == (((int64_t)63LL)))) || ((k_105) == (((int64_t)64LL))))) { (void)(({ hrv *_v439 = &(g707); int32_t _x439 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p439 = (int32_t*)hr_grow(_v439, 1, sizeof _x439); *_p439 = _x439; _p439; }));
return;
 }
if ((((((k_105) == (((int64_t)71LL))) || ((k_105) == (((int64_t)66LL)))) || ((k_105) == (((int64_t)67LL)))) || ((k_105) == (((int64_t)69LL))))) { int64_t v_437 = f74_pvdecl(true); 
(void)(f39_ex(((int64_t)12LL), hr_str("global declaration", 18)));
(void)(({ hrv *_v443 = &(g707); int32_t _x443 = ((int32_t)(v_437)); int32_t *_p443 = (int32_t*)hr_grow(_v443, 1, sizeof _x443); *_p443 = _x443; _p443; }));
return;
 }
hrv m_438 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o445 = &(m_438); hr_fs(_o445, hr_str("top-level declaration expected, found '", 39)); hr_fs(_o445, f35_cur_text()); hr_fs(_o445, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_438)));
}
static void f33_nx(void) {
if (((((*({ hrv *_t448 = &(g914); int64_t _i448 = g709; (S3*)_t448->b + hr_ix(_i448, _t448->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:34"); }))).k_) != (((uint8_t)0LL)))) { g709++;
 }
}
static int64_t f34_ident(hsl ctx_106) {
if (((f31_tk()) != (((int64_t)1LL)))) { hrv m_107 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o451 = &(m_107); hr_fs(_o451, hr_str("expected identifier in ", 23)); hr_fs(_o451, ctx_106); hr_fs(_o451, hr_str(", found '", 9)); hr_fs(_o451, f35_cur_text()); hr_fs(_o451, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_107)));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t v_115 = ((int64_t)(((*({ hrv *_t454 = &(g914); int64_t _i454 = g709; (S3*)_t454->b + hr_ix(_i454, _t454->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:51"); }))).v_)); 
(void)(f33_nx());
return v_115;
}
static hsl f35_cur_text(void) {
int64_t k_108 = f31_tk(); 
return ({ hsl _r457; if (((((k_108) == (((int64_t)1LL))) || ((k_108) == (((int64_t)2LL)))) || ((k_108) == (((int64_t)3LL))))) { _r457 = f36_tok_text(g709);  } else { _r457 = f37_tname(k_108);  } _r457; });
}
static hsl f36_tok_text(int64_t t_109) {
S3 x_110 = (*({ hrv *_t460 = &(g914); int64_t _i460 = t_109; (S3*)_t460->b + hr_ix(_i460, _t460->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:181"); })); 
return ({ hsl _t461 = hr_sl(g908); int64_t _l461 = ((int64_t)((x_110).s_)), _h461 = ((int64_t)(((int32_t)((int64_t)(x_110).s_ + (int64_t)(x_110).n_)))); if (_l461 < 0 || _h461 < _l461 || _h461 > _t461.n) hr_slerr(_l461, _h461, _t461.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:181"); (hsl){ _t461.p + _l461 * (int64_t)sizeof(uint8_t), _h461 - _l461 }; });
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
if (((g711) > (((int64_t)0LL)))) { g712 = true;
g709 = ((int64_t)((int64_t)(g914).n - (int64_t)((int64_t)1LL)));
return;
 }
if ((((g710).n) > (((int64_t)0LL)))) { return;
 }
S3 t_114 = (*({ hrv *_t465 = &(g914); int64_t _i465 = g709; (S3*)_t465->b + hr_ix(_i465, _t465->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:45"); })); 
(void)(({ hrv *_v466 = &(g710); hsl _s466 = f10_nm(((int64_t)(((*({ hrv *_t468 = &(g913); int64_t _i468 = (t_114).f_; (S2*)_t468->b + hr_ix(_i468, _t468->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:46"); }))).name_))); hr_append(_v466, _s466.p, _s466.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o469 = &(g710); hr_fs(_o469, hr_str(":", 1)); hr_fi(_o469, (t_114).line_); hr_fs(_o469, hr_str(": error: ", 9)); hr_fs(_o469, m_113); }));
g709 = ((int64_t)((int64_t)(g914).n - (int64_t)((int64_t)1LL)));
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
(void)(({ hrv *_v477 = &(g704); S4 _x477 = ((S4){ .k_ = ((uint8_t)(k_119)), .t_ = ((int32_t)(t_120)), .a_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .b_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .d_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .e_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .s_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .l_ = ((int32_t)0LL), .n_ = ((int32_t)0LL), }); S4 *_p477 = (S4*)hr_grow(_v477, 1, sizeof _x477); *_p477 = _x477; _p477; }));
return ((int64_t)((int64_t)(g704).n - (int64_t)((int64_t)1LL)));
}
static bool f41_is(int64_t k_122) {
if (((f31_tk()) == (k_122))) { (void)(f33_nx());
return true;
 }
return false;
}
static bool f42_at_from(void) {
return (f43_at_word(g721) && (((f44_tkat(((int64_t)((int64_t)g709 + (int64_t)((int64_t)1LL))))) == (((int64_t)1LL))) || ((f44_tkat(((int64_t)((int64_t)g709 + (int64_t)((int64_t)1LL))))) == (((int64_t)15LL)))));
}
static bool f43_at_word(int64_t w_125) {
return (((f31_tk()) == (((int64_t)1LL))) && ((((*({ hrv *_t484 = &(g914); int64_t _i484 = g709; (S3*)_t484->b + hr_ix(_i484, _t484->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:69"); }))).v_) == (w_125)));
}
static int64_t f44_tkat(int64_t i_126) {
return ((int64_t)(((*({ hrv *_t485 = &(g914); int64_t _i485 = f45_min(i_126, ((int64_t)((int64_t)(g914).n - (int64_t)((int64_t)1LL)))); (S3*)_t485->b + hr_ix(_i485, _t485->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:33"); }))).k_));
}
static int64_t f45_min(int64_t a_127, int64_t b_128) {
if (((b_128) < (a_127))) { return b_128;
 }
return a_127;
}
static bool f46_at_inline(void) {
return (f43_at_word(g722) && ((((f44_tkat(((int64_t)((int64_t)g709 + (int64_t)((int64_t)1LL))))) == (((int64_t)61LL))) || ((f44_tkat(((int64_t)((int64_t)g709 + (int64_t)((int64_t)1LL))))) == (((int64_t)65LL)))) || ((f44_tkat(((int64_t)((int64_t)g709 + (int64_t)((int64_t)1LL))))) == (((int64_t)62LL)))));
}
static bool f47_at_checkfree(void) {
int64_t n_129 = f44_tkat(((int64_t)((int64_t)g709 + (int64_t)((int64_t)1LL)))); 
return (f43_at_word(g723) && (((((((n_129) == (((int64_t)61LL))) || ((n_129) == (((int64_t)65LL)))) || ((n_129) == (((int64_t)62LL)))) || ((n_129) == (((int64_t)64LL)))) || ((n_129) == (((int64_t)68LL)))) || ((n_129) == (((int64_t)1LL)))));
}
static bool f48_at_lut(void) {
return (f43_at_word(g724) && ((f44_tkat(((int64_t)((int64_t)g709 + (int64_t)((int64_t)1LL))))) == (((int64_t)61LL))));
}
static int64_t f49_pfn(bool nested_130, int64_t cname_131, int64_t dylib_132) {
int64_t st_133 = g709; 
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
if (((f31_tk()) == (((int64_t)4LL)))) { cn_136 = g709;
(void)(f33_nx());
 }
 }
if (f41_is(((int64_t)68LL))) { { int64_t *_t509 = &(fl_135); *_t509 = ((int64_t)((int64_t)(*_t509) | (int64_t)((int64_t)1LL))); }
if (((f31_tk()) == (((int64_t)4LL)))) { cn_136 = g709;
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
{ int32_t *_t528 = &(((*({ hrv *_t529 = &(g704); int64_t _i529 = n_134; (S4*)_t529->b + hr_ix(_i529, _t529->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:657"); }))).s_); *_t528 = ((int32_t)(q__139)); }
 }
{ int32_t *_t530 = &(((*({ hrv *_t531 = &(g704); int64_t _i531 = n_134; (S4*)_t531->b + hr_ix(_i531, _t531->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:658"); }))).a_); *_t530 = ((int32_t)(g716)); }
{ int64_t q__403 = f51_pgenerics(); 
{ int32_t *_t533 = &(((*({ hrv *_t534 = &(g704); int64_t _i534 = n_134; (S4*)_t534->b + hr_ix(_i534, _t534->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:659"); }))).d_); *_t533 = ((int32_t)(q__403)); }
 }
(void)(f39_ex(((int64_t)5LL), hr_str("function declaration", 20)));
int64_t m_404 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t p_405 = f40_mk(((int64_t)32LL), g709); 
if (f41_is(((int64_t)67LL))) { { uint16_t *_t542 = &(((*({ hrv *_t543 = &(g704); int64_t _i543 = p_405; (S4*)_t543->b + hr_ix(_i543, _t543->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:664"); }))).fl_); *_t542 = ((uint16_t)1LL); }
 }
{ int64_t q__406 = f34_ident(hr_str("parameter list", 14)); 
{ int32_t *_t545 = &(((*({ hrv *_t546 = &(g704); int64_t _i546 = p_405; (S4*)_t546->b + hr_ix(_i546, _t546->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:665"); }))).s_); *_t545 = ((int32_t)(q__406)); }
 }
if ((f41_is(((int64_t)13LL)) || f75_amni_type())) { { int64_t q__407 = f53_ptype(); 
{ int32_t *_t550 = &(((*({ hrv *_t551 = &(g704); int64_t _i551 = p_405; (S4*)_t551->b + hr_ix(_i551, _t551->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:666"); }))).a_); *_t550 = ((int32_t)(q__407)); }
 }
 }
if (f41_is(((int64_t)36LL))) { { int64_t q__408 = f61_pexpr(); 
{ int32_t *_t554 = &(((*({ hrv *_t555 = &(g704); int64_t _i555 = p_405; (S4*)_t555->b + hr_ix(_i555, _t555->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:667"); }))).b_); *_t554 = ((int32_t)(q__408)); }
 }
 }
(void)(({ hrv *_v556 = &(g706); int32_t _x556 = ((int32_t)(p_405)); int32_t *_p556 = (int32_t*)hr_grow(_v556, 1, sizeof _x556); *_p556 = _x556; _p556; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk537; }
 }
 } _bk537:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function declaration", 20)));
(void)(f59_setl(n_134, m_404));
if ((f41_is(((int64_t)54LL)) || f75_amni_type())) { { int64_t *_t562 = &(fl_135); *_t562 = ((int64_t)((int64_t)(*_t562) | (int64_t)((int64_t)512LL))); }
int64_t r_409 = f40_mk(((int64_t)36LL), g709); 
int64_t m2_410 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v566 = &(g706); int32_t _x566 = ((int32_t)(f53_ptype())); int32_t *_p566 = (int32_t*)hr_grow(_v566, 1, sizeof _x566); *_p566 = _x566; _p566; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk565; }
 }
 } _bk565:; 
(void)(f59_setl(r_409, m2_410));
{ int32_t *_t570 = &(((*({ hrv *_t571 = &(g704); int64_t _i571 = n_134; (S4*)_t571->b + hr_ix(_i571, _t571->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:677"); }))).b_); *_t570 = ((int32_t)(r_409)); }
 }
if (((((int64_t)((int64_t)fl_135 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)))) { if (f41_is(((int64_t)36LL))) { if (((f31_tk()) != (((int64_t)4LL)))) { (void)(f38_perr(hr_str("an extern fn's symbol is a string: fn name(...) = \"symbol\"; (\302\2477.10)", 68)));
 }
cn_136 = g709;
(void)(f33_nx());
 }
(void)(f39_ex(((int64_t)12LL), hr_str("extern declaration", 18)));
int64_t x_411 = f40_mk(((int64_t)58LL), st_133); 
{ int32_t *_t578 = &(((*({ hrv *_t579 = &(g704); int64_t _i579 = x_411; (S4*)_t579->b + hr_ix(_i579, _t579->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:682"); }))).a_); *_t578 = ((int32_t)(cn_136)); }
{ int32_t *_t580 = &(((*({ hrv *_t581 = &(g704); int64_t _i581 = x_411; (S4*)_t581->b + hr_ix(_i581, _t581->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:682"); }))).b_); *_t580 = ((int32_t)(dylib_132)); }
{ int32_t *_t582 = &(((*({ hrv *_t583 = &(g704); int64_t _i583 = n_134; (S4*)_t583->b + hr_ix(_i583, _t583->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:682"); }))).e_); *_t582 = ((int32_t)(x_411)); }
 } else { if (((((int64_t)((int64_t)fl_135 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { int64_t x_412 = f40_mk(((int64_t)58LL), st_133); 
{ int32_t *_t585 = &(((*({ hrv *_t586 = &(g704); int64_t _i586 = x_412; (S4*)_t586->b + hr_ix(_i586, _t586->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:684"); }))).a_); *_t585 = ((int32_t)(cn_136)); }
{ int32_t *_t587 = &(((*({ hrv *_t588 = &(g704); int64_t _i588 = n_134; (S4*)_t588->b + hr_ix(_i588, _t588->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:684"); }))).e_); *_t587 = ((int32_t)(x_412)); }
 }
{ int64_t q__413 = f66_pblock(hr_str("function body", 13)); 
{ int32_t *_t590 = &(((*({ hrv *_t591 = &(g704); int64_t _i591 = n_134; (S4*)_t591->b + hr_ix(_i591, _t591->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:685"); }))).c_); *_t590 = ((int32_t)(q__413)); }
 }
 }
{ uint16_t *_t592 = &(((*({ hrv *_t593 = &(g704); int64_t _i593 = n_134; (S4*)_t593->b + hr_ix(_i593, _t593->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:687"); }))).fl_); *_t592 = ((uint16_t)(fl_135)); }
(void)(f88_set_end(n_134));
return n_134;
}
static int64_t f50_declname(hsl ctx_137) {
int64_t a_138 = ({ int64_t _r595; if (((f31_tk()) == (((int64_t)15LL)))) { _r595 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r595 = f34_ident(ctx_137);  } _r595; }); 
if (f41_is(((int64_t)15LL))) { g716 = a_138;
return f34_ident(ctx_137);
 }
return a_138;
}
static int64_t f51_pgenerics(void) {
if ((!(f41_is(((int64_t)39LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t l_140 = f40_mk(((int64_t)36LL), g709); 
int64_t m_141 = f52_wbeg(); 
for (;;) { int64_t g_142 = f40_mk(((int64_t)57LL), g709); 
{ int64_t q__143 = f34_ident(hr_str("generic parameter list", 22)); 
{ int32_t *_t606 = &(((*({ hrv *_t607 = &(g704); int64_t _i607 = g_142; (S4*)_t607->b + hr_ix(_i607, _t607->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:587"); }))).s_); *_t606 = ((int32_t)(q__143)); }
 }
if (f41_is(((int64_t)13LL))) { { int64_t q__402 = f53_ptype(); 
{ int32_t *_t610 = &(((*({ hrv *_t611 = &(g704); int64_t _i611 = g_142; (S4*)_t611->b + hr_ix(_i611, _t611->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:588"); }))).a_); *_t610 = ((int32_t)(q__402)); }
 }
 }
(void)(({ hrv *_v612 = &(g706); int32_t _x612 = ((int32_t)(g_142)); int32_t *_p612 = (int32_t*)hr_grow(_v612, 1, sizeof _x612); *_p612 = _x612; _p612; }));
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
return (g706).n;
}
static int64_t f53_ptype(void) {
bool cq_144 = f41_is(((int64_t)69LL)); 
int64_t t_175 = f54_ptype_prim(); 
bool q_176 = cq_144; 
for (;;) { int64_t st_177 = g709; 
if (f41_is(((int64_t)7LL))) { if (f41_is(((int64_t)13LL))) { (void)(f39_ex(((int64_t)8LL), hr_str("slice type", 10)));
int64_t n_178 = f40_mk(((int64_t)43LL), st_177); 
{ int32_t *_t625 = &(((*({ hrv *_t626 = &(g704); int64_t _i626 = n_178; (S4*)_t626->b + hr_ix(_i626, _t626->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:84"); }))).a_); *_t625 = ((int32_t)(t_175)); }
if (q_176) { { uint16_t *_t627 = &(((*({ hrv *_t628 = &(g704); int64_t _i628 = n_178; (S4*)_t628->b + hr_ix(_i628, _t628->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:84"); }))).fl_); *_t627 = ((uint16_t)1LL); }
q_176 = false;
 }
t_175 = n_178;
continue;
 }
int64_t n_179 = f40_mk(((int64_t)42LL), st_177); 
{ int32_t *_t630 = &(((*({ hrv *_t631 = &(g704); int64_t _i631 = n_179; (S4*)_t631->b + hr_ix(_i631, _t631->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:85"); }))).a_); *_t630 = ((int32_t)(t_175)); }
if (f41_is(((int64_t)8LL))) { { uint8_t *_t633 = &(((*({ hrv *_t634 = &(g704); int64_t _i634 = n_179; (S4*)_t634->b + hr_ix(_i634, _t634->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:86"); }))).op_); *_t633 = ((uint8_t)(((uint8_t)2LL))); }
t_175 = n_179;
continue;
 }
if (f41_is(((int64_t)17LL))) { { uint8_t *_t636 = &(((*({ hrv *_t637 = &(g704); int64_t _i637 = n_179; (S4*)_t637->b + hr_ix(_i637, _t637->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:87"); }))).op_); *_t636 = ((uint8_t)(((uint8_t)3LL))); }
if (((f31_tk()) != (((int64_t)8LL)))) { { int64_t q__391 = f61_pexpr(); 
{ int32_t *_t640 = &(((*({ hrv *_t641 = &(g704); int64_t _i641 = n_179; (S4*)_t641->b + hr_ix(_i641, _t641->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:87"); }))).b_); *_t640 = ((int32_t)(q__391)); }
 }
 }
 } else { if (f41_is(((int64_t)40LL))) { (void)(f39_ex(((int64_t)17LL), hr_str("resizable array type", 20)));
{ uint8_t *_t644 = &(((*({ hrv *_t645 = &(g704); int64_t _i645 = n_179; (S4*)_t645->b + hr_ix(_i645, _t645->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:88"); }))).op_); *_t644 = ({ uint8_t _r646; if (f41_is(((int64_t)39LL))) { _r646 = ((uint8_t)(((uint8_t)5LL)));  } else { _r646 = ((uint8_t)(((uint8_t)4LL)));  } _r646; }); }
 } else { if (f55_prim_tok(f31_tk())) { { uint8_t *_t650 = &(((*({ hrv *_t651 = &(g704); int64_t _i651 = n_179; (S4*)_t651->b + hr_ix(_i651, _t651->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:89"); }))).op_); *_t650 = ((uint8_t)(((uint8_t)2LL))); }
{ int64_t q__393 = f93_lenstore(); 
{ int32_t *_t653 = &(((*({ hrv *_t654 = &(g704); int64_t _i654 = n_179; (S4*)_t654->b + hr_ix(_i654, _t654->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:89"); }))).c_); *_t653 = ((int32_t)(q__393)); }
 }
 } else { { uint8_t *_t655 = &(((*({ hrv *_t656 = &(g704); int64_t _i656 = n_179; (S4*)_t656->b + hr_ix(_i656, _t656->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:90"); }))).op_); *_t655 = ((uint8_t)(((uint8_t)1LL))); }
{ int64_t q__394 = f61_pexpr(); 
{ int32_t *_t658 = &(((*({ hrv *_t659 = &(g704); int64_t _i659 = n_179; (S4*)_t659->b + hr_ix(_i659, _t659->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:90"); }))).b_); *_t658 = ((int32_t)(q__394)); }
 }
 }
 }
 }
(void)(f39_ex(((int64_t)8LL), hr_str("array type", 10)));
t_175 = n_179;
continue;
 }
if (f41_is(((int64_t)49LL))) { int64_t n_395 = f40_mk(((int64_t)44LL), st_177); 
{ int32_t *_t663 = &(((*({ hrv *_t664 = &(g704); int64_t _i664 = n_395; (S4*)_t664->b + hr_ix(_i664, _t664->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:95"); }))).a_); *_t663 = ((int32_t)(t_175)); }
if (q_176) { { uint16_t *_t665 = &(((*({ hrv *_t666 = &(g704); int64_t _i666 = n_395; (S4*)_t666->b + hr_ix(_i666, _t666->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:95"); }))).fl_); *_t665 = ((uint16_t)1LL); }
q_176 = false;
 }
if (f41_is(((int64_t)39LL))) { { int64_t q__396 = f93_lenstore(); 
{ int32_t *_t669 = &(((*({ hrv *_t670 = &(g704); int64_t _i670 = n_395; (S4*)_t670->b + hr_ix(_i670, _t670->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:96"); }))).c_); *_t669 = ((int32_t)(q__396)); }
 }
if (f41_is(((int64_t)76LL))) { { int64_t q__397 = f56_qname(hr_str("relative reference pool", 23)); 
{ int32_t *_t673 = &(((*({ hrv *_t674 = &(g704); int64_t _i674 = n_395; (S4*)_t674->b + hr_ix(_i674, _t674->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:96"); }))).s_); *_t673 = ((int32_t)(q__397)); }
 }
 }
(void)(f58_close_angle(hr_str("relative reference width", 24)));
 }
t_175 = n_395;
continue;
 }
if (f41_is(((int64_t)14LL))) { if (((((*({ hrv *_t677 = &(g704); int64_t _i677 = t_175; (S4*)_t677->b + hr_ix(_i677, _t677->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).k_) == (((uint8_t)44LL)))) { { uint16_t *_t678 = &(((*({ hrv *_t679 = &(g704); int64_t _i679 = t_175; (S4*)_t679->b + hr_ix(_i679, _t679->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).fl_); *_t678 = ((uint16_t)((uint64_t)(*_t678) | (uint64_t)((uint16_t)2LL))); }
 } else { int64_t n_398 = f40_mk(((int64_t)44LL), st_177); 
{ int32_t *_t681 = &(((*({ hrv *_t682 = &(g704); int64_t _i682 = n_398; (S4*)_t682->b + hr_ix(_i682, _t682->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).a_); *_t681 = ((int32_t)(t_175)); }
{ uint16_t *_t683 = &(((*({ hrv *_t684 = &(g704); int64_t _i684 = n_398; (S4*)_t684->b + hr_ix(_i684, _t684->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).fl_); *_t683 = ((uint16_t)2LL); }
if (q_176) { { uint16_t *_t685 = &(((*({ hrv *_t686 = &(g704); int64_t _i686 = n_398; (S4*)_t686->b + hr_ix(_i686, _t686->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).fl_); *_t685 = ((uint16_t)((uint64_t)(*_t685) | (uint64_t)((uint16_t)1LL))); }
q_176 = false;
 }
t_175 = n_398;
 }
continue;
 }
if (((f31_tk()) == (((int64_t)17LL)))) { (void)(f33_nx());
if (((((*({ hrv *_t689 = &(g704); int64_t _i689 = t_175; (S4*)_t689->b + hr_ix(_i689, _t689->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:103"); }))).k_) == (((uint8_t)41LL)))) { { uint16_t *_t690 = &(((*({ hrv *_t691 = &(g704); int64_t _i691 = t_175; (S4*)_t691->b + hr_ix(_i691, _t691->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:103"); }))).fl_); *_t690 = ((uint16_t)((uint64_t)(*_t690) | (uint64_t)((uint16_t)1LL))); }
 } else { (void)(f38_perr(hr_str("variable mode (..) applies only to ADT type names", 49)));
 }
continue;
 }
if (f41_is(((int64_t)16LL))) { int64_t n_399 = f40_mk(((int64_t)46LL), st_177); 
{ int32_t *_t695 = &(((*({ hrv *_t696 = &(g704); int64_t _i696 = n_399; (S4*)_t696->b + hr_ix(_i696, _t696->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:104"); }))).a_); *_t695 = ((int32_t)(t_175)); }
{ int64_t q__400 = f34_ident(hr_str("variant type", 12)); 
{ int32_t *_t698 = &(((*({ hrv *_t699 = &(g704); int64_t _i699 = n_399; (S4*)_t699->b + hr_ix(_i699, _t699->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:104"); }))).s_); *_t698 = ((int32_t)(q__400)); }
 }
t_175 = n_399;
continue;
 }
if (q_176) { int64_t n_401 = f40_mk(((int64_t)48LL), st_177); 
{ int32_t *_t701 = &(((*({ hrv *_t702 = &(g704); int64_t _i702 = n_401; (S4*)_t702->b + hr_ix(_i702, _t702->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:105"); }))).a_); *_t701 = ((int32_t)(t_175)); }
t_175 = n_401;
 }
return t_175;
 } _bk620:; 
}
static int64_t f54_ptype_prim(void) {
int64_t st_145 = g709; 
int64_t k_146 = f31_tk(); 
if (f55_prim_tok(k_146)) { (void)(f33_nx());
bool up_148 = f43_at_word(g726); 
if (((((((((k_146) >= (((int64_t)91LL))) && ((k_146) <= (((int64_t)98LL)))) || ((k_146) == (((int64_t)103LL)))) || ((k_146) == (((int64_t)102LL)))) || ((k_146) == (((int64_t)101LL)))) && (!(g756))) && (((f31_tk()) == (((int64_t)76LL))) || up_148))) { (void)(f33_nx());
int64_t n_149 = f40_mk(((int64_t)47LL), st_145); 
{ uint8_t *_t710 = &(((*({ hrv *_t711 = &(g704); int64_t _i711 = n_149; (S4*)_t711->b + hr_ix(_i711, _t711->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:116"); }))).op_); *_t710 = ((uint8_t)(k_146)); }
{ uint16_t *_t712 = &(((*({ hrv *_t713 = &(g704); int64_t _i713 = n_149; (S4*)_t713->b + hr_ix(_i713, _t713->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:116"); }))).fl_); *_t712 = ({ uint16_t _r714; if (up_148) { _r714 = ((uint16_t)1LL);  } else { _r714 = ((uint16_t)0LL);  } _r714; }); }
{ int64_t q__155 = f56_qname(hr_str("index type", 10)); 
{ int32_t *_t716 = &(((*({ hrv *_t717 = &(g704); int64_t _i717 = n_149; (S4*)_t717->b + hr_ix(_i717, _t717->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:116"); }))).s_); *_t716 = ((int32_t)(q__155)); }
 }
return n_149;
 }
int64_t n_156 = f40_mk(((int64_t)40LL), st_145); 
{ uint8_t *_t719 = &(((*({ hrv *_t720 = &(g704); int64_t _i720 = n_156; (S4*)_t720->b + hr_ix(_i720, _t720->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:118"); }))).op_); *_t719 = ((uint8_t)(k_146)); }
return n_156;
 }
if ((((k_146) == (((int64_t)1LL))) || ((k_146) == (((int64_t)15LL))))) { int64_t n_157 = f40_mk(((int64_t)41LL), st_145); 
{ int64_t q__158 = f56_qname(hr_str("type", 4)); 
{ int32_t *_t723 = &(((*({ hrv *_t724 = &(g704); int64_t _i724 = n_157; (S4*)_t724->b + hr_ix(_i724, _t724->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:121"); }))).s_); *_t723 = ((int32_t)(q__158)); }
 }
if (f41_is(((int64_t)39LL))) { int64_t m_159 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v728 = &(g706); int32_t _x728 = ((int32_t)(f53_ptype())); int32_t *_p728 = (int32_t*)hr_grow(_v728, 1, sizeof _x728); *_p728 = _x728; _p728; }));
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
if (f41_is(((int64_t)5LL))) { { uint16_t *_t738 = &(((*({ hrv *_t739 = &(g704); int64_t _i739 = n_168; (S4*)_t739->b + hr_ix(_i739, _t739->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:128"); }))).fl_); *_t738 = ((uint16_t)1LL); }
int64_t m_169 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v744 = &(g706); int32_t _x744 = ((int32_t)(f53_ptype())); int32_t *_p744 = (int32_t*)hr_grow(_v744, 1, sizeof _x744); *_p744 = _x744; _p744; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk741; }
 }
 } _bk741:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function type", 13)));
(void)(f59_setl(n_168, m_169));
if (f41_is(((int64_t)54LL))) { int64_t r_170 = f40_mk(((int64_t)36LL), g709); 
int64_t m2_171 = f52_wbeg(); 
if (f41_is(((int64_t)5LL))) { while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v756 = &(g706); int32_t _x756 = ((int32_t)(f53_ptype())); int32_t *_p756 = (int32_t*)hr_grow(_v756, 1, sizeof _x756); *_p756 = _x756; _p756; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk753; }
 }
 } _bk753:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function type return list", 25)));
 } else { (void)(({ hrv *_v760 = &(g706); int32_t _x760 = ((int32_t)(f53_ptype())); int32_t *_p760 = (int32_t*)hr_grow(_v760, 1, sizeof _x760); *_p760 = _x760; _p760; }));
 }
(void)(f59_setl(r_170, m2_171));
{ int32_t *_t763 = &(((*({ hrv *_t764 = &(g704); int64_t _i764 = n_168; (S4*)_t764->b + hr_ix(_i764, _t764->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:133"); }))).b_); *_t763 = ((int32_t)(r_170)); }
 }
 }
return n_168;
 }
if (f41_is(((int64_t)5LL))) { bool fb_172 = g756; 
g756 = false;
int64_t t_173 = f53_ptype(); 
g756 = fb_172;
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
if (((f31_tk()) == (((int64_t)44LL)))) { (void)(({ hrv *_v788 = &(g718); int64_t _x788 = g709; int64_t *_p788 = (int64_t*)hr_grow(_v788, 1, sizeof _x788); *_p788 = _x788; _p788; }));
{ uint8_t *_t789 = &(((*({ hrv *_t790 = &(g914); int64_t _i790 = g709; (S3*)_t790->b + hr_ix(_i790, _t790->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:52"); }))).k_); *_t789 = ((uint8_t)(((uint8_t)40LL))); }
return;
 }
(void)(f39_ex(((int64_t)40LL), ctx_160));
}
static void f59_setl(int64_t n_161, int64_t m_162) {
int64_t c_163 = ((int64_t)((int64_t)(g706).n - (int64_t)m_162)); 
{ int64_t q__167 = f60_wend(m_162); 
{ int32_t *_t793 = &(((*({ hrv *_t794 = &(g704); int64_t _i794 = n_161; (S4*)_t794->b + hr_ix(_i794, _t794->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:55"); }))).l_); *_t793 = ((int32_t)(q__167)); }
 }
{ int32_t *_t795 = &(((*({ hrv *_t796 = &(g704); int64_t _i796 = n_161; (S4*)_t796->b + hr_ix(_i796, _t796->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:55"); }))).n_); *_t795 = ((int32_t)(c_163)); }
}
static int64_t f60_wend(int64_t m_164) {
int64_t l_165 = (g705).n; 
{ int64_t _e798 = (g706).n; for (int64_t _k798 = m_164; _k798 < _e798; _k798++) { int64_t i_166 = (int64_t)_k798; (void)(({ hrv *_v799 = &(g705); int32_t _x799 = (*({ hrv *_t800 = &(g706); int64_t _i800 = i_166; (int32_t*)_t800->b + hr_ix(_i800, _t800->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:54"); })); int32_t *_p799 = (int32_t*)hr_grow(_v799, 1, sizeof _x799); *_p799 = _x799; _p799; }));
 } } _bk797:; 
(void)(({ hrv *_v801 = &(g706); int64_t _k801 = ((int64_t)((int64_t)(g706).n - (int64_t)m_164)); if (_k801 < 0 || _k801 > _v801->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:54"); _v801->n -= _k801; }));
return l_165;
}
static int64_t f61_pexpr(void) {
int64_t st_180 = g709; 
int64_t k_181 = f31_tk(); 
if (((k_181) == (((int64_t)72LL)))) { int64_t e_270 = f62_pif(); 
if (g714) { g715 = true;
 }
return e_270;
 }
if (((k_181) == (((int64_t)80LL)))) { int64_t e_274 = f78_pmatch(); 
if (g714) { g715 = true;
 }
return e_274;
 }
if (((k_181) == (((int64_t)78LL)))) { (void)(f33_nx());
int64_t e_275 = f40_mk(((int64_t)24LL), st_180); 
{ int64_t q__276 = f66_pblock(hr_str("block expression", 16)); 
{ int32_t *_t808 = &(((*({ hrv *_t809 = &(g704); int64_t _i809 = e_275; (S4*)_t809->b + hr_ix(_i809, _t809->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:147"); }))).a_); *_t808 = ((int32_t)(q__276)); }
 }
if (g714) { g715 = true;
 }
return e_275;
 }
if (((k_181) == (((int64_t)9LL)))) { int64_t e_277 = f66_pblock(hr_str("block", 5)); 
if (g714) { g715 = true;
 }
return e_277;
 }
if (((k_181) == (((int64_t)74LL)))) { (void)(f33_nx());
int64_t e_278 = f40_mk(((int64_t)25LL), st_180); 
{ int64_t q__279 = f63_pscrut(); 
{ int32_t *_t814 = &(((*({ hrv *_t815 = &(g704); int64_t _i815 = e_278; (S4*)_t815->b + hr_ix(_i815, _t815->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:149"); }))).a_); *_t814 = ((int32_t)(q__279)); }
 }
{ int64_t q__280 = f66_pblock(hr_str("while body", 10)); 
{ int32_t *_t817 = &(((*({ hrv *_t818 = &(g704); int64_t _i818 = e_278; (S4*)_t818->b + hr_ix(_i818, _t818->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:149"); }))).b_); *_t817 = ((int32_t)(q__280)); }
 }
if (g714) { g715 = true;
 }
return e_278;
 }
if (((k_181) == (((int64_t)77LL)))) { (void)(f33_nx());
int64_t e_281 = f40_mk(((int64_t)26LL), st_180); 
{ int64_t q__282 = f66_pblock(hr_str("loop body", 9)); 
{ int32_t *_t822 = &(((*({ hrv *_t823 = &(g704); int64_t _i823 = e_281; (S4*)_t823->b + hr_ix(_i823, _t823->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:150"); }))).a_); *_t822 = ((int32_t)(q__282)); }
 }
if (g714) { g715 = true;
 }
return e_281;
 }
if (((k_181) == (((int64_t)75LL)))) { int64_t e_294 = f79_pfor(); 
if (g714) { g715 = true;
 }
return e_294;
 }
if (((k_181) == (((int64_t)79LL)))) { (void)(f38_perr(hr_str("guard is a statement: it guards the rest of the block it is in", 62)));
return f40_mk(((int64_t)6LL), st_180);
 }
if (((k_181) == (((int64_t)81LL)))) { (void)(f33_nx());
bool sl_295 = g714; 
bool se_296 = g715; 
g714 = false;
g715 = false;
int64_t r_297 = f40_mk(((int64_t)28LL), st_180); 
if (((((f31_tk()) != (((int64_t)12LL))) && ((f31_tk()) != (((int64_t)10LL)))) && (!(f42_at_from())))) { int64_t m_298 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v834 = &(g706); int32_t _x834 = ((int32_t)(f61_pexpr())); int32_t *_p834 = (int32_t*)hr_grow(_v834, 1, sizeof _x834); *_p834 = _x834; _p834; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk833; }
 }
 } _bk833:; 
(void)(f59_setl(r_297, m_298));
 }
if (f42_at_from()) { (void)(f33_nx());
{ int64_t q__299 = f56_qname(hr_str("return from", 11)); 
{ int32_t *_t841 = &(((*({ hrv *_t842 = &(g704); int64_t _i842 = r_297; (S4*)_t842->b + hr_ix(_i842, _t842->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:158"); }))).s_); *_t841 = ((int32_t)(q__299)); }
 }
 }
g714 = sl_295;
g715 = se_296;
return r_297;
 }
if (((k_181) == (((int64_t)82LL)))) { (void)(f33_nx());
bool sl_300 = g714; 
bool se_301 = g715; 
g714 = false;
g715 = false;
int64_t r_302 = f40_mk(((int64_t)29LL), st_180); 
if ((((f31_tk()) != (((int64_t)12LL))) && ((f31_tk()) != (((int64_t)10LL))))) { { int64_t q__303 = f61_pexpr(); 
{ int32_t *_t848 = &(((*({ hrv *_t849 = &(g704); int64_t _i849 = r_302; (S4*)_t849->b + hr_ix(_i849, _t849->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:166"); }))).a_); *_t848 = ((int32_t)(q__303)); }
 }
 }
g714 = sl_300;
g715 = se_301;
return r_302;
 }
if (((k_181) == (((int64_t)83LL)))) { (void)(f33_nx());
return f40_mk(((int64_t)30LL), st_180);
 }
return f80_pbin(((int64_t)1LL));
}
static int64_t f62_pif(void) {
int64_t st_182 = g709; 
(void)(f33_nx());
int64_t n_183 = f40_mk(((int64_t)19LL), st_182); 
{ int64_t q__189 = f63_pscrut(); 
{ int32_t *_t856 = &(((*({ hrv *_t857 = &(g704); int64_t _i857 = n_183; (S4*)_t857->b + hr_ix(_i857, _t857->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:180"); }))).a_); *_t856 = ((int32_t)(q__189)); }
 }
{ int64_t q__268 = f66_pblock(hr_str("if body", 7)); 
{ int32_t *_t859 = &(((*({ hrv *_t860 = &(g704); int64_t _i860 = n_183; (S4*)_t860->b + hr_ix(_i860, _t860->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:181"); }))).b_); *_t859 = ((int32_t)(q__268)); }
 }
if (f41_is(((int64_t)73LL))) { { int64_t q__269 = ({ int64_t _r862; if (((f31_tk()) == (((int64_t)72LL)))) { _r862 = f62_pif();  } else { _r862 = f66_pblock(hr_str("else body", 9));  } _r862; }); 
{ int32_t *_t866 = &(((*({ hrv *_t867 = &(g704); int64_t _i867 = n_183; (S4*)_t867->b + hr_ix(_i867, _t867->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:182"); }))).c_); *_t866 = ((int32_t)(q__269)); }
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
int64_t s_185 = ((int64_t)((int64_t)((int64_t)((int64_t)({ int64_t _r871; if (g713) { _r871 = ((int64_t)1LL);  } else { _r871 = ((int64_t)0LL);  } _r871; }) | (int64_t)({ int64_t _r872; if (g714) { _r872 = ((int64_t)2LL);  } else { _r872 = ((int64_t)0LL);  } _r872; }))) | (int64_t)({ int64_t _r873; if (g715) { _r873 = ((int64_t)4LL);  } else { _r873 = ((int64_t)0LL);  } _r873; }))); 
g713 = nosl_184;
g714 = false;
g715 = false;
return s_185;
}
static void f65_sub_end(int64_t s_188) {
g713 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)));
g714 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)));
g715 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL)));
}
static int64_t f66_pblock(hsl ctx_190) {
int64_t st_191 = g709; 
(void)(f39_ex(((int64_t)9LL), ctx_190));
int64_t b_192 = f40_mk(((int64_t)23LL), st_191); 
(void)(f67_pbody(b_192));
return b_192;
}
static void f67_pbody(int64_t b_193) {
int64_t s_194 = f64_sub_begin(false); 
int64_t m_195 = f52_wbeg(); 
for (;;) { g714 = false;
g715 = false;
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
if (((((((((f46_at_inline() || f47_at_checkfree()) || f48_at_lut()) || ((k_197) == (((int64_t)65LL)))) || ((k_197) == (((int64_t)61LL)))) || ((k_197) == (((int64_t)62LL)))) || ((k_197) == (((int64_t)68LL)))) || ((k_197) == (((int64_t)63LL)))) || ((k_197) == (((int64_t)64LL))))) { (void)(({ hrv *_v890 = &(g706); int32_t _x890 = ((int32_t)(f49_pfn(true, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p890 = (int32_t*)hr_grow(_v890, 1, sizeof _x890); *_p890 = _x890; _p890; }));
return true;
 }
if ((((((k_197) == (((int64_t)66LL))) || ((k_197) == (((int64_t)67LL)))) || ((k_197) == (((int64_t)69LL)))) || ((k_197) == (((int64_t)71LL))))) { if ((((k_197) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g709 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v893 = &(g706); int32_t _x893 = ((int32_t)(f69_pcfor(((int64_t)0LL)))); int32_t *_p893 = (int32_t*)hr_grow(_v893, 1, sizeof _x893); *_p893 = _x893; _p893; }));
return true;
 }
int64_t v_247 = f74_pvdecl(false); 
(void)(f39_ex(((int64_t)12LL), hr_str("variable declaration", 20)));
(void)(({ hrv *_v897 = &(g706); int32_t _x897 = ((int32_t)(v_247)); int32_t *_p897 = (int32_t*)hr_grow(_v897, 1, sizeof _x897); *_p897 = _x897; _p897; }));
return true;
 }
if (((k_197) == (((int64_t)79LL)))) { (void)(f76_pguard(b_196));
return false;
 }
g714 = true;
int64_t e_254 = f61_pexpr(); 
g714 = false;
int64_t st_255 = g709; 
if ((!(g715))) { int64_t o_256 = f31_tk(); 
if ((((((((((((((o_256) == (((int64_t)36LL))) || ((o_256) == (((int64_t)18LL)))) || ((o_256) == (((int64_t)26LL)))) || ((o_256) == (((int64_t)27LL)))) || ((o_256) == (((int64_t)28LL)))) || ((o_256) == (((int64_t)29LL)))) || ((o_256) == (((int64_t)30LL)))) || ((o_256) == (((int64_t)31LL)))) || ((o_256) == (((int64_t)32LL)))) || ((o_256) == (((int64_t)33LL)))) || ((o_256) == (((int64_t)45LL)))) || ((o_256) == (((int64_t)46LL))))) { (void)(f33_nx());
int64_t r_257 = f61_pexpr(); 
(void)(f39_ex(((int64_t)12LL), hr_str("assignment statement", 20)));
int64_t n_258 = f40_mk(((int64_t)34LL), st_255); 
{ uint8_t *_t905 = &(((*({ hrv *_t906 = &(g704); int64_t _i906 = n_258; (S4*)_t906->b + hr_ix(_i906, _t906->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:528"); }))).op_); *_t905 = ((uint8_t)(o_256)); }
{ int32_t *_t907 = &(((*({ hrv *_t908 = &(g704); int64_t _i908 = n_258; (S4*)_t908->b + hr_ix(_i908, _t908->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:528"); }))).a_); *_t907 = ((int32_t)(e_254)); }
{ int32_t *_t909 = &(((*({ hrv *_t910 = &(g704); int64_t _i910 = n_258; (S4*)_t910->b + hr_ix(_i910, _t910->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:528"); }))).b_); *_t909 = ((int32_t)(r_257)); }
(void)(({ hrv *_v911 = &(g706); int32_t _x911 = ((int32_t)(n_258)); int32_t *_p911 = (int32_t*)hr_grow(_v911, 1, sizeof _x911); *_p911 = _x911; _p911; }));
return true;
 }
if ((((o_256) == (((int64_t)34LL))) || ((o_256) == (((int64_t)35LL))))) { (void)(f33_nx());
(void)(f39_ex(((int64_t)12LL), hr_str("increment statement", 19)));
int64_t n_259 = f40_mk(((int64_t)35LL), st_255); 
{ uint8_t *_t915 = &(((*({ hrv *_t916 = &(g704); int64_t _i916 = n_259; (S4*)_t916->b + hr_ix(_i916, _t916->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:530"); }))).op_); *_t915 = ((uint8_t)(o_256)); }
{ int32_t *_t917 = &(((*({ hrv *_t918 = &(g704); int64_t _i918 = n_259; (S4*)_t918->b + hr_ix(_i918, _t918->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:530"); }))).a_); *_t917 = ((int32_t)(e_254)); }
(void)(({ hrv *_v919 = &(g706); int32_t _x919 = ((int32_t)(n_259)); int32_t *_p919 = (int32_t*)hr_grow(_v919, 1, sizeof _x919); *_p919 = _x919; _p919; }));
return true;
 }
if (((o_256) == (((int64_t)11LL)))) { (void)(({ hrv *_v920 = &(g706); int32_t _x920 = ((int32_t)(f77_pmulti(e_254, st_255))); int32_t *_p920 = (int32_t*)hr_grow(_v920, 1, sizeof _x920); *_p920 = _x920; _p920; }));
return true;
 }
 }
if (f41_is(((int64_t)12LL))) { (void)(({ hrv *_v923 = &(g706); int32_t _x923 = ((int32_t)(e_254)); int32_t *_p923 = (int32_t*)hr_grow(_v923, 1, sizeof _x923); *_p923 = _x923; _p923; }));
return true;
 }
if (f41_is(((int64_t)10LL))) { { int32_t *_t925 = &(((*({ hrv *_t926 = &(g704); int64_t _i926 = b_196; (S4*)_t926->b + hr_ix(_i926, _t926->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:534"); }))).a_); *_t925 = ((int32_t)(e_254)); }
return false;
 }
if (g715) { (void)(({ hrv *_v927 = &(g706); int32_t _x927 = ((int32_t)(e_254)); int32_t *_p927 = (int32_t*)hr_grow(_v927, 1, sizeof _x927); *_p927 = _x927; _p927; }));
return true;
 }
hrv m_267 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o929 = &(m_267); hr_fs(_o929, hr_str("';' expected after expression, found '", 38)); hr_fs(_o929, f35_cur_text()); hr_fs(_o929, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_267)));
return false;
}
static int64_t f69_pcfor(int64_t mode_198) {
int64_t cf_199 = f40_mk(((int64_t)37LL), g709); 
(void)(f39_ex(((int64_t)69LL), hr_str("const for", 9)));
(void)(f39_ex(((int64_t)75LL), hr_str("const for", 9)));
(void)(f39_ex(((int64_t)39LL), hr_str("const for bindings", 18)));
int64_t nb_200 = f40_mk(((int64_t)36LL), g709); 
int64_t m_201 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v939 = &(g706); int32_t _x939 = ((int32_t)(f34_ident(hr_str("const for binding", 17)))); int32_t *_p939 = (int32_t*)hr_grow(_v939, 1, sizeof _x939); *_p939 = _x939; _p939; }));
if (((!(f41_is(((int64_t)11LL)))) || ((f31_tk()) == (((int64_t)40LL))))) { { goto _bk938; }
 }
 } _bk938:; 
(void)(f59_setl(nb_200, m_201));
(void)(f58_close_angle(hr_str("const for bindings", 18)));
(void)(f39_ex(((int64_t)76LL), hr_str("const for", 9)));
{ int32_t *_t946 = &(((*({ hrv *_t947 = &(g704); int64_t _i947 = cf_199; (S4*)_t947->b + hr_ix(_i947, _t947->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:426"); }))).a_); *_t946 = ((int32_t)(nb_200)); }
int64_t src_202 = f40_mk(((int64_t)36LL), g709); 
if (f41_is(((int64_t)7LL))) { { uint8_t *_t950 = &(((*({ hrv *_t951 = &(g704); int64_t _i951 = cf_199; (S4*)_t951->b + hr_ix(_i951, _t951->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:429"); }))).op_); *_t950 = ((uint8_t)1LL); }
int64_t s_203 = f64_sub_begin(false); 
int64_t m2_204 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)8LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v957 = &(g706); int32_t _x957 = ((int32_t)(f61_pexpr())); int32_t *_p957 = (int32_t*)hr_grow(_v957, 1, sizeof _x957); *_p957 = _x957; _p957; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk954; }
 }
 } _bk954:; 
(void)(f39_ex(((int64_t)8LL), hr_str("const for constant list", 23)));
(void)(f59_setl(src_202, m2_204));
(void)(f65_sub_end(s_203));
 } else { int64_t q_205 = f34_ident(hr_str("const for source", 16)); 
{ uint8_t *_t964 = &(((*({ hrv *_t965 = &(g704); int64_t _i965 = cf_199; (S4*)_t965->b + hr_ix(_i965, _t965->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:435"); }))).op_); *_t964 = ((uint8_t)(({ uint8_t _r966; if (((q_205) == (g727))) { _r966 = ((uint8_t)2LL);  } else { _r966 = ({ uint8_t _r967; if (((q_205) == (g729))) { _r967 = ((uint8_t)3LL);  } else { _r967 = ({ uint8_t _r968; if (((q_205) == (g728))) { _r968 = ((uint8_t)4LL);  } else { _r968 = ((uint8_t)0LL);  } _r968; });  } _r967; });  } _r966; }))); }
if (((((*({ hrv *_t969 = &(g704); int64_t _i969 = cf_199; (S4*)_t969->b + hr_ix(_i969, _t969->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:436"); }))).op_) == (((uint8_t)0LL)))) { (void)(f38_perr(hr_str("const for source must be fields<T>, variants<E>, types<...>, or [constants]", 75)));
 }
(void)(f39_ex(((int64_t)39LL), hr_str("const for source", 16)));
int64_t m2_206 = f52_wbeg(); 
while (((((f31_tk()) != (((int64_t)40LL))) && ((f31_tk()) != (((int64_t)44LL)))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v977 = &(g706); int32_t _x977 = ((int32_t)(f53_ptype())); int32_t *_p977 = (int32_t*)hr_grow(_v977, 1, sizeof _x977); *_p977 = _x977; _p977; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk973; }
 }
 } _bk973:; 
(void)(f58_close_angle(hr_str("const for source", 16)));
(void)(f59_setl(src_202, m2_206));
 }
{ int32_t *_t982 = &(((*({ hrv *_t983 = &(g704); int64_t _i983 = cf_199; (S4*)_t983->b + hr_ix(_i983, _t983->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:440"); }))).b_); *_t982 = ((int32_t)(src_202)); }
{ uint16_t *_t984 = &(((*({ hrv *_t985 = &(g704); int64_t _i985 = cf_199; (S4*)_t985->b + hr_ix(_i985, _t985->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:441"); }))).fl_); *_t984 = ((uint16_t)(mode_198)); }
if (((mode_198) == (((int64_t)1LL)))) { int64_t il_207 = f40_mk(((int64_t)36LL), g709); 
(void)(f70_pinits(il_207, true));
{ int32_t *_t988 = &(((*({ hrv *_t989 = &(g704); int64_t _i989 = cf_199; (S4*)_t989->b + hr_ix(_i989, _t989->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:442"); }))).c_); *_t988 = ((int32_t)(il_207)); }
 } else { if (((mode_198) == (((int64_t)2LL)))) { (void)(f39_ex(((int64_t)9LL), hr_str("const for arms", 14)));
int64_t al_214 = f40_mk(((int64_t)36LL), g709); 
(void)(f71_parms(al_214));
(void)(f39_ex(((int64_t)10LL), hr_str("const for arms", 14)));
{ int32_t *_t994 = &(((*({ hrv *_t995 = &(g704); int64_t _i995 = cf_199; (S4*)_t995->b + hr_ix(_i995, _t995->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:443"); }))).c_); *_t994 = ((int32_t)(al_214)); }
 } else { { int64_t q__237 = f66_pblock(hr_str("const for body", 14)); 
{ int32_t *_t997 = &(((*({ hrv *_t998 = &(g704); int64_t _i998 = cf_199; (S4*)_t998->b + hr_ix(_i998, _t998->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:443"); }))).c_); *_t997 = ((int32_t)(q__237)); }
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
{ uint16_t *_t1007 = &(((*({ hrv *_t1008 = &(g704); int64_t _i1008 = n_208; (S4*)_t1008->b + hr_ix(_i1008, _t1008->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:451"); }))).fl_); *_t1007 = ((uint16_t)((uint64_t)(*_t1007) | (uint64_t)((uint16_t)1LL))); }
{ goto _bk1002; }
 }
if ((((f31_tk()) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g709 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v1011 = &(g706); int32_t _x1011 = ((int32_t)(f69_pcfor(((int64_t)1LL)))); int32_t *_p1011 = (int32_t*)hr_grow(_v1011, 1, sizeof _x1011); *_p1011 = _x1011; _p1011; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1002; }
 }
continue;
 }
int64_t fi_212 = f40_mk(((int64_t)18LL), g709); 
if ((((f31_tk()) == (((int64_t)1LL))) && ((f44_tkat(((int64_t)((int64_t)g709 + (int64_t)((int64_t)1LL))))) == (((int64_t)13LL))))) { { int32_t *_t1017 = &(((*({ hrv *_t1018 = &(g704); int64_t _i1018 = fi_212; (S4*)_t1018->b + hr_ix(_i1018, _t1018->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:454"); }))).s_); *_t1017 = ((int32_t)(((*({ hrv *_t1019 = &(g914); int64_t _i1019 = g709; (S3*)_t1019->b + hr_ix(_i1019, _t1019->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:454"); }))).v_)); }
(void)(f33_nx());
(void)(f33_nx());
 }
{ int64_t q__213 = f61_pexpr(); 
{ int32_t *_t1023 = &(((*({ hrv *_t1024 = &(g704); int64_t _i1024 = fi_212; (S4*)_t1024->b + hr_ix(_i1024, _t1024->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:455"); }))).a_); *_t1023 = ((int32_t)(q__213)); }
 }
(void)(({ hrv *_v1025 = &(g706); int32_t _x1025 = ((int32_t)(fi_212)); int32_t *_p1025 = (int32_t*)hr_grow(_v1025, 1, sizeof _x1025); *_p1025 = _x1025; _p1025; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1002; }
 }
 } _bk1002:; 
(void)(f39_ex(((int64_t)10LL), hr_str("struct literal", 14)));
(void)(f59_setl(n_208, m_211));
(void)(f65_sub_end(s_210));
}
static void f71_parms(int64_t n_215) {
int64_t s_216 = f64_sub_begin(g713); 
int64_t m_217 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { if ((((f31_tk()) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g709 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v1037 = &(g706); int32_t _x1037 = ((int32_t)(f69_pcfor(((int64_t)2LL)))); int32_t *_p1037 = (int32_t*)hr_grow(_v1037, 1, sizeof _x1037); *_p1037 = _x1037; _p1037; }));
 } else { int64_t a_235 = f72_ppattern(); 
(void)(f39_ex(((int64_t)55LL), hr_str("match arm", 9)));
{ int64_t q__236 = f61_pexpr(); 
{ int32_t *_t1042 = &(((*({ hrv *_t1043 = &(g704); int64_t _i1043 = a_235; (S4*)_t1043->b + hr_ix(_i1043, _t1043->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:218"); }))).b_); *_t1042 = ((int32_t)(q__236)); }
 }
(void)(({ hrv *_v1044 = &(g706); int32_t _x1044 = ((int32_t)(a_235)); int32_t *_p1044 = (int32_t*)hr_grow(_v1044, 1, sizeof _x1044); *_p1044 = _x1044; _p1044; }));
 }
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1032; }
 }
 } _bk1032:; 
(void)(f59_setl(n_215, m_217));
(void)(f65_sub_end(s_216));
}
static int64_t f72_ppattern(void) {
int64_t a_218 = f40_mk(((int64_t)21LL), g709); 
if (f43_at_word(g725)) { (void)(f33_nx());
{ uint16_t *_t1051 = &(((*({ hrv *_t1052 = &(g704); int64_t _i1052 = a_218; (S4*)_t1052->b + hr_ix(_i1052, _t1052->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:226"); }))).fl_); *_t1051 = ((uint16_t)1LL); }
if (((f31_tk()) == (((int64_t)11LL)))) { (void)(f38_perr(hr_str("_ cannot be listed with other patterns", 38)));
 }
return a_218;
 }
int64_t m_219 = f52_wbeg(); 
for (;;) { int64_t it_220 = f40_mk(((int64_t)22LL), g709); 
{ int64_t q__229 = f73_pbound(); 
{ int32_t *_t1059 = &(((*({ hrv *_t1060 = &(g704); int64_t _i1060 = it_220; (S4*)_t1060->b + hr_ix(_i1060, _t1060->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:230"); }))).a_); *_t1059 = ((int32_t)(q__229)); }
 }
if (f41_is(((int64_t)17LL))) { { int64_t q__230 = f73_pbound(); 
{ int32_t *_t1063 = &(((*({ hrv *_t1064 = &(g704); int64_t _i1064 = it_220; (S4*)_t1064->b + hr_ix(_i1064, _t1064->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:231"); }))).b_); *_t1063 = ((int32_t)(q__230)); }
 }
 }
(void)(({ hrv *_v1065 = &(g706); int32_t _x1065 = ((int32_t)(it_220)); int32_t *_p1065 = (int32_t*)hr_grow(_v1065, 1, sizeof _x1065); *_p1065 = _x1065; _p1065; }));
int64_t lo_231 = ((int64_t)(((*({ hrv *_t1066 = &(g704); int64_t _i1066 = it_220; (S4*)_t1066->b + hr_ix(_i1066, _t1066->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:233"); }))).a_)); 
if (((((((*({ hrv *_t1067 = &(g704); int64_t _i1067 = lo_231; (S4*)_t1067->b + hr_ix(_i1067, _t1067->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:234"); }))).k_) == (((uint8_t)8LL))) && ((((*({ hrv *_t1068 = &(g704); int64_t _i1068 = it_220; (S4*)_t1068->b + hr_ix(_i1068, _t1068->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:234"); }))).b_) < (((int32_t)0LL)))) && (((f31_tk()) == (((int64_t)49LL))) || ((f31_tk()) == (((int64_t)1LL)))))) { bool hasq_232 = false; 
{ hsl _v1072 = f10_nm(((int64_t)(((*({ hrv *_t1074 = &(g704); int64_t _i1074 = lo_231; (S4*)_t1074->b + hr_ix(_i1074, _t1074->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:235"); }))).s_))); for (int64_t _k1072 = 0; _k1072 < _v1072.n; _k1072++) { uint8_t c_233 = ((uint8_t*)_v1072.p)[_k1072]; if (((c_233) == (((uint8_t)58LL)))) { hasq_232 = true;
 }
 } } _bk1071:; 
if ((!(hasq_232))) { if (((((int64_t)((int64_t)(g706).n - (int64_t)m_219))) > (((int64_t)1LL)))) { (void)(f38_perr(hr_str("a list of patterns binds no payload: give the variant an arm of its own", 71)));
 }
if (f41_is(((int64_t)49LL))) { { uint16_t *_t1077 = &(((*({ hrv *_t1078 = &(g704); int64_t _i1078 = a_218; (S4*)_t1078->b + hr_ix(_i1078, _t1078->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:238"); }))).fl_); *_t1077 = ((uint16_t)((uint64_t)(*_t1077) | (uint64_t)((uint16_t)2LL))); }
 }
{ int64_t q__234 = f34_ident(hr_str("match binding", 13)); 
{ int32_t *_t1080 = &(((*({ hrv *_t1081 = &(g704); int64_t _i1081 = a_218; (S4*)_t1081->b + hr_ix(_i1081, _t1081->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:239"); }))).s_); *_t1080 = ((int32_t)(q__234)); }
 }
if (((f31_tk()) == (((int64_t)11LL)))) { (void)(f38_perr(hr_str("a list of patterns binds no payload: give the variant an arm of its own", 71)));
 }
(void)(f59_setl(a_218, m_219));
return a_218;
 }
 }
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1056; }
 }
if (f43_at_word(g725)) { (void)(f38_perr(hr_str("_ cannot be listed with other patterns", 38)));
 }
 } _bk1056:; 
(void)(f59_setl(a_218, m_219));
return a_218;
}
static int64_t f73_pbound(void) {
int64_t st_221 = g709; 
bool neg_222 = f41_is(((int64_t)22LL)); 
if ((((f31_tk()) == (((int64_t)1LL))) || ((f31_tk()) == (((int64_t)15LL))))) { int64_t n_223 = f40_mk(((int64_t)8LL), g709); 
{ int64_t q__224 = f56_qname(hr_str("match pattern", 13)); 
{ int32_t *_t1094 = &(((*({ hrv *_t1095 = &(g704); int64_t _i1095 = n_223; (S4*)_t1095->b + hr_ix(_i1095, _t1095->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:254"); }))).s_); *_t1094 = ((int32_t)(q__224)); }
 }
if (neg_222) { int64_t u_225 = f40_mk(((int64_t)10LL), st_221); 
{ uint8_t *_t1097 = &(((*({ hrv *_t1098 = &(g704); int64_t _i1098 = u_225; (S4*)_t1098->b + hr_ix(_i1098, _t1098->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:254"); }))).op_); *_t1097 = ((uint8_t)(((uint8_t)22LL))); }
{ int32_t *_t1099 = &(((*({ hrv *_t1100 = &(g704); int64_t _i1100 = u_225; (S4*)_t1100->b + hr_ix(_i1100, _t1100->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:254"); }))).a_); *_t1099 = ((int32_t)(n_223)); }
return u_225;
 }
return n_223;
 }
if (((f31_tk()) != (((int64_t)2LL)))) { hrv m_226 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1103 = &(m_226); hr_fs(_o1103, hr_str("integer constant expected in match pattern, found '", 51)); hr_fs(_o1103, f35_cur_text()); hr_fs(_o1103, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_226)));
return f40_mk(((int64_t)1LL), st_221);
 }
int64_t n_227 = f40_mk(((int64_t)1LL), g709); 
(void)(f33_nx());
if (neg_222) { int64_t u_228 = f40_mk(((int64_t)10LL), st_221); 
{ uint8_t *_t1110 = &(((*({ hrv *_t1111 = &(g704); int64_t _i1111 = u_228; (S4*)_t1111->b + hr_ix(_i1111, _t1111->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:257"); }))).op_); *_t1110 = ((uint8_t)(((uint8_t)22LL))); }
{ int32_t *_t1112 = &(((*({ hrv *_t1113 = &(g704); int64_t _i1113 = u_228; (S4*)_t1113->b + hr_ix(_i1113, _t1113->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:257"); }))).a_); *_t1112 = ((int32_t)(n_227)); }
return u_228;
 }
return n_227;
}
static int64_t f74_pvdecl(bool glob_238) {
int64_t st_239 = g709; 
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
for (;;) { (void)(({ hrv *_v1129 = &(g706); int32_t _x1129 = ((int32_t)(({ int64_t _r1130; if (glob_238) { _r1130 = f50_declname(hr_str("global declaration", 18));  } else { _r1130 = f34_ident(hr_str("variable declaration", 20));  } _r1130; }))); int32_t *_p1129 = (int32_t*)hr_grow(_v1129, 1, sizeof _x1129); *_p1129 = _x1129; _p1129; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1128; }
 }
 } _bk1128:; 
(void)(f59_setl(v_241, m_242));
{ int32_t *_t1135 = &(((*({ hrv *_t1136 = &(g704); int64_t _i1136 = v_241; (S4*)_t1136->b + hr_ix(_i1136, _t1136->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:571"); }))).c_); *_t1135 = ((int32_t)(g716)); }
if ((f41_is(((int64_t)13LL)) || f75_amni_type())) { { int64_t q__244 = f53_ptype(); 
{ int32_t *_t1140 = &(((*({ hrv *_t1141 = &(g704); int64_t _i1141 = v_241; (S4*)_t1141->b + hr_ix(_i1141, _t1141->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:572"); }))).a_); *_t1140 = ((int32_t)(q__244)); }
 }
 }
if (f41_is(((int64_t)18LL))) { { int64_t *_t1143 = &(fl_240); *_t1143 = ((int64_t)((int64_t)(*_t1143) | (int64_t)((int64_t)4LL))); }
 }
if ((((((int64_t)((int64_t)fl_240 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL))) || f41_is(((int64_t)36LL)))) { int64_t il_245 = f40_mk(((int64_t)36LL), g709); 
int64_t m2_246 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v1148 = &(g706); int32_t _x1148 = ((int32_t)(f61_pexpr())); int32_t *_p1148 = (int32_t*)hr_grow(_v1148, 1, sizeof _x1148); *_p1148 = _x1148; _p1148; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1147; }
 }
 } _bk1147:; 
(void)(f59_setl(il_245, m2_246));
{ int32_t *_t1152 = &(((*({ hrv *_t1153 = &(g704); int64_t _i1153 = v_241; (S4*)_t1153->b + hr_ix(_i1153, _t1153->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:574"); }))).b_); *_t1152 = ((int32_t)(il_245)); }
 }
{ uint16_t *_t1154 = &(((*({ hrv *_t1155 = &(g704); int64_t _i1155 = v_241; (S4*)_t1155->b + hr_ix(_i1155, _t1155->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:575"); }))).fl_); *_t1154 = ((uint16_t)(fl_240)); }
if (glob_238) { if ((((((*({ hrv *_t1156 = &(g704); int64_t _i1156 = v_241; (S4*)_t1156->b + hr_ix(_i1156, _t1156->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:577"); }))).b_) < (((int32_t)0LL))) && ((((int64_t)((int64_t)fl_240 & (int64_t)((int64_t)1LL)))) == (((int64_t)0LL))))) { (void)(f38_perr(hr_str("let and const global declarations require an initializer", 56)));
 }
if (((((*({ hrv *_t1158 = &(g704); int64_t _i1158 = v_241; (S4*)_t1158->b + hr_ix(_i1158, _t1158->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:578"); }))).n_) != (((int32_t)1LL)))) { (void)(f38_perr(hr_str("global declarations declare a single name", 41)));
 }
 }
return v_241;
}
static bool f75_amni_type(void) {
int64_t k_243 = f31_tk(); 
return (((*({ hrv *_t1161 = &(g913); int64_t _i1161 = ((*({ hrv *_t1162 = &(g914); int64_t _i1162 = g709; (S3*)_t1162->b + hr_ix(_i1162, _t1162->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:74"); }))).f_; (S2*)_t1161->b + hr_ix(_i1161, _t1161->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:74"); }))).amni_ && (((((f55_prim_tok(k_243) || ((k_243) == (((int64_t)1LL)))) || ((k_243) == (((int64_t)15LL)))) || ((k_243) == (((int64_t)61LL)))) || ((k_243) == (((int64_t)5LL)))) || ((k_243) == (((int64_t)69LL)))));
}
static void f76_pguard(int64_t b_248) {
int64_t st_249 = g709; 
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
{ int32_t *_t1173 = &(((*({ hrv *_t1174 = &(g704); int64_t _i1174 = i_253; (S4*)_t1174->b + hr_ix(_i1174, _t1174->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).a_); *_t1173 = ((int32_t)(c_250)); }
{ int32_t *_t1175 = &(((*({ hrv *_t1176 = &(g704); int64_t _i1176 = i_253; (S4*)_t1176->b + hr_ix(_i1176, _t1176->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).b_); *_t1175 = ((int32_t)(rest_252)); }
{ int32_t *_t1177 = &(((*({ hrv *_t1178 = &(g704); int64_t _i1178 = i_253; (S4*)_t1178->b + hr_ix(_i1178, _t1178->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).c_); *_t1177 = ((int32_t)(eb_251)); }
{ uint16_t *_t1179 = &(((*({ hrv *_t1180 = &(g704); int64_t _i1180 = i_253; (S4*)_t1180->b + hr_ix(_i1180, _t1180->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).fl_); *_t1179 = ((uint16_t)1LL); }
if (((((*({ hrv *_t1181 = &(g704); int64_t _i1181 = rest_252; (S4*)_t1181->b + hr_ix(_i1181, _t1181->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:560"); }))).a_) >= (((int32_t)0LL)))) { { int32_t *_t1182 = &(((*({ hrv *_t1183 = &(g704); int64_t _i1183 = b_248; (S4*)_t1183->b + hr_ix(_i1183, _t1183->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:560"); }))).a_); *_t1182 = ((int32_t)(i_253)); }
 } else { (void)(({ hrv *_v1184 = &(g706); int32_t _x1184 = ((int32_t)(i_253)); int32_t *_p1184 = (int32_t*)hr_grow(_v1184, 1, sizeof _x1184); *_p1184 = _x1184; _p1184; }));
 }
}
static int64_t f77_pmulti(int64_t first_260, int64_t st_261) {
int64_t tl_262 = f40_mk(((int64_t)36LL), st_261); 
int64_t m_263 = f52_wbeg(); 
(void)(({ hrv *_v1187 = &(g706); int32_t _x1187 = ((int32_t)(first_260)); int32_t *_p1187 = (int32_t*)hr_grow(_v1187, 1, sizeof _x1187); *_p1187 = _x1187; _p1187; }));
while (f41_is(((int64_t)11LL))) { (void)(({ hrv *_v1190 = &(g706); int32_t _x1190 = ((int32_t)(f61_pexpr())); int32_t *_p1190 = (int32_t*)hr_grow(_v1190, 1, sizeof _x1190); *_p1190 = _x1190; _p1190; }));
 } _bk1188:; 
(void)(f59_setl(tl_262, m_263));
int64_t o_264 = f31_tk(); 
if (((((((((((((o_264) == (((int64_t)18LL))) || ((o_264) == (((int64_t)26LL)))) || ((o_264) == (((int64_t)27LL)))) || ((o_264) == (((int64_t)28LL)))) || ((o_264) == (((int64_t)29LL)))) || ((o_264) == (((int64_t)30LL)))) || ((o_264) == (((int64_t)31LL)))) || ((o_264) == (((int64_t)32LL)))) || ((o_264) == (((int64_t)33LL)))) || ((o_264) == (((int64_t)45LL)))) || ((o_264) == (((int64_t)46LL))))) { (void)(f38_perr(hr_str("several targets take a call's results with `=` alone (\302\2477.1)", 60)));
 }
if (((f31_tk()) != (((int64_t)36LL)))) { (void)(f38_perr(hr_str("several values exist only in `return a, b;` and in a call's results, so a block or branch cannot end in `a, b`: return from each branch instead (\302\2477.1)", 151)));
 }
(void)(f33_nx());
int64_t n_265 = f40_mk(((int64_t)34LL), st_261); 
{ uint8_t *_t1199 = &(((*({ hrv *_t1200 = &(g704); int64_t _i1200 = n_265; (S4*)_t1200->b + hr_ix(_i1200, _t1200->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:548"); }))).op_); *_t1199 = ((uint8_t)(((uint8_t)11LL))); }
{ int32_t *_t1201 = &(((*({ hrv *_t1202 = &(g704); int64_t _i1202 = n_265; (S4*)_t1202->b + hr_ix(_i1202, _t1202->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:548"); }))).a_); *_t1201 = ((int32_t)(tl_262)); }
{ int64_t q__266 = f61_pexpr(); 
{ int32_t *_t1204 = &(((*({ hrv *_t1205 = &(g704); int64_t _i1205 = n_265; (S4*)_t1205->b + hr_ix(_i1205, _t1205->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:548"); }))).b_); *_t1204 = ((int32_t)(q__266)); }
 }
(void)(f39_ex(((int64_t)12LL), hr_str("assignment statement", 20)));
return n_265;
}
static int64_t f78_pmatch(void) {
int64_t st_271 = g709; 
(void)(f33_nx());
int64_t n_272 = f40_mk(((int64_t)20LL), st_271); 
{ int64_t q__273 = f63_pscrut(); 
{ int32_t *_t1210 = &(((*({ hrv *_t1211 = &(g704); int64_t _i1211 = n_272; (S4*)_t1211->b + hr_ix(_i1211, _t1211->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:206"); }))).a_); *_t1210 = ((int32_t)(q__273)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("match expression", 16)));
(void)(f71_parms(n_272));
(void)(f39_ex(((int64_t)10LL), hr_str("match expression", 16)));
if ((((((*({ hrv *_t1215 = &(g704); int64_t _i1215 = n_272; (S4*)_t1215->b + hr_ix(_i1215, _t1215->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:210"); }))).n_) == (((int32_t)0LL))) && (((g710).n) == (((int64_t)0LL))))) { (void)(f38_perr(hr_str("match must have at least one arm", 32)));
 }
return n_272;
}
static int64_t f79_pfor(void) {
int64_t st_283 = g709; 
(void)(f33_nx());
int64_t n_284 = f40_mk(((int64_t)27LL), st_283); 
if (f41_is(((int64_t)49LL))) { { uint16_t *_t1220 = &(((*({ hrv *_t1221 = &(g704); int64_t _i1221 = n_284; (S4*)_t1221->b + hr_ix(_i1221, _t1221->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:188"); }))).fl_); *_t1220 = ((uint16_t)1LL); }
 }
{ int64_t q__285 = f34_ident(hr_str("for binding", 11)); 
{ int32_t *_t1223 = &(((*({ hrv *_t1224 = &(g704); int64_t _i1224 = n_284; (S4*)_t1224->b + hr_ix(_i1224, _t1224->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:189"); }))).s_); *_t1223 = ((int32_t)(q__285)); }
 }
bool fb_286 = g756; 
g756 = true;
{ int32_t *_t1225 = &(((*({ hrv *_t1226 = &(g704); int64_t _i1226 = n_284; (S4*)_t1226->b + hr_ix(_i1226, _t1226->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:191"); }))).l_); *_t1225 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
{ int32_t *_t1227 = &(((*({ hrv *_t1228 = &(g704); int64_t _i1228 = n_284; (S4*)_t1228->b + hr_ix(_i1228, _t1228->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:191"); }))).n_); *_t1227 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
if (f41_is(((int64_t)13LL))) { { int64_t q__287 = f53_ptype(); 
{ int32_t *_t1231 = &(((*({ hrv *_t1232 = &(g704); int64_t _i1232 = n_284; (S4*)_t1232->b + hr_ix(_i1232, _t1232->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:192"); }))).l_); *_t1231 = ((int32_t)(q__287)); }
 }
 }
if (f41_is(((int64_t)11LL))) { { int64_t q__288 = f34_ident(hr_str("for index binding", 17)); 
{ int32_t *_t1235 = &(((*({ hrv *_t1236 = &(g704); int64_t _i1236 = n_284; (S4*)_t1236->b + hr_ix(_i1236, _t1236->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:193"); }))).c_); *_t1235 = ((int32_t)(q__288)); }
 }
if (f41_is(((int64_t)13LL))) { { int64_t q__289 = f53_ptype(); 
{ int32_t *_t1239 = &(((*({ hrv *_t1240 = &(g704); int64_t _i1240 = n_284; (S4*)_t1240->b + hr_ix(_i1240, _t1240->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:193"); }))).n_); *_t1239 = ((int32_t)(q__289)); }
 }
 }
 }
g756 = fb_286;
(void)(f39_ex(((int64_t)76LL), hr_str("for statement", 13)));
int64_t s_290 = f64_sub_begin(true); 
{ int64_t q__291 = f61_pexpr(); 
{ int32_t *_t1244 = &(((*({ hrv *_t1245 = &(g704); int64_t _i1245 = n_284; (S4*)_t1245->b + hr_ix(_i1245, _t1245->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:197"); }))).a_); *_t1244 = ((int32_t)(q__291)); }
 }
if (f41_is(((int64_t)17LL))) { { int64_t q__292 = f61_pexpr(); 
{ int32_t *_t1248 = &(((*({ hrv *_t1249 = &(g704); int64_t _i1249 = n_284; (S4*)_t1249->b + hr_ix(_i1249, _t1249->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:198"); }))).b_); *_t1248 = ((int32_t)(q__292)); }
 }
 }
(void)(f65_sub_end(s_290));
{ int64_t q__293 = f66_pblock(hr_str("for body", 8)); 
{ int32_t *_t1252 = &(((*({ hrv *_t1253 = &(g704); int64_t _i1253 = n_284; (S4*)_t1253->b + hr_ix(_i1253, _t1253->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:200"); }))).d_); *_t1252 = ((int32_t)(q__293)); }
 }
return n_284;
}
static int64_t f80_pbin(int64_t minp_304) {
int64_t l_383 = f81_pun(); 
for (;;) { if (g715) { return l_383;
 }
int64_t pr_385 = f92_binprec(f31_tk()); 
if ((((pr_385) < (minp_304)) || ((pr_385) == (((int64_t)0LL))))) { return l_383;
 }
int64_t op_386 = f31_tk(); 
int64_t st_387 = g709; 
(void)(f33_nx());
int64_t s_388 = f64_sub_begin(g713); 
int64_t r_389 = f80_pbin(((int64_t)((int64_t)pr_385 + (int64_t)((int64_t)1LL)))); 
(void)(f65_sub_end(s_388));
int64_t n_390 = f40_mk(((int64_t)9LL), st_387); 
{ uint8_t *_t1264 = &(((*({ hrv *_t1265 = &(g704); int64_t _i1265 = n_390; (S4*)_t1265->b + hr_ix(_i1265, _t1265->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:280"); }))).op_); *_t1264 = ((uint8_t)(op_386)); }
{ int32_t *_t1266 = &(((*({ hrv *_t1267 = &(g704); int64_t _i1267 = n_390; (S4*)_t1267->b + hr_ix(_i1267, _t1267->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:280"); }))).a_); *_t1266 = ((int32_t)(l_383)); }
{ int32_t *_t1268 = &(((*({ hrv *_t1269 = &(g704); int64_t _i1269 = n_390; (S4*)_t1269->b + hr_ix(_i1269, _t1269->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:280"); }))).b_); *_t1268 = ((int32_t)(r_389)); }
l_383 = n_390;
 } _bk1255:; 
}
static int64_t f81_pun(void) {
int64_t k_305 = f31_tk(); 
if ((((((k_305) == (((int64_t)22LL))) || ((k_305) == (((int64_t)47LL)))) || ((k_305) == (((int64_t)48LL)))) || ((k_305) == (((int64_t)49LL))))) { int64_t st_306 = g709; 
(void)(f33_nx());
int64_t s_307 = f64_sub_begin(g713); 
int64_t a_308 = f81_pun(); 
(void)(f65_sub_end(s_307));
int64_t n_309 = f40_mk(((int64_t)10LL), st_306); 
{ uint8_t *_t1276 = &(((*({ hrv *_t1277 = &(g704); int64_t _i1277 = n_309; (S4*)_t1277->b + hr_ix(_i1277, _t1277->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:291"); }))).op_); *_t1276 = ((uint8_t)(k_305)); }
{ int32_t *_t1278 = &(((*({ hrv *_t1279 = &(g704); int64_t _i1279 = n_309; (S4*)_t1279->b + hr_ix(_i1279, _t1279->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:291"); }))).a_); *_t1278 = ((int32_t)(a_308)); }
return n_309;
 }
return f82_ppost();
}
static int64_t f82_ppost(void) {
int64_t e_367 = f83_pprim(); 
for (;;) { if (g715) { return e_367;
 }
int64_t st_368 = g709; 
if (f41_is(((int64_t)5LL))) { e_367 = f86_pcall(e_367, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), st_368);
continue;
 }
if (((f31_tk()) == (((int64_t)7LL)))) { e_367 = f91_pindex(e_367);
continue;
 }
if (f41_is(((int64_t)16LL))) { int64_t nmid_377 = f34_ident(hr_str("field access", 12)); 
if (((((f31_tk()) == (((int64_t)9LL))) && (!(g713))) && ((((*({ hrv *_t1290 = &(g704); int64_t _i1290 = e_367; (S4*)_t1290->b + hr_ix(_i1290, _t1290->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:305"); }))).k_) == (((uint8_t)8LL))))) { int64_t b_378 = f40_mk(((int64_t)41LL), ((int64_t)(((*({ hrv *_t1292 = &(g704); int64_t _i1292 = e_367; (S4*)_t1292->b + hr_ix(_i1292, _t1292->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:306"); }))).t_))); 
{ int32_t *_t1293 = &(((*({ hrv *_t1294 = &(g704); int64_t _i1294 = b_378; (S4*)_t1294->b + hr_ix(_i1294, _t1294->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:306"); }))).s_); *_t1293 = ((*({ hrv *_t1295 = &(g704); int64_t _i1295 = e_367; (S4*)_t1295->b + hr_ix(_i1295, _t1295->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:306"); }))).s_; }
int64_t v_379 = f40_mk(((int64_t)46LL), st_368); 
{ int32_t *_t1297 = &(((*({ hrv *_t1298 = &(g704); int64_t _i1298 = v_379; (S4*)_t1298->b + hr_ix(_i1298, _t1298->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:307"); }))).a_); *_t1297 = ((int32_t)(b_378)); }
{ int32_t *_t1299 = &(((*({ hrv *_t1300 = &(g704); int64_t _i1300 = v_379; (S4*)_t1300->b + hr_ix(_i1300, _t1300->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:307"); }))).s_); *_t1299 = ((int32_t)(nmid_377)); }
e_367 = f89_pslit(v_379, st_368);
 } else { int64_t d_380 = f40_mk(((int64_t)14LL), st_368); 
{ int32_t *_t1303 = &(((*({ hrv *_t1304 = &(g704); int64_t _i1304 = d_380; (S4*)_t1304->b + hr_ix(_i1304, _t1304->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:309"); }))).a_); *_t1303 = ((int32_t)(e_367)); }
{ int32_t *_t1305 = &(((*({ hrv *_t1306 = &(g704); int64_t _i1306 = d_380; (S4*)_t1306->b + hr_ix(_i1306, _t1306->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:309"); }))).s_); *_t1305 = ((int32_t)(nmid_377)); }
e_367 = d_380;
 }
continue;
 }
if (f41_is(((int64_t)84LL))) { int64_t n_381 = f40_mk(((int64_t)15LL), st_368); 
{ uint16_t *_t1309 = &(((*({ hrv *_t1310 = &(g704); int64_t _i1310 = n_381; (S4*)_t1310->b + hr_ix(_i1310, _t1310->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:312"); }))).fl_); *_t1309 = ({ uint16_t _r1311; if (f41_is(((int64_t)47LL))) { _r1311 = ((uint16_t)1LL);  } else { _r1311 = ((uint16_t)0LL);  } _r1311; }); }
{ int32_t *_t1313 = &(((*({ hrv *_t1314 = &(g704); int64_t _i1314 = n_381; (S4*)_t1314->b + hr_ix(_i1314, _t1314->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:312"); }))).a_); *_t1313 = ((int32_t)(e_367)); }
{ int64_t q__382 = f53_ptype(); 
{ int32_t *_t1316 = &(((*({ hrv *_t1317 = &(g704); int64_t _i1317 = n_381; (S4*)_t1317->b + hr_ix(_i1317, _t1317->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:312"); }))).b_); *_t1316 = ((int32_t)(q__382)); }
 }
e_367 = n_381;
continue;
 }
return e_367;
 } _bk1282:; 
}
static int64_t f83_pprim(void) {
int64_t st_310 = g709; 
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
{ int32_t *_t1344 = &(((*({ hrv *_t1345 = &(g704); int64_t _i1345 = id_332; (S4*)_t1345->b + hr_ix(_i1345, _t1345->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:364"); }))).s_); *_t1344 = ((int32_t)(name_321)); }
return f86_pcall(id_332, ta_331, st_310);
 }
int64_t t_352 = f40_mk(((int64_t)41LL), st_310); 
{ int32_t *_t1348 = &(((*({ hrv *_t1349 = &(g704); int64_t _i1349 = t_352; (S4*)_t1349->b + hr_ix(_i1349, _t1349->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).s_); *_t1348 = ((int32_t)(name_321)); }
{ int32_t *_t1350 = &(((*({ hrv *_t1351 = &(g704); int64_t _i1351 = t_352; (S4*)_t1351->b + hr_ix(_i1351, _t1351->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).l_); *_t1350 = ((*({ hrv *_t1352 = &(g704); int64_t _i1352 = ta_331; (S4*)_t1352->b + hr_ix(_i1352, _t1352->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).l_; }
{ int32_t *_t1353 = &(((*({ hrv *_t1354 = &(g704); int64_t _i1354 = t_352; (S4*)_t1354->b + hr_ix(_i1354, _t1354->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).n_); *_t1353 = ((*({ hrv *_t1355 = &(g704); int64_t _i1355 = ta_331; (S4*)_t1355->b + hr_ix(_i1355, _t1355->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).n_; }
if (f41_is(((int64_t)16LL))) { int64_t v_353 = f40_mk(((int64_t)46LL), st_310); 
{ int32_t *_t1358 = &(((*({ hrv *_t1359 = &(g704); int64_t _i1359 = v_353; (S4*)_t1359->b + hr_ix(_i1359, _t1359->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:366"); }))).a_); *_t1358 = ((int32_t)(t_352)); }
{ int64_t q__354 = f34_ident(hr_str("variant literal", 15)); 
{ int32_t *_t1361 = &(((*({ hrv *_t1362 = &(g704); int64_t _i1362 = v_353; (S4*)_t1362->b + hr_ix(_i1362, _t1362->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:366"); }))).s_); *_t1361 = ((int32_t)(q__354)); }
 }
return f89_pslit(v_353, st_310);
 }
return f89_pslit(t_352, st_310);
 }
 }
if ((((f31_tk()) == (((int64_t)9LL))) && (!(g713)))) { int64_t t_364 = f40_mk(((int64_t)41LL), st_310); 
{ int32_t *_t1367 = &(((*({ hrv *_t1368 = &(g704); int64_t _i1368 = t_364; (S4*)_t1368->b + hr_ix(_i1368, _t1368->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:370"); }))).s_); *_t1367 = ((int32_t)(name_321)); }
return f89_pslit(t_364, st_310);
 }
int64_t id_365 = f40_mk(((int64_t)8LL), st_310); 
{ int32_t *_t1371 = &(((*({ hrv *_t1372 = &(g704); int64_t _i1372 = id_365; (S4*)_t1372->b + hr_ix(_i1372, _t1372->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:371"); }))).s_); *_t1371 = ((int32_t)(name_321)); }
return id_365;
 }
hrv m_366 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1374 = &(m_366); hr_fs(_o1374, hr_str("expression expected, found '", 28)); hr_fs(_o1374, f35_cur_text()); hr_fs(_o1374, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_366)));
return f40_mk(((int64_t)6LL), st_310);
}
static int64_t f84_parray(void) {
int64_t st_314 = g709; 
(void)(f33_nx());
int64_t a_315 = f40_mk(((int64_t)16LL), st_314); 
int64_t s_316 = f64_sub_begin(false); 
if (f41_is(((int64_t)17LL))) { { int64_t q__317 = f61_pexpr(); 
{ int32_t *_t1383 = &(((*({ hrv *_t1384 = &(g704); int64_t _i1384 = a_315; (S4*)_t1384->b + hr_ix(_i1384, _t1384->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:406"); }))).c_); *_t1383 = ((int32_t)(q__317)); }
 }
 } else { if (((f31_tk()) != (((int64_t)8LL)))) { int64_t first_318 = f61_pexpr(); 
if (f41_is(((int64_t)12LL))) { { int32_t *_t1388 = &(((*({ hrv *_t1389 = &(g704); int64_t _i1389 = a_315; (S4*)_t1389->b + hr_ix(_i1389, _t1389->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:410"); }))).a_); *_t1388 = ((int32_t)(first_318)); }
{ int64_t q__319 = f61_pexpr(); 
{ int32_t *_t1391 = &(((*({ hrv *_t1392 = &(g704); int64_t _i1392 = a_315; (S4*)_t1392->b + hr_ix(_i1392, _t1392->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:410"); }))).b_); *_t1391 = ((int32_t)(q__319)); }
 }
 } else { int64_t m_320 = f52_wbeg(); 
(void)(({ hrv *_v1394 = &(g706); int32_t _x1394 = ((int32_t)(first_318)); int32_t *_p1394 = (int32_t*)hr_grow(_v1394, 1, sizeof _x1394); *_p1394 = _x1394; _p1394; }));
while ((f41_is(((int64_t)11LL)) && ((f31_tk()) != (((int64_t)8LL))))) { (void)(({ hrv *_v1398 = &(g706); int32_t _x1398 = ((int32_t)(f61_pexpr())); int32_t *_p1398 = (int32_t*)hr_grow(_v1398, 1, sizeof _x1398); *_p1398 = _x1398; _p1398; }));
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
int64_t save_322 = g709; 
int64_t nd0_323 = (g704).n; 
int64_t ls0_324 = (g705).n; 
int64_t sp0_325 = (g718).n; 
int64_t ws0_326 = (g706).n; 
g711++;
(void)(f33_nx());
int64_t l_327 = f40_mk(((int64_t)36LL), save_322); 
int64_t m_328 = f52_wbeg(); 
bool ok_329 = false; 
for (;;) { (void)(({ hrv *_v1407 = &(g706); int32_t _x1407 = ((int32_t)(f53_ptype())); int32_t *_p1407 = (int32_t*)hr_grow(_v1407, 1, sizeof _x1407); *_p1407 = _x1407; _p1407; }));
if ((g712 || (!(f41_is(((int64_t)11LL)))))) { { goto _bk1406; }
 }
if ((((f31_tk()) == (((int64_t)40LL))) || ((f31_tk()) == (((int64_t)44LL))))) { { goto _bk1406; }
 }
 } _bk1406:; 
if ((!(g712))) { if (((f31_tk()) == (((int64_t)44LL)))) { (void)(({ hrv *_v1413 = &(g718); int64_t _x1413 = g709; int64_t *_p1413 = (int64_t*)hr_grow(_v1413, 1, sizeof _x1413); *_p1413 = _x1413; _p1413; }));
{ uint8_t *_t1414 = &(((*({ hrv *_t1415 = &(g914); int64_t _i1415 = g709; (S3*)_t1415->b + hr_ix(_i1415, _t1415->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:386"); }))).k_); *_t1414 = ((uint8_t)(((uint8_t)40LL))); }
ok_329 = true;
 } else { if (((f31_tk()) == (((int64_t)40LL)))) { (void)(f33_nx());
ok_329 = true;
 }
 }
if (ok_329) { ok_329 = false;
if ((((f31_tk()) == (((int64_t)5LL))) || (((f31_tk()) == (((int64_t)9LL))) && (!(g713))))) { ok_329 = true;
 }
if ((((((f31_tk()) == (((int64_t)16LL))) && (!(g713))) && ((f44_tkat(((int64_t)((int64_t)g709 + (int64_t)((int64_t)1LL))))) == (((int64_t)1LL)))) && ((f44_tkat(((int64_t)((int64_t)g709 + (int64_t)((int64_t)2LL))))) == (((int64_t)9LL))))) { ok_329 = true;
 }
 }
 }
g711--;
if ((ok_329 && (!(g712)))) { (void)(f59_setl(l_327, m_328));
return l_327;
 }
g712 = false;
while ((((g718).n) > (sp0_325))) { int64_t q_330 = ({ hrv *_v1425 = &(g718); if (!_v1425->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:396"); ((int64_t*)_v1425->b)[--_v1425->n]; }); 
{ uint8_t *_t1426 = &(((*({ hrv *_t1427 = &(g914); int64_t _i1427 = q_330; (S3*)_t1427->b + hr_ix(_i1427, _t1427->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:396"); }))).k_); *_t1426 = ((uint8_t)(((uint8_t)44LL))); }
 } _bk1424:; 
if ((((g706).n) > (ws0_326))) { (void)(({ hrv *_v1428 = &(g706); int64_t _k1428 = ((int64_t)((int64_t)(g706).n - (int64_t)ws0_326)); if (_k1428 < 0 || _k1428 > _v1428->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:397"); _v1428->n -= _k1428; }));
 }
(void)(({ hrv *_v1429 = &(g704); int64_t _k1429 = nd0_323; if (_k1429 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:398"); S4 _x1429 = ((S4){ 0}); int64_t _o1429 = _v1429->n; hr_resize(_v1429, _k1429, sizeof _x1429); for (int64_t _j = _o1429; _j < _k1429; _j++) ((S4*)_v1429->b)[_j] = _x1429; }));
(void)(({ hrv *_v1430 = &(g705); int64_t _k1430 = ls0_324; if (_k1430 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:398"); int32_t _x1430 = ((int32_t)0LL); int64_t _o1430 = _v1430->n; hr_resize(_v1430, _k1430, sizeof _x1430); for (int64_t _j = _o1430; _j < _k1430; _j++) ((int32_t*)_v1430->b)[_j] = _x1430; }));
g709 = save_322;
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f86_pcall(int64_t callee_333, int64_t tyargs_334, int64_t st_335) {
int64_t c_336 = f40_mk(((int64_t)11LL), st_335); 
{ int32_t *_t1432 = &(((*({ hrv *_t1433 = &(g704); int64_t _i1433 = c_336; (S4*)_t1433->b + hr_ix(_i1433, _t1433->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:317"); }))).a_); *_t1432 = ((int32_t)(callee_333)); }
{ int32_t *_t1434 = &(((*({ hrv *_t1435 = &(g704); int64_t _i1435 = c_336; (S4*)_t1435->b + hr_ix(_i1435, _t1435->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:317"); }))).c_); *_t1434 = ((int32_t)(tyargs_334)); }
int64_t s_337 = f64_sub_begin(false); 
int64_t m_338 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v1441 = &(g706); int32_t _x1441 = ((int32_t)(f61_pexpr())); int32_t *_p1441 = (int32_t*)hr_grow(_v1441, 1, sizeof _x1441); *_p1441 = _x1441; _p1441; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1438; }
 }
 } _bk1438:; 
(void)(f39_ex(((int64_t)6LL), hr_str("call arguments", 14)));
(void)(f59_setl(c_336, m_338));
(void)(f65_sub_end(s_337));
if ((((f31_tk()) == (((int64_t)9LL))) && (!(g713)))) { { int64_t q__351 = f87_pfunval(); 
{ int32_t *_t1449 = &(((*({ hrv *_t1450 = &(g704); int64_t _i1450 = c_336; (S4*)_t1450->b + hr_ix(_i1450, _t1450->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:324"); }))).b_); *_t1449 = ((int32_t)(q__351)); }
 }
if (g714) { g715 = true;
 }
 }
return c_336;
}
static int64_t f87_pfunval(void) {
int64_t st_339 = g709; 
(void)(f39_ex(((int64_t)9LL), hr_str("function value", 14)));
int64_t fv_340 = f40_mk(((int64_t)31LL), st_339); 
int64_t b_341 = f40_mk(((int64_t)23LL), st_339); 
{ int32_t *_t1454 = &(((*({ hrv *_t1455 = &(g704); int64_t _i1455 = fv_340; (S4*)_t1455->b + hr_ix(_i1455, _t1455->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:476"); }))).a_); *_t1454 = ((int32_t)(b_341)); }
if ((((f31_tk()) == (((int64_t)1LL))) || ((f31_tk()) == (((int64_t)67LL))))) { int64_t save_342 = g709; 
int64_t nd0_343 = (g704).n; 
int64_t ws0_344 = (g706).n; 
g711++;
bool ok_345 = true; 
int64_t m_346 = f52_wbeg(); 
for (;;) { bool pv_347 = f41_is(((int64_t)67LL)); 
if (((f31_tk()) != (((int64_t)1LL)))) { ok_345 = false;
{ goto _bk1459; }
 }
int64_t p_348 = f40_mk(((int64_t)32LL), g709); 
{ int32_t *_t1463 = &(((*({ hrv *_t1464 = &(g704); int64_t _i1464 = p_348; (S4*)_t1464->b + hr_ix(_i1464, _t1464->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:485"); }))).s_); *_t1463 = ((int32_t)(((*({ hrv *_t1465 = &(g914); int64_t _i1465 = g709; (S3*)_t1465->b + hr_ix(_i1465, _t1465->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:485"); }))).v_)); }
if (pv_347) { { uint16_t *_t1466 = &(((*({ hrv *_t1467 = &(g704); int64_t _i1467 = p_348; (S4*)_t1467->b + hr_ix(_i1467, _t1467->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:485"); }))).fl_); *_t1466 = ((uint16_t)1LL); }
 }
(void)(f33_nx());
if (f41_is(((int64_t)13LL))) { { int64_t q__349 = f53_ptype(); 
{ int32_t *_t1471 = &(((*({ hrv *_t1472 = &(g704); int64_t _i1472 = p_348; (S4*)_t1472->b + hr_ix(_i1472, _t1472->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:486"); }))).a_); *_t1471 = ((int32_t)(q__349)); }
 }
 }
(void)(({ hrv *_v1473 = &(g706); int32_t _x1473 = ((int32_t)(p_348)); int32_t *_p1473 = (int32_t*)hr_grow(_v1473, 1, sizeof _x1473); *_p1473 = _x1473; _p1473; }));
if ((g712 || (!(f41_is(((int64_t)11LL)))))) { { goto _bk1459; }
 }
 } _bk1459:; 
if (((g712 || (!(ok_345))) || (!(f41_is(((int64_t)55LL)))))) { ok_345 = false;
 }
g711--;
if (ok_345) { (void)(f59_setl(fv_340, m_346));
{ uint16_t *_t1477 = &(((*({ hrv *_t1478 = &(g704); int64_t _i1478 = fv_340; (S4*)_t1478->b + hr_ix(_i1478, _t1478->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:492"); }))).fl_); *_t1477 = ((uint16_t)1LL); }
 } else { g712 = false;
if ((((g706).n) > (ws0_344))) { (void)(({ hrv *_v1479 = &(g706); int64_t _k1479 = ((int64_t)((int64_t)(g706).n - (int64_t)ws0_344)); if (_k1479 < 0 || _k1479 > _v1479->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:493"); _v1479->n -= _k1479; }));
 }
(void)(({ hrv *_v1480 = &(g704); int64_t _k1480 = nd0_343; if (_k1480 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:493"); S4 _x1480 = ((S4){ 0}); int64_t _o1480 = _v1480->n; hr_resize(_v1480, _k1480, sizeof _x1480); for (int64_t _j = _o1480; _j < _k1480; _j++) ((S4*)_v1480->b)[_j] = _x1480; }));
g709 = save_342;
 }
 }
(void)(f67_pbody(b_341));
(void)(f88_set_end(fv_340));
return fv_340;
}
static void f88_set_end(int64_t n_350) {
while ((((g719).n) < ((g704).n))) { (void)(({ hrv *_v1484 = &(g719); int32_t _x1484 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1484 = (int32_t*)hr_grow(_v1484, 1, sizeof _x1484); *_p1484 = _x1484; _p1484; }));
 } _bk1483:; 
{ int32_t *_t1485 = &((*({ hrv *_t1486 = &(g719); int64_t _i1486 = n_350; (int32_t*)_t1486->b + hr_ix(_i1486, _t1486->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:28"); }))); *_t1485 = ((int32_t)((g704).n)); }
}
static int64_t f89_pslit(int64_t ty_355, int64_t st_356) {
int64_t n_357 = f40_mk(((int64_t)17LL), st_356); 
{ int32_t *_t1488 = &(((*({ hrv *_t1489 = &(g704); int64_t _i1489 = n_357; (S4*)_t1489->b + hr_ix(_i1489, _t1489->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:464"); }))).a_); *_t1488 = ((int32_t)(ty_355)); }
(void)(f70_pinits(n_357, false));
int64_t named_358 = ((int64_t)0LL); 
bool cf_359 = false; 
{ int32_t _e1492 = ((*({ hrv *_t1493 = &(g704); int64_t _i1493 = n_357; (S4*)_t1493->b + hr_ix(_i1493, _t1493->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:467"); }))).n_; for (int32_t _k1492 = 0; _k1492 < _e1492; _k1492++) { int32_t i_360 = (int32_t)_k1492; int64_t fi_363 = f90_kid(n_357, ((int64_t)(i_360))); 
if (((((*({ hrv *_t1495 = &(g704); int64_t _i1495 = fi_363; (S4*)_t1495->b + hr_ix(_i1495, _t1495->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:467"); }))).k_) == (((uint8_t)37LL)))) { cf_359 = true;
 } else { if (((((*({ hrv *_t1496 = &(g704); int64_t _i1496 = fi_363; (S4*)_t1496->b + hr_ix(_i1496, _t1496->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:467"); }))).s_) >= (((int32_t)0LL)))) { named_358++;
 }
 }
 } } _bk1491:; 
if ((((!(cf_359)) && ((named_358) > (((int64_t)0LL)))) && ((named_358) != (((int64_t)(((*({ hrv *_t1497 = &(g704); int64_t _i1497 = n_357; (S4*)_t1497->b + hr_ix(_i1497, _t1497->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:468"); }))).n_)))))) { (void)(f38_perr(hr_str("struct literal mixes named and positional initializers", 54)));
 }
return n_357;
}
static int64_t f90_kid(int64_t n_361, int64_t i_362) {
return ((int64_t)((*({ hrv *_t1499 = &(g705); int64_t _i1499 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1500 = &(g704); int64_t _i1500 = n_361; (S4*)_t1500->b + hr_ix(_i1500, _t1500->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:56"); }))).l_)) + (int64_t)i_362)); (int32_t*)_t1499->b + hr_ix(_i1499, _t1499->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:56"); }))));
}
static int64_t f91_pindex(int64_t obj_369) {
int64_t st_370 = g709; 
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
{ int32_t *_t1509 = &(((*({ hrv *_t1510 = &(g704); int64_t _i1510 = r_375; (S4*)_t1510->b + hr_ix(_i1510, _t1510->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:336"); }))).a_); *_t1509 = ((int32_t)(obj_369)); }
{ int32_t *_t1511 = &(((*({ hrv *_t1512 = &(g704); int64_t _i1512 = r_375; (S4*)_t1512->b + hr_ix(_i1512, _t1512->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:336"); }))).b_); *_t1511 = ((int32_t)(lo_372)); }
if (lfe_373) { { uint16_t *_t1513 = &(((*({ hrv *_t1514 = &(g704); int64_t _i1514 = r_375; (S4*)_t1514->b + hr_ix(_i1514, _t1514->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:337"); }))).fl_); *_t1513 = ((uint16_t)1LL); }
 }
if (((f31_tk()) != (((int64_t)8LL)))) { if (f41_is(((int64_t)51LL))) { { uint16_t *_t1517 = &(((*({ hrv *_t1518 = &(g704); int64_t _i1518 = r_375; (S4*)_t1518->b + hr_ix(_i1518, _t1518->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:338"); }))).fl_); *_t1517 = ((uint16_t)((uint64_t)(*_t1517) | (uint64_t)((uint16_t)2LL))); }
 }
{ int64_t q__376 = f61_pexpr(); 
{ int32_t *_t1520 = &(((*({ hrv *_t1521 = &(g704); int64_t _i1521 = r_375; (S4*)_t1521->b + hr_ix(_i1521, _t1521->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:338"); }))).c_); *_t1520 = ((int32_t)(q__376)); }
 }
 }
 } else { if (lfe_373) { (void)(f38_perr(hr_str("'^' bounds are only valid in slices", 35)));
 }
r_375 = f40_mk(((int64_t)12LL), st_370);
{ int32_t *_t1524 = &(((*({ hrv *_t1525 = &(g704); int64_t _i1525 = r_375; (S4*)_t1525->b + hr_ix(_i1525, _t1525->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:341"); }))).a_); *_t1524 = ((int32_t)(obj_369)); }
{ int32_t *_t1526 = &(((*({ hrv *_t1527 = &(g704); int64_t _i1527 = r_375; (S4*)_t1527->b + hr_ix(_i1527, _t1527->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:341"); }))).b_); *_t1526 = ((int32_t)(lo_372)); }
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
int64_t st_414 = g709; 
(void)(f33_nx());
int64_t n_415 = f40_mk(((int64_t)51LL), st_414); 
{ int64_t q__416 = f50_declname(hr_str("struct declaration", 18)); 
{ int32_t *_t1536 = &(((*({ hrv *_t1537 = &(g704); int64_t _i1537 = n_415; (S4*)_t1537->b + hr_ix(_i1537, _t1537->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:618"); }))).s_); *_t1536 = ((int32_t)(q__416)); }
 }
{ int32_t *_t1538 = &(((*({ hrv *_t1539 = &(g704); int64_t _i1539 = n_415; (S4*)_t1539->b + hr_ix(_i1539, _t1539->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:618"); }))).a_); *_t1538 = ((int32_t)(g716)); }
{ int64_t q__417 = f51_pgenerics(); 
{ int32_t *_t1541 = &(((*({ hrv *_t1542 = &(g704); int64_t _i1542 = n_415; (S4*)_t1542->b + hr_ix(_i1542, _t1542->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:619"); }))).d_); *_t1541 = ((int32_t)(q__417)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("struct declaration", 18)));
(void)(f95_pfields(n_415, hr_str("struct body", 11)));
(void)(f39_ex(((int64_t)10LL), hr_str("struct declaration", 18)));
return n_415;
}
static void f95_pfields(int64_t n_418, hsl ctx_419) {
int64_t m_420 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t f_421 = f40_mk(((int64_t)55LL), g709); 
if (f41_is(((int64_t)70LL))) { { uint16_t *_t1552 = &(((*({ hrv *_t1553 = &(g704); int64_t _i1553 = f_421; (S4*)_t1553->b + hr_ix(_i1553, _t1553->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:601"); }))).fl_); *_t1552 = ((uint16_t)4LL); }
if (((f31_tk()) == (((int64_t)2LL)))) { { int32_t *_t1555 = &(((*({ hrv *_t1556 = &(g704); int64_t _i1556 = f_421; (S4*)_t1556->b + hr_ix(_i1556, _t1556->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:601"); }))).c_); *_t1555 = ((int32_t)(((*({ hrv *_t1557 = &(g914); int64_t _i1557 = g709; (S3*)_t1557->b + hr_ix(_i1557, _t1557->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:601"); }))).v_)); }
(void)(f33_nx());
 }
 } else { bool cq_422 = f41_is(((int64_t)69LL)); 
if ((cq_422 || f41_is(((int64_t)66LL)))) { { uint16_t *_t1561 = &(((*({ hrv *_t1562 = &(g704); int64_t _i1562 = f_421; (S4*)_t1562->b + hr_ix(_i1562, _t1562->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:604"); }))).fl_); *_t1561 = ({ uint16_t _r1563; if (cq_422) { _r1563 = ((uint16_t)3LL);  } else { _r1563 = ((uint16_t)1LL);  } _r1563; }); }
 }
{ int64_t q__423 = f34_ident(ctx_419); 
{ int32_t *_t1565 = &(((*({ hrv *_t1566 = &(g704); int64_t _i1566 = f_421; (S4*)_t1566->b + hr_ix(_i1566, _t1566->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:605"); }))).s_); *_t1565 = ((int32_t)(q__423)); }
 }
if ((!(f75_amni_type()))) { (void)(f39_ex(((int64_t)13LL), ctx_419));
 }
{ int64_t q__424 = f53_ptype(); 
{ int32_t *_t1570 = &(((*({ hrv *_t1571 = &(g704); int64_t _i1571 = f_421; (S4*)_t1571->b + hr_ix(_i1571, _t1571->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:607"); }))).a_); *_t1570 = ((int32_t)(q__424)); }
 }
if (f41_is(((int64_t)36LL))) { { int64_t q__425 = f61_pexpr(); 
{ int32_t *_t1574 = &(((*({ hrv *_t1575 = &(g704); int64_t _i1575 = f_421; (S4*)_t1575->b + hr_ix(_i1575, _t1575->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:608"); }))).b_); *_t1574 = ((int32_t)(q__425)); }
 }
 }
 }
(void)(({ hrv *_v1576 = &(g706); int32_t _x1576 = ((int32_t)(f_421)); int32_t *_p1576 = (int32_t*)hr_grow(_v1576, 1, sizeof _x1576); *_p1576 = _x1576; _p1576; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1547; }
 }
 } _bk1547:; 
(void)(f59_setl(n_418, m_420));
}
static int64_t f96_penum(void) {
int64_t st_426 = g709; 
(void)(f33_nx());
int64_t n_427 = f40_mk(((int64_t)52LL), st_426); 
{ int64_t q__428 = f50_declname(hr_str("enum declaration", 16)); 
{ int32_t *_t1582 = &(((*({ hrv *_t1583 = &(g704); int64_t _i1583 = n_427; (S4*)_t1583->b + hr_ix(_i1583, _t1583->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:628"); }))).s_); *_t1582 = ((int32_t)(q__428)); }
 }
{ int32_t *_t1584 = &(((*({ hrv *_t1585 = &(g704); int64_t _i1585 = n_427; (S4*)_t1585->b + hr_ix(_i1585, _t1585->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:628"); }))).a_); *_t1584 = ((int32_t)(g716)); }
{ int64_t q__429 = f51_pgenerics(); 
{ int32_t *_t1587 = &(((*({ hrv *_t1588 = &(g704); int64_t _i1588 = n_427; (S4*)_t1588->b + hr_ix(_i1588, _t1588->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:629"); }))).d_); *_t1587 = ((int32_t)(q__429)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("enum declaration", 16)));
int64_t m_430 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t v_431 = f40_mk(((int64_t)56LL), g709); 
{ int64_t q__432 = f34_ident(hr_str("enum variant", 12)); 
{ int32_t *_t1596 = &(((*({ hrv *_t1597 = &(g704); int64_t _i1597 = v_431; (S4*)_t1597->b + hr_ix(_i1597, _t1597->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:633"); }))).s_); *_t1596 = ((int32_t)(q__432)); }
 }
if (f41_is(((int64_t)9LL))) { { uint16_t *_t1599 = &(((*({ hrv *_t1600 = &(g704); int64_t _i1600 = v_431; (S4*)_t1600->b + hr_ix(_i1600, _t1600->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:634"); }))).fl_); *_t1599 = ((uint16_t)1LL); }
(void)(f95_pfields(v_431, hr_str("variant body", 12)));
(void)(f39_ex(((int64_t)10LL), hr_str("enum variant", 12)));
 }
(void)(({ hrv *_v1603 = &(g706); int32_t _x1603 = ((int32_t)(v_431)); int32_t *_p1603 = (int32_t*)hr_grow(_v1603, 1, sizeof _x1603); *_p1603 = _x1603; _p1603; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1591; }
 }
 } _bk1591:; 
(void)(f59_setl(n_427, m_430));
(void)(f39_ex(((int64_t)10LL), hr_str("enum declaration", 16)));
return n_427;
}
static void f97_collect(int64_t file_440, int64_t t0_441, int64_t t1_442) {
{ int64_t _e1608 = t1_442; for (int64_t _k1608 = t0_441; _k1608 < _e1608; _k1608++) { int64_t i_443 = (int64_t)_k1608; int64_t n_444 = ((int64_t)((*({ hrv *_t1609 = &(g707); int64_t _i1609 = i_443; (int32_t*)_t1609->b + hr_ix(_i1609, _t1609->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:27"); })))); 
S4 x_445 = (*({ hrv *_t1610 = &(g704); int64_t _i1610 = n_444; (S4*)_t1610->b + hr_ix(_i1610, _t1610->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:28"); })); 
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
if (((k_446) == (((int64_t)33LL)))) { (void)(f99_dadd(((int64_t)5LL), n_444, file_440, f98_qual(((int64_t)((x_445).c_)), ((int64_t)((*({ hrv *_t1622 = &(g705); int64_t _i1622 = (x_445).l_; (int32_t*)_t1622->b + hr_ix(_i1622, _t1622->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:34"); })))))));
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
while ((((g490).n) <= (name_453))) { (void)(({ hrv *_v1632 = &(g490); int32_t _x1632 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1632 = (int32_t*)hr_grow(_v1632, 1, sizeof _x1632); *_p1632 = _x1632; _p1632; }));
 } _bk1631:; 
int64_t i_454 = (g489).n; 
(void)(({ hrv *_v1633 = &(g489); S5 _x1633 = ((S5){ .k_ = ((uint8_t)(k_450)), .node_ = ((int32_t)(node_451)), .file_ = ((int32_t)(file_452)), .next_ = (*({ hrv *_t1634 = &(g490); int64_t _i1634 = name_453; (int32_t*)_t1634->b + hr_ix(_i1634, _t1634->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:19"); })), .name_ = ((int32_t)(name_453)), }); S5 *_p1633 = (S5*)hr_grow(_v1633, 1, sizeof _x1633); *_p1633 = _x1633; _p1633; }));
{ int32_t *_t1635 = &((*({ hrv *_t1636 = &(g490); int64_t _i1636 = name_453; (int32_t*)_t1636->b + hr_ix(_i1636, _t1636->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:20"); }))); *_t1635 = ((int32_t)(i_454)); }
}
static L49 f100_lib_path(hsl name_459) {
L49 p_460 = ({ L49 _t1637; memset(&_t1637, 0, sizeof _t1637); _t1637.n = 0; _t1637; }); 
(void)(({ L49 *_v1638 = &(p_460); hsl _s1638 = hr_sl(g493); if (_v1638->n + _s1638.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); memmove(_v1638->e + _v1638->n, _s1638.p, (size_t)_s1638.n * sizeof _v1638->e[0]); _v1638->n += _s1638.n; }));
(void)(({ L49 *_v1639 = &(p_460); uint8_t _x1639 = ((uint8_t)47LL); if (_v1639->n >= 1024) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); _v1639->e[_v1639->n] = _x1639; &_v1639->e[_v1639->n++]; }));
(void)(({ L49 *_v1640 = &(p_460); hsl _s1640 = name_459; if (_v1640->n + _s1640.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); memmove(_v1640->e + _v1640->n, _s1640.p, (size_t)_s1640.n * sizeof _v1640->e[0]); _v1640->n += _s1640.n; }));
(void)(({ L49 *_v1641 = &(p_460); hsl _s1641 = hr_str(".amni", 5); if (_v1641->n + _s1641.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); memmove(_v1641->e + _v1641->n, _s1641.p, (size_t)_s1641.n * sizeof _v1641->e[0]); _v1641->n += _s1641.n; }));
return p_460;
}
static int64_t f101_load_import(int64_t name_463, int64_t from_464, int64_t t_465) {
L49 p_466 = ({ L49 _t1642; memset(&_t1642, 0, sizeof _t1642); _t1642.n = 0; _t1642; }); 
(void)(({ L49 *_v1643 = &(p_466); hsl _s1643 = hr_sl(g492); if (_v1643->n + _s1643.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:59"); memmove(_v1643->e + _v1643->n, _s1643.p, (size_t)_s1643.n * sizeof _v1643->e[0]); _v1643->n += _s1643.n; }));
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
if ((((g495).n) > (((int64_t)0LL)))) { return;
 }
S3 x_474 = (*({ hrv *_t1660 = &(g914); int64_t _i1660 = f103_max(t_470, ((int64_t)0LL)); (S3*)_t1660->b + hr_ix(_i1660, _t1660->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:14"); })); 
(void)(({ hrv *_v1662 = &(g495); hsl _s1662 = f10_nm(((int64_t)(((*({ hrv *_t1664 = &(g913); int64_t _i1664 = (x_474).f_; (S2*)_t1664->b + hr_ix(_i1664, _t1664->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:14"); }))).name_))); hr_append(_v1662, _s1662.p, _s1662.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o1665 = &(g495); hr_fs(_o1665, hr_str(":", 1)); hr_fi(_o1665, (x_474).line_); hr_fs(_o1665, hr_str(": error: ", 9)); hr_fs(_o1665, m_471); }));
}
static int64_t f103_max(int64_t a_472, int64_t b_473) {
if (((a_472) < (b_473))) { return b_473;
 }
return a_472;
}
static bool f104_check_program(void) {
g403 = f105_new_inst(((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)0LL), (g704).n, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
{ uint8_t *_t1667 = &(((*({ hrv *_t1668 = &(g388); int64_t _i1668 = g403; (S6*)_t1668->b + hr_ix(_i1668, _t1668->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:498"); }))).st_); *_t1667 = ((uint8_t)2LL); }
g401 = g403;
g402 = g403;
int64_t md_489 = f106_lookup(f8_intern(hr_str("main", 4)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)4LL)); 
if (((md_489) < (((int64_t)0LL)))) { (void)(f108_cerr(((int64_t)0LL), hr_str("no main function", 16)));
return false;
 }
{ hrv *_v1673 = &(g489); for (int64_t _k1673 = 0; _k1673 < _v1673->n; _k1673++) { S5 d_493 = ((S5*)_v1673->b)[_k1673]; int64_t i_494 = (int64_t)_k1673; if ((((((int64_t)((d_493).k_))) == (((int64_t)5LL))) && (((d_493).file_) == (((int32_t)0LL))))) { (void)(f109_global_type(i_494));
 }
 } } _bk1672:; 
int64_t mi_1484 = f252_get_inst(((int64_t)(((*({ hrv *_t1676 = &(g489); int64_t _i1676 = md_489; (S5*)_t1676->b + hr_ix(_i1676, _t1676->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:503"); }))).node_)), (g314).n, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
{ hrv *_v1678 = &(g489); for (int64_t _k1678 = 0; _k1678 < _v1678->n; _k1678++) { S5 d_1485 = ((S5*)_v1678->b)[_k1678]; int64_t i_1486 = (int64_t)_k1678; if (((((int64_t)((d_1485).k_))) == (((int64_t)5LL)))) { (void)(f109_global_type(i_1486));
 }
 } } _bk1677:; 
(void)(f258_propagate_calls());
return ((g405) == (((int64_t)0LL)));
}
static int64_t f105_new_inst(int64_t node_477, int64_t lo_478, int64_t hi_479, int64_t par_480) {
int64_t i_481 = (g388).n; 
(void)(({ hrv *_v1681 = &(g388); S6 _x1681 = ((S6){ .node_ = ((int32_t)(node_477)), .lo_ = ((int32_t)(lo_478)), .hi_ = ((int32_t)(hi_479)), .ab_ = ((int32_t)((g395).n)), .par_ = ((int32_t)(par_480)), .cfn_ = ((int32_t)(i_481)), .g0_ = ((int32_t)((g394).n)), .gn_ = ((int32_t)0LL), .ret_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .p0_ = ((int32_t)0LL), .pn_ = ((int32_t)0LL), .st_ = ((uint8_t)0LL), .blk_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .bown_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .name_ = ({ int32_t _r1682; if (((node_477) >= (((int64_t)0LL)))) { _r1682 = ((*({ hrv *_t1683 = &(g704); int64_t _i1683 = node_477; (S4*)_t1683->b + hr_ix(_i1683, _t1683->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:30"); }))).s_;  } else { _r1682 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));  } _r1682; }), }); S6 *_p1681 = (S6*)hr_grow(_v1681, 1, sizeof _x1681); *_p1681 = _x1681; _p1681; }));
int64_t n_482 = ((int64_t)((int64_t)hi_479 - (int64_t)lo_478)); 
(void)(({ hrv *_v1684 = &(g395); int64_t _k1684 = ((int64_t)((int64_t)(g395).n + (int64_t)n_482)); if (_k1684 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1684 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1684 = _v1684->n; hr_resize(_v1684, _k1684, sizeof _x1684); for (int64_t _j = _o1684; _j < _k1684; _j++) ((int32_t*)_v1684->b)[_j] = _x1684; }));
(void)(({ hrv *_v1685 = &(g396); int64_t _k1685 = ((int64_t)((int64_t)(g396).n + (int64_t)n_482)); if (_k1685 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1685 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1685 = _v1685->n; hr_resize(_v1685, _k1685, sizeof _x1685); for (int64_t _j = _o1685; _j < _k1685; _j++) ((int32_t*)_v1685->b)[_j] = _x1685; }));
(void)(({ hrv *_v1686 = &(g397); int64_t _k1686 = ((int64_t)((int64_t)(g397).n + (int64_t)n_482)); if (_k1686 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); uint8_t _x1686 = ((uint8_t)0LL); int64_t _o1686 = _v1686->n; hr_resize(_v1686, _k1686, sizeof _x1686); for (int64_t _j = _o1686; _j < _k1686; _j++) ((uint8_t*)_v1686->b)[_j] = _x1686; }));
(void)(({ hrv *_v1687 = &(g398); int64_t _k1687 = ((int64_t)((int64_t)(g398).n + (int64_t)n_482)); if (_k1687 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1687 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1687 = _v1687->n; hr_resize(_v1687, _k1687, sizeof _x1687); for (int64_t _j = _o1687; _j < _k1687; _j++) ((int32_t*)_v1687->b)[_j] = _x1687; }));
(void)(({ hrv *_v1688 = &(g399); int64_t _k1688 = ((int64_t)((int64_t)(g399).n + (int64_t)n_482)); if (_k1688 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1688 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1688 = _v1688->n; hr_resize(_v1688, _k1688, sizeof _x1688); for (int64_t _j = _o1688; _j < _k1688; _j++) ((int32_t*)_v1688->b)[_j] = _x1688; }));
return i_481;
}
static int64_t f106_lookup(int64_t name_483, int64_t ns_484, int64_t k_485) {
if (((ns_484) >= (((int64_t)0LL)))) { int64_t d_487 = f107_dmap(f98_qual(ns_484, name_483)); 
while (((d_487) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1692 = &(g489); int64_t _i1692 = d_487; (S5*)_t1692->b + hr_ix(_i1692, _t1692->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:74"); }))).k_))) == (k_485))) { return d_487;
 }
d_487 = ((int64_t)(((*({ hrv *_t1693 = &(g489); int64_t _i1693 = d_487; (S5*)_t1693->b + hr_ix(_i1693, _t1693->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:74"); }))).next_));
 } _bk1691:; 
 }
int64_t d_488 = f107_dmap(name_483); 
while (((d_488) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1696 = &(g489); int64_t _i1696 = d_488; (S5*)_t1696->b + hr_ix(_i1696, _t1696->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:76"); }))).k_))) == (k_485))) { return d_488;
 }
d_488 = ((int64_t)(((*({ hrv *_t1697 = &(g489); int64_t _i1697 = d_488; (S5*)_t1697->b + hr_ix(_i1697, _t1697->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:76"); }))).next_));
 } _bk1695:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f107_dmap(int64_t name_486) {
return ({ int64_t _r1698; if ((((name_486) < (((int64_t)0LL))) || ((name_486) >= ((g490).n)))) { _r1698 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1698 = ((int64_t)((*({ hrv *_t1699 = &(g490); int64_t _i1699 = name_486; (int32_t*)_t1699->b + hr_ix(_i1699, _t1699->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:15"); }))));  } _r1698; });
}
static void f108_cerr(int64_t n_490, hsl m_491) {
g405++;
if ((((g404).n) > (((int64_t)0LL)))) { return;
 }
S3 x_492 = (*({ hrv *_t1700 = &(g914); int64_t _i1700 = ((*({ hrv *_t1701 = &(g704); int64_t _i1701 = f103_max(n_490, ((int64_t)0LL)); (S4*)_t1701->b + hr_ix(_i1701, _t1701->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:27"); }))).t_; (S3*)_t1700->b + hr_ix(_i1700, _t1700->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:27"); })); 
(void)(({ hrv *_v1703 = &(g404); hsl _s1703 = f10_nm(((int64_t)(((*({ hrv *_t1705 = &(g913); int64_t _i1705 = (x_492).f_; (S2*)_t1705->b + hr_ix(_i1705, _t1705->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:27"); }))).name_))); hr_append(_v1703, _s1703.p, _s1703.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o1706 = &(g404); hr_fs(_o1706, hr_str(":", 1)); hr_fi(_o1706, (x_492).line_); hr_fs(_o1706, hr_str(": error: ", 9)); hr_fs(_o1706, m_491); }));
}
static int64_t f109_global_type(int64_t d_495) {
while ((((g450).n) < ((g489).n))) { (void)(({ hrv *_v1708 = &(g450); int32_t _x1708 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1708 = (int32_t*)hr_grow(_v1708, 1, sizeof _x1708); *_p1708 = _x1708; _p1708; }));
(void)(({ hrv *_v1709 = &(g451); uint8_t _x1709 = ((uint8_t)0LL); uint8_t *_p1709 = (uint8_t*)hr_grow(_v1709, 1, sizeof _x1709); *_p1709 = _x1709; _p1709; }));
 } _bk1707:; 
if ((((*({ hrv *_t1710 = &(g450); int64_t _i1710 = d_495; (int32_t*)_t1710->b + hr_ix(_i1710, _t1710->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:381"); }))) >= (((int32_t)0LL)))) { return ((int64_t)((*({ hrv *_t1711 = &(g450); int64_t _i1711 = d_495; (int32_t*)_t1711->b + hr_ix(_i1711, _t1711->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:381"); }))));
 }
int64_t g_496 = ((int64_t)(((*({ hrv *_t1712 = &(g489); int64_t _i1712 = d_495; (S5*)_t1712->b + hr_ix(_i1712, _t1712->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:382"); }))).node_)); 
S4 x_497 = (*({ hrv *_t1713 = &(g704); int64_t _i1713 = g_496; (S4*)_t1713->b + hr_ix(_i1713, _t1713->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:383"); })); 
int64_t saved_498 = g401; 
int64_t sc_499 = g402; 
g401 = g403;
g402 = g403;
int64_t t_500 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((x_497).a_) >= (((int32_t)0LL)))) { t_500 = f113_rtype(((int64_t)((x_497).a_)), f110_ns_of(g_496));
{ int32_t *_t1716 = &((*({ hrv *_t1717 = &(g450); int64_t _i1717 = d_495; (int32_t*)_t1717->b + hr_ix(_i1717, _t1717->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:387"); }))); *_t1716 = ((int32_t)(t_500)); }
if ((((x_497).b_) >= (((int32_t)0LL)))) { int64_t iv_670 = f90_kid(((int64_t)((x_497).b_)), ((int64_t)0LL)); 
(void)(f137_ck(iv_670, t_500));
(void)(f140_conv(iv_670, t_500));
 }
 } else { if ((((*({ hrv *_t1721 = &(g451); int64_t _i1721 = d_495; (uint8_t*)_t1721->b + hr_ix(_i1721, _t1721->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:389"); }))) == (((uint8_t)1LL)))) { (void)(f108_cerr(g_496, hr_str("global initializer depends on itself", 36)));
g401 = saved_498;
g402 = sc_499;
return g575;
 }
{ uint8_t *_t1723 = &((*({ hrv *_t1724 = &(g451); int64_t _i1724 = d_495; (uint8_t*)_t1724->b + hr_ix(_i1724, _t1724->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:390"); }))); *_t1723 = ((uint8_t)1LL); }
int64_t iv_1481 = f90_kid(((int64_t)((x_497).b_)), ((int64_t)0LL)); 
(void)(f137_ck(iv_1481, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
t_500 = f184_default_t(iv_1481);
if (((((*({ hrv *_t1728 = &(g551); int64_t _i1728 = t_500; (S1*)_t1728->b + hr_ix(_i1728, _t1728->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:394"); }))).k_) == (((uint8_t)18LL)))) { t_500 = g576;
 }
if (((((((*({ hrv *_t1729 = &(g551); int64_t _i1729 = t_500; (S1*)_t1729->b + hr_ix(_i1729, _t1729->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:395"); }))).k_) == (((uint8_t)7LL))) && (((((*({ hrv *_t1730 = &(g704); int64_t _i1730 = iv_1481; (S4*)_t1730->b + hr_ix(_i1730, _t1730->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:395"); }))).k_) == (((uint8_t)14LL))) || ((((*({ hrv *_t1731 = &(g704); int64_t _i1731 = iv_1481; (S4*)_t1731->b + hr_ix(_i1731, _t1731->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:395"); }))).k_) == (((uint8_t)17LL))))) && ((((uint16_t)((uint64_t)(x_497).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))))) { t_500 = f136_t_enum(((int64_t)(((*({ hrv *_t1733 = &(g551); int64_t _i1733 = t_500; (S1*)_t1733->b + hr_ix(_i1733, _t1733->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:395"); }))).a_)), false);
(void)(f142_set_cv(iv_1481, t_500));
 }
{ int32_t *_t1735 = &((*({ hrv *_t1736 = &(g450); int64_t _i1736 = d_495; (int32_t*)_t1736->b + hr_ix(_i1736, _t1736->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:396"); }))); *_t1735 = ((int32_t)(t_500)); }
 }
if ((!(f257_ORD_HAS(d_495)))) { (void)(({ hrv *_v1738 = &(g409); int32_t _x1738 = ((int32_t)(d_495)); int32_t *_p1738 = (int32_t*)hr_grow(_v1738, 1, sizeof _x1738); *_p1738 = _x1738; _p1738; }));
 }
g401 = saved_498;
g402 = sc_499;
return t_500;
}
static int64_t f110_ns_of(int64_t n_501) {
return f112_file_ns(f111_node_file(n_501));
}
static int64_t f111_node_file(int64_t n_502) {
return ((int64_t)(((*({ hrv *_t1741 = &(g914); int64_t _i1741 = ((*({ hrv *_t1742 = &(g704); int64_t _i1742 = n_502; (S4*)_t1742->b + hr_ix(_i1742, _t1742->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:23"); }))).t_; (S3*)_t1741->b + hr_ix(_i1741, _t1741->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:23"); }))).f_));
}
static int64_t f112_file_ns(int64_t f_503) {
return ({ int64_t _r1743; if (((f_503) < ((g496).n))) { _r1743 = ((int64_t)((*({ hrv *_t1744 = &(g496); int64_t _i1744 = f_503; (int32_t*)_t1744->b + hr_ix(_i1744, _t1744->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:24"); }))));  } else { _r1743 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1743; });
}
static int64_t f113_rtype(int64_t n_504, int64_t ns_505) {
if (((n_504) < (((int64_t)0LL)))) { return g558;
 }
S4 x_506 = (*({ hrv *_t1745 = &(g704); int64_t _i1745 = n_504; (S4*)_t1745->b + hr_ix(_i1745, _t1745->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:93"); })); 
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
if ((((((*({ hrv *_t1757 = &(g551); int64_t _i1757 = e_512; (S1*)_t1757->b + hr_ix(_i1757, _t1757->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t1758 = &(g551); int64_t _i1758 = e_512; (S1*)_t1758->b + hr_ix(_i1758, _t1758->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).c_) < (((int32_t)0LL))))) { if (((((int64_t)((int64_t)fl_513 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { return f119_t_ref(((int64_t)(((*({ hrv *_t1760 = &(g551); int64_t _i1760 = e_512; (S1*)_t1760->b + hr_ix(_i1760, _t1760->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).a_)), ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1761 = &(g551); int64_t _i1761 = e_512; (S1*)_t1761->b + hr_ix(_i1761, _t1761->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).fl_)) | (int64_t)((int64_t)2LL))));
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
if (((((*({ hrv *_t1780 = &(g551); int64_t _i1780 = b_593; (S1*)_t1780->b + hr_ix(_i1780, _t1780->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:120"); }))).k_) != (((uint8_t)6LL)))) { (void)(f102_derr(((int64_t)((x_506).t_)), hr_str("variant type of a non-enum", 26)));
return g575;
 }
int64_t ei_594 = ((int64_t)(((*({ hrv *_t1782 = &(g551); int64_t _i1782 = b_593; (S1*)_t1782->b + hr_ix(_i1782, _t1782->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:121"); }))).a_)); 
{ int32_t _e1784 = ((*({ hrv *_t1785 = &(g556); int64_t _i1785 = ei_594; (S8*)_t1785->b + hr_ix(_i1785, _t1785->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:122"); }))).vnum_; for (int32_t _k1784 = 0; _k1784 < _e1784; _k1784++) { int32_t i_595 = (int32_t)_k1784; if (((((*({ hrv *_t1786 = &(g557); int64_t _i1786 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1787 = &(g556); int64_t _i1787 = ei_594; (S8*)_t1787->b + hr_ix(_i1787, _t1787->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:122"); }))).v0_)) + (int64_t)((int64_t)(i_595)))); (S9*)_t1786->b + hr_ix(_i1786, _t1786->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:122"); }))).name_) == ((x_506).s_))) { return f125_t_variant(ei_594, ((int64_t)(i_595)));
 }
 } } _bk1783:; 
hrv m_598 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1792 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1790 = &(m_598); hr_fs(_o1790, hr_str("no variant ", 11)); hr_fs(_o1790, f10_nm(((int64_t)((x_506).s_)))); hr_fs(_o1790, hr_str(" in ", 4)); hr_fs(_o1790, hr_sl(*hr_tmp(&_t1792, f126_ty_name(b_593)))); }));
}
(void)(f102_derr(((int64_t)((x_506).t_)), hr_sl(m_598)));
return g575;
 }
if (((k_507) == (((int64_t)45LL)))) { return g578;
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
if (((d_621) >= (((int64_t)0LL)))) { return f134_t_struct(f131_inst_struct(((int64_t)(((*({ hrv *_t1805 = &(g489); int64_t _i1805 = d_621; (S5*)_t1805->b + hr_ix(_i1805, _t1805->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:133"); }))).node_)), ({ hsl _t1806 = ({ L66 *_t1807 = &(args_618); (hsl){ (uint8_t*)_t1807->e, _t1807->n }; }); int64_t _l1806 = 0, _h1806 = _t1806.n; if (_l1806 < 0 || _h1806 < _l1806 || _h1806 > _t1806.n) hr_slerr(_l1806, _h1806, _t1806.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:133"); (hsl){ _t1806.p + _l1806 * (int64_t)sizeof(int32_t), _h1806 - _l1806 }; })));
 }
d_621 = f116_lookup_q(name_614, ns_505, ((int64_t)2LL));
if (((d_621) >= (((int64_t)0LL)))) { return f136_t_enum(f135_inst_enum(((int64_t)(((*({ hrv *_t1811 = &(g489); int64_t _i1811 = d_621; (S5*)_t1811->b + hr_ix(_i1811, _t1811->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:135"); }))).node_)), ({ hsl _t1812 = ({ L66 *_t1813 = &(args_618); (hsl){ (uint8_t*)_t1813->e, _t1813->n }; }); int64_t _l1812 = 0, _h1812 = _t1812.n; if (_l1812 < 0 || _h1812 < _l1812 || _h1812 > _t1812.n) hr_slerr(_l1812, _h1812, _t1812.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:135"); (hsl){ _t1812.p + _l1812 * (int64_t)sizeof(int32_t), _h1812 - _l1812 }; })), ((((uint16_t)((uint64_t)(x_506).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))));
 }
d_621 = f116_lookup_q(name_614, ns_505, ((int64_t)3LL));
if (((d_621) >= (((int64_t)0LL)))) { int64_t an_668 = ((int64_t)(((*({ hrv *_t1815 = &(g489); int64_t _i1815 = d_621; (S5*)_t1815->b + hr_ix(_i1815, _t1815->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:137"); }))).node_)); 
return f113_rtype(((int64_t)(((*({ hrv *_t1817 = &(g704); int64_t _i1817 = an_668; (S4*)_t1817->b + hr_ix(_i1817, _t1817->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:137"); }))).b_)), f110_ns_of(an_668));
 }
hrv m_669 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1820 = &(m_669); hr_fs(_o1820, hr_str("unknown type ", 13)); hr_fs(_o1820, f10_nm(name_614)); }));
(void)(f102_derr(((int64_t)((x_506).t_)), hr_sl(m_669)));
return g575;
 }
(void)(f102_derr(((int64_t)((x_506).t_)), hr_str("bad type", 8)));
return g575;
}
static int64_t f114_prim_type(int64_t k_508) {
if (((k_508) == (((int64_t)89LL)))) { return g559;
 }
if (((k_508) == (((int64_t)90LL)))) { return g574;
 }
if (((k_508) == (((int64_t)99LL)))) { return g568;
 }
if ((((k_508) == (((int64_t)100LL))) || ((k_508) == (((int64_t)104LL))))) { return g569;
 }
int64_t s_510 = f115_int_storage_of_tok(k_508); 
return ({ int64_t _r1825; if (((s_510) >= (((int64_t)0LL)))) { _r1825 = f17_t_int(s_510);  } else { _r1825 = g575;  } _r1825; });
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
while (((d_523) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1832 = &(g489); int64_t _i1832 = d_523; (S5*)_t1832->b + hr_ix(_i1832, _t1832->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:87"); }))).k_))) == (k_517))) { return d_523;
 }
d_523 = ((int64_t)(((*({ hrv *_t1833 = &(g489); int64_t _i1833 = d_523; (S5*)_t1833->b + hr_ix(_i1833, _t1833->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:87"); }))).next_));
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
S4 x_537 = (*({ hrv *_t1850 = &(g704); int64_t _i1850 = n_535; (S4*)_t1850->b + hr_ix(_i1850, _t1850->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:205"); })); 
int64_t k_538 = ((int64_t)((x_537).k_)); 
if (((k_538) == (((int64_t)1LL)))) { return (M57){ ((*({ hrv *_t1851 = &(g914); int64_t _i1851 = (x_537).t_; (S3*)_t1851->b + hr_ix(_i1851, _t1851->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:207"); }))).v_, ({ int64_t _r1852; if (((*({ hrv *_t1853 = &(g914); int64_t _i1853 = (x_537).t_; (S3*)_t1853->b + hr_ix(_i1853, _t1853->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:207"); }))).uns_) { _r1852 = ((int64_t)7LL);  } else { _r1852 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1852; }), true };
 }
if (((k_538) == (((int64_t)10LL)))) { M57 _t1854 = f121_ceval3(((int64_t)((x_537).a_)), ns_536); int64_t v_539 = _t1854.r0; int64_t c_540 = _t1854.r1; bool ok_541 = _t1854.r2; 
if (((((int64_t)((x_537).op_))) == (((int64_t)22LL)))) { int64_t c2_542 = ({ int64_t _r1856; if ((((c_540) == (((int64_t)7LL))) && ((((*({ hrv *_t1857 = &(g704); int64_t _i1857 = (x_537).a_; (S4*)_t1857->b + hr_ix(_i1857, _t1857->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:210"); }))).k_) == (((uint8_t)1LL))))) { _r1856 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1856 = c_540;  } _r1856; }); 
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
if (((((*({ hrv *_t1886 = &(g704); int64_t _i1886 = tn0_564; (S4*)_t1886->b + hr_ix(_i1886, _t1886->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:231"); }))).k_) == (((uint8_t)40LL)))) { int64_t tc_565 = f115_int_storage_of_tok(((int64_t)(((*({ hrv *_t1888 = &(g704); int64_t _i1888 = tn0_564; (S4*)_t1888->b + hr_ix(_i1888, _t1888->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:231"); }))).op_))); 
if (((tc_565) >= (((int64_t)0LL)))) { return (M57){ f122_cwrap(v_561, tc_565), tc_565, ok_563 };
 }
 }
return (M57){ v_561, c_562, ok_563 };
 }
if (((k_538) == (((int64_t)8LL)))) { int64_t d_566 = f116_lookup_q(((int64_t)((x_537).s_)), ns_536, ((int64_t)5LL)); 
if (((d_566) < (((int64_t)0LL)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
int64_t g_567 = ((int64_t)(((*({ hrv *_t1891 = &(g489); int64_t _i1891 = d_566; (S5*)_t1891->b + hr_ix(_i1891, _t1891->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:235"); }))).node_)); 
if ((((((uint16_t)((uint64_t)((*({ hrv *_t1892 = &(g704); int64_t _i1892 = g_567; (S4*)_t1892->b + hr_ix(_i1892, _t1892->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:236"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || ((((*({ hrv *_t1893 = &(g704); int64_t _i1893 = g_567; (S4*)_t1893->b + hr_ix(_i1893, _t1893->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:236"); }))).b_) < (((int32_t)0LL))))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
M57 _t1894 = f121_ceval3(f90_kid(((int64_t)(((*({ hrv *_t1897 = &(g704); int64_t _i1897 = g_567; (S4*)_t1897->b + hr_ix(_i1897, _t1897->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:237"); }))).b_)), ((int64_t)0LL)), f110_ns_of(g_567)); int64_t v_568 = _t1894.r0; int64_t c_569 = _t1894.r1; bool ok_570 = _t1894.r2; 
int64_t tn0_571 = ((int64_t)(((*({ hrv *_t1899 = &(g704); int64_t _i1899 = g_567; (S4*)_t1899->b + hr_ix(_i1899, _t1899->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:238"); }))).a_)); 
if ((((tn0_571) >= (((int64_t)0LL))) && ((((*({ hrv *_t1900 = &(g704); int64_t _i1900 = tn0_571; (S4*)_t1900->b + hr_ix(_i1900, _t1900->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:239"); }))).k_) == (((uint8_t)40LL))))) { int64_t tc_572 = f115_int_storage_of_tok(((int64_t)(((*({ hrv *_t1902 = &(g704); int64_t _i1902 = tn0_571; (S4*)_t1902->b + hr_ix(_i1902, _t1902->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:239"); }))).op_))); 
if (((tc_572) >= (((int64_t)0LL)))) { return (M57){ f122_cwrap(v_568, tc_572), tc_572, ok_570 };
 }
 }
return (M57){ v_568, c_569, ok_570 };
 }
if (((((k_538) == (((int64_t)14LL))) && hr_streq(f10_nm(((int64_t)((x_537).s_))), hr_str("len", 3))) && ((((*({ hrv *_t1905 = &(g704); int64_t _i1905 = (x_537).a_; (S4*)_t1905->b + hr_ix(_i1905, _t1905->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:242"); }))).k_) == (((uint8_t)8LL))))) { int64_t d_573 = f116_lookup_q(((int64_t)(((*({ hrv *_t1907 = &(g704); int64_t _i1907 = (x_537).a_; (S4*)_t1907->b + hr_ix(_i1907, _t1907->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:243"); }))).s_)), ns_536, ((int64_t)5LL)); 
if (((d_573) < (((int64_t)0LL)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
int64_t g_574 = ((int64_t)(((*({ hrv *_t1908 = &(g489); int64_t _i1908 = d_573; (S5*)_t1908->b + hr_ix(_i1908, _t1908->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:245"); }))).node_)); 
if (((((*({ hrv *_t1909 = &(g704); int64_t _i1909 = g_574; (S4*)_t1909->b + hr_ix(_i1909, _t1909->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).a_) >= (((int32_t)0LL)))) { int64_t t_575 = f113_rtype(((int64_t)(((*({ hrv *_t1911 = &(g704); int64_t _i1911 = g_574; (S4*)_t1911->b + hr_ix(_i1911, _t1911->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).a_)), f110_ns_of(g_574)); 
if ((((((*({ hrv *_t1913 = &(g551); int64_t _i1913 = t_575; (S1*)_t1913->b + hr_ix(_i1913, _t1913->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).k_) == (((uint8_t)8LL))) && ((((*({ hrv *_t1914 = &(g551); int64_t _i1914 = t_575; (S1*)_t1914->b + hr_ix(_i1914, _t1914->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).s_) == (((uint8_t)(((uint8_t)1LL))))))) { return (M57){ ((*({ hrv *_t1915 = &(g551); int64_t _i1915 = t_575; (S1*)_t1915->b + hr_ix(_i1915, _t1915->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).b_, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
 }
 }
if (((((*({ hrv *_t1916 = &(g704); int64_t _i1916 = g_574; (S4*)_t1916->b + hr_ix(_i1916, _t1916->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_) >= (((int32_t)0LL)))) { int64_t iv_576 = f90_kid(((int64_t)(((*({ hrv *_t1918 = &(g704); int64_t _i1918 = g_574; (S4*)_t1918->b + hr_ix(_i1918, _t1918->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_)), ((int64_t)0LL)); 
if (((((*({ hrv *_t1919 = &(g704); int64_t _i1919 = iv_576; (S4*)_t1919->b + hr_ix(_i1919, _t1919->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).k_) == (((uint8_t)16LL)))) { if (((((*({ hrv *_t1920 = &(g704); int64_t _i1920 = iv_576; (S4*)_t1920->b + hr_ix(_i1920, _t1920->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_) >= (((int32_t)0LL)))) { M57 _t1921 = f121_ceval3(((int64_t)(((*({ hrv *_t1923 = &(g704); int64_t _i1923 = iv_576; (S4*)_t1923->b + hr_ix(_i1923, _t1923->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_)), f110_ns_of(g_574)); int64_t v_577 = _t1921.r0; int64_t c_578 = _t1921.r1; bool ok_579 = _t1921.r2; 
return (M57){ v_577, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ok_579 };
 }
return (M57){ ((int64_t)(((*({ hrv *_t1925 = &(g704); int64_t _i1925 = iv_576; (S4*)_t1925->b + hr_ix(_i1925, _t1925->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).n_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
 }
if (((((*({ hrv *_t1926 = &(g704); int64_t _i1926 = iv_576; (S4*)_t1926->b + hr_ix(_i1926, _t1926->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).k_) == (((uint8_t)3LL)))) { return (M57){ ((int64_t)(((*({ hrv *_t1927 = &(g914); int64_t _i1927 = ((*({ hrv *_t1928 = &(g704); int64_t _i1928 = iv_576; (S4*)_t1928->b + hr_ix(_i1928, _t1928->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).t_; (S3*)_t1927->b + hr_ix(_i1927, _t1927->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).w_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
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
S1 x_603 = (*({ hrv *_t1937 = &(g551); int64_t _i1937 = t_601; (S1*)_t1937->b + hr_ix(_i1937, _t1937->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:199"); })); 
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
if (((k_604) == (((int64_t)5LL)))) { (void)(({ hrv *_v1951 = out_602; hsl _s1951 = f10_nm(((int64_t)(((*({ hrv *_t1953 = &(g554); int64_t _i1953 = (x_603).a_; (S10*)_t1953->b + hr_ix(_i1953, _t1953->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:212"); }))).name_))); hr_append(_v1951, _s1951.p, _s1951.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1955 = &(g554); int64_t _i1955 = (x_603).a_; (S10*)_t1955->b + hr_ix(_i1955, _t1955->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:212"); }))).ta_)), ((int64_t)(((*({ hrv *_t1956 = &(g554); int64_t _i1956 = (x_603).a_; (S10*)_t1956->b + hr_ix(_i1956, _t1956->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:212"); }))).tn_)), out_602));
return;
 }
if (((k_604) == (((int64_t)6LL)))) { (void)(({ hrv *_v1957 = out_602; hsl _s1957 = f10_nm(((int64_t)(((*({ hrv *_t1959 = &(g556); int64_t _i1959 = (x_603).a_; (S8*)_t1959->b + hr_ix(_i1959, _t1959->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:213"); }))).name_))); hr_append(_v1957, _s1957.p, _s1957.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1961 = &(g556); int64_t _i1961 = (x_603).a_; (S8*)_t1961->b + hr_ix(_i1961, _t1961->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:213"); }))).ta_)), ((int64_t)(((*({ hrv *_t1962 = &(g556); int64_t _i1962 = (x_603).a_; (S8*)_t1962->b + hr_ix(_i1962, _t1962->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:213"); }))).tn_)), out_602));
if (((((uint16_t)((uint64_t)(x_603).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v1963 = out_602; hsl _s1963 = hr_str("..", 2); hr_append(_v1963, _s1963.p, _s1963.n, sizeof(uint8_t)); }));
 }
return;
 }
if (((k_604) == (((int64_t)7LL)))) { (void)(({ hrv *_v1964 = out_602; hsl _s1964 = f10_nm(((int64_t)(((*({ hrv *_t1966 = &(g556); int64_t _i1966 = (x_603).a_; (S8*)_t1966->b + hr_ix(_i1966, _t1966->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).name_))); hr_append(_v1964, _s1964.p, _s1964.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1968 = &(g556); int64_t _i1968 = (x_603).a_; (S8*)_t1968->b + hr_ix(_i1968, _t1968->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).ta_)), ((int64_t)(((*({ hrv *_t1969 = &(g556); int64_t _i1969 = (x_603).a_; (S8*)_t1969->b + hr_ix(_i1969, _t1969->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).tn_)), out_602));
(void)(({ hrv *_v1970 = out_602; uint8_t _x1970 = ((uint8_t)46LL); uint8_t *_p1970 = (uint8_t*)hr_grow(_v1970, 1, sizeof _x1970); *_p1970 = _x1970; _p1970; }));
(void)(({ hrv *_v1971 = out_602; hsl _s1971 = f10_nm(((int64_t)(((*({ hrv *_t1973 = &(g557); int64_t _i1973 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1974 = &(g556); int64_t _i1974 = (x_603).a_; (S8*)_t1974->b + hr_ix(_i1974, _t1974->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).v0_)) + (int64_t)((int64_t)((x_603).c_)))); (S9*)_t1973->b + hr_ix(_i1973, _t1973->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).name_))); hr_append(_v1971, _s1971.p, _s1971.n, sizeof(uint8_t)); }));
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
(void)(f127_ty_name_into(((int64_t)((*({ hrv *_t2002 = &(g552); int64_t _i2002 = ((int64_t)((int64_t)((int64_t)((x_603).l_)) + (int64_t)((int64_t)(i_613)))); (int32_t*)_t2002->b + hr_ix(_i2002, _t2002->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:232"); })))), out_602));
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
(void)(f127_ty_name_into(((int64_t)((*({ hrv *_t2012 = &(g552); int64_t _i2012 = ((int64_t)((int64_t)l_608 + (int64_t)i_611)); (int32_t*)_t2012->b + hr_ix(_i2012, _t2012->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:235"); })))), out_610));
 } } _bk2008:; 
(void)(({ hrv *_v2013 = out_610; uint8_t _x2013 = ((uint8_t)62LL); uint8_t *_p2013 = (uint8_t*)hr_grow(_v2013, 1, sizeof _x2013); *_p2013 = _x2013; _p2013; }));
}
static int64_t f130_gb_find(int64_t name_615) {
int64_t i_616 = ((int64_t)((int64_t)(g491).n - (int64_t)((int64_t)1LL))); 
while (((i_616) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t2015 = &(g491); int64_t _i2015 = i_616; (S7*)_t2015->b + hr_ix(_i2015, _t2015->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:72"); }))).name_))) == (name_615))) { return ((int64_t)(((*({ hrv *_t2016 = &(g491); int64_t _i2016 = i_616; (S7*)_t2016->b + hr_ix(_i2016, _t2016->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:72"); }))).ty_));
 }
i_616--;
 } _bk2014:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f131_inst_struct(int64_t node_622, hsl args_623) {
{ hrv *_v2018 = &(g554); for (int64_t _k2018 = 0; _k2018 < _v2018->n; _k2018++) { S10 s_624 = ((S10*)_v2018->b)[_k2018]; int64_t i_625 = (int64_t)_k2018; if ((((((int64_t)((s_624).node_))) == (node_622)) && ((((int64_t)((s_624).tn_))) == ((args_623).n)))) { bool same_626 = true; 
{ int64_t _e2020 = (args_623).n; for (int64_t _k2020 = 0; _k2020 < _e2020; _k2020++) { int64_t j_627 = (int64_t)_k2020; if ((((*({ hrv *_t2021 = &(g552); int64_t _i2021 = ((int64_t)((int64_t)((int64_t)((s_624).ta_)) + (int64_t)j_627)); (int32_t*)_t2021->b + hr_ix(_i2021, _t2021->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:146"); }))) != ((*({ hsl _t2022 = args_623; int64_t _i2022 = j_627; (int32_t*)_t2022.p + hr_ix(_i2022, _t2022.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:146"); }))))) { same_626 = false;
 }
 } } _bk2019:; 
if (same_626) { return i_625;
 }
 }
 } } _bk2017:; 
int64_t ta_628 = (g552).n; 
(void)(({ hrv *_v2023 = &(g552); hsl _s2023 = args_623; hr_append(_v2023, _s2023.p, _s2023.n, sizeof(int32_t)); }));
int64_t si_629 = (g554).n; 
(void)(({ hrv *_v2024 = &(g554); S10 _x2024 = ((S10){ .node_ = ((int32_t)(node_622)), .ta_ = ((int32_t)(ta_628)), .tn_ = ((int32_t)((args_623).n)), .f0_ = ((int32_t)((g555).n)), .fnum_ = ((int32_t)0LL), .name_ = ((*({ hrv *_t2025 = &(g704); int64_t _i2025 = node_622; (S4*)_t2025->b + hr_ix(_i2025, _t2025->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:149"); }))).s_, }); S10 *_p2024 = (S10*)hr_grow(_v2024, 1, sizeof _x2024); *_p2024 = _x2024; _p2024; }));
L66 gn_630 = ({ L66 _t2026; memset(&_t2026, 0, sizeof _t2026); _t2026.n = 0; _t2026; }); 
(void)(f132_gen_names(((int64_t)(((*({ hrv *_t2028 = &(g704); int64_t _i2028 = node_622; (S4*)_t2028->b + hr_ix(_i2028, _t2028->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:150"); }))).d_)), (&(gn_630))));
if (((((int64_t)(gn_630).n)) != ((args_623).n))) { (void)(f102_derr(((int64_t)(((*({ hrv *_t2030 = &(g704); int64_t _i2030 = node_622; (S4*)_t2030->b + hr_ix(_i2030, _t2030->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:151"); }))).t_)), hr_str("wrong number of type arguments", 30)));
 }
int64_t g0_634 = (g491).n; 
{ int64_t _e2032 = f45_min(((int64_t)(gn_630).n), (args_623).n); for (int64_t _k2032 = 0; _k2032 < _e2032; _k2032++) { int64_t i_635 = (int64_t)_k2032; (void)(({ hrv *_v2034 = &(g491); S7 _x2034 = ((S7){ .name_ = (*({ L66 *_t2035 = &(gn_630); int64_t _i2035 = i_635; _t2035->e + hr_ix(_i2035, _t2035->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:153"); })), .ty_ = (*({ hsl _t2036 = args_623; int64_t _i2036 = i_635; (int32_t*)_t2036.p + hr_ix(_i2036, _t2036.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:153"); })), }); S7 *_p2034 = (S7*)hr_grow(_v2034, 1, sizeof _x2034); *_p2034 = _x2034; _p2034; }));
 } } _bk2031:; 
int64_t f0_644 = f133_fields_into(node_622, f110_ns_of(node_622)); 
{ int32_t *_t2039 = &(((*({ hrv *_t2040 = &(g554); int64_t _i2040 = si_629; (S10*)_t2040->b + hr_ix(_i2040, _t2040->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:155"); }))).f0_); *_t2039 = ((int32_t)(f0_644)); }
{ int32_t *_t2041 = &(((*({ hrv *_t2042 = &(g554); int64_t _i2042 = si_629; (S10*)_t2042->b + hr_ix(_i2042, _t2042->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:155"); }))).fnum_); *_t2041 = ((int32_t)(((int64_t)((int64_t)(g555).n - (int64_t)f0_644)))); }
(void)(({ hrv *_v2043 = &(g491); int64_t _k2043 = ((int64_t)((int64_t)(g491).n - (int64_t)g0_634)); if (_k2043 < 0 || _k2043 > _v2043->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:156"); _v2043->n -= _k2043; }));
return si_629;
}
static void f132_gen_names(int64_t gl_631, L66* out_632) {
if (((gl_631) >= (((int64_t)0LL)))) { { int32_t _e2045 = ((*({ hrv *_t2046 = &(g704); int64_t _i2046 = gl_631; (S4*)_t2046->b + hr_ix(_i2046, _t2046->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:144"); }))).n_; for (int32_t _k2045 = 0; _k2045 < _e2045; _k2045++) { int32_t i_633 = (int32_t)_k2045; (void)(({ L66 *_v2047 = out_632; int32_t _x2047 = ((*({ hrv *_t2048 = &(g704); int64_t _i2048 = f90_kid(gl_631, ((int64_t)(i_633))); (S4*)_t2048->b + hr_ix(_i2048, _t2048->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:144"); }))).s_; if (_v2047->n >= 16) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:144"); _v2047->e[_v2047->n] = _x2047; &_v2047->e[_v2047->n++]; }));
 } } _bk2044:; 
 }
}
static int64_t f133_fields_into(int64_t node_636, int64_t ns_637) {
L73 buf_638 = ({ L73 _t2050; memset(&_t2050, 0, sizeof _t2050); _t2050.n = 0; _t2050; }); 
{ int32_t _e2052 = ((*({ hrv *_t2053 = &(g704); int64_t _i2053 = node_636; (S4*)_t2053->b + hr_ix(_i2053, _t2053->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:161"); }))).n_; for (int32_t _k2052 = 0; _k2052 < _e2052; _k2052++) { int32_t i_639 = (int32_t)_k2052; int64_t f_640 = f90_kid(node_636, ((int64_t)(i_639))); 
S4 x_641 = (*({ hrv *_t2055 = &(g704); int64_t _i2055 = f_640; (S4*)_t2055->b + hr_ix(_i2055, _t2055->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:163"); })); 
if (((((uint16_t)((uint64_t)(x_641).fl_ & (uint64_t)((uint16_t)4LL)))) != (((uint16_t)0LL)))) { (void)(({ L73 *_v2056 = &(buf_638); S11 _x2056 = ((S11){ .name_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .def_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .fl_ = (x_641).fl_, .padn_ = (x_641).c_, .off_ = ((int64_t)0LL), }); if (_v2056->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:164"); _v2056->e[_v2056->n] = _x2056; &_v2056->e[_v2056->n++]; }));
continue;
 }
int64_t ft_642 = f113_rtype(((int64_t)((x_641).a_)), ns_637); 
(void)(({ L73 *_v2058 = &(buf_638); S11 _x2058 = ((S11){ .name_ = (x_641).s_, .ty_ = ((int32_t)(ft_642)), .def_ = (x_641).b_, .fl_ = (x_641).fl_, .padn_ = ((int32_t)0LL), .off_ = ((int64_t)0LL), }); if (_v2058->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:166"); _v2058->e[_v2058->n] = _x2058; &_v2058->e[_v2058->n++]; }));
 } } _bk2051:; 
int64_t f0_643 = (g555).n; 
(void)(({ hrv *_v2059 = &(g555); hsl _s2059 = ({ hsl _t2060 = ({ L73 *_t2061 = &(buf_638); (hsl){ (uint8_t*)_t2061->e, _t2061->n }; }); int64_t _l2060 = 0, _h2060 = _t2060.n; if (_l2060 < 0 || _h2060 < _l2060 || _h2060 > _t2060.n) hr_slerr(_l2060, _h2060, _t2060.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:169"); (hsl){ _t2060.p + _l2060 * (int64_t)sizeof(S11), _h2060 - _l2060 }; }); hr_append(_v2059, _s2059.p, _s2059.n, sizeof(S11)); }));
return f0_643;
}
static int64_t f134_t_struct(int64_t si_645) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)5LL))), .a_ = ((int32_t)(si_645)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f135_inst_enum(int64_t node_646, hsl args_647) {
{ hrv *_v2064 = &(g556); for (int64_t _k2064 = 0; _k2064 < _v2064->n; _k2064++) { S8 s_648 = ((S8*)_v2064->b)[_k2064]; int64_t i_649 = (int64_t)_k2064; if ((((((int64_t)((s_648).node_))) == (node_646)) && ((((int64_t)((s_648).tn_))) == ((args_647).n)))) { bool same_650 = true; 
{ int64_t _e2066 = (args_647).n; for (int64_t _k2066 = 0; _k2066 < _e2066; _k2066++) { int64_t j_651 = (int64_t)_k2066; if ((((*({ hrv *_t2067 = &(g552); int64_t _i2067 = ((int64_t)((int64_t)((int64_t)((s_648).ta_)) + (int64_t)j_651)); (int32_t*)_t2067->b + hr_ix(_i2067, _t2067->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:173"); }))) != ((*({ hsl _t2068 = args_647; int64_t _i2068 = j_651; (int32_t*)_t2068.p + hr_ix(_i2068, _t2068.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:173"); }))))) { same_650 = false;
 }
 } } _bk2065:; 
if (same_650) { return i_649;
 }
 }
 } } _bk2063:; 
int64_t ta_652 = (g552).n; 
(void)(({ hrv *_v2069 = &(g552); hsl _s2069 = args_647; hr_append(_v2069, _s2069.p, _s2069.n, sizeof(int32_t)); }));
int64_t ei_653 = (g556).n; 
int64_t nv_654 = ((int64_t)(((*({ hrv *_t2070 = &(g704); int64_t _i2070 = node_646; (S4*)_t2070->b + hr_ix(_i2070, _t2070->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:176"); }))).n_)); 
(void)(({ hrv *_v2071 = &(g556); S8 _x2071 = ((S8){ .node_ = ((int32_t)(node_646)), .ta_ = ((int32_t)(ta_652)), .tn_ = ((int32_t)((args_647).n)), .v0_ = ((int32_t)((g557).n)), .vnum_ = ((int32_t)(nv_654)), .name_ = ((*({ hrv *_t2072 = &(g704); int64_t _i2072 = node_646; (S4*)_t2072->b + hr_ix(_i2072, _t2072->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:177"); }))).s_, }); S8 *_p2071 = (S8*)hr_grow(_v2071, 1, sizeof _x2071); *_p2071 = _x2071; _p2071; }));
int64_t v0_655 = (g557).n; 
{ int64_t _e2074 = nv_654; for (int64_t _k2074 = 0; _k2074 < _e2074; _k2074++) { int64_t i_656 = (int64_t)_k2074; int64_t v_657 = f90_kid(node_646, i_656); 
(void)(({ hrv *_v2076 = &(g557); S9 _x2076 = ((S9){ .name_ = ((*({ hrv *_t2077 = &(g704); int64_t _i2077 = v_657; (S4*)_t2077->b + hr_ix(_i2077, _t2077->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:179"); }))).s_, .f0_ = ((int32_t)0LL), .fnum_ = ((int32_t)0LL), .si_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .size_ = ((int64_t)0LL), .haspay_ = ((((uint16_t)((uint64_t)((*({ hrv *_t2078 = &(g704); int64_t _i2078 = v_657; (S4*)_t2078->b + hr_ix(_i2078, _t2078->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:179"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))), }); S9 *_p2076 = (S9*)hr_grow(_v2076, 1, sizeof _x2076); *_p2076 = _x2076; _p2076; }));
 } } _bk2073:; 
L66 gn_658 = ({ L66 _t2079; memset(&_t2079, 0, sizeof _t2079); _t2079.n = 0; _t2079; }); 
(void)(f132_gen_names(((int64_t)(((*({ hrv *_t2081 = &(g704); int64_t _i2081 = node_646; (S4*)_t2081->b + hr_ix(_i2081, _t2081->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:180"); }))).d_)), (&(gn_658))));
int64_t g0_659 = (g491).n; 
{ int64_t _e2083 = f45_min(((int64_t)(gn_658).n), (args_647).n); for (int64_t _k2083 = 0; _k2083 < _e2083; _k2083++) { int64_t i_660 = (int64_t)_k2083; (void)(({ hrv *_v2085 = &(g491); S7 _x2085 = ((S7){ .name_ = (*({ L66 *_t2086 = &(gn_658); int64_t _i2086 = i_660; _t2086->e + hr_ix(_i2086, _t2086->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:182"); })), .ty_ = (*({ hsl _t2087 = args_647; int64_t _i2087 = i_660; (int32_t*)_t2087.p + hr_ix(_i2087, _t2087.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:182"); })), }); S7 *_p2085 = (S7*)hr_grow(_v2085, 1, sizeof _x2085); *_p2085 = _x2085; _p2085; }));
 } } _bk2082:; 
int64_t ns_661 = f110_ns_of(node_646); 
{ int64_t _e2090 = nv_654; for (int64_t _k2090 = 0; _k2090 < _e2090; _k2090++) { int64_t i_662 = (int64_t)_k2090; int64_t v_663 = f90_kid(node_646, i_662); 
int64_t si_664 = (g554).n; 
(void)(({ hrv *_v2092 = &(g554); S10 _x2092 = ((S10){ .node_ = ((int32_t)(v_663)), .ta_ = ((int32_t)(ta_652)), .tn_ = ((int32_t)((args_647).n)), .f0_ = ((int32_t)((g555).n)), .fnum_ = ((int32_t)0LL), .name_ = ((*({ hrv *_t2093 = &(g704); int64_t _i2093 = v_663; (S4*)_t2093->b + hr_ix(_i2093, _t2093->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:187"); }))).s_, }); S10 *_p2092 = (S10*)hr_grow(_v2092, 1, sizeof _x2092); *_p2092 = _x2092; _p2092; }));
int64_t f0_665 = f133_fields_into(v_663, ns_661); 
{ int32_t *_t2095 = &(((*({ hrv *_t2096 = &(g554); int64_t _i2096 = si_664; (S10*)_t2096->b + hr_ix(_i2096, _t2096->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:189"); }))).f0_); *_t2095 = ((int32_t)(f0_665)); }
{ int32_t *_t2097 = &(((*({ hrv *_t2098 = &(g554); int64_t _i2098 = si_664; (S10*)_t2098->b + hr_ix(_i2098, _t2098->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:189"); }))).fnum_); *_t2097 = ((int32_t)(((int64_t)((int64_t)(g555).n - (int64_t)f0_665)))); }
{ int32_t *_t2099 = &(((*({ hrv *_t2100 = &(g557); int64_t _i2100 = ((int64_t)((int64_t)v0_655 + (int64_t)i_662)); (S9*)_t2100->b + hr_ix(_i2100, _t2100->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:190"); }))).si_); *_t2099 = ((int32_t)(si_664)); }
 } } _bk2089:; 
(void)(({ hrv *_v2101 = &(g491); int64_t _k2101 = ((int64_t)((int64_t)(g491).n - (int64_t)g0_659)); if (_k2101 < 0 || _k2101 > _v2101->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:192"); _v2101->n -= _k2101; }));
return ei_653;
}
static int64_t f136_t_enum(int64_t ei_666, bool vm_667) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)6LL))), .fl_ = ({ uint16_t _r2103; if (vm_667) { _r2103 = ((uint16_t)1LL);  } else { _r2103 = ((uint16_t)0LL);  } _r2103; }), .a_ = ((int32_t)(ei_666)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f137_ck(int64_t n_671, int64_t want_672) {
if (((n_671) < (((int64_t)0LL)))) { return g558;
 }
S4 x_673 = (*({ hrv *_t2104 = &(g704); int64_t _i2104 = n_671; (S4*)_t2104->b + hr_ix(_i2104, _t2104->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:671"); })); 
int64_t k_674 = ((int64_t)((x_673).k_)); 
if (((k_674) == (((int64_t)1LL)))) { if ((((want_672) >= (((int64_t)0LL))) && ((((((*({ hrv *_t2105 = &(g551); int64_t _i2105 = want_672; (S1*)_t2105->b + hr_ix(_i2105, _t2105->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:673"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2106 = &(g551); int64_t _i2106 = want_672; (S1*)_t2106->b + hr_ix(_i2106, _t2106->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:673"); }))).k_) == (((uint8_t)4LL)))) || ((((*({ hrv *_t2107 = &(g551); int64_t _i2107 = want_672; (S1*)_t2107->b + hr_ix(_i2107, _t2107->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:673"); }))).k_) == (((uint8_t)17LL)))))) { (void)(f138_set_t(n_671, g571));
(void)(f140_conv(n_671, want_672));
return want_672;
 }
return f138_set_t(n_671, g571);
 }
if (((k_674) == (((int64_t)2LL)))) { if ((((want_672) >= (((int64_t)0LL))) && ((((*({ hrv *_t2111 = &(g551); int64_t _i2111 = want_672; (S1*)_t2111->b + hr_ix(_i2111, _t2111->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:674"); }))).k_) == (((uint8_t)4LL))))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g572);
 }
if (((k_674) == (((int64_t)3LL)))) { if ((((want_672) >= (((int64_t)0LL))) && f164_is_byte_arr(want_672))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g573);
 }
if ((((k_674) == (((int64_t)4LL))) || ((k_674) == (((int64_t)5LL))))) { return f138_set_t(n_671, g559);
 }
if (((k_674) == (((int64_t)6LL)))) { if ((((want_672) >= (((int64_t)0LL))) && f165_is_opt(want_672))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g570);
 }
if (((k_674) == (((int64_t)7LL)))) { return f138_set_t(n_671, ({ int64_t _r2122; if (((want_672) >= (((int64_t)0LL)))) { _r2122 = want_672;  } else { _r2122 = g575;  } _r2122; }));
 }
if (((k_674) == (((int64_t)8LL)))) { return f166_ck_id(n_671, want_672);
 }
if (((k_674) == (((int64_t)9LL)))) { int64_t t_888 = f176_ck_bin(n_671, want_672); 
if (((((want_672) >= (((int64_t)0LL))) && f163_is_pending(t_888)) && (((((*({ hrv *_t2126 = &(g551); int64_t _i2126 = want_672; (S1*)_t2126->b + hr_ix(_i2126, _t2126->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:680"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2127 = &(g551); int64_t _i2127 = want_672; (S1*)_t2127->b + hr_ix(_i2127, _t2127->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:680"); }))).k_) == (((uint8_t)4LL)))))) { (void)(f140_conv(n_671, want_672));
return want_672;
 }
return t_888;
 }
if (((k_674) == (((int64_t)10LL)))) { int64_t t_915 = f183_ck_un(n_671, want_672); 
if (((((want_672) >= (((int64_t)0LL))) && f163_is_pending(t_915)) && (((((*({ hrv *_t2131 = &(g551); int64_t _i2131 = want_672; (S1*)_t2131->b + hr_ix(_i2131, _t2131->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:681"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2132 = &(g551); int64_t _i2132 = want_672; (S1*)_t2132->b + hr_ix(_i2132, _t2132->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:681"); }))).k_) == (((uint8_t)4LL)))))) { (void)(f140_conv(n_671, want_672));
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
if (((k_674) == (((int64_t)24LL)))) { (void)(({ hrv *_v2140 = &(g468); int32_t _x2140 = ({ int32_t _r2141; if ((((want_672) >= (((int64_t)0LL))) && ((want_672) != (g558)))) { _r2141 = ((int32_t)(want_672));  } else { _r2141 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));  } _r2141; }); int32_t *_p2140 = (int32_t*)hr_grow(_v2140, 1, sizeof _x2140); *_p2140 = _x2140; _p2140; }));
int64_t bt_1105 = f137_ck(((int64_t)((x_673).a_)), want_672); 
int64_t t_1106 = ((int64_t)(({ hrv *_v2143 = &(g468); if (!_v2143->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:688"); ((int32_t*)_v2143->b)[--_v2143->n]; }))); 
if ((((bt_1105) != (g558)) && (!(f163_is_pending(bt_1105))))) { return f138_set_t(n_671, bt_1105);
 }
if (((t_1106) >= (((int64_t)0LL)))) { (void)(f140_conv(((int64_t)((x_673).a_)), t_1106));
return f138_set_t(n_671, t_1106);
 }
return f138_set_t(n_671, bt_1105);
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
if (((k_674) == (((int64_t)30LL)))) { return f138_set_t(n_671, g558);
 }
if (((k_674) == (((int64_t)11LL)))) { return f223_ck_call(n_671, want_672);
 }
if (((k_674) == (((int64_t)17LL)))) { return f256_ck_slit(n_671, want_672);
 }
if (((k_674) == (((int64_t)31LL)))) { return f138_set_t(n_671, g578);
 }
(void)(f108_cerr(n_671, hr_str("unsupported expression", 22)));
return f138_set_t(n_671, g575);
}
static int64_t f138_set_t(int64_t n_675, int64_t t_676) {
{ int32_t *_t2162 = &((*({ hrv *_t2163 = &(g395); int64_t _i2163 = f139_aix(n_675); (int32_t*)_t2163->b + hr_ix(_i2163, _t2163->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:42"); }))); *_t2162 = ((int32_t)(t_676)); }
return t_676;
}
static int64_t f139_aix(int64_t n_677) {
int64_t i_678 = g401; 
while (((i_678) >= (((int64_t)0LL)))) { S6 f_679 = (*({ hrv *_t2166 = &(g388); int64_t _i2166 = i_678; (S6*)_t2166->b + hr_ix(_i2166, _t2166->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:37"); })); 
if ((((n_677) >= (((int64_t)((f_679).lo_)))) && ((n_677) < (((int64_t)((f_679).hi_)))))) { return ((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((f_679).ab_)) + (int64_t)n_677)) - (int64_t)((int64_t)((f_679).lo_))));
 }
i_678 = ((int64_t)((f_679).par_));
 } _bk2165:; 
S6 g_680 = (*({ hrv *_t2167 = &(g388); int64_t _i2167 = g403; (S6*)_t2167->b + hr_ix(_i2167, _t2167->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:38"); })); 
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
int64_t fk_685 = ((int64_t)(((*({ hrv *_t2169 = &(g551); int64_t _i2169 = f_684; (S1*)_t2169->b + hr_ix(_i2169, _t2169->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:149"); }))).k_)); 
int64_t tkd_686 = ((int64_t)(((*({ hrv *_t2170 = &(g551); int64_t _i2170 = t_682; (S1*)_t2170->b + hr_ix(_i2170, _t2170->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:150"); }))).k_)); 
if ((((tkd_686) == (((int64_t)0LL))) || ((fk_685) == (((int64_t)0LL))))) { return true;
 }
if (((((tkd_686) == (((int64_t)2LL))) && ((fk_685) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2171 = &(g551); int64_t _i2171 = f_684; (S1*)_t2171->b + hr_ix(_i2171, _t2171->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:152"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f142_set_cv(n_681, g559));
return true;
 }
if ((((((tkd_686) == (((int64_t)10LL))) && ((((*({ hrv *_t2173 = &(g551); int64_t _i2173 = t_682; (S1*)_t2173->b + hr_ix(_i2173, _t2173->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:153"); }))).c_) < (((int32_t)0LL)))) && ((fk_685) != (((int64_t)11LL)))) && ((fk_685) != (((int64_t)10LL))))) { if (((f143_tclass(t_682)) >= (((int64_t)0LL)))) { bool ok_735 = f140_conv(n_681, ((int64_t)(((*({ hrv *_t2176 = &(g551); int64_t _i2176 = t_682; (S1*)_t2176->b + hr_ix(_i2176, _t2176->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:153"); }))).a_))); 
if ((ok_735 && ((f150_cv(n_681)) < (((int64_t)0LL))))) { (void)(f142_set_cv(n_681, t_682));
 }
return ok_735;
 }
 }
if (((((fk_685) == (((int64_t)10LL))) && ((((*({ hrv *_t2179 = &(g551); int64_t _i2179 = f_684; (S1*)_t2179->b + hr_ix(_i2179, _t2179->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:154"); }))).c_) < (((int32_t)0LL)))) && ((tkd_686) != (((int64_t)10LL))))) { if (f151_conv_ok(((int64_t)(((*({ hrv *_t2181 = &(g551); int64_t _i2181 = f_684; (S1*)_t2181->b + hr_ix(_i2181, _t2181->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:154"); }))).a_)), t_682, n_681)) { (void)(f142_set_cv(n_681, t_682));
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
if ((((fk_685) == (((int64_t)18LL))) && (f164_is_byte_arr(t_682) || (((tkd_686) == (((int64_t)10LL))) && f164_is_byte_arr(((int64_t)(((*({ hrv *_t2196 = &(g551); int64_t _i2196 = t_682; (S1*)_t2196->b + hr_ix(_i2196, _t2196->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:161"); }))).a_))))))) { (void)(f162_commit(n_681, ({ int64_t _r2198; if (((tkd_686) == (((int64_t)10LL)))) { _r2198 = ((int64_t)(((*({ hrv *_t2199 = &(g551); int64_t _i2199 = t_682; (S1*)_t2199->b + hr_ix(_i2199, _t2199->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:161"); }))).a_));  } else { _r2198 = t_682;  } _r2198; })));
return true;
 }
if ((((fk_685) == (((int64_t)19LL))) && (((tkd_686) == (((int64_t)8LL))) || ((tkd_686) == (((int64_t)9LL)))))) { (void)(f162_commit(n_681, t_682));
return true;
 }
if (((((fk_685) == (((int64_t)11LL))) && ((tkd_686) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2201 = &(g551); int64_t _i2201 = t_682; (S1*)_t2201->b + hr_ix(_i2201, _t2201->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:163"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f162_commit(n_681, t_682));
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
return ((int64_t)((*({ hrv *_t2212 = &(g395); int64_t _i2212 = f139_aix(n_683); (int32_t*)_t2212->b + hr_ix(_i2212, _t2212->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:41"); }))));
}
static void f142_set_cv(int64_t n_687, int64_t t_688) {
{ int32_t *_t2214 = &((*({ hrv *_t2215 = &(g396); int64_t _i2215 = f139_aix(n_687); (int32_t*)_t2215->b + hr_ix(_i2215, _t2215->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:48"); }))); *_t2214 = ((int32_t)(t_688)); }
}
static int64_t f143_tclass(int64_t t_689) {
S1 x_690 = (*({ hrv *_t2217 = &(g551); int64_t _i2217 = t_689; (S1*)_t2217->b + hr_ix(_i2217, _t2217->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:83"); })); 
int64_t k_691 = ((int64_t)((x_690).k_)); 
if (((k_691) == (((int64_t)5LL)))) { (void)(f144_si_layout(((int64_t)((x_690).a_))));
return ((int64_t)(((*({ hrv *_t2219 = &(g554); int64_t _i2219 = (x_690).a_; (S10*)_t2219->b + hr_ix(_i2219, _t2219->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:85"); }))).cls_));
 }
if (((k_691) == (((int64_t)7LL)))) { (void)(f146_ei_layout(((int64_t)((x_690).a_))));
S9 v_732 = (*({ hrv *_t2221 = &(g557); int64_t _i2221 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2222 = &(g556); int64_t _i2222 = (x_690).a_; (S8*)_t2222->b + hr_ix(_i2222, _t2222->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:86"); }))).v0_)) + (int64_t)((int64_t)((x_690).c_)))); (S9*)_t2221->b + hr_ix(_i2221, _t2221->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:86"); })); 
if ((((v_732).si_) >= (((int32_t)0LL)))) { (void)(f144_si_layout(((int64_t)((v_732).si_))));
return ((int64_t)(((*({ hrv *_t2224 = &(g554); int64_t _i2224 = (v_732).si_; (S10*)_t2224->b + hr_ix(_i2224, _t2224->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:86"); }))).cls_));
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
if (((((*({ hrv *_t2228 = &(g554); int64_t _i2228 = si_692; (S10*)_t2228->b + hr_ix(_i2228, _t2228->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:127"); }))).done_) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t2229 = &(((*({ hrv *_t2230 = &(g554); int64_t _i2230 = si_692; (S10*)_t2230->b + hr_ix(_i2230, _t2230->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:128"); }))).done_); *_t2229 = ((uint8_t)1LL); }
int64_t off_693 = ((int64_t)0LL); 
int64_t cls_694 = ((int64_t)0LL); 
bool flat_695 = true; 
int64_t f0_696 = ((int64_t)(((*({ hrv *_t2231 = &(g554); int64_t _i2231 = si_692; (S10*)_t2231->b + hr_ix(_i2231, _t2231->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:130"); }))).f0_)); 
int64_t fnum_697 = ((int64_t)(((*({ hrv *_t2232 = &(g554); int64_t _i2232 = si_692; (S10*)_t2232->b + hr_ix(_i2232, _t2232->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:130"); }))).fnum_)); 
{ int64_t _e2234 = fnum_697; for (int64_t _k2234 = 0; _k2234 < _e2234; _k2234++) { int64_t i_698 = (int64_t)_k2234; int64_t fi_699 = ((int64_t)((int64_t)f0_696 + (int64_t)i_698)); 
int64_t ft_700 = ((int64_t)(((*({ hrv *_t2235 = &(g555); int64_t _i2235 = fi_699; (S11*)_t2235->b + hr_ix(_i2235, _t2235->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:133"); }))).ty_)); 
if (((ft_700) >= (((int64_t)0LL)))) { int64_t c_701 = f143_tclass(ft_700); 
if (((c_701) > (cls_694))) { cls_694 = c_701;
 }
if ((!(f145_tflat(ft_700)))) { flat_695 = false;
 }
 }
 } } _bk2233:; 
bool cur_var_715 = false; 
{ int64_t _e2239 = fnum_697; for (int64_t _k2239 = 0; _k2239 < _e2239; _k2239++) { int64_t i_716 = (int64_t)_k2239; int64_t fi_717 = ((int64_t)((int64_t)f0_696 + (int64_t)i_716)); 
int64_t ft_718 = ((int64_t)(((*({ hrv *_t2240 = &(g555); int64_t _i2240 = fi_717; (S11*)_t2240->b + hr_ix(_i2240, _t2240->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:143"); }))).ty_)); 
if (((ft_718) < (((int64_t)0LL)))) { if (((((*({ hrv *_t2241 = &(g555); int64_t _i2241 = fi_717; (S11*)_t2241->b + hr_ix(_i2241, _t2241->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:145"); }))).padn_) < (((int32_t)0LL)))) { if (((cls_694) == (((int64_t)0LL)))) { int64_t a_719 = ((int64_t)1LL); 
{ int64_t _e2243 = fnum_697; for (int64_t _k2243 = ((int64_t)((int64_t)i_716 + (int64_t)((int64_t)1LL))); _k2243 < _e2243; _k2243++) { int64_t j_720 = (int64_t)_k2243; if (((((*({ hrv *_t2244 = &(g555); int64_t _i2244 = ((int64_t)((int64_t)f0_696 + (int64_t)j_720)); (S11*)_t2244->b + hr_ix(_i2244, _t2244->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:148"); }))).ty_) >= (((int32_t)0LL)))) { a_719 = f147_pad_align(((int64_t)(((*({ hrv *_t2246 = &(g555); int64_t _i2246 = ((int64_t)((int64_t)f0_696 + (int64_t)j_720)); (S11*)_t2246->b + hr_ix(_i2246, _t2246->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:148"); }))).ty_)));
{ goto _bk2242; }
 }
 } } _bk2242:; 
int64_t next_off_725 = ((int64_t)((int64_t)HR_SDIV(int64_t, ((int64_t)((int64_t)((int64_t)((int64_t)off_693 + (int64_t)a_719)) - (int64_t)((int64_t)1LL))), a_719, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:149") * (int64_t)a_719)); 
{ int32_t *_t2247 = &(((*({ hrv *_t2248 = &(g555); int64_t _i2248 = fi_717; (S11*)_t2248->b + hr_ix(_i2248, _t2248->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:150"); }))).padn_); *_t2247 = ((int32_t)(((int64_t)((int64_t)next_off_725 - (int64_t)off_693)))); }
{ int64_t *_t2249 = &(((*({ hrv *_t2250 = &(g555); int64_t _i2250 = fi_717; (S11*)_t2250->b + hr_ix(_i2250, _t2250->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:151"); }))).off_); *_t2249 = off_693; }
off_693 = next_off_725;
 } else { { int32_t *_t2251 = &(((*({ hrv *_t2252 = &(g555); int64_t _i2252 = fi_717; (S11*)_t2252->b + hr_ix(_i2252, _t2252->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:154"); }))).padn_); *_t2251 = ((int32_t)0LL); }
{ int64_t *_t2253 = &(((*({ hrv *_t2254 = &(g555); int64_t _i2254 = fi_717; (S11*)_t2254->b + hr_ix(_i2254, _t2254->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:155"); }))).off_); *_t2253 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); }
 }
 } else { { int64_t *_t2255 = &(((*({ hrv *_t2256 = &(g555); int64_t _i2256 = fi_717; (S11*)_t2256->b + hr_ix(_i2256, _t2256->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:158"); }))).off_); *_t2255 = ({ int64_t _r2257; if ((!(cur_var_715))) { _r2257 = off_693;  } else { _r2257 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2257; }); }
if ((!(cur_var_715))) { { int64_t *_t2258 = &(off_693); *_t2258 = ((int64_t)((int64_t)(*_t2258) + (int64_t)((int64_t)(((*({ hrv *_t2259 = &(g555); int64_t _i2259 = fi_717; (S11*)_t2259->b + hr_ix(_i2259, _t2259->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:159"); }))).padn_)))); }
 }
 }
continue;
 }
int64_t c_726 = f143_tclass(ft_718); 
if (((c_726) != (((int64_t)0LL)))) { cur_var_715 = true;
 }
{ int64_t *_t2261 = &(((*({ hrv *_t2262 = &(g555); int64_t _i2262 = fi_717; (S11*)_t2262->b + hr_ix(_i2262, _t2262->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:165"); }))).off_); *_t2261 = ({ int64_t _r2263; if ((!(cur_var_715))) { _r2263 = off_693;  } else { _r2263 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2263; }); }
if ((!(cur_var_715))) { { int64_t *_t2264 = &(off_693); *_t2264 = ((int64_t)((int64_t)(*_t2264) + (int64_t)f149_tsize(ft_718))); }
 }
 } } _bk2238:; 
{ uint8_t *_t2266 = &(((*({ hrv *_t2267 = &(g554); int64_t _i2267 = si_692; (S10*)_t2267->b + hr_ix(_i2267, _t2267->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:168"); }))).cls_); *_t2266 = ((uint8_t)(cls_694)); }
{ bool *_t2268 = &(((*({ hrv *_t2269 = &(g554); int64_t _i2269 = si_692; (S10*)_t2269->b + hr_ix(_i2269, _t2269->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:168"); }))).flat_); *_t2268 = flat_695; }
{ int64_t *_t2270 = &(((*({ hrv *_t2271 = &(g554); int64_t _i2271 = si_692; (S10*)_t2271->b + hr_ix(_i2271, _t2271->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:169"); }))).size_); *_t2270 = ({ int64_t _r2272; if (((cls_694) == (((int64_t)0LL)))) { _r2272 = f103_max(off_693, ((int64_t)1LL));  } else { _r2272 = off_693;  } _r2272; }); }
{ bool *_t2274 = &(((*({ hrv *_t2275 = &(g554); int64_t _i2275 = si_692; (S10*)_t2275->b + hr_ix(_i2275, _t2275->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:170"); }))).zero_); *_t2274 = (((cls_694) == (((int64_t)0LL))) && ((off_693) == (((int64_t)0LL)))); }
{ uint8_t *_t2276 = &(((*({ hrv *_t2277 = &(g554); int64_t _i2277 = si_692; (S10*)_t2277->b + hr_ix(_i2277, _t2277->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:171"); }))).done_); *_t2276 = ((uint8_t)2LL); }
}
static bool f145_tflat(int64_t t_702) {
S1 x_703 = (*({ hrv *_t2278 = &(g551); int64_t _i2278 = t_702; (S1*)_t2278->b + hr_ix(_i2278, _t2278->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:118"); })); 
int64_t k_704 = ((int64_t)((x_703).k_)); 
if ((((k_704) == (((int64_t)10LL))) || ((k_704) == (((int64_t)9LL))))) { return false;
 }
if (((k_704) == (((int64_t)5LL)))) { (void)(f144_si_layout(((int64_t)((x_703).a_))));
return ((*({ hrv *_t2280 = &(g554); int64_t _i2280 = (x_703).a_; (S10*)_t2280->b + hr_ix(_i2280, _t2280->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:120"); }))).flat_;
 }
if ((((k_704) == (((int64_t)6LL))) || ((k_704) == (((int64_t)7LL))))) { (void)(f146_ei_layout(((int64_t)((x_703).a_))));
return ((*({ hrv *_t2282 = &(g556); int64_t _i2282 = (x_703).a_; (S8*)_t2282->b + hr_ix(_i2282, _t2282->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:121"); }))).flat_;
 }
if (((k_704) == (((int64_t)8LL)))) { return f145_tflat(((int64_t)((x_703).a_)));
 }
return true;
}
static void f146_ei_layout(int64_t ei_705) {
if (((((*({ hrv *_t2284 = &(g556); int64_t _i2284 = ei_705; (S8*)_t2284->b + hr_ix(_i2284, _t2284->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:174"); }))).done_) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t2285 = &(((*({ hrv *_t2286 = &(g556); int64_t _i2286 = ei_705; (S8*)_t2286->b + hr_ix(_i2286, _t2286->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:175"); }))).done_); *_t2285 = ((uint8_t)1LL); }
int64_t nv_706 = ((int64_t)(((*({ hrv *_t2287 = &(g556); int64_t _i2287 = ei_705; (S8*)_t2287->b + hr_ix(_i2287, _t2287->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:176"); }))).vnum_)); 
int64_t tz_707 = ({ int64_t _r2288; if (((nv_706) <= (((int64_t)256LL)))) { _r2288 = ((int64_t)1LL);  } else { _r2288 = ((int64_t)2LL);  } _r2288; }); 
{ uint8_t *_t2289 = &(((*({ hrv *_t2290 = &(g556); int64_t _i2290 = ei_705; (S8*)_t2290->b + hr_ix(_i2290, _t2290->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:178"); }))).tagsz_); *_t2289 = ((uint8_t)(tz_707)); }
int64_t mx_708 = ((int64_t)0LL); 
int64_t cls_709 = ((int64_t)0LL); 
bool flat_710 = true; 
{ int64_t _e2292 = nv_706; for (int64_t _k2292 = 0; _k2292 < _e2292; _k2292++) { int64_t i_711 = (int64_t)_k2292; int64_t v_712 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2293 = &(g556); int64_t _i2293 = ei_705; (S8*)_t2293->b + hr_ix(_i2293, _t2293->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:181"); }))).v0_)) + (int64_t)i_711)); 
if (((((*({ hrv *_t2294 = &(g557); int64_t _i2294 = v_712; (S9*)_t2294->b + hr_ix(_i2294, _t2294->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:182"); }))).si_) >= (((int32_t)0LL)))) { int64_t si_713 = ((int64_t)(((*({ hrv *_t2295 = &(g557); int64_t _i2295 = v_712; (S9*)_t2295->b + hr_ix(_i2295, _t2295->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:183"); }))).si_)); 
(void)(f144_si_layout(si_713));
if (((((int64_t)(((*({ hrv *_t2297 = &(g554); int64_t _i2297 = si_713; (S10*)_t2297->b + hr_ix(_i2297, _t2297->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:185"); }))).cls_))) > (cls_709))) { cls_709 = ((int64_t)(((*({ hrv *_t2298 = &(g554); int64_t _i2298 = si_713; (S10*)_t2298->b + hr_ix(_i2298, _t2298->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:185"); }))).cls_));
 }
if ((!(((*({ hrv *_t2299 = &(g554); int64_t _i2299 = si_713; (S10*)_t2299->b + hr_ix(_i2299, _t2299->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:186"); }))).flat_))) { flat_710 = false;
 }
int64_t ps_714 = ({ int64_t _r2300; if (((*({ hrv *_t2301 = &(g554); int64_t _i2301 = si_713; (S10*)_t2301->b + hr_ix(_i2301, _t2301->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:187"); }))).zero_) { _r2300 = ((int64_t)0LL);  } else { _r2300 = ((*({ hrv *_t2302 = &(g554); int64_t _i2302 = si_713; (S10*)_t2302->b + hr_ix(_i2302, _t2302->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:187"); }))).size_;  } _r2300; }); 
{ int64_t *_t2303 = &(((*({ hrv *_t2304 = &(g557); int64_t _i2304 = v_712; (S9*)_t2304->b + hr_ix(_i2304, _t2304->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:188"); }))).size_); *_t2303 = ps_714; }
if (((ps_714) > (mx_708))) { mx_708 = ps_714;
 }
 }
 } } _bk2291:; 
{ uint8_t *_t2305 = &(((*({ hrv *_t2306 = &(g556); int64_t _i2306 = ei_705; (S8*)_t2306->b + hr_ix(_i2306, _t2306->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:192"); }))).cls_); *_t2305 = ((uint8_t)(cls_709)); }
{ bool *_t2307 = &(((*({ hrv *_t2308 = &(g556); int64_t _i2308 = ei_705; (S8*)_t2308->b + hr_ix(_i2308, _t2308->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:192"); }))).flat_); *_t2307 = flat_710; }
{ int64_t *_t2309 = &(((*({ hrv *_t2310 = &(g556); int64_t _i2310 = ei_705; (S8*)_t2310->b + hr_ix(_i2310, _t2310->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:193"); }))).size_); *_t2309 = ((int64_t)((int64_t)((int64_t)(tz_707)) + (int64_t)mx_708)); }
{ uint8_t *_t2311 = &(((*({ hrv *_t2312 = &(g556); int64_t _i2312 = ei_705; (S8*)_t2312->b + hr_ix(_i2312, _t2312->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:194"); }))).done_); *_t2311 = ((uint8_t)2LL); }
}
static int64_t f147_pad_align(int64_t t_721) {
S1 x_722 = (*({ hrv *_t2313 = &(g551); int64_t _i2313 = t_721; (S1*)_t2313->b + hr_ix(_i2313, _t2313->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:96"); })); 
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
S1 x_728 = (*({ hrv *_t2317 = &(g551); int64_t _i2317 = t_727; (S1*)_t2317->b + hr_ix(_i2317, _t2317->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:104"); })); 
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
return ((*({ hrv *_t2321 = &(g554); int64_t _i2321 = (x_728).a_; (S10*)_t2321->b + hr_ix(_i2321, _t2321->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:111"); }))).size_;
 }
if (((k_729) == (((int64_t)7LL)))) { (void)(f146_ei_layout(((int64_t)((x_728).a_))));
S9 v_730 = (*({ hrv *_t2323 = &(g557); int64_t _i2323 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2324 = &(g556); int64_t _i2324 = (x_728).a_; (S8*)_t2324->b + hr_ix(_i2324, _t2324->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:112"); }))).v0_)) + (int64_t)((int64_t)((x_728).c_)))); (S9*)_t2323->b + hr_ix(_i2323, _t2323->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:112"); })); 
return (v_730).size_;
 }
if (((k_729) == (((int64_t)6LL)))) { (void)(f146_ei_layout(((int64_t)((x_728).a_))));
return ((*({ hrv *_t2326 = &(g556); int64_t _i2326 = (x_728).a_; (S8*)_t2326->b + hr_ix(_i2326, _t2326->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:113"); }))).size_;
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
return ((int64_t)((*({ hrv *_t2332 = &(g396); int64_t _i2332 = f139_aix(n_736); (int32_t*)_t2332->b + hr_ix(_i2332, _t2332->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:49"); }))));
}
static bool f151_conv_ok(int64_t f_737, int64_t t_738, int64_t n_739) {
if (((f_737) == (t_738))) { return true;
 }
S1 a_740 = (*({ hrv *_t2334 = &(g551); int64_t _i2334 = f_737; (S1*)_t2334->b + hr_ix(_i2334, _t2334->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:170"); })); 
S1 b_741 = (*({ hrv *_t2335 = &(g551); int64_t _i2335 = t_738; (S1*)_t2335->b + hr_ix(_i2335, _t2335->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:170"); })); 
if (f152_widens(f_737, t_738)) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)2LL))) && (((a_740).k_) == (((uint8_t)10LL)))) && ((((uint16_t)((uint64_t)(a_740).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)9LL))) && ((((a_740).k_) == (((uint8_t)8LL))) || (((a_740).k_) == (((uint8_t)9LL))))) && (((a_740).a_) == ((b_741).a_)))) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)9LL))) && (((a_740).k_) == (((uint8_t)18LL)))) && ((((int64_t)((b_741).a_))) == (g564)))) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)10LL))) && (((a_740).k_) == (((uint8_t)10LL)))) && (((((uint16_t)((uint64_t)(b_741).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))) || ((((uint16_t)((uint64_t)(a_740).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))))) { if ((((a_740).a_) == ((b_741).a_))) { return true;
 }
if (((((((*({ hrv *_t2337 = &(g551); int64_t _i2337 = (b_741).a_; (S1*)_t2337->b + hr_ix(_i2337, _t2337->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:177"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t2338 = &(g551); int64_t _i2338 = (a_740).a_; (S1*)_t2338->b + hr_ix(_i2338, _t2338->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:177"); }))).k_) == (((uint8_t)7LL)))) && ((((*({ hrv *_t2339 = &(g551); int64_t _i2339 = (a_740).a_; (S1*)_t2339->b + hr_ix(_i2339, _t2339->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:177"); }))).a_) == (((*({ hrv *_t2340 = &(g551); int64_t _i2340 = (b_741).a_; (S1*)_t2340->b + hr_ix(_i2340, _t2340->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:177"); }))).a_)))) { return true;
 }
if (((((((*({ hrv *_t2341 = &(g551); int64_t _i2341 = (b_741).a_; (S1*)_t2341->b + hr_ix(_i2341, _t2341->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:178"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t2342 = &(g551); int64_t _i2342 = (a_740).a_; (S1*)_t2342->b + hr_ix(_i2342, _t2342->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:178"); }))).k_) == (((uint8_t)6LL)))) && ((((*({ hrv *_t2343 = &(g551); int64_t _i2343 = (a_740).a_; (S1*)_t2343->b + hr_ix(_i2343, _t2343->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:178"); }))).a_) == (((*({ hrv *_t2344 = &(g551); int64_t _i2344 = (b_741).a_; (S1*)_t2344->b + hr_ix(_i2344, _t2344->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:178"); }))).a_)))) { return true;
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
S1 a_744 = (*({ hrv *_t2345 = &(g551); int64_t _i2345 = f_742; (S1*)_t2345->b + hr_ix(_i2345, _t2345->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:115"); })); 
S1 b_745 = (*({ hrv *_t2346 = &(g551); int64_t _i2346 = t_743; (S1*)_t2346->b + hr_ix(_i2346, _t2346->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:115"); })); 
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
if (((((a_744).k_) == (((uint8_t)17LL))) && (((b_745).k_) == (((uint8_t)3LL))))) { return ((t_743) == (g563));
 }
return false;
}
static bool f153_is_signed(int64_t t_746) {
return ((((*({ hrv *_t2355 = &(g551); int64_t _i2355 = t_746; (S1*)_t2355->b + hr_ix(_i2355, _t2355->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:60"); }))).s_) < (((uint8_t)4LL)));
}
static int64_t f154_ibits(int64_t t_749) {
return ((int64_t)((((int64_t)8LL)) << ((((int64_t)(((uint8_t)((uint64_t)((*({ hrv *_t2356 = &(g551); int64_t _i2356 = t_749; (S1*)_t2356->b + hr_ix(_i2356, _t2356->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:61"); }))).s_ & (uint64_t)((uint8_t)3LL)))))) & 63)));
}
static M78 f155_cval(int64_t n_750) {
if (((n_750) < (((int64_t)0LL)))) { return (M78){ ((int64_t)0LL), false, false };
 }
S4 x_751 = (*({ hrv *_t2357 = &(g704); int64_t _i2357 = n_750; (S4*)_t2357->b + hr_ix(_i2357, _t2357->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:125"); })); 
int64_t k_752 = ((int64_t)((x_751).k_)); 
if (((k_752) == (((int64_t)1LL)))) { return (M78){ ((*({ hrv *_t2358 = &(g914); int64_t _i2358 = (x_751).t_; (S3*)_t2358->b + hr_ix(_i2358, _t2358->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:126"); }))).v_, ((*({ hrv *_t2359 = &(g914); int64_t _i2359 = (x_751).t_; (S3*)_t2359->b + hr_ix(_i2359, _t2359->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:126"); }))).uns_, true };
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
if ((((k_752) == (((int64_t)8LL))) && ((f156_rk(n_750)) == (((int64_t)6LL))))) { return (M78){ (*({ hrv *_t2363 = &(g436); int64_t _i2363 = f157_rv(n_750); (int64_t*)_t2363->b + hr_ix(_i2363, _t2363->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:128"); })), false, true };
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
return (M78){ HR_SDIV(int64_t, a_758, b_761, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:134"), false, true };
 }
if (((o_764) == (((int64_t)25LL)))) { if (((b_761) == (((int64_t)0LL)))) { return (M78){ ((int64_t)0LL), false, false };
 }
return (M78){ HR_SMOD(int64_t, ((int64_t)((int64_t)HR_SMOD(int64_t, a_758, b_761, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:135") + (int64_t)b_761)), b_761, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:135"), false, true };
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
return ((int64_t)((*({ hrv *_t2369 = &(g397); int64_t _i2369 = f139_aix(n_756); (uint8_t*)_t2369->b + hr_ix(_i2369, _t2369->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:44"); }))));
}
static int64_t f157_rv(int64_t n_757) {
return ((int64_t)((*({ hrv *_t2371 = &(g398); int64_t _i2371 = f139_aix(n_757); (int32_t*)_t2371->b + hr_ix(_i2371, _t2371->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:45"); }))));
}
static bool f158_int_fits(int64_t v_768, bool uns_769, int64_t t_770) {
if (((((*({ hrv *_t2373 = &(g551); int64_t _i2373 = t_770; (S1*)_t2373->b + hr_ix(_i2373, _t2373->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:108"); }))).k_) != (((uint8_t)3LL)))) { return false;
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
S4 x_780 = (*({ hrv *_t2388 = &(g704); int64_t _i2388 = n_778; (S4*)_t2388->b + hr_ix(_i2388, _t2388->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:190"); })); 
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
if (((k_781) == (((int64_t)20LL)))) { { int32_t _e2404 = (x_780).n_; for (int32_t _k2404 = 0; _k2404 < _e2404; _k2404++) { int32_t i_786 = (int32_t)_k2404; (void)(f162_commit(((int64_t)(((*({ hrv *_t2406 = &(g704); int64_t _i2406 = f90_kid(n_778, ((int64_t)(i_786))); (S4*)_t2406->b + hr_ix(_i2406, _t2406->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:204"); }))).b_)), t_779));
 } } _bk2403:; 
return;
 }
if (((k_781) == (((int64_t)16LL)))) { int64_t e_787 = ({ int64_t _r2408; if ((((((*({ hrv *_t2409 = &(g551); int64_t _i2409 = t_779; (S1*)_t2409->b + hr_ix(_i2409, _t2409->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:206"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2410 = &(g551); int64_t _i2410 = t_779; (S1*)_t2410->b + hr_ix(_i2410, _t2410->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:206"); }))).k_) == (((uint8_t)9LL))))) { _r2408 = ((int64_t)(((*({ hrv *_t2411 = &(g551); int64_t _i2411 = t_779; (S1*)_t2411->b + hr_ix(_i2411, _t2411->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:206"); }))).a_));  } else { _r2408 = g575;  } _r2408; }); 
if ((((x_780).a_) >= (((int32_t)0LL)))) { (void)(f140_conv(((int64_t)((x_780).a_)), e_787));
(void)(f140_conv(((int64_t)((x_780).b_)), g563));
 }
{ int32_t _e2415 = (x_780).n_; for (int32_t _k2415 = 0; _k2415 < _e2415; _k2415++) { int32_t i_788 = (int32_t)_k2415; (void)(f140_conv(f90_kid(n_778, ((int64_t)(i_788))), e_787));
 } } _bk2414:; 
if (((((*({ hrv *_t2418 = &(g551); int64_t _i2418 = t_779; (S1*)_t2418->b + hr_ix(_i2418, _t2418->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:209"); }))).k_) == (((uint8_t)9LL)))) { (void)(f138_set_t(n_778, f123_t_arr(e_787, ((int64_t)1LL), f103_max(((int64_t)((x_780).n_)), ((int64_t)1LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f142_set_cv(n_778, t_779));
 }
return;
 }
}
static bool f163_is_pending(int64_t t_783) {
int64_t k_784 = ((int64_t)(((*({ hrv *_t2423 = &(g551); int64_t _i2423 = t_783; (S1*)_t2423->b + hr_ix(_i2423, _t2423->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:106"); }))).k_)); 
return ((((((k_784) == (((int64_t)12LL))) || ((k_784) == (((int64_t)13LL)))) || ((k_784) == (((int64_t)18LL)))) || ((k_784) == (((int64_t)19LL)))) || ((k_784) == (((int64_t)11LL))));
}
static bool f164_is_byte_arr(int64_t t_789) {
uint8_t k_790 = ((*({ hrv *_t2424 = &(g551); int64_t _i2424 = t_789; (S1*)_t2424->b + hr_ix(_i2424, _t2424->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:68"); }))).k_; 
return ((((k_790) == (((uint8_t)8LL))) || ((k_790) == (((uint8_t)9LL)))) && ((((int64_t)(((*({ hrv *_t2425 = &(g551); int64_t _i2425 = t_789; (S1*)_t2425->b + hr_ix(_i2425, _t2425->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:68"); }))).a_))) == (g564)));
}
static bool f165_is_opt(int64_t t_792) {
return (((((*({ hrv *_t2426 = &(g551); int64_t _i2426 = t_792; (S1*)_t2426->b + hr_ix(_i2426, _t2426->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:66"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2427 = &(g551); int64_t _i2427 = t_792; (S1*)_t2427->b + hr_ix(_i2427, _t2427->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:66"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))));
}
static int64_t f166_ck_id(int64_t n_793, int64_t want_794) {
int64_t name_795 = ((int64_t)(((*({ hrv *_t2428 = &(g704); int64_t _i2428 = n_793; (S4*)_t2428->b + hr_ix(_i2428, _t2428->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:339"); }))).s_)); 
int64_t v_803 = f167_find_lv(name_795); 
if (((v_803) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_793, ((int64_t)1LL), v_803));
(void)(f171_note_cap(v_803));
return f138_set_t(n_793, ((int64_t)(((*({ hrv *_t2433 = &(g389); int64_t _i2433 = v_803; (S12*)_t2433->b + hr_ix(_i2433, _t2433->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:341"); }))).ty_)));
 }
int64_t ns_814 = f110_ns_of(n_793); 
int64_t d_815 = f116_lookup_q(name_795, ns_814, ((int64_t)5LL)); 
if (((d_815) >= (((int64_t)0LL)))) { int64_t g_816 = ((int64_t)(((*({ hrv *_t2436 = &(g489); int64_t _i2436 = d_815; (S5*)_t2436->b + hr_ix(_i2436, _t2436->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:345"); }))).node_)); 
int64_t ci_829 = f173_const_of(d_815); 
if (((ci_829) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_793, ((int64_t)6LL), ci_829));
return f138_set_t(n_793, g571);
 }
(void)(f170_set_r(n_793, ((int64_t)2LL), d_815));
return f138_set_t(n_793, f109_global_type(d_815));
 }
d_815 = f116_lookup_q(name_795, ns_814, ((int64_t)4LL));
if (((d_815) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_793, ((int64_t)3LL), d_815));
(void)(f175_set_x(n_793, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_793, g578);
 }
hrv m_832 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o2448 = &(m_832); hr_fs(_o2448, hr_str("unknown name: ", 14)); hr_fs(_o2448, f10_nm(name_795)); }));
(void)(f108_cerr(n_793, hr_sl(m_832)));
return f138_set_t(n_793, g575);
}
static int64_t f167_find_lv(int64_t name_796) {
int64_t i_797 = ((int64_t)((int64_t)(g390).n - (int64_t)((int64_t)1LL))); 
while (((i_797) >= (((int64_t)0LL)))) { int64_t v_798 = ((int64_t)((*({ hrv *_t2453 = &(g390); int64_t _i2453 = i_797; (int32_t*)_t2453->b + hr_ix(_i2453, _t2453->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:60"); })))); 
if ((((((int64_t)(((*({ hrv *_t2454 = &(g389); int64_t _i2454 = v_798; (S12*)_t2454->b + hr_ix(_i2454, _t2454->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:60"); }))).name_))) == (name_796)) && f168_visible(((int64_t)(((*({ hrv *_t2456 = &(g389); int64_t _i2456 = v_798; (S12*)_t2456->b + hr_ix(_i2456, _t2456->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:60"); }))).own_))))) { return v_798;
 }
i_797--;
 } _bk2452:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f168_visible(int64_t own_799) {
return f169_visible_in(own_799, g401);
}
static bool f169_visible_in(int64_t own_800, int64_t cur_801) {
int64_t i_802 = cur_801; 
while (((i_802) >= (((int64_t)0LL)))) { if (((i_802) == (own_800))) { return true;
 }
i_802 = ((int64_t)(((*({ hrv *_t2459 = &(g388); int64_t _i2459 = i_802; (S6*)_t2459->b + hr_ix(_i2459, _t2459->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:56"); }))).par_));
 } _bk2458:; 
return false;
}
static void f170_set_r(int64_t n_804, int64_t k_805, int64_t v_806) {
int64_t i_807 = f139_aix(n_804); 
{ uint8_t *_t2461 = &((*({ hrv *_t2462 = &(g397); int64_t _i2462 = i_807; (uint8_t*)_t2462->b + hr_ix(_i2462, _t2462->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:43"); }))); *_t2461 = ((uint8_t)(k_805)); }
{ int32_t *_t2463 = &((*({ hrv *_t2464 = &(g398); int64_t _i2464 = i_807; (int32_t*)_t2464->b + hr_ix(_i2464, _t2464->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:43"); }))); *_t2463 = ((int32_t)(v_806)); }
}
static void f171_note_cap(int64_t v_808) {
int64_t own_809 = ((int64_t)(((*({ hrv *_t2465 = &(g389); int64_t _i2465 = v_808; (S12*)_t2465->b + hr_ix(_i2465, _t2465->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:70"); }))).own_)); 
int64_t a_810 = g401; 
while ((((a_810) >= (((int64_t)0LL))) && ((a_810) != (own_809)))) { (void)(f172_add_cap_one(((int64_t)(((*({ hrv *_t2468 = &(g388); int64_t _i2468 = a_810; (S6*)_t2468->b + hr_ix(_i2468, _t2468->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:73"); }))).cfn_)), v_808));
a_810 = ((int64_t)(((*({ hrv *_t2469 = &(g388); int64_t _i2469 = a_810; (S6*)_t2469->b + hr_ix(_i2469, _t2469->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:74"); }))).par_));
 } _bk2466:; 
}
static bool f172_add_cap_one(int64_t cf_811, int64_t v_812) {
if ((((cf_811) < (((int64_t)0LL))) || ((cf_811) == (((int64_t)(((*({ hrv *_t2470 = &(g389); int64_t _i2470 = v_812; (S12*)_t2470->b + hr_ix(_i2470, _t2470->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:64"); }))).cfn_)))))) { return false;
 }
{ hrv *_v2472 = &(g392); for (int64_t _k2472 = 0; _k2472 < _v2472->n; _k2472++) { S13 x_813 = ((S13*)_v2472->b)[_k2472]; if ((((((int64_t)((x_813).inst_))) == (cf_811)) && ((((int64_t)((x_813).lv_))) == (v_812)))) { return false;
 }
 } } _bk2471:; 
(void)(({ hrv *_v2473 = &(g392); S13 _x2473 = ((S13){ .inst_ = ((int32_t)(cf_811)), .lv_ = ((int32_t)(v_812)), }); S13 *_p2473 = (S13*)hr_grow(_v2473, 1, sizeof _x2473); *_p2473 = _x2473; _p2473; }));
return true;
}
static int64_t f173_const_of(int64_t d_817) {
{ hrv *_v2475 = &(g437); for (int64_t _k2475 = 0; _k2475 < _v2475->n; _k2475++) { int32_t c_818 = ((int32_t*)_v2475->b)[_k2475]; int64_t i_819 = (int64_t)_k2475; if (((((int64_t)(c_818))) == (d_817))) { return i_819;
 }
 } } _bk2474:; 
int64_t g_820 = ((int64_t)(((*({ hrv *_t2476 = &(g489); int64_t _i2476 = d_817; (S5*)_t2476->b + hr_ix(_i2476, _t2476->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:360"); }))).node_)); 
S4 x_821 = (*({ hrv *_t2477 = &(g704); int64_t _i2477 = g_820; (S4*)_t2477->b + hr_ix(_i2477, _t2477->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:361"); })); 
if (((((((uint16_t)((uint64_t)(x_821).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || (((x_821).a_) >= (((int32_t)0LL)))) || (((x_821).b_) < (((int32_t)0LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t iv_822 = f90_kid(((int64_t)((x_821).b_)), ((int64_t)0LL)); 
M56 _t2479 = f120_ceval(iv_822, f110_ns_of(g_820)); int64_t v_823 = _t2479.r0; bool ok_824 = _t2479.r1; 
if ((!(ok_824))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if ((!(f174_all_int(iv_822)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
(void)(({ hrv *_v2483 = &(g437); int32_t _x2483 = ((int32_t)(d_817)); int32_t *_p2483 = (int32_t*)hr_grow(_v2483, 1, sizeof _x2483); *_p2483 = _x2483; _p2483; }));
(void)(({ hrv *_v2484 = &(g436); int64_t _x2484 = v_823; int64_t *_p2484 = (int64_t*)hr_grow(_v2484, 1, sizeof _x2484); *_p2484 = _x2484; _p2484; }));
return ((int64_t)((int64_t)(g437).n - (int64_t)((int64_t)1LL)));
}
static bool f174_all_int(int64_t n_825) {
S4 x_826 = (*({ hrv *_t2485 = &(g704); int64_t _i2485 = n_825; (S4*)_t2485->b + hr_ix(_i2485, _t2485->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:371"); })); 
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
{ int32_t *_t2493 = &((*({ hrv *_t2494 = &(g399); int64_t _i2494 = f139_aix(n_830); (int32_t*)_t2494->b + hr_ix(_i2494, _t2494->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:46"); }))); *_t2493 = ((int32_t)(v_831)); }
}
static int64_t f176_ck_bin(int64_t n_833, int64_t want_834) {
S4 x_835 = (*({ hrv *_t2496 = &(g704); int64_t _i2496 = n_833; (S4*)_t2496->b + hr_ix(_i2496, _t2496->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:276"); })); 
int64_t o_836 = ((int64_t)((x_835).op_)); 
int64_t a_837 = ((int64_t)((x_835).a_)); 
int64_t b_838 = ((int64_t)((x_835).b_)); 
if (((o_836) == (((int64_t)52LL)))) { (void)(f137_ck(a_837, g559));
(void)(f140_conv(a_837, g559));
int64_t nm0_839 = (g391).n; 
(void)(f177_narrow_push(a_837));
(void)(f137_ck(b_838, g559));
(void)(f140_conv(b_838, g559));
(void)(f178_narrow_pop(nm0_839));
return f138_set_t(n_833, g559);
 }
if (((o_836) == (((int64_t)53LL)))) { (void)(f137_ck(a_837, g559));
(void)(f140_conv(a_837, g559));
(void)(f137_ck(b_838, g559));
(void)(f140_conv(b_838, g559));
return f138_set_t(n_833, g559);
 }
if ((((o_836) == (((int64_t)19LL))) || ((o_836) == (((int64_t)20LL))))) { (void)(f137_ck(a_837, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
(void)(f137_ck(b_838, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_833, g559);
 }
bool cmp_848 = (((((((o_836) == (((int64_t)37LL))) || ((o_836) == (((int64_t)38LL)))) || ((o_836) == (((int64_t)39LL)))) || ((o_836) == (((int64_t)40LL)))) || ((o_836) == (((int64_t)41LL)))) || ((o_836) == (((int64_t)42LL)))); 
int64_t w_849 = ({ int64_t _r2512; if (cmp_848) { _r2512 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2512 = want_834;  } _r2512; }); 
int64_t ta_850 = f137_ck(a_837, w_849); 
int64_t tb_852 = f137_ck(b_838, ({ int64_t _r2515; if (f163_is_pending(ta_850)) { _r2515 = w_849;  } else { _r2515 = f179_deref(ta_850);  } _r2515; })); 
if ((((o_836) == (((int64_t)43LL))) || ((o_836) == (((int64_t)44LL))))) { if (((((*({ hrv *_t2518 = &(g551); int64_t _i2518 = tb_852; (S1*)_t2518->b + hr_ix(_i2518, _t2518->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:292"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(b_838, g563));
 } else { if (((((*({ hrv *_t2520 = &(g551); int64_t _i2520 = f179_deref(tb_852); (S1*)_t2520->b + hr_ix(_i2520, _t2520->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:292"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(b_838, hr_str("shift count must be an integer", 30)));
 }
 }
int64_t da_853 = f179_deref(ta_850); 
if (((((*({ hrv *_t2524 = &(g551); int64_t _i2524 = da_853; (S1*)_t2524->b + hr_ix(_i2524, _t2524->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:294"); }))).k_) == (((uint8_t)12LL)))) { if ((((want_834) >= (((int64_t)0LL))) && ((((*({ hrv *_t2525 = &(g551); int64_t _i2525 = want_834; (S1*)_t2525->b + hr_ix(_i2525, _t2525->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:294"); }))).k_) == (((uint8_t)3LL))))) { (void)(f140_conv(a_837, want_834));
return f138_set_t(n_833, want_834);
 }
return f138_set_t(n_833, g571);
 }
if (((((*({ hrv *_t2529 = &(g551); int64_t _i2529 = da_853; (S1*)_t2529->b + hr_ix(_i2529, _t2529->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:295"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(a_837, hr_str("shift of a non-integer", 22)));
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
if ((((((cmp_848 && (((((*({ hrv *_t2552 = &(g551); int64_t _i2552 = da_854; (S1*)_t2552->b + hr_ix(_i2552, _t2552->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:307"); }))).k_) == (((uint8_t)3LL))) && ((((*({ hrv *_t2553 = &(g551); int64_t _i2553 = db_855; (S1*)_t2553->b + hr_ix(_i2553, _t2553->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:307"); }))).k_) == (((uint8_t)3LL))))) && ((f153_is_signed(da_854)) != (f153_is_signed(db_855)))) && (((f154_ibits(da_854)) == (((int64_t)64LL))) || ((f154_ibits(db_855)) == (((int64_t)64LL))))) && (!(f152_widens(da_854, db_855)))) && (!(f152_widens(db_855, da_854))))) { (void)(f175_set_x(n_833, ((int64_t)1LL)));
return f138_set_t(n_833, g559);
 }
if ((cmp_848 && (((o_836) == (((int64_t)37LL))) || ((o_836) == (((int64_t)38LL)))))) { int64_t ka_873 = ((int64_t)(((*({ hrv *_t2562 = &(g551); int64_t _i2562 = da_854; (S1*)_t2562->b + hr_ix(_i2562, _t2562->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:312"); }))).k_)); 
int64_t kb_874 = ((int64_t)(((*({ hrv *_t2563 = &(g551); int64_t _i2563 = db_855; (S1*)_t2563->b + hr_ix(_i2563, _t2563->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:312"); }))).k_)); 
if ((((ka_873) == (((int64_t)11LL))) || ((kb_874) == (((int64_t)11LL))))) { if ((((ka_873) == (((int64_t)11LL))) && ((kb_874) == (((int64_t)11LL))))) { return f138_set_t(n_833, g559);
 }
if (((ka_873) == (((int64_t)11LL)))) { (void)(f138_set_t(a_837, tb_852));
 } else { (void)(f138_set_t(b_838, ta_850));
 }
return f138_set_t(n_833, g559);
 }
if (((((ka_873) == (((int64_t)18LL))) || ((kb_874) == (((int64_t)18LL)))) || (f164_is_byte_arr(da_854) && f164_is_byte_arr(db_855)))) { if (((ka_873) == (((int64_t)18LL)))) { (void)(f138_set_t(a_837, g576));
 }
if (((kb_874) == (((int64_t)18LL)))) { (void)(f138_set_t(b_838, g576));
 }
(void)(f175_set_x(n_833, ((int64_t)2LL)));
return f138_set_t(n_833, g559);
 }
if ((((((((ka_873) == (((int64_t)5LL))) || ((ka_873) == (((int64_t)8LL)))) || ((ka_873) == (((int64_t)6LL)))) || ((ka_873) == (((int64_t)7LL)))) || ((ka_873) == (((int64_t)9LL)))) && ((da_854) == (db_855)))) { (void)(f175_set_x(n_833, ((int64_t)3LL)));
return f138_set_t(n_833, g559);
 }
if (((((ka_873) == (((int64_t)6LL))) && ((kb_874) == (((int64_t)7LL)))) || (((ka_873) == (((int64_t)7LL))) && ((kb_874) == (((int64_t)6LL)))))) { (void)(f175_set_x(n_833, ((int64_t)3LL)));
return f138_set_t(n_833, g559);
 }
if ((((ka_873) == (((int64_t)19LL))) || ((kb_874) == (((int64_t)19LL))))) { if (((ka_873) == (((int64_t)19LL)))) { (void)(f140_conv(a_837, db_855));
 } else { (void)(f140_conv(b_838, da_854));
 }
(void)(f175_set_x(n_833, ((int64_t)3LL)));
return f138_set_t(n_833, g559);
 }
 }
int64_t u_886 = f182_unify(n_833, a_837, b_838); 
if (cmp_848) { if (((((*({ hrv *_t2583 = &(g551); int64_t _i2583 = u_886; (S1*)_t2583->b + hr_ix(_i2583, _t2583->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:320"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(a_837, g563));
(void)(f140_conv(b_838, g563));
 }
if (((((*({ hrv *_t2586 = &(g551); int64_t _i2586 = u_886; (S1*)_t2586->b + hr_ix(_i2586, _t2586->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:320"); }))).k_) == (((uint8_t)13LL)))) { (void)(f140_conv(a_837, g569));
(void)(f140_conv(b_838, g569));
 }
return f138_set_t(n_833, g559);
 }
int64_t uk_887 = ((int64_t)(((*({ hrv *_t2590 = &(g551); int64_t _i2590 = u_886; (S1*)_t2590->b + hr_ix(_i2590, _t2590->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:321"); }))).k_)); 
if (((((((((o_836) == (((int64_t)49LL))) || ((o_836) == (((int64_t)50LL)))) || ((o_836) == (((int64_t)51LL)))) && ((uk_887) != (((int64_t)3LL)))) && ((uk_887) != (((int64_t)12LL)))) && ((uk_887) != (((int64_t)2LL)))) && ((uk_887) != (((int64_t)0LL))))) { (void)(f108_cerr(n_833, hr_str("bitwise operator on a non-integer", 33)));
 }
if ((((((uk_887) == (((int64_t)2LL))) && ((o_836) != (((int64_t)49LL)))) && ((o_836) != (((int64_t)50LL)))) && ((o_836) != (((int64_t)51LL))))) { (void)(f108_cerr(n_833, hr_str("arithmetic on bool", 18)));
 }
return f138_set_t(n_833, u_886);
}
static void f177_narrow_push(int64_t c_840) {
if (((c_840) < (((int64_t)0LL)))) { return;
 }
S4 x_841 = (*({ hrv *_t2594 = &(g704); int64_t _i2594 = c_840; (S4*)_t2594->b + hr_ix(_i2594, _t2594->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:84"); })); 
int64_t k_842 = ((int64_t)((x_841).k_)); 
if ((((k_842) == (((int64_t)8LL))) && ((f156_rk(c_840)) == (((int64_t)1LL))))) { int64_t v_843 = f157_rv(c_840); 
int64_t t_844 = ((int64_t)(((*({ hrv *_t2597 = &(g389); int64_t _i2597 = v_843; (S12*)_t2597->b + hr_ix(_i2597, _t2597->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:87"); }))).ty_)); 
if ((((((*({ hrv *_t2598 = &(g551); int64_t _i2598 = t_844; (S1*)_t2598->b + hr_ix(_i2598, _t2598->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:88"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2599 = &(g551); int64_t _i2599 = t_844; (S1*)_t2599->b + hr_ix(_i2599, _t2599->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:88"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(({ hrv *_v2600 = &(g391); int32_t _x2600 = ((int32_t)(v_843)); int32_t *_p2600 = (int32_t*)hr_grow(_v2600, 1, sizeof _x2600); *_p2600 = _x2600; _p2600; }));
(void)(({ hrv *_v2601 = &(g391); int32_t _x2601 = ((int32_t)(t_844)); int32_t *_p2601 = (int32_t*)hr_grow(_v2601, 1, sizeof _x2601); *_p2601 = _x2601; _p2601; }));
{ int32_t *_t2602 = &(((*({ hrv *_t2603 = &(g389); int64_t _i2603 = v_843; (S12*)_t2603->b + hr_ix(_i2603, _t2603->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:90"); }))).ty_); *_t2602 = ((int32_t)(f119_t_ref(((int64_t)(((*({ hrv *_t2605 = &(g551); int64_t _i2605 = t_844; (S1*)_t2605->b + hr_ix(_i2605, _t2605->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:90"); }))).a_)), ((int64_t)0LL)))); }
 }
return;
 }
if ((((k_842) == (((int64_t)9LL))) && ((((int64_t)((x_841).op_))) == (((int64_t)52LL))))) { (void)(f177_narrow_push(((int64_t)((x_841).a_))));
(void)(f177_narrow_push(((int64_t)((x_841).b_))));
 }
}
static void f178_narrow_pop(int64_t m_845) {
while ((((g391).n) > (m_845))) { int32_t old_t_846 = ({ hrv *_v2609 = &(g391); if (!_v2609->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:101"); ((int32_t*)_v2609->b)[--_v2609->n]; }); 
int64_t v_847 = ((int64_t)(({ hrv *_v2610 = &(g391); if (!_v2610->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:102"); ((int32_t*)_v2610->b)[--_v2610->n]; }))); 
{ int32_t *_t2611 = &(((*({ hrv *_t2612 = &(g389); int64_t _i2612 = v_847; (S12*)_t2612->b + hr_ix(_i2612, _t2612->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:103"); }))).ty_); *_t2611 = old_t_846; }
 } _bk2608:; 
}
static int64_t f179_deref(int64_t t_851) {
return ({ int64_t _r2613; if ((((((*({ hrv *_t2614 = &(g551); int64_t _i2614 = t_851; (S1*)_t2614->b + hr_ix(_i2614, _t2614->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:67"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2615 = &(g551); int64_t _i2615 = t_851; (S1*)_t2615->b + hr_ix(_i2615, _t2615->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:67"); }))).c_) < (((int32_t)0LL))))) { _r2613 = ((int64_t)(((*({ hrv *_t2616 = &(g551); int64_t _i2616 = t_851; (S1*)_t2616->b + hr_ix(_i2616, _t2616->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:67"); }))).a_));  } else { _r2613 = t_851;  } _r2613; });
}
static int64_t f180_leaf_kind(int64_t t_856) {
S1 x_857 = (*({ hrv *_t2617 = &(g551); int64_t _i2617 = t_856; (S1*)_t2617->b + hr_ix(_i2617, _t2617->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:262"); })); 
int64_t k_858 = ((int64_t)((x_857).k_)); 
if (((k_858) == (((int64_t)3LL)))) { return ((int64_t)1LL);
 }
if (((k_858) == (((int64_t)4LL)))) { return ((int64_t)2LL);
 }
if (((k_858) == (((int64_t)5LL)))) { int64_t r_859 = ((int64_t)0LL); 
{ int32_t _e2619 = ((*({ hrv *_t2620 = &(g554); int64_t _i2620 = (x_857).a_; (S10*)_t2620->b + hr_ix(_i2620, _t2620->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:264"); }))).fnum_; for (int32_t _k2619 = 0; _k2619 < _e2619; _k2619++) { int32_t i_860 = (int32_t)_k2619; S11 f_861 = (*({ hrv *_t2621 = &(g555); int64_t _i2621 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2622 = &(g554); int64_t _i2622 = (x_857).a_; (S10*)_t2622->b + hr_ix(_i2622, _t2622->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:264"); }))).f0_)) + (int64_t)((int64_t)(i_860)))); (S11*)_t2621->b + hr_ix(_i2621, _t2621->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:264"); })); 
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
S1 x_867 = (*({ hrv *_t2625 = &(g551); int64_t _i2625 = t_866; (S1*)_t2625->b + hr_ix(_i2625, _t2625->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:269"); })); 
int64_t k_868 = ((int64_t)((x_867).k_)); 
if ((((k_868) == (((int64_t)3LL))) || ((k_868) == (((int64_t)4LL))))) { return t_866;
 }
if (((k_868) == (((int64_t)5LL)))) { int64_t r_869 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e2627 = ((*({ hrv *_t2628 = &(g554); int64_t _i2628 = (x_867).a_; (S10*)_t2628->b + hr_ix(_i2628, _t2628->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:271"); }))).fnum_; for (int32_t _k2627 = 0; _k2627 < _e2627; _k2627++) { int32_t i_870 = (int32_t)_k2627; S11 f_871 = (*({ hrv *_t2629 = &(g555); int64_t _i2629 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2630 = &(g554); int64_t _i2630 = (x_867).a_; (S10*)_t2630->b + hr_ix(_i2630, _t2630->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:271"); }))).f0_)) + (int64_t)((int64_t)(i_870)))); (S11*)_t2629->b + hr_ix(_i2629, _t2629->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:271"); })); 
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
if ((((ta_878) < (((int64_t)0LL))) || ((tb_879) < (((int64_t)0LL))))) { return g575;
 }
int64_t da_880 = f179_deref(ta_878); 
int64_t db_881 = f179_deref(tb_879); 
int64_t ka_882 = ((int64_t)(((*({ hrv *_t2637 = &(g551); int64_t _i2637 = da_880; (S1*)_t2637->b + hr_ix(_i2637, _t2637->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:238"); }))).k_)); 
int64_t kb_883 = ((int64_t)(((*({ hrv *_t2638 = &(g551); int64_t _i2638 = db_881; (S1*)_t2638->b + hr_ix(_i2638, _t2638->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:238"); }))).k_)); 
if ((((ka_882) == (((int64_t)0LL))) || ((kb_883) == (((int64_t)0LL))))) { return g575;
 }
if ((((ka_882) == (((int64_t)12LL))) && ((kb_883) == (((int64_t)12LL))))) { return g571;
 }
if (((((ka_882) == (((int64_t)12LL))) || ((ka_882) == (((int64_t)13LL)))) && ((kb_883) == (((int64_t)13LL))))) { return g572;
 }
if ((((ka_882) == (((int64_t)13LL))) && ((kb_883) == (((int64_t)12LL))))) { return g572;
 }
if ((((ka_882) == (((int64_t)18LL))) && ((kb_883) == (((int64_t)18LL))))) { (void)(f138_set_t(a_876, g576));
(void)(f138_set_t(b_877, g576));
return g576;
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
if (((kb_883) == (((int64_t)3LL)))) { return g572;
 }
 }
if (((kb_883) == (((int64_t)13LL)))) { if (((ka_882) == (((int64_t)4LL)))) { (void)(f140_conv(b_877, da_880));
return da_880;
 }
if (((ka_882) == (((int64_t)3LL)))) { return g572;
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
if (((((ka_882) == (((int64_t)7LL))) && ((kb_883) == (((int64_t)7LL)))) && ((((*({ hrv *_t2657 = &(g551); int64_t _i2657 = da_880; (S1*)_t2657->b + hr_ix(_i2657, _t2657->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:255"); }))).a_) == (((*({ hrv *_t2658 = &(g551); int64_t _i2658 = db_881; (S1*)_t2658->b + hr_ix(_i2658, _t2658->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:255"); }))).a_)))) { int64_t et_884 = f136_t_enum(((int64_t)(((*({ hrv *_t2660 = &(g551); int64_t _i2660 = da_880; (S1*)_t2660->b + hr_ix(_i2660, _t2660->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:255"); }))).a_)), false); 
(void)(f142_set_cv(a_876, et_884));
(void)(f142_set_cv(b_877, et_884));
return et_884;
 }
if (((((ka_882) == (((int64_t)6LL))) && ((kb_883) == (((int64_t)7LL)))) && ((((*({ hrv *_t2663 = &(g551); int64_t _i2663 = da_880; (S1*)_t2663->b + hr_ix(_i2663, _t2663->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:256"); }))).a_) == (((*({ hrv *_t2664 = &(g551); int64_t _i2664 = db_881; (S1*)_t2664->b + hr_ix(_i2664, _t2664->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:256"); }))).a_)))) { (void)(f142_set_cv(b_877, da_880));
if (((ta_878) != (da_880))) { (void)(f142_set_cv(a_876, da_880));
 }
return da_880;
 }
if (((((kb_883) == (((int64_t)6LL))) && ((ka_882) == (((int64_t)7LL)))) && ((((*({ hrv *_t2667 = &(g551); int64_t _i2667 = da_880; (S1*)_t2667->b + hr_ix(_i2667, _t2667->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:257"); }))).a_) == (((*({ hrv *_t2668 = &(g551); int64_t _i2668 = db_881; (S1*)_t2668->b + hr_ix(_i2668, _t2668->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:257"); }))).a_)))) { (void)(f142_set_cv(a_876, db_881));
if (((tb_879) != (db_881))) { (void)(f142_set_cv(b_877, db_881));
 }
return db_881;
 }
hrv m_885 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2673 __attribute__((cleanup(hr_rdrop))) = {0}; hrv _t2675 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2672 = &(m_885); hr_fs(_o2672, hr_str("operands of types ", 18)); hr_fs(_o2672, hr_sl(*hr_tmp(&_t2673, f161_tn(da_880)))); hr_fs(_o2672, hr_str(" and ", 5)); hr_fs(_o2672, hr_sl(*hr_tmp(&_t2675, f161_tn(db_881)))); hr_fs(_o2672, hr_str(" need a cast to a common type", 29)); }));
}
(void)(f108_cerr(n_875, hr_sl(m_885)));
return g575;
}
static int64_t f183_ck_un(int64_t n_889, int64_t want_890) {
S4 x_891 = (*({ hrv *_t2678 = &(g704); int64_t _i2678 = n_889; (S4*)_t2678->b + hr_ix(_i2678, _t2678->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:327"); })); 
int64_t o_892 = ((int64_t)((x_891).op_)); 
int64_t a_893 = ((int64_t)((x_891).a_)); 
if (((o_892) == (((int64_t)47LL)))) { (void)(f137_ck(a_893, g559));
(void)(f140_conv(a_893, g559));
return f138_set_t(n_889, g559);
 }
if (((o_892) == (((int64_t)49LL)))) { int64_t t_894 = f137_ck(a_893, ({ int64_t _r2683; if ((((want_890) >= (((int64_t)0LL))) && ((((*({ hrv *_t2684 = &(g551); int64_t _i2684 = want_890; (S1*)_t2684->b + hr_ix(_i2684, _t2684->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:330"); }))).k_) == (((uint8_t)10LL))))) { _r2683 = ((int64_t)(((*({ hrv *_t2685 = &(g551); int64_t _i2685 = want_890; (S1*)_t2685->b + hr_ix(_i2685, _t2685->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:330"); }))).a_));  } else { _r2683 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2683; })); 
if (f163_is_pending(t_894)) { (void)(f184_default_t(a_893));
 }
(void)(f175_set_x(n_889, ((int64_t)1LL)));
return f138_set_t(n_889, f141_at(a_893));
 }
int64_t t_913 = f137_ck(a_893, want_890); 
int64_t d_914 = f179_deref(t_913); 
if (((t_913) != (d_914))) { (void)(f142_set_cv(a_893, d_914));
 }
if (((((o_892) == (((int64_t)22LL))) && ((((*({ hrv *_t2694 = &(g551); int64_t _i2694 = d_914; (S1*)_t2694->b + hr_ix(_i2694, _t2694->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:334"); }))).k_) == (((uint8_t)3LL)))) && (!(f153_is_signed(d_914))))) { (void)(f108_cerr(n_889, hr_str("unary - of an unsigned integer", 30)));
 }
return f138_set_t(n_889, d_914);
}
static int64_t f184_default_t(int64_t n_895) {
int64_t t_896 = f141_at(n_895); 
if (((t_896) < (((int64_t)0LL)))) { return g558;
 }
int64_t k_897 = ((int64_t)(((*({ hrv *_t2699 = &(g551); int64_t _i2699 = t_896; (S1*)_t2699->b + hr_ix(_i2699, _t2699->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:216"); }))).k_)); 
if (((k_897) == (((int64_t)12LL)))) { M78 _t2700 = f155_cval(n_895); int64_t v_898 = _t2700.r0; bool u_899 = _t2700.r1; bool ok_900 = _t2700.r2; 
int64_t d_901 = ({ int64_t _r2702; if ((ok_900 && u_899)) { _r2702 = g567;  } else { _r2702 = g563;  } _r2702; }); 
(void)(f162_commit(n_895, d_901));
return d_901;
 }
if (((k_897) == (((int64_t)13LL)))) { (void)(f162_commit(n_895, g569));
return g569;
 }
if (((k_897) == (((int64_t)18LL)))) { (void)(f138_set_t(n_895, g576));
return g576;
 }
if (((k_897) == (((int64_t)19LL)))) { S4 x_902 = (*({ hrv *_t2706 = &(g704); int64_t _i2706 = n_895; (S4*)_t2706->b + hr_ix(_i2706, _t2706->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:221"); })); 
int64_t e_903 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((x_902).a_) >= (((int32_t)0LL)))) { e_903 = f184_default_t(((int64_t)((x_902).a_)));
M78 _t2708 = f155_cval(((int64_t)((x_902).b_))); int64_t cnt_904 = _t2708.r0; bool u0_905 = _t2708.r1; bool ok_906 = _t2708.r2; 
(void)(f140_conv(((int64_t)((x_902).b_)), g563));
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
return g575;
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
S4 x_918 = (*({ hrv *_t2727 = &(g704); int64_t _i2727 = n_916; (S4*)_t2727->b + hr_ix(_i2727, _t2727->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:406"); })); 
int64_t a_919 = ((int64_t)((x_918).a_)); 
int64_t name_920 = ((int64_t)((x_918).s_)); 
if ((((((*({ hrv *_t2728 = &(g704); int64_t _i2728 = a_919; (S4*)_t2728->b + hr_ix(_i2728, _t2728->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:409"); }))).k_) == (((uint8_t)8LL))) && ((f167_find_lv(((int64_t)(((*({ hrv *_t2730 = &(g704); int64_t _i2730 = a_919; (S4*)_t2730->b + hr_ix(_i2730, _t2730->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:409"); }))).s_)))) < (((int64_t)0LL))))) { int64_t ns_921 = f110_ns_of(a_919); 
int64_t de_922 = f116_lookup_q(((int64_t)(((*({ hrv *_t2733 = &(g704); int64_t _i2733 = a_919; (S4*)_t2733->b + hr_ix(_i2733, _t2733->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:411"); }))).s_)), ns_921, ((int64_t)2LL)); 
if ((((de_922) >= (((int64_t)0LL))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t2735 = &(g704); int64_t _i2735 = a_919; (S4*)_t2735->b + hr_ix(_i2735, _t2735->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:412"); }))).s_)), ns_921, ((int64_t)5LL))) < (((int64_t)0LL))))) { int64_t et_926 = f186_rtype_name_enum(de_922); 
int64_t ei_927 = ((int64_t)(((*({ hrv *_t2737 = &(g551); int64_t _i2737 = et_926; (S1*)_t2737->b + hr_ix(_i2737, _t2737->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:414"); }))).a_)); 
{ int32_t _e2739 = ((*({ hrv *_t2740 = &(g556); int64_t _i2740 = ei_927; (S8*)_t2740->b + hr_ix(_i2740, _t2740->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:415"); }))).vnum_; for (int32_t _k2739 = 0; _k2739 < _e2739; _k2739++) { int32_t i_928 = (int32_t)_k2739; if (((((int64_t)(((*({ hrv *_t2741 = &(g557); int64_t _i2741 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2742 = &(g556); int64_t _i2742 = ei_927; (S8*)_t2742->b + hr_ix(_i2742, _t2742->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:415"); }))).v0_)) + (int64_t)((int64_t)(i_928)))); (S9*)_t2741->b + hr_ix(_i2741, _t2741->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:415"); }))).name_))) == (name_920))) { (void)(f170_set_r(n_916, ((int64_t)7LL), ((int64_t)(i_928))));
return f138_set_t(n_916, f125_t_variant(ei_927, ((int64_t)(i_928))));
 }
 } } _bk2738:; 
hrv m_929 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2749 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2747 = &(m_929); hr_fs(_o2747, hr_str("no variant ", 11)); hr_fs(_o2747, f10_nm(name_920)); hr_fs(_o2747, hr_str(" in ", 4)); hr_fs(_o2747, hr_sl(*hr_tmp(&_t2749, f161_tn(et_926)))); }));
}
(void)(f108_cerr(n_916, hr_sl(m_929)));
return f138_set_t(n_916, g575);
 }
 }
int64_t t0_930 = f137_ck(a_919, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t t_931 = t0_930; 
if (((((*({ hrv *_t2754 = &(g551); int64_t _i2754 = t_931; (S1*)_t2754->b + hr_ix(_i2754, _t2754->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:421"); }))).k_) == (((uint8_t)18LL)))) { t_931 = g576;
(void)(f138_set_t(a_919, g576));
 }
if (((((*({ hrv *_t2756 = &(g551); int64_t _i2756 = t_931; (S1*)_t2756->b + hr_ix(_i2756, _t2756->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:422"); }))).k_) == (((uint8_t)19LL)))) { t_931 = f184_default_t(a_919);
 }
int64_t d_932 = f179_deref(t_931); 
int64_t k_933 = ((int64_t)(((*({ hrv *_t2759 = &(g551); int64_t _i2759 = d_932; (S1*)_t2759->b + hr_ix(_i2759, _t2759->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:424"); }))).k_)); 
if (((((k_933) == (((int64_t)8LL))) || ((k_933) == (((int64_t)9LL)))) && hr_streq(f10_nm(name_920), hr_str("len", 3)))) { (void)(f170_set_r(n_916, ((int64_t)8LL), ((int64_t)1LL)));
return f138_set_t(n_916, g563);
 }
if ((((k_933) == (((int64_t)8LL))) && hr_streq(f10_nm(name_920), hr_str("cap", 3)))) { (void)(f170_set_r(n_916, ((int64_t)8LL), ((int64_t)2LL)));
return f138_set_t(n_916, g563);
 }
if (((k_933) == (((int64_t)5LL)))) { int64_t si_934 = ((int64_t)(((*({ hrv *_t2766 = &(g551); int64_t _i2766 = d_932; (S1*)_t2766->b + hr_ix(_i2766, _t2766->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:428"); }))).a_)); 
int64_t fi_938 = f187_sfield(si_934, name_920); 
if (((fi_938) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_916, ((int64_t)5LL), fi_938));
int64_t ft_939 = ((int64_t)(((*({ hrv *_t2769 = &(g555); int64_t _i2769 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2770 = &(g554); int64_t _i2770 = si_934; (S10*)_t2770->b + hr_ix(_i2770, _t2770->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:430"); }))).f0_)) + (int64_t)fi_938)); (S11*)_t2769->b + hr_ix(_i2769, _t2769->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:430"); }))).ty_)); 
return f138_set_t(n_916, f188_decode_rel(ft_939));
 }
 }
if (((k_933) == (((int64_t)7LL)))) { S9 v_941 = (*({ hrv *_t2773 = &(g557); int64_t _i2773 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2774 = &(g556); int64_t _i2774 = ((*({ hrv *_t2775 = &(g551); int64_t _i2775 = d_932; (S1*)_t2775->b + hr_ix(_i2775, _t2775->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:433"); }))).a_; (S8*)_t2774->b + hr_ix(_i2774, _t2774->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:433"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t2776 = &(g551); int64_t _i2776 = d_932; (S1*)_t2776->b + hr_ix(_i2776, _t2776->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:433"); }))).c_)))); (S9*)_t2773->b + hr_ix(_i2773, _t2773->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:433"); })); 
if ((((v_941).si_) >= (((int32_t)0LL)))) { int64_t fi_942 = f187_sfield(((int64_t)((v_941).si_)), name_920); 
if (((fi_942) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_916, ((int64_t)5LL), fi_942));
(void)(f175_set_x(n_916, ((int64_t)((v_941).si_))));
return f138_set_t(n_916, f188_decode_rel(((int64_t)(((*({ hrv *_t2782 = &(g555); int64_t _i2782 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2783 = &(g554); int64_t _i2783 = (v_941).si_; (S10*)_t2783->b + hr_ix(_i2783, _t2783->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:434"); }))).f0_)) + (int64_t)fi_942)); (S11*)_t2782->b + hr_ix(_i2782, _t2782->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:434"); }))).ty_))));
 }
 }
 }
hrv m_943 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2787 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2785 = &(m_943); hr_fs(_o2785, hr_str("no field ", 9)); hr_fs(_o2785, f10_nm(name_920)); hr_fs(_o2785, hr_str(" in ", 4)); hr_fs(_o2785, hr_sl(*hr_tmp(&_t2787, f161_tn(d_932)))); }));
}
(void)(f108_cerr(n_916, hr_sl(m_943)));
return f138_set_t(n_916, g575);
}
static int64_t f186_rtype_name_enum(int64_t de_923) {
int64_t node_924 = ((int64_t)(((*({ hrv *_t2791 = &(g489); int64_t _i2791 = de_923; (S5*)_t2791->b + hr_ix(_i2791, _t2791->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:439"); }))).node_)); 
L84 none_925 = ({ L84 _t2792; memset(&_t2792, 0, sizeof _t2792); _t2792.n = 0; _t2792; }); 
return f136_t_enum(f135_inst_enum(node_924, ({ hsl _t2795 = ({ L84 *_t2796 = &(none_925); (hsl){ (uint8_t*)_t2796->e, _t2796->n }; }); int64_t _l2795 = 0, _h2795 = _t2795.n; if (_l2795 < 0 || _h2795 < _l2795 || _h2795 > _t2795.n) hr_slerr(_l2795, _h2795, _t2795.n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:439"); (hsl){ _t2795.p + _l2795 * (int64_t)sizeof(int32_t), _h2795 - _l2795 }; })), false);
}
static int64_t f187_sfield(int64_t si_935, int64_t name_936) {
{ int32_t _e2798 = ((*({ hrv *_t2799 = &(g554); int64_t _i2799 = si_935; (S10*)_t2799->b + hr_ix(_i2799, _t2799->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:196"); }))).fnum_; for (int32_t _k2798 = 0; _k2798 < _e2798; _k2798++) { int32_t i_937 = (int32_t)_k2798; if (((((int64_t)(((*({ hrv *_t2800 = &(g555); int64_t _i2800 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2801 = &(g554); int64_t _i2801 = si_935; (S10*)_t2801->b + hr_ix(_i2801, _t2801->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:196"); }))).f0_)) + (int64_t)((int64_t)(i_937)))); (S11*)_t2800->b + hr_ix(_i2800, _t2800->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:196"); }))).name_))) == (name_936))) { return ((int64_t)(i_937));
 }
 } } _bk2797:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f188_decode_rel(int64_t ft_940) {
return ({ int64_t _r2802; if ((((((*({ hrv *_t2803 = &(g551); int64_t _i2803 = ft_940; (S1*)_t2803->b + hr_ix(_i2803, _t2803->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:404"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2804 = &(g551); int64_t _i2804 = ft_940; (S1*)_t2804->b + hr_ix(_i2804, _t2804->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:404"); }))).c_) >= (((int32_t)0LL))))) { _r2802 = f119_t_ref(((int64_t)(((*({ hrv *_t2806 = &(g551); int64_t _i2806 = ft_940; (S1*)_t2806->b + hr_ix(_i2806, _t2806->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:404"); }))).a_)), ((int64_t)(((*({ hrv *_t2807 = &(g551); int64_t _i2807 = ft_940; (S1*)_t2807->b + hr_ix(_i2807, _t2807->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:404"); }))).fl_)));  } else { _r2802 = ft_940;  } _r2802; });
}
static int64_t f189_ck_idx(int64_t n_944, int64_t want_945) {
S4 x_946 = (*({ hrv *_t2808 = &(g704); int64_t _i2808 = n_944; (S4*)_t2808->b + hr_ix(_i2808, _t2808->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:441"); })); 
int64_t t_947 = f137_ck(((int64_t)((x_946).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t2810 = &(g551); int64_t _i2810 = t_947; (S1*)_t2810->b + hr_ix(_i2810, _t2810->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:443"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_946).a_)), g576));
t_947 = g576;
 }
if (((((*({ hrv *_t2812 = &(g551); int64_t _i2812 = t_947; (S1*)_t2812->b + hr_ix(_i2812, _t2812->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:444"); }))).k_) == (((uint8_t)19LL)))) { t_947 = f184_default_t(((int64_t)((x_946).a_)));
 }
int64_t d_948 = f179_deref(t_947); 
int64_t ti_949 = f137_ck(((int64_t)((x_946).b_)), g563); 
if (((((*({ hrv *_t2816 = &(g551); int64_t _i2816 = ti_949; (S1*)_t2816->b + hr_ix(_i2816, _t2816->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:447"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_946).b_)), g563));
 } else { int64_t di_950 = f179_deref(ti_949); 
if ((((((*({ hrv *_t2819 = &(g551); int64_t _i2819 = di_950; (S1*)_t2819->b + hr_ix(_i2819, _t2819->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:447"); }))).k_) != (((uint8_t)3LL))) && ((((*({ hrv *_t2820 = &(g551); int64_t _i2820 = di_950; (S1*)_t2820->b + hr_ix(_i2820, _t2820->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:447"); }))).k_) != (((uint8_t)17LL))))) { (void)(f108_cerr(((int64_t)((x_946).b_)), hr_str("index must be an integer", 24)));
 } else { if (((di_950) != (ti_949))) { (void)(f142_set_cv(((int64_t)((x_946).b_)), di_950));
 }
 }
 }
int64_t k_951 = ((int64_t)(((*({ hrv *_t2823 = &(g551); int64_t _i2823 = d_948; (S1*)_t2823->b + hr_ix(_i2823, _t2823->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:448"); }))).k_)); 
if ((((k_951) == (((int64_t)8LL))) || ((k_951) == (((int64_t)9LL))))) { return f138_set_t(n_944, f188_decode_rel(((int64_t)(((*({ hrv *_t2826 = &(g551); int64_t _i2826 = d_948; (S1*)_t2826->b + hr_ix(_i2826, _t2826->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:449"); }))).a_))));
 }
hrv m_952 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2829 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2828 = &(m_952); hr_fs(_o2828, hr_str("cannot index ", 13)); hr_fs(_o2828, hr_sl(*hr_tmp(&_t2829, f161_tn(d_948)))); }));
}
(void)(f108_cerr(n_944, hr_sl(m_952)));
return f138_set_t(n_944, g575);
}
static int64_t f190_ck_slice(int64_t n_953, int64_t want_954) {
S4 x_955 = (*({ hrv *_t2833 = &(g704); int64_t _i2833 = n_953; (S4*)_t2833->b + hr_ix(_i2833, _t2833->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:454"); })); 
int64_t t_956 = f137_ck(((int64_t)((x_955).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t2835 = &(g551); int64_t _i2835 = t_956; (S1*)_t2835->b + hr_ix(_i2835, _t2835->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:456"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_955).a_)), g576));
t_956 = g576;
 }
if (((((*({ hrv *_t2837 = &(g551); int64_t _i2837 = t_956; (S1*)_t2837->b + hr_ix(_i2837, _t2837->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:457"); }))).k_) == (((uint8_t)19LL)))) { t_956 = f184_default_t(((int64_t)((x_955).a_)));
 }
int64_t d_957 = f179_deref(t_956); 
if ((((x_955).b_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_955).b_)), g563));
(void)(f140_conv(((int64_t)((x_955).b_)), g563));
 }
if ((((x_955).c_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_955).c_)), g563));
(void)(f140_conv(((int64_t)((x_955).c_)), g563));
 }
int64_t k_958 = ((int64_t)(((*({ hrv *_t2844 = &(g551); int64_t _i2844 = d_957; (S1*)_t2844->b + hr_ix(_i2844, _t2844->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:461"); }))).k_)); 
if (((k_958) == (((int64_t)8LL)))) { return f138_set_t(n_953, f18_t_slice(((int64_t)(((*({ hrv *_t2847 = &(g551); int64_t _i2847 = d_957; (S1*)_t2847->b + hr_ix(_i2847, _t2847->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:462"); }))).a_)), false));
 }
if (((k_958) == (((int64_t)9LL)))) { return f138_set_t(n_953, d_957);
 }
hrv m_959 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2851 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2850 = &(m_959); hr_fs(_o2850, hr_str("cannot slice ", 13)); hr_fs(_o2850, hr_sl(*hr_tmp(&_t2851, f161_tn(d_957)))); }));
}
(void)(f108_cerr(n_953, hr_sl(m_959)));
return f138_set_t(n_953, g575);
}
static int64_t f191_ck_as(int64_t n_960, int64_t want_961) {
S4 x_962 = (*({ hrv *_t2855 = &(g704); int64_t _i2855 = n_960; (S4*)_t2855->b + hr_ix(_i2855, _t2855->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:468"); })); 
int64_t t_963 = f113_rtype(((int64_t)((x_962).b_)), f110_ns_of(n_960)); 
int64_t f_964 = f137_ck(((int64_t)((x_962).a_)), ({ int64_t _r2859; if ((((((*({ hrv *_t2860 = &(g551); int64_t _i2860 = t_963; (S1*)_t2860->b + hr_ix(_i2860, _t2860->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:470"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2861 = &(g551); int64_t _i2861 = t_963; (S1*)_t2861->b + hr_ix(_i2861, _t2861->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:470"); }))).k_) == (((uint8_t)4LL))))) { _r2859 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2859 = t_963;  } _r2859; })); 
int64_t df_965 = f179_deref(f_964); 
if ((((((*({ hrv *_t2863 = &(g551); int64_t _i2863 = df_965; (S1*)_t2863->b + hr_ix(_i2863, _t2863->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:472"); }))).k_) == (((uint8_t)12LL))) || ((((*({ hrv *_t2864 = &(g551); int64_t _i2864 = df_965; (S1*)_t2864->b + hr_ix(_i2864, _t2864->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:472"); }))).k_) == (((uint8_t)13LL))))) { (void)(f140_conv(((int64_t)((x_962).a_)), ({ int64_t _r2866; if ((((((*({ hrv *_t2867 = &(g551); int64_t _i2867 = t_963; (S1*)_t2867->b + hr_ix(_i2867, _t2867->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:472"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2868 = &(g551); int64_t _i2868 = t_963; (S1*)_t2868->b + hr_ix(_i2868, _t2868->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:472"); }))).k_) == (((uint8_t)4LL))))) { _r2866 = t_963;  } else { _r2866 = g563;  } _r2866; })));
 } else { if (((df_965) != (f_964))) { (void)(f142_set_cv(((int64_t)((x_962).a_)), df_965));
 }
 }
return f138_set_t(n_960, t_963);
}
static int64_t f192_ck_arr(int64_t n_966, int64_t want_967) {
S4 x_968 = (*({ hrv *_t2871 = &(g704); int64_t _i2871 = n_966; (S4*)_t2871->b + hr_ix(_i2871, _t2871->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:704"); })); 
int64_t e_969 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((want_967) >= (((int64_t)0LL))) && (((((*({ hrv *_t2872 = &(g551); int64_t _i2872 = want_967; (S1*)_t2872->b + hr_ix(_i2872, _t2872->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:706"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2873 = &(g551); int64_t _i2873 = want_967; (S1*)_t2873->b + hr_ix(_i2873, _t2873->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:706"); }))).k_) == (((uint8_t)9LL)))))) { e_969 = ((int64_t)(((*({ hrv *_t2874 = &(g551); int64_t _i2874 = want_967; (S1*)_t2874->b + hr_ix(_i2874, _t2874->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:706"); }))).a_));
 }
if ((((x_968).c_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_968).c_)), g563));
(void)(f140_conv(((int64_t)((x_968).c_)), g563));
if (((want_967) >= (((int64_t)0LL)))) { return f138_set_t(n_966, want_967);
 }
return f138_set_t(n_966, g577);
 }
if ((((x_968).a_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_968).a_)), e_969));
(void)(f137_ck(((int64_t)((x_968).b_)), g563));
if (((e_969) >= (((int64_t)0LL)))) { (void)(f140_conv(((int64_t)((x_968).a_)), e_969));
(void)(f140_conv(((int64_t)((x_968).b_)), g563));
if (((((*({ hrv *_t2883 = &(g551); int64_t _i2883 = want_967; (S1*)_t2883->b + hr_ix(_i2883, _t2883->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:708"); }))).k_) == (((uint8_t)9LL)))) { M78 _t2884 = f155_cval(((int64_t)((x_968).b_))); int64_t cnt_970 = _t2884.r0; bool u0_971 = _t2884.r1; bool ok_972 = _t2884.r2; 
(void)(f138_set_t(n_966, f123_t_arr(e_969, ((int64_t)1LL), cnt_970, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f142_set_cv(n_966, want_967));
return want_967;
 }
return f138_set_t(n_966, want_967);
 }
return f138_set_t(n_966, g577);
 }
{ int32_t _e2892 = (x_968).n_; for (int32_t _k2892 = 0; _k2892 < _e2892; _k2892++) { int32_t i_973 = (int32_t)_k2892; (void)(f137_ck(f90_kid(n_966, ((int64_t)(i_973))), e_969));
 } } _bk2891:; 
if (((e_969) >= (((int64_t)0LL)))) { { int32_t _e2896 = (x_968).n_; for (int32_t _k2896 = 0; _k2896 < _e2896; _k2896++) { int32_t i_974 = (int32_t)_k2896; (void)(f140_conv(f90_kid(n_966, ((int64_t)(i_974))), e_969));
 } } _bk2895:; 
if (((((*({ hrv *_t2899 = &(g551); int64_t _i2899 = want_967; (S1*)_t2899->b + hr_ix(_i2899, _t2899->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:712"); }))).k_) == (((uint8_t)9LL)))) { (void)(f138_set_t(n_966, f123_t_arr(e_969, ((int64_t)1LL), f103_max(((int64_t)((x_968).n_)), ((int64_t)1LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f142_set_cv(n_966, want_967));
return want_967;
 }
return f138_set_t(n_966, want_967);
 }
return f138_set_t(n_966, g577);
}
static int64_t f193_ck_block(int64_t n_975, int64_t want_976) {
S4 x_977 = (*({ hrv *_t2906 = &(g704); int64_t _i2906 = n_975; (S4*)_t2906->b + hr_ix(_i2906, _t2906->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:477"); })); 
int64_t m_978 = (g390).n; 
int64_t nm0_979 = (g391).n; 
int64_t nf0_1013 = f194_pre_decl_block_fns(n_975); 
{ int32_t _e2909 = (x_977).n_; for (int32_t _k2909 = 0; _k2909 < _e2909; _k2909++) { int32_t i_1014 = (int32_t)_k2909; (void)(f200_cstmt(f90_kid(n_975, ((int64_t)(i_1014)))));
 } } _bk2908:; 
int64_t t_1103 = g558; 
if ((((x_977).a_) >= (((int32_t)0LL)))) { t_1103 = f137_ck(((int64_t)((x_977).a_)), want_976);
 }
(void)(f211_pop_block_fns(nf0_1013));
(void)(f178_narrow_pop(nm0_979));
(void)(({ hrv *_v2915 = &(g390); int64_t _k2915 = ((int64_t)((int64_t)(g390).n - (int64_t)m_978)); if (_k2915 < 0 || _k2915 > _v2915->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:486"); _v2915->n -= _k2915; }));
return f138_set_t(n_975, t_1103);
}
static int64_t f194_pre_decl_block_fns(int64_t b_980) {
int64_t m_981 = (g312).n; 
{ int32_t _e2918 = ((*({ hrv *_t2919 = &(g704); int64_t _i2919 = b_980; (S4*)_t2919->b + hr_ix(_i2919, _t2919->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); }))).n_; for (int32_t _k2918 = 0; _k2918 < _e2918; _k2918++) { int32_t q_982 = (int32_t)_k2918; int64_t c_983 = f90_kid(b_980, ((int64_t)(q_982))); 
if (((((int64_t)(((*({ hrv *_t2921 = &(g704); int64_t _i2921 = c_983; (S4*)_t2921->b + hr_ix(_i2921, _t2921->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); }))).k_))) == (((int64_t)50LL)))) { int64_t i_984 = f105_new_inst(c_983, c_983, ((int64_t)((*({ hrv *_t2923 = &(g719); int64_t _i2923 = c_983; (int32_t*)_t2923->b + hr_ix(_i2923, _t2923->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); })))), g401); 
(void)(({ hrv *_v2924 = &(g312); S14 _x2924 = ((S14){ .name_ = ((*({ hrv *_t2925 = &(g704); int64_t _i2925 = c_983; (S4*)_t2925->b + hr_ix(_i2925, _t2925->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); }))).s_, .node_ = ((int32_t)(c_983)), .inst_ = ((int32_t)(i_984)), .own_ = ((int32_t)(g401)), }); S14 *_p2924 = (S14*)hr_grow(_v2924, 1, sizeof _x2924); *_p2924 = _x2924; _p2924; }));
(void)(f195_sig_inst(i_984));
 }
 } } _bk2917:; 
return m_981;
}
static void f195_sig_inst(int64_t i_985) {
int64_t node_986 = ((int64_t)(((*({ hrv *_t2927 = &(g388); int64_t _i2927 = i_985; (S6*)_t2927->b + hr_ix(_i2927, _t2927->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:106"); }))).node_)); 
int64_t ns_987 = f110_ns_of(node_986); 
int64_t g0_988 = (g491).n; 
{ int32_t _e2930 = ((*({ hrv *_t2931 = &(g388); int64_t _i2931 = i_985; (S6*)_t2931->b + hr_ix(_i2931, _t2931->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:109"); }))).gn_; for (int32_t _k2930 = 0; _k2930 < _e2930; _k2930++) { int32_t j_989 = (int32_t)_k2930; (void)(({ hrv *_v2932 = &(g491); S7 _x2932 = (*({ hrv *_t2933 = &(g394); int64_t _i2933 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2934 = &(g388); int64_t _i2934 = i_985; (S6*)_t2934->b + hr_ix(_i2934, _t2934->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:109"); }))).g0_)) + (int64_t)((int64_t)(j_989)))); (S7*)_t2933->b + hr_ix(_i2933, _t2933->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:109"); })); S7 *_p2932 = (S7*)hr_grow(_v2932, 1, sizeof _x2932); *_p2932 = _x2932; _p2932; }));
 } } _bk2929:; 
int64_t p0_990 = (g552).n; 
L88 pts_991 = ({ L88 _t2935; memset(&_t2935, 0, sizeof _t2935); _t2935.n = 0; _t2935; }); 
{ int32_t _e2937 = ((*({ hrv *_t2938 = &(g704); int64_t _i2938 = node_986; (S4*)_t2938->b + hr_ix(_i2938, _t2938->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:112"); }))).n_; for (int32_t _k2937 = 0; _k2937 < _e2937; _k2937++) { int32_t j_992 = (int32_t)_k2937; int64_t p_993 = f90_kid(node_986, ((int64_t)(j_992))); 
int64_t t_994 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((*({ hrv *_t2940 = &(g704); int64_t _i2940 = p_993; (S4*)_t2940->b + hr_ix(_i2940, _t2940->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:115"); }))).a_) >= (((int32_t)0LL)))) { t_994 = f113_rtype(((int64_t)(((*({ hrv *_t2942 = &(g704); int64_t _i2942 = p_993; (S4*)_t2942->b + hr_ix(_i2942, _t2942->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:115"); }))).a_)), ns_987);
 } else { t_994 = f130_gb_find(f196_upname(p_993));
if (((t_994) < (((int64_t)0LL)))) { t_994 = g575;
 }
 }
(void)(({ L88 *_v2945 = &(pts_991); int32_t _x2945 = ((int32_t)(t_994)); if (_v2945->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:116"); _v2945->e[_v2945->n] = _x2945; &_v2945->e[_v2945->n++]; }));
 } } _bk2936:; 
{ int32_t *_t2946 = &(((*({ hrv *_t2947 = &(g388); int64_t _i2947 = i_985; (S6*)_t2947->b + hr_ix(_i2947, _t2947->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:118"); }))).p0_); *_t2946 = ((int32_t)((g552).n)); }
(void)(({ hrv *_v2948 = &(g552); hsl _s2948 = ({ hsl _t2949 = ({ L88 *_t2950 = &(pts_991); (hsl){ (uint8_t*)_t2950->e, _t2950->n }; }); int64_t _l2949 = 0, _h2949 = _t2949.n; if (_l2949 < 0 || _h2949 < _l2949 || _h2949 > _t2949.n) hr_slerr(_l2949, _h2949, _t2949.n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:118"); (hsl){ _t2949.p + _l2949 * (int64_t)sizeof(int32_t), _h2949 - _l2949 }; }); hr_append(_v2948, _s2948.p, _s2948.n, sizeof(int32_t)); }));
{ int32_t *_t2951 = &(((*({ hrv *_t2952 = &(g388); int64_t _i2952 = i_985; (S6*)_t2952->b + hr_ix(_i2952, _t2952->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:118"); }))).pn_); *_t2951 = ((int32_t)(((int64_t)(pts_991).n))); }
if (((((*({ hrv *_t2953 = &(g704); int64_t _i2953 = node_986; (S4*)_t2953->b + hr_ix(_i2953, _t2953->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:119"); }))).b_) >= (((int32_t)0LL)))) { int64_t rl_997 = ((int64_t)(((*({ hrv *_t2954 = &(g704); int64_t _i2954 = node_986; (S4*)_t2954->b + hr_ix(_i2954, _t2954->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:120"); }))).b_)); 
if (((((*({ hrv *_t2955 = &(g704); int64_t _i2955 = rl_997; (S4*)_t2955->b + hr_ix(_i2955, _t2955->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:121"); }))).n_) == (((int32_t)1LL)))) { { int32_t *_t2956 = &(((*({ hrv *_t2957 = &(g388); int64_t _i2957 = i_985; (S6*)_t2957->b + hr_ix(_i2957, _t2957->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:121"); }))).ret_); *_t2956 = ((int32_t)(f113_rtype(f90_kid(rl_997, ((int64_t)0LL)), ns_987))); }
 } else { L89 rs_998 = ({ L89 _t2960; memset(&_t2960, 0, sizeof _t2960); _t2960.n = 0; _t2960; }); 
{ int32_t _e2962 = ((*({ hrv *_t2963 = &(g704); int64_t _i2963 = rl_997; (S4*)_t2963->b + hr_ix(_i2963, _t2963->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); }))).n_; for (int32_t _k2962 = 0; _k2962 < _e2962; _k2962++) { int32_t j_999 = (int32_t)_k2962; int64_t r0_1000 = f113_rtype(f90_kid(rl_997, ((int64_t)(j_999))), ns_987); 
(void)(({ L89 *_v2966 = &(rs_998); int32_t _x2966 = ((int32_t)(r0_1000)); if (_v2966->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); _v2966->e[_v2966->n] = _x2966; &_v2966->e[_v2966->n++]; }));
 } } _bk2961:; 
{ int32_t *_t2967 = &(((*({ hrv *_t2968 = &(g388); int64_t _i2968 = i_985; (S6*)_t2968->b + hr_ix(_i2968, _t2968->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); }))).ret_); *_t2967 = ((int32_t)(f197_tlist(((int64_t)14LL), ({ hsl _t2970 = ({ L89 *_t2971 = &(rs_998); (hsl){ (uint8_t*)_t2971->e, _t2971->n }; }); int64_t _l2970 = 0, _h2970 = _t2970.n; if (_l2970 < 0 || _h2970 < _l2970 || _h2970 > _t2970.n) hr_slerr(_l2970, _h2970, _t2970.n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); (hsl){ _t2970.p + _l2970 * (int64_t)sizeof(int32_t), _h2970 - _l2970 }; }), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); }
 }
 } else { { int32_t *_t2972 = &(((*({ hrv *_t2973 = &(g388); int64_t _i2973 = i_985; (S6*)_t2973->b + hr_ix(_i2973, _t2973->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).ret_); *_t2972 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
{ bool *_t2974 = &(((*({ hrv *_t2975 = &(g388); int64_t _i2975 = i_985; (S6*)_t2975->b + hr_ix(_i2975, _t2975->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).rinf_); *_t2974 = true; }
if ((((((uint16_t)((uint64_t)((*({ hrv *_t2976 = &(g704); int64_t _i2976 = node_986; (S4*)_t2976->b + hr_ix(_i2976, _t2976->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || f198_surely_void(node_986))) { { int32_t *_t2978 = &(((*({ hrv *_t2979 = &(g388); int64_t _i2979 = i_985; (S6*)_t2979->b + hr_ix(_i2979, _t2979->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).ret_); *_t2978 = ((int32_t)(g558)); }
{ bool *_t2980 = &(((*({ hrv *_t2981 = &(g388); int64_t _i2981 = i_985; (S6*)_t2981->b + hr_ix(_i2981, _t2981->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).rinf_); *_t2980 = false; }
 }
 }
(void)(({ hrv *_v2982 = &(g491); int64_t _k2982 = ((int64_t)((int64_t)(g491).n - (int64_t)g0_988)); if (_k2982 < 0 || _k2982 > _v2982->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:124"); _v2982->n -= _k2982; }));
}
static int64_t f196_upname(int64_t p_995) {
hrv s_996 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v2984 = &(s_996); uint8_t _x2984 = ((uint8_t)36LL); uint8_t *_p2984 = (uint8_t*)hr_grow(_v2984, 1, sizeof _x2984); *_p2984 = _x2984; _p2984; }));
(void)(({ hrv *_v2985 = &(s_996); hsl _s2985 = f10_nm(((int64_t)(((*({ hrv *_t2987 = &(g704); int64_t _i2987 = p_995; (S4*)_t2987->b + hr_ix(_i2987, _t2987->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:60"); }))).s_))); hr_append(_v2985, _s2985.p, _s2985.n, sizeof(uint8_t)); }));
return f8_intern(hr_sl(s_996));
}
static int64_t f197_tlist(int64_t k_1001, hsl xs_1002, int64_t a_1003) {
int64_t l_1004 = (g552).n; 
(void)(({ hrv *_v2989 = &(g552); hsl _s2989 = xs_1002; hr_append(_v2989, _s2989.p, _s2989.n, sizeof(int32_t)); }));
return f13_tmk(((S1){ .k_ = ((uint8_t)(k_1001)), .a_ = ((int32_t)(a_1003)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .l_ = ((int32_t)(l_1004)), .n_ = ((int32_t)((xs_1002).n)), }));
}
static bool f198_surely_void(int64_t fnode_1005) {
int64_t body_1006 = ((int64_t)(((*({ hrv *_t2991 = &(g704); int64_t _i2991 = fnode_1005; (S4*)_t2991->b + hr_ix(_i2991, _t2991->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:127"); }))).c_)); 
if (((body_1006) < (((int64_t)0LL)))) { return true;
 }
int64_t tl_1007 = ((int64_t)(((*({ hrv *_t2992 = &(g704); int64_t _i2992 = body_1006; (S4*)_t2992->b + hr_ix(_i2992, _t2992->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:129"); }))).a_)); 
if (((tl_1007) >= (((int64_t)0LL)))) { int64_t k_1008 = ((int64_t)(((*({ hrv *_t2993 = &(g704); int64_t _i2993 = tl_1007; (S4*)_t2993->b + hr_ix(_i2993, _t2993->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:130"); }))).k_)); 
if ((!((((((((k_1008) == (((int64_t)25LL))) || ((k_1008) == (((int64_t)27LL)))) || ((k_1008) == (((int64_t)28LL)))) || ((k_1008) == (((int64_t)29LL)))) || ((k_1008) == (((int64_t)30LL)))) || (((k_1008) == (((int64_t)19LL))) && ((((*({ hrv *_t2994 = &(g704); int64_t _i2994 = tl_1007; (S4*)_t2994->b + hr_ix(_i2994, _t2994->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:130"); }))).c_) < (((int32_t)0LL)))))))) { return false;
 }
 }
return (!(f199_has_valret(body_1006)));
}
static bool f199_has_valret(int64_t n_1009) {
if (((n_1009) < (((int64_t)0LL)))) { return false;
 }
S4 x_1010 = (*({ hrv *_t2996 = &(g704); int64_t _i2996 = n_1009; (S4*)_t2996->b + hr_ix(_i2996, _t2996->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:135"); })); 
int64_t k_1011 = ((int64_t)((x_1010).k_)); 
if (((k_1011) == (((int64_t)28LL)))) { return ((((x_1010).n_) > (((int32_t)0LL))) && (((x_1010).s_) < (((int32_t)0LL))));
 }
if ((((k_1011) == (((int64_t)50LL))) || ((k_1011) == (((int64_t)37LL))))) { return (((k_1011) == (((int64_t)37LL))) && f199_has_valret(((int64_t)((x_1010).c_))));
 }
if ((((((k_1011) == (((int64_t)1LL))) || ((k_1011) == (((int64_t)2LL)))) || ((k_1011) == (((int64_t)3LL)))) || ((k_1011) == (((int64_t)8LL))))) { return false;
 }
if ((((k_1011) >= (((int64_t)40LL))) && ((k_1011) < (((int64_t)50LL))))) { return false;
 }
if ((((f199_has_valret(((int64_t)((x_1010).a_))) || f199_has_valret(((int64_t)((x_1010).b_)))) || f199_has_valret(((int64_t)((x_1010).c_)))) || f199_has_valret(((int64_t)((x_1010).d_))))) { return true;
 }
if ((((((((((k_1011) == (((int64_t)23LL))) || ((k_1011) == (((int64_t)11LL)))) || ((k_1011) == (((int64_t)20LL)))) || ((k_1011) == (((int64_t)21LL)))) || ((k_1011) == (((int64_t)36LL)))) || ((k_1011) == (((int64_t)16LL)))) || ((k_1011) == (((int64_t)17LL)))) || ((k_1011) == (((int64_t)28LL))))) { { int32_t _e3003 = (x_1010).n_; for (int32_t _k3003 = 0; _k3003 < _e3003; _k3003++) { int32_t i_1012 = (int32_t)_k3003; if (f199_has_valret(f90_kid(n_1009, ((int64_t)(i_1012))))) { return true;
 }
 } } _bk3002:; 
 }
return false;
}
static void f200_cstmt(int64_t n_1015) {
S4 x_1016 = (*({ hrv *_t3006 = &(g704); int64_t _i3006 = n_1015; (S4*)_t3006->b + hr_ix(_i3006, _t3006->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:718"); })); 
int64_t k_1017 = ((int64_t)((x_1016).k_)); 
if (((k_1017) == (((int64_t)33LL)))) { (void)(f201_ck_vdecl(n_1015));
return;
 }
if (((k_1017) == (((int64_t)34LL)))) { (void)(f205_ck_assign(n_1015));
return;
 }
if (((k_1017) == (((int64_t)35LL)))) { int64_t t_1062 = f137_ck(((int64_t)((x_1016).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if ((((((*({ hrv *_t3010 = &(g551); int64_t _i3010 = f179_deref(t_1062); (S1*)_t3010->b + hr_ix(_i3010, _t3010->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:722"); }))).k_) != (((uint8_t)3LL))) && ((((*({ hrv *_t3012 = &(g551); int64_t _i3012 = f179_deref(t_1062); (S1*)_t3012->b + hr_ix(_i3012, _t3012->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:722"); }))).k_) != (((uint8_t)17LL))))) { (void)(f108_cerr(n_1015, hr_str("++/-- needs an integer", 22)));
 }
return;
 }
if (((k_1017) == (((int64_t)50LL)))) { (void)(f206_decl_nested(n_1015));
return;
 }
int64_t t_1102 = f137_ck(n_1015, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f163_is_pending(t_1102)) { (void)(f184_default_t(n_1015));
 }
}
static void f201_ck_vdecl(int64_t n_1018) {
S4 x_1019 = (*({ hrv *_t3019 = &(g704); int64_t _i3019 = n_1018; (S4*)_t3019->b + hr_ix(_i3019, _t3019->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:729"); })); 
int64_t fl_1020 = ((int64_t)((x_1019).fl_)); 
int64_t ns_1021 = f110_ns_of(n_1018); 
bool byref_1022 = ((((int64_t)((int64_t)fl_1020 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL))); 
int64_t dt_1023 = ({ int64_t _r3021; if ((((x_1019).a_) >= (((int32_t)0LL)))) { _r3021 = f113_rtype(((int64_t)((x_1019).a_)), ns_1021);  } else { _r3021 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3021; }); 
int64_t lf_1024 = ((int64_t)((int64_t)((int64_t)((int64_t)({ int64_t _r3023; if (((((int64_t)((int64_t)fl_1020 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)))) { _r3023 = ((int64_t)1LL);  } else { _r3023 = ((int64_t)0LL);  } _r3023; }) | (int64_t)({ int64_t _r3024; if (((((int64_t)((int64_t)fl_1020 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { _r3024 = ((int64_t)2LL);  } else { _r3024 = ((int64_t)0LL);  } _r3024; }))) | (int64_t)({ int64_t _r3025; if (byref_1022) { _r3025 = ((int64_t)8LL);  } else { _r3025 = ((int64_t)0LL);  } _r3025; }))); 
if ((((x_1019).n_) > (((int32_t)1LL)))) { if ((((x_1019).b_) < (((int32_t)0LL)))) { (void)(f108_cerr(n_1018, hr_str("several names need a call's results", 35)));
return;
 }
int64_t init_1025 = f90_kid(((int64_t)((x_1019).b_)), ((int64_t)0LL)); 
int64_t t_1026 = f137_ck(init_1025, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3029 = &(g551); int64_t _i3029 = t_1026; (S1*)_t3029->b + hr_ix(_i3029, _t3029->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:739"); }))).k_) != (((uint8_t)14LL)))) { if (((((int64_t)(((*({ hrv *_t3030 = &(g704); int64_t _i3030 = (x_1019).b_; (S4*)_t3030->b + hr_ix(_i3030, _t3030->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:739"); }))).n_))) == (((int64_t)((x_1019).n_))))) { { int32_t _e3032 = (x_1019).n_; for (int32_t _k3032 = ((int32_t)1LL); _k3032 < _e3032; _k3032++) { int32_t i_1027 = (int32_t)_k3032; int64_t iv_1028 = f90_kid(((int64_t)((x_1019).b_)), ((int64_t)(i_1027))); 
(void)(f137_ck(iv_1028, dt_1023));
if (((dt_1023) >= (((int64_t)0LL)))) { (void)(f140_conv(iv_1028, dt_1023));
 } else { (void)(f184_default_t(iv_1028));
 }
 } } _bk3031:; 
if (((dt_1023) >= (((int64_t)0LL)))) { (void)(f140_conv(init_1025, dt_1023));
 } else { (void)(f184_default_t(init_1025));
 }
{ int32_t _e3040 = (x_1019).n_; for (int32_t _k3040 = 0; _k3040 < _e3040; _k3040++) { int32_t i_1029 = (int32_t)_k3040; int64_t iv_1030 = f90_kid(((int64_t)((x_1019).b_)), ((int64_t)(i_1029))); 
int64_t v_1037 = f203_add_lv(((int64_t)((*({ hrv *_t3043 = &(g705); int64_t _i3043 = ((int64_t)((int64_t)((int64_t)((x_1019).l_)) + (int64_t)((int64_t)(i_1029)))); (int32_t*)_t3043->b + hr_ix(_i3043, _t3043->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:739"); })))), ({ int64_t _r3044; if (((dt_1023) >= (((int64_t)0LL)))) { _r3044 = dt_1023;  } else { _r3044 = f202_fin_t(iv_1030);  } _r3044; }), lf_1024, n_1018); 
if (((i_1029) == (((int32_t)0LL)))) { (void)(f170_set_r(n_1018, ((int64_t)1LL), v_1037));
 }
 } } _bk3039:; 
(void)(f175_set_x(n_1018, ((int64_t)1LL)));
return;
 }
(void)(f108_cerr(n_1018, hr_str("several names need a call with as many results", 46)));
return;
 }
if (((((*({ hrv *_t3049 = &(g551); int64_t _i3049 = t_1026; (S1*)_t3049->b + hr_ix(_i3049, _t3049->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:740"); }))).n_) != ((x_1019).n_))) { (void)(f108_cerr(n_1018, hr_str("result count does not match the names", 37)));
 }
{ int32_t _e3052 = (x_1019).n_; for (int32_t _k3052 = 0; _k3052 < _e3052; _k3052++) { int32_t i_1038 = (int32_t)_k3052; int64_t et_1039 = ({ int64_t _r3053; if (((((int64_t)(i_1038))) < (((int64_t)(((*({ hrv *_t3054 = &(g551); int64_t _i3054 = t_1026; (S1*)_t3054->b + hr_ix(_i3054, _t3054->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:741"); }))).n_))))) { _r3053 = ((int64_t)((*({ hrv *_t3055 = &(g552); int64_t _i3055 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3056 = &(g551); int64_t _i3056 = t_1026; (S1*)_t3056->b + hr_ix(_i3056, _t3056->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:741"); }))).l_)) + (int64_t)((int64_t)(i_1038)))); (int32_t*)_t3055->b + hr_ix(_i3055, _t3055->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:741"); }))));  } else { _r3053 = g575;  } _r3053; }); 
int64_t v_1040 = f203_add_lv(((int64_t)((*({ hrv *_t3058 = &(g705); int64_t _i3058 = ((int64_t)((int64_t)((int64_t)((x_1019).l_)) + (int64_t)((int64_t)(i_1038)))); (int32_t*)_t3058->b + hr_ix(_i3058, _t3058->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:741"); })))), et_1039, lf_1024, n_1018); 
if (((i_1038) == (((int32_t)0LL)))) { (void)(f170_set_r(n_1018, ((int64_t)1LL), v_1040));
 }
 } } _bk3051:; 
return;
 }
int64_t t_1041 = dt_1023; 
if ((((x_1019).b_) >= (((int32_t)0LL)))) { int64_t init_1042 = f90_kid(((int64_t)((x_1019).b_)), ((int64_t)0LL)); 
if (((((((dt_1023) < (((int64_t)0LL))) && ((((*({ hrv *_t3061 = &(g704); int64_t _i3061 = init_1042; (S4*)_t3061->b + hr_ix(_i3061, _t3061->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:747"); }))).k_) == (((uint8_t)16LL)))) && ((((*({ hrv *_t3062 = &(g704); int64_t _i3062 = init_1042; (S4*)_t3062->b + hr_ix(_i3062, _t3062->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:747"); }))).n_) == (((int32_t)0LL)))) && ((((*({ hrv *_t3063 = &(g704); int64_t _i3063 = init_1042; (S4*)_t3063->b + hr_ix(_i3063, _t3063->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:747"); }))).a_) < (((int32_t)0LL)))) && ((((*({ hrv *_t3064 = &(g704); int64_t _i3064 = init_1042; (S4*)_t3064->b + hr_ix(_i3064, _t3064->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:747"); }))).c_) < (((int32_t)0LL))))) { t_1041 = f123_t_arr(g575, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
(void)(f138_set_t(init_1042, t_1041));
 } else { int64_t it_1043 = f137_ck(init_1042, dt_1023); 
if (((dt_1023) >= (((int64_t)0LL)))) { if (byref_1022) { if ((!(((((*({ hrv *_t3068 = &(g551); int64_t _i3068 = dt_1023; (S1*)_t3068->b + hr_ix(_i3068, _t3068->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:752"); }))).k_) == (((uint8_t)10LL)))))) { (void)(f140_conv(init_1042, dt_1023));
 }
 } else { (void)(f140_conv(init_1042, dt_1023));
 }
 } else { t_1041 = f184_default_t(init_1042);
if (((((*({ hrv *_t3072 = &(g551); int64_t _i3072 = t_1041; (S1*)_t3072->b + hr_ix(_i3072, _t3072->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:755"); }))).k_) == (((uint8_t)14LL)))) { t_1041 = ((int64_t)((*({ hrv *_t3073 = &(g552); int64_t _i3073 = ((*({ hrv *_t3074 = &(g551); int64_t _i3074 = t_1041; (S1*)_t3074->b + hr_ix(_i3074, _t3074->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:755"); }))).l_; (int32_t*)_t3073->b + hr_ix(_i3073, _t3073->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:755"); }))));
 }
if (((((((*({ hrv *_t3075 = &(g551); int64_t _i3075 = t_1041; (S1*)_t3075->b + hr_ix(_i3075, _t3075->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:756"); }))).k_) == (((uint8_t)7LL))) && (((((*({ hrv *_t3076 = &(g704); int64_t _i3076 = init_1042; (S4*)_t3076->b + hr_ix(_i3076, _t3076->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:756"); }))).k_) == (((uint8_t)14LL))) || ((((*({ hrv *_t3077 = &(g704); int64_t _i3077 = init_1042; (S4*)_t3077->b + hr_ix(_i3077, _t3077->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:756"); }))).k_) == (((uint8_t)17LL))))) && ((((int64_t)((int64_t)lf_1024 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL))))) { t_1041 = f136_t_enum(((int64_t)(((*({ hrv *_t3079 = &(g551); int64_t _i3079 = t_1041; (S1*)_t3079->b + hr_ix(_i3079, _t3079->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:756"); }))).a_)), false);
(void)(f142_set_cv(init_1042, t_1041));
 }
if ((byref_1022 || (((((*({ hrv *_t3081 = &(g704); int64_t _i3081 = init_1042; (S4*)_t3081->b + hr_ix(_i3081, _t3081->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:757"); }))).k_) == (((uint8_t)10LL))) && ((((int64_t)(((*({ hrv *_t3082 = &(g704); int64_t _i3082 = init_1042; (S4*)_t3082->b + hr_ix(_i3082, _t3082->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:757"); }))).op_))) == (((int64_t)49LL)))))) { if (((((*({ hrv *_t3083 = &(g551); int64_t _i3083 = t_1041; (S1*)_t3083->b + hr_ix(_i3083, _t3083->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:757"); }))).k_) != (((uint8_t)10LL)))) { t_1041 = f119_t_ref(t_1041, ((int64_t)0LL));
 }
 } else { if ((((((((*({ hrv *_t3085 = &(g551); int64_t _i3085 = t_1041; (S1*)_t3085->b + hr_ix(_i3085, _t3085->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:758"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t3086 = &(g551); int64_t _i3086 = t_1041; (S1*)_t3086->b + hr_ix(_i3086, _t3086->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:758"); }))).c_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t3087 = &(g551); int64_t _i3087 = t_1041; (S1*)_t3087->b + hr_ix(_i3087, _t3087->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:758"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))) && f204_is_fixed(((int64_t)(((*({ hrv *_t3089 = &(g551); int64_t _i3089 = t_1041; (S1*)_t3089->b + hr_ix(_i3089, _t3089->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:758"); }))).a_))))) { t_1041 = ((int64_t)(((*({ hrv *_t3090 = &(g551); int64_t _i3090 = t_1041; (S1*)_t3090->b + hr_ix(_i3090, _t3090->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:758"); }))).a_));
(void)(f142_set_cv(init_1042, t_1041));
 }
 }
 }
 }
 } else { if (((t_1041) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1018, hr_str("a declaration needs a type or an initializer", 44)));
t_1041 = g575;
 }
 }
if ((byref_1022 && ((((*({ hrv *_t3093 = &(g551); int64_t _i3093 = t_1041; (S1*)_t3093->b + hr_ix(_i3093, _t3093->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:764"); }))).k_) != (((uint8_t)10LL))))) { t_1041 = f119_t_ref(t_1041, ((int64_t)0LL));
 }
int64_t v_1045 = f203_add_lv(((int64_t)((*({ hrv *_t3096 = &(g705); int64_t _i3096 = (x_1019).l_; (int32_t*)_t3096->b + hr_ix(_i3096, _t3096->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:765"); })))), t_1041, lf_1024, n_1018); 
(void)(f170_set_r(n_1018, ((int64_t)1LL), v_1045));
}
static int64_t f202_fin_t(int64_t n_1031) {
int64_t c_1032 = f150_cv(n_1031); 
return ({ int64_t _r3099; if (((c_1032) >= (((int64_t)0LL)))) { _r3099 = c_1032;  } else { _r3099 = f141_at(n_1031);  } _r3099; });
}
static int64_t f203_add_lv(int64_t name_1033, int64_t t_1034, int64_t fl_1035, int64_t node_1036) {
(void)(({ hrv *_v3101 = &(g389); S12 _x3101 = ((S12){ .name_ = ((int32_t)(name_1033)), .ty_ = ((int32_t)(t_1034)), .fl_ = ((uint16_t)(fl_1035)), .cfn_ = ((int32_t)(g402)), .own_ = ((int32_t)(g401)), .node_ = ((int32_t)(node_1036)), .cnt_ = ((int32_t)0LL), }); S12 *_p3101 = (S12*)hr_grow(_v3101, 1, sizeof _x3101); *_p3101 = _x3101; _p3101; }));
(void)(({ hrv *_v3102 = &(g390); int32_t _x3102 = ((int32_t)(((int64_t)((int64_t)(g389).n - (int64_t)((int64_t)1LL))))); int32_t *_p3102 = (int32_t*)hr_grow(_v3102, 1, sizeof _x3102); *_p3102 = _x3102; _p3102; }));
return ((int64_t)((int64_t)(g389).n - (int64_t)((int64_t)1LL)));
}
static bool f204_is_fixed(int64_t t_1044) {
return ((f143_tclass(t_1044)) == (((int64_t)0LL)));
}
static void f205_ck_assign(int64_t n_1046) {
S4 x_1047 = (*({ hrv *_t3104 = &(g704); int64_t _i3104 = n_1046; (S4*)_t3104->b + hr_ix(_i3104, _t3104->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:769"); })); 
int64_t o_1048 = ((int64_t)((x_1047).op_)); 
if (((o_1048) == (((int64_t)11LL)))) { int64_t t_1049 = f137_ck(((int64_t)((x_1047).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t tl_1050 = ((int64_t)((x_1047).a_)); 
{ int32_t _e3107 = ((*({ hrv *_t3108 = &(g704); int64_t _i3108 = tl_1050; (S4*)_t3108->b + hr_ix(_i3108, _t3108->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:774"); }))).n_; for (int32_t _k3107 = 0; _k3107 < _e3107; _k3107++) { int32_t i_1051 = (int32_t)_k3107; int64_t tg_1052 = f90_kid(tl_1050, ((int64_t)(i_1051))); 
int64_t tt_1053 = f137_ck(tg_1052, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
 } } _bk3106:; 
return;
 }
if (((o_1048) == (((int64_t)18LL)))) { int64_t tt_1054 = f137_ck(((int64_t)((x_1047).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t rt_1055 = f137_ck(((int64_t)((x_1047).b_)), tt_1054); 
if (f163_is_pending(rt_1055)) { if ((((((*({ hrv *_t3114 = &(g551); int64_t _i3114 = rt_1055; (S1*)_t3114->b + hr_ix(_i3114, _t3114->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:781"); }))).k_) == (((uint8_t)11LL))) && ((((*({ hrv *_t3115 = &(g551); int64_t _i3115 = tt_1054; (S1*)_t3115->b + hr_ix(_i3115, _t3115->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:781"); }))).k_) == (((uint8_t)10LL))))) { (void)(f138_set_t(((int64_t)((x_1047).b_)), f119_t_ref(((int64_t)(((*({ hrv *_t3118 = &(g551); int64_t _i3118 = tt_1054; (S1*)_t3118->b + hr_ix(_i3118, _t3118->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:781"); }))).a_)), ((int64_t)2LL))));
 } else { (void)(f184_default_t(((int64_t)((x_1047).b_))));
 }
 }
if ((((((*({ hrv *_t3120 = &(g704); int64_t _i3120 = (x_1047).a_; (S4*)_t3120->b + hr_ix(_i3120, _t3120->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:784"); }))).k_) == (((uint8_t)8LL))) && ((f156_rk(((int64_t)((x_1047).a_)))) == (((int64_t)1LL))))) { int64_t v_1056 = f157_rv(((int64_t)((x_1047).a_))); 
if ((f165_is_opt(f141_at(((int64_t)((x_1047).b_)))) || ((((*({ hrv *_t3125 = &(g551); int64_t _i3125 = f141_at(((int64_t)((x_1047).b_))); (S1*)_t3125->b + hr_ix(_i3125, _t3125->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:786"); }))).k_) == (((uint8_t)11LL))))) { { int32_t *_t3127 = &(((*({ hrv *_t3128 = &(g389); int64_t _i3128 = v_1056; (S12*)_t3128->b + hr_ix(_i3128, _t3128->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:787"); }))).ty_); *_t3127 = ((int32_t)(f119_t_ref(((int64_t)(((*({ hrv *_t3130 = &(g551); int64_t _i3130 = ((*({ hrv *_t3131 = &(g389); int64_t _i3131 = v_1056; (S12*)_t3131->b + hr_ix(_i3131, _t3131->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:787"); }))).ty_; (S1*)_t3130->b + hr_ix(_i3130, _t3130->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:787"); }))).a_)), ((int64_t)2LL)))); }
 }
 }
return;
 }
int64_t tt_1057 = f137_ck(((int64_t)((x_1047).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t d_1058 = f179_deref(tt_1057); 
if (((o_1048) == (((int64_t)36LL)))) { if ((((((*({ hrv *_t3134 = &(g551); int64_t _i3134 = tt_1057; (S1*)_t3134->b + hr_ix(_i3134, _t3134->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:795"); }))).k_) == (((uint8_t)10LL))) && f165_is_opt(tt_1057))) { int64_t rt_1059 = f137_ck(((int64_t)((x_1047).b_)), tt_1057); 
if (((((*({ hrv *_t3137 = &(g551); int64_t _i3137 = rt_1059; (S1*)_t3137->b + hr_ix(_i3137, _t3137->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:797"); }))).k_) == (((uint8_t)11LL)))) { (void)(f162_commit(((int64_t)((x_1047).b_)), tt_1057));
return;
 }
if (((((*({ hrv *_t3139 = &(g551); int64_t _i3139 = rt_1059; (S1*)_t3139->b + hr_ix(_i3139, _t3139->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:798"); }))).k_) == (((uint8_t)10LL)))) { (void)(f140_conv(((int64_t)((x_1047).b_)), tt_1057));
return;
 }
 }
(void)(f137_ck(((int64_t)((x_1047).b_)), d_1058));
(void)(f140_conv(((int64_t)((x_1047).b_)), d_1058));
return;
 }
int64_t lk_1060 = f180_leaf_kind(d_1058); 
int64_t rt_1061 = f137_ck(((int64_t)((x_1047).b_)), ({ int64_t _r3145; if ((((lk_1060) >= (((int64_t)4LL))) && (((o_1048) == (((int64_t)28LL))) || ((o_1048) == (((int64_t)29LL)))))) { _r3145 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r3145 = d_1058;  } _r3145; })); 
if (((((lk_1060) >= (((int64_t)4LL))) && (((o_1048) == (((int64_t)28LL))) || ((o_1048) == (((int64_t)29LL))))) && ((f179_deref(rt_1061)) != (d_1058)))) { (void)(f140_conv(((int64_t)((x_1047).b_)), f181_leaf_type(d_1058)));
return;
 }
if ((((o_1048) == (((int64_t)45LL))) || ((o_1048) == (((int64_t)46LL))))) { if (f163_is_pending(rt_1061)) { (void)(f140_conv(((int64_t)((x_1047).b_)), g563));
 }
return;
 }
(void)(f140_conv(((int64_t)((x_1047).b_)), d_1058));
}
static void f206_decl_nested(int64_t n_1063) {
int64_t i_1064 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v3153 = &(g312); for (int64_t _k3153 = 0; _k3153 < _v3153->n; _k3153++) { S14 f_1065 = ((S14*)_v3153->b)[_k3153]; if ((((((int64_t)((f_1065).node_))) == (n_1063)) && ((((int64_t)((f_1065).own_))) == (g401)))) { i_1064 = ((int64_t)((f_1065).inst_));
 }
 } } _bk3152:; 
if (((i_1064) < (((int64_t)0LL)))) { i_1064 = f105_new_inst(n_1063, n_1063, ((int64_t)((*({ hrv *_t3155 = &(g719); int64_t _i3155 = n_1063; (int32_t*)_t3155->b + hr_ix(_i3155, _t3155->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:27"); })))), g401);
(void)(({ hrv *_v3156 = &(g312); S14 _x3156 = ((S14){ .name_ = ((*({ hrv *_t3157 = &(g704); int64_t _i3157 = n_1063; (S4*)_t3157->b + hr_ix(_i3157, _t3157->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:27"); }))).s_, .node_ = ((int32_t)(n_1063)), .inst_ = ((int32_t)(i_1064)), .own_ = ((int32_t)(g401)), }); S14 *_p3156 = (S14*)hr_grow(_v3156, 1, sizeof _x3156); *_p3156 = _x3156; _p3156; }));
(void)(f195_sig_inst(i_1064));
 }
(void)(f207_check_inst(i_1064));
}
static void f207_check_inst(int64_t i_1066) {
if (((((*({ hrv *_t3160 = &(g388); int64_t _i3160 = i_1066; (S6*)_t3160->b + hr_ix(_i3160, _t3160->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:146"); }))).st_) != (((uint8_t)0LL)))) { return;
 }
int64_t node_1067 = ((int64_t)(((*({ hrv *_t3161 = &(g388); int64_t _i3161 = i_1066; (S6*)_t3161->b + hr_ix(_i3161, _t3161->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:147"); }))).node_)); 
{ uint8_t *_t3162 = &(((*({ hrv *_t3163 = &(g388); int64_t _i3163 = i_1066; (S6*)_t3163->b + hr_ix(_i3163, _t3163->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:148"); }))).st_); *_t3162 = ((uint8_t)1LL); }
if (((((uint16_t)((uint64_t)((*({ hrv *_t3164 = &(g704); int64_t _i3164 = node_1067; (S4*)_t3164->b + hr_ix(_i3164, _t3164->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:149"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { int64_t sa0_1068 = g401; 
int64_t sc0_1069 = g402; 
g401 = i_1066;
g402 = i_1066;
{ int32_t _e3166 = ((*({ hrv *_t3167 = &(g704); int64_t _i3167 = node_1067; (S4*)_t3167->b + hr_ix(_i3167, _t3167->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:149"); }))).n_; for (int32_t _k3166 = 0; _k3166 < _e3166; _k3166++) { int32_t j_1070 = (int32_t)_k3166; int64_t p_1071 = f90_kid(node_1067, ((int64_t)(j_1070))); 
if (((((*({ hrv *_t3169 = &(g704); int64_t _i3169 = p_1071; (S4*)_t3169->b + hr_ix(_i3169, _t3169->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:149"); }))).b_) >= (((int32_t)0LL)))) { int64_t pt_1074 = f208_ptype_of(i_1066, ((int64_t)(j_1070))); 
(void)(f137_ck(((int64_t)(((*({ hrv *_t3172 = &(g704); int64_t _i3172 = p_1071; (S4*)_t3172->b + hr_ix(_i3172, _t3172->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:149"); }))).b_)), pt_1074));
(void)(f140_conv(((int64_t)(((*({ hrv *_t3174 = &(g704); int64_t _i3174 = p_1071; (S4*)_t3174->b + hr_ix(_i3174, _t3174->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:149"); }))).b_)), pt_1074));
 }
 } } _bk3165:; 
g401 = sa0_1068;
g402 = sc0_1069;
{ uint8_t *_t3175 = &(((*({ hrv *_t3176 = &(g388); int64_t _i3176 = i_1066; (S6*)_t3176->b + hr_ix(_i3176, _t3176->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:149"); }))).st_); *_t3175 = ((uint8_t)2LL); }
return;
 }
int64_t sa_1075 = g401; 
int64_t sc_1076 = g402; 
int64_t sm_1077 = (g390).n; 
int64_t ld_1078 = g407; 
int64_t bt_1079 = (g468).n; 
int64_t nm0_1080 = (g312).n; 
g401 = i_1066;
g402 = i_1066;
g407 = ((int64_t)0LL);
int64_t g0_1081 = (g491).n; 
{ int32_t _e3178 = ((*({ hrv *_t3179 = &(g388); int64_t _i3179 = i_1066; (S6*)_t3179->b + hr_ix(_i3179, _t3179->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:153"); }))).gn_; for (int32_t _k3178 = 0; _k3178 < _e3178; _k3178++) { int32_t j_1082 = (int32_t)_k3178; (void)(({ hrv *_v3180 = &(g491); S7 _x3180 = (*({ hrv *_t3181 = &(g394); int64_t _i3181 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3182 = &(g388); int64_t _i3182 = i_1066; (S6*)_t3182->b + hr_ix(_i3182, _t3182->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:153"); }))).g0_)) + (int64_t)((int64_t)(j_1082)))); (S7*)_t3181->b + hr_ix(_i3181, _t3181->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:153"); })); S7 *_p3180 = (S7*)hr_grow(_v3180, 1, sizeof _x3180); *_p3180 = _x3180; _p3180; }));
 } } _bk3177:; 
{ int32_t _e3184 = ((*({ hrv *_t3185 = &(g704); int64_t _i3185 = node_1067; (S4*)_t3185->b + hr_ix(_i3185, _t3185->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:154"); }))).n_; for (int32_t _k3184 = 0; _k3184 < _e3184; _k3184++) { int32_t j_1083 = (int32_t)_k3184; int64_t p_1084 = f90_kid(node_1067, ((int64_t)(j_1083))); 
if (((((*({ hrv *_t3187 = &(g704); int64_t _i3187 = p_1084; (S4*)_t3187->b + hr_ix(_i3187, _t3187->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:154"); }))).b_) >= (((int32_t)0LL)))) { int64_t pt_1085 = f208_ptype_of(i_1066, ((int64_t)(j_1083))); 
(void)(f137_ck(((int64_t)(((*({ hrv *_t3190 = &(g704); int64_t _i3190 = p_1084; (S4*)_t3190->b + hr_ix(_i3190, _t3190->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:154"); }))).b_)), pt_1085));
(void)(f140_conv(((int64_t)(((*({ hrv *_t3192 = &(g704); int64_t _i3192 = p_1084; (S4*)_t3192->b + hr_ix(_i3192, _t3192->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:154"); }))).b_)), pt_1085));
 }
 } } _bk3183:; 
{ int32_t _e3194 = ((*({ hrv *_t3195 = &(g704); int64_t _i3195 = node_1067; (S4*)_t3195->b + hr_ix(_i3195, _t3195->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:155"); }))).n_; for (int32_t _k3194 = 0; _k3194 < _e3194; _k3194++) { int32_t j_1086 = (int32_t)_k3194; int64_t p_1087 = f90_kid(node_1067, ((int64_t)(j_1086))); 
int64_t v_1088 = f203_add_lv(((int64_t)(((*({ hrv *_t3198 = &(g704); int64_t _i3198 = p_1087; (S4*)_t3198->b + hr_ix(_i3198, _t3198->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:155"); }))).s_)), f208_ptype_of(i_1066, ((int64_t)(j_1086))), ((int64_t)((int64_t)((int64_t)4LL) | (int64_t)({ int64_t _r3200; if (((((uint16_t)((uint64_t)((*({ hrv *_t3201 = &(g704); int64_t _i3201 = p_1087; (S4*)_t3201->b + hr_ix(_i3201, _t3201->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:155"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { _r3200 = ((int64_t)1LL);  } else { _r3200 = ((int64_t)0LL);  } _r3200; }))), p_1087); 
(void)(f170_set_r(p_1087, ((int64_t)1LL), v_1088));
 } } _bk3193:; 
int64_t body_1089 = ((int64_t)(((*({ hrv *_t3203 = &(g704); int64_t _i3203 = node_1067; (S4*)_t3203->b + hr_ix(_i3203, _t3203->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:156"); }))).c_)); 
int64_t rt_1090 = ((int64_t)(((*({ hrv *_t3204 = &(g388); int64_t _i3204 = i_1066; (S6*)_t3204->b + hr_ix(_i3204, _t3204->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:157"); }))).ret_)); 
int64_t t_1091 = f137_ck(body_1089, ({ int64_t _r3206; if (((rt_1090) >= (((int64_t)0LL)))) { _r3206 = rt_1090;  } else { _r3206 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3206; })); 
int64_t tail_1092 = ((int64_t)(((*({ hrv *_t3207 = &(g704); int64_t _i3207 = body_1089; (S4*)_t3207->b + hr_ix(_i3207, _t3207->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:159"); }))).a_)); 
if (((rt_1090) >= (((int64_t)0LL)))) { if ((((((tail_1092) >= (((int64_t)0LL))) && ((rt_1090) != (g558))) && ((t_1091) != (g558))) && (!(f209_ends(tail_1092))))) { (void)(f140_conv(tail_1092, rt_1090));
 }
 } else { if (((((*({ hrv *_t3210 = &(g388); int64_t _i3210 = i_1066; (S6*)_t3210->b + hr_ix(_i3210, _t3210->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:162"); }))).ret_) < (((int32_t)0LL)))) { if ((((tail_1092) >= (((int64_t)0LL))) && ((t_1091) != (g558)))) { { int32_t *_t3211 = &(((*({ hrv *_t3212 = &(g388); int64_t _i3212 = i_1066; (S6*)_t3212->b + hr_ix(_i3212, _t3212->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:162"); }))).ret_); *_t3211 = ((int32_t)(f184_default_t(tail_1092))); }
 } else { { int32_t *_t3214 = &(((*({ hrv *_t3215 = &(g388); int64_t _i3215 = i_1066; (S6*)_t3215->b + hr_ix(_i3215, _t3215->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:162"); }))).ret_); *_t3214 = ((int32_t)(g558)); }
 }
 } else { if (((((tail_1092) >= (((int64_t)0LL))) && ((t_1091) != (g558))) && ((((int64_t)(((*({ hrv *_t3216 = &(g388); int64_t _i3216 = i_1066; (S6*)_t3216->b + hr_ix(_i3216, _t3216->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:163"); }))).ret_))) != (g558)))) { (void)(f140_conv(tail_1092, ((int64_t)(((*({ hrv *_t3218 = &(g388); int64_t _i3218 = i_1066; (S6*)_t3218->b + hr_ix(_i3218, _t3218->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:163"); }))).ret_))));
 }
 }
 }
(void)(({ hrv *_v3219 = &(g491); int64_t _k3219 = ((int64_t)((int64_t)(g491).n - (int64_t)g0_1081)); if (_k3219 < 0 || _k3219 > _v3219->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:165"); _v3219->n -= _k3219; }));
(void)(({ hrv *_v3220 = &(g390); int64_t _k3220 = ((int64_t)((int64_t)(g390).n - (int64_t)sm_1077)); if (_k3220 < 0 || _k3220 > _v3220->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:166"); _v3220->n -= _k3220; }));
(void)(({ hrv *_v3221 = &(g312); int64_t _k3221 = ((int64_t)((int64_t)(g312).n - (int64_t)nm0_1080)); if (_k3221 < 0 || _k3221 > _v3221->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:166"); _v3221->n -= _k3221; }));
while ((((g468).n) > (bt_1079))) { (void)(({ hrv *_v3223 = &(g468); if (!_v3223->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:167"); ((int32_t*)_v3223->b)[--_v3223->n]; }));
 } _bk3222:; 
g401 = sa_1075;
g402 = sc_1076;
g407 = ld_1078;
{ uint8_t *_t3224 = &(((*({ hrv *_t3225 = &(g388); int64_t _i3225 = i_1066; (S6*)_t3225->b + hr_ix(_i3225, _t3225->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:169"); }))).st_); *_t3224 = ((uint8_t)2LL); }
}
static int64_t f208_ptype_of(int64_t i_1072, int64_t j_1073) {
return ((int64_t)((*({ hrv *_t3226 = &(g552); int64_t _i3226 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3227 = &(g388); int64_t _i3227 = i_1072; (S6*)_t3227->b + hr_ix(_i3227, _t3227->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:144"); }))).p0_)) + (int64_t)j_1073)); (int32_t*)_t3226->b + hr_ix(_i3226, _t3226->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:144"); }))));
}
static bool f209_ends(int64_t n_1093) {
if (((n_1093) < (((int64_t)0LL)))) { return false;
 }
int64_t k_1094 = ((int64_t)(((*({ hrv *_t3228 = &(g704); int64_t _i3228 = n_1093; (S4*)_t3228->b + hr_ix(_i3228, _t3228->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:491"); }))).k_)); 
if (((((k_1094) == (((int64_t)28LL))) || ((k_1094) == (((int64_t)29LL)))) || ((k_1094) == (((int64_t)30LL))))) { return true;
 }
if ((((k_1094) == (((int64_t)11LL))) && ((((*({ hrv *_t3229 = &(g704); int64_t _i3229 = ((*({ hrv *_t3230 = &(g704); int64_t _i3230 = n_1093; (S4*)_t3230->b + hr_ix(_i3230, _t3230->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:493"); }))).a_; (S4*)_t3229->b + hr_ix(_i3229, _t3229->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:493"); }))).k_) == (((uint8_t)8LL))))) { hsl s_1095 = f10_nm(((int64_t)(((*({ hrv *_t3232 = &(g704); int64_t _i3232 = ((*({ hrv *_t3233 = &(g704); int64_t _i3233 = n_1093; (S4*)_t3233->b + hr_ix(_i3233, _t3233->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:493"); }))).a_; (S4*)_t3232->b + hr_ix(_i3232, _t3232->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:493"); }))).s_))); 
if ((hr_streq(s_1095, hr_str("abort", 5)) || hr_streq(s_1095, hr_str("exit", 4)))) { return true;
 }
 }
if (((k_1094) == (((int64_t)23LL)))) { if (((((*({ hrv *_t3234 = &(g704); int64_t _i3234 = n_1093; (S4*)_t3234->b + hr_ix(_i3234, _t3234->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:494"); }))).a_) >= (((int32_t)0LL)))) { return f209_ends(((int64_t)(((*({ hrv *_t3236 = &(g704); int64_t _i3236 = n_1093; (S4*)_t3236->b + hr_ix(_i3236, _t3236->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:494"); }))).a_)));
 }
if (((((*({ hrv *_t3237 = &(g704); int64_t _i3237 = n_1093; (S4*)_t3237->b + hr_ix(_i3237, _t3237->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:494"); }))).n_) > (((int32_t)0LL)))) { return f209_ends(f90_kid(n_1093, ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3240 = &(g704); int64_t _i3240 = n_1093; (S4*)_t3240->b + hr_ix(_i3240, _t3240->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:494"); }))).n_)) - (int64_t)((int64_t)1LL)))));
 }
return false;
 }
if (((k_1094) == (((int64_t)19LL)))) { return ((((((*({ hrv *_t3241 = &(g704); int64_t _i3241 = n_1093; (S4*)_t3241->b + hr_ix(_i3241, _t3241->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:495"); }))).c_) >= (((int32_t)0LL))) && f209_ends(((int64_t)(((*({ hrv *_t3243 = &(g704); int64_t _i3243 = n_1093; (S4*)_t3243->b + hr_ix(_i3243, _t3243->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:495"); }))).b_)))) && f209_ends(((int64_t)(((*({ hrv *_t3245 = &(g704); int64_t _i3245 = n_1093; (S4*)_t3245->b + hr_ix(_i3245, _t3245->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:495"); }))).c_))));
 }
if (((k_1094) == (((int64_t)26LL)))) { return (!(f210_has_break(((int64_t)(((*({ hrv *_t3247 = &(g704); int64_t _i3247 = n_1093; (S4*)_t3247->b + hr_ix(_i3247, _t3247->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:496"); }))).a_)))));
 }
return false;
}
static bool f210_has_break(int64_t n_1096) {
if (((n_1096) < (((int64_t)0LL)))) { return false;
 }
S4 x_1097 = (*({ hrv *_t3248 = &(g704); int64_t _i3248 = n_1096; (S4*)_t3248->b + hr_ix(_i3248, _t3248->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:501"); })); 
int64_t k_1098 = ((int64_t)((x_1097).k_)); 
if (((k_1098) == (((int64_t)29LL)))) { return true;
 }
if (((((((k_1098) == (((int64_t)25LL))) || ((k_1098) == (((int64_t)26LL)))) || ((k_1098) == (((int64_t)27LL)))) || ((k_1098) == (((int64_t)50LL)))) || ((k_1098) == (((int64_t)31LL))))) { return false;
 }
if ((((k_1098) >= (((int64_t)40LL))) && ((k_1098) < (((int64_t)50LL))))) { return false;
 }
if (((k_1098) == (((int64_t)33LL)))) { return f210_has_break(((int64_t)((x_1097).b_)));
 }
if (((k_1098) == (((int64_t)11LL)))) { if (f210_has_break(((int64_t)((x_1097).a_)))) { return true;
 }
{ int32_t _e3252 = (x_1097).n_; for (int32_t _k3252 = 0; _k3252 < _e3252; _k3252++) { int32_t i_1099 = (int32_t)_k3252; if (f210_has_break(f90_kid(n_1096, ((int64_t)(i_1099))))) { return true;
 }
 } } _bk3251:; 
return false;
 }
if ((((f210_has_break(((int64_t)((x_1097).a_))) || f210_has_break(((int64_t)((x_1097).b_)))) || f210_has_break(((int64_t)((x_1097).c_)))) || f210_has_break(((int64_t)((x_1097).d_))))) { return true;
 }
if ((((((((k_1098) == (((int64_t)23LL))) || ((k_1098) == (((int64_t)20LL)))) || ((k_1098) == (((int64_t)36LL)))) || ((k_1098) == (((int64_t)16LL)))) || ((k_1098) == (((int64_t)17LL)))) || ((k_1098) == (((int64_t)28LL))))) { { int32_t _e3260 = (x_1097).n_; for (int32_t _k3260 = 0; _k3260 < _e3260; _k3260++) { int32_t i_1100 = (int32_t)_k3260; int64_t c_1101 = f90_kid(n_1096, ((int64_t)(i_1100))); 
if (f210_has_break(c_1101)) { return true;
 }
if ((((k_1098) == (((int64_t)20LL))) && f210_has_break(((int64_t)(((*({ hrv *_t3264 = &(g704); int64_t _i3264 = c_1101; (S4*)_t3264->b + hr_ix(_i3264, _t3264->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:512"); }))).b_))))) { return true;
 }
 } } _bk3259:; 
 }
return false;
}
static void f211_pop_block_fns(int64_t m_1104) {
if ((((g312).n) > (m_1104))) { (void)(({ hrv *_v3265 = &(g312); int64_t _k3265 = ((int64_t)((int64_t)(g312).n - (int64_t)m_1104)); if (_k3265 < 0 || _k3265 > _v3265->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:35"); _v3265->n -= _k3265; }));
 }
}
static int64_t f212_ck_if(int64_t n_1107, int64_t want_1108) {
S4 x_1109 = (*({ hrv *_t3266 = &(g704); int64_t _i3266 = n_1107; (S4*)_t3266->b + hr_ix(_i3266, _t3266->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:518"); })); 
int64_t c_1110 = f137_ck(((int64_t)((x_1109).a_)), g559); 
(void)(f140_conv(((int64_t)((x_1109).a_)), g559));
int64_t m_1111 = (g390).n; 
int64_t nm0_1112 = (g391).n; 
(void)(f177_narrow_push(((int64_t)((x_1109).a_))));
int64_t tb_1113 = f137_ck(((int64_t)((x_1109).b_)), want_1108); 
(void)(f178_narrow_pop(nm0_1112));
(void)(({ hrv *_v3272 = &(g390); int64_t _k3272 = ((int64_t)((int64_t)(g390).n - (int64_t)m_1111)); if (_k3272 < 0 || _k3272 > _v3272->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:526"); _v3272->n -= _k3272; }));
if ((((x_1109).c_) < (((int32_t)0LL)))) { return f138_set_t(n_1107, g558);
 }
int64_t tc_1114 = f137_ck(((int64_t)((x_1109).c_)), want_1108); 
bool eb_1115 = f209_ends(((int64_t)((x_1109).b_))); 
bool ec_1116 = f209_ends(((int64_t)((x_1109).c_))); 
if ((eb_1115 && (!(ec_1116)))) { return f138_set_t(n_1107, tc_1114);
 }
if ((ec_1116 && (!(eb_1115)))) { return f138_set_t(n_1107, tb_1113);
 }
if ((eb_1115 && ec_1116)) { return f138_set_t(n_1107, tb_1113);
 }
if ((((tb_1113) == (g558)) || ((tc_1114) == (g558)))) { return f138_set_t(n_1107, g558);
 }
if (((tb_1113) == (tc_1114))) { return f138_set_t(n_1107, tb_1113);
 }
if ((((((want_1108) >= (((int64_t)0LL))) && ((want_1108) != (g558))) && (f163_is_pending(tb_1113) || f151_conv_ok(tb_1113, want_1108, ((int64_t)((x_1109).b_))))) && (f163_is_pending(tc_1114) || f151_conv_ok(tc_1114, want_1108, ((int64_t)((x_1109).c_)))))) { (void)(f140_conv(((int64_t)((x_1109).b_)), want_1108));
(void)(f140_conv(((int64_t)((x_1109).c_)), want_1108));
return f138_set_t(n_1107, want_1108);
 }
int64_t u_1117 = f182_unify(n_1107, ((int64_t)((x_1109).b_)), ((int64_t)((x_1109).c_))); 
return f138_set_t(n_1107, u_1117);
}
static int64_t f213_ck_while(int64_t n_1118) {
S4 x_1119 = (*({ hrv *_t3291 = &(g704); int64_t _i3291 = n_1118; (S4*)_t3291->b + hr_ix(_i3291, _t3291->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:540"); })); 
int64_t c_1120 = f137_ck(((int64_t)((x_1119).a_)), g559); 
(void)(f140_conv(((int64_t)((x_1119).a_)), g559));
int64_t nm0_1121 = (g391).n; 
(void)(f177_narrow_push(((int64_t)((x_1119).a_))));
g407++;
(void)(f137_ck(((int64_t)((x_1119).b_)), g558));
g407--;
(void)(f178_narrow_pop(nm0_1121));
return f138_set_t(n_1118, g558);
}
static int64_t f214_ck_loop(int64_t n_1122, int64_t want_1123) {
(void)(({ hrv *_v3298 = &(g468); int32_t _x3298 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p3298 = (int32_t*)hr_grow(_v3298, 1, sizeof _x3298); *_p3298 = _x3298; _p3298; }));
g407++;
(void)(f137_ck(((int64_t)(((*({ hrv *_t3300 = &(g704); int64_t _i3300 = n_1122; (S4*)_t3300->b + hr_ix(_i3300, _t3300->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:555"); }))).a_)), g558));
g407--;
int64_t t_1124 = ((int64_t)(({ hrv *_v3301 = &(g468); if (!_v3301->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:557"); ((int32_t*)_v3301->b)[--_v3301->n]; }))); 
return f138_set_t(n_1122, ({ int64_t _r3303; if (((t_1124) < (((int64_t)0LL)))) { _r3303 = g558;  } else { _r3303 = t_1124;  } _r3303; }));
}
static int64_t f215_ck_for(int64_t n_1125) {
S4 x_1126 = (*({ hrv *_t3304 = &(g704); int64_t _i3304 = n_1125; (S4*)_t3304->b + hr_ix(_i3304, _t3304->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:561"); })); 
int64_t m_1127 = (g390).n; 
int64_t et_1128 = g563; 
if ((((x_1126).b_) >= (((int32_t)0LL)))) { int64_t ta_1129 = f137_ck(((int64_t)((x_1126).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t tb_1130 = f137_ck(((int64_t)((x_1126).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t u_1131 = f182_unify(n_1125, ((int64_t)((x_1126).a_)), ((int64_t)((x_1126).b_))); 
et_1128 = ({ int64_t _r3308; if (((((*({ hrv *_t3309 = &(g551); int64_t _i3309 = u_1131; (S1*)_t3309->b + hr_ix(_i3309, _t3309->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:567"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1126).a_)), g563));
(void)(f140_conv(((int64_t)((x_1126).b_)), g563));
_r3308 = g563;  } else { _r3308 = u_1131;  } _r3308; });
(void)(f175_set_x(n_1125, ((int64_t)0LL)));
 } else { int64_t t_1132 = f137_ck(((int64_t)((x_1126).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3314 = &(g551); int64_t _i3314 = t_1132; (S1*)_t3314->b + hr_ix(_i3314, _t3314->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:571"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_1126).a_)), g576));
t_1132 = g576;
 }
if (((((*({ hrv *_t3316 = &(g551); int64_t _i3316 = t_1132; (S1*)_t3316->b + hr_ix(_i3316, _t3316->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:572"); }))).k_) == (((uint8_t)19LL)))) { t_1132 = f184_default_t(((int64_t)((x_1126).a_)));
 }
int64_t d_1133 = f179_deref(t_1132); 
if (((((*({ hrv *_t3319 = &(g551); int64_t _i3319 = d_1133; (S1*)_t3319->b + hr_ix(_i3319, _t3319->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:574"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1126).a_)), g563));
et_1128 = g563;
(void)(f175_set_x(n_1125, ((int64_t)0LL)));
 } else { if ((((((*({ hrv *_t3322 = &(g551); int64_t _i3322 = d_1133; (S1*)_t3322->b + hr_ix(_i3322, _t3322->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:575"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t3323 = &(g551); int64_t _i3323 = d_1133; (S1*)_t3323->b + hr_ix(_i3323, _t3323->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:575"); }))).k_) == (((uint8_t)17LL))))) { et_1128 = ({ int64_t _r3324; if (((((*({ hrv *_t3325 = &(g551); int64_t _i3325 = d_1133; (S1*)_t3325->b + hr_ix(_i3325, _t3325->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:575"); }))).k_) == (((uint8_t)17LL)))) { _r3324 = g563;  } else { _r3324 = d_1133;  } _r3324; });
if (((et_1128) != (t_1132))) { (void)(f142_set_cv(((int64_t)((x_1126).a_)), et_1128));
 }
(void)(f175_set_x(n_1125, ((int64_t)0LL)));
 } else { if ((((((*({ hrv *_t3328 = &(g551); int64_t _i3328 = d_1133; (S1*)_t3328->b + hr_ix(_i3328, _t3328->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:576"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3329 = &(g551); int64_t _i3329 = d_1133; (S1*)_t3329->b + hr_ix(_i3329, _t3329->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:576"); }))).k_) == (((uint8_t)9LL))))) { et_1128 = f188_decode_rel(((int64_t)(((*({ hrv *_t3331 = &(g551); int64_t _i3331 = d_1133; (S1*)_t3331->b + hr_ix(_i3331, _t3331->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:576"); }))).a_)));
(void)(f175_set_x(n_1125, ((int64_t)1LL)));
 } else { hrv mm_1134 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t3335 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o3334 = &(mm_1134); hr_fs(_o3334, hr_str("cannot iterate over ", 20)); hr_fs(_o3334, hr_sl(*hr_tmp(&_t3335, f161_tn(d_1133)))); }));
}
(void)(f108_cerr(n_1125, hr_sl(mm_1134)));
 }
 }
 }
 }
if ((((x_1126).l_) >= (((int32_t)0LL)))) { et_1128 = f113_rtype(((int64_t)((x_1126).l_)), f110_ns_of(n_1125));
 }
bool byref_1136 = (((((uint16_t)((uint64_t)(x_1126).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || f216_is_bytes(et_1128)); 
int64_t v_1137 = f203_add_lv(((int64_t)((x_1126).s_)), ({ int64_t _r3342; if (byref_1136) { _r3342 = f119_t_ref(et_1128, ((int64_t)0LL));  } else { _r3342 = et_1128;  } _r3342; }), ((int64_t)((int64_t)((int64_t)16LL) | (int64_t)({ int64_t _r3344; if (byref_1136) { _r3344 = ((int64_t)8LL);  } else { _r3344 = ((int64_t)0LL);  } _r3344; }))), n_1125); 
(void)(f170_set_r(n_1125, ((int64_t)1LL), v_1137));
if ((((x_1126).c_) >= (((int32_t)0LL)))) { int64_t iv_1138 = f203_add_lv(((int64_t)((x_1126).c_)), ({ int64_t _r3347; if ((((x_1126).n_) >= (((int32_t)0LL)))) { _r3347 = f113_rtype(((int64_t)((x_1126).n_)), f110_ns_of(n_1125));  } else { _r3347 = g563;  } _r3347; }), ((int64_t)16LL), n_1125); 
(void)(f175_set_x(n_1125, ((int64_t)((int64_t)f217_ax(n_1125) | (int64_t)((int64_t)((iv_1138) << ((((int64_t)2LL)) & 63)))))));
 }
g407++;
(void)(f137_ck(((int64_t)((x_1126).d_)), g558));
g407--;
(void)(({ hrv *_v3353 = &(g390); int64_t _k3353 = ((int64_t)((int64_t)(g390).n - (int64_t)m_1127)); if (_k3353 < 0 || _k3353 > _v3353->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:587"); _v3353->n -= _k3353; }));
return f138_set_t(n_1125, g558);
}
static bool f216_is_bytes(int64_t t_1135) {
return ((((f143_tclass(t_1135)) == (((int64_t)1LL))) && ((((*({ hrv *_t3356 = &(g551); int64_t _i3356 = t_1135; (S1*)_t3356->b + hr_ix(_i3356, _t3356->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:93"); }))).k_) != (((uint8_t)17LL)))) && ((((*({ hrv *_t3357 = &(g551); int64_t _i3357 = t_1135; (S1*)_t3357->b + hr_ix(_i3357, _t3357->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:93"); }))).k_) != (((uint8_t)10LL))));
}
static int64_t f217_ax(int64_t n_1139) {
return ((int64_t)((*({ hrv *_t3358 = &(g399); int64_t _i3358 = f139_aix(n_1139); (int32_t*)_t3358->b + hr_ix(_i3358, _t3358->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:47"); }))));
}
static int64_t f218_ck_match(int64_t n_1140, int64_t want_1141) {
S4 x_1142 = (*({ hrv *_t3360 = &(g704); int64_t _i3360 = n_1140; (S4*)_t3360->b + hr_ix(_i3360, _t3360->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:591"); })); 
int64_t st_1143 = f137_ck(((int64_t)((x_1142).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3362 = &(g551); int64_t _i3362 = st_1143; (S1*)_t3362->b + hr_ix(_i3362, _t3362->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:593"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1142).a_)), g563));
st_1143 = g563;
 }
if (((((*({ hrv *_t3364 = &(g551); int64_t _i3364 = st_1143; (S1*)_t3364->b + hr_ix(_i3364, _t3364->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:594"); }))).k_) == (((uint8_t)7LL)))) { st_1143 = f136_t_enum(((int64_t)(((*({ hrv *_t3366 = &(g551); int64_t _i3366 = st_1143; (S1*)_t3366->b + hr_ix(_i3366, _t3366->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:594"); }))).a_)), false);
(void)(f142_set_cv(((int64_t)((x_1142).a_)), st_1143));
 }
int64_t d_1144 = f179_deref(st_1143); 
int64_t rt_1145 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
bool allv_1146 = true; 
{ int32_t _e3370 = (x_1142).n_; for (int32_t _k3370 = 0; _k3370 < _e3370; _k3370++) { int32_t i_1147 = (int32_t)_k3370; int64_t arm_1148 = f90_kid(n_1140, ((int64_t)(i_1147))); 
int64_t m_1149 = (g390).n; 
S4 ax0_1150 = (*({ hrv *_t3372 = &(g704); int64_t _i3372 = arm_1148; (S4*)_t3372->b + hr_ix(_i3372, _t3372->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:601"); })); 
if (((((uint16_t)((uint64_t)(ax0_1150).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) { { int32_t _e3374 = (ax0_1150).n_; for (int32_t _k3374 = 0; _k3374 < _e3374; _k3374++) { int32_t j_1151 = (int32_t)_k3374; int64_t it_1152 = f90_kid(arm_1148, ((int64_t)(j_1151))); 
int64_t lo_1153 = ((int64_t)(((*({ hrv *_t3376 = &(g704); int64_t _i3376 = it_1152; (S4*)_t3376->b + hr_ix(_i3376, _t3376->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:605"); }))).a_)); 
if ((((((*({ hrv *_t3377 = &(g551); int64_t _i3377 = d_1144; (S1*)_t3377->b + hr_ix(_i3377, _t3377->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:606"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t3378 = &(g704); int64_t _i3378 = lo_1153; (S4*)_t3378->b + hr_ix(_i3378, _t3378->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:606"); }))).k_) == (((uint8_t)8LL))))) { int64_t ei_1154 = ((int64_t)(((*({ hrv *_t3379 = &(g551); int64_t _i3379 = d_1144; (S1*)_t3379->b + hr_ix(_i3379, _t3379->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:607"); }))).a_)); 
int64_t found_1155 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e3381 = ((*({ hrv *_t3382 = &(g556); int64_t _i3382 = ei_1154; (S8*)_t3382->b + hr_ix(_i3382, _t3382->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:609"); }))).vnum_; for (int32_t _k3381 = 0; _k3381 < _e3381; _k3381++) { int32_t q_1156 = (int32_t)_k3381; if (((((*({ hrv *_t3383 = &(g557); int64_t _i3383 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3384 = &(g556); int64_t _i3384 = ei_1154; (S8*)_t3384->b + hr_ix(_i3384, _t3384->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:609"); }))).v0_)) + (int64_t)((int64_t)(q_1156)))); (S9*)_t3383->b + hr_ix(_i3383, _t3383->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:609"); }))).name_) == (((*({ hrv *_t3385 = &(g704); int64_t _i3385 = lo_1153; (S4*)_t3385->b + hr_ix(_i3385, _t3385->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:609"); }))).s_))) { found_1155 = ((int64_t)(q_1156));
 }
 } } _bk3380:; 
if (((found_1155) < (((int64_t)0LL)))) { hrv mm_1157 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t3390 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o3387 = &(mm_1157); hr_fs(_o3387, hr_str("no variant ", 11)); hr_fs(_o3387, f10_nm(((int64_t)(((*({ hrv *_t3389 = &(g704); int64_t _i3389 = lo_1153; (S4*)_t3389->b + hr_ix(_i3389, _t3389->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:610"); }))).s_)))); hr_fs(_o3387, hr_str(" in ", 4)); hr_fs(_o3387, hr_sl(*hr_tmp(&_t3390, f161_tn(d_1144)))); }));
}
(void)(f108_cerr(lo_1153, hr_sl(mm_1157)));
 }
(void)(f170_set_r(lo_1153, ((int64_t)7LL), found_1155));
(void)(f138_set_t(lo_1153, d_1144));
if (((((ax0_1150).s_) >= (((int32_t)0LL))) && ((found_1155) >= (((int64_t)0LL))))) { int64_t vt_1158 = f125_t_variant(ei_1154, found_1155); 
bool byr_1159 = (((((uint16_t)((uint64_t)(ax0_1150).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))) || f216_is_bytes(vt_1158)); 
int64_t v_1160 = f203_add_lv(((int64_t)((ax0_1150).s_)), ({ int64_t _r3398; if (byr_1159) { _r3398 = f119_t_ref(vt_1158, ((int64_t)0LL));  } else { _r3398 = vt_1158;  } _r3398; }), ({ int64_t _r3400; if (byr_1159) { _r3400 = ((int64_t)8LL);  } else { _r3400 = ((int64_t)0LL);  } _r3400; }), arm_1148); 
(void)(f170_set_r(arm_1148, ((int64_t)1LL), v_1160));
 }
 } else { (void)(f137_ck(lo_1153, d_1144));
(void)(f140_conv(lo_1153, d_1144));
if (((((*({ hrv *_t3404 = &(g704); int64_t _i3404 = it_1152; (S4*)_t3404->b + hr_ix(_i3404, _t3404->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:615"); }))).b_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)(((*({ hrv *_t3406 = &(g704); int64_t _i3406 = it_1152; (S4*)_t3406->b + hr_ix(_i3406, _t3406->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:615"); }))).b_)), d_1144));
(void)(f140_conv(((int64_t)(((*({ hrv *_t3408 = &(g704); int64_t _i3408 = it_1152; (S4*)_t3408->b + hr_ix(_i3408, _t3408->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:615"); }))).b_)), d_1144));
 }
 }
 } } _bk3373:; 
 }
int64_t bt_1161 = f137_ck(((int64_t)((ax0_1150).b_)), want_1141); 
(void)(({ hrv *_v3410 = &(g390); int64_t _k3410 = ((int64_t)((int64_t)(g390).n - (int64_t)m_1149)); if (_k3410 < 0 || _k3410 > _v3410->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:620"); _v3410->n -= _k3410; }));
if (((bt_1161) == (g558))) { allv_1146 = false;
 } else { if ((!(f209_ends(((int64_t)((ax0_1150).b_)))))) { if ((((rt_1145) < (((int64_t)0LL))) || f163_is_pending(rt_1145))) { rt_1145 = bt_1161;
 }
 }
 }
 } } _bk3369:; 
if (((!(allv_1146)) || ((rt_1145) < (((int64_t)0LL))))) { return f138_set_t(n_1140, g558);
 }
bool allw_1162 = (((want_1141) >= (((int64_t)0LL))) && ((want_1141) != (g558))); 
if (allw_1162) { { int32_t _e3415 = (x_1142).n_; for (int32_t _k3415 = 0; _k3415 < _e3415; _k3415++) { int32_t i_1163 = (int32_t)_k3415; int64_t b_1164 = ((int64_t)(((*({ hrv *_t3416 = &(g704); int64_t _i3416 = f90_kid(n_1140, ((int64_t)(i_1163))); (S4*)_t3416->b + hr_ix(_i3416, _t3416->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:625"); }))).b_)); 
int64_t bt_1165 = f141_at(b_1164); 
if ((((!(f209_ends(b_1164))) && (!(f163_is_pending(bt_1165)))) && (!(f151_conv_ok(bt_1165, want_1141, b_1164))))) { allw_1162 = false;
 }
 } } _bk3414:; 
 }
if (allw_1162) { { int32_t _e3423 = (x_1142).n_; for (int32_t _k3423 = 0; _k3423 < _e3423; _k3423++) { int32_t i_1166 = (int32_t)_k3423; int64_t b_1167 = ((int64_t)(((*({ hrv *_t3424 = &(g704); int64_t _i3424 = f90_kid(n_1140, ((int64_t)(i_1166))); (S4*)_t3424->b + hr_ix(_i3424, _t3424->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:626"); }))).b_)); 
if ((!(f209_ends(b_1167)))) { (void)(f140_conv(b_1167, want_1141));
 }
 } } _bk3422:; 
return f138_set_t(n_1140, want_1141);
 }
if (f163_is_pending(rt_1145)) { { int32_t _e3431 = (x_1142).n_; for (int32_t _k3431 = 0; _k3431 < _e3431; _k3431++) { int32_t i_1168 = (int32_t)_k3431; int64_t b_1169 = ((int64_t)(((*({ hrv *_t3432 = &(g704); int64_t _i3432 = f90_kid(n_1140, ((int64_t)(i_1168))); (S4*)_t3432->b + hr_ix(_i3432, _t3432->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:627"); }))).b_)); 
int64_t bt_1170 = f141_at(b_1169); 
if (((!(f163_is_pending(bt_1170))) && (!(f209_ends(b_1169))))) { rt_1145 = bt_1170;
 }
 } } _bk3430:; 
 }
if (f163_is_pending(rt_1145)) { int64_t b_1171 = ((int64_t)(((*({ hrv *_t3438 = &(g704); int64_t _i3438 = f90_kid(n_1140, ((int64_t)0LL)); (S4*)_t3438->b + hr_ix(_i3438, _t3438->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:628"); }))).b_)); 
rt_1145 = f184_default_t(b_1171);
 }
{ int32_t _e3442 = (x_1142).n_; for (int32_t _k3442 = 0; _k3442 < _e3442; _k3442++) { int32_t i_1172 = (int32_t)_k3442; int64_t b_1173 = ((int64_t)(((*({ hrv *_t3443 = &(g704); int64_t _i3443 = f90_kid(n_1140, ((int64_t)(i_1172))); (S4*)_t3443->b + hr_ix(_i3443, _t3443->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:629"); }))).b_)); 
if ((!(f209_ends(b_1173)))) { (void)(f140_conv(b_1173, rt_1145));
 }
 } } _bk3441:; 
return f138_set_t(n_1140, rt_1145);
}
static int64_t f219_ck_ret(int64_t n_1174) {
S4 x_1175 = (*({ hrv *_t3448 = &(g704); int64_t _i3448 = n_1174; (S4*)_t3448->b + hr_ix(_i3448, _t3448->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:641"); })); 
int64_t f_1179 = ({ int64_t _r3449; if ((((x_1175).s_) >= (((int32_t)0LL)))) { _r3449 = f220_find_from_fn(((int64_t)((x_1175).s_)));  } else { _r3449 = f221_ret_fn();  } _r3449; }); 
if (((f_1179) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1174, hr_str("return outside a function", 25)));
return g558;
 }
if (((f_1179) != (g402))) { { bool *_t3453 = &(((*({ hrv *_t3454 = &(g388); int64_t _i3454 = g402; (S6*)_t3454->b + hr_ix(_i3454, _t3454->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:644"); }))).lr_); *_t3453 = true; }
{ bool *_t3455 = &(((*({ hrv *_t3456 = &(g388); int64_t _i3456 = f_1179; (S6*)_t3456->b + hr_ix(_i3456, _t3456->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:644"); }))).tg_); *_t3455 = true; }
(void)(f175_set_x(n_1174, f_1179));
 } else { (void)(f175_set_x(n_1174, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
int64_t rt_1180 = ((int64_t)(((*({ hrv *_t3459 = &(g388); int64_t _i3459 = f_1179; (S6*)_t3459->b + hr_ix(_i3459, _t3459->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:645"); }))).ret_)); 
if ((((x_1175).n_) == (((int32_t)0LL)))) { if (((((rt_1180) >= (((int64_t)0LL))) && ((rt_1180) != (g558))) && (!(((*({ hrv *_t3460 = &(g388); int64_t _i3460 = f_1179; (S6*)_t3460->b + hr_ix(_i3460, _t3460->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:646"); }))).rinf_)))) { (void)(f108_cerr(n_1174, hr_str("return needs a value", 20)));
 }
if (((rt_1180) < (((int64_t)0LL)))) { { int32_t *_t3462 = &(((*({ hrv *_t3463 = &(g388); int64_t _i3463 = f_1179; (S6*)_t3463->b + hr_ix(_i3463, _t3463->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:646"); }))).ret_); *_t3462 = ((int32_t)(g558)); }
 }
return f138_set_t(n_1174, g558);
 }
if (((((rt_1180) >= (((int64_t)0LL))) && ((((*({ hrv *_t3465 = &(g551); int64_t _i3465 = rt_1180; (S1*)_t3465->b + hr_ix(_i3465, _t3465->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:647"); }))).k_) == (((uint8_t)14LL)))) && (((x_1175).n_) == (((int32_t)1LL))))) { int64_t c_1181 = f90_kid(n_1174, ((int64_t)0LL)); 
(void)(f137_ck(c_1181, rt_1180));
return f138_set_t(n_1174, g558);
 }
if ((((x_1175).n_) > (((int32_t)1LL)))) { if (((rt_1180) < (((int64_t)0LL)))) { L89 ts_1182 = ({ L89 _t3469; memset(&_t3469, 0, sizeof _t3469); _t3469.n = 0; _t3469; }); 
{ int32_t _e3471 = (x_1175).n_; for (int32_t _k3471 = 0; _k3471 < _e3471; _k3471++) { int32_t i_1183 = (int32_t)_k3471; (void)(f137_ck(f90_kid(n_1174, ((int64_t)(i_1183))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
int64_t dt0_1184 = f184_default_t(f90_kid(n_1174, ((int64_t)(i_1183)))); 
(void)(({ L89 *_v3476 = &(ts_1182); int32_t _x3476 = ((int32_t)(dt0_1184)); if (_v3476->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:649"); _v3476->e[_v3476->n] = _x3476; &_v3476->e[_v3476->n++]; }));
 } } _bk3470:; 
{ int32_t *_t3477 = &(((*({ hrv *_t3478 = &(g388); int64_t _i3478 = f_1179; (S6*)_t3478->b + hr_ix(_i3478, _t3478->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:649"); }))).ret_); *_t3477 = ((int32_t)(f197_tlist(((int64_t)14LL), ({ hsl _t3480 = ({ L89 *_t3481 = &(ts_1182); (hsl){ (uint8_t*)_t3481->e, _t3481->n }; }); int64_t _l3480 = 0, _h3480 = _t3480.n; if (_l3480 < 0 || _h3480 < _l3480 || _h3480 > _t3480.n) hr_slerr(_l3480, _h3480, _t3480.n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:649"); (hsl){ _t3480.p + _l3480 * (int64_t)sizeof(int32_t), _h3480 - _l3480 }; }), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); }
return f138_set_t(n_1174, g558);
 }
{ int32_t _e3484 = (x_1175).n_; for (int32_t _k3484 = 0; _k3484 < _e3484; _k3484++) { int32_t i_1185 = (int32_t)_k3484; int64_t et_1186 = ({ int64_t _r3485; if ((((((*({ hrv *_t3486 = &(g551); int64_t _i3486 = rt_1180; (S1*)_t3486->b + hr_ix(_i3486, _t3486->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:650"); }))).k_) == (((uint8_t)14LL))) && ((((int64_t)(i_1185))) < (((int64_t)(((*({ hrv *_t3487 = &(g551); int64_t _i3487 = rt_1180; (S1*)_t3487->b + hr_ix(_i3487, _t3487->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:650"); }))).n_)))))) { _r3485 = ((int64_t)((*({ hrv *_t3488 = &(g552); int64_t _i3488 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3489 = &(g551); int64_t _i3489 = rt_1180; (S1*)_t3489->b + hr_ix(_i3489, _t3489->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:650"); }))).l_)) + (int64_t)((int64_t)(i_1185)))); (int32_t*)_t3488->b + hr_ix(_i3488, _t3488->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:650"); }))));  } else { _r3485 = g575;  } _r3485; }); 
(void)(f137_ck(f90_kid(n_1174, ((int64_t)(i_1185))), et_1186));
(void)(f140_conv(f90_kid(n_1174, ((int64_t)(i_1185))), et_1186));
 } } _bk3483:; 
return f138_set_t(n_1174, g558);
 }
int64_t c_1187 = f90_kid(n_1174, ((int64_t)0LL)); 
if (((rt_1180) < (((int64_t)0LL)))) { (void)(f137_ck(c_1187, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
int64_t t_1188 = f184_default_t(c_1187); 
{ int32_t *_t3498 = &(((*({ hrv *_t3499 = &(g388); int64_t _i3499 = f_1179; (S6*)_t3499->b + hr_ix(_i3499, _t3499->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:654"); }))).ret_); *_t3498 = ((int32_t)(t_1188)); }
return f138_set_t(n_1174, g558);
 }
(void)(f137_ck(c_1187, rt_1180));
(void)(f140_conv(c_1187, rt_1180));
return f138_set_t(n_1174, g558);
}
static int64_t f220_find_from_fn(int64_t name_1176) {
int64_t i_1177 = g401; 
while (((i_1177) >= (((int64_t)0LL)))) { if (((((((*({ hrv *_t3505 = &(g388); int64_t _i3505 = i_1177; (S6*)_t3505->b + hr_ix(_i3505, _t3505->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:635"); }))).node_) >= (((int32_t)0LL))) && ((((*({ hrv *_t3506 = &(g704); int64_t _i3506 = ((*({ hrv *_t3507 = &(g388); int64_t _i3507 = i_1177; (S6*)_t3507->b + hr_ix(_i3507, _t3507->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:635"); }))).node_; (S4*)_t3506->b + hr_ix(_i3506, _t3506->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:635"); }))).k_) == (((uint8_t)50LL)))) && ((((int64_t)(((*({ hrv *_t3508 = &(g388); int64_t _i3508 = i_1177; (S6*)_t3508->b + hr_ix(_i3508, _t3508->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:635"); }))).name_))) == (name_1176)))) { return i_1177;
 }
i_1177 = ({ int64_t _r3509; if (((((*({ hrv *_t3510 = &(g388); int64_t _i3510 = i_1177; (S6*)_t3510->b + hr_ix(_i3510, _t3510->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:636"); }))).bown_) >= (((int32_t)0LL)))) { _r3509 = ((int64_t)(((*({ hrv *_t3511 = &(g388); int64_t _i3511 = i_1177; (S6*)_t3511->b + hr_ix(_i3511, _t3511->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:636"); }))).bown_));  } else { _r3509 = ((int64_t)(((*({ hrv *_t3512 = &(g388); int64_t _i3512 = i_1177; (S6*)_t3512->b + hr_ix(_i3512, _t3512->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:636"); }))).par_));  } _r3509; });
 } _bk3504:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f221_ret_fn(void) {
int64_t i_1178 = g401; 
while (((i_1178) >= (((int64_t)0LL)))) { if ((((((*({ hrv *_t3514 = &(g388); int64_t _i3514 = i_1178; (S6*)_t3514->b + hr_ix(_i3514, _t3514->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:658"); }))).node_) >= (((int32_t)0LL))) && ((((*({ hrv *_t3515 = &(g704); int64_t _i3515 = ((*({ hrv *_t3516 = &(g388); int64_t _i3516 = i_1178; (S6*)_t3516->b + hr_ix(_i3516, _t3516->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:658"); }))).node_; (S4*)_t3515->b + hr_ix(_i3515, _t3515->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:658"); }))).k_) == (((uint8_t)50LL))))) { return i_1178;
 }
i_1178 = ((int64_t)(((*({ hrv *_t3517 = &(g388); int64_t _i3517 = i_1178; (S6*)_t3517->b + hr_ix(_i3517, _t3517->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:658"); }))).par_));
 } _bk3513:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f222_ck_break(int64_t n_1189) {
S4 x_1190 = (*({ hrv *_t3518 = &(g704); int64_t _i3518 = n_1189; (S4*)_t3518->b + hr_ix(_i3518, _t3518->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:660"); })); 
if ((((x_1190).a_) >= (((int32_t)0LL)))) { if ((((g468).n) == (((int64_t)0LL)))) { (void)(f108_cerr(n_1189, hr_str("break with a value outside loop or block", 40)));
return g558;
 }
int64_t w_1191 = ((int64_t)((*({ hrv *_t3520 = &(g468); int64_t _i3520 = ((int64_t)((int64_t)(g468).n - (int64_t)((int64_t)1LL))); (int32_t*)_t3520->b + hr_ix(_i3520, _t3520->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:663"); })))); 
int64_t t_1192 = f137_ck(((int64_t)((x_1190).a_)), ({ int64_t _r3522; if (((w_1191) >= (((int64_t)0LL)))) { _r3522 = w_1191;  } else { _r3522 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3522; })); 
if (((w_1191) < (((int64_t)0LL)))) { { int32_t *_t3523 = &((*({ hrv *_t3524 = &(g468); int64_t _i3524 = ((int64_t)((int64_t)(g468).n - (int64_t)((int64_t)1LL))); (int32_t*)_t3524->b + hr_ix(_i3524, _t3524->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:665"); }))); *_t3523 = ((int32_t)(f184_default_t(((int64_t)((x_1190).a_))))); }
 } else { (void)(f140_conv(((int64_t)((x_1190).a_)), w_1191));
 }
 }
return f138_set_t(n_1189, g558);
}
static int64_t f223_ck_call(int64_t n_1193, int64_t want_1194) {
S4 x_1195 = (*({ hrv *_t3528 = &(g704); int64_t _i3528 = n_1193; (S4*)_t3528->b + hr_ix(_i3528, _t3528->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:256"); })); 
int64_t cal_1196 = ((int64_t)((x_1195).a_)); 
int64_t ck__1197 = ((int64_t)(((*({ hrv *_t3529 = &(g704); int64_t _i3529 = cal_1196; (S4*)_t3529->b + hr_ix(_i3529, _t3529->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:258"); }))).k_)); 
if (((ck__1197) == (((int64_t)8LL)))) { int64_t name_1198 = ((int64_t)(((*({ hrv *_t3530 = &(g704); int64_t _i3530 = cal_1196; (S4*)_t3530->b + hr_ix(_i3530, _t3530->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:260"); }))).s_)); 
int64_t v_1199 = f167_find_lv(name_1198); 
int64_t nf_1202 = f224_find_nest(name_1198); 
if ((((v_1199) < (((int64_t)0LL))) && ((nf_1202) >= (((int64_t)0LL))))) { return f225_call_nested(n_1193, nf_1202);
 }
if (((v_1199) < (((int64_t)0LL)))) { int64_t bg_1239 = f230_block_binding(name_1198); 
if (((bg_1239) >= (((int64_t)0LL)))) { return f235_call_block(n_1193, bg_1239);
 }
int64_t b_1269 = f237_builtin_of(f10_nm(name_1198)); 
if (((((b_1269) >= (((int64_t)0LL))) && (!((((b_1269) == (((int64_t)3LL))) && f238_user_format(n_1193))))) && (!((((b_1269) == (((int64_t)9LL))) && false))))) { return f240_ck_builtin(n_1193, b_1269, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), want_1194);
 }
return f254_call_fn(n_1193, name_1198, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), want_1194);
 }
 }
if (((ck__1197) == (((int64_t)14LL)))) { int64_t obj_1450 = ((int64_t)(((*({ hrv *_t3541 = &(g704); int64_t _i3541 = cal_1196; (S4*)_t3541->b + hr_ix(_i3541, _t3541->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:273"); }))).a_)); 
int64_t name_1451 = ((int64_t)(((*({ hrv *_t3542 = &(g704); int64_t _i3542 = cal_1196; (S4*)_t3542->b + hr_ix(_i3542, _t3542->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:274"); }))).s_)); 
if ((((((((*({ hrv *_t3543 = &(g704); int64_t _i3543 = obj_1450; (S4*)_t3543->b + hr_ix(_i3543, _t3543->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:275"); }))).k_) == (((uint8_t)8LL))) && ((f167_find_lv(((int64_t)(((*({ hrv *_t3545 = &(g704); int64_t _i3545 = obj_1450; (S4*)_t3545->b + hr_ix(_i3545, _t3545->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:275"); }))).s_)))) < (((int64_t)0LL)))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t3547 = &(g704); int64_t _i3547 = obj_1450; (S4*)_t3547->b + hr_ix(_i3547, _t3547->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:275"); }))).s_)), f110_ns_of(obj_1450), ((int64_t)2LL))) >= (((int64_t)0LL)))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t3550 = &(g704); int64_t _i3550 = obj_1450; (S4*)_t3550->b + hr_ix(_i3550, _t3550->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:275"); }))).s_)), f110_ns_of(obj_1450), ((int64_t)5LL))) < (((int64_t)0LL))))) { (void)(f108_cerr(n_1193, hr_str("a variant is constructed with { }", 33)));
return f138_set_t(n_1193, g575);
 }
int64_t ot_1452 = f137_ck(obj_1450, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3555 = &(g551); int64_t _i3555 = ot_1452; (S1*)_t3555->b + hr_ix(_i3555, _t3555->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:277"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(obj_1450, g576));
ot_1452 = g576;
 }
int64_t d_1453 = f179_deref(ot_1452); 
int64_t mb_1455 = f255_member_of(f10_nm(name_1451)); 
if ((((mb_1455) >= (((int64_t)0LL))) && (((((*({ hrv *_t3560 = &(g551); int64_t _i3560 = d_1453; (S1*)_t3560->b + hr_ix(_i3560, _t3560->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:280"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3561 = &(g551); int64_t _i3561 = d_1453; (S1*)_t3561->b + hr_ix(_i3561, _t3561->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:280"); }))).k_) == (((uint8_t)9LL)))))) { return f240_ck_builtin(n_1193, mb_1455, obj_1450, want_1194);
 }
if (((((((*({ hrv *_t3563 = &(g551); int64_t _i3563 = ot_1452; (S1*)_t3563->b + hr_ix(_i3563, _t3563->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:281"); }))).k_) == (((uint8_t)19LL))) || ((((*({ hrv *_t3564 = &(g551); int64_t _i3564 = ot_1452; (S1*)_t3564->b + hr_ix(_i3564, _t3564->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:281"); }))).k_) == (((uint8_t)12LL)))) || ((((*({ hrv *_t3565 = &(g551); int64_t _i3565 = ot_1452; (S1*)_t3565->b + hr_ix(_i3565, _t3565->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:281"); }))).k_) == (((uint8_t)13LL))))) { (void)(f184_default_t(obj_1450));
 }
int64_t b_1456 = f237_builtin_of(f10_nm(name_1451)); 
if ((((((b_1456) == (((int64_t)3LL))) || ((b_1456) == (((int64_t)30LL)))) || ((b_1456) == (((int64_t)31LL)))) || ((b_1456) == (((int64_t)7LL))))) { return f240_ck_builtin(n_1193, b_1456, obj_1450, want_1194);
 }
(void)(f175_set_x(n_1193, ((int64_t)1LL)));
return f254_call_fn(n_1193, name_1451, obj_1450, want_1194);
 }
(void)(f108_cerr(n_1193, hr_str("this call's callee is not supported yet", 39)));
return f138_set_t(n_1193, g575);
}
static int64_t f224_find_nest(int64_t name_1200) {
int64_t i_1201 = ((int64_t)((int64_t)(g312).n - (int64_t)((int64_t)1LL))); 
while (((i_1201) >= (((int64_t)0LL)))) { if ((((((int64_t)(((*({ hrv *_t3575 = &(g312); int64_t _i3575 = i_1201; (S14*)_t3575->b + hr_ix(_i3575, _t3575->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:23"); }))).name_))) == (name_1200)) && f168_visible(((int64_t)(((*({ hrv *_t3577 = &(g312); int64_t _i3577 = i_1201; (S14*)_t3577->b + hr_ix(_i3577, _t3577->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:23"); }))).own_))))) { return i_1201;
 }
i_1201--;
 } _bk3574:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f225_call_nested(int64_t n_1203, int64_t nf_1204) {
int64_t i_1205 = ((int64_t)(((*({ hrv *_t3578 = &(g312); int64_t _i3578 = nf_1204; (S14*)_t3578->b + hr_ix(_i3578, _t3578->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:372"); }))).inst_)); 
int64_t s_1212 = f226_ck_args(n_1203, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
{ int32_t _e3581 = ((*({ hrv *_t3582 = &(g704); int64_t _i3582 = n_1203; (S4*)_t3582->b + hr_ix(_i3582, _t3582->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:374"); }))).n_; for (int32_t _k3581 = 0; _k3581 < _e3581; _k3581++) { int32_t j_1213 = (int32_t)_k3581; int64_t c_1214 = f90_kid(n_1203, ((int64_t)(j_1213))); 
if (((((int64_t)(j_1213))) < (((int64_t)(((*({ hrv *_t3584 = &(g388); int64_t _i3584 = i_1205; (S6*)_t3584->b + hr_ix(_i3584, _t3584->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:374"); }))).pn_))))) { (void)(f140_conv(c_1214, f208_ptype_of(i_1205, ((int64_t)(j_1213)))));
 }
 } } _bk3580:; 
(void)(f227_pop_args(s_1212));
(void)(f228_note_caps_of(i_1205));
(void)(f229_note_edge(i_1205));
(void)(f170_set_r(n_1203, ((int64_t)3LL), i_1205));
return f138_set_t(n_1203, ({ int64_t _r3592; if (((((*({ hrv *_t3593 = &(g388); int64_t _i3593 = i_1205; (S6*)_t3593->b + hr_ix(_i3593, _t3593->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:378"); }))).ret_) >= (((int32_t)0LL)))) { _r3592 = ((int64_t)(((*({ hrv *_t3594 = &(g388); int64_t _i3594 = i_1205; (S6*)_t3594->b + hr_ix(_i3594, _t3594->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:378"); }))).ret_));  } else { _r3592 = g558;  } _r3592; }));
}
static int64_t f226_ck_args(int64_t n_1206, int64_t a0n_1207, int64_t first_1208) {
int64_t start_1209 = (g408).n; 
if (((first_1208) >= (((int64_t)0LL)))) { (void)(({ hrv *_v3595 = &(g408); int32_t _x3595 = ((int32_t)(f141_at(first_1208))); int32_t *_p3595 = (int32_t*)hr_grow(_v3595, 1, sizeof _x3595); *_p3595 = _x3595; _p3595; }));
(void)(({ hrv *_v3597 = &(g316); int32_t _x3597 = ((int32_t)(first_1208)); int32_t *_p3597 = (int32_t*)hr_grow(_v3597, 1, sizeof _x3597); *_p3597 = _x3597; _p3597; }));
 }
{ int32_t _e3599 = ((*({ hrv *_t3600 = &(g704); int64_t _i3600 = n_1206; (S4*)_t3600->b + hr_ix(_i3600, _t3600->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:251"); }))).n_; for (int32_t _k3599 = 0; _k3599 < _e3599; _k3599++) { int32_t i_1210 = (int32_t)_k3599; int64_t c_1211 = f90_kid(n_1206, ((int64_t)(i_1210))); 
(void)(({ hrv *_v3602 = &(g408); int32_t _x3602 = ((int32_t)(f137_ck(c_1211, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p3602 = (int32_t*)hr_grow(_v3602, 1, sizeof _x3602); *_p3602 = _x3602; _p3602; }));
(void)(({ hrv *_v3604 = &(g316); int32_t _x3604 = ((int32_t)(c_1211)); int32_t *_p3604 = (int32_t*)hr_grow(_v3604, 1, sizeof _x3604); *_p3604 = _x3604; _p3604; }));
 } } _bk3598:; 
return start_1209;
}
static void f227_pop_args(int64_t s_1215) {
(void)(({ hrv *_v3605 = &(g408); int64_t _k3605 = ((int64_t)((int64_t)(g408).n - (int64_t)s_1215)); if (_k3605 < 0 || _k3605 > _v3605->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:254"); _v3605->n -= _k3605; }));
(void)(({ hrv *_v3606 = &(g316); int64_t _k3606 = ((int64_t)((int64_t)(g316).n - (int64_t)s_1215)); if (_k3606 < 0 || _k3606 > _v3606->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:254"); _v3606->n -= _k3606; }));
}
static void f228_note_caps_of(int64_t i_1216) {
{ hrv *_v3608 = &(g392); for (int64_t _k3608 = 0; _k3608 < _v3608->n; _k3608++) { S13 c_1217 = ((S13*)_v3608->b)[_k3608]; if (((((int64_t)((c_1217).inst_))) == (i_1216))) { int64_t v_1218 = ((int64_t)((c_1217).lv_)); 
if (((((int64_t)(((*({ hrv *_t3609 = &(g389); int64_t _i3609 = v_1218; (S12*)_t3609->b + hr_ix(_i3609, _t3609->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:381"); }))).cfn_))) != (g402))) { (void)(f171_note_cap(v_1218));
 }
 }
 } } _bk3607:; 
}
static void f229_note_edge(int64_t callee_1219) {
if (((((g402) < (((int64_t)0LL))) || ((callee_1219) < (((int64_t)0LL)))) || ((g402) == (callee_1219)))) { return;
 }
{ hrv *_v3612 = &(g393); for (int64_t _k3612 = 0; _k3612 < _v3612->n; _k3612++) { S15 e_1220 = ((S15*)_v3612->b)[_k3612]; if ((((((int64_t)((e_1220).caller_))) == (g402)) && ((((int64_t)((e_1220).callee_))) == (callee_1219)))) { return;
 }
 } } _bk3611:; 
(void)(({ hrv *_v3613 = &(g393); S15 _x3613 = ((S15){ .caller_ = ((int32_t)(g402)), .callee_ = ((int32_t)(callee_1219)), }); S15 *_p3613 = (S15*)hr_grow(_v3613, 1, sizeof _x3613); *_p3613 = _x3613; _p3613; }));
}
static int64_t f230_block_binding(int64_t name_1221) {
int64_t i_1222 = g401; 
while (((i_1222) >= (((int64_t)0LL)))) { S6 f_1223 = (*({ hrv *_t3615 = &(g388); int64_t _i3615 = i_1222; (S6*)_t3615->b + hr_ix(_i3615, _t3615->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:334"); })); 
if ((((f_1223).blk_) >= (((int32_t)0LL)))) { int64_t fnode_1224 = ((int64_t)((f_1223).node_)); 
if (((f231_blk_gen(fnode_1224)) == (name_1221))) { return i_1222;
 }
 }
i_1222 = ((int64_t)((f_1223).par_));
 } _bk3614:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f231_blk_gen(int64_t fnode_1225) {
int64_t gl_1227 = f232_gen_list(fnode_1225); 
if (((gl_1227) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
{ int32_t _e3619 = ((*({ hrv *_t3620 = &(g704); int64_t _i3620 = gl_1227; (S4*)_t3620->b + hr_ix(_i3620, _t3620->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:59"); }))).n_; for (int32_t _k3619 = 0; _k3619 < _e3619; _k3619++) { int32_t i_1228 = (int32_t)_k3619; int64_t g_1229 = ((int64_t)(((*({ hrv *_t3621 = &(g704); int64_t _i3621 = f90_kid(gl_1227, ((int64_t)(i_1228))); (S4*)_t3621->b + hr_ix(_i3621, _t3621->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:59"); }))).s_)); 
if (f233_is_blockparam(fnode_1225, g_1229)) { return g_1229;
 }
 } } _bk3618:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f232_gen_list(int64_t fnode_1226) {
return ((int64_t)(((*({ hrv *_t3624 = &(g704); int64_t _i3624 = fnode_1226; (S4*)_t3624->b + hr_ix(_i3624, _t3624->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:47"); }))).d_));
}
static bool f233_is_blockparam(int64_t fnode_1230, int64_t gname_1231) {
{ int32_t _e3626 = ((*({ hrv *_t3627 = &(g704); int64_t _i3627 = fnode_1230; (S4*)_t3627->b + hr_ix(_i3627, _t3627->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:49"); }))).n_; for (int32_t _k3626 = 0; _k3626 < _e3626; _k3626++) { int32_t i_1232 = (int32_t)_k3626; int64_t p_1233 = f90_kid(fnode_1230, ((int64_t)(i_1232))); 
if ((((((*({ hrv *_t3629 = &(g704); int64_t _i3629 = p_1233; (S4*)_t3629->b + hr_ix(_i3629, _t3629->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:49"); }))).a_) >= (((int32_t)0LL))) && f234_mentions(((int64_t)(((*({ hrv *_t3631 = &(g704); int64_t _i3631 = p_1233; (S4*)_t3631->b + hr_ix(_i3631, _t3631->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:49"); }))).a_)), gname_1231))) { return false;
 }
 } } _bk3625:; 
return true;
}
static bool f234_mentions(int64_t t_1234, int64_t g_1235) {
if (((t_1234) < (((int64_t)0LL)))) { return false;
 }
S4 x_1236 = (*({ hrv *_t3632 = &(g704); int64_t _i3632 = t_1234; (S4*)_t3632->b + hr_ix(_i3632, _t3632->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:54"); })); 
int64_t k_1237 = ((int64_t)((x_1236).k_)); 
if (((k_1237) == (((int64_t)41LL)))) { if (((((int64_t)((x_1236).s_))) == (g_1235))) { return true;
 }
{ int32_t _e3634 = (x_1236).n_; for (int32_t _k3634 = 0; _k3634 < _e3634; _k3634++) { int32_t i_1238 = (int32_t)_k3634; if (f234_mentions(f90_kid(t_1234, ((int64_t)(i_1238))), g_1235)) { return true;
 }
 } } _bk3633:; 
return false;
 }
if (((((((k_1237) == (((int64_t)42LL))) || ((k_1237) == (((int64_t)43LL)))) || ((k_1237) == (((int64_t)44LL)))) || ((k_1237) == (((int64_t)48LL)))) || ((k_1237) == (((int64_t)46LL))))) { return f234_mentions(((int64_t)((x_1236).a_)), g_1235);
 }
return false;
}
static int64_t f235_call_block(int64_t n_1240, int64_t inst_1241) {
int64_t fv_1242 = ((int64_t)(((*({ hrv *_t3638 = &(g388); int64_t _i3638 = inst_1241; (S6*)_t3638->b + hr_ix(_i3638, _t3638->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:341"); }))).blk_)); 
int64_t own_1243 = ((int64_t)(((*({ hrv *_t3639 = &(g388); int64_t _i3639 = inst_1241; (S6*)_t3639->b + hr_ix(_i3639, _t3639->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:342"); }))).bown_)); 
int64_t s_1244 = f226_ck_args(n_1240, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t na_1245 = ((int64_t)(((*({ hrv *_t3641 = &(g704); int64_t _i3641 = n_1240; (S4*)_t3641->b + hr_ix(_i3641, _t3641->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:344"); }))).n_)); 
{ int64_t _e3643 = na_1245; for (int64_t _k3643 = 0; _k3643 < _e3643; _k3643++) { int64_t j_1246 = (int64_t)_k3643; int64_t c_1247 = f90_kid(n_1240, j_1246); 
if (f163_is_pending(f141_at(c_1247))) { { int32_t *_t3647 = &((*({ hrv *_t3648 = &(g408); int64_t _i3648 = ((int64_t)((int64_t)s_1244 + (int64_t)j_1246)); (int32_t*)_t3648->b + hr_ix(_i3648, _t3648->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:345"); }))); *_t3647 = ((int32_t)(f184_default_t(c_1247))); }
 } else { { int32_t *_t3650 = &((*({ hrv *_t3651 = &(g408); int64_t _i3651 = ((int64_t)((int64_t)s_1244 + (int64_t)j_1246)); (int32_t*)_t3651->b + hr_ix(_i3651, _t3651->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:345"); }))); *_t3650 = ((int32_t)(f236_deref_val(f141_at(c_1247)))); }
 }
 } } _bk3642:; 
int64_t bi_1250 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v3655 = &(g388); for (int64_t _k3655 = 0; _k3655 < _v3655->n; _k3655++) { S6 f_1251 = ((S6*)_v3655->b)[_k3655]; int64_t i_1252 = (int64_t)_k3655; if (((((((int64_t)((f_1251).node_))) == (fv_1242)) && ((((int64_t)((f_1251).par_))) == (own_1243))) && (((f_1251).blk_) == (((int32_t)(inst_1241)))))) { bi_1250 = i_1252;
 }
 } } _bk3654:; 
if (((bi_1250) < (((int64_t)0LL)))) { bi_1250 = f105_new_inst(fv_1242, fv_1242, ((int64_t)((*({ hrv *_t3657 = &(g719); int64_t _i3657 = fv_1242; (int32_t*)_t3657->b + hr_ix(_i3657, _t3657->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:349"); })))), own_1243);
{ int32_t *_t3658 = &(((*({ hrv *_t3659 = &(g388); int64_t _i3659 = bi_1250; (S6*)_t3659->b + hr_ix(_i3659, _t3659->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:350"); }))).blk_); *_t3658 = ((int32_t)(inst_1241)); }
{ int32_t *_t3660 = &(((*({ hrv *_t3661 = &(g388); int64_t _i3661 = bi_1250; (S6*)_t3661->b + hr_ix(_i3661, _t3661->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:350"); }))).bown_); *_t3660 = ((int32_t)(own_1243)); }
{ int32_t *_t3662 = &(((*({ hrv *_t3663 = &(g388); int64_t _i3663 = bi_1250; (S6*)_t3663->b + hr_ix(_i3663, _t3663->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:351"); }))).cfn_); *_t3662 = ((int32_t)(g402)); }
int64_t sa_1253 = g401; 
int64_t sm_1254 = (g390).n; 
int64_t bt_1255 = (g468).n; 
int64_t ld_1256 = g407; 
g401 = bi_1250;
g407 = ((int64_t)0LL);
int64_t np_1257 = ((int64_t)(((*({ hrv *_t3664 = &(g704); int64_t _i3664 = fv_1242; (S4*)_t3664->b + hr_ix(_i3664, _t3664->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:354"); }))).n_)); 
if (((((uint16_t)((uint64_t)((*({ hrv *_t3665 = &(g704); int64_t _i3665 = fv_1242; (S4*)_t3665->b + hr_ix(_i3665, _t3665->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:355"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { int64_t _e3667 = np_1257; for (int64_t _k3667 = 0; _k3667 < _e3667; _k3667++) { int64_t j_1258 = (int64_t)_k3667; int64_t p_1259 = f90_kid(fv_1242, j_1258); 
int64_t pt_1260 = ({ int64_t _r3669; if (((j_1258) < (na_1245))) { _r3669 = ((int64_t)((*({ hrv *_t3670 = &(g408); int64_t _i3670 = ((int64_t)((int64_t)s_1244 + (int64_t)j_1258)); (int32_t*)_t3670->b + hr_ix(_i3670, _t3670->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:355"); }))));  } else { _r3669 = g575;  } _r3669; }); 
int64_t v_1261 = f203_add_lv(((int64_t)(((*({ hrv *_t3672 = &(g704); int64_t _i3672 = p_1259; (S4*)_t3672->b + hr_ix(_i3672, _t3672->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:355"); }))).s_)), pt_1260, ((int64_t)32LL), p_1259); 
(void)(f170_set_r(p_1259, ((int64_t)1LL), v_1261));
 } } _bk3666:; 
 } else { if (((na_1245) >= (((int64_t)1LL)))) { int64_t v_1262 = f203_add_lv(f8_intern(hr_str("it", 2)), ((int64_t)((*({ hrv *_t3676 = &(g408); int64_t _i3676 = s_1244; (int32_t*)_t3676->b + hr_ix(_i3676, _t3676->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:356"); })))), ((int64_t)32LL), fv_1242); 
(void)(f170_set_r(fv_1242, ((int64_t)1LL), v_1262));
 }
 }
int64_t body_1263 = ((int64_t)(((*({ hrv *_t3678 = &(g704); int64_t _i3678 = fv_1242; (S4*)_t3678->b + hr_ix(_i3678, _t3678->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:357"); }))).a_)); 
int64_t bt0_1264 = f137_ck(body_1263, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t rt_1265 = g558; 
if ((((((*({ hrv *_t3680 = &(g704); int64_t _i3680 = body_1263; (S4*)_t3680->b + hr_ix(_i3680, _t3680->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:360"); }))).a_) >= (((int32_t)0LL))) && ((bt0_1264) != (g558)))) { rt_1265 = ({ int64_t _r3681; if (f163_is_pending(bt0_1264)) { _r3681 = f184_default_t(((int64_t)(((*({ hrv *_t3684 = &(g704); int64_t _i3684 = body_1263; (S4*)_t3684->b + hr_ix(_i3684, _t3684->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:360"); }))).a_)));  } else { _r3681 = bt0_1264;  } _r3681; });
 }
{ int32_t *_t3685 = &(((*({ hrv *_t3686 = &(g388); int64_t _i3686 = bi_1250; (S6*)_t3686->b + hr_ix(_i3686, _t3686->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:361"); }))).ret_); *_t3685 = ((int32_t)(rt_1265)); }
(void)(({ hrv *_v3687 = &(g390); int64_t _k3687 = ((int64_t)((int64_t)(g390).n - (int64_t)sm_1254)); if (_k3687 < 0 || _k3687 > _v3687->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:362"); _v3687->n -= _k3687; }));
while ((((g468).n) > (bt_1255))) { (void)(({ hrv *_v3689 = &(g468); if (!_v3689->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:362"); ((int32_t*)_v3689->b)[--_v3689->n]; }));
 } _bk3688:; 
g401 = sa_1253;
g407 = ld_1256;
{ uint8_t *_t3690 = &(((*({ hrv *_t3691 = &(g388); int64_t _i3691 = bi_1250; (S6*)_t3691->b + hr_ix(_i3691, _t3691->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:364"); }))).st_); *_t3690 = ((uint8_t)2LL); }
 }
{ int64_t _e3693 = na_1245; for (int64_t _k3693 = 0; _k3693 < _e3693; _k3693++) { int64_t j_1266 = (int64_t)_k3693; int64_t c_1267 = f90_kid(n_1240, j_1266); 
if (f163_is_pending(f141_at(c_1267))) { (void)(f184_default_t(c_1267));
 }
 } } _bk3692:; 
(void)(f227_pop_args(s_1244));
(void)(f170_set_r(n_1240, ((int64_t)10LL), bi_1250));
return f138_set_t(n_1240, ((int64_t)(((*({ hrv *_t3701 = &(g388); int64_t _i3701 = bi_1250; (S6*)_t3701->b + hr_ix(_i3701, _t3701->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:369"); }))).ret_)));
}
static int64_t f236_deref_val(int64_t a_1248) {
int64_t d_1249 = f179_deref(a_1248); 
return ({ int64_t _r3703; if (((((*({ hrv *_t3704 = &(g551); int64_t _i3704 = d_1249; (S1*)_t3704->b + hr_ix(_i3704, _t3704->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:246"); }))).k_) == (((uint8_t)18LL)))) { _r3703 = g576;  } else { _r3703 = ({ int64_t _r3705; if (((((*({ hrv *_t3706 = &(g551); int64_t _i3706 = d_1249; (S1*)_t3706->b + hr_ix(_i3706, _t3706->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:246"); }))).k_) == (((uint8_t)7LL)))) { _r3705 = f136_t_enum(((int64_t)(((*({ hrv *_t3708 = &(g551); int64_t _i3708 = d_1249; (S1*)_t3708->b + hr_ix(_i3708, _t3708->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:246"); }))).a_)), false);  } else { _r3705 = d_1249;  } _r3705; });  } _r3703; });
}
static int64_t f237_builtin_of(hsl name_1268) {
if (hr_streq(name_1268, hr_str("print", 5))) { return ((int64_t)1LL);
 }
if (hr_streq(name_1268, hr_str("str", 3))) { return ((int64_t)2LL);
 }
if (hr_streq(name_1268, hr_str("format", 6))) { return ((int64_t)3LL);
 }
if (hr_streq(name_1268, hr_str("assert", 6))) { return ((int64_t)4LL);
 }
if (hr_streq(name_1268, hr_str("abort", 5))) { return ((int64_t)5LL);
 }
if (hr_streq(name_1268, hr_str("exit", 4))) { return ((int64_t)6LL);
 }
if (hr_streq(name_1268, hr_str("copy", 4))) { return ((int64_t)7LL);
 }
if (hr_streq(name_1268, hr_str("default", 7))) { return ((int64_t)8LL);
 }
if (hr_streq(name_1268, hr_str("to_bytes", 8))) { return ((int64_t)30LL);
 }
if (hr_streq(name_1268, hr_str("bytes_of", 8))) { return ((int64_t)31LL);
 }
if (hr_streq(name_1268, hr_str("from_bytes", 10))) { return ((int64_t)32LL);
 }
if (hr_streq(name_1268, hr_str("embed_file", 10))) { return ((int64_t)33LL);
 }
if (hr_streq(name_1268, hr_str("len", 3))) { return ((int64_t)9LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f238_user_format(int64_t n_1270) {
if (((((*({ hrv *_t3709 = &(g704); int64_t _i3709 = n_1270; (S4*)_t3709->b + hr_ix(_i3709, _t3709->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:290"); }))).n_) == (((int32_t)0LL)))) { return false;
 }
int64_t t_1271 = f179_deref(f137_ck(f90_kid(n_1270, ((int64_t)0LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))); 
return (!(((((((*({ hrv *_t3713 = &(g551); int64_t _i3713 = t_1271; (S1*)_t3713->b + hr_ix(_i3713, _t3713->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:290"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t3714 = &(g551); int64_t _i3714 = t_1271; (S1*)_t3714->b + hr_ix(_i3714, _t3714->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:290"); }))).a_))) == (g564))) && (f239_is_grow(t_1271) || ((((int64_t)(((*({ hrv *_t3716 = &(g551); int64_t _i3716 = t_1271; (S1*)_t3716->b + hr_ix(_i3716, _t3716->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:290"); }))).s_))) == (((int64_t)3LL)))))));
}
static bool f239_is_grow(int64_t t_1272) {
return (((((int64_t)(((*({ hrv *_t3717 = &(g551); int64_t _i3717 = t_1272; (S1*)_t3717->b + hr_ix(_i3717, _t3717->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:291"); }))).s_))) == (((int64_t)4LL))) || ((((int64_t)(((*({ hrv *_t3718 = &(g551); int64_t _i3718 = t_1272; (S1*)_t3718->b + hr_ix(_i3718, _t3718->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:291"); }))).s_))) == (((int64_t)5LL))));
}
static int64_t f240_ck_builtin(int64_t n_1273, int64_t b_1274, int64_t recv_1275, int64_t want_1276) {
S4 x_1277 = (*({ hrv *_t3719 = &(g704); int64_t _i3719 = n_1273; (S4*)_t3719->b + hr_ix(_i3719, _t3719->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:408"); })); 
(void)(f170_set_r(n_1273, ((int64_t)4LL), b_1274));
(void)(f175_set_x(n_1273, ({ int64_t _r3722; if (((recv_1275) >= (((int64_t)0LL)))) { _r3722 = ((int64_t)1LL);  } else { _r3722 = ((int64_t)0LL);  } _r3722; })));
int64_t na_1278 = ((int64_t)((x_1277).n_)); 

int64_t total_1280 = ((int64_t)((int64_t)na_1278 + (int64_t)({ int64_t _r3723; if (((recv_1275) >= (((int64_t)0LL)))) { _r3723 = ((int64_t)1LL);  } else { _r3723 = ((int64_t)0LL);  } _r3723; }))); 
int64_t need_1281 = ({ int64_t _r3724; if (((((((b_1274) == (((int64_t)1LL))) || ((b_1274) == (((int64_t)2LL)))) || ((b_1274) == (((int64_t)8LL)))) || ((b_1274) == (((int64_t)22LL)))) || ((b_1274) == (((int64_t)25LL))))) { _r3724 = ((int64_t)0LL);  } else { _r3724 = ({ int64_t _r3725; if (((((((b_1274) == (((int64_t)20LL))) || ((b_1274) == (((int64_t)21LL)))) || ((b_1274) == (((int64_t)23LL)))) || ((b_1274) == (((int64_t)24LL)))) || ((b_1274) == (((int64_t)26LL))))) { _r3725 = ((int64_t)2LL);  } else { _r3725 = ((int64_t)1LL);  } _r3725; });  } _r3724; }); 
if (((total_1280) < (need_1281))) { (void)(f108_cerr(n_1273, hr_str("too few arguments to a builtin", 30)));
return f138_set_t(n_1273, g575);
 }
if ((((b_1274) == (((int64_t)1LL))) || ((b_1274) == (((int64_t)2LL))))) { { int64_t _e3729 = na_1278; for (int64_t _k3729 = 0; _k3729 < _e3729; _k3729++) { int64_t i_1282 = (int64_t)_k3729; int64_t c_1283 = f90_kid(n_1273, i_1282); 
int64_t t_1284 = f137_ck(c_1283, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f163_is_pending(t_1284)) { (void)(f184_default_t(c_1283));
 }
(void)(f242_hook_walk(f202_fin_t(c_1283)));
 } } _bk3728:; 
return f138_set_t(n_1273, ({ int64_t _r3737; if (((b_1274) == (((int64_t)2LL)))) { _r3737 = f123_t_arr(g564, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));  } else { _r3737 = g558;  } _r3737; }));
 }
if (((b_1274) == (((int64_t)3LL)))) { int64_t o_1410 = f241_arg(((int64_t)0LL), &recv_1275, &n_1273); 
if (((recv_1275) < (((int64_t)0LL)))) { (void)(f137_ck(o_1410, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
{ int64_t _e3742 = total_1280; for (int64_t _k3742 = ((int64_t)1LL); _k3742 < _e3742; _k3742++) { int64_t i_1411 = (int64_t)_k3742; int64_t c_1412 = f241_arg(i_1411, &recv_1275, &n_1273); 
int64_t t_1413 = f137_ck(c_1412, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f163_is_pending(t_1413)) { (void)(f184_default_t(c_1412));
 }
(void)(f242_hook_walk(f202_fin_t(c_1412)));
 } } _bk3741:; 
return f138_set_t(n_1273, g558);
 }
if (((b_1274) == (((int64_t)4LL)))) { (void)(f137_ck(f241_arg(((int64_t)0LL), &recv_1275, &n_1273), g559));
(void)(f140_conv(f241_arg(((int64_t)0LL), &recv_1275, &n_1273), g559));
return f138_set_t(n_1273, g558);
 }
if (((b_1274) == (((int64_t)5LL)))) { int64_t t_1414 = f137_ck(f241_arg(((int64_t)0LL), &recv_1275, &n_1273), g576); 
if (f163_is_pending(t_1414)) { (void)(f184_default_t(f241_arg(((int64_t)0LL), &recv_1275, &n_1273)));
 }
return f138_set_t(n_1273, g558);
 }
if (((b_1274) == (((int64_t)6LL)))) { (void)(f137_ck(f241_arg(((int64_t)0LL), &recv_1275, &n_1273), g563));
(void)(f140_conv(f241_arg(((int64_t)0LL), &recv_1275, &n_1273), g563));
return f138_set_t(n_1273, g558);
 }
if (((b_1274) == (((int64_t)8LL)))) { int64_t ta_1415 = ((int64_t)((x_1277).c_)); 
if (((ta_1415) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1273, hr_str("default needs a type: default<T>()", 34)));
return f138_set_t(n_1273, g575);
 }
return f138_set_t(n_1273, f113_rtype(f90_kid(ta_1415, ((int64_t)0LL)), f110_ns_of(n_1273)));
 }
if (((b_1274) == (((int64_t)7LL)))) { int64_t c_1416 = f241_arg(((int64_t)0LL), &recv_1275, &n_1273); 
if (((recv_1275) < (((int64_t)0LL)))) { (void)(f137_ck(c_1416, want_1276));
 }
int64_t t_1417 = f141_at(c_1416); 
if (f163_is_pending(t_1417)) { t_1417 = f184_default_t(c_1416);
 }
int64_t d_1418 = f179_deref(t_1417); 
int64_t k_1419 = ((int64_t)(((*({ hrv *_t3778 = &(g551); int64_t _i3778 = d_1418; (S1*)_t3778->b + hr_ix(_i3778, _t3778->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:436"); }))).k_)); 
if (((k_1419) == (((int64_t)9LL)))) { return f138_set_t(n_1273, f123_t_arr(((int64_t)(((*({ hrv *_t3781 = &(g551); int64_t _i3781 = d_1418; (S1*)_t3781->b + hr_ix(_i3781, _t3781->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:437"); }))).a_)), ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
return f138_set_t(n_1273, d_1418);
 }
if (((b_1274) == (((int64_t)9LL)))) { int64_t c_1420 = f241_arg(((int64_t)0LL), &recv_1275, &n_1273); 
if (((recv_1275) < (((int64_t)0LL)))) { (void)(f137_ck(c_1420, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (((((*({ hrv *_t3785 = &(g551); int64_t _i3785 = f141_at(c_1420); (S1*)_t3785->b + hr_ix(_i3785, _t3785->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:440"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(c_1420, g576));
 }
return f138_set_t(n_1273, g563);
 }
if (((b_1274) == (((int64_t)31LL)))) { int64_t c_1421 = f241_arg(((int64_t)0LL), &recv_1275, &n_1273); 
if (((recv_1275) < (((int64_t)0LL)))) { (void)(f137_ck(c_1421, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (f163_is_pending(f141_at(c_1421))) { (void)(f184_default_t(c_1421));
 }
return f138_set_t(n_1273, g576);
 }
if (((b_1274) == (((int64_t)30LL)))) { int64_t c_1422 = f241_arg(((int64_t)0LL), &recv_1275, &n_1273); 
if (((recv_1275) < (((int64_t)0LL)))) { (void)(f137_ck(c_1422, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (f163_is_pending(f141_at(c_1422))) { (void)(f184_default_t(c_1422));
 }
if (((total_1280) > (((int64_t)1LL)))) { (void)(f137_ck(f241_arg(((int64_t)1LL), &recv_1275, &n_1273), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_1273, g558);
 }
return f138_set_t(n_1273, f123_t_arr(g564, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (((b_1274) == (((int64_t)32LL)))) { int64_t ta_1423 = ((int64_t)((x_1277).c_)); 
int64_t t_1424 = ({ int64_t _r3805; if (((ta_1423) >= (((int64_t)0LL)))) { _r3805 = f113_rtype(f90_kid(ta_1423, ((int64_t)0LL)), f110_ns_of(n_1273));  } else { _r3805 = g575;  } _r3805; }); 
(void)(f137_ck(f241_arg(((int64_t)0LL), &recv_1275, &n_1273), g576));
if (f163_is_pending(f141_at(f241_arg(((int64_t)0LL), &recv_1275, &n_1273)))) { (void)(f184_default_t(f241_arg(((int64_t)0LL), &recv_1275, &n_1273)));
 }
return f138_set_t(n_1273, t_1424);
 }
if (((b_1274) == (((int64_t)33LL)))) { (void)(f137_ck(f241_arg(((int64_t)0LL), &recv_1275, &n_1273), g576));
(void)(f184_default_t(f241_arg(((int64_t)0LL), &recv_1275, &n_1273)));
return f138_set_t(n_1273, g576);
 }
int64_t r_1425 = recv_1275; 
int64_t rt_1426 = f179_deref(f141_at(r_1425)); 
int64_t e_1427 = ((int64_t)(((*({ hrv *_t3824 = &(g551); int64_t _i3824 = rt_1426; (S1*)_t3824->b + hr_ix(_i3824, _t3824->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:447"); }))).a_)); 
if (((b_1274) == (((int64_t)20LL)))) { if (((total_1280) != (((int64_t)2LL)))) { (void)(f108_cerr(n_1273, hr_str("push takes one value", 20)));
return f138_set_t(n_1273, g575);
 }
int64_t c_1428 = f241_arg(((int64_t)1LL), &recv_1275, &n_1273); 
(void)(f137_ck(c_1428, e_1427));
(void)(f140_conv(c_1428, e_1427));
return f138_set_t(n_1273, f119_t_ref(e_1427, ((int64_t)0LL)));
 }
if (((b_1274) == (((int64_t)21LL)))) { int64_t c_1429 = f241_arg(((int64_t)1LL), &recv_1275, &n_1273); 
int64_t t_1430 = f137_ck(c_1429, f18_t_slice(e_1427, true)); 
if (((((*({ hrv *_t3835 = &(g551); int64_t _i3835 = t_1430; (S1*)_t3835->b + hr_ix(_i3835, _t3835->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:449"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(c_1429, g576));
 } else { if (((((*({ hrv *_t3837 = &(g551); int64_t _i3837 = t_1430; (S1*)_t3837->b + hr_ix(_i3837, _t3837->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:449"); }))).k_) == (((uint8_t)19LL)))) { (void)(f140_conv(c_1429, f123_t_arr(e_1427, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
 } else { int64_t dt_1431 = f179_deref(t_1430); 
if (((((((*({ hrv *_t3841 = &(g551); int64_t _i3841 = dt_1431; (S1*)_t3841->b + hr_ix(_i3841, _t3841->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:449"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3842 = &(g551); int64_t _i3842 = dt_1431; (S1*)_t3842->b + hr_ix(_i3842, _t3842->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:449"); }))).k_) == (((uint8_t)9LL)))) && ((((int64_t)(((*({ hrv *_t3843 = &(g551); int64_t _i3843 = dt_1431; (S1*)_t3843->b + hr_ix(_i3843, _t3843->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:449"); }))).a_))) != (e_1427)))) { (void)(f108_cerr(c_1429, hr_str("append of a different element type", 34)));
 }
 }
 }
return f138_set_t(n_1273, g558);
 }
if (((b_1274) == (((int64_t)22LL)))) { return f138_set_t(n_1273, e_1427);
 }
if (((b_1274) == (((int64_t)23LL)))) { (void)(f137_ck(f241_arg(((int64_t)1LL), &recv_1275, &n_1273), g563));
(void)(f140_conv(f241_arg(((int64_t)1LL), &recv_1275, &n_1273), g563));
return f138_set_t(n_1273, g558);
 }
if (((b_1274) == (((int64_t)24LL)))) { (void)(f137_ck(f241_arg(((int64_t)1LL), &recv_1275, &n_1273), g563));
(void)(f140_conv(f241_arg(((int64_t)1LL), &recv_1275, &n_1273), g563));
if (((total_1280) > (((int64_t)2LL)))) { (void)(f137_ck(f241_arg(((int64_t)2LL), &recv_1275, &n_1273), e_1427));
(void)(f140_conv(f241_arg(((int64_t)2LL), &recv_1275, &n_1273), e_1427));
 }
return f138_set_t(n_1273, g558);
 }
if (((b_1274) == (((int64_t)25LL)))) { return f138_set_t(n_1273, g558);
 }
if (((b_1274) == (((int64_t)26LL)))) { (void)(f137_ck(f241_arg(((int64_t)1LL), &recv_1275, &n_1273), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_1273, g563);
 }
return f138_set_t(n_1273, g575);
}
static int64_t f241_arg(int64_t i_1279, int64_t *c1275, int64_t *c1273) {
return ({ int64_t _r3866; if ((((*c1275)) >= (((int64_t)0LL)))) { _r3866 = ({ int64_t _r3867; if (((i_1279) == (((int64_t)0LL)))) { _r3867 = (*c1275);  } else { _r3867 = f90_kid((*c1273), ((int64_t)((int64_t)i_1279 - (int64_t)((int64_t)1LL))));  } _r3867; });  } else { _r3866 = f90_kid((*c1273), i_1279);  } _r3866; });
}
static void f242_hook_walk(int64_t t_1285) {
while ((((g349).n) < ((g551).n))) { (void)(({ hrv *_v3871 = &(g349); int32_t _x3871 = ((int32_t)(0 - (uint64_t)(((int32_t)2LL)))); int32_t *_p3871 = (int32_t*)hr_grow(_v3871, 1, sizeof _x3871); *_p3871 = _x3871; _p3871; }));
(void)(({ hrv *_v3872 = &(g350); uint8_t _x3872 = ((uint8_t)0LL); uint8_t *_p3872 = (uint8_t*)hr_grow(_v3872, 1, sizeof _x3872); *_p3872 = _x3872; _p3872; }));
 } _bk3870:; 
if ((((t_1285) < (((int64_t)0LL))) || (((*({ hrv *_t3873 = &(g350); int64_t _i3873 = t_1285; (uint8_t*)_t3873->b + hr_ix(_i3873, _t3873->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:321"); }))) != (((uint8_t)0LL))))) { return;
 }
{ uint8_t *_t3874 = &((*({ hrv *_t3875 = &(g350); int64_t _i3875 = t_1285; (uint8_t*)_t3875->b + hr_ix(_i3875, _t3875->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:322"); }))); *_t3874 = ((uint8_t)1LL); }
S1 x_1286 = (*({ hrv *_t3876 = &(g551); int64_t _i3876 = t_1285; (S1*)_t3876->b + hr_ix(_i3876, _t3876->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:323"); })); 
int64_t k_1287 = ((int64_t)((x_1286).k_)); 
if (((k_1287) == (((int64_t)10LL)))) { (void)(f242_hook_walk(((int64_t)((x_1286).a_))));
return;
 }
if ((((k_1287) == (((int64_t)8LL))) || ((k_1287) == (((int64_t)9LL))))) { (void)(f242_hook_walk(((int64_t)((x_1286).a_))));
return;
 }
if (((k_1287) == (((int64_t)14LL)))) { { int32_t _e3880 = (x_1286).n_; for (int32_t _k3880 = 0; _k3880 < _e3880; _k3880++) { int32_t i_1288 = (int32_t)_k3880; (void)(f242_hook_walk(((int64_t)((*({ hrv *_t3882 = &(g552); int64_t _i3882 = ((int64_t)((int64_t)((int64_t)((x_1286).l_)) + (int64_t)((int64_t)(i_1288)))); (int32_t*)_t3882->b + hr_ix(_i3882, _t3882->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:326"); }))))));
 } } _bk3879:; 
return;
 }
if (((k_1287) == (((int64_t)5LL)))) { (void)(f243_hook_of(t_1285));
int64_t si_1402 = ((int64_t)((x_1286).a_)); 
{ int32_t _e3885 = ((*({ hrv *_t3886 = &(g554); int64_t _i3886 = si_1402; (S10*)_t3886->b + hr_ix(_i3886, _t3886->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:327"); }))).fnum_; for (int32_t _k3885 = 0; _k3885 < _e3885; _k3885++) { int32_t i_1403 = (int32_t)_k3885; S11 f_1404 = (*({ hrv *_t3887 = &(g555); int64_t _i3887 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3888 = &(g554); int64_t _i3888 = si_1402; (S10*)_t3888->b + hr_ix(_i3888, _t3888->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:327"); }))).f0_)) + (int64_t)((int64_t)(i_1403)))); (S11*)_t3887->b + hr_ix(_i3887, _t3887->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:327"); })); 
if ((((f_1404).ty_) >= (((int32_t)0LL)))) { (void)(f242_hook_walk(((int64_t)((f_1404).ty_))));
 }
 } } _bk3884:; 
return;
 }
if (((k_1287) == (((int64_t)7LL)))) { (void)(f243_hook_of(t_1285));
S9 v_1405 = (*({ hrv *_t3891 = &(g557); int64_t _i3891 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3892 = &(g556); int64_t _i3892 = (x_1286).a_; (S8*)_t3892->b + hr_ix(_i3892, _t3892->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:328"); }))).v0_)) + (int64_t)((int64_t)((x_1286).c_)))); (S9*)_t3891->b + hr_ix(_i3891, _t3891->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:328"); })); 
if ((((v_1405).si_) >= (((int32_t)0LL)))) { { int32_t _e3894 = ((*({ hrv *_t3895 = &(g554); int64_t _i3895 = (v_1405).si_; (S10*)_t3895->b + hr_ix(_i3895, _t3895->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:328"); }))).fnum_; for (int32_t _k3894 = 0; _k3894 < _e3894; _k3894++) { int32_t i_1406 = (int32_t)_k3894; S11 f_1407 = (*({ hrv *_t3896 = &(g555); int64_t _i3896 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3897 = &(g554); int64_t _i3897 = (v_1405).si_; (S10*)_t3897->b + hr_ix(_i3897, _t3897->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:328"); }))).f0_)) + (int64_t)((int64_t)(i_1406)))); (S11*)_t3896->b + hr_ix(_i3896, _t3896->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:328"); })); 
if ((((f_1407).ty_) >= (((int32_t)0LL)))) { (void)(f242_hook_walk(((int64_t)((f_1407).ty_))));
 }
 } } _bk3893:; 
 }
return;
 }
if (((k_1287) == (((int64_t)6LL)))) { (void)(f243_hook_of(t_1285));
int64_t ei_1408 = ((int64_t)((x_1286).a_)); 
{ int32_t _e3901 = ((*({ hrv *_t3902 = &(g556); int64_t _i3902 = ei_1408; (S8*)_t3902->b + hr_ix(_i3902, _t3902->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:329"); }))).vnum_; for (int32_t _k3901 = 0; _k3901 < _e3901; _k3901++) { int32_t i_1409 = (int32_t)_k3901; (void)(f242_hook_walk(f125_t_variant(ei_1408, ((int64_t)(i_1409)))));
 } } _bk3900:; 
 }
}
static int64_t f243_hook_of(int64_t t_1289) {
while ((((g349).n) < ((g551).n))) { (void)(({ hrv *_v3906 = &(g349); int32_t _x3906 = ((int32_t)(0 - (uint64_t)(((int32_t)2LL)))); int32_t *_p3906 = (int32_t*)hr_grow(_v3906, 1, sizeof _x3906); *_p3906 = _x3906; _p3906; }));
(void)(({ hrv *_v3907 = &(g350); uint8_t _x3907 = ((uint8_t)0LL); uint8_t *_p3907 = (uint8_t*)hr_grow(_v3907, 1, sizeof _x3907); *_p3907 = _x3907; _p3907; }));
 } _bk3905:; 
if ((((*({ hrv *_t3908 = &(g349); int64_t _i3908 = t_1289; (int32_t*)_t3908->b + hr_ix(_i3908, _t3908->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:297"); }))) != (((int32_t)(0 - (uint64_t)(((int32_t)2LL))))))) { return ((int64_t)((*({ hrv *_t3909 = &(g349); int64_t _i3909 = t_1289; (int32_t*)_t3909->b + hr_ix(_i3909, _t3909->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:297"); }))));
 }
{ int32_t *_t3910 = &((*({ hrv *_t3911 = &(g349); int64_t _i3911 = t_1289; (int32_t*)_t3911->b + hr_ix(_i3911, _t3911->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:298"); }))); *_t3910 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
int64_t k_1290 = ((int64_t)(((*({ hrv *_t3912 = &(g551); int64_t _i3912 = t_1289; (S1*)_t3912->b + hr_ix(_i3912, _t3912->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:299"); }))).k_)); 
if (((((((k_1290) == (((int64_t)0LL))) || ((k_1290) == (((int64_t)1LL)))) || ((k_1290) == (((int64_t)10LL)))) || ((k_1290) == (((int64_t)14LL)))) || f163_is_pending(t_1289))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t node_1291 = ({ int64_t _r3914; if (((k_1290) == (((int64_t)5LL)))) { _r3914 = ((int64_t)(((*({ hrv *_t3915 = &(g554); int64_t _i3915 = ((*({ hrv *_t3916 = &(g551); int64_t _i3916 = t_1289; (S1*)_t3916->b + hr_ix(_i3916, _t3916->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:301"); }))).a_; (S10*)_t3915->b + hr_ix(_i3915, _t3915->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:301"); }))).node_));  } else { _r3914 = ({ int64_t _r3917; if ((((k_1290) == (((int64_t)6LL))) || ((k_1290) == (((int64_t)7LL))))) { _r3917 = ((int64_t)(((*({ hrv *_t3918 = &(g556); int64_t _i3918 = ((*({ hrv *_t3919 = &(g551); int64_t _i3919 = t_1289; (S1*)_t3919->b + hr_ix(_i3919, _t3919->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:301"); }))).a_; (S8*)_t3918->b + hr_ix(_i3918, _t3918->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:301"); }))).node_));  } else { _r3917 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3917; });  } _r3914; }); 
if (((g351) < (((int64_t)0LL)))) { g351 = f8_intern(hr_str("format", 6));
 }
int64_t s_1292 = (g408).n; 
(void)(({ hrv *_v3921 = &(g408); int32_t _x3921 = ((int32_t)(f119_t_ref(f123_t_arr(g564, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))), ((int64_t)0LL)))); int32_t *_p3921 = (int32_t*)hr_grow(_v3921, 1, sizeof _x3921); *_p3921 = _x3921; _p3921; }));
(void)(({ hrv *_v3924 = &(g316); int32_t _x3924 = ((int32_t)0LL); int32_t *_p3924 = (int32_t*)hr_grow(_v3924, 1, sizeof _x3924); *_p3924 = _x3924; _p3924; }));
(void)(({ hrv *_v3925 = &(g408); int32_t _x3925 = ((int32_t)(t_1289)); int32_t *_p3925 = (int32_t*)hr_grow(_v3925, 1, sizeof _x3925); *_p3925 = _x3925; _p3925; }));
(void)(({ hrv *_v3926 = &(g316); int32_t _x3926 = ((int32_t)0LL); int32_t *_p3926 = (int32_t*)hr_grow(_v3926, 1, sizeof _x3926); *_p3926 = _x3926; _p3926; }));
M94 _t3927 = f244_resolve(((int64_t)0LL), g351, ({ int64_t _r3929; if (((node_1291) >= (((int64_t)0LL)))) { _r3929 = f110_ns_of(node_1291);  } else { _r3929 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3929; }), s_1292, ((int64_t)2LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false); int64_t fnode_1381 = _t3927.r0; int64_t b0_1382 = _t3927.r1; int64_t bn_1383 = _t3927.r2; 
(void)(f227_pop_args(s_1292));
if (((((fnode_1381) < (((int64_t)0LL))) || ((((*({ hrv *_t3932 = &(g704); int64_t _i3932 = fnode_1381; (S4*)_t3932->b + hr_ix(_i3932, _t3932->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:308"); }))).n_) != (((int32_t)2LL)))) || f251_is_std_node(fnode_1381))) { (void)(({ hrv *_v3934 = &(g314); int64_t _k3934 = ((int64_t)((int64_t)(g314).n - (int64_t)b0_1382)); if (_k3934 < 0 || _k3934 > _v3934->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:308"); _v3934->n -= _k3934; }));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t sa_1384 = g401; 
int64_t sc_1385 = g402; 
g401 = g403;
g402 = g403;
int64_t inst_1400 = f252_get_inst(fnode_1381, b0_1382, bn_1383, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
g401 = sa_1384;
g402 = sc_1385;
(void)(({ hrv *_v3936 = &(g314); int64_t _k3936 = ((int64_t)((int64_t)(g314).n - (int64_t)b0_1382)); if (_k3936 < 0 || _k3936 > _v3936->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:312"); _v3936->n -= _k3936; }));
while ((((g349).n) < ((g551).n))) { (void)(({ hrv *_v3938 = &(g349); int32_t _x3938 = ((int32_t)(0 - (uint64_t)(((int32_t)2LL)))); int32_t *_p3938 = (int32_t*)hr_grow(_v3938, 1, sizeof _x3938); *_p3938 = _x3938; _p3938; }));
(void)(({ hrv *_v3939 = &(g350); uint8_t _x3939 = ((uint8_t)0LL); uint8_t *_p3939 = (uint8_t*)hr_grow(_v3939, 1, sizeof _x3939); *_p3939 = _x3939; _p3939; }));
 } _bk3937:; 
int64_t pd_1401 = f179_deref(f208_ptype_of(inst_1400, ((int64_t)1LL))); 
if ((((pd_1401) != (t_1289)) && (!((((k_1290) == (((int64_t)7LL))) && ((((*({ hrv *_t3942 = &(g551); int64_t _i3942 = pd_1401; (S1*)_t3942->b + hr_ix(_i3942, _t3942->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:315"); }))).k_) == (((uint8_t)6LL)))))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
{ int32_t *_t3943 = &((*({ hrv *_t3944 = &(g349); int64_t _i3944 = t_1289; (int32_t*)_t3944->b + hr_ix(_i3944, _t3944->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:316"); }))); *_t3943 = ((int32_t)(inst_1400)); }
return inst_1400;
}
static M94 f244_resolve(int64_t n_1293, int64_t name_1294, int64_t ns_1295, int64_t a0_1296, int64_t an_1297, int64_t blk_1298, int64_t tyargs_1299, bool report_1300) {
int64_t c0_1301 = (g313).n; 
(void)(f245_cands_add(name_1294, ns_1295));
int64_t best_1310 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
int64_t bestr_1311 = ((int64_t)99LL); 
int64_t bestb0_1312 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
int64_t bestbn_1313 = ((int64_t)0LL); 
bool tie_1314 = false; 
bool bestuser_1315 = false; 
int64_t nb0_1316 = (g314).n; 
{ int64_t _e3947 = (g313).n; for (int64_t _k3947 = c0_1301; _k3947 < _e3947; _k3947++) { int64_t ci_1317 = (int64_t)_k3947; int64_t fnode_1318 = ((int64_t)(((*({ hrv *_t3948 = &(g489); int64_t _i3948 = (*({ hrv *_t3949 = &(g313); int64_t _i3949 = ci_1317; (int32_t*)_t3949->b + hr_ix(_i3949, _t3949->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:203"); })); (S5*)_t3948->b + hr_ix(_i3948, _t3948->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:203"); }))).node_)); 
int64_t np_1319 = ((int64_t)(((*({ hrv *_t3950 = &(g704); int64_t _i3950 = fnode_1318; (S4*)_t3950->b + hr_ix(_i3950, _t3950->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:204"); }))).n_)); 
int64_t nreq_1320 = ((int64_t)0LL); 
{ int64_t _e3952 = np_1319; for (int64_t _k3952 = 0; _k3952 < _e3952; _k3952++) { int64_t j_1321 = (int64_t)_k3952; if (((((*({ hrv *_t3953 = &(g704); int64_t _i3953 = f90_kid(fnode_1318, j_1321); (S4*)_t3953->b + hr_ix(_i3953, _t3953->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:206"); }))).b_) < (((int32_t)0LL)))) { nreq_1320 = ((int64_t)((int64_t)j_1321 + (int64_t)((int64_t)1LL)));
 }
 } } _bk3951:; 
if ((((an_1297) > (np_1319)) || ((an_1297) < (nreq_1320)))) { continue;
 }
int64_t bg_1322 = f231_blk_gen(fnode_1318); 
if ((((((blk_1298) >= (((int64_t)0LL)))) != (((bg_1322) >= (((int64_t)0LL))))) && (!(((((blk_1298) < (((int64_t)0LL))) && ((bg_1322) >= (((int64_t)0LL)))) && ((tyargs_1299) >= (((int64_t)0LL)))))))) { continue;
 }
int64_t b0_1323 = (g314).n; 
int64_t gl_1324 = f232_gen_list(fnode_1318); 
if (((gl_1324) >= (((int64_t)0LL)))) { { int32_t _e3958 = ((*({ hrv *_t3959 = &(g704); int64_t _i3959 = gl_1324; (S4*)_t3959->b + hr_ix(_i3959, _t3959->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:212"); }))).n_; for (int32_t _k3958 = 0; _k3958 < _e3958; _k3958++) { int32_t j_1325 = (int32_t)_k3958; (void)(({ hrv *_v3960 = &(g314); S7 _x3960 = ((S7){ .name_ = ((*({ hrv *_t3961 = &(g704); int64_t _i3961 = f90_kid(gl_1324, ((int64_t)(j_1325))); (S4*)_t3961->b + hr_ix(_i3961, _t3961->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:212"); }))).s_, .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }); S7 *_p3960 = (S7*)hr_grow(_v3960, 1, sizeof _x3960); *_p3960 = _x3960; _p3960; }));
 } } _bk3957:; 
 }
{ int64_t _e3964 = np_1319; for (int64_t _k3964 = 0; _k3964 < _e3964; _k3964++) { int64_t j_1326 = (int64_t)_k3964; int64_t p_1327 = f90_kid(fnode_1318, j_1326); 
if (((((*({ hrv *_t3966 = &(g704); int64_t _i3966 = p_1327; (S4*)_t3966->b + hr_ix(_i3966, _t3966->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:213"); }))).a_) < (((int32_t)0LL)))) { (void)(({ hrv *_v3967 = &(g314); S7 _x3967 = ((S7){ .name_ = ((int32_t)(f196_upname(p_1327))), .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }); S7 *_p3967 = (S7*)hr_grow(_v3967, 1, sizeof _x3967); *_p3967 = _x3967; _p3967; }));
 }
 } } _bk3963:; 
if (((tyargs_1299) >= (((int64_t)0LL)))) { { int64_t _e3970 = f45_min(((int64_t)(((*({ hrv *_t3972 = &(g704); int64_t _i3972 = tyargs_1299; (S4*)_t3972->b + hr_ix(_i3972, _t3972->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:214"); }))).n_)), ((int64_t)((int64_t)(g314).n - (int64_t)b0_1323))); for (int64_t _k3970 = 0; _k3970 < _e3970; _k3970++) { int64_t j_1328 = (int64_t)_k3970; { int32_t *_t3973 = &(((*({ hrv *_t3974 = &(g314); int64_t _i3974 = ((int64_t)((int64_t)b0_1323 + (int64_t)j_1328)); (S7*)_t3974->b + hr_ix(_i3974, _t3974->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:214"); }))).ty_); *_t3973 = ((int32_t)(f113_rtype(f90_kid(tyargs_1299, j_1328), ns_1295))); }
 } } _bk3969:; 
 }
{ int64_t _e3978 = an_1297; for (int64_t _k3978 = 0; _k3978 < _e3978; _k3978++) { int64_t j_1329 = (int64_t)_k3978; int64_t p_1330 = f90_kid(fnode_1318, j_1329); 
int64_t a_1331 = ((int64_t)((*({ hrv *_t3980 = &(g408); int64_t _i3980 = ((int64_t)((int64_t)a0_1296 + (int64_t)j_1329)); (int32_t*)_t3980->b + hr_ix(_i3980, _t3980->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:215"); })))); 
if ((!(f163_is_pending(a_1331)))) { if (((((*({ hrv *_t3982 = &(g704); int64_t _i3982 = p_1330; (S4*)_t3982->b + hr_ix(_i3982, _t3982->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:215"); }))).a_) >= (((int32_t)0LL)))) { (void)(f246_match_ty(((int64_t)(((*({ hrv *_t3984 = &(g704); int64_t _i3984 = p_1330; (S4*)_t3984->b + hr_ix(_i3984, _t3984->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:215"); }))).a_)), a_1331, b0_1323));
 } else { { int64_t _e3986 = (g314).n; for (int64_t _k3986 = b0_1323; _k3986 < _e3986; _k3986++) { int64_t q_1343 = (int64_t)_k3986; if ((((((int64_t)(((*({ hrv *_t3987 = &(g314); int64_t _i3987 = q_1343; (S7*)_t3987->b + hr_ix(_i3987, _t3987->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:215"); }))).name_))) == (f196_upname(p_1330))) && ((((*({ hrv *_t3989 = &(g314); int64_t _i3989 = q_1343; (S7*)_t3989->b + hr_ix(_i3989, _t3989->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:215"); }))).ty_) < (((int32_t)0LL))))) { { int32_t *_t3990 = &(((*({ hrv *_t3991 = &(g314); int64_t _i3991 = q_1343; (S7*)_t3991->b + hr_ix(_i3991, _t3991->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:215"); }))).ty_); *_t3990 = ((int32_t)(f236_deref_val(a_1331))); }
 }
 } } _bk3985:; 
 }
 }
 } } _bk3977:; 
{ int64_t _e3994 = an_1297; for (int64_t _k3994 = 0; _k3994 < _e3994; _k3994++) { int64_t j_1344 = (int64_t)_k3994; int64_t p_1345 = f90_kid(fnode_1318, j_1344); 
int64_t a_1346 = ((int64_t)((*({ hrv *_t3996 = &(g408); int64_t _i3996 = ((int64_t)((int64_t)a0_1296 + (int64_t)j_1344)); (int32_t*)_t3996->b + hr_ix(_i3996, _t3996->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:216"); })))); 
if (f163_is_pending(a_1346)) { int64_t dt_1349 = f247_pend_default(a_1346); 
if (((((*({ hrv *_t3999 = &(g704); int64_t _i3999 = p_1345; (S4*)_t3999->b + hr_ix(_i3999, _t3999->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:216"); }))).a_) >= (((int32_t)0LL)))) { (void)(f246_match_ty(((int64_t)(((*({ hrv *_t4001 = &(g704); int64_t _i4001 = p_1345; (S4*)_t4001->b + hr_ix(_i4001, _t4001->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:216"); }))).a_)), dt_1349, b0_1323));
 } else { { int64_t _e4003 = (g314).n; for (int64_t _k4003 = b0_1323; _k4003 < _e4003; _k4003++) { int64_t q_1350 = (int64_t)_k4003; if ((((((int64_t)(((*({ hrv *_t4004 = &(g314); int64_t _i4004 = q_1350; (S7*)_t4004->b + hr_ix(_i4004, _t4004->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:216"); }))).name_))) == (f196_upname(p_1345))) && ((((*({ hrv *_t4006 = &(g314); int64_t _i4006 = q_1350; (S7*)_t4006->b + hr_ix(_i4006, _t4006->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:216"); }))).ty_) < (((int32_t)0LL))))) { { int32_t *_t4007 = &(((*({ hrv *_t4008 = &(g314); int64_t _i4008 = q_1350; (S7*)_t4008->b + hr_ix(_i4008, _t4008->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:216"); }))).ty_); *_t4007 = ((int32_t)(dt_1349)); }
 }
 } } _bk4002:; 
 }
 }
 } } _bk3993:; 
bool ok_1351 = true; 
{ int64_t _e4010 = (g314).n; for (int64_t _k4010 = b0_1323; _k4010 < _e4010; _k4010++) { int64_t q_1352 = (int64_t)_k4010; if (((((*({ hrv *_t4011 = &(g314); int64_t _i4011 = q_1352; (S7*)_t4011->b + hr_ix(_i4011, _t4011->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:218"); }))).ty_) < (((int32_t)0LL)))) { if ((((bg_1322) >= (((int64_t)0LL))) && ((((int64_t)(((*({ hrv *_t4012 = &(g314); int64_t _i4012 = q_1352; (S7*)_t4012->b + hr_ix(_i4012, _t4012->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:218"); }))).name_))) == (bg_1322)))) { { int32_t *_t4013 = &(((*({ hrv *_t4014 = &(g314); int64_t _i4014 = q_1352; (S7*)_t4014->b + hr_ix(_i4014, _t4014->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:218"); }))).ty_); *_t4013 = ((int32_t)(g578)); }
 } else { ok_1351 = false;
 }
 }
 } } _bk4009:; 
if ((!(ok_1351))) { (void)(({ hrv *_v4015 = &(g314); int64_t _k4015 = ((int64_t)((int64_t)(g314).n - (int64_t)b0_1323)); if (_k4015 < 0 || _k4015 > _v4015->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:219"); _v4015->n -= _k4015; }));
continue;
 }
int64_t g0_1353 = (g491).n; 
{ int64_t _e4017 = (g314).n; for (int64_t _k4017 = b0_1323; _k4017 < _e4017; _k4017++) { int64_t q_1354 = (int64_t)_k4017; (void)(({ hrv *_v4018 = &(g491); S7 _x4018 = (*({ hrv *_t4019 = &(g314); int64_t _i4019 = q_1354; (S7*)_t4019->b + hr_ix(_i4019, _t4019->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:221"); })); S7 *_p4018 = (S7*)hr_grow(_v4018, 1, sizeof _x4018); *_p4018 = _x4018; _p4018; }));
 } } _bk4016:; 
int64_t fns_1355 = f110_ns_of(fnode_1318); 
int64_t worst_1356 = ((int64_t)0LL); 
{ int64_t _e4022 = an_1297; for (int64_t _k4022 = 0; _k4022 < _e4022; _k4022++) { int64_t j_1357 = (int64_t)_k4022; int64_t p_1358 = f90_kid(fnode_1318, j_1357); 
int64_t pt_1359 = ({ int64_t _r4024; if (((((*({ hrv *_t4025 = &(g704); int64_t _i4025 = p_1358; (S4*)_t4025->b + hr_ix(_i4025, _t4025->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:226"); }))).a_) >= (((int32_t)0LL)))) { _r4024 = f113_rtype(((int64_t)(((*({ hrv *_t4027 = &(g704); int64_t _i4027 = p_1358; (S4*)_t4027->b + hr_ix(_i4027, _t4027->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:226"); }))).a_)), fns_1355);  } else { _r4024 = f130_gb_find(f196_upname(p_1358));  } _r4024; }); 
int64_t r_1372 = f248_arg_rank(((int64_t)((*({ hrv *_t4031 = &(g316); int64_t _i4031 = ((int64_t)((int64_t)a0_1296 + (int64_t)j_1357)); (int32_t*)_t4031->b + hr_ix(_i4031, _t4031->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:227"); })))), ((int64_t)((*({ hrv *_t4032 = &(g408); int64_t _i4032 = ((int64_t)((int64_t)a0_1296 + (int64_t)j_1357)); (int32_t*)_t4032->b + hr_ix(_i4032, _t4032->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:227"); })))), pt_1359); 
if (((r_1372) < (((int64_t)0LL)))) { worst_1356 = ((int64_t)99LL);
{ goto _bk4021; }
 }
if (((r_1372) > (worst_1356))) { worst_1356 = r_1372;
 }
 } } _bk4021:; 
(void)(({ hrv *_v4033 = &(g491); int64_t _k4033 = ((int64_t)((int64_t)(g491).n - (int64_t)g0_1353)); if (_k4033 < 0 || _k4033 > _v4033->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:231"); _v4033->n -= _k4033; }));
if ((((worst_1356) < (((int64_t)2LL))) && (((gl_1324) >= (((int64_t)0LL))) || (((np_1319) > (((int64_t)0LL))) && f250_untyped_any(fnode_1318))))) { worst_1356 = f103_max(worst_1356, ((int64_t)1LL));
 }
if (((worst_1356) == (((int64_t)99LL)))) { (void)(({ hrv *_v4036 = &(g314); int64_t _k4036 = ((int64_t)((int64_t)(g314).n - (int64_t)b0_1323)); if (_k4036 < 0 || _k4036 > _v4036->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:233"); _v4036->n -= _k4036; }));
continue;
 }
bool user_1378 = (!(f251_is_std_node(fnode_1318))); 
if ((((worst_1356) < (bestr_1311)) || ((((worst_1356) == (bestr_1311)) && user_1378) && (!(bestuser_1315))))) { best_1310 = fnode_1318;
bestr_1311 = worst_1356;
bestb0_1312 = b0_1323;
bestbn_1313 = ((int64_t)((int64_t)(g314).n - (int64_t)b0_1323));
tie_1314 = false;
bestuser_1315 = user_1378;
 } else { if ((((worst_1356) == (bestr_1311)) && ((user_1378) == (bestuser_1315)))) { tie_1314 = true;
 }
 }
 } } _bk3946:; 
(void)(({ hrv *_v4038 = &(g313); int64_t _k4038 = ((int64_t)((int64_t)(g313).n - (int64_t)c0_1301)); if (_k4038 < 0 || _k4038 > _v4038->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:238"); _v4038->n -= _k4038; }));
if (((best_1310) < (((int64_t)0LL)))) { (void)(({ hrv *_v4039 = &(g314); int64_t _k4039 = ((int64_t)((int64_t)(g314).n - (int64_t)nb0_1316)); if (_k4039 < 0 || _k4039 > _v4039->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:239"); _v4039->n -= _k4039; }));
return (M94){ ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), nb0_1316, ((int64_t)0LL) };
 }
if ((tie_1314 && report_1300)) { hrv m_1379 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o4041 = &(m_1379); hr_fs(_o4041, hr_str("ambiguous call to ", 18)); hr_fs(_o4041, f10_nm(name_1294)); }));
(void)(f108_cerr(n_1293, hr_sl(m_1379)));
 }
if (((bestb0_1312) > (nb0_1316))) { { int64_t _e4045 = bestbn_1313; for (int64_t _k4045 = ((int64_t)0LL); _k4045 < _e4045; _k4045++) { int64_t q_1380 = (int64_t)_k4045; { S7 *_t4046 = &((*({ hrv *_t4047 = &(g314); int64_t _i4047 = ((int64_t)((int64_t)nb0_1316 + (int64_t)q_1380)); (S7*)_t4047->b + hr_ix(_i4047, _t4047->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:241"); }))); *_t4046 = (*({ hrv *_t4048 = &(g314); int64_t _i4048 = ((int64_t)((int64_t)bestb0_1312 + (int64_t)q_1380)); (S7*)_t4048->b + hr_ix(_i4048, _t4048->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:241"); })); }
 } } _bk4044:; 
 }
(void)(({ hrv *_v4049 = &(g314); int64_t _k4049 = ((int64_t)((int64_t)((int64_t)((int64_t)(g314).n - (int64_t)nb0_1316)) - (int64_t)bestbn_1313)); if (_k4049 < 0 || _k4049 > _v4049->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:242"); _v4049->n -= _k4049; }));
return (M94){ best_1310, nb0_1316, bestbn_1313 };
}
static void f245_cands_add(int64_t name_1302, int64_t ns_1303) {
M55 _t4050 = f117_split_q(name_1302); int64_t a_1304 = _t4050.r0; int64_t b_1305 = _t4050.r1; 
if (((a_1304) >= (((int64_t)0LL)))) { int64_t d_1306 = f107_dmap(name_1302); 
while (((d_1306) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4054 = &(g489); int64_t _i4054 = d_1306; (S5*)_t4054->b + hr_ix(_i4054, _t4054->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:190"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4055 = &(g313); int32_t _x4055 = ((int32_t)(d_1306)); int32_t *_p4055 = (int32_t*)hr_grow(_v4055, 1, sizeof _x4055); *_p4055 = _x4055; _p4055; }));
 }
d_1306 = ((int64_t)(((*({ hrv *_t4056 = &(g489); int64_t _i4056 = d_1306; (S5*)_t4056->b + hr_ix(_i4056, _t4056->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:190"); }))).next_));
 } _bk4053:; 
return;
 }
if (((a_1304) == (((int64_t)(0 - (uint64_t)(((int64_t)2LL))))))) { int64_t d_1307 = f107_dmap(b_1305); 
while (((d_1307) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4059 = &(g489); int64_t _i4059 = d_1307; (S5*)_t4059->b + hr_ix(_i4059, _t4059->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:191"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4060 = &(g313); int32_t _x4060 = ((int32_t)(d_1307)); int32_t *_p4060 = (int32_t*)hr_grow(_v4060, 1, sizeof _x4060); *_p4060 = _x4060; _p4060; }));
 }
d_1307 = ((int64_t)(((*({ hrv *_t4061 = &(g489); int64_t _i4061 = d_1307; (S5*)_t4061->b + hr_ix(_i4061, _t4061->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:191"); }))).next_));
 } _bk4058:; 
return;
 }
if (((ns_1303) >= (((int64_t)0LL)))) { int64_t d_1308 = f107_dmap(f98_qual(ns_1303, name_1302)); 
while (((d_1308) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4065 = &(g489); int64_t _i4065 = d_1308; (S5*)_t4065->b + hr_ix(_i4065, _t4065->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:192"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4066 = &(g313); int32_t _x4066 = ((int32_t)(d_1308)); int32_t *_p4066 = (int32_t*)hr_grow(_v4066, 1, sizeof _x4066); *_p4066 = _x4066; _p4066; }));
 }
d_1308 = ((int64_t)(((*({ hrv *_t4067 = &(g489); int64_t _i4067 = d_1308; (S5*)_t4067->b + hr_ix(_i4067, _t4067->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:192"); }))).next_));
 } _bk4064:; 
 }
int64_t d_1309 = f107_dmap(name_1302); 
while (((d_1309) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4070 = &(g489); int64_t _i4070 = d_1309; (S5*)_t4070->b + hr_ix(_i4070, _t4070->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:194"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4071 = &(g313); int32_t _x4071 = ((int32_t)(d_1309)); int32_t *_p4071 = (int32_t*)hr_grow(_v4071, 1, sizeof _x4071); *_p4071 = _x4071; _p4071; }));
 }
d_1309 = ((int64_t)(((*({ hrv *_t4072 = &(g489); int64_t _i4072 = d_1309; (S5*)_t4072->b + hr_ix(_i4072, _t4072->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:194"); }))).next_));
 } _bk4069:; 
}
static bool f246_match_ty(int64_t tn0_1332, int64_t t0_1333, int64_t g0_1334) {
if (((tn0_1332) < (((int64_t)0LL)))) { return true;
 }
S4 x_1335 = (*({ hrv *_t4073 = &(g704); int64_t _i4073 = tn0_1332; (S4*)_t4073->b + hr_ix(_i4073, _t4073->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:63"); })); 
int64_t k_1336 = ((int64_t)((x_1335).k_)); 
int64_t t_1337 = f179_deref(t0_1333); 
if (((k_1336) == (((int64_t)41LL)))) { if ((((x_1335).n_) == (((int32_t)0LL)))) { { int64_t _e4076 = (g314).n; for (int64_t _k4076 = g0_1334; _k4076 < _e4076; _k4076++) { int64_t i_1338 = (int64_t)_k4076; if (((((*({ hrv *_t4077 = &(g314); int64_t _i4077 = i_1338; (S7*)_t4077->b + hr_ix(_i4077, _t4077->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:67"); }))).name_) == ((x_1335).s_))) { if (((((*({ hrv *_t4078 = &(g314); int64_t _i4078 = i_1338; (S7*)_t4078->b + hr_ix(_i4078, _t4078->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:67"); }))).ty_) < (((int32_t)0LL)))) { { int32_t *_t4079 = &(((*({ hrv *_t4080 = &(g314); int64_t _i4080 = i_1338; (S7*)_t4080->b + hr_ix(_i4080, _t4080->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:67"); }))).ty_); *_t4079 = ((int32_t)(f236_deref_val(t_1337))); }
 }
return true;
 }
 } } _bk4075:; 
return true;
 }
if (((((*({ hrv *_t4082 = &(g551); int64_t _i4082 = t_1337; (S1*)_t4082->b + hr_ix(_i4082, _t4082->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).k_) == (((uint8_t)5LL)))) { int64_t si_1339 = ((int64_t)(((*({ hrv *_t4083 = &(g551); int64_t _i4083 = t_1337; (S1*)_t4083->b + hr_ix(_i4083, _t4083->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).a_)); 
if (((((*({ hrv *_t4084 = &(g554); int64_t _i4084 = si_1339; (S10*)_t4084->b + hr_ix(_i4084, _t4084->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).tn_) == ((x_1335).n_))) { { int32_t _e4086 = (x_1335).n_; for (int32_t _k4086 = 0; _k4086 < _e4086; _k4086++) { int32_t i_1340 = (int32_t)_k4086; (void)(f246_match_ty(f90_kid(tn0_1332, ((int64_t)(i_1340))), ((int64_t)((*({ hrv *_t4089 = &(g552); int64_t _i4089 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4090 = &(g554); int64_t _i4090 = si_1339; (S10*)_t4090->b + hr_ix(_i4090, _t4090->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).ta_)) + (int64_t)((int64_t)(i_1340)))); (int32_t*)_t4089->b + hr_ix(_i4089, _t4089->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); })))), g0_1334));
 } } _bk4085:; 
 }
 }
if (((((*({ hrv *_t4091 = &(g551); int64_t _i4091 = t_1337; (S1*)_t4091->b + hr_ix(_i4091, _t4091->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).k_) == (((uint8_t)6LL)))) { int64_t ei_1341 = ((int64_t)(((*({ hrv *_t4092 = &(g551); int64_t _i4092 = t_1337; (S1*)_t4092->b + hr_ix(_i4092, _t4092->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).a_)); 
if (((((*({ hrv *_t4093 = &(g556); int64_t _i4093 = ei_1341; (S8*)_t4093->b + hr_ix(_i4093, _t4093->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).tn_) == ((x_1335).n_))) { { int32_t _e4095 = (x_1335).n_; for (int32_t _k4095 = 0; _k4095 < _e4095; _k4095++) { int32_t i_1342 = (int32_t)_k4095; (void)(f246_match_ty(f90_kid(tn0_1332, ((int64_t)(i_1342))), ((int64_t)((*({ hrv *_t4098 = &(g552); int64_t _i4098 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4099 = &(g556); int64_t _i4099 = ei_1341; (S8*)_t4099->b + hr_ix(_i4099, _t4099->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).ta_)) + (int64_t)((int64_t)(i_1342)))); (int32_t*)_t4098->b + hr_ix(_i4098, _t4098->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); })))), g0_1334));
 } } _bk4094:; 
 }
 }
return true;
 }
if ((((k_1336) == (((int64_t)42LL))) || ((k_1336) == (((int64_t)43LL))))) { if ((((((*({ hrv *_t4100 = &(g551); int64_t _i4100 = t_1337; (S1*)_t4100->b + hr_ix(_i4100, _t4100->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t4101 = &(g551); int64_t _i4101 = t_1337; (S1*)_t4101->b + hr_ix(_i4101, _t4101->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).k_) == (((uint8_t)9LL))))) { return f246_match_ty(((int64_t)((x_1335).a_)), ((int64_t)(((*({ hrv *_t4103 = &(g551); int64_t _i4103 = t_1337; (S1*)_t4103->b + hr_ix(_i4103, _t4103->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).a_)), g0_1334);
 }
if (((((*({ hrv *_t4104 = &(g551); int64_t _i4104 = t_1337; (S1*)_t4104->b + hr_ix(_i4104, _t4104->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).k_) == (((uint8_t)18LL)))) { return f246_match_ty(((int64_t)((x_1335).a_)), g564, g0_1334);
 }
return true;
 }
if (((k_1336) == (((int64_t)44LL)))) { if (((((*({ hrv *_t4106 = &(g551); int64_t _i4106 = t0_1333; (S1*)_t4106->b + hr_ix(_i4106, _t4106->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:75"); }))).k_) == (((uint8_t)10LL)))) { return f246_match_ty(((int64_t)((x_1335).a_)), ((int64_t)(((*({ hrv *_t4108 = &(g551); int64_t _i4108 = t0_1333; (S1*)_t4108->b + hr_ix(_i4108, _t4108->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:75"); }))).a_)), g0_1334);
 }
return f246_match_ty(((int64_t)((x_1335).a_)), t_1337, g0_1334);
 }
if (((k_1336) == (((int64_t)48LL)))) { return f246_match_ty(((int64_t)((x_1335).a_)), t0_1333, g0_1334);
 }
return true;
}
static int64_t f247_pend_default(int64_t a_1347) {
int64_t k_1348 = ((int64_t)(((*({ hrv *_t4111 = &(g551); int64_t _i4111 = a_1347; (S1*)_t4111->b + hr_ix(_i4111, _t4111->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:247"); }))).k_)); 
return ({ int64_t _r4112; if (((k_1348) == (((int64_t)12LL)))) { _r4112 = g563;  } else { _r4112 = ({ int64_t _r4113; if (((k_1348) == (((int64_t)13LL)))) { _r4113 = g569;  } else { _r4113 = ({ int64_t _r4114; if (((k_1348) == (((int64_t)18LL)))) { _r4114 = g576;  } else { _r4114 = a_1347;  } _r4114; });  } _r4113; });  } _r4112; });
}
static int64_t f248_arg_rank(int64_t n_1360, int64_t a_1361, int64_t p_1362) {
if (((p_1362) < (((int64_t)0LL)))) { return ((int64_t)1LL);
 }
if (((a_1361) == (p_1362))) { return ((int64_t)0LL);
 }
int64_t ak_1363 = ((int64_t)(((*({ hrv *_t4115 = &(g551); int64_t _i4115 = a_1361; (S1*)_t4115->b + hr_ix(_i4115, _t4115->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:82"); }))).k_)); 
int64_t pk_1364 = ((int64_t)(((*({ hrv *_t4116 = &(g551); int64_t _i4116 = p_1362; (S1*)_t4116->b + hr_ix(_i4116, _t4116->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:82"); }))).k_)); 
if ((((pk_1364) == (((int64_t)0LL))) || ((ak_1363) == (((int64_t)0LL))))) { return ((int64_t)0LL);
 }
if (((((pk_1364) == (((int64_t)10LL))) && ((((*({ hrv *_t4117 = &(g551); int64_t _i4117 = p_1362; (S1*)_t4117->b + hr_ix(_i4117, _t4117->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:84"); }))).c_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4118 = &(g551); int64_t _i4118 = p_1362; (S1*)_t4118->b + hr_ix(_i4118, _t4118->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:84"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL))))) { int64_t tgt_1365 = ((int64_t)(((*({ hrv *_t4119 = &(g551); int64_t _i4119 = p_1362; (S1*)_t4119->b + hr_ix(_i4119, _t4119->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:84"); }))).a_)); 
if (((f179_deref(a_1361)) == (tgt_1365))) { return ((int64_t)0LL);
 }
if ((((ak_1363) == (((int64_t)12LL))) || ((ak_1363) == (((int64_t)13LL))))) { return f248_arg_rank(n_1360, a_1361, tgt_1365);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if ((((ak_1363) == (((int64_t)10LL))) && ((((*({ hrv *_t4122 = &(g551); int64_t _i4122 = a_1361; (S1*)_t4122->b + hr_ix(_i4122, _t4122->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).c_) < (((int32_t)0LL))))) { int64_t d_1366 = ((int64_t)(((*({ hrv *_t4123 = &(g551); int64_t _i4123 = a_1361; (S1*)_t4123->b + hr_ix(_i4123, _t4123->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).a_)); 
if (((d_1366) == (p_1362))) { return ((int64_t)0LL);
 }
if (((((pk_1364) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4124 = &(g551); int64_t _i4124 = p_1362; (S1*)_t4124->b + hr_ix(_i4124, _t4124->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && ((((*({ hrv *_t4125 = &(g551); int64_t _i4125 = p_1362; (S1*)_t4125->b + hr_ix(_i4125, _t4125->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).a_) == (((*({ hrv *_t4126 = &(g551); int64_t _i4126 = a_1361; (S1*)_t4126->b + hr_ix(_i4126, _t4126->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).a_)))) { return ((int64_t)0LL);
 }
return f248_arg_rank(n_1360, d_1366, p_1362);
 }
if (((ak_1363) == (((int64_t)12LL)))) { M78 _t4128 = f155_cval(n_1360); int64_t v_1367 = _t4128.r0; bool u_1368 = _t4128.r1; bool ok_1369 = _t4128.r2; 
if (((pk_1364) == (((int64_t)3LL)))) { if (((!(ok_1369)) || f158_int_fits(v_1367, u_1368, p_1362))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((pk_1364) == (((int64_t)4LL)))) { return ((int64_t)3LL);
 }
if (((pk_1364) == (((int64_t)17LL)))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1363) == (((int64_t)13LL)))) { if (((pk_1364) == (((int64_t)4LL)))) { return ({ int64_t _r4131; if (((((*({ hrv *_t4132 = &(g551); int64_t _i4132 = p_1362; (S1*)_t4132->b + hr_ix(_i4132, _t4132->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:93"); }))).s_) == (((uint8_t)8LL)))) { _r4131 = ((int64_t)1LL);  } else { _r4131 = ((int64_t)2LL);  } _r4131; });
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1363) == (((int64_t)18LL)))) { if ((((pk_1364) == (((int64_t)9LL))) && ((((int64_t)(((*({ hrv *_t4133 = &(g551); int64_t _i4133 = p_1362; (S1*)_t4133->b + hr_ix(_i4133, _t4133->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:94"); }))).a_))) == (g564)))) { return ((int64_t)0LL);
 }
if (f164_is_byte_arr(p_1362)) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1363) == (((int64_t)19LL)))) { if ((((pk_1364) == (((int64_t)8LL))) || ((pk_1364) == (((int64_t)9LL))))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1363) == (((int64_t)11LL)))) { if ((((pk_1364) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4135 = &(g551); int64_t _i4135 = p_1362; (S1*)_t4135->b + hr_ix(_i4135, _t4135->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:96"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { return ((int64_t)0LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((((pk_1364) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4136 = &(g551); int64_t _i4136 = p_1362; (S1*)_t4136->b + hr_ix(_i4136, _t4136->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:97"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && ((((int64_t)(((*({ hrv *_t4137 = &(g551); int64_t _i4137 = p_1362; (S1*)_t4137->b + hr_ix(_i4137, _t4137->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:97"); }))).a_))) == (a_1361)))) { return ((int64_t)0LL);
 }
if ((((ak_1363) == (((int64_t)3LL))) && ((pk_1364) == (((int64_t)4LL))))) { return ((int64_t)3LL);
 }
if (f152_widens(a_1361, p_1362)) { return ((int64_t)2LL);
 }
if (((((pk_1364) == (((int64_t)9LL))) && (((ak_1363) == (((int64_t)8LL))) || ((ak_1363) == (((int64_t)9LL))))) && ((((*({ hrv *_t4139 = &(g551); int64_t _i4139 = a_1361; (S1*)_t4139->b + hr_ix(_i4139, _t4139->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:100"); }))).a_) == (((*({ hrv *_t4140 = &(g551); int64_t _i4140 = p_1362; (S1*)_t4140->b + hr_ix(_i4140, _t4140->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:100"); }))).a_)))) { return ((int64_t)2LL);
 }
if (((((pk_1364) == (((int64_t)6LL))) && ((ak_1363) == (((int64_t)7LL)))) && ((((*({ hrv *_t4141 = &(g551); int64_t _i4141 = a_1361; (S1*)_t4141->b + hr_ix(_i4141, _t4141->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:101"); }))).a_) == (((*({ hrv *_t4142 = &(g551); int64_t _i4142 = p_1362; (S1*)_t4142->b + hr_ix(_i4142, _t4142->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:101"); }))).a_)))) { return ((int64_t)2LL);
 }
if ((((((pk_1364) == (((int64_t)8LL))) && (((ak_1363) == (((int64_t)8LL))) || ((ak_1363) == (((int64_t)9LL))))) && ((((*({ hrv *_t4143 = &(g551); int64_t _i4143 = a_1361; (S1*)_t4143->b + hr_ix(_i4143, _t4143->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:102"); }))).a_) == (((*({ hrv *_t4144 = &(g551); int64_t _i4144 = p_1362; (S1*)_t4144->b + hr_ix(_i4144, _t4144->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:102"); }))).a_))) && f249_is_construct(n_1360))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f249_is_construct(int64_t n_1370) {
int64_t k_1371 = ((int64_t)(((*({ hrv *_t4146 = &(g704); int64_t _i4146 = n_1370; (S4*)_t4146->b + hr_ix(_i4146, _t4146->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:187"); }))).k_)); 
return ((((k_1371) == (((int64_t)11LL))) || ((k_1371) == (((int64_t)16LL)))) || ((k_1371) == (((int64_t)3LL))));
}
static bool f250_untyped_any(int64_t f_1373) {
{ int32_t _e4148 = ((*({ hrv *_t4149 = &(g704); int64_t _i4149 = f_1373; (S4*)_t4149->b + hr_ix(_i4149, _t4149->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:245"); }))).n_; for (int32_t _k4148 = 0; _k4148 < _e4148; _k4148++) { int32_t j_1374 = (int32_t)_k4148; if (((((*({ hrv *_t4150 = &(g704); int64_t _i4150 = f90_kid(f_1373, ((int64_t)(j_1374))); (S4*)_t4150->b + hr_ix(_i4150, _t4150->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:245"); }))).a_) < (((int32_t)0LL)))) { return true;
 }
 } } _bk4147:; 
return false;
}
static bool f251_is_std_node(int64_t node_1375) {
int64_t f_1376 = f111_node_file(node_1375); 
L49 sp_1377 = f100_lib_path(hr_str("std", 3)); 
return hr_streq(f10_nm(((int64_t)(((*({ hrv *_t4155 = &(g913); int64_t _i4155 = f_1376; (S2*)_t4155->b + hr_ix(_i4155, _t4155->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:196"); }))).name_))), ({ hsl _t4156 = ({ L49 *_t4157 = &(sp_1377); (hsl){ (uint8_t*)_t4157->e, _t4157->n }; }); int64_t _l4156 = 0, _h4156 = _t4156.n; if (_l4156 < 0 || _h4156 < _l4156 || _h4156 > _t4156.n) hr_slerr(_l4156, _h4156, _t4156.n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:196"); (hsl){ _t4156.p + _l4156 * (int64_t)sizeof(uint8_t), _h4156 - _l4156 }; }));
}
static int64_t f252_get_inst(int64_t node_1386, int64_t b0_1387, int64_t bn_1388, int64_t blk_1389, int64_t bown_1390) {
int64_t par_1391 = ({ int64_t _r4158; if (((((uint16_t)((uint64_t)((*({ hrv *_t4159 = &(g704); int64_t _i4159 = node_1386; (S4*)_t4159->b + hr_ix(_i4159, _t4159->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:177"); }))).fl_ & (uint64_t)((uint16_t)128LL)))) != (((uint16_t)0LL)))) { _r4158 = g401;  } else { _r4158 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r4158; }); 
if (((blk_1389) < (((int64_t)0LL)))) { { hrv *_v4161 = &(g388); for (int64_t _k4161 = 0; _k4161 < _v4161->n; _k4161++) { S6 f_1392 = ((S6*)_v4161->b)[_k4161]; int64_t i_1393 = (int64_t)_k4161; if ((((((((int64_t)((f_1392).node_))) == (node_1386)) && (((f_1392).blk_) < (((int32_t)0LL)))) && ((((int64_t)((f_1392).par_))) == (par_1391))) && f253_same_binds(i_1393, b0_1387, bn_1388))) { return i_1393;
 }
 } } _bk4160:; 
 }
int64_t i_1398 = f105_new_inst(node_1386, node_1386, ((int64_t)((*({ hrv *_t4164 = &(g719); int64_t _i4164 = node_1386; (int32_t*)_t4164->b + hr_ix(_i4164, _t4164->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:179"); })))), par_1391); 
{ int32_t *_t4165 = &(((*({ hrv *_t4166 = &(g388); int64_t _i4166 = i_1398; (S6*)_t4166->b + hr_ix(_i4166, _t4166->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:180"); }))).g0_); *_t4165 = ((int32_t)((g394).n)); }
{ int64_t _e4168 = bn_1388; for (int64_t _k4168 = 0; _k4168 < _e4168; _k4168++) { int64_t j_1399 = (int64_t)_k4168; (void)(({ hrv *_v4169 = &(g394); S7 _x4169 = (*({ hrv *_t4170 = &(g314); int64_t _i4170 = ((int64_t)((int64_t)b0_1387 + (int64_t)j_1399)); (S7*)_t4170->b + hr_ix(_i4170, _t4170->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:181"); })); S7 *_p4169 = (S7*)hr_grow(_v4169, 1, sizeof _x4169); *_p4169 = _x4169; _p4169; }));
 } } _bk4167:; 
{ int32_t *_t4171 = &(((*({ hrv *_t4172 = &(g388); int64_t _i4172 = i_1398; (S6*)_t4172->b + hr_ix(_i4172, _t4172->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:182"); }))).gn_); *_t4171 = ((int32_t)(bn_1388)); }
{ int32_t *_t4173 = &(((*({ hrv *_t4174 = &(g388); int64_t _i4174 = i_1398; (S6*)_t4174->b + hr_ix(_i4174, _t4174->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:183"); }))).blk_); *_t4173 = ((int32_t)(blk_1389)); }
{ int32_t *_t4175 = &(((*({ hrv *_t4176 = &(g388); int64_t _i4176 = i_1398; (S6*)_t4176->b + hr_ix(_i4176, _t4176->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:183"); }))).bown_); *_t4175 = ((int32_t)(bown_1390)); }
(void)(f195_sig_inst(i_1398));
(void)(f207_check_inst(i_1398));
return i_1398;
}
static bool f253_same_binds(int64_t i_1394, int64_t b0_1395, int64_t bn_1396) {
if (((((int64_t)(((*({ hrv *_t4179 = &(g388); int64_t _i4179 = i_1394; (S6*)_t4179->b + hr_ix(_i4179, _t4179->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:172"); }))).gn_))) != (bn_1396))) { return false;
 }
{ int64_t _e4181 = bn_1396; for (int64_t _k4181 = 0; _k4181 < _e4181; _k4181++) { int64_t j_1397 = (int64_t)_k4181; if ((((((*({ hrv *_t4182 = &(g394); int64_t _i4182 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4183 = &(g388); int64_t _i4183 = i_1394; (S6*)_t4183->b + hr_ix(_i4183, _t4183->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); }))).g0_)) + (int64_t)j_1397)); (S7*)_t4182->b + hr_ix(_i4182, _t4182->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); }))).ty_) != (((*({ hrv *_t4184 = &(g314); int64_t _i4184 = ((int64_t)((int64_t)b0_1395 + (int64_t)j_1397)); (S7*)_t4184->b + hr_ix(_i4184, _t4184->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); }))).ty_)) || ((((*({ hrv *_t4185 = &(g394); int64_t _i4185 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4186 = &(g388); int64_t _i4186 = i_1394; (S6*)_t4186->b + hr_ix(_i4186, _t4186->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); }))).g0_)) + (int64_t)j_1397)); (S7*)_t4185->b + hr_ix(_i4185, _t4185->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); }))).name_) != (((*({ hrv *_t4187 = &(g314); int64_t _i4187 = ((int64_t)((int64_t)b0_1395 + (int64_t)j_1397)); (S7*)_t4187->b + hr_ix(_i4187, _t4187->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); }))).name_)))) { return false;
 }
 } } _bk4180:; 
return true;
}
static int64_t f254_call_fn(int64_t n_1432, int64_t name_1433, int64_t recv_1434, int64_t want_1435) {
int64_t s_1436 = f226_ck_args(n_1432, ((int64_t)0LL), recv_1434); 
int64_t an_1437 = ((int64_t)((int64_t)(g408).n - (int64_t)s_1436)); 
int64_t blk_1438 = ((int64_t)(((*({ hrv *_t4189 = &(g704); int64_t _i4189 = n_1432; (S4*)_t4189->b + hr_ix(_i4189, _t4189->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:386"); }))).b_)); 
M94 _t4190 = f244_resolve(n_1432, name_1433, f110_ns_of(n_1432), s_1436, an_1437, blk_1438, ((int64_t)(((*({ hrv *_t4193 = &(g704); int64_t _i4193 = n_1432; (S4*)_t4193->b + hr_ix(_i4193, _t4193->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:387"); }))).c_)), true); int64_t fnode_1439 = _t4190.r0; int64_t b0_1440 = _t4190.r1; int64_t bn_1441 = _t4190.r2; 
if (((fnode_1439) < (((int64_t)0LL)))) { hrv m_1442 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o4195 = &(m_1442); hr_fs(_o4195, hr_str("no function ", 12)); hr_fs(_o4195, f10_nm(name_1433)); hr_fs(_o4195, hr_str(" matches (", 10)); }));
{ int64_t _e4198 = an_1437; for (int64_t _k4198 = 0; _k4198 < _e4198; _k4198++) { int64_t j_1443 = (int64_t)_k4198; if (((j_1443) > (((int64_t)0LL)))) { (void)(({ hrv *_v4199 = &(m_1442); hsl _s4199 = hr_str(", ", 2); hr_append(_v4199, _s4199.p, _s4199.n, sizeof(uint8_t)); }));
 }
{ hrv _t4201 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_v4200 = &(m_1442); hsl _s4200 = hr_sl(*hr_tmp(&_t4201, f161_tn(((int64_t)((*({ hrv *_t4203 = &(g408); int64_t _i4203 = ((int64_t)((int64_t)s_1436 + (int64_t)j_1443)); (int32_t*)_t4203->b + hr_ix(_i4203, _t4203->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:390"); }))))))); hr_append(_v4200, _s4200.p, _s4200.n, sizeof(uint8_t)); }));
}
 } } _bk4197:; 
(void)(({ hrv *_v4204 = &(m_1442); hsl _s4204 = hr_str(")", 1); hr_append(_v4204, _s4204.p, _s4204.n, sizeof(uint8_t)); }));
(void)(f108_cerr(n_1432, hr_sl(m_1442)));
(void)(f227_pop_args(s_1436));
(void)(({ hrv *_v4207 = &(g314); int64_t _k4207 = ((int64_t)((int64_t)(g314).n - (int64_t)b0_1440)); if (_k4207 < 0 || _k4207 > _v4207->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:394"); _v4207->n -= _k4207; }));
return f138_set_t(n_1432, g575);
 }
int64_t inst_1444 = f252_get_inst(fnode_1439, b0_1440, bn_1441, blk_1438, g401); 
(void)(({ hrv *_v4210 = &(g314); int64_t _k4210 = ((int64_t)((int64_t)(g314).n - (int64_t)b0_1440)); if (_k4210 < 0 || _k4210 > _v4210->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:398"); _v4210->n -= _k4210; }));
{ int64_t _e4212 = an_1437; for (int64_t _k4212 = 0; _k4212 < _e4212; _k4212++) { int64_t j_1445 = (int64_t)_k4212; int64_t c_1446 = ((int64_t)((*({ hrv *_t4213 = &(g316); int64_t _i4213 = ((int64_t)((int64_t)s_1436 + (int64_t)j_1445)); (int32_t*)_t4213->b + hr_ix(_i4213, _t4213->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:399"); })))); 
int64_t pt_1447 = f208_ptype_of(inst_1444, j_1445); 
if ((((((pt_1447) >= (((int64_t)0LL))) && ((((*({ hrv *_t4215 = &(g551); int64_t _i4215 = pt_1447; (S1*)_t4215->b + hr_ix(_i4215, _t4215->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:399"); }))).k_) == (((uint8_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4216 = &(g551); int64_t _i4216 = pt_1447; (S1*)_t4216->b + hr_ix(_i4216, _t4216->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:399"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))) && ((((*({ hrv *_t4217 = &(g551); int64_t _i4217 = pt_1447; (S1*)_t4217->b + hr_ix(_i4217, _t4217->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:399"); }))).c_) < (((int32_t)0LL))))) { if (f163_is_pending(f141_at(c_1446))) { (void)(f140_conv(c_1446, ((int64_t)(((*({ hrv *_t4221 = &(g551); int64_t _i4221 = pt_1447; (S1*)_t4221->b + hr_ix(_i4221, _t4221->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:399"); }))).a_))));
 }
 } else { (void)(f140_conv(c_1446, pt_1447));
 }
 } } _bk4211:; 
(void)(f227_pop_args(s_1436));
(void)(f228_note_caps_of(inst_1444));
(void)(f229_note_edge(inst_1444));
(void)(f170_set_r(n_1432, ((int64_t)3LL), inst_1444));
int64_t rt_1448 = ((int64_t)(((*({ hrv *_t4227 = &(g388); int64_t _i4227 = inst_1444; (S6*)_t4227->b + hr_ix(_i4227, _t4227->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:403"); }))).ret_)); 
if (((rt_1448) < (((int64_t)0LL)))) { if (((((*({ hrv *_t4228 = &(g388); int64_t _i4228 = inst_1444; (S6*)_t4228->b + hr_ix(_i4228, _t4228->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:404"); }))).st_) == (((uint8_t)1LL)))) { hrv m_1449 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o4230 = &(m_1449); hr_fs(_o4230, hr_str("recursive call to ", 18)); hr_fs(_o4230, f10_nm(name_1433)); hr_fs(_o4230, hr_str(" needs its result type written", 30)); }));
(void)(f108_cerr(n_1432, hr_sl(m_1449)));
 }
return f138_set_t(n_1432, g575);
 }
return f138_set_t(n_1432, rt_1448);
}
static int64_t f255_member_of(hsl name_1454) {
if (hr_streq(name_1454, hr_str("push", 4))) { return ((int64_t)20LL);
 }
if (hr_streq(name_1454, hr_str("append", 6))) { return ((int64_t)21LL);
 }
if (hr_streq(name_1454, hr_str("pop", 3))) { return ((int64_t)22LL);
 }
if (hr_streq(name_1454, hr_str("pop_n", 5))) { return ((int64_t)23LL);
 }
if (hr_streq(name_1454, hr_str("resize", 6))) { return ((int64_t)24LL);
 }
if (hr_streq(name_1454, hr_str("clear", 5))) { return ((int64_t)25LL);
 }
if (hr_streq(name_1454, hr_str("index_of", 8))) { return ((int64_t)26LL);
 }
if (hr_streq(name_1454, hr_str("len", 3))) { return ((int64_t)9LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f256_ck_slit(int64_t n_1457, int64_t want_1458) {
S4 x_1459 = (*({ hrv *_t4235 = &(g704); int64_t _i4235 = n_1457; (S4*)_t4235->b + hr_ix(_i4235, _t4235->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:458"); })); 
int64_t tnode_1460 = ((int64_t)((x_1459).a_)); 
int64_t ns_1461 = f110_ns_of(n_1457); 
int64_t t_1462 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((((*({ hrv *_t4237 = &(g704); int64_t _i4237 = tnode_1460; (S4*)_t4237->b + hr_ix(_i4237, _t4237->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:462"); }))).k_) == (((uint8_t)41LL))) && ((((*({ hrv *_t4238 = &(g704); int64_t _i4238 = tnode_1460; (S4*)_t4238->b + hr_ix(_i4238, _t4238->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:462"); }))).n_) == (((int32_t)0LL)))) && ((f130_gb_find(((int64_t)(((*({ hrv *_t4240 = &(g704); int64_t _i4240 = tnode_1460; (S4*)_t4240->b + hr_ix(_i4240, _t4240->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:462"); }))).s_)))) < (((int64_t)0LL))))) { int64_t d_1463 = f116_lookup_q(((int64_t)(((*({ hrv *_t4242 = &(g704); int64_t _i4242 = tnode_1460; (S4*)_t4242->b + hr_ix(_i4242, _t4242->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:463"); }))).s_)), ns_1461, ((int64_t)1LL)); 
if ((((d_1463) >= (((int64_t)0LL))) && ((((*({ hrv *_t4243 = &(g704); int64_t _i4243 = ((*({ hrv *_t4244 = &(g489); int64_t _i4244 = d_1463; (S5*)_t4244->b + hr_ix(_i4244, _t4244->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:464"); }))).node_; (S4*)_t4243->b + hr_ix(_i4243, _t4243->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:464"); }))).d_) >= (((int32_t)0LL))))) { if (((((want_1458) >= (((int64_t)0LL))) && ((((*({ hrv *_t4245 = &(g551); int64_t _i4245 = want_1458; (S1*)_t4245->b + hr_ix(_i4245, _t4245->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:464"); }))).k_) == (((uint8_t)5LL)))) && ((((*({ hrv *_t4246 = &(g554); int64_t _i4246 = ((*({ hrv *_t4247 = &(g551); int64_t _i4247 = want_1458; (S1*)_t4247->b + hr_ix(_i4247, _t4247->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:464"); }))).a_; (S10*)_t4246->b + hr_ix(_i4246, _t4246->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:464"); }))).node_) == (((*({ hrv *_t4248 = &(g489); int64_t _i4248 = d_1463; (S5*)_t4248->b + hr_ix(_i4248, _t4248->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:464"); }))).node_)))) { t_1462 = want_1458;
 }
 }
 }
if (((t_1462) < (((int64_t)0LL)))) { t_1462 = f113_rtype(tnode_1460, ns_1461);
 }
int64_t si_1464 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((*({ hrv *_t4250 = &(g551); int64_t _i4250 = t_1462; (S1*)_t4250->b + hr_ix(_i4250, _t4250->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:468"); }))).k_) == (((uint8_t)5LL)))) { si_1464 = ((int64_t)(((*({ hrv *_t4251 = &(g551); int64_t _i4251 = t_1462; (S1*)_t4251->b + hr_ix(_i4251, _t4251->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:468"); }))).a_));
 }
if (((((*({ hrv *_t4252 = &(g551); int64_t _i4252 = t_1462; (S1*)_t4252->b + hr_ix(_i4252, _t4252->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:469"); }))).k_) == (((uint8_t)7LL)))) { si_1464 = ((int64_t)(((*({ hrv *_t4253 = &(g557); int64_t _i4253 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4254 = &(g556); int64_t _i4254 = ((*({ hrv *_t4255 = &(g551); int64_t _i4255 = t_1462; (S1*)_t4255->b + hr_ix(_i4255, _t4255->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:469"); }))).a_; (S8*)_t4254->b + hr_ix(_i4254, _t4254->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:469"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t4256 = &(g551); int64_t _i4256 = t_1462; (S1*)_t4256->b + hr_ix(_i4256, _t4256->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:469"); }))).c_)))); (S9*)_t4253->b + hr_ix(_i4253, _t4253->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:469"); }))).si_));
 }
if (((si_1464) < (((int64_t)0LL)))) { if (((((*({ hrv *_t4257 = &(g551); int64_t _i4257 = t_1462; (S1*)_t4257->b + hr_ix(_i4257, _t4257->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:470"); }))).k_) != (((uint8_t)0LL)))) { (void)(f108_cerr(n_1457, hr_str("not a struct type", 17)));
 }
return f138_set_t(n_1457, g575);
 }
{ int32_t _e4261 = (x_1459).n_; for (int32_t _k4261 = 0; _k4261 < _e4261; _k4261++) { int32_t i_1465 = (int32_t)_k4261; if (((((int64_t)(((*({ hrv *_t4262 = &(g704); int64_t _i4262 = f90_kid(n_1457, ((int64_t)(i_1465))); (S4*)_t4262->b + hr_ix(_i4262, _t4262->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:471"); }))).k_))) == (((int64_t)37LL)))) { (void)(f108_cerr(f90_kid(n_1457, ((int64_t)(i_1465))), hr_str("const for is not supported by the self-hosted compiler yet", 58)));
return f138_set_t(n_1457, g575);
 }
 } } _bk4260:; 
int64_t nf_1466 = ((int64_t)(((*({ hrv *_t4267 = &(g554); int64_t _i4267 = si_1464; (S10*)_t4267->b + hr_ix(_i4267, _t4267->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:472"); }))).fnum_)); 
bool named_1467 = ((((x_1459).n_) > (((int32_t)0LL))) && ((((*({ hrv *_t4268 = &(g704); int64_t _i4268 = f90_kid(n_1457, ((int64_t)0LL)); (S4*)_t4268->b + hr_ix(_i4268, _t4268->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:473"); }))).s_) >= (((int32_t)0LL)))); 
int64_t fpos_1468 = ((int64_t)0LL); 
{ int32_t _e4271 = (x_1459).n_; for (int32_t _k4271 = 0; _k4271 < _e4271; _k4271++) { int32_t i_1469 = (int32_t)_k4271; int64_t fi_1470 = f90_kid(n_1457, ((int64_t)(i_1469))); 
int64_t idx_1471 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (named_1467) { idx_1471 = f187_sfield(si_1464, ((int64_t)(((*({ hrv *_t4274 = &(g704); int64_t _i4274 = fi_1470; (S4*)_t4274->b + hr_ix(_i4274, _t4274->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:478"); }))).s_)));
if (((idx_1471) < (((int64_t)0LL)))) { hrv m_1472 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t4279 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o4276 = &(m_1472); hr_fs(_o4276, hr_str("no field ", 9)); hr_fs(_o4276, f10_nm(((int64_t)(((*({ hrv *_t4278 = &(g704); int64_t _i4278 = fi_1470; (S4*)_t4278->b + hr_ix(_i4278, _t4278->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:478"); }))).s_)))); hr_fs(_o4276, hr_str(" in ", 4)); hr_fs(_o4276, hr_sl(*hr_tmp(&_t4279, f161_tn(t_1462)))); }));
}
(void)(f108_cerr(fi_1470, hr_sl(m_1472)));
continue;
 }
 } else { while ((((fpos_1468) < (nf_1466)) && ((((*({ hrv *_t4283 = &(g555); int64_t _i4283 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4284 = &(g554); int64_t _i4284 = si_1464; (S10*)_t4284->b + hr_ix(_i4284, _t4284->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:479"); }))).f0_)) + (int64_t)fpos_1468)); (S11*)_t4283->b + hr_ix(_i4283, _t4283->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:479"); }))).ty_) < (((int32_t)0LL))))) { fpos_1468++;
 } _bk4282:; 
idx_1471 = fpos_1468;
fpos_1468++;
if (((idx_1471) >= (nf_1466))) { (void)(f108_cerr(fi_1470, hr_str("too many initializers", 21)));
continue;
 }
 }
int64_t ft_1473 = ((int64_t)(((*({ hrv *_t4286 = &(g555); int64_t _i4286 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4287 = &(g554); int64_t _i4287 = si_1464; (S10*)_t4287->b + hr_ix(_i4287, _t4287->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:480"); }))).f0_)) + (int64_t)idx_1471)); (S11*)_t4286->b + hr_ix(_i4286, _t4286->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:480"); }))).ty_)); 
(void)(f170_set_r(fi_1470, ((int64_t)5LL), idx_1471));
int64_t v_1474 = ((int64_t)(((*({ hrv *_t4289 = &(g704); int64_t _i4289 = fi_1470; (S4*)_t4289->b + hr_ix(_i4289, _t4289->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:482"); }))).a_)); 
(void)(f137_ck(v_1474, ft_1473));
(void)(f140_conv(v_1474, ft_1473));
 } } _bk4270:; 
{ int64_t _e4293 = nf_1466; for (int64_t _k4293 = 0; _k4293 < _e4293; _k4293++) { int64_t j_1475 = (int64_t)_k4293; S11 f_1476 = (*({ hrv *_t4294 = &(g555); int64_t _i4294 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4295 = &(g554); int64_t _i4295 = si_1464; (S10*)_t4295->b + hr_ix(_i4295, _t4295->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:486"); }))).f0_)) + (int64_t)j_1475)); (S11*)_t4294->b + hr_ix(_i4294, _t4294->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:486"); })); 
if ((((f_1476).ty_) < (((int32_t)0LL)))) { continue;
 }
bool given_1477 = false; 
{ int32_t _e4297 = (x_1459).n_; for (int32_t _k4297 = 0; _k4297 < _e4297; _k4297++) { int32_t i_1478 = (int32_t)_k4297; if (((f157_rv(f90_kid(n_1457, ((int64_t)(i_1478))))) == (j_1475))) { given_1477 = true;
 }
 } } _bk4296:; 
if (((!(given_1477)) && (((f_1476).def_) >= (((int32_t)0LL))))) { int64_t sa_1479 = g401; 
g401 = g403;
(void)(f137_ck(((int64_t)((f_1476).def_)), ((int64_t)((f_1476).ty_))));
(void)(f140_conv(((int64_t)((f_1476).def_)), ((int64_t)((f_1476).ty_))));
g401 = sa_1479;
 }
if (((((!(given_1477)) && (((f_1476).def_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)(x_1459).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) && (!(f165_is_opt(((int64_t)((f_1476).ty_))))))) { hrv m_1480 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t4306 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o4304 = &(m_1480); hr_fs(_o4304, hr_str("missing field ", 14)); hr_fs(_o4304, f10_nm(((int64_t)((f_1476).name_)))); hr_fs(_o4304, hr_str(" in ", 4)); hr_fs(_o4304, hr_sl(*hr_tmp(&_t4306, f161_tn(t_1462)))); }));
}
(void)(f108_cerr(n_1457, hr_sl(m_1480)));
 }
 } } _bk4292:; 
(void)(f170_set_r(n_1457, ((int64_t)9LL), si_1464));
return f138_set_t(n_1457, t_1462);
}
static bool f257_ORD_HAS(int64_t d_1482) {
{ hrv *_v4312 = &(g409); for (int64_t _k4312 = 0; _k4312 < _v4312->n; _k4312++) { int32_t o_1483 = ((int32_t*)_v4312->b)[_k4312]; if (((((int64_t)(o_1483))) == (d_1482))) { return true;
 }
 } } _bk4311:; 
return false;
}
static void f258_propagate_calls(void) {
bool changed_1487 = true; 
while (changed_1487) { changed_1487 = false;
{ hrv *_v4315 = &(g393); for (int64_t _k4315 = 0; _k4315 < _v4315->n; _k4315++) { S15 e_1488 = ((S15*)_v4315->b)[_k4315]; int64_t cr_1489 = ((int64_t)((e_1488).caller_)); 
int64_t ce_1490 = ((int64_t)((e_1488).callee_)); 
if ((((*({ hrv *_t4316 = &(g388); int64_t _i4316 = ce_1490; (S6*)_t4316->b + hr_ix(_i4316, _t4316->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:42"); }))).lr_ && (!(((*({ hrv *_t4317 = &(g388); int64_t _i4317 = cr_1489; (S6*)_t4317->b + hr_ix(_i4317, _t4317->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:42"); }))).lr_)))) { { bool *_t4318 = &(((*({ hrv *_t4319 = &(g388); int64_t _i4319 = cr_1489; (S6*)_t4319->b + hr_ix(_i4319, _t4319->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:42"); }))).lr_); *_t4318 = true; }
changed_1487 = true;
 }
{ hrv *_v4321 = &(g392); for (int64_t _k4321 = 0; _k4321 < _v4321->n; _k4321++) { S13 c_1491 = ((S13*)_v4321->b)[_k4321]; if (((((int64_t)((c_1491).inst_))) == (ce_1490))) { int64_t v_1492 = ((int64_t)((c_1491).lv_)); 
if ((f169_visible_in(((int64_t)(((*({ hrv *_t4323 = &(g389); int64_t _i4323 = v_1492; (S12*)_t4323->b + hr_ix(_i4323, _t4323->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:43"); }))).own_)), cr_1489) || ((((int64_t)(((*({ hrv *_t4324 = &(g389); int64_t _i4324 = v_1492; (S12*)_t4324->b + hr_ix(_i4324, _t4324->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:43"); }))).cfn_))) != (cr_1489)))) { if (f172_add_cap_one(cr_1489, v_1492)) { changed_1487 = true;
 }
 }
 }
 } } _bk4320:; 
 } } _bk4314:; 
 } _bk4313:; 
}
static bool f259_gen_program(hrv* out_1494) {
(void)(({ hrv *_v4326 = &(g163); _v4326->n = 0; }));
{ hrv *_v4328 = &(g388); for (int64_t _k4328 = 0; _k4328 < _v4328->n; _k4328++) { S6 f_1495 = ((S6*)_v4328->b)[_k4328]; int64_t i_1496 = (int64_t)_k4328; if ((((f_1495).tg_ && (((f_1495).ret_) >= (((int32_t)0LL)))) && ((((int64_t)((f_1495).ret_))) != (g558)))) { int64_t sv_1497 = (g163).n; 
(void)(f260_ow(hr_str("static __thread ", 16)));
(void)(f261_ct(((int64_t)((f_1495).ret_))));
(void)(({ hrv *_o4331 = &(g163); hr_fs(_o4331, hr_str(" _lrv", 5)); hr_fi(_o4331, i_1496); hr_fs(_o4331, hr_str(";\012", 2)); }));
(void)(({ hrv *_v4332 = &(g167); hsl _s4332 = ({ hsl _t4333 = hr_sl(g163); int64_t _l4333 = sv_1497, _h4333 = _t4333.n; if (_l4333 < 0 || _h4333 < _l4333 || _h4333 > _t4333.n) hr_slerr(_l4333, _h4333, _t4333.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1125"); (hsl){ _t4333.p + _l4333 * (int64_t)sizeof(uint8_t), _h4333 - _l4333 }; }); hr_append(_v4332, _s4332.p, _s4332.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4334 = &(g163); int64_t _k4334 = sv_1497; if (_k4334 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1125"); hr_resize(_v4334, _k4334, sizeof(uint8_t)); }));
 }
 } } _bk4327:; 
{ hrv *_v4336 = &(g409); for (int64_t _k4336 = 0; _k4336 < _v4336->n; _k4336++) { int32_t d_1538 = ((int32_t*)_v4336->b)[_k4336]; int64_t di_1539 = ((int64_t)(d_1538)); 
int64_t t_1540 = ((int64_t)((*({ hrv *_t4337 = &(g450); int64_t _i4337 = di_1539; (int32_t*)_t4337->b + hr_ix(_i4337, _t4337->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1128"); })))); 
int64_t g_1541 = ((int64_t)(((*({ hrv *_t4338 = &(g489); int64_t _i4338 = di_1539; (S5*)_t4338->b + hr_ix(_i4338, _t4338->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1129"); }))).node_)); 
if ((((f173_const_of(di_1539)) >= (((int64_t)0LL))) && ((((*({ hrv *_t4340 = &(g551); int64_t _i4340 = t_1540; (S1*)_t4340->b + hr_ix(_i4340, _t4340->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1130"); }))).k_) == (((uint8_t)12LL))))) { continue;
 }
int64_t sv_1542 = (g163).n; 
g401 = g403;
g179 = g403;
(void)(f260_ow(hr_str("static ", 7)));
(void)(f261_ct(t_1540));
(void)(({ hrv *_o4343 = &(g163); hr_fs(_o4343, hr_str(" g", 2)); hr_fi(_o4343, di_1539); hr_fs(_o4343, hr_str(";\012", 2)); }));
(void)(({ hrv *_v4344 = &(g167); hsl _s4344 = ({ hsl _t4345 = hr_sl(g163); int64_t _l4345 = sv_1542, _h4345 = _t4345.n; if (_l4345 < 0 || _h4345 < _l4345 || _h4345 > _t4345.n) hr_slerr(_l4345, _h4345, _t4345.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1134"); (hsl){ _t4345.p + _l4345 * (int64_t)sizeof(uint8_t), _h4345 - _l4345 }; }); hr_append(_v4344, _s4344.p, _s4344.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4346 = &(g163); int64_t _k4346 = sv_1542; if (_k4346 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1134"); hr_resize(_v4346, _k4346, sizeof(uint8_t)); }));
S4 x_1543 = (*({ hrv *_t4347 = &(g704); int64_t _i4347 = g_1541; (S4*)_t4347->b + hr_ix(_i4347, _t4347->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1135"); })); 
if ((((x_1543).b_) >= (((int32_t)0LL)))) { int64_t iv_1544 = f90_kid(((int64_t)((x_1543).b_)), ((int64_t)0LL)); 
int64_t sp_1545 = (g163).n; 
(void)(({ hrv *_o4349 = &(g163); hr_fs(_o4349, hr_str("g", 1)); hr_fi(_o4349, di_1539); hr_fs(_o4349, hr_str(" = ", 3)); }));
if (f268_is_res(t_1540)) { (void)(f269_gxo(iv_1544));
 } else { (void)(f289_gx(iv_1544));
 }
(void)(f260_ow(hr_str(";\012", 2)));
if ((((g176).n) > (((int64_t)0LL)))) { (void)(({ hrv *_v4354 = &(g177); _v4354->n = 0; }));
(void)(({ hrv *_v4355 = &(g177); hsl _s4355 = ({ hsl _t4356 = hr_sl(g163); int64_t _l4356 = sp_1545, _h4356 = _t4356.n; if (_l4356 < 0 || _h4356 < _l4356 || _h4356 > _t4356.n) hr_slerr(_l4356, _h4356, _t4356.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1142"); (hsl){ _t4356.p + _l4356 * (int64_t)sizeof(uint8_t), _h4356 - _l4356 }; }); hr_append(_v4355, _s4355.p, _s4355.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4357 = &(g163); int64_t _k4357 = sp_1545; if (_k4357 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1142"); hr_resize(_v4357, _k4357, sizeof(uint8_t)); }));
(void)(f260_ow(hr_str("{ ", 2)));
(void)(({ hrv *_v4359 = &(g163); hsl _s4359 = ({ hsl _t4360 = hr_sl(g176); int64_t _l4360 = 0, _h4360 = _t4360.n; if (_l4360 < 0 || _h4360 < _l4360 || _h4360 > _t4360.n) hr_slerr(_l4360, _h4360, _t4360.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1142"); (hsl){ _t4360.p + _l4360 * (int64_t)sizeof(uint8_t), _h4360 - _l4360 }; }); hr_append(_v4359, _s4359.p, _s4359.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4361 = &(g176); _v4361->n = 0; }));
(void)(({ hrv *_v4362 = &(g163); hsl _s4362 = ({ hsl _t4363 = hr_sl(g177); int64_t _l4363 = 0, _h4363 = _t4363.n; if (_l4363 < 0 || _h4363 < _l4363 || _h4363 > _t4363.n) hr_slerr(_l4363, _h4363, _t4363.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1142"); (hsl){ _t4363.p + _l4363 * (int64_t)sizeof(uint8_t), _h4363 - _l4363 }; }); hr_append(_v4362, _s4362.p, _s4362.n, sizeof(uint8_t)); }));
(void)(f260_ow(hr_str("}\012", 2)));
 }
(void)(({ hrv *_v4365 = &(g168); hsl _s4365 = ({ hsl _t4366 = hr_sl(g163); int64_t _l4366 = sp_1545, _h4366 = _t4366.n; if (_l4366 < 0 || _h4366 < _l4366 || _h4366 > _t4366.n) hr_slerr(_l4366, _h4366, _t4366.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1143"); (hsl){ _t4366.p + _l4366 * (int64_t)sizeof(uint8_t), _h4366 - _l4366 }; }); hr_append(_v4365, _s4365.p, _s4365.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4367 = &(g163); int64_t _k4367 = sp_1545; if (_k4367 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1143"); hr_resize(_v4367, _k4367, sizeof(uint8_t)); }));
 }
 } } _bk4335:; 
int64_t mi_2087 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v4369 = &(g388); for (int64_t _k4369 = 0; _k4369 < _v4369->n; _k4369++) { S6 f_2088 = ((S6*)_v4369->b)[_k4369]; int64_t i_2089 = (int64_t)_k4369; if (((((f_2088).node_) < (((int32_t)0LL))) || (((f_2088).st_) != (((uint8_t)2LL))))) { continue;
 }
int64_t node_2090 = ((int64_t)((f_2088).node_)); 
if ((((((*({ hrv *_t4370 = &(g704); int64_t _i4370 = node_2090; (S4*)_t4370->b + hr_ix(_i4370, _t4370->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1150"); }))).k_) != (((uint8_t)50LL))) || ((((uint16_t)((uint64_t)((*({ hrv *_t4371 = &(g704); int64_t _i4371 = node_2090; (S4*)_t4371->b + hr_ix(_i4371, _t4371->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1150"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))))) { continue;
 }
if (((((f_2088).par_) < (((int32_t)0LL))) && hr_streq(f10_nm(((int64_t)((f_2088).name_))), hr_str("main", 4)))) { mi_2087 = i_2089;
 }
(void)(f362_gen_fn(i_2089));
if ((((g182).n) > (((int64_t)0LL)))) { return false;
 }
 } } _bk4368:; 
(void)(({ hrv *_v4374 = out_1494; hsl _s4374 = hr_str("#include \"hrt.h\"\012", 17); hr_append(_v4374, _s4374.p, _s4374.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4375 = out_1494; hsl _s4375 = hr_sl(g164); hr_append(_v4375, _s4375.p, _s4375.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4376 = out_1494; hsl _s4376 = hr_str("#pragma pack(push, 1)\012", 22); hr_append(_v4376, _s4376.p, _s4376.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4377 = out_1494; hsl _s4377 = hr_sl(g165); hr_append(_v4377, _s4377.p, _s4377.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4378 = out_1494; hsl _s4378 = hr_str("#pragma pack(pop)\012", 18); hr_append(_v4378, _s4378.p, _s4378.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4379 = out_1494; hsl _s4379 = hr_sl(g166); hr_append(_v4379, _s4379.p, _s4379.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4380 = out_1494; hsl _s4380 = hr_sl(g167); hr_append(_v4380, _s4380.p, _s4380.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4381 = out_1494; hsl _s4381 = ({ hsl _t4382 = hr_sl(g169); int64_t _l4382 = 0, _h4382 = _t4382.n; if (_l4382 < 0 || _h4382 < _l4382 || _h4382 > _t4382.n) hr_slerr(_l4382, _h4382, _t4382.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1162"); (hsl){ _t4382.p + _l4382 * (int64_t)sizeof(uint8_t), _h4382 - _l4382 }; }); hr_append(_v4381, _s4381.p, _s4381.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4383 = out_1494; hsl _s4383 = ({ hsl _t4384 = hr_sl(g163); int64_t _l4384 = 0, _h4384 = _t4384.n; if (_l4384 < 0 || _h4384 < _l4384 || _h4384 > _t4384.n) hr_slerr(_l4384, _h4384, _t4384.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1163"); (hsl){ _t4384.p + _l4384 * (int64_t)sizeof(uint8_t), _h4384 - _l4384 }; }); hr_append(_v4383, _s4383.p, _s4383.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4385 = out_1494; hsl _s4385 = hr_str("static void hr_init_globals(void) {\012", 36); hr_append(_v4385, _s4385.p, _s4385.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4386 = out_1494; hsl _s4386 = hr_sl(g168); hr_append(_v4386, _s4386.p, _s4386.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4387 = out_1494; hsl _s4387 = hr_str("}\012", 2); hr_append(_v4387, _s4387.p, _s4387.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4388 = out_1494; hsl _s4388 = hr_str("static void hr_main(void) { ", 28); hr_append(_v4388, _s4388.p, _s4388.n, sizeof(uint8_t)); }));
if (((mi_2087) >= (((int64_t)0LL)))) { int64_t rt_2114 = ((int64_t)(((*({ hrv *_t4389 = &(g388); int64_t _i4389 = mi_2087; (S6*)_t4389->b + hr_ix(_i4389, _t4389->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1166"); }))).ret_)); 
if ((((rt_2114) >= (((int64_t)0LL))) && ((((*({ hrv *_t4390 = &(g551); int64_t _i4390 = rt_2114; (S1*)_t4390->b + hr_ix(_i4390, _t4390->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1166"); }))).k_) == (((uint8_t)3LL))))) { (void)(({ hrv *_v4391 = out_1494; hsl _s4391 = hr_str("hr_flush(); exit((int)", 22); hr_append(_v4391, _s4391.p, _s4391.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4392 = &(g163); _v4392->n = 0; }));
(void)(f323_fn_cname(mi_2087));
(void)(({ hrv *_v4394 = out_1494; hsl _s4394 = ({ hsl _t4395 = hr_sl(g163); int64_t _l4395 = 0, _h4395 = _t4395.n; if (_l4395 < 0 || _h4395 < _l4395 || _h4395 > _t4395.n) hr_slerr(_l4395, _h4395, _t4395.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1166"); (hsl){ _t4395.p + _l4395 * (int64_t)sizeof(uint8_t), _h4395 - _l4395 }; }); hr_append(_v4394, _s4394.p, _s4394.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4396 = out_1494; hsl _s4396 = hr_str("()", 2); hr_append(_v4396, _s4396.p, _s4396.n, sizeof(uint8_t)); }));
if ((((rt_2114) >= (((int64_t)0LL))) && ((((*({ hrv *_t4397 = &(g551); int64_t _i4397 = rt_2114; (S1*)_t4397->b + hr_ix(_i4397, _t4397->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1166"); }))).k_) == (((uint8_t)3LL))))) { (void)(({ hrv *_v4398 = out_1494; hsl _s4398 = hr_str(")", 1); hr_append(_v4398, _s4398.p, _s4398.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4399 = out_1494; hsl _s4399 = hr_str("; ", 2); hr_append(_v4399, _s4399.p, _s4399.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4400 = out_1494; hsl _s4400 = hr_str("}\012", 2); hr_append(_v4400, _s4400.p, _s4400.n, sizeof(uint8_t)); }));
return (((g182).n) == (((int64_t)0LL)));
}
static void f260_ow(hsl s_1498) {
(void)(({ hrv *_v4401 = &(g163); hsl _s4401 = s_1498; hr_append(_v4401, _s4401.p, _s4401.n, sizeof(uint8_t)); }));
}
static void f261_ct(int64_t t_1499) {
(void)(f262_cbody(t_1499));
(void)(f260_ow(f264_cn(t_1499)));
}
static void f262_cbody(int64_t t_1500) {
(void)(f263_cn_grow());
S1 x_1501 = (*({ hrv *_t4406 = &(g551); int64_t _i4406 = t_1500; (S1*)_t4406->b + hr_ix(_i4406, _t4406->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:51"); })); 
int64_t k_1502 = ((int64_t)((x_1501).k_)); 
if ((((k_1502) == (((int64_t)10LL))) || (((*({ hrv *_t4407 = &(g173); int64_t _i4407 = t_1500; (uint8_t*)_t4407->b + hr_ix(_i4407, _t4407->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:52"); }))) != (((uint8_t)0LL))))) { (void)(f264_cn(t_1500));
return;
 }
{ uint8_t *_t4409 = &((*({ hrv *_t4410 = &(g173); int64_t _i4410 = t_1500; (uint8_t*)_t4410->b + hr_ix(_i4410, _t4410->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:53"); }))); *_t4409 = ((uint8_t)1LL); }
(void)(f264_cn(t_1500));
if (((k_1502) == (((int64_t)7LL)))) { S9 v_1516 = (*({ hrv *_t4412 = &(g557); int64_t _i4412 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4413 = &(g556); int64_t _i4413 = (x_1501).a_; (S8*)_t4413->b + hr_ix(_i4413, _t4413->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:55"); }))).v0_)) + (int64_t)((int64_t)((x_1501).c_)))); (S9*)_t4412->b + hr_ix(_i4412, _t4412->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:55"); })); 
if ((((v_1516).si_) >= (((int32_t)0LL)))) { (void)(f262_cbody(f134_t_struct(((int64_t)((v_1516).si_)))));
 }
return;
 }
if (((k_1502) == (((int64_t)5LL)))) { int64_t si_1517 = ((int64_t)((x_1501).a_)); 
(void)(f144_si_layout(si_1517));
int64_t f0_1518 = ((int64_t)(((*({ hrv *_t4417 = &(g554); int64_t _i4417 = si_1517; (S10*)_t4417->b + hr_ix(_i4417, _t4417->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:58"); }))).f0_)); 
int64_t fnum_1519 = ((int64_t)(((*({ hrv *_t4418 = &(g554); int64_t _i4418 = si_1517; (S10*)_t4418->b + hr_ix(_i4418, _t4418->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:58"); }))).fnum_)); 
{ int64_t _e4420 = fnum_1519; for (int64_t _k4420 = 0; _k4420 < _e4420; _k4420++) { int64_t i_1520 = (int64_t)_k4420; int32_t ft_1521 = ((*({ hrv *_t4421 = &(g555); int64_t _i4421 = ((int64_t)((int64_t)f0_1518 + (int64_t)i_1520)); (S11*)_t4421->b + hr_ix(_i4421, _t4421->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:59"); }))).ty_; 
if (((ft_1521) >= (((int32_t)0LL)))) { (void)(f262_cbody(((int64_t)(ft_1521))));
 }
 } } _bk4419:; 
(void)(({ hrv *_v4423 = &(g165); hsl _s4423 = hr_str("struct ", 7); hr_append(_v4423, _s4423.p, _s4423.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4424 = &(g165); hsl _s4424 = f264_cn(t_1500); hr_append(_v4424, _s4424.p, _s4424.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4426 = &(g165); hsl _s4426 = hr_str(" { ", 3); hr_append(_v4426, _s4426.p, _s4426.n, sizeof(uint8_t)); }));
bool any_1522 = false; 
{ int64_t _e4428 = fnum_1519; for (int64_t _k4428 = 0; _k4428 < _e4428; _k4428++) { int64_t i_1523 = (int64_t)_k4428; S11 f_1524 = (*({ hrv *_t4429 = &(g555); int64_t _i4429 = ((int64_t)((int64_t)f0_1518 + (int64_t)i_1523)); (S11*)_t4429->b + hr_ix(_i4429, _t4429->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:63"); })); 
if ((((f_1524).ty_) < (((int32_t)0LL)))) { if ((((f_1524).padn_) > (((int32_t)0LL)))) { (void)(({ hrv *_o4430 = &(g165); hr_fs(_o4430, hr_str("uint8_t _p", 10)); hr_fi(_o4430, i_1523); hr_fs(_o4430, hr_str("[", 1)); hr_fi(_o4430, (f_1524).padn_); hr_fs(_o4430, hr_str("]; ", 3)); }));
any_1522 = true;
 }
continue;
 }
(void)(({ hrv *_v4431 = &(g165); hsl _s4431 = f264_cn(((int64_t)((f_1524).ty_))); hr_append(_v4431, _s4431.p, _s4431.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4433 = &(g165); uint8_t _x4433 = ((uint8_t)32LL); uint8_t *_p4433 = (uint8_t*)hr_grow(_v4433, 1, sizeof _x4433); *_p4433 = _x4433; _p4433; }));
(void)(f267_fname_into((&(g165)), ((int64_t)((f_1524).name_))));
(void)(({ hrv *_v4435 = &(g165); hsl _s4435 = hr_str("; ", 2); hr_append(_v4435, _s4435.p, _s4435.n, sizeof(uint8_t)); }));
any_1522 = true;
 } } _bk4427:; 
if ((!(any_1522))) { (void)(({ hrv *_v4436 = &(g165); hsl _s4436 = hr_str("uint8_t _e; ", 12); hr_append(_v4436, _s4436.p, _s4436.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4437 = &(g165); hsl _s4437 = hr_str("};\012", 3); hr_append(_v4437, _s4437.p, _s4437.n, sizeof(uint8_t)); }));
return;
 }
if (((k_1502) == (((int64_t)6LL)))) { int64_t ei_1528 = ((int64_t)((x_1501).a_)); 
(void)(f146_ei_layout(ei_1528));
int64_t v0_1529 = ((int64_t)(((*({ hrv *_t4439 = &(g556); int64_t _i4439 = ei_1528; (S8*)_t4439->b + hr_ix(_i4439, _t4439->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:73"); }))).v0_)); 
bool pay_1530 = false; 
{ int32_t _e4441 = ((*({ hrv *_t4442 = &(g556); int64_t _i4442 = ei_1528; (S8*)_t4442->b + hr_ix(_i4442, _t4442->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:75"); }))).vnum_; for (int32_t _k4441 = 0; _k4441 < _e4441; _k4441++) { int32_t i_1531 = (int32_t)_k4441; S9 v_1532 = (*({ hrv *_t4443 = &(g557); int64_t _i4443 = ((int64_t)((int64_t)v0_1529 + (int64_t)((int64_t)(i_1531)))); (S9*)_t4443->b + hr_ix(_i4443, _t4443->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:75"); })); 
if (((((v_1532).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4444 = &(g554); int64_t _i4444 = (v_1532).si_; (S10*)_t4444->b + hr_ix(_i4444, _t4444->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:75"); }))).zero_)))) { (void)(f262_cbody(f134_t_struct(((int64_t)((v_1532).si_)))));
pay_1530 = true;
 }
 } } _bk4440:; 
(void)(({ hrv *_v4447 = &(g165); hsl _s4447 = hr_str("struct ", 7); hr_append(_v4447, _s4447.p, _s4447.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4448 = &(g165); hsl _s4448 = f264_cn(t_1500); hr_append(_v4448, _s4448.p, _s4448.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4450 = &(g165); hsl _s4450 = ({ hsl _r4451; if (((((*({ hrv *_t4452 = &(g556); int64_t _i4452 = ei_1528; (S8*)_t4452->b + hr_ix(_i4452, _t4452->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:76"); }))).tagsz_) == (((uint8_t)1LL)))) { _r4451 = hr_str(" { uint8_t tag; ", 16);  } else { _r4451 = hr_str(" { uint16_t tag; ", 17);  } _r4451; }); hr_append(_v4450, _s4450.p, _s4450.n, sizeof(uint8_t)); }));
if (pay_1530) { (void)(({ hrv *_v4453 = &(g165); hsl _s4453 = hr_str("union { ", 8); hr_append(_v4453, _s4453.p, _s4453.n, sizeof(uint8_t)); }));
{ int32_t _e4455 = ((*({ hrv *_t4456 = &(g556); int64_t _i4456 = ei_1528; (S8*)_t4456->b + hr_ix(_i4456, _t4456->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:77"); }))).vnum_; for (int32_t _k4455 = 0; _k4455 < _e4455; _k4455++) { int32_t i_1533 = (int32_t)_k4455; S9 v_1534 = (*({ hrv *_t4457 = &(g557); int64_t _i4457 = ((int64_t)((int64_t)v0_1529 + (int64_t)((int64_t)(i_1533)))); (S9*)_t4457->b + hr_ix(_i4457, _t4457->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:77"); })); 
if (((((v_1534).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4458 = &(g554); int64_t _i4458 = (v_1534).si_; (S10*)_t4458->b + hr_ix(_i4458, _t4458->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:77"); }))).zero_)))) { (void)(({ hrv *_v4459 = &(g165); hsl _s4459 = f264_cn(f134_t_struct(((int64_t)((v_1534).si_)))); hr_append(_v4459, _s4459.p, _s4459.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4462 = &(g165); hr_fs(_o4462, hr_str(" v", 2)); hr_fi(_o4462, i_1533); hr_fs(_o4462, hr_str("; ", 2)); }));
 }
 } } _bk4454:; 
(void)(({ hrv *_v4463 = &(g165); hsl _s4463 = hr_str("} u; ", 5); hr_append(_v4463, _s4463.p, _s4463.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4464 = &(g165); hsl _s4464 = hr_str("};\012", 3); hr_append(_v4464, _s4464.p, _s4464.n, sizeof(uint8_t)); }));
return;
 }
if (((k_1502) == (((int64_t)8LL)))) { int64_t a_1535 = ((int64_t)((x_1501).s_)); 
if ((((a_1535) == (((int64_t)1LL))) || (((a_1535) == (((int64_t)3LL))) && (((x_1501).b_) >= (((int64_t)0LL)))))) { (void)(f262_cbody(((int64_t)((x_1501).a_))));
(void)(({ hrv *_v4466 = &(g165); hsl _s4466 = hr_str("struct ", 7); hr_append(_v4466, _s4466.p, _s4466.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4467 = &(g165); hsl _s4467 = f264_cn(t_1500); hr_append(_v4467, _s4467.p, _s4467.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4469 = &(g165); hsl _s4469 = hr_str(" { ", 3); hr_append(_v4469, _s4469.p, _s4469.n, sizeof(uint8_t)); }));
if (((a_1535) == (((int64_t)3LL)))) { (void)(({ hrv *_v4470 = &(g165); hsl _s4470 = (g183).e[hr_ix(((int64_t)((int64_t)f124_lim_lenstore((x_1501).b_) & (int64_t)((int64_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:86")]; hr_append(_v4470, _s4470.p, _s4470.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4473 = &(g165); hsl _s4473 = hr_str(" n; ", 4); hr_append(_v4473, _s4473.p, _s4473.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4474 = &(g165); hsl _s4474 = f264_cn(((int64_t)((x_1501).a_))); hr_append(_v4474, _s4474.p, _s4474.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4476 = &(g165); hr_fs(_o4476, hr_str(" e[", 3)); hr_fi(_o4476, f103_max((x_1501).b_, ((int64_t)1LL))); hr_fs(_o4476, hr_str("]; };\012", 6)); }));
 }
return;
 }
if (((k_1502) == (((int64_t)14LL)))) { { int32_t _e4479 = (x_1501).n_; for (int32_t _k4479 = 0; _k4479 < _e4479; _k4479++) { int32_t i_1536 = (int32_t)_k4479; (void)(f262_cbody(((int64_t)((*({ hrv *_t4481 = &(g552); int64_t _i4481 = ((int64_t)((int64_t)((int64_t)((x_1501).l_)) + (int64_t)((int64_t)(i_1536)))); (int32_t*)_t4481->b + hr_ix(_i4481, _t4481->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:92"); }))))));
 } } _bk4478:; 
(void)(({ hrv *_v4482 = &(g165); hsl _s4482 = hr_str("struct ", 7); hr_append(_v4482, _s4482.p, _s4482.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4483 = &(g165); hsl _s4483 = f264_cn(t_1500); hr_append(_v4483, _s4483.p, _s4483.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4485 = &(g165); hsl _s4485 = hr_str(" { ", 3); hr_append(_v4485, _s4485.p, _s4485.n, sizeof(uint8_t)); }));
{ int32_t _e4487 = (x_1501).n_; for (int32_t _k4487 = 0; _k4487 < _e4487; _k4487++) { int32_t i_1537 = (int32_t)_k4487; (void)(({ hrv *_v4488 = &(g165); hsl _s4488 = f264_cn(((int64_t)((*({ hrv *_t4490 = &(g552); int64_t _i4490 = ((int64_t)((int64_t)((int64_t)((x_1501).l_)) + (int64_t)((int64_t)(i_1537)))); (int32_t*)_t4490->b + hr_ix(_i4490, _t4490->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:94"); }))))); hr_append(_v4488, _s4488.p, _s4488.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4491 = &(g165); hr_fs(_o4491, hr_str(" r", 2)); hr_fi(_o4491, i_1537); hr_fs(_o4491, hr_str("; ", 2)); }));
 } } _bk4486:; 
(void)(({ hrv *_v4492 = &(g165); hsl _s4492 = hr_str("};\012", 3); hr_append(_v4492, _s4492.p, _s4492.n, sizeof(uint8_t)); }));
 }
}
static void f263_cn_grow(void) {
while ((((g171).n) < ((g551).n))) { (void)(({ hrv *_v4494 = &(g171); int32_t _x4494 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p4494 = (int32_t*)hr_grow(_v4494, 1, sizeof _x4494); *_p4494 = _x4494; _p4494; }));
(void)(({ hrv *_v4495 = &(g172); int32_t _x4495 = ((int32_t)0LL); int32_t *_p4495 = (int32_t*)hr_grow(_v4495, 1, sizeof _x4495); *_p4495 = _x4495; _p4495; }));
(void)(({ hrv *_v4496 = &(g173); uint8_t _x4496 = ((uint8_t)0LL); uint8_t *_p4496 = (uint8_t*)hr_grow(_v4496, 1, sizeof _x4496); *_p4496 = _x4496; _p4496; }));
(void)(({ hrv *_v4497 = &(g174); uint8_t _x4497 = ((uint8_t)0LL); uint8_t *_p4497 = (uint8_t*)hr_grow(_v4497, 1, sizeof _x4497); *_p4497 = _x4497; _p4497; }));
(void)(({ hrv *_v4498 = &(g175); uint8_t _x4498 = ((uint8_t)0LL); uint8_t *_p4498 = (uint8_t*)hr_grow(_v4498, 1, sizeof _x4498); *_p4498 = _x4498; _p4498; }));
 } _bk4493:; 
}
static hsl f264_cn(int64_t t_1503) {
(void)(f263_cn_grow());
if ((((*({ hrv *_t4500 = &(g171); int64_t _i4500 = t_1503; (int32_t*)_t4500->b + hr_ix(_i4500, _t4500->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:23"); }))) < (((int32_t)0LL)))) { (void)(f265_cn_make(t_1503));
 }
int64_t o_1515 = ((int64_t)((*({ hrv *_t4502 = &(g171); int64_t _i4502 = t_1503; (int32_t*)_t4502->b + hr_ix(_i4502, _t4502->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:24"); })))); 
return ({ hsl _t4503 = hr_sl(g170); int64_t _l4503 = o_1515, _h4503 = ((int64_t)((int64_t)o_1515 + (int64_t)((int64_t)((*({ hrv *_t4504 = &(g172); int64_t _i4504 = t_1503; (int32_t*)_t4504->b + hr_ix(_i4504, _t4504->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:25"); })))))); if (_l4503 < 0 || _h4503 < _l4503 || _h4503 > _t4503.n) hr_slerr(_l4503, _h4503, _t4503.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:25"); (hsl){ _t4503.p + _l4503 * (int64_t)sizeof(uint8_t), _h4503 - _l4503 }; });
}
static void f265_cn_make(int64_t t_1504) {
S1 x_1505 = (*({ hrv *_t4505 = &(g551); int64_t _i4505 = t_1504; (S1*)_t4505->b + hr_ix(_i4505, _t4505->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:28"); })); 
int64_t k_1506 = ((int64_t)((x_1505).k_)); 
if ((((k_1506) == (((int64_t)10LL))) && (((x_1505).c_) < (((int32_t)0LL))))) { hsl e_1507 = f264_cn(((int64_t)((x_1505).a_))); 
int64_t s0_1508 = (g170).n; 
(void)(({ hrv *_v4507 = &(g170); hsl _s4507 = e_1507; hr_append(_v4507, _s4507.p, _s4507.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4508 = &(g170); uint8_t _x4508 = ((uint8_t)42LL); uint8_t *_p4508 = (uint8_t*)hr_grow(_v4508, 1, sizeof _x4508); *_p4508 = _x4508; _p4508; }));
{ int32_t *_t4509 = &((*({ hrv *_t4510 = &(g171); int64_t _i4510 = t_1504; (int32_t*)_t4510->b + hr_ix(_i4510, _t4510->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:29"); }))); *_t4509 = ((int32_t)(s0_1508)); }
{ int32_t *_t4511 = &((*({ hrv *_t4512 = &(g172); int64_t _i4512 = t_1504; (int32_t*)_t4512->b + hr_ix(_i4512, _t4512->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:29"); }))); *_t4511 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1508)))); }
return;
 }
if (((k_1506) == (((int64_t)7LL)))) { S9 v_1509 = (*({ hrv *_t4513 = &(g557); int64_t _i4513 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4514 = &(g556); int64_t _i4514 = (x_1505).a_; (S8*)_t4514->b + hr_ix(_i4514, _t4514->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:30"); }))).v0_)) + (int64_t)((int64_t)((x_1505).c_)))); (S9*)_t4513->b + hr_ix(_i4513, _t4513->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:30"); })); 
if ((((v_1509).si_) >= (((int32_t)0LL)))) { hsl e_1510 = f264_cn(f134_t_struct(((int64_t)((v_1509).si_)))); 
int64_t s0_1511 = (g170).n; 
(void)(({ hrv *_v4517 = &(g170); hsl _s4517 = e_1510; hr_append(_v4517, _s4517.p, _s4517.n, sizeof(uint8_t)); }));
{ int32_t *_t4518 = &((*({ hrv *_t4519 = &(g171); int64_t _i4519 = t_1504; (int32_t*)_t4519->b + hr_ix(_i4519, _t4519->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:30"); }))); *_t4518 = ((int32_t)(s0_1511)); }
{ int32_t *_t4520 = &((*({ hrv *_t4521 = &(g172); int64_t _i4521 = t_1504; (int32_t*)_t4521->b + hr_ix(_i4521, _t4521->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:30"); }))); *_t4520 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1511)))); }
return;
 }
 }
int64_t s0_1512 = (g170).n; 
if (((k_1506) == (((int64_t)3LL)))) { (void)(({ hrv *_v4522 = &(g170); hsl _s4522 = (g183).e[hr_ix(((uint8_t)((uint64_t)(x_1505).s_ & (uint64_t)((uint8_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:32")]; hr_append(_v4522, _s4522.p, _s4522.n, sizeof(uint8_t)); }));
 } else { if (((k_1506) == (((int64_t)10LL)))) { (void)(({ hrv *_v4524 = &(g170); hsl _s4524 = (g183).e[hr_ix(((int32_t)((int64_t)((int32_t)((int64_t)(x_1505).c_ & (int64_t)((int32_t)3LL))) + (int64_t)((int32_t)4LL))), 8, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:33")]; hr_append(_v4524, _s4524.p, _s4524.n, sizeof(uint8_t)); }));
 } else { if (((k_1506) == (((int64_t)2LL)))) { (void)(({ hrv *_v4526 = &(g170); hsl _s4526 = hr_str("bool", 4); hr_append(_v4526, _s4526.p, _s4526.n, sizeof(uint8_t)); }));
 } else { if (((k_1506) == (((int64_t)4LL)))) { (void)(({ hrv *_v4527 = &(g170); hsl _s4527 = ({ hsl _r4528; if ((((x_1505).s_) == (((uint8_t)4LL)))) { _r4528 = hr_str("float", 5);  } else { _r4528 = hr_str("double", 6);  } _r4528; }); hr_append(_v4527, _s4527.p, _s4527.n, sizeof(uint8_t)); }));
 } else { if (((k_1506) == (((int64_t)1LL)))) { (void)(({ hrv *_v4529 = &(g170); hsl _s4529 = hr_str("void", 4); hr_append(_v4529, _s4529.p, _s4529.n, sizeof(uint8_t)); }));
 } else { if (((k_1506) == (((int64_t)5LL)))) { (void)(({ hrv *_o4530 = &(g170); hr_fs(_o4530, hr_str("S", 1)); hr_fi(_o4530, (x_1505).a_); }));
(void)(f266_fwd(s0_1512));
 } else { if (((k_1506) == (((int64_t)6LL)))) { (void)(({ hrv *_o4532 = &(g170); hr_fs(_o4532, hr_str("E", 1)); hr_fi(_o4532, (x_1505).a_); }));
(void)(f266_fwd(s0_1512));
 } else { if (((k_1506) == (((int64_t)7LL)))) { (void)(({ hrv *_v4534 = &(g170); hsl _s4534 = hr_str("hr_unit", 7); hr_append(_v4534, _s4534.p, _s4534.n, sizeof(uint8_t)); }));
 } else { if (((k_1506) == (((int64_t)8LL)))) { int64_t a_1514 = ((int64_t)((x_1505).s_)); 
if ((((a_1514) == (((int64_t)4LL))) || ((a_1514) == (((int64_t)5LL))))) { (void)(({ hrv *_v4535 = &(g170); hsl _s4535 = hr_str("hrv", 3); hr_append(_v4535, _s4535.p, _s4535.n, sizeof(uint8_t)); }));
 } else { if (((a_1514) == (((int64_t)1LL)))) { (void)(({ hrv *_o4536 = &(g170); hr_fs(_o4536, hr_str("A", 1)); hr_fi(_o4536, t_1504); }));
(void)(f266_fwd(s0_1512));
 } else { if ((((a_1514) == (((int64_t)3LL))) && (((x_1505).b_) >= (((int64_t)0LL))))) { (void)(({ hrv *_o4538 = &(g170); hr_fs(_o4538, hr_str("L", 1)); hr_fi(_o4538, t_1504); }));
(void)(f266_fwd(s0_1512));
 } else { (void)(({ hrv *_v4540 = &(g170); hsl _s4540 = hr_str("uint8_t*", 8); hr_append(_v4540, _s4540.p, _s4540.n, sizeof(uint8_t)); }));
 }
 }
 }
 } else { if (((((k_1506) == (((int64_t)9LL))) || ((k_1506) == (((int64_t)18LL)))) || ((k_1506) == (((int64_t)19LL))))) { (void)(({ hrv *_v4541 = &(g170); hsl _s4541 = hr_str("hsl", 3); hr_append(_v4541, _s4541.p, _s4541.n, sizeof(uint8_t)); }));
 } else { if (((k_1506) == (((int64_t)14LL)))) { (void)(({ hrv *_o4542 = &(g170); hr_fs(_o4542, hr_str("M", 1)); hr_fi(_o4542, t_1504); }));
(void)(f266_fwd(s0_1512));
 } else { if ((((k_1506) == (((int64_t)12LL))) || ((k_1506) == (((int64_t)17LL))))) { (void)(({ hrv *_v4544 = &(g170); hsl _s4544 = hr_str("int64_t", 7); hr_append(_v4544, _s4544.p, _s4544.n, sizeof(uint8_t)); }));
 } else { if (((k_1506) == (((int64_t)13LL)))) { (void)(({ hrv *_v4545 = &(g170); hsl _s4545 = hr_str("double", 6); hr_append(_v4545, _s4545.p, _s4545.n, sizeof(uint8_t)); }));
 } else { (void)(({ hrv *_v4546 = &(g170); hsl _s4546 = hr_str("void*", 5); hr_append(_v4546, _s4546.p, _s4546.n, sizeof(uint8_t)); }));
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
{ int32_t *_t4547 = &((*({ hrv *_t4548 = &(g171); int64_t _i4548 = t_1504; (int32_t*)_t4548->b + hr_ix(_i4548, _t4548->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:46"); }))); *_t4547 = ((int32_t)(s0_1512)); }
{ int32_t *_t4549 = &((*({ hrv *_t4550 = &(g172); int64_t _i4550 = t_1504; (int32_t*)_t4550->b + hr_ix(_i4550, _t4550->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:46"); }))); *_t4549 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1512)))); }
}
static void f266_fwd(int64_t s0_1513) {
(void)(({ hrv *_v4551 = &(g164); hsl _s4551 = hr_str("typedef struct ", 15); hr_append(_v4551, _s4551.p, _s4551.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4552 = &(g164); hsl _s4552 = ({ hsl _t4553 = hr_sl(g170); int64_t _l4553 = s0_1513, _h4553 = _t4553.n; if (_l4553 < 0 || _h4553 < _l4553 || _h4553 > _t4553.n) hr_slerr(_l4553, _h4553, _t4553.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:17"); (hsl){ _t4553.p + _l4553 * (int64_t)sizeof(uint8_t), _h4553 - _l4553 }; }); hr_append(_v4552, _s4552.p, _s4552.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4554 = &(g164); uint8_t _x4554 = ((uint8_t)32LL); uint8_t *_p4554 = (uint8_t*)hr_grow(_v4554, 1, sizeof _x4554); *_p4554 = _x4554; _p4554; }));
(void)(({ hrv *_v4555 = &(g164); hsl _s4555 = ({ hsl _t4556 = hr_sl(g170); int64_t _l4556 = s0_1513, _h4556 = _t4556.n; if (_l4556 < 0 || _h4556 < _l4556 || _h4556 > _t4556.n) hr_slerr(_l4556, _h4556, _t4556.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:17"); (hsl){ _t4556.p + _l4556 * (int64_t)sizeof(uint8_t), _h4556 - _l4556 }; }); hr_append(_v4555, _s4555.p, _s4555.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4557 = &(g164); hsl _s4557 = hr_str(";\012", 2); hr_append(_v4557, _s4557.p, _s4557.n, sizeof(uint8_t)); }));
}
static void f267_fname_into(hrv* b_1525, int64_t name_1526) {
{ hsl _v4559 = f10_nm(name_1526); for (int64_t _k4559 = 0; _k4559 < _v4559.n; _k4559++) { uint8_t c_1527 = ((uint8_t*)_v4559.p)[_k4559]; (void)(({ hrv *_v4561 = b_1525; uint8_t _x4561 = ({ uint8_t _r4562; if (((c_1527) == (((uint8_t)58LL)))) { _r4562 = ((uint8_t)95LL);  } else { _r4562 = c_1527;  } _r4562; }); uint8_t *_p4561 = (uint8_t*)hr_grow(_v4561, 1, sizeof _x4561); *_p4561 = _x4561; _p4561; }));
 } } _bk4558:; 
(void)(({ hrv *_v4563 = b_1525; uint8_t _x4563 = ((uint8_t)95LL); uint8_t *_p4563 = (uint8_t*)hr_grow(_v4563, 1, sizeof _x4563); *_p4563 = _x4563; _p4563; }));
}
static bool f268_is_res(int64_t t_1546) {
return (((((*({ hrv *_t4564 = &(g551); int64_t _i4564 = t_1546; (S1*)_t4564->b + hr_ix(_i4564, _t4564->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:18"); }))).k_) == (((uint8_t)8LL))) && (((((int64_t)(((*({ hrv *_t4565 = &(g551); int64_t _i4565 = t_1546; (S1*)_t4565->b + hr_ix(_i4565, _t4565->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:18"); }))).s_))) == (((int64_t)4LL))) || ((((int64_t)(((*({ hrv *_t4566 = &(g551); int64_t _i4566 = t_1546; (S1*)_t4566->b + hr_ix(_i4566, _t4566->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:18"); }))).s_))) == (((int64_t)5LL)))));
}
static void f269_gxo(int64_t n_1547) {
int64_t c_1548 = f150_cv(n_1547); 
int64_t t_1549 = f141_at(n_1547); 
if ((((c_1548) >= (((int64_t)0LL))) && ((c_1548) != (t_1549)))) { if (f268_is_res(c_1548)) { (void)(f270_gcv(n_1547, t_1549, c_1548));
return;
 }
(void)(f289_gx(n_1547));
return;
 }
if ((f268_is_res(t_1549) && f272_is_place(n_1547))) { (void)(f260_ow(hr_str("hr_rdup(", 8)));
(void)(f275_gx0(n_1547));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f326_esz(((int64_t)(((*({ hrv *_t4578 = &(g551); int64_t _i4578 = t_1549; (S1*)_t4578->b + hr_ix(_i4578, _t4578->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:160"); }))).a_))));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
(void)(f275_gx0(n_1547));
}
static void f270_gcv(int64_t n_1550, int64_t f_1551, int64_t t_1552) {
if (((f_1551) == (t_1552))) { (void)(f271_gx1(n_1550));
return;
 }
int64_t fk_2079 = ((int64_t)(((*({ hrv *_t4582 = &(g551); int64_t _i4582 = f_1551; (S1*)_t4582->b + hr_ix(_i4582, _t4582->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:207"); }))).k_)); 
int64_t tk0_2080 = ((int64_t)(((*({ hrv *_t4583 = &(g551); int64_t _i4583 = t_1552; (S1*)_t4583->b + hr_ix(_i4583, _t4583->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:207"); }))).k_)); 
if (((((tk0_2080) == (((int64_t)2LL))) && ((fk_2079) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4584 = &(g551); int64_t _i4584 = f_1551; (S1*)_t4584->b + hr_ix(_i4584, _t4584->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:208"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f271_gx1(n_1550));
(void)(f260_ow(hr_str(") != 0)", 7)));
return;
 }
if (((((fk_2079) == (((int64_t)10LL))) && ((((*({ hrv *_t4588 = &(g551); int64_t _i4588 = f_1551; (S1*)_t4588->b + hr_ix(_i4588, _t4588->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:209"); }))).c_) < (((int32_t)0LL)))) && ((tk0_2080) != (((int64_t)10LL))))) { int64_t m_2081 = ((int64_t)(((*({ hrv *_t4589 = &(g551); int64_t _i4589 = f_1551; (S1*)_t4589->b + hr_ix(_i4589, _t4589->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:210"); }))).a_)); 
if (((m_2081) == (t_1552))) { (void)(f260_ow(hr_str("(*", 2)));
(void)(f271_gx1(n_1550));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if ((((tk0_2080) == (((int64_t)9LL))) && (((((*({ hrv *_t4593 = &(g551); int64_t _i4593 = m_2081; (S1*)_t4593->b + hr_ix(_i4593, _t4593->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:212"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t4594 = &(g551); int64_t _i4594 = m_2081; (S1*)_t4594->b + hr_ix(_i4594, _t4594->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:212"); }))).k_) == (((uint8_t)9LL)))))) { (void)(f292_gsl(n_1550, f_1551));
return;
 }
if ((((tk0_2080) == (((int64_t)3LL))) || ((tk0_2080) == (((int64_t)4LL))))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1552));
(void)(f260_ow(hr_str(")(*", 3)));
(void)(f271_gx1(n_1550));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (f268_is_res(t_1552)) { (void)(f260_ow(hr_str("hr_rfrom(", 9)));
(void)(f292_gsl(n_1550, f_1551));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f326_esz(((int64_t)(((*({ hrv *_t4606 = &(g551); int64_t _i4606 = t_1552; (S1*)_t4606->b + hr_ix(_i4606, _t4606->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:214"); }))).a_))));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
(void)(f260_ow(hr_str("(*", 2)));
(void)(f271_gx1(n_1550));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((((tk0_2080) == (((int64_t)3LL))) || ((tk0_2080) == (((int64_t)4LL)))) && ((((fk_2079) == (((int64_t)3LL))) || ((fk_2079) == (((int64_t)4LL)))) || ((fk_2079) == (((int64_t)2LL)))))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1552));
(void)(f260_ow(hr_str(")(", 2)));
(void)(f271_gx1(n_1550));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (((tk0_2080) == (((int64_t)9LL)))) { (void)(f292_gsl(n_1550, f_1551));
return;
 }
if ((((tk0_2080) == (((int64_t)6LL))) && ((fk_2079) == (((int64_t)7LL))))) { int64_t vi_2082 = ((int64_t)(((*({ hrv *_t4617 = &(g551); int64_t _i4617 = f_1551; (S1*)_t4617->b + hr_ix(_i4617, _t4617->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:220"); }))).c_)); 
int64_t ei_2083 = ((int64_t)(((*({ hrv *_t4618 = &(g551); int64_t _i4618 = f_1551; (S1*)_t4618->b + hr_ix(_i4618, _t4618->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:220"); }))).a_)); 
S9 v_2084 = (*({ hrv *_t4619 = &(g557); int64_t _i4619 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4620 = &(g556); int64_t _i4620 = ei_2083; (S8*)_t4620->b + hr_ix(_i4620, _t4620->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:220"); }))).v0_)) + (int64_t)vi_2082)); (S9*)_t4619->b + hr_ix(_i4619, _t4619->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:220"); })); 
int64_t p_2085 = f293_nt(); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(t_1552));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_2085));
(void)(f260_ow(hr_str("; memset(&_t", 12)));
(void)(f294_oi(p_2085));
(void)(f260_ow(hr_str(", 0, sizeof _t", 14)));
(void)(f294_oi(p_2085));
(void)(f260_ow(hr_str("); _t", 5)));
(void)(f294_oi(p_2085));
(void)(({ hrv *_o4632 = &(g163); hr_fs(_o4632, hr_str(".tag = ", 7)); hr_fi(_o4632, vi_2082); hr_fs(_o4632, hr_str("; ", 2)); }));
if (((((v_2084).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4633 = &(g554); int64_t _i4633 = (v_2084).si_; (S10*)_t4633->b + hr_ix(_i4633, _t4633->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:223"); }))).zero_)))) { (void)(f260_ow(hr_str("_t", 2)));
(void)(f294_oi(p_2085));
(void)(({ hrv *_o4636 = &(g163); hr_fs(_o4636, hr_str(".u.v", 4)); hr_fi(_o4636, vi_2082); hr_fs(_o4636, hr_str(" = ", 3)); }));
(void)(f271_gx1(n_1550));
(void)(f260_ow(hr_str("; ", 2)));
 } else { (void)(f260_ow(hr_str("(void)(", 7)));
(void)(f271_gx1(n_1550));
(void)(f260_ow(hr_str("); ", 3)));
 }
(void)(f260_ow(hr_str("_t", 2)));
(void)(f294_oi(p_2085));
(void)(f260_ow(hr_str("; })", 4)));
return;
 }
if (((tk0_2080) == (((int64_t)10LL)))) { if (((fk_2079) == (((int64_t)10LL)))) { (void)(f271_gx1(n_1550));
return;
 }
(void)(f324_gaddr(n_1550));
return;
 }
if (f268_is_res(t_1552)) { (void)(f260_ow(hr_str("hr_rfrom(", 9)));
(void)(f292_gsl(n_1550, f_1551));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f326_esz(((int64_t)(((*({ hrv *_t4652 = &(g551); int64_t _i4652 = t_1552; (S1*)_t4652->b + hr_ix(_i4652, _t4652->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:228"); }))).a_))));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if ((f282_is_fix(t_1552) || f283_is_lim(t_1552))) { int64_t p_2086 = f293_nt(); 
(void)(f260_ow(hr_str("({ hsl _t", 9)));
(void)(f294_oi(p_2086));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f292_gsl(n_1550, f_1551));
(void)(f260_ow(hr_str("; ", 2)));
(void)(f261_ct(t_1552));
(void)(f260_ow(hr_str(" _r", 3)));
(void)(f294_oi(p_2086));
(void)(f260_ow(hr_str("; ", 2)));
if (f282_is_fix(t_1552)) { (void)(({ hrv *_o4667 = &(g163); hr_fs(_o4667, hr_str("if (_t", 6)); hr_fi(_o4667, p_2086); hr_fs(_o4667, hr_str(".n != ", 6)); hr_fi(_o4667, ((*({ hrv *_t4668 = &(g551); int64_t _i4668 = t_1552; (S1*)_t4668->b + hr_ix(_i4668, _t4668->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:232"); }))).b_); hr_fs(_o4667, hr_str(") hr_die(\"array length mismatch\", ", 34)); }));
(void)(f312_wloc(n_1550));
(void)(f260_ow(hr_str("); ", 3)));
 } else { (void)(({ hrv *_o4671 = &(g163); hr_fs(_o4671, hr_str("if (_t", 6)); hr_fi(_o4671, p_2086); hr_fs(_o4671, hr_str(".n > ", 5)); hr_fi(_o4671, ((*({ hrv *_t4672 = &(g551); int64_t _i4672 = t_1552; (S1*)_t4672->b + hr_ix(_i4672, _t4672->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:233"); }))).b_); hr_fs(_o4671, hr_str(") hr_die(\"too many elements for a limited array\", ", 50)); }));
(void)(f312_wloc(n_1550));
(void)(({ hrv *_o4674 = &(g163); hr_fs(_o4674, hr_str("); _r", 5)); hr_fi(_o4674, p_2086); hr_fs(_o4674, hr_str(".n = _t", 7)); hr_fi(_o4674, p_2086); hr_fs(_o4674, hr_str(".n; ", 4)); }));
 }
(void)(({ hrv *_o4675 = &(g163); hr_fs(_o4675, hr_str("memcpy(_r", 9)); hr_fi(_o4675, p_2086); hr_fs(_o4675, hr_str(".e, _t", 6)); hr_fi(_o4675, p_2086); hr_fs(_o4675, hr_str(".p, (size_t)_t", 14)); hr_fi(_o4675, p_2086); hr_fs(_o4675, hr_str(".n * sizeof _r", 14)); hr_fi(_o4675, p_2086); hr_fs(_o4675, hr_str(".e[0]); _r", 10)); hr_fi(_o4675, p_2086); hr_fs(_o4675, hr_str("; })", 4)); }));
return;
 }
(void)(f271_gx1(n_1550));
}
static void f271_gx1(int64_t n_1553) {
if ((f268_is_res(f141_at(n_1553)) && (!(f272_is_place(n_1553))))) { int64_t k_1561 = f273_tmp(f141_at(n_1553), true); 
(void)(f260_ow(hr_str("(*hr_tmp(&", 10)));
(void)(f274_ot(k_1561));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f275_gx0(n_1553));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
(void)(f275_gx0(n_1553));
}
static bool f272_is_place(int64_t n_1554) {
S4 x_1555 = (*({ hrv *_t4688 = &(g704); int64_t _i4688 = n_1554; (S4*)_t4688->b + hr_ix(_i4688, _t4688->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:122"); })); 
int64_t k_1556 = ((int64_t)((x_1555).k_)); 
if (((k_1556) == (((int64_t)8LL)))) { int64_t r_1557 = f156_rk(n_1554); 
return (((r_1557) == (((int64_t)1LL))) || ((r_1557) == (((int64_t)2LL))));
 }
if (((k_1556) == (((int64_t)14LL)))) { return (((f156_rk(n_1554)) == (((int64_t)5LL))) && (f272_is_place(((int64_t)((x_1555).a_))) || ((((*({ hrv *_t4692 = &(g551); int64_t _i4692 = f141_at(((int64_t)((x_1555).a_))); (S1*)_t4692->b + hr_ix(_i4692, _t4692->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:124"); }))).k_) == (((uint8_t)10LL)))));
 }
if (((k_1556) == (((int64_t)12LL)))) { int64_t bt_1558 = f141_at(((int64_t)((x_1555).a_))); 
return ((((((*({ hrv *_t4695 = &(g551); int64_t _i4695 = f179_deref(bt_1558); (S1*)_t4695->b + hr_ix(_i4695, _t4695->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:125"); }))).k_) == (((uint8_t)9LL))) || f272_is_place(((int64_t)((x_1555).a_)))) || ((((*({ hrv *_t4698 = &(g551); int64_t _i4698 = bt_1558; (S1*)_t4698->b + hr_ix(_i4698, _t4698->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:125"); }))).k_) == (((uint8_t)10LL))));
 }
if ((((k_1556) == (((int64_t)10LL))) && ((((int64_t)((x_1555).op_))) == (((int64_t)49LL))))) { return f272_is_place(((int64_t)((x_1555).a_)));
 }
if (((((k_1556) == (((int64_t)11LL))) && ((f156_rk(n_1554)) == (((int64_t)4LL)))) && ((f157_rv(n_1554)) == (((int64_t)20LL))))) { return true;
 }
return false;
}
static int64_t f273_tmp(int64_t t_1559, bool clean_1560) {
(void)(f262_cbody(t_1559));
g178++;
(void)(({ hrv *_v4703 = &(g176); hsl _s4703 = f264_cn(t_1559); hr_append(_v4703, _s4703.p, _s4703.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4705 = &(g176); hr_fs(_o4705, hr_str(" _t", 3)); hr_fi(_o4705, g178); }));
if (clean_1560) { (void)(({ hrv *_v4706 = &(g176); hsl _s4706 = hr_str(" __attribute__((cleanup(hr_rdrop)))", 35); hr_append(_v4706, _s4706.p, _s4706.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4707 = &(g176); hsl _s4707 = hr_str(" = {0}; ", 8); hr_append(_v4707, _s4707.p, _s4707.n, sizeof(uint8_t)); }));
return g178;
}
static void f274_ot(int64_t k_1562) {
(void)(({ hrv *_o4708 = &(g163); hr_fs(_o4708, hr_str("_t", 2)); hr_fi(_o4708, k_1562); }));
}
static void f275_gx0(int64_t n_1563) {
S4 x_1564 = (*({ hrv *_t4709 = &(g704); int64_t _i4709 = n_1563; (S4*)_t4709->b + hr_ix(_i4709, _t4709->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:732"); })); 
int64_t k_1565 = ((int64_t)((x_1564).k_)); 
if (((k_1565) == (((int64_t)1LL)))) { (void)(f277_oint(((*({ hrv *_t4711 = &(g914); int64_t _i4711 = (x_1564).t_; (S3*)_t4711->b + hr_ix(_i4711, _t4711->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:734"); }))).v_, ((*({ hrv *_t4712 = &(g914); int64_t _i4712 = (x_1564).t_; (S3*)_t4712->b + hr_ix(_i4712, _t4712->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:734"); }))).uns_, f276_fin_lit(n_1563)));
return;
 }
if (((k_1565) == (((int64_t)2LL)))) { int64_t t_1572 = f276_fin_lit(n_1563); 
(void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(({ int64_t _r4717; if (((((*({ hrv *_t4718 = &(g551); int64_t _i4718 = t_1572; (S1*)_t4718->b + hr_ix(_i4718, _t4718->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:735"); }))).k_) == (((uint8_t)4LL)))) { _r4717 = t_1572;  } else { _r4717 = g569;  } _r4717; })));
(void)(f260_ow(hr_str(")", 1)));
(void)(f260_ow(f36_tok_text(((int64_t)((x_1564).t_)))));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((k_1565) == (((int64_t)3LL)))) { (void)(f278_gstr(n_1563));
return;
 }
if (((k_1565) == (((int64_t)4LL)))) { (void)(f260_ow(hr_str("true", 4)));
return;
 }
if (((k_1565) == (((int64_t)5LL)))) { (void)(f260_ow(hr_str("false", 5)));
return;
 }
if (((k_1565) == (((int64_t)6LL)))) { (void)(f260_ow(hr_str("((void*)0)", 10)));
return;
 }
if (((k_1565) == (((int64_t)8LL)))) { int64_t r_1586 = f156_rk(n_1563); 
if (((r_1586) == (((int64_t)1LL)))) { (void)(f284_lv_expr(f157_rv(n_1563)));
return;
 }
if (((r_1586) == (((int64_t)2LL)))) { (void)(({ hrv *_o4730 = &(g163); hr_fs(_o4730, hr_str("g", 1)); hr_fi(_o4730, f157_rv(n_1563)); }));
return;
 }
if (((r_1586) == (((int64_t)6LL)))) { (void)(f277_oint((*({ hrv *_t4733 = &(g436); int64_t _i4733 = f157_rv(n_1563); (int64_t*)_t4733->b + hr_ix(_i4733, _t4733->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:744"); })), false, f276_fin_lit(n_1563)));
return;
 }
(void)(f287_gerr(n_1563, hr_str("unsupported name use", 20)));
return;
 }
if (((k_1565) == (((int64_t)9LL)))) { (void)(f288_gbin(n_1563));
return;
 }
if (((k_1565) == (((int64_t)10LL)))) { (void)(f313_gun(n_1563));
return;
 }
if (((k_1565) == (((int64_t)14LL)))) { int64_t r_1779 = f156_rk(n_1563); 
int64_t a_1780 = ((int64_t)((x_1564).a_)); 
if ((((r_1779) == (((int64_t)7LL))) && ((((*({ hrv *_t4740 = &(g551); int64_t _i4740 = f141_at(n_1563); (S1*)_t4740->b + hr_ix(_i4740, _t4740->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); }))).k_) == (((uint8_t)7LL))))) { int64_t t_1781 = f141_at(n_1563); 
S9 v_1782 = (*({ hrv *_t4743 = &(g557); int64_t _i4743 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4744 = &(g556); int64_t _i4744 = ((*({ hrv *_t4745 = &(g551); int64_t _i4745 = t_1781; (S1*)_t4745->b + hr_ix(_i4745, _t4745->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); }))).a_; (S8*)_t4744->b + hr_ix(_i4744, _t4744->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t4746 = &(g551); int64_t _i4746 = t_1781; (S1*)_t4746->b + hr_ix(_i4746, _t4746->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); }))).c_)))); (S9*)_t4743->b + hr_ix(_i4743, _t4743->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); })); 
if ((((v_1782).si_) >= (((int32_t)0LL)))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1781));
(void)(f260_ow(hr_str("){0})", 5)));
 } else { (void)(f260_ow(hr_str("((hr_unit)0)", 12)));
 }
return;
 }
if (((r_1779) == (((int64_t)7LL)))) { int64_t t_1783 = f141_at(n_1563); 
int64_t p_1784 = f293_nt(); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(t_1783));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_1784));
(void)(({ hrv *_o4757 = &(g163); hr_fs(_o4757, hr_str("; memset(&_t", 12)); hr_fi(_o4757, p_1784); hr_fs(_o4757, hr_str(", 0, sizeof _t", 14)); hr_fi(_o4757, p_1784); hr_fs(_o4757, hr_str("); _t", 5)); hr_fi(_o4757, p_1784); hr_fs(_o4757, hr_str(".tag = ", 7)); hr_fi(_o4757, f157_rv(n_1563)); hr_fs(_o4757, hr_str("; _t", 4)); hr_fi(_o4757, p_1784); hr_fs(_o4757, hr_str("; })", 4)); }));
return;
 }
if (((r_1779) == (((int64_t)8LL)))) { int64_t d_1785 = f179_deref(f141_at(a_1780)); 
if (((f157_rv(n_1563)) == (((int64_t)2LL)))) { (void)(({ hrv *_o4762 = &(g163); hr_fs(_o4762, hr_str("((int64_t)", 10)); hr_fi(_o4762, ((*({ hrv *_t4763 = &(g551); int64_t _i4763 = d_1785; (S1*)_t4763->b + hr_ix(_i4763, _t4763->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:756"); }))).b_); hr_fs(_o4762, hr_str(")", 1)); }));
return;
 }
if (f282_is_fix(d_1785)) { (void)(({ hrv *_o4765 = &(g163); hr_fs(_o4765, hr_str("((int64_t)", 10)); hr_fi(_o4765, ((*({ hrv *_t4766 = &(g551); int64_t _i4766 = d_1785; (S1*)_t4766->b + hr_ix(_i4766, _t4766->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:757"); }))).b_); hr_fs(_o4765, hr_str(")", 1)); }));
return;
 }
if (f283_is_lim(d_1785)) { (void)(f260_ow(hr_str("((int64_t)(", 11)));
if (((((*({ hrv *_t4769 = &(g551); int64_t _i4769 = f141_at(a_1780); (S1*)_t4769->b + hr_ix(_i4769, _t4769->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:758"); }))).k_) == (((uint8_t)10LL)))) { (void)(f275_gx0(a_1780));
(void)(f260_ow(hr_str(")->n)", 5)));
 } else { (void)(f289_gx(a_1780));
(void)(f260_ow(hr_str(").n)", 4)));
 }
return;
 }
if (((((*({ hrv *_t4775 = &(g551); int64_t _i4775 = f141_at(a_1780); (S1*)_t4775->b + hr_ix(_i4775, _t4775->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:759"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f275_gx0(a_1780));
(void)(f260_ow(hr_str(")->n)", 5)));
return;
 }
(void)(f260_ow(hr_str("(", 1)));
(void)(f289_gx(a_1780));
(void)(f260_ow(hr_str(").n", 3)));
return;
 }
if (((r_1779) == (((int64_t)5LL)))) { int64_t bt_1786 = f141_at(a_1780); 
int64_t st_1787 = f179_deref(bt_1786); 
int64_t si_1788 = ({ int64_t _r4785; if (((((*({ hrv *_t4786 = &(g551); int64_t _i4786 = st_1787; (S1*)_t4786->b + hr_ix(_i4786, _t4786->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:765"); }))).k_) == (((uint8_t)5LL)))) { _r4785 = ((int64_t)(((*({ hrv *_t4787 = &(g551); int64_t _i4787 = st_1787; (S1*)_t4787->b + hr_ix(_i4787, _t4787->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:765"); }))).a_));  } else { _r4785 = f217_ax(n_1563);  } _r4785; }); 
S11 f_1789 = (*({ hrv *_t4789 = &(g555); int64_t _i4789 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4790 = &(g554); int64_t _i4790 = si_1788; (S10*)_t4790->b + hr_ix(_i4790, _t4790->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:766"); }))).f0_)) + (int64_t)f157_rv(n_1563))); (S11*)_t4789->b + hr_ix(_i4789, _t4789->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:766"); })); 
(void)(f260_ow(hr_str("(", 1)));
if (((((*({ hrv *_t4793 = &(g551); int64_t _i4793 = bt_1786; (S1*)_t4793->b + hr_ix(_i4793, _t4793->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:768"); }))).k_) == (((uint8_t)10LL)))) { (void)(f275_gx0(a_1780));
(void)(f260_ow(hr_str(")->", 3)));
 } else { (void)(f289_gx(a_1780));
(void)(f260_ow(hr_str(").", 2)));
 }
(void)(f267_fname_into((&(g163)), ((int64_t)((f_1789).name_))));
return;
 }
(void)(f287_gerr(n_1563, hr_str("unsupported member", 18)));
return;
 }
if (((k_1565) == (((int64_t)12LL)))) { (void)(f315_gidx(n_1563));
return;
 }
if (((k_1565) == (((int64_t)13LL)))) { (void)(f316_gslice(n_1563));
return;
 }
if (((k_1565) == (((int64_t)15LL)))) { int64_t t_1804 = f141_at(n_1563); 
int64_t ft_1805 = ((int64_t)(((*({ hrv *_t4803 = &(g551); int64_t _i4803 = f279_fin(((int64_t)((x_1564).a_))); (S1*)_t4803->b + hr_ix(_i4803, _t4803->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:776"); }))).k_)); 
if ((((((*({ hrv *_t4805 = &(g551); int64_t _i4805 = t_1804; (S1*)_t4805->b + hr_ix(_i4805, _t4805->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:776"); }))).k_) == (((uint8_t)3LL))) && (((ft_1805) == (((int64_t)4LL))) || ((ft_1805) == (((int64_t)13LL)))))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1804));
(void)(f260_ow(hr_str(")hr_f2i(", 8)));
(void)(f289_gx(((int64_t)((x_1564).a_))));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
(void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1804));
(void)(f260_ow(hr_str(")(", 2)));
(void)(f289_gx(((int64_t)((x_1564).a_))));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (((k_1565) == (((int64_t)16LL)))) { (void)(f317_garr(n_1563));
return;
 }
if (((k_1565) == (((int64_t)17LL)))) { (void)(f318_gslit(n_1563));
return;
 }
if (((k_1565) == (((int64_t)11LL)))) { (void)(f319_gcall(n_1563));
return;
 }
if (((k_1565) == (((int64_t)23LL)))) { (void)(f260_ow(hr_str("({ ", 3)));
(void)(f342_gblk(n_1563, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((f141_at(n_1563)) != (g558))));
(void)(f260_ow(hr_str(" })", 3)));
return;
 }
if ((((((k_1565) == (((int64_t)19LL))) || ((k_1565) == (((int64_t)20LL)))) || ((k_1565) == (((int64_t)24LL)))) || ((k_1565) == (((int64_t)26LL))))) { int64_t t_2077 = f141_at(n_1563); 
if ((((t_2077) == (g558)) || ((t_2077) < (((int64_t)0LL))))) { (void)(f260_ow(hr_str("({ ", 3)));
(void)(f335_gstmt(n_1563));
(void)(f260_ow(hr_str(" })", 3)));
return;
 }
int64_t r_2078 = f293_nt(); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(t_2077));
(void)(f260_ow(hr_str(" _r", 3)));
(void)(f294_oi(r_2078));
(void)(f260_ow(hr_str("; ", 2)));
if (((k_1565) == (((int64_t)19LL)))) { (void)(f341_gif(n_1563, r_2078));
 } else { if (((k_1565) == (((int64_t)20LL)))) { (void)(f349_gmatch(n_1563, r_2078));
 } else { if (((k_1565) == (((int64_t)24LL)))) { (void)(f350_geblock(n_1563, r_2078));
 } else { (void)(f347_gloop(n_1563, r_2078));
 }
 }
 }
(void)(f260_ow(hr_str(" _r", 3)));
(void)(f294_oi(r_2078));
(void)(f260_ow(hr_str("; })", 4)));
return;
 }
if (((((((k_1565) == (((int64_t)28LL))) || ((k_1565) == (((int64_t)29LL)))) || ((k_1565) == (((int64_t)30LL)))) || ((k_1565) == (((int64_t)25LL)))) || ((k_1565) == (((int64_t)27LL))))) { (void)(f260_ow(hr_str("({ ", 3)));
(void)(f335_gstmt(n_1563));
(void)(f260_ow(hr_str(" })", 3)));
return;
 }
(void)(f287_gerr(n_1563, hr_str("unsupported expression in codegen", 33)));
}
static int64_t f276_fin_lit(int64_t n_1566) {
int64_t t_1567 = f141_at(n_1566); 
return ({ int64_t _r4845; if ((((t_1567) < (((int64_t)0LL))) || ((((*({ hrv *_t4846 = &(g551); int64_t _i4846 = t_1567; (S1*)_t4846->b + hr_ix(_i4846, _t4846->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:795"); }))).k_) == (((uint8_t)12LL))))) { _r4845 = g563;  } else { _r4845 = ({ int64_t _r4847; if (((((*({ hrv *_t4848 = &(g551); int64_t _i4848 = t_1567; (S1*)_t4848->b + hr_ix(_i4848, _t4848->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:795"); }))).k_) == (((uint8_t)13LL)))) { _r4847 = g569;  } else { _r4847 = t_1567;  } _r4847; });  } _r4845; });
}
static void f277_oint(int64_t v_1568, bool uns_1569, int64_t t_1570) {
int64_t k_1571 = ((int64_t)(((*({ hrv *_t4849 = &(g551); int64_t _i4849 = t_1570; (S1*)_t4849->b + hr_ix(_i4849, _t4849->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:140"); }))).k_)); 
if (((k_1571) == (((int64_t)4LL)))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1570));
(void)(f260_ow(hr_str(")", 1)));
if (uns_1569) { (void)(({ hrv *_o4853 = &(g163); hr_fu(_o4853, ((uint64_t)(v_1568))); hr_fs(_o4853, hr_str(".0", 2)); }));
 } else { (void)(({ hrv *_o4854 = &(g163); hr_fi(_o4854, v_1568); hr_fs(_o4854, hr_str(".0", 2)); }));
 }
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((k_1571) == (((int64_t)2LL)))) { (void)(f260_ow(({ hsl _r4857; if (((v_1568) != (((int64_t)0LL)))) { _r4857 = hr_str("true", 4);  } else { _r4857 = hr_str("false", 5);  } _r4857; })));
return;
 }
(void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(({ int64_t _r4860; if (((k_1571) == (((int64_t)3LL)))) { _r4860 = t_1570;  } else { _r4860 = g563;  } _r4860; })));
(void)(f260_ow(hr_str(")", 1)));
if (uns_1569) { (void)(({ hrv *_o4862 = &(g163); hr_fu(_o4862, ((uint64_t)(v_1568))); hr_fs(_o4862, hr_str("ULL)", 4)); }));
return;
 }
if (((v_1568) == (((int64_t)((int64_t)((int64_t)(0 - (uint64_t)(((int64_t)9223372036854775807LL)))) - (int64_t)((int64_t)1LL)))))) { (void)(f260_ow(hr_str("(-9223372036854775807LL-1))", 27)));
return;
 }
(void)(({ hrv *_o4864 = &(g163); hr_fi(_o4864, v_1568); hr_fs(_o4864, hr_str("LL)", 3)); }));
}
static void f278_gstr(int64_t n_1573) {
int64_t t_1577 = f279_fin(n_1573); 
hsl s_1580 = f280_tok_str(((int64_t)(((*({ hrv *_t4867 = &(g704); int64_t _i4867 = n_1573; (S4*)_t4867->b + hr_ix(_i4867, _t4867->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:345"); }))).t_))); 
int64_t a_1581 = f141_at(n_1573); 
if (f268_is_res(a_1581)) { (void)(f260_ow(hr_str("hr_rfrom(hr_str(", 16)));
(void)(f281_cstr_lit(s_1580));
(void)(({ hrv *_o4872 = &(g163); hr_fs(_o4872, hr_str(", ", 2)); hr_fi(_o4872, (s_1580).n); hr_fs(_o4872, hr_str("), 1)", 5)); }));
return;
 }
if (f282_is_fix(a_1581)) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(a_1581));
(void)(f260_ow(hr_str("){ ", 3)));
(void)(f281_cstr_lit(s_1580));
(void)(f260_ow(hr_str(" })", 3)));
return;
 }
if (f283_is_lim(a_1581)) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(a_1581));
(void)(({ hrv *_o4882 = &(g163); hr_fs(_o4882, hr_str("){ ", 3)); hr_fi(_o4882, (s_1580).n); hr_fs(_o4882, hr_str(", ", 2)); }));
(void)(f281_cstr_lit(s_1580));
(void)(f260_ow(hr_str(" })", 3)));
return;
 }
(void)(f260_ow(hr_str("hr_str(", 7)));
(void)(f281_cstr_lit(s_1580));
(void)(({ hrv *_o4887 = &(g163); hr_fs(_o4887, hr_str(", ", 2)); hr_fi(_o4887, (s_1580).n); hr_fs(_o4887, hr_str(")", 1)); }));
}
static int64_t f279_fin(int64_t n_1574) {
int64_t c_1575 = f150_cv(n_1574); 
return ({ int64_t _r4889; if (((c_1575) >= (((int64_t)0LL)))) { _r4889 = c_1575;  } else { int64_t t_1576 = f141_at(n_1574); 
_r4889 = ({ int64_t _r4891; if (((t_1576) < (((int64_t)0LL)))) { _r4891 = g558;  } else { _r4891 = t_1576;  } _r4891; });  } _r4889; });
}
static hsl f280_tok_str(int64_t t_1578) {
S3 x_1579 = (*({ hrv *_t4892 = &(g914); int64_t _i4892 = t_1578; (S3*)_t4892->b + hr_ix(_i4892, _t4892->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:182"); })); 
return ({ hsl _t4893 = hr_sl(g910); int64_t _l4893 = ((int64_t)((x_1579).v_)), _h4893 = ((int64_t)((int64_t)((int64_t)((x_1579).v_)) + (int64_t)((int64_t)((x_1579).w_)))); if (_l4893 < 0 || _h4893 < _l4893 || _h4893 > _t4893.n) hr_slerr(_l4893, _h4893, _t4893.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:182"); (hsl){ _t4893.p + _l4893 * (int64_t)sizeof(uint8_t), _h4893 - _l4893 }; });
}
static void f281_cstr_lit(hsl s_1582) {
(void)(({ hrv *_v4894 = &(g163); uint8_t _x4894 = ((uint8_t)34LL); uint8_t *_p4894 = (uint8_t*)hr_grow(_v4894, 1, sizeof _x4894); *_p4894 = _x4894; _p4894; }));
{ hsl _v4896 = s_1582; for (int64_t _k4896 = 0; _k4896 < _v4896.n; _k4896++) { uint8_t c_1583 = ((uint8_t*)_v4896.p)[_k4896]; if ((((c_1583) == (((uint8_t)34LL))) || ((c_1583) == (((uint8_t)92LL))))) { (void)(({ hrv *_v4897 = &(g163); uint8_t _x4897 = ((uint8_t)92LL); uint8_t *_p4897 = (uint8_t*)hr_grow(_v4897, 1, sizeof _x4897); *_p4897 = _x4897; _p4897; }));
(void)(({ hrv *_v4898 = &(g163); uint8_t _x4898 = c_1583; uint8_t *_p4898 = (uint8_t*)hr_grow(_v4898, 1, sizeof _x4898); *_p4898 = _x4898; _p4898; }));
 } else { if (((((c_1583) >= (((uint8_t)32LL))) && ((c_1583) < (((uint8_t)127LL)))) && ((c_1583) != (((uint8_t)63LL))))) { (void)(({ hrv *_v4899 = &(g163); uint8_t _x4899 = c_1583; uint8_t *_p4899 = (uint8_t*)hr_grow(_v4899, 1, sizeof _x4899); *_p4899 = _x4899; _p4899; }));
 } else { (void)(({ hrv *_v4900 = &(g163); uint8_t _x4900 = ((uint8_t)92LL); uint8_t *_p4900 = (uint8_t*)hr_grow(_v4900, 1, sizeof _x4900); *_p4900 = _x4900; _p4900; }));
(void)(({ hrv *_v4901 = &(g163); uint8_t _x4901 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)((uint8_t)((c_1583) >> ((((uint8_t)6LL)) & 7))) & (uint64_t)((uint8_t)7LL))))); uint8_t *_p4901 = (uint8_t*)hr_grow(_v4901, 1, sizeof _x4901); *_p4901 = _x4901; _p4901; }));
(void)(({ hrv *_v4902 = &(g163); uint8_t _x4902 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)((uint8_t)((c_1583) >> ((((uint8_t)3LL)) & 7))) & (uint64_t)((uint8_t)7LL))))); uint8_t *_p4902 = (uint8_t*)hr_grow(_v4902, 1, sizeof _x4902); *_p4902 = _x4902; _p4902; }));
(void)(({ hrv *_v4903 = &(g163); uint8_t _x4903 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)c_1583 & (uint64_t)((uint8_t)7LL))))); uint8_t *_p4903 = (uint8_t*)hr_grow(_v4903, 1, sizeof _x4903); *_p4903 = _x4903; _p4903; }));
 }
 }
 } } _bk4895:; 
(void)(({ hrv *_v4904 = &(g163); uint8_t _x4904 = ((uint8_t)34LL); uint8_t *_p4904 = (uint8_t*)hr_grow(_v4904, 1, sizeof _x4904); *_p4904 = _x4904; _p4904; }));
}
static bool f282_is_fix(int64_t t_1584) {
return (((((*({ hrv *_t4905 = &(g551); int64_t _i4905 = t_1584; (S1*)_t4905->b + hr_ix(_i4905, _t4905->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:20"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t4906 = &(g551); int64_t _i4906 = t_1584; (S1*)_t4906->b + hr_ix(_i4906, _t4906->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:20"); }))).s_))) == (((int64_t)1LL))));
}
static bool f283_is_lim(int64_t t_1585) {
return (((((*({ hrv *_t4907 = &(g551); int64_t _i4907 = t_1585; (S1*)_t4907->b + hr_ix(_i4907, _t4907->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:19"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t4908 = &(g551); int64_t _i4908 = t_1585; (S1*)_t4908->b + hr_ix(_i4908, _t4908->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:19"); }))).s_))) == (((int64_t)3LL))));
}
static void f284_lv_expr(int64_t v_1587) {
bool p_1589 = f285_lv_isptr(v_1587); 
if (((((int64_t)(((*({ hrv *_t4910 = &(g389); int64_t _i4910 = v_1587; (S12*)_t4910->b + hr_ix(_i4910, _t4910->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:115"); }))).cfn_))) != (g179))) { (void)(f260_ow(({ hsl _r4912; if (p_1589) { _r4912 = hr_str("(**c", 4);  } else { _r4912 = hr_str("(*c", 3);  } _r4912; })));
(void)(({ hrv *_o4913 = &(g163); hr_fi(_o4913, v_1587); hr_fs(_o4913, hr_str(")", 1)); }));
return;
 }
if (p_1589) { (void)(f260_ow(hr_str("(*", 2)));
(void)(f286_lv_name(v_1587));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
(void)(f286_lv_name(v_1587));
}
static bool f285_lv_isptr(int64_t v_1588) {
return (((((uint16_t)((uint64_t)((*({ hrv *_t4918 = &(g389); int64_t _i4918 = v_1588; (S12*)_t4918->b + hr_ix(_i4918, _t4918->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:112"); }))).fl_ & (uint64_t)((uint16_t)8LL)))) != (((uint16_t)0LL))) && ((((*({ hrv *_t4919 = &(g551); int64_t _i4919 = ((*({ hrv *_t4920 = &(g389); int64_t _i4920 = v_1588; (S12*)_t4920->b + hr_ix(_i4920, _t4920->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:112"); }))).ty_; (S1*)_t4919->b + hr_ix(_i4919, _t4919->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:112"); }))).k_) != (((uint8_t)10LL))));
}
static void f286_lv_name(int64_t v_1590) {
{ hsl _v4922 = f10_nm(((int64_t)(((*({ hrv *_t4924 = &(g389); int64_t _i4924 = v_1590; (S12*)_t4924->b + hr_ix(_i4924, _t4924->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:111"); }))).name_))); for (int64_t _k4922 = 0; _k4922 < _v4922.n; _k4922++) { uint8_t c_1591 = ((uint8_t*)_v4922.p)[_k4922]; (void)(({ hrv *_v4925 = &(g163); uint8_t _x4925 = ({ uint8_t _r4926; if ((((c_1591) == (((uint8_t)36LL))) || ((c_1591) == (((uint8_t)58LL))))) { _r4926 = ((uint8_t)95LL);  } else { _r4926 = c_1591;  } _r4926; }); uint8_t *_p4925 = (uint8_t*)hr_grow(_v4925, 1, sizeof _x4925); *_p4925 = _x4925; _p4925; }));
 } } _bk4921:; 
(void)(({ hrv *_o4927 = &(g163); hr_fs(_o4927, hr_str("_", 1)); hr_fi(_o4927, v_1590); }));
}
static void f287_gerr(int64_t n_1592, hsl m_1593) {
if ((((g182).n) > (((int64_t)0LL)))) { return;
 }
S3 x_1594 = (*({ hrv *_t4928 = &(g914); int64_t _i4928 = ((*({ hrv *_t4929 = &(g704); int64_t _i4929 = f103_max(n_1592, ((int64_t)0LL)); (S4*)_t4929->b + hr_ix(_i4929, _t4929->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:15"); }))).t_; (S3*)_t4928->b + hr_ix(_i4928, _t4928->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:15"); })); 
(void)(({ hrv *_v4931 = &(g182); hsl _s4931 = f10_nm(((int64_t)(((*({ hrv *_t4933 = &(g913); int64_t _i4933 = (x_1594).f_; (S2*)_t4933->b + hr_ix(_i4933, _t4933->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:15"); }))).name_))); hr_append(_v4931, _s4931.p, _s4931.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4934 = &(g182); hr_fs(_o4934, hr_str(":", 1)); hr_fi(_o4934, (x_1594).line_); hr_fs(_o4934, hr_str(": error: ", 9)); hr_fs(_o4934, m_1593); }));
}
static void f288_gbin(int64_t n_1595) {
S4 x_1596 = (*({ hrv *_t4935 = &(g704); int64_t _i4935 = n_1595; (S4*)_t4935->b + hr_ix(_i4935, _t4935->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:263"); })); 
int64_t o_1597 = ((int64_t)((x_1596).op_)); 
int64_t a_1598 = ((int64_t)((x_1596).a_)); 
int64_t b_1599 = ((int64_t)((x_1596).b_)); 
if ((((o_1597) == (((int64_t)52LL))) || ((o_1597) == (((int64_t)53LL))))) { (void)(f260_ow(hr_str("(", 1)));
(void)(f289_gx(a_1598));
(void)(f260_ow(({ hsl _r4939; if (((o_1597) == (((int64_t)52LL)))) { _r4939 = hr_str(" && ", 4);  } else { _r4939 = hr_str(" || ", 4);  } _r4939; })));
(void)(f289_gx(b_1599));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
bool cmp_1603 = (((((((o_1597) == (((int64_t)37LL))) || ((o_1597) == (((int64_t)38LL)))) || ((o_1597) == (((int64_t)39LL)))) || ((o_1597) == (((int64_t)40LL)))) || ((o_1597) == (((int64_t)41LL)))) || ((o_1597) == (((int64_t)42LL)))); 
if (cmp_1603) { int64_t m_1604 = f217_ax(n_1595); 
int64_t ta_1605 = f279_fin(a_1598); 
int64_t tb_1606 = f279_fin(b_1599); 
if (((m_1604) == (((int64_t)1LL)))) { (void)(f260_ow(hr_str("((uint64_t)(", 12)));
(void)(f289_gx(a_1598));
(void)(f260_ow(hr_str(") ", 2)));
(void)(f260_ow(f290_cmp_op(o_1597)));
(void)(f260_ow(hr_str(" (uint64_t)(", 12)));
(void)(f289_gx(b_1599));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (((m_1604) == (((int64_t)2LL)))) { if (((o_1597) == (((int64_t)38LL)))) { (void)(f260_ow(hr_str("!", 1)));
 }
(void)(f260_ow(hr_str("hr_streq(", 9)));
(void)(f291_gas(a_1598));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f291_gas(b_1599));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((m_1604) == (((int64_t)3LL)))) { int64_t et_1621 = ({ int64_t _r4959; if ((((((*({ hrv *_t4960 = &(g551); int64_t _i4960 = ta_1605; (S1*)_t4960->b + hr_ix(_i4960, _t4960->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:271"); }))).k_) == (((uint8_t)7LL))) || ((((*({ hrv *_t4961 = &(g551); int64_t _i4961 = ta_1605; (S1*)_t4961->b + hr_ix(_i4961, _t4961->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:271"); }))).k_) == (((uint8_t)19LL))))) { _r4959 = tb_1606;  } else { _r4959 = ta_1605;  } _r4959; }); 
(void)(f295_gen_heq(et_1621));
if (((o_1597) == (((int64_t)38LL)))) { (void)(f260_ow(hr_str("!", 1)));
 }
(void)(f260_ow(hr_str("heq", 3)));
(void)(f294_oi(et_1621));
(void)(f260_ow(hr_str("(", 1)));
if (f305_hsl_ty(et_1621)) { (void)(f291_gas(a_1598));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f291_gas(b_1599));
 } else { (void)(f306_gxas(a_1598, et_1621));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f306_gxas(b_1599, et_1621));
 }
(void)(f260_ow(hr_str(")", 1)));
return;
 }
int64_t ka_1725 = ((int64_t)(((*({ hrv *_t4975 = &(g551); int64_t _i4975 = ta_1605; (S1*)_t4975->b + hr_ix(_i4975, _t4975->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:272"); }))).k_)); 
if (((((ka_1725) == (((int64_t)10LL))) || ((ka_1725) == (((int64_t)11LL)))) || ((((*({ hrv *_t4976 = &(g551); int64_t _i4976 = tb_1606; (S1*)_t4976->b + hr_ix(_i4976, _t4976->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:273"); }))).k_) == (((uint8_t)10LL))))) { (void)(f260_ow(hr_str("((void*)(", 9)));
(void)(f289_gx(a_1598));
(void)(f260_ow(hr_str(") ", 2)));
(void)(f260_ow(f290_cmp_op(o_1597)));
(void)(f260_ow(hr_str(" (void*)(", 9)));
(void)(f289_gx(b_1599));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
(void)(f260_ow(hr_str("((", 2)));
(void)(f289_gx(a_1598));
(void)(f260_ow(hr_str(") ", 2)));
(void)(f260_ow(f290_cmp_op(o_1597)));
(void)(f260_ow(hr_str(" (", 2)));
(void)(f289_gx(b_1599));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
(void)(f307_garith(o_1597, f279_fin(n_1595), a_1598, b_1599, ((int64_t)0LL), n_1595));
}
static void f289_gx(int64_t n_1600) {
int64_t c_1601 = f150_cv(n_1600); 
int64_t t_1602 = f141_at(n_1600); 
if ((((c_1601) < (((int64_t)0LL))) || ((c_1601) == (t_1602)))) { (void)(f271_gx1(n_1600));
return;
 }
(void)(f270_gcv(n_1600, t_1602, c_1601));
}
static hsl f290_cmp_op(int64_t o_1607) {
if (((o_1607) == (((int64_t)37LL)))) { return hr_str("==", 2);
 }
if (((o_1607) == (((int64_t)38LL)))) { return hr_str("!=", 2);
 }
if (((o_1607) == (((int64_t)39LL)))) { return hr_str("<", 1);
 }
if (((o_1607) == (((int64_t)40LL)))) { return hr_str(">", 1);
 }
if (((o_1607) == (((int64_t)41LL)))) { return hr_str("<=", 2);
 }
if (((o_1607) == (((int64_t)42LL)))) { return hr_str(">=", 2);
 }
return hr_str("\077", 1);
}
static void f291_gas(int64_t n_1608) {
int64_t c_1609 = f150_cv(n_1608); 
int64_t t_1610 = f141_at(n_1608); 
if (((((c_1609) >= (((int64_t)0LL))) && ((c_1609) != (t_1610))) && ((((*({ hrv *_t5001 = &(g551); int64_t _i5001 = c_1609; (S1*)_t5001->b + hr_ix(_i5001, _t5001->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:201"); }))).k_) == (((uint8_t)9LL))))) { (void)(f292_gsl(n_1608, t_1610));
return;
 }
if ((((c_1609) >= (((int64_t)0LL))) && ((c_1609) != (t_1610)))) { int64_t p_1620 = f293_nt(); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(c_1609));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_1620));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(n_1608));
(void)(f260_ow(hr_str("; ", 2)));
if (f268_is_res(c_1609)) { (void)(f260_ow(hr_str("hr_sl(_t", 8)));
(void)(f294_oi(p_1620));
(void)(f260_ow(hr_str(")", 1)));
 } else { if (f282_is_fix(c_1609)) { (void)(f260_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f294_oi(p_1620));
(void)(({ hrv *_o5018 = &(g163); hr_fs(_o5018, hr_str(".e, ", 4)); hr_fi(_o5018, ((*({ hrv *_t5019 = &(g551); int64_t _i5019 = c_1609; (S1*)_t5019->b + hr_ix(_i5019, _t5019->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:202"); }))).b_); hr_fs(_o5018, hr_str(" }", 2)); }));
 } else { if (((((*({ hrv *_t5020 = &(g551); int64_t _i5020 = c_1609; (S1*)_t5020->b + hr_ix(_i5020, _t5020->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:202"); }))).k_) == (((uint8_t)9LL)))) { (void)(f260_ow(hr_str("_t", 2)));
(void)(f294_oi(p_1620));
 } else { (void)(f260_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f294_oi(p_1620));
(void)(f260_ow(hr_str(".e, _t", 6)));
(void)(f294_oi(p_1620));
(void)(f260_ow(hr_str(".n }", 4)));
 }
 }
 }
(void)(f260_ow(hr_str("; })", 4)));
return;
 }
(void)(f292_gsl(n_1608, t_1610));
}
static void f292_gsl(int64_t n_1611, int64_t f_1612) {
int64_t d_1613 = f179_deref(f_1612); 
int64_t k_1614 = ((int64_t)(((*({ hrv *_t5031 = &(g551); int64_t _i5031 = d_1613; (S1*)_t5031->b + hr_ix(_i5031, _t5031->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:178"); }))).k_)); 
if ((((((*({ hrv *_t5032 = &(g551); int64_t _i5032 = f_1612; (S1*)_t5032->b + hr_ix(_i5032, _t5032->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:179"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t5033 = &(g551); int64_t _i5033 = f_1612; (S1*)_t5033->b + hr_ix(_i5033, _t5033->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:179"); }))).c_) < (((int32_t)0LL))))) { int64_t p_1615 = f293_nt(); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(f_1612));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_1615));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f275_gx0(n_1611));
(void)(f260_ow(hr_str("; ", 2)));
if (((k_1614) == (((int64_t)9LL)))) { (void)(f260_ow(hr_str("*_t", 3)));
(void)(f294_oi(p_1615));
 } else { if (f268_is_res(d_1613)) { (void)(f260_ow(hr_str("hr_sl(*_t", 9)));
(void)(f294_oi(p_1615));
(void)(f260_ow(hr_str(")", 1)));
 } else { if (f282_is_fix(d_1613)) { (void)(f260_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f294_oi(p_1615));
(void)(({ hrv *_o5051 = &(g163); hr_fs(_o5051, hr_str("->e, ", 5)); hr_fi(_o5051, ((*({ hrv *_t5052 = &(g551); int64_t _i5052 = d_1613; (S1*)_t5052->b + hr_ix(_i5052, _t5052->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:184"); }))).b_); hr_fs(_o5051, hr_str(" }", 2)); }));
 } else { (void)(f260_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f294_oi(p_1615));
(void)(f260_ow(hr_str("->e, _t", 7)));
(void)(f294_oi(p_1615));
(void)(f260_ow(hr_str("->n }", 5)));
 }
 }
 }
(void)(f260_ow(hr_str("; })", 4)));
return;
 }
if ((((k_1614) == (((int64_t)9LL))) || ((k_1614) == (((int64_t)18LL))))) { (void)(f275_gx0(n_1611));
return;
 }
if (f268_is_res(d_1613)) { (void)(f260_ow(hr_str("hr_sl(", 6)));
if (f272_is_place(n_1611)) { (void)(f275_gx0(n_1611));
 } else { int64_t tk0_1617 = f273_tmp(d_1613, true); 
(void)(f260_ow(hr_str("*hr_tmp(&", 9)));
(void)(f274_ot(tk0_1617));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f275_gx0(n_1611));
(void)(f260_ow(hr_str(")", 1)));
 }
(void)(f260_ow(hr_str(")", 1)));
return;
 }
int64_t p_1618 = f293_nt(); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(d_1613));
(void)(f260_ow(hr_str(" *_t", 4)));
(void)(f294_oi(p_1618));
(void)(f260_ow(hr_str(" = ", 3)));
if (f272_is_place(n_1611)) { (void)(f260_ow(hr_str("&(", 2)));
(void)(f275_gx0(n_1611));
(void)(f260_ow(hr_str(")", 1)));
 } else { int64_t tk0_1619 = f273_tmp(d_1613, false); 
(void)(f260_ow(hr_str("(", 1)));
(void)(f274_ot(tk0_1619));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f275_gx0(n_1611));
(void)(f260_ow(hr_str(", &", 3)));
(void)(f274_ot(tk0_1619));
(void)(f260_ow(hr_str(")", 1)));
 }
(void)(f260_ow(hr_str("; ", 2)));
if (f282_is_fix(d_1613)) { (void)(f260_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f294_oi(p_1618));
(void)(({ hrv *_o5093 = &(g163); hr_fs(_o5093, hr_str("->e, ", 5)); hr_fi(_o5093, ((*({ hrv *_t5094 = &(g551); int64_t _i5094 = d_1613; (S1*)_t5094->b + hr_ix(_i5094, _t5094->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:195"); }))).b_); hr_fs(_o5093, hr_str(" }", 2)); }));
 } else { (void)(f260_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f294_oi(p_1618));
(void)(f260_ow(hr_str("->e, _t", 7)));
(void)(f294_oi(p_1618));
(void)(f260_ow(hr_str("->n }", 5)));
 }
(void)(f260_ow(hr_str("; })", 4)));
}
static int64_t f293_nt(void) {
g178++;
return g178;
}
static void f294_oi(int64_t v_1616) {
(void)(({ hrv *_o5101 = &(g163); hr_fi(_o5101, v_1616); }));
}
static void f295_gen_heq(int64_t t_1622) {
(void)(f263_cn_grow());
if ((((*({ hrv *_t5103 = &(g175); int64_t _i5103 = t_1622; (uint8_t*)_t5103->b + hr_ix(_i5103, _t5103->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:485"); }))) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t5104 = &((*({ hrv *_t5105 = &(g175); int64_t _i5105 = t_1622; (uint8_t*)_t5105->b + hr_ix(_i5105, _t5105->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:486"); }))); *_t5104 = ((uint8_t)1LL); }
S1 x_1623 = (*({ hrv *_t5106 = &(g551); int64_t _i5106 = t_1622; (S1*)_t5106->b + hr_ix(_i5106, _t5106->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:487"); })); 
int64_t k_1624 = ((int64_t)((x_1623).k_)); 
(void)(f262_cbody(t_1622));
bool sl_1625 = (((k_1624) == (((int64_t)9LL))) || ((((k_1624) == (((int64_t)8LL))) && (!(f282_is_fix(t_1622)))) && (!(f283_is_lim(t_1622))))); 
(void)(f296_comp_pre(t_1622, false));
L97 sig_1699 = ({ L97 _t5111; memset(&_t5111, 0, sizeof _t5111); _t5111.n = 0; _t5111; }); 
(void)(({ L97 *_l5112 = &(sig_1699); hrv _o5112 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5112, hr_str("static bool heq", 15)); hr_fi(&_o5112, t_1622); hr_fs(&_o5112, hr_str("(", 1)); if (_l5112->n + _o5112.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:492"); memcpy(_l5112->e + _l5112->n, _o5112.b, (size_t)_o5112.n); _l5112->n += _o5112.n; }));
hsl c_1700 = ({ hsl _r5113; if (sl_1625) { _r5113 = hr_str("hsl", 3);  } else { _r5113 = f264_cn(t_1622);  } _r5113; }); 
(void)(({ L97 *_v5115 = &(sig_1699); hsl _s5115 = c_1700; if (_v5115->n + _s5115.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:494"); memmove(_v5115->e + _v5115->n, _s5115.p, (size_t)_s5115.n * sizeof _v5115->e[0]); _v5115->n += _s5115.n; }));
(void)(({ L97 *_v5116 = &(sig_1699); hsl _s5116 = hr_str(" a, ", 4); if (_v5116->n + _s5116.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:494"); memmove(_v5116->e + _v5116->n, _s5116.p, (size_t)_s5116.n * sizeof _v5116->e[0]); _v5116->n += _s5116.n; }));
(void)(({ L97 *_v5117 = &(sig_1699); hsl _s5117 = c_1700; if (_v5117->n + _s5117.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:494"); memmove(_v5117->e + _v5117->n, _s5117.p, (size_t)_s5117.n * sizeof _v5117->e[0]); _v5117->n += _s5117.n; }));
(void)(({ L97 *_v5118 = &(sig_1699); hsl _s5118 = hr_str(" b)", 3); if (_v5118->n + _s5118.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:494"); memmove(_v5118->e + _v5118->n, _s5118.p, (size_t)_s5118.n * sizeof _v5118->e[0]); _v5118->n += _s5118.n; }));
(void)(({ hrv *_v5119 = &(g166); hsl _s5119 = ({ hsl _t5120 = ({ L97 *_t5121 = &(sig_1699); (hsl){ (uint8_t*)_t5121->e, _t5121->n }; }); int64_t _l5120 = 0, _h5120 = _t5120.n; if (_l5120 < 0 || _h5120 < _l5120 || _h5120 > _t5120.n) hr_slerr(_l5120, _h5120, _t5120.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:495"); (hsl){ _t5120.p + _l5120 * (int64_t)sizeof(uint8_t), _h5120 - _l5120 }; }); hr_append(_v5119, _s5119.p, _s5119.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5122 = &(g166); hsl _s5122 = hr_str(";\012", 2); hr_append(_v5122, _s5122.p, _s5122.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5123 = &(g169); hsl _s5123 = ({ hsl _t5124 = ({ L97 *_t5125 = &(sig_1699); (hsl){ (uint8_t*)_t5125->e, _t5125->n }; }); int64_t _l5124 = 0, _h5124 = _t5124.n; if (_l5124 < 0 || _h5124 < _l5124 || _h5124 > _t5124.n) hr_slerr(_l5124, _h5124, _t5124.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:496"); (hsl){ _t5124.p + _l5124 * (int64_t)sizeof(uint8_t), _h5124 - _l5124 }; }); hr_append(_v5123, _s5123.p, _s5123.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" { ", 3)));
if ((((k_1624) == (((int64_t)5LL))) || ((k_1624) == (((int64_t)7LL))))) { int64_t si_1701 = ({ int64_t _r5127; if (((k_1624) == (((int64_t)5LL)))) { _r5127 = ((int64_t)((x_1623).a_));  } else { _r5127 = ((int64_t)(((*({ hrv *_t5128 = &(g557); int64_t _i5128 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5129 = &(g556); int64_t _i5129 = (x_1623).a_; (S8*)_t5129->b + hr_ix(_i5129, _t5129->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:498"); }))).v0_)) + (int64_t)((int64_t)((x_1623).c_)))); (S9*)_t5128->b + hr_ix(_i5128, _t5128->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:498"); }))).si_));  } _r5127; }); 
(void)(f301_hh(hr_str("return true", 11)));
if (((si_1701) >= (((int64_t)0LL)))) { int64_t f0_1702 = ((int64_t)(((*({ hrv *_t5131 = &(g554); int64_t _i5131 = si_1701; (S10*)_t5131->b + hr_ix(_i5131, _t5131->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); }))).f0_)); 
{ int32_t _e5133 = ((*({ hrv *_t5134 = &(g554); int64_t _i5134 = si_1701; (S10*)_t5134->b + hr_ix(_i5134, _t5134->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); }))).fnum_; for (int32_t _k5133 = 0; _k5133 < _e5133; _k5133++) { int32_t i_1703 = (int32_t)_k5133; S11 f_1704 = (*({ hrv *_t5135 = &(g555); int64_t _i5135 = ((int64_t)((int64_t)f0_1702 + (int64_t)((int64_t)(i_1703)))); (S11*)_t5135->b + hr_ix(_i5135, _t5135->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); })); 
if ((((f_1704).ty_) < (((int32_t)0LL)))) { continue;
 }
L98 ea_1705 = ({ L98 _t5136; memset(&_t5136, 0, sizeof _t5136); _t5136.n = 0; _t5136; }); 
L98 eb_1706 = ({ L98 _t5137; memset(&_t5137, 0, sizeof _t5137); _t5137.n = 0; _t5137; }); 
(void)(({ L98 *_v5138 = &(ea_1705); hsl _s5138 = hr_str("a.", 2); if (_v5138->n + _s5138.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); memmove(_v5138->e + _v5138->n, _s5138.p, (size_t)_s5138.n * sizeof _v5138->e[0]); _v5138->n += _s5138.n; }));
(void)(({ L98 *_v5139 = &(eb_1706); hsl _s5139 = hr_str("b.", 2); if (_v5139->n + _s5139.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); memmove(_v5139->e + _v5139->n, _s5139.p, (size_t)_s5139.n * sizeof _v5139->e[0]); _v5139->n += _s5139.n; }));
{ hsl _v5141 = f10_nm(((int64_t)((f_1704).name_))); for (int64_t _k5141 = 0; _k5141 < _v5141.n; _k5141++) { uint8_t ch_1707 = ((uint8_t*)_v5141.p)[_k5141]; (void)(({ L98 *_v5143 = &(ea_1705); uint8_t _x5143 = ch_1707; if (_v5143->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); _v5143->e[_v5143->n] = _x5143; &_v5143->e[_v5143->n++]; }));
(void)(({ L98 *_v5144 = &(eb_1706); uint8_t _x5144 = ch_1707; if (_v5144->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); _v5144->e[_v5144->n] = _x5144; &_v5144->e[_v5144->n++]; }));
 } } _bk5140:; 
(void)(({ L98 *_v5145 = &(ea_1705); uint8_t _x5145 = ((uint8_t)95LL); if (_v5145->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); _v5145->e[_v5145->n] = _x5145; &_v5145->e[_v5145->n++]; }));
(void)(({ L98 *_v5146 = &(eb_1706); uint8_t _x5146 = ((uint8_t)95LL); if (_v5146->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); _v5146->e[_v5146->n] = _x5146; &_v5146->e[_v5146->n++]; }));
(void)(f301_hh(hr_str(" && ", 4)));
(void)(f304_heq_val(((int64_t)((f_1704).ty_)), ({ hsl _t5149 = ({ L98 *_t5150 = &(ea_1705); (hsl){ (uint8_t*)_t5150->e, _t5150->n }; }); int64_t _l5149 = 0, _h5149 = _t5149.n; if (_l5149 < 0 || _h5149 < _l5149 || _h5149 > _t5149.n) hr_slerr(_l5149, _h5149, _t5149.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); (hsl){ _t5149.p + _l5149 * (int64_t)sizeof(uint8_t), _h5149 - _l5149 }; }), ({ hsl _t5151 = ({ L98 *_t5152 = &(eb_1706); (hsl){ (uint8_t*)_t5152->e, _t5152->n }; }); int64_t _l5151 = 0, _h5151 = _t5151.n; if (_l5151 < 0 || _h5151 < _l5151 || _h5151 > _t5151.n) hr_slerr(_l5151, _h5151, _t5151.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); (hsl){ _t5151.p + _l5151 * (int64_t)sizeof(uint8_t), _h5151 - _l5151 }; })));
 } } _bk5132:; 
 }
(void)(f301_hh(hr_str("; ", 2)));
 }
if (((k_1624) == (((int64_t)6LL)))) { int64_t ei_1712 = ((int64_t)((x_1623).a_)); 
int64_t v0_1713 = ((int64_t)(((*({ hrv *_t5154 = &(g556); int64_t _i5154 = ei_1712; (S8*)_t5154->b + hr_ix(_i5154, _t5154->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:504"); }))).v0_)); 
(void)(f301_hh(hr_str("if (a.tag != b.tag) return false; ", 34)));
{ int32_t _e5157 = ((*({ hrv *_t5158 = &(g556); int64_t _i5158 = ei_1712; (S8*)_t5158->b + hr_ix(_i5158, _t5158->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); }))).vnum_; for (int32_t _k5157 = 0; _k5157 < _e5157; _k5157++) { int32_t i_1714 = (int32_t)_k5157; S9 v_1715 = (*({ hrv *_t5159 = &(g557); int64_t _i5159 = ((int64_t)((int64_t)v0_1713 + (int64_t)((int64_t)(i_1714)))); (S9*)_t5159->b + hr_ix(_i5159, _t5159->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); })); 
if (((((v_1715).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t5160 = &(g554); int64_t _i5160 = (v_1715).si_; (S10*)_t5160->b + hr_ix(_i5160, _t5160->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); }))).zero_)))) { L100 ea_1716 = ({ L100 _t5161; memset(&_t5161, 0, sizeof _t5161); _t5161.n = 0; _t5161; }); 
L100 eb_1717 = ({ L100 _t5162; memset(&_t5162, 0, sizeof _t5162); _t5162.n = 0; _t5162; }); 
(void)(({ L100 *_l5163 = &(ea_1716); hrv _o5163 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5163, hr_str("a.u.v", 5)); hr_fi(&_o5163, i_1714); if (_l5163->n + _o5163.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); memcpy(_l5163->e + _l5163->n, _o5163.b, (size_t)_o5163.n); _l5163->n += _o5163.n; }));
(void)(({ L100 *_l5164 = &(eb_1717); hrv _o5164 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5164, hr_str("b.u.v", 5)); hr_fi(&_o5164, i_1714); if (_l5164->n + _o5164.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); memcpy(_l5164->e + _l5164->n, _o5164.b, (size_t)_o5164.n); _l5164->n += _o5164.n; }));
(void)(({ hrv *_o5165 = &(g169); hr_fs(_o5165, hr_str("if (a.tag == ", 13)); hr_fi(_o5165, i_1714); hr_fs(_o5165, hr_str(") return ", 9)); }));
(void)(f304_heq_val(f125_t_variant(ei_1712, ((int64_t)(i_1714))), ({ hsl _t5168 = ({ L100 *_t5169 = &(ea_1716); (hsl){ (uint8_t*)_t5169->e, _t5169->n }; }); int64_t _l5168 = 0, _h5168 = _t5168.n; if (_l5168 < 0 || _h5168 < _l5168 || _h5168 > _t5168.n) hr_slerr(_l5168, _h5168, _t5168.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); (hsl){ _t5168.p + _l5168 * (int64_t)sizeof(uint8_t), _h5168 - _l5168 }; }), ({ hsl _t5170 = ({ L100 *_t5171 = &(eb_1717); (hsl){ (uint8_t*)_t5171->e, _t5171->n }; }); int64_t _l5170 = 0, _h5170 = _t5170.n; if (_l5170 < 0 || _h5170 < _l5170 || _h5170 > _t5170.n) hr_slerr(_l5170, _h5170, _t5170.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); (hsl){ _t5170.p + _l5170 * (int64_t)sizeof(uint8_t), _h5170 - _l5170 }; })));
(void)(f301_hh(hr_str("; ", 2)));
 }
 } } _bk5156:; 
(void)(f301_hh(hr_str("return true; ", 13)));
 }
if ((((k_1624) == (((int64_t)8LL))) || ((k_1624) == (((int64_t)9LL))))) { int64_t e_1718 = ((int64_t)((x_1623).a_)); 
L98 ea_1719 = ({ L98 _t5174; memset(&_t5174, 0, sizeof _t5174); _t5174.n = 0; _t5174; }); 
L98 eb_1720 = ({ L98 _t5175; memset(&_t5175, 0, sizeof _t5175); _t5175.n = 0; _t5175; }); 
if (f282_is_fix(t_1622)) { (void)(({ hrv *_o5177 = &(g169); hr_fs(_o5177, hr_str("for (int64_t i = 0; i < ", 24)); hr_fi(_o5177, (x_1623).b_); hr_fs(_o5177, hr_str("; i++) if (!(", 13)); }));
(void)(({ L98 *_v5178 = &(ea_1719); hsl _s5178 = hr_str("a.e[i]", 6); if (_v5178->n + _s5178.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:512"); memmove(_v5178->e + _v5178->n, _s5178.p, (size_t)_s5178.n * sizeof _v5178->e[0]); _v5178->n += _s5178.n; }));
(void)(({ L98 *_v5179 = &(eb_1720); hsl _s5179 = hr_str("b.e[i]", 6); if (_v5179->n + _s5179.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:512"); memmove(_v5179->e + _v5179->n, _s5179.p, (size_t)_s5179.n * sizeof _v5179->e[0]); _v5179->n += _s5179.n; }));
 } else { if (f283_is_lim(t_1622)) { (void)(f301_hh(hr_str("if (a.n != b.n) return false; for (int64_t i = 0; i < a.n; i++) if (!(", 70)));
(void)(({ L98 *_v5182 = &(ea_1719); hsl _s5182 = hr_str("a.e[i]", 6); if (_v5182->n + _s5182.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:513"); memmove(_v5182->e + _v5182->n, _s5182.p, (size_t)_s5182.n * sizeof _v5182->e[0]); _v5182->n += _s5182.n; }));
(void)(({ L98 *_v5183 = &(eb_1720); hsl _s5183 = hr_str("b.e[i]", 6); if (_v5183->n + _s5183.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:513"); memmove(_v5183->e + _v5183->n, _s5183.p, (size_t)_s5183.n * sizeof _v5183->e[0]); _v5183->n += _s5183.n; }));
 } else { (void)(f301_hh(hr_str("if (a.n != b.n) return false; for (int64_t i = 0; i < a.n; i++) if (!(", 70)));
(void)(({ L98 *_v5185 = &(ea_1719); hsl _s5185 = hr_str("((", 2); if (_v5185->n + _s5185.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:514"); memmove(_v5185->e + _v5185->n, _s5185.p, (size_t)_s5185.n * sizeof _v5185->e[0]); _v5185->n += _s5185.n; }));
(void)(({ L98 *_v5186 = &(ea_1719); hsl _s5186 = f264_cn(e_1718); if (_v5186->n + _s5186.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:514"); memmove(_v5186->e + _v5186->n, _s5186.p, (size_t)_s5186.n * sizeof _v5186->e[0]); _v5186->n += _s5186.n; }));
(void)(({ L98 *_v5188 = &(ea_1719); hsl _s5188 = hr_str("*)a.p)[i]", 9); if (_v5188->n + _s5188.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:514"); memmove(_v5188->e + _v5188->n, _s5188.p, (size_t)_s5188.n * sizeof _v5188->e[0]); _v5188->n += _s5188.n; }));
(void)(({ L98 *_v5189 = &(eb_1720); hsl _s5189 = hr_str("((", 2); if (_v5189->n + _s5189.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:514"); memmove(_v5189->e + _v5189->n, _s5189.p, (size_t)_s5189.n * sizeof _v5189->e[0]); _v5189->n += _s5189.n; }));
(void)(({ L98 *_v5190 = &(eb_1720); hsl _s5190 = f264_cn(e_1718); if (_v5190->n + _s5190.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:514"); memmove(_v5190->e + _v5190->n, _s5190.p, (size_t)_s5190.n * sizeof _v5190->e[0]); _v5190->n += _s5190.n; }));
(void)(({ L98 *_v5192 = &(eb_1720); hsl _s5192 = hr_str("*)b.p)[i]", 9); if (_v5192->n + _s5192.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:514"); memmove(_v5192->e + _v5192->n, _s5192.p, (size_t)_s5192.n * sizeof _v5192->e[0]); _v5192->n += _s5192.n; }));
 }
 }
(void)(f304_heq_val(e_1718, ({ hsl _t5194 = ({ L98 *_t5195 = &(ea_1719); (hsl){ (uint8_t*)_t5195->e, _t5195->n }; }); int64_t _l5194 = 0, _h5194 = _t5194.n; if (_l5194 < 0 || _h5194 < _l5194 || _h5194 > _t5194.n) hr_slerr(_l5194, _h5194, _t5194.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:515"); (hsl){ _t5194.p + _l5194 * (int64_t)sizeof(uint8_t), _h5194 - _l5194 }; }), ({ hsl _t5196 = ({ L98 *_t5197 = &(eb_1720); (hsl){ (uint8_t*)_t5197->e, _t5197->n }; }); int64_t _l5196 = 0, _h5196 = _t5196.n; if (_l5196 < 0 || _h5196 < _l5196 || _h5196 > _t5196.n) hr_slerr(_l5196, _h5196, _t5196.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:515"); (hsl){ _t5196.p + _l5196 * (int64_t)sizeof(uint8_t), _h5196 - _l5196 }; })));
(void)(f301_hh(hr_str(")) return false; return true; ", 30)));
 }
if (((k_1624) == (((int64_t)14LL)))) { (void)(f301_hh(hr_str("return true; ", 13)));
 }
(void)(f301_hh(hr_str("}\012", 2)));
}
static void f296_comp_pre(int64_t t_1626, bool fmt_1627) {
S1 x_1628 = (*({ hrv *_t5201 = &(g551); int64_t _i5201 = t_1626; (S1*)_t5201->b + hr_ix(_i5201, _t5201->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:400"); })); 
int64_t k_1629 = ((int64_t)((x_1628).k_)); 
if (((k_1629) == (((int64_t)5LL)))) { int64_t si_1630 = ((int64_t)((x_1628).a_)); 
{ int32_t _e5203 = ((*({ hrv *_t5204 = &(g554); int64_t _i5204 = si_1630; (S10*)_t5204->b + hr_ix(_i5204, _t5204->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:401"); }))).fnum_; for (int32_t _k5203 = 0; _k5203 < _e5203; _k5203++) { int32_t i_1631 = (int32_t)_k5203; S11 f_1632 = (*({ hrv *_t5205 = &(g555); int64_t _i5205 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5206 = &(g554); int64_t _i5206 = si_1630; (S10*)_t5206->b + hr_ix(_i5206, _t5206->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:401"); }))).f0_)) + (int64_t)((int64_t)(i_1631)))); (S11*)_t5205->b + hr_ix(_i5205, _t5205->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:401"); })); 
if ((((f_1632).ty_) >= (((int32_t)0LL)))) { (void)(f297_comp_one(((int64_t)((f_1632).ty_)), fmt_1627));
 }
 } } _bk5202:; 
 }
if (((k_1629) == (((int64_t)7LL)))) { S9 v_1690 = (*({ hrv *_t5208 = &(g557); int64_t _i5208 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5209 = &(g556); int64_t _i5209 = (x_1628).a_; (S8*)_t5209->b + hr_ix(_i5209, _t5209->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:402"); }))).v0_)) + (int64_t)((int64_t)((x_1628).c_)))); (S9*)_t5208->b + hr_ix(_i5208, _t5208->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:402"); })); 
if ((((v_1690).si_) >= (((int32_t)0LL)))) { { int32_t _e5211 = ((*({ hrv *_t5212 = &(g554); int64_t _i5212 = (v_1690).si_; (S10*)_t5212->b + hr_ix(_i5212, _t5212->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:402"); }))).fnum_; for (int32_t _k5211 = 0; _k5211 < _e5211; _k5211++) { int32_t i_1691 = (int32_t)_k5211; S11 f_1692 = (*({ hrv *_t5213 = &(g555); int64_t _i5213 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5214 = &(g554); int64_t _i5214 = (v_1690).si_; (S10*)_t5214->b + hr_ix(_i5214, _t5214->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:402"); }))).f0_)) + (int64_t)((int64_t)(i_1691)))); (S11*)_t5213->b + hr_ix(_i5213, _t5213->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:402"); })); 
if ((((f_1692).ty_) >= (((int32_t)0LL)))) { (void)(f297_comp_one(((int64_t)((f_1692).ty_)), fmt_1627));
 }
 } } _bk5210:; 
 }
 }
if (((k_1629) == (((int64_t)6LL)))) { int64_t ei_1693 = ((int64_t)((x_1628).a_)); 
{ int32_t _e5217 = ((*({ hrv *_t5218 = &(g556); int64_t _i5218 = ei_1693; (S8*)_t5218->b + hr_ix(_i5218, _t5218->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).vnum_; for (int32_t _k5217 = 0; _k5217 < _e5217; _k5217++) { int32_t i_1694 = (int32_t)_k5217; S9 v_1695 = (*({ hrv *_t5219 = &(g557); int64_t _i5219 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5220 = &(g556); int64_t _i5220 = ei_1693; (S8*)_t5220->b + hr_ix(_i5220, _t5220->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).v0_)) + (int64_t)((int64_t)(i_1694)))); (S9*)_t5219->b + hr_ix(_i5219, _t5219->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); })); 
if (((((v_1695).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t5221 = &(g554); int64_t _i5221 = (v_1695).si_; (S10*)_t5221->b + hr_ix(_i5221, _t5221->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).zero_)))) { if (fmt_1627) { { int32_t _e5223 = ((*({ hrv *_t5224 = &(g554); int64_t _i5224 = (v_1695).si_; (S10*)_t5224->b + hr_ix(_i5224, _t5224->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).fnum_; for (int32_t _k5223 = 0; _k5223 < _e5223; _k5223++) { int32_t j_1696 = (int32_t)_k5223; S11 f_1697 = (*({ hrv *_t5225 = &(g555); int64_t _i5225 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5226 = &(g554); int64_t _i5226 = (v_1695).si_; (S10*)_t5226->b + hr_ix(_i5226, _t5226->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).f0_)) + (int64_t)((int64_t)(j_1696)))); (S11*)_t5225->b + hr_ix(_i5225, _t5225->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); })); 
if ((((f_1697).ty_) >= (((int32_t)0LL)))) { (void)(f297_comp_one(((int64_t)((f_1697).ty_)), fmt_1627));
 }
 } } _bk5222:; 
 } else { (void)(f295_gen_heq(f125_t_variant(ei_1693, ((int64_t)(i_1694)))));
 }
 }
 } } _bk5216:; 
 }
if ((((k_1629) == (((int64_t)8LL))) || ((k_1629) == (((int64_t)9LL))))) { (void)(f297_comp_one(((int64_t)((x_1628).a_)), fmt_1627));
 }
if (((k_1629) == (((int64_t)14LL)))) { { int32_t _e5232 = (x_1628).n_; for (int32_t _k5232 = 0; _k5232 < _e5232; _k5232++) { int32_t i_1698 = (int32_t)_k5232; (void)(f297_comp_one(((int64_t)((*({ hrv *_t5234 = &(g552); int64_t _i5234 = ((int64_t)((int64_t)((int64_t)((x_1628).l_)) + (int64_t)((int64_t)(i_1698)))); (int32_t*)_t5234->b + hr_ix(_i5234, _t5234->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:405"); })))), fmt_1627));
 } } _bk5231:; 
 }
}
static void f297_comp_one(int64_t t_1633, bool fmt_1634) {
int64_t u_1635 = ({ int64_t _r5235; if (((((*({ hrv *_t5236 = &(g551); int64_t _i5236 = t_1633; (S1*)_t5236->b + hr_ix(_i5236, _t5236->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:398"); }))).k_) == (((uint8_t)10LL)))) { _r5235 = ((int64_t)(((*({ hrv *_t5237 = &(g551); int64_t _i5237 = t_1633; (S1*)_t5237->b + hr_ix(_i5237, _t5237->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:398"); }))).a_));  } else { _r5235 = t_1633;  } _r5235; }); 
if ((((((*({ hrv *_t5238 = &(g551); int64_t _i5238 = t_1633; (S1*)_t5238->b + hr_ix(_i5238, _t5238->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:398"); }))).k_) == (((uint8_t)10LL))) && (!(fmt_1634)))) { return;
 }
if (f298_need_helper(u_1635)) { if (fmt_1634) { (void)(f299_gen_hf(u_1635));
 } else { (void)(f295_gen_heq(u_1635));
 }
 }
}
static bool f298_need_helper(int64_t t_1636) {
int64_t k_1637 = ((int64_t)(((*({ hrv *_t5242 = &(g551); int64_t _i5242 = t_1636; (S1*)_t5242->b + hr_ix(_i5242, _t5242->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:397"); }))).k_)); 
if (f164_is_byte_arr(t_1636)) { return false;
 }
if (((k_1637) == (((int64_t)10LL)))) { return f298_need_helper(((int64_t)(((*({ hrv *_t5245 = &(g551); int64_t _i5245 = t_1636; (S1*)_t5245->b + hr_ix(_i5245, _t5245->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:397"); }))).a_)));
 }
return (((((((k_1637) == (((int64_t)5LL))) || ((k_1637) == (((int64_t)6LL)))) || ((k_1637) == (((int64_t)7LL)))) || ((k_1637) == (((int64_t)8LL)))) || ((k_1637) == (((int64_t)9LL)))) || ((k_1637) == (((int64_t)14LL))));
}
static void f299_gen_hf(int64_t t_1638) {
(void)(f263_cn_grow());
if ((((*({ hrv *_t5247 = &(g174); int64_t _i5247 = t_1638; (uint8_t*)_t5247->b + hr_ix(_i5247, _t5247->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:420"); }))) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t5248 = &((*({ hrv *_t5249 = &(g174); int64_t _i5249 = t_1638; (uint8_t*)_t5249->b + hr_ix(_i5249, _t5249->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:421"); }))); *_t5248 = ((uint8_t)1LL); }
S1 x_1639 = (*({ hrv *_t5250 = &(g551); int64_t _i5250 = t_1638; (S1*)_t5250->b + hr_ix(_i5250, _t5250->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:422"); })); 
int64_t k_1640 = ((int64_t)((x_1639).k_)); 
(void)(f262_cbody(t_1638));
bool sl_1641 = (((k_1640) == (((int64_t)9LL))) || ((((k_1640) == (((int64_t)8LL))) && (!(f282_is_fix(t_1638)))) && (!(f283_is_lim(t_1638))))); 
(void)(f300_hf_pre(t_1638));
L97 sig_1643 = ({ L97 _t5255; memset(&_t5255, 0, sizeof _t5255); _t5255.n = 0; _t5255; }); 
(void)(({ L97 *_l5256 = &(sig_1643); hrv _o5256 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5256, hr_str("static void hf", 14)); hr_fi(&_o5256, t_1638); hr_fs(&_o5256, hr_str("(hrv *o, ", 9)); if (_l5256->n + _o5256.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:427"); memcpy(_l5256->e + _l5256->n, _o5256.b, (size_t)_o5256.n); _l5256->n += _o5256.n; }));
(void)(({ L97 *_v5257 = &(sig_1643); hsl _s5257 = ({ hsl _r5258; if (sl_1641) { _r5258 = hr_str("hsl", 3);  } else { _r5258 = f264_cn(t_1638);  } _r5258; }); if (_v5257->n + _s5257.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:428"); memmove(_v5257->e + _v5257->n, _s5257.p, (size_t)_s5257.n * sizeof _v5257->e[0]); _v5257->n += _s5257.n; }));
(void)(({ L97 *_v5260 = &(sig_1643); hsl _s5260 = hr_str(" v)", 3); if (_v5260->n + _s5260.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:429"); memmove(_v5260->e + _v5260->n, _s5260.p, (size_t)_s5260.n * sizeof _v5260->e[0]); _v5260->n += _s5260.n; }));
(void)(({ hrv *_v5261 = &(g166); hsl _s5261 = ({ hsl _t5262 = ({ L97 *_t5263 = &(sig_1643); (hsl){ (uint8_t*)_t5263->e, _t5263->n }; }); int64_t _l5262 = 0, _h5262 = _t5262.n; if (_l5262 < 0 || _h5262 < _l5262 || _h5262 > _t5262.n) hr_slerr(_l5262, _h5262, _t5262.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:430"); (hsl){ _t5262.p + _l5262 * (int64_t)sizeof(uint8_t), _h5262 - _l5262 }; }); hr_append(_v5261, _s5261.p, _s5261.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5264 = &(g166); hsl _s5264 = hr_str(";\012", 2); hr_append(_v5264, _s5264.p, _s5264.n, sizeof(uint8_t)); }));
int64_t s0_1644 = (g169).n; 
(void)(({ hrv *_v5265 = &(g169); hsl _s5265 = ({ hsl _t5266 = ({ L97 *_t5267 = &(sig_1643); (hsl){ (uint8_t*)_t5267->e, _t5267->n }; }); int64_t _l5266 = 0, _h5266 = _t5266.n; if (_l5266 < 0 || _h5266 < _l5266 || _h5266 > _t5266.n) hr_slerr(_l5266, _h5266, _t5266.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:432"); (hsl){ _t5266.p + _l5266 * (int64_t)sizeof(uint8_t), _h5266 - _l5266 }; }); hr_append(_v5265, _s5265.p, _s5265.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" { ", 3)));
int64_t hk_1646 = ({ int64_t _r5269; if (((t_1638) < ((g349).n))) { _r5269 = ((int64_t)((*({ hrv *_t5270 = &(g349); int64_t _i5270 = t_1638; (int32_t*)_t5270->b + hr_ix(_i5270, _t5270->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:433"); }))));  } else { _r5269 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r5269; }); 
if (((hk_1646) >= (((int64_t)0LL)))) { int64_t pt_1647 = f208_ptype_of(hk_1646, ((int64_t)1LL)); 
bool byr_1648 = ((((*({ hrv *_t5272 = &(g551); int64_t _i5272 = pt_1647; (S1*)_t5272->b + hr_ix(_i5272, _t5272->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:436"); }))).k_) == (((uint8_t)10LL))); 
int64_t dp_1649 = f179_deref(pt_1647); 
if (((((dp_1649) != (t_1638)) && ((((*({ hrv *_t5274 = &(g551); int64_t _i5274 = dp_1649; (S1*)_t5274->b + hr_ix(_i5274, _t5274->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:438"); }))).k_) == (((uint8_t)6LL)))) && ((k_1640) == (((int64_t)7LL))))) { int64_t vi_1650 = ((int64_t)((x_1639).c_)); 
S9 vv_1651 = (*({ hrv *_t5275 = &(g557); int64_t _i5275 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5276 = &(g556); int64_t _i5276 = (x_1639).a_; (S8*)_t5276->b + hr_ix(_i5276, _t5276->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:438"); }))).v0_)) + (int64_t)vi_1650)); (S9*)_t5275->b + hr_ix(_i5275, _t5275->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:438"); })); 
(void)(({ hrv *_v5277 = &(g169); hsl _s5277 = f264_cn(dp_1649); hr_append(_v5277, _s5277.p, _s5277.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" e; memset(&e, 0, sizeof e); ", 29)));
(void)(({ hrv *_o5280 = &(g169); hr_fs(_o5280, hr_str("e.tag = ", 8)); hr_fi(_o5280, vi_1650); hr_fs(_o5280, hr_str("; ", 2)); }));
if (((((vv_1651).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t5281 = &(g554); int64_t _i5281 = (vv_1651).si_; (S10*)_t5281->b + hr_ix(_i5281, _t5281->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:438"); }))).zero_)))) { (void)(({ hrv *_o5282 = &(g169); hr_fs(_o5282, hr_str("e.u.v", 5)); hr_fi(_o5282, vi_1650); hr_fs(_o5282, hr_str(" = v; ", 6)); }));
 }
(void)(f302_fn_cname_to((&(g169)), hk_1646));
(void)(f301_hh(({ hsl _r5285; if (byr_1648) { _r5285 = hr_str("(o, &e); }\012", 11);  } else { _r5285 = hr_str("(o, e); }\012", 10);  } _r5285; })));
return;
 }
(void)(f302_fn_cname_to((&(g169)), hk_1646));
(void)(f301_hh(({ hsl _r5288; if (byr_1648) { _r5288 = hr_str("(o, &v); }\012", 11);  } else { _r5288 = hr_str("(o, v); }\012", 10);  } _r5288; })));
return;
 }
if (((k_1640) == (((int64_t)5LL)))) { int64_t si_1656 = ((int64_t)((x_1639).a_)); 
int64_t f0_1657 = ((int64_t)(((*({ hrv *_t5289 = &(g554); int64_t _i5289 = si_1656; (S10*)_t5289->b + hr_ix(_i5289, _t5289->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:443"); }))).f0_)); 
(void)(f301_hh(hr_str("hr_fc(o, \"", 10)));
hrv tnm_1658 __attribute__((cleanup(hr_rdrop))) = f126_ty_name(t_1638); 
(void)(({ hrv *_v5292 = &(g169); hsl _s5292 = ({ hsl _t5293 = hr_sl(tnm_1658); int64_t _l5293 = 0, _h5293 = _t5293.n; if (_l5293 < 0 || _h5293 < _l5293 || _h5293 > _t5293.n) hr_slerr(_l5293, _h5293, _t5293.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:444"); (hsl){ _t5293.p + _l5293 * (int64_t)sizeof(uint8_t), _h5293 - _l5293 }; }); hr_append(_v5292, _s5292.p, _s5292.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" { \"); ", 7)));
bool first_1659 = true; 
{ int32_t _e5296 = ((*({ hrv *_t5297 = &(g554); int64_t _i5297 = si_1656; (S10*)_t5297->b + hr_ix(_i5297, _t5297->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:446"); }))).fnum_; for (int32_t _k5296 = 0; _k5296 < _e5296; _k5296++) { int32_t i_1660 = (int32_t)_k5296; S11 f_1661 = (*({ hrv *_t5298 = &(g555); int64_t _i5298 = ((int64_t)((int64_t)f0_1657 + (int64_t)((int64_t)(i_1660)))); (S11*)_t5298->b + hr_ix(_i5298, _t5298->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:446"); })); 
if ((((f_1661).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1659))) { (void)(f301_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1659 = false;
L98 e_1662 = ({ L98 _t5300; memset(&_t5300, 0, sizeof _t5300); _t5300.n = 0; _t5300; }); 
(void)(({ L98 *_v5301 = &(e_1662); hsl _s5301 = hr_str("v.", 2); if (_v5301->n + _s5301.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:446"); memmove(_v5301->e + _v5301->n, _s5301.p, (size_t)_s5301.n * sizeof _v5301->e[0]); _v5301->n += _s5301.n; }));
{ hsl _v5303 = f10_nm(((int64_t)((f_1661).name_))); for (int64_t _k5303 = 0; _k5303 < _v5303.n; _k5303++) { uint8_t c_1663 = ((uint8_t*)_v5303.p)[_k5303]; (void)(({ L98 *_v5305 = &(e_1662); uint8_t _x5305 = c_1663; if (_v5305->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:446"); _v5305->e[_v5305->n] = _x5305; &_v5305->e[_v5305->n++]; }));
 } } _bk5302:; 
(void)(({ L98 *_v5306 = &(e_1662); uint8_t _x5306 = ((uint8_t)95LL); if (_v5306->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:446"); _v5306->e[_v5306->n] = _x5306; &_v5306->e[_v5306->n++]; }));
(void)(f303_hf_val(((int64_t)((f_1661).ty_)), ({ hsl _t5308 = ({ L98 *_t5309 = &(e_1662); (hsl){ (uint8_t*)_t5309->e, _t5309->n }; }); int64_t _l5308 = 0, _h5308 = _t5308.n; if (_l5308 < 0 || _h5308 < _l5308 || _h5308 > _t5308.n) hr_slerr(_l5308, _h5308, _t5308.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:446"); (hsl){ _t5308.p + _l5308 * (int64_t)sizeof(uint8_t), _h5308 - _l5308 }; })));
 } } _bk5295:; 
(void)(f301_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 }
if (((k_1640) == (((int64_t)6LL)))) { int64_t ei_1668 = ((int64_t)((x_1639).a_)); 
int64_t v0_1669 = ((int64_t)(((*({ hrv *_t5311 = &(g556); int64_t _i5311 = ei_1668; (S8*)_t5311->b + hr_ix(_i5311, _t5311->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:450"); }))).v0_)); 
{ int32_t _e5313 = ((*({ hrv *_t5314 = &(g556); int64_t _i5314 = ei_1668; (S8*)_t5314->b + hr_ix(_i5314, _t5314->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:451"); }))).vnum_; for (int32_t _k5313 = 0; _k5313 < _e5313; _k5313++) { int32_t i_1670 = (int32_t)_k5313; S9 v_1671 = (*({ hrv *_t5315 = &(g557); int64_t _i5315 = ((int64_t)((int64_t)v0_1669 + (int64_t)((int64_t)(i_1670)))); (S9*)_t5315->b + hr_ix(_i5315, _t5315->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:452"); })); 
(void)(({ hrv *_o5316 = &(g169); hr_fs(_o5316, hr_str("if (v.tag == ", 13)); hr_fi(_o5316, i_1670); hr_fs(_o5316, hr_str(") { ", 4)); }));
if (((((v_1671).si_) >= (((int32_t)0LL))) && ((((*({ hrv *_t5317 = &(g554); int64_t _i5317 = (v_1671).si_; (S10*)_t5317->b + hr_ix(_i5317, _t5317->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); }))).fnum_) > (((int32_t)0LL))))) { (void)(f301_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f301_hh(f10_nm(((int64_t)((v_1671).name_)))));
(void)(f301_hh(hr_str(" { \"); ", 7)));
bool first_1672 = true; 
int64_t sf0_1673 = ((int64_t)(((*({ hrv *_t5322 = &(g554); int64_t _i5322 = (v_1671).si_; (S10*)_t5322->b + hr_ix(_i5322, _t5322->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); }))).f0_)); 
{ int32_t _e5324 = ((*({ hrv *_t5325 = &(g554); int64_t _i5325 = (v_1671).si_; (S10*)_t5325->b + hr_ix(_i5325, _t5325->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); }))).fnum_; for (int32_t _k5324 = 0; _k5324 < _e5324; _k5324++) { int32_t j_1674 = (int32_t)_k5324; S11 f_1675 = (*({ hrv *_t5326 = &(g555); int64_t _i5326 = ((int64_t)((int64_t)sf0_1673 + (int64_t)((int64_t)(j_1674)))); (S11*)_t5326->b + hr_ix(_i5326, _t5326->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); })); 
if ((((f_1675).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1672))) { (void)(f301_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1672 = false;
L98 e_1676 = ({ L98 _t5328; memset(&_t5328, 0, sizeof _t5328); _t5328.n = 0; _t5328; }); 
(void)(({ L98 *_l5329 = &(e_1676); hrv _o5329 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5329, hr_str("v.u.v", 5)); hr_fi(&_o5329, i_1670); hr_fs(&_o5329, hr_str(".", 1)); if (_l5329->n + _o5329.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); memcpy(_l5329->e + _l5329->n, _o5329.b, (size_t)_o5329.n); _l5329->n += _o5329.n; }));
{ hsl _v5331 = f10_nm(((int64_t)((f_1675).name_))); for (int64_t _k5331 = 0; _k5331 < _v5331.n; _k5331++) { uint8_t c_1677 = ((uint8_t*)_v5331.p)[_k5331]; (void)(({ L98 *_v5333 = &(e_1676); uint8_t _x5333 = c_1677; if (_v5333->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); _v5333->e[_v5333->n] = _x5333; &_v5333->e[_v5333->n++]; }));
 } } _bk5330:; 
(void)(({ L98 *_v5334 = &(e_1676); uint8_t _x5334 = ((uint8_t)95LL); if (_v5334->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); _v5334->e[_v5334->n] = _x5334; &_v5334->e[_v5334->n++]; }));
(void)(f303_hf_val(((int64_t)((f_1675).ty_)), ({ hsl _t5336 = ({ L98 *_t5337 = &(e_1676); (hsl){ (uint8_t*)_t5337->e, _t5337->n }; }); int64_t _l5336 = 0, _h5336 = _t5336.n; if (_l5336 < 0 || _h5336 < _l5336 || _h5336 > _t5336.n) hr_slerr(_l5336, _h5336, _t5336.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); (hsl){ _t5336.p + _l5336 * (int64_t)sizeof(uint8_t), _h5336 - _l5336 }; })));
 } } _bk5323:; 
(void)(f301_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 } else { (void)(f301_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f301_hh(f10_nm(((int64_t)(((*({ hrv *_t5342 = &(g556); int64_t _i5342 = ei_1668; (S8*)_t5342->b + hr_ix(_i5342, _t5342->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:455"); }))).name_)))));
(void)(f301_hh(hr_str(".", 1)));
(void)(f301_hh(f10_nm(((int64_t)((v_1671).name_)))));
(void)(f301_hh(hr_str("\"); ", 4)));
 }
(void)(f301_hh(hr_str("} ", 2)));
 } } _bk5312:; 
 }
if (((k_1640) == (((int64_t)7LL)))) { int64_t ei_1678 = ((int64_t)((x_1639).a_)); 
S9 v_1679 = (*({ hrv *_t5348 = &(g557); int64_t _i5348 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5349 = &(g556); int64_t _i5349 = ei_1678; (S8*)_t5349->b + hr_ix(_i5349, _t5349->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:460"); }))).v0_)) + (int64_t)((int64_t)((x_1639).c_)))); (S9*)_t5348->b + hr_ix(_i5348, _t5348->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:460"); })); 
if (((((v_1679).si_) >= (((int32_t)0LL))) && ((((*({ hrv *_t5350 = &(g554); int64_t _i5350 = (v_1679).si_; (S10*)_t5350->b + hr_ix(_i5350, _t5350->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); }))).fnum_) > (((int32_t)0LL))))) { (void)(f301_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f301_hh(f10_nm(((int64_t)((v_1679).name_)))));
(void)(f301_hh(hr_str(" { \"); ", 7)));
bool first_1680 = true; 
int64_t sf0_1681 = ((int64_t)(((*({ hrv *_t5355 = &(g554); int64_t _i5355 = (v_1679).si_; (S10*)_t5355->b + hr_ix(_i5355, _t5355->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); }))).f0_)); 
{ int32_t _e5357 = ((*({ hrv *_t5358 = &(g554); int64_t _i5358 = (v_1679).si_; (S10*)_t5358->b + hr_ix(_i5358, _t5358->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); }))).fnum_; for (int32_t _k5357 = 0; _k5357 < _e5357; _k5357++) { int32_t j_1682 = (int32_t)_k5357; S11 f_1683 = (*({ hrv *_t5359 = &(g555); int64_t _i5359 = ((int64_t)((int64_t)sf0_1681 + (int64_t)((int64_t)(j_1682)))); (S11*)_t5359->b + hr_ix(_i5359, _t5359->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); })); 
if ((((f_1683).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1680))) { (void)(f301_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1680 = false;
L98 e_1684 = ({ L98 _t5361; memset(&_t5361, 0, sizeof _t5361); _t5361.n = 0; _t5361; }); 
(void)(({ L98 *_v5362 = &(e_1684); hsl _s5362 = hr_str("v.", 2); if (_v5362->n + _s5362.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); memmove(_v5362->e + _v5362->n, _s5362.p, (size_t)_s5362.n * sizeof _v5362->e[0]); _v5362->n += _s5362.n; }));
{ hsl _v5364 = f10_nm(((int64_t)((f_1683).name_))); for (int64_t _k5364 = 0; _k5364 < _v5364.n; _k5364++) { uint8_t c_1685 = ((uint8_t*)_v5364.p)[_k5364]; (void)(({ L98 *_v5366 = &(e_1684); uint8_t _x5366 = c_1685; if (_v5366->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); _v5366->e[_v5366->n] = _x5366; &_v5366->e[_v5366->n++]; }));
 } } _bk5363:; 
(void)(({ L98 *_v5367 = &(e_1684); uint8_t _x5367 = ((uint8_t)95LL); if (_v5367->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); _v5367->e[_v5367->n] = _x5367; &_v5367->e[_v5367->n++]; }));
(void)(f303_hf_val(((int64_t)((f_1683).ty_)), ({ hsl _t5369 = ({ L98 *_t5370 = &(e_1684); (hsl){ (uint8_t*)_t5370->e, _t5370->n }; }); int64_t _l5369 = 0, _h5369 = _t5369.n; if (_l5369 < 0 || _h5369 < _l5369 || _h5369 > _t5369.n) hr_slerr(_l5369, _h5369, _t5369.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); (hsl){ _t5369.p + _l5369 * (int64_t)sizeof(uint8_t), _h5369 - _l5369 }; })));
 } } _bk5356:; 
(void)(f301_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 } else { (void)(f301_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f301_hh(f10_nm(((int64_t)(((*({ hrv *_t5375 = &(g556); int64_t _i5375 = ei_1678; (S8*)_t5375->b + hr_ix(_i5375, _t5375->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:462"); }))).name_)))));
(void)(f301_hh(hr_str(".", 1)));
(void)(f301_hh(f10_nm(((int64_t)((v_1679).name_)))));
(void)(f301_hh(hr_str("\"); ", 4)));
 }
 }
if ((((k_1640) == (((int64_t)8LL))) || ((k_1640) == (((int64_t)9LL))))) { int64_t e_1686 = ((int64_t)((x_1639).a_)); 
(void)(f262_cbody(e_1686));
(void)(f301_hh(hr_str("hr_fb(o, '['); ", 15)));
if (f282_is_fix(t_1638)) { (void)(({ hrv *_o5383 = &(g169); hr_fs(_o5383, hr_str("for (int64_t i = 0; i < ", 24)); hr_fi(_o5383, (x_1639).b_); hr_fs(_o5383, hr_str("; i++) { if (i) hr_fc(o, \", \"); ", 32)); }));
(void)(f303_hf_val(e_1686, hr_str("v.e[i]", 6)));
(void)(f301_hh(hr_str("} ", 2)));
 } else { if (f283_is_lim(t_1638)) { (void)(f301_hh(hr_str("for (int64_t i = 0; i < v.n; i++) { if (i) hr_fc(o, \", \"); ", 59)));
(void)(f303_hf_val(e_1686, hr_str("v.e[i]", 6)));
(void)(f301_hh(hr_str("} ", 2)));
 } else { (void)(f301_hh(hr_str("for (int64_t i = 0; i < v.n; i++) { if (i) hr_fc(o, \", \"); ", 59)));
L98 ex_1687 = ({ L98 _t5391; memset(&_t5391, 0, sizeof _t5391); _t5391.n = 0; _t5391; }); 
(void)(({ L98 *_v5392 = &(ex_1687); hsl _s5392 = hr_str("((", 2); if (_v5392->n + _s5392.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:470"); memmove(_v5392->e + _v5392->n, _s5392.p, (size_t)_s5392.n * sizeof _v5392->e[0]); _v5392->n += _s5392.n; }));
(void)(({ L98 *_v5393 = &(ex_1687); hsl _s5393 = f264_cn(e_1686); if (_v5393->n + _s5393.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:470"); memmove(_v5393->e + _v5393->n, _s5393.p, (size_t)_s5393.n * sizeof _v5393->e[0]); _v5393->n += _s5393.n; }));
(void)(({ L98 *_v5395 = &(ex_1687); hsl _s5395 = hr_str("*)v.p)[i]", 9); if (_v5395->n + _s5395.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:470"); memmove(_v5395->e + _v5395->n, _s5395.p, (size_t)_s5395.n * sizeof _v5395->e[0]); _v5395->n += _s5395.n; }));
(void)(f303_hf_val(e_1686, ({ hsl _t5397 = ({ L98 *_t5398 = &(ex_1687); (hsl){ (uint8_t*)_t5398->e, _t5398->n }; }); int64_t _l5397 = 0, _h5397 = _t5397.n; if (_l5397 < 0 || _h5397 < _l5397 || _h5397 > _t5397.n) hr_slerr(_l5397, _h5397, _t5397.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:470"); (hsl){ _t5397.p + _l5397 * (int64_t)sizeof(uint8_t), _h5397 - _l5397 }; })));
(void)(f301_hh(hr_str("} ", 2)));
 }
 }
(void)(f301_hh(hr_str("hr_fb(o, ']'); ", 15)));
 }
if (((k_1640) == (((int64_t)14LL)))) { { int32_t _e5402 = (x_1639).n_; for (int32_t _k5402 = 0; _k5402 < _e5402; _k5402++) { int32_t i_1688 = (int32_t)_k5402; if (((i_1688) > (((int32_t)0LL)))) { (void)(f301_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
L99 e_1689 = ({ L99 _t5404; memset(&_t5404, 0, sizeof _t5404); _t5404.n = 0; _t5404; }); 
(void)(({ L99 *_l5405 = &(e_1689); hrv _o5405 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5405, hr_str("v.r", 3)); hr_fi(&_o5405, i_1688); if (_l5405->n + _o5405.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:473"); memcpy(_l5405->e + _l5405->n, _o5405.b, (size_t)_o5405.n); _l5405->n += _o5405.n; }));
(void)(f303_hf_val(((int64_t)((*({ hrv *_t5407 = &(g552); int64_t _i5407 = ((int64_t)((int64_t)((int64_t)((x_1639).l_)) + (int64_t)((int64_t)(i_1688)))); (int32_t*)_t5407->b + hr_ix(_i5407, _t5407->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:473"); })))), ({ hsl _t5408 = ({ L99 *_t5409 = &(e_1689); (hsl){ (uint8_t*)_t5409->e, _t5409->n }; }); int64_t _l5408 = 0, _h5408 = _t5408.n; if (_l5408 < 0 || _h5408 < _l5408 || _h5408 > _t5408.n) hr_slerr(_l5408, _h5408, _t5408.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:473"); (hsl){ _t5408.p + _l5408 * (int64_t)sizeof(uint8_t), _h5408 - _l5408 }; })));
 } } _bk5401:; 
 }
(void)(f301_hh(hr_str("}\012", 2)));
}
static void f300_hf_pre(int64_t t_1642) {
(void)(f296_comp_pre(t_1642, true));
}
static void f301_hh(hsl s_1645) {
(void)(({ hrv *_v5412 = &(g169); hsl _s5412 = s_1645; hr_append(_v5412, _s5412.p, _s5412.n, sizeof(uint8_t)); }));
}
static void f302_fn_cname_to(hrv* b_1652, int64_t i_1653) {
(void)(({ hrv *_o5413 = b_1652; hr_fs(_o5413, hr_str("f", 1)); hr_fi(_o5413, i_1653); hr_fs(_o5413, hr_str("_", 1)); }));
int64_t s_1654 = ((int64_t)(((*({ hrv *_t5414 = &(g388); int64_t _i5414 = i_1653; (S6*)_t5414->b + hr_ix(_i5414, _t5414->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:573"); }))).name_)); 
if (((s_1654) >= (((int64_t)0LL)))) { { hsl _v5416 = f10_nm(s_1654); for (int64_t _k5416 = 0; _k5416 < _v5416.n; _k5416++) { uint8_t c_1655 = ((uint8_t*)_v5416.p)[_k5416]; (void)(({ hrv *_v5418 = b_1652; uint8_t _x5418 = ({ uint8_t _r5419; if (((c_1655) == (((uint8_t)58LL)))) { _r5419 = ((uint8_t)95LL);  } else { _r5419 = c_1655;  } _r5419; }); uint8_t *_p5418 = (uint8_t*)hr_grow(_v5418, 1, sizeof _x5418); *_p5418 = _x5418; _p5418; }));
 } } _bk5415:; 
 }
}
static void f303_hf_val(int64_t t_1664, hsl e_1665) {
int64_t k_1666 = ((int64_t)(((*({ hrv *_t5420 = &(g551); int64_t _i5420 = t_1664; (S1*)_t5420->b + hr_ix(_i5420, _t5420->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:409"); }))).k_)); 
if (f164_is_byte_arr(t_1664)) { if (f282_is_fix(t_1664)) { (void)(({ hrv *_o5423 = &(g169); hr_fs(_o5423, hr_str("hr_fq(o, (hsl){ (uint8_t*)(", 27)); hr_fs(_o5423, e_1665); hr_fs(_o5423, hr_str(").e, ", 5)); hr_fi(_o5423, ((*({ hrv *_t5424 = &(g551); int64_t _i5424 = t_1664; (S1*)_t5424->b + hr_ix(_i5424, _t5424->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:410"); }))).b_); hr_fs(_o5423, hr_str(" }); ", 5)); }));
return;
 }
if (f283_is_lim(t_1664)) { (void)(({ hrv *_o5426 = &(g169); hr_fs(_o5426, hr_str("hr_fq(o, (hsl){ (uint8_t*)(", 27)); hr_fs(_o5426, e_1665); hr_fs(_o5426, hr_str(").e, (", 6)); hr_fs(_o5426, e_1665); hr_fs(_o5426, hr_str(").n }); ", 8)); }));
return;
 }
if (((((*({ hrv *_t5427 = &(g551); int64_t _i5427 = t_1664; (S1*)_t5427->b + hr_ix(_i5427, _t5427->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:410"); }))).k_) == (((uint8_t)9LL)))) { (void)(({ hrv *_o5428 = &(g169); hr_fs(_o5428, hr_str("hr_fq(o, ", 9)); hr_fs(_o5428, e_1665); hr_fs(_o5428, hr_str("); ", 3)); }));
return;
 }
(void)(({ hrv *_o5429 = &(g169); hr_fs(_o5429, hr_str("hr_fq(o, hr_sl(", 15)); hr_fs(_o5429, e_1665); hr_fs(_o5429, hr_str(")); ", 4)); }));
return;
 }
if (((k_1666) == (((int64_t)3LL)))) { (void)(({ hrv *_o5430 = &(g169); hr_fs(_o5430, ({ hsl _r5431; if (f153_is_signed(t_1664)) { _r5431 = hr_str("hr_fi(o, ", 9);  } else { _r5431 = hr_str("hr_fu(o, ", 9);  } _r5431; })); hr_fs(_o5430, e_1665); hr_fs(_o5430, hr_str("); ", 3)); }));
return;
 }
if (((k_1666) == (((int64_t)4LL)))) { (void)(({ hrv *_o5433 = &(g169); hr_fs(_o5433, ({ hsl _r5434; if (((((*({ hrv *_t5435 = &(g551); int64_t _i5435 = t_1664; (S1*)_t5435->b + hr_ix(_i5435, _t5435->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:412"); }))).s_) == (((uint8_t)4LL)))) { _r5434 = hr_str("hr_ff(o, ", 9);  } else { _r5434 = hr_str("hr_fd(o, ", 9);  } _r5434; })); hr_fs(_o5433, e_1665); hr_fs(_o5433, hr_str("); ", 3)); }));
return;
 }
if (((k_1666) == (((int64_t)2LL)))) { (void)(({ hrv *_o5436 = &(g169); hr_fs(_o5436, hr_str("hr_fc(o, (", 10)); hr_fs(_o5436, e_1665); hr_fs(_o5436, hr_str(") \077 \"true\" : \"false\"); ", 23)); }));
return;
 }
if (((k_1666) == (((int64_t)10LL)))) { if (((((*({ hrv *_t5437 = &(g551); int64_t _i5437 = t_1664; (S1*)_t5437->b + hr_ix(_i5437, _t5437->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:414"); }))).c_) >= (((int32_t)0LL)))) { (void)(({ hrv *_o5438 = &(g169); hr_fs(_o5438, hr_str("hr_fu(o, ", 9)); hr_fs(_o5438, e_1665); hr_fs(_o5438, hr_str("); ", 3)); }));
return;
 }
L97 pe_1667 = ({ L97 _t5439; memset(&_t5439, 0, sizeof _t5439); _t5439.n = 0; _t5439; }); 
(void)(({ L97 *_l5440 = &(pe_1667); hrv _o5440 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5440, hr_str("(*(", 3)); hr_fs(&_o5440, e_1665); hr_fs(&_o5440, hr_str("))", 2)); if (_l5440->n + _o5440.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:414"); memcpy(_l5440->e + _l5440->n, _o5440.b, (size_t)_o5440.n); _l5440->n += _o5440.n; }));
(void)(({ hrv *_o5441 = &(g169); hr_fs(_o5441, hr_str("if (", 4)); hr_fs(_o5441, e_1665); hr_fs(_o5441, hr_str(") { ", 4)); }));
(void)(f303_hf_val(((int64_t)(((*({ hrv *_t5443 = &(g551); int64_t _i5443 = t_1664; (S1*)_t5443->b + hr_ix(_i5443, _t5443->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:414"); }))).a_)), ({ hsl _t5444 = ({ L97 *_t5445 = &(pe_1667); (hsl){ (uint8_t*)_t5445->e, _t5445->n }; }); int64_t _l5444 = 0, _h5444 = _t5444.n; if (_l5444 < 0 || _h5444 < _l5444 || _h5444 > _t5444.n) hr_slerr(_l5444, _h5444, _t5444.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:414"); (hsl){ _t5444.p + _l5444 * (int64_t)sizeof(uint8_t), _h5444 - _l5444 }; })));
(void)(f301_hh(hr_str("} else hr_fc(o, \"null\"); ", 25)));
return;
 }
if (((((k_1666) == (((int64_t)8LL))) && (!(f282_is_fix(t_1664)))) && (!(f283_is_lim(t_1664))))) { (void)(({ hrv *_o5449 = &(g169); hr_fs(_o5449, hr_str("hf", 2)); hr_fi(_o5449, t_1664); hr_fs(_o5449, hr_str("(o, hr_sl(", 10)); hr_fs(_o5449, e_1665); hr_fs(_o5449, hr_str(")); ", 4)); }));
return;
 }
(void)(({ hrv *_o5450 = &(g169); hr_fs(_o5450, hr_str("hf", 2)); hr_fi(_o5450, t_1664); hr_fs(_o5450, hr_str("(o, ", 4)); hr_fs(_o5450, e_1665); hr_fs(_o5450, hr_str("); ", 3)); }));
}
static void f304_heq_val(int64_t t_1708, hsl a_1709, hsl b_1710) {
int64_t k_1711 = ((int64_t)(((*({ hrv *_t5451 = &(g551); int64_t _i5451 = t_1708; (S1*)_t5451->b + hr_ix(_i5451, _t5451->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:477"); }))).k_)); 
if ((((((k_1711) == (((int64_t)3LL))) || ((k_1711) == (((int64_t)4LL)))) || ((k_1711) == (((int64_t)2LL)))) || ((k_1711) == (((int64_t)10LL))))) { (void)(({ hrv *_o5452 = &(g169); hr_fs(_o5452, hr_str("(", 1)); hr_fs(_o5452, a_1709); hr_fs(_o5452, hr_str(") == (", 6)); hr_fs(_o5452, b_1710); hr_fs(_o5452, hr_str(")", 1)); }));
return;
 }
(void)(f295_gen_heq(t_1708));
if ((((k_1711) == (((int64_t)9LL))) || ((((k_1711) == (((int64_t)8LL))) && (!(f282_is_fix(t_1708)))) && (!(f283_is_lim(t_1708)))))) { (void)(({ hrv *_o5456 = &(g169); hr_fs(_o5456, hr_str("heq", 3)); hr_fi(_o5456, t_1708); hr_fs(_o5456, hr_str("(hr_sl(", 7)); hr_fs(_o5456, a_1709); hr_fs(_o5456, hr_str("), hr_sl(", 9)); hr_fs(_o5456, b_1710); hr_fs(_o5456, hr_str("))", 2)); }));
return;
 }
(void)(({ hrv *_o5457 = &(g169); hr_fs(_o5457, hr_str("heq", 3)); hr_fi(_o5457, t_1708); hr_fs(_o5457, hr_str("(", 1)); hr_fs(_o5457, a_1709); hr_fs(_o5457, hr_str(", ", 2)); hr_fs(_o5457, b_1710); hr_fs(_o5457, hr_str(")", 1)); }));
}
static bool f305_hsl_ty(int64_t t_1721) {
return (((((*({ hrv *_t5458 = &(g551); int64_t _i5458 = t_1721; (S1*)_t5458->b + hr_ix(_i5458, _t5458->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:793"); }))).k_) == (((uint8_t)9LL))) || ((((((*({ hrv *_t5459 = &(g551); int64_t _i5459 = t_1721; (S1*)_t5459->b + hr_ix(_i5459, _t5459->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:793"); }))).k_) == (((uint8_t)8LL))) && (!(f282_is_fix(t_1721)))) && (!(f283_is_lim(t_1721)))));
}
static void f306_gxas(int64_t n_1722, int64_t t_1723) {
int64_t f_1724 = f279_fin(n_1722); 
if (((f_1724) == (t_1723))) { (void)(f289_gx(n_1722));
return;
 }
(void)(f270_gcv(n_1722, f141_at(n_1722), t_1723));
}
static void f307_garith(int64_t o_1726, int64_t t0_1727, int64_t a_1728, int64_t b_1729, int64_t tv_1730, int64_t loc_1731) {
int64_t t_1732 = ({ int64_t _r5466; if (((((*({ hrv *_t5467 = &(g551); int64_t _i5467 = t0_1727; (S1*)_t5467->b + hr_ix(_i5467, _t5467->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:244"); }))).k_) == (((uint8_t)12LL)))) { _r5466 = g563;  } else { _r5466 = ({ int64_t _r5468; if (((((*({ hrv *_t5469 = &(g551); int64_t _i5469 = t0_1727; (S1*)_t5469->b + hr_ix(_i5469, _t5469->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:244"); }))).k_) == (((uint8_t)13LL)))) { _r5468 = g569;  } else { _r5468 = t0_1727;  } _r5468; });  } _r5466; }); 
int64_t k_1733 = ((int64_t)(((*({ hrv *_t5470 = &(g551); int64_t _i5470 = t_1732; (S1*)_t5470->b + hr_ix(_i5470, _t5470->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:245"); }))).k_)); 
int64_t lk_1734 = f180_leaf_kind(t_1732); 
if (((lk_1734) >= (((int64_t)4LL)))) { int64_t ta_1735 = ({ int64_t _r5472; if (((a_1728) >= (((int64_t)0LL)))) { _r5472 = f279_fin(a_1728);  } else { _r5472 = t_1732;  } _r5472; }); 
int64_t tb_1736 = ({ int64_t _r5474; if (((b_1729) >= (((int64_t)0LL)))) { _r5474 = f279_fin(b_1729);  } else { _r5474 = t_1732;  } _r5474; }); 
if (((ta_1735) != (t_1732))) { if (((o_1726) != (((int64_t)23LL)))) { (void)(f287_gerr(loc_1731, hr_str("only * takes a scalar on the left of a struct or array", 54)));
return;
 }
(void)(f260_ow(hr_str("hop", 3)));
(void)(f294_oi(t_1732));
(void)(f260_ow(hr_str("_", 1)));
(void)(f294_oi(o_1726));
(void)(f260_ow(hr_str("(", 1)));
(void)(f308_gopnd(b_1729, tv_1730));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f308_gopnd(a_1728, tv_1730));
(void)(f260_ow(hr_str(")", 1)));
(void)(f309_gen_hop(t_1732, o_1726, ta_1735));
return;
 }
(void)(f260_ow(hr_str("hop", 3)));
(void)(f294_oi(t_1732));
(void)(f260_ow(hr_str("_", 1)));
(void)(f294_oi(o_1726));
(void)(f260_ow(hr_str("(", 1)));
(void)(f308_gopnd(a_1728, tv_1730));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f308_gopnd(b_1729, tv_1730));
(void)(f260_ow(hr_str(")", 1)));
(void)(f309_gen_hop(t_1732, o_1726, tb_1736));
return;
 }
if (((k_1733) == (((int64_t)4LL)))) { if (((o_1726) == (((int64_t)25LL)))) { (void)(f260_ow(({ hsl _r5498; if (((((*({ hrv *_t5499 = &(g551); int64_t _i5499 = t_1732; (S1*)_t5499->b + hr_ix(_i5499, _t5499->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:252"); }))).s_) == (((uint8_t)4LL)))) { _r5498 = hr_str("fmodf(", 6);  } else { _r5498 = hr_str("fmod(", 5);  } _r5498; })));
(void)(f308_gopnd(a_1728, tv_1730));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f308_gopnd(b_1729, tv_1730));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
(void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1732));
(void)(f260_ow(hr_str(")(", 2)));
(void)(f308_gopnd(a_1728, tv_1730));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f260_ow(f311_ar_op(o_1726)));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f308_gopnd(b_1729, tv_1730));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (((k_1733) == (((int64_t)2LL)))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f308_gopnd(a_1728, tv_1730));
(void)(f260_ow(hr_str(") ", 2)));
(void)(f260_ow(f311_ar_op(o_1726)));
(void)(f260_ow(hr_str(" (", 2)));
(void)(f308_gopnd(b_1729, tv_1730));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
bool sg_1767 = (((k_1733) == (((int64_t)3LL))) && f153_is_signed(t_1732)); 
if ((((o_1726) == (((int64_t)24LL))) || ((o_1726) == (((int64_t)25LL))))) { (void)(f260_ow(({ hsl _r5524; if (((o_1726) == (((int64_t)24LL)))) { _r5524 = ({ hsl _r5525; if (sg_1767) { _r5525 = hr_str("HR_SDIV(", 8);  } else { _r5525 = hr_str("HR_UDIV(", 8);  } _r5525; });  } else { _r5524 = ({ hsl _r5526; if (sg_1767) { _r5526 = hr_str("HR_SMOD(", 8);  } else { _r5526 = hr_str("HR_UDIV_MOD(", 12);  } _r5526; });  } _r5524; })));
(void)(f261_ct(t_1732));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f308_gopnd(a_1728, tv_1730));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f308_gopnd(b_1729, tv_1730));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f312_wloc(loc_1731));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if ((((o_1726) == (((int64_t)43LL))) || ((o_1726) == (((int64_t)44LL))))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1732));
(void)(f260_ow(hr_str(")((", 3)));
(void)(f308_gopnd(a_1728, tv_1730));
(void)(f260_ow(hr_str(") ", 2)));
(void)(f260_ow(f311_ar_op(o_1726)));
(void)(f260_ow(hr_str(" ((", 3)));
(void)(f308_gopnd(b_1729, tv_1730));
(void)(({ hrv *_o5544 = &(g163); hr_fs(_o5544, hr_str(") & ", 4)); hr_fi(_o5544, ((int64_t)((int64_t)f154_ibits(t_1732) - (int64_t)((int64_t)1LL)))); hr_fs(_o5544, hr_str(")))", 3)); }));
return;
 }
(void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1732));
(void)(f260_ow(hr_str(")(", 2)));
if (sg_1767) { (void)(f260_ow(hr_str("(int64_t)", 9)));
 } else { (void)(f260_ow(hr_str("(uint64_t)", 10)));
 }
(void)(f308_gopnd(a_1728, tv_1730));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f260_ow(f311_ar_op(o_1726)));
(void)(f260_ow(hr_str(" ", 1)));
if (sg_1767) { (void)(f260_ow(hr_str("(int64_t)", 9)));
 } else { (void)(f260_ow(hr_str("(uint64_t)", 10)));
 }
(void)(f308_gopnd(b_1729, tv_1730));
(void)(f260_ow(hr_str("))", 2)));
}
static void f308_gopnd(int64_t n_1737, int64_t tv_1738) {
if (((n_1737) >= (((int64_t)0LL)))) { (void)(f289_gx(n_1737));
 } else { (void)(({ hrv *_o5561 = &(g163); hr_fs(_o5561, hr_str("(*_t", 4)); hr_fi(_o5561, tv_1738); hr_fs(_o5561, hr_str(")", 1)); }));
 }
}
static void f309_gen_hop(int64_t t_1739, int64_t o_1740, int64_t bt_1741) {
int64_t key_1742 = ((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)(t_1739)) * (int64_t)((int64_t)4096LL))) + (int64_t)((int64_t)((int64_t)((int64_t)(o_1740)) * (int64_t)((int64_t)64LL))))) + (int64_t)({ int64_t _r5562; if (((bt_1741) == (t_1739))) { _r5562 = ((int64_t)0LL);  } else { _r5562 = ((int64_t)1LL);  } _r5562; }))); 
{ hrv *_v5564 = &(g240); for (int64_t _k5564 = 0; _k5564 < _v5564->n; _k5564++) { int64_t h_1743 = ((int64_t*)_v5564->b)[_k5564]; if (((h_1743) == (key_1742))) { return;
 }
 } } _bk5563:; 
(void)(({ hrv *_v5565 = &(g240); int64_t _x5565 = key_1742; int64_t *_p5565 = (int64_t*)hr_grow(_v5565, 1, sizeof _x5565); *_p5565 = _x5565; _p5565; }));
(void)(f262_cbody(t_1739));
int64_t lt_1744 = f181_leaf_type(t_1739); 
bool sc_1745 = ((bt_1741) != (t_1739)); 
L97 sig_1746 = ({ L97 _t5568; memset(&_t5568, 0, sizeof _t5568); _t5568.n = 0; _t5568; }); 
(void)(({ L97 *_l5569 = &(sig_1746); hrv _o5569 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5569, hr_str("static ", 7)); if (_l5569->n + _o5569.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:530"); memcpy(_l5569->e + _l5569->n, _o5569.b, (size_t)_o5569.n); _l5569->n += _o5569.n; }));
(void)(({ L97 *_v5570 = &(sig_1746); hsl _s5570 = f264_cn(t_1739); if (_v5570->n + _s5570.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:530"); memmove(_v5570->e + _v5570->n, _s5570.p, (size_t)_s5570.n * sizeof _v5570->e[0]); _v5570->n += _s5570.n; }));
(void)(({ L97 *_l5572 = &(sig_1746); hrv _o5572 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5572, hr_str(" hop", 4)); hr_fi(&_o5572, t_1739); hr_fs(&_o5572, hr_str("_", 1)); hr_fi(&_o5572, o_1740); hr_fs(&_o5572, hr_str("(", 1)); if (_l5572->n + _o5572.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:530"); memcpy(_l5572->e + _l5572->n, _o5572.b, (size_t)_o5572.n); _l5572->n += _o5572.n; }));
(void)(({ L97 *_v5573 = &(sig_1746); hsl _s5573 = f264_cn(t_1739); if (_v5573->n + _s5573.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:531"); memmove(_v5573->e + _v5573->n, _s5573.p, (size_t)_s5573.n * sizeof _v5573->e[0]); _v5573->n += _s5573.n; }));
(void)(({ L97 *_v5575 = &(sig_1746); hsl _s5575 = hr_str(" a, ", 4); if (_v5575->n + _s5575.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:531"); memmove(_v5575->e + _v5575->n, _s5575.p, (size_t)_s5575.n * sizeof _v5575->e[0]); _v5575->n += _s5575.n; }));
(void)(({ L97 *_v5576 = &(sig_1746); hsl _s5576 = f264_cn(({ int64_t _r5578; if (sc_1745) { _r5578 = bt_1741;  } else { _r5578 = t_1739;  } _r5578; })); if (_v5576->n + _s5576.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:531"); memmove(_v5576->e + _v5576->n, _s5576.p, (size_t)_s5576.n * sizeof _v5576->e[0]); _v5576->n += _s5576.n; }));
(void)(({ L97 *_v5579 = &(sig_1746); hsl _s5579 = hr_str(" b)", 3); if (_v5579->n + _s5579.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:531"); memmove(_v5579->e + _v5579->n, _s5579.p, (size_t)_s5579.n * sizeof _v5579->e[0]); _v5579->n += _s5579.n; }));
(void)(({ hrv *_v5580 = &(g166); hsl _s5580 = ({ hsl _t5581 = ({ L97 *_t5582 = &(sig_1746); (hsl){ (uint8_t*)_t5582->e, _t5582->n }; }); int64_t _l5581 = 0, _h5581 = _t5581.n; if (_l5581 < 0 || _h5581 < _l5581 || _h5581 > _t5581.n) hr_slerr(_l5581, _h5581, _t5581.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:532"); (hsl){ _t5581.p + _l5581 * (int64_t)sizeof(uint8_t), _h5581 - _l5581 }; }); hr_append(_v5580, _s5580.p, _s5580.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5583 = &(g166); hsl _s5583 = hr_str(";\012", 2); hr_append(_v5583, _s5583.p, _s5583.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5584 = &(g169); hsl _s5584 = ({ hsl _t5585 = ({ L97 *_t5586 = &(sig_1746); (hsl){ (uint8_t*)_t5586->e, _t5586->n }; }); int64_t _l5585 = 0, _h5585 = _t5585.n; if (_l5585 < 0 || _h5585 < _l5585 || _h5585 > _t5585.n) hr_slerr(_l5585, _h5585, _t5585.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:533"); (hsl){ _t5585.p + _l5585 * (int64_t)sizeof(uint8_t), _h5585 - _l5585 }; }); hr_append(_v5584, _s5584.p, _s5584.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" { ", 3)));
(void)(({ hrv *_v5588 = &(g169); hsl _s5588 = f264_cn(t_1739); hr_append(_v5588, _s5588.p, _s5588.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" r; ", 4)));
(void)(f310_hop_body(t_1739, o_1740, hr_str("r", 1), hr_str("a", 1), hr_str("b", 1), sc_1745));
(void)(f301_hh(hr_str("return r; }\012", 12)));
}
static void f310_hop_body(int64_t t_1747, int64_t o_1748, hsl r_1749, hsl a_1750, hsl b_1751, bool sc_1752) {
int64_t k_1753 = ((int64_t)(((*({ hrv *_t5593 = &(g551); int64_t _i5593 = t_1747; (S1*)_t5593->b + hr_ix(_i5593, _t5593->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:538"); }))).k_)); 
if ((((k_1753) == (((int64_t)3LL))) || ((k_1753) == (((int64_t)4LL))))) { (void)(({ hrv *_o5594 = &(g169); hr_fs(_o5594, r_1749); hr_fs(_o5594, hr_str(" = (", 4)); }));
(void)(({ hrv *_v5595 = &(g169); hsl _s5595 = f264_cn(t_1747); hr_append(_v5595, _s5595.p, _s5595.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o5597 = &(g169); hr_fs(_o5597, hr_str(")((", 3)); hr_fs(_o5597, a_1750); hr_fs(_o5597, hr_str(") ", 2)); hr_fs(_o5597, f311_ar_op(o_1748)); hr_fs(_o5597, hr_str(" (", 2)); hr_fs(_o5597, b_1751); hr_fs(_o5597, hr_str(")); ", 4)); }));
return;
 }
if (((k_1753) == (((int64_t)5LL)))) { int64_t si_1755 = ((int64_t)(((*({ hrv *_t5599 = &(g551); int64_t _i5599 = t_1747; (S1*)_t5599->b + hr_ix(_i5599, _t5599->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:541"); }))).a_)); 
int64_t f0_1756 = ((int64_t)(((*({ hrv *_t5600 = &(g554); int64_t _i5600 = si_1755; (S10*)_t5600->b + hr_ix(_i5600, _t5600->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:541"); }))).f0_)); 
{ int32_t _e5602 = ((*({ hrv *_t5603 = &(g554); int64_t _i5603 = si_1755; (S10*)_t5603->b + hr_ix(_i5603, _t5603->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:542"); }))).fnum_; for (int32_t _k5602 = 0; _k5602 < _e5602; _k5602++) { int32_t i_1757 = (int32_t)_k5602; S11 f_1758 = (*({ hrv *_t5604 = &(g555); int64_t _i5604 = ((int64_t)((int64_t)f0_1756 + (int64_t)((int64_t)(i_1757)))); (S11*)_t5604->b + hr_ix(_i5604, _t5604->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:543"); })); 
if ((((f_1758).ty_) < (((int32_t)0LL)))) { continue;
 }
L97 rr_1759 = ({ L97 _t5605; memset(&_t5605, 0, sizeof _t5605); _t5605.n = 0; _t5605; }); 
L97 aa_1760 = ({ L97 _t5606; memset(&_t5606, 0, sizeof _t5606); _t5606.n = 0; _t5606; }); 
L97 bb_1761 = ({ L97 _t5607; memset(&_t5607, 0, sizeof _t5607); _t5607.n = 0; _t5607; }); 
(void)(({ L97 *_v5608 = &(rr_1759); hsl _s5608 = r_1749; if (_v5608->n + _s5608.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:545"); memmove(_v5608->e + _v5608->n, _s5608.p, (size_t)_s5608.n * sizeof _v5608->e[0]); _v5608->n += _s5608.n; }));
(void)(({ L97 *_v5609 = &(rr_1759); uint8_t _x5609 = ((uint8_t)46LL); if (_v5609->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:545"); _v5609->e[_v5609->n] = _x5609; &_v5609->e[_v5609->n++]; }));
(void)(({ L97 *_v5610 = &(aa_1760); hsl _s5610 = a_1750; if (_v5610->n + _s5610.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:545"); memmove(_v5610->e + _v5610->n, _s5610.p, (size_t)_s5610.n * sizeof _v5610->e[0]); _v5610->n += _s5610.n; }));
(void)(({ L97 *_v5611 = &(aa_1760); uint8_t _x5611 = ((uint8_t)46LL); if (_v5611->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:545"); _v5611->e[_v5611->n] = _x5611; &_v5611->e[_v5611->n++]; }));
(void)(({ L97 *_v5612 = &(bb_1761); hsl _s5612 = b_1751; if (_v5612->n + _s5612.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:545"); memmove(_v5612->e + _v5612->n, _s5612.p, (size_t)_s5612.n * sizeof _v5612->e[0]); _v5612->n += _s5612.n; }));
if ((!(sc_1752))) { (void)(({ L97 *_v5613 = &(bb_1761); uint8_t _x5613 = ((uint8_t)46LL); if (_v5613->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:545"); _v5613->e[_v5613->n] = _x5613; &_v5613->e[_v5613->n++]; }));
 }
{ hsl _v5615 = f10_nm(((int64_t)((f_1758).name_))); for (int64_t _k5615 = 0; _k5615 < _v5615.n; _k5615++) { uint8_t ch_1762 = ((uint8_t*)_v5615.p)[_k5615]; (void)(({ L97 *_v5617 = &(rr_1759); uint8_t _x5617 = ch_1762; if (_v5617->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:546"); _v5617->e[_v5617->n] = _x5617; &_v5617->e[_v5617->n++]; }));
(void)(({ L97 *_v5618 = &(aa_1760); uint8_t _x5618 = ch_1762; if (_v5618->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:546"); _v5618->e[_v5618->n] = _x5618; &_v5618->e[_v5618->n++]; }));
if ((!(sc_1752))) { (void)(({ L97 *_v5619 = &(bb_1761); uint8_t _x5619 = ch_1762; if (_v5619->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:546"); _v5619->e[_v5619->n] = _x5619; &_v5619->e[_v5619->n++]; }));
 }
 } } _bk5614:; 
(void)(({ L97 *_v5620 = &(rr_1759); uint8_t _x5620 = ((uint8_t)95LL); if (_v5620->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:547"); _v5620->e[_v5620->n] = _x5620; &_v5620->e[_v5620->n++]; }));
(void)(({ L97 *_v5621 = &(aa_1760); uint8_t _x5621 = ((uint8_t)95LL); if (_v5621->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:547"); _v5621->e[_v5621->n] = _x5621; &_v5621->e[_v5621->n++]; }));
if ((!(sc_1752))) { (void)(({ L97 *_v5622 = &(bb_1761); uint8_t _x5622 = ((uint8_t)95LL); if (_v5622->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:547"); _v5622->e[_v5622->n] = _x5622; &_v5622->e[_v5622->n++]; }));
 }
(void)(f310_hop_body(((int64_t)((f_1758).ty_)), o_1748, ({ hsl _t5624 = ({ L97 *_t5625 = &(rr_1759); (hsl){ (uint8_t*)_t5625->e, _t5625->n }; }); int64_t _l5624 = 0, _h5624 = _t5624.n; if (_l5624 < 0 || _h5624 < _l5624 || _h5624 > _t5624.n) hr_slerr(_l5624, _h5624, _t5624.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:548"); (hsl){ _t5624.p + _l5624 * (int64_t)sizeof(uint8_t), _h5624 - _l5624 }; }), ({ hsl _t5626 = ({ L97 *_t5627 = &(aa_1760); (hsl){ (uint8_t*)_t5627->e, _t5627->n }; }); int64_t _l5626 = 0, _h5626 = _t5626.n; if (_l5626 < 0 || _h5626 < _l5626 || _h5626 > _t5626.n) hr_slerr(_l5626, _h5626, _t5626.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:548"); (hsl){ _t5626.p + _l5626 * (int64_t)sizeof(uint8_t), _h5626 - _l5626 }; }), ({ hsl _t5628 = ({ L97 *_t5629 = &(bb_1761); (hsl){ (uint8_t*)_t5629->e, _t5629->n }; }); int64_t _l5628 = 0, _h5628 = _t5628.n; if (_l5628 < 0 || _h5628 < _l5628 || _h5628 > _t5628.n) hr_slerr(_l5628, _h5628, _t5628.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:548"); (hsl){ _t5628.p + _l5628 * (int64_t)sizeof(uint8_t), _h5628 - _l5628 }; }), sc_1752));
 } } _bk5601:; 
return;
 }
if (f282_is_fix(t_1747)) { int64_t p_1763 = f293_nt(); 
(void)(({ hrv *_o5632 = &(g169); hr_fs(_o5632, hr_str("for (int64_t _i", 15)); hr_fi(_o5632, p_1763); hr_fs(_o5632, hr_str(" = 0; _i", 8)); hr_fi(_o5632, p_1763); hr_fs(_o5632, hr_str(" < ", 3)); hr_fi(_o5632, ((*({ hrv *_t5633 = &(g551); int64_t _i5633 = t_1747; (S1*)_t5633->b + hr_ix(_i5633, _t5633->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:554"); }))).b_); hr_fs(_o5632, hr_str("; _i", 4)); hr_fi(_o5632, p_1763); hr_fs(_o5632, hr_str("++) { ", 6)); }));
L97 rr_1764 = ({ L97 _t5634; memset(&_t5634, 0, sizeof _t5634); _t5634.n = 0; _t5634; }); 
L97 aa_1765 = ({ L97 _t5635; memset(&_t5635, 0, sizeof _t5635); _t5635.n = 0; _t5635; }); 
L97 bb_1766 = ({ L97 _t5636; memset(&_t5636, 0, sizeof _t5636); _t5636.n = 0; _t5636; }); 
(void)(({ L97 *_l5637 = &(rr_1764); hrv _o5637 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5637, r_1749); hr_fs(&_o5637, hr_str(".e[_i", 5)); hr_fi(&_o5637, p_1763); hr_fs(&_o5637, hr_str("]", 1)); if (_l5637->n + _o5637.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:556"); memcpy(_l5637->e + _l5637->n, _o5637.b, (size_t)_o5637.n); _l5637->n += _o5637.n; }));
(void)(({ L97 *_l5638 = &(aa_1765); hrv _o5638 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5638, a_1750); hr_fs(&_o5638, hr_str(".e[_i", 5)); hr_fi(&_o5638, p_1763); hr_fs(&_o5638, hr_str("]", 1)); if (_l5638->n + _o5638.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:556"); memcpy(_l5638->e + _l5638->n, _o5638.b, (size_t)_o5638.n); _l5638->n += _o5638.n; }));
if (sc_1752) { (void)(({ L97 *_v5639 = &(bb_1766); hsl _s5639 = b_1751; if (_v5639->n + _s5639.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:556"); memmove(_v5639->e + _v5639->n, _s5639.p, (size_t)_s5639.n * sizeof _v5639->e[0]); _v5639->n += _s5639.n; }));
 } else { (void)(({ L97 *_l5640 = &(bb_1766); hrv _o5640 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5640, b_1751); hr_fs(&_o5640, hr_str(".e[_i", 5)); hr_fi(&_o5640, p_1763); hr_fs(&_o5640, hr_str("]", 1)); if (_l5640->n + _o5640.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:556"); memcpy(_l5640->e + _l5640->n, _o5640.b, (size_t)_o5640.n); _l5640->n += _o5640.n; }));
 }
(void)(f310_hop_body(((int64_t)(((*({ hrv *_t5642 = &(g551); int64_t _i5642 = t_1747; (S1*)_t5642->b + hr_ix(_i5642, _t5642->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:557"); }))).a_)), o_1748, ({ hsl _t5643 = ({ L97 *_t5644 = &(rr_1764); (hsl){ (uint8_t*)_t5644->e, _t5644->n }; }); int64_t _l5643 = 0, _h5643 = _t5643.n; if (_l5643 < 0 || _h5643 < _l5643 || _h5643 > _t5643.n) hr_slerr(_l5643, _h5643, _t5643.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:557"); (hsl){ _t5643.p + _l5643 * (int64_t)sizeof(uint8_t), _h5643 - _l5643 }; }), ({ hsl _t5645 = ({ L97 *_t5646 = &(aa_1765); (hsl){ (uint8_t*)_t5646->e, _t5646->n }; }); int64_t _l5645 = 0, _h5645 = _t5645.n; if (_l5645 < 0 || _h5645 < _l5645 || _h5645 > _t5645.n) hr_slerr(_l5645, _h5645, _t5645.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:557"); (hsl){ _t5645.p + _l5645 * (int64_t)sizeof(uint8_t), _h5645 - _l5645 }; }), ({ hsl _t5647 = ({ L97 *_t5648 = &(bb_1766); (hsl){ (uint8_t*)_t5648->e, _t5648->n }; }); int64_t _l5647 = 0, _h5647 = _t5647.n; if (_l5647 < 0 || _h5647 < _l5647 || _h5647 > _t5647.n) hr_slerr(_l5647, _h5647, _t5647.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:557"); (hsl){ _t5647.p + _l5647 * (int64_t)sizeof(uint8_t), _h5647 - _l5647 }; }), sc_1752));
(void)(f301_hh(hr_str("} ", 2)));
 }
}
static hsl f311_ar_op(int64_t o_1754) {
if ((((o_1754) == (((int64_t)21LL))) || ((o_1754) == (((int64_t)26LL))))) { return hr_str("+", 1);
 }
if ((((o_1754) == (((int64_t)22LL))) || ((o_1754) == (((int64_t)27LL))))) { return hr_str("-", 1);
 }
if ((((o_1754) == (((int64_t)23LL))) || ((o_1754) == (((int64_t)28LL))))) { return hr_str("*", 1);
 }
if ((((o_1754) == (((int64_t)24LL))) || ((o_1754) == (((int64_t)29LL))))) { return hr_str("/", 1);
 }
if ((((o_1754) == (((int64_t)25LL))) || ((o_1754) == (((int64_t)30LL))))) { return hr_str("%", 1);
 }
if ((((o_1754) == (((int64_t)49LL))) || ((o_1754) == (((int64_t)31LL))))) { return hr_str("&", 1);
 }
if ((((o_1754) == (((int64_t)50LL))) || ((o_1754) == (((int64_t)32LL))))) { return hr_str("|", 1);
 }
if ((((o_1754) == (((int64_t)51LL))) || ((o_1754) == (((int64_t)33LL))))) { return hr_str("^", 1);
 }
if ((((o_1754) == (((int64_t)43LL))) || ((o_1754) == (((int64_t)45LL))))) { return hr_str("<<", 2);
 }
if ((((o_1754) == (((int64_t)44LL))) || ((o_1754) == (((int64_t)46LL))))) { return hr_str(">>", 2);
 }
return hr_str("\077", 1);
}
static void f312_wloc(int64_t n_1768) {
S3 x_1769 = (*({ hrv *_t5650 = &(g914); int64_t _i5650 = ((*({ hrv *_t5651 = &(g704); int64_t _i5651 = f103_max(n_1768, ((int64_t)0LL)); (S4*)_t5651->b + hr_ix(_i5651, _t5651->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:100"); }))).t_; (S3*)_t5650->b + hr_ix(_i5650, _t5650->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:100"); })); 
(void)(f260_ow(hr_str("\"", 1)));
{ hsl _v5655 = f10_nm(((int64_t)(((*({ hrv *_t5657 = &(g913); int64_t _i5657 = (x_1769).f_; (S2*)_t5657->b + hr_ix(_i5657, _t5657->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:100"); }))).name_))); for (int64_t _k5655 = 0; _k5655 < _v5655.n; _k5655++) { uint8_t c_1770 = ((uint8_t*)_v5655.p)[_k5655]; if ((((c_1770) == (((uint8_t)34LL))) || ((c_1770) == (((uint8_t)92LL))))) { (void)(({ hrv *_v5658 = &(g163); uint8_t _x5658 = ((uint8_t)92LL); uint8_t *_p5658 = (uint8_t*)hr_grow(_v5658, 1, sizeof _x5658); *_p5658 = _x5658; _p5658; }));
 }
(void)(({ hrv *_v5659 = &(g163); uint8_t _x5659 = c_1770; uint8_t *_p5659 = (uint8_t*)hr_grow(_v5659, 1, sizeof _x5659); *_p5659 = _x5659; _p5659; }));
 } } _bk5654:; 
(void)(({ hrv *_o5660 = &(g163); hr_fs(_o5660, hr_str(":", 1)); hr_fi(_o5660, (x_1769).line_); hr_fs(_o5660, hr_str("\"", 1)); }));
}
static void f313_gun(int64_t n_1771) {
S4 x_1772 = (*({ hrv *_t5661 = &(g704); int64_t _i5661 = n_1771; (S4*)_t5661->b + hr_ix(_i5661, _t5661->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:279"); })); 
int64_t o_1773 = ((int64_t)((x_1772).op_)); 
int64_t a_1774 = ((int64_t)((x_1772).a_)); 
if (((o_1773) == (((int64_t)47LL)))) { (void)(f260_ow(hr_str("(!(", 3)));
(void)(f289_gx(a_1774));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (((o_1773) == (((int64_t)49LL)))) { (void)(f289_gx(a_1774));
return;
 }
int64_t t_1775 = f279_fin(n_1771); 
if (((o_1773) == (((int64_t)22LL)))) { if (((((*({ hrv *_t5667 = &(g551); int64_t _i5667 = t_1775; (S1*)_t5667->b + hr_ix(_i5667, _t5667->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:283"); }))).k_) == (((uint8_t)4LL)))) { (void)(f260_ow(hr_str("(-(", 3)));
(void)(f289_gx(a_1774));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (((f180_leaf_kind(t_1775)) >= (((int64_t)4LL)))) { (void)(f260_ow(hr_str("hneg", 4)));
(void)(f294_oi(t_1775));
(void)(f260_ow(hr_str("(", 1)));
(void)(f289_gx(a_1774));
(void)(f260_ow(hr_str(")", 1)));
(void)(f314_gen_hneg(t_1775));
return;
 }
(void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1775));
(void)(f260_ow(hr_str(")(0 - (uint64_t)(", 17)));
(void)(f289_gx(a_1774));
(void)(f260_ow(hr_str(")))", 3)));
return;
 }
if (((o_1773) == (((int64_t)48LL)))) { (void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1775));
(void)(f260_ow(hr_str(")~(", 3)));
(void)(f289_gx(a_1774));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
if (((o_1773) == (((int64_t)23LL)))) { (void)(f260_ow(hr_str("(*", 2)));
(void)(f289_gx(a_1774));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((o_1773) == (((int64_t)21LL)))) { (void)(f289_gx(a_1774));
return;
 }
(void)(f287_gerr(n_1771, hr_str("unsupported unary operator", 26)));
}
static void f314_gen_hneg(int64_t t_1776) {
{ hrv *_v5694 = &(g243); for (int64_t _k5694 = 0; _k5694 < _v5694->n; _k5694++) { int32_t h_1777 = ((int32_t*)_v5694->b)[_k5694]; if (((((int64_t)(h_1777))) == (t_1776))) { return;
 }
 } } _bk5693:; 
(void)(({ hrv *_v5695 = &(g243); int32_t _x5695 = ((int32_t)(t_1776)); int32_t *_p5695 = (int32_t*)hr_grow(_v5695, 1, sizeof _x5695); *_p5695 = _x5695; _p5695; }));
(void)(f262_cbody(t_1776));
L97 sig_1778 = ({ L97 _t5697; memset(&_t5697, 0, sizeof _t5697); _t5697.n = 0; _t5697; }); 
(void)(({ L97 *_l5698 = &(sig_1778); hrv _o5698 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5698, hr_str("static ", 7)); if (_l5698->n + _o5698.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:567"); memcpy(_l5698->e + _l5698->n, _o5698.b, (size_t)_o5698.n); _l5698->n += _o5698.n; }));
(void)(({ L97 *_v5699 = &(sig_1778); hsl _s5699 = f264_cn(t_1776); if (_v5699->n + _s5699.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:567"); memmove(_v5699->e + _v5699->n, _s5699.p, (size_t)_s5699.n * sizeof _v5699->e[0]); _v5699->n += _s5699.n; }));
(void)(({ L97 *_l5701 = &(sig_1778); hrv _o5701 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5701, hr_str(" hneg", 5)); hr_fi(&_o5701, t_1776); hr_fs(&_o5701, hr_str("(", 1)); if (_l5701->n + _o5701.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:567"); memcpy(_l5701->e + _l5701->n, _o5701.b, (size_t)_o5701.n); _l5701->n += _o5701.n; }));
(void)(({ L97 *_v5702 = &(sig_1778); hsl _s5702 = f264_cn(t_1776); if (_v5702->n + _s5702.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:567"); memmove(_v5702->e + _v5702->n, _s5702.p, (size_t)_s5702.n * sizeof _v5702->e[0]); _v5702->n += _s5702.n; }));
(void)(({ L97 *_v5704 = &(sig_1778); hsl _s5704 = hr_str(" a)", 3); if (_v5704->n + _s5704.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:567"); memmove(_v5704->e + _v5704->n, _s5704.p, (size_t)_s5704.n * sizeof _v5704->e[0]); _v5704->n += _s5704.n; }));
(void)(({ hrv *_v5705 = &(g166); hsl _s5705 = ({ hsl _t5706 = ({ L97 *_t5707 = &(sig_1778); (hsl){ (uint8_t*)_t5707->e, _t5707->n }; }); int64_t _l5706 = 0, _h5706 = _t5706.n; if (_l5706 < 0 || _h5706 < _l5706 || _h5706 > _t5706.n) hr_slerr(_l5706, _h5706, _t5706.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:568"); (hsl){ _t5706.p + _l5706 * (int64_t)sizeof(uint8_t), _h5706 - _l5706 }; }); hr_append(_v5705, _s5705.p, _s5705.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5708 = &(g166); hsl _s5708 = hr_str(";\012", 2); hr_append(_v5708, _s5708.p, _s5708.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5709 = &(g169); hsl _s5709 = ({ hsl _t5710 = ({ L97 *_t5711 = &(sig_1778); (hsl){ (uint8_t*)_t5711->e, _t5711->n }; }); int64_t _l5710 = 0, _h5710 = _t5710.n; if (_l5710 < 0 || _h5710 < _l5710 || _h5710 > _t5710.n) hr_slerr(_l5710, _h5710, _t5710.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:569"); (hsl){ _t5710.p + _l5710 * (int64_t)sizeof(uint8_t), _h5710 - _l5710 }; }); hr_append(_v5709, _s5709.p, _s5709.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" { ", 3)));
(void)(({ hrv *_v5713 = &(g169); hsl _s5713 = f264_cn(t_1776); hr_append(_v5713, _s5713.p, _s5713.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" z; memset(&z, 0, sizeof z); ", 29)));
(void)(({ hrv *_v5716 = &(g169); hsl _s5716 = f264_cn(t_1776); hr_append(_v5716, _s5716.p, _s5716.n, sizeof(uint8_t)); }));
(void)(f301_hh(hr_str(" r; ", 4)));
(void)(f310_hop_body(t_1776, ((int64_t)22LL), hr_str("r", 1), hr_str("z", 1), hr_str("a", 1), false));
(void)(f301_hh(hr_str("return r; }\012", 12)));
}
static void f315_gidx(int64_t n_1790) {
S4 x_1791 = (*({ hrv *_t5721 = &(g704); int64_t _i5721 = n_1790; (S4*)_t5721->b + hr_ix(_i5721, _t5721->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:290"); })); 
int64_t a_1792 = ((int64_t)((x_1791).a_)); 
int64_t bt_1793 = f141_at(a_1792); 
int64_t d_1794 = f179_deref(bt_1793); 
int64_t e_1795 = ((int64_t)(((*({ hrv *_t5724 = &(g551); int64_t _i5724 = d_1794; (S1*)_t5724->b + hr_ix(_i5724, _t5724->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:294"); }))).a_)); 
int64_t p_1796 = f293_nt(); 
if ((f282_is_fix(d_1794) && ((((*({ hrv *_t5727 = &(g551); int64_t _i5727 = bt_1793; (S1*)_t5727->b + hr_ix(_i5727, _t5727->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:296"); }))).k_) != (((uint8_t)10LL))))) { (void)(f260_ow(hr_str("(", 1)));
(void)(f289_gx(a_1792));
(void)(f260_ow(hr_str(").e[hr_ix(", 10)));
(void)(f289_gx(((int64_t)((x_1791).b_))));
(void)(({ hrv *_o5732 = &(g163); hr_fs(_o5732, hr_str(", ", 2)); hr_fi(_o5732, ((*({ hrv *_t5733 = &(g551); int64_t _i5733 = d_1794; (S1*)_t5733->b + hr_ix(_i5733, _t5733->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:297"); }))).b_); hr_fs(_o5732, hr_str(", ", 2)); }));
(void)(f312_wloc(n_1790));
(void)(f260_ow(hr_str(")]", 2)));
return;
 }
(void)(f260_ow(hr_str("(*({ ", 5)));
if (((((*({ hrv *_t5737 = &(g551); int64_t _i5737 = d_1794; (S1*)_t5737->b + hr_ix(_i5737, _t5737->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:300"); }))).k_) == (((uint8_t)9LL)))) { (void)(f260_ow(hr_str("hsl _t", 6)));
(void)(f294_oi(p_1796));
(void)(f260_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t5741 = &(g551); int64_t _i5741 = bt_1793; (S1*)_t5741->b + hr_ix(_i5741, _t5741->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:300"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_ow(hr_str("*", 1)));
(void)(f275_gx0(a_1792));
 } else { (void)(f289_gx(a_1792));
 }
(void)(f260_ow(hr_str("; int64_t _i", 12)));
(void)(f294_oi(p_1796));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1791).b_))));
(void)(f260_ow(hr_str("; (", 3)));
(void)(f261_ct(e_1795));
(void)(f260_ow(hr_str("*)_t", 4)));
(void)(f294_oi(p_1796));
(void)(({ hrv *_o5753 = &(g163); hr_fs(_o5753, hr_str(".p + hr_ix(_i", 13)); hr_fi(_o5753, p_1796); hr_fs(_o5753, hr_str(", _t", 4)); hr_fi(_o5753, p_1796); hr_fs(_o5753, hr_str(".n, ", 4)); }));
(void)(f312_wloc(n_1790));
(void)(f260_ow(hr_str("); }))", 6)));
return;
 }
(void)(f261_ct(d_1794));
(void)(f260_ow(hr_str(" *_t", 4)));
(void)(f294_oi(p_1796));
(void)(f260_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t5760 = &(g551); int64_t _i5760 = bt_1793; (S1*)_t5760->b + hr_ix(_i5760, _t5760->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:302"); }))).k_) == (((uint8_t)10LL)))) { (void)(f275_gx0(a_1792));
 } else { if (f272_is_place(a_1792)) { (void)(f260_ow(hr_str("&(", 2)));
(void)(f289_gx(a_1792));
(void)(f260_ow(hr_str(")", 1)));
 } else { int64_t k_1797 = f273_tmp(d_1794, f268_is_res(d_1794)); 
(void)(f260_ow(hr_str("(", 1)));
(void)(f274_ot(k_1797));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f269_gxo(a_1792));
(void)(f260_ow(hr_str(", &", 3)));
(void)(f274_ot(k_1797));
(void)(f260_ow(hr_str(")", 1)));
 }
 }
(void)(f260_ow(hr_str("; int64_t _i", 12)));
(void)(f294_oi(p_1796));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1791).b_))));
(void)(f260_ow(hr_str("; ", 2)));
if (f268_is_res(d_1794)) { (void)(f260_ow(hr_str("(", 1)));
(void)(f261_ct(e_1795));
(void)(f260_ow(hr_str("*)_t", 4)));
(void)(f294_oi(p_1796));
(void)(({ hrv *_o5785 = &(g163); hr_fs(_o5785, hr_str("->b + hr_ix(_i", 14)); hr_fi(_o5785, p_1796); hr_fs(_o5785, hr_str(", _t", 4)); hr_fi(_o5785, p_1796); hr_fs(_o5785, hr_str("->n, ", 5)); }));
(void)(f312_wloc(n_1790));
(void)(f260_ow(hr_str("); }))", 6)));
return;
 }
if (f282_is_fix(d_1794)) { (void)(({ hrv *_o5789 = &(g163); hr_fs(_o5789, hr_str("_t", 2)); hr_fi(_o5789, p_1796); hr_fs(_o5789, hr_str("->e + hr_ix(_i", 14)); hr_fi(_o5789, p_1796); hr_fs(_o5789, hr_str(", ", 2)); hr_fi(_o5789, ((*({ hrv *_t5790 = &(g551); int64_t _i5790 = d_1794; (S1*)_t5790->b + hr_ix(_i5790, _t5790->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:305"); }))).b_); hr_fs(_o5789, hr_str(", ", 2)); }));
(void)(f312_wloc(n_1790));
(void)(f260_ow(hr_str("); }))", 6)));
return;
 }
(void)(({ hrv *_o5793 = &(g163); hr_fs(_o5793, hr_str("_t", 2)); hr_fi(_o5793, p_1796); hr_fs(_o5793, hr_str("->e + hr_ix(_i", 14)); hr_fi(_o5793, p_1796); hr_fs(_o5793, hr_str(", _t", 4)); hr_fi(_o5793, p_1796); hr_fs(_o5793, hr_str("->n, ", 5)); }));
(void)(f312_wloc(n_1790));
(void)(f260_ow(hr_str("); }))", 6)));
}
static void f316_gslice(int64_t n_1798) {
S4 x_1799 = (*({ hrv *_t5796 = &(g704); int64_t _i5796 = n_1798; (S4*)_t5796->b + hr_ix(_i5796, _t5796->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:309"); })); 
int64_t a_1800 = ((int64_t)((x_1799).a_)); 
int64_t d_1801 = f179_deref(f141_at(a_1800)); 
int64_t e_1802 = ((int64_t)(((*({ hrv *_t5799 = &(g551); int64_t _i5799 = d_1801; (S1*)_t5799->b + hr_ix(_i5799, _t5799->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:312"); }))).a_)); 
int64_t p_1803 = f293_nt(); 
(void)(f260_ow(hr_str("({ hsl _t", 9)));
(void)(f294_oi(p_1803));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f292_gsl(a_1800, f141_at(a_1800)));
(void)(f260_ow(hr_str("; int64_t _l", 12)));
(void)(f294_oi(p_1803));
(void)(f260_ow(hr_str(" = ", 3)));
if ((((x_1799).b_) >= (((int32_t)0LL)))) { if (((((uint16_t)((uint64_t)(x_1799).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_o5809 = &(g163); hr_fs(_o5809, hr_str("_t", 2)); hr_fi(_o5809, p_1803); hr_fs(_o5809, hr_str(".n - ", 5)); }));
 }
(void)(f289_gx(((int64_t)((x_1799).b_))));
 } else { (void)(f260_ow(hr_str("0", 1)));
 }
(void)(f260_ow(hr_str(", _h", 4)));
(void)(f294_oi(p_1803));
(void)(f260_ow(hr_str(" = ", 3)));
if ((((x_1799).c_) >= (((int32_t)0LL)))) { if (((((uint16_t)((uint64_t)(x_1799).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_o5815 = &(g163); hr_fs(_o5815, hr_str("_t", 2)); hr_fi(_o5815, p_1803); hr_fs(_o5815, hr_str(".n - ", 5)); }));
 }
(void)(f289_gx(((int64_t)((x_1799).c_))));
 } else { (void)(({ hrv *_o5817 = &(g163); hr_fs(_o5817, hr_str("_t", 2)); hr_fi(_o5817, p_1803); hr_fs(_o5817, hr_str(".n", 2)); }));
 }
(void)(({ hrv *_o5818 = &(g163); hr_fs(_o5818, hr_str("; if (_l", 8)); hr_fi(_o5818, p_1803); hr_fs(_o5818, hr_str(" < 0 || _h", 10)); hr_fi(_o5818, p_1803); hr_fs(_o5818, hr_str(" < _l", 5)); hr_fi(_o5818, p_1803); hr_fs(_o5818, hr_str(" || _h", 6)); hr_fi(_o5818, p_1803); hr_fs(_o5818, hr_str(" > _t", 5)); hr_fi(_o5818, p_1803); hr_fs(_o5818, hr_str(".n) hr_slerr(_l", 15)); hr_fi(_o5818, p_1803); hr_fs(_o5818, hr_str(", _h", 4)); hr_fi(_o5818, p_1803); hr_fs(_o5818, hr_str(", _t", 4)); hr_fi(_o5818, p_1803); hr_fs(_o5818, hr_str(".n, ", 4)); }));
(void)(f312_wloc(n_1798));
(void)(({ hrv *_o5820 = &(g163); hr_fs(_o5820, hr_str("); (hsl){ _t", 12)); hr_fi(_o5820, p_1803); hr_fs(_o5820, hr_str(".p + _l", 7)); hr_fi(_o5820, p_1803); hr_fs(_o5820, hr_str(" * (int64_t)sizeof(", 19)); }));
(void)(f261_ct(e_1802));
(void)(({ hrv *_o5822 = &(g163); hr_fs(_o5822, hr_str("), _h", 5)); hr_fi(_o5822, p_1803); hr_fs(_o5822, hr_str(" - _l", 5)); hr_fi(_o5822, p_1803); hr_fs(_o5822, hr_str(" }; })", 6)); }));
}
static void f317_garr(int64_t n_1806) {
S4 x_1807 = (*({ hrv *_t5823 = &(g704); int64_t _i5823 = n_1806; (S4*)_t5823->b + hr_ix(_i5823, _t5823->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:322"); })); 
int64_t t_1808 = f141_at(n_1806); 
int64_t e_1809 = ((int64_t)(((*({ hrv *_t5825 = &(g551); int64_t _i5825 = t_1808; (S1*)_t5825->b + hr_ix(_i5825, _t5825->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:324"); }))).a_)); 
int64_t p_1810 = f293_nt(); 
if (f268_is_res(t_1808)) { if (((((x_1807).n_) == (((int32_t)0LL))) && (((x_1807).a_) < (((int32_t)0LL))))) { (void)(f260_ow(hr_str("((hrv){0})", 10)));
return;
 }
(void)(f260_ow(hr_str("({ hrv _t", 9)));
(void)(f294_oi(p_1810));
(void)(f260_ow(hr_str(" = {0}; ", 8)));
if ((((x_1807).a_) >= (((int32_t)0LL)))) { (void)(f260_ow(hr_str("int64_t _c", 10)));
(void)(f294_oi(p_1810));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1807).b_))));
(void)(f260_ow(hr_str("; ", 2)));
(void)(f261_ct(e_1809));
(void)(f260_ow(hr_str(" _v", 3)));
(void)(f294_oi(p_1810));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1807).a_))));
(void)(f260_ow(hr_str("; ", 2)));
(void)(f261_ct(e_1809));
(void)(f260_ow(hr_str(" *_p", 4)));
(void)(f294_oi(p_1810));
(void)(f260_ow(hr_str(" = (", 4)));
(void)(f261_ct(e_1809));
(void)(({ hrv *_o5848 = &(g163); hr_fs(_o5848, hr_str("*)hr_grow(&_t", 13)); hr_fi(_o5848, p_1810); hr_fs(_o5848, hr_str(", _c", 4)); hr_fi(_o5848, p_1810); hr_fs(_o5848, hr_str(", sizeof _v", 11)); hr_fi(_o5848, p_1810); hr_fs(_o5848, hr_str("); for (int64_t _k = 0; _k < _c", 31)); hr_fi(_o5848, p_1810); hr_fs(_o5848, hr_str("; _k++) _p", 10)); hr_fi(_o5848, p_1810); hr_fs(_o5848, hr_str("[_k] = _v", 9)); hr_fi(_o5848, p_1810); hr_fs(_o5848, hr_str("; ", 2)); }));
 } else { (void)(f261_ct(e_1809));
(void)(f260_ow(hr_str(" *_p", 4)));
(void)(f294_oi(p_1810));
(void)(f260_ow(hr_str(" = (", 4)));
(void)(f261_ct(e_1809));
(void)(({ hrv *_o5854 = &(g163); hr_fs(_o5854, hr_str("*)hr_grow(&_t", 13)); hr_fi(_o5854, p_1810); hr_fs(_o5854, hr_str(", ", 2)); hr_fi(_o5854, (x_1807).n_); hr_fs(_o5854, hr_str(", sizeof(", 9)); }));
(void)(f261_ct(e_1809));
(void)(f260_ow(hr_str(")); ", 4)));
{ int32_t _e5858 = (x_1807).n_; for (int32_t _k5858 = 0; _k5858 < _e5858; _k5858++) { int32_t i_1811 = (int32_t)_k5858; (void)(({ hrv *_o5859 = &(g163); hr_fs(_o5859, hr_str("_p", 2)); hr_fi(_o5859, p_1810); hr_fs(_o5859, hr_str("[", 1)); hr_fi(_o5859, i_1811); hr_fs(_o5859, hr_str("] = ", 4)); }));
(void)(f289_gx(f90_kid(n_1806, ((int64_t)(i_1811)))));
(void)(f260_ow(hr_str("; ", 2)));
 } } _bk5857:; 
 }
(void)(f260_ow(hr_str("_t", 2)));
(void)(f294_oi(p_1810));
(void)(f260_ow(hr_str("; })", 4)));
return;
 }
if ((f282_is_fix(t_1808) || f283_is_lim(t_1808))) { (void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(t_1808));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_1810));
(void)(f260_ow(hr_str("; ", 2)));
if ((((x_1807).a_) >= (((int32_t)0LL)))) { (void)(f261_ct(e_1809));
(void)(f260_ow(hr_str(" _v", 3)));
(void)(f294_oi(p_1810));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1807).a_))));
(void)(({ hrv *_o5878 = &(g163); hr_fs(_o5878, hr_str("; for (int64_t _k = 0; _k < ", 28)); hr_fi(_o5878, ({ int64_t _r5879; if (f282_is_fix(t_1808)) { _r5879 = ((*({ hrv *_t5881 = &(g551); int64_t _i5881 = t_1808; (S1*)_t5881->b + hr_ix(_i5881, _t5881->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:336"); }))).b_;  } else { _r5879 = ((int64_t)0LL);  } _r5879; })); hr_fs(_o5878, hr_str("; _k++) _t", 10)); hr_fi(_o5878, p_1810); hr_fs(_o5878, hr_str(".e[_k] = _v", 11)); hr_fi(_o5878, p_1810); hr_fs(_o5878, hr_str("; ", 2)); }));
if (f283_is_lim(t_1808)) { (void)(f260_ow(hr_str("int64_t _c", 10)));
(void)(f294_oi(p_1810));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1807).b_))));
(void)(({ hrv *_o5887 = &(g163); hr_fs(_o5887, hr_str("; for (int64_t _k = 0; _k < _c", 30)); hr_fi(_o5887, p_1810); hr_fs(_o5887, hr_str("; _k++) _t", 10)); hr_fi(_o5887, p_1810); hr_fs(_o5887, hr_str(".e[_k] = _v", 11)); hr_fi(_o5887, p_1810); hr_fs(_o5887, hr_str("; _t", 4)); hr_fi(_o5887, p_1810); hr_fs(_o5887, hr_str(".n = _c", 7)); hr_fi(_o5887, p_1810); hr_fs(_o5887, hr_str("; ", 2)); }));
 }
 } else { if (f283_is_lim(t_1808)) { (void)(({ hrv *_o5889 = &(g163); hr_fs(_o5889, hr_str("memset(&_t", 10)); hr_fi(_o5889, p_1810); hr_fs(_o5889, hr_str(", 0, sizeof _t", 14)); hr_fi(_o5889, p_1810); hr_fs(_o5889, hr_str("); _t", 5)); hr_fi(_o5889, p_1810); hr_fs(_o5889, hr_str(".n = ", 5)); hr_fi(_o5889, (x_1807).n_); hr_fs(_o5889, hr_str("; ", 2)); }));
 }
{ int32_t _e5891 = (x_1807).n_; for (int32_t _k5891 = 0; _k5891 < _e5891; _k5891++) { int32_t i_1812 = (int32_t)_k5891; (void)(({ hrv *_o5892 = &(g163); hr_fs(_o5892, hr_str("_t", 2)); hr_fi(_o5892, p_1810); hr_fs(_o5892, hr_str(".e[", 3)); hr_fi(_o5892, i_1812); hr_fs(_o5892, hr_str("] = ", 4)); }));
(void)(f289_gx(f90_kid(n_1806, ((int64_t)(i_1812)))));
(void)(f260_ow(hr_str("; ", 2)));
 } } _bk5890:; 
 }
(void)(f260_ow(hr_str("_t", 2)));
(void)(f294_oi(p_1810));
(void)(f260_ow(hr_str("; })", 4)));
return;
 }
(void)(f287_gerr(n_1806, hr_str("unsupported array literal type", 30)));
}
static void f318_gslit(int64_t n_1813) {
S4 x_1814 = (*({ hrv *_t5900 = &(g704); int64_t _i5900 = n_1813; (S4*)_t5900->b + hr_ix(_i5900, _t5900->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:353"); })); 
int64_t t_1815 = f141_at(n_1813); 
int64_t si_1816 = f157_rv(n_1813); 
int64_t f0_1817 = ((int64_t)(((*({ hrv *_t5903 = &(g554); int64_t _i5903 = si_1816; (S10*)_t5903->b + hr_ix(_i5903, _t5903->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:356"); }))).f0_)); 
(void)(f260_ow(hr_str("((", 2)));
(void)(f261_ct(t_1815));
(void)(f260_ow(hr_str("){ ", 3)));
bool any_1818 = false; 
{ int32_t _e5908 = ((*({ hrv *_t5909 = &(g554); int64_t _i5909 = si_1816; (S10*)_t5909->b + hr_ix(_i5909, _t5909->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:359"); }))).fnum_; for (int32_t _k5908 = 0; _k5908 < _e5908; _k5908++) { int32_t j_1819 = (int32_t)_k5908; S11 f_1820 = (*({ hrv *_t5910 = &(g555); int64_t _i5910 = ((int64_t)((int64_t)f0_1817 + (int64_t)((int64_t)(j_1819)))); (S11*)_t5910->b + hr_ix(_i5910, _t5910->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:360"); })); 
if ((((f_1820).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t given_1821 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e5912 = (x_1814).n_; for (int32_t _k5912 = 0; _k5912 < _e5912; _k5912++) { int32_t i_1822 = (int32_t)_k5912; if (((f157_rv(f90_kid(n_1813, ((int64_t)(i_1822))))) == (((int64_t)(j_1819))))) { given_1821 = f90_kid(n_1813, ((int64_t)(i_1822)));
 }
 } } _bk5911:; 
if ((((given_1821) < (((int64_t)0LL))) && (((f_1820).def_) < (((int32_t)0LL))))) { continue;
 }
(void)(f260_ow(hr_str(".", 1)));
(void)(f267_fname_into((&(g163)), ((int64_t)((f_1820).name_))));
(void)(f260_ow(hr_str(" = ", 3)));
if (((given_1821) >= (((int64_t)0LL)))) { int64_t v_1823 = ((int64_t)(((*({ hrv *_t5919 = &(g704); int64_t _i5919 = given_1821; (S4*)_t5919->b + hr_ix(_i5919, _t5919->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:366"); }))).a_)); 
if (f268_is_res(((int64_t)((f_1820).ty_)))) { (void)(f269_gxo(v_1823));
 } else { (void)(f289_gx(v_1823));
 }
 } else { int64_t sa_1824 = g401; 
g401 = g403;
(void)(f289_gx(((int64_t)((f_1820).def_))));
g401 = sa_1824;
 }
(void)(f260_ow(hr_str(", ", 2)));
any_1818 = true;
 } } _bk5907:; 
if ((!(any_1818))) { (void)(f260_ow(hr_str("0", 1)));
 }
(void)(f260_ow(hr_str("})", 2)));
}
static void f319_gcall(int64_t n_1825) {
int64_t r_1826 = f156_rk(n_1825); 
if (((r_1826) == (((int64_t)4LL)))) { (void)(f320_gbuiltin(n_1825));
return;
 }
if (((r_1826) == (((int64_t)10LL)))) { (void)(f334_gblkcall(n_1825));
return;
 }
if (((r_1826) != (((int64_t)3LL)))) { (void)(f287_gerr(n_1825, hr_str("unsupported call", 16)));
return;
 }
int64_t inst_2050 = f157_rv(n_1825); 
int64_t recv_2051 = ({ int64_t _r5932; if ((((f217_ax(n_1825)) == (((int64_t)1LL))) && ((((*({ hrv *_t5934 = &(g704); int64_t _i5934 = ((*({ hrv *_t5935 = &(g704); int64_t _i5935 = n_1825; (S4*)_t5935->b + hr_ix(_i5935, _t5935->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:614"); }))).a_; (S4*)_t5934->b + hr_ix(_i5934, _t5934->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:614"); }))).k_) == (((uint8_t)14LL))))) { _r5932 = ((int64_t)(((*({ hrv *_t5936 = &(g704); int64_t _i5936 = ((*({ hrv *_t5937 = &(g704); int64_t _i5937 = n_1825; (S4*)_t5937->b + hr_ix(_i5937, _t5937->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:614"); }))).a_; (S4*)_t5936->b + hr_ix(_i5936, _t5936->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:614"); }))).a_));  } else { _r5932 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r5932; }); 
bool lrw_2053 = ((!(f357_is_ext(inst_2050))) && ((*({ hrv *_t5939 = &(g388); int64_t _i5939 = inst_2050; (S6*)_t5939->b + hr_ix(_i5939, _t5939->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:615"); }))).lr_); 
int64_t rt_2054 = ((int64_t)(((*({ hrv *_t5940 = &(g388); int64_t _i5940 = inst_2050; (S6*)_t5940->b + hr_ix(_i5940, _t5940->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:616"); }))).ret_)); 
bool vd_2055 = (((rt_2054) < (((int64_t)0LL))) || ((rt_2054) == (g558))); 
int64_t q_2056 = f293_nt(); 
if (lrw_2053) { (void)(f260_ow(hr_str("({ ", 3)));
if ((!(vd_2055))) { (void)(f261_ct(rt_2054));
(void)(({ hrv *_o5944 = &(g163); hr_fs(_o5944, hr_str(" _c", 3)); hr_fi(_o5944, q_2056); hr_fs(_o5944, hr_str(" = ", 3)); }));
 }
 }
if (f357_is_ext(inst_2050)) { (void)(f358_ext_name(inst_2050));
 } else { (void)(f323_fn_cname(inst_2050));
 }
(void)(f260_ow(hr_str("(", 1)));
(void)(f359_gcall_args(n_1825, inst_2050, recv_2051));
(void)(f260_ow(hr_str(")", 1)));
if (lrw_2053) { (void)(f260_ow(hr_str("; ", 2)));
(void)(f361_glrcheck());
if ((!(vd_2055))) { (void)(({ hrv *_o5953 = &(g163); hr_fs(_o5953, hr_str("_c", 2)); hr_fi(_o5953, q_2056); hr_fs(_o5953, hr_str("; ", 2)); }));
 }
(void)(f260_ow(hr_str("})", 2)));
 }
}
static void f320_gbuiltin(int64_t n_1827) {
S4 x_1828 = (*({ hrv *_t5955 = &(g704); int64_t _i5955 = n_1827; (S4*)_t5955->b + hr_ix(_i5955, _t5955->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:653"); })); 
int64_t b_1829 = f157_rv(n_1827); 
bool hasr_1830 = ((f217_ax(n_1827)) == (((int64_t)1LL))); 
int64_t recv_1831 = ({ int64_t _r5958; if (hasr_1830) { _r5958 = ((int64_t)(((*({ hrv *_t5959 = &(g704); int64_t _i5959 = (x_1828).a_; (S4*)_t5959->b + hr_ix(_i5959, _t5959->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:656"); }))).a_));  } else { _r5958 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r5958; }); 
int64_t total_1832 = ((int64_t)((int64_t)((int64_t)((x_1828).n_)) + (int64_t)({ int64_t _r5960; if (hasr_1830) { _r5960 = ((int64_t)1LL);  } else { _r5960 = ((int64_t)0LL);  } _r5960; }))); 

int64_t p_1834 = f293_nt(); 
if (((b_1829) == (((int64_t)1LL)))) { (void)(f260_ow(hr_str("({ ", 3)));
{ int32_t _e5964 = (x_1828).n_; for (int32_t _k5964 = 0; _k5964 < _e5964; _k5964++) { int32_t i_1835 = (int32_t)_k5964; int64_t c_1836 = f90_kid(n_1827, ((int64_t)(i_1835))); 
(void)(f322_gfmt(hr_str("&hr_ob", 6), c_1836, f279_fin(c_1836), true));
(void)(f260_ow(hr_str("; ", 2)));
 } } _bk5963:; 
(void)(f260_ow(hr_str("hr_println(); })", 16)));
return;
 }
if (((b_1829) == (((int64_t)2LL)))) { (void)(f260_ow(hr_str("({ hrv _o", 9)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" = {0}; ", 8)));
L99 nmo_1852 = ({ L99 _t5973; memset(&_t5973, 0, sizeof _t5973); _t5973.n = 0; _t5973; }); 
(void)(({ L99 *_l5974 = &(nmo_1852); hrv _o5974 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5974, hr_str("&_o", 3)); hr_fi(&_o5974, p_1834); if (_l5974->n + _o5974.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:661"); memcpy(_l5974->e + _l5974->n, _o5974.b, (size_t)_o5974.n); _l5974->n += _o5974.n; }));
{ int32_t _e5976 = (x_1828).n_; for (int32_t _k5976 = 0; _k5976 < _e5976; _k5976++) { int32_t i_1853 = (int32_t)_k5976; int64_t c_1854 = f90_kid(n_1827, ((int64_t)(i_1853))); 
(void)(f322_gfmt(({ hsl _t5979 = ({ L99 *_t5980 = &(nmo_1852); (hsl){ (uint8_t*)_t5980->e, _t5980->n }; }); int64_t _l5979 = 0, _h5979 = _t5979.n; if (_l5979 < 0 || _h5979 < _l5979 || _h5979 > _t5979.n) hr_slerr(_l5979, _h5979, _t5979.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:661"); (hsl){ _t5979.p + _l5979 * (int64_t)sizeof(uint8_t), _h5979 - _l5979 }; }), c_1854, f279_fin(c_1854), true));
(void)(f260_ow(hr_str("; ", 2)));
 } } _bk5975:; 
(void)(f260_ow(hr_str("_o", 2)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str("; })", 4)));
return;
 }
if ((((b_1829) == (((int64_t)3LL))) && f283_is_lim(f179_deref(f141_at(f321_arg(((int64_t)0LL), &recv_1831, &n_1827)))))) { int64_t lt_1855 = f179_deref(f141_at(f321_arg(((int64_t)0LL), &recv_1831, &n_1827))); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(lt_1855));
(void)(f260_ow(hr_str(" *_l", 4)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f325_grecv_ptr(f321_arg(((int64_t)0LL), &recv_1831, &n_1827)));
(void)(f260_ow(hr_str("; hrv _o", 8)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" __attribute__((cleanup(hr_rdrop))) = {0}; ", 43)));
L99 nmo_1859 = ({ L99 _t6003; memset(&_t6003, 0, sizeof _t6003); _t6003.n = 0; _t6003; }); 
(void)(({ L99 *_l6004 = &(nmo_1859); hrv _o6004 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6004, hr_str("&_o", 3)); hr_fi(&_o6004, p_1834); if (_l6004->n + _o6004.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:665"); memcpy(_l6004->e + _l6004->n, _o6004.b, (size_t)_o6004.n); _l6004->n += _o6004.n; }));
{ int64_t _e6006 = total_1832; for (int64_t _k6006 = ((int64_t)1LL); _k6006 < _e6006; _k6006++) { int64_t i_1860 = (int64_t)_k6006; int64_t c_1861 = f321_arg(i_1860, &recv_1831, &n_1827); 
(void)(f322_gfmt(({ hsl _t6009 = ({ L99 *_t6010 = &(nmo_1859); (hsl){ (uint8_t*)_t6010->e, _t6010->n }; }); int64_t _l6009 = 0, _h6009 = _t6009.n; if (_l6009 < 0 || _h6009 < _l6009 || _h6009 > _t6009.n) hr_slerr(_l6009, _h6009, _t6009.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:666"); (hsl){ _t6009.p + _l6009 * (int64_t)sizeof(uint8_t), _h6009 - _l6009 }; }), c_1861, f279_fin(c_1861), true));
(void)(f260_ow(hr_str("; ", 2)));
 } } _bk6005:; 
(void)(({ hrv *_o6013 = &(g163); hr_fs(_o6013, hr_str("if (_l", 6)); hr_fi(_o6013, p_1834); hr_fs(_o6013, hr_str("->n + _o", 8)); hr_fi(_o6013, p_1834); hr_fs(_o6013, hr_str(".n > ", 5)); hr_fi(_o6013, ((*({ hrv *_t6014 = &(g551); int64_t _i6014 = lt_1855; (S1*)_t6014->b + hr_ix(_i6014, _t6014->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:667"); }))).b_); hr_fs(_o6013, hr_str(") hr_die(\"format past a limited array's capacity\", ", 51)); }));
(void)(f312_wloc(n_1827));
(void)(({ hrv *_o6016 = &(g163); hr_fs(_o6016, hr_str("); memcpy(_l", 12)); hr_fi(_o6016, p_1834); hr_fs(_o6016, hr_str("->e + _l", 8)); hr_fi(_o6016, p_1834); hr_fs(_o6016, hr_str("->n, _o", 7)); hr_fi(_o6016, p_1834); hr_fs(_o6016, hr_str(".b, (size_t)_o", 14)); hr_fi(_o6016, p_1834); hr_fs(_o6016, hr_str(".n); _l", 7)); hr_fi(_o6016, p_1834); hr_fs(_o6016, hr_str("->n += _o", 9)); hr_fi(_o6016, p_1834); hr_fs(_o6016, hr_str(".n; })", 6)); }));
return;
 }
if (((b_1829) == (((int64_t)3LL)))) { (void)(f260_ow(hr_str("({ hrv *_o", 10)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f325_grecv_ptr(f321_arg(((int64_t)0LL), &recv_1831, &n_1827)));
(void)(f260_ow(hr_str("; ", 2)));
L99 nmo_1862 = ({ L99 _t6023; memset(&_t6023, 0, sizeof _t6023); _t6023.n = 0; _t6023; }); 
(void)(({ L99 *_l6024 = &(nmo_1862); hrv _o6024 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6024, hr_str("_o", 2)); hr_fi(&_o6024, p_1834); if (_l6024->n + _o6024.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:670"); memcpy(_l6024->e + _l6024->n, _o6024.b, (size_t)_o6024.n); _l6024->n += _o6024.n; }));
{ int64_t _e6026 = total_1832; for (int64_t _k6026 = ((int64_t)1LL); _k6026 < _e6026; _k6026++) { int64_t i_1863 = (int64_t)_k6026; int64_t c_1864 = f321_arg(i_1863, &recv_1831, &n_1827); 
(void)(f322_gfmt(({ hsl _t6029 = ({ L99 *_t6030 = &(nmo_1862); (hsl){ (uint8_t*)_t6030->e, _t6030->n }; }); int64_t _l6029 = 0, _h6029 = _t6029.n; if (_l6029 < 0 || _h6029 < _l6029 || _h6029 > _t6029.n) hr_slerr(_l6029, _h6029, _t6029.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:670"); (hsl){ _t6029.p + _l6029 * (int64_t)sizeof(uint8_t), _h6029 - _l6029 }; }), c_1864, f279_fin(c_1864), true));
(void)(f260_ow(hr_str("; ", 2)));
 } } _bk6025:; 
(void)(f260_ow(hr_str("})", 2)));
return;
 }
if (((b_1829) == (((int64_t)4LL)))) { (void)(f260_ow(hr_str("({ if (!(", 9)));
(void)(f289_gx(f321_arg(((int64_t)0LL), &recv_1831, &n_1827)));
(void)(f260_ow(hr_str(")) hr_assert_fail(", 18)));
(void)(f312_wloc(n_1827));
(void)(f260_ow(hr_str("); })", 5)));
return;
 }
if (((b_1829) == (((int64_t)5LL)))) { (void)(f260_ow(hr_str("hr_abort(", 9)));
(void)(f291_gas(f321_arg(((int64_t)0LL), &recv_1831, &n_1827)));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((b_1829) == (((int64_t)6LL)))) { (void)(f260_ow(hr_str("hr_exit(", 8)));
(void)(f289_gx(f321_arg(((int64_t)0LL), &recv_1831, &n_1827)));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((b_1829) == (((int64_t)8LL)))) { int64_t t_1865 = f141_at(n_1827); 
(void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(t_1865));
(void)(f260_ow(hr_str(" _d", 3)));
(void)(f294_oi(p_1834));
(void)(({ hrv *_o6053 = &(g163); hr_fs(_o6053, hr_str("; memset(&_d", 12)); hr_fi(_o6053, p_1834); hr_fs(_o6053, hr_str(", 0, sizeof _d", 14)); hr_fi(_o6053, p_1834); hr_fs(_o6053, hr_str("); _d", 5)); hr_fi(_o6053, p_1834); hr_fs(_o6053, hr_str("; })", 4)); }));
return;
 }
if (((b_1829) == (((int64_t)9LL)))) { int64_t c_1866 = f321_arg(((int64_t)0LL), &recv_1831, &n_1827); 
int64_t t_1867 = f179_deref(f279_fin(c_1866)); 
if (f282_is_fix(t_1867)) { (void)(({ hrv *_o6058 = &(g163); hr_fs(_o6058, hr_str("((int64_t)", 10)); hr_fi(_o6058, ((*({ hrv *_t6059 = &(g551); int64_t _i6059 = t_1867; (S1*)_t6059->b + hr_ix(_i6059, _t6059->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:675"); }))).b_); hr_fs(_o6058, hr_str(")", 1)); }));
return;
 }
(void)(f260_ow(hr_str("(", 1)));
(void)(f291_gas(c_1866));
(void)(f260_ow(hr_str(").n", 3)));
return;
 }
if (((b_1829) == (((int64_t)7LL)))) { int64_t c_1868 = f321_arg(((int64_t)0LL), &recv_1831, &n_1827); 
int64_t t_1869 = f179_deref(f279_fin(c_1868)); 
if ((((((*({ hrv *_t6066 = &(g551); int64_t _i6066 = t_1869; (S1*)_t6066->b + hr_ix(_i6066, _t6066->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:676"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t6067 = &(g551); int64_t _i6067 = t_1869; (S1*)_t6067->b + hr_ix(_i6067, _t6067->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:676"); }))).k_) == (((uint8_t)9LL))))) { (void)(f260_ow(hr_str("hr_rfrom(", 9)));
(void)(f291_gas(c_1868));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f326_esz(((int64_t)(((*({ hrv *_t6072 = &(g551); int64_t _i6072 = t_1869; (S1*)_t6072->b + hr_ix(_i6072, _t6072->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:676"); }))).a_))));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((f279_fin(c_1868)) != (t_1869))) { (void)(f260_ow(hr_str("(*", 2)));
(void)(f289_gx(c_1868));
(void)(f260_ow(hr_str(")", 1)));
 } else { (void)(f289_gx(c_1868));
 }
return;
 }
if (((b_1829) == (((int64_t)31LL)))) { int64_t c_1871 = f321_arg(((int64_t)0LL), &recv_1831, &n_1827); 
int64_t t_1872 = f179_deref(f279_fin(c_1871)); 
if ((((((*({ hrv *_t6082 = &(g551); int64_t _i6082 = t_1872; (S1*)_t6082->b + hr_ix(_i6082, _t6082->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:677"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t6083 = &(g551); int64_t _i6083 = t_1872; (S1*)_t6083->b + hr_ix(_i6083, _t6083->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:677"); }))).k_) == (((uint8_t)9LL))))) { int64_t q_1873 = f293_nt(); 
(void)(f260_ow(hr_str("({ hsl _s", 9)));
(void)(f294_oi(q_1873));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f291_gas(c_1871));
(void)(({ hrv *_o6089 = &(g163); hr_fs(_o6089, hr_str("; (hsl){ _s", 11)); hr_fi(_o6089, q_1873); hr_fs(_o6089, hr_str(".p, _s", 6)); hr_fi(_o6089, q_1873); hr_fs(_o6089, hr_str(".n * (int64_t)sizeof(", 21)); }));
(void)(f261_ct(((int64_t)(((*({ hrv *_t6091 = &(g551); int64_t _i6091 = t_1872; (S1*)_t6091->b + hr_ix(_i6091, _t6091->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:677"); }))).a_))));
(void)(f260_ow(hr_str(") }; })", 7)));
return;
 }
(void)(f260_ow(hr_str("((hsl){ (uint8_t*)", 18)));
(void)(f324_gaddr(c_1871));
(void)(f260_ow(hr_str(", sizeof(", 9)));
(void)(f261_ct(t_1872));
(void)(f260_ow(hr_str(") })", 4)));
return;
 }
if (((b_1829) == (((int64_t)30LL)))) { int64_t c_1874 = f321_arg(((int64_t)0LL), &recv_1831, &n_1827); 
int64_t t_1875 = f179_deref(f279_fin(c_1874)); 
(void)(f260_ow(hr_str("hr_rfrom(", 9)));
if ((((((*({ hrv *_t6102 = &(g551); int64_t _i6102 = t_1875; (S1*)_t6102->b + hr_ix(_i6102, _t6102->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:678"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t6103 = &(g551); int64_t _i6103 = t_1875; (S1*)_t6103->b + hr_ix(_i6103, _t6103->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:678"); }))).k_) == (((uint8_t)9LL))))) { int64_t q_1876 = f293_nt(); 
(void)(f260_ow(hr_str("({ hsl _s", 9)));
(void)(f294_oi(q_1876));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f291_gas(c_1874));
(void)(({ hrv *_o6109 = &(g163); hr_fs(_o6109, hr_str("; (hsl){ _s", 11)); hr_fi(_o6109, q_1876); hr_fs(_o6109, hr_str(".p, _s", 6)); hr_fi(_o6109, q_1876); hr_fs(_o6109, hr_str(".n * (int64_t)sizeof(", 21)); }));
(void)(f261_ct(((int64_t)(((*({ hrv *_t6111 = &(g551); int64_t _i6111 = t_1875; (S1*)_t6111->b + hr_ix(_i6111, _t6111->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:678"); }))).a_))));
(void)(f260_ow(hr_str(") }; })", 7)));
 } else { (void)(f260_ow(hr_str("((hsl){ (uint8_t*)", 18)));
(void)(f324_gaddr(c_1874));
(void)(f260_ow(hr_str(", sizeof(", 9)));
(void)(f261_ct(t_1875));
(void)(f260_ow(hr_str(") })", 4)));
 }
(void)(f260_ow(hr_str(", 1)", 4)));
return;
 }
if (((b_1829) == (((int64_t)33LL)))) { (void)(f327_gembed(n_1827, f321_arg(((int64_t)0LL), &recv_1831, &n_1827)));
return;
 }
if (((b_1829) == (((int64_t)32LL)))) { int64_t t_1885 = f141_at(n_1827); 
(void)(f260_ow(hr_str("({ hsl _s", 9)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f291_gas(f321_arg(((int64_t)0LL), &recv_1831, &n_1827)));
(void)(f260_ow(hr_str("; ", 2)));
(void)(f261_ct(t_1885));
(void)(({ hrv *_o6129 = &(g163); hr_fs(_o6129, hr_str(" _d", 3)); hr_fi(_o6129, p_1834); hr_fs(_o6129, hr_str("; if (_s", 8)); hr_fi(_o6129, p_1834); hr_fs(_o6129, hr_str(".n != sizeof _d", 15)); hr_fi(_o6129, p_1834); hr_fs(_o6129, hr_str(") hr_die(\"from_bytes: wrong byte count\", ", 41)); }));
(void)(f312_wloc(n_1827));
(void)(({ hrv *_o6131 = &(g163); hr_fs(_o6131, hr_str("); memcpy(&_d", 13)); hr_fi(_o6131, p_1834); hr_fs(_o6131, hr_str(", _s", 4)); hr_fi(_o6131, p_1834); hr_fs(_o6131, hr_str(".p, sizeof _d", 13)); hr_fi(_o6131, p_1834); hr_fs(_o6131, hr_str("); _d", 5)); hr_fi(_o6131, p_1834); hr_fs(_o6131, hr_str("; })", 4)); }));
return;
 }
if (((recv_1831) < (((int64_t)0LL)))) { (void)(f287_gerr(n_1827, hr_str("unsupported builtin call", 24)));
return;
 }
int64_t rt_1886 = f179_deref(f141_at(recv_1831)); 
int64_t e_1887 = ((int64_t)(((*({ hrv *_t6135 = &(g551); int64_t _i6135 = rt_1886; (S1*)_t6135->b + hr_ix(_i6135, _t6135->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:683"); }))).a_)); 
if (f283_is_lim(rt_1886)) { (void)(f260_ow(hr_str("({ ", 3)));
(void)(f261_ct(rt_1886));
(void)(f260_ow(hr_str(" *_v", 4)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f325_grecv_ptr(recv_1831));
(void)(f260_ow(hr_str("; ", 2)));
if (((b_1829) == (((int64_t)20LL)))) { (void)(f261_ct(e_1887));
(void)(f260_ow(hr_str(" _x", 3)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1831, &n_1827)));
(void)(({ hrv *_o6150 = &(g163); hr_fs(_o6150, hr_str("; if (_v", 8)); hr_fi(_o6150, p_1834); hr_fs(_o6150, hr_str("->n >= ", 7)); hr_fi(_o6150, ((*({ hrv *_t6151 = &(g551); int64_t _i6151 = rt_1886; (S1*)_t6151->b + hr_ix(_i6151, _t6151->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:686"); }))).b_); hr_fs(_o6150, hr_str(") hr_die(\"push past a limited array's capacity\", ", 49)); }));
(void)(f312_wloc(n_1827));
(void)(({ hrv *_o6153 = &(g163); hr_fs(_o6153, hr_str("); _v", 5)); hr_fi(_o6153, p_1834); hr_fs(_o6153, hr_str("->e[_v", 6)); hr_fi(_o6153, p_1834); hr_fs(_o6153, hr_str("->n] = _x", 9)); hr_fi(_o6153, p_1834); hr_fs(_o6153, hr_str("; &_v", 5)); hr_fi(_o6153, p_1834); hr_fs(_o6153, hr_str("->e[_v", 6)); hr_fi(_o6153, p_1834); hr_fs(_o6153, hr_str("->n++]; })", 10)); }));
return;
 }
if (((b_1829) == (((int64_t)21LL)))) { (void)(({ hrv *_o6154 = &(g163); hr_fs(_o6154, hr_str("hsl _s", 6)); hr_fi(_o6154, p_1834); hr_fs(_o6154, hr_str(" = ", 3)); }));
(void)(f291_gas(f321_arg(((int64_t)1LL), &recv_1831, &n_1827)));
(void)(({ hrv *_o6157 = &(g163); hr_fs(_o6157, hr_str("; if (_v", 8)); hr_fi(_o6157, p_1834); hr_fs(_o6157, hr_str("->n + _s", 8)); hr_fi(_o6157, p_1834); hr_fs(_o6157, hr_str(".n > ", 5)); hr_fi(_o6157, ((*({ hrv *_t6158 = &(g551); int64_t _i6158 = rt_1886; (S1*)_t6158->b + hr_ix(_i6158, _t6158->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:687"); }))).b_); hr_fs(_o6157, hr_str(") hr_die(\"append past a limited array's capacity\", ", 51)); }));
(void)(f312_wloc(n_1827));
(void)(({ hrv *_o6160 = &(g163); hr_fs(_o6160, hr_str("); memmove(_v", 13)); hr_fi(_o6160, p_1834); hr_fs(_o6160, hr_str("->e + _v", 8)); hr_fi(_o6160, p_1834); hr_fs(_o6160, hr_str("->n, _s", 7)); hr_fi(_o6160, p_1834); hr_fs(_o6160, hr_str(".p, (size_t)_s", 14)); hr_fi(_o6160, p_1834); hr_fs(_o6160, hr_str(".n * sizeof _v", 14)); hr_fi(_o6160, p_1834); hr_fs(_o6160, hr_str("->e[0]); _v", 11)); hr_fi(_o6160, p_1834); hr_fs(_o6160, hr_str("->n += _s", 9)); hr_fi(_o6160, p_1834); hr_fs(_o6160, hr_str(".n; })", 6)); }));
return;
 }
if (((b_1829) == (((int64_t)22LL)))) { (void)(({ hrv *_o6161 = &(g163); hr_fs(_o6161, hr_str("if (!_v", 7)); hr_fi(_o6161, p_1834); hr_fs(_o6161, hr_str("->n) hr_die(\"pop of an empty array\", ", 37)); }));
(void)(f312_wloc(n_1827));
(void)(({ hrv *_o6163 = &(g163); hr_fs(_o6163, hr_str("); _v", 5)); hr_fi(_o6163, p_1834); hr_fs(_o6163, hr_str("->e[--_v", 8)); hr_fi(_o6163, p_1834); hr_fs(_o6163, hr_str("->n]; })", 8)); }));
return;
 }
if (((b_1829) == (((int64_t)23LL)))) { (void)(({ hrv *_o6164 = &(g163); hr_fs(_o6164, hr_str("int64_t _k", 10)); hr_fi(_o6164, p_1834); hr_fs(_o6164, hr_str(" = ", 3)); }));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1831, &n_1827)));
(void)(({ hrv *_o6167 = &(g163); hr_fs(_o6167, hr_str("; if (_k", 8)); hr_fi(_o6167, p_1834); hr_fs(_o6167, hr_str(" < 0 || _k", 10)); hr_fi(_o6167, p_1834); hr_fs(_o6167, hr_str(" > _v", 5)); hr_fi(_o6167, p_1834); hr_fs(_o6167, hr_str("->n) hr_die(\"pop_n past the length\", ", 37)); }));
(void)(f312_wloc(n_1827));
(void)(({ hrv *_o6169 = &(g163); hr_fs(_o6169, hr_str("); _v", 5)); hr_fi(_o6169, p_1834); hr_fs(_o6169, hr_str("->n -= _k", 9)); hr_fi(_o6169, p_1834); hr_fs(_o6169, hr_str("; })", 4)); }));
return;
 }
if (((b_1829) == (((int64_t)25LL)))) { (void)(({ hrv *_o6170 = &(g163); hr_fs(_o6170, hr_str("_v", 2)); hr_fi(_o6170, p_1834); hr_fs(_o6170, hr_str("->n = 0; })", 11)); }));
return;
 }
if (((b_1829) == (((int64_t)24LL)))) { (void)(({ hrv *_o6171 = &(g163); hr_fs(_o6171, hr_str("int64_t _k", 10)); hr_fi(_o6171, p_1834); hr_fs(_o6171, hr_str(" = ", 3)); }));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1831, &n_1827)));
(void)(({ hrv *_o6174 = &(g163); hr_fs(_o6174, hr_str("; if (_k", 8)); hr_fi(_o6174, p_1834); hr_fs(_o6174, hr_str(" < 0 || _k", 10)); hr_fi(_o6174, p_1834); hr_fs(_o6174, hr_str(" > ", 3)); hr_fi(_o6174, ((*({ hrv *_t6175 = &(g551); int64_t _i6175 = rt_1886; (S1*)_t6175->b + hr_ix(_i6175, _t6175->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:691"); }))).b_); hr_fs(_o6174, hr_str(") hr_die(\"resize past a limited array's capacity\", ", 51)); }));
(void)(f312_wloc(n_1827));
(void)(({ hrv *_o6177 = &(g163); hr_fs(_o6177, hr_str("); for (int64_t _j = _v", 23)); hr_fi(_o6177, p_1834); hr_fs(_o6177, hr_str("->n; _j < _k", 12)); hr_fi(_o6177, p_1834); hr_fs(_o6177, hr_str("; _j++) memset(&_v", 18)); hr_fi(_o6177, p_1834); hr_fs(_o6177, hr_str("->e[_j], 0, sizeof _v", 21)); hr_fi(_o6177, p_1834); hr_fs(_o6177, hr_str("->e[0]); ", 9)); }));
if (((total_1832) > (((int64_t)2LL)))) { (void)(({ hrv *_o6178 = &(g163); hr_fs(_o6178, hr_str("for (int64_t _j = _v", 20)); hr_fi(_o6178, p_1834); hr_fs(_o6178, hr_str("->n; _j < _k", 12)); hr_fi(_o6178, p_1834); hr_fs(_o6178, hr_str("; _j++) _v", 10)); hr_fi(_o6178, p_1834); hr_fs(_o6178, hr_str("->e[_j] = ", 10)); }));
(void)(f289_gx(f321_arg(((int64_t)2LL), &recv_1831, &n_1827)));
(void)(f260_ow(hr_str("; ", 2)));
 }
(void)(({ hrv *_o6182 = &(g163); hr_fs(_o6182, hr_str("_v", 2)); hr_fi(_o6182, p_1834); hr_fs(_o6182, hr_str("->n = _k", 8)); hr_fi(_o6182, p_1834); hr_fs(_o6182, hr_str("; })", 4)); }));
return;
 }
if (((b_1829) == (((int64_t)26LL)))) { (void)(f261_ct(e_1887));
(void)(f260_ow(hr_str(" _x", 3)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1831, &n_1827)));
(void)(({ hrv *_o6189 = &(g163); hr_fs(_o6189, hr_str("; int64_t _r", 12)); hr_fi(_o6189, p_1834); hr_fs(_o6189, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6189, p_1834); hr_fs(_o6189, hr_str("->n; _j++) if (", 15)); }));
(void)(f328_heq_val_o(e_1887, p_1834));
(void)(({ hrv *_o6191 = &(g163); hr_fs(_o6191, hr_str(") { _r", 6)); hr_fi(_o6191, p_1834); hr_fs(_o6191, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6191, p_1834); hr_fs(_o6191, hr_str("; })", 4)); }));
return;
 }
(void)(f287_gerr(n_1827, hr_str("unsupported limited-array operation", 35)));
return;
 }
if ((((((*({ hrv *_t6193 = &(g551); int64_t _i6193 = rt_1886; (S1*)_t6193->b + hr_ix(_i6193, _t6193->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:695"); }))).k_) == (((uint8_t)9LL))) || f282_is_fix(rt_1886))) { if (((b_1829) == (((int64_t)26LL)))) { (void)(f260_ow(hr_str("({ hsl _v", 9)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f291_gas(recv_1831));
(void)(f260_ow(hr_str("; ", 2)));
(void)(f261_ct(e_1887));
(void)(f260_ow(hr_str(" _x", 3)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1831, &n_1827)));
(void)(({ hrv *_o6206 = &(g163); hr_fs(_o6206, hr_str("; int64_t _r", 12)); hr_fi(_o6206, p_1834); hr_fs(_o6206, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6206, p_1834); hr_fs(_o6206, hr_str(".n; _j++) if (", 14)); }));
(void)(f332_heq_val_s(e_1887, p_1834));
(void)(({ hrv *_o6208 = &(g163); hr_fs(_o6208, hr_str(") { _r", 6)); hr_fi(_o6208, p_1834); hr_fs(_o6208, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6208, p_1834); hr_fs(_o6208, hr_str("; })", 4)); }));
return;
 }
(void)(f287_gerr(n_1827, hr_str("this operation needs a resizable array", 38)));
return;
 }
(void)(f260_ow(hr_str("({ hrv *_v", 10)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f325_grecv_ptr(recv_1831));
(void)(f260_ow(hr_str("; ", 2)));
if (((b_1829) == (((int64_t)20LL)))) { (void)(f261_ct(e_1887));
(void)(f260_ow(hr_str(" _x", 3)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1831, &n_1827)));
(void)(f260_ow(hr_str("; ", 2)));
(void)(f261_ct(e_1887));
(void)(f260_ow(hr_str(" *_p", 4)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" = (", 4)));
(void)(f261_ct(e_1887));
(void)(({ hrv *_o6227 = &(g163); hr_fs(_o6227, hr_str("*)hr_grow(_v", 12)); hr_fi(_o6227, p_1834); hr_fs(_o6227, hr_str(", 1, sizeof _x", 14)); hr_fi(_o6227, p_1834); hr_fs(_o6227, hr_str("); *_p", 6)); hr_fi(_o6227, p_1834); hr_fs(_o6227, hr_str(" = _x", 5)); hr_fi(_o6227, p_1834); hr_fs(_o6227, hr_str("; _p", 4)); hr_fi(_o6227, p_1834); hr_fs(_o6227, hr_str("; })", 4)); }));
return;
 }
if (((b_1829) == (((int64_t)21LL)))) { (void)(({ hrv *_o6228 = &(g163); hr_fs(_o6228, hr_str("hsl _s", 6)); hr_fi(_o6228, p_1834); hr_fs(_o6228, hr_str(" = ", 3)); }));
(void)(f291_gas(f321_arg(((int64_t)1LL), &recv_1831, &n_1827)));
(void)(({ hrv *_o6231 = &(g163); hr_fs(_o6231, hr_str("; hr_append(_v", 14)); hr_fi(_o6231, p_1834); hr_fs(_o6231, hr_str(", _s", 4)); hr_fi(_o6231, p_1834); hr_fs(_o6231, hr_str(".p, _s", 6)); hr_fi(_o6231, p_1834); hr_fs(_o6231, hr_str(".n, sizeof(", 11)); }));
(void)(f261_ct(e_1887));
(void)(f260_ow(hr_str(")); })", 6)));
return;
 }
if (((b_1829) == (((int64_t)22LL)))) { (void)(({ hrv *_o6234 = &(g163); hr_fs(_o6234, hr_str("if (!_v", 7)); hr_fi(_o6234, p_1834); hr_fs(_o6234, hr_str("->n) hr_die(\"pop of an empty array\", ", 37)); }));
(void)(f312_wloc(n_1827));
(void)(({ hrv *_o6236 = &(g163); hr_fs(_o6236, hr_str("); ((", 5)); }));
(void)(f261_ct(e_1887));
(void)(({ hrv *_o6238 = &(g163); hr_fs(_o6238, hr_str("*)_v", 4)); hr_fi(_o6238, p_1834); hr_fs(_o6238, hr_str("->b)[--_v", 9)); hr_fi(_o6238, p_1834); hr_fs(_o6238, hr_str("->n]; })", 8)); }));
return;
 }
if (((b_1829) == (((int64_t)23LL)))) { (void)(({ hrv *_o6239 = &(g163); hr_fs(_o6239, hr_str("int64_t _k", 10)); hr_fi(_o6239, p_1834); hr_fs(_o6239, hr_str(" = ", 3)); }));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1831, &n_1827)));
(void)(({ hrv *_o6242 = &(g163); hr_fs(_o6242, hr_str("; if (_k", 8)); hr_fi(_o6242, p_1834); hr_fs(_o6242, hr_str(" < 0 || _k", 10)); hr_fi(_o6242, p_1834); hr_fs(_o6242, hr_str(" > _v", 5)); hr_fi(_o6242, p_1834); hr_fs(_o6242, hr_str("->n) hr_die(\"pop_n past the length\", ", 37)); }));
(void)(f312_wloc(n_1827));
(void)(({ hrv *_o6244 = &(g163); hr_fs(_o6244, hr_str("); _v", 5)); hr_fi(_o6244, p_1834); hr_fs(_o6244, hr_str("->n -= _k", 9)); hr_fi(_o6244, p_1834); hr_fs(_o6244, hr_str("; })", 4)); }));
return;
 }
if (((b_1829) == (((int64_t)25LL)))) { (void)(({ hrv *_o6245 = &(g163); hr_fs(_o6245, hr_str("_v", 2)); hr_fi(_o6245, p_1834); hr_fs(_o6245, hr_str("->n = 0; })", 11)); }));
return;
 }
if (((b_1829) == (((int64_t)24LL)))) { (void)(({ hrv *_o6246 = &(g163); hr_fs(_o6246, hr_str("int64_t _k", 10)); hr_fi(_o6246, p_1834); hr_fs(_o6246, hr_str(" = ", 3)); }));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1831, &n_1827)));
(void)(({ hrv *_o6249 = &(g163); hr_fs(_o6249, hr_str("; if (_k", 8)); hr_fi(_o6249, p_1834); hr_fs(_o6249, hr_str(" < 0) hr_die(\"resize to a negative length\", ", 44)); }));
(void)(f312_wloc(n_1827));
(void)(f260_ow(hr_str("); ", 3)));
if (((total_1832) > (((int64_t)2LL)))) { (void)(f261_ct(e_1887));
(void)(f260_ow(hr_str(" _x", 3)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f321_arg(((int64_t)2LL), &recv_1831, &n_1827)));
(void)(({ hrv *_o6258 = &(g163); hr_fs(_o6258, hr_str("; int64_t _o", 12)); hr_fi(_o6258, p_1834); hr_fs(_o6258, hr_str(" = _v", 5)); hr_fi(_o6258, p_1834); hr_fs(_o6258, hr_str("->n; hr_resize(_v", 17)); hr_fi(_o6258, p_1834); hr_fs(_o6258, hr_str(", _k", 4)); hr_fi(_o6258, p_1834); hr_fs(_o6258, hr_str(", sizeof _x", 11)); hr_fi(_o6258, p_1834); hr_fs(_o6258, hr_str("); for (int64_t _j = _o", 23)); hr_fi(_o6258, p_1834); hr_fs(_o6258, hr_str("; _j < _k", 9)); hr_fi(_o6258, p_1834); hr_fs(_o6258, hr_str("; _j++) ((", 10)); }));
(void)(f261_ct(e_1887));
(void)(({ hrv *_o6260 = &(g163); hr_fs(_o6260, hr_str("*)_v", 4)); hr_fi(_o6260, p_1834); hr_fs(_o6260, hr_str("->b)[_j] = _x", 13)); hr_fi(_o6260, p_1834); hr_fs(_o6260, hr_str("; })", 4)); }));
return;
 }
(void)(({ hrv *_o6261 = &(g163); hr_fs(_o6261, hr_str("hr_resize(_v", 12)); hr_fi(_o6261, p_1834); hr_fs(_o6261, hr_str(", _k", 4)); hr_fi(_o6261, p_1834); hr_fs(_o6261, hr_str(", sizeof(", 9)); }));
(void)(f261_ct(e_1887));
(void)(f260_ow(hr_str(")); })", 6)));
return;
 }
if (((b_1829) == (((int64_t)26LL)))) { (void)(f261_ct(e_1887));
(void)(f260_ow(hr_str(" _x", 3)));
(void)(f294_oi(p_1834));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f321_arg(((int64_t)1LL), &recv_1831, &n_1827)));
(void)(({ hrv *_o6270 = &(g163); hr_fs(_o6270, hr_str("; int64_t _r", 12)); hr_fi(_o6270, p_1834); hr_fs(_o6270, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6270, p_1834); hr_fs(_o6270, hr_str("->n; _j++) if (", 15)); }));
(void)(f333_heq_val_r(e_1887, p_1834));
(void)(({ hrv *_o6272 = &(g163); hr_fs(_o6272, hr_str(") { _r", 6)); hr_fi(_o6272, p_1834); hr_fs(_o6272, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6272, p_1834); hr_fs(_o6272, hr_str("; })", 4)); }));
return;
 }
(void)(f287_gerr(n_1827, hr_str("unsupported array operation", 27)));
}
static int64_t f321_arg(int64_t i_1833, int64_t *c1831, int64_t *c1827) {
return ({ int64_t _r6274; if ((((*c1831)) >= (((int64_t)0LL)))) { _r6274 = ({ int64_t _r6275; if (((i_1833) == (((int64_t)0LL)))) { _r6275 = (*c1831);  } else { _r6275 = f90_kid((*c1827), ((int64_t)((int64_t)i_1833 - (int64_t)((int64_t)1LL))));  } _r6275; });  } else { _r6274 = f90_kid((*c1827), i_1833);  } _r6274; });
}
static void f322_gfmt(hsl o_1837, int64_t n_1838, int64_t t_1839, bool top_1840) {
int64_t d_1841 = f179_deref(t_1839); 
int64_t k_1842 = ((int64_t)(((*({ hrv *_t6279 = &(g551); int64_t _i6279 = d_1841; (S1*)_t6279->b + hr_ix(_i6279, _t6279->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:375"); }))).k_)); 
int64_t hk_1843 = ({ int64_t _r6280; if (((d_1841) < ((g349).n))) { _r6280 = ((int64_t)((*({ hrv *_t6281 = &(g349); int64_t _i6281 = d_1841; (int32_t*)_t6281->b + hr_ix(_i6281, _t6281->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:376"); }))));  } else { _r6280 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r6280; }); 
if ((((hk_1843) >= (((int64_t)0LL))) && ((f179_deref(f208_ptype_of(hk_1843, ((int64_t)1LL)))) == (d_1841)))) { int64_t pt_1844 = f208_ptype_of(hk_1843, ((int64_t)1LL)); 
(void)(f323_fn_cname(hk_1843));
(void)(f260_ow(hr_str("(", 1)));
(void)(f260_ow(o_1837));
(void)(f260_ow(hr_str(", ", 2)));
if (((((*({ hrv *_t6289 = &(g551); int64_t _i6289 = pt_1844; (S1*)_t6289->b + hr_ix(_i6289, _t6289->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:380"); }))).k_) == (((uint8_t)10LL)))) { if (((((*({ hrv *_t6290 = &(g551); int64_t _i6290 = t_1839; (S1*)_t6290->b + hr_ix(_i6290, _t6290->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:380"); }))).k_) == (((uint8_t)10LL)))) { (void)(f289_gx(n_1838));
 } else { (void)(f324_gaddr(n_1838));
 }
 } else { if (((((*({ hrv *_t6293 = &(g551); int64_t _i6293 = t_1839; (S1*)_t6293->b + hr_ix(_i6293, _t6293->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:380"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_ow(hr_str("*", 1)));
 }
(void)(f289_gx(n_1838));
 }
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if ((((k_1842) == (((int64_t)18LL))) || f164_is_byte_arr(d_1841))) { if (top_1840) { (void)(f260_ow(hr_str("hr_fs(", 6)));
 } else { (void)(f260_ow(hr_str("hr_fq(", 6)));
 }
(void)(f260_ow(o_1837));
(void)(f260_ow(hr_str(", ", 2)));
if (((((*({ hrv *_t6302 = &(g551); int64_t _i6302 = f141_at(n_1838); (S1*)_t6302->b + hr_ix(_i6302, _t6302->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:384"); }))).k_) == (((uint8_t)18LL)))) { (void)(f289_gx(n_1838));
 } else { (void)(f291_gas(n_1838));
 }
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((k_1842) == (((int64_t)3LL)))) { (void)(f260_ow(({ hsl _r6308; if (f153_is_signed(d_1841)) { _r6308 = hr_str("hr_fi(", 6);  } else { _r6308 = hr_str("hr_fu(", 6);  } _r6308; })));
(void)(f260_ow(o_1837));
(void)(f260_ow(hr_str(", ", 2)));
if (((d_1841) != (t_1839))) { (void)(f260_ow(hr_str("*", 1)));
 }
(void)(f289_gx(n_1838));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((k_1842) == (((int64_t)12LL)))) { (void)(f260_ow(hr_str("hr_fi(", 6)));
(void)(f260_ow(o_1837));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f289_gx(n_1838));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((k_1842) == (((int64_t)4LL)))) { (void)(f260_ow(({ hsl _r6321; if (((((*({ hrv *_t6322 = &(g551); int64_t _i6322 = d_1841; (S1*)_t6322->b + hr_ix(_i6322, _t6322->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:387"); }))).s_) == (((uint8_t)4LL)))) { _r6321 = hr_str("hr_ff(", 6);  } else { _r6321 = hr_str("hr_fd(", 6);  } _r6321; })));
(void)(f260_ow(o_1837));
(void)(f260_ow(hr_str(", ", 2)));
if (((d_1841) != (t_1839))) { (void)(f260_ow(hr_str("*", 1)));
 }
(void)(f289_gx(n_1838));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((k_1842) == (((int64_t)13LL)))) { (void)(f260_ow(hr_str("hr_fd(", 6)));
(void)(f260_ow(o_1837));
(void)(f260_ow(hr_str(", ", 2)));
(void)(f289_gx(n_1838));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
if (((k_1842) == (((int64_t)2LL)))) { (void)(f260_ow(hr_str("hr_fc(", 6)));
(void)(f260_ow(o_1837));
(void)(f260_ow(hr_str(", (", 3)));
if (((d_1841) != (t_1839))) { (void)(f260_ow(hr_str("*", 1)));
 }
(void)(f289_gx(n_1838));
(void)(f260_ow(hr_str(") \077 \"true\" : \"false\")", 21)));
return;
 }
(void)(f260_ow(hr_str("hf", 2)));
(void)(f294_oi(d_1841));
(void)(f260_ow(hr_str("(", 1)));
(void)(f260_ow(o_1837));
(void)(f260_ow(hr_str(", ", 2)));
if (((d_1841) != (t_1839))) { (void)(f260_ow(hr_str("*", 1)));
 }
if ((((((k_1842) == (((int64_t)8LL))) && (!(f282_is_fix(d_1841)))) && (!(f283_is_lim(d_1841)))) || ((k_1842) == (((int64_t)9LL))))) { (void)(f292_gsl(n_1838, t_1839));
 } else { (void)(f289_gx(n_1838));
 }
(void)(f260_ow(hr_str(")", 1)));
(void)(f299_gen_hf(d_1841));
}
static void f323_fn_cname(int64_t i_1845) {
(void)(f302_fn_cname_to((&(g163)), i_1845));
}
static void f324_gaddr(int64_t n_1846) {
if (f272_is_place(n_1846)) { (void)(f260_ow(hr_str("(&(", 3)));
(void)(f275_gx0(n_1846));
(void)(f260_ow(hr_str("))", 2)));
return;
 }
int64_t t_1847 = f141_at(n_1846); 
int64_t c_1848 = f150_cv(n_1846); 
if (((((c_1848) >= (((int64_t)0LL))) && ((((*({ hrv *_t6358 = &(g551); int64_t _i6358 = c_1848; (S1*)_t6358->b + hr_ix(_i6358, _t6358->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:167"); }))).k_) == (((uint8_t)10LL)))) && ((((*({ hrv *_t6359 = &(g551); int64_t _i6359 = t_1847; (S1*)_t6359->b + hr_ix(_i6359, _t6359->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:167"); }))).k_) != (((uint8_t)10LL))))) { int64_t pt_1849 = ((int64_t)(((*({ hrv *_t6360 = &(g551); int64_t _i6360 = c_1848; (S1*)_t6360->b + hr_ix(_i6360, _t6360->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:168"); }))).a_)); 
int64_t k_1850 = f273_tmp(pt_1849, f268_is_res(pt_1849)); 
(void)(f260_ow(hr_str("(", 1)));
(void)(f274_ot(k_1850));
(void)(f260_ow(hr_str(" = (", 4)));
if (((pt_1849) == (t_1847))) { if (f268_is_res(t_1847)) { (void)(f275_gx0(n_1846));
 } else { (void)(f271_gx1(n_1846));
 }
 } else { (void)(f270_gcv(n_1846, t_1847, pt_1849));
 }
(void)(f260_ow(hr_str("), &", 4)));
(void)(f274_ot(k_1850));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
int64_t k_1851 = f273_tmp(t_1847, f268_is_res(t_1847)); 
(void)(f260_ow(hr_str("(", 1)));
(void)(f274_ot(k_1851));
(void)(f260_ow(hr_str(" = (", 4)));
(void)(f269_gxo(n_1846));
(void)(f260_ow(hr_str("), &", 4)));
(void)(f274_ot(k_1851));
(void)(f260_ow(hr_str(")", 1)));
}
static void f325_grecv_ptr(int64_t r_1856) {
int64_t t_1857 = f141_at(r_1856); 
if (((((*({ hrv *_t6383 = &(g551); int64_t _i6383 = t_1857; (S1*)_t6383->b + hr_ix(_i6383, _t6383->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:648"); }))).k_) == (((uint8_t)10LL)))) { (void)(f275_gx0(r_1856));
return;
 }
if (f272_is_place(r_1856)) { (void)(f260_ow(hr_str("&(", 2)));
(void)(f275_gx0(r_1856));
(void)(f260_ow(hr_str(")", 1)));
return;
 }
int64_t k_1858 = f273_tmp(t_1857, f268_is_res(t_1857)); 
(void)(f260_ow(hr_str("(", 1)));
(void)(f274_ot(k_1858));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f269_gxo(r_1856));
(void)(f260_ow(hr_str(", &", 3)));
(void)(f274_ot(k_1858));
(void)(f260_ow(hr_str(")", 1)));
}
static void f326_esz(int64_t t_1870) {
(void)(f260_ow(hr_str("sizeof(", 7)));
(void)(f261_ct(t_1870));
(void)(f260_ow(hr_str(")", 1)));
}
static void f327_gembed(int64_t n_1877, int64_t a_1878) {
if (((((*({ hrv *_t6401 = &(g704); int64_t _i6401 = a_1878; (S4*)_t6401->b + hr_ix(_i6401, _t6401->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:714"); }))).k_) != (((uint8_t)3LL)))) { (void)(f287_gerr(n_1877, hr_str("embed_file needs a string literal path", 38)));
return;
 }
int64_t f_1879 = ((int64_t)(((*({ hrv *_t6403 = &(g913); int64_t _i6403 = ((*({ hrv *_t6404 = &(g914); int64_t _i6404 = ((*({ hrv *_t6405 = &(g704); int64_t _i6405 = n_1877; (S4*)_t6405->b + hr_ix(_i6405, _t6405->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:715"); }))).t_; (S3*)_t6404->b + hr_ix(_i6404, _t6404->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:715"); }))).f_; (S2*)_t6403->b + hr_ix(_i6403, _t6403->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:715"); }))).name_)); 
L101 p_1880 = ({ L101 _t6406; memset(&_t6406, 0, sizeof _t6406); _t6406.n = 0; _t6406; }); 
int64_t sl_1881 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hsl _v6408 = f10_nm(f_1879); for (int64_t _k6408 = 0; _k6408 < _v6408.n; _k6408++) { uint8_t c_1882 = ((uint8_t*)_v6408.p)[_k6408]; int64_t i_1883 = (int64_t)_k6408; if (((c_1882) == (((uint8_t)47LL)))) { sl_1881 = i_1883;
 }
 } } _bk6407:; 
if (((sl_1881) >= (((int64_t)0LL)))) { (void)(({ L101 *_v6410 = &(p_1880); hsl _s6410 = ({ hsl _t6411 = f10_nm(f_1879); int64_t _l6411 = 0, _h6411 = ((int64_t)((int64_t)sl_1881 + (int64_t)((int64_t)1LL))); if (_l6411 < 0 || _h6411 < _l6411 || _h6411 > _t6411.n) hr_slerr(_l6411, _h6411, _t6411.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:719"); (hsl){ _t6411.p + _l6411 * (int64_t)sizeof(uint8_t), _h6411 - _l6411 }; }); if (_v6410->n + _s6410.n > 4096) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:719"); memmove(_v6410->e + _v6410->n, _s6410.p, (size_t)_s6410.n * sizeof _v6410->e[0]); _v6410->n += _s6410.n; }));
 }
(void)(({ L101 *_v6413 = &(p_1880); hsl _s6413 = f280_tok_str(((int64_t)(((*({ hrv *_t6415 = &(g704); int64_t _i6415 = a_1878; (S4*)_t6415->b + hr_ix(_i6415, _t6415->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:720"); }))).t_))); if (_v6413->n + _s6413.n > 4096) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:720"); memmove(_v6413->e + _v6413->n, _s6413.p, (size_t)_s6413.n * sizeof _v6413->e[0]); _v6413->n += _s6413.n; }));
hrv emb_1884 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(hr_os_read_file(({ hsl _t6418 = ({ L101 *_t6419 = &(p_1880); (hsl){ (uint8_t*)_t6419->e, _t6419->n }; }); int64_t _l6418 = 0, _h6418 = _t6418.n; if (_l6418 < 0 || _h6418 < _l6418 || _h6418 > _t6418.n) hr_slerr(_l6418, _h6418, _t6418.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:722"); (hsl){ _t6418.p + _l6418 * (int64_t)sizeof(uint8_t), _h6418 - _l6418 }; }), (&(emb_1884)))))) { (void)(f287_gerr(n_1877, hr_str("embed_file cannot read its file", 31)));
return;
 }
(void)(f260_ow(hr_str("hr_str(", 7)));
(void)(f281_cstr_lit(({ hsl _t6423 = hr_sl(emb_1884); int64_t _l6423 = 0, _h6423 = _t6423.n; if (_l6423 < 0 || _h6423 < _l6423 || _h6423 > _t6423.n) hr_slerr(_l6423, _h6423, _t6423.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:723"); (hsl){ _t6423.p + _l6423 * (int64_t)sizeof(uint8_t), _h6423 - _l6423 }; })));
(void)(({ hrv *_o6424 = &(g163); hr_fs(_o6424, hr_str(", ", 2)); hr_fi(_o6424, (emb_1884).n); hr_fs(_o6424, hr_str(")", 1)); }));
}
static void f328_heq_val_o(int64_t e_1888, int64_t p_1889) {
L100 a_1890 = ({ L100 _t6425; memset(&_t6425, 0, sizeof _t6425); _t6425.n = 0; _t6425; }); 
L100 b_1891 = ({ L100 _t6426; memset(&_t6426, 0, sizeof _t6426); _t6426.n = 0; _t6426; }); 
(void)(({ L100 *_l6427 = &(a_1890); hrv _o6427 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6427, hr_str("_v", 2)); hr_fi(&_o6427, p_1889); hr_fs(&_o6427, hr_str("->e[_j]", 7)); if (_l6427->n + _o6427.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:728"); memcpy(_l6427->e + _l6427->n, _o6427.b, (size_t)_o6427.n); _l6427->n += _o6427.n; }));
(void)(({ L100 *_l6428 = &(b_1891); hrv _o6428 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6428, hr_str("_x", 2)); hr_fi(&_o6428, p_1889); if (_l6428->n + _o6428.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:728"); memcpy(_l6428->e + _l6428->n, _o6428.b, (size_t)_o6428.n); _l6428->n += _o6428.n; }));
(void)(f329_heq_o(e_1888, ({ hsl _t6430 = ({ L100 *_t6431 = &(a_1890); (hsl){ (uint8_t*)_t6431->e, _t6431->n }; }); int64_t _l6430 = 0, _h6430 = _t6430.n; if (_l6430 < 0 || _h6430 < _l6430 || _h6430 > _t6430.n) hr_slerr(_l6430, _h6430, _t6430.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:728"); (hsl){ _t6430.p + _l6430 * (int64_t)sizeof(uint8_t), _h6430 - _l6430 }; }), ({ hsl _t6432 = ({ L100 *_t6433 = &(b_1891); (hsl){ (uint8_t*)_t6433->e, _t6433->n }; }); int64_t _l6432 = 0, _h6432 = _t6432.n; if (_l6432 < 0 || _h6432 < _l6432 || _h6432 > _t6432.n) hr_slerr(_l6432, _h6432, _t6432.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:728"); (hsl){ _t6432.p + _l6432 * (int64_t)sizeof(uint8_t), _h6432 - _l6432 }; })));
}
static void f329_heq_o(int64_t e_1892, hsl a_1893, hsl b_1894) {
(void)(f330_heq_pre(e_1892));
int64_t s0_1898 = (g169).n; 
(void)(f304_heq_val(e_1892, a_1893, b_1894));
(void)(({ hrv *_v6436 = &(g163); hsl _s6436 = ({ hsl _t6437 = hr_sl(g169); int64_t _l6437 = s0_1898, _h6437 = _t6437.n; if (_l6437 < 0 || _h6437 < _l6437 || _h6437 > _t6437.n) hr_slerr(_l6437, _h6437, _t6437.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:725"); (hsl){ _t6437.p + _l6437 * (int64_t)sizeof(uint8_t), _h6437 - _l6437 }; }); hr_append(_v6436, _s6436.p, _s6436.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6438 = &(g169); int64_t _k6438 = s0_1898; if (_k6438 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:725"); hr_resize(_v6438, _k6438, sizeof(uint8_t)); }));
}
static void f330_heq_pre(int64_t t_1895) {
if ((!(f331_scalar_ty(t_1895)))) { (void)(f295_gen_heq(t_1895));
 }
}
static bool f331_scalar_ty(int64_t t_1896) {
int64_t k_1897 = ((int64_t)(((*({ hrv *_t6441 = &(g551); int64_t _i6441 = t_1896; (S1*)_t6441->b + hr_ix(_i6441, _t6441->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:726"); }))).k_)); 
return (((((k_1897) == (((int64_t)3LL))) || ((k_1897) == (((int64_t)4LL)))) || ((k_1897) == (((int64_t)2LL)))) || ((k_1897) == (((int64_t)10LL))));
}
static void f332_heq_val_s(int64_t e_1899, int64_t p_1900) {
L98 a_1901 = ({ L98 _t6442; memset(&_t6442, 0, sizeof _t6442); _t6442.n = 0; _t6442; }); 
L100 b_1902 = ({ L100 _t6443; memset(&_t6443, 0, sizeof _t6443); _t6443.n = 0; _t6443; }); 
(void)(({ L98 *_v6444 = &(a_1901); hsl _s6444 = hr_str("((", 2); if (_v6444->n + _s6444.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:729"); memmove(_v6444->e + _v6444->n, _s6444.p, (size_t)_s6444.n * sizeof _v6444->e[0]); _v6444->n += _s6444.n; }));
(void)(({ L98 *_v6445 = &(a_1901); hsl _s6445 = f264_cn(e_1899); if (_v6445->n + _s6445.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:729"); memmove(_v6445->e + _v6445->n, _s6445.p, (size_t)_s6445.n * sizeof _v6445->e[0]); _v6445->n += _s6445.n; }));
(void)(({ L98 *_l6447 = &(a_1901); hrv _o6447 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6447, hr_str("*)_v", 4)); hr_fi(&_o6447, p_1900); hr_fs(&_o6447, hr_str(".p)[_j]", 7)); if (_l6447->n + _o6447.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:729"); memcpy(_l6447->e + _l6447->n, _o6447.b, (size_t)_o6447.n); _l6447->n += _o6447.n; }));
(void)(({ L100 *_l6448 = &(b_1902); hrv _o6448 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6448, hr_str("_x", 2)); hr_fi(&_o6448, p_1900); if (_l6448->n + _o6448.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:729"); memcpy(_l6448->e + _l6448->n, _o6448.b, (size_t)_o6448.n); _l6448->n += _o6448.n; }));
(void)(f329_heq_o(e_1899, ({ hsl _t6450 = ({ L98 *_t6451 = &(a_1901); (hsl){ (uint8_t*)_t6451->e, _t6451->n }; }); int64_t _l6450 = 0, _h6450 = _t6450.n; if (_l6450 < 0 || _h6450 < _l6450 || _h6450 > _t6450.n) hr_slerr(_l6450, _h6450, _t6450.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:729"); (hsl){ _t6450.p + _l6450 * (int64_t)sizeof(uint8_t), _h6450 - _l6450 }; }), ({ hsl _t6452 = ({ L100 *_t6453 = &(b_1902); (hsl){ (uint8_t*)_t6453->e, _t6453->n }; }); int64_t _l6452 = 0, _h6452 = _t6452.n; if (_l6452 < 0 || _h6452 < _l6452 || _h6452 > _t6452.n) hr_slerr(_l6452, _h6452, _t6452.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:729"); (hsl){ _t6452.p + _l6452 * (int64_t)sizeof(uint8_t), _h6452 - _l6452 }; })));
}
static void f333_heq_val_r(int64_t e_1903, int64_t p_1904) {
L98 a_1905 = ({ L98 _t6454; memset(&_t6454, 0, sizeof _t6454); _t6454.n = 0; _t6454; }); 
L100 b_1906 = ({ L100 _t6455; memset(&_t6455, 0, sizeof _t6455); _t6455.n = 0; _t6455; }); 
(void)(({ L98 *_v6456 = &(a_1905); hsl _s6456 = hr_str("((", 2); if (_v6456->n + _s6456.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:730"); memmove(_v6456->e + _v6456->n, _s6456.p, (size_t)_s6456.n * sizeof _v6456->e[0]); _v6456->n += _s6456.n; }));
(void)(({ L98 *_v6457 = &(a_1905); hsl _s6457 = f264_cn(e_1903); if (_v6457->n + _s6457.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:730"); memmove(_v6457->e + _v6457->n, _s6457.p, (size_t)_s6457.n * sizeof _v6457->e[0]); _v6457->n += _s6457.n; }));
(void)(({ L98 *_l6459 = &(a_1905); hrv _o6459 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6459, hr_str("*)_v", 4)); hr_fi(&_o6459, p_1904); hr_fs(&_o6459, hr_str("->b)[_j]", 8)); if (_l6459->n + _o6459.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:730"); memcpy(_l6459->e + _l6459->n, _o6459.b, (size_t)_o6459.n); _l6459->n += _o6459.n; }));
(void)(({ L100 *_l6460 = &(b_1906); hrv _o6460 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6460, hr_str("_x", 2)); hr_fi(&_o6460, p_1904); if (_l6460->n + _o6460.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:730"); memcpy(_l6460->e + _l6460->n, _o6460.b, (size_t)_o6460.n); _l6460->n += _o6460.n; }));
(void)(f329_heq_o(e_1903, ({ hsl _t6462 = ({ L98 *_t6463 = &(a_1905); (hsl){ (uint8_t*)_t6463->e, _t6463->n }; }); int64_t _l6462 = 0, _h6462 = _t6462.n; if (_l6462 < 0 || _h6462 < _l6462 || _h6462 > _t6462.n) hr_slerr(_l6462, _h6462, _t6462.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:730"); (hsl){ _t6462.p + _l6462 * (int64_t)sizeof(uint8_t), _h6462 - _l6462 }; }), ({ hsl _t6464 = ({ L100 *_t6465 = &(b_1906); (hsl){ (uint8_t*)_t6465->e, _t6465->n }; }); int64_t _l6464 = 0, _h6464 = _t6464.n; if (_l6464 < 0 || _h6464 < _l6464 || _h6464 > _t6464.n) hr_slerr(_l6464, _h6464, _t6464.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:730"); (hsl){ _t6464.p + _l6464 * (int64_t)sizeof(uint8_t), _h6464 - _l6464 }; })));
}
static void f334_gblkcall(int64_t n_1907) {
int64_t bi_1908 = f157_rv(n_1907); 
int64_t fv_1909 = ((int64_t)(((*({ hrv *_t6467 = &(g388); int64_t _i6467 = bi_1908; (S6*)_t6467->b + hr_ix(_i6467, _t6467->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:628"); }))).node_)); 
int64_t sa_1910 = g401; 
(void)(f260_ow(hr_str("({ ", 3)));
int64_t np_1911 = ((int64_t)(((*({ hrv *_t6469 = &(g704); int64_t _i6469 = fv_1909; (S4*)_t6469->b + hr_ix(_i6469, _t6469->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:631"); }))).n_)); 
int64_t na_1912 = ((int64_t)(((*({ hrv *_t6470 = &(g704); int64_t _i6470 = n_1907; (S4*)_t6470->b + hr_ix(_i6470, _t6470->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:632"); }))).n_)); 
if (((((uint16_t)((uint64_t)((*({ hrv *_t6471 = &(g704); int64_t _i6471 = fv_1909; (S4*)_t6471->b + hr_ix(_i6471, _t6471->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:633"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { int64_t _e6473 = np_1911; for (int64_t _k6473 = 0; _k6473 < _e6473; _k6473++) { int64_t j_1913 = (int64_t)_k6473; int64_t p_1914 = f90_kid(fv_1909, j_1913); 
g401 = bi_1908;
int64_t v_1915 = f157_rv(p_1914); 
g401 = sa_1910;
if (((j_1913) < (na_1912))) { (void)(f261_ct(((int64_t)(((*({ hrv *_t6477 = &(g389); int64_t _i6477 = v_1915; (S12*)_t6477->b + hr_ix(_i6477, _t6477->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:634"); }))).ty_))));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f286_lv_name(v_1915));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f90_kid(n_1907, j_1913)));
(void)(f260_ow(hr_str("; ", 2)));
 }
 } } _bk6472:; 
 } else { if (((na_1912) >= (((int64_t)1LL)))) { g401 = bi_1908;
int64_t v_1916 = f157_rv(fv_1909); 
g401 = sa_1910;
if (((v_1916) >= (((int64_t)0LL)))) { (void)(f261_ct(((int64_t)(((*({ hrv *_t6486 = &(g389); int64_t _i6486 = v_1916; (S12*)_t6486->b + hr_ix(_i6486, _t6486->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:636"); }))).ty_))));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f286_lv_name(v_1916));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(f90_kid(n_1907, ((int64_t)0LL))));
(void)(f260_ow(hr_str("; ", 2)));
 } else { (void)(f260_ow(hr_str("(void)(", 7)));
(void)(f289_gx(f90_kid(n_1907, ((int64_t)0LL))));
(void)(f260_ow(hr_str("); ", 3)));
 }
 }
 }
g401 = bi_1908;
int64_t body_1917 = ((int64_t)(((*({ hrv *_t6497 = &(g704); int64_t _i6497 = fv_1909; (S4*)_t6497->b + hr_ix(_i6497, _t6497->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:639"); }))).a_)); 
{ int32_t _e6499 = ((*({ hrv *_t6500 = &(g704); int64_t _i6500 = body_1917; (S4*)_t6500->b + hr_ix(_i6500, _t6500->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:640"); }))).n_; for (int32_t _k6499 = 0; _k6499 < _e6499; _k6499++) { int32_t i_1918 = (int32_t)_k6499; (void)(f335_gstmt(f90_kid(body_1917, ((int64_t)(i_1918)))));
 } } _bk6498:; 
int64_t tl_2049 = ((int64_t)(((*({ hrv *_t6503 = &(g704); int64_t _i6503 = body_1917; (S4*)_t6503->b + hr_ix(_i6503, _t6503->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:641"); }))).a_)); 
if (((tl_2049) >= (((int64_t)0LL)))) { if ((((((int64_t)(((*({ hrv *_t6504 = &(g388); int64_t _i6504 = bi_1908; (S6*)_t6504->b + hr_ix(_i6504, _t6504->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:642"); }))).ret_))) != (g558)) && (!(f209_ends(tl_2049))))) { (void)(f289_gx(tl_2049));
(void)(f260_ow(hr_str("; ", 2)));
 } else { (void)(f335_gstmt(tl_2049));
 }
 }
g401 = sa_1910;
(void)(f260_ow(hr_str(" })", 3)));
}
static void f335_gstmt(int64_t n_1919) {
if (((n_1919) < (((int64_t)0LL)))) { return;
 }
int64_t sp_1920 = (g163).n; 
int64_t td_1921 = (g176).n; 
S4 x_1922 = (*({ hrv *_t6510 = &(g704); int64_t _i6510 = n_1919; (S4*)_t6510->b + hr_ix(_i6510, _t6510->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1046"); })); 
int64_t k_1923 = ((int64_t)((x_1922).k_)); 
bool decl_1924 = ((k_1923) == (((int64_t)33LL))); 
if (((k_1923) == (((int64_t)33LL)))) { (void)(f336_gvdecl(n_1919));
 } else { (void)(f338_gstmt1(n_1919));
 }
(void)(f260_ow(hr_str("\012", 1)));
if ((((g176).n) > (td_1921))) { (void)(({ hrv *_v6514 = &(g177); _v6514->n = 0; }));
(void)(({ hrv *_v6515 = &(g177); hsl _s6515 = ({ hsl _t6516 = hr_sl(g163); int64_t _l6516 = sp_1920, _h6516 = _t6516.n; if (_l6516 < 0 || _h6516 < _l6516 || _h6516 > _t6516.n) hr_slerr(_l6516, _h6516, _t6516.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1052"); (hsl){ _t6516.p + _l6516 * (int64_t)sizeof(uint8_t), _h6516 - _l6516 }; }); hr_append(_v6515, _s6515.p, _s6515.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6517 = &(g163); int64_t _k6517 = sp_1920; if (_k6517 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1052"); hr_resize(_v6517, _k6517, sizeof(uint8_t)); }));
if ((!(decl_1924))) { (void)(f260_ow(hr_str("{ ", 2)));
 }
(void)(({ hrv *_v6519 = &(g163); hsl _s6519 = ({ hsl _t6520 = hr_sl(g176); int64_t _l6520 = td_1921, _h6520 = _t6520.n; if (_l6520 < 0 || _h6520 < _l6520 || _h6520 > _t6520.n) hr_slerr(_l6520, _h6520, _t6520.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1054"); (hsl){ _t6520.p + _l6520 * (int64_t)sizeof(uint8_t), _h6520 - _l6520 }; }); hr_append(_v6519, _s6519.p, _s6519.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6521 = &(g176); int64_t _k6521 = td_1921; if (_k6521 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1054"); hr_resize(_v6521, _k6521, sizeof(uint8_t)); }));
(void)(({ hrv *_v6522 = &(g163); hsl _s6522 = ({ hsl _t6523 = hr_sl(g177); int64_t _l6523 = 0, _h6523 = _t6523.n; if (_l6523 < 0 || _h6523 < _l6523 || _h6523 > _t6523.n) hr_slerr(_l6523, _h6523, _t6523.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1055"); (hsl){ _t6523.p + _l6523 * (int64_t)sizeof(uint8_t), _h6523 - _l6523 }; }); hr_append(_v6522, _s6522.p, _s6522.n, sizeof(uint8_t)); }));
if ((!(decl_1924))) { (void)(f260_ow(hr_str("}\012", 2)));
 }
 }
}
static void f336_gvdecl(int64_t n_1925) {
S4 x_1926 = (*({ hrv *_t6525 = &(g704); int64_t _i6525 = n_1925; (S4*)_t6525->b + hr_ix(_i6525, _t6525->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:934"); })); 
if ((((x_1926).n_) > (((int32_t)1LL)))) { if (((f217_ax(n_1925)) == (((int64_t)1LL)))) { L89 ids_1927 = ({ L89 _t6527; memset(&_t6527, 0, sizeof _t6527); _t6527.n = 0; _t6527; }); 
{ int32_t _e6529 = (x_1926).n_; for (int32_t _k6529 = 0; _k6529 < _e6529; _k6529++) { int32_t i_1928 = (int32_t)_k6529; int64_t iv_1929 = f90_kid(((int64_t)((x_1926).b_)), ((int64_t)(i_1928))); 
int64_t p_1930 = f293_nt(); 
(void)(({ L89 *_v6532 = &(ids_1927); int32_t _x6532 = ((int32_t)(p_1930)); if (_v6532->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:938"); _v6532->e[_v6532->n] = _x6532; &_v6532->e[_v6532->n++]; }));
(void)(f261_ct(f279_fin(iv_1929)));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_1930));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(iv_1929));
(void)(f260_ow(hr_str("; ", 2)));
 } } _bk6528:; 
int64_t v0_1931 = f157_rv(n_1925); 
{ int32_t _e6542 = (x_1926).n_; for (int32_t _k6542 = 0; _k6542 < _e6542; _k6542++) { int32_t i_1932 = (int32_t)_k6542; (void)(f337_decl_lv(((int64_t)((int64_t)v0_1931 + (int64_t)((int64_t)(i_1932))))));
(void)(({ hrv *_o6544 = &(g163); hr_fs(_o6544, hr_str(" = _t", 5)); hr_fi(_o6544, (*({ L89 *_t6545 = &(ids_1927); int64_t _i6545 = i_1932; _t6545->e + hr_ix(_i6545, _t6545->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:940"); }))); hr_fs(_o6544, hr_str("; ", 2)); }));
 } } _bk6541:; 
return;
 }
int64_t init_1935 = f90_kid(((int64_t)((x_1926).b_)), ((int64_t)0LL)); 
int64_t p_1936 = f293_nt(); 
(void)(f261_ct(f141_at(init_1935)));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_1936));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(init_1935));
(void)(f260_ow(hr_str("; ", 2)));
int64_t v0_1937 = f157_rv(n_1925); 
{ int32_t _e6557 = (x_1926).n_; for (int32_t _k6557 = 0; _k6557 < _e6557; _k6557++) { int32_t i_1938 = (int32_t)_k6557; (void)(f337_decl_lv(((int64_t)((int64_t)v0_1937 + (int64_t)((int64_t)(i_1938))))));
(void)(({ hrv *_o6559 = &(g163); hr_fs(_o6559, hr_str(" = _t", 5)); hr_fi(_o6559, p_1936); hr_fs(_o6559, hr_str(".r", 2)); hr_fi(_o6559, i_1938); hr_fs(_o6559, hr_str("; ", 2)); }));
 } } _bk6556:; 
return;
 }
int64_t v_1939 = f157_rv(n_1925); 
int64_t t_1940 = ((int64_t)(((*({ hrv *_t6561 = &(g389); int64_t _i6561 = v_1939; (S12*)_t6561->b + hr_ix(_i6561, _t6561->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:951"); }))).ty_)); 
(void)(f337_decl_lv(v_1939));
(void)(f260_ow(hr_str(" = ", 3)));
if ((((x_1926).b_) < (((int32_t)0LL)))) { (void)(f260_ow(hr_str("{0}; ", 5)));
return;
 }
int64_t init_1941 = f90_kid(((int64_t)((x_1926).b_)), ((int64_t)0LL)); 
if (((((*({ hrv *_t6566 = &(g551); int64_t _i6566 = t_1940; (S1*)_t6566->b + hr_ix(_i6566, _t6566->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:956"); }))).k_) == (((uint8_t)10LL)))) { int64_t it_1942 = f279_fin(init_1941); 
if ((((((*({ hrv *_t6568 = &(g551); int64_t _i6568 = it_1942; (S1*)_t6568->b + hr_ix(_i6568, _t6568->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:956"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t6569 = &(g551); int64_t _i6569 = it_1942; (S1*)_t6569->b + hr_ix(_i6569, _t6569->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:956"); }))).k_) == (((uint8_t)11LL))))) { (void)(f289_gx(init_1941));
 } else { (void)(f324_gaddr(init_1941));
 }
(void)(f260_ow(hr_str("; ", 2)));
return;
 }
if (f268_is_res(t_1940)) { (void)(f269_gxo(init_1941));
(void)(f260_ow(hr_str("; ", 2)));
return;
 }
int64_t it_1943 = f141_at(init_1941); 
if (((((*({ hrv *_t6577 = &(g551); int64_t _i6577 = it_1943; (S1*)_t6577->b + hr_ix(_i6577, _t6577->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:959"); }))).k_) == (((uint8_t)14LL)))) { (void)(f289_gx(init_1941));
(void)(({ hrv *_o6579 = &(g163); hr_fs(_o6579, hr_str(".r0; ", 5)); }));
return;
 }
(void)(f289_gx(init_1941));
(void)(f260_ow(hr_str("; ", 2)));
}
static void f337_decl_lv(int64_t v_1933) {
int64_t t_1934 = ((int64_t)(((*({ hrv *_t6582 = &(g389); int64_t _i6582 = v_1933; (S12*)_t6582->b + hr_ix(_i6582, _t6582->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:963"); }))).ty_)); 
(void)(f261_ct(t_1934));
(void)(f260_ow(hr_str(" ", 1)));
if (f285_lv_isptr(v_1933)) { (void)(f260_ow(hr_str("*", 1)));
 }
(void)(f286_lv_name(v_1933));
if ((f268_is_res(t_1934) && (!(f285_lv_isptr(v_1933))))) { (void)(f260_ow(hr_str(" __attribute__((cleanup(hr_rdrop)))", 35)));
 }
}
static void f338_gstmt1(int64_t n_1944) {
S4 x_1945 = (*({ hrv *_t6591 = &(g704); int64_t _i6591 = n_1944; (S4*)_t6591->b + hr_ix(_i6591, _t6591->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1060"); })); 
int64_t k_1946 = ((int64_t)((x_1945).k_)); 
if (((k_1946) == (((int64_t)34LL)))) { (void)(f339_gassign(n_1944));
return;
 }
if (((k_1946) == (((int64_t)35LL)))) { int64_t a_1961 = ((int64_t)((x_1945).a_)); 
int64_t tt_1962 = f141_at(a_1961); 
if (((((*({ hrv *_t6594 = &(g551); int64_t _i6594 = tt_1962; (S1*)_t6594->b + hr_ix(_i6594, _t6594->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1063"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_ow(hr_str("(*", 2)));
(void)(f275_gx0(a_1961));
(void)(f260_ow(hr_str(")", 1)));
 } else { (void)(f289_gx(a_1961));
 }
(void)(f260_ow(({ hsl _r6600; if (((((int64_t)((x_1945).op_))) == (((int64_t)34LL)))) { _r6600 = hr_str("++;", 3);  } else { _r6600 = hr_str("--;", 3);  } _r6600; })));
return;
 }
if (((k_1946) == (((int64_t)50LL)))) { return;
 }
if (((k_1946) == (((int64_t)19LL)))) { (void)(f341_gif(n_1944, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1946) == (((int64_t)25LL)))) { (void)(f344_gwhile(n_1944));
return;
 }
if (((k_1946) == (((int64_t)26LL)))) { (void)(f347_gloop(n_1944, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1946) == (((int64_t)27LL)))) { (void)(f348_gfor(n_1944));
return;
 }
if (((k_1946) == (((int64_t)20LL)))) { (void)(f349_gmatch(n_1944, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1946) == (((int64_t)24LL)))) { (void)(f350_geblock(n_1944, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1946) == (((int64_t)23LL)))) { (void)(f260_ow(hr_str("{ ", 2)));
(void)(f342_gblk(n_1944, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f260_ow(hr_str(" }", 2)));
return;
 }
if (((k_1946) == (((int64_t)28LL)))) { (void)(f351_gret(n_1944));
return;
 }
if (((k_1946) == (((int64_t)29LL)))) { (void)(f355_gbreak(n_1944));
return;
 }
if (((k_1946) == (((int64_t)30LL)))) { (void)(f260_ow(hr_str("continue;", 9)));
return;
 }
if (((k_1946) == (((int64_t)37LL)))) { (void)(f287_gerr(n_1944, hr_str("const for is not supported by the self-hosted compiler yet", 58)));
return;
 }
if (f356_owned(n_1944)) { (void)(f260_ow(hr_str("hr_rgive(", 9)));
(void)(f275_gx0(n_1944));
(void)(f260_ow(hr_str(");", 2)));
return;
 }
(void)(f260_ow(hr_str("(void)(", 7)));
(void)(f289_gx(n_1944));
(void)(f260_ow(hr_str(");", 2)));
}
static void f339_gassign(int64_t n_1947) {
S4 x_1948 = (*({ hrv *_t6621 = &(g704); int64_t _i6621 = n_1947; (S4*)_t6621->b + hr_ix(_i6621, _t6621->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:970"); })); 
int64_t o_1949 = ((int64_t)((x_1948).op_)); 
if (((o_1949) == (((int64_t)11LL)))) { int64_t p_1950 = f293_nt(); 
(void)(f260_ow(hr_str("{ ", 2)));
(void)(f261_ct(f141_at(((int64_t)((x_1948).b_)))));
(void)(f260_ow(hr_str(" _t", 3)));
(void)(f294_oi(p_1950));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1948).b_))));
(void)(f260_ow(hr_str("; ", 2)));
int64_t tl_1951 = ((int64_t)((x_1948).a_)); 
{ int32_t _e6632 = ((*({ hrv *_t6633 = &(g704); int64_t _i6633 = tl_1951; (S4*)_t6633->b + hr_ix(_i6633, _t6633->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:976"); }))).n_; for (int32_t _k6632 = 0; _k6632 < _e6632; _k6632++) { int32_t i_1952 = (int32_t)_k6632; int64_t tg_1953 = f90_kid(tl_1951, ((int64_t)(i_1952))); 
(void)(f289_gx(tg_1953));
(void)(({ hrv *_o6636 = &(g163); hr_fs(_o6636, hr_str(" = _t", 5)); hr_fi(_o6636, p_1950); hr_fs(_o6636, hr_str(".r", 2)); hr_fi(_o6636, i_1952); hr_fs(_o6636, hr_str("; ", 2)); }));
 } } _bk6631:; 
(void)(f260_ow(hr_str("}", 1)));
return;
 }
int64_t a_1954 = ((int64_t)((x_1948).a_)); 
int64_t tt_1955 = f141_at(a_1954); 
int64_t d_1956 = f179_deref(tt_1955); 
if ((((o_1949) == (((int64_t)18LL))) && ((((*({ hrv *_t6640 = &(g551); int64_t _i6640 = tt_1955; (S1*)_t6640->b + hr_ix(_i6640, _t6640->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:983"); }))).k_) == (((uint8_t)10LL))))) { int64_t b_1957 = ((int64_t)((x_1948).b_)); 
(void)(f275_gx0(a_1954));
(void)(f260_ow(hr_str(" = ", 3)));
if ((((((*({ hrv *_t6643 = &(g551); int64_t _i6643 = f279_fin(b_1957); (S1*)_t6643->b + hr_ix(_i6643, _t6643->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:986"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t6645 = &(g551); int64_t _i6645 = f279_fin(b_1957); (S1*)_t6645->b + hr_ix(_i6645, _t6645->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:986"); }))).k_) == (((uint8_t)11LL))))) { (void)(f289_gx(b_1957));
 } else { (void)(f324_gaddr(b_1957));
 }
(void)(f260_ow(hr_str(";", 1)));
return;
 }
if ((((o_1949) == (((int64_t)36LL))) || ((o_1949) == (((int64_t)18LL))))) { if (f268_is_res(d_1956)) { (void)(f260_ow(hr_str("hr_rset(", 8)));
if (((((*({ hrv *_t6652 = &(g551); int64_t _i6652 = tt_1955; (S1*)_t6652->b + hr_ix(_i6652, _t6652->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:991"); }))).k_) == (((uint8_t)10LL)))) { (void)(f275_gx0(a_1954));
 } else { (void)(f260_ow(hr_str("&(", 2)));
(void)(f289_gx(a_1954));
(void)(f260_ow(hr_str(")", 1)));
 }
(void)(f260_ow(hr_str(", ", 2)));
(void)(f269_gxo(((int64_t)((x_1948).b_))));
(void)(f260_ow(hr_str(");", 2)));
return;
 }
if ((((((((*({ hrv *_t6660 = &(g551); int64_t _i6660 = tt_1955; (S1*)_t6660->b + hr_ix(_i6660, _t6660->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:992"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t6661 = &(g551); int64_t _i6661 = f141_at(((int64_t)((x_1948).b_))); (S1*)_t6661->b + hr_ix(_i6661, _t6661->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:992"); }))).k_) != (((uint8_t)10LL)))) && ((((*({ hrv *_t6663 = &(g551); int64_t _i6663 = f279_fin(((int64_t)((x_1948).b_))); (S1*)_t6663->b + hr_ix(_i6663, _t6663->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:992"); }))).k_) != (((uint8_t)10LL)))) && ((((*({ hrv *_t6665 = &(g551); int64_t _i6665 = f141_at(((int64_t)((x_1948).b_))); (S1*)_t6665->b + hr_ix(_i6665, _t6665->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:992"); }))).k_) != (((uint8_t)11LL))))) { (void)(f260_ow(hr_str("*", 1)));
(void)(f275_gx0(a_1954));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1948).b_))));
(void)(f260_ow(hr_str(";", 1)));
return;
 }
if (((((*({ hrv *_t6672 = &(g704); int64_t _i6672 = a_1954; (S4*)_t6672->b + hr_ix(_i6672, _t6672->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:993"); }))).k_) == (((uint8_t)8LL)))) { (void)(f289_gx(a_1954));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1948).b_))));
(void)(f260_ow(hr_str(";", 1)));
return;
 }
int64_t q_1958 = f293_nt(); 
(void)(f260_ow(hr_str("{ ", 2)));
(void)(f261_ct(d_1956));
(void)(f260_ow(hr_str(" *_t", 4)));
(void)(f294_oi(q_1958));
(void)(f260_ow(hr_str(" = &(", 5)));
(void)(f289_gx(a_1954));
(void)(f260_ow(hr_str("); *_t", 6)));
(void)(f294_oi(q_1958));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_1948).b_))));
(void)(f260_ow(hr_str("; }", 3)));
return;
 }
int64_t p_1959 = f293_nt(); 
(void)(f260_ow(hr_str("{ ", 2)));
(void)(f261_ct(d_1956));
(void)(f260_ow(hr_str(" *_t", 4)));
(void)(f294_oi(p_1959));
(void)(f260_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t6695 = &(g551); int64_t _i6695 = tt_1955; (S1*)_t6695->b + hr_ix(_i6695, _t6695->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1000"); }))).k_) == (((uint8_t)10LL)))) { (void)(f275_gx0(a_1954));
 } else { (void)(f260_ow(hr_str("&(", 2)));
(void)(f289_gx(a_1954));
(void)(f260_ow(hr_str(")", 1)));
 }
(void)(f260_ow(hr_str("; *_t", 5)));
(void)(f294_oi(p_1959));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f307_garith(f340_base_op(o_1949), d_1956, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)((x_1948).b_)), p_1959, n_1947));
(void)(f260_ow(hr_str("; }", 3)));
}
static int64_t f340_base_op(int64_t o_1960) {
if (((o_1960) == (((int64_t)26LL)))) { return ((int64_t)21LL);
 }
if (((o_1960) == (((int64_t)27LL)))) { return ((int64_t)22LL);
 }
if (((o_1960) == (((int64_t)28LL)))) { return ((int64_t)23LL);
 }
if (((o_1960) == (((int64_t)29LL)))) { return ((int64_t)24LL);
 }
if (((o_1960) == (((int64_t)30LL)))) { return ((int64_t)25LL);
 }
if (((o_1960) == (((int64_t)31LL)))) { return ((int64_t)49LL);
 }
if (((o_1960) == (((int64_t)32LL)))) { return ((int64_t)50LL);
 }
if (((o_1960) == (((int64_t)33LL)))) { return ((int64_t)51LL);
 }
if (((o_1960) == (((int64_t)45LL)))) { return ((int64_t)43LL);
 }
if (((o_1960) == (((int64_t)46LL)))) { return ((int64_t)44LL);
 }
return o_1960;
}
static void f341_gif(int64_t n_1963, int64_t res_1964) {
S4 x_1965 = (*({ hrv *_t6706 = &(g704); int64_t _i6706 = n_1963; (S4*)_t6706->b + hr_ix(_i6706, _t6706->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:817"); })); 
(void)(f260_ow(hr_str("if (", 4)));
int64_t m_1966 = f217_ax(n_1963); 
if ((((m_1966) != (((int64_t)0LL))) && ((m_1966) != (((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))))) { (void)(f260_ow(hr_str("(", 1)));
(void)(f275_gx0(((int64_t)((x_1965).a_))));
(void)(f260_ow(hr_str(") != 0", 6)));
 } else { (void)(f289_gx(((int64_t)((x_1965).a_))));
 }
(void)(f260_ow(hr_str(") { ", 4)));
if (((m_1966) > (((int64_t)1LL)))) { int64_t v_1967 = ((int64_t)((int64_t)m_1966 & (int64_t)((int64_t)((int64_t)((int64_t)((((int64_t)1LL)) << ((((int64_t)30LL)) & 63))) - (int64_t)((int64_t)1LL))))); 
(void)(f261_ct(((int64_t)(((*({ hrv *_t6715 = &(g389); int64_t _i6715 = v_1967; (S12*)_t6715->b + hr_ix(_i6715, _t6715->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:822"); }))).ty_))));
(void)(f260_ow(hr_str(" *", 2)));
(void)(f286_lv_name(v_1967));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f275_gx0(((int64_t)((x_1965).a_))));
(void)(f260_ow(hr_str("; ", 2)));
 }
(void)(f342_gblk(((int64_t)((x_1965).b_)), res_1964, false));
(void)(f260_ow(hr_str(" }", 2)));
if ((((x_1965).c_) >= (((int32_t)0LL)))) { (void)(f260_ow(hr_str(" else { ", 8)));
if (((((*({ hrv *_t6724 = &(g704); int64_t _i6724 = (x_1965).c_; (S4*)_t6724->b + hr_ix(_i6724, _t6724->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:825"); }))).k_) == (((uint8_t)19LL)))) { (void)(f341_gif(((int64_t)((x_1965).c_)), res_1964));
 } else { (void)(f342_gblk(((int64_t)((x_1965).c_)), res_1964, false));
 }
(void)(f260_ow(hr_str(" }", 2)));
 }
}
static void f342_gblk(int64_t b_1968, int64_t res_1969, bool val_1970) {
S4 x_1971 = (*({ hrv *_t6728 = &(g704); int64_t _i6728 = b_1968; (S4*)_t6728->b + hr_ix(_i6728, _t6728->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:806"); })); 
if (((((int64_t)((x_1971).k_))) != (((int64_t)23LL)))) { if (((res_1969) >= (((int64_t)0LL)))) { (void)(f343_gtail(b_1968, res_1969));
 } else { if (val_1970) { (void)(f289_gx(b_1968));
(void)(f260_ow(hr_str(";", 1)));
 } else { (void)(f335_gstmt(b_1968));
 }
 }
return;
 }
{ int32_t _e6734 = (x_1971).n_; for (int32_t _k6734 = 0; _k6734 < _e6734; _k6734++) { int32_t i_1974 = (int32_t)_k6734; (void)(f335_gstmt(f90_kid(b_1968, ((int64_t)(i_1974)))));
 } } _bk6733:; 
if ((((x_1971).a_) >= (((int32_t)0LL)))) { int64_t tl_1975 = ((int64_t)((x_1971).a_)); 
if (((res_1969) >= (((int64_t)0LL)))) { (void)(f343_gtail(tl_1975, res_1969));
return;
 }
if (((val_1970 && ((f141_at(tl_1975)) != (g558))) && (!(f209_ends(tl_1975))))) { (void)(f289_gx(tl_1975));
(void)(f260_ow(hr_str("; ", 2)));
return;
 }
(void)(f335_gstmt(tl_1975));
 }
}
static void f343_gtail(int64_t tl_1972, int64_t res_1973) {
if ((((res_1973) >= (((int64_t)0LL))) && (!(f209_ends(tl_1972))))) { (void)(f260_ow(hr_str("_r", 2)));
(void)(f294_oi(res_1973));
(void)(f260_ow(hr_str(" = ", 3)));
if (f268_is_res(f279_fin(tl_1972))) { (void)(f269_gxo(tl_1972));
 } else { (void)(f289_gx(tl_1972));
 }
(void)(f260_ow(hr_str("; ", 2)));
return;
 }
(void)(f335_gstmt(tl_1972));
}
static void f344_gwhile(int64_t n_1976) {
S4 x_1977 = (*({ hrv *_t6753 = &(g704); int64_t _i6753 = n_1976; (S4*)_t6753->b + hr_ix(_i6753, _t6753->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:840"); })); 
int64_t l_1980 = f345_lbl_push(((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f260_ow(hr_str("while (", 7)));
if (((f217_ax(n_1976)) == (((int64_t)1LL)))) { (void)(f260_ow(hr_str("(", 1)));
(void)(f275_gx0(((int64_t)((x_1977).a_))));
(void)(f260_ow(hr_str(") != 0", 6)));
 } else { (void)(f289_gx(((int64_t)((x_1977).a_))));
 }
(void)(f260_ow(hr_str(") { ", 4)));
(void)(f342_gblk(((int64_t)((x_1977).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f260_ow(hr_str(" }", 2)));
(void)(f346_lbl_pop(l_1980));
}
static int64_t f345_lbl_push(int64_t res_1978) {
int64_t l_1979 = f293_nt(); 
(void)(({ hrv *_v6766 = &(g180); int32_t _x6766 = ((int32_t)(l_1979)); int32_t *_p6766 = (int32_t*)hr_grow(_v6766, 1, sizeof _x6766); *_p6766 = _x6766; _p6766; }));
(void)(({ hrv *_v6767 = &(g181); int32_t _x6767 = ((int32_t)(res_1978)); int32_t *_p6767 = (int32_t*)hr_grow(_v6767, 1, sizeof _x6767); *_p6767 = _x6767; _p6767; }));
return l_1979;
}
static void f346_lbl_pop(int64_t l_1981) {
(void)(({ hrv *_v6768 = &(g180); if (!_v6768->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:828"); ((int32_t*)_v6768->b)[--_v6768->n]; }));
(void)(({ hrv *_v6769 = &(g181); if (!_v6769->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:828"); ((int32_t*)_v6769->b)[--_v6769->n]; }));
(void)(({ hrv *_o6770 = &(g163); hr_fs(_o6770, hr_str(" _bk", 4)); hr_fi(_o6770, l_1981); hr_fs(_o6770, hr_str(":; ", 3)); }));
}
static void f347_gloop(int64_t n_1982, int64_t res_1983) {
int64_t l_1984 = f345_lbl_push(res_1983); 
(void)(f260_ow(hr_str("for (;;) { ", 11)));
(void)(f342_gblk(((int64_t)(((*({ hrv *_t6774 = &(g704); int64_t _i6774 = n_1982; (S4*)_t6774->b + hr_ix(_i6774, _t6774->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:831"); }))).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f260_ow(hr_str(" }", 2)));
(void)(f346_lbl_pop(l_1984));
}
static void f348_gfor(int64_t n_1985) {
S4 x_1986 = (*({ hrv *_t6777 = &(g704); int64_t _i6777 = n_1985; (S4*)_t6777->b + hr_ix(_i6777, _t6777->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:848"); })); 
int64_t v_1987 = f157_rv(n_1985); 
int64_t m_1988 = f217_ax(n_1985); 
int64_t iv_1989 = ({ int64_t _r6780; if ((((x_1986).c_) >= (((int32_t)0LL)))) { _r6780 = ((int64_t)((m_1988) >> ((((int64_t)2LL)) & 63)));  } else { _r6780 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r6780; }); 
int64_t l_1990 = f345_lbl_push(((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t p_1991 = f293_nt(); 
int64_t et_1992 = ((int64_t)(((*({ hrv *_t6783 = &(g389); int64_t _i6783 = v_1987; (S12*)_t6783->b + hr_ix(_i6783, _t6783->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:854"); }))).ty_)); 
if (((((int64_t)((int64_t)m_1988 & (int64_t)((int64_t)3LL)))) == (((int64_t)0LL)))) { int64_t rt0_1993 = f279_fin(({ int64_t _r6785; if ((((x_1986).b_) >= (((int32_t)0LL)))) { _r6785 = ((int64_t)((x_1986).b_));  } else { _r6785 = ((int64_t)((x_1986).a_));  } _r6785; })); 
int64_t ctt_1994 = ({ int64_t _r6786; if (((((*({ hrv *_t6787 = &(g551); int64_t _i6787 = rt0_1993; (S1*)_t6787->b + hr_ix(_i6787, _t6787->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:857"); }))).k_) == (((uint8_t)3LL)))) { _r6786 = rt0_1993;  } else { _r6786 = g563;  } _r6786; }); 
(void)(f260_ow(hr_str("{ ", 2)));
(void)(f261_ct(ctt_1994));
(void)(f260_ow(hr_str(" _e", 3)));
(void)(f294_oi(p_1991));
(void)(f260_ow(hr_str(" = ", 3)));
if ((((x_1986).b_) >= (((int32_t)0LL)))) { (void)(f289_gx(((int64_t)((x_1986).b_))));
 } else { (void)(f289_gx(((int64_t)((x_1986).a_))));
 }
(void)(f260_ow(hr_str("; for (", 7)));
(void)(f261_ct(ctt_1994));
(void)(({ hrv *_o6797 = &(g163); hr_fs(_o6797, hr_str(" _k", 3)); hr_fi(_o6797, p_1991); hr_fs(_o6797, hr_str(" = ", 3)); }));
if ((((x_1986).b_) >= (((int32_t)0LL)))) { (void)(f289_gx(((int64_t)((x_1986).a_))));
 } else { (void)(f260_ow(hr_str("0", 1)));
 }
(void)(({ hrv *_o6800 = &(g163); hr_fs(_o6800, hr_str("; _k", 4)); hr_fi(_o6800, p_1991); hr_fs(_o6800, hr_str(" < _e", 5)); hr_fi(_o6800, p_1991); hr_fs(_o6800, hr_str("; _k", 4)); hr_fi(_o6800, p_1991); hr_fs(_o6800, hr_str("++) { ", 6)); }));
(void)(f261_ct(et_1992));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f286_lv_name(v_1987));
(void)(({ hrv *_o6804 = &(g163); hr_fs(_o6804, hr_str(" = (", 4)); }));
(void)(f261_ct(et_1992));
(void)(({ hrv *_o6806 = &(g163); hr_fs(_o6806, hr_str(")_k", 3)); hr_fi(_o6806, p_1991); hr_fs(_o6806, hr_str("; ", 2)); }));
if (((iv_1989) >= (((int64_t)0LL)))) { (void)(f261_ct(((int64_t)(((*({ hrv *_t6808 = &(g389); int64_t _i6808 = iv_1989; (S12*)_t6808->b + hr_ix(_i6808, _t6808->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:863"); }))).ty_))));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f286_lv_name(iv_1989));
(void)(f260_ow(hr_str(" = (", 4)));
(void)(f261_ct(((int64_t)(((*({ hrv *_t6813 = &(g389); int64_t _i6813 = iv_1989; (S12*)_t6813->b + hr_ix(_i6813, _t6813->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:863"); }))).ty_))));
(void)(({ hrv *_o6814 = &(g163); hr_fs(_o6814, hr_str(")_k", 3)); hr_fi(_o6814, p_1991); hr_fs(_o6814, hr_str("; ", 2)); }));
 }
(void)(f342_gblk(((int64_t)((x_1986).d_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f260_ow(hr_str(" } }", 4)));
(void)(f346_lbl_pop(l_1990));
return;
 }
int64_t a_1995 = ((int64_t)((x_1986).a_)); 
int64_t bt_1996 = f141_at(a_1995); 
int64_t d_1997 = f179_deref(bt_1996); 
int64_t e_1998 = ((int64_t)(((*({ hrv *_t6820 = &(g551); int64_t _i6820 = d_1997; (S1*)_t6820->b + hr_ix(_i6820, _t6820->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:872"); }))).a_)); 
bool byref_1999 = ((((uint16_t)((uint64_t)(x_1986).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))); 
if (f268_is_res(d_1997)) { (void)(f260_ow(hr_str("{ hrv *_v", 9)));
(void)(f294_oi(p_1991));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f325_grecv_ptr(a_1995));
(void)(({ hrv *_o6826 = &(g163); hr_fs(_o6826, hr_str("; for (int64_t _k", 17)); hr_fi(_o6826, p_1991); hr_fs(_o6826, hr_str(" = 0; _k", 8)); hr_fi(_o6826, p_1991); hr_fs(_o6826, hr_str(" < _v", 5)); hr_fi(_o6826, p_1991); hr_fs(_o6826, hr_str("->n; _k", 7)); hr_fi(_o6826, p_1991); hr_fs(_o6826, hr_str("++) { ", 6)); }));
(void)(f261_ct(e_1998));
(void)(f260_ow(({ hsl _r6829; if (byref_1999) { _r6829 = hr_str(" *", 2);  } else { _r6829 = hr_str(" ", 1);  } _r6829; })));
(void)(f286_lv_name(v_1987));
(void)(f260_ow(({ hsl _r6832; if (byref_1999) { _r6832 = hr_str(" = &((", 6);  } else { _r6832 = hr_str(" = ((", 5);  } _r6832; })));
(void)(f261_ct(e_1998));
(void)(({ hrv *_o6834 = &(g163); hr_fs(_o6834, hr_str("*)_v", 4)); hr_fi(_o6834, p_1991); hr_fs(_o6834, hr_str("->b)[_k", 7)); hr_fi(_o6834, p_1991); hr_fs(_o6834, hr_str("]; ", 3)); }));
 } else { (void)(f260_ow(hr_str("{ hsl _v", 8)));
(void)(f294_oi(p_1991));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f292_gsl(a_1995, bt_1996));
(void)(({ hrv *_o6839 = &(g163); hr_fs(_o6839, hr_str("; for (int64_t _k", 17)); hr_fi(_o6839, p_1991); hr_fs(_o6839, hr_str(" = 0; _k", 8)); hr_fi(_o6839, p_1991); hr_fs(_o6839, hr_str(" < _v", 5)); hr_fi(_o6839, p_1991); hr_fs(_o6839, hr_str(".n; _k", 6)); hr_fi(_o6839, p_1991); hr_fs(_o6839, hr_str("++) { ", 6)); }));
(void)(f261_ct(e_1998));
(void)(f260_ow(({ hsl _r6842; if (byref_1999) { _r6842 = hr_str(" *", 2);  } else { _r6842 = hr_str(" ", 1);  } _r6842; })));
(void)(f286_lv_name(v_1987));
(void)(f260_ow(({ hsl _r6845; if (byref_1999) { _r6845 = hr_str(" = &((", 6);  } else { _r6845 = hr_str(" = ((", 5);  } _r6845; })));
(void)(f261_ct(e_1998));
(void)(({ hrv *_o6847 = &(g163); hr_fs(_o6847, hr_str("*)_v", 4)); hr_fi(_o6847, p_1991); hr_fs(_o6847, hr_str(".p)[_k", 6)); hr_fi(_o6847, p_1991); hr_fs(_o6847, hr_str("]; ", 3)); }));
 }
if (((iv_1989) >= (((int64_t)0LL)))) { (void)(f261_ct(((int64_t)(((*({ hrv *_t6849 = &(g389); int64_t _i6849 = iv_1989; (S12*)_t6849->b + hr_ix(_i6849, _t6849->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:881"); }))).ty_))));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f286_lv_name(iv_1989));
(void)(f260_ow(hr_str(" = (", 4)));
(void)(f261_ct(((int64_t)(((*({ hrv *_t6854 = &(g389); int64_t _i6854 = iv_1989; (S12*)_t6854->b + hr_ix(_i6854, _t6854->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:881"); }))).ty_))));
(void)(({ hrv *_o6855 = &(g163); hr_fs(_o6855, hr_str(")_k", 3)); hr_fi(_o6855, p_1991); hr_fs(_o6855, hr_str("; ", 2)); }));
 }
(void)(f342_gblk(((int64_t)((x_1986).d_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f260_ow(hr_str(" } }", 4)));
(void)(f346_lbl_pop(l_1990));
}
static void f349_gmatch(int64_t n_2000, int64_t res_2001) {
S4 x_2002 = (*({ hrv *_t6859 = &(g704); int64_t _i6859 = n_2000; (S4*)_t6859->b + hr_ix(_i6859, _t6859->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:887"); })); 
int64_t a_2003 = ((int64_t)((x_2002).a_)); 
int64_t st_2004 = f141_at(a_2003); 
int64_t d_2005 = f179_deref(st_2004); 
int64_t p_2006 = f293_nt(); 
bool isenum_2007 = ((((*({ hrv *_t6863 = &(g551); int64_t _i6863 = d_2005; (S1*)_t6863->b + hr_ix(_i6863, _t6863->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:892"); }))).k_) == (((uint8_t)6LL))); 
(void)(f260_ow(hr_str("{ ", 2)));
if (isenum_2007) { (void)(f261_ct(d_2005));
(void)(f260_ow(hr_str(" *_m", 4)));
(void)(f294_oi(p_2006));
(void)(f260_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t6869 = &(g551); int64_t _i6869 = st_2004; (S1*)_t6869->b + hr_ix(_i6869, _t6869->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:894"); }))).k_) == (((uint8_t)10LL)))) { (void)(f275_gx0(a_2003));
 } else { if (f272_is_place(a_2003)) { (void)(f260_ow(hr_str("&(", 2)));
(void)(f289_gx(a_2003));
(void)(f260_ow(hr_str(")", 1)));
 } else { int64_t k0_2008 = f273_tmp(d_2005, false); 
(void)(f260_ow(hr_str("(", 1)));
(void)(f274_ot(k0_2008));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f269_gxo(a_2003));
(void)(f260_ow(hr_str(", &", 3)));
(void)(f274_ot(k0_2008));
(void)(f260_ow(hr_str(")", 1)));
 }
 }
(void)(f260_ow(hr_str("; ", 2)));
 } else { (void)(f261_ct(d_2005));
(void)(f260_ow(hr_str(" _m", 3)));
(void)(f294_oi(p_2006));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(a_2003));
(void)(f260_ow(hr_str("; ", 2)));
 }
bool first_2009 = true; 
{ int32_t _e6891 = (x_2002).n_; for (int32_t _k6891 = 0; _k6891 < _e6891; _k6891++) { int32_t i_2010 = (int32_t)_k6891; int64_t arm_2011 = f90_kid(n_2000, ((int64_t)(i_2010))); 
S4 ar_2012 = (*({ hrv *_t6893 = &(g704); int64_t _i6893 = arm_2011; (S4*)_t6893->b + hr_ix(_i6893, _t6893->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:899"); })); 
if ((!(first_2009))) { (void)(f260_ow(hr_str(" else ", 6)));
 }
first_2009 = false;
if (((((uint16_t)((uint64_t)(ar_2012).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(f260_ow(hr_str("{ ", 2)));
(void)(f342_gblk(((int64_t)((ar_2012).b_)), res_2001, false));
(void)(f260_ow(hr_str(" }", 2)));
continue;
 }
(void)(f260_ow(hr_str("if (", 4)));
{ int32_t _e6900 = (ar_2012).n_; for (int32_t _k6900 = 0; _k6900 < _e6900; _k6900++) { int32_t j_2013 = (int32_t)_k6900; if (((j_2013) > (((int32_t)0LL)))) { (void)(f260_ow(hr_str(" || ", 4)));
 }
int64_t it_2014 = f90_kid(arm_2011, ((int64_t)(j_2013))); 
int64_t lo_2015 = ((int64_t)(((*({ hrv *_t6903 = &(g704); int64_t _i6903 = it_2014; (S4*)_t6903->b + hr_ix(_i6903, _t6903->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:907"); }))).a_)); 
if (isenum_2007) { (void)(({ hrv *_o6904 = &(g163); hr_fs(_o6904, hr_str("_m", 2)); hr_fi(_o6904, p_2006); hr_fs(_o6904, hr_str("->tag == ", 9)); hr_fi(_o6904, f157_rv(lo_2015)); }));
 } else { if (((((*({ hrv *_t6906 = &(g704); int64_t _i6906 = it_2014; (S4*)_t6906->b + hr_ix(_i6906, _t6906->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:910"); }))).b_) >= (((int32_t)0LL)))) { (void)(({ hrv *_o6907 = &(g163); hr_fs(_o6907, hr_str("(_m", 3)); hr_fi(_o6907, p_2006); hr_fs(_o6907, hr_str(" >= ", 4)); }));
(void)(f289_gx(lo_2015));
(void)(({ hrv *_o6909 = &(g163); hr_fs(_o6909, hr_str(" && _m", 6)); hr_fi(_o6909, p_2006); hr_fs(_o6909, hr_str(" < ", 3)); }));
(void)(f289_gx(((int64_t)(((*({ hrv *_t6911 = &(g704); int64_t _i6911 = it_2014; (S4*)_t6911->b + hr_ix(_i6911, _t6911->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:910"); }))).b_))));
(void)(f260_ow(hr_str(")", 1)));
 } else { if (((((f180_leaf_kind(d_2005)) == (((int64_t)0LL))) && ((((*({ hrv *_t6914 = &(g551); int64_t _i6914 = d_2005; (S1*)_t6914->b + hr_ix(_i6914, _t6914->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:911"); }))).k_) != (((uint8_t)3LL)))) && ((((*({ hrv *_t6915 = &(g551); int64_t _i6915 = d_2005; (S1*)_t6915->b + hr_ix(_i6915, _t6915->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:911"); }))).k_) != (((uint8_t)2LL))))) { (void)(f260_ow(hr_str("heq", 3)));
(void)(f294_oi(d_2005));
(void)(({ hrv *_o6918 = &(g163); hr_fs(_o6918, hr_str("(_m", 3)); hr_fi(_o6918, p_2006); hr_fs(_o6918, hr_str(", ", 2)); }));
(void)(f289_gx(lo_2015));
(void)(f260_ow(hr_str(")", 1)));
(void)(f295_gen_heq(d_2005));
 } else { (void)(({ hrv *_o6922 = &(g163); hr_fs(_o6922, hr_str("_m", 2)); hr_fi(_o6922, p_2006); hr_fs(_o6922, hr_str(" == ", 4)); }));
(void)(f289_gx(lo_2015));
 }
 }
 }
 } } _bk6899:; 
(void)(f260_ow(hr_str(") { ", 4)));
if (((((ar_2012).s_) >= (((int32_t)0LL))) && isenum_2007)) { int64_t v_2016 = f157_rv(arm_2011); 
int64_t vi_2017 = f157_rv(((int64_t)(((*({ hrv *_t6927 = &(g704); int64_t _i6927 = f90_kid(arm_2011, ((int64_t)0LL)); (S4*)_t6927->b + hr_ix(_i6927, _t6927->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:917"); }))).a_))); 
int64_t lt_2018 = ((int64_t)(((*({ hrv *_t6929 = &(g389); int64_t _i6929 = v_2016; (S12*)_t6929->b + hr_ix(_i6929, _t6929->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:918"); }))).ty_)); 
int64_t vt_2019 = f179_deref(lt_2018); 
int64_t ei_2020 = ((int64_t)(((*({ hrv *_t6931 = &(g551); int64_t _i6931 = d_2005; (S1*)_t6931->b + hr_ix(_i6931, _t6931->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:920"); }))).a_)); 
S9 vv_2021 = (*({ hrv *_t6932 = &(g557); int64_t _i6932 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t6933 = &(g556); int64_t _i6933 = ei_2020; (S8*)_t6933->b + hr_ix(_i6933, _t6933->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:921"); }))).v0_)) + (int64_t)vi_2017)); (S9*)_t6932->b + hr_ix(_i6932, _t6932->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:921"); })); 
bool has_2022 = ((((vv_2021).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t6934 = &(g554); int64_t _i6934 = (vv_2021).si_; (S10*)_t6934->b + hr_ix(_i6934, _t6934->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:922"); }))).zero_))); 
(void)(f261_ct(lt_2018));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f286_lv_name(v_2016));
(void)(f260_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t6939 = &(g551); int64_t _i6939 = lt_2018; (S1*)_t6939->b + hr_ix(_i6939, _t6939->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:924"); }))).k_) == (((uint8_t)10LL)))) { if (has_2022) { (void)(({ hrv *_o6940 = &(g163); hr_fs(_o6940, hr_str("&_m", 3)); hr_fi(_o6940, p_2006); hr_fs(_o6940, hr_str("->u.v", 5)); hr_fi(_o6940, vi_2017); hr_fs(_o6940, hr_str("; ", 2)); }));
 } else { (void)(f260_ow(hr_str("0; ", 3)));
 }
 } else { if (has_2022) { (void)(({ hrv *_o6942 = &(g163); hr_fs(_o6942, hr_str("_m", 2)); hr_fi(_o6942, p_2006); hr_fs(_o6942, hr_str("->u.v", 5)); hr_fi(_o6942, vi_2017); hr_fs(_o6942, hr_str("; ", 2)); }));
 } else { (void)(f260_ow(hr_str("0; ", 3)));
 }
 }
 }
(void)(f342_gblk(((int64_t)((ar_2012).b_)), res_2001, false));
(void)(f260_ow(hr_str(" }", 2)));
 } } _bk6890:; 
(void)(f260_ow(hr_str(" }", 2)));
}
static void f350_geblock(int64_t n_2023, int64_t res_2024) {
int64_t l_2025 = f345_lbl_push(res_2024); 
(void)(f260_ow(hr_str("{ ", 2)));
(void)(f342_gblk(((int64_t)(((*({ hrv *_t6950 = &(g704); int64_t _i6950 = n_2023; (S4*)_t6950->b + hr_ix(_i6950, _t6950->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:836"); }))).a_)), res_2024, false));
(void)(f260_ow(hr_str(" }", 2)));
(void)(f346_lbl_pop(l_2025));
}
static void f351_gret(int64_t n_2026) {
S4 x_2027 = (*({ hrv *_t6953 = &(g704); int64_t _i6953 = n_2026; (S4*)_t6953->b + hr_ix(_i6953, _t6953->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1017"); })); 
int64_t lt_2028 = f217_ax(n_2026); 
if ((((lt_2028) >= (((int64_t)0LL))) && ((lt_2028) != (g179)))) { int64_t rt0_2029 = ((int64_t)(((*({ hrv *_t6955 = &(g388); int64_t _i6955 = lt_2028; (S6*)_t6955->b + hr_ix(_i6955, _t6955->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1020"); }))).ret_)); 
(void)(f260_ow(hr_str("{ ", 2)));
if ((((x_2027).n_) > (((int32_t)1LL)))) { (void)(({ hrv *_o6957 = &(g163); hr_fs(_o6957, hr_str("_lrv", 4)); hr_fi(_o6957, lt_2028); hr_fs(_o6957, hr_str(" = (", 4)); }));
(void)(f261_ct(rt0_2029));
(void)(f260_ow(hr_str("){ ", 3)));
{ int32_t _e6961 = (x_2027).n_; for (int32_t _k6961 = 0; _k6961 < _e6961; _k6961++) { int32_t i_2030 = (int32_t)_k6961; if (((i_2030) > (((int32_t)0LL)))) { (void)(f260_ow(hr_str(", ", 2)));
 }
int64_t c_2031 = f90_kid(n_2026, ((int64_t)(i_2030))); 
if (f268_is_res(f279_fin(c_2031))) { (void)(f352_gmove(c_2031));
 } else { (void)(f289_gx(c_2031));
 }
 } } _bk6960:; 
(void)(f260_ow(hr_str(" }; ", 4)));
 } else { if ((((x_2027).n_) == (((int32_t)1LL)))) { (void)(({ hrv *_o6969 = &(g163); hr_fs(_o6969, hr_str("_lrv", 4)); hr_fi(_o6969, lt_2028); hr_fs(_o6969, hr_str(" = ", 3)); }));
int64_t c_2037 = f90_kid(n_2026, ((int64_t)0LL)); 
if (f268_is_res(rt0_2029)) { (void)(f352_gmove(c_2037));
 } else { (void)(f289_gx(c_2037));
 }
(void)(f260_ow(hr_str("; ", 2)));
 }
 }
(void)(({ hrv *_o6975 = &(g163); hr_fs(_o6975, hr_str("hr_lr = ", 8)); hr_fi(_o6975, ((int64_t)((int64_t)lt_2028 + (int64_t)((int64_t)1LL)))); hr_fs(_o6975, hr_str("; ", 2)); }));
(void)(f354_gdummy());
(void)(f260_ow(hr_str(" }", 2)));
return;
 }
if ((((x_2027).n_) == (((int32_t)0LL)))) { (void)(f260_ow(hr_str("return;", 7)));
return;
 }
int64_t f_2039 = ({ int64_t _r6979; if (((lt_2028) >= (((int64_t)0LL)))) { _r6979 = lt_2028;  } else { _r6979 = f221_ret_fn();  } _r6979; }); 
int64_t rt_2040 = ((int64_t)(((*({ hrv *_t6981 = &(g388); int64_t _i6981 = f_2039; (S6*)_t6981->b + hr_ix(_i6981, _t6981->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1029"); }))).ret_)); 
if ((((x_2027).n_) > (((int32_t)1LL)))) { (void)(f260_ow(hr_str("return (", 8)));
(void)(f261_ct(rt_2040));
(void)(f260_ow(hr_str("){ ", 3)));
{ int32_t _e6986 = (x_2027).n_; for (int32_t _k6986 = 0; _k6986 < _e6986; _k6986++) { int32_t i_2041 = (int32_t)_k6986; if (((i_2041) > (((int32_t)0LL)))) { (void)(f260_ow(hr_str(", ", 2)));
 }
int64_t c_2042 = f90_kid(n_2026, ((int64_t)(i_2041))); 
if (f268_is_res(f279_fin(c_2042))) { (void)(f352_gmove(c_2042));
 } else { (void)(f289_gx(c_2042));
 }
 } } _bk6985:; 
(void)(f260_ow(hr_str(" };", 3)));
return;
 }
int64_t c_2043 = f90_kid(n_2026, ((int64_t)0LL)); 
(void)(f260_ow(hr_str("return ", 7)));
if (f268_is_res(rt_2040)) { (void)(f352_gmove(c_2043));
 } else { (void)(f289_gx(c_2043));
 }
(void)(f260_ow(hr_str(";", 1)));
}
static void f352_gmove(int64_t c_2032) {
if (f353_movable_local(c_2032)) { int64_t v_2035 = f157_rv(c_2032); 
int64_t p_2036 = f293_nt(); 
(void)(f260_ow(hr_str("({ hrv _mv", 10)));
(void)(f294_oi(p_2036));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f286_lv_name(v_2035));
(void)(f260_ow(hr_str("; ", 2)));
(void)(f286_lv_name(v_2035));
(void)(f260_ow(hr_str(".b = 0; ", 8)));
(void)(f286_lv_name(v_2035));
(void)(({ hrv *_o7011 = &(g163); hr_fs(_o7011, hr_str(".n = 0; _mv", 11)); hr_fi(_o7011, p_2036); hr_fs(_o7011, hr_str("; })", 4)); }));
return;
 }
(void)(f269_gxo(c_2032));
}
static bool f353_movable_local(int64_t c_2033) {
if ((((((*({ hrv *_t7013 = &(g704); int64_t _i7013 = c_2033; (S4*)_t7013->b + hr_ix(_i7013, _t7013->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1011"); }))).k_) != (((uint8_t)8LL))) || ((f156_rk(c_2033)) != (((int64_t)1LL))))) { return false;
 }
int64_t v_2034 = f157_rv(c_2033); 
return (((((((int64_t)(((*({ hrv *_t7016 = &(g389); int64_t _i7016 = v_2034; (S12*)_t7016->b + hr_ix(_i7016, _t7016->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1011"); }))).cfn_))) == (g179)) && (!(f285_lv_isptr(v_2034)))) && ((((*({ hrv *_t7018 = &(g551); int64_t _i7018 = ((*({ hrv *_t7019 = &(g389); int64_t _i7019 = v_2034; (S12*)_t7019->b + hr_ix(_i7019, _t7019->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1011"); }))).ty_; (S1*)_t7018->b + hr_ix(_i7018, _t7018->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1011"); }))).k_) != (((uint8_t)10LL)))) && (((f150_cv(c_2033)) < (((int64_t)0LL))) || ((f150_cv(c_2033)) == (f141_at(c_2033)))));
}
static void f354_gdummy(void) {
int64_t rt_2038 = ((int64_t)(((*({ hrv *_t7023 = &(g388); int64_t _i7023 = g179; (S6*)_t7023->b + hr_ix(_i7023, _t7023->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1005"); }))).ret_)); 
if ((((rt_2038) < (((int64_t)0LL))) || ((rt_2038) == (g558)))) { (void)(f260_ow(hr_str("return;", 7)));
return;
 }
(void)(f260_ow(hr_str("{ ", 2)));
(void)(f261_ct(rt_2038));
(void)(f260_ow(hr_str(" _z; memset(&_z, 0, sizeof _z); return _z; }", 44)));
}
static void f355_gbreak(int64_t n_2044) {
S4 x_2045 = (*({ hrv *_t7028 = &(g704); int64_t _i7028 = n_2044; (S4*)_t7028->b + hr_ix(_i7028, _t7028->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1035"); })); 
if ((((g180).n) == (((int64_t)0LL)))) { (void)(f287_gerr(n_2044, hr_str("break outside a loop", 20)));
return;
 }
int64_t l_2046 = ((int64_t)((*({ hrv *_t7030 = &(g180); int64_t _i7030 = ((int64_t)((int64_t)(g180).n - (int64_t)((int64_t)1LL))); (int32_t*)_t7030->b + hr_ix(_i7030, _t7030->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1037"); })))); 
int64_t r_2047 = ((int64_t)((*({ hrv *_t7031 = &(g181); int64_t _i7031 = ((int64_t)((int64_t)(g181).n - (int64_t)((int64_t)1LL))); (int32_t*)_t7031->b + hr_ix(_i7031, _t7031->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1038"); })))); 
(void)(f260_ow(hr_str("{ ", 2)));
if ((((x_2045).a_) >= (((int32_t)0LL)))) { if (((r_2047) >= (((int64_t)0LL)))) { (void)(f260_ow(hr_str("_r", 2)));
(void)(f294_oi(r_2047));
(void)(f260_ow(hr_str(" = ", 3)));
(void)(f289_gx(((int64_t)((x_2045).a_))));
(void)(f260_ow(hr_str("; ", 2)));
 } else { (void)(f260_ow(hr_str("(void)(", 7)));
(void)(f289_gx(((int64_t)((x_2045).a_))));
(void)(f260_ow(hr_str("); ", 3)));
 }
 }
(void)(({ hrv *_o7041 = &(g163); hr_fs(_o7041, hr_str("goto _bk", 8)); hr_fi(_o7041, l_2046); hr_fs(_o7041, hr_str("; }", 3)); }));
}
static bool f356_owned(int64_t n_2048) {
return (f268_is_res(f279_fin(n_2048)) && (!(f272_is_place(n_2048))));
}
static bool f357_is_ext(int64_t i_2052) {
return ((((uint16_t)((uint64_t)((*({ hrv *_t7045 = &(g704); int64_t _i7045 = ((*({ hrv *_t7046 = &(g388); int64_t _i7046 = i_2052; (S6*)_t7046->b + hr_ix(_i7046, _t7046->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:581"); }))).node_; (S4*)_t7045->b + hr_ix(_i7045, _t7045->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:581"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)));
}
static void f358_ext_name(int64_t i_2057) {
int64_t node_2058 = ((int64_t)(((*({ hrv *_t7047 = &(g388); int64_t _i7047 = i_2057; (S6*)_t7047->b + hr_ix(_i7047, _t7047->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:576"); }))).node_)); 
int64_t x_2059 = ((int64_t)(((*({ hrv *_t7048 = &(g704); int64_t _i7048 = node_2058; (S4*)_t7048->b + hr_ix(_i7048, _t7048->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:577"); }))).e_)); 
if ((((x_2059) >= (((int64_t)0LL))) && ((((*({ hrv *_t7049 = &(g704); int64_t _i7049 = x_2059; (S4*)_t7049->b + hr_ix(_i7049, _t7049->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:578"); }))).a_) >= (((int32_t)0LL))))) { hsl s_2060 = f280_tok_str(((int64_t)(((*({ hrv *_t7051 = &(g704); int64_t _i7051 = x_2059; (S4*)_t7051->b + hr_ix(_i7051, _t7051->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:578"); }))).a_))); 
if (((((((s_2060).n) > (((int64_t)3LL))) && (((*({ hsl _t7052 = s_2060; int64_t _i7052 = ((int64_t)0LL); (uint8_t*)_t7052.p + hr_ix(_i7052, _t7052.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:578"); }))) == (((uint8_t)103LL)))) && (((*({ hsl _t7053 = s_2060; int64_t _i7053 = ((int64_t)1LL); (uint8_t*)_t7053.p + hr_ix(_i7053, _t7053.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:578"); }))) == (((uint8_t)115LL)))) && (((*({ hsl _t7054 = s_2060; int64_t _i7054 = ((int64_t)2LL); (uint8_t*)_t7054.p + hr_ix(_i7054, _t7054.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:578"); }))) == (((uint8_t)95LL))))) { (void)(f260_ow(hr_str("hr_", 3)));
(void)(f260_ow(({ hsl _t7057 = s_2060; int64_t _l7057 = ((int64_t)3LL), _h7057 = _t7057.n; if (_l7057 < 0 || _h7057 < _l7057 || _h7057 > _t7057.n) hr_slerr(_l7057, _h7057, _t7057.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:578"); (hsl){ _t7057.p + _l7057 * (int64_t)sizeof(uint8_t), _h7057 - _l7057 }; })));
return;
 }
(void)(f260_ow(s_2060));
return;
 }
(void)(f260_ow(f10_nm(((int64_t)(((*({ hrv *_t7061 = &(g704); int64_t _i7061 = node_2058; (S4*)_t7061->b + hr_ix(_i7061, _t7061->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:579"); }))).s_)))));
}
static void f359_gcall_args(int64_t n_2061, int64_t inst_2062, int64_t recv_2063) {
S4 x_2064 = (*({ hrv *_t7062 = &(g704); int64_t _i7062 = n_2061; (S4*)_t7062->b + hr_ix(_i7062, _t7062->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:583"); })); 
int64_t np_2065 = ((int64_t)(((*({ hrv *_t7063 = &(g704); int64_t _i7063 = ((*({ hrv *_t7064 = &(g388); int64_t _i7064 = inst_2062; (S6*)_t7064->b + hr_ix(_i7064, _t7064->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:584"); }))).node_; (S4*)_t7063->b + hr_ix(_i7063, _t7063->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:584"); }))).n_)); 
int64_t na_2066 = ((int64_t)((int64_t)((int64_t)((x_2064).n_)) + (int64_t)({ int64_t _r7065; if (((recv_2063) >= (((int64_t)0LL)))) { _r7065 = ((int64_t)1LL);  } else { _r7065 = ((int64_t)0LL);  } _r7065; }))); 
bool first_2067 = true; 
{ int64_t _e7067 = np_2065; for (int64_t _k7067 = 0; _k7067 < _e7067; _k7067++) { int64_t j_2068 = (int64_t)_k7067; int64_t pt_2069 = f208_ptype_of(inst_2062, j_2068); 
if ((!(first_2067))) { (void)(f260_ow(hr_str(", ", 2)));
 }
first_2067 = false;
if (((j_2068) >= (na_2066))) { int64_t p_2070 = f90_kid(((int64_t)(((*({ hrv *_t7071 = &(g388); int64_t _i7071 = inst_2062; (S6*)_t7071->b + hr_ix(_i7071, _t7071->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:592"); }))).node_)), j_2068); 
int64_t sa_2071 = g401; 
g401 = inst_2062;
(void)(f289_gx(((int64_t)(((*({ hrv *_t7073 = &(g704); int64_t _i7073 = p_2070; (S4*)_t7073->b + hr_ix(_i7073, _t7073->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:593"); }))).b_))));
g401 = sa_2071;
continue;
 }
int64_t c_2072 = ({ int64_t _r7074; if (((recv_2063) >= (((int64_t)0LL)))) { _r7074 = ({ int64_t _r7075; if (((j_2068) == (((int64_t)0LL)))) { _r7075 = recv_2063;  } else { _r7075 = f90_kid(n_2061, ((int64_t)((int64_t)j_2068 - (int64_t)((int64_t)1LL))));  } _r7075; });  } else { _r7074 = f90_kid(n_2061, j_2068);  } _r7074; }); 
int64_t ct0_2073 = f279_fin(c_2072); 
if ((((((*({ hrv *_t7079 = &(g551); int64_t _i7079 = pt_2069; (S1*)_t7079->b + hr_ix(_i7079, _t7079->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:598"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t7080 = &(g551); int64_t _i7080 = pt_2069; (S1*)_t7080->b + hr_ix(_i7080, _t7080->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:598"); }))).c_) < (((int32_t)0LL))))) { if ((((((*({ hrv *_t7081 = &(g551); int64_t _i7081 = ct0_2073; (S1*)_t7081->b + hr_ix(_i7081, _t7081->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:599"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t7082 = &(g551); int64_t _i7082 = ct0_2073; (S1*)_t7082->b + hr_ix(_i7082, _t7082->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:599"); }))).k_) == (((uint8_t)11LL))))) { (void)(f289_gx(c_2072));
 } else { (void)(f324_gaddr(c_2072));
 }
continue;
 }
if (f268_is_res(pt_2069)) { (void)(f269_gxo(c_2072));
continue;
 }
if (((((*({ hrv *_t7087 = &(g551); int64_t _i7087 = pt_2069; (S1*)_t7087->b + hr_ix(_i7087, _t7087->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:603"); }))).k_) == (((uint8_t)9LL)))) { (void)(f291_gas(c_2072));
continue;
 }
(void)(f289_gx(c_2072));
 } } _bk7066:; 
{ hrv *_v7091 = &(g392); for (int64_t _k7091 = 0; _k7091 < _v7091->n; _k7091++) { S13 cp_2074 = ((S13*)_v7091->b)[_k7091]; if (((((int64_t)((cp_2074).inst_))) == (inst_2062))) { if ((!(first_2067))) { (void)(f260_ow(hr_str(", ", 2)));
 }
first_2067 = false;
(void)(f360_lv_addr(((int64_t)((cp_2074).lv_))));
 }
 } } _bk7090:; 
}
static void f360_lv_addr(int64_t v_2075) {
if (((((int64_t)(((*({ hrv *_t7094 = &(g389); int64_t _i7094 = v_2075; (S12*)_t7094->b + hr_ix(_i7094, _t7094->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:119"); }))).cfn_))) != (g179))) { (void)(({ hrv *_o7095 = &(g163); hr_fs(_o7095, hr_str("c", 1)); hr_fi(_o7095, v_2075); }));
return;
 }
(void)(f260_ow(hr_str("&", 1)));
(void)(f286_lv_name(v_2075));
}
static void f361_glrcheck(void) {
(void)(f260_ow(hr_str("if (HR_UNLIKELY(hr_lr)) { ", 26)));
if (((*({ hrv *_t7099 = &(g388); int64_t _i7099 = g179; (S6*)_t7099->b + hr_ix(_i7099, _t7099->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1008"); }))).tg_) { int64_t rt_2076 = ((int64_t)(((*({ hrv *_t7100 = &(g388); int64_t _i7100 = g179; (S6*)_t7100->b + hr_ix(_i7100, _t7100->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1008"); }))).ret_)); 
(void)(({ hrv *_o7101 = &(g163); hr_fs(_o7101, hr_str("if (hr_lr == ", 13)); hr_fi(_o7101, ((int64_t)((int64_t)g179 + (int64_t)((int64_t)1LL)))); hr_fs(_o7101, hr_str(") { hr_lr = 0; ", 15)); }));
if ((((rt_2076) < (((int64_t)0LL))) || ((rt_2076) == (g558)))) { (void)(f260_ow(hr_str("return; } ", 10)));
 } else { (void)(({ hrv *_o7103 = &(g163); hr_fs(_o7103, hr_str("return _lrv", 11)); hr_fi(_o7103, g179); hr_fs(_o7103, hr_str("; } ", 4)); }));
 }
 }
(void)(f354_gdummy());
(void)(f260_ow(hr_str(" } ", 3)));
}
static void f362_gen_fn(int64_t i_2091) {
int64_t node_2092 = ((int64_t)(((*({ hrv *_t7106 = &(g388); int64_t _i7106 = i_2091; (S6*)_t7106->b + hr_ix(_i7106, _t7106->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1101"); }))).node_)); 
g401 = i_2091;
g179 = i_2091;
(void)(({ hrv *_v7107 = &(g180); _v7107->n = 0; }));
(void)(({ hrv *_v7108 = &(g181); _v7108->n = 0; }));
int64_t s0_2093 = (g163).n; 
(void)(f363_gsig(i_2091));
(void)(({ hrv *_v7110 = &(g166); hsl _s7110 = ({ hsl _t7111 = hr_sl(g163); int64_t _l7111 = s0_2093, _h7111 = _t7111.n; if (_l7111 < 0 || _h7111 < _l7111 || _h7111 > _t7111.n) hr_slerr(_l7111, _h7111, _t7111.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1106"); (hsl){ _t7111.p + _l7111 * (int64_t)sizeof(uint8_t), _h7111 - _l7111 }; }); hr_append(_v7110, _s7110.p, _s7110.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v7112 = &(g166); hsl _s7112 = hr_str(";\012", 2); hr_append(_v7112, _s7112.p, _s7112.n, sizeof(uint8_t)); }));
(void)(f260_ow(hr_str(" {\012", 3)));
{ int32_t _e7115 = ((*({ hrv *_t7116 = &(g704); int64_t _i7116 = node_2092; (S4*)_t7116->b + hr_ix(_i7116, _t7116->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1108"); }))).n_; for (int32_t _k7115 = 0; _k7115 < _e7115; _k7115++) { int32_t j_2105 = (int32_t)_k7115; int64_t p_2106 = f90_kid(node_2092, ((int64_t)(j_2105))); 
int64_t v_2107 = f157_rv(p_2106); 
if (f268_is_res(f208_ptype_of(i_2091, ((int64_t)(j_2105))))) { (void)(f260_ow(hr_str("hrv ", 4)));
(void)(f286_lv_name(v_2107));
(void)(f260_ow(hr_str(" __attribute__((cleanup(hr_rdrop))) = ", 38)));
(void)(f286_lv_name(v_2107));
(void)(f260_ow(hr_str("_in;\012", 5)));
 }
 } } _bk7114:; 
int64_t body_2108 = ((int64_t)(((*({ hrv *_t7126 = &(g704); int64_t _i7126 = node_2092; (S4*)_t7126->b + hr_ix(_i7126, _t7126->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1109"); }))).c_)); 
int64_t rt_2109 = ((int64_t)(((*({ hrv *_t7127 = &(g388); int64_t _i7127 = i_2091; (S6*)_t7127->b + hr_ix(_i7127, _t7127->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1110"); }))).ret_)); 
int64_t tl_2110 = ((int64_t)(((*({ hrv *_t7128 = &(g704); int64_t _i7128 = body_2108; (S4*)_t7128->b + hr_ix(_i7128, _t7128->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1111"); }))).a_)); 
{ int32_t _e7130 = ((*({ hrv *_t7131 = &(g704); int64_t _i7131 = body_2108; (S4*)_t7131->b + hr_ix(_i7131, _t7131->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1112"); }))).n_; for (int32_t _k7130 = 0; _k7130 < _e7130; _k7130++) { int32_t q_2111 = (int32_t)_k7130; (void)(f335_gstmt(f90_kid(body_2108, ((int64_t)(q_2111)))));
 } } _bk7129:; 
if (((tl_2110) >= (((int64_t)0LL)))) { if ((((((rt_2109) >= (((int64_t)0LL))) && ((rt_2109) != (g558))) && ((f141_at(tl_2110)) != (g558))) && (!(f209_ends(tl_2110))))) { int64_t sp_2112 = (g163).n; 
int64_t td_2113 = (g176).n; 
if ((((((*({ hrv *_t7136 = &(g551); int64_t _i7136 = rt_2109; (S1*)_t7136->b + hr_ix(_i7136, _t7136->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1116"); }))).k_) == (((uint8_t)14LL))) && ((((*({ hrv *_t7137 = &(g704); int64_t _i7137 = tl_2110; (S4*)_t7137->b + hr_ix(_i7137, _t7137->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1116"); }))).k_) == (((uint8_t)11LL))))) { (void)(f260_ow(hr_str("return ", 7)));
(void)(f289_gx(tl_2110));
(void)(f260_ow(hr_str(";\012", 2)));
 } else { (void)(f260_ow(hr_str("return ", 7)));
if (f268_is_res(rt_2109)) { (void)(f352_gmove(tl_2110));
 } else { (void)(f289_gx(tl_2110));
 }
(void)(f260_ow(hr_str(";\012", 2)));
 }
if ((((g176).n) > (td_2113))) { (void)(({ hrv *_v7146 = &(g177); _v7146->n = 0; }));
(void)(({ hrv *_v7147 = &(g177); hsl _s7147 = ({ hsl _t7148 = hr_sl(g163); int64_t _l7148 = sp_2112, _h7148 = _t7148.n; if (_l7148 < 0 || _h7148 < _l7148 || _h7148 > _t7148.n) hr_slerr(_l7148, _h7148, _t7148.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1118"); (hsl){ _t7148.p + _l7148 * (int64_t)sizeof(uint8_t), _h7148 - _l7148 }; }); hr_append(_v7147, _s7147.p, _s7147.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v7149 = &(g163); int64_t _k7149 = sp_2112; if (_k7149 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1118"); hr_resize(_v7149, _k7149, sizeof(uint8_t)); }));
(void)(f260_ow(hr_str("{ ", 2)));
(void)(({ hrv *_v7151 = &(g163); hsl _s7151 = ({ hsl _t7152 = hr_sl(g176); int64_t _l7152 = td_2113, _h7152 = _t7152.n; if (_l7152 < 0 || _h7152 < _l7152 || _h7152 > _t7152.n) hr_slerr(_l7152, _h7152, _t7152.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1118"); (hsl){ _t7152.p + _l7152 * (int64_t)sizeof(uint8_t), _h7152 - _l7152 }; }); hr_append(_v7151, _s7151.p, _s7151.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v7153 = &(g176); int64_t _k7153 = td_2113; if (_k7153 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1118"); hr_resize(_v7153, _k7153, sizeof(uint8_t)); }));
(void)(({ hrv *_v7154 = &(g163); hsl _s7154 = ({ hsl _t7155 = hr_sl(g177); int64_t _l7155 = 0, _h7155 = _t7155.n; if (_l7155 < 0 || _h7155 < _l7155 || _h7155 > _t7155.n) hr_slerr(_l7155, _h7155, _t7155.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1118"); (hsl){ _t7155.p + _l7155 * (int64_t)sizeof(uint8_t), _h7155 - _l7155 }; }); hr_append(_v7154, _s7154.p, _s7154.n, sizeof(uint8_t)); }));
(void)(f260_ow(hr_str("}\012", 2)));
 }
 } else { (void)(f335_gstmt(tl_2110));
 }
 }
(void)(f260_ow(hr_str("}\012", 2)));
}
static void f363_gsig(int64_t i_2094) {
int64_t rt_2095 = ((int64_t)(((*({ hrv *_t7159 = &(g388); int64_t _i7159 = i_2094; (S6*)_t7159->b + hr_ix(_i7159, _t7159->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1080"); }))).ret_)); 
(void)(f260_ow(hr_str("static ", 7)));
if (((rt_2095) < (((int64_t)0LL)))) { (void)(f260_ow(hr_str("void", 4)));
 } else { (void)(f261_ct(rt_2095));
 }
(void)(f260_ow(hr_str(" ", 1)));
(void)(f323_fn_cname(i_2094));
(void)(f260_ow(hr_str("(", 1)));
int64_t node_2096 = ((int64_t)(((*({ hrv *_t7166 = &(g388); int64_t _i7166 = i_2094; (S6*)_t7166->b + hr_ix(_i7166, _t7166->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1084"); }))).node_)); 
bool first_2097 = true; 
int64_t sa_2098 = g401; 
g401 = i_2094;
{ int32_t _e7168 = ((*({ hrv *_t7169 = &(g704); int64_t _i7169 = node_2096; (S4*)_t7169->b + hr_ix(_i7169, _t7169->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1087"); }))).n_; for (int32_t _k7168 = 0; _k7168 < _e7168; _k7168++) { int32_t j_2099 = (int32_t)_k7168; int64_t p_2100 = f90_kid(node_2096, ((int64_t)(j_2099))); 
int64_t v_2101 = f157_rv(p_2100); 
if ((!(first_2097))) { (void)(f260_ow(hr_str(", ", 2)));
 }
first_2097 = false;
int64_t t_2102 = f208_ptype_of(i_2094, ((int64_t)(j_2099))); 
(void)(f261_ct(t_2102));
(void)(f260_ow(hr_str(" ", 1)));
(void)(f286_lv_name(v_2101));
if (f268_is_res(t_2102)) { (void)(f260_ow(hr_str("_in", 3)));
 }
 } } _bk7167:; 
g401 = sa_2098;
{ hrv *_v7180 = &(g392); for (int64_t _k7180 = 0; _k7180 < _v7180->n; _k7180++) { S13 cp_2103 = ((S13*)_v7180->b)[_k7180]; if (((((int64_t)((cp_2103).inst_))) == (i_2094))) { if ((!(first_2097))) { (void)(f260_ow(hr_str(", ", 2)));
 }
first_2097 = false;
int64_t v_2104 = ((int64_t)((cp_2103).lv_)); 
(void)(f261_ct(((int64_t)(((*({ hrv *_t7183 = &(g389); int64_t _i7183 = v_2104; (S12*)_t7183->b + hr_ix(_i7183, _t7183->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1096"); }))).ty_))));
(void)(f260_ow(({ hsl _r7185; if (f285_lv_isptr(v_2104)) { _r7185 = hr_str(" **c", 4);  } else { _r7185 = hr_str(" *c", 3);  } _r7185; })));
(void)(f294_oi(v_2104));
 }
 } } _bk7179:; 
if (first_2097) { (void)(f260_ow(hr_str("void", 4)));
 }
(void)(f260_ow(hr_str(")", 1)));
}
static void hr_init_globals(void) {
g854 = ({ A25 _t1; _t1.e[0] = hr_str("import", 6); _t1.e[1] = hr_str("namespace", 9); _t1.e[2] = hr_str("struct", 6); _t1.e[3] = hr_str("enum", 4); _t1.e[4] = hr_str("type", 4); _t1.e[5] = hr_str("fn", 2); _t1.e[6] = hr_str("thread_fn", 9); _t1.e[7] = hr_str("export", 6); _t1.e[8] = hr_str("simd", 4); _t1.e[9] = hr_str("recursive", 9); _t1.e[10] = hr_str("let", 3); _t1.e[11] = hr_str("var", 3); _t1.e[12] = hr_str("extern", 6); _t1.e[13] = hr_str("const", 5); _t1.e[14] = hr_str("pad", 3); _t1.e[15] = hr_str("reusable", 8); _t1.e[16] = hr_str("if", 2); _t1.e[17] = hr_str("else", 4); _t1.e[18] = hr_str("while", 5); _t1.e[19] = hr_str("for", 3); _t1.e[20] = hr_str("in", 2); _t1.e[21] = hr_str("loop", 4); _t1.e[22] = hr_str("block", 5); _t1.e[23] = hr_str("guard", 5); _t1.e[24] = hr_str("match", 5); _t1.e[25] = hr_str("return", 6); _t1.e[26] = hr_str("break", 5); _t1.e[27] = hr_str("continue", 8); _t1.e[28] = hr_str("as", 2); _t1.e[29] = hr_str("true", 4); _t1.e[30] = hr_str("false", 5); _t1.e[31] = hr_str("null", 4); _t1.e[32] = hr_str("self", 4); _t1.e[33] = hr_str("bool", 4); _t1.e[34] = hr_str("varint", 6); _t1.e[35] = hr_str("i8", 2); _t1.e[36] = hr_str("i16", 3); _t1.e[37] = hr_str("i32", 3); _t1.e[38] = hr_str("i64", 3); _t1.e[39] = hr_str("u8", 2); _t1.e[40] = hr_str("u16", 3); _t1.e[41] = hr_str("u32", 3); _t1.e[42] = hr_str("u64", 3); _t1.e[43] = hr_str("f32", 3); _t1.e[44] = hr_str("f64", 3); _t1.e[45] = hr_str("int", 3); _t1.e[46] = hr_str("uint", 4); _t1.e[47] = hr_str("byte", 4); _t1.e[48] = hr_str("real", 4); _t1; });
g721 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g722 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g723 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g724 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g725 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g726 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g727 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g728 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g729 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g730 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g717 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g716 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g403 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g401 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g402 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g351 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g183 = ({ A62 _t2; _t2.e[0] = hr_str("int8_t", 6); _t2.e[1] = hr_str("int16_t", 7); _t2.e[2] = hr_str("int32_t", 7); _t2.e[3] = hr_str("int64_t", 7); _t2.e[4] = hr_str("uint8_t", 7); _t2.e[5] = hr_str("uint16_t", 8); _t2.e[6] = hr_str("uint32_t", 8); _t2.e[7] = hr_str("uint64_t", 8); _t2; });
g179 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g114 = ({ A102 _t3; _t3.e[0] = ((double)1e0); _t3.e[1] = ((double)1e1); _t3.e[2] = ((double)1e2); _t3.e[3] = ((double)1e3); _t3.e[4] = ((double)1e4); _t3.e[5] = ((double)1e5); _t3.e[6] = ((double)1e6); _t3.e[7] = ((double)1e7); _t3.e[8] = ((double)1e8); _t3.e[9] = ((double)1e9); _t3.e[10] = ((double)1e10); _t3.e[11] = ((double)1e11); _t3.e[12] = ((double)1e12); _t3.e[13] = ((double)1e13); _t3.e[14] = ((double)1e14); _t3.e[15] = ((double)1e15); _t3.e[16] = ((double)1e16); _t3.e[17] = ((double)1e17); _t3.e[18] = ((double)1e18); _t3.e[19] = ((double)1e19); _t3.e[20] = ((double)1e20); _t3.e[21] = ((double)1e21); _t3.e[22] = ((double)1e22); _t3; });
g154 = ((hrv){0});
g290 = ((int64_t)1LL);
g291 = ((int64_t)2LL);
g292 = ((int64_t)3LL);
g293 = ((int64_t)4LL);
g294 = ((int64_t)5LL);
g295 = ((int64_t)6LL);
g296 = ((int64_t)7LL);
g297 = ((int64_t)8LL);
g298 = ((int64_t)9LL);
g299 = ((int64_t)20LL);
g300 = ((int64_t)21LL);
g301 = ((int64_t)22LL);
g302 = ((int64_t)23LL);
g303 = ((int64_t)24LL);
g304 = ((int64_t)25LL);
g305 = ((int64_t)26LL);
g306 = ((int64_t)27LL);
g307 = ((int64_t)30LL);
g308 = ((int64_t)31LL);
g309 = ((int64_t)32LL);
g310 = ((int64_t)33LL);
g362 = ((int64_t)0LL);
g363 = ((int64_t)1LL);
g364 = ((int64_t)2LL);
g365 = ((int64_t)3LL);
g366 = ((int64_t)4LL);
g367 = ((int64_t)5LL);
g368 = ((int64_t)6LL);
g369 = ((int64_t)7LL);
g370 = ((int64_t)8LL);
g371 = ((int64_t)9LL);
g372 = ((int64_t)10LL);
g373 = ((int64_t)11LL);
g374 = ((int64_t)12LL);
g375 = ((int64_t)13LL);
g376 = ((int64_t)14LL);
g377 = ((int64_t)1LL);
g378 = ((int64_t)2LL);
g379 = ((int64_t)4LL);
g380 = ((int64_t)8LL);
g381 = ((int64_t)16LL);
g382 = ((int64_t)32LL);
g383 = ((int64_t)2LL);
g400 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g406 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g482 = ((int64_t)1LL);
g483 = ((int64_t)2LL);
g484 = ((int64_t)3LL);
g485 = ((int64_t)4LL);
g486 = ((int64_t)5LL);
g521 = ((int64_t)0LL);
g522 = ((int64_t)1LL);
g523 = ((int64_t)2LL);
g524 = ((int64_t)3LL);
g525 = ((int64_t)4LL);
g526 = ((int64_t)5LL);
g527 = ((int64_t)6LL);
g528 = ((int64_t)7LL);
g529 = ((int64_t)8LL);
g530 = ((int64_t)9LL);
g531 = ((int64_t)10LL);
g532 = ((int64_t)11LL);
g533 = ((int64_t)12LL);
g534 = ((int64_t)13LL);
g535 = ((int64_t)14LL);
g536 = ((int64_t)15LL);
g537 = ((int64_t)16LL);
g538 = ((int64_t)17LL);
g539 = ((int64_t)18LL);
g540 = ((int64_t)19LL);
g541 = ((int64_t)1LL);
g542 = ((int64_t)2LL);
g543 = ((int64_t)0LL);
g544 = ((int64_t)1LL);
g545 = ((int64_t)2LL);
g626 = ((int64_t)1LL);
g627 = ((int64_t)2LL);
g628 = ((int64_t)3LL);
g629 = ((int64_t)4LL);
g630 = ((int64_t)5LL);
g631 = ((int64_t)6LL);
g632 = ((int64_t)7LL);
g633 = ((int64_t)8LL);
g634 = ((int64_t)9LL);
g635 = ((int64_t)10LL);
g636 = ((int64_t)11LL);
g637 = ((int64_t)12LL);
g638 = ((int64_t)13LL);
g639 = ((int64_t)14LL);
g640 = ((int64_t)15LL);
g641 = ((int64_t)16LL);
g642 = ((int64_t)17LL);
g643 = ((int64_t)18LL);
g644 = ((int64_t)19LL);
g645 = ((int64_t)20LL);
g646 = ((int64_t)21LL);
g647 = ((int64_t)22LL);
g648 = ((int64_t)23LL);
g649 = ((int64_t)24LL);
g650 = ((int64_t)25LL);
g651 = ((int64_t)26LL);
g652 = ((int64_t)27LL);
g653 = ((int64_t)28LL);
g654 = ((int64_t)29LL);
g655 = ((int64_t)30LL);
g656 = ((int64_t)31LL);
g657 = ((int64_t)32LL);
g658 = ((int64_t)33LL);
g659 = ((int64_t)34LL);
g660 = ((int64_t)35LL);
g661 = ((int64_t)36LL);
g662 = ((int64_t)37LL);
g663 = ((int64_t)40LL);
g664 = ((int64_t)41LL);
g665 = ((int64_t)42LL);
g666 = ((int64_t)43LL);
g667 = ((int64_t)44LL);
g668 = ((int64_t)45LL);
g669 = ((int64_t)46LL);
g670 = ((int64_t)47LL);
g671 = ((int64_t)48LL);
g672 = ((int64_t)50LL);
g673 = ((int64_t)51LL);
g674 = ((int64_t)52LL);
g675 = ((int64_t)53LL);
g676 = ((int64_t)54LL);
g677 = ((int64_t)55LL);
g678 = ((int64_t)56LL);
g679 = ((int64_t)57LL);
g680 = ((int64_t)58LL);
g681 = ((int64_t)1LL);
g682 = ((int64_t)2LL);
g683 = ((int64_t)3LL);
g684 = ((int64_t)4LL);
g685 = ((int64_t)5LL);
g686 = ((int64_t)1LL);
g687 = ((int64_t)2LL);
g688 = ((int64_t)4LL);
g689 = ((int64_t)8LL);
g690 = ((int64_t)16LL);
g691 = ((int64_t)32LL);
g692 = ((int64_t)64LL);
g693 = ((int64_t)128LL);
g694 = ((int64_t)256LL);
g695 = ((int64_t)512LL);
g696 = ((int64_t)1LL);
g697 = ((int64_t)2LL);
g698 = ((int64_t)4LL);
g699 = ((int64_t)8LL);
g700 = ((int64_t)16LL);
g701 = ((int64_t)32LL);
g702 = ((int64_t)64LL);
g797 = ((int64_t)0LL);
g798 = ((int64_t)1LL);
g799 = ((int64_t)2LL);
g800 = ((int64_t)3LL);
g801 = ((int64_t)4LL);
g802 = ((int64_t)5LL);
g803 = ((int64_t)6LL);
g804 = ((int64_t)7LL);
g805 = ((int64_t)8LL);
g806 = ((int64_t)9LL);
g807 = ((int64_t)10LL);
g808 = ((int64_t)11LL);
g809 = ((int64_t)12LL);
g810 = ((int64_t)13LL);
g811 = ((int64_t)14LL);
g812 = ((int64_t)15LL);
g813 = ((int64_t)16LL);
g814 = ((int64_t)17LL);
g815 = ((int64_t)18LL);
g816 = ((int64_t)19LL);
g817 = ((int64_t)20LL);
g818 = ((int64_t)21LL);
g819 = ((int64_t)22LL);
g820 = ((int64_t)23LL);
g821 = ((int64_t)24LL);
g822 = ((int64_t)25LL);
g823 = ((int64_t)26LL);
g824 = ((int64_t)27LL);
g825 = ((int64_t)28LL);
g826 = ((int64_t)29LL);
g827 = ((int64_t)30LL);
g828 = ((int64_t)31LL);
g829 = ((int64_t)32LL);
g830 = ((int64_t)33LL);
g831 = ((int64_t)34LL);
g832 = ((int64_t)35LL);
g833 = ((int64_t)36LL);
g834 = ((int64_t)37LL);
g835 = ((int64_t)38LL);
g836 = ((int64_t)39LL);
g837 = ((int64_t)40LL);
g838 = ((int64_t)41LL);
g839 = ((int64_t)42LL);
g840 = ((int64_t)43LL);
g841 = ((int64_t)44LL);
g842 = ((int64_t)45LL);
g843 = ((int64_t)46LL);
g844 = ((int64_t)47LL);
g845 = ((int64_t)48LL);
g846 = ((int64_t)49LL);
g847 = ((int64_t)50LL);
g848 = ((int64_t)51LL);
g849 = ((int64_t)52LL);
g850 = ((int64_t)53LL);
g851 = ((int64_t)54LL);
g852 = ((int64_t)55LL);
g853 = ((int64_t)56LL);
g855 = ((int64_t)56LL);
g856 = ((int64_t)57LL);
g857 = ((int64_t)58LL);
g858 = ((int64_t)59LL);
g859 = ((int64_t)60LL);
g860 = ((int64_t)61LL);
g861 = ((int64_t)62LL);
g862 = ((int64_t)63LL);
g863 = ((int64_t)64LL);
g864 = ((int64_t)65LL);
g865 = ((int64_t)66LL);
g866 = ((int64_t)67LL);
g867 = ((int64_t)68LL);
g868 = ((int64_t)69LL);
g869 = ((int64_t)70LL);
g870 = ((int64_t)71LL);
g871 = ((int64_t)72LL);
g872 = ((int64_t)73LL);
g873 = ((int64_t)74LL);
g874 = ((int64_t)75LL);
g875 = ((int64_t)76LL);
g876 = ((int64_t)77LL);
g877 = ((int64_t)78LL);
g878 = ((int64_t)79LL);
g879 = ((int64_t)80LL);
g880 = ((int64_t)81LL);
g881 = ((int64_t)82LL);
g882 = ((int64_t)83LL);
g883 = ((int64_t)84LL);
g884 = ((int64_t)85LL);
g885 = ((int64_t)86LL);
g886 = ((int64_t)87LL);
g887 = ((int64_t)88LL);
g888 = ((int64_t)89LL);
g889 = ((int64_t)90LL);
g890 = ((int64_t)91LL);
g891 = ((int64_t)92LL);
g892 = ((int64_t)93LL);
g893 = ((int64_t)94LL);
g894 = ((int64_t)95LL);
g895 = ((int64_t)96LL);
g896 = ((int64_t)97LL);
g897 = ((int64_t)98LL);
g898 = ((int64_t)99LL);
g899 = ((int64_t)100LL);
g900 = ((int64_t)101LL);
g901 = ((int64_t)102LL);
g902 = ((int64_t)103LL);
g903 = ((int64_t)104LL);
g904 = ((int64_t)49LL);
}
static void hr_main(void) { f1_main(); }
