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
static void f142_conv_tail(int64_t n_688, int64_t t_689);
static bool f143_ends(int64_t n_692);
static bool f144_has_break(int64_t n_695);
static void f145_set_cv(int64_t n_703, int64_t t_704);
static int64_t f146_tclass(int64_t t_705);
static void f147_si_layout(int64_t si_708);
static bool f148_tflat(int64_t t_718);
static void f149_ei_layout(int64_t ei_721);
static int64_t f150_pad_align(int64_t t_737);
static int64_t f151_isz(int64_t s_740);
static int64_t f152_tsize(int64_t t_743);
static int64_t f153_cv(int64_t n_752);
static bool f154_conv_ok(int64_t f_753, int64_t t_754, int64_t n_755);
static bool f155_widens(int64_t f_758, int64_t t_759);
static bool f156_is_signed(int64_t t_762);
static int64_t f157_ibits(int64_t t_765);
static M78 f158_cval(int64_t n_766);
static int64_t f159_rk(int64_t n_772);
static int64_t f160_rv(int64_t n_773);
static bool f161_int_fits(int64_t v_784, bool uns_785, int64_t t_786);
static int64_t f162_int_min(int64_t t_787);
static uint64_t f163_int_max_u(int64_t t_789);
static hrv f164_tn(int64_t t_793);
static void f165_commit(int64_t n_794, int64_t t_795);
static bool f166_is_pending(int64_t t_799);
static bool f167_is_byte_arr(int64_t t_805);
static bool f168_is_opt(int64_t t_808);
static int64_t f169_ck_id(int64_t n_809, int64_t want_810);
static int64_t f170_find_lv(int64_t name_812);
static bool f171_visible(int64_t own_815);
static bool f172_visible_in(int64_t own_816, int64_t cur_817);
static void f173_set_r(int64_t n_820, int64_t k_821, int64_t v_822);
static void f174_note_cap(int64_t v_824);
static bool f175_add_cap_one(int64_t cf_827, int64_t v_828);
static int64_t f176_const_of(int64_t d_833);
static bool f177_all_int(int64_t n_841);
static void f178_set_x(int64_t n_846, int64_t v_847);
static int64_t f179_ck_bin(int64_t n_849, int64_t want_850);
static void f180_narrow_push(int64_t c_856);
static void f181_narrow_pop(int64_t m_861);
static int64_t f182_deref(int64_t t_868);
static int64_t f183_leaf_kind(int64_t t_873);
static int64_t f184_leaf_type(int64_t t_883);
static int64_t f185_unify(int64_t n_892, int64_t a_893, int64_t b_894);
static int64_t f186_ck_un(int64_t n_906, int64_t want_907);
static int64_t f187_default_t(int64_t n_912);
static int64_t f188_ck_dot(int64_t n_933, int64_t want_934);
static int64_t f189_rtype_name_enum(int64_t de_940);
static int64_t f190_sfield(int64_t si_952, int64_t name_953);
static int64_t f191_decode_rel(int64_t ft_957);
static int64_t f192_ck_idx(int64_t n_961, int64_t want_962);
static int64_t f193_ck_slice(int64_t n_970, int64_t want_971);
static int64_t f194_ck_as(int64_t n_977, int64_t want_978);
static int64_t f195_ck_arr(int64_t n_983, int64_t want_984);
static int64_t f196_ck_block(int64_t n_992, int64_t want_993);
static int64_t f197_pre_decl_block_fns(int64_t b_997);
static void f198_sig_inst(int64_t i_1002);
static int64_t f199_upname(int64_t p_1012);
static int64_t f200_tlist(int64_t k_1018, hsl xs_1019, int64_t a_1020);
static bool f201_surely_void(int64_t fnode_1022);
static bool f202_tail_void(int64_t tl_1025);
static bool f203_has_valret(int64_t n_1028);
static void f204_cstmt(int64_t n_1034);
static void f205_ck_vdecl(int64_t n_1037);
static int64_t f206_fin_t(int64_t n_1050);
static int64_t f207_add_lv(int64_t name_1052, int64_t t_1053, int64_t fl_1054, int64_t node_1055);
static bool f208_is_fixed(int64_t t_1063);
static void f209_ck_assign(int64_t n_1065);
static void f210_decl_nested(int64_t n_1082);
static void f211_check_inst(int64_t i_1085);
static int64_t f212_ptype_of(int64_t i_1091, int64_t j_1092);
static void f213_pop_block_fns(int64_t m_1114);
static int64_t f214_ck_if(int64_t n_1117, int64_t want_1118);
static int64_t f215_ck_while(int64_t n_1128);
static int64_t f216_ck_loop(int64_t n_1132, int64_t want_1133);
static int64_t f217_ck_for(int64_t n_1135);
static bool f218_is_bytes(int64_t t_1145);
static int64_t f219_ax(int64_t n_1149);
static int64_t f220_ck_match(int64_t n_1150, int64_t want_1151);
static int64_t f221_ck_ret(int64_t n_1184);
static int64_t f222_find_from_fn(int64_t name_1186);
static int64_t f223_ret_fn(void);
static int64_t f224_ck_break(int64_t n_1199);
static int64_t f225_ck_call(int64_t n_1203, int64_t want_1204);
static int64_t f226_find_nest(int64_t name_1210);
static int64_t f227_call_nested(int64_t n_1213, int64_t nf_1214);
static int64_t f228_ck_args(int64_t n_1216, int64_t a0n_1217, int64_t first_1218);
static void f229_pop_args(int64_t s_1225);
static void f230_note_caps_of(int64_t i_1226);
static void f231_note_edge(int64_t callee_1229);
static int64_t f232_block_binding(int64_t name_1231);
static int64_t f233_blk_gen(int64_t fnode_1235);
static int64_t f234_gen_list(int64_t fnode_1236);
static bool f235_is_blockparam(int64_t fnode_1240, int64_t gname_1241);
static bool f236_mentions(int64_t t_1244, int64_t g_1245);
static int64_t f237_call_block(int64_t n_1250, int64_t inst_1251);
static int64_t f238_deref_val(int64_t a_1258);
static int64_t f239_builtin_of(hsl name_1278);
static bool f240_user_format(int64_t n_1280);
static bool f241_is_grow(int64_t t_1282);
static int64_t f242_ck_builtin(int64_t n_1283, int64_t b_1284, int64_t recv_1285, int64_t want_1286);
static int64_t f243_arg(int64_t i_1289, int64_t *c1285, int64_t *c1283);
static void f244_hook_walk(int64_t t_1295);
static int64_t f245_hook_of(int64_t t_1299);
static M94 f246_resolve(int64_t n_1303, int64_t name_1304, int64_t ns_1305, int64_t a0_1306, int64_t an_1307, int64_t blk_1308, int64_t tyargs_1309, bool report_1310);
static void f247_cands_add(int64_t name_1312, int64_t ns_1313);
static bool f248_match_ty(int64_t tn0_1342, int64_t t0_1343, int64_t g0_1344);
static int64_t f249_pend_default(int64_t a_1357);
static int64_t f250_arg_rank(int64_t n_1370, int64_t a_1371, int64_t p_1372);
static bool f251_is_construct(int64_t n_1380);
static bool f252_untyped_any(int64_t f_1383);
static bool f253_is_std_node(int64_t node_1385);
static int64_t f254_get_inst(int64_t node_1396, int64_t b0_1397, int64_t bn_1398, int64_t blk_1399, int64_t bown_1400);
static bool f255_same_binds(int64_t i_1404, int64_t b0_1405, int64_t bn_1406);
static int64_t f256_call_fn(int64_t n_1442, int64_t name_1443, int64_t recv_1444, int64_t want_1445);
static int64_t f257_member_of(hsl name_1464);
static int64_t f258_ck_slit(int64_t n_1467, int64_t want_1468);
static bool f259_ORD_HAS(int64_t d_1492);
static void f260_propagate_calls(void);
static bool f261_gen_program(hrv* out_1504);
static void f262_ow(hsl s_1508);
static void f263_ct(int64_t t_1509);
static void f264_cbody(int64_t t_1510);
static void f265_cn_grow(void);
static hsl f266_cn(int64_t t_1513);
static void f267_cn_make(int64_t t_1514);
static void f268_fwd(int64_t s0_1523);
static void f269_fname_into(hrv* b_1535, int64_t name_1536);
static bool f270_is_res(int64_t t_1556);
static void f271_gxo(int64_t n_1557);
static void f272_gcv(int64_t n_1560, int64_t f_1561, int64_t t_1562);
static void f273_gx1(int64_t n_1563);
static bool f274_is_place(int64_t n_1564);
static int64_t f275_tmp(int64_t t_1569, bool clean_1570);
static void f276_ot(int64_t k_1572);
static void f277_gx0(int64_t n_1573);
static int64_t f278_fin_lit(int64_t n_1576);
static void f279_oint(int64_t v_1578, bool uns_1579, int64_t t_1580);
static void f280_gstr(int64_t n_1583);
static int64_t f281_fin(int64_t n_1584);
static hsl f282_tok_str(int64_t t_1588);
static void f283_cstr_lit(hsl s_1592);
static bool f284_is_fix(int64_t t_1594);
static bool f285_is_lim(int64_t t_1595);
static void f286_lv_expr(int64_t v_1598);
static bool f287_lv_isptr(int64_t v_1599);
static void f288_lv_name(int64_t v_1601);
static void f289_gerr(int64_t n_1603, hsl m_1604);
static void f290_gbin(int64_t n_1606);
static void f291_gx(int64_t n_1611);
static hsl f292_cmp_op(int64_t o_1618);
static void f293_gas(int64_t n_1619);
static void f294_gsl(int64_t n_1622, int64_t f_1623);
static int64_t f295_nt(void);
static void f296_oi(int64_t v_1627);
static void f297_gen_heq(int64_t t_1633);
static void f298_comp_pre(int64_t t_1637, bool fmt_1638);
static void f299_comp_one(int64_t t_1644, bool fmt_1645);
static bool f300_need_helper(int64_t t_1647);
static void f301_gen_hf(int64_t t_1649);
static void f302_hf_pre(int64_t t_1653);
static void f303_hh(hsl s_1656);
static void f304_fn_cname_to(hrv* b_1663, int64_t i_1664);
static void f305_hf_val(int64_t t_1675, hsl e_1676);
static void f306_heq_val(int64_t t_1719, hsl a_1720, hsl b_1721);
static bool f307_hsl_ty(int64_t t_1732);
static void f308_gxas(int64_t n_1733, int64_t t_1734);
static void f309_garith(int64_t o_1737, int64_t t0_1738, int64_t a_1739, int64_t b_1740, int64_t tv_1741, int64_t loc_1742);
static void f310_gopnd(int64_t n_1748, int64_t tv_1749);
static void f311_gen_hop(int64_t t_1750, int64_t o_1751, int64_t bt_1752);
static void f312_hop_body(int64_t t_1758, int64_t o_1759, hsl r_1760, hsl a_1761, hsl b_1762, bool sc_1763);
static hsl f313_ar_op(int64_t o_1765);
static void f314_wloc(int64_t n_1779);
static void f315_gun(int64_t n_1782);
static void f316_gen_hneg(int64_t t_1787);
static void f317_gidx(int64_t n_1801);
static void f318_gslice(int64_t n_1809);
static void f319_garr(int64_t n_1817);
static void f320_gslit(int64_t n_1824);
static void f321_gcall(int64_t n_1836);
static void f322_gbuiltin(int64_t n_1838);
static int64_t f323_arg(int64_t i_1844, int64_t *c1842, int64_t *c1838);
static void f324_gfmt(hsl o_1848, int64_t n_1849, int64_t t_1850, bool top_1851);
static void f325_fn_cname(int64_t i_1856);
static void f326_gaddr(int64_t n_1857);
static void f327_grecv_ptr(int64_t r_1867);
static void f328_esz(int64_t t_1881);
static void f329_gembed(int64_t n_1888, int64_t a_1889);
static void f330_heq_val_o(int64_t e_1899, int64_t p_1900);
static void f331_heq_o(int64_t e_1903, hsl a_1904, hsl b_1905);
static void f332_heq_pre(int64_t t_1906);
static bool f333_scalar_ty(int64_t t_1907);
static void f334_heq_val_s(int64_t e_1910, int64_t p_1911);
static void f335_heq_val_r(int64_t e_1914, int64_t p_1915);
static void f336_gblkcall(int64_t n_1918);
static void f337_gstmt(int64_t n_1930);
static void f338_gvdecl(int64_t n_1936);
static void f339_decl_lv(int64_t v_1944);
static void f340_gstmt1(int64_t n_1955);
static void f341_gassign(int64_t n_1958);
static int64_t f342_base_op(int64_t o_1971);
static void f343_gif(int64_t n_1974, int64_t res_1975);
static void f344_gblk(int64_t b_1979, int64_t res_1980, bool val_1981);
static void f345_gtail(int64_t tl_1983, int64_t res_1984);
static void f346_gwhile(int64_t n_1987);
static int64_t f347_lbl_push(int64_t res_1989);
static void f348_lbl_pop(int64_t l_1992);
static void f349_gloop(int64_t n_1993, int64_t res_1994);
static void f350_gfor(int64_t n_1996);
static void f351_gmatch(int64_t n_2011, int64_t res_2012);
static void f352_geblock(int64_t n_2034, int64_t res_2035);
static void f353_gret(int64_t n_2037);
static void f354_gmove(int64_t c_2043);
static bool f355_movable_local(int64_t c_2044);
static void f356_gdummy(void);
static void f357_gbreak(int64_t n_2055);
static bool f358_owned(int64_t n_2059);
static bool f359_is_ext(int64_t i_2063);
static void f360_ext_name(int64_t i_2068);
static void f361_gcall_args(int64_t n_2072, int64_t inst_2073, int64_t recv_2074);
static void f362_lv_addr(int64_t v_2086);
static void f363_glrcheck(void);
static void f364_gen_fn(int64_t i_2102);
static void f365_gsig(int64_t i_2105);
static hrv g496;
static hrv g914;
static A25 g857;
static hrv g915;
static hrv g912;
static int64_t g724;
static int64_t g725;
static int64_t g726;
static int64_t g727;
static int64_t g728;
static int64_t g729;
static int64_t g730;
static int64_t g731;
static int64_t g732;
static int64_t g733;
static hrv g554;
static int64_t g578;
static hrv g556;
static hrv g555;
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
static int64_t g575;
static int64_t g576;
static int64_t g577;
static int64_t g580;
static int64_t g581;
static int64_t g579;
static hrv g495;
static hrv g916;
static hrv g710;
static hrv g917;
static hrv g918;
static hrv g911;
static hrv g913;
static hrv g713;
static int64_t g712;
static int64_t g720;
static int64_t g719;
static int64_t g714;
static bool g715;
static hrv g707;
static hrv g709;
static bool g759;
static hrv g721;
static hrv g708;
static bool g716;
static bool g717;
static bool g718;
static hrv g722;
static hrv g711;
static hrv g498;
static hrv g499;
static hrv g493;
static hrv g492;
static hrv g497;
static int64_t g405;
static hrv g390;
static hrv g397;
static hrv g396;
static hrv g398;
static hrv g399;
static hrv g400;
static hrv g401;
static int64_t g403;
static int64_t g404;
static int64_t g407;
static hrv g406;
static hrv g453;
static hrv g454;
static hrv g559;
static hrv g560;
static hrv g557;
static hrv g494;
static hrv g558;
static hrv g438;
static hrv g392;
static hrv g391;
static hrv g394;
static hrv g439;
static hrv g393;
static hrv g312;
static int64_t g409;
static hrv g471;
static hrv g410;
static hrv g316;
static hrv g395;
static hrv g350;
static hrv g351;
static int64_t g352;
static hrv g313;
static hrv g314;
static hrv g411;
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
static int64_t g384;
static int64_t g385;
static int64_t g402;
static int64_t g408;
static int64_t g485;
static int64_t g486;
static int64_t g487;
static int64_t g488;
static int64_t g489;
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
static int64_t g546;
static int64_t g547;
static int64_t g548;
static int64_t g621;
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
static int64_t g703;
static int64_t g704;
static int64_t g705;
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
static int64_t g854;
static int64_t g855;
static int64_t g856;
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
static int64_t g905;
static int64_t g906;
static int64_t g907;
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
(void)(({ hrv *_v15 = &(g496); hsl _s15 = hr_sl(lib_2); hr_append(_v15, _s15.p, _s15.n, sizeof(uint8_t)); }));
if ((!(f5_load_program(hr_sl(a_0))))) { (void)(({ hr_fs(&hr_ob, hr_sl(g498)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((!(f104_check_program()))) { (void)(({ hr_fs(&hr_ob, hr_sl(g406)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((((g498).n) > (((int64_t)0LL)))) { (void)(({ hr_fs(&hr_ob, hr_sl(g498)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
hrv c_1503 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(f261_gen_program((&(c_1503)))))) { (void)(({ hr_fs(&hr_ob, hr_sl(g182)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((!(hr_os_write_file(hr_sl(o_1), hr_sl(c_1503))))) { (void)(({ hr_fs(&hr_ob, hr_str("cannot write ", 13)); hr_fs(&hr_ob, hr_sl(o_1)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
}
static bool f5_load_program(hsl root_3) {
(void)(f6_parse_init());
(void)(f11_types_init());
int64_t d_38 = (root_3).n; 
while ((((d_38) > (((int64_t)0LL))) && (((*({ hsl _t34 = root_3; int64_t _i34 = ((int64_t)((int64_t)d_38 - (int64_t)((int64_t)1LL))); (uint8_t*)_t34.p + hr_ix(_i34, _t34.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:68"); }))) != (((uint8_t)47LL))))) { d_38--;
 } _bk33:; 
(void)(({ hrv *_v35 = &(g495); _v35->n = 0; }));
(void)(({ hrv *_v36 = &(g495); hsl _s36 = ({ hsl _r37; if (((d_38) > (((int64_t)0LL)))) { _r37 = ({ hsl _t38 = root_3; int64_t _l38 = 0, _h38 = ((int64_t)((int64_t)d_38 - (int64_t)((int64_t)1LL))); if (_l38 < 0 || _h38 < _l38 || _h38 > _t38.n) hr_slerr(_l38, _h38, _t38.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:69"); (hsl){ _t38.p + _l38 * (int64_t)sizeof(uint8_t), _h38 - _l38 }; });  } else { _r37 = hr_str(".", 1);  } _r37; }); hr_append(_v36, _s36.p, _s36.n, sizeof(uint8_t)); }));
return (((f19_try_load(root_3)) >= (((int64_t)0LL))) && (((g498).n) == (((int64_t)0LL))));
}
static void f6_parse_init(void) {
(void)(f7_lex_init());
if (((g724) < (((int64_t)0LL)))) { g724 = f8_intern(hr_str("from", 4));
g725 = f8_intern(hr_str("inline", 6));
g726 = f8_intern(hr_str("checkfree", 9));
g727 = f8_intern(hr_str("lut", 3));
g728 = f8_intern(hr_str("_", 1));
g729 = f8_intern(hr_str("upto", 4));
g730 = f8_intern(hr_str("fields", 6));
g731 = f8_intern(hr_str("types", 5));
g732 = f8_intern(hr_str("variants", 8));
g733 = f8_intern(hr_str("std", 3));
 }
}
static void f7_lex_init(void) {
if ((((g914).n) == (((int64_t)0LL)))) { { hsl _v52 = ({ A25 *_t53 = &(g857); (hsl){ (uint8_t*)_t53->e, 49 }; }); for (int64_t _k52 = 0; _k52 < _v52.n; _k52++) { hsl k_4 = ((hsl*)_v52.p)[_k52]; (void)(f8_intern(k_4));
 } } _bk51:; 
 }
}
static int64_t f8_intern(hsl s_5) {
if ((((g915).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v55 = &(g915); int64_t _k55 = ((int64_t)((((int64_t)1LL)) << ((((int64_t)16LL)) & 63))); if (_k55 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:32"); int32_t _x55 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o55 = _v55->n; hr_resize(_v55, _k55, sizeof _x55); for (int64_t _j = _o55; _j < _k55; _j++) ((int32_t*)_v55->b)[_j] = _x55; }));
 }
if (((((int64_t)((int64_t)(g914).n * (int64_t)((int64_t)2LL)))) >= ((g915).n))) { int64_t n_6 = ((int64_t)((int64_t)(g915).n * (int64_t)((int64_t)2LL))); 
(void)(({ hrv *_v56 = &(g915); _v56->n = 0; }));
(void)(({ hrv *_v57 = &(g915); int64_t _k57 = n_6; if (_k57 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:35"); int32_t _x57 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o57 = _v57->n; hr_resize(_v57, _k57, sizeof _x57); for (int64_t _j = _o57; _j < _k57; _j++) ((int32_t*)_v57->b)[_j] = _x57; }));
{ hrv *_v59 = &(g914); for (int64_t _k59 = 0; _k59 < _v59->n; _k59++) { S0 x_7 = ((S0*)_v59->b)[_k59]; int64_t i_8 = (int64_t)_k59; int64_t j_12 = ((int64_t)((int64_t)((int64_t)(f9_hash(({ hsl _t61 = hr_sl(g912); int64_t _l61 = ((int64_t)((x_7).s_)), _h61 = ((int64_t)(((int32_t)((int64_t)(x_7).s_ + (int64_t)(x_7).n_)))); if (_l61 < 0 || _h61 < _l61 || _h61 > _t61.n) hr_slerr(_l61, _h61, _t61.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:36"); (hsl){ _t61.p + _l61 * (int64_t)sizeof(uint8_t), _h61 - _l61 }; })))) & (int64_t)((int64_t)((int64_t)n_6 - (int64_t)((int64_t)1LL))))); 
while ((((*({ hrv *_t63 = &(g915); int64_t _i63 = j_12; (int32_t*)_t63->b + hr_ix(_i63, _t63->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:36"); }))) >= (((int32_t)0LL)))) { j_12 = ((int64_t)((int64_t)((int64_t)((int64_t)j_12 + (int64_t)((int64_t)1LL))) & (int64_t)((int64_t)((int64_t)n_6 - (int64_t)((int64_t)1LL)))));
 } _bk62:; 
{ int32_t *_t64 = &((*({ hrv *_t65 = &(g915); int64_t _i65 = j_12; (int32_t*)_t65->b + hr_ix(_i65, _t65->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:36"); }))); *_t64 = ((int32_t)(i_8)); }
 } } _bk58:; 
 }
int64_t m_13 = ((int64_t)((int64_t)(g915).n - (int64_t)((int64_t)1LL))); 
int64_t j_14 = ((int64_t)((int64_t)((int64_t)(f9_hash(s_5))) & (int64_t)m_13)); 
while ((((*({ hrv *_t68 = &(g915); int64_t _i68 = j_14; (int32_t*)_t68->b + hr_ix(_i68, _t68->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:40"); }))) >= (((int32_t)0LL)))) { if (hr_streq(f10_nm(((int64_t)((*({ hrv *_t70 = &(g915); int64_t _i70 = j_14; (int32_t*)_t70->b + hr_ix(_i70, _t70->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:40"); }))))), s_5)) { return ((int64_t)((*({ hrv *_t71 = &(g915); int64_t _i71 = j_14; (int32_t*)_t71->b + hr_ix(_i71, _t71->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:40"); }))));
 }
j_14 = ((int64_t)((int64_t)((int64_t)((int64_t)j_14 + (int64_t)((int64_t)1LL))) & (int64_t)m_13));
 } _bk67:; 
int64_t id_17 = (g914).n; 
(void)(({ hrv *_v72 = &(g914); S0 _x72 = ((S0){ .s_ = ((int32_t)((g912).n)), .n_ = ((int32_t)((s_5).n)), }); S0 *_p72 = (S0*)hr_grow(_v72, 1, sizeof _x72); *_p72 = _x72; _p72; }));
(void)(({ hrv *_v73 = &(g912); hsl _s73 = s_5; hr_append(_v73, _s73.p, _s73.n, sizeof(uint8_t)); }));
{ int32_t *_t74 = &((*({ hrv *_t75 = &(g915); int64_t _i75 = j_14; (int32_t*)_t75->b + hr_ix(_i75, _t75->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:44"); }))); *_t74 = ((int32_t)(id_17)); }
return id_17;
}
static uint64_t f9_hash(hsl s_9) {
uint64_t h_10 = ((uint64_t)1469598103934665603LL); 
{ hsl _v77 = s_9; for (int64_t _k77 = 0; _k77 < _v77.n; _k77++) { uint8_t c_11 = ((uint8_t*)_v77.p)[_k77]; h_10 = ((uint64_t)((uint64_t)((uint64_t)((uint64_t)h_10 ^ (uint64_t)((uint64_t)(c_11)))) * (uint64_t)((uint64_t)1099511628211LL)));
 } } _bk76:; 
return h_10;
}
static hsl f10_nm(int64_t id_15) {
S0 x_16 = (*({ hrv *_t78 = &(g914); int64_t _i78 = id_15; (S0*)_t78->b + hr_ix(_i78, _t78->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:29"); })); 
return ({ hsl _t79 = hr_sl(g912); int64_t _l79 = ((int64_t)((x_16).s_)), _h79 = ((int64_t)(((int32_t)((int64_t)(x_16).s_ + (int64_t)(x_16).n_)))); if (_l79 < 0 || _h79 < _l79 || _h79 > _t79.n) hr_slerr(_l79, _h79, _t79.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:29"); (hsl){ _t79.p + _l79 * (int64_t)sizeof(uint8_t), _h79 - _l79 }; });
}
static void f11_types_init(void) {
if ((((g554).n) > (((int64_t)0LL)))) { return;
 }
g578 = f12_tsimple(((int64_t)0LL), ((int64_t)0LL));
g561 = f12_tsimple(((int64_t)1LL), ((int64_t)0LL));
g562 = f12_tsimple(((int64_t)2LL), ((int64_t)0LL));
g563 = f17_t_int(((int64_t)0LL));
g564 = f17_t_int(((int64_t)1LL));
g565 = f17_t_int(((int64_t)2LL));
g566 = f17_t_int(((int64_t)3LL));
g567 = f17_t_int(((int64_t)4LL));
g568 = f17_t_int(((int64_t)5LL));
g569 = f17_t_int(((int64_t)6LL));
g570 = f17_t_int(((int64_t)7LL));
g571 = f12_tsimple(((int64_t)4LL), ((int64_t)4LL));
g572 = f12_tsimple(((int64_t)4LL), ((int64_t)8LL));
g573 = f12_tsimple(((int64_t)11LL), ((int64_t)0LL));
g574 = f12_tsimple(((int64_t)12LL), ((int64_t)0LL));
g575 = f12_tsimple(((int64_t)13LL), ((int64_t)0LL));
g576 = f12_tsimple(((int64_t)18LL), ((int64_t)0LL));
g577 = f12_tsimple(((int64_t)17LL), ((int64_t)0LL));
g580 = f12_tsimple(((int64_t)19LL), ((int64_t)0LL));
g581 = f12_tsimple(((int64_t)15LL), ((int64_t)0LL));
g579 = f18_t_slice(g567, true);
}
static int64_t f12_tsimple(int64_t k_18, int64_t s_19) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(k_18)), .s_ = ((uint8_t)(s_19)), .a_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f13_tmk(S1 t_20) {
if ((((g556).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v102 = &(g556); int64_t _k102 = ((int64_t)((((int64_t)1LL)) << ((((int64_t)14LL)) & 63))); if (_k102 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:27"); int32_t _x102 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o102 = _v102->n; hr_resize(_v102, _k102, sizeof _x102); for (int64_t _j = _o102; _j < _k102; _j++) ((int32_t*)_v102->b)[_j] = _x102; }));
 }
if (((((int64_t)((int64_t)(g554).n * (int64_t)((int64_t)2LL)))) >= ((g556).n))) { int64_t n_21 = ((int64_t)((int64_t)(g556).n * (int64_t)((int64_t)2LL))); 
(void)(({ hrv *_v103 = &(g556); _v103->n = 0; }));
(void)(({ hrv *_v104 = &(g556); int64_t _k104 = n_21; if (_k104 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:29"); int32_t _x104 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o104 = _v104->n; hr_resize(_v104, _k104, sizeof _x104); for (int64_t _j = _o104; _j < _k104; _j++) ((int32_t*)_v104->b)[_j] = _x104; }));
{ hrv *_v106 = &(g554); for (int64_t _k106 = 0; _k106 < _v106->n; _k106++) { S1 x_22 = ((S1*)_v106->b)[_k106]; int64_t i_23 = (int64_t)_k106; int64_t j_29 = ((int64_t)((int64_t)((int64_t)(f14_th(x_22))) & (int64_t)((int64_t)((int64_t)n_21 - (int64_t)((int64_t)1LL))))); 
while ((((*({ hrv *_t109 = &(g556); int64_t _i109 = j_29; (int32_t*)_t109->b + hr_ix(_i109, _t109->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:30"); }))) >= (((int32_t)0LL)))) { j_29 = ((int64_t)((int64_t)((int64_t)((int64_t)j_29 + (int64_t)((int64_t)1LL))) & (int64_t)((int64_t)((int64_t)n_21 - (int64_t)((int64_t)1LL)))));
 } _bk108:; 
{ int32_t *_t110 = &((*({ hrv *_t111 = &(g556); int64_t _i111 = j_29; (int32_t*)_t111->b + hr_ix(_i111, _t111->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:30"); }))); *_t110 = ((int32_t)(i_23)); }
 } } _bk105:; 
 }
int64_t m_30 = ((int64_t)((int64_t)(g556).n - (int64_t)((int64_t)1LL))); 
int64_t j_31 = ((int64_t)((int64_t)((int64_t)(f14_th(t_20))) & (int64_t)m_30)); 
while ((((*({ hrv *_t114 = &(g556); int64_t _i114 = j_31; (int32_t*)_t114->b + hr_ix(_i114, _t114->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); }))) >= (((int32_t)0LL)))) { if (f16_teq((*({ hrv *_t116 = &(g554); int64_t _i116 = (*({ hrv *_t117 = &(g556); int64_t _i117 = j_31; (int32_t*)_t117->b + hr_ix(_i117, _t117->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); })); (S1*)_t116->b + hr_ix(_i116, _t116->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); })), t_20)) { return ((int64_t)((*({ hrv *_t118 = &(g556); int64_t _i118 = j_31; (int32_t*)_t118->b + hr_ix(_i118, _t118->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); }))));
 }
j_31 = ((int64_t)((int64_t)((int64_t)((int64_t)j_31 + (int64_t)((int64_t)1LL))) & (int64_t)m_30));
 } _bk113:; 
(void)(({ hrv *_v119 = &(g554); S1 _x119 = t_20; S1 *_p119 = (S1*)hr_grow(_v119, 1, sizeof _x119); *_p119 = _x119; _p119; }));
{ int32_t *_t120 = &((*({ hrv *_t121 = &(g556); int64_t _i121 = j_31; (int32_t*)_t121->b + hr_ix(_i121, _t121->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:35"); }))); *_t120 = ((int32_t)(((int64_t)((int64_t)(g554).n - (int64_t)((int64_t)1LL))))); }
return ((int64_t)((int64_t)(g554).n - (int64_t)((int64_t)1LL)));
}
static uint64_t f14_th(S1 t_24) {
uint64_t h_27 = f15_hash_mix(((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((t_24).k_)) | (uint64_t)((uint64_t)((((uint64_t)((t_24).s_))) << ((((int64_t)8LL)) & 63))))) | (uint64_t)((uint64_t)((((uint64_t)((t_24).fl_))) << ((((int64_t)16LL)) & 63))))) | (uint64_t)((uint64_t)((((uint64_t)((t_24).a_))) << ((((int64_t)32LL)) & 63)))))); 
h_27 = f15_hash_mix(((uint64_t)((uint64_t)((uint64_t)((uint64_t)h_27 ^ (uint64_t)((uint64_t)((t_24).c_)))) ^ (uint64_t)((uint64_t)((((uint64_t)((t_24).b_))) << ((((int64_t)20LL)) & 63))))));
{ int32_t _e125 = (t_24).n_; for (int32_t _k125 = 0; _k125 < _e125; _k125++) { int32_t i_28 = (int32_t)_k125; h_27 = f15_hash_mix(((uint64_t)((uint64_t)h_27 ^ (uint64_t)((uint64_t)((*({ hrv *_t127 = &(g555); int64_t _i127 = ((int64_t)((int64_t)((int64_t)((t_24).l_)) + (int64_t)((int64_t)(i_28)))); (int32_t*)_t127->b + hr_ix(_i127, _t127->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:20"); })))))));
 } } _bk124:; 
return h_27;
}
static uint64_t f15_hash_mix(uint64_t x_25) {
uint64_t h_26 = ((uint64_t)((uint64_t)x_25 * (uint64_t)((uint64_t)11400714819323198485ULL))); 
h_26 = ((uint64_t)((uint64_t)h_26 ^ (uint64_t)((uint64_t)((h_26) >> ((((int64_t)32LL)) & 63)))));
return h_26;
}
static bool f16_teq(S1 x_32, S1 y_33) {
if ((((((((((x_32).k_) != ((y_33).k_)) || (((x_32).s_) != ((y_33).s_))) || (((x_32).fl_) != ((y_33).fl_))) || (((x_32).a_) != ((y_33).a_))) || (((x_32).c_) != ((y_33).c_))) || (((x_32).b_) != ((y_33).b_))) || (((x_32).n_) != ((y_33).n_)))) { return false;
 }
{ int32_t _e129 = (x_32).n_; for (int32_t _k129 = 0; _k129 < _e129; _k129++) { int32_t i_34 = (int32_t)_k129; if ((((*({ hrv *_t130 = &(g555); int64_t _i130 = ((int64_t)((int64_t)((int64_t)((x_32).l_)) + (int64_t)((int64_t)(i_34)))); (int32_t*)_t130->b + hr_ix(_i130, _t130->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:23"); }))) != ((*({ hrv *_t131 = &(g555); int64_t _i131 = ((int64_t)((int64_t)((int64_t)((y_33).l_)) + (int64_t)((int64_t)(i_34)))); (int32_t*)_t131->b + hr_ix(_i131, _t131->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:23"); }))))) { return false;
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
{ hrv *_v136 = &(g916); for (int64_t _k136 = 0; _k136 < _v136->n; _k136++) { S2 f_41 = ((S2*)_v136->b)[_k136]; int64_t i_42 = (int64_t)_k136; if (((((int64_t)((f_41).name_))) == (id_40))) { return i_42;
 }
 } } _bk135:; 
if ((!(hr_os_file_exists(path_39)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t t0_43 = (g710).n; 
if ((!(f21_parse_file(path_39)))) { (void)(({ hrv *_v139 = &(g498); hsl _s139 = hr_sl(g713); hr_append(_v139, _s139.p, _s139.n, sizeof(uint8_t)); }));
return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
int64_t f_439 = ((int64_t)((int64_t)(g916).n - (int64_t)((int64_t)1LL))); 
while ((((g499).n) < ((g916).n))) { (void)(({ hrv *_v141 = &(g499); int32_t _x141 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p141 = (int32_t*)hr_grow(_v141, 1, sizeof _x141); *_p141 = _x141; _p141; }));
 } _bk140:; 
{ int32_t *_t142 = &((*({ hrv *_t143 = &(g499); int64_t _i143 = f_439; (int32_t*)_t143->b + hr_ix(_i143, _t143->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:45"); }))); *_t142 = (*({ hrv *_t144 = &(g711); int64_t _i144 = ((int64_t)((int64_t)(g711).n - (int64_t)((int64_t)1LL))); (int32_t*)_t144->b + hr_ix(_i144, _t144->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:45"); })); }
(void)(f97_collect(f_439, t0_43, (g710).n));
int64_t t1_455 = (g710).n; 
int64_t im0_456 = (g497).n; 
{ int64_t _e147 = t1_455; for (int64_t _k147 = t0_43; _k147 < _e147; _k147++) { int64_t i_457 = (int64_t)_k147; if (((((*({ hrv *_t148 = &(g707); int64_t _i148 = (*({ hrv *_t149 = &(g710); int64_t _i149 = i_457; (int32_t*)_t149->b + hr_ix(_i149, _t149->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:49"); })); (S4*)_t148->b + hr_ix(_i148, _t148->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:49"); }))).k_) == (((uint8_t)54LL)))) { (void)(({ hrv *_v150 = &(g497); int32_t _x150 = (*({ hrv *_t151 = &(g710); int64_t _i151 = i_457; (int32_t*)_t151->b + hr_ix(_i151, _t151->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:49"); })); int32_t *_p150 = (int32_t*)hr_grow(_v150, 1, sizeof _x150); *_p150 = _x150; _p150; }));
 }
 } } _bk146:; 
int64_t im1_458 = (g497).n; 
L49 sp_461 = f100_lib_path(hr_str("std", 3)); 
bool isstd_462 = hr_streq(path_39, ({ hsl _t153 = ({ L49 *_t154 = &(sp_461); (hsl){ (uint8_t*)_t154->e, _t154->n }; }); int64_t _l153 = 0, _h153 = _t153.n; if (_l153 < 0 || _h153 < _l153 || _h153 > _t153.n) hr_slerr(_l153, _h153, _t153.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:51"); (hsl){ _t153.p + _l153 * (int64_t)sizeof(uint8_t), _h153 - _l153 }; })); 
if ((((*({ hrv *_t155 = &(g916); int64_t _i155 = f_439; (S2*)_t155->b + hr_ix(_i155, _t155->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:52"); }))).amni_ && (!(isstd_462)))) { if (((f101_load_import(g733, f_439, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
 }
{ int64_t _e158 = im1_458; for (int64_t _k158 = im0_456; _k158 < _e158; _k158++) { int64_t q_475 = (int64_t)_k158; int64_t n_476 = ((int64_t)((*({ hrv *_t159 = &(g497); int64_t _i159 = q_475; (int32_t*)_t159->b + hr_ix(_i159, _t159->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:53"); })))); 
if (((f101_load_import(((int64_t)(((*({ hrv *_t161 = &(g707); int64_t _i161 = n_476; (S4*)_t161->b + hr_ix(_i161, _t161->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:53"); }))).s_)), f_439, ((int64_t)(((*({ hrv *_t162 = &(g707); int64_t _i162 = n_476; (S4*)_t162->b + hr_ix(_i162, _t162->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:53"); }))).t_)))) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
 } } _bk157:; 
return f_439;
}
static bool f21_parse_file(hsl path_44) {
(void)(f6_parse_init());
int64_t t0_45 = (g917).n; 
if ((!(f22_lex_file(path_44)))) { (void)(({ hrv *_v165 = &(g713); hsl _s165 = hr_sl(g918); hr_append(_v165, _s165.p, _s165.n, sizeof(uint8_t)); }));
return false;
 }
g712 = t0_45;
g720 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
while ((((f31_tk()) != (((int64_t)0LL))) && (((g713).n) == (((int64_t)0LL))))) { (void)(f32_ptop());
 } _bk166:; 
(void)(({ hrv *_v169 = &(g711); int32_t _x169 = ((int32_t)(g720)); int32_t *_p169 = (int32_t*)hr_grow(_v169, 1, sizeof _x169); *_p169 = _x169; _p169; }));
return (((g713).n) == (((int64_t)0LL)));
}
static bool f22_lex_file(hsl path_46) {
(void)(f7_lex_init());
hrv body_47 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(hr_os_read_file(path_46, (&(body_47)))))) { (void)(({ hrv *_v173 = &(g918); hsl _s173 = hr_str("cannot read ", 12); hr_append(_v173, _s173.p, _s173.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v174 = &(g918); hsl _s174 = path_46; hr_append(_v174, _s174.p, _s174.n, sizeof(uint8_t)); }));
return false;
 }
int64_t f_48 = (g916).n; 
int64_t base_49 = (g911).n; 
int64_t skip_50 = ({ int64_t _r175; if (((((((body_47).n) >= (((int64_t)3LL))) && (((*({ hrv *_t176 = &(body_47); int64_t _i176 = ((int64_t)0LL); (uint8_t*)_t176->b + hr_ix(_i176, _t176->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:69"); }))) == (((uint8_t)239LL)))) && (((*({ hrv *_t177 = &(body_47); int64_t _i177 = ((int64_t)1LL); (uint8_t*)_t177->b + hr_ix(_i177, _t177->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:69"); }))) == (((uint8_t)187LL)))) && (((*({ hrv *_t178 = &(body_47); int64_t _i178 = ((int64_t)2LL); (uint8_t*)_t178->b + hr_ix(_i178, _t178->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:69"); }))) == (((uint8_t)191LL))))) { _r175 = ((int64_t)3LL);  } else { _r175 = ((int64_t)0LL);  } _r175; }); 
(void)(({ hrv *_v179 = &(g911); hsl _s179 = ({ hsl _t180 = hr_sl(body_47); int64_t _l180 = skip_50, _h180 = _t180.n; if (_l180 < 0 || _h180 < _l180 || _h180 > _t180.n) hr_slerr(_l180, _h180, _t180.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:70"); (hsl){ _t180.p + _l180 * (int64_t)sizeof(uint8_t), _h180 - _l180 }; }); hr_append(_v179, _s179.p, _s179.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v181 = &(g911); uint8_t _x181 = ((uint8_t)0LL); uint8_t *_p181 = (uint8_t*)hr_grow(_v181, 1, sizeof _x181); *_p181 = _x181; _p181; }));
(void)(({ hrv *_v182 = &(g911); uint8_t _x182 = ((uint8_t)0LL); uint8_t *_p182 = (uint8_t*)hr_grow(_v182, 1, sizeof _x182); *_p182 = _x182; _p182; }));
(void)(({ hrv *_v183 = &(g911); uint8_t _x183 = ((uint8_t)0LL); uint8_t *_p183 = (uint8_t*)hr_grow(_v183, 1, sizeof _x183); *_p183 = _x183; _p183; }));
(void)(({ hrv *_v184 = &(g911); uint8_t _x184 = ((uint8_t)0LL); uint8_t *_p184 = (uint8_t*)hr_grow(_v184, 1, sizeof _x184); *_p184 = _x184; _p184; }));
(void)(({ hrv *_v185 = &(g916); S2 _x185 = ((S2){ .s_ = ((int32_t)(base_49)), .n_ = ((int32_t)(((int64_t)((int64_t)(body_47).n - (int64_t)skip_50)))), .name_ = ((int32_t)(f8_intern(path_46))), .amni_ = ((((path_46).n) > (((int64_t)5LL))) && hr_streq(({ hsl _t187 = path_46; int64_t _l187 = _t187.n - ((int64_t)5LL), _h187 = _t187.n; if (_l187 < 0 || _h187 < _l187 || _h187 > _t187.n) hr_slerr(_l187, _h187, _t187.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:71"); (hsl){ _t187.p + _l187 * (int64_t)sizeof(uint8_t), _h187 - _l187 }; }), hr_str(".amni", 5))), }); S2 *_p185 = (S2*)hr_grow(_v185, 1, sizeof _x185); *_p185 = _x185; _p185; }));
bool amni_51 = ((*({ hrv *_t188 = &(g916); int64_t _i188 = f_48; (S2*)_t188->b + hr_ix(_i188, _t188->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:72"); }))).amni_; 
int64_t p_52 = base_49; 
int64_t line_53 = ((int64_t)1LL); 

for (;;) { uint8_t c_57 = (*({ hrv *_t190 = &(g911); int64_t _i190 = p_52; (uint8_t*)_t190->b + hr_ix(_i190, _t190->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:77"); })); 
while ((((((c_57) == (((uint8_t)32LL))) || ((c_57) == (((uint8_t)9LL)))) || ((c_57) == (((uint8_t)13LL)))) || ((c_57) == (((uint8_t)10LL))))) { if (((c_57) == (((uint8_t)10LL)))) { line_53++;
 }
p_52++;
c_57 = (*({ hrv *_t192 = &(g911); int64_t _i192 = p_52; (uint8_t*)_t192->b + hr_ix(_i192, _t192->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:78"); }));
 } _bk191:; 
if ((((c_57) == (((uint8_t)47LL))) && (((*({ hrv *_t193 = &(g911); int64_t _i193 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t193->b + hr_ix(_i193, _t193->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:79"); }))) == (((uint8_t)47LL))))) { while (((((*({ hrv *_t195 = &(g911); int64_t _i195 = p_52; (uint8_t*)_t195->b + hr_ix(_i195, _t195->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:79"); }))) != (((uint8_t)10LL))) && (((*({ hrv *_t196 = &(g911); int64_t _i196 = p_52; (uint8_t*)_t196->b + hr_ix(_i196, _t196->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:79"); }))) != (((uint8_t)0LL))))) { p_52++;
 } _bk194:; 
continue;
 }
if ((((c_57) == (((uint8_t)47LL))) && (((*({ hrv *_t197 = &(g911); int64_t _i197 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t197->b + hr_ix(_i197, _t197->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:80"); }))) == (((uint8_t)42LL))))) { { int64_t *_t198 = &(p_52); *_t198 = ((int64_t)((int64_t)(*_t198) + (int64_t)((int64_t)2LL))); }
int64_t nest_58 = ((int64_t)1LL); 
while (((nest_58) > (((int64_t)0LL)))) { uint8_t d_59 = (*({ hrv *_t200 = &(g911); int64_t _i200 = p_52; (uint8_t*)_t200->b + hr_ix(_i200, _t200->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:82"); })); 
if (((d_59) == (((uint8_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("unterminated /* comment", 23));
 }
if (((d_59) == (((uint8_t)10LL)))) { line_53++;
 }
if ((((d_59) == (((uint8_t)42LL))) && (((*({ hrv *_t202 = &(g911); int64_t _i202 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t202->b + hr_ix(_i202, _t202->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:82"); }))) == (((uint8_t)47LL))))) { nest_58--;
p_52++;
 } else { if ((((d_59) == (((uint8_t)47LL))) && (((*({ hrv *_t203 = &(g911); int64_t _i203 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t203->b + hr_ix(_i203, _t203->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:82"); }))) == (((uint8_t)42LL))))) { nest_58++;
p_52++;
 }
 }
p_52++;
 } _bk199:; 
continue;
 }
int64_t s_63 = p_52; 
uint8_t n1_64 = (*({ hrv *_t204 = &(g911); int64_t _i204 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t204->b + hr_ix(_i204, _t204->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:86"); })); 
uint8_t n2_65 = (*({ hrv *_t205 = &(g911); int64_t _i205 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t205->b + hr_ix(_i205, _t205->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:86"); })); 
if (((c_57) == (((uint8_t)0LL)))) { (void)(f23_put(((int64_t)0LL), s_63, s_63, &f_48, &line_53));
return true;
 }
if (f26_dig(c_57)) { if ((((c_57) == (((uint8_t)48LL))) && (((n1_64) == (((uint8_t)120LL))) || ((n1_64) == (((uint8_t)88LL)))))) { { int64_t *_t208 = &(p_52); *_t208 = ((int64_t)((int64_t)(*_t208) + (int64_t)((int64_t)2LL))); }
int64_t ds_67 = p_52; 
while (f27_hexd((*({ hrv *_t211 = &(g911); int64_t _i211 = p_52; (uint8_t*)_t211->b + hr_ix(_i211, _t211->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:90"); })))) { p_52++;
 } _bk209:; 
bool hf_69 = false; 
if (((((*({ hrv *_t212 = &(g911); int64_t _i212 = p_52; (uint8_t*)_t212->b + hr_ix(_i212, _t212->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:92"); }))) == (((uint8_t)46LL))) && f27_hexd((*({ hrv *_t214 = &(g911); int64_t _i214 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t214->b + hr_ix(_i214, _t214->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:92"); }))))) { hf_69 = true;
p_52++;
while (f27_hexd((*({ hrv *_t217 = &(g911); int64_t _i217 = p_52; (uint8_t*)_t217->b + hr_ix(_i217, _t217->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:92"); })))) { p_52++;
 } _bk215:; 
 }
if (((((*({ hrv *_t218 = &(g911); int64_t _i218 = p_52; (uint8_t*)_t218->b + hr_ix(_i218, _t218->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)112LL))) || (((*({ hrv *_t219 = &(g911); int64_t _i219 = p_52; (uint8_t*)_t219->b + hr_ix(_i219, _t219->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)80LL))))) { hf_69 = true;
p_52++;
if (((((*({ hrv *_t220 = &(g911); int64_t _i220 = p_52; (uint8_t*)_t220->b + hr_ix(_i220, _t220->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)43LL))) || (((*({ hrv *_t221 = &(g911); int64_t _i221 = p_52; (uint8_t*)_t221->b + hr_ix(_i221, _t221->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)45LL))))) { p_52++;
 }
while (f26_dig((*({ hrv *_t224 = &(g911); int64_t _i224 = p_52; (uint8_t*)_t224->b + hr_ix(_i224, _t224->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); })))) { p_52++;
 } _bk222:; 
 }
if (hf_69) { (void)(f23_put(((int64_t)3LL), s_63, p_52, &f_48, &line_53));
continue;
 }
if (((((int64_t)((int64_t)p_52 - (int64_t)ds_67))) > (((int64_t)16LL)))) { return f25_lerr(f_48, line_53, hr_str("hex literal too large for 64 bits", 33));
 }
uint64_t v_70 = ((uint64_t)0LL); 
{ int64_t _e228 = p_52; for (int64_t _k228 = ds_67; _k228 < _e228; _k228++) { int64_t q_71 = (int64_t)_k228; v_70 = ((uint64_t)((uint64_t)((uint64_t)((v_70) << ((((int64_t)4LL)) & 63))) | (uint64_t)((uint64_t)(f28_hexv((*({ hrv *_t230 = &(g911); int64_t _i230 = q_71; (uint8_t*)_t230->b + hr_ix(_i230, _t230->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:96"); })))))));
 } } _bk227:; 
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t232 = &(((*({ hrv *_t233 = &(g917); int64_t _i233 = ((int64_t)((int64_t)(g917).n - (int64_t)((int64_t)1LL))); (S3*)_t233->b + hr_ix(_i233, _t233->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:97"); }))).v_); *_t232 = ((int64_t)(v_70)); }
{ bool *_t234 = &(((*({ hrv *_t235 = &(g917); int64_t _i235 = ((int64_t)((int64_t)(g917).n - (int64_t)((int64_t)1LL))); (S3*)_t235->b + hr_ix(_i235, _t235->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:97"); }))).uns_); *_t234 = ((v_70) > (((uint64_t)9223372036854775807LL))); }
continue;
 }
while (f26_dig((*({ hrv *_t238 = &(g911); int64_t _i238 = p_52; (uint8_t*)_t238->b + hr_ix(_i238, _t238->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:99"); })))) { p_52++;
 } _bk236:; 
bool fl_73 = false; 
if (((((*({ hrv *_t239 = &(g911); int64_t _i239 = p_52; (uint8_t*)_t239->b + hr_ix(_i239, _t239->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:101"); }))) == (((uint8_t)46LL))) && f26_dig((*({ hrv *_t241 = &(g911); int64_t _i241 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t241->b + hr_ix(_i241, _t241->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:101"); }))))) { fl_73 = true;
p_52++;
while (f26_dig((*({ hrv *_t244 = &(g911); int64_t _i244 = p_52; (uint8_t*)_t244->b + hr_ix(_i244, _t244->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:101"); })))) { p_52++;
 } _bk242:; 
 }
if ((((((*({ hrv *_t245 = &(g911); int64_t _i245 = p_52; (uint8_t*)_t245->b + hr_ix(_i245, _t245->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)101LL))) || (((*({ hrv *_t246 = &(g911); int64_t _i246 = p_52; (uint8_t*)_t246->b + hr_ix(_i246, _t246->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)69LL)))) && (f26_dig((*({ hrv *_t248 = &(g911); int64_t _i248 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t248->b + hr_ix(_i248, _t248->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) || (((((*({ hrv *_t249 = &(g911); int64_t _i249 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t249->b + hr_ix(_i249, _t249->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)43LL))) || (((*({ hrv *_t250 = &(g911); int64_t _i250 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t250->b + hr_ix(_i250, _t250->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)45LL)))) && f26_dig((*({ hrv *_t252 = &(g911); int64_t _i252 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t252->b + hr_ix(_i252, _t252->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))))))) { fl_73 = true;
{ int64_t *_t253 = &(p_52); *_t253 = ((int64_t)((int64_t)(*_t253) + (int64_t)((int64_t)2LL))); }
while (f26_dig((*({ hrv *_t256 = &(g911); int64_t _i256 = p_52; (uint8_t*)_t256->b + hr_ix(_i256, _t256->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); })))) { p_52++;
 } _bk254:; 
 }
if (fl_73) { (void)(f23_put(((int64_t)3LL), s_63, p_52, &f_48, &line_53));
continue;
 }
uint64_t v_74 = ((uint64_t)0LL); 
{ int64_t _e259 = p_52; for (int64_t _k259 = s_63; _k259 < _e259; _k259++) { int64_t q_75 = (int64_t)_k259; uint64_t d_76 = ((uint64_t)(((uint8_t)((uint64_t)(*({ hrv *_t260 = &(g911); int64_t _i260 = q_75; (uint8_t*)_t260->b + hr_ix(_i260, _t260->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:105"); })) - (uint64_t)((uint8_t)48LL))))); 
if (((v_74) > (HR_UDIV(uint64_t, ((uint64_t)((uint64_t)((uint64_t)18446744073709551615ULL) - (uint64_t)d_76)), ((uint64_t)10LL), "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:105")))) { return f25_lerr(f_48, line_53, hr_str("integer literal too large for 64 bits", 37));
 }
v_74 = ((uint64_t)((uint64_t)((uint64_t)((uint64_t)v_74 * (uint64_t)((uint64_t)10LL))) + (uint64_t)d_76));
 } } _bk258:; 
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t263 = &(((*({ hrv *_t264 = &(g917); int64_t _i264 = ((int64_t)((int64_t)(g917).n - (int64_t)((int64_t)1LL))); (S3*)_t264->b + hr_ix(_i264, _t264->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:106"); }))).v_); *_t263 = ((int64_t)(v_74)); }
{ bool *_t265 = &(((*({ hrv *_t266 = &(g917); int64_t _i266 = ((int64_t)((int64_t)(g917).n - (int64_t)((int64_t)1LL))); (S3*)_t266->b + hr_ix(_i266, _t266->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:106"); }))).uns_); *_t265 = ((v_74) > (((uint64_t)9223372036854775807LL))); }
continue;
 }
if (f29_idc(c_57)) { while (f29_idc((*({ hrv *_t270 = &(g911); int64_t _i270 = p_52; (uint8_t*)_t270->b + hr_ix(_i270, _t270->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:109"); })))) { p_52++;
 } _bk268:; 
int64_t id_78 = f8_intern(({ hsl _t272 = hr_sl(g911); int64_t _l272 = s_63, _h272 = p_52; if (_l272 < 0 || _h272 < _l272 || _h272 > _t272.n) hr_slerr(_l272, _h272, _t272.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:110"); (hsl){ _t272.p + _l272 * (int64_t)sizeof(uint8_t), _h272 - _l272 }; })); 
int64_t k_79 = ({ int64_t _r273; if (((id_78) < (((int64_t)49LL)))) { _r273 = ((int64_t)((int64_t)((int64_t)56LL) + (int64_t)id_78));  } else { _r273 = ((int64_t)1LL);  } _r273; }); 
if (((!(amni_51)) && ((k_79) >= (((int64_t)101LL))))) { k_79 = ((int64_t)1LL);
 }
(void)(f23_put(k_79, s_63, p_52, &f_48, &line_53));
{ int64_t *_t275 = &(((*({ hrv *_t276 = &(g917); int64_t _i276 = ((int64_t)((int64_t)(g917).n - (int64_t)((int64_t)1LL))); (S3*)_t276->b + hr_ix(_i276, _t276->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:113"); }))).v_); *_t275 = id_78; }
continue;
 }
if (((c_57) == (((uint8_t)39LL)))) { p_52++;
int64_t v_86 = f30_esc((&(p_52)), f_48, line_53); 
if (((v_86) < (((int64_t)0LL)))) { return false;
 }
if ((((*({ hrv *_t278 = &(g911); int64_t _i278 = p_52; (uint8_t*)_t278->b + hr_ix(_i278, _t278->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:119"); }))) != (((uint8_t)39LL)))) { return f25_lerr(f_48, line_53, hr_str("expected closing ' of character literal", 39));
 }
p_52++;
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t281 = &(((*({ hrv *_t282 = &(g917); int64_t _i282 = ((int64_t)((int64_t)(g917).n - (int64_t)((int64_t)1LL))); (S3*)_t282->b + hr_ix(_i282, _t282->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:120"); }))).v_); *_t281 = v_86; }
continue;
 }
if (((c_57) == (((uint8_t)34LL)))) { int64_t ss_87 = (g913).n; 
bool ml_88 = false; 
if ((((n1_64) == (((uint8_t)34LL))) && ((n2_65) == (((uint8_t)34LL))))) { { int64_t *_t283 = &(p_52); *_t283 = ((int64_t)((int64_t)(*_t283) + (int64_t)((int64_t)3LL))); }
int64_t q_89 = p_52; 
while ((((((*({ hrv *_t285 = &(g911); int64_t _i285 = q_89; (uint8_t*)_t285->b + hr_ix(_i285, _t285->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:127"); }))) == (((uint8_t)32LL))) || (((*({ hrv *_t286 = &(g911); int64_t _i286 = q_89; (uint8_t*)_t286->b + hr_ix(_i286, _t286->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:127"); }))) == (((uint8_t)9LL)))) || (((*({ hrv *_t287 = &(g911); int64_t _i287 = q_89; (uint8_t*)_t287->b + hr_ix(_i287, _t287->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:127"); }))) == (((uint8_t)13LL))))) { q_89++;
 } _bk284:; 
if ((((*({ hrv *_t288 = &(g911); int64_t _i288 = q_89; (uint8_t*)_t288->b + hr_ix(_i288, _t288->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:128"); }))) != (((uint8_t)10LL)))) { while ((!((((((*({ hrv *_t290 = &(g911); int64_t _i290 = p_52; (uint8_t*)_t290->b + hr_ix(_i290, _t290->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)34LL))) && (((*({ hrv *_t291 = &(g911); int64_t _i291 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t291->b + hr_ix(_i291, _t291->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)34LL)))) && (((*({ hrv *_t292 = &(g911); int64_t _i292 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t292->b + hr_ix(_i292, _t292->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)34LL))))))) { if (((((*({ hrv *_t293 = &(g911); int64_t _i293 = p_52; (uint8_t*)_t293->b + hr_ix(_i293, _t293->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)0LL))) || (((*({ hrv *_t294 = &(g911); int64_t _i294 = p_52; (uint8_t*)_t294->b + hr_ix(_i294, _t294->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)10LL))))) { return f25_lerr(f_48, line_53, hr_str("unterminated \"\"\" string", 23));
 }
(void)(({ hrv *_v296 = &(g913); uint8_t _x296 = (*({ hrv *_t297 = &(g911); int64_t _i297 = p_52; (uint8_t*)_t297->b + hr_ix(_i297, _t297->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); })); uint8_t *_p296 = (uint8_t*)hr_grow(_v296, 1, sizeof _x296); *_p296 = _x296; _p296; }));
p_52++;
 } _bk289:; 
{ int64_t *_t298 = &(p_52); *_t298 = ((int64_t)((int64_t)(*_t298) + (int64_t)((int64_t)3LL))); }
 } else { ml_88 = true;
int64_t first_90 = ((int64_t)((int64_t)q_89 + (int64_t)((int64_t)1LL))); 
int64_t close_91 = first_90; 
while ((!((((((*({ hrv *_t300 = &(g911); int64_t _i300 = close_91; (uint8_t*)_t300->b + hr_ix(_i300, _t300->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)34LL))) && (((*({ hrv *_t301 = &(g911); int64_t _i301 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)1LL))); (uint8_t*)_t301->b + hr_ix(_i301, _t301->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)34LL)))) && (((*({ hrv *_t302 = &(g911); int64_t _i302 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)2LL))); (uint8_t*)_t302->b + hr_ix(_i302, _t302->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)34LL))))))) { if ((((*({ hrv *_t303 = &(g911); int64_t _i303 = close_91; (uint8_t*)_t303->b + hr_ix(_i303, _t303->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("unterminated \"\"\" string", 23));
 }
close_91++;
 } _bk299:; 
int64_t cs_92 = close_91; 
while ((((cs_92) > (first_90)) && (((*({ hrv *_t306 = &(g911); int64_t _i306 = ((int64_t)((int64_t)cs_92 - (int64_t)((int64_t)1LL))); (uint8_t*)_t306->b + hr_ix(_i306, _t306->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:136"); }))) != (((uint8_t)10LL))))) { cs_92--;
 } _bk305:; 
int64_t mg_93 = ((int64_t)((int64_t)close_91 - (int64_t)cs_92)); 
{ int64_t _e308 = close_91; for (int64_t _k308 = cs_92; _k308 < _e308; _k308++) { int64_t q2_94 = (int64_t)_k308; if (((((*({ hrv *_t309 = &(g911); int64_t _i309 = q2_94; (uint8_t*)_t309->b + hr_ix(_i309, _t309->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:138"); }))) != (((uint8_t)32LL))) && (((*({ hrv *_t310 = &(g911); int64_t _i310 = q2_94; (uint8_t*)_t310->b + hr_ix(_i310, _t310->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:138"); }))) != (((uint8_t)9LL))))) { return f25_lerr(f_48, line_53, hr_str("only indentation may come before the closing \"\"\" of a multi-line string", 71));
 }
 } } _bk307:; 
int64_t l_95 = first_90; 
while (((l_95) < (cs_92))) { int64_t e_96 = l_95; 
while ((((*({ hrv *_t314 = &(g911); int64_t _i314 = e_96; (uint8_t*)_t314->b + hr_ix(_i314, _t314->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:141"); }))) != (((uint8_t)10LL)))) { e_96++;
 } _bk313:; 
int64_t te_97 = e_96; 
if ((((te_97) > (l_95)) && (((*({ hrv *_t315 = &(g911); int64_t _i315 = ((int64_t)((int64_t)te_97 - (int64_t)((int64_t)1LL))); (uint8_t*)_t315->b + hr_ix(_i315, _t315->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:142"); }))) == (((uint8_t)13LL))))) { te_97--;
 }
if (((l_95) != (first_90))) { (void)(({ hrv *_v316 = &(g913); uint8_t _x316 = ((uint8_t)10LL); uint8_t *_p316 = (uint8_t*)hr_grow(_v316, 1, sizeof _x316); *_p316 = _x316; _p316; }));
 }
bool ok_98 = ((((int64_t)((int64_t)te_97 - (int64_t)l_95))) >= (mg_93)); 
if (ok_98) { { int64_t _e318 = mg_93; for (int64_t _k318 = 0; _k318 < _e318; _k318++) { int64_t k_99 = (int64_t)_k318; if ((((*({ hrv *_t319 = &(g911); int64_t _i319 = ((int64_t)((int64_t)l_95 + (int64_t)k_99)); (uint8_t*)_t319->b + hr_ix(_i319, _t319->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:144"); }))) != ((*({ hrv *_t320 = &(g911); int64_t _i320 = ((int64_t)((int64_t)cs_92 + (int64_t)k_99)); (uint8_t*)_t320->b + hr_ix(_i320, _t320->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:144"); }))))) { ok_98 = false;
 }
 } } _bk317:; 
 }
if (ok_98) { (void)(({ hrv *_v321 = &(g913); hsl _s321 = ({ hsl _t322 = hr_sl(g911); int64_t _l322 = ((int64_t)((int64_t)l_95 + (int64_t)mg_93)), _h322 = te_97; if (_l322 < 0 || _h322 < _l322 || _h322 > _t322.n) hr_slerr(_l322, _h322, _t322.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:145"); (hsl){ _t322.p + _l322 * (int64_t)sizeof(uint8_t), _h322 - _l322 }; }); hr_append(_v321, _s321.p, _s321.n, sizeof(uint8_t)); }));
 } else { { int64_t _e324 = te_97; for (int64_t _k324 = l_95; _k324 < _e324; _k324++) { int64_t k_100 = (int64_t)_k324; if (((((*({ hrv *_t325 = &(g911); int64_t _i325 = k_100; (uint8_t*)_t325->b + hr_ix(_i325, _t325->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:145"); }))) != (((uint8_t)32LL))) && (((*({ hrv *_t326 = &(g911); int64_t _i326 = k_100; (uint8_t*)_t326->b + hr_ix(_i326, _t326->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:145"); }))) != (((uint8_t)9LL))))) { return f25_lerr(f_48, line_53, hr_str("a line of a multi-line string must start with the indentation of its closing \"\"\"", 80));
 }
 } } _bk323:; 
 }
l_95 = ((int64_t)((int64_t)e_96 + (int64_t)((int64_t)1LL)));
 } _bk312:; 
{ int64_t _e329 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)3LL))); for (int64_t _k329 = p_52; _k329 < _e329; _k329++) { int64_t k_101 = (int64_t)_k329; if ((((*({ hrv *_t330 = &(g911); int64_t _i330 = k_101; (uint8_t*)_t330->b + hr_ix(_i330, _t330->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:148"); }))) == (((uint8_t)10LL)))) { line_53++;
 }
 } } _bk328:; 
p_52 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)3LL)));
 }
 } else { p_52++;
while ((((*({ hrv *_t332 = &(g911); int64_t _i332 = p_52; (uint8_t*)_t332->b + hr_ix(_i332, _t332->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:153"); }))) != (((uint8_t)34LL)))) { if (((((*({ hrv *_t333 = &(g911); int64_t _i333 = p_52; (uint8_t*)_t333->b + hr_ix(_i333, _t333->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:153"); }))) == (((uint8_t)10LL))) || (((*({ hrv *_t334 = &(g911); int64_t _i334 = p_52; (uint8_t*)_t334->b + hr_ix(_i334, _t334->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:153"); }))) == (((uint8_t)0LL))))) { return f25_lerr(f_48, line_53, hr_str("unterminated string literal", 27));
 }
int64_t v_102 = f30_esc((&(p_52)), f_48, line_53); 
if (((v_102) < (((int64_t)0LL)))) { return false;
 }
(void)(({ hrv *_v337 = &(g913); uint8_t _x337 = ((uint8_t)(v_102)); uint8_t *_p337 = (uint8_t*)hr_grow(_v337, 1, sizeof _x337); *_p337 = _x337; _p337; }));
 } _bk331:; 
p_52++;
 }
(void)(f23_put(((int64_t)4LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t339 = &(((*({ hrv *_t340 = &(g917); int64_t _i340 = ((int64_t)((int64_t)(g917).n - (int64_t)((int64_t)1LL))); (S3*)_t340->b + hr_ix(_i340, _t340->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:156"); }))).v_); *_t339 = ss_87; }
{ int32_t *_t341 = &(((*({ hrv *_t342 = &(g917); int64_t _i342 = ((int64_t)((int64_t)(g917).n - (int64_t)((int64_t)1LL))); (S3*)_t342->b + hr_ix(_i342, _t342->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:156"); }))).w_); *_t341 = ((int32_t)(((int64_t)((int64_t)(g913).n - (int64_t)ss_87)))); }
{ bool *_t343 = &(((*({ hrv *_t344 = &(g917); int64_t _i344 = ((int64_t)((int64_t)(g917).n - (int64_t)((int64_t)1LL))); (S3*)_t344->b + hr_ix(_i344, _t344->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:156"); }))).ml_); *_t343 = ml_88; }
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
(void)(({ hrv *_v351 = &(g917); S3 _x351 = ((S3){ .k_ = ((uint8_t)(k_54)), .f_ = ((uint16_t)((*c48))), .line_ = ((int32_t)((*c53))), .s_ = ((int32_t)(s_55)), .n_ = ((int32_t)(((int64_t)((int64_t)e_56 - (int64_t)s_55)))), }); S3 *_p351 = (S3*)hr_grow(_v351, 1, sizeof _x351); *_p351 = _x351; _p351; }));
}
static bool f25_lerr(int64_t f_60, int64_t line_61, hsl m_62) {
if ((((g918).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v352 = &(g918); hsl _s352 = f10_nm(((int64_t)(((*({ hrv *_t354 = &(g916); int64_t _i354 = f_60; (S2*)_t354->b + hr_ix(_i354, _t354->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:52"); }))).name_))); hr_append(_v352, _s352.p, _s352.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o355 = &(g918); hr_fs(_o355, hr_str(":", 1)); hr_fi(_o355, line_61); hr_fs(_o355, hr_str(": error: ", 9)); hr_fs(_o355, m_62); }));
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
uint8_t c_83 = (*({ hrv *_t358 = &(g911); int64_t _i358 = (*p_80); (uint8_t*)_t358->b + hr_ix(_i358, _t358->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:54"); })); 
(*p_80)++;
if (((c_83) != (((uint8_t)92LL)))) { return ((int64_t)(c_83));
 }
uint8_t e_84 = (*({ hrv *_t359 = &(g911); int64_t _i359 = (*p_80); (uint8_t*)_t359->b + hr_ix(_i359, _t359->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:56"); })); 
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
if (((((e_84) == (((uint8_t)120LL))) && f27_hexd((*({ hrv *_t361 = &(g911); int64_t _i361 = (*p_80); (uint8_t*)_t361->b + hr_ix(_i361, _t361->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); })))) && f27_hexd((*({ hrv *_t363 = &(g911); int64_t _i363 = ((int64_t)((int64_t)(*p_80) + (int64_t)((int64_t)1LL))); (uint8_t*)_t363->b + hr_ix(_i363, _t363->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); }))))) { int64_t v_85 = ((int64_t)((int64_t)((int64_t)((int64_t)f28_hexv((*({ hrv *_t365 = &(g911); int64_t _i365 = (*p_80); (uint8_t*)_t365->b + hr_ix(_i365, _t365->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); }))) * (int64_t)((int64_t)16LL))) + (int64_t)f28_hexv((*({ hrv *_t367 = &(g911); int64_t _i367 = ((int64_t)((int64_t)(*p_80) + (int64_t)((int64_t)1LL))); (uint8_t*)_t367->b + hr_ix(_i367, _t367->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); }))))); 
{ int64_t *_t368 = p_80; *_t368 = ((int64_t)((int64_t)(*_t368) + (int64_t)((int64_t)2LL))); }
return v_85;
 }
(void)(f25_lerr(f_81, line_82, hr_str("unknown escape sequence", 23)));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f31_tk(void) {
return ((int64_t)(((*({ hrv *_t370 = &(g917); int64_t _i370 = g712; (S3*)_t370->b + hr_ix(_i370, _t370->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:32"); }))).k_));
}
static void f32_ptop(void) {
int64_t st_104 = g712; 
g719 = g720;
int64_t k_105 = f31_tk(); 
if (((k_105) == (((int64_t)57LL)))) { (void)(f33_nx());
g720 = f34_ident(hr_str("namespace declaration", 21));
g719 = g720;
(void)(f39_ex(((int64_t)12LL), hr_str("namespace declaration", 21)));
return;
 }
if (((k_105) == (((int64_t)56LL)))) { (void)(f33_nx());
int64_t n_121 = f40_mk(((int64_t)54LL), st_104); 
if (f41_is(((int64_t)16LL))) { { uint16_t *_t378 = &(((*({ hrv *_t379 = &(g707); int64_t _i379 = n_121; (S4*)_t379->b + hr_ix(_i379, _t379->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:699"); }))).fl_); *_t378 = ((uint16_t)1LL); }
 }
hrv path_123 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v381 = &(path_123); hsl _s381 = f10_nm(f34_ident(hr_str("import", 6))); hr_append(_v381, _s381.p, _s381.n, sizeof(uint8_t)); }));
while (f41_is(((int64_t)16LL))) { (void)(({ hrv *_v386 = &(path_123); uint8_t _x386 = ((uint8_t)47LL); uint8_t *_p386 = (uint8_t*)hr_grow(_v386, 1, sizeof _x386); *_p386 = _x386; _p386; }));
(void)(({ hrv *_v387 = &(path_123); hsl _s387 = f10_nm(f34_ident(hr_str("import", 6))); hr_append(_v387, _s387.p, _s387.n, sizeof(uint8_t)); }));
 } _bk384:; 
{ int64_t q__124 = f8_intern(hr_sl(path_123)); 
{ int32_t *_t391 = &(((*({ hrv *_t392 = &(g707); int64_t _i392 = n_121; (S4*)_t392->b + hr_ix(_i392, _t392->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:703"); }))).s_); *_t391 = ((int32_t)(q__124)); }
 }
if ((f42_at_from() || f43_at_word(g724))) { (void)(f33_nx());
if (((f31_tk()) != (((int64_t)4LL)))) { (void)(f38_perr(hr_str("expected the package's source, a string, after from", 51)));
 }
{ int32_t *_t398 = &(((*({ hrv *_t399 = &(g707); int64_t _i399 = n_121; (S4*)_t399->b + hr_ix(_i399, _t399->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:704"); }))).a_); *_t398 = ((int32_t)(g712)); }
(void)(f33_nx());
 }
(void)(f39_ex(((int64_t)12LL), hr_str("import", 6)));
(void)(({ hrv *_v402 = &(g710); int32_t _x402 = ((int32_t)(n_121)); int32_t *_p402 = (int32_t*)hr_grow(_v402, 1, sizeof _x402); *_p402 = _x402; _p402; }));
return;
 }
if (((f46_at_inline() || f47_at_checkfree()) || f48_at_lut())) { (void)(({ hrv *_v406 = &(g710); int32_t _x406 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p406 = (int32_t*)hr_grow(_v406, 1, sizeof _x406); *_p406 = _x406; _p406; }));
return;
 }
if (((k_105) == (((int64_t)58LL)))) { (void)(({ hrv *_v408 = &(g710); int32_t _x408 = ((int32_t)(f94_pstruct())); int32_t *_p408 = (int32_t*)hr_grow(_v408, 1, sizeof _x408); *_p408 = _x408; _p408; }));
return;
 }
if (((k_105) == (((int64_t)59LL)))) { (void)(({ hrv *_v410 = &(g710); int32_t _x410 = ((int32_t)(f96_penum())); int32_t *_p410 = (int32_t*)hr_grow(_v410, 1, sizeof _x410); *_p410 = _x410; _p410; }));
return;
 }
if (((k_105) == (((int64_t)60LL)))) { (void)(f33_nx());
int64_t n_433 = f40_mk(((int64_t)53LL), st_104); 
{ int64_t q__434 = f50_declname(hr_str("type alias", 10)); 
{ int32_t *_t415 = &(((*({ hrv *_t416 = &(g707); int64_t _i416 = n_433; (S4*)_t416->b + hr_ix(_i416, _t416->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:712"); }))).s_); *_t415 = ((int32_t)(q__434)); }
 }
{ int32_t *_t417 = &(((*({ hrv *_t418 = &(g707); int64_t _i418 = n_433; (S4*)_t418->b + hr_ix(_i418, _t418->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:712"); }))).a_); *_t417 = ((int32_t)(g719)); }
(void)(f39_ex(((int64_t)36LL), hr_str("type alias", 10)));
{ int64_t q__435 = f53_ptype(); 
{ int32_t *_t421 = &(((*({ hrv *_t422 = &(g707); int64_t _i422 = n_433; (S4*)_t422->b + hr_ix(_i422, _t422->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:712"); }))).b_); *_t421 = ((int32_t)(q__435)); }
 }
(void)(f39_ex(((int64_t)12LL), hr_str("type alias", 10)));
(void)(({ hrv *_v424 = &(g710); int32_t _x424 = ((int32_t)(n_433)); int32_t *_p424 = (int32_t*)hr_grow(_v424, 1, sizeof _x424); *_p424 = _x424; _p424; }));
return;
 }
if (((k_105) == (((int64_t)68LL)))) { (void)(f33_nx());
int64_t cs_436 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((f31_tk()) == (((int64_t)4LL)))) { cs_436 = g712;
(void)(f33_nx());
 }
if (((f31_tk()) == (((int64_t)9LL)))) { if (((cs_436) < (((int64_t)0LL)))) { (void)(f38_perr(hr_str("an extern block names the library it binds from: extern \"lib\" {", 63)));
 }
(void)(f33_nx());
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v434 = &(g710); int32_t _x434 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), cs_436))); int32_t *_p434 = (int32_t*)hr_grow(_v434, 1, sizeof _x434); *_p434 = _x434; _p434; }));
 } _bk431:; 
(void)(f39_ex(((int64_t)10LL), hr_str("extern block", 12)));
return;
 }
g712--;
if (((cs_436) >= (((int64_t)0LL)))) { g712--;
 }
(void)(({ hrv *_v437 = &(g710); int32_t _x437 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p437 = (int32_t*)hr_grow(_v437, 1, sizeof _x437); *_p437 = _x437; _p437; }));
return;
 }
if (((((((k_105) == (((int64_t)65LL))) || ((k_105) == (((int64_t)61LL)))) || ((k_105) == (((int64_t)62LL)))) || ((k_105) == (((int64_t)63LL)))) || ((k_105) == (((int64_t)64LL))))) { (void)(({ hrv *_v439 = &(g710); int32_t _x439 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p439 = (int32_t*)hr_grow(_v439, 1, sizeof _x439); *_p439 = _x439; _p439; }));
return;
 }
if ((((((k_105) == (((int64_t)71LL))) || ((k_105) == (((int64_t)66LL)))) || ((k_105) == (((int64_t)67LL)))) || ((k_105) == (((int64_t)69LL))))) { int64_t v_437 = f74_pvdecl(true); 
(void)(f39_ex(((int64_t)12LL), hr_str("global declaration", 18)));
(void)(({ hrv *_v443 = &(g710); int32_t _x443 = ((int32_t)(v_437)); int32_t *_p443 = (int32_t*)hr_grow(_v443, 1, sizeof _x443); *_p443 = _x443; _p443; }));
return;
 }
hrv m_438 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o445 = &(m_438); hr_fs(_o445, hr_str("top-level declaration expected, found '", 39)); hr_fs(_o445, f35_cur_text()); hr_fs(_o445, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_438)));
}
static void f33_nx(void) {
if (((((*({ hrv *_t448 = &(g917); int64_t _i448 = g712; (S3*)_t448->b + hr_ix(_i448, _t448->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:34"); }))).k_) != (((uint8_t)0LL)))) { g712++;
 }
}
static int64_t f34_ident(hsl ctx_106) {
if (((f31_tk()) != (((int64_t)1LL)))) { hrv m_107 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o451 = &(m_107); hr_fs(_o451, hr_str("expected identifier in ", 23)); hr_fs(_o451, ctx_106); hr_fs(_o451, hr_str(", found '", 9)); hr_fs(_o451, f35_cur_text()); hr_fs(_o451, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_107)));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t v_115 = ((int64_t)(((*({ hrv *_t454 = &(g917); int64_t _i454 = g712; (S3*)_t454->b + hr_ix(_i454, _t454->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:51"); }))).v_)); 
(void)(f33_nx());
return v_115;
}
static hsl f35_cur_text(void) {
int64_t k_108 = f31_tk(); 
return ({ hsl _r457; if (((((k_108) == (((int64_t)1LL))) || ((k_108) == (((int64_t)2LL)))) || ((k_108) == (((int64_t)3LL))))) { _r457 = f36_tok_text(g712);  } else { _r457 = f37_tname(k_108);  } _r457; });
}
static hsl f36_tok_text(int64_t t_109) {
S3 x_110 = (*({ hrv *_t460 = &(g917); int64_t _i460 = t_109; (S3*)_t460->b + hr_ix(_i460, _t460->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:181"); })); 
return ({ hsl _t461 = hr_sl(g911); int64_t _l461 = ((int64_t)((x_110).s_)), _h461 = ((int64_t)(((int32_t)((int64_t)(x_110).s_ + (int64_t)(x_110).n_)))); if (_l461 < 0 || _h461 < _l461 || _h461 > _t461.n) hr_slerr(_l461, _h461, _t461.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:181"); (hsl){ _t461.p + _l461 * (int64_t)sizeof(uint8_t), _h461 - _l461 }; });
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
if (((g714) > (((int64_t)0LL)))) { g715 = true;
g712 = ((int64_t)((int64_t)(g917).n - (int64_t)((int64_t)1LL)));
return;
 }
if ((((g713).n) > (((int64_t)0LL)))) { return;
 }
S3 t_114 = (*({ hrv *_t465 = &(g917); int64_t _i465 = g712; (S3*)_t465->b + hr_ix(_i465, _t465->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:45"); })); 
(void)(({ hrv *_v466 = &(g713); hsl _s466 = f10_nm(((int64_t)(((*({ hrv *_t468 = &(g916); int64_t _i468 = (t_114).f_; (S2*)_t468->b + hr_ix(_i468, _t468->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:46"); }))).name_))); hr_append(_v466, _s466.p, _s466.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o469 = &(g713); hr_fs(_o469, hr_str(":", 1)); hr_fi(_o469, (t_114).line_); hr_fs(_o469, hr_str(": error: ", 9)); hr_fs(_o469, m_113); }));
g712 = ((int64_t)((int64_t)(g917).n - (int64_t)((int64_t)1LL)));
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
(void)(({ hrv *_v477 = &(g707); S4 _x477 = ((S4){ .k_ = ((uint8_t)(k_119)), .t_ = ((int32_t)(t_120)), .a_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .b_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .d_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .e_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .s_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .l_ = ((int32_t)0LL), .n_ = ((int32_t)0LL), }); S4 *_p477 = (S4*)hr_grow(_v477, 1, sizeof _x477); *_p477 = _x477; _p477; }));
return ((int64_t)((int64_t)(g707).n - (int64_t)((int64_t)1LL)));
}
static bool f41_is(int64_t k_122) {
if (((f31_tk()) == (k_122))) { (void)(f33_nx());
return true;
 }
return false;
}
static bool f42_at_from(void) {
return (f43_at_word(g724) && (((f44_tkat(((int64_t)((int64_t)g712 + (int64_t)((int64_t)1LL))))) == (((int64_t)1LL))) || ((f44_tkat(((int64_t)((int64_t)g712 + (int64_t)((int64_t)1LL))))) == (((int64_t)15LL)))));
}
static bool f43_at_word(int64_t w_125) {
return (((f31_tk()) == (((int64_t)1LL))) && ((((*({ hrv *_t484 = &(g917); int64_t _i484 = g712; (S3*)_t484->b + hr_ix(_i484, _t484->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:69"); }))).v_) == (w_125)));
}
static int64_t f44_tkat(int64_t i_126) {
return ((int64_t)(((*({ hrv *_t485 = &(g917); int64_t _i485 = f45_min(i_126, ((int64_t)((int64_t)(g917).n - (int64_t)((int64_t)1LL)))); (S3*)_t485->b + hr_ix(_i485, _t485->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:33"); }))).k_));
}
static int64_t f45_min(int64_t a_127, int64_t b_128) {
if (((b_128) < (a_127))) { return b_128;
 }
return a_127;
}
static bool f46_at_inline(void) {
return (f43_at_word(g725) && ((((f44_tkat(((int64_t)((int64_t)g712 + (int64_t)((int64_t)1LL))))) == (((int64_t)61LL))) || ((f44_tkat(((int64_t)((int64_t)g712 + (int64_t)((int64_t)1LL))))) == (((int64_t)65LL)))) || ((f44_tkat(((int64_t)((int64_t)g712 + (int64_t)((int64_t)1LL))))) == (((int64_t)62LL)))));
}
static bool f47_at_checkfree(void) {
int64_t n_129 = f44_tkat(((int64_t)((int64_t)g712 + (int64_t)((int64_t)1LL)))); 
return (f43_at_word(g726) && (((((((n_129) == (((int64_t)61LL))) || ((n_129) == (((int64_t)65LL)))) || ((n_129) == (((int64_t)62LL)))) || ((n_129) == (((int64_t)64LL)))) || ((n_129) == (((int64_t)68LL)))) || ((n_129) == (((int64_t)1LL)))));
}
static bool f48_at_lut(void) {
return (f43_at_word(g727) && ((f44_tkat(((int64_t)((int64_t)g712 + (int64_t)((int64_t)1LL))))) == (((int64_t)61LL))));
}
static int64_t f49_pfn(bool nested_130, int64_t cname_131, int64_t dylib_132) {
int64_t st_133 = g712; 
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
if (((f31_tk()) == (((int64_t)4LL)))) { cn_136 = g712;
(void)(f33_nx());
 }
 }
if (f41_is(((int64_t)68LL))) { { int64_t *_t509 = &(fl_135); *_t509 = ((int64_t)((int64_t)(*_t509) | (int64_t)((int64_t)1LL))); }
if (((f31_tk()) == (((int64_t)4LL)))) { cn_136 = g712;
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
{ int32_t *_t528 = &(((*({ hrv *_t529 = &(g707); int64_t _i529 = n_134; (S4*)_t529->b + hr_ix(_i529, _t529->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:657"); }))).s_); *_t528 = ((int32_t)(q__139)); }
 }
{ int32_t *_t530 = &(((*({ hrv *_t531 = &(g707); int64_t _i531 = n_134; (S4*)_t531->b + hr_ix(_i531, _t531->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:658"); }))).a_); *_t530 = ((int32_t)(g719)); }
{ int64_t q__403 = f51_pgenerics(); 
{ int32_t *_t533 = &(((*({ hrv *_t534 = &(g707); int64_t _i534 = n_134; (S4*)_t534->b + hr_ix(_i534, _t534->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:659"); }))).d_); *_t533 = ((int32_t)(q__403)); }
 }
(void)(f39_ex(((int64_t)5LL), hr_str("function declaration", 20)));
int64_t m_404 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t p_405 = f40_mk(((int64_t)32LL), g712); 
if (f41_is(((int64_t)67LL))) { { uint16_t *_t542 = &(((*({ hrv *_t543 = &(g707); int64_t _i543 = p_405; (S4*)_t543->b + hr_ix(_i543, _t543->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:664"); }))).fl_); *_t542 = ((uint16_t)1LL); }
 }
{ int64_t q__406 = f34_ident(hr_str("parameter list", 14)); 
{ int32_t *_t545 = &(((*({ hrv *_t546 = &(g707); int64_t _i546 = p_405; (S4*)_t546->b + hr_ix(_i546, _t546->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:665"); }))).s_); *_t545 = ((int32_t)(q__406)); }
 }
if ((f41_is(((int64_t)13LL)) || f75_amni_type())) { { int64_t q__407 = f53_ptype(); 
{ int32_t *_t550 = &(((*({ hrv *_t551 = &(g707); int64_t _i551 = p_405; (S4*)_t551->b + hr_ix(_i551, _t551->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:666"); }))).a_); *_t550 = ((int32_t)(q__407)); }
 }
 }
if (f41_is(((int64_t)36LL))) { { int64_t q__408 = f61_pexpr(); 
{ int32_t *_t554 = &(((*({ hrv *_t555 = &(g707); int64_t _i555 = p_405; (S4*)_t555->b + hr_ix(_i555, _t555->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:667"); }))).b_); *_t554 = ((int32_t)(q__408)); }
 }
 }
(void)(({ hrv *_v556 = &(g709); int32_t _x556 = ((int32_t)(p_405)); int32_t *_p556 = (int32_t*)hr_grow(_v556, 1, sizeof _x556); *_p556 = _x556; _p556; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk537; }
 }
 } _bk537:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function declaration", 20)));
(void)(f59_setl(n_134, m_404));
if ((f41_is(((int64_t)54LL)) || f75_amni_type())) { { int64_t *_t562 = &(fl_135); *_t562 = ((int64_t)((int64_t)(*_t562) | (int64_t)((int64_t)512LL))); }
int64_t r_409 = f40_mk(((int64_t)36LL), g712); 
int64_t m2_410 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v566 = &(g709); int32_t _x566 = ((int32_t)(f53_ptype())); int32_t *_p566 = (int32_t*)hr_grow(_v566, 1, sizeof _x566); *_p566 = _x566; _p566; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk565; }
 }
 } _bk565:; 
(void)(f59_setl(r_409, m2_410));
{ int32_t *_t570 = &(((*({ hrv *_t571 = &(g707); int64_t _i571 = n_134; (S4*)_t571->b + hr_ix(_i571, _t571->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:677"); }))).b_); *_t570 = ((int32_t)(r_409)); }
 }
if (((((int64_t)((int64_t)fl_135 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)))) { if (f41_is(((int64_t)36LL))) { if (((f31_tk()) != (((int64_t)4LL)))) { (void)(f38_perr(hr_str("an extern fn's symbol is a string: fn name(...) = \"symbol\"; (\302\2477.10)", 68)));
 }
cn_136 = g712;
(void)(f33_nx());
 }
(void)(f39_ex(((int64_t)12LL), hr_str("extern declaration", 18)));
int64_t x_411 = f40_mk(((int64_t)58LL), st_133); 
{ int32_t *_t578 = &(((*({ hrv *_t579 = &(g707); int64_t _i579 = x_411; (S4*)_t579->b + hr_ix(_i579, _t579->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:682"); }))).a_); *_t578 = ((int32_t)(cn_136)); }
{ int32_t *_t580 = &(((*({ hrv *_t581 = &(g707); int64_t _i581 = x_411; (S4*)_t581->b + hr_ix(_i581, _t581->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:682"); }))).b_); *_t580 = ((int32_t)(dylib_132)); }
{ int32_t *_t582 = &(((*({ hrv *_t583 = &(g707); int64_t _i583 = n_134; (S4*)_t583->b + hr_ix(_i583, _t583->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:682"); }))).e_); *_t582 = ((int32_t)(x_411)); }
 } else { if (((((int64_t)((int64_t)fl_135 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { int64_t x_412 = f40_mk(((int64_t)58LL), st_133); 
{ int32_t *_t585 = &(((*({ hrv *_t586 = &(g707); int64_t _i586 = x_412; (S4*)_t586->b + hr_ix(_i586, _t586->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:684"); }))).a_); *_t585 = ((int32_t)(cn_136)); }
{ int32_t *_t587 = &(((*({ hrv *_t588 = &(g707); int64_t _i588 = n_134; (S4*)_t588->b + hr_ix(_i588, _t588->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:684"); }))).e_); *_t587 = ((int32_t)(x_412)); }
 }
{ int64_t q__413 = f66_pblock(hr_str("function body", 13)); 
{ int32_t *_t590 = &(((*({ hrv *_t591 = &(g707); int64_t _i591 = n_134; (S4*)_t591->b + hr_ix(_i591, _t591->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:685"); }))).c_); *_t590 = ((int32_t)(q__413)); }
 }
 }
{ uint16_t *_t592 = &(((*({ hrv *_t593 = &(g707); int64_t _i593 = n_134; (S4*)_t593->b + hr_ix(_i593, _t593->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:687"); }))).fl_); *_t592 = ((uint16_t)(fl_135)); }
(void)(f88_set_end(n_134));
return n_134;
}
static int64_t f50_declname(hsl ctx_137) {
int64_t a_138 = ({ int64_t _r595; if (((f31_tk()) == (((int64_t)15LL)))) { _r595 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r595 = f34_ident(ctx_137);  } _r595; }); 
if (f41_is(((int64_t)15LL))) { g719 = a_138;
return f34_ident(ctx_137);
 }
return a_138;
}
static int64_t f51_pgenerics(void) {
if ((!(f41_is(((int64_t)39LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t l_140 = f40_mk(((int64_t)36LL), g712); 
int64_t m_141 = f52_wbeg(); 
for (;;) { int64_t g_142 = f40_mk(((int64_t)57LL), g712); 
{ int64_t q__143 = f34_ident(hr_str("generic parameter list", 22)); 
{ int32_t *_t606 = &(((*({ hrv *_t607 = &(g707); int64_t _i607 = g_142; (S4*)_t607->b + hr_ix(_i607, _t607->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:587"); }))).s_); *_t606 = ((int32_t)(q__143)); }
 }
if (f41_is(((int64_t)13LL))) { { int64_t q__402 = f53_ptype(); 
{ int32_t *_t610 = &(((*({ hrv *_t611 = &(g707); int64_t _i611 = g_142; (S4*)_t611->b + hr_ix(_i611, _t611->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:588"); }))).a_); *_t610 = ((int32_t)(q__402)); }
 }
 }
(void)(({ hrv *_v612 = &(g709); int32_t _x612 = ((int32_t)(g_142)); int32_t *_p612 = (int32_t*)hr_grow(_v612, 1, sizeof _x612); *_p612 = _x612; _p612; }));
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
return (g709).n;
}
static int64_t f53_ptype(void) {
bool cq_144 = f41_is(((int64_t)69LL)); 
int64_t t_175 = f54_ptype_prim(); 
bool q_176 = cq_144; 
for (;;) { int64_t st_177 = g712; 
if (f41_is(((int64_t)7LL))) { if (f41_is(((int64_t)13LL))) { (void)(f39_ex(((int64_t)8LL), hr_str("slice type", 10)));
int64_t n_178 = f40_mk(((int64_t)43LL), st_177); 
{ int32_t *_t625 = &(((*({ hrv *_t626 = &(g707); int64_t _i626 = n_178; (S4*)_t626->b + hr_ix(_i626, _t626->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:84"); }))).a_); *_t625 = ((int32_t)(t_175)); }
if (q_176) { { uint16_t *_t627 = &(((*({ hrv *_t628 = &(g707); int64_t _i628 = n_178; (S4*)_t628->b + hr_ix(_i628, _t628->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:84"); }))).fl_); *_t627 = ((uint16_t)1LL); }
q_176 = false;
 }
t_175 = n_178;
continue;
 }
int64_t n_179 = f40_mk(((int64_t)42LL), st_177); 
{ int32_t *_t630 = &(((*({ hrv *_t631 = &(g707); int64_t _i631 = n_179; (S4*)_t631->b + hr_ix(_i631, _t631->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:85"); }))).a_); *_t630 = ((int32_t)(t_175)); }
if (f41_is(((int64_t)8LL))) { { uint8_t *_t633 = &(((*({ hrv *_t634 = &(g707); int64_t _i634 = n_179; (S4*)_t634->b + hr_ix(_i634, _t634->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:86"); }))).op_); *_t633 = ((uint8_t)(((uint8_t)2LL))); }
t_175 = n_179;
continue;
 }
if (f41_is(((int64_t)17LL))) { { uint8_t *_t636 = &(((*({ hrv *_t637 = &(g707); int64_t _i637 = n_179; (S4*)_t637->b + hr_ix(_i637, _t637->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:87"); }))).op_); *_t636 = ((uint8_t)(((uint8_t)3LL))); }
if (((f31_tk()) != (((int64_t)8LL)))) { { int64_t q__391 = f61_pexpr(); 
{ int32_t *_t640 = &(((*({ hrv *_t641 = &(g707); int64_t _i641 = n_179; (S4*)_t641->b + hr_ix(_i641, _t641->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:87"); }))).b_); *_t640 = ((int32_t)(q__391)); }
 }
 }
 } else { if (f41_is(((int64_t)40LL))) { (void)(f39_ex(((int64_t)17LL), hr_str("resizable array type", 20)));
{ uint8_t *_t644 = &(((*({ hrv *_t645 = &(g707); int64_t _i645 = n_179; (S4*)_t645->b + hr_ix(_i645, _t645->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:88"); }))).op_); *_t644 = ({ uint8_t _r646; if (f41_is(((int64_t)39LL))) { _r646 = ((uint8_t)(((uint8_t)5LL)));  } else { _r646 = ((uint8_t)(((uint8_t)4LL)));  } _r646; }); }
 } else { if (f55_prim_tok(f31_tk())) { { uint8_t *_t650 = &(((*({ hrv *_t651 = &(g707); int64_t _i651 = n_179; (S4*)_t651->b + hr_ix(_i651, _t651->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:89"); }))).op_); *_t650 = ((uint8_t)(((uint8_t)2LL))); }
{ int64_t q__393 = f93_lenstore(); 
{ int32_t *_t653 = &(((*({ hrv *_t654 = &(g707); int64_t _i654 = n_179; (S4*)_t654->b + hr_ix(_i654, _t654->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:89"); }))).c_); *_t653 = ((int32_t)(q__393)); }
 }
 } else { { uint8_t *_t655 = &(((*({ hrv *_t656 = &(g707); int64_t _i656 = n_179; (S4*)_t656->b + hr_ix(_i656, _t656->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:90"); }))).op_); *_t655 = ((uint8_t)(((uint8_t)1LL))); }
{ int64_t q__394 = f61_pexpr(); 
{ int32_t *_t658 = &(((*({ hrv *_t659 = &(g707); int64_t _i659 = n_179; (S4*)_t659->b + hr_ix(_i659, _t659->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:90"); }))).b_); *_t658 = ((int32_t)(q__394)); }
 }
 }
 }
 }
(void)(f39_ex(((int64_t)8LL), hr_str("array type", 10)));
t_175 = n_179;
continue;
 }
if (f41_is(((int64_t)49LL))) { int64_t n_395 = f40_mk(((int64_t)44LL), st_177); 
{ int32_t *_t663 = &(((*({ hrv *_t664 = &(g707); int64_t _i664 = n_395; (S4*)_t664->b + hr_ix(_i664, _t664->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:95"); }))).a_); *_t663 = ((int32_t)(t_175)); }
if (q_176) { { uint16_t *_t665 = &(((*({ hrv *_t666 = &(g707); int64_t _i666 = n_395; (S4*)_t666->b + hr_ix(_i666, _t666->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:95"); }))).fl_); *_t665 = ((uint16_t)1LL); }
q_176 = false;
 }
if (f41_is(((int64_t)39LL))) { { int64_t q__396 = f93_lenstore(); 
{ int32_t *_t669 = &(((*({ hrv *_t670 = &(g707); int64_t _i670 = n_395; (S4*)_t670->b + hr_ix(_i670, _t670->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:96"); }))).c_); *_t669 = ((int32_t)(q__396)); }
 }
if (f41_is(((int64_t)76LL))) { { int64_t q__397 = f56_qname(hr_str("relative reference pool", 23)); 
{ int32_t *_t673 = &(((*({ hrv *_t674 = &(g707); int64_t _i674 = n_395; (S4*)_t674->b + hr_ix(_i674, _t674->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:96"); }))).s_); *_t673 = ((int32_t)(q__397)); }
 }
 }
(void)(f58_close_angle(hr_str("relative reference width", 24)));
 }
t_175 = n_395;
continue;
 }
if (f41_is(((int64_t)14LL))) { if (((((*({ hrv *_t677 = &(g707); int64_t _i677 = t_175; (S4*)_t677->b + hr_ix(_i677, _t677->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).k_) == (((uint8_t)44LL)))) { { uint16_t *_t678 = &(((*({ hrv *_t679 = &(g707); int64_t _i679 = t_175; (S4*)_t679->b + hr_ix(_i679, _t679->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).fl_); *_t678 = ((uint16_t)((uint64_t)(*_t678) | (uint64_t)((uint16_t)2LL))); }
 } else { int64_t n_398 = f40_mk(((int64_t)44LL), st_177); 
{ int32_t *_t681 = &(((*({ hrv *_t682 = &(g707); int64_t _i682 = n_398; (S4*)_t682->b + hr_ix(_i682, _t682->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).a_); *_t681 = ((int32_t)(t_175)); }
{ uint16_t *_t683 = &(((*({ hrv *_t684 = &(g707); int64_t _i684 = n_398; (S4*)_t684->b + hr_ix(_i684, _t684->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).fl_); *_t683 = ((uint16_t)2LL); }
if (q_176) { { uint16_t *_t685 = &(((*({ hrv *_t686 = &(g707); int64_t _i686 = n_398; (S4*)_t686->b + hr_ix(_i686, _t686->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).fl_); *_t685 = ((uint16_t)((uint64_t)(*_t685) | (uint64_t)((uint16_t)1LL))); }
q_176 = false;
 }
t_175 = n_398;
 }
continue;
 }
if (((f31_tk()) == (((int64_t)17LL)))) { (void)(f33_nx());
if (((((*({ hrv *_t689 = &(g707); int64_t _i689 = t_175; (S4*)_t689->b + hr_ix(_i689, _t689->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:103"); }))).k_) == (((uint8_t)41LL)))) { { uint16_t *_t690 = &(((*({ hrv *_t691 = &(g707); int64_t _i691 = t_175; (S4*)_t691->b + hr_ix(_i691, _t691->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:103"); }))).fl_); *_t690 = ((uint16_t)((uint64_t)(*_t690) | (uint64_t)((uint16_t)1LL))); }
 } else { (void)(f38_perr(hr_str("variable mode (..) applies only to ADT type names", 49)));
 }
continue;
 }
if (f41_is(((int64_t)16LL))) { int64_t n_399 = f40_mk(((int64_t)46LL), st_177); 
{ int32_t *_t695 = &(((*({ hrv *_t696 = &(g707); int64_t _i696 = n_399; (S4*)_t696->b + hr_ix(_i696, _t696->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:104"); }))).a_); *_t695 = ((int32_t)(t_175)); }
{ int64_t q__400 = f34_ident(hr_str("variant type", 12)); 
{ int32_t *_t698 = &(((*({ hrv *_t699 = &(g707); int64_t _i699 = n_399; (S4*)_t699->b + hr_ix(_i699, _t699->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:104"); }))).s_); *_t698 = ((int32_t)(q__400)); }
 }
t_175 = n_399;
continue;
 }
if (q_176) { int64_t n_401 = f40_mk(((int64_t)48LL), st_177); 
{ int32_t *_t701 = &(((*({ hrv *_t702 = &(g707); int64_t _i702 = n_401; (S4*)_t702->b + hr_ix(_i702, _t702->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:105"); }))).a_); *_t701 = ((int32_t)(t_175)); }
t_175 = n_401;
 }
return t_175;
 } _bk620:; 
}
static int64_t f54_ptype_prim(void) {
int64_t st_145 = g712; 
int64_t k_146 = f31_tk(); 
if (f55_prim_tok(k_146)) { (void)(f33_nx());
bool up_148 = f43_at_word(g729); 
if (((((((((k_146) >= (((int64_t)91LL))) && ((k_146) <= (((int64_t)98LL)))) || ((k_146) == (((int64_t)103LL)))) || ((k_146) == (((int64_t)102LL)))) || ((k_146) == (((int64_t)101LL)))) && (!(g759))) && (((f31_tk()) == (((int64_t)76LL))) || up_148))) { (void)(f33_nx());
int64_t n_149 = f40_mk(((int64_t)47LL), st_145); 
{ uint8_t *_t710 = &(((*({ hrv *_t711 = &(g707); int64_t _i711 = n_149; (S4*)_t711->b + hr_ix(_i711, _t711->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:116"); }))).op_); *_t710 = ((uint8_t)(k_146)); }
{ uint16_t *_t712 = &(((*({ hrv *_t713 = &(g707); int64_t _i713 = n_149; (S4*)_t713->b + hr_ix(_i713, _t713->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:116"); }))).fl_); *_t712 = ({ uint16_t _r714; if (up_148) { _r714 = ((uint16_t)1LL);  } else { _r714 = ((uint16_t)0LL);  } _r714; }); }
{ int64_t q__155 = f56_qname(hr_str("index type", 10)); 
{ int32_t *_t716 = &(((*({ hrv *_t717 = &(g707); int64_t _i717 = n_149; (S4*)_t717->b + hr_ix(_i717, _t717->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:116"); }))).s_); *_t716 = ((int32_t)(q__155)); }
 }
return n_149;
 }
int64_t n_156 = f40_mk(((int64_t)40LL), st_145); 
{ uint8_t *_t719 = &(((*({ hrv *_t720 = &(g707); int64_t _i720 = n_156; (S4*)_t720->b + hr_ix(_i720, _t720->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:118"); }))).op_); *_t719 = ((uint8_t)(k_146)); }
return n_156;
 }
if ((((k_146) == (((int64_t)1LL))) || ((k_146) == (((int64_t)15LL))))) { int64_t n_157 = f40_mk(((int64_t)41LL), st_145); 
{ int64_t q__158 = f56_qname(hr_str("type", 4)); 
{ int32_t *_t723 = &(((*({ hrv *_t724 = &(g707); int64_t _i724 = n_157; (S4*)_t724->b + hr_ix(_i724, _t724->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:121"); }))).s_); *_t723 = ((int32_t)(q__158)); }
 }
if (f41_is(((int64_t)39LL))) { int64_t m_159 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v728 = &(g709); int32_t _x728 = ((int32_t)(f53_ptype())); int32_t *_p728 = (int32_t*)hr_grow(_v728, 1, sizeof _x728); *_p728 = _x728; _p728; }));
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
if (f41_is(((int64_t)5LL))) { { uint16_t *_t738 = &(((*({ hrv *_t739 = &(g707); int64_t _i739 = n_168; (S4*)_t739->b + hr_ix(_i739, _t739->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:128"); }))).fl_); *_t738 = ((uint16_t)1LL); }
int64_t m_169 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v744 = &(g709); int32_t _x744 = ((int32_t)(f53_ptype())); int32_t *_p744 = (int32_t*)hr_grow(_v744, 1, sizeof _x744); *_p744 = _x744; _p744; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk741; }
 }
 } _bk741:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function type", 13)));
(void)(f59_setl(n_168, m_169));
if (f41_is(((int64_t)54LL))) { int64_t r_170 = f40_mk(((int64_t)36LL), g712); 
int64_t m2_171 = f52_wbeg(); 
if (f41_is(((int64_t)5LL))) { while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v756 = &(g709); int32_t _x756 = ((int32_t)(f53_ptype())); int32_t *_p756 = (int32_t*)hr_grow(_v756, 1, sizeof _x756); *_p756 = _x756; _p756; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk753; }
 }
 } _bk753:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function type return list", 25)));
 } else { (void)(({ hrv *_v760 = &(g709); int32_t _x760 = ((int32_t)(f53_ptype())); int32_t *_p760 = (int32_t*)hr_grow(_v760, 1, sizeof _x760); *_p760 = _x760; _p760; }));
 }
(void)(f59_setl(r_170, m2_171));
{ int32_t *_t763 = &(((*({ hrv *_t764 = &(g707); int64_t _i764 = n_168; (S4*)_t764->b + hr_ix(_i764, _t764->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:133"); }))).b_); *_t763 = ((int32_t)(r_170)); }
 }
 }
return n_168;
 }
if (f41_is(((int64_t)5LL))) { bool fb_172 = g759; 
g759 = false;
int64_t t_173 = f53_ptype(); 
g759 = fb_172;
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
if (((f31_tk()) == (((int64_t)44LL)))) { (void)(({ hrv *_v788 = &(g721); int64_t _x788 = g712; int64_t *_p788 = (int64_t*)hr_grow(_v788, 1, sizeof _x788); *_p788 = _x788; _p788; }));
{ uint8_t *_t789 = &(((*({ hrv *_t790 = &(g917); int64_t _i790 = g712; (S3*)_t790->b + hr_ix(_i790, _t790->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:52"); }))).k_); *_t789 = ((uint8_t)(((uint8_t)40LL))); }
return;
 }
(void)(f39_ex(((int64_t)40LL), ctx_160));
}
static void f59_setl(int64_t n_161, int64_t m_162) {
int64_t c_163 = ((int64_t)((int64_t)(g709).n - (int64_t)m_162)); 
{ int64_t q__167 = f60_wend(m_162); 
{ int32_t *_t793 = &(((*({ hrv *_t794 = &(g707); int64_t _i794 = n_161; (S4*)_t794->b + hr_ix(_i794, _t794->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:55"); }))).l_); *_t793 = ((int32_t)(q__167)); }
 }
{ int32_t *_t795 = &(((*({ hrv *_t796 = &(g707); int64_t _i796 = n_161; (S4*)_t796->b + hr_ix(_i796, _t796->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:55"); }))).n_); *_t795 = ((int32_t)(c_163)); }
}
static int64_t f60_wend(int64_t m_164) {
int64_t l_165 = (g708).n; 
{ int64_t _e798 = (g709).n; for (int64_t _k798 = m_164; _k798 < _e798; _k798++) { int64_t i_166 = (int64_t)_k798; (void)(({ hrv *_v799 = &(g708); int32_t _x799 = (*({ hrv *_t800 = &(g709); int64_t _i800 = i_166; (int32_t*)_t800->b + hr_ix(_i800, _t800->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:54"); })); int32_t *_p799 = (int32_t*)hr_grow(_v799, 1, sizeof _x799); *_p799 = _x799; _p799; }));
 } } _bk797:; 
(void)(({ hrv *_v801 = &(g709); int64_t _k801 = ((int64_t)((int64_t)(g709).n - (int64_t)m_164)); if (_k801 < 0 || _k801 > _v801->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:54"); _v801->n -= _k801; }));
return l_165;
}
static int64_t f61_pexpr(void) {
int64_t st_180 = g712; 
int64_t k_181 = f31_tk(); 
if (((k_181) == (((int64_t)72LL)))) { int64_t e_270 = f62_pif(); 
if (g717) { g718 = true;
 }
return e_270;
 }
if (((k_181) == (((int64_t)80LL)))) { int64_t e_274 = f78_pmatch(); 
if (g717) { g718 = true;
 }
return e_274;
 }
if (((k_181) == (((int64_t)78LL)))) { (void)(f33_nx());
int64_t e_275 = f40_mk(((int64_t)24LL), st_180); 
{ int64_t q__276 = f66_pblock(hr_str("block expression", 16)); 
{ int32_t *_t808 = &(((*({ hrv *_t809 = &(g707); int64_t _i809 = e_275; (S4*)_t809->b + hr_ix(_i809, _t809->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:147"); }))).a_); *_t808 = ((int32_t)(q__276)); }
 }
if (g717) { g718 = true;
 }
return e_275;
 }
if (((k_181) == (((int64_t)9LL)))) { int64_t e_277 = f66_pblock(hr_str("block", 5)); 
if (g717) { g718 = true;
 }
return e_277;
 }
if (((k_181) == (((int64_t)74LL)))) { (void)(f33_nx());
int64_t e_278 = f40_mk(((int64_t)25LL), st_180); 
{ int64_t q__279 = f63_pscrut(); 
{ int32_t *_t814 = &(((*({ hrv *_t815 = &(g707); int64_t _i815 = e_278; (S4*)_t815->b + hr_ix(_i815, _t815->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:149"); }))).a_); *_t814 = ((int32_t)(q__279)); }
 }
{ int64_t q__280 = f66_pblock(hr_str("while body", 10)); 
{ int32_t *_t817 = &(((*({ hrv *_t818 = &(g707); int64_t _i818 = e_278; (S4*)_t818->b + hr_ix(_i818, _t818->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:149"); }))).b_); *_t817 = ((int32_t)(q__280)); }
 }
if (g717) { g718 = true;
 }
return e_278;
 }
if (((k_181) == (((int64_t)77LL)))) { (void)(f33_nx());
int64_t e_281 = f40_mk(((int64_t)26LL), st_180); 
{ int64_t q__282 = f66_pblock(hr_str("loop body", 9)); 
{ int32_t *_t822 = &(((*({ hrv *_t823 = &(g707); int64_t _i823 = e_281; (S4*)_t823->b + hr_ix(_i823, _t823->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:150"); }))).a_); *_t822 = ((int32_t)(q__282)); }
 }
if (g717) { g718 = true;
 }
return e_281;
 }
if (((k_181) == (((int64_t)75LL)))) { int64_t e_294 = f79_pfor(); 
if (g717) { g718 = true;
 }
return e_294;
 }
if (((k_181) == (((int64_t)79LL)))) { (void)(f38_perr(hr_str("guard is a statement: it guards the rest of the block it is in", 62)));
return f40_mk(((int64_t)6LL), st_180);
 }
if (((k_181) == (((int64_t)81LL)))) { (void)(f33_nx());
bool sl_295 = g717; 
bool se_296 = g718; 
g717 = false;
g718 = false;
int64_t r_297 = f40_mk(((int64_t)28LL), st_180); 
if (((((f31_tk()) != (((int64_t)12LL))) && ((f31_tk()) != (((int64_t)10LL)))) && (!(f42_at_from())))) { int64_t m_298 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v834 = &(g709); int32_t _x834 = ((int32_t)(f61_pexpr())); int32_t *_p834 = (int32_t*)hr_grow(_v834, 1, sizeof _x834); *_p834 = _x834; _p834; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk833; }
 }
 } _bk833:; 
(void)(f59_setl(r_297, m_298));
 }
if (f42_at_from()) { (void)(f33_nx());
{ int64_t q__299 = f56_qname(hr_str("return from", 11)); 
{ int32_t *_t841 = &(((*({ hrv *_t842 = &(g707); int64_t _i842 = r_297; (S4*)_t842->b + hr_ix(_i842, _t842->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:158"); }))).s_); *_t841 = ((int32_t)(q__299)); }
 }
 }
g717 = sl_295;
g718 = se_296;
return r_297;
 }
if (((k_181) == (((int64_t)82LL)))) { (void)(f33_nx());
bool sl_300 = g717; 
bool se_301 = g718; 
g717 = false;
g718 = false;
int64_t r_302 = f40_mk(((int64_t)29LL), st_180); 
if ((((f31_tk()) != (((int64_t)12LL))) && ((f31_tk()) != (((int64_t)10LL))))) { { int64_t q__303 = f61_pexpr(); 
{ int32_t *_t848 = &(((*({ hrv *_t849 = &(g707); int64_t _i849 = r_302; (S4*)_t849->b + hr_ix(_i849, _t849->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:166"); }))).a_); *_t848 = ((int32_t)(q__303)); }
 }
 }
g717 = sl_300;
g718 = se_301;
return r_302;
 }
if (((k_181) == (((int64_t)83LL)))) { (void)(f33_nx());
return f40_mk(((int64_t)30LL), st_180);
 }
return f80_pbin(((int64_t)1LL));
}
static int64_t f62_pif(void) {
int64_t st_182 = g712; 
(void)(f33_nx());
int64_t n_183 = f40_mk(((int64_t)19LL), st_182); 
{ int64_t q__189 = f63_pscrut(); 
{ int32_t *_t856 = &(((*({ hrv *_t857 = &(g707); int64_t _i857 = n_183; (S4*)_t857->b + hr_ix(_i857, _t857->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:180"); }))).a_); *_t856 = ((int32_t)(q__189)); }
 }
{ int64_t q__268 = f66_pblock(hr_str("if body", 7)); 
{ int32_t *_t859 = &(((*({ hrv *_t860 = &(g707); int64_t _i860 = n_183; (S4*)_t860->b + hr_ix(_i860, _t860->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:181"); }))).b_); *_t859 = ((int32_t)(q__268)); }
 }
if (f41_is(((int64_t)73LL))) { { int64_t q__269 = ({ int64_t _r862; if (((f31_tk()) == (((int64_t)72LL)))) { _r862 = f62_pif();  } else { _r862 = f66_pblock(hr_str("else body", 9));  } _r862; }); 
{ int32_t *_t866 = &(((*({ hrv *_t867 = &(g707); int64_t _i867 = n_183; (S4*)_t867->b + hr_ix(_i867, _t867->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:182"); }))).c_); *_t866 = ((int32_t)(q__269)); }
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
int64_t s_185 = ((int64_t)((int64_t)((int64_t)((int64_t)({ int64_t _r871; if (g716) { _r871 = ((int64_t)1LL);  } else { _r871 = ((int64_t)0LL);  } _r871; }) | (int64_t)({ int64_t _r872; if (g717) { _r872 = ((int64_t)2LL);  } else { _r872 = ((int64_t)0LL);  } _r872; }))) | (int64_t)({ int64_t _r873; if (g718) { _r873 = ((int64_t)4LL);  } else { _r873 = ((int64_t)0LL);  } _r873; }))); 
g716 = nosl_184;
g717 = false;
g718 = false;
return s_185;
}
static void f65_sub_end(int64_t s_188) {
g716 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)));
g717 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)));
g718 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL)));
}
static int64_t f66_pblock(hsl ctx_190) {
int64_t st_191 = g712; 
(void)(f39_ex(((int64_t)9LL), ctx_190));
int64_t b_192 = f40_mk(((int64_t)23LL), st_191); 
(void)(f67_pbody(b_192));
return b_192;
}
static void f67_pbody(int64_t b_193) {
int64_t s_194 = f64_sub_begin(false); 
int64_t m_195 = f52_wbeg(); 
for (;;) { g717 = false;
g718 = false;
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
if (((((((((f46_at_inline() || f47_at_checkfree()) || f48_at_lut()) || ((k_197) == (((int64_t)65LL)))) || ((k_197) == (((int64_t)61LL)))) || ((k_197) == (((int64_t)62LL)))) || ((k_197) == (((int64_t)68LL)))) || ((k_197) == (((int64_t)63LL)))) || ((k_197) == (((int64_t)64LL))))) { (void)(({ hrv *_v890 = &(g709); int32_t _x890 = ((int32_t)(f49_pfn(true, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p890 = (int32_t*)hr_grow(_v890, 1, sizeof _x890); *_p890 = _x890; _p890; }));
return true;
 }
if ((((((k_197) == (((int64_t)66LL))) || ((k_197) == (((int64_t)67LL)))) || ((k_197) == (((int64_t)69LL)))) || ((k_197) == (((int64_t)71LL))))) { if ((((k_197) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g712 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v893 = &(g709); int32_t _x893 = ((int32_t)(f69_pcfor(((int64_t)0LL)))); int32_t *_p893 = (int32_t*)hr_grow(_v893, 1, sizeof _x893); *_p893 = _x893; _p893; }));
return true;
 }
int64_t v_247 = f74_pvdecl(false); 
(void)(f39_ex(((int64_t)12LL), hr_str("variable declaration", 20)));
(void)(({ hrv *_v897 = &(g709); int32_t _x897 = ((int32_t)(v_247)); int32_t *_p897 = (int32_t*)hr_grow(_v897, 1, sizeof _x897); *_p897 = _x897; _p897; }));
return true;
 }
if (((k_197) == (((int64_t)79LL)))) { (void)(f76_pguard(b_196));
return false;
 }
g717 = true;
int64_t e_254 = f61_pexpr(); 
g717 = false;
int64_t st_255 = g712; 
if ((!(g718))) { int64_t o_256 = f31_tk(); 
if ((((((((((((((o_256) == (((int64_t)36LL))) || ((o_256) == (((int64_t)18LL)))) || ((o_256) == (((int64_t)26LL)))) || ((o_256) == (((int64_t)27LL)))) || ((o_256) == (((int64_t)28LL)))) || ((o_256) == (((int64_t)29LL)))) || ((o_256) == (((int64_t)30LL)))) || ((o_256) == (((int64_t)31LL)))) || ((o_256) == (((int64_t)32LL)))) || ((o_256) == (((int64_t)33LL)))) || ((o_256) == (((int64_t)45LL)))) || ((o_256) == (((int64_t)46LL))))) { (void)(f33_nx());
int64_t r_257 = f61_pexpr(); 
(void)(f39_ex(((int64_t)12LL), hr_str("assignment statement", 20)));
int64_t n_258 = f40_mk(((int64_t)34LL), st_255); 
{ uint8_t *_t905 = &(((*({ hrv *_t906 = &(g707); int64_t _i906 = n_258; (S4*)_t906->b + hr_ix(_i906, _t906->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:528"); }))).op_); *_t905 = ((uint8_t)(o_256)); }
{ int32_t *_t907 = &(((*({ hrv *_t908 = &(g707); int64_t _i908 = n_258; (S4*)_t908->b + hr_ix(_i908, _t908->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:528"); }))).a_); *_t907 = ((int32_t)(e_254)); }
{ int32_t *_t909 = &(((*({ hrv *_t910 = &(g707); int64_t _i910 = n_258; (S4*)_t910->b + hr_ix(_i910, _t910->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:528"); }))).b_); *_t909 = ((int32_t)(r_257)); }
(void)(({ hrv *_v911 = &(g709); int32_t _x911 = ((int32_t)(n_258)); int32_t *_p911 = (int32_t*)hr_grow(_v911, 1, sizeof _x911); *_p911 = _x911; _p911; }));
return true;
 }
if ((((o_256) == (((int64_t)34LL))) || ((o_256) == (((int64_t)35LL))))) { (void)(f33_nx());
(void)(f39_ex(((int64_t)12LL), hr_str("increment statement", 19)));
int64_t n_259 = f40_mk(((int64_t)35LL), st_255); 
{ uint8_t *_t915 = &(((*({ hrv *_t916 = &(g707); int64_t _i916 = n_259; (S4*)_t916->b + hr_ix(_i916, _t916->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:530"); }))).op_); *_t915 = ((uint8_t)(o_256)); }
{ int32_t *_t917 = &(((*({ hrv *_t918 = &(g707); int64_t _i918 = n_259; (S4*)_t918->b + hr_ix(_i918, _t918->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:530"); }))).a_); *_t917 = ((int32_t)(e_254)); }
(void)(({ hrv *_v919 = &(g709); int32_t _x919 = ((int32_t)(n_259)); int32_t *_p919 = (int32_t*)hr_grow(_v919, 1, sizeof _x919); *_p919 = _x919; _p919; }));
return true;
 }
if (((o_256) == (((int64_t)11LL)))) { (void)(({ hrv *_v920 = &(g709); int32_t _x920 = ((int32_t)(f77_pmulti(e_254, st_255))); int32_t *_p920 = (int32_t*)hr_grow(_v920, 1, sizeof _x920); *_p920 = _x920; _p920; }));
return true;
 }
 }
if (f41_is(((int64_t)12LL))) { (void)(({ hrv *_v923 = &(g709); int32_t _x923 = ((int32_t)(e_254)); int32_t *_p923 = (int32_t*)hr_grow(_v923, 1, sizeof _x923); *_p923 = _x923; _p923; }));
return true;
 }
if (f41_is(((int64_t)10LL))) { { int32_t *_t925 = &(((*({ hrv *_t926 = &(g707); int64_t _i926 = b_196; (S4*)_t926->b + hr_ix(_i926, _t926->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:534"); }))).a_); *_t925 = ((int32_t)(e_254)); }
return false;
 }
if (g718) { (void)(({ hrv *_v927 = &(g709); int32_t _x927 = ((int32_t)(e_254)); int32_t *_p927 = (int32_t*)hr_grow(_v927, 1, sizeof _x927); *_p927 = _x927; _p927; }));
return true;
 }
hrv m_267 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o929 = &(m_267); hr_fs(_o929, hr_str("';' expected after expression, found '", 38)); hr_fs(_o929, f35_cur_text()); hr_fs(_o929, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_267)));
return false;
}
static int64_t f69_pcfor(int64_t mode_198) {
int64_t cf_199 = f40_mk(((int64_t)37LL), g712); 
(void)(f39_ex(((int64_t)69LL), hr_str("const for", 9)));
(void)(f39_ex(((int64_t)75LL), hr_str("const for", 9)));
(void)(f39_ex(((int64_t)39LL), hr_str("const for bindings", 18)));
int64_t nb_200 = f40_mk(((int64_t)36LL), g712); 
int64_t m_201 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v939 = &(g709); int32_t _x939 = ((int32_t)(f34_ident(hr_str("const for binding", 17)))); int32_t *_p939 = (int32_t*)hr_grow(_v939, 1, sizeof _x939); *_p939 = _x939; _p939; }));
if (((!(f41_is(((int64_t)11LL)))) || ((f31_tk()) == (((int64_t)40LL))))) { { goto _bk938; }
 }
 } _bk938:; 
(void)(f59_setl(nb_200, m_201));
(void)(f58_close_angle(hr_str("const for bindings", 18)));
(void)(f39_ex(((int64_t)76LL), hr_str("const for", 9)));
{ int32_t *_t946 = &(((*({ hrv *_t947 = &(g707); int64_t _i947 = cf_199; (S4*)_t947->b + hr_ix(_i947, _t947->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:426"); }))).a_); *_t946 = ((int32_t)(nb_200)); }
int64_t src_202 = f40_mk(((int64_t)36LL), g712); 
if (f41_is(((int64_t)7LL))) { { uint8_t *_t950 = &(((*({ hrv *_t951 = &(g707); int64_t _i951 = cf_199; (S4*)_t951->b + hr_ix(_i951, _t951->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:429"); }))).op_); *_t950 = ((uint8_t)1LL); }
int64_t s_203 = f64_sub_begin(false); 
int64_t m2_204 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)8LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v957 = &(g709); int32_t _x957 = ((int32_t)(f61_pexpr())); int32_t *_p957 = (int32_t*)hr_grow(_v957, 1, sizeof _x957); *_p957 = _x957; _p957; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk954; }
 }
 } _bk954:; 
(void)(f39_ex(((int64_t)8LL), hr_str("const for constant list", 23)));
(void)(f59_setl(src_202, m2_204));
(void)(f65_sub_end(s_203));
 } else { int64_t q_205 = f34_ident(hr_str("const for source", 16)); 
{ uint8_t *_t964 = &(((*({ hrv *_t965 = &(g707); int64_t _i965 = cf_199; (S4*)_t965->b + hr_ix(_i965, _t965->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:435"); }))).op_); *_t964 = ((uint8_t)(({ uint8_t _r966; if (((q_205) == (g730))) { _r966 = ((uint8_t)2LL);  } else { _r966 = ({ uint8_t _r967; if (((q_205) == (g732))) { _r967 = ((uint8_t)3LL);  } else { _r967 = ({ uint8_t _r968; if (((q_205) == (g731))) { _r968 = ((uint8_t)4LL);  } else { _r968 = ((uint8_t)0LL);  } _r968; });  } _r967; });  } _r966; }))); }
if (((((*({ hrv *_t969 = &(g707); int64_t _i969 = cf_199; (S4*)_t969->b + hr_ix(_i969, _t969->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:436"); }))).op_) == (((uint8_t)0LL)))) { (void)(f38_perr(hr_str("const for source must be fields<T>, variants<E>, types<...>, or [constants]", 75)));
 }
(void)(f39_ex(((int64_t)39LL), hr_str("const for source", 16)));
int64_t m2_206 = f52_wbeg(); 
while (((((f31_tk()) != (((int64_t)40LL))) && ((f31_tk()) != (((int64_t)44LL)))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v977 = &(g709); int32_t _x977 = ((int32_t)(f53_ptype())); int32_t *_p977 = (int32_t*)hr_grow(_v977, 1, sizeof _x977); *_p977 = _x977; _p977; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk973; }
 }
 } _bk973:; 
(void)(f58_close_angle(hr_str("const for source", 16)));
(void)(f59_setl(src_202, m2_206));
 }
{ int32_t *_t982 = &(((*({ hrv *_t983 = &(g707); int64_t _i983 = cf_199; (S4*)_t983->b + hr_ix(_i983, _t983->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:440"); }))).b_); *_t982 = ((int32_t)(src_202)); }
{ uint16_t *_t984 = &(((*({ hrv *_t985 = &(g707); int64_t _i985 = cf_199; (S4*)_t985->b + hr_ix(_i985, _t985->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:441"); }))).fl_); *_t984 = ((uint16_t)(mode_198)); }
if (((mode_198) == (((int64_t)1LL)))) { int64_t il_207 = f40_mk(((int64_t)36LL), g712); 
(void)(f70_pinits(il_207, true));
{ int32_t *_t988 = &(((*({ hrv *_t989 = &(g707); int64_t _i989 = cf_199; (S4*)_t989->b + hr_ix(_i989, _t989->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:442"); }))).c_); *_t988 = ((int32_t)(il_207)); }
 } else { if (((mode_198) == (((int64_t)2LL)))) { (void)(f39_ex(((int64_t)9LL), hr_str("const for arms", 14)));
int64_t al_214 = f40_mk(((int64_t)36LL), g712); 
(void)(f71_parms(al_214));
(void)(f39_ex(((int64_t)10LL), hr_str("const for arms", 14)));
{ int32_t *_t994 = &(((*({ hrv *_t995 = &(g707); int64_t _i995 = cf_199; (S4*)_t995->b + hr_ix(_i995, _t995->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:443"); }))).c_); *_t994 = ((int32_t)(al_214)); }
 } else { { int64_t q__237 = f66_pblock(hr_str("const for body", 14)); 
{ int32_t *_t997 = &(((*({ hrv *_t998 = &(g707); int64_t _i998 = cf_199; (S4*)_t998->b + hr_ix(_i998, _t998->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:443"); }))).c_); *_t997 = ((int32_t)(q__237)); }
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
{ uint16_t *_t1007 = &(((*({ hrv *_t1008 = &(g707); int64_t _i1008 = n_208; (S4*)_t1008->b + hr_ix(_i1008, _t1008->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:451"); }))).fl_); *_t1007 = ((uint16_t)((uint64_t)(*_t1007) | (uint64_t)((uint16_t)1LL))); }
{ goto _bk1002; }
 }
if ((((f31_tk()) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g712 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v1011 = &(g709); int32_t _x1011 = ((int32_t)(f69_pcfor(((int64_t)1LL)))); int32_t *_p1011 = (int32_t*)hr_grow(_v1011, 1, sizeof _x1011); *_p1011 = _x1011; _p1011; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1002; }
 }
continue;
 }
int64_t fi_212 = f40_mk(((int64_t)18LL), g712); 
if ((((f31_tk()) == (((int64_t)1LL))) && ((f44_tkat(((int64_t)((int64_t)g712 + (int64_t)((int64_t)1LL))))) == (((int64_t)13LL))))) { { int32_t *_t1017 = &(((*({ hrv *_t1018 = &(g707); int64_t _i1018 = fi_212; (S4*)_t1018->b + hr_ix(_i1018, _t1018->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:454"); }))).s_); *_t1017 = ((int32_t)(((*({ hrv *_t1019 = &(g917); int64_t _i1019 = g712; (S3*)_t1019->b + hr_ix(_i1019, _t1019->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:454"); }))).v_)); }
(void)(f33_nx());
(void)(f33_nx());
 }
{ int64_t q__213 = f61_pexpr(); 
{ int32_t *_t1023 = &(((*({ hrv *_t1024 = &(g707); int64_t _i1024 = fi_212; (S4*)_t1024->b + hr_ix(_i1024, _t1024->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:455"); }))).a_); *_t1023 = ((int32_t)(q__213)); }
 }
(void)(({ hrv *_v1025 = &(g709); int32_t _x1025 = ((int32_t)(fi_212)); int32_t *_p1025 = (int32_t*)hr_grow(_v1025, 1, sizeof _x1025); *_p1025 = _x1025; _p1025; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1002; }
 }
 } _bk1002:; 
(void)(f39_ex(((int64_t)10LL), hr_str("struct literal", 14)));
(void)(f59_setl(n_208, m_211));
(void)(f65_sub_end(s_210));
}
static void f71_parms(int64_t n_215) {
int64_t s_216 = f64_sub_begin(g716); 
int64_t m_217 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { if ((((f31_tk()) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g712 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v1037 = &(g709); int32_t _x1037 = ((int32_t)(f69_pcfor(((int64_t)2LL)))); int32_t *_p1037 = (int32_t*)hr_grow(_v1037, 1, sizeof _x1037); *_p1037 = _x1037; _p1037; }));
 } else { int64_t a_235 = f72_ppattern(); 
(void)(f39_ex(((int64_t)55LL), hr_str("match arm", 9)));
{ int64_t q__236 = f61_pexpr(); 
{ int32_t *_t1042 = &(((*({ hrv *_t1043 = &(g707); int64_t _i1043 = a_235; (S4*)_t1043->b + hr_ix(_i1043, _t1043->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:218"); }))).b_); *_t1042 = ((int32_t)(q__236)); }
 }
(void)(({ hrv *_v1044 = &(g709); int32_t _x1044 = ((int32_t)(a_235)); int32_t *_p1044 = (int32_t*)hr_grow(_v1044, 1, sizeof _x1044); *_p1044 = _x1044; _p1044; }));
 }
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1032; }
 }
 } _bk1032:; 
(void)(f59_setl(n_215, m_217));
(void)(f65_sub_end(s_216));
}
static int64_t f72_ppattern(void) {
int64_t a_218 = f40_mk(((int64_t)21LL), g712); 
if (f43_at_word(g728)) { (void)(f33_nx());
{ uint16_t *_t1051 = &(((*({ hrv *_t1052 = &(g707); int64_t _i1052 = a_218; (S4*)_t1052->b + hr_ix(_i1052, _t1052->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:226"); }))).fl_); *_t1051 = ((uint16_t)1LL); }
if (((f31_tk()) == (((int64_t)11LL)))) { (void)(f38_perr(hr_str("_ cannot be listed with other patterns", 38)));
 }
return a_218;
 }
int64_t m_219 = f52_wbeg(); 
for (;;) { int64_t it_220 = f40_mk(((int64_t)22LL), g712); 
{ int64_t q__229 = f73_pbound(); 
{ int32_t *_t1059 = &(((*({ hrv *_t1060 = &(g707); int64_t _i1060 = it_220; (S4*)_t1060->b + hr_ix(_i1060, _t1060->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:230"); }))).a_); *_t1059 = ((int32_t)(q__229)); }
 }
if (f41_is(((int64_t)17LL))) { { int64_t q__230 = f73_pbound(); 
{ int32_t *_t1063 = &(((*({ hrv *_t1064 = &(g707); int64_t _i1064 = it_220; (S4*)_t1064->b + hr_ix(_i1064, _t1064->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:231"); }))).b_); *_t1063 = ((int32_t)(q__230)); }
 }
 }
(void)(({ hrv *_v1065 = &(g709); int32_t _x1065 = ((int32_t)(it_220)); int32_t *_p1065 = (int32_t*)hr_grow(_v1065, 1, sizeof _x1065); *_p1065 = _x1065; _p1065; }));
int64_t lo_231 = ((int64_t)(((*({ hrv *_t1066 = &(g707); int64_t _i1066 = it_220; (S4*)_t1066->b + hr_ix(_i1066, _t1066->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:233"); }))).a_)); 
if (((((((*({ hrv *_t1067 = &(g707); int64_t _i1067 = lo_231; (S4*)_t1067->b + hr_ix(_i1067, _t1067->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:234"); }))).k_) == (((uint8_t)8LL))) && ((((*({ hrv *_t1068 = &(g707); int64_t _i1068 = it_220; (S4*)_t1068->b + hr_ix(_i1068, _t1068->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:234"); }))).b_) < (((int32_t)0LL)))) && (((f31_tk()) == (((int64_t)49LL))) || ((f31_tk()) == (((int64_t)1LL)))))) { bool hasq_232 = false; 
{ hsl _v1072 = f10_nm(((int64_t)(((*({ hrv *_t1074 = &(g707); int64_t _i1074 = lo_231; (S4*)_t1074->b + hr_ix(_i1074, _t1074->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:235"); }))).s_))); for (int64_t _k1072 = 0; _k1072 < _v1072.n; _k1072++) { uint8_t c_233 = ((uint8_t*)_v1072.p)[_k1072]; if (((c_233) == (((uint8_t)58LL)))) { hasq_232 = true;
 }
 } } _bk1071:; 
if ((!(hasq_232))) { if (((((int64_t)((int64_t)(g709).n - (int64_t)m_219))) > (((int64_t)1LL)))) { (void)(f38_perr(hr_str("a list of patterns binds no payload: give the variant an arm of its own", 71)));
 }
if (f41_is(((int64_t)49LL))) { { uint16_t *_t1077 = &(((*({ hrv *_t1078 = &(g707); int64_t _i1078 = a_218; (S4*)_t1078->b + hr_ix(_i1078, _t1078->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:238"); }))).fl_); *_t1077 = ((uint16_t)((uint64_t)(*_t1077) | (uint64_t)((uint16_t)2LL))); }
 }
{ int64_t q__234 = f34_ident(hr_str("match binding", 13)); 
{ int32_t *_t1080 = &(((*({ hrv *_t1081 = &(g707); int64_t _i1081 = a_218; (S4*)_t1081->b + hr_ix(_i1081, _t1081->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:239"); }))).s_); *_t1080 = ((int32_t)(q__234)); }
 }
if (((f31_tk()) == (((int64_t)11LL)))) { (void)(f38_perr(hr_str("a list of patterns binds no payload: give the variant an arm of its own", 71)));
 }
(void)(f59_setl(a_218, m_219));
return a_218;
 }
 }
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1056; }
 }
if (f43_at_word(g728)) { (void)(f38_perr(hr_str("_ cannot be listed with other patterns", 38)));
 }
 } _bk1056:; 
(void)(f59_setl(a_218, m_219));
return a_218;
}
static int64_t f73_pbound(void) {
int64_t st_221 = g712; 
bool neg_222 = f41_is(((int64_t)22LL)); 
if ((((f31_tk()) == (((int64_t)1LL))) || ((f31_tk()) == (((int64_t)15LL))))) { int64_t n_223 = f40_mk(((int64_t)8LL), g712); 
{ int64_t q__224 = f56_qname(hr_str("match pattern", 13)); 
{ int32_t *_t1094 = &(((*({ hrv *_t1095 = &(g707); int64_t _i1095 = n_223; (S4*)_t1095->b + hr_ix(_i1095, _t1095->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:254"); }))).s_); *_t1094 = ((int32_t)(q__224)); }
 }
if (neg_222) { int64_t u_225 = f40_mk(((int64_t)10LL), st_221); 
{ uint8_t *_t1097 = &(((*({ hrv *_t1098 = &(g707); int64_t _i1098 = u_225; (S4*)_t1098->b + hr_ix(_i1098, _t1098->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:254"); }))).op_); *_t1097 = ((uint8_t)(((uint8_t)22LL))); }
{ int32_t *_t1099 = &(((*({ hrv *_t1100 = &(g707); int64_t _i1100 = u_225; (S4*)_t1100->b + hr_ix(_i1100, _t1100->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:254"); }))).a_); *_t1099 = ((int32_t)(n_223)); }
return u_225;
 }
return n_223;
 }
if (((f31_tk()) != (((int64_t)2LL)))) { hrv m_226 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1103 = &(m_226); hr_fs(_o1103, hr_str("integer constant expected in match pattern, found '", 51)); hr_fs(_o1103, f35_cur_text()); hr_fs(_o1103, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_226)));
return f40_mk(((int64_t)1LL), st_221);
 }
int64_t n_227 = f40_mk(((int64_t)1LL), g712); 
(void)(f33_nx());
if (neg_222) { int64_t u_228 = f40_mk(((int64_t)10LL), st_221); 
{ uint8_t *_t1110 = &(((*({ hrv *_t1111 = &(g707); int64_t _i1111 = u_228; (S4*)_t1111->b + hr_ix(_i1111, _t1111->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:257"); }))).op_); *_t1110 = ((uint8_t)(((uint8_t)22LL))); }
{ int32_t *_t1112 = &(((*({ hrv *_t1113 = &(g707); int64_t _i1113 = u_228; (S4*)_t1113->b + hr_ix(_i1113, _t1113->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:257"); }))).a_); *_t1112 = ((int32_t)(n_227)); }
return u_228;
 }
return n_227;
}
static int64_t f74_pvdecl(bool glob_238) {
int64_t st_239 = g712; 
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
for (;;) { (void)(({ hrv *_v1129 = &(g709); int32_t _x1129 = ((int32_t)(({ int64_t _r1130; if (glob_238) { _r1130 = f50_declname(hr_str("global declaration", 18));  } else { _r1130 = f34_ident(hr_str("variable declaration", 20));  } _r1130; }))); int32_t *_p1129 = (int32_t*)hr_grow(_v1129, 1, sizeof _x1129); *_p1129 = _x1129; _p1129; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1128; }
 }
 } _bk1128:; 
(void)(f59_setl(v_241, m_242));
{ int32_t *_t1135 = &(((*({ hrv *_t1136 = &(g707); int64_t _i1136 = v_241; (S4*)_t1136->b + hr_ix(_i1136, _t1136->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:571"); }))).c_); *_t1135 = ((int32_t)(g719)); }
if ((f41_is(((int64_t)13LL)) || f75_amni_type())) { { int64_t q__244 = f53_ptype(); 
{ int32_t *_t1140 = &(((*({ hrv *_t1141 = &(g707); int64_t _i1141 = v_241; (S4*)_t1141->b + hr_ix(_i1141, _t1141->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:572"); }))).a_); *_t1140 = ((int32_t)(q__244)); }
 }
 }
if (f41_is(((int64_t)18LL))) { { int64_t *_t1143 = &(fl_240); *_t1143 = ((int64_t)((int64_t)(*_t1143) | (int64_t)((int64_t)4LL))); }
 }
if ((((((int64_t)((int64_t)fl_240 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL))) || f41_is(((int64_t)36LL)))) { int64_t il_245 = f40_mk(((int64_t)36LL), g712); 
int64_t m2_246 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v1148 = &(g709); int32_t _x1148 = ((int32_t)(f61_pexpr())); int32_t *_p1148 = (int32_t*)hr_grow(_v1148, 1, sizeof _x1148); *_p1148 = _x1148; _p1148; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1147; }
 }
 } _bk1147:; 
(void)(f59_setl(il_245, m2_246));
{ int32_t *_t1152 = &(((*({ hrv *_t1153 = &(g707); int64_t _i1153 = v_241; (S4*)_t1153->b + hr_ix(_i1153, _t1153->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:574"); }))).b_); *_t1152 = ((int32_t)(il_245)); }
 }
{ uint16_t *_t1154 = &(((*({ hrv *_t1155 = &(g707); int64_t _i1155 = v_241; (S4*)_t1155->b + hr_ix(_i1155, _t1155->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:575"); }))).fl_); *_t1154 = ((uint16_t)(fl_240)); }
if (glob_238) { if ((((((*({ hrv *_t1156 = &(g707); int64_t _i1156 = v_241; (S4*)_t1156->b + hr_ix(_i1156, _t1156->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:577"); }))).b_) < (((int32_t)0LL))) && ((((int64_t)((int64_t)fl_240 & (int64_t)((int64_t)1LL)))) == (((int64_t)0LL))))) { (void)(f38_perr(hr_str("let and const global declarations require an initializer", 56)));
 }
if (((((*({ hrv *_t1158 = &(g707); int64_t _i1158 = v_241; (S4*)_t1158->b + hr_ix(_i1158, _t1158->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:578"); }))).n_) != (((int32_t)1LL)))) { (void)(f38_perr(hr_str("global declarations declare a single name", 41)));
 }
 }
return v_241;
}
static bool f75_amni_type(void) {
int64_t k_243 = f31_tk(); 
return (((*({ hrv *_t1161 = &(g916); int64_t _i1161 = ((*({ hrv *_t1162 = &(g917); int64_t _i1162 = g712; (S3*)_t1162->b + hr_ix(_i1162, _t1162->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:74"); }))).f_; (S2*)_t1161->b + hr_ix(_i1161, _t1161->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:74"); }))).amni_ && (((((f55_prim_tok(k_243) || ((k_243) == (((int64_t)1LL)))) || ((k_243) == (((int64_t)15LL)))) || ((k_243) == (((int64_t)61LL)))) || ((k_243) == (((int64_t)5LL)))) || ((k_243) == (((int64_t)69LL)))));
}
static void f76_pguard(int64_t b_248) {
int64_t st_249 = g712; 
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
{ int32_t *_t1173 = &(((*({ hrv *_t1174 = &(g707); int64_t _i1174 = i_253; (S4*)_t1174->b + hr_ix(_i1174, _t1174->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).a_); *_t1173 = ((int32_t)(c_250)); }
{ int32_t *_t1175 = &(((*({ hrv *_t1176 = &(g707); int64_t _i1176 = i_253; (S4*)_t1176->b + hr_ix(_i1176, _t1176->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).b_); *_t1175 = ((int32_t)(rest_252)); }
{ int32_t *_t1177 = &(((*({ hrv *_t1178 = &(g707); int64_t _i1178 = i_253; (S4*)_t1178->b + hr_ix(_i1178, _t1178->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).c_); *_t1177 = ((int32_t)(eb_251)); }
{ uint16_t *_t1179 = &(((*({ hrv *_t1180 = &(g707); int64_t _i1180 = i_253; (S4*)_t1180->b + hr_ix(_i1180, _t1180->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).fl_); *_t1179 = ((uint16_t)1LL); }
if (((((*({ hrv *_t1181 = &(g707); int64_t _i1181 = rest_252; (S4*)_t1181->b + hr_ix(_i1181, _t1181->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:560"); }))).a_) >= (((int32_t)0LL)))) { { int32_t *_t1182 = &(((*({ hrv *_t1183 = &(g707); int64_t _i1183 = b_248; (S4*)_t1183->b + hr_ix(_i1183, _t1183->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:560"); }))).a_); *_t1182 = ((int32_t)(i_253)); }
 } else { (void)(({ hrv *_v1184 = &(g709); int32_t _x1184 = ((int32_t)(i_253)); int32_t *_p1184 = (int32_t*)hr_grow(_v1184, 1, sizeof _x1184); *_p1184 = _x1184; _p1184; }));
 }
}
static int64_t f77_pmulti(int64_t first_260, int64_t st_261) {
int64_t tl_262 = f40_mk(((int64_t)36LL), st_261); 
int64_t m_263 = f52_wbeg(); 
(void)(({ hrv *_v1187 = &(g709); int32_t _x1187 = ((int32_t)(first_260)); int32_t *_p1187 = (int32_t*)hr_grow(_v1187, 1, sizeof _x1187); *_p1187 = _x1187; _p1187; }));
while (f41_is(((int64_t)11LL))) { (void)(({ hrv *_v1190 = &(g709); int32_t _x1190 = ((int32_t)(f61_pexpr())); int32_t *_p1190 = (int32_t*)hr_grow(_v1190, 1, sizeof _x1190); *_p1190 = _x1190; _p1190; }));
 } _bk1188:; 
(void)(f59_setl(tl_262, m_263));
int64_t o_264 = f31_tk(); 
if (((((((((((((o_264) == (((int64_t)18LL))) || ((o_264) == (((int64_t)26LL)))) || ((o_264) == (((int64_t)27LL)))) || ((o_264) == (((int64_t)28LL)))) || ((o_264) == (((int64_t)29LL)))) || ((o_264) == (((int64_t)30LL)))) || ((o_264) == (((int64_t)31LL)))) || ((o_264) == (((int64_t)32LL)))) || ((o_264) == (((int64_t)33LL)))) || ((o_264) == (((int64_t)45LL)))) || ((o_264) == (((int64_t)46LL))))) { (void)(f38_perr(hr_str("several targets take a call's results with `=` alone (\302\2477.1)", 60)));
 }
if (((f31_tk()) != (((int64_t)36LL)))) { (void)(f38_perr(hr_str("several values exist only in `return a, b;` and in a call's results, so a block or branch cannot end in `a, b`: return from each branch instead (\302\2477.1)", 151)));
 }
(void)(f33_nx());
int64_t n_265 = f40_mk(((int64_t)34LL), st_261); 
{ uint8_t *_t1199 = &(((*({ hrv *_t1200 = &(g707); int64_t _i1200 = n_265; (S4*)_t1200->b + hr_ix(_i1200, _t1200->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:548"); }))).op_); *_t1199 = ((uint8_t)(((uint8_t)11LL))); }
{ int32_t *_t1201 = &(((*({ hrv *_t1202 = &(g707); int64_t _i1202 = n_265; (S4*)_t1202->b + hr_ix(_i1202, _t1202->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:548"); }))).a_); *_t1201 = ((int32_t)(tl_262)); }
{ int64_t q__266 = f61_pexpr(); 
{ int32_t *_t1204 = &(((*({ hrv *_t1205 = &(g707); int64_t _i1205 = n_265; (S4*)_t1205->b + hr_ix(_i1205, _t1205->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:548"); }))).b_); *_t1204 = ((int32_t)(q__266)); }
 }
(void)(f39_ex(((int64_t)12LL), hr_str("assignment statement", 20)));
return n_265;
}
static int64_t f78_pmatch(void) {
int64_t st_271 = g712; 
(void)(f33_nx());
int64_t n_272 = f40_mk(((int64_t)20LL), st_271); 
{ int64_t q__273 = f63_pscrut(); 
{ int32_t *_t1210 = &(((*({ hrv *_t1211 = &(g707); int64_t _i1211 = n_272; (S4*)_t1211->b + hr_ix(_i1211, _t1211->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:206"); }))).a_); *_t1210 = ((int32_t)(q__273)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("match expression", 16)));
(void)(f71_parms(n_272));
(void)(f39_ex(((int64_t)10LL), hr_str("match expression", 16)));
if ((((((*({ hrv *_t1215 = &(g707); int64_t _i1215 = n_272; (S4*)_t1215->b + hr_ix(_i1215, _t1215->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:210"); }))).n_) == (((int32_t)0LL))) && (((g713).n) == (((int64_t)0LL))))) { (void)(f38_perr(hr_str("match must have at least one arm", 32)));
 }
return n_272;
}
static int64_t f79_pfor(void) {
int64_t st_283 = g712; 
(void)(f33_nx());
int64_t n_284 = f40_mk(((int64_t)27LL), st_283); 
if (f41_is(((int64_t)49LL))) { { uint16_t *_t1220 = &(((*({ hrv *_t1221 = &(g707); int64_t _i1221 = n_284; (S4*)_t1221->b + hr_ix(_i1221, _t1221->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:188"); }))).fl_); *_t1220 = ((uint16_t)1LL); }
 }
{ int64_t q__285 = f34_ident(hr_str("for binding", 11)); 
{ int32_t *_t1223 = &(((*({ hrv *_t1224 = &(g707); int64_t _i1224 = n_284; (S4*)_t1224->b + hr_ix(_i1224, _t1224->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:189"); }))).s_); *_t1223 = ((int32_t)(q__285)); }
 }
bool fb_286 = g759; 
g759 = true;
{ int32_t *_t1225 = &(((*({ hrv *_t1226 = &(g707); int64_t _i1226 = n_284; (S4*)_t1226->b + hr_ix(_i1226, _t1226->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:191"); }))).l_); *_t1225 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
{ int32_t *_t1227 = &(((*({ hrv *_t1228 = &(g707); int64_t _i1228 = n_284; (S4*)_t1228->b + hr_ix(_i1228, _t1228->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:191"); }))).n_); *_t1227 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
if (f41_is(((int64_t)13LL))) { { int64_t q__287 = f53_ptype(); 
{ int32_t *_t1231 = &(((*({ hrv *_t1232 = &(g707); int64_t _i1232 = n_284; (S4*)_t1232->b + hr_ix(_i1232, _t1232->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:192"); }))).l_); *_t1231 = ((int32_t)(q__287)); }
 }
 }
if (f41_is(((int64_t)11LL))) { { int64_t q__288 = f34_ident(hr_str("for index binding", 17)); 
{ int32_t *_t1235 = &(((*({ hrv *_t1236 = &(g707); int64_t _i1236 = n_284; (S4*)_t1236->b + hr_ix(_i1236, _t1236->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:193"); }))).c_); *_t1235 = ((int32_t)(q__288)); }
 }
if (f41_is(((int64_t)13LL))) { { int64_t q__289 = f53_ptype(); 
{ int32_t *_t1239 = &(((*({ hrv *_t1240 = &(g707); int64_t _i1240 = n_284; (S4*)_t1240->b + hr_ix(_i1240, _t1240->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:193"); }))).n_); *_t1239 = ((int32_t)(q__289)); }
 }
 }
 }
g759 = fb_286;
(void)(f39_ex(((int64_t)76LL), hr_str("for statement", 13)));
int64_t s_290 = f64_sub_begin(true); 
{ int64_t q__291 = f61_pexpr(); 
{ int32_t *_t1244 = &(((*({ hrv *_t1245 = &(g707); int64_t _i1245 = n_284; (S4*)_t1245->b + hr_ix(_i1245, _t1245->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:197"); }))).a_); *_t1244 = ((int32_t)(q__291)); }
 }
if (f41_is(((int64_t)17LL))) { { int64_t q__292 = f61_pexpr(); 
{ int32_t *_t1248 = &(((*({ hrv *_t1249 = &(g707); int64_t _i1249 = n_284; (S4*)_t1249->b + hr_ix(_i1249, _t1249->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:198"); }))).b_); *_t1248 = ((int32_t)(q__292)); }
 }
 }
(void)(f65_sub_end(s_290));
{ int64_t q__293 = f66_pblock(hr_str("for body", 8)); 
{ int32_t *_t1252 = &(((*({ hrv *_t1253 = &(g707); int64_t _i1253 = n_284; (S4*)_t1253->b + hr_ix(_i1253, _t1253->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:200"); }))).d_); *_t1252 = ((int32_t)(q__293)); }
 }
return n_284;
}
static int64_t f80_pbin(int64_t minp_304) {
int64_t l_383 = f81_pun(); 
for (;;) { if (g718) { return l_383;
 }
int64_t pr_385 = f92_binprec(f31_tk()); 
if ((((pr_385) < (minp_304)) || ((pr_385) == (((int64_t)0LL))))) { return l_383;
 }
int64_t op_386 = f31_tk(); 
int64_t st_387 = g712; 
(void)(f33_nx());
int64_t s_388 = f64_sub_begin(g716); 
int64_t r_389 = f80_pbin(((int64_t)((int64_t)pr_385 + (int64_t)((int64_t)1LL)))); 
(void)(f65_sub_end(s_388));
int64_t n_390 = f40_mk(((int64_t)9LL), st_387); 
{ uint8_t *_t1264 = &(((*({ hrv *_t1265 = &(g707); int64_t _i1265 = n_390; (S4*)_t1265->b + hr_ix(_i1265, _t1265->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:280"); }))).op_); *_t1264 = ((uint8_t)(op_386)); }
{ int32_t *_t1266 = &(((*({ hrv *_t1267 = &(g707); int64_t _i1267 = n_390; (S4*)_t1267->b + hr_ix(_i1267, _t1267->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:280"); }))).a_); *_t1266 = ((int32_t)(l_383)); }
{ int32_t *_t1268 = &(((*({ hrv *_t1269 = &(g707); int64_t _i1269 = n_390; (S4*)_t1269->b + hr_ix(_i1269, _t1269->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:280"); }))).b_); *_t1268 = ((int32_t)(r_389)); }
l_383 = n_390;
 } _bk1255:; 
}
static int64_t f81_pun(void) {
int64_t k_305 = f31_tk(); 
if ((((((k_305) == (((int64_t)22LL))) || ((k_305) == (((int64_t)47LL)))) || ((k_305) == (((int64_t)48LL)))) || ((k_305) == (((int64_t)49LL))))) { int64_t st_306 = g712; 
(void)(f33_nx());
int64_t s_307 = f64_sub_begin(g716); 
int64_t a_308 = f81_pun(); 
(void)(f65_sub_end(s_307));
int64_t n_309 = f40_mk(((int64_t)10LL), st_306); 
{ uint8_t *_t1276 = &(((*({ hrv *_t1277 = &(g707); int64_t _i1277 = n_309; (S4*)_t1277->b + hr_ix(_i1277, _t1277->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:291"); }))).op_); *_t1276 = ((uint8_t)(k_305)); }
{ int32_t *_t1278 = &(((*({ hrv *_t1279 = &(g707); int64_t _i1279 = n_309; (S4*)_t1279->b + hr_ix(_i1279, _t1279->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:291"); }))).a_); *_t1278 = ((int32_t)(a_308)); }
return n_309;
 }
return f82_ppost();
}
static int64_t f82_ppost(void) {
int64_t e_367 = f83_pprim(); 
for (;;) { if (g718) { return e_367;
 }
int64_t st_368 = g712; 
if (f41_is(((int64_t)5LL))) { e_367 = f86_pcall(e_367, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), st_368);
continue;
 }
if (((f31_tk()) == (((int64_t)7LL)))) { e_367 = f91_pindex(e_367);
continue;
 }
if (f41_is(((int64_t)16LL))) { int64_t nmid_377 = f34_ident(hr_str("field access", 12)); 
if (((((f31_tk()) == (((int64_t)9LL))) && (!(g716))) && ((((*({ hrv *_t1290 = &(g707); int64_t _i1290 = e_367; (S4*)_t1290->b + hr_ix(_i1290, _t1290->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:305"); }))).k_) == (((uint8_t)8LL))))) { int64_t b_378 = f40_mk(((int64_t)41LL), ((int64_t)(((*({ hrv *_t1292 = &(g707); int64_t _i1292 = e_367; (S4*)_t1292->b + hr_ix(_i1292, _t1292->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:306"); }))).t_))); 
{ int32_t *_t1293 = &(((*({ hrv *_t1294 = &(g707); int64_t _i1294 = b_378; (S4*)_t1294->b + hr_ix(_i1294, _t1294->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:306"); }))).s_); *_t1293 = ((*({ hrv *_t1295 = &(g707); int64_t _i1295 = e_367; (S4*)_t1295->b + hr_ix(_i1295, _t1295->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:306"); }))).s_; }
int64_t v_379 = f40_mk(((int64_t)46LL), st_368); 
{ int32_t *_t1297 = &(((*({ hrv *_t1298 = &(g707); int64_t _i1298 = v_379; (S4*)_t1298->b + hr_ix(_i1298, _t1298->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:307"); }))).a_); *_t1297 = ((int32_t)(b_378)); }
{ int32_t *_t1299 = &(((*({ hrv *_t1300 = &(g707); int64_t _i1300 = v_379; (S4*)_t1300->b + hr_ix(_i1300, _t1300->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:307"); }))).s_); *_t1299 = ((int32_t)(nmid_377)); }
e_367 = f89_pslit(v_379, st_368);
 } else { int64_t d_380 = f40_mk(((int64_t)14LL), st_368); 
{ int32_t *_t1303 = &(((*({ hrv *_t1304 = &(g707); int64_t _i1304 = d_380; (S4*)_t1304->b + hr_ix(_i1304, _t1304->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:309"); }))).a_); *_t1303 = ((int32_t)(e_367)); }
{ int32_t *_t1305 = &(((*({ hrv *_t1306 = &(g707); int64_t _i1306 = d_380; (S4*)_t1306->b + hr_ix(_i1306, _t1306->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:309"); }))).s_); *_t1305 = ((int32_t)(nmid_377)); }
e_367 = d_380;
 }
continue;
 }
if (f41_is(((int64_t)84LL))) { int64_t n_381 = f40_mk(((int64_t)15LL), st_368); 
{ uint16_t *_t1309 = &(((*({ hrv *_t1310 = &(g707); int64_t _i1310 = n_381; (S4*)_t1310->b + hr_ix(_i1310, _t1310->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:312"); }))).fl_); *_t1309 = ({ uint16_t _r1311; if (f41_is(((int64_t)47LL))) { _r1311 = ((uint16_t)1LL);  } else { _r1311 = ((uint16_t)0LL);  } _r1311; }); }
{ int32_t *_t1313 = &(((*({ hrv *_t1314 = &(g707); int64_t _i1314 = n_381; (S4*)_t1314->b + hr_ix(_i1314, _t1314->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:312"); }))).a_); *_t1313 = ((int32_t)(e_367)); }
{ int64_t q__382 = f53_ptype(); 
{ int32_t *_t1316 = &(((*({ hrv *_t1317 = &(g707); int64_t _i1317 = n_381; (S4*)_t1317->b + hr_ix(_i1317, _t1317->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:312"); }))).b_); *_t1316 = ((int32_t)(q__382)); }
 }
e_367 = n_381;
continue;
 }
return e_367;
 } _bk1282:; 
}
static int64_t f83_pprim(void) {
int64_t st_310 = g712; 
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
{ int32_t *_t1344 = &(((*({ hrv *_t1345 = &(g707); int64_t _i1345 = id_332; (S4*)_t1345->b + hr_ix(_i1345, _t1345->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:364"); }))).s_); *_t1344 = ((int32_t)(name_321)); }
return f86_pcall(id_332, ta_331, st_310);
 }
int64_t t_352 = f40_mk(((int64_t)41LL), st_310); 
{ int32_t *_t1348 = &(((*({ hrv *_t1349 = &(g707); int64_t _i1349 = t_352; (S4*)_t1349->b + hr_ix(_i1349, _t1349->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).s_); *_t1348 = ((int32_t)(name_321)); }
{ int32_t *_t1350 = &(((*({ hrv *_t1351 = &(g707); int64_t _i1351 = t_352; (S4*)_t1351->b + hr_ix(_i1351, _t1351->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).l_); *_t1350 = ((*({ hrv *_t1352 = &(g707); int64_t _i1352 = ta_331; (S4*)_t1352->b + hr_ix(_i1352, _t1352->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).l_; }
{ int32_t *_t1353 = &(((*({ hrv *_t1354 = &(g707); int64_t _i1354 = t_352; (S4*)_t1354->b + hr_ix(_i1354, _t1354->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).n_); *_t1353 = ((*({ hrv *_t1355 = &(g707); int64_t _i1355 = ta_331; (S4*)_t1355->b + hr_ix(_i1355, _t1355->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).n_; }
if (f41_is(((int64_t)16LL))) { int64_t v_353 = f40_mk(((int64_t)46LL), st_310); 
{ int32_t *_t1358 = &(((*({ hrv *_t1359 = &(g707); int64_t _i1359 = v_353; (S4*)_t1359->b + hr_ix(_i1359, _t1359->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:366"); }))).a_); *_t1358 = ((int32_t)(t_352)); }
{ int64_t q__354 = f34_ident(hr_str("variant literal", 15)); 
{ int32_t *_t1361 = &(((*({ hrv *_t1362 = &(g707); int64_t _i1362 = v_353; (S4*)_t1362->b + hr_ix(_i1362, _t1362->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:366"); }))).s_); *_t1361 = ((int32_t)(q__354)); }
 }
return f89_pslit(v_353, st_310);
 }
return f89_pslit(t_352, st_310);
 }
 }
if ((((f31_tk()) == (((int64_t)9LL))) && (!(g716)))) { int64_t t_364 = f40_mk(((int64_t)41LL), st_310); 
{ int32_t *_t1367 = &(((*({ hrv *_t1368 = &(g707); int64_t _i1368 = t_364; (S4*)_t1368->b + hr_ix(_i1368, _t1368->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:370"); }))).s_); *_t1367 = ((int32_t)(name_321)); }
return f89_pslit(t_364, st_310);
 }
int64_t id_365 = f40_mk(((int64_t)8LL), st_310); 
{ int32_t *_t1371 = &(((*({ hrv *_t1372 = &(g707); int64_t _i1372 = id_365; (S4*)_t1372->b + hr_ix(_i1372, _t1372->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:371"); }))).s_); *_t1371 = ((int32_t)(name_321)); }
return id_365;
 }
hrv m_366 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1374 = &(m_366); hr_fs(_o1374, hr_str("expression expected, found '", 28)); hr_fs(_o1374, f35_cur_text()); hr_fs(_o1374, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_366)));
return f40_mk(((int64_t)6LL), st_310);
}
static int64_t f84_parray(void) {
int64_t st_314 = g712; 
(void)(f33_nx());
int64_t a_315 = f40_mk(((int64_t)16LL), st_314); 
int64_t s_316 = f64_sub_begin(false); 
if (f41_is(((int64_t)17LL))) { { int64_t q__317 = f61_pexpr(); 
{ int32_t *_t1383 = &(((*({ hrv *_t1384 = &(g707); int64_t _i1384 = a_315; (S4*)_t1384->b + hr_ix(_i1384, _t1384->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:406"); }))).c_); *_t1383 = ((int32_t)(q__317)); }
 }
 } else { if (((f31_tk()) != (((int64_t)8LL)))) { int64_t first_318 = f61_pexpr(); 
if (f41_is(((int64_t)12LL))) { { int32_t *_t1388 = &(((*({ hrv *_t1389 = &(g707); int64_t _i1389 = a_315; (S4*)_t1389->b + hr_ix(_i1389, _t1389->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:410"); }))).a_); *_t1388 = ((int32_t)(first_318)); }
{ int64_t q__319 = f61_pexpr(); 
{ int32_t *_t1391 = &(((*({ hrv *_t1392 = &(g707); int64_t _i1392 = a_315; (S4*)_t1392->b + hr_ix(_i1392, _t1392->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:410"); }))).b_); *_t1391 = ((int32_t)(q__319)); }
 }
 } else { int64_t m_320 = f52_wbeg(); 
(void)(({ hrv *_v1394 = &(g709); int32_t _x1394 = ((int32_t)(first_318)); int32_t *_p1394 = (int32_t*)hr_grow(_v1394, 1, sizeof _x1394); *_p1394 = _x1394; _p1394; }));
while ((f41_is(((int64_t)11LL)) && ((f31_tk()) != (((int64_t)8LL))))) { (void)(({ hrv *_v1398 = &(g709); int32_t _x1398 = ((int32_t)(f61_pexpr())); int32_t *_p1398 = (int32_t*)hr_grow(_v1398, 1, sizeof _x1398); *_p1398 = _x1398; _p1398; }));
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
int64_t save_322 = g712; 
int64_t nd0_323 = (g707).n; 
int64_t ls0_324 = (g708).n; 
int64_t sp0_325 = (g721).n; 
int64_t ws0_326 = (g709).n; 
g714++;
(void)(f33_nx());
int64_t l_327 = f40_mk(((int64_t)36LL), save_322); 
int64_t m_328 = f52_wbeg(); 
bool ok_329 = false; 
for (;;) { (void)(({ hrv *_v1407 = &(g709); int32_t _x1407 = ((int32_t)(f53_ptype())); int32_t *_p1407 = (int32_t*)hr_grow(_v1407, 1, sizeof _x1407); *_p1407 = _x1407; _p1407; }));
if ((g715 || (!(f41_is(((int64_t)11LL)))))) { { goto _bk1406; }
 }
if ((((f31_tk()) == (((int64_t)40LL))) || ((f31_tk()) == (((int64_t)44LL))))) { { goto _bk1406; }
 }
 } _bk1406:; 
if ((!(g715))) { if (((f31_tk()) == (((int64_t)44LL)))) { (void)(({ hrv *_v1413 = &(g721); int64_t _x1413 = g712; int64_t *_p1413 = (int64_t*)hr_grow(_v1413, 1, sizeof _x1413); *_p1413 = _x1413; _p1413; }));
{ uint8_t *_t1414 = &(((*({ hrv *_t1415 = &(g917); int64_t _i1415 = g712; (S3*)_t1415->b + hr_ix(_i1415, _t1415->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:386"); }))).k_); *_t1414 = ((uint8_t)(((uint8_t)40LL))); }
ok_329 = true;
 } else { if (((f31_tk()) == (((int64_t)40LL)))) { (void)(f33_nx());
ok_329 = true;
 }
 }
if (ok_329) { ok_329 = false;
if ((((f31_tk()) == (((int64_t)5LL))) || (((f31_tk()) == (((int64_t)9LL))) && (!(g716))))) { ok_329 = true;
 }
if ((((((f31_tk()) == (((int64_t)16LL))) && (!(g716))) && ((f44_tkat(((int64_t)((int64_t)g712 + (int64_t)((int64_t)1LL))))) == (((int64_t)1LL)))) && ((f44_tkat(((int64_t)((int64_t)g712 + (int64_t)((int64_t)2LL))))) == (((int64_t)9LL))))) { ok_329 = true;
 }
 }
 }
g714--;
if ((ok_329 && (!(g715)))) { (void)(f59_setl(l_327, m_328));
return l_327;
 }
g715 = false;
while ((((g721).n) > (sp0_325))) { int64_t q_330 = ({ hrv *_v1425 = &(g721); if (!_v1425->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:396"); ((int64_t*)_v1425->b)[--_v1425->n]; }); 
{ uint8_t *_t1426 = &(((*({ hrv *_t1427 = &(g917); int64_t _i1427 = q_330; (S3*)_t1427->b + hr_ix(_i1427, _t1427->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:396"); }))).k_); *_t1426 = ((uint8_t)(((uint8_t)44LL))); }
 } _bk1424:; 
if ((((g709).n) > (ws0_326))) { (void)(({ hrv *_v1428 = &(g709); int64_t _k1428 = ((int64_t)((int64_t)(g709).n - (int64_t)ws0_326)); if (_k1428 < 0 || _k1428 > _v1428->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:397"); _v1428->n -= _k1428; }));
 }
(void)(({ hrv *_v1429 = &(g707); int64_t _k1429 = nd0_323; if (_k1429 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:398"); S4 _x1429 = ((S4){ 0}); int64_t _o1429 = _v1429->n; hr_resize(_v1429, _k1429, sizeof _x1429); for (int64_t _j = _o1429; _j < _k1429; _j++) ((S4*)_v1429->b)[_j] = _x1429; }));
(void)(({ hrv *_v1430 = &(g708); int64_t _k1430 = ls0_324; if (_k1430 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:398"); int32_t _x1430 = ((int32_t)0LL); int64_t _o1430 = _v1430->n; hr_resize(_v1430, _k1430, sizeof _x1430); for (int64_t _j = _o1430; _j < _k1430; _j++) ((int32_t*)_v1430->b)[_j] = _x1430; }));
g712 = save_322;
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f86_pcall(int64_t callee_333, int64_t tyargs_334, int64_t st_335) {
int64_t c_336 = f40_mk(((int64_t)11LL), st_335); 
{ int32_t *_t1432 = &(((*({ hrv *_t1433 = &(g707); int64_t _i1433 = c_336; (S4*)_t1433->b + hr_ix(_i1433, _t1433->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:317"); }))).a_); *_t1432 = ((int32_t)(callee_333)); }
{ int32_t *_t1434 = &(((*({ hrv *_t1435 = &(g707); int64_t _i1435 = c_336; (S4*)_t1435->b + hr_ix(_i1435, _t1435->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:317"); }))).c_); *_t1434 = ((int32_t)(tyargs_334)); }
int64_t s_337 = f64_sub_begin(false); 
int64_t m_338 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v1441 = &(g709); int32_t _x1441 = ((int32_t)(f61_pexpr())); int32_t *_p1441 = (int32_t*)hr_grow(_v1441, 1, sizeof _x1441); *_p1441 = _x1441; _p1441; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1438; }
 }
 } _bk1438:; 
(void)(f39_ex(((int64_t)6LL), hr_str("call arguments", 14)));
(void)(f59_setl(c_336, m_338));
(void)(f65_sub_end(s_337));
if ((((f31_tk()) == (((int64_t)9LL))) && (!(g716)))) { { int64_t q__351 = f87_pfunval(); 
{ int32_t *_t1449 = &(((*({ hrv *_t1450 = &(g707); int64_t _i1450 = c_336; (S4*)_t1450->b + hr_ix(_i1450, _t1450->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:324"); }))).b_); *_t1449 = ((int32_t)(q__351)); }
 }
if (g717) { g718 = true;
 }
 }
return c_336;
}
static int64_t f87_pfunval(void) {
int64_t st_339 = g712; 
(void)(f39_ex(((int64_t)9LL), hr_str("function value", 14)));
int64_t fv_340 = f40_mk(((int64_t)31LL), st_339); 
int64_t b_341 = f40_mk(((int64_t)23LL), st_339); 
{ int32_t *_t1454 = &(((*({ hrv *_t1455 = &(g707); int64_t _i1455 = fv_340; (S4*)_t1455->b + hr_ix(_i1455, _t1455->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:476"); }))).a_); *_t1454 = ((int32_t)(b_341)); }
if ((((f31_tk()) == (((int64_t)1LL))) || ((f31_tk()) == (((int64_t)67LL))))) { int64_t save_342 = g712; 
int64_t nd0_343 = (g707).n; 
int64_t ws0_344 = (g709).n; 
g714++;
bool ok_345 = true; 
int64_t m_346 = f52_wbeg(); 
for (;;) { bool pv_347 = f41_is(((int64_t)67LL)); 
if (((f31_tk()) != (((int64_t)1LL)))) { ok_345 = false;
{ goto _bk1459; }
 }
int64_t p_348 = f40_mk(((int64_t)32LL), g712); 
{ int32_t *_t1463 = &(((*({ hrv *_t1464 = &(g707); int64_t _i1464 = p_348; (S4*)_t1464->b + hr_ix(_i1464, _t1464->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:485"); }))).s_); *_t1463 = ((int32_t)(((*({ hrv *_t1465 = &(g917); int64_t _i1465 = g712; (S3*)_t1465->b + hr_ix(_i1465, _t1465->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:485"); }))).v_)); }
if (pv_347) { { uint16_t *_t1466 = &(((*({ hrv *_t1467 = &(g707); int64_t _i1467 = p_348; (S4*)_t1467->b + hr_ix(_i1467, _t1467->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:485"); }))).fl_); *_t1466 = ((uint16_t)1LL); }
 }
(void)(f33_nx());
if (f41_is(((int64_t)13LL))) { { int64_t q__349 = f53_ptype(); 
{ int32_t *_t1471 = &(((*({ hrv *_t1472 = &(g707); int64_t _i1472 = p_348; (S4*)_t1472->b + hr_ix(_i1472, _t1472->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:486"); }))).a_); *_t1471 = ((int32_t)(q__349)); }
 }
 }
(void)(({ hrv *_v1473 = &(g709); int32_t _x1473 = ((int32_t)(p_348)); int32_t *_p1473 = (int32_t*)hr_grow(_v1473, 1, sizeof _x1473); *_p1473 = _x1473; _p1473; }));
if ((g715 || (!(f41_is(((int64_t)11LL)))))) { { goto _bk1459; }
 }
 } _bk1459:; 
if (((g715 || (!(ok_345))) || (!(f41_is(((int64_t)55LL)))))) { ok_345 = false;
 }
g714--;
if (ok_345) { (void)(f59_setl(fv_340, m_346));
{ uint16_t *_t1477 = &(((*({ hrv *_t1478 = &(g707); int64_t _i1478 = fv_340; (S4*)_t1478->b + hr_ix(_i1478, _t1478->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:492"); }))).fl_); *_t1477 = ((uint16_t)1LL); }
 } else { g715 = false;
if ((((g709).n) > (ws0_344))) { (void)(({ hrv *_v1479 = &(g709); int64_t _k1479 = ((int64_t)((int64_t)(g709).n - (int64_t)ws0_344)); if (_k1479 < 0 || _k1479 > _v1479->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:493"); _v1479->n -= _k1479; }));
 }
(void)(({ hrv *_v1480 = &(g707); int64_t _k1480 = nd0_343; if (_k1480 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:493"); S4 _x1480 = ((S4){ 0}); int64_t _o1480 = _v1480->n; hr_resize(_v1480, _k1480, sizeof _x1480); for (int64_t _j = _o1480; _j < _k1480; _j++) ((S4*)_v1480->b)[_j] = _x1480; }));
g712 = save_342;
 }
 }
(void)(f67_pbody(b_341));
(void)(f88_set_end(fv_340));
return fv_340;
}
static void f88_set_end(int64_t n_350) {
while ((((g722).n) < ((g707).n))) { (void)(({ hrv *_v1484 = &(g722); int32_t _x1484 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1484 = (int32_t*)hr_grow(_v1484, 1, sizeof _x1484); *_p1484 = _x1484; _p1484; }));
 } _bk1483:; 
{ int32_t *_t1485 = &((*({ hrv *_t1486 = &(g722); int64_t _i1486 = n_350; (int32_t*)_t1486->b + hr_ix(_i1486, _t1486->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:28"); }))); *_t1485 = ((int32_t)((g707).n)); }
}
static int64_t f89_pslit(int64_t ty_355, int64_t st_356) {
int64_t n_357 = f40_mk(((int64_t)17LL), st_356); 
{ int32_t *_t1488 = &(((*({ hrv *_t1489 = &(g707); int64_t _i1489 = n_357; (S4*)_t1489->b + hr_ix(_i1489, _t1489->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:464"); }))).a_); *_t1488 = ((int32_t)(ty_355)); }
(void)(f70_pinits(n_357, false));
int64_t named_358 = ((int64_t)0LL); 
bool cf_359 = false; 
{ int32_t _e1492 = ((*({ hrv *_t1493 = &(g707); int64_t _i1493 = n_357; (S4*)_t1493->b + hr_ix(_i1493, _t1493->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:467"); }))).n_; for (int32_t _k1492 = 0; _k1492 < _e1492; _k1492++) { int32_t i_360 = (int32_t)_k1492; int64_t fi_363 = f90_kid(n_357, ((int64_t)(i_360))); 
if (((((*({ hrv *_t1495 = &(g707); int64_t _i1495 = fi_363; (S4*)_t1495->b + hr_ix(_i1495, _t1495->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:467"); }))).k_) == (((uint8_t)37LL)))) { cf_359 = true;
 } else { if (((((*({ hrv *_t1496 = &(g707); int64_t _i1496 = fi_363; (S4*)_t1496->b + hr_ix(_i1496, _t1496->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:467"); }))).s_) >= (((int32_t)0LL)))) { named_358++;
 }
 }
 } } _bk1491:; 
if ((((!(cf_359)) && ((named_358) > (((int64_t)0LL)))) && ((named_358) != (((int64_t)(((*({ hrv *_t1497 = &(g707); int64_t _i1497 = n_357; (S4*)_t1497->b + hr_ix(_i1497, _t1497->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:468"); }))).n_)))))) { (void)(f38_perr(hr_str("struct literal mixes named and positional initializers", 54)));
 }
return n_357;
}
static int64_t f90_kid(int64_t n_361, int64_t i_362) {
return ((int64_t)((*({ hrv *_t1499 = &(g708); int64_t _i1499 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1500 = &(g707); int64_t _i1500 = n_361; (S4*)_t1500->b + hr_ix(_i1500, _t1500->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:56"); }))).l_)) + (int64_t)i_362)); (int32_t*)_t1499->b + hr_ix(_i1499, _t1499->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:56"); }))));
}
static int64_t f91_pindex(int64_t obj_369) {
int64_t st_370 = g712; 
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
{ int32_t *_t1509 = &(((*({ hrv *_t1510 = &(g707); int64_t _i1510 = r_375; (S4*)_t1510->b + hr_ix(_i1510, _t1510->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:336"); }))).a_); *_t1509 = ((int32_t)(obj_369)); }
{ int32_t *_t1511 = &(((*({ hrv *_t1512 = &(g707); int64_t _i1512 = r_375; (S4*)_t1512->b + hr_ix(_i1512, _t1512->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:336"); }))).b_); *_t1511 = ((int32_t)(lo_372)); }
if (lfe_373) { { uint16_t *_t1513 = &(((*({ hrv *_t1514 = &(g707); int64_t _i1514 = r_375; (S4*)_t1514->b + hr_ix(_i1514, _t1514->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:337"); }))).fl_); *_t1513 = ((uint16_t)1LL); }
 }
if (((f31_tk()) != (((int64_t)8LL)))) { if (f41_is(((int64_t)51LL))) { { uint16_t *_t1517 = &(((*({ hrv *_t1518 = &(g707); int64_t _i1518 = r_375; (S4*)_t1518->b + hr_ix(_i1518, _t1518->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:338"); }))).fl_); *_t1517 = ((uint16_t)((uint64_t)(*_t1517) | (uint64_t)((uint16_t)2LL))); }
 }
{ int64_t q__376 = f61_pexpr(); 
{ int32_t *_t1520 = &(((*({ hrv *_t1521 = &(g707); int64_t _i1521 = r_375; (S4*)_t1521->b + hr_ix(_i1521, _t1521->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:338"); }))).c_); *_t1520 = ((int32_t)(q__376)); }
 }
 }
 } else { if (lfe_373) { (void)(f38_perr(hr_str("'^' bounds are only valid in slices", 35)));
 }
r_375 = f40_mk(((int64_t)12LL), st_370);
{ int32_t *_t1524 = &(((*({ hrv *_t1525 = &(g707); int64_t _i1525 = r_375; (S4*)_t1525->b + hr_ix(_i1525, _t1525->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:341"); }))).a_); *_t1524 = ((int32_t)(obj_369)); }
{ int32_t *_t1526 = &(((*({ hrv *_t1527 = &(g707); int64_t _i1527 = r_375; (S4*)_t1527->b + hr_ix(_i1527, _t1527->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:341"); }))).b_); *_t1526 = ((int32_t)(lo_372)); }
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
int64_t st_414 = g712; 
(void)(f33_nx());
int64_t n_415 = f40_mk(((int64_t)51LL), st_414); 
{ int64_t q__416 = f50_declname(hr_str("struct declaration", 18)); 
{ int32_t *_t1536 = &(((*({ hrv *_t1537 = &(g707); int64_t _i1537 = n_415; (S4*)_t1537->b + hr_ix(_i1537, _t1537->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:618"); }))).s_); *_t1536 = ((int32_t)(q__416)); }
 }
{ int32_t *_t1538 = &(((*({ hrv *_t1539 = &(g707); int64_t _i1539 = n_415; (S4*)_t1539->b + hr_ix(_i1539, _t1539->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:618"); }))).a_); *_t1538 = ((int32_t)(g719)); }
{ int64_t q__417 = f51_pgenerics(); 
{ int32_t *_t1541 = &(((*({ hrv *_t1542 = &(g707); int64_t _i1542 = n_415; (S4*)_t1542->b + hr_ix(_i1542, _t1542->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:619"); }))).d_); *_t1541 = ((int32_t)(q__417)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("struct declaration", 18)));
(void)(f95_pfields(n_415, hr_str("struct body", 11)));
(void)(f39_ex(((int64_t)10LL), hr_str("struct declaration", 18)));
return n_415;
}
static void f95_pfields(int64_t n_418, hsl ctx_419) {
int64_t m_420 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t f_421 = f40_mk(((int64_t)55LL), g712); 
if (f41_is(((int64_t)70LL))) { { uint16_t *_t1552 = &(((*({ hrv *_t1553 = &(g707); int64_t _i1553 = f_421; (S4*)_t1553->b + hr_ix(_i1553, _t1553->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:601"); }))).fl_); *_t1552 = ((uint16_t)4LL); }
if (((f31_tk()) == (((int64_t)2LL)))) { { int32_t *_t1555 = &(((*({ hrv *_t1556 = &(g707); int64_t _i1556 = f_421; (S4*)_t1556->b + hr_ix(_i1556, _t1556->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:601"); }))).c_); *_t1555 = ((int32_t)(((*({ hrv *_t1557 = &(g917); int64_t _i1557 = g712; (S3*)_t1557->b + hr_ix(_i1557, _t1557->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:601"); }))).v_)); }
(void)(f33_nx());
 }
 } else { bool cq_422 = f41_is(((int64_t)69LL)); 
if ((cq_422 || f41_is(((int64_t)66LL)))) { { uint16_t *_t1561 = &(((*({ hrv *_t1562 = &(g707); int64_t _i1562 = f_421; (S4*)_t1562->b + hr_ix(_i1562, _t1562->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:604"); }))).fl_); *_t1561 = ({ uint16_t _r1563; if (cq_422) { _r1563 = ((uint16_t)3LL);  } else { _r1563 = ((uint16_t)1LL);  } _r1563; }); }
 }
{ int64_t q__423 = f34_ident(ctx_419); 
{ int32_t *_t1565 = &(((*({ hrv *_t1566 = &(g707); int64_t _i1566 = f_421; (S4*)_t1566->b + hr_ix(_i1566, _t1566->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:605"); }))).s_); *_t1565 = ((int32_t)(q__423)); }
 }
if ((!(f75_amni_type()))) { (void)(f39_ex(((int64_t)13LL), ctx_419));
 }
{ int64_t q__424 = f53_ptype(); 
{ int32_t *_t1570 = &(((*({ hrv *_t1571 = &(g707); int64_t _i1571 = f_421; (S4*)_t1571->b + hr_ix(_i1571, _t1571->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:607"); }))).a_); *_t1570 = ((int32_t)(q__424)); }
 }
if (f41_is(((int64_t)36LL))) { { int64_t q__425 = f61_pexpr(); 
{ int32_t *_t1574 = &(((*({ hrv *_t1575 = &(g707); int64_t _i1575 = f_421; (S4*)_t1575->b + hr_ix(_i1575, _t1575->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:608"); }))).b_); *_t1574 = ((int32_t)(q__425)); }
 }
 }
 }
(void)(({ hrv *_v1576 = &(g709); int32_t _x1576 = ((int32_t)(f_421)); int32_t *_p1576 = (int32_t*)hr_grow(_v1576, 1, sizeof _x1576); *_p1576 = _x1576; _p1576; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1547; }
 }
 } _bk1547:; 
(void)(f59_setl(n_418, m_420));
}
static int64_t f96_penum(void) {
int64_t st_426 = g712; 
(void)(f33_nx());
int64_t n_427 = f40_mk(((int64_t)52LL), st_426); 
{ int64_t q__428 = f50_declname(hr_str("enum declaration", 16)); 
{ int32_t *_t1582 = &(((*({ hrv *_t1583 = &(g707); int64_t _i1583 = n_427; (S4*)_t1583->b + hr_ix(_i1583, _t1583->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:628"); }))).s_); *_t1582 = ((int32_t)(q__428)); }
 }
{ int32_t *_t1584 = &(((*({ hrv *_t1585 = &(g707); int64_t _i1585 = n_427; (S4*)_t1585->b + hr_ix(_i1585, _t1585->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:628"); }))).a_); *_t1584 = ((int32_t)(g719)); }
{ int64_t q__429 = f51_pgenerics(); 
{ int32_t *_t1587 = &(((*({ hrv *_t1588 = &(g707); int64_t _i1588 = n_427; (S4*)_t1588->b + hr_ix(_i1588, _t1588->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:629"); }))).d_); *_t1587 = ((int32_t)(q__429)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("enum declaration", 16)));
int64_t m_430 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t v_431 = f40_mk(((int64_t)56LL), g712); 
{ int64_t q__432 = f34_ident(hr_str("enum variant", 12)); 
{ int32_t *_t1596 = &(((*({ hrv *_t1597 = &(g707); int64_t _i1597 = v_431; (S4*)_t1597->b + hr_ix(_i1597, _t1597->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:633"); }))).s_); *_t1596 = ((int32_t)(q__432)); }
 }
if (f41_is(((int64_t)9LL))) { { uint16_t *_t1599 = &(((*({ hrv *_t1600 = &(g707); int64_t _i1600 = v_431; (S4*)_t1600->b + hr_ix(_i1600, _t1600->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:634"); }))).fl_); *_t1599 = ((uint16_t)1LL); }
(void)(f95_pfields(v_431, hr_str("variant body", 12)));
(void)(f39_ex(((int64_t)10LL), hr_str("enum variant", 12)));
 }
(void)(({ hrv *_v1603 = &(g709); int32_t _x1603 = ((int32_t)(v_431)); int32_t *_p1603 = (int32_t*)hr_grow(_v1603, 1, sizeof _x1603); *_p1603 = _x1603; _p1603; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1591; }
 }
 } _bk1591:; 
(void)(f59_setl(n_427, m_430));
(void)(f39_ex(((int64_t)10LL), hr_str("enum declaration", 16)));
return n_427;
}
static void f97_collect(int64_t file_440, int64_t t0_441, int64_t t1_442) {
{ int64_t _e1608 = t1_442; for (int64_t _k1608 = t0_441; _k1608 < _e1608; _k1608++) { int64_t i_443 = (int64_t)_k1608; int64_t n_444 = ((int64_t)((*({ hrv *_t1609 = &(g710); int64_t _i1609 = i_443; (int32_t*)_t1609->b + hr_ix(_i1609, _t1609->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:27"); })))); 
S4 x_445 = (*({ hrv *_t1610 = &(g707); int64_t _i1610 = n_444; (S4*)_t1610->b + hr_ix(_i1610, _t1610->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:28"); })); 
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
if (((k_446) == (((int64_t)33LL)))) { (void)(f99_dadd(((int64_t)5LL), n_444, file_440, f98_qual(((int64_t)((x_445).c_)), ((int64_t)((*({ hrv *_t1622 = &(g708); int64_t _i1622 = (x_445).l_; (int32_t*)_t1622->b + hr_ix(_i1622, _t1622->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:34"); })))))));
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
while ((((g493).n) <= (name_453))) { (void)(({ hrv *_v1632 = &(g493); int32_t _x1632 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1632 = (int32_t*)hr_grow(_v1632, 1, sizeof _x1632); *_p1632 = _x1632; _p1632; }));
 } _bk1631:; 
int64_t i_454 = (g492).n; 
(void)(({ hrv *_v1633 = &(g492); S5 _x1633 = ((S5){ .k_ = ((uint8_t)(k_450)), .node_ = ((int32_t)(node_451)), .file_ = ((int32_t)(file_452)), .next_ = (*({ hrv *_t1634 = &(g493); int64_t _i1634 = name_453; (int32_t*)_t1634->b + hr_ix(_i1634, _t1634->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:19"); })), .name_ = ((int32_t)(name_453)), }); S5 *_p1633 = (S5*)hr_grow(_v1633, 1, sizeof _x1633); *_p1633 = _x1633; _p1633; }));
{ int32_t *_t1635 = &((*({ hrv *_t1636 = &(g493); int64_t _i1636 = name_453; (int32_t*)_t1636->b + hr_ix(_i1636, _t1636->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:20"); }))); *_t1635 = ((int32_t)(i_454)); }
}
static L49 f100_lib_path(hsl name_459) {
L49 p_460 = ({ L49 _t1637; memset(&_t1637, 0, sizeof _t1637); _t1637.n = 0; _t1637; }); 
(void)(({ L49 *_v1638 = &(p_460); hsl _s1638 = hr_sl(g496); if (_v1638->n + _s1638.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); memmove(_v1638->e + _v1638->n, _s1638.p, (size_t)_s1638.n * sizeof _v1638->e[0]); _v1638->n += _s1638.n; }));
(void)(({ L49 *_v1639 = &(p_460); uint8_t _x1639 = ((uint8_t)47LL); if (_v1639->n >= 1024) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); _v1639->e[_v1639->n] = _x1639; &_v1639->e[_v1639->n++]; }));
(void)(({ L49 *_v1640 = &(p_460); hsl _s1640 = name_459; if (_v1640->n + _s1640.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); memmove(_v1640->e + _v1640->n, _s1640.p, (size_t)_s1640.n * sizeof _v1640->e[0]); _v1640->n += _s1640.n; }));
(void)(({ L49 *_v1641 = &(p_460); hsl _s1641 = hr_str(".amni", 5); if (_v1641->n + _s1641.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); memmove(_v1641->e + _v1641->n, _s1641.p, (size_t)_s1641.n * sizeof _v1641->e[0]); _v1641->n += _s1641.n; }));
return p_460;
}
static int64_t f101_load_import(int64_t name_463, int64_t from_464, int64_t t_465) {
L49 p_466 = ({ L49 _t1642; memset(&_t1642, 0, sizeof _t1642); _t1642.n = 0; _t1642; }); 
(void)(({ L49 *_v1643 = &(p_466); hsl _s1643 = hr_sl(g495); if (_v1643->n + _s1643.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:59"); memmove(_v1643->e + _v1643->n, _s1643.p, (size_t)_s1643.n * sizeof _v1643->e[0]); _v1643->n += _s1643.n; }));
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
if ((((g498).n) > (((int64_t)0LL)))) { return;
 }
S3 x_474 = (*({ hrv *_t1660 = &(g917); int64_t _i1660 = f103_max(t_470, ((int64_t)0LL)); (S3*)_t1660->b + hr_ix(_i1660, _t1660->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:14"); })); 
(void)(({ hrv *_v1662 = &(g498); hsl _s1662 = f10_nm(((int64_t)(((*({ hrv *_t1664 = &(g916); int64_t _i1664 = (x_474).f_; (S2*)_t1664->b + hr_ix(_i1664, _t1664->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:14"); }))).name_))); hr_append(_v1662, _s1662.p, _s1662.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o1665 = &(g498); hr_fs(_o1665, hr_str(":", 1)); hr_fi(_o1665, (x_474).line_); hr_fs(_o1665, hr_str(": error: ", 9)); hr_fs(_o1665, m_471); }));
}
static int64_t f103_max(int64_t a_472, int64_t b_473) {
if (((a_472) < (b_473))) { return b_473;
 }
return a_472;
}
static bool f104_check_program(void) {
g405 = f105_new_inst(((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)0LL), (g707).n, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
{ uint8_t *_t1667 = &(((*({ hrv *_t1668 = &(g390); int64_t _i1668 = g405; (S6*)_t1668->b + hr_ix(_i1668, _t1668->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:505"); }))).st_); *_t1667 = ((uint8_t)2LL); }
g403 = g405;
g404 = g405;
int64_t md_489 = f106_lookup(f8_intern(hr_str("main", 4)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)4LL)); 
if (((md_489) < (((int64_t)0LL)))) { (void)(f108_cerr(((int64_t)0LL), hr_str("no main function", 16)));
return false;
 }
{ hrv *_v1673 = &(g492); for (int64_t _k1673 = 0; _k1673 < _v1673->n; _k1673++) { S5 d_493 = ((S5*)_v1673->b)[_k1673]; int64_t i_494 = (int64_t)_k1673; if ((((((int64_t)((d_493).k_))) == (((int64_t)5LL))) && (((d_493).file_) == (((int32_t)0LL))))) { (void)(f109_global_type(i_494));
 }
 } } _bk1672:; 
int64_t mi_1494 = f254_get_inst(((int64_t)(((*({ hrv *_t1676 = &(g492); int64_t _i1676 = md_489; (S5*)_t1676->b + hr_ix(_i1676, _t1676->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:510"); }))).node_)), (g314).n, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
{ hrv *_v1678 = &(g492); for (int64_t _k1678 = 0; _k1678 < _v1678->n; _k1678++) { S5 d_1495 = ((S5*)_v1678->b)[_k1678]; int64_t i_1496 = (int64_t)_k1678; if (((((int64_t)((d_1495).k_))) == (((int64_t)5LL)))) { (void)(f109_global_type(i_1496));
 }
 } } _bk1677:; 
(void)(f260_propagate_calls());
return ((g407) == (((int64_t)0LL)));
}
static int64_t f105_new_inst(int64_t node_477, int64_t lo_478, int64_t hi_479, int64_t par_480) {
int64_t i_481 = (g390).n; 
(void)(({ hrv *_v1681 = &(g390); S6 _x1681 = ((S6){ .node_ = ((int32_t)(node_477)), .lo_ = ((int32_t)(lo_478)), .hi_ = ((int32_t)(hi_479)), .ab_ = ((int32_t)((g397).n)), .par_ = ((int32_t)(par_480)), .cfn_ = ((int32_t)(i_481)), .g0_ = ((int32_t)((g396).n)), .gn_ = ((int32_t)0LL), .ret_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .p0_ = ((int32_t)0LL), .pn_ = ((int32_t)0LL), .st_ = ((uint8_t)0LL), .blk_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .bown_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .name_ = ({ int32_t _r1682; if (((node_477) >= (((int64_t)0LL)))) { _r1682 = ((*({ hrv *_t1683 = &(g707); int64_t _i1683 = node_477; (S4*)_t1683->b + hr_ix(_i1683, _t1683->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:30"); }))).s_;  } else { _r1682 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));  } _r1682; }), }); S6 *_p1681 = (S6*)hr_grow(_v1681, 1, sizeof _x1681); *_p1681 = _x1681; _p1681; }));
int64_t n_482 = ((int64_t)((int64_t)hi_479 - (int64_t)lo_478)); 
(void)(({ hrv *_v1684 = &(g397); int64_t _k1684 = ((int64_t)((int64_t)(g397).n + (int64_t)n_482)); if (_k1684 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1684 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1684 = _v1684->n; hr_resize(_v1684, _k1684, sizeof _x1684); for (int64_t _j = _o1684; _j < _k1684; _j++) ((int32_t*)_v1684->b)[_j] = _x1684; }));
(void)(({ hrv *_v1685 = &(g398); int64_t _k1685 = ((int64_t)((int64_t)(g398).n + (int64_t)n_482)); if (_k1685 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1685 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1685 = _v1685->n; hr_resize(_v1685, _k1685, sizeof _x1685); for (int64_t _j = _o1685; _j < _k1685; _j++) ((int32_t*)_v1685->b)[_j] = _x1685; }));
(void)(({ hrv *_v1686 = &(g399); int64_t _k1686 = ((int64_t)((int64_t)(g399).n + (int64_t)n_482)); if (_k1686 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); uint8_t _x1686 = ((uint8_t)0LL); int64_t _o1686 = _v1686->n; hr_resize(_v1686, _k1686, sizeof _x1686); for (int64_t _j = _o1686; _j < _k1686; _j++) ((uint8_t*)_v1686->b)[_j] = _x1686; }));
(void)(({ hrv *_v1687 = &(g400); int64_t _k1687 = ((int64_t)((int64_t)(g400).n + (int64_t)n_482)); if (_k1687 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1687 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1687 = _v1687->n; hr_resize(_v1687, _k1687, sizeof _x1687); for (int64_t _j = _o1687; _j < _k1687; _j++) ((int32_t*)_v1687->b)[_j] = _x1687; }));
(void)(({ hrv *_v1688 = &(g401); int64_t _k1688 = ((int64_t)((int64_t)(g401).n + (int64_t)n_482)); if (_k1688 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1688 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1688 = _v1688->n; hr_resize(_v1688, _k1688, sizeof _x1688); for (int64_t _j = _o1688; _j < _k1688; _j++) ((int32_t*)_v1688->b)[_j] = _x1688; }));
return i_481;
}
static int64_t f106_lookup(int64_t name_483, int64_t ns_484, int64_t k_485) {
if (((ns_484) >= (((int64_t)0LL)))) { int64_t d_487 = f107_dmap(f98_qual(ns_484, name_483)); 
while (((d_487) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1692 = &(g492); int64_t _i1692 = d_487; (S5*)_t1692->b + hr_ix(_i1692, _t1692->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:74"); }))).k_))) == (k_485))) { return d_487;
 }
d_487 = ((int64_t)(((*({ hrv *_t1693 = &(g492); int64_t _i1693 = d_487; (S5*)_t1693->b + hr_ix(_i1693, _t1693->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:74"); }))).next_));
 } _bk1691:; 
 }
int64_t d_488 = f107_dmap(name_483); 
while (((d_488) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1696 = &(g492); int64_t _i1696 = d_488; (S5*)_t1696->b + hr_ix(_i1696, _t1696->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:76"); }))).k_))) == (k_485))) { return d_488;
 }
d_488 = ((int64_t)(((*({ hrv *_t1697 = &(g492); int64_t _i1697 = d_488; (S5*)_t1697->b + hr_ix(_i1697, _t1697->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:76"); }))).next_));
 } _bk1695:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f107_dmap(int64_t name_486) {
return ({ int64_t _r1698; if ((((name_486) < (((int64_t)0LL))) || ((name_486) >= ((g493).n)))) { _r1698 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1698 = ((int64_t)((*({ hrv *_t1699 = &(g493); int64_t _i1699 = name_486; (int32_t*)_t1699->b + hr_ix(_i1699, _t1699->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:15"); }))));  } _r1698; });
}
static void f108_cerr(int64_t n_490, hsl m_491) {
g407++;
if ((((g406).n) > (((int64_t)0LL)))) { return;
 }
S3 x_492 = (*({ hrv *_t1700 = &(g917); int64_t _i1700 = ((*({ hrv *_t1701 = &(g707); int64_t _i1701 = f103_max(n_490, ((int64_t)0LL)); (S4*)_t1701->b + hr_ix(_i1701, _t1701->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:27"); }))).t_; (S3*)_t1700->b + hr_ix(_i1700, _t1700->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:27"); })); 
(void)(({ hrv *_v1703 = &(g406); hsl _s1703 = f10_nm(((int64_t)(((*({ hrv *_t1705 = &(g916); int64_t _i1705 = (x_492).f_; (S2*)_t1705->b + hr_ix(_i1705, _t1705->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:27"); }))).name_))); hr_append(_v1703, _s1703.p, _s1703.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o1706 = &(g406); hr_fs(_o1706, hr_str(":", 1)); hr_fi(_o1706, (x_492).line_); hr_fs(_o1706, hr_str(": error: ", 9)); hr_fs(_o1706, m_491); }));
}
static int64_t f109_global_type(int64_t d_495) {
while ((((g453).n) < ((g492).n))) { (void)(({ hrv *_v1708 = &(g453); int32_t _x1708 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1708 = (int32_t*)hr_grow(_v1708, 1, sizeof _x1708); *_p1708 = _x1708; _p1708; }));
(void)(({ hrv *_v1709 = &(g454); uint8_t _x1709 = ((uint8_t)0LL); uint8_t *_p1709 = (uint8_t*)hr_grow(_v1709, 1, sizeof _x1709); *_p1709 = _x1709; _p1709; }));
 } _bk1707:; 
if ((((*({ hrv *_t1710 = &(g453); int64_t _i1710 = d_495; (int32_t*)_t1710->b + hr_ix(_i1710, _t1710->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:390"); }))) >= (((int32_t)0LL)))) { return ((int64_t)((*({ hrv *_t1711 = &(g453); int64_t _i1711 = d_495; (int32_t*)_t1711->b + hr_ix(_i1711, _t1711->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:390"); }))));
 }
int64_t g_496 = ((int64_t)(((*({ hrv *_t1712 = &(g492); int64_t _i1712 = d_495; (S5*)_t1712->b + hr_ix(_i1712, _t1712->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:391"); }))).node_)); 
S4 x_497 = (*({ hrv *_t1713 = &(g707); int64_t _i1713 = g_496; (S4*)_t1713->b + hr_ix(_i1713, _t1713->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:392"); })); 
int64_t saved_498 = g403; 
int64_t sc_499 = g404; 
g403 = g405;
g404 = g405;
int64_t t_500 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((x_497).a_) >= (((int32_t)0LL)))) { t_500 = f113_rtype(((int64_t)((x_497).a_)), f110_ns_of(g_496));
{ int32_t *_t1716 = &((*({ hrv *_t1717 = &(g453); int64_t _i1717 = d_495; (int32_t*)_t1717->b + hr_ix(_i1717, _t1717->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:396"); }))); *_t1716 = ((int32_t)(t_500)); }
if ((((x_497).b_) >= (((int32_t)0LL)))) { int64_t iv_670 = f90_kid(((int64_t)((x_497).b_)), ((int64_t)0LL)); 
(void)(f137_ck(iv_670, t_500));
(void)(f140_conv(iv_670, t_500));
 }
 } else { if ((((*({ hrv *_t1721 = &(g454); int64_t _i1721 = d_495; (uint8_t*)_t1721->b + hr_ix(_i1721, _t1721->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:398"); }))) == (((uint8_t)1LL)))) { (void)(f108_cerr(g_496, hr_str("global initializer depends on itself", 36)));
g403 = saved_498;
g404 = sc_499;
return g578;
 }
{ uint8_t *_t1723 = &((*({ hrv *_t1724 = &(g454); int64_t _i1724 = d_495; (uint8_t*)_t1724->b + hr_ix(_i1724, _t1724->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:399"); }))); *_t1723 = ((uint8_t)1LL); }
int64_t iv_1491 = f90_kid(((int64_t)((x_497).b_)), ((int64_t)0LL)); 
(void)(f137_ck(iv_1491, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
t_500 = f187_default_t(iv_1491);
if (((((*({ hrv *_t1728 = &(g554); int64_t _i1728 = t_500; (S1*)_t1728->b + hr_ix(_i1728, _t1728->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:403"); }))).k_) == (((uint8_t)18LL)))) { t_500 = g579;
 }
if (((((((*({ hrv *_t1729 = &(g554); int64_t _i1729 = t_500; (S1*)_t1729->b + hr_ix(_i1729, _t1729->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:404"); }))).k_) == (((uint8_t)7LL))) && (((((*({ hrv *_t1730 = &(g707); int64_t _i1730 = iv_1491; (S4*)_t1730->b + hr_ix(_i1730, _t1730->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:404"); }))).k_) == (((uint8_t)14LL))) || ((((*({ hrv *_t1731 = &(g707); int64_t _i1731 = iv_1491; (S4*)_t1731->b + hr_ix(_i1731, _t1731->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:404"); }))).k_) == (((uint8_t)17LL))))) && ((((uint16_t)((uint64_t)(x_497).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))))) { t_500 = f136_t_enum(((int64_t)(((*({ hrv *_t1733 = &(g554); int64_t _i1733 = t_500; (S1*)_t1733->b + hr_ix(_i1733, _t1733->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:404"); }))).a_)), false);
(void)(f145_set_cv(iv_1491, t_500));
 }
{ int32_t *_t1735 = &((*({ hrv *_t1736 = &(g453); int64_t _i1736 = d_495; (int32_t*)_t1736->b + hr_ix(_i1736, _t1736->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:405"); }))); *_t1735 = ((int32_t)(t_500)); }
 }
if ((!(f259_ORD_HAS(d_495)))) { (void)(({ hrv *_v1738 = &(g411); int32_t _x1738 = ((int32_t)(d_495)); int32_t *_p1738 = (int32_t*)hr_grow(_v1738, 1, sizeof _x1738); *_p1738 = _x1738; _p1738; }));
 }
g403 = saved_498;
g404 = sc_499;
return t_500;
}
static int64_t f110_ns_of(int64_t n_501) {
return f112_file_ns(f111_node_file(n_501));
}
static int64_t f111_node_file(int64_t n_502) {
return ((int64_t)(((*({ hrv *_t1741 = &(g917); int64_t _i1741 = ((*({ hrv *_t1742 = &(g707); int64_t _i1742 = n_502; (S4*)_t1742->b + hr_ix(_i1742, _t1742->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:23"); }))).t_; (S3*)_t1741->b + hr_ix(_i1741, _t1741->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:23"); }))).f_));
}
static int64_t f112_file_ns(int64_t f_503) {
return ({ int64_t _r1743; if (((f_503) < ((g499).n))) { _r1743 = ((int64_t)((*({ hrv *_t1744 = &(g499); int64_t _i1744 = f_503; (int32_t*)_t1744->b + hr_ix(_i1744, _t1744->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:24"); }))));  } else { _r1743 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1743; });
}
static int64_t f113_rtype(int64_t n_504, int64_t ns_505) {
if (((n_504) < (((int64_t)0LL)))) { return g561;
 }
S4 x_506 = (*({ hrv *_t1745 = &(g707); int64_t _i1745 = n_504; (S4*)_t1745->b + hr_ix(_i1745, _t1745->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:93"); })); 
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
if ((((((*({ hrv *_t1757 = &(g554); int64_t _i1757 = e_512; (S1*)_t1757->b + hr_ix(_i1757, _t1757->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t1758 = &(g554); int64_t _i1758 = e_512; (S1*)_t1758->b + hr_ix(_i1758, _t1758->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).c_) < (((int32_t)0LL))))) { if (((((int64_t)((int64_t)fl_513 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { return f119_t_ref(((int64_t)(((*({ hrv *_t1760 = &(g554); int64_t _i1760 = e_512; (S1*)_t1760->b + hr_ix(_i1760, _t1760->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).a_)), ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1761 = &(g554); int64_t _i1761 = e_512; (S1*)_t1761->b + hr_ix(_i1761, _t1761->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).fl_)) | (int64_t)((int64_t)2LL))));
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
if (((((*({ hrv *_t1780 = &(g554); int64_t _i1780 = b_593; (S1*)_t1780->b + hr_ix(_i1780, _t1780->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:120"); }))).k_) != (((uint8_t)6LL)))) { (void)(f102_derr(((int64_t)((x_506).t_)), hr_str("variant type of a non-enum", 26)));
return g578;
 }
int64_t ei_594 = ((int64_t)(((*({ hrv *_t1782 = &(g554); int64_t _i1782 = b_593; (S1*)_t1782->b + hr_ix(_i1782, _t1782->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:121"); }))).a_)); 
{ int32_t _e1784 = ((*({ hrv *_t1785 = &(g559); int64_t _i1785 = ei_594; (S8*)_t1785->b + hr_ix(_i1785, _t1785->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:122"); }))).vnum_; for (int32_t _k1784 = 0; _k1784 < _e1784; _k1784++) { int32_t i_595 = (int32_t)_k1784; if (((((*({ hrv *_t1786 = &(g560); int64_t _i1786 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1787 = &(g559); int64_t _i1787 = ei_594; (S8*)_t1787->b + hr_ix(_i1787, _t1787->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:122"); }))).v0_)) + (int64_t)((int64_t)(i_595)))); (S9*)_t1786->b + hr_ix(_i1786, _t1786->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:122"); }))).name_) == ((x_506).s_))) { return f125_t_variant(ei_594, ((int64_t)(i_595)));
 }
 } } _bk1783:; 
hrv m_598 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1792 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1790 = &(m_598); hr_fs(_o1790, hr_str("no variant ", 11)); hr_fs(_o1790, f10_nm(((int64_t)((x_506).s_)))); hr_fs(_o1790, hr_str(" in ", 4)); hr_fs(_o1790, hr_sl(*hr_tmp(&_t1792, f126_ty_name(b_593)))); }));
}
(void)(f102_derr(((int64_t)((x_506).t_)), hr_sl(m_598)));
return g578;
 }
if (((k_507) == (((int64_t)45LL)))) { return g581;
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
if (((d_621) >= (((int64_t)0LL)))) { return f134_t_struct(f131_inst_struct(((int64_t)(((*({ hrv *_t1805 = &(g492); int64_t _i1805 = d_621; (S5*)_t1805->b + hr_ix(_i1805, _t1805->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:133"); }))).node_)), ({ hsl _t1806 = ({ L66 *_t1807 = &(args_618); (hsl){ (uint8_t*)_t1807->e, _t1807->n }; }); int64_t _l1806 = 0, _h1806 = _t1806.n; if (_l1806 < 0 || _h1806 < _l1806 || _h1806 > _t1806.n) hr_slerr(_l1806, _h1806, _t1806.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:133"); (hsl){ _t1806.p + _l1806 * (int64_t)sizeof(int32_t), _h1806 - _l1806 }; })));
 }
d_621 = f116_lookup_q(name_614, ns_505, ((int64_t)2LL));
if (((d_621) >= (((int64_t)0LL)))) { return f136_t_enum(f135_inst_enum(((int64_t)(((*({ hrv *_t1811 = &(g492); int64_t _i1811 = d_621; (S5*)_t1811->b + hr_ix(_i1811, _t1811->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:135"); }))).node_)), ({ hsl _t1812 = ({ L66 *_t1813 = &(args_618); (hsl){ (uint8_t*)_t1813->e, _t1813->n }; }); int64_t _l1812 = 0, _h1812 = _t1812.n; if (_l1812 < 0 || _h1812 < _l1812 || _h1812 > _t1812.n) hr_slerr(_l1812, _h1812, _t1812.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:135"); (hsl){ _t1812.p + _l1812 * (int64_t)sizeof(int32_t), _h1812 - _l1812 }; })), ((((uint16_t)((uint64_t)(x_506).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))));
 }
d_621 = f116_lookup_q(name_614, ns_505, ((int64_t)3LL));
if (((d_621) >= (((int64_t)0LL)))) { int64_t an_668 = ((int64_t)(((*({ hrv *_t1815 = &(g492); int64_t _i1815 = d_621; (S5*)_t1815->b + hr_ix(_i1815, _t1815->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:137"); }))).node_)); 
return f113_rtype(((int64_t)(((*({ hrv *_t1817 = &(g707); int64_t _i1817 = an_668; (S4*)_t1817->b + hr_ix(_i1817, _t1817->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:137"); }))).b_)), f110_ns_of(an_668));
 }
hrv m_669 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1820 = &(m_669); hr_fs(_o1820, hr_str("unknown type ", 13)); hr_fs(_o1820, f10_nm(name_614)); }));
(void)(f102_derr(((int64_t)((x_506).t_)), hr_sl(m_669)));
return g578;
 }
(void)(f102_derr(((int64_t)((x_506).t_)), hr_str("bad type", 8)));
return g578;
}
static int64_t f114_prim_type(int64_t k_508) {
if (((k_508) == (((int64_t)89LL)))) { return g562;
 }
if (((k_508) == (((int64_t)90LL)))) { return g577;
 }
if (((k_508) == (((int64_t)99LL)))) { return g571;
 }
if ((((k_508) == (((int64_t)100LL))) || ((k_508) == (((int64_t)104LL))))) { return g572;
 }
int64_t s_510 = f115_int_storage_of_tok(k_508); 
return ({ int64_t _r1825; if (((s_510) >= (((int64_t)0LL)))) { _r1825 = f17_t_int(s_510);  } else { _r1825 = g578;  } _r1825; });
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
while (((d_523) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1832 = &(g492); int64_t _i1832 = d_523; (S5*)_t1832->b + hr_ix(_i1832, _t1832->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:87"); }))).k_))) == (k_517))) { return d_523;
 }
d_523 = ((int64_t)(((*({ hrv *_t1833 = &(g492); int64_t _i1833 = d_523; (S5*)_t1833->b + hr_ix(_i1833, _t1833->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:87"); }))).next_));
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
S4 x_537 = (*({ hrv *_t1850 = &(g707); int64_t _i1850 = n_535; (S4*)_t1850->b + hr_ix(_i1850, _t1850->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:205"); })); 
int64_t k_538 = ((int64_t)((x_537).k_)); 
if (((k_538) == (((int64_t)1LL)))) { return (M57){ ((*({ hrv *_t1851 = &(g917); int64_t _i1851 = (x_537).t_; (S3*)_t1851->b + hr_ix(_i1851, _t1851->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:207"); }))).v_, ({ int64_t _r1852; if (((*({ hrv *_t1853 = &(g917); int64_t _i1853 = (x_537).t_; (S3*)_t1853->b + hr_ix(_i1853, _t1853->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:207"); }))).uns_) { _r1852 = ((int64_t)7LL);  } else { _r1852 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1852; }), true };
 }
if (((k_538) == (((int64_t)10LL)))) { M57 _t1854 = f121_ceval3(((int64_t)((x_537).a_)), ns_536); int64_t v_539 = _t1854.r0; int64_t c_540 = _t1854.r1; bool ok_541 = _t1854.r2; 
if (((((int64_t)((x_537).op_))) == (((int64_t)22LL)))) { int64_t c2_542 = ({ int64_t _r1856; if ((((c_540) == (((int64_t)7LL))) && ((((*({ hrv *_t1857 = &(g707); int64_t _i1857 = (x_537).a_; (S4*)_t1857->b + hr_ix(_i1857, _t1857->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:210"); }))).k_) == (((uint8_t)1LL))))) { _r1856 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1856 = c_540;  } _r1856; }); 
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
if (((((*({ hrv *_t1886 = &(g707); int64_t _i1886 = tn0_564; (S4*)_t1886->b + hr_ix(_i1886, _t1886->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:231"); }))).k_) == (((uint8_t)40LL)))) { int64_t tc_565 = f115_int_storage_of_tok(((int64_t)(((*({ hrv *_t1888 = &(g707); int64_t _i1888 = tn0_564; (S4*)_t1888->b + hr_ix(_i1888, _t1888->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:231"); }))).op_))); 
if (((tc_565) >= (((int64_t)0LL)))) { return (M57){ f122_cwrap(v_561, tc_565), tc_565, ok_563 };
 }
 }
return (M57){ v_561, c_562, ok_563 };
 }
if (((k_538) == (((int64_t)8LL)))) { int64_t d_566 = f116_lookup_q(((int64_t)((x_537).s_)), ns_536, ((int64_t)5LL)); 
if (((d_566) < (((int64_t)0LL)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
int64_t g_567 = ((int64_t)(((*({ hrv *_t1891 = &(g492); int64_t _i1891 = d_566; (S5*)_t1891->b + hr_ix(_i1891, _t1891->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:235"); }))).node_)); 
if ((((((uint16_t)((uint64_t)((*({ hrv *_t1892 = &(g707); int64_t _i1892 = g_567; (S4*)_t1892->b + hr_ix(_i1892, _t1892->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:236"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || ((((*({ hrv *_t1893 = &(g707); int64_t _i1893 = g_567; (S4*)_t1893->b + hr_ix(_i1893, _t1893->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:236"); }))).b_) < (((int32_t)0LL))))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
M57 _t1894 = f121_ceval3(f90_kid(((int64_t)(((*({ hrv *_t1897 = &(g707); int64_t _i1897 = g_567; (S4*)_t1897->b + hr_ix(_i1897, _t1897->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:237"); }))).b_)), ((int64_t)0LL)), f110_ns_of(g_567)); int64_t v_568 = _t1894.r0; int64_t c_569 = _t1894.r1; bool ok_570 = _t1894.r2; 
int64_t tn0_571 = ((int64_t)(((*({ hrv *_t1899 = &(g707); int64_t _i1899 = g_567; (S4*)_t1899->b + hr_ix(_i1899, _t1899->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:238"); }))).a_)); 
if ((((tn0_571) >= (((int64_t)0LL))) && ((((*({ hrv *_t1900 = &(g707); int64_t _i1900 = tn0_571; (S4*)_t1900->b + hr_ix(_i1900, _t1900->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:239"); }))).k_) == (((uint8_t)40LL))))) { int64_t tc_572 = f115_int_storage_of_tok(((int64_t)(((*({ hrv *_t1902 = &(g707); int64_t _i1902 = tn0_571; (S4*)_t1902->b + hr_ix(_i1902, _t1902->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:239"); }))).op_))); 
if (((tc_572) >= (((int64_t)0LL)))) { return (M57){ f122_cwrap(v_568, tc_572), tc_572, ok_570 };
 }
 }
return (M57){ v_568, c_569, ok_570 };
 }
if (((((k_538) == (((int64_t)14LL))) && hr_streq(f10_nm(((int64_t)((x_537).s_))), hr_str("len", 3))) && ((((*({ hrv *_t1905 = &(g707); int64_t _i1905 = (x_537).a_; (S4*)_t1905->b + hr_ix(_i1905, _t1905->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:242"); }))).k_) == (((uint8_t)8LL))))) { int64_t d_573 = f116_lookup_q(((int64_t)(((*({ hrv *_t1907 = &(g707); int64_t _i1907 = (x_537).a_; (S4*)_t1907->b + hr_ix(_i1907, _t1907->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:243"); }))).s_)), ns_536, ((int64_t)5LL)); 
if (((d_573) < (((int64_t)0LL)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
int64_t g_574 = ((int64_t)(((*({ hrv *_t1908 = &(g492); int64_t _i1908 = d_573; (S5*)_t1908->b + hr_ix(_i1908, _t1908->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:245"); }))).node_)); 
if (((((*({ hrv *_t1909 = &(g707); int64_t _i1909 = g_574; (S4*)_t1909->b + hr_ix(_i1909, _t1909->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).a_) >= (((int32_t)0LL)))) { int64_t t_575 = f113_rtype(((int64_t)(((*({ hrv *_t1911 = &(g707); int64_t _i1911 = g_574; (S4*)_t1911->b + hr_ix(_i1911, _t1911->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).a_)), f110_ns_of(g_574)); 
if ((((((*({ hrv *_t1913 = &(g554); int64_t _i1913 = t_575; (S1*)_t1913->b + hr_ix(_i1913, _t1913->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).k_) == (((uint8_t)8LL))) && ((((*({ hrv *_t1914 = &(g554); int64_t _i1914 = t_575; (S1*)_t1914->b + hr_ix(_i1914, _t1914->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).s_) == (((uint8_t)(((uint8_t)1LL))))))) { return (M57){ ((*({ hrv *_t1915 = &(g554); int64_t _i1915 = t_575; (S1*)_t1915->b + hr_ix(_i1915, _t1915->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).b_, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
 }
 }
if (((((*({ hrv *_t1916 = &(g707); int64_t _i1916 = g_574; (S4*)_t1916->b + hr_ix(_i1916, _t1916->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_) >= (((int32_t)0LL)))) { int64_t iv_576 = f90_kid(((int64_t)(((*({ hrv *_t1918 = &(g707); int64_t _i1918 = g_574; (S4*)_t1918->b + hr_ix(_i1918, _t1918->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_)), ((int64_t)0LL)); 
if (((((*({ hrv *_t1919 = &(g707); int64_t _i1919 = iv_576; (S4*)_t1919->b + hr_ix(_i1919, _t1919->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).k_) == (((uint8_t)16LL)))) { if (((((*({ hrv *_t1920 = &(g707); int64_t _i1920 = iv_576; (S4*)_t1920->b + hr_ix(_i1920, _t1920->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_) >= (((int32_t)0LL)))) { M57 _t1921 = f121_ceval3(((int64_t)(((*({ hrv *_t1923 = &(g707); int64_t _i1923 = iv_576; (S4*)_t1923->b + hr_ix(_i1923, _t1923->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_)), f110_ns_of(g_574)); int64_t v_577 = _t1921.r0; int64_t c_578 = _t1921.r1; bool ok_579 = _t1921.r2; 
return (M57){ v_577, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ok_579 };
 }
return (M57){ ((int64_t)(((*({ hrv *_t1925 = &(g707); int64_t _i1925 = iv_576; (S4*)_t1925->b + hr_ix(_i1925, _t1925->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).n_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
 }
if (((((*({ hrv *_t1926 = &(g707); int64_t _i1926 = iv_576; (S4*)_t1926->b + hr_ix(_i1926, _t1926->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).k_) == (((uint8_t)3LL)))) { return (M57){ ((int64_t)(((*({ hrv *_t1927 = &(g917); int64_t _i1927 = ((*({ hrv *_t1928 = &(g707); int64_t _i1928 = iv_576; (S4*)_t1928->b + hr_ix(_i1928, _t1928->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).t_; (S3*)_t1927->b + hr_ix(_i1927, _t1927->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).w_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
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
S1 x_603 = (*({ hrv *_t1937 = &(g554); int64_t _i1937 = t_601; (S1*)_t1937->b + hr_ix(_i1937, _t1937->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:199"); })); 
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
if (((k_604) == (((int64_t)5LL)))) { (void)(({ hrv *_v1951 = out_602; hsl _s1951 = f10_nm(((int64_t)(((*({ hrv *_t1953 = &(g557); int64_t _i1953 = (x_603).a_; (S10*)_t1953->b + hr_ix(_i1953, _t1953->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:212"); }))).name_))); hr_append(_v1951, _s1951.p, _s1951.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1955 = &(g557); int64_t _i1955 = (x_603).a_; (S10*)_t1955->b + hr_ix(_i1955, _t1955->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:212"); }))).ta_)), ((int64_t)(((*({ hrv *_t1956 = &(g557); int64_t _i1956 = (x_603).a_; (S10*)_t1956->b + hr_ix(_i1956, _t1956->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:212"); }))).tn_)), out_602));
return;
 }
if (((k_604) == (((int64_t)6LL)))) { (void)(({ hrv *_v1957 = out_602; hsl _s1957 = f10_nm(((int64_t)(((*({ hrv *_t1959 = &(g559); int64_t _i1959 = (x_603).a_; (S8*)_t1959->b + hr_ix(_i1959, _t1959->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:213"); }))).name_))); hr_append(_v1957, _s1957.p, _s1957.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1961 = &(g559); int64_t _i1961 = (x_603).a_; (S8*)_t1961->b + hr_ix(_i1961, _t1961->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:213"); }))).ta_)), ((int64_t)(((*({ hrv *_t1962 = &(g559); int64_t _i1962 = (x_603).a_; (S8*)_t1962->b + hr_ix(_i1962, _t1962->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:213"); }))).tn_)), out_602));
if (((((uint16_t)((uint64_t)(x_603).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v1963 = out_602; hsl _s1963 = hr_str("..", 2); hr_append(_v1963, _s1963.p, _s1963.n, sizeof(uint8_t)); }));
 }
return;
 }
if (((k_604) == (((int64_t)7LL)))) { (void)(({ hrv *_v1964 = out_602; hsl _s1964 = f10_nm(((int64_t)(((*({ hrv *_t1966 = &(g559); int64_t _i1966 = (x_603).a_; (S8*)_t1966->b + hr_ix(_i1966, _t1966->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).name_))); hr_append(_v1964, _s1964.p, _s1964.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1968 = &(g559); int64_t _i1968 = (x_603).a_; (S8*)_t1968->b + hr_ix(_i1968, _t1968->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).ta_)), ((int64_t)(((*({ hrv *_t1969 = &(g559); int64_t _i1969 = (x_603).a_; (S8*)_t1969->b + hr_ix(_i1969, _t1969->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).tn_)), out_602));
(void)(({ hrv *_v1970 = out_602; uint8_t _x1970 = ((uint8_t)46LL); uint8_t *_p1970 = (uint8_t*)hr_grow(_v1970, 1, sizeof _x1970); *_p1970 = _x1970; _p1970; }));
(void)(({ hrv *_v1971 = out_602; hsl _s1971 = f10_nm(((int64_t)(((*({ hrv *_t1973 = &(g560); int64_t _i1973 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1974 = &(g559); int64_t _i1974 = (x_603).a_; (S8*)_t1974->b + hr_ix(_i1974, _t1974->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).v0_)) + (int64_t)((int64_t)((x_603).c_)))); (S9*)_t1973->b + hr_ix(_i1973, _t1973->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).name_))); hr_append(_v1971, _s1971.p, _s1971.n, sizeof(uint8_t)); }));
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
(void)(f127_ty_name_into(((int64_t)((*({ hrv *_t2002 = &(g555); int64_t _i2002 = ((int64_t)((int64_t)((int64_t)((x_603).l_)) + (int64_t)((int64_t)(i_613)))); (int32_t*)_t2002->b + hr_ix(_i2002, _t2002->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:232"); })))), out_602));
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
(void)(f127_ty_name_into(((int64_t)((*({ hrv *_t2012 = &(g555); int64_t _i2012 = ((int64_t)((int64_t)l_608 + (int64_t)i_611)); (int32_t*)_t2012->b + hr_ix(_i2012, _t2012->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:235"); })))), out_610));
 } } _bk2008:; 
(void)(({ hrv *_v2013 = out_610; uint8_t _x2013 = ((uint8_t)62LL); uint8_t *_p2013 = (uint8_t*)hr_grow(_v2013, 1, sizeof _x2013); *_p2013 = _x2013; _p2013; }));
}
static int64_t f130_gb_find(int64_t name_615) {
int64_t i_616 = ((int64_t)((int64_t)(g494).n - (int64_t)((int64_t)1LL))); 
while (((i_616) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t2015 = &(g494); int64_t _i2015 = i_616; (S7*)_t2015->b + hr_ix(_i2015, _t2015->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:72"); }))).name_))) == (name_615))) { return ((int64_t)(((*({ hrv *_t2016 = &(g494); int64_t _i2016 = i_616; (S7*)_t2016->b + hr_ix(_i2016, _t2016->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:72"); }))).ty_));
 }
i_616--;
 } _bk2014:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f131_inst_struct(int64_t node_622, hsl args_623) {
{ hrv *_v2018 = &(g557); for (int64_t _k2018 = 0; _k2018 < _v2018->n; _k2018++) { S10 s_624 = ((S10*)_v2018->b)[_k2018]; int64_t i_625 = (int64_t)_k2018; if ((((((int64_t)((s_624).node_))) == (node_622)) && ((((int64_t)((s_624).tn_))) == ((args_623).n)))) { bool same_626 = true; 
{ int64_t _e2020 = (args_623).n; for (int64_t _k2020 = 0; _k2020 < _e2020; _k2020++) { int64_t j_627 = (int64_t)_k2020; if ((((*({ hrv *_t2021 = &(g555); int64_t _i2021 = ((int64_t)((int64_t)((int64_t)((s_624).ta_)) + (int64_t)j_627)); (int32_t*)_t2021->b + hr_ix(_i2021, _t2021->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:146"); }))) != ((*({ hsl _t2022 = args_623; int64_t _i2022 = j_627; (int32_t*)_t2022.p + hr_ix(_i2022, _t2022.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:146"); }))))) { same_626 = false;
 }
 } } _bk2019:; 
if (same_626) { return i_625;
 }
 }
 } } _bk2017:; 
int64_t ta_628 = (g555).n; 
(void)(({ hrv *_v2023 = &(g555); hsl _s2023 = args_623; hr_append(_v2023, _s2023.p, _s2023.n, sizeof(int32_t)); }));
int64_t si_629 = (g557).n; 
(void)(({ hrv *_v2024 = &(g557); S10 _x2024 = ((S10){ .node_ = ((int32_t)(node_622)), .ta_ = ((int32_t)(ta_628)), .tn_ = ((int32_t)((args_623).n)), .f0_ = ((int32_t)((g558).n)), .fnum_ = ((int32_t)0LL), .name_ = ((*({ hrv *_t2025 = &(g707); int64_t _i2025 = node_622; (S4*)_t2025->b + hr_ix(_i2025, _t2025->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:149"); }))).s_, }); S10 *_p2024 = (S10*)hr_grow(_v2024, 1, sizeof _x2024); *_p2024 = _x2024; _p2024; }));
L66 gn_630 = ({ L66 _t2026; memset(&_t2026, 0, sizeof _t2026); _t2026.n = 0; _t2026; }); 
(void)(f132_gen_names(((int64_t)(((*({ hrv *_t2028 = &(g707); int64_t _i2028 = node_622; (S4*)_t2028->b + hr_ix(_i2028, _t2028->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:150"); }))).d_)), (&(gn_630))));
if (((((int64_t)(gn_630).n)) != ((args_623).n))) { (void)(f102_derr(((int64_t)(((*({ hrv *_t2030 = &(g707); int64_t _i2030 = node_622; (S4*)_t2030->b + hr_ix(_i2030, _t2030->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:151"); }))).t_)), hr_str("wrong number of type arguments", 30)));
 }
int64_t g0_634 = (g494).n; 
{ int64_t _e2032 = f45_min(((int64_t)(gn_630).n), (args_623).n); for (int64_t _k2032 = 0; _k2032 < _e2032; _k2032++) { int64_t i_635 = (int64_t)_k2032; (void)(({ hrv *_v2034 = &(g494); S7 _x2034 = ((S7){ .name_ = (*({ L66 *_t2035 = &(gn_630); int64_t _i2035 = i_635; _t2035->e + hr_ix(_i2035, _t2035->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:153"); })), .ty_ = (*({ hsl _t2036 = args_623; int64_t _i2036 = i_635; (int32_t*)_t2036.p + hr_ix(_i2036, _t2036.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:153"); })), }); S7 *_p2034 = (S7*)hr_grow(_v2034, 1, sizeof _x2034); *_p2034 = _x2034; _p2034; }));
 } } _bk2031:; 
int64_t f0_644 = f133_fields_into(node_622, f110_ns_of(node_622)); 
{ int32_t *_t2039 = &(((*({ hrv *_t2040 = &(g557); int64_t _i2040 = si_629; (S10*)_t2040->b + hr_ix(_i2040, _t2040->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:155"); }))).f0_); *_t2039 = ((int32_t)(f0_644)); }
{ int32_t *_t2041 = &(((*({ hrv *_t2042 = &(g557); int64_t _i2042 = si_629; (S10*)_t2042->b + hr_ix(_i2042, _t2042->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:155"); }))).fnum_); *_t2041 = ((int32_t)(((int64_t)((int64_t)(g558).n - (int64_t)f0_644)))); }
(void)(({ hrv *_v2043 = &(g494); int64_t _k2043 = ((int64_t)((int64_t)(g494).n - (int64_t)g0_634)); if (_k2043 < 0 || _k2043 > _v2043->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:156"); _v2043->n -= _k2043; }));
return si_629;
}
static void f132_gen_names(int64_t gl_631, L66* out_632) {
if (((gl_631) >= (((int64_t)0LL)))) { { int32_t _e2045 = ((*({ hrv *_t2046 = &(g707); int64_t _i2046 = gl_631; (S4*)_t2046->b + hr_ix(_i2046, _t2046->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:144"); }))).n_; for (int32_t _k2045 = 0; _k2045 < _e2045; _k2045++) { int32_t i_633 = (int32_t)_k2045; (void)(({ L66 *_v2047 = out_632; int32_t _x2047 = ((*({ hrv *_t2048 = &(g707); int64_t _i2048 = f90_kid(gl_631, ((int64_t)(i_633))); (S4*)_t2048->b + hr_ix(_i2048, _t2048->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:144"); }))).s_; if (_v2047->n >= 16) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:144"); _v2047->e[_v2047->n] = _x2047; &_v2047->e[_v2047->n++]; }));
 } } _bk2044:; 
 }
}
static int64_t f133_fields_into(int64_t node_636, int64_t ns_637) {
L73 buf_638 = ({ L73 _t2050; memset(&_t2050, 0, sizeof _t2050); _t2050.n = 0; _t2050; }); 
{ int32_t _e2052 = ((*({ hrv *_t2053 = &(g707); int64_t _i2053 = node_636; (S4*)_t2053->b + hr_ix(_i2053, _t2053->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:161"); }))).n_; for (int32_t _k2052 = 0; _k2052 < _e2052; _k2052++) { int32_t i_639 = (int32_t)_k2052; int64_t f_640 = f90_kid(node_636, ((int64_t)(i_639))); 
S4 x_641 = (*({ hrv *_t2055 = &(g707); int64_t _i2055 = f_640; (S4*)_t2055->b + hr_ix(_i2055, _t2055->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:163"); })); 
if (((((uint16_t)((uint64_t)(x_641).fl_ & (uint64_t)((uint16_t)4LL)))) != (((uint16_t)0LL)))) { (void)(({ L73 *_v2056 = &(buf_638); S11 _x2056 = ((S11){ .name_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .def_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .fl_ = (x_641).fl_, .padn_ = (x_641).c_, .off_ = ((int64_t)0LL), }); if (_v2056->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:164"); _v2056->e[_v2056->n] = _x2056; &_v2056->e[_v2056->n++]; }));
continue;
 }
int64_t ft_642 = f113_rtype(((int64_t)((x_641).a_)), ns_637); 
(void)(({ L73 *_v2058 = &(buf_638); S11 _x2058 = ((S11){ .name_ = (x_641).s_, .ty_ = ((int32_t)(ft_642)), .def_ = (x_641).b_, .fl_ = (x_641).fl_, .padn_ = ((int32_t)0LL), .off_ = ((int64_t)0LL), }); if (_v2058->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:166"); _v2058->e[_v2058->n] = _x2058; &_v2058->e[_v2058->n++]; }));
 } } _bk2051:; 
int64_t f0_643 = (g558).n; 
(void)(({ hrv *_v2059 = &(g558); hsl _s2059 = ({ hsl _t2060 = ({ L73 *_t2061 = &(buf_638); (hsl){ (uint8_t*)_t2061->e, _t2061->n }; }); int64_t _l2060 = 0, _h2060 = _t2060.n; if (_l2060 < 0 || _h2060 < _l2060 || _h2060 > _t2060.n) hr_slerr(_l2060, _h2060, _t2060.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:169"); (hsl){ _t2060.p + _l2060 * (int64_t)sizeof(S11), _h2060 - _l2060 }; }); hr_append(_v2059, _s2059.p, _s2059.n, sizeof(S11)); }));
return f0_643;
}
static int64_t f134_t_struct(int64_t si_645) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)5LL))), .a_ = ((int32_t)(si_645)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f135_inst_enum(int64_t node_646, hsl args_647) {
{ hrv *_v2064 = &(g559); for (int64_t _k2064 = 0; _k2064 < _v2064->n; _k2064++) { S8 s_648 = ((S8*)_v2064->b)[_k2064]; int64_t i_649 = (int64_t)_k2064; if ((((((int64_t)((s_648).node_))) == (node_646)) && ((((int64_t)((s_648).tn_))) == ((args_647).n)))) { bool same_650 = true; 
{ int64_t _e2066 = (args_647).n; for (int64_t _k2066 = 0; _k2066 < _e2066; _k2066++) { int64_t j_651 = (int64_t)_k2066; if ((((*({ hrv *_t2067 = &(g555); int64_t _i2067 = ((int64_t)((int64_t)((int64_t)((s_648).ta_)) + (int64_t)j_651)); (int32_t*)_t2067->b + hr_ix(_i2067, _t2067->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:173"); }))) != ((*({ hsl _t2068 = args_647; int64_t _i2068 = j_651; (int32_t*)_t2068.p + hr_ix(_i2068, _t2068.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:173"); }))))) { same_650 = false;
 }
 } } _bk2065:; 
if (same_650) { return i_649;
 }
 }
 } } _bk2063:; 
int64_t ta_652 = (g555).n; 
(void)(({ hrv *_v2069 = &(g555); hsl _s2069 = args_647; hr_append(_v2069, _s2069.p, _s2069.n, sizeof(int32_t)); }));
int64_t ei_653 = (g559).n; 
int64_t nv_654 = ((int64_t)(((*({ hrv *_t2070 = &(g707); int64_t _i2070 = node_646; (S4*)_t2070->b + hr_ix(_i2070, _t2070->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:176"); }))).n_)); 
(void)(({ hrv *_v2071 = &(g559); S8 _x2071 = ((S8){ .node_ = ((int32_t)(node_646)), .ta_ = ((int32_t)(ta_652)), .tn_ = ((int32_t)((args_647).n)), .v0_ = ((int32_t)((g560).n)), .vnum_ = ((int32_t)(nv_654)), .name_ = ((*({ hrv *_t2072 = &(g707); int64_t _i2072 = node_646; (S4*)_t2072->b + hr_ix(_i2072, _t2072->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:177"); }))).s_, }); S8 *_p2071 = (S8*)hr_grow(_v2071, 1, sizeof _x2071); *_p2071 = _x2071; _p2071; }));
int64_t v0_655 = (g560).n; 
{ int64_t _e2074 = nv_654; for (int64_t _k2074 = 0; _k2074 < _e2074; _k2074++) { int64_t i_656 = (int64_t)_k2074; int64_t v_657 = f90_kid(node_646, i_656); 
(void)(({ hrv *_v2076 = &(g560); S9 _x2076 = ((S9){ .name_ = ((*({ hrv *_t2077 = &(g707); int64_t _i2077 = v_657; (S4*)_t2077->b + hr_ix(_i2077, _t2077->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:179"); }))).s_, .f0_ = ((int32_t)0LL), .fnum_ = ((int32_t)0LL), .si_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .size_ = ((int64_t)0LL), .haspay_ = ((((uint16_t)((uint64_t)((*({ hrv *_t2078 = &(g707); int64_t _i2078 = v_657; (S4*)_t2078->b + hr_ix(_i2078, _t2078->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:179"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))), }); S9 *_p2076 = (S9*)hr_grow(_v2076, 1, sizeof _x2076); *_p2076 = _x2076; _p2076; }));
 } } _bk2073:; 
L66 gn_658 = ({ L66 _t2079; memset(&_t2079, 0, sizeof _t2079); _t2079.n = 0; _t2079; }); 
(void)(f132_gen_names(((int64_t)(((*({ hrv *_t2081 = &(g707); int64_t _i2081 = node_646; (S4*)_t2081->b + hr_ix(_i2081, _t2081->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:180"); }))).d_)), (&(gn_658))));
int64_t g0_659 = (g494).n; 
{ int64_t _e2083 = f45_min(((int64_t)(gn_658).n), (args_647).n); for (int64_t _k2083 = 0; _k2083 < _e2083; _k2083++) { int64_t i_660 = (int64_t)_k2083; (void)(({ hrv *_v2085 = &(g494); S7 _x2085 = ((S7){ .name_ = (*({ L66 *_t2086 = &(gn_658); int64_t _i2086 = i_660; _t2086->e + hr_ix(_i2086, _t2086->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:182"); })), .ty_ = (*({ hsl _t2087 = args_647; int64_t _i2087 = i_660; (int32_t*)_t2087.p + hr_ix(_i2087, _t2087.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:182"); })), }); S7 *_p2085 = (S7*)hr_grow(_v2085, 1, sizeof _x2085); *_p2085 = _x2085; _p2085; }));
 } } _bk2082:; 
int64_t ns_661 = f110_ns_of(node_646); 
{ int64_t _e2090 = nv_654; for (int64_t _k2090 = 0; _k2090 < _e2090; _k2090++) { int64_t i_662 = (int64_t)_k2090; int64_t v_663 = f90_kid(node_646, i_662); 
int64_t si_664 = (g557).n; 
(void)(({ hrv *_v2092 = &(g557); S10 _x2092 = ((S10){ .node_ = ((int32_t)(v_663)), .ta_ = ((int32_t)(ta_652)), .tn_ = ((int32_t)((args_647).n)), .f0_ = ((int32_t)((g558).n)), .fnum_ = ((int32_t)0LL), .name_ = ((*({ hrv *_t2093 = &(g707); int64_t _i2093 = v_663; (S4*)_t2093->b + hr_ix(_i2093, _t2093->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:187"); }))).s_, }); S10 *_p2092 = (S10*)hr_grow(_v2092, 1, sizeof _x2092); *_p2092 = _x2092; _p2092; }));
int64_t f0_665 = f133_fields_into(v_663, ns_661); 
{ int32_t *_t2095 = &(((*({ hrv *_t2096 = &(g557); int64_t _i2096 = si_664; (S10*)_t2096->b + hr_ix(_i2096, _t2096->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:189"); }))).f0_); *_t2095 = ((int32_t)(f0_665)); }
{ int32_t *_t2097 = &(((*({ hrv *_t2098 = &(g557); int64_t _i2098 = si_664; (S10*)_t2098->b + hr_ix(_i2098, _t2098->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:189"); }))).fnum_); *_t2097 = ((int32_t)(((int64_t)((int64_t)(g558).n - (int64_t)f0_665)))); }
{ int32_t *_t2099 = &(((*({ hrv *_t2100 = &(g560); int64_t _i2100 = ((int64_t)((int64_t)v0_655 + (int64_t)i_662)); (S9*)_t2100->b + hr_ix(_i2100, _t2100->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:190"); }))).si_); *_t2099 = ((int32_t)(si_664)); }
 } } _bk2089:; 
(void)(({ hrv *_v2101 = &(g494); int64_t _k2101 = ((int64_t)((int64_t)(g494).n - (int64_t)g0_659)); if (_k2101 < 0 || _k2101 > _v2101->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:192"); _v2101->n -= _k2101; }));
return ei_653;
}
static int64_t f136_t_enum(int64_t ei_666, bool vm_667) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)6LL))), .fl_ = ({ uint16_t _r2103; if (vm_667) { _r2103 = ((uint16_t)1LL);  } else { _r2103 = ((uint16_t)0LL);  } _r2103; }), .a_ = ((int32_t)(ei_666)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f137_ck(int64_t n_671, int64_t want_672) {
if (((n_671) < (((int64_t)0LL)))) { return g561;
 }
S4 x_673 = (*({ hrv *_t2104 = &(g707); int64_t _i2104 = n_671; (S4*)_t2104->b + hr_ix(_i2104, _t2104->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:680"); })); 
int64_t k_674 = ((int64_t)((x_673).k_)); 
if (((k_674) == (((int64_t)1LL)))) { if ((((want_672) >= (((int64_t)0LL))) && ((((((*({ hrv *_t2105 = &(g554); int64_t _i2105 = want_672; (S1*)_t2105->b + hr_ix(_i2105, _t2105->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:682"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2106 = &(g554); int64_t _i2106 = want_672; (S1*)_t2106->b + hr_ix(_i2106, _t2106->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:682"); }))).k_) == (((uint8_t)4LL)))) || ((((*({ hrv *_t2107 = &(g554); int64_t _i2107 = want_672; (S1*)_t2107->b + hr_ix(_i2107, _t2107->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:682"); }))).k_) == (((uint8_t)17LL)))))) { (void)(f138_set_t(n_671, g574));
(void)(f140_conv(n_671, want_672));
return want_672;
 }
return f138_set_t(n_671, g574);
 }
if (((k_674) == (((int64_t)2LL)))) { if ((((want_672) >= (((int64_t)0LL))) && ((((*({ hrv *_t2111 = &(g554); int64_t _i2111 = want_672; (S1*)_t2111->b + hr_ix(_i2111, _t2111->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:683"); }))).k_) == (((uint8_t)4LL))))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g575);
 }
if (((k_674) == (((int64_t)3LL)))) { if ((((want_672) >= (((int64_t)0LL))) && f167_is_byte_arr(want_672))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g576);
 }
if ((((k_674) == (((int64_t)4LL))) || ((k_674) == (((int64_t)5LL))))) { return f138_set_t(n_671, g562);
 }
if (((k_674) == (((int64_t)6LL)))) { if ((((want_672) >= (((int64_t)0LL))) && f168_is_opt(want_672))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g573);
 }
if (((k_674) == (((int64_t)7LL)))) { return f138_set_t(n_671, ({ int64_t _r2122; if (((want_672) >= (((int64_t)0LL)))) { _r2122 = want_672;  } else { _r2122 = g578;  } _r2122; }));
 }
if (((k_674) == (((int64_t)8LL)))) { return f169_ck_id(n_671, want_672);
 }
if (((k_674) == (((int64_t)9LL)))) { int64_t t_905 = f179_ck_bin(n_671, want_672); 
if (((((want_672) >= (((int64_t)0LL))) && f166_is_pending(t_905)) && (((((*({ hrv *_t2126 = &(g554); int64_t _i2126 = want_672; (S1*)_t2126->b + hr_ix(_i2126, _t2126->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:689"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2127 = &(g554); int64_t _i2127 = want_672; (S1*)_t2127->b + hr_ix(_i2127, _t2127->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:689"); }))).k_) == (((uint8_t)4LL)))))) { (void)(f140_conv(n_671, want_672));
return want_672;
 }
return t_905;
 }
if (((k_674) == (((int64_t)10LL)))) { int64_t t_932 = f186_ck_un(n_671, want_672); 
if (((((want_672) >= (((int64_t)0LL))) && f166_is_pending(t_932)) && (((((*({ hrv *_t2131 = &(g554); int64_t _i2131 = want_672; (S1*)_t2131->b + hr_ix(_i2131, _t2131->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:690"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2132 = &(g554); int64_t _i2132 = want_672; (S1*)_t2132->b + hr_ix(_i2132, _t2132->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:690"); }))).k_) == (((uint8_t)4LL)))))) { (void)(f140_conv(n_671, want_672));
return want_672;
 }
return t_932;
 }
if (((k_674) == (((int64_t)14LL)))) { return f188_ck_dot(n_671, want_672);
 }
if (((k_674) == (((int64_t)12LL)))) { return f192_ck_idx(n_671, want_672);
 }
if (((k_674) == (((int64_t)13LL)))) { return f193_ck_slice(n_671, want_672);
 }
if (((k_674) == (((int64_t)15LL)))) { return f194_ck_as(n_671, want_672);
 }
if (((k_674) == (((int64_t)16LL)))) { return f195_ck_arr(n_671, want_672);
 }
if (((k_674) == (((int64_t)23LL)))) { return f196_ck_block(n_671, want_672);
 }
if (((k_674) == (((int64_t)24LL)))) { (void)(({ hrv *_v2140 = &(g471); int32_t _x2140 = ({ int32_t _r2141; if ((((want_672) >= (((int64_t)0LL))) && ((want_672) != (g561)))) { _r2141 = ((int32_t)(want_672));  } else { _r2141 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));  } _r2141; }); int32_t *_p2140 = (int32_t*)hr_grow(_v2140, 1, sizeof _x2140); *_p2140 = _x2140; _p2140; }));
int64_t bt_1115 = f137_ck(((int64_t)((x_673).a_)), want_672); 
int64_t t_1116 = ((int64_t)(({ hrv *_v2143 = &(g471); if (!_v2143->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:697"); ((int32_t*)_v2143->b)[--_v2143->n]; }))); 
if ((((bt_1115) != (g561)) && (!(f166_is_pending(bt_1115))))) { return f138_set_t(n_671, bt_1115);
 }
if (((t_1116) >= (((int64_t)0LL)))) { (void)(f140_conv(((int64_t)((x_673).a_)), t_1116));
return f138_set_t(n_671, t_1116);
 }
return f138_set_t(n_671, bt_1115);
 }
if (((k_674) == (((int64_t)19LL)))) { return f214_ck_if(n_671, want_672);
 }
if (((k_674) == (((int64_t)25LL)))) { return f215_ck_while(n_671);
 }
if (((k_674) == (((int64_t)26LL)))) { return f216_ck_loop(n_671, want_672);
 }
if (((k_674) == (((int64_t)27LL)))) { return f217_ck_for(n_671);
 }
if (((k_674) == (((int64_t)20LL)))) { return f220_ck_match(n_671, want_672);
 }
if (((k_674) == (((int64_t)28LL)))) { return f221_ck_ret(n_671);
 }
if (((k_674) == (((int64_t)29LL)))) { return f224_ck_break(n_671);
 }
if (((k_674) == (((int64_t)30LL)))) { return f138_set_t(n_671, g561);
 }
if (((k_674) == (((int64_t)11LL)))) { return f225_ck_call(n_671, want_672);
 }
if (((k_674) == (((int64_t)17LL)))) { return f258_ck_slit(n_671, want_672);
 }
if (((k_674) == (((int64_t)31LL)))) { return f138_set_t(n_671, g581);
 }
(void)(f108_cerr(n_671, hr_str("unsupported expression", 22)));
return f138_set_t(n_671, g578);
}
static int64_t f138_set_t(int64_t n_675, int64_t t_676) {
{ int32_t *_t2162 = &((*({ hrv *_t2163 = &(g397); int64_t _i2163 = f139_aix(n_675); (int32_t*)_t2163->b + hr_ix(_i2163, _t2163->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:42"); }))); *_t2162 = ((int32_t)(t_676)); }
return t_676;
}
static int64_t f139_aix(int64_t n_677) {
int64_t i_678 = g403; 
while (((i_678) >= (((int64_t)0LL)))) { S6 f_679 = (*({ hrv *_t2166 = &(g390); int64_t _i2166 = i_678; (S6*)_t2166->b + hr_ix(_i2166, _t2166->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:37"); })); 
if ((((n_677) >= (((int64_t)((f_679).lo_)))) && ((n_677) < (((int64_t)((f_679).hi_)))))) { return ((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((f_679).ab_)) + (int64_t)n_677)) - (int64_t)((int64_t)((f_679).lo_))));
 }
i_678 = ((int64_t)((f_679).par_));
 } _bk2165:; 
S6 g_680 = (*({ hrv *_t2167 = &(g390); int64_t _i2167 = g405; (S6*)_t2167->b + hr_ix(_i2167, _t2167->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:38"); })); 
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
int64_t fk_685 = ((int64_t)(((*({ hrv *_t2169 = &(g554); int64_t _i2169 = f_684; (S1*)_t2169->b + hr_ix(_i2169, _t2169->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:155"); }))).k_)); 
int64_t tkd_686 = ((int64_t)(((*({ hrv *_t2170 = &(g554); int64_t _i2170 = t_682; (S1*)_t2170->b + hr_ix(_i2170, _t2170->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:156"); }))).k_)); 
if ((((tkd_686) == (((int64_t)0LL))) || ((fk_685) == (((int64_t)0LL))))) { return true;
 }
int64_t nk_687 = ((int64_t)(((*({ hrv *_t2171 = &(g707); int64_t _i2171 = n_681; (S4*)_t2171->b + hr_ix(_i2171, _t2171->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:158"); }))).k_)); 
if (((((((((nk_687) == (((int64_t)23LL))) || ((nk_687) == (((int64_t)24LL)))) || ((nk_687) == (((int64_t)19LL)))) || ((nk_687) == (((int64_t)20LL)))) && ((fk_685) == (((int64_t)7LL)))) && ((tkd_686) == (((int64_t)6LL)))) && ((((*({ hrv *_t2172 = &(g554); int64_t _i2172 = f_684; (S1*)_t2172->b + hr_ix(_i2172, _t2172->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:159"); }))).a_) == (((*({ hrv *_t2173 = &(g554); int64_t _i2173 = t_682; (S1*)_t2173->b + hr_ix(_i2173, _t2173->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:159"); }))).a_)))) { (void)(f142_conv_tail(n_681, t_682));
(void)(f138_set_t(n_681, t_682));
return true;
 }
if (((((tkd_686) == (((int64_t)2LL))) && ((fk_685) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2176 = &(g554); int64_t _i2176 = f_684; (S1*)_t2176->b + hr_ix(_i2176, _t2176->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:160"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f145_set_cv(n_681, g562));
return true;
 }
if ((((((tkd_686) == (((int64_t)10LL))) && ((((*({ hrv *_t2178 = &(g554); int64_t _i2178 = t_682; (S1*)_t2178->b + hr_ix(_i2178, _t2178->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:161"); }))).c_) < (((int32_t)0LL)))) && ((fk_685) != (((int64_t)11LL)))) && ((fk_685) != (((int64_t)10LL))))) { if (((f146_tclass(t_682)) >= (((int64_t)0LL)))) { bool ok_751 = f140_conv(n_681, ((int64_t)(((*({ hrv *_t2181 = &(g554); int64_t _i2181 = t_682; (S1*)_t2181->b + hr_ix(_i2181, _t2181->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:161"); }))).a_))); 
if ((ok_751 && ((f153_cv(n_681)) < (((int64_t)0LL))))) { (void)(f145_set_cv(n_681, t_682));
 }
return ok_751;
 }
 }
if (((((fk_685) == (((int64_t)10LL))) && ((((*({ hrv *_t2184 = &(g554); int64_t _i2184 = f_684; (S1*)_t2184->b + hr_ix(_i2184, _t2184->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:162"); }))).c_) < (((int32_t)0LL)))) && ((tkd_686) != (((int64_t)10LL))))) { if (f154_conv_ok(((int64_t)(((*({ hrv *_t2186 = &(g554); int64_t _i2186 = f_684; (S1*)_t2186->b + hr_ix(_i2186, _t2186->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:162"); }))).a_)), t_682, n_681)) { (void)(f145_set_cv(n_681, t_682));
return true;
 }
 }
if (((fk_685) == (((int64_t)12LL)))) { M78 _t2188 = f158_cval(n_681); int64_t v_781 = _t2188.r0; bool u_782 = _t2188.r1; bool ok_783 = _t2188.r2; 
if (((tkd_686) == (((int64_t)3LL)))) { if ((ok_783 && (!(f161_int_fits(v_781, u_782, t_682))))) { hrv m_792 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2193 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2192 = &(m_792); hr_fs(_o2192, hr_str("constant ", 9)); hr_fi(_o2192, v_781); hr_fs(_o2192, hr_str(" does not fit in ", 17)); hr_fs(_o2192, hr_sl(*hr_tmp(&_t2193, f164_tn(t_682)))); }));
}
(void)(f108_cerr(n_681, hr_sl(m_792)));
return false;
 }
(void)(f165_commit(n_681, t_682));
return true;
 }
if ((((tkd_686) == (((int64_t)4LL))) || ((tkd_686) == (((int64_t)17LL))))) { (void)(f165_commit(n_681, t_682));
return true;
 }
 }
if ((((fk_685) == (((int64_t)13LL))) && ((tkd_686) == (((int64_t)4LL))))) { (void)(f165_commit(n_681, t_682));
return true;
 }
if ((((fk_685) == (((int64_t)18LL))) && (f167_is_byte_arr(t_682) || (((tkd_686) == (((int64_t)10LL))) && f167_is_byte_arr(((int64_t)(((*({ hrv *_t2201 = &(g554); int64_t _i2201 = t_682; (S1*)_t2201->b + hr_ix(_i2201, _t2201->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:169"); }))).a_))))))) { (void)(f165_commit(n_681, ({ int64_t _r2203; if (((tkd_686) == (((int64_t)10LL)))) { _r2203 = ((int64_t)(((*({ hrv *_t2204 = &(g554); int64_t _i2204 = t_682; (S1*)_t2204->b + hr_ix(_i2204, _t2204->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:169"); }))).a_));  } else { _r2203 = t_682;  } _r2203; })));
return true;
 }
if ((((fk_685) == (((int64_t)19LL))) && (((tkd_686) == (((int64_t)8LL))) || ((tkd_686) == (((int64_t)9LL)))))) { (void)(f165_commit(n_681, t_682));
return true;
 }
if (((((fk_685) == (((int64_t)11LL))) && ((tkd_686) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2206 = &(g554); int64_t _i2206 = t_682; (S1*)_t2206->b + hr_ix(_i2206, _t2206->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:171"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f165_commit(n_681, t_682));
return true;
 }
if (f154_conv_ok(f_684, t_682, n_681)) { (void)(f145_set_cv(n_681, t_682));
return true;
 }
hrv m_807 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2212 __attribute__((cleanup(hr_rdrop))) = {0}; hrv _t2214 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2211 = &(m_807); hr_fs(_o2211, hr_str("cannot convert ", 15)); hr_fs(_o2211, hr_sl(*hr_tmp(&_t2212, f164_tn(f_684)))); hr_fs(_o2211, hr_str(" to ", 4)); hr_fs(_o2211, hr_sl(*hr_tmp(&_t2214, f164_tn(t_682)))); }));
}
(void)(f108_cerr(n_681, hr_sl(m_807)));
return false;
}
static int64_t f141_at(int64_t n_683) {
return ((int64_t)((*({ hrv *_t2217 = &(g397); int64_t _i2217 = f139_aix(n_683); (int32_t*)_t2217->b + hr_ix(_i2217, _t2217->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:41"); }))));
}
static void f142_conv_tail(int64_t n_688, int64_t t_689) {
S4 x_690 = (*({ hrv *_t2219 = &(g707); int64_t _i2219 = n_688; (S4*)_t2219->b + hr_ix(_i2219, _t2219->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:145"); })); 
int64_t k_691 = ((int64_t)((x_690).k_)); 
if ((((k_691) == (((int64_t)23LL))) || ((k_691) == (((int64_t)24LL))))) { if (((((x_690).a_) >= (((int32_t)0LL))) && (!(f143_ends(((int64_t)((x_690).a_))))))) { (void)(f140_conv(((int64_t)((x_690).a_)), t_689));
 }
return;
 }
if (((k_691) == (((int64_t)19LL)))) { if ((!(f143_ends(((int64_t)((x_690).b_)))))) { (void)(f140_conv(((int64_t)((x_690).b_)), t_689));
 }
if (((((x_690).c_) >= (((int32_t)0LL))) && (!(f143_ends(((int64_t)((x_690).c_))))))) { (void)(f140_conv(((int64_t)((x_690).c_)), t_689));
 }
return;
 }
if (((k_691) == (((int64_t)20LL)))) { { int32_t _e2227 = (x_690).n_; for (int32_t _k2227 = 0; _k2227 < _e2227; _k2227++) { int32_t i_701 = (int32_t)_k2227; int64_t b_702 = ((int64_t)(((*({ hrv *_t2228 = &(g707); int64_t _i2228 = f90_kid(n_688, ((int64_t)(i_701))); (S4*)_t2228->b + hr_ix(_i2228, _t2228->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:148"); }))).b_)); 
if ((((b_702) >= (((int64_t)0LL))) && (!(f143_ends(b_702))))) { (void)(f140_conv(b_702, t_689));
 }
 } } _bk2226:; 
 }
}
static bool f143_ends(int64_t n_692) {
if (((n_692) < (((int64_t)0LL)))) { return false;
 }
int64_t k_693 = ((int64_t)(((*({ hrv *_t2232 = &(g707); int64_t _i2232 = n_692; (S4*)_t2232->b + hr_ix(_i2232, _t2232->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:500"); }))).k_)); 
if (((((k_693) == (((int64_t)28LL))) || ((k_693) == (((int64_t)29LL)))) || ((k_693) == (((int64_t)30LL))))) { return true;
 }
if ((((k_693) == (((int64_t)11LL))) && ((((*({ hrv *_t2233 = &(g707); int64_t _i2233 = ((*({ hrv *_t2234 = &(g707); int64_t _i2234 = n_692; (S4*)_t2234->b + hr_ix(_i2234, _t2234->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:502"); }))).a_; (S4*)_t2233->b + hr_ix(_i2233, _t2233->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:502"); }))).k_) == (((uint8_t)8LL))))) { hsl s_694 = f10_nm(((int64_t)(((*({ hrv *_t2236 = &(g707); int64_t _i2236 = ((*({ hrv *_t2237 = &(g707); int64_t _i2237 = n_692; (S4*)_t2237->b + hr_ix(_i2237, _t2237->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:502"); }))).a_; (S4*)_t2236->b + hr_ix(_i2236, _t2236->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:502"); }))).s_))); 
if ((hr_streq(s_694, hr_str("abort", 5)) || hr_streq(s_694, hr_str("exit", 4)))) { return true;
 }
 }
if (((k_693) == (((int64_t)23LL)))) { if (((((*({ hrv *_t2238 = &(g707); int64_t _i2238 = n_692; (S4*)_t2238->b + hr_ix(_i2238, _t2238->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:503"); }))).a_) >= (((int32_t)0LL)))) { return f143_ends(((int64_t)(((*({ hrv *_t2240 = &(g707); int64_t _i2240 = n_692; (S4*)_t2240->b + hr_ix(_i2240, _t2240->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:503"); }))).a_)));
 }
if (((((*({ hrv *_t2241 = &(g707); int64_t _i2241 = n_692; (S4*)_t2241->b + hr_ix(_i2241, _t2241->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:503"); }))).n_) > (((int32_t)0LL)))) { return f143_ends(f90_kid(n_692, ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2244 = &(g707); int64_t _i2244 = n_692; (S4*)_t2244->b + hr_ix(_i2244, _t2244->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:503"); }))).n_)) - (int64_t)((int64_t)1LL)))));
 }
return false;
 }
if (((k_693) == (((int64_t)19LL)))) { return ((((((*({ hrv *_t2245 = &(g707); int64_t _i2245 = n_692; (S4*)_t2245->b + hr_ix(_i2245, _t2245->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:504"); }))).c_) >= (((int32_t)0LL))) && f143_ends(((int64_t)(((*({ hrv *_t2247 = &(g707); int64_t _i2247 = n_692; (S4*)_t2247->b + hr_ix(_i2247, _t2247->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:504"); }))).b_)))) && f143_ends(((int64_t)(((*({ hrv *_t2249 = &(g707); int64_t _i2249 = n_692; (S4*)_t2249->b + hr_ix(_i2249, _t2249->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:504"); }))).c_))));
 }
if (((k_693) == (((int64_t)26LL)))) { return (!(f144_has_break(((int64_t)(((*({ hrv *_t2251 = &(g707); int64_t _i2251 = n_692; (S4*)_t2251->b + hr_ix(_i2251, _t2251->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:505"); }))).a_)))));
 }
return false;
}
static bool f144_has_break(int64_t n_695) {
if (((n_695) < (((int64_t)0LL)))) { return false;
 }
S4 x_696 = (*({ hrv *_t2252 = &(g707); int64_t _i2252 = n_695; (S4*)_t2252->b + hr_ix(_i2252, _t2252->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:510"); })); 
int64_t k_697 = ((int64_t)((x_696).k_)); 
if (((k_697) == (((int64_t)29LL)))) { return true;
 }
if (((((((k_697) == (((int64_t)25LL))) || ((k_697) == (((int64_t)26LL)))) || ((k_697) == (((int64_t)27LL)))) || ((k_697) == (((int64_t)50LL)))) || ((k_697) == (((int64_t)31LL))))) { return false;
 }
if ((((k_697) >= (((int64_t)40LL))) && ((k_697) < (((int64_t)50LL))))) { return false;
 }
if (((k_697) == (((int64_t)33LL)))) { return f144_has_break(((int64_t)((x_696).b_)));
 }
if (((k_697) == (((int64_t)11LL)))) { if (f144_has_break(((int64_t)((x_696).a_)))) { return true;
 }
{ int32_t _e2256 = (x_696).n_; for (int32_t _k2256 = 0; _k2256 < _e2256; _k2256++) { int32_t i_698 = (int32_t)_k2256; if (f144_has_break(f90_kid(n_695, ((int64_t)(i_698))))) { return true;
 }
 } } _bk2255:; 
return false;
 }
if ((((f144_has_break(((int64_t)((x_696).a_))) || f144_has_break(((int64_t)((x_696).b_)))) || f144_has_break(((int64_t)((x_696).c_)))) || f144_has_break(((int64_t)((x_696).d_))))) { return true;
 }
if ((((((((k_697) == (((int64_t)23LL))) || ((k_697) == (((int64_t)20LL)))) || ((k_697) == (((int64_t)36LL)))) || ((k_697) == (((int64_t)16LL)))) || ((k_697) == (((int64_t)17LL)))) || ((k_697) == (((int64_t)28LL))))) { { int32_t _e2264 = (x_696).n_; for (int32_t _k2264 = 0; _k2264 < _e2264; _k2264++) { int32_t i_699 = (int32_t)_k2264; int64_t c_700 = f90_kid(n_695, ((int64_t)(i_699))); 
if (f144_has_break(c_700)) { return true;
 }
if ((((k_697) == (((int64_t)20LL))) && f144_has_break(((int64_t)(((*({ hrv *_t2268 = &(g707); int64_t _i2268 = c_700; (S4*)_t2268->b + hr_ix(_i2268, _t2268->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:521"); }))).b_))))) { return true;
 }
 } } _bk2263:; 
 }
return false;
}
static void f145_set_cv(int64_t n_703, int64_t t_704) {
{ int32_t *_t2269 = &((*({ hrv *_t2270 = &(g398); int64_t _i2270 = f139_aix(n_703); (int32_t*)_t2270->b + hr_ix(_i2270, _t2270->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:48"); }))); *_t2269 = ((int32_t)(t_704)); }
}
static int64_t f146_tclass(int64_t t_705) {
S1 x_706 = (*({ hrv *_t2272 = &(g554); int64_t _i2272 = t_705; (S1*)_t2272->b + hr_ix(_i2272, _t2272->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:83"); })); 
int64_t k_707 = ((int64_t)((x_706).k_)); 
if (((k_707) == (((int64_t)5LL)))) { (void)(f147_si_layout(((int64_t)((x_706).a_))));
return ((int64_t)(((*({ hrv *_t2274 = &(g557); int64_t _i2274 = (x_706).a_; (S10*)_t2274->b + hr_ix(_i2274, _t2274->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:85"); }))).cls_));
 }
if (((k_707) == (((int64_t)7LL)))) { (void)(f149_ei_layout(((int64_t)((x_706).a_))));
S9 v_748 = (*({ hrv *_t2276 = &(g560); int64_t _i2276 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2277 = &(g559); int64_t _i2277 = (x_706).a_; (S8*)_t2277->b + hr_ix(_i2277, _t2277->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:86"); }))).v0_)) + (int64_t)((int64_t)((x_706).c_)))); (S9*)_t2276->b + hr_ix(_i2276, _t2276->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:86"); })); 
if ((((v_748).si_) >= (((int32_t)0LL)))) { (void)(f147_si_layout(((int64_t)((v_748).si_))));
return ((int64_t)(((*({ hrv *_t2279 = &(g557); int64_t _i2279 = (v_748).si_; (S10*)_t2279->b + hr_ix(_i2279, _t2279->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:86"); }))).cls_));
 }
return ((int64_t)0LL);
 }
if (((k_707) == (((int64_t)6LL)))) { (void)(f149_ei_layout(((int64_t)((x_706).a_))));
if (((((uint16_t)((uint64_t)(x_706).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) { return ((int64_t)0LL);
 }
return ((int64_t)1LL);
 }
if (((k_707) == (((int64_t)8LL)))) { int64_t a_749 = ((int64_t)((x_706).s_)); 
if ((((a_749) == (((int64_t)4LL))) || ((a_749) == (((int64_t)5LL))))) { return ((int64_t)2LL);
 }
if (((a_749) == (((int64_t)2LL)))) { return ((int64_t)1LL);
 }
if ((((a_749) == (((int64_t)3LL))) && (((x_706).b_) < (((int64_t)0LL))))) { return ((int64_t)1LL);
 }
int64_t ec_750 = f146_tclass(((int64_t)((x_706).a_))); 
return ({ int64_t _r2282; if (((ec_750) > (((int64_t)0LL)))) { _r2282 = ((int64_t)1LL);  } else { _r2282 = ((int64_t)0LL);  } _r2282; });
 }
if ((((k_707) == (((int64_t)17LL))) || (((k_707) == (((int64_t)10LL))) && (((x_706).c_) == (((int32_t)8LL)))))) { return ((int64_t)1LL);
 }
return ((int64_t)0LL);
}
static void f147_si_layout(int64_t si_708) {
if (((((*({ hrv *_t2283 = &(g557); int64_t _i2283 = si_708; (S10*)_t2283->b + hr_ix(_i2283, _t2283->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:127"); }))).done_) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t2284 = &(((*({ hrv *_t2285 = &(g557); int64_t _i2285 = si_708; (S10*)_t2285->b + hr_ix(_i2285, _t2285->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:128"); }))).done_); *_t2284 = ((uint8_t)1LL); }
int64_t off_709 = ((int64_t)0LL); 
int64_t cls_710 = ((int64_t)0LL); 
bool flat_711 = true; 
int64_t f0_712 = ((int64_t)(((*({ hrv *_t2286 = &(g557); int64_t _i2286 = si_708; (S10*)_t2286->b + hr_ix(_i2286, _t2286->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:130"); }))).f0_)); 
int64_t fnum_713 = ((int64_t)(((*({ hrv *_t2287 = &(g557); int64_t _i2287 = si_708; (S10*)_t2287->b + hr_ix(_i2287, _t2287->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:130"); }))).fnum_)); 
{ int64_t _e2289 = fnum_713; for (int64_t _k2289 = 0; _k2289 < _e2289; _k2289++) { int64_t i_714 = (int64_t)_k2289; int64_t fi_715 = ((int64_t)((int64_t)f0_712 + (int64_t)i_714)); 
int64_t ft_716 = ((int64_t)(((*({ hrv *_t2290 = &(g558); int64_t _i2290 = fi_715; (S11*)_t2290->b + hr_ix(_i2290, _t2290->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:133"); }))).ty_)); 
if (((ft_716) >= (((int64_t)0LL)))) { int64_t c_717 = f146_tclass(ft_716); 
if (((c_717) > (cls_710))) { cls_710 = c_717;
 }
if ((!(f148_tflat(ft_716)))) { flat_711 = false;
 }
 }
 } } _bk2288:; 
bool cur_var_731 = false; 
{ int64_t _e2294 = fnum_713; for (int64_t _k2294 = 0; _k2294 < _e2294; _k2294++) { int64_t i_732 = (int64_t)_k2294; int64_t fi_733 = ((int64_t)((int64_t)f0_712 + (int64_t)i_732)); 
int64_t ft_734 = ((int64_t)(((*({ hrv *_t2295 = &(g558); int64_t _i2295 = fi_733; (S11*)_t2295->b + hr_ix(_i2295, _t2295->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:143"); }))).ty_)); 
if (((ft_734) < (((int64_t)0LL)))) { if (((((*({ hrv *_t2296 = &(g558); int64_t _i2296 = fi_733; (S11*)_t2296->b + hr_ix(_i2296, _t2296->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:145"); }))).padn_) < (((int32_t)0LL)))) { if (((cls_710) == (((int64_t)0LL)))) { int64_t a_735 = ((int64_t)1LL); 
{ int64_t _e2298 = fnum_713; for (int64_t _k2298 = ((int64_t)((int64_t)i_732 + (int64_t)((int64_t)1LL))); _k2298 < _e2298; _k2298++) { int64_t j_736 = (int64_t)_k2298; if (((((*({ hrv *_t2299 = &(g558); int64_t _i2299 = ((int64_t)((int64_t)f0_712 + (int64_t)j_736)); (S11*)_t2299->b + hr_ix(_i2299, _t2299->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:148"); }))).ty_) >= (((int32_t)0LL)))) { a_735 = f150_pad_align(((int64_t)(((*({ hrv *_t2301 = &(g558); int64_t _i2301 = ((int64_t)((int64_t)f0_712 + (int64_t)j_736)); (S11*)_t2301->b + hr_ix(_i2301, _t2301->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:148"); }))).ty_)));
{ goto _bk2297; }
 }
 } } _bk2297:; 
int64_t next_off_741 = ((int64_t)((int64_t)HR_SDIV(int64_t, ((int64_t)((int64_t)((int64_t)((int64_t)off_709 + (int64_t)a_735)) - (int64_t)((int64_t)1LL))), a_735, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:149") * (int64_t)a_735)); 
{ int32_t *_t2302 = &(((*({ hrv *_t2303 = &(g558); int64_t _i2303 = fi_733; (S11*)_t2303->b + hr_ix(_i2303, _t2303->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:150"); }))).padn_); *_t2302 = ((int32_t)(((int64_t)((int64_t)next_off_741 - (int64_t)off_709)))); }
{ int64_t *_t2304 = &(((*({ hrv *_t2305 = &(g558); int64_t _i2305 = fi_733; (S11*)_t2305->b + hr_ix(_i2305, _t2305->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:151"); }))).off_); *_t2304 = off_709; }
off_709 = next_off_741;
 } else { { int32_t *_t2306 = &(((*({ hrv *_t2307 = &(g558); int64_t _i2307 = fi_733; (S11*)_t2307->b + hr_ix(_i2307, _t2307->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:154"); }))).padn_); *_t2306 = ((int32_t)0LL); }
{ int64_t *_t2308 = &(((*({ hrv *_t2309 = &(g558); int64_t _i2309 = fi_733; (S11*)_t2309->b + hr_ix(_i2309, _t2309->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:155"); }))).off_); *_t2308 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); }
 }
 } else { { int64_t *_t2310 = &(((*({ hrv *_t2311 = &(g558); int64_t _i2311 = fi_733; (S11*)_t2311->b + hr_ix(_i2311, _t2311->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:158"); }))).off_); *_t2310 = ({ int64_t _r2312; if ((!(cur_var_731))) { _r2312 = off_709;  } else { _r2312 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2312; }); }
if ((!(cur_var_731))) { { int64_t *_t2313 = &(off_709); *_t2313 = ((int64_t)((int64_t)(*_t2313) + (int64_t)((int64_t)(((*({ hrv *_t2314 = &(g558); int64_t _i2314 = fi_733; (S11*)_t2314->b + hr_ix(_i2314, _t2314->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:159"); }))).padn_)))); }
 }
 }
continue;
 }
int64_t c_742 = f146_tclass(ft_734); 
if (((c_742) != (((int64_t)0LL)))) { cur_var_731 = true;
 }
{ int64_t *_t2316 = &(((*({ hrv *_t2317 = &(g558); int64_t _i2317 = fi_733; (S11*)_t2317->b + hr_ix(_i2317, _t2317->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:165"); }))).off_); *_t2316 = ({ int64_t _r2318; if ((!(cur_var_731))) { _r2318 = off_709;  } else { _r2318 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2318; }); }
if ((!(cur_var_731))) { { int64_t *_t2319 = &(off_709); *_t2319 = ((int64_t)((int64_t)(*_t2319) + (int64_t)f152_tsize(ft_734))); }
 }
 } } _bk2293:; 
{ uint8_t *_t2321 = &(((*({ hrv *_t2322 = &(g557); int64_t _i2322 = si_708; (S10*)_t2322->b + hr_ix(_i2322, _t2322->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:168"); }))).cls_); *_t2321 = ((uint8_t)(cls_710)); }
{ bool *_t2323 = &(((*({ hrv *_t2324 = &(g557); int64_t _i2324 = si_708; (S10*)_t2324->b + hr_ix(_i2324, _t2324->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:168"); }))).flat_); *_t2323 = flat_711; }
{ int64_t *_t2325 = &(((*({ hrv *_t2326 = &(g557); int64_t _i2326 = si_708; (S10*)_t2326->b + hr_ix(_i2326, _t2326->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:169"); }))).size_); *_t2325 = ({ int64_t _r2327; if (((cls_710) == (((int64_t)0LL)))) { _r2327 = f103_max(off_709, ((int64_t)1LL));  } else { _r2327 = off_709;  } _r2327; }); }
{ bool *_t2329 = &(((*({ hrv *_t2330 = &(g557); int64_t _i2330 = si_708; (S10*)_t2330->b + hr_ix(_i2330, _t2330->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:170"); }))).zero_); *_t2329 = (((cls_710) == (((int64_t)0LL))) && ((off_709) == (((int64_t)0LL)))); }
{ uint8_t *_t2331 = &(((*({ hrv *_t2332 = &(g557); int64_t _i2332 = si_708; (S10*)_t2332->b + hr_ix(_i2332, _t2332->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:171"); }))).done_); *_t2331 = ((uint8_t)2LL); }
}
static bool f148_tflat(int64_t t_718) {
S1 x_719 = (*({ hrv *_t2333 = &(g554); int64_t _i2333 = t_718; (S1*)_t2333->b + hr_ix(_i2333, _t2333->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:118"); })); 
int64_t k_720 = ((int64_t)((x_719).k_)); 
if ((((k_720) == (((int64_t)10LL))) || ((k_720) == (((int64_t)9LL))))) { return false;
 }
if (((k_720) == (((int64_t)5LL)))) { (void)(f147_si_layout(((int64_t)((x_719).a_))));
return ((*({ hrv *_t2335 = &(g557); int64_t _i2335 = (x_719).a_; (S10*)_t2335->b + hr_ix(_i2335, _t2335->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:120"); }))).flat_;
 }
if ((((k_720) == (((int64_t)6LL))) || ((k_720) == (((int64_t)7LL))))) { (void)(f149_ei_layout(((int64_t)((x_719).a_))));
return ((*({ hrv *_t2337 = &(g559); int64_t _i2337 = (x_719).a_; (S8*)_t2337->b + hr_ix(_i2337, _t2337->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:121"); }))).flat_;
 }
if (((k_720) == (((int64_t)8LL)))) { return f148_tflat(((int64_t)((x_719).a_)));
 }
return true;
}
static void f149_ei_layout(int64_t ei_721) {
if (((((*({ hrv *_t2339 = &(g559); int64_t _i2339 = ei_721; (S8*)_t2339->b + hr_ix(_i2339, _t2339->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:174"); }))).done_) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t2340 = &(((*({ hrv *_t2341 = &(g559); int64_t _i2341 = ei_721; (S8*)_t2341->b + hr_ix(_i2341, _t2341->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:175"); }))).done_); *_t2340 = ((uint8_t)1LL); }
int64_t nv_722 = ((int64_t)(((*({ hrv *_t2342 = &(g559); int64_t _i2342 = ei_721; (S8*)_t2342->b + hr_ix(_i2342, _t2342->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:176"); }))).vnum_)); 
int64_t tz_723 = ({ int64_t _r2343; if (((nv_722) <= (((int64_t)256LL)))) { _r2343 = ((int64_t)1LL);  } else { _r2343 = ((int64_t)2LL);  } _r2343; }); 
{ uint8_t *_t2344 = &(((*({ hrv *_t2345 = &(g559); int64_t _i2345 = ei_721; (S8*)_t2345->b + hr_ix(_i2345, _t2345->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:178"); }))).tagsz_); *_t2344 = ((uint8_t)(tz_723)); }
int64_t mx_724 = ((int64_t)0LL); 
int64_t cls_725 = ((int64_t)0LL); 
bool flat_726 = true; 
{ int64_t _e2347 = nv_722; for (int64_t _k2347 = 0; _k2347 < _e2347; _k2347++) { int64_t i_727 = (int64_t)_k2347; int64_t v_728 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2348 = &(g559); int64_t _i2348 = ei_721; (S8*)_t2348->b + hr_ix(_i2348, _t2348->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:181"); }))).v0_)) + (int64_t)i_727)); 
if (((((*({ hrv *_t2349 = &(g560); int64_t _i2349 = v_728; (S9*)_t2349->b + hr_ix(_i2349, _t2349->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:182"); }))).si_) >= (((int32_t)0LL)))) { int64_t si_729 = ((int64_t)(((*({ hrv *_t2350 = &(g560); int64_t _i2350 = v_728; (S9*)_t2350->b + hr_ix(_i2350, _t2350->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:183"); }))).si_)); 
(void)(f147_si_layout(si_729));
if (((((int64_t)(((*({ hrv *_t2352 = &(g557); int64_t _i2352 = si_729; (S10*)_t2352->b + hr_ix(_i2352, _t2352->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:185"); }))).cls_))) > (cls_725))) { cls_725 = ((int64_t)(((*({ hrv *_t2353 = &(g557); int64_t _i2353 = si_729; (S10*)_t2353->b + hr_ix(_i2353, _t2353->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:185"); }))).cls_));
 }
if ((!(((*({ hrv *_t2354 = &(g557); int64_t _i2354 = si_729; (S10*)_t2354->b + hr_ix(_i2354, _t2354->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:186"); }))).flat_))) { flat_726 = false;
 }
int64_t ps_730 = ({ int64_t _r2355; if (((*({ hrv *_t2356 = &(g557); int64_t _i2356 = si_729; (S10*)_t2356->b + hr_ix(_i2356, _t2356->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:187"); }))).zero_) { _r2355 = ((int64_t)0LL);  } else { _r2355 = ((*({ hrv *_t2357 = &(g557); int64_t _i2357 = si_729; (S10*)_t2357->b + hr_ix(_i2357, _t2357->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:187"); }))).size_;  } _r2355; }); 
{ int64_t *_t2358 = &(((*({ hrv *_t2359 = &(g560); int64_t _i2359 = v_728; (S9*)_t2359->b + hr_ix(_i2359, _t2359->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:188"); }))).size_); *_t2358 = ps_730; }
if (((ps_730) > (mx_724))) { mx_724 = ps_730;
 }
 }
 } } _bk2346:; 
{ uint8_t *_t2360 = &(((*({ hrv *_t2361 = &(g559); int64_t _i2361 = ei_721; (S8*)_t2361->b + hr_ix(_i2361, _t2361->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:192"); }))).cls_); *_t2360 = ((uint8_t)(cls_725)); }
{ bool *_t2362 = &(((*({ hrv *_t2363 = &(g559); int64_t _i2363 = ei_721; (S8*)_t2363->b + hr_ix(_i2363, _t2363->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:192"); }))).flat_); *_t2362 = flat_726; }
{ int64_t *_t2364 = &(((*({ hrv *_t2365 = &(g559); int64_t _i2365 = ei_721; (S8*)_t2365->b + hr_ix(_i2365, _t2365->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:193"); }))).size_); *_t2364 = ((int64_t)((int64_t)((int64_t)(tz_723)) + (int64_t)mx_724)); }
{ uint8_t *_t2366 = &(((*({ hrv *_t2367 = &(g559); int64_t _i2367 = ei_721; (S8*)_t2367->b + hr_ix(_i2367, _t2367->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:194"); }))).done_); *_t2366 = ((uint8_t)2LL); }
}
static int64_t f150_pad_align(int64_t t_737) {
S1 x_738 = (*({ hrv *_t2368 = &(g554); int64_t _i2368 = t_737; (S1*)_t2368->b + hr_ix(_i2368, _t2368->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:96"); })); 
int64_t k_739 = ((int64_t)((x_738).k_)); 
if (((k_739) == (((int64_t)3LL)))) { return f151_isz(((int64_t)((x_738).s_)));
 }
if (((k_739) == (((int64_t)4LL)))) { return ((int64_t)((x_738).s_));
 }
if (((k_739) == (((int64_t)10LL)))) { if ((((x_738).c_) >= (((int32_t)0LL)))) { return ({ int64_t _r2370; if ((((x_738).c_) == (((int32_t)8LL)))) { _r2370 = ((int64_t)1LL);  } else { _r2370 = f151_isz(((int64_t)((x_738).c_)));  } _r2370; });
 }
return ((int64_t)8LL);
 }
if (((k_739) == (((int64_t)9LL)))) { return ((int64_t)8LL);
 }
return ((int64_t)1LL);
}
static int64_t f151_isz(int64_t s_740) {
return ((int64_t)((((int64_t)1LL)) << ((((int64_t)(((int64_t)((int64_t)s_740 & (int64_t)((int64_t)3LL)))))) & 63)));
}
static int64_t f152_tsize(int64_t t_743) {
S1 x_744 = (*({ hrv *_t2372 = &(g554); int64_t _i2372 = t_743; (S1*)_t2372->b + hr_ix(_i2372, _t2372->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:104"); })); 
int64_t k_745 = ((int64_t)((x_744).k_)); 
if (((k_745) == (((int64_t)2LL)))) { return ((int64_t)1LL);
 }
if (((k_745) == (((int64_t)3LL)))) { return f151_isz(((int64_t)((x_744).s_)));
 }
if (((k_745) == (((int64_t)4LL)))) { return ((int64_t)((x_744).s_));
 }
if (((k_745) == (((int64_t)10LL)))) { if ((((x_744).c_) >= (((int32_t)0LL)))) { return f151_isz(((int64_t)((x_744).c_)));
 }
return ((int64_t)8LL);
 }
if (((k_745) == (((int64_t)9LL)))) { return ((int64_t)16LL);
 }
if (((k_745) == (((int64_t)5LL)))) { (void)(f147_si_layout(((int64_t)((x_744).a_))));
return ((*({ hrv *_t2376 = &(g557); int64_t _i2376 = (x_744).a_; (S10*)_t2376->b + hr_ix(_i2376, _t2376->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:111"); }))).size_;
 }
if (((k_745) == (((int64_t)7LL)))) { (void)(f149_ei_layout(((int64_t)((x_744).a_))));
S9 v_746 = (*({ hrv *_t2378 = &(g560); int64_t _i2378 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2379 = &(g559); int64_t _i2379 = (x_744).a_; (S8*)_t2379->b + hr_ix(_i2379, _t2379->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:112"); }))).v0_)) + (int64_t)((int64_t)((x_744).c_)))); (S9*)_t2378->b + hr_ix(_i2378, _t2378->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:112"); })); 
return (v_746).size_;
 }
if (((k_745) == (((int64_t)6LL)))) { (void)(f149_ei_layout(((int64_t)((x_744).a_))));
return ((*({ hrv *_t2381 = &(g559); int64_t _i2381 = (x_744).a_; (S8*)_t2381->b + hr_ix(_i2381, _t2381->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:113"); }))).size_;
 }
if (((k_745) == (((int64_t)8LL)))) { int64_t a_747 = ((int64_t)((x_744).s_)); 
if (((a_747) == (((int64_t)1LL)))) { return ((int64_t)((int64_t)f103_max((x_744).b_, ((int64_t)1LL)) * (int64_t)f152_tsize(((int64_t)((x_744).a_)))));
 }
if (((a_747) == (((int64_t)3LL)))) { return ((int64_t)((int64_t)f151_isz(((int64_t)((x_744).c_))) + (int64_t)((int64_t)((int64_t)f103_max((x_744).b_, ((int64_t)1LL)) * (int64_t)f152_tsize(((int64_t)((x_744).a_)))))));
 }
 }
return ((int64_t)0LL);
}
static int64_t f153_cv(int64_t n_752) {
return ((int64_t)((*({ hrv *_t2387 = &(g398); int64_t _i2387 = f139_aix(n_752); (int32_t*)_t2387->b + hr_ix(_i2387, _t2387->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:49"); }))));
}
static bool f154_conv_ok(int64_t f_753, int64_t t_754, int64_t n_755) {
if (((f_753) == (t_754))) { return true;
 }
S1 a_756 = (*({ hrv *_t2389 = &(g554); int64_t _i2389 = f_753; (S1*)_t2389->b + hr_ix(_i2389, _t2389->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:178"); })); 
S1 b_757 = (*({ hrv *_t2390 = &(g554); int64_t _i2390 = t_754; (S1*)_t2390->b + hr_ix(_i2390, _t2390->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:178"); })); 
if (f155_widens(f_753, t_754)) { return true;
 }
if ((((((b_757).k_) == (((uint8_t)2LL))) && (((a_756).k_) == (((uint8_t)10LL)))) && ((((uint16_t)((uint64_t)(a_756).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { return true;
 }
if ((((((b_757).k_) == (((uint8_t)9LL))) && ((((a_756).k_) == (((uint8_t)8LL))) || (((a_756).k_) == (((uint8_t)9LL))))) && (((a_756).a_) == ((b_757).a_)))) { return true;
 }
if ((((((b_757).k_) == (((uint8_t)9LL))) && (((a_756).k_) == (((uint8_t)18LL)))) && ((((int64_t)((b_757).a_))) == (g567)))) { return true;
 }
if ((((((b_757).k_) == (((uint8_t)10LL))) && (((a_756).k_) == (((uint8_t)10LL)))) && (((((uint16_t)((uint64_t)(b_757).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))) || ((((uint16_t)((uint64_t)(a_756).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))))) { if ((((a_756).a_) == ((b_757).a_))) { return true;
 }
if (((((((*({ hrv *_t2392 = &(g554); int64_t _i2392 = (b_757).a_; (S1*)_t2392->b + hr_ix(_i2392, _t2392->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:185"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t2393 = &(g554); int64_t _i2393 = (a_756).a_; (S1*)_t2393->b + hr_ix(_i2393, _t2393->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:185"); }))).k_) == (((uint8_t)7LL)))) && ((((*({ hrv *_t2394 = &(g554); int64_t _i2394 = (a_756).a_; (S1*)_t2394->b + hr_ix(_i2394, _t2394->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:185"); }))).a_) == (((*({ hrv *_t2395 = &(g554); int64_t _i2395 = (b_757).a_; (S1*)_t2395->b + hr_ix(_i2395, _t2395->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:185"); }))).a_)))) { return true;
 }
if (((((((*({ hrv *_t2396 = &(g554); int64_t _i2396 = (b_757).a_; (S1*)_t2396->b + hr_ix(_i2396, _t2396->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:186"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t2397 = &(g554); int64_t _i2397 = (a_756).a_; (S1*)_t2397->b + hr_ix(_i2397, _t2397->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:186"); }))).k_) == (((uint8_t)6LL)))) && ((((*({ hrv *_t2398 = &(g554); int64_t _i2398 = (a_756).a_; (S1*)_t2398->b + hr_ix(_i2398, _t2398->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:186"); }))).a_) == (((*({ hrv *_t2399 = &(g554); int64_t _i2399 = (b_757).a_; (S1*)_t2399->b + hr_ix(_i2399, _t2399->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:186"); }))).a_)))) { return true;
 }
 }
if (((((b_757).k_) == (((uint8_t)10LL))) && ((((int64_t)((b_757).a_))) == (f_753)))) { return true;
 }
if ((((((b_757).k_) == (((uint8_t)6LL))) && (((a_756).k_) == (((uint8_t)7LL)))) && (((a_756).a_) == ((b_757).a_)))) { return true;
 }
if ((((((b_757).k_) == (((uint8_t)6LL))) && (((a_756).k_) == (((uint8_t)6LL)))) && (((a_756).a_) == ((b_757).a_)))) { return true;
 }
if ((((((b_757).k_) == (((uint8_t)8LL))) && (((a_756).k_) == (((uint8_t)8LL)))) && (((a_756).a_) == ((b_757).a_)))) { return true;
 }
if ((((((b_757).k_) == (((uint8_t)8LL))) && (((a_756).k_) == (((uint8_t)9LL)))) && (((a_756).a_) == ((b_757).a_)))) { return true;
 }
return false;
}
static bool f155_widens(int64_t f_758, int64_t t_759) {
if (((f_758) == (t_759))) { return true;
 }
S1 a_760 = (*({ hrv *_t2400 = &(g554); int64_t _i2400 = f_758; (S1*)_t2400->b + hr_ix(_i2400, _t2400->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:115"); })); 
S1 b_761 = (*({ hrv *_t2401 = &(g554); int64_t _i2401 = t_759; (S1*)_t2401->b + hr_ix(_i2401, _t2401->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:115"); })); 
if (((((a_760).k_) == (((uint8_t)3LL))) && (((b_761).k_) == (((uint8_t)3LL))))) { bool fs_763 = f156_is_signed(f_758); 
bool ts_764 = f156_is_signed(t_759); 
if (((fs_763) == (ts_764))) { return ((f157_ibits(t_759)) > (f157_ibits(f_758)));
 }
return (((!(fs_763)) && ts_764) && ((f157_ibits(t_759)) > (f157_ibits(f_758))));
 }
if (((((a_760).k_) == (((uint8_t)3LL))) && (((b_761).k_) == (((uint8_t)4LL))))) { return true;
 }
if (((((a_760).k_) == (((uint8_t)4LL))) && (((b_761).k_) == (((uint8_t)4LL))))) { return (((b_761).s_) > ((a_760).s_));
 }
if (((((a_760).k_) == (((uint8_t)3LL))) && (((b_761).k_) == (((uint8_t)17LL))))) { return (!((((f157_ibits(f_758)) == (((int64_t)64LL))) && (!(f156_is_signed(f_758))))));
 }
if (((((a_760).k_) == (((uint8_t)17LL))) && (((b_761).k_) == (((uint8_t)3LL))))) { return ((t_759) == (g566));
 }
return false;
}
static bool f156_is_signed(int64_t t_762) {
return ((((*({ hrv *_t2410 = &(g554); int64_t _i2410 = t_762; (S1*)_t2410->b + hr_ix(_i2410, _t2410->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:60"); }))).s_) < (((uint8_t)4LL)));
}
static int64_t f157_ibits(int64_t t_765) {
return ((int64_t)((((int64_t)8LL)) << ((((int64_t)(((uint8_t)((uint64_t)((*({ hrv *_t2411 = &(g554); int64_t _i2411 = t_765; (S1*)_t2411->b + hr_ix(_i2411, _t2411->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:61"); }))).s_ & (uint64_t)((uint8_t)3LL)))))) & 63)));
}
static M78 f158_cval(int64_t n_766) {
if (((n_766) < (((int64_t)0LL)))) { return (M78){ ((int64_t)0LL), false, false };
 }
S4 x_767 = (*({ hrv *_t2412 = &(g707); int64_t _i2412 = n_766; (S4*)_t2412->b + hr_ix(_i2412, _t2412->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:125"); })); 
int64_t k_768 = ((int64_t)((x_767).k_)); 
if (((k_768) == (((int64_t)1LL)))) { return (M78){ ((*({ hrv *_t2413 = &(g917); int64_t _i2413 = (x_767).t_; (S3*)_t2413->b + hr_ix(_i2413, _t2413->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:126"); }))).v_, ((*({ hrv *_t2414 = &(g917); int64_t _i2414 = (x_767).t_; (S3*)_t2414->b + hr_ix(_i2414, _t2414->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:126"); }))).uns_, true };
 }
if (((k_768) == (((int64_t)10LL)))) { M78 _t2415 = f158_cval(((int64_t)((x_767).a_))); int64_t v_769 = _t2415.r0; bool u_770 = _t2415.r1; bool ok_771 = _t2415.r2; 
if ((!(ok_771))) { return (M78){ ((int64_t)0LL), false, false };
 }
if (((((int64_t)((x_767).op_))) == (((int64_t)22LL)))) { return (M78){ ((int64_t)(0 - (uint64_t)(v_769))), false, true };
 }
if (((((int64_t)((x_767).op_))) == (((int64_t)48LL)))) { return (M78){ ((int64_t)~(v_769)), false, true };
 }
return (M78){ ((int64_t)0LL), false, false };
 }
if ((((k_768) == (((int64_t)8LL))) && ((f159_rk(n_766)) == (((int64_t)6LL))))) { return (M78){ (*({ hrv *_t2418 = &(g438); int64_t _i2418 = f160_rv(n_766); (int64_t*)_t2418->b + hr_ix(_i2418, _t2418->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:128"); })), false, true };
 }
if (((k_768) == (((int64_t)9LL)))) { M78 _t2420 = f158_cval(((int64_t)((x_767).a_))); int64_t a_774 = _t2420.r0; bool ua_775 = _t2420.r1; bool oa_776 = _t2420.r2; 
M78 _t2422 = f158_cval(((int64_t)((x_767).b_))); int64_t b_777 = _t2422.r0; bool ub_778 = _t2422.r1; bool ob_779 = _t2422.r2; 
if (((!(oa_776)) || (!(ob_779)))) { return (M78){ ((int64_t)0LL), false, false };
 }
int64_t o_780 = ((int64_t)((x_767).op_)); 
if (((o_780) == (((int64_t)21LL)))) { return (M78){ ((int64_t)((int64_t)a_774 + (int64_t)b_777)), false, true };
 }
if (((o_780) == (((int64_t)22LL)))) { return (M78){ ((int64_t)((int64_t)a_774 - (int64_t)b_777)), false, true };
 }
if (((o_780) == (((int64_t)23LL)))) { return (M78){ ((int64_t)((int64_t)a_774 * (int64_t)b_777)), false, true };
 }
if (((o_780) == (((int64_t)24LL)))) { if (((b_777) == (((int64_t)0LL)))) { return (M78){ ((int64_t)0LL), false, false };
 }
return (M78){ HR_SDIV(int64_t, a_774, b_777, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:134"), false, true };
 }
if (((o_780) == (((int64_t)25LL)))) { if (((b_777) == (((int64_t)0LL)))) { return (M78){ ((int64_t)0LL), false, false };
 }
return (M78){ HR_SMOD(int64_t, ((int64_t)((int64_t)HR_SMOD(int64_t, a_774, b_777, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:135") + (int64_t)b_777)), b_777, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:135"), false, true };
 }
if (((o_780) == (((int64_t)43LL)))) { return (M78){ ((int64_t)((a_774) << ((b_777) & 63))), false, true };
 }
if (((o_780) == (((int64_t)44LL)))) { return (M78){ ((int64_t)((a_774) >> ((b_777) & 63))), false, true };
 }
if (((o_780) == (((int64_t)49LL)))) { return (M78){ ((int64_t)((int64_t)a_774 & (int64_t)b_777)), false, true };
 }
if (((o_780) == (((int64_t)50LL)))) { return (M78){ ((int64_t)((int64_t)a_774 | (int64_t)b_777)), false, true };
 }
if (((o_780) == (((int64_t)51LL)))) { return (M78){ ((int64_t)((int64_t)a_774 ^ (int64_t)b_777)), false, true };
 }
 }
if ((((k_768) == (((int64_t)19LL))) || ((k_768) == (((int64_t)23LL))))) { return (M78){ ((int64_t)0LL), false, false };
 }
return (M78){ ((int64_t)0LL), false, false };
}
static int64_t f159_rk(int64_t n_772) {
return ((int64_t)((*({ hrv *_t2424 = &(g399); int64_t _i2424 = f139_aix(n_772); (uint8_t*)_t2424->b + hr_ix(_i2424, _t2424->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:44"); }))));
}
static int64_t f160_rv(int64_t n_773) {
return ((int64_t)((*({ hrv *_t2426 = &(g400); int64_t _i2426 = f139_aix(n_773); (int32_t*)_t2426->b + hr_ix(_i2426, _t2426->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:45"); }))));
}
static bool f161_int_fits(int64_t v_784, bool uns_785, int64_t t_786) {
if (((((*({ hrv *_t2428 = &(g554); int64_t _i2428 = t_786; (S1*)_t2428->b + hr_ix(_i2428, _t2428->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:108"); }))).k_) != (((uint8_t)3LL)))) { return false;
 }
if (uns_785) { return ((!(f156_is_signed(t_786))) && ((f157_ibits(t_786)) == (((int64_t)64LL))));
 }
if (((v_784) < (((int64_t)0LL)))) { return (f156_is_signed(t_786) && ((v_784) >= (f162_int_min(t_786))));
 }
return ((((uint64_t)(v_784))) <= (f163_int_max_u(t_786)));
}
static int64_t f162_int_min(int64_t t_787) {
if ((!(f156_is_signed(t_787)))) { return ((int64_t)0LL);
 }
int64_t b_788 = f157_ibits(t_787); 
return ({ int64_t _r2436; if (((b_788) == (((int64_t)64LL)))) { _r2436 = ((int64_t)((int64_t)((int64_t)(0 - (uint64_t)(((int64_t)9223372036854775807LL)))) - (int64_t)((int64_t)1LL)));  } else { _r2436 = ((int64_t)(0 - (uint64_t)(((int64_t)((((int64_t)1LL)) << ((((int64_t)((int64_t)b_788 - (int64_t)((int64_t)1LL)))) & 63))))));  } _r2436; });
}
static uint64_t f163_int_max_u(int64_t t_789) {
int64_t b_790 = f157_ibits(t_789); 
bool sg_791 = f156_is_signed(t_789); 
return ({ uint64_t _r2439; if (((b_790) == (((int64_t)64LL)))) { _r2439 = ({ uint64_t _r2440; if (sg_791) { _r2440 = ((uint64_t)9223372036854775807LL);  } else { _r2440 = ((uint64_t)18446744073709551615ULL);  } _r2440; });  } else { _r2439 = ({ uint64_t _r2441; if (sg_791) { _r2441 = ((uint64_t)((uint64_t)((uint64_t)((((uint64_t)1LL)) << ((((int64_t)((int64_t)b_790 - (int64_t)((int64_t)1LL)))) & 63))) - (uint64_t)((uint64_t)1LL)));  } else { _r2441 = ((uint64_t)((uint64_t)((uint64_t)((((uint64_t)1LL)) << ((b_790) & 63))) - (uint64_t)((uint64_t)1LL)));  } _r2441; });  } _r2439; });
}
static hrv f164_tn(int64_t t_793) {
return f126_ty_name(t_793);
}
static void f165_commit(int64_t n_794, int64_t t_795) {
if (((n_794) < (((int64_t)0LL)))) { return;
 }
S4 x_796 = (*({ hrv *_t2443 = &(g707); int64_t _i2443 = n_794; (S4*)_t2443->b + hr_ix(_i2443, _t2443->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:198"); })); 
int64_t k_797 = ((int64_t)((x_796).k_)); 
int64_t f_798 = f141_at(n_794); 
if ((((f_798) >= (((int64_t)0LL))) && (!(f166_is_pending(f_798))))) { if ((((f_798) != (t_795)) && f154_conv_ok(f_798, t_795, n_794))) { (void)(f145_set_cv(n_794, t_795));
 }
return;
 }
(void)(f138_set_t(n_794, t_795));
if (((k_797) == (((int64_t)10LL)))) { (void)(f165_commit(((int64_t)((x_796).a_)), t_795));
return;
 }
if (((k_797) == (((int64_t)9LL)))) { int64_t o_801 = ((int64_t)((x_796).op_)); 
if ((((o_801) == (((int64_t)43LL))) || ((o_801) == (((int64_t)44LL))))) { (void)(f165_commit(((int64_t)((x_796).a_)), t_795));
return;
 }
if (((f92_binprec(o_801)) >= (((int64_t)5LL)))) { (void)(f165_commit(((int64_t)((x_796).a_)), t_795));
(void)(f165_commit(((int64_t)((x_796).b_)), t_795));
 }
return;
 }
if (((k_797) == (((int64_t)19LL)))) { (void)(f165_commit(((int64_t)((x_796).b_)), t_795));
if ((((x_796).c_) >= (((int32_t)0LL)))) { (void)(f165_commit(((int64_t)((x_796).c_)), t_795));
 }
return;
 }
if (((k_797) == (((int64_t)23LL)))) { if ((((x_796).a_) >= (((int32_t)0LL)))) { (void)(f165_commit(((int64_t)((x_796).a_)), t_795));
 }
return;
 }
if (((k_797) == (((int64_t)24LL)))) { (void)(f165_commit(((int64_t)((x_796).a_)), t_795));
return;
 }
if (((k_797) == (((int64_t)20LL)))) { { int32_t _e2459 = (x_796).n_; for (int32_t _k2459 = 0; _k2459 < _e2459; _k2459++) { int32_t i_802 = (int32_t)_k2459; (void)(f165_commit(((int64_t)(((*({ hrv *_t2461 = &(g707); int64_t _i2461 = f90_kid(n_794, ((int64_t)(i_802))); (S4*)_t2461->b + hr_ix(_i2461, _t2461->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:212"); }))).b_)), t_795));
 } } _bk2458:; 
return;
 }
if (((k_797) == (((int64_t)16LL)))) { int64_t e_803 = ({ int64_t _r2463; if ((((((*({ hrv *_t2464 = &(g554); int64_t _i2464 = t_795; (S1*)_t2464->b + hr_ix(_i2464, _t2464->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:214"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2465 = &(g554); int64_t _i2465 = t_795; (S1*)_t2465->b + hr_ix(_i2465, _t2465->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:214"); }))).k_) == (((uint8_t)9LL))))) { _r2463 = ((int64_t)(((*({ hrv *_t2466 = &(g554); int64_t _i2466 = t_795; (S1*)_t2466->b + hr_ix(_i2466, _t2466->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:214"); }))).a_));  } else { _r2463 = g578;  } _r2463; }); 
if ((((x_796).a_) >= (((int32_t)0LL)))) { (void)(f140_conv(((int64_t)((x_796).a_)), e_803));
(void)(f140_conv(((int64_t)((x_796).b_)), g566));
 }
{ int32_t _e2470 = (x_796).n_; for (int32_t _k2470 = 0; _k2470 < _e2470; _k2470++) { int32_t i_804 = (int32_t)_k2470; (void)(f140_conv(f90_kid(n_794, ((int64_t)(i_804))), e_803));
 } } _bk2469:; 
if (((((*({ hrv *_t2473 = &(g554); int64_t _i2473 = t_795; (S1*)_t2473->b + hr_ix(_i2473, _t2473->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:217"); }))).k_) == (((uint8_t)9LL)))) { (void)(f138_set_t(n_794, f123_t_arr(e_803, ((int64_t)1LL), f103_max(((int64_t)((x_796).n_)), ((int64_t)1LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f145_set_cv(n_794, t_795));
 }
return;
 }
}
static bool f166_is_pending(int64_t t_799) {
int64_t k_800 = ((int64_t)(((*({ hrv *_t2478 = &(g554); int64_t _i2478 = t_799; (S1*)_t2478->b + hr_ix(_i2478, _t2478->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:106"); }))).k_)); 
return ((((((k_800) == (((int64_t)12LL))) || ((k_800) == (((int64_t)13LL)))) || ((k_800) == (((int64_t)18LL)))) || ((k_800) == (((int64_t)19LL)))) || ((k_800) == (((int64_t)11LL))));
}
static bool f167_is_byte_arr(int64_t t_805) {
uint8_t k_806 = ((*({ hrv *_t2479 = &(g554); int64_t _i2479 = t_805; (S1*)_t2479->b + hr_ix(_i2479, _t2479->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:68"); }))).k_; 
return ((((k_806) == (((uint8_t)8LL))) || ((k_806) == (((uint8_t)9LL)))) && ((((int64_t)(((*({ hrv *_t2480 = &(g554); int64_t _i2480 = t_805; (S1*)_t2480->b + hr_ix(_i2480, _t2480->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:68"); }))).a_))) == (g567)));
}
static bool f168_is_opt(int64_t t_808) {
return (((((*({ hrv *_t2481 = &(g554); int64_t _i2481 = t_808; (S1*)_t2481->b + hr_ix(_i2481, _t2481->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:66"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2482 = &(g554); int64_t _i2482 = t_808; (S1*)_t2482->b + hr_ix(_i2482, _t2482->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:66"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))));
}
static int64_t f169_ck_id(int64_t n_809, int64_t want_810) {
int64_t name_811 = ((int64_t)(((*({ hrv *_t2483 = &(g707); int64_t _i2483 = n_809; (S4*)_t2483->b + hr_ix(_i2483, _t2483->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:348"); }))).s_)); 
int64_t v_819 = f170_find_lv(name_811); 
if (((v_819) >= (((int64_t)0LL)))) { (void)(f173_set_r(n_809, ((int64_t)1LL), v_819));
(void)(f174_note_cap(v_819));
return f138_set_t(n_809, ({ int64_t _r2488; if (((((uint16_t)((uint64_t)((*({ hrv *_t2489 = &(g391); int64_t _i2489 = v_819; (S12*)_t2489->b + hr_ix(_i2489, _t2489->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:350"); }))).fl_ & (uint64_t)((uint16_t)64LL)))) != (((uint16_t)0LL)))) { _r2488 = g575;  } else { _r2488 = ((int64_t)(((*({ hrv *_t2490 = &(g391); int64_t _i2490 = v_819; (S12*)_t2490->b + hr_ix(_i2490, _t2490->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:350"); }))).ty_));  } _r2488; }));
 }
int64_t ns_830 = f110_ns_of(n_809); 
int64_t d_831 = f116_lookup_q(name_811, ns_830, ((int64_t)5LL)); 
if (((d_831) >= (((int64_t)0LL)))) { int64_t g_832 = ((int64_t)(((*({ hrv *_t2493 = &(g492); int64_t _i2493 = d_831; (S5*)_t2493->b + hr_ix(_i2493, _t2493->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:354"); }))).node_)); 
int64_t ci_845 = f176_const_of(d_831); 
if (((ci_845) >= (((int64_t)0LL)))) { (void)(f173_set_r(n_809, ((int64_t)6LL), ci_845));
return f138_set_t(n_809, g574);
 }
(void)(f173_set_r(n_809, ((int64_t)2LL), d_831));
return f138_set_t(n_809, f109_global_type(d_831));
 }
d_831 = f116_lookup_q(name_811, ns_830, ((int64_t)4LL));
if (((d_831) >= (((int64_t)0LL)))) { (void)(f173_set_r(n_809, ((int64_t)3LL), d_831));
(void)(f178_set_x(n_809, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_809, g581);
 }
hrv m_848 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o2505 = &(m_848); hr_fs(_o2505, hr_str("unknown name: ", 14)); hr_fs(_o2505, f10_nm(name_811)); }));
(void)(f108_cerr(n_809, hr_sl(m_848)));
return f138_set_t(n_809, g578);
}
static int64_t f170_find_lv(int64_t name_812) {
int64_t i_813 = ((int64_t)((int64_t)(g392).n - (int64_t)((int64_t)1LL))); 
while (((i_813) >= (((int64_t)0LL)))) { int64_t v_814 = ((int64_t)((*({ hrv *_t2510 = &(g392); int64_t _i2510 = i_813; (int32_t*)_t2510->b + hr_ix(_i2510, _t2510->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:60"); })))); 
if ((((((int64_t)(((*({ hrv *_t2511 = &(g391); int64_t _i2511 = v_814; (S12*)_t2511->b + hr_ix(_i2511, _t2511->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:60"); }))).name_))) == (name_812)) && f171_visible(((int64_t)(((*({ hrv *_t2513 = &(g391); int64_t _i2513 = v_814; (S12*)_t2513->b + hr_ix(_i2513, _t2513->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:60"); }))).own_))))) { return v_814;
 }
i_813--;
 } _bk2509:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f171_visible(int64_t own_815) {
return f172_visible_in(own_815, g403);
}
static bool f172_visible_in(int64_t own_816, int64_t cur_817) {
int64_t i_818 = cur_817; 
while (((i_818) >= (((int64_t)0LL)))) { if (((i_818) == (own_816))) { return true;
 }
i_818 = ((int64_t)(((*({ hrv *_t2516 = &(g390); int64_t _i2516 = i_818; (S6*)_t2516->b + hr_ix(_i2516, _t2516->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:56"); }))).par_));
 } _bk2515:; 
return false;
}
static void f173_set_r(int64_t n_820, int64_t k_821, int64_t v_822) {
int64_t i_823 = f139_aix(n_820); 
{ uint8_t *_t2518 = &((*({ hrv *_t2519 = &(g399); int64_t _i2519 = i_823; (uint8_t*)_t2519->b + hr_ix(_i2519, _t2519->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:43"); }))); *_t2518 = ((uint8_t)(k_821)); }
{ int32_t *_t2520 = &((*({ hrv *_t2521 = &(g400); int64_t _i2521 = i_823; (int32_t*)_t2521->b + hr_ix(_i2521, _t2521->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:43"); }))); *_t2520 = ((int32_t)(v_822)); }
}
static void f174_note_cap(int64_t v_824) {
int64_t own_825 = ((int64_t)(((*({ hrv *_t2522 = &(g391); int64_t _i2522 = v_824; (S12*)_t2522->b + hr_ix(_i2522, _t2522->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:70"); }))).own_)); 
int64_t a_826 = g403; 
while ((((a_826) >= (((int64_t)0LL))) && ((a_826) != (own_825)))) { (void)(f175_add_cap_one(((int64_t)(((*({ hrv *_t2525 = &(g390); int64_t _i2525 = a_826; (S6*)_t2525->b + hr_ix(_i2525, _t2525->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:73"); }))).cfn_)), v_824));
a_826 = ((int64_t)(((*({ hrv *_t2526 = &(g390); int64_t _i2526 = a_826; (S6*)_t2526->b + hr_ix(_i2526, _t2526->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:74"); }))).par_));
 } _bk2523:; 
}
static bool f175_add_cap_one(int64_t cf_827, int64_t v_828) {
if ((((cf_827) < (((int64_t)0LL))) || ((cf_827) == (((int64_t)(((*({ hrv *_t2527 = &(g391); int64_t _i2527 = v_828; (S12*)_t2527->b + hr_ix(_i2527, _t2527->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:64"); }))).cfn_)))))) { return false;
 }
{ hrv *_v2529 = &(g394); for (int64_t _k2529 = 0; _k2529 < _v2529->n; _k2529++) { S13 x_829 = ((S13*)_v2529->b)[_k2529]; if ((((((int64_t)((x_829).inst_))) == (cf_827)) && ((((int64_t)((x_829).lv_))) == (v_828)))) { return false;
 }
 } } _bk2528:; 
(void)(({ hrv *_v2530 = &(g394); S13 _x2530 = ((S13){ .inst_ = ((int32_t)(cf_827)), .lv_ = ((int32_t)(v_828)), }); S13 *_p2530 = (S13*)hr_grow(_v2530, 1, sizeof _x2530); *_p2530 = _x2530; _p2530; }));
return true;
}
static int64_t f176_const_of(int64_t d_833) {
{ hrv *_v2532 = &(g439); for (int64_t _k2532 = 0; _k2532 < _v2532->n; _k2532++) { int32_t c_834 = ((int32_t*)_v2532->b)[_k2532]; int64_t i_835 = (int64_t)_k2532; if (((((int64_t)(c_834))) == (d_833))) { return i_835;
 }
 } } _bk2531:; 
int64_t g_836 = ((int64_t)(((*({ hrv *_t2533 = &(g492); int64_t _i2533 = d_833; (S5*)_t2533->b + hr_ix(_i2533, _t2533->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:369"); }))).node_)); 
S4 x_837 = (*({ hrv *_t2534 = &(g707); int64_t _i2534 = g_836; (S4*)_t2534->b + hr_ix(_i2534, _t2534->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:370"); })); 
if (((((((uint16_t)((uint64_t)(x_837).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || (((x_837).a_) >= (((int32_t)0LL)))) || (((x_837).b_) < (((int32_t)0LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t iv_838 = f90_kid(((int64_t)((x_837).b_)), ((int64_t)0LL)); 
M56 _t2536 = f120_ceval(iv_838, f110_ns_of(g_836)); int64_t v_839 = _t2536.r0; bool ok_840 = _t2536.r1; 
if ((!(ok_840))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if ((!(f177_all_int(iv_838)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
(void)(({ hrv *_v2540 = &(g439); int32_t _x2540 = ((int32_t)(d_833)); int32_t *_p2540 = (int32_t*)hr_grow(_v2540, 1, sizeof _x2540); *_p2540 = _x2540; _p2540; }));
(void)(({ hrv *_v2541 = &(g438); int64_t _x2541 = v_839; int64_t *_p2541 = (int64_t*)hr_grow(_v2541, 1, sizeof _x2541); *_p2541 = _x2541; _p2541; }));
return ((int64_t)((int64_t)(g439).n - (int64_t)((int64_t)1LL)));
}
static bool f177_all_int(int64_t n_841) {
S4 x_842 = (*({ hrv *_t2542 = &(g707); int64_t _i2542 = n_841; (S4*)_t2542->b + hr_ix(_i2542, _t2542->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:380"); })); 
int64_t k_843 = ((int64_t)((x_842).k_)); 
if (((k_843) == (((int64_t)1LL)))) { return true;
 }
if (((k_843) == (((int64_t)10LL)))) { return f177_all_int(((int64_t)((x_842).a_)));
 }
if (((k_843) == (((int64_t)9LL)))) { return (f177_all_int(((int64_t)((x_842).a_))) && f177_all_int(((int64_t)((x_842).b_))));
 }
if (((k_843) == (((int64_t)8LL)))) { int64_t d_844 = f116_lookup_q(((int64_t)((x_842).s_)), f110_ns_of(n_841), ((int64_t)5LL)); 
if (((d_844) < (((int64_t)0LL)))) { return false;
 }
return ((f176_const_of(d_844)) >= (((int64_t)0LL)));
 }
if (((k_843) == (((int64_t)14LL)))) { return hr_streq(f10_nm(((int64_t)((x_842).s_))), hr_str("len", 3));
 }
return false;
}
static void f178_set_x(int64_t n_846, int64_t v_847) {
{ int32_t *_t2550 = &((*({ hrv *_t2551 = &(g401); int64_t _i2551 = f139_aix(n_846); (int32_t*)_t2551->b + hr_ix(_i2551, _t2551->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:46"); }))); *_t2550 = ((int32_t)(v_847)); }
}
static int64_t f179_ck_bin(int64_t n_849, int64_t want_850) {
S4 x_851 = (*({ hrv *_t2553 = &(g707); int64_t _i2553 = n_849; (S4*)_t2553->b + hr_ix(_i2553, _t2553->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:284"); })); 
int64_t o_852 = ((int64_t)((x_851).op_)); 
int64_t a_853 = ((int64_t)((x_851).a_)); 
int64_t b_854 = ((int64_t)((x_851).b_)); 
if (((o_852) == (((int64_t)52LL)))) { (void)(f137_ck(a_853, g562));
(void)(f140_conv(a_853, g562));
int64_t nm0_855 = (g393).n; 
(void)(f180_narrow_push(a_853));
(void)(f137_ck(b_854, g562));
(void)(f140_conv(b_854, g562));
(void)(f181_narrow_pop(nm0_855));
return f138_set_t(n_849, g562);
 }
if (((o_852) == (((int64_t)53LL)))) { (void)(f137_ck(a_853, g562));
(void)(f140_conv(a_853, g562));
(void)(f137_ck(b_854, g562));
(void)(f140_conv(b_854, g562));
return f138_set_t(n_849, g562);
 }
if ((((o_852) == (((int64_t)19LL))) || ((o_852) == (((int64_t)20LL))))) { (void)(f137_ck(a_853, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
(void)(f137_ck(b_854, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_849, g562);
 }
bool cmp_864 = (((((((o_852) == (((int64_t)37LL))) || ((o_852) == (((int64_t)38LL)))) || ((o_852) == (((int64_t)39LL)))) || ((o_852) == (((int64_t)40LL)))) || ((o_852) == (((int64_t)41LL)))) || ((o_852) == (((int64_t)42LL)))); 
int64_t w_865 = ({ int64_t _r2569; if (cmp_864) { _r2569 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2569 = want_850;  } _r2569; }); 
int64_t ta_866 = f137_ck(a_853, ({ int64_t _r2571; if (((((int64_t)(((*({ hrv *_t2572 = &(g707); int64_t _i2572 = a_853; (S4*)_t2572->b + hr_ix(_i2572, _t2572->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:297"); }))).k_))) == (((int64_t)1LL)))) { _r2571 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2571 = w_865;  } _r2571; })); 
bool sh_867 = (((o_852) == (((int64_t)43LL))) || ((o_852) == (((int64_t)44LL)))); 
int64_t tb_869 = f137_ck(b_854, ({ int64_t _r2574; if (sh_867) { _r2574 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2574 = ({ int64_t _r2575; if (f166_is_pending(ta_866)) { _r2575 = w_865;  } else { _r2575 = f182_deref(ta_866);  } _r2575; });  } _r2574; })); 
if (sh_867) { if (((((*({ hrv *_t2578 = &(g554); int64_t _i2578 = tb_869; (S1*)_t2578->b + hr_ix(_i2578, _t2578->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:301"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(b_854, g566));
 } else { if (((((*({ hrv *_t2580 = &(g554); int64_t _i2580 = f182_deref(tb_869); (S1*)_t2580->b + hr_ix(_i2580, _t2580->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:301"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(b_854, hr_str("shift count must be an integer", 30)));
 }
 }
int64_t da_870 = f182_deref(ta_866); 
if (((((*({ hrv *_t2584 = &(g554); int64_t _i2584 = da_870; (S1*)_t2584->b + hr_ix(_i2584, _t2584->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:303"); }))).k_) == (((uint8_t)12LL)))) { if ((((want_850) >= (((int64_t)0LL))) && ((((*({ hrv *_t2585 = &(g554); int64_t _i2585 = want_850; (S1*)_t2585->b + hr_ix(_i2585, _t2585->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:303"); }))).k_) == (((uint8_t)3LL))))) { (void)(f140_conv(a_853, want_850));
return f138_set_t(n_849, want_850);
 }
return f138_set_t(n_849, g574);
 }
if (((((*({ hrv *_t2589 = &(g554); int64_t _i2589 = da_870; (S1*)_t2589->b + hr_ix(_i2589, _t2589->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:304"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(a_853, hr_str("shift of a non-integer", 22)));
 }
if (((ta_866) != (da_870))) { (void)(f145_set_cv(a_853, da_870));
 }
return f138_set_t(n_849, da_870);
 }
int64_t da_871 = f182_deref(ta_866); 
int64_t db_872 = f182_deref(tb_869); 
int64_t la_881 = f183_leaf_kind(da_871); 
int64_t lb_882 = f183_leaf_kind(db_872); 
if (((((la_881) >= (((int64_t)4LL))) || ((lb_882) >= (((int64_t)4LL)))) && (!(cmp_864)))) { if (((da_871) == (db_872))) { if (((ta_866) != (da_871))) { (void)(f145_set_cv(a_853, da_871));
 }
if (((tb_869) != (db_872))) { (void)(f145_set_cv(b_854, db_872));
 }
return f138_set_t(n_849, da_871);
 }
if ((((la_881) >= (((int64_t)4LL))) && (((o_852) == (((int64_t)23LL))) || ((o_852) == (((int64_t)24LL)))))) { (void)(f140_conv(b_854, f184_leaf_type(da_871)));
if (((ta_866) != (da_871))) { (void)(f145_set_cv(a_853, da_871));
 }
return f138_set_t(n_849, da_871);
 }
if ((((lb_882) >= (((int64_t)4LL))) && ((o_852) == (((int64_t)23LL))))) { (void)(f140_conv(a_853, f184_leaf_type(db_872)));
if (((tb_869) != (db_872))) { (void)(f145_set_cv(b_854, db_872));
 }
return f138_set_t(n_849, db_872);
 }
if ((((lb_882) >= (((int64_t)4LL))) && ((o_852) == (((int64_t)24LL))))) { (void)(f140_conv(a_853, f184_leaf_type(db_872)));
if (((tb_869) != (db_872))) { (void)(f145_set_cv(b_854, db_872));
 }
return f138_set_t(n_849, db_872);
 }
 }
if ((((((cmp_864 && (((((*({ hrv *_t2612 = &(g554); int64_t _i2612 = da_871; (S1*)_t2612->b + hr_ix(_i2612, _t2612->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:316"); }))).k_) == (((uint8_t)3LL))) && ((((*({ hrv *_t2613 = &(g554); int64_t _i2613 = db_872; (S1*)_t2613->b + hr_ix(_i2613, _t2613->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:316"); }))).k_) == (((uint8_t)3LL))))) && ((f156_is_signed(da_871)) != (f156_is_signed(db_872)))) && (((f157_ibits(da_871)) == (((int64_t)64LL))) || ((f157_ibits(db_872)) == (((int64_t)64LL))))) && (!(f155_widens(da_871, db_872)))) && (!(f155_widens(db_872, da_871))))) { (void)(f178_set_x(n_849, ((int64_t)1LL)));
return f138_set_t(n_849, g562);
 }
if ((cmp_864 && (((o_852) == (((int64_t)37LL))) || ((o_852) == (((int64_t)38LL)))))) { int64_t ka_890 = ((int64_t)(((*({ hrv *_t2622 = &(g554); int64_t _i2622 = da_871; (S1*)_t2622->b + hr_ix(_i2622, _t2622->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:321"); }))).k_)); 
int64_t kb_891 = ((int64_t)(((*({ hrv *_t2623 = &(g554); int64_t _i2623 = db_872; (S1*)_t2623->b + hr_ix(_i2623, _t2623->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:321"); }))).k_)); 
if ((((ka_890) == (((int64_t)11LL))) || ((kb_891) == (((int64_t)11LL))))) { if ((((ka_890) == (((int64_t)11LL))) && ((kb_891) == (((int64_t)11LL))))) { return f138_set_t(n_849, g562);
 }
if (((ka_890) == (((int64_t)11LL)))) { (void)(f138_set_t(a_853, tb_869));
 } else { (void)(f138_set_t(b_854, ta_866));
 }
return f138_set_t(n_849, g562);
 }
if (((((ka_890) == (((int64_t)18LL))) || ((kb_891) == (((int64_t)18LL)))) || (f167_is_byte_arr(da_871) && f167_is_byte_arr(db_872)))) { if (((ka_890) == (((int64_t)18LL)))) { (void)(f138_set_t(a_853, g579));
 }
if (((kb_891) == (((int64_t)18LL)))) { (void)(f138_set_t(b_854, g579));
 }
(void)(f178_set_x(n_849, ((int64_t)2LL)));
return f138_set_t(n_849, g562);
 }
if ((((((((ka_890) == (((int64_t)5LL))) || ((ka_890) == (((int64_t)8LL)))) || ((ka_890) == (((int64_t)6LL)))) || ((ka_890) == (((int64_t)7LL)))) || ((ka_890) == (((int64_t)9LL)))) && ((da_871) == (db_872)))) { (void)(f178_set_x(n_849, ((int64_t)3LL)));
return f138_set_t(n_849, g562);
 }
if (((((ka_890) == (((int64_t)6LL))) && ((kb_891) == (((int64_t)7LL)))) || (((ka_890) == (((int64_t)7LL))) && ((kb_891) == (((int64_t)6LL)))))) { (void)(f178_set_x(n_849, ((int64_t)3LL)));
return f138_set_t(n_849, g562);
 }
if ((((ka_890) == (((int64_t)19LL))) || ((kb_891) == (((int64_t)19LL))))) { if (((ka_890) == (((int64_t)19LL)))) { (void)(f140_conv(a_853, db_872));
 } else { (void)(f140_conv(b_854, da_871));
 }
(void)(f178_set_x(n_849, ((int64_t)3LL)));
return f138_set_t(n_849, g562);
 }
 }
int64_t u_903 = f185_unify(n_849, a_853, b_854); 
if (cmp_864) { if (((((*({ hrv *_t2643 = &(g554); int64_t _i2643 = u_903; (S1*)_t2643->b + hr_ix(_i2643, _t2643->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:329"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(a_853, g566));
(void)(f140_conv(b_854, g566));
 }
if (((((*({ hrv *_t2646 = &(g554); int64_t _i2646 = u_903; (S1*)_t2646->b + hr_ix(_i2646, _t2646->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:329"); }))).k_) == (((uint8_t)13LL)))) { (void)(f140_conv(a_853, g572));
(void)(f140_conv(b_854, g572));
 }
return f138_set_t(n_849, g562);
 }
int64_t uk_904 = ((int64_t)(((*({ hrv *_t2650 = &(g554); int64_t _i2650 = u_903; (S1*)_t2650->b + hr_ix(_i2650, _t2650->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:330"); }))).k_)); 
if (((((((((o_852) == (((int64_t)49LL))) || ((o_852) == (((int64_t)50LL)))) || ((o_852) == (((int64_t)51LL)))) && ((uk_904) != (((int64_t)3LL)))) && ((uk_904) != (((int64_t)12LL)))) && ((uk_904) != (((int64_t)2LL)))) && ((uk_904) != (((int64_t)0LL))))) { (void)(f108_cerr(n_849, hr_str("bitwise operator on a non-integer", 33)));
 }
if ((((((uk_904) == (((int64_t)2LL))) && ((o_852) != (((int64_t)49LL)))) && ((o_852) != (((int64_t)50LL)))) && ((o_852) != (((int64_t)51LL))))) { (void)(f108_cerr(n_849, hr_str("arithmetic on bool", 18)));
 }
return f138_set_t(n_849, u_903);
}
static void f180_narrow_push(int64_t c_856) {
if (((c_856) < (((int64_t)0LL)))) { return;
 }
S4 x_857 = (*({ hrv *_t2654 = &(g707); int64_t _i2654 = c_856; (S4*)_t2654->b + hr_ix(_i2654, _t2654->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:84"); })); 
int64_t k_858 = ((int64_t)((x_857).k_)); 
if ((((k_858) == (((int64_t)8LL))) && ((f159_rk(c_856)) == (((int64_t)1LL))))) { int64_t v_859 = f160_rv(c_856); 
int64_t t_860 = ((int64_t)(((*({ hrv *_t2657 = &(g391); int64_t _i2657 = v_859; (S12*)_t2657->b + hr_ix(_i2657, _t2657->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:87"); }))).ty_)); 
if ((((((*({ hrv *_t2658 = &(g554); int64_t _i2658 = t_860; (S1*)_t2658->b + hr_ix(_i2658, _t2658->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:88"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2659 = &(g554); int64_t _i2659 = t_860; (S1*)_t2659->b + hr_ix(_i2659, _t2659->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:88"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(({ hrv *_v2660 = &(g393); int32_t _x2660 = ((int32_t)(v_859)); int32_t *_p2660 = (int32_t*)hr_grow(_v2660, 1, sizeof _x2660); *_p2660 = _x2660; _p2660; }));
(void)(({ hrv *_v2661 = &(g393); int32_t _x2661 = ((int32_t)(t_860)); int32_t *_p2661 = (int32_t*)hr_grow(_v2661, 1, sizeof _x2661); *_p2661 = _x2661; _p2661; }));
{ int32_t *_t2662 = &(((*({ hrv *_t2663 = &(g391); int64_t _i2663 = v_859; (S12*)_t2663->b + hr_ix(_i2663, _t2663->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:90"); }))).ty_); *_t2662 = ((int32_t)(f119_t_ref(((int64_t)(((*({ hrv *_t2665 = &(g554); int64_t _i2665 = t_860; (S1*)_t2665->b + hr_ix(_i2665, _t2665->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:90"); }))).a_)), ((int64_t)0LL)))); }
 }
return;
 }
if ((((k_858) == (((int64_t)9LL))) && ((((int64_t)((x_857).op_))) == (((int64_t)52LL))))) { (void)(f180_narrow_push(((int64_t)((x_857).a_))));
(void)(f180_narrow_push(((int64_t)((x_857).b_))));
 }
}
static void f181_narrow_pop(int64_t m_861) {
while ((((g393).n) > (m_861))) { int32_t old_t_862 = ({ hrv *_v2669 = &(g393); if (!_v2669->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:101"); ((int32_t*)_v2669->b)[--_v2669->n]; }); 
int64_t v_863 = ((int64_t)(({ hrv *_v2670 = &(g393); if (!_v2670->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:102"); ((int32_t*)_v2670->b)[--_v2670->n]; }))); 
{ int32_t *_t2671 = &(((*({ hrv *_t2672 = &(g391); int64_t _i2672 = v_863; (S12*)_t2672->b + hr_ix(_i2672, _t2672->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:103"); }))).ty_); *_t2671 = old_t_862; }
 } _bk2668:; 
}
static int64_t f182_deref(int64_t t_868) {
return ({ int64_t _r2673; if ((((((*({ hrv *_t2674 = &(g554); int64_t _i2674 = t_868; (S1*)_t2674->b + hr_ix(_i2674, _t2674->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:67"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2675 = &(g554); int64_t _i2675 = t_868; (S1*)_t2675->b + hr_ix(_i2675, _t2675->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:67"); }))).c_) < (((int32_t)0LL))))) { _r2673 = ((int64_t)(((*({ hrv *_t2676 = &(g554); int64_t _i2676 = t_868; (S1*)_t2676->b + hr_ix(_i2676, _t2676->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:67"); }))).a_));  } else { _r2673 = t_868;  } _r2673; });
}
static int64_t f183_leaf_kind(int64_t t_873) {
S1 x_874 = (*({ hrv *_t2677 = &(g554); int64_t _i2677 = t_873; (S1*)_t2677->b + hr_ix(_i2677, _t2677->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:270"); })); 
int64_t k_875 = ((int64_t)((x_874).k_)); 
if (((k_875) == (((int64_t)3LL)))) { return ((int64_t)1LL);
 }
if (((k_875) == (((int64_t)4LL)))) { return ((int64_t)2LL);
 }
if (((k_875) == (((int64_t)5LL)))) { int64_t r_876 = ((int64_t)0LL); 
{ int32_t _e2679 = ((*({ hrv *_t2680 = &(g557); int64_t _i2680 = (x_874).a_; (S10*)_t2680->b + hr_ix(_i2680, _t2680->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:272"); }))).fnum_; for (int32_t _k2679 = 0; _k2679 < _e2679; _k2679++) { int32_t i_877 = (int32_t)_k2679; S11 f_878 = (*({ hrv *_t2681 = &(g558); int64_t _i2681 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2682 = &(g557); int64_t _i2682 = (x_874).a_; (S10*)_t2682->b + hr_ix(_i2682, _t2682->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:272"); }))).f0_)) + (int64_t)((int64_t)(i_877)))); (S11*)_t2681->b + hr_ix(_i2681, _t2681->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:272"); })); 
if ((((f_878).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t l_879 = f183_leaf_kind(((int64_t)((f_878).ty_))); 
if ((((l_879) == (((int64_t)0LL))) || (((r_876) != (((int64_t)0LL))) && ((r_876) != (l_879))))) { return ((int64_t)0LL);
 }
r_876 = l_879;
 } } _bk2678:; 
return ((int64_t)((int64_t)r_876 + (int64_t)((int64_t)4LL)));
 }
if ((((k_875) == (((int64_t)8LL))) && (((x_874).s_) == (((uint8_t)(((uint8_t)1LL))))))) { int64_t l_880 = f183_leaf_kind(((int64_t)((x_874).a_))); 
if (((l_880) == (((int64_t)0LL)))) { return ((int64_t)0LL);
 }
return ((int64_t)((int64_t)((int64_t)((int64_t)l_880 & (int64_t)((int64_t)3LL))) + (int64_t)((int64_t)4LL)));
 }
return ((int64_t)0LL);
}
static int64_t f184_leaf_type(int64_t t_883) {
S1 x_884 = (*({ hrv *_t2685 = &(g554); int64_t _i2685 = t_883; (S1*)_t2685->b + hr_ix(_i2685, _t2685->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:277"); })); 
int64_t k_885 = ((int64_t)((x_884).k_)); 
if ((((k_885) == (((int64_t)3LL))) || ((k_885) == (((int64_t)4LL))))) { return t_883;
 }
if (((k_885) == (((int64_t)5LL)))) { int64_t r_886 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e2687 = ((*({ hrv *_t2688 = &(g557); int64_t _i2688 = (x_884).a_; (S10*)_t2688->b + hr_ix(_i2688, _t2688->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:279"); }))).fnum_; for (int32_t _k2687 = 0; _k2687 < _e2687; _k2687++) { int32_t i_887 = (int32_t)_k2687; S11 f_888 = (*({ hrv *_t2689 = &(g558); int64_t _i2689 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2690 = &(g557); int64_t _i2690 = (x_884).a_; (S10*)_t2690->b + hr_ix(_i2690, _t2690->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:279"); }))).f0_)) + (int64_t)((int64_t)(i_887)))); (S11*)_t2689->b + hr_ix(_i2689, _t2689->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:279"); })); 
if ((((f_888).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t l_889 = f184_leaf_type(((int64_t)((f_888).ty_))); 
if ((((l_889) < (((int64_t)0LL))) || (((r_886) >= (((int64_t)0LL))) && ((r_886) != (l_889))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
r_886 = l_889;
 } } _bk2686:; 
return r_886;
 }
if ((((k_885) == (((int64_t)8LL))) && (((x_884).s_) == (((uint8_t)(((uint8_t)1LL))))))) { return f184_leaf_type(((int64_t)((x_884).a_)));
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f185_unify(int64_t n_892, int64_t a_893, int64_t b_894) {
int64_t ta_895 = f141_at(a_893); 
int64_t tb_896 = f141_at(b_894); 
if ((((ta_895) < (((int64_t)0LL))) || ((tb_896) < (((int64_t)0LL))))) { return g578;
 }
int64_t da_897 = f182_deref(ta_895); 
int64_t db_898 = f182_deref(tb_896); 
int64_t ka_899 = ((int64_t)(((*({ hrv *_t2697 = &(g554); int64_t _i2697 = da_897; (S1*)_t2697->b + hr_ix(_i2697, _t2697->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:246"); }))).k_)); 
int64_t kb_900 = ((int64_t)(((*({ hrv *_t2698 = &(g554); int64_t _i2698 = db_898; (S1*)_t2698->b + hr_ix(_i2698, _t2698->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:246"); }))).k_)); 
if ((((ka_899) == (((int64_t)0LL))) || ((kb_900) == (((int64_t)0LL))))) { return g578;
 }
if ((((ka_899) == (((int64_t)12LL))) && ((kb_900) == (((int64_t)12LL))))) { return g574;
 }
if (((((ka_899) == (((int64_t)12LL))) || ((ka_899) == (((int64_t)13LL)))) && ((kb_900) == (((int64_t)13LL))))) { return g575;
 }
if ((((ka_899) == (((int64_t)13LL))) && ((kb_900) == (((int64_t)12LL))))) { return g575;
 }
if ((((ka_899) == (((int64_t)18LL))) && ((kb_900) == (((int64_t)18LL))))) { (void)(f138_set_t(a_893, g579));
(void)(f138_set_t(b_894, g579));
return g579;
 }
if (((((ka_899) == (((int64_t)18LL))) || ((ka_899) == (((int64_t)19LL)))) || ((ka_899) == (((int64_t)11LL))))) { (void)(f140_conv(a_893, db_898));
return db_898;
 }
if (((((kb_900) == (((int64_t)18LL))) || ((kb_900) == (((int64_t)19LL)))) || ((kb_900) == (((int64_t)11LL))))) { (void)(f140_conv(b_894, da_897));
return da_897;
 }
if (((ka_899) == (((int64_t)12LL)))) { (void)(f140_conv(a_893, db_898));
return db_898;
 }
if (((kb_900) == (((int64_t)12LL)))) { (void)(f140_conv(b_894, da_897));
return da_897;
 }
if (((ka_899) == (((int64_t)13LL)))) { if (((kb_900) == (((int64_t)4LL)))) { (void)(f140_conv(a_893, db_898));
return db_898;
 }
if (((kb_900) == (((int64_t)3LL)))) { return g575;
 }
 }
if (((kb_900) == (((int64_t)13LL)))) { if (((ka_899) == (((int64_t)4LL)))) { (void)(f140_conv(b_894, da_897));
return da_897;
 }
if (((ka_899) == (((int64_t)3LL)))) { return g575;
 }
 }
if (((da_897) == (db_898))) { if (((ta_895) != (da_897))) { (void)(f145_set_cv(a_893, da_897));
 }
if (((tb_896) != (db_898))) { (void)(f145_set_cv(b_894, db_898));
 }
return da_897;
 }
if ((f155_widens(da_897, db_898) && (!((((ka_899) == (((int64_t)4LL))) && ((kb_900) == (((int64_t)3LL)))))))) { (void)(f145_set_cv(a_893, db_898));
if (((tb_896) != (db_898))) { (void)(f145_set_cv(b_894, db_898));
 }
return db_898;
 }
if ((f155_widens(db_898, da_897) && (!((((kb_900) == (((int64_t)4LL))) && ((ka_899) == (((int64_t)3LL)))))))) { (void)(f145_set_cv(b_894, da_897));
if (((ta_895) != (da_897))) { (void)(f145_set_cv(a_893, da_897));
 }
return da_897;
 }
if ((((ka_899) == (((int64_t)3LL))) && ((kb_900) == (((int64_t)4LL))))) { (void)(f145_set_cv(a_893, db_898));
return db_898;
 }
if ((((kb_900) == (((int64_t)3LL))) && ((ka_899) == (((int64_t)4LL))))) { (void)(f145_set_cv(b_894, da_897));
return da_897;
 }
if (((((ka_899) == (((int64_t)7LL))) && ((kb_900) == (((int64_t)7LL)))) && ((((*({ hrv *_t2717 = &(g554); int64_t _i2717 = da_897; (S1*)_t2717->b + hr_ix(_i2717, _t2717->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:263"); }))).a_) == (((*({ hrv *_t2718 = &(g554); int64_t _i2718 = db_898; (S1*)_t2718->b + hr_ix(_i2718, _t2718->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:263"); }))).a_)))) { int64_t et_901 = f136_t_enum(((int64_t)(((*({ hrv *_t2720 = &(g554); int64_t _i2720 = da_897; (S1*)_t2720->b + hr_ix(_i2720, _t2720->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:263"); }))).a_)), false); 
(void)(f145_set_cv(a_893, et_901));
(void)(f145_set_cv(b_894, et_901));
return et_901;
 }
if (((((ka_899) == (((int64_t)6LL))) && ((kb_900) == (((int64_t)7LL)))) && ((((*({ hrv *_t2723 = &(g554); int64_t _i2723 = da_897; (S1*)_t2723->b + hr_ix(_i2723, _t2723->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:264"); }))).a_) == (((*({ hrv *_t2724 = &(g554); int64_t _i2724 = db_898; (S1*)_t2724->b + hr_ix(_i2724, _t2724->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:264"); }))).a_)))) { (void)(f145_set_cv(b_894, da_897));
if (((ta_895) != (da_897))) { (void)(f145_set_cv(a_893, da_897));
 }
return da_897;
 }
if (((((kb_900) == (((int64_t)6LL))) && ((ka_899) == (((int64_t)7LL)))) && ((((*({ hrv *_t2727 = &(g554); int64_t _i2727 = da_897; (S1*)_t2727->b + hr_ix(_i2727, _t2727->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:265"); }))).a_) == (((*({ hrv *_t2728 = &(g554); int64_t _i2728 = db_898; (S1*)_t2728->b + hr_ix(_i2728, _t2728->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:265"); }))).a_)))) { (void)(f145_set_cv(a_893, db_898));
if (((tb_896) != (db_898))) { (void)(f145_set_cv(b_894, db_898));
 }
return db_898;
 }
hrv m_902 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2733 __attribute__((cleanup(hr_rdrop))) = {0}; hrv _t2735 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2732 = &(m_902); hr_fs(_o2732, hr_str("operands of types ", 18)); hr_fs(_o2732, hr_sl(*hr_tmp(&_t2733, f164_tn(da_897)))); hr_fs(_o2732, hr_str(" and ", 5)); hr_fs(_o2732, hr_sl(*hr_tmp(&_t2735, f164_tn(db_898)))); hr_fs(_o2732, hr_str(" need a cast to a common type", 29)); }));
}
(void)(f108_cerr(n_892, hr_sl(m_902)));
return g578;
}
static int64_t f186_ck_un(int64_t n_906, int64_t want_907) {
S4 x_908 = (*({ hrv *_t2738 = &(g707); int64_t _i2738 = n_906; (S4*)_t2738->b + hr_ix(_i2738, _t2738->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:336"); })); 
int64_t o_909 = ((int64_t)((x_908).op_)); 
int64_t a_910 = ((int64_t)((x_908).a_)); 
if (((o_909) == (((int64_t)47LL)))) { (void)(f137_ck(a_910, g562));
(void)(f140_conv(a_910, g562));
return f138_set_t(n_906, g562);
 }
if (((o_909) == (((int64_t)49LL)))) { int64_t t_911 = f137_ck(a_910, ({ int64_t _r2743; if ((((want_907) >= (((int64_t)0LL))) && ((((*({ hrv *_t2744 = &(g554); int64_t _i2744 = want_907; (S1*)_t2744->b + hr_ix(_i2744, _t2744->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:339"); }))).k_) == (((uint8_t)10LL))))) { _r2743 = ((int64_t)(((*({ hrv *_t2745 = &(g554); int64_t _i2745 = want_907; (S1*)_t2745->b + hr_ix(_i2745, _t2745->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:339"); }))).a_));  } else { _r2743 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2743; })); 
if (f166_is_pending(t_911)) { (void)(f187_default_t(a_910));
 }
(void)(f178_set_x(n_906, ((int64_t)1LL)));
return f138_set_t(n_906, f141_at(a_910));
 }
int64_t t_930 = f137_ck(a_910, want_907); 
int64_t d_931 = f182_deref(t_930); 
if (((t_930) != (d_931))) { (void)(f145_set_cv(a_910, d_931));
 }
if (((((o_909) == (((int64_t)22LL))) && ((((*({ hrv *_t2754 = &(g554); int64_t _i2754 = d_931; (S1*)_t2754->b + hr_ix(_i2754, _t2754->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:343"); }))).k_) == (((uint8_t)3LL)))) && (!(f156_is_signed(d_931))))) { (void)(f108_cerr(n_906, hr_str("unary - of an unsigned integer", 30)));
 }
return f138_set_t(n_906, d_931);
}
static int64_t f187_default_t(int64_t n_912) {
int64_t t_913 = f141_at(n_912); 
if (((t_913) < (((int64_t)0LL)))) { return g561;
 }
int64_t k_914 = ((int64_t)(((*({ hrv *_t2759 = &(g554); int64_t _i2759 = t_913; (S1*)_t2759->b + hr_ix(_i2759, _t2759->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:224"); }))).k_)); 
if (((k_914) == (((int64_t)12LL)))) { M78 _t2760 = f158_cval(n_912); int64_t v_915 = _t2760.r0; bool u_916 = _t2760.r1; bool ok_917 = _t2760.r2; 
int64_t d_918 = ({ int64_t _r2762; if ((ok_917 && u_916)) { _r2762 = g570;  } else { _r2762 = g566;  } _r2762; }); 
(void)(f165_commit(n_912, d_918));
return d_918;
 }
if (((k_914) == (((int64_t)13LL)))) { (void)(f165_commit(n_912, g572));
return g572;
 }
if (((k_914) == (((int64_t)18LL)))) { (void)(f138_set_t(n_912, g579));
return g579;
 }
if (((k_914) == (((int64_t)19LL)))) { S4 x_919 = (*({ hrv *_t2766 = &(g707); int64_t _i2766 = n_912; (S4*)_t2766->b + hr_ix(_i2766, _t2766->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:229"); })); 
int64_t e_920 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((x_919).a_) >= (((int32_t)0LL)))) { e_920 = f187_default_t(((int64_t)((x_919).a_)));
M78 _t2768 = f158_cval(((int64_t)((x_919).b_))); int64_t cnt_921 = _t2768.r0; bool u0_922 = _t2768.r1; bool ok_923 = _t2768.r2; 
(void)(f140_conv(((int64_t)((x_919).b_)), g566));
int64_t a_924 = f123_t_arr(e_920, ((int64_t)1LL), cnt_921, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f138_set_t(n_912, a_924));
return a_924;
 }
{ int32_t _e2774 = (x_919).n_; for (int32_t _k2774 = 0; _k2774 < _e2774; _k2774++) { int32_t i_925 = (int32_t)_k2774; int64_t c_926 = f90_kid(n_912, ((int64_t)(i_925))); 
int64_t ct_927 = f141_at(c_926); 
if ((!(f166_is_pending(ct_927)))) { e_920 = ct_927;
 }
 } } _bk2773:; 
if ((((e_920) < (((int64_t)0LL))) && (((x_919).n_) > (((int32_t)0LL))))) { e_920 = f187_default_t(f90_kid(n_912, ((int64_t)0LL)));
 }
if (((e_920) < (((int64_t)0LL)))) { (void)(f108_cerr(n_912, hr_str("an empty [] has no element type here", 36)));
return g578;
 }
{ int32_t _e2782 = (x_919).n_; for (int32_t _k2782 = 0; _k2782 < _e2782; _k2782++) { int32_t i_928 = (int32_t)_k2782; (void)(f140_conv(f90_kid(n_912, ((int64_t)(i_928))), e_920));
 } } _bk2781:; 
int64_t a_929 = f123_t_arr(e_920, ((int64_t)1LL), ((int64_t)((x_919).n_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f138_set_t(n_912, a_929));
return a_929;
 }
return t_913;
}
static int64_t f188_ck_dot(int64_t n_933, int64_t want_934) {
S4 x_935 = (*({ hrv *_t2787 = &(g707); int64_t _i2787 = n_933; (S4*)_t2787->b + hr_ix(_i2787, _t2787->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:415"); })); 
int64_t a_936 = ((int64_t)((x_935).a_)); 
int64_t name_937 = ((int64_t)((x_935).s_)); 
if ((((((*({ hrv *_t2788 = &(g707); int64_t _i2788 = a_936; (S4*)_t2788->b + hr_ix(_i2788, _t2788->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:418"); }))).k_) == (((uint8_t)8LL))) && ((f170_find_lv(((int64_t)(((*({ hrv *_t2790 = &(g707); int64_t _i2790 = a_936; (S4*)_t2790->b + hr_ix(_i2790, _t2790->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:418"); }))).s_)))) < (((int64_t)0LL))))) { int64_t ns_938 = f110_ns_of(a_936); 
int64_t de_939 = f116_lookup_q(((int64_t)(((*({ hrv *_t2793 = &(g707); int64_t _i2793 = a_936; (S4*)_t2793->b + hr_ix(_i2793, _t2793->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:420"); }))).s_)), ns_938, ((int64_t)2LL)); 
if ((((de_939) >= (((int64_t)0LL))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t2795 = &(g707); int64_t _i2795 = a_936; (S4*)_t2795->b + hr_ix(_i2795, _t2795->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:421"); }))).s_)), ns_938, ((int64_t)5LL))) < (((int64_t)0LL))))) { int64_t et_943 = f189_rtype_name_enum(de_939); 
int64_t ei_944 = ((int64_t)(((*({ hrv *_t2797 = &(g554); int64_t _i2797 = et_943; (S1*)_t2797->b + hr_ix(_i2797, _t2797->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:423"); }))).a_)); 
{ int32_t _e2799 = ((*({ hrv *_t2800 = &(g559); int64_t _i2800 = ei_944; (S8*)_t2800->b + hr_ix(_i2800, _t2800->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:424"); }))).vnum_; for (int32_t _k2799 = 0; _k2799 < _e2799; _k2799++) { int32_t i_945 = (int32_t)_k2799; if (((((int64_t)(((*({ hrv *_t2801 = &(g560); int64_t _i2801 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2802 = &(g559); int64_t _i2802 = ei_944; (S8*)_t2802->b + hr_ix(_i2802, _t2802->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:424"); }))).v0_)) + (int64_t)((int64_t)(i_945)))); (S9*)_t2801->b + hr_ix(_i2801, _t2801->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:424"); }))).name_))) == (name_937))) { (void)(f173_set_r(n_933, ((int64_t)7LL), ((int64_t)(i_945))));
return f138_set_t(n_933, f125_t_variant(ei_944, ((int64_t)(i_945))));
 }
 } } _bk2798:; 
hrv m_946 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2809 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2807 = &(m_946); hr_fs(_o2807, hr_str("no variant ", 11)); hr_fs(_o2807, f10_nm(name_937)); hr_fs(_o2807, hr_str(" in ", 4)); hr_fs(_o2807, hr_sl(*hr_tmp(&_t2809, f164_tn(et_943)))); }));
}
(void)(f108_cerr(n_933, hr_sl(m_946)));
return f138_set_t(n_933, g578);
 }
 }
int64_t t0_947 = f137_ck(a_936, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t t_948 = t0_947; 
if (((((*({ hrv *_t2814 = &(g554); int64_t _i2814 = t_948; (S1*)_t2814->b + hr_ix(_i2814, _t2814->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:430"); }))).k_) == (((uint8_t)18LL)))) { t_948 = g579;
(void)(f138_set_t(a_936, g579));
 }
if (((((*({ hrv *_t2816 = &(g554); int64_t _i2816 = t_948; (S1*)_t2816->b + hr_ix(_i2816, _t2816->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:431"); }))).k_) == (((uint8_t)19LL)))) { t_948 = f187_default_t(a_936);
 }
int64_t d_949 = f182_deref(t_948); 
int64_t k_950 = ((int64_t)(((*({ hrv *_t2819 = &(g554); int64_t _i2819 = d_949; (S1*)_t2819->b + hr_ix(_i2819, _t2819->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:433"); }))).k_)); 
if (((((k_950) == (((int64_t)8LL))) || ((k_950) == (((int64_t)9LL)))) && hr_streq(f10_nm(name_937), hr_str("len", 3)))) { (void)(f173_set_r(n_933, ((int64_t)8LL), ((int64_t)1LL)));
return f138_set_t(n_933, g566);
 }
if ((((k_950) == (((int64_t)8LL))) && hr_streq(f10_nm(name_937), hr_str("cap", 3)))) { (void)(f173_set_r(n_933, ((int64_t)8LL), ((int64_t)2LL)));
return f138_set_t(n_933, g566);
 }
if (((k_950) == (((int64_t)5LL)))) { int64_t si_951 = ((int64_t)(((*({ hrv *_t2826 = &(g554); int64_t _i2826 = d_949; (S1*)_t2826->b + hr_ix(_i2826, _t2826->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:437"); }))).a_)); 
int64_t fi_955 = f190_sfield(si_951, name_937); 
if (((fi_955) >= (((int64_t)0LL)))) { (void)(f173_set_r(n_933, ((int64_t)5LL), fi_955));
int64_t ft_956 = ((int64_t)(((*({ hrv *_t2829 = &(g558); int64_t _i2829 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2830 = &(g557); int64_t _i2830 = si_951; (S10*)_t2830->b + hr_ix(_i2830, _t2830->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:439"); }))).f0_)) + (int64_t)fi_955)); (S11*)_t2829->b + hr_ix(_i2829, _t2829->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:439"); }))).ty_)); 
return f138_set_t(n_933, f191_decode_rel(ft_956));
 }
 }
if (((k_950) == (((int64_t)7LL)))) { S9 v_958 = (*({ hrv *_t2833 = &(g560); int64_t _i2833 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2834 = &(g559); int64_t _i2834 = ((*({ hrv *_t2835 = &(g554); int64_t _i2835 = d_949; (S1*)_t2835->b + hr_ix(_i2835, _t2835->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:442"); }))).a_; (S8*)_t2834->b + hr_ix(_i2834, _t2834->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:442"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t2836 = &(g554); int64_t _i2836 = d_949; (S1*)_t2836->b + hr_ix(_i2836, _t2836->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:442"); }))).c_)))); (S9*)_t2833->b + hr_ix(_i2833, _t2833->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:442"); })); 
if ((((v_958).si_) >= (((int32_t)0LL)))) { int64_t fi_959 = f190_sfield(((int64_t)((v_958).si_)), name_937); 
if (((fi_959) >= (((int64_t)0LL)))) { (void)(f173_set_r(n_933, ((int64_t)5LL), fi_959));
(void)(f178_set_x(n_933, ((int64_t)((v_958).si_))));
return f138_set_t(n_933, f191_decode_rel(((int64_t)(((*({ hrv *_t2842 = &(g558); int64_t _i2842 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2843 = &(g557); int64_t _i2843 = (v_958).si_; (S10*)_t2843->b + hr_ix(_i2843, _t2843->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:443"); }))).f0_)) + (int64_t)fi_959)); (S11*)_t2842->b + hr_ix(_i2842, _t2842->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:443"); }))).ty_))));
 }
 }
 }
hrv m_960 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2847 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2845 = &(m_960); hr_fs(_o2845, hr_str("no field ", 9)); hr_fs(_o2845, f10_nm(name_937)); hr_fs(_o2845, hr_str(" in ", 4)); hr_fs(_o2845, hr_sl(*hr_tmp(&_t2847, f164_tn(d_949)))); }));
}
(void)(f108_cerr(n_933, hr_sl(m_960)));
return f138_set_t(n_933, g578);
}
static int64_t f189_rtype_name_enum(int64_t de_940) {
int64_t node_941 = ((int64_t)(((*({ hrv *_t2851 = &(g492); int64_t _i2851 = de_940; (S5*)_t2851->b + hr_ix(_i2851, _t2851->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:448"); }))).node_)); 
L84 none_942 = ({ L84 _t2852; memset(&_t2852, 0, sizeof _t2852); _t2852.n = 0; _t2852; }); 
return f136_t_enum(f135_inst_enum(node_941, ({ hsl _t2855 = ({ L84 *_t2856 = &(none_942); (hsl){ (uint8_t*)_t2856->e, _t2856->n }; }); int64_t _l2855 = 0, _h2855 = _t2855.n; if (_l2855 < 0 || _h2855 < _l2855 || _h2855 > _t2855.n) hr_slerr(_l2855, _h2855, _t2855.n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:448"); (hsl){ _t2855.p + _l2855 * (int64_t)sizeof(int32_t), _h2855 - _l2855 }; })), false);
}
static int64_t f190_sfield(int64_t si_952, int64_t name_953) {
{ int32_t _e2858 = ((*({ hrv *_t2859 = &(g557); int64_t _i2859 = si_952; (S10*)_t2859->b + hr_ix(_i2859, _t2859->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:196"); }))).fnum_; for (int32_t _k2858 = 0; _k2858 < _e2858; _k2858++) { int32_t i_954 = (int32_t)_k2858; if (((((int64_t)(((*({ hrv *_t2860 = &(g558); int64_t _i2860 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2861 = &(g557); int64_t _i2861 = si_952; (S10*)_t2861->b + hr_ix(_i2861, _t2861->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:196"); }))).f0_)) + (int64_t)((int64_t)(i_954)))); (S11*)_t2860->b + hr_ix(_i2860, _t2860->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:196"); }))).name_))) == (name_953))) { return ((int64_t)(i_954));
 }
 } } _bk2857:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f191_decode_rel(int64_t ft_957) {
return ({ int64_t _r2862; if ((((((*({ hrv *_t2863 = &(g554); int64_t _i2863 = ft_957; (S1*)_t2863->b + hr_ix(_i2863, _t2863->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:413"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2864 = &(g554); int64_t _i2864 = ft_957; (S1*)_t2864->b + hr_ix(_i2864, _t2864->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:413"); }))).c_) >= (((int32_t)0LL))))) { _r2862 = f119_t_ref(((int64_t)(((*({ hrv *_t2866 = &(g554); int64_t _i2866 = ft_957; (S1*)_t2866->b + hr_ix(_i2866, _t2866->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:413"); }))).a_)), ((int64_t)(((*({ hrv *_t2867 = &(g554); int64_t _i2867 = ft_957; (S1*)_t2867->b + hr_ix(_i2867, _t2867->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:413"); }))).fl_)));  } else { _r2862 = ft_957;  } _r2862; });
}
static int64_t f192_ck_idx(int64_t n_961, int64_t want_962) {
S4 x_963 = (*({ hrv *_t2868 = &(g707); int64_t _i2868 = n_961; (S4*)_t2868->b + hr_ix(_i2868, _t2868->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:450"); })); 
int64_t t_964 = f137_ck(((int64_t)((x_963).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t2870 = &(g554); int64_t _i2870 = t_964; (S1*)_t2870->b + hr_ix(_i2870, _t2870->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:452"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_963).a_)), g579));
t_964 = g579;
 }
if (((((*({ hrv *_t2872 = &(g554); int64_t _i2872 = t_964; (S1*)_t2872->b + hr_ix(_i2872, _t2872->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:453"); }))).k_) == (((uint8_t)19LL)))) { t_964 = f187_default_t(((int64_t)((x_963).a_)));
 }
int64_t d_965 = f182_deref(t_964); 
int64_t ti_966 = f137_ck(((int64_t)((x_963).b_)), g566); 
if (((((*({ hrv *_t2876 = &(g554); int64_t _i2876 = ti_966; (S1*)_t2876->b + hr_ix(_i2876, _t2876->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:456"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_963).b_)), g566));
 } else { int64_t di_967 = f182_deref(ti_966); 
if ((((((*({ hrv *_t2879 = &(g554); int64_t _i2879 = di_967; (S1*)_t2879->b + hr_ix(_i2879, _t2879->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:456"); }))).k_) != (((uint8_t)3LL))) && ((((*({ hrv *_t2880 = &(g554); int64_t _i2880 = di_967; (S1*)_t2880->b + hr_ix(_i2880, _t2880->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:456"); }))).k_) != (((uint8_t)17LL))))) { (void)(f108_cerr(((int64_t)((x_963).b_)), hr_str("index must be an integer", 24)));
 } else { if (((di_967) != (ti_966))) { (void)(f145_set_cv(((int64_t)((x_963).b_)), di_967));
 }
 }
 }
int64_t k_968 = ((int64_t)(((*({ hrv *_t2883 = &(g554); int64_t _i2883 = d_965; (S1*)_t2883->b + hr_ix(_i2883, _t2883->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:457"); }))).k_)); 
if ((((k_968) == (((int64_t)8LL))) || ((k_968) == (((int64_t)9LL))))) { return f138_set_t(n_961, f191_decode_rel(((int64_t)(((*({ hrv *_t2886 = &(g554); int64_t _i2886 = d_965; (S1*)_t2886->b + hr_ix(_i2886, _t2886->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:458"); }))).a_))));
 }
hrv m_969 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2889 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2888 = &(m_969); hr_fs(_o2888, hr_str("cannot index ", 13)); hr_fs(_o2888, hr_sl(*hr_tmp(&_t2889, f164_tn(d_965)))); }));
}
(void)(f108_cerr(n_961, hr_sl(m_969)));
return f138_set_t(n_961, g578);
}
static int64_t f193_ck_slice(int64_t n_970, int64_t want_971) {
S4 x_972 = (*({ hrv *_t2893 = &(g707); int64_t _i2893 = n_970; (S4*)_t2893->b + hr_ix(_i2893, _t2893->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:463"); })); 
int64_t t_973 = f137_ck(((int64_t)((x_972).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t2895 = &(g554); int64_t _i2895 = t_973; (S1*)_t2895->b + hr_ix(_i2895, _t2895->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:465"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_972).a_)), g579));
t_973 = g579;
 }
if (((((*({ hrv *_t2897 = &(g554); int64_t _i2897 = t_973; (S1*)_t2897->b + hr_ix(_i2897, _t2897->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:466"); }))).k_) == (((uint8_t)19LL)))) { t_973 = f187_default_t(((int64_t)((x_972).a_)));
 }
int64_t d_974 = f182_deref(t_973); 
if ((((x_972).b_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_972).b_)), g566));
(void)(f140_conv(((int64_t)((x_972).b_)), g566));
 }
if ((((x_972).c_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_972).c_)), g566));
(void)(f140_conv(((int64_t)((x_972).c_)), g566));
 }
int64_t k_975 = ((int64_t)(((*({ hrv *_t2904 = &(g554); int64_t _i2904 = d_974; (S1*)_t2904->b + hr_ix(_i2904, _t2904->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:470"); }))).k_)); 
if (((k_975) == (((int64_t)8LL)))) { return f138_set_t(n_970, f18_t_slice(((int64_t)(((*({ hrv *_t2907 = &(g554); int64_t _i2907 = d_974; (S1*)_t2907->b + hr_ix(_i2907, _t2907->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:471"); }))).a_)), false));
 }
if (((k_975) == (((int64_t)9LL)))) { return f138_set_t(n_970, d_974);
 }
hrv m_976 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2911 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2910 = &(m_976); hr_fs(_o2910, hr_str("cannot slice ", 13)); hr_fs(_o2910, hr_sl(*hr_tmp(&_t2911, f164_tn(d_974)))); }));
}
(void)(f108_cerr(n_970, hr_sl(m_976)));
return f138_set_t(n_970, g578);
}
static int64_t f194_ck_as(int64_t n_977, int64_t want_978) {
S4 x_979 = (*({ hrv *_t2915 = &(g707); int64_t _i2915 = n_977; (S4*)_t2915->b + hr_ix(_i2915, _t2915->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:477"); })); 
int64_t t_980 = f113_rtype(((int64_t)((x_979).b_)), f110_ns_of(n_977)); 
int64_t f_981 = f137_ck(((int64_t)((x_979).a_)), ({ int64_t _r2919; if ((((((*({ hrv *_t2920 = &(g554); int64_t _i2920 = t_980; (S1*)_t2920->b + hr_ix(_i2920, _t2920->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:479"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2921 = &(g554); int64_t _i2921 = t_980; (S1*)_t2921->b + hr_ix(_i2921, _t2921->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:479"); }))).k_) == (((uint8_t)4LL))))) { _r2919 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2919 = t_980;  } _r2919; })); 
int64_t df_982 = f182_deref(f_981); 
if ((((((*({ hrv *_t2923 = &(g554); int64_t _i2923 = df_982; (S1*)_t2923->b + hr_ix(_i2923, _t2923->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:481"); }))).k_) == (((uint8_t)12LL))) || ((((*({ hrv *_t2924 = &(g554); int64_t _i2924 = df_982; (S1*)_t2924->b + hr_ix(_i2924, _t2924->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:481"); }))).k_) == (((uint8_t)13LL))))) { (void)(f140_conv(((int64_t)((x_979).a_)), ({ int64_t _r2926; if ((((((*({ hrv *_t2927 = &(g554); int64_t _i2927 = t_980; (S1*)_t2927->b + hr_ix(_i2927, _t2927->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:481"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2928 = &(g554); int64_t _i2928 = t_980; (S1*)_t2928->b + hr_ix(_i2928, _t2928->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:481"); }))).k_) == (((uint8_t)4LL))))) { _r2926 = t_980;  } else { _r2926 = g566;  } _r2926; })));
 } else { if (((df_982) != (f_981))) { (void)(f145_set_cv(((int64_t)((x_979).a_)), df_982));
 }
 }
return f138_set_t(n_977, t_980);
}
static int64_t f195_ck_arr(int64_t n_983, int64_t want_984) {
S4 x_985 = (*({ hrv *_t2931 = &(g707); int64_t _i2931 = n_983; (S4*)_t2931->b + hr_ix(_i2931, _t2931->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:713"); })); 
int64_t e_986 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((want_984) >= (((int64_t)0LL))) && (((((*({ hrv *_t2932 = &(g554); int64_t _i2932 = want_984; (S1*)_t2932->b + hr_ix(_i2932, _t2932->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:715"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2933 = &(g554); int64_t _i2933 = want_984; (S1*)_t2933->b + hr_ix(_i2933, _t2933->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:715"); }))).k_) == (((uint8_t)9LL)))))) { e_986 = ((int64_t)(((*({ hrv *_t2934 = &(g554); int64_t _i2934 = want_984; (S1*)_t2934->b + hr_ix(_i2934, _t2934->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:715"); }))).a_));
 }
if ((((x_985).c_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_985).c_)), g566));
(void)(f140_conv(((int64_t)((x_985).c_)), g566));
if (((want_984) >= (((int64_t)0LL)))) { return f138_set_t(n_983, want_984);
 }
return f138_set_t(n_983, g580);
 }
if ((((x_985).a_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_985).a_)), e_986));
(void)(f137_ck(((int64_t)((x_985).b_)), g566));
if (((e_986) >= (((int64_t)0LL)))) { (void)(f140_conv(((int64_t)((x_985).a_)), e_986));
(void)(f140_conv(((int64_t)((x_985).b_)), g566));
if (((((*({ hrv *_t2943 = &(g554); int64_t _i2943 = want_984; (S1*)_t2943->b + hr_ix(_i2943, _t2943->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:717"); }))).k_) == (((uint8_t)9LL)))) { M78 _t2944 = f158_cval(((int64_t)((x_985).b_))); int64_t cnt_987 = _t2944.r0; bool u0_988 = _t2944.r1; bool ok_989 = _t2944.r2; 
(void)(f138_set_t(n_983, f123_t_arr(e_986, ((int64_t)1LL), cnt_987, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f145_set_cv(n_983, want_984));
return want_984;
 }
return f138_set_t(n_983, want_984);
 }
return f138_set_t(n_983, g580);
 }
{ int32_t _e2952 = (x_985).n_; for (int32_t _k2952 = 0; _k2952 < _e2952; _k2952++) { int32_t i_990 = (int32_t)_k2952; (void)(f137_ck(f90_kid(n_983, ((int64_t)(i_990))), e_986));
 } } _bk2951:; 
if (((e_986) >= (((int64_t)0LL)))) { { int32_t _e2956 = (x_985).n_; for (int32_t _k2956 = 0; _k2956 < _e2956; _k2956++) { int32_t i_991 = (int32_t)_k2956; (void)(f140_conv(f90_kid(n_983, ((int64_t)(i_991))), e_986));
 } } _bk2955:; 
if (((((*({ hrv *_t2959 = &(g554); int64_t _i2959 = want_984; (S1*)_t2959->b + hr_ix(_i2959, _t2959->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:721"); }))).k_) == (((uint8_t)9LL)))) { (void)(f138_set_t(n_983, f123_t_arr(e_986, ((int64_t)1LL), f103_max(((int64_t)((x_985).n_)), ((int64_t)1LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f145_set_cv(n_983, want_984));
return want_984;
 }
return f138_set_t(n_983, want_984);
 }
return f138_set_t(n_983, g580);
}
static int64_t f196_ck_block(int64_t n_992, int64_t want_993) {
S4 x_994 = (*({ hrv *_t2966 = &(g707); int64_t _i2966 = n_992; (S4*)_t2966->b + hr_ix(_i2966, _t2966->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:486"); })); 
int64_t m_995 = (g392).n; 
int64_t nm0_996 = (g393).n; 
int64_t nf0_1032 = f197_pre_decl_block_fns(n_992); 
{ int32_t _e2969 = (x_994).n_; for (int32_t _k2969 = 0; _k2969 < _e2969; _k2969++) { int32_t i_1033 = (int32_t)_k2969; (void)(f204_cstmt(f90_kid(n_992, ((int64_t)(i_1033)))));
 } } _bk2968:; 
int64_t t_1113 = g561; 
if ((((x_994).a_) >= (((int32_t)0LL)))) { t_1113 = f137_ck(((int64_t)((x_994).a_)), want_993);
 }
(void)(f213_pop_block_fns(nf0_1032));
(void)(f181_narrow_pop(nm0_996));
(void)(({ hrv *_v2975 = &(g392); int64_t _k2975 = ((int64_t)((int64_t)(g392).n - (int64_t)m_995)); if (_k2975 < 0 || _k2975 > _v2975->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:495"); _v2975->n -= _k2975; }));
return f138_set_t(n_992, t_1113);
}
static int64_t f197_pre_decl_block_fns(int64_t b_997) {
int64_t m_998 = (g312).n; 
{ int32_t _e2978 = ((*({ hrv *_t2979 = &(g707); int64_t _i2979 = b_997; (S4*)_t2979->b + hr_ix(_i2979, _t2979->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); }))).n_; for (int32_t _k2978 = 0; _k2978 < _e2978; _k2978++) { int32_t q_999 = (int32_t)_k2978; int64_t c_1000 = f90_kid(b_997, ((int64_t)(q_999))); 
if (((((int64_t)(((*({ hrv *_t2981 = &(g707); int64_t _i2981 = c_1000; (S4*)_t2981->b + hr_ix(_i2981, _t2981->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); }))).k_))) == (((int64_t)50LL)))) { int64_t i_1001 = f105_new_inst(c_1000, c_1000, ((int64_t)((*({ hrv *_t2983 = &(g722); int64_t _i2983 = c_1000; (int32_t*)_t2983->b + hr_ix(_i2983, _t2983->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); })))), g403); 
(void)(({ hrv *_v2984 = &(g312); S14 _x2984 = ((S14){ .name_ = ((*({ hrv *_t2985 = &(g707); int64_t _i2985 = c_1000; (S4*)_t2985->b + hr_ix(_i2985, _t2985->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); }))).s_, .node_ = ((int32_t)(c_1000)), .inst_ = ((int32_t)(i_1001)), .own_ = ((int32_t)(g403)), }); S14 *_p2984 = (S14*)hr_grow(_v2984, 1, sizeof _x2984); *_p2984 = _x2984; _p2984; }));
(void)(f198_sig_inst(i_1001));
 }
 } } _bk2977:; 
return m_998;
}
static void f198_sig_inst(int64_t i_1002) {
int64_t node_1003 = ((int64_t)(((*({ hrv *_t2987 = &(g390); int64_t _i2987 = i_1002; (S6*)_t2987->b + hr_ix(_i2987, _t2987->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:106"); }))).node_)); 
int64_t ns_1004 = f110_ns_of(node_1003); 
int64_t g0_1005 = (g494).n; 
{ int32_t _e2990 = ((*({ hrv *_t2991 = &(g390); int64_t _i2991 = i_1002; (S6*)_t2991->b + hr_ix(_i2991, _t2991->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:109"); }))).gn_; for (int32_t _k2990 = 0; _k2990 < _e2990; _k2990++) { int32_t j_1006 = (int32_t)_k2990; (void)(({ hrv *_v2992 = &(g494); S7 _x2992 = (*({ hrv *_t2993 = &(g396); int64_t _i2993 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2994 = &(g390); int64_t _i2994 = i_1002; (S6*)_t2994->b + hr_ix(_i2994, _t2994->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:109"); }))).g0_)) + (int64_t)((int64_t)(j_1006)))); (S7*)_t2993->b + hr_ix(_i2993, _t2993->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:109"); })); S7 *_p2992 = (S7*)hr_grow(_v2992, 1, sizeof _x2992); *_p2992 = _x2992; _p2992; }));
 } } _bk2989:; 
int64_t p0_1007 = (g555).n; 
L88 pts_1008 = ({ L88 _t2995; memset(&_t2995, 0, sizeof _t2995); _t2995.n = 0; _t2995; }); 
{ int32_t _e2997 = ((*({ hrv *_t2998 = &(g707); int64_t _i2998 = node_1003; (S4*)_t2998->b + hr_ix(_i2998, _t2998->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:112"); }))).n_; for (int32_t _k2997 = 0; _k2997 < _e2997; _k2997++) { int32_t j_1009 = (int32_t)_k2997; int64_t p_1010 = f90_kid(node_1003, ((int64_t)(j_1009))); 
int64_t t_1011 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((*({ hrv *_t3000 = &(g707); int64_t _i3000 = p_1010; (S4*)_t3000->b + hr_ix(_i3000, _t3000->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:115"); }))).a_) >= (((int32_t)0LL)))) { t_1011 = f113_rtype(((int64_t)(((*({ hrv *_t3002 = &(g707); int64_t _i3002 = p_1010; (S4*)_t3002->b + hr_ix(_i3002, _t3002->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:115"); }))).a_)), ns_1004);
 } else { t_1011 = f130_gb_find(f199_upname(p_1010));
if (((t_1011) < (((int64_t)0LL)))) { t_1011 = g578;
 }
 }
(void)(({ L88 *_v3005 = &(pts_1008); int32_t _x3005 = ((int32_t)(t_1011)); if (_v3005->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:116"); _v3005->e[_v3005->n] = _x3005; &_v3005->e[_v3005->n++]; }));
 } } _bk2996:; 
{ int32_t *_t3006 = &(((*({ hrv *_t3007 = &(g390); int64_t _i3007 = i_1002; (S6*)_t3007->b + hr_ix(_i3007, _t3007->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:118"); }))).p0_); *_t3006 = ((int32_t)((g555).n)); }
(void)(({ hrv *_v3008 = &(g555); hsl _s3008 = ({ hsl _t3009 = ({ L88 *_t3010 = &(pts_1008); (hsl){ (uint8_t*)_t3010->e, _t3010->n }; }); int64_t _l3009 = 0, _h3009 = _t3009.n; if (_l3009 < 0 || _h3009 < _l3009 || _h3009 > _t3009.n) hr_slerr(_l3009, _h3009, _t3009.n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:118"); (hsl){ _t3009.p + _l3009 * (int64_t)sizeof(int32_t), _h3009 - _l3009 }; }); hr_append(_v3008, _s3008.p, _s3008.n, sizeof(int32_t)); }));
{ int32_t *_t3011 = &(((*({ hrv *_t3012 = &(g390); int64_t _i3012 = i_1002; (S6*)_t3012->b + hr_ix(_i3012, _t3012->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:118"); }))).pn_); *_t3011 = ((int32_t)(((int64_t)(pts_1008).n))); }
if (((((*({ hrv *_t3013 = &(g707); int64_t _i3013 = node_1003; (S4*)_t3013->b + hr_ix(_i3013, _t3013->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:119"); }))).b_) >= (((int32_t)0LL)))) { int64_t rl_1014 = ((int64_t)(((*({ hrv *_t3014 = &(g707); int64_t _i3014 = node_1003; (S4*)_t3014->b + hr_ix(_i3014, _t3014->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:120"); }))).b_)); 
if (((((*({ hrv *_t3015 = &(g707); int64_t _i3015 = rl_1014; (S4*)_t3015->b + hr_ix(_i3015, _t3015->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:121"); }))).n_) == (((int32_t)1LL)))) { { int32_t *_t3016 = &(((*({ hrv *_t3017 = &(g390); int64_t _i3017 = i_1002; (S6*)_t3017->b + hr_ix(_i3017, _t3017->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:121"); }))).ret_); *_t3016 = ((int32_t)(f113_rtype(f90_kid(rl_1014, ((int64_t)0LL)), ns_1004))); }
 } else { L89 rs_1015 = ({ L89 _t3020; memset(&_t3020, 0, sizeof _t3020); _t3020.n = 0; _t3020; }); 
{ int32_t _e3022 = ((*({ hrv *_t3023 = &(g707); int64_t _i3023 = rl_1014; (S4*)_t3023->b + hr_ix(_i3023, _t3023->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); }))).n_; for (int32_t _k3022 = 0; _k3022 < _e3022; _k3022++) { int32_t j_1016 = (int32_t)_k3022; int64_t r0_1017 = f113_rtype(f90_kid(rl_1014, ((int64_t)(j_1016))), ns_1004); 
(void)(({ L89 *_v3026 = &(rs_1015); int32_t _x3026 = ((int32_t)(r0_1017)); if (_v3026->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); _v3026->e[_v3026->n] = _x3026; &_v3026->e[_v3026->n++]; }));
 } } _bk3021:; 
{ int32_t *_t3027 = &(((*({ hrv *_t3028 = &(g390); int64_t _i3028 = i_1002; (S6*)_t3028->b + hr_ix(_i3028, _t3028->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); }))).ret_); *_t3027 = ((int32_t)(f200_tlist(((int64_t)14LL), ({ hsl _t3030 = ({ L89 *_t3031 = &(rs_1015); (hsl){ (uint8_t*)_t3031->e, _t3031->n }; }); int64_t _l3030 = 0, _h3030 = _t3030.n; if (_l3030 < 0 || _h3030 < _l3030 || _h3030 > _t3030.n) hr_slerr(_l3030, _h3030, _t3030.n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); (hsl){ _t3030.p + _l3030 * (int64_t)sizeof(int32_t), _h3030 - _l3030 }; }), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); }
 }
 } else { { int32_t *_t3032 = &(((*({ hrv *_t3033 = &(g390); int64_t _i3033 = i_1002; (S6*)_t3033->b + hr_ix(_i3033, _t3033->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).ret_); *_t3032 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
{ bool *_t3034 = &(((*({ hrv *_t3035 = &(g390); int64_t _i3035 = i_1002; (S6*)_t3035->b + hr_ix(_i3035, _t3035->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).rinf_); *_t3034 = true; }
if ((((((uint16_t)((uint64_t)((*({ hrv *_t3036 = &(g707); int64_t _i3036 = node_1003; (S4*)_t3036->b + hr_ix(_i3036, _t3036->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || f201_surely_void(node_1003))) { { int32_t *_t3038 = &(((*({ hrv *_t3039 = &(g390); int64_t _i3039 = i_1002; (S6*)_t3039->b + hr_ix(_i3039, _t3039->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).ret_); *_t3038 = ((int32_t)(g561)); }
{ bool *_t3040 = &(((*({ hrv *_t3041 = &(g390); int64_t _i3041 = i_1002; (S6*)_t3041->b + hr_ix(_i3041, _t3041->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).rinf_); *_t3040 = false; }
 }
 }
(void)(({ hrv *_v3042 = &(g494); int64_t _k3042 = ((int64_t)((int64_t)(g494).n - (int64_t)g0_1005)); if (_k3042 < 0 || _k3042 > _v3042->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:124"); _v3042->n -= _k3042; }));
}
static int64_t f199_upname(int64_t p_1012) {
hrv s_1013 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v3044 = &(s_1013); uint8_t _x3044 = ((uint8_t)36LL); uint8_t *_p3044 = (uint8_t*)hr_grow(_v3044, 1, sizeof _x3044); *_p3044 = _x3044; _p3044; }));
(void)(({ hrv *_v3045 = &(s_1013); hsl _s3045 = f10_nm(((int64_t)(((*({ hrv *_t3047 = &(g707); int64_t _i3047 = p_1012; (S4*)_t3047->b + hr_ix(_i3047, _t3047->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:60"); }))).s_))); hr_append(_v3045, _s3045.p, _s3045.n, sizeof(uint8_t)); }));
return f8_intern(hr_sl(s_1013));
}
static int64_t f200_tlist(int64_t k_1018, hsl xs_1019, int64_t a_1020) {
int64_t l_1021 = (g555).n; 
(void)(({ hrv *_v3049 = &(g555); hsl _s3049 = xs_1019; hr_append(_v3049, _s3049.p, _s3049.n, sizeof(int32_t)); }));
return f13_tmk(((S1){ .k_ = ((uint8_t)(k_1018)), .a_ = ((int32_t)(a_1020)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .l_ = ((int32_t)(l_1021)), .n_ = ((int32_t)((xs_1019).n)), }));
}
static bool f201_surely_void(int64_t fnode_1022) {
int64_t body_1023 = ((int64_t)(((*({ hrv *_t3051 = &(g707); int64_t _i3051 = fnode_1022; (S4*)_t3051->b + hr_ix(_i3051, _t3051->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:127"); }))).c_)); 
if (((body_1023) < (((int64_t)0LL)))) { return true;
 }
int64_t tl_1024 = ((int64_t)(((*({ hrv *_t3052 = &(g707); int64_t _i3052 = body_1023; (S4*)_t3052->b + hr_ix(_i3052, _t3052->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:129"); }))).a_)); 
return (f202_tail_void(tl_1024) && (!(f203_has_valret(body_1023))));
}
static bool f202_tail_void(int64_t tl_1025) {
if (((tl_1025) < (((int64_t)0LL)))) { return true;
 }
S4 x_1026 = (*({ hrv *_t3055 = &(g707); int64_t _i3055 = tl_1025; (S4*)_t3055->b + hr_ix(_i3055, _t3055->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:134"); })); 
int64_t k_1027 = ((int64_t)((x_1026).k_)); 
if (((((((k_1027) == (((int64_t)25LL))) || ((k_1027) == (((int64_t)27LL)))) || ((k_1027) == (((int64_t)28LL)))) || ((k_1027) == (((int64_t)29LL)))) || ((k_1027) == (((int64_t)30LL))))) { return true;
 }
if (((k_1027) == (((int64_t)19LL)))) { return ((((x_1026).c_) < (((int32_t)0LL))) || (f202_tail_void(((int64_t)((x_1026).b_))) && f202_tail_void(((int64_t)((x_1026).c_)))));
 }
if (((k_1027) == (((int64_t)23LL)))) { return f202_tail_void(((int64_t)((x_1026).a_)));
 }
return false;
}
static bool f203_has_valret(int64_t n_1028) {
if (((n_1028) < (((int64_t)0LL)))) { return false;
 }
S4 x_1029 = (*({ hrv *_t3059 = &(g707); int64_t _i3059 = n_1028; (S4*)_t3059->b + hr_ix(_i3059, _t3059->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:142"); })); 
int64_t k_1030 = ((int64_t)((x_1029).k_)); 
if (((k_1030) == (((int64_t)28LL)))) { return ((((x_1029).n_) > (((int32_t)0LL))) && (((x_1029).s_) < (((int32_t)0LL))));
 }
if ((((k_1030) == (((int64_t)50LL))) || ((k_1030) == (((int64_t)37LL))))) { return (((k_1030) == (((int64_t)37LL))) && f203_has_valret(((int64_t)((x_1029).c_))));
 }
if ((((((k_1030) == (((int64_t)1LL))) || ((k_1030) == (((int64_t)2LL)))) || ((k_1030) == (((int64_t)3LL)))) || ((k_1030) == (((int64_t)8LL))))) { return false;
 }
if ((((k_1030) >= (((int64_t)40LL))) && ((k_1030) < (((int64_t)50LL))))) { return false;
 }
if ((((f203_has_valret(((int64_t)((x_1029).a_))) || f203_has_valret(((int64_t)((x_1029).b_)))) || f203_has_valret(((int64_t)((x_1029).c_)))) || f203_has_valret(((int64_t)((x_1029).d_))))) { return true;
 }
if ((((((((((k_1030) == (((int64_t)23LL))) || ((k_1030) == (((int64_t)11LL)))) || ((k_1030) == (((int64_t)20LL)))) || ((k_1030) == (((int64_t)21LL)))) || ((k_1030) == (((int64_t)36LL)))) || ((k_1030) == (((int64_t)16LL)))) || ((k_1030) == (((int64_t)17LL)))) || ((k_1030) == (((int64_t)28LL))))) { { int32_t _e3066 = (x_1029).n_; for (int32_t _k3066 = 0; _k3066 < _e3066; _k3066++) { int32_t i_1031 = (int32_t)_k3066; if (f203_has_valret(f90_kid(n_1028, ((int64_t)(i_1031))))) { return true;
 }
 } } _bk3065:; 
 }
return false;
}
static void f204_cstmt(int64_t n_1034) {
S4 x_1035 = (*({ hrv *_t3069 = &(g707); int64_t _i3069 = n_1034; (S4*)_t3069->b + hr_ix(_i3069, _t3069->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:727"); })); 
int64_t k_1036 = ((int64_t)((x_1035).k_)); 
if (((k_1036) == (((int64_t)33LL)))) { (void)(f205_ck_vdecl(n_1034));
return;
 }
if (((k_1036) == (((int64_t)34LL)))) { (void)(f209_ck_assign(n_1034));
return;
 }
if (((k_1036) == (((int64_t)35LL)))) { int64_t t_1081 = f137_ck(((int64_t)((x_1035).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if ((((((*({ hrv *_t3073 = &(g554); int64_t _i3073 = f182_deref(t_1081); (S1*)_t3073->b + hr_ix(_i3073, _t3073->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:731"); }))).k_) != (((uint8_t)3LL))) && ((((*({ hrv *_t3075 = &(g554); int64_t _i3075 = f182_deref(t_1081); (S1*)_t3075->b + hr_ix(_i3075, _t3075->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:731"); }))).k_) != (((uint8_t)17LL))))) { (void)(f108_cerr(n_1034, hr_str("++/-- needs an integer", 22)));
 }
return;
 }
if (((k_1036) == (((int64_t)50LL)))) { (void)(f210_decl_nested(n_1034));
return;
 }
int64_t t_1112 = f137_ck(n_1034, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f166_is_pending(t_1112)) { (void)(f187_default_t(n_1034));
 }
}
static void f205_ck_vdecl(int64_t n_1037) {
S4 x_1038 = (*({ hrv *_t3082 = &(g707); int64_t _i3082 = n_1037; (S4*)_t3082->b + hr_ix(_i3082, _t3082->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:738"); })); 
int64_t fl_1039 = ((int64_t)((x_1038).fl_)); 
int64_t ns_1040 = f110_ns_of(n_1037); 
bool byref_1041 = ((((int64_t)((int64_t)fl_1039 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL))); 
int64_t dt_1042 = ({ int64_t _r3084; if ((((x_1038).a_) >= (((int32_t)0LL)))) { _r3084 = f113_rtype(((int64_t)((x_1038).a_)), ns_1040);  } else { _r3084 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3084; }); 
int64_t lf_1043 = ((int64_t)((int64_t)((int64_t)((int64_t)({ int64_t _r3086; if (((((int64_t)((int64_t)fl_1039 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)))) { _r3086 = ((int64_t)1LL);  } else { _r3086 = ((int64_t)0LL);  } _r3086; }) | (int64_t)({ int64_t _r3087; if (((((int64_t)((int64_t)fl_1039 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { _r3087 = ((int64_t)2LL);  } else { _r3087 = ((int64_t)0LL);  } _r3087; }))) | (int64_t)({ int64_t _r3088; if (byref_1041) { _r3088 = ((int64_t)8LL);  } else { _r3088 = ((int64_t)0LL);  } _r3088; }))); 
if ((((x_1038).n_) > (((int32_t)1LL)))) { if ((((x_1038).b_) < (((int32_t)0LL)))) { (void)(f108_cerr(n_1037, hr_str("several names need a call's results", 35)));
return;
 }
int64_t init_1044 = f90_kid(((int64_t)((x_1038).b_)), ((int64_t)0LL)); 
int64_t t_1045 = f137_ck(init_1044, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3092 = &(g554); int64_t _i3092 = t_1045; (S1*)_t3092->b + hr_ix(_i3092, _t3092->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:748"); }))).k_) != (((uint8_t)14LL)))) { if (((((int64_t)(((*({ hrv *_t3093 = &(g707); int64_t _i3093 = (x_1038).b_; (S4*)_t3093->b + hr_ix(_i3093, _t3093->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:748"); }))).n_))) == (((int64_t)((x_1038).n_))))) { { int32_t _e3095 = (x_1038).n_; for (int32_t _k3095 = ((int32_t)1LL); _k3095 < _e3095; _k3095++) { int32_t i_1046 = (int32_t)_k3095; int64_t iv_1047 = f90_kid(((int64_t)((x_1038).b_)), ((int64_t)(i_1046))); 
(void)(f137_ck(iv_1047, dt_1042));
if (((dt_1042) >= (((int64_t)0LL)))) { (void)(f140_conv(iv_1047, dt_1042));
 } else { (void)(f187_default_t(iv_1047));
 }
 } } _bk3094:; 
if (((dt_1042) >= (((int64_t)0LL)))) { (void)(f140_conv(init_1044, dt_1042));
 } else { (void)(f187_default_t(init_1044));
 }
{ int32_t _e3103 = (x_1038).n_; for (int32_t _k3103 = 0; _k3103 < _e3103; _k3103++) { int32_t i_1048 = (int32_t)_k3103; int64_t iv_1049 = f90_kid(((int64_t)((x_1038).b_)), ((int64_t)(i_1048))); 
int64_t v_1056 = f207_add_lv(((int64_t)((*({ hrv *_t3106 = &(g708); int64_t _i3106 = ((int64_t)((int64_t)((int64_t)((x_1038).l_)) + (int64_t)((int64_t)(i_1048)))); (int32_t*)_t3106->b + hr_ix(_i3106, _t3106->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:748"); })))), ({ int64_t _r3107; if (((dt_1042) >= (((int64_t)0LL)))) { _r3107 = dt_1042;  } else { _r3107 = f206_fin_t(iv_1049);  } _r3107; }), lf_1043, n_1037); 
if (((i_1048) == (((int32_t)0LL)))) { (void)(f173_set_r(n_1037, ((int64_t)1LL), v_1056));
 }
 } } _bk3102:; 
(void)(f178_set_x(n_1037, ((int64_t)1LL)));
return;
 }
(void)(f108_cerr(n_1037, hr_str("several names need a call with as many results", 46)));
return;
 }
if (((((*({ hrv *_t3112 = &(g554); int64_t _i3112 = t_1045; (S1*)_t3112->b + hr_ix(_i3112, _t3112->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:749"); }))).n_) != ((x_1038).n_))) { (void)(f108_cerr(n_1037, hr_str("result count does not match the names", 37)));
 }
{ int32_t _e3115 = (x_1038).n_; for (int32_t _k3115 = 0; _k3115 < _e3115; _k3115++) { int32_t i_1057 = (int32_t)_k3115; int64_t et_1058 = ({ int64_t _r3116; if (((((int64_t)(i_1057))) < (((int64_t)(((*({ hrv *_t3117 = &(g554); int64_t _i3117 = t_1045; (S1*)_t3117->b + hr_ix(_i3117, _t3117->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:750"); }))).n_))))) { _r3116 = ((int64_t)((*({ hrv *_t3118 = &(g555); int64_t _i3118 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3119 = &(g554); int64_t _i3119 = t_1045; (S1*)_t3119->b + hr_ix(_i3119, _t3119->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:750"); }))).l_)) + (int64_t)((int64_t)(i_1057)))); (int32_t*)_t3118->b + hr_ix(_i3118, _t3118->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:750"); }))));  } else { _r3116 = g578;  } _r3116; }); 
int64_t v_1059 = f207_add_lv(((int64_t)((*({ hrv *_t3121 = &(g708); int64_t _i3121 = ((int64_t)((int64_t)((int64_t)((x_1038).l_)) + (int64_t)((int64_t)(i_1057)))); (int32_t*)_t3121->b + hr_ix(_i3121, _t3121->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:750"); })))), et_1058, lf_1043, n_1037); 
if (((i_1057) == (((int32_t)0LL)))) { (void)(f173_set_r(n_1037, ((int64_t)1LL), v_1059));
 }
 } } _bk3114:; 
return;
 }
int64_t t_1060 = dt_1042; 
if ((((x_1038).b_) >= (((int32_t)0LL)))) { int64_t init_1061 = f90_kid(((int64_t)((x_1038).b_)), ((int64_t)0LL)); 
if (((((((dt_1042) < (((int64_t)0LL))) && ((((*({ hrv *_t3124 = &(g707); int64_t _i3124 = init_1061; (S4*)_t3124->b + hr_ix(_i3124, _t3124->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:756"); }))).k_) == (((uint8_t)16LL)))) && ((((*({ hrv *_t3125 = &(g707); int64_t _i3125 = init_1061; (S4*)_t3125->b + hr_ix(_i3125, _t3125->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:756"); }))).n_) == (((int32_t)0LL)))) && ((((*({ hrv *_t3126 = &(g707); int64_t _i3126 = init_1061; (S4*)_t3126->b + hr_ix(_i3126, _t3126->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:756"); }))).a_) < (((int32_t)0LL)))) && ((((*({ hrv *_t3127 = &(g707); int64_t _i3127 = init_1061; (S4*)_t3127->b + hr_ix(_i3127, _t3127->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:756"); }))).c_) < (((int32_t)0LL))))) { t_1060 = f123_t_arr(g578, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
(void)(f138_set_t(init_1061, t_1060));
 } else { int64_t it_1062 = f137_ck(init_1061, dt_1042); 
if (((dt_1042) >= (((int64_t)0LL)))) { if (byref_1041) { if ((!(((((*({ hrv *_t3131 = &(g554); int64_t _i3131 = dt_1042; (S1*)_t3131->b + hr_ix(_i3131, _t3131->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:761"); }))).k_) == (((uint8_t)10LL)))))) { (void)(f140_conv(init_1061, dt_1042));
 }
 } else { (void)(f140_conv(init_1061, dt_1042));
 }
 } else { if ((((((*({ hrv *_t3134 = &(g554); int64_t _i3134 = it_1062; (S1*)_t3134->b + hr_ix(_i3134, _t3134->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:763"); }))).k_) == (((uint8_t)13LL))) && ((((int64_t)((int64_t)lf_1043 & (int64_t)((int64_t)((int64_t)((int64_t)1LL) | (int64_t)((int64_t)8LL)))))) == (((int64_t)0LL))))) { lf_1043 = ((int64_t)((int64_t)lf_1043 | (int64_t)((int64_t)64LL)));
 }
t_1060 = f187_default_t(init_1061);
if (((((*({ hrv *_t3136 = &(g554); int64_t _i3136 = t_1060; (S1*)_t3136->b + hr_ix(_i3136, _t3136->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:765"); }))).k_) == (((uint8_t)14LL)))) { t_1060 = ((int64_t)((*({ hrv *_t3137 = &(g555); int64_t _i3137 = ((*({ hrv *_t3138 = &(g554); int64_t _i3138 = t_1060; (S1*)_t3138->b + hr_ix(_i3138, _t3138->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:765"); }))).l_; (int32_t*)_t3137->b + hr_ix(_i3137, _t3137->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:765"); }))));
 }
if (((((((*({ hrv *_t3139 = &(g554); int64_t _i3139 = t_1060; (S1*)_t3139->b + hr_ix(_i3139, _t3139->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:766"); }))).k_) == (((uint8_t)7LL))) && (((((*({ hrv *_t3140 = &(g707); int64_t _i3140 = init_1061; (S4*)_t3140->b + hr_ix(_i3140, _t3140->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:766"); }))).k_) == (((uint8_t)14LL))) || ((((*({ hrv *_t3141 = &(g707); int64_t _i3141 = init_1061; (S4*)_t3141->b + hr_ix(_i3141, _t3141->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:766"); }))).k_) == (((uint8_t)17LL))))) && ((((int64_t)((int64_t)lf_1043 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL))))) { t_1060 = f136_t_enum(((int64_t)(((*({ hrv *_t3143 = &(g554); int64_t _i3143 = t_1060; (S1*)_t3143->b + hr_ix(_i3143, _t3143->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:766"); }))).a_)), false);
(void)(f145_set_cv(init_1061, t_1060));
 }
if ((byref_1041 || (((((*({ hrv *_t3145 = &(g707); int64_t _i3145 = init_1061; (S4*)_t3145->b + hr_ix(_i3145, _t3145->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:767"); }))).k_) == (((uint8_t)10LL))) && ((((int64_t)(((*({ hrv *_t3146 = &(g707); int64_t _i3146 = init_1061; (S4*)_t3146->b + hr_ix(_i3146, _t3146->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:767"); }))).op_))) == (((int64_t)49LL)))))) { if (((((*({ hrv *_t3147 = &(g554); int64_t _i3147 = t_1060; (S1*)_t3147->b + hr_ix(_i3147, _t3147->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:767"); }))).k_) != (((uint8_t)10LL)))) { t_1060 = f119_t_ref(t_1060, ((int64_t)0LL));
 }
 } else { if ((((((((*({ hrv *_t3149 = &(g554); int64_t _i3149 = t_1060; (S1*)_t3149->b + hr_ix(_i3149, _t3149->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:768"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t3150 = &(g554); int64_t _i3150 = t_1060; (S1*)_t3150->b + hr_ix(_i3150, _t3150->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:768"); }))).c_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t3151 = &(g554); int64_t _i3151 = t_1060; (S1*)_t3151->b + hr_ix(_i3151, _t3151->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:768"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))) && f208_is_fixed(((int64_t)(((*({ hrv *_t3153 = &(g554); int64_t _i3153 = t_1060; (S1*)_t3153->b + hr_ix(_i3153, _t3153->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:768"); }))).a_))))) { t_1060 = ((int64_t)(((*({ hrv *_t3154 = &(g554); int64_t _i3154 = t_1060; (S1*)_t3154->b + hr_ix(_i3154, _t3154->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:768"); }))).a_));
(void)(f145_set_cv(init_1061, t_1060));
 }
 }
 }
 }
 } else { if (((t_1060) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1037, hr_str("a declaration needs a type or an initializer", 44)));
t_1060 = g578;
 }
 }
if ((byref_1041 && ((((*({ hrv *_t3157 = &(g554); int64_t _i3157 = t_1060; (S1*)_t3157->b + hr_ix(_i3157, _t3157->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:774"); }))).k_) != (((uint8_t)10LL))))) { t_1060 = f119_t_ref(t_1060, ((int64_t)0LL));
 }
int64_t v_1064 = f207_add_lv(((int64_t)((*({ hrv *_t3160 = &(g708); int64_t _i3160 = (x_1038).l_; (int32_t*)_t3160->b + hr_ix(_i3160, _t3160->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:775"); })))), t_1060, lf_1043, n_1037); 
(void)(f173_set_r(n_1037, ((int64_t)1LL), v_1064));
}
static int64_t f206_fin_t(int64_t n_1050) {
int64_t c_1051 = f153_cv(n_1050); 
return ({ int64_t _r3163; if (((c_1051) >= (((int64_t)0LL)))) { _r3163 = c_1051;  } else { _r3163 = f141_at(n_1050);  } _r3163; });
}
static int64_t f207_add_lv(int64_t name_1052, int64_t t_1053, int64_t fl_1054, int64_t node_1055) {
(void)(({ hrv *_v3165 = &(g391); S12 _x3165 = ((S12){ .name_ = ((int32_t)(name_1052)), .ty_ = ((int32_t)(t_1053)), .fl_ = ((uint16_t)(fl_1054)), .cfn_ = ((int32_t)(g404)), .own_ = ((int32_t)(g403)), .node_ = ((int32_t)(node_1055)), .cnt_ = ((int32_t)0LL), }); S12 *_p3165 = (S12*)hr_grow(_v3165, 1, sizeof _x3165); *_p3165 = _x3165; _p3165; }));
(void)(({ hrv *_v3166 = &(g392); int32_t _x3166 = ((int32_t)(((int64_t)((int64_t)(g391).n - (int64_t)((int64_t)1LL))))); int32_t *_p3166 = (int32_t*)hr_grow(_v3166, 1, sizeof _x3166); *_p3166 = _x3166; _p3166; }));
return ((int64_t)((int64_t)(g391).n - (int64_t)((int64_t)1LL)));
}
static bool f208_is_fixed(int64_t t_1063) {
return ((f146_tclass(t_1063)) == (((int64_t)0LL)));
}
static void f209_ck_assign(int64_t n_1065) {
S4 x_1066 = (*({ hrv *_t3168 = &(g707); int64_t _i3168 = n_1065; (S4*)_t3168->b + hr_ix(_i3168, _t3168->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:779"); })); 
int64_t o_1067 = ((int64_t)((x_1066).op_)); 
if (((o_1067) == (((int64_t)11LL)))) { int64_t t_1068 = f137_ck(((int64_t)((x_1066).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t tl_1069 = ((int64_t)((x_1066).a_)); 
{ int32_t _e3171 = ((*({ hrv *_t3172 = &(g707); int64_t _i3172 = tl_1069; (S4*)_t3172->b + hr_ix(_i3172, _t3172->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:784"); }))).n_; for (int32_t _k3171 = 0; _k3171 < _e3171; _k3171++) { int32_t i_1070 = (int32_t)_k3171; int64_t tg_1071 = f90_kid(tl_1069, ((int64_t)(i_1070))); 
int64_t tt_1072 = f137_ck(tg_1071, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
 } } _bk3170:; 
return;
 }
if (((o_1067) == (((int64_t)18LL)))) { int64_t tt_1073 = f137_ck(((int64_t)((x_1066).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t rt_1074 = f137_ck(((int64_t)((x_1066).b_)), tt_1073); 
if (f166_is_pending(rt_1074)) { if ((((((*({ hrv *_t3178 = &(g554); int64_t _i3178 = rt_1074; (S1*)_t3178->b + hr_ix(_i3178, _t3178->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:791"); }))).k_) == (((uint8_t)11LL))) && ((((*({ hrv *_t3179 = &(g554); int64_t _i3179 = tt_1073; (S1*)_t3179->b + hr_ix(_i3179, _t3179->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:791"); }))).k_) == (((uint8_t)10LL))))) { (void)(f138_set_t(((int64_t)((x_1066).b_)), f119_t_ref(((int64_t)(((*({ hrv *_t3182 = &(g554); int64_t _i3182 = tt_1073; (S1*)_t3182->b + hr_ix(_i3182, _t3182->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:791"); }))).a_)), ((int64_t)2LL))));
 } else { (void)(f187_default_t(((int64_t)((x_1066).b_))));
 }
 }
if ((((((*({ hrv *_t3184 = &(g707); int64_t _i3184 = (x_1066).a_; (S4*)_t3184->b + hr_ix(_i3184, _t3184->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:794"); }))).k_) == (((uint8_t)8LL))) && ((f159_rk(((int64_t)((x_1066).a_)))) == (((int64_t)1LL))))) { int64_t v_1075 = f160_rv(((int64_t)((x_1066).a_))); 
if ((f168_is_opt(f141_at(((int64_t)((x_1066).b_)))) || ((((*({ hrv *_t3189 = &(g554); int64_t _i3189 = f141_at(((int64_t)((x_1066).b_))); (S1*)_t3189->b + hr_ix(_i3189, _t3189->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:796"); }))).k_) == (((uint8_t)11LL))))) { { int32_t *_t3191 = &(((*({ hrv *_t3192 = &(g391); int64_t _i3192 = v_1075; (S12*)_t3192->b + hr_ix(_i3192, _t3192->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:797"); }))).ty_); *_t3191 = ((int32_t)(f119_t_ref(((int64_t)(((*({ hrv *_t3194 = &(g554); int64_t _i3194 = ((*({ hrv *_t3195 = &(g391); int64_t _i3195 = v_1075; (S12*)_t3195->b + hr_ix(_i3195, _t3195->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:797"); }))).ty_; (S1*)_t3194->b + hr_ix(_i3194, _t3194->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:797"); }))).a_)), ((int64_t)2LL)))); }
 }
 }
return;
 }
int64_t tt_1076 = f137_ck(((int64_t)((x_1066).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t d_1077 = f182_deref(tt_1076); 
if (((o_1067) == (((int64_t)36LL)))) { if ((((((*({ hrv *_t3198 = &(g554); int64_t _i3198 = tt_1076; (S1*)_t3198->b + hr_ix(_i3198, _t3198->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:805"); }))).k_) == (((uint8_t)10LL))) && f168_is_opt(tt_1076))) { int64_t rt_1078 = f137_ck(((int64_t)((x_1066).b_)), tt_1076); 
if (((((*({ hrv *_t3201 = &(g554); int64_t _i3201 = rt_1078; (S1*)_t3201->b + hr_ix(_i3201, _t3201->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:807"); }))).k_) == (((uint8_t)11LL)))) { (void)(f165_commit(((int64_t)((x_1066).b_)), tt_1076));
return;
 }
if (((((*({ hrv *_t3203 = &(g554); int64_t _i3203 = rt_1078; (S1*)_t3203->b + hr_ix(_i3203, _t3203->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:808"); }))).k_) == (((uint8_t)10LL)))) { (void)(f140_conv(((int64_t)((x_1066).b_)), tt_1076));
return;
 }
 }
(void)(f137_ck(((int64_t)((x_1066).b_)), d_1077));
(void)(f140_conv(((int64_t)((x_1066).b_)), d_1077));
return;
 }
int64_t lk_1079 = f183_leaf_kind(d_1077); 
int64_t rt_1080 = f137_ck(((int64_t)((x_1066).b_)), ({ int64_t _r3209; if ((((((lk_1079) >= (((int64_t)4LL))) && (((o_1067) == (((int64_t)28LL))) || ((o_1067) == (((int64_t)29LL))))) || ((o_1067) == (((int64_t)45LL)))) || ((o_1067) == (((int64_t)46LL))))) { _r3209 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r3209 = d_1077;  } _r3209; })); 
if (((((lk_1079) >= (((int64_t)4LL))) && (((o_1067) == (((int64_t)28LL))) || ((o_1067) == (((int64_t)29LL))))) && ((f182_deref(rt_1080)) != (d_1077)))) { (void)(f140_conv(((int64_t)((x_1066).b_)), f184_leaf_type(d_1077)));
return;
 }
if ((((o_1067) == (((int64_t)45LL))) || ((o_1067) == (((int64_t)46LL))))) { if (f166_is_pending(rt_1080)) { (void)(f140_conv(((int64_t)((x_1066).b_)), g566));
 }
return;
 }
(void)(f140_conv(((int64_t)((x_1066).b_)), d_1077));
}
static void f210_decl_nested(int64_t n_1082) {
int64_t i_1083 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v3217 = &(g312); for (int64_t _k3217 = 0; _k3217 < _v3217->n; _k3217++) { S14 f_1084 = ((S14*)_v3217->b)[_k3217]; if ((((((int64_t)((f_1084).node_))) == (n_1082)) && ((((int64_t)((f_1084).own_))) == (g403)))) { i_1083 = ((int64_t)((f_1084).inst_));
 }
 } } _bk3216:; 
if (((i_1083) < (((int64_t)0LL)))) { i_1083 = f105_new_inst(n_1082, n_1082, ((int64_t)((*({ hrv *_t3219 = &(g722); int64_t _i3219 = n_1082; (int32_t*)_t3219->b + hr_ix(_i3219, _t3219->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:27"); })))), g403);
(void)(({ hrv *_v3220 = &(g312); S14 _x3220 = ((S14){ .name_ = ((*({ hrv *_t3221 = &(g707); int64_t _i3221 = n_1082; (S4*)_t3221->b + hr_ix(_i3221, _t3221->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:27"); }))).s_, .node_ = ((int32_t)(n_1082)), .inst_ = ((int32_t)(i_1083)), .own_ = ((int32_t)(g403)), }); S14 *_p3220 = (S14*)hr_grow(_v3220, 1, sizeof _x3220); *_p3220 = _x3220; _p3220; }));
(void)(f198_sig_inst(i_1083));
 }
(void)(f211_check_inst(i_1083));
}
static void f211_check_inst(int64_t i_1085) {
if (((((*({ hrv *_t3224 = &(g390); int64_t _i3224 = i_1085; (S6*)_t3224->b + hr_ix(_i3224, _t3224->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:153"); }))).st_) != (((uint8_t)0LL)))) { return;
 }
int64_t node_1086 = ((int64_t)(((*({ hrv *_t3225 = &(g390); int64_t _i3225 = i_1085; (S6*)_t3225->b + hr_ix(_i3225, _t3225->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:154"); }))).node_)); 
{ uint8_t *_t3226 = &(((*({ hrv *_t3227 = &(g390); int64_t _i3227 = i_1085; (S6*)_t3227->b + hr_ix(_i3227, _t3227->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:155"); }))).st_); *_t3226 = ((uint8_t)1LL); }
if (((((uint16_t)((uint64_t)((*({ hrv *_t3228 = &(g707); int64_t _i3228 = node_1086; (S4*)_t3228->b + hr_ix(_i3228, _t3228->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:156"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { int64_t sa0_1087 = g403; 
int64_t sc0_1088 = g404; 
g403 = i_1085;
g404 = i_1085;
{ int32_t _e3230 = ((*({ hrv *_t3231 = &(g707); int64_t _i3231 = node_1086; (S4*)_t3231->b + hr_ix(_i3231, _t3231->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:156"); }))).n_; for (int32_t _k3230 = 0; _k3230 < _e3230; _k3230++) { int32_t j_1089 = (int32_t)_k3230; int64_t p_1090 = f90_kid(node_1086, ((int64_t)(j_1089))); 
if (((((*({ hrv *_t3233 = &(g707); int64_t _i3233 = p_1090; (S4*)_t3233->b + hr_ix(_i3233, _t3233->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:156"); }))).b_) >= (((int32_t)0LL)))) { int64_t pt_1093 = f212_ptype_of(i_1085, ((int64_t)(j_1089))); 
(void)(f137_ck(((int64_t)(((*({ hrv *_t3236 = &(g707); int64_t _i3236 = p_1090; (S4*)_t3236->b + hr_ix(_i3236, _t3236->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:156"); }))).b_)), pt_1093));
(void)(f140_conv(((int64_t)(((*({ hrv *_t3238 = &(g707); int64_t _i3238 = p_1090; (S4*)_t3238->b + hr_ix(_i3238, _t3238->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:156"); }))).b_)), pt_1093));
 }
 } } _bk3229:; 
g403 = sa0_1087;
g404 = sc0_1088;
{ uint8_t *_t3239 = &(((*({ hrv *_t3240 = &(g390); int64_t _i3240 = i_1085; (S6*)_t3240->b + hr_ix(_i3240, _t3240->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:156"); }))).st_); *_t3239 = ((uint8_t)2LL); }
return;
 }
int64_t sa_1094 = g403; 
int64_t sc_1095 = g404; 
int64_t sm_1096 = (g392).n; 
int64_t ld_1097 = g409; 
int64_t bt_1098 = (g471).n; 
int64_t nm0_1099 = (g312).n; 
g403 = i_1085;
g404 = i_1085;
g409 = ((int64_t)0LL);
int64_t g0_1100 = (g494).n; 
{ int32_t _e3242 = ((*({ hrv *_t3243 = &(g390); int64_t _i3243 = i_1085; (S6*)_t3243->b + hr_ix(_i3243, _t3243->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:160"); }))).gn_; for (int32_t _k3242 = 0; _k3242 < _e3242; _k3242++) { int32_t j_1101 = (int32_t)_k3242; (void)(({ hrv *_v3244 = &(g494); S7 _x3244 = (*({ hrv *_t3245 = &(g396); int64_t _i3245 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3246 = &(g390); int64_t _i3246 = i_1085; (S6*)_t3246->b + hr_ix(_i3246, _t3246->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:160"); }))).g0_)) + (int64_t)((int64_t)(j_1101)))); (S7*)_t3245->b + hr_ix(_i3245, _t3245->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:160"); })); S7 *_p3244 = (S7*)hr_grow(_v3244, 1, sizeof _x3244); *_p3244 = _x3244; _p3244; }));
 } } _bk3241:; 
{ int32_t _e3248 = ((*({ hrv *_t3249 = &(g707); int64_t _i3249 = node_1086; (S4*)_t3249->b + hr_ix(_i3249, _t3249->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:161"); }))).n_; for (int32_t _k3248 = 0; _k3248 < _e3248; _k3248++) { int32_t j_1102 = (int32_t)_k3248; int64_t p_1103 = f90_kid(node_1086, ((int64_t)(j_1102))); 
if (((((*({ hrv *_t3251 = &(g707); int64_t _i3251 = p_1103; (S4*)_t3251->b + hr_ix(_i3251, _t3251->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:161"); }))).b_) >= (((int32_t)0LL)))) { int64_t pt_1104 = f212_ptype_of(i_1085, ((int64_t)(j_1102))); 
(void)(f137_ck(((int64_t)(((*({ hrv *_t3254 = &(g707); int64_t _i3254 = p_1103; (S4*)_t3254->b + hr_ix(_i3254, _t3254->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:161"); }))).b_)), pt_1104));
(void)(f140_conv(((int64_t)(((*({ hrv *_t3256 = &(g707); int64_t _i3256 = p_1103; (S4*)_t3256->b + hr_ix(_i3256, _t3256->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:161"); }))).b_)), pt_1104));
 }
 } } _bk3247:; 
{ int32_t _e3258 = ((*({ hrv *_t3259 = &(g707); int64_t _i3259 = node_1086; (S4*)_t3259->b + hr_ix(_i3259, _t3259->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:162"); }))).n_; for (int32_t _k3258 = 0; _k3258 < _e3258; _k3258++) { int32_t j_1105 = (int32_t)_k3258; int64_t p_1106 = f90_kid(node_1086, ((int64_t)(j_1105))); 
int64_t v_1107 = f207_add_lv(((int64_t)(((*({ hrv *_t3262 = &(g707); int64_t _i3262 = p_1106; (S4*)_t3262->b + hr_ix(_i3262, _t3262->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:162"); }))).s_)), f212_ptype_of(i_1085, ((int64_t)(j_1105))), ((int64_t)((int64_t)((int64_t)4LL) | (int64_t)({ int64_t _r3264; if (((((uint16_t)((uint64_t)((*({ hrv *_t3265 = &(g707); int64_t _i3265 = p_1106; (S4*)_t3265->b + hr_ix(_i3265, _t3265->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:162"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { _r3264 = ((int64_t)1LL);  } else { _r3264 = ((int64_t)0LL);  } _r3264; }))), p_1106); 
(void)(f173_set_r(p_1106, ((int64_t)1LL), v_1107));
 } } _bk3257:; 
int64_t body_1108 = ((int64_t)(((*({ hrv *_t3267 = &(g707); int64_t _i3267 = node_1086; (S4*)_t3267->b + hr_ix(_i3267, _t3267->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:163"); }))).c_)); 
int64_t rt_1109 = ((int64_t)(((*({ hrv *_t3268 = &(g390); int64_t _i3268 = i_1085; (S6*)_t3268->b + hr_ix(_i3268, _t3268->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:164"); }))).ret_)); 
int64_t t_1110 = f137_ck(body_1108, ({ int64_t _r3270; if (((rt_1109) >= (((int64_t)0LL)))) { _r3270 = rt_1109;  } else { _r3270 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3270; })); 
int64_t tail_1111 = ((int64_t)(((*({ hrv *_t3271 = &(g707); int64_t _i3271 = body_1108; (S4*)_t3271->b + hr_ix(_i3271, _t3271->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:166"); }))).a_)); 
if (((rt_1109) >= (((int64_t)0LL)))) { if ((((((tail_1111) >= (((int64_t)0LL))) && ((rt_1109) != (g561))) && ((t_1110) != (g561))) && (!(f143_ends(tail_1111))))) { (void)(f140_conv(tail_1111, rt_1109));
 }
 } else { if (((((*({ hrv *_t3274 = &(g390); int64_t _i3274 = i_1085; (S6*)_t3274->b + hr_ix(_i3274, _t3274->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:169"); }))).ret_) < (((int32_t)0LL)))) { if ((((tail_1111) >= (((int64_t)0LL))) && ((t_1110) != (g561)))) { { int32_t *_t3275 = &(((*({ hrv *_t3276 = &(g390); int64_t _i3276 = i_1085; (S6*)_t3276->b + hr_ix(_i3276, _t3276->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:169"); }))).ret_); *_t3275 = ((int32_t)(f187_default_t(tail_1111))); }
 } else { { int32_t *_t3278 = &(((*({ hrv *_t3279 = &(g390); int64_t _i3279 = i_1085; (S6*)_t3279->b + hr_ix(_i3279, _t3279->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:169"); }))).ret_); *_t3278 = ((int32_t)(g561)); }
 }
 } else { if (((((tail_1111) >= (((int64_t)0LL))) && ((t_1110) != (g561))) && ((((int64_t)(((*({ hrv *_t3280 = &(g390); int64_t _i3280 = i_1085; (S6*)_t3280->b + hr_ix(_i3280, _t3280->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:170"); }))).ret_))) != (g561)))) { (void)(f140_conv(tail_1111, ((int64_t)(((*({ hrv *_t3282 = &(g390); int64_t _i3282 = i_1085; (S6*)_t3282->b + hr_ix(_i3282, _t3282->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:170"); }))).ret_))));
 }
 }
 }
(void)(({ hrv *_v3283 = &(g494); int64_t _k3283 = ((int64_t)((int64_t)(g494).n - (int64_t)g0_1100)); if (_k3283 < 0 || _k3283 > _v3283->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:172"); _v3283->n -= _k3283; }));
(void)(({ hrv *_v3284 = &(g392); int64_t _k3284 = ((int64_t)((int64_t)(g392).n - (int64_t)sm_1096)); if (_k3284 < 0 || _k3284 > _v3284->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); _v3284->n -= _k3284; }));
(void)(({ hrv *_v3285 = &(g312); int64_t _k3285 = ((int64_t)((int64_t)(g312).n - (int64_t)nm0_1099)); if (_k3285 < 0 || _k3285 > _v3285->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); _v3285->n -= _k3285; }));
while ((((g471).n) > (bt_1098))) { (void)(({ hrv *_v3287 = &(g471); if (!_v3287->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:174"); ((int32_t*)_v3287->b)[--_v3287->n]; }));
 } _bk3286:; 
g403 = sa_1094;
g404 = sc_1095;
g409 = ld_1097;
{ uint8_t *_t3288 = &(((*({ hrv *_t3289 = &(g390); int64_t _i3289 = i_1085; (S6*)_t3289->b + hr_ix(_i3289, _t3289->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:176"); }))).st_); *_t3288 = ((uint8_t)2LL); }
}
static int64_t f212_ptype_of(int64_t i_1091, int64_t j_1092) {
return ((int64_t)((*({ hrv *_t3290 = &(g555); int64_t _i3290 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3291 = &(g390); int64_t _i3291 = i_1091; (S6*)_t3291->b + hr_ix(_i3291, _t3291->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:151"); }))).p0_)) + (int64_t)j_1092)); (int32_t*)_t3290->b + hr_ix(_i3290, _t3290->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:151"); }))));
}
static void f213_pop_block_fns(int64_t m_1114) {
if ((((g312).n) > (m_1114))) { (void)(({ hrv *_v3292 = &(g312); int64_t _k3292 = ((int64_t)((int64_t)(g312).n - (int64_t)m_1114)); if (_k3292 < 0 || _k3292 > _v3292->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:35"); _v3292->n -= _k3292; }));
 }
}
static int64_t f214_ck_if(int64_t n_1117, int64_t want_1118) {
S4 x_1119 = (*({ hrv *_t3293 = &(g707); int64_t _i3293 = n_1117; (S4*)_t3293->b + hr_ix(_i3293, _t3293->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:527"); })); 
int64_t c_1120 = f137_ck(((int64_t)((x_1119).a_)), g562); 
(void)(f140_conv(((int64_t)((x_1119).a_)), g562));
int64_t m_1121 = (g392).n; 
int64_t nm0_1122 = (g393).n; 
(void)(f180_narrow_push(((int64_t)((x_1119).a_))));
int64_t tb_1123 = f137_ck(((int64_t)((x_1119).b_)), want_1118); 
(void)(f181_narrow_pop(nm0_1122));
(void)(({ hrv *_v3299 = &(g392); int64_t _k3299 = ((int64_t)((int64_t)(g392).n - (int64_t)m_1121)); if (_k3299 < 0 || _k3299 > _v3299->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:535"); _v3299->n -= _k3299; }));
if ((((x_1119).c_) < (((int32_t)0LL)))) { return f138_set_t(n_1117, g561);
 }
int64_t tc_1124 = f137_ck(((int64_t)((x_1119).c_)), want_1118); 
bool eb_1125 = f143_ends(((int64_t)((x_1119).b_))); 
bool ec_1126 = f143_ends(((int64_t)((x_1119).c_))); 
if ((eb_1125 && (!(ec_1126)))) { return f138_set_t(n_1117, tc_1124);
 }
if ((ec_1126 && (!(eb_1125)))) { return f138_set_t(n_1117, tb_1123);
 }
if ((eb_1125 && ec_1126)) { return f138_set_t(n_1117, tb_1123);
 }
if ((((tb_1123) == (g561)) || ((tc_1124) == (g561)))) { return f138_set_t(n_1117, g561);
 }
if (((tb_1123) == (tc_1124))) { return f138_set_t(n_1117, tb_1123);
 }
if ((((((want_1118) >= (((int64_t)0LL))) && ((want_1118) != (g561))) && (f166_is_pending(tb_1123) || f154_conv_ok(tb_1123, want_1118, ((int64_t)((x_1119).b_))))) && (f166_is_pending(tc_1124) || f154_conv_ok(tc_1124, want_1118, ((int64_t)((x_1119).c_)))))) { (void)(f140_conv(((int64_t)((x_1119).b_)), want_1118));
(void)(f140_conv(((int64_t)((x_1119).c_)), want_1118));
return f138_set_t(n_1117, want_1118);
 }
int64_t u_1127 = f185_unify(n_1117, ((int64_t)((x_1119).b_)), ((int64_t)((x_1119).c_))); 
return f138_set_t(n_1117, u_1127);
}
static int64_t f215_ck_while(int64_t n_1128) {
S4 x_1129 = (*({ hrv *_t3318 = &(g707); int64_t _i3318 = n_1128; (S4*)_t3318->b + hr_ix(_i3318, _t3318->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:549"); })); 
int64_t c_1130 = f137_ck(((int64_t)((x_1129).a_)), g562); 
(void)(f140_conv(((int64_t)((x_1129).a_)), g562));
int64_t nm0_1131 = (g393).n; 
(void)(f180_narrow_push(((int64_t)((x_1129).a_))));
g409++;
(void)(f137_ck(((int64_t)((x_1129).b_)), g561));
g409--;
(void)(f181_narrow_pop(nm0_1131));
return f138_set_t(n_1128, g561);
}
static int64_t f216_ck_loop(int64_t n_1132, int64_t want_1133) {
(void)(({ hrv *_v3325 = &(g471); int32_t _x3325 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p3325 = (int32_t*)hr_grow(_v3325, 1, sizeof _x3325); *_p3325 = _x3325; _p3325; }));
g409++;
(void)(f137_ck(((int64_t)(((*({ hrv *_t3327 = &(g707); int64_t _i3327 = n_1132; (S4*)_t3327->b + hr_ix(_i3327, _t3327->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:564"); }))).a_)), g561));
g409--;
int64_t t_1134 = ((int64_t)(({ hrv *_v3328 = &(g471); if (!_v3328->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:566"); ((int32_t*)_v3328->b)[--_v3328->n]; }))); 
return f138_set_t(n_1132, ({ int64_t _r3330; if (((t_1134) < (((int64_t)0LL)))) { _r3330 = g561;  } else { _r3330 = t_1134;  } _r3330; }));
}
static int64_t f217_ck_for(int64_t n_1135) {
S4 x_1136 = (*({ hrv *_t3331 = &(g707); int64_t _i3331 = n_1135; (S4*)_t3331->b + hr_ix(_i3331, _t3331->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:570"); })); 
int64_t m_1137 = (g392).n; 
int64_t et_1138 = g566; 
if ((((x_1136).b_) >= (((int32_t)0LL)))) { int64_t ta_1139 = f137_ck(((int64_t)((x_1136).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t tb_1140 = f137_ck(((int64_t)((x_1136).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t u_1141 = f185_unify(n_1135, ((int64_t)((x_1136).a_)), ((int64_t)((x_1136).b_))); 
et_1138 = ({ int64_t _r3335; if (((((*({ hrv *_t3336 = &(g554); int64_t _i3336 = u_1141; (S1*)_t3336->b + hr_ix(_i3336, _t3336->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:576"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1136).a_)), g566));
(void)(f140_conv(((int64_t)((x_1136).b_)), g566));
_r3335 = g566;  } else { _r3335 = u_1141;  } _r3335; });
(void)(f178_set_x(n_1135, ((int64_t)0LL)));
 } else { int64_t t_1142 = f137_ck(((int64_t)((x_1136).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3341 = &(g554); int64_t _i3341 = t_1142; (S1*)_t3341->b + hr_ix(_i3341, _t3341->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:580"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_1136).a_)), g579));
t_1142 = g579;
 }
if (((((*({ hrv *_t3343 = &(g554); int64_t _i3343 = t_1142; (S1*)_t3343->b + hr_ix(_i3343, _t3343->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:581"); }))).k_) == (((uint8_t)19LL)))) { t_1142 = f187_default_t(((int64_t)((x_1136).a_)));
 }
int64_t d_1143 = f182_deref(t_1142); 
if (((((*({ hrv *_t3346 = &(g554); int64_t _i3346 = d_1143; (S1*)_t3346->b + hr_ix(_i3346, _t3346->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:583"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1136).a_)), g566));
et_1138 = g566;
(void)(f178_set_x(n_1135, ((int64_t)0LL)));
 } else { if ((((((*({ hrv *_t3349 = &(g554); int64_t _i3349 = d_1143; (S1*)_t3349->b + hr_ix(_i3349, _t3349->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:584"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t3350 = &(g554); int64_t _i3350 = d_1143; (S1*)_t3350->b + hr_ix(_i3350, _t3350->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:584"); }))).k_) == (((uint8_t)17LL))))) { et_1138 = ({ int64_t _r3351; if (((((*({ hrv *_t3352 = &(g554); int64_t _i3352 = d_1143; (S1*)_t3352->b + hr_ix(_i3352, _t3352->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:584"); }))).k_) == (((uint8_t)17LL)))) { _r3351 = g566;  } else { _r3351 = d_1143;  } _r3351; });
if (((et_1138) != (t_1142))) { (void)(f145_set_cv(((int64_t)((x_1136).a_)), et_1138));
 }
(void)(f178_set_x(n_1135, ((int64_t)0LL)));
 } else { if ((((((*({ hrv *_t3355 = &(g554); int64_t _i3355 = d_1143; (S1*)_t3355->b + hr_ix(_i3355, _t3355->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:585"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3356 = &(g554); int64_t _i3356 = d_1143; (S1*)_t3356->b + hr_ix(_i3356, _t3356->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:585"); }))).k_) == (((uint8_t)9LL))))) { et_1138 = f191_decode_rel(((int64_t)(((*({ hrv *_t3358 = &(g554); int64_t _i3358 = d_1143; (S1*)_t3358->b + hr_ix(_i3358, _t3358->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:585"); }))).a_)));
(void)(f178_set_x(n_1135, ((int64_t)1LL)));
 } else { hrv mm_1144 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t3362 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o3361 = &(mm_1144); hr_fs(_o3361, hr_str("cannot iterate over ", 20)); hr_fs(_o3361, hr_sl(*hr_tmp(&_t3362, f164_tn(d_1143)))); }));
}
(void)(f108_cerr(n_1135, hr_sl(mm_1144)));
 }
 }
 }
 }
if ((((x_1136).l_) >= (((int32_t)0LL)))) { et_1138 = f113_rtype(((int64_t)((x_1136).l_)), f110_ns_of(n_1135));
 }
bool byref_1146 = (((((uint16_t)((uint64_t)(x_1136).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || f218_is_bytes(et_1138)); 
int64_t v_1147 = f207_add_lv(((int64_t)((x_1136).s_)), ({ int64_t _r3369; if (byref_1146) { _r3369 = f119_t_ref(et_1138, ((int64_t)0LL));  } else { _r3369 = et_1138;  } _r3369; }), ((int64_t)((int64_t)((int64_t)16LL) | (int64_t)({ int64_t _r3371; if (byref_1146) { _r3371 = ((int64_t)8LL);  } else { _r3371 = ((int64_t)0LL);  } _r3371; }))), n_1135); 
(void)(f173_set_r(n_1135, ((int64_t)1LL), v_1147));
if ((((x_1136).c_) >= (((int32_t)0LL)))) { int64_t iv_1148 = f207_add_lv(((int64_t)((x_1136).c_)), ({ int64_t _r3374; if ((((x_1136).n_) >= (((int32_t)0LL)))) { _r3374 = f113_rtype(((int64_t)((x_1136).n_)), f110_ns_of(n_1135));  } else { _r3374 = g566;  } _r3374; }), ((int64_t)16LL), n_1135); 
(void)(f178_set_x(n_1135, ((int64_t)((int64_t)f219_ax(n_1135) | (int64_t)((int64_t)((iv_1148) << ((((int64_t)2LL)) & 63)))))));
 }
g409++;
(void)(f137_ck(((int64_t)((x_1136).d_)), g561));
g409--;
(void)(({ hrv *_v3380 = &(g392); int64_t _k3380 = ((int64_t)((int64_t)(g392).n - (int64_t)m_1137)); if (_k3380 < 0 || _k3380 > _v3380->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:596"); _v3380->n -= _k3380; }));
return f138_set_t(n_1135, g561);
}
static bool f218_is_bytes(int64_t t_1145) {
return ((((f146_tclass(t_1145)) == (((int64_t)1LL))) && ((((*({ hrv *_t3383 = &(g554); int64_t _i3383 = t_1145; (S1*)_t3383->b + hr_ix(_i3383, _t3383->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:93"); }))).k_) != (((uint8_t)17LL)))) && ((((*({ hrv *_t3384 = &(g554); int64_t _i3384 = t_1145; (S1*)_t3384->b + hr_ix(_i3384, _t3384->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:93"); }))).k_) != (((uint8_t)10LL))));
}
static int64_t f219_ax(int64_t n_1149) {
return ((int64_t)((*({ hrv *_t3385 = &(g401); int64_t _i3385 = f139_aix(n_1149); (int32_t*)_t3385->b + hr_ix(_i3385, _t3385->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:47"); }))));
}
static int64_t f220_ck_match(int64_t n_1150, int64_t want_1151) {
S4 x_1152 = (*({ hrv *_t3387 = &(g707); int64_t _i3387 = n_1150; (S4*)_t3387->b + hr_ix(_i3387, _t3387->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:600"); })); 
int64_t st_1153 = f137_ck(((int64_t)((x_1152).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3389 = &(g554); int64_t _i3389 = st_1153; (S1*)_t3389->b + hr_ix(_i3389, _t3389->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:602"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1152).a_)), g566));
st_1153 = g566;
 }
if (((((*({ hrv *_t3391 = &(g554); int64_t _i3391 = st_1153; (S1*)_t3391->b + hr_ix(_i3391, _t3391->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:603"); }))).k_) == (((uint8_t)7LL)))) { st_1153 = f136_t_enum(((int64_t)(((*({ hrv *_t3393 = &(g554); int64_t _i3393 = st_1153; (S1*)_t3393->b + hr_ix(_i3393, _t3393->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:603"); }))).a_)), false);
(void)(f145_set_cv(((int64_t)((x_1152).a_)), st_1153));
 }
int64_t d_1154 = f182_deref(st_1153); 
int64_t rt_1155 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
bool allv_1156 = true; 
{ int32_t _e3397 = (x_1152).n_; for (int32_t _k3397 = 0; _k3397 < _e3397; _k3397++) { int32_t i_1157 = (int32_t)_k3397; int64_t arm_1158 = f90_kid(n_1150, ((int64_t)(i_1157))); 
int64_t m_1159 = (g392).n; 
S4 ax0_1160 = (*({ hrv *_t3399 = &(g707); int64_t _i3399 = arm_1158; (S4*)_t3399->b + hr_ix(_i3399, _t3399->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:610"); })); 
if (((((uint16_t)((uint64_t)(ax0_1160).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) { { int32_t _e3401 = (ax0_1160).n_; for (int32_t _k3401 = 0; _k3401 < _e3401; _k3401++) { int32_t j_1161 = (int32_t)_k3401; int64_t it_1162 = f90_kid(arm_1158, ((int64_t)(j_1161))); 
int64_t lo_1163 = ((int64_t)(((*({ hrv *_t3403 = &(g707); int64_t _i3403 = it_1162; (S4*)_t3403->b + hr_ix(_i3403, _t3403->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:614"); }))).a_)); 
if ((((((*({ hrv *_t3404 = &(g554); int64_t _i3404 = d_1154; (S1*)_t3404->b + hr_ix(_i3404, _t3404->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:615"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t3405 = &(g707); int64_t _i3405 = lo_1163; (S4*)_t3405->b + hr_ix(_i3405, _t3405->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:615"); }))).k_) == (((uint8_t)8LL))))) { int64_t ei_1164 = ((int64_t)(((*({ hrv *_t3406 = &(g554); int64_t _i3406 = d_1154; (S1*)_t3406->b + hr_ix(_i3406, _t3406->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:616"); }))).a_)); 
int64_t found_1165 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e3408 = ((*({ hrv *_t3409 = &(g559); int64_t _i3409 = ei_1164; (S8*)_t3409->b + hr_ix(_i3409, _t3409->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:618"); }))).vnum_; for (int32_t _k3408 = 0; _k3408 < _e3408; _k3408++) { int32_t q_1166 = (int32_t)_k3408; if (((((*({ hrv *_t3410 = &(g560); int64_t _i3410 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3411 = &(g559); int64_t _i3411 = ei_1164; (S8*)_t3411->b + hr_ix(_i3411, _t3411->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:618"); }))).v0_)) + (int64_t)((int64_t)(q_1166)))); (S9*)_t3410->b + hr_ix(_i3410, _t3410->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:618"); }))).name_) == (((*({ hrv *_t3412 = &(g707); int64_t _i3412 = lo_1163; (S4*)_t3412->b + hr_ix(_i3412, _t3412->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:618"); }))).s_))) { found_1165 = ((int64_t)(q_1166));
 }
 } } _bk3407:; 
if (((found_1165) < (((int64_t)0LL)))) { hrv mm_1167 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t3417 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o3414 = &(mm_1167); hr_fs(_o3414, hr_str("no variant ", 11)); hr_fs(_o3414, f10_nm(((int64_t)(((*({ hrv *_t3416 = &(g707); int64_t _i3416 = lo_1163; (S4*)_t3416->b + hr_ix(_i3416, _t3416->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:619"); }))).s_)))); hr_fs(_o3414, hr_str(" in ", 4)); hr_fs(_o3414, hr_sl(*hr_tmp(&_t3417, f164_tn(d_1154)))); }));
}
(void)(f108_cerr(lo_1163, hr_sl(mm_1167)));
 }
(void)(f173_set_r(lo_1163, ((int64_t)7LL), found_1165));
(void)(f138_set_t(lo_1163, d_1154));
if (((((ax0_1160).s_) >= (((int32_t)0LL))) && ((found_1165) >= (((int64_t)0LL))))) { int64_t vt_1168 = f125_t_variant(ei_1164, found_1165); 
bool byr_1169 = (((((uint16_t)((uint64_t)(ax0_1160).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))) || f218_is_bytes(vt_1168)); 
int64_t v_1170 = f207_add_lv(((int64_t)((ax0_1160).s_)), ({ int64_t _r3425; if (byr_1169) { _r3425 = f119_t_ref(vt_1168, ((int64_t)0LL));  } else { _r3425 = vt_1168;  } _r3425; }), ({ int64_t _r3427; if (byr_1169) { _r3427 = ((int64_t)8LL);  } else { _r3427 = ((int64_t)0LL);  } _r3427; }), arm_1158); 
(void)(f173_set_r(arm_1158, ((int64_t)1LL), v_1170));
 }
 } else { (void)(f137_ck(lo_1163, d_1154));
(void)(f140_conv(lo_1163, d_1154));
if (((((*({ hrv *_t3431 = &(g707); int64_t _i3431 = it_1162; (S4*)_t3431->b + hr_ix(_i3431, _t3431->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:624"); }))).b_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)(((*({ hrv *_t3433 = &(g707); int64_t _i3433 = it_1162; (S4*)_t3433->b + hr_ix(_i3433, _t3433->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:624"); }))).b_)), d_1154));
(void)(f140_conv(((int64_t)(((*({ hrv *_t3435 = &(g707); int64_t _i3435 = it_1162; (S4*)_t3435->b + hr_ix(_i3435, _t3435->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:624"); }))).b_)), d_1154));
 }
 }
 } } _bk3400:; 
 }
int64_t bt_1171 = f137_ck(((int64_t)((ax0_1160).b_)), want_1151); 
(void)(({ hrv *_v3437 = &(g392); int64_t _k3437 = ((int64_t)((int64_t)(g392).n - (int64_t)m_1159)); if (_k3437 < 0 || _k3437 > _v3437->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:629"); _v3437->n -= _k3437; }));
if (((bt_1171) == (g561))) { allv_1156 = false;
 } else { if ((!(f143_ends(((int64_t)((ax0_1160).b_)))))) { if ((((rt_1155) < (((int64_t)0LL))) || f166_is_pending(rt_1155))) { rt_1155 = bt_1171;
 }
 }
 }
 } } _bk3396:; 
if (((!(allv_1156)) || ((rt_1155) < (((int64_t)0LL))))) { return f138_set_t(n_1150, g561);
 }
bool allw_1172 = (((want_1151) >= (((int64_t)0LL))) && ((want_1151) != (g561))); 
if (allw_1172) { { int32_t _e3442 = (x_1152).n_; for (int32_t _k3442 = 0; _k3442 < _e3442; _k3442++) { int32_t i_1173 = (int32_t)_k3442; int64_t b_1174 = ((int64_t)(((*({ hrv *_t3443 = &(g707); int64_t _i3443 = f90_kid(n_1150, ((int64_t)(i_1173))); (S4*)_t3443->b + hr_ix(_i3443, _t3443->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:634"); }))).b_)); 
int64_t bt_1175 = f141_at(b_1174); 
if ((((!(f143_ends(b_1174))) && (!(f166_is_pending(bt_1175)))) && (!(f154_conv_ok(bt_1175, want_1151, b_1174))))) { allw_1172 = false;
 }
 } } _bk3441:; 
 }
if (allw_1172) { { int32_t _e3450 = (x_1152).n_; for (int32_t _k3450 = 0; _k3450 < _e3450; _k3450++) { int32_t i_1176 = (int32_t)_k3450; int64_t b_1177 = ((int64_t)(((*({ hrv *_t3451 = &(g707); int64_t _i3451 = f90_kid(n_1150, ((int64_t)(i_1176))); (S4*)_t3451->b + hr_ix(_i3451, _t3451->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:635"); }))).b_)); 
if ((!(f143_ends(b_1177)))) { (void)(f140_conv(b_1177, want_1151));
 }
 } } _bk3449:; 
return f138_set_t(n_1150, want_1151);
 }
if (f166_is_pending(rt_1155)) { { int32_t _e3458 = (x_1152).n_; for (int32_t _k3458 = 0; _k3458 < _e3458; _k3458++) { int32_t i_1178 = (int32_t)_k3458; int64_t b_1179 = ((int64_t)(((*({ hrv *_t3459 = &(g707); int64_t _i3459 = f90_kid(n_1150, ((int64_t)(i_1178))); (S4*)_t3459->b + hr_ix(_i3459, _t3459->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:636"); }))).b_)); 
int64_t bt_1180 = f141_at(b_1179); 
if (((!(f166_is_pending(bt_1180))) && (!(f143_ends(b_1179))))) { rt_1155 = bt_1180;
 }
 } } _bk3457:; 
 }
if (f166_is_pending(rt_1155)) { int64_t b_1181 = ((int64_t)(((*({ hrv *_t3465 = &(g707); int64_t _i3465 = f90_kid(n_1150, ((int64_t)0LL)); (S4*)_t3465->b + hr_ix(_i3465, _t3465->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:637"); }))).b_)); 
rt_1155 = f187_default_t(b_1181);
 }
{ int32_t _e3469 = (x_1152).n_; for (int32_t _k3469 = 0; _k3469 < _e3469; _k3469++) { int32_t i_1182 = (int32_t)_k3469; int64_t b_1183 = ((int64_t)(((*({ hrv *_t3470 = &(g707); int64_t _i3470 = f90_kid(n_1150, ((int64_t)(i_1182))); (S4*)_t3470->b + hr_ix(_i3470, _t3470->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:638"); }))).b_)); 
if ((!(f143_ends(b_1183)))) { (void)(f140_conv(b_1183, rt_1155));
 }
 } } _bk3468:; 
return f138_set_t(n_1150, rt_1155);
}
static int64_t f221_ck_ret(int64_t n_1184) {
S4 x_1185 = (*({ hrv *_t3475 = &(g707); int64_t _i3475 = n_1184; (S4*)_t3475->b + hr_ix(_i3475, _t3475->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:650"); })); 
int64_t f_1189 = ({ int64_t _r3476; if ((((x_1185).s_) >= (((int32_t)0LL)))) { _r3476 = f222_find_from_fn(((int64_t)((x_1185).s_)));  } else { _r3476 = f223_ret_fn();  } _r3476; }); 
if (((f_1189) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1184, hr_str("return outside a function", 25)));
return g561;
 }
if (((f_1189) != (g404))) { { bool *_t3480 = &(((*({ hrv *_t3481 = &(g390); int64_t _i3481 = g404; (S6*)_t3481->b + hr_ix(_i3481, _t3481->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:653"); }))).lr_); *_t3480 = true; }
{ bool *_t3482 = &(((*({ hrv *_t3483 = &(g390); int64_t _i3483 = f_1189; (S6*)_t3483->b + hr_ix(_i3483, _t3483->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:653"); }))).tg_); *_t3482 = true; }
(void)(f178_set_x(n_1184, f_1189));
 } else { (void)(f178_set_x(n_1184, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
int64_t rt_1190 = ((int64_t)(((*({ hrv *_t3486 = &(g390); int64_t _i3486 = f_1189; (S6*)_t3486->b + hr_ix(_i3486, _t3486->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:654"); }))).ret_)); 
if ((((x_1185).n_) == (((int32_t)0LL)))) { if (((((rt_1190) >= (((int64_t)0LL))) && ((rt_1190) != (g561))) && (!(((*({ hrv *_t3487 = &(g390); int64_t _i3487 = f_1189; (S6*)_t3487->b + hr_ix(_i3487, _t3487->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:655"); }))).rinf_)))) { (void)(f108_cerr(n_1184, hr_str("return needs a value", 20)));
 }
if (((rt_1190) < (((int64_t)0LL)))) { { int32_t *_t3489 = &(((*({ hrv *_t3490 = &(g390); int64_t _i3490 = f_1189; (S6*)_t3490->b + hr_ix(_i3490, _t3490->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:655"); }))).ret_); *_t3489 = ((int32_t)(g561)); }
 }
return f138_set_t(n_1184, g561);
 }
if (((((rt_1190) >= (((int64_t)0LL))) && ((((*({ hrv *_t3492 = &(g554); int64_t _i3492 = rt_1190; (S1*)_t3492->b + hr_ix(_i3492, _t3492->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:656"); }))).k_) == (((uint8_t)14LL)))) && (((x_1185).n_) == (((int32_t)1LL))))) { int64_t c_1191 = f90_kid(n_1184, ((int64_t)0LL)); 
(void)(f137_ck(c_1191, rt_1190));
return f138_set_t(n_1184, g561);
 }
if ((((x_1185).n_) > (((int32_t)1LL)))) { if (((rt_1190) < (((int64_t)0LL)))) { L89 ts_1192 = ({ L89 _t3496; memset(&_t3496, 0, sizeof _t3496); _t3496.n = 0; _t3496; }); 
{ int32_t _e3498 = (x_1185).n_; for (int32_t _k3498 = 0; _k3498 < _e3498; _k3498++) { int32_t i_1193 = (int32_t)_k3498; (void)(f137_ck(f90_kid(n_1184, ((int64_t)(i_1193))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
int64_t dt0_1194 = f187_default_t(f90_kid(n_1184, ((int64_t)(i_1193)))); 
(void)(({ L89 *_v3503 = &(ts_1192); int32_t _x3503 = ((int32_t)(dt0_1194)); if (_v3503->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:658"); _v3503->e[_v3503->n] = _x3503; &_v3503->e[_v3503->n++]; }));
 } } _bk3497:; 
{ int32_t *_t3504 = &(((*({ hrv *_t3505 = &(g390); int64_t _i3505 = f_1189; (S6*)_t3505->b + hr_ix(_i3505, _t3505->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:658"); }))).ret_); *_t3504 = ((int32_t)(f200_tlist(((int64_t)14LL), ({ hsl _t3507 = ({ L89 *_t3508 = &(ts_1192); (hsl){ (uint8_t*)_t3508->e, _t3508->n }; }); int64_t _l3507 = 0, _h3507 = _t3507.n; if (_l3507 < 0 || _h3507 < _l3507 || _h3507 > _t3507.n) hr_slerr(_l3507, _h3507, _t3507.n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:658"); (hsl){ _t3507.p + _l3507 * (int64_t)sizeof(int32_t), _h3507 - _l3507 }; }), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); }
return f138_set_t(n_1184, g561);
 }
{ int32_t _e3511 = (x_1185).n_; for (int32_t _k3511 = 0; _k3511 < _e3511; _k3511++) { int32_t i_1195 = (int32_t)_k3511; int64_t et_1196 = ({ int64_t _r3512; if ((((((*({ hrv *_t3513 = &(g554); int64_t _i3513 = rt_1190; (S1*)_t3513->b + hr_ix(_i3513, _t3513->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:659"); }))).k_) == (((uint8_t)14LL))) && ((((int64_t)(i_1195))) < (((int64_t)(((*({ hrv *_t3514 = &(g554); int64_t _i3514 = rt_1190; (S1*)_t3514->b + hr_ix(_i3514, _t3514->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:659"); }))).n_)))))) { _r3512 = ((int64_t)((*({ hrv *_t3515 = &(g555); int64_t _i3515 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3516 = &(g554); int64_t _i3516 = rt_1190; (S1*)_t3516->b + hr_ix(_i3516, _t3516->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:659"); }))).l_)) + (int64_t)((int64_t)(i_1195)))); (int32_t*)_t3515->b + hr_ix(_i3515, _t3515->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:659"); }))));  } else { _r3512 = g578;  } _r3512; }); 
(void)(f137_ck(f90_kid(n_1184, ((int64_t)(i_1195))), et_1196));
(void)(f140_conv(f90_kid(n_1184, ((int64_t)(i_1195))), et_1196));
 } } _bk3510:; 
return f138_set_t(n_1184, g561);
 }
int64_t c_1197 = f90_kid(n_1184, ((int64_t)0LL)); 
if (((rt_1190) < (((int64_t)0LL)))) { (void)(f137_ck(c_1197, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
int64_t t_1198 = f187_default_t(c_1197); 
{ int32_t *_t3525 = &(((*({ hrv *_t3526 = &(g390); int64_t _i3526 = f_1189; (S6*)_t3526->b + hr_ix(_i3526, _t3526->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:663"); }))).ret_); *_t3525 = ((int32_t)(t_1198)); }
return f138_set_t(n_1184, g561);
 }
(void)(f137_ck(c_1197, rt_1190));
(void)(f140_conv(c_1197, rt_1190));
return f138_set_t(n_1184, g561);
}
static int64_t f222_find_from_fn(int64_t name_1186) {
int64_t i_1187 = g403; 
while (((i_1187) >= (((int64_t)0LL)))) { if (((((((*({ hrv *_t3532 = &(g390); int64_t _i3532 = i_1187; (S6*)_t3532->b + hr_ix(_i3532, _t3532->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:644"); }))).node_) >= (((int32_t)0LL))) && ((((*({ hrv *_t3533 = &(g707); int64_t _i3533 = ((*({ hrv *_t3534 = &(g390); int64_t _i3534 = i_1187; (S6*)_t3534->b + hr_ix(_i3534, _t3534->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:644"); }))).node_; (S4*)_t3533->b + hr_ix(_i3533, _t3533->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:644"); }))).k_) == (((uint8_t)50LL)))) && ((((int64_t)(((*({ hrv *_t3535 = &(g390); int64_t _i3535 = i_1187; (S6*)_t3535->b + hr_ix(_i3535, _t3535->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:644"); }))).name_))) == (name_1186)))) { return i_1187;
 }
i_1187 = ({ int64_t _r3536; if (((((*({ hrv *_t3537 = &(g390); int64_t _i3537 = i_1187; (S6*)_t3537->b + hr_ix(_i3537, _t3537->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:645"); }))).bown_) >= (((int32_t)0LL)))) { _r3536 = ((int64_t)(((*({ hrv *_t3538 = &(g390); int64_t _i3538 = i_1187; (S6*)_t3538->b + hr_ix(_i3538, _t3538->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:645"); }))).bown_));  } else { _r3536 = ((int64_t)(((*({ hrv *_t3539 = &(g390); int64_t _i3539 = i_1187; (S6*)_t3539->b + hr_ix(_i3539, _t3539->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:645"); }))).par_));  } _r3536; });
 } _bk3531:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f223_ret_fn(void) {
int64_t i_1188 = g403; 
while (((i_1188) >= (((int64_t)0LL)))) { if ((((((*({ hrv *_t3541 = &(g390); int64_t _i3541 = i_1188; (S6*)_t3541->b + hr_ix(_i3541, _t3541->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:667"); }))).node_) >= (((int32_t)0LL))) && ((((*({ hrv *_t3542 = &(g707); int64_t _i3542 = ((*({ hrv *_t3543 = &(g390); int64_t _i3543 = i_1188; (S6*)_t3543->b + hr_ix(_i3543, _t3543->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:667"); }))).node_; (S4*)_t3542->b + hr_ix(_i3542, _t3542->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:667"); }))).k_) == (((uint8_t)50LL))))) { return i_1188;
 }
i_1188 = ((int64_t)(((*({ hrv *_t3544 = &(g390); int64_t _i3544 = i_1188; (S6*)_t3544->b + hr_ix(_i3544, _t3544->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:667"); }))).par_));
 } _bk3540:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f224_ck_break(int64_t n_1199) {
S4 x_1200 = (*({ hrv *_t3545 = &(g707); int64_t _i3545 = n_1199; (S4*)_t3545->b + hr_ix(_i3545, _t3545->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:669"); })); 
if ((((x_1200).a_) >= (((int32_t)0LL)))) { if ((((g471).n) == (((int64_t)0LL)))) { (void)(f108_cerr(n_1199, hr_str("break with a value outside loop or block", 40)));
return g561;
 }
int64_t w_1201 = ((int64_t)((*({ hrv *_t3547 = &(g471); int64_t _i3547 = ((int64_t)((int64_t)(g471).n - (int64_t)((int64_t)1LL))); (int32_t*)_t3547->b + hr_ix(_i3547, _t3547->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:672"); })))); 
int64_t t_1202 = f137_ck(((int64_t)((x_1200).a_)), ({ int64_t _r3549; if (((w_1201) >= (((int64_t)0LL)))) { _r3549 = w_1201;  } else { _r3549 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3549; })); 
if (((w_1201) < (((int64_t)0LL)))) { { int32_t *_t3550 = &((*({ hrv *_t3551 = &(g471); int64_t _i3551 = ((int64_t)((int64_t)(g471).n - (int64_t)((int64_t)1LL))); (int32_t*)_t3551->b + hr_ix(_i3551, _t3551->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:674"); }))); *_t3550 = ((int32_t)(f187_default_t(((int64_t)((x_1200).a_))))); }
 } else { (void)(f140_conv(((int64_t)((x_1200).a_)), w_1201));
 }
 }
return f138_set_t(n_1199, g561);
}
static int64_t f225_ck_call(int64_t n_1203, int64_t want_1204) {
S4 x_1205 = (*({ hrv *_t3555 = &(g707); int64_t _i3555 = n_1203; (S4*)_t3555->b + hr_ix(_i3555, _t3555->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:263"); })); 
int64_t cal_1206 = ((int64_t)((x_1205).a_)); 
int64_t ck__1207 = ((int64_t)(((*({ hrv *_t3556 = &(g707); int64_t _i3556 = cal_1206; (S4*)_t3556->b + hr_ix(_i3556, _t3556->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:265"); }))).k_)); 
if (((ck__1207) == (((int64_t)8LL)))) { int64_t name_1208 = ((int64_t)(((*({ hrv *_t3557 = &(g707); int64_t _i3557 = cal_1206; (S4*)_t3557->b + hr_ix(_i3557, _t3557->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:267"); }))).s_)); 
int64_t v_1209 = f170_find_lv(name_1208); 
int64_t nf_1212 = f226_find_nest(name_1208); 
if ((((v_1209) < (((int64_t)0LL))) && ((nf_1212) >= (((int64_t)0LL))))) { return f227_call_nested(n_1203, nf_1212);
 }
if (((v_1209) < (((int64_t)0LL)))) { int64_t bg_1249 = f232_block_binding(name_1208); 
if (((bg_1249) >= (((int64_t)0LL)))) { return f237_call_block(n_1203, bg_1249);
 }
int64_t b_1279 = f239_builtin_of(f10_nm(name_1208)); 
if (((((b_1279) >= (((int64_t)0LL))) && (!((((b_1279) == (((int64_t)3LL))) && f240_user_format(n_1203))))) && (!((((b_1279) == (((int64_t)9LL))) && false))))) { return f242_ck_builtin(n_1203, b_1279, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), want_1204);
 }
return f256_call_fn(n_1203, name_1208, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), want_1204);
 }
 }
if (((ck__1207) == (((int64_t)14LL)))) { int64_t obj_1460 = ((int64_t)(((*({ hrv *_t3568 = &(g707); int64_t _i3568 = cal_1206; (S4*)_t3568->b + hr_ix(_i3568, _t3568->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:280"); }))).a_)); 
int64_t name_1461 = ((int64_t)(((*({ hrv *_t3569 = &(g707); int64_t _i3569 = cal_1206; (S4*)_t3569->b + hr_ix(_i3569, _t3569->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:281"); }))).s_)); 
if ((((((((*({ hrv *_t3570 = &(g707); int64_t _i3570 = obj_1460; (S4*)_t3570->b + hr_ix(_i3570, _t3570->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:282"); }))).k_) == (((uint8_t)8LL))) && ((f170_find_lv(((int64_t)(((*({ hrv *_t3572 = &(g707); int64_t _i3572 = obj_1460; (S4*)_t3572->b + hr_ix(_i3572, _t3572->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:282"); }))).s_)))) < (((int64_t)0LL)))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t3574 = &(g707); int64_t _i3574 = obj_1460; (S4*)_t3574->b + hr_ix(_i3574, _t3574->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:282"); }))).s_)), f110_ns_of(obj_1460), ((int64_t)2LL))) >= (((int64_t)0LL)))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t3577 = &(g707); int64_t _i3577 = obj_1460; (S4*)_t3577->b + hr_ix(_i3577, _t3577->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:282"); }))).s_)), f110_ns_of(obj_1460), ((int64_t)5LL))) < (((int64_t)0LL))))) { (void)(f108_cerr(n_1203, hr_str("a variant is constructed with { }", 33)));
return f138_set_t(n_1203, g578);
 }
int64_t ot_1462 = f137_ck(obj_1460, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3582 = &(g554); int64_t _i3582 = ot_1462; (S1*)_t3582->b + hr_ix(_i3582, _t3582->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:284"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(obj_1460, g579));
ot_1462 = g579;
 }
int64_t d_1463 = f182_deref(ot_1462); 
int64_t mb_1465 = f257_member_of(f10_nm(name_1461)); 
if ((((mb_1465) >= (((int64_t)0LL))) && (((((*({ hrv *_t3587 = &(g554); int64_t _i3587 = d_1463; (S1*)_t3587->b + hr_ix(_i3587, _t3587->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:287"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3588 = &(g554); int64_t _i3588 = d_1463; (S1*)_t3588->b + hr_ix(_i3588, _t3588->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:287"); }))).k_) == (((uint8_t)9LL)))))) { return f242_ck_builtin(n_1203, mb_1465, obj_1460, want_1204);
 }
if (((((((*({ hrv *_t3590 = &(g554); int64_t _i3590 = ot_1462; (S1*)_t3590->b + hr_ix(_i3590, _t3590->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:288"); }))).k_) == (((uint8_t)19LL))) || ((((*({ hrv *_t3591 = &(g554); int64_t _i3591 = ot_1462; (S1*)_t3591->b + hr_ix(_i3591, _t3591->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:288"); }))).k_) == (((uint8_t)12LL)))) || ((((*({ hrv *_t3592 = &(g554); int64_t _i3592 = ot_1462; (S1*)_t3592->b + hr_ix(_i3592, _t3592->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:288"); }))).k_) == (((uint8_t)13LL))))) { (void)(f187_default_t(obj_1460));
 }
int64_t b_1466 = f239_builtin_of(f10_nm(name_1461)); 
if ((((((b_1466) == (((int64_t)3LL))) || ((b_1466) == (((int64_t)30LL)))) || ((b_1466) == (((int64_t)31LL)))) || ((b_1466) == (((int64_t)7LL))))) { return f242_ck_builtin(n_1203, b_1466, obj_1460, want_1204);
 }
(void)(f178_set_x(n_1203, ((int64_t)1LL)));
return f256_call_fn(n_1203, name_1461, obj_1460, want_1204);
 }
(void)(f108_cerr(n_1203, hr_str("this call's callee is not supported yet", 39)));
return f138_set_t(n_1203, g578);
}
static int64_t f226_find_nest(int64_t name_1210) {
int64_t i_1211 = ((int64_t)((int64_t)(g312).n - (int64_t)((int64_t)1LL))); 
while (((i_1211) >= (((int64_t)0LL)))) { if ((((((int64_t)(((*({ hrv *_t3602 = &(g312); int64_t _i3602 = i_1211; (S14*)_t3602->b + hr_ix(_i3602, _t3602->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:23"); }))).name_))) == (name_1210)) && f171_visible(((int64_t)(((*({ hrv *_t3604 = &(g312); int64_t _i3604 = i_1211; (S14*)_t3604->b + hr_ix(_i3604, _t3604->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:23"); }))).own_))))) { return i_1211;
 }
i_1211--;
 } _bk3601:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f227_call_nested(int64_t n_1213, int64_t nf_1214) {
int64_t i_1215 = ((int64_t)(((*({ hrv *_t3605 = &(g312); int64_t _i3605 = nf_1214; (S14*)_t3605->b + hr_ix(_i3605, _t3605->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:379"); }))).inst_)); 
int64_t s_1222 = f228_ck_args(n_1213, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
{ int32_t _e3608 = ((*({ hrv *_t3609 = &(g707); int64_t _i3609 = n_1213; (S4*)_t3609->b + hr_ix(_i3609, _t3609->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:381"); }))).n_; for (int32_t _k3608 = 0; _k3608 < _e3608; _k3608++) { int32_t j_1223 = (int32_t)_k3608; int64_t c_1224 = f90_kid(n_1213, ((int64_t)(j_1223))); 
if (((((int64_t)(j_1223))) < (((int64_t)(((*({ hrv *_t3611 = &(g390); int64_t _i3611 = i_1215; (S6*)_t3611->b + hr_ix(_i3611, _t3611->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:381"); }))).pn_))))) { (void)(f140_conv(c_1224, f212_ptype_of(i_1215, ((int64_t)(j_1223)))));
 }
 } } _bk3607:; 
(void)(f229_pop_args(s_1222));
(void)(f230_note_caps_of(i_1215));
(void)(f231_note_edge(i_1215));
(void)(f173_set_r(n_1213, ((int64_t)3LL), i_1215));
return f138_set_t(n_1213, ({ int64_t _r3619; if (((((*({ hrv *_t3620 = &(g390); int64_t _i3620 = i_1215; (S6*)_t3620->b + hr_ix(_i3620, _t3620->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:385"); }))).ret_) >= (((int32_t)0LL)))) { _r3619 = ((int64_t)(((*({ hrv *_t3621 = &(g390); int64_t _i3621 = i_1215; (S6*)_t3621->b + hr_ix(_i3621, _t3621->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:385"); }))).ret_));  } else { _r3619 = g561;  } _r3619; }));
}
static int64_t f228_ck_args(int64_t n_1216, int64_t a0n_1217, int64_t first_1218) {
int64_t start_1219 = (g410).n; 
if (((first_1218) >= (((int64_t)0LL)))) { (void)(({ hrv *_v3622 = &(g410); int32_t _x3622 = ((int32_t)(f141_at(first_1218))); int32_t *_p3622 = (int32_t*)hr_grow(_v3622, 1, sizeof _x3622); *_p3622 = _x3622; _p3622; }));
(void)(({ hrv *_v3624 = &(g316); int32_t _x3624 = ((int32_t)(first_1218)); int32_t *_p3624 = (int32_t*)hr_grow(_v3624, 1, sizeof _x3624); *_p3624 = _x3624; _p3624; }));
 }
{ int32_t _e3626 = ((*({ hrv *_t3627 = &(g707); int64_t _i3627 = n_1216; (S4*)_t3627->b + hr_ix(_i3627, _t3627->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:258"); }))).n_; for (int32_t _k3626 = 0; _k3626 < _e3626; _k3626++) { int32_t i_1220 = (int32_t)_k3626; int64_t c_1221 = f90_kid(n_1216, ((int64_t)(i_1220))); 
(void)(({ hrv *_v3629 = &(g410); int32_t _x3629 = ((int32_t)(f137_ck(c_1221, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p3629 = (int32_t*)hr_grow(_v3629, 1, sizeof _x3629); *_p3629 = _x3629; _p3629; }));
(void)(({ hrv *_v3631 = &(g316); int32_t _x3631 = ((int32_t)(c_1221)); int32_t *_p3631 = (int32_t*)hr_grow(_v3631, 1, sizeof _x3631); *_p3631 = _x3631; _p3631; }));
 } } _bk3625:; 
return start_1219;
}
static void f229_pop_args(int64_t s_1225) {
(void)(({ hrv *_v3632 = &(g410); int64_t _k3632 = ((int64_t)((int64_t)(g410).n - (int64_t)s_1225)); if (_k3632 < 0 || _k3632 > _v3632->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:261"); _v3632->n -= _k3632; }));
(void)(({ hrv *_v3633 = &(g316); int64_t _k3633 = ((int64_t)((int64_t)(g316).n - (int64_t)s_1225)); if (_k3633 < 0 || _k3633 > _v3633->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:261"); _v3633->n -= _k3633; }));
}
static void f230_note_caps_of(int64_t i_1226) {
{ hrv *_v3635 = &(g394); for (int64_t _k3635 = 0; _k3635 < _v3635->n; _k3635++) { S13 c_1227 = ((S13*)_v3635->b)[_k3635]; if (((((int64_t)((c_1227).inst_))) == (i_1226))) { int64_t v_1228 = ((int64_t)((c_1227).lv_)); 
if (((((int64_t)(((*({ hrv *_t3636 = &(g391); int64_t _i3636 = v_1228; (S12*)_t3636->b + hr_ix(_i3636, _t3636->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:388"); }))).cfn_))) != (g404))) { (void)(f174_note_cap(v_1228));
 }
 }
 } } _bk3634:; 
}
static void f231_note_edge(int64_t callee_1229) {
if (((((g404) < (((int64_t)0LL))) || ((callee_1229) < (((int64_t)0LL)))) || ((g404) == (callee_1229)))) { return;
 }
{ hrv *_v3639 = &(g395); for (int64_t _k3639 = 0; _k3639 < _v3639->n; _k3639++) { S15 e_1230 = ((S15*)_v3639->b)[_k3639]; if ((((((int64_t)((e_1230).caller_))) == (g404)) && ((((int64_t)((e_1230).callee_))) == (callee_1229)))) { return;
 }
 } } _bk3638:; 
(void)(({ hrv *_v3640 = &(g395); S15 _x3640 = ((S15){ .caller_ = ((int32_t)(g404)), .callee_ = ((int32_t)(callee_1229)), }); S15 *_p3640 = (S15*)hr_grow(_v3640, 1, sizeof _x3640); *_p3640 = _x3640; _p3640; }));
}
static int64_t f232_block_binding(int64_t name_1231) {
int64_t i_1232 = g403; 
while (((i_1232) >= (((int64_t)0LL)))) { S6 f_1233 = (*({ hrv *_t3642 = &(g390); int64_t _i3642 = i_1232; (S6*)_t3642->b + hr_ix(_i3642, _t3642->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:341"); })); 
if ((((f_1233).blk_) >= (((int32_t)0LL)))) { int64_t fnode_1234 = ((int64_t)((f_1233).node_)); 
if (((f233_blk_gen(fnode_1234)) == (name_1231))) { return i_1232;
 }
 }
i_1232 = ((int64_t)((f_1233).par_));
 } _bk3641:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f233_blk_gen(int64_t fnode_1235) {
int64_t gl_1237 = f234_gen_list(fnode_1235); 
if (((gl_1237) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
{ int32_t _e3646 = ((*({ hrv *_t3647 = &(g707); int64_t _i3647 = gl_1237; (S4*)_t3647->b + hr_ix(_i3647, _t3647->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:59"); }))).n_; for (int32_t _k3646 = 0; _k3646 < _e3646; _k3646++) { int32_t i_1238 = (int32_t)_k3646; int64_t g_1239 = ((int64_t)(((*({ hrv *_t3648 = &(g707); int64_t _i3648 = f90_kid(gl_1237, ((int64_t)(i_1238))); (S4*)_t3648->b + hr_ix(_i3648, _t3648->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:59"); }))).s_)); 
if (f235_is_blockparam(fnode_1235, g_1239)) { return g_1239;
 }
 } } _bk3645:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f234_gen_list(int64_t fnode_1236) {
return ((int64_t)(((*({ hrv *_t3651 = &(g707); int64_t _i3651 = fnode_1236; (S4*)_t3651->b + hr_ix(_i3651, _t3651->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:47"); }))).d_));
}
static bool f235_is_blockparam(int64_t fnode_1240, int64_t gname_1241) {
{ int32_t _e3653 = ((*({ hrv *_t3654 = &(g707); int64_t _i3654 = fnode_1240; (S4*)_t3654->b + hr_ix(_i3654, _t3654->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:49"); }))).n_; for (int32_t _k3653 = 0; _k3653 < _e3653; _k3653++) { int32_t i_1242 = (int32_t)_k3653; int64_t p_1243 = f90_kid(fnode_1240, ((int64_t)(i_1242))); 
if ((((((*({ hrv *_t3656 = &(g707); int64_t _i3656 = p_1243; (S4*)_t3656->b + hr_ix(_i3656, _t3656->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:49"); }))).a_) >= (((int32_t)0LL))) && f236_mentions(((int64_t)(((*({ hrv *_t3658 = &(g707); int64_t _i3658 = p_1243; (S4*)_t3658->b + hr_ix(_i3658, _t3658->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:49"); }))).a_)), gname_1241))) { return false;
 }
 } } _bk3652:; 
return true;
}
static bool f236_mentions(int64_t t_1244, int64_t g_1245) {
if (((t_1244) < (((int64_t)0LL)))) { return false;
 }
S4 x_1246 = (*({ hrv *_t3659 = &(g707); int64_t _i3659 = t_1244; (S4*)_t3659->b + hr_ix(_i3659, _t3659->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:54"); })); 
int64_t k_1247 = ((int64_t)((x_1246).k_)); 
if (((k_1247) == (((int64_t)41LL)))) { if (((((int64_t)((x_1246).s_))) == (g_1245))) { return true;
 }
{ int32_t _e3661 = (x_1246).n_; for (int32_t _k3661 = 0; _k3661 < _e3661; _k3661++) { int32_t i_1248 = (int32_t)_k3661; if (f236_mentions(f90_kid(t_1244, ((int64_t)(i_1248))), g_1245)) { return true;
 }
 } } _bk3660:; 
return false;
 }
if (((((((k_1247) == (((int64_t)42LL))) || ((k_1247) == (((int64_t)43LL)))) || ((k_1247) == (((int64_t)44LL)))) || ((k_1247) == (((int64_t)48LL)))) || ((k_1247) == (((int64_t)46LL))))) { return f236_mentions(((int64_t)((x_1246).a_)), g_1245);
 }
return false;
}
static int64_t f237_call_block(int64_t n_1250, int64_t inst_1251) {
int64_t fv_1252 = ((int64_t)(((*({ hrv *_t3665 = &(g390); int64_t _i3665 = inst_1251; (S6*)_t3665->b + hr_ix(_i3665, _t3665->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:348"); }))).blk_)); 
int64_t own_1253 = ((int64_t)(((*({ hrv *_t3666 = &(g390); int64_t _i3666 = inst_1251; (S6*)_t3666->b + hr_ix(_i3666, _t3666->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:349"); }))).bown_)); 
int64_t s_1254 = f228_ck_args(n_1250, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t na_1255 = ((int64_t)(((*({ hrv *_t3668 = &(g707); int64_t _i3668 = n_1250; (S4*)_t3668->b + hr_ix(_i3668, _t3668->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:351"); }))).n_)); 
{ int64_t _e3670 = na_1255; for (int64_t _k3670 = 0; _k3670 < _e3670; _k3670++) { int64_t j_1256 = (int64_t)_k3670; int64_t c_1257 = f90_kid(n_1250, j_1256); 
if (f166_is_pending(f141_at(c_1257))) { { int32_t *_t3674 = &((*({ hrv *_t3675 = &(g410); int64_t _i3675 = ((int64_t)((int64_t)s_1254 + (int64_t)j_1256)); (int32_t*)_t3675->b + hr_ix(_i3675, _t3675->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:352"); }))); *_t3674 = ((int32_t)(f187_default_t(c_1257))); }
 } else { { int32_t *_t3677 = &((*({ hrv *_t3678 = &(g410); int64_t _i3678 = ((int64_t)((int64_t)s_1254 + (int64_t)j_1256)); (int32_t*)_t3678->b + hr_ix(_i3678, _t3678->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:352"); }))); *_t3677 = ((int32_t)(f238_deref_val(f141_at(c_1257)))); }
 }
 } } _bk3669:; 
int64_t bi_1260 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v3682 = &(g390); for (int64_t _k3682 = 0; _k3682 < _v3682->n; _k3682++) { S6 f_1261 = ((S6*)_v3682->b)[_k3682]; int64_t i_1262 = (int64_t)_k3682; if ((((((((int64_t)((f_1261).node_))) == (fv_1252)) && ((((int64_t)((f_1261).par_))) == (own_1253))) && (((f_1261).blk_) == (((int32_t)(inst_1251))))) && ((((int64_t)((f_1261).cfn_))) == (g404)))) { bi_1260 = i_1262;
 }
 } } _bk3681:; 
if (((bi_1260) < (((int64_t)0LL)))) { bi_1260 = f105_new_inst(fv_1252, fv_1252, ((int64_t)((*({ hrv *_t3684 = &(g722); int64_t _i3684 = fv_1252; (int32_t*)_t3684->b + hr_ix(_i3684, _t3684->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:356"); })))), own_1253);
{ int32_t *_t3685 = &(((*({ hrv *_t3686 = &(g390); int64_t _i3686 = bi_1260; (S6*)_t3686->b + hr_ix(_i3686, _t3686->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:357"); }))).blk_); *_t3685 = ((int32_t)(inst_1251)); }
{ int32_t *_t3687 = &(((*({ hrv *_t3688 = &(g390); int64_t _i3688 = bi_1260; (S6*)_t3688->b + hr_ix(_i3688, _t3688->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:357"); }))).bown_); *_t3687 = ((int32_t)(own_1253)); }
{ int32_t *_t3689 = &(((*({ hrv *_t3690 = &(g390); int64_t _i3690 = bi_1260; (S6*)_t3690->b + hr_ix(_i3690, _t3690->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:358"); }))).cfn_); *_t3689 = ((int32_t)(g404)); }
int64_t sa_1263 = g403; 
int64_t sm_1264 = (g392).n; 
int64_t bt_1265 = (g471).n; 
int64_t ld_1266 = g409; 
g403 = bi_1260;
g409 = ((int64_t)0LL);
int64_t np_1267 = ((int64_t)(((*({ hrv *_t3691 = &(g707); int64_t _i3691 = fv_1252; (S4*)_t3691->b + hr_ix(_i3691, _t3691->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:361"); }))).n_)); 
if (((((uint16_t)((uint64_t)((*({ hrv *_t3692 = &(g707); int64_t _i3692 = fv_1252; (S4*)_t3692->b + hr_ix(_i3692, _t3692->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:362"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { int64_t _e3694 = np_1267; for (int64_t _k3694 = 0; _k3694 < _e3694; _k3694++) { int64_t j_1268 = (int64_t)_k3694; int64_t p_1269 = f90_kid(fv_1252, j_1268); 
int64_t pt_1270 = ({ int64_t _r3696; if (((j_1268) < (na_1255))) { _r3696 = ((int64_t)((*({ hrv *_t3697 = &(g410); int64_t _i3697 = ((int64_t)((int64_t)s_1254 + (int64_t)j_1268)); (int32_t*)_t3697->b + hr_ix(_i3697, _t3697->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:362"); }))));  } else { _r3696 = g578;  } _r3696; }); 
int64_t v_1271 = f207_add_lv(((int64_t)(((*({ hrv *_t3699 = &(g707); int64_t _i3699 = p_1269; (S4*)_t3699->b + hr_ix(_i3699, _t3699->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:362"); }))).s_)), pt_1270, ((int64_t)32LL), p_1269); 
(void)(f173_set_r(p_1269, ((int64_t)1LL), v_1271));
 } } _bk3693:; 
 } else { if (((na_1255) >= (((int64_t)1LL)))) { int64_t v_1272 = f207_add_lv(f8_intern(hr_str("it", 2)), ((int64_t)((*({ hrv *_t3703 = &(g410); int64_t _i3703 = s_1254; (int32_t*)_t3703->b + hr_ix(_i3703, _t3703->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:363"); })))), ((int64_t)32LL), fv_1252); 
(void)(f173_set_r(fv_1252, ((int64_t)1LL), v_1272));
 }
 }
int64_t body_1273 = ((int64_t)(((*({ hrv *_t3705 = &(g707); int64_t _i3705 = fv_1252; (S4*)_t3705->b + hr_ix(_i3705, _t3705->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:364"); }))).a_)); 
int64_t bt0_1274 = f137_ck(body_1273, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t rt_1275 = g561; 
if ((((((*({ hrv *_t3707 = &(g707); int64_t _i3707 = body_1273; (S4*)_t3707->b + hr_ix(_i3707, _t3707->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:367"); }))).a_) >= (((int32_t)0LL))) && ((bt0_1274) != (g561)))) { rt_1275 = ({ int64_t _r3708; if (f166_is_pending(bt0_1274)) { _r3708 = f187_default_t(((int64_t)(((*({ hrv *_t3711 = &(g707); int64_t _i3711 = body_1273; (S4*)_t3711->b + hr_ix(_i3711, _t3711->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:367"); }))).a_)));  } else { _r3708 = bt0_1274;  } _r3708; });
 }
{ int32_t *_t3712 = &(((*({ hrv *_t3713 = &(g390); int64_t _i3713 = bi_1260; (S6*)_t3713->b + hr_ix(_i3713, _t3713->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:368"); }))).ret_); *_t3712 = ((int32_t)(rt_1275)); }
(void)(({ hrv *_v3714 = &(g392); int64_t _k3714 = ((int64_t)((int64_t)(g392).n - (int64_t)sm_1264)); if (_k3714 < 0 || _k3714 > _v3714->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:369"); _v3714->n -= _k3714; }));
while ((((g471).n) > (bt_1265))) { (void)(({ hrv *_v3716 = &(g471); if (!_v3716->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:369"); ((int32_t*)_v3716->b)[--_v3716->n]; }));
 } _bk3715:; 
g403 = sa_1263;
g409 = ld_1266;
{ uint8_t *_t3717 = &(((*({ hrv *_t3718 = &(g390); int64_t _i3718 = bi_1260; (S6*)_t3718->b + hr_ix(_i3718, _t3718->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:371"); }))).st_); *_t3717 = ((uint8_t)2LL); }
 }
{ int64_t _e3720 = na_1255; for (int64_t _k3720 = 0; _k3720 < _e3720; _k3720++) { int64_t j_1276 = (int64_t)_k3720; int64_t c_1277 = f90_kid(n_1250, j_1276); 
if (f166_is_pending(f141_at(c_1277))) { (void)(f187_default_t(c_1277));
 }
 } } _bk3719:; 
(void)(f229_pop_args(s_1254));
(void)(f173_set_r(n_1250, ((int64_t)10LL), bi_1260));
return f138_set_t(n_1250, ((int64_t)(((*({ hrv *_t3728 = &(g390); int64_t _i3728 = bi_1260; (S6*)_t3728->b + hr_ix(_i3728, _t3728->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:376"); }))).ret_)));
}
static int64_t f238_deref_val(int64_t a_1258) {
int64_t d_1259 = f182_deref(a_1258); 
return ({ int64_t _r3730; if (((((*({ hrv *_t3731 = &(g554); int64_t _i3731 = d_1259; (S1*)_t3731->b + hr_ix(_i3731, _t3731->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:253"); }))).k_) == (((uint8_t)18LL)))) { _r3730 = g579;  } else { _r3730 = ({ int64_t _r3732; if (((((*({ hrv *_t3733 = &(g554); int64_t _i3733 = d_1259; (S1*)_t3733->b + hr_ix(_i3733, _t3733->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:253"); }))).k_) == (((uint8_t)7LL)))) { _r3732 = f136_t_enum(((int64_t)(((*({ hrv *_t3735 = &(g554); int64_t _i3735 = d_1259; (S1*)_t3735->b + hr_ix(_i3735, _t3735->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:253"); }))).a_)), false);  } else { _r3732 = d_1259;  } _r3732; });  } _r3730; });
}
static int64_t f239_builtin_of(hsl name_1278) {
if (hr_streq(name_1278, hr_str("print", 5))) { return ((int64_t)1LL);
 }
if (hr_streq(name_1278, hr_str("str", 3))) { return ((int64_t)2LL);
 }
if (hr_streq(name_1278, hr_str("format", 6))) { return ((int64_t)3LL);
 }
if (hr_streq(name_1278, hr_str("assert", 6))) { return ((int64_t)4LL);
 }
if (hr_streq(name_1278, hr_str("abort", 5))) { return ((int64_t)5LL);
 }
if (hr_streq(name_1278, hr_str("exit", 4))) { return ((int64_t)6LL);
 }
if (hr_streq(name_1278, hr_str("copy", 4))) { return ((int64_t)7LL);
 }
if (hr_streq(name_1278, hr_str("default", 7))) { return ((int64_t)8LL);
 }
if (hr_streq(name_1278, hr_str("to_bytes", 8))) { return ((int64_t)30LL);
 }
if (hr_streq(name_1278, hr_str("bytes_of", 8))) { return ((int64_t)31LL);
 }
if (hr_streq(name_1278, hr_str("from_bytes", 10))) { return ((int64_t)32LL);
 }
if (hr_streq(name_1278, hr_str("embed_file", 10))) { return ((int64_t)33LL);
 }
if (hr_streq(name_1278, hr_str("len", 3))) { return ((int64_t)9LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f240_user_format(int64_t n_1280) {
if (((((*({ hrv *_t3736 = &(g707); int64_t _i3736 = n_1280; (S4*)_t3736->b + hr_ix(_i3736, _t3736->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:297"); }))).n_) == (((int32_t)0LL)))) { return false;
 }
int64_t t_1281 = f182_deref(f137_ck(f90_kid(n_1280, ((int64_t)0LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))); 
return (!(((((((*({ hrv *_t3740 = &(g554); int64_t _i3740 = t_1281; (S1*)_t3740->b + hr_ix(_i3740, _t3740->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:297"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t3741 = &(g554); int64_t _i3741 = t_1281; (S1*)_t3741->b + hr_ix(_i3741, _t3741->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:297"); }))).a_))) == (g567))) && (f241_is_grow(t_1281) || ((((int64_t)(((*({ hrv *_t3743 = &(g554); int64_t _i3743 = t_1281; (S1*)_t3743->b + hr_ix(_i3743, _t3743->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:297"); }))).s_))) == (((int64_t)3LL)))))));
}
static bool f241_is_grow(int64_t t_1282) {
return (((((int64_t)(((*({ hrv *_t3744 = &(g554); int64_t _i3744 = t_1282; (S1*)_t3744->b + hr_ix(_i3744, _t3744->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:298"); }))).s_))) == (((int64_t)4LL))) || ((((int64_t)(((*({ hrv *_t3745 = &(g554); int64_t _i3745 = t_1282; (S1*)_t3745->b + hr_ix(_i3745, _t3745->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:298"); }))).s_))) == (((int64_t)5LL))));
}
static int64_t f242_ck_builtin(int64_t n_1283, int64_t b_1284, int64_t recv_1285, int64_t want_1286) {
S4 x_1287 = (*({ hrv *_t3746 = &(g707); int64_t _i3746 = n_1283; (S4*)_t3746->b + hr_ix(_i3746, _t3746->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:415"); })); 
(void)(f173_set_r(n_1283, ((int64_t)4LL), b_1284));
(void)(f178_set_x(n_1283, ({ int64_t _r3749; if (((recv_1285) >= (((int64_t)0LL)))) { _r3749 = ((int64_t)1LL);  } else { _r3749 = ((int64_t)0LL);  } _r3749; })));
int64_t na_1288 = ((int64_t)((x_1287).n_)); 

int64_t total_1290 = ((int64_t)((int64_t)na_1288 + (int64_t)({ int64_t _r3750; if (((recv_1285) >= (((int64_t)0LL)))) { _r3750 = ((int64_t)1LL);  } else { _r3750 = ((int64_t)0LL);  } _r3750; }))); 
int64_t need_1291 = ({ int64_t _r3751; if (((((((b_1284) == (((int64_t)1LL))) || ((b_1284) == (((int64_t)2LL)))) || ((b_1284) == (((int64_t)8LL)))) || ((b_1284) == (((int64_t)22LL)))) || ((b_1284) == (((int64_t)25LL))))) { _r3751 = ((int64_t)0LL);  } else { _r3751 = ({ int64_t _r3752; if (((((((b_1284) == (((int64_t)20LL))) || ((b_1284) == (((int64_t)21LL)))) || ((b_1284) == (((int64_t)23LL)))) || ((b_1284) == (((int64_t)24LL)))) || ((b_1284) == (((int64_t)26LL))))) { _r3752 = ((int64_t)2LL);  } else { _r3752 = ((int64_t)1LL);  } _r3752; });  } _r3751; }); 
if (((total_1290) < (need_1291))) { (void)(f108_cerr(n_1283, hr_str("too few arguments to a builtin", 30)));
return f138_set_t(n_1283, g578);
 }
if ((((b_1284) == (((int64_t)1LL))) || ((b_1284) == (((int64_t)2LL))))) { { int64_t _e3756 = na_1288; for (int64_t _k3756 = 0; _k3756 < _e3756; _k3756++) { int64_t i_1292 = (int64_t)_k3756; int64_t c_1293 = f90_kid(n_1283, i_1292); 
int64_t t_1294 = f137_ck(c_1293, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f166_is_pending(t_1294)) { (void)(f187_default_t(c_1293));
 }
(void)(f244_hook_walk(f206_fin_t(c_1293)));
 } } _bk3755:; 
return f138_set_t(n_1283, ({ int64_t _r3764; if (((b_1284) == (((int64_t)2LL)))) { _r3764 = f123_t_arr(g567, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));  } else { _r3764 = g561;  } _r3764; }));
 }
if (((b_1284) == (((int64_t)3LL)))) { int64_t o_1420 = f243_arg(((int64_t)0LL), &recv_1285, &n_1283); 
if (((recv_1285) < (((int64_t)0LL)))) { (void)(f137_ck(o_1420, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
{ int64_t _e3769 = total_1290; for (int64_t _k3769 = ((int64_t)1LL); _k3769 < _e3769; _k3769++) { int64_t i_1421 = (int64_t)_k3769; int64_t c_1422 = f243_arg(i_1421, &recv_1285, &n_1283); 
int64_t t_1423 = f137_ck(c_1422, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f166_is_pending(t_1423)) { (void)(f187_default_t(c_1422));
 }
(void)(f244_hook_walk(f206_fin_t(c_1422)));
 } } _bk3768:; 
return f138_set_t(n_1283, g561);
 }
if (((b_1284) == (((int64_t)4LL)))) { (void)(f137_ck(f243_arg(((int64_t)0LL), &recv_1285, &n_1283), g562));
(void)(f140_conv(f243_arg(((int64_t)0LL), &recv_1285, &n_1283), g562));
return f138_set_t(n_1283, g561);
 }
if (((b_1284) == (((int64_t)5LL)))) { int64_t t_1424 = f137_ck(f243_arg(((int64_t)0LL), &recv_1285, &n_1283), g579); 
if (f166_is_pending(t_1424)) { (void)(f187_default_t(f243_arg(((int64_t)0LL), &recv_1285, &n_1283)));
 }
return f138_set_t(n_1283, g561);
 }
if (((b_1284) == (((int64_t)6LL)))) { (void)(f137_ck(f243_arg(((int64_t)0LL), &recv_1285, &n_1283), g566));
(void)(f140_conv(f243_arg(((int64_t)0LL), &recv_1285, &n_1283), g566));
return f138_set_t(n_1283, g561);
 }
if (((b_1284) == (((int64_t)8LL)))) { int64_t ta_1425 = ((int64_t)((x_1287).c_)); 
if (((ta_1425) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1283, hr_str("default needs a type: default<T>()", 34)));
return f138_set_t(n_1283, g578);
 }
return f138_set_t(n_1283, f113_rtype(f90_kid(ta_1425, ((int64_t)0LL)), f110_ns_of(n_1283)));
 }
if (((b_1284) == (((int64_t)7LL)))) { int64_t c_1426 = f243_arg(((int64_t)0LL), &recv_1285, &n_1283); 
if (((recv_1285) < (((int64_t)0LL)))) { (void)(f137_ck(c_1426, want_1286));
 }
int64_t t_1427 = f141_at(c_1426); 
if (f166_is_pending(t_1427)) { t_1427 = f187_default_t(c_1426);
 }
int64_t d_1428 = f182_deref(t_1427); 
int64_t k_1429 = ((int64_t)(((*({ hrv *_t3805 = &(g554); int64_t _i3805 = d_1428; (S1*)_t3805->b + hr_ix(_i3805, _t3805->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:443"); }))).k_)); 
if (((k_1429) == (((int64_t)9LL)))) { return f138_set_t(n_1283, f123_t_arr(((int64_t)(((*({ hrv *_t3808 = &(g554); int64_t _i3808 = d_1428; (S1*)_t3808->b + hr_ix(_i3808, _t3808->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:444"); }))).a_)), ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
return f138_set_t(n_1283, d_1428);
 }
if (((b_1284) == (((int64_t)9LL)))) { int64_t c_1430 = f243_arg(((int64_t)0LL), &recv_1285, &n_1283); 
if (((recv_1285) < (((int64_t)0LL)))) { (void)(f137_ck(c_1430, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (((((*({ hrv *_t3812 = &(g554); int64_t _i3812 = f141_at(c_1430); (S1*)_t3812->b + hr_ix(_i3812, _t3812->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:447"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(c_1430, g579));
 }
return f138_set_t(n_1283, g566);
 }
if (((b_1284) == (((int64_t)31LL)))) { int64_t c_1431 = f243_arg(((int64_t)0LL), &recv_1285, &n_1283); 
if (((recv_1285) < (((int64_t)0LL)))) { (void)(f137_ck(c_1431, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (f166_is_pending(f141_at(c_1431))) { (void)(f187_default_t(c_1431));
 }
return f138_set_t(n_1283, g579);
 }
if (((b_1284) == (((int64_t)30LL)))) { int64_t c_1432 = f243_arg(((int64_t)0LL), &recv_1285, &n_1283); 
if (((recv_1285) < (((int64_t)0LL)))) { (void)(f137_ck(c_1432, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (f166_is_pending(f141_at(c_1432))) { (void)(f187_default_t(c_1432));
 }
if (((total_1290) > (((int64_t)1LL)))) { (void)(f137_ck(f243_arg(((int64_t)1LL), &recv_1285, &n_1283), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_1283, g561);
 }
return f138_set_t(n_1283, f123_t_arr(g567, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (((b_1284) == (((int64_t)32LL)))) { int64_t ta_1433 = ((int64_t)((x_1287).c_)); 
int64_t t_1434 = ({ int64_t _r3832; if (((ta_1433) >= (((int64_t)0LL)))) { _r3832 = f113_rtype(f90_kid(ta_1433, ((int64_t)0LL)), f110_ns_of(n_1283));  } else { _r3832 = g578;  } _r3832; }); 
(void)(f137_ck(f243_arg(((int64_t)0LL), &recv_1285, &n_1283), g579));
if (f166_is_pending(f141_at(f243_arg(((int64_t)0LL), &recv_1285, &n_1283)))) { (void)(f187_default_t(f243_arg(((int64_t)0LL), &recv_1285, &n_1283)));
 }
return f138_set_t(n_1283, t_1434);
 }
if (((b_1284) == (((int64_t)33LL)))) { (void)(f137_ck(f243_arg(((int64_t)0LL), &recv_1285, &n_1283), g579));
(void)(f187_default_t(f243_arg(((int64_t)0LL), &recv_1285, &n_1283)));
return f138_set_t(n_1283, g579);
 }
int64_t r_1435 = recv_1285; 
int64_t rt_1436 = f182_deref(f141_at(r_1435)); 
int64_t e_1437 = ((int64_t)(((*({ hrv *_t3851 = &(g554); int64_t _i3851 = rt_1436; (S1*)_t3851->b + hr_ix(_i3851, _t3851->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:454"); }))).a_)); 
if (((b_1284) == (((int64_t)20LL)))) { if (((total_1290) != (((int64_t)2LL)))) { (void)(f108_cerr(n_1283, hr_str("push takes one value", 20)));
return f138_set_t(n_1283, g578);
 }
int64_t c_1438 = f243_arg(((int64_t)1LL), &recv_1285, &n_1283); 
(void)(f137_ck(c_1438, e_1437));
(void)(f140_conv(c_1438, e_1437));
return f138_set_t(n_1283, f119_t_ref(e_1437, ((int64_t)0LL)));
 }
if (((b_1284) == (((int64_t)21LL)))) { int64_t c_1439 = f243_arg(((int64_t)1LL), &recv_1285, &n_1283); 
int64_t t_1440 = f137_ck(c_1439, f18_t_slice(e_1437, true)); 
if (((((*({ hrv *_t3862 = &(g554); int64_t _i3862 = t_1440; (S1*)_t3862->b + hr_ix(_i3862, _t3862->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:456"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(c_1439, g579));
 } else { if (((((*({ hrv *_t3864 = &(g554); int64_t _i3864 = t_1440; (S1*)_t3864->b + hr_ix(_i3864, _t3864->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:456"); }))).k_) == (((uint8_t)19LL)))) { (void)(f140_conv(c_1439, f123_t_arr(e_1437, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
 } else { int64_t dt_1441 = f182_deref(t_1440); 
if (((((((*({ hrv *_t3868 = &(g554); int64_t _i3868 = dt_1441; (S1*)_t3868->b + hr_ix(_i3868, _t3868->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:456"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3869 = &(g554); int64_t _i3869 = dt_1441; (S1*)_t3869->b + hr_ix(_i3869, _t3869->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:456"); }))).k_) == (((uint8_t)9LL)))) && ((((int64_t)(((*({ hrv *_t3870 = &(g554); int64_t _i3870 = dt_1441; (S1*)_t3870->b + hr_ix(_i3870, _t3870->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:456"); }))).a_))) != (e_1437)))) { (void)(f108_cerr(c_1439, hr_str("append of a different element type", 34)));
 }
 }
 }
return f138_set_t(n_1283, g561);
 }
if (((b_1284) == (((int64_t)22LL)))) { return f138_set_t(n_1283, e_1437);
 }
if (((b_1284) == (((int64_t)23LL)))) { (void)(f137_ck(f243_arg(((int64_t)1LL), &recv_1285, &n_1283), g566));
(void)(f140_conv(f243_arg(((int64_t)1LL), &recv_1285, &n_1283), g566));
return f138_set_t(n_1283, g561);
 }
if (((b_1284) == (((int64_t)24LL)))) { (void)(f137_ck(f243_arg(((int64_t)1LL), &recv_1285, &n_1283), g566));
(void)(f140_conv(f243_arg(((int64_t)1LL), &recv_1285, &n_1283), g566));
if (((total_1290) > (((int64_t)2LL)))) { (void)(f137_ck(f243_arg(((int64_t)2LL), &recv_1285, &n_1283), e_1437));
(void)(f140_conv(f243_arg(((int64_t)2LL), &recv_1285, &n_1283), e_1437));
 }
return f138_set_t(n_1283, g561);
 }
if (((b_1284) == (((int64_t)25LL)))) { return f138_set_t(n_1283, g561);
 }
if (((b_1284) == (((int64_t)26LL)))) { (void)(f137_ck(f243_arg(((int64_t)1LL), &recv_1285, &n_1283), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_1283, g566);
 }
return f138_set_t(n_1283, g578);
}
static int64_t f243_arg(int64_t i_1289, int64_t *c1285, int64_t *c1283) {
return ({ int64_t _r3893; if ((((*c1285)) >= (((int64_t)0LL)))) { _r3893 = ({ int64_t _r3894; if (((i_1289) == (((int64_t)0LL)))) { _r3894 = (*c1285);  } else { _r3894 = f90_kid((*c1283), ((int64_t)((int64_t)i_1289 - (int64_t)((int64_t)1LL))));  } _r3894; });  } else { _r3893 = f90_kid((*c1283), i_1289);  } _r3893; });
}
static void f244_hook_walk(int64_t t_1295) {
while ((((g350).n) < ((g554).n))) { (void)(({ hrv *_v3898 = &(g350); int32_t _x3898 = ((int32_t)(0 - (uint64_t)(((int32_t)2LL)))); int32_t *_p3898 = (int32_t*)hr_grow(_v3898, 1, sizeof _x3898); *_p3898 = _x3898; _p3898; }));
(void)(({ hrv *_v3899 = &(g351); uint8_t _x3899 = ((uint8_t)0LL); uint8_t *_p3899 = (uint8_t*)hr_grow(_v3899, 1, sizeof _x3899); *_p3899 = _x3899; _p3899; }));
 } _bk3897:; 
if ((((t_1295) < (((int64_t)0LL))) || (((*({ hrv *_t3900 = &(g351); int64_t _i3900 = t_1295; (uint8_t*)_t3900->b + hr_ix(_i3900, _t3900->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:328"); }))) != (((uint8_t)0LL))))) { return;
 }
{ uint8_t *_t3901 = &((*({ hrv *_t3902 = &(g351); int64_t _i3902 = t_1295; (uint8_t*)_t3902->b + hr_ix(_i3902, _t3902->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:329"); }))); *_t3901 = ((uint8_t)1LL); }
S1 x_1296 = (*({ hrv *_t3903 = &(g554); int64_t _i3903 = t_1295; (S1*)_t3903->b + hr_ix(_i3903, _t3903->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:330"); })); 
int64_t k_1297 = ((int64_t)((x_1296).k_)); 
if (((k_1297) == (((int64_t)10LL)))) { (void)(f244_hook_walk(((int64_t)((x_1296).a_))));
return;
 }
if ((((k_1297) == (((int64_t)8LL))) || ((k_1297) == (((int64_t)9LL))))) { (void)(f244_hook_walk(((int64_t)((x_1296).a_))));
return;
 }
if (((k_1297) == (((int64_t)14LL)))) { { int32_t _e3907 = (x_1296).n_; for (int32_t _k3907 = 0; _k3907 < _e3907; _k3907++) { int32_t i_1298 = (int32_t)_k3907; (void)(f244_hook_walk(((int64_t)((*({ hrv *_t3909 = &(g555); int64_t _i3909 = ((int64_t)((int64_t)((int64_t)((x_1296).l_)) + (int64_t)((int64_t)(i_1298)))); (int32_t*)_t3909->b + hr_ix(_i3909, _t3909->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:333"); }))))));
 } } _bk3906:; 
return;
 }
if (((k_1297) == (((int64_t)5LL)))) { (void)(f245_hook_of(t_1295));
int64_t si_1412 = ((int64_t)((x_1296).a_)); 
{ int32_t _e3912 = ((*({ hrv *_t3913 = &(g557); int64_t _i3913 = si_1412; (S10*)_t3913->b + hr_ix(_i3913, _t3913->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:334"); }))).fnum_; for (int32_t _k3912 = 0; _k3912 < _e3912; _k3912++) { int32_t i_1413 = (int32_t)_k3912; S11 f_1414 = (*({ hrv *_t3914 = &(g558); int64_t _i3914 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3915 = &(g557); int64_t _i3915 = si_1412; (S10*)_t3915->b + hr_ix(_i3915, _t3915->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:334"); }))).f0_)) + (int64_t)((int64_t)(i_1413)))); (S11*)_t3914->b + hr_ix(_i3914, _t3914->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:334"); })); 
if ((((f_1414).ty_) >= (((int32_t)0LL)))) { (void)(f244_hook_walk(((int64_t)((f_1414).ty_))));
 }
 } } _bk3911:; 
return;
 }
if (((k_1297) == (((int64_t)7LL)))) { (void)(f245_hook_of(t_1295));
S9 v_1415 = (*({ hrv *_t3918 = &(g560); int64_t _i3918 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3919 = &(g559); int64_t _i3919 = (x_1296).a_; (S8*)_t3919->b + hr_ix(_i3919, _t3919->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:335"); }))).v0_)) + (int64_t)((int64_t)((x_1296).c_)))); (S9*)_t3918->b + hr_ix(_i3918, _t3918->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:335"); })); 
if ((((v_1415).si_) >= (((int32_t)0LL)))) { { int32_t _e3921 = ((*({ hrv *_t3922 = &(g557); int64_t _i3922 = (v_1415).si_; (S10*)_t3922->b + hr_ix(_i3922, _t3922->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:335"); }))).fnum_; for (int32_t _k3921 = 0; _k3921 < _e3921; _k3921++) { int32_t i_1416 = (int32_t)_k3921; S11 f_1417 = (*({ hrv *_t3923 = &(g558); int64_t _i3923 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3924 = &(g557); int64_t _i3924 = (v_1415).si_; (S10*)_t3924->b + hr_ix(_i3924, _t3924->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:335"); }))).f0_)) + (int64_t)((int64_t)(i_1416)))); (S11*)_t3923->b + hr_ix(_i3923, _t3923->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:335"); })); 
if ((((f_1417).ty_) >= (((int32_t)0LL)))) { (void)(f244_hook_walk(((int64_t)((f_1417).ty_))));
 }
 } } _bk3920:; 
 }
return;
 }
if (((k_1297) == (((int64_t)6LL)))) { (void)(f245_hook_of(t_1295));
int64_t ei_1418 = ((int64_t)((x_1296).a_)); 
{ int32_t _e3928 = ((*({ hrv *_t3929 = &(g559); int64_t _i3929 = ei_1418; (S8*)_t3929->b + hr_ix(_i3929, _t3929->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:336"); }))).vnum_; for (int32_t _k3928 = 0; _k3928 < _e3928; _k3928++) { int32_t i_1419 = (int32_t)_k3928; (void)(f244_hook_walk(f125_t_variant(ei_1418, ((int64_t)(i_1419)))));
 } } _bk3927:; 
 }
}
static int64_t f245_hook_of(int64_t t_1299) {
while ((((g350).n) < ((g554).n))) { (void)(({ hrv *_v3933 = &(g350); int32_t _x3933 = ((int32_t)(0 - (uint64_t)(((int32_t)2LL)))); int32_t *_p3933 = (int32_t*)hr_grow(_v3933, 1, sizeof _x3933); *_p3933 = _x3933; _p3933; }));
(void)(({ hrv *_v3934 = &(g351); uint8_t _x3934 = ((uint8_t)0LL); uint8_t *_p3934 = (uint8_t*)hr_grow(_v3934, 1, sizeof _x3934); *_p3934 = _x3934; _p3934; }));
 } _bk3932:; 
if ((((*({ hrv *_t3935 = &(g350); int64_t _i3935 = t_1299; (int32_t*)_t3935->b + hr_ix(_i3935, _t3935->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:304"); }))) != (((int32_t)(0 - (uint64_t)(((int32_t)2LL))))))) { return ((int64_t)((*({ hrv *_t3936 = &(g350); int64_t _i3936 = t_1299; (int32_t*)_t3936->b + hr_ix(_i3936, _t3936->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:304"); }))));
 }
{ int32_t *_t3937 = &((*({ hrv *_t3938 = &(g350); int64_t _i3938 = t_1299; (int32_t*)_t3938->b + hr_ix(_i3938, _t3938->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:305"); }))); *_t3937 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
int64_t k_1300 = ((int64_t)(((*({ hrv *_t3939 = &(g554); int64_t _i3939 = t_1299; (S1*)_t3939->b + hr_ix(_i3939, _t3939->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:306"); }))).k_)); 
if (((((((k_1300) == (((int64_t)0LL))) || ((k_1300) == (((int64_t)1LL)))) || ((k_1300) == (((int64_t)10LL)))) || ((k_1300) == (((int64_t)14LL)))) || f166_is_pending(t_1299))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t node_1301 = ({ int64_t _r3941; if (((k_1300) == (((int64_t)5LL)))) { _r3941 = ((int64_t)(((*({ hrv *_t3942 = &(g557); int64_t _i3942 = ((*({ hrv *_t3943 = &(g554); int64_t _i3943 = t_1299; (S1*)_t3943->b + hr_ix(_i3943, _t3943->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:308"); }))).a_; (S10*)_t3942->b + hr_ix(_i3942, _t3942->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:308"); }))).node_));  } else { _r3941 = ({ int64_t _r3944; if ((((k_1300) == (((int64_t)6LL))) || ((k_1300) == (((int64_t)7LL))))) { _r3944 = ((int64_t)(((*({ hrv *_t3945 = &(g559); int64_t _i3945 = ((*({ hrv *_t3946 = &(g554); int64_t _i3946 = t_1299; (S1*)_t3946->b + hr_ix(_i3946, _t3946->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:308"); }))).a_; (S8*)_t3945->b + hr_ix(_i3945, _t3945->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:308"); }))).node_));  } else { _r3944 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3944; });  } _r3941; }); 
if (((g352) < (((int64_t)0LL)))) { g352 = f8_intern(hr_str("format", 6));
 }
int64_t s_1302 = (g410).n; 
(void)(({ hrv *_v3948 = &(g410); int32_t _x3948 = ((int32_t)(f119_t_ref(f123_t_arr(g567, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))), ((int64_t)0LL)))); int32_t *_p3948 = (int32_t*)hr_grow(_v3948, 1, sizeof _x3948); *_p3948 = _x3948; _p3948; }));
(void)(({ hrv *_v3951 = &(g316); int32_t _x3951 = ((int32_t)0LL); int32_t *_p3951 = (int32_t*)hr_grow(_v3951, 1, sizeof _x3951); *_p3951 = _x3951; _p3951; }));
(void)(({ hrv *_v3952 = &(g410); int32_t _x3952 = ((int32_t)(t_1299)); int32_t *_p3952 = (int32_t*)hr_grow(_v3952, 1, sizeof _x3952); *_p3952 = _x3952; _p3952; }));
(void)(({ hrv *_v3953 = &(g316); int32_t _x3953 = ((int32_t)0LL); int32_t *_p3953 = (int32_t*)hr_grow(_v3953, 1, sizeof _x3953); *_p3953 = _x3953; _p3953; }));
M94 _t3954 = f246_resolve(((int64_t)0LL), g352, ({ int64_t _r3956; if (((node_1301) >= (((int64_t)0LL)))) { _r3956 = f110_ns_of(node_1301);  } else { _r3956 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3956; }), s_1302, ((int64_t)2LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false); int64_t fnode_1391 = _t3954.r0; int64_t b0_1392 = _t3954.r1; int64_t bn_1393 = _t3954.r2; 
(void)(f229_pop_args(s_1302));
if (((((fnode_1391) < (((int64_t)0LL))) || ((((*({ hrv *_t3959 = &(g707); int64_t _i3959 = fnode_1391; (S4*)_t3959->b + hr_ix(_i3959, _t3959->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:315"); }))).n_) != (((int32_t)2LL)))) || f253_is_std_node(fnode_1391))) { (void)(({ hrv *_v3961 = &(g314); int64_t _k3961 = ((int64_t)((int64_t)(g314).n - (int64_t)b0_1392)); if (_k3961 < 0 || _k3961 > _v3961->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:315"); _v3961->n -= _k3961; }));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t sa_1394 = g403; 
int64_t sc_1395 = g404; 
g403 = g405;
g404 = g405;
int64_t inst_1410 = f254_get_inst(fnode_1391, b0_1392, bn_1393, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
g403 = sa_1394;
g404 = sc_1395;
(void)(({ hrv *_v3963 = &(g314); int64_t _k3963 = ((int64_t)((int64_t)(g314).n - (int64_t)b0_1392)); if (_k3963 < 0 || _k3963 > _v3963->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:319"); _v3963->n -= _k3963; }));
while ((((g350).n) < ((g554).n))) { (void)(({ hrv *_v3965 = &(g350); int32_t _x3965 = ((int32_t)(0 - (uint64_t)(((int32_t)2LL)))); int32_t *_p3965 = (int32_t*)hr_grow(_v3965, 1, sizeof _x3965); *_p3965 = _x3965; _p3965; }));
(void)(({ hrv *_v3966 = &(g351); uint8_t _x3966 = ((uint8_t)0LL); uint8_t *_p3966 = (uint8_t*)hr_grow(_v3966, 1, sizeof _x3966); *_p3966 = _x3966; _p3966; }));
 } _bk3964:; 
int64_t pd_1411 = f182_deref(f212_ptype_of(inst_1410, ((int64_t)1LL))); 
if ((((pd_1411) != (t_1299)) && (!((((k_1300) == (((int64_t)7LL))) && ((((*({ hrv *_t3969 = &(g554); int64_t _i3969 = pd_1411; (S1*)_t3969->b + hr_ix(_i3969, _t3969->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:322"); }))).k_) == (((uint8_t)6LL)))))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
{ int32_t *_t3970 = &((*({ hrv *_t3971 = &(g350); int64_t _i3971 = t_1299; (int32_t*)_t3971->b + hr_ix(_i3971, _t3971->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:323"); }))); *_t3970 = ((int32_t)(inst_1410)); }
return inst_1410;
}
static M94 f246_resolve(int64_t n_1303, int64_t name_1304, int64_t ns_1305, int64_t a0_1306, int64_t an_1307, int64_t blk_1308, int64_t tyargs_1309, bool report_1310) {
int64_t c0_1311 = (g313).n; 
(void)(f247_cands_add(name_1304, ns_1305));
int64_t best_1320 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
int64_t bestr_1321 = ((int64_t)99LL); 
int64_t bestb0_1322 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
int64_t bestbn_1323 = ((int64_t)0LL); 
bool tie_1324 = false; 
bool bestuser_1325 = false; 
int64_t nb0_1326 = (g314).n; 
{ int64_t _e3974 = (g313).n; for (int64_t _k3974 = c0_1311; _k3974 < _e3974; _k3974++) { int64_t ci_1327 = (int64_t)_k3974; int64_t fnode_1328 = ((int64_t)(((*({ hrv *_t3975 = &(g492); int64_t _i3975 = (*({ hrv *_t3976 = &(g313); int64_t _i3976 = ci_1327; (int32_t*)_t3976->b + hr_ix(_i3976, _t3976->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:210"); })); (S5*)_t3975->b + hr_ix(_i3975, _t3975->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:210"); }))).node_)); 
int64_t np_1329 = ((int64_t)(((*({ hrv *_t3977 = &(g707); int64_t _i3977 = fnode_1328; (S4*)_t3977->b + hr_ix(_i3977, _t3977->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:211"); }))).n_)); 
int64_t nreq_1330 = ((int64_t)0LL); 
{ int64_t _e3979 = np_1329; for (int64_t _k3979 = 0; _k3979 < _e3979; _k3979++) { int64_t j_1331 = (int64_t)_k3979; if (((((*({ hrv *_t3980 = &(g707); int64_t _i3980 = f90_kid(fnode_1328, j_1331); (S4*)_t3980->b + hr_ix(_i3980, _t3980->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:213"); }))).b_) < (((int32_t)0LL)))) { nreq_1330 = ((int64_t)((int64_t)j_1331 + (int64_t)((int64_t)1LL)));
 }
 } } _bk3978:; 
if ((((an_1307) > (np_1329)) || ((an_1307) < (nreq_1330)))) { continue;
 }
int64_t bg_1332 = f233_blk_gen(fnode_1328); 
if ((((((blk_1308) >= (((int64_t)0LL)))) != (((bg_1332) >= (((int64_t)0LL))))) && (!(((((blk_1308) < (((int64_t)0LL))) && ((bg_1332) >= (((int64_t)0LL)))) && ((tyargs_1309) >= (((int64_t)0LL)))))))) { continue;
 }
int64_t b0_1333 = (g314).n; 
int64_t gl_1334 = f234_gen_list(fnode_1328); 
if (((gl_1334) >= (((int64_t)0LL)))) { { int32_t _e3985 = ((*({ hrv *_t3986 = &(g707); int64_t _i3986 = gl_1334; (S4*)_t3986->b + hr_ix(_i3986, _t3986->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:219"); }))).n_; for (int32_t _k3985 = 0; _k3985 < _e3985; _k3985++) { int32_t j_1335 = (int32_t)_k3985; (void)(({ hrv *_v3987 = &(g314); S7 _x3987 = ((S7){ .name_ = ((*({ hrv *_t3988 = &(g707); int64_t _i3988 = f90_kid(gl_1334, ((int64_t)(j_1335))); (S4*)_t3988->b + hr_ix(_i3988, _t3988->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:219"); }))).s_, .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }); S7 *_p3987 = (S7*)hr_grow(_v3987, 1, sizeof _x3987); *_p3987 = _x3987; _p3987; }));
 } } _bk3984:; 
 }
{ int64_t _e3991 = np_1329; for (int64_t _k3991 = 0; _k3991 < _e3991; _k3991++) { int64_t j_1336 = (int64_t)_k3991; int64_t p_1337 = f90_kid(fnode_1328, j_1336); 
if (((((*({ hrv *_t3993 = &(g707); int64_t _i3993 = p_1337; (S4*)_t3993->b + hr_ix(_i3993, _t3993->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:220"); }))).a_) < (((int32_t)0LL)))) { (void)(({ hrv *_v3994 = &(g314); S7 _x3994 = ((S7){ .name_ = ((int32_t)(f199_upname(p_1337))), .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }); S7 *_p3994 = (S7*)hr_grow(_v3994, 1, sizeof _x3994); *_p3994 = _x3994; _p3994; }));
 }
 } } _bk3990:; 
if (((tyargs_1309) >= (((int64_t)0LL)))) { { int64_t _e3997 = f45_min(((int64_t)(((*({ hrv *_t3999 = &(g707); int64_t _i3999 = tyargs_1309; (S4*)_t3999->b + hr_ix(_i3999, _t3999->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:221"); }))).n_)), ((int64_t)((int64_t)(g314).n - (int64_t)b0_1333))); for (int64_t _k3997 = 0; _k3997 < _e3997; _k3997++) { int64_t j_1338 = (int64_t)_k3997; { int32_t *_t4000 = &(((*({ hrv *_t4001 = &(g314); int64_t _i4001 = ((int64_t)((int64_t)b0_1333 + (int64_t)j_1338)); (S7*)_t4001->b + hr_ix(_i4001, _t4001->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:221"); }))).ty_); *_t4000 = ((int32_t)(f113_rtype(f90_kid(tyargs_1309, j_1338), ns_1305))); }
 } } _bk3996:; 
 }
{ int64_t _e4005 = an_1307; for (int64_t _k4005 = 0; _k4005 < _e4005; _k4005++) { int64_t j_1339 = (int64_t)_k4005; int64_t p_1340 = f90_kid(fnode_1328, j_1339); 
int64_t a_1341 = ((int64_t)((*({ hrv *_t4007 = &(g410); int64_t _i4007 = ((int64_t)((int64_t)a0_1306 + (int64_t)j_1339)); (int32_t*)_t4007->b + hr_ix(_i4007, _t4007->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:222"); })))); 
if ((!(f166_is_pending(a_1341)))) { if (((((*({ hrv *_t4009 = &(g707); int64_t _i4009 = p_1340; (S4*)_t4009->b + hr_ix(_i4009, _t4009->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:222"); }))).a_) >= (((int32_t)0LL)))) { (void)(f248_match_ty(((int64_t)(((*({ hrv *_t4011 = &(g707); int64_t _i4011 = p_1340; (S4*)_t4011->b + hr_ix(_i4011, _t4011->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:222"); }))).a_)), a_1341, b0_1333));
 } else { { int64_t _e4013 = (g314).n; for (int64_t _k4013 = b0_1333; _k4013 < _e4013; _k4013++) { int64_t q_1353 = (int64_t)_k4013; if ((((((int64_t)(((*({ hrv *_t4014 = &(g314); int64_t _i4014 = q_1353; (S7*)_t4014->b + hr_ix(_i4014, _t4014->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:222"); }))).name_))) == (f199_upname(p_1340))) && ((((*({ hrv *_t4016 = &(g314); int64_t _i4016 = q_1353; (S7*)_t4016->b + hr_ix(_i4016, _t4016->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:222"); }))).ty_) < (((int32_t)0LL))))) { { int32_t *_t4017 = &(((*({ hrv *_t4018 = &(g314); int64_t _i4018 = q_1353; (S7*)_t4018->b + hr_ix(_i4018, _t4018->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:222"); }))).ty_); *_t4017 = ((int32_t)(f238_deref_val(a_1341))); }
 }
 } } _bk4012:; 
 }
 }
 } } _bk4004:; 
{ int64_t _e4021 = an_1307; for (int64_t _k4021 = 0; _k4021 < _e4021; _k4021++) { int64_t j_1354 = (int64_t)_k4021; int64_t p_1355 = f90_kid(fnode_1328, j_1354); 
int64_t a_1356 = ((int64_t)((*({ hrv *_t4023 = &(g410); int64_t _i4023 = ((int64_t)((int64_t)a0_1306 + (int64_t)j_1354)); (int32_t*)_t4023->b + hr_ix(_i4023, _t4023->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:223"); })))); 
if (f166_is_pending(a_1356)) { int64_t dt_1359 = f249_pend_default(a_1356); 
if (((((*({ hrv *_t4026 = &(g707); int64_t _i4026 = p_1355; (S4*)_t4026->b + hr_ix(_i4026, _t4026->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:223"); }))).a_) >= (((int32_t)0LL)))) { (void)(f248_match_ty(((int64_t)(((*({ hrv *_t4028 = &(g707); int64_t _i4028 = p_1355; (S4*)_t4028->b + hr_ix(_i4028, _t4028->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:223"); }))).a_)), dt_1359, b0_1333));
 } else { { int64_t _e4030 = (g314).n; for (int64_t _k4030 = b0_1333; _k4030 < _e4030; _k4030++) { int64_t q_1360 = (int64_t)_k4030; if ((((((int64_t)(((*({ hrv *_t4031 = &(g314); int64_t _i4031 = q_1360; (S7*)_t4031->b + hr_ix(_i4031, _t4031->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:223"); }))).name_))) == (f199_upname(p_1355))) && ((((*({ hrv *_t4033 = &(g314); int64_t _i4033 = q_1360; (S7*)_t4033->b + hr_ix(_i4033, _t4033->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:223"); }))).ty_) < (((int32_t)0LL))))) { { int32_t *_t4034 = &(((*({ hrv *_t4035 = &(g314); int64_t _i4035 = q_1360; (S7*)_t4035->b + hr_ix(_i4035, _t4035->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:223"); }))).ty_); *_t4034 = ((int32_t)(dt_1359)); }
 }
 } } _bk4029:; 
 }
 }
 } } _bk4020:; 
bool ok_1361 = true; 
{ int64_t _e4037 = (g314).n; for (int64_t _k4037 = b0_1333; _k4037 < _e4037; _k4037++) { int64_t q_1362 = (int64_t)_k4037; if (((((*({ hrv *_t4038 = &(g314); int64_t _i4038 = q_1362; (S7*)_t4038->b + hr_ix(_i4038, _t4038->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:225"); }))).ty_) < (((int32_t)0LL)))) { if ((((bg_1332) >= (((int64_t)0LL))) && ((((int64_t)(((*({ hrv *_t4039 = &(g314); int64_t _i4039 = q_1362; (S7*)_t4039->b + hr_ix(_i4039, _t4039->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:225"); }))).name_))) == (bg_1332)))) { { int32_t *_t4040 = &(((*({ hrv *_t4041 = &(g314); int64_t _i4041 = q_1362; (S7*)_t4041->b + hr_ix(_i4041, _t4041->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:225"); }))).ty_); *_t4040 = ((int32_t)(g581)); }
 } else { ok_1361 = false;
 }
 }
 } } _bk4036:; 
if ((!(ok_1361))) { (void)(({ hrv *_v4042 = &(g314); int64_t _k4042 = ((int64_t)((int64_t)(g314).n - (int64_t)b0_1333)); if (_k4042 < 0 || _k4042 > _v4042->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:226"); _v4042->n -= _k4042; }));
continue;
 }
int64_t g0_1363 = (g494).n; 
{ int64_t _e4044 = (g314).n; for (int64_t _k4044 = b0_1333; _k4044 < _e4044; _k4044++) { int64_t q_1364 = (int64_t)_k4044; (void)(({ hrv *_v4045 = &(g494); S7 _x4045 = (*({ hrv *_t4046 = &(g314); int64_t _i4046 = q_1364; (S7*)_t4046->b + hr_ix(_i4046, _t4046->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:228"); })); S7 *_p4045 = (S7*)hr_grow(_v4045, 1, sizeof _x4045); *_p4045 = _x4045; _p4045; }));
 } } _bk4043:; 
int64_t fns_1365 = f110_ns_of(fnode_1328); 
int64_t worst_1366 = ((int64_t)0LL); 
{ int64_t _e4049 = an_1307; for (int64_t _k4049 = 0; _k4049 < _e4049; _k4049++) { int64_t j_1367 = (int64_t)_k4049; int64_t p_1368 = f90_kid(fnode_1328, j_1367); 
int64_t pt_1369 = ({ int64_t _r4051; if (((((*({ hrv *_t4052 = &(g707); int64_t _i4052 = p_1368; (S4*)_t4052->b + hr_ix(_i4052, _t4052->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:233"); }))).a_) >= (((int32_t)0LL)))) { _r4051 = f113_rtype(((int64_t)(((*({ hrv *_t4054 = &(g707); int64_t _i4054 = p_1368; (S4*)_t4054->b + hr_ix(_i4054, _t4054->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:233"); }))).a_)), fns_1365);  } else { _r4051 = f130_gb_find(f199_upname(p_1368));  } _r4051; }); 
int64_t r_1382 = f250_arg_rank(((int64_t)((*({ hrv *_t4058 = &(g316); int64_t _i4058 = ((int64_t)((int64_t)a0_1306 + (int64_t)j_1367)); (int32_t*)_t4058->b + hr_ix(_i4058, _t4058->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:234"); })))), ((int64_t)((*({ hrv *_t4059 = &(g410); int64_t _i4059 = ((int64_t)((int64_t)a0_1306 + (int64_t)j_1367)); (int32_t*)_t4059->b + hr_ix(_i4059, _t4059->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:234"); })))), pt_1369); 
if (((r_1382) < (((int64_t)0LL)))) { worst_1366 = ((int64_t)99LL);
{ goto _bk4048; }
 }
if (((r_1382) > (worst_1366))) { worst_1366 = r_1382;
 }
 } } _bk4048:; 
(void)(({ hrv *_v4060 = &(g494); int64_t _k4060 = ((int64_t)((int64_t)(g494).n - (int64_t)g0_1363)); if (_k4060 < 0 || _k4060 > _v4060->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:238"); _v4060->n -= _k4060; }));
if ((((worst_1366) < (((int64_t)2LL))) && (((gl_1334) >= (((int64_t)0LL))) || (((np_1329) > (((int64_t)0LL))) && f252_untyped_any(fnode_1328))))) { worst_1366 = f103_max(worst_1366, ((int64_t)1LL));
 }
if (((worst_1366) == (((int64_t)99LL)))) { (void)(({ hrv *_v4063 = &(g314); int64_t _k4063 = ((int64_t)((int64_t)(g314).n - (int64_t)b0_1333)); if (_k4063 < 0 || _k4063 > _v4063->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:240"); _v4063->n -= _k4063; }));
continue;
 }
bool user_1388 = (!(f253_is_std_node(fnode_1328))); 
if ((((worst_1366) < (bestr_1321)) || ((((worst_1366) == (bestr_1321)) && user_1388) && (!(bestuser_1325))))) { best_1320 = fnode_1328;
bestr_1321 = worst_1366;
bestb0_1322 = b0_1333;
bestbn_1323 = ((int64_t)((int64_t)(g314).n - (int64_t)b0_1333));
tie_1324 = false;
bestuser_1325 = user_1388;
 } else { if ((((worst_1366) == (bestr_1321)) && ((user_1388) == (bestuser_1325)))) { tie_1324 = true;
 }
 }
 } } _bk3973:; 
(void)(({ hrv *_v4065 = &(g313); int64_t _k4065 = ((int64_t)((int64_t)(g313).n - (int64_t)c0_1311)); if (_k4065 < 0 || _k4065 > _v4065->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:245"); _v4065->n -= _k4065; }));
if (((best_1320) < (((int64_t)0LL)))) { (void)(({ hrv *_v4066 = &(g314); int64_t _k4066 = ((int64_t)((int64_t)(g314).n - (int64_t)nb0_1326)); if (_k4066 < 0 || _k4066 > _v4066->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:246"); _v4066->n -= _k4066; }));
return (M94){ ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), nb0_1326, ((int64_t)0LL) };
 }
if ((tie_1324 && report_1310)) { hrv m_1389 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o4068 = &(m_1389); hr_fs(_o4068, hr_str("ambiguous call to ", 18)); hr_fs(_o4068, f10_nm(name_1304)); }));
(void)(f108_cerr(n_1303, hr_sl(m_1389)));
 }
if (((bestb0_1322) > (nb0_1326))) { { int64_t _e4072 = bestbn_1323; for (int64_t _k4072 = ((int64_t)0LL); _k4072 < _e4072; _k4072++) { int64_t q_1390 = (int64_t)_k4072; { S7 *_t4073 = &((*({ hrv *_t4074 = &(g314); int64_t _i4074 = ((int64_t)((int64_t)nb0_1326 + (int64_t)q_1390)); (S7*)_t4074->b + hr_ix(_i4074, _t4074->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:248"); }))); *_t4073 = (*({ hrv *_t4075 = &(g314); int64_t _i4075 = ((int64_t)((int64_t)bestb0_1322 + (int64_t)q_1390)); (S7*)_t4075->b + hr_ix(_i4075, _t4075->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:248"); })); }
 } } _bk4071:; 
 }
(void)(({ hrv *_v4076 = &(g314); int64_t _k4076 = ((int64_t)((int64_t)((int64_t)((int64_t)(g314).n - (int64_t)nb0_1326)) - (int64_t)bestbn_1323)); if (_k4076 < 0 || _k4076 > _v4076->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:249"); _v4076->n -= _k4076; }));
return (M94){ best_1320, nb0_1326, bestbn_1323 };
}
static void f247_cands_add(int64_t name_1312, int64_t ns_1313) {
M55 _t4077 = f117_split_q(name_1312); int64_t a_1314 = _t4077.r0; int64_t b_1315 = _t4077.r1; 
if (((a_1314) >= (((int64_t)0LL)))) { int64_t d_1316 = f107_dmap(name_1312); 
while (((d_1316) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4081 = &(g492); int64_t _i4081 = d_1316; (S5*)_t4081->b + hr_ix(_i4081, _t4081->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:197"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4082 = &(g313); int32_t _x4082 = ((int32_t)(d_1316)); int32_t *_p4082 = (int32_t*)hr_grow(_v4082, 1, sizeof _x4082); *_p4082 = _x4082; _p4082; }));
 }
d_1316 = ((int64_t)(((*({ hrv *_t4083 = &(g492); int64_t _i4083 = d_1316; (S5*)_t4083->b + hr_ix(_i4083, _t4083->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:197"); }))).next_));
 } _bk4080:; 
return;
 }
if (((a_1314) == (((int64_t)(0 - (uint64_t)(((int64_t)2LL))))))) { int64_t d_1317 = f107_dmap(b_1315); 
while (((d_1317) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4086 = &(g492); int64_t _i4086 = d_1317; (S5*)_t4086->b + hr_ix(_i4086, _t4086->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:198"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4087 = &(g313); int32_t _x4087 = ((int32_t)(d_1317)); int32_t *_p4087 = (int32_t*)hr_grow(_v4087, 1, sizeof _x4087); *_p4087 = _x4087; _p4087; }));
 }
d_1317 = ((int64_t)(((*({ hrv *_t4088 = &(g492); int64_t _i4088 = d_1317; (S5*)_t4088->b + hr_ix(_i4088, _t4088->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:198"); }))).next_));
 } _bk4085:; 
return;
 }
if (((ns_1313) >= (((int64_t)0LL)))) { int64_t d_1318 = f107_dmap(f98_qual(ns_1313, name_1312)); 
while (((d_1318) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4092 = &(g492); int64_t _i4092 = d_1318; (S5*)_t4092->b + hr_ix(_i4092, _t4092->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:199"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4093 = &(g313); int32_t _x4093 = ((int32_t)(d_1318)); int32_t *_p4093 = (int32_t*)hr_grow(_v4093, 1, sizeof _x4093); *_p4093 = _x4093; _p4093; }));
 }
d_1318 = ((int64_t)(((*({ hrv *_t4094 = &(g492); int64_t _i4094 = d_1318; (S5*)_t4094->b + hr_ix(_i4094, _t4094->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:199"); }))).next_));
 } _bk4091:; 
 }
int64_t d_1319 = f107_dmap(name_1312); 
while (((d_1319) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4097 = &(g492); int64_t _i4097 = d_1319; (S5*)_t4097->b + hr_ix(_i4097, _t4097->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:201"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4098 = &(g313); int32_t _x4098 = ((int32_t)(d_1319)); int32_t *_p4098 = (int32_t*)hr_grow(_v4098, 1, sizeof _x4098); *_p4098 = _x4098; _p4098; }));
 }
d_1319 = ((int64_t)(((*({ hrv *_t4099 = &(g492); int64_t _i4099 = d_1319; (S5*)_t4099->b + hr_ix(_i4099, _t4099->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:201"); }))).next_));
 } _bk4096:; 
}
static bool f248_match_ty(int64_t tn0_1342, int64_t t0_1343, int64_t g0_1344) {
if (((tn0_1342) < (((int64_t)0LL)))) { return true;
 }
S4 x_1345 = (*({ hrv *_t4100 = &(g707); int64_t _i4100 = tn0_1342; (S4*)_t4100->b + hr_ix(_i4100, _t4100->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:63"); })); 
int64_t k_1346 = ((int64_t)((x_1345).k_)); 
int64_t t_1347 = f182_deref(t0_1343); 
if (((k_1346) == (((int64_t)41LL)))) { if ((((x_1345).n_) == (((int32_t)0LL)))) { { int64_t _e4103 = (g314).n; for (int64_t _k4103 = g0_1344; _k4103 < _e4103; _k4103++) { int64_t i_1348 = (int64_t)_k4103; if (((((*({ hrv *_t4104 = &(g314); int64_t _i4104 = i_1348; (S7*)_t4104->b + hr_ix(_i4104, _t4104->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:67"); }))).name_) == ((x_1345).s_))) { if (((((*({ hrv *_t4105 = &(g314); int64_t _i4105 = i_1348; (S7*)_t4105->b + hr_ix(_i4105, _t4105->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:67"); }))).ty_) < (((int32_t)0LL)))) { { int32_t *_t4106 = &(((*({ hrv *_t4107 = &(g314); int64_t _i4107 = i_1348; (S7*)_t4107->b + hr_ix(_i4107, _t4107->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:67"); }))).ty_); *_t4106 = ((int32_t)(f238_deref_val(t_1347))); }
 }
return true;
 }
 } } _bk4102:; 
return true;
 }
if (((((*({ hrv *_t4109 = &(g554); int64_t _i4109 = t_1347; (S1*)_t4109->b + hr_ix(_i4109, _t4109->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).k_) == (((uint8_t)5LL)))) { int64_t si_1349 = ((int64_t)(((*({ hrv *_t4110 = &(g554); int64_t _i4110 = t_1347; (S1*)_t4110->b + hr_ix(_i4110, _t4110->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).a_)); 
if (((((*({ hrv *_t4111 = &(g557); int64_t _i4111 = si_1349; (S10*)_t4111->b + hr_ix(_i4111, _t4111->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).tn_) == ((x_1345).n_))) { { int32_t _e4113 = (x_1345).n_; for (int32_t _k4113 = 0; _k4113 < _e4113; _k4113++) { int32_t i_1350 = (int32_t)_k4113; (void)(f248_match_ty(f90_kid(tn0_1342, ((int64_t)(i_1350))), ((int64_t)((*({ hrv *_t4116 = &(g555); int64_t _i4116 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4117 = &(g557); int64_t _i4117 = si_1349; (S10*)_t4117->b + hr_ix(_i4117, _t4117->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).ta_)) + (int64_t)((int64_t)(i_1350)))); (int32_t*)_t4116->b + hr_ix(_i4116, _t4116->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); })))), g0_1344));
 } } _bk4112:; 
 }
 }
if (((((*({ hrv *_t4118 = &(g554); int64_t _i4118 = t_1347; (S1*)_t4118->b + hr_ix(_i4118, _t4118->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).k_) == (((uint8_t)6LL)))) { int64_t ei_1351 = ((int64_t)(((*({ hrv *_t4119 = &(g554); int64_t _i4119 = t_1347; (S1*)_t4119->b + hr_ix(_i4119, _t4119->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).a_)); 
if (((((*({ hrv *_t4120 = &(g559); int64_t _i4120 = ei_1351; (S8*)_t4120->b + hr_ix(_i4120, _t4120->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).tn_) == ((x_1345).n_))) { { int32_t _e4122 = (x_1345).n_; for (int32_t _k4122 = 0; _k4122 < _e4122; _k4122++) { int32_t i_1352 = (int32_t)_k4122; (void)(f248_match_ty(f90_kid(tn0_1342, ((int64_t)(i_1352))), ((int64_t)((*({ hrv *_t4125 = &(g555); int64_t _i4125 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4126 = &(g559); int64_t _i4126 = ei_1351; (S8*)_t4126->b + hr_ix(_i4126, _t4126->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).ta_)) + (int64_t)((int64_t)(i_1352)))); (int32_t*)_t4125->b + hr_ix(_i4125, _t4125->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); })))), g0_1344));
 } } _bk4121:; 
 }
 }
return true;
 }
if ((((k_1346) == (((int64_t)42LL))) || ((k_1346) == (((int64_t)43LL))))) { if ((((((*({ hrv *_t4127 = &(g554); int64_t _i4127 = t_1347; (S1*)_t4127->b + hr_ix(_i4127, _t4127->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t4128 = &(g554); int64_t _i4128 = t_1347; (S1*)_t4128->b + hr_ix(_i4128, _t4128->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).k_) == (((uint8_t)9LL))))) { return f248_match_ty(((int64_t)((x_1345).a_)), ((int64_t)(((*({ hrv *_t4130 = &(g554); int64_t _i4130 = t_1347; (S1*)_t4130->b + hr_ix(_i4130, _t4130->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).a_)), g0_1344);
 }
if (((((*({ hrv *_t4131 = &(g554); int64_t _i4131 = t_1347; (S1*)_t4131->b + hr_ix(_i4131, _t4131->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).k_) == (((uint8_t)18LL)))) { return f248_match_ty(((int64_t)((x_1345).a_)), g567, g0_1344);
 }
return true;
 }
if (((k_1346) == (((int64_t)44LL)))) { if (((((*({ hrv *_t4133 = &(g554); int64_t _i4133 = t0_1343; (S1*)_t4133->b + hr_ix(_i4133, _t4133->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:75"); }))).k_) == (((uint8_t)10LL)))) { return f248_match_ty(((int64_t)((x_1345).a_)), ((int64_t)(((*({ hrv *_t4135 = &(g554); int64_t _i4135 = t0_1343; (S1*)_t4135->b + hr_ix(_i4135, _t4135->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:75"); }))).a_)), g0_1344);
 }
return f248_match_ty(((int64_t)((x_1345).a_)), t_1347, g0_1344);
 }
if (((k_1346) == (((int64_t)48LL)))) { return f248_match_ty(((int64_t)((x_1345).a_)), t0_1343, g0_1344);
 }
return true;
}
static int64_t f249_pend_default(int64_t a_1357) {
int64_t k_1358 = ((int64_t)(((*({ hrv *_t4138 = &(g554); int64_t _i4138 = a_1357; (S1*)_t4138->b + hr_ix(_i4138, _t4138->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:254"); }))).k_)); 
return ({ int64_t _r4139; if (((k_1358) == (((int64_t)12LL)))) { _r4139 = g566;  } else { _r4139 = ({ int64_t _r4140; if (((k_1358) == (((int64_t)13LL)))) { _r4140 = g572;  } else { _r4140 = ({ int64_t _r4141; if (((k_1358) == (((int64_t)18LL)))) { _r4141 = g579;  } else { _r4141 = a_1357;  } _r4141; });  } _r4140; });  } _r4139; });
}
static int64_t f250_arg_rank(int64_t n_1370, int64_t a_1371, int64_t p_1372) {
if (((p_1372) < (((int64_t)0LL)))) { return ((int64_t)1LL);
 }
if (((a_1371) == (p_1372))) { return ((int64_t)0LL);
 }
int64_t ak_1373 = ((int64_t)(((*({ hrv *_t4142 = &(g554); int64_t _i4142 = a_1371; (S1*)_t4142->b + hr_ix(_i4142, _t4142->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:82"); }))).k_)); 
int64_t pk_1374 = ((int64_t)(((*({ hrv *_t4143 = &(g554); int64_t _i4143 = p_1372; (S1*)_t4143->b + hr_ix(_i4143, _t4143->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:82"); }))).k_)); 
if ((((pk_1374) == (((int64_t)0LL))) || ((ak_1373) == (((int64_t)0LL))))) { return ((int64_t)0LL);
 }
if (((((pk_1374) == (((int64_t)10LL))) && ((((*({ hrv *_t4144 = &(g554); int64_t _i4144 = p_1372; (S1*)_t4144->b + hr_ix(_i4144, _t4144->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:84"); }))).c_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4145 = &(g554); int64_t _i4145 = p_1372; (S1*)_t4145->b + hr_ix(_i4145, _t4145->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:84"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL))))) { int64_t tgt_1375 = ((int64_t)(((*({ hrv *_t4146 = &(g554); int64_t _i4146 = p_1372; (S1*)_t4146->b + hr_ix(_i4146, _t4146->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:84"); }))).a_)); 
if (((f182_deref(a_1371)) == (tgt_1375))) { return ((int64_t)0LL);
 }
if ((((ak_1373) == (((int64_t)12LL))) || ((ak_1373) == (((int64_t)13LL))))) { return f250_arg_rank(n_1370, a_1371, tgt_1375);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if ((((ak_1373) == (((int64_t)10LL))) && ((((*({ hrv *_t4149 = &(g554); int64_t _i4149 = a_1371; (S1*)_t4149->b + hr_ix(_i4149, _t4149->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).c_) < (((int32_t)0LL))))) { int64_t d_1376 = ((int64_t)(((*({ hrv *_t4150 = &(g554); int64_t _i4150 = a_1371; (S1*)_t4150->b + hr_ix(_i4150, _t4150->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).a_)); 
if (((d_1376) == (p_1372))) { return ((int64_t)0LL);
 }
if (((((pk_1374) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4151 = &(g554); int64_t _i4151 = p_1372; (S1*)_t4151->b + hr_ix(_i4151, _t4151->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && ((((*({ hrv *_t4152 = &(g554); int64_t _i4152 = p_1372; (S1*)_t4152->b + hr_ix(_i4152, _t4152->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).a_) == (((*({ hrv *_t4153 = &(g554); int64_t _i4153 = a_1371; (S1*)_t4153->b + hr_ix(_i4153, _t4153->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).a_)))) { return ((int64_t)0LL);
 }
return f250_arg_rank(n_1370, d_1376, p_1372);
 }
if (((ak_1373) == (((int64_t)12LL)))) { M78 _t4155 = f158_cval(n_1370); int64_t v_1377 = _t4155.r0; bool u_1378 = _t4155.r1; bool ok_1379 = _t4155.r2; 
if (((pk_1374) == (((int64_t)3LL)))) { if (((!(ok_1379)) || f161_int_fits(v_1377, u_1378, p_1372))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((pk_1374) == (((int64_t)4LL)))) { return ((int64_t)3LL);
 }
if (((pk_1374) == (((int64_t)17LL)))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1373) == (((int64_t)13LL)))) { if (((pk_1374) == (((int64_t)4LL)))) { return ({ int64_t _r4158; if (((((*({ hrv *_t4159 = &(g554); int64_t _i4159 = p_1372; (S1*)_t4159->b + hr_ix(_i4159, _t4159->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:93"); }))).s_) == (((uint8_t)8LL)))) { _r4158 = ((int64_t)1LL);  } else { _r4158 = ((int64_t)2LL);  } _r4158; });
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1373) == (((int64_t)18LL)))) { if ((((pk_1374) == (((int64_t)9LL))) && ((((int64_t)(((*({ hrv *_t4160 = &(g554); int64_t _i4160 = p_1372; (S1*)_t4160->b + hr_ix(_i4160, _t4160->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:94"); }))).a_))) == (g567)))) { return ((int64_t)0LL);
 }
if (f167_is_byte_arr(p_1372)) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1373) == (((int64_t)19LL)))) { if ((((pk_1374) == (((int64_t)8LL))) || ((pk_1374) == (((int64_t)9LL))))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1373) == (((int64_t)11LL)))) { if ((((pk_1374) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4162 = &(g554); int64_t _i4162 = p_1372; (S1*)_t4162->b + hr_ix(_i4162, _t4162->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:96"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { return ((int64_t)0LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((((pk_1374) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4163 = &(g554); int64_t _i4163 = p_1372; (S1*)_t4163->b + hr_ix(_i4163, _t4163->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:97"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && ((((int64_t)(((*({ hrv *_t4164 = &(g554); int64_t _i4164 = p_1372; (S1*)_t4164->b + hr_ix(_i4164, _t4164->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:97"); }))).a_))) == (a_1371)))) { return ((int64_t)0LL);
 }
if ((((ak_1373) == (((int64_t)3LL))) && ((pk_1374) == (((int64_t)4LL))))) { return ((int64_t)3LL);
 }
if (f155_widens(a_1371, p_1372)) { return ((int64_t)2LL);
 }
if (((((pk_1374) == (((int64_t)9LL))) && (((ak_1373) == (((int64_t)8LL))) || ((ak_1373) == (((int64_t)9LL))))) && ((((*({ hrv *_t4166 = &(g554); int64_t _i4166 = a_1371; (S1*)_t4166->b + hr_ix(_i4166, _t4166->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:100"); }))).a_) == (((*({ hrv *_t4167 = &(g554); int64_t _i4167 = p_1372; (S1*)_t4167->b + hr_ix(_i4167, _t4167->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:100"); }))).a_)))) { return ((int64_t)2LL);
 }
if (((((pk_1374) == (((int64_t)6LL))) && ((ak_1373) == (((int64_t)7LL)))) && ((((*({ hrv *_t4168 = &(g554); int64_t _i4168 = a_1371; (S1*)_t4168->b + hr_ix(_i4168, _t4168->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:101"); }))).a_) == (((*({ hrv *_t4169 = &(g554); int64_t _i4169 = p_1372; (S1*)_t4169->b + hr_ix(_i4169, _t4169->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:101"); }))).a_)))) { return ((int64_t)2LL);
 }
if ((((((pk_1374) == (((int64_t)8LL))) && (((ak_1373) == (((int64_t)8LL))) || ((ak_1373) == (((int64_t)9LL))))) && ((((*({ hrv *_t4170 = &(g554); int64_t _i4170 = a_1371; (S1*)_t4170->b + hr_ix(_i4170, _t4170->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:102"); }))).a_) == (((*({ hrv *_t4171 = &(g554); int64_t _i4171 = p_1372; (S1*)_t4171->b + hr_ix(_i4171, _t4171->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:102"); }))).a_))) && f251_is_construct(n_1370))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f251_is_construct(int64_t n_1380) {
int64_t k_1381 = ((int64_t)(((*({ hrv *_t4173 = &(g707); int64_t _i4173 = n_1380; (S4*)_t4173->b + hr_ix(_i4173, _t4173->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:195"); }))).k_)); 
return ((((k_1381) == (((int64_t)11LL))) || ((k_1381) == (((int64_t)16LL)))) || ((k_1381) == (((int64_t)3LL))));
}
static bool f252_untyped_any(int64_t f_1383) {
{ int32_t _e4175 = ((*({ hrv *_t4176 = &(g707); int64_t _i4176 = f_1383; (S4*)_t4176->b + hr_ix(_i4176, _t4176->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:252"); }))).n_; for (int32_t _k4175 = 0; _k4175 < _e4175; _k4175++) { int32_t j_1384 = (int32_t)_k4175; if (((((*({ hrv *_t4177 = &(g707); int64_t _i4177 = f90_kid(f_1383, ((int64_t)(j_1384))); (S4*)_t4177->b + hr_ix(_i4177, _t4177->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:252"); }))).a_) < (((int32_t)0LL)))) { return true;
 }
 } } _bk4174:; 
return false;
}
static bool f253_is_std_node(int64_t node_1385) {
int64_t f_1386 = f111_node_file(node_1385); 
L49 sp_1387 = f100_lib_path(hr_str("std", 3)); 
return hr_streq(f10_nm(((int64_t)(((*({ hrv *_t4182 = &(g916); int64_t _i4182 = f_1386; (S2*)_t4182->b + hr_ix(_i4182, _t4182->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:203"); }))).name_))), ({ hsl _t4183 = ({ L49 *_t4184 = &(sp_1387); (hsl){ (uint8_t*)_t4184->e, _t4184->n }; }); int64_t _l4183 = 0, _h4183 = _t4183.n; if (_l4183 < 0 || _h4183 < _l4183 || _h4183 > _t4183.n) hr_slerr(_l4183, _h4183, _t4183.n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:203"); (hsl){ _t4183.p + _l4183 * (int64_t)sizeof(uint8_t), _h4183 - _l4183 }; }));
}
static int64_t f254_get_inst(int64_t node_1396, int64_t b0_1397, int64_t bn_1398, int64_t blk_1399, int64_t bown_1400) {
int64_t par_1401 = ({ int64_t _r4185; if (((((uint16_t)((uint64_t)((*({ hrv *_t4186 = &(g707); int64_t _i4186 = node_1396; (S4*)_t4186->b + hr_ix(_i4186, _t4186->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:184"); }))).fl_ & (uint64_t)((uint16_t)128LL)))) != (((uint16_t)0LL)))) { _r4185 = g403;  } else { _r4185 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r4185; }); 
if (((blk_1399) < (((int64_t)0LL)))) { { hrv *_v4188 = &(g390); for (int64_t _k4188 = 0; _k4188 < _v4188->n; _k4188++) { S6 f_1402 = ((S6*)_v4188->b)[_k4188]; int64_t i_1403 = (int64_t)_k4188; if ((((((((int64_t)((f_1402).node_))) == (node_1396)) && (((f_1402).blk_) < (((int32_t)0LL)))) && ((((int64_t)((f_1402).par_))) == (par_1401))) && f255_same_binds(i_1403, b0_1397, bn_1398))) { return i_1403;
 }
 } } _bk4187:; 
 }
int64_t i_1408 = f105_new_inst(node_1396, node_1396, ((int64_t)((*({ hrv *_t4191 = &(g722); int64_t _i4191 = node_1396; (int32_t*)_t4191->b + hr_ix(_i4191, _t4191->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:186"); })))), par_1401); 
{ int32_t *_t4192 = &(((*({ hrv *_t4193 = &(g390); int64_t _i4193 = i_1408; (S6*)_t4193->b + hr_ix(_i4193, _t4193->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:187"); }))).g0_); *_t4192 = ((int32_t)((g396).n)); }
{ int64_t _e4195 = bn_1398; for (int64_t _k4195 = 0; _k4195 < _e4195; _k4195++) { int64_t j_1409 = (int64_t)_k4195; (void)(({ hrv *_v4196 = &(g396); S7 _x4196 = (*({ hrv *_t4197 = &(g314); int64_t _i4197 = ((int64_t)((int64_t)b0_1397 + (int64_t)j_1409)); (S7*)_t4197->b + hr_ix(_i4197, _t4197->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:188"); })); S7 *_p4196 = (S7*)hr_grow(_v4196, 1, sizeof _x4196); *_p4196 = _x4196; _p4196; }));
 } } _bk4194:; 
{ int32_t *_t4198 = &(((*({ hrv *_t4199 = &(g390); int64_t _i4199 = i_1408; (S6*)_t4199->b + hr_ix(_i4199, _t4199->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:189"); }))).gn_); *_t4198 = ((int32_t)(bn_1398)); }
{ int32_t *_t4200 = &(((*({ hrv *_t4201 = &(g390); int64_t _i4201 = i_1408; (S6*)_t4201->b + hr_ix(_i4201, _t4201->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:190"); }))).blk_); *_t4200 = ((int32_t)(blk_1399)); }
{ int32_t *_t4202 = &(((*({ hrv *_t4203 = &(g390); int64_t _i4203 = i_1408; (S6*)_t4203->b + hr_ix(_i4203, _t4203->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:190"); }))).bown_); *_t4202 = ((int32_t)(bown_1400)); }
(void)(f198_sig_inst(i_1408));
(void)(f211_check_inst(i_1408));
return i_1408;
}
static bool f255_same_binds(int64_t i_1404, int64_t b0_1405, int64_t bn_1406) {
if (((((int64_t)(((*({ hrv *_t4206 = &(g390); int64_t _i4206 = i_1404; (S6*)_t4206->b + hr_ix(_i4206, _t4206->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:179"); }))).gn_))) != (bn_1406))) { return false;
 }
{ int64_t _e4208 = bn_1406; for (int64_t _k4208 = 0; _k4208 < _e4208; _k4208++) { int64_t j_1407 = (int64_t)_k4208; if ((((((*({ hrv *_t4209 = &(g396); int64_t _i4209 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4210 = &(g390); int64_t _i4210 = i_1404; (S6*)_t4210->b + hr_ix(_i4210, _t4210->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:180"); }))).g0_)) + (int64_t)j_1407)); (S7*)_t4209->b + hr_ix(_i4209, _t4209->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:180"); }))).ty_) != (((*({ hrv *_t4211 = &(g314); int64_t _i4211 = ((int64_t)((int64_t)b0_1405 + (int64_t)j_1407)); (S7*)_t4211->b + hr_ix(_i4211, _t4211->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:180"); }))).ty_)) || ((((*({ hrv *_t4212 = &(g396); int64_t _i4212 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4213 = &(g390); int64_t _i4213 = i_1404; (S6*)_t4213->b + hr_ix(_i4213, _t4213->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:180"); }))).g0_)) + (int64_t)j_1407)); (S7*)_t4212->b + hr_ix(_i4212, _t4212->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:180"); }))).name_) != (((*({ hrv *_t4214 = &(g314); int64_t _i4214 = ((int64_t)((int64_t)b0_1405 + (int64_t)j_1407)); (S7*)_t4214->b + hr_ix(_i4214, _t4214->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:180"); }))).name_)))) { return false;
 }
 } } _bk4207:; 
return true;
}
static int64_t f256_call_fn(int64_t n_1442, int64_t name_1443, int64_t recv_1444, int64_t want_1445) {
int64_t s_1446 = f228_ck_args(n_1442, ((int64_t)0LL), recv_1444); 
int64_t an_1447 = ((int64_t)((int64_t)(g410).n - (int64_t)s_1446)); 
int64_t blk_1448 = ((int64_t)(((*({ hrv *_t4216 = &(g707); int64_t _i4216 = n_1442; (S4*)_t4216->b + hr_ix(_i4216, _t4216->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:393"); }))).b_)); 
M94 _t4217 = f246_resolve(n_1442, name_1443, f110_ns_of(n_1442), s_1446, an_1447, blk_1448, ((int64_t)(((*({ hrv *_t4220 = &(g707); int64_t _i4220 = n_1442; (S4*)_t4220->b + hr_ix(_i4220, _t4220->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:394"); }))).c_)), true); int64_t fnode_1449 = _t4217.r0; int64_t b0_1450 = _t4217.r1; int64_t bn_1451 = _t4217.r2; 
if (((fnode_1449) < (((int64_t)0LL)))) { hrv m_1452 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o4222 = &(m_1452); hr_fs(_o4222, hr_str("no function ", 12)); hr_fs(_o4222, f10_nm(name_1443)); hr_fs(_o4222, hr_str(" matches (", 10)); }));
{ int64_t _e4225 = an_1447; for (int64_t _k4225 = 0; _k4225 < _e4225; _k4225++) { int64_t j_1453 = (int64_t)_k4225; if (((j_1453) > (((int64_t)0LL)))) { (void)(({ hrv *_v4226 = &(m_1452); hsl _s4226 = hr_str(", ", 2); hr_append(_v4226, _s4226.p, _s4226.n, sizeof(uint8_t)); }));
 }
{ hrv _t4228 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_v4227 = &(m_1452); hsl _s4227 = hr_sl(*hr_tmp(&_t4228, f164_tn(((int64_t)((*({ hrv *_t4230 = &(g410); int64_t _i4230 = ((int64_t)((int64_t)s_1446 + (int64_t)j_1453)); (int32_t*)_t4230->b + hr_ix(_i4230, _t4230->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:397"); }))))))); hr_append(_v4227, _s4227.p, _s4227.n, sizeof(uint8_t)); }));
}
 } } _bk4224:; 
(void)(({ hrv *_v4231 = &(m_1452); hsl _s4231 = hr_str(")", 1); hr_append(_v4231, _s4231.p, _s4231.n, sizeof(uint8_t)); }));
(void)(f108_cerr(n_1442, hr_sl(m_1452)));
(void)(f229_pop_args(s_1446));
(void)(({ hrv *_v4234 = &(g314); int64_t _k4234 = ((int64_t)((int64_t)(g314).n - (int64_t)b0_1450)); if (_k4234 < 0 || _k4234 > _v4234->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:401"); _v4234->n -= _k4234; }));
return f138_set_t(n_1442, g578);
 }
int64_t inst_1454 = f254_get_inst(fnode_1449, b0_1450, bn_1451, blk_1448, g403); 
(void)(({ hrv *_v4237 = &(g314); int64_t _k4237 = ((int64_t)((int64_t)(g314).n - (int64_t)b0_1450)); if (_k4237 < 0 || _k4237 > _v4237->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:405"); _v4237->n -= _k4237; }));
{ int64_t _e4239 = an_1447; for (int64_t _k4239 = 0; _k4239 < _e4239; _k4239++) { int64_t j_1455 = (int64_t)_k4239; int64_t c_1456 = ((int64_t)((*({ hrv *_t4240 = &(g316); int64_t _i4240 = ((int64_t)((int64_t)s_1446 + (int64_t)j_1455)); (int32_t*)_t4240->b + hr_ix(_i4240, _t4240->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:406"); })))); 
int64_t pt_1457 = f212_ptype_of(inst_1454, j_1455); 
if ((((((pt_1457) >= (((int64_t)0LL))) && ((((*({ hrv *_t4242 = &(g554); int64_t _i4242 = pt_1457; (S1*)_t4242->b + hr_ix(_i4242, _t4242->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:406"); }))).k_) == (((uint8_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4243 = &(g554); int64_t _i4243 = pt_1457; (S1*)_t4243->b + hr_ix(_i4243, _t4243->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:406"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))) && ((((*({ hrv *_t4244 = &(g554); int64_t _i4244 = pt_1457; (S1*)_t4244->b + hr_ix(_i4244, _t4244->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:406"); }))).c_) < (((int32_t)0LL))))) { if (f166_is_pending(f141_at(c_1456))) { (void)(f140_conv(c_1456, ((int64_t)(((*({ hrv *_t4248 = &(g554); int64_t _i4248 = pt_1457; (S1*)_t4248->b + hr_ix(_i4248, _t4248->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:406"); }))).a_))));
 }
 } else { (void)(f140_conv(c_1456, pt_1457));
 }
 } } _bk4238:; 
(void)(f229_pop_args(s_1446));
(void)(f230_note_caps_of(inst_1454));
(void)(f231_note_edge(inst_1454));
(void)(f173_set_r(n_1442, ((int64_t)3LL), inst_1454));
int64_t rt_1458 = ((int64_t)(((*({ hrv *_t4254 = &(g390); int64_t _i4254 = inst_1454; (S6*)_t4254->b + hr_ix(_i4254, _t4254->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:410"); }))).ret_)); 
if (((rt_1458) < (((int64_t)0LL)))) { if (((((*({ hrv *_t4255 = &(g390); int64_t _i4255 = inst_1454; (S6*)_t4255->b + hr_ix(_i4255, _t4255->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:411"); }))).st_) == (((uint8_t)1LL)))) { hrv m_1459 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o4257 = &(m_1459); hr_fs(_o4257, hr_str("recursive call to ", 18)); hr_fs(_o4257, f10_nm(name_1443)); hr_fs(_o4257, hr_str(" needs its result type written", 30)); }));
(void)(f108_cerr(n_1442, hr_sl(m_1459)));
 }
return f138_set_t(n_1442, g578);
 }
return f138_set_t(n_1442, rt_1458);
}
static int64_t f257_member_of(hsl name_1464) {
if (hr_streq(name_1464, hr_str("push", 4))) { return ((int64_t)20LL);
 }
if (hr_streq(name_1464, hr_str("append", 6))) { return ((int64_t)21LL);
 }
if (hr_streq(name_1464, hr_str("pop", 3))) { return ((int64_t)22LL);
 }
if (hr_streq(name_1464, hr_str("pop_n", 5))) { return ((int64_t)23LL);
 }
if (hr_streq(name_1464, hr_str("resize", 6))) { return ((int64_t)24LL);
 }
if (hr_streq(name_1464, hr_str("clear", 5))) { return ((int64_t)25LL);
 }
if (hr_streq(name_1464, hr_str("index_of", 8))) { return ((int64_t)26LL);
 }
if (hr_streq(name_1464, hr_str("len", 3))) { return ((int64_t)9LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f258_ck_slit(int64_t n_1467, int64_t want_1468) {
S4 x_1469 = (*({ hrv *_t4262 = &(g707); int64_t _i4262 = n_1467; (S4*)_t4262->b + hr_ix(_i4262, _t4262->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:465"); })); 
int64_t tnode_1470 = ((int64_t)((x_1469).a_)); 
int64_t ns_1471 = f110_ns_of(n_1467); 
int64_t t_1472 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((((*({ hrv *_t4264 = &(g707); int64_t _i4264 = tnode_1470; (S4*)_t4264->b + hr_ix(_i4264, _t4264->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:469"); }))).k_) == (((uint8_t)41LL))) && ((((*({ hrv *_t4265 = &(g707); int64_t _i4265 = tnode_1470; (S4*)_t4265->b + hr_ix(_i4265, _t4265->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:469"); }))).n_) == (((int32_t)0LL)))) && ((f130_gb_find(((int64_t)(((*({ hrv *_t4267 = &(g707); int64_t _i4267 = tnode_1470; (S4*)_t4267->b + hr_ix(_i4267, _t4267->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:469"); }))).s_)))) < (((int64_t)0LL))))) { int64_t d_1473 = f116_lookup_q(((int64_t)(((*({ hrv *_t4269 = &(g707); int64_t _i4269 = tnode_1470; (S4*)_t4269->b + hr_ix(_i4269, _t4269->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:470"); }))).s_)), ns_1471, ((int64_t)1LL)); 
if ((((d_1473) >= (((int64_t)0LL))) && ((((*({ hrv *_t4270 = &(g707); int64_t _i4270 = ((*({ hrv *_t4271 = &(g492); int64_t _i4271 = d_1473; (S5*)_t4271->b + hr_ix(_i4271, _t4271->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:471"); }))).node_; (S4*)_t4270->b + hr_ix(_i4270, _t4270->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:471"); }))).d_) >= (((int32_t)0LL))))) { if (((((want_1468) >= (((int64_t)0LL))) && ((((*({ hrv *_t4272 = &(g554); int64_t _i4272 = want_1468; (S1*)_t4272->b + hr_ix(_i4272, _t4272->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:471"); }))).k_) == (((uint8_t)5LL)))) && ((((*({ hrv *_t4273 = &(g557); int64_t _i4273 = ((*({ hrv *_t4274 = &(g554); int64_t _i4274 = want_1468; (S1*)_t4274->b + hr_ix(_i4274, _t4274->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:471"); }))).a_; (S10*)_t4273->b + hr_ix(_i4273, _t4273->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:471"); }))).node_) == (((*({ hrv *_t4275 = &(g492); int64_t _i4275 = d_1473; (S5*)_t4275->b + hr_ix(_i4275, _t4275->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:471"); }))).node_)))) { t_1472 = want_1468;
 }
 }
 }
if (((t_1472) < (((int64_t)0LL)))) { t_1472 = f113_rtype(tnode_1470, ns_1471);
 }
int64_t si_1474 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((*({ hrv *_t4277 = &(g554); int64_t _i4277 = t_1472; (S1*)_t4277->b + hr_ix(_i4277, _t4277->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:475"); }))).k_) == (((uint8_t)5LL)))) { si_1474 = ((int64_t)(((*({ hrv *_t4278 = &(g554); int64_t _i4278 = t_1472; (S1*)_t4278->b + hr_ix(_i4278, _t4278->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:475"); }))).a_));
 }
if (((((*({ hrv *_t4279 = &(g554); int64_t _i4279 = t_1472; (S1*)_t4279->b + hr_ix(_i4279, _t4279->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:476"); }))).k_) == (((uint8_t)7LL)))) { si_1474 = ((int64_t)(((*({ hrv *_t4280 = &(g560); int64_t _i4280 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4281 = &(g559); int64_t _i4281 = ((*({ hrv *_t4282 = &(g554); int64_t _i4282 = t_1472; (S1*)_t4282->b + hr_ix(_i4282, _t4282->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:476"); }))).a_; (S8*)_t4281->b + hr_ix(_i4281, _t4281->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:476"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t4283 = &(g554); int64_t _i4283 = t_1472; (S1*)_t4283->b + hr_ix(_i4283, _t4283->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:476"); }))).c_)))); (S9*)_t4280->b + hr_ix(_i4280, _t4280->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:476"); }))).si_));
 }
if (((si_1474) < (((int64_t)0LL)))) { if (((((*({ hrv *_t4284 = &(g554); int64_t _i4284 = t_1472; (S1*)_t4284->b + hr_ix(_i4284, _t4284->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:477"); }))).k_) != (((uint8_t)0LL)))) { (void)(f108_cerr(n_1467, hr_str("not a struct type", 17)));
 }
return f138_set_t(n_1467, g578);
 }
{ int32_t _e4288 = (x_1469).n_; for (int32_t _k4288 = 0; _k4288 < _e4288; _k4288++) { int32_t i_1475 = (int32_t)_k4288; if (((((int64_t)(((*({ hrv *_t4289 = &(g707); int64_t _i4289 = f90_kid(n_1467, ((int64_t)(i_1475))); (S4*)_t4289->b + hr_ix(_i4289, _t4289->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:478"); }))).k_))) == (((int64_t)37LL)))) { (void)(f108_cerr(f90_kid(n_1467, ((int64_t)(i_1475))), hr_str("const for is not supported by the self-hosted compiler yet", 58)));
return f138_set_t(n_1467, g578);
 }
 } } _bk4287:; 
int64_t nf_1476 = ((int64_t)(((*({ hrv *_t4294 = &(g557); int64_t _i4294 = si_1474; (S10*)_t4294->b + hr_ix(_i4294, _t4294->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:479"); }))).fnum_)); 
bool named_1477 = ((((x_1469).n_) > (((int32_t)0LL))) && ((((*({ hrv *_t4295 = &(g707); int64_t _i4295 = f90_kid(n_1467, ((int64_t)0LL)); (S4*)_t4295->b + hr_ix(_i4295, _t4295->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:480"); }))).s_) >= (((int32_t)0LL)))); 
int64_t fpos_1478 = ((int64_t)0LL); 
{ int32_t _e4298 = (x_1469).n_; for (int32_t _k4298 = 0; _k4298 < _e4298; _k4298++) { int32_t i_1479 = (int32_t)_k4298; int64_t fi_1480 = f90_kid(n_1467, ((int64_t)(i_1479))); 
int64_t idx_1481 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (named_1477) { idx_1481 = f190_sfield(si_1474, ((int64_t)(((*({ hrv *_t4301 = &(g707); int64_t _i4301 = fi_1480; (S4*)_t4301->b + hr_ix(_i4301, _t4301->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:485"); }))).s_)));
if (((idx_1481) < (((int64_t)0LL)))) { hrv m_1482 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t4306 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o4303 = &(m_1482); hr_fs(_o4303, hr_str("no field ", 9)); hr_fs(_o4303, f10_nm(((int64_t)(((*({ hrv *_t4305 = &(g707); int64_t _i4305 = fi_1480; (S4*)_t4305->b + hr_ix(_i4305, _t4305->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:485"); }))).s_)))); hr_fs(_o4303, hr_str(" in ", 4)); hr_fs(_o4303, hr_sl(*hr_tmp(&_t4306, f164_tn(t_1472)))); }));
}
(void)(f108_cerr(fi_1480, hr_sl(m_1482)));
continue;
 }
 } else { while ((((fpos_1478) < (nf_1476)) && ((((*({ hrv *_t4310 = &(g558); int64_t _i4310 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4311 = &(g557); int64_t _i4311 = si_1474; (S10*)_t4311->b + hr_ix(_i4311, _t4311->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:486"); }))).f0_)) + (int64_t)fpos_1478)); (S11*)_t4310->b + hr_ix(_i4310, _t4310->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:486"); }))).ty_) < (((int32_t)0LL))))) { fpos_1478++;
 } _bk4309:; 
idx_1481 = fpos_1478;
fpos_1478++;
if (((idx_1481) >= (nf_1476))) { (void)(f108_cerr(fi_1480, hr_str("too many initializers", 21)));
continue;
 }
 }
int64_t ft_1483 = ((int64_t)(((*({ hrv *_t4313 = &(g558); int64_t _i4313 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4314 = &(g557); int64_t _i4314 = si_1474; (S10*)_t4314->b + hr_ix(_i4314, _t4314->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:487"); }))).f0_)) + (int64_t)idx_1481)); (S11*)_t4313->b + hr_ix(_i4313, _t4313->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:487"); }))).ty_)); 
(void)(f173_set_r(fi_1480, ((int64_t)5LL), idx_1481));
int64_t v_1484 = ((int64_t)(((*({ hrv *_t4316 = &(g707); int64_t _i4316 = fi_1480; (S4*)_t4316->b + hr_ix(_i4316, _t4316->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:489"); }))).a_)); 
(void)(f137_ck(v_1484, ft_1483));
(void)(f140_conv(v_1484, ft_1483));
 } } _bk4297:; 
{ int64_t _e4320 = nf_1476; for (int64_t _k4320 = 0; _k4320 < _e4320; _k4320++) { int64_t j_1485 = (int64_t)_k4320; S11 f_1486 = (*({ hrv *_t4321 = &(g558); int64_t _i4321 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4322 = &(g557); int64_t _i4322 = si_1474; (S10*)_t4322->b + hr_ix(_i4322, _t4322->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:493"); }))).f0_)) + (int64_t)j_1485)); (S11*)_t4321->b + hr_ix(_i4321, _t4321->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:493"); })); 
if ((((f_1486).ty_) < (((int32_t)0LL)))) { continue;
 }
bool given_1487 = false; 
{ int32_t _e4324 = (x_1469).n_; for (int32_t _k4324 = 0; _k4324 < _e4324; _k4324++) { int32_t i_1488 = (int32_t)_k4324; if (((f160_rv(f90_kid(n_1467, ((int64_t)(i_1488))))) == (j_1485))) { given_1487 = true;
 }
 } } _bk4323:; 
if (((!(given_1487)) && (((f_1486).def_) >= (((int32_t)0LL))))) { int64_t sa_1489 = g403; 
g403 = g405;
(void)(f137_ck(((int64_t)((f_1486).def_)), ((int64_t)((f_1486).ty_))));
(void)(f140_conv(((int64_t)((f_1486).def_)), ((int64_t)((f_1486).ty_))));
g403 = sa_1489;
 }
if (((((!(given_1487)) && (((f_1486).def_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)(x_1469).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) && (!(f168_is_opt(((int64_t)((f_1486).ty_))))))) { hrv m_1490 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t4333 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o4331 = &(m_1490); hr_fs(_o4331, hr_str("missing field ", 14)); hr_fs(_o4331, f10_nm(((int64_t)((f_1486).name_)))); hr_fs(_o4331, hr_str(" in ", 4)); hr_fs(_o4331, hr_sl(*hr_tmp(&_t4333, f164_tn(t_1472)))); }));
}
(void)(f108_cerr(n_1467, hr_sl(m_1490)));
 }
 } } _bk4319:; 
(void)(f173_set_r(n_1467, ((int64_t)9LL), si_1474));
return f138_set_t(n_1467, t_1472);
}
static bool f259_ORD_HAS(int64_t d_1492) {
{ hrv *_v4339 = &(g411); for (int64_t _k4339 = 0; _k4339 < _v4339->n; _k4339++) { int32_t o_1493 = ((int32_t*)_v4339->b)[_k4339]; if (((((int64_t)(o_1493))) == (d_1492))) { return true;
 }
 } } _bk4338:; 
return false;
}
static void f260_propagate_calls(void) {
bool changed_1497 = true; 
while (changed_1497) { changed_1497 = false;
{ hrv *_v4342 = &(g395); for (int64_t _k4342 = 0; _k4342 < _v4342->n; _k4342++) { S15 e_1498 = ((S15*)_v4342->b)[_k4342]; int64_t cr_1499 = ((int64_t)((e_1498).caller_)); 
int64_t ce_1500 = ((int64_t)((e_1498).callee_)); 
if ((((*({ hrv *_t4343 = &(g390); int64_t _i4343 = ce_1500; (S6*)_t4343->b + hr_ix(_i4343, _t4343->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:42"); }))).lr_ && (!(((*({ hrv *_t4344 = &(g390); int64_t _i4344 = cr_1499; (S6*)_t4344->b + hr_ix(_i4344, _t4344->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:42"); }))).lr_)))) { { bool *_t4345 = &(((*({ hrv *_t4346 = &(g390); int64_t _i4346 = cr_1499; (S6*)_t4346->b + hr_ix(_i4346, _t4346->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:42"); }))).lr_); *_t4345 = true; }
changed_1497 = true;
 }
{ hrv *_v4348 = &(g394); for (int64_t _k4348 = 0; _k4348 < _v4348->n; _k4348++) { S13 c_1501 = ((S13*)_v4348->b)[_k4348]; if (((((int64_t)((c_1501).inst_))) == (ce_1500))) { int64_t v_1502 = ((int64_t)((c_1501).lv_)); 
if ((f172_visible_in(((int64_t)(((*({ hrv *_t4350 = &(g391); int64_t _i4350 = v_1502; (S12*)_t4350->b + hr_ix(_i4350, _t4350->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:43"); }))).own_)), cr_1499) || ((((int64_t)(((*({ hrv *_t4351 = &(g391); int64_t _i4351 = v_1502; (S12*)_t4351->b + hr_ix(_i4351, _t4351->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:43"); }))).cfn_))) != (cr_1499)))) { if (f175_add_cap_one(cr_1499, v_1502)) { changed_1497 = true;
 }
 }
 }
 } } _bk4347:; 
 } } _bk4341:; 
 } _bk4340:; 
}
static bool f261_gen_program(hrv* out_1504) {
(void)(({ hrv *_v4353 = &(g163); _v4353->n = 0; }));
{ hrv *_v4355 = &(g390); for (int64_t _k4355 = 0; _k4355 < _v4355->n; _k4355++) { S6 f_1505 = ((S6*)_v4355->b)[_k4355]; int64_t i_1506 = (int64_t)_k4355; if ((((f_1505).tg_ && (((f_1505).ret_) >= (((int32_t)0LL)))) && ((((int64_t)((f_1505).ret_))) != (g561)))) { int64_t sv_1507 = (g163).n; 
(void)(f262_ow(hr_str("static __thread ", 16)));
(void)(f263_ct(((int64_t)((f_1505).ret_))));
(void)(({ hrv *_o4358 = &(g163); hr_fs(_o4358, hr_str(" _lrv", 5)); hr_fi(_o4358, i_1506); hr_fs(_o4358, hr_str(";\012", 2)); }));
(void)(({ hrv *_v4359 = &(g167); hsl _s4359 = ({ hsl _t4360 = hr_sl(g163); int64_t _l4360 = sv_1507, _h4360 = _t4360.n; if (_l4360 < 0 || _h4360 < _l4360 || _h4360 > _t4360.n) hr_slerr(_l4360, _h4360, _t4360.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1125"); (hsl){ _t4360.p + _l4360 * (int64_t)sizeof(uint8_t), _h4360 - _l4360 }; }); hr_append(_v4359, _s4359.p, _s4359.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4361 = &(g163); int64_t _k4361 = sv_1507; if (_k4361 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1125"); hr_resize(_v4361, _k4361, sizeof(uint8_t)); }));
 }
 } } _bk4354:; 
{ hrv *_v4363 = &(g411); for (int64_t _k4363 = 0; _k4363 < _v4363->n; _k4363++) { int32_t d_1548 = ((int32_t*)_v4363->b)[_k4363]; int64_t di_1549 = ((int64_t)(d_1548)); 
int64_t t_1550 = ((int64_t)((*({ hrv *_t4364 = &(g453); int64_t _i4364 = di_1549; (int32_t*)_t4364->b + hr_ix(_i4364, _t4364->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1128"); })))); 
int64_t g_1551 = ((int64_t)(((*({ hrv *_t4365 = &(g492); int64_t _i4365 = di_1549; (S5*)_t4365->b + hr_ix(_i4365, _t4365->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1129"); }))).node_)); 
if ((((f176_const_of(di_1549)) >= (((int64_t)0LL))) && ((((*({ hrv *_t4367 = &(g554); int64_t _i4367 = t_1550; (S1*)_t4367->b + hr_ix(_i4367, _t4367->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1130"); }))).k_) == (((uint8_t)12LL))))) { continue;
 }
int64_t sv_1552 = (g163).n; 
g403 = g405;
g179 = g405;
(void)(f262_ow(hr_str("static ", 7)));
(void)(f263_ct(t_1550));
(void)(({ hrv *_o4370 = &(g163); hr_fs(_o4370, hr_str(" g", 2)); hr_fi(_o4370, di_1549); hr_fs(_o4370, hr_str(";\012", 2)); }));
(void)(({ hrv *_v4371 = &(g167); hsl _s4371 = ({ hsl _t4372 = hr_sl(g163); int64_t _l4372 = sv_1552, _h4372 = _t4372.n; if (_l4372 < 0 || _h4372 < _l4372 || _h4372 > _t4372.n) hr_slerr(_l4372, _h4372, _t4372.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1134"); (hsl){ _t4372.p + _l4372 * (int64_t)sizeof(uint8_t), _h4372 - _l4372 }; }); hr_append(_v4371, _s4371.p, _s4371.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4373 = &(g163); int64_t _k4373 = sv_1552; if (_k4373 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1134"); hr_resize(_v4373, _k4373, sizeof(uint8_t)); }));
S4 x_1553 = (*({ hrv *_t4374 = &(g707); int64_t _i4374 = g_1551; (S4*)_t4374->b + hr_ix(_i4374, _t4374->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1135"); })); 
if ((((x_1553).b_) >= (((int32_t)0LL)))) { int64_t iv_1554 = f90_kid(((int64_t)((x_1553).b_)), ((int64_t)0LL)); 
int64_t sp_1555 = (g163).n; 
(void)(({ hrv *_o4376 = &(g163); hr_fs(_o4376, hr_str("g", 1)); hr_fi(_o4376, di_1549); hr_fs(_o4376, hr_str(" = ", 3)); }));
if (f270_is_res(t_1550)) { (void)(f271_gxo(iv_1554));
 } else { (void)(f291_gx(iv_1554));
 }
(void)(f262_ow(hr_str(";\012", 2)));
if ((((g176).n) > (((int64_t)0LL)))) { (void)(({ hrv *_v4381 = &(g177); _v4381->n = 0; }));
(void)(({ hrv *_v4382 = &(g177); hsl _s4382 = ({ hsl _t4383 = hr_sl(g163); int64_t _l4383 = sp_1555, _h4383 = _t4383.n; if (_l4383 < 0 || _h4383 < _l4383 || _h4383 > _t4383.n) hr_slerr(_l4383, _h4383, _t4383.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1142"); (hsl){ _t4383.p + _l4383 * (int64_t)sizeof(uint8_t), _h4383 - _l4383 }; }); hr_append(_v4382, _s4382.p, _s4382.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4384 = &(g163); int64_t _k4384 = sp_1555; if (_k4384 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1142"); hr_resize(_v4384, _k4384, sizeof(uint8_t)); }));
(void)(f262_ow(hr_str("{ ", 2)));
(void)(({ hrv *_v4386 = &(g163); hsl _s4386 = ({ hsl _t4387 = hr_sl(g176); int64_t _l4387 = 0, _h4387 = _t4387.n; if (_l4387 < 0 || _h4387 < _l4387 || _h4387 > _t4387.n) hr_slerr(_l4387, _h4387, _t4387.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1142"); (hsl){ _t4387.p + _l4387 * (int64_t)sizeof(uint8_t), _h4387 - _l4387 }; }); hr_append(_v4386, _s4386.p, _s4386.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4388 = &(g176); _v4388->n = 0; }));
(void)(({ hrv *_v4389 = &(g163); hsl _s4389 = ({ hsl _t4390 = hr_sl(g177); int64_t _l4390 = 0, _h4390 = _t4390.n; if (_l4390 < 0 || _h4390 < _l4390 || _h4390 > _t4390.n) hr_slerr(_l4390, _h4390, _t4390.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1142"); (hsl){ _t4390.p + _l4390 * (int64_t)sizeof(uint8_t), _h4390 - _l4390 }; }); hr_append(_v4389, _s4389.p, _s4389.n, sizeof(uint8_t)); }));
(void)(f262_ow(hr_str("}\012", 2)));
 }
(void)(({ hrv *_v4392 = &(g168); hsl _s4392 = ({ hsl _t4393 = hr_sl(g163); int64_t _l4393 = sp_1555, _h4393 = _t4393.n; if (_l4393 < 0 || _h4393 < _l4393 || _h4393 > _t4393.n) hr_slerr(_l4393, _h4393, _t4393.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1143"); (hsl){ _t4393.p + _l4393 * (int64_t)sizeof(uint8_t), _h4393 - _l4393 }; }); hr_append(_v4392, _s4392.p, _s4392.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4394 = &(g163); int64_t _k4394 = sp_1555; if (_k4394 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1143"); hr_resize(_v4394, _k4394, sizeof(uint8_t)); }));
 }
 } } _bk4362:; 
int64_t mi_2098 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v4396 = &(g390); for (int64_t _k4396 = 0; _k4396 < _v4396->n; _k4396++) { S6 f_2099 = ((S6*)_v4396->b)[_k4396]; int64_t i_2100 = (int64_t)_k4396; if (((((f_2099).node_) < (((int32_t)0LL))) || (((f_2099).st_) != (((uint8_t)2LL))))) { continue;
 }
int64_t node_2101 = ((int64_t)((f_2099).node_)); 
if ((((((*({ hrv *_t4397 = &(g707); int64_t _i4397 = node_2101; (S4*)_t4397->b + hr_ix(_i4397, _t4397->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1150"); }))).k_) != (((uint8_t)50LL))) || ((((uint16_t)((uint64_t)((*({ hrv *_t4398 = &(g707); int64_t _i4398 = node_2101; (S4*)_t4398->b + hr_ix(_i4398, _t4398->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1150"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))))) { continue;
 }
if (((((f_2099).par_) < (((int32_t)0LL))) && hr_streq(f10_nm(((int64_t)((f_2099).name_))), hr_str("main", 4)))) { mi_2098 = i_2100;
 }
(void)(f364_gen_fn(i_2100));
if ((((g182).n) > (((int64_t)0LL)))) { return false;
 }
 } } _bk4395:; 
(void)(({ hrv *_v4401 = out_1504; hsl _s4401 = hr_str("#include \"hrt.h\"\012", 17); hr_append(_v4401, _s4401.p, _s4401.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4402 = out_1504; hsl _s4402 = hr_sl(g164); hr_append(_v4402, _s4402.p, _s4402.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4403 = out_1504; hsl _s4403 = hr_str("#pragma pack(push, 1)\012", 22); hr_append(_v4403, _s4403.p, _s4403.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4404 = out_1504; hsl _s4404 = hr_sl(g165); hr_append(_v4404, _s4404.p, _s4404.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4405 = out_1504; hsl _s4405 = hr_str("#pragma pack(pop)\012", 18); hr_append(_v4405, _s4405.p, _s4405.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4406 = out_1504; hsl _s4406 = hr_sl(g166); hr_append(_v4406, _s4406.p, _s4406.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4407 = out_1504; hsl _s4407 = hr_sl(g167); hr_append(_v4407, _s4407.p, _s4407.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4408 = out_1504; hsl _s4408 = ({ hsl _t4409 = hr_sl(g169); int64_t _l4409 = 0, _h4409 = _t4409.n; if (_l4409 < 0 || _h4409 < _l4409 || _h4409 > _t4409.n) hr_slerr(_l4409, _h4409, _t4409.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1162"); (hsl){ _t4409.p + _l4409 * (int64_t)sizeof(uint8_t), _h4409 - _l4409 }; }); hr_append(_v4408, _s4408.p, _s4408.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4410 = out_1504; hsl _s4410 = ({ hsl _t4411 = hr_sl(g163); int64_t _l4411 = 0, _h4411 = _t4411.n; if (_l4411 < 0 || _h4411 < _l4411 || _h4411 > _t4411.n) hr_slerr(_l4411, _h4411, _t4411.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1163"); (hsl){ _t4411.p + _l4411 * (int64_t)sizeof(uint8_t), _h4411 - _l4411 }; }); hr_append(_v4410, _s4410.p, _s4410.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4412 = out_1504; hsl _s4412 = hr_str("static void hr_init_globals(void) {\012", 36); hr_append(_v4412, _s4412.p, _s4412.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4413 = out_1504; hsl _s4413 = hr_sl(g168); hr_append(_v4413, _s4413.p, _s4413.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4414 = out_1504; hsl _s4414 = hr_str("}\012", 2); hr_append(_v4414, _s4414.p, _s4414.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4415 = out_1504; hsl _s4415 = hr_str("static void hr_main(void) { ", 28); hr_append(_v4415, _s4415.p, _s4415.n, sizeof(uint8_t)); }));
if (((mi_2098) >= (((int64_t)0LL)))) { int64_t rt_2125 = ((int64_t)(((*({ hrv *_t4416 = &(g390); int64_t _i4416 = mi_2098; (S6*)_t4416->b + hr_ix(_i4416, _t4416->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1166"); }))).ret_)); 
if ((((rt_2125) >= (((int64_t)0LL))) && ((((*({ hrv *_t4417 = &(g554); int64_t _i4417 = rt_2125; (S1*)_t4417->b + hr_ix(_i4417, _t4417->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1166"); }))).k_) == (((uint8_t)3LL))))) { (void)(({ hrv *_v4418 = out_1504; hsl _s4418 = hr_str("hr_flush(); exit((int)", 22); hr_append(_v4418, _s4418.p, _s4418.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4419 = &(g163); _v4419->n = 0; }));
(void)(f325_fn_cname(mi_2098));
(void)(({ hrv *_v4421 = out_1504; hsl _s4421 = ({ hsl _t4422 = hr_sl(g163); int64_t _l4422 = 0, _h4422 = _t4422.n; if (_l4422 < 0 || _h4422 < _l4422 || _h4422 > _t4422.n) hr_slerr(_l4422, _h4422, _t4422.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1166"); (hsl){ _t4422.p + _l4422 * (int64_t)sizeof(uint8_t), _h4422 - _l4422 }; }); hr_append(_v4421, _s4421.p, _s4421.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4423 = out_1504; hsl _s4423 = hr_str("()", 2); hr_append(_v4423, _s4423.p, _s4423.n, sizeof(uint8_t)); }));
if ((((rt_2125) >= (((int64_t)0LL))) && ((((*({ hrv *_t4424 = &(g554); int64_t _i4424 = rt_2125; (S1*)_t4424->b + hr_ix(_i4424, _t4424->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1166"); }))).k_) == (((uint8_t)3LL))))) { (void)(({ hrv *_v4425 = out_1504; hsl _s4425 = hr_str(")", 1); hr_append(_v4425, _s4425.p, _s4425.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4426 = out_1504; hsl _s4426 = hr_str("; ", 2); hr_append(_v4426, _s4426.p, _s4426.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4427 = out_1504; hsl _s4427 = hr_str("}\012", 2); hr_append(_v4427, _s4427.p, _s4427.n, sizeof(uint8_t)); }));
return (((g182).n) == (((int64_t)0LL)));
}
static void f262_ow(hsl s_1508) {
(void)(({ hrv *_v4428 = &(g163); hsl _s4428 = s_1508; hr_append(_v4428, _s4428.p, _s4428.n, sizeof(uint8_t)); }));
}
static void f263_ct(int64_t t_1509) {
(void)(f264_cbody(t_1509));
(void)(f262_ow(f266_cn(t_1509)));
}
static void f264_cbody(int64_t t_1510) {
(void)(f265_cn_grow());
S1 x_1511 = (*({ hrv *_t4433 = &(g554); int64_t _i4433 = t_1510; (S1*)_t4433->b + hr_ix(_i4433, _t4433->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:51"); })); 
int64_t k_1512 = ((int64_t)((x_1511).k_)); 
if ((((k_1512) == (((int64_t)10LL))) || (((*({ hrv *_t4434 = &(g173); int64_t _i4434 = t_1510; (uint8_t*)_t4434->b + hr_ix(_i4434, _t4434->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:52"); }))) != (((uint8_t)0LL))))) { (void)(f266_cn(t_1510));
return;
 }
{ uint8_t *_t4436 = &((*({ hrv *_t4437 = &(g173); int64_t _i4437 = t_1510; (uint8_t*)_t4437->b + hr_ix(_i4437, _t4437->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:53"); }))); *_t4436 = ((uint8_t)1LL); }
(void)(f266_cn(t_1510));
if (((k_1512) == (((int64_t)7LL)))) { S9 v_1526 = (*({ hrv *_t4439 = &(g560); int64_t _i4439 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4440 = &(g559); int64_t _i4440 = (x_1511).a_; (S8*)_t4440->b + hr_ix(_i4440, _t4440->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:55"); }))).v0_)) + (int64_t)((int64_t)((x_1511).c_)))); (S9*)_t4439->b + hr_ix(_i4439, _t4439->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:55"); })); 
if ((((v_1526).si_) >= (((int32_t)0LL)))) { (void)(f264_cbody(f134_t_struct(((int64_t)((v_1526).si_)))));
 }
return;
 }
if (((k_1512) == (((int64_t)5LL)))) { int64_t si_1527 = ((int64_t)((x_1511).a_)); 
(void)(f147_si_layout(si_1527));
int64_t f0_1528 = ((int64_t)(((*({ hrv *_t4444 = &(g557); int64_t _i4444 = si_1527; (S10*)_t4444->b + hr_ix(_i4444, _t4444->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:58"); }))).f0_)); 
int64_t fnum_1529 = ((int64_t)(((*({ hrv *_t4445 = &(g557); int64_t _i4445 = si_1527; (S10*)_t4445->b + hr_ix(_i4445, _t4445->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:58"); }))).fnum_)); 
{ int64_t _e4447 = fnum_1529; for (int64_t _k4447 = 0; _k4447 < _e4447; _k4447++) { int64_t i_1530 = (int64_t)_k4447; int32_t ft_1531 = ((*({ hrv *_t4448 = &(g558); int64_t _i4448 = ((int64_t)((int64_t)f0_1528 + (int64_t)i_1530)); (S11*)_t4448->b + hr_ix(_i4448, _t4448->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:59"); }))).ty_; 
if (((ft_1531) >= (((int32_t)0LL)))) { (void)(f264_cbody(((int64_t)(ft_1531))));
 }
 } } _bk4446:; 
(void)(({ hrv *_v4450 = &(g165); hsl _s4450 = hr_str("struct ", 7); hr_append(_v4450, _s4450.p, _s4450.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4451 = &(g165); hsl _s4451 = f266_cn(t_1510); hr_append(_v4451, _s4451.p, _s4451.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4453 = &(g165); hsl _s4453 = hr_str(" { ", 3); hr_append(_v4453, _s4453.p, _s4453.n, sizeof(uint8_t)); }));
bool any_1532 = false; 
{ int64_t _e4455 = fnum_1529; for (int64_t _k4455 = 0; _k4455 < _e4455; _k4455++) { int64_t i_1533 = (int64_t)_k4455; S11 f_1534 = (*({ hrv *_t4456 = &(g558); int64_t _i4456 = ((int64_t)((int64_t)f0_1528 + (int64_t)i_1533)); (S11*)_t4456->b + hr_ix(_i4456, _t4456->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:63"); })); 
if ((((f_1534).ty_) < (((int32_t)0LL)))) { if ((((f_1534).padn_) > (((int32_t)0LL)))) { (void)(({ hrv *_o4457 = &(g165); hr_fs(_o4457, hr_str("uint8_t _p", 10)); hr_fi(_o4457, i_1533); hr_fs(_o4457, hr_str("[", 1)); hr_fi(_o4457, (f_1534).padn_); hr_fs(_o4457, hr_str("]; ", 3)); }));
any_1532 = true;
 }
continue;
 }
(void)(({ hrv *_v4458 = &(g165); hsl _s4458 = f266_cn(((int64_t)((f_1534).ty_))); hr_append(_v4458, _s4458.p, _s4458.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4460 = &(g165); uint8_t _x4460 = ((uint8_t)32LL); uint8_t *_p4460 = (uint8_t*)hr_grow(_v4460, 1, sizeof _x4460); *_p4460 = _x4460; _p4460; }));
(void)(f269_fname_into((&(g165)), ((int64_t)((f_1534).name_))));
(void)(({ hrv *_v4462 = &(g165); hsl _s4462 = hr_str("; ", 2); hr_append(_v4462, _s4462.p, _s4462.n, sizeof(uint8_t)); }));
any_1532 = true;
 } } _bk4454:; 
if ((!(any_1532))) { (void)(({ hrv *_v4463 = &(g165); hsl _s4463 = hr_str("uint8_t _e; ", 12); hr_append(_v4463, _s4463.p, _s4463.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4464 = &(g165); hsl _s4464 = hr_str("};\012", 3); hr_append(_v4464, _s4464.p, _s4464.n, sizeof(uint8_t)); }));
return;
 }
if (((k_1512) == (((int64_t)6LL)))) { int64_t ei_1538 = ((int64_t)((x_1511).a_)); 
(void)(f149_ei_layout(ei_1538));
int64_t v0_1539 = ((int64_t)(((*({ hrv *_t4466 = &(g559); int64_t _i4466 = ei_1538; (S8*)_t4466->b + hr_ix(_i4466, _t4466->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:73"); }))).v0_)); 
bool pay_1540 = false; 
{ int32_t _e4468 = ((*({ hrv *_t4469 = &(g559); int64_t _i4469 = ei_1538; (S8*)_t4469->b + hr_ix(_i4469, _t4469->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:75"); }))).vnum_; for (int32_t _k4468 = 0; _k4468 < _e4468; _k4468++) { int32_t i_1541 = (int32_t)_k4468; S9 v_1542 = (*({ hrv *_t4470 = &(g560); int64_t _i4470 = ((int64_t)((int64_t)v0_1539 + (int64_t)((int64_t)(i_1541)))); (S9*)_t4470->b + hr_ix(_i4470, _t4470->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:75"); })); 
if (((((v_1542).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4471 = &(g557); int64_t _i4471 = (v_1542).si_; (S10*)_t4471->b + hr_ix(_i4471, _t4471->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:75"); }))).zero_)))) { (void)(f264_cbody(f134_t_struct(((int64_t)((v_1542).si_)))));
pay_1540 = true;
 }
 } } _bk4467:; 
(void)(({ hrv *_v4474 = &(g165); hsl _s4474 = hr_str("struct ", 7); hr_append(_v4474, _s4474.p, _s4474.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4475 = &(g165); hsl _s4475 = f266_cn(t_1510); hr_append(_v4475, _s4475.p, _s4475.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4477 = &(g165); hsl _s4477 = ({ hsl _r4478; if (((((*({ hrv *_t4479 = &(g559); int64_t _i4479 = ei_1538; (S8*)_t4479->b + hr_ix(_i4479, _t4479->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:76"); }))).tagsz_) == (((uint8_t)1LL)))) { _r4478 = hr_str(" { uint8_t tag; ", 16);  } else { _r4478 = hr_str(" { uint16_t tag; ", 17);  } _r4478; }); hr_append(_v4477, _s4477.p, _s4477.n, sizeof(uint8_t)); }));
if (pay_1540) { (void)(({ hrv *_v4480 = &(g165); hsl _s4480 = hr_str("union { ", 8); hr_append(_v4480, _s4480.p, _s4480.n, sizeof(uint8_t)); }));
{ int32_t _e4482 = ((*({ hrv *_t4483 = &(g559); int64_t _i4483 = ei_1538; (S8*)_t4483->b + hr_ix(_i4483, _t4483->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:77"); }))).vnum_; for (int32_t _k4482 = 0; _k4482 < _e4482; _k4482++) { int32_t i_1543 = (int32_t)_k4482; S9 v_1544 = (*({ hrv *_t4484 = &(g560); int64_t _i4484 = ((int64_t)((int64_t)v0_1539 + (int64_t)((int64_t)(i_1543)))); (S9*)_t4484->b + hr_ix(_i4484, _t4484->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:77"); })); 
if (((((v_1544).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4485 = &(g557); int64_t _i4485 = (v_1544).si_; (S10*)_t4485->b + hr_ix(_i4485, _t4485->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:77"); }))).zero_)))) { (void)(({ hrv *_v4486 = &(g165); hsl _s4486 = f266_cn(f134_t_struct(((int64_t)((v_1544).si_)))); hr_append(_v4486, _s4486.p, _s4486.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4489 = &(g165); hr_fs(_o4489, hr_str(" v", 2)); hr_fi(_o4489, i_1543); hr_fs(_o4489, hr_str("; ", 2)); }));
 }
 } } _bk4481:; 
(void)(({ hrv *_v4490 = &(g165); hsl _s4490 = hr_str("} u; ", 5); hr_append(_v4490, _s4490.p, _s4490.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4491 = &(g165); hsl _s4491 = hr_str("};\012", 3); hr_append(_v4491, _s4491.p, _s4491.n, sizeof(uint8_t)); }));
return;
 }
if (((k_1512) == (((int64_t)8LL)))) { int64_t a_1545 = ((int64_t)((x_1511).s_)); 
if ((((a_1545) == (((int64_t)1LL))) || (((a_1545) == (((int64_t)3LL))) && (((x_1511).b_) >= (((int64_t)0LL)))))) { (void)(f264_cbody(((int64_t)((x_1511).a_))));
(void)(({ hrv *_v4493 = &(g165); hsl _s4493 = hr_str("struct ", 7); hr_append(_v4493, _s4493.p, _s4493.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4494 = &(g165); hsl _s4494 = f266_cn(t_1510); hr_append(_v4494, _s4494.p, _s4494.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4496 = &(g165); hsl _s4496 = hr_str(" { ", 3); hr_append(_v4496, _s4496.p, _s4496.n, sizeof(uint8_t)); }));
if (((a_1545) == (((int64_t)3LL)))) { (void)(({ hrv *_v4497 = &(g165); hsl _s4497 = (g183).e[hr_ix(((int64_t)((int64_t)f124_lim_lenstore((x_1511).b_) & (int64_t)((int64_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:86")]; hr_append(_v4497, _s4497.p, _s4497.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4500 = &(g165); hsl _s4500 = hr_str(" n; ", 4); hr_append(_v4500, _s4500.p, _s4500.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4501 = &(g165); hsl _s4501 = f266_cn(((int64_t)((x_1511).a_))); hr_append(_v4501, _s4501.p, _s4501.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4503 = &(g165); hr_fs(_o4503, hr_str(" e[", 3)); hr_fi(_o4503, f103_max((x_1511).b_, ((int64_t)1LL))); hr_fs(_o4503, hr_str("]; };\012", 6)); }));
 }
return;
 }
if (((k_1512) == (((int64_t)14LL)))) { { int32_t _e4506 = (x_1511).n_; for (int32_t _k4506 = 0; _k4506 < _e4506; _k4506++) { int32_t i_1546 = (int32_t)_k4506; (void)(f264_cbody(((int64_t)((*({ hrv *_t4508 = &(g555); int64_t _i4508 = ((int64_t)((int64_t)((int64_t)((x_1511).l_)) + (int64_t)((int64_t)(i_1546)))); (int32_t*)_t4508->b + hr_ix(_i4508, _t4508->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:92"); }))))));
 } } _bk4505:; 
(void)(({ hrv *_v4509 = &(g165); hsl _s4509 = hr_str("struct ", 7); hr_append(_v4509, _s4509.p, _s4509.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4510 = &(g165); hsl _s4510 = f266_cn(t_1510); hr_append(_v4510, _s4510.p, _s4510.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4512 = &(g165); hsl _s4512 = hr_str(" { ", 3); hr_append(_v4512, _s4512.p, _s4512.n, sizeof(uint8_t)); }));
{ int32_t _e4514 = (x_1511).n_; for (int32_t _k4514 = 0; _k4514 < _e4514; _k4514++) { int32_t i_1547 = (int32_t)_k4514; (void)(({ hrv *_v4515 = &(g165); hsl _s4515 = f266_cn(((int64_t)((*({ hrv *_t4517 = &(g555); int64_t _i4517 = ((int64_t)((int64_t)((int64_t)((x_1511).l_)) + (int64_t)((int64_t)(i_1547)))); (int32_t*)_t4517->b + hr_ix(_i4517, _t4517->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:94"); }))))); hr_append(_v4515, _s4515.p, _s4515.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4518 = &(g165); hr_fs(_o4518, hr_str(" r", 2)); hr_fi(_o4518, i_1547); hr_fs(_o4518, hr_str("; ", 2)); }));
 } } _bk4513:; 
(void)(({ hrv *_v4519 = &(g165); hsl _s4519 = hr_str("};\012", 3); hr_append(_v4519, _s4519.p, _s4519.n, sizeof(uint8_t)); }));
 }
}
static void f265_cn_grow(void) {
while ((((g171).n) < ((g554).n))) { (void)(({ hrv *_v4521 = &(g171); int32_t _x4521 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p4521 = (int32_t*)hr_grow(_v4521, 1, sizeof _x4521); *_p4521 = _x4521; _p4521; }));
(void)(({ hrv *_v4522 = &(g172); int32_t _x4522 = ((int32_t)0LL); int32_t *_p4522 = (int32_t*)hr_grow(_v4522, 1, sizeof _x4522); *_p4522 = _x4522; _p4522; }));
(void)(({ hrv *_v4523 = &(g173); uint8_t _x4523 = ((uint8_t)0LL); uint8_t *_p4523 = (uint8_t*)hr_grow(_v4523, 1, sizeof _x4523); *_p4523 = _x4523; _p4523; }));
(void)(({ hrv *_v4524 = &(g174); uint8_t _x4524 = ((uint8_t)0LL); uint8_t *_p4524 = (uint8_t*)hr_grow(_v4524, 1, sizeof _x4524); *_p4524 = _x4524; _p4524; }));
(void)(({ hrv *_v4525 = &(g175); uint8_t _x4525 = ((uint8_t)0LL); uint8_t *_p4525 = (uint8_t*)hr_grow(_v4525, 1, sizeof _x4525); *_p4525 = _x4525; _p4525; }));
 } _bk4520:; 
}
static hsl f266_cn(int64_t t_1513) {
(void)(f265_cn_grow());
if ((((*({ hrv *_t4527 = &(g171); int64_t _i4527 = t_1513; (int32_t*)_t4527->b + hr_ix(_i4527, _t4527->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:23"); }))) < (((int32_t)0LL)))) { (void)(f267_cn_make(t_1513));
 }
int64_t o_1525 = ((int64_t)((*({ hrv *_t4529 = &(g171); int64_t _i4529 = t_1513; (int32_t*)_t4529->b + hr_ix(_i4529, _t4529->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:24"); })))); 
return ({ hsl _t4530 = hr_sl(g170); int64_t _l4530 = o_1525, _h4530 = ((int64_t)((int64_t)o_1525 + (int64_t)((int64_t)((*({ hrv *_t4531 = &(g172); int64_t _i4531 = t_1513; (int32_t*)_t4531->b + hr_ix(_i4531, _t4531->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:25"); })))))); if (_l4530 < 0 || _h4530 < _l4530 || _h4530 > _t4530.n) hr_slerr(_l4530, _h4530, _t4530.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:25"); (hsl){ _t4530.p + _l4530 * (int64_t)sizeof(uint8_t), _h4530 - _l4530 }; });
}
static void f267_cn_make(int64_t t_1514) {
S1 x_1515 = (*({ hrv *_t4532 = &(g554); int64_t _i4532 = t_1514; (S1*)_t4532->b + hr_ix(_i4532, _t4532->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:28"); })); 
int64_t k_1516 = ((int64_t)((x_1515).k_)); 
if ((((k_1516) == (((int64_t)10LL))) && (((x_1515).c_) < (((int32_t)0LL))))) { hsl e_1517 = f266_cn(((int64_t)((x_1515).a_))); 
int64_t s0_1518 = (g170).n; 
(void)(({ hrv *_v4534 = &(g170); hsl _s4534 = e_1517; hr_append(_v4534, _s4534.p, _s4534.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4535 = &(g170); uint8_t _x4535 = ((uint8_t)42LL); uint8_t *_p4535 = (uint8_t*)hr_grow(_v4535, 1, sizeof _x4535); *_p4535 = _x4535; _p4535; }));
{ int32_t *_t4536 = &((*({ hrv *_t4537 = &(g171); int64_t _i4537 = t_1514; (int32_t*)_t4537->b + hr_ix(_i4537, _t4537->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:29"); }))); *_t4536 = ((int32_t)(s0_1518)); }
{ int32_t *_t4538 = &((*({ hrv *_t4539 = &(g172); int64_t _i4539 = t_1514; (int32_t*)_t4539->b + hr_ix(_i4539, _t4539->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:29"); }))); *_t4538 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1518)))); }
return;
 }
if (((k_1516) == (((int64_t)7LL)))) { S9 v_1519 = (*({ hrv *_t4540 = &(g560); int64_t _i4540 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4541 = &(g559); int64_t _i4541 = (x_1515).a_; (S8*)_t4541->b + hr_ix(_i4541, _t4541->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:30"); }))).v0_)) + (int64_t)((int64_t)((x_1515).c_)))); (S9*)_t4540->b + hr_ix(_i4540, _t4540->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:30"); })); 
if ((((v_1519).si_) >= (((int32_t)0LL)))) { hsl e_1520 = f266_cn(f134_t_struct(((int64_t)((v_1519).si_)))); 
int64_t s0_1521 = (g170).n; 
(void)(({ hrv *_v4544 = &(g170); hsl _s4544 = e_1520; hr_append(_v4544, _s4544.p, _s4544.n, sizeof(uint8_t)); }));
{ int32_t *_t4545 = &((*({ hrv *_t4546 = &(g171); int64_t _i4546 = t_1514; (int32_t*)_t4546->b + hr_ix(_i4546, _t4546->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:30"); }))); *_t4545 = ((int32_t)(s0_1521)); }
{ int32_t *_t4547 = &((*({ hrv *_t4548 = &(g172); int64_t _i4548 = t_1514; (int32_t*)_t4548->b + hr_ix(_i4548, _t4548->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:30"); }))); *_t4547 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1521)))); }
return;
 }
 }
int64_t s0_1522 = (g170).n; 
if (((k_1516) == (((int64_t)3LL)))) { (void)(({ hrv *_v4549 = &(g170); hsl _s4549 = (g183).e[hr_ix(((uint8_t)((uint64_t)(x_1515).s_ & (uint64_t)((uint8_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:32")]; hr_append(_v4549, _s4549.p, _s4549.n, sizeof(uint8_t)); }));
 } else { if (((k_1516) == (((int64_t)10LL)))) { (void)(({ hrv *_v4551 = &(g170); hsl _s4551 = (g183).e[hr_ix(((int32_t)((int64_t)((int32_t)((int64_t)(x_1515).c_ & (int64_t)((int32_t)3LL))) + (int64_t)((int32_t)4LL))), 8, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:33")]; hr_append(_v4551, _s4551.p, _s4551.n, sizeof(uint8_t)); }));
 } else { if (((k_1516) == (((int64_t)2LL)))) { (void)(({ hrv *_v4553 = &(g170); hsl _s4553 = hr_str("bool", 4); hr_append(_v4553, _s4553.p, _s4553.n, sizeof(uint8_t)); }));
 } else { if (((k_1516) == (((int64_t)4LL)))) { (void)(({ hrv *_v4554 = &(g170); hsl _s4554 = ({ hsl _r4555; if ((((x_1515).s_) == (((uint8_t)4LL)))) { _r4555 = hr_str("float", 5);  } else { _r4555 = hr_str("double", 6);  } _r4555; }); hr_append(_v4554, _s4554.p, _s4554.n, sizeof(uint8_t)); }));
 } else { if (((k_1516) == (((int64_t)1LL)))) { (void)(({ hrv *_v4556 = &(g170); hsl _s4556 = hr_str("void", 4); hr_append(_v4556, _s4556.p, _s4556.n, sizeof(uint8_t)); }));
 } else { if (((k_1516) == (((int64_t)5LL)))) { (void)(({ hrv *_o4557 = &(g170); hr_fs(_o4557, hr_str("S", 1)); hr_fi(_o4557, (x_1515).a_); }));
(void)(f268_fwd(s0_1522));
 } else { if (((k_1516) == (((int64_t)6LL)))) { (void)(({ hrv *_o4559 = &(g170); hr_fs(_o4559, hr_str("E", 1)); hr_fi(_o4559, (x_1515).a_); }));
(void)(f268_fwd(s0_1522));
 } else { if (((k_1516) == (((int64_t)7LL)))) { (void)(({ hrv *_v4561 = &(g170); hsl _s4561 = hr_str("hr_unit", 7); hr_append(_v4561, _s4561.p, _s4561.n, sizeof(uint8_t)); }));
 } else { if (((k_1516) == (((int64_t)8LL)))) { int64_t a_1524 = ((int64_t)((x_1515).s_)); 
if ((((a_1524) == (((int64_t)4LL))) || ((a_1524) == (((int64_t)5LL))))) { (void)(({ hrv *_v4562 = &(g170); hsl _s4562 = hr_str("hrv", 3); hr_append(_v4562, _s4562.p, _s4562.n, sizeof(uint8_t)); }));
 } else { if (((a_1524) == (((int64_t)1LL)))) { (void)(({ hrv *_o4563 = &(g170); hr_fs(_o4563, hr_str("A", 1)); hr_fi(_o4563, t_1514); }));
(void)(f268_fwd(s0_1522));
 } else { if ((((a_1524) == (((int64_t)3LL))) && (((x_1515).b_) >= (((int64_t)0LL))))) { (void)(({ hrv *_o4565 = &(g170); hr_fs(_o4565, hr_str("L", 1)); hr_fi(_o4565, t_1514); }));
(void)(f268_fwd(s0_1522));
 } else { (void)(({ hrv *_v4567 = &(g170); hsl _s4567 = hr_str("uint8_t*", 8); hr_append(_v4567, _s4567.p, _s4567.n, sizeof(uint8_t)); }));
 }
 }
 }
 } else { if (((((k_1516) == (((int64_t)9LL))) || ((k_1516) == (((int64_t)18LL)))) || ((k_1516) == (((int64_t)19LL))))) { (void)(({ hrv *_v4568 = &(g170); hsl _s4568 = hr_str("hsl", 3); hr_append(_v4568, _s4568.p, _s4568.n, sizeof(uint8_t)); }));
 } else { if (((k_1516) == (((int64_t)14LL)))) { (void)(({ hrv *_o4569 = &(g170); hr_fs(_o4569, hr_str("M", 1)); hr_fi(_o4569, t_1514); }));
(void)(f268_fwd(s0_1522));
 } else { if ((((k_1516) == (((int64_t)12LL))) || ((k_1516) == (((int64_t)17LL))))) { (void)(({ hrv *_v4571 = &(g170); hsl _s4571 = hr_str("int64_t", 7); hr_append(_v4571, _s4571.p, _s4571.n, sizeof(uint8_t)); }));
 } else { if (((k_1516) == (((int64_t)13LL)))) { (void)(({ hrv *_v4572 = &(g170); hsl _s4572 = hr_str("double", 6); hr_append(_v4572, _s4572.p, _s4572.n, sizeof(uint8_t)); }));
 } else { (void)(({ hrv *_v4573 = &(g170); hsl _s4573 = hr_str("void*", 5); hr_append(_v4573, _s4573.p, _s4573.n, sizeof(uint8_t)); }));
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
{ int32_t *_t4574 = &((*({ hrv *_t4575 = &(g171); int64_t _i4575 = t_1514; (int32_t*)_t4575->b + hr_ix(_i4575, _t4575->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:46"); }))); *_t4574 = ((int32_t)(s0_1522)); }
{ int32_t *_t4576 = &((*({ hrv *_t4577 = &(g172); int64_t _i4577 = t_1514; (int32_t*)_t4577->b + hr_ix(_i4577, _t4577->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:46"); }))); *_t4576 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1522)))); }
}
static void f268_fwd(int64_t s0_1523) {
(void)(({ hrv *_v4578 = &(g164); hsl _s4578 = hr_str("typedef struct ", 15); hr_append(_v4578, _s4578.p, _s4578.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4579 = &(g164); hsl _s4579 = ({ hsl _t4580 = hr_sl(g170); int64_t _l4580 = s0_1523, _h4580 = _t4580.n; if (_l4580 < 0 || _h4580 < _l4580 || _h4580 > _t4580.n) hr_slerr(_l4580, _h4580, _t4580.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:17"); (hsl){ _t4580.p + _l4580 * (int64_t)sizeof(uint8_t), _h4580 - _l4580 }; }); hr_append(_v4579, _s4579.p, _s4579.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4581 = &(g164); uint8_t _x4581 = ((uint8_t)32LL); uint8_t *_p4581 = (uint8_t*)hr_grow(_v4581, 1, sizeof _x4581); *_p4581 = _x4581; _p4581; }));
(void)(({ hrv *_v4582 = &(g164); hsl _s4582 = ({ hsl _t4583 = hr_sl(g170); int64_t _l4583 = s0_1523, _h4583 = _t4583.n; if (_l4583 < 0 || _h4583 < _l4583 || _h4583 > _t4583.n) hr_slerr(_l4583, _h4583, _t4583.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:17"); (hsl){ _t4583.p + _l4583 * (int64_t)sizeof(uint8_t), _h4583 - _l4583 }; }); hr_append(_v4582, _s4582.p, _s4582.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4584 = &(g164); hsl _s4584 = hr_str(";\012", 2); hr_append(_v4584, _s4584.p, _s4584.n, sizeof(uint8_t)); }));
}
static void f269_fname_into(hrv* b_1535, int64_t name_1536) {
{ hsl _v4586 = f10_nm(name_1536); for (int64_t _k4586 = 0; _k4586 < _v4586.n; _k4586++) { uint8_t c_1537 = ((uint8_t*)_v4586.p)[_k4586]; (void)(({ hrv *_v4588 = b_1535; uint8_t _x4588 = ({ uint8_t _r4589; if (((c_1537) == (((uint8_t)58LL)))) { _r4589 = ((uint8_t)95LL);  } else { _r4589 = c_1537;  } _r4589; }); uint8_t *_p4588 = (uint8_t*)hr_grow(_v4588, 1, sizeof _x4588); *_p4588 = _x4588; _p4588; }));
 } } _bk4585:; 
(void)(({ hrv *_v4590 = b_1535; uint8_t _x4590 = ((uint8_t)95LL); uint8_t *_p4590 = (uint8_t*)hr_grow(_v4590, 1, sizeof _x4590); *_p4590 = _x4590; _p4590; }));
}
static bool f270_is_res(int64_t t_1556) {
return (((((*({ hrv *_t4591 = &(g554); int64_t _i4591 = t_1556; (S1*)_t4591->b + hr_ix(_i4591, _t4591->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:18"); }))).k_) == (((uint8_t)8LL))) && (((((int64_t)(((*({ hrv *_t4592 = &(g554); int64_t _i4592 = t_1556; (S1*)_t4592->b + hr_ix(_i4592, _t4592->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:18"); }))).s_))) == (((int64_t)4LL))) || ((((int64_t)(((*({ hrv *_t4593 = &(g554); int64_t _i4593 = t_1556; (S1*)_t4593->b + hr_ix(_i4593, _t4593->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:18"); }))).s_))) == (((int64_t)5LL)))));
}
static void f271_gxo(int64_t n_1557) {
int64_t c_1558 = f153_cv(n_1557); 
int64_t t_1559 = f141_at(n_1557); 
if ((((c_1558) >= (((int64_t)0LL))) && ((c_1558) != (t_1559)))) { if (f270_is_res(c_1558)) { (void)(f272_gcv(n_1557, t_1559, c_1558));
return;
 }
(void)(f291_gx(n_1557));
return;
 }
if ((f270_is_res(t_1559) && f274_is_place(n_1557))) { (void)(f262_ow(hr_str("hr_rdup(", 8)));
(void)(f277_gx0(n_1557));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f328_esz(((int64_t)(((*({ hrv *_t4605 = &(g554); int64_t _i4605 = t_1559; (S1*)_t4605->b + hr_ix(_i4605, _t4605->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:160"); }))).a_))));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
(void)(f277_gx0(n_1557));
}
static void f272_gcv(int64_t n_1560, int64_t f_1561, int64_t t_1562) {
if (((f_1561) == (t_1562))) { (void)(f273_gx1(n_1560));
return;
 }
int64_t fk_2090 = ((int64_t)(((*({ hrv *_t4609 = &(g554); int64_t _i4609 = f_1561; (S1*)_t4609->b + hr_ix(_i4609, _t4609->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:207"); }))).k_)); 
int64_t tk0_2091 = ((int64_t)(((*({ hrv *_t4610 = &(g554); int64_t _i4610 = t_1562; (S1*)_t4610->b + hr_ix(_i4610, _t4610->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:207"); }))).k_)); 
if (((((tk0_2091) == (((int64_t)2LL))) && ((fk_2090) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4611 = &(g554); int64_t _i4611 = f_1561; (S1*)_t4611->b + hr_ix(_i4611, _t4611->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:208"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f262_ow(hr_str("((", 2)));
(void)(f273_gx1(n_1560));
(void)(f262_ow(hr_str(") != 0)", 7)));
return;
 }
if (((((fk_2090) == (((int64_t)10LL))) && ((((*({ hrv *_t4615 = &(g554); int64_t _i4615 = f_1561; (S1*)_t4615->b + hr_ix(_i4615, _t4615->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:209"); }))).c_) < (((int32_t)0LL)))) && ((tk0_2091) != (((int64_t)10LL))))) { int64_t m_2092 = ((int64_t)(((*({ hrv *_t4616 = &(g554); int64_t _i4616 = f_1561; (S1*)_t4616->b + hr_ix(_i4616, _t4616->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:210"); }))).a_)); 
if (((m_2092) == (t_1562))) { (void)(f262_ow(hr_str("(*", 2)));
(void)(f273_gx1(n_1560));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if ((((tk0_2091) == (((int64_t)9LL))) && (((((*({ hrv *_t4620 = &(g554); int64_t _i4620 = m_2092; (S1*)_t4620->b + hr_ix(_i4620, _t4620->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:212"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t4621 = &(g554); int64_t _i4621 = m_2092; (S1*)_t4621->b + hr_ix(_i4621, _t4621->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:212"); }))).k_) == (((uint8_t)9LL)))))) { (void)(f294_gsl(n_1560, f_1561));
return;
 }
if ((((tk0_2091) == (((int64_t)3LL))) || ((tk0_2091) == (((int64_t)4LL))))) { (void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(t_1562));
(void)(f262_ow(hr_str(")(*", 3)));
(void)(f273_gx1(n_1560));
(void)(f262_ow(hr_str("))", 2)));
return;
 }
if (f270_is_res(t_1562)) { (void)(f262_ow(hr_str("hr_rfrom(", 9)));
(void)(f294_gsl(n_1560, f_1561));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f328_esz(((int64_t)(((*({ hrv *_t4633 = &(g554); int64_t _i4633 = t_1562; (S1*)_t4633->b + hr_ix(_i4633, _t4633->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:214"); }))).a_))));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
(void)(f262_ow(hr_str("(*", 2)));
(void)(f273_gx1(n_1560));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if (((((tk0_2091) == (((int64_t)3LL))) || ((tk0_2091) == (((int64_t)4LL)))) && ((((fk_2090) == (((int64_t)3LL))) || ((fk_2090) == (((int64_t)4LL)))) || ((fk_2090) == (((int64_t)2LL)))))) { (void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(t_1562));
(void)(f262_ow(hr_str(")(", 2)));
(void)(f273_gx1(n_1560));
(void)(f262_ow(hr_str("))", 2)));
return;
 }
if (((tk0_2091) == (((int64_t)9LL)))) { (void)(f294_gsl(n_1560, f_1561));
return;
 }
if ((((tk0_2091) == (((int64_t)6LL))) && ((fk_2090) == (((int64_t)7LL))))) { int64_t vi_2093 = ((int64_t)(((*({ hrv *_t4644 = &(g554); int64_t _i4644 = f_1561; (S1*)_t4644->b + hr_ix(_i4644, _t4644->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:220"); }))).c_)); 
int64_t ei_2094 = ((int64_t)(((*({ hrv *_t4645 = &(g554); int64_t _i4645 = f_1561; (S1*)_t4645->b + hr_ix(_i4645, _t4645->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:220"); }))).a_)); 
S9 v_2095 = (*({ hrv *_t4646 = &(g560); int64_t _i4646 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4647 = &(g559); int64_t _i4647 = ei_2094; (S8*)_t4647->b + hr_ix(_i4647, _t4647->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:220"); }))).v0_)) + (int64_t)vi_2093)); (S9*)_t4646->b + hr_ix(_i4646, _t4646->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:220"); })); 
int64_t p_2096 = f295_nt(); 
(void)(f262_ow(hr_str("({ ", 3)));
(void)(f263_ct(t_1562));
(void)(f262_ow(hr_str(" _t", 3)));
(void)(f296_oi(p_2096));
(void)(f262_ow(hr_str("; memset(&_t", 12)));
(void)(f296_oi(p_2096));
(void)(f262_ow(hr_str(", 0, sizeof _t", 14)));
(void)(f296_oi(p_2096));
(void)(f262_ow(hr_str("); _t", 5)));
(void)(f296_oi(p_2096));
(void)(({ hrv *_o4659 = &(g163); hr_fs(_o4659, hr_str(".tag = ", 7)); hr_fi(_o4659, vi_2093); hr_fs(_o4659, hr_str("; ", 2)); }));
if (((((v_2095).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4660 = &(g557); int64_t _i4660 = (v_2095).si_; (S10*)_t4660->b + hr_ix(_i4660, _t4660->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:223"); }))).zero_)))) { (void)(f262_ow(hr_str("_t", 2)));
(void)(f296_oi(p_2096));
(void)(({ hrv *_o4663 = &(g163); hr_fs(_o4663, hr_str(".u.v", 4)); hr_fi(_o4663, vi_2093); hr_fs(_o4663, hr_str(" = ", 3)); }));
(void)(f273_gx1(n_1560));
(void)(f262_ow(hr_str("; ", 2)));
 } else { (void)(f262_ow(hr_str("(void)(", 7)));
(void)(f273_gx1(n_1560));
(void)(f262_ow(hr_str("); ", 3)));
 }
(void)(f262_ow(hr_str("_t", 2)));
(void)(f296_oi(p_2096));
(void)(f262_ow(hr_str("; })", 4)));
return;
 }
if (((tk0_2091) == (((int64_t)10LL)))) { if (((fk_2090) == (((int64_t)10LL)))) { (void)(f273_gx1(n_1560));
return;
 }
(void)(f326_gaddr(n_1560));
return;
 }
if (f270_is_res(t_1562)) { (void)(f262_ow(hr_str("hr_rfrom(", 9)));
(void)(f294_gsl(n_1560, f_1561));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f328_esz(((int64_t)(((*({ hrv *_t4679 = &(g554); int64_t _i4679 = t_1562; (S1*)_t4679->b + hr_ix(_i4679, _t4679->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:228"); }))).a_))));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if ((f284_is_fix(t_1562) || f285_is_lim(t_1562))) { int64_t p_2097 = f295_nt(); 
(void)(f262_ow(hr_str("({ hsl _t", 9)));
(void)(f296_oi(p_2097));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f294_gsl(n_1560, f_1561));
(void)(f262_ow(hr_str("; ", 2)));
(void)(f263_ct(t_1562));
(void)(f262_ow(hr_str(" _r", 3)));
(void)(f296_oi(p_2097));
(void)(f262_ow(hr_str("; ", 2)));
if (f284_is_fix(t_1562)) { (void)(({ hrv *_o4694 = &(g163); hr_fs(_o4694, hr_str("if (_t", 6)); hr_fi(_o4694, p_2097); hr_fs(_o4694, hr_str(".n != ", 6)); hr_fi(_o4694, ((*({ hrv *_t4695 = &(g554); int64_t _i4695 = t_1562; (S1*)_t4695->b + hr_ix(_i4695, _t4695->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:232"); }))).b_); hr_fs(_o4694, hr_str(") hr_die(\"array length mismatch\", ", 34)); }));
(void)(f314_wloc(n_1560));
(void)(f262_ow(hr_str("); ", 3)));
 } else { (void)(({ hrv *_o4698 = &(g163); hr_fs(_o4698, hr_str("if (_t", 6)); hr_fi(_o4698, p_2097); hr_fs(_o4698, hr_str(".n > ", 5)); hr_fi(_o4698, ((*({ hrv *_t4699 = &(g554); int64_t _i4699 = t_1562; (S1*)_t4699->b + hr_ix(_i4699, _t4699->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:233"); }))).b_); hr_fs(_o4698, hr_str(") hr_die(\"too many elements for a limited array\", ", 50)); }));
(void)(f314_wloc(n_1560));
(void)(({ hrv *_o4701 = &(g163); hr_fs(_o4701, hr_str("); _r", 5)); hr_fi(_o4701, p_2097); hr_fs(_o4701, hr_str(".n = _t", 7)); hr_fi(_o4701, p_2097); hr_fs(_o4701, hr_str(".n; ", 4)); }));
 }
(void)(({ hrv *_o4702 = &(g163); hr_fs(_o4702, hr_str("memcpy(_r", 9)); hr_fi(_o4702, p_2097); hr_fs(_o4702, hr_str(".e, _t", 6)); hr_fi(_o4702, p_2097); hr_fs(_o4702, hr_str(".p, (size_t)_t", 14)); hr_fi(_o4702, p_2097); hr_fs(_o4702, hr_str(".n * sizeof _r", 14)); hr_fi(_o4702, p_2097); hr_fs(_o4702, hr_str(".e[0]); _r", 10)); hr_fi(_o4702, p_2097); hr_fs(_o4702, hr_str("; })", 4)); }));
return;
 }
(void)(f273_gx1(n_1560));
}
static void f273_gx1(int64_t n_1563) {
if ((f270_is_res(f141_at(n_1563)) && (!(f274_is_place(n_1563))))) { int64_t k_1571 = f275_tmp(f141_at(n_1563), true); 
(void)(f262_ow(hr_str("(*hr_tmp(&", 10)));
(void)(f276_ot(k_1571));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f277_gx0(n_1563));
(void)(f262_ow(hr_str("))", 2)));
return;
 }
(void)(f277_gx0(n_1563));
}
static bool f274_is_place(int64_t n_1564) {
S4 x_1565 = (*({ hrv *_t4715 = &(g707); int64_t _i4715 = n_1564; (S4*)_t4715->b + hr_ix(_i4715, _t4715->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:122"); })); 
int64_t k_1566 = ((int64_t)((x_1565).k_)); 
if (((k_1566) == (((int64_t)8LL)))) { int64_t r_1567 = f159_rk(n_1564); 
return (((r_1567) == (((int64_t)1LL))) || ((r_1567) == (((int64_t)2LL))));
 }
if (((k_1566) == (((int64_t)14LL)))) { return (((f159_rk(n_1564)) == (((int64_t)5LL))) && (f274_is_place(((int64_t)((x_1565).a_))) || ((((*({ hrv *_t4719 = &(g554); int64_t _i4719 = f141_at(((int64_t)((x_1565).a_))); (S1*)_t4719->b + hr_ix(_i4719, _t4719->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:124"); }))).k_) == (((uint8_t)10LL)))));
 }
if (((k_1566) == (((int64_t)12LL)))) { int64_t bt_1568 = f141_at(((int64_t)((x_1565).a_))); 
return ((((((*({ hrv *_t4722 = &(g554); int64_t _i4722 = f182_deref(bt_1568); (S1*)_t4722->b + hr_ix(_i4722, _t4722->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:125"); }))).k_) == (((uint8_t)9LL))) || f274_is_place(((int64_t)((x_1565).a_)))) || ((((*({ hrv *_t4725 = &(g554); int64_t _i4725 = bt_1568; (S1*)_t4725->b + hr_ix(_i4725, _t4725->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:125"); }))).k_) == (((uint8_t)10LL))));
 }
if ((((k_1566) == (((int64_t)10LL))) && ((((int64_t)((x_1565).op_))) == (((int64_t)49LL))))) { return f274_is_place(((int64_t)((x_1565).a_)));
 }
if (((((k_1566) == (((int64_t)11LL))) && ((f159_rk(n_1564)) == (((int64_t)4LL)))) && ((f160_rv(n_1564)) == (((int64_t)20LL))))) { return true;
 }
return false;
}
static int64_t f275_tmp(int64_t t_1569, bool clean_1570) {
(void)(f264_cbody(t_1569));
g178++;
(void)(({ hrv *_v4730 = &(g176); hsl _s4730 = f266_cn(t_1569); hr_append(_v4730, _s4730.p, _s4730.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4732 = &(g176); hr_fs(_o4732, hr_str(" _t", 3)); hr_fi(_o4732, g178); }));
if (clean_1570) { (void)(({ hrv *_v4733 = &(g176); hsl _s4733 = hr_str(" __attribute__((cleanup(hr_rdrop)))", 35); hr_append(_v4733, _s4733.p, _s4733.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4734 = &(g176); hsl _s4734 = hr_str(" = {0}; ", 8); hr_append(_v4734, _s4734.p, _s4734.n, sizeof(uint8_t)); }));
return g178;
}
static void f276_ot(int64_t k_1572) {
(void)(({ hrv *_o4735 = &(g163); hr_fs(_o4735, hr_str("_t", 2)); hr_fi(_o4735, k_1572); }));
}
static void f277_gx0(int64_t n_1573) {
S4 x_1574 = (*({ hrv *_t4736 = &(g707); int64_t _i4736 = n_1573; (S4*)_t4736->b + hr_ix(_i4736, _t4736->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:732"); })); 
int64_t k_1575 = ((int64_t)((x_1574).k_)); 
if (((k_1575) == (((int64_t)1LL)))) { (void)(f279_oint(((*({ hrv *_t4738 = &(g917); int64_t _i4738 = (x_1574).t_; (S3*)_t4738->b + hr_ix(_i4738, _t4738->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:734"); }))).v_, ((*({ hrv *_t4739 = &(g917); int64_t _i4739 = (x_1574).t_; (S3*)_t4739->b + hr_ix(_i4739, _t4739->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:734"); }))).uns_, f278_fin_lit(n_1573)));
return;
 }
if (((k_1575) == (((int64_t)2LL)))) { int64_t t_1582 = f278_fin_lit(n_1573); 
(void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(({ int64_t _r4744; if (((((*({ hrv *_t4745 = &(g554); int64_t _i4745 = t_1582; (S1*)_t4745->b + hr_ix(_i4745, _t4745->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:735"); }))).k_) == (((uint8_t)4LL)))) { _r4744 = t_1582;  } else { _r4744 = g572;  } _r4744; })));
(void)(f262_ow(hr_str(")", 1)));
(void)(f262_ow(f36_tok_text(((int64_t)((x_1574).t_)))));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if (((k_1575) == (((int64_t)3LL)))) { (void)(f280_gstr(n_1573));
return;
 }
if (((k_1575) == (((int64_t)4LL)))) { (void)(f262_ow(hr_str("true", 4)));
return;
 }
if (((k_1575) == (((int64_t)5LL)))) { (void)(f262_ow(hr_str("false", 5)));
return;
 }
if (((k_1575) == (((int64_t)6LL)))) { (void)(f262_ow(hr_str("((void*)0)", 10)));
return;
 }
if (((k_1575) == (((int64_t)8LL)))) { int64_t r_1596 = f159_rk(n_1573); 
if (((r_1596) == (((int64_t)1LL)))) { bool fc_1597 = (((((uint16_t)((uint64_t)((*({ hrv *_t4755 = &(g391); int64_t _i4755 = f160_rv(n_1573); (S12*)_t4755->b + hr_ix(_i4755, _t4755->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:742"); }))).fl_ & (uint64_t)((uint16_t)64LL)))) != (((uint16_t)0LL))) && ((f141_at(n_1573)) != (((int64_t)(((*({ hrv *_t4758 = &(g391); int64_t _i4758 = f160_rv(n_1573); (S12*)_t4758->b + hr_ix(_i4758, _t4758->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:742"); }))).ty_))))); 
if (fc_1597) { (void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(f141_at(n_1573)));
(void)(f262_ow(hr_str(")", 1)));
 }
(void)(f286_lv_expr(f160_rv(n_1573)));
if (fc_1597) { (void)(f262_ow(hr_str(")", 1)));
 }
return;
 }
if (((r_1596) == (((int64_t)2LL)))) { (void)(({ hrv *_o4767 = &(g163); hr_fs(_o4767, hr_str("g", 1)); hr_fi(_o4767, f160_rv(n_1573)); }));
return;
 }
if (((r_1596) == (((int64_t)6LL)))) { (void)(f279_oint((*({ hrv *_t4770 = &(g438); int64_t _i4770 = f160_rv(n_1573); (int64_t*)_t4770->b + hr_ix(_i4770, _t4770->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:744"); })), false, f278_fin_lit(n_1573)));
return;
 }
(void)(f289_gerr(n_1573, hr_str("unsupported name use", 20)));
return;
 }
if (((k_1575) == (((int64_t)9LL)))) { (void)(f290_gbin(n_1573));
return;
 }
if (((k_1575) == (((int64_t)10LL)))) { (void)(f315_gun(n_1573));
return;
 }
if (((k_1575) == (((int64_t)14LL)))) { int64_t r_1790 = f159_rk(n_1573); 
int64_t a_1791 = ((int64_t)((x_1574).a_)); 
if ((((r_1790) == (((int64_t)7LL))) && ((((*({ hrv *_t4777 = &(g554); int64_t _i4777 = f141_at(n_1573); (S1*)_t4777->b + hr_ix(_i4777, _t4777->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); }))).k_) == (((uint8_t)7LL))))) { int64_t t_1792 = f141_at(n_1573); 
S9 v_1793 = (*({ hrv *_t4780 = &(g560); int64_t _i4780 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4781 = &(g559); int64_t _i4781 = ((*({ hrv *_t4782 = &(g554); int64_t _i4782 = t_1792; (S1*)_t4782->b + hr_ix(_i4782, _t4782->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); }))).a_; (S8*)_t4781->b + hr_ix(_i4781, _t4781->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t4783 = &(g554); int64_t _i4783 = t_1792; (S1*)_t4783->b + hr_ix(_i4783, _t4783->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); }))).c_)))); (S9*)_t4780->b + hr_ix(_i4780, _t4780->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); })); 
if ((((v_1793).si_) >= (((int32_t)0LL)))) { (void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(t_1792));
(void)(f262_ow(hr_str("){0})", 5)));
 } else { (void)(f262_ow(hr_str("((hr_unit)0)", 12)));
 }
return;
 }
if (((r_1790) == (((int64_t)7LL)))) { int64_t t_1794 = f141_at(n_1573); 
int64_t p_1795 = f295_nt(); 
(void)(f262_ow(hr_str("({ ", 3)));
(void)(f263_ct(t_1794));
(void)(f262_ow(hr_str(" _t", 3)));
(void)(f296_oi(p_1795));
(void)(({ hrv *_o4794 = &(g163); hr_fs(_o4794, hr_str("; memset(&_t", 12)); hr_fi(_o4794, p_1795); hr_fs(_o4794, hr_str(", 0, sizeof _t", 14)); hr_fi(_o4794, p_1795); hr_fs(_o4794, hr_str("); _t", 5)); hr_fi(_o4794, p_1795); hr_fs(_o4794, hr_str(".tag = ", 7)); hr_fi(_o4794, f160_rv(n_1573)); hr_fs(_o4794, hr_str("; _t", 4)); hr_fi(_o4794, p_1795); hr_fs(_o4794, hr_str("; })", 4)); }));
return;
 }
if (((r_1790) == (((int64_t)8LL)))) { int64_t d_1796 = f182_deref(f141_at(a_1791)); 
if (((f160_rv(n_1573)) == (((int64_t)2LL)))) { (void)(({ hrv *_o4799 = &(g163); hr_fs(_o4799, hr_str("((int64_t)", 10)); hr_fi(_o4799, ((*({ hrv *_t4800 = &(g554); int64_t _i4800 = d_1796; (S1*)_t4800->b + hr_ix(_i4800, _t4800->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:756"); }))).b_); hr_fs(_o4799, hr_str(")", 1)); }));
return;
 }
if (f284_is_fix(d_1796)) { (void)(({ hrv *_o4802 = &(g163); hr_fs(_o4802, hr_str("((int64_t)", 10)); hr_fi(_o4802, ((*({ hrv *_t4803 = &(g554); int64_t _i4803 = d_1796; (S1*)_t4803->b + hr_ix(_i4803, _t4803->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:757"); }))).b_); hr_fs(_o4802, hr_str(")", 1)); }));
return;
 }
if (f285_is_lim(d_1796)) { (void)(f262_ow(hr_str("((int64_t)(", 11)));
if (((((*({ hrv *_t4806 = &(g554); int64_t _i4806 = f141_at(a_1791); (S1*)_t4806->b + hr_ix(_i4806, _t4806->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:758"); }))).k_) == (((uint8_t)10LL)))) { (void)(f277_gx0(a_1791));
(void)(f262_ow(hr_str(")->n)", 5)));
 } else { (void)(f291_gx(a_1791));
(void)(f262_ow(hr_str(").n)", 4)));
 }
return;
 }
if (((((*({ hrv *_t4812 = &(g554); int64_t _i4812 = f141_at(a_1791); (S1*)_t4812->b + hr_ix(_i4812, _t4812->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:759"); }))).k_) == (((uint8_t)10LL)))) { (void)(f262_ow(hr_str("((", 2)));
(void)(f277_gx0(a_1791));
(void)(f262_ow(hr_str(")->n)", 5)));
return;
 }
(void)(f262_ow(hr_str("(", 1)));
(void)(f291_gx(a_1791));
(void)(f262_ow(hr_str(").n", 3)));
return;
 }
if (((r_1790) == (((int64_t)5LL)))) { int64_t bt_1797 = f141_at(a_1791); 
int64_t st_1798 = f182_deref(bt_1797); 
int64_t si_1799 = ({ int64_t _r4822; if (((((*({ hrv *_t4823 = &(g554); int64_t _i4823 = st_1798; (S1*)_t4823->b + hr_ix(_i4823, _t4823->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:765"); }))).k_) == (((uint8_t)5LL)))) { _r4822 = ((int64_t)(((*({ hrv *_t4824 = &(g554); int64_t _i4824 = st_1798; (S1*)_t4824->b + hr_ix(_i4824, _t4824->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:765"); }))).a_));  } else { _r4822 = f219_ax(n_1573);  } _r4822; }); 
S11 f_1800 = (*({ hrv *_t4826 = &(g558); int64_t _i4826 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4827 = &(g557); int64_t _i4827 = si_1799; (S10*)_t4827->b + hr_ix(_i4827, _t4827->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:766"); }))).f0_)) + (int64_t)f160_rv(n_1573))); (S11*)_t4826->b + hr_ix(_i4826, _t4826->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:766"); })); 
(void)(f262_ow(hr_str("(", 1)));
if (((((*({ hrv *_t4830 = &(g554); int64_t _i4830 = bt_1797; (S1*)_t4830->b + hr_ix(_i4830, _t4830->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:768"); }))).k_) == (((uint8_t)10LL)))) { (void)(f277_gx0(a_1791));
(void)(f262_ow(hr_str(")->", 3)));
 } else { (void)(f291_gx(a_1791));
(void)(f262_ow(hr_str(").", 2)));
 }
(void)(f269_fname_into((&(g163)), ((int64_t)((f_1800).name_))));
return;
 }
(void)(f289_gerr(n_1573, hr_str("unsupported member", 18)));
return;
 }
if (((k_1575) == (((int64_t)12LL)))) { (void)(f317_gidx(n_1573));
return;
 }
if (((k_1575) == (((int64_t)13LL)))) { (void)(f318_gslice(n_1573));
return;
 }
if (((k_1575) == (((int64_t)15LL)))) { int64_t t_1815 = f141_at(n_1573); 
int64_t ft_1816 = ((int64_t)(((*({ hrv *_t4840 = &(g554); int64_t _i4840 = f281_fin(((int64_t)((x_1574).a_))); (S1*)_t4840->b + hr_ix(_i4840, _t4840->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:776"); }))).k_)); 
if ((((((*({ hrv *_t4842 = &(g554); int64_t _i4842 = t_1815; (S1*)_t4842->b + hr_ix(_i4842, _t4842->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:776"); }))).k_) == (((uint8_t)3LL))) && (((ft_1816) == (((int64_t)4LL))) || ((ft_1816) == (((int64_t)13LL)))))) { (void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(t_1815));
(void)(f262_ow(hr_str(")hr_f2i(", 8)));
(void)(f291_gx(((int64_t)((x_1574).a_))));
(void)(f262_ow(hr_str("))", 2)));
return;
 }
(void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(t_1815));
(void)(f262_ow(hr_str(")(", 2)));
(void)(f291_gx(((int64_t)((x_1574).a_))));
(void)(f262_ow(hr_str("))", 2)));
return;
 }
if (((k_1575) == (((int64_t)16LL)))) { (void)(f319_garr(n_1573));
return;
 }
if (((k_1575) == (((int64_t)17LL)))) { (void)(f320_gslit(n_1573));
return;
 }
if (((k_1575) == (((int64_t)11LL)))) { (void)(f321_gcall(n_1573));
return;
 }
if (((k_1575) == (((int64_t)23LL)))) { (void)(f262_ow(hr_str("({ ", 3)));
(void)(f344_gblk(n_1573, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((f141_at(n_1573)) != (g561))));
(void)(f262_ow(hr_str(" })", 3)));
return;
 }
if ((((((k_1575) == (((int64_t)19LL))) || ((k_1575) == (((int64_t)20LL)))) || ((k_1575) == (((int64_t)24LL)))) || ((k_1575) == (((int64_t)26LL))))) { int64_t t_2088 = f141_at(n_1573); 
if ((((t_2088) == (g561)) || ((t_2088) < (((int64_t)0LL))))) { (void)(f262_ow(hr_str("({ ", 3)));
(void)(f337_gstmt(n_1573));
(void)(f262_ow(hr_str(" })", 3)));
return;
 }
int64_t r_2089 = f295_nt(); 
(void)(f262_ow(hr_str("({ ", 3)));
(void)(f263_ct(t_2088));
(void)(f262_ow(hr_str(" _r", 3)));
(void)(f296_oi(r_2089));
(void)(f262_ow(hr_str("; ", 2)));
if (((k_1575) == (((int64_t)19LL)))) { (void)(f343_gif(n_1573, r_2089));
 } else { if (((k_1575) == (((int64_t)20LL)))) { (void)(f351_gmatch(n_1573, r_2089));
 } else { if (((k_1575) == (((int64_t)24LL)))) { (void)(f352_geblock(n_1573, r_2089));
 } else { (void)(f349_gloop(n_1573, r_2089));
 }
 }
 }
(void)(f262_ow(hr_str(" _r", 3)));
(void)(f296_oi(r_2089));
(void)(f262_ow(hr_str("; })", 4)));
return;
 }
if (((((((k_1575) == (((int64_t)28LL))) || ((k_1575) == (((int64_t)29LL)))) || ((k_1575) == (((int64_t)30LL)))) || ((k_1575) == (((int64_t)25LL)))) || ((k_1575) == (((int64_t)27LL))))) { (void)(f262_ow(hr_str("({ ", 3)));
(void)(f337_gstmt(n_1573));
(void)(f262_ow(hr_str(" })", 3)));
return;
 }
(void)(f289_gerr(n_1573, hr_str("unsupported expression in codegen", 33)));
}
static int64_t f278_fin_lit(int64_t n_1576) {
int64_t t_1577 = f141_at(n_1576); 
return ({ int64_t _r4882; if ((((t_1577) < (((int64_t)0LL))) || ((((*({ hrv *_t4883 = &(g554); int64_t _i4883 = t_1577; (S1*)_t4883->b + hr_ix(_i4883, _t4883->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:795"); }))).k_) == (((uint8_t)12LL))))) { _r4882 = g566;  } else { _r4882 = ({ int64_t _r4884; if (((((*({ hrv *_t4885 = &(g554); int64_t _i4885 = t_1577; (S1*)_t4885->b + hr_ix(_i4885, _t4885->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:795"); }))).k_) == (((uint8_t)13LL)))) { _r4884 = g572;  } else { _r4884 = t_1577;  } _r4884; });  } _r4882; });
}
static void f279_oint(int64_t v_1578, bool uns_1579, int64_t t_1580) {
int64_t k_1581 = ((int64_t)(((*({ hrv *_t4886 = &(g554); int64_t _i4886 = t_1580; (S1*)_t4886->b + hr_ix(_i4886, _t4886->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:140"); }))).k_)); 
if (((k_1581) == (((int64_t)4LL)))) { (void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(t_1580));
(void)(f262_ow(hr_str(")", 1)));
if (uns_1579) { (void)(({ hrv *_o4890 = &(g163); hr_fu(_o4890, ((uint64_t)(v_1578))); hr_fs(_o4890, hr_str(".0", 2)); }));
 } else { (void)(({ hrv *_o4891 = &(g163); hr_fi(_o4891, v_1578); hr_fs(_o4891, hr_str(".0", 2)); }));
 }
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if (((k_1581) == (((int64_t)2LL)))) { (void)(f262_ow(({ hsl _r4894; if (((v_1578) != (((int64_t)0LL)))) { _r4894 = hr_str("true", 4);  } else { _r4894 = hr_str("false", 5);  } _r4894; })));
return;
 }
(void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(({ int64_t _r4897; if (((k_1581) == (((int64_t)3LL)))) { _r4897 = t_1580;  } else { _r4897 = g566;  } _r4897; })));
(void)(f262_ow(hr_str(")", 1)));
if (uns_1579) { (void)(({ hrv *_o4899 = &(g163); hr_fu(_o4899, ((uint64_t)(v_1578))); hr_fs(_o4899, hr_str("ULL)", 4)); }));
return;
 }
if (((v_1578) == (((int64_t)((int64_t)((int64_t)(0 - (uint64_t)(((int64_t)9223372036854775807LL)))) - (int64_t)((int64_t)1LL)))))) { (void)(f262_ow(hr_str("(-9223372036854775807LL-1))", 27)));
return;
 }
(void)(({ hrv *_o4901 = &(g163); hr_fi(_o4901, v_1578); hr_fs(_o4901, hr_str("LL)", 3)); }));
}
static void f280_gstr(int64_t n_1583) {
int64_t t_1587 = f281_fin(n_1583); 
hsl s_1590 = f282_tok_str(((int64_t)(((*({ hrv *_t4904 = &(g707); int64_t _i4904 = n_1583; (S4*)_t4904->b + hr_ix(_i4904, _t4904->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:345"); }))).t_))); 
int64_t a_1591 = f141_at(n_1583); 
if (f270_is_res(a_1591)) { (void)(f262_ow(hr_str("hr_rfrom(hr_str(", 16)));
(void)(f283_cstr_lit(s_1590));
(void)(({ hrv *_o4909 = &(g163); hr_fs(_o4909, hr_str(", ", 2)); hr_fi(_o4909, (s_1590).n); hr_fs(_o4909, hr_str("), 1)", 5)); }));
return;
 }
if (f284_is_fix(a_1591)) { (void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(a_1591));
(void)(f262_ow(hr_str("){ ", 3)));
(void)(f283_cstr_lit(s_1590));
(void)(f262_ow(hr_str(" })", 3)));
return;
 }
if (f285_is_lim(a_1591)) { (void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(a_1591));
(void)(({ hrv *_o4919 = &(g163); hr_fs(_o4919, hr_str("){ ", 3)); hr_fi(_o4919, (s_1590).n); hr_fs(_o4919, hr_str(", ", 2)); }));
(void)(f283_cstr_lit(s_1590));
(void)(f262_ow(hr_str(" })", 3)));
return;
 }
(void)(f262_ow(hr_str("hr_str(", 7)));
(void)(f283_cstr_lit(s_1590));
(void)(({ hrv *_o4924 = &(g163); hr_fs(_o4924, hr_str(", ", 2)); hr_fi(_o4924, (s_1590).n); hr_fs(_o4924, hr_str(")", 1)); }));
}
static int64_t f281_fin(int64_t n_1584) {
int64_t c_1585 = f153_cv(n_1584); 
return ({ int64_t _r4926; if (((c_1585) >= (((int64_t)0LL)))) { _r4926 = c_1585;  } else { int64_t t_1586 = f141_at(n_1584); 
_r4926 = ({ int64_t _r4928; if (((t_1586) < (((int64_t)0LL)))) { _r4928 = g561;  } else { _r4928 = t_1586;  } _r4928; });  } _r4926; });
}
static hsl f282_tok_str(int64_t t_1588) {
S3 x_1589 = (*({ hrv *_t4929 = &(g917); int64_t _i4929 = t_1588; (S3*)_t4929->b + hr_ix(_i4929, _t4929->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:182"); })); 
return ({ hsl _t4930 = hr_sl(g913); int64_t _l4930 = ((int64_t)((x_1589).v_)), _h4930 = ((int64_t)((int64_t)((int64_t)((x_1589).v_)) + (int64_t)((int64_t)((x_1589).w_)))); if (_l4930 < 0 || _h4930 < _l4930 || _h4930 > _t4930.n) hr_slerr(_l4930, _h4930, _t4930.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:182"); (hsl){ _t4930.p + _l4930 * (int64_t)sizeof(uint8_t), _h4930 - _l4930 }; });
}
static void f283_cstr_lit(hsl s_1592) {
(void)(({ hrv *_v4931 = &(g163); uint8_t _x4931 = ((uint8_t)34LL); uint8_t *_p4931 = (uint8_t*)hr_grow(_v4931, 1, sizeof _x4931); *_p4931 = _x4931; _p4931; }));
{ hsl _v4933 = s_1592; for (int64_t _k4933 = 0; _k4933 < _v4933.n; _k4933++) { uint8_t c_1593 = ((uint8_t*)_v4933.p)[_k4933]; if ((((c_1593) == (((uint8_t)34LL))) || ((c_1593) == (((uint8_t)92LL))))) { (void)(({ hrv *_v4934 = &(g163); uint8_t _x4934 = ((uint8_t)92LL); uint8_t *_p4934 = (uint8_t*)hr_grow(_v4934, 1, sizeof _x4934); *_p4934 = _x4934; _p4934; }));
(void)(({ hrv *_v4935 = &(g163); uint8_t _x4935 = c_1593; uint8_t *_p4935 = (uint8_t*)hr_grow(_v4935, 1, sizeof _x4935); *_p4935 = _x4935; _p4935; }));
 } else { if (((((c_1593) >= (((uint8_t)32LL))) && ((c_1593) < (((uint8_t)127LL)))) && ((c_1593) != (((uint8_t)63LL))))) { (void)(({ hrv *_v4936 = &(g163); uint8_t _x4936 = c_1593; uint8_t *_p4936 = (uint8_t*)hr_grow(_v4936, 1, sizeof _x4936); *_p4936 = _x4936; _p4936; }));
 } else { (void)(({ hrv *_v4937 = &(g163); uint8_t _x4937 = ((uint8_t)92LL); uint8_t *_p4937 = (uint8_t*)hr_grow(_v4937, 1, sizeof _x4937); *_p4937 = _x4937; _p4937; }));
(void)(({ hrv *_v4938 = &(g163); uint8_t _x4938 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)((uint8_t)((c_1593) >> ((((int64_t)6LL)) & 7))) & (uint64_t)((uint8_t)7LL))))); uint8_t *_p4938 = (uint8_t*)hr_grow(_v4938, 1, sizeof _x4938); *_p4938 = _x4938; _p4938; }));
(void)(({ hrv *_v4939 = &(g163); uint8_t _x4939 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)((uint8_t)((c_1593) >> ((((int64_t)3LL)) & 7))) & (uint64_t)((uint8_t)7LL))))); uint8_t *_p4939 = (uint8_t*)hr_grow(_v4939, 1, sizeof _x4939); *_p4939 = _x4939; _p4939; }));
(void)(({ hrv *_v4940 = &(g163); uint8_t _x4940 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)c_1593 & (uint64_t)((uint8_t)7LL))))); uint8_t *_p4940 = (uint8_t*)hr_grow(_v4940, 1, sizeof _x4940); *_p4940 = _x4940; _p4940; }));
 }
 }
 } } _bk4932:; 
(void)(({ hrv *_v4941 = &(g163); uint8_t _x4941 = ((uint8_t)34LL); uint8_t *_p4941 = (uint8_t*)hr_grow(_v4941, 1, sizeof _x4941); *_p4941 = _x4941; _p4941; }));
}
static bool f284_is_fix(int64_t t_1594) {
return (((((*({ hrv *_t4942 = &(g554); int64_t _i4942 = t_1594; (S1*)_t4942->b + hr_ix(_i4942, _t4942->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:20"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t4943 = &(g554); int64_t _i4943 = t_1594; (S1*)_t4943->b + hr_ix(_i4943, _t4943->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:20"); }))).s_))) == (((int64_t)1LL))));
}
static bool f285_is_lim(int64_t t_1595) {
return (((((*({ hrv *_t4944 = &(g554); int64_t _i4944 = t_1595; (S1*)_t4944->b + hr_ix(_i4944, _t4944->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:19"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t4945 = &(g554); int64_t _i4945 = t_1595; (S1*)_t4945->b + hr_ix(_i4945, _t4945->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:19"); }))).s_))) == (((int64_t)3LL))));
}
static void f286_lv_expr(int64_t v_1598) {
bool p_1600 = f287_lv_isptr(v_1598); 
if (((((int64_t)(((*({ hrv *_t4947 = &(g391); int64_t _i4947 = v_1598; (S12*)_t4947->b + hr_ix(_i4947, _t4947->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:115"); }))).cfn_))) != (g179))) { (void)(f262_ow(({ hsl _r4949; if (p_1600) { _r4949 = hr_str("(**c", 4);  } else { _r4949 = hr_str("(*c", 3);  } _r4949; })));
(void)(({ hrv *_o4950 = &(g163); hr_fi(_o4950, v_1598); hr_fs(_o4950, hr_str(")", 1)); }));
return;
 }
if (p_1600) { (void)(f262_ow(hr_str("(*", 2)));
(void)(f288_lv_name(v_1598));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
(void)(f288_lv_name(v_1598));
}
static bool f287_lv_isptr(int64_t v_1599) {
return (((((uint16_t)((uint64_t)((*({ hrv *_t4955 = &(g391); int64_t _i4955 = v_1599; (S12*)_t4955->b + hr_ix(_i4955, _t4955->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:112"); }))).fl_ & (uint64_t)((uint16_t)8LL)))) != (((uint16_t)0LL))) && ((((*({ hrv *_t4956 = &(g554); int64_t _i4956 = ((*({ hrv *_t4957 = &(g391); int64_t _i4957 = v_1599; (S12*)_t4957->b + hr_ix(_i4957, _t4957->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:112"); }))).ty_; (S1*)_t4956->b + hr_ix(_i4956, _t4956->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:112"); }))).k_) != (((uint8_t)10LL))));
}
static void f288_lv_name(int64_t v_1601) {
{ hsl _v4959 = f10_nm(((int64_t)(((*({ hrv *_t4961 = &(g391); int64_t _i4961 = v_1601; (S12*)_t4961->b + hr_ix(_i4961, _t4961->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:111"); }))).name_))); for (int64_t _k4959 = 0; _k4959 < _v4959.n; _k4959++) { uint8_t c_1602 = ((uint8_t*)_v4959.p)[_k4959]; (void)(({ hrv *_v4962 = &(g163); uint8_t _x4962 = ({ uint8_t _r4963; if ((((c_1602) == (((uint8_t)36LL))) || ((c_1602) == (((uint8_t)58LL))))) { _r4963 = ((uint8_t)95LL);  } else { _r4963 = c_1602;  } _r4963; }); uint8_t *_p4962 = (uint8_t*)hr_grow(_v4962, 1, sizeof _x4962); *_p4962 = _x4962; _p4962; }));
 } } _bk4958:; 
(void)(({ hrv *_o4964 = &(g163); hr_fs(_o4964, hr_str("_", 1)); hr_fi(_o4964, v_1601); }));
}
static void f289_gerr(int64_t n_1603, hsl m_1604) {
if ((((g182).n) > (((int64_t)0LL)))) { return;
 }
S3 x_1605 = (*({ hrv *_t4965 = &(g917); int64_t _i4965 = ((*({ hrv *_t4966 = &(g707); int64_t _i4966 = f103_max(n_1603, ((int64_t)0LL)); (S4*)_t4966->b + hr_ix(_i4966, _t4966->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:15"); }))).t_; (S3*)_t4965->b + hr_ix(_i4965, _t4965->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:15"); })); 
(void)(({ hrv *_v4968 = &(g182); hsl _s4968 = f10_nm(((int64_t)(((*({ hrv *_t4970 = &(g916); int64_t _i4970 = (x_1605).f_; (S2*)_t4970->b + hr_ix(_i4970, _t4970->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:15"); }))).name_))); hr_append(_v4968, _s4968.p, _s4968.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4971 = &(g182); hr_fs(_o4971, hr_str(":", 1)); hr_fi(_o4971, (x_1605).line_); hr_fs(_o4971, hr_str(": error: ", 9)); hr_fs(_o4971, m_1604); }));
}
static void f290_gbin(int64_t n_1606) {
S4 x_1607 = (*({ hrv *_t4972 = &(g707); int64_t _i4972 = n_1606; (S4*)_t4972->b + hr_ix(_i4972, _t4972->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:263"); })); 
int64_t o_1608 = ((int64_t)((x_1607).op_)); 
int64_t a_1609 = ((int64_t)((x_1607).a_)); 
int64_t b_1610 = ((int64_t)((x_1607).b_)); 
if ((((o_1608) == (((int64_t)52LL))) || ((o_1608) == (((int64_t)53LL))))) { (void)(f262_ow(hr_str("(", 1)));
(void)(f291_gx(a_1609));
(void)(f262_ow(({ hsl _r4976; if (((o_1608) == (((int64_t)52LL)))) { _r4976 = hr_str(" && ", 4);  } else { _r4976 = hr_str(" || ", 4);  } _r4976; })));
(void)(f291_gx(b_1610));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
bool cmp_1614 = (((((((o_1608) == (((int64_t)37LL))) || ((o_1608) == (((int64_t)38LL)))) || ((o_1608) == (((int64_t)39LL)))) || ((o_1608) == (((int64_t)40LL)))) || ((o_1608) == (((int64_t)41LL)))) || ((o_1608) == (((int64_t)42LL)))); 
if (cmp_1614) { int64_t m_1615 = f219_ax(n_1606); 
int64_t ta_1616 = f281_fin(a_1609); 
int64_t tb_1617 = f281_fin(b_1610); 
if (((m_1615) == (((int64_t)1LL)))) { (void)(f262_ow(hr_str("((uint64_t)(", 12)));
(void)(f291_gx(a_1609));
(void)(f262_ow(hr_str(") ", 2)));
(void)(f262_ow(f292_cmp_op(o_1608)));
(void)(f262_ow(hr_str(" (uint64_t)(", 12)));
(void)(f291_gx(b_1610));
(void)(f262_ow(hr_str("))", 2)));
return;
 }
if (((m_1615) == (((int64_t)2LL)))) { if (((o_1608) == (((int64_t)38LL)))) { (void)(f262_ow(hr_str("!", 1)));
 }
(void)(f262_ow(hr_str("hr_streq(", 9)));
(void)(f293_gas(a_1609));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f293_gas(b_1610));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if (((m_1615) == (((int64_t)3LL)))) { int64_t et_1632 = ({ int64_t _r4996; if ((((((*({ hrv *_t4997 = &(g554); int64_t _i4997 = ta_1616; (S1*)_t4997->b + hr_ix(_i4997, _t4997->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:271"); }))).k_) == (((uint8_t)7LL))) || ((((*({ hrv *_t4998 = &(g554); int64_t _i4998 = ta_1616; (S1*)_t4998->b + hr_ix(_i4998, _t4998->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:271"); }))).k_) == (((uint8_t)19LL))))) { _r4996 = tb_1617;  } else { _r4996 = ta_1616;  } _r4996; }); 
(void)(f297_gen_heq(et_1632));
if (((o_1608) == (((int64_t)38LL)))) { (void)(f262_ow(hr_str("!", 1)));
 }
(void)(f262_ow(hr_str("heq", 3)));
(void)(f296_oi(et_1632));
(void)(f262_ow(hr_str("(", 1)));
if (f307_hsl_ty(et_1632)) { (void)(f293_gas(a_1609));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f293_gas(b_1610));
 } else { (void)(f308_gxas(a_1609, et_1632));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f308_gxas(b_1610, et_1632));
 }
(void)(f262_ow(hr_str(")", 1)));
return;
 }
int64_t ka_1736 = ((int64_t)(((*({ hrv *_t5012 = &(g554); int64_t _i5012 = ta_1616; (S1*)_t5012->b + hr_ix(_i5012, _t5012->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:272"); }))).k_)); 
if (((((ka_1736) == (((int64_t)10LL))) || ((ka_1736) == (((int64_t)11LL)))) || ((((*({ hrv *_t5013 = &(g554); int64_t _i5013 = tb_1617; (S1*)_t5013->b + hr_ix(_i5013, _t5013->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:273"); }))).k_) == (((uint8_t)10LL))))) { (void)(f262_ow(hr_str("((void*)(", 9)));
(void)(f291_gx(a_1609));
(void)(f262_ow(hr_str(") ", 2)));
(void)(f262_ow(f292_cmp_op(o_1608)));
(void)(f262_ow(hr_str(" (void*)(", 9)));
(void)(f291_gx(b_1610));
(void)(f262_ow(hr_str("))", 2)));
return;
 }
(void)(f262_ow(hr_str("((", 2)));
(void)(f291_gx(a_1609));
(void)(f262_ow(hr_str(") ", 2)));
(void)(f262_ow(f292_cmp_op(o_1608)));
(void)(f262_ow(hr_str(" (", 2)));
(void)(f291_gx(b_1610));
(void)(f262_ow(hr_str("))", 2)));
return;
 }
(void)(f309_garith(o_1608, f281_fin(n_1606), a_1609, b_1610, ((int64_t)0LL), n_1606));
}
static void f291_gx(int64_t n_1611) {
int64_t c_1612 = f153_cv(n_1611); 
int64_t t_1613 = f141_at(n_1611); 
if ((((c_1612) < (((int64_t)0LL))) || ((c_1612) == (t_1613)))) { (void)(f273_gx1(n_1611));
return;
 }
(void)(f272_gcv(n_1611, t_1613, c_1612));
}
static hsl f292_cmp_op(int64_t o_1618) {
if (((o_1618) == (((int64_t)37LL)))) { return hr_str("==", 2);
 }
if (((o_1618) == (((int64_t)38LL)))) { return hr_str("!=", 2);
 }
if (((o_1618) == (((int64_t)39LL)))) { return hr_str("<", 1);
 }
if (((o_1618) == (((int64_t)40LL)))) { return hr_str(">", 1);
 }
if (((o_1618) == (((int64_t)41LL)))) { return hr_str("<=", 2);
 }
if (((o_1618) == (((int64_t)42LL)))) { return hr_str(">=", 2);
 }
return hr_str("\077", 1);
}
static void f293_gas(int64_t n_1619) {
int64_t c_1620 = f153_cv(n_1619); 
int64_t t_1621 = f141_at(n_1619); 
if (((((c_1620) >= (((int64_t)0LL))) && ((c_1620) != (t_1621))) && ((((*({ hrv *_t5038 = &(g554); int64_t _i5038 = c_1620; (S1*)_t5038->b + hr_ix(_i5038, _t5038->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:201"); }))).k_) == (((uint8_t)9LL))))) { (void)(f294_gsl(n_1619, t_1621));
return;
 }
if ((((c_1620) >= (((int64_t)0LL))) && ((c_1620) != (t_1621)))) { int64_t p_1631 = f295_nt(); 
(void)(f262_ow(hr_str("({ ", 3)));
(void)(f263_ct(c_1620));
(void)(f262_ow(hr_str(" _t", 3)));
(void)(f296_oi(p_1631));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(n_1619));
(void)(f262_ow(hr_str("; ", 2)));
if (f270_is_res(c_1620)) { (void)(f262_ow(hr_str("hr_sl(_t", 8)));
(void)(f296_oi(p_1631));
(void)(f262_ow(hr_str(")", 1)));
 } else { if (f284_is_fix(c_1620)) { (void)(f262_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f296_oi(p_1631));
(void)(({ hrv *_o5055 = &(g163); hr_fs(_o5055, hr_str(".e, ", 4)); hr_fi(_o5055, ((*({ hrv *_t5056 = &(g554); int64_t _i5056 = c_1620; (S1*)_t5056->b + hr_ix(_i5056, _t5056->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:202"); }))).b_); hr_fs(_o5055, hr_str(" }", 2)); }));
 } else { if (((((*({ hrv *_t5057 = &(g554); int64_t _i5057 = c_1620; (S1*)_t5057->b + hr_ix(_i5057, _t5057->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:202"); }))).k_) == (((uint8_t)9LL)))) { (void)(f262_ow(hr_str("_t", 2)));
(void)(f296_oi(p_1631));
 } else { (void)(f262_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f296_oi(p_1631));
(void)(f262_ow(hr_str(".e, _t", 6)));
(void)(f296_oi(p_1631));
(void)(f262_ow(hr_str(".n }", 4)));
 }
 }
 }
(void)(f262_ow(hr_str("; })", 4)));
return;
 }
(void)(f294_gsl(n_1619, t_1621));
}
static void f294_gsl(int64_t n_1622, int64_t f_1623) {
int64_t d_1624 = f182_deref(f_1623); 
int64_t k_1625 = ((int64_t)(((*({ hrv *_t5068 = &(g554); int64_t _i5068 = d_1624; (S1*)_t5068->b + hr_ix(_i5068, _t5068->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:178"); }))).k_)); 
if ((((((*({ hrv *_t5069 = &(g554); int64_t _i5069 = f_1623; (S1*)_t5069->b + hr_ix(_i5069, _t5069->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:179"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t5070 = &(g554); int64_t _i5070 = f_1623; (S1*)_t5070->b + hr_ix(_i5070, _t5070->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:179"); }))).c_) < (((int32_t)0LL))))) { int64_t p_1626 = f295_nt(); 
(void)(f262_ow(hr_str("({ ", 3)));
(void)(f263_ct(f_1623));
(void)(f262_ow(hr_str(" _t", 3)));
(void)(f296_oi(p_1626));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f277_gx0(n_1622));
(void)(f262_ow(hr_str("; ", 2)));
if (((k_1625) == (((int64_t)9LL)))) { (void)(f262_ow(hr_str("*_t", 3)));
(void)(f296_oi(p_1626));
 } else { if (f270_is_res(d_1624)) { (void)(f262_ow(hr_str("hr_sl(*_t", 9)));
(void)(f296_oi(p_1626));
(void)(f262_ow(hr_str(")", 1)));
 } else { if (f284_is_fix(d_1624)) { (void)(f262_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f296_oi(p_1626));
(void)(({ hrv *_o5088 = &(g163); hr_fs(_o5088, hr_str("->e, ", 5)); hr_fi(_o5088, ((*({ hrv *_t5089 = &(g554); int64_t _i5089 = d_1624; (S1*)_t5089->b + hr_ix(_i5089, _t5089->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:184"); }))).b_); hr_fs(_o5088, hr_str(" }", 2)); }));
 } else { (void)(f262_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f296_oi(p_1626));
(void)(f262_ow(hr_str("->e, _t", 7)));
(void)(f296_oi(p_1626));
(void)(f262_ow(hr_str("->n }", 5)));
 }
 }
 }
(void)(f262_ow(hr_str("; })", 4)));
return;
 }
if ((((k_1625) == (((int64_t)9LL))) || ((k_1625) == (((int64_t)18LL))))) { (void)(f277_gx0(n_1622));
return;
 }
if (f270_is_res(d_1624)) { (void)(f262_ow(hr_str("hr_sl(", 6)));
if (f274_is_place(n_1622)) { (void)(f277_gx0(n_1622));
 } else { int64_t tk0_1628 = f275_tmp(d_1624, true); 
(void)(f262_ow(hr_str("*hr_tmp(&", 9)));
(void)(f276_ot(tk0_1628));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f277_gx0(n_1622));
(void)(f262_ow(hr_str(")", 1)));
 }
(void)(f262_ow(hr_str(")", 1)));
return;
 }
int64_t p_1629 = f295_nt(); 
(void)(f262_ow(hr_str("({ ", 3)));
(void)(f263_ct(d_1624));
(void)(f262_ow(hr_str(" *_t", 4)));
(void)(f296_oi(p_1629));
(void)(f262_ow(hr_str(" = ", 3)));
if (f274_is_place(n_1622)) { (void)(f262_ow(hr_str("&(", 2)));
(void)(f277_gx0(n_1622));
(void)(f262_ow(hr_str(")", 1)));
 } else { int64_t tk0_1630 = f275_tmp(d_1624, false); 
(void)(f262_ow(hr_str("(", 1)));
(void)(f276_ot(tk0_1630));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f277_gx0(n_1622));
(void)(f262_ow(hr_str(", &", 3)));
(void)(f276_ot(tk0_1630));
(void)(f262_ow(hr_str(")", 1)));
 }
(void)(f262_ow(hr_str("; ", 2)));
if (f284_is_fix(d_1624)) { (void)(f262_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f296_oi(p_1629));
(void)(({ hrv *_o5130 = &(g163); hr_fs(_o5130, hr_str("->e, ", 5)); hr_fi(_o5130, ((*({ hrv *_t5131 = &(g554); int64_t _i5131 = d_1624; (S1*)_t5131->b + hr_ix(_i5131, _t5131->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:195"); }))).b_); hr_fs(_o5130, hr_str(" }", 2)); }));
 } else { (void)(f262_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f296_oi(p_1629));
(void)(f262_ow(hr_str("->e, _t", 7)));
(void)(f296_oi(p_1629));
(void)(f262_ow(hr_str("->n }", 5)));
 }
(void)(f262_ow(hr_str("; })", 4)));
}
static int64_t f295_nt(void) {
g178++;
return g178;
}
static void f296_oi(int64_t v_1627) {
(void)(({ hrv *_o5138 = &(g163); hr_fi(_o5138, v_1627); }));
}
static void f297_gen_heq(int64_t t_1633) {
(void)(f265_cn_grow());
if ((((*({ hrv *_t5140 = &(g175); int64_t _i5140 = t_1633; (uint8_t*)_t5140->b + hr_ix(_i5140, _t5140->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:485"); }))) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t5141 = &((*({ hrv *_t5142 = &(g175); int64_t _i5142 = t_1633; (uint8_t*)_t5142->b + hr_ix(_i5142, _t5142->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:486"); }))); *_t5141 = ((uint8_t)1LL); }
S1 x_1634 = (*({ hrv *_t5143 = &(g554); int64_t _i5143 = t_1633; (S1*)_t5143->b + hr_ix(_i5143, _t5143->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:487"); })); 
int64_t k_1635 = ((int64_t)((x_1634).k_)); 
(void)(f264_cbody(t_1633));
bool sl_1636 = (((k_1635) == (((int64_t)9LL))) || ((((k_1635) == (((int64_t)8LL))) && (!(f284_is_fix(t_1633)))) && (!(f285_is_lim(t_1633))))); 
(void)(f298_comp_pre(t_1633, false));
L97 sig_1710 = ({ L97 _t5148; memset(&_t5148, 0, sizeof _t5148); _t5148.n = 0; _t5148; }); 
(void)(({ L97 *_l5149 = &(sig_1710); hrv _o5149 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5149, hr_str("static bool heq", 15)); hr_fi(&_o5149, t_1633); hr_fs(&_o5149, hr_str("(", 1)); if (_l5149->n + _o5149.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:492"); memcpy(_l5149->e + _l5149->n, _o5149.b, (size_t)_o5149.n); _l5149->n += _o5149.n; }));
hsl c_1711 = ({ hsl _r5150; if (sl_1636) { _r5150 = hr_str("hsl", 3);  } else { _r5150 = f266_cn(t_1633);  } _r5150; }); 
(void)(({ L97 *_v5152 = &(sig_1710); hsl _s5152 = c_1711; if (_v5152->n + _s5152.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:494"); memmove(_v5152->e + _v5152->n, _s5152.p, (size_t)_s5152.n * sizeof _v5152->e[0]); _v5152->n += _s5152.n; }));
(void)(({ L97 *_v5153 = &(sig_1710); hsl _s5153 = hr_str(" a, ", 4); if (_v5153->n + _s5153.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:494"); memmove(_v5153->e + _v5153->n, _s5153.p, (size_t)_s5153.n * sizeof _v5153->e[0]); _v5153->n += _s5153.n; }));
(void)(({ L97 *_v5154 = &(sig_1710); hsl _s5154 = c_1711; if (_v5154->n + _s5154.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:494"); memmove(_v5154->e + _v5154->n, _s5154.p, (size_t)_s5154.n * sizeof _v5154->e[0]); _v5154->n += _s5154.n; }));
(void)(({ L97 *_v5155 = &(sig_1710); hsl _s5155 = hr_str(" b)", 3); if (_v5155->n + _s5155.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:494"); memmove(_v5155->e + _v5155->n, _s5155.p, (size_t)_s5155.n * sizeof _v5155->e[0]); _v5155->n += _s5155.n; }));
(void)(({ hrv *_v5156 = &(g166); hsl _s5156 = ({ hsl _t5157 = ({ L97 *_t5158 = &(sig_1710); (hsl){ (uint8_t*)_t5158->e, _t5158->n }; }); int64_t _l5157 = 0, _h5157 = _t5157.n; if (_l5157 < 0 || _h5157 < _l5157 || _h5157 > _t5157.n) hr_slerr(_l5157, _h5157, _t5157.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:495"); (hsl){ _t5157.p + _l5157 * (int64_t)sizeof(uint8_t), _h5157 - _l5157 }; }); hr_append(_v5156, _s5156.p, _s5156.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5159 = &(g166); hsl _s5159 = hr_str(";\012", 2); hr_append(_v5159, _s5159.p, _s5159.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5160 = &(g169); hsl _s5160 = ({ hsl _t5161 = ({ L97 *_t5162 = &(sig_1710); (hsl){ (uint8_t*)_t5162->e, _t5162->n }; }); int64_t _l5161 = 0, _h5161 = _t5161.n; if (_l5161 < 0 || _h5161 < _l5161 || _h5161 > _t5161.n) hr_slerr(_l5161, _h5161, _t5161.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:496"); (hsl){ _t5161.p + _l5161 * (int64_t)sizeof(uint8_t), _h5161 - _l5161 }; }); hr_append(_v5160, _s5160.p, _s5160.n, sizeof(uint8_t)); }));
(void)(f303_hh(hr_str(" { ", 3)));
if ((((k_1635) == (((int64_t)5LL))) || ((k_1635) == (((int64_t)7LL))))) { int64_t si_1712 = ({ int64_t _r5164; if (((k_1635) == (((int64_t)5LL)))) { _r5164 = ((int64_t)((x_1634).a_));  } else { _r5164 = ((int64_t)(((*({ hrv *_t5165 = &(g560); int64_t _i5165 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5166 = &(g559); int64_t _i5166 = (x_1634).a_; (S8*)_t5166->b + hr_ix(_i5166, _t5166->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:498"); }))).v0_)) + (int64_t)((int64_t)((x_1634).c_)))); (S9*)_t5165->b + hr_ix(_i5165, _t5165->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:498"); }))).si_));  } _r5164; }); 
(void)(f303_hh(hr_str("return true", 11)));
if (((si_1712) >= (((int64_t)0LL)))) { int64_t f0_1713 = ((int64_t)(((*({ hrv *_t5168 = &(g557); int64_t _i5168 = si_1712; (S10*)_t5168->b + hr_ix(_i5168, _t5168->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); }))).f0_)); 
{ int32_t _e5170 = ((*({ hrv *_t5171 = &(g557); int64_t _i5171 = si_1712; (S10*)_t5171->b + hr_ix(_i5171, _t5171->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); }))).fnum_; for (int32_t _k5170 = 0; _k5170 < _e5170; _k5170++) { int32_t i_1714 = (int32_t)_k5170; S11 f_1715 = (*({ hrv *_t5172 = &(g558); int64_t _i5172 = ((int64_t)((int64_t)f0_1713 + (int64_t)((int64_t)(i_1714)))); (S11*)_t5172->b + hr_ix(_i5172, _t5172->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); })); 
if ((((f_1715).ty_) < (((int32_t)0LL)))) { continue;
 }
L98 ea_1716 = ({ L98 _t5173; memset(&_t5173, 0, sizeof _t5173); _t5173.n = 0; _t5173; }); 
L98 eb_1717 = ({ L98 _t5174; memset(&_t5174, 0, sizeof _t5174); _t5174.n = 0; _t5174; }); 
(void)(({ L98 *_v5175 = &(ea_1716); hsl _s5175 = hr_str("a.", 2); if (_v5175->n + _s5175.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); memmove(_v5175->e + _v5175->n, _s5175.p, (size_t)_s5175.n * sizeof _v5175->e[0]); _v5175->n += _s5175.n; }));
(void)(({ L98 *_v5176 = &(eb_1717); hsl _s5176 = hr_str("b.", 2); if (_v5176->n + _s5176.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); memmove(_v5176->e + _v5176->n, _s5176.p, (size_t)_s5176.n * sizeof _v5176->e[0]); _v5176->n += _s5176.n; }));
{ hsl _v5178 = f10_nm(((int64_t)((f_1715).name_))); for (int64_t _k5178 = 0; _k5178 < _v5178.n; _k5178++) { uint8_t ch_1718 = ((uint8_t*)_v5178.p)[_k5178]; (void)(({ L98 *_v5180 = &(ea_1716); uint8_t _x5180 = ch_1718; if (_v5180->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); _v5180->e[_v5180->n] = _x5180; &_v5180->e[_v5180->n++]; }));
(void)(({ L98 *_v5181 = &(eb_1717); uint8_t _x5181 = ch_1718; if (_v5181->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); _v5181->e[_v5181->n] = _x5181; &_v5181->e[_v5181->n++]; }));
 } } _bk5177:; 
(void)(({ L98 *_v5182 = &(ea_1716); uint8_t _x5182 = ((uint8_t)95LL); if (_v5182->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); _v5182->e[_v5182->n] = _x5182; &_v5182->e[_v5182->n++]; }));
(void)(({ L98 *_v5183 = &(eb_1717); uint8_t _x5183 = ((uint8_t)95LL); if (_v5183->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); _v5183->e[_v5183->n] = _x5183; &_v5183->e[_v5183->n++]; }));
(void)(f303_hh(hr_str(" && ", 4)));
(void)(f306_heq_val(((int64_t)((f_1715).ty_)), ({ hsl _t5186 = ({ L98 *_t5187 = &(ea_1716); (hsl){ (uint8_t*)_t5187->e, _t5187->n }; }); int64_t _l5186 = 0, _h5186 = _t5186.n; if (_l5186 < 0 || _h5186 < _l5186 || _h5186 > _t5186.n) hr_slerr(_l5186, _h5186, _t5186.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); (hsl){ _t5186.p + _l5186 * (int64_t)sizeof(uint8_t), _h5186 - _l5186 }; }), ({ hsl _t5188 = ({ L98 *_t5189 = &(eb_1717); (hsl){ (uint8_t*)_t5189->e, _t5189->n }; }); int64_t _l5188 = 0, _h5188 = _t5188.n; if (_l5188 < 0 || _h5188 < _l5188 || _h5188 > _t5188.n) hr_slerr(_l5188, _h5188, _t5188.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); (hsl){ _t5188.p + _l5188 * (int64_t)sizeof(uint8_t), _h5188 - _l5188 }; })));
 } } _bk5169:; 
 }
(void)(f303_hh(hr_str("; ", 2)));
 }
if (((k_1635) == (((int64_t)6LL)))) { int64_t ei_1723 = ((int64_t)((x_1634).a_)); 
int64_t v0_1724 = ((int64_t)(((*({ hrv *_t5191 = &(g559); int64_t _i5191 = ei_1723; (S8*)_t5191->b + hr_ix(_i5191, _t5191->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:504"); }))).v0_)); 
(void)(f303_hh(hr_str("if (a.tag != b.tag) return false; ", 34)));
{ int32_t _e5194 = ((*({ hrv *_t5195 = &(g559); int64_t _i5195 = ei_1723; (S8*)_t5195->b + hr_ix(_i5195, _t5195->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); }))).vnum_; for (int32_t _k5194 = 0; _k5194 < _e5194; _k5194++) { int32_t i_1725 = (int32_t)_k5194; S9 v_1726 = (*({ hrv *_t5196 = &(g560); int64_t _i5196 = ((int64_t)((int64_t)v0_1724 + (int64_t)((int64_t)(i_1725)))); (S9*)_t5196->b + hr_ix(_i5196, _t5196->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); })); 
if (((((v_1726).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t5197 = &(g557); int64_t _i5197 = (v_1726).si_; (S10*)_t5197->b + hr_ix(_i5197, _t5197->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); }))).zero_)))) { L100 ea_1727 = ({ L100 _t5198; memset(&_t5198, 0, sizeof _t5198); _t5198.n = 0; _t5198; }); 
L100 eb_1728 = ({ L100 _t5199; memset(&_t5199, 0, sizeof _t5199); _t5199.n = 0; _t5199; }); 
(void)(({ L100 *_l5200 = &(ea_1727); hrv _o5200 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5200, hr_str("a.u.v", 5)); hr_fi(&_o5200, i_1725); if (_l5200->n + _o5200.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); memcpy(_l5200->e + _l5200->n, _o5200.b, (size_t)_o5200.n); _l5200->n += _o5200.n; }));
(void)(({ L100 *_l5201 = &(eb_1728); hrv _o5201 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5201, hr_str("b.u.v", 5)); hr_fi(&_o5201, i_1725); if (_l5201->n + _o5201.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); memcpy(_l5201->e + _l5201->n, _o5201.b, (size_t)_o5201.n); _l5201->n += _o5201.n; }));
(void)(({ hrv *_o5202 = &(g169); hr_fs(_o5202, hr_str("if (a.tag == ", 13)); hr_fi(_o5202, i_1725); hr_fs(_o5202, hr_str(") return ", 9)); }));
(void)(f306_heq_val(f125_t_variant(ei_1723, ((int64_t)(i_1725))), ({ hsl _t5205 = ({ L100 *_t5206 = &(ea_1727); (hsl){ (uint8_t*)_t5206->e, _t5206->n }; }); int64_t _l5205 = 0, _h5205 = _t5205.n; if (_l5205 < 0 || _h5205 < _l5205 || _h5205 > _t5205.n) hr_slerr(_l5205, _h5205, _t5205.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); (hsl){ _t5205.p + _l5205 * (int64_t)sizeof(uint8_t), _h5205 - _l5205 }; }), ({ hsl _t5207 = ({ L100 *_t5208 = &(eb_1728); (hsl){ (uint8_t*)_t5208->e, _t5208->n }; }); int64_t _l5207 = 0, _h5207 = _t5207.n; if (_l5207 < 0 || _h5207 < _l5207 || _h5207 > _t5207.n) hr_slerr(_l5207, _h5207, _t5207.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:506"); (hsl){ _t5207.p + _l5207 * (int64_t)sizeof(uint8_t), _h5207 - _l5207 }; })));
(void)(f303_hh(hr_str("; ", 2)));
 }
 } } _bk5193:; 
(void)(f303_hh(hr_str("return true; ", 13)));
 }
if ((((k_1635) == (((int64_t)8LL))) || ((k_1635) == (((int64_t)9LL))))) { int64_t e_1729 = ((int64_t)((x_1634).a_)); 
L98 ea_1730 = ({ L98 _t5211; memset(&_t5211, 0, sizeof _t5211); _t5211.n = 0; _t5211; }); 
L98 eb_1731 = ({ L98 _t5212; memset(&_t5212, 0, sizeof _t5212); _t5212.n = 0; _t5212; }); 
if (f284_is_fix(t_1633)) { (void)(({ hrv *_o5214 = &(g169); hr_fs(_o5214, hr_str("for (int64_t i = 0; i < ", 24)); hr_fi(_o5214, (x_1634).b_); hr_fs(_o5214, hr_str("; i++) if (!(", 13)); }));
(void)(({ L98 *_v5215 = &(ea_1730); hsl _s5215 = hr_str("a.e[i]", 6); if (_v5215->n + _s5215.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:512"); memmove(_v5215->e + _v5215->n, _s5215.p, (size_t)_s5215.n * sizeof _v5215->e[0]); _v5215->n += _s5215.n; }));
(void)(({ L98 *_v5216 = &(eb_1731); hsl _s5216 = hr_str("b.e[i]", 6); if (_v5216->n + _s5216.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:512"); memmove(_v5216->e + _v5216->n, _s5216.p, (size_t)_s5216.n * sizeof _v5216->e[0]); _v5216->n += _s5216.n; }));
 } else { if (f285_is_lim(t_1633)) { (void)(f303_hh(hr_str("if (a.n != b.n) return false; for (int64_t i = 0; i < a.n; i++) if (!(", 70)));
(void)(({ L98 *_v5219 = &(ea_1730); hsl _s5219 = hr_str("a.e[i]", 6); if (_v5219->n + _s5219.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:513"); memmove(_v5219->e + _v5219->n, _s5219.p, (size_t)_s5219.n * sizeof _v5219->e[0]); _v5219->n += _s5219.n; }));
(void)(({ L98 *_v5220 = &(eb_1731); hsl _s5220 = hr_str("b.e[i]", 6); if (_v5220->n + _s5220.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:513"); memmove(_v5220->e + _v5220->n, _s5220.p, (size_t)_s5220.n * sizeof _v5220->e[0]); _v5220->n += _s5220.n; }));
 } else { (void)(f303_hh(hr_str("if (a.n != b.n) return false; for (int64_t i = 0; i < a.n; i++) if (!(", 70)));
(void)(({ L98 *_v5222 = &(ea_1730); hsl _s5222 = hr_str("((", 2); if (_v5222->n + _s5222.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:514"); memmove(_v5222->e + _v5222->n, _s5222.p, (size_t)_s5222.n * sizeof _v5222->e[0]); _v5222->n += _s5222.n; }));
(void)(({ L98 *_v5223 = &(ea_1730); hsl _s5223 = f266_cn(e_1729); if (_v5223->n + _s5223.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:514"); memmove(_v5223->e + _v5223->n, _s5223.p, (size_t)_s5223.n * sizeof _v5223->e[0]); _v5223->n += _s5223.n; }));
(void)(({ L98 *_v5225 = &(ea_1730); hsl _s5225 = hr_str("*)a.p)[i]", 9); if (_v5225->n + _s5225.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:514"); memmove(_v5225->e + _v5225->n, _s5225.p, (size_t)_s5225.n * sizeof _v5225->e[0]); _v5225->n += _s5225.n; }));
(void)(({ L98 *_v5226 = &(eb_1731); hsl _s5226 = hr_str("((", 2); if (_v5226->n + _s5226.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:514"); memmove(_v5226->e + _v5226->n, _s5226.p, (size_t)_s5226.n * sizeof _v5226->e[0]); _v5226->n += _s5226.n; }));
(void)(({ L98 *_v5227 = &(eb_1731); hsl _s5227 = f266_cn(e_1729); if (_v5227->n + _s5227.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:514"); memmove(_v5227->e + _v5227->n, _s5227.p, (size_t)_s5227.n * sizeof _v5227->e[0]); _v5227->n += _s5227.n; }));
(void)(({ L98 *_v5229 = &(eb_1731); hsl _s5229 = hr_str("*)b.p)[i]", 9); if (_v5229->n + _s5229.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:514"); memmove(_v5229->e + _v5229->n, _s5229.p, (size_t)_s5229.n * sizeof _v5229->e[0]); _v5229->n += _s5229.n; }));
 }
 }
(void)(f306_heq_val(e_1729, ({ hsl _t5231 = ({ L98 *_t5232 = &(ea_1730); (hsl){ (uint8_t*)_t5232->e, _t5232->n }; }); int64_t _l5231 = 0, _h5231 = _t5231.n; if (_l5231 < 0 || _h5231 < _l5231 || _h5231 > _t5231.n) hr_slerr(_l5231, _h5231, _t5231.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:515"); (hsl){ _t5231.p + _l5231 * (int64_t)sizeof(uint8_t), _h5231 - _l5231 }; }), ({ hsl _t5233 = ({ L98 *_t5234 = &(eb_1731); (hsl){ (uint8_t*)_t5234->e, _t5234->n }; }); int64_t _l5233 = 0, _h5233 = _t5233.n; if (_l5233 < 0 || _h5233 < _l5233 || _h5233 > _t5233.n) hr_slerr(_l5233, _h5233, _t5233.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:515"); (hsl){ _t5233.p + _l5233 * (int64_t)sizeof(uint8_t), _h5233 - _l5233 }; })));
(void)(f303_hh(hr_str(")) return false; return true; ", 30)));
 }
if (((k_1635) == (((int64_t)14LL)))) { (void)(f303_hh(hr_str("return true; ", 13)));
 }
(void)(f303_hh(hr_str("}\012", 2)));
}
static void f298_comp_pre(int64_t t_1637, bool fmt_1638) {
S1 x_1639 = (*({ hrv *_t5238 = &(g554); int64_t _i5238 = t_1637; (S1*)_t5238->b + hr_ix(_i5238, _t5238->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:400"); })); 
int64_t k_1640 = ((int64_t)((x_1639).k_)); 
if (((k_1640) == (((int64_t)5LL)))) { int64_t si_1641 = ((int64_t)((x_1639).a_)); 
{ int32_t _e5240 = ((*({ hrv *_t5241 = &(g557); int64_t _i5241 = si_1641; (S10*)_t5241->b + hr_ix(_i5241, _t5241->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:401"); }))).fnum_; for (int32_t _k5240 = 0; _k5240 < _e5240; _k5240++) { int32_t i_1642 = (int32_t)_k5240; S11 f_1643 = (*({ hrv *_t5242 = &(g558); int64_t _i5242 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5243 = &(g557); int64_t _i5243 = si_1641; (S10*)_t5243->b + hr_ix(_i5243, _t5243->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:401"); }))).f0_)) + (int64_t)((int64_t)(i_1642)))); (S11*)_t5242->b + hr_ix(_i5242, _t5242->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:401"); })); 
if ((((f_1643).ty_) >= (((int32_t)0LL)))) { (void)(f299_comp_one(((int64_t)((f_1643).ty_)), fmt_1638));
 }
 } } _bk5239:; 
 }
if (((k_1640) == (((int64_t)7LL)))) { S9 v_1701 = (*({ hrv *_t5245 = &(g560); int64_t _i5245 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5246 = &(g559); int64_t _i5246 = (x_1639).a_; (S8*)_t5246->b + hr_ix(_i5246, _t5246->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:402"); }))).v0_)) + (int64_t)((int64_t)((x_1639).c_)))); (S9*)_t5245->b + hr_ix(_i5245, _t5245->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:402"); })); 
if ((((v_1701).si_) >= (((int32_t)0LL)))) { { int32_t _e5248 = ((*({ hrv *_t5249 = &(g557); int64_t _i5249 = (v_1701).si_; (S10*)_t5249->b + hr_ix(_i5249, _t5249->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:402"); }))).fnum_; for (int32_t _k5248 = 0; _k5248 < _e5248; _k5248++) { int32_t i_1702 = (int32_t)_k5248; S11 f_1703 = (*({ hrv *_t5250 = &(g558); int64_t _i5250 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5251 = &(g557); int64_t _i5251 = (v_1701).si_; (S10*)_t5251->b + hr_ix(_i5251, _t5251->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:402"); }))).f0_)) + (int64_t)((int64_t)(i_1702)))); (S11*)_t5250->b + hr_ix(_i5250, _t5250->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:402"); })); 
if ((((f_1703).ty_) >= (((int32_t)0LL)))) { (void)(f299_comp_one(((int64_t)((f_1703).ty_)), fmt_1638));
 }
 } } _bk5247:; 
 }
 }
if (((k_1640) == (((int64_t)6LL)))) { int64_t ei_1704 = ((int64_t)((x_1639).a_)); 
{ int32_t _e5254 = ((*({ hrv *_t5255 = &(g559); int64_t _i5255 = ei_1704; (S8*)_t5255->b + hr_ix(_i5255, _t5255->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).vnum_; for (int32_t _k5254 = 0; _k5254 < _e5254; _k5254++) { int32_t i_1705 = (int32_t)_k5254; S9 v_1706 = (*({ hrv *_t5256 = &(g560); int64_t _i5256 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5257 = &(g559); int64_t _i5257 = ei_1704; (S8*)_t5257->b + hr_ix(_i5257, _t5257->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).v0_)) + (int64_t)((int64_t)(i_1705)))); (S9*)_t5256->b + hr_ix(_i5256, _t5256->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); })); 
if (((((v_1706).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t5258 = &(g557); int64_t _i5258 = (v_1706).si_; (S10*)_t5258->b + hr_ix(_i5258, _t5258->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).zero_)))) { if (fmt_1638) { { int32_t _e5260 = ((*({ hrv *_t5261 = &(g557); int64_t _i5261 = (v_1706).si_; (S10*)_t5261->b + hr_ix(_i5261, _t5261->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).fnum_; for (int32_t _k5260 = 0; _k5260 < _e5260; _k5260++) { int32_t j_1707 = (int32_t)_k5260; S11 f_1708 = (*({ hrv *_t5262 = &(g558); int64_t _i5262 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5263 = &(g557); int64_t _i5263 = (v_1706).si_; (S10*)_t5263->b + hr_ix(_i5263, _t5263->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).f0_)) + (int64_t)((int64_t)(j_1707)))); (S11*)_t5262->b + hr_ix(_i5262, _t5262->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); })); 
if ((((f_1708).ty_) >= (((int32_t)0LL)))) { (void)(f299_comp_one(((int64_t)((f_1708).ty_)), fmt_1638));
 }
 } } _bk5259:; 
 } else { (void)(f297_gen_heq(f125_t_variant(ei_1704, ((int64_t)(i_1705)))));
 }
 }
 } } _bk5253:; 
 }
if ((((k_1640) == (((int64_t)8LL))) || ((k_1640) == (((int64_t)9LL))))) { (void)(f299_comp_one(((int64_t)((x_1639).a_)), fmt_1638));
 }
if (((k_1640) == (((int64_t)14LL)))) { { int32_t _e5269 = (x_1639).n_; for (int32_t _k5269 = 0; _k5269 < _e5269; _k5269++) { int32_t i_1709 = (int32_t)_k5269; (void)(f299_comp_one(((int64_t)((*({ hrv *_t5271 = &(g555); int64_t _i5271 = ((int64_t)((int64_t)((int64_t)((x_1639).l_)) + (int64_t)((int64_t)(i_1709)))); (int32_t*)_t5271->b + hr_ix(_i5271, _t5271->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:405"); })))), fmt_1638));
 } } _bk5268:; 
 }
}
static void f299_comp_one(int64_t t_1644, bool fmt_1645) {
int64_t u_1646 = ({ int64_t _r5272; if (((((*({ hrv *_t5273 = &(g554); int64_t _i5273 = t_1644; (S1*)_t5273->b + hr_ix(_i5273, _t5273->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:398"); }))).k_) == (((uint8_t)10LL)))) { _r5272 = ((int64_t)(((*({ hrv *_t5274 = &(g554); int64_t _i5274 = t_1644; (S1*)_t5274->b + hr_ix(_i5274, _t5274->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:398"); }))).a_));  } else { _r5272 = t_1644;  } _r5272; }); 
if ((((((*({ hrv *_t5275 = &(g554); int64_t _i5275 = t_1644; (S1*)_t5275->b + hr_ix(_i5275, _t5275->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:398"); }))).k_) == (((uint8_t)10LL))) && (!(fmt_1645)))) { return;
 }
if (f300_need_helper(u_1646)) { if (fmt_1645) { (void)(f301_gen_hf(u_1646));
 } else { (void)(f297_gen_heq(u_1646));
 }
 }
}
static bool f300_need_helper(int64_t t_1647) {
int64_t k_1648 = ((int64_t)(((*({ hrv *_t5279 = &(g554); int64_t _i5279 = t_1647; (S1*)_t5279->b + hr_ix(_i5279, _t5279->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:397"); }))).k_)); 
if (f167_is_byte_arr(t_1647)) { return false;
 }
if (((k_1648) == (((int64_t)10LL)))) { return f300_need_helper(((int64_t)(((*({ hrv *_t5282 = &(g554); int64_t _i5282 = t_1647; (S1*)_t5282->b + hr_ix(_i5282, _t5282->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:397"); }))).a_)));
 }
return (((((((k_1648) == (((int64_t)5LL))) || ((k_1648) == (((int64_t)6LL)))) || ((k_1648) == (((int64_t)7LL)))) || ((k_1648) == (((int64_t)8LL)))) || ((k_1648) == (((int64_t)9LL)))) || ((k_1648) == (((int64_t)14LL))));
}
static void f301_gen_hf(int64_t t_1649) {
(void)(f265_cn_grow());
if ((((*({ hrv *_t5284 = &(g174); int64_t _i5284 = t_1649; (uint8_t*)_t5284->b + hr_ix(_i5284, _t5284->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:420"); }))) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t5285 = &((*({ hrv *_t5286 = &(g174); int64_t _i5286 = t_1649; (uint8_t*)_t5286->b + hr_ix(_i5286, _t5286->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:421"); }))); *_t5285 = ((uint8_t)1LL); }
S1 x_1650 = (*({ hrv *_t5287 = &(g554); int64_t _i5287 = t_1649; (S1*)_t5287->b + hr_ix(_i5287, _t5287->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:422"); })); 
int64_t k_1651 = ((int64_t)((x_1650).k_)); 
(void)(f264_cbody(t_1649));
bool sl_1652 = (((k_1651) == (((int64_t)9LL))) || ((((k_1651) == (((int64_t)8LL))) && (!(f284_is_fix(t_1649)))) && (!(f285_is_lim(t_1649))))); 
(void)(f302_hf_pre(t_1649));
L97 sig_1654 = ({ L97 _t5292; memset(&_t5292, 0, sizeof _t5292); _t5292.n = 0; _t5292; }); 
(void)(({ L97 *_l5293 = &(sig_1654); hrv _o5293 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5293, hr_str("static void hf", 14)); hr_fi(&_o5293, t_1649); hr_fs(&_o5293, hr_str("(hrv *o, ", 9)); if (_l5293->n + _o5293.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:427"); memcpy(_l5293->e + _l5293->n, _o5293.b, (size_t)_o5293.n); _l5293->n += _o5293.n; }));
(void)(({ L97 *_v5294 = &(sig_1654); hsl _s5294 = ({ hsl _r5295; if (sl_1652) { _r5295 = hr_str("hsl", 3);  } else { _r5295 = f266_cn(t_1649);  } _r5295; }); if (_v5294->n + _s5294.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:428"); memmove(_v5294->e + _v5294->n, _s5294.p, (size_t)_s5294.n * sizeof _v5294->e[0]); _v5294->n += _s5294.n; }));
(void)(({ L97 *_v5297 = &(sig_1654); hsl _s5297 = hr_str(" v)", 3); if (_v5297->n + _s5297.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:429"); memmove(_v5297->e + _v5297->n, _s5297.p, (size_t)_s5297.n * sizeof _v5297->e[0]); _v5297->n += _s5297.n; }));
(void)(({ hrv *_v5298 = &(g166); hsl _s5298 = ({ hsl _t5299 = ({ L97 *_t5300 = &(sig_1654); (hsl){ (uint8_t*)_t5300->e, _t5300->n }; }); int64_t _l5299 = 0, _h5299 = _t5299.n; if (_l5299 < 0 || _h5299 < _l5299 || _h5299 > _t5299.n) hr_slerr(_l5299, _h5299, _t5299.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:430"); (hsl){ _t5299.p + _l5299 * (int64_t)sizeof(uint8_t), _h5299 - _l5299 }; }); hr_append(_v5298, _s5298.p, _s5298.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5301 = &(g166); hsl _s5301 = hr_str(";\012", 2); hr_append(_v5301, _s5301.p, _s5301.n, sizeof(uint8_t)); }));
int64_t s0_1655 = (g169).n; 
(void)(({ hrv *_v5302 = &(g169); hsl _s5302 = ({ hsl _t5303 = ({ L97 *_t5304 = &(sig_1654); (hsl){ (uint8_t*)_t5304->e, _t5304->n }; }); int64_t _l5303 = 0, _h5303 = _t5303.n; if (_l5303 < 0 || _h5303 < _l5303 || _h5303 > _t5303.n) hr_slerr(_l5303, _h5303, _t5303.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:432"); (hsl){ _t5303.p + _l5303 * (int64_t)sizeof(uint8_t), _h5303 - _l5303 }; }); hr_append(_v5302, _s5302.p, _s5302.n, sizeof(uint8_t)); }));
(void)(f303_hh(hr_str(" { ", 3)));
int64_t hk_1657 = ({ int64_t _r5306; if (((t_1649) < ((g350).n))) { _r5306 = ((int64_t)((*({ hrv *_t5307 = &(g350); int64_t _i5307 = t_1649; (int32_t*)_t5307->b + hr_ix(_i5307, _t5307->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:433"); }))));  } else { _r5306 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r5306; }); 
if (((hk_1657) >= (((int64_t)0LL)))) { int64_t pt_1658 = f212_ptype_of(hk_1657, ((int64_t)1LL)); 
bool byr_1659 = ((((*({ hrv *_t5309 = &(g554); int64_t _i5309 = pt_1658; (S1*)_t5309->b + hr_ix(_i5309, _t5309->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:436"); }))).k_) == (((uint8_t)10LL))); 
int64_t dp_1660 = f182_deref(pt_1658); 
if (((((dp_1660) != (t_1649)) && ((((*({ hrv *_t5311 = &(g554); int64_t _i5311 = dp_1660; (S1*)_t5311->b + hr_ix(_i5311, _t5311->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:438"); }))).k_) == (((uint8_t)6LL)))) && ((k_1651) == (((int64_t)7LL))))) { int64_t vi_1661 = ((int64_t)((x_1650).c_)); 
S9 vv_1662 = (*({ hrv *_t5312 = &(g560); int64_t _i5312 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5313 = &(g559); int64_t _i5313 = (x_1650).a_; (S8*)_t5313->b + hr_ix(_i5313, _t5313->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:438"); }))).v0_)) + (int64_t)vi_1661)); (S9*)_t5312->b + hr_ix(_i5312, _t5312->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:438"); })); 
(void)(({ hrv *_v5314 = &(g169); hsl _s5314 = f266_cn(dp_1660); hr_append(_v5314, _s5314.p, _s5314.n, sizeof(uint8_t)); }));
(void)(f303_hh(hr_str(" e; memset(&e, 0, sizeof e); ", 29)));
(void)(({ hrv *_o5317 = &(g169); hr_fs(_o5317, hr_str("e.tag = ", 8)); hr_fi(_o5317, vi_1661); hr_fs(_o5317, hr_str("; ", 2)); }));
if (((((vv_1662).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t5318 = &(g557); int64_t _i5318 = (vv_1662).si_; (S10*)_t5318->b + hr_ix(_i5318, _t5318->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:438"); }))).zero_)))) { (void)(({ hrv *_o5319 = &(g169); hr_fs(_o5319, hr_str("e.u.v", 5)); hr_fi(_o5319, vi_1661); hr_fs(_o5319, hr_str(" = v; ", 6)); }));
 }
(void)(f304_fn_cname_to((&(g169)), hk_1657));
(void)(f303_hh(({ hsl _r5322; if (byr_1659) { _r5322 = hr_str("(o, &e); }\012", 11);  } else { _r5322 = hr_str("(o, e); }\012", 10);  } _r5322; })));
return;
 }
(void)(f304_fn_cname_to((&(g169)), hk_1657));
(void)(f303_hh(({ hsl _r5325; if (byr_1659) { _r5325 = hr_str("(o, &v); }\012", 11);  } else { _r5325 = hr_str("(o, v); }\012", 10);  } _r5325; })));
return;
 }
if (((k_1651) == (((int64_t)5LL)))) { int64_t si_1667 = ((int64_t)((x_1650).a_)); 
int64_t f0_1668 = ((int64_t)(((*({ hrv *_t5326 = &(g557); int64_t _i5326 = si_1667; (S10*)_t5326->b + hr_ix(_i5326, _t5326->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:443"); }))).f0_)); 
(void)(f303_hh(hr_str("hr_fc(o, \"", 10)));
hrv tnm_1669 __attribute__((cleanup(hr_rdrop))) = f126_ty_name(t_1649); 
(void)(({ hrv *_v5329 = &(g169); hsl _s5329 = ({ hsl _t5330 = hr_sl(tnm_1669); int64_t _l5330 = 0, _h5330 = _t5330.n; if (_l5330 < 0 || _h5330 < _l5330 || _h5330 > _t5330.n) hr_slerr(_l5330, _h5330, _t5330.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:444"); (hsl){ _t5330.p + _l5330 * (int64_t)sizeof(uint8_t), _h5330 - _l5330 }; }); hr_append(_v5329, _s5329.p, _s5329.n, sizeof(uint8_t)); }));
(void)(f303_hh(hr_str(" { \"); ", 7)));
bool first_1670 = true; 
{ int32_t _e5333 = ((*({ hrv *_t5334 = &(g557); int64_t _i5334 = si_1667; (S10*)_t5334->b + hr_ix(_i5334, _t5334->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:446"); }))).fnum_; for (int32_t _k5333 = 0; _k5333 < _e5333; _k5333++) { int32_t i_1671 = (int32_t)_k5333; S11 f_1672 = (*({ hrv *_t5335 = &(g558); int64_t _i5335 = ((int64_t)((int64_t)f0_1668 + (int64_t)((int64_t)(i_1671)))); (S11*)_t5335->b + hr_ix(_i5335, _t5335->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:446"); })); 
if ((((f_1672).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1670))) { (void)(f303_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1670 = false;
L98 e_1673 = ({ L98 _t5337; memset(&_t5337, 0, sizeof _t5337); _t5337.n = 0; _t5337; }); 
(void)(({ L98 *_v5338 = &(e_1673); hsl _s5338 = hr_str("v.", 2); if (_v5338->n + _s5338.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:446"); memmove(_v5338->e + _v5338->n, _s5338.p, (size_t)_s5338.n * sizeof _v5338->e[0]); _v5338->n += _s5338.n; }));
{ hsl _v5340 = f10_nm(((int64_t)((f_1672).name_))); for (int64_t _k5340 = 0; _k5340 < _v5340.n; _k5340++) { uint8_t c_1674 = ((uint8_t*)_v5340.p)[_k5340]; (void)(({ L98 *_v5342 = &(e_1673); uint8_t _x5342 = c_1674; if (_v5342->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:446"); _v5342->e[_v5342->n] = _x5342; &_v5342->e[_v5342->n++]; }));
 } } _bk5339:; 
(void)(({ L98 *_v5343 = &(e_1673); uint8_t _x5343 = ((uint8_t)95LL); if (_v5343->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:446"); _v5343->e[_v5343->n] = _x5343; &_v5343->e[_v5343->n++]; }));
(void)(f305_hf_val(((int64_t)((f_1672).ty_)), ({ hsl _t5345 = ({ L98 *_t5346 = &(e_1673); (hsl){ (uint8_t*)_t5346->e, _t5346->n }; }); int64_t _l5345 = 0, _h5345 = _t5345.n; if (_l5345 < 0 || _h5345 < _l5345 || _h5345 > _t5345.n) hr_slerr(_l5345, _h5345, _t5345.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:446"); (hsl){ _t5345.p + _l5345 * (int64_t)sizeof(uint8_t), _h5345 - _l5345 }; })));
 } } _bk5332:; 
(void)(f303_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 }
if (((k_1651) == (((int64_t)6LL)))) { int64_t ei_1679 = ((int64_t)((x_1650).a_)); 
int64_t v0_1680 = ((int64_t)(((*({ hrv *_t5348 = &(g559); int64_t _i5348 = ei_1679; (S8*)_t5348->b + hr_ix(_i5348, _t5348->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:450"); }))).v0_)); 
{ int32_t _e5350 = ((*({ hrv *_t5351 = &(g559); int64_t _i5351 = ei_1679; (S8*)_t5351->b + hr_ix(_i5351, _t5351->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:451"); }))).vnum_; for (int32_t _k5350 = 0; _k5350 < _e5350; _k5350++) { int32_t i_1681 = (int32_t)_k5350; S9 v_1682 = (*({ hrv *_t5352 = &(g560); int64_t _i5352 = ((int64_t)((int64_t)v0_1680 + (int64_t)((int64_t)(i_1681)))); (S9*)_t5352->b + hr_ix(_i5352, _t5352->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:452"); })); 
(void)(({ hrv *_o5353 = &(g169); hr_fs(_o5353, hr_str("if (v.tag == ", 13)); hr_fi(_o5353, i_1681); hr_fs(_o5353, hr_str(") { ", 4)); }));
if (((((v_1682).si_) >= (((int32_t)0LL))) && ((((*({ hrv *_t5354 = &(g557); int64_t _i5354 = (v_1682).si_; (S10*)_t5354->b + hr_ix(_i5354, _t5354->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); }))).fnum_) > (((int32_t)0LL))))) { (void)(f303_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f303_hh(f10_nm(((int64_t)((v_1682).name_)))));
(void)(f303_hh(hr_str(" { \"); ", 7)));
bool first_1683 = true; 
int64_t sf0_1684 = ((int64_t)(((*({ hrv *_t5359 = &(g557); int64_t _i5359 = (v_1682).si_; (S10*)_t5359->b + hr_ix(_i5359, _t5359->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); }))).f0_)); 
{ int32_t _e5361 = ((*({ hrv *_t5362 = &(g557); int64_t _i5362 = (v_1682).si_; (S10*)_t5362->b + hr_ix(_i5362, _t5362->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); }))).fnum_; for (int32_t _k5361 = 0; _k5361 < _e5361; _k5361++) { int32_t j_1685 = (int32_t)_k5361; S11 f_1686 = (*({ hrv *_t5363 = &(g558); int64_t _i5363 = ((int64_t)((int64_t)sf0_1684 + (int64_t)((int64_t)(j_1685)))); (S11*)_t5363->b + hr_ix(_i5363, _t5363->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); })); 
if ((((f_1686).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1683))) { (void)(f303_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1683 = false;
L98 e_1687 = ({ L98 _t5365; memset(&_t5365, 0, sizeof _t5365); _t5365.n = 0; _t5365; }); 
(void)(({ L98 *_l5366 = &(e_1687); hrv _o5366 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5366, hr_str("v.u.v", 5)); hr_fi(&_o5366, i_1681); hr_fs(&_o5366, hr_str(".", 1)); if (_l5366->n + _o5366.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); memcpy(_l5366->e + _l5366->n, _o5366.b, (size_t)_o5366.n); _l5366->n += _o5366.n; }));
{ hsl _v5368 = f10_nm(((int64_t)((f_1686).name_))); for (int64_t _k5368 = 0; _k5368 < _v5368.n; _k5368++) { uint8_t c_1688 = ((uint8_t*)_v5368.p)[_k5368]; (void)(({ L98 *_v5370 = &(e_1687); uint8_t _x5370 = c_1688; if (_v5370->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); _v5370->e[_v5370->n] = _x5370; &_v5370->e[_v5370->n++]; }));
 } } _bk5367:; 
(void)(({ L98 *_v5371 = &(e_1687); uint8_t _x5371 = ((uint8_t)95LL); if (_v5371->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); _v5371->e[_v5371->n] = _x5371; &_v5371->e[_v5371->n++]; }));
(void)(f305_hf_val(((int64_t)((f_1686).ty_)), ({ hsl _t5373 = ({ L98 *_t5374 = &(e_1687); (hsl){ (uint8_t*)_t5374->e, _t5374->n }; }); int64_t _l5373 = 0, _h5373 = _t5373.n; if (_l5373 < 0 || _h5373 < _l5373 || _h5373 > _t5373.n) hr_slerr(_l5373, _h5373, _t5373.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:454"); (hsl){ _t5373.p + _l5373 * (int64_t)sizeof(uint8_t), _h5373 - _l5373 }; })));
 } } _bk5360:; 
(void)(f303_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 } else { (void)(f303_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f303_hh(f10_nm(((int64_t)(((*({ hrv *_t5379 = &(g559); int64_t _i5379 = ei_1679; (S8*)_t5379->b + hr_ix(_i5379, _t5379->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:455"); }))).name_)))));
(void)(f303_hh(hr_str(".", 1)));
(void)(f303_hh(f10_nm(((int64_t)((v_1682).name_)))));
(void)(f303_hh(hr_str("\"); ", 4)));
 }
(void)(f303_hh(hr_str("} ", 2)));
 } } _bk5349:; 
 }
if (((k_1651) == (((int64_t)7LL)))) { int64_t ei_1689 = ((int64_t)((x_1650).a_)); 
S9 v_1690 = (*({ hrv *_t5385 = &(g560); int64_t _i5385 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5386 = &(g559); int64_t _i5386 = ei_1689; (S8*)_t5386->b + hr_ix(_i5386, _t5386->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:460"); }))).v0_)) + (int64_t)((int64_t)((x_1650).c_)))); (S9*)_t5385->b + hr_ix(_i5385, _t5385->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:460"); })); 
if (((((v_1690).si_) >= (((int32_t)0LL))) && ((((*({ hrv *_t5387 = &(g557); int64_t _i5387 = (v_1690).si_; (S10*)_t5387->b + hr_ix(_i5387, _t5387->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); }))).fnum_) > (((int32_t)0LL))))) { (void)(f303_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f303_hh(f10_nm(((int64_t)((v_1690).name_)))));
(void)(f303_hh(hr_str(" { \"); ", 7)));
bool first_1691 = true; 
int64_t sf0_1692 = ((int64_t)(((*({ hrv *_t5392 = &(g557); int64_t _i5392 = (v_1690).si_; (S10*)_t5392->b + hr_ix(_i5392, _t5392->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); }))).f0_)); 
{ int32_t _e5394 = ((*({ hrv *_t5395 = &(g557); int64_t _i5395 = (v_1690).si_; (S10*)_t5395->b + hr_ix(_i5395, _t5395->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); }))).fnum_; for (int32_t _k5394 = 0; _k5394 < _e5394; _k5394++) { int32_t j_1693 = (int32_t)_k5394; S11 f_1694 = (*({ hrv *_t5396 = &(g558); int64_t _i5396 = ((int64_t)((int64_t)sf0_1692 + (int64_t)((int64_t)(j_1693)))); (S11*)_t5396->b + hr_ix(_i5396, _t5396->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); })); 
if ((((f_1694).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1691))) { (void)(f303_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1691 = false;
L98 e_1695 = ({ L98 _t5398; memset(&_t5398, 0, sizeof _t5398); _t5398.n = 0; _t5398; }); 
(void)(({ L98 *_v5399 = &(e_1695); hsl _s5399 = hr_str("v.", 2); if (_v5399->n + _s5399.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); memmove(_v5399->e + _v5399->n, _s5399.p, (size_t)_s5399.n * sizeof _v5399->e[0]); _v5399->n += _s5399.n; }));
{ hsl _v5401 = f10_nm(((int64_t)((f_1694).name_))); for (int64_t _k5401 = 0; _k5401 < _v5401.n; _k5401++) { uint8_t c_1696 = ((uint8_t*)_v5401.p)[_k5401]; (void)(({ L98 *_v5403 = &(e_1695); uint8_t _x5403 = c_1696; if (_v5403->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); _v5403->e[_v5403->n] = _x5403; &_v5403->e[_v5403->n++]; }));
 } } _bk5400:; 
(void)(({ L98 *_v5404 = &(e_1695); uint8_t _x5404 = ((uint8_t)95LL); if (_v5404->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); _v5404->e[_v5404->n] = _x5404; &_v5404->e[_v5404->n++]; }));
(void)(f305_hf_val(((int64_t)((f_1694).ty_)), ({ hsl _t5406 = ({ L98 *_t5407 = &(e_1695); (hsl){ (uint8_t*)_t5407->e, _t5407->n }; }); int64_t _l5406 = 0, _h5406 = _t5406.n; if (_l5406 < 0 || _h5406 < _l5406 || _h5406 > _t5406.n) hr_slerr(_l5406, _h5406, _t5406.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); (hsl){ _t5406.p + _l5406 * (int64_t)sizeof(uint8_t), _h5406 - _l5406 }; })));
 } } _bk5393:; 
(void)(f303_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 } else { (void)(f303_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f303_hh(f10_nm(((int64_t)(((*({ hrv *_t5412 = &(g559); int64_t _i5412 = ei_1689; (S8*)_t5412->b + hr_ix(_i5412, _t5412->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:462"); }))).name_)))));
(void)(f303_hh(hr_str(".", 1)));
(void)(f303_hh(f10_nm(((int64_t)((v_1690).name_)))));
(void)(f303_hh(hr_str("\"); ", 4)));
 }
 }
if ((((k_1651) == (((int64_t)8LL))) || ((k_1651) == (((int64_t)9LL))))) { int64_t e_1697 = ((int64_t)((x_1650).a_)); 
(void)(f264_cbody(e_1697));
(void)(f303_hh(hr_str("hr_fb(o, '['); ", 15)));
if (f284_is_fix(t_1649)) { (void)(({ hrv *_o5420 = &(g169); hr_fs(_o5420, hr_str("for (int64_t i = 0; i < ", 24)); hr_fi(_o5420, (x_1650).b_); hr_fs(_o5420, hr_str("; i++) { if (i) hr_fc(o, \", \"); ", 32)); }));
(void)(f305_hf_val(e_1697, hr_str("v.e[i]", 6)));
(void)(f303_hh(hr_str("} ", 2)));
 } else { if (f285_is_lim(t_1649)) { (void)(f303_hh(hr_str("for (int64_t i = 0; i < v.n; i++) { if (i) hr_fc(o, \", \"); ", 59)));
(void)(f305_hf_val(e_1697, hr_str("v.e[i]", 6)));
(void)(f303_hh(hr_str("} ", 2)));
 } else { (void)(f303_hh(hr_str("for (int64_t i = 0; i < v.n; i++) { if (i) hr_fc(o, \", \"); ", 59)));
L98 ex_1698 = ({ L98 _t5428; memset(&_t5428, 0, sizeof _t5428); _t5428.n = 0; _t5428; }); 
(void)(({ L98 *_v5429 = &(ex_1698); hsl _s5429 = hr_str("((", 2); if (_v5429->n + _s5429.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:470"); memmove(_v5429->e + _v5429->n, _s5429.p, (size_t)_s5429.n * sizeof _v5429->e[0]); _v5429->n += _s5429.n; }));
(void)(({ L98 *_v5430 = &(ex_1698); hsl _s5430 = f266_cn(e_1697); if (_v5430->n + _s5430.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:470"); memmove(_v5430->e + _v5430->n, _s5430.p, (size_t)_s5430.n * sizeof _v5430->e[0]); _v5430->n += _s5430.n; }));
(void)(({ L98 *_v5432 = &(ex_1698); hsl _s5432 = hr_str("*)v.p)[i]", 9); if (_v5432->n + _s5432.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:470"); memmove(_v5432->e + _v5432->n, _s5432.p, (size_t)_s5432.n * sizeof _v5432->e[0]); _v5432->n += _s5432.n; }));
(void)(f305_hf_val(e_1697, ({ hsl _t5434 = ({ L98 *_t5435 = &(ex_1698); (hsl){ (uint8_t*)_t5435->e, _t5435->n }; }); int64_t _l5434 = 0, _h5434 = _t5434.n; if (_l5434 < 0 || _h5434 < _l5434 || _h5434 > _t5434.n) hr_slerr(_l5434, _h5434, _t5434.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:470"); (hsl){ _t5434.p + _l5434 * (int64_t)sizeof(uint8_t), _h5434 - _l5434 }; })));
(void)(f303_hh(hr_str("} ", 2)));
 }
 }
(void)(f303_hh(hr_str("hr_fb(o, ']'); ", 15)));
 }
if (((k_1651) == (((int64_t)14LL)))) { { int32_t _e5439 = (x_1650).n_; for (int32_t _k5439 = 0; _k5439 < _e5439; _k5439++) { int32_t i_1699 = (int32_t)_k5439; if (((i_1699) > (((int32_t)0LL)))) { (void)(f303_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
L99 e_1700 = ({ L99 _t5441; memset(&_t5441, 0, sizeof _t5441); _t5441.n = 0; _t5441; }); 
(void)(({ L99 *_l5442 = &(e_1700); hrv _o5442 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5442, hr_str("v.r", 3)); hr_fi(&_o5442, i_1699); if (_l5442->n + _o5442.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:473"); memcpy(_l5442->e + _l5442->n, _o5442.b, (size_t)_o5442.n); _l5442->n += _o5442.n; }));
(void)(f305_hf_val(((int64_t)((*({ hrv *_t5444 = &(g555); int64_t _i5444 = ((int64_t)((int64_t)((int64_t)((x_1650).l_)) + (int64_t)((int64_t)(i_1699)))); (int32_t*)_t5444->b + hr_ix(_i5444, _t5444->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:473"); })))), ({ hsl _t5445 = ({ L99 *_t5446 = &(e_1700); (hsl){ (uint8_t*)_t5446->e, _t5446->n }; }); int64_t _l5445 = 0, _h5445 = _t5445.n; if (_l5445 < 0 || _h5445 < _l5445 || _h5445 > _t5445.n) hr_slerr(_l5445, _h5445, _t5445.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:473"); (hsl){ _t5445.p + _l5445 * (int64_t)sizeof(uint8_t), _h5445 - _l5445 }; })));
 } } _bk5438:; 
 }
(void)(f303_hh(hr_str("}\012", 2)));
}
static void f302_hf_pre(int64_t t_1653) {
(void)(f298_comp_pre(t_1653, true));
}
static void f303_hh(hsl s_1656) {
(void)(({ hrv *_v5449 = &(g169); hsl _s5449 = s_1656; hr_append(_v5449, _s5449.p, _s5449.n, sizeof(uint8_t)); }));
}
static void f304_fn_cname_to(hrv* b_1663, int64_t i_1664) {
(void)(({ hrv *_o5450 = b_1663; hr_fs(_o5450, hr_str("f", 1)); hr_fi(_o5450, i_1664); hr_fs(_o5450, hr_str("_", 1)); }));
int64_t s_1665 = ((int64_t)(((*({ hrv *_t5451 = &(g390); int64_t _i5451 = i_1664; (S6*)_t5451->b + hr_ix(_i5451, _t5451->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:573"); }))).name_)); 
if (((s_1665) >= (((int64_t)0LL)))) { { hsl _v5453 = f10_nm(s_1665); for (int64_t _k5453 = 0; _k5453 < _v5453.n; _k5453++) { uint8_t c_1666 = ((uint8_t*)_v5453.p)[_k5453]; (void)(({ hrv *_v5455 = b_1663; uint8_t _x5455 = ({ uint8_t _r5456; if (((c_1666) == (((uint8_t)58LL)))) { _r5456 = ((uint8_t)95LL);  } else { _r5456 = c_1666;  } _r5456; }); uint8_t *_p5455 = (uint8_t*)hr_grow(_v5455, 1, sizeof _x5455); *_p5455 = _x5455; _p5455; }));
 } } _bk5452:; 
 }
}
static void f305_hf_val(int64_t t_1675, hsl e_1676) {
int64_t k_1677 = ((int64_t)(((*({ hrv *_t5457 = &(g554); int64_t _i5457 = t_1675; (S1*)_t5457->b + hr_ix(_i5457, _t5457->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:409"); }))).k_)); 
if (f167_is_byte_arr(t_1675)) { if (f284_is_fix(t_1675)) { (void)(({ hrv *_o5460 = &(g169); hr_fs(_o5460, hr_str("hr_fq(o, (hsl){ (uint8_t*)(", 27)); hr_fs(_o5460, e_1676); hr_fs(_o5460, hr_str(").e, ", 5)); hr_fi(_o5460, ((*({ hrv *_t5461 = &(g554); int64_t _i5461 = t_1675; (S1*)_t5461->b + hr_ix(_i5461, _t5461->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:410"); }))).b_); hr_fs(_o5460, hr_str(" }); ", 5)); }));
return;
 }
if (f285_is_lim(t_1675)) { (void)(({ hrv *_o5463 = &(g169); hr_fs(_o5463, hr_str("hr_fq(o, (hsl){ (uint8_t*)(", 27)); hr_fs(_o5463, e_1676); hr_fs(_o5463, hr_str(").e, (", 6)); hr_fs(_o5463, e_1676); hr_fs(_o5463, hr_str(").n }); ", 8)); }));
return;
 }
if (((((*({ hrv *_t5464 = &(g554); int64_t _i5464 = t_1675; (S1*)_t5464->b + hr_ix(_i5464, _t5464->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:410"); }))).k_) == (((uint8_t)9LL)))) { (void)(({ hrv *_o5465 = &(g169); hr_fs(_o5465, hr_str("hr_fq(o, ", 9)); hr_fs(_o5465, e_1676); hr_fs(_o5465, hr_str("); ", 3)); }));
return;
 }
(void)(({ hrv *_o5466 = &(g169); hr_fs(_o5466, hr_str("hr_fq(o, hr_sl(", 15)); hr_fs(_o5466, e_1676); hr_fs(_o5466, hr_str(")); ", 4)); }));
return;
 }
if (((k_1677) == (((int64_t)3LL)))) { (void)(({ hrv *_o5467 = &(g169); hr_fs(_o5467, ({ hsl _r5468; if (f156_is_signed(t_1675)) { _r5468 = hr_str("hr_fi(o, ", 9);  } else { _r5468 = hr_str("hr_fu(o, ", 9);  } _r5468; })); hr_fs(_o5467, e_1676); hr_fs(_o5467, hr_str("); ", 3)); }));
return;
 }
if (((k_1677) == (((int64_t)4LL)))) { (void)(({ hrv *_o5470 = &(g169); hr_fs(_o5470, ({ hsl _r5471; if (((((*({ hrv *_t5472 = &(g554); int64_t _i5472 = t_1675; (S1*)_t5472->b + hr_ix(_i5472, _t5472->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:412"); }))).s_) == (((uint8_t)4LL)))) { _r5471 = hr_str("hr_ff(o, ", 9);  } else { _r5471 = hr_str("hr_fd(o, ", 9);  } _r5471; })); hr_fs(_o5470, e_1676); hr_fs(_o5470, hr_str("); ", 3)); }));
return;
 }
if (((k_1677) == (((int64_t)2LL)))) { (void)(({ hrv *_o5473 = &(g169); hr_fs(_o5473, hr_str("hr_fc(o, (", 10)); hr_fs(_o5473, e_1676); hr_fs(_o5473, hr_str(") \077 \"true\" : \"false\"); ", 23)); }));
return;
 }
if (((k_1677) == (((int64_t)10LL)))) { if (((((*({ hrv *_t5474 = &(g554); int64_t _i5474 = t_1675; (S1*)_t5474->b + hr_ix(_i5474, _t5474->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:414"); }))).c_) >= (((int32_t)0LL)))) { (void)(({ hrv *_o5475 = &(g169); hr_fs(_o5475, hr_str("hr_fu(o, ", 9)); hr_fs(_o5475, e_1676); hr_fs(_o5475, hr_str("); ", 3)); }));
return;
 }
L97 pe_1678 = ({ L97 _t5476; memset(&_t5476, 0, sizeof _t5476); _t5476.n = 0; _t5476; }); 
(void)(({ L97 *_l5477 = &(pe_1678); hrv _o5477 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5477, hr_str("(*(", 3)); hr_fs(&_o5477, e_1676); hr_fs(&_o5477, hr_str("))", 2)); if (_l5477->n + _o5477.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:414"); memcpy(_l5477->e + _l5477->n, _o5477.b, (size_t)_o5477.n); _l5477->n += _o5477.n; }));
(void)(({ hrv *_o5478 = &(g169); hr_fs(_o5478, hr_str("if (", 4)); hr_fs(_o5478, e_1676); hr_fs(_o5478, hr_str(") { ", 4)); }));
(void)(f305_hf_val(((int64_t)(((*({ hrv *_t5480 = &(g554); int64_t _i5480 = t_1675; (S1*)_t5480->b + hr_ix(_i5480, _t5480->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:414"); }))).a_)), ({ hsl _t5481 = ({ L97 *_t5482 = &(pe_1678); (hsl){ (uint8_t*)_t5482->e, _t5482->n }; }); int64_t _l5481 = 0, _h5481 = _t5481.n; if (_l5481 < 0 || _h5481 < _l5481 || _h5481 > _t5481.n) hr_slerr(_l5481, _h5481, _t5481.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:414"); (hsl){ _t5481.p + _l5481 * (int64_t)sizeof(uint8_t), _h5481 - _l5481 }; })));
(void)(f303_hh(hr_str("} else hr_fc(o, \"null\"); ", 25)));
return;
 }
if (((((k_1677) == (((int64_t)8LL))) && (!(f284_is_fix(t_1675)))) && (!(f285_is_lim(t_1675))))) { (void)(({ hrv *_o5486 = &(g169); hr_fs(_o5486, hr_str("hf", 2)); hr_fi(_o5486, t_1675); hr_fs(_o5486, hr_str("(o, hr_sl(", 10)); hr_fs(_o5486, e_1676); hr_fs(_o5486, hr_str(")); ", 4)); }));
return;
 }
(void)(({ hrv *_o5487 = &(g169); hr_fs(_o5487, hr_str("hf", 2)); hr_fi(_o5487, t_1675); hr_fs(_o5487, hr_str("(o, ", 4)); hr_fs(_o5487, e_1676); hr_fs(_o5487, hr_str("); ", 3)); }));
}
static void f306_heq_val(int64_t t_1719, hsl a_1720, hsl b_1721) {
int64_t k_1722 = ((int64_t)(((*({ hrv *_t5488 = &(g554); int64_t _i5488 = t_1719; (S1*)_t5488->b + hr_ix(_i5488, _t5488->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:477"); }))).k_)); 
if ((((((k_1722) == (((int64_t)3LL))) || ((k_1722) == (((int64_t)4LL)))) || ((k_1722) == (((int64_t)2LL)))) || ((k_1722) == (((int64_t)10LL))))) { (void)(({ hrv *_o5489 = &(g169); hr_fs(_o5489, hr_str("(", 1)); hr_fs(_o5489, a_1720); hr_fs(_o5489, hr_str(") == (", 6)); hr_fs(_o5489, b_1721); hr_fs(_o5489, hr_str(")", 1)); }));
return;
 }
(void)(f297_gen_heq(t_1719));
if ((((k_1722) == (((int64_t)9LL))) || ((((k_1722) == (((int64_t)8LL))) && (!(f284_is_fix(t_1719)))) && (!(f285_is_lim(t_1719)))))) { (void)(({ hrv *_o5493 = &(g169); hr_fs(_o5493, hr_str("heq", 3)); hr_fi(_o5493, t_1719); hr_fs(_o5493, hr_str("(hr_sl(", 7)); hr_fs(_o5493, a_1720); hr_fs(_o5493, hr_str("), hr_sl(", 9)); hr_fs(_o5493, b_1721); hr_fs(_o5493, hr_str("))", 2)); }));
return;
 }
(void)(({ hrv *_o5494 = &(g169); hr_fs(_o5494, hr_str("heq", 3)); hr_fi(_o5494, t_1719); hr_fs(_o5494, hr_str("(", 1)); hr_fs(_o5494, a_1720); hr_fs(_o5494, hr_str(", ", 2)); hr_fs(_o5494, b_1721); hr_fs(_o5494, hr_str(")", 1)); }));
}
static bool f307_hsl_ty(int64_t t_1732) {
return (((((*({ hrv *_t5495 = &(g554); int64_t _i5495 = t_1732; (S1*)_t5495->b + hr_ix(_i5495, _t5495->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:793"); }))).k_) == (((uint8_t)9LL))) || ((((((*({ hrv *_t5496 = &(g554); int64_t _i5496 = t_1732; (S1*)_t5496->b + hr_ix(_i5496, _t5496->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:793"); }))).k_) == (((uint8_t)8LL))) && (!(f284_is_fix(t_1732)))) && (!(f285_is_lim(t_1732)))));
}
static void f308_gxas(int64_t n_1733, int64_t t_1734) {
int64_t f_1735 = f281_fin(n_1733); 
if (((f_1735) == (t_1734))) { (void)(f291_gx(n_1733));
return;
 }
(void)(f272_gcv(n_1733, f141_at(n_1733), t_1734));
}
static void f309_garith(int64_t o_1737, int64_t t0_1738, int64_t a_1739, int64_t b_1740, int64_t tv_1741, int64_t loc_1742) {
int64_t t_1743 = ({ int64_t _r5503; if (((((*({ hrv *_t5504 = &(g554); int64_t _i5504 = t0_1738; (S1*)_t5504->b + hr_ix(_i5504, _t5504->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:244"); }))).k_) == (((uint8_t)12LL)))) { _r5503 = g566;  } else { _r5503 = ({ int64_t _r5505; if (((((*({ hrv *_t5506 = &(g554); int64_t _i5506 = t0_1738; (S1*)_t5506->b + hr_ix(_i5506, _t5506->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:244"); }))).k_) == (((uint8_t)13LL)))) { _r5505 = g572;  } else { _r5505 = t0_1738;  } _r5505; });  } _r5503; }); 
int64_t k_1744 = ((int64_t)(((*({ hrv *_t5507 = &(g554); int64_t _i5507 = t_1743; (S1*)_t5507->b + hr_ix(_i5507, _t5507->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:245"); }))).k_)); 
int64_t lk_1745 = f183_leaf_kind(t_1743); 
if (((lk_1745) >= (((int64_t)4LL)))) { int64_t ta_1746 = ({ int64_t _r5509; if (((a_1739) >= (((int64_t)0LL)))) { _r5509 = f281_fin(a_1739);  } else { _r5509 = t_1743;  } _r5509; }); 
int64_t tb_1747 = ({ int64_t _r5511; if (((b_1740) >= (((int64_t)0LL)))) { _r5511 = f281_fin(b_1740);  } else { _r5511 = t_1743;  } _r5511; }); 
if (((ta_1746) != (t_1743))) { if (((o_1737) != (((int64_t)23LL)))) { (void)(f289_gerr(loc_1742, hr_str("only * takes a scalar on the left of a struct or array", 54)));
return;
 }
(void)(f262_ow(hr_str("hop", 3)));
(void)(f296_oi(t_1743));
(void)(f262_ow(hr_str("_", 1)));
(void)(f296_oi(o_1737));
(void)(f262_ow(hr_str("(", 1)));
(void)(f310_gopnd(b_1740, tv_1741));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f310_gopnd(a_1739, tv_1741));
(void)(f262_ow(hr_str(")", 1)));
(void)(f311_gen_hop(t_1743, o_1737, ta_1746));
return;
 }
(void)(f262_ow(hr_str("hop", 3)));
(void)(f296_oi(t_1743));
(void)(f262_ow(hr_str("_", 1)));
(void)(f296_oi(o_1737));
(void)(f262_ow(hr_str("(", 1)));
(void)(f310_gopnd(a_1739, tv_1741));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f310_gopnd(b_1740, tv_1741));
(void)(f262_ow(hr_str(")", 1)));
(void)(f311_gen_hop(t_1743, o_1737, tb_1747));
return;
 }
if (((k_1744) == (((int64_t)4LL)))) { if (((o_1737) == (((int64_t)25LL)))) { (void)(f262_ow(({ hsl _r5535; if (((((*({ hrv *_t5536 = &(g554); int64_t _i5536 = t_1743; (S1*)_t5536->b + hr_ix(_i5536, _t5536->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:252"); }))).s_) == (((uint8_t)4LL)))) { _r5535 = hr_str("fmodf(", 6);  } else { _r5535 = hr_str("fmod(", 5);  } _r5535; })));
(void)(f310_gopnd(a_1739, tv_1741));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f310_gopnd(b_1740, tv_1741));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
(void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(t_1743));
(void)(f262_ow(hr_str(")(", 2)));
(void)(f310_gopnd(a_1739, tv_1741));
(void)(f262_ow(hr_str(" ", 1)));
(void)(f262_ow(f313_ar_op(o_1737)));
(void)(f262_ow(hr_str(" ", 1)));
(void)(f310_gopnd(b_1740, tv_1741));
(void)(f262_ow(hr_str("))", 2)));
return;
 }
if (((k_1744) == (((int64_t)2LL)))) { (void)(f262_ow(hr_str("((", 2)));
(void)(f310_gopnd(a_1739, tv_1741));
(void)(f262_ow(hr_str(") ", 2)));
(void)(f262_ow(f313_ar_op(o_1737)));
(void)(f262_ow(hr_str(" (", 2)));
(void)(f310_gopnd(b_1740, tv_1741));
(void)(f262_ow(hr_str("))", 2)));
return;
 }
bool sg_1778 = (((k_1744) == (((int64_t)3LL))) && f156_is_signed(t_1743)); 
if ((((o_1737) == (((int64_t)24LL))) || ((o_1737) == (((int64_t)25LL))))) { (void)(f262_ow(({ hsl _r5561; if (((o_1737) == (((int64_t)24LL)))) { _r5561 = ({ hsl _r5562; if (sg_1778) { _r5562 = hr_str("HR_SDIV(", 8);  } else { _r5562 = hr_str("HR_UDIV(", 8);  } _r5562; });  } else { _r5561 = ({ hsl _r5563; if (sg_1778) { _r5563 = hr_str("HR_SMOD(", 8);  } else { _r5563 = hr_str("HR_UDIV_MOD(", 12);  } _r5563; });  } _r5561; })));
(void)(f263_ct(t_1743));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f310_gopnd(a_1739, tv_1741));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f310_gopnd(b_1740, tv_1741));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f314_wloc(loc_1742));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if ((((o_1737) == (((int64_t)43LL))) || ((o_1737) == (((int64_t)44LL))))) { (void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(t_1743));
(void)(f262_ow(hr_str(")((", 3)));
(void)(f310_gopnd(a_1739, tv_1741));
(void)(f262_ow(hr_str(") ", 2)));
(void)(f262_ow(f313_ar_op(o_1737)));
(void)(f262_ow(hr_str(" ((", 3)));
(void)(f310_gopnd(b_1740, tv_1741));
(void)(({ hrv *_o5581 = &(g163); hr_fs(_o5581, hr_str(") & ", 4)); hr_fi(_o5581, ((int64_t)((int64_t)f157_ibits(t_1743) - (int64_t)((int64_t)1LL)))); hr_fs(_o5581, hr_str(")))", 3)); }));
return;
 }
(void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(t_1743));
(void)(f262_ow(hr_str(")(", 2)));
if (sg_1778) { (void)(f262_ow(hr_str("(int64_t)", 9)));
 } else { (void)(f262_ow(hr_str("(uint64_t)", 10)));
 }
(void)(f310_gopnd(a_1739, tv_1741));
(void)(f262_ow(hr_str(" ", 1)));
(void)(f262_ow(f313_ar_op(o_1737)));
(void)(f262_ow(hr_str(" ", 1)));
if (sg_1778) { (void)(f262_ow(hr_str("(int64_t)", 9)));
 } else { (void)(f262_ow(hr_str("(uint64_t)", 10)));
 }
(void)(f310_gopnd(b_1740, tv_1741));
(void)(f262_ow(hr_str("))", 2)));
}
static void f310_gopnd(int64_t n_1748, int64_t tv_1749) {
if (((n_1748) >= (((int64_t)0LL)))) { (void)(f291_gx(n_1748));
 } else { (void)(({ hrv *_o5598 = &(g163); hr_fs(_o5598, hr_str("(*_t", 4)); hr_fi(_o5598, tv_1749); hr_fs(_o5598, hr_str(")", 1)); }));
 }
}
static void f311_gen_hop(int64_t t_1750, int64_t o_1751, int64_t bt_1752) {
int64_t key_1753 = ((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)(t_1750)) * (int64_t)((int64_t)4096LL))) + (int64_t)((int64_t)((int64_t)((int64_t)(o_1751)) * (int64_t)((int64_t)64LL))))) + (int64_t)({ int64_t _r5599; if (((bt_1752) == (t_1750))) { _r5599 = ((int64_t)0LL);  } else { _r5599 = ((int64_t)1LL);  } _r5599; }))); 
{ hrv *_v5601 = &(g240); for (int64_t _k5601 = 0; _k5601 < _v5601->n; _k5601++) { int64_t h_1754 = ((int64_t*)_v5601->b)[_k5601]; if (((h_1754) == (key_1753))) { return;
 }
 } } _bk5600:; 
(void)(({ hrv *_v5602 = &(g240); int64_t _x5602 = key_1753; int64_t *_p5602 = (int64_t*)hr_grow(_v5602, 1, sizeof _x5602); *_p5602 = _x5602; _p5602; }));
(void)(f264_cbody(t_1750));
int64_t lt_1755 = f184_leaf_type(t_1750); 
bool sc_1756 = ((bt_1752) != (t_1750)); 
L97 sig_1757 = ({ L97 _t5605; memset(&_t5605, 0, sizeof _t5605); _t5605.n = 0; _t5605; }); 
(void)(({ L97 *_l5606 = &(sig_1757); hrv _o5606 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5606, hr_str("static ", 7)); if (_l5606->n + _o5606.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:530"); memcpy(_l5606->e + _l5606->n, _o5606.b, (size_t)_o5606.n); _l5606->n += _o5606.n; }));
(void)(({ L97 *_v5607 = &(sig_1757); hsl _s5607 = f266_cn(t_1750); if (_v5607->n + _s5607.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:530"); memmove(_v5607->e + _v5607->n, _s5607.p, (size_t)_s5607.n * sizeof _v5607->e[0]); _v5607->n += _s5607.n; }));
(void)(({ L97 *_l5609 = &(sig_1757); hrv _o5609 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5609, hr_str(" hop", 4)); hr_fi(&_o5609, t_1750); hr_fs(&_o5609, hr_str("_", 1)); hr_fi(&_o5609, o_1751); hr_fs(&_o5609, hr_str("(", 1)); if (_l5609->n + _o5609.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:530"); memcpy(_l5609->e + _l5609->n, _o5609.b, (size_t)_o5609.n); _l5609->n += _o5609.n; }));
(void)(({ L97 *_v5610 = &(sig_1757); hsl _s5610 = f266_cn(t_1750); if (_v5610->n + _s5610.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:531"); memmove(_v5610->e + _v5610->n, _s5610.p, (size_t)_s5610.n * sizeof _v5610->e[0]); _v5610->n += _s5610.n; }));
(void)(({ L97 *_v5612 = &(sig_1757); hsl _s5612 = hr_str(" a, ", 4); if (_v5612->n + _s5612.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:531"); memmove(_v5612->e + _v5612->n, _s5612.p, (size_t)_s5612.n * sizeof _v5612->e[0]); _v5612->n += _s5612.n; }));
(void)(({ L97 *_v5613 = &(sig_1757); hsl _s5613 = f266_cn(({ int64_t _r5615; if (sc_1756) { _r5615 = bt_1752;  } else { _r5615 = t_1750;  } _r5615; })); if (_v5613->n + _s5613.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:531"); memmove(_v5613->e + _v5613->n, _s5613.p, (size_t)_s5613.n * sizeof _v5613->e[0]); _v5613->n += _s5613.n; }));
(void)(({ L97 *_v5616 = &(sig_1757); hsl _s5616 = hr_str(" b)", 3); if (_v5616->n + _s5616.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:531"); memmove(_v5616->e + _v5616->n, _s5616.p, (size_t)_s5616.n * sizeof _v5616->e[0]); _v5616->n += _s5616.n; }));
(void)(({ hrv *_v5617 = &(g166); hsl _s5617 = ({ hsl _t5618 = ({ L97 *_t5619 = &(sig_1757); (hsl){ (uint8_t*)_t5619->e, _t5619->n }; }); int64_t _l5618 = 0, _h5618 = _t5618.n; if (_l5618 < 0 || _h5618 < _l5618 || _h5618 > _t5618.n) hr_slerr(_l5618, _h5618, _t5618.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:532"); (hsl){ _t5618.p + _l5618 * (int64_t)sizeof(uint8_t), _h5618 - _l5618 }; }); hr_append(_v5617, _s5617.p, _s5617.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5620 = &(g166); hsl _s5620 = hr_str(";\012", 2); hr_append(_v5620, _s5620.p, _s5620.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5621 = &(g169); hsl _s5621 = ({ hsl _t5622 = ({ L97 *_t5623 = &(sig_1757); (hsl){ (uint8_t*)_t5623->e, _t5623->n }; }); int64_t _l5622 = 0, _h5622 = _t5622.n; if (_l5622 < 0 || _h5622 < _l5622 || _h5622 > _t5622.n) hr_slerr(_l5622, _h5622, _t5622.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:533"); (hsl){ _t5622.p + _l5622 * (int64_t)sizeof(uint8_t), _h5622 - _l5622 }; }); hr_append(_v5621, _s5621.p, _s5621.n, sizeof(uint8_t)); }));
(void)(f303_hh(hr_str(" { ", 3)));
(void)(({ hrv *_v5625 = &(g169); hsl _s5625 = f266_cn(t_1750); hr_append(_v5625, _s5625.p, _s5625.n, sizeof(uint8_t)); }));
(void)(f303_hh(hr_str(" r; ", 4)));
(void)(f312_hop_body(t_1750, o_1751, hr_str("r", 1), hr_str("a", 1), hr_str("b", 1), sc_1756));
(void)(f303_hh(hr_str("return r; }\012", 12)));
}
static void f312_hop_body(int64_t t_1758, int64_t o_1759, hsl r_1760, hsl a_1761, hsl b_1762, bool sc_1763) {
int64_t k_1764 = ((int64_t)(((*({ hrv *_t5630 = &(g554); int64_t _i5630 = t_1758; (S1*)_t5630->b + hr_ix(_i5630, _t5630->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:538"); }))).k_)); 
if ((((k_1764) == (((int64_t)3LL))) || ((k_1764) == (((int64_t)4LL))))) { (void)(({ hrv *_o5631 = &(g169); hr_fs(_o5631, r_1760); hr_fs(_o5631, hr_str(" = (", 4)); }));
(void)(({ hrv *_v5632 = &(g169); hsl _s5632 = f266_cn(t_1758); hr_append(_v5632, _s5632.p, _s5632.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o5634 = &(g169); hr_fs(_o5634, hr_str(")((", 3)); hr_fs(_o5634, a_1761); hr_fs(_o5634, hr_str(") ", 2)); hr_fs(_o5634, f313_ar_op(o_1759)); hr_fs(_o5634, hr_str(" (", 2)); hr_fs(_o5634, b_1762); hr_fs(_o5634, hr_str(")); ", 4)); }));
return;
 }
if (((k_1764) == (((int64_t)5LL)))) { int64_t si_1766 = ((int64_t)(((*({ hrv *_t5636 = &(g554); int64_t _i5636 = t_1758; (S1*)_t5636->b + hr_ix(_i5636, _t5636->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:541"); }))).a_)); 
int64_t f0_1767 = ((int64_t)(((*({ hrv *_t5637 = &(g557); int64_t _i5637 = si_1766; (S10*)_t5637->b + hr_ix(_i5637, _t5637->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:541"); }))).f0_)); 
{ int32_t _e5639 = ((*({ hrv *_t5640 = &(g557); int64_t _i5640 = si_1766; (S10*)_t5640->b + hr_ix(_i5640, _t5640->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:542"); }))).fnum_; for (int32_t _k5639 = 0; _k5639 < _e5639; _k5639++) { int32_t i_1768 = (int32_t)_k5639; S11 f_1769 = (*({ hrv *_t5641 = &(g558); int64_t _i5641 = ((int64_t)((int64_t)f0_1767 + (int64_t)((int64_t)(i_1768)))); (S11*)_t5641->b + hr_ix(_i5641, _t5641->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:543"); })); 
if ((((f_1769).ty_) < (((int32_t)0LL)))) { continue;
 }
L97 rr_1770 = ({ L97 _t5642; memset(&_t5642, 0, sizeof _t5642); _t5642.n = 0; _t5642; }); 
L97 aa_1771 = ({ L97 _t5643; memset(&_t5643, 0, sizeof _t5643); _t5643.n = 0; _t5643; }); 
L97 bb_1772 = ({ L97 _t5644; memset(&_t5644, 0, sizeof _t5644); _t5644.n = 0; _t5644; }); 
(void)(({ L97 *_v5645 = &(rr_1770); hsl _s5645 = r_1760; if (_v5645->n + _s5645.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:545"); memmove(_v5645->e + _v5645->n, _s5645.p, (size_t)_s5645.n * sizeof _v5645->e[0]); _v5645->n += _s5645.n; }));
(void)(({ L97 *_v5646 = &(rr_1770); uint8_t _x5646 = ((uint8_t)46LL); if (_v5646->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:545"); _v5646->e[_v5646->n] = _x5646; &_v5646->e[_v5646->n++]; }));
(void)(({ L97 *_v5647 = &(aa_1771); hsl _s5647 = a_1761; if (_v5647->n + _s5647.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:545"); memmove(_v5647->e + _v5647->n, _s5647.p, (size_t)_s5647.n * sizeof _v5647->e[0]); _v5647->n += _s5647.n; }));
(void)(({ L97 *_v5648 = &(aa_1771); uint8_t _x5648 = ((uint8_t)46LL); if (_v5648->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:545"); _v5648->e[_v5648->n] = _x5648; &_v5648->e[_v5648->n++]; }));
(void)(({ L97 *_v5649 = &(bb_1772); hsl _s5649 = b_1762; if (_v5649->n + _s5649.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:545"); memmove(_v5649->e + _v5649->n, _s5649.p, (size_t)_s5649.n * sizeof _v5649->e[0]); _v5649->n += _s5649.n; }));
if ((!(sc_1763))) { (void)(({ L97 *_v5650 = &(bb_1772); uint8_t _x5650 = ((uint8_t)46LL); if (_v5650->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:545"); _v5650->e[_v5650->n] = _x5650; &_v5650->e[_v5650->n++]; }));
 }
{ hsl _v5652 = f10_nm(((int64_t)((f_1769).name_))); for (int64_t _k5652 = 0; _k5652 < _v5652.n; _k5652++) { uint8_t ch_1773 = ((uint8_t*)_v5652.p)[_k5652]; (void)(({ L97 *_v5654 = &(rr_1770); uint8_t _x5654 = ch_1773; if (_v5654->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:546"); _v5654->e[_v5654->n] = _x5654; &_v5654->e[_v5654->n++]; }));
(void)(({ L97 *_v5655 = &(aa_1771); uint8_t _x5655 = ch_1773; if (_v5655->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:546"); _v5655->e[_v5655->n] = _x5655; &_v5655->e[_v5655->n++]; }));
if ((!(sc_1763))) { (void)(({ L97 *_v5656 = &(bb_1772); uint8_t _x5656 = ch_1773; if (_v5656->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:546"); _v5656->e[_v5656->n] = _x5656; &_v5656->e[_v5656->n++]; }));
 }
 } } _bk5651:; 
(void)(({ L97 *_v5657 = &(rr_1770); uint8_t _x5657 = ((uint8_t)95LL); if (_v5657->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:547"); _v5657->e[_v5657->n] = _x5657; &_v5657->e[_v5657->n++]; }));
(void)(({ L97 *_v5658 = &(aa_1771); uint8_t _x5658 = ((uint8_t)95LL); if (_v5658->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:547"); _v5658->e[_v5658->n] = _x5658; &_v5658->e[_v5658->n++]; }));
if ((!(sc_1763))) { (void)(({ L97 *_v5659 = &(bb_1772); uint8_t _x5659 = ((uint8_t)95LL); if (_v5659->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:547"); _v5659->e[_v5659->n] = _x5659; &_v5659->e[_v5659->n++]; }));
 }
(void)(f312_hop_body(((int64_t)((f_1769).ty_)), o_1759, ({ hsl _t5661 = ({ L97 *_t5662 = &(rr_1770); (hsl){ (uint8_t*)_t5662->e, _t5662->n }; }); int64_t _l5661 = 0, _h5661 = _t5661.n; if (_l5661 < 0 || _h5661 < _l5661 || _h5661 > _t5661.n) hr_slerr(_l5661, _h5661, _t5661.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:548"); (hsl){ _t5661.p + _l5661 * (int64_t)sizeof(uint8_t), _h5661 - _l5661 }; }), ({ hsl _t5663 = ({ L97 *_t5664 = &(aa_1771); (hsl){ (uint8_t*)_t5664->e, _t5664->n }; }); int64_t _l5663 = 0, _h5663 = _t5663.n; if (_l5663 < 0 || _h5663 < _l5663 || _h5663 > _t5663.n) hr_slerr(_l5663, _h5663, _t5663.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:548"); (hsl){ _t5663.p + _l5663 * (int64_t)sizeof(uint8_t), _h5663 - _l5663 }; }), ({ hsl _t5665 = ({ L97 *_t5666 = &(bb_1772); (hsl){ (uint8_t*)_t5666->e, _t5666->n }; }); int64_t _l5665 = 0, _h5665 = _t5665.n; if (_l5665 < 0 || _h5665 < _l5665 || _h5665 > _t5665.n) hr_slerr(_l5665, _h5665, _t5665.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:548"); (hsl){ _t5665.p + _l5665 * (int64_t)sizeof(uint8_t), _h5665 - _l5665 }; }), sc_1763));
 } } _bk5638:; 
return;
 }
if (f284_is_fix(t_1758)) { int64_t p_1774 = f295_nt(); 
(void)(({ hrv *_o5669 = &(g169); hr_fs(_o5669, hr_str("for (int64_t _i", 15)); hr_fi(_o5669, p_1774); hr_fs(_o5669, hr_str(" = 0; _i", 8)); hr_fi(_o5669, p_1774); hr_fs(_o5669, hr_str(" < ", 3)); hr_fi(_o5669, ((*({ hrv *_t5670 = &(g554); int64_t _i5670 = t_1758; (S1*)_t5670->b + hr_ix(_i5670, _t5670->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:554"); }))).b_); hr_fs(_o5669, hr_str("; _i", 4)); hr_fi(_o5669, p_1774); hr_fs(_o5669, hr_str("++) { ", 6)); }));
L97 rr_1775 = ({ L97 _t5671; memset(&_t5671, 0, sizeof _t5671); _t5671.n = 0; _t5671; }); 
L97 aa_1776 = ({ L97 _t5672; memset(&_t5672, 0, sizeof _t5672); _t5672.n = 0; _t5672; }); 
L97 bb_1777 = ({ L97 _t5673; memset(&_t5673, 0, sizeof _t5673); _t5673.n = 0; _t5673; }); 
(void)(({ L97 *_l5674 = &(rr_1775); hrv _o5674 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5674, r_1760); hr_fs(&_o5674, hr_str(".e[_i", 5)); hr_fi(&_o5674, p_1774); hr_fs(&_o5674, hr_str("]", 1)); if (_l5674->n + _o5674.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:556"); memcpy(_l5674->e + _l5674->n, _o5674.b, (size_t)_o5674.n); _l5674->n += _o5674.n; }));
(void)(({ L97 *_l5675 = &(aa_1776); hrv _o5675 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5675, a_1761); hr_fs(&_o5675, hr_str(".e[_i", 5)); hr_fi(&_o5675, p_1774); hr_fs(&_o5675, hr_str("]", 1)); if (_l5675->n + _o5675.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:556"); memcpy(_l5675->e + _l5675->n, _o5675.b, (size_t)_o5675.n); _l5675->n += _o5675.n; }));
if (sc_1763) { (void)(({ L97 *_v5676 = &(bb_1777); hsl _s5676 = b_1762; if (_v5676->n + _s5676.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:556"); memmove(_v5676->e + _v5676->n, _s5676.p, (size_t)_s5676.n * sizeof _v5676->e[0]); _v5676->n += _s5676.n; }));
 } else { (void)(({ L97 *_l5677 = &(bb_1777); hrv _o5677 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5677, b_1762); hr_fs(&_o5677, hr_str(".e[_i", 5)); hr_fi(&_o5677, p_1774); hr_fs(&_o5677, hr_str("]", 1)); if (_l5677->n + _o5677.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:556"); memcpy(_l5677->e + _l5677->n, _o5677.b, (size_t)_o5677.n); _l5677->n += _o5677.n; }));
 }
(void)(f312_hop_body(((int64_t)(((*({ hrv *_t5679 = &(g554); int64_t _i5679 = t_1758; (S1*)_t5679->b + hr_ix(_i5679, _t5679->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:557"); }))).a_)), o_1759, ({ hsl _t5680 = ({ L97 *_t5681 = &(rr_1775); (hsl){ (uint8_t*)_t5681->e, _t5681->n }; }); int64_t _l5680 = 0, _h5680 = _t5680.n; if (_l5680 < 0 || _h5680 < _l5680 || _h5680 > _t5680.n) hr_slerr(_l5680, _h5680, _t5680.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:557"); (hsl){ _t5680.p + _l5680 * (int64_t)sizeof(uint8_t), _h5680 - _l5680 }; }), ({ hsl _t5682 = ({ L97 *_t5683 = &(aa_1776); (hsl){ (uint8_t*)_t5683->e, _t5683->n }; }); int64_t _l5682 = 0, _h5682 = _t5682.n; if (_l5682 < 0 || _h5682 < _l5682 || _h5682 > _t5682.n) hr_slerr(_l5682, _h5682, _t5682.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:557"); (hsl){ _t5682.p + _l5682 * (int64_t)sizeof(uint8_t), _h5682 - _l5682 }; }), ({ hsl _t5684 = ({ L97 *_t5685 = &(bb_1777); (hsl){ (uint8_t*)_t5685->e, _t5685->n }; }); int64_t _l5684 = 0, _h5684 = _t5684.n; if (_l5684 < 0 || _h5684 < _l5684 || _h5684 > _t5684.n) hr_slerr(_l5684, _h5684, _t5684.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:557"); (hsl){ _t5684.p + _l5684 * (int64_t)sizeof(uint8_t), _h5684 - _l5684 }; }), sc_1763));
(void)(f303_hh(hr_str("} ", 2)));
 }
}
static hsl f313_ar_op(int64_t o_1765) {
if ((((o_1765) == (((int64_t)21LL))) || ((o_1765) == (((int64_t)26LL))))) { return hr_str("+", 1);
 }
if ((((o_1765) == (((int64_t)22LL))) || ((o_1765) == (((int64_t)27LL))))) { return hr_str("-", 1);
 }
if ((((o_1765) == (((int64_t)23LL))) || ((o_1765) == (((int64_t)28LL))))) { return hr_str("*", 1);
 }
if ((((o_1765) == (((int64_t)24LL))) || ((o_1765) == (((int64_t)29LL))))) { return hr_str("/", 1);
 }
if ((((o_1765) == (((int64_t)25LL))) || ((o_1765) == (((int64_t)30LL))))) { return hr_str("%", 1);
 }
if ((((o_1765) == (((int64_t)49LL))) || ((o_1765) == (((int64_t)31LL))))) { return hr_str("&", 1);
 }
if ((((o_1765) == (((int64_t)50LL))) || ((o_1765) == (((int64_t)32LL))))) { return hr_str("|", 1);
 }
if ((((o_1765) == (((int64_t)51LL))) || ((o_1765) == (((int64_t)33LL))))) { return hr_str("^", 1);
 }
if ((((o_1765) == (((int64_t)43LL))) || ((o_1765) == (((int64_t)45LL))))) { return hr_str("<<", 2);
 }
if ((((o_1765) == (((int64_t)44LL))) || ((o_1765) == (((int64_t)46LL))))) { return hr_str(">>", 2);
 }
return hr_str("\077", 1);
}
static void f314_wloc(int64_t n_1779) {
S3 x_1780 = (*({ hrv *_t5687 = &(g917); int64_t _i5687 = ((*({ hrv *_t5688 = &(g707); int64_t _i5688 = f103_max(n_1779, ((int64_t)0LL)); (S4*)_t5688->b + hr_ix(_i5688, _t5688->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:100"); }))).t_; (S3*)_t5687->b + hr_ix(_i5687, _t5687->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:100"); })); 
(void)(f262_ow(hr_str("\"", 1)));
{ hsl _v5692 = f10_nm(((int64_t)(((*({ hrv *_t5694 = &(g916); int64_t _i5694 = (x_1780).f_; (S2*)_t5694->b + hr_ix(_i5694, _t5694->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:100"); }))).name_))); for (int64_t _k5692 = 0; _k5692 < _v5692.n; _k5692++) { uint8_t c_1781 = ((uint8_t*)_v5692.p)[_k5692]; if ((((c_1781) == (((uint8_t)34LL))) || ((c_1781) == (((uint8_t)92LL))))) { (void)(({ hrv *_v5695 = &(g163); uint8_t _x5695 = ((uint8_t)92LL); uint8_t *_p5695 = (uint8_t*)hr_grow(_v5695, 1, sizeof _x5695); *_p5695 = _x5695; _p5695; }));
 }
(void)(({ hrv *_v5696 = &(g163); uint8_t _x5696 = c_1781; uint8_t *_p5696 = (uint8_t*)hr_grow(_v5696, 1, sizeof _x5696); *_p5696 = _x5696; _p5696; }));
 } } _bk5691:; 
(void)(({ hrv *_o5697 = &(g163); hr_fs(_o5697, hr_str(":", 1)); hr_fi(_o5697, (x_1780).line_); hr_fs(_o5697, hr_str("\"", 1)); }));
}
static void f315_gun(int64_t n_1782) {
S4 x_1783 = (*({ hrv *_t5698 = &(g707); int64_t _i5698 = n_1782; (S4*)_t5698->b + hr_ix(_i5698, _t5698->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:279"); })); 
int64_t o_1784 = ((int64_t)((x_1783).op_)); 
int64_t a_1785 = ((int64_t)((x_1783).a_)); 
if (((o_1784) == (((int64_t)47LL)))) { (void)(f262_ow(hr_str("(!(", 3)));
(void)(f291_gx(a_1785));
(void)(f262_ow(hr_str("))", 2)));
return;
 }
if (((o_1784) == (((int64_t)49LL)))) { (void)(f291_gx(a_1785));
return;
 }
int64_t t_1786 = f281_fin(n_1782); 
if (((o_1784) == (((int64_t)22LL)))) { if (((((*({ hrv *_t5704 = &(g554); int64_t _i5704 = t_1786; (S1*)_t5704->b + hr_ix(_i5704, _t5704->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:283"); }))).k_) == (((uint8_t)4LL)))) { (void)(f262_ow(hr_str("(-(", 3)));
(void)(f291_gx(a_1785));
(void)(f262_ow(hr_str("))", 2)));
return;
 }
if (((f183_leaf_kind(t_1786)) >= (((int64_t)4LL)))) { (void)(f262_ow(hr_str("hneg", 4)));
(void)(f296_oi(t_1786));
(void)(f262_ow(hr_str("(", 1)));
(void)(f291_gx(a_1785));
(void)(f262_ow(hr_str(")", 1)));
(void)(f316_gen_hneg(t_1786));
return;
 }
(void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(t_1786));
(void)(f262_ow(hr_str(")(0 - (uint64_t)(", 17)));
(void)(f291_gx(a_1785));
(void)(f262_ow(hr_str(")))", 3)));
return;
 }
if (((o_1784) == (((int64_t)48LL)))) { (void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(t_1786));
(void)(f262_ow(hr_str(")~(", 3)));
(void)(f291_gx(a_1785));
(void)(f262_ow(hr_str("))", 2)));
return;
 }
if (((o_1784) == (((int64_t)23LL)))) { (void)(f262_ow(hr_str("(*", 2)));
(void)(f291_gx(a_1785));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if (((o_1784) == (((int64_t)21LL)))) { (void)(f291_gx(a_1785));
return;
 }
(void)(f289_gerr(n_1782, hr_str("unsupported unary operator", 26)));
}
static void f316_gen_hneg(int64_t t_1787) {
{ hrv *_v5731 = &(g243); for (int64_t _k5731 = 0; _k5731 < _v5731->n; _k5731++) { int32_t h_1788 = ((int32_t*)_v5731->b)[_k5731]; if (((((int64_t)(h_1788))) == (t_1787))) { return;
 }
 } } _bk5730:; 
(void)(({ hrv *_v5732 = &(g243); int32_t _x5732 = ((int32_t)(t_1787)); int32_t *_p5732 = (int32_t*)hr_grow(_v5732, 1, sizeof _x5732); *_p5732 = _x5732; _p5732; }));
(void)(f264_cbody(t_1787));
L97 sig_1789 = ({ L97 _t5734; memset(&_t5734, 0, sizeof _t5734); _t5734.n = 0; _t5734; }); 
(void)(({ L97 *_l5735 = &(sig_1789); hrv _o5735 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5735, hr_str("static ", 7)); if (_l5735->n + _o5735.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:567"); memcpy(_l5735->e + _l5735->n, _o5735.b, (size_t)_o5735.n); _l5735->n += _o5735.n; }));
(void)(({ L97 *_v5736 = &(sig_1789); hsl _s5736 = f266_cn(t_1787); if (_v5736->n + _s5736.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:567"); memmove(_v5736->e + _v5736->n, _s5736.p, (size_t)_s5736.n * sizeof _v5736->e[0]); _v5736->n += _s5736.n; }));
(void)(({ L97 *_l5738 = &(sig_1789); hrv _o5738 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5738, hr_str(" hneg", 5)); hr_fi(&_o5738, t_1787); hr_fs(&_o5738, hr_str("(", 1)); if (_l5738->n + _o5738.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:567"); memcpy(_l5738->e + _l5738->n, _o5738.b, (size_t)_o5738.n); _l5738->n += _o5738.n; }));
(void)(({ L97 *_v5739 = &(sig_1789); hsl _s5739 = f266_cn(t_1787); if (_v5739->n + _s5739.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:567"); memmove(_v5739->e + _v5739->n, _s5739.p, (size_t)_s5739.n * sizeof _v5739->e[0]); _v5739->n += _s5739.n; }));
(void)(({ L97 *_v5741 = &(sig_1789); hsl _s5741 = hr_str(" a)", 3); if (_v5741->n + _s5741.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:567"); memmove(_v5741->e + _v5741->n, _s5741.p, (size_t)_s5741.n * sizeof _v5741->e[0]); _v5741->n += _s5741.n; }));
(void)(({ hrv *_v5742 = &(g166); hsl _s5742 = ({ hsl _t5743 = ({ L97 *_t5744 = &(sig_1789); (hsl){ (uint8_t*)_t5744->e, _t5744->n }; }); int64_t _l5743 = 0, _h5743 = _t5743.n; if (_l5743 < 0 || _h5743 < _l5743 || _h5743 > _t5743.n) hr_slerr(_l5743, _h5743, _t5743.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:568"); (hsl){ _t5743.p + _l5743 * (int64_t)sizeof(uint8_t), _h5743 - _l5743 }; }); hr_append(_v5742, _s5742.p, _s5742.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5745 = &(g166); hsl _s5745 = hr_str(";\012", 2); hr_append(_v5745, _s5745.p, _s5745.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5746 = &(g169); hsl _s5746 = ({ hsl _t5747 = ({ L97 *_t5748 = &(sig_1789); (hsl){ (uint8_t*)_t5748->e, _t5748->n }; }); int64_t _l5747 = 0, _h5747 = _t5747.n; if (_l5747 < 0 || _h5747 < _l5747 || _h5747 > _t5747.n) hr_slerr(_l5747, _h5747, _t5747.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:569"); (hsl){ _t5747.p + _l5747 * (int64_t)sizeof(uint8_t), _h5747 - _l5747 }; }); hr_append(_v5746, _s5746.p, _s5746.n, sizeof(uint8_t)); }));
(void)(f303_hh(hr_str(" { ", 3)));
(void)(({ hrv *_v5750 = &(g169); hsl _s5750 = f266_cn(t_1787); hr_append(_v5750, _s5750.p, _s5750.n, sizeof(uint8_t)); }));
(void)(f303_hh(hr_str(" z; memset(&z, 0, sizeof z); ", 29)));
(void)(({ hrv *_v5753 = &(g169); hsl _s5753 = f266_cn(t_1787); hr_append(_v5753, _s5753.p, _s5753.n, sizeof(uint8_t)); }));
(void)(f303_hh(hr_str(" r; ", 4)));
(void)(f312_hop_body(t_1787, ((int64_t)22LL), hr_str("r", 1), hr_str("z", 1), hr_str("a", 1), false));
(void)(f303_hh(hr_str("return r; }\012", 12)));
}
static void f317_gidx(int64_t n_1801) {
S4 x_1802 = (*({ hrv *_t5758 = &(g707); int64_t _i5758 = n_1801; (S4*)_t5758->b + hr_ix(_i5758, _t5758->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:290"); })); 
int64_t a_1803 = ((int64_t)((x_1802).a_)); 
int64_t bt_1804 = f141_at(a_1803); 
int64_t d_1805 = f182_deref(bt_1804); 
int64_t e_1806 = ((int64_t)(((*({ hrv *_t5761 = &(g554); int64_t _i5761 = d_1805; (S1*)_t5761->b + hr_ix(_i5761, _t5761->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:294"); }))).a_)); 
int64_t p_1807 = f295_nt(); 
if ((f284_is_fix(d_1805) && ((((*({ hrv *_t5764 = &(g554); int64_t _i5764 = bt_1804; (S1*)_t5764->b + hr_ix(_i5764, _t5764->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:296"); }))).k_) != (((uint8_t)10LL))))) { (void)(f262_ow(hr_str("(", 1)));
(void)(f291_gx(a_1803));
(void)(f262_ow(hr_str(").e[hr_ix(", 10)));
(void)(f291_gx(((int64_t)((x_1802).b_))));
(void)(({ hrv *_o5769 = &(g163); hr_fs(_o5769, hr_str(", ", 2)); hr_fi(_o5769, ((*({ hrv *_t5770 = &(g554); int64_t _i5770 = d_1805; (S1*)_t5770->b + hr_ix(_i5770, _t5770->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:297"); }))).b_); hr_fs(_o5769, hr_str(", ", 2)); }));
(void)(f314_wloc(n_1801));
(void)(f262_ow(hr_str(")]", 2)));
return;
 }
(void)(f262_ow(hr_str("(*({ ", 5)));
if (((((*({ hrv *_t5774 = &(g554); int64_t _i5774 = d_1805; (S1*)_t5774->b + hr_ix(_i5774, _t5774->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:300"); }))).k_) == (((uint8_t)9LL)))) { (void)(f262_ow(hr_str("hsl _t", 6)));
(void)(f296_oi(p_1807));
(void)(f262_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t5778 = &(g554); int64_t _i5778 = bt_1804; (S1*)_t5778->b + hr_ix(_i5778, _t5778->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:300"); }))).k_) == (((uint8_t)10LL)))) { (void)(f262_ow(hr_str("*", 1)));
(void)(f277_gx0(a_1803));
 } else { (void)(f291_gx(a_1803));
 }
(void)(f262_ow(hr_str("; int64_t _i", 12)));
(void)(f296_oi(p_1807));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(((int64_t)((x_1802).b_))));
(void)(f262_ow(hr_str("; (", 3)));
(void)(f263_ct(e_1806));
(void)(f262_ow(hr_str("*)_t", 4)));
(void)(f296_oi(p_1807));
(void)(({ hrv *_o5790 = &(g163); hr_fs(_o5790, hr_str(".p + hr_ix(_i", 13)); hr_fi(_o5790, p_1807); hr_fs(_o5790, hr_str(", _t", 4)); hr_fi(_o5790, p_1807); hr_fs(_o5790, hr_str(".n, ", 4)); }));
(void)(f314_wloc(n_1801));
(void)(f262_ow(hr_str("); }))", 6)));
return;
 }
(void)(f263_ct(d_1805));
(void)(f262_ow(hr_str(" *_t", 4)));
(void)(f296_oi(p_1807));
(void)(f262_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t5797 = &(g554); int64_t _i5797 = bt_1804; (S1*)_t5797->b + hr_ix(_i5797, _t5797->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:302"); }))).k_) == (((uint8_t)10LL)))) { (void)(f277_gx0(a_1803));
 } else { if (f274_is_place(a_1803)) { (void)(f262_ow(hr_str("&(", 2)));
(void)(f291_gx(a_1803));
(void)(f262_ow(hr_str(")", 1)));
 } else { int64_t k_1808 = f275_tmp(d_1805, f270_is_res(d_1805)); 
(void)(f262_ow(hr_str("(", 1)));
(void)(f276_ot(k_1808));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f271_gxo(a_1803));
(void)(f262_ow(hr_str(", &", 3)));
(void)(f276_ot(k_1808));
(void)(f262_ow(hr_str(")", 1)));
 }
 }
(void)(f262_ow(hr_str("; int64_t _i", 12)));
(void)(f296_oi(p_1807));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(((int64_t)((x_1802).b_))));
(void)(f262_ow(hr_str("; ", 2)));
if (f270_is_res(d_1805)) { (void)(f262_ow(hr_str("(", 1)));
(void)(f263_ct(e_1806));
(void)(f262_ow(hr_str("*)_t", 4)));
(void)(f296_oi(p_1807));
(void)(({ hrv *_o5822 = &(g163); hr_fs(_o5822, hr_str("->b + hr_ix(_i", 14)); hr_fi(_o5822, p_1807); hr_fs(_o5822, hr_str(", _t", 4)); hr_fi(_o5822, p_1807); hr_fs(_o5822, hr_str("->n, ", 5)); }));
(void)(f314_wloc(n_1801));
(void)(f262_ow(hr_str("); }))", 6)));
return;
 }
if (f284_is_fix(d_1805)) { (void)(({ hrv *_o5826 = &(g163); hr_fs(_o5826, hr_str("_t", 2)); hr_fi(_o5826, p_1807); hr_fs(_o5826, hr_str("->e + hr_ix(_i", 14)); hr_fi(_o5826, p_1807); hr_fs(_o5826, hr_str(", ", 2)); hr_fi(_o5826, ((*({ hrv *_t5827 = &(g554); int64_t _i5827 = d_1805; (S1*)_t5827->b + hr_ix(_i5827, _t5827->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:305"); }))).b_); hr_fs(_o5826, hr_str(", ", 2)); }));
(void)(f314_wloc(n_1801));
(void)(f262_ow(hr_str("); }))", 6)));
return;
 }
(void)(({ hrv *_o5830 = &(g163); hr_fs(_o5830, hr_str("_t", 2)); hr_fi(_o5830, p_1807); hr_fs(_o5830, hr_str("->e + hr_ix(_i", 14)); hr_fi(_o5830, p_1807); hr_fs(_o5830, hr_str(", _t", 4)); hr_fi(_o5830, p_1807); hr_fs(_o5830, hr_str("->n, ", 5)); }));
(void)(f314_wloc(n_1801));
(void)(f262_ow(hr_str("); }))", 6)));
}
static void f318_gslice(int64_t n_1809) {
S4 x_1810 = (*({ hrv *_t5833 = &(g707); int64_t _i5833 = n_1809; (S4*)_t5833->b + hr_ix(_i5833, _t5833->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:309"); })); 
int64_t a_1811 = ((int64_t)((x_1810).a_)); 
int64_t d_1812 = f182_deref(f141_at(a_1811)); 
int64_t e_1813 = ((int64_t)(((*({ hrv *_t5836 = &(g554); int64_t _i5836 = d_1812; (S1*)_t5836->b + hr_ix(_i5836, _t5836->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:312"); }))).a_)); 
int64_t p_1814 = f295_nt(); 
(void)(f262_ow(hr_str("({ hsl _t", 9)));
(void)(f296_oi(p_1814));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f294_gsl(a_1811, f141_at(a_1811)));
(void)(f262_ow(hr_str("; int64_t _l", 12)));
(void)(f296_oi(p_1814));
(void)(f262_ow(hr_str(" = ", 3)));
if ((((x_1810).b_) >= (((int32_t)0LL)))) { if (((((uint16_t)((uint64_t)(x_1810).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_o5846 = &(g163); hr_fs(_o5846, hr_str("_t", 2)); hr_fi(_o5846, p_1814); hr_fs(_o5846, hr_str(".n - ", 5)); }));
 }
(void)(f291_gx(((int64_t)((x_1810).b_))));
 } else { (void)(f262_ow(hr_str("0", 1)));
 }
(void)(f262_ow(hr_str(", _h", 4)));
(void)(f296_oi(p_1814));
(void)(f262_ow(hr_str(" = ", 3)));
if ((((x_1810).c_) >= (((int32_t)0LL)))) { if (((((uint16_t)((uint64_t)(x_1810).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_o5852 = &(g163); hr_fs(_o5852, hr_str("_t", 2)); hr_fi(_o5852, p_1814); hr_fs(_o5852, hr_str(".n - ", 5)); }));
 }
(void)(f291_gx(((int64_t)((x_1810).c_))));
 } else { (void)(({ hrv *_o5854 = &(g163); hr_fs(_o5854, hr_str("_t", 2)); hr_fi(_o5854, p_1814); hr_fs(_o5854, hr_str(".n", 2)); }));
 }
(void)(({ hrv *_o5855 = &(g163); hr_fs(_o5855, hr_str("; if (_l", 8)); hr_fi(_o5855, p_1814); hr_fs(_o5855, hr_str(" < 0 || _h", 10)); hr_fi(_o5855, p_1814); hr_fs(_o5855, hr_str(" < _l", 5)); hr_fi(_o5855, p_1814); hr_fs(_o5855, hr_str(" || _h", 6)); hr_fi(_o5855, p_1814); hr_fs(_o5855, hr_str(" > _t", 5)); hr_fi(_o5855, p_1814); hr_fs(_o5855, hr_str(".n) hr_slerr(_l", 15)); hr_fi(_o5855, p_1814); hr_fs(_o5855, hr_str(", _h", 4)); hr_fi(_o5855, p_1814); hr_fs(_o5855, hr_str(", _t", 4)); hr_fi(_o5855, p_1814); hr_fs(_o5855, hr_str(".n, ", 4)); }));
(void)(f314_wloc(n_1809));
(void)(({ hrv *_o5857 = &(g163); hr_fs(_o5857, hr_str("); (hsl){ _t", 12)); hr_fi(_o5857, p_1814); hr_fs(_o5857, hr_str(".p + _l", 7)); hr_fi(_o5857, p_1814); hr_fs(_o5857, hr_str(" * (int64_t)sizeof(", 19)); }));
(void)(f263_ct(e_1813));
(void)(({ hrv *_o5859 = &(g163); hr_fs(_o5859, hr_str("), _h", 5)); hr_fi(_o5859, p_1814); hr_fs(_o5859, hr_str(" - _l", 5)); hr_fi(_o5859, p_1814); hr_fs(_o5859, hr_str(" }; })", 6)); }));
}
static void f319_garr(int64_t n_1817) {
S4 x_1818 = (*({ hrv *_t5860 = &(g707); int64_t _i5860 = n_1817; (S4*)_t5860->b + hr_ix(_i5860, _t5860->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:322"); })); 
int64_t t_1819 = f141_at(n_1817); 
int64_t e_1820 = ((int64_t)(((*({ hrv *_t5862 = &(g554); int64_t _i5862 = t_1819; (S1*)_t5862->b + hr_ix(_i5862, _t5862->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:324"); }))).a_)); 
int64_t p_1821 = f295_nt(); 
if (f270_is_res(t_1819)) { if (((((x_1818).n_) == (((int32_t)0LL))) && (((x_1818).a_) < (((int32_t)0LL))))) { (void)(f262_ow(hr_str("((hrv){0})", 10)));
return;
 }
(void)(f262_ow(hr_str("({ hrv _t", 9)));
(void)(f296_oi(p_1821));
(void)(f262_ow(hr_str(" = {0}; ", 8)));
if ((((x_1818).a_) >= (((int32_t)0LL)))) { (void)(f262_ow(hr_str("int64_t _c", 10)));
(void)(f296_oi(p_1821));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(((int64_t)((x_1818).b_))));
(void)(f262_ow(hr_str("; ", 2)));
(void)(f263_ct(e_1820));
(void)(f262_ow(hr_str(" _v", 3)));
(void)(f296_oi(p_1821));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(((int64_t)((x_1818).a_))));
(void)(f262_ow(hr_str("; ", 2)));
(void)(f263_ct(e_1820));
(void)(f262_ow(hr_str(" *_p", 4)));
(void)(f296_oi(p_1821));
(void)(f262_ow(hr_str(" = (", 4)));
(void)(f263_ct(e_1820));
(void)(({ hrv *_o5885 = &(g163); hr_fs(_o5885, hr_str("*)hr_grow(&_t", 13)); hr_fi(_o5885, p_1821); hr_fs(_o5885, hr_str(", _c", 4)); hr_fi(_o5885, p_1821); hr_fs(_o5885, hr_str(", sizeof _v", 11)); hr_fi(_o5885, p_1821); hr_fs(_o5885, hr_str("); for (int64_t _k = 0; _k < _c", 31)); hr_fi(_o5885, p_1821); hr_fs(_o5885, hr_str("; _k++) _p", 10)); hr_fi(_o5885, p_1821); hr_fs(_o5885, hr_str("[_k] = _v", 9)); hr_fi(_o5885, p_1821); hr_fs(_o5885, hr_str("; ", 2)); }));
 } else { (void)(f263_ct(e_1820));
(void)(f262_ow(hr_str(" *_p", 4)));
(void)(f296_oi(p_1821));
(void)(f262_ow(hr_str(" = (", 4)));
(void)(f263_ct(e_1820));
(void)(({ hrv *_o5891 = &(g163); hr_fs(_o5891, hr_str("*)hr_grow(&_t", 13)); hr_fi(_o5891, p_1821); hr_fs(_o5891, hr_str(", ", 2)); hr_fi(_o5891, (x_1818).n_); hr_fs(_o5891, hr_str(", sizeof(", 9)); }));
(void)(f263_ct(e_1820));
(void)(f262_ow(hr_str(")); ", 4)));
{ int32_t _e5895 = (x_1818).n_; for (int32_t _k5895 = 0; _k5895 < _e5895; _k5895++) { int32_t i_1822 = (int32_t)_k5895; (void)(({ hrv *_o5896 = &(g163); hr_fs(_o5896, hr_str("_p", 2)); hr_fi(_o5896, p_1821); hr_fs(_o5896, hr_str("[", 1)); hr_fi(_o5896, i_1822); hr_fs(_o5896, hr_str("] = ", 4)); }));
(void)(f291_gx(f90_kid(n_1817, ((int64_t)(i_1822)))));
(void)(f262_ow(hr_str("; ", 2)));
 } } _bk5894:; 
 }
(void)(f262_ow(hr_str("_t", 2)));
(void)(f296_oi(p_1821));
(void)(f262_ow(hr_str("; })", 4)));
return;
 }
if ((f284_is_fix(t_1819) || f285_is_lim(t_1819))) { (void)(f262_ow(hr_str("({ ", 3)));
(void)(f263_ct(t_1819));
(void)(f262_ow(hr_str(" _t", 3)));
(void)(f296_oi(p_1821));
(void)(f262_ow(hr_str("; ", 2)));
if ((((x_1818).a_) >= (((int32_t)0LL)))) { (void)(f263_ct(e_1820));
(void)(f262_ow(hr_str(" _v", 3)));
(void)(f296_oi(p_1821));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(((int64_t)((x_1818).a_))));
(void)(({ hrv *_o5915 = &(g163); hr_fs(_o5915, hr_str("; for (int64_t _k = 0; _k < ", 28)); hr_fi(_o5915, ({ int64_t _r5916; if (f284_is_fix(t_1819)) { _r5916 = ((*({ hrv *_t5918 = &(g554); int64_t _i5918 = t_1819; (S1*)_t5918->b + hr_ix(_i5918, _t5918->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:336"); }))).b_;  } else { _r5916 = ((int64_t)0LL);  } _r5916; })); hr_fs(_o5915, hr_str("; _k++) _t", 10)); hr_fi(_o5915, p_1821); hr_fs(_o5915, hr_str(".e[_k] = _v", 11)); hr_fi(_o5915, p_1821); hr_fs(_o5915, hr_str("; ", 2)); }));
if (f285_is_lim(t_1819)) { (void)(f262_ow(hr_str("int64_t _c", 10)));
(void)(f296_oi(p_1821));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(((int64_t)((x_1818).b_))));
(void)(({ hrv *_o5924 = &(g163); hr_fs(_o5924, hr_str("; for (int64_t _k = 0; _k < _c", 30)); hr_fi(_o5924, p_1821); hr_fs(_o5924, hr_str("; _k++) _t", 10)); hr_fi(_o5924, p_1821); hr_fs(_o5924, hr_str(".e[_k] = _v", 11)); hr_fi(_o5924, p_1821); hr_fs(_o5924, hr_str("; _t", 4)); hr_fi(_o5924, p_1821); hr_fs(_o5924, hr_str(".n = _c", 7)); hr_fi(_o5924, p_1821); hr_fs(_o5924, hr_str("; ", 2)); }));
 }
 } else { if (f285_is_lim(t_1819)) { (void)(({ hrv *_o5926 = &(g163); hr_fs(_o5926, hr_str("memset(&_t", 10)); hr_fi(_o5926, p_1821); hr_fs(_o5926, hr_str(", 0, sizeof _t", 14)); hr_fi(_o5926, p_1821); hr_fs(_o5926, hr_str("); _t", 5)); hr_fi(_o5926, p_1821); hr_fs(_o5926, hr_str(".n = ", 5)); hr_fi(_o5926, (x_1818).n_); hr_fs(_o5926, hr_str("; ", 2)); }));
 }
{ int32_t _e5928 = (x_1818).n_; for (int32_t _k5928 = 0; _k5928 < _e5928; _k5928++) { int32_t i_1823 = (int32_t)_k5928; (void)(({ hrv *_o5929 = &(g163); hr_fs(_o5929, hr_str("_t", 2)); hr_fi(_o5929, p_1821); hr_fs(_o5929, hr_str(".e[", 3)); hr_fi(_o5929, i_1823); hr_fs(_o5929, hr_str("] = ", 4)); }));
(void)(f291_gx(f90_kid(n_1817, ((int64_t)(i_1823)))));
(void)(f262_ow(hr_str("; ", 2)));
 } } _bk5927:; 
 }
(void)(f262_ow(hr_str("_t", 2)));
(void)(f296_oi(p_1821));
(void)(f262_ow(hr_str("; })", 4)));
return;
 }
(void)(f289_gerr(n_1817, hr_str("unsupported array literal type", 30)));
}
static void f320_gslit(int64_t n_1824) {
S4 x_1825 = (*({ hrv *_t5937 = &(g707); int64_t _i5937 = n_1824; (S4*)_t5937->b + hr_ix(_i5937, _t5937->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:353"); })); 
int64_t t_1826 = f141_at(n_1824); 
int64_t si_1827 = f160_rv(n_1824); 
int64_t f0_1828 = ((int64_t)(((*({ hrv *_t5940 = &(g557); int64_t _i5940 = si_1827; (S10*)_t5940->b + hr_ix(_i5940, _t5940->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:356"); }))).f0_)); 
(void)(f262_ow(hr_str("((", 2)));
(void)(f263_ct(t_1826));
(void)(f262_ow(hr_str("){ ", 3)));
bool any_1829 = false; 
{ int32_t _e5945 = ((*({ hrv *_t5946 = &(g557); int64_t _i5946 = si_1827; (S10*)_t5946->b + hr_ix(_i5946, _t5946->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:359"); }))).fnum_; for (int32_t _k5945 = 0; _k5945 < _e5945; _k5945++) { int32_t j_1830 = (int32_t)_k5945; S11 f_1831 = (*({ hrv *_t5947 = &(g558); int64_t _i5947 = ((int64_t)((int64_t)f0_1828 + (int64_t)((int64_t)(j_1830)))); (S11*)_t5947->b + hr_ix(_i5947, _t5947->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:360"); })); 
if ((((f_1831).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t given_1832 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e5949 = (x_1825).n_; for (int32_t _k5949 = 0; _k5949 < _e5949; _k5949++) { int32_t i_1833 = (int32_t)_k5949; if (((f160_rv(f90_kid(n_1824, ((int64_t)(i_1833))))) == (((int64_t)(j_1830))))) { given_1832 = f90_kid(n_1824, ((int64_t)(i_1833)));
 }
 } } _bk5948:; 
if ((((given_1832) < (((int64_t)0LL))) && (((f_1831).def_) < (((int32_t)0LL))))) { continue;
 }
(void)(f262_ow(hr_str(".", 1)));
(void)(f269_fname_into((&(g163)), ((int64_t)((f_1831).name_))));
(void)(f262_ow(hr_str(" = ", 3)));
if (((given_1832) >= (((int64_t)0LL)))) { int64_t v_1834 = ((int64_t)(((*({ hrv *_t5956 = &(g707); int64_t _i5956 = given_1832; (S4*)_t5956->b + hr_ix(_i5956, _t5956->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:366"); }))).a_)); 
if (f270_is_res(((int64_t)((f_1831).ty_)))) { (void)(f271_gxo(v_1834));
 } else { (void)(f291_gx(v_1834));
 }
 } else { int64_t sa_1835 = g403; 
g403 = g405;
(void)(f291_gx(((int64_t)((f_1831).def_))));
g403 = sa_1835;
 }
(void)(f262_ow(hr_str(", ", 2)));
any_1829 = true;
 } } _bk5944:; 
if ((!(any_1829))) { (void)(f262_ow(hr_str("0", 1)));
 }
(void)(f262_ow(hr_str("})", 2)));
}
static void f321_gcall(int64_t n_1836) {
int64_t r_1837 = f159_rk(n_1836); 
if (((r_1837) == (((int64_t)4LL)))) { (void)(f322_gbuiltin(n_1836));
return;
 }
if (((r_1837) == (((int64_t)10LL)))) { (void)(f336_gblkcall(n_1836));
return;
 }
if (((r_1837) != (((int64_t)3LL)))) { (void)(f289_gerr(n_1836, hr_str("unsupported call", 16)));
return;
 }
int64_t inst_2061 = f160_rv(n_1836); 
int64_t recv_2062 = ({ int64_t _r5969; if ((((f219_ax(n_1836)) == (((int64_t)1LL))) && ((((*({ hrv *_t5971 = &(g707); int64_t _i5971 = ((*({ hrv *_t5972 = &(g707); int64_t _i5972 = n_1836; (S4*)_t5972->b + hr_ix(_i5972, _t5972->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:614"); }))).a_; (S4*)_t5971->b + hr_ix(_i5971, _t5971->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:614"); }))).k_) == (((uint8_t)14LL))))) { _r5969 = ((int64_t)(((*({ hrv *_t5973 = &(g707); int64_t _i5973 = ((*({ hrv *_t5974 = &(g707); int64_t _i5974 = n_1836; (S4*)_t5974->b + hr_ix(_i5974, _t5974->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:614"); }))).a_; (S4*)_t5973->b + hr_ix(_i5973, _t5973->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:614"); }))).a_));  } else { _r5969 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r5969; }); 
bool lrw_2064 = ((!(f359_is_ext(inst_2061))) && ((*({ hrv *_t5976 = &(g390); int64_t _i5976 = inst_2061; (S6*)_t5976->b + hr_ix(_i5976, _t5976->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:615"); }))).lr_); 
int64_t rt_2065 = ((int64_t)(((*({ hrv *_t5977 = &(g390); int64_t _i5977 = inst_2061; (S6*)_t5977->b + hr_ix(_i5977, _t5977->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:616"); }))).ret_)); 
bool vd_2066 = (((rt_2065) < (((int64_t)0LL))) || ((rt_2065) == (g561))); 
int64_t q_2067 = f295_nt(); 
if (lrw_2064) { (void)(f262_ow(hr_str("({ ", 3)));
if ((!(vd_2066))) { (void)(f263_ct(rt_2065));
(void)(({ hrv *_o5981 = &(g163); hr_fs(_o5981, hr_str(" _c", 3)); hr_fi(_o5981, q_2067); hr_fs(_o5981, hr_str(" = ", 3)); }));
 }
 }
if (f359_is_ext(inst_2061)) { (void)(f360_ext_name(inst_2061));
 } else { (void)(f325_fn_cname(inst_2061));
 }
(void)(f262_ow(hr_str("(", 1)));
(void)(f361_gcall_args(n_1836, inst_2061, recv_2062));
(void)(f262_ow(hr_str(")", 1)));
if (lrw_2064) { (void)(f262_ow(hr_str("; ", 2)));
(void)(f363_glrcheck());
if ((!(vd_2066))) { (void)(({ hrv *_o5990 = &(g163); hr_fs(_o5990, hr_str("_c", 2)); hr_fi(_o5990, q_2067); hr_fs(_o5990, hr_str("; ", 2)); }));
 }
(void)(f262_ow(hr_str("})", 2)));
 }
}
static void f322_gbuiltin(int64_t n_1838) {
S4 x_1839 = (*({ hrv *_t5992 = &(g707); int64_t _i5992 = n_1838; (S4*)_t5992->b + hr_ix(_i5992, _t5992->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:653"); })); 
int64_t b_1840 = f160_rv(n_1838); 
bool hasr_1841 = ((f219_ax(n_1838)) == (((int64_t)1LL))); 
int64_t recv_1842 = ({ int64_t _r5995; if (hasr_1841) { _r5995 = ((int64_t)(((*({ hrv *_t5996 = &(g707); int64_t _i5996 = (x_1839).a_; (S4*)_t5996->b + hr_ix(_i5996, _t5996->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:656"); }))).a_));  } else { _r5995 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r5995; }); 
int64_t total_1843 = ((int64_t)((int64_t)((int64_t)((x_1839).n_)) + (int64_t)({ int64_t _r5997; if (hasr_1841) { _r5997 = ((int64_t)1LL);  } else { _r5997 = ((int64_t)0LL);  } _r5997; }))); 

int64_t p_1845 = f295_nt(); 
if (((b_1840) == (((int64_t)1LL)))) { (void)(f262_ow(hr_str("({ ", 3)));
{ int32_t _e6001 = (x_1839).n_; for (int32_t _k6001 = 0; _k6001 < _e6001; _k6001++) { int32_t i_1846 = (int32_t)_k6001; int64_t c_1847 = f90_kid(n_1838, ((int64_t)(i_1846))); 
(void)(f324_gfmt(hr_str("&hr_ob", 6), c_1847, f281_fin(c_1847), true));
(void)(f262_ow(hr_str("; ", 2)));
 } } _bk6000:; 
(void)(f262_ow(hr_str("hr_println(); })", 16)));
return;
 }
if (((b_1840) == (((int64_t)2LL)))) { (void)(f262_ow(hr_str("({ hrv _o", 9)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" = {0}; ", 8)));
L99 nmo_1863 = ({ L99 _t6010; memset(&_t6010, 0, sizeof _t6010); _t6010.n = 0; _t6010; }); 
(void)(({ L99 *_l6011 = &(nmo_1863); hrv _o6011 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6011, hr_str("&_o", 3)); hr_fi(&_o6011, p_1845); if (_l6011->n + _o6011.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:661"); memcpy(_l6011->e + _l6011->n, _o6011.b, (size_t)_o6011.n); _l6011->n += _o6011.n; }));
{ int32_t _e6013 = (x_1839).n_; for (int32_t _k6013 = 0; _k6013 < _e6013; _k6013++) { int32_t i_1864 = (int32_t)_k6013; int64_t c_1865 = f90_kid(n_1838, ((int64_t)(i_1864))); 
(void)(f324_gfmt(({ hsl _t6016 = ({ L99 *_t6017 = &(nmo_1863); (hsl){ (uint8_t*)_t6017->e, _t6017->n }; }); int64_t _l6016 = 0, _h6016 = _t6016.n; if (_l6016 < 0 || _h6016 < _l6016 || _h6016 > _t6016.n) hr_slerr(_l6016, _h6016, _t6016.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:661"); (hsl){ _t6016.p + _l6016 * (int64_t)sizeof(uint8_t), _h6016 - _l6016 }; }), c_1865, f281_fin(c_1865), true));
(void)(f262_ow(hr_str("; ", 2)));
 } } _bk6012:; 
(void)(f262_ow(hr_str("_o", 2)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str("; })", 4)));
return;
 }
if ((((b_1840) == (((int64_t)3LL))) && f285_is_lim(f182_deref(f141_at(f323_arg(((int64_t)0LL), &recv_1842, &n_1838)))))) { int64_t lt_1866 = f182_deref(f141_at(f323_arg(((int64_t)0LL), &recv_1842, &n_1838))); 
(void)(f262_ow(hr_str("({ ", 3)));
(void)(f263_ct(lt_1866));
(void)(f262_ow(hr_str(" *_l", 4)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f327_grecv_ptr(f323_arg(((int64_t)0LL), &recv_1842, &n_1838)));
(void)(f262_ow(hr_str("; hrv _o", 8)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" __attribute__((cleanup(hr_rdrop))) = {0}; ", 43)));
L99 nmo_1870 = ({ L99 _t6040; memset(&_t6040, 0, sizeof _t6040); _t6040.n = 0; _t6040; }); 
(void)(({ L99 *_l6041 = &(nmo_1870); hrv _o6041 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6041, hr_str("&_o", 3)); hr_fi(&_o6041, p_1845); if (_l6041->n + _o6041.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:665"); memcpy(_l6041->e + _l6041->n, _o6041.b, (size_t)_o6041.n); _l6041->n += _o6041.n; }));
{ int64_t _e6043 = total_1843; for (int64_t _k6043 = ((int64_t)1LL); _k6043 < _e6043; _k6043++) { int64_t i_1871 = (int64_t)_k6043; int64_t c_1872 = f323_arg(i_1871, &recv_1842, &n_1838); 
(void)(f324_gfmt(({ hsl _t6046 = ({ L99 *_t6047 = &(nmo_1870); (hsl){ (uint8_t*)_t6047->e, _t6047->n }; }); int64_t _l6046 = 0, _h6046 = _t6046.n; if (_l6046 < 0 || _h6046 < _l6046 || _h6046 > _t6046.n) hr_slerr(_l6046, _h6046, _t6046.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:666"); (hsl){ _t6046.p + _l6046 * (int64_t)sizeof(uint8_t), _h6046 - _l6046 }; }), c_1872, f281_fin(c_1872), true));
(void)(f262_ow(hr_str("; ", 2)));
 } } _bk6042:; 
(void)(({ hrv *_o6050 = &(g163); hr_fs(_o6050, hr_str("if (_l", 6)); hr_fi(_o6050, p_1845); hr_fs(_o6050, hr_str("->n + _o", 8)); hr_fi(_o6050, p_1845); hr_fs(_o6050, hr_str(".n > ", 5)); hr_fi(_o6050, ((*({ hrv *_t6051 = &(g554); int64_t _i6051 = lt_1866; (S1*)_t6051->b + hr_ix(_i6051, _t6051->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:667"); }))).b_); hr_fs(_o6050, hr_str(") hr_die(\"format past a limited array's capacity\", ", 51)); }));
(void)(f314_wloc(n_1838));
(void)(({ hrv *_o6053 = &(g163); hr_fs(_o6053, hr_str("); memcpy(_l", 12)); hr_fi(_o6053, p_1845); hr_fs(_o6053, hr_str("->e + _l", 8)); hr_fi(_o6053, p_1845); hr_fs(_o6053, hr_str("->n, _o", 7)); hr_fi(_o6053, p_1845); hr_fs(_o6053, hr_str(".b, (size_t)_o", 14)); hr_fi(_o6053, p_1845); hr_fs(_o6053, hr_str(".n); _l", 7)); hr_fi(_o6053, p_1845); hr_fs(_o6053, hr_str("->n += _o", 9)); hr_fi(_o6053, p_1845); hr_fs(_o6053, hr_str(".n; })", 6)); }));
return;
 }
if (((b_1840) == (((int64_t)3LL)))) { (void)(f262_ow(hr_str("({ hrv *_o", 10)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f327_grecv_ptr(f323_arg(((int64_t)0LL), &recv_1842, &n_1838)));
(void)(f262_ow(hr_str("; ", 2)));
L99 nmo_1873 = ({ L99 _t6060; memset(&_t6060, 0, sizeof _t6060); _t6060.n = 0; _t6060; }); 
(void)(({ L99 *_l6061 = &(nmo_1873); hrv _o6061 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6061, hr_str("_o", 2)); hr_fi(&_o6061, p_1845); if (_l6061->n + _o6061.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:670"); memcpy(_l6061->e + _l6061->n, _o6061.b, (size_t)_o6061.n); _l6061->n += _o6061.n; }));
{ int64_t _e6063 = total_1843; for (int64_t _k6063 = ((int64_t)1LL); _k6063 < _e6063; _k6063++) { int64_t i_1874 = (int64_t)_k6063; int64_t c_1875 = f323_arg(i_1874, &recv_1842, &n_1838); 
(void)(f324_gfmt(({ hsl _t6066 = ({ L99 *_t6067 = &(nmo_1873); (hsl){ (uint8_t*)_t6067->e, _t6067->n }; }); int64_t _l6066 = 0, _h6066 = _t6066.n; if (_l6066 < 0 || _h6066 < _l6066 || _h6066 > _t6066.n) hr_slerr(_l6066, _h6066, _t6066.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:670"); (hsl){ _t6066.p + _l6066 * (int64_t)sizeof(uint8_t), _h6066 - _l6066 }; }), c_1875, f281_fin(c_1875), true));
(void)(f262_ow(hr_str("; ", 2)));
 } } _bk6062:; 
(void)(f262_ow(hr_str("})", 2)));
return;
 }
if (((b_1840) == (((int64_t)4LL)))) { (void)(f262_ow(hr_str("({ if (!(", 9)));
(void)(f291_gx(f323_arg(((int64_t)0LL), &recv_1842, &n_1838)));
(void)(f262_ow(hr_str(")) hr_assert_fail(", 18)));
(void)(f314_wloc(n_1838));
(void)(f262_ow(hr_str("); })", 5)));
return;
 }
if (((b_1840) == (((int64_t)5LL)))) { (void)(f262_ow(hr_str("hr_abort(", 9)));
(void)(f293_gas(f323_arg(((int64_t)0LL), &recv_1842, &n_1838)));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if (((b_1840) == (((int64_t)6LL)))) { (void)(f262_ow(hr_str("hr_exit(", 8)));
(void)(f291_gx(f323_arg(((int64_t)0LL), &recv_1842, &n_1838)));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if (((b_1840) == (((int64_t)8LL)))) { int64_t t_1876 = f141_at(n_1838); 
(void)(f262_ow(hr_str("({ ", 3)));
(void)(f263_ct(t_1876));
(void)(f262_ow(hr_str(" _d", 3)));
(void)(f296_oi(p_1845));
(void)(({ hrv *_o6090 = &(g163); hr_fs(_o6090, hr_str("; memset(&_d", 12)); hr_fi(_o6090, p_1845); hr_fs(_o6090, hr_str(", 0, sizeof _d", 14)); hr_fi(_o6090, p_1845); hr_fs(_o6090, hr_str("); _d", 5)); hr_fi(_o6090, p_1845); hr_fs(_o6090, hr_str("; })", 4)); }));
return;
 }
if (((b_1840) == (((int64_t)9LL)))) { int64_t c_1877 = f323_arg(((int64_t)0LL), &recv_1842, &n_1838); 
int64_t t_1878 = f182_deref(f281_fin(c_1877)); 
if (f284_is_fix(t_1878)) { (void)(({ hrv *_o6095 = &(g163); hr_fs(_o6095, hr_str("((int64_t)", 10)); hr_fi(_o6095, ((*({ hrv *_t6096 = &(g554); int64_t _i6096 = t_1878; (S1*)_t6096->b + hr_ix(_i6096, _t6096->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:675"); }))).b_); hr_fs(_o6095, hr_str(")", 1)); }));
return;
 }
(void)(f262_ow(hr_str("(", 1)));
(void)(f293_gas(c_1877));
(void)(f262_ow(hr_str(").n", 3)));
return;
 }
if (((b_1840) == (((int64_t)7LL)))) { int64_t c_1879 = f323_arg(((int64_t)0LL), &recv_1842, &n_1838); 
int64_t t_1880 = f182_deref(f281_fin(c_1879)); 
if ((((((*({ hrv *_t6103 = &(g554); int64_t _i6103 = t_1880; (S1*)_t6103->b + hr_ix(_i6103, _t6103->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:676"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t6104 = &(g554); int64_t _i6104 = t_1880; (S1*)_t6104->b + hr_ix(_i6104, _t6104->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:676"); }))).k_) == (((uint8_t)9LL))))) { (void)(f262_ow(hr_str("hr_rfrom(", 9)));
(void)(f293_gas(c_1879));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f328_esz(((int64_t)(((*({ hrv *_t6109 = &(g554); int64_t _i6109 = t_1880; (S1*)_t6109->b + hr_ix(_i6109, _t6109->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:676"); }))).a_))));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if (((f281_fin(c_1879)) != (t_1880))) { (void)(f262_ow(hr_str("(*", 2)));
(void)(f291_gx(c_1879));
(void)(f262_ow(hr_str(")", 1)));
 } else { (void)(f291_gx(c_1879));
 }
return;
 }
if (((b_1840) == (((int64_t)31LL)))) { int64_t c_1882 = f323_arg(((int64_t)0LL), &recv_1842, &n_1838); 
int64_t t_1883 = f182_deref(f281_fin(c_1882)); 
if ((((((*({ hrv *_t6119 = &(g554); int64_t _i6119 = t_1883; (S1*)_t6119->b + hr_ix(_i6119, _t6119->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:677"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t6120 = &(g554); int64_t _i6120 = t_1883; (S1*)_t6120->b + hr_ix(_i6120, _t6120->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:677"); }))).k_) == (((uint8_t)9LL))))) { int64_t q_1884 = f295_nt(); 
(void)(f262_ow(hr_str("({ hsl _s", 9)));
(void)(f296_oi(q_1884));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f293_gas(c_1882));
(void)(({ hrv *_o6126 = &(g163); hr_fs(_o6126, hr_str("; (hsl){ _s", 11)); hr_fi(_o6126, q_1884); hr_fs(_o6126, hr_str(".p, _s", 6)); hr_fi(_o6126, q_1884); hr_fs(_o6126, hr_str(".n * (int64_t)sizeof(", 21)); }));
(void)(f263_ct(((int64_t)(((*({ hrv *_t6128 = &(g554); int64_t _i6128 = t_1883; (S1*)_t6128->b + hr_ix(_i6128, _t6128->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:677"); }))).a_))));
(void)(f262_ow(hr_str(") }; })", 7)));
return;
 }
(void)(f262_ow(hr_str("((hsl){ (uint8_t*)", 18)));
(void)(f326_gaddr(c_1882));
(void)(f262_ow(hr_str(", sizeof(", 9)));
(void)(f263_ct(t_1883));
(void)(f262_ow(hr_str(") })", 4)));
return;
 }
if (((b_1840) == (((int64_t)30LL)))) { int64_t c_1885 = f323_arg(((int64_t)0LL), &recv_1842, &n_1838); 
int64_t t_1886 = f182_deref(f281_fin(c_1885)); 
(void)(f262_ow(hr_str("hr_rfrom(", 9)));
if ((((((*({ hrv *_t6139 = &(g554); int64_t _i6139 = t_1886; (S1*)_t6139->b + hr_ix(_i6139, _t6139->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:678"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t6140 = &(g554); int64_t _i6140 = t_1886; (S1*)_t6140->b + hr_ix(_i6140, _t6140->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:678"); }))).k_) == (((uint8_t)9LL))))) { int64_t q_1887 = f295_nt(); 
(void)(f262_ow(hr_str("({ hsl _s", 9)));
(void)(f296_oi(q_1887));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f293_gas(c_1885));
(void)(({ hrv *_o6146 = &(g163); hr_fs(_o6146, hr_str("; (hsl){ _s", 11)); hr_fi(_o6146, q_1887); hr_fs(_o6146, hr_str(".p, _s", 6)); hr_fi(_o6146, q_1887); hr_fs(_o6146, hr_str(".n * (int64_t)sizeof(", 21)); }));
(void)(f263_ct(((int64_t)(((*({ hrv *_t6148 = &(g554); int64_t _i6148 = t_1886; (S1*)_t6148->b + hr_ix(_i6148, _t6148->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:678"); }))).a_))));
(void)(f262_ow(hr_str(") }; })", 7)));
 } else { (void)(f262_ow(hr_str("((hsl){ (uint8_t*)", 18)));
(void)(f326_gaddr(c_1885));
(void)(f262_ow(hr_str(", sizeof(", 9)));
(void)(f263_ct(t_1886));
(void)(f262_ow(hr_str(") })", 4)));
 }
(void)(f262_ow(hr_str(", 1)", 4)));
return;
 }
if (((b_1840) == (((int64_t)33LL)))) { (void)(f329_gembed(n_1838, f323_arg(((int64_t)0LL), &recv_1842, &n_1838)));
return;
 }
if (((b_1840) == (((int64_t)32LL)))) { int64_t t_1896 = f141_at(n_1838); 
(void)(f262_ow(hr_str("({ hsl _s", 9)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f293_gas(f323_arg(((int64_t)0LL), &recv_1842, &n_1838)));
(void)(f262_ow(hr_str("; ", 2)));
(void)(f263_ct(t_1896));
(void)(({ hrv *_o6166 = &(g163); hr_fs(_o6166, hr_str(" _d", 3)); hr_fi(_o6166, p_1845); hr_fs(_o6166, hr_str("; if (_s", 8)); hr_fi(_o6166, p_1845); hr_fs(_o6166, hr_str(".n != sizeof _d", 15)); hr_fi(_o6166, p_1845); hr_fs(_o6166, hr_str(") hr_die(\"from_bytes: wrong byte count\", ", 41)); }));
(void)(f314_wloc(n_1838));
(void)(({ hrv *_o6168 = &(g163); hr_fs(_o6168, hr_str("); memcpy(&_d", 13)); hr_fi(_o6168, p_1845); hr_fs(_o6168, hr_str(", _s", 4)); hr_fi(_o6168, p_1845); hr_fs(_o6168, hr_str(".p, sizeof _d", 13)); hr_fi(_o6168, p_1845); hr_fs(_o6168, hr_str("); _d", 5)); hr_fi(_o6168, p_1845); hr_fs(_o6168, hr_str("; })", 4)); }));
return;
 }
if (((recv_1842) < (((int64_t)0LL)))) { (void)(f289_gerr(n_1838, hr_str("unsupported builtin call", 24)));
return;
 }
int64_t rt_1897 = f182_deref(f141_at(recv_1842)); 
int64_t e_1898 = ((int64_t)(((*({ hrv *_t6172 = &(g554); int64_t _i6172 = rt_1897; (S1*)_t6172->b + hr_ix(_i6172, _t6172->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:683"); }))).a_)); 
if (f285_is_lim(rt_1897)) { (void)(f262_ow(hr_str("({ ", 3)));
(void)(f263_ct(rt_1897));
(void)(f262_ow(hr_str(" *_v", 4)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f327_grecv_ptr(recv_1842));
(void)(f262_ow(hr_str("; ", 2)));
if (((b_1840) == (((int64_t)20LL)))) { (void)(f263_ct(e_1898));
(void)(f262_ow(hr_str(" _x", 3)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(f323_arg(((int64_t)1LL), &recv_1842, &n_1838)));
(void)(({ hrv *_o6187 = &(g163); hr_fs(_o6187, hr_str("; if (_v", 8)); hr_fi(_o6187, p_1845); hr_fs(_o6187, hr_str("->n >= ", 7)); hr_fi(_o6187, ((*({ hrv *_t6188 = &(g554); int64_t _i6188 = rt_1897; (S1*)_t6188->b + hr_ix(_i6188, _t6188->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:686"); }))).b_); hr_fs(_o6187, hr_str(") hr_die(\"push past a limited array's capacity\", ", 49)); }));
(void)(f314_wloc(n_1838));
(void)(({ hrv *_o6190 = &(g163); hr_fs(_o6190, hr_str("); _v", 5)); hr_fi(_o6190, p_1845); hr_fs(_o6190, hr_str("->e[_v", 6)); hr_fi(_o6190, p_1845); hr_fs(_o6190, hr_str("->n] = _x", 9)); hr_fi(_o6190, p_1845); hr_fs(_o6190, hr_str("; &_v", 5)); hr_fi(_o6190, p_1845); hr_fs(_o6190, hr_str("->e[_v", 6)); hr_fi(_o6190, p_1845); hr_fs(_o6190, hr_str("->n++]; })", 10)); }));
return;
 }
if (((b_1840) == (((int64_t)21LL)))) { (void)(({ hrv *_o6191 = &(g163); hr_fs(_o6191, hr_str("hsl _s", 6)); hr_fi(_o6191, p_1845); hr_fs(_o6191, hr_str(" = ", 3)); }));
(void)(f293_gas(f323_arg(((int64_t)1LL), &recv_1842, &n_1838)));
(void)(({ hrv *_o6194 = &(g163); hr_fs(_o6194, hr_str("; if (_v", 8)); hr_fi(_o6194, p_1845); hr_fs(_o6194, hr_str("->n + _s", 8)); hr_fi(_o6194, p_1845); hr_fs(_o6194, hr_str(".n > ", 5)); hr_fi(_o6194, ((*({ hrv *_t6195 = &(g554); int64_t _i6195 = rt_1897; (S1*)_t6195->b + hr_ix(_i6195, _t6195->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:687"); }))).b_); hr_fs(_o6194, hr_str(") hr_die(\"append past a limited array's capacity\", ", 51)); }));
(void)(f314_wloc(n_1838));
(void)(({ hrv *_o6197 = &(g163); hr_fs(_o6197, hr_str("); memmove(_v", 13)); hr_fi(_o6197, p_1845); hr_fs(_o6197, hr_str("->e + _v", 8)); hr_fi(_o6197, p_1845); hr_fs(_o6197, hr_str("->n, _s", 7)); hr_fi(_o6197, p_1845); hr_fs(_o6197, hr_str(".p, (size_t)_s", 14)); hr_fi(_o6197, p_1845); hr_fs(_o6197, hr_str(".n * sizeof _v", 14)); hr_fi(_o6197, p_1845); hr_fs(_o6197, hr_str("->e[0]); _v", 11)); hr_fi(_o6197, p_1845); hr_fs(_o6197, hr_str("->n += _s", 9)); hr_fi(_o6197, p_1845); hr_fs(_o6197, hr_str(".n; })", 6)); }));
return;
 }
if (((b_1840) == (((int64_t)22LL)))) { (void)(({ hrv *_o6198 = &(g163); hr_fs(_o6198, hr_str("if (!_v", 7)); hr_fi(_o6198, p_1845); hr_fs(_o6198, hr_str("->n) hr_die(\"pop of an empty array\", ", 37)); }));
(void)(f314_wloc(n_1838));
(void)(({ hrv *_o6200 = &(g163); hr_fs(_o6200, hr_str("); _v", 5)); hr_fi(_o6200, p_1845); hr_fs(_o6200, hr_str("->e[--_v", 8)); hr_fi(_o6200, p_1845); hr_fs(_o6200, hr_str("->n]; })", 8)); }));
return;
 }
if (((b_1840) == (((int64_t)23LL)))) { (void)(({ hrv *_o6201 = &(g163); hr_fs(_o6201, hr_str("int64_t _k", 10)); hr_fi(_o6201, p_1845); hr_fs(_o6201, hr_str(" = ", 3)); }));
(void)(f291_gx(f323_arg(((int64_t)1LL), &recv_1842, &n_1838)));
(void)(({ hrv *_o6204 = &(g163); hr_fs(_o6204, hr_str("; if (_k", 8)); hr_fi(_o6204, p_1845); hr_fs(_o6204, hr_str(" < 0 || _k", 10)); hr_fi(_o6204, p_1845); hr_fs(_o6204, hr_str(" > _v", 5)); hr_fi(_o6204, p_1845); hr_fs(_o6204, hr_str("->n) hr_die(\"pop_n past the length\", ", 37)); }));
(void)(f314_wloc(n_1838));
(void)(({ hrv *_o6206 = &(g163); hr_fs(_o6206, hr_str("); _v", 5)); hr_fi(_o6206, p_1845); hr_fs(_o6206, hr_str("->n -= _k", 9)); hr_fi(_o6206, p_1845); hr_fs(_o6206, hr_str("; })", 4)); }));
return;
 }
if (((b_1840) == (((int64_t)25LL)))) { (void)(({ hrv *_o6207 = &(g163); hr_fs(_o6207, hr_str("_v", 2)); hr_fi(_o6207, p_1845); hr_fs(_o6207, hr_str("->n = 0; })", 11)); }));
return;
 }
if (((b_1840) == (((int64_t)24LL)))) { (void)(({ hrv *_o6208 = &(g163); hr_fs(_o6208, hr_str("int64_t _k", 10)); hr_fi(_o6208, p_1845); hr_fs(_o6208, hr_str(" = ", 3)); }));
(void)(f291_gx(f323_arg(((int64_t)1LL), &recv_1842, &n_1838)));
(void)(({ hrv *_o6211 = &(g163); hr_fs(_o6211, hr_str("; if (_k", 8)); hr_fi(_o6211, p_1845); hr_fs(_o6211, hr_str(" < 0 || _k", 10)); hr_fi(_o6211, p_1845); hr_fs(_o6211, hr_str(" > ", 3)); hr_fi(_o6211, ((*({ hrv *_t6212 = &(g554); int64_t _i6212 = rt_1897; (S1*)_t6212->b + hr_ix(_i6212, _t6212->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:691"); }))).b_); hr_fs(_o6211, hr_str(") hr_die(\"resize past a limited array's capacity\", ", 51)); }));
(void)(f314_wloc(n_1838));
(void)(({ hrv *_o6214 = &(g163); hr_fs(_o6214, hr_str("); for (int64_t _j = _v", 23)); hr_fi(_o6214, p_1845); hr_fs(_o6214, hr_str("->n; _j < _k", 12)); hr_fi(_o6214, p_1845); hr_fs(_o6214, hr_str("; _j++) memset(&_v", 18)); hr_fi(_o6214, p_1845); hr_fs(_o6214, hr_str("->e[_j], 0, sizeof _v", 21)); hr_fi(_o6214, p_1845); hr_fs(_o6214, hr_str("->e[0]); ", 9)); }));
if (((total_1843) > (((int64_t)2LL)))) { (void)(({ hrv *_o6215 = &(g163); hr_fs(_o6215, hr_str("for (int64_t _j = _v", 20)); hr_fi(_o6215, p_1845); hr_fs(_o6215, hr_str("->n; _j < _k", 12)); hr_fi(_o6215, p_1845); hr_fs(_o6215, hr_str("; _j++) _v", 10)); hr_fi(_o6215, p_1845); hr_fs(_o6215, hr_str("->e[_j] = ", 10)); }));
(void)(f291_gx(f323_arg(((int64_t)2LL), &recv_1842, &n_1838)));
(void)(f262_ow(hr_str("; ", 2)));
 }
(void)(({ hrv *_o6219 = &(g163); hr_fs(_o6219, hr_str("_v", 2)); hr_fi(_o6219, p_1845); hr_fs(_o6219, hr_str("->n = _k", 8)); hr_fi(_o6219, p_1845); hr_fs(_o6219, hr_str("; })", 4)); }));
return;
 }
if (((b_1840) == (((int64_t)26LL)))) { (void)(f263_ct(e_1898));
(void)(f262_ow(hr_str(" _x", 3)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(f323_arg(((int64_t)1LL), &recv_1842, &n_1838)));
(void)(({ hrv *_o6226 = &(g163); hr_fs(_o6226, hr_str("; int64_t _r", 12)); hr_fi(_o6226, p_1845); hr_fs(_o6226, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6226, p_1845); hr_fs(_o6226, hr_str("->n; _j++) if (", 15)); }));
(void)(f330_heq_val_o(e_1898, p_1845));
(void)(({ hrv *_o6228 = &(g163); hr_fs(_o6228, hr_str(") { _r", 6)); hr_fi(_o6228, p_1845); hr_fs(_o6228, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6228, p_1845); hr_fs(_o6228, hr_str("; })", 4)); }));
return;
 }
(void)(f289_gerr(n_1838, hr_str("unsupported limited-array operation", 35)));
return;
 }
if ((((((*({ hrv *_t6230 = &(g554); int64_t _i6230 = rt_1897; (S1*)_t6230->b + hr_ix(_i6230, _t6230->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:695"); }))).k_) == (((uint8_t)9LL))) || f284_is_fix(rt_1897))) { if (((b_1840) == (((int64_t)26LL)))) { (void)(f262_ow(hr_str("({ hsl _v", 9)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f293_gas(recv_1842));
(void)(f262_ow(hr_str("; ", 2)));
(void)(f263_ct(e_1898));
(void)(f262_ow(hr_str(" _x", 3)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(f323_arg(((int64_t)1LL), &recv_1842, &n_1838)));
(void)(({ hrv *_o6243 = &(g163); hr_fs(_o6243, hr_str("; int64_t _r", 12)); hr_fi(_o6243, p_1845); hr_fs(_o6243, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6243, p_1845); hr_fs(_o6243, hr_str(".n; _j++) if (", 14)); }));
(void)(f334_heq_val_s(e_1898, p_1845));
(void)(({ hrv *_o6245 = &(g163); hr_fs(_o6245, hr_str(") { _r", 6)); hr_fi(_o6245, p_1845); hr_fs(_o6245, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6245, p_1845); hr_fs(_o6245, hr_str("; })", 4)); }));
return;
 }
(void)(f289_gerr(n_1838, hr_str("this operation needs a resizable array", 38)));
return;
 }
(void)(f262_ow(hr_str("({ hrv *_v", 10)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f327_grecv_ptr(recv_1842));
(void)(f262_ow(hr_str("; ", 2)));
if (((b_1840) == (((int64_t)20LL)))) { (void)(f263_ct(e_1898));
(void)(f262_ow(hr_str(" _x", 3)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(f323_arg(((int64_t)1LL), &recv_1842, &n_1838)));
(void)(f262_ow(hr_str("; ", 2)));
(void)(f263_ct(e_1898));
(void)(f262_ow(hr_str(" *_p", 4)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" = (", 4)));
(void)(f263_ct(e_1898));
(void)(({ hrv *_o6264 = &(g163); hr_fs(_o6264, hr_str("*)hr_grow(_v", 12)); hr_fi(_o6264, p_1845); hr_fs(_o6264, hr_str(", 1, sizeof _x", 14)); hr_fi(_o6264, p_1845); hr_fs(_o6264, hr_str("); *_p", 6)); hr_fi(_o6264, p_1845); hr_fs(_o6264, hr_str(" = _x", 5)); hr_fi(_o6264, p_1845); hr_fs(_o6264, hr_str("; _p", 4)); hr_fi(_o6264, p_1845); hr_fs(_o6264, hr_str("; })", 4)); }));
return;
 }
if (((b_1840) == (((int64_t)21LL)))) { (void)(({ hrv *_o6265 = &(g163); hr_fs(_o6265, hr_str("hsl _s", 6)); hr_fi(_o6265, p_1845); hr_fs(_o6265, hr_str(" = ", 3)); }));
(void)(f293_gas(f323_arg(((int64_t)1LL), &recv_1842, &n_1838)));
(void)(({ hrv *_o6268 = &(g163); hr_fs(_o6268, hr_str("; hr_append(_v", 14)); hr_fi(_o6268, p_1845); hr_fs(_o6268, hr_str(", _s", 4)); hr_fi(_o6268, p_1845); hr_fs(_o6268, hr_str(".p, _s", 6)); hr_fi(_o6268, p_1845); hr_fs(_o6268, hr_str(".n, sizeof(", 11)); }));
(void)(f263_ct(e_1898));
(void)(f262_ow(hr_str(")); })", 6)));
return;
 }
if (((b_1840) == (((int64_t)22LL)))) { (void)(({ hrv *_o6271 = &(g163); hr_fs(_o6271, hr_str("if (!_v", 7)); hr_fi(_o6271, p_1845); hr_fs(_o6271, hr_str("->n) hr_die(\"pop of an empty array\", ", 37)); }));
(void)(f314_wloc(n_1838));
(void)(({ hrv *_o6273 = &(g163); hr_fs(_o6273, hr_str("); ((", 5)); }));
(void)(f263_ct(e_1898));
(void)(({ hrv *_o6275 = &(g163); hr_fs(_o6275, hr_str("*)_v", 4)); hr_fi(_o6275, p_1845); hr_fs(_o6275, hr_str("->b)[--_v", 9)); hr_fi(_o6275, p_1845); hr_fs(_o6275, hr_str("->n]; })", 8)); }));
return;
 }
if (((b_1840) == (((int64_t)23LL)))) { (void)(({ hrv *_o6276 = &(g163); hr_fs(_o6276, hr_str("int64_t _k", 10)); hr_fi(_o6276, p_1845); hr_fs(_o6276, hr_str(" = ", 3)); }));
(void)(f291_gx(f323_arg(((int64_t)1LL), &recv_1842, &n_1838)));
(void)(({ hrv *_o6279 = &(g163); hr_fs(_o6279, hr_str("; if (_k", 8)); hr_fi(_o6279, p_1845); hr_fs(_o6279, hr_str(" < 0 || _k", 10)); hr_fi(_o6279, p_1845); hr_fs(_o6279, hr_str(" > _v", 5)); hr_fi(_o6279, p_1845); hr_fs(_o6279, hr_str("->n) hr_die(\"pop_n past the length\", ", 37)); }));
(void)(f314_wloc(n_1838));
(void)(({ hrv *_o6281 = &(g163); hr_fs(_o6281, hr_str("); _v", 5)); hr_fi(_o6281, p_1845); hr_fs(_o6281, hr_str("->n -= _k", 9)); hr_fi(_o6281, p_1845); hr_fs(_o6281, hr_str("; })", 4)); }));
return;
 }
if (((b_1840) == (((int64_t)25LL)))) { (void)(({ hrv *_o6282 = &(g163); hr_fs(_o6282, hr_str("_v", 2)); hr_fi(_o6282, p_1845); hr_fs(_o6282, hr_str("->n = 0; })", 11)); }));
return;
 }
if (((b_1840) == (((int64_t)24LL)))) { (void)(({ hrv *_o6283 = &(g163); hr_fs(_o6283, hr_str("int64_t _k", 10)); hr_fi(_o6283, p_1845); hr_fs(_o6283, hr_str(" = ", 3)); }));
(void)(f291_gx(f323_arg(((int64_t)1LL), &recv_1842, &n_1838)));
(void)(({ hrv *_o6286 = &(g163); hr_fs(_o6286, hr_str("; if (_k", 8)); hr_fi(_o6286, p_1845); hr_fs(_o6286, hr_str(" < 0) hr_die(\"resize to a negative length\", ", 44)); }));
(void)(f314_wloc(n_1838));
(void)(f262_ow(hr_str("); ", 3)));
if (((total_1843) > (((int64_t)2LL)))) { (void)(f263_ct(e_1898));
(void)(f262_ow(hr_str(" _x", 3)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(f323_arg(((int64_t)2LL), &recv_1842, &n_1838)));
(void)(({ hrv *_o6295 = &(g163); hr_fs(_o6295, hr_str("; int64_t _o", 12)); hr_fi(_o6295, p_1845); hr_fs(_o6295, hr_str(" = _v", 5)); hr_fi(_o6295, p_1845); hr_fs(_o6295, hr_str("->n; hr_resize(_v", 17)); hr_fi(_o6295, p_1845); hr_fs(_o6295, hr_str(", _k", 4)); hr_fi(_o6295, p_1845); hr_fs(_o6295, hr_str(", sizeof _x", 11)); hr_fi(_o6295, p_1845); hr_fs(_o6295, hr_str("); for (int64_t _j = _o", 23)); hr_fi(_o6295, p_1845); hr_fs(_o6295, hr_str("; _j < _k", 9)); hr_fi(_o6295, p_1845); hr_fs(_o6295, hr_str("; _j++) ((", 10)); }));
(void)(f263_ct(e_1898));
(void)(({ hrv *_o6297 = &(g163); hr_fs(_o6297, hr_str("*)_v", 4)); hr_fi(_o6297, p_1845); hr_fs(_o6297, hr_str("->b)[_j] = _x", 13)); hr_fi(_o6297, p_1845); hr_fs(_o6297, hr_str("; })", 4)); }));
return;
 }
(void)(({ hrv *_o6298 = &(g163); hr_fs(_o6298, hr_str("hr_resize(_v", 12)); hr_fi(_o6298, p_1845); hr_fs(_o6298, hr_str(", _k", 4)); hr_fi(_o6298, p_1845); hr_fs(_o6298, hr_str(", sizeof(", 9)); }));
(void)(f263_ct(e_1898));
(void)(f262_ow(hr_str(")); })", 6)));
return;
 }
if (((b_1840) == (((int64_t)26LL)))) { (void)(f263_ct(e_1898));
(void)(f262_ow(hr_str(" _x", 3)));
(void)(f296_oi(p_1845));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(f323_arg(((int64_t)1LL), &recv_1842, &n_1838)));
(void)(({ hrv *_o6307 = &(g163); hr_fs(_o6307, hr_str("; int64_t _r", 12)); hr_fi(_o6307, p_1845); hr_fs(_o6307, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6307, p_1845); hr_fs(_o6307, hr_str("->n; _j++) if (", 15)); }));
(void)(f335_heq_val_r(e_1898, p_1845));
(void)(({ hrv *_o6309 = &(g163); hr_fs(_o6309, hr_str(") { _r", 6)); hr_fi(_o6309, p_1845); hr_fs(_o6309, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6309, p_1845); hr_fs(_o6309, hr_str("; })", 4)); }));
return;
 }
(void)(f289_gerr(n_1838, hr_str("unsupported array operation", 27)));
}
static int64_t f323_arg(int64_t i_1844, int64_t *c1842, int64_t *c1838) {
return ({ int64_t _r6311; if ((((*c1842)) >= (((int64_t)0LL)))) { _r6311 = ({ int64_t _r6312; if (((i_1844) == (((int64_t)0LL)))) { _r6312 = (*c1842);  } else { _r6312 = f90_kid((*c1838), ((int64_t)((int64_t)i_1844 - (int64_t)((int64_t)1LL))));  } _r6312; });  } else { _r6311 = f90_kid((*c1838), i_1844);  } _r6311; });
}
static void f324_gfmt(hsl o_1848, int64_t n_1849, int64_t t_1850, bool top_1851) {
int64_t d_1852 = f182_deref(t_1850); 
int64_t k_1853 = ((int64_t)(((*({ hrv *_t6316 = &(g554); int64_t _i6316 = d_1852; (S1*)_t6316->b + hr_ix(_i6316, _t6316->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:375"); }))).k_)); 
int64_t hk_1854 = ({ int64_t _r6317; if (((d_1852) < ((g350).n))) { _r6317 = ((int64_t)((*({ hrv *_t6318 = &(g350); int64_t _i6318 = d_1852; (int32_t*)_t6318->b + hr_ix(_i6318, _t6318->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:376"); }))));  } else { _r6317 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r6317; }); 
if ((((hk_1854) >= (((int64_t)0LL))) && ((f182_deref(f212_ptype_of(hk_1854, ((int64_t)1LL)))) == (d_1852)))) { int64_t pt_1855 = f212_ptype_of(hk_1854, ((int64_t)1LL)); 
(void)(f325_fn_cname(hk_1854));
(void)(f262_ow(hr_str("(", 1)));
(void)(f262_ow(o_1848));
(void)(f262_ow(hr_str(", ", 2)));
if (((((*({ hrv *_t6326 = &(g554); int64_t _i6326 = pt_1855; (S1*)_t6326->b + hr_ix(_i6326, _t6326->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:380"); }))).k_) == (((uint8_t)10LL)))) { if (((((*({ hrv *_t6327 = &(g554); int64_t _i6327 = t_1850; (S1*)_t6327->b + hr_ix(_i6327, _t6327->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:380"); }))).k_) == (((uint8_t)10LL)))) { (void)(f291_gx(n_1849));
 } else { (void)(f326_gaddr(n_1849));
 }
 } else { if (((((*({ hrv *_t6330 = &(g554); int64_t _i6330 = t_1850; (S1*)_t6330->b + hr_ix(_i6330, _t6330->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:380"); }))).k_) == (((uint8_t)10LL)))) { (void)(f262_ow(hr_str("*", 1)));
 }
(void)(f291_gx(n_1849));
 }
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if ((((k_1853) == (((int64_t)18LL))) || f167_is_byte_arr(d_1852))) { if (top_1851) { (void)(f262_ow(hr_str("hr_fs(", 6)));
 } else { (void)(f262_ow(hr_str("hr_fq(", 6)));
 }
(void)(f262_ow(o_1848));
(void)(f262_ow(hr_str(", ", 2)));
if (((((*({ hrv *_t6339 = &(g554); int64_t _i6339 = f141_at(n_1849); (S1*)_t6339->b + hr_ix(_i6339, _t6339->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:384"); }))).k_) == (((uint8_t)18LL)))) { (void)(f291_gx(n_1849));
 } else { (void)(f293_gas(n_1849));
 }
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if (((k_1853) == (((int64_t)3LL)))) { (void)(f262_ow(({ hsl _r6345; if (f156_is_signed(d_1852)) { _r6345 = hr_str("hr_fi(", 6);  } else { _r6345 = hr_str("hr_fu(", 6);  } _r6345; })));
(void)(f262_ow(o_1848));
(void)(f262_ow(hr_str(", ", 2)));
if (((d_1852) != (t_1850))) { (void)(f262_ow(hr_str("*", 1)));
 }
(void)(f291_gx(n_1849));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if (((k_1853) == (((int64_t)12LL)))) { (void)(f262_ow(hr_str("hr_fi(", 6)));
(void)(f262_ow(o_1848));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f291_gx(n_1849));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if (((k_1853) == (((int64_t)4LL)))) { (void)(f262_ow(({ hsl _r6358; if (((((*({ hrv *_t6359 = &(g554); int64_t _i6359 = d_1852; (S1*)_t6359->b + hr_ix(_i6359, _t6359->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:387"); }))).s_) == (((uint8_t)4LL)))) { _r6358 = hr_str("hr_ff(", 6);  } else { _r6358 = hr_str("hr_fd(", 6);  } _r6358; })));
(void)(f262_ow(o_1848));
(void)(f262_ow(hr_str(", ", 2)));
if (((d_1852) != (t_1850))) { (void)(f262_ow(hr_str("*", 1)));
 }
(void)(f291_gx(n_1849));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if (((k_1853) == (((int64_t)13LL)))) { (void)(f262_ow(hr_str("hr_fd(", 6)));
(void)(f262_ow(o_1848));
(void)(f262_ow(hr_str(", ", 2)));
(void)(f291_gx(n_1849));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
if (((k_1853) == (((int64_t)2LL)))) { (void)(f262_ow(hr_str("hr_fc(", 6)));
(void)(f262_ow(o_1848));
(void)(f262_ow(hr_str(", (", 3)));
if (((d_1852) != (t_1850))) { (void)(f262_ow(hr_str("*", 1)));
 }
(void)(f291_gx(n_1849));
(void)(f262_ow(hr_str(") \077 \"true\" : \"false\")", 21)));
return;
 }
(void)(f262_ow(hr_str("hf", 2)));
(void)(f296_oi(d_1852));
(void)(f262_ow(hr_str("(", 1)));
(void)(f262_ow(o_1848));
(void)(f262_ow(hr_str(", ", 2)));
if (((d_1852) != (t_1850))) { (void)(f262_ow(hr_str("*", 1)));
 }
if ((((((k_1853) == (((int64_t)8LL))) && (!(f284_is_fix(d_1852)))) && (!(f285_is_lim(d_1852)))) || ((k_1853) == (((int64_t)9LL))))) { (void)(f294_gsl(n_1849, t_1850));
 } else { (void)(f291_gx(n_1849));
 }
(void)(f262_ow(hr_str(")", 1)));
(void)(f301_gen_hf(d_1852));
}
static void f325_fn_cname(int64_t i_1856) {
(void)(f304_fn_cname_to((&(g163)), i_1856));
}
static void f326_gaddr(int64_t n_1857) {
if (f274_is_place(n_1857)) { (void)(f262_ow(hr_str("(&(", 3)));
(void)(f277_gx0(n_1857));
(void)(f262_ow(hr_str("))", 2)));
return;
 }
int64_t t_1858 = f141_at(n_1857); 
int64_t c_1859 = f153_cv(n_1857); 
if (((((c_1859) >= (((int64_t)0LL))) && ((((*({ hrv *_t6395 = &(g554); int64_t _i6395 = c_1859; (S1*)_t6395->b + hr_ix(_i6395, _t6395->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:167"); }))).k_) == (((uint8_t)10LL)))) && ((((*({ hrv *_t6396 = &(g554); int64_t _i6396 = t_1858; (S1*)_t6396->b + hr_ix(_i6396, _t6396->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:167"); }))).k_) != (((uint8_t)10LL))))) { int64_t pt_1860 = ((int64_t)(((*({ hrv *_t6397 = &(g554); int64_t _i6397 = c_1859; (S1*)_t6397->b + hr_ix(_i6397, _t6397->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:168"); }))).a_)); 
int64_t k_1861 = f275_tmp(pt_1860, f270_is_res(pt_1860)); 
(void)(f262_ow(hr_str("(", 1)));
(void)(f276_ot(k_1861));
(void)(f262_ow(hr_str(" = (", 4)));
if (((pt_1860) == (t_1858))) { if (f270_is_res(t_1858)) { (void)(f277_gx0(n_1857));
 } else { (void)(f273_gx1(n_1857));
 }
 } else { (void)(f272_gcv(n_1857, t_1858, pt_1860));
 }
(void)(f262_ow(hr_str("), &", 4)));
(void)(f276_ot(k_1861));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
int64_t k_1862 = f275_tmp(t_1858, f270_is_res(t_1858)); 
(void)(f262_ow(hr_str("(", 1)));
(void)(f276_ot(k_1862));
(void)(f262_ow(hr_str(" = (", 4)));
(void)(f271_gxo(n_1857));
(void)(f262_ow(hr_str("), &", 4)));
(void)(f276_ot(k_1862));
(void)(f262_ow(hr_str(")", 1)));
}
static void f327_grecv_ptr(int64_t r_1867) {
int64_t t_1868 = f141_at(r_1867); 
if (((((*({ hrv *_t6420 = &(g554); int64_t _i6420 = t_1868; (S1*)_t6420->b + hr_ix(_i6420, _t6420->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:648"); }))).k_) == (((uint8_t)10LL)))) { (void)(f277_gx0(r_1867));
return;
 }
if (f274_is_place(r_1867)) { (void)(f262_ow(hr_str("&(", 2)));
(void)(f277_gx0(r_1867));
(void)(f262_ow(hr_str(")", 1)));
return;
 }
int64_t k_1869 = f275_tmp(t_1868, f270_is_res(t_1868)); 
(void)(f262_ow(hr_str("(", 1)));
(void)(f276_ot(k_1869));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f271_gxo(r_1867));
(void)(f262_ow(hr_str(", &", 3)));
(void)(f276_ot(k_1869));
(void)(f262_ow(hr_str(")", 1)));
}
static void f328_esz(int64_t t_1881) {
(void)(f262_ow(hr_str("sizeof(", 7)));
(void)(f263_ct(t_1881));
(void)(f262_ow(hr_str(")", 1)));
}
static void f329_gembed(int64_t n_1888, int64_t a_1889) {
if (((((*({ hrv *_t6438 = &(g707); int64_t _i6438 = a_1889; (S4*)_t6438->b + hr_ix(_i6438, _t6438->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:714"); }))).k_) != (((uint8_t)3LL)))) { (void)(f289_gerr(n_1888, hr_str("embed_file needs a string literal path", 38)));
return;
 }
int64_t f_1890 = ((int64_t)(((*({ hrv *_t6440 = &(g916); int64_t _i6440 = ((*({ hrv *_t6441 = &(g917); int64_t _i6441 = ((*({ hrv *_t6442 = &(g707); int64_t _i6442 = n_1888; (S4*)_t6442->b + hr_ix(_i6442, _t6442->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:715"); }))).t_; (S3*)_t6441->b + hr_ix(_i6441, _t6441->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:715"); }))).f_; (S2*)_t6440->b + hr_ix(_i6440, _t6440->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:715"); }))).name_)); 
L101 p_1891 = ({ L101 _t6443; memset(&_t6443, 0, sizeof _t6443); _t6443.n = 0; _t6443; }); 
int64_t sl_1892 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hsl _v6445 = f10_nm(f_1890); for (int64_t _k6445 = 0; _k6445 < _v6445.n; _k6445++) { uint8_t c_1893 = ((uint8_t*)_v6445.p)[_k6445]; int64_t i_1894 = (int64_t)_k6445; if (((c_1893) == (((uint8_t)47LL)))) { sl_1892 = i_1894;
 }
 } } _bk6444:; 
if (((sl_1892) >= (((int64_t)0LL)))) { (void)(({ L101 *_v6447 = &(p_1891); hsl _s6447 = ({ hsl _t6448 = f10_nm(f_1890); int64_t _l6448 = 0, _h6448 = ((int64_t)((int64_t)sl_1892 + (int64_t)((int64_t)1LL))); if (_l6448 < 0 || _h6448 < _l6448 || _h6448 > _t6448.n) hr_slerr(_l6448, _h6448, _t6448.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:719"); (hsl){ _t6448.p + _l6448 * (int64_t)sizeof(uint8_t), _h6448 - _l6448 }; }); if (_v6447->n + _s6447.n > 4096) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:719"); memmove(_v6447->e + _v6447->n, _s6447.p, (size_t)_s6447.n * sizeof _v6447->e[0]); _v6447->n += _s6447.n; }));
 }
(void)(({ L101 *_v6450 = &(p_1891); hsl _s6450 = f282_tok_str(((int64_t)(((*({ hrv *_t6452 = &(g707); int64_t _i6452 = a_1889; (S4*)_t6452->b + hr_ix(_i6452, _t6452->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:720"); }))).t_))); if (_v6450->n + _s6450.n > 4096) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:720"); memmove(_v6450->e + _v6450->n, _s6450.p, (size_t)_s6450.n * sizeof _v6450->e[0]); _v6450->n += _s6450.n; }));
hrv emb_1895 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(hr_os_read_file(({ hsl _t6455 = ({ L101 *_t6456 = &(p_1891); (hsl){ (uint8_t*)_t6456->e, _t6456->n }; }); int64_t _l6455 = 0, _h6455 = _t6455.n; if (_l6455 < 0 || _h6455 < _l6455 || _h6455 > _t6455.n) hr_slerr(_l6455, _h6455, _t6455.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:722"); (hsl){ _t6455.p + _l6455 * (int64_t)sizeof(uint8_t), _h6455 - _l6455 }; }), (&(emb_1895)))))) { (void)(f289_gerr(n_1888, hr_str("embed_file cannot read its file", 31)));
return;
 }
(void)(f262_ow(hr_str("hr_str(", 7)));
(void)(f283_cstr_lit(({ hsl _t6460 = hr_sl(emb_1895); int64_t _l6460 = 0, _h6460 = _t6460.n; if (_l6460 < 0 || _h6460 < _l6460 || _h6460 > _t6460.n) hr_slerr(_l6460, _h6460, _t6460.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:723"); (hsl){ _t6460.p + _l6460 * (int64_t)sizeof(uint8_t), _h6460 - _l6460 }; })));
(void)(({ hrv *_o6461 = &(g163); hr_fs(_o6461, hr_str(", ", 2)); hr_fi(_o6461, (emb_1895).n); hr_fs(_o6461, hr_str(")", 1)); }));
}
static void f330_heq_val_o(int64_t e_1899, int64_t p_1900) {
L100 a_1901 = ({ L100 _t6462; memset(&_t6462, 0, sizeof _t6462); _t6462.n = 0; _t6462; }); 
L100 b_1902 = ({ L100 _t6463; memset(&_t6463, 0, sizeof _t6463); _t6463.n = 0; _t6463; }); 
(void)(({ L100 *_l6464 = &(a_1901); hrv _o6464 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6464, hr_str("_v", 2)); hr_fi(&_o6464, p_1900); hr_fs(&_o6464, hr_str("->e[_j]", 7)); if (_l6464->n + _o6464.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:728"); memcpy(_l6464->e + _l6464->n, _o6464.b, (size_t)_o6464.n); _l6464->n += _o6464.n; }));
(void)(({ L100 *_l6465 = &(b_1902); hrv _o6465 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6465, hr_str("_x", 2)); hr_fi(&_o6465, p_1900); if (_l6465->n + _o6465.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:728"); memcpy(_l6465->e + _l6465->n, _o6465.b, (size_t)_o6465.n); _l6465->n += _o6465.n; }));
(void)(f331_heq_o(e_1899, ({ hsl _t6467 = ({ L100 *_t6468 = &(a_1901); (hsl){ (uint8_t*)_t6468->e, _t6468->n }; }); int64_t _l6467 = 0, _h6467 = _t6467.n; if (_l6467 < 0 || _h6467 < _l6467 || _h6467 > _t6467.n) hr_slerr(_l6467, _h6467, _t6467.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:728"); (hsl){ _t6467.p + _l6467 * (int64_t)sizeof(uint8_t), _h6467 - _l6467 }; }), ({ hsl _t6469 = ({ L100 *_t6470 = &(b_1902); (hsl){ (uint8_t*)_t6470->e, _t6470->n }; }); int64_t _l6469 = 0, _h6469 = _t6469.n; if (_l6469 < 0 || _h6469 < _l6469 || _h6469 > _t6469.n) hr_slerr(_l6469, _h6469, _t6469.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:728"); (hsl){ _t6469.p + _l6469 * (int64_t)sizeof(uint8_t), _h6469 - _l6469 }; })));
}
static void f331_heq_o(int64_t e_1903, hsl a_1904, hsl b_1905) {
(void)(f332_heq_pre(e_1903));
int64_t s0_1909 = (g169).n; 
(void)(f306_heq_val(e_1903, a_1904, b_1905));
(void)(({ hrv *_v6473 = &(g163); hsl _s6473 = ({ hsl _t6474 = hr_sl(g169); int64_t _l6474 = s0_1909, _h6474 = _t6474.n; if (_l6474 < 0 || _h6474 < _l6474 || _h6474 > _t6474.n) hr_slerr(_l6474, _h6474, _t6474.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:725"); (hsl){ _t6474.p + _l6474 * (int64_t)sizeof(uint8_t), _h6474 - _l6474 }; }); hr_append(_v6473, _s6473.p, _s6473.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6475 = &(g169); int64_t _k6475 = s0_1909; if (_k6475 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:725"); hr_resize(_v6475, _k6475, sizeof(uint8_t)); }));
}
static void f332_heq_pre(int64_t t_1906) {
if ((!(f333_scalar_ty(t_1906)))) { (void)(f297_gen_heq(t_1906));
 }
}
static bool f333_scalar_ty(int64_t t_1907) {
int64_t k_1908 = ((int64_t)(((*({ hrv *_t6478 = &(g554); int64_t _i6478 = t_1907; (S1*)_t6478->b + hr_ix(_i6478, _t6478->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:726"); }))).k_)); 
return (((((k_1908) == (((int64_t)3LL))) || ((k_1908) == (((int64_t)4LL)))) || ((k_1908) == (((int64_t)2LL)))) || ((k_1908) == (((int64_t)10LL))));
}
static void f334_heq_val_s(int64_t e_1910, int64_t p_1911) {
L98 a_1912 = ({ L98 _t6479; memset(&_t6479, 0, sizeof _t6479); _t6479.n = 0; _t6479; }); 
L100 b_1913 = ({ L100 _t6480; memset(&_t6480, 0, sizeof _t6480); _t6480.n = 0; _t6480; }); 
(void)(({ L98 *_v6481 = &(a_1912); hsl _s6481 = hr_str("((", 2); if (_v6481->n + _s6481.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:729"); memmove(_v6481->e + _v6481->n, _s6481.p, (size_t)_s6481.n * sizeof _v6481->e[0]); _v6481->n += _s6481.n; }));
(void)(({ L98 *_v6482 = &(a_1912); hsl _s6482 = f266_cn(e_1910); if (_v6482->n + _s6482.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:729"); memmove(_v6482->e + _v6482->n, _s6482.p, (size_t)_s6482.n * sizeof _v6482->e[0]); _v6482->n += _s6482.n; }));
(void)(({ L98 *_l6484 = &(a_1912); hrv _o6484 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6484, hr_str("*)_v", 4)); hr_fi(&_o6484, p_1911); hr_fs(&_o6484, hr_str(".p)[_j]", 7)); if (_l6484->n + _o6484.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:729"); memcpy(_l6484->e + _l6484->n, _o6484.b, (size_t)_o6484.n); _l6484->n += _o6484.n; }));
(void)(({ L100 *_l6485 = &(b_1913); hrv _o6485 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6485, hr_str("_x", 2)); hr_fi(&_o6485, p_1911); if (_l6485->n + _o6485.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:729"); memcpy(_l6485->e + _l6485->n, _o6485.b, (size_t)_o6485.n); _l6485->n += _o6485.n; }));
(void)(f331_heq_o(e_1910, ({ hsl _t6487 = ({ L98 *_t6488 = &(a_1912); (hsl){ (uint8_t*)_t6488->e, _t6488->n }; }); int64_t _l6487 = 0, _h6487 = _t6487.n; if (_l6487 < 0 || _h6487 < _l6487 || _h6487 > _t6487.n) hr_slerr(_l6487, _h6487, _t6487.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:729"); (hsl){ _t6487.p + _l6487 * (int64_t)sizeof(uint8_t), _h6487 - _l6487 }; }), ({ hsl _t6489 = ({ L100 *_t6490 = &(b_1913); (hsl){ (uint8_t*)_t6490->e, _t6490->n }; }); int64_t _l6489 = 0, _h6489 = _t6489.n; if (_l6489 < 0 || _h6489 < _l6489 || _h6489 > _t6489.n) hr_slerr(_l6489, _h6489, _t6489.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:729"); (hsl){ _t6489.p + _l6489 * (int64_t)sizeof(uint8_t), _h6489 - _l6489 }; })));
}
static void f335_heq_val_r(int64_t e_1914, int64_t p_1915) {
L98 a_1916 = ({ L98 _t6491; memset(&_t6491, 0, sizeof _t6491); _t6491.n = 0; _t6491; }); 
L100 b_1917 = ({ L100 _t6492; memset(&_t6492, 0, sizeof _t6492); _t6492.n = 0; _t6492; }); 
(void)(({ L98 *_v6493 = &(a_1916); hsl _s6493 = hr_str("((", 2); if (_v6493->n + _s6493.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:730"); memmove(_v6493->e + _v6493->n, _s6493.p, (size_t)_s6493.n * sizeof _v6493->e[0]); _v6493->n += _s6493.n; }));
(void)(({ L98 *_v6494 = &(a_1916); hsl _s6494 = f266_cn(e_1914); if (_v6494->n + _s6494.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:730"); memmove(_v6494->e + _v6494->n, _s6494.p, (size_t)_s6494.n * sizeof _v6494->e[0]); _v6494->n += _s6494.n; }));
(void)(({ L98 *_l6496 = &(a_1916); hrv _o6496 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6496, hr_str("*)_v", 4)); hr_fi(&_o6496, p_1915); hr_fs(&_o6496, hr_str("->b)[_j]", 8)); if (_l6496->n + _o6496.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:730"); memcpy(_l6496->e + _l6496->n, _o6496.b, (size_t)_o6496.n); _l6496->n += _o6496.n; }));
(void)(({ L100 *_l6497 = &(b_1917); hrv _o6497 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6497, hr_str("_x", 2)); hr_fi(&_o6497, p_1915); if (_l6497->n + _o6497.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:730"); memcpy(_l6497->e + _l6497->n, _o6497.b, (size_t)_o6497.n); _l6497->n += _o6497.n; }));
(void)(f331_heq_o(e_1914, ({ hsl _t6499 = ({ L98 *_t6500 = &(a_1916); (hsl){ (uint8_t*)_t6500->e, _t6500->n }; }); int64_t _l6499 = 0, _h6499 = _t6499.n; if (_l6499 < 0 || _h6499 < _l6499 || _h6499 > _t6499.n) hr_slerr(_l6499, _h6499, _t6499.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:730"); (hsl){ _t6499.p + _l6499 * (int64_t)sizeof(uint8_t), _h6499 - _l6499 }; }), ({ hsl _t6501 = ({ L100 *_t6502 = &(b_1917); (hsl){ (uint8_t*)_t6502->e, _t6502->n }; }); int64_t _l6501 = 0, _h6501 = _t6501.n; if (_l6501 < 0 || _h6501 < _l6501 || _h6501 > _t6501.n) hr_slerr(_l6501, _h6501, _t6501.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:730"); (hsl){ _t6501.p + _l6501 * (int64_t)sizeof(uint8_t), _h6501 - _l6501 }; })));
}
static void f336_gblkcall(int64_t n_1918) {
int64_t bi_1919 = f160_rv(n_1918); 
int64_t fv_1920 = ((int64_t)(((*({ hrv *_t6504 = &(g390); int64_t _i6504 = bi_1919; (S6*)_t6504->b + hr_ix(_i6504, _t6504->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:628"); }))).node_)); 
int64_t sa_1921 = g403; 
(void)(f262_ow(hr_str("({ ", 3)));
int64_t np_1922 = ((int64_t)(((*({ hrv *_t6506 = &(g707); int64_t _i6506 = fv_1920; (S4*)_t6506->b + hr_ix(_i6506, _t6506->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:631"); }))).n_)); 
int64_t na_1923 = ((int64_t)(((*({ hrv *_t6507 = &(g707); int64_t _i6507 = n_1918; (S4*)_t6507->b + hr_ix(_i6507, _t6507->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:632"); }))).n_)); 
if (((((uint16_t)((uint64_t)((*({ hrv *_t6508 = &(g707); int64_t _i6508 = fv_1920; (S4*)_t6508->b + hr_ix(_i6508, _t6508->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:633"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { int64_t _e6510 = np_1922; for (int64_t _k6510 = 0; _k6510 < _e6510; _k6510++) { int64_t j_1924 = (int64_t)_k6510; int64_t p_1925 = f90_kid(fv_1920, j_1924); 
g403 = bi_1919;
int64_t v_1926 = f160_rv(p_1925); 
g403 = sa_1921;
if (((j_1924) < (na_1923))) { (void)(f263_ct(((int64_t)(((*({ hrv *_t6514 = &(g391); int64_t _i6514 = v_1926; (S12*)_t6514->b + hr_ix(_i6514, _t6514->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:634"); }))).ty_))));
(void)(f262_ow(hr_str(" ", 1)));
(void)(f288_lv_name(v_1926));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(f90_kid(n_1918, j_1924)));
(void)(f262_ow(hr_str("; ", 2)));
 }
 } } _bk6509:; 
 } else { if (((na_1923) >= (((int64_t)1LL)))) { g403 = bi_1919;
int64_t v_1927 = f160_rv(fv_1920); 
g403 = sa_1921;
if (((v_1927) >= (((int64_t)0LL)))) { (void)(f263_ct(((int64_t)(((*({ hrv *_t6523 = &(g391); int64_t _i6523 = v_1927; (S12*)_t6523->b + hr_ix(_i6523, _t6523->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:636"); }))).ty_))));
(void)(f262_ow(hr_str(" ", 1)));
(void)(f288_lv_name(v_1927));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(f90_kid(n_1918, ((int64_t)0LL))));
(void)(f262_ow(hr_str("; ", 2)));
 } else { (void)(f262_ow(hr_str("(void)(", 7)));
(void)(f291_gx(f90_kid(n_1918, ((int64_t)0LL))));
(void)(f262_ow(hr_str("); ", 3)));
 }
 }
 }
g403 = bi_1919;
int64_t body_1928 = ((int64_t)(((*({ hrv *_t6534 = &(g707); int64_t _i6534 = fv_1920; (S4*)_t6534->b + hr_ix(_i6534, _t6534->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:639"); }))).a_)); 
{ int32_t _e6536 = ((*({ hrv *_t6537 = &(g707); int64_t _i6537 = body_1928; (S4*)_t6537->b + hr_ix(_i6537, _t6537->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:640"); }))).n_; for (int32_t _k6536 = 0; _k6536 < _e6536; _k6536++) { int32_t i_1929 = (int32_t)_k6536; (void)(f337_gstmt(f90_kid(body_1928, ((int64_t)(i_1929)))));
 } } _bk6535:; 
int64_t tl_2060 = ((int64_t)(((*({ hrv *_t6540 = &(g707); int64_t _i6540 = body_1928; (S4*)_t6540->b + hr_ix(_i6540, _t6540->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:641"); }))).a_)); 
if (((tl_2060) >= (((int64_t)0LL)))) { if ((((((int64_t)(((*({ hrv *_t6541 = &(g390); int64_t _i6541 = bi_1919; (S6*)_t6541->b + hr_ix(_i6541, _t6541->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:642"); }))).ret_))) != (g561)) && (!(f143_ends(tl_2060))))) { (void)(f291_gx(tl_2060));
(void)(f262_ow(hr_str("; ", 2)));
 } else { (void)(f337_gstmt(tl_2060));
 }
 }
g403 = sa_1921;
(void)(f262_ow(hr_str(" })", 3)));
}
static void f337_gstmt(int64_t n_1930) {
if (((n_1930) < (((int64_t)0LL)))) { return;
 }
int64_t sp_1931 = (g163).n; 
int64_t td_1932 = (g176).n; 
S4 x_1933 = (*({ hrv *_t6547 = &(g707); int64_t _i6547 = n_1930; (S4*)_t6547->b + hr_ix(_i6547, _t6547->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1046"); })); 
int64_t k_1934 = ((int64_t)((x_1933).k_)); 
bool decl_1935 = ((k_1934) == (((int64_t)33LL))); 
if (((k_1934) == (((int64_t)33LL)))) { (void)(f338_gvdecl(n_1930));
 } else { (void)(f340_gstmt1(n_1930));
 }
(void)(f262_ow(hr_str("\012", 1)));
if ((((g176).n) > (td_1932))) { (void)(({ hrv *_v6551 = &(g177); _v6551->n = 0; }));
(void)(({ hrv *_v6552 = &(g177); hsl _s6552 = ({ hsl _t6553 = hr_sl(g163); int64_t _l6553 = sp_1931, _h6553 = _t6553.n; if (_l6553 < 0 || _h6553 < _l6553 || _h6553 > _t6553.n) hr_slerr(_l6553, _h6553, _t6553.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1052"); (hsl){ _t6553.p + _l6553 * (int64_t)sizeof(uint8_t), _h6553 - _l6553 }; }); hr_append(_v6552, _s6552.p, _s6552.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6554 = &(g163); int64_t _k6554 = sp_1931; if (_k6554 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1052"); hr_resize(_v6554, _k6554, sizeof(uint8_t)); }));
if ((!(decl_1935))) { (void)(f262_ow(hr_str("{ ", 2)));
 }
(void)(({ hrv *_v6556 = &(g163); hsl _s6556 = ({ hsl _t6557 = hr_sl(g176); int64_t _l6557 = td_1932, _h6557 = _t6557.n; if (_l6557 < 0 || _h6557 < _l6557 || _h6557 > _t6557.n) hr_slerr(_l6557, _h6557, _t6557.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1054"); (hsl){ _t6557.p + _l6557 * (int64_t)sizeof(uint8_t), _h6557 - _l6557 }; }); hr_append(_v6556, _s6556.p, _s6556.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6558 = &(g176); int64_t _k6558 = td_1932; if (_k6558 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1054"); hr_resize(_v6558, _k6558, sizeof(uint8_t)); }));
(void)(({ hrv *_v6559 = &(g163); hsl _s6559 = ({ hsl _t6560 = hr_sl(g177); int64_t _l6560 = 0, _h6560 = _t6560.n; if (_l6560 < 0 || _h6560 < _l6560 || _h6560 > _t6560.n) hr_slerr(_l6560, _h6560, _t6560.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1055"); (hsl){ _t6560.p + _l6560 * (int64_t)sizeof(uint8_t), _h6560 - _l6560 }; }); hr_append(_v6559, _s6559.p, _s6559.n, sizeof(uint8_t)); }));
if ((!(decl_1935))) { (void)(f262_ow(hr_str("}\012", 2)));
 }
 }
}
static void f338_gvdecl(int64_t n_1936) {
S4 x_1937 = (*({ hrv *_t6562 = &(g707); int64_t _i6562 = n_1936; (S4*)_t6562->b + hr_ix(_i6562, _t6562->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:934"); })); 
if ((((x_1937).n_) > (((int32_t)1LL)))) { if (((f219_ax(n_1936)) == (((int64_t)1LL)))) { L89 ids_1938 = ({ L89 _t6564; memset(&_t6564, 0, sizeof _t6564); _t6564.n = 0; _t6564; }); 
{ int32_t _e6566 = (x_1937).n_; for (int32_t _k6566 = 0; _k6566 < _e6566; _k6566++) { int32_t i_1939 = (int32_t)_k6566; int64_t iv_1940 = f90_kid(((int64_t)((x_1937).b_)), ((int64_t)(i_1939))); 
int64_t p_1941 = f295_nt(); 
(void)(({ L89 *_v6569 = &(ids_1938); int32_t _x6569 = ((int32_t)(p_1941)); if (_v6569->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:938"); _v6569->e[_v6569->n] = _x6569; &_v6569->e[_v6569->n++]; }));
(void)(f263_ct(f281_fin(iv_1940)));
(void)(f262_ow(hr_str(" _t", 3)));
(void)(f296_oi(p_1941));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(iv_1940));
(void)(f262_ow(hr_str("; ", 2)));
 } } _bk6565:; 
int64_t v0_1942 = f160_rv(n_1936); 
{ int32_t _e6579 = (x_1937).n_; for (int32_t _k6579 = 0; _k6579 < _e6579; _k6579++) { int32_t i_1943 = (int32_t)_k6579; (void)(f339_decl_lv(((int64_t)((int64_t)v0_1942 + (int64_t)((int64_t)(i_1943))))));
(void)(({ hrv *_o6581 = &(g163); hr_fs(_o6581, hr_str(" = _t", 5)); hr_fi(_o6581, (*({ L89 *_t6582 = &(ids_1938); int64_t _i6582 = i_1943; _t6582->e + hr_ix(_i6582, _t6582->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:940"); }))); hr_fs(_o6581, hr_str("; ", 2)); }));
 } } _bk6578:; 
return;
 }
int64_t init_1946 = f90_kid(((int64_t)((x_1937).b_)), ((int64_t)0LL)); 
int64_t p_1947 = f295_nt(); 
(void)(f263_ct(f141_at(init_1946)));
(void)(f262_ow(hr_str(" _t", 3)));
(void)(f296_oi(p_1947));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(init_1946));
(void)(f262_ow(hr_str("; ", 2)));
int64_t v0_1948 = f160_rv(n_1936); 
{ int32_t _e6594 = (x_1937).n_; for (int32_t _k6594 = 0; _k6594 < _e6594; _k6594++) { int32_t i_1949 = (int32_t)_k6594; (void)(f339_decl_lv(((int64_t)((int64_t)v0_1948 + (int64_t)((int64_t)(i_1949))))));
(void)(({ hrv *_o6596 = &(g163); hr_fs(_o6596, hr_str(" = _t", 5)); hr_fi(_o6596, p_1947); hr_fs(_o6596, hr_str(".r", 2)); hr_fi(_o6596, i_1949); hr_fs(_o6596, hr_str("; ", 2)); }));
 } } _bk6593:; 
return;
 }
int64_t v_1950 = f160_rv(n_1936); 
int64_t t_1951 = ((int64_t)(((*({ hrv *_t6598 = &(g391); int64_t _i6598 = v_1950; (S12*)_t6598->b + hr_ix(_i6598, _t6598->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:951"); }))).ty_)); 
(void)(f339_decl_lv(v_1950));
(void)(f262_ow(hr_str(" = ", 3)));
if ((((x_1937).b_) < (((int32_t)0LL)))) { (void)(f262_ow(hr_str("{0}; ", 5)));
return;
 }
int64_t init_1952 = f90_kid(((int64_t)((x_1937).b_)), ((int64_t)0LL)); 
if (((((*({ hrv *_t6603 = &(g554); int64_t _i6603 = t_1951; (S1*)_t6603->b + hr_ix(_i6603, _t6603->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:956"); }))).k_) == (((uint8_t)10LL)))) { int64_t it_1953 = f281_fin(init_1952); 
if ((((((*({ hrv *_t6605 = &(g554); int64_t _i6605 = it_1953; (S1*)_t6605->b + hr_ix(_i6605, _t6605->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:956"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t6606 = &(g554); int64_t _i6606 = it_1953; (S1*)_t6606->b + hr_ix(_i6606, _t6606->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:956"); }))).k_) == (((uint8_t)11LL))))) { (void)(f291_gx(init_1952));
 } else { (void)(f326_gaddr(init_1952));
 }
(void)(f262_ow(hr_str("; ", 2)));
return;
 }
if (f270_is_res(t_1951)) { (void)(f271_gxo(init_1952));
(void)(f262_ow(hr_str("; ", 2)));
return;
 }
int64_t it_1954 = f141_at(init_1952); 
if (((((*({ hrv *_t6614 = &(g554); int64_t _i6614 = it_1954; (S1*)_t6614->b + hr_ix(_i6614, _t6614->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:959"); }))).k_) == (((uint8_t)14LL)))) { (void)(f291_gx(init_1952));
(void)(({ hrv *_o6616 = &(g163); hr_fs(_o6616, hr_str(".r0; ", 5)); }));
return;
 }
(void)(f291_gx(init_1952));
(void)(f262_ow(hr_str("; ", 2)));
}
static void f339_decl_lv(int64_t v_1944) {
int64_t t_1945 = ((int64_t)(((*({ hrv *_t6619 = &(g391); int64_t _i6619 = v_1944; (S12*)_t6619->b + hr_ix(_i6619, _t6619->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:963"); }))).ty_)); 
(void)(f263_ct(t_1945));
(void)(f262_ow(hr_str(" ", 1)));
if (f287_lv_isptr(v_1944)) { (void)(f262_ow(hr_str("*", 1)));
 }
(void)(f288_lv_name(v_1944));
if ((f270_is_res(t_1945) && (!(f287_lv_isptr(v_1944))))) { (void)(f262_ow(hr_str(" __attribute__((cleanup(hr_rdrop)))", 35)));
 }
}
static void f340_gstmt1(int64_t n_1955) {
S4 x_1956 = (*({ hrv *_t6628 = &(g707); int64_t _i6628 = n_1955; (S4*)_t6628->b + hr_ix(_i6628, _t6628->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1060"); })); 
int64_t k_1957 = ((int64_t)((x_1956).k_)); 
if (((k_1957) == (((int64_t)34LL)))) { (void)(f341_gassign(n_1955));
return;
 }
if (((k_1957) == (((int64_t)35LL)))) { int64_t a_1972 = ((int64_t)((x_1956).a_)); 
int64_t tt_1973 = f141_at(a_1972); 
if (((((*({ hrv *_t6631 = &(g554); int64_t _i6631 = tt_1973; (S1*)_t6631->b + hr_ix(_i6631, _t6631->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1063"); }))).k_) == (((uint8_t)10LL)))) { (void)(f262_ow(hr_str("(*", 2)));
(void)(f277_gx0(a_1972));
(void)(f262_ow(hr_str(")", 1)));
 } else { (void)(f291_gx(a_1972));
 }
(void)(f262_ow(({ hsl _r6637; if (((((int64_t)((x_1956).op_))) == (((int64_t)34LL)))) { _r6637 = hr_str("++;", 3);  } else { _r6637 = hr_str("--;", 3);  } _r6637; })));
return;
 }
if (((k_1957) == (((int64_t)50LL)))) { return;
 }
if (((k_1957) == (((int64_t)19LL)))) { (void)(f343_gif(n_1955, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1957) == (((int64_t)25LL)))) { (void)(f346_gwhile(n_1955));
return;
 }
if (((k_1957) == (((int64_t)26LL)))) { (void)(f349_gloop(n_1955, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1957) == (((int64_t)27LL)))) { (void)(f350_gfor(n_1955));
return;
 }
if (((k_1957) == (((int64_t)20LL)))) { (void)(f351_gmatch(n_1955, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1957) == (((int64_t)24LL)))) { (void)(f352_geblock(n_1955, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1957) == (((int64_t)23LL)))) { (void)(f262_ow(hr_str("{ ", 2)));
(void)(f344_gblk(n_1955, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f262_ow(hr_str(" }", 2)));
return;
 }
if (((k_1957) == (((int64_t)28LL)))) { (void)(f353_gret(n_1955));
return;
 }
if (((k_1957) == (((int64_t)29LL)))) { (void)(f357_gbreak(n_1955));
return;
 }
if (((k_1957) == (((int64_t)30LL)))) { (void)(f262_ow(hr_str("continue;", 9)));
return;
 }
if (((k_1957) == (((int64_t)37LL)))) { (void)(f289_gerr(n_1955, hr_str("const for is not supported by the self-hosted compiler yet", 58)));
return;
 }
if (f358_owned(n_1955)) { (void)(f262_ow(hr_str("hr_rgive(", 9)));
(void)(f277_gx0(n_1955));
(void)(f262_ow(hr_str(");", 2)));
return;
 }
(void)(f262_ow(hr_str("(void)(", 7)));
(void)(f291_gx(n_1955));
(void)(f262_ow(hr_str(");", 2)));
}
static void f341_gassign(int64_t n_1958) {
S4 x_1959 = (*({ hrv *_t6658 = &(g707); int64_t _i6658 = n_1958; (S4*)_t6658->b + hr_ix(_i6658, _t6658->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:970"); })); 
int64_t o_1960 = ((int64_t)((x_1959).op_)); 
if (((o_1960) == (((int64_t)11LL)))) { int64_t p_1961 = f295_nt(); 
(void)(f262_ow(hr_str("{ ", 2)));
(void)(f263_ct(f141_at(((int64_t)((x_1959).b_)))));
(void)(f262_ow(hr_str(" _t", 3)));
(void)(f296_oi(p_1961));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(((int64_t)((x_1959).b_))));
(void)(f262_ow(hr_str("; ", 2)));
int64_t tl_1962 = ((int64_t)((x_1959).a_)); 
{ int32_t _e6669 = ((*({ hrv *_t6670 = &(g707); int64_t _i6670 = tl_1962; (S4*)_t6670->b + hr_ix(_i6670, _t6670->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:976"); }))).n_; for (int32_t _k6669 = 0; _k6669 < _e6669; _k6669++) { int32_t i_1963 = (int32_t)_k6669; int64_t tg_1964 = f90_kid(tl_1962, ((int64_t)(i_1963))); 
(void)(f291_gx(tg_1964));
(void)(({ hrv *_o6673 = &(g163); hr_fs(_o6673, hr_str(" = _t", 5)); hr_fi(_o6673, p_1961); hr_fs(_o6673, hr_str(".r", 2)); hr_fi(_o6673, i_1963); hr_fs(_o6673, hr_str("; ", 2)); }));
 } } _bk6668:; 
(void)(f262_ow(hr_str("}", 1)));
return;
 }
int64_t a_1965 = ((int64_t)((x_1959).a_)); 
int64_t tt_1966 = f141_at(a_1965); 
int64_t d_1967 = f182_deref(tt_1966); 
if ((((o_1960) == (((int64_t)18LL))) && ((((*({ hrv *_t6677 = &(g554); int64_t _i6677 = tt_1966; (S1*)_t6677->b + hr_ix(_i6677, _t6677->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:983"); }))).k_) == (((uint8_t)10LL))))) { int64_t b_1968 = ((int64_t)((x_1959).b_)); 
(void)(f277_gx0(a_1965));
(void)(f262_ow(hr_str(" = ", 3)));
if ((((((*({ hrv *_t6680 = &(g554); int64_t _i6680 = f281_fin(b_1968); (S1*)_t6680->b + hr_ix(_i6680, _t6680->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:986"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t6682 = &(g554); int64_t _i6682 = f281_fin(b_1968); (S1*)_t6682->b + hr_ix(_i6682, _t6682->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:986"); }))).k_) == (((uint8_t)11LL))))) { (void)(f291_gx(b_1968));
 } else { (void)(f326_gaddr(b_1968));
 }
(void)(f262_ow(hr_str(";", 1)));
return;
 }
if ((((o_1960) == (((int64_t)36LL))) || ((o_1960) == (((int64_t)18LL))))) { if (f270_is_res(d_1967)) { (void)(f262_ow(hr_str("hr_rset(", 8)));
if (((((*({ hrv *_t6689 = &(g554); int64_t _i6689 = tt_1966; (S1*)_t6689->b + hr_ix(_i6689, _t6689->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:991"); }))).k_) == (((uint8_t)10LL)))) { (void)(f277_gx0(a_1965));
 } else { (void)(f262_ow(hr_str("&(", 2)));
(void)(f291_gx(a_1965));
(void)(f262_ow(hr_str(")", 1)));
 }
(void)(f262_ow(hr_str(", ", 2)));
(void)(f271_gxo(((int64_t)((x_1959).b_))));
(void)(f262_ow(hr_str(");", 2)));
return;
 }
if ((((((((*({ hrv *_t6697 = &(g554); int64_t _i6697 = tt_1966; (S1*)_t6697->b + hr_ix(_i6697, _t6697->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:992"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t6698 = &(g554); int64_t _i6698 = f141_at(((int64_t)((x_1959).b_))); (S1*)_t6698->b + hr_ix(_i6698, _t6698->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:992"); }))).k_) != (((uint8_t)10LL)))) && ((((*({ hrv *_t6700 = &(g554); int64_t _i6700 = f281_fin(((int64_t)((x_1959).b_))); (S1*)_t6700->b + hr_ix(_i6700, _t6700->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:992"); }))).k_) != (((uint8_t)10LL)))) && ((((*({ hrv *_t6702 = &(g554); int64_t _i6702 = f141_at(((int64_t)((x_1959).b_))); (S1*)_t6702->b + hr_ix(_i6702, _t6702->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:992"); }))).k_) != (((uint8_t)11LL))))) { (void)(f262_ow(hr_str("*", 1)));
(void)(f277_gx0(a_1965));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(((int64_t)((x_1959).b_))));
(void)(f262_ow(hr_str(";", 1)));
return;
 }
if (((((*({ hrv *_t6709 = &(g707); int64_t _i6709 = a_1965; (S4*)_t6709->b + hr_ix(_i6709, _t6709->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:993"); }))).k_) == (((uint8_t)8LL)))) { (void)(f291_gx(a_1965));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(((int64_t)((x_1959).b_))));
(void)(f262_ow(hr_str(";", 1)));
return;
 }
int64_t q_1969 = f295_nt(); 
(void)(f262_ow(hr_str("{ ", 2)));
(void)(f263_ct(d_1967));
(void)(f262_ow(hr_str(" *_t", 4)));
(void)(f296_oi(q_1969));
(void)(f262_ow(hr_str(" = &(", 5)));
(void)(f291_gx(a_1965));
(void)(f262_ow(hr_str("); *_t", 6)));
(void)(f296_oi(q_1969));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(((int64_t)((x_1959).b_))));
(void)(f262_ow(hr_str("; }", 3)));
return;
 }
int64_t p_1970 = f295_nt(); 
(void)(f262_ow(hr_str("{ ", 2)));
(void)(f263_ct(d_1967));
(void)(f262_ow(hr_str(" *_t", 4)));
(void)(f296_oi(p_1970));
(void)(f262_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t6732 = &(g554); int64_t _i6732 = tt_1966; (S1*)_t6732->b + hr_ix(_i6732, _t6732->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1000"); }))).k_) == (((uint8_t)10LL)))) { (void)(f277_gx0(a_1965));
 } else { (void)(f262_ow(hr_str("&(", 2)));
(void)(f291_gx(a_1965));
(void)(f262_ow(hr_str(")", 1)));
 }
(void)(f262_ow(hr_str("; *_t", 5)));
(void)(f296_oi(p_1970));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f309_garith(f342_base_op(o_1960), d_1967, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)((x_1959).b_)), p_1970, n_1958));
(void)(f262_ow(hr_str("; }", 3)));
}
static int64_t f342_base_op(int64_t o_1971) {
if (((o_1971) == (((int64_t)26LL)))) { return ((int64_t)21LL);
 }
if (((o_1971) == (((int64_t)27LL)))) { return ((int64_t)22LL);
 }
if (((o_1971) == (((int64_t)28LL)))) { return ((int64_t)23LL);
 }
if (((o_1971) == (((int64_t)29LL)))) { return ((int64_t)24LL);
 }
if (((o_1971) == (((int64_t)30LL)))) { return ((int64_t)25LL);
 }
if (((o_1971) == (((int64_t)31LL)))) { return ((int64_t)49LL);
 }
if (((o_1971) == (((int64_t)32LL)))) { return ((int64_t)50LL);
 }
if (((o_1971) == (((int64_t)33LL)))) { return ((int64_t)51LL);
 }
if (((o_1971) == (((int64_t)45LL)))) { return ((int64_t)43LL);
 }
if (((o_1971) == (((int64_t)46LL)))) { return ((int64_t)44LL);
 }
return o_1971;
}
static void f343_gif(int64_t n_1974, int64_t res_1975) {
S4 x_1976 = (*({ hrv *_t6743 = &(g707); int64_t _i6743 = n_1974; (S4*)_t6743->b + hr_ix(_i6743, _t6743->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:817"); })); 
(void)(f262_ow(hr_str("if (", 4)));
int64_t m_1977 = f219_ax(n_1974); 
if ((((m_1977) != (((int64_t)0LL))) && ((m_1977) != (((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))))) { (void)(f262_ow(hr_str("(", 1)));
(void)(f277_gx0(((int64_t)((x_1976).a_))));
(void)(f262_ow(hr_str(") != 0", 6)));
 } else { (void)(f291_gx(((int64_t)((x_1976).a_))));
 }
(void)(f262_ow(hr_str(") { ", 4)));
if (((m_1977) > (((int64_t)1LL)))) { int64_t v_1978 = ((int64_t)((int64_t)m_1977 & (int64_t)((int64_t)((int64_t)((int64_t)((((int64_t)1LL)) << ((((int64_t)30LL)) & 63))) - (int64_t)((int64_t)1LL))))); 
(void)(f263_ct(((int64_t)(((*({ hrv *_t6752 = &(g391); int64_t _i6752 = v_1978; (S12*)_t6752->b + hr_ix(_i6752, _t6752->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:822"); }))).ty_))));
(void)(f262_ow(hr_str(" *", 2)));
(void)(f288_lv_name(v_1978));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f277_gx0(((int64_t)((x_1976).a_))));
(void)(f262_ow(hr_str("; ", 2)));
 }
(void)(f344_gblk(((int64_t)((x_1976).b_)), res_1975, false));
(void)(f262_ow(hr_str(" }", 2)));
if ((((x_1976).c_) >= (((int32_t)0LL)))) { (void)(f262_ow(hr_str(" else { ", 8)));
if (((((*({ hrv *_t6761 = &(g707); int64_t _i6761 = (x_1976).c_; (S4*)_t6761->b + hr_ix(_i6761, _t6761->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:825"); }))).k_) == (((uint8_t)19LL)))) { (void)(f343_gif(((int64_t)((x_1976).c_)), res_1975));
 } else { (void)(f344_gblk(((int64_t)((x_1976).c_)), res_1975, false));
 }
(void)(f262_ow(hr_str(" }", 2)));
 }
}
static void f344_gblk(int64_t b_1979, int64_t res_1980, bool val_1981) {
S4 x_1982 = (*({ hrv *_t6765 = &(g707); int64_t _i6765 = b_1979; (S4*)_t6765->b + hr_ix(_i6765, _t6765->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:806"); })); 
if (((((int64_t)((x_1982).k_))) != (((int64_t)23LL)))) { if (((res_1980) >= (((int64_t)0LL)))) { (void)(f345_gtail(b_1979, res_1980));
 } else { if (val_1981) { (void)(f291_gx(b_1979));
(void)(f262_ow(hr_str(";", 1)));
 } else { (void)(f337_gstmt(b_1979));
 }
 }
return;
 }
{ int32_t _e6771 = (x_1982).n_; for (int32_t _k6771 = 0; _k6771 < _e6771; _k6771++) { int32_t i_1985 = (int32_t)_k6771; (void)(f337_gstmt(f90_kid(b_1979, ((int64_t)(i_1985)))));
 } } _bk6770:; 
if ((((x_1982).a_) >= (((int32_t)0LL)))) { int64_t tl_1986 = ((int64_t)((x_1982).a_)); 
if (((res_1980) >= (((int64_t)0LL)))) { (void)(f345_gtail(tl_1986, res_1980));
return;
 }
if (((val_1981 && ((f141_at(tl_1986)) != (g561))) && (!(f143_ends(tl_1986))))) { (void)(f291_gx(tl_1986));
(void)(f262_ow(hr_str("; ", 2)));
return;
 }
(void)(f337_gstmt(tl_1986));
 }
}
static void f345_gtail(int64_t tl_1983, int64_t res_1984) {
if ((((res_1984) >= (((int64_t)0LL))) && (!(f143_ends(tl_1983))))) { (void)(f262_ow(hr_str("_r", 2)));
(void)(f296_oi(res_1984));
(void)(f262_ow(hr_str(" = ", 3)));
if (f270_is_res(f281_fin(tl_1983))) { (void)(f271_gxo(tl_1983));
 } else { (void)(f291_gx(tl_1983));
 }
(void)(f262_ow(hr_str("; ", 2)));
return;
 }
(void)(f337_gstmt(tl_1983));
}
static void f346_gwhile(int64_t n_1987) {
S4 x_1988 = (*({ hrv *_t6790 = &(g707); int64_t _i6790 = n_1987; (S4*)_t6790->b + hr_ix(_i6790, _t6790->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:840"); })); 
int64_t l_1991 = f347_lbl_push(((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f262_ow(hr_str("while (", 7)));
if (((f219_ax(n_1987)) == (((int64_t)1LL)))) { (void)(f262_ow(hr_str("(", 1)));
(void)(f277_gx0(((int64_t)((x_1988).a_))));
(void)(f262_ow(hr_str(") != 0", 6)));
 } else { (void)(f291_gx(((int64_t)((x_1988).a_))));
 }
(void)(f262_ow(hr_str(") { ", 4)));
(void)(f344_gblk(((int64_t)((x_1988).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f262_ow(hr_str(" }", 2)));
(void)(f348_lbl_pop(l_1991));
}
static int64_t f347_lbl_push(int64_t res_1989) {
int64_t l_1990 = f295_nt(); 
(void)(({ hrv *_v6803 = &(g180); int32_t _x6803 = ((int32_t)(l_1990)); int32_t *_p6803 = (int32_t*)hr_grow(_v6803, 1, sizeof _x6803); *_p6803 = _x6803; _p6803; }));
(void)(({ hrv *_v6804 = &(g181); int32_t _x6804 = ((int32_t)(res_1989)); int32_t *_p6804 = (int32_t*)hr_grow(_v6804, 1, sizeof _x6804); *_p6804 = _x6804; _p6804; }));
return l_1990;
}
static void f348_lbl_pop(int64_t l_1992) {
(void)(({ hrv *_v6805 = &(g180); if (!_v6805->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:828"); ((int32_t*)_v6805->b)[--_v6805->n]; }));
(void)(({ hrv *_v6806 = &(g181); if (!_v6806->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:828"); ((int32_t*)_v6806->b)[--_v6806->n]; }));
(void)(({ hrv *_o6807 = &(g163); hr_fs(_o6807, hr_str(" _bk", 4)); hr_fi(_o6807, l_1992); hr_fs(_o6807, hr_str(":; ", 3)); }));
}
static void f349_gloop(int64_t n_1993, int64_t res_1994) {
int64_t l_1995 = f347_lbl_push(res_1994); 
(void)(f262_ow(hr_str("for (;;) { ", 11)));
(void)(f344_gblk(((int64_t)(((*({ hrv *_t6811 = &(g707); int64_t _i6811 = n_1993; (S4*)_t6811->b + hr_ix(_i6811, _t6811->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:831"); }))).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f262_ow(hr_str(" }", 2)));
(void)(f348_lbl_pop(l_1995));
}
static void f350_gfor(int64_t n_1996) {
S4 x_1997 = (*({ hrv *_t6814 = &(g707); int64_t _i6814 = n_1996; (S4*)_t6814->b + hr_ix(_i6814, _t6814->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:848"); })); 
int64_t v_1998 = f160_rv(n_1996); 
int64_t m_1999 = f219_ax(n_1996); 
int64_t iv_2000 = ({ int64_t _r6817; if ((((x_1997).c_) >= (((int32_t)0LL)))) { _r6817 = ((int64_t)((m_1999) >> ((((int64_t)2LL)) & 63)));  } else { _r6817 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r6817; }); 
int64_t l_2001 = f347_lbl_push(((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t p_2002 = f295_nt(); 
int64_t et_2003 = ((int64_t)(((*({ hrv *_t6820 = &(g391); int64_t _i6820 = v_1998; (S12*)_t6820->b + hr_ix(_i6820, _t6820->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:854"); }))).ty_)); 
if (((((int64_t)((int64_t)m_1999 & (int64_t)((int64_t)3LL)))) == (((int64_t)0LL)))) { int64_t rt0_2004 = f281_fin(({ int64_t _r6822; if ((((x_1997).b_) >= (((int32_t)0LL)))) { _r6822 = ((int64_t)((x_1997).b_));  } else { _r6822 = ((int64_t)((x_1997).a_));  } _r6822; })); 
int64_t ctt_2005 = ({ int64_t _r6823; if (((((*({ hrv *_t6824 = &(g554); int64_t _i6824 = rt0_2004; (S1*)_t6824->b + hr_ix(_i6824, _t6824->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:857"); }))).k_) == (((uint8_t)3LL)))) { _r6823 = rt0_2004;  } else { _r6823 = g566;  } _r6823; }); 
(void)(f262_ow(hr_str("{ ", 2)));
(void)(f263_ct(ctt_2005));
(void)(f262_ow(hr_str(" _e", 3)));
(void)(f296_oi(p_2002));
(void)(f262_ow(hr_str(" = ", 3)));
if ((((x_1997).b_) >= (((int32_t)0LL)))) { (void)(f291_gx(((int64_t)((x_1997).b_))));
 } else { (void)(f291_gx(((int64_t)((x_1997).a_))));
 }
(void)(f262_ow(hr_str("; for (", 7)));
(void)(f263_ct(ctt_2005));
(void)(({ hrv *_o6834 = &(g163); hr_fs(_o6834, hr_str(" _k", 3)); hr_fi(_o6834, p_2002); hr_fs(_o6834, hr_str(" = ", 3)); }));
if ((((x_1997).b_) >= (((int32_t)0LL)))) { (void)(f291_gx(((int64_t)((x_1997).a_))));
 } else { (void)(f262_ow(hr_str("0", 1)));
 }
(void)(({ hrv *_o6837 = &(g163); hr_fs(_o6837, hr_str("; _k", 4)); hr_fi(_o6837, p_2002); hr_fs(_o6837, hr_str(" < _e", 5)); hr_fi(_o6837, p_2002); hr_fs(_o6837, hr_str("; _k", 4)); hr_fi(_o6837, p_2002); hr_fs(_o6837, hr_str("++) { ", 6)); }));
(void)(f263_ct(et_2003));
(void)(f262_ow(hr_str(" ", 1)));
(void)(f288_lv_name(v_1998));
(void)(({ hrv *_o6841 = &(g163); hr_fs(_o6841, hr_str(" = (", 4)); }));
(void)(f263_ct(et_2003));
(void)(({ hrv *_o6843 = &(g163); hr_fs(_o6843, hr_str(")_k", 3)); hr_fi(_o6843, p_2002); hr_fs(_o6843, hr_str("; ", 2)); }));
if (((iv_2000) >= (((int64_t)0LL)))) { (void)(f263_ct(((int64_t)(((*({ hrv *_t6845 = &(g391); int64_t _i6845 = iv_2000; (S12*)_t6845->b + hr_ix(_i6845, _t6845->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:863"); }))).ty_))));
(void)(f262_ow(hr_str(" ", 1)));
(void)(f288_lv_name(iv_2000));
(void)(f262_ow(hr_str(" = (", 4)));
(void)(f263_ct(((int64_t)(((*({ hrv *_t6850 = &(g391); int64_t _i6850 = iv_2000; (S12*)_t6850->b + hr_ix(_i6850, _t6850->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:863"); }))).ty_))));
(void)(({ hrv *_o6851 = &(g163); hr_fs(_o6851, hr_str(")_k", 3)); hr_fi(_o6851, p_2002); hr_fs(_o6851, hr_str("; ", 2)); }));
 }
(void)(f344_gblk(((int64_t)((x_1997).d_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f262_ow(hr_str(" } }", 4)));
(void)(f348_lbl_pop(l_2001));
return;
 }
int64_t a_2006 = ((int64_t)((x_1997).a_)); 
int64_t bt_2007 = f141_at(a_2006); 
int64_t d_2008 = f182_deref(bt_2007); 
int64_t e_2009 = ((int64_t)(((*({ hrv *_t6857 = &(g554); int64_t _i6857 = d_2008; (S1*)_t6857->b + hr_ix(_i6857, _t6857->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:872"); }))).a_)); 
bool byref_2010 = ((((uint16_t)((uint64_t)(x_1997).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))); 
if (f270_is_res(d_2008)) { (void)(f262_ow(hr_str("{ hrv *_v", 9)));
(void)(f296_oi(p_2002));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f327_grecv_ptr(a_2006));
(void)(({ hrv *_o6863 = &(g163); hr_fs(_o6863, hr_str("; for (int64_t _k", 17)); hr_fi(_o6863, p_2002); hr_fs(_o6863, hr_str(" = 0; _k", 8)); hr_fi(_o6863, p_2002); hr_fs(_o6863, hr_str(" < _v", 5)); hr_fi(_o6863, p_2002); hr_fs(_o6863, hr_str("->n; _k", 7)); hr_fi(_o6863, p_2002); hr_fs(_o6863, hr_str("++) { ", 6)); }));
(void)(f263_ct(e_2009));
(void)(f262_ow(({ hsl _r6866; if (byref_2010) { _r6866 = hr_str(" *", 2);  } else { _r6866 = hr_str(" ", 1);  } _r6866; })));
(void)(f288_lv_name(v_1998));
(void)(f262_ow(({ hsl _r6869; if (byref_2010) { _r6869 = hr_str(" = &((", 6);  } else { _r6869 = hr_str(" = ((", 5);  } _r6869; })));
(void)(f263_ct(e_2009));
(void)(({ hrv *_o6871 = &(g163); hr_fs(_o6871, hr_str("*)_v", 4)); hr_fi(_o6871, p_2002); hr_fs(_o6871, hr_str("->b)[_k", 7)); hr_fi(_o6871, p_2002); hr_fs(_o6871, hr_str("]; ", 3)); }));
 } else { (void)(f262_ow(hr_str("{ hsl _v", 8)));
(void)(f296_oi(p_2002));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f294_gsl(a_2006, bt_2007));
(void)(({ hrv *_o6876 = &(g163); hr_fs(_o6876, hr_str("; for (int64_t _k", 17)); hr_fi(_o6876, p_2002); hr_fs(_o6876, hr_str(" = 0; _k", 8)); hr_fi(_o6876, p_2002); hr_fs(_o6876, hr_str(" < _v", 5)); hr_fi(_o6876, p_2002); hr_fs(_o6876, hr_str(".n; _k", 6)); hr_fi(_o6876, p_2002); hr_fs(_o6876, hr_str("++) { ", 6)); }));
(void)(f263_ct(e_2009));
(void)(f262_ow(({ hsl _r6879; if (byref_2010) { _r6879 = hr_str(" *", 2);  } else { _r6879 = hr_str(" ", 1);  } _r6879; })));
(void)(f288_lv_name(v_1998));
(void)(f262_ow(({ hsl _r6882; if (byref_2010) { _r6882 = hr_str(" = &((", 6);  } else { _r6882 = hr_str(" = ((", 5);  } _r6882; })));
(void)(f263_ct(e_2009));
(void)(({ hrv *_o6884 = &(g163); hr_fs(_o6884, hr_str("*)_v", 4)); hr_fi(_o6884, p_2002); hr_fs(_o6884, hr_str(".p)[_k", 6)); hr_fi(_o6884, p_2002); hr_fs(_o6884, hr_str("]; ", 3)); }));
 }
if (((iv_2000) >= (((int64_t)0LL)))) { (void)(f263_ct(((int64_t)(((*({ hrv *_t6886 = &(g391); int64_t _i6886 = iv_2000; (S12*)_t6886->b + hr_ix(_i6886, _t6886->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:881"); }))).ty_))));
(void)(f262_ow(hr_str(" ", 1)));
(void)(f288_lv_name(iv_2000));
(void)(f262_ow(hr_str(" = (", 4)));
(void)(f263_ct(((int64_t)(((*({ hrv *_t6891 = &(g391); int64_t _i6891 = iv_2000; (S12*)_t6891->b + hr_ix(_i6891, _t6891->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:881"); }))).ty_))));
(void)(({ hrv *_o6892 = &(g163); hr_fs(_o6892, hr_str(")_k", 3)); hr_fi(_o6892, p_2002); hr_fs(_o6892, hr_str("; ", 2)); }));
 }
(void)(f344_gblk(((int64_t)((x_1997).d_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f262_ow(hr_str(" } }", 4)));
(void)(f348_lbl_pop(l_2001));
}
static void f351_gmatch(int64_t n_2011, int64_t res_2012) {
S4 x_2013 = (*({ hrv *_t6896 = &(g707); int64_t _i6896 = n_2011; (S4*)_t6896->b + hr_ix(_i6896, _t6896->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:887"); })); 
int64_t a_2014 = ((int64_t)((x_2013).a_)); 
int64_t st_2015 = f141_at(a_2014); 
int64_t d_2016 = f182_deref(st_2015); 
int64_t p_2017 = f295_nt(); 
bool isenum_2018 = ((((*({ hrv *_t6900 = &(g554); int64_t _i6900 = d_2016; (S1*)_t6900->b + hr_ix(_i6900, _t6900->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:892"); }))).k_) == (((uint8_t)6LL))); 
(void)(f262_ow(hr_str("{ ", 2)));
if (isenum_2018) { (void)(f263_ct(d_2016));
(void)(f262_ow(hr_str(" *_m", 4)));
(void)(f296_oi(p_2017));
(void)(f262_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t6906 = &(g554); int64_t _i6906 = st_2015; (S1*)_t6906->b + hr_ix(_i6906, _t6906->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:894"); }))).k_) == (((uint8_t)10LL)))) { (void)(f277_gx0(a_2014));
 } else { if (f274_is_place(a_2014)) { (void)(f262_ow(hr_str("&(", 2)));
(void)(f291_gx(a_2014));
(void)(f262_ow(hr_str(")", 1)));
 } else { int64_t k0_2019 = f275_tmp(d_2016, false); 
(void)(f262_ow(hr_str("(", 1)));
(void)(f276_ot(k0_2019));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f271_gxo(a_2014));
(void)(f262_ow(hr_str(", &", 3)));
(void)(f276_ot(k0_2019));
(void)(f262_ow(hr_str(")", 1)));
 }
 }
(void)(f262_ow(hr_str("; ", 2)));
 } else { (void)(f263_ct(d_2016));
(void)(f262_ow(hr_str(" _m", 3)));
(void)(f296_oi(p_2017));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(a_2014));
(void)(f262_ow(hr_str("; ", 2)));
 }
bool first_2020 = true; 
{ int32_t _e6928 = (x_2013).n_; for (int32_t _k6928 = 0; _k6928 < _e6928; _k6928++) { int32_t i_2021 = (int32_t)_k6928; int64_t arm_2022 = f90_kid(n_2011, ((int64_t)(i_2021))); 
S4 ar_2023 = (*({ hrv *_t6930 = &(g707); int64_t _i6930 = arm_2022; (S4*)_t6930->b + hr_ix(_i6930, _t6930->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:899"); })); 
if ((!(first_2020))) { (void)(f262_ow(hr_str(" else ", 6)));
 }
first_2020 = false;
if (((((uint16_t)((uint64_t)(ar_2023).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(f262_ow(hr_str("{ ", 2)));
(void)(f344_gblk(((int64_t)((ar_2023).b_)), res_2012, false));
(void)(f262_ow(hr_str(" }", 2)));
continue;
 }
(void)(f262_ow(hr_str("if (", 4)));
{ int32_t _e6937 = (ar_2023).n_; for (int32_t _k6937 = 0; _k6937 < _e6937; _k6937++) { int32_t j_2024 = (int32_t)_k6937; if (((j_2024) > (((int32_t)0LL)))) { (void)(f262_ow(hr_str(" || ", 4)));
 }
int64_t it_2025 = f90_kid(arm_2022, ((int64_t)(j_2024))); 
int64_t lo_2026 = ((int64_t)(((*({ hrv *_t6940 = &(g707); int64_t _i6940 = it_2025; (S4*)_t6940->b + hr_ix(_i6940, _t6940->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:907"); }))).a_)); 
if (isenum_2018) { (void)(({ hrv *_o6941 = &(g163); hr_fs(_o6941, hr_str("_m", 2)); hr_fi(_o6941, p_2017); hr_fs(_o6941, hr_str("->tag == ", 9)); hr_fi(_o6941, f160_rv(lo_2026)); }));
 } else { if (((((*({ hrv *_t6943 = &(g707); int64_t _i6943 = it_2025; (S4*)_t6943->b + hr_ix(_i6943, _t6943->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:910"); }))).b_) >= (((int32_t)0LL)))) { (void)(({ hrv *_o6944 = &(g163); hr_fs(_o6944, hr_str("(_m", 3)); hr_fi(_o6944, p_2017); hr_fs(_o6944, hr_str(" >= ", 4)); }));
(void)(f291_gx(lo_2026));
(void)(({ hrv *_o6946 = &(g163); hr_fs(_o6946, hr_str(" && _m", 6)); hr_fi(_o6946, p_2017); hr_fs(_o6946, hr_str(" < ", 3)); }));
(void)(f291_gx(((int64_t)(((*({ hrv *_t6948 = &(g707); int64_t _i6948 = it_2025; (S4*)_t6948->b + hr_ix(_i6948, _t6948->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:910"); }))).b_))));
(void)(f262_ow(hr_str(")", 1)));
 } else { if (((((f183_leaf_kind(d_2016)) == (((int64_t)0LL))) && ((((*({ hrv *_t6951 = &(g554); int64_t _i6951 = d_2016; (S1*)_t6951->b + hr_ix(_i6951, _t6951->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:911"); }))).k_) != (((uint8_t)3LL)))) && ((((*({ hrv *_t6952 = &(g554); int64_t _i6952 = d_2016; (S1*)_t6952->b + hr_ix(_i6952, _t6952->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:911"); }))).k_) != (((uint8_t)2LL))))) { (void)(f262_ow(hr_str("heq", 3)));
(void)(f296_oi(d_2016));
(void)(({ hrv *_o6955 = &(g163); hr_fs(_o6955, hr_str("(_m", 3)); hr_fi(_o6955, p_2017); hr_fs(_o6955, hr_str(", ", 2)); }));
(void)(f291_gx(lo_2026));
(void)(f262_ow(hr_str(")", 1)));
(void)(f297_gen_heq(d_2016));
 } else { (void)(({ hrv *_o6959 = &(g163); hr_fs(_o6959, hr_str("_m", 2)); hr_fi(_o6959, p_2017); hr_fs(_o6959, hr_str(" == ", 4)); }));
(void)(f291_gx(lo_2026));
 }
 }
 }
 } } _bk6936:; 
(void)(f262_ow(hr_str(") { ", 4)));
if (((((ar_2023).s_) >= (((int32_t)0LL))) && isenum_2018)) { int64_t v_2027 = f160_rv(arm_2022); 
int64_t vi_2028 = f160_rv(((int64_t)(((*({ hrv *_t6964 = &(g707); int64_t _i6964 = f90_kid(arm_2022, ((int64_t)0LL)); (S4*)_t6964->b + hr_ix(_i6964, _t6964->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:917"); }))).a_))); 
int64_t lt_2029 = ((int64_t)(((*({ hrv *_t6966 = &(g391); int64_t _i6966 = v_2027; (S12*)_t6966->b + hr_ix(_i6966, _t6966->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:918"); }))).ty_)); 
int64_t vt_2030 = f182_deref(lt_2029); 
int64_t ei_2031 = ((int64_t)(((*({ hrv *_t6968 = &(g554); int64_t _i6968 = d_2016; (S1*)_t6968->b + hr_ix(_i6968, _t6968->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:920"); }))).a_)); 
S9 vv_2032 = (*({ hrv *_t6969 = &(g560); int64_t _i6969 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t6970 = &(g559); int64_t _i6970 = ei_2031; (S8*)_t6970->b + hr_ix(_i6970, _t6970->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:921"); }))).v0_)) + (int64_t)vi_2028)); (S9*)_t6969->b + hr_ix(_i6969, _t6969->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:921"); })); 
bool has_2033 = ((((vv_2032).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t6971 = &(g557); int64_t _i6971 = (vv_2032).si_; (S10*)_t6971->b + hr_ix(_i6971, _t6971->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:922"); }))).zero_))); 
(void)(f263_ct(lt_2029));
(void)(f262_ow(hr_str(" ", 1)));
(void)(f288_lv_name(v_2027));
(void)(f262_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t6976 = &(g554); int64_t _i6976 = lt_2029; (S1*)_t6976->b + hr_ix(_i6976, _t6976->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:924"); }))).k_) == (((uint8_t)10LL)))) { if (has_2033) { (void)(({ hrv *_o6977 = &(g163); hr_fs(_o6977, hr_str("&_m", 3)); hr_fi(_o6977, p_2017); hr_fs(_o6977, hr_str("->u.v", 5)); hr_fi(_o6977, vi_2028); hr_fs(_o6977, hr_str("; ", 2)); }));
 } else { (void)(f262_ow(hr_str("0; ", 3)));
 }
 } else { if (has_2033) { (void)(({ hrv *_o6979 = &(g163); hr_fs(_o6979, hr_str("_m", 2)); hr_fi(_o6979, p_2017); hr_fs(_o6979, hr_str("->u.v", 5)); hr_fi(_o6979, vi_2028); hr_fs(_o6979, hr_str("; ", 2)); }));
 } else { (void)(f262_ow(hr_str("0; ", 3)));
 }
 }
 }
(void)(f344_gblk(((int64_t)((ar_2023).b_)), res_2012, false));
(void)(f262_ow(hr_str(" }", 2)));
 } } _bk6927:; 
(void)(f262_ow(hr_str(" }", 2)));
}
static void f352_geblock(int64_t n_2034, int64_t res_2035) {
int64_t l_2036 = f347_lbl_push(res_2035); 
(void)(f262_ow(hr_str("{ ", 2)));
(void)(f344_gblk(((int64_t)(((*({ hrv *_t6987 = &(g707); int64_t _i6987 = n_2034; (S4*)_t6987->b + hr_ix(_i6987, _t6987->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:836"); }))).a_)), res_2035, false));
(void)(f262_ow(hr_str(" }", 2)));
(void)(f348_lbl_pop(l_2036));
}
static void f353_gret(int64_t n_2037) {
S4 x_2038 = (*({ hrv *_t6990 = &(g707); int64_t _i6990 = n_2037; (S4*)_t6990->b + hr_ix(_i6990, _t6990->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1017"); })); 
int64_t lt_2039 = f219_ax(n_2037); 
if ((((lt_2039) >= (((int64_t)0LL))) && ((lt_2039) != (g179)))) { int64_t rt0_2040 = ((int64_t)(((*({ hrv *_t6992 = &(g390); int64_t _i6992 = lt_2039; (S6*)_t6992->b + hr_ix(_i6992, _t6992->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1020"); }))).ret_)); 
(void)(f262_ow(hr_str("{ ", 2)));
if ((((x_2038).n_) > (((int32_t)1LL)))) { (void)(({ hrv *_o6994 = &(g163); hr_fs(_o6994, hr_str("_lrv", 4)); hr_fi(_o6994, lt_2039); hr_fs(_o6994, hr_str(" = (", 4)); }));
(void)(f263_ct(rt0_2040));
(void)(f262_ow(hr_str("){ ", 3)));
{ int32_t _e6998 = (x_2038).n_; for (int32_t _k6998 = 0; _k6998 < _e6998; _k6998++) { int32_t i_2041 = (int32_t)_k6998; if (((i_2041) > (((int32_t)0LL)))) { (void)(f262_ow(hr_str(", ", 2)));
 }
int64_t c_2042 = f90_kid(n_2037, ((int64_t)(i_2041))); 
if (f270_is_res(f281_fin(c_2042))) { (void)(f354_gmove(c_2042));
 } else { (void)(f291_gx(c_2042));
 }
 } } _bk6997:; 
(void)(f262_ow(hr_str(" }; ", 4)));
 } else { if ((((x_2038).n_) == (((int32_t)1LL)))) { (void)(({ hrv *_o7006 = &(g163); hr_fs(_o7006, hr_str("_lrv", 4)); hr_fi(_o7006, lt_2039); hr_fs(_o7006, hr_str(" = ", 3)); }));
int64_t c_2048 = f90_kid(n_2037, ((int64_t)0LL)); 
if (f270_is_res(rt0_2040)) { (void)(f354_gmove(c_2048));
 } else { (void)(f291_gx(c_2048));
 }
(void)(f262_ow(hr_str("; ", 2)));
 }
 }
(void)(({ hrv *_o7012 = &(g163); hr_fs(_o7012, hr_str("hr_lr = ", 8)); hr_fi(_o7012, ((int64_t)((int64_t)lt_2039 + (int64_t)((int64_t)1LL)))); hr_fs(_o7012, hr_str("; ", 2)); }));
(void)(f356_gdummy());
(void)(f262_ow(hr_str(" }", 2)));
return;
 }
if ((((x_2038).n_) == (((int32_t)0LL)))) { (void)(f262_ow(hr_str("return;", 7)));
return;
 }
int64_t f_2050 = ({ int64_t _r7016; if (((lt_2039) >= (((int64_t)0LL)))) { _r7016 = lt_2039;  } else { _r7016 = f223_ret_fn();  } _r7016; }); 
int64_t rt_2051 = ((int64_t)(((*({ hrv *_t7018 = &(g390); int64_t _i7018 = f_2050; (S6*)_t7018->b + hr_ix(_i7018, _t7018->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1029"); }))).ret_)); 
if ((((x_2038).n_) > (((int32_t)1LL)))) { (void)(f262_ow(hr_str("return (", 8)));
(void)(f263_ct(rt_2051));
(void)(f262_ow(hr_str("){ ", 3)));
{ int32_t _e7023 = (x_2038).n_; for (int32_t _k7023 = 0; _k7023 < _e7023; _k7023++) { int32_t i_2052 = (int32_t)_k7023; if (((i_2052) > (((int32_t)0LL)))) { (void)(f262_ow(hr_str(", ", 2)));
 }
int64_t c_2053 = f90_kid(n_2037, ((int64_t)(i_2052))); 
if (f270_is_res(f281_fin(c_2053))) { (void)(f354_gmove(c_2053));
 } else { (void)(f291_gx(c_2053));
 }
 } } _bk7022:; 
(void)(f262_ow(hr_str(" };", 3)));
return;
 }
int64_t c_2054 = f90_kid(n_2037, ((int64_t)0LL)); 
(void)(f262_ow(hr_str("return ", 7)));
if (f270_is_res(rt_2051)) { (void)(f354_gmove(c_2054));
 } else { (void)(f291_gx(c_2054));
 }
(void)(f262_ow(hr_str(";", 1)));
}
static void f354_gmove(int64_t c_2043) {
if (f355_movable_local(c_2043)) { int64_t v_2046 = f160_rv(c_2043); 
int64_t p_2047 = f295_nt(); 
(void)(f262_ow(hr_str("({ hrv _mv", 10)));
(void)(f296_oi(p_2047));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f288_lv_name(v_2046));
(void)(f262_ow(hr_str("; ", 2)));
(void)(f288_lv_name(v_2046));
(void)(f262_ow(hr_str(".b = 0; ", 8)));
(void)(f288_lv_name(v_2046));
(void)(({ hrv *_o7048 = &(g163); hr_fs(_o7048, hr_str(".n = 0; _mv", 11)); hr_fi(_o7048, p_2047); hr_fs(_o7048, hr_str("; })", 4)); }));
return;
 }
(void)(f271_gxo(c_2043));
}
static bool f355_movable_local(int64_t c_2044) {
if ((((((*({ hrv *_t7050 = &(g707); int64_t _i7050 = c_2044; (S4*)_t7050->b + hr_ix(_i7050, _t7050->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1011"); }))).k_) != (((uint8_t)8LL))) || ((f159_rk(c_2044)) != (((int64_t)1LL))))) { return false;
 }
int64_t v_2045 = f160_rv(c_2044); 
return (((((((int64_t)(((*({ hrv *_t7053 = &(g391); int64_t _i7053 = v_2045; (S12*)_t7053->b + hr_ix(_i7053, _t7053->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1011"); }))).cfn_))) == (g179)) && (!(f287_lv_isptr(v_2045)))) && ((((*({ hrv *_t7055 = &(g554); int64_t _i7055 = ((*({ hrv *_t7056 = &(g391); int64_t _i7056 = v_2045; (S12*)_t7056->b + hr_ix(_i7056, _t7056->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1011"); }))).ty_; (S1*)_t7055->b + hr_ix(_i7055, _t7055->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1011"); }))).k_) != (((uint8_t)10LL)))) && (((f153_cv(c_2044)) < (((int64_t)0LL))) || ((f153_cv(c_2044)) == (f141_at(c_2044)))));
}
static void f356_gdummy(void) {
int64_t rt_2049 = ((int64_t)(((*({ hrv *_t7060 = &(g390); int64_t _i7060 = g179; (S6*)_t7060->b + hr_ix(_i7060, _t7060->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1005"); }))).ret_)); 
if ((((rt_2049) < (((int64_t)0LL))) || ((rt_2049) == (g561)))) { (void)(f262_ow(hr_str("return;", 7)));
return;
 }
(void)(f262_ow(hr_str("{ ", 2)));
(void)(f263_ct(rt_2049));
(void)(f262_ow(hr_str(" _z; memset(&_z, 0, sizeof _z); return _z; }", 44)));
}
static void f357_gbreak(int64_t n_2055) {
S4 x_2056 = (*({ hrv *_t7065 = &(g707); int64_t _i7065 = n_2055; (S4*)_t7065->b + hr_ix(_i7065, _t7065->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1035"); })); 
if ((((g180).n) == (((int64_t)0LL)))) { (void)(f289_gerr(n_2055, hr_str("break outside a loop", 20)));
return;
 }
int64_t l_2057 = ((int64_t)((*({ hrv *_t7067 = &(g180); int64_t _i7067 = ((int64_t)((int64_t)(g180).n - (int64_t)((int64_t)1LL))); (int32_t*)_t7067->b + hr_ix(_i7067, _t7067->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1037"); })))); 
int64_t r_2058 = ((int64_t)((*({ hrv *_t7068 = &(g181); int64_t _i7068 = ((int64_t)((int64_t)(g181).n - (int64_t)((int64_t)1LL))); (int32_t*)_t7068->b + hr_ix(_i7068, _t7068->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1038"); })))); 
(void)(f262_ow(hr_str("{ ", 2)));
if ((((x_2056).a_) >= (((int32_t)0LL)))) { if (((r_2058) >= (((int64_t)0LL)))) { (void)(f262_ow(hr_str("_r", 2)));
(void)(f296_oi(r_2058));
(void)(f262_ow(hr_str(" = ", 3)));
(void)(f291_gx(((int64_t)((x_2056).a_))));
(void)(f262_ow(hr_str("; ", 2)));
 } else { (void)(f262_ow(hr_str("(void)(", 7)));
(void)(f291_gx(((int64_t)((x_2056).a_))));
(void)(f262_ow(hr_str("); ", 3)));
 }
 }
(void)(({ hrv *_o7078 = &(g163); hr_fs(_o7078, hr_str("goto _bk", 8)); hr_fi(_o7078, l_2057); hr_fs(_o7078, hr_str("; }", 3)); }));
}
static bool f358_owned(int64_t n_2059) {
return (f270_is_res(f281_fin(n_2059)) && (!(f274_is_place(n_2059))));
}
static bool f359_is_ext(int64_t i_2063) {
return ((((uint16_t)((uint64_t)((*({ hrv *_t7082 = &(g707); int64_t _i7082 = ((*({ hrv *_t7083 = &(g390); int64_t _i7083 = i_2063; (S6*)_t7083->b + hr_ix(_i7083, _t7083->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:581"); }))).node_; (S4*)_t7082->b + hr_ix(_i7082, _t7082->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:581"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)));
}
static void f360_ext_name(int64_t i_2068) {
int64_t node_2069 = ((int64_t)(((*({ hrv *_t7084 = &(g390); int64_t _i7084 = i_2068; (S6*)_t7084->b + hr_ix(_i7084, _t7084->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:576"); }))).node_)); 
int64_t x_2070 = ((int64_t)(((*({ hrv *_t7085 = &(g707); int64_t _i7085 = node_2069; (S4*)_t7085->b + hr_ix(_i7085, _t7085->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:577"); }))).e_)); 
if ((((x_2070) >= (((int64_t)0LL))) && ((((*({ hrv *_t7086 = &(g707); int64_t _i7086 = x_2070; (S4*)_t7086->b + hr_ix(_i7086, _t7086->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:578"); }))).a_) >= (((int32_t)0LL))))) { hsl s_2071 = f282_tok_str(((int64_t)(((*({ hrv *_t7088 = &(g707); int64_t _i7088 = x_2070; (S4*)_t7088->b + hr_ix(_i7088, _t7088->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:578"); }))).a_))); 
if (((((((s_2071).n) > (((int64_t)3LL))) && (((*({ hsl _t7089 = s_2071; int64_t _i7089 = ((int64_t)0LL); (uint8_t*)_t7089.p + hr_ix(_i7089, _t7089.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:578"); }))) == (((uint8_t)103LL)))) && (((*({ hsl _t7090 = s_2071; int64_t _i7090 = ((int64_t)1LL); (uint8_t*)_t7090.p + hr_ix(_i7090, _t7090.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:578"); }))) == (((uint8_t)115LL)))) && (((*({ hsl _t7091 = s_2071; int64_t _i7091 = ((int64_t)2LL); (uint8_t*)_t7091.p + hr_ix(_i7091, _t7091.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:578"); }))) == (((uint8_t)95LL))))) { (void)(f262_ow(hr_str("hr_", 3)));
(void)(f262_ow(({ hsl _t7094 = s_2071; int64_t _l7094 = ((int64_t)3LL), _h7094 = _t7094.n; if (_l7094 < 0 || _h7094 < _l7094 || _h7094 > _t7094.n) hr_slerr(_l7094, _h7094, _t7094.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:578"); (hsl){ _t7094.p + _l7094 * (int64_t)sizeof(uint8_t), _h7094 - _l7094 }; })));
return;
 }
(void)(f262_ow(s_2071));
return;
 }
(void)(f262_ow(f10_nm(((int64_t)(((*({ hrv *_t7098 = &(g707); int64_t _i7098 = node_2069; (S4*)_t7098->b + hr_ix(_i7098, _t7098->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:579"); }))).s_)))));
}
static void f361_gcall_args(int64_t n_2072, int64_t inst_2073, int64_t recv_2074) {
S4 x_2075 = (*({ hrv *_t7099 = &(g707); int64_t _i7099 = n_2072; (S4*)_t7099->b + hr_ix(_i7099, _t7099->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:583"); })); 
int64_t np_2076 = ((int64_t)(((*({ hrv *_t7100 = &(g707); int64_t _i7100 = ((*({ hrv *_t7101 = &(g390); int64_t _i7101 = inst_2073; (S6*)_t7101->b + hr_ix(_i7101, _t7101->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:584"); }))).node_; (S4*)_t7100->b + hr_ix(_i7100, _t7100->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:584"); }))).n_)); 
int64_t na_2077 = ((int64_t)((int64_t)((int64_t)((x_2075).n_)) + (int64_t)({ int64_t _r7102; if (((recv_2074) >= (((int64_t)0LL)))) { _r7102 = ((int64_t)1LL);  } else { _r7102 = ((int64_t)0LL);  } _r7102; }))); 
bool first_2078 = true; 
{ int64_t _e7104 = np_2076; for (int64_t _k7104 = 0; _k7104 < _e7104; _k7104++) { int64_t j_2079 = (int64_t)_k7104; int64_t pt_2080 = f212_ptype_of(inst_2073, j_2079); 
if ((!(first_2078))) { (void)(f262_ow(hr_str(", ", 2)));
 }
first_2078 = false;
if (((j_2079) >= (na_2077))) { int64_t p_2081 = f90_kid(((int64_t)(((*({ hrv *_t7108 = &(g390); int64_t _i7108 = inst_2073; (S6*)_t7108->b + hr_ix(_i7108, _t7108->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:592"); }))).node_)), j_2079); 
int64_t sa_2082 = g403; 
g403 = inst_2073;
(void)(f291_gx(((int64_t)(((*({ hrv *_t7110 = &(g707); int64_t _i7110 = p_2081; (S4*)_t7110->b + hr_ix(_i7110, _t7110->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:593"); }))).b_))));
g403 = sa_2082;
continue;
 }
int64_t c_2083 = ({ int64_t _r7111; if (((recv_2074) >= (((int64_t)0LL)))) { _r7111 = ({ int64_t _r7112; if (((j_2079) == (((int64_t)0LL)))) { _r7112 = recv_2074;  } else { _r7112 = f90_kid(n_2072, ((int64_t)((int64_t)j_2079 - (int64_t)((int64_t)1LL))));  } _r7112; });  } else { _r7111 = f90_kid(n_2072, j_2079);  } _r7111; }); 
int64_t ct0_2084 = f281_fin(c_2083); 
if ((((((*({ hrv *_t7116 = &(g554); int64_t _i7116 = pt_2080; (S1*)_t7116->b + hr_ix(_i7116, _t7116->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:598"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t7117 = &(g554); int64_t _i7117 = pt_2080; (S1*)_t7117->b + hr_ix(_i7117, _t7117->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:598"); }))).c_) < (((int32_t)0LL))))) { if ((((((*({ hrv *_t7118 = &(g554); int64_t _i7118 = ct0_2084; (S1*)_t7118->b + hr_ix(_i7118, _t7118->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:599"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t7119 = &(g554); int64_t _i7119 = ct0_2084; (S1*)_t7119->b + hr_ix(_i7119, _t7119->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:599"); }))).k_) == (((uint8_t)11LL))))) { (void)(f291_gx(c_2083));
 } else { (void)(f326_gaddr(c_2083));
 }
continue;
 }
if (f270_is_res(pt_2080)) { (void)(f271_gxo(c_2083));
continue;
 }
if (((((*({ hrv *_t7124 = &(g554); int64_t _i7124 = pt_2080; (S1*)_t7124->b + hr_ix(_i7124, _t7124->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:603"); }))).k_) == (((uint8_t)9LL)))) { (void)(f293_gas(c_2083));
continue;
 }
(void)(f291_gx(c_2083));
 } } _bk7103:; 
{ hrv *_v7128 = &(g394); for (int64_t _k7128 = 0; _k7128 < _v7128->n; _k7128++) { S13 cp_2085 = ((S13*)_v7128->b)[_k7128]; if (((((int64_t)((cp_2085).inst_))) == (inst_2073))) { if ((!(first_2078))) { (void)(f262_ow(hr_str(", ", 2)));
 }
first_2078 = false;
(void)(f362_lv_addr(((int64_t)((cp_2085).lv_))));
 }
 } } _bk7127:; 
}
static void f362_lv_addr(int64_t v_2086) {
if (((((int64_t)(((*({ hrv *_t7131 = &(g391); int64_t _i7131 = v_2086; (S12*)_t7131->b + hr_ix(_i7131, _t7131->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:119"); }))).cfn_))) != (g179))) { (void)(({ hrv *_o7132 = &(g163); hr_fs(_o7132, hr_str("c", 1)); hr_fi(_o7132, v_2086); }));
return;
 }
(void)(f262_ow(hr_str("&", 1)));
(void)(f288_lv_name(v_2086));
}
static void f363_glrcheck(void) {
(void)(f262_ow(hr_str("if (HR_UNLIKELY(hr_lr)) { ", 26)));
if (((*({ hrv *_t7136 = &(g390); int64_t _i7136 = g179; (S6*)_t7136->b + hr_ix(_i7136, _t7136->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1008"); }))).tg_) { int64_t rt_2087 = ((int64_t)(((*({ hrv *_t7137 = &(g390); int64_t _i7137 = g179; (S6*)_t7137->b + hr_ix(_i7137, _t7137->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1008"); }))).ret_)); 
(void)(({ hrv *_o7138 = &(g163); hr_fs(_o7138, hr_str("if (hr_lr == ", 13)); hr_fi(_o7138, ((int64_t)((int64_t)g179 + (int64_t)((int64_t)1LL)))); hr_fs(_o7138, hr_str(") { hr_lr = 0; ", 15)); }));
if ((((rt_2087) < (((int64_t)0LL))) || ((rt_2087) == (g561)))) { (void)(f262_ow(hr_str("return; } ", 10)));
 } else { (void)(({ hrv *_o7140 = &(g163); hr_fs(_o7140, hr_str("return _lrv", 11)); hr_fi(_o7140, g179); hr_fs(_o7140, hr_str("; } ", 4)); }));
 }
 }
(void)(f356_gdummy());
(void)(f262_ow(hr_str(" } ", 3)));
}
static void f364_gen_fn(int64_t i_2102) {
int64_t node_2103 = ((int64_t)(((*({ hrv *_t7143 = &(g390); int64_t _i7143 = i_2102; (S6*)_t7143->b + hr_ix(_i7143, _t7143->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1101"); }))).node_)); 
g403 = i_2102;
g179 = i_2102;
(void)(({ hrv *_v7144 = &(g180); _v7144->n = 0; }));
(void)(({ hrv *_v7145 = &(g181); _v7145->n = 0; }));
int64_t s0_2104 = (g163).n; 
(void)(f365_gsig(i_2102));
(void)(({ hrv *_v7147 = &(g166); hsl _s7147 = ({ hsl _t7148 = hr_sl(g163); int64_t _l7148 = s0_2104, _h7148 = _t7148.n; if (_l7148 < 0 || _h7148 < _l7148 || _h7148 > _t7148.n) hr_slerr(_l7148, _h7148, _t7148.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1106"); (hsl){ _t7148.p + _l7148 * (int64_t)sizeof(uint8_t), _h7148 - _l7148 }; }); hr_append(_v7147, _s7147.p, _s7147.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v7149 = &(g166); hsl _s7149 = hr_str(";\012", 2); hr_append(_v7149, _s7149.p, _s7149.n, sizeof(uint8_t)); }));
(void)(f262_ow(hr_str(" {\012", 3)));
{ int32_t _e7152 = ((*({ hrv *_t7153 = &(g707); int64_t _i7153 = node_2103; (S4*)_t7153->b + hr_ix(_i7153, _t7153->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1108"); }))).n_; for (int32_t _k7152 = 0; _k7152 < _e7152; _k7152++) { int32_t j_2116 = (int32_t)_k7152; int64_t p_2117 = f90_kid(node_2103, ((int64_t)(j_2116))); 
int64_t v_2118 = f160_rv(p_2117); 
if (f270_is_res(f212_ptype_of(i_2102, ((int64_t)(j_2116))))) { (void)(f262_ow(hr_str("hrv ", 4)));
(void)(f288_lv_name(v_2118));
(void)(f262_ow(hr_str(" __attribute__((cleanup(hr_rdrop))) = ", 38)));
(void)(f288_lv_name(v_2118));
(void)(f262_ow(hr_str("_in;\012", 5)));
 }
 } } _bk7151:; 
int64_t body_2119 = ((int64_t)(((*({ hrv *_t7163 = &(g707); int64_t _i7163 = node_2103; (S4*)_t7163->b + hr_ix(_i7163, _t7163->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1109"); }))).c_)); 
int64_t rt_2120 = ((int64_t)(((*({ hrv *_t7164 = &(g390); int64_t _i7164 = i_2102; (S6*)_t7164->b + hr_ix(_i7164, _t7164->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1110"); }))).ret_)); 
int64_t tl_2121 = ((int64_t)(((*({ hrv *_t7165 = &(g707); int64_t _i7165 = body_2119; (S4*)_t7165->b + hr_ix(_i7165, _t7165->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1111"); }))).a_)); 
{ int32_t _e7167 = ((*({ hrv *_t7168 = &(g707); int64_t _i7168 = body_2119; (S4*)_t7168->b + hr_ix(_i7168, _t7168->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1112"); }))).n_; for (int32_t _k7167 = 0; _k7167 < _e7167; _k7167++) { int32_t q_2122 = (int32_t)_k7167; (void)(f337_gstmt(f90_kid(body_2119, ((int64_t)(q_2122)))));
 } } _bk7166:; 
if (((tl_2121) >= (((int64_t)0LL)))) { if ((((((rt_2120) >= (((int64_t)0LL))) && ((rt_2120) != (g561))) && ((f141_at(tl_2121)) != (g561))) && (!(f143_ends(tl_2121))))) { int64_t sp_2123 = (g163).n; 
int64_t td_2124 = (g176).n; 
if ((((((*({ hrv *_t7173 = &(g554); int64_t _i7173 = rt_2120; (S1*)_t7173->b + hr_ix(_i7173, _t7173->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1116"); }))).k_) == (((uint8_t)14LL))) && ((((*({ hrv *_t7174 = &(g707); int64_t _i7174 = tl_2121; (S4*)_t7174->b + hr_ix(_i7174, _t7174->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1116"); }))).k_) == (((uint8_t)11LL))))) { (void)(f262_ow(hr_str("return ", 7)));
(void)(f291_gx(tl_2121));
(void)(f262_ow(hr_str(";\012", 2)));
 } else { (void)(f262_ow(hr_str("return ", 7)));
if (f270_is_res(rt_2120)) { (void)(f354_gmove(tl_2121));
 } else { (void)(f291_gx(tl_2121));
 }
(void)(f262_ow(hr_str(";\012", 2)));
 }
if ((((g176).n) > (td_2124))) { (void)(({ hrv *_v7183 = &(g177); _v7183->n = 0; }));
(void)(({ hrv *_v7184 = &(g177); hsl _s7184 = ({ hsl _t7185 = hr_sl(g163); int64_t _l7185 = sp_2123, _h7185 = _t7185.n; if (_l7185 < 0 || _h7185 < _l7185 || _h7185 > _t7185.n) hr_slerr(_l7185, _h7185, _t7185.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1118"); (hsl){ _t7185.p + _l7185 * (int64_t)sizeof(uint8_t), _h7185 - _l7185 }; }); hr_append(_v7184, _s7184.p, _s7184.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v7186 = &(g163); int64_t _k7186 = sp_2123; if (_k7186 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1118"); hr_resize(_v7186, _k7186, sizeof(uint8_t)); }));
(void)(f262_ow(hr_str("{ ", 2)));
(void)(({ hrv *_v7188 = &(g163); hsl _s7188 = ({ hsl _t7189 = hr_sl(g176); int64_t _l7189 = td_2124, _h7189 = _t7189.n; if (_l7189 < 0 || _h7189 < _l7189 || _h7189 > _t7189.n) hr_slerr(_l7189, _h7189, _t7189.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1118"); (hsl){ _t7189.p + _l7189 * (int64_t)sizeof(uint8_t), _h7189 - _l7189 }; }); hr_append(_v7188, _s7188.p, _s7188.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v7190 = &(g176); int64_t _k7190 = td_2124; if (_k7190 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1118"); hr_resize(_v7190, _k7190, sizeof(uint8_t)); }));
(void)(({ hrv *_v7191 = &(g163); hsl _s7191 = ({ hsl _t7192 = hr_sl(g177); int64_t _l7192 = 0, _h7192 = _t7192.n; if (_l7192 < 0 || _h7192 < _l7192 || _h7192 > _t7192.n) hr_slerr(_l7192, _h7192, _t7192.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1118"); (hsl){ _t7192.p + _l7192 * (int64_t)sizeof(uint8_t), _h7192 - _l7192 }; }); hr_append(_v7191, _s7191.p, _s7191.n, sizeof(uint8_t)); }));
(void)(f262_ow(hr_str("}\012", 2)));
 }
 } else { (void)(f337_gstmt(tl_2121));
 }
 }
(void)(f262_ow(hr_str("}\012", 2)));
}
static void f365_gsig(int64_t i_2105) {
int64_t rt_2106 = ((int64_t)(((*({ hrv *_t7196 = &(g390); int64_t _i7196 = i_2105; (S6*)_t7196->b + hr_ix(_i7196, _t7196->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1080"); }))).ret_)); 
(void)(f262_ow(hr_str("static ", 7)));
if (((rt_2106) < (((int64_t)0LL)))) { (void)(f262_ow(hr_str("void", 4)));
 } else { (void)(f263_ct(rt_2106));
 }
(void)(f262_ow(hr_str(" ", 1)));
(void)(f325_fn_cname(i_2105));
(void)(f262_ow(hr_str("(", 1)));
int64_t node_2107 = ((int64_t)(((*({ hrv *_t7203 = &(g390); int64_t _i7203 = i_2105; (S6*)_t7203->b + hr_ix(_i7203, _t7203->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1084"); }))).node_)); 
bool first_2108 = true; 
int64_t sa_2109 = g403; 
g403 = i_2105;
{ int32_t _e7205 = ((*({ hrv *_t7206 = &(g707); int64_t _i7206 = node_2107; (S4*)_t7206->b + hr_ix(_i7206, _t7206->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1087"); }))).n_; for (int32_t _k7205 = 0; _k7205 < _e7205; _k7205++) { int32_t j_2110 = (int32_t)_k7205; int64_t p_2111 = f90_kid(node_2107, ((int64_t)(j_2110))); 
int64_t v_2112 = f160_rv(p_2111); 
if ((!(first_2108))) { (void)(f262_ow(hr_str(", ", 2)));
 }
first_2108 = false;
int64_t t_2113 = f212_ptype_of(i_2105, ((int64_t)(j_2110))); 
(void)(f263_ct(t_2113));
(void)(f262_ow(hr_str(" ", 1)));
(void)(f288_lv_name(v_2112));
if (f270_is_res(t_2113)) { (void)(f262_ow(hr_str("_in", 3)));
 }
 } } _bk7204:; 
g403 = sa_2109;
{ hrv *_v7217 = &(g394); for (int64_t _k7217 = 0; _k7217 < _v7217->n; _k7217++) { S13 cp_2114 = ((S13*)_v7217->b)[_k7217]; if (((((int64_t)((cp_2114).inst_))) == (i_2105))) { if ((!(first_2108))) { (void)(f262_ow(hr_str(", ", 2)));
 }
first_2108 = false;
int64_t v_2115 = ((int64_t)((cp_2114).lv_)); 
(void)(f263_ct(((int64_t)(((*({ hrv *_t7220 = &(g391); int64_t _i7220 = v_2115; (S12*)_t7220->b + hr_ix(_i7220, _t7220->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1096"); }))).ty_))));
(void)(f262_ow(({ hsl _r7222; if (f287_lv_isptr(v_2115)) { _r7222 = hr_str(" **c", 4);  } else { _r7222 = hr_str(" *c", 3);  } _r7222; })));
(void)(f296_oi(v_2115));
 }
 } } _bk7216:; 
if (first_2108) { (void)(f262_ow(hr_str("void", 4)));
 }
(void)(f262_ow(hr_str(")", 1)));
}
static void hr_init_globals(void) {
g857 = ({ A25 _t1; _t1.e[0] = hr_str("import", 6); _t1.e[1] = hr_str("namespace", 9); _t1.e[2] = hr_str("struct", 6); _t1.e[3] = hr_str("enum", 4); _t1.e[4] = hr_str("type", 4); _t1.e[5] = hr_str("fn", 2); _t1.e[6] = hr_str("thread_fn", 9); _t1.e[7] = hr_str("export", 6); _t1.e[8] = hr_str("simd", 4); _t1.e[9] = hr_str("recursive", 9); _t1.e[10] = hr_str("let", 3); _t1.e[11] = hr_str("var", 3); _t1.e[12] = hr_str("extern", 6); _t1.e[13] = hr_str("const", 5); _t1.e[14] = hr_str("pad", 3); _t1.e[15] = hr_str("reusable", 8); _t1.e[16] = hr_str("if", 2); _t1.e[17] = hr_str("else", 4); _t1.e[18] = hr_str("while", 5); _t1.e[19] = hr_str("for", 3); _t1.e[20] = hr_str("in", 2); _t1.e[21] = hr_str("loop", 4); _t1.e[22] = hr_str("block", 5); _t1.e[23] = hr_str("guard", 5); _t1.e[24] = hr_str("match", 5); _t1.e[25] = hr_str("return", 6); _t1.e[26] = hr_str("break", 5); _t1.e[27] = hr_str("continue", 8); _t1.e[28] = hr_str("as", 2); _t1.e[29] = hr_str("true", 4); _t1.e[30] = hr_str("false", 5); _t1.e[31] = hr_str("null", 4); _t1.e[32] = hr_str("self", 4); _t1.e[33] = hr_str("bool", 4); _t1.e[34] = hr_str("varint", 6); _t1.e[35] = hr_str("i8", 2); _t1.e[36] = hr_str("i16", 3); _t1.e[37] = hr_str("i32", 3); _t1.e[38] = hr_str("i64", 3); _t1.e[39] = hr_str("u8", 2); _t1.e[40] = hr_str("u16", 3); _t1.e[41] = hr_str("u32", 3); _t1.e[42] = hr_str("u64", 3); _t1.e[43] = hr_str("f32", 3); _t1.e[44] = hr_str("f64", 3); _t1.e[45] = hr_str("int", 3); _t1.e[46] = hr_str("uint", 4); _t1.e[47] = hr_str("byte", 4); _t1.e[48] = hr_str("real", 4); _t1; });
g724 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g725 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g726 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g727 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g728 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g729 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g730 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g731 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g732 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g733 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g720 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g719 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g405 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g403 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g404 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g352 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
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
g363 = ((int64_t)0LL);
g364 = ((int64_t)1LL);
g365 = ((int64_t)2LL);
g366 = ((int64_t)3LL);
g367 = ((int64_t)4LL);
g368 = ((int64_t)5LL);
g369 = ((int64_t)6LL);
g370 = ((int64_t)7LL);
g371 = ((int64_t)8LL);
g372 = ((int64_t)9LL);
g373 = ((int64_t)10LL);
g374 = ((int64_t)11LL);
g375 = ((int64_t)12LL);
g376 = ((int64_t)13LL);
g377 = ((int64_t)14LL);
g378 = ((int64_t)1LL);
g379 = ((int64_t)2LL);
g380 = ((int64_t)4LL);
g381 = ((int64_t)8LL);
g382 = ((int64_t)16LL);
g383 = ((int64_t)32LL);
g384 = ((int64_t)64LL);
g385 = ((int64_t)2LL);
g402 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g408 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g485 = ((int64_t)1LL);
g486 = ((int64_t)2LL);
g487 = ((int64_t)3LL);
g488 = ((int64_t)4LL);
g489 = ((int64_t)5LL);
g524 = ((int64_t)0LL);
g525 = ((int64_t)1LL);
g526 = ((int64_t)2LL);
g527 = ((int64_t)3LL);
g528 = ((int64_t)4LL);
g529 = ((int64_t)5LL);
g530 = ((int64_t)6LL);
g531 = ((int64_t)7LL);
g532 = ((int64_t)8LL);
g533 = ((int64_t)9LL);
g534 = ((int64_t)10LL);
g535 = ((int64_t)11LL);
g536 = ((int64_t)12LL);
g537 = ((int64_t)13LL);
g538 = ((int64_t)14LL);
g539 = ((int64_t)15LL);
g540 = ((int64_t)16LL);
g541 = ((int64_t)17LL);
g542 = ((int64_t)18LL);
g543 = ((int64_t)19LL);
g544 = ((int64_t)1LL);
g545 = ((int64_t)2LL);
g546 = ((int64_t)0LL);
g547 = ((int64_t)1LL);
g548 = ((int64_t)2LL);
g629 = ((int64_t)1LL);
g630 = ((int64_t)2LL);
g631 = ((int64_t)3LL);
g632 = ((int64_t)4LL);
g633 = ((int64_t)5LL);
g634 = ((int64_t)6LL);
g635 = ((int64_t)7LL);
g636 = ((int64_t)8LL);
g637 = ((int64_t)9LL);
g638 = ((int64_t)10LL);
g639 = ((int64_t)11LL);
g640 = ((int64_t)12LL);
g641 = ((int64_t)13LL);
g642 = ((int64_t)14LL);
g643 = ((int64_t)15LL);
g644 = ((int64_t)16LL);
g645 = ((int64_t)17LL);
g646 = ((int64_t)18LL);
g647 = ((int64_t)19LL);
g648 = ((int64_t)20LL);
g649 = ((int64_t)21LL);
g650 = ((int64_t)22LL);
g651 = ((int64_t)23LL);
g652 = ((int64_t)24LL);
g653 = ((int64_t)25LL);
g654 = ((int64_t)26LL);
g655 = ((int64_t)27LL);
g656 = ((int64_t)28LL);
g657 = ((int64_t)29LL);
g658 = ((int64_t)30LL);
g659 = ((int64_t)31LL);
g660 = ((int64_t)32LL);
g661 = ((int64_t)33LL);
g662 = ((int64_t)34LL);
g663 = ((int64_t)35LL);
g664 = ((int64_t)36LL);
g665 = ((int64_t)37LL);
g666 = ((int64_t)40LL);
g667 = ((int64_t)41LL);
g668 = ((int64_t)42LL);
g669 = ((int64_t)43LL);
g670 = ((int64_t)44LL);
g671 = ((int64_t)45LL);
g672 = ((int64_t)46LL);
g673 = ((int64_t)47LL);
g674 = ((int64_t)48LL);
g675 = ((int64_t)50LL);
g676 = ((int64_t)51LL);
g677 = ((int64_t)52LL);
g678 = ((int64_t)53LL);
g679 = ((int64_t)54LL);
g680 = ((int64_t)55LL);
g681 = ((int64_t)56LL);
g682 = ((int64_t)57LL);
g683 = ((int64_t)58LL);
g684 = ((int64_t)1LL);
g685 = ((int64_t)2LL);
g686 = ((int64_t)3LL);
g687 = ((int64_t)4LL);
g688 = ((int64_t)5LL);
g689 = ((int64_t)1LL);
g690 = ((int64_t)2LL);
g691 = ((int64_t)4LL);
g692 = ((int64_t)8LL);
g693 = ((int64_t)16LL);
g694 = ((int64_t)32LL);
g695 = ((int64_t)64LL);
g696 = ((int64_t)128LL);
g697 = ((int64_t)256LL);
g698 = ((int64_t)512LL);
g699 = ((int64_t)1LL);
g700 = ((int64_t)2LL);
g701 = ((int64_t)4LL);
g702 = ((int64_t)8LL);
g703 = ((int64_t)16LL);
g704 = ((int64_t)32LL);
g705 = ((int64_t)64LL);
g800 = ((int64_t)0LL);
g801 = ((int64_t)1LL);
g802 = ((int64_t)2LL);
g803 = ((int64_t)3LL);
g804 = ((int64_t)4LL);
g805 = ((int64_t)5LL);
g806 = ((int64_t)6LL);
g807 = ((int64_t)7LL);
g808 = ((int64_t)8LL);
g809 = ((int64_t)9LL);
g810 = ((int64_t)10LL);
g811 = ((int64_t)11LL);
g812 = ((int64_t)12LL);
g813 = ((int64_t)13LL);
g814 = ((int64_t)14LL);
g815 = ((int64_t)15LL);
g816 = ((int64_t)16LL);
g817 = ((int64_t)17LL);
g818 = ((int64_t)18LL);
g819 = ((int64_t)19LL);
g820 = ((int64_t)20LL);
g821 = ((int64_t)21LL);
g822 = ((int64_t)22LL);
g823 = ((int64_t)23LL);
g824 = ((int64_t)24LL);
g825 = ((int64_t)25LL);
g826 = ((int64_t)26LL);
g827 = ((int64_t)27LL);
g828 = ((int64_t)28LL);
g829 = ((int64_t)29LL);
g830 = ((int64_t)30LL);
g831 = ((int64_t)31LL);
g832 = ((int64_t)32LL);
g833 = ((int64_t)33LL);
g834 = ((int64_t)34LL);
g835 = ((int64_t)35LL);
g836 = ((int64_t)36LL);
g837 = ((int64_t)37LL);
g838 = ((int64_t)38LL);
g839 = ((int64_t)39LL);
g840 = ((int64_t)40LL);
g841 = ((int64_t)41LL);
g842 = ((int64_t)42LL);
g843 = ((int64_t)43LL);
g844 = ((int64_t)44LL);
g845 = ((int64_t)45LL);
g846 = ((int64_t)46LL);
g847 = ((int64_t)47LL);
g848 = ((int64_t)48LL);
g849 = ((int64_t)49LL);
g850 = ((int64_t)50LL);
g851 = ((int64_t)51LL);
g852 = ((int64_t)52LL);
g853 = ((int64_t)53LL);
g854 = ((int64_t)54LL);
g855 = ((int64_t)55LL);
g856 = ((int64_t)56LL);
g858 = ((int64_t)56LL);
g859 = ((int64_t)57LL);
g860 = ((int64_t)58LL);
g861 = ((int64_t)59LL);
g862 = ((int64_t)60LL);
g863 = ((int64_t)61LL);
g864 = ((int64_t)62LL);
g865 = ((int64_t)63LL);
g866 = ((int64_t)64LL);
g867 = ((int64_t)65LL);
g868 = ((int64_t)66LL);
g869 = ((int64_t)67LL);
g870 = ((int64_t)68LL);
g871 = ((int64_t)69LL);
g872 = ((int64_t)70LL);
g873 = ((int64_t)71LL);
g874 = ((int64_t)72LL);
g875 = ((int64_t)73LL);
g876 = ((int64_t)74LL);
g877 = ((int64_t)75LL);
g878 = ((int64_t)76LL);
g879 = ((int64_t)77LL);
g880 = ((int64_t)78LL);
g881 = ((int64_t)79LL);
g882 = ((int64_t)80LL);
g883 = ((int64_t)81LL);
g884 = ((int64_t)82LL);
g885 = ((int64_t)83LL);
g886 = ((int64_t)84LL);
g887 = ((int64_t)85LL);
g888 = ((int64_t)86LL);
g889 = ((int64_t)87LL);
g890 = ((int64_t)88LL);
g891 = ((int64_t)89LL);
g892 = ((int64_t)90LL);
g893 = ((int64_t)91LL);
g894 = ((int64_t)92LL);
g895 = ((int64_t)93LL);
g896 = ((int64_t)94LL);
g897 = ((int64_t)95LL);
g898 = ((int64_t)96LL);
g899 = ((int64_t)97LL);
g900 = ((int64_t)98LL);
g901 = ((int64_t)99LL);
g902 = ((int64_t)100LL);
g903 = ((int64_t)101LL);
g904 = ((int64_t)102LL);
g905 = ((int64_t)103LL);
g906 = ((int64_t)104LL);
g907 = ((int64_t)49LL);
}
static void hr_main(void) { f1_main(); }
