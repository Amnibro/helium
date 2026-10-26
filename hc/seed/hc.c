#include "hrt.h"
typedef struct A25 A25;
typedef struct A62 A62;
typedef struct A104 A104;
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
typedef struct M96 M96;
typedef struct L99 L99;
typedef struct L100 L100;
typedef struct L102 L102;
typedef struct L101 L101;
typedef struct L103 L103;
#pragma pack(push, 1)
struct A25 { hsl e[49]; };
struct A62 { hsl e[8]; };
struct A104 { double e[23]; };
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
struct M96 { int64_t r0; int64_t r1; int64_t r2; };
struct L99 { uint16_t n; uint8_t e[256]; };
struct L100 { uint8_t n; uint8_t e[128]; };
struct L102 { uint8_t n; uint8_t e[64]; };
struct L101 { uint8_t n; uint8_t e[32]; };
struct L103 { uint16_t n; uint8_t e[4096]; };
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
static bool f209_has_rel(int64_t t_1064);
static void f210_ck_assign(int64_t n_1072);
static void f211_decl_nested(int64_t n_1089);
static void f212_check_inst(int64_t i_1092);
static int64_t f213_ptype_of(int64_t i_1098, int64_t j_1099);
static void f214_pop_block_fns(int64_t m_1121);
static int64_t f215_ck_if(int64_t n_1124, int64_t want_1125);
static int64_t f216_ck_while(int64_t n_1135);
static int64_t f217_ck_loop(int64_t n_1139, int64_t want_1140);
static int64_t f218_ck_for(int64_t n_1142);
static bool f219_is_bytes(int64_t t_1152);
static int64_t f220_ax(int64_t n_1156);
static int64_t f221_ck_match(int64_t n_1157, int64_t want_1158);
static int64_t f222_ck_ret(int64_t n_1191);
static int64_t f223_find_from_fn(int64_t name_1193);
static int64_t f224_ret_fn(void);
static int64_t f225_ck_break(int64_t n_1206);
static int64_t f226_ck_call(int64_t n_1210, int64_t want_1211);
static int64_t f227_find_nest(int64_t name_1217);
static int64_t f228_call_nested(int64_t n_1220, int64_t nf_1221);
static int64_t f229_ck_args(int64_t n_1223, int64_t a0n_1224, int64_t first_1225);
static void f230_pop_args(int64_t s_1232);
static void f231_note_caps_of(int64_t i_1233);
static void f232_note_edge(int64_t callee_1236);
static int64_t f233_block_binding(int64_t name_1238);
static int64_t f234_blk_gen(int64_t fnode_1242);
static int64_t f235_gen_list(int64_t fnode_1243);
static bool f236_is_blockparam(int64_t fnode_1247, int64_t gname_1248);
static bool f237_mentions(int64_t t_1251, int64_t g_1252);
static int64_t f238_call_block(int64_t n_1257, int64_t inst_1258);
static int64_t f239_deref_val(int64_t a_1266);
static int64_t f240_builtin_of(hsl name_1286);
static bool f241_user_format(int64_t n_1288);
static bool f242_is_grow(int64_t t_1290);
static int64_t f243_ck_builtin(int64_t n_1291, int64_t b_1292, int64_t recv_1293, int64_t want_1294);
static int64_t f244_arg(int64_t i_1297, int64_t *c1293, int64_t *c1291);
static void f245_hook_walk(int64_t t_1303);
static int64_t f246_hook_of(int64_t t_1307);
static M96 f247_resolve(int64_t n_1311, int64_t name_1312, int64_t ns_1313, int64_t a0_1314, int64_t an_1315, int64_t blk_1316, int64_t tyargs_1317, bool report_1318);
static void f248_cands_add(int64_t name_1320, int64_t ns_1321);
static bool f249_match_ty(int64_t tn0_1350, int64_t t0_1351, int64_t g0_1352);
static int64_t f250_pend_default(int64_t a_1365);
static int64_t f251_arg_rank(int64_t n_1378, int64_t a_1379, int64_t p_1380);
static bool f252_is_construct(int64_t n_1388);
static bool f253_untyped_any(int64_t f_1391);
static bool f254_is_std_node(int64_t node_1393);
static int64_t f255_get_inst(int64_t node_1404, int64_t b0_1405, int64_t bn_1406, int64_t blk_1407, int64_t bown_1408);
static bool f256_same_binds(int64_t i_1412, int64_t b0_1413, int64_t bn_1414);
static int64_t f257_call_fn(int64_t n_1450, int64_t name_1451, int64_t recv_1452, int64_t want_1453);
static int64_t f258_member_of(hsl name_1472);
static int64_t f259_ck_slit(int64_t n_1475, int64_t want_1476);
static bool f260_ORD_HAS(int64_t d_1500);
static void f261_propagate_calls(void);
static bool f262_gen_program(hrv* out_1512);
static void f263_ow(hsl s_1516);
static void f264_ct(int64_t t_1517);
static void f265_cbody(int64_t t_1518);
static void f266_cn_grow(void);
static hsl f267_cn(int64_t t_1521);
static void f268_cn_make(int64_t t_1522);
static void f269_fwd(int64_t s0_1531);
static void f270_fname_into(hrv* b_1543, int64_t name_1544);
static bool f271_is_res(int64_t t_1564);
static void f272_gxo(int64_t n_1565);
static void f273_gcv(int64_t n_1568, int64_t f_1569, int64_t t_1570);
static void f274_gx1(int64_t n_1571);
static bool f275_is_place(int64_t n_1572);
static int64_t f276_rel_field(int64_t n_1576);
static bool f277_is_rel(int64_t t_1581);
static int64_t f278_tmp(int64_t t_1583, bool clean_1584);
static void f279_ot(int64_t k_1586);
static void f280_gx0(int64_t n_1587);
static int64_t f281_fin_lit(int64_t n_1590);
static void f282_oint(int64_t v_1592, bool uns_1593, int64_t t_1594);
static void f283_gstr(int64_t n_1597);
static int64_t f284_fin(int64_t n_1598);
static hsl f285_tok_str(int64_t t_1602);
static void f286_cstr_lit(hsl s_1606);
static bool f287_is_fix(int64_t t_1608);
static bool f288_is_lim(int64_t t_1609);
static bool f289_is_vimg(int64_t t_1610);
static void f290_vargs(int64_t t_1611);
static int64_t f291_vlim(int64_t t_1612);
static void f292_lv_expr(int64_t v_1615);
static bool f293_lv_isptr(int64_t v_1616);
static void f294_lv_name(int64_t v_1618);
static void f295_gerr(int64_t n_1620, hsl m_1621);
static void f296_gbin(int64_t n_1623);
static void f297_gx(int64_t n_1628);
static hsl f298_cmp_op(int64_t o_1635);
static void f299_gas(int64_t n_1636);
static void f300_gsl(int64_t n_1639, int64_t f_1640);
static int64_t f301_nt(void);
static void f302_oi(int64_t v_1644);
static bool f303_vok(int64_t n_1645, int64_t t_1646);
static void f304_gen_heq(int64_t t_1652);
static void f305_comp_pre(int64_t t_1656, bool fmt_1657);
static void f306_comp_one(int64_t t_1663, bool fmt_1664);
static bool f307_need_helper(int64_t t_1666);
static void f308_gen_hf(int64_t t_1668);
static void f309_hf_pre(int64_t t_1672);
static void f310_hh(hsl s_1675);
static void f311_fn_cname_to(hrv* b_1682, int64_t i_1683);
static void f312_hf_val(int64_t t_1694, hsl e_1695);
static void f313_heq_val(int64_t t_1738, hsl a_1739, hsl b_1740);
static bool f314_hsl_ty(int64_t t_1751);
static void f315_gxas(int64_t n_1752, int64_t t_1753);
static void f316_garith(int64_t o_1756, int64_t t0_1757, int64_t a_1758, int64_t b_1759, int64_t tv_1760, int64_t loc_1761);
static void f317_gopnd(int64_t n_1767, int64_t tv_1768);
static void f318_gen_hop(int64_t t_1769, int64_t o_1770, int64_t bt_1771);
static void f319_hop_body(int64_t t_1777, int64_t o_1778, hsl r_1779, hsl a_1780, hsl b_1781, bool sc_1782);
static hsl f320_ar_op(int64_t o_1784);
static void f321_wloc(int64_t n_1798);
static void f322_gun(int64_t n_1801);
static void f323_gen_hneg(int64_t t_1806);
static void f324_gidx(int64_t n_1821);
static void f325_gslice(int64_t n_1829);
static void f326_garr(int64_t n_1837);
static void f327_gslit(int64_t n_1846);
static void f328_gcall(int64_t n_1858);
static void f329_gbuiltin(int64_t n_1860);
static int64_t f330_arg(int64_t i_1866, int64_t *c1864, int64_t *c1860);
static void f331_gfmt(hsl o_1870, int64_t n_1871, int64_t t_1872, bool top_1873);
static void f332_fn_cname(int64_t i_1878);
static void f333_gaddr(int64_t n_1879);
static void f334_grecv_ptr(int64_t r_1889);
static void f335_esz(int64_t t_1903);
static void f336_gembed(int64_t n_1910, int64_t a_1911);
static void f337_heq_val_o(int64_t e_1921, int64_t p_1922);
static void f338_heq_o(int64_t e_1925, hsl a_1926, hsl b_1927);
static void f339_heq_pre(int64_t t_1928);
static bool f340_scalar_ty(int64_t t_1929);
static void f341_heq_val_s(int64_t e_1932, int64_t p_1933);
static void f342_heq_val_r(int64_t e_1936, int64_t p_1937);
static void f343_gblkcall(int64_t n_1940);
static void f344_gstmt(int64_t n_1952);
static void f345_gvdecl(int64_t n_1958);
static void f346_decl_lv(int64_t v_1966);
static void f347_gstmt1(int64_t n_1977);
static void f348_gassign(int64_t n_1980);
static void f349_grel_lv(int64_t n_1992);
static int64_t f350_base_op(int64_t o_2001);
static void f351_gif(int64_t n_2004, int64_t res_2005);
static void f352_gblk(int64_t b_2009, int64_t res_2010, bool val_2011);
static void f353_gtail(int64_t tl_2013, int64_t res_2014);
static void f354_gblk1(int64_t b_2017, int64_t res_2018, bool val_2019);
static void f355_gwhile(int64_t n_2023);
static int64_t f356_lbl_push(int64_t res_2025);
static void f357_lbl_pop(int64_t l_2028);
static void f358_gloop(int64_t n_2029, int64_t res_2030);
static void f359_gfor(int64_t n_2032);
static void f360_gmatch(int64_t n_2047, int64_t res_2048);
static void f361_geblock(int64_t n_2070, int64_t res_2071);
static void f362_gret(int64_t n_2073);
static void f363_gmove(int64_t c_2079);
static bool f364_movable_local(int64_t c_2080);
static void f365_gdummy(void);
static void f366_gvret(int64_t c_2091, int64_t rt_2092);
static void f367_gbreak(int64_t n_2093);
static bool f368_owned(int64_t n_2097);
static bool f369_is_ext(int64_t i_2101);
static void f370_ext_name(int64_t i_2106);
static void f371_gcall_args(int64_t n_2110, int64_t inst_2111, int64_t recv_2112);
static void f372_lv_addr(int64_t v_2124);
static void f373_glrcheck(void);
static void f374_gen_fn(int64_t i_2140);
static void f375_gsig(int64_t i_2143);
static hrv g510;
static hrv g928;
static A25 g871;
static hrv g929;
static hrv g926;
static int64_t g738;
static int64_t g739;
static int64_t g740;
static int64_t g741;
static int64_t g742;
static int64_t g743;
static int64_t g744;
static int64_t g745;
static int64_t g746;
static int64_t g747;
static hrv g568;
static int64_t g592;
static hrv g570;
static hrv g569;
static int64_t g575;
static int64_t g576;
static int64_t g577;
static int64_t g578;
static int64_t g579;
static int64_t g580;
static int64_t g581;
static int64_t g582;
static int64_t g583;
static int64_t g584;
static int64_t g585;
static int64_t g586;
static int64_t g587;
static int64_t g588;
static int64_t g589;
static int64_t g590;
static int64_t g591;
static int64_t g594;
static int64_t g595;
static int64_t g593;
static hrv g509;
static hrv g930;
static hrv g724;
static hrv g931;
static hrv g932;
static hrv g925;
static hrv g927;
static hrv g727;
static int64_t g726;
static int64_t g734;
static int64_t g733;
static int64_t g728;
static bool g729;
static hrv g721;
static hrv g723;
static bool g773;
static hrv g735;
static hrv g722;
static bool g730;
static bool g731;
static bool g732;
static hrv g736;
static hrv g725;
static hrv g512;
static hrv g513;
static hrv g507;
static hrv g506;
static hrv g511;
static int64_t g416;
static hrv g401;
static hrv g408;
static hrv g407;
static hrv g409;
static hrv g410;
static hrv g411;
static hrv g412;
static int64_t g414;
static int64_t g415;
static int64_t g418;
static hrv g417;
static hrv g464;
static hrv g465;
static hrv g573;
static hrv g574;
static hrv g571;
static hrv g508;
static hrv g572;
static hrv g449;
static hrv g403;
static hrv g402;
static hrv g405;
static hrv g450;
static hrv g404;
static hrv g323;
static hrv g471;
static int64_t g420;
static hrv g484;
static int64_t g494;
static hrv g421;
static hrv g327;
static hrv g406;
static hrv g361;
static hrv g362;
static int64_t g363;
static hrv g324;
static hrv g325;
static hrv g422;
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
static int64_t g195;
static hrv g182;
static hrv g166;
static hrv g169;
static hrv g246;
static hrv g249;
static hrv g196;
static hrv g180;
static hrv g181;
static hrv g177;
static hrv g168;
static A104 g114;
static hrv g154;
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
static int64_t g311;
static int64_t g312;
static int64_t g313;
static int64_t g314;
static int64_t g315;
static int64_t g316;
static int64_t g317;
static int64_t g318;
static int64_t g319;
static int64_t g320;
static int64_t g321;
static hrv g326;
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
static int64_t g386;
static int64_t g387;
static int64_t g388;
static int64_t g389;
static int64_t g390;
static int64_t g391;
static int64_t g392;
static int64_t g393;
static int64_t g394;
static int64_t g395;
static int64_t g396;
static int64_t g413;
static int64_t g419;
static int64_t g499;
static int64_t g500;
static int64_t g501;
static int64_t g502;
static int64_t g503;
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
static int64_t g549;
static int64_t g550;
static int64_t g551;
static int64_t g552;
static int64_t g553;
static int64_t g554;
static int64_t g555;
static int64_t g556;
static int64_t g557;
static int64_t g558;
static int64_t g559;
static int64_t g560;
static int64_t g561;
static int64_t g562;
static int64_t g635;
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
static int64_t g706;
static int64_t g707;
static int64_t g708;
static int64_t g709;
static int64_t g710;
static int64_t g711;
static int64_t g712;
static int64_t g713;
static int64_t g714;
static int64_t g715;
static int64_t g716;
static int64_t g717;
static int64_t g718;
static int64_t g719;
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
static int64_t g908;
static int64_t g909;
static int64_t g910;
static int64_t g911;
static int64_t g912;
static int64_t g913;
static int64_t g914;
static int64_t g915;
static int64_t g916;
static int64_t g917;
static int64_t g918;
static int64_t g919;
static int64_t g920;
static int64_t g921;
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
(void)(({ hrv *_v15 = &(g510); hsl _s15 = hr_sl(lib_2); hr_append(_v15, _s15.p, _s15.n, sizeof(uint8_t)); }));
if ((!(f5_load_program(hr_sl(a_0))))) { (void)(({ hr_fs(&hr_ob, hr_sl(g512)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((!(f104_check_program()))) { (void)(({ hr_fs(&hr_ob, hr_sl(g417)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((((g512).n) > (((int64_t)0LL)))) { (void)(({ hr_fs(&hr_ob, hr_sl(g512)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
hrv c_1511 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(f262_gen_program((&(c_1511)))))) { (void)(({ hr_fs(&hr_ob, hr_sl(g182)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((!(hr_os_write_file(hr_sl(o_1), hr_sl(c_1511))))) { (void)(({ hr_fs(&hr_ob, hr_str("cannot write ", 13)); hr_fs(&hr_ob, hr_sl(o_1)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
}
static bool f5_load_program(hsl root_3) {
(void)(f6_parse_init());
(void)(f11_types_init());
int64_t d_38 = (root_3).n; 
while ((((d_38) > (((int64_t)0LL))) && (((*({ hsl _t34 = root_3; int64_t _i34 = ((int64_t)((int64_t)d_38 - (int64_t)((int64_t)1LL))); (uint8_t*)_t34.p + hr_ix(_i34, _t34.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:68"); }))) != (((uint8_t)47LL))))) { d_38--;
 } _bk33:; 
(void)(({ hrv *_v35 = &(g509); _v35->n = 0; }));
(void)(({ hrv *_v36 = &(g509); hsl _s36 = ({ hsl _r37; if (((d_38) > (((int64_t)0LL)))) { _r37 = ({ hsl _t38 = root_3; int64_t _l38 = 0, _h38 = ((int64_t)((int64_t)d_38 - (int64_t)((int64_t)1LL))); if (_l38 < 0 || _h38 < _l38 || _h38 > _t38.n) hr_slerr(_l38, _h38, _t38.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:69"); (hsl){ _t38.p + _l38 * (int64_t)sizeof(uint8_t), _h38 - _l38 }; });  } else { _r37 = hr_str(".", 1);  } _r37; }); hr_append(_v36, _s36.p, _s36.n, sizeof(uint8_t)); }));
return (((f19_try_load(root_3)) >= (((int64_t)0LL))) && (((g512).n) == (((int64_t)0LL))));
}
static void f6_parse_init(void) {
(void)(f7_lex_init());
if (((g738) < (((int64_t)0LL)))) { g738 = f8_intern(hr_str("from", 4));
g739 = f8_intern(hr_str("inline", 6));
g740 = f8_intern(hr_str("checkfree", 9));
g741 = f8_intern(hr_str("lut", 3));
g742 = f8_intern(hr_str("_", 1));
g743 = f8_intern(hr_str("upto", 4));
g744 = f8_intern(hr_str("fields", 6));
g745 = f8_intern(hr_str("types", 5));
g746 = f8_intern(hr_str("variants", 8));
g747 = f8_intern(hr_str("std", 3));
 }
}
static void f7_lex_init(void) {
if ((((g928).n) == (((int64_t)0LL)))) { { hsl _v52 = ({ A25 *_t53 = &(g871); (hsl){ (uint8_t*)_t53->e, 49 }; }); for (int64_t _k52 = 0; _k52 < _v52.n; _k52++) { hsl k_4 = ((hsl*)_v52.p)[_k52]; (void)(f8_intern(k_4));
 } } _bk51:; 
 }
}
static int64_t f8_intern(hsl s_5) {
if ((((g929).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v55 = &(g929); int64_t _k55 = ((int64_t)((((int64_t)1LL)) << ((((int64_t)16LL)) & 63))); if (_k55 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:32"); int32_t _x55 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o55 = _v55->n; hr_resize(_v55, _k55, sizeof _x55); for (int64_t _j = _o55; _j < _k55; _j++) ((int32_t*)_v55->b)[_j] = _x55; }));
 }
if (((((int64_t)((int64_t)(g928).n * (int64_t)((int64_t)2LL)))) >= ((g929).n))) { int64_t n_6 = ((int64_t)((int64_t)(g929).n * (int64_t)((int64_t)2LL))); 
(void)(({ hrv *_v56 = &(g929); _v56->n = 0; }));
(void)(({ hrv *_v57 = &(g929); int64_t _k57 = n_6; if (_k57 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:35"); int32_t _x57 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o57 = _v57->n; hr_resize(_v57, _k57, sizeof _x57); for (int64_t _j = _o57; _j < _k57; _j++) ((int32_t*)_v57->b)[_j] = _x57; }));
{ hrv *_v59 = &(g928); for (int64_t _k59 = 0; _k59 < _v59->n; _k59++) { S0 x_7 = ((S0*)_v59->b)[_k59]; int64_t i_8 = (int64_t)_k59; int64_t j_12 = ((int64_t)((int64_t)((int64_t)(f9_hash(({ hsl _t61 = hr_sl(g926); int64_t _l61 = ((int64_t)((x_7).s_)), _h61 = ((int64_t)(((int32_t)((int64_t)(x_7).s_ + (int64_t)(x_7).n_)))); if (_l61 < 0 || _h61 < _l61 || _h61 > _t61.n) hr_slerr(_l61, _h61, _t61.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:36"); (hsl){ _t61.p + _l61 * (int64_t)sizeof(uint8_t), _h61 - _l61 }; })))) & (int64_t)((int64_t)((int64_t)n_6 - (int64_t)((int64_t)1LL))))); 
while ((((*({ hrv *_t63 = &(g929); int64_t _i63 = j_12; (int32_t*)_t63->b + hr_ix(_i63, _t63->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:36"); }))) >= (((int32_t)0LL)))) { j_12 = ((int64_t)((int64_t)((int64_t)((int64_t)j_12 + (int64_t)((int64_t)1LL))) & (int64_t)((int64_t)((int64_t)n_6 - (int64_t)((int64_t)1LL)))));
 } _bk62:; 
{ int32_t *_t64 = &((*({ hrv *_t65 = &(g929); int64_t _i65 = j_12; (int32_t*)_t65->b + hr_ix(_i65, _t65->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:36"); }))); *_t64 = ((int32_t)(i_8)); }
 } } _bk58:; 
 }
int64_t m_13 = ((int64_t)((int64_t)(g929).n - (int64_t)((int64_t)1LL))); 
int64_t j_14 = ((int64_t)((int64_t)((int64_t)(f9_hash(s_5))) & (int64_t)m_13)); 
while ((((*({ hrv *_t68 = &(g929); int64_t _i68 = j_14; (int32_t*)_t68->b + hr_ix(_i68, _t68->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:40"); }))) >= (((int32_t)0LL)))) { if (hr_streq(f10_nm(((int64_t)((*({ hrv *_t70 = &(g929); int64_t _i70 = j_14; (int32_t*)_t70->b + hr_ix(_i70, _t70->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:40"); }))))), s_5)) { return ((int64_t)((*({ hrv *_t71 = &(g929); int64_t _i71 = j_14; (int32_t*)_t71->b + hr_ix(_i71, _t71->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:40"); }))));
 }
j_14 = ((int64_t)((int64_t)((int64_t)((int64_t)j_14 + (int64_t)((int64_t)1LL))) & (int64_t)m_13));
 } _bk67:; 
int64_t id_17 = (g928).n; 
(void)(({ hrv *_v72 = &(g928); S0 _x72 = ((S0){ .s_ = ((int32_t)((g926).n)), .n_ = ((int32_t)((s_5).n)), }); S0 *_p72 = (S0*)hr_grow(_v72, 1, sizeof _x72); *_p72 = _x72; _p72; }));
(void)(({ hrv *_v73 = &(g926); hsl _s73 = s_5; hr_append(_v73, _s73.p, _s73.n, sizeof(uint8_t)); }));
{ int32_t *_t74 = &((*({ hrv *_t75 = &(g929); int64_t _i75 = j_14; (int32_t*)_t75->b + hr_ix(_i75, _t75->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:44"); }))); *_t74 = ((int32_t)(id_17)); }
return id_17;
}
static uint64_t f9_hash(hsl s_9) {
uint64_t h_10 = ((uint64_t)1469598103934665603LL); 
{ hsl _v77 = s_9; for (int64_t _k77 = 0; _k77 < _v77.n; _k77++) { uint8_t c_11 = ((uint8_t*)_v77.p)[_k77]; h_10 = ((uint64_t)((uint64_t)((uint64_t)((uint64_t)h_10 ^ (uint64_t)((uint64_t)(c_11)))) * (uint64_t)((uint64_t)1099511628211LL)));
 } } _bk76:; 
return h_10;
}
static hsl f10_nm(int64_t id_15) {
S0 x_16 = (*({ hrv *_t78 = &(g928); int64_t _i78 = id_15; (S0*)_t78->b + hr_ix(_i78, _t78->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:29"); })); 
return ({ hsl _t79 = hr_sl(g926); int64_t _l79 = ((int64_t)((x_16).s_)), _h79 = ((int64_t)(((int32_t)((int64_t)(x_16).s_ + (int64_t)(x_16).n_)))); if (_l79 < 0 || _h79 < _l79 || _h79 > _t79.n) hr_slerr(_l79, _h79, _t79.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:29"); (hsl){ _t79.p + _l79 * (int64_t)sizeof(uint8_t), _h79 - _l79 }; });
}
static void f11_types_init(void) {
if ((((g568).n) > (((int64_t)0LL)))) { return;
 }
g592 = f12_tsimple(((int64_t)0LL), ((int64_t)0LL));
g575 = f12_tsimple(((int64_t)1LL), ((int64_t)0LL));
g576 = f12_tsimple(((int64_t)2LL), ((int64_t)0LL));
g577 = f17_t_int(((int64_t)0LL));
g578 = f17_t_int(((int64_t)1LL));
g579 = f17_t_int(((int64_t)2LL));
g580 = f17_t_int(((int64_t)3LL));
g581 = f17_t_int(((int64_t)4LL));
g582 = f17_t_int(((int64_t)5LL));
g583 = f17_t_int(((int64_t)6LL));
g584 = f17_t_int(((int64_t)7LL));
g585 = f12_tsimple(((int64_t)4LL), ((int64_t)4LL));
g586 = f12_tsimple(((int64_t)4LL), ((int64_t)8LL));
g587 = f12_tsimple(((int64_t)11LL), ((int64_t)0LL));
g588 = f12_tsimple(((int64_t)12LL), ((int64_t)0LL));
g589 = f12_tsimple(((int64_t)13LL), ((int64_t)0LL));
g590 = f12_tsimple(((int64_t)18LL), ((int64_t)0LL));
g591 = f12_tsimple(((int64_t)17LL), ((int64_t)0LL));
g594 = f12_tsimple(((int64_t)19LL), ((int64_t)0LL));
g595 = f12_tsimple(((int64_t)15LL), ((int64_t)0LL));
g593 = f18_t_slice(g581, true);
}
static int64_t f12_tsimple(int64_t k_18, int64_t s_19) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(k_18)), .s_ = ((uint8_t)(s_19)), .a_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f13_tmk(S1 t_20) {
if ((((g570).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v102 = &(g570); int64_t _k102 = ((int64_t)((((int64_t)1LL)) << ((((int64_t)14LL)) & 63))); if (_k102 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:27"); int32_t _x102 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o102 = _v102->n; hr_resize(_v102, _k102, sizeof _x102); for (int64_t _j = _o102; _j < _k102; _j++) ((int32_t*)_v102->b)[_j] = _x102; }));
 }
if (((((int64_t)((int64_t)(g568).n * (int64_t)((int64_t)2LL)))) >= ((g570).n))) { int64_t n_21 = ((int64_t)((int64_t)(g570).n * (int64_t)((int64_t)2LL))); 
(void)(({ hrv *_v103 = &(g570); _v103->n = 0; }));
(void)(({ hrv *_v104 = &(g570); int64_t _k104 = n_21; if (_k104 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:29"); int32_t _x104 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o104 = _v104->n; hr_resize(_v104, _k104, sizeof _x104); for (int64_t _j = _o104; _j < _k104; _j++) ((int32_t*)_v104->b)[_j] = _x104; }));
{ hrv *_v106 = &(g568); for (int64_t _k106 = 0; _k106 < _v106->n; _k106++) { S1 x_22 = ((S1*)_v106->b)[_k106]; int64_t i_23 = (int64_t)_k106; int64_t j_29 = ((int64_t)((int64_t)((int64_t)(f14_th(x_22))) & (int64_t)((int64_t)((int64_t)n_21 - (int64_t)((int64_t)1LL))))); 
while ((((*({ hrv *_t109 = &(g570); int64_t _i109 = j_29; (int32_t*)_t109->b + hr_ix(_i109, _t109->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:30"); }))) >= (((int32_t)0LL)))) { j_29 = ((int64_t)((int64_t)((int64_t)((int64_t)j_29 + (int64_t)((int64_t)1LL))) & (int64_t)((int64_t)((int64_t)n_21 - (int64_t)((int64_t)1LL)))));
 } _bk108:; 
{ int32_t *_t110 = &((*({ hrv *_t111 = &(g570); int64_t _i111 = j_29; (int32_t*)_t111->b + hr_ix(_i111, _t111->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:30"); }))); *_t110 = ((int32_t)(i_23)); }
 } } _bk105:; 
 }
int64_t m_30 = ((int64_t)((int64_t)(g570).n - (int64_t)((int64_t)1LL))); 
int64_t j_31 = ((int64_t)((int64_t)((int64_t)(f14_th(t_20))) & (int64_t)m_30)); 
while ((((*({ hrv *_t114 = &(g570); int64_t _i114 = j_31; (int32_t*)_t114->b + hr_ix(_i114, _t114->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); }))) >= (((int32_t)0LL)))) { if (f16_teq((*({ hrv *_t116 = &(g568); int64_t _i116 = (*({ hrv *_t117 = &(g570); int64_t _i117 = j_31; (int32_t*)_t117->b + hr_ix(_i117, _t117->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); })); (S1*)_t116->b + hr_ix(_i116, _t116->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); })), t_20)) { return ((int64_t)((*({ hrv *_t118 = &(g570); int64_t _i118 = j_31; (int32_t*)_t118->b + hr_ix(_i118, _t118->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:34"); }))));
 }
j_31 = ((int64_t)((int64_t)((int64_t)((int64_t)j_31 + (int64_t)((int64_t)1LL))) & (int64_t)m_30));
 } _bk113:; 
(void)(({ hrv *_v119 = &(g568); S1 _x119 = t_20; S1 *_p119 = (S1*)hr_grow(_v119, 1, sizeof _x119); *_p119 = _x119; _p119; }));
{ int32_t *_t120 = &((*({ hrv *_t121 = &(g570); int64_t _i121 = j_31; (int32_t*)_t121->b + hr_ix(_i121, _t121->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:35"); }))); *_t120 = ((int32_t)(((int64_t)((int64_t)(g568).n - (int64_t)((int64_t)1LL))))); }
return ((int64_t)((int64_t)(g568).n - (int64_t)((int64_t)1LL)));
}
static uint64_t f14_th(S1 t_24) {
uint64_t h_27 = f15_hash_mix(((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((t_24).k_)) | (uint64_t)((uint64_t)((((uint64_t)((t_24).s_))) << ((((int64_t)8LL)) & 63))))) | (uint64_t)((uint64_t)((((uint64_t)((t_24).fl_))) << ((((int64_t)16LL)) & 63))))) | (uint64_t)((uint64_t)((((uint64_t)((t_24).a_))) << ((((int64_t)32LL)) & 63)))))); 
h_27 = f15_hash_mix(((uint64_t)((uint64_t)((uint64_t)((uint64_t)h_27 ^ (uint64_t)((uint64_t)((t_24).c_)))) ^ (uint64_t)((uint64_t)((((uint64_t)((t_24).b_))) << ((((int64_t)20LL)) & 63))))));
{ int32_t _e125 = (t_24).n_; for (int32_t _k125 = 0; _k125 < _e125; _k125++) { int32_t i_28 = (int32_t)_k125; h_27 = f15_hash_mix(((uint64_t)((uint64_t)h_27 ^ (uint64_t)((uint64_t)((*({ hrv *_t127 = &(g569); int64_t _i127 = ((int64_t)((int64_t)((int64_t)((t_24).l_)) + (int64_t)((int64_t)(i_28)))); (int32_t*)_t127->b + hr_ix(_i127, _t127->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:20"); })))))));
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
{ int32_t _e129 = (x_32).n_; for (int32_t _k129 = 0; _k129 < _e129; _k129++) { int32_t i_34 = (int32_t)_k129; if ((((*({ hrv *_t130 = &(g569); int64_t _i130 = ((int64_t)((int64_t)((int64_t)((x_32).l_)) + (int64_t)((int64_t)(i_34)))); (int32_t*)_t130->b + hr_ix(_i130, _t130->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:23"); }))) != ((*({ hrv *_t131 = &(g569); int64_t _i131 = ((int64_t)((int64_t)((int64_t)((y_33).l_)) + (int64_t)((int64_t)(i_34)))); (int32_t*)_t131->b + hr_ix(_i131, _t131->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:23"); }))))) { return false;
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
{ hrv *_v136 = &(g930); for (int64_t _k136 = 0; _k136 < _v136->n; _k136++) { S2 f_41 = ((S2*)_v136->b)[_k136]; int64_t i_42 = (int64_t)_k136; if (((((int64_t)((f_41).name_))) == (id_40))) { return i_42;
 }
 } } _bk135:; 
if ((!(hr_os_file_exists(path_39)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t t0_43 = (g724).n; 
if ((!(f21_parse_file(path_39)))) { (void)(({ hrv *_v139 = &(g512); hsl _s139 = hr_sl(g727); hr_append(_v139, _s139.p, _s139.n, sizeof(uint8_t)); }));
return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
int64_t f_439 = ((int64_t)((int64_t)(g930).n - (int64_t)((int64_t)1LL))); 
while ((((g513).n) < ((g930).n))) { (void)(({ hrv *_v141 = &(g513); int32_t _x141 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p141 = (int32_t*)hr_grow(_v141, 1, sizeof _x141); *_p141 = _x141; _p141; }));
 } _bk140:; 
{ int32_t *_t142 = &((*({ hrv *_t143 = &(g513); int64_t _i143 = f_439; (int32_t*)_t143->b + hr_ix(_i143, _t143->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:45"); }))); *_t142 = (*({ hrv *_t144 = &(g725); int64_t _i144 = ((int64_t)((int64_t)(g725).n - (int64_t)((int64_t)1LL))); (int32_t*)_t144->b + hr_ix(_i144, _t144->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:45"); })); }
(void)(f97_collect(f_439, t0_43, (g724).n));
int64_t t1_455 = (g724).n; 
int64_t im0_456 = (g511).n; 
{ int64_t _e147 = t1_455; for (int64_t _k147 = t0_43; _k147 < _e147; _k147++) { int64_t i_457 = (int64_t)_k147; if (((((*({ hrv *_t148 = &(g721); int64_t _i148 = (*({ hrv *_t149 = &(g724); int64_t _i149 = i_457; (int32_t*)_t149->b + hr_ix(_i149, _t149->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:49"); })); (S4*)_t148->b + hr_ix(_i148, _t148->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:49"); }))).k_) == (((uint8_t)54LL)))) { (void)(({ hrv *_v150 = &(g511); int32_t _x150 = (*({ hrv *_t151 = &(g724); int64_t _i151 = i_457; (int32_t*)_t151->b + hr_ix(_i151, _t151->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:49"); })); int32_t *_p150 = (int32_t*)hr_grow(_v150, 1, sizeof _x150); *_p150 = _x150; _p150; }));
 }
 } } _bk146:; 
int64_t im1_458 = (g511).n; 
L49 sp_461 = f100_lib_path(hr_str("std", 3)); 
bool isstd_462 = hr_streq(path_39, ({ hsl _t153 = ({ L49 *_t154 = &(sp_461); (hsl){ (uint8_t*)_t154->e, _t154->n }; }); int64_t _l153 = 0, _h153 = _t153.n; if (_l153 < 0 || _h153 < _l153 || _h153 > _t153.n) hr_slerr(_l153, _h153, _t153.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:51"); (hsl){ _t153.p + _l153 * (int64_t)sizeof(uint8_t), _h153 - _l153 }; })); 
if ((((*({ hrv *_t155 = &(g930); int64_t _i155 = f_439; (S2*)_t155->b + hr_ix(_i155, _t155->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:52"); }))).amni_ && (!(isstd_462)))) { if (((f101_load_import(g747, f_439, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
 }
{ int64_t _e158 = im1_458; for (int64_t _k158 = im0_456; _k158 < _e158; _k158++) { int64_t q_475 = (int64_t)_k158; int64_t n_476 = ((int64_t)((*({ hrv *_t159 = &(g511); int64_t _i159 = q_475; (int32_t*)_t159->b + hr_ix(_i159, _t159->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:53"); })))); 
if (((f101_load_import(((int64_t)(((*({ hrv *_t161 = &(g721); int64_t _i161 = n_476; (S4*)_t161->b + hr_ix(_i161, _t161->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:53"); }))).s_)), f_439, ((int64_t)(((*({ hrv *_t162 = &(g721); int64_t _i162 = n_476; (S4*)_t162->b + hr_ix(_i162, _t162->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:53"); }))).t_)))) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
 } } _bk157:; 
return f_439;
}
static bool f21_parse_file(hsl path_44) {
(void)(f6_parse_init());
int64_t t0_45 = (g931).n; 
if ((!(f22_lex_file(path_44)))) { (void)(({ hrv *_v165 = &(g727); hsl _s165 = hr_sl(g932); hr_append(_v165, _s165.p, _s165.n, sizeof(uint8_t)); }));
return false;
 }
g726 = t0_45;
g734 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
while ((((f31_tk()) != (((int64_t)0LL))) && (((g727).n) == (((int64_t)0LL))))) { (void)(f32_ptop());
 } _bk166:; 
(void)(({ hrv *_v169 = &(g725); int32_t _x169 = ((int32_t)(g734)); int32_t *_p169 = (int32_t*)hr_grow(_v169, 1, sizeof _x169); *_p169 = _x169; _p169; }));
return (((g727).n) == (((int64_t)0LL)));
}
static bool f22_lex_file(hsl path_46) {
(void)(f7_lex_init());
hrv body_47 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(hr_os_read_file(path_46, (&(body_47)))))) { (void)(({ hrv *_v173 = &(g932); hsl _s173 = hr_str("cannot read ", 12); hr_append(_v173, _s173.p, _s173.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v174 = &(g932); hsl _s174 = path_46; hr_append(_v174, _s174.p, _s174.n, sizeof(uint8_t)); }));
return false;
 }
int64_t f_48 = (g930).n; 
int64_t base_49 = (g925).n; 
int64_t skip_50 = ({ int64_t _r175; if (((((((body_47).n) >= (((int64_t)3LL))) && (((*({ hrv *_t176 = &(body_47); int64_t _i176 = ((int64_t)0LL); (uint8_t*)_t176->b + hr_ix(_i176, _t176->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:69"); }))) == (((uint8_t)239LL)))) && (((*({ hrv *_t177 = &(body_47); int64_t _i177 = ((int64_t)1LL); (uint8_t*)_t177->b + hr_ix(_i177, _t177->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:69"); }))) == (((uint8_t)187LL)))) && (((*({ hrv *_t178 = &(body_47); int64_t _i178 = ((int64_t)2LL); (uint8_t*)_t178->b + hr_ix(_i178, _t178->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:69"); }))) == (((uint8_t)191LL))))) { _r175 = ((int64_t)3LL);  } else { _r175 = ((int64_t)0LL);  } _r175; }); 
(void)(({ hrv *_v179 = &(g925); hsl _s179 = ({ hsl _t180 = hr_sl(body_47); int64_t _l180 = skip_50, _h180 = _t180.n; if (_l180 < 0 || _h180 < _l180 || _h180 > _t180.n) hr_slerr(_l180, _h180, _t180.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:70"); (hsl){ _t180.p + _l180 * (int64_t)sizeof(uint8_t), _h180 - _l180 }; }); hr_append(_v179, _s179.p, _s179.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v181 = &(g925); uint8_t _x181 = ((uint8_t)0LL); uint8_t *_p181 = (uint8_t*)hr_grow(_v181, 1, sizeof _x181); *_p181 = _x181; _p181; }));
(void)(({ hrv *_v182 = &(g925); uint8_t _x182 = ((uint8_t)0LL); uint8_t *_p182 = (uint8_t*)hr_grow(_v182, 1, sizeof _x182); *_p182 = _x182; _p182; }));
(void)(({ hrv *_v183 = &(g925); uint8_t _x183 = ((uint8_t)0LL); uint8_t *_p183 = (uint8_t*)hr_grow(_v183, 1, sizeof _x183); *_p183 = _x183; _p183; }));
(void)(({ hrv *_v184 = &(g925); uint8_t _x184 = ((uint8_t)0LL); uint8_t *_p184 = (uint8_t*)hr_grow(_v184, 1, sizeof _x184); *_p184 = _x184; _p184; }));
(void)(({ hrv *_v185 = &(g930); S2 _x185 = ((S2){ .s_ = ((int32_t)(base_49)), .n_ = ((int32_t)(((int64_t)((int64_t)(body_47).n - (int64_t)skip_50)))), .name_ = ((int32_t)(f8_intern(path_46))), .amni_ = ((((path_46).n) > (((int64_t)5LL))) && hr_streq(({ hsl _t187 = path_46; int64_t _l187 = _t187.n - ((int64_t)5LL), _h187 = _t187.n; if (_l187 < 0 || _h187 < _l187 || _h187 > _t187.n) hr_slerr(_l187, _h187, _t187.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:71"); (hsl){ _t187.p + _l187 * (int64_t)sizeof(uint8_t), _h187 - _l187 }; }), hr_str(".amni", 5))), }); S2 *_p185 = (S2*)hr_grow(_v185, 1, sizeof _x185); *_p185 = _x185; _p185; }));
bool amni_51 = ((*({ hrv *_t188 = &(g930); int64_t _i188 = f_48; (S2*)_t188->b + hr_ix(_i188, _t188->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:72"); }))).amni_; 
int64_t p_52 = base_49; 
int64_t line_53 = ((int64_t)1LL); 

for (;;) { uint8_t c_57 = (*({ hrv *_t190 = &(g925); int64_t _i190 = p_52; (uint8_t*)_t190->b + hr_ix(_i190, _t190->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:77"); })); 
while ((((((c_57) == (((uint8_t)32LL))) || ((c_57) == (((uint8_t)9LL)))) || ((c_57) == (((uint8_t)13LL)))) || ((c_57) == (((uint8_t)10LL))))) { if (((c_57) == (((uint8_t)10LL)))) { line_53++;
 }
p_52++;
c_57 = (*({ hrv *_t192 = &(g925); int64_t _i192 = p_52; (uint8_t*)_t192->b + hr_ix(_i192, _t192->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:78"); }));
 } _bk191:; 
if ((((c_57) == (((uint8_t)47LL))) && (((*({ hrv *_t193 = &(g925); int64_t _i193 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t193->b + hr_ix(_i193, _t193->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:79"); }))) == (((uint8_t)47LL))))) { while (((((*({ hrv *_t195 = &(g925); int64_t _i195 = p_52; (uint8_t*)_t195->b + hr_ix(_i195, _t195->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:79"); }))) != (((uint8_t)10LL))) && (((*({ hrv *_t196 = &(g925); int64_t _i196 = p_52; (uint8_t*)_t196->b + hr_ix(_i196, _t196->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:79"); }))) != (((uint8_t)0LL))))) { p_52++;
 } _bk194:; 
continue;
 }
if ((((c_57) == (((uint8_t)47LL))) && (((*({ hrv *_t197 = &(g925); int64_t _i197 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t197->b + hr_ix(_i197, _t197->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:80"); }))) == (((uint8_t)42LL))))) { { int64_t *_t198 = &(p_52); *_t198 = ((int64_t)((int64_t)(*_t198) + (int64_t)((int64_t)2LL))); }
int64_t nest_58 = ((int64_t)1LL); 
while (((nest_58) > (((int64_t)0LL)))) { uint8_t d_59 = (*({ hrv *_t200 = &(g925); int64_t _i200 = p_52; (uint8_t*)_t200->b + hr_ix(_i200, _t200->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:82"); })); 
if (((d_59) == (((uint8_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("unterminated /* comment", 23));
 }
if (((d_59) == (((uint8_t)10LL)))) { line_53++;
 }
if ((((d_59) == (((uint8_t)42LL))) && (((*({ hrv *_t202 = &(g925); int64_t _i202 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t202->b + hr_ix(_i202, _t202->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:82"); }))) == (((uint8_t)47LL))))) { nest_58--;
p_52++;
 } else { if ((((d_59) == (((uint8_t)47LL))) && (((*({ hrv *_t203 = &(g925); int64_t _i203 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t203->b + hr_ix(_i203, _t203->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:82"); }))) == (((uint8_t)42LL))))) { nest_58++;
p_52++;
 }
 }
p_52++;
 } _bk199:; 
continue;
 }
int64_t s_63 = p_52; 
uint8_t n1_64 = (*({ hrv *_t204 = &(g925); int64_t _i204 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t204->b + hr_ix(_i204, _t204->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:86"); })); 
uint8_t n2_65 = (*({ hrv *_t205 = &(g925); int64_t _i205 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t205->b + hr_ix(_i205, _t205->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:86"); })); 
if (((c_57) == (((uint8_t)0LL)))) { (void)(f23_put(((int64_t)0LL), s_63, s_63, &f_48, &line_53));
return true;
 }
if (f26_dig(c_57)) { if ((((c_57) == (((uint8_t)48LL))) && (((n1_64) == (((uint8_t)120LL))) || ((n1_64) == (((uint8_t)88LL)))))) { { int64_t *_t208 = &(p_52); *_t208 = ((int64_t)((int64_t)(*_t208) + (int64_t)((int64_t)2LL))); }
int64_t ds_67 = p_52; 
while (f27_hexd((*({ hrv *_t211 = &(g925); int64_t _i211 = p_52; (uint8_t*)_t211->b + hr_ix(_i211, _t211->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:90"); })))) { p_52++;
 } _bk209:; 
bool hf_69 = false; 
if (((((*({ hrv *_t212 = &(g925); int64_t _i212 = p_52; (uint8_t*)_t212->b + hr_ix(_i212, _t212->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:92"); }))) == (((uint8_t)46LL))) && f27_hexd((*({ hrv *_t214 = &(g925); int64_t _i214 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t214->b + hr_ix(_i214, _t214->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:92"); }))))) { hf_69 = true;
p_52++;
while (f27_hexd((*({ hrv *_t217 = &(g925); int64_t _i217 = p_52; (uint8_t*)_t217->b + hr_ix(_i217, _t217->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:92"); })))) { p_52++;
 } _bk215:; 
 }
if (((((*({ hrv *_t218 = &(g925); int64_t _i218 = p_52; (uint8_t*)_t218->b + hr_ix(_i218, _t218->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)112LL))) || (((*({ hrv *_t219 = &(g925); int64_t _i219 = p_52; (uint8_t*)_t219->b + hr_ix(_i219, _t219->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)80LL))))) { hf_69 = true;
p_52++;
if (((((*({ hrv *_t220 = &(g925); int64_t _i220 = p_52; (uint8_t*)_t220->b + hr_ix(_i220, _t220->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)43LL))) || (((*({ hrv *_t221 = &(g925); int64_t _i221 = p_52; (uint8_t*)_t221->b + hr_ix(_i221, _t221->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); }))) == (((uint8_t)45LL))))) { p_52++;
 }
while (f26_dig((*({ hrv *_t224 = &(g925); int64_t _i224 = p_52; (uint8_t*)_t224->b + hr_ix(_i224, _t224->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:93"); })))) { p_52++;
 } _bk222:; 
 }
if (hf_69) { (void)(f23_put(((int64_t)3LL), s_63, p_52, &f_48, &line_53));
continue;
 }
if (((((int64_t)((int64_t)p_52 - (int64_t)ds_67))) > (((int64_t)16LL)))) { return f25_lerr(f_48, line_53, hr_str("hex literal too large for 64 bits", 33));
 }
uint64_t v_70 = ((uint64_t)0LL); 
{ int64_t _e228 = p_52; for (int64_t _k228 = ds_67; _k228 < _e228; _k228++) { int64_t q_71 = (int64_t)_k228; v_70 = ((uint64_t)((uint64_t)((uint64_t)((v_70) << ((((int64_t)4LL)) & 63))) | (uint64_t)((uint64_t)(f28_hexv((*({ hrv *_t230 = &(g925); int64_t _i230 = q_71; (uint8_t*)_t230->b + hr_ix(_i230, _t230->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:96"); })))))));
 } } _bk227:; 
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t232 = &(((*({ hrv *_t233 = &(g931); int64_t _i233 = ((int64_t)((int64_t)(g931).n - (int64_t)((int64_t)1LL))); (S3*)_t233->b + hr_ix(_i233, _t233->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:97"); }))).v_); *_t232 = ((int64_t)(v_70)); }
{ bool *_t234 = &(((*({ hrv *_t235 = &(g931); int64_t _i235 = ((int64_t)((int64_t)(g931).n - (int64_t)((int64_t)1LL))); (S3*)_t235->b + hr_ix(_i235, _t235->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:97"); }))).uns_); *_t234 = ((v_70) > (((uint64_t)9223372036854775807LL))); }
continue;
 }
while (f26_dig((*({ hrv *_t238 = &(g925); int64_t _i238 = p_52; (uint8_t*)_t238->b + hr_ix(_i238, _t238->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:99"); })))) { p_52++;
 } _bk236:; 
bool fl_73 = false; 
if (((((*({ hrv *_t239 = &(g925); int64_t _i239 = p_52; (uint8_t*)_t239->b + hr_ix(_i239, _t239->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:101"); }))) == (((uint8_t)46LL))) && f26_dig((*({ hrv *_t241 = &(g925); int64_t _i241 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t241->b + hr_ix(_i241, _t241->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:101"); }))))) { fl_73 = true;
p_52++;
while (f26_dig((*({ hrv *_t244 = &(g925); int64_t _i244 = p_52; (uint8_t*)_t244->b + hr_ix(_i244, _t244->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:101"); })))) { p_52++;
 } _bk242:; 
 }
if ((((((*({ hrv *_t245 = &(g925); int64_t _i245 = p_52; (uint8_t*)_t245->b + hr_ix(_i245, _t245->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)101LL))) || (((*({ hrv *_t246 = &(g925); int64_t _i246 = p_52; (uint8_t*)_t246->b + hr_ix(_i246, _t246->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)69LL)))) && (f26_dig((*({ hrv *_t248 = &(g925); int64_t _i248 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t248->b + hr_ix(_i248, _t248->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) || (((((*({ hrv *_t249 = &(g925); int64_t _i249 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t249->b + hr_ix(_i249, _t249->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)43LL))) || (((*({ hrv *_t250 = &(g925); int64_t _i250 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t250->b + hr_ix(_i250, _t250->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))) == (((uint8_t)45LL)))) && f26_dig((*({ hrv *_t252 = &(g925); int64_t _i252 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t252->b + hr_ix(_i252, _t252->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); }))))))) { fl_73 = true;
{ int64_t *_t253 = &(p_52); *_t253 = ((int64_t)((int64_t)(*_t253) + (int64_t)((int64_t)2LL))); }
while (f26_dig((*({ hrv *_t256 = &(g925); int64_t _i256 = p_52; (uint8_t*)_t256->b + hr_ix(_i256, _t256->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:102"); })))) { p_52++;
 } _bk254:; 
 }
if (fl_73) { (void)(f23_put(((int64_t)3LL), s_63, p_52, &f_48, &line_53));
continue;
 }
uint64_t v_74 = ((uint64_t)0LL); 
{ int64_t _e259 = p_52; for (int64_t _k259 = s_63; _k259 < _e259; _k259++) { int64_t q_75 = (int64_t)_k259; uint64_t d_76 = ((uint64_t)(((uint8_t)((uint64_t)(*({ hrv *_t260 = &(g925); int64_t _i260 = q_75; (uint8_t*)_t260->b + hr_ix(_i260, _t260->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:105"); })) - (uint64_t)((uint8_t)48LL))))); 
if (((v_74) > (HR_UDIV(uint64_t, ((uint64_t)((uint64_t)((uint64_t)18446744073709551615ULL) - (uint64_t)d_76)), ((uint64_t)10LL), "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:105")))) { return f25_lerr(f_48, line_53, hr_str("integer literal too large for 64 bits", 37));
 }
v_74 = ((uint64_t)((uint64_t)((uint64_t)((uint64_t)v_74 * (uint64_t)((uint64_t)10LL))) + (uint64_t)d_76));
 } } _bk258:; 
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t263 = &(((*({ hrv *_t264 = &(g931); int64_t _i264 = ((int64_t)((int64_t)(g931).n - (int64_t)((int64_t)1LL))); (S3*)_t264->b + hr_ix(_i264, _t264->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:106"); }))).v_); *_t263 = ((int64_t)(v_74)); }
{ bool *_t265 = &(((*({ hrv *_t266 = &(g931); int64_t _i266 = ((int64_t)((int64_t)(g931).n - (int64_t)((int64_t)1LL))); (S3*)_t266->b + hr_ix(_i266, _t266->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:106"); }))).uns_); *_t265 = ((v_74) > (((uint64_t)9223372036854775807LL))); }
continue;
 }
if (f29_idc(c_57)) { while (f29_idc((*({ hrv *_t270 = &(g925); int64_t _i270 = p_52; (uint8_t*)_t270->b + hr_ix(_i270, _t270->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:109"); })))) { p_52++;
 } _bk268:; 
int64_t id_78 = f8_intern(({ hsl _t272 = hr_sl(g925); int64_t _l272 = s_63, _h272 = p_52; if (_l272 < 0 || _h272 < _l272 || _h272 > _t272.n) hr_slerr(_l272, _h272, _t272.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:110"); (hsl){ _t272.p + _l272 * (int64_t)sizeof(uint8_t), _h272 - _l272 }; })); 
int64_t k_79 = ({ int64_t _r273; if (((id_78) < (((int64_t)49LL)))) { _r273 = ((int64_t)((int64_t)((int64_t)56LL) + (int64_t)id_78));  } else { _r273 = ((int64_t)1LL);  } _r273; }); 
if (((!(amni_51)) && ((k_79) >= (((int64_t)101LL))))) { k_79 = ((int64_t)1LL);
 }
(void)(f23_put(k_79, s_63, p_52, &f_48, &line_53));
{ int64_t *_t275 = &(((*({ hrv *_t276 = &(g931); int64_t _i276 = ((int64_t)((int64_t)(g931).n - (int64_t)((int64_t)1LL))); (S3*)_t276->b + hr_ix(_i276, _t276->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:113"); }))).v_); *_t275 = id_78; }
continue;
 }
if (((c_57) == (((uint8_t)39LL)))) { p_52++;
int64_t v_86 = f30_esc((&(p_52)), f_48, line_53); 
if (((v_86) < (((int64_t)0LL)))) { return false;
 }
if ((((*({ hrv *_t278 = &(g925); int64_t _i278 = p_52; (uint8_t*)_t278->b + hr_ix(_i278, _t278->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:119"); }))) != (((uint8_t)39LL)))) { return f25_lerr(f_48, line_53, hr_str("expected closing ' of character literal", 39));
 }
p_52++;
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t281 = &(((*({ hrv *_t282 = &(g931); int64_t _i282 = ((int64_t)((int64_t)(g931).n - (int64_t)((int64_t)1LL))); (S3*)_t282->b + hr_ix(_i282, _t282->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:120"); }))).v_); *_t281 = v_86; }
continue;
 }
if (((c_57) == (((uint8_t)34LL)))) { int64_t ss_87 = (g927).n; 
bool ml_88 = false; 
if ((((n1_64) == (((uint8_t)34LL))) && ((n2_65) == (((uint8_t)34LL))))) { { int64_t *_t283 = &(p_52); *_t283 = ((int64_t)((int64_t)(*_t283) + (int64_t)((int64_t)3LL))); }
int64_t q_89 = p_52; 
while ((((((*({ hrv *_t285 = &(g925); int64_t _i285 = q_89; (uint8_t*)_t285->b + hr_ix(_i285, _t285->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:127"); }))) == (((uint8_t)32LL))) || (((*({ hrv *_t286 = &(g925); int64_t _i286 = q_89; (uint8_t*)_t286->b + hr_ix(_i286, _t286->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:127"); }))) == (((uint8_t)9LL)))) || (((*({ hrv *_t287 = &(g925); int64_t _i287 = q_89; (uint8_t*)_t287->b + hr_ix(_i287, _t287->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:127"); }))) == (((uint8_t)13LL))))) { q_89++;
 } _bk284:; 
if ((((*({ hrv *_t288 = &(g925); int64_t _i288 = q_89; (uint8_t*)_t288->b + hr_ix(_i288, _t288->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:128"); }))) != (((uint8_t)10LL)))) { while ((!((((((*({ hrv *_t290 = &(g925); int64_t _i290 = p_52; (uint8_t*)_t290->b + hr_ix(_i290, _t290->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)34LL))) && (((*({ hrv *_t291 = &(g925); int64_t _i291 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t291->b + hr_ix(_i291, _t291->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)34LL)))) && (((*({ hrv *_t292 = &(g925); int64_t _i292 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t292->b + hr_ix(_i292, _t292->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)34LL))))))) { if (((((*({ hrv *_t293 = &(g925); int64_t _i293 = p_52; (uint8_t*)_t293->b + hr_ix(_i293, _t293->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)0LL))) || (((*({ hrv *_t294 = &(g925); int64_t _i294 = p_52; (uint8_t*)_t294->b + hr_ix(_i294, _t294->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); }))) == (((uint8_t)10LL))))) { return f25_lerr(f_48, line_53, hr_str("unterminated \"\"\" string", 23));
 }
(void)(({ hrv *_v296 = &(g927); uint8_t _x296 = (*({ hrv *_t297 = &(g925); int64_t _i297 = p_52; (uint8_t*)_t297->b + hr_ix(_i297, _t297->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:129"); })); uint8_t *_p296 = (uint8_t*)hr_grow(_v296, 1, sizeof _x296); *_p296 = _x296; _p296; }));
p_52++;
 } _bk289:; 
{ int64_t *_t298 = &(p_52); *_t298 = ((int64_t)((int64_t)(*_t298) + (int64_t)((int64_t)3LL))); }
 } else { ml_88 = true;
int64_t first_90 = ((int64_t)((int64_t)q_89 + (int64_t)((int64_t)1LL))); 
int64_t close_91 = first_90; 
while ((!((((((*({ hrv *_t300 = &(g925); int64_t _i300 = close_91; (uint8_t*)_t300->b + hr_ix(_i300, _t300->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)34LL))) && (((*({ hrv *_t301 = &(g925); int64_t _i301 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)1LL))); (uint8_t*)_t301->b + hr_ix(_i301, _t301->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)34LL)))) && (((*({ hrv *_t302 = &(g925); int64_t _i302 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)2LL))); (uint8_t*)_t302->b + hr_ix(_i302, _t302->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)34LL))))))) { if ((((*({ hrv *_t303 = &(g925); int64_t _i303 = close_91; (uint8_t*)_t303->b + hr_ix(_i303, _t303->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:135"); }))) == (((uint8_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("unterminated \"\"\" string", 23));
 }
close_91++;
 } _bk299:; 
int64_t cs_92 = close_91; 
while ((((cs_92) > (first_90)) && (((*({ hrv *_t306 = &(g925); int64_t _i306 = ((int64_t)((int64_t)cs_92 - (int64_t)((int64_t)1LL))); (uint8_t*)_t306->b + hr_ix(_i306, _t306->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:136"); }))) != (((uint8_t)10LL))))) { cs_92--;
 } _bk305:; 
int64_t mg_93 = ((int64_t)((int64_t)close_91 - (int64_t)cs_92)); 
{ int64_t _e308 = close_91; for (int64_t _k308 = cs_92; _k308 < _e308; _k308++) { int64_t q2_94 = (int64_t)_k308; if (((((*({ hrv *_t309 = &(g925); int64_t _i309 = q2_94; (uint8_t*)_t309->b + hr_ix(_i309, _t309->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:138"); }))) != (((uint8_t)32LL))) && (((*({ hrv *_t310 = &(g925); int64_t _i310 = q2_94; (uint8_t*)_t310->b + hr_ix(_i310, _t310->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:138"); }))) != (((uint8_t)9LL))))) { return f25_lerr(f_48, line_53, hr_str("only indentation may come before the closing \"\"\" of a multi-line string", 71));
 }
 } } _bk307:; 
int64_t l_95 = first_90; 
while (((l_95) < (cs_92))) { int64_t e_96 = l_95; 
while ((((*({ hrv *_t314 = &(g925); int64_t _i314 = e_96; (uint8_t*)_t314->b + hr_ix(_i314, _t314->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:141"); }))) != (((uint8_t)10LL)))) { e_96++;
 } _bk313:; 
int64_t te_97 = e_96; 
if ((((te_97) > (l_95)) && (((*({ hrv *_t315 = &(g925); int64_t _i315 = ((int64_t)((int64_t)te_97 - (int64_t)((int64_t)1LL))); (uint8_t*)_t315->b + hr_ix(_i315, _t315->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:142"); }))) == (((uint8_t)13LL))))) { te_97--;
 }
if (((l_95) != (first_90))) { (void)(({ hrv *_v316 = &(g927); uint8_t _x316 = ((uint8_t)10LL); uint8_t *_p316 = (uint8_t*)hr_grow(_v316, 1, sizeof _x316); *_p316 = _x316; _p316; }));
 }
bool ok_98 = ((((int64_t)((int64_t)te_97 - (int64_t)l_95))) >= (mg_93)); 
if (ok_98) { { int64_t _e318 = mg_93; for (int64_t _k318 = 0; _k318 < _e318; _k318++) { int64_t k_99 = (int64_t)_k318; if ((((*({ hrv *_t319 = &(g925); int64_t _i319 = ((int64_t)((int64_t)l_95 + (int64_t)k_99)); (uint8_t*)_t319->b + hr_ix(_i319, _t319->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:144"); }))) != ((*({ hrv *_t320 = &(g925); int64_t _i320 = ((int64_t)((int64_t)cs_92 + (int64_t)k_99)); (uint8_t*)_t320->b + hr_ix(_i320, _t320->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:144"); }))))) { ok_98 = false;
 }
 } } _bk317:; 
 }
if (ok_98) { (void)(({ hrv *_v321 = &(g927); hsl _s321 = ({ hsl _t322 = hr_sl(g925); int64_t _l322 = ((int64_t)((int64_t)l_95 + (int64_t)mg_93)), _h322 = te_97; if (_l322 < 0 || _h322 < _l322 || _h322 > _t322.n) hr_slerr(_l322, _h322, _t322.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:145"); (hsl){ _t322.p + _l322 * (int64_t)sizeof(uint8_t), _h322 - _l322 }; }); hr_append(_v321, _s321.p, _s321.n, sizeof(uint8_t)); }));
 } else { { int64_t _e324 = te_97; for (int64_t _k324 = l_95; _k324 < _e324; _k324++) { int64_t k_100 = (int64_t)_k324; if (((((*({ hrv *_t325 = &(g925); int64_t _i325 = k_100; (uint8_t*)_t325->b + hr_ix(_i325, _t325->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:145"); }))) != (((uint8_t)32LL))) && (((*({ hrv *_t326 = &(g925); int64_t _i326 = k_100; (uint8_t*)_t326->b + hr_ix(_i326, _t326->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:145"); }))) != (((uint8_t)9LL))))) { return f25_lerr(f_48, line_53, hr_str("a line of a multi-line string must start with the indentation of its closing \"\"\"", 80));
 }
 } } _bk323:; 
 }
l_95 = ((int64_t)((int64_t)e_96 + (int64_t)((int64_t)1LL)));
 } _bk312:; 
{ int64_t _e329 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)3LL))); for (int64_t _k329 = p_52; _k329 < _e329; _k329++) { int64_t k_101 = (int64_t)_k329; if ((((*({ hrv *_t330 = &(g925); int64_t _i330 = k_101; (uint8_t*)_t330->b + hr_ix(_i330, _t330->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:148"); }))) == (((uint8_t)10LL)))) { line_53++;
 }
 } } _bk328:; 
p_52 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)3LL)));
 }
 } else { p_52++;
while ((((*({ hrv *_t332 = &(g925); int64_t _i332 = p_52; (uint8_t*)_t332->b + hr_ix(_i332, _t332->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:153"); }))) != (((uint8_t)34LL)))) { if (((((*({ hrv *_t333 = &(g925); int64_t _i333 = p_52; (uint8_t*)_t333->b + hr_ix(_i333, _t333->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:153"); }))) == (((uint8_t)10LL))) || (((*({ hrv *_t334 = &(g925); int64_t _i334 = p_52; (uint8_t*)_t334->b + hr_ix(_i334, _t334->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:153"); }))) == (((uint8_t)0LL))))) { return f25_lerr(f_48, line_53, hr_str("unterminated string literal", 27));
 }
int64_t v_102 = f30_esc((&(p_52)), f_48, line_53); 
if (((v_102) < (((int64_t)0LL)))) { return false;
 }
(void)(({ hrv *_v337 = &(g927); uint8_t _x337 = ((uint8_t)(v_102)); uint8_t *_p337 = (uint8_t*)hr_grow(_v337, 1, sizeof _x337); *_p337 = _x337; _p337; }));
 } _bk331:; 
p_52++;
 }
(void)(f23_put(((int64_t)4LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t339 = &(((*({ hrv *_t340 = &(g931); int64_t _i340 = ((int64_t)((int64_t)(g931).n - (int64_t)((int64_t)1LL))); (S3*)_t340->b + hr_ix(_i340, _t340->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:156"); }))).v_); *_t339 = ss_87; }
{ int32_t *_t341 = &(((*({ hrv *_t342 = &(g931); int64_t _i342 = ((int64_t)((int64_t)(g931).n - (int64_t)((int64_t)1LL))); (S3*)_t342->b + hr_ix(_i342, _t342->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:156"); }))).w_); *_t341 = ((int32_t)(((int64_t)((int64_t)(g927).n - (int64_t)ss_87)))); }
{ bool *_t343 = &(((*({ hrv *_t344 = &(g931); int64_t _i344 = ((int64_t)((int64_t)(g931).n - (int64_t)((int64_t)1LL))); (S3*)_t344->b + hr_ix(_i344, _t344->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:156"); }))).ml_); *_t343 = ml_88; }
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
(void)(({ hrv *_v351 = &(g931); S3 _x351 = ((S3){ .k_ = ((uint8_t)(k_54)), .f_ = ((uint16_t)((*c48))), .line_ = ((int32_t)((*c53))), .s_ = ((int32_t)(s_55)), .n_ = ((int32_t)(((int64_t)((int64_t)e_56 - (int64_t)s_55)))), }); S3 *_p351 = (S3*)hr_grow(_v351, 1, sizeof _x351); *_p351 = _x351; _p351; }));
}
static bool f25_lerr(int64_t f_60, int64_t line_61, hsl m_62) {
if ((((g932).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v352 = &(g932); hsl _s352 = f10_nm(((int64_t)(((*({ hrv *_t354 = &(g930); int64_t _i354 = f_60; (S2*)_t354->b + hr_ix(_i354, _t354->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:52"); }))).name_))); hr_append(_v352, _s352.p, _s352.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o355 = &(g932); hr_fs(_o355, hr_str(":", 1)); hr_fi(_o355, line_61); hr_fs(_o355, hr_str(": error: ", 9)); hr_fs(_o355, m_62); }));
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
uint8_t c_83 = (*({ hrv *_t358 = &(g925); int64_t _i358 = (*p_80); (uint8_t*)_t358->b + hr_ix(_i358, _t358->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:54"); })); 
(*p_80)++;
if (((c_83) != (((uint8_t)92LL)))) { return ((int64_t)(c_83));
 }
uint8_t e_84 = (*({ hrv *_t359 = &(g925); int64_t _i359 = (*p_80); (uint8_t*)_t359->b + hr_ix(_i359, _t359->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:56"); })); 
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
if (((((e_84) == (((uint8_t)120LL))) && f27_hexd((*({ hrv *_t361 = &(g925); int64_t _i361 = (*p_80); (uint8_t*)_t361->b + hr_ix(_i361, _t361->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); })))) && f27_hexd((*({ hrv *_t363 = &(g925); int64_t _i363 = ((int64_t)((int64_t)(*p_80) + (int64_t)((int64_t)1LL))); (uint8_t*)_t363->b + hr_ix(_i363, _t363->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); }))))) { int64_t v_85 = ((int64_t)((int64_t)((int64_t)((int64_t)f28_hexv((*({ hrv *_t365 = &(g925); int64_t _i365 = (*p_80); (uint8_t*)_t365->b + hr_ix(_i365, _t365->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); }))) * (int64_t)((int64_t)16LL))) + (int64_t)f28_hexv((*({ hrv *_t367 = &(g925); int64_t _i367 = ((int64_t)((int64_t)(*p_80) + (int64_t)((int64_t)1LL))); (uint8_t*)_t367->b + hr_ix(_i367, _t367->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:59"); }))))); 
{ int64_t *_t368 = p_80; *_t368 = ((int64_t)((int64_t)(*_t368) + (int64_t)((int64_t)2LL))); }
return v_85;
 }
(void)(f25_lerr(f_81, line_82, hr_str("unknown escape sequence", 23)));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f31_tk(void) {
return ((int64_t)(((*({ hrv *_t370 = &(g931); int64_t _i370 = g726; (S3*)_t370->b + hr_ix(_i370, _t370->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:32"); }))).k_));
}
static void f32_ptop(void) {
int64_t st_104 = g726; 
g733 = g734;
int64_t k_105 = f31_tk(); 
if (((k_105) == (((int64_t)57LL)))) { (void)(f33_nx());
g734 = f34_ident(hr_str("namespace declaration", 21));
g733 = g734;
(void)(f39_ex(((int64_t)12LL), hr_str("namespace declaration", 21)));
return;
 }
if (((k_105) == (((int64_t)56LL)))) { (void)(f33_nx());
int64_t n_121 = f40_mk(((int64_t)54LL), st_104); 
if (f41_is(((int64_t)16LL))) { { uint16_t *_t378 = &(((*({ hrv *_t379 = &(g721); int64_t _i379 = n_121; (S4*)_t379->b + hr_ix(_i379, _t379->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:699"); }))).fl_); *_t378 = ((uint16_t)1LL); }
 }
hrv path_123 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v381 = &(path_123); hsl _s381 = f10_nm(f34_ident(hr_str("import", 6))); hr_append(_v381, _s381.p, _s381.n, sizeof(uint8_t)); }));
while (f41_is(((int64_t)16LL))) { (void)(({ hrv *_v386 = &(path_123); uint8_t _x386 = ((uint8_t)47LL); uint8_t *_p386 = (uint8_t*)hr_grow(_v386, 1, sizeof _x386); *_p386 = _x386; _p386; }));
(void)(({ hrv *_v387 = &(path_123); hsl _s387 = f10_nm(f34_ident(hr_str("import", 6))); hr_append(_v387, _s387.p, _s387.n, sizeof(uint8_t)); }));
 } _bk384:; 
{ int64_t q__124 = f8_intern(hr_sl(path_123)); 
{ int32_t *_t391 = &(((*({ hrv *_t392 = &(g721); int64_t _i392 = n_121; (S4*)_t392->b + hr_ix(_i392, _t392->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:703"); }))).s_); *_t391 = ((int32_t)(q__124)); }
 }
if ((f42_at_from() || f43_at_word(g738))) { (void)(f33_nx());
if (((f31_tk()) != (((int64_t)4LL)))) { (void)(f38_perr(hr_str("expected the package's source, a string, after from", 51)));
 }
{ int32_t *_t398 = &(((*({ hrv *_t399 = &(g721); int64_t _i399 = n_121; (S4*)_t399->b + hr_ix(_i399, _t399->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:704"); }))).a_); *_t398 = ((int32_t)(g726)); }
(void)(f33_nx());
 }
(void)(f39_ex(((int64_t)12LL), hr_str("import", 6)));
(void)(({ hrv *_v402 = &(g724); int32_t _x402 = ((int32_t)(n_121)); int32_t *_p402 = (int32_t*)hr_grow(_v402, 1, sizeof _x402); *_p402 = _x402; _p402; }));
return;
 }
if (((f46_at_inline() || f47_at_checkfree()) || f48_at_lut())) { (void)(({ hrv *_v406 = &(g724); int32_t _x406 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p406 = (int32_t*)hr_grow(_v406, 1, sizeof _x406); *_p406 = _x406; _p406; }));
return;
 }
if (((k_105) == (((int64_t)58LL)))) { (void)(({ hrv *_v408 = &(g724); int32_t _x408 = ((int32_t)(f94_pstruct())); int32_t *_p408 = (int32_t*)hr_grow(_v408, 1, sizeof _x408); *_p408 = _x408; _p408; }));
return;
 }
if (((k_105) == (((int64_t)59LL)))) { (void)(({ hrv *_v410 = &(g724); int32_t _x410 = ((int32_t)(f96_penum())); int32_t *_p410 = (int32_t*)hr_grow(_v410, 1, sizeof _x410); *_p410 = _x410; _p410; }));
return;
 }
if (((k_105) == (((int64_t)60LL)))) { (void)(f33_nx());
int64_t n_433 = f40_mk(((int64_t)53LL), st_104); 
{ int64_t q__434 = f50_declname(hr_str("type alias", 10)); 
{ int32_t *_t415 = &(((*({ hrv *_t416 = &(g721); int64_t _i416 = n_433; (S4*)_t416->b + hr_ix(_i416, _t416->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:712"); }))).s_); *_t415 = ((int32_t)(q__434)); }
 }
{ int32_t *_t417 = &(((*({ hrv *_t418 = &(g721); int64_t _i418 = n_433; (S4*)_t418->b + hr_ix(_i418, _t418->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:712"); }))).a_); *_t417 = ((int32_t)(g733)); }
(void)(f39_ex(((int64_t)36LL), hr_str("type alias", 10)));
{ int64_t q__435 = f53_ptype(); 
{ int32_t *_t421 = &(((*({ hrv *_t422 = &(g721); int64_t _i422 = n_433; (S4*)_t422->b + hr_ix(_i422, _t422->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:712"); }))).b_); *_t421 = ((int32_t)(q__435)); }
 }
(void)(f39_ex(((int64_t)12LL), hr_str("type alias", 10)));
(void)(({ hrv *_v424 = &(g724); int32_t _x424 = ((int32_t)(n_433)); int32_t *_p424 = (int32_t*)hr_grow(_v424, 1, sizeof _x424); *_p424 = _x424; _p424; }));
return;
 }
if (((k_105) == (((int64_t)68LL)))) { (void)(f33_nx());
int64_t cs_436 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((f31_tk()) == (((int64_t)4LL)))) { cs_436 = g726;
(void)(f33_nx());
 }
if (((f31_tk()) == (((int64_t)9LL)))) { if (((cs_436) < (((int64_t)0LL)))) { (void)(f38_perr(hr_str("an extern block names the library it binds from: extern \"lib\" {", 63)));
 }
(void)(f33_nx());
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v434 = &(g724); int32_t _x434 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), cs_436))); int32_t *_p434 = (int32_t*)hr_grow(_v434, 1, sizeof _x434); *_p434 = _x434; _p434; }));
 } _bk431:; 
(void)(f39_ex(((int64_t)10LL), hr_str("extern block", 12)));
return;
 }
g726--;
if (((cs_436) >= (((int64_t)0LL)))) { g726--;
 }
(void)(({ hrv *_v437 = &(g724); int32_t _x437 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p437 = (int32_t*)hr_grow(_v437, 1, sizeof _x437); *_p437 = _x437; _p437; }));
return;
 }
if (((((((k_105) == (((int64_t)65LL))) || ((k_105) == (((int64_t)61LL)))) || ((k_105) == (((int64_t)62LL)))) || ((k_105) == (((int64_t)63LL)))) || ((k_105) == (((int64_t)64LL))))) { (void)(({ hrv *_v439 = &(g724); int32_t _x439 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p439 = (int32_t*)hr_grow(_v439, 1, sizeof _x439); *_p439 = _x439; _p439; }));
return;
 }
if ((((((k_105) == (((int64_t)71LL))) || ((k_105) == (((int64_t)66LL)))) || ((k_105) == (((int64_t)67LL)))) || ((k_105) == (((int64_t)69LL))))) { int64_t v_437 = f74_pvdecl(true); 
(void)(f39_ex(((int64_t)12LL), hr_str("global declaration", 18)));
(void)(({ hrv *_v443 = &(g724); int32_t _x443 = ((int32_t)(v_437)); int32_t *_p443 = (int32_t*)hr_grow(_v443, 1, sizeof _x443); *_p443 = _x443; _p443; }));
return;
 }
hrv m_438 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o445 = &(m_438); hr_fs(_o445, hr_str("top-level declaration expected, found '", 39)); hr_fs(_o445, f35_cur_text()); hr_fs(_o445, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_438)));
}
static void f33_nx(void) {
if (((((*({ hrv *_t448 = &(g931); int64_t _i448 = g726; (S3*)_t448->b + hr_ix(_i448, _t448->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:34"); }))).k_) != (((uint8_t)0LL)))) { g726++;
 }
}
static int64_t f34_ident(hsl ctx_106) {
if (((f31_tk()) != (((int64_t)1LL)))) { hrv m_107 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o451 = &(m_107); hr_fs(_o451, hr_str("expected identifier in ", 23)); hr_fs(_o451, ctx_106); hr_fs(_o451, hr_str(", found '", 9)); hr_fs(_o451, f35_cur_text()); hr_fs(_o451, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_107)));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t v_115 = ((int64_t)(((*({ hrv *_t454 = &(g931); int64_t _i454 = g726; (S3*)_t454->b + hr_ix(_i454, _t454->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:51"); }))).v_)); 
(void)(f33_nx());
return v_115;
}
static hsl f35_cur_text(void) {
int64_t k_108 = f31_tk(); 
return ({ hsl _r457; if (((((k_108) == (((int64_t)1LL))) || ((k_108) == (((int64_t)2LL)))) || ((k_108) == (((int64_t)3LL))))) { _r457 = f36_tok_text(g726);  } else { _r457 = f37_tname(k_108);  } _r457; });
}
static hsl f36_tok_text(int64_t t_109) {
S3 x_110 = (*({ hrv *_t460 = &(g931); int64_t _i460 = t_109; (S3*)_t460->b + hr_ix(_i460, _t460->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:181"); })); 
return ({ hsl _t461 = hr_sl(g925); int64_t _l461 = ((int64_t)((x_110).s_)), _h461 = ((int64_t)(((int32_t)((int64_t)(x_110).s_ + (int64_t)(x_110).n_)))); if (_l461 < 0 || _h461 < _l461 || _h461 > _t461.n) hr_slerr(_l461, _h461, _t461.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:181"); (hsl){ _t461.p + _l461 * (int64_t)sizeof(uint8_t), _h461 - _l461 }; });
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
if (((g728) > (((int64_t)0LL)))) { g729 = true;
g726 = ((int64_t)((int64_t)(g931).n - (int64_t)((int64_t)1LL)));
return;
 }
if ((((g727).n) > (((int64_t)0LL)))) { return;
 }
S3 t_114 = (*({ hrv *_t465 = &(g931); int64_t _i465 = g726; (S3*)_t465->b + hr_ix(_i465, _t465->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:45"); })); 
(void)(({ hrv *_v466 = &(g727); hsl _s466 = f10_nm(((int64_t)(((*({ hrv *_t468 = &(g930); int64_t _i468 = (t_114).f_; (S2*)_t468->b + hr_ix(_i468, _t468->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:46"); }))).name_))); hr_append(_v466, _s466.p, _s466.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o469 = &(g727); hr_fs(_o469, hr_str(":", 1)); hr_fi(_o469, (t_114).line_); hr_fs(_o469, hr_str(": error: ", 9)); hr_fs(_o469, m_113); }));
g726 = ((int64_t)((int64_t)(g931).n - (int64_t)((int64_t)1LL)));
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
(void)(({ hrv *_v477 = &(g721); S4 _x477 = ((S4){ .k_ = ((uint8_t)(k_119)), .t_ = ((int32_t)(t_120)), .a_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .b_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .d_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .e_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .s_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .l_ = ((int32_t)0LL), .n_ = ((int32_t)0LL), }); S4 *_p477 = (S4*)hr_grow(_v477, 1, sizeof _x477); *_p477 = _x477; _p477; }));
return ((int64_t)((int64_t)(g721).n - (int64_t)((int64_t)1LL)));
}
static bool f41_is(int64_t k_122) {
if (((f31_tk()) == (k_122))) { (void)(f33_nx());
return true;
 }
return false;
}
static bool f42_at_from(void) {
return (f43_at_word(g738) && (((f44_tkat(((int64_t)((int64_t)g726 + (int64_t)((int64_t)1LL))))) == (((int64_t)1LL))) || ((f44_tkat(((int64_t)((int64_t)g726 + (int64_t)((int64_t)1LL))))) == (((int64_t)15LL)))));
}
static bool f43_at_word(int64_t w_125) {
return (((f31_tk()) == (((int64_t)1LL))) && ((((*({ hrv *_t484 = &(g931); int64_t _i484 = g726; (S3*)_t484->b + hr_ix(_i484, _t484->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:69"); }))).v_) == (w_125)));
}
static int64_t f44_tkat(int64_t i_126) {
return ((int64_t)(((*({ hrv *_t485 = &(g931); int64_t _i485 = f45_min(i_126, ((int64_t)((int64_t)(g931).n - (int64_t)((int64_t)1LL)))); (S3*)_t485->b + hr_ix(_i485, _t485->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:33"); }))).k_));
}
static int64_t f45_min(int64_t a_127, int64_t b_128) {
if (((b_128) < (a_127))) { return b_128;
 }
return a_127;
}
static bool f46_at_inline(void) {
return (f43_at_word(g739) && ((((f44_tkat(((int64_t)((int64_t)g726 + (int64_t)((int64_t)1LL))))) == (((int64_t)61LL))) || ((f44_tkat(((int64_t)((int64_t)g726 + (int64_t)((int64_t)1LL))))) == (((int64_t)65LL)))) || ((f44_tkat(((int64_t)((int64_t)g726 + (int64_t)((int64_t)1LL))))) == (((int64_t)62LL)))));
}
static bool f47_at_checkfree(void) {
int64_t n_129 = f44_tkat(((int64_t)((int64_t)g726 + (int64_t)((int64_t)1LL)))); 
return (f43_at_word(g740) && (((((((n_129) == (((int64_t)61LL))) || ((n_129) == (((int64_t)65LL)))) || ((n_129) == (((int64_t)62LL)))) || ((n_129) == (((int64_t)64LL)))) || ((n_129) == (((int64_t)68LL)))) || ((n_129) == (((int64_t)1LL)))));
}
static bool f48_at_lut(void) {
return (f43_at_word(g741) && ((f44_tkat(((int64_t)((int64_t)g726 + (int64_t)((int64_t)1LL))))) == (((int64_t)61LL))));
}
static int64_t f49_pfn(bool nested_130, int64_t cname_131, int64_t dylib_132) {
int64_t st_133 = g726; 
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
if (((f31_tk()) == (((int64_t)4LL)))) { cn_136 = g726;
(void)(f33_nx());
 }
 }
if (f41_is(((int64_t)68LL))) { { int64_t *_t509 = &(fl_135); *_t509 = ((int64_t)((int64_t)(*_t509) | (int64_t)((int64_t)1LL))); }
if (((f31_tk()) == (((int64_t)4LL)))) { cn_136 = g726;
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
{ int32_t *_t528 = &(((*({ hrv *_t529 = &(g721); int64_t _i529 = n_134; (S4*)_t529->b + hr_ix(_i529, _t529->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:657"); }))).s_); *_t528 = ((int32_t)(q__139)); }
 }
{ int32_t *_t530 = &(((*({ hrv *_t531 = &(g721); int64_t _i531 = n_134; (S4*)_t531->b + hr_ix(_i531, _t531->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:658"); }))).a_); *_t530 = ((int32_t)(g733)); }
{ int64_t q__403 = f51_pgenerics(); 
{ int32_t *_t533 = &(((*({ hrv *_t534 = &(g721); int64_t _i534 = n_134; (S4*)_t534->b + hr_ix(_i534, _t534->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:659"); }))).d_); *_t533 = ((int32_t)(q__403)); }
 }
(void)(f39_ex(((int64_t)5LL), hr_str("function declaration", 20)));
int64_t m_404 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t p_405 = f40_mk(((int64_t)32LL), g726); 
if (f41_is(((int64_t)67LL))) { { uint16_t *_t542 = &(((*({ hrv *_t543 = &(g721); int64_t _i543 = p_405; (S4*)_t543->b + hr_ix(_i543, _t543->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:664"); }))).fl_); *_t542 = ((uint16_t)1LL); }
 }
{ int64_t q__406 = f34_ident(hr_str("parameter list", 14)); 
{ int32_t *_t545 = &(((*({ hrv *_t546 = &(g721); int64_t _i546 = p_405; (S4*)_t546->b + hr_ix(_i546, _t546->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:665"); }))).s_); *_t545 = ((int32_t)(q__406)); }
 }
if ((f41_is(((int64_t)13LL)) || f75_amni_type())) { { int64_t q__407 = f53_ptype(); 
{ int32_t *_t550 = &(((*({ hrv *_t551 = &(g721); int64_t _i551 = p_405; (S4*)_t551->b + hr_ix(_i551, _t551->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:666"); }))).a_); *_t550 = ((int32_t)(q__407)); }
 }
 }
if (f41_is(((int64_t)36LL))) { { int64_t q__408 = f61_pexpr(); 
{ int32_t *_t554 = &(((*({ hrv *_t555 = &(g721); int64_t _i555 = p_405; (S4*)_t555->b + hr_ix(_i555, _t555->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:667"); }))).b_); *_t554 = ((int32_t)(q__408)); }
 }
 }
(void)(({ hrv *_v556 = &(g723); int32_t _x556 = ((int32_t)(p_405)); int32_t *_p556 = (int32_t*)hr_grow(_v556, 1, sizeof _x556); *_p556 = _x556; _p556; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk537; }
 }
 } _bk537:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function declaration", 20)));
(void)(f59_setl(n_134, m_404));
if ((f41_is(((int64_t)54LL)) || f75_amni_type())) { { int64_t *_t562 = &(fl_135); *_t562 = ((int64_t)((int64_t)(*_t562) | (int64_t)((int64_t)512LL))); }
int64_t r_409 = f40_mk(((int64_t)36LL), g726); 
int64_t m2_410 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v566 = &(g723); int32_t _x566 = ((int32_t)(f53_ptype())); int32_t *_p566 = (int32_t*)hr_grow(_v566, 1, sizeof _x566); *_p566 = _x566; _p566; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk565; }
 }
 } _bk565:; 
(void)(f59_setl(r_409, m2_410));
{ int32_t *_t570 = &(((*({ hrv *_t571 = &(g721); int64_t _i571 = n_134; (S4*)_t571->b + hr_ix(_i571, _t571->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:677"); }))).b_); *_t570 = ((int32_t)(r_409)); }
 }
if (((((int64_t)((int64_t)fl_135 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)))) { if (f41_is(((int64_t)36LL))) { if (((f31_tk()) != (((int64_t)4LL)))) { (void)(f38_perr(hr_str("an extern fn's symbol is a string: fn name(...) = \"symbol\"; (\302\2477.10)", 68)));
 }
cn_136 = g726;
(void)(f33_nx());
 }
(void)(f39_ex(((int64_t)12LL), hr_str("extern declaration", 18)));
int64_t x_411 = f40_mk(((int64_t)58LL), st_133); 
{ int32_t *_t578 = &(((*({ hrv *_t579 = &(g721); int64_t _i579 = x_411; (S4*)_t579->b + hr_ix(_i579, _t579->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:682"); }))).a_); *_t578 = ((int32_t)(cn_136)); }
{ int32_t *_t580 = &(((*({ hrv *_t581 = &(g721); int64_t _i581 = x_411; (S4*)_t581->b + hr_ix(_i581, _t581->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:682"); }))).b_); *_t580 = ((int32_t)(dylib_132)); }
{ int32_t *_t582 = &(((*({ hrv *_t583 = &(g721); int64_t _i583 = n_134; (S4*)_t583->b + hr_ix(_i583, _t583->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:682"); }))).e_); *_t582 = ((int32_t)(x_411)); }
 } else { if (((((int64_t)((int64_t)fl_135 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { int64_t x_412 = f40_mk(((int64_t)58LL), st_133); 
{ int32_t *_t585 = &(((*({ hrv *_t586 = &(g721); int64_t _i586 = x_412; (S4*)_t586->b + hr_ix(_i586, _t586->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:684"); }))).a_); *_t585 = ((int32_t)(cn_136)); }
{ int32_t *_t587 = &(((*({ hrv *_t588 = &(g721); int64_t _i588 = n_134; (S4*)_t588->b + hr_ix(_i588, _t588->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:684"); }))).e_); *_t587 = ((int32_t)(x_412)); }
 }
{ int64_t q__413 = f66_pblock(hr_str("function body", 13)); 
{ int32_t *_t590 = &(((*({ hrv *_t591 = &(g721); int64_t _i591 = n_134; (S4*)_t591->b + hr_ix(_i591, _t591->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:685"); }))).c_); *_t590 = ((int32_t)(q__413)); }
 }
 }
{ uint16_t *_t592 = &(((*({ hrv *_t593 = &(g721); int64_t _i593 = n_134; (S4*)_t593->b + hr_ix(_i593, _t593->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:687"); }))).fl_); *_t592 = ((uint16_t)(fl_135)); }
(void)(f88_set_end(n_134));
return n_134;
}
static int64_t f50_declname(hsl ctx_137) {
int64_t a_138 = ({ int64_t _r595; if (((f31_tk()) == (((int64_t)15LL)))) { _r595 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r595 = f34_ident(ctx_137);  } _r595; }); 
if (f41_is(((int64_t)15LL))) { g733 = a_138;
return f34_ident(ctx_137);
 }
return a_138;
}
static int64_t f51_pgenerics(void) {
if ((!(f41_is(((int64_t)39LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t l_140 = f40_mk(((int64_t)36LL), g726); 
int64_t m_141 = f52_wbeg(); 
for (;;) { int64_t g_142 = f40_mk(((int64_t)57LL), g726); 
{ int64_t q__143 = f34_ident(hr_str("generic parameter list", 22)); 
{ int32_t *_t606 = &(((*({ hrv *_t607 = &(g721); int64_t _i607 = g_142; (S4*)_t607->b + hr_ix(_i607, _t607->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:587"); }))).s_); *_t606 = ((int32_t)(q__143)); }
 }
if (f41_is(((int64_t)13LL))) { { int64_t q__402 = f53_ptype(); 
{ int32_t *_t610 = &(((*({ hrv *_t611 = &(g721); int64_t _i611 = g_142; (S4*)_t611->b + hr_ix(_i611, _t611->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:588"); }))).a_); *_t610 = ((int32_t)(q__402)); }
 }
 }
(void)(({ hrv *_v612 = &(g723); int32_t _x612 = ((int32_t)(g_142)); int32_t *_p612 = (int32_t*)hr_grow(_v612, 1, sizeof _x612); *_p612 = _x612; _p612; }));
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
return (g723).n;
}
static int64_t f53_ptype(void) {
bool cq_144 = f41_is(((int64_t)69LL)); 
int64_t t_175 = f54_ptype_prim(); 
bool q_176 = cq_144; 
for (;;) { int64_t st_177 = g726; 
if (f41_is(((int64_t)7LL))) { if (f41_is(((int64_t)13LL))) { (void)(f39_ex(((int64_t)8LL), hr_str("slice type", 10)));
int64_t n_178 = f40_mk(((int64_t)43LL), st_177); 
{ int32_t *_t625 = &(((*({ hrv *_t626 = &(g721); int64_t _i626 = n_178; (S4*)_t626->b + hr_ix(_i626, _t626->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:84"); }))).a_); *_t625 = ((int32_t)(t_175)); }
if (q_176) { { uint16_t *_t627 = &(((*({ hrv *_t628 = &(g721); int64_t _i628 = n_178; (S4*)_t628->b + hr_ix(_i628, _t628->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:84"); }))).fl_); *_t627 = ((uint16_t)1LL); }
q_176 = false;
 }
t_175 = n_178;
continue;
 }
int64_t n_179 = f40_mk(((int64_t)42LL), st_177); 
{ int32_t *_t630 = &(((*({ hrv *_t631 = &(g721); int64_t _i631 = n_179; (S4*)_t631->b + hr_ix(_i631, _t631->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:85"); }))).a_); *_t630 = ((int32_t)(t_175)); }
if (f41_is(((int64_t)8LL))) { { uint8_t *_t633 = &(((*({ hrv *_t634 = &(g721); int64_t _i634 = n_179; (S4*)_t634->b + hr_ix(_i634, _t634->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:86"); }))).op_); *_t633 = ((uint8_t)(((uint8_t)2LL))); }
t_175 = n_179;
continue;
 }
if (f41_is(((int64_t)17LL))) { { uint8_t *_t636 = &(((*({ hrv *_t637 = &(g721); int64_t _i637 = n_179; (S4*)_t637->b + hr_ix(_i637, _t637->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:87"); }))).op_); *_t636 = ((uint8_t)(((uint8_t)3LL))); }
if (((f31_tk()) != (((int64_t)8LL)))) { { int64_t q__391 = f61_pexpr(); 
{ int32_t *_t640 = &(((*({ hrv *_t641 = &(g721); int64_t _i641 = n_179; (S4*)_t641->b + hr_ix(_i641, _t641->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:87"); }))).b_); *_t640 = ((int32_t)(q__391)); }
 }
 }
 } else { if (f41_is(((int64_t)40LL))) { (void)(f39_ex(((int64_t)17LL), hr_str("resizable array type", 20)));
{ uint8_t *_t644 = &(((*({ hrv *_t645 = &(g721); int64_t _i645 = n_179; (S4*)_t645->b + hr_ix(_i645, _t645->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:88"); }))).op_); *_t644 = ({ uint8_t _r646; if (f41_is(((int64_t)39LL))) { _r646 = ((uint8_t)(((uint8_t)5LL)));  } else { _r646 = ((uint8_t)(((uint8_t)4LL)));  } _r646; }); }
 } else { if (f55_prim_tok(f31_tk())) { { uint8_t *_t650 = &(((*({ hrv *_t651 = &(g721); int64_t _i651 = n_179; (S4*)_t651->b + hr_ix(_i651, _t651->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:89"); }))).op_); *_t650 = ((uint8_t)(((uint8_t)2LL))); }
{ int64_t q__393 = f93_lenstore(); 
{ int32_t *_t653 = &(((*({ hrv *_t654 = &(g721); int64_t _i654 = n_179; (S4*)_t654->b + hr_ix(_i654, _t654->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:89"); }))).c_); *_t653 = ((int32_t)(q__393)); }
 }
 } else { { uint8_t *_t655 = &(((*({ hrv *_t656 = &(g721); int64_t _i656 = n_179; (S4*)_t656->b + hr_ix(_i656, _t656->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:90"); }))).op_); *_t655 = ((uint8_t)(((uint8_t)1LL))); }
{ int64_t q__394 = f61_pexpr(); 
{ int32_t *_t658 = &(((*({ hrv *_t659 = &(g721); int64_t _i659 = n_179; (S4*)_t659->b + hr_ix(_i659, _t659->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:90"); }))).b_); *_t658 = ((int32_t)(q__394)); }
 }
 }
 }
 }
(void)(f39_ex(((int64_t)8LL), hr_str("array type", 10)));
t_175 = n_179;
continue;
 }
if (f41_is(((int64_t)49LL))) { int64_t n_395 = f40_mk(((int64_t)44LL), st_177); 
{ int32_t *_t663 = &(((*({ hrv *_t664 = &(g721); int64_t _i664 = n_395; (S4*)_t664->b + hr_ix(_i664, _t664->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:95"); }))).a_); *_t663 = ((int32_t)(t_175)); }
if (q_176) { { uint16_t *_t665 = &(((*({ hrv *_t666 = &(g721); int64_t _i666 = n_395; (S4*)_t666->b + hr_ix(_i666, _t666->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:95"); }))).fl_); *_t665 = ((uint16_t)1LL); }
q_176 = false;
 }
if (f41_is(((int64_t)39LL))) { { int64_t q__396 = f93_lenstore(); 
{ int32_t *_t669 = &(((*({ hrv *_t670 = &(g721); int64_t _i670 = n_395; (S4*)_t670->b + hr_ix(_i670, _t670->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:96"); }))).c_); *_t669 = ((int32_t)(q__396)); }
 }
if (f41_is(((int64_t)76LL))) { { int64_t q__397 = f56_qname(hr_str("relative reference pool", 23)); 
{ int32_t *_t673 = &(((*({ hrv *_t674 = &(g721); int64_t _i674 = n_395; (S4*)_t674->b + hr_ix(_i674, _t674->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:96"); }))).s_); *_t673 = ((int32_t)(q__397)); }
 }
 }
(void)(f58_close_angle(hr_str("relative reference width", 24)));
 }
t_175 = n_395;
continue;
 }
if (f41_is(((int64_t)14LL))) { if (((((*({ hrv *_t677 = &(g721); int64_t _i677 = t_175; (S4*)_t677->b + hr_ix(_i677, _t677->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).k_) == (((uint8_t)44LL)))) { { uint16_t *_t678 = &(((*({ hrv *_t679 = &(g721); int64_t _i679 = t_175; (S4*)_t679->b + hr_ix(_i679, _t679->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).fl_); *_t678 = ((uint16_t)((uint64_t)(*_t678) | (uint64_t)((uint16_t)2LL))); }
 } else { int64_t n_398 = f40_mk(((int64_t)44LL), st_177); 
{ int32_t *_t681 = &(((*({ hrv *_t682 = &(g721); int64_t _i682 = n_398; (S4*)_t682->b + hr_ix(_i682, _t682->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).a_); *_t681 = ((int32_t)(t_175)); }
{ uint16_t *_t683 = &(((*({ hrv *_t684 = &(g721); int64_t _i684 = n_398; (S4*)_t684->b + hr_ix(_i684, _t684->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).fl_); *_t683 = ((uint16_t)2LL); }
if (q_176) { { uint16_t *_t685 = &(((*({ hrv *_t686 = &(g721); int64_t _i686 = n_398; (S4*)_t686->b + hr_ix(_i686, _t686->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:100"); }))).fl_); *_t685 = ((uint16_t)((uint64_t)(*_t685) | (uint64_t)((uint16_t)1LL))); }
q_176 = false;
 }
t_175 = n_398;
 }
continue;
 }
if (((f31_tk()) == (((int64_t)17LL)))) { (void)(f33_nx());
if (((((*({ hrv *_t689 = &(g721); int64_t _i689 = t_175; (S4*)_t689->b + hr_ix(_i689, _t689->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:103"); }))).k_) == (((uint8_t)41LL)))) { { uint16_t *_t690 = &(((*({ hrv *_t691 = &(g721); int64_t _i691 = t_175; (S4*)_t691->b + hr_ix(_i691, _t691->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:103"); }))).fl_); *_t690 = ((uint16_t)((uint64_t)(*_t690) | (uint64_t)((uint16_t)1LL))); }
 } else { (void)(f38_perr(hr_str("variable mode (..) applies only to ADT type names", 49)));
 }
continue;
 }
if (f41_is(((int64_t)16LL))) { int64_t n_399 = f40_mk(((int64_t)46LL), st_177); 
{ int32_t *_t695 = &(((*({ hrv *_t696 = &(g721); int64_t _i696 = n_399; (S4*)_t696->b + hr_ix(_i696, _t696->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:104"); }))).a_); *_t695 = ((int32_t)(t_175)); }
{ int64_t q__400 = f34_ident(hr_str("variant type", 12)); 
{ int32_t *_t698 = &(((*({ hrv *_t699 = &(g721); int64_t _i699 = n_399; (S4*)_t699->b + hr_ix(_i699, _t699->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:104"); }))).s_); *_t698 = ((int32_t)(q__400)); }
 }
t_175 = n_399;
continue;
 }
if (q_176) { int64_t n_401 = f40_mk(((int64_t)48LL), st_177); 
{ int32_t *_t701 = &(((*({ hrv *_t702 = &(g721); int64_t _i702 = n_401; (S4*)_t702->b + hr_ix(_i702, _t702->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:105"); }))).a_); *_t701 = ((int32_t)(t_175)); }
t_175 = n_401;
 }
return t_175;
 } _bk620:; 
}
static int64_t f54_ptype_prim(void) {
int64_t st_145 = g726; 
int64_t k_146 = f31_tk(); 
if (f55_prim_tok(k_146)) { (void)(f33_nx());
bool up_148 = f43_at_word(g743); 
if (((((((((k_146) >= (((int64_t)91LL))) && ((k_146) <= (((int64_t)98LL)))) || ((k_146) == (((int64_t)103LL)))) || ((k_146) == (((int64_t)102LL)))) || ((k_146) == (((int64_t)101LL)))) && (!(g773))) && (((f31_tk()) == (((int64_t)76LL))) || up_148))) { (void)(f33_nx());
int64_t n_149 = f40_mk(((int64_t)47LL), st_145); 
{ uint8_t *_t710 = &(((*({ hrv *_t711 = &(g721); int64_t _i711 = n_149; (S4*)_t711->b + hr_ix(_i711, _t711->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:116"); }))).op_); *_t710 = ((uint8_t)(k_146)); }
{ uint16_t *_t712 = &(((*({ hrv *_t713 = &(g721); int64_t _i713 = n_149; (S4*)_t713->b + hr_ix(_i713, _t713->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:116"); }))).fl_); *_t712 = ({ uint16_t _r714; if (up_148) { _r714 = ((uint16_t)1LL);  } else { _r714 = ((uint16_t)0LL);  } _r714; }); }
{ int64_t q__155 = f56_qname(hr_str("index type", 10)); 
{ int32_t *_t716 = &(((*({ hrv *_t717 = &(g721); int64_t _i717 = n_149; (S4*)_t717->b + hr_ix(_i717, _t717->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:116"); }))).s_); *_t716 = ((int32_t)(q__155)); }
 }
return n_149;
 }
int64_t n_156 = f40_mk(((int64_t)40LL), st_145); 
{ uint8_t *_t719 = &(((*({ hrv *_t720 = &(g721); int64_t _i720 = n_156; (S4*)_t720->b + hr_ix(_i720, _t720->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:118"); }))).op_); *_t719 = ((uint8_t)(k_146)); }
return n_156;
 }
if ((((k_146) == (((int64_t)1LL))) || ((k_146) == (((int64_t)15LL))))) { int64_t n_157 = f40_mk(((int64_t)41LL), st_145); 
{ int64_t q__158 = f56_qname(hr_str("type", 4)); 
{ int32_t *_t723 = &(((*({ hrv *_t724 = &(g721); int64_t _i724 = n_157; (S4*)_t724->b + hr_ix(_i724, _t724->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:121"); }))).s_); *_t723 = ((int32_t)(q__158)); }
 }
if (f41_is(((int64_t)39LL))) { int64_t m_159 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v728 = &(g723); int32_t _x728 = ((int32_t)(f53_ptype())); int32_t *_p728 = (int32_t*)hr_grow(_v728, 1, sizeof _x728); *_p728 = _x728; _p728; }));
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
if (f41_is(((int64_t)5LL))) { { uint16_t *_t738 = &(((*({ hrv *_t739 = &(g721); int64_t _i739 = n_168; (S4*)_t739->b + hr_ix(_i739, _t739->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:128"); }))).fl_); *_t738 = ((uint16_t)1LL); }
int64_t m_169 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v744 = &(g723); int32_t _x744 = ((int32_t)(f53_ptype())); int32_t *_p744 = (int32_t*)hr_grow(_v744, 1, sizeof _x744); *_p744 = _x744; _p744; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk741; }
 }
 } _bk741:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function type", 13)));
(void)(f59_setl(n_168, m_169));
if (f41_is(((int64_t)54LL))) { int64_t r_170 = f40_mk(((int64_t)36LL), g726); 
int64_t m2_171 = f52_wbeg(); 
if (f41_is(((int64_t)5LL))) { while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v756 = &(g723); int32_t _x756 = ((int32_t)(f53_ptype())); int32_t *_p756 = (int32_t*)hr_grow(_v756, 1, sizeof _x756); *_p756 = _x756; _p756; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk753; }
 }
 } _bk753:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function type return list", 25)));
 } else { (void)(({ hrv *_v760 = &(g723); int32_t _x760 = ((int32_t)(f53_ptype())); int32_t *_p760 = (int32_t*)hr_grow(_v760, 1, sizeof _x760); *_p760 = _x760; _p760; }));
 }
(void)(f59_setl(r_170, m2_171));
{ int32_t *_t763 = &(((*({ hrv *_t764 = &(g721); int64_t _i764 = n_168; (S4*)_t764->b + hr_ix(_i764, _t764->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:133"); }))).b_); *_t763 = ((int32_t)(r_170)); }
 }
 }
return n_168;
 }
if (f41_is(((int64_t)5LL))) { bool fb_172 = g773; 
g773 = false;
int64_t t_173 = f53_ptype(); 
g773 = fb_172;
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
if (((f31_tk()) == (((int64_t)44LL)))) { (void)(({ hrv *_v788 = &(g735); int64_t _x788 = g726; int64_t *_p788 = (int64_t*)hr_grow(_v788, 1, sizeof _x788); *_p788 = _x788; _p788; }));
{ uint8_t *_t789 = &(((*({ hrv *_t790 = &(g931); int64_t _i790 = g726; (S3*)_t790->b + hr_ix(_i790, _t790->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:52"); }))).k_); *_t789 = ((uint8_t)(((uint8_t)40LL))); }
return;
 }
(void)(f39_ex(((int64_t)40LL), ctx_160));
}
static void f59_setl(int64_t n_161, int64_t m_162) {
int64_t c_163 = ((int64_t)((int64_t)(g723).n - (int64_t)m_162)); 
{ int64_t q__167 = f60_wend(m_162); 
{ int32_t *_t793 = &(((*({ hrv *_t794 = &(g721); int64_t _i794 = n_161; (S4*)_t794->b + hr_ix(_i794, _t794->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:55"); }))).l_); *_t793 = ((int32_t)(q__167)); }
 }
{ int32_t *_t795 = &(((*({ hrv *_t796 = &(g721); int64_t _i796 = n_161; (S4*)_t796->b + hr_ix(_i796, _t796->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:55"); }))).n_); *_t795 = ((int32_t)(c_163)); }
}
static int64_t f60_wend(int64_t m_164) {
int64_t l_165 = (g722).n; 
{ int64_t _e798 = (g723).n; for (int64_t _k798 = m_164; _k798 < _e798; _k798++) { int64_t i_166 = (int64_t)_k798; (void)(({ hrv *_v799 = &(g722); int32_t _x799 = (*({ hrv *_t800 = &(g723); int64_t _i800 = i_166; (int32_t*)_t800->b + hr_ix(_i800, _t800->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:54"); })); int32_t *_p799 = (int32_t*)hr_grow(_v799, 1, sizeof _x799); *_p799 = _x799; _p799; }));
 } } _bk797:; 
(void)(({ hrv *_v801 = &(g723); int64_t _k801 = ((int64_t)((int64_t)(g723).n - (int64_t)m_164)); if (_k801 < 0 || _k801 > _v801->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:54"); _v801->n -= _k801; }));
return l_165;
}
static int64_t f61_pexpr(void) {
int64_t st_180 = g726; 
int64_t k_181 = f31_tk(); 
if (((k_181) == (((int64_t)72LL)))) { int64_t e_270 = f62_pif(); 
if (g731) { g732 = true;
 }
return e_270;
 }
if (((k_181) == (((int64_t)80LL)))) { int64_t e_274 = f78_pmatch(); 
if (g731) { g732 = true;
 }
return e_274;
 }
if (((k_181) == (((int64_t)78LL)))) { (void)(f33_nx());
int64_t e_275 = f40_mk(((int64_t)24LL), st_180); 
{ int64_t q__276 = f66_pblock(hr_str("block expression", 16)); 
{ int32_t *_t808 = &(((*({ hrv *_t809 = &(g721); int64_t _i809 = e_275; (S4*)_t809->b + hr_ix(_i809, _t809->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:147"); }))).a_); *_t808 = ((int32_t)(q__276)); }
 }
if (g731) { g732 = true;
 }
return e_275;
 }
if (((k_181) == (((int64_t)9LL)))) { int64_t e_277 = f66_pblock(hr_str("block", 5)); 
if (g731) { g732 = true;
 }
return e_277;
 }
if (((k_181) == (((int64_t)74LL)))) { (void)(f33_nx());
int64_t e_278 = f40_mk(((int64_t)25LL), st_180); 
{ int64_t q__279 = f63_pscrut(); 
{ int32_t *_t814 = &(((*({ hrv *_t815 = &(g721); int64_t _i815 = e_278; (S4*)_t815->b + hr_ix(_i815, _t815->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:149"); }))).a_); *_t814 = ((int32_t)(q__279)); }
 }
{ int64_t q__280 = f66_pblock(hr_str("while body", 10)); 
{ int32_t *_t817 = &(((*({ hrv *_t818 = &(g721); int64_t _i818 = e_278; (S4*)_t818->b + hr_ix(_i818, _t818->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:149"); }))).b_); *_t817 = ((int32_t)(q__280)); }
 }
if (g731) { g732 = true;
 }
return e_278;
 }
if (((k_181) == (((int64_t)77LL)))) { (void)(f33_nx());
int64_t e_281 = f40_mk(((int64_t)26LL), st_180); 
{ int64_t q__282 = f66_pblock(hr_str("loop body", 9)); 
{ int32_t *_t822 = &(((*({ hrv *_t823 = &(g721); int64_t _i823 = e_281; (S4*)_t823->b + hr_ix(_i823, _t823->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:150"); }))).a_); *_t822 = ((int32_t)(q__282)); }
 }
if (g731) { g732 = true;
 }
return e_281;
 }
if (((k_181) == (((int64_t)75LL)))) { int64_t e_294 = f79_pfor(); 
if (g731) { g732 = true;
 }
return e_294;
 }
if (((k_181) == (((int64_t)79LL)))) { (void)(f38_perr(hr_str("guard is a statement: it guards the rest of the block it is in", 62)));
return f40_mk(((int64_t)6LL), st_180);
 }
if (((k_181) == (((int64_t)81LL)))) { (void)(f33_nx());
bool sl_295 = g731; 
bool se_296 = g732; 
g731 = false;
g732 = false;
int64_t r_297 = f40_mk(((int64_t)28LL), st_180); 
if (((((f31_tk()) != (((int64_t)12LL))) && ((f31_tk()) != (((int64_t)10LL)))) && (!(f42_at_from())))) { int64_t m_298 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v834 = &(g723); int32_t _x834 = ((int32_t)(f61_pexpr())); int32_t *_p834 = (int32_t*)hr_grow(_v834, 1, sizeof _x834); *_p834 = _x834; _p834; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk833; }
 }
 } _bk833:; 
(void)(f59_setl(r_297, m_298));
 }
if (f42_at_from()) { (void)(f33_nx());
{ int64_t q__299 = f56_qname(hr_str("return from", 11)); 
{ int32_t *_t841 = &(((*({ hrv *_t842 = &(g721); int64_t _i842 = r_297; (S4*)_t842->b + hr_ix(_i842, _t842->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:158"); }))).s_); *_t841 = ((int32_t)(q__299)); }
 }
 }
g731 = sl_295;
g732 = se_296;
return r_297;
 }
if (((k_181) == (((int64_t)82LL)))) { (void)(f33_nx());
bool sl_300 = g731; 
bool se_301 = g732; 
g731 = false;
g732 = false;
int64_t r_302 = f40_mk(((int64_t)29LL), st_180); 
if ((((f31_tk()) != (((int64_t)12LL))) && ((f31_tk()) != (((int64_t)10LL))))) { { int64_t q__303 = f61_pexpr(); 
{ int32_t *_t848 = &(((*({ hrv *_t849 = &(g721); int64_t _i849 = r_302; (S4*)_t849->b + hr_ix(_i849, _t849->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:166"); }))).a_); *_t848 = ((int32_t)(q__303)); }
 }
 }
g731 = sl_300;
g732 = se_301;
return r_302;
 }
if (((k_181) == (((int64_t)83LL)))) { (void)(f33_nx());
return f40_mk(((int64_t)30LL), st_180);
 }
return f80_pbin(((int64_t)1LL));
}
static int64_t f62_pif(void) {
int64_t st_182 = g726; 
(void)(f33_nx());
int64_t n_183 = f40_mk(((int64_t)19LL), st_182); 
{ int64_t q__189 = f63_pscrut(); 
{ int32_t *_t856 = &(((*({ hrv *_t857 = &(g721); int64_t _i857 = n_183; (S4*)_t857->b + hr_ix(_i857, _t857->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:180"); }))).a_); *_t856 = ((int32_t)(q__189)); }
 }
{ int64_t q__268 = f66_pblock(hr_str("if body", 7)); 
{ int32_t *_t859 = &(((*({ hrv *_t860 = &(g721); int64_t _i860 = n_183; (S4*)_t860->b + hr_ix(_i860, _t860->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:181"); }))).b_); *_t859 = ((int32_t)(q__268)); }
 }
if (f41_is(((int64_t)73LL))) { { int64_t q__269 = ({ int64_t _r862; if (((f31_tk()) == (((int64_t)72LL)))) { _r862 = f62_pif();  } else { _r862 = f66_pblock(hr_str("else body", 9));  } _r862; }); 
{ int32_t *_t866 = &(((*({ hrv *_t867 = &(g721); int64_t _i867 = n_183; (S4*)_t867->b + hr_ix(_i867, _t867->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:182"); }))).c_); *_t866 = ((int32_t)(q__269)); }
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
int64_t s_185 = ((int64_t)((int64_t)((int64_t)((int64_t)({ int64_t _r871; if (g730) { _r871 = ((int64_t)1LL);  } else { _r871 = ((int64_t)0LL);  } _r871; }) | (int64_t)({ int64_t _r872; if (g731) { _r872 = ((int64_t)2LL);  } else { _r872 = ((int64_t)0LL);  } _r872; }))) | (int64_t)({ int64_t _r873; if (g732) { _r873 = ((int64_t)4LL);  } else { _r873 = ((int64_t)0LL);  } _r873; }))); 
g730 = nosl_184;
g731 = false;
g732 = false;
return s_185;
}
static void f65_sub_end(int64_t s_188) {
g730 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)));
g731 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)));
g732 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL)));
}
static int64_t f66_pblock(hsl ctx_190) {
int64_t st_191 = g726; 
(void)(f39_ex(((int64_t)9LL), ctx_190));
int64_t b_192 = f40_mk(((int64_t)23LL), st_191); 
(void)(f67_pbody(b_192));
return b_192;
}
static void f67_pbody(int64_t b_193) {
int64_t s_194 = f64_sub_begin(false); 
int64_t m_195 = f52_wbeg(); 
for (;;) { g731 = false;
g732 = false;
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
if (((((((((f46_at_inline() || f47_at_checkfree()) || f48_at_lut()) || ((k_197) == (((int64_t)65LL)))) || ((k_197) == (((int64_t)61LL)))) || ((k_197) == (((int64_t)62LL)))) || ((k_197) == (((int64_t)68LL)))) || ((k_197) == (((int64_t)63LL)))) || ((k_197) == (((int64_t)64LL))))) { (void)(({ hrv *_v890 = &(g723); int32_t _x890 = ((int32_t)(f49_pfn(true, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p890 = (int32_t*)hr_grow(_v890, 1, sizeof _x890); *_p890 = _x890; _p890; }));
return true;
 }
if ((((((k_197) == (((int64_t)66LL))) || ((k_197) == (((int64_t)67LL)))) || ((k_197) == (((int64_t)69LL)))) || ((k_197) == (((int64_t)71LL))))) { if ((((k_197) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g726 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v893 = &(g723); int32_t _x893 = ((int32_t)(f69_pcfor(((int64_t)0LL)))); int32_t *_p893 = (int32_t*)hr_grow(_v893, 1, sizeof _x893); *_p893 = _x893; _p893; }));
return true;
 }
int64_t v_247 = f74_pvdecl(false); 
(void)(f39_ex(((int64_t)12LL), hr_str("variable declaration", 20)));
(void)(({ hrv *_v897 = &(g723); int32_t _x897 = ((int32_t)(v_247)); int32_t *_p897 = (int32_t*)hr_grow(_v897, 1, sizeof _x897); *_p897 = _x897; _p897; }));
return true;
 }
if (((k_197) == (((int64_t)79LL)))) { (void)(f76_pguard(b_196));
return false;
 }
g731 = true;
int64_t e_254 = f61_pexpr(); 
g731 = false;
int64_t st_255 = g726; 
if ((!(g732))) { int64_t o_256 = f31_tk(); 
if ((((((((((((((o_256) == (((int64_t)36LL))) || ((o_256) == (((int64_t)18LL)))) || ((o_256) == (((int64_t)26LL)))) || ((o_256) == (((int64_t)27LL)))) || ((o_256) == (((int64_t)28LL)))) || ((o_256) == (((int64_t)29LL)))) || ((o_256) == (((int64_t)30LL)))) || ((o_256) == (((int64_t)31LL)))) || ((o_256) == (((int64_t)32LL)))) || ((o_256) == (((int64_t)33LL)))) || ((o_256) == (((int64_t)45LL)))) || ((o_256) == (((int64_t)46LL))))) { (void)(f33_nx());
int64_t r_257 = f61_pexpr(); 
(void)(f39_ex(((int64_t)12LL), hr_str("assignment statement", 20)));
int64_t n_258 = f40_mk(((int64_t)34LL), st_255); 
{ uint8_t *_t905 = &(((*({ hrv *_t906 = &(g721); int64_t _i906 = n_258; (S4*)_t906->b + hr_ix(_i906, _t906->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:528"); }))).op_); *_t905 = ((uint8_t)(o_256)); }
{ int32_t *_t907 = &(((*({ hrv *_t908 = &(g721); int64_t _i908 = n_258; (S4*)_t908->b + hr_ix(_i908, _t908->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:528"); }))).a_); *_t907 = ((int32_t)(e_254)); }
{ int32_t *_t909 = &(((*({ hrv *_t910 = &(g721); int64_t _i910 = n_258; (S4*)_t910->b + hr_ix(_i910, _t910->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:528"); }))).b_); *_t909 = ((int32_t)(r_257)); }
(void)(({ hrv *_v911 = &(g723); int32_t _x911 = ((int32_t)(n_258)); int32_t *_p911 = (int32_t*)hr_grow(_v911, 1, sizeof _x911); *_p911 = _x911; _p911; }));
return true;
 }
if ((((o_256) == (((int64_t)34LL))) || ((o_256) == (((int64_t)35LL))))) { (void)(f33_nx());
(void)(f39_ex(((int64_t)12LL), hr_str("increment statement", 19)));
int64_t n_259 = f40_mk(((int64_t)35LL), st_255); 
{ uint8_t *_t915 = &(((*({ hrv *_t916 = &(g721); int64_t _i916 = n_259; (S4*)_t916->b + hr_ix(_i916, _t916->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:530"); }))).op_); *_t915 = ((uint8_t)(o_256)); }
{ int32_t *_t917 = &(((*({ hrv *_t918 = &(g721); int64_t _i918 = n_259; (S4*)_t918->b + hr_ix(_i918, _t918->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:530"); }))).a_); *_t917 = ((int32_t)(e_254)); }
(void)(({ hrv *_v919 = &(g723); int32_t _x919 = ((int32_t)(n_259)); int32_t *_p919 = (int32_t*)hr_grow(_v919, 1, sizeof _x919); *_p919 = _x919; _p919; }));
return true;
 }
if (((o_256) == (((int64_t)11LL)))) { (void)(({ hrv *_v920 = &(g723); int32_t _x920 = ((int32_t)(f77_pmulti(e_254, st_255))); int32_t *_p920 = (int32_t*)hr_grow(_v920, 1, sizeof _x920); *_p920 = _x920; _p920; }));
return true;
 }
 }
if (f41_is(((int64_t)12LL))) { (void)(({ hrv *_v923 = &(g723); int32_t _x923 = ((int32_t)(e_254)); int32_t *_p923 = (int32_t*)hr_grow(_v923, 1, sizeof _x923); *_p923 = _x923; _p923; }));
return true;
 }
if (f41_is(((int64_t)10LL))) { { int32_t *_t925 = &(((*({ hrv *_t926 = &(g721); int64_t _i926 = b_196; (S4*)_t926->b + hr_ix(_i926, _t926->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:534"); }))).a_); *_t925 = ((int32_t)(e_254)); }
return false;
 }
if (g732) { (void)(({ hrv *_v927 = &(g723); int32_t _x927 = ((int32_t)(e_254)); int32_t *_p927 = (int32_t*)hr_grow(_v927, 1, sizeof _x927); *_p927 = _x927; _p927; }));
return true;
 }
hrv m_267 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o929 = &(m_267); hr_fs(_o929, hr_str("';' expected after expression, found '", 38)); hr_fs(_o929, f35_cur_text()); hr_fs(_o929, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_267)));
return false;
}
static int64_t f69_pcfor(int64_t mode_198) {
int64_t cf_199 = f40_mk(((int64_t)37LL), g726); 
(void)(f39_ex(((int64_t)69LL), hr_str("const for", 9)));
(void)(f39_ex(((int64_t)75LL), hr_str("const for", 9)));
(void)(f39_ex(((int64_t)39LL), hr_str("const for bindings", 18)));
int64_t nb_200 = f40_mk(((int64_t)36LL), g726); 
int64_t m_201 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v939 = &(g723); int32_t _x939 = ((int32_t)(f34_ident(hr_str("const for binding", 17)))); int32_t *_p939 = (int32_t*)hr_grow(_v939, 1, sizeof _x939); *_p939 = _x939; _p939; }));
if (((!(f41_is(((int64_t)11LL)))) || ((f31_tk()) == (((int64_t)40LL))))) { { goto _bk938; }
 }
 } _bk938:; 
(void)(f59_setl(nb_200, m_201));
(void)(f58_close_angle(hr_str("const for bindings", 18)));
(void)(f39_ex(((int64_t)76LL), hr_str("const for", 9)));
{ int32_t *_t946 = &(((*({ hrv *_t947 = &(g721); int64_t _i947 = cf_199; (S4*)_t947->b + hr_ix(_i947, _t947->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:426"); }))).a_); *_t946 = ((int32_t)(nb_200)); }
int64_t src_202 = f40_mk(((int64_t)36LL), g726); 
if (f41_is(((int64_t)7LL))) { { uint8_t *_t950 = &(((*({ hrv *_t951 = &(g721); int64_t _i951 = cf_199; (S4*)_t951->b + hr_ix(_i951, _t951->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:429"); }))).op_); *_t950 = ((uint8_t)1LL); }
int64_t s_203 = f64_sub_begin(false); 
int64_t m2_204 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)8LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v957 = &(g723); int32_t _x957 = ((int32_t)(f61_pexpr())); int32_t *_p957 = (int32_t*)hr_grow(_v957, 1, sizeof _x957); *_p957 = _x957; _p957; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk954; }
 }
 } _bk954:; 
(void)(f39_ex(((int64_t)8LL), hr_str("const for constant list", 23)));
(void)(f59_setl(src_202, m2_204));
(void)(f65_sub_end(s_203));
 } else { int64_t q_205 = f34_ident(hr_str("const for source", 16)); 
{ uint8_t *_t964 = &(((*({ hrv *_t965 = &(g721); int64_t _i965 = cf_199; (S4*)_t965->b + hr_ix(_i965, _t965->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:435"); }))).op_); *_t964 = ((uint8_t)(({ uint8_t _r966; if (((q_205) == (g744))) { _r966 = ((uint8_t)2LL);  } else { _r966 = ({ uint8_t _r967; if (((q_205) == (g746))) { _r967 = ((uint8_t)3LL);  } else { _r967 = ({ uint8_t _r968; if (((q_205) == (g745))) { _r968 = ((uint8_t)4LL);  } else { _r968 = ((uint8_t)0LL);  } _r968; });  } _r967; });  } _r966; }))); }
if (((((*({ hrv *_t969 = &(g721); int64_t _i969 = cf_199; (S4*)_t969->b + hr_ix(_i969, _t969->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:436"); }))).op_) == (((uint8_t)0LL)))) { (void)(f38_perr(hr_str("const for source must be fields<T>, variants<E>, types<...>, or [constants]", 75)));
 }
(void)(f39_ex(((int64_t)39LL), hr_str("const for source", 16)));
int64_t m2_206 = f52_wbeg(); 
while (((((f31_tk()) != (((int64_t)40LL))) && ((f31_tk()) != (((int64_t)44LL)))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v977 = &(g723); int32_t _x977 = ((int32_t)(f53_ptype())); int32_t *_p977 = (int32_t*)hr_grow(_v977, 1, sizeof _x977); *_p977 = _x977; _p977; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk973; }
 }
 } _bk973:; 
(void)(f58_close_angle(hr_str("const for source", 16)));
(void)(f59_setl(src_202, m2_206));
 }
{ int32_t *_t982 = &(((*({ hrv *_t983 = &(g721); int64_t _i983 = cf_199; (S4*)_t983->b + hr_ix(_i983, _t983->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:440"); }))).b_); *_t982 = ((int32_t)(src_202)); }
{ uint16_t *_t984 = &(((*({ hrv *_t985 = &(g721); int64_t _i985 = cf_199; (S4*)_t985->b + hr_ix(_i985, _t985->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:441"); }))).fl_); *_t984 = ((uint16_t)(mode_198)); }
if (((mode_198) == (((int64_t)1LL)))) { int64_t il_207 = f40_mk(((int64_t)36LL), g726); 
(void)(f70_pinits(il_207, true));
{ int32_t *_t988 = &(((*({ hrv *_t989 = &(g721); int64_t _i989 = cf_199; (S4*)_t989->b + hr_ix(_i989, _t989->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:442"); }))).c_); *_t988 = ((int32_t)(il_207)); }
 } else { if (((mode_198) == (((int64_t)2LL)))) { (void)(f39_ex(((int64_t)9LL), hr_str("const for arms", 14)));
int64_t al_214 = f40_mk(((int64_t)36LL), g726); 
(void)(f71_parms(al_214));
(void)(f39_ex(((int64_t)10LL), hr_str("const for arms", 14)));
{ int32_t *_t994 = &(((*({ hrv *_t995 = &(g721); int64_t _i995 = cf_199; (S4*)_t995->b + hr_ix(_i995, _t995->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:443"); }))).c_); *_t994 = ((int32_t)(al_214)); }
 } else { { int64_t q__237 = f66_pblock(hr_str("const for body", 14)); 
{ int32_t *_t997 = &(((*({ hrv *_t998 = &(g721); int64_t _i998 = cf_199; (S4*)_t998->b + hr_ix(_i998, _t998->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:443"); }))).c_); *_t997 = ((int32_t)(q__237)); }
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
{ uint16_t *_t1007 = &(((*({ hrv *_t1008 = &(g721); int64_t _i1008 = n_208; (S4*)_t1008->b + hr_ix(_i1008, _t1008->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:451"); }))).fl_); *_t1007 = ((uint16_t)((uint64_t)(*_t1007) | (uint64_t)((uint16_t)1LL))); }
{ goto _bk1002; }
 }
if ((((f31_tk()) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g726 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v1011 = &(g723); int32_t _x1011 = ((int32_t)(f69_pcfor(((int64_t)1LL)))); int32_t *_p1011 = (int32_t*)hr_grow(_v1011, 1, sizeof _x1011); *_p1011 = _x1011; _p1011; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1002; }
 }
continue;
 }
int64_t fi_212 = f40_mk(((int64_t)18LL), g726); 
if ((((f31_tk()) == (((int64_t)1LL))) && ((f44_tkat(((int64_t)((int64_t)g726 + (int64_t)((int64_t)1LL))))) == (((int64_t)13LL))))) { { int32_t *_t1017 = &(((*({ hrv *_t1018 = &(g721); int64_t _i1018 = fi_212; (S4*)_t1018->b + hr_ix(_i1018, _t1018->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:454"); }))).s_); *_t1017 = ((int32_t)(((*({ hrv *_t1019 = &(g931); int64_t _i1019 = g726; (S3*)_t1019->b + hr_ix(_i1019, _t1019->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:454"); }))).v_)); }
(void)(f33_nx());
(void)(f33_nx());
 }
{ int64_t q__213 = f61_pexpr(); 
{ int32_t *_t1023 = &(((*({ hrv *_t1024 = &(g721); int64_t _i1024 = fi_212; (S4*)_t1024->b + hr_ix(_i1024, _t1024->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:455"); }))).a_); *_t1023 = ((int32_t)(q__213)); }
 }
(void)(({ hrv *_v1025 = &(g723); int32_t _x1025 = ((int32_t)(fi_212)); int32_t *_p1025 = (int32_t*)hr_grow(_v1025, 1, sizeof _x1025); *_p1025 = _x1025; _p1025; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1002; }
 }
 } _bk1002:; 
(void)(f39_ex(((int64_t)10LL), hr_str("struct literal", 14)));
(void)(f59_setl(n_208, m_211));
(void)(f65_sub_end(s_210));
}
static void f71_parms(int64_t n_215) {
int64_t s_216 = f64_sub_begin(g730); 
int64_t m_217 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { if ((((f31_tk()) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g726 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v1037 = &(g723); int32_t _x1037 = ((int32_t)(f69_pcfor(((int64_t)2LL)))); int32_t *_p1037 = (int32_t*)hr_grow(_v1037, 1, sizeof _x1037); *_p1037 = _x1037; _p1037; }));
 } else { int64_t a_235 = f72_ppattern(); 
(void)(f39_ex(((int64_t)55LL), hr_str("match arm", 9)));
{ int64_t q__236 = f61_pexpr(); 
{ int32_t *_t1042 = &(((*({ hrv *_t1043 = &(g721); int64_t _i1043 = a_235; (S4*)_t1043->b + hr_ix(_i1043, _t1043->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:218"); }))).b_); *_t1042 = ((int32_t)(q__236)); }
 }
(void)(({ hrv *_v1044 = &(g723); int32_t _x1044 = ((int32_t)(a_235)); int32_t *_p1044 = (int32_t*)hr_grow(_v1044, 1, sizeof _x1044); *_p1044 = _x1044; _p1044; }));
 }
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1032; }
 }
 } _bk1032:; 
(void)(f59_setl(n_215, m_217));
(void)(f65_sub_end(s_216));
}
static int64_t f72_ppattern(void) {
int64_t a_218 = f40_mk(((int64_t)21LL), g726); 
if (f43_at_word(g742)) { (void)(f33_nx());
{ uint16_t *_t1051 = &(((*({ hrv *_t1052 = &(g721); int64_t _i1052 = a_218; (S4*)_t1052->b + hr_ix(_i1052, _t1052->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:226"); }))).fl_); *_t1051 = ((uint16_t)1LL); }
if (((f31_tk()) == (((int64_t)11LL)))) { (void)(f38_perr(hr_str("_ cannot be listed with other patterns", 38)));
 }
return a_218;
 }
int64_t m_219 = f52_wbeg(); 
for (;;) { int64_t it_220 = f40_mk(((int64_t)22LL), g726); 
{ int64_t q__229 = f73_pbound(); 
{ int32_t *_t1059 = &(((*({ hrv *_t1060 = &(g721); int64_t _i1060 = it_220; (S4*)_t1060->b + hr_ix(_i1060, _t1060->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:230"); }))).a_); *_t1059 = ((int32_t)(q__229)); }
 }
if (f41_is(((int64_t)17LL))) { { int64_t q__230 = f73_pbound(); 
{ int32_t *_t1063 = &(((*({ hrv *_t1064 = &(g721); int64_t _i1064 = it_220; (S4*)_t1064->b + hr_ix(_i1064, _t1064->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:231"); }))).b_); *_t1063 = ((int32_t)(q__230)); }
 }
 }
(void)(({ hrv *_v1065 = &(g723); int32_t _x1065 = ((int32_t)(it_220)); int32_t *_p1065 = (int32_t*)hr_grow(_v1065, 1, sizeof _x1065); *_p1065 = _x1065; _p1065; }));
int64_t lo_231 = ((int64_t)(((*({ hrv *_t1066 = &(g721); int64_t _i1066 = it_220; (S4*)_t1066->b + hr_ix(_i1066, _t1066->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:233"); }))).a_)); 
if (((((((*({ hrv *_t1067 = &(g721); int64_t _i1067 = lo_231; (S4*)_t1067->b + hr_ix(_i1067, _t1067->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:234"); }))).k_) == (((uint8_t)8LL))) && ((((*({ hrv *_t1068 = &(g721); int64_t _i1068 = it_220; (S4*)_t1068->b + hr_ix(_i1068, _t1068->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:234"); }))).b_) < (((int32_t)0LL)))) && (((f31_tk()) == (((int64_t)49LL))) || ((f31_tk()) == (((int64_t)1LL)))))) { bool hasq_232 = false; 
{ hsl _v1072 = f10_nm(((int64_t)(((*({ hrv *_t1074 = &(g721); int64_t _i1074 = lo_231; (S4*)_t1074->b + hr_ix(_i1074, _t1074->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:235"); }))).s_))); for (int64_t _k1072 = 0; _k1072 < _v1072.n; _k1072++) { uint8_t c_233 = ((uint8_t*)_v1072.p)[_k1072]; if (((c_233) == (((uint8_t)58LL)))) { hasq_232 = true;
 }
 } } _bk1071:; 
if ((!(hasq_232))) { if (((((int64_t)((int64_t)(g723).n - (int64_t)m_219))) > (((int64_t)1LL)))) { (void)(f38_perr(hr_str("a list of patterns binds no payload: give the variant an arm of its own", 71)));
 }
if (f41_is(((int64_t)49LL))) { { uint16_t *_t1077 = &(((*({ hrv *_t1078 = &(g721); int64_t _i1078 = a_218; (S4*)_t1078->b + hr_ix(_i1078, _t1078->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:238"); }))).fl_); *_t1077 = ((uint16_t)((uint64_t)(*_t1077) | (uint64_t)((uint16_t)2LL))); }
 }
{ int64_t q__234 = f34_ident(hr_str("match binding", 13)); 
{ int32_t *_t1080 = &(((*({ hrv *_t1081 = &(g721); int64_t _i1081 = a_218; (S4*)_t1081->b + hr_ix(_i1081, _t1081->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:239"); }))).s_); *_t1080 = ((int32_t)(q__234)); }
 }
if (((f31_tk()) == (((int64_t)11LL)))) { (void)(f38_perr(hr_str("a list of patterns binds no payload: give the variant an arm of its own", 71)));
 }
(void)(f59_setl(a_218, m_219));
return a_218;
 }
 }
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1056; }
 }
if (f43_at_word(g742)) { (void)(f38_perr(hr_str("_ cannot be listed with other patterns", 38)));
 }
 } _bk1056:; 
(void)(f59_setl(a_218, m_219));
return a_218;
}
static int64_t f73_pbound(void) {
int64_t st_221 = g726; 
bool neg_222 = f41_is(((int64_t)22LL)); 
if ((((f31_tk()) == (((int64_t)1LL))) || ((f31_tk()) == (((int64_t)15LL))))) { int64_t n_223 = f40_mk(((int64_t)8LL), g726); 
{ int64_t q__224 = f56_qname(hr_str("match pattern", 13)); 
{ int32_t *_t1094 = &(((*({ hrv *_t1095 = &(g721); int64_t _i1095 = n_223; (S4*)_t1095->b + hr_ix(_i1095, _t1095->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:254"); }))).s_); *_t1094 = ((int32_t)(q__224)); }
 }
if (neg_222) { int64_t u_225 = f40_mk(((int64_t)10LL), st_221); 
{ uint8_t *_t1097 = &(((*({ hrv *_t1098 = &(g721); int64_t _i1098 = u_225; (S4*)_t1098->b + hr_ix(_i1098, _t1098->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:254"); }))).op_); *_t1097 = ((uint8_t)(((uint8_t)22LL))); }
{ int32_t *_t1099 = &(((*({ hrv *_t1100 = &(g721); int64_t _i1100 = u_225; (S4*)_t1100->b + hr_ix(_i1100, _t1100->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:254"); }))).a_); *_t1099 = ((int32_t)(n_223)); }
return u_225;
 }
return n_223;
 }
if (((f31_tk()) != (((int64_t)2LL)))) { hrv m_226 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1103 = &(m_226); hr_fs(_o1103, hr_str("integer constant expected in match pattern, found '", 51)); hr_fs(_o1103, f35_cur_text()); hr_fs(_o1103, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_226)));
return f40_mk(((int64_t)1LL), st_221);
 }
int64_t n_227 = f40_mk(((int64_t)1LL), g726); 
(void)(f33_nx());
if (neg_222) { int64_t u_228 = f40_mk(((int64_t)10LL), st_221); 
{ uint8_t *_t1110 = &(((*({ hrv *_t1111 = &(g721); int64_t _i1111 = u_228; (S4*)_t1111->b + hr_ix(_i1111, _t1111->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:257"); }))).op_); *_t1110 = ((uint8_t)(((uint8_t)22LL))); }
{ int32_t *_t1112 = &(((*({ hrv *_t1113 = &(g721); int64_t _i1113 = u_228; (S4*)_t1113->b + hr_ix(_i1113, _t1113->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:257"); }))).a_); *_t1112 = ((int32_t)(n_227)); }
return u_228;
 }
return n_227;
}
static int64_t f74_pvdecl(bool glob_238) {
int64_t st_239 = g726; 
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
for (;;) { (void)(({ hrv *_v1129 = &(g723); int32_t _x1129 = ((int32_t)(({ int64_t _r1130; if (glob_238) { _r1130 = f50_declname(hr_str("global declaration", 18));  } else { _r1130 = f34_ident(hr_str("variable declaration", 20));  } _r1130; }))); int32_t *_p1129 = (int32_t*)hr_grow(_v1129, 1, sizeof _x1129); *_p1129 = _x1129; _p1129; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1128; }
 }
 } _bk1128:; 
(void)(f59_setl(v_241, m_242));
{ int32_t *_t1135 = &(((*({ hrv *_t1136 = &(g721); int64_t _i1136 = v_241; (S4*)_t1136->b + hr_ix(_i1136, _t1136->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:571"); }))).c_); *_t1135 = ((int32_t)(g733)); }
if ((f41_is(((int64_t)13LL)) || f75_amni_type())) { { int64_t q__244 = f53_ptype(); 
{ int32_t *_t1140 = &(((*({ hrv *_t1141 = &(g721); int64_t _i1141 = v_241; (S4*)_t1141->b + hr_ix(_i1141, _t1141->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:572"); }))).a_); *_t1140 = ((int32_t)(q__244)); }
 }
 }
if (f41_is(((int64_t)18LL))) { { int64_t *_t1143 = &(fl_240); *_t1143 = ((int64_t)((int64_t)(*_t1143) | (int64_t)((int64_t)4LL))); }
 }
if ((((((int64_t)((int64_t)fl_240 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL))) || f41_is(((int64_t)36LL)))) { int64_t il_245 = f40_mk(((int64_t)36LL), g726); 
int64_t m2_246 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v1148 = &(g723); int32_t _x1148 = ((int32_t)(f61_pexpr())); int32_t *_p1148 = (int32_t*)hr_grow(_v1148, 1, sizeof _x1148); *_p1148 = _x1148; _p1148; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1147; }
 }
 } _bk1147:; 
(void)(f59_setl(il_245, m2_246));
{ int32_t *_t1152 = &(((*({ hrv *_t1153 = &(g721); int64_t _i1153 = v_241; (S4*)_t1153->b + hr_ix(_i1153, _t1153->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:574"); }))).b_); *_t1152 = ((int32_t)(il_245)); }
 }
{ uint16_t *_t1154 = &(((*({ hrv *_t1155 = &(g721); int64_t _i1155 = v_241; (S4*)_t1155->b + hr_ix(_i1155, _t1155->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:575"); }))).fl_); *_t1154 = ((uint16_t)(fl_240)); }
if (glob_238) { if ((((((*({ hrv *_t1156 = &(g721); int64_t _i1156 = v_241; (S4*)_t1156->b + hr_ix(_i1156, _t1156->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:577"); }))).b_) < (((int32_t)0LL))) && ((((int64_t)((int64_t)fl_240 & (int64_t)((int64_t)1LL)))) == (((int64_t)0LL))))) { (void)(f38_perr(hr_str("let and const global declarations require an initializer", 56)));
 }
if (((((*({ hrv *_t1158 = &(g721); int64_t _i1158 = v_241; (S4*)_t1158->b + hr_ix(_i1158, _t1158->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:578"); }))).n_) != (((int32_t)1LL)))) { (void)(f38_perr(hr_str("global declarations declare a single name", 41)));
 }
 }
return v_241;
}
static bool f75_amni_type(void) {
int64_t k_243 = f31_tk(); 
return (((*({ hrv *_t1161 = &(g930); int64_t _i1161 = ((*({ hrv *_t1162 = &(g931); int64_t _i1162 = g726; (S3*)_t1162->b + hr_ix(_i1162, _t1162->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:74"); }))).f_; (S2*)_t1161->b + hr_ix(_i1161, _t1161->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:74"); }))).amni_ && (((((f55_prim_tok(k_243) || ((k_243) == (((int64_t)1LL)))) || ((k_243) == (((int64_t)15LL)))) || ((k_243) == (((int64_t)61LL)))) || ((k_243) == (((int64_t)5LL)))) || ((k_243) == (((int64_t)69LL)))));
}
static void f76_pguard(int64_t b_248) {
int64_t st_249 = g726; 
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
{ int32_t *_t1173 = &(((*({ hrv *_t1174 = &(g721); int64_t _i1174 = i_253; (S4*)_t1174->b + hr_ix(_i1174, _t1174->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).a_); *_t1173 = ((int32_t)(c_250)); }
{ int32_t *_t1175 = &(((*({ hrv *_t1176 = &(g721); int64_t _i1176 = i_253; (S4*)_t1176->b + hr_ix(_i1176, _t1176->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).b_); *_t1175 = ((int32_t)(rest_252)); }
{ int32_t *_t1177 = &(((*({ hrv *_t1178 = &(g721); int64_t _i1178 = i_253; (S4*)_t1178->b + hr_ix(_i1178, _t1178->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).c_); *_t1177 = ((int32_t)(eb_251)); }
{ uint16_t *_t1179 = &(((*({ hrv *_t1180 = &(g721); int64_t _i1180 = i_253; (S4*)_t1180->b + hr_ix(_i1180, _t1180->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:559"); }))).fl_); *_t1179 = ((uint16_t)1LL); }
if (((((*({ hrv *_t1181 = &(g721); int64_t _i1181 = rest_252; (S4*)_t1181->b + hr_ix(_i1181, _t1181->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:560"); }))).a_) >= (((int32_t)0LL)))) { { int32_t *_t1182 = &(((*({ hrv *_t1183 = &(g721); int64_t _i1183 = b_248; (S4*)_t1183->b + hr_ix(_i1183, _t1183->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:560"); }))).a_); *_t1182 = ((int32_t)(i_253)); }
 } else { (void)(({ hrv *_v1184 = &(g723); int32_t _x1184 = ((int32_t)(i_253)); int32_t *_p1184 = (int32_t*)hr_grow(_v1184, 1, sizeof _x1184); *_p1184 = _x1184; _p1184; }));
 }
}
static int64_t f77_pmulti(int64_t first_260, int64_t st_261) {
int64_t tl_262 = f40_mk(((int64_t)36LL), st_261); 
int64_t m_263 = f52_wbeg(); 
(void)(({ hrv *_v1187 = &(g723); int32_t _x1187 = ((int32_t)(first_260)); int32_t *_p1187 = (int32_t*)hr_grow(_v1187, 1, sizeof _x1187); *_p1187 = _x1187; _p1187; }));
while (f41_is(((int64_t)11LL))) { (void)(({ hrv *_v1190 = &(g723); int32_t _x1190 = ((int32_t)(f61_pexpr())); int32_t *_p1190 = (int32_t*)hr_grow(_v1190, 1, sizeof _x1190); *_p1190 = _x1190; _p1190; }));
 } _bk1188:; 
(void)(f59_setl(tl_262, m_263));
int64_t o_264 = f31_tk(); 
if (((((((((((((o_264) == (((int64_t)18LL))) || ((o_264) == (((int64_t)26LL)))) || ((o_264) == (((int64_t)27LL)))) || ((o_264) == (((int64_t)28LL)))) || ((o_264) == (((int64_t)29LL)))) || ((o_264) == (((int64_t)30LL)))) || ((o_264) == (((int64_t)31LL)))) || ((o_264) == (((int64_t)32LL)))) || ((o_264) == (((int64_t)33LL)))) || ((o_264) == (((int64_t)45LL)))) || ((o_264) == (((int64_t)46LL))))) { (void)(f38_perr(hr_str("several targets take a call's results with `=` alone (\302\2477.1)", 60)));
 }
if (((f31_tk()) != (((int64_t)36LL)))) { (void)(f38_perr(hr_str("several values exist only in `return a, b;` and in a call's results, so a block or branch cannot end in `a, b`: return from each branch instead (\302\2477.1)", 151)));
 }
(void)(f33_nx());
int64_t n_265 = f40_mk(((int64_t)34LL), st_261); 
{ uint8_t *_t1199 = &(((*({ hrv *_t1200 = &(g721); int64_t _i1200 = n_265; (S4*)_t1200->b + hr_ix(_i1200, _t1200->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:548"); }))).op_); *_t1199 = ((uint8_t)(((uint8_t)11LL))); }
{ int32_t *_t1201 = &(((*({ hrv *_t1202 = &(g721); int64_t _i1202 = n_265; (S4*)_t1202->b + hr_ix(_i1202, _t1202->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:548"); }))).a_); *_t1201 = ((int32_t)(tl_262)); }
{ int64_t q__266 = f61_pexpr(); 
{ int32_t *_t1204 = &(((*({ hrv *_t1205 = &(g721); int64_t _i1205 = n_265; (S4*)_t1205->b + hr_ix(_i1205, _t1205->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:548"); }))).b_); *_t1204 = ((int32_t)(q__266)); }
 }
(void)(f39_ex(((int64_t)12LL), hr_str("assignment statement", 20)));
return n_265;
}
static int64_t f78_pmatch(void) {
int64_t st_271 = g726; 
(void)(f33_nx());
int64_t n_272 = f40_mk(((int64_t)20LL), st_271); 
{ int64_t q__273 = f63_pscrut(); 
{ int32_t *_t1210 = &(((*({ hrv *_t1211 = &(g721); int64_t _i1211 = n_272; (S4*)_t1211->b + hr_ix(_i1211, _t1211->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:206"); }))).a_); *_t1210 = ((int32_t)(q__273)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("match expression", 16)));
(void)(f71_parms(n_272));
(void)(f39_ex(((int64_t)10LL), hr_str("match expression", 16)));
if ((((((*({ hrv *_t1215 = &(g721); int64_t _i1215 = n_272; (S4*)_t1215->b + hr_ix(_i1215, _t1215->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:210"); }))).n_) == (((int32_t)0LL))) && (((g727).n) == (((int64_t)0LL))))) { (void)(f38_perr(hr_str("match must have at least one arm", 32)));
 }
return n_272;
}
static int64_t f79_pfor(void) {
int64_t st_283 = g726; 
(void)(f33_nx());
int64_t n_284 = f40_mk(((int64_t)27LL), st_283); 
if (f41_is(((int64_t)49LL))) { { uint16_t *_t1220 = &(((*({ hrv *_t1221 = &(g721); int64_t _i1221 = n_284; (S4*)_t1221->b + hr_ix(_i1221, _t1221->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:188"); }))).fl_); *_t1220 = ((uint16_t)1LL); }
 }
{ int64_t q__285 = f34_ident(hr_str("for binding", 11)); 
{ int32_t *_t1223 = &(((*({ hrv *_t1224 = &(g721); int64_t _i1224 = n_284; (S4*)_t1224->b + hr_ix(_i1224, _t1224->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:189"); }))).s_); *_t1223 = ((int32_t)(q__285)); }
 }
bool fb_286 = g773; 
g773 = true;
{ int32_t *_t1225 = &(((*({ hrv *_t1226 = &(g721); int64_t _i1226 = n_284; (S4*)_t1226->b + hr_ix(_i1226, _t1226->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:191"); }))).l_); *_t1225 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
{ int32_t *_t1227 = &(((*({ hrv *_t1228 = &(g721); int64_t _i1228 = n_284; (S4*)_t1228->b + hr_ix(_i1228, _t1228->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:191"); }))).n_); *_t1227 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
if (f41_is(((int64_t)13LL))) { { int64_t q__287 = f53_ptype(); 
{ int32_t *_t1231 = &(((*({ hrv *_t1232 = &(g721); int64_t _i1232 = n_284; (S4*)_t1232->b + hr_ix(_i1232, _t1232->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:192"); }))).l_); *_t1231 = ((int32_t)(q__287)); }
 }
 }
if (f41_is(((int64_t)11LL))) { { int64_t q__288 = f34_ident(hr_str("for index binding", 17)); 
{ int32_t *_t1235 = &(((*({ hrv *_t1236 = &(g721); int64_t _i1236 = n_284; (S4*)_t1236->b + hr_ix(_i1236, _t1236->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:193"); }))).c_); *_t1235 = ((int32_t)(q__288)); }
 }
if (f41_is(((int64_t)13LL))) { { int64_t q__289 = f53_ptype(); 
{ int32_t *_t1239 = &(((*({ hrv *_t1240 = &(g721); int64_t _i1240 = n_284; (S4*)_t1240->b + hr_ix(_i1240, _t1240->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:193"); }))).n_); *_t1239 = ((int32_t)(q__289)); }
 }
 }
 }
g773 = fb_286;
(void)(f39_ex(((int64_t)76LL), hr_str("for statement", 13)));
int64_t s_290 = f64_sub_begin(true); 
{ int64_t q__291 = f61_pexpr(); 
{ int32_t *_t1244 = &(((*({ hrv *_t1245 = &(g721); int64_t _i1245 = n_284; (S4*)_t1245->b + hr_ix(_i1245, _t1245->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:197"); }))).a_); *_t1244 = ((int32_t)(q__291)); }
 }
if (f41_is(((int64_t)17LL))) { { int64_t q__292 = f61_pexpr(); 
{ int32_t *_t1248 = &(((*({ hrv *_t1249 = &(g721); int64_t _i1249 = n_284; (S4*)_t1249->b + hr_ix(_i1249, _t1249->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:198"); }))).b_); *_t1248 = ((int32_t)(q__292)); }
 }
 }
(void)(f65_sub_end(s_290));
{ int64_t q__293 = f66_pblock(hr_str("for body", 8)); 
{ int32_t *_t1252 = &(((*({ hrv *_t1253 = &(g721); int64_t _i1253 = n_284; (S4*)_t1253->b + hr_ix(_i1253, _t1253->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:200"); }))).d_); *_t1252 = ((int32_t)(q__293)); }
 }
return n_284;
}
static int64_t f80_pbin(int64_t minp_304) {
int64_t l_383 = f81_pun(); 
for (;;) { if (g732) { return l_383;
 }
int64_t pr_385 = f92_binprec(f31_tk()); 
if ((((pr_385) < (minp_304)) || ((pr_385) == (((int64_t)0LL))))) { return l_383;
 }
int64_t op_386 = f31_tk(); 
int64_t st_387 = g726; 
(void)(f33_nx());
int64_t s_388 = f64_sub_begin(g730); 
int64_t r_389 = f80_pbin(((int64_t)((int64_t)pr_385 + (int64_t)((int64_t)1LL)))); 
(void)(f65_sub_end(s_388));
int64_t n_390 = f40_mk(((int64_t)9LL), st_387); 
{ uint8_t *_t1264 = &(((*({ hrv *_t1265 = &(g721); int64_t _i1265 = n_390; (S4*)_t1265->b + hr_ix(_i1265, _t1265->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:280"); }))).op_); *_t1264 = ((uint8_t)(op_386)); }
{ int32_t *_t1266 = &(((*({ hrv *_t1267 = &(g721); int64_t _i1267 = n_390; (S4*)_t1267->b + hr_ix(_i1267, _t1267->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:280"); }))).a_); *_t1266 = ((int32_t)(l_383)); }
{ int32_t *_t1268 = &(((*({ hrv *_t1269 = &(g721); int64_t _i1269 = n_390; (S4*)_t1269->b + hr_ix(_i1269, _t1269->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:280"); }))).b_); *_t1268 = ((int32_t)(r_389)); }
l_383 = n_390;
 } _bk1255:; 
}
static int64_t f81_pun(void) {
int64_t k_305 = f31_tk(); 
if ((((((k_305) == (((int64_t)22LL))) || ((k_305) == (((int64_t)47LL)))) || ((k_305) == (((int64_t)48LL)))) || ((k_305) == (((int64_t)49LL))))) { int64_t st_306 = g726; 
(void)(f33_nx());
int64_t s_307 = f64_sub_begin(g730); 
int64_t a_308 = f81_pun(); 
(void)(f65_sub_end(s_307));
int64_t n_309 = f40_mk(((int64_t)10LL), st_306); 
{ uint8_t *_t1276 = &(((*({ hrv *_t1277 = &(g721); int64_t _i1277 = n_309; (S4*)_t1277->b + hr_ix(_i1277, _t1277->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:291"); }))).op_); *_t1276 = ((uint8_t)(k_305)); }
{ int32_t *_t1278 = &(((*({ hrv *_t1279 = &(g721); int64_t _i1279 = n_309; (S4*)_t1279->b + hr_ix(_i1279, _t1279->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:291"); }))).a_); *_t1278 = ((int32_t)(a_308)); }
return n_309;
 }
return f82_ppost();
}
static int64_t f82_ppost(void) {
int64_t e_367 = f83_pprim(); 
for (;;) { if (g732) { return e_367;
 }
int64_t st_368 = g726; 
if (f41_is(((int64_t)5LL))) { e_367 = f86_pcall(e_367, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), st_368);
continue;
 }
if (((f31_tk()) == (((int64_t)7LL)))) { e_367 = f91_pindex(e_367);
continue;
 }
if (f41_is(((int64_t)16LL))) { int64_t nmid_377 = f34_ident(hr_str("field access", 12)); 
if (((((f31_tk()) == (((int64_t)9LL))) && (!(g730))) && ((((*({ hrv *_t1290 = &(g721); int64_t _i1290 = e_367; (S4*)_t1290->b + hr_ix(_i1290, _t1290->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:305"); }))).k_) == (((uint8_t)8LL))))) { int64_t b_378 = f40_mk(((int64_t)41LL), ((int64_t)(((*({ hrv *_t1292 = &(g721); int64_t _i1292 = e_367; (S4*)_t1292->b + hr_ix(_i1292, _t1292->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:306"); }))).t_))); 
{ int32_t *_t1293 = &(((*({ hrv *_t1294 = &(g721); int64_t _i1294 = b_378; (S4*)_t1294->b + hr_ix(_i1294, _t1294->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:306"); }))).s_); *_t1293 = ((*({ hrv *_t1295 = &(g721); int64_t _i1295 = e_367; (S4*)_t1295->b + hr_ix(_i1295, _t1295->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:306"); }))).s_; }
int64_t v_379 = f40_mk(((int64_t)46LL), st_368); 
{ int32_t *_t1297 = &(((*({ hrv *_t1298 = &(g721); int64_t _i1298 = v_379; (S4*)_t1298->b + hr_ix(_i1298, _t1298->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:307"); }))).a_); *_t1297 = ((int32_t)(b_378)); }
{ int32_t *_t1299 = &(((*({ hrv *_t1300 = &(g721); int64_t _i1300 = v_379; (S4*)_t1300->b + hr_ix(_i1300, _t1300->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:307"); }))).s_); *_t1299 = ((int32_t)(nmid_377)); }
e_367 = f89_pslit(v_379, st_368);
 } else { int64_t d_380 = f40_mk(((int64_t)14LL), st_368); 
{ int32_t *_t1303 = &(((*({ hrv *_t1304 = &(g721); int64_t _i1304 = d_380; (S4*)_t1304->b + hr_ix(_i1304, _t1304->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:309"); }))).a_); *_t1303 = ((int32_t)(e_367)); }
{ int32_t *_t1305 = &(((*({ hrv *_t1306 = &(g721); int64_t _i1306 = d_380; (S4*)_t1306->b + hr_ix(_i1306, _t1306->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:309"); }))).s_); *_t1305 = ((int32_t)(nmid_377)); }
e_367 = d_380;
 }
continue;
 }
if (f41_is(((int64_t)84LL))) { int64_t n_381 = f40_mk(((int64_t)15LL), st_368); 
{ uint16_t *_t1309 = &(((*({ hrv *_t1310 = &(g721); int64_t _i1310 = n_381; (S4*)_t1310->b + hr_ix(_i1310, _t1310->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:312"); }))).fl_); *_t1309 = ({ uint16_t _r1311; if (f41_is(((int64_t)47LL))) { _r1311 = ((uint16_t)1LL);  } else { _r1311 = ((uint16_t)0LL);  } _r1311; }); }
{ int32_t *_t1313 = &(((*({ hrv *_t1314 = &(g721); int64_t _i1314 = n_381; (S4*)_t1314->b + hr_ix(_i1314, _t1314->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:312"); }))).a_); *_t1313 = ((int32_t)(e_367)); }
{ int64_t q__382 = f53_ptype(); 
{ int32_t *_t1316 = &(((*({ hrv *_t1317 = &(g721); int64_t _i1317 = n_381; (S4*)_t1317->b + hr_ix(_i1317, _t1317->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:312"); }))).b_); *_t1316 = ((int32_t)(q__382)); }
 }
e_367 = n_381;
continue;
 }
return e_367;
 } _bk1282:; 
}
static int64_t f83_pprim(void) {
int64_t st_310 = g726; 
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
{ int32_t *_t1344 = &(((*({ hrv *_t1345 = &(g721); int64_t _i1345 = id_332; (S4*)_t1345->b + hr_ix(_i1345, _t1345->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:364"); }))).s_); *_t1344 = ((int32_t)(name_321)); }
return f86_pcall(id_332, ta_331, st_310);
 }
int64_t t_352 = f40_mk(((int64_t)41LL), st_310); 
{ int32_t *_t1348 = &(((*({ hrv *_t1349 = &(g721); int64_t _i1349 = t_352; (S4*)_t1349->b + hr_ix(_i1349, _t1349->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).s_); *_t1348 = ((int32_t)(name_321)); }
{ int32_t *_t1350 = &(((*({ hrv *_t1351 = &(g721); int64_t _i1351 = t_352; (S4*)_t1351->b + hr_ix(_i1351, _t1351->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).l_); *_t1350 = ((*({ hrv *_t1352 = &(g721); int64_t _i1352 = ta_331; (S4*)_t1352->b + hr_ix(_i1352, _t1352->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).l_; }
{ int32_t *_t1353 = &(((*({ hrv *_t1354 = &(g721); int64_t _i1354 = t_352; (S4*)_t1354->b + hr_ix(_i1354, _t1354->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).n_); *_t1353 = ((*({ hrv *_t1355 = &(g721); int64_t _i1355 = ta_331; (S4*)_t1355->b + hr_ix(_i1355, _t1355->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:365"); }))).n_; }
if (f41_is(((int64_t)16LL))) { int64_t v_353 = f40_mk(((int64_t)46LL), st_310); 
{ int32_t *_t1358 = &(((*({ hrv *_t1359 = &(g721); int64_t _i1359 = v_353; (S4*)_t1359->b + hr_ix(_i1359, _t1359->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:366"); }))).a_); *_t1358 = ((int32_t)(t_352)); }
{ int64_t q__354 = f34_ident(hr_str("variant literal", 15)); 
{ int32_t *_t1361 = &(((*({ hrv *_t1362 = &(g721); int64_t _i1362 = v_353; (S4*)_t1362->b + hr_ix(_i1362, _t1362->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:366"); }))).s_); *_t1361 = ((int32_t)(q__354)); }
 }
return f89_pslit(v_353, st_310);
 }
return f89_pslit(t_352, st_310);
 }
 }
if ((((f31_tk()) == (((int64_t)9LL))) && (!(g730)))) { int64_t t_364 = f40_mk(((int64_t)41LL), st_310); 
{ int32_t *_t1367 = &(((*({ hrv *_t1368 = &(g721); int64_t _i1368 = t_364; (S4*)_t1368->b + hr_ix(_i1368, _t1368->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:370"); }))).s_); *_t1367 = ((int32_t)(name_321)); }
return f89_pslit(t_364, st_310);
 }
int64_t id_365 = f40_mk(((int64_t)8LL), st_310); 
{ int32_t *_t1371 = &(((*({ hrv *_t1372 = &(g721); int64_t _i1372 = id_365; (S4*)_t1372->b + hr_ix(_i1372, _t1372->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:371"); }))).s_); *_t1371 = ((int32_t)(name_321)); }
return id_365;
 }
hrv m_366 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1374 = &(m_366); hr_fs(_o1374, hr_str("expression expected, found '", 28)); hr_fs(_o1374, f35_cur_text()); hr_fs(_o1374, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_366)));
return f40_mk(((int64_t)6LL), st_310);
}
static int64_t f84_parray(void) {
int64_t st_314 = g726; 
(void)(f33_nx());
int64_t a_315 = f40_mk(((int64_t)16LL), st_314); 
int64_t s_316 = f64_sub_begin(false); 
if (f41_is(((int64_t)17LL))) { { int64_t q__317 = f61_pexpr(); 
{ int32_t *_t1383 = &(((*({ hrv *_t1384 = &(g721); int64_t _i1384 = a_315; (S4*)_t1384->b + hr_ix(_i1384, _t1384->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:406"); }))).c_); *_t1383 = ((int32_t)(q__317)); }
 }
 } else { if (((f31_tk()) != (((int64_t)8LL)))) { int64_t first_318 = f61_pexpr(); 
if (f41_is(((int64_t)12LL))) { { int32_t *_t1388 = &(((*({ hrv *_t1389 = &(g721); int64_t _i1389 = a_315; (S4*)_t1389->b + hr_ix(_i1389, _t1389->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:410"); }))).a_); *_t1388 = ((int32_t)(first_318)); }
{ int64_t q__319 = f61_pexpr(); 
{ int32_t *_t1391 = &(((*({ hrv *_t1392 = &(g721); int64_t _i1392 = a_315; (S4*)_t1392->b + hr_ix(_i1392, _t1392->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:410"); }))).b_); *_t1391 = ((int32_t)(q__319)); }
 }
 } else { int64_t m_320 = f52_wbeg(); 
(void)(({ hrv *_v1394 = &(g723); int32_t _x1394 = ((int32_t)(first_318)); int32_t *_p1394 = (int32_t*)hr_grow(_v1394, 1, sizeof _x1394); *_p1394 = _x1394; _p1394; }));
while ((f41_is(((int64_t)11LL)) && ((f31_tk()) != (((int64_t)8LL))))) { (void)(({ hrv *_v1398 = &(g723); int32_t _x1398 = ((int32_t)(f61_pexpr())); int32_t *_p1398 = (int32_t*)hr_grow(_v1398, 1, sizeof _x1398); *_p1398 = _x1398; _p1398; }));
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
int64_t save_322 = g726; 
int64_t nd0_323 = (g721).n; 
int64_t ls0_324 = (g722).n; 
int64_t sp0_325 = (g735).n; 
int64_t ws0_326 = (g723).n; 
g728++;
(void)(f33_nx());
int64_t l_327 = f40_mk(((int64_t)36LL), save_322); 
int64_t m_328 = f52_wbeg(); 
bool ok_329 = false; 
for (;;) { (void)(({ hrv *_v1407 = &(g723); int32_t _x1407 = ((int32_t)(f53_ptype())); int32_t *_p1407 = (int32_t*)hr_grow(_v1407, 1, sizeof _x1407); *_p1407 = _x1407; _p1407; }));
if ((g729 || (!(f41_is(((int64_t)11LL)))))) { { goto _bk1406; }
 }
if ((((f31_tk()) == (((int64_t)40LL))) || ((f31_tk()) == (((int64_t)44LL))))) { { goto _bk1406; }
 }
 } _bk1406:; 
if ((!(g729))) { if (((f31_tk()) == (((int64_t)44LL)))) { (void)(({ hrv *_v1413 = &(g735); int64_t _x1413 = g726; int64_t *_p1413 = (int64_t*)hr_grow(_v1413, 1, sizeof _x1413); *_p1413 = _x1413; _p1413; }));
{ uint8_t *_t1414 = &(((*({ hrv *_t1415 = &(g931); int64_t _i1415 = g726; (S3*)_t1415->b + hr_ix(_i1415, _t1415->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:386"); }))).k_); *_t1414 = ((uint8_t)(((uint8_t)40LL))); }
ok_329 = true;
 } else { if (((f31_tk()) == (((int64_t)40LL)))) { (void)(f33_nx());
ok_329 = true;
 }
 }
if (ok_329) { ok_329 = false;
if ((((f31_tk()) == (((int64_t)5LL))) || (((f31_tk()) == (((int64_t)9LL))) && (!(g730))))) { ok_329 = true;
 }
if ((((((f31_tk()) == (((int64_t)16LL))) && (!(g730))) && ((f44_tkat(((int64_t)((int64_t)g726 + (int64_t)((int64_t)1LL))))) == (((int64_t)1LL)))) && ((f44_tkat(((int64_t)((int64_t)g726 + (int64_t)((int64_t)2LL))))) == (((int64_t)9LL))))) { ok_329 = true;
 }
 }
 }
g728--;
if ((ok_329 && (!(g729)))) { (void)(f59_setl(l_327, m_328));
return l_327;
 }
g729 = false;
while ((((g735).n) > (sp0_325))) { int64_t q_330 = ({ hrv *_v1425 = &(g735); if (!_v1425->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:396"); ((int64_t*)_v1425->b)[--_v1425->n]; }); 
{ uint8_t *_t1426 = &(((*({ hrv *_t1427 = &(g931); int64_t _i1427 = q_330; (S3*)_t1427->b + hr_ix(_i1427, _t1427->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:396"); }))).k_); *_t1426 = ((uint8_t)(((uint8_t)44LL))); }
 } _bk1424:; 
if ((((g723).n) > (ws0_326))) { (void)(({ hrv *_v1428 = &(g723); int64_t _k1428 = ((int64_t)((int64_t)(g723).n - (int64_t)ws0_326)); if (_k1428 < 0 || _k1428 > _v1428->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:397"); _v1428->n -= _k1428; }));
 }
(void)(({ hrv *_v1429 = &(g721); int64_t _k1429 = nd0_323; if (_k1429 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:398"); S4 _x1429 = ((S4){ 0}); int64_t _o1429 = _v1429->n; hr_resize(_v1429, _k1429, sizeof _x1429); for (int64_t _j = _o1429; _j < _k1429; _j++) ((S4*)_v1429->b)[_j] = _x1429; }));
(void)(({ hrv *_v1430 = &(g722); int64_t _k1430 = ls0_324; if (_k1430 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:398"); int32_t _x1430 = ((int32_t)0LL); int64_t _o1430 = _v1430->n; hr_resize(_v1430, _k1430, sizeof _x1430); for (int64_t _j = _o1430; _j < _k1430; _j++) ((int32_t*)_v1430->b)[_j] = _x1430; }));
g726 = save_322;
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f86_pcall(int64_t callee_333, int64_t tyargs_334, int64_t st_335) {
int64_t c_336 = f40_mk(((int64_t)11LL), st_335); 
{ int32_t *_t1432 = &(((*({ hrv *_t1433 = &(g721); int64_t _i1433 = c_336; (S4*)_t1433->b + hr_ix(_i1433, _t1433->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:317"); }))).a_); *_t1432 = ((int32_t)(callee_333)); }
{ int32_t *_t1434 = &(((*({ hrv *_t1435 = &(g721); int64_t _i1435 = c_336; (S4*)_t1435->b + hr_ix(_i1435, _t1435->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:317"); }))).c_); *_t1434 = ((int32_t)(tyargs_334)); }
int64_t s_337 = f64_sub_begin(false); 
int64_t m_338 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v1441 = &(g723); int32_t _x1441 = ((int32_t)(f61_pexpr())); int32_t *_p1441 = (int32_t*)hr_grow(_v1441, 1, sizeof _x1441); *_p1441 = _x1441; _p1441; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1438; }
 }
 } _bk1438:; 
(void)(f39_ex(((int64_t)6LL), hr_str("call arguments", 14)));
(void)(f59_setl(c_336, m_338));
(void)(f65_sub_end(s_337));
if ((((f31_tk()) == (((int64_t)9LL))) && (!(g730)))) { { int64_t q__351 = f87_pfunval(); 
{ int32_t *_t1449 = &(((*({ hrv *_t1450 = &(g721); int64_t _i1450 = c_336; (S4*)_t1450->b + hr_ix(_i1450, _t1450->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:324"); }))).b_); *_t1449 = ((int32_t)(q__351)); }
 }
if (g731) { g732 = true;
 }
 }
return c_336;
}
static int64_t f87_pfunval(void) {
int64_t st_339 = g726; 
(void)(f39_ex(((int64_t)9LL), hr_str("function value", 14)));
int64_t fv_340 = f40_mk(((int64_t)31LL), st_339); 
int64_t b_341 = f40_mk(((int64_t)23LL), st_339); 
{ int32_t *_t1454 = &(((*({ hrv *_t1455 = &(g721); int64_t _i1455 = fv_340; (S4*)_t1455->b + hr_ix(_i1455, _t1455->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:476"); }))).a_); *_t1454 = ((int32_t)(b_341)); }
if ((((f31_tk()) == (((int64_t)1LL))) || ((f31_tk()) == (((int64_t)67LL))))) { int64_t save_342 = g726; 
int64_t nd0_343 = (g721).n; 
int64_t ws0_344 = (g723).n; 
g728++;
bool ok_345 = true; 
int64_t m_346 = f52_wbeg(); 
for (;;) { bool pv_347 = f41_is(((int64_t)67LL)); 
if (((f31_tk()) != (((int64_t)1LL)))) { ok_345 = false;
{ goto _bk1459; }
 }
int64_t p_348 = f40_mk(((int64_t)32LL), g726); 
{ int32_t *_t1463 = &(((*({ hrv *_t1464 = &(g721); int64_t _i1464 = p_348; (S4*)_t1464->b + hr_ix(_i1464, _t1464->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:485"); }))).s_); *_t1463 = ((int32_t)(((*({ hrv *_t1465 = &(g931); int64_t _i1465 = g726; (S3*)_t1465->b + hr_ix(_i1465, _t1465->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:485"); }))).v_)); }
if (pv_347) { { uint16_t *_t1466 = &(((*({ hrv *_t1467 = &(g721); int64_t _i1467 = p_348; (S4*)_t1467->b + hr_ix(_i1467, _t1467->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:485"); }))).fl_); *_t1466 = ((uint16_t)1LL); }
 }
(void)(f33_nx());
if (f41_is(((int64_t)13LL))) { { int64_t q__349 = f53_ptype(); 
{ int32_t *_t1471 = &(((*({ hrv *_t1472 = &(g721); int64_t _i1472 = p_348; (S4*)_t1472->b + hr_ix(_i1472, _t1472->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:486"); }))).a_); *_t1471 = ((int32_t)(q__349)); }
 }
 }
(void)(({ hrv *_v1473 = &(g723); int32_t _x1473 = ((int32_t)(p_348)); int32_t *_p1473 = (int32_t*)hr_grow(_v1473, 1, sizeof _x1473); *_p1473 = _x1473; _p1473; }));
if ((g729 || (!(f41_is(((int64_t)11LL)))))) { { goto _bk1459; }
 }
 } _bk1459:; 
if (((g729 || (!(ok_345))) || (!(f41_is(((int64_t)55LL)))))) { ok_345 = false;
 }
g728--;
if (ok_345) { (void)(f59_setl(fv_340, m_346));
{ uint16_t *_t1477 = &(((*({ hrv *_t1478 = &(g721); int64_t _i1478 = fv_340; (S4*)_t1478->b + hr_ix(_i1478, _t1478->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:492"); }))).fl_); *_t1477 = ((uint16_t)1LL); }
 } else { g729 = false;
if ((((g723).n) > (ws0_344))) { (void)(({ hrv *_v1479 = &(g723); int64_t _k1479 = ((int64_t)((int64_t)(g723).n - (int64_t)ws0_344)); if (_k1479 < 0 || _k1479 > _v1479->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:493"); _v1479->n -= _k1479; }));
 }
(void)(({ hrv *_v1480 = &(g721); int64_t _k1480 = nd0_343; if (_k1480 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:493"); S4 _x1480 = ((S4){ 0}); int64_t _o1480 = _v1480->n; hr_resize(_v1480, _k1480, sizeof _x1480); for (int64_t _j = _o1480; _j < _k1480; _j++) ((S4*)_v1480->b)[_j] = _x1480; }));
g726 = save_342;
 }
 }
(void)(f67_pbody(b_341));
(void)(f88_set_end(fv_340));
return fv_340;
}
static void f88_set_end(int64_t n_350) {
while ((((g736).n) < ((g721).n))) { (void)(({ hrv *_v1484 = &(g736); int32_t _x1484 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1484 = (int32_t*)hr_grow(_v1484, 1, sizeof _x1484); *_p1484 = _x1484; _p1484; }));
 } _bk1483:; 
{ int32_t *_t1485 = &((*({ hrv *_t1486 = &(g736); int64_t _i1486 = n_350; (int32_t*)_t1486->b + hr_ix(_i1486, _t1486->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:28"); }))); *_t1485 = ((int32_t)((g721).n)); }
}
static int64_t f89_pslit(int64_t ty_355, int64_t st_356) {
int64_t n_357 = f40_mk(((int64_t)17LL), st_356); 
{ int32_t *_t1488 = &(((*({ hrv *_t1489 = &(g721); int64_t _i1489 = n_357; (S4*)_t1489->b + hr_ix(_i1489, _t1489->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:464"); }))).a_); *_t1488 = ((int32_t)(ty_355)); }
(void)(f70_pinits(n_357, false));
int64_t named_358 = ((int64_t)0LL); 
bool cf_359 = false; 
{ int32_t _e1492 = ((*({ hrv *_t1493 = &(g721); int64_t _i1493 = n_357; (S4*)_t1493->b + hr_ix(_i1493, _t1493->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:467"); }))).n_; for (int32_t _k1492 = 0; _k1492 < _e1492; _k1492++) { int32_t i_360 = (int32_t)_k1492; int64_t fi_363 = f90_kid(n_357, ((int64_t)(i_360))); 
if (((((*({ hrv *_t1495 = &(g721); int64_t _i1495 = fi_363; (S4*)_t1495->b + hr_ix(_i1495, _t1495->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:467"); }))).k_) == (((uint8_t)37LL)))) { cf_359 = true;
 } else { if (((((*({ hrv *_t1496 = &(g721); int64_t _i1496 = fi_363; (S4*)_t1496->b + hr_ix(_i1496, _t1496->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:467"); }))).s_) >= (((int32_t)0LL)))) { named_358++;
 }
 }
 } } _bk1491:; 
if ((((!(cf_359)) && ((named_358) > (((int64_t)0LL)))) && ((named_358) != (((int64_t)(((*({ hrv *_t1497 = &(g721); int64_t _i1497 = n_357; (S4*)_t1497->b + hr_ix(_i1497, _t1497->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:468"); }))).n_)))))) { (void)(f38_perr(hr_str("struct literal mixes named and positional initializers", 54)));
 }
return n_357;
}
static int64_t f90_kid(int64_t n_361, int64_t i_362) {
return ((int64_t)((*({ hrv *_t1499 = &(g722); int64_t _i1499 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1500 = &(g721); int64_t _i1500 = n_361; (S4*)_t1500->b + hr_ix(_i1500, _t1500->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:56"); }))).l_)) + (int64_t)i_362)); (int32_t*)_t1499->b + hr_ix(_i1499, _t1499->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:56"); }))));
}
static int64_t f91_pindex(int64_t obj_369) {
int64_t st_370 = g726; 
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
{ int32_t *_t1509 = &(((*({ hrv *_t1510 = &(g721); int64_t _i1510 = r_375; (S4*)_t1510->b + hr_ix(_i1510, _t1510->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:336"); }))).a_); *_t1509 = ((int32_t)(obj_369)); }
{ int32_t *_t1511 = &(((*({ hrv *_t1512 = &(g721); int64_t _i1512 = r_375; (S4*)_t1512->b + hr_ix(_i1512, _t1512->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:336"); }))).b_); *_t1511 = ((int32_t)(lo_372)); }
if (lfe_373) { { uint16_t *_t1513 = &(((*({ hrv *_t1514 = &(g721); int64_t _i1514 = r_375; (S4*)_t1514->b + hr_ix(_i1514, _t1514->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:337"); }))).fl_); *_t1513 = ((uint16_t)1LL); }
 }
if (((f31_tk()) != (((int64_t)8LL)))) { if (f41_is(((int64_t)51LL))) { { uint16_t *_t1517 = &(((*({ hrv *_t1518 = &(g721); int64_t _i1518 = r_375; (S4*)_t1518->b + hr_ix(_i1518, _t1518->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:338"); }))).fl_); *_t1517 = ((uint16_t)((uint64_t)(*_t1517) | (uint64_t)((uint16_t)2LL))); }
 }
{ int64_t q__376 = f61_pexpr(); 
{ int32_t *_t1520 = &(((*({ hrv *_t1521 = &(g721); int64_t _i1521 = r_375; (S4*)_t1521->b + hr_ix(_i1521, _t1521->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:338"); }))).c_); *_t1520 = ((int32_t)(q__376)); }
 }
 }
 } else { if (lfe_373) { (void)(f38_perr(hr_str("'^' bounds are only valid in slices", 35)));
 }
r_375 = f40_mk(((int64_t)12LL), st_370);
{ int32_t *_t1524 = &(((*({ hrv *_t1525 = &(g721); int64_t _i1525 = r_375; (S4*)_t1525->b + hr_ix(_i1525, _t1525->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:341"); }))).a_); *_t1524 = ((int32_t)(obj_369)); }
{ int32_t *_t1526 = &(((*({ hrv *_t1527 = &(g721); int64_t _i1527 = r_375; (S4*)_t1527->b + hr_ix(_i1527, _t1527->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:341"); }))).b_); *_t1526 = ((int32_t)(lo_372)); }
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
int64_t st_414 = g726; 
(void)(f33_nx());
int64_t n_415 = f40_mk(((int64_t)51LL), st_414); 
{ int64_t q__416 = f50_declname(hr_str("struct declaration", 18)); 
{ int32_t *_t1536 = &(((*({ hrv *_t1537 = &(g721); int64_t _i1537 = n_415; (S4*)_t1537->b + hr_ix(_i1537, _t1537->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:618"); }))).s_); *_t1536 = ((int32_t)(q__416)); }
 }
{ int32_t *_t1538 = &(((*({ hrv *_t1539 = &(g721); int64_t _i1539 = n_415; (S4*)_t1539->b + hr_ix(_i1539, _t1539->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:618"); }))).a_); *_t1538 = ((int32_t)(g733)); }
{ int64_t q__417 = f51_pgenerics(); 
{ int32_t *_t1541 = &(((*({ hrv *_t1542 = &(g721); int64_t _i1542 = n_415; (S4*)_t1542->b + hr_ix(_i1542, _t1542->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:619"); }))).d_); *_t1541 = ((int32_t)(q__417)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("struct declaration", 18)));
(void)(f95_pfields(n_415, hr_str("struct body", 11)));
(void)(f39_ex(((int64_t)10LL), hr_str("struct declaration", 18)));
return n_415;
}
static void f95_pfields(int64_t n_418, hsl ctx_419) {
int64_t m_420 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t f_421 = f40_mk(((int64_t)55LL), g726); 
if (f41_is(((int64_t)70LL))) { { uint16_t *_t1552 = &(((*({ hrv *_t1553 = &(g721); int64_t _i1553 = f_421; (S4*)_t1553->b + hr_ix(_i1553, _t1553->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:601"); }))).fl_); *_t1552 = ((uint16_t)4LL); }
if (((f31_tk()) == (((int64_t)2LL)))) { { int32_t *_t1555 = &(((*({ hrv *_t1556 = &(g721); int64_t _i1556 = f_421; (S4*)_t1556->b + hr_ix(_i1556, _t1556->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:601"); }))).c_); *_t1555 = ((int32_t)(((*({ hrv *_t1557 = &(g931); int64_t _i1557 = g726; (S3*)_t1557->b + hr_ix(_i1557, _t1557->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:601"); }))).v_)); }
(void)(f33_nx());
 }
 } else { bool cq_422 = f41_is(((int64_t)69LL)); 
if ((cq_422 || f41_is(((int64_t)66LL)))) { { uint16_t *_t1561 = &(((*({ hrv *_t1562 = &(g721); int64_t _i1562 = f_421; (S4*)_t1562->b + hr_ix(_i1562, _t1562->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:604"); }))).fl_); *_t1561 = ({ uint16_t _r1563; if (cq_422) { _r1563 = ((uint16_t)3LL);  } else { _r1563 = ((uint16_t)1LL);  } _r1563; }); }
 }
{ int64_t q__423 = f34_ident(ctx_419); 
{ int32_t *_t1565 = &(((*({ hrv *_t1566 = &(g721); int64_t _i1566 = f_421; (S4*)_t1566->b + hr_ix(_i1566, _t1566->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:605"); }))).s_); *_t1565 = ((int32_t)(q__423)); }
 }
if ((!(f75_amni_type()))) { (void)(f39_ex(((int64_t)13LL), ctx_419));
 }
{ int64_t q__424 = f53_ptype(); 
{ int32_t *_t1570 = &(((*({ hrv *_t1571 = &(g721); int64_t _i1571 = f_421; (S4*)_t1571->b + hr_ix(_i1571, _t1571->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:607"); }))).a_); *_t1570 = ((int32_t)(q__424)); }
 }
if (f41_is(((int64_t)36LL))) { { int64_t q__425 = f61_pexpr(); 
{ int32_t *_t1574 = &(((*({ hrv *_t1575 = &(g721); int64_t _i1575 = f_421; (S4*)_t1575->b + hr_ix(_i1575, _t1575->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:608"); }))).b_); *_t1574 = ((int32_t)(q__425)); }
 }
 }
 }
(void)(({ hrv *_v1576 = &(g723); int32_t _x1576 = ((int32_t)(f_421)); int32_t *_p1576 = (int32_t*)hr_grow(_v1576, 1, sizeof _x1576); *_p1576 = _x1576; _p1576; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1547; }
 }
 } _bk1547:; 
(void)(f59_setl(n_418, m_420));
}
static int64_t f96_penum(void) {
int64_t st_426 = g726; 
(void)(f33_nx());
int64_t n_427 = f40_mk(((int64_t)52LL), st_426); 
{ int64_t q__428 = f50_declname(hr_str("enum declaration", 16)); 
{ int32_t *_t1582 = &(((*({ hrv *_t1583 = &(g721); int64_t _i1583 = n_427; (S4*)_t1583->b + hr_ix(_i1583, _t1583->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:628"); }))).s_); *_t1582 = ((int32_t)(q__428)); }
 }
{ int32_t *_t1584 = &(((*({ hrv *_t1585 = &(g721); int64_t _i1585 = n_427; (S4*)_t1585->b + hr_ix(_i1585, _t1585->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:628"); }))).a_); *_t1584 = ((int32_t)(g733)); }
{ int64_t q__429 = f51_pgenerics(); 
{ int32_t *_t1587 = &(((*({ hrv *_t1588 = &(g721); int64_t _i1588 = n_427; (S4*)_t1588->b + hr_ix(_i1588, _t1588->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:629"); }))).d_); *_t1587 = ((int32_t)(q__429)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("enum declaration", 16)));
int64_t m_430 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t v_431 = f40_mk(((int64_t)56LL), g726); 
{ int64_t q__432 = f34_ident(hr_str("enum variant", 12)); 
{ int32_t *_t1596 = &(((*({ hrv *_t1597 = &(g721); int64_t _i1597 = v_431; (S4*)_t1597->b + hr_ix(_i1597, _t1597->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:633"); }))).s_); *_t1596 = ((int32_t)(q__432)); }
 }
if (f41_is(((int64_t)9LL))) { { uint16_t *_t1599 = &(((*({ hrv *_t1600 = &(g721); int64_t _i1600 = v_431; (S4*)_t1600->b + hr_ix(_i1600, _t1600->n, "/home/anmire/ai/amni-lang/helium-self/hc/parse.amni:634"); }))).fl_); *_t1599 = ((uint16_t)1LL); }
(void)(f95_pfields(v_431, hr_str("variant body", 12)));
(void)(f39_ex(((int64_t)10LL), hr_str("enum variant", 12)));
 }
(void)(({ hrv *_v1603 = &(g723); int32_t _x1603 = ((int32_t)(v_431)); int32_t *_p1603 = (int32_t*)hr_grow(_v1603, 1, sizeof _x1603); *_p1603 = _x1603; _p1603; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1591; }
 }
 } _bk1591:; 
(void)(f59_setl(n_427, m_430));
(void)(f39_ex(((int64_t)10LL), hr_str("enum declaration", 16)));
return n_427;
}
static void f97_collect(int64_t file_440, int64_t t0_441, int64_t t1_442) {
{ int64_t _e1608 = t1_442; for (int64_t _k1608 = t0_441; _k1608 < _e1608; _k1608++) { int64_t i_443 = (int64_t)_k1608; int64_t n_444 = ((int64_t)((*({ hrv *_t1609 = &(g724); int64_t _i1609 = i_443; (int32_t*)_t1609->b + hr_ix(_i1609, _t1609->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:27"); })))); 
S4 x_445 = (*({ hrv *_t1610 = &(g721); int64_t _i1610 = n_444; (S4*)_t1610->b + hr_ix(_i1610, _t1610->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:28"); })); 
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
if (((k_446) == (((int64_t)33LL)))) { (void)(f99_dadd(((int64_t)5LL), n_444, file_440, f98_qual(((int64_t)((x_445).c_)), ((int64_t)((*({ hrv *_t1622 = &(g722); int64_t _i1622 = (x_445).l_; (int32_t*)_t1622->b + hr_ix(_i1622, _t1622->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:34"); })))))));
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
while ((((g507).n) <= (name_453))) { (void)(({ hrv *_v1632 = &(g507); int32_t _x1632 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1632 = (int32_t*)hr_grow(_v1632, 1, sizeof _x1632); *_p1632 = _x1632; _p1632; }));
 } _bk1631:; 
int64_t i_454 = (g506).n; 
(void)(({ hrv *_v1633 = &(g506); S5 _x1633 = ((S5){ .k_ = ((uint8_t)(k_450)), .node_ = ((int32_t)(node_451)), .file_ = ((int32_t)(file_452)), .next_ = (*({ hrv *_t1634 = &(g507); int64_t _i1634 = name_453; (int32_t*)_t1634->b + hr_ix(_i1634, _t1634->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:19"); })), .name_ = ((int32_t)(name_453)), }); S5 *_p1633 = (S5*)hr_grow(_v1633, 1, sizeof _x1633); *_p1633 = _x1633; _p1633; }));
{ int32_t *_t1635 = &((*({ hrv *_t1636 = &(g507); int64_t _i1636 = name_453; (int32_t*)_t1636->b + hr_ix(_i1636, _t1636->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:20"); }))); *_t1635 = ((int32_t)(i_454)); }
}
static L49 f100_lib_path(hsl name_459) {
L49 p_460 = ({ L49 _t1637; memset(&_t1637, 0, sizeof _t1637); _t1637.n = 0; _t1637; }); 
(void)(({ L49 *_v1638 = &(p_460); hsl _s1638 = hr_sl(g510); if (_v1638->n + _s1638.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); memmove(_v1638->e + _v1638->n, _s1638.p, (size_t)_s1638.n * sizeof _v1638->e[0]); _v1638->n += _s1638.n; }));
(void)(({ L49 *_v1639 = &(p_460); uint8_t _x1639 = ((uint8_t)47LL); if (_v1639->n >= 1024) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); _v1639->e[_v1639->n] = _x1639; &_v1639->e[_v1639->n++]; }));
(void)(({ L49 *_v1640 = &(p_460); hsl _s1640 = name_459; if (_v1640->n + _s1640.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); memmove(_v1640->e + _v1640->n, _s1640.p, (size_t)_s1640.n * sizeof _v1640->e[0]); _v1640->n += _s1640.n; }));
(void)(({ L49 *_v1641 = &(p_460); hsl _s1641 = hr_str(".amni", 5); if (_v1641->n + _s1641.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:56"); memmove(_v1641->e + _v1641->n, _s1641.p, (size_t)_s1641.n * sizeof _v1641->e[0]); _v1641->n += _s1641.n; }));
return p_460;
}
static int64_t f101_load_import(int64_t name_463, int64_t from_464, int64_t t_465) {
L49 p_466 = ({ L49 _t1642; memset(&_t1642, 0, sizeof _t1642); _t1642.n = 0; _t1642; }); 
(void)(({ L49 *_v1643 = &(p_466); hsl _s1643 = hr_sl(g509); if (_v1643->n + _s1643.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:59"); memmove(_v1643->e + _v1643->n, _s1643.p, (size_t)_s1643.n * sizeof _v1643->e[0]); _v1643->n += _s1643.n; }));
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
if ((((g512).n) > (((int64_t)0LL)))) { return;
 }
S3 x_474 = (*({ hrv *_t1660 = &(g931); int64_t _i1660 = f103_max(t_470, ((int64_t)0LL)); (S3*)_t1660->b + hr_ix(_i1660, _t1660->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:14"); })); 
(void)(({ hrv *_v1662 = &(g512); hsl _s1662 = f10_nm(((int64_t)(((*({ hrv *_t1664 = &(g930); int64_t _i1664 = (x_474).f_; (S2*)_t1664->b + hr_ix(_i1664, _t1664->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:14"); }))).name_))); hr_append(_v1662, _s1662.p, _s1662.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o1665 = &(g512); hr_fs(_o1665, hr_str(":", 1)); hr_fi(_o1665, (x_474).line_); hr_fs(_o1665, hr_str(": error: ", 9)); hr_fs(_o1665, m_471); }));
}
static int64_t f103_max(int64_t a_472, int64_t b_473) {
if (((a_472) < (b_473))) { return b_473;
 }
return a_472;
}
static bool f104_check_program(void) {
g416 = f105_new_inst(((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)0LL), (g721).n, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
{ uint8_t *_t1667 = &(((*({ hrv *_t1668 = &(g401); int64_t _i1668 = g416; (S6*)_t1668->b + hr_ix(_i1668, _t1668->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:506"); }))).st_); *_t1667 = ((uint8_t)2LL); }
g414 = g416;
g415 = g416;
int64_t md_489 = f106_lookup(f8_intern(hr_str("main", 4)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)4LL)); 
if (((md_489) < (((int64_t)0LL)))) { (void)(f108_cerr(((int64_t)0LL), hr_str("no main function", 16)));
return false;
 }
{ hrv *_v1673 = &(g506); for (int64_t _k1673 = 0; _k1673 < _v1673->n; _k1673++) { S5 d_493 = ((S5*)_v1673->b)[_k1673]; int64_t i_494 = (int64_t)_k1673; if ((((((int64_t)((d_493).k_))) == (((int64_t)5LL))) && (((d_493).file_) == (((int32_t)0LL))))) { (void)(f109_global_type(i_494));
 }
 } } _bk1672:; 
int64_t mi_1502 = f255_get_inst(((int64_t)(((*({ hrv *_t1676 = &(g506); int64_t _i1676 = md_489; (S5*)_t1676->b + hr_ix(_i1676, _t1676->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:511"); }))).node_)), (g325).n, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
{ hrv *_v1678 = &(g506); for (int64_t _k1678 = 0; _k1678 < _v1678->n; _k1678++) { S5 d_1503 = ((S5*)_v1678->b)[_k1678]; int64_t i_1504 = (int64_t)_k1678; if (((((int64_t)((d_1503).k_))) == (((int64_t)5LL)))) { (void)(f109_global_type(i_1504));
 }
 } } _bk1677:; 
(void)(f261_propagate_calls());
return ((g418) == (((int64_t)0LL)));
}
static int64_t f105_new_inst(int64_t node_477, int64_t lo_478, int64_t hi_479, int64_t par_480) {
int64_t i_481 = (g401).n; 
(void)(({ hrv *_v1681 = &(g401); S6 _x1681 = ((S6){ .node_ = ((int32_t)(node_477)), .lo_ = ((int32_t)(lo_478)), .hi_ = ((int32_t)(hi_479)), .ab_ = ((int32_t)((g408).n)), .par_ = ((int32_t)(par_480)), .cfn_ = ((int32_t)(i_481)), .g0_ = ((int32_t)((g407).n)), .gn_ = ((int32_t)0LL), .ret_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .p0_ = ((int32_t)0LL), .pn_ = ((int32_t)0LL), .st_ = ((uint8_t)0LL), .blk_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .bown_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .name_ = ({ int32_t _r1682; if (((node_477) >= (((int64_t)0LL)))) { _r1682 = ((*({ hrv *_t1683 = &(g721); int64_t _i1683 = node_477; (S4*)_t1683->b + hr_ix(_i1683, _t1683->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:30"); }))).s_;  } else { _r1682 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));  } _r1682; }), }); S6 *_p1681 = (S6*)hr_grow(_v1681, 1, sizeof _x1681); *_p1681 = _x1681; _p1681; }));
int64_t n_482 = ((int64_t)((int64_t)hi_479 - (int64_t)lo_478)); 
(void)(({ hrv *_v1684 = &(g408); int64_t _k1684 = ((int64_t)((int64_t)(g408).n + (int64_t)n_482)); if (_k1684 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1684 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1684 = _v1684->n; hr_resize(_v1684, _k1684, sizeof _x1684); for (int64_t _j = _o1684; _j < _k1684; _j++) ((int32_t*)_v1684->b)[_j] = _x1684; }));
(void)(({ hrv *_v1685 = &(g409); int64_t _k1685 = ((int64_t)((int64_t)(g409).n + (int64_t)n_482)); if (_k1685 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1685 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1685 = _v1685->n; hr_resize(_v1685, _k1685, sizeof _x1685); for (int64_t _j = _o1685; _j < _k1685; _j++) ((int32_t*)_v1685->b)[_j] = _x1685; }));
(void)(({ hrv *_v1686 = &(g410); int64_t _k1686 = ((int64_t)((int64_t)(g410).n + (int64_t)n_482)); if (_k1686 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); uint8_t _x1686 = ((uint8_t)0LL); int64_t _o1686 = _v1686->n; hr_resize(_v1686, _k1686, sizeof _x1686); for (int64_t _j = _o1686; _j < _k1686; _j++) ((uint8_t*)_v1686->b)[_j] = _x1686; }));
(void)(({ hrv *_v1687 = &(g411); int64_t _k1687 = ((int64_t)((int64_t)(g411).n + (int64_t)n_482)); if (_k1687 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1687 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1687 = _v1687->n; hr_resize(_v1687, _k1687, sizeof _x1687); for (int64_t _j = _o1687; _j < _k1687; _j++) ((int32_t*)_v1687->b)[_j] = _x1687; }));
(void)(({ hrv *_v1688 = &(g412); int64_t _k1688 = ((int64_t)((int64_t)(g412).n + (int64_t)n_482)); if (_k1688 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:32"); int32_t _x1688 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1688 = _v1688->n; hr_resize(_v1688, _k1688, sizeof _x1688); for (int64_t _j = _o1688; _j < _k1688; _j++) ((int32_t*)_v1688->b)[_j] = _x1688; }));
return i_481;
}
static int64_t f106_lookup(int64_t name_483, int64_t ns_484, int64_t k_485) {
if (((ns_484) >= (((int64_t)0LL)))) { int64_t d_487 = f107_dmap(f98_qual(ns_484, name_483)); 
while (((d_487) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1692 = &(g506); int64_t _i1692 = d_487; (S5*)_t1692->b + hr_ix(_i1692, _t1692->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:74"); }))).k_))) == (k_485))) { return d_487;
 }
d_487 = ((int64_t)(((*({ hrv *_t1693 = &(g506); int64_t _i1693 = d_487; (S5*)_t1693->b + hr_ix(_i1693, _t1693->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:74"); }))).next_));
 } _bk1691:; 
 }
int64_t d_488 = f107_dmap(name_483); 
while (((d_488) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1696 = &(g506); int64_t _i1696 = d_488; (S5*)_t1696->b + hr_ix(_i1696, _t1696->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:76"); }))).k_))) == (k_485))) { return d_488;
 }
d_488 = ((int64_t)(((*({ hrv *_t1697 = &(g506); int64_t _i1697 = d_488; (S5*)_t1697->b + hr_ix(_i1697, _t1697->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:76"); }))).next_));
 } _bk1695:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f107_dmap(int64_t name_486) {
return ({ int64_t _r1698; if ((((name_486) < (((int64_t)0LL))) || ((name_486) >= ((g507).n)))) { _r1698 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1698 = ((int64_t)((*({ hrv *_t1699 = &(g507); int64_t _i1699 = name_486; (int32_t*)_t1699->b + hr_ix(_i1699, _t1699->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:15"); }))));  } _r1698; });
}
static void f108_cerr(int64_t n_490, hsl m_491) {
g418++;
if ((((g417).n) > (((int64_t)0LL)))) { return;
 }
S3 x_492 = (*({ hrv *_t1700 = &(g931); int64_t _i1700 = ((*({ hrv *_t1701 = &(g721); int64_t _i1701 = f103_max(n_490, ((int64_t)0LL)); (S4*)_t1701->b + hr_ix(_i1701, _t1701->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:27"); }))).t_; (S3*)_t1700->b + hr_ix(_i1700, _t1700->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:27"); })); 
(void)(({ hrv *_v1703 = &(g417); hsl _s1703 = f10_nm(((int64_t)(((*({ hrv *_t1705 = &(g930); int64_t _i1705 = (x_492).f_; (S2*)_t1705->b + hr_ix(_i1705, _t1705->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:27"); }))).name_))); hr_append(_v1703, _s1703.p, _s1703.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o1706 = &(g417); hr_fs(_o1706, hr_str(":", 1)); hr_fi(_o1706, (x_492).line_); hr_fs(_o1706, hr_str(": error: ", 9)); hr_fs(_o1706, m_491); }));
}
static int64_t f109_global_type(int64_t d_495) {
while ((((g464).n) < ((g506).n))) { (void)(({ hrv *_v1708 = &(g464); int32_t _x1708 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1708 = (int32_t*)hr_grow(_v1708, 1, sizeof _x1708); *_p1708 = _x1708; _p1708; }));
(void)(({ hrv *_v1709 = &(g465); uint8_t _x1709 = ((uint8_t)0LL); uint8_t *_p1709 = (uint8_t*)hr_grow(_v1709, 1, sizeof _x1709); *_p1709 = _x1709; _p1709; }));
 } _bk1707:; 
if ((((*({ hrv *_t1710 = &(g464); int64_t _i1710 = d_495; (int32_t*)_t1710->b + hr_ix(_i1710, _t1710->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:390"); }))) >= (((int32_t)0LL)))) { return ((int64_t)((*({ hrv *_t1711 = &(g464); int64_t _i1711 = d_495; (int32_t*)_t1711->b + hr_ix(_i1711, _t1711->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:390"); }))));
 }
int64_t g_496 = ((int64_t)(((*({ hrv *_t1712 = &(g506); int64_t _i1712 = d_495; (S5*)_t1712->b + hr_ix(_i1712, _t1712->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:391"); }))).node_)); 
S4 x_497 = (*({ hrv *_t1713 = &(g721); int64_t _i1713 = g_496; (S4*)_t1713->b + hr_ix(_i1713, _t1713->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:392"); })); 
int64_t saved_498 = g414; 
int64_t sc_499 = g415; 
g414 = g416;
g415 = g416;
int64_t t_500 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((x_497).a_) >= (((int32_t)0LL)))) { t_500 = f113_rtype(((int64_t)((x_497).a_)), f110_ns_of(g_496));
{ int32_t *_t1716 = &((*({ hrv *_t1717 = &(g464); int64_t _i1717 = d_495; (int32_t*)_t1717->b + hr_ix(_i1717, _t1717->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:396"); }))); *_t1716 = ((int32_t)(t_500)); }
if ((((x_497).b_) >= (((int32_t)0LL)))) { int64_t iv_670 = f90_kid(((int64_t)((x_497).b_)), ((int64_t)0LL)); 
(void)(f137_ck(iv_670, t_500));
(void)(f140_conv(iv_670, t_500));
 }
 } else { if ((((*({ hrv *_t1721 = &(g465); int64_t _i1721 = d_495; (uint8_t*)_t1721->b + hr_ix(_i1721, _t1721->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:398"); }))) == (((uint8_t)1LL)))) { (void)(f108_cerr(g_496, hr_str("global initializer depends on itself", 36)));
g414 = saved_498;
g415 = sc_499;
return g592;
 }
{ uint8_t *_t1723 = &((*({ hrv *_t1724 = &(g465); int64_t _i1724 = d_495; (uint8_t*)_t1724->b + hr_ix(_i1724, _t1724->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:399"); }))); *_t1723 = ((uint8_t)1LL); }
int64_t iv_1499 = f90_kid(((int64_t)((x_497).b_)), ((int64_t)0LL)); 
(void)(f137_ck(iv_1499, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
t_500 = f187_default_t(iv_1499);
if (((((*({ hrv *_t1728 = &(g568); int64_t _i1728 = t_500; (S1*)_t1728->b + hr_ix(_i1728, _t1728->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:403"); }))).k_) == (((uint8_t)18LL)))) { t_500 = g593;
 }
if (((((((*({ hrv *_t1729 = &(g568); int64_t _i1729 = t_500; (S1*)_t1729->b + hr_ix(_i1729, _t1729->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:404"); }))).k_) == (((uint8_t)7LL))) && (((((*({ hrv *_t1730 = &(g721); int64_t _i1730 = iv_1499; (S4*)_t1730->b + hr_ix(_i1730, _t1730->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:404"); }))).k_) == (((uint8_t)14LL))) || ((((*({ hrv *_t1731 = &(g721); int64_t _i1731 = iv_1499; (S4*)_t1731->b + hr_ix(_i1731, _t1731->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:404"); }))).k_) == (((uint8_t)17LL))))) && ((((uint16_t)((uint64_t)(x_497).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))))) { t_500 = f136_t_enum(((int64_t)(((*({ hrv *_t1733 = &(g568); int64_t _i1733 = t_500; (S1*)_t1733->b + hr_ix(_i1733, _t1733->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:404"); }))).a_)), false);
(void)(f145_set_cv(iv_1499, t_500));
 }
{ int32_t *_t1735 = &((*({ hrv *_t1736 = &(g464); int64_t _i1736 = d_495; (int32_t*)_t1736->b + hr_ix(_i1736, _t1736->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:405"); }))); *_t1735 = ((int32_t)(t_500)); }
 }
if ((!(f260_ORD_HAS(d_495)))) { (void)(({ hrv *_v1738 = &(g422); int32_t _x1738 = ((int32_t)(d_495)); int32_t *_p1738 = (int32_t*)hr_grow(_v1738, 1, sizeof _x1738); *_p1738 = _x1738; _p1738; }));
 }
g414 = saved_498;
g415 = sc_499;
return t_500;
}
static int64_t f110_ns_of(int64_t n_501) {
return f112_file_ns(f111_node_file(n_501));
}
static int64_t f111_node_file(int64_t n_502) {
return ((int64_t)(((*({ hrv *_t1741 = &(g931); int64_t _i1741 = ((*({ hrv *_t1742 = &(g721); int64_t _i1742 = n_502; (S4*)_t1742->b + hr_ix(_i1742, _t1742->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:23"); }))).t_; (S3*)_t1741->b + hr_ix(_i1741, _t1741->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:23"); }))).f_));
}
static int64_t f112_file_ns(int64_t f_503) {
return ({ int64_t _r1743; if (((f_503) < ((g513).n))) { _r1743 = ((int64_t)((*({ hrv *_t1744 = &(g513); int64_t _i1744 = f_503; (int32_t*)_t1744->b + hr_ix(_i1744, _t1744->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:24"); }))));  } else { _r1743 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1743; });
}
static int64_t f113_rtype(int64_t n_504, int64_t ns_505) {
if (((n_504) < (((int64_t)0LL)))) { return g575;
 }
S4 x_506 = (*({ hrv *_t1745 = &(g721); int64_t _i1745 = n_504; (S4*)_t1745->b + hr_ix(_i1745, _t1745->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:93"); })); 
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
if ((((((*({ hrv *_t1757 = &(g568); int64_t _i1757 = e_512; (S1*)_t1757->b + hr_ix(_i1757, _t1757->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t1758 = &(g568); int64_t _i1758 = e_512; (S1*)_t1758->b + hr_ix(_i1758, _t1758->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).c_) < (((int32_t)0LL))))) { if (((((int64_t)((int64_t)fl_513 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { return f119_t_ref(((int64_t)(((*({ hrv *_t1760 = &(g568); int64_t _i1760 = e_512; (S1*)_t1760->b + hr_ix(_i1760, _t1760->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).a_)), ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1761 = &(g568); int64_t _i1761 = e_512; (S1*)_t1761->b + hr_ix(_i1761, _t1761->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:107"); }))).fl_)) | (int64_t)((int64_t)2LL))));
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
if (((((*({ hrv *_t1780 = &(g568); int64_t _i1780 = b_593; (S1*)_t1780->b + hr_ix(_i1780, _t1780->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:120"); }))).k_) != (((uint8_t)6LL)))) { (void)(f102_derr(((int64_t)((x_506).t_)), hr_str("variant type of a non-enum", 26)));
return g592;
 }
int64_t ei_594 = ((int64_t)(((*({ hrv *_t1782 = &(g568); int64_t _i1782 = b_593; (S1*)_t1782->b + hr_ix(_i1782, _t1782->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:121"); }))).a_)); 
{ int32_t _e1784 = ((*({ hrv *_t1785 = &(g573); int64_t _i1785 = ei_594; (S8*)_t1785->b + hr_ix(_i1785, _t1785->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:122"); }))).vnum_; for (int32_t _k1784 = 0; _k1784 < _e1784; _k1784++) { int32_t i_595 = (int32_t)_k1784; if (((((*({ hrv *_t1786 = &(g574); int64_t _i1786 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1787 = &(g573); int64_t _i1787 = ei_594; (S8*)_t1787->b + hr_ix(_i1787, _t1787->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:122"); }))).v0_)) + (int64_t)((int64_t)(i_595)))); (S9*)_t1786->b + hr_ix(_i1786, _t1786->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:122"); }))).name_) == ((x_506).s_))) { return f125_t_variant(ei_594, ((int64_t)(i_595)));
 }
 } } _bk1783:; 
hrv m_598 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1792 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1790 = &(m_598); hr_fs(_o1790, hr_str("no variant ", 11)); hr_fs(_o1790, f10_nm(((int64_t)((x_506).s_)))); hr_fs(_o1790, hr_str(" in ", 4)); hr_fs(_o1790, hr_sl(*hr_tmp(&_t1792, f126_ty_name(b_593)))); }));
}
(void)(f102_derr(((int64_t)((x_506).t_)), hr_sl(m_598)));
return g592;
 }
if (((k_507) == (((int64_t)45LL)))) { return g595;
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
if (((d_621) >= (((int64_t)0LL)))) { return f134_t_struct(f131_inst_struct(((int64_t)(((*({ hrv *_t1805 = &(g506); int64_t _i1805 = d_621; (S5*)_t1805->b + hr_ix(_i1805, _t1805->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:133"); }))).node_)), ({ hsl _t1806 = ({ L66 *_t1807 = &(args_618); (hsl){ (uint8_t*)_t1807->e, _t1807->n }; }); int64_t _l1806 = 0, _h1806 = _t1806.n; if (_l1806 < 0 || _h1806 < _l1806 || _h1806 > _t1806.n) hr_slerr(_l1806, _h1806, _t1806.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:133"); (hsl){ _t1806.p + _l1806 * (int64_t)sizeof(int32_t), _h1806 - _l1806 }; })));
 }
d_621 = f116_lookup_q(name_614, ns_505, ((int64_t)2LL));
if (((d_621) >= (((int64_t)0LL)))) { return f136_t_enum(f135_inst_enum(((int64_t)(((*({ hrv *_t1811 = &(g506); int64_t _i1811 = d_621; (S5*)_t1811->b + hr_ix(_i1811, _t1811->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:135"); }))).node_)), ({ hsl _t1812 = ({ L66 *_t1813 = &(args_618); (hsl){ (uint8_t*)_t1813->e, _t1813->n }; }); int64_t _l1812 = 0, _h1812 = _t1812.n; if (_l1812 < 0 || _h1812 < _l1812 || _h1812 > _t1812.n) hr_slerr(_l1812, _h1812, _t1812.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:135"); (hsl){ _t1812.p + _l1812 * (int64_t)sizeof(int32_t), _h1812 - _l1812 }; })), ((((uint16_t)((uint64_t)(x_506).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))));
 }
d_621 = f116_lookup_q(name_614, ns_505, ((int64_t)3LL));
if (((d_621) >= (((int64_t)0LL)))) { int64_t an_668 = ((int64_t)(((*({ hrv *_t1815 = &(g506); int64_t _i1815 = d_621; (S5*)_t1815->b + hr_ix(_i1815, _t1815->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:137"); }))).node_)); 
return f113_rtype(((int64_t)(((*({ hrv *_t1817 = &(g721); int64_t _i1817 = an_668; (S4*)_t1817->b + hr_ix(_i1817, _t1817->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:137"); }))).b_)), f110_ns_of(an_668));
 }
hrv m_669 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1820 = &(m_669); hr_fs(_o1820, hr_str("unknown type ", 13)); hr_fs(_o1820, f10_nm(name_614)); }));
(void)(f102_derr(((int64_t)((x_506).t_)), hr_sl(m_669)));
return g592;
 }
(void)(f102_derr(((int64_t)((x_506).t_)), hr_str("bad type", 8)));
return g592;
}
static int64_t f114_prim_type(int64_t k_508) {
if (((k_508) == (((int64_t)89LL)))) { return g576;
 }
if (((k_508) == (((int64_t)90LL)))) { return g591;
 }
if (((k_508) == (((int64_t)99LL)))) { return g585;
 }
if ((((k_508) == (((int64_t)100LL))) || ((k_508) == (((int64_t)104LL))))) { return g586;
 }
int64_t s_510 = f115_int_storage_of_tok(k_508); 
return ({ int64_t _r1825; if (((s_510) >= (((int64_t)0LL)))) { _r1825 = f17_t_int(s_510);  } else { _r1825 = g592;  } _r1825; });
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
while (((d_523) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1832 = &(g506); int64_t _i1832 = d_523; (S5*)_t1832->b + hr_ix(_i1832, _t1832->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:87"); }))).k_))) == (k_517))) { return d_523;
 }
d_523 = ((int64_t)(((*({ hrv *_t1833 = &(g506); int64_t _i1833 = d_523; (S5*)_t1833->b + hr_ix(_i1833, _t1833->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:87"); }))).next_));
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
S4 x_537 = (*({ hrv *_t1850 = &(g721); int64_t _i1850 = n_535; (S4*)_t1850->b + hr_ix(_i1850, _t1850->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:205"); })); 
int64_t k_538 = ((int64_t)((x_537).k_)); 
if (((k_538) == (((int64_t)1LL)))) { return (M57){ ((*({ hrv *_t1851 = &(g931); int64_t _i1851 = (x_537).t_; (S3*)_t1851->b + hr_ix(_i1851, _t1851->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:207"); }))).v_, ({ int64_t _r1852; if (((*({ hrv *_t1853 = &(g931); int64_t _i1853 = (x_537).t_; (S3*)_t1853->b + hr_ix(_i1853, _t1853->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:207"); }))).uns_) { _r1852 = ((int64_t)7LL);  } else { _r1852 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1852; }), true };
 }
if (((k_538) == (((int64_t)10LL)))) { M57 _t1854 = f121_ceval3(((int64_t)((x_537).a_)), ns_536); int64_t v_539 = _t1854.r0; int64_t c_540 = _t1854.r1; bool ok_541 = _t1854.r2; 
if (((((int64_t)((x_537).op_))) == (((int64_t)22LL)))) { int64_t c2_542 = ({ int64_t _r1856; if ((((c_540) == (((int64_t)7LL))) && ((((*({ hrv *_t1857 = &(g721); int64_t _i1857 = (x_537).a_; (S4*)_t1857->b + hr_ix(_i1857, _t1857->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:210"); }))).k_) == (((uint8_t)1LL))))) { _r1856 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1856 = c_540;  } _r1856; }); 
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
if (((((*({ hrv *_t1886 = &(g721); int64_t _i1886 = tn0_564; (S4*)_t1886->b + hr_ix(_i1886, _t1886->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:231"); }))).k_) == (((uint8_t)40LL)))) { int64_t tc_565 = f115_int_storage_of_tok(((int64_t)(((*({ hrv *_t1888 = &(g721); int64_t _i1888 = tn0_564; (S4*)_t1888->b + hr_ix(_i1888, _t1888->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:231"); }))).op_))); 
if (((tc_565) >= (((int64_t)0LL)))) { return (M57){ f122_cwrap(v_561, tc_565), tc_565, ok_563 };
 }
 }
return (M57){ v_561, c_562, ok_563 };
 }
if (((k_538) == (((int64_t)8LL)))) { int64_t d_566 = f116_lookup_q(((int64_t)((x_537).s_)), ns_536, ((int64_t)5LL)); 
if (((d_566) < (((int64_t)0LL)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
int64_t g_567 = ((int64_t)(((*({ hrv *_t1891 = &(g506); int64_t _i1891 = d_566; (S5*)_t1891->b + hr_ix(_i1891, _t1891->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:235"); }))).node_)); 
if ((((((uint16_t)((uint64_t)((*({ hrv *_t1892 = &(g721); int64_t _i1892 = g_567; (S4*)_t1892->b + hr_ix(_i1892, _t1892->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:236"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || ((((*({ hrv *_t1893 = &(g721); int64_t _i1893 = g_567; (S4*)_t1893->b + hr_ix(_i1893, _t1893->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:236"); }))).b_) < (((int32_t)0LL))))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
M57 _t1894 = f121_ceval3(f90_kid(((int64_t)(((*({ hrv *_t1897 = &(g721); int64_t _i1897 = g_567; (S4*)_t1897->b + hr_ix(_i1897, _t1897->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:237"); }))).b_)), ((int64_t)0LL)), f110_ns_of(g_567)); int64_t v_568 = _t1894.r0; int64_t c_569 = _t1894.r1; bool ok_570 = _t1894.r2; 
int64_t tn0_571 = ((int64_t)(((*({ hrv *_t1899 = &(g721); int64_t _i1899 = g_567; (S4*)_t1899->b + hr_ix(_i1899, _t1899->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:238"); }))).a_)); 
if ((((tn0_571) >= (((int64_t)0LL))) && ((((*({ hrv *_t1900 = &(g721); int64_t _i1900 = tn0_571; (S4*)_t1900->b + hr_ix(_i1900, _t1900->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:239"); }))).k_) == (((uint8_t)40LL))))) { int64_t tc_572 = f115_int_storage_of_tok(((int64_t)(((*({ hrv *_t1902 = &(g721); int64_t _i1902 = tn0_571; (S4*)_t1902->b + hr_ix(_i1902, _t1902->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:239"); }))).op_))); 
if (((tc_572) >= (((int64_t)0LL)))) { return (M57){ f122_cwrap(v_568, tc_572), tc_572, ok_570 };
 }
 }
return (M57){ v_568, c_569, ok_570 };
 }
if (((((k_538) == (((int64_t)14LL))) && hr_streq(f10_nm(((int64_t)((x_537).s_))), hr_str("len", 3))) && ((((*({ hrv *_t1905 = &(g721); int64_t _i1905 = (x_537).a_; (S4*)_t1905->b + hr_ix(_i1905, _t1905->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:242"); }))).k_) == (((uint8_t)8LL))))) { int64_t d_573 = f116_lookup_q(((int64_t)(((*({ hrv *_t1907 = &(g721); int64_t _i1907 = (x_537).a_; (S4*)_t1907->b + hr_ix(_i1907, _t1907->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:243"); }))).s_)), ns_536, ((int64_t)5LL)); 
if (((d_573) < (((int64_t)0LL)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
int64_t g_574 = ((int64_t)(((*({ hrv *_t1908 = &(g506); int64_t _i1908 = d_573; (S5*)_t1908->b + hr_ix(_i1908, _t1908->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:245"); }))).node_)); 
if (((((*({ hrv *_t1909 = &(g721); int64_t _i1909 = g_574; (S4*)_t1909->b + hr_ix(_i1909, _t1909->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).a_) >= (((int32_t)0LL)))) { int64_t t_575 = f113_rtype(((int64_t)(((*({ hrv *_t1911 = &(g721); int64_t _i1911 = g_574; (S4*)_t1911->b + hr_ix(_i1911, _t1911->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).a_)), f110_ns_of(g_574)); 
if ((((((*({ hrv *_t1913 = &(g568); int64_t _i1913 = t_575; (S1*)_t1913->b + hr_ix(_i1913, _t1913->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).k_) == (((uint8_t)8LL))) && ((((*({ hrv *_t1914 = &(g568); int64_t _i1914 = t_575; (S1*)_t1914->b + hr_ix(_i1914, _t1914->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).s_) == (((uint8_t)(((uint8_t)1LL))))))) { return (M57){ ((*({ hrv *_t1915 = &(g568); int64_t _i1915 = t_575; (S1*)_t1915->b + hr_ix(_i1915, _t1915->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:246"); }))).b_, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
 }
 }
if (((((*({ hrv *_t1916 = &(g721); int64_t _i1916 = g_574; (S4*)_t1916->b + hr_ix(_i1916, _t1916->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_) >= (((int32_t)0LL)))) { int64_t iv_576 = f90_kid(((int64_t)(((*({ hrv *_t1918 = &(g721); int64_t _i1918 = g_574; (S4*)_t1918->b + hr_ix(_i1918, _t1918->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_)), ((int64_t)0LL)); 
if (((((*({ hrv *_t1919 = &(g721); int64_t _i1919 = iv_576; (S4*)_t1919->b + hr_ix(_i1919, _t1919->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).k_) == (((uint8_t)16LL)))) { if (((((*({ hrv *_t1920 = &(g721); int64_t _i1920 = iv_576; (S4*)_t1920->b + hr_ix(_i1920, _t1920->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_) >= (((int32_t)0LL)))) { M57 _t1921 = f121_ceval3(((int64_t)(((*({ hrv *_t1923 = &(g721); int64_t _i1923 = iv_576; (S4*)_t1923->b + hr_ix(_i1923, _t1923->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).b_)), f110_ns_of(g_574)); int64_t v_577 = _t1921.r0; int64_t c_578 = _t1921.r1; bool ok_579 = _t1921.r2; 
return (M57){ v_577, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ok_579 };
 }
return (M57){ ((int64_t)(((*({ hrv *_t1925 = &(g721); int64_t _i1925 = iv_576; (S4*)_t1925->b + hr_ix(_i1925, _t1925->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).n_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
 }
if (((((*({ hrv *_t1926 = &(g721); int64_t _i1926 = iv_576; (S4*)_t1926->b + hr_ix(_i1926, _t1926->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).k_) == (((uint8_t)3LL)))) { return (M57){ ((int64_t)(((*({ hrv *_t1927 = &(g931); int64_t _i1927 = ((*({ hrv *_t1928 = &(g721); int64_t _i1928 = iv_576; (S4*)_t1928->b + hr_ix(_i1928, _t1928->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).t_; (S3*)_t1927->b + hr_ix(_i1927, _t1927->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:247"); }))).w_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
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
S1 x_603 = (*({ hrv *_t1937 = &(g568); int64_t _i1937 = t_601; (S1*)_t1937->b + hr_ix(_i1937, _t1937->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:199"); })); 
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
if (((k_604) == (((int64_t)5LL)))) { (void)(({ hrv *_v1951 = out_602; hsl _s1951 = f10_nm(((int64_t)(((*({ hrv *_t1953 = &(g571); int64_t _i1953 = (x_603).a_; (S10*)_t1953->b + hr_ix(_i1953, _t1953->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:212"); }))).name_))); hr_append(_v1951, _s1951.p, _s1951.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1955 = &(g571); int64_t _i1955 = (x_603).a_; (S10*)_t1955->b + hr_ix(_i1955, _t1955->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:212"); }))).ta_)), ((int64_t)(((*({ hrv *_t1956 = &(g571); int64_t _i1956 = (x_603).a_; (S10*)_t1956->b + hr_ix(_i1956, _t1956->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:212"); }))).tn_)), out_602));
return;
 }
if (((k_604) == (((int64_t)6LL)))) { (void)(({ hrv *_v1957 = out_602; hsl _s1957 = f10_nm(((int64_t)(((*({ hrv *_t1959 = &(g573); int64_t _i1959 = (x_603).a_; (S8*)_t1959->b + hr_ix(_i1959, _t1959->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:213"); }))).name_))); hr_append(_v1957, _s1957.p, _s1957.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1961 = &(g573); int64_t _i1961 = (x_603).a_; (S8*)_t1961->b + hr_ix(_i1961, _t1961->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:213"); }))).ta_)), ((int64_t)(((*({ hrv *_t1962 = &(g573); int64_t _i1962 = (x_603).a_; (S8*)_t1962->b + hr_ix(_i1962, _t1962->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:213"); }))).tn_)), out_602));
if (((((uint16_t)((uint64_t)(x_603).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v1963 = out_602; hsl _s1963 = hr_str("..", 2); hr_append(_v1963, _s1963.p, _s1963.n, sizeof(uint8_t)); }));
 }
return;
 }
if (((k_604) == (((int64_t)7LL)))) { (void)(({ hrv *_v1964 = out_602; hsl _s1964 = f10_nm(((int64_t)(((*({ hrv *_t1966 = &(g573); int64_t _i1966 = (x_603).a_; (S8*)_t1966->b + hr_ix(_i1966, _t1966->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).name_))); hr_append(_v1964, _s1964.p, _s1964.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1968 = &(g573); int64_t _i1968 = (x_603).a_; (S8*)_t1968->b + hr_ix(_i1968, _t1968->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).ta_)), ((int64_t)(((*({ hrv *_t1969 = &(g573); int64_t _i1969 = (x_603).a_; (S8*)_t1969->b + hr_ix(_i1969, _t1969->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).tn_)), out_602));
(void)(({ hrv *_v1970 = out_602; uint8_t _x1970 = ((uint8_t)46LL); uint8_t *_p1970 = (uint8_t*)hr_grow(_v1970, 1, sizeof _x1970); *_p1970 = _x1970; _p1970; }));
(void)(({ hrv *_v1971 = out_602; hsl _s1971 = f10_nm(((int64_t)(((*({ hrv *_t1973 = &(g574); int64_t _i1973 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1974 = &(g573); int64_t _i1974 = (x_603).a_; (S8*)_t1974->b + hr_ix(_i1974, _t1974->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).v0_)) + (int64_t)((int64_t)((x_603).c_)))); (S9*)_t1973->b + hr_ix(_i1973, _t1973->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:214"); }))).name_))); hr_append(_v1971, _s1971.p, _s1971.n, sizeof(uint8_t)); }));
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
(void)(f127_ty_name_into(((int64_t)((*({ hrv *_t2002 = &(g569); int64_t _i2002 = ((int64_t)((int64_t)((int64_t)((x_603).l_)) + (int64_t)((int64_t)(i_613)))); (int32_t*)_t2002->b + hr_ix(_i2002, _t2002->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:232"); })))), out_602));
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
(void)(f127_ty_name_into(((int64_t)((*({ hrv *_t2012 = &(g569); int64_t _i2012 = ((int64_t)((int64_t)l_608 + (int64_t)i_611)); (int32_t*)_t2012->b + hr_ix(_i2012, _t2012->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:235"); })))), out_610));
 } } _bk2008:; 
(void)(({ hrv *_v2013 = out_610; uint8_t _x2013 = ((uint8_t)62LL); uint8_t *_p2013 = (uint8_t*)hr_grow(_v2013, 1, sizeof _x2013); *_p2013 = _x2013; _p2013; }));
}
static int64_t f130_gb_find(int64_t name_615) {
int64_t i_616 = ((int64_t)((int64_t)(g508).n - (int64_t)((int64_t)1LL))); 
while (((i_616) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t2015 = &(g508); int64_t _i2015 = i_616; (S7*)_t2015->b + hr_ix(_i2015, _t2015->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:72"); }))).name_))) == (name_615))) { return ((int64_t)(((*({ hrv *_t2016 = &(g508); int64_t _i2016 = i_616; (S7*)_t2016->b + hr_ix(_i2016, _t2016->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:72"); }))).ty_));
 }
i_616--;
 } _bk2014:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f131_inst_struct(int64_t node_622, hsl args_623) {
{ hrv *_v2018 = &(g571); for (int64_t _k2018 = 0; _k2018 < _v2018->n; _k2018++) { S10 s_624 = ((S10*)_v2018->b)[_k2018]; int64_t i_625 = (int64_t)_k2018; if ((((((int64_t)((s_624).node_))) == (node_622)) && ((((int64_t)((s_624).tn_))) == ((args_623).n)))) { bool same_626 = true; 
{ int64_t _e2020 = (args_623).n; for (int64_t _k2020 = 0; _k2020 < _e2020; _k2020++) { int64_t j_627 = (int64_t)_k2020; if ((((*({ hrv *_t2021 = &(g569); int64_t _i2021 = ((int64_t)((int64_t)((int64_t)((s_624).ta_)) + (int64_t)j_627)); (int32_t*)_t2021->b + hr_ix(_i2021, _t2021->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:146"); }))) != ((*({ hsl _t2022 = args_623; int64_t _i2022 = j_627; (int32_t*)_t2022.p + hr_ix(_i2022, _t2022.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:146"); }))))) { same_626 = false;
 }
 } } _bk2019:; 
if (same_626) { return i_625;
 }
 }
 } } _bk2017:; 
int64_t ta_628 = (g569).n; 
(void)(({ hrv *_v2023 = &(g569); hsl _s2023 = args_623; hr_append(_v2023, _s2023.p, _s2023.n, sizeof(int32_t)); }));
int64_t si_629 = (g571).n; 
(void)(({ hrv *_v2024 = &(g571); S10 _x2024 = ((S10){ .node_ = ((int32_t)(node_622)), .ta_ = ((int32_t)(ta_628)), .tn_ = ((int32_t)((args_623).n)), .f0_ = ((int32_t)((g572).n)), .fnum_ = ((int32_t)0LL), .name_ = ((*({ hrv *_t2025 = &(g721); int64_t _i2025 = node_622; (S4*)_t2025->b + hr_ix(_i2025, _t2025->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:149"); }))).s_, }); S10 *_p2024 = (S10*)hr_grow(_v2024, 1, sizeof _x2024); *_p2024 = _x2024; _p2024; }));
L66 gn_630 = ({ L66 _t2026; memset(&_t2026, 0, sizeof _t2026); _t2026.n = 0; _t2026; }); 
(void)(f132_gen_names(((int64_t)(((*({ hrv *_t2028 = &(g721); int64_t _i2028 = node_622; (S4*)_t2028->b + hr_ix(_i2028, _t2028->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:150"); }))).d_)), (&(gn_630))));
if (((((int64_t)(gn_630).n)) != ((args_623).n))) { (void)(f102_derr(((int64_t)(((*({ hrv *_t2030 = &(g721); int64_t _i2030 = node_622; (S4*)_t2030->b + hr_ix(_i2030, _t2030->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:151"); }))).t_)), hr_str("wrong number of type arguments", 30)));
 }
int64_t g0_634 = (g508).n; 
{ int64_t _e2032 = f45_min(((int64_t)(gn_630).n), (args_623).n); for (int64_t _k2032 = 0; _k2032 < _e2032; _k2032++) { int64_t i_635 = (int64_t)_k2032; (void)(({ hrv *_v2034 = &(g508); S7 _x2034 = ((S7){ .name_ = (*({ L66 *_t2035 = &(gn_630); int64_t _i2035 = i_635; _t2035->e + hr_ix(_i2035, _t2035->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:153"); })), .ty_ = (*({ hsl _t2036 = args_623; int64_t _i2036 = i_635; (int32_t*)_t2036.p + hr_ix(_i2036, _t2036.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:153"); })), }); S7 *_p2034 = (S7*)hr_grow(_v2034, 1, sizeof _x2034); *_p2034 = _x2034; _p2034; }));
 } } _bk2031:; 
int64_t f0_644 = f133_fields_into(node_622, f110_ns_of(node_622)); 
{ int32_t *_t2039 = &(((*({ hrv *_t2040 = &(g571); int64_t _i2040 = si_629; (S10*)_t2040->b + hr_ix(_i2040, _t2040->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:155"); }))).f0_); *_t2039 = ((int32_t)(f0_644)); }
{ int32_t *_t2041 = &(((*({ hrv *_t2042 = &(g571); int64_t _i2042 = si_629; (S10*)_t2042->b + hr_ix(_i2042, _t2042->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:155"); }))).fnum_); *_t2041 = ((int32_t)(((int64_t)((int64_t)(g572).n - (int64_t)f0_644)))); }
(void)(({ hrv *_v2043 = &(g508); int64_t _k2043 = ((int64_t)((int64_t)(g508).n - (int64_t)g0_634)); if (_k2043 < 0 || _k2043 > _v2043->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:156"); _v2043->n -= _k2043; }));
return si_629;
}
static void f132_gen_names(int64_t gl_631, L66* out_632) {
if (((gl_631) >= (((int64_t)0LL)))) { { int32_t _e2045 = ((*({ hrv *_t2046 = &(g721); int64_t _i2046 = gl_631; (S4*)_t2046->b + hr_ix(_i2046, _t2046->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:144"); }))).n_; for (int32_t _k2045 = 0; _k2045 < _e2045; _k2045++) { int32_t i_633 = (int32_t)_k2045; (void)(({ L66 *_v2047 = out_632; int32_t _x2047 = ((*({ hrv *_t2048 = &(g721); int64_t _i2048 = f90_kid(gl_631, ((int64_t)(i_633))); (S4*)_t2048->b + hr_ix(_i2048, _t2048->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:144"); }))).s_; if (_v2047->n >= 16) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:144"); _v2047->e[_v2047->n] = _x2047; &_v2047->e[_v2047->n++]; }));
 } } _bk2044:; 
 }
}
static int64_t f133_fields_into(int64_t node_636, int64_t ns_637) {
L73 buf_638 = ({ L73 _t2050; memset(&_t2050, 0, sizeof _t2050); _t2050.n = 0; _t2050; }); 
{ int32_t _e2052 = ((*({ hrv *_t2053 = &(g721); int64_t _i2053 = node_636; (S4*)_t2053->b + hr_ix(_i2053, _t2053->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:161"); }))).n_; for (int32_t _k2052 = 0; _k2052 < _e2052; _k2052++) { int32_t i_639 = (int32_t)_k2052; int64_t f_640 = f90_kid(node_636, ((int64_t)(i_639))); 
S4 x_641 = (*({ hrv *_t2055 = &(g721); int64_t _i2055 = f_640; (S4*)_t2055->b + hr_ix(_i2055, _t2055->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:163"); })); 
if (((((uint16_t)((uint64_t)(x_641).fl_ & (uint64_t)((uint16_t)4LL)))) != (((uint16_t)0LL)))) { (void)(({ L73 *_v2056 = &(buf_638); S11 _x2056 = ((S11){ .name_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .def_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .fl_ = (x_641).fl_, .padn_ = (x_641).c_, .off_ = ((int64_t)0LL), }); if (_v2056->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:164"); _v2056->e[_v2056->n] = _x2056; &_v2056->e[_v2056->n++]; }));
continue;
 }
int64_t ft_642 = f113_rtype(((int64_t)((x_641).a_)), ns_637); 
(void)(({ L73 *_v2058 = &(buf_638); S11 _x2058 = ((S11){ .name_ = (x_641).s_, .ty_ = ((int32_t)(ft_642)), .def_ = (x_641).b_, .fl_ = (x_641).fl_, .padn_ = ((int32_t)0LL), .off_ = ((int64_t)0LL), }); if (_v2058->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:166"); _v2058->e[_v2058->n] = _x2058; &_v2058->e[_v2058->n++]; }));
 } } _bk2051:; 
int64_t f0_643 = (g572).n; 
(void)(({ hrv *_v2059 = &(g572); hsl _s2059 = ({ hsl _t2060 = ({ L73 *_t2061 = &(buf_638); (hsl){ (uint8_t*)_t2061->e, _t2061->n }; }); int64_t _l2060 = 0, _h2060 = _t2060.n; if (_l2060 < 0 || _h2060 < _l2060 || _h2060 > _t2060.n) hr_slerr(_l2060, _h2060, _t2060.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:169"); (hsl){ _t2060.p + _l2060 * (int64_t)sizeof(S11), _h2060 - _l2060 }; }); hr_append(_v2059, _s2059.p, _s2059.n, sizeof(S11)); }));
return f0_643;
}
static int64_t f134_t_struct(int64_t si_645) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)5LL))), .a_ = ((int32_t)(si_645)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f135_inst_enum(int64_t node_646, hsl args_647) {
{ hrv *_v2064 = &(g573); for (int64_t _k2064 = 0; _k2064 < _v2064->n; _k2064++) { S8 s_648 = ((S8*)_v2064->b)[_k2064]; int64_t i_649 = (int64_t)_k2064; if ((((((int64_t)((s_648).node_))) == (node_646)) && ((((int64_t)((s_648).tn_))) == ((args_647).n)))) { bool same_650 = true; 
{ int64_t _e2066 = (args_647).n; for (int64_t _k2066 = 0; _k2066 < _e2066; _k2066++) { int64_t j_651 = (int64_t)_k2066; if ((((*({ hrv *_t2067 = &(g569); int64_t _i2067 = ((int64_t)((int64_t)((int64_t)((s_648).ta_)) + (int64_t)j_651)); (int32_t*)_t2067->b + hr_ix(_i2067, _t2067->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:173"); }))) != ((*({ hsl _t2068 = args_647; int64_t _i2068 = j_651; (int32_t*)_t2068.p + hr_ix(_i2068, _t2068.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:173"); }))))) { same_650 = false;
 }
 } } _bk2065:; 
if (same_650) { return i_649;
 }
 }
 } } _bk2063:; 
int64_t ta_652 = (g569).n; 
(void)(({ hrv *_v2069 = &(g569); hsl _s2069 = args_647; hr_append(_v2069, _s2069.p, _s2069.n, sizeof(int32_t)); }));
int64_t ei_653 = (g573).n; 
int64_t nv_654 = ((int64_t)(((*({ hrv *_t2070 = &(g721); int64_t _i2070 = node_646; (S4*)_t2070->b + hr_ix(_i2070, _t2070->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:176"); }))).n_)); 
(void)(({ hrv *_v2071 = &(g573); S8 _x2071 = ((S8){ .node_ = ((int32_t)(node_646)), .ta_ = ((int32_t)(ta_652)), .tn_ = ((int32_t)((args_647).n)), .v0_ = ((int32_t)((g574).n)), .vnum_ = ((int32_t)(nv_654)), .name_ = ((*({ hrv *_t2072 = &(g721); int64_t _i2072 = node_646; (S4*)_t2072->b + hr_ix(_i2072, _t2072->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:177"); }))).s_, }); S8 *_p2071 = (S8*)hr_grow(_v2071, 1, sizeof _x2071); *_p2071 = _x2071; _p2071; }));
int64_t v0_655 = (g574).n; 
{ int64_t _e2074 = nv_654; for (int64_t _k2074 = 0; _k2074 < _e2074; _k2074++) { int64_t i_656 = (int64_t)_k2074; int64_t v_657 = f90_kid(node_646, i_656); 
(void)(({ hrv *_v2076 = &(g574); S9 _x2076 = ((S9){ .name_ = ((*({ hrv *_t2077 = &(g721); int64_t _i2077 = v_657; (S4*)_t2077->b + hr_ix(_i2077, _t2077->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:179"); }))).s_, .f0_ = ((int32_t)0LL), .fnum_ = ((int32_t)0LL), .si_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .size_ = ((int64_t)0LL), .haspay_ = ((((uint16_t)((uint64_t)((*({ hrv *_t2078 = &(g721); int64_t _i2078 = v_657; (S4*)_t2078->b + hr_ix(_i2078, _t2078->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:179"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))), }); S9 *_p2076 = (S9*)hr_grow(_v2076, 1, sizeof _x2076); *_p2076 = _x2076; _p2076; }));
 } } _bk2073:; 
L66 gn_658 = ({ L66 _t2079; memset(&_t2079, 0, sizeof _t2079); _t2079.n = 0; _t2079; }); 
(void)(f132_gen_names(((int64_t)(((*({ hrv *_t2081 = &(g721); int64_t _i2081 = node_646; (S4*)_t2081->b + hr_ix(_i2081, _t2081->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:180"); }))).d_)), (&(gn_658))));
int64_t g0_659 = (g508).n; 
{ int64_t _e2083 = f45_min(((int64_t)(gn_658).n), (args_647).n); for (int64_t _k2083 = 0; _k2083 < _e2083; _k2083++) { int64_t i_660 = (int64_t)_k2083; (void)(({ hrv *_v2085 = &(g508); S7 _x2085 = ((S7){ .name_ = (*({ L66 *_t2086 = &(gn_658); int64_t _i2086 = i_660; _t2086->e + hr_ix(_i2086, _t2086->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:182"); })), .ty_ = (*({ hsl _t2087 = args_647; int64_t _i2087 = i_660; (int32_t*)_t2087.p + hr_ix(_i2087, _t2087.n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:182"); })), }); S7 *_p2085 = (S7*)hr_grow(_v2085, 1, sizeof _x2085); *_p2085 = _x2085; _p2085; }));
 } } _bk2082:; 
int64_t ns_661 = f110_ns_of(node_646); 
{ int64_t _e2090 = nv_654; for (int64_t _k2090 = 0; _k2090 < _e2090; _k2090++) { int64_t i_662 = (int64_t)_k2090; int64_t v_663 = f90_kid(node_646, i_662); 
int64_t si_664 = (g571).n; 
(void)(({ hrv *_v2092 = &(g571); S10 _x2092 = ((S10){ .node_ = ((int32_t)(v_663)), .ta_ = ((int32_t)(ta_652)), .tn_ = ((int32_t)((args_647).n)), .f0_ = ((int32_t)((g572).n)), .fnum_ = ((int32_t)0LL), .name_ = ((*({ hrv *_t2093 = &(g721); int64_t _i2093 = v_663; (S4*)_t2093->b + hr_ix(_i2093, _t2093->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:187"); }))).s_, }); S10 *_p2092 = (S10*)hr_grow(_v2092, 1, sizeof _x2092); *_p2092 = _x2092; _p2092; }));
int64_t f0_665 = f133_fields_into(v_663, ns_661); 
{ int32_t *_t2095 = &(((*({ hrv *_t2096 = &(g571); int64_t _i2096 = si_664; (S10*)_t2096->b + hr_ix(_i2096, _t2096->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:189"); }))).f0_); *_t2095 = ((int32_t)(f0_665)); }
{ int32_t *_t2097 = &(((*({ hrv *_t2098 = &(g571); int64_t _i2098 = si_664; (S10*)_t2098->b + hr_ix(_i2098, _t2098->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:189"); }))).fnum_); *_t2097 = ((int32_t)(((int64_t)((int64_t)(g572).n - (int64_t)f0_665)))); }
{ int32_t *_t2099 = &(((*({ hrv *_t2100 = &(g574); int64_t _i2100 = ((int64_t)((int64_t)v0_655 + (int64_t)i_662)); (S9*)_t2100->b + hr_ix(_i2100, _t2100->n, "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:190"); }))).si_); *_t2099 = ((int32_t)(si_664)); }
 } } _bk2089:; 
(void)(({ hrv *_v2101 = &(g508); int64_t _k2101 = ((int64_t)((int64_t)(g508).n - (int64_t)g0_659)); if (_k2101 < 0 || _k2101 > _v2101->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/decl.amni:192"); _v2101->n -= _k2101; }));
return ei_653;
}
static int64_t f136_t_enum(int64_t ei_666, bool vm_667) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)6LL))), .fl_ = ({ uint16_t _r2103; if (vm_667) { _r2103 = ((uint16_t)1LL);  } else { _r2103 = ((uint16_t)0LL);  } _r2103; }), .a_ = ((int32_t)(ei_666)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f137_ck(int64_t n_671, int64_t want_672) {
if (((n_671) < (((int64_t)0LL)))) { return g575;
 }
S4 x_673 = (*({ hrv *_t2104 = &(g721); int64_t _i2104 = n_671; (S4*)_t2104->b + hr_ix(_i2104, _t2104->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:694"); })); 
int64_t k_674 = ((int64_t)((x_673).k_)); 
if (((k_674) == (((int64_t)1LL)))) { if ((((want_672) >= (((int64_t)0LL))) && ((((((*({ hrv *_t2105 = &(g568); int64_t _i2105 = want_672; (S1*)_t2105->b + hr_ix(_i2105, _t2105->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:696"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2106 = &(g568); int64_t _i2106 = want_672; (S1*)_t2106->b + hr_ix(_i2106, _t2106->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:696"); }))).k_) == (((uint8_t)4LL)))) || ((((*({ hrv *_t2107 = &(g568); int64_t _i2107 = want_672; (S1*)_t2107->b + hr_ix(_i2107, _t2107->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:696"); }))).k_) == (((uint8_t)17LL)))))) { (void)(f138_set_t(n_671, g588));
(void)(f140_conv(n_671, want_672));
return want_672;
 }
return f138_set_t(n_671, g588);
 }
if (((k_674) == (((int64_t)2LL)))) { if ((((want_672) >= (((int64_t)0LL))) && ((((*({ hrv *_t2111 = &(g568); int64_t _i2111 = want_672; (S1*)_t2111->b + hr_ix(_i2111, _t2111->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:697"); }))).k_) == (((uint8_t)4LL))))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g589);
 }
if (((k_674) == (((int64_t)3LL)))) { if ((((want_672) >= (((int64_t)0LL))) && f167_is_byte_arr(want_672))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g590);
 }
if ((((k_674) == (((int64_t)4LL))) || ((k_674) == (((int64_t)5LL))))) { return f138_set_t(n_671, g576);
 }
if (((k_674) == (((int64_t)6LL)))) { if ((((want_672) >= (((int64_t)0LL))) && f168_is_opt(want_672))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g587);
 }
if (((k_674) == (((int64_t)7LL)))) { return f138_set_t(n_671, ({ int64_t _r2122; if (((want_672) >= (((int64_t)0LL)))) { _r2122 = want_672;  } else { _r2122 = g592;  } _r2122; }));
 }
if (((k_674) == (((int64_t)8LL)))) { return f169_ck_id(n_671, want_672);
 }
if (((k_674) == (((int64_t)9LL)))) { int64_t t_905 = f179_ck_bin(n_671, want_672); 
if (((((want_672) >= (((int64_t)0LL))) && f166_is_pending(t_905)) && (((((*({ hrv *_t2126 = &(g568); int64_t _i2126 = want_672; (S1*)_t2126->b + hr_ix(_i2126, _t2126->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:703"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2127 = &(g568); int64_t _i2127 = want_672; (S1*)_t2127->b + hr_ix(_i2127, _t2127->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:703"); }))).k_) == (((uint8_t)4LL)))))) { (void)(f140_conv(n_671, want_672));
return want_672;
 }
return t_905;
 }
if (((k_674) == (((int64_t)10LL)))) { int64_t t_932 = f186_ck_un(n_671, want_672); 
if (((((want_672) >= (((int64_t)0LL))) && f166_is_pending(t_932)) && (((((*({ hrv *_t2131 = &(g568); int64_t _i2131 = want_672; (S1*)_t2131->b + hr_ix(_i2131, _t2131->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:704"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2132 = &(g568); int64_t _i2132 = want_672; (S1*)_t2132->b + hr_ix(_i2132, _t2132->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:704"); }))).k_) == (((uint8_t)4LL)))))) { (void)(f140_conv(n_671, want_672));
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
if (((k_674) == (((int64_t)24LL)))) { (void)(({ hrv *_v2140 = &(g484); int32_t _x2140 = ({ int32_t _r2141; if ((((want_672) >= (((int64_t)0LL))) && ((want_672) != (g575)))) { _r2141 = ((int32_t)(want_672));  } else { _r2141 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));  } _r2141; }); int32_t *_p2140 = (int32_t*)hr_grow(_v2140, 1, sizeof _x2140); *_p2140 = _x2140; _p2140; }));
int64_t bt_1122 = f137_ck(((int64_t)((x_673).a_)), want_672); 
int64_t t_1123 = ((int64_t)(({ hrv *_v2143 = &(g484); if (!_v2143->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:711"); ((int32_t*)_v2143->b)[--_v2143->n]; }))); 
if ((((bt_1122) != (g575)) && (!(f166_is_pending(bt_1122))))) { return f138_set_t(n_671, bt_1122);
 }
if (((t_1123) >= (((int64_t)0LL)))) { (void)(f140_conv(((int64_t)((x_673).a_)), t_1123));
return f138_set_t(n_671, t_1123);
 }
return f138_set_t(n_671, bt_1122);
 }
if (((k_674) == (((int64_t)19LL)))) { return f215_ck_if(n_671, want_672);
 }
if (((k_674) == (((int64_t)25LL)))) { return f216_ck_while(n_671);
 }
if (((k_674) == (((int64_t)26LL)))) { return f217_ck_loop(n_671, want_672);
 }
if (((k_674) == (((int64_t)27LL)))) { return f218_ck_for(n_671);
 }
if (((k_674) == (((int64_t)20LL)))) { return f221_ck_match(n_671, want_672);
 }
if (((k_674) == (((int64_t)28LL)))) { return f222_ck_ret(n_671);
 }
if (((k_674) == (((int64_t)29LL)))) { return f225_ck_break(n_671);
 }
if (((k_674) == (((int64_t)30LL)))) { return f138_set_t(n_671, g575);
 }
if (((k_674) == (((int64_t)11LL)))) { return f226_ck_call(n_671, want_672);
 }
if (((k_674) == (((int64_t)17LL)))) { return f259_ck_slit(n_671, want_672);
 }
if (((k_674) == (((int64_t)31LL)))) { return f138_set_t(n_671, g595);
 }
(void)(f108_cerr(n_671, hr_str("unsupported expression", 22)));
return f138_set_t(n_671, g592);
}
static int64_t f138_set_t(int64_t n_675, int64_t t_676) {
{ int32_t *_t2162 = &((*({ hrv *_t2163 = &(g408); int64_t _i2163 = f139_aix(n_675); (int32_t*)_t2163->b + hr_ix(_i2163, _t2163->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:42"); }))); *_t2162 = ((int32_t)(t_676)); }
return t_676;
}
static int64_t f139_aix(int64_t n_677) {
int64_t i_678 = g414; 
while (((i_678) >= (((int64_t)0LL)))) { S6 f_679 = (*({ hrv *_t2166 = &(g401); int64_t _i2166 = i_678; (S6*)_t2166->b + hr_ix(_i2166, _t2166->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:37"); })); 
if ((((n_677) >= (((int64_t)((f_679).lo_)))) && ((n_677) < (((int64_t)((f_679).hi_)))))) { return ((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((f_679).ab_)) + (int64_t)n_677)) - (int64_t)((int64_t)((f_679).lo_))));
 }
i_678 = ((int64_t)((f_679).par_));
 } _bk2165:; 
S6 g_680 = (*({ hrv *_t2167 = &(g401); int64_t _i2167 = g416; (S6*)_t2167->b + hr_ix(_i2167, _t2167->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:38"); })); 
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
int64_t fk_685 = ((int64_t)(((*({ hrv *_t2169 = &(g568); int64_t _i2169 = f_684; (S1*)_t2169->b + hr_ix(_i2169, _t2169->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:155"); }))).k_)); 
int64_t tkd_686 = ((int64_t)(((*({ hrv *_t2170 = &(g568); int64_t _i2170 = t_682; (S1*)_t2170->b + hr_ix(_i2170, _t2170->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:156"); }))).k_)); 
if ((((tkd_686) == (((int64_t)0LL))) || ((fk_685) == (((int64_t)0LL))))) { return true;
 }
int64_t nk_687 = ((int64_t)(((*({ hrv *_t2171 = &(g721); int64_t _i2171 = n_681; (S4*)_t2171->b + hr_ix(_i2171, _t2171->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:158"); }))).k_)); 
if (((((((((nk_687) == (((int64_t)23LL))) || ((nk_687) == (((int64_t)24LL)))) || ((nk_687) == (((int64_t)19LL)))) || ((nk_687) == (((int64_t)20LL)))) && ((fk_685) == (((int64_t)7LL)))) && ((tkd_686) == (((int64_t)6LL)))) && ((((*({ hrv *_t2172 = &(g568); int64_t _i2172 = f_684; (S1*)_t2172->b + hr_ix(_i2172, _t2172->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:159"); }))).a_) == (((*({ hrv *_t2173 = &(g568); int64_t _i2173 = t_682; (S1*)_t2173->b + hr_ix(_i2173, _t2173->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:159"); }))).a_)))) { (void)(f142_conv_tail(n_681, t_682));
(void)(f138_set_t(n_681, t_682));
return true;
 }
if (((((tkd_686) == (((int64_t)2LL))) && ((fk_685) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2176 = &(g568); int64_t _i2176 = f_684; (S1*)_t2176->b + hr_ix(_i2176, _t2176->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:160"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f145_set_cv(n_681, g576));
return true;
 }
if ((((((tkd_686) == (((int64_t)10LL))) && ((((*({ hrv *_t2178 = &(g568); int64_t _i2178 = t_682; (S1*)_t2178->b + hr_ix(_i2178, _t2178->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:161"); }))).c_) < (((int32_t)0LL)))) && ((fk_685) != (((int64_t)11LL)))) && ((fk_685) != (((int64_t)10LL))))) { if (((f146_tclass(t_682)) >= (((int64_t)0LL)))) { bool ok_751 = f140_conv(n_681, ((int64_t)(((*({ hrv *_t2181 = &(g568); int64_t _i2181 = t_682; (S1*)_t2181->b + hr_ix(_i2181, _t2181->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:161"); }))).a_))); 
if ((ok_751 && ((f153_cv(n_681)) < (((int64_t)0LL))))) { (void)(f145_set_cv(n_681, t_682));
 }
return ok_751;
 }
 }
if (((((fk_685) == (((int64_t)10LL))) && ((((*({ hrv *_t2184 = &(g568); int64_t _i2184 = f_684; (S1*)_t2184->b + hr_ix(_i2184, _t2184->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:162"); }))).c_) < (((int32_t)0LL)))) && ((tkd_686) != (((int64_t)10LL))))) { if (f154_conv_ok(((int64_t)(((*({ hrv *_t2186 = &(g568); int64_t _i2186 = f_684; (S1*)_t2186->b + hr_ix(_i2186, _t2186->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:162"); }))).a_)), t_682, n_681)) { (void)(f145_set_cv(n_681, t_682));
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
if ((((fk_685) == (((int64_t)18LL))) && (f167_is_byte_arr(t_682) || (((tkd_686) == (((int64_t)10LL))) && f167_is_byte_arr(((int64_t)(((*({ hrv *_t2201 = &(g568); int64_t _i2201 = t_682; (S1*)_t2201->b + hr_ix(_i2201, _t2201->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:169"); }))).a_))))))) { (void)(f165_commit(n_681, ({ int64_t _r2203; if (((tkd_686) == (((int64_t)10LL)))) { _r2203 = ((int64_t)(((*({ hrv *_t2204 = &(g568); int64_t _i2204 = t_682; (S1*)_t2204->b + hr_ix(_i2204, _t2204->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:169"); }))).a_));  } else { _r2203 = t_682;  } _r2203; })));
return true;
 }
if ((((fk_685) == (((int64_t)19LL))) && (((tkd_686) == (((int64_t)8LL))) || ((tkd_686) == (((int64_t)9LL)))))) { (void)(f165_commit(n_681, t_682));
return true;
 }
if (((((fk_685) == (((int64_t)11LL))) && ((tkd_686) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2206 = &(g568); int64_t _i2206 = t_682; (S1*)_t2206->b + hr_ix(_i2206, _t2206->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:171"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f165_commit(n_681, t_682));
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
return ((int64_t)((*({ hrv *_t2217 = &(g408); int64_t _i2217 = f139_aix(n_683); (int32_t*)_t2217->b + hr_ix(_i2217, _t2217->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:41"); }))));
}
static void f142_conv_tail(int64_t n_688, int64_t t_689) {
S4 x_690 = (*({ hrv *_t2219 = &(g721); int64_t _i2219 = n_688; (S4*)_t2219->b + hr_ix(_i2219, _t2219->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:145"); })); 
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
if (((k_691) == (((int64_t)20LL)))) { { int32_t _e2227 = (x_690).n_; for (int32_t _k2227 = 0; _k2227 < _e2227; _k2227++) { int32_t i_701 = (int32_t)_k2227; int64_t b_702 = ((int64_t)(((*({ hrv *_t2228 = &(g721); int64_t _i2228 = f90_kid(n_688, ((int64_t)(i_701))); (S4*)_t2228->b + hr_ix(_i2228, _t2228->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:148"); }))).b_)); 
if ((((b_702) >= (((int64_t)0LL))) && (!(f143_ends(b_702))))) { (void)(f140_conv(b_702, t_689));
 }
 } } _bk2226:; 
 }
}
static bool f143_ends(int64_t n_692) {
if (((n_692) < (((int64_t)0LL)))) { return false;
 }
int64_t k_693 = ((int64_t)(((*({ hrv *_t2232 = &(g721); int64_t _i2232 = n_692; (S4*)_t2232->b + hr_ix(_i2232, _t2232->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:514"); }))).k_)); 
if (((((k_693) == (((int64_t)28LL))) || ((k_693) == (((int64_t)29LL)))) || ((k_693) == (((int64_t)30LL))))) { return true;
 }
if ((((k_693) == (((int64_t)11LL))) && ((((*({ hrv *_t2233 = &(g721); int64_t _i2233 = ((*({ hrv *_t2234 = &(g721); int64_t _i2234 = n_692; (S4*)_t2234->b + hr_ix(_i2234, _t2234->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:516"); }))).a_; (S4*)_t2233->b + hr_ix(_i2233, _t2233->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:516"); }))).k_) == (((uint8_t)8LL))))) { hsl s_694 = f10_nm(((int64_t)(((*({ hrv *_t2236 = &(g721); int64_t _i2236 = ((*({ hrv *_t2237 = &(g721); int64_t _i2237 = n_692; (S4*)_t2237->b + hr_ix(_i2237, _t2237->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:516"); }))).a_; (S4*)_t2236->b + hr_ix(_i2236, _t2236->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:516"); }))).s_))); 
if ((hr_streq(s_694, hr_str("abort", 5)) || hr_streq(s_694, hr_str("exit", 4)))) { return true;
 }
 }
if (((k_693) == (((int64_t)23LL)))) { if (((((*({ hrv *_t2238 = &(g721); int64_t _i2238 = n_692; (S4*)_t2238->b + hr_ix(_i2238, _t2238->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:517"); }))).a_) >= (((int32_t)0LL)))) { return f143_ends(((int64_t)(((*({ hrv *_t2240 = &(g721); int64_t _i2240 = n_692; (S4*)_t2240->b + hr_ix(_i2240, _t2240->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:517"); }))).a_)));
 }
if (((((*({ hrv *_t2241 = &(g721); int64_t _i2241 = n_692; (S4*)_t2241->b + hr_ix(_i2241, _t2241->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:517"); }))).n_) > (((int32_t)0LL)))) { return f143_ends(f90_kid(n_692, ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2244 = &(g721); int64_t _i2244 = n_692; (S4*)_t2244->b + hr_ix(_i2244, _t2244->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:517"); }))).n_)) - (int64_t)((int64_t)1LL)))));
 }
return false;
 }
if (((k_693) == (((int64_t)19LL)))) { return ((((((*({ hrv *_t2245 = &(g721); int64_t _i2245 = n_692; (S4*)_t2245->b + hr_ix(_i2245, _t2245->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:518"); }))).c_) >= (((int32_t)0LL))) && f143_ends(((int64_t)(((*({ hrv *_t2247 = &(g721); int64_t _i2247 = n_692; (S4*)_t2247->b + hr_ix(_i2247, _t2247->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:518"); }))).b_)))) && f143_ends(((int64_t)(((*({ hrv *_t2249 = &(g721); int64_t _i2249 = n_692; (S4*)_t2249->b + hr_ix(_i2249, _t2249->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:518"); }))).c_))));
 }
if (((k_693) == (((int64_t)26LL)))) { return (!(f144_has_break(((int64_t)(((*({ hrv *_t2251 = &(g721); int64_t _i2251 = n_692; (S4*)_t2251->b + hr_ix(_i2251, _t2251->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:519"); }))).a_)))));
 }
return false;
}
static bool f144_has_break(int64_t n_695) {
if (((n_695) < (((int64_t)0LL)))) { return false;
 }
S4 x_696 = (*({ hrv *_t2252 = &(g721); int64_t _i2252 = n_695; (S4*)_t2252->b + hr_ix(_i2252, _t2252->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:524"); })); 
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
if ((((k_697) == (((int64_t)20LL))) && f144_has_break(((int64_t)(((*({ hrv *_t2268 = &(g721); int64_t _i2268 = c_700; (S4*)_t2268->b + hr_ix(_i2268, _t2268->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:535"); }))).b_))))) { return true;
 }
 } } _bk2263:; 
 }
return false;
}
static void f145_set_cv(int64_t n_703, int64_t t_704) {
{ int32_t *_t2269 = &((*({ hrv *_t2270 = &(g409); int64_t _i2270 = f139_aix(n_703); (int32_t*)_t2270->b + hr_ix(_i2270, _t2270->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:48"); }))); *_t2269 = ((int32_t)(t_704)); }
}
static int64_t f146_tclass(int64_t t_705) {
S1 x_706 = (*({ hrv *_t2272 = &(g568); int64_t _i2272 = t_705; (S1*)_t2272->b + hr_ix(_i2272, _t2272->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:83"); })); 
int64_t k_707 = ((int64_t)((x_706).k_)); 
if (((k_707) == (((int64_t)5LL)))) { (void)(f147_si_layout(((int64_t)((x_706).a_))));
return ((int64_t)(((*({ hrv *_t2274 = &(g571); int64_t _i2274 = (x_706).a_; (S10*)_t2274->b + hr_ix(_i2274, _t2274->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:85"); }))).cls_));
 }
if (((k_707) == (((int64_t)7LL)))) { (void)(f149_ei_layout(((int64_t)((x_706).a_))));
S9 v_748 = (*({ hrv *_t2276 = &(g574); int64_t _i2276 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2277 = &(g573); int64_t _i2277 = (x_706).a_; (S8*)_t2277->b + hr_ix(_i2277, _t2277->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:86"); }))).v0_)) + (int64_t)((int64_t)((x_706).c_)))); (S9*)_t2276->b + hr_ix(_i2276, _t2276->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:86"); })); 
if ((((v_748).si_) >= (((int32_t)0LL)))) { (void)(f147_si_layout(((int64_t)((v_748).si_))));
return ((int64_t)(((*({ hrv *_t2279 = &(g571); int64_t _i2279 = (v_748).si_; (S10*)_t2279->b + hr_ix(_i2279, _t2279->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:86"); }))).cls_));
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
if (((((*({ hrv *_t2283 = &(g571); int64_t _i2283 = si_708; (S10*)_t2283->b + hr_ix(_i2283, _t2283->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:127"); }))).done_) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t2284 = &(((*({ hrv *_t2285 = &(g571); int64_t _i2285 = si_708; (S10*)_t2285->b + hr_ix(_i2285, _t2285->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:128"); }))).done_); *_t2284 = ((uint8_t)1LL); }
int64_t off_709 = ((int64_t)0LL); 
int64_t cls_710 = ((int64_t)0LL); 
bool flat_711 = true; 
int64_t f0_712 = ((int64_t)(((*({ hrv *_t2286 = &(g571); int64_t _i2286 = si_708; (S10*)_t2286->b + hr_ix(_i2286, _t2286->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:130"); }))).f0_)); 
int64_t fnum_713 = ((int64_t)(((*({ hrv *_t2287 = &(g571); int64_t _i2287 = si_708; (S10*)_t2287->b + hr_ix(_i2287, _t2287->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:130"); }))).fnum_)); 
{ int64_t _e2289 = fnum_713; for (int64_t _k2289 = 0; _k2289 < _e2289; _k2289++) { int64_t i_714 = (int64_t)_k2289; int64_t fi_715 = ((int64_t)((int64_t)f0_712 + (int64_t)i_714)); 
int64_t ft_716 = ((int64_t)(((*({ hrv *_t2290 = &(g572); int64_t _i2290 = fi_715; (S11*)_t2290->b + hr_ix(_i2290, _t2290->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:133"); }))).ty_)); 
if (((ft_716) >= (((int64_t)0LL)))) { int64_t c_717 = f146_tclass(ft_716); 
if (((c_717) > (cls_710))) { cls_710 = c_717;
 }
if ((!(f148_tflat(ft_716)))) { flat_711 = false;
 }
 }
 } } _bk2288:; 
bool cur_var_731 = false; 
{ int64_t _e2294 = fnum_713; for (int64_t _k2294 = 0; _k2294 < _e2294; _k2294++) { int64_t i_732 = (int64_t)_k2294; int64_t fi_733 = ((int64_t)((int64_t)f0_712 + (int64_t)i_732)); 
int64_t ft_734 = ((int64_t)(((*({ hrv *_t2295 = &(g572); int64_t _i2295 = fi_733; (S11*)_t2295->b + hr_ix(_i2295, _t2295->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:143"); }))).ty_)); 
if (((ft_734) < (((int64_t)0LL)))) { if (((((*({ hrv *_t2296 = &(g572); int64_t _i2296 = fi_733; (S11*)_t2296->b + hr_ix(_i2296, _t2296->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:145"); }))).padn_) < (((int32_t)0LL)))) { if (((cls_710) == (((int64_t)0LL)))) { int64_t a_735 = ((int64_t)1LL); 
{ int64_t _e2298 = fnum_713; for (int64_t _k2298 = ((int64_t)((int64_t)i_732 + (int64_t)((int64_t)1LL))); _k2298 < _e2298; _k2298++) { int64_t j_736 = (int64_t)_k2298; if (((((*({ hrv *_t2299 = &(g572); int64_t _i2299 = ((int64_t)((int64_t)f0_712 + (int64_t)j_736)); (S11*)_t2299->b + hr_ix(_i2299, _t2299->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:148"); }))).ty_) >= (((int32_t)0LL)))) { a_735 = f150_pad_align(((int64_t)(((*({ hrv *_t2301 = &(g572); int64_t _i2301 = ((int64_t)((int64_t)f0_712 + (int64_t)j_736)); (S11*)_t2301->b + hr_ix(_i2301, _t2301->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:148"); }))).ty_)));
{ goto _bk2297; }
 }
 } } _bk2297:; 
int64_t next_off_741 = ((int64_t)((int64_t)HR_SDIV(int64_t, ((int64_t)((int64_t)((int64_t)((int64_t)off_709 + (int64_t)a_735)) - (int64_t)((int64_t)1LL))), a_735, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:149") * (int64_t)a_735)); 
{ int32_t *_t2302 = &(((*({ hrv *_t2303 = &(g572); int64_t _i2303 = fi_733; (S11*)_t2303->b + hr_ix(_i2303, _t2303->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:150"); }))).padn_); *_t2302 = ((int32_t)(((int64_t)((int64_t)next_off_741 - (int64_t)off_709)))); }
{ int64_t *_t2304 = &(((*({ hrv *_t2305 = &(g572); int64_t _i2305 = fi_733; (S11*)_t2305->b + hr_ix(_i2305, _t2305->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:151"); }))).off_); *_t2304 = off_709; }
off_709 = next_off_741;
 } else { { int32_t *_t2306 = &(((*({ hrv *_t2307 = &(g572); int64_t _i2307 = fi_733; (S11*)_t2307->b + hr_ix(_i2307, _t2307->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:154"); }))).padn_); *_t2306 = ((int32_t)0LL); }
{ int64_t *_t2308 = &(((*({ hrv *_t2309 = &(g572); int64_t _i2309 = fi_733; (S11*)_t2309->b + hr_ix(_i2309, _t2309->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:155"); }))).off_); *_t2308 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); }
 }
 } else { { int64_t *_t2310 = &(((*({ hrv *_t2311 = &(g572); int64_t _i2311 = fi_733; (S11*)_t2311->b + hr_ix(_i2311, _t2311->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:158"); }))).off_); *_t2310 = ({ int64_t _r2312; if ((!(cur_var_731))) { _r2312 = off_709;  } else { _r2312 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2312; }); }
if ((!(cur_var_731))) { { int64_t *_t2313 = &(off_709); *_t2313 = ((int64_t)((int64_t)(*_t2313) + (int64_t)((int64_t)(((*({ hrv *_t2314 = &(g572); int64_t _i2314 = fi_733; (S11*)_t2314->b + hr_ix(_i2314, _t2314->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:159"); }))).padn_)))); }
 }
 }
continue;
 }
int64_t c_742 = f146_tclass(ft_734); 
if (((c_742) != (((int64_t)0LL)))) { cur_var_731 = true;
 }
{ int64_t *_t2316 = &(((*({ hrv *_t2317 = &(g572); int64_t _i2317 = fi_733; (S11*)_t2317->b + hr_ix(_i2317, _t2317->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:165"); }))).off_); *_t2316 = ({ int64_t _r2318; if ((!(cur_var_731))) { _r2318 = off_709;  } else { _r2318 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2318; }); }
if ((!(cur_var_731))) { { int64_t *_t2319 = &(off_709); *_t2319 = ((int64_t)((int64_t)(*_t2319) + (int64_t)f152_tsize(ft_734))); }
 }
 } } _bk2293:; 
{ uint8_t *_t2321 = &(((*({ hrv *_t2322 = &(g571); int64_t _i2322 = si_708; (S10*)_t2322->b + hr_ix(_i2322, _t2322->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:168"); }))).cls_); *_t2321 = ((uint8_t)(cls_710)); }
{ bool *_t2323 = &(((*({ hrv *_t2324 = &(g571); int64_t _i2324 = si_708; (S10*)_t2324->b + hr_ix(_i2324, _t2324->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:168"); }))).flat_); *_t2323 = flat_711; }
{ int64_t *_t2325 = &(((*({ hrv *_t2326 = &(g571); int64_t _i2326 = si_708; (S10*)_t2326->b + hr_ix(_i2326, _t2326->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:169"); }))).size_); *_t2325 = ({ int64_t _r2327; if (((cls_710) == (((int64_t)0LL)))) { _r2327 = f103_max(off_709, ((int64_t)1LL));  } else { _r2327 = off_709;  } _r2327; }); }
{ bool *_t2329 = &(((*({ hrv *_t2330 = &(g571); int64_t _i2330 = si_708; (S10*)_t2330->b + hr_ix(_i2330, _t2330->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:170"); }))).zero_); *_t2329 = (((cls_710) == (((int64_t)0LL))) && ((off_709) == (((int64_t)0LL)))); }
{ uint8_t *_t2331 = &(((*({ hrv *_t2332 = &(g571); int64_t _i2332 = si_708; (S10*)_t2332->b + hr_ix(_i2332, _t2332->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:171"); }))).done_); *_t2331 = ((uint8_t)2LL); }
}
static bool f148_tflat(int64_t t_718) {
S1 x_719 = (*({ hrv *_t2333 = &(g568); int64_t _i2333 = t_718; (S1*)_t2333->b + hr_ix(_i2333, _t2333->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:118"); })); 
int64_t k_720 = ((int64_t)((x_719).k_)); 
if ((((k_720) == (((int64_t)10LL))) || ((k_720) == (((int64_t)9LL))))) { return false;
 }
if (((k_720) == (((int64_t)5LL)))) { (void)(f147_si_layout(((int64_t)((x_719).a_))));
return ((*({ hrv *_t2335 = &(g571); int64_t _i2335 = (x_719).a_; (S10*)_t2335->b + hr_ix(_i2335, _t2335->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:120"); }))).flat_;
 }
if ((((k_720) == (((int64_t)6LL))) || ((k_720) == (((int64_t)7LL))))) { (void)(f149_ei_layout(((int64_t)((x_719).a_))));
return ((*({ hrv *_t2337 = &(g573); int64_t _i2337 = (x_719).a_; (S8*)_t2337->b + hr_ix(_i2337, _t2337->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:121"); }))).flat_;
 }
if (((k_720) == (((int64_t)8LL)))) { return f148_tflat(((int64_t)((x_719).a_)));
 }
return true;
}
static void f149_ei_layout(int64_t ei_721) {
if (((((*({ hrv *_t2339 = &(g573); int64_t _i2339 = ei_721; (S8*)_t2339->b + hr_ix(_i2339, _t2339->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:174"); }))).done_) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t2340 = &(((*({ hrv *_t2341 = &(g573); int64_t _i2341 = ei_721; (S8*)_t2341->b + hr_ix(_i2341, _t2341->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:175"); }))).done_); *_t2340 = ((uint8_t)1LL); }
int64_t nv_722 = ((int64_t)(((*({ hrv *_t2342 = &(g573); int64_t _i2342 = ei_721; (S8*)_t2342->b + hr_ix(_i2342, _t2342->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:176"); }))).vnum_)); 
int64_t tz_723 = ({ int64_t _r2343; if (((nv_722) <= (((int64_t)256LL)))) { _r2343 = ((int64_t)1LL);  } else { _r2343 = ((int64_t)2LL);  } _r2343; }); 
{ uint8_t *_t2344 = &(((*({ hrv *_t2345 = &(g573); int64_t _i2345 = ei_721; (S8*)_t2345->b + hr_ix(_i2345, _t2345->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:178"); }))).tagsz_); *_t2344 = ((uint8_t)(tz_723)); }
int64_t mx_724 = ((int64_t)0LL); 
int64_t cls_725 = ((int64_t)0LL); 
bool flat_726 = true; 
{ int64_t _e2347 = nv_722; for (int64_t _k2347 = 0; _k2347 < _e2347; _k2347++) { int64_t i_727 = (int64_t)_k2347; int64_t v_728 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2348 = &(g573); int64_t _i2348 = ei_721; (S8*)_t2348->b + hr_ix(_i2348, _t2348->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:181"); }))).v0_)) + (int64_t)i_727)); 
if (((((*({ hrv *_t2349 = &(g574); int64_t _i2349 = v_728; (S9*)_t2349->b + hr_ix(_i2349, _t2349->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:182"); }))).si_) >= (((int32_t)0LL)))) { int64_t si_729 = ((int64_t)(((*({ hrv *_t2350 = &(g574); int64_t _i2350 = v_728; (S9*)_t2350->b + hr_ix(_i2350, _t2350->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:183"); }))).si_)); 
(void)(f147_si_layout(si_729));
if (((((int64_t)(((*({ hrv *_t2352 = &(g571); int64_t _i2352 = si_729; (S10*)_t2352->b + hr_ix(_i2352, _t2352->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:185"); }))).cls_))) > (cls_725))) { cls_725 = ((int64_t)(((*({ hrv *_t2353 = &(g571); int64_t _i2353 = si_729; (S10*)_t2353->b + hr_ix(_i2353, _t2353->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:185"); }))).cls_));
 }
if ((!(((*({ hrv *_t2354 = &(g571); int64_t _i2354 = si_729; (S10*)_t2354->b + hr_ix(_i2354, _t2354->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:186"); }))).flat_))) { flat_726 = false;
 }
int64_t ps_730 = ({ int64_t _r2355; if (((*({ hrv *_t2356 = &(g571); int64_t _i2356 = si_729; (S10*)_t2356->b + hr_ix(_i2356, _t2356->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:187"); }))).zero_) { _r2355 = ((int64_t)0LL);  } else { _r2355 = ((*({ hrv *_t2357 = &(g571); int64_t _i2357 = si_729; (S10*)_t2357->b + hr_ix(_i2357, _t2357->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:187"); }))).size_;  } _r2355; }); 
{ int64_t *_t2358 = &(((*({ hrv *_t2359 = &(g574); int64_t _i2359 = v_728; (S9*)_t2359->b + hr_ix(_i2359, _t2359->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:188"); }))).size_); *_t2358 = ps_730; }
if (((ps_730) > (mx_724))) { mx_724 = ps_730;
 }
 }
 } } _bk2346:; 
{ uint8_t *_t2360 = &(((*({ hrv *_t2361 = &(g573); int64_t _i2361 = ei_721; (S8*)_t2361->b + hr_ix(_i2361, _t2361->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:192"); }))).cls_); *_t2360 = ((uint8_t)(cls_725)); }
{ bool *_t2362 = &(((*({ hrv *_t2363 = &(g573); int64_t _i2363 = ei_721; (S8*)_t2363->b + hr_ix(_i2363, _t2363->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:192"); }))).flat_); *_t2362 = flat_726; }
{ int64_t *_t2364 = &(((*({ hrv *_t2365 = &(g573); int64_t _i2365 = ei_721; (S8*)_t2365->b + hr_ix(_i2365, _t2365->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:193"); }))).size_); *_t2364 = ((int64_t)((int64_t)((int64_t)(tz_723)) + (int64_t)mx_724)); }
{ uint8_t *_t2366 = &(((*({ hrv *_t2367 = &(g573); int64_t _i2367 = ei_721; (S8*)_t2367->b + hr_ix(_i2367, _t2367->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:194"); }))).done_); *_t2366 = ((uint8_t)2LL); }
}
static int64_t f150_pad_align(int64_t t_737) {
S1 x_738 = (*({ hrv *_t2368 = &(g568); int64_t _i2368 = t_737; (S1*)_t2368->b + hr_ix(_i2368, _t2368->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:96"); })); 
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
S1 x_744 = (*({ hrv *_t2372 = &(g568); int64_t _i2372 = t_743; (S1*)_t2372->b + hr_ix(_i2372, _t2372->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:104"); })); 
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
return ((*({ hrv *_t2376 = &(g571); int64_t _i2376 = (x_744).a_; (S10*)_t2376->b + hr_ix(_i2376, _t2376->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:111"); }))).size_;
 }
if (((k_745) == (((int64_t)7LL)))) { (void)(f149_ei_layout(((int64_t)((x_744).a_))));
S9 v_746 = (*({ hrv *_t2378 = &(g574); int64_t _i2378 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2379 = &(g573); int64_t _i2379 = (x_744).a_; (S8*)_t2379->b + hr_ix(_i2379, _t2379->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:112"); }))).v0_)) + (int64_t)((int64_t)((x_744).c_)))); (S9*)_t2378->b + hr_ix(_i2378, _t2378->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:112"); })); 
return (v_746).size_;
 }
if (((k_745) == (((int64_t)6LL)))) { (void)(f149_ei_layout(((int64_t)((x_744).a_))));
return ((*({ hrv *_t2381 = &(g573); int64_t _i2381 = (x_744).a_; (S8*)_t2381->b + hr_ix(_i2381, _t2381->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:113"); }))).size_;
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
return ((int64_t)((*({ hrv *_t2387 = &(g409); int64_t _i2387 = f139_aix(n_752); (int32_t*)_t2387->b + hr_ix(_i2387, _t2387->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:49"); }))));
}
static bool f154_conv_ok(int64_t f_753, int64_t t_754, int64_t n_755) {
if (((f_753) == (t_754))) { return true;
 }
S1 a_756 = (*({ hrv *_t2389 = &(g568); int64_t _i2389 = f_753; (S1*)_t2389->b + hr_ix(_i2389, _t2389->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:178"); })); 
S1 b_757 = (*({ hrv *_t2390 = &(g568); int64_t _i2390 = t_754; (S1*)_t2390->b + hr_ix(_i2390, _t2390->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:178"); })); 
if (f155_widens(f_753, t_754)) { return true;
 }
if ((((((b_757).k_) == (((uint8_t)2LL))) && (((a_756).k_) == (((uint8_t)10LL)))) && ((((uint16_t)((uint64_t)(a_756).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { return true;
 }
if ((((((b_757).k_) == (((uint8_t)9LL))) && ((((a_756).k_) == (((uint8_t)8LL))) || (((a_756).k_) == (((uint8_t)9LL))))) && (((a_756).a_) == ((b_757).a_)))) { return true;
 }
if ((((((b_757).k_) == (((uint8_t)9LL))) && (((a_756).k_) == (((uint8_t)18LL)))) && ((((int64_t)((b_757).a_))) == (g581)))) { return true;
 }
if ((((((b_757).k_) == (((uint8_t)10LL))) && (((a_756).k_) == (((uint8_t)10LL)))) && (((((uint16_t)((uint64_t)(b_757).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))) || ((((uint16_t)((uint64_t)(a_756).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))))) { if ((((a_756).a_) == ((b_757).a_))) { return true;
 }
if (((((((*({ hrv *_t2392 = &(g568); int64_t _i2392 = (b_757).a_; (S1*)_t2392->b + hr_ix(_i2392, _t2392->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:185"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t2393 = &(g568); int64_t _i2393 = (a_756).a_; (S1*)_t2393->b + hr_ix(_i2393, _t2393->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:185"); }))).k_) == (((uint8_t)7LL)))) && ((((*({ hrv *_t2394 = &(g568); int64_t _i2394 = (a_756).a_; (S1*)_t2394->b + hr_ix(_i2394, _t2394->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:185"); }))).a_) == (((*({ hrv *_t2395 = &(g568); int64_t _i2395 = (b_757).a_; (S1*)_t2395->b + hr_ix(_i2395, _t2395->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:185"); }))).a_)))) { return true;
 }
if (((((((*({ hrv *_t2396 = &(g568); int64_t _i2396 = (b_757).a_; (S1*)_t2396->b + hr_ix(_i2396, _t2396->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:186"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t2397 = &(g568); int64_t _i2397 = (a_756).a_; (S1*)_t2397->b + hr_ix(_i2397, _t2397->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:186"); }))).k_) == (((uint8_t)6LL)))) && ((((*({ hrv *_t2398 = &(g568); int64_t _i2398 = (a_756).a_; (S1*)_t2398->b + hr_ix(_i2398, _t2398->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:186"); }))).a_) == (((*({ hrv *_t2399 = &(g568); int64_t _i2399 = (b_757).a_; (S1*)_t2399->b + hr_ix(_i2399, _t2399->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:186"); }))).a_)))) { return true;
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
S1 a_760 = (*({ hrv *_t2400 = &(g568); int64_t _i2400 = f_758; (S1*)_t2400->b + hr_ix(_i2400, _t2400->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:115"); })); 
S1 b_761 = (*({ hrv *_t2401 = &(g568); int64_t _i2401 = t_759; (S1*)_t2401->b + hr_ix(_i2401, _t2401->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:115"); })); 
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
if (((((a_760).k_) == (((uint8_t)17LL))) && (((b_761).k_) == (((uint8_t)3LL))))) { return ((t_759) == (g580));
 }
return false;
}
static bool f156_is_signed(int64_t t_762) {
return ((((*({ hrv *_t2410 = &(g568); int64_t _i2410 = t_762; (S1*)_t2410->b + hr_ix(_i2410, _t2410->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:60"); }))).s_) < (((uint8_t)4LL)));
}
static int64_t f157_ibits(int64_t t_765) {
return ((int64_t)((((int64_t)8LL)) << ((((int64_t)(((uint8_t)((uint64_t)((*({ hrv *_t2411 = &(g568); int64_t _i2411 = t_765; (S1*)_t2411->b + hr_ix(_i2411, _t2411->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:61"); }))).s_ & (uint64_t)((uint8_t)3LL)))))) & 63)));
}
static M78 f158_cval(int64_t n_766) {
if (((n_766) < (((int64_t)0LL)))) { return (M78){ ((int64_t)0LL), false, false };
 }
S4 x_767 = (*({ hrv *_t2412 = &(g721); int64_t _i2412 = n_766; (S4*)_t2412->b + hr_ix(_i2412, _t2412->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:125"); })); 
int64_t k_768 = ((int64_t)((x_767).k_)); 
if (((k_768) == (((int64_t)1LL)))) { return (M78){ ((*({ hrv *_t2413 = &(g931); int64_t _i2413 = (x_767).t_; (S3*)_t2413->b + hr_ix(_i2413, _t2413->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:126"); }))).v_, ((*({ hrv *_t2414 = &(g931); int64_t _i2414 = (x_767).t_; (S3*)_t2414->b + hr_ix(_i2414, _t2414->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:126"); }))).uns_, true };
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
if ((((k_768) == (((int64_t)8LL))) && ((f159_rk(n_766)) == (((int64_t)6LL))))) { return (M78){ (*({ hrv *_t2418 = &(g449); int64_t _i2418 = f160_rv(n_766); (int64_t*)_t2418->b + hr_ix(_i2418, _t2418->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:128"); })), false, true };
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
return ((int64_t)((*({ hrv *_t2424 = &(g410); int64_t _i2424 = f139_aix(n_772); (uint8_t*)_t2424->b + hr_ix(_i2424, _t2424->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:44"); }))));
}
static int64_t f160_rv(int64_t n_773) {
return ((int64_t)((*({ hrv *_t2426 = &(g411); int64_t _i2426 = f139_aix(n_773); (int32_t*)_t2426->b + hr_ix(_i2426, _t2426->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:45"); }))));
}
static bool f161_int_fits(int64_t v_784, bool uns_785, int64_t t_786) {
if (((((*({ hrv *_t2428 = &(g568); int64_t _i2428 = t_786; (S1*)_t2428->b + hr_ix(_i2428, _t2428->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:108"); }))).k_) != (((uint8_t)3LL)))) { return false;
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
S4 x_796 = (*({ hrv *_t2443 = &(g721); int64_t _i2443 = n_794; (S4*)_t2443->b + hr_ix(_i2443, _t2443->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:198"); })); 
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
if (((k_797) == (((int64_t)20LL)))) { { int32_t _e2459 = (x_796).n_; for (int32_t _k2459 = 0; _k2459 < _e2459; _k2459++) { int32_t i_802 = (int32_t)_k2459; (void)(f165_commit(((int64_t)(((*({ hrv *_t2461 = &(g721); int64_t _i2461 = f90_kid(n_794, ((int64_t)(i_802))); (S4*)_t2461->b + hr_ix(_i2461, _t2461->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:212"); }))).b_)), t_795));
 } } _bk2458:; 
return;
 }
if (((k_797) == (((int64_t)16LL)))) { int64_t e_803 = ({ int64_t _r2463; if ((((((*({ hrv *_t2464 = &(g568); int64_t _i2464 = t_795; (S1*)_t2464->b + hr_ix(_i2464, _t2464->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:214"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2465 = &(g568); int64_t _i2465 = t_795; (S1*)_t2465->b + hr_ix(_i2465, _t2465->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:214"); }))).k_) == (((uint8_t)9LL))))) { _r2463 = ((int64_t)(((*({ hrv *_t2466 = &(g568); int64_t _i2466 = t_795; (S1*)_t2466->b + hr_ix(_i2466, _t2466->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:214"); }))).a_));  } else { _r2463 = g592;  } _r2463; }); 
if ((((x_796).a_) >= (((int32_t)0LL)))) { (void)(f140_conv(((int64_t)((x_796).a_)), e_803));
(void)(f140_conv(((int64_t)((x_796).b_)), g580));
 }
{ int32_t _e2470 = (x_796).n_; for (int32_t _k2470 = 0; _k2470 < _e2470; _k2470++) { int32_t i_804 = (int32_t)_k2470; (void)(f140_conv(f90_kid(n_794, ((int64_t)(i_804))), e_803));
 } } _bk2469:; 
if (((((*({ hrv *_t2473 = &(g568); int64_t _i2473 = t_795; (S1*)_t2473->b + hr_ix(_i2473, _t2473->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:217"); }))).k_) == (((uint8_t)9LL)))) { (void)(f138_set_t(n_794, f123_t_arr(e_803, ((int64_t)1LL), ((int64_t)((x_796).n_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f145_set_cv(n_794, t_795));
 }
return;
 }
}
static bool f166_is_pending(int64_t t_799) {
int64_t k_800 = ((int64_t)(((*({ hrv *_t2477 = &(g568); int64_t _i2477 = t_799; (S1*)_t2477->b + hr_ix(_i2477, _t2477->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:106"); }))).k_)); 
return ((((((k_800) == (((int64_t)12LL))) || ((k_800) == (((int64_t)13LL)))) || ((k_800) == (((int64_t)18LL)))) || ((k_800) == (((int64_t)19LL)))) || ((k_800) == (((int64_t)11LL))));
}
static bool f167_is_byte_arr(int64_t t_805) {
uint8_t k_806 = ((*({ hrv *_t2478 = &(g568); int64_t _i2478 = t_805; (S1*)_t2478->b + hr_ix(_i2478, _t2478->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:68"); }))).k_; 
return ((((k_806) == (((uint8_t)8LL))) || ((k_806) == (((uint8_t)9LL)))) && ((((int64_t)(((*({ hrv *_t2479 = &(g568); int64_t _i2479 = t_805; (S1*)_t2479->b + hr_ix(_i2479, _t2479->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:68"); }))).a_))) == (g581)));
}
static bool f168_is_opt(int64_t t_808) {
return (((((*({ hrv *_t2480 = &(g568); int64_t _i2480 = t_808; (S1*)_t2480->b + hr_ix(_i2480, _t2480->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:66"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2481 = &(g568); int64_t _i2481 = t_808; (S1*)_t2481->b + hr_ix(_i2481, _t2481->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:66"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))));
}
static int64_t f169_ck_id(int64_t n_809, int64_t want_810) {
int64_t name_811 = ((int64_t)(((*({ hrv *_t2482 = &(g721); int64_t _i2482 = n_809; (S4*)_t2482->b + hr_ix(_i2482, _t2482->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:348"); }))).s_)); 
int64_t v_819 = f170_find_lv(name_811); 
if (((v_819) >= (((int64_t)0LL)))) { (void)(f173_set_r(n_809, ((int64_t)1LL), v_819));
(void)(f174_note_cap(v_819));
return f138_set_t(n_809, ({ int64_t _r2487; if (((((uint16_t)((uint64_t)((*({ hrv *_t2488 = &(g402); int64_t _i2488 = v_819; (S12*)_t2488->b + hr_ix(_i2488, _t2488->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:350"); }))).fl_ & (uint64_t)((uint16_t)64LL)))) != (((uint16_t)0LL)))) { _r2487 = g589;  } else { _r2487 = ((int64_t)(((*({ hrv *_t2489 = &(g402); int64_t _i2489 = v_819; (S12*)_t2489->b + hr_ix(_i2489, _t2489->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:350"); }))).ty_));  } _r2487; }));
 }
int64_t ns_830 = f110_ns_of(n_809); 
int64_t d_831 = f116_lookup_q(name_811, ns_830, ((int64_t)5LL)); 
if (((d_831) >= (((int64_t)0LL)))) { int64_t g_832 = ((int64_t)(((*({ hrv *_t2492 = &(g506); int64_t _i2492 = d_831; (S5*)_t2492->b + hr_ix(_i2492, _t2492->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:354"); }))).node_)); 
int64_t ci_845 = f176_const_of(d_831); 
if (((ci_845) >= (((int64_t)0LL)))) { (void)(f173_set_r(n_809, ((int64_t)6LL), ci_845));
return f138_set_t(n_809, g588);
 }
(void)(f173_set_r(n_809, ((int64_t)2LL), d_831));
return f138_set_t(n_809, f109_global_type(d_831));
 }
d_831 = f116_lookup_q(name_811, ns_830, ((int64_t)4LL));
if (((d_831) >= (((int64_t)0LL)))) { (void)(f173_set_r(n_809, ((int64_t)3LL), d_831));
(void)(f178_set_x(n_809, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_809, g595);
 }
hrv m_848 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o2504 = &(m_848); hr_fs(_o2504, hr_str("unknown name: ", 14)); hr_fs(_o2504, f10_nm(name_811)); }));
(void)(f108_cerr(n_809, hr_sl(m_848)));
return f138_set_t(n_809, g592);
}
static int64_t f170_find_lv(int64_t name_812) {
int64_t i_813 = ((int64_t)((int64_t)(g403).n - (int64_t)((int64_t)1LL))); 
while (((i_813) >= (((int64_t)0LL)))) { int64_t v_814 = ((int64_t)((*({ hrv *_t2509 = &(g403); int64_t _i2509 = i_813; (int32_t*)_t2509->b + hr_ix(_i2509, _t2509->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:60"); })))); 
if ((((((int64_t)(((*({ hrv *_t2510 = &(g402); int64_t _i2510 = v_814; (S12*)_t2510->b + hr_ix(_i2510, _t2510->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:60"); }))).name_))) == (name_812)) && f171_visible(((int64_t)(((*({ hrv *_t2512 = &(g402); int64_t _i2512 = v_814; (S12*)_t2512->b + hr_ix(_i2512, _t2512->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:60"); }))).own_))))) { return v_814;
 }
i_813--;
 } _bk2508:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f171_visible(int64_t own_815) {
return f172_visible_in(own_815, g414);
}
static bool f172_visible_in(int64_t own_816, int64_t cur_817) {
int64_t i_818 = cur_817; 
while (((i_818) >= (((int64_t)0LL)))) { if (((i_818) == (own_816))) { return true;
 }
i_818 = ((int64_t)(((*({ hrv *_t2515 = &(g401); int64_t _i2515 = i_818; (S6*)_t2515->b + hr_ix(_i2515, _t2515->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:56"); }))).par_));
 } _bk2514:; 
return false;
}
static void f173_set_r(int64_t n_820, int64_t k_821, int64_t v_822) {
int64_t i_823 = f139_aix(n_820); 
{ uint8_t *_t2517 = &((*({ hrv *_t2518 = &(g410); int64_t _i2518 = i_823; (uint8_t*)_t2518->b + hr_ix(_i2518, _t2518->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:43"); }))); *_t2517 = ((uint8_t)(k_821)); }
{ int32_t *_t2519 = &((*({ hrv *_t2520 = &(g411); int64_t _i2520 = i_823; (int32_t*)_t2520->b + hr_ix(_i2520, _t2520->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:43"); }))); *_t2519 = ((int32_t)(v_822)); }
}
static void f174_note_cap(int64_t v_824) {
int64_t own_825 = ((int64_t)(((*({ hrv *_t2521 = &(g402); int64_t _i2521 = v_824; (S12*)_t2521->b + hr_ix(_i2521, _t2521->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:70"); }))).own_)); 
int64_t a_826 = g414; 
while ((((a_826) >= (((int64_t)0LL))) && ((a_826) != (own_825)))) { (void)(f175_add_cap_one(((int64_t)(((*({ hrv *_t2524 = &(g401); int64_t _i2524 = a_826; (S6*)_t2524->b + hr_ix(_i2524, _t2524->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:73"); }))).cfn_)), v_824));
a_826 = ((int64_t)(((*({ hrv *_t2525 = &(g401); int64_t _i2525 = a_826; (S6*)_t2525->b + hr_ix(_i2525, _t2525->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:74"); }))).par_));
 } _bk2522:; 
}
static bool f175_add_cap_one(int64_t cf_827, int64_t v_828) {
if ((((cf_827) < (((int64_t)0LL))) || ((cf_827) == (((int64_t)(((*({ hrv *_t2526 = &(g402); int64_t _i2526 = v_828; (S12*)_t2526->b + hr_ix(_i2526, _t2526->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:64"); }))).cfn_)))))) { return false;
 }
{ hrv *_v2528 = &(g405); for (int64_t _k2528 = 0; _k2528 < _v2528->n; _k2528++) { S13 x_829 = ((S13*)_v2528->b)[_k2528]; if ((((((int64_t)((x_829).inst_))) == (cf_827)) && ((((int64_t)((x_829).lv_))) == (v_828)))) { return false;
 }
 } } _bk2527:; 
(void)(({ hrv *_v2529 = &(g405); S13 _x2529 = ((S13){ .inst_ = ((int32_t)(cf_827)), .lv_ = ((int32_t)(v_828)), }); S13 *_p2529 = (S13*)hr_grow(_v2529, 1, sizeof _x2529); *_p2529 = _x2529; _p2529; }));
return true;
}
static int64_t f176_const_of(int64_t d_833) {
{ hrv *_v2531 = &(g450); for (int64_t _k2531 = 0; _k2531 < _v2531->n; _k2531++) { int32_t c_834 = ((int32_t*)_v2531->b)[_k2531]; int64_t i_835 = (int64_t)_k2531; if (((((int64_t)(c_834))) == (d_833))) { return i_835;
 }
 } } _bk2530:; 
int64_t g_836 = ((int64_t)(((*({ hrv *_t2532 = &(g506); int64_t _i2532 = d_833; (S5*)_t2532->b + hr_ix(_i2532, _t2532->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:369"); }))).node_)); 
S4 x_837 = (*({ hrv *_t2533 = &(g721); int64_t _i2533 = g_836; (S4*)_t2533->b + hr_ix(_i2533, _t2533->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:370"); })); 
if (((((((uint16_t)((uint64_t)(x_837).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || (((x_837).a_) >= (((int32_t)0LL)))) || (((x_837).b_) < (((int32_t)0LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t iv_838 = f90_kid(((int64_t)((x_837).b_)), ((int64_t)0LL)); 
M56 _t2535 = f120_ceval(iv_838, f110_ns_of(g_836)); int64_t v_839 = _t2535.r0; bool ok_840 = _t2535.r1; 
if ((!(ok_840))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if ((!(f177_all_int(iv_838)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
(void)(({ hrv *_v2539 = &(g450); int32_t _x2539 = ((int32_t)(d_833)); int32_t *_p2539 = (int32_t*)hr_grow(_v2539, 1, sizeof _x2539); *_p2539 = _x2539; _p2539; }));
(void)(({ hrv *_v2540 = &(g449); int64_t _x2540 = v_839; int64_t *_p2540 = (int64_t*)hr_grow(_v2540, 1, sizeof _x2540); *_p2540 = _x2540; _p2540; }));
return ((int64_t)((int64_t)(g450).n - (int64_t)((int64_t)1LL)));
}
static bool f177_all_int(int64_t n_841) {
S4 x_842 = (*({ hrv *_t2541 = &(g721); int64_t _i2541 = n_841; (S4*)_t2541->b + hr_ix(_i2541, _t2541->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:380"); })); 
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
{ int32_t *_t2549 = &((*({ hrv *_t2550 = &(g412); int64_t _i2550 = f139_aix(n_846); (int32_t*)_t2550->b + hr_ix(_i2550, _t2550->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:46"); }))); *_t2549 = ((int32_t)(v_847)); }
}
static int64_t f179_ck_bin(int64_t n_849, int64_t want_850) {
S4 x_851 = (*({ hrv *_t2552 = &(g721); int64_t _i2552 = n_849; (S4*)_t2552->b + hr_ix(_i2552, _t2552->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:284"); })); 
int64_t o_852 = ((int64_t)((x_851).op_)); 
int64_t a_853 = ((int64_t)((x_851).a_)); 
int64_t b_854 = ((int64_t)((x_851).b_)); 
if (((o_852) == (((int64_t)52LL)))) { (void)(f137_ck(a_853, g576));
(void)(f140_conv(a_853, g576));
int64_t nm0_855 = (g404).n; 
(void)(f180_narrow_push(a_853));
(void)(f137_ck(b_854, g576));
(void)(f140_conv(b_854, g576));
(void)(f181_narrow_pop(nm0_855));
return f138_set_t(n_849, g576);
 }
if (((o_852) == (((int64_t)53LL)))) { (void)(f137_ck(a_853, g576));
(void)(f140_conv(a_853, g576));
(void)(f137_ck(b_854, g576));
(void)(f140_conv(b_854, g576));
return f138_set_t(n_849, g576);
 }
if ((((o_852) == (((int64_t)19LL))) || ((o_852) == (((int64_t)20LL))))) { (void)(f137_ck(a_853, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
(void)(f137_ck(b_854, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_849, g576);
 }
bool cmp_864 = (((((((o_852) == (((int64_t)37LL))) || ((o_852) == (((int64_t)38LL)))) || ((o_852) == (((int64_t)39LL)))) || ((o_852) == (((int64_t)40LL)))) || ((o_852) == (((int64_t)41LL)))) || ((o_852) == (((int64_t)42LL)))); 
int64_t w_865 = ({ int64_t _r2568; if (cmp_864) { _r2568 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2568 = want_850;  } _r2568; }); 
int64_t ta_866 = f137_ck(a_853, ({ int64_t _r2570; if (((((int64_t)(((*({ hrv *_t2571 = &(g721); int64_t _i2571 = a_853; (S4*)_t2571->b + hr_ix(_i2571, _t2571->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:297"); }))).k_))) == (((int64_t)1LL)))) { _r2570 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2570 = w_865;  } _r2570; })); 
bool sh_867 = (((o_852) == (((int64_t)43LL))) || ((o_852) == (((int64_t)44LL)))); 
int64_t tb_869 = f137_ck(b_854, ({ int64_t _r2573; if (sh_867) { _r2573 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2573 = ({ int64_t _r2574; if (f166_is_pending(ta_866)) { _r2574 = w_865;  } else { _r2574 = f182_deref(ta_866);  } _r2574; });  } _r2573; })); 
if (sh_867) { if (((((*({ hrv *_t2577 = &(g568); int64_t _i2577 = tb_869; (S1*)_t2577->b + hr_ix(_i2577, _t2577->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:301"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(b_854, g580));
 } else { if (((((*({ hrv *_t2579 = &(g568); int64_t _i2579 = f182_deref(tb_869); (S1*)_t2579->b + hr_ix(_i2579, _t2579->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:301"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(b_854, hr_str("shift count must be an integer", 30)));
 }
 }
int64_t da_870 = f182_deref(ta_866); 
if (((((*({ hrv *_t2583 = &(g568); int64_t _i2583 = da_870; (S1*)_t2583->b + hr_ix(_i2583, _t2583->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:303"); }))).k_) == (((uint8_t)12LL)))) { if ((((want_850) >= (((int64_t)0LL))) && ((((*({ hrv *_t2584 = &(g568); int64_t _i2584 = want_850; (S1*)_t2584->b + hr_ix(_i2584, _t2584->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:303"); }))).k_) == (((uint8_t)3LL))))) { (void)(f140_conv(a_853, want_850));
return f138_set_t(n_849, want_850);
 }
return f138_set_t(n_849, g588);
 }
if (((((*({ hrv *_t2588 = &(g568); int64_t _i2588 = da_870; (S1*)_t2588->b + hr_ix(_i2588, _t2588->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:304"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(a_853, hr_str("shift of a non-integer", 22)));
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
if ((((((cmp_864 && (((((*({ hrv *_t2611 = &(g568); int64_t _i2611 = da_871; (S1*)_t2611->b + hr_ix(_i2611, _t2611->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:316"); }))).k_) == (((uint8_t)3LL))) && ((((*({ hrv *_t2612 = &(g568); int64_t _i2612 = db_872; (S1*)_t2612->b + hr_ix(_i2612, _t2612->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:316"); }))).k_) == (((uint8_t)3LL))))) && ((f156_is_signed(da_871)) != (f156_is_signed(db_872)))) && (((f157_ibits(da_871)) == (((int64_t)64LL))) || ((f157_ibits(db_872)) == (((int64_t)64LL))))) && (!(f155_widens(da_871, db_872)))) && (!(f155_widens(db_872, da_871))))) { (void)(f178_set_x(n_849, ((int64_t)1LL)));
return f138_set_t(n_849, g576);
 }
if ((cmp_864 && (((o_852) == (((int64_t)37LL))) || ((o_852) == (((int64_t)38LL)))))) { int64_t ka_890 = ((int64_t)(((*({ hrv *_t2621 = &(g568); int64_t _i2621 = da_871; (S1*)_t2621->b + hr_ix(_i2621, _t2621->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:321"); }))).k_)); 
int64_t kb_891 = ((int64_t)(((*({ hrv *_t2622 = &(g568); int64_t _i2622 = db_872; (S1*)_t2622->b + hr_ix(_i2622, _t2622->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:321"); }))).k_)); 
if ((((ka_890) == (((int64_t)11LL))) || ((kb_891) == (((int64_t)11LL))))) { if ((((ka_890) == (((int64_t)11LL))) && ((kb_891) == (((int64_t)11LL))))) { return f138_set_t(n_849, g576);
 }
if (((ka_890) == (((int64_t)11LL)))) { (void)(f138_set_t(a_853, tb_869));
 } else { (void)(f138_set_t(b_854, ta_866));
 }
return f138_set_t(n_849, g576);
 }
if (((((ka_890) == (((int64_t)18LL))) || ((kb_891) == (((int64_t)18LL)))) || (f167_is_byte_arr(da_871) && f167_is_byte_arr(db_872)))) { if (((ka_890) == (((int64_t)18LL)))) { (void)(f138_set_t(a_853, g593));
 }
if (((kb_891) == (((int64_t)18LL)))) { (void)(f138_set_t(b_854, g593));
 }
(void)(f178_set_x(n_849, ((int64_t)2LL)));
return f138_set_t(n_849, g576);
 }
if ((((((((ka_890) == (((int64_t)5LL))) || ((ka_890) == (((int64_t)8LL)))) || ((ka_890) == (((int64_t)6LL)))) || ((ka_890) == (((int64_t)7LL)))) || ((ka_890) == (((int64_t)9LL)))) && ((da_871) == (db_872)))) { (void)(f178_set_x(n_849, ((int64_t)3LL)));
return f138_set_t(n_849, g576);
 }
if (((((ka_890) == (((int64_t)6LL))) && ((kb_891) == (((int64_t)7LL)))) || (((ka_890) == (((int64_t)7LL))) && ((kb_891) == (((int64_t)6LL)))))) { (void)(f178_set_x(n_849, ((int64_t)3LL)));
return f138_set_t(n_849, g576);
 }
if ((((ka_890) == (((int64_t)19LL))) || ((kb_891) == (((int64_t)19LL))))) { if (((ka_890) == (((int64_t)19LL)))) { (void)(f140_conv(a_853, db_872));
 } else { (void)(f140_conv(b_854, da_871));
 }
(void)(f178_set_x(n_849, ((int64_t)3LL)));
return f138_set_t(n_849, g576);
 }
 }
int64_t u_903 = f185_unify(n_849, a_853, b_854); 
if (cmp_864) { if (((((*({ hrv *_t2642 = &(g568); int64_t _i2642 = u_903; (S1*)_t2642->b + hr_ix(_i2642, _t2642->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:329"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(a_853, g580));
(void)(f140_conv(b_854, g580));
 }
if (((((*({ hrv *_t2645 = &(g568); int64_t _i2645 = u_903; (S1*)_t2645->b + hr_ix(_i2645, _t2645->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:329"); }))).k_) == (((uint8_t)13LL)))) { (void)(f140_conv(a_853, g586));
(void)(f140_conv(b_854, g586));
 }
return f138_set_t(n_849, g576);
 }
int64_t uk_904 = ((int64_t)(((*({ hrv *_t2649 = &(g568); int64_t _i2649 = u_903; (S1*)_t2649->b + hr_ix(_i2649, _t2649->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:330"); }))).k_)); 
if (((((((((o_852) == (((int64_t)49LL))) || ((o_852) == (((int64_t)50LL)))) || ((o_852) == (((int64_t)51LL)))) && ((uk_904) != (((int64_t)3LL)))) && ((uk_904) != (((int64_t)12LL)))) && ((uk_904) != (((int64_t)2LL)))) && ((uk_904) != (((int64_t)0LL))))) { (void)(f108_cerr(n_849, hr_str("bitwise operator on a non-integer", 33)));
 }
if ((((((uk_904) == (((int64_t)2LL))) && ((o_852) != (((int64_t)49LL)))) && ((o_852) != (((int64_t)50LL)))) && ((o_852) != (((int64_t)51LL))))) { (void)(f108_cerr(n_849, hr_str("arithmetic on bool", 18)));
 }
return f138_set_t(n_849, u_903);
}
static void f180_narrow_push(int64_t c_856) {
if (((c_856) < (((int64_t)0LL)))) { return;
 }
S4 x_857 = (*({ hrv *_t2653 = &(g721); int64_t _i2653 = c_856; (S4*)_t2653->b + hr_ix(_i2653, _t2653->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:84"); })); 
int64_t k_858 = ((int64_t)((x_857).k_)); 
if ((((k_858) == (((int64_t)8LL))) && ((f159_rk(c_856)) == (((int64_t)1LL))))) { int64_t v_859 = f160_rv(c_856); 
int64_t t_860 = ((int64_t)(((*({ hrv *_t2656 = &(g402); int64_t _i2656 = v_859; (S12*)_t2656->b + hr_ix(_i2656, _t2656->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:87"); }))).ty_)); 
if ((((((*({ hrv *_t2657 = &(g568); int64_t _i2657 = t_860; (S1*)_t2657->b + hr_ix(_i2657, _t2657->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:88"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2658 = &(g568); int64_t _i2658 = t_860; (S1*)_t2658->b + hr_ix(_i2658, _t2658->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:88"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(({ hrv *_v2659 = &(g404); int32_t _x2659 = ((int32_t)(v_859)); int32_t *_p2659 = (int32_t*)hr_grow(_v2659, 1, sizeof _x2659); *_p2659 = _x2659; _p2659; }));
(void)(({ hrv *_v2660 = &(g404); int32_t _x2660 = ((int32_t)(t_860)); int32_t *_p2660 = (int32_t*)hr_grow(_v2660, 1, sizeof _x2660); *_p2660 = _x2660; _p2660; }));
{ int32_t *_t2661 = &(((*({ hrv *_t2662 = &(g402); int64_t _i2662 = v_859; (S12*)_t2662->b + hr_ix(_i2662, _t2662->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:90"); }))).ty_); *_t2661 = ((int32_t)(f119_t_ref(((int64_t)(((*({ hrv *_t2664 = &(g568); int64_t _i2664 = t_860; (S1*)_t2664->b + hr_ix(_i2664, _t2664->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:90"); }))).a_)), ((int64_t)0LL)))); }
 }
return;
 }
if ((((k_858) == (((int64_t)9LL))) && ((((int64_t)((x_857).op_))) == (((int64_t)52LL))))) { (void)(f180_narrow_push(((int64_t)((x_857).a_))));
(void)(f180_narrow_push(((int64_t)((x_857).b_))));
 }
}
static void f181_narrow_pop(int64_t m_861) {
while ((((g404).n) > (m_861))) { int32_t old_t_862 = ({ hrv *_v2668 = &(g404); if (!_v2668->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:101"); ((int32_t*)_v2668->b)[--_v2668->n]; }); 
int64_t v_863 = ((int64_t)(({ hrv *_v2669 = &(g404); if (!_v2669->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:102"); ((int32_t*)_v2669->b)[--_v2669->n]; }))); 
{ int32_t *_t2670 = &(((*({ hrv *_t2671 = &(g402); int64_t _i2671 = v_863; (S12*)_t2671->b + hr_ix(_i2671, _t2671->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:103"); }))).ty_); *_t2670 = old_t_862; }
 } _bk2667:; 
}
static int64_t f182_deref(int64_t t_868) {
return ({ int64_t _r2672; if ((((((*({ hrv *_t2673 = &(g568); int64_t _i2673 = t_868; (S1*)_t2673->b + hr_ix(_i2673, _t2673->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:67"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2674 = &(g568); int64_t _i2674 = t_868; (S1*)_t2674->b + hr_ix(_i2674, _t2674->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:67"); }))).c_) < (((int32_t)0LL))))) { _r2672 = ((int64_t)(((*({ hrv *_t2675 = &(g568); int64_t _i2675 = t_868; (S1*)_t2675->b + hr_ix(_i2675, _t2675->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:67"); }))).a_));  } else { _r2672 = t_868;  } _r2672; });
}
static int64_t f183_leaf_kind(int64_t t_873) {
S1 x_874 = (*({ hrv *_t2676 = &(g568); int64_t _i2676 = t_873; (S1*)_t2676->b + hr_ix(_i2676, _t2676->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:270"); })); 
int64_t k_875 = ((int64_t)((x_874).k_)); 
if (((k_875) == (((int64_t)3LL)))) { return ((int64_t)1LL);
 }
if (((k_875) == (((int64_t)4LL)))) { return ((int64_t)2LL);
 }
if (((k_875) == (((int64_t)5LL)))) { int64_t r_876 = ((int64_t)0LL); 
{ int32_t _e2678 = ((*({ hrv *_t2679 = &(g571); int64_t _i2679 = (x_874).a_; (S10*)_t2679->b + hr_ix(_i2679, _t2679->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:272"); }))).fnum_; for (int32_t _k2678 = 0; _k2678 < _e2678; _k2678++) { int32_t i_877 = (int32_t)_k2678; S11 f_878 = (*({ hrv *_t2680 = &(g572); int64_t _i2680 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2681 = &(g571); int64_t _i2681 = (x_874).a_; (S10*)_t2681->b + hr_ix(_i2681, _t2681->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:272"); }))).f0_)) + (int64_t)((int64_t)(i_877)))); (S11*)_t2680->b + hr_ix(_i2680, _t2680->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:272"); })); 
if ((((f_878).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t l_879 = f183_leaf_kind(((int64_t)((f_878).ty_))); 
if ((((l_879) == (((int64_t)0LL))) || (((r_876) != (((int64_t)0LL))) && ((r_876) != (l_879))))) { return ((int64_t)0LL);
 }
r_876 = l_879;
 } } _bk2677:; 
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
S1 x_884 = (*({ hrv *_t2684 = &(g568); int64_t _i2684 = t_883; (S1*)_t2684->b + hr_ix(_i2684, _t2684->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:277"); })); 
int64_t k_885 = ((int64_t)((x_884).k_)); 
if ((((k_885) == (((int64_t)3LL))) || ((k_885) == (((int64_t)4LL))))) { return t_883;
 }
if (((k_885) == (((int64_t)5LL)))) { int64_t r_886 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e2686 = ((*({ hrv *_t2687 = &(g571); int64_t _i2687 = (x_884).a_; (S10*)_t2687->b + hr_ix(_i2687, _t2687->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:279"); }))).fnum_; for (int32_t _k2686 = 0; _k2686 < _e2686; _k2686++) { int32_t i_887 = (int32_t)_k2686; S11 f_888 = (*({ hrv *_t2688 = &(g572); int64_t _i2688 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2689 = &(g571); int64_t _i2689 = (x_884).a_; (S10*)_t2689->b + hr_ix(_i2689, _t2689->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:279"); }))).f0_)) + (int64_t)((int64_t)(i_887)))); (S11*)_t2688->b + hr_ix(_i2688, _t2688->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:279"); })); 
if ((((f_888).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t l_889 = f184_leaf_type(((int64_t)((f_888).ty_))); 
if ((((l_889) < (((int64_t)0LL))) || (((r_886) >= (((int64_t)0LL))) && ((r_886) != (l_889))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
r_886 = l_889;
 } } _bk2685:; 
return r_886;
 }
if ((((k_885) == (((int64_t)8LL))) && (((x_884).s_) == (((uint8_t)(((uint8_t)1LL))))))) { return f184_leaf_type(((int64_t)((x_884).a_)));
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f185_unify(int64_t n_892, int64_t a_893, int64_t b_894) {
int64_t ta_895 = f141_at(a_893); 
int64_t tb_896 = f141_at(b_894); 
if ((((ta_895) < (((int64_t)0LL))) || ((tb_896) < (((int64_t)0LL))))) { return g592;
 }
int64_t da_897 = f182_deref(ta_895); 
int64_t db_898 = f182_deref(tb_896); 
int64_t ka_899 = ((int64_t)(((*({ hrv *_t2696 = &(g568); int64_t _i2696 = da_897; (S1*)_t2696->b + hr_ix(_i2696, _t2696->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:246"); }))).k_)); 
int64_t kb_900 = ((int64_t)(((*({ hrv *_t2697 = &(g568); int64_t _i2697 = db_898; (S1*)_t2697->b + hr_ix(_i2697, _t2697->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:246"); }))).k_)); 
if ((((ka_899) == (((int64_t)0LL))) || ((kb_900) == (((int64_t)0LL))))) { return g592;
 }
if ((((ka_899) == (((int64_t)12LL))) && ((kb_900) == (((int64_t)12LL))))) { return g588;
 }
if (((((ka_899) == (((int64_t)12LL))) || ((ka_899) == (((int64_t)13LL)))) && ((kb_900) == (((int64_t)13LL))))) { return g589;
 }
if ((((ka_899) == (((int64_t)13LL))) && ((kb_900) == (((int64_t)12LL))))) { return g589;
 }
if ((((ka_899) == (((int64_t)18LL))) && ((kb_900) == (((int64_t)18LL))))) { (void)(f138_set_t(a_893, g593));
(void)(f138_set_t(b_894, g593));
return g593;
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
if (((kb_900) == (((int64_t)3LL)))) { return g589;
 }
 }
if (((kb_900) == (((int64_t)13LL)))) { if (((ka_899) == (((int64_t)4LL)))) { (void)(f140_conv(b_894, da_897));
return da_897;
 }
if (((ka_899) == (((int64_t)3LL)))) { return g589;
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
if (((((ka_899) == (((int64_t)7LL))) && ((kb_900) == (((int64_t)7LL)))) && ((((*({ hrv *_t2716 = &(g568); int64_t _i2716 = da_897; (S1*)_t2716->b + hr_ix(_i2716, _t2716->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:263"); }))).a_) == (((*({ hrv *_t2717 = &(g568); int64_t _i2717 = db_898; (S1*)_t2717->b + hr_ix(_i2717, _t2717->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:263"); }))).a_)))) { int64_t et_901 = f136_t_enum(((int64_t)(((*({ hrv *_t2719 = &(g568); int64_t _i2719 = da_897; (S1*)_t2719->b + hr_ix(_i2719, _t2719->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:263"); }))).a_)), false); 
(void)(f145_set_cv(a_893, et_901));
(void)(f145_set_cv(b_894, et_901));
return et_901;
 }
if (((((ka_899) == (((int64_t)6LL))) && ((kb_900) == (((int64_t)7LL)))) && ((((*({ hrv *_t2722 = &(g568); int64_t _i2722 = da_897; (S1*)_t2722->b + hr_ix(_i2722, _t2722->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:264"); }))).a_) == (((*({ hrv *_t2723 = &(g568); int64_t _i2723 = db_898; (S1*)_t2723->b + hr_ix(_i2723, _t2723->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:264"); }))).a_)))) { (void)(f145_set_cv(b_894, da_897));
if (((ta_895) != (da_897))) { (void)(f145_set_cv(a_893, da_897));
 }
return da_897;
 }
if (((((kb_900) == (((int64_t)6LL))) && ((ka_899) == (((int64_t)7LL)))) && ((((*({ hrv *_t2726 = &(g568); int64_t _i2726 = da_897; (S1*)_t2726->b + hr_ix(_i2726, _t2726->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:265"); }))).a_) == (((*({ hrv *_t2727 = &(g568); int64_t _i2727 = db_898; (S1*)_t2727->b + hr_ix(_i2727, _t2727->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:265"); }))).a_)))) { (void)(f145_set_cv(a_893, db_898));
if (((tb_896) != (db_898))) { (void)(f145_set_cv(b_894, db_898));
 }
return db_898;
 }
hrv m_902 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2732 __attribute__((cleanup(hr_rdrop))) = {0}; hrv _t2734 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2731 = &(m_902); hr_fs(_o2731, hr_str("operands of types ", 18)); hr_fs(_o2731, hr_sl(*hr_tmp(&_t2732, f164_tn(da_897)))); hr_fs(_o2731, hr_str(" and ", 5)); hr_fs(_o2731, hr_sl(*hr_tmp(&_t2734, f164_tn(db_898)))); hr_fs(_o2731, hr_str(" need a cast to a common type", 29)); }));
}
(void)(f108_cerr(n_892, hr_sl(m_902)));
return g592;
}
static int64_t f186_ck_un(int64_t n_906, int64_t want_907) {
S4 x_908 = (*({ hrv *_t2737 = &(g721); int64_t _i2737 = n_906; (S4*)_t2737->b + hr_ix(_i2737, _t2737->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:336"); })); 
int64_t o_909 = ((int64_t)((x_908).op_)); 
int64_t a_910 = ((int64_t)((x_908).a_)); 
if (((o_909) == (((int64_t)47LL)))) { (void)(f137_ck(a_910, g576));
(void)(f140_conv(a_910, g576));
return f138_set_t(n_906, g576);
 }
if (((o_909) == (((int64_t)49LL)))) { int64_t t_911 = f137_ck(a_910, ({ int64_t _r2742; if ((((want_907) >= (((int64_t)0LL))) && ((((*({ hrv *_t2743 = &(g568); int64_t _i2743 = want_907; (S1*)_t2743->b + hr_ix(_i2743, _t2743->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:339"); }))).k_) == (((uint8_t)10LL))))) { _r2742 = ((int64_t)(((*({ hrv *_t2744 = &(g568); int64_t _i2744 = want_907; (S1*)_t2744->b + hr_ix(_i2744, _t2744->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:339"); }))).a_));  } else { _r2742 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2742; })); 
if (f166_is_pending(t_911)) { (void)(f187_default_t(a_910));
 }
(void)(f178_set_x(n_906, ((int64_t)1LL)));
return f138_set_t(n_906, f141_at(a_910));
 }
int64_t t_930 = f137_ck(a_910, ({ int64_t _r2751; if ((((((int64_t)(((*({ hrv *_t2752 = &(g721); int64_t _i2752 = a_910; (S4*)_t2752->b + hr_ix(_i2752, _t2752->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:340"); }))).k_))) == (((int64_t)1LL))) || ((((int64_t)(((*({ hrv *_t2753 = &(g721); int64_t _i2753 = a_910; (S4*)_t2753->b + hr_ix(_i2753, _t2753->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:340"); }))).k_))) == (((int64_t)2LL))))) { _r2751 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2751 = want_907;  } _r2751; })); 
int64_t d_931 = f182_deref(t_930); 
if (((t_930) != (d_931))) { (void)(f145_set_cv(a_910, d_931));
 }
if (((((o_909) == (((int64_t)22LL))) && ((((*({ hrv *_t2756 = &(g568); int64_t _i2756 = d_931; (S1*)_t2756->b + hr_ix(_i2756, _t2756->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:343"); }))).k_) == (((uint8_t)3LL)))) && (!(f156_is_signed(d_931))))) { (void)(f108_cerr(n_906, hr_str("unary - of an unsigned integer", 30)));
 }
return f138_set_t(n_906, d_931);
}
static int64_t f187_default_t(int64_t n_912) {
int64_t t_913 = f141_at(n_912); 
if (((t_913) < (((int64_t)0LL)))) { return g575;
 }
int64_t k_914 = ((int64_t)(((*({ hrv *_t2761 = &(g568); int64_t _i2761 = t_913; (S1*)_t2761->b + hr_ix(_i2761, _t2761->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:224"); }))).k_)); 
if (((k_914) == (((int64_t)12LL)))) { M78 _t2762 = f158_cval(n_912); int64_t v_915 = _t2762.r0; bool u_916 = _t2762.r1; bool ok_917 = _t2762.r2; 
int64_t d_918 = ({ int64_t _r2764; if ((ok_917 && u_916)) { _r2764 = g584;  } else { _r2764 = g580;  } _r2764; }); 
(void)(f165_commit(n_912, d_918));
return d_918;
 }
if (((k_914) == (((int64_t)13LL)))) { (void)(f165_commit(n_912, g586));
return g586;
 }
if (((k_914) == (((int64_t)18LL)))) { (void)(f138_set_t(n_912, g593));
return g593;
 }
if (((k_914) == (((int64_t)19LL)))) { S4 x_919 = (*({ hrv *_t2768 = &(g721); int64_t _i2768 = n_912; (S4*)_t2768->b + hr_ix(_i2768, _t2768->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:229"); })); 
int64_t e_920 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((x_919).a_) >= (((int32_t)0LL)))) { e_920 = f187_default_t(((int64_t)((x_919).a_)));
M78 _t2770 = f158_cval(((int64_t)((x_919).b_))); int64_t cnt_921 = _t2770.r0; bool u0_922 = _t2770.r1; bool ok_923 = _t2770.r2; 
(void)(f140_conv(((int64_t)((x_919).b_)), g580));
int64_t a_924 = f123_t_arr(e_920, ((int64_t)1LL), cnt_921, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f138_set_t(n_912, a_924));
return a_924;
 }
{ int32_t _e2776 = (x_919).n_; for (int32_t _k2776 = 0; _k2776 < _e2776; _k2776++) { int32_t i_925 = (int32_t)_k2776; int64_t c_926 = f90_kid(n_912, ((int64_t)(i_925))); 
int64_t ct_927 = f141_at(c_926); 
if ((!(f166_is_pending(ct_927)))) { e_920 = ct_927;
 }
 } } _bk2775:; 
if ((((e_920) < (((int64_t)0LL))) && (((x_919).n_) > (((int32_t)0LL))))) { e_920 = f187_default_t(f90_kid(n_912, ((int64_t)0LL)));
 }
if (((e_920) < (((int64_t)0LL)))) { (void)(f108_cerr(n_912, hr_str("an empty [] has no element type here", 36)));
return g592;
 }
{ int32_t _e2784 = (x_919).n_; for (int32_t _k2784 = 0; _k2784 < _e2784; _k2784++) { int32_t i_928 = (int32_t)_k2784; (void)(f140_conv(f90_kid(n_912, ((int64_t)(i_928))), e_920));
 } } _bk2783:; 
int64_t a_929 = f123_t_arr(e_920, ((int64_t)1LL), ((int64_t)((x_919).n_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f138_set_t(n_912, a_929));
return a_929;
 }
return t_913;
}
static int64_t f188_ck_dot(int64_t n_933, int64_t want_934) {
S4 x_935 = (*({ hrv *_t2789 = &(g721); int64_t _i2789 = n_933; (S4*)_t2789->b + hr_ix(_i2789, _t2789->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:429"); })); 
int64_t a_936 = ((int64_t)((x_935).a_)); 
int64_t name_937 = ((int64_t)((x_935).s_)); 
if ((((((*({ hrv *_t2790 = &(g721); int64_t _i2790 = a_936; (S4*)_t2790->b + hr_ix(_i2790, _t2790->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:432"); }))).k_) == (((uint8_t)8LL))) && ((f170_find_lv(((int64_t)(((*({ hrv *_t2792 = &(g721); int64_t _i2792 = a_936; (S4*)_t2792->b + hr_ix(_i2792, _t2792->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:432"); }))).s_)))) < (((int64_t)0LL))))) { int64_t ns_938 = f110_ns_of(a_936); 
int64_t de_939 = f116_lookup_q(((int64_t)(((*({ hrv *_t2795 = &(g721); int64_t _i2795 = a_936; (S4*)_t2795->b + hr_ix(_i2795, _t2795->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:434"); }))).s_)), ns_938, ((int64_t)2LL)); 
if ((((de_939) >= (((int64_t)0LL))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t2797 = &(g721); int64_t _i2797 = a_936; (S4*)_t2797->b + hr_ix(_i2797, _t2797->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:435"); }))).s_)), ns_938, ((int64_t)5LL))) < (((int64_t)0LL))))) { int64_t et_943 = f189_rtype_name_enum(de_939); 
int64_t ei_944 = ((int64_t)(((*({ hrv *_t2799 = &(g568); int64_t _i2799 = et_943; (S1*)_t2799->b + hr_ix(_i2799, _t2799->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:437"); }))).a_)); 
{ int32_t _e2801 = ((*({ hrv *_t2802 = &(g573); int64_t _i2802 = ei_944; (S8*)_t2802->b + hr_ix(_i2802, _t2802->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:438"); }))).vnum_; for (int32_t _k2801 = 0; _k2801 < _e2801; _k2801++) { int32_t i_945 = (int32_t)_k2801; if (((((int64_t)(((*({ hrv *_t2803 = &(g574); int64_t _i2803 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2804 = &(g573); int64_t _i2804 = ei_944; (S8*)_t2804->b + hr_ix(_i2804, _t2804->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:438"); }))).v0_)) + (int64_t)((int64_t)(i_945)))); (S9*)_t2803->b + hr_ix(_i2803, _t2803->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:438"); }))).name_))) == (name_937))) { (void)(f173_set_r(n_933, ((int64_t)7LL), ((int64_t)(i_945))));
return f138_set_t(n_933, f125_t_variant(ei_944, ((int64_t)(i_945))));
 }
 } } _bk2800:; 
hrv m_946 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2811 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2809 = &(m_946); hr_fs(_o2809, hr_str("no variant ", 11)); hr_fs(_o2809, f10_nm(name_937)); hr_fs(_o2809, hr_str(" in ", 4)); hr_fs(_o2809, hr_sl(*hr_tmp(&_t2811, f164_tn(et_943)))); }));
}
(void)(f108_cerr(n_933, hr_sl(m_946)));
return f138_set_t(n_933, g592);
 }
 }
int64_t t0_947 = f137_ck(a_936, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t t_948 = t0_947; 
if (((((*({ hrv *_t2816 = &(g568); int64_t _i2816 = t_948; (S1*)_t2816->b + hr_ix(_i2816, _t2816->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:444"); }))).k_) == (((uint8_t)18LL)))) { t_948 = g593;
(void)(f138_set_t(a_936, g593));
 }
if (((((*({ hrv *_t2818 = &(g568); int64_t _i2818 = t_948; (S1*)_t2818->b + hr_ix(_i2818, _t2818->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:445"); }))).k_) == (((uint8_t)19LL)))) { t_948 = f187_default_t(a_936);
 }
int64_t d_949 = f182_deref(t_948); 
int64_t k_950 = ((int64_t)(((*({ hrv *_t2821 = &(g568); int64_t _i2821 = d_949; (S1*)_t2821->b + hr_ix(_i2821, _t2821->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:447"); }))).k_)); 
if (((((k_950) == (((int64_t)8LL))) || ((k_950) == (((int64_t)9LL)))) && hr_streq(f10_nm(name_937), hr_str("len", 3)))) { (void)(f173_set_r(n_933, ((int64_t)8LL), ((int64_t)1LL)));
return f138_set_t(n_933, g580);
 }
if ((((k_950) == (((int64_t)8LL))) && hr_streq(f10_nm(name_937), hr_str("cap", 3)))) { (void)(f173_set_r(n_933, ((int64_t)8LL), ((int64_t)2LL)));
return f138_set_t(n_933, g580);
 }
if (((k_950) == (((int64_t)5LL)))) { int64_t si_951 = ((int64_t)(((*({ hrv *_t2828 = &(g568); int64_t _i2828 = d_949; (S1*)_t2828->b + hr_ix(_i2828, _t2828->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:451"); }))).a_)); 
int64_t fi_955 = f190_sfield(si_951, name_937); 
if (((fi_955) >= (((int64_t)0LL)))) { (void)(f173_set_r(n_933, ((int64_t)5LL), fi_955));
int64_t ft_956 = ((int64_t)(((*({ hrv *_t2831 = &(g572); int64_t _i2831 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2832 = &(g571); int64_t _i2832 = si_951; (S10*)_t2832->b + hr_ix(_i2832, _t2832->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:453"); }))).f0_)) + (int64_t)fi_955)); (S11*)_t2831->b + hr_ix(_i2831, _t2831->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:453"); }))).ty_)); 
return f138_set_t(n_933, f191_decode_rel(ft_956));
 }
 }
if (((k_950) == (((int64_t)7LL)))) { S9 v_958 = (*({ hrv *_t2835 = &(g574); int64_t _i2835 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2836 = &(g573); int64_t _i2836 = ((*({ hrv *_t2837 = &(g568); int64_t _i2837 = d_949; (S1*)_t2837->b + hr_ix(_i2837, _t2837->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:456"); }))).a_; (S8*)_t2836->b + hr_ix(_i2836, _t2836->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:456"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t2838 = &(g568); int64_t _i2838 = d_949; (S1*)_t2838->b + hr_ix(_i2838, _t2838->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:456"); }))).c_)))); (S9*)_t2835->b + hr_ix(_i2835, _t2835->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:456"); })); 
if ((((v_958).si_) >= (((int32_t)0LL)))) { int64_t fi_959 = f190_sfield(((int64_t)((v_958).si_)), name_937); 
if (((fi_959) >= (((int64_t)0LL)))) { (void)(f173_set_r(n_933, ((int64_t)5LL), fi_959));
(void)(f178_set_x(n_933, ((int64_t)((v_958).si_))));
return f138_set_t(n_933, f191_decode_rel(((int64_t)(((*({ hrv *_t2844 = &(g572); int64_t _i2844 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2845 = &(g571); int64_t _i2845 = (v_958).si_; (S10*)_t2845->b + hr_ix(_i2845, _t2845->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:457"); }))).f0_)) + (int64_t)fi_959)); (S11*)_t2844->b + hr_ix(_i2844, _t2844->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:457"); }))).ty_))));
 }
 }
 }
hrv m_960 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2849 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2847 = &(m_960); hr_fs(_o2847, hr_str("no field ", 9)); hr_fs(_o2847, f10_nm(name_937)); hr_fs(_o2847, hr_str(" in ", 4)); hr_fs(_o2847, hr_sl(*hr_tmp(&_t2849, f164_tn(d_949)))); }));
}
(void)(f108_cerr(n_933, hr_sl(m_960)));
return f138_set_t(n_933, g592);
}
static int64_t f189_rtype_name_enum(int64_t de_940) {
int64_t node_941 = ((int64_t)(((*({ hrv *_t2853 = &(g506); int64_t _i2853 = de_940; (S5*)_t2853->b + hr_ix(_i2853, _t2853->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:462"); }))).node_)); 
L84 none_942 = ({ L84 _t2854; memset(&_t2854, 0, sizeof _t2854); _t2854.n = 0; _t2854; }); 
return f136_t_enum(f135_inst_enum(node_941, ({ hsl _t2857 = ({ L84 *_t2858 = &(none_942); (hsl){ (uint8_t*)_t2858->e, _t2858->n }; }); int64_t _l2857 = 0, _h2857 = _t2857.n; if (_l2857 < 0 || _h2857 < _l2857 || _h2857 > _t2857.n) hr_slerr(_l2857, _h2857, _t2857.n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:462"); (hsl){ _t2857.p + _l2857 * (int64_t)sizeof(int32_t), _h2857 - _l2857 }; })), false);
}
static int64_t f190_sfield(int64_t si_952, int64_t name_953) {
{ int32_t _e2860 = ((*({ hrv *_t2861 = &(g571); int64_t _i2861 = si_952; (S10*)_t2861->b + hr_ix(_i2861, _t2861->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:196"); }))).fnum_; for (int32_t _k2860 = 0; _k2860 < _e2860; _k2860++) { int32_t i_954 = (int32_t)_k2860; if (((((int64_t)(((*({ hrv *_t2862 = &(g572); int64_t _i2862 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2863 = &(g571); int64_t _i2863 = si_952; (S10*)_t2863->b + hr_ix(_i2863, _t2863->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:196"); }))).f0_)) + (int64_t)((int64_t)(i_954)))); (S11*)_t2862->b + hr_ix(_i2862, _t2862->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:196"); }))).name_))) == (name_953))) { return ((int64_t)(i_954));
 }
 } } _bk2859:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f191_decode_rel(int64_t ft_957) {
return ({ int64_t _r2864; if ((((((*({ hrv *_t2865 = &(g568); int64_t _i2865 = ft_957; (S1*)_t2865->b + hr_ix(_i2865, _t2865->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:427"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2866 = &(g568); int64_t _i2866 = ft_957; (S1*)_t2866->b + hr_ix(_i2866, _t2866->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:427"); }))).c_) >= (((int32_t)0LL))))) { _r2864 = f119_t_ref(((int64_t)(((*({ hrv *_t2868 = &(g568); int64_t _i2868 = ft_957; (S1*)_t2868->b + hr_ix(_i2868, _t2868->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:427"); }))).a_)), ((int64_t)(((*({ hrv *_t2869 = &(g568); int64_t _i2869 = ft_957; (S1*)_t2869->b + hr_ix(_i2869, _t2869->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:427"); }))).fl_)));  } else { _r2864 = ft_957;  } _r2864; });
}
static int64_t f192_ck_idx(int64_t n_961, int64_t want_962) {
S4 x_963 = (*({ hrv *_t2870 = &(g721); int64_t _i2870 = n_961; (S4*)_t2870->b + hr_ix(_i2870, _t2870->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:464"); })); 
int64_t t_964 = f137_ck(((int64_t)((x_963).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t2872 = &(g568); int64_t _i2872 = t_964; (S1*)_t2872->b + hr_ix(_i2872, _t2872->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:466"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_963).a_)), g593));
t_964 = g593;
 }
if (((((*({ hrv *_t2874 = &(g568); int64_t _i2874 = t_964; (S1*)_t2874->b + hr_ix(_i2874, _t2874->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:467"); }))).k_) == (((uint8_t)19LL)))) { t_964 = f187_default_t(((int64_t)((x_963).a_)));
 }
int64_t d_965 = f182_deref(t_964); 
int64_t ti_966 = f137_ck(((int64_t)((x_963).b_)), g580); 
if (((((*({ hrv *_t2878 = &(g568); int64_t _i2878 = ti_966; (S1*)_t2878->b + hr_ix(_i2878, _t2878->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:470"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_963).b_)), g580));
 } else { int64_t di_967 = f182_deref(ti_966); 
if ((((((*({ hrv *_t2881 = &(g568); int64_t _i2881 = di_967; (S1*)_t2881->b + hr_ix(_i2881, _t2881->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:470"); }))).k_) != (((uint8_t)3LL))) && ((((*({ hrv *_t2882 = &(g568); int64_t _i2882 = di_967; (S1*)_t2882->b + hr_ix(_i2882, _t2882->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:470"); }))).k_) != (((uint8_t)17LL))))) { (void)(f108_cerr(((int64_t)((x_963).b_)), hr_str("index must be an integer", 24)));
 } else { if (((di_967) != (ti_966))) { (void)(f145_set_cv(((int64_t)((x_963).b_)), di_967));
 }
 }
 }
int64_t k_968 = ((int64_t)(((*({ hrv *_t2885 = &(g568); int64_t _i2885 = d_965; (S1*)_t2885->b + hr_ix(_i2885, _t2885->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:471"); }))).k_)); 
if ((((k_968) == (((int64_t)8LL))) || ((k_968) == (((int64_t)9LL))))) { return f138_set_t(n_961, f191_decode_rel(((int64_t)(((*({ hrv *_t2888 = &(g568); int64_t _i2888 = d_965; (S1*)_t2888->b + hr_ix(_i2888, _t2888->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:472"); }))).a_))));
 }
hrv m_969 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2891 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2890 = &(m_969); hr_fs(_o2890, hr_str("cannot index ", 13)); hr_fs(_o2890, hr_sl(*hr_tmp(&_t2891, f164_tn(d_965)))); }));
}
(void)(f108_cerr(n_961, hr_sl(m_969)));
return f138_set_t(n_961, g592);
}
static int64_t f193_ck_slice(int64_t n_970, int64_t want_971) {
S4 x_972 = (*({ hrv *_t2895 = &(g721); int64_t _i2895 = n_970; (S4*)_t2895->b + hr_ix(_i2895, _t2895->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:477"); })); 
int64_t t_973 = f137_ck(((int64_t)((x_972).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t2897 = &(g568); int64_t _i2897 = t_973; (S1*)_t2897->b + hr_ix(_i2897, _t2897->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:479"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_972).a_)), g593));
t_973 = g593;
 }
if (((((*({ hrv *_t2899 = &(g568); int64_t _i2899 = t_973; (S1*)_t2899->b + hr_ix(_i2899, _t2899->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:480"); }))).k_) == (((uint8_t)19LL)))) { t_973 = f187_default_t(((int64_t)((x_972).a_)));
 }
int64_t d_974 = f182_deref(t_973); 
if ((((x_972).b_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_972).b_)), g580));
(void)(f140_conv(((int64_t)((x_972).b_)), g580));
 }
if ((((x_972).c_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_972).c_)), g580));
(void)(f140_conv(((int64_t)((x_972).c_)), g580));
 }
int64_t k_975 = ((int64_t)(((*({ hrv *_t2906 = &(g568); int64_t _i2906 = d_974; (S1*)_t2906->b + hr_ix(_i2906, _t2906->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:484"); }))).k_)); 
if (((k_975) == (((int64_t)8LL)))) { return f138_set_t(n_970, f18_t_slice(((int64_t)(((*({ hrv *_t2909 = &(g568); int64_t _i2909 = d_974; (S1*)_t2909->b + hr_ix(_i2909, _t2909->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:485"); }))).a_)), false));
 }
if (((k_975) == (((int64_t)9LL)))) { return f138_set_t(n_970, d_974);
 }
hrv m_976 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2913 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2912 = &(m_976); hr_fs(_o2912, hr_str("cannot slice ", 13)); hr_fs(_o2912, hr_sl(*hr_tmp(&_t2913, f164_tn(d_974)))); }));
}
(void)(f108_cerr(n_970, hr_sl(m_976)));
return f138_set_t(n_970, g592);
}
static int64_t f194_ck_as(int64_t n_977, int64_t want_978) {
S4 x_979 = (*({ hrv *_t2917 = &(g721); int64_t _i2917 = n_977; (S4*)_t2917->b + hr_ix(_i2917, _t2917->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:491"); })); 
int64_t t_980 = f113_rtype(((int64_t)((x_979).b_)), f110_ns_of(n_977)); 
int64_t f_981 = f137_ck(((int64_t)((x_979).a_)), ({ int64_t _r2921; if ((((((*({ hrv *_t2922 = &(g568); int64_t _i2922 = t_980; (S1*)_t2922->b + hr_ix(_i2922, _t2922->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:493"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2923 = &(g568); int64_t _i2923 = t_980; (S1*)_t2923->b + hr_ix(_i2923, _t2923->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:493"); }))).k_) == (((uint8_t)4LL))))) { _r2921 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2921 = t_980;  } _r2921; })); 
int64_t df_982 = f182_deref(f_981); 
if ((((((*({ hrv *_t2925 = &(g568); int64_t _i2925 = df_982; (S1*)_t2925->b + hr_ix(_i2925, _t2925->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:495"); }))).k_) == (((uint8_t)12LL))) || ((((*({ hrv *_t2926 = &(g568); int64_t _i2926 = df_982; (S1*)_t2926->b + hr_ix(_i2926, _t2926->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:495"); }))).k_) == (((uint8_t)13LL))))) { (void)(f140_conv(((int64_t)((x_979).a_)), ({ int64_t _r2928; if ((((((*({ hrv *_t2929 = &(g568); int64_t _i2929 = t_980; (S1*)_t2929->b + hr_ix(_i2929, _t2929->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:495"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2930 = &(g568); int64_t _i2930 = t_980; (S1*)_t2930->b + hr_ix(_i2930, _t2930->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:495"); }))).k_) == (((uint8_t)4LL))))) { _r2928 = t_980;  } else { _r2928 = g580;  } _r2928; })));
 } else { if (((df_982) != (f_981))) { (void)(f145_set_cv(((int64_t)((x_979).a_)), df_982));
 }
 }
return f138_set_t(n_977, t_980);
}
static int64_t f195_ck_arr(int64_t n_983, int64_t want_984) {
S4 x_985 = (*({ hrv *_t2933 = &(g721); int64_t _i2933 = n_983; (S4*)_t2933->b + hr_ix(_i2933, _t2933->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:727"); })); 
int64_t e_986 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((want_984) >= (((int64_t)0LL))) && (((((*({ hrv *_t2934 = &(g568); int64_t _i2934 = want_984; (S1*)_t2934->b + hr_ix(_i2934, _t2934->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:729"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2935 = &(g568); int64_t _i2935 = want_984; (S1*)_t2935->b + hr_ix(_i2935, _t2935->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:729"); }))).k_) == (((uint8_t)9LL)))))) { e_986 = ((int64_t)(((*({ hrv *_t2936 = &(g568); int64_t _i2936 = want_984; (S1*)_t2936->b + hr_ix(_i2936, _t2936->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:729"); }))).a_));
 }
if ((((x_985).c_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_985).c_)), g580));
(void)(f140_conv(((int64_t)((x_985).c_)), g580));
if (((want_984) >= (((int64_t)0LL)))) { return f138_set_t(n_983, want_984);
 }
return f138_set_t(n_983, g594);
 }
if ((((x_985).a_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_985).a_)), e_986));
(void)(f137_ck(((int64_t)((x_985).b_)), g580));
if (((e_986) >= (((int64_t)0LL)))) { (void)(f140_conv(((int64_t)((x_985).a_)), e_986));
(void)(f140_conv(((int64_t)((x_985).b_)), g580));
if (((((*({ hrv *_t2945 = &(g568); int64_t _i2945 = want_984; (S1*)_t2945->b + hr_ix(_i2945, _t2945->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:731"); }))).k_) == (((uint8_t)9LL)))) { M78 _t2946 = f158_cval(((int64_t)((x_985).b_))); int64_t cnt_987 = _t2946.r0; bool u0_988 = _t2946.r1; bool ok_989 = _t2946.r2; 
(void)(f138_set_t(n_983, f123_t_arr(e_986, ((int64_t)1LL), cnt_987, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f145_set_cv(n_983, want_984));
return want_984;
 }
return f138_set_t(n_983, want_984);
 }
return f138_set_t(n_983, g594);
 }
{ int32_t _e2954 = (x_985).n_; for (int32_t _k2954 = 0; _k2954 < _e2954; _k2954++) { int32_t i_990 = (int32_t)_k2954; (void)(f137_ck(f90_kid(n_983, ((int64_t)(i_990))), e_986));
 } } _bk2953:; 
if (((e_986) >= (((int64_t)0LL)))) { { int32_t _e2958 = (x_985).n_; for (int32_t _k2958 = 0; _k2958 < _e2958; _k2958++) { int32_t i_991 = (int32_t)_k2958; (void)(f140_conv(f90_kid(n_983, ((int64_t)(i_991))), e_986));
 } } _bk2957:; 
if (((((*({ hrv *_t2961 = &(g568); int64_t _i2961 = want_984; (S1*)_t2961->b + hr_ix(_i2961, _t2961->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:735"); }))).k_) == (((uint8_t)9LL)))) { (void)(f138_set_t(n_983, f123_t_arr(e_986, ((int64_t)1LL), ((int64_t)((x_985).n_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f145_set_cv(n_983, want_984));
return want_984;
 }
return f138_set_t(n_983, want_984);
 }
return f138_set_t(n_983, g594);
}
static int64_t f196_ck_block(int64_t n_992, int64_t want_993) {
S4 x_994 = (*({ hrv *_t2967 = &(g721); int64_t _i2967 = n_992; (S4*)_t2967->b + hr_ix(_i2967, _t2967->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:500"); })); 
int64_t m_995 = (g403).n; 
int64_t nm0_996 = (g404).n; 
int64_t nf0_1032 = f197_pre_decl_block_fns(n_992); 
{ int32_t _e2970 = (x_994).n_; for (int32_t _k2970 = 0; _k2970 < _e2970; _k2970++) { int32_t i_1033 = (int32_t)_k2970; (void)(f204_cstmt(f90_kid(n_992, ((int64_t)(i_1033)))));
 } } _bk2969:; 
int64_t t_1120 = g575; 
if ((((x_994).a_) >= (((int32_t)0LL)))) { t_1120 = f137_ck(((int64_t)((x_994).a_)), want_993);
 }
(void)(f214_pop_block_fns(nf0_1032));
(void)(f181_narrow_pop(nm0_996));
(void)(({ hrv *_v2976 = &(g403); int64_t _k2976 = ((int64_t)((int64_t)(g403).n - (int64_t)m_995)); if (_k2976 < 0 || _k2976 > _v2976->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:509"); _v2976->n -= _k2976; }));
return f138_set_t(n_992, t_1120);
}
static int64_t f197_pre_decl_block_fns(int64_t b_997) {
int64_t m_998 = (g323).n; 
{ int32_t _e2979 = ((*({ hrv *_t2980 = &(g721); int64_t _i2980 = b_997; (S4*)_t2980->b + hr_ix(_i2980, _t2980->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); }))).n_; for (int32_t _k2979 = 0; _k2979 < _e2979; _k2979++) { int32_t q_999 = (int32_t)_k2979; int64_t c_1000 = f90_kid(b_997, ((int64_t)(q_999))); 
if (((((int64_t)(((*({ hrv *_t2982 = &(g721); int64_t _i2982 = c_1000; (S4*)_t2982->b + hr_ix(_i2982, _t2982->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); }))).k_))) == (((int64_t)50LL)))) { int64_t i_1001 = f105_new_inst(c_1000, c_1000, ((int64_t)((*({ hrv *_t2984 = &(g736); int64_t _i2984 = c_1000; (int32_t*)_t2984->b + hr_ix(_i2984, _t2984->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); })))), g414); 
(void)(({ hrv *_v2985 = &(g323); S14 _x2985 = ((S14){ .name_ = ((*({ hrv *_t2986 = &(g721); int64_t _i2986 = c_1000; (S4*)_t2986->b + hr_ix(_i2986, _t2986->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:32"); }))).s_, .node_ = ((int32_t)(c_1000)), .inst_ = ((int32_t)(i_1001)), .own_ = ((int32_t)(g414)), }); S14 *_p2985 = (S14*)hr_grow(_v2985, 1, sizeof _x2985); *_p2985 = _x2985; _p2985; }));
(void)(f198_sig_inst(i_1001));
 }
 } } _bk2978:; 
return m_998;
}
static void f198_sig_inst(int64_t i_1002) {
int64_t node_1003 = ((int64_t)(((*({ hrv *_t2988 = &(g401); int64_t _i2988 = i_1002; (S6*)_t2988->b + hr_ix(_i2988, _t2988->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:106"); }))).node_)); 
int64_t ns_1004 = f110_ns_of(node_1003); 
int64_t g0_1005 = (g508).n; 
{ int32_t _e2991 = ((*({ hrv *_t2992 = &(g401); int64_t _i2992 = i_1002; (S6*)_t2992->b + hr_ix(_i2992, _t2992->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:109"); }))).gn_; for (int32_t _k2991 = 0; _k2991 < _e2991; _k2991++) { int32_t j_1006 = (int32_t)_k2991; (void)(({ hrv *_v2993 = &(g508); S7 _x2993 = (*({ hrv *_t2994 = &(g407); int64_t _i2994 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2995 = &(g401); int64_t _i2995 = i_1002; (S6*)_t2995->b + hr_ix(_i2995, _t2995->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:109"); }))).g0_)) + (int64_t)((int64_t)(j_1006)))); (S7*)_t2994->b + hr_ix(_i2994, _t2994->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:109"); })); S7 *_p2993 = (S7*)hr_grow(_v2993, 1, sizeof _x2993); *_p2993 = _x2993; _p2993; }));
 } } _bk2990:; 
int64_t p0_1007 = (g569).n; 
L88 pts_1008 = ({ L88 _t2996; memset(&_t2996, 0, sizeof _t2996); _t2996.n = 0; _t2996; }); 
{ int32_t _e2998 = ((*({ hrv *_t2999 = &(g721); int64_t _i2999 = node_1003; (S4*)_t2999->b + hr_ix(_i2999, _t2999->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:112"); }))).n_; for (int32_t _k2998 = 0; _k2998 < _e2998; _k2998++) { int32_t j_1009 = (int32_t)_k2998; int64_t p_1010 = f90_kid(node_1003, ((int64_t)(j_1009))); 
int64_t t_1011 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((*({ hrv *_t3001 = &(g721); int64_t _i3001 = p_1010; (S4*)_t3001->b + hr_ix(_i3001, _t3001->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:115"); }))).a_) >= (((int32_t)0LL)))) { t_1011 = f113_rtype(((int64_t)(((*({ hrv *_t3003 = &(g721); int64_t _i3003 = p_1010; (S4*)_t3003->b + hr_ix(_i3003, _t3003->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:115"); }))).a_)), ns_1004);
 } else { t_1011 = f130_gb_find(f199_upname(p_1010));
if (((t_1011) < (((int64_t)0LL)))) { t_1011 = g592;
 }
 }
(void)(({ L88 *_v3006 = &(pts_1008); int32_t _x3006 = ((int32_t)(t_1011)); if (_v3006->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:116"); _v3006->e[_v3006->n] = _x3006; &_v3006->e[_v3006->n++]; }));
 } } _bk2997:; 
{ int32_t *_t3007 = &(((*({ hrv *_t3008 = &(g401); int64_t _i3008 = i_1002; (S6*)_t3008->b + hr_ix(_i3008, _t3008->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:118"); }))).p0_); *_t3007 = ((int32_t)((g569).n)); }
(void)(({ hrv *_v3009 = &(g569); hsl _s3009 = ({ hsl _t3010 = ({ L88 *_t3011 = &(pts_1008); (hsl){ (uint8_t*)_t3011->e, _t3011->n }; }); int64_t _l3010 = 0, _h3010 = _t3010.n; if (_l3010 < 0 || _h3010 < _l3010 || _h3010 > _t3010.n) hr_slerr(_l3010, _h3010, _t3010.n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:118"); (hsl){ _t3010.p + _l3010 * (int64_t)sizeof(int32_t), _h3010 - _l3010 }; }); hr_append(_v3009, _s3009.p, _s3009.n, sizeof(int32_t)); }));
{ int32_t *_t3012 = &(((*({ hrv *_t3013 = &(g401); int64_t _i3013 = i_1002; (S6*)_t3013->b + hr_ix(_i3013, _t3013->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:118"); }))).pn_); *_t3012 = ((int32_t)(((int64_t)(pts_1008).n))); }
if (((((*({ hrv *_t3014 = &(g721); int64_t _i3014 = node_1003; (S4*)_t3014->b + hr_ix(_i3014, _t3014->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:119"); }))).b_) >= (((int32_t)0LL)))) { int64_t rl_1014 = ((int64_t)(((*({ hrv *_t3015 = &(g721); int64_t _i3015 = node_1003; (S4*)_t3015->b + hr_ix(_i3015, _t3015->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:120"); }))).b_)); 
if (((((*({ hrv *_t3016 = &(g721); int64_t _i3016 = rl_1014; (S4*)_t3016->b + hr_ix(_i3016, _t3016->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:121"); }))).n_) == (((int32_t)1LL)))) { { int32_t *_t3017 = &(((*({ hrv *_t3018 = &(g401); int64_t _i3018 = i_1002; (S6*)_t3018->b + hr_ix(_i3018, _t3018->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:121"); }))).ret_); *_t3017 = ((int32_t)(f113_rtype(f90_kid(rl_1014, ((int64_t)0LL)), ns_1004))); }
 } else { L89 rs_1015 = ({ L89 _t3021; memset(&_t3021, 0, sizeof _t3021); _t3021.n = 0; _t3021; }); 
{ int32_t _e3023 = ((*({ hrv *_t3024 = &(g721); int64_t _i3024 = rl_1014; (S4*)_t3024->b + hr_ix(_i3024, _t3024->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); }))).n_; for (int32_t _k3023 = 0; _k3023 < _e3023; _k3023++) { int32_t j_1016 = (int32_t)_k3023; int64_t r0_1017 = f113_rtype(f90_kid(rl_1014, ((int64_t)(j_1016))), ns_1004); 
(void)(({ L89 *_v3027 = &(rs_1015); int32_t _x3027 = ((int32_t)(r0_1017)); if (_v3027->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); _v3027->e[_v3027->n] = _x3027; &_v3027->e[_v3027->n++]; }));
 } } _bk3022:; 
{ int32_t *_t3028 = &(((*({ hrv *_t3029 = &(g401); int64_t _i3029 = i_1002; (S6*)_t3029->b + hr_ix(_i3029, _t3029->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); }))).ret_); *_t3028 = ((int32_t)(f200_tlist(((int64_t)14LL), ({ hsl _t3031 = ({ L89 *_t3032 = &(rs_1015); (hsl){ (uint8_t*)_t3032->e, _t3032->n }; }); int64_t _l3031 = 0, _h3031 = _t3031.n; if (_l3031 < 0 || _h3031 < _l3031 || _h3031 > _t3031.n) hr_slerr(_l3031, _h3031, _t3031.n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:122"); (hsl){ _t3031.p + _l3031 * (int64_t)sizeof(int32_t), _h3031 - _l3031 }; }), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); }
 }
 } else { { int32_t *_t3033 = &(((*({ hrv *_t3034 = &(g401); int64_t _i3034 = i_1002; (S6*)_t3034->b + hr_ix(_i3034, _t3034->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).ret_); *_t3033 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
{ bool *_t3035 = &(((*({ hrv *_t3036 = &(g401); int64_t _i3036 = i_1002; (S6*)_t3036->b + hr_ix(_i3036, _t3036->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).rinf_); *_t3035 = true; }
if ((((((uint16_t)((uint64_t)((*({ hrv *_t3037 = &(g721); int64_t _i3037 = node_1003; (S4*)_t3037->b + hr_ix(_i3037, _t3037->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || f201_surely_void(node_1003))) { { int32_t *_t3039 = &(((*({ hrv *_t3040 = &(g401); int64_t _i3040 = i_1002; (S6*)_t3040->b + hr_ix(_i3040, _t3040->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).ret_); *_t3039 = ((int32_t)(g575)); }
{ bool *_t3041 = &(((*({ hrv *_t3042 = &(g401); int64_t _i3042 = i_1002; (S6*)_t3042->b + hr_ix(_i3042, _t3042->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:123"); }))).rinf_); *_t3041 = false; }
 }
 }
(void)(({ hrv *_v3043 = &(g508); int64_t _k3043 = ((int64_t)((int64_t)(g508).n - (int64_t)g0_1005)); if (_k3043 < 0 || _k3043 > _v3043->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:124"); _v3043->n -= _k3043; }));
}
static int64_t f199_upname(int64_t p_1012) {
hrv s_1013 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v3045 = &(s_1013); uint8_t _x3045 = ((uint8_t)36LL); uint8_t *_p3045 = (uint8_t*)hr_grow(_v3045, 1, sizeof _x3045); *_p3045 = _x3045; _p3045; }));
(void)(({ hrv *_v3046 = &(s_1013); hsl _s3046 = f10_nm(((int64_t)(((*({ hrv *_t3048 = &(g721); int64_t _i3048 = p_1012; (S4*)_t3048->b + hr_ix(_i3048, _t3048->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:60"); }))).s_))); hr_append(_v3046, _s3046.p, _s3046.n, sizeof(uint8_t)); }));
return f8_intern(hr_sl(s_1013));
}
static int64_t f200_tlist(int64_t k_1018, hsl xs_1019, int64_t a_1020) {
int64_t l_1021 = (g569).n; 
(void)(({ hrv *_v3050 = &(g569); hsl _s3050 = xs_1019; hr_append(_v3050, _s3050.p, _s3050.n, sizeof(int32_t)); }));
return f13_tmk(((S1){ .k_ = ((uint8_t)(k_1018)), .a_ = ((int32_t)(a_1020)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .l_ = ((int32_t)(l_1021)), .n_ = ((int32_t)((xs_1019).n)), }));
}
static bool f201_surely_void(int64_t fnode_1022) {
int64_t body_1023 = ((int64_t)(((*({ hrv *_t3052 = &(g721); int64_t _i3052 = fnode_1022; (S4*)_t3052->b + hr_ix(_i3052, _t3052->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:127"); }))).c_)); 
if (((body_1023) < (((int64_t)0LL)))) { return true;
 }
int64_t tl_1024 = ((int64_t)(((*({ hrv *_t3053 = &(g721); int64_t _i3053 = body_1023; (S4*)_t3053->b + hr_ix(_i3053, _t3053->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:129"); }))).a_)); 
return (f202_tail_void(tl_1024) && (!(f203_has_valret(body_1023))));
}
static bool f202_tail_void(int64_t tl_1025) {
if (((tl_1025) < (((int64_t)0LL)))) { return true;
 }
S4 x_1026 = (*({ hrv *_t3056 = &(g721); int64_t _i3056 = tl_1025; (S4*)_t3056->b + hr_ix(_i3056, _t3056->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:134"); })); 
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
S4 x_1029 = (*({ hrv *_t3060 = &(g721); int64_t _i3060 = n_1028; (S4*)_t3060->b + hr_ix(_i3060, _t3060->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:142"); })); 
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
if ((((((((((k_1030) == (((int64_t)23LL))) || ((k_1030) == (((int64_t)11LL)))) || ((k_1030) == (((int64_t)20LL)))) || ((k_1030) == (((int64_t)21LL)))) || ((k_1030) == (((int64_t)36LL)))) || ((k_1030) == (((int64_t)16LL)))) || ((k_1030) == (((int64_t)17LL)))) || ((k_1030) == (((int64_t)28LL))))) { { int32_t _e3067 = (x_1029).n_; for (int32_t _k3067 = 0; _k3067 < _e3067; _k3067++) { int32_t i_1031 = (int32_t)_k3067; if (f203_has_valret(f90_kid(n_1028, ((int64_t)(i_1031))))) { return true;
 }
 } } _bk3066:; 
 }
return false;
}
static void f204_cstmt(int64_t n_1034) {
S4 x_1035 = (*({ hrv *_t3070 = &(g721); int64_t _i3070 = n_1034; (S4*)_t3070->b + hr_ix(_i3070, _t3070->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:742"); })); 
int64_t k_1036 = ((int64_t)((x_1035).k_)); 
if (((k_1036) == (((int64_t)33LL)))) { (void)(f205_ck_vdecl(n_1034));
return;
 }
if (((k_1036) == (((int64_t)34LL)))) { (void)(f210_ck_assign(n_1034));
return;
 }
if (((k_1036) == (((int64_t)35LL)))) { int64_t t_1088 = f137_ck(((int64_t)((x_1035).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if ((((((*({ hrv *_t3074 = &(g568); int64_t _i3074 = f182_deref(t_1088); (S1*)_t3074->b + hr_ix(_i3074, _t3074->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:746"); }))).k_) != (((uint8_t)3LL))) && ((((*({ hrv *_t3076 = &(g568); int64_t _i3076 = f182_deref(t_1088); (S1*)_t3076->b + hr_ix(_i3076, _t3076->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:746"); }))).k_) != (((uint8_t)17LL))))) { (void)(f108_cerr(n_1034, hr_str("++/-- needs an integer", 22)));
 }
return;
 }
if (((k_1036) == (((int64_t)50LL)))) { (void)(f211_decl_nested(n_1034));
return;
 }
g494 = n_1034;
int64_t t_1119 = f137_ck(n_1034, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f166_is_pending(t_1119)) { (void)(f187_default_t(n_1034));
 }
}
static void f205_ck_vdecl(int64_t n_1037) {
S4 x_1038 = (*({ hrv *_t3083 = &(g721); int64_t _i3083 = n_1037; (S4*)_t3083->b + hr_ix(_i3083, _t3083->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:754"); })); 
int64_t fl_1039 = ((int64_t)((x_1038).fl_)); 
int64_t ns_1040 = f110_ns_of(n_1037); 
bool byref_1041 = ((((int64_t)((int64_t)fl_1039 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL))); 
int64_t dt_1042 = ({ int64_t _r3085; if ((((x_1038).a_) >= (((int32_t)0LL)))) { _r3085 = f113_rtype(((int64_t)((x_1038).a_)), ns_1040);  } else { _r3085 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3085; }); 
int64_t lf_1043 = ((int64_t)((int64_t)((int64_t)((int64_t)({ int64_t _r3087; if (((((int64_t)((int64_t)fl_1039 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)))) { _r3087 = ((int64_t)1LL);  } else { _r3087 = ((int64_t)0LL);  } _r3087; }) | (int64_t)({ int64_t _r3088; if (((((int64_t)((int64_t)fl_1039 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { _r3088 = ((int64_t)2LL);  } else { _r3088 = ((int64_t)0LL);  } _r3088; }))) | (int64_t)({ int64_t _r3089; if (byref_1041) { _r3089 = ((int64_t)8LL);  } else { _r3089 = ((int64_t)0LL);  } _r3089; }))); 
if ((((x_1038).n_) > (((int32_t)1LL)))) { if ((((x_1038).b_) < (((int32_t)0LL)))) { (void)(f108_cerr(n_1037, hr_str("several names need a call's results", 35)));
return;
 }
int64_t init_1044 = f90_kid(((int64_t)((x_1038).b_)), ((int64_t)0LL)); 
int64_t t_1045 = f137_ck(init_1044, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3093 = &(g568); int64_t _i3093 = t_1045; (S1*)_t3093->b + hr_ix(_i3093, _t3093->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:764"); }))).k_) != (((uint8_t)14LL)))) { if (((((int64_t)(((*({ hrv *_t3094 = &(g721); int64_t _i3094 = (x_1038).b_; (S4*)_t3094->b + hr_ix(_i3094, _t3094->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:764"); }))).n_))) == (((int64_t)((x_1038).n_))))) { { int32_t _e3096 = (x_1038).n_; for (int32_t _k3096 = ((int32_t)1LL); _k3096 < _e3096; _k3096++) { int32_t i_1046 = (int32_t)_k3096; int64_t iv_1047 = f90_kid(((int64_t)((x_1038).b_)), ((int64_t)(i_1046))); 
(void)(f137_ck(iv_1047, dt_1042));
if (((dt_1042) >= (((int64_t)0LL)))) { (void)(f140_conv(iv_1047, dt_1042));
 } else { (void)(f187_default_t(iv_1047));
 }
 } } _bk3095:; 
if (((dt_1042) >= (((int64_t)0LL)))) { (void)(f140_conv(init_1044, dt_1042));
 } else { (void)(f187_default_t(init_1044));
 }
{ int32_t _e3104 = (x_1038).n_; for (int32_t _k3104 = 0; _k3104 < _e3104; _k3104++) { int32_t i_1048 = (int32_t)_k3104; int64_t iv_1049 = f90_kid(((int64_t)((x_1038).b_)), ((int64_t)(i_1048))); 
int64_t v_1056 = f207_add_lv(((int64_t)((*({ hrv *_t3107 = &(g722); int64_t _i3107 = ((int64_t)((int64_t)((int64_t)((x_1038).l_)) + (int64_t)((int64_t)(i_1048)))); (int32_t*)_t3107->b + hr_ix(_i3107, _t3107->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:764"); })))), ({ int64_t _r3108; if (((dt_1042) >= (((int64_t)0LL)))) { _r3108 = dt_1042;  } else { _r3108 = f206_fin_t(iv_1049);  } _r3108; }), lf_1043, n_1037); 
if (((i_1048) == (((int32_t)0LL)))) { (void)(f173_set_r(n_1037, ((int64_t)1LL), v_1056));
 }
 } } _bk3103:; 
(void)(f178_set_x(n_1037, ((int64_t)1LL)));
return;
 }
(void)(f108_cerr(n_1037, hr_str("several names need a call with as many results", 46)));
return;
 }
if (((((*({ hrv *_t3113 = &(g568); int64_t _i3113 = t_1045; (S1*)_t3113->b + hr_ix(_i3113, _t3113->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:765"); }))).n_) != ((x_1038).n_))) { (void)(f108_cerr(n_1037, hr_str("result count does not match the names", 37)));
 }
{ int32_t _e3116 = (x_1038).n_; for (int32_t _k3116 = 0; _k3116 < _e3116; _k3116++) { int32_t i_1057 = (int32_t)_k3116; int64_t et_1058 = ({ int64_t _r3117; if (((((int64_t)(i_1057))) < (((int64_t)(((*({ hrv *_t3118 = &(g568); int64_t _i3118 = t_1045; (S1*)_t3118->b + hr_ix(_i3118, _t3118->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:766"); }))).n_))))) { _r3117 = ((int64_t)((*({ hrv *_t3119 = &(g569); int64_t _i3119 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3120 = &(g568); int64_t _i3120 = t_1045; (S1*)_t3120->b + hr_ix(_i3120, _t3120->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:766"); }))).l_)) + (int64_t)((int64_t)(i_1057)))); (int32_t*)_t3119->b + hr_ix(_i3119, _t3119->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:766"); }))));  } else { _r3117 = g592;  } _r3117; }); 
int64_t v_1059 = f207_add_lv(((int64_t)((*({ hrv *_t3122 = &(g722); int64_t _i3122 = ((int64_t)((int64_t)((int64_t)((x_1038).l_)) + (int64_t)((int64_t)(i_1057)))); (int32_t*)_t3122->b + hr_ix(_i3122, _t3122->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:766"); })))), et_1058, lf_1043, n_1037); 
if (((i_1057) == (((int32_t)0LL)))) { (void)(f173_set_r(n_1037, ((int64_t)1LL), v_1059));
 }
 } } _bk3115:; 
return;
 }
int64_t t_1060 = dt_1042; 
if ((((x_1038).b_) >= (((int32_t)0LL)))) { int64_t init_1061 = f90_kid(((int64_t)((x_1038).b_)), ((int64_t)0LL)); 
if (((((((dt_1042) < (((int64_t)0LL))) && ((((*({ hrv *_t3125 = &(g721); int64_t _i3125 = init_1061; (S4*)_t3125->b + hr_ix(_i3125, _t3125->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:772"); }))).k_) == (((uint8_t)16LL)))) && ((((*({ hrv *_t3126 = &(g721); int64_t _i3126 = init_1061; (S4*)_t3126->b + hr_ix(_i3126, _t3126->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:772"); }))).n_) == (((int32_t)0LL)))) && ((((*({ hrv *_t3127 = &(g721); int64_t _i3127 = init_1061; (S4*)_t3127->b + hr_ix(_i3127, _t3127->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:772"); }))).a_) < (((int32_t)0LL)))) && ((((*({ hrv *_t3128 = &(g721); int64_t _i3128 = init_1061; (S4*)_t3128->b + hr_ix(_i3128, _t3128->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:772"); }))).c_) < (((int32_t)0LL))))) { t_1060 = f123_t_arr(g592, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
(void)(f138_set_t(init_1061, t_1060));
 } else { int64_t it_1062 = f137_ck(init_1061, dt_1042); 
if (((dt_1042) >= (((int64_t)0LL)))) { if (byref_1041) { if ((!(((((*({ hrv *_t3132 = &(g568); int64_t _i3132 = dt_1042; (S1*)_t3132->b + hr_ix(_i3132, _t3132->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:777"); }))).k_) == (((uint8_t)10LL)))))) { (void)(f140_conv(init_1061, dt_1042));
 }
 } else { (void)(f140_conv(init_1061, dt_1042));
 }
 } else { if ((((((*({ hrv *_t3135 = &(g568); int64_t _i3135 = it_1062; (S1*)_t3135->b + hr_ix(_i3135, _t3135->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:779"); }))).k_) == (((uint8_t)13LL))) && ((((int64_t)((int64_t)lf_1043 & (int64_t)((int64_t)((int64_t)((int64_t)1LL) | (int64_t)((int64_t)8LL)))))) == (((int64_t)0LL))))) { lf_1043 = ((int64_t)((int64_t)lf_1043 | (int64_t)((int64_t)64LL)));
 }
t_1060 = f187_default_t(init_1061);
if (((((*({ hrv *_t3137 = &(g568); int64_t _i3137 = t_1060; (S1*)_t3137->b + hr_ix(_i3137, _t3137->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:781"); }))).k_) == (((uint8_t)14LL)))) { t_1060 = ((int64_t)((*({ hrv *_t3138 = &(g569); int64_t _i3138 = ((*({ hrv *_t3139 = &(g568); int64_t _i3139 = t_1060; (S1*)_t3139->b + hr_ix(_i3139, _t3139->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:781"); }))).l_; (int32_t*)_t3138->b + hr_ix(_i3138, _t3138->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:781"); }))));
 }
if (((((((*({ hrv *_t3140 = &(g568); int64_t _i3140 = t_1060; (S1*)_t3140->b + hr_ix(_i3140, _t3140->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:782"); }))).k_) == (((uint8_t)7LL))) && (((((*({ hrv *_t3141 = &(g721); int64_t _i3141 = init_1061; (S4*)_t3141->b + hr_ix(_i3141, _t3141->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:782"); }))).k_) == (((uint8_t)14LL))) || ((((*({ hrv *_t3142 = &(g721); int64_t _i3142 = init_1061; (S4*)_t3142->b + hr_ix(_i3142, _t3142->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:782"); }))).k_) == (((uint8_t)17LL))))) && ((((int64_t)((int64_t)lf_1043 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL))))) { t_1060 = f136_t_enum(((int64_t)(((*({ hrv *_t3144 = &(g568); int64_t _i3144 = t_1060; (S1*)_t3144->b + hr_ix(_i3144, _t3144->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:782"); }))).a_)), false);
(void)(f145_set_cv(init_1061, t_1060));
 }
if ((byref_1041 || (((((*({ hrv *_t3146 = &(g721); int64_t _i3146 = init_1061; (S4*)_t3146->b + hr_ix(_i3146, _t3146->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:783"); }))).k_) == (((uint8_t)10LL))) && ((((int64_t)(((*({ hrv *_t3147 = &(g721); int64_t _i3147 = init_1061; (S4*)_t3147->b + hr_ix(_i3147, _t3147->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:783"); }))).op_))) == (((int64_t)49LL)))))) { if (((((*({ hrv *_t3148 = &(g568); int64_t _i3148 = t_1060; (S1*)_t3148->b + hr_ix(_i3148, _t3148->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:783"); }))).k_) != (((uint8_t)10LL)))) { t_1060 = f119_t_ref(t_1060, ((int64_t)0LL));
 }
 } else { if (((((((((*({ hrv *_t3150 = &(g568); int64_t _i3150 = t_1060; (S1*)_t3150->b + hr_ix(_i3150, _t3150->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:784"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t3151 = &(g568); int64_t _i3151 = t_1060; (S1*)_t3151->b + hr_ix(_i3151, _t3151->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:784"); }))).c_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t3152 = &(g568); int64_t _i3152 = t_1060; (S1*)_t3152->b + hr_ix(_i3152, _t3152->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:784"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))) && f208_is_fixed(((int64_t)(((*({ hrv *_t3154 = &(g568); int64_t _i3154 = t_1060; (S1*)_t3154->b + hr_ix(_i3154, _t3154->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:784"); }))).a_)))) && (!(f209_has_rel(((int64_t)(((*({ hrv *_t3156 = &(g568); int64_t _i3156 = t_1060; (S1*)_t3156->b + hr_ix(_i3156, _t3156->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:784"); }))).a_))))))) { t_1060 = ((int64_t)(((*({ hrv *_t3157 = &(g568); int64_t _i3157 = t_1060; (S1*)_t3157->b + hr_ix(_i3157, _t3157->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:784"); }))).a_));
(void)(f145_set_cv(init_1061, t_1060));
 }
 }
 }
 }
 } else { if (((t_1060) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1037, hr_str("a declaration needs a type or an initializer", 44)));
t_1060 = g592;
 }
 }
if ((byref_1041 && ((((*({ hrv *_t3160 = &(g568); int64_t _i3160 = t_1060; (S1*)_t3160->b + hr_ix(_i3160, _t3160->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:790"); }))).k_) != (((uint8_t)10LL))))) { t_1060 = f119_t_ref(t_1060, ((int64_t)0LL));
 }
int64_t v_1071 = f207_add_lv(((int64_t)((*({ hrv *_t3163 = &(g722); int64_t _i3163 = (x_1038).l_; (int32_t*)_t3163->b + hr_ix(_i3163, _t3163->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:791"); })))), t_1060, lf_1043, n_1037); 
(void)(f173_set_r(n_1037, ((int64_t)1LL), v_1071));
}
static int64_t f206_fin_t(int64_t n_1050) {
int64_t c_1051 = f153_cv(n_1050); 
return ({ int64_t _r3166; if (((c_1051) >= (((int64_t)0LL)))) { _r3166 = c_1051;  } else { _r3166 = f141_at(n_1050);  } _r3166; });
}
static int64_t f207_add_lv(int64_t name_1052, int64_t t_1053, int64_t fl_1054, int64_t node_1055) {
(void)(({ hrv *_v3168 = &(g402); S12 _x3168 = ((S12){ .name_ = ((int32_t)(name_1052)), .ty_ = ((int32_t)(t_1053)), .fl_ = ((uint16_t)(fl_1054)), .cfn_ = ((int32_t)(g415)), .own_ = ((int32_t)(g414)), .node_ = ((int32_t)(node_1055)), .cnt_ = ((int32_t)0LL), }); S12 *_p3168 = (S12*)hr_grow(_v3168, 1, sizeof _x3168); *_p3168 = _x3168; _p3168; }));
(void)(({ hrv *_v3169 = &(g403); int32_t _x3169 = ((int32_t)(((int64_t)((int64_t)(g402).n - (int64_t)((int64_t)1LL))))); int32_t *_p3169 = (int32_t*)hr_grow(_v3169, 1, sizeof _x3169); *_p3169 = _x3169; _p3169; }));
return ((int64_t)((int64_t)(g402).n - (int64_t)((int64_t)1LL)));
}
static bool f208_is_fixed(int64_t t_1063) {
return ((f146_tclass(t_1063)) == (((int64_t)0LL)));
}
static bool f209_has_rel(int64_t t_1064) {
if (((t_1064) < (((int64_t)0LL)))) { return false;
 }
while ((((g471).n) < ((g568).n))) { (void)(({ hrv *_v3172 = &(g471); int8_t _x3172 = ((int8_t)(0 - (uint64_t)(((int8_t)1LL)))); int8_t *_p3172 = (int8_t*)hr_grow(_v3172, 1, sizeof _x3172); *_p3172 = _x3172; _p3172; }));
 } _bk3171:; 
if ((((*({ hrv *_t3173 = &(g471); int64_t _i3173 = t_1064; (int8_t*)_t3173->b + hr_ix(_i3173, _t3173->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:417"); }))) >= (((int8_t)0LL)))) { return (((*({ hrv *_t3174 = &(g471); int64_t _i3174 = t_1064; (int8_t*)_t3174->b + hr_ix(_i3174, _t3174->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:417"); }))) == (((int8_t)1LL)));
 }
{ int8_t *_t3175 = &((*({ hrv *_t3176 = &(g471); int64_t _i3176 = t_1064; (int8_t*)_t3176->b + hr_ix(_i3176, _t3176->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:418"); }))); *_t3175 = ((int8_t)0LL); }
S1 x_1065 = (*({ hrv *_t3177 = &(g568); int64_t _i3177 = t_1064; (S1*)_t3177->b + hr_ix(_i3177, _t3177->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:419"); })); 
int64_t k_1066 = ((int64_t)((x_1065).k_)); 
bool r_1067 = false; 
if (((k_1066) == (((int64_t)5LL)))) { int64_t si_1068 = ((int64_t)((x_1065).a_)); 
{ int32_t _e3179 = ((*({ hrv *_t3180 = &(g571); int64_t _i3180 = si_1068; (S10*)_t3180->b + hr_ix(_i3180, _t3180->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:421"); }))).fnum_; for (int32_t _k3179 = 0; _k3179 < _e3179; _k3179++) { int32_t i_1069 = (int32_t)_k3179; int64_t ft_1070 = ((int64_t)(((*({ hrv *_t3181 = &(g572); int64_t _i3181 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3182 = &(g571); int64_t _i3182 = si_1068; (S10*)_t3182->b + hr_ix(_i3182, _t3182->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:421"); }))).f0_)) + (int64_t)((int64_t)(i_1069)))); (S11*)_t3181->b + hr_ix(_i3181, _t3181->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:421"); }))).ty_)); 
if ((((ft_1070) >= (((int64_t)0LL))) && ((((((*({ hrv *_t3183 = &(g568); int64_t _i3183 = ft_1070; (S1*)_t3183->b + hr_ix(_i3183, _t3183->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:421"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t3184 = &(g568); int64_t _i3184 = ft_1070; (S1*)_t3184->b + hr_ix(_i3184, _t3184->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:421"); }))).c_) >= (((int32_t)0LL)))) || f209_has_rel(ft_1070)))) { r_1067 = true;
 }
 } } _bk3178:; 
 }
if ((((k_1066) == (((int64_t)8LL))) && ((((int64_t)((x_1065).s_))) == (((int64_t)1LL))))) { r_1067 = f209_has_rel(((int64_t)((x_1065).a_)));
 }
while ((((g471).n) < ((g568).n))) { (void)(({ hrv *_v3188 = &(g471); int8_t _x3188 = ((int8_t)(0 - (uint64_t)(((int8_t)1LL)))); int8_t *_p3188 = (int8_t*)hr_grow(_v3188, 1, sizeof _x3188); *_p3188 = _x3188; _p3188; }));
 } _bk3187:; 
{ int8_t *_t3189 = &((*({ hrv *_t3190 = &(g471); int64_t _i3190 = t_1064; (int8_t*)_t3190->b + hr_ix(_i3190, _t3190->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:424"); }))); *_t3189 = ({ int8_t _r3191; if (r_1067) { _r3191 = ((int8_t)1LL);  } else { _r3191 = ((int8_t)0LL);  } _r3191; }); }
return r_1067;
}
static void f210_ck_assign(int64_t n_1072) {
S4 x_1073 = (*({ hrv *_t3192 = &(g721); int64_t _i3192 = n_1072; (S4*)_t3192->b + hr_ix(_i3192, _t3192->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:795"); })); 
int64_t o_1074 = ((int64_t)((x_1073).op_)); 
if (((o_1074) == (((int64_t)11LL)))) { int64_t t_1075 = f137_ck(((int64_t)((x_1073).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t tl_1076 = ((int64_t)((x_1073).a_)); 
{ int32_t _e3195 = ((*({ hrv *_t3196 = &(g721); int64_t _i3196 = tl_1076; (S4*)_t3196->b + hr_ix(_i3196, _t3196->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:800"); }))).n_; for (int32_t _k3195 = 0; _k3195 < _e3195; _k3195++) { int32_t i_1077 = (int32_t)_k3195; int64_t tg_1078 = f90_kid(tl_1076, ((int64_t)(i_1077))); 
int64_t tt_1079 = f137_ck(tg_1078, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
 } } _bk3194:; 
return;
 }
if (((o_1074) == (((int64_t)18LL)))) { int64_t tt_1080 = f137_ck(((int64_t)((x_1073).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t rt_1081 = f137_ck(((int64_t)((x_1073).b_)), tt_1080); 
if (f166_is_pending(rt_1081)) { if ((((((*({ hrv *_t3202 = &(g568); int64_t _i3202 = rt_1081; (S1*)_t3202->b + hr_ix(_i3202, _t3202->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:807"); }))).k_) == (((uint8_t)11LL))) && ((((*({ hrv *_t3203 = &(g568); int64_t _i3203 = tt_1080; (S1*)_t3203->b + hr_ix(_i3203, _t3203->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:807"); }))).k_) == (((uint8_t)10LL))))) { (void)(f138_set_t(((int64_t)((x_1073).b_)), f119_t_ref(((int64_t)(((*({ hrv *_t3206 = &(g568); int64_t _i3206 = tt_1080; (S1*)_t3206->b + hr_ix(_i3206, _t3206->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:807"); }))).a_)), ((int64_t)2LL))));
 } else { (void)(f187_default_t(((int64_t)((x_1073).b_))));
 }
 }
if ((((((*({ hrv *_t3208 = &(g721); int64_t _i3208 = (x_1073).a_; (S4*)_t3208->b + hr_ix(_i3208, _t3208->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:810"); }))).k_) == (((uint8_t)8LL))) && ((f159_rk(((int64_t)((x_1073).a_)))) == (((int64_t)1LL))))) { int64_t v_1082 = f160_rv(((int64_t)((x_1073).a_))); 
if ((f168_is_opt(f141_at(((int64_t)((x_1073).b_)))) || ((((*({ hrv *_t3213 = &(g568); int64_t _i3213 = f141_at(((int64_t)((x_1073).b_))); (S1*)_t3213->b + hr_ix(_i3213, _t3213->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:812"); }))).k_) == (((uint8_t)11LL))))) { { int32_t *_t3215 = &(((*({ hrv *_t3216 = &(g402); int64_t _i3216 = v_1082; (S12*)_t3216->b + hr_ix(_i3216, _t3216->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:813"); }))).ty_); *_t3215 = ((int32_t)(f119_t_ref(((int64_t)(((*({ hrv *_t3218 = &(g568); int64_t _i3218 = ((*({ hrv *_t3219 = &(g402); int64_t _i3219 = v_1082; (S12*)_t3219->b + hr_ix(_i3219, _t3219->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:813"); }))).ty_; (S1*)_t3218->b + hr_ix(_i3218, _t3218->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:813"); }))).a_)), ((int64_t)2LL)))); }
 }
 }
return;
 }
int64_t tt_1083 = f137_ck(((int64_t)((x_1073).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t d_1084 = f182_deref(tt_1083); 
if (((o_1074) == (((int64_t)36LL)))) { if ((((((*({ hrv *_t3222 = &(g568); int64_t _i3222 = tt_1083; (S1*)_t3222->b + hr_ix(_i3222, _t3222->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:821"); }))).k_) == (((uint8_t)10LL))) && f168_is_opt(tt_1083))) { int64_t rt_1085 = f137_ck(((int64_t)((x_1073).b_)), tt_1083); 
if (((((*({ hrv *_t3225 = &(g568); int64_t _i3225 = rt_1085; (S1*)_t3225->b + hr_ix(_i3225, _t3225->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:823"); }))).k_) == (((uint8_t)11LL)))) { (void)(f165_commit(((int64_t)((x_1073).b_)), tt_1083));
return;
 }
if (((((*({ hrv *_t3227 = &(g568); int64_t _i3227 = rt_1085; (S1*)_t3227->b + hr_ix(_i3227, _t3227->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:824"); }))).k_) == (((uint8_t)10LL)))) { (void)(f140_conv(((int64_t)((x_1073).b_)), tt_1083));
return;
 }
 }
(void)(f137_ck(((int64_t)((x_1073).b_)), d_1084));
(void)(f140_conv(((int64_t)((x_1073).b_)), d_1084));
return;
 }
int64_t lk_1086 = f183_leaf_kind(d_1084); 
int64_t rt_1087 = f137_ck(((int64_t)((x_1073).b_)), ({ int64_t _r3233; if ((((((lk_1086) >= (((int64_t)4LL))) && (((o_1074) == (((int64_t)28LL))) || ((o_1074) == (((int64_t)29LL))))) || ((o_1074) == (((int64_t)45LL)))) || ((o_1074) == (((int64_t)46LL))))) { _r3233 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r3233 = d_1084;  } _r3233; })); 
if (((((lk_1086) >= (((int64_t)4LL))) && (((o_1074) == (((int64_t)28LL))) || ((o_1074) == (((int64_t)29LL))))) && ((f182_deref(rt_1087)) != (d_1084)))) { (void)(f140_conv(((int64_t)((x_1073).b_)), f184_leaf_type(d_1084)));
return;
 }
if ((((o_1074) == (((int64_t)45LL))) || ((o_1074) == (((int64_t)46LL))))) { if (f166_is_pending(rt_1087)) { (void)(f140_conv(((int64_t)((x_1073).b_)), g580));
 }
return;
 }
(void)(f140_conv(((int64_t)((x_1073).b_)), d_1084));
}
static void f211_decl_nested(int64_t n_1089) {
int64_t i_1090 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v3241 = &(g323); for (int64_t _k3241 = 0; _k3241 < _v3241->n; _k3241++) { S14 f_1091 = ((S14*)_v3241->b)[_k3241]; if ((((((int64_t)((f_1091).node_))) == (n_1089)) && ((((int64_t)((f_1091).own_))) == (g414)))) { i_1090 = ((int64_t)((f_1091).inst_));
 }
 } } _bk3240:; 
if (((i_1090) < (((int64_t)0LL)))) { i_1090 = f105_new_inst(n_1089, n_1089, ((int64_t)((*({ hrv *_t3243 = &(g736); int64_t _i3243 = n_1089; (int32_t*)_t3243->b + hr_ix(_i3243, _t3243->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:27"); })))), g414);
(void)(({ hrv *_v3244 = &(g323); S14 _x3244 = ((S14){ .name_ = ((*({ hrv *_t3245 = &(g721); int64_t _i3245 = n_1089; (S4*)_t3245->b + hr_ix(_i3245, _t3245->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:27"); }))).s_, .node_ = ((int32_t)(n_1089)), .inst_ = ((int32_t)(i_1090)), .own_ = ((int32_t)(g414)), }); S14 *_p3244 = (S14*)hr_grow(_v3244, 1, sizeof _x3244); *_p3244 = _x3244; _p3244; }));
(void)(f198_sig_inst(i_1090));
 }
(void)(f212_check_inst(i_1090));
}
static void f212_check_inst(int64_t i_1092) {
if (((((*({ hrv *_t3248 = &(g401); int64_t _i3248 = i_1092; (S6*)_t3248->b + hr_ix(_i3248, _t3248->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:153"); }))).st_) != (((uint8_t)0LL)))) { return;
 }
int64_t node_1093 = ((int64_t)(((*({ hrv *_t3249 = &(g401); int64_t _i3249 = i_1092; (S6*)_t3249->b + hr_ix(_i3249, _t3249->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:154"); }))).node_)); 
{ uint8_t *_t3250 = &(((*({ hrv *_t3251 = &(g401); int64_t _i3251 = i_1092; (S6*)_t3251->b + hr_ix(_i3251, _t3251->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:155"); }))).st_); *_t3250 = ((uint8_t)1LL); }
if (((((uint16_t)((uint64_t)((*({ hrv *_t3252 = &(g721); int64_t _i3252 = node_1093; (S4*)_t3252->b + hr_ix(_i3252, _t3252->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:156"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { int64_t sa0_1094 = g414; 
int64_t sc0_1095 = g415; 
g414 = i_1092;
g415 = i_1092;
{ int32_t _e3254 = ((*({ hrv *_t3255 = &(g721); int64_t _i3255 = node_1093; (S4*)_t3255->b + hr_ix(_i3255, _t3255->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:156"); }))).n_; for (int32_t _k3254 = 0; _k3254 < _e3254; _k3254++) { int32_t j_1096 = (int32_t)_k3254; int64_t p_1097 = f90_kid(node_1093, ((int64_t)(j_1096))); 
if (((((*({ hrv *_t3257 = &(g721); int64_t _i3257 = p_1097; (S4*)_t3257->b + hr_ix(_i3257, _t3257->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:156"); }))).b_) >= (((int32_t)0LL)))) { int64_t pt_1100 = f213_ptype_of(i_1092, ((int64_t)(j_1096))); 
(void)(f137_ck(((int64_t)(((*({ hrv *_t3260 = &(g721); int64_t _i3260 = p_1097; (S4*)_t3260->b + hr_ix(_i3260, _t3260->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:156"); }))).b_)), pt_1100));
(void)(f140_conv(((int64_t)(((*({ hrv *_t3262 = &(g721); int64_t _i3262 = p_1097; (S4*)_t3262->b + hr_ix(_i3262, _t3262->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:156"); }))).b_)), pt_1100));
 }
 } } _bk3253:; 
g414 = sa0_1094;
g415 = sc0_1095;
{ uint8_t *_t3263 = &(((*({ hrv *_t3264 = &(g401); int64_t _i3264 = i_1092; (S6*)_t3264->b + hr_ix(_i3264, _t3264->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:156"); }))).st_); *_t3263 = ((uint8_t)2LL); }
return;
 }
int64_t sa_1101 = g414; 
int64_t sc_1102 = g415; 
int64_t sm_1103 = (g403).n; 
int64_t ld_1104 = g420; 
int64_t bt_1105 = (g484).n; 
int64_t nm0_1106 = (g323).n; 
g414 = i_1092;
g415 = i_1092;
g420 = ((int64_t)0LL);
int64_t g0_1107 = (g508).n; 
{ int32_t _e3266 = ((*({ hrv *_t3267 = &(g401); int64_t _i3267 = i_1092; (S6*)_t3267->b + hr_ix(_i3267, _t3267->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:160"); }))).gn_; for (int32_t _k3266 = 0; _k3266 < _e3266; _k3266++) { int32_t j_1108 = (int32_t)_k3266; (void)(({ hrv *_v3268 = &(g508); S7 _x3268 = (*({ hrv *_t3269 = &(g407); int64_t _i3269 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3270 = &(g401); int64_t _i3270 = i_1092; (S6*)_t3270->b + hr_ix(_i3270, _t3270->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:160"); }))).g0_)) + (int64_t)((int64_t)(j_1108)))); (S7*)_t3269->b + hr_ix(_i3269, _t3269->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:160"); })); S7 *_p3268 = (S7*)hr_grow(_v3268, 1, sizeof _x3268); *_p3268 = _x3268; _p3268; }));
 } } _bk3265:; 
{ int32_t _e3272 = ((*({ hrv *_t3273 = &(g721); int64_t _i3273 = node_1093; (S4*)_t3273->b + hr_ix(_i3273, _t3273->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:161"); }))).n_; for (int32_t _k3272 = 0; _k3272 < _e3272; _k3272++) { int32_t j_1109 = (int32_t)_k3272; int64_t p_1110 = f90_kid(node_1093, ((int64_t)(j_1109))); 
if (((((*({ hrv *_t3275 = &(g721); int64_t _i3275 = p_1110; (S4*)_t3275->b + hr_ix(_i3275, _t3275->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:161"); }))).b_) >= (((int32_t)0LL)))) { int64_t pt_1111 = f213_ptype_of(i_1092, ((int64_t)(j_1109))); 
(void)(f137_ck(((int64_t)(((*({ hrv *_t3278 = &(g721); int64_t _i3278 = p_1110; (S4*)_t3278->b + hr_ix(_i3278, _t3278->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:161"); }))).b_)), pt_1111));
(void)(f140_conv(((int64_t)(((*({ hrv *_t3280 = &(g721); int64_t _i3280 = p_1110; (S4*)_t3280->b + hr_ix(_i3280, _t3280->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:161"); }))).b_)), pt_1111));
 }
 } } _bk3271:; 
{ int32_t _e3282 = ((*({ hrv *_t3283 = &(g721); int64_t _i3283 = node_1093; (S4*)_t3283->b + hr_ix(_i3283, _t3283->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:162"); }))).n_; for (int32_t _k3282 = 0; _k3282 < _e3282; _k3282++) { int32_t j_1112 = (int32_t)_k3282; int64_t p_1113 = f90_kid(node_1093, ((int64_t)(j_1112))); 
int64_t v_1114 = f207_add_lv(((int64_t)(((*({ hrv *_t3286 = &(g721); int64_t _i3286 = p_1113; (S4*)_t3286->b + hr_ix(_i3286, _t3286->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:162"); }))).s_)), f213_ptype_of(i_1092, ((int64_t)(j_1112))), ((int64_t)((int64_t)((int64_t)4LL) | (int64_t)({ int64_t _r3288; if (((((uint16_t)((uint64_t)((*({ hrv *_t3289 = &(g721); int64_t _i3289 = p_1113; (S4*)_t3289->b + hr_ix(_i3289, _t3289->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:162"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { _r3288 = ((int64_t)1LL);  } else { _r3288 = ((int64_t)0LL);  } _r3288; }))), p_1113); 
(void)(f173_set_r(p_1113, ((int64_t)1LL), v_1114));
 } } _bk3281:; 
int64_t body_1115 = ((int64_t)(((*({ hrv *_t3291 = &(g721); int64_t _i3291 = node_1093; (S4*)_t3291->b + hr_ix(_i3291, _t3291->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:163"); }))).c_)); 
int64_t rt_1116 = ((int64_t)(((*({ hrv *_t3292 = &(g401); int64_t _i3292 = i_1092; (S6*)_t3292->b + hr_ix(_i3292, _t3292->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:164"); }))).ret_)); 
int64_t t_1117 = f137_ck(body_1115, ({ int64_t _r3294; if (((rt_1116) >= (((int64_t)0LL)))) { _r3294 = rt_1116;  } else { _r3294 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3294; })); 
int64_t tail_1118 = ((int64_t)(((*({ hrv *_t3295 = &(g721); int64_t _i3295 = body_1115; (S4*)_t3295->b + hr_ix(_i3295, _t3295->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:166"); }))).a_)); 
if (((rt_1116) >= (((int64_t)0LL)))) { if ((((((tail_1118) >= (((int64_t)0LL))) && ((rt_1116) != (g575))) && ((t_1117) != (g575))) && (!(f143_ends(tail_1118))))) { (void)(f140_conv(tail_1118, rt_1116));
 }
 } else { if (((((*({ hrv *_t3298 = &(g401); int64_t _i3298 = i_1092; (S6*)_t3298->b + hr_ix(_i3298, _t3298->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:169"); }))).ret_) < (((int32_t)0LL)))) { if ((((tail_1118) >= (((int64_t)0LL))) && ((t_1117) != (g575)))) { { int32_t *_t3299 = &(((*({ hrv *_t3300 = &(g401); int64_t _i3300 = i_1092; (S6*)_t3300->b + hr_ix(_i3300, _t3300->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:169"); }))).ret_); *_t3299 = ((int32_t)(f187_default_t(tail_1118))); }
 } else { { int32_t *_t3302 = &(((*({ hrv *_t3303 = &(g401); int64_t _i3303 = i_1092; (S6*)_t3303->b + hr_ix(_i3303, _t3303->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:169"); }))).ret_); *_t3302 = ((int32_t)(g575)); }
 }
 } else { if (((((tail_1118) >= (((int64_t)0LL))) && ((t_1117) != (g575))) && ((((int64_t)(((*({ hrv *_t3304 = &(g401); int64_t _i3304 = i_1092; (S6*)_t3304->b + hr_ix(_i3304, _t3304->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:170"); }))).ret_))) != (g575)))) { (void)(f140_conv(tail_1118, ((int64_t)(((*({ hrv *_t3306 = &(g401); int64_t _i3306 = i_1092; (S6*)_t3306->b + hr_ix(_i3306, _t3306->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:170"); }))).ret_))));
 }
 }
 }
(void)(({ hrv *_v3307 = &(g508); int64_t _k3307 = ((int64_t)((int64_t)(g508).n - (int64_t)g0_1107)); if (_k3307 < 0 || _k3307 > _v3307->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:172"); _v3307->n -= _k3307; }));
(void)(({ hrv *_v3308 = &(g403); int64_t _k3308 = ((int64_t)((int64_t)(g403).n - (int64_t)sm_1103)); if (_k3308 < 0 || _k3308 > _v3308->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); _v3308->n -= _k3308; }));
(void)(({ hrv *_v3309 = &(g323); int64_t _k3309 = ((int64_t)((int64_t)(g323).n - (int64_t)nm0_1106)); if (_k3309 < 0 || _k3309 > _v3309->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:173"); _v3309->n -= _k3309; }));
while ((((g484).n) > (bt_1105))) { (void)(({ hrv *_v3311 = &(g484); if (!_v3311->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:174"); ((int32_t*)_v3311->b)[--_v3311->n]; }));
 } _bk3310:; 
g414 = sa_1101;
g415 = sc_1102;
g420 = ld_1104;
{ uint8_t *_t3312 = &(((*({ hrv *_t3313 = &(g401); int64_t _i3313 = i_1092; (S6*)_t3313->b + hr_ix(_i3313, _t3313->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:176"); }))).st_); *_t3312 = ((uint8_t)2LL); }
}
static int64_t f213_ptype_of(int64_t i_1098, int64_t j_1099) {
return ((int64_t)((*({ hrv *_t3314 = &(g569); int64_t _i3314 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3315 = &(g401); int64_t _i3315 = i_1098; (S6*)_t3315->b + hr_ix(_i3315, _t3315->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:151"); }))).p0_)) + (int64_t)j_1099)); (int32_t*)_t3314->b + hr_ix(_i3314, _t3314->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:151"); }))));
}
static void f214_pop_block_fns(int64_t m_1121) {
if ((((g323).n) > (m_1121))) { (void)(({ hrv *_v3316 = &(g323); int64_t _k3316 = ((int64_t)((int64_t)(g323).n - (int64_t)m_1121)); if (_k3316 < 0 || _k3316 > _v3316->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:35"); _v3316->n -= _k3316; }));
 }
}
static int64_t f215_ck_if(int64_t n_1124, int64_t want_1125) {
S4 x_1126 = (*({ hrv *_t3317 = &(g721); int64_t _i3317 = n_1124; (S4*)_t3317->b + hr_ix(_i3317, _t3317->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:541"); })); 
int64_t c_1127 = f137_ck(((int64_t)((x_1126).a_)), g576); 
(void)(f140_conv(((int64_t)((x_1126).a_)), g576));
int64_t m_1128 = (g403).n; 
int64_t nm0_1129 = (g404).n; 
(void)(f180_narrow_push(((int64_t)((x_1126).a_))));
int64_t tb_1130 = f137_ck(((int64_t)((x_1126).b_)), want_1125); 
(void)(f181_narrow_pop(nm0_1129));
(void)(({ hrv *_v3323 = &(g403); int64_t _k3323 = ((int64_t)((int64_t)(g403).n - (int64_t)m_1128)); if (_k3323 < 0 || _k3323 > _v3323->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:549"); _v3323->n -= _k3323; }));
if ((((x_1126).c_) < (((int32_t)0LL)))) { return f138_set_t(n_1124, g575);
 }
int64_t tc_1131 = f137_ck(((int64_t)((x_1126).c_)), want_1125); 
bool eb_1132 = f143_ends(((int64_t)((x_1126).b_))); 
bool ec_1133 = f143_ends(((int64_t)((x_1126).c_))); 
if ((eb_1132 && (!(ec_1133)))) { return f138_set_t(n_1124, tc_1131);
 }
if ((ec_1133 && (!(eb_1132)))) { return f138_set_t(n_1124, tb_1130);
 }
if ((eb_1132 && ec_1133)) { return f138_set_t(n_1124, tb_1130);
 }
if ((((tb_1130) == (g575)) || ((tc_1131) == (g575)))) { return f138_set_t(n_1124, g575);
 }
if (((tb_1130) == (tc_1131))) { return f138_set_t(n_1124, tb_1130);
 }
if ((((((want_1125) >= (((int64_t)0LL))) && ((want_1125) != (g575))) && (f166_is_pending(tb_1130) || f154_conv_ok(tb_1130, want_1125, ((int64_t)((x_1126).b_))))) && (f166_is_pending(tc_1131) || f154_conv_ok(tc_1131, want_1125, ((int64_t)((x_1126).c_)))))) { (void)(f140_conv(((int64_t)((x_1126).b_)), want_1125));
(void)(f140_conv(((int64_t)((x_1126).c_)), want_1125));
return f138_set_t(n_1124, want_1125);
 }
int64_t u_1134 = f185_unify(n_1124, ((int64_t)((x_1126).b_)), ((int64_t)((x_1126).c_))); 
return f138_set_t(n_1124, u_1134);
}
static int64_t f216_ck_while(int64_t n_1135) {
S4 x_1136 = (*({ hrv *_t3342 = &(g721); int64_t _i3342 = n_1135; (S4*)_t3342->b + hr_ix(_i3342, _t3342->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:563"); })); 
int64_t c_1137 = f137_ck(((int64_t)((x_1136).a_)), g576); 
(void)(f140_conv(((int64_t)((x_1136).a_)), g576));
int64_t nm0_1138 = (g404).n; 
(void)(f180_narrow_push(((int64_t)((x_1136).a_))));
g420++;
(void)(f137_ck(((int64_t)((x_1136).b_)), g575));
g420--;
(void)(f181_narrow_pop(nm0_1138));
return f138_set_t(n_1135, g575);
}
static int64_t f217_ck_loop(int64_t n_1139, int64_t want_1140) {
(void)(({ hrv *_v3349 = &(g484); int32_t _x3349 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p3349 = (int32_t*)hr_grow(_v3349, 1, sizeof _x3349); *_p3349 = _x3349; _p3349; }));
g420++;
(void)(f137_ck(((int64_t)(((*({ hrv *_t3351 = &(g721); int64_t _i3351 = n_1139; (S4*)_t3351->b + hr_ix(_i3351, _t3351->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:578"); }))).a_)), g575));
g420--;
int64_t t_1141 = ((int64_t)(({ hrv *_v3352 = &(g484); if (!_v3352->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:580"); ((int32_t*)_v3352->b)[--_v3352->n]; }))); 
return f138_set_t(n_1139, ({ int64_t _r3354; if (((t_1141) < (((int64_t)0LL)))) { _r3354 = g575;  } else { _r3354 = t_1141;  } _r3354; }));
}
static int64_t f218_ck_for(int64_t n_1142) {
S4 x_1143 = (*({ hrv *_t3355 = &(g721); int64_t _i3355 = n_1142; (S4*)_t3355->b + hr_ix(_i3355, _t3355->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:584"); })); 
int64_t m_1144 = (g403).n; 
int64_t et_1145 = g580; 
if ((((x_1143).b_) >= (((int32_t)0LL)))) { int64_t ta_1146 = f137_ck(((int64_t)((x_1143).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t tb_1147 = f137_ck(((int64_t)((x_1143).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t u_1148 = f185_unify(n_1142, ((int64_t)((x_1143).a_)), ((int64_t)((x_1143).b_))); 
et_1145 = ({ int64_t _r3359; if (((((*({ hrv *_t3360 = &(g568); int64_t _i3360 = u_1148; (S1*)_t3360->b + hr_ix(_i3360, _t3360->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:590"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1143).a_)), g580));
(void)(f140_conv(((int64_t)((x_1143).b_)), g580));
_r3359 = g580;  } else { _r3359 = u_1148;  } _r3359; });
(void)(f178_set_x(n_1142, ((int64_t)0LL)));
 } else { int64_t t_1149 = f137_ck(((int64_t)((x_1143).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3365 = &(g568); int64_t _i3365 = t_1149; (S1*)_t3365->b + hr_ix(_i3365, _t3365->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:594"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_1143).a_)), g593));
t_1149 = g593;
 }
if (((((*({ hrv *_t3367 = &(g568); int64_t _i3367 = t_1149; (S1*)_t3367->b + hr_ix(_i3367, _t3367->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:595"); }))).k_) == (((uint8_t)19LL)))) { t_1149 = f187_default_t(((int64_t)((x_1143).a_)));
 }
int64_t d_1150 = f182_deref(t_1149); 
if (((((*({ hrv *_t3370 = &(g568); int64_t _i3370 = d_1150; (S1*)_t3370->b + hr_ix(_i3370, _t3370->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:597"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1143).a_)), g580));
et_1145 = g580;
(void)(f178_set_x(n_1142, ((int64_t)0LL)));
 } else { if ((((((*({ hrv *_t3373 = &(g568); int64_t _i3373 = d_1150; (S1*)_t3373->b + hr_ix(_i3373, _t3373->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:598"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t3374 = &(g568); int64_t _i3374 = d_1150; (S1*)_t3374->b + hr_ix(_i3374, _t3374->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:598"); }))).k_) == (((uint8_t)17LL))))) { et_1145 = ({ int64_t _r3375; if (((((*({ hrv *_t3376 = &(g568); int64_t _i3376 = d_1150; (S1*)_t3376->b + hr_ix(_i3376, _t3376->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:598"); }))).k_) == (((uint8_t)17LL)))) { _r3375 = g580;  } else { _r3375 = d_1150;  } _r3375; });
if (((et_1145) != (t_1149))) { (void)(f145_set_cv(((int64_t)((x_1143).a_)), et_1145));
 }
(void)(f178_set_x(n_1142, ((int64_t)0LL)));
 } else { if ((((((*({ hrv *_t3379 = &(g568); int64_t _i3379 = d_1150; (S1*)_t3379->b + hr_ix(_i3379, _t3379->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:599"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3380 = &(g568); int64_t _i3380 = d_1150; (S1*)_t3380->b + hr_ix(_i3380, _t3380->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:599"); }))).k_) == (((uint8_t)9LL))))) { et_1145 = f191_decode_rel(((int64_t)(((*({ hrv *_t3382 = &(g568); int64_t _i3382 = d_1150; (S1*)_t3382->b + hr_ix(_i3382, _t3382->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:599"); }))).a_)));
(void)(f178_set_x(n_1142, ((int64_t)1LL)));
 } else { hrv mm_1151 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t3386 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o3385 = &(mm_1151); hr_fs(_o3385, hr_str("cannot iterate over ", 20)); hr_fs(_o3385, hr_sl(*hr_tmp(&_t3386, f164_tn(d_1150)))); }));
}
(void)(f108_cerr(n_1142, hr_sl(mm_1151)));
 }
 }
 }
 }
if ((((x_1143).l_) >= (((int32_t)0LL)))) { et_1145 = f113_rtype(((int64_t)((x_1143).l_)), f110_ns_of(n_1142));
 }
bool byref_1153 = (((((uint16_t)((uint64_t)(x_1143).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || f219_is_bytes(et_1145)); 
int64_t v_1154 = f207_add_lv(((int64_t)((x_1143).s_)), ({ int64_t _r3393; if (byref_1153) { _r3393 = f119_t_ref(et_1145, ((int64_t)0LL));  } else { _r3393 = et_1145;  } _r3393; }), ((int64_t)((int64_t)((int64_t)16LL) | (int64_t)({ int64_t _r3395; if (byref_1153) { _r3395 = ((int64_t)8LL);  } else { _r3395 = ((int64_t)0LL);  } _r3395; }))), n_1142); 
(void)(f173_set_r(n_1142, ((int64_t)1LL), v_1154));
if ((((x_1143).c_) >= (((int32_t)0LL)))) { int64_t iv_1155 = f207_add_lv(((int64_t)((x_1143).c_)), ({ int64_t _r3398; if ((((x_1143).n_) >= (((int32_t)0LL)))) { _r3398 = f113_rtype(((int64_t)((x_1143).n_)), f110_ns_of(n_1142));  } else { _r3398 = g580;  } _r3398; }), ((int64_t)16LL), n_1142); 
(void)(f178_set_x(n_1142, ((int64_t)((int64_t)f220_ax(n_1142) | (int64_t)((int64_t)((iv_1155) << ((((int64_t)2LL)) & 63)))))));
 }
g420++;
(void)(f137_ck(((int64_t)((x_1143).d_)), g575));
g420--;
(void)(({ hrv *_v3404 = &(g403); int64_t _k3404 = ((int64_t)((int64_t)(g403).n - (int64_t)m_1144)); if (_k3404 < 0 || _k3404 > _v3404->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:610"); _v3404->n -= _k3404; }));
return f138_set_t(n_1142, g575);
}
static bool f219_is_bytes(int64_t t_1152) {
return ((((f146_tclass(t_1152)) == (((int64_t)1LL))) && ((((*({ hrv *_t3407 = &(g568); int64_t _i3407 = t_1152; (S1*)_t3407->b + hr_ix(_i3407, _t3407->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:93"); }))).k_) != (((uint8_t)17LL)))) && ((((*({ hrv *_t3408 = &(g568); int64_t _i3408 = t_1152; (S1*)_t3408->b + hr_ix(_i3408, _t3408->n, "/home/anmire/ai/amni-lang/helium-self/hc/types.amni:93"); }))).k_) != (((uint8_t)10LL))));
}
static int64_t f220_ax(int64_t n_1156) {
return ((int64_t)((*({ hrv *_t3409 = &(g412); int64_t _i3409 = f139_aix(n_1156); (int32_t*)_t3409->b + hr_ix(_i3409, _t3409->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:47"); }))));
}
static int64_t f221_ck_match(int64_t n_1157, int64_t want_1158) {
S4 x_1159 = (*({ hrv *_t3411 = &(g721); int64_t _i3411 = n_1157; (S4*)_t3411->b + hr_ix(_i3411, _t3411->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:614"); })); 
int64_t st_1160 = f137_ck(((int64_t)((x_1159).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3413 = &(g568); int64_t _i3413 = st_1160; (S1*)_t3413->b + hr_ix(_i3413, _t3413->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:616"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1159).a_)), g580));
st_1160 = g580;
 }
if (((((*({ hrv *_t3415 = &(g568); int64_t _i3415 = st_1160; (S1*)_t3415->b + hr_ix(_i3415, _t3415->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:617"); }))).k_) == (((uint8_t)7LL)))) { st_1160 = f136_t_enum(((int64_t)(((*({ hrv *_t3417 = &(g568); int64_t _i3417 = st_1160; (S1*)_t3417->b + hr_ix(_i3417, _t3417->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:617"); }))).a_)), false);
(void)(f145_set_cv(((int64_t)((x_1159).a_)), st_1160));
 }
int64_t d_1161 = f182_deref(st_1160); 
int64_t rt_1162 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
bool allv_1163 = true; 
{ int32_t _e3421 = (x_1159).n_; for (int32_t _k3421 = 0; _k3421 < _e3421; _k3421++) { int32_t i_1164 = (int32_t)_k3421; int64_t arm_1165 = f90_kid(n_1157, ((int64_t)(i_1164))); 
int64_t m_1166 = (g403).n; 
S4 ax0_1167 = (*({ hrv *_t3423 = &(g721); int64_t _i3423 = arm_1165; (S4*)_t3423->b + hr_ix(_i3423, _t3423->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:624"); })); 
if (((((uint16_t)((uint64_t)(ax0_1167).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) { { int32_t _e3425 = (ax0_1167).n_; for (int32_t _k3425 = 0; _k3425 < _e3425; _k3425++) { int32_t j_1168 = (int32_t)_k3425; int64_t it_1169 = f90_kid(arm_1165, ((int64_t)(j_1168))); 
int64_t lo_1170 = ((int64_t)(((*({ hrv *_t3427 = &(g721); int64_t _i3427 = it_1169; (S4*)_t3427->b + hr_ix(_i3427, _t3427->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:628"); }))).a_)); 
if ((((((*({ hrv *_t3428 = &(g568); int64_t _i3428 = d_1161; (S1*)_t3428->b + hr_ix(_i3428, _t3428->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:629"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t3429 = &(g721); int64_t _i3429 = lo_1170; (S4*)_t3429->b + hr_ix(_i3429, _t3429->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:629"); }))).k_) == (((uint8_t)8LL))))) { int64_t ei_1171 = ((int64_t)(((*({ hrv *_t3430 = &(g568); int64_t _i3430 = d_1161; (S1*)_t3430->b + hr_ix(_i3430, _t3430->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:630"); }))).a_)); 
int64_t found_1172 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e3432 = ((*({ hrv *_t3433 = &(g573); int64_t _i3433 = ei_1171; (S8*)_t3433->b + hr_ix(_i3433, _t3433->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:632"); }))).vnum_; for (int32_t _k3432 = 0; _k3432 < _e3432; _k3432++) { int32_t q_1173 = (int32_t)_k3432; if (((((*({ hrv *_t3434 = &(g574); int64_t _i3434 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3435 = &(g573); int64_t _i3435 = ei_1171; (S8*)_t3435->b + hr_ix(_i3435, _t3435->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:632"); }))).v0_)) + (int64_t)((int64_t)(q_1173)))); (S9*)_t3434->b + hr_ix(_i3434, _t3434->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:632"); }))).name_) == (((*({ hrv *_t3436 = &(g721); int64_t _i3436 = lo_1170; (S4*)_t3436->b + hr_ix(_i3436, _t3436->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:632"); }))).s_))) { found_1172 = ((int64_t)(q_1173));
 }
 } } _bk3431:; 
if (((found_1172) < (((int64_t)0LL)))) { hrv mm_1174 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t3441 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o3438 = &(mm_1174); hr_fs(_o3438, hr_str("no variant ", 11)); hr_fs(_o3438, f10_nm(((int64_t)(((*({ hrv *_t3440 = &(g721); int64_t _i3440 = lo_1170; (S4*)_t3440->b + hr_ix(_i3440, _t3440->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:633"); }))).s_)))); hr_fs(_o3438, hr_str(" in ", 4)); hr_fs(_o3438, hr_sl(*hr_tmp(&_t3441, f164_tn(d_1161)))); }));
}
(void)(f108_cerr(lo_1170, hr_sl(mm_1174)));
 }
(void)(f173_set_r(lo_1170, ((int64_t)7LL), found_1172));
(void)(f138_set_t(lo_1170, d_1161));
if (((((ax0_1167).s_) >= (((int32_t)0LL))) && ((found_1172) >= (((int64_t)0LL))))) { int64_t vt_1175 = f125_t_variant(ei_1171, found_1172); 
bool byr_1176 = (((((uint16_t)((uint64_t)(ax0_1167).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))) || f219_is_bytes(vt_1175)); 
int64_t v_1177 = f207_add_lv(((int64_t)((ax0_1167).s_)), ({ int64_t _r3449; if (byr_1176) { _r3449 = f119_t_ref(vt_1175, ((int64_t)0LL));  } else { _r3449 = vt_1175;  } _r3449; }), ({ int64_t _r3451; if (byr_1176) { _r3451 = ((int64_t)8LL);  } else { _r3451 = ((int64_t)0LL);  } _r3451; }), arm_1165); 
(void)(f173_set_r(arm_1165, ((int64_t)1LL), v_1177));
 }
 } else { (void)(f137_ck(lo_1170, d_1161));
(void)(f140_conv(lo_1170, d_1161));
if (((((*({ hrv *_t3455 = &(g721); int64_t _i3455 = it_1169; (S4*)_t3455->b + hr_ix(_i3455, _t3455->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:638"); }))).b_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)(((*({ hrv *_t3457 = &(g721); int64_t _i3457 = it_1169; (S4*)_t3457->b + hr_ix(_i3457, _t3457->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:638"); }))).b_)), d_1161));
(void)(f140_conv(((int64_t)(((*({ hrv *_t3459 = &(g721); int64_t _i3459 = it_1169; (S4*)_t3459->b + hr_ix(_i3459, _t3459->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:638"); }))).b_)), d_1161));
 }
 }
 } } _bk3424:; 
 }
int64_t bt_1178 = f137_ck(((int64_t)((ax0_1167).b_)), want_1158); 
(void)(({ hrv *_v3461 = &(g403); int64_t _k3461 = ((int64_t)((int64_t)(g403).n - (int64_t)m_1166)); if (_k3461 < 0 || _k3461 > _v3461->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:643"); _v3461->n -= _k3461; }));
if (((bt_1178) == (g575))) { allv_1163 = false;
 } else { if ((!(f143_ends(((int64_t)((ax0_1167).b_)))))) { if ((((rt_1162) < (((int64_t)0LL))) || f166_is_pending(rt_1162))) { rt_1162 = bt_1178;
 }
 }
 }
 } } _bk3420:; 
if (((!(allv_1163)) || ((rt_1162) < (((int64_t)0LL))))) { return f138_set_t(n_1157, g575);
 }
bool allw_1179 = (((want_1158) >= (((int64_t)0LL))) && ((want_1158) != (g575))); 
if (allw_1179) { { int32_t _e3466 = (x_1159).n_; for (int32_t _k3466 = 0; _k3466 < _e3466; _k3466++) { int32_t i_1180 = (int32_t)_k3466; int64_t b_1181 = ((int64_t)(((*({ hrv *_t3467 = &(g721); int64_t _i3467 = f90_kid(n_1157, ((int64_t)(i_1180))); (S4*)_t3467->b + hr_ix(_i3467, _t3467->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:648"); }))).b_)); 
int64_t bt_1182 = f141_at(b_1181); 
if ((((!(f143_ends(b_1181))) && (!(f166_is_pending(bt_1182)))) && (!(f154_conv_ok(bt_1182, want_1158, b_1181))))) { allw_1179 = false;
 }
 } } _bk3465:; 
 }
if (allw_1179) { { int32_t _e3474 = (x_1159).n_; for (int32_t _k3474 = 0; _k3474 < _e3474; _k3474++) { int32_t i_1183 = (int32_t)_k3474; int64_t b_1184 = ((int64_t)(((*({ hrv *_t3475 = &(g721); int64_t _i3475 = f90_kid(n_1157, ((int64_t)(i_1183))); (S4*)_t3475->b + hr_ix(_i3475, _t3475->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:649"); }))).b_)); 
if ((!(f143_ends(b_1184)))) { (void)(f140_conv(b_1184, want_1158));
 }
 } } _bk3473:; 
return f138_set_t(n_1157, want_1158);
 }
if (f166_is_pending(rt_1162)) { { int32_t _e3482 = (x_1159).n_; for (int32_t _k3482 = 0; _k3482 < _e3482; _k3482++) { int32_t i_1185 = (int32_t)_k3482; int64_t b_1186 = ((int64_t)(((*({ hrv *_t3483 = &(g721); int64_t _i3483 = f90_kid(n_1157, ((int64_t)(i_1185))); (S4*)_t3483->b + hr_ix(_i3483, _t3483->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:650"); }))).b_)); 
int64_t bt_1187 = f141_at(b_1186); 
if (((!(f166_is_pending(bt_1187))) && (!(f143_ends(b_1186))))) { rt_1162 = bt_1187;
 }
 } } _bk3481:; 
 }
if (f166_is_pending(rt_1162)) { int64_t b_1188 = ((int64_t)(((*({ hrv *_t3489 = &(g721); int64_t _i3489 = f90_kid(n_1157, ((int64_t)0LL)); (S4*)_t3489->b + hr_ix(_i3489, _t3489->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:651"); }))).b_)); 
rt_1162 = f187_default_t(b_1188);
 }
{ int32_t _e3493 = (x_1159).n_; for (int32_t _k3493 = 0; _k3493 < _e3493; _k3493++) { int32_t i_1189 = (int32_t)_k3493; int64_t b_1190 = ((int64_t)(((*({ hrv *_t3494 = &(g721); int64_t _i3494 = f90_kid(n_1157, ((int64_t)(i_1189))); (S4*)_t3494->b + hr_ix(_i3494, _t3494->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:652"); }))).b_)); 
if ((!(f143_ends(b_1190)))) { (void)(f140_conv(b_1190, rt_1162));
 }
 } } _bk3492:; 
return f138_set_t(n_1157, rt_1162);
}
static int64_t f222_ck_ret(int64_t n_1191) {
S4 x_1192 = (*({ hrv *_t3499 = &(g721); int64_t _i3499 = n_1191; (S4*)_t3499->b + hr_ix(_i3499, _t3499->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:664"); })); 
int64_t f_1196 = ({ int64_t _r3500; if ((((x_1192).s_) >= (((int32_t)0LL)))) { _r3500 = f223_find_from_fn(((int64_t)((x_1192).s_)));  } else { _r3500 = f224_ret_fn();  } _r3500; }); 
if (((f_1196) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1191, hr_str("return outside a function", 25)));
return g575;
 }
if (((f_1196) != (g415))) { { bool *_t3504 = &(((*({ hrv *_t3505 = &(g401); int64_t _i3505 = g415; (S6*)_t3505->b + hr_ix(_i3505, _t3505->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:667"); }))).lr_); *_t3504 = true; }
{ bool *_t3506 = &(((*({ hrv *_t3507 = &(g401); int64_t _i3507 = f_1196; (S6*)_t3507->b + hr_ix(_i3507, _t3507->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:667"); }))).tg_); *_t3506 = true; }
(void)(f178_set_x(n_1191, f_1196));
 } else { (void)(f178_set_x(n_1191, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
int64_t rt_1197 = ((int64_t)(((*({ hrv *_t3510 = &(g401); int64_t _i3510 = f_1196; (S6*)_t3510->b + hr_ix(_i3510, _t3510->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:668"); }))).ret_)); 
if ((((x_1192).n_) == (((int32_t)0LL)))) { if (((((rt_1197) >= (((int64_t)0LL))) && ((rt_1197) != (g575))) && (!(((*({ hrv *_t3511 = &(g401); int64_t _i3511 = f_1196; (S6*)_t3511->b + hr_ix(_i3511, _t3511->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:669"); }))).rinf_)))) { (void)(f108_cerr(n_1191, hr_str("return needs a value", 20)));
 }
if (((rt_1197) < (((int64_t)0LL)))) { { int32_t *_t3513 = &(((*({ hrv *_t3514 = &(g401); int64_t _i3514 = f_1196; (S6*)_t3514->b + hr_ix(_i3514, _t3514->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:669"); }))).ret_); *_t3513 = ((int32_t)(g575)); }
 }
return f138_set_t(n_1191, g575);
 }
if (((((rt_1197) >= (((int64_t)0LL))) && ((((*({ hrv *_t3516 = &(g568); int64_t _i3516 = rt_1197; (S1*)_t3516->b + hr_ix(_i3516, _t3516->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:670"); }))).k_) == (((uint8_t)14LL)))) && (((x_1192).n_) == (((int32_t)1LL))))) { int64_t c_1198 = f90_kid(n_1191, ((int64_t)0LL)); 
(void)(f137_ck(c_1198, rt_1197));
return f138_set_t(n_1191, g575);
 }
if ((((x_1192).n_) > (((int32_t)1LL)))) { if (((rt_1197) < (((int64_t)0LL)))) { L89 ts_1199 = ({ L89 _t3520; memset(&_t3520, 0, sizeof _t3520); _t3520.n = 0; _t3520; }); 
{ int32_t _e3522 = (x_1192).n_; for (int32_t _k3522 = 0; _k3522 < _e3522; _k3522++) { int32_t i_1200 = (int32_t)_k3522; (void)(f137_ck(f90_kid(n_1191, ((int64_t)(i_1200))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
int64_t dt0_1201 = f187_default_t(f90_kid(n_1191, ((int64_t)(i_1200)))); 
(void)(({ L89 *_v3527 = &(ts_1199); int32_t _x3527 = ((int32_t)(dt0_1201)); if (_v3527->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:672"); _v3527->e[_v3527->n] = _x3527; &_v3527->e[_v3527->n++]; }));
 } } _bk3521:; 
{ int32_t *_t3528 = &(((*({ hrv *_t3529 = &(g401); int64_t _i3529 = f_1196; (S6*)_t3529->b + hr_ix(_i3529, _t3529->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:672"); }))).ret_); *_t3528 = ((int32_t)(f200_tlist(((int64_t)14LL), ({ hsl _t3531 = ({ L89 *_t3532 = &(ts_1199); (hsl){ (uint8_t*)_t3532->e, _t3532->n }; }); int64_t _l3531 = 0, _h3531 = _t3531.n; if (_l3531 < 0 || _h3531 < _l3531 || _h3531 > _t3531.n) hr_slerr(_l3531, _h3531, _t3531.n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:672"); (hsl){ _t3531.p + _l3531 * (int64_t)sizeof(int32_t), _h3531 - _l3531 }; }), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); }
return f138_set_t(n_1191, g575);
 }
{ int32_t _e3535 = (x_1192).n_; for (int32_t _k3535 = 0; _k3535 < _e3535; _k3535++) { int32_t i_1202 = (int32_t)_k3535; int64_t et_1203 = ({ int64_t _r3536; if ((((((*({ hrv *_t3537 = &(g568); int64_t _i3537 = rt_1197; (S1*)_t3537->b + hr_ix(_i3537, _t3537->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:673"); }))).k_) == (((uint8_t)14LL))) && ((((int64_t)(i_1202))) < (((int64_t)(((*({ hrv *_t3538 = &(g568); int64_t _i3538 = rt_1197; (S1*)_t3538->b + hr_ix(_i3538, _t3538->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:673"); }))).n_)))))) { _r3536 = ((int64_t)((*({ hrv *_t3539 = &(g569); int64_t _i3539 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3540 = &(g568); int64_t _i3540 = rt_1197; (S1*)_t3540->b + hr_ix(_i3540, _t3540->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:673"); }))).l_)) + (int64_t)((int64_t)(i_1202)))); (int32_t*)_t3539->b + hr_ix(_i3539, _t3539->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:673"); }))));  } else { _r3536 = g592;  } _r3536; }); 
(void)(f137_ck(f90_kid(n_1191, ((int64_t)(i_1202))), et_1203));
(void)(f140_conv(f90_kid(n_1191, ((int64_t)(i_1202))), et_1203));
 } } _bk3534:; 
return f138_set_t(n_1191, g575);
 }
int64_t c_1204 = f90_kid(n_1191, ((int64_t)0LL)); 
if (((rt_1197) < (((int64_t)0LL)))) { (void)(f137_ck(c_1204, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
int64_t t_1205 = f187_default_t(c_1204); 
{ int32_t *_t3549 = &(((*({ hrv *_t3550 = &(g401); int64_t _i3550 = f_1196; (S6*)_t3550->b + hr_ix(_i3550, _t3550->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:677"); }))).ret_); *_t3549 = ((int32_t)(t_1205)); }
return f138_set_t(n_1191, g575);
 }
(void)(f137_ck(c_1204, rt_1197));
(void)(f140_conv(c_1204, rt_1197));
return f138_set_t(n_1191, g575);
}
static int64_t f223_find_from_fn(int64_t name_1193) {
int64_t i_1194 = g414; 
while (((i_1194) >= (((int64_t)0LL)))) { if (((((((*({ hrv *_t3556 = &(g401); int64_t _i3556 = i_1194; (S6*)_t3556->b + hr_ix(_i3556, _t3556->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:658"); }))).node_) >= (((int32_t)0LL))) && ((((*({ hrv *_t3557 = &(g721); int64_t _i3557 = ((*({ hrv *_t3558 = &(g401); int64_t _i3558 = i_1194; (S6*)_t3558->b + hr_ix(_i3558, _t3558->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:658"); }))).node_; (S4*)_t3557->b + hr_ix(_i3557, _t3557->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:658"); }))).k_) == (((uint8_t)50LL)))) && ((((int64_t)(((*({ hrv *_t3559 = &(g401); int64_t _i3559 = i_1194; (S6*)_t3559->b + hr_ix(_i3559, _t3559->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:658"); }))).name_))) == (name_1193)))) { return i_1194;
 }
i_1194 = ({ int64_t _r3560; if (((((*({ hrv *_t3561 = &(g401); int64_t _i3561 = i_1194; (S6*)_t3561->b + hr_ix(_i3561, _t3561->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:659"); }))).bown_) >= (((int32_t)0LL)))) { _r3560 = ((int64_t)(((*({ hrv *_t3562 = &(g401); int64_t _i3562 = i_1194; (S6*)_t3562->b + hr_ix(_i3562, _t3562->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:659"); }))).bown_));  } else { _r3560 = ((int64_t)(((*({ hrv *_t3563 = &(g401); int64_t _i3563 = i_1194; (S6*)_t3563->b + hr_ix(_i3563, _t3563->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:659"); }))).par_));  } _r3560; });
 } _bk3555:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f224_ret_fn(void) {
int64_t i_1195 = g414; 
while (((i_1195) >= (((int64_t)0LL)))) { if ((((((*({ hrv *_t3565 = &(g401); int64_t _i3565 = i_1195; (S6*)_t3565->b + hr_ix(_i3565, _t3565->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:681"); }))).node_) >= (((int32_t)0LL))) && ((((*({ hrv *_t3566 = &(g721); int64_t _i3566 = ((*({ hrv *_t3567 = &(g401); int64_t _i3567 = i_1195; (S6*)_t3567->b + hr_ix(_i3567, _t3567->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:681"); }))).node_; (S4*)_t3566->b + hr_ix(_i3566, _t3566->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:681"); }))).k_) == (((uint8_t)50LL))))) { return i_1195;
 }
i_1195 = ((int64_t)(((*({ hrv *_t3568 = &(g401); int64_t _i3568 = i_1195; (S6*)_t3568->b + hr_ix(_i3568, _t3568->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:681"); }))).par_));
 } _bk3564:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f225_ck_break(int64_t n_1206) {
S4 x_1207 = (*({ hrv *_t3569 = &(g721); int64_t _i3569 = n_1206; (S4*)_t3569->b + hr_ix(_i3569, _t3569->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:683"); })); 
if ((((x_1207).a_) >= (((int32_t)0LL)))) { if ((((g484).n) == (((int64_t)0LL)))) { (void)(f108_cerr(n_1206, hr_str("break with a value outside loop or block", 40)));
return g575;
 }
int64_t w_1208 = ((int64_t)((*({ hrv *_t3571 = &(g484); int64_t _i3571 = ((int64_t)((int64_t)(g484).n - (int64_t)((int64_t)1LL))); (int32_t*)_t3571->b + hr_ix(_i3571, _t3571->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:686"); })))); 
int64_t t_1209 = f137_ck(((int64_t)((x_1207).a_)), ({ int64_t _r3573; if (((w_1208) >= (((int64_t)0LL)))) { _r3573 = w_1208;  } else { _r3573 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3573; })); 
if (((w_1208) < (((int64_t)0LL)))) { { int32_t *_t3574 = &((*({ hrv *_t3575 = &(g484); int64_t _i3575 = ((int64_t)((int64_t)(g484).n - (int64_t)((int64_t)1LL))); (int32_t*)_t3575->b + hr_ix(_i3575, _t3575->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:688"); }))); *_t3574 = ((int32_t)(f187_default_t(((int64_t)((x_1207).a_))))); }
 } else { (void)(f140_conv(((int64_t)((x_1207).a_)), w_1208));
 }
 }
return f138_set_t(n_1206, g575);
}
static int64_t f226_ck_call(int64_t n_1210, int64_t want_1211) {
S4 x_1212 = (*({ hrv *_t3579 = &(g721); int64_t _i3579 = n_1210; (S4*)_t3579->b + hr_ix(_i3579, _t3579->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:263"); })); 
int64_t cal_1213 = ((int64_t)((x_1212).a_)); 
int64_t ck__1214 = ((int64_t)(((*({ hrv *_t3580 = &(g721); int64_t _i3580 = cal_1213; (S4*)_t3580->b + hr_ix(_i3580, _t3580->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:265"); }))).k_)); 
if (((ck__1214) == (((int64_t)8LL)))) { int64_t name_1215 = ((int64_t)(((*({ hrv *_t3581 = &(g721); int64_t _i3581 = cal_1213; (S4*)_t3581->b + hr_ix(_i3581, _t3581->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:267"); }))).s_)); 
int64_t v_1216 = f170_find_lv(name_1215); 
int64_t nf_1219 = f227_find_nest(name_1215); 
if ((((v_1216) < (((int64_t)0LL))) && ((nf_1219) >= (((int64_t)0LL))))) { return f228_call_nested(n_1210, nf_1219);
 }
if (((v_1216) < (((int64_t)0LL)))) { int64_t bg_1256 = f233_block_binding(name_1215); 
if (((bg_1256) >= (((int64_t)0LL)))) { return f238_call_block(n_1210, bg_1256);
 }
int64_t b_1287 = f240_builtin_of(f10_nm(name_1215)); 
if (((((b_1287) >= (((int64_t)0LL))) && (!((((b_1287) == (((int64_t)3LL))) && f241_user_format(n_1210))))) && (!((((b_1287) == (((int64_t)9LL))) && false))))) { return f243_ck_builtin(n_1210, b_1287, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), want_1211);
 }
return f257_call_fn(n_1210, name_1215, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), want_1211);
 }
 }
if (((ck__1214) == (((int64_t)14LL)))) { int64_t obj_1468 = ((int64_t)(((*({ hrv *_t3592 = &(g721); int64_t _i3592 = cal_1213; (S4*)_t3592->b + hr_ix(_i3592, _t3592->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:280"); }))).a_)); 
int64_t name_1469 = ((int64_t)(((*({ hrv *_t3593 = &(g721); int64_t _i3593 = cal_1213; (S4*)_t3593->b + hr_ix(_i3593, _t3593->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:281"); }))).s_)); 
if ((((((((*({ hrv *_t3594 = &(g721); int64_t _i3594 = obj_1468; (S4*)_t3594->b + hr_ix(_i3594, _t3594->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:282"); }))).k_) == (((uint8_t)8LL))) && ((f170_find_lv(((int64_t)(((*({ hrv *_t3596 = &(g721); int64_t _i3596 = obj_1468; (S4*)_t3596->b + hr_ix(_i3596, _t3596->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:282"); }))).s_)))) < (((int64_t)0LL)))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t3598 = &(g721); int64_t _i3598 = obj_1468; (S4*)_t3598->b + hr_ix(_i3598, _t3598->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:282"); }))).s_)), f110_ns_of(obj_1468), ((int64_t)2LL))) >= (((int64_t)0LL)))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t3601 = &(g721); int64_t _i3601 = obj_1468; (S4*)_t3601->b + hr_ix(_i3601, _t3601->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:282"); }))).s_)), f110_ns_of(obj_1468), ((int64_t)5LL))) < (((int64_t)0LL))))) { (void)(f108_cerr(n_1210, hr_str("a variant is constructed with { }", 33)));
return f138_set_t(n_1210, g592);
 }
int64_t ot_1470 = f137_ck(obj_1468, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3606 = &(g568); int64_t _i3606 = ot_1470; (S1*)_t3606->b + hr_ix(_i3606, _t3606->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:284"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(obj_1468, g593));
ot_1470 = g593;
 }
int64_t d_1471 = f182_deref(ot_1470); 
int64_t mb_1473 = f258_member_of(f10_nm(name_1469)); 
if ((((mb_1473) >= (((int64_t)0LL))) && (((((*({ hrv *_t3611 = &(g568); int64_t _i3611 = d_1471; (S1*)_t3611->b + hr_ix(_i3611, _t3611->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:287"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3612 = &(g568); int64_t _i3612 = d_1471; (S1*)_t3612->b + hr_ix(_i3612, _t3612->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:287"); }))).k_) == (((uint8_t)9LL)))))) { return f243_ck_builtin(n_1210, mb_1473, obj_1468, want_1211);
 }
if (((((((*({ hrv *_t3614 = &(g568); int64_t _i3614 = ot_1470; (S1*)_t3614->b + hr_ix(_i3614, _t3614->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:288"); }))).k_) == (((uint8_t)19LL))) || ((((*({ hrv *_t3615 = &(g568); int64_t _i3615 = ot_1470; (S1*)_t3615->b + hr_ix(_i3615, _t3615->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:288"); }))).k_) == (((uint8_t)12LL)))) || ((((*({ hrv *_t3616 = &(g568); int64_t _i3616 = ot_1470; (S1*)_t3616->b + hr_ix(_i3616, _t3616->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:288"); }))).k_) == (((uint8_t)13LL))))) { (void)(f187_default_t(obj_1468));
 }
int64_t b_1474 = f240_builtin_of(f10_nm(name_1469)); 
if ((((((b_1474) == (((int64_t)3LL))) || ((b_1474) == (((int64_t)30LL)))) || ((b_1474) == (((int64_t)31LL)))) || ((b_1474) == (((int64_t)7LL))))) { return f243_ck_builtin(n_1210, b_1474, obj_1468, want_1211);
 }
(void)(f178_set_x(n_1210, ((int64_t)1LL)));
return f257_call_fn(n_1210, name_1469, obj_1468, want_1211);
 }
(void)(f108_cerr(n_1210, hr_str("this call's callee is not supported yet", 39)));
return f138_set_t(n_1210, g592);
}
static int64_t f227_find_nest(int64_t name_1217) {
int64_t i_1218 = ((int64_t)((int64_t)(g323).n - (int64_t)((int64_t)1LL))); 
while (((i_1218) >= (((int64_t)0LL)))) { if ((((((int64_t)(((*({ hrv *_t3626 = &(g323); int64_t _i3626 = i_1218; (S14*)_t3626->b + hr_ix(_i3626, _t3626->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:23"); }))).name_))) == (name_1217)) && f171_visible(((int64_t)(((*({ hrv *_t3628 = &(g323); int64_t _i3628 = i_1218; (S14*)_t3628->b + hr_ix(_i3628, _t3628->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:23"); }))).own_))))) { return i_1218;
 }
i_1218--;
 } _bk3625:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f228_call_nested(int64_t n_1220, int64_t nf_1221) {
int64_t i_1222 = ((int64_t)(((*({ hrv *_t3629 = &(g323); int64_t _i3629 = nf_1221; (S14*)_t3629->b + hr_ix(_i3629, _t3629->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:379"); }))).inst_)); 
int64_t s_1229 = f229_ck_args(n_1220, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
{ int32_t _e3632 = ((*({ hrv *_t3633 = &(g721); int64_t _i3633 = n_1220; (S4*)_t3633->b + hr_ix(_i3633, _t3633->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:381"); }))).n_; for (int32_t _k3632 = 0; _k3632 < _e3632; _k3632++) { int32_t j_1230 = (int32_t)_k3632; int64_t c_1231 = f90_kid(n_1220, ((int64_t)(j_1230))); 
if (((((int64_t)(j_1230))) < (((int64_t)(((*({ hrv *_t3635 = &(g401); int64_t _i3635 = i_1222; (S6*)_t3635->b + hr_ix(_i3635, _t3635->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:381"); }))).pn_))))) { (void)(f140_conv(c_1231, f213_ptype_of(i_1222, ((int64_t)(j_1230)))));
 }
 } } _bk3631:; 
(void)(f230_pop_args(s_1229));
(void)(f231_note_caps_of(i_1222));
(void)(f232_note_edge(i_1222));
(void)(f173_set_r(n_1220, ((int64_t)3LL), i_1222));
return f138_set_t(n_1220, ({ int64_t _r3643; if (((((*({ hrv *_t3644 = &(g401); int64_t _i3644 = i_1222; (S6*)_t3644->b + hr_ix(_i3644, _t3644->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:385"); }))).ret_) >= (((int32_t)0LL)))) { _r3643 = ((int64_t)(((*({ hrv *_t3645 = &(g401); int64_t _i3645 = i_1222; (S6*)_t3645->b + hr_ix(_i3645, _t3645->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:385"); }))).ret_));  } else { _r3643 = g575;  } _r3643; }));
}
static int64_t f229_ck_args(int64_t n_1223, int64_t a0n_1224, int64_t first_1225) {
int64_t start_1226 = (g421).n; 
if (((first_1225) >= (((int64_t)0LL)))) { (void)(({ hrv *_v3646 = &(g421); int32_t _x3646 = ((int32_t)(f141_at(first_1225))); int32_t *_p3646 = (int32_t*)hr_grow(_v3646, 1, sizeof _x3646); *_p3646 = _x3646; _p3646; }));
(void)(({ hrv *_v3648 = &(g327); int32_t _x3648 = ((int32_t)(first_1225)); int32_t *_p3648 = (int32_t*)hr_grow(_v3648, 1, sizeof _x3648); *_p3648 = _x3648; _p3648; }));
 }
{ int32_t _e3650 = ((*({ hrv *_t3651 = &(g721); int64_t _i3651 = n_1223; (S4*)_t3651->b + hr_ix(_i3651, _t3651->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:258"); }))).n_; for (int32_t _k3650 = 0; _k3650 < _e3650; _k3650++) { int32_t i_1227 = (int32_t)_k3650; int64_t c_1228 = f90_kid(n_1223, ((int64_t)(i_1227))); 
(void)(({ hrv *_v3653 = &(g421); int32_t _x3653 = ((int32_t)(f137_ck(c_1228, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p3653 = (int32_t*)hr_grow(_v3653, 1, sizeof _x3653); *_p3653 = _x3653; _p3653; }));
(void)(({ hrv *_v3655 = &(g327); int32_t _x3655 = ((int32_t)(c_1228)); int32_t *_p3655 = (int32_t*)hr_grow(_v3655, 1, sizeof _x3655); *_p3655 = _x3655; _p3655; }));
 } } _bk3649:; 
return start_1226;
}
static void f230_pop_args(int64_t s_1232) {
(void)(({ hrv *_v3656 = &(g421); int64_t _k3656 = ((int64_t)((int64_t)(g421).n - (int64_t)s_1232)); if (_k3656 < 0 || _k3656 > _v3656->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:261"); _v3656->n -= _k3656; }));
(void)(({ hrv *_v3657 = &(g327); int64_t _k3657 = ((int64_t)((int64_t)(g327).n - (int64_t)s_1232)); if (_k3657 < 0 || _k3657 > _v3657->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:261"); _v3657->n -= _k3657; }));
}
static void f231_note_caps_of(int64_t i_1233) {
{ hrv *_v3659 = &(g405); for (int64_t _k3659 = 0; _k3659 < _v3659->n; _k3659++) { S13 c_1234 = ((S13*)_v3659->b)[_k3659]; if (((((int64_t)((c_1234).inst_))) == (i_1233))) { int64_t v_1235 = ((int64_t)((c_1234).lv_)); 
if (((((int64_t)(((*({ hrv *_t3660 = &(g402); int64_t _i3660 = v_1235; (S12*)_t3660->b + hr_ix(_i3660, _t3660->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:388"); }))).cfn_))) != (g415))) { (void)(f174_note_cap(v_1235));
 }
 }
 } } _bk3658:; 
}
static void f232_note_edge(int64_t callee_1236) {
if (((((g415) < (((int64_t)0LL))) || ((callee_1236) < (((int64_t)0LL)))) || ((g415) == (callee_1236)))) { return;
 }
{ hrv *_v3663 = &(g406); for (int64_t _k3663 = 0; _k3663 < _v3663->n; _k3663++) { S15 e_1237 = ((S15*)_v3663->b)[_k3663]; if ((((((int64_t)((e_1237).caller_))) == (g415)) && ((((int64_t)((e_1237).callee_))) == (callee_1236)))) { return;
 }
 } } _bk3662:; 
(void)(({ hrv *_v3664 = &(g406); S15 _x3664 = ((S15){ .caller_ = ((int32_t)(g415)), .callee_ = ((int32_t)(callee_1236)), }); S15 *_p3664 = (S15*)hr_grow(_v3664, 1, sizeof _x3664); *_p3664 = _x3664; _p3664; }));
}
static int64_t f233_block_binding(int64_t name_1238) {
int64_t i_1239 = g414; 
while (((i_1239) >= (((int64_t)0LL)))) { S6 f_1240 = (*({ hrv *_t3666 = &(g401); int64_t _i3666 = i_1239; (S6*)_t3666->b + hr_ix(_i3666, _t3666->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:341"); })); 
if ((((f_1240).blk_) >= (((int32_t)0LL)))) { int64_t fnode_1241 = ((int64_t)((f_1240).node_)); 
if (((f234_blk_gen(fnode_1241)) == (name_1238))) { return i_1239;
 }
 }
i_1239 = ((int64_t)((f_1240).par_));
 } _bk3665:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f234_blk_gen(int64_t fnode_1242) {
int64_t gl_1244 = f235_gen_list(fnode_1242); 
if (((gl_1244) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
{ int32_t _e3670 = ((*({ hrv *_t3671 = &(g721); int64_t _i3671 = gl_1244; (S4*)_t3671->b + hr_ix(_i3671, _t3671->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:59"); }))).n_; for (int32_t _k3670 = 0; _k3670 < _e3670; _k3670++) { int32_t i_1245 = (int32_t)_k3670; int64_t g_1246 = ((int64_t)(((*({ hrv *_t3672 = &(g721); int64_t _i3672 = f90_kid(gl_1244, ((int64_t)(i_1245))); (S4*)_t3672->b + hr_ix(_i3672, _t3672->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:59"); }))).s_)); 
if (f236_is_blockparam(fnode_1242, g_1246)) { return g_1246;
 }
 } } _bk3669:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f235_gen_list(int64_t fnode_1243) {
return ((int64_t)(((*({ hrv *_t3675 = &(g721); int64_t _i3675 = fnode_1243; (S4*)_t3675->b + hr_ix(_i3675, _t3675->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:47"); }))).d_));
}
static bool f236_is_blockparam(int64_t fnode_1247, int64_t gname_1248) {
{ int32_t _e3677 = ((*({ hrv *_t3678 = &(g721); int64_t _i3678 = fnode_1247; (S4*)_t3678->b + hr_ix(_i3678, _t3678->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:49"); }))).n_; for (int32_t _k3677 = 0; _k3677 < _e3677; _k3677++) { int32_t i_1249 = (int32_t)_k3677; int64_t p_1250 = f90_kid(fnode_1247, ((int64_t)(i_1249))); 
if ((((((*({ hrv *_t3680 = &(g721); int64_t _i3680 = p_1250; (S4*)_t3680->b + hr_ix(_i3680, _t3680->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:49"); }))).a_) >= (((int32_t)0LL))) && f237_mentions(((int64_t)(((*({ hrv *_t3682 = &(g721); int64_t _i3682 = p_1250; (S4*)_t3682->b + hr_ix(_i3682, _t3682->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:49"); }))).a_)), gname_1248))) { return false;
 }
 } } _bk3676:; 
return true;
}
static bool f237_mentions(int64_t t_1251, int64_t g_1252) {
if (((t_1251) < (((int64_t)0LL)))) { return false;
 }
S4 x_1253 = (*({ hrv *_t3683 = &(g721); int64_t _i3683 = t_1251; (S4*)_t3683->b + hr_ix(_i3683, _t3683->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:54"); })); 
int64_t k_1254 = ((int64_t)((x_1253).k_)); 
if (((k_1254) == (((int64_t)41LL)))) { if (((((int64_t)((x_1253).s_))) == (g_1252))) { return true;
 }
{ int32_t _e3685 = (x_1253).n_; for (int32_t _k3685 = 0; _k3685 < _e3685; _k3685++) { int32_t i_1255 = (int32_t)_k3685; if (f237_mentions(f90_kid(t_1251, ((int64_t)(i_1255))), g_1252)) { return true;
 }
 } } _bk3684:; 
return false;
 }
if (((((((k_1254) == (((int64_t)42LL))) || ((k_1254) == (((int64_t)43LL)))) || ((k_1254) == (((int64_t)44LL)))) || ((k_1254) == (((int64_t)48LL)))) || ((k_1254) == (((int64_t)46LL))))) { return f237_mentions(((int64_t)((x_1253).a_)), g_1252);
 }
return false;
}
static int64_t f238_call_block(int64_t n_1257, int64_t inst_1258) {
int64_t fv_1259 = ((int64_t)(((*({ hrv *_t3689 = &(g401); int64_t _i3689 = inst_1258; (S6*)_t3689->b + hr_ix(_i3689, _t3689->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:348"); }))).blk_)); 
int64_t own_1260 = ((int64_t)(((*({ hrv *_t3690 = &(g401); int64_t _i3690 = inst_1258; (S6*)_t3690->b + hr_ix(_i3690, _t3690->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:349"); }))).bown_)); 
int64_t s_1261 = f229_ck_args(n_1257, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t na_1262 = ((int64_t)(((*({ hrv *_t3692 = &(g721); int64_t _i3692 = n_1257; (S4*)_t3692->b + hr_ix(_i3692, _t3692->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:351"); }))).n_)); 
{ int64_t _e3694 = na_1262; for (int64_t _k3694 = 0; _k3694 < _e3694; _k3694++) { int64_t j_1263 = (int64_t)_k3694; int64_t c_1264 = f90_kid(n_1257, j_1263); 
if (f166_is_pending(f141_at(c_1264))) { { int32_t *_t3698 = &((*({ hrv *_t3699 = &(g421); int64_t _i3699 = ((int64_t)((int64_t)s_1261 + (int64_t)j_1263)); (int32_t*)_t3699->b + hr_ix(_i3699, _t3699->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:352"); }))); *_t3698 = ((int32_t)(f187_default_t(c_1264))); }
 } else { int64_t ct0_1265 = f141_at(c_1264); 
{ int32_t *_t3702 = &((*({ hrv *_t3703 = &(g421); int64_t _i3703 = ((int64_t)((int64_t)s_1261 + (int64_t)j_1263)); (int32_t*)_t3703->b + hr_ix(_i3703, _t3703->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:352"); }))); *_t3702 = ((int32_t)(({ int64_t _r3704; if (f209_has_rel(f182_deref(ct0_1265))) { _r3704 = ({ int64_t _r3707; if (((((*({ hrv *_t3708 = &(g568); int64_t _i3708 = ct0_1265; (S1*)_t3708->b + hr_ix(_i3708, _t3708->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:352"); }))).k_) == (((uint8_t)10LL)))) { _r3707 = ct0_1265;  } else { _r3707 = f119_t_ref(ct0_1265, ((int64_t)0LL));  } _r3707; });  } else { _r3704 = f239_deref_val(ct0_1265);  } _r3704; }))); }
 }
 } } _bk3693:; 
int64_t bi_1268 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v3712 = &(g401); for (int64_t _k3712 = 0; _k3712 < _v3712->n; _k3712++) { S6 f_1269 = ((S6*)_v3712->b)[_k3712]; int64_t i_1270 = (int64_t)_k3712; if ((((((((int64_t)((f_1269).node_))) == (fv_1259)) && ((((int64_t)((f_1269).par_))) == (own_1260))) && (((f_1269).blk_) == (((int32_t)(inst_1258))))) && ((((int64_t)((f_1269).cfn_))) == (g415)))) { bi_1268 = i_1270;
 }
 } } _bk3711:; 
if (((bi_1268) < (((int64_t)0LL)))) { bi_1268 = f105_new_inst(fv_1259, fv_1259, ((int64_t)((*({ hrv *_t3714 = &(g736); int64_t _i3714 = fv_1259; (int32_t*)_t3714->b + hr_ix(_i3714, _t3714->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:356"); })))), own_1260);
{ int32_t *_t3715 = &(((*({ hrv *_t3716 = &(g401); int64_t _i3716 = bi_1268; (S6*)_t3716->b + hr_ix(_i3716, _t3716->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:357"); }))).blk_); *_t3715 = ((int32_t)(inst_1258)); }
{ int32_t *_t3717 = &(((*({ hrv *_t3718 = &(g401); int64_t _i3718 = bi_1268; (S6*)_t3718->b + hr_ix(_i3718, _t3718->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:357"); }))).bown_); *_t3717 = ((int32_t)(own_1260)); }
{ int32_t *_t3719 = &(((*({ hrv *_t3720 = &(g401); int64_t _i3720 = bi_1268; (S6*)_t3720->b + hr_ix(_i3720, _t3720->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:358"); }))).cfn_); *_t3719 = ((int32_t)(g415)); }
int64_t sa_1271 = g414; 
int64_t sm_1272 = (g403).n; 
int64_t bt_1273 = (g484).n; 
int64_t ld_1274 = g420; 
g414 = bi_1268;
g420 = ((int64_t)0LL);
int64_t np_1275 = ((int64_t)(((*({ hrv *_t3721 = &(g721); int64_t _i3721 = fv_1259; (S4*)_t3721->b + hr_ix(_i3721, _t3721->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:361"); }))).n_)); 
if (((((uint16_t)((uint64_t)((*({ hrv *_t3722 = &(g721); int64_t _i3722 = fv_1259; (S4*)_t3722->b + hr_ix(_i3722, _t3722->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:362"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { int64_t _e3724 = np_1275; for (int64_t _k3724 = 0; _k3724 < _e3724; _k3724++) { int64_t j_1276 = (int64_t)_k3724; int64_t p_1277 = f90_kid(fv_1259, j_1276); 
int64_t pt_1278 = ({ int64_t _r3726; if (((j_1276) < (na_1262))) { _r3726 = ((int64_t)((*({ hrv *_t3727 = &(g421); int64_t _i3727 = ((int64_t)((int64_t)s_1261 + (int64_t)j_1276)); (int32_t*)_t3727->b + hr_ix(_i3727, _t3727->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:362"); }))));  } else { _r3726 = g592;  } _r3726; }); 
int64_t v_1279 = f207_add_lv(((int64_t)(((*({ hrv *_t3729 = &(g721); int64_t _i3729 = p_1277; (S4*)_t3729->b + hr_ix(_i3729, _t3729->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:362"); }))).s_)), pt_1278, ((int64_t)32LL), p_1277); 
(void)(f173_set_r(p_1277, ((int64_t)1LL), v_1279));
 } } _bk3723:; 
 } else { if (((na_1262) >= (((int64_t)1LL)))) { int64_t v_1280 = f207_add_lv(f8_intern(hr_str("it", 2)), ((int64_t)((*({ hrv *_t3733 = &(g421); int64_t _i3733 = s_1261; (int32_t*)_t3733->b + hr_ix(_i3733, _t3733->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:363"); })))), ((int64_t)32LL), fv_1259); 
(void)(f173_set_r(fv_1259, ((int64_t)1LL), v_1280));
 }
 }
int64_t body_1281 = ((int64_t)(((*({ hrv *_t3735 = &(g721); int64_t _i3735 = fv_1259; (S4*)_t3735->b + hr_ix(_i3735, _t3735->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:364"); }))).a_)); 
int64_t bt0_1282 = f137_ck(body_1281, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t rt_1283 = g575; 
if ((((((*({ hrv *_t3737 = &(g721); int64_t _i3737 = body_1281; (S4*)_t3737->b + hr_ix(_i3737, _t3737->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:367"); }))).a_) >= (((int32_t)0LL))) && ((bt0_1282) != (g575)))) { rt_1283 = ({ int64_t _r3738; if (f166_is_pending(bt0_1282)) { _r3738 = f187_default_t(((int64_t)(((*({ hrv *_t3741 = &(g721); int64_t _i3741 = body_1281; (S4*)_t3741->b + hr_ix(_i3741, _t3741->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:367"); }))).a_)));  } else { _r3738 = bt0_1282;  } _r3738; });
 }
{ int32_t *_t3742 = &(((*({ hrv *_t3743 = &(g401); int64_t _i3743 = bi_1268; (S6*)_t3743->b + hr_ix(_i3743, _t3743->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:368"); }))).ret_); *_t3742 = ((int32_t)(rt_1283)); }
(void)(({ hrv *_v3744 = &(g403); int64_t _k3744 = ((int64_t)((int64_t)(g403).n - (int64_t)sm_1272)); if (_k3744 < 0 || _k3744 > _v3744->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:369"); _v3744->n -= _k3744; }));
while ((((g484).n) > (bt_1273))) { (void)(({ hrv *_v3746 = &(g484); if (!_v3746->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:369"); ((int32_t*)_v3746->b)[--_v3746->n]; }));
 } _bk3745:; 
g414 = sa_1271;
g420 = ld_1274;
{ uint8_t *_t3747 = &(((*({ hrv *_t3748 = &(g401); int64_t _i3748 = bi_1268; (S6*)_t3748->b + hr_ix(_i3748, _t3748->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:371"); }))).st_); *_t3747 = ((uint8_t)2LL); }
 }
{ int64_t _e3750 = na_1262; for (int64_t _k3750 = 0; _k3750 < _e3750; _k3750++) { int64_t j_1284 = (int64_t)_k3750; int64_t c_1285 = f90_kid(n_1257, j_1284); 
if (f166_is_pending(f141_at(c_1285))) { (void)(f187_default_t(c_1285));
 }
 } } _bk3749:; 
(void)(f230_pop_args(s_1261));
(void)(f173_set_r(n_1257, ((int64_t)10LL), bi_1268));
return f138_set_t(n_1257, ((int64_t)(((*({ hrv *_t3758 = &(g401); int64_t _i3758 = bi_1268; (S6*)_t3758->b + hr_ix(_i3758, _t3758->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:376"); }))).ret_)));
}
static int64_t f239_deref_val(int64_t a_1266) {
int64_t d_1267 = f182_deref(a_1266); 
return ({ int64_t _r3760; if (((((*({ hrv *_t3761 = &(g568); int64_t _i3761 = d_1267; (S1*)_t3761->b + hr_ix(_i3761, _t3761->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:253"); }))).k_) == (((uint8_t)18LL)))) { _r3760 = g593;  } else { _r3760 = ({ int64_t _r3762; if (((((*({ hrv *_t3763 = &(g568); int64_t _i3763 = d_1267; (S1*)_t3763->b + hr_ix(_i3763, _t3763->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:253"); }))).k_) == (((uint8_t)7LL)))) { _r3762 = f136_t_enum(((int64_t)(((*({ hrv *_t3765 = &(g568); int64_t _i3765 = d_1267; (S1*)_t3765->b + hr_ix(_i3765, _t3765->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:253"); }))).a_)), false);  } else { _r3762 = d_1267;  } _r3762; });  } _r3760; });
}
static int64_t f240_builtin_of(hsl name_1286) {
if (hr_streq(name_1286, hr_str("print", 5))) { return ((int64_t)1LL);
 }
if (hr_streq(name_1286, hr_str("str", 3))) { return ((int64_t)2LL);
 }
if (hr_streq(name_1286, hr_str("format", 6))) { return ((int64_t)3LL);
 }
if (hr_streq(name_1286, hr_str("assert", 6))) { return ((int64_t)4LL);
 }
if (hr_streq(name_1286, hr_str("abort", 5))) { return ((int64_t)5LL);
 }
if (hr_streq(name_1286, hr_str("exit", 4))) { return ((int64_t)6LL);
 }
if (hr_streq(name_1286, hr_str("copy", 4))) { return ((int64_t)7LL);
 }
if (hr_streq(name_1286, hr_str("default", 7))) { return ((int64_t)8LL);
 }
if (hr_streq(name_1286, hr_str("to_bytes", 8))) { return ((int64_t)30LL);
 }
if (hr_streq(name_1286, hr_str("bytes_of", 8))) { return ((int64_t)31LL);
 }
if (hr_streq(name_1286, hr_str("from_bytes", 10))) { return ((int64_t)32LL);
 }
if (hr_streq(name_1286, hr_str("embed_file", 10))) { return ((int64_t)33LL);
 }
if (hr_streq(name_1286, hr_str("len", 3))) { return ((int64_t)9LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f241_user_format(int64_t n_1288) {
if (((((*({ hrv *_t3766 = &(g721); int64_t _i3766 = n_1288; (S4*)_t3766->b + hr_ix(_i3766, _t3766->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:297"); }))).n_) == (((int32_t)0LL)))) { return false;
 }
int64_t t_1289 = f182_deref(f137_ck(f90_kid(n_1288, ((int64_t)0LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))); 
return (!(((((((*({ hrv *_t3770 = &(g568); int64_t _i3770 = t_1289; (S1*)_t3770->b + hr_ix(_i3770, _t3770->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:297"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t3771 = &(g568); int64_t _i3771 = t_1289; (S1*)_t3771->b + hr_ix(_i3771, _t3771->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:297"); }))).a_))) == (g581))) && (f242_is_grow(t_1289) || ((((int64_t)(((*({ hrv *_t3773 = &(g568); int64_t _i3773 = t_1289; (S1*)_t3773->b + hr_ix(_i3773, _t3773->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:297"); }))).s_))) == (((int64_t)3LL)))))));
}
static bool f242_is_grow(int64_t t_1290) {
return (((((int64_t)(((*({ hrv *_t3774 = &(g568); int64_t _i3774 = t_1290; (S1*)_t3774->b + hr_ix(_i3774, _t3774->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:298"); }))).s_))) == (((int64_t)4LL))) || ((((int64_t)(((*({ hrv *_t3775 = &(g568); int64_t _i3775 = t_1290; (S1*)_t3775->b + hr_ix(_i3775, _t3775->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:298"); }))).s_))) == (((int64_t)5LL))));
}
static int64_t f243_ck_builtin(int64_t n_1291, int64_t b_1292, int64_t recv_1293, int64_t want_1294) {
S4 x_1295 = (*({ hrv *_t3776 = &(g721); int64_t _i3776 = n_1291; (S4*)_t3776->b + hr_ix(_i3776, _t3776->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:416"); })); 
(void)(f173_set_r(n_1291, ((int64_t)4LL), b_1292));
(void)(f178_set_x(n_1291, ({ int64_t _r3779; if (((recv_1293) >= (((int64_t)0LL)))) { _r3779 = ((int64_t)1LL);  } else { _r3779 = ((int64_t)0LL);  } _r3779; })));
int64_t na_1296 = ((int64_t)((x_1295).n_)); 

int64_t total_1298 = ((int64_t)((int64_t)na_1296 + (int64_t)({ int64_t _r3780; if (((recv_1293) >= (((int64_t)0LL)))) { _r3780 = ((int64_t)1LL);  } else { _r3780 = ((int64_t)0LL);  } _r3780; }))); 
int64_t need_1299 = ({ int64_t _r3781; if (((((((b_1292) == (((int64_t)1LL))) || ((b_1292) == (((int64_t)2LL)))) || ((b_1292) == (((int64_t)8LL)))) || ((b_1292) == (((int64_t)22LL)))) || ((b_1292) == (((int64_t)25LL))))) { _r3781 = ((int64_t)0LL);  } else { _r3781 = ({ int64_t _r3782; if (((((((b_1292) == (((int64_t)20LL))) || ((b_1292) == (((int64_t)21LL)))) || ((b_1292) == (((int64_t)23LL)))) || ((b_1292) == (((int64_t)24LL)))) || ((b_1292) == (((int64_t)26LL))))) { _r3782 = ((int64_t)2LL);  } else { _r3782 = ((int64_t)1LL);  } _r3782; });  } _r3781; }); 
if (((total_1298) < (need_1299))) { (void)(f108_cerr(n_1291, hr_str("too few arguments to a builtin", 30)));
return f138_set_t(n_1291, g592);
 }
if ((((b_1292) == (((int64_t)1LL))) || ((b_1292) == (((int64_t)2LL))))) { { int64_t _e3786 = na_1296; for (int64_t _k3786 = 0; _k3786 < _e3786; _k3786++) { int64_t i_1300 = (int64_t)_k3786; int64_t c_1301 = f90_kid(n_1291, i_1300); 
int64_t t_1302 = f137_ck(c_1301, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f166_is_pending(t_1302)) { (void)(f187_default_t(c_1301));
 }
(void)(f245_hook_walk(f206_fin_t(c_1301)));
 } } _bk3785:; 
return f138_set_t(n_1291, ({ int64_t _r3794; if (((b_1292) == (((int64_t)2LL)))) { _r3794 = f123_t_arr(g581, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));  } else { _r3794 = g575;  } _r3794; }));
 }
if (((b_1292) == (((int64_t)3LL)))) { int64_t o_1428 = f244_arg(((int64_t)0LL), &recv_1293, &n_1291); 
if (((recv_1293) < (((int64_t)0LL)))) { (void)(f137_ck(o_1428, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
{ int64_t _e3799 = total_1298; for (int64_t _k3799 = ((int64_t)1LL); _k3799 < _e3799; _k3799++) { int64_t i_1429 = (int64_t)_k3799; int64_t c_1430 = f244_arg(i_1429, &recv_1293, &n_1291); 
int64_t t_1431 = f137_ck(c_1430, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f166_is_pending(t_1431)) { (void)(f187_default_t(c_1430));
 }
(void)(f245_hook_walk(f206_fin_t(c_1430)));
 } } _bk3798:; 
return f138_set_t(n_1291, g575);
 }
if (((b_1292) == (((int64_t)4LL)))) { (void)(f137_ck(f244_arg(((int64_t)0LL), &recv_1293, &n_1291), g576));
(void)(f140_conv(f244_arg(((int64_t)0LL), &recv_1293, &n_1291), g576));
return f138_set_t(n_1291, g575);
 }
if (((b_1292) == (((int64_t)5LL)))) { int64_t t_1432 = f137_ck(f244_arg(((int64_t)0LL), &recv_1293, &n_1291), g593); 
if (f166_is_pending(t_1432)) { (void)(f187_default_t(f244_arg(((int64_t)0LL), &recv_1293, &n_1291)));
 }
return f138_set_t(n_1291, g575);
 }
if (((b_1292) == (((int64_t)6LL)))) { (void)(f137_ck(f244_arg(((int64_t)0LL), &recv_1293, &n_1291), g580));
(void)(f140_conv(f244_arg(((int64_t)0LL), &recv_1293, &n_1291), g580));
return f138_set_t(n_1291, g575);
 }
if (((b_1292) == (((int64_t)8LL)))) { int64_t ta_1433 = ((int64_t)((x_1295).c_)); 
if (((ta_1433) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1291, hr_str("default needs a type: default<T>()", 34)));
return f138_set_t(n_1291, g592);
 }
return f138_set_t(n_1291, f113_rtype(f90_kid(ta_1433, ((int64_t)0LL)), f110_ns_of(n_1291)));
 }
if (((b_1292) == (((int64_t)7LL)))) { int64_t c_1434 = f244_arg(((int64_t)0LL), &recv_1293, &n_1291); 
if (((recv_1293) < (((int64_t)0LL)))) { (void)(f137_ck(c_1434, want_1294));
 }
int64_t t_1435 = f141_at(c_1434); 
if (f166_is_pending(t_1435)) { t_1435 = f187_default_t(c_1434);
 }
int64_t d_1436 = f182_deref(t_1435); 
int64_t k_1437 = ((int64_t)(((*({ hrv *_t3835 = &(g568); int64_t _i3835 = d_1436; (S1*)_t3835->b + hr_ix(_i3835, _t3835->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:444"); }))).k_)); 
if (((k_1437) == (((int64_t)9LL)))) { return f138_set_t(n_1291, f123_t_arr(((int64_t)(((*({ hrv *_t3838 = &(g568); int64_t _i3838 = d_1436; (S1*)_t3838->b + hr_ix(_i3838, _t3838->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:445"); }))).a_)), ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
return f138_set_t(n_1291, d_1436);
 }
if (((b_1292) == (((int64_t)9LL)))) { int64_t c_1438 = f244_arg(((int64_t)0LL), &recv_1293, &n_1291); 
if (((recv_1293) < (((int64_t)0LL)))) { (void)(f137_ck(c_1438, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (((((*({ hrv *_t3842 = &(g568); int64_t _i3842 = f141_at(c_1438); (S1*)_t3842->b + hr_ix(_i3842, _t3842->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:448"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(c_1438, g593));
 }
return f138_set_t(n_1291, g580);
 }
if (((b_1292) == (((int64_t)31LL)))) { int64_t c_1439 = f244_arg(((int64_t)0LL), &recv_1293, &n_1291); 
if (((recv_1293) < (((int64_t)0LL)))) { (void)(f137_ck(c_1439, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (f166_is_pending(f141_at(c_1439))) { (void)(f187_default_t(c_1439));
 }
return f138_set_t(n_1291, g593);
 }
if (((b_1292) == (((int64_t)30LL)))) { int64_t c_1440 = f244_arg(((int64_t)0LL), &recv_1293, &n_1291); 
if (((recv_1293) < (((int64_t)0LL)))) { (void)(f137_ck(c_1440, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (f166_is_pending(f141_at(c_1440))) { (void)(f187_default_t(c_1440));
 }
if (((total_1298) > (((int64_t)1LL)))) { (void)(f137_ck(f244_arg(((int64_t)1LL), &recv_1293, &n_1291), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_1291, g575);
 }
return f138_set_t(n_1291, f123_t_arr(g581, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (((b_1292) == (((int64_t)32LL)))) { int64_t ta_1441 = ((int64_t)((x_1295).c_)); 
int64_t t_1442 = ({ int64_t _r3862; if (((ta_1441) >= (((int64_t)0LL)))) { _r3862 = f113_rtype(f90_kid(ta_1441, ((int64_t)0LL)), f110_ns_of(n_1291));  } else { _r3862 = g592;  } _r3862; }); 
(void)(f137_ck(f244_arg(((int64_t)0LL), &recv_1293, &n_1291), g593));
if (f166_is_pending(f141_at(f244_arg(((int64_t)0LL), &recv_1293, &n_1291)))) { (void)(f187_default_t(f244_arg(((int64_t)0LL), &recv_1293, &n_1291)));
 }
return f138_set_t(n_1291, t_1442);
 }
if (((b_1292) == (((int64_t)33LL)))) { (void)(f137_ck(f244_arg(((int64_t)0LL), &recv_1293, &n_1291), g593));
(void)(f187_default_t(f244_arg(((int64_t)0LL), &recv_1293, &n_1291)));
return f138_set_t(n_1291, g593);
 }
int64_t r_1443 = recv_1293; 
int64_t rt_1444 = f182_deref(f141_at(r_1443)); 
int64_t e_1445 = ((int64_t)(((*({ hrv *_t3881 = &(g568); int64_t _i3881 = rt_1444; (S1*)_t3881->b + hr_ix(_i3881, _t3881->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:455"); }))).a_)); 
if (((b_1292) == (((int64_t)20LL)))) { if (((total_1298) != (((int64_t)2LL)))) { (void)(f108_cerr(n_1291, hr_str("push takes one value", 20)));
return f138_set_t(n_1291, g592);
 }
int64_t c_1446 = f244_arg(((int64_t)1LL), &recv_1293, &n_1291); 
(void)(f137_ck(c_1446, e_1445));
(void)(f140_conv(c_1446, e_1445));
return f138_set_t(n_1291, f119_t_ref(e_1445, ((int64_t)0LL)));
 }
if (((b_1292) == (((int64_t)21LL)))) { int64_t c_1447 = f244_arg(((int64_t)1LL), &recv_1293, &n_1291); 
int64_t t_1448 = f137_ck(c_1447, f18_t_slice(e_1445, true)); 
if (((((*({ hrv *_t3892 = &(g568); int64_t _i3892 = t_1448; (S1*)_t3892->b + hr_ix(_i3892, _t3892->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:457"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(c_1447, g593));
 } else { if (((((*({ hrv *_t3894 = &(g568); int64_t _i3894 = t_1448; (S1*)_t3894->b + hr_ix(_i3894, _t3894->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:457"); }))).k_) == (((uint8_t)19LL)))) { (void)(f140_conv(c_1447, f123_t_arr(e_1445, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
 } else { int64_t dt_1449 = f182_deref(t_1448); 
if (((((((*({ hrv *_t3898 = &(g568); int64_t _i3898 = dt_1449; (S1*)_t3898->b + hr_ix(_i3898, _t3898->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:457"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3899 = &(g568); int64_t _i3899 = dt_1449; (S1*)_t3899->b + hr_ix(_i3899, _t3899->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:457"); }))).k_) == (((uint8_t)9LL)))) && ((((int64_t)(((*({ hrv *_t3900 = &(g568); int64_t _i3900 = dt_1449; (S1*)_t3900->b + hr_ix(_i3900, _t3900->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:457"); }))).a_))) != (e_1445)))) { (void)(f108_cerr(c_1447, hr_str("append of a different element type", 34)));
 }
 }
 }
return f138_set_t(n_1291, g575);
 }
if (((b_1292) == (((int64_t)22LL)))) { return f138_set_t(n_1291, e_1445);
 }
if (((b_1292) == (((int64_t)23LL)))) { (void)(f137_ck(f244_arg(((int64_t)1LL), &recv_1293, &n_1291), g580));
(void)(f140_conv(f244_arg(((int64_t)1LL), &recv_1293, &n_1291), g580));
return f138_set_t(n_1291, g575);
 }
if (((b_1292) == (((int64_t)24LL)))) { (void)(f137_ck(f244_arg(((int64_t)1LL), &recv_1293, &n_1291), g580));
(void)(f140_conv(f244_arg(((int64_t)1LL), &recv_1293, &n_1291), g580));
if (((total_1298) > (((int64_t)2LL)))) { (void)(f137_ck(f244_arg(((int64_t)2LL), &recv_1293, &n_1291), e_1445));
(void)(f140_conv(f244_arg(((int64_t)2LL), &recv_1293, &n_1291), e_1445));
 }
return f138_set_t(n_1291, g575);
 }
if (((b_1292) == (((int64_t)25LL)))) { return f138_set_t(n_1291, g575);
 }
if (((b_1292) == (((int64_t)26LL)))) { (void)(f137_ck(f244_arg(((int64_t)1LL), &recv_1293, &n_1291), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_1291, g580);
 }
return f138_set_t(n_1291, g592);
}
static int64_t f244_arg(int64_t i_1297, int64_t *c1293, int64_t *c1291) {
return ({ int64_t _r3923; if ((((*c1293)) >= (((int64_t)0LL)))) { _r3923 = ({ int64_t _r3924; if (((i_1297) == (((int64_t)0LL)))) { _r3924 = (*c1293);  } else { _r3924 = f90_kid((*c1291), ((int64_t)((int64_t)i_1297 - (int64_t)((int64_t)1LL))));  } _r3924; });  } else { _r3923 = f90_kid((*c1291), i_1297);  } _r3923; });
}
static void f245_hook_walk(int64_t t_1303) {
while ((((g361).n) < ((g568).n))) { (void)(({ hrv *_v3928 = &(g361); int32_t _x3928 = ((int32_t)(0 - (uint64_t)(((int32_t)2LL)))); int32_t *_p3928 = (int32_t*)hr_grow(_v3928, 1, sizeof _x3928); *_p3928 = _x3928; _p3928; }));
(void)(({ hrv *_v3929 = &(g362); uint8_t _x3929 = ((uint8_t)0LL); uint8_t *_p3929 = (uint8_t*)hr_grow(_v3929, 1, sizeof _x3929); *_p3929 = _x3929; _p3929; }));
 } _bk3927:; 
if ((((t_1303) < (((int64_t)0LL))) || (((*({ hrv *_t3930 = &(g362); int64_t _i3930 = t_1303; (uint8_t*)_t3930->b + hr_ix(_i3930, _t3930->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:328"); }))) != (((uint8_t)0LL))))) { return;
 }
{ uint8_t *_t3931 = &((*({ hrv *_t3932 = &(g362); int64_t _i3932 = t_1303; (uint8_t*)_t3932->b + hr_ix(_i3932, _t3932->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:329"); }))); *_t3931 = ((uint8_t)1LL); }
S1 x_1304 = (*({ hrv *_t3933 = &(g568); int64_t _i3933 = t_1303; (S1*)_t3933->b + hr_ix(_i3933, _t3933->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:330"); })); 
int64_t k_1305 = ((int64_t)((x_1304).k_)); 
if (((k_1305) == (((int64_t)10LL)))) { (void)(f245_hook_walk(((int64_t)((x_1304).a_))));
return;
 }
if ((((k_1305) == (((int64_t)8LL))) || ((k_1305) == (((int64_t)9LL))))) { (void)(f245_hook_walk(((int64_t)((x_1304).a_))));
return;
 }
if (((k_1305) == (((int64_t)14LL)))) { { int32_t _e3937 = (x_1304).n_; for (int32_t _k3937 = 0; _k3937 < _e3937; _k3937++) { int32_t i_1306 = (int32_t)_k3937; (void)(f245_hook_walk(((int64_t)((*({ hrv *_t3939 = &(g569); int64_t _i3939 = ((int64_t)((int64_t)((int64_t)((x_1304).l_)) + (int64_t)((int64_t)(i_1306)))); (int32_t*)_t3939->b + hr_ix(_i3939, _t3939->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:333"); }))))));
 } } _bk3936:; 
return;
 }
if (((k_1305) == (((int64_t)5LL)))) { (void)(f246_hook_of(t_1303));
int64_t si_1420 = ((int64_t)((x_1304).a_)); 
{ int32_t _e3942 = ((*({ hrv *_t3943 = &(g571); int64_t _i3943 = si_1420; (S10*)_t3943->b + hr_ix(_i3943, _t3943->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:334"); }))).fnum_; for (int32_t _k3942 = 0; _k3942 < _e3942; _k3942++) { int32_t i_1421 = (int32_t)_k3942; S11 f_1422 = (*({ hrv *_t3944 = &(g572); int64_t _i3944 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3945 = &(g571); int64_t _i3945 = si_1420; (S10*)_t3945->b + hr_ix(_i3945, _t3945->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:334"); }))).f0_)) + (int64_t)((int64_t)(i_1421)))); (S11*)_t3944->b + hr_ix(_i3944, _t3944->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:334"); })); 
if ((((f_1422).ty_) >= (((int32_t)0LL)))) { (void)(f245_hook_walk(((int64_t)((f_1422).ty_))));
 }
 } } _bk3941:; 
return;
 }
if (((k_1305) == (((int64_t)7LL)))) { (void)(f246_hook_of(t_1303));
S9 v_1423 = (*({ hrv *_t3948 = &(g574); int64_t _i3948 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3949 = &(g573); int64_t _i3949 = (x_1304).a_; (S8*)_t3949->b + hr_ix(_i3949, _t3949->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:335"); }))).v0_)) + (int64_t)((int64_t)((x_1304).c_)))); (S9*)_t3948->b + hr_ix(_i3948, _t3948->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:335"); })); 
if ((((v_1423).si_) >= (((int32_t)0LL)))) { { int32_t _e3951 = ((*({ hrv *_t3952 = &(g571); int64_t _i3952 = (v_1423).si_; (S10*)_t3952->b + hr_ix(_i3952, _t3952->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:335"); }))).fnum_; for (int32_t _k3951 = 0; _k3951 < _e3951; _k3951++) { int32_t i_1424 = (int32_t)_k3951; S11 f_1425 = (*({ hrv *_t3953 = &(g572); int64_t _i3953 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3954 = &(g571); int64_t _i3954 = (v_1423).si_; (S10*)_t3954->b + hr_ix(_i3954, _t3954->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:335"); }))).f0_)) + (int64_t)((int64_t)(i_1424)))); (S11*)_t3953->b + hr_ix(_i3953, _t3953->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:335"); })); 
if ((((f_1425).ty_) >= (((int32_t)0LL)))) { (void)(f245_hook_walk(((int64_t)((f_1425).ty_))));
 }
 } } _bk3950:; 
 }
return;
 }
if (((k_1305) == (((int64_t)6LL)))) { (void)(f246_hook_of(t_1303));
int64_t ei_1426 = ((int64_t)((x_1304).a_)); 
{ int32_t _e3958 = ((*({ hrv *_t3959 = &(g573); int64_t _i3959 = ei_1426; (S8*)_t3959->b + hr_ix(_i3959, _t3959->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:336"); }))).vnum_; for (int32_t _k3958 = 0; _k3958 < _e3958; _k3958++) { int32_t i_1427 = (int32_t)_k3958; (void)(f245_hook_walk(f125_t_variant(ei_1426, ((int64_t)(i_1427)))));
 } } _bk3957:; 
 }
}
static int64_t f246_hook_of(int64_t t_1307) {
while ((((g361).n) < ((g568).n))) { (void)(({ hrv *_v3963 = &(g361); int32_t _x3963 = ((int32_t)(0 - (uint64_t)(((int32_t)2LL)))); int32_t *_p3963 = (int32_t*)hr_grow(_v3963, 1, sizeof _x3963); *_p3963 = _x3963; _p3963; }));
(void)(({ hrv *_v3964 = &(g362); uint8_t _x3964 = ((uint8_t)0LL); uint8_t *_p3964 = (uint8_t*)hr_grow(_v3964, 1, sizeof _x3964); *_p3964 = _x3964; _p3964; }));
 } _bk3962:; 
if ((((*({ hrv *_t3965 = &(g361); int64_t _i3965 = t_1307; (int32_t*)_t3965->b + hr_ix(_i3965, _t3965->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:304"); }))) != (((int32_t)(0 - (uint64_t)(((int32_t)2LL))))))) { return ((int64_t)((*({ hrv *_t3966 = &(g361); int64_t _i3966 = t_1307; (int32_t*)_t3966->b + hr_ix(_i3966, _t3966->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:304"); }))));
 }
{ int32_t *_t3967 = &((*({ hrv *_t3968 = &(g361); int64_t _i3968 = t_1307; (int32_t*)_t3968->b + hr_ix(_i3968, _t3968->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:305"); }))); *_t3967 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
int64_t k_1308 = ((int64_t)(((*({ hrv *_t3969 = &(g568); int64_t _i3969 = t_1307; (S1*)_t3969->b + hr_ix(_i3969, _t3969->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:306"); }))).k_)); 
if (((((((k_1308) == (((int64_t)0LL))) || ((k_1308) == (((int64_t)1LL)))) || ((k_1308) == (((int64_t)10LL)))) || ((k_1308) == (((int64_t)14LL)))) || f166_is_pending(t_1307))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t node_1309 = ({ int64_t _r3971; if (((k_1308) == (((int64_t)5LL)))) { _r3971 = ((int64_t)(((*({ hrv *_t3972 = &(g571); int64_t _i3972 = ((*({ hrv *_t3973 = &(g568); int64_t _i3973 = t_1307; (S1*)_t3973->b + hr_ix(_i3973, _t3973->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:308"); }))).a_; (S10*)_t3972->b + hr_ix(_i3972, _t3972->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:308"); }))).node_));  } else { _r3971 = ({ int64_t _r3974; if ((((k_1308) == (((int64_t)6LL))) || ((k_1308) == (((int64_t)7LL))))) { _r3974 = ((int64_t)(((*({ hrv *_t3975 = &(g573); int64_t _i3975 = ((*({ hrv *_t3976 = &(g568); int64_t _i3976 = t_1307; (S1*)_t3976->b + hr_ix(_i3976, _t3976->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:308"); }))).a_; (S8*)_t3975->b + hr_ix(_i3975, _t3975->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:308"); }))).node_));  } else { _r3974 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3974; });  } _r3971; }); 
if (((g363) < (((int64_t)0LL)))) { g363 = f8_intern(hr_str("format", 6));
 }
int64_t s_1310 = (g421).n; 
(void)(({ hrv *_v3978 = &(g421); int32_t _x3978 = ((int32_t)(f119_t_ref(f123_t_arr(g581, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))), ((int64_t)0LL)))); int32_t *_p3978 = (int32_t*)hr_grow(_v3978, 1, sizeof _x3978); *_p3978 = _x3978; _p3978; }));
(void)(({ hrv *_v3981 = &(g327); int32_t _x3981 = ((int32_t)0LL); int32_t *_p3981 = (int32_t*)hr_grow(_v3981, 1, sizeof _x3981); *_p3981 = _x3981; _p3981; }));
(void)(({ hrv *_v3982 = &(g421); int32_t _x3982 = ((int32_t)(t_1307)); int32_t *_p3982 = (int32_t*)hr_grow(_v3982, 1, sizeof _x3982); *_p3982 = _x3982; _p3982; }));
(void)(({ hrv *_v3983 = &(g327); int32_t _x3983 = ((int32_t)0LL); int32_t *_p3983 = (int32_t*)hr_grow(_v3983, 1, sizeof _x3983); *_p3983 = _x3983; _p3983; }));
M96 _t3984 = f247_resolve(((int64_t)0LL), g363, ({ int64_t _r3986; if (((node_1309) >= (((int64_t)0LL)))) { _r3986 = f110_ns_of(node_1309);  } else { _r3986 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3986; }), s_1310, ((int64_t)2LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false); int64_t fnode_1399 = _t3984.r0; int64_t b0_1400 = _t3984.r1; int64_t bn_1401 = _t3984.r2; 
(void)(f230_pop_args(s_1310));
if (((((fnode_1399) < (((int64_t)0LL))) || ((((*({ hrv *_t3989 = &(g721); int64_t _i3989 = fnode_1399; (S4*)_t3989->b + hr_ix(_i3989, _t3989->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:315"); }))).n_) != (((int32_t)2LL)))) || f254_is_std_node(fnode_1399))) { (void)(({ hrv *_v3991 = &(g325); int64_t _k3991 = ((int64_t)((int64_t)(g325).n - (int64_t)b0_1400)); if (_k3991 < 0 || _k3991 > _v3991->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:315"); _v3991->n -= _k3991; }));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t sa_1402 = g414; 
int64_t sc_1403 = g415; 
g414 = g416;
g415 = g416;
int64_t inst_1418 = f255_get_inst(fnode_1399, b0_1400, bn_1401, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
g414 = sa_1402;
g415 = sc_1403;
(void)(({ hrv *_v3993 = &(g325); int64_t _k3993 = ((int64_t)((int64_t)(g325).n - (int64_t)b0_1400)); if (_k3993 < 0 || _k3993 > _v3993->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:319"); _v3993->n -= _k3993; }));
while ((((g361).n) < ((g568).n))) { (void)(({ hrv *_v3995 = &(g361); int32_t _x3995 = ((int32_t)(0 - (uint64_t)(((int32_t)2LL)))); int32_t *_p3995 = (int32_t*)hr_grow(_v3995, 1, sizeof _x3995); *_p3995 = _x3995; _p3995; }));
(void)(({ hrv *_v3996 = &(g362); uint8_t _x3996 = ((uint8_t)0LL); uint8_t *_p3996 = (uint8_t*)hr_grow(_v3996, 1, sizeof _x3996); *_p3996 = _x3996; _p3996; }));
 } _bk3994:; 
int64_t pd_1419 = f182_deref(f213_ptype_of(inst_1418, ((int64_t)1LL))); 
if ((((pd_1419) != (t_1307)) && (!((((k_1308) == (((int64_t)7LL))) && ((((*({ hrv *_t3999 = &(g568); int64_t _i3999 = pd_1419; (S1*)_t3999->b + hr_ix(_i3999, _t3999->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:322"); }))).k_) == (((uint8_t)6LL)))))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
{ int32_t *_t4000 = &((*({ hrv *_t4001 = &(g361); int64_t _i4001 = t_1307; (int32_t*)_t4001->b + hr_ix(_i4001, _t4001->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:323"); }))); *_t4000 = ((int32_t)(inst_1418)); }
return inst_1418;
}
static M96 f247_resolve(int64_t n_1311, int64_t name_1312, int64_t ns_1313, int64_t a0_1314, int64_t an_1315, int64_t blk_1316, int64_t tyargs_1317, bool report_1318) {
int64_t c0_1319 = (g324).n; 
(void)(f248_cands_add(name_1312, ns_1313));
int64_t best_1328 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
int64_t bestr_1329 = ((int64_t)99LL); 
int64_t bestb0_1330 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
int64_t bestbn_1331 = ((int64_t)0LL); 
bool tie_1332 = false; 
bool bestuser_1333 = false; 
int64_t nb0_1334 = (g325).n; 
{ int64_t _e4004 = (g324).n; for (int64_t _k4004 = c0_1319; _k4004 < _e4004; _k4004++) { int64_t ci_1335 = (int64_t)_k4004; int64_t fnode_1336 = ((int64_t)(((*({ hrv *_t4005 = &(g506); int64_t _i4005 = (*({ hrv *_t4006 = &(g324); int64_t _i4006 = ci_1335; (int32_t*)_t4006->b + hr_ix(_i4006, _t4006->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:210"); })); (S5*)_t4005->b + hr_ix(_i4005, _t4005->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:210"); }))).node_)); 
int64_t np_1337 = ((int64_t)(((*({ hrv *_t4007 = &(g721); int64_t _i4007 = fnode_1336; (S4*)_t4007->b + hr_ix(_i4007, _t4007->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:211"); }))).n_)); 
int64_t nreq_1338 = ((int64_t)0LL); 
{ int64_t _e4009 = np_1337; for (int64_t _k4009 = 0; _k4009 < _e4009; _k4009++) { int64_t j_1339 = (int64_t)_k4009; if (((((*({ hrv *_t4010 = &(g721); int64_t _i4010 = f90_kid(fnode_1336, j_1339); (S4*)_t4010->b + hr_ix(_i4010, _t4010->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:213"); }))).b_) < (((int32_t)0LL)))) { nreq_1338 = ((int64_t)((int64_t)j_1339 + (int64_t)((int64_t)1LL)));
 }
 } } _bk4008:; 
if ((((an_1315) > (np_1337)) || ((an_1315) < (nreq_1338)))) { continue;
 }
int64_t bg_1340 = f234_blk_gen(fnode_1336); 
if ((((((blk_1316) >= (((int64_t)0LL)))) != (((bg_1340) >= (((int64_t)0LL))))) && (!(((((blk_1316) < (((int64_t)0LL))) && ((bg_1340) >= (((int64_t)0LL)))) && ((tyargs_1317) >= (((int64_t)0LL)))))))) { continue;
 }
int64_t b0_1341 = (g325).n; 
int64_t gl_1342 = f235_gen_list(fnode_1336); 
if (((gl_1342) >= (((int64_t)0LL)))) { { int32_t _e4015 = ((*({ hrv *_t4016 = &(g721); int64_t _i4016 = gl_1342; (S4*)_t4016->b + hr_ix(_i4016, _t4016->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:219"); }))).n_; for (int32_t _k4015 = 0; _k4015 < _e4015; _k4015++) { int32_t j_1343 = (int32_t)_k4015; (void)(({ hrv *_v4017 = &(g325); S7 _x4017 = ((S7){ .name_ = ((*({ hrv *_t4018 = &(g721); int64_t _i4018 = f90_kid(gl_1342, ((int64_t)(j_1343))); (S4*)_t4018->b + hr_ix(_i4018, _t4018->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:219"); }))).s_, .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }); S7 *_p4017 = (S7*)hr_grow(_v4017, 1, sizeof _x4017); *_p4017 = _x4017; _p4017; }));
 } } _bk4014:; 
 }
{ int64_t _e4021 = np_1337; for (int64_t _k4021 = 0; _k4021 < _e4021; _k4021++) { int64_t j_1344 = (int64_t)_k4021; int64_t p_1345 = f90_kid(fnode_1336, j_1344); 
if (((((*({ hrv *_t4023 = &(g721); int64_t _i4023 = p_1345; (S4*)_t4023->b + hr_ix(_i4023, _t4023->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:220"); }))).a_) < (((int32_t)0LL)))) { (void)(({ hrv *_v4024 = &(g325); S7 _x4024 = ((S7){ .name_ = ((int32_t)(f199_upname(p_1345))), .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }); S7 *_p4024 = (S7*)hr_grow(_v4024, 1, sizeof _x4024); *_p4024 = _x4024; _p4024; }));
 }
 } } _bk4020:; 
if (((tyargs_1317) >= (((int64_t)0LL)))) { { int64_t _e4027 = f45_min(((int64_t)(((*({ hrv *_t4029 = &(g721); int64_t _i4029 = tyargs_1317; (S4*)_t4029->b + hr_ix(_i4029, _t4029->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:221"); }))).n_)), ((int64_t)((int64_t)(g325).n - (int64_t)b0_1341))); for (int64_t _k4027 = 0; _k4027 < _e4027; _k4027++) { int64_t j_1346 = (int64_t)_k4027; { int32_t *_t4030 = &(((*({ hrv *_t4031 = &(g325); int64_t _i4031 = ((int64_t)((int64_t)b0_1341 + (int64_t)j_1346)); (S7*)_t4031->b + hr_ix(_i4031, _t4031->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:221"); }))).ty_); *_t4030 = ((int32_t)(f113_rtype(f90_kid(tyargs_1317, j_1346), ns_1313))); }
 } } _bk4026:; 
 }
{ int64_t _e4035 = an_1315; for (int64_t _k4035 = 0; _k4035 < _e4035; _k4035++) { int64_t j_1347 = (int64_t)_k4035; int64_t p_1348 = f90_kid(fnode_1336, j_1347); 
int64_t a_1349 = ((int64_t)((*({ hrv *_t4037 = &(g421); int64_t _i4037 = ((int64_t)((int64_t)a0_1314 + (int64_t)j_1347)); (int32_t*)_t4037->b + hr_ix(_i4037, _t4037->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:222"); })))); 
if ((!(f166_is_pending(a_1349)))) { if (((((*({ hrv *_t4039 = &(g721); int64_t _i4039 = p_1348; (S4*)_t4039->b + hr_ix(_i4039, _t4039->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:222"); }))).a_) >= (((int32_t)0LL)))) { (void)(f249_match_ty(((int64_t)(((*({ hrv *_t4041 = &(g721); int64_t _i4041 = p_1348; (S4*)_t4041->b + hr_ix(_i4041, _t4041->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:222"); }))).a_)), a_1349, b0_1341));
 } else { { int64_t _e4043 = (g325).n; for (int64_t _k4043 = b0_1341; _k4043 < _e4043; _k4043++) { int64_t q_1361 = (int64_t)_k4043; if ((((((int64_t)(((*({ hrv *_t4044 = &(g325); int64_t _i4044 = q_1361; (S7*)_t4044->b + hr_ix(_i4044, _t4044->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:222"); }))).name_))) == (f199_upname(p_1348))) && ((((*({ hrv *_t4046 = &(g325); int64_t _i4046 = q_1361; (S7*)_t4046->b + hr_ix(_i4046, _t4046->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:222"); }))).ty_) < (((int32_t)0LL))))) { { int32_t *_t4047 = &(((*({ hrv *_t4048 = &(g325); int64_t _i4048 = q_1361; (S7*)_t4048->b + hr_ix(_i4048, _t4048->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:222"); }))).ty_); *_t4047 = ((int32_t)(f239_deref_val(a_1349))); }
 }
 } } _bk4042:; 
 }
 }
 } } _bk4034:; 
{ int64_t _e4051 = an_1315; for (int64_t _k4051 = 0; _k4051 < _e4051; _k4051++) { int64_t j_1362 = (int64_t)_k4051; int64_t p_1363 = f90_kid(fnode_1336, j_1362); 
int64_t a_1364 = ((int64_t)((*({ hrv *_t4053 = &(g421); int64_t _i4053 = ((int64_t)((int64_t)a0_1314 + (int64_t)j_1362)); (int32_t*)_t4053->b + hr_ix(_i4053, _t4053->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:223"); })))); 
if (f166_is_pending(a_1364)) { int64_t dt_1367 = f250_pend_default(a_1364); 
if (((((*({ hrv *_t4056 = &(g721); int64_t _i4056 = p_1363; (S4*)_t4056->b + hr_ix(_i4056, _t4056->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:223"); }))).a_) >= (((int32_t)0LL)))) { (void)(f249_match_ty(((int64_t)(((*({ hrv *_t4058 = &(g721); int64_t _i4058 = p_1363; (S4*)_t4058->b + hr_ix(_i4058, _t4058->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:223"); }))).a_)), dt_1367, b0_1341));
 } else { { int64_t _e4060 = (g325).n; for (int64_t _k4060 = b0_1341; _k4060 < _e4060; _k4060++) { int64_t q_1368 = (int64_t)_k4060; if ((((((int64_t)(((*({ hrv *_t4061 = &(g325); int64_t _i4061 = q_1368; (S7*)_t4061->b + hr_ix(_i4061, _t4061->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:223"); }))).name_))) == (f199_upname(p_1363))) && ((((*({ hrv *_t4063 = &(g325); int64_t _i4063 = q_1368; (S7*)_t4063->b + hr_ix(_i4063, _t4063->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:223"); }))).ty_) < (((int32_t)0LL))))) { { int32_t *_t4064 = &(((*({ hrv *_t4065 = &(g325); int64_t _i4065 = q_1368; (S7*)_t4065->b + hr_ix(_i4065, _t4065->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:223"); }))).ty_); *_t4064 = ((int32_t)(dt_1367)); }
 }
 } } _bk4059:; 
 }
 }
 } } _bk4050:; 
bool ok_1369 = true; 
{ int64_t _e4067 = (g325).n; for (int64_t _k4067 = b0_1341; _k4067 < _e4067; _k4067++) { int64_t q_1370 = (int64_t)_k4067; if (((((*({ hrv *_t4068 = &(g325); int64_t _i4068 = q_1370; (S7*)_t4068->b + hr_ix(_i4068, _t4068->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:225"); }))).ty_) < (((int32_t)0LL)))) { if ((((bg_1340) >= (((int64_t)0LL))) && ((((int64_t)(((*({ hrv *_t4069 = &(g325); int64_t _i4069 = q_1370; (S7*)_t4069->b + hr_ix(_i4069, _t4069->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:225"); }))).name_))) == (bg_1340)))) { { int32_t *_t4070 = &(((*({ hrv *_t4071 = &(g325); int64_t _i4071 = q_1370; (S7*)_t4071->b + hr_ix(_i4071, _t4071->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:225"); }))).ty_); *_t4070 = ((int32_t)(g595)); }
 } else { ok_1369 = false;
 }
 }
 } } _bk4066:; 
if ((!(ok_1369))) { (void)(({ hrv *_v4072 = &(g325); int64_t _k4072 = ((int64_t)((int64_t)(g325).n - (int64_t)b0_1341)); if (_k4072 < 0 || _k4072 > _v4072->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:226"); _v4072->n -= _k4072; }));
continue;
 }
int64_t g0_1371 = (g508).n; 
{ int64_t _e4074 = (g325).n; for (int64_t _k4074 = b0_1341; _k4074 < _e4074; _k4074++) { int64_t q_1372 = (int64_t)_k4074; (void)(({ hrv *_v4075 = &(g508); S7 _x4075 = (*({ hrv *_t4076 = &(g325); int64_t _i4076 = q_1372; (S7*)_t4076->b + hr_ix(_i4076, _t4076->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:228"); })); S7 *_p4075 = (S7*)hr_grow(_v4075, 1, sizeof _x4075); *_p4075 = _x4075; _p4075; }));
 } } _bk4073:; 
int64_t fns_1373 = f110_ns_of(fnode_1336); 
int64_t worst_1374 = ((int64_t)0LL); 
{ int64_t _e4079 = an_1315; for (int64_t _k4079 = 0; _k4079 < _e4079; _k4079++) { int64_t j_1375 = (int64_t)_k4079; int64_t p_1376 = f90_kid(fnode_1336, j_1375); 
int64_t pt_1377 = ({ int64_t _r4081; if (((((*({ hrv *_t4082 = &(g721); int64_t _i4082 = p_1376; (S4*)_t4082->b + hr_ix(_i4082, _t4082->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:233"); }))).a_) >= (((int32_t)0LL)))) { _r4081 = f113_rtype(((int64_t)(((*({ hrv *_t4084 = &(g721); int64_t _i4084 = p_1376; (S4*)_t4084->b + hr_ix(_i4084, _t4084->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:233"); }))).a_)), fns_1373);  } else { _r4081 = f130_gb_find(f199_upname(p_1376));  } _r4081; }); 
int64_t r_1390 = f251_arg_rank(((int64_t)((*({ hrv *_t4088 = &(g327); int64_t _i4088 = ((int64_t)((int64_t)a0_1314 + (int64_t)j_1375)); (int32_t*)_t4088->b + hr_ix(_i4088, _t4088->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:234"); })))), ((int64_t)((*({ hrv *_t4089 = &(g421); int64_t _i4089 = ((int64_t)((int64_t)a0_1314 + (int64_t)j_1375)); (int32_t*)_t4089->b + hr_ix(_i4089, _t4089->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:234"); })))), pt_1377); 
if (((r_1390) < (((int64_t)0LL)))) { worst_1374 = ((int64_t)99LL);
{ goto _bk4078; }
 }
if (((r_1390) > (worst_1374))) { worst_1374 = r_1390;
 }
 } } _bk4078:; 
(void)(({ hrv *_v4090 = &(g508); int64_t _k4090 = ((int64_t)((int64_t)(g508).n - (int64_t)g0_1371)); if (_k4090 < 0 || _k4090 > _v4090->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:238"); _v4090->n -= _k4090; }));
if ((((worst_1374) < (((int64_t)2LL))) && (((gl_1342) >= (((int64_t)0LL))) || (((np_1337) > (((int64_t)0LL))) && f253_untyped_any(fnode_1336))))) { worst_1374 = f103_max(worst_1374, ((int64_t)1LL));
 }
if (((worst_1374) == (((int64_t)99LL)))) { (void)(({ hrv *_v4093 = &(g325); int64_t _k4093 = ((int64_t)((int64_t)(g325).n - (int64_t)b0_1341)); if (_k4093 < 0 || _k4093 > _v4093->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:240"); _v4093->n -= _k4093; }));
continue;
 }
bool user_1396 = (!(f254_is_std_node(fnode_1336))); 
if ((((worst_1374) < (bestr_1329)) || ((((worst_1374) == (bestr_1329)) && user_1396) && (!(bestuser_1333))))) { best_1328 = fnode_1336;
bestr_1329 = worst_1374;
bestb0_1330 = b0_1341;
bestbn_1331 = ((int64_t)((int64_t)(g325).n - (int64_t)b0_1341));
tie_1332 = false;
bestuser_1333 = user_1396;
 } else { if ((((worst_1374) == (bestr_1329)) && ((user_1396) == (bestuser_1333)))) { tie_1332 = true;
 }
 }
 } } _bk4003:; 
(void)(({ hrv *_v4095 = &(g324); int64_t _k4095 = ((int64_t)((int64_t)(g324).n - (int64_t)c0_1319)); if (_k4095 < 0 || _k4095 > _v4095->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:245"); _v4095->n -= _k4095; }));
if (((best_1328) < (((int64_t)0LL)))) { (void)(({ hrv *_v4096 = &(g325); int64_t _k4096 = ((int64_t)((int64_t)(g325).n - (int64_t)nb0_1334)); if (_k4096 < 0 || _k4096 > _v4096->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:246"); _v4096->n -= _k4096; }));
return (M96){ ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), nb0_1334, ((int64_t)0LL) };
 }
if ((tie_1332 && report_1318)) { hrv m_1397 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o4098 = &(m_1397); hr_fs(_o4098, hr_str("ambiguous call to ", 18)); hr_fs(_o4098, f10_nm(name_1312)); }));
(void)(f108_cerr(n_1311, hr_sl(m_1397)));
 }
if (((bestb0_1330) > (nb0_1334))) { { int64_t _e4102 = bestbn_1331; for (int64_t _k4102 = ((int64_t)0LL); _k4102 < _e4102; _k4102++) { int64_t q_1398 = (int64_t)_k4102; { S7 *_t4103 = &((*({ hrv *_t4104 = &(g325); int64_t _i4104 = ((int64_t)((int64_t)nb0_1334 + (int64_t)q_1398)); (S7*)_t4104->b + hr_ix(_i4104, _t4104->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:248"); }))); *_t4103 = (*({ hrv *_t4105 = &(g325); int64_t _i4105 = ((int64_t)((int64_t)bestb0_1330 + (int64_t)q_1398)); (S7*)_t4105->b + hr_ix(_i4105, _t4105->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:248"); })); }
 } } _bk4101:; 
 }
(void)(({ hrv *_v4106 = &(g325); int64_t _k4106 = ((int64_t)((int64_t)((int64_t)((int64_t)(g325).n - (int64_t)nb0_1334)) - (int64_t)bestbn_1331)); if (_k4106 < 0 || _k4106 > _v4106->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:249"); _v4106->n -= _k4106; }));
return (M96){ best_1328, nb0_1334, bestbn_1331 };
}
static void f248_cands_add(int64_t name_1320, int64_t ns_1321) {
M55 _t4107 = f117_split_q(name_1320); int64_t a_1322 = _t4107.r0; int64_t b_1323 = _t4107.r1; 
if (((a_1322) >= (((int64_t)0LL)))) { int64_t d_1324 = f107_dmap(name_1320); 
while (((d_1324) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4111 = &(g506); int64_t _i4111 = d_1324; (S5*)_t4111->b + hr_ix(_i4111, _t4111->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:197"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4112 = &(g324); int32_t _x4112 = ((int32_t)(d_1324)); int32_t *_p4112 = (int32_t*)hr_grow(_v4112, 1, sizeof _x4112); *_p4112 = _x4112; _p4112; }));
 }
d_1324 = ((int64_t)(((*({ hrv *_t4113 = &(g506); int64_t _i4113 = d_1324; (S5*)_t4113->b + hr_ix(_i4113, _t4113->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:197"); }))).next_));
 } _bk4110:; 
return;
 }
if (((a_1322) == (((int64_t)(0 - (uint64_t)(((int64_t)2LL))))))) { int64_t d_1325 = f107_dmap(b_1323); 
while (((d_1325) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4116 = &(g506); int64_t _i4116 = d_1325; (S5*)_t4116->b + hr_ix(_i4116, _t4116->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:198"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4117 = &(g324); int32_t _x4117 = ((int32_t)(d_1325)); int32_t *_p4117 = (int32_t*)hr_grow(_v4117, 1, sizeof _x4117); *_p4117 = _x4117; _p4117; }));
 }
d_1325 = ((int64_t)(((*({ hrv *_t4118 = &(g506); int64_t _i4118 = d_1325; (S5*)_t4118->b + hr_ix(_i4118, _t4118->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:198"); }))).next_));
 } _bk4115:; 
return;
 }
if (((ns_1321) >= (((int64_t)0LL)))) { int64_t d_1326 = f107_dmap(f98_qual(ns_1321, name_1320)); 
while (((d_1326) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4122 = &(g506); int64_t _i4122 = d_1326; (S5*)_t4122->b + hr_ix(_i4122, _t4122->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:199"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4123 = &(g324); int32_t _x4123 = ((int32_t)(d_1326)); int32_t *_p4123 = (int32_t*)hr_grow(_v4123, 1, sizeof _x4123); *_p4123 = _x4123; _p4123; }));
 }
d_1326 = ((int64_t)(((*({ hrv *_t4124 = &(g506); int64_t _i4124 = d_1326; (S5*)_t4124->b + hr_ix(_i4124, _t4124->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:199"); }))).next_));
 } _bk4121:; 
 }
int64_t d_1327 = f107_dmap(name_1320); 
while (((d_1327) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t4127 = &(g506); int64_t _i4127 = d_1327; (S5*)_t4127->b + hr_ix(_i4127, _t4127->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:201"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v4128 = &(g324); int32_t _x4128 = ((int32_t)(d_1327)); int32_t *_p4128 = (int32_t*)hr_grow(_v4128, 1, sizeof _x4128); *_p4128 = _x4128; _p4128; }));
 }
d_1327 = ((int64_t)(((*({ hrv *_t4129 = &(g506); int64_t _i4129 = d_1327; (S5*)_t4129->b + hr_ix(_i4129, _t4129->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:201"); }))).next_));
 } _bk4126:; 
}
static bool f249_match_ty(int64_t tn0_1350, int64_t t0_1351, int64_t g0_1352) {
if (((tn0_1350) < (((int64_t)0LL)))) { return true;
 }
S4 x_1353 = (*({ hrv *_t4130 = &(g721); int64_t _i4130 = tn0_1350; (S4*)_t4130->b + hr_ix(_i4130, _t4130->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:63"); })); 
int64_t k_1354 = ((int64_t)((x_1353).k_)); 
int64_t t_1355 = f182_deref(t0_1351); 
if (((k_1354) == (((int64_t)41LL)))) { if ((((x_1353).n_) == (((int32_t)0LL)))) { { int64_t _e4133 = (g325).n; for (int64_t _k4133 = g0_1352; _k4133 < _e4133; _k4133++) { int64_t i_1356 = (int64_t)_k4133; if (((((*({ hrv *_t4134 = &(g325); int64_t _i4134 = i_1356; (S7*)_t4134->b + hr_ix(_i4134, _t4134->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:67"); }))).name_) == ((x_1353).s_))) { if (((((*({ hrv *_t4135 = &(g325); int64_t _i4135 = i_1356; (S7*)_t4135->b + hr_ix(_i4135, _t4135->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:67"); }))).ty_) < (((int32_t)0LL)))) { { int32_t *_t4136 = &(((*({ hrv *_t4137 = &(g325); int64_t _i4137 = i_1356; (S7*)_t4137->b + hr_ix(_i4137, _t4137->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:67"); }))).ty_); *_t4136 = ((int32_t)(f239_deref_val(t_1355))); }
 }
return true;
 }
 } } _bk4132:; 
return true;
 }
if (((((*({ hrv *_t4139 = &(g568); int64_t _i4139 = t_1355; (S1*)_t4139->b + hr_ix(_i4139, _t4139->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).k_) == (((uint8_t)5LL)))) { int64_t si_1357 = ((int64_t)(((*({ hrv *_t4140 = &(g568); int64_t _i4140 = t_1355; (S1*)_t4140->b + hr_ix(_i4140, _t4140->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).a_)); 
if (((((*({ hrv *_t4141 = &(g571); int64_t _i4141 = si_1357; (S10*)_t4141->b + hr_ix(_i4141, _t4141->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).tn_) == ((x_1353).n_))) { { int32_t _e4143 = (x_1353).n_; for (int32_t _k4143 = 0; _k4143 < _e4143; _k4143++) { int32_t i_1358 = (int32_t)_k4143; (void)(f249_match_ty(f90_kid(tn0_1350, ((int64_t)(i_1358))), ((int64_t)((*({ hrv *_t4146 = &(g569); int64_t _i4146 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4147 = &(g571); int64_t _i4147 = si_1357; (S10*)_t4147->b + hr_ix(_i4147, _t4147->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); }))).ta_)) + (int64_t)((int64_t)(i_1358)))); (int32_t*)_t4146->b + hr_ix(_i4146, _t4146->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:70"); })))), g0_1352));
 } } _bk4142:; 
 }
 }
if (((((*({ hrv *_t4148 = &(g568); int64_t _i4148 = t_1355; (S1*)_t4148->b + hr_ix(_i4148, _t4148->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).k_) == (((uint8_t)6LL)))) { int64_t ei_1359 = ((int64_t)(((*({ hrv *_t4149 = &(g568); int64_t _i4149 = t_1355; (S1*)_t4149->b + hr_ix(_i4149, _t4149->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).a_)); 
if (((((*({ hrv *_t4150 = &(g573); int64_t _i4150 = ei_1359; (S8*)_t4150->b + hr_ix(_i4150, _t4150->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).tn_) == ((x_1353).n_))) { { int32_t _e4152 = (x_1353).n_; for (int32_t _k4152 = 0; _k4152 < _e4152; _k4152++) { int32_t i_1360 = (int32_t)_k4152; (void)(f249_match_ty(f90_kid(tn0_1350, ((int64_t)(i_1360))), ((int64_t)((*({ hrv *_t4155 = &(g569); int64_t _i4155 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4156 = &(g573); int64_t _i4156 = ei_1359; (S8*)_t4156->b + hr_ix(_i4156, _t4156->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); }))).ta_)) + (int64_t)((int64_t)(i_1360)))); (int32_t*)_t4155->b + hr_ix(_i4155, _t4155->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:71"); })))), g0_1352));
 } } _bk4151:; 
 }
 }
return true;
 }
if ((((k_1354) == (((int64_t)42LL))) || ((k_1354) == (((int64_t)43LL))))) { if ((((((*({ hrv *_t4157 = &(g568); int64_t _i4157 = t_1355; (S1*)_t4157->b + hr_ix(_i4157, _t4157->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t4158 = &(g568); int64_t _i4158 = t_1355; (S1*)_t4158->b + hr_ix(_i4158, _t4158->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).k_) == (((uint8_t)9LL))))) { return f249_match_ty(((int64_t)((x_1353).a_)), ((int64_t)(((*({ hrv *_t4160 = &(g568); int64_t _i4160 = t_1355; (S1*)_t4160->b + hr_ix(_i4160, _t4160->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).a_)), g0_1352);
 }
if (((((*({ hrv *_t4161 = &(g568); int64_t _i4161 = t_1355; (S1*)_t4161->b + hr_ix(_i4161, _t4161->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:74"); }))).k_) == (((uint8_t)18LL)))) { return f249_match_ty(((int64_t)((x_1353).a_)), g581, g0_1352);
 }
return true;
 }
if (((k_1354) == (((int64_t)44LL)))) { if (((((*({ hrv *_t4163 = &(g568); int64_t _i4163 = t0_1351; (S1*)_t4163->b + hr_ix(_i4163, _t4163->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:75"); }))).k_) == (((uint8_t)10LL)))) { return f249_match_ty(((int64_t)((x_1353).a_)), ((int64_t)(((*({ hrv *_t4165 = &(g568); int64_t _i4165 = t0_1351; (S1*)_t4165->b + hr_ix(_i4165, _t4165->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:75"); }))).a_)), g0_1352);
 }
return f249_match_ty(((int64_t)((x_1353).a_)), t_1355, g0_1352);
 }
if (((k_1354) == (((int64_t)48LL)))) { return f249_match_ty(((int64_t)((x_1353).a_)), t0_1351, g0_1352);
 }
return true;
}
static int64_t f250_pend_default(int64_t a_1365) {
int64_t k_1366 = ((int64_t)(((*({ hrv *_t4168 = &(g568); int64_t _i4168 = a_1365; (S1*)_t4168->b + hr_ix(_i4168, _t4168->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:254"); }))).k_)); 
return ({ int64_t _r4169; if (((k_1366) == (((int64_t)12LL)))) { _r4169 = g580;  } else { _r4169 = ({ int64_t _r4170; if (((k_1366) == (((int64_t)13LL)))) { _r4170 = g586;  } else { _r4170 = ({ int64_t _r4171; if (((k_1366) == (((int64_t)18LL)))) { _r4171 = g593;  } else { _r4171 = a_1365;  } _r4171; });  } _r4170; });  } _r4169; });
}
static int64_t f251_arg_rank(int64_t n_1378, int64_t a_1379, int64_t p_1380) {
if (((p_1380) < (((int64_t)0LL)))) { return ((int64_t)1LL);
 }
if (((a_1379) == (p_1380))) { return ((int64_t)0LL);
 }
int64_t ak_1381 = ((int64_t)(((*({ hrv *_t4172 = &(g568); int64_t _i4172 = a_1379; (S1*)_t4172->b + hr_ix(_i4172, _t4172->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:82"); }))).k_)); 
int64_t pk_1382 = ((int64_t)(((*({ hrv *_t4173 = &(g568); int64_t _i4173 = p_1380; (S1*)_t4173->b + hr_ix(_i4173, _t4173->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:82"); }))).k_)); 
if ((((pk_1382) == (((int64_t)0LL))) || ((ak_1381) == (((int64_t)0LL))))) { return ((int64_t)0LL);
 }
if (((((pk_1382) == (((int64_t)10LL))) && ((((*({ hrv *_t4174 = &(g568); int64_t _i4174 = p_1380; (S1*)_t4174->b + hr_ix(_i4174, _t4174->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:84"); }))).c_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4175 = &(g568); int64_t _i4175 = p_1380; (S1*)_t4175->b + hr_ix(_i4175, _t4175->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:84"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL))))) { int64_t tgt_1383 = ((int64_t)(((*({ hrv *_t4176 = &(g568); int64_t _i4176 = p_1380; (S1*)_t4176->b + hr_ix(_i4176, _t4176->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:84"); }))).a_)); 
if (((f182_deref(a_1379)) == (tgt_1383))) { return ((int64_t)0LL);
 }
if ((((ak_1381) == (((int64_t)12LL))) || ((ak_1381) == (((int64_t)13LL))))) { return f251_arg_rank(n_1378, a_1379, tgt_1383);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if ((((ak_1381) == (((int64_t)10LL))) && ((((*({ hrv *_t4179 = &(g568); int64_t _i4179 = a_1379; (S1*)_t4179->b + hr_ix(_i4179, _t4179->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).c_) < (((int32_t)0LL))))) { int64_t d_1384 = ((int64_t)(((*({ hrv *_t4180 = &(g568); int64_t _i4180 = a_1379; (S1*)_t4180->b + hr_ix(_i4180, _t4180->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).a_)); 
if (((d_1384) == (p_1380))) { return ((int64_t)0LL);
 }
if (((((pk_1382) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4181 = &(g568); int64_t _i4181 = p_1380; (S1*)_t4181->b + hr_ix(_i4181, _t4181->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && ((((*({ hrv *_t4182 = &(g568); int64_t _i4182 = p_1380; (S1*)_t4182->b + hr_ix(_i4182, _t4182->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).a_) == (((*({ hrv *_t4183 = &(g568); int64_t _i4183 = a_1379; (S1*)_t4183->b + hr_ix(_i4183, _t4183->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:85"); }))).a_)))) { return ((int64_t)0LL);
 }
return f251_arg_rank(n_1378, d_1384, p_1380);
 }
if (((ak_1381) == (((int64_t)12LL)))) { M78 _t4185 = f158_cval(n_1378); int64_t v_1385 = _t4185.r0; bool u_1386 = _t4185.r1; bool ok_1387 = _t4185.r2; 
if (((pk_1382) == (((int64_t)3LL)))) { if (((!(ok_1387)) || f161_int_fits(v_1385, u_1386, p_1380))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((pk_1382) == (((int64_t)4LL)))) { return ((int64_t)3LL);
 }
if (((pk_1382) == (((int64_t)17LL)))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1381) == (((int64_t)13LL)))) { if (((pk_1382) == (((int64_t)4LL)))) { return ({ int64_t _r4188; if (((((*({ hrv *_t4189 = &(g568); int64_t _i4189 = p_1380; (S1*)_t4189->b + hr_ix(_i4189, _t4189->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:93"); }))).s_) == (((uint8_t)8LL)))) { _r4188 = ((int64_t)1LL);  } else { _r4188 = ((int64_t)2LL);  } _r4188; });
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1381) == (((int64_t)18LL)))) { if ((((pk_1382) == (((int64_t)9LL))) && ((((int64_t)(((*({ hrv *_t4190 = &(g568); int64_t _i4190 = p_1380; (S1*)_t4190->b + hr_ix(_i4190, _t4190->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:94"); }))).a_))) == (g581)))) { return ((int64_t)0LL);
 }
if (f167_is_byte_arr(p_1380)) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1381) == (((int64_t)19LL)))) { if ((((pk_1382) == (((int64_t)8LL))) || ((pk_1382) == (((int64_t)9LL))))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1381) == (((int64_t)11LL)))) { if ((((pk_1382) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4192 = &(g568); int64_t _i4192 = p_1380; (S1*)_t4192->b + hr_ix(_i4192, _t4192->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:96"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { return ((int64_t)0LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((((pk_1382) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4193 = &(g568); int64_t _i4193 = p_1380; (S1*)_t4193->b + hr_ix(_i4193, _t4193->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:97"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && ((((int64_t)(((*({ hrv *_t4194 = &(g568); int64_t _i4194 = p_1380; (S1*)_t4194->b + hr_ix(_i4194, _t4194->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:97"); }))).a_))) == (a_1379)))) { return ((int64_t)0LL);
 }
if ((((ak_1381) == (((int64_t)3LL))) && ((pk_1382) == (((int64_t)4LL))))) { return ((int64_t)3LL);
 }
if (f155_widens(a_1379, p_1380)) { return ((int64_t)2LL);
 }
if (((((pk_1382) == (((int64_t)9LL))) && (((ak_1381) == (((int64_t)8LL))) || ((ak_1381) == (((int64_t)9LL))))) && ((((*({ hrv *_t4196 = &(g568); int64_t _i4196 = a_1379; (S1*)_t4196->b + hr_ix(_i4196, _t4196->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:100"); }))).a_) == (((*({ hrv *_t4197 = &(g568); int64_t _i4197 = p_1380; (S1*)_t4197->b + hr_ix(_i4197, _t4197->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:100"); }))).a_)))) { return ((int64_t)2LL);
 }
if (((((pk_1382) == (((int64_t)6LL))) && ((ak_1381) == (((int64_t)7LL)))) && ((((*({ hrv *_t4198 = &(g568); int64_t _i4198 = a_1379; (S1*)_t4198->b + hr_ix(_i4198, _t4198->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:101"); }))).a_) == (((*({ hrv *_t4199 = &(g568); int64_t _i4199 = p_1380; (S1*)_t4199->b + hr_ix(_i4199, _t4199->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:101"); }))).a_)))) { return ((int64_t)2LL);
 }
if ((((((pk_1382) == (((int64_t)8LL))) && (((ak_1381) == (((int64_t)8LL))) || ((ak_1381) == (((int64_t)9LL))))) && ((((*({ hrv *_t4200 = &(g568); int64_t _i4200 = a_1379; (S1*)_t4200->b + hr_ix(_i4200, _t4200->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:102"); }))).a_) == (((*({ hrv *_t4201 = &(g568); int64_t _i4201 = p_1380; (S1*)_t4201->b + hr_ix(_i4201, _t4201->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:102"); }))).a_))) && f252_is_construct(n_1378))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f252_is_construct(int64_t n_1388) {
int64_t k_1389 = ((int64_t)(((*({ hrv *_t4203 = &(g721); int64_t _i4203 = n_1388; (S4*)_t4203->b + hr_ix(_i4203, _t4203->n, "/home/anmire/ai/amni-lang/helium-self/hc/check.amni:195"); }))).k_)); 
return ((((k_1389) == (((int64_t)11LL))) || ((k_1389) == (((int64_t)16LL)))) || ((k_1389) == (((int64_t)3LL))));
}
static bool f253_untyped_any(int64_t f_1391) {
{ int32_t _e4205 = ((*({ hrv *_t4206 = &(g721); int64_t _i4206 = f_1391; (S4*)_t4206->b + hr_ix(_i4206, _t4206->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:252"); }))).n_; for (int32_t _k4205 = 0; _k4205 < _e4205; _k4205++) { int32_t j_1392 = (int32_t)_k4205; if (((((*({ hrv *_t4207 = &(g721); int64_t _i4207 = f90_kid(f_1391, ((int64_t)(j_1392))); (S4*)_t4207->b + hr_ix(_i4207, _t4207->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:252"); }))).a_) < (((int32_t)0LL)))) { return true;
 }
 } } _bk4204:; 
return false;
}
static bool f254_is_std_node(int64_t node_1393) {
int64_t f_1394 = f111_node_file(node_1393); 
L49 sp_1395 = f100_lib_path(hr_str("std", 3)); 
return hr_streq(f10_nm(((int64_t)(((*({ hrv *_t4212 = &(g930); int64_t _i4212 = f_1394; (S2*)_t4212->b + hr_ix(_i4212, _t4212->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:203"); }))).name_))), ({ hsl _t4213 = ({ L49 *_t4214 = &(sp_1395); (hsl){ (uint8_t*)_t4214->e, _t4214->n }; }); int64_t _l4213 = 0, _h4213 = _t4213.n; if (_l4213 < 0 || _h4213 < _l4213 || _h4213 > _t4213.n) hr_slerr(_l4213, _h4213, _t4213.n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:203"); (hsl){ _t4213.p + _l4213 * (int64_t)sizeof(uint8_t), _h4213 - _l4213 }; }));
}
static int64_t f255_get_inst(int64_t node_1404, int64_t b0_1405, int64_t bn_1406, int64_t blk_1407, int64_t bown_1408) {
int64_t par_1409 = ({ int64_t _r4215; if (((((uint16_t)((uint64_t)((*({ hrv *_t4216 = &(g721); int64_t _i4216 = node_1404; (S4*)_t4216->b + hr_ix(_i4216, _t4216->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:184"); }))).fl_ & (uint64_t)((uint16_t)128LL)))) != (((uint16_t)0LL)))) { _r4215 = g414;  } else { _r4215 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r4215; }); 
if (((blk_1407) < (((int64_t)0LL)))) { { hrv *_v4218 = &(g401); for (int64_t _k4218 = 0; _k4218 < _v4218->n; _k4218++) { S6 f_1410 = ((S6*)_v4218->b)[_k4218]; int64_t i_1411 = (int64_t)_k4218; if ((((((((int64_t)((f_1410).node_))) == (node_1404)) && (((f_1410).blk_) < (((int32_t)0LL)))) && ((((int64_t)((f_1410).par_))) == (par_1409))) && f256_same_binds(i_1411, b0_1405, bn_1406))) { return i_1411;
 }
 } } _bk4217:; 
 }
int64_t i_1416 = f105_new_inst(node_1404, node_1404, ((int64_t)((*({ hrv *_t4221 = &(g736); int64_t _i4221 = node_1404; (int32_t*)_t4221->b + hr_ix(_i4221, _t4221->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:186"); })))), par_1409); 
{ int32_t *_t4222 = &(((*({ hrv *_t4223 = &(g401); int64_t _i4223 = i_1416; (S6*)_t4223->b + hr_ix(_i4223, _t4223->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:187"); }))).g0_); *_t4222 = ((int32_t)((g407).n)); }
{ int64_t _e4225 = bn_1406; for (int64_t _k4225 = 0; _k4225 < _e4225; _k4225++) { int64_t j_1417 = (int64_t)_k4225; (void)(({ hrv *_v4226 = &(g407); S7 _x4226 = (*({ hrv *_t4227 = &(g325); int64_t _i4227 = ((int64_t)((int64_t)b0_1405 + (int64_t)j_1417)); (S7*)_t4227->b + hr_ix(_i4227, _t4227->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:188"); })); S7 *_p4226 = (S7*)hr_grow(_v4226, 1, sizeof _x4226); *_p4226 = _x4226; _p4226; }));
 } } _bk4224:; 
{ int32_t *_t4228 = &(((*({ hrv *_t4229 = &(g401); int64_t _i4229 = i_1416; (S6*)_t4229->b + hr_ix(_i4229, _t4229->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:189"); }))).gn_); *_t4228 = ((int32_t)(bn_1406)); }
{ int32_t *_t4230 = &(((*({ hrv *_t4231 = &(g401); int64_t _i4231 = i_1416; (S6*)_t4231->b + hr_ix(_i4231, _t4231->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:190"); }))).blk_); *_t4230 = ((int32_t)(blk_1407)); }
{ int32_t *_t4232 = &(((*({ hrv *_t4233 = &(g401); int64_t _i4233 = i_1416; (S6*)_t4233->b + hr_ix(_i4233, _t4233->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:190"); }))).bown_); *_t4232 = ((int32_t)(bown_1408)); }
(void)(f198_sig_inst(i_1416));
(void)(f212_check_inst(i_1416));
return i_1416;
}
static bool f256_same_binds(int64_t i_1412, int64_t b0_1413, int64_t bn_1414) {
if (((((int64_t)(((*({ hrv *_t4236 = &(g401); int64_t _i4236 = i_1412; (S6*)_t4236->b + hr_ix(_i4236, _t4236->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:179"); }))).gn_))) != (bn_1414))) { return false;
 }
{ int64_t _e4238 = bn_1414; for (int64_t _k4238 = 0; _k4238 < _e4238; _k4238++) { int64_t j_1415 = (int64_t)_k4238; if ((((((*({ hrv *_t4239 = &(g407); int64_t _i4239 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4240 = &(g401); int64_t _i4240 = i_1412; (S6*)_t4240->b + hr_ix(_i4240, _t4240->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:180"); }))).g0_)) + (int64_t)j_1415)); (S7*)_t4239->b + hr_ix(_i4239, _t4239->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:180"); }))).ty_) != (((*({ hrv *_t4241 = &(g325); int64_t _i4241 = ((int64_t)((int64_t)b0_1413 + (int64_t)j_1415)); (S7*)_t4241->b + hr_ix(_i4241, _t4241->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:180"); }))).ty_)) || ((((*({ hrv *_t4242 = &(g407); int64_t _i4242 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4243 = &(g401); int64_t _i4243 = i_1412; (S6*)_t4243->b + hr_ix(_i4243, _t4243->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:180"); }))).g0_)) + (int64_t)j_1415)); (S7*)_t4242->b + hr_ix(_i4242, _t4242->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:180"); }))).name_) != (((*({ hrv *_t4244 = &(g325); int64_t _i4244 = ((int64_t)((int64_t)b0_1413 + (int64_t)j_1415)); (S7*)_t4244->b + hr_ix(_i4244, _t4244->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:180"); }))).name_)))) { return false;
 }
 } } _bk4237:; 
return true;
}
static int64_t f257_call_fn(int64_t n_1450, int64_t name_1451, int64_t recv_1452, int64_t want_1453) {
int64_t s_1454 = f229_ck_args(n_1450, ((int64_t)0LL), recv_1452); 
int64_t an_1455 = ((int64_t)((int64_t)(g421).n - (int64_t)s_1454)); 
int64_t blk_1456 = ((int64_t)(((*({ hrv *_t4246 = &(g721); int64_t _i4246 = n_1450; (S4*)_t4246->b + hr_ix(_i4246, _t4246->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:393"); }))).b_)); 
M96 _t4247 = f247_resolve(n_1450, name_1451, f110_ns_of(n_1450), s_1454, an_1455, blk_1456, ((int64_t)(((*({ hrv *_t4250 = &(g721); int64_t _i4250 = n_1450; (S4*)_t4250->b + hr_ix(_i4250, _t4250->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:394"); }))).c_)), true); int64_t fnode_1457 = _t4247.r0; int64_t b0_1458 = _t4247.r1; int64_t bn_1459 = _t4247.r2; 
if (((fnode_1457) < (((int64_t)0LL)))) { hrv m_1460 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o4252 = &(m_1460); hr_fs(_o4252, hr_str("no function ", 12)); hr_fs(_o4252, f10_nm(name_1451)); hr_fs(_o4252, hr_str(" matches (", 10)); }));
{ int64_t _e4255 = an_1455; for (int64_t _k4255 = 0; _k4255 < _e4255; _k4255++) { int64_t j_1461 = (int64_t)_k4255; if (((j_1461) > (((int64_t)0LL)))) { (void)(({ hrv *_v4256 = &(m_1460); hsl _s4256 = hr_str(", ", 2); hr_append(_v4256, _s4256.p, _s4256.n, sizeof(uint8_t)); }));
 }
{ hrv _t4258 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_v4257 = &(m_1460); hsl _s4257 = hr_sl(*hr_tmp(&_t4258, f164_tn(((int64_t)((*({ hrv *_t4260 = &(g421); int64_t _i4260 = ((int64_t)((int64_t)s_1454 + (int64_t)j_1461)); (int32_t*)_t4260->b + hr_ix(_i4260, _t4260->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:397"); }))))))); hr_append(_v4257, _s4257.p, _s4257.n, sizeof(uint8_t)); }));
}
 } } _bk4254:; 
(void)(({ hrv *_v4261 = &(m_1460); hsl _s4261 = hr_str(")", 1); hr_append(_v4261, _s4261.p, _s4261.n, sizeof(uint8_t)); }));
(void)(f108_cerr(n_1450, hr_sl(m_1460)));
(void)(f230_pop_args(s_1454));
(void)(({ hrv *_v4264 = &(g325); int64_t _k4264 = ((int64_t)((int64_t)(g325).n - (int64_t)b0_1458)); if (_k4264 < 0 || _k4264 > _v4264->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:401"); _v4264->n -= _k4264; }));
return f138_set_t(n_1450, g592);
 }
int64_t inst_1462 = f255_get_inst(fnode_1457, b0_1458, bn_1459, blk_1456, g414); 
(void)(({ hrv *_v4267 = &(g325); int64_t _k4267 = ((int64_t)((int64_t)(g325).n - (int64_t)b0_1458)); if (_k4267 < 0 || _k4267 > _v4267->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:405"); _v4267->n -= _k4267; }));
{ int64_t _e4269 = an_1455; for (int64_t _k4269 = 0; _k4269 < _e4269; _k4269++) { int64_t j_1463 = (int64_t)_k4269; int64_t c_1464 = ((int64_t)((*({ hrv *_t4270 = &(g327); int64_t _i4270 = ((int64_t)((int64_t)s_1454 + (int64_t)j_1463)); (int32_t*)_t4270->b + hr_ix(_i4270, _t4270->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:406"); })))); 
int64_t pt_1465 = f213_ptype_of(inst_1462, j_1463); 
if ((((((pt_1465) >= (((int64_t)0LL))) && ((((*({ hrv *_t4272 = &(g568); int64_t _i4272 = pt_1465; (S1*)_t4272->b + hr_ix(_i4272, _t4272->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:406"); }))).k_) == (((uint8_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4273 = &(g568); int64_t _i4273 = pt_1465; (S1*)_t4273->b + hr_ix(_i4273, _t4273->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:406"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))) && ((((*({ hrv *_t4274 = &(g568); int64_t _i4274 = pt_1465; (S1*)_t4274->b + hr_ix(_i4274, _t4274->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:406"); }))).c_) < (((int32_t)0LL))))) { if (f166_is_pending(f141_at(c_1464))) { (void)(f140_conv(c_1464, ((int64_t)(((*({ hrv *_t4278 = &(g568); int64_t _i4278 = pt_1465; (S1*)_t4278->b + hr_ix(_i4278, _t4278->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:406"); }))).a_))));
 }
 } else { (void)(f140_conv(c_1464, pt_1465));
 }
 } } _bk4268:; 
(void)(f230_pop_args(s_1454));
(void)(f231_note_caps_of(inst_1462));
(void)(f232_note_edge(inst_1462));
(void)(f173_set_r(n_1450, ((int64_t)3LL), inst_1462));
int64_t rt_1466 = ((int64_t)(((*({ hrv *_t4284 = &(g401); int64_t _i4284 = inst_1462; (S6*)_t4284->b + hr_ix(_i4284, _t4284->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:410"); }))).ret_)); 
if (((((rt_1466) < (((int64_t)0LL))) && ((((*({ hrv *_t4285 = &(g401); int64_t _i4285 = inst_1462; (S6*)_t4285->b + hr_ix(_i4285, _t4285->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:411"); }))).st_) == (((uint8_t)1LL)))) && ((n_1450) == (g494)))) { return f138_set_t(n_1450, g575);
 }
if (((rt_1466) < (((int64_t)0LL)))) { if (((((*({ hrv *_t4287 = &(g401); int64_t _i4287 = inst_1462; (S6*)_t4287->b + hr_ix(_i4287, _t4287->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:412"); }))).st_) == (((uint8_t)1LL)))) { hrv m_1467 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o4289 = &(m_1467); hr_fs(_o4289, hr_str("recursive call to ", 18)); hr_fs(_o4289, f10_nm(name_1451)); hr_fs(_o4289, hr_str(" needs its result type written", 30)); }));
(void)(f108_cerr(n_1450, hr_sl(m_1467)));
 }
return f138_set_t(n_1450, g592);
 }
return f138_set_t(n_1450, rt_1466);
}
static int64_t f258_member_of(hsl name_1472) {
if (hr_streq(name_1472, hr_str("push", 4))) { return ((int64_t)20LL);
 }
if (hr_streq(name_1472, hr_str("append", 6))) { return ((int64_t)21LL);
 }
if (hr_streq(name_1472, hr_str("pop", 3))) { return ((int64_t)22LL);
 }
if (hr_streq(name_1472, hr_str("pop_n", 5))) { return ((int64_t)23LL);
 }
if (hr_streq(name_1472, hr_str("resize", 6))) { return ((int64_t)24LL);
 }
if (hr_streq(name_1472, hr_str("clear", 5))) { return ((int64_t)25LL);
 }
if (hr_streq(name_1472, hr_str("index_of", 8))) { return ((int64_t)26LL);
 }
if (hr_streq(name_1472, hr_str("len", 3))) { return ((int64_t)9LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f259_ck_slit(int64_t n_1475, int64_t want_1476) {
S4 x_1477 = (*({ hrv *_t4294 = &(g721); int64_t _i4294 = n_1475; (S4*)_t4294->b + hr_ix(_i4294, _t4294->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:466"); })); 
int64_t tnode_1478 = ((int64_t)((x_1477).a_)); 
int64_t ns_1479 = f110_ns_of(n_1475); 
int64_t t_1480 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((((*({ hrv *_t4296 = &(g721); int64_t _i4296 = tnode_1478; (S4*)_t4296->b + hr_ix(_i4296, _t4296->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:470"); }))).k_) == (((uint8_t)41LL))) && ((((*({ hrv *_t4297 = &(g721); int64_t _i4297 = tnode_1478; (S4*)_t4297->b + hr_ix(_i4297, _t4297->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:470"); }))).n_) == (((int32_t)0LL)))) && ((f130_gb_find(((int64_t)(((*({ hrv *_t4299 = &(g721); int64_t _i4299 = tnode_1478; (S4*)_t4299->b + hr_ix(_i4299, _t4299->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:470"); }))).s_)))) < (((int64_t)0LL))))) { int64_t d_1481 = f116_lookup_q(((int64_t)(((*({ hrv *_t4301 = &(g721); int64_t _i4301 = tnode_1478; (S4*)_t4301->b + hr_ix(_i4301, _t4301->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:471"); }))).s_)), ns_1479, ((int64_t)1LL)); 
if ((((d_1481) >= (((int64_t)0LL))) && ((((*({ hrv *_t4302 = &(g721); int64_t _i4302 = ((*({ hrv *_t4303 = &(g506); int64_t _i4303 = d_1481; (S5*)_t4303->b + hr_ix(_i4303, _t4303->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:472"); }))).node_; (S4*)_t4302->b + hr_ix(_i4302, _t4302->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:472"); }))).d_) >= (((int32_t)0LL))))) { if (((((want_1476) >= (((int64_t)0LL))) && ((((*({ hrv *_t4304 = &(g568); int64_t _i4304 = want_1476; (S1*)_t4304->b + hr_ix(_i4304, _t4304->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:472"); }))).k_) == (((uint8_t)5LL)))) && ((((*({ hrv *_t4305 = &(g571); int64_t _i4305 = ((*({ hrv *_t4306 = &(g568); int64_t _i4306 = want_1476; (S1*)_t4306->b + hr_ix(_i4306, _t4306->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:472"); }))).a_; (S10*)_t4305->b + hr_ix(_i4305, _t4305->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:472"); }))).node_) == (((*({ hrv *_t4307 = &(g506); int64_t _i4307 = d_1481; (S5*)_t4307->b + hr_ix(_i4307, _t4307->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:472"); }))).node_)))) { t_1480 = want_1476;
 }
 }
 }
if (((t_1480) < (((int64_t)0LL)))) { t_1480 = f113_rtype(tnode_1478, ns_1479);
 }
int64_t si_1482 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((*({ hrv *_t4309 = &(g568); int64_t _i4309 = t_1480; (S1*)_t4309->b + hr_ix(_i4309, _t4309->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:476"); }))).k_) == (((uint8_t)5LL)))) { si_1482 = ((int64_t)(((*({ hrv *_t4310 = &(g568); int64_t _i4310 = t_1480; (S1*)_t4310->b + hr_ix(_i4310, _t4310->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:476"); }))).a_));
 }
if (((((*({ hrv *_t4311 = &(g568); int64_t _i4311 = t_1480; (S1*)_t4311->b + hr_ix(_i4311, _t4311->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:477"); }))).k_) == (((uint8_t)7LL)))) { si_1482 = ((int64_t)(((*({ hrv *_t4312 = &(g574); int64_t _i4312 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4313 = &(g573); int64_t _i4313 = ((*({ hrv *_t4314 = &(g568); int64_t _i4314 = t_1480; (S1*)_t4314->b + hr_ix(_i4314, _t4314->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:477"); }))).a_; (S8*)_t4313->b + hr_ix(_i4313, _t4313->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:477"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t4315 = &(g568); int64_t _i4315 = t_1480; (S1*)_t4315->b + hr_ix(_i4315, _t4315->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:477"); }))).c_)))); (S9*)_t4312->b + hr_ix(_i4312, _t4312->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:477"); }))).si_));
 }
if (((si_1482) < (((int64_t)0LL)))) { if (((((*({ hrv *_t4316 = &(g568); int64_t _i4316 = t_1480; (S1*)_t4316->b + hr_ix(_i4316, _t4316->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:478"); }))).k_) != (((uint8_t)0LL)))) { (void)(f108_cerr(n_1475, hr_str("not a struct type", 17)));
 }
return f138_set_t(n_1475, g592);
 }
{ int32_t _e4320 = (x_1477).n_; for (int32_t _k4320 = 0; _k4320 < _e4320; _k4320++) { int32_t i_1483 = (int32_t)_k4320; if (((((int64_t)(((*({ hrv *_t4321 = &(g721); int64_t _i4321 = f90_kid(n_1475, ((int64_t)(i_1483))); (S4*)_t4321->b + hr_ix(_i4321, _t4321->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:479"); }))).k_))) == (((int64_t)37LL)))) { (void)(f108_cerr(f90_kid(n_1475, ((int64_t)(i_1483))), hr_str("const for is not supported by the self-hosted compiler yet", 58)));
return f138_set_t(n_1475, g592);
 }
 } } _bk4319:; 
int64_t nf_1484 = ((int64_t)(((*({ hrv *_t4326 = &(g571); int64_t _i4326 = si_1482; (S10*)_t4326->b + hr_ix(_i4326, _t4326->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:480"); }))).fnum_)); 
bool named_1485 = ((((x_1477).n_) > (((int32_t)0LL))) && ((((*({ hrv *_t4327 = &(g721); int64_t _i4327 = f90_kid(n_1475, ((int64_t)0LL)); (S4*)_t4327->b + hr_ix(_i4327, _t4327->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:481"); }))).s_) >= (((int32_t)0LL)))); 
int64_t fpos_1486 = ((int64_t)0LL); 
{ int32_t _e4330 = (x_1477).n_; for (int32_t _k4330 = 0; _k4330 < _e4330; _k4330++) { int32_t i_1487 = (int32_t)_k4330; int64_t fi_1488 = f90_kid(n_1475, ((int64_t)(i_1487))); 
int64_t idx_1489 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (named_1485) { idx_1489 = f190_sfield(si_1482, ((int64_t)(((*({ hrv *_t4333 = &(g721); int64_t _i4333 = fi_1488; (S4*)_t4333->b + hr_ix(_i4333, _t4333->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:486"); }))).s_)));
if (((idx_1489) < (((int64_t)0LL)))) { hrv m_1490 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t4338 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o4335 = &(m_1490); hr_fs(_o4335, hr_str("no field ", 9)); hr_fs(_o4335, f10_nm(((int64_t)(((*({ hrv *_t4337 = &(g721); int64_t _i4337 = fi_1488; (S4*)_t4337->b + hr_ix(_i4337, _t4337->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:486"); }))).s_)))); hr_fs(_o4335, hr_str(" in ", 4)); hr_fs(_o4335, hr_sl(*hr_tmp(&_t4338, f164_tn(t_1480)))); }));
}
(void)(f108_cerr(fi_1488, hr_sl(m_1490)));
continue;
 }
 } else { while ((((fpos_1486) < (nf_1484)) && ((((*({ hrv *_t4342 = &(g572); int64_t _i4342 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4343 = &(g571); int64_t _i4343 = si_1482; (S10*)_t4343->b + hr_ix(_i4343, _t4343->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:487"); }))).f0_)) + (int64_t)fpos_1486)); (S11*)_t4342->b + hr_ix(_i4342, _t4342->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:487"); }))).ty_) < (((int32_t)0LL))))) { fpos_1486++;
 } _bk4341:; 
idx_1489 = fpos_1486;
fpos_1486++;
if (((idx_1489) >= (nf_1484))) { (void)(f108_cerr(fi_1488, hr_str("too many initializers", 21)));
continue;
 }
 }
int64_t ft_1491 = ((int64_t)(((*({ hrv *_t4345 = &(g572); int64_t _i4345 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4346 = &(g571); int64_t _i4346 = si_1482; (S10*)_t4346->b + hr_ix(_i4346, _t4346->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:488"); }))).f0_)) + (int64_t)idx_1489)); (S11*)_t4345->b + hr_ix(_i4345, _t4345->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:488"); }))).ty_)); 
(void)(f173_set_r(fi_1488, ((int64_t)5LL), idx_1489));
int64_t v_1492 = ((int64_t)(((*({ hrv *_t4348 = &(g721); int64_t _i4348 = fi_1488; (S4*)_t4348->b + hr_ix(_i4348, _t4348->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:490"); }))).a_)); 
(void)(f137_ck(v_1492, ft_1491));
(void)(f140_conv(v_1492, ft_1491));
 } } _bk4329:; 
{ int64_t _e4352 = nf_1484; for (int64_t _k4352 = 0; _k4352 < _e4352; _k4352++) { int64_t j_1493 = (int64_t)_k4352; S11 f_1494 = (*({ hrv *_t4353 = &(g572); int64_t _i4353 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4354 = &(g571); int64_t _i4354 = si_1482; (S10*)_t4354->b + hr_ix(_i4354, _t4354->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:494"); }))).f0_)) + (int64_t)j_1493)); (S11*)_t4353->b + hr_ix(_i4353, _t4353->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:494"); })); 
if ((((f_1494).ty_) < (((int32_t)0LL)))) { continue;
 }
bool given_1495 = false; 
{ int32_t _e4356 = (x_1477).n_; for (int32_t _k4356 = 0; _k4356 < _e4356; _k4356++) { int32_t i_1496 = (int32_t)_k4356; if (((f160_rv(f90_kid(n_1475, ((int64_t)(i_1496))))) == (j_1493))) { given_1495 = true;
 }
 } } _bk4355:; 
if (((!(given_1495)) && (((f_1494).def_) >= (((int32_t)0LL))))) { int64_t sa_1497 = g414; 
g414 = g416;
(void)(f137_ck(((int64_t)((f_1494).def_)), ((int64_t)((f_1494).ty_))));
(void)(f140_conv(((int64_t)((f_1494).def_)), ((int64_t)((f_1494).ty_))));
g414 = sa_1497;
 }
if (((((!(given_1495)) && (((f_1494).def_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)(x_1477).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) && (!(f168_is_opt(((int64_t)((f_1494).ty_))))))) { hrv m_1498 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t4365 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o4363 = &(m_1498); hr_fs(_o4363, hr_str("missing field ", 14)); hr_fs(_o4363, f10_nm(((int64_t)((f_1494).name_)))); hr_fs(_o4363, hr_str(" in ", 4)); hr_fs(_o4363, hr_sl(*hr_tmp(&_t4365, f164_tn(t_1480)))); }));
}
(void)(f108_cerr(n_1475, hr_sl(m_1498)));
 }
 } } _bk4351:; 
(void)(f173_set_r(n_1475, ((int64_t)9LL), si_1482));
return f138_set_t(n_1475, t_1480);
}
static bool f260_ORD_HAS(int64_t d_1500) {
{ hrv *_v4371 = &(g422); for (int64_t _k4371 = 0; _k4371 < _v4371->n; _k4371++) { int32_t o_1501 = ((int32_t*)_v4371->b)[_k4371]; if (((((int64_t)(o_1501))) == (d_1500))) { return true;
 }
 } } _bk4370:; 
return false;
}
static void f261_propagate_calls(void) {
bool changed_1505 = true; 
while (changed_1505) { changed_1505 = false;
{ hrv *_v4374 = &(g406); for (int64_t _k4374 = 0; _k4374 < _v4374->n; _k4374++) { S15 e_1506 = ((S15*)_v4374->b)[_k4374]; int64_t cr_1507 = ((int64_t)((e_1506).caller_)); 
int64_t ce_1508 = ((int64_t)((e_1506).callee_)); 
if ((((*({ hrv *_t4375 = &(g401); int64_t _i4375 = ce_1508; (S6*)_t4375->b + hr_ix(_i4375, _t4375->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:42"); }))).lr_ && (!(((*({ hrv *_t4376 = &(g401); int64_t _i4376 = cr_1507; (S6*)_t4376->b + hr_ix(_i4376, _t4376->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:42"); }))).lr_)))) { { bool *_t4377 = &(((*({ hrv *_t4378 = &(g401); int64_t _i4378 = cr_1507; (S6*)_t4378->b + hr_ix(_i4378, _t4378->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:42"); }))).lr_); *_t4377 = true; }
changed_1505 = true;
 }
{ hrv *_v4380 = &(g405); for (int64_t _k4380 = 0; _k4380 < _v4380->n; _k4380++) { S13 c_1509 = ((S13*)_v4380->b)[_k4380]; if (((((int64_t)((c_1509).inst_))) == (ce_1508))) { int64_t v_1510 = ((int64_t)((c_1509).lv_)); 
if ((f172_visible_in(((int64_t)(((*({ hrv *_t4382 = &(g402); int64_t _i4382 = v_1510; (S12*)_t4382->b + hr_ix(_i4382, _t4382->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:43"); }))).own_)), cr_1507) || ((((int64_t)(((*({ hrv *_t4383 = &(g402); int64_t _i4383 = v_1510; (S12*)_t4383->b + hr_ix(_i4383, _t4383->n, "/home/anmire/ai/amni-lang/helium-self/hc/calls.amni:43"); }))).cfn_))) != (cr_1507)))) { if (f175_add_cap_one(cr_1507, v_1510)) { changed_1505 = true;
 }
 }
 }
 } } _bk4379:; 
 } } _bk4373:; 
 } _bk4372:; 
}
static bool f262_gen_program(hrv* out_1512) {
(void)(({ hrv *_v4385 = &(g163); _v4385->n = 0; }));
{ hrv *_v4387 = &(g401); for (int64_t _k4387 = 0; _k4387 < _v4387->n; _k4387++) { S6 f_1513 = ((S6*)_v4387->b)[_k4387]; int64_t i_1514 = (int64_t)_k4387; if ((((f_1513).tg_ && (((f_1513).ret_) >= (((int32_t)0LL)))) && ((((int64_t)((f_1513).ret_))) != (g575)))) { int64_t sv_1515 = (g163).n; 
(void)(f263_ow(hr_str("static __thread ", 16)));
(void)(f264_ct(((int64_t)((f_1513).ret_))));
(void)(({ hrv *_o4390 = &(g163); hr_fs(_o4390, hr_str(" _lrv", 5)); hr_fi(_o4390, i_1514); hr_fs(_o4390, hr_str(";\012", 2)); }));
(void)(({ hrv *_v4391 = &(g167); hsl _s4391 = ({ hsl _t4392 = hr_sl(g163); int64_t _l4392 = sv_1515, _h4392 = _t4392.n; if (_l4392 < 0 || _h4392 < _l4392 || _h4392 > _t4392.n) hr_slerr(_l4392, _h4392, _t4392.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1185"); (hsl){ _t4392.p + _l4392 * (int64_t)sizeof(uint8_t), _h4392 - _l4392 }; }); hr_append(_v4391, _s4391.p, _s4391.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4393 = &(g163); int64_t _k4393 = sv_1515; if (_k4393 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1185"); hr_resize(_v4393, _k4393, sizeof(uint8_t)); }));
 }
 } } _bk4386:; 
{ hrv *_v4395 = &(g422); for (int64_t _k4395 = 0; _k4395 < _v4395->n; _k4395++) { int32_t d_1556 = ((int32_t*)_v4395->b)[_k4395]; int64_t di_1557 = ((int64_t)(d_1556)); 
int64_t t_1558 = ((int64_t)((*({ hrv *_t4396 = &(g464); int64_t _i4396 = di_1557; (int32_t*)_t4396->b + hr_ix(_i4396, _t4396->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1188"); })))); 
int64_t g_1559 = ((int64_t)(((*({ hrv *_t4397 = &(g506); int64_t _i4397 = di_1557; (S5*)_t4397->b + hr_ix(_i4397, _t4397->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1189"); }))).node_)); 
if ((((f176_const_of(di_1557)) >= (((int64_t)0LL))) && ((((*({ hrv *_t4399 = &(g568); int64_t _i4399 = t_1558; (S1*)_t4399->b + hr_ix(_i4399, _t4399->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1190"); }))).k_) == (((uint8_t)12LL))))) { continue;
 }
int64_t sv_1560 = (g163).n; 
g414 = g416;
g179 = g416;
(void)(f263_ow(hr_str("static ", 7)));
(void)(f264_ct(t_1558));
(void)(({ hrv *_o4402 = &(g163); hr_fs(_o4402, hr_str(" g", 2)); hr_fi(_o4402, di_1557); hr_fs(_o4402, hr_str(";\012", 2)); }));
(void)(({ hrv *_v4403 = &(g167); hsl _s4403 = ({ hsl _t4404 = hr_sl(g163); int64_t _l4404 = sv_1560, _h4404 = _t4404.n; if (_l4404 < 0 || _h4404 < _l4404 || _h4404 > _t4404.n) hr_slerr(_l4404, _h4404, _t4404.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1194"); (hsl){ _t4404.p + _l4404 * (int64_t)sizeof(uint8_t), _h4404 - _l4404 }; }); hr_append(_v4403, _s4403.p, _s4403.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4405 = &(g163); int64_t _k4405 = sv_1560; if (_k4405 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1194"); hr_resize(_v4405, _k4405, sizeof(uint8_t)); }));
S4 x_1561 = (*({ hrv *_t4406 = &(g721); int64_t _i4406 = g_1559; (S4*)_t4406->b + hr_ix(_i4406, _t4406->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1195"); })); 
if ((((x_1561).b_) >= (((int32_t)0LL)))) { int64_t iv_1562 = f90_kid(((int64_t)((x_1561).b_)), ((int64_t)0LL)); 
int64_t sp_1563 = (g163).n; 
(void)(({ hrv *_o4408 = &(g163); hr_fs(_o4408, hr_str("g", 1)); hr_fi(_o4408, di_1557); hr_fs(_o4408, hr_str(" = ", 3)); }));
if (f271_is_res(t_1558)) { (void)(f272_gxo(iv_1562));
 } else { (void)(f297_gx(iv_1562));
 }
(void)(f263_ow(hr_str(";\012", 2)));
if ((((g176).n) > (((int64_t)0LL)))) { (void)(({ hrv *_v4413 = &(g177); _v4413->n = 0; }));
(void)(({ hrv *_v4414 = &(g177); hsl _s4414 = ({ hsl _t4415 = hr_sl(g163); int64_t _l4415 = sp_1563, _h4415 = _t4415.n; if (_l4415 < 0 || _h4415 < _l4415 || _h4415 > _t4415.n) hr_slerr(_l4415, _h4415, _t4415.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1202"); (hsl){ _t4415.p + _l4415 * (int64_t)sizeof(uint8_t), _h4415 - _l4415 }; }); hr_append(_v4414, _s4414.p, _s4414.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4416 = &(g163); int64_t _k4416 = sp_1563; if (_k4416 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1202"); hr_resize(_v4416, _k4416, sizeof(uint8_t)); }));
(void)(f263_ow(hr_str("{ ", 2)));
(void)(({ hrv *_v4418 = &(g163); hsl _s4418 = ({ hsl _t4419 = hr_sl(g176); int64_t _l4419 = 0, _h4419 = _t4419.n; if (_l4419 < 0 || _h4419 < _l4419 || _h4419 > _t4419.n) hr_slerr(_l4419, _h4419, _t4419.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1202"); (hsl){ _t4419.p + _l4419 * (int64_t)sizeof(uint8_t), _h4419 - _l4419 }; }); hr_append(_v4418, _s4418.p, _s4418.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4420 = &(g176); _v4420->n = 0; }));
(void)(({ hrv *_v4421 = &(g163); hsl _s4421 = ({ hsl _t4422 = hr_sl(g177); int64_t _l4422 = 0, _h4422 = _t4422.n; if (_l4422 < 0 || _h4422 < _l4422 || _h4422 > _t4422.n) hr_slerr(_l4422, _h4422, _t4422.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1202"); (hsl){ _t4422.p + _l4422 * (int64_t)sizeof(uint8_t), _h4422 - _l4422 }; }); hr_append(_v4421, _s4421.p, _s4421.n, sizeof(uint8_t)); }));
(void)(f263_ow(hr_str("}\012", 2)));
 }
(void)(({ hrv *_v4424 = &(g168); hsl _s4424 = ({ hsl _t4425 = hr_sl(g163); int64_t _l4425 = sp_1563, _h4425 = _t4425.n; if (_l4425 < 0 || _h4425 < _l4425 || _h4425 > _t4425.n) hr_slerr(_l4425, _h4425, _t4425.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1203"); (hsl){ _t4425.p + _l4425 * (int64_t)sizeof(uint8_t), _h4425 - _l4425 }; }); hr_append(_v4424, _s4424.p, _s4424.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4426 = &(g163); int64_t _k4426 = sp_1563; if (_k4426 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1203"); hr_resize(_v4426, _k4426, sizeof(uint8_t)); }));
 }
 } } _bk4394:; 
int64_t mi_2136 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v4428 = &(g401); for (int64_t _k4428 = 0; _k4428 < _v4428->n; _k4428++) { S6 f_2137 = ((S6*)_v4428->b)[_k4428]; int64_t i_2138 = (int64_t)_k4428; if (((((f_2137).node_) < (((int32_t)0LL))) || (((f_2137).st_) != (((uint8_t)2LL))))) { continue;
 }
int64_t node_2139 = ((int64_t)((f_2137).node_)); 
if ((((((*({ hrv *_t4429 = &(g721); int64_t _i4429 = node_2139; (S4*)_t4429->b + hr_ix(_i4429, _t4429->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1210"); }))).k_) != (((uint8_t)50LL))) || ((((uint16_t)((uint64_t)((*({ hrv *_t4430 = &(g721); int64_t _i4430 = node_2139; (S4*)_t4430->b + hr_ix(_i4430, _t4430->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1210"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))))) { continue;
 }
if (((((f_2137).par_) < (((int32_t)0LL))) && hr_streq(f10_nm(((int64_t)((f_2137).name_))), hr_str("main", 4)))) { mi_2136 = i_2138;
 }
(void)(f374_gen_fn(i_2138));
if ((((g182).n) > (((int64_t)0LL)))) { return false;
 }
 } } _bk4427:; 
(void)(({ hrv *_v4433 = out_1512; hsl _s4433 = hr_str("#include \"hrt.h\"\012", 17); hr_append(_v4433, _s4433.p, _s4433.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4434 = out_1512; hsl _s4434 = hr_sl(g164); hr_append(_v4434, _s4434.p, _s4434.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4435 = out_1512; hsl _s4435 = hr_str("#pragma pack(push, 1)\012", 22); hr_append(_v4435, _s4435.p, _s4435.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4436 = out_1512; hsl _s4436 = hr_sl(g165); hr_append(_v4436, _s4436.p, _s4436.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4437 = out_1512; hsl _s4437 = hr_str("#pragma pack(pop)\012", 18); hr_append(_v4437, _s4437.p, _s4437.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4438 = out_1512; hsl _s4438 = hr_sl(g166); hr_append(_v4438, _s4438.p, _s4438.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4439 = out_1512; hsl _s4439 = hr_sl(g167); hr_append(_v4439, _s4439.p, _s4439.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4440 = out_1512; hsl _s4440 = ({ hsl _t4441 = hr_sl(g169); int64_t _l4441 = 0, _h4441 = _t4441.n; if (_l4441 < 0 || _h4441 < _l4441 || _h4441 > _t4441.n) hr_slerr(_l4441, _h4441, _t4441.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1222"); (hsl){ _t4441.p + _l4441 * (int64_t)sizeof(uint8_t), _h4441 - _l4441 }; }); hr_append(_v4440, _s4440.p, _s4440.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4442 = out_1512; hsl _s4442 = ({ hsl _t4443 = hr_sl(g163); int64_t _l4443 = 0, _h4443 = _t4443.n; if (_l4443 < 0 || _h4443 < _l4443 || _h4443 > _t4443.n) hr_slerr(_l4443, _h4443, _t4443.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1223"); (hsl){ _t4443.p + _l4443 * (int64_t)sizeof(uint8_t), _h4443 - _l4443 }; }); hr_append(_v4442, _s4442.p, _s4442.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4444 = out_1512; hsl _s4444 = hr_str("static void hr_init_globals(void) {\012", 36); hr_append(_v4444, _s4444.p, _s4444.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4445 = out_1512; hsl _s4445 = hr_sl(g168); hr_append(_v4445, _s4445.p, _s4445.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4446 = out_1512; hsl _s4446 = hr_str("}\012", 2); hr_append(_v4446, _s4446.p, _s4446.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4447 = out_1512; hsl _s4447 = hr_str("static void hr_main(void) { ", 28); hr_append(_v4447, _s4447.p, _s4447.n, sizeof(uint8_t)); }));
if (((mi_2136) >= (((int64_t)0LL)))) { int64_t rt_2165 = ((int64_t)(((*({ hrv *_t4448 = &(g401); int64_t _i4448 = mi_2136; (S6*)_t4448->b + hr_ix(_i4448, _t4448->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1226"); }))).ret_)); 
if ((((rt_2165) >= (((int64_t)0LL))) && ((((*({ hrv *_t4449 = &(g568); int64_t _i4449 = rt_2165; (S1*)_t4449->b + hr_ix(_i4449, _t4449->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1226"); }))).k_) == (((uint8_t)3LL))))) { (void)(({ hrv *_v4450 = out_1512; hsl _s4450 = hr_str("hr_flush(); exit((int)", 22); hr_append(_v4450, _s4450.p, _s4450.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4451 = &(g163); _v4451->n = 0; }));
(void)(f332_fn_cname(mi_2136));
(void)(({ hrv *_v4453 = out_1512; hsl _s4453 = ({ hsl _t4454 = hr_sl(g163); int64_t _l4454 = 0, _h4454 = _t4454.n; if (_l4454 < 0 || _h4454 < _l4454 || _h4454 > _t4454.n) hr_slerr(_l4454, _h4454, _t4454.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1226"); (hsl){ _t4454.p + _l4454 * (int64_t)sizeof(uint8_t), _h4454 - _l4454 }; }); hr_append(_v4453, _s4453.p, _s4453.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4455 = out_1512; hsl _s4455 = hr_str("()", 2); hr_append(_v4455, _s4455.p, _s4455.n, sizeof(uint8_t)); }));
if ((((rt_2165) >= (((int64_t)0LL))) && ((((*({ hrv *_t4456 = &(g568); int64_t _i4456 = rt_2165; (S1*)_t4456->b + hr_ix(_i4456, _t4456->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1226"); }))).k_) == (((uint8_t)3LL))))) { (void)(({ hrv *_v4457 = out_1512; hsl _s4457 = hr_str(")", 1); hr_append(_v4457, _s4457.p, _s4457.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4458 = out_1512; hsl _s4458 = hr_str("; ", 2); hr_append(_v4458, _s4458.p, _s4458.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4459 = out_1512; hsl _s4459 = hr_str("}\012", 2); hr_append(_v4459, _s4459.p, _s4459.n, sizeof(uint8_t)); }));
return (((g182).n) == (((int64_t)0LL)));
}
static void f263_ow(hsl s_1516) {
(void)(({ hrv *_v4460 = &(g163); hsl _s4460 = s_1516; hr_append(_v4460, _s4460.p, _s4460.n, sizeof(uint8_t)); }));
}
static void f264_ct(int64_t t_1517) {
(void)(f265_cbody(t_1517));
(void)(f263_ow(f267_cn(t_1517)));
}
static void f265_cbody(int64_t t_1518) {
(void)(f266_cn_grow());
S1 x_1519 = (*({ hrv *_t4465 = &(g568); int64_t _i4465 = t_1518; (S1*)_t4465->b + hr_ix(_i4465, _t4465->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:57"); })); 
int64_t k_1520 = ((int64_t)((x_1519).k_)); 
if ((((k_1520) == (((int64_t)10LL))) || (((*({ hrv *_t4466 = &(g173); int64_t _i4466 = t_1518; (uint8_t*)_t4466->b + hr_ix(_i4466, _t4466->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:58"); }))) != (((uint8_t)0LL))))) { (void)(f267_cn(t_1518));
return;
 }
{ uint8_t *_t4468 = &((*({ hrv *_t4469 = &(g173); int64_t _i4469 = t_1518; (uint8_t*)_t4469->b + hr_ix(_i4469, _t4469->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:59"); }))); *_t4468 = ((uint8_t)1LL); }
(void)(f267_cn(t_1518));
if (((k_1520) == (((int64_t)7LL)))) { S9 v_1534 = (*({ hrv *_t4471 = &(g574); int64_t _i4471 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4472 = &(g573); int64_t _i4472 = (x_1519).a_; (S8*)_t4472->b + hr_ix(_i4472, _t4472->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:61"); }))).v0_)) + (int64_t)((int64_t)((x_1519).c_)))); (S9*)_t4471->b + hr_ix(_i4471, _t4471->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:61"); })); 
if ((((v_1534).si_) >= (((int32_t)0LL)))) { (void)(f265_cbody(f134_t_struct(((int64_t)((v_1534).si_)))));
 }
return;
 }
if (((k_1520) == (((int64_t)5LL)))) { int64_t si_1535 = ((int64_t)((x_1519).a_)); 
(void)(f147_si_layout(si_1535));
int64_t f0_1536 = ((int64_t)(((*({ hrv *_t4476 = &(g571); int64_t _i4476 = si_1535; (S10*)_t4476->b + hr_ix(_i4476, _t4476->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:64"); }))).f0_)); 
int64_t fnum_1537 = ((int64_t)(((*({ hrv *_t4477 = &(g571); int64_t _i4477 = si_1535; (S10*)_t4477->b + hr_ix(_i4477, _t4477->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:64"); }))).fnum_)); 
{ int64_t _e4479 = fnum_1537; for (int64_t _k4479 = 0; _k4479 < _e4479; _k4479++) { int64_t i_1538 = (int64_t)_k4479; int32_t ft_1539 = ((*({ hrv *_t4480 = &(g572); int64_t _i4480 = ((int64_t)((int64_t)f0_1536 + (int64_t)i_1538)); (S11*)_t4480->b + hr_ix(_i4480, _t4480->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:65"); }))).ty_; 
if (((ft_1539) >= (((int32_t)0LL)))) { (void)(f265_cbody(((int64_t)(ft_1539))));
 }
 } } _bk4478:; 
(void)(({ hrv *_v4482 = &(g165); hsl _s4482 = hr_str("struct ", 7); hr_append(_v4482, _s4482.p, _s4482.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4483 = &(g165); hsl _s4483 = f267_cn(t_1518); hr_append(_v4483, _s4483.p, _s4483.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4485 = &(g165); hsl _s4485 = hr_str(" { ", 3); hr_append(_v4485, _s4485.p, _s4485.n, sizeof(uint8_t)); }));
bool any_1540 = false; 
{ int64_t _e4487 = fnum_1537; for (int64_t _k4487 = 0; _k4487 < _e4487; _k4487++) { int64_t i_1541 = (int64_t)_k4487; S11 f_1542 = (*({ hrv *_t4488 = &(g572); int64_t _i4488 = ((int64_t)((int64_t)f0_1536 + (int64_t)i_1541)); (S11*)_t4488->b + hr_ix(_i4488, _t4488->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:69"); })); 
if ((((f_1542).ty_) < (((int32_t)0LL)))) { if ((((f_1542).padn_) > (((int32_t)0LL)))) { (void)(({ hrv *_o4489 = &(g165); hr_fs(_o4489, hr_str("uint8_t _p", 10)); hr_fi(_o4489, i_1541); hr_fs(_o4489, hr_str("[", 1)); hr_fi(_o4489, (f_1542).padn_); hr_fs(_o4489, hr_str("]; ", 3)); }));
any_1540 = true;
 }
continue;
 }
(void)(({ hrv *_v4490 = &(g165); hsl _s4490 = f267_cn(((int64_t)((f_1542).ty_))); hr_append(_v4490, _s4490.p, _s4490.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4492 = &(g165); uint8_t _x4492 = ((uint8_t)32LL); uint8_t *_p4492 = (uint8_t*)hr_grow(_v4492, 1, sizeof _x4492); *_p4492 = _x4492; _p4492; }));
(void)(f270_fname_into((&(g165)), ((int64_t)((f_1542).name_))));
(void)(({ hrv *_v4494 = &(g165); hsl _s4494 = hr_str("; ", 2); hr_append(_v4494, _s4494.p, _s4494.n, sizeof(uint8_t)); }));
any_1540 = true;
 } } _bk4486:; 
if ((!(any_1540))) { (void)(({ hrv *_v4495 = &(g165); hsl _s4495 = hr_str("uint8_t _e; ", 12); hr_append(_v4495, _s4495.p, _s4495.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4496 = &(g165); hsl _s4496 = hr_str("};\012", 3); hr_append(_v4496, _s4496.p, _s4496.n, sizeof(uint8_t)); }));
return;
 }
if (((k_1520) == (((int64_t)6LL)))) { int64_t ei_1546 = ((int64_t)((x_1519).a_)); 
(void)(f149_ei_layout(ei_1546));
int64_t v0_1547 = ((int64_t)(((*({ hrv *_t4498 = &(g573); int64_t _i4498 = ei_1546; (S8*)_t4498->b + hr_ix(_i4498, _t4498->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:79"); }))).v0_)); 
bool pay_1548 = false; 
{ int32_t _e4500 = ((*({ hrv *_t4501 = &(g573); int64_t _i4501 = ei_1546; (S8*)_t4501->b + hr_ix(_i4501, _t4501->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:81"); }))).vnum_; for (int32_t _k4500 = 0; _k4500 < _e4500; _k4500++) { int32_t i_1549 = (int32_t)_k4500; S9 v_1550 = (*({ hrv *_t4502 = &(g574); int64_t _i4502 = ((int64_t)((int64_t)v0_1547 + (int64_t)((int64_t)(i_1549)))); (S9*)_t4502->b + hr_ix(_i4502, _t4502->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:81"); })); 
if (((((v_1550).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4503 = &(g571); int64_t _i4503 = (v_1550).si_; (S10*)_t4503->b + hr_ix(_i4503, _t4503->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:81"); }))).zero_)))) { (void)(f265_cbody(f134_t_struct(((int64_t)((v_1550).si_)))));
pay_1548 = true;
 }
 } } _bk4499:; 
(void)(({ hrv *_v4506 = &(g165); hsl _s4506 = hr_str("struct ", 7); hr_append(_v4506, _s4506.p, _s4506.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4507 = &(g165); hsl _s4507 = f267_cn(t_1518); hr_append(_v4507, _s4507.p, _s4507.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4509 = &(g165); hsl _s4509 = ({ hsl _r4510; if (((((*({ hrv *_t4511 = &(g573); int64_t _i4511 = ei_1546; (S8*)_t4511->b + hr_ix(_i4511, _t4511->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:82"); }))).tagsz_) == (((uint8_t)1LL)))) { _r4510 = hr_str(" { uint8_t tag; ", 16);  } else { _r4510 = hr_str(" { uint16_t tag; ", 17);  } _r4510; }); hr_append(_v4509, _s4509.p, _s4509.n, sizeof(uint8_t)); }));
if (pay_1548) { (void)(({ hrv *_v4512 = &(g165); hsl _s4512 = hr_str("union { ", 8); hr_append(_v4512, _s4512.p, _s4512.n, sizeof(uint8_t)); }));
{ int32_t _e4514 = ((*({ hrv *_t4515 = &(g573); int64_t _i4515 = ei_1546; (S8*)_t4515->b + hr_ix(_i4515, _t4515->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:83"); }))).vnum_; for (int32_t _k4514 = 0; _k4514 < _e4514; _k4514++) { int32_t i_1551 = (int32_t)_k4514; S9 v_1552 = (*({ hrv *_t4516 = &(g574); int64_t _i4516 = ((int64_t)((int64_t)v0_1547 + (int64_t)((int64_t)(i_1551)))); (S9*)_t4516->b + hr_ix(_i4516, _t4516->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:83"); })); 
if (((((v_1552).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4517 = &(g571); int64_t _i4517 = (v_1552).si_; (S10*)_t4517->b + hr_ix(_i4517, _t4517->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:83"); }))).zero_)))) { (void)(({ hrv *_v4518 = &(g165); hsl _s4518 = f267_cn(f134_t_struct(((int64_t)((v_1552).si_)))); hr_append(_v4518, _s4518.p, _s4518.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4521 = &(g165); hr_fs(_o4521, hr_str(" v", 2)); hr_fi(_o4521, i_1551); hr_fs(_o4521, hr_str("; ", 2)); }));
 }
 } } _bk4513:; 
(void)(({ hrv *_v4522 = &(g165); hsl _s4522 = hr_str("} u; ", 5); hr_append(_v4522, _s4522.p, _s4522.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4523 = &(g165); hsl _s4523 = hr_str("};\012", 3); hr_append(_v4523, _s4523.p, _s4523.n, sizeof(uint8_t)); }));
return;
 }
if (((k_1520) == (((int64_t)8LL)))) { int64_t a_1553 = ((int64_t)((x_1519).s_)); 
if ((((a_1553) == (((int64_t)1LL))) || (((a_1553) == (((int64_t)3LL))) && (((x_1519).b_) >= (((int64_t)0LL)))))) { (void)(f265_cbody(((int64_t)((x_1519).a_))));
(void)(({ hrv *_v4525 = &(g165); hsl _s4525 = hr_str("struct ", 7); hr_append(_v4525, _s4525.p, _s4525.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4526 = &(g165); hsl _s4526 = f267_cn(t_1518); hr_append(_v4526, _s4526.p, _s4526.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4528 = &(g165); hsl _s4528 = hr_str(" { ", 3); hr_append(_v4528, _s4528.p, _s4528.n, sizeof(uint8_t)); }));
if (((a_1553) == (((int64_t)3LL)))) { (void)(({ hrv *_v4529 = &(g165); hsl _s4529 = (g183).e[hr_ix(((int64_t)((int64_t)f124_lim_lenstore((x_1519).b_) & (int64_t)((int64_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:92")]; hr_append(_v4529, _s4529.p, _s4529.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4532 = &(g165); hsl _s4532 = hr_str(" n; ", 4); hr_append(_v4532, _s4532.p, _s4532.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4533 = &(g165); hsl _s4533 = f267_cn(((int64_t)((x_1519).a_))); hr_append(_v4533, _s4533.p, _s4533.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4535 = &(g165); hr_fs(_o4535, hr_str(" e[", 3)); hr_fi(_o4535, f103_max((x_1519).b_, ((int64_t)1LL))); hr_fs(_o4535, hr_str("]; };\012", 6)); }));
 }
return;
 }
if (((k_1520) == (((int64_t)14LL)))) { { int32_t _e4538 = (x_1519).n_; for (int32_t _k4538 = 0; _k4538 < _e4538; _k4538++) { int32_t i_1554 = (int32_t)_k4538; (void)(f265_cbody(((int64_t)((*({ hrv *_t4540 = &(g569); int64_t _i4540 = ((int64_t)((int64_t)((int64_t)((x_1519).l_)) + (int64_t)((int64_t)(i_1554)))); (int32_t*)_t4540->b + hr_ix(_i4540, _t4540->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:98"); }))))));
 } } _bk4537:; 
(void)(({ hrv *_v4541 = &(g165); hsl _s4541 = hr_str("struct ", 7); hr_append(_v4541, _s4541.p, _s4541.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4542 = &(g165); hsl _s4542 = f267_cn(t_1518); hr_append(_v4542, _s4542.p, _s4542.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4544 = &(g165); hsl _s4544 = hr_str(" { ", 3); hr_append(_v4544, _s4544.p, _s4544.n, sizeof(uint8_t)); }));
{ int32_t _e4546 = (x_1519).n_; for (int32_t _k4546 = 0; _k4546 < _e4546; _k4546++) { int32_t i_1555 = (int32_t)_k4546; (void)(({ hrv *_v4547 = &(g165); hsl _s4547 = f267_cn(((int64_t)((*({ hrv *_t4549 = &(g569); int64_t _i4549 = ((int64_t)((int64_t)((int64_t)((x_1519).l_)) + (int64_t)((int64_t)(i_1555)))); (int32_t*)_t4549->b + hr_ix(_i4549, _t4549->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:100"); }))))); hr_append(_v4547, _s4547.p, _s4547.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4550 = &(g165); hr_fs(_o4550, hr_str(" r", 2)); hr_fi(_o4550, i_1555); hr_fs(_o4550, hr_str("; ", 2)); }));
 } } _bk4545:; 
(void)(({ hrv *_v4551 = &(g165); hsl _s4551 = hr_str("};\012", 3); hr_append(_v4551, _s4551.p, _s4551.n, sizeof(uint8_t)); }));
 }
}
static void f266_cn_grow(void) {
while ((((g171).n) < ((g568).n))) { (void)(({ hrv *_v4553 = &(g171); int32_t _x4553 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p4553 = (int32_t*)hr_grow(_v4553, 1, sizeof _x4553); *_p4553 = _x4553; _p4553; }));
(void)(({ hrv *_v4554 = &(g172); int32_t _x4554 = ((int32_t)0LL); int32_t *_p4554 = (int32_t*)hr_grow(_v4554, 1, sizeof _x4554); *_p4554 = _x4554; _p4554; }));
(void)(({ hrv *_v4555 = &(g173); uint8_t _x4555 = ((uint8_t)0LL); uint8_t *_p4555 = (uint8_t*)hr_grow(_v4555, 1, sizeof _x4555); *_p4555 = _x4555; _p4555; }));
(void)(({ hrv *_v4556 = &(g174); uint8_t _x4556 = ((uint8_t)0LL); uint8_t *_p4556 = (uint8_t*)hr_grow(_v4556, 1, sizeof _x4556); *_p4556 = _x4556; _p4556; }));
(void)(({ hrv *_v4557 = &(g175); uint8_t _x4557 = ((uint8_t)0LL); uint8_t *_p4557 = (uint8_t*)hr_grow(_v4557, 1, sizeof _x4557); *_p4557 = _x4557; _p4557; }));
 } _bk4552:; 
}
static hsl f267_cn(int64_t t_1521) {
(void)(f266_cn_grow());
if ((((*({ hrv *_t4559 = &(g171); int64_t _i4559 = t_1521; (int32_t*)_t4559->b + hr_ix(_i4559, _t4559->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:29"); }))) < (((int32_t)0LL)))) { (void)(f268_cn_make(t_1521));
 }
int64_t o_1533 = ((int64_t)((*({ hrv *_t4561 = &(g171); int64_t _i4561 = t_1521; (int32_t*)_t4561->b + hr_ix(_i4561, _t4561->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:30"); })))); 
return ({ hsl _t4562 = hr_sl(g170); int64_t _l4562 = o_1533, _h4562 = ((int64_t)((int64_t)o_1533 + (int64_t)((int64_t)((*({ hrv *_t4563 = &(g172); int64_t _i4563 = t_1521; (int32_t*)_t4563->b + hr_ix(_i4563, _t4563->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:31"); })))))); if (_l4562 < 0 || _h4562 < _l4562 || _h4562 > _t4562.n) hr_slerr(_l4562, _h4562, _t4562.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:31"); (hsl){ _t4562.p + _l4562 * (int64_t)sizeof(uint8_t), _h4562 - _l4562 }; });
}
static void f268_cn_make(int64_t t_1522) {
S1 x_1523 = (*({ hrv *_t4564 = &(g568); int64_t _i4564 = t_1522; (S1*)_t4564->b + hr_ix(_i4564, _t4564->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:34"); })); 
int64_t k_1524 = ((int64_t)((x_1523).k_)); 
if ((((k_1524) == (((int64_t)10LL))) && (((x_1523).c_) < (((int32_t)0LL))))) { hsl e_1525 = f267_cn(((int64_t)((x_1523).a_))); 
int64_t s0_1526 = (g170).n; 
(void)(({ hrv *_v4566 = &(g170); hsl _s4566 = e_1525; hr_append(_v4566, _s4566.p, _s4566.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4567 = &(g170); uint8_t _x4567 = ((uint8_t)42LL); uint8_t *_p4567 = (uint8_t*)hr_grow(_v4567, 1, sizeof _x4567); *_p4567 = _x4567; _p4567; }));
{ int32_t *_t4568 = &((*({ hrv *_t4569 = &(g171); int64_t _i4569 = t_1522; (int32_t*)_t4569->b + hr_ix(_i4569, _t4569->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:35"); }))); *_t4568 = ((int32_t)(s0_1526)); }
{ int32_t *_t4570 = &((*({ hrv *_t4571 = &(g172); int64_t _i4571 = t_1522; (int32_t*)_t4571->b + hr_ix(_i4571, _t4571->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:35"); }))); *_t4570 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1526)))); }
return;
 }
if (((k_1524) == (((int64_t)7LL)))) { S9 v_1527 = (*({ hrv *_t4572 = &(g574); int64_t _i4572 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4573 = &(g573); int64_t _i4573 = (x_1523).a_; (S8*)_t4573->b + hr_ix(_i4573, _t4573->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:36"); }))).v0_)) + (int64_t)((int64_t)((x_1523).c_)))); (S9*)_t4572->b + hr_ix(_i4572, _t4572->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:36"); })); 
if ((((v_1527).si_) >= (((int32_t)0LL)))) { hsl e_1528 = f267_cn(f134_t_struct(((int64_t)((v_1527).si_)))); 
int64_t s0_1529 = (g170).n; 
(void)(({ hrv *_v4576 = &(g170); hsl _s4576 = e_1528; hr_append(_v4576, _s4576.p, _s4576.n, sizeof(uint8_t)); }));
{ int32_t *_t4577 = &((*({ hrv *_t4578 = &(g171); int64_t _i4578 = t_1522; (int32_t*)_t4578->b + hr_ix(_i4578, _t4578->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:36"); }))); *_t4577 = ((int32_t)(s0_1529)); }
{ int32_t *_t4579 = &((*({ hrv *_t4580 = &(g172); int64_t _i4580 = t_1522; (int32_t*)_t4580->b + hr_ix(_i4580, _t4580->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:36"); }))); *_t4579 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1529)))); }
return;
 }
 }
int64_t s0_1530 = (g170).n; 
if (((k_1524) == (((int64_t)3LL)))) { (void)(({ hrv *_v4581 = &(g170); hsl _s4581 = (g183).e[hr_ix(((uint8_t)((uint64_t)(x_1523).s_ & (uint64_t)((uint8_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:38")]; hr_append(_v4581, _s4581.p, _s4581.n, sizeof(uint8_t)); }));
 } else { if (((k_1524) == (((int64_t)10LL)))) { (void)(({ hrv *_v4583 = &(g170); hsl _s4583 = (g183).e[hr_ix(((int32_t)((int64_t)(x_1523).c_ & (int64_t)((int32_t)3LL))), 8, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:39")]; hr_append(_v4583, _s4583.p, _s4583.n, sizeof(uint8_t)); }));
 } else { if (((k_1524) == (((int64_t)2LL)))) { (void)(({ hrv *_v4585 = &(g170); hsl _s4585 = hr_str("bool", 4); hr_append(_v4585, _s4585.p, _s4585.n, sizeof(uint8_t)); }));
 } else { if (((k_1524) == (((int64_t)4LL)))) { (void)(({ hrv *_v4586 = &(g170); hsl _s4586 = ({ hsl _r4587; if ((((x_1523).s_) == (((uint8_t)4LL)))) { _r4587 = hr_str("float", 5);  } else { _r4587 = hr_str("double", 6);  } _r4587; }); hr_append(_v4586, _s4586.p, _s4586.n, sizeof(uint8_t)); }));
 } else { if (((k_1524) == (((int64_t)1LL)))) { (void)(({ hrv *_v4588 = &(g170); hsl _s4588 = hr_str("void", 4); hr_append(_v4588, _s4588.p, _s4588.n, sizeof(uint8_t)); }));
 } else { if (((k_1524) == (((int64_t)5LL)))) { (void)(({ hrv *_o4589 = &(g170); hr_fs(_o4589, hr_str("S", 1)); hr_fi(_o4589, (x_1523).a_); }));
(void)(f269_fwd(s0_1530));
 } else { if (((k_1524) == (((int64_t)6LL)))) { (void)(({ hrv *_o4591 = &(g170); hr_fs(_o4591, hr_str("E", 1)); hr_fi(_o4591, (x_1523).a_); }));
(void)(f269_fwd(s0_1530));
 } else { if (((k_1524) == (((int64_t)7LL)))) { (void)(({ hrv *_v4593 = &(g170); hsl _s4593 = hr_str("hr_unit", 7); hr_append(_v4593, _s4593.p, _s4593.n, sizeof(uint8_t)); }));
 } else { if (((k_1524) == (((int64_t)8LL)))) { int64_t a_1532 = ((int64_t)((x_1523).s_)); 
if ((((a_1532) == (((int64_t)4LL))) || ((a_1532) == (((int64_t)5LL))))) { (void)(({ hrv *_v4594 = &(g170); hsl _s4594 = hr_str("hrv", 3); hr_append(_v4594, _s4594.p, _s4594.n, sizeof(uint8_t)); }));
 } else { if (((a_1532) == (((int64_t)1LL)))) { (void)(({ hrv *_o4595 = &(g170); hr_fs(_o4595, hr_str("A", 1)); hr_fi(_o4595, t_1522); }));
(void)(f269_fwd(s0_1530));
 } else { if ((((a_1532) == (((int64_t)3LL))) && (((x_1523).b_) >= (((int64_t)0LL))))) { (void)(({ hrv *_o4597 = &(g170); hr_fs(_o4597, hr_str("L", 1)); hr_fi(_o4597, t_1522); }));
(void)(f269_fwd(s0_1530));
 } else { (void)(({ hrv *_v4599 = &(g170); hsl _s4599 = hr_str("uint8_t*", 8); hr_append(_v4599, _s4599.p, _s4599.n, sizeof(uint8_t)); }));
 }
 }
 }
 } else { if (((((k_1524) == (((int64_t)9LL))) || ((k_1524) == (((int64_t)18LL)))) || ((k_1524) == (((int64_t)19LL))))) { (void)(({ hrv *_v4600 = &(g170); hsl _s4600 = hr_str("hsl", 3); hr_append(_v4600, _s4600.p, _s4600.n, sizeof(uint8_t)); }));
 } else { if (((k_1524) == (((int64_t)14LL)))) { (void)(({ hrv *_o4601 = &(g170); hr_fs(_o4601, hr_str("M", 1)); hr_fi(_o4601, t_1522); }));
(void)(f269_fwd(s0_1530));
 } else { if ((((k_1524) == (((int64_t)12LL))) || ((k_1524) == (((int64_t)17LL))))) { (void)(({ hrv *_v4603 = &(g170); hsl _s4603 = hr_str("int64_t", 7); hr_append(_v4603, _s4603.p, _s4603.n, sizeof(uint8_t)); }));
 } else { if (((k_1524) == (((int64_t)13LL)))) { (void)(({ hrv *_v4604 = &(g170); hsl _s4604 = hr_str("double", 6); hr_append(_v4604, _s4604.p, _s4604.n, sizeof(uint8_t)); }));
 } else { (void)(({ hrv *_v4605 = &(g170); hsl _s4605 = hr_str("void*", 5); hr_append(_v4605, _s4605.p, _s4605.n, sizeof(uint8_t)); }));
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
{ int32_t *_t4606 = &((*({ hrv *_t4607 = &(g171); int64_t _i4607 = t_1522; (int32_t*)_t4607->b + hr_ix(_i4607, _t4607->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:52"); }))); *_t4606 = ((int32_t)(s0_1530)); }
{ int32_t *_t4608 = &((*({ hrv *_t4609 = &(g172); int64_t _i4609 = t_1522; (int32_t*)_t4609->b + hr_ix(_i4609, _t4609->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:52"); }))); *_t4608 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1530)))); }
}
static void f269_fwd(int64_t s0_1531) {
(void)(({ hrv *_v4610 = &(g164); hsl _s4610 = hr_str("typedef struct ", 15); hr_append(_v4610, _s4610.p, _s4610.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4611 = &(g164); hsl _s4611 = ({ hsl _t4612 = hr_sl(g170); int64_t _l4612 = s0_1531, _h4612 = _t4612.n; if (_l4612 < 0 || _h4612 < _l4612 || _h4612 > _t4612.n) hr_slerr(_l4612, _h4612, _t4612.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:17"); (hsl){ _t4612.p + _l4612 * (int64_t)sizeof(uint8_t), _h4612 - _l4612 }; }); hr_append(_v4611, _s4611.p, _s4611.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4613 = &(g164); uint8_t _x4613 = ((uint8_t)32LL); uint8_t *_p4613 = (uint8_t*)hr_grow(_v4613, 1, sizeof _x4613); *_p4613 = _x4613; _p4613; }));
(void)(({ hrv *_v4614 = &(g164); hsl _s4614 = ({ hsl _t4615 = hr_sl(g170); int64_t _l4615 = s0_1531, _h4615 = _t4615.n; if (_l4615 < 0 || _h4615 < _l4615 || _h4615 > _t4615.n) hr_slerr(_l4615, _h4615, _t4615.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:17"); (hsl){ _t4615.p + _l4615 * (int64_t)sizeof(uint8_t), _h4615 - _l4615 }; }); hr_append(_v4614, _s4614.p, _s4614.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4616 = &(g164); hsl _s4616 = hr_str(";\012", 2); hr_append(_v4616, _s4616.p, _s4616.n, sizeof(uint8_t)); }));
}
static void f270_fname_into(hrv* b_1543, int64_t name_1544) {
{ hsl _v4618 = f10_nm(name_1544); for (int64_t _k4618 = 0; _k4618 < _v4618.n; _k4618++) { uint8_t c_1545 = ((uint8_t*)_v4618.p)[_k4618]; (void)(({ hrv *_v4620 = b_1543; uint8_t _x4620 = ({ uint8_t _r4621; if (((c_1545) == (((uint8_t)58LL)))) { _r4621 = ((uint8_t)95LL);  } else { _r4621 = c_1545;  } _r4621; }); uint8_t *_p4620 = (uint8_t*)hr_grow(_v4620, 1, sizeof _x4620); *_p4620 = _x4620; _p4620; }));
 } } _bk4617:; 
(void)(({ hrv *_v4622 = b_1543; uint8_t _x4622 = ((uint8_t)95LL); uint8_t *_p4622 = (uint8_t*)hr_grow(_v4622, 1, sizeof _x4622); *_p4622 = _x4622; _p4622; }));
}
static bool f271_is_res(int64_t t_1564) {
return (((((*({ hrv *_t4623 = &(g568); int64_t _i4623 = t_1564; (S1*)_t4623->b + hr_ix(_i4623, _t4623->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:18"); }))).k_) == (((uint8_t)8LL))) && (((((int64_t)(((*({ hrv *_t4624 = &(g568); int64_t _i4624 = t_1564; (S1*)_t4624->b + hr_ix(_i4624, _t4624->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:18"); }))).s_))) == (((int64_t)4LL))) || ((((int64_t)(((*({ hrv *_t4625 = &(g568); int64_t _i4625 = t_1564; (S1*)_t4625->b + hr_ix(_i4625, _t4625->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:18"); }))).s_))) == (((int64_t)5LL)))));
}
static void f272_gxo(int64_t n_1565) {
int64_t c_1566 = f153_cv(n_1565); 
int64_t t_1567 = f141_at(n_1565); 
if ((((c_1566) >= (((int64_t)0LL))) && ((c_1566) != (t_1567)))) { if (f271_is_res(c_1566)) { (void)(f273_gcv(n_1565, t_1567, c_1566));
return;
 }
(void)(f297_gx(n_1565));
return;
 }
if ((f271_is_res(t_1567) && f275_is_place(n_1565))) { (void)(f263_ow(hr_str("hr_rdup(", 8)));
(void)(f280_gx0(n_1565));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f335_esz(((int64_t)(((*({ hrv *_t4637 = &(g568); int64_t _i4637 = t_1567; (S1*)_t4637->b + hr_ix(_i4637, _t4637->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:166"); }))).a_))));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
(void)(f280_gx0(n_1565));
}
static void f273_gcv(int64_t n_1568, int64_t f_1569, int64_t t_1570) {
if (((f_1569) == (t_1570))) { (void)(f274_gx1(n_1568));
return;
 }
int64_t fk_2128 = ((int64_t)(((*({ hrv *_t4641 = &(g568); int64_t _i4641 = f_1569; (S1*)_t4641->b + hr_ix(_i4641, _t4641->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:215"); }))).k_)); 
int64_t tk0_2129 = ((int64_t)(((*({ hrv *_t4642 = &(g568); int64_t _i4642 = t_1570; (S1*)_t4642->b + hr_ix(_i4642, _t4642->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:215"); }))).k_)); 
if (((((tk0_2129) == (((int64_t)2LL))) && ((fk_2128) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4643 = &(g568); int64_t _i4643 = f_1569; (S1*)_t4643->b + hr_ix(_i4643, _t4643->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:216"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f263_ow(hr_str("((", 2)));
(void)(f274_gx1(n_1568));
(void)(f263_ow(hr_str(") != 0)", 7)));
return;
 }
if (((((fk_2128) == (((int64_t)10LL))) && ((((*({ hrv *_t4647 = &(g568); int64_t _i4647 = f_1569; (S1*)_t4647->b + hr_ix(_i4647, _t4647->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:217"); }))).c_) < (((int32_t)0LL)))) && ((tk0_2129) != (((int64_t)10LL))))) { int64_t m_2130 = ((int64_t)(((*({ hrv *_t4648 = &(g568); int64_t _i4648 = f_1569; (S1*)_t4648->b + hr_ix(_i4648, _t4648->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:218"); }))).a_)); 
if (((m_2130) == (t_1570))) { (void)(f263_ow(hr_str("(*", 2)));
(void)(f274_gx1(n_1568));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if ((((tk0_2129) == (((int64_t)9LL))) && (((((*({ hrv *_t4652 = &(g568); int64_t _i4652 = m_2130; (S1*)_t4652->b + hr_ix(_i4652, _t4652->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:220"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t4653 = &(g568); int64_t _i4653 = m_2130; (S1*)_t4653->b + hr_ix(_i4653, _t4653->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:220"); }))).k_) == (((uint8_t)9LL)))))) { (void)(f300_gsl(n_1568, f_1569));
return;
 }
if ((((tk0_2129) == (((int64_t)3LL))) || ((tk0_2129) == (((int64_t)4LL))))) { (void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(t_1570));
(void)(f263_ow(hr_str(")(*", 3)));
(void)(f274_gx1(n_1568));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
if (f271_is_res(t_1570)) { (void)(f263_ow(hr_str("hr_rfrom(", 9)));
(void)(f300_gsl(n_1568, f_1569));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f335_esz(((int64_t)(((*({ hrv *_t4665 = &(g568); int64_t _i4665 = t_1570; (S1*)_t4665->b + hr_ix(_i4665, _t4665->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:222"); }))).a_))));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
(void)(f263_ow(hr_str("(*", 2)));
(void)(f274_gx1(n_1568));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if (((((tk0_2129) == (((int64_t)3LL))) || ((tk0_2129) == (((int64_t)4LL)))) && ((((fk_2128) == (((int64_t)3LL))) || ((fk_2128) == (((int64_t)4LL)))) || ((fk_2128) == (((int64_t)2LL)))))) { (void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(t_1570));
(void)(f263_ow(hr_str(")(", 2)));
(void)(f274_gx1(n_1568));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
if (((tk0_2129) == (((int64_t)9LL)))) { (void)(f300_gsl(n_1568, f_1569));
return;
 }
if ((((tk0_2129) == (((int64_t)6LL))) && ((fk_2128) == (((int64_t)7LL))))) { int64_t vi_2131 = ((int64_t)(((*({ hrv *_t4676 = &(g568); int64_t _i4676 = f_1569; (S1*)_t4676->b + hr_ix(_i4676, _t4676->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:228"); }))).c_)); 
int64_t ei_2132 = ((int64_t)(((*({ hrv *_t4677 = &(g568); int64_t _i4677 = f_1569; (S1*)_t4677->b + hr_ix(_i4677, _t4677->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:228"); }))).a_)); 
S9 v_2133 = (*({ hrv *_t4678 = &(g574); int64_t _i4678 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4679 = &(g573); int64_t _i4679 = ei_2132; (S8*)_t4679->b + hr_ix(_i4679, _t4679->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:228"); }))).v0_)) + (int64_t)vi_2131)); (S9*)_t4678->b + hr_ix(_i4678, _t4678->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:228"); })); 
int64_t p_2134 = f301_nt(); 
(void)(f263_ow(hr_str("({ ", 3)));
(void)(f264_ct(t_1570));
(void)(f263_ow(hr_str(" _t", 3)));
(void)(f302_oi(p_2134));
(void)(f263_ow(hr_str("; memset(&_t", 12)));
(void)(f302_oi(p_2134));
(void)(f263_ow(hr_str(", 0, sizeof _t", 14)));
(void)(f302_oi(p_2134));
(void)(f263_ow(hr_str("); _t", 5)));
(void)(f302_oi(p_2134));
(void)(({ hrv *_o4691 = &(g163); hr_fs(_o4691, hr_str(".tag = ", 7)); hr_fi(_o4691, vi_2131); hr_fs(_o4691, hr_str("; ", 2)); }));
if (((((v_2133).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4692 = &(g571); int64_t _i4692 = (v_2133).si_; (S10*)_t4692->b + hr_ix(_i4692, _t4692->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:231"); }))).zero_)))) { (void)(f263_ow(hr_str("_t", 2)));
(void)(f302_oi(p_2134));
(void)(({ hrv *_o4695 = &(g163); hr_fs(_o4695, hr_str(".u.v", 4)); hr_fi(_o4695, vi_2131); hr_fs(_o4695, hr_str(" = ", 3)); }));
(void)(f274_gx1(n_1568));
(void)(f263_ow(hr_str("; ", 2)));
 } else { (void)(f263_ow(hr_str("(void)(", 7)));
(void)(f274_gx1(n_1568));
(void)(f263_ow(hr_str("); ", 3)));
 }
(void)(f263_ow(hr_str("_t", 2)));
(void)(f302_oi(p_2134));
(void)(f263_ow(hr_str("; })", 4)));
return;
 }
if (((tk0_2129) == (((int64_t)10LL)))) { if (((fk_2128) == (((int64_t)10LL)))) { (void)(f274_gx1(n_1568));
return;
 }
(void)(f333_gaddr(n_1568));
return;
 }
if (f289_is_vimg(t_1570)) { if ((!(f303_vok(n_1568, t_1570)))) { return;
 }
g195++;
(void)(f263_ow(hr_str("hr_vfrom(", 9)));
(void)(f300_gsl(n_1568, f_1569));
(void)(f290_vargs(t_1570));
(void)(f263_ow(hr_str(", sizeof(", 9)));
(void)(f264_ct(((int64_t)(((*({ hrv *_t4713 = &(g568); int64_t _i4713 = t_1570; (S1*)_t4713->b + hr_ix(_i4713, _t4713->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:236"); }))).a_))));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
if (f271_is_res(t_1570)) { (void)(f263_ow(hr_str("hr_rfrom(", 9)));
(void)(f300_gsl(n_1568, f_1569));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f335_esz(((int64_t)(((*({ hrv *_t4720 = &(g568); int64_t _i4720 = t_1570; (S1*)_t4720->b + hr_ix(_i4720, _t4720->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:237"); }))).a_))));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if ((f287_is_fix(t_1570) || f288_is_lim(t_1570))) { int64_t p_2135 = f301_nt(); 
(void)(f263_ow(hr_str("({ hsl _t", 9)));
(void)(f302_oi(p_2135));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f300_gsl(n_1568, f_1569));
(void)(f263_ow(hr_str("; ", 2)));
(void)(f264_ct(t_1570));
(void)(f263_ow(hr_str(" _r", 3)));
(void)(f302_oi(p_2135));
(void)(f263_ow(hr_str("; ", 2)));
if (f287_is_fix(t_1570)) { (void)(({ hrv *_o4735 = &(g163); hr_fs(_o4735, hr_str("if (_t", 6)); hr_fi(_o4735, p_2135); hr_fs(_o4735, hr_str(".n != ", 6)); hr_fi(_o4735, ((*({ hrv *_t4736 = &(g568); int64_t _i4736 = t_1570; (S1*)_t4736->b + hr_ix(_i4736, _t4736->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:241"); }))).b_); hr_fs(_o4735, hr_str(") hr_die(\"array length mismatch\", ", 34)); }));
(void)(f321_wloc(n_1568));
(void)(f263_ow(hr_str("); ", 3)));
 } else { (void)(({ hrv *_o4739 = &(g163); hr_fs(_o4739, hr_str("if (_t", 6)); hr_fi(_o4739, p_2135); hr_fs(_o4739, hr_str(".n > ", 5)); hr_fi(_o4739, ((*({ hrv *_t4740 = &(g568); int64_t _i4740 = t_1570; (S1*)_t4740->b + hr_ix(_i4740, _t4740->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:242"); }))).b_); hr_fs(_o4739, hr_str(") hr_die(\"too many elements for a limited array\", ", 50)); }));
(void)(f321_wloc(n_1568));
(void)(({ hrv *_o4742 = &(g163); hr_fs(_o4742, hr_str("); _r", 5)); hr_fi(_o4742, p_2135); hr_fs(_o4742, hr_str(".n = _t", 7)); hr_fi(_o4742, p_2135); hr_fs(_o4742, hr_str(".n; ", 4)); }));
 }
(void)(({ hrv *_o4743 = &(g163); hr_fs(_o4743, hr_str("memcpy(_r", 9)); hr_fi(_o4743, p_2135); hr_fs(_o4743, hr_str(".e, _t", 6)); hr_fi(_o4743, p_2135); hr_fs(_o4743, hr_str(".p, (size_t)_t", 14)); hr_fi(_o4743, p_2135); hr_fs(_o4743, hr_str(".n * sizeof _r", 14)); hr_fi(_o4743, p_2135); hr_fs(_o4743, hr_str(".e[0]); _r", 10)); hr_fi(_o4743, p_2135); hr_fs(_o4743, hr_str("; })", 4)); }));
return;
 }
(void)(f274_gx1(n_1568));
}
static void f274_gx1(int64_t n_1571) {
if ((f271_is_res(f141_at(n_1571)) && (!(f275_is_place(n_1571))))) { int64_t k_1585 = f278_tmp(f141_at(n_1571), true); 
(void)(f263_ow(hr_str("(*hr_tmp(&", 10)));
(void)(f279_ot(k_1585));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f280_gx0(n_1571));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
(void)(f280_gx0(n_1571));
}
static bool f275_is_place(int64_t n_1572) {
S4 x_1573 = (*({ hrv *_t4756 = &(g721); int64_t _i4756 = n_1572; (S4*)_t4756->b + hr_ix(_i4756, _t4756->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:128"); })); 
int64_t k_1574 = ((int64_t)((x_1573).k_)); 
if (((k_1574) == (((int64_t)8LL)))) { int64_t r_1575 = f159_rk(n_1572); 
return (((r_1575) == (((int64_t)1LL))) || ((r_1575) == (((int64_t)2LL))));
 }
if (((k_1574) == (((int64_t)14LL)))) { return ((((f159_rk(n_1572)) == (((int64_t)5LL))) && ((f276_rel_field(n_1572)) < (((int64_t)0LL)))) && (f275_is_place(((int64_t)((x_1573).a_))) || ((((*({ hrv *_t4761 = &(g568); int64_t _i4761 = f141_at(((int64_t)((x_1573).a_))); (S1*)_t4761->b + hr_ix(_i4761, _t4761->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:130"); }))).k_) == (((uint8_t)10LL)))));
 }
if (((k_1574) == (((int64_t)12LL)))) { int64_t bt_1582 = f141_at(((int64_t)((x_1573).a_))); 
return ((((((*({ hrv *_t4764 = &(g568); int64_t _i4764 = f182_deref(bt_1582); (S1*)_t4764->b + hr_ix(_i4764, _t4764->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:131"); }))).k_) == (((uint8_t)9LL))) || f275_is_place(((int64_t)((x_1573).a_)))) || ((((*({ hrv *_t4767 = &(g568); int64_t _i4767 = bt_1582; (S1*)_t4767->b + hr_ix(_i4767, _t4767->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:131"); }))).k_) == (((uint8_t)10LL))));
 }
if ((((k_1574) == (((int64_t)10LL))) && ((((int64_t)((x_1573).op_))) == (((int64_t)49LL))))) { return f275_is_place(((int64_t)((x_1573).a_)));
 }
if (((((k_1574) == (((int64_t)11LL))) && ((f159_rk(n_1572)) == (((int64_t)4LL)))) && ((f160_rv(n_1572)) == (((int64_t)20LL))))) { return true;
 }
return false;
}
static int64_t f276_rel_field(int64_t n_1576) {
if ((((((*({ hrv *_t4771 = &(g721); int64_t _i4771 = n_1576; (S4*)_t4771->b + hr_ix(_i4771, _t4771->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1052"); }))).k_) != (((uint8_t)14LL))) || ((f159_rk(n_1576)) != (((int64_t)5LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t a_1577 = ((int64_t)(((*({ hrv *_t4773 = &(g721); int64_t _i4773 = n_1576; (S4*)_t4773->b + hr_ix(_i4773, _t4773->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1053"); }))).a_)); 
int64_t st_1578 = f182_deref(f141_at(a_1577)); 
int64_t si_1579 = ({ int64_t _r4776; if (((((*({ hrv *_t4777 = &(g568); int64_t _i4777 = st_1578; (S1*)_t4777->b + hr_ix(_i4777, _t4777->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1054"); }))).k_) == (((uint8_t)5LL)))) { _r4776 = ((int64_t)(((*({ hrv *_t4778 = &(g568); int64_t _i4778 = st_1578; (S1*)_t4778->b + hr_ix(_i4778, _t4778->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1054"); }))).a_));  } else { _r4776 = f220_ax(n_1576);  } _r4776; }); 
int64_t ft_1580 = ((int64_t)(((*({ hrv *_t4780 = &(g572); int64_t _i4780 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4781 = &(g571); int64_t _i4781 = si_1579; (S10*)_t4781->b + hr_ix(_i4781, _t4781->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1055"); }))).f0_)) + (int64_t)f160_rv(n_1576))); (S11*)_t4780->b + hr_ix(_i4780, _t4780->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1055"); }))).ty_)); 
return ({ int64_t _r4783; if (f277_is_rel(ft_1580)) { _r4783 = ft_1580;  } else { _r4783 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r4783; });
}
static bool f277_is_rel(int64_t t_1581) {
return ((((t_1581) >= (((int64_t)0LL))) && ((((*({ hrv *_t4785 = &(g568); int64_t _i4785 = t_1581; (S1*)_t4785->b + hr_ix(_i4785, _t4785->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1050"); }))).k_) == (((uint8_t)10LL)))) && ((((*({ hrv *_t4786 = &(g568); int64_t _i4786 = t_1581; (S1*)_t4786->b + hr_ix(_i4786, _t4786->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1050"); }))).c_) >= (((int32_t)0LL))));
}
static int64_t f278_tmp(int64_t t_1583, bool clean_1584) {
(void)(f265_cbody(t_1583));
g178++;
(void)(({ hrv *_v4788 = &(g176); hsl _s4788 = f267_cn(t_1583); hr_append(_v4788, _s4788.p, _s4788.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4790 = &(g176); hr_fs(_o4790, hr_str(" _t", 3)); hr_fi(_o4790, g178); }));
if (clean_1584) { (void)(({ hrv *_v4791 = &(g176); hsl _s4791 = hr_str(" __attribute__((cleanup(hr_rdrop)))", 35); hr_append(_v4791, _s4791.p, _s4791.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4792 = &(g176); hsl _s4792 = hr_str(" = {0}; ", 8); hr_append(_v4792, _s4792.p, _s4792.n, sizeof(uint8_t)); }));
return g178;
}
static void f279_ot(int64_t k_1586) {
(void)(({ hrv *_o4793 = &(g163); hr_fs(_o4793, hr_str("_t", 2)); hr_fi(_o4793, k_1586); }));
}
static void f280_gx0(int64_t n_1587) {
S4 x_1588 = (*({ hrv *_t4794 = &(g721); int64_t _i4794 = n_1587; (S4*)_t4794->b + hr_ix(_i4794, _t4794->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:755"); })); 
int64_t k_1589 = ((int64_t)((x_1588).k_)); 
if (((k_1589) == (((int64_t)1LL)))) { (void)(f282_oint(((*({ hrv *_t4796 = &(g931); int64_t _i4796 = (x_1588).t_; (S3*)_t4796->b + hr_ix(_i4796, _t4796->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:757"); }))).v_, ((*({ hrv *_t4797 = &(g931); int64_t _i4797 = (x_1588).t_; (S3*)_t4797->b + hr_ix(_i4797, _t4797->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:757"); }))).uns_, f281_fin_lit(n_1587)));
return;
 }
if (((k_1589) == (((int64_t)2LL)))) { int64_t t_1596 = f281_fin_lit(n_1587); 
(void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(({ int64_t _r4802; if (((((*({ hrv *_t4803 = &(g568); int64_t _i4803 = t_1596; (S1*)_t4803->b + hr_ix(_i4803, _t4803->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:758"); }))).k_) == (((uint8_t)4LL)))) { _r4802 = t_1596;  } else { _r4802 = g586;  } _r4802; })));
(void)(f263_ow(hr_str(")", 1)));
(void)(f263_ow(f36_tok_text(((int64_t)((x_1588).t_)))));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if (((k_1589) == (((int64_t)3LL)))) { (void)(f283_gstr(n_1587));
return;
 }
if (((k_1589) == (((int64_t)4LL)))) { (void)(f263_ow(hr_str("true", 4)));
return;
 }
if (((k_1589) == (((int64_t)5LL)))) { (void)(f263_ow(hr_str("false", 5)));
return;
 }
if (((k_1589) == (((int64_t)6LL)))) { (void)(f263_ow(hr_str("((void*)0)", 10)));
return;
 }
if (((k_1589) == (((int64_t)8LL)))) { int64_t r_1613 = f159_rk(n_1587); 
if (((r_1613) == (((int64_t)1LL)))) { bool fc_1614 = (((((uint16_t)((uint64_t)((*({ hrv *_t4813 = &(g402); int64_t _i4813 = f160_rv(n_1587); (S12*)_t4813->b + hr_ix(_i4813, _t4813->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:765"); }))).fl_ & (uint64_t)((uint16_t)64LL)))) != (((uint16_t)0LL))) && ((f141_at(n_1587)) != (((int64_t)(((*({ hrv *_t4816 = &(g402); int64_t _i4816 = f160_rv(n_1587); (S12*)_t4816->b + hr_ix(_i4816, _t4816->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:765"); }))).ty_))))); 
if (fc_1614) { (void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(f141_at(n_1587)));
(void)(f263_ow(hr_str(")", 1)));
 }
(void)(f292_lv_expr(f160_rv(n_1587)));
if (fc_1614) { (void)(f263_ow(hr_str(")", 1)));
 }
return;
 }
if (((r_1613) == (((int64_t)2LL)))) { (void)(({ hrv *_o4825 = &(g163); hr_fs(_o4825, hr_str("g", 1)); hr_fi(_o4825, f160_rv(n_1587)); }));
return;
 }
if (((r_1613) == (((int64_t)6LL)))) { (void)(f282_oint((*({ hrv *_t4828 = &(g449); int64_t _i4828 = f160_rv(n_1587); (int64_t*)_t4828->b + hr_ix(_i4828, _t4828->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:767"); })), false, f281_fin_lit(n_1587)));
return;
 }
(void)(f295_gerr(n_1587, hr_str("unsupported name use", 20)));
return;
 }
if (((k_1589) == (((int64_t)9LL)))) { (void)(f296_gbin(n_1587));
return;
 }
if (((k_1589) == (((int64_t)10LL)))) { (void)(f322_gun(n_1587));
return;
 }
if (((k_1589) == (((int64_t)14LL)))) { int64_t r_1809 = f159_rk(n_1587); 
int64_t a_1810 = ((int64_t)((x_1588).a_)); 
if ((((r_1809) == (((int64_t)7LL))) && ((((*({ hrv *_t4835 = &(g568); int64_t _i4835 = f141_at(n_1587); (S1*)_t4835->b + hr_ix(_i4835, _t4835->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:775"); }))).k_) == (((uint8_t)7LL))))) { int64_t t_1811 = f141_at(n_1587); 
S9 v_1812 = (*({ hrv *_t4838 = &(g574); int64_t _i4838 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4839 = &(g573); int64_t _i4839 = ((*({ hrv *_t4840 = &(g568); int64_t _i4840 = t_1811; (S1*)_t4840->b + hr_ix(_i4840, _t4840->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:775"); }))).a_; (S8*)_t4839->b + hr_ix(_i4839, _t4839->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:775"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t4841 = &(g568); int64_t _i4841 = t_1811; (S1*)_t4841->b + hr_ix(_i4841, _t4841->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:775"); }))).c_)))); (S9*)_t4838->b + hr_ix(_i4838, _t4838->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:775"); })); 
if ((((v_1812).si_) >= (((int32_t)0LL)))) { (void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(t_1811));
(void)(f263_ow(hr_str("){0})", 5)));
 } else { (void)(f263_ow(hr_str("((hr_unit)0)", 12)));
 }
return;
 }
if (((r_1809) == (((int64_t)7LL)))) { int64_t t_1813 = f141_at(n_1587); 
int64_t p_1814 = f301_nt(); 
(void)(f263_ow(hr_str("({ ", 3)));
(void)(f264_ct(t_1813));
(void)(f263_ow(hr_str(" _t", 3)));
(void)(f302_oi(p_1814));
(void)(({ hrv *_o4852 = &(g163); hr_fs(_o4852, hr_str("; memset(&_t", 12)); hr_fi(_o4852, p_1814); hr_fs(_o4852, hr_str(", 0, sizeof _t", 14)); hr_fi(_o4852, p_1814); hr_fs(_o4852, hr_str("); _t", 5)); hr_fi(_o4852, p_1814); hr_fs(_o4852, hr_str(".tag = ", 7)); hr_fi(_o4852, f160_rv(n_1587)); hr_fs(_o4852, hr_str("; _t", 4)); hr_fi(_o4852, p_1814); hr_fs(_o4852, hr_str("; })", 4)); }));
return;
 }
if (((r_1809) == (((int64_t)8LL)))) { int64_t d_1815 = f182_deref(f141_at(a_1810)); 
if (f289_is_vimg(d_1815)) { if (((f160_rv(n_1587)) == (((int64_t)2LL)))) { (void)(f263_ow(hr_str("((int64_t)hr_vget(", 18)));
 } else { (void)(f263_ow(hr_str("(hr_vsl(", 8)));
 }
if (((((*({ hrv *_t4860 = &(g568); int64_t _i4860 = f141_at(a_1810); (S1*)_t4860->b + hr_ix(_i4860, _t4860->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:779"); }))).k_) == (((uint8_t)10LL)))) { (void)(f263_ow(hr_str("*", 1)));
(void)(f280_gx0(a_1810));
 } else { (void)(f297_gx(a_1810));
 }
if (((f160_rv(n_1587)) == (((int64_t)2LL)))) { (void)(({ hrv *_o4866 = &(g163); hr_fs(_o4866, hr_str(", ", 2)); hr_fi(_o4866, f151_isz(((int64_t)(((*({ hrv *_t4868 = &(g568); int64_t _i4868 = d_1815; (S1*)_t4868->b + hr_ix(_i4868, _t4868->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:779"); }))).c_)))); hr_fs(_o4866, hr_str("))", 2)); }));
 } else { (void)(f290_vargs(d_1815));
(void)(f263_ow(hr_str(").n)", 4)));
 }
return;
 }
if (((f160_rv(n_1587)) == (((int64_t)2LL)))) { (void)(({ hrv *_o4872 = &(g163); hr_fs(_o4872, hr_str("((int64_t)", 10)); hr_fi(_o4872, ((*({ hrv *_t4873 = &(g568); int64_t _i4873 = d_1815; (S1*)_t4873->b + hr_ix(_i4873, _t4873->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:780"); }))).b_); hr_fs(_o4872, hr_str(")", 1)); }));
return;
 }
if (f287_is_fix(d_1815)) { (void)(({ hrv *_o4875 = &(g163); hr_fs(_o4875, hr_str("((int64_t)", 10)); hr_fi(_o4875, ((*({ hrv *_t4876 = &(g568); int64_t _i4876 = d_1815; (S1*)_t4876->b + hr_ix(_i4876, _t4876->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:781"); }))).b_); hr_fs(_o4875, hr_str(")", 1)); }));
return;
 }
if (f288_is_lim(d_1815)) { (void)(f263_ow(hr_str("((int64_t)(", 11)));
if (((((*({ hrv *_t4879 = &(g568); int64_t _i4879 = f141_at(a_1810); (S1*)_t4879->b + hr_ix(_i4879, _t4879->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:782"); }))).k_) == (((uint8_t)10LL)))) { (void)(f280_gx0(a_1810));
(void)(f263_ow(hr_str(")->n)", 5)));
 } else { (void)(f297_gx(a_1810));
(void)(f263_ow(hr_str(").n)", 4)));
 }
return;
 }
if (((((*({ hrv *_t4885 = &(g568); int64_t _i4885 = f141_at(a_1810); (S1*)_t4885->b + hr_ix(_i4885, _t4885->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:783"); }))).k_) == (((uint8_t)10LL)))) { (void)(f263_ow(hr_str("((", 2)));
(void)(f280_gx0(a_1810));
(void)(f263_ow(hr_str(")->n)", 5)));
return;
 }
(void)(f263_ow(hr_str("(", 1)));
(void)(f297_gx(a_1810));
(void)(f263_ow(hr_str(").n", 3)));
return;
 }
if (((r_1809) == (((int64_t)5LL)))) { int64_t bt_1816 = f141_at(a_1810); 
int64_t st_1817 = f182_deref(bt_1816); 
int64_t si_1818 = ({ int64_t _r4895; if (((((*({ hrv *_t4896 = &(g568); int64_t _i4896 = st_1817; (S1*)_t4896->b + hr_ix(_i4896, _t4896->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:789"); }))).k_) == (((uint8_t)5LL)))) { _r4895 = ((int64_t)(((*({ hrv *_t4897 = &(g568); int64_t _i4897 = st_1817; (S1*)_t4897->b + hr_ix(_i4897, _t4897->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:789"); }))).a_));  } else { _r4895 = f220_ax(n_1587);  } _r4895; }); 
S11 f_1819 = (*({ hrv *_t4899 = &(g572); int64_t _i4899 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4900 = &(g571); int64_t _i4900 = si_1818; (S10*)_t4900->b + hr_ix(_i4900, _t4900->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:790"); }))).f0_)) + (int64_t)f160_rv(n_1587))); (S11*)_t4899->b + hr_ix(_i4899, _t4899->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:790"); })); 
bool rl_1820 = f277_is_rel(((int64_t)((f_1819).ty_))); 
if (rl_1820) { (void)(f263_ow(hr_str("(((", 3)));
(void)(f264_ct(f141_at(n_1587)));
(void)(f263_ow(hr_str(")hr_rld(&(", 10)));
 }
(void)(f263_ow(hr_str("(", 1)));
if (((((*({ hrv *_t4908 = &(g568); int64_t _i4908 = bt_1816; (S1*)_t4908->b + hr_ix(_i4908, _t4908->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:794"); }))).k_) == (((uint8_t)10LL)))) { (void)(f280_gx0(a_1810));
(void)(f263_ow(hr_str(")->", 3)));
 } else { (void)(f297_gx(a_1810));
(void)(f263_ow(hr_str(").", 2)));
 }
(void)(f270_fname_into((&(g163)), ((int64_t)((f_1819).name_))));
if (rl_1820) { (void)(({ hrv *_o4914 = &(g163); hr_fs(_o4914, hr_str("), ", 3)); hr_fc(_o4914, (((((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4915 = &(g568); int64_t _i4915 = (f_1819).ty_; (S1*)_t4915->b + hr_ix(_i4915, _t4915->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:796"); }))).fl_)) & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) ? "true" : "false"); hr_fs(_o4914, hr_str(")))", 3)); }));
 }
return;
 }
(void)(f295_gerr(n_1587, hr_str("unsupported member", 18)));
return;
 }
if (((k_1589) == (((int64_t)12LL)))) { (void)(f324_gidx(n_1587));
return;
 }
if (((k_1589) == (((int64_t)13LL)))) { (void)(f325_gslice(n_1587));
return;
 }
if (((k_1589) == (((int64_t)15LL)))) { int64_t t_1835 = f141_at(n_1587); 
int64_t ft_1836 = ((int64_t)(((*({ hrv *_t4920 = &(g568); int64_t _i4920 = f284_fin(((int64_t)((x_1588).a_))); (S1*)_t4920->b + hr_ix(_i4920, _t4920->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:803"); }))).k_)); 
if ((((((*({ hrv *_t4922 = &(g568); int64_t _i4922 = t_1835; (S1*)_t4922->b + hr_ix(_i4922, _t4922->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:803"); }))).k_) == (((uint8_t)3LL))) && (((ft_1836) == (((int64_t)4LL))) || ((ft_1836) == (((int64_t)13LL)))))) { (void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(t_1835));
(void)(f263_ow(hr_str(")hr_f2i(", 8)));
(void)(f297_gx(((int64_t)((x_1588).a_))));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
(void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(t_1835));
(void)(f263_ow(hr_str(")(", 2)));
(void)(f297_gx(((int64_t)((x_1588).a_))));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
if (((k_1589) == (((int64_t)16LL)))) { (void)(f326_garr(n_1587));
return;
 }
if (((k_1589) == (((int64_t)17LL)))) { (void)(f327_gslit(n_1587));
return;
 }
if (((k_1589) == (((int64_t)11LL)))) { if (f289_is_vimg(f141_at(n_1587))) { g195++;
 }
(void)(f328_gcall(n_1587));
return;
 }
if (((k_1589) == (((int64_t)23LL)))) { (void)(f263_ow(hr_str("({ ", 3)));
(void)(f352_gblk(n_1587, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((f141_at(n_1587)) != (g575))));
(void)(f263_ow(hr_str(" })", 3)));
return;
 }
if ((((((k_1589) == (((int64_t)19LL))) || ((k_1589) == (((int64_t)20LL)))) || ((k_1589) == (((int64_t)24LL)))) || ((k_1589) == (((int64_t)26LL))))) { int64_t t_2126 = f141_at(n_1587); 
if ((((t_2126) == (g575)) || ((t_2126) < (((int64_t)0LL))))) { (void)(f263_ow(hr_str("({ ", 3)));
(void)(f344_gstmt(n_1587));
(void)(f263_ow(hr_str(" })", 3)));
return;
 }
int64_t r_2127 = f301_nt(); 
(void)(f263_ow(hr_str("({ ", 3)));
(void)(f264_ct(t_2126));
(void)(f263_ow(hr_str(" _r", 3)));
(void)(f302_oi(r_2127));
(void)(f263_ow(hr_str("; ", 2)));
if (((k_1589) == (((int64_t)19LL)))) { (void)(f351_gif(n_1587, r_2127));
 } else { if (((k_1589) == (((int64_t)20LL)))) { (void)(f360_gmatch(n_1587, r_2127));
 } else { if (((k_1589) == (((int64_t)24LL)))) { (void)(f361_geblock(n_1587, r_2127));
 } else { (void)(f358_gloop(n_1587, r_2127));
 }
 }
 }
(void)(f263_ow(hr_str(" _r", 3)));
(void)(f302_oi(r_2127));
(void)(f263_ow(hr_str("; })", 4)));
return;
 }
if (((((((k_1589) == (((int64_t)28LL))) || ((k_1589) == (((int64_t)29LL)))) || ((k_1589) == (((int64_t)30LL)))) || ((k_1589) == (((int64_t)25LL)))) || ((k_1589) == (((int64_t)27LL))))) { (void)(f263_ow(hr_str("({ ", 3)));
(void)(f344_gstmt(n_1587));
(void)(f263_ow(hr_str(" })", 3)));
return;
 }
(void)(f295_gerr(n_1587, hr_str("unsupported expression in codegen", 33)));
}
static int64_t f281_fin_lit(int64_t n_1590) {
int64_t t_1591 = f141_at(n_1590); 
return ({ int64_t _r4964; if ((((t_1591) < (((int64_t)0LL))) || ((((*({ hrv *_t4965 = &(g568); int64_t _i4965 = t_1591; (S1*)_t4965->b + hr_ix(_i4965, _t4965->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:822"); }))).k_) == (((uint8_t)12LL))))) { _r4964 = g580;  } else { _r4964 = ({ int64_t _r4966; if (((((*({ hrv *_t4967 = &(g568); int64_t _i4967 = t_1591; (S1*)_t4967->b + hr_ix(_i4967, _t4967->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:822"); }))).k_) == (((uint8_t)13LL)))) { _r4966 = g586;  } else { _r4966 = t_1591;  } _r4966; });  } _r4964; });
}
static void f282_oint(int64_t v_1592, bool uns_1593, int64_t t_1594) {
int64_t k_1595 = ((int64_t)(((*({ hrv *_t4968 = &(g568); int64_t _i4968 = t_1594; (S1*)_t4968->b + hr_ix(_i4968, _t4968->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:146"); }))).k_)); 
if (((k_1595) == (((int64_t)4LL)))) { (void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(t_1594));
(void)(f263_ow(hr_str(")", 1)));
if (uns_1593) { (void)(({ hrv *_o4972 = &(g163); hr_fu(_o4972, ((uint64_t)(v_1592))); hr_fs(_o4972, hr_str(".0", 2)); }));
 } else { (void)(({ hrv *_o4973 = &(g163); hr_fi(_o4973, v_1592); hr_fs(_o4973, hr_str(".0", 2)); }));
 }
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if (((k_1595) == (((int64_t)2LL)))) { (void)(f263_ow(({ hsl _r4976; if (((v_1592) != (((int64_t)0LL)))) { _r4976 = hr_str("true", 4);  } else { _r4976 = hr_str("false", 5);  } _r4976; })));
return;
 }
(void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(({ int64_t _r4979; if (((k_1595) == (((int64_t)3LL)))) { _r4979 = t_1594;  } else { _r4979 = g580;  } _r4979; })));
(void)(f263_ow(hr_str(")", 1)));
if (uns_1593) { (void)(({ hrv *_o4981 = &(g163); hr_fu(_o4981, ((uint64_t)(v_1592))); hr_fs(_o4981, hr_str("ULL)", 4)); }));
return;
 }
if (((v_1592) == (((int64_t)((int64_t)((int64_t)(0 - (uint64_t)(((int64_t)9223372036854775807LL)))) - (int64_t)((int64_t)1LL)))))) { (void)(f263_ow(hr_str("(-9223372036854775807LL-1))", 27)));
return;
 }
(void)(({ hrv *_o4983 = &(g163); hr_fi(_o4983, v_1592); hr_fs(_o4983, hr_str("LL)", 3)); }));
}
static void f283_gstr(int64_t n_1597) {
int64_t t_1601 = f284_fin(n_1597); 
hsl s_1604 = f285_tok_str(((int64_t)(((*({ hrv *_t4986 = &(g721); int64_t _i4986 = n_1597; (S4*)_t4986->b + hr_ix(_i4986, _t4986->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:366"); }))).t_))); 
int64_t a_1605 = f141_at(n_1597); 
if (f271_is_res(a_1605)) { (void)(f263_ow(hr_str("hr_rfrom(hr_str(", 16)));
(void)(f286_cstr_lit(s_1604));
(void)(({ hrv *_o4991 = &(g163); hr_fs(_o4991, hr_str(", ", 2)); hr_fi(_o4991, (s_1604).n); hr_fs(_o4991, hr_str("), 1)", 5)); }));
return;
 }
if (f287_is_fix(a_1605)) { (void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(a_1605));
(void)(f263_ow(hr_str("){ ", 3)));
(void)(f286_cstr_lit(s_1604));
(void)(f263_ow(hr_str(" })", 3)));
return;
 }
if (f288_is_lim(a_1605)) { (void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(a_1605));
(void)(({ hrv *_o5001 = &(g163); hr_fs(_o5001, hr_str("){ ", 3)); hr_fi(_o5001, (s_1604).n); hr_fs(_o5001, hr_str(", ", 2)); }));
(void)(f286_cstr_lit(s_1604));
(void)(f263_ow(hr_str(" })", 3)));
return;
 }
if (f289_is_vimg(a_1605)) { g195++;
(void)(f263_ow(hr_str("hr_vfrom(hr_str(", 16)));
(void)(f286_cstr_lit(s_1604));
(void)(({ hrv *_o5007 = &(g163); hr_fs(_o5007, hr_str(", ", 2)); hr_fi(_o5007, (s_1604).n); hr_fs(_o5007, hr_str(")", 1)); }));
(void)(f290_vargs(a_1605));
(void)(f263_ow(hr_str(", 1)", 4)));
return;
 }
(void)(f263_ow(hr_str("hr_str(", 7)));
(void)(f286_cstr_lit(s_1604));
(void)(({ hrv *_o5012 = &(g163); hr_fs(_o5012, hr_str(", ", 2)); hr_fi(_o5012, (s_1604).n); hr_fs(_o5012, hr_str(")", 1)); }));
}
static int64_t f284_fin(int64_t n_1598) {
int64_t c_1599 = f153_cv(n_1598); 
return ({ int64_t _r5014; if (((c_1599) >= (((int64_t)0LL)))) { _r5014 = c_1599;  } else { int64_t t_1600 = f141_at(n_1598); 
_r5014 = ({ int64_t _r5016; if (((t_1600) < (((int64_t)0LL)))) { _r5016 = g575;  } else { _r5016 = t_1600;  } _r5016; });  } _r5014; });
}
static hsl f285_tok_str(int64_t t_1602) {
S3 x_1603 = (*({ hrv *_t5017 = &(g931); int64_t _i5017 = t_1602; (S3*)_t5017->b + hr_ix(_i5017, _t5017->n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:182"); })); 
return ({ hsl _t5018 = hr_sl(g927); int64_t _l5018 = ((int64_t)((x_1603).v_)), _h5018 = ((int64_t)((int64_t)((int64_t)((x_1603).v_)) + (int64_t)((int64_t)((x_1603).w_)))); if (_l5018 < 0 || _h5018 < _l5018 || _h5018 > _t5018.n) hr_slerr(_l5018, _h5018, _t5018.n, "/home/anmire/ai/amni-lang/helium-self/hc/lex.amni:182"); (hsl){ _t5018.p + _l5018 * (int64_t)sizeof(uint8_t), _h5018 - _l5018 }; });
}
static void f286_cstr_lit(hsl s_1606) {
(void)(({ hrv *_v5019 = &(g163); uint8_t _x5019 = ((uint8_t)34LL); uint8_t *_p5019 = (uint8_t*)hr_grow(_v5019, 1, sizeof _x5019); *_p5019 = _x5019; _p5019; }));
{ hsl _v5021 = s_1606; for (int64_t _k5021 = 0; _k5021 < _v5021.n; _k5021++) { uint8_t c_1607 = ((uint8_t*)_v5021.p)[_k5021]; if ((((c_1607) == (((uint8_t)34LL))) || ((c_1607) == (((uint8_t)92LL))))) { (void)(({ hrv *_v5022 = &(g163); uint8_t _x5022 = ((uint8_t)92LL); uint8_t *_p5022 = (uint8_t*)hr_grow(_v5022, 1, sizeof _x5022); *_p5022 = _x5022; _p5022; }));
(void)(({ hrv *_v5023 = &(g163); uint8_t _x5023 = c_1607; uint8_t *_p5023 = (uint8_t*)hr_grow(_v5023, 1, sizeof _x5023); *_p5023 = _x5023; _p5023; }));
 } else { if (((((c_1607) >= (((uint8_t)32LL))) && ((c_1607) < (((uint8_t)127LL)))) && ((c_1607) != (((uint8_t)63LL))))) { (void)(({ hrv *_v5024 = &(g163); uint8_t _x5024 = c_1607; uint8_t *_p5024 = (uint8_t*)hr_grow(_v5024, 1, sizeof _x5024); *_p5024 = _x5024; _p5024; }));
 } else { (void)(({ hrv *_v5025 = &(g163); uint8_t _x5025 = ((uint8_t)92LL); uint8_t *_p5025 = (uint8_t*)hr_grow(_v5025, 1, sizeof _x5025); *_p5025 = _x5025; _p5025; }));
(void)(({ hrv *_v5026 = &(g163); uint8_t _x5026 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)((uint8_t)((c_1607) >> ((((int64_t)6LL)) & 7))) & (uint64_t)((uint8_t)7LL))))); uint8_t *_p5026 = (uint8_t*)hr_grow(_v5026, 1, sizeof _x5026); *_p5026 = _x5026; _p5026; }));
(void)(({ hrv *_v5027 = &(g163); uint8_t _x5027 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)((uint8_t)((c_1607) >> ((((int64_t)3LL)) & 7))) & (uint64_t)((uint8_t)7LL))))); uint8_t *_p5027 = (uint8_t*)hr_grow(_v5027, 1, sizeof _x5027); *_p5027 = _x5027; _p5027; }));
(void)(({ hrv *_v5028 = &(g163); uint8_t _x5028 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)c_1607 & (uint64_t)((uint8_t)7LL))))); uint8_t *_p5028 = (uint8_t*)hr_grow(_v5028, 1, sizeof _x5028); *_p5028 = _x5028; _p5028; }));
 }
 }
 } } _bk5020:; 
(void)(({ hrv *_v5029 = &(g163); uint8_t _x5029 = ((uint8_t)34LL); uint8_t *_p5029 = (uint8_t*)hr_grow(_v5029, 1, sizeof _x5029); *_p5029 = _x5029; _p5029; }));
}
static bool f287_is_fix(int64_t t_1608) {
return (((((*({ hrv *_t5030 = &(g568); int64_t _i5030 = t_1608; (S1*)_t5030->b + hr_ix(_i5030, _t5030->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:26"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t5031 = &(g568); int64_t _i5031 = t_1608; (S1*)_t5031->b + hr_ix(_i5031, _t5031->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:26"); }))).s_))) == (((int64_t)1LL))));
}
static bool f288_is_lim(int64_t t_1609) {
return ((((((*({ hrv *_t5032 = &(g568); int64_t _i5032 = t_1609; (S1*)_t5032->b + hr_ix(_i5032, _t5032->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:19"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t5033 = &(g568); int64_t _i5033 = t_1609; (S1*)_t5033->b + hr_ix(_i5033, _t5033->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:19"); }))).s_))) == (((int64_t)3LL)))) && ((((*({ hrv *_t5034 = &(g568); int64_t _i5034 = t_1609; (S1*)_t5034->b + hr_ix(_i5034, _t5034->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:19"); }))).b_) >= (((int64_t)0LL))));
}
static bool f289_is_vimg(int64_t t_1610) {
return ((((t_1610) >= (((int64_t)0LL))) && ((((*({ hrv *_t5035 = &(g568); int64_t _i5035 = t_1610; (S1*)_t5035->b + hr_ix(_i5035, _t5035->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:20"); }))).k_) == (((uint8_t)8LL)))) && (((((int64_t)(((*({ hrv *_t5036 = &(g568); int64_t _i5036 = t_1610; (S1*)_t5036->b + hr_ix(_i5036, _t5036->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:20"); }))).s_))) == (((int64_t)2LL))) || (((((int64_t)(((*({ hrv *_t5037 = &(g568); int64_t _i5037 = t_1610; (S1*)_t5037->b + hr_ix(_i5037, _t5037->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:20"); }))).s_))) == (((int64_t)3LL))) && ((((*({ hrv *_t5038 = &(g568); int64_t _i5038 = t_1610; (S1*)_t5038->b + hr_ix(_i5038, _t5038->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:20"); }))).b_) < (((int64_t)0LL))))));
}
static void f290_vargs(int64_t t_1611) {
(void)(({ hrv *_o5039 = &(g163); hr_fs(_o5039, hr_str(", ", 2)); hr_fi(_o5039, f151_isz(((int64_t)(((*({ hrv *_t5041 = &(g568); int64_t _i5041 = t_1611; (S1*)_t5041->b + hr_ix(_i5041, _t5041->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:22"); }))).c_)))); hr_fs(_o5039, hr_str(", ", 2)); hr_fi(_o5039, f291_vlim(t_1611)); }));
}
static int64_t f291_vlim(int64_t t_1612) {
return ({ int64_t _r5043; if (((((int64_t)(((*({ hrv *_t5044 = &(g568); int64_t _i5044 = t_1612; (S1*)_t5044->b + hr_ix(_i5044, _t5044->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:21"); }))).s_))) == (((int64_t)3LL)))) { _r5043 = ((int64_t)1LL);  } else { _r5043 = ((int64_t)0LL);  } _r5043; });
}
static void f292_lv_expr(int64_t v_1615) {
bool p_1617 = f293_lv_isptr(v_1615); 
if (((((int64_t)(((*({ hrv *_t5046 = &(g402); int64_t _i5046 = v_1615; (S12*)_t5046->b + hr_ix(_i5046, _t5046->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:121"); }))).cfn_))) != (g179))) { (void)(f263_ow(({ hsl _r5048; if (p_1617) { _r5048 = hr_str("(**c", 4);  } else { _r5048 = hr_str("(*c", 3);  } _r5048; })));
(void)(({ hrv *_o5049 = &(g163); hr_fi(_o5049, v_1615); hr_fs(_o5049, hr_str(")", 1)); }));
return;
 }
if (p_1617) { (void)(f263_ow(hr_str("(*", 2)));
(void)(f294_lv_name(v_1615));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
(void)(f294_lv_name(v_1615));
}
static bool f293_lv_isptr(int64_t v_1616) {
return (((((uint16_t)((uint64_t)((*({ hrv *_t5054 = &(g402); int64_t _i5054 = v_1616; (S12*)_t5054->b + hr_ix(_i5054, _t5054->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:118"); }))).fl_ & (uint64_t)((uint16_t)8LL)))) != (((uint16_t)0LL))) && ((((*({ hrv *_t5055 = &(g568); int64_t _i5055 = ((*({ hrv *_t5056 = &(g402); int64_t _i5056 = v_1616; (S12*)_t5056->b + hr_ix(_i5056, _t5056->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:118"); }))).ty_; (S1*)_t5055->b + hr_ix(_i5055, _t5055->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:118"); }))).k_) != (((uint8_t)10LL))));
}
static void f294_lv_name(int64_t v_1618) {
{ hsl _v5058 = f10_nm(((int64_t)(((*({ hrv *_t5060 = &(g402); int64_t _i5060 = v_1618; (S12*)_t5060->b + hr_ix(_i5060, _t5060->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:117"); }))).name_))); for (int64_t _k5058 = 0; _k5058 < _v5058.n; _k5058++) { uint8_t c_1619 = ((uint8_t*)_v5058.p)[_k5058]; (void)(({ hrv *_v5061 = &(g163); uint8_t _x5061 = ({ uint8_t _r5062; if ((((c_1619) == (((uint8_t)36LL))) || ((c_1619) == (((uint8_t)58LL))))) { _r5062 = ((uint8_t)95LL);  } else { _r5062 = c_1619;  } _r5062; }); uint8_t *_p5061 = (uint8_t*)hr_grow(_v5061, 1, sizeof _x5061); *_p5061 = _x5061; _p5061; }));
 } } _bk5057:; 
(void)(({ hrv *_o5063 = &(g163); hr_fs(_o5063, hr_str("_", 1)); hr_fi(_o5063, v_1618); }));
}
static void f295_gerr(int64_t n_1620, hsl m_1621) {
if ((((g182).n) > (((int64_t)0LL)))) { return;
 }
S3 x_1622 = (*({ hrv *_t5064 = &(g931); int64_t _i5064 = ((*({ hrv *_t5065 = &(g721); int64_t _i5065 = f103_max(n_1620, ((int64_t)0LL)); (S4*)_t5065->b + hr_ix(_i5065, _t5065->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:15"); }))).t_; (S3*)_t5064->b + hr_ix(_i5064, _t5064->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:15"); })); 
(void)(({ hrv *_v5067 = &(g182); hsl _s5067 = f10_nm(((int64_t)(((*({ hrv *_t5069 = &(g930); int64_t _i5069 = (x_1622).f_; (S2*)_t5069->b + hr_ix(_i5069, _t5069->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:15"); }))).name_))); hr_append(_v5067, _s5067.p, _s5067.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o5070 = &(g182); hr_fs(_o5070, hr_str(":", 1)); hr_fi(_o5070, (x_1622).line_); hr_fs(_o5070, hr_str(": error: ", 9)); hr_fs(_o5070, m_1621); }));
}
static void f296_gbin(int64_t n_1623) {
S4 x_1624 = (*({ hrv *_t5071 = &(g721); int64_t _i5071 = n_1623; (S4*)_t5071->b + hr_ix(_i5071, _t5071->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:272"); })); 
int64_t o_1625 = ((int64_t)((x_1624).op_)); 
int64_t a_1626 = ((int64_t)((x_1624).a_)); 
int64_t b_1627 = ((int64_t)((x_1624).b_)); 
if ((((o_1625) == (((int64_t)52LL))) || ((o_1625) == (((int64_t)53LL))))) { (void)(f263_ow(hr_str("(", 1)));
(void)(f297_gx(a_1626));
(void)(f263_ow(({ hsl _r5075; if (((o_1625) == (((int64_t)52LL)))) { _r5075 = hr_str(" && ", 4);  } else { _r5075 = hr_str(" || ", 4);  } _r5075; })));
(void)(f297_gx(b_1627));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
bool cmp_1631 = (((((((o_1625) == (((int64_t)37LL))) || ((o_1625) == (((int64_t)38LL)))) || ((o_1625) == (((int64_t)39LL)))) || ((o_1625) == (((int64_t)40LL)))) || ((o_1625) == (((int64_t)41LL)))) || ((o_1625) == (((int64_t)42LL)))); 
if (cmp_1631) { int64_t m_1632 = f220_ax(n_1623); 
int64_t ta_1633 = f284_fin(a_1626); 
int64_t tb_1634 = f284_fin(b_1627); 
if (((m_1632) == (((int64_t)1LL)))) { (void)(f263_ow(hr_str("((uint64_t)(", 12)));
(void)(f297_gx(a_1626));
(void)(f263_ow(hr_str(") ", 2)));
(void)(f263_ow(f298_cmp_op(o_1625)));
(void)(f263_ow(hr_str(" (uint64_t)(", 12)));
(void)(f297_gx(b_1627));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
if (((m_1632) == (((int64_t)2LL)))) { if (((o_1625) == (((int64_t)38LL)))) { (void)(f263_ow(hr_str("!", 1)));
 }
(void)(f263_ow(hr_str("hr_streq(", 9)));
(void)(f299_gas(a_1626));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f299_gas(b_1627));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if (((m_1632) == (((int64_t)3LL)))) { int64_t et_1651 = ({ int64_t _r5095; if ((((((*({ hrv *_t5096 = &(g568); int64_t _i5096 = ta_1633; (S1*)_t5096->b + hr_ix(_i5096, _t5096->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:280"); }))).k_) == (((uint8_t)7LL))) || ((((*({ hrv *_t5097 = &(g568); int64_t _i5097 = ta_1633; (S1*)_t5097->b + hr_ix(_i5097, _t5097->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:280"); }))).k_) == (((uint8_t)19LL))))) { _r5095 = tb_1634;  } else { _r5095 = ta_1633;  } _r5095; }); 
(void)(f304_gen_heq(et_1651));
if (((o_1625) == (((int64_t)38LL)))) { (void)(f263_ow(hr_str("!", 1)));
 }
(void)(f263_ow(hr_str("heq", 3)));
(void)(f302_oi(et_1651));
(void)(f263_ow(hr_str("(", 1)));
if (f314_hsl_ty(et_1651)) { (void)(f299_gas(a_1626));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f299_gas(b_1627));
 } else { (void)(f315_gxas(a_1626, et_1651));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f315_gxas(b_1627, et_1651));
 }
(void)(f263_ow(hr_str(")", 1)));
return;
 }
int64_t ka_1755 = ((int64_t)(((*({ hrv *_t5111 = &(g568); int64_t _i5111 = ta_1633; (S1*)_t5111->b + hr_ix(_i5111, _t5111->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:281"); }))).k_)); 
if (((((ka_1755) == (((int64_t)10LL))) || ((ka_1755) == (((int64_t)11LL)))) || ((((*({ hrv *_t5112 = &(g568); int64_t _i5112 = tb_1634; (S1*)_t5112->b + hr_ix(_i5112, _t5112->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:282"); }))).k_) == (((uint8_t)10LL))))) { (void)(f263_ow(hr_str("((void*)(", 9)));
(void)(f297_gx(a_1626));
(void)(f263_ow(hr_str(") ", 2)));
(void)(f263_ow(f298_cmp_op(o_1625)));
(void)(f263_ow(hr_str(" (void*)(", 9)));
(void)(f297_gx(b_1627));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
(void)(f263_ow(hr_str("((", 2)));
(void)(f297_gx(a_1626));
(void)(f263_ow(hr_str(") ", 2)));
(void)(f263_ow(f298_cmp_op(o_1625)));
(void)(f263_ow(hr_str(" (", 2)));
(void)(f297_gx(b_1627));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
(void)(f316_garith(o_1625, f284_fin(n_1623), a_1626, b_1627, ((int64_t)0LL), n_1623));
}
static void f297_gx(int64_t n_1628) {
int64_t c_1629 = f153_cv(n_1628); 
int64_t t_1630 = f141_at(n_1628); 
if ((((c_1629) < (((int64_t)0LL))) || ((c_1629) == (t_1630)))) { (void)(f274_gx1(n_1628));
return;
 }
(void)(f273_gcv(n_1628, t_1630, c_1629));
}
static hsl f298_cmp_op(int64_t o_1635) {
if (((o_1635) == (((int64_t)37LL)))) { return hr_str("==", 2);
 }
if (((o_1635) == (((int64_t)38LL)))) { return hr_str("!=", 2);
 }
if (((o_1635) == (((int64_t)39LL)))) { return hr_str("<", 1);
 }
if (((o_1635) == (((int64_t)40LL)))) { return hr_str(">", 1);
 }
if (((o_1635) == (((int64_t)41LL)))) { return hr_str("<=", 2);
 }
if (((o_1635) == (((int64_t)42LL)))) { return hr_str(">=", 2);
 }
return hr_str("\077", 1);
}
static void f299_gas(int64_t n_1636) {
int64_t c_1637 = f153_cv(n_1636); 
int64_t t_1638 = f141_at(n_1636); 
if (((((c_1637) >= (((int64_t)0LL))) && ((c_1637) != (t_1638))) && ((((*({ hrv *_t5137 = &(g568); int64_t _i5137 = c_1637; (S1*)_t5137->b + hr_ix(_i5137, _t5137->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:209"); }))).k_) == (((uint8_t)9LL))))) { (void)(f300_gsl(n_1636, t_1638));
return;
 }
if ((((c_1637) >= (((int64_t)0LL))) && ((c_1637) != (t_1638)))) { int64_t p_1650 = f301_nt(); 
(void)(f263_ow(hr_str("({ ", 3)));
(void)(f264_ct(c_1637));
(void)(f263_ow(hr_str(" _t", 3)));
(void)(f302_oi(p_1650));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(n_1636));
(void)(f263_ow(hr_str("; ", 2)));
if (f271_is_res(c_1637)) { (void)(f263_ow(hr_str("hr_sl(_t", 8)));
(void)(f302_oi(p_1650));
(void)(f263_ow(hr_str(")", 1)));
 } else { if (f287_is_fix(c_1637)) { (void)(f263_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f302_oi(p_1650));
(void)(({ hrv *_o5154 = &(g163); hr_fs(_o5154, hr_str(".e, ", 4)); hr_fi(_o5154, ((*({ hrv *_t5155 = &(g568); int64_t _i5155 = c_1637; (S1*)_t5155->b + hr_ix(_i5155, _t5155->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:210"); }))).b_); hr_fs(_o5154, hr_str(" }", 2)); }));
 } else { if (((((*({ hrv *_t5156 = &(g568); int64_t _i5156 = c_1637; (S1*)_t5156->b + hr_ix(_i5156, _t5156->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:210"); }))).k_) == (((uint8_t)9LL)))) { (void)(f263_ow(hr_str("_t", 2)));
(void)(f302_oi(p_1650));
 } else { (void)(f263_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f302_oi(p_1650));
(void)(f263_ow(hr_str(".e, _t", 6)));
(void)(f302_oi(p_1650));
(void)(f263_ow(hr_str(".n }", 4)));
 }
 }
 }
(void)(f263_ow(hr_str("; })", 4)));
return;
 }
(void)(f300_gsl(n_1636, t_1638));
}
static void f300_gsl(int64_t n_1639, int64_t f_1640) {
int64_t d_1641 = f182_deref(f_1640); 
int64_t k_1642 = ((int64_t)(((*({ hrv *_t5167 = &(g568); int64_t _i5167 = d_1641; (S1*)_t5167->b + hr_ix(_i5167, _t5167->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:184"); }))).k_)); 
if ((((((*({ hrv *_t5168 = &(g568); int64_t _i5168 = f_1640; (S1*)_t5168->b + hr_ix(_i5168, _t5168->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:185"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t5169 = &(g568); int64_t _i5169 = f_1640; (S1*)_t5169->b + hr_ix(_i5169, _t5169->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:185"); }))).c_) < (((int32_t)0LL))))) { int64_t p_1643 = f301_nt(); 
(void)(f263_ow(hr_str("({ ", 3)));
(void)(f264_ct(f_1640));
(void)(f263_ow(hr_str(" _t", 3)));
(void)(f302_oi(p_1643));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f280_gx0(n_1639));
(void)(f263_ow(hr_str("; ", 2)));
if (((k_1642) == (((int64_t)9LL)))) { (void)(f263_ow(hr_str("*_t", 3)));
(void)(f302_oi(p_1643));
 } else { if (f289_is_vimg(d_1641)) { (void)(f263_ow(hr_str("hr_vsl(*_t", 10)));
(void)(f302_oi(p_1643));
(void)(f290_vargs(d_1641));
(void)(f263_ow(hr_str(")", 1)));
 } else { if (f271_is_res(d_1641)) { (void)(f263_ow(hr_str("hr_sl(*_t", 9)));
(void)(f302_oi(p_1643));
(void)(f263_ow(hr_str(")", 1)));
 } else { if (f287_is_fix(d_1641)) { (void)(f263_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f302_oi(p_1643));
(void)(({ hrv *_o5192 = &(g163); hr_fs(_o5192, hr_str("->e, ", 5)); hr_fi(_o5192, ((*({ hrv *_t5193 = &(g568); int64_t _i5193 = d_1641; (S1*)_t5193->b + hr_ix(_i5193, _t5193->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:191"); }))).b_); hr_fs(_o5192, hr_str(" }", 2)); }));
 } else { (void)(f263_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f302_oi(p_1643));
(void)(f263_ow(hr_str("->e, _t", 7)));
(void)(f302_oi(p_1643));
(void)(f263_ow(hr_str("->n }", 5)));
 }
 }
 }
 }
(void)(f263_ow(hr_str("; })", 4)));
return;
 }
if ((((k_1642) == (((int64_t)9LL))) || ((k_1642) == (((int64_t)18LL))))) { (void)(f280_gx0(n_1639));
return;
 }
if (f289_is_vimg(d_1641)) { if ((!(f303_vok(n_1639, d_1641)))) { return;
 }
(void)(f263_ow(hr_str("hr_vsl(", 7)));
(void)(f280_gx0(n_1639));
(void)(f290_vargs(d_1641));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if (f271_is_res(d_1641)) { (void)(f263_ow(hr_str("hr_sl(", 6)));
if (f275_is_place(n_1639)) { (void)(f280_gx0(n_1639));
 } else { int64_t tk0_1647 = f278_tmp(d_1641, true); 
(void)(f263_ow(hr_str("*hr_tmp(&", 9)));
(void)(f279_ot(tk0_1647));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f280_gx0(n_1639));
(void)(f263_ow(hr_str(")", 1)));
 }
(void)(f263_ow(hr_str(")", 1)));
return;
 }
int64_t p_1648 = f301_nt(); 
(void)(f263_ow(hr_str("({ ", 3)));
(void)(f264_ct(d_1641));
(void)(f263_ow(hr_str(" *_t", 4)));
(void)(f302_oi(p_1648));
(void)(f263_ow(hr_str(" = ", 3)));
if (f275_is_place(n_1639)) { (void)(f263_ow(hr_str("&(", 2)));
(void)(f280_gx0(n_1639));
(void)(f263_ow(hr_str(")", 1)));
 } else { int64_t tk0_1649 = f278_tmp(d_1641, false); 
(void)(f263_ow(hr_str("(", 1)));
(void)(f279_ot(tk0_1649));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f280_gx0(n_1639));
(void)(f263_ow(hr_str(", &", 3)));
(void)(f279_ot(tk0_1649));
(void)(f263_ow(hr_str(")", 1)));
 }
(void)(f263_ow(hr_str("; ", 2)));
if (f287_is_fix(d_1641)) { (void)(f263_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f302_oi(p_1648));
(void)(({ hrv *_o5240 = &(g163); hr_fs(_o5240, hr_str("->e, ", 5)); hr_fi(_o5240, ((*({ hrv *_t5241 = &(g568); int64_t _i5241 = d_1641; (S1*)_t5241->b + hr_ix(_i5241, _t5241->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:203"); }))).b_); hr_fs(_o5240, hr_str(" }", 2)); }));
 } else { (void)(f263_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f302_oi(p_1648));
(void)(f263_ow(hr_str("->e, _t", 7)));
(void)(f302_oi(p_1648));
(void)(f263_ow(hr_str("->n }", 5)));
 }
(void)(f263_ow(hr_str("; })", 4)));
}
static int64_t f301_nt(void) {
g178++;
return g178;
}
static void f302_oi(int64_t v_1644) {
(void)(({ hrv *_o5248 = &(g163); hr_fi(_o5248, v_1644); }));
}
static bool f303_vok(int64_t n_1645, int64_t t_1646) {
if (((((*({ hrv *_t5249 = &(g568); int64_t _i5249 = t_1646; (S1*)_t5249->b + hr_ix(_i5249, _t5249->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:23"); }))).c_) == (((int32_t)8LL)))) { (void)(f295_gerr(n_1645, hr_str("varint array lengths are not supported by the self-hosted compiler yet", 70)));
return false;
 }
if ((!(f208_is_fixed(((int64_t)(((*({ hrv *_t5252 = &(g568); int64_t _i5252 = t_1646; (S1*)_t5252->b + hr_ix(_i5252, _t5252->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:23"); }))).a_)))))) { (void)(f295_gerr(n_1645, hr_str("arrays of variable-size elements are not supported by the self-hosted compiler yet", 82)));
return false;
 }
return true;
}
static void f304_gen_heq(int64_t t_1652) {
(void)(f266_cn_grow());
if ((((*({ hrv *_t5255 = &(g175); int64_t _i5255 = t_1652; (uint8_t*)_t5255->b + hr_ix(_i5255, _t5255->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:508"); }))) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t5256 = &((*({ hrv *_t5257 = &(g175); int64_t _i5257 = t_1652; (uint8_t*)_t5257->b + hr_ix(_i5257, _t5257->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:509"); }))); *_t5256 = ((uint8_t)1LL); }
S1 x_1653 = (*({ hrv *_t5258 = &(g568); int64_t _i5258 = t_1652; (S1*)_t5258->b + hr_ix(_i5258, _t5258->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:510"); })); 
int64_t k_1654 = ((int64_t)((x_1653).k_)); 
(void)(f265_cbody(t_1652));
bool sl_1655 = (((k_1654) == (((int64_t)9LL))) || ((((k_1654) == (((int64_t)8LL))) && (!(f287_is_fix(t_1652)))) && (!(f288_is_lim(t_1652))))); 
(void)(f305_comp_pre(t_1652, false));
L99 sig_1729 = ({ L99 _t5263; memset(&_t5263, 0, sizeof _t5263); _t5263.n = 0; _t5263; }); 
(void)(({ L99 *_l5264 = &(sig_1729); hrv _o5264 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5264, hr_str("static bool heq", 15)); hr_fi(&_o5264, t_1652); hr_fs(&_o5264, hr_str("(", 1)); if (_l5264->n + _o5264.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:515"); memcpy(_l5264->e + _l5264->n, _o5264.b, (size_t)_o5264.n); _l5264->n += _o5264.n; }));
hsl c_1730 = ({ hsl _r5265; if (sl_1655) { _r5265 = hr_str("hsl", 3);  } else { _r5265 = f267_cn(t_1652);  } _r5265; }); 
(void)(({ L99 *_v5267 = &(sig_1729); hsl _s5267 = c_1730; if (_v5267->n + _s5267.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:517"); memmove(_v5267->e + _v5267->n, _s5267.p, (size_t)_s5267.n * sizeof _v5267->e[0]); _v5267->n += _s5267.n; }));
(void)(({ L99 *_v5268 = &(sig_1729); hsl _s5268 = hr_str(" a, ", 4); if (_v5268->n + _s5268.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:517"); memmove(_v5268->e + _v5268->n, _s5268.p, (size_t)_s5268.n * sizeof _v5268->e[0]); _v5268->n += _s5268.n; }));
(void)(({ L99 *_v5269 = &(sig_1729); hsl _s5269 = c_1730; if (_v5269->n + _s5269.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:517"); memmove(_v5269->e + _v5269->n, _s5269.p, (size_t)_s5269.n * sizeof _v5269->e[0]); _v5269->n += _s5269.n; }));
(void)(({ L99 *_v5270 = &(sig_1729); hsl _s5270 = hr_str(" b)", 3); if (_v5270->n + _s5270.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:517"); memmove(_v5270->e + _v5270->n, _s5270.p, (size_t)_s5270.n * sizeof _v5270->e[0]); _v5270->n += _s5270.n; }));
(void)(({ hrv *_v5271 = &(g166); hsl _s5271 = ({ hsl _t5272 = ({ L99 *_t5273 = &(sig_1729); (hsl){ (uint8_t*)_t5273->e, _t5273->n }; }); int64_t _l5272 = 0, _h5272 = _t5272.n; if (_l5272 < 0 || _h5272 < _l5272 || _h5272 > _t5272.n) hr_slerr(_l5272, _h5272, _t5272.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:518"); (hsl){ _t5272.p + _l5272 * (int64_t)sizeof(uint8_t), _h5272 - _l5272 }; }); hr_append(_v5271, _s5271.p, _s5271.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5274 = &(g166); hsl _s5274 = hr_str(";\012", 2); hr_append(_v5274, _s5274.p, _s5274.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5275 = &(g169); hsl _s5275 = ({ hsl _t5276 = ({ L99 *_t5277 = &(sig_1729); (hsl){ (uint8_t*)_t5277->e, _t5277->n }; }); int64_t _l5276 = 0, _h5276 = _t5276.n; if (_l5276 < 0 || _h5276 < _l5276 || _h5276 > _t5276.n) hr_slerr(_l5276, _h5276, _t5276.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:519"); (hsl){ _t5276.p + _l5276 * (int64_t)sizeof(uint8_t), _h5276 - _l5276 }; }); hr_append(_v5275, _s5275.p, _s5275.n, sizeof(uint8_t)); }));
(void)(f310_hh(hr_str(" { ", 3)));
if ((((k_1654) == (((int64_t)5LL))) || ((k_1654) == (((int64_t)7LL))))) { int64_t si_1731 = ({ int64_t _r5279; if (((k_1654) == (((int64_t)5LL)))) { _r5279 = ((int64_t)((x_1653).a_));  } else { _r5279 = ((int64_t)(((*({ hrv *_t5280 = &(g574); int64_t _i5280 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5281 = &(g573); int64_t _i5281 = (x_1653).a_; (S8*)_t5281->b + hr_ix(_i5281, _t5281->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:521"); }))).v0_)) + (int64_t)((int64_t)((x_1653).c_)))); (S9*)_t5280->b + hr_ix(_i5280, _t5280->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:521"); }))).si_));  } _r5279; }); 
(void)(f310_hh(hr_str("return true", 11)));
if (((si_1731) >= (((int64_t)0LL)))) { int64_t f0_1732 = ((int64_t)(((*({ hrv *_t5283 = &(g571); int64_t _i5283 = si_1731; (S10*)_t5283->b + hr_ix(_i5283, _t5283->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:523"); }))).f0_)); 
{ int32_t _e5285 = ((*({ hrv *_t5286 = &(g571); int64_t _i5286 = si_1731; (S10*)_t5286->b + hr_ix(_i5286, _t5286->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:523"); }))).fnum_; for (int32_t _k5285 = 0; _k5285 < _e5285; _k5285++) { int32_t i_1733 = (int32_t)_k5285; S11 f_1734 = (*({ hrv *_t5287 = &(g572); int64_t _i5287 = ((int64_t)((int64_t)f0_1732 + (int64_t)((int64_t)(i_1733)))); (S11*)_t5287->b + hr_ix(_i5287, _t5287->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:523"); })); 
if ((((f_1734).ty_) < (((int32_t)0LL)))) { continue;
 }
L100 ea_1735 = ({ L100 _t5288; memset(&_t5288, 0, sizeof _t5288); _t5288.n = 0; _t5288; }); 
L100 eb_1736 = ({ L100 _t5289; memset(&_t5289, 0, sizeof _t5289); _t5289.n = 0; _t5289; }); 
(void)(({ L100 *_v5290 = &(ea_1735); hsl _s5290 = hr_str("a.", 2); if (_v5290->n + _s5290.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:523"); memmove(_v5290->e + _v5290->n, _s5290.p, (size_t)_s5290.n * sizeof _v5290->e[0]); _v5290->n += _s5290.n; }));
(void)(({ L100 *_v5291 = &(eb_1736); hsl _s5291 = hr_str("b.", 2); if (_v5291->n + _s5291.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:523"); memmove(_v5291->e + _v5291->n, _s5291.p, (size_t)_s5291.n * sizeof _v5291->e[0]); _v5291->n += _s5291.n; }));
{ hsl _v5293 = f10_nm(((int64_t)((f_1734).name_))); for (int64_t _k5293 = 0; _k5293 < _v5293.n; _k5293++) { uint8_t ch_1737 = ((uint8_t*)_v5293.p)[_k5293]; (void)(({ L100 *_v5295 = &(ea_1735); uint8_t _x5295 = ch_1737; if (_v5295->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:523"); _v5295->e[_v5295->n] = _x5295; &_v5295->e[_v5295->n++]; }));
(void)(({ L100 *_v5296 = &(eb_1736); uint8_t _x5296 = ch_1737; if (_v5296->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:523"); _v5296->e[_v5296->n] = _x5296; &_v5296->e[_v5296->n++]; }));
 } } _bk5292:; 
(void)(({ L100 *_v5297 = &(ea_1735); uint8_t _x5297 = ((uint8_t)95LL); if (_v5297->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:523"); _v5297->e[_v5297->n] = _x5297; &_v5297->e[_v5297->n++]; }));
(void)(({ L100 *_v5298 = &(eb_1736); uint8_t _x5298 = ((uint8_t)95LL); if (_v5298->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:523"); _v5298->e[_v5298->n] = _x5298; &_v5298->e[_v5298->n++]; }));
(void)(f310_hh(hr_str(" && ", 4)));
(void)(f313_heq_val(((int64_t)((f_1734).ty_)), ({ hsl _t5301 = ({ L100 *_t5302 = &(ea_1735); (hsl){ (uint8_t*)_t5302->e, _t5302->n }; }); int64_t _l5301 = 0, _h5301 = _t5301.n; if (_l5301 < 0 || _h5301 < _l5301 || _h5301 > _t5301.n) hr_slerr(_l5301, _h5301, _t5301.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:523"); (hsl){ _t5301.p + _l5301 * (int64_t)sizeof(uint8_t), _h5301 - _l5301 }; }), ({ hsl _t5303 = ({ L100 *_t5304 = &(eb_1736); (hsl){ (uint8_t*)_t5304->e, _t5304->n }; }); int64_t _l5303 = 0, _h5303 = _t5303.n; if (_l5303 < 0 || _h5303 < _l5303 || _h5303 > _t5303.n) hr_slerr(_l5303, _h5303, _t5303.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:523"); (hsl){ _t5303.p + _l5303 * (int64_t)sizeof(uint8_t), _h5303 - _l5303 }; })));
 } } _bk5284:; 
 }
(void)(f310_hh(hr_str("; ", 2)));
 }
if (((k_1654) == (((int64_t)6LL)))) { int64_t ei_1742 = ((int64_t)((x_1653).a_)); 
int64_t v0_1743 = ((int64_t)(((*({ hrv *_t5306 = &(g573); int64_t _i5306 = ei_1742; (S8*)_t5306->b + hr_ix(_i5306, _t5306->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:527"); }))).v0_)); 
(void)(f310_hh(hr_str("if (a.tag != b.tag) return false; ", 34)));
{ int32_t _e5309 = ((*({ hrv *_t5310 = &(g573); int64_t _i5310 = ei_1742; (S8*)_t5310->b + hr_ix(_i5310, _t5310->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:529"); }))).vnum_; for (int32_t _k5309 = 0; _k5309 < _e5309; _k5309++) { int32_t i_1744 = (int32_t)_k5309; S9 v_1745 = (*({ hrv *_t5311 = &(g574); int64_t _i5311 = ((int64_t)((int64_t)v0_1743 + (int64_t)((int64_t)(i_1744)))); (S9*)_t5311->b + hr_ix(_i5311, _t5311->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:529"); })); 
if (((((v_1745).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t5312 = &(g571); int64_t _i5312 = (v_1745).si_; (S10*)_t5312->b + hr_ix(_i5312, _t5312->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:529"); }))).zero_)))) { L102 ea_1746 = ({ L102 _t5313; memset(&_t5313, 0, sizeof _t5313); _t5313.n = 0; _t5313; }); 
L102 eb_1747 = ({ L102 _t5314; memset(&_t5314, 0, sizeof _t5314); _t5314.n = 0; _t5314; }); 
(void)(({ L102 *_l5315 = &(ea_1746); hrv _o5315 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5315, hr_str("a.u.v", 5)); hr_fi(&_o5315, i_1744); if (_l5315->n + _o5315.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:529"); memcpy(_l5315->e + _l5315->n, _o5315.b, (size_t)_o5315.n); _l5315->n += _o5315.n; }));
(void)(({ L102 *_l5316 = &(eb_1747); hrv _o5316 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5316, hr_str("b.u.v", 5)); hr_fi(&_o5316, i_1744); if (_l5316->n + _o5316.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:529"); memcpy(_l5316->e + _l5316->n, _o5316.b, (size_t)_o5316.n); _l5316->n += _o5316.n; }));
(void)(({ hrv *_o5317 = &(g169); hr_fs(_o5317, hr_str("if (a.tag == ", 13)); hr_fi(_o5317, i_1744); hr_fs(_o5317, hr_str(") return ", 9)); }));
(void)(f313_heq_val(f125_t_variant(ei_1742, ((int64_t)(i_1744))), ({ hsl _t5320 = ({ L102 *_t5321 = &(ea_1746); (hsl){ (uint8_t*)_t5321->e, _t5321->n }; }); int64_t _l5320 = 0, _h5320 = _t5320.n; if (_l5320 < 0 || _h5320 < _l5320 || _h5320 > _t5320.n) hr_slerr(_l5320, _h5320, _t5320.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:529"); (hsl){ _t5320.p + _l5320 * (int64_t)sizeof(uint8_t), _h5320 - _l5320 }; }), ({ hsl _t5322 = ({ L102 *_t5323 = &(eb_1747); (hsl){ (uint8_t*)_t5323->e, _t5323->n }; }); int64_t _l5322 = 0, _h5322 = _t5322.n; if (_l5322 < 0 || _h5322 < _l5322 || _h5322 > _t5322.n) hr_slerr(_l5322, _h5322, _t5322.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:529"); (hsl){ _t5322.p + _l5322 * (int64_t)sizeof(uint8_t), _h5322 - _l5322 }; })));
(void)(f310_hh(hr_str("; ", 2)));
 }
 } } _bk5308:; 
(void)(f310_hh(hr_str("return true; ", 13)));
 }
if ((((k_1654) == (((int64_t)8LL))) || ((k_1654) == (((int64_t)9LL))))) { int64_t e_1748 = ((int64_t)((x_1653).a_)); 
L100 ea_1749 = ({ L100 _t5326; memset(&_t5326, 0, sizeof _t5326); _t5326.n = 0; _t5326; }); 
L100 eb_1750 = ({ L100 _t5327; memset(&_t5327, 0, sizeof _t5327); _t5327.n = 0; _t5327; }); 
if (f287_is_fix(t_1652)) { (void)(({ hrv *_o5329 = &(g169); hr_fs(_o5329, hr_str("for (int64_t i = 0; i < ", 24)); hr_fi(_o5329, (x_1653).b_); hr_fs(_o5329, hr_str("; i++) if (!(", 13)); }));
(void)(({ L100 *_v5330 = &(ea_1749); hsl _s5330 = hr_str("a.e[i]", 6); if (_v5330->n + _s5330.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:535"); memmove(_v5330->e + _v5330->n, _s5330.p, (size_t)_s5330.n * sizeof _v5330->e[0]); _v5330->n += _s5330.n; }));
(void)(({ L100 *_v5331 = &(eb_1750); hsl _s5331 = hr_str("b.e[i]", 6); if (_v5331->n + _s5331.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:535"); memmove(_v5331->e + _v5331->n, _s5331.p, (size_t)_s5331.n * sizeof _v5331->e[0]); _v5331->n += _s5331.n; }));
 } else { if (f288_is_lim(t_1652)) { (void)(f310_hh(hr_str("if (a.n != b.n) return false; for (int64_t i = 0; i < a.n; i++) if (!(", 70)));
(void)(({ L100 *_v5334 = &(ea_1749); hsl _s5334 = hr_str("a.e[i]", 6); if (_v5334->n + _s5334.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:536"); memmove(_v5334->e + _v5334->n, _s5334.p, (size_t)_s5334.n * sizeof _v5334->e[0]); _v5334->n += _s5334.n; }));
(void)(({ L100 *_v5335 = &(eb_1750); hsl _s5335 = hr_str("b.e[i]", 6); if (_v5335->n + _s5335.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:536"); memmove(_v5335->e + _v5335->n, _s5335.p, (size_t)_s5335.n * sizeof _v5335->e[0]); _v5335->n += _s5335.n; }));
 } else { (void)(f310_hh(hr_str("if (a.n != b.n) return false; for (int64_t i = 0; i < a.n; i++) if (!(", 70)));
(void)(({ L100 *_v5337 = &(ea_1749); hsl _s5337 = hr_str("((", 2); if (_v5337->n + _s5337.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:537"); memmove(_v5337->e + _v5337->n, _s5337.p, (size_t)_s5337.n * sizeof _v5337->e[0]); _v5337->n += _s5337.n; }));
(void)(({ L100 *_v5338 = &(ea_1749); hsl _s5338 = f267_cn(e_1748); if (_v5338->n + _s5338.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:537"); memmove(_v5338->e + _v5338->n, _s5338.p, (size_t)_s5338.n * sizeof _v5338->e[0]); _v5338->n += _s5338.n; }));
(void)(({ L100 *_v5340 = &(ea_1749); hsl _s5340 = hr_str("*)a.p)[i]", 9); if (_v5340->n + _s5340.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:537"); memmove(_v5340->e + _v5340->n, _s5340.p, (size_t)_s5340.n * sizeof _v5340->e[0]); _v5340->n += _s5340.n; }));
(void)(({ L100 *_v5341 = &(eb_1750); hsl _s5341 = hr_str("((", 2); if (_v5341->n + _s5341.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:537"); memmove(_v5341->e + _v5341->n, _s5341.p, (size_t)_s5341.n * sizeof _v5341->e[0]); _v5341->n += _s5341.n; }));
(void)(({ L100 *_v5342 = &(eb_1750); hsl _s5342 = f267_cn(e_1748); if (_v5342->n + _s5342.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:537"); memmove(_v5342->e + _v5342->n, _s5342.p, (size_t)_s5342.n * sizeof _v5342->e[0]); _v5342->n += _s5342.n; }));
(void)(({ L100 *_v5344 = &(eb_1750); hsl _s5344 = hr_str("*)b.p)[i]", 9); if (_v5344->n + _s5344.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:537"); memmove(_v5344->e + _v5344->n, _s5344.p, (size_t)_s5344.n * sizeof _v5344->e[0]); _v5344->n += _s5344.n; }));
 }
 }
(void)(f313_heq_val(e_1748, ({ hsl _t5346 = ({ L100 *_t5347 = &(ea_1749); (hsl){ (uint8_t*)_t5347->e, _t5347->n }; }); int64_t _l5346 = 0, _h5346 = _t5346.n; if (_l5346 < 0 || _h5346 < _l5346 || _h5346 > _t5346.n) hr_slerr(_l5346, _h5346, _t5346.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:538"); (hsl){ _t5346.p + _l5346 * (int64_t)sizeof(uint8_t), _h5346 - _l5346 }; }), ({ hsl _t5348 = ({ L100 *_t5349 = &(eb_1750); (hsl){ (uint8_t*)_t5349->e, _t5349->n }; }); int64_t _l5348 = 0, _h5348 = _t5348.n; if (_l5348 < 0 || _h5348 < _l5348 || _h5348 > _t5348.n) hr_slerr(_l5348, _h5348, _t5348.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:538"); (hsl){ _t5348.p + _l5348 * (int64_t)sizeof(uint8_t), _h5348 - _l5348 }; })));
(void)(f310_hh(hr_str(")) return false; return true; ", 30)));
 }
if (((k_1654) == (((int64_t)14LL)))) { (void)(f310_hh(hr_str("return true; ", 13)));
 }
(void)(f310_hh(hr_str("}\012", 2)));
}
static void f305_comp_pre(int64_t t_1656, bool fmt_1657) {
S1 x_1658 = (*({ hrv *_t5353 = &(g568); int64_t _i5353 = t_1656; (S1*)_t5353->b + hr_ix(_i5353, _t5353->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:423"); })); 
int64_t k_1659 = ((int64_t)((x_1658).k_)); 
if (((k_1659) == (((int64_t)5LL)))) { int64_t si_1660 = ((int64_t)((x_1658).a_)); 
{ int32_t _e5355 = ((*({ hrv *_t5356 = &(g571); int64_t _i5356 = si_1660; (S10*)_t5356->b + hr_ix(_i5356, _t5356->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:424"); }))).fnum_; for (int32_t _k5355 = 0; _k5355 < _e5355; _k5355++) { int32_t i_1661 = (int32_t)_k5355; S11 f_1662 = (*({ hrv *_t5357 = &(g572); int64_t _i5357 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5358 = &(g571); int64_t _i5358 = si_1660; (S10*)_t5358->b + hr_ix(_i5358, _t5358->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:424"); }))).f0_)) + (int64_t)((int64_t)(i_1661)))); (S11*)_t5357->b + hr_ix(_i5357, _t5357->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:424"); })); 
if ((((f_1662).ty_) >= (((int32_t)0LL)))) { (void)(f306_comp_one(((int64_t)((f_1662).ty_)), fmt_1657));
 }
 } } _bk5354:; 
 }
if (((k_1659) == (((int64_t)7LL)))) { S9 v_1720 = (*({ hrv *_t5360 = &(g574); int64_t _i5360 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5361 = &(g573); int64_t _i5361 = (x_1658).a_; (S8*)_t5361->b + hr_ix(_i5361, _t5361->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:425"); }))).v0_)) + (int64_t)((int64_t)((x_1658).c_)))); (S9*)_t5360->b + hr_ix(_i5360, _t5360->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:425"); })); 
if ((((v_1720).si_) >= (((int32_t)0LL)))) { { int32_t _e5363 = ((*({ hrv *_t5364 = &(g571); int64_t _i5364 = (v_1720).si_; (S10*)_t5364->b + hr_ix(_i5364, _t5364->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:425"); }))).fnum_; for (int32_t _k5363 = 0; _k5363 < _e5363; _k5363++) { int32_t i_1721 = (int32_t)_k5363; S11 f_1722 = (*({ hrv *_t5365 = &(g572); int64_t _i5365 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5366 = &(g571); int64_t _i5366 = (v_1720).si_; (S10*)_t5366->b + hr_ix(_i5366, _t5366->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:425"); }))).f0_)) + (int64_t)((int64_t)(i_1721)))); (S11*)_t5365->b + hr_ix(_i5365, _t5365->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:425"); })); 
if ((((f_1722).ty_) >= (((int32_t)0LL)))) { (void)(f306_comp_one(((int64_t)((f_1722).ty_)), fmt_1657));
 }
 } } _bk5362:; 
 }
 }
if (((k_1659) == (((int64_t)6LL)))) { int64_t ei_1723 = ((int64_t)((x_1658).a_)); 
{ int32_t _e5369 = ((*({ hrv *_t5370 = &(g573); int64_t _i5370 = ei_1723; (S8*)_t5370->b + hr_ix(_i5370, _t5370->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:426"); }))).vnum_; for (int32_t _k5369 = 0; _k5369 < _e5369; _k5369++) { int32_t i_1724 = (int32_t)_k5369; S9 v_1725 = (*({ hrv *_t5371 = &(g574); int64_t _i5371 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5372 = &(g573); int64_t _i5372 = ei_1723; (S8*)_t5372->b + hr_ix(_i5372, _t5372->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:426"); }))).v0_)) + (int64_t)((int64_t)(i_1724)))); (S9*)_t5371->b + hr_ix(_i5371, _t5371->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:426"); })); 
if (((((v_1725).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t5373 = &(g571); int64_t _i5373 = (v_1725).si_; (S10*)_t5373->b + hr_ix(_i5373, _t5373->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:426"); }))).zero_)))) { if (fmt_1657) { { int32_t _e5375 = ((*({ hrv *_t5376 = &(g571); int64_t _i5376 = (v_1725).si_; (S10*)_t5376->b + hr_ix(_i5376, _t5376->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:426"); }))).fnum_; for (int32_t _k5375 = 0; _k5375 < _e5375; _k5375++) { int32_t j_1726 = (int32_t)_k5375; S11 f_1727 = (*({ hrv *_t5377 = &(g572); int64_t _i5377 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5378 = &(g571); int64_t _i5378 = (v_1725).si_; (S10*)_t5378->b + hr_ix(_i5378, _t5378->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:426"); }))).f0_)) + (int64_t)((int64_t)(j_1726)))); (S11*)_t5377->b + hr_ix(_i5377, _t5377->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:426"); })); 
if ((((f_1727).ty_) >= (((int32_t)0LL)))) { (void)(f306_comp_one(((int64_t)((f_1727).ty_)), fmt_1657));
 }
 } } _bk5374:; 
 } else { (void)(f304_gen_heq(f125_t_variant(ei_1723, ((int64_t)(i_1724)))));
 }
 }
 } } _bk5368:; 
 }
if ((((k_1659) == (((int64_t)8LL))) || ((k_1659) == (((int64_t)9LL))))) { (void)(f306_comp_one(((int64_t)((x_1658).a_)), fmt_1657));
 }
if (((k_1659) == (((int64_t)14LL)))) { { int32_t _e5384 = (x_1658).n_; for (int32_t _k5384 = 0; _k5384 < _e5384; _k5384++) { int32_t i_1728 = (int32_t)_k5384; (void)(f306_comp_one(((int64_t)((*({ hrv *_t5386 = &(g569); int64_t _i5386 = ((int64_t)((int64_t)((int64_t)((x_1658).l_)) + (int64_t)((int64_t)(i_1728)))); (int32_t*)_t5386->b + hr_ix(_i5386, _t5386->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:428"); })))), fmt_1657));
 } } _bk5383:; 
 }
}
static void f306_comp_one(int64_t t_1663, bool fmt_1664) {
int64_t u_1665 = ({ int64_t _r5387; if (((((*({ hrv *_t5388 = &(g568); int64_t _i5388 = t_1663; (S1*)_t5388->b + hr_ix(_i5388, _t5388->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:421"); }))).k_) == (((uint8_t)10LL)))) { _r5387 = ((int64_t)(((*({ hrv *_t5389 = &(g568); int64_t _i5389 = t_1663; (S1*)_t5389->b + hr_ix(_i5389, _t5389->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:421"); }))).a_));  } else { _r5387 = t_1663;  } _r5387; }); 
if ((((((*({ hrv *_t5390 = &(g568); int64_t _i5390 = t_1663; (S1*)_t5390->b + hr_ix(_i5390, _t5390->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:421"); }))).k_) == (((uint8_t)10LL))) && (!(fmt_1664)))) { return;
 }
if (f307_need_helper(u_1665)) { if (fmt_1664) { (void)(f308_gen_hf(u_1665));
 } else { (void)(f304_gen_heq(u_1665));
 }
 }
}
static bool f307_need_helper(int64_t t_1666) {
int64_t k_1667 = ((int64_t)(((*({ hrv *_t5394 = &(g568); int64_t _i5394 = t_1666; (S1*)_t5394->b + hr_ix(_i5394, _t5394->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:420"); }))).k_)); 
if (f167_is_byte_arr(t_1666)) { return false;
 }
if (((k_1667) == (((int64_t)10LL)))) { return f307_need_helper(((int64_t)(((*({ hrv *_t5397 = &(g568); int64_t _i5397 = t_1666; (S1*)_t5397->b + hr_ix(_i5397, _t5397->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:420"); }))).a_)));
 }
return (((((((k_1667) == (((int64_t)5LL))) || ((k_1667) == (((int64_t)6LL)))) || ((k_1667) == (((int64_t)7LL)))) || ((k_1667) == (((int64_t)8LL)))) || ((k_1667) == (((int64_t)9LL)))) || ((k_1667) == (((int64_t)14LL))));
}
static void f308_gen_hf(int64_t t_1668) {
(void)(f266_cn_grow());
if ((((*({ hrv *_t5399 = &(g174); int64_t _i5399 = t_1668; (uint8_t*)_t5399->b + hr_ix(_i5399, _t5399->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:443"); }))) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t5400 = &((*({ hrv *_t5401 = &(g174); int64_t _i5401 = t_1668; (uint8_t*)_t5401->b + hr_ix(_i5401, _t5401->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:444"); }))); *_t5400 = ((uint8_t)1LL); }
S1 x_1669 = (*({ hrv *_t5402 = &(g568); int64_t _i5402 = t_1668; (S1*)_t5402->b + hr_ix(_i5402, _t5402->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:445"); })); 
int64_t k_1670 = ((int64_t)((x_1669).k_)); 
(void)(f265_cbody(t_1668));
bool sl_1671 = (((k_1670) == (((int64_t)9LL))) || ((((k_1670) == (((int64_t)8LL))) && (!(f287_is_fix(t_1668)))) && (!(f288_is_lim(t_1668))))); 
(void)(f309_hf_pre(t_1668));
L99 sig_1673 = ({ L99 _t5407; memset(&_t5407, 0, sizeof _t5407); _t5407.n = 0; _t5407; }); 
(void)(({ L99 *_l5408 = &(sig_1673); hrv _o5408 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5408, hr_str("static void hf", 14)); hr_fi(&_o5408, t_1668); hr_fs(&_o5408, hr_str("(hrv *o, ", 9)); if (_l5408->n + _o5408.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:450"); memcpy(_l5408->e + _l5408->n, _o5408.b, (size_t)_o5408.n); _l5408->n += _o5408.n; }));
(void)(({ L99 *_v5409 = &(sig_1673); hsl _s5409 = ({ hsl _r5410; if (sl_1671) { _r5410 = hr_str("hsl", 3);  } else { _r5410 = f267_cn(t_1668);  } _r5410; }); if (_v5409->n + _s5409.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:451"); memmove(_v5409->e + _v5409->n, _s5409.p, (size_t)_s5409.n * sizeof _v5409->e[0]); _v5409->n += _s5409.n; }));
(void)(({ L99 *_v5412 = &(sig_1673); hsl _s5412 = hr_str(" v)", 3); if (_v5412->n + _s5412.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:452"); memmove(_v5412->e + _v5412->n, _s5412.p, (size_t)_s5412.n * sizeof _v5412->e[0]); _v5412->n += _s5412.n; }));
(void)(({ hrv *_v5413 = &(g166); hsl _s5413 = ({ hsl _t5414 = ({ L99 *_t5415 = &(sig_1673); (hsl){ (uint8_t*)_t5415->e, _t5415->n }; }); int64_t _l5414 = 0, _h5414 = _t5414.n; if (_l5414 < 0 || _h5414 < _l5414 || _h5414 > _t5414.n) hr_slerr(_l5414, _h5414, _t5414.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:453"); (hsl){ _t5414.p + _l5414 * (int64_t)sizeof(uint8_t), _h5414 - _l5414 }; }); hr_append(_v5413, _s5413.p, _s5413.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5416 = &(g166); hsl _s5416 = hr_str(";\012", 2); hr_append(_v5416, _s5416.p, _s5416.n, sizeof(uint8_t)); }));
int64_t s0_1674 = (g169).n; 
(void)(({ hrv *_v5417 = &(g169); hsl _s5417 = ({ hsl _t5418 = ({ L99 *_t5419 = &(sig_1673); (hsl){ (uint8_t*)_t5419->e, _t5419->n }; }); int64_t _l5418 = 0, _h5418 = _t5418.n; if (_l5418 < 0 || _h5418 < _l5418 || _h5418 > _t5418.n) hr_slerr(_l5418, _h5418, _t5418.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:455"); (hsl){ _t5418.p + _l5418 * (int64_t)sizeof(uint8_t), _h5418 - _l5418 }; }); hr_append(_v5417, _s5417.p, _s5417.n, sizeof(uint8_t)); }));
(void)(f310_hh(hr_str(" { ", 3)));
int64_t hk_1676 = ({ int64_t _r5421; if (((t_1668) < ((g361).n))) { _r5421 = ((int64_t)((*({ hrv *_t5422 = &(g361); int64_t _i5422 = t_1668; (int32_t*)_t5422->b + hr_ix(_i5422, _t5422->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:456"); }))));  } else { _r5421 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r5421; }); 
if (((hk_1676) >= (((int64_t)0LL)))) { int64_t pt_1677 = f213_ptype_of(hk_1676, ((int64_t)1LL)); 
bool byr_1678 = ((((*({ hrv *_t5424 = &(g568); int64_t _i5424 = pt_1677; (S1*)_t5424->b + hr_ix(_i5424, _t5424->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:459"); }))).k_) == (((uint8_t)10LL))); 
int64_t dp_1679 = f182_deref(pt_1677); 
if (((((dp_1679) != (t_1668)) && ((((*({ hrv *_t5426 = &(g568); int64_t _i5426 = dp_1679; (S1*)_t5426->b + hr_ix(_i5426, _t5426->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); }))).k_) == (((uint8_t)6LL)))) && ((k_1670) == (((int64_t)7LL))))) { int64_t vi_1680 = ((int64_t)((x_1669).c_)); 
S9 vv_1681 = (*({ hrv *_t5427 = &(g574); int64_t _i5427 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5428 = &(g573); int64_t _i5428 = (x_1669).a_; (S8*)_t5428->b + hr_ix(_i5428, _t5428->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); }))).v0_)) + (int64_t)vi_1680)); (S9*)_t5427->b + hr_ix(_i5427, _t5427->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); })); 
(void)(({ hrv *_v5429 = &(g169); hsl _s5429 = f267_cn(dp_1679); hr_append(_v5429, _s5429.p, _s5429.n, sizeof(uint8_t)); }));
(void)(f310_hh(hr_str(" e; memset(&e, 0, sizeof e); ", 29)));
(void)(({ hrv *_o5432 = &(g169); hr_fs(_o5432, hr_str("e.tag = ", 8)); hr_fi(_o5432, vi_1680); hr_fs(_o5432, hr_str("; ", 2)); }));
if (((((vv_1681).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t5433 = &(g571); int64_t _i5433 = (vv_1681).si_; (S10*)_t5433->b + hr_ix(_i5433, _t5433->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:461"); }))).zero_)))) { (void)(({ hrv *_o5434 = &(g169); hr_fs(_o5434, hr_str("e.u.v", 5)); hr_fi(_o5434, vi_1680); hr_fs(_o5434, hr_str(" = v; ", 6)); }));
 }
(void)(f311_fn_cname_to((&(g169)), hk_1676));
(void)(f310_hh(({ hsl _r5437; if (byr_1678) { _r5437 = hr_str("(o, &e); }\012", 11);  } else { _r5437 = hr_str("(o, e); }\012", 10);  } _r5437; })));
return;
 }
(void)(f311_fn_cname_to((&(g169)), hk_1676));
(void)(f310_hh(({ hsl _r5440; if (byr_1678) { _r5440 = hr_str("(o, &v); }\012", 11);  } else { _r5440 = hr_str("(o, v); }\012", 10);  } _r5440; })));
return;
 }
if (((k_1670) == (((int64_t)5LL)))) { int64_t si_1686 = ((int64_t)((x_1669).a_)); 
int64_t f0_1687 = ((int64_t)(((*({ hrv *_t5441 = &(g571); int64_t _i5441 = si_1686; (S10*)_t5441->b + hr_ix(_i5441, _t5441->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:466"); }))).f0_)); 
(void)(f310_hh(hr_str("hr_fc(o, \"", 10)));
hrv tnm_1688 __attribute__((cleanup(hr_rdrop))) = f126_ty_name(t_1668); 
(void)(({ hrv *_v5444 = &(g169); hsl _s5444 = ({ hsl _t5445 = hr_sl(tnm_1688); int64_t _l5445 = 0, _h5445 = _t5445.n; if (_l5445 < 0 || _h5445 < _l5445 || _h5445 > _t5445.n) hr_slerr(_l5445, _h5445, _t5445.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:467"); (hsl){ _t5445.p + _l5445 * (int64_t)sizeof(uint8_t), _h5445 - _l5445 }; }); hr_append(_v5444, _s5444.p, _s5444.n, sizeof(uint8_t)); }));
(void)(f310_hh(hr_str(" { \"); ", 7)));
bool first_1689 = true; 
{ int32_t _e5448 = ((*({ hrv *_t5449 = &(g571); int64_t _i5449 = si_1686; (S10*)_t5449->b + hr_ix(_i5449, _t5449->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:469"); }))).fnum_; for (int32_t _k5448 = 0; _k5448 < _e5448; _k5448++) { int32_t i_1690 = (int32_t)_k5448; S11 f_1691 = (*({ hrv *_t5450 = &(g572); int64_t _i5450 = ((int64_t)((int64_t)f0_1687 + (int64_t)((int64_t)(i_1690)))); (S11*)_t5450->b + hr_ix(_i5450, _t5450->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:469"); })); 
if ((((f_1691).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1689))) { (void)(f310_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1689 = false;
L100 e_1692 = ({ L100 _t5452; memset(&_t5452, 0, sizeof _t5452); _t5452.n = 0; _t5452; }); 
(void)(({ L100 *_v5453 = &(e_1692); hsl _s5453 = hr_str("v.", 2); if (_v5453->n + _s5453.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:469"); memmove(_v5453->e + _v5453->n, _s5453.p, (size_t)_s5453.n * sizeof _v5453->e[0]); _v5453->n += _s5453.n; }));
{ hsl _v5455 = f10_nm(((int64_t)((f_1691).name_))); for (int64_t _k5455 = 0; _k5455 < _v5455.n; _k5455++) { uint8_t c_1693 = ((uint8_t*)_v5455.p)[_k5455]; (void)(({ L100 *_v5457 = &(e_1692); uint8_t _x5457 = c_1693; if (_v5457->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:469"); _v5457->e[_v5457->n] = _x5457; &_v5457->e[_v5457->n++]; }));
 } } _bk5454:; 
(void)(({ L100 *_v5458 = &(e_1692); uint8_t _x5458 = ((uint8_t)95LL); if (_v5458->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:469"); _v5458->e[_v5458->n] = _x5458; &_v5458->e[_v5458->n++]; }));
(void)(f312_hf_val(((int64_t)((f_1691).ty_)), ({ hsl _t5460 = ({ L100 *_t5461 = &(e_1692); (hsl){ (uint8_t*)_t5461->e, _t5461->n }; }); int64_t _l5460 = 0, _h5460 = _t5460.n; if (_l5460 < 0 || _h5460 < _l5460 || _h5460 > _t5460.n) hr_slerr(_l5460, _h5460, _t5460.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:469"); (hsl){ _t5460.p + _l5460 * (int64_t)sizeof(uint8_t), _h5460 - _l5460 }; })));
 } } _bk5447:; 
(void)(f310_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 }
if (((k_1670) == (((int64_t)6LL)))) { int64_t ei_1698 = ((int64_t)((x_1669).a_)); 
int64_t v0_1699 = ((int64_t)(((*({ hrv *_t5463 = &(g573); int64_t _i5463 = ei_1698; (S8*)_t5463->b + hr_ix(_i5463, _t5463->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:473"); }))).v0_)); 
{ int32_t _e5465 = ((*({ hrv *_t5466 = &(g573); int64_t _i5466 = ei_1698; (S8*)_t5466->b + hr_ix(_i5466, _t5466->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:474"); }))).vnum_; for (int32_t _k5465 = 0; _k5465 < _e5465; _k5465++) { int32_t i_1700 = (int32_t)_k5465; S9 v_1701 = (*({ hrv *_t5467 = &(g574); int64_t _i5467 = ((int64_t)((int64_t)v0_1699 + (int64_t)((int64_t)(i_1700)))); (S9*)_t5467->b + hr_ix(_i5467, _t5467->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:475"); })); 
(void)(({ hrv *_o5468 = &(g169); hr_fs(_o5468, hr_str("if (v.tag == ", 13)); hr_fi(_o5468, i_1700); hr_fs(_o5468, hr_str(") { ", 4)); }));
if (((((v_1701).si_) >= (((int32_t)0LL))) && ((((*({ hrv *_t5469 = &(g571); int64_t _i5469 = (v_1701).si_; (S10*)_t5469->b + hr_ix(_i5469, _t5469->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:477"); }))).fnum_) > (((int32_t)0LL))))) { (void)(f310_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f310_hh(f10_nm(((int64_t)((v_1701).name_)))));
(void)(f310_hh(hr_str(" { \"); ", 7)));
bool first_1702 = true; 
int64_t sf0_1703 = ((int64_t)(((*({ hrv *_t5474 = &(g571); int64_t _i5474 = (v_1701).si_; (S10*)_t5474->b + hr_ix(_i5474, _t5474->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:477"); }))).f0_)); 
{ int32_t _e5476 = ((*({ hrv *_t5477 = &(g571); int64_t _i5477 = (v_1701).si_; (S10*)_t5477->b + hr_ix(_i5477, _t5477->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:477"); }))).fnum_; for (int32_t _k5476 = 0; _k5476 < _e5476; _k5476++) { int32_t j_1704 = (int32_t)_k5476; S11 f_1705 = (*({ hrv *_t5478 = &(g572); int64_t _i5478 = ((int64_t)((int64_t)sf0_1703 + (int64_t)((int64_t)(j_1704)))); (S11*)_t5478->b + hr_ix(_i5478, _t5478->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:477"); })); 
if ((((f_1705).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1702))) { (void)(f310_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1702 = false;
L100 e_1706 = ({ L100 _t5480; memset(&_t5480, 0, sizeof _t5480); _t5480.n = 0; _t5480; }); 
(void)(({ L100 *_l5481 = &(e_1706); hrv _o5481 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5481, hr_str("v.u.v", 5)); hr_fi(&_o5481, i_1700); hr_fs(&_o5481, hr_str(".", 1)); if (_l5481->n + _o5481.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:477"); memcpy(_l5481->e + _l5481->n, _o5481.b, (size_t)_o5481.n); _l5481->n += _o5481.n; }));
{ hsl _v5483 = f10_nm(((int64_t)((f_1705).name_))); for (int64_t _k5483 = 0; _k5483 < _v5483.n; _k5483++) { uint8_t c_1707 = ((uint8_t*)_v5483.p)[_k5483]; (void)(({ L100 *_v5485 = &(e_1706); uint8_t _x5485 = c_1707; if (_v5485->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:477"); _v5485->e[_v5485->n] = _x5485; &_v5485->e[_v5485->n++]; }));
 } } _bk5482:; 
(void)(({ L100 *_v5486 = &(e_1706); uint8_t _x5486 = ((uint8_t)95LL); if (_v5486->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:477"); _v5486->e[_v5486->n] = _x5486; &_v5486->e[_v5486->n++]; }));
(void)(f312_hf_val(((int64_t)((f_1705).ty_)), ({ hsl _t5488 = ({ L100 *_t5489 = &(e_1706); (hsl){ (uint8_t*)_t5489->e, _t5489->n }; }); int64_t _l5488 = 0, _h5488 = _t5488.n; if (_l5488 < 0 || _h5488 < _l5488 || _h5488 > _t5488.n) hr_slerr(_l5488, _h5488, _t5488.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:477"); (hsl){ _t5488.p + _l5488 * (int64_t)sizeof(uint8_t), _h5488 - _l5488 }; })));
 } } _bk5475:; 
(void)(f310_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 } else { (void)(f310_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f310_hh(f10_nm(((int64_t)(((*({ hrv *_t5494 = &(g573); int64_t _i5494 = ei_1698; (S8*)_t5494->b + hr_ix(_i5494, _t5494->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:478"); }))).name_)))));
(void)(f310_hh(hr_str(".", 1)));
(void)(f310_hh(f10_nm(((int64_t)((v_1701).name_)))));
(void)(f310_hh(hr_str("\"); ", 4)));
 }
(void)(f310_hh(hr_str("} ", 2)));
 } } _bk5464:; 
 }
if (((k_1670) == (((int64_t)7LL)))) { int64_t ei_1708 = ((int64_t)((x_1669).a_)); 
S9 v_1709 = (*({ hrv *_t5500 = &(g574); int64_t _i5500 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5501 = &(g573); int64_t _i5501 = ei_1708; (S8*)_t5501->b + hr_ix(_i5501, _t5501->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:483"); }))).v0_)) + (int64_t)((int64_t)((x_1669).c_)))); (S9*)_t5500->b + hr_ix(_i5500, _t5500->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:483"); })); 
if (((((v_1709).si_) >= (((int32_t)0LL))) && ((((*({ hrv *_t5502 = &(g571); int64_t _i5502 = (v_1709).si_; (S10*)_t5502->b + hr_ix(_i5502, _t5502->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:484"); }))).fnum_) > (((int32_t)0LL))))) { (void)(f310_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f310_hh(f10_nm(((int64_t)((v_1709).name_)))));
(void)(f310_hh(hr_str(" { \"); ", 7)));
bool first_1710 = true; 
int64_t sf0_1711 = ((int64_t)(((*({ hrv *_t5507 = &(g571); int64_t _i5507 = (v_1709).si_; (S10*)_t5507->b + hr_ix(_i5507, _t5507->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:484"); }))).f0_)); 
{ int32_t _e5509 = ((*({ hrv *_t5510 = &(g571); int64_t _i5510 = (v_1709).si_; (S10*)_t5510->b + hr_ix(_i5510, _t5510->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:484"); }))).fnum_; for (int32_t _k5509 = 0; _k5509 < _e5509; _k5509++) { int32_t j_1712 = (int32_t)_k5509; S11 f_1713 = (*({ hrv *_t5511 = &(g572); int64_t _i5511 = ((int64_t)((int64_t)sf0_1711 + (int64_t)((int64_t)(j_1712)))); (S11*)_t5511->b + hr_ix(_i5511, _t5511->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:484"); })); 
if ((((f_1713).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1710))) { (void)(f310_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1710 = false;
L100 e_1714 = ({ L100 _t5513; memset(&_t5513, 0, sizeof _t5513); _t5513.n = 0; _t5513; }); 
(void)(({ L100 *_v5514 = &(e_1714); hsl _s5514 = hr_str("v.", 2); if (_v5514->n + _s5514.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:484"); memmove(_v5514->e + _v5514->n, _s5514.p, (size_t)_s5514.n * sizeof _v5514->e[0]); _v5514->n += _s5514.n; }));
{ hsl _v5516 = f10_nm(((int64_t)((f_1713).name_))); for (int64_t _k5516 = 0; _k5516 < _v5516.n; _k5516++) { uint8_t c_1715 = ((uint8_t*)_v5516.p)[_k5516]; (void)(({ L100 *_v5518 = &(e_1714); uint8_t _x5518 = c_1715; if (_v5518->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:484"); _v5518->e[_v5518->n] = _x5518; &_v5518->e[_v5518->n++]; }));
 } } _bk5515:; 
(void)(({ L100 *_v5519 = &(e_1714); uint8_t _x5519 = ((uint8_t)95LL); if (_v5519->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:484"); _v5519->e[_v5519->n] = _x5519; &_v5519->e[_v5519->n++]; }));
(void)(f312_hf_val(((int64_t)((f_1713).ty_)), ({ hsl _t5521 = ({ L100 *_t5522 = &(e_1714); (hsl){ (uint8_t*)_t5522->e, _t5522->n }; }); int64_t _l5521 = 0, _h5521 = _t5521.n; if (_l5521 < 0 || _h5521 < _l5521 || _h5521 > _t5521.n) hr_slerr(_l5521, _h5521, _t5521.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:484"); (hsl){ _t5521.p + _l5521 * (int64_t)sizeof(uint8_t), _h5521 - _l5521 }; })));
 } } _bk5508:; 
(void)(f310_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 } else { (void)(f310_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f310_hh(f10_nm(((int64_t)(((*({ hrv *_t5527 = &(g573); int64_t _i5527 = ei_1708; (S8*)_t5527->b + hr_ix(_i5527, _t5527->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:485"); }))).name_)))));
(void)(f310_hh(hr_str(".", 1)));
(void)(f310_hh(f10_nm(((int64_t)((v_1709).name_)))));
(void)(f310_hh(hr_str("\"); ", 4)));
 }
 }
if ((((k_1670) == (((int64_t)8LL))) || ((k_1670) == (((int64_t)9LL))))) { int64_t e_1716 = ((int64_t)((x_1669).a_)); 
(void)(f265_cbody(e_1716));
(void)(f310_hh(hr_str("hr_fb(o, '['); ", 15)));
if (f287_is_fix(t_1668)) { (void)(({ hrv *_o5535 = &(g169); hr_fs(_o5535, hr_str("for (int64_t i = 0; i < ", 24)); hr_fi(_o5535, (x_1669).b_); hr_fs(_o5535, hr_str("; i++) { if (i) hr_fc(o, \", \"); ", 32)); }));
(void)(f312_hf_val(e_1716, hr_str("v.e[i]", 6)));
(void)(f310_hh(hr_str("} ", 2)));
 } else { if (f288_is_lim(t_1668)) { (void)(f310_hh(hr_str("for (int64_t i = 0; i < v.n; i++) { if (i) hr_fc(o, \", \"); ", 59)));
(void)(f312_hf_val(e_1716, hr_str("v.e[i]", 6)));
(void)(f310_hh(hr_str("} ", 2)));
 } else { (void)(f310_hh(hr_str("for (int64_t i = 0; i < v.n; i++) { if (i) hr_fc(o, \", \"); ", 59)));
L100 ex_1717 = ({ L100 _t5543; memset(&_t5543, 0, sizeof _t5543); _t5543.n = 0; _t5543; }); 
(void)(({ L100 *_v5544 = &(ex_1717); hsl _s5544 = hr_str("((", 2); if (_v5544->n + _s5544.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); memmove(_v5544->e + _v5544->n, _s5544.p, (size_t)_s5544.n * sizeof _v5544->e[0]); _v5544->n += _s5544.n; }));
(void)(({ L100 *_v5545 = &(ex_1717); hsl _s5545 = f267_cn(e_1716); if (_v5545->n + _s5545.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); memmove(_v5545->e + _v5545->n, _s5545.p, (size_t)_s5545.n * sizeof _v5545->e[0]); _v5545->n += _s5545.n; }));
(void)(({ L100 *_v5547 = &(ex_1717); hsl _s5547 = hr_str("*)v.p)[i]", 9); if (_v5547->n + _s5547.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); memmove(_v5547->e + _v5547->n, _s5547.p, (size_t)_s5547.n * sizeof _v5547->e[0]); _v5547->n += _s5547.n; }));
(void)(f312_hf_val(e_1716, ({ hsl _t5549 = ({ L100 *_t5550 = &(ex_1717); (hsl){ (uint8_t*)_t5550->e, _t5550->n }; }); int64_t _l5549 = 0, _h5549 = _t5549.n; if (_l5549 < 0 || _h5549 < _l5549 || _h5549 > _t5549.n) hr_slerr(_l5549, _h5549, _t5549.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:493"); (hsl){ _t5549.p + _l5549 * (int64_t)sizeof(uint8_t), _h5549 - _l5549 }; })));
(void)(f310_hh(hr_str("} ", 2)));
 }
 }
(void)(f310_hh(hr_str("hr_fb(o, ']'); ", 15)));
 }
if (((k_1670) == (((int64_t)14LL)))) { { int32_t _e5554 = (x_1669).n_; for (int32_t _k5554 = 0; _k5554 < _e5554; _k5554++) { int32_t i_1718 = (int32_t)_k5554; if (((i_1718) > (((int32_t)0LL)))) { (void)(f310_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
L101 e_1719 = ({ L101 _t5556; memset(&_t5556, 0, sizeof _t5556); _t5556.n = 0; _t5556; }); 
(void)(({ L101 *_l5557 = &(e_1719); hrv _o5557 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5557, hr_str("v.r", 3)); hr_fi(&_o5557, i_1718); if (_l5557->n + _o5557.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:496"); memcpy(_l5557->e + _l5557->n, _o5557.b, (size_t)_o5557.n); _l5557->n += _o5557.n; }));
(void)(f312_hf_val(((int64_t)((*({ hrv *_t5559 = &(g569); int64_t _i5559 = ((int64_t)((int64_t)((int64_t)((x_1669).l_)) + (int64_t)((int64_t)(i_1718)))); (int32_t*)_t5559->b + hr_ix(_i5559, _t5559->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:496"); })))), ({ hsl _t5560 = ({ L101 *_t5561 = &(e_1719); (hsl){ (uint8_t*)_t5561->e, _t5561->n }; }); int64_t _l5560 = 0, _h5560 = _t5560.n; if (_l5560 < 0 || _h5560 < _l5560 || _h5560 > _t5560.n) hr_slerr(_l5560, _h5560, _t5560.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:496"); (hsl){ _t5560.p + _l5560 * (int64_t)sizeof(uint8_t), _h5560 - _l5560 }; })));
 } } _bk5553:; 
 }
(void)(f310_hh(hr_str("}\012", 2)));
}
static void f309_hf_pre(int64_t t_1672) {
(void)(f305_comp_pre(t_1672, true));
}
static void f310_hh(hsl s_1675) {
(void)(({ hrv *_v5564 = &(g169); hsl _s5564 = s_1675; hr_append(_v5564, _s5564.p, _s5564.n, sizeof(uint8_t)); }));
}
static void f311_fn_cname_to(hrv* b_1682, int64_t i_1683) {
(void)(({ hrv *_o5565 = b_1682; hr_fs(_o5565, hr_str("f", 1)); hr_fi(_o5565, i_1683); hr_fs(_o5565, hr_str("_", 1)); }));
int64_t s_1684 = ((int64_t)(((*({ hrv *_t5566 = &(g401); int64_t _i5566 = i_1683; (S6*)_t5566->b + hr_ix(_i5566, _t5566->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:596"); }))).name_)); 
if (((s_1684) >= (((int64_t)0LL)))) { { hsl _v5568 = f10_nm(s_1684); for (int64_t _k5568 = 0; _k5568 < _v5568.n; _k5568++) { uint8_t c_1685 = ((uint8_t*)_v5568.p)[_k5568]; (void)(({ hrv *_v5570 = b_1682; uint8_t _x5570 = ({ uint8_t _r5571; if (((c_1685) == (((uint8_t)58LL)))) { _r5571 = ((uint8_t)95LL);  } else { _r5571 = c_1685;  } _r5571; }); uint8_t *_p5570 = (uint8_t*)hr_grow(_v5570, 1, sizeof _x5570); *_p5570 = _x5570; _p5570; }));
 } } _bk5567:; 
 }
}
static void f312_hf_val(int64_t t_1694, hsl e_1695) {
int64_t k_1696 = ((int64_t)(((*({ hrv *_t5572 = &(g568); int64_t _i5572 = t_1694; (S1*)_t5572->b + hr_ix(_i5572, _t5572->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:432"); }))).k_)); 
if (f167_is_byte_arr(t_1694)) { if (f287_is_fix(t_1694)) { (void)(({ hrv *_o5575 = &(g169); hr_fs(_o5575, hr_str("hr_fq(o, (hsl){ (uint8_t*)(", 27)); hr_fs(_o5575, e_1695); hr_fs(_o5575, hr_str(").e, ", 5)); hr_fi(_o5575, ((*({ hrv *_t5576 = &(g568); int64_t _i5576 = t_1694; (S1*)_t5576->b + hr_ix(_i5576, _t5576->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:433"); }))).b_); hr_fs(_o5575, hr_str(" }); ", 5)); }));
return;
 }
if (f288_is_lim(t_1694)) { (void)(({ hrv *_o5578 = &(g169); hr_fs(_o5578, hr_str("hr_fq(o, (hsl){ (uint8_t*)(", 27)); hr_fs(_o5578, e_1695); hr_fs(_o5578, hr_str(").e, (", 6)); hr_fs(_o5578, e_1695); hr_fs(_o5578, hr_str(").n }); ", 8)); }));
return;
 }
if (((((*({ hrv *_t5579 = &(g568); int64_t _i5579 = t_1694; (S1*)_t5579->b + hr_ix(_i5579, _t5579->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:433"); }))).k_) == (((uint8_t)9LL)))) { (void)(({ hrv *_o5580 = &(g169); hr_fs(_o5580, hr_str("hr_fq(o, ", 9)); hr_fs(_o5580, e_1695); hr_fs(_o5580, hr_str("); ", 3)); }));
return;
 }
(void)(({ hrv *_o5581 = &(g169); hr_fs(_o5581, hr_str("hr_fq(o, hr_sl(", 15)); hr_fs(_o5581, e_1695); hr_fs(_o5581, hr_str(")); ", 4)); }));
return;
 }
if (((k_1696) == (((int64_t)3LL)))) { (void)(({ hrv *_o5582 = &(g169); hr_fs(_o5582, ({ hsl _r5583; if (f156_is_signed(t_1694)) { _r5583 = hr_str("hr_fi(o, ", 9);  } else { _r5583 = hr_str("hr_fu(o, ", 9);  } _r5583; })); hr_fs(_o5582, e_1695); hr_fs(_o5582, hr_str("); ", 3)); }));
return;
 }
if (((k_1696) == (((int64_t)4LL)))) { (void)(({ hrv *_o5585 = &(g169); hr_fs(_o5585, ({ hsl _r5586; if (((((*({ hrv *_t5587 = &(g568); int64_t _i5587 = t_1694; (S1*)_t5587->b + hr_ix(_i5587, _t5587->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:435"); }))).s_) == (((uint8_t)4LL)))) { _r5586 = hr_str("hr_ff(o, ", 9);  } else { _r5586 = hr_str("hr_fd(o, ", 9);  } _r5586; })); hr_fs(_o5585, e_1695); hr_fs(_o5585, hr_str("); ", 3)); }));
return;
 }
if (((k_1696) == (((int64_t)2LL)))) { (void)(({ hrv *_o5588 = &(g169); hr_fs(_o5588, hr_str("hr_fc(o, (", 10)); hr_fs(_o5588, e_1695); hr_fs(_o5588, hr_str(") \077 \"true\" : \"false\"); ", 23)); }));
return;
 }
if (((k_1696) == (((int64_t)10LL)))) { if (((((*({ hrv *_t5589 = &(g568); int64_t _i5589 = t_1694; (S1*)_t5589->b + hr_ix(_i5589, _t5589->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:437"); }))).c_) >= (((int32_t)0LL)))) { (void)(({ hrv *_o5590 = &(g169); hr_fs(_o5590, hr_str("hr_fu(o, ", 9)); hr_fs(_o5590, e_1695); hr_fs(_o5590, hr_str("); ", 3)); }));
return;
 }
L99 pe_1697 = ({ L99 _t5591; memset(&_t5591, 0, sizeof _t5591); _t5591.n = 0; _t5591; }); 
(void)(({ L99 *_l5592 = &(pe_1697); hrv _o5592 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5592, hr_str("(*(", 3)); hr_fs(&_o5592, e_1695); hr_fs(&_o5592, hr_str("))", 2)); if (_l5592->n + _o5592.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:437"); memcpy(_l5592->e + _l5592->n, _o5592.b, (size_t)_o5592.n); _l5592->n += _o5592.n; }));
(void)(({ hrv *_o5593 = &(g169); hr_fs(_o5593, hr_str("if (", 4)); hr_fs(_o5593, e_1695); hr_fs(_o5593, hr_str(") { ", 4)); }));
(void)(f312_hf_val(((int64_t)(((*({ hrv *_t5595 = &(g568); int64_t _i5595 = t_1694; (S1*)_t5595->b + hr_ix(_i5595, _t5595->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:437"); }))).a_)), ({ hsl _t5596 = ({ L99 *_t5597 = &(pe_1697); (hsl){ (uint8_t*)_t5597->e, _t5597->n }; }); int64_t _l5596 = 0, _h5596 = _t5596.n; if (_l5596 < 0 || _h5596 < _l5596 || _h5596 > _t5596.n) hr_slerr(_l5596, _h5596, _t5596.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:437"); (hsl){ _t5596.p + _l5596 * (int64_t)sizeof(uint8_t), _h5596 - _l5596 }; })));
(void)(f310_hh(hr_str("} else hr_fc(o, \"null\"); ", 25)));
return;
 }
if (((((k_1696) == (((int64_t)8LL))) && (!(f287_is_fix(t_1694)))) && (!(f288_is_lim(t_1694))))) { (void)(({ hrv *_o5601 = &(g169); hr_fs(_o5601, hr_str("hf", 2)); hr_fi(_o5601, t_1694); hr_fs(_o5601, hr_str("(o, hr_sl(", 10)); hr_fs(_o5601, e_1695); hr_fs(_o5601, hr_str(")); ", 4)); }));
return;
 }
(void)(({ hrv *_o5602 = &(g169); hr_fs(_o5602, hr_str("hf", 2)); hr_fi(_o5602, t_1694); hr_fs(_o5602, hr_str("(o, ", 4)); hr_fs(_o5602, e_1695); hr_fs(_o5602, hr_str("); ", 3)); }));
}
static void f313_heq_val(int64_t t_1738, hsl a_1739, hsl b_1740) {
int64_t k_1741 = ((int64_t)(((*({ hrv *_t5603 = &(g568); int64_t _i5603 = t_1738; (S1*)_t5603->b + hr_ix(_i5603, _t5603->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:500"); }))).k_)); 
if ((((((k_1741) == (((int64_t)3LL))) || ((k_1741) == (((int64_t)4LL)))) || ((k_1741) == (((int64_t)2LL)))) || ((k_1741) == (((int64_t)10LL))))) { (void)(({ hrv *_o5604 = &(g169); hr_fs(_o5604, hr_str("(", 1)); hr_fs(_o5604, a_1739); hr_fs(_o5604, hr_str(") == (", 6)); hr_fs(_o5604, b_1740); hr_fs(_o5604, hr_str(")", 1)); }));
return;
 }
(void)(f304_gen_heq(t_1738));
if ((((k_1741) == (((int64_t)9LL))) || ((((k_1741) == (((int64_t)8LL))) && (!(f287_is_fix(t_1738)))) && (!(f288_is_lim(t_1738)))))) { (void)(({ hrv *_o5608 = &(g169); hr_fs(_o5608, hr_str("heq", 3)); hr_fi(_o5608, t_1738); hr_fs(_o5608, hr_str("(hr_sl(", 7)); hr_fs(_o5608, a_1739); hr_fs(_o5608, hr_str("), hr_sl(", 9)); hr_fs(_o5608, b_1740); hr_fs(_o5608, hr_str("))", 2)); }));
return;
 }
(void)(({ hrv *_o5609 = &(g169); hr_fs(_o5609, hr_str("heq", 3)); hr_fi(_o5609, t_1738); hr_fs(_o5609, hr_str("(", 1)); hr_fs(_o5609, a_1739); hr_fs(_o5609, hr_str(", ", 2)); hr_fs(_o5609, b_1740); hr_fs(_o5609, hr_str(")", 1)); }));
}
static bool f314_hsl_ty(int64_t t_1751) {
return (((((*({ hrv *_t5610 = &(g568); int64_t _i5610 = t_1751; (S1*)_t5610->b + hr_ix(_i5610, _t5610->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:820"); }))).k_) == (((uint8_t)9LL))) || ((((((*({ hrv *_t5611 = &(g568); int64_t _i5611 = t_1751; (S1*)_t5611->b + hr_ix(_i5611, _t5611->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:820"); }))).k_) == (((uint8_t)8LL))) && (!(f287_is_fix(t_1751)))) && (!(f288_is_lim(t_1751)))));
}
static void f315_gxas(int64_t n_1752, int64_t t_1753) {
int64_t f_1754 = f284_fin(n_1752); 
if (((f_1754) == (t_1753))) { (void)(f297_gx(n_1752));
return;
 }
(void)(f273_gcv(n_1752, f141_at(n_1752), t_1753));
}
static void f316_garith(int64_t o_1756, int64_t t0_1757, int64_t a_1758, int64_t b_1759, int64_t tv_1760, int64_t loc_1761) {
int64_t t_1762 = ({ int64_t _r5618; if (((((*({ hrv *_t5619 = &(g568); int64_t _i5619 = t0_1757; (S1*)_t5619->b + hr_ix(_i5619, _t5619->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:253"); }))).k_) == (((uint8_t)12LL)))) { _r5618 = g580;  } else { _r5618 = ({ int64_t _r5620; if (((((*({ hrv *_t5621 = &(g568); int64_t _i5621 = t0_1757; (S1*)_t5621->b + hr_ix(_i5621, _t5621->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:253"); }))).k_) == (((uint8_t)13LL)))) { _r5620 = g586;  } else { _r5620 = t0_1757;  } _r5620; });  } _r5618; }); 
int64_t k_1763 = ((int64_t)(((*({ hrv *_t5622 = &(g568); int64_t _i5622 = t_1762; (S1*)_t5622->b + hr_ix(_i5622, _t5622->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:254"); }))).k_)); 
int64_t lk_1764 = f183_leaf_kind(t_1762); 
if (((lk_1764) >= (((int64_t)4LL)))) { int64_t ta_1765 = ({ int64_t _r5624; if (((a_1758) >= (((int64_t)0LL)))) { _r5624 = f284_fin(a_1758);  } else { _r5624 = t_1762;  } _r5624; }); 
int64_t tb_1766 = ({ int64_t _r5626; if (((b_1759) >= (((int64_t)0LL)))) { _r5626 = f284_fin(b_1759);  } else { _r5626 = t_1762;  } _r5626; }); 
if (((ta_1765) != (t_1762))) { if (((o_1756) != (((int64_t)23LL)))) { (void)(f295_gerr(loc_1761, hr_str("only * takes a scalar on the left of a struct or array", 54)));
return;
 }
(void)(f263_ow(hr_str("hop", 3)));
(void)(f302_oi(t_1762));
(void)(f263_ow(hr_str("_", 1)));
(void)(f302_oi(o_1756));
(void)(f263_ow(hr_str("(", 1)));
(void)(f317_gopnd(b_1759, tv_1760));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f317_gopnd(a_1758, tv_1760));
(void)(f263_ow(hr_str(")", 1)));
(void)(f318_gen_hop(t_1762, o_1756, ta_1765));
return;
 }
(void)(f263_ow(hr_str("hop", 3)));
(void)(f302_oi(t_1762));
(void)(f263_ow(hr_str("_", 1)));
(void)(f302_oi(o_1756));
(void)(f263_ow(hr_str("(", 1)));
(void)(f317_gopnd(a_1758, tv_1760));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f317_gopnd(b_1759, tv_1760));
(void)(f263_ow(hr_str(")", 1)));
(void)(f318_gen_hop(t_1762, o_1756, tb_1766));
return;
 }
if (((k_1763) == (((int64_t)4LL)))) { if (((o_1756) == (((int64_t)25LL)))) { (void)(f263_ow(({ hsl _r5650; if (((((*({ hrv *_t5651 = &(g568); int64_t _i5651 = t_1762; (S1*)_t5651->b + hr_ix(_i5651, _t5651->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:261"); }))).s_) == (((uint8_t)4LL)))) { _r5650 = hr_str("fmodf(", 6);  } else { _r5650 = hr_str("fmod(", 5);  } _r5650; })));
(void)(f317_gopnd(a_1758, tv_1760));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f317_gopnd(b_1759, tv_1760));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
(void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(t_1762));
(void)(f263_ow(hr_str(")(", 2)));
(void)(f317_gopnd(a_1758, tv_1760));
(void)(f263_ow(hr_str(" ", 1)));
(void)(f263_ow(f320_ar_op(o_1756)));
(void)(f263_ow(hr_str(" ", 1)));
(void)(f317_gopnd(b_1759, tv_1760));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
if (((k_1763) == (((int64_t)2LL)))) { (void)(f263_ow(hr_str("((", 2)));
(void)(f317_gopnd(a_1758, tv_1760));
(void)(f263_ow(hr_str(") ", 2)));
(void)(f263_ow(f320_ar_op(o_1756)));
(void)(f263_ow(hr_str(" (", 2)));
(void)(f317_gopnd(b_1759, tv_1760));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
bool sg_1797 = (((k_1763) == (((int64_t)3LL))) && f156_is_signed(t_1762)); 
if ((((o_1756) == (((int64_t)24LL))) || ((o_1756) == (((int64_t)25LL))))) { (void)(f263_ow(({ hsl _r5676; if (((o_1756) == (((int64_t)24LL)))) { _r5676 = ({ hsl _r5677; if (sg_1797) { _r5677 = hr_str("HR_SDIV(", 8);  } else { _r5677 = hr_str("HR_UDIV(", 8);  } _r5677; });  } else { _r5676 = ({ hsl _r5678; if (sg_1797) { _r5678 = hr_str("HR_SMOD(", 8);  } else { _r5678 = hr_str("HR_UDIV_MOD(", 12);  } _r5678; });  } _r5676; })));
(void)(f264_ct(t_1762));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f317_gopnd(a_1758, tv_1760));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f317_gopnd(b_1759, tv_1760));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f321_wloc(loc_1761));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if ((((o_1756) == (((int64_t)43LL))) || ((o_1756) == (((int64_t)44LL))))) { (void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(t_1762));
(void)(f263_ow(hr_str(")((", 3)));
(void)(f317_gopnd(a_1758, tv_1760));
(void)(f263_ow(hr_str(") ", 2)));
(void)(f263_ow(f320_ar_op(o_1756)));
(void)(f263_ow(hr_str(" ((", 3)));
(void)(f317_gopnd(b_1759, tv_1760));
(void)(({ hrv *_o5696 = &(g163); hr_fs(_o5696, hr_str(") & ", 4)); hr_fi(_o5696, ((int64_t)((int64_t)f157_ibits(t_1762) - (int64_t)((int64_t)1LL)))); hr_fs(_o5696, hr_str(")))", 3)); }));
return;
 }
(void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(t_1762));
(void)(f263_ow(hr_str(")(", 2)));
if (sg_1797) { (void)(f263_ow(hr_str("(int64_t)", 9)));
 } else { (void)(f263_ow(hr_str("(uint64_t)", 10)));
 }
(void)(f317_gopnd(a_1758, tv_1760));
(void)(f263_ow(hr_str(" ", 1)));
(void)(f263_ow(f320_ar_op(o_1756)));
(void)(f263_ow(hr_str(" ", 1)));
if (sg_1797) { (void)(f263_ow(hr_str("(int64_t)", 9)));
 } else { (void)(f263_ow(hr_str("(uint64_t)", 10)));
 }
(void)(f317_gopnd(b_1759, tv_1760));
(void)(f263_ow(hr_str("))", 2)));
}
static void f317_gopnd(int64_t n_1767, int64_t tv_1768) {
if (((n_1767) >= (((int64_t)0LL)))) { (void)(f297_gx(n_1767));
 } else { (void)(({ hrv *_o5713 = &(g163); hr_fs(_o5713, hr_str("(*_t", 4)); hr_fi(_o5713, tv_1768); hr_fs(_o5713, hr_str(")", 1)); }));
 }
}
static void f318_gen_hop(int64_t t_1769, int64_t o_1770, int64_t bt_1771) {
int64_t key_1772 = ((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)(t_1769)) * (int64_t)((int64_t)4096LL))) + (int64_t)((int64_t)((int64_t)((int64_t)(o_1770)) * (int64_t)((int64_t)64LL))))) + (int64_t)({ int64_t _r5714; if (((bt_1771) == (t_1769))) { _r5714 = ((int64_t)0LL);  } else { _r5714 = ((int64_t)1LL);  } _r5714; }))); 
{ hrv *_v5716 = &(g246); for (int64_t _k5716 = 0; _k5716 < _v5716->n; _k5716++) { int64_t h_1773 = ((int64_t*)_v5716->b)[_k5716]; if (((h_1773) == (key_1772))) { return;
 }
 } } _bk5715:; 
(void)(({ hrv *_v5717 = &(g246); int64_t _x5717 = key_1772; int64_t *_p5717 = (int64_t*)hr_grow(_v5717, 1, sizeof _x5717); *_p5717 = _x5717; _p5717; }));
(void)(f265_cbody(t_1769));
int64_t lt_1774 = f184_leaf_type(t_1769); 
bool sc_1775 = ((bt_1771) != (t_1769)); 
L99 sig_1776 = ({ L99 _t5720; memset(&_t5720, 0, sizeof _t5720); _t5720.n = 0; _t5720; }); 
(void)(({ L99 *_l5721 = &(sig_1776); hrv _o5721 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5721, hr_str("static ", 7)); if (_l5721->n + _o5721.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:553"); memcpy(_l5721->e + _l5721->n, _o5721.b, (size_t)_o5721.n); _l5721->n += _o5721.n; }));
(void)(({ L99 *_v5722 = &(sig_1776); hsl _s5722 = f267_cn(t_1769); if (_v5722->n + _s5722.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:553"); memmove(_v5722->e + _v5722->n, _s5722.p, (size_t)_s5722.n * sizeof _v5722->e[0]); _v5722->n += _s5722.n; }));
(void)(({ L99 *_l5724 = &(sig_1776); hrv _o5724 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5724, hr_str(" hop", 4)); hr_fi(&_o5724, t_1769); hr_fs(&_o5724, hr_str("_", 1)); hr_fi(&_o5724, o_1770); hr_fs(&_o5724, hr_str("(", 1)); if (_l5724->n + _o5724.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:553"); memcpy(_l5724->e + _l5724->n, _o5724.b, (size_t)_o5724.n); _l5724->n += _o5724.n; }));
(void)(({ L99 *_v5725 = &(sig_1776); hsl _s5725 = f267_cn(t_1769); if (_v5725->n + _s5725.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:554"); memmove(_v5725->e + _v5725->n, _s5725.p, (size_t)_s5725.n * sizeof _v5725->e[0]); _v5725->n += _s5725.n; }));
(void)(({ L99 *_v5727 = &(sig_1776); hsl _s5727 = hr_str(" a, ", 4); if (_v5727->n + _s5727.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:554"); memmove(_v5727->e + _v5727->n, _s5727.p, (size_t)_s5727.n * sizeof _v5727->e[0]); _v5727->n += _s5727.n; }));
(void)(({ L99 *_v5728 = &(sig_1776); hsl _s5728 = f267_cn(({ int64_t _r5730; if (sc_1775) { _r5730 = bt_1771;  } else { _r5730 = t_1769;  } _r5730; })); if (_v5728->n + _s5728.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:554"); memmove(_v5728->e + _v5728->n, _s5728.p, (size_t)_s5728.n * sizeof _v5728->e[0]); _v5728->n += _s5728.n; }));
(void)(({ L99 *_v5731 = &(sig_1776); hsl _s5731 = hr_str(" b)", 3); if (_v5731->n + _s5731.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:554"); memmove(_v5731->e + _v5731->n, _s5731.p, (size_t)_s5731.n * sizeof _v5731->e[0]); _v5731->n += _s5731.n; }));
(void)(({ hrv *_v5732 = &(g166); hsl _s5732 = ({ hsl _t5733 = ({ L99 *_t5734 = &(sig_1776); (hsl){ (uint8_t*)_t5734->e, _t5734->n }; }); int64_t _l5733 = 0, _h5733 = _t5733.n; if (_l5733 < 0 || _h5733 < _l5733 || _h5733 > _t5733.n) hr_slerr(_l5733, _h5733, _t5733.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:555"); (hsl){ _t5733.p + _l5733 * (int64_t)sizeof(uint8_t), _h5733 - _l5733 }; }); hr_append(_v5732, _s5732.p, _s5732.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5735 = &(g166); hsl _s5735 = hr_str(";\012", 2); hr_append(_v5735, _s5735.p, _s5735.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5736 = &(g169); hsl _s5736 = ({ hsl _t5737 = ({ L99 *_t5738 = &(sig_1776); (hsl){ (uint8_t*)_t5738->e, _t5738->n }; }); int64_t _l5737 = 0, _h5737 = _t5737.n; if (_l5737 < 0 || _h5737 < _l5737 || _h5737 > _t5737.n) hr_slerr(_l5737, _h5737, _t5737.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:556"); (hsl){ _t5737.p + _l5737 * (int64_t)sizeof(uint8_t), _h5737 - _l5737 }; }); hr_append(_v5736, _s5736.p, _s5736.n, sizeof(uint8_t)); }));
(void)(f310_hh(hr_str(" { ", 3)));
(void)(({ hrv *_v5740 = &(g169); hsl _s5740 = f267_cn(t_1769); hr_append(_v5740, _s5740.p, _s5740.n, sizeof(uint8_t)); }));
(void)(f310_hh(hr_str(" r; ", 4)));
(void)(f319_hop_body(t_1769, o_1770, hr_str("r", 1), hr_str("a", 1), hr_str("b", 1), sc_1775));
(void)(f310_hh(hr_str("return r; }\012", 12)));
}
static void f319_hop_body(int64_t t_1777, int64_t o_1778, hsl r_1779, hsl a_1780, hsl b_1781, bool sc_1782) {
int64_t k_1783 = ((int64_t)(((*({ hrv *_t5745 = &(g568); int64_t _i5745 = t_1777; (S1*)_t5745->b + hr_ix(_i5745, _t5745->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:561"); }))).k_)); 
if ((((k_1783) == (((int64_t)3LL))) || ((k_1783) == (((int64_t)4LL))))) { (void)(({ hrv *_o5746 = &(g169); hr_fs(_o5746, r_1779); hr_fs(_o5746, hr_str(" = (", 4)); }));
(void)(({ hrv *_v5747 = &(g169); hsl _s5747 = f267_cn(t_1777); hr_append(_v5747, _s5747.p, _s5747.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o5749 = &(g169); hr_fs(_o5749, hr_str(")((", 3)); hr_fs(_o5749, a_1780); hr_fs(_o5749, hr_str(") ", 2)); hr_fs(_o5749, f320_ar_op(o_1778)); hr_fs(_o5749, hr_str(" (", 2)); hr_fs(_o5749, b_1781); hr_fs(_o5749, hr_str(")); ", 4)); }));
return;
 }
if (((k_1783) == (((int64_t)5LL)))) { int64_t si_1785 = ((int64_t)(((*({ hrv *_t5751 = &(g568); int64_t _i5751 = t_1777; (S1*)_t5751->b + hr_ix(_i5751, _t5751->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:564"); }))).a_)); 
int64_t f0_1786 = ((int64_t)(((*({ hrv *_t5752 = &(g571); int64_t _i5752 = si_1785; (S10*)_t5752->b + hr_ix(_i5752, _t5752->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:564"); }))).f0_)); 
{ int32_t _e5754 = ((*({ hrv *_t5755 = &(g571); int64_t _i5755 = si_1785; (S10*)_t5755->b + hr_ix(_i5755, _t5755->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:565"); }))).fnum_; for (int32_t _k5754 = 0; _k5754 < _e5754; _k5754++) { int32_t i_1787 = (int32_t)_k5754; S11 f_1788 = (*({ hrv *_t5756 = &(g572); int64_t _i5756 = ((int64_t)((int64_t)f0_1786 + (int64_t)((int64_t)(i_1787)))); (S11*)_t5756->b + hr_ix(_i5756, _t5756->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:566"); })); 
if ((((f_1788).ty_) < (((int32_t)0LL)))) { continue;
 }
L99 rr_1789 = ({ L99 _t5757; memset(&_t5757, 0, sizeof _t5757); _t5757.n = 0; _t5757; }); 
L99 aa_1790 = ({ L99 _t5758; memset(&_t5758, 0, sizeof _t5758); _t5758.n = 0; _t5758; }); 
L99 bb_1791 = ({ L99 _t5759; memset(&_t5759, 0, sizeof _t5759); _t5759.n = 0; _t5759; }); 
(void)(({ L99 *_v5760 = &(rr_1789); hsl _s5760 = r_1779; if (_v5760->n + _s5760.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:568"); memmove(_v5760->e + _v5760->n, _s5760.p, (size_t)_s5760.n * sizeof _v5760->e[0]); _v5760->n += _s5760.n; }));
(void)(({ L99 *_v5761 = &(rr_1789); uint8_t _x5761 = ((uint8_t)46LL); if (_v5761->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:568"); _v5761->e[_v5761->n] = _x5761; &_v5761->e[_v5761->n++]; }));
(void)(({ L99 *_v5762 = &(aa_1790); hsl _s5762 = a_1780; if (_v5762->n + _s5762.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:568"); memmove(_v5762->e + _v5762->n, _s5762.p, (size_t)_s5762.n * sizeof _v5762->e[0]); _v5762->n += _s5762.n; }));
(void)(({ L99 *_v5763 = &(aa_1790); uint8_t _x5763 = ((uint8_t)46LL); if (_v5763->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:568"); _v5763->e[_v5763->n] = _x5763; &_v5763->e[_v5763->n++]; }));
(void)(({ L99 *_v5764 = &(bb_1791); hsl _s5764 = b_1781; if (_v5764->n + _s5764.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:568"); memmove(_v5764->e + _v5764->n, _s5764.p, (size_t)_s5764.n * sizeof _v5764->e[0]); _v5764->n += _s5764.n; }));
if ((!(sc_1782))) { (void)(({ L99 *_v5765 = &(bb_1791); uint8_t _x5765 = ((uint8_t)46LL); if (_v5765->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:568"); _v5765->e[_v5765->n] = _x5765; &_v5765->e[_v5765->n++]; }));
 }
{ hsl _v5767 = f10_nm(((int64_t)((f_1788).name_))); for (int64_t _k5767 = 0; _k5767 < _v5767.n; _k5767++) { uint8_t ch_1792 = ((uint8_t*)_v5767.p)[_k5767]; (void)(({ L99 *_v5769 = &(rr_1789); uint8_t _x5769 = ch_1792; if (_v5769->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:569"); _v5769->e[_v5769->n] = _x5769; &_v5769->e[_v5769->n++]; }));
(void)(({ L99 *_v5770 = &(aa_1790); uint8_t _x5770 = ch_1792; if (_v5770->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:569"); _v5770->e[_v5770->n] = _x5770; &_v5770->e[_v5770->n++]; }));
if ((!(sc_1782))) { (void)(({ L99 *_v5771 = &(bb_1791); uint8_t _x5771 = ch_1792; if (_v5771->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:569"); _v5771->e[_v5771->n] = _x5771; &_v5771->e[_v5771->n++]; }));
 }
 } } _bk5766:; 
(void)(({ L99 *_v5772 = &(rr_1789); uint8_t _x5772 = ((uint8_t)95LL); if (_v5772->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:570"); _v5772->e[_v5772->n] = _x5772; &_v5772->e[_v5772->n++]; }));
(void)(({ L99 *_v5773 = &(aa_1790); uint8_t _x5773 = ((uint8_t)95LL); if (_v5773->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:570"); _v5773->e[_v5773->n] = _x5773; &_v5773->e[_v5773->n++]; }));
if ((!(sc_1782))) { (void)(({ L99 *_v5774 = &(bb_1791); uint8_t _x5774 = ((uint8_t)95LL); if (_v5774->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:570"); _v5774->e[_v5774->n] = _x5774; &_v5774->e[_v5774->n++]; }));
 }
(void)(f319_hop_body(((int64_t)((f_1788).ty_)), o_1778, ({ hsl _t5776 = ({ L99 *_t5777 = &(rr_1789); (hsl){ (uint8_t*)_t5777->e, _t5777->n }; }); int64_t _l5776 = 0, _h5776 = _t5776.n; if (_l5776 < 0 || _h5776 < _l5776 || _h5776 > _t5776.n) hr_slerr(_l5776, _h5776, _t5776.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:571"); (hsl){ _t5776.p + _l5776 * (int64_t)sizeof(uint8_t), _h5776 - _l5776 }; }), ({ hsl _t5778 = ({ L99 *_t5779 = &(aa_1790); (hsl){ (uint8_t*)_t5779->e, _t5779->n }; }); int64_t _l5778 = 0, _h5778 = _t5778.n; if (_l5778 < 0 || _h5778 < _l5778 || _h5778 > _t5778.n) hr_slerr(_l5778, _h5778, _t5778.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:571"); (hsl){ _t5778.p + _l5778 * (int64_t)sizeof(uint8_t), _h5778 - _l5778 }; }), ({ hsl _t5780 = ({ L99 *_t5781 = &(bb_1791); (hsl){ (uint8_t*)_t5781->e, _t5781->n }; }); int64_t _l5780 = 0, _h5780 = _t5780.n; if (_l5780 < 0 || _h5780 < _l5780 || _h5780 > _t5780.n) hr_slerr(_l5780, _h5780, _t5780.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:571"); (hsl){ _t5780.p + _l5780 * (int64_t)sizeof(uint8_t), _h5780 - _l5780 }; }), sc_1782));
 } } _bk5753:; 
return;
 }
if (f287_is_fix(t_1777)) { int64_t p_1793 = f301_nt(); 
(void)(({ hrv *_o5784 = &(g169); hr_fs(_o5784, hr_str("for (int64_t _i", 15)); hr_fi(_o5784, p_1793); hr_fs(_o5784, hr_str(" = 0; _i", 8)); hr_fi(_o5784, p_1793); hr_fs(_o5784, hr_str(" < ", 3)); hr_fi(_o5784, ((*({ hrv *_t5785 = &(g568); int64_t _i5785 = t_1777; (S1*)_t5785->b + hr_ix(_i5785, _t5785->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:577"); }))).b_); hr_fs(_o5784, hr_str("; _i", 4)); hr_fi(_o5784, p_1793); hr_fs(_o5784, hr_str("++) { ", 6)); }));
L99 rr_1794 = ({ L99 _t5786; memset(&_t5786, 0, sizeof _t5786); _t5786.n = 0; _t5786; }); 
L99 aa_1795 = ({ L99 _t5787; memset(&_t5787, 0, sizeof _t5787); _t5787.n = 0; _t5787; }); 
L99 bb_1796 = ({ L99 _t5788; memset(&_t5788, 0, sizeof _t5788); _t5788.n = 0; _t5788; }); 
(void)(({ L99 *_l5789 = &(rr_1794); hrv _o5789 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5789, r_1779); hr_fs(&_o5789, hr_str(".e[_i", 5)); hr_fi(&_o5789, p_1793); hr_fs(&_o5789, hr_str("]", 1)); if (_l5789->n + _o5789.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:579"); memcpy(_l5789->e + _l5789->n, _o5789.b, (size_t)_o5789.n); _l5789->n += _o5789.n; }));
(void)(({ L99 *_l5790 = &(aa_1795); hrv _o5790 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5790, a_1780); hr_fs(&_o5790, hr_str(".e[_i", 5)); hr_fi(&_o5790, p_1793); hr_fs(&_o5790, hr_str("]", 1)); if (_l5790->n + _o5790.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:579"); memcpy(_l5790->e + _l5790->n, _o5790.b, (size_t)_o5790.n); _l5790->n += _o5790.n; }));
if (sc_1782) { (void)(({ L99 *_v5791 = &(bb_1796); hsl _s5791 = b_1781; if (_v5791->n + _s5791.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:579"); memmove(_v5791->e + _v5791->n, _s5791.p, (size_t)_s5791.n * sizeof _v5791->e[0]); _v5791->n += _s5791.n; }));
 } else { (void)(({ L99 *_l5792 = &(bb_1796); hrv _o5792 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5792, b_1781); hr_fs(&_o5792, hr_str(".e[_i", 5)); hr_fi(&_o5792, p_1793); hr_fs(&_o5792, hr_str("]", 1)); if (_l5792->n + _o5792.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:579"); memcpy(_l5792->e + _l5792->n, _o5792.b, (size_t)_o5792.n); _l5792->n += _o5792.n; }));
 }
(void)(f319_hop_body(((int64_t)(((*({ hrv *_t5794 = &(g568); int64_t _i5794 = t_1777; (S1*)_t5794->b + hr_ix(_i5794, _t5794->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:580"); }))).a_)), o_1778, ({ hsl _t5795 = ({ L99 *_t5796 = &(rr_1794); (hsl){ (uint8_t*)_t5796->e, _t5796->n }; }); int64_t _l5795 = 0, _h5795 = _t5795.n; if (_l5795 < 0 || _h5795 < _l5795 || _h5795 > _t5795.n) hr_slerr(_l5795, _h5795, _t5795.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:580"); (hsl){ _t5795.p + _l5795 * (int64_t)sizeof(uint8_t), _h5795 - _l5795 }; }), ({ hsl _t5797 = ({ L99 *_t5798 = &(aa_1795); (hsl){ (uint8_t*)_t5798->e, _t5798->n }; }); int64_t _l5797 = 0, _h5797 = _t5797.n; if (_l5797 < 0 || _h5797 < _l5797 || _h5797 > _t5797.n) hr_slerr(_l5797, _h5797, _t5797.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:580"); (hsl){ _t5797.p + _l5797 * (int64_t)sizeof(uint8_t), _h5797 - _l5797 }; }), ({ hsl _t5799 = ({ L99 *_t5800 = &(bb_1796); (hsl){ (uint8_t*)_t5800->e, _t5800->n }; }); int64_t _l5799 = 0, _h5799 = _t5799.n; if (_l5799 < 0 || _h5799 < _l5799 || _h5799 > _t5799.n) hr_slerr(_l5799, _h5799, _t5799.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:580"); (hsl){ _t5799.p + _l5799 * (int64_t)sizeof(uint8_t), _h5799 - _l5799 }; }), sc_1782));
(void)(f310_hh(hr_str("} ", 2)));
 }
}
static hsl f320_ar_op(int64_t o_1784) {
if ((((o_1784) == (((int64_t)21LL))) || ((o_1784) == (((int64_t)26LL))))) { return hr_str("+", 1);
 }
if ((((o_1784) == (((int64_t)22LL))) || ((o_1784) == (((int64_t)27LL))))) { return hr_str("-", 1);
 }
if ((((o_1784) == (((int64_t)23LL))) || ((o_1784) == (((int64_t)28LL))))) { return hr_str("*", 1);
 }
if ((((o_1784) == (((int64_t)24LL))) || ((o_1784) == (((int64_t)29LL))))) { return hr_str("/", 1);
 }
if ((((o_1784) == (((int64_t)25LL))) || ((o_1784) == (((int64_t)30LL))))) { return hr_str("%", 1);
 }
if ((((o_1784) == (((int64_t)49LL))) || ((o_1784) == (((int64_t)31LL))))) { return hr_str("&", 1);
 }
if ((((o_1784) == (((int64_t)50LL))) || ((o_1784) == (((int64_t)32LL))))) { return hr_str("|", 1);
 }
if ((((o_1784) == (((int64_t)51LL))) || ((o_1784) == (((int64_t)33LL))))) { return hr_str("^", 1);
 }
if ((((o_1784) == (((int64_t)43LL))) || ((o_1784) == (((int64_t)45LL))))) { return hr_str("<<", 2);
 }
if ((((o_1784) == (((int64_t)44LL))) || ((o_1784) == (((int64_t)46LL))))) { return hr_str(">>", 2);
 }
return hr_str("\077", 1);
}
static void f321_wloc(int64_t n_1798) {
S3 x_1799 = (*({ hrv *_t5802 = &(g931); int64_t _i5802 = ((*({ hrv *_t5803 = &(g721); int64_t _i5803 = f103_max(n_1798, ((int64_t)0LL)); (S4*)_t5803->b + hr_ix(_i5803, _t5803->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:106"); }))).t_; (S3*)_t5802->b + hr_ix(_i5802, _t5802->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:106"); })); 
(void)(f263_ow(hr_str("\"", 1)));
{ hsl _v5807 = f10_nm(((int64_t)(((*({ hrv *_t5809 = &(g930); int64_t _i5809 = (x_1799).f_; (S2*)_t5809->b + hr_ix(_i5809, _t5809->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:106"); }))).name_))); for (int64_t _k5807 = 0; _k5807 < _v5807.n; _k5807++) { uint8_t c_1800 = ((uint8_t*)_v5807.p)[_k5807]; if ((((c_1800) == (((uint8_t)34LL))) || ((c_1800) == (((uint8_t)92LL))))) { (void)(({ hrv *_v5810 = &(g163); uint8_t _x5810 = ((uint8_t)92LL); uint8_t *_p5810 = (uint8_t*)hr_grow(_v5810, 1, sizeof _x5810); *_p5810 = _x5810; _p5810; }));
 }
(void)(({ hrv *_v5811 = &(g163); uint8_t _x5811 = c_1800; uint8_t *_p5811 = (uint8_t*)hr_grow(_v5811, 1, sizeof _x5811); *_p5811 = _x5811; _p5811; }));
 } } _bk5806:; 
(void)(({ hrv *_o5812 = &(g163); hr_fs(_o5812, hr_str(":", 1)); hr_fi(_o5812, (x_1799).line_); hr_fs(_o5812, hr_str("\"", 1)); }));
}
static void f322_gun(int64_t n_1801) {
S4 x_1802 = (*({ hrv *_t5813 = &(g721); int64_t _i5813 = n_1801; (S4*)_t5813->b + hr_ix(_i5813, _t5813->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:288"); })); 
int64_t o_1803 = ((int64_t)((x_1802).op_)); 
int64_t a_1804 = ((int64_t)((x_1802).a_)); 
if (((o_1803) == (((int64_t)47LL)))) { (void)(f263_ow(hr_str("(!(", 3)));
(void)(f297_gx(a_1804));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
if (((o_1803) == (((int64_t)49LL)))) { (void)(f297_gx(a_1804));
return;
 }
int64_t t_1805 = f284_fin(n_1801); 
if (((o_1803) == (((int64_t)22LL)))) { if (((((*({ hrv *_t5819 = &(g568); int64_t _i5819 = t_1805; (S1*)_t5819->b + hr_ix(_i5819, _t5819->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:292"); }))).k_) == (((uint8_t)4LL)))) { (void)(f263_ow(hr_str("(-(", 3)));
(void)(f297_gx(a_1804));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
if (((f183_leaf_kind(t_1805)) >= (((int64_t)4LL)))) { (void)(f263_ow(hr_str("hneg", 4)));
(void)(f302_oi(t_1805));
(void)(f263_ow(hr_str("(", 1)));
(void)(f297_gx(a_1804));
(void)(f263_ow(hr_str(")", 1)));
(void)(f323_gen_hneg(t_1805));
return;
 }
(void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(t_1805));
(void)(f263_ow(hr_str(")(0 - (uint64_t)(", 17)));
(void)(f297_gx(a_1804));
(void)(f263_ow(hr_str(")))", 3)));
return;
 }
if (((o_1803) == (((int64_t)48LL)))) { (void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(t_1805));
(void)(f263_ow(hr_str(")~(", 3)));
(void)(f297_gx(a_1804));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
if (((o_1803) == (((int64_t)23LL)))) { (void)(f263_ow(hr_str("(*", 2)));
(void)(f297_gx(a_1804));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if (((o_1803) == (((int64_t)21LL)))) { (void)(f297_gx(a_1804));
return;
 }
(void)(f295_gerr(n_1801, hr_str("unsupported unary operator", 26)));
}
static void f323_gen_hneg(int64_t t_1806) {
{ hrv *_v5846 = &(g249); for (int64_t _k5846 = 0; _k5846 < _v5846->n; _k5846++) { int32_t h_1807 = ((int32_t*)_v5846->b)[_k5846]; if (((((int64_t)(h_1807))) == (t_1806))) { return;
 }
 } } _bk5845:; 
(void)(({ hrv *_v5847 = &(g249); int32_t _x5847 = ((int32_t)(t_1806)); int32_t *_p5847 = (int32_t*)hr_grow(_v5847, 1, sizeof _x5847); *_p5847 = _x5847; _p5847; }));
(void)(f265_cbody(t_1806));
L99 sig_1808 = ({ L99 _t5849; memset(&_t5849, 0, sizeof _t5849); _t5849.n = 0; _t5849; }); 
(void)(({ L99 *_l5850 = &(sig_1808); hrv _o5850 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5850, hr_str("static ", 7)); if (_l5850->n + _o5850.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:590"); memcpy(_l5850->e + _l5850->n, _o5850.b, (size_t)_o5850.n); _l5850->n += _o5850.n; }));
(void)(({ L99 *_v5851 = &(sig_1808); hsl _s5851 = f267_cn(t_1806); if (_v5851->n + _s5851.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:590"); memmove(_v5851->e + _v5851->n, _s5851.p, (size_t)_s5851.n * sizeof _v5851->e[0]); _v5851->n += _s5851.n; }));
(void)(({ L99 *_l5853 = &(sig_1808); hrv _o5853 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5853, hr_str(" hneg", 5)); hr_fi(&_o5853, t_1806); hr_fs(&_o5853, hr_str("(", 1)); if (_l5853->n + _o5853.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:590"); memcpy(_l5853->e + _l5853->n, _o5853.b, (size_t)_o5853.n); _l5853->n += _o5853.n; }));
(void)(({ L99 *_v5854 = &(sig_1808); hsl _s5854 = f267_cn(t_1806); if (_v5854->n + _s5854.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:590"); memmove(_v5854->e + _v5854->n, _s5854.p, (size_t)_s5854.n * sizeof _v5854->e[0]); _v5854->n += _s5854.n; }));
(void)(({ L99 *_v5856 = &(sig_1808); hsl _s5856 = hr_str(" a)", 3); if (_v5856->n + _s5856.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:590"); memmove(_v5856->e + _v5856->n, _s5856.p, (size_t)_s5856.n * sizeof _v5856->e[0]); _v5856->n += _s5856.n; }));
(void)(({ hrv *_v5857 = &(g166); hsl _s5857 = ({ hsl _t5858 = ({ L99 *_t5859 = &(sig_1808); (hsl){ (uint8_t*)_t5859->e, _t5859->n }; }); int64_t _l5858 = 0, _h5858 = _t5858.n; if (_l5858 < 0 || _h5858 < _l5858 || _h5858 > _t5858.n) hr_slerr(_l5858, _h5858, _t5858.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:591"); (hsl){ _t5858.p + _l5858 * (int64_t)sizeof(uint8_t), _h5858 - _l5858 }; }); hr_append(_v5857, _s5857.p, _s5857.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5860 = &(g166); hsl _s5860 = hr_str(";\012", 2); hr_append(_v5860, _s5860.p, _s5860.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5861 = &(g169); hsl _s5861 = ({ hsl _t5862 = ({ L99 *_t5863 = &(sig_1808); (hsl){ (uint8_t*)_t5863->e, _t5863->n }; }); int64_t _l5862 = 0, _h5862 = _t5862.n; if (_l5862 < 0 || _h5862 < _l5862 || _h5862 > _t5862.n) hr_slerr(_l5862, _h5862, _t5862.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:592"); (hsl){ _t5862.p + _l5862 * (int64_t)sizeof(uint8_t), _h5862 - _l5862 }; }); hr_append(_v5861, _s5861.p, _s5861.n, sizeof(uint8_t)); }));
(void)(f310_hh(hr_str(" { ", 3)));
(void)(({ hrv *_v5865 = &(g169); hsl _s5865 = f267_cn(t_1806); hr_append(_v5865, _s5865.p, _s5865.n, sizeof(uint8_t)); }));
(void)(f310_hh(hr_str(" z; memset(&z, 0, sizeof z); ", 29)));
(void)(({ hrv *_v5868 = &(g169); hsl _s5868 = f267_cn(t_1806); hr_append(_v5868, _s5868.p, _s5868.n, sizeof(uint8_t)); }));
(void)(f310_hh(hr_str(" r; ", 4)));
(void)(f319_hop_body(t_1806, ((int64_t)22LL), hr_str("r", 1), hr_str("z", 1), hr_str("a", 1), false));
(void)(f310_hh(hr_str("return r; }\012", 12)));
}
static void f324_gidx(int64_t n_1821) {
S4 x_1822 = (*({ hrv *_t5873 = &(g721); int64_t _i5873 = n_1821; (S4*)_t5873->b + hr_ix(_i5873, _t5873->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:299"); })); 
int64_t a_1823 = ((int64_t)((x_1822).a_)); 
int64_t bt_1824 = f141_at(a_1823); 
int64_t d_1825 = f182_deref(bt_1824); 
int64_t e_1826 = ((int64_t)(((*({ hrv *_t5876 = &(g568); int64_t _i5876 = d_1825; (S1*)_t5876->b + hr_ix(_i5876, _t5876->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:303"); }))).a_)); 
int64_t p_1827 = f301_nt(); 
if ((f287_is_fix(d_1825) && ((((*({ hrv *_t5879 = &(g568); int64_t _i5879 = bt_1824; (S1*)_t5879->b + hr_ix(_i5879, _t5879->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:305"); }))).k_) != (((uint8_t)10LL))))) { (void)(f263_ow(hr_str("(", 1)));
(void)(f297_gx(a_1823));
(void)(f263_ow(hr_str(").e[hr_ix(", 10)));
(void)(f297_gx(((int64_t)((x_1822).b_))));
(void)(({ hrv *_o5884 = &(g163); hr_fs(_o5884, hr_str(", ", 2)); hr_fi(_o5884, ((*({ hrv *_t5885 = &(g568); int64_t _i5885 = d_1825; (S1*)_t5885->b + hr_ix(_i5885, _t5885->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:306"); }))).b_); hr_fs(_o5884, hr_str(", ", 2)); }));
(void)(f321_wloc(n_1821));
(void)(f263_ow(hr_str(")]", 2)));
return;
 }
(void)(f263_ow(hr_str("(*({ ", 5)));
if (f289_is_vimg(d_1825)) { (void)(f263_ow(hr_str("hsl _t", 6)));
(void)(f302_oi(p_1827));
(void)(f263_ow(hr_str(" = hr_vsl(", 10)));
if (((((*({ hrv *_t5893 = &(g568); int64_t _i5893 = bt_1824; (S1*)_t5893->b + hr_ix(_i5893, _t5893->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:309"); }))).k_) == (((uint8_t)10LL)))) { (void)(f263_ow(hr_str("*", 1)));
(void)(f280_gx0(a_1823));
 } else { (void)(f297_gx(a_1823));
 }
(void)(f290_vargs(d_1825));
(void)(f263_ow(hr_str("); int64_t _i", 13)));
(void)(f302_oi(p_1827));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(((int64_t)((x_1822).b_))));
(void)(f263_ow(hr_str("; (", 3)));
(void)(f264_ct(e_1826));
(void)(f263_ow(hr_str("*)_t", 4)));
(void)(f302_oi(p_1827));
(void)(({ hrv *_o5906 = &(g163); hr_fs(_o5906, hr_str(".p + hr_ix(_i", 13)); hr_fi(_o5906, p_1827); hr_fs(_o5906, hr_str(", _t", 4)); hr_fi(_o5906, p_1827); hr_fs(_o5906, hr_str(".n, ", 4)); }));
(void)(f321_wloc(n_1821));
(void)(f263_ow(hr_str("); }))", 6)));
return;
 }
if (((((*({ hrv *_t5909 = &(g568); int64_t _i5909 = d_1825; (S1*)_t5909->b + hr_ix(_i5909, _t5909->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:310"); }))).k_) == (((uint8_t)9LL)))) { (void)(f263_ow(hr_str("hsl _t", 6)));
(void)(f302_oi(p_1827));
(void)(f263_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t5913 = &(g568); int64_t _i5913 = bt_1824; (S1*)_t5913->b + hr_ix(_i5913, _t5913->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:310"); }))).k_) == (((uint8_t)10LL)))) { (void)(f263_ow(hr_str("*", 1)));
(void)(f280_gx0(a_1823));
 } else { (void)(f297_gx(a_1823));
 }
(void)(f263_ow(hr_str("; int64_t _i", 12)));
(void)(f302_oi(p_1827));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(((int64_t)((x_1822).b_))));
(void)(f263_ow(hr_str("; (", 3)));
(void)(f264_ct(e_1826));
(void)(f263_ow(hr_str("*)_t", 4)));
(void)(f302_oi(p_1827));
(void)(({ hrv *_o5925 = &(g163); hr_fs(_o5925, hr_str(".p + hr_ix(_i", 13)); hr_fi(_o5925, p_1827); hr_fs(_o5925, hr_str(", _t", 4)); hr_fi(_o5925, p_1827); hr_fs(_o5925, hr_str(".n, ", 4)); }));
(void)(f321_wloc(n_1821));
(void)(f263_ow(hr_str("); }))", 6)));
return;
 }
(void)(f264_ct(d_1825));
(void)(f263_ow(hr_str(" *_t", 4)));
(void)(f302_oi(p_1827));
(void)(f263_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t5932 = &(g568); int64_t _i5932 = bt_1824; (S1*)_t5932->b + hr_ix(_i5932, _t5932->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:312"); }))).k_) == (((uint8_t)10LL)))) { (void)(f280_gx0(a_1823));
 } else { if (f275_is_place(a_1823)) { (void)(f263_ow(hr_str("&(", 2)));
(void)(f297_gx(a_1823));
(void)(f263_ow(hr_str(")", 1)));
 } else { int64_t k_1828 = f278_tmp(d_1825, f271_is_res(d_1825)); 
(void)(f263_ow(hr_str("(", 1)));
(void)(f279_ot(k_1828));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f272_gxo(a_1823));
(void)(f263_ow(hr_str(", &", 3)));
(void)(f279_ot(k_1828));
(void)(f263_ow(hr_str(")", 1)));
 }
 }
(void)(f263_ow(hr_str("; int64_t _i", 12)));
(void)(f302_oi(p_1827));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(((int64_t)((x_1822).b_))));
(void)(f263_ow(hr_str("; ", 2)));
if (f271_is_res(d_1825)) { (void)(f263_ow(hr_str("(", 1)));
(void)(f264_ct(e_1826));
(void)(f263_ow(hr_str("*)_t", 4)));
(void)(f302_oi(p_1827));
(void)(({ hrv *_o5957 = &(g163); hr_fs(_o5957, hr_str("->b + hr_ix(_i", 14)); hr_fi(_o5957, p_1827); hr_fs(_o5957, hr_str(", _t", 4)); hr_fi(_o5957, p_1827); hr_fs(_o5957, hr_str("->n, ", 5)); }));
(void)(f321_wloc(n_1821));
(void)(f263_ow(hr_str("); }))", 6)));
return;
 }
if (f287_is_fix(d_1825)) { (void)(({ hrv *_o5961 = &(g163); hr_fs(_o5961, hr_str("_t", 2)); hr_fi(_o5961, p_1827); hr_fs(_o5961, hr_str("->e + hr_ix(_i", 14)); hr_fi(_o5961, p_1827); hr_fs(_o5961, hr_str(", ", 2)); hr_fi(_o5961, ((*({ hrv *_t5962 = &(g568); int64_t _i5962 = d_1825; (S1*)_t5962->b + hr_ix(_i5962, _t5962->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:315"); }))).b_); hr_fs(_o5961, hr_str(", ", 2)); }));
(void)(f321_wloc(n_1821));
(void)(f263_ow(hr_str("); }))", 6)));
return;
 }
(void)(({ hrv *_o5965 = &(g163); hr_fs(_o5965, hr_str("_t", 2)); hr_fi(_o5965, p_1827); hr_fs(_o5965, hr_str("->e + hr_ix(_i", 14)); hr_fi(_o5965, p_1827); hr_fs(_o5965, hr_str(", _t", 4)); hr_fi(_o5965, p_1827); hr_fs(_o5965, hr_str("->n, ", 5)); }));
(void)(f321_wloc(n_1821));
(void)(f263_ow(hr_str("); }))", 6)));
}
static void f325_gslice(int64_t n_1829) {
S4 x_1830 = (*({ hrv *_t5968 = &(g721); int64_t _i5968 = n_1829; (S4*)_t5968->b + hr_ix(_i5968, _t5968->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:319"); })); 
int64_t a_1831 = ((int64_t)((x_1830).a_)); 
int64_t d_1832 = f182_deref(f141_at(a_1831)); 
int64_t e_1833 = ((int64_t)(((*({ hrv *_t5971 = &(g568); int64_t _i5971 = d_1832; (S1*)_t5971->b + hr_ix(_i5971, _t5971->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:322"); }))).a_)); 
int64_t p_1834 = f301_nt(); 
(void)(f263_ow(hr_str("({ hsl _t", 9)));
(void)(f302_oi(p_1834));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f300_gsl(a_1831, f141_at(a_1831)));
(void)(f263_ow(hr_str("; int64_t _l", 12)));
(void)(f302_oi(p_1834));
(void)(f263_ow(hr_str(" = ", 3)));
if ((((x_1830).b_) >= (((int32_t)0LL)))) { if (((((uint16_t)((uint64_t)(x_1830).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_o5981 = &(g163); hr_fs(_o5981, hr_str("_t", 2)); hr_fi(_o5981, p_1834); hr_fs(_o5981, hr_str(".n - ", 5)); }));
 }
(void)(f297_gx(((int64_t)((x_1830).b_))));
 } else { (void)(f263_ow(hr_str("0", 1)));
 }
(void)(f263_ow(hr_str(", _h", 4)));
(void)(f302_oi(p_1834));
(void)(f263_ow(hr_str(" = ", 3)));
if ((((x_1830).c_) >= (((int32_t)0LL)))) { if (((((uint16_t)((uint64_t)(x_1830).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_o5987 = &(g163); hr_fs(_o5987, hr_str("_t", 2)); hr_fi(_o5987, p_1834); hr_fs(_o5987, hr_str(".n - ", 5)); }));
 }
(void)(f297_gx(((int64_t)((x_1830).c_))));
 } else { (void)(({ hrv *_o5989 = &(g163); hr_fs(_o5989, hr_str("_t", 2)); hr_fi(_o5989, p_1834); hr_fs(_o5989, hr_str(".n", 2)); }));
 }
(void)(({ hrv *_o5990 = &(g163); hr_fs(_o5990, hr_str("; if (_l", 8)); hr_fi(_o5990, p_1834); hr_fs(_o5990, hr_str(" < 0 || _h", 10)); hr_fi(_o5990, p_1834); hr_fs(_o5990, hr_str(" < _l", 5)); hr_fi(_o5990, p_1834); hr_fs(_o5990, hr_str(" || _h", 6)); hr_fi(_o5990, p_1834); hr_fs(_o5990, hr_str(" > _t", 5)); hr_fi(_o5990, p_1834); hr_fs(_o5990, hr_str(".n) hr_slerr(_l", 15)); hr_fi(_o5990, p_1834); hr_fs(_o5990, hr_str(", _h", 4)); hr_fi(_o5990, p_1834); hr_fs(_o5990, hr_str(", _t", 4)); hr_fi(_o5990, p_1834); hr_fs(_o5990, hr_str(".n, ", 4)); }));
(void)(f321_wloc(n_1829));
(void)(({ hrv *_o5992 = &(g163); hr_fs(_o5992, hr_str("); (hsl){ _t", 12)); hr_fi(_o5992, p_1834); hr_fs(_o5992, hr_str(".p + _l", 7)); hr_fi(_o5992, p_1834); hr_fs(_o5992, hr_str(" * (int64_t)sizeof(", 19)); }));
(void)(f264_ct(e_1833));
(void)(({ hrv *_o5994 = &(g163); hr_fs(_o5994, hr_str("), _h", 5)); hr_fi(_o5994, p_1834); hr_fs(_o5994, hr_str(" - _l", 5)); hr_fi(_o5994, p_1834); hr_fs(_o5994, hr_str(" }; })", 6)); }));
}
static void f326_garr(int64_t n_1837) {
S4 x_1838 = (*({ hrv *_t5995 = &(g721); int64_t _i5995 = n_1837; (S4*)_t5995->b + hr_ix(_i5995, _t5995->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:332"); })); 
int64_t t_1839 = f141_at(n_1837); 
int64_t e_1840 = ((int64_t)(((*({ hrv *_t5997 = &(g568); int64_t _i5997 = t_1839; (S1*)_t5997->b + hr_ix(_i5997, _t5997->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:334"); }))).a_)); 
int64_t p_1841 = f301_nt(); 
if (f271_is_res(t_1839)) { if (((((x_1838).n_) == (((int32_t)0LL))) && (((x_1838).a_) < (((int32_t)0LL))))) { (void)(f263_ow(hr_str("((hrv){0})", 10)));
return;
 }
(void)(f263_ow(hr_str("({ hrv _t", 9)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str(" = {0}; ", 8)));
if ((((x_1838).a_) >= (((int32_t)0LL)))) { (void)(f263_ow(hr_str("int64_t _c", 10)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(((int64_t)((x_1838).b_))));
(void)(f263_ow(hr_str("; ", 2)));
(void)(f264_ct(e_1840));
(void)(f263_ow(hr_str(" _v", 3)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(((int64_t)((x_1838).a_))));
(void)(f263_ow(hr_str("; ", 2)));
(void)(f264_ct(e_1840));
(void)(f263_ow(hr_str(" *_p", 4)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str(" = (", 4)));
(void)(f264_ct(e_1840));
(void)(({ hrv *_o6020 = &(g163); hr_fs(_o6020, hr_str("*)hr_grow(&_t", 13)); hr_fi(_o6020, p_1841); hr_fs(_o6020, hr_str(", _c", 4)); hr_fi(_o6020, p_1841); hr_fs(_o6020, hr_str(", sizeof _v", 11)); hr_fi(_o6020, p_1841); hr_fs(_o6020, hr_str("); for (int64_t _k = 0; _k < _c", 31)); hr_fi(_o6020, p_1841); hr_fs(_o6020, hr_str("; _k++) _p", 10)); hr_fi(_o6020, p_1841); hr_fs(_o6020, hr_str("[_k] = _v", 9)); hr_fi(_o6020, p_1841); hr_fs(_o6020, hr_str("; ", 2)); }));
 } else { (void)(f264_ct(e_1840));
(void)(f263_ow(hr_str(" *_p", 4)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str(" = (", 4)));
(void)(f264_ct(e_1840));
(void)(({ hrv *_o6026 = &(g163); hr_fs(_o6026, hr_str("*)hr_grow(&_t", 13)); hr_fi(_o6026, p_1841); hr_fs(_o6026, hr_str(", ", 2)); hr_fi(_o6026, (x_1838).n_); hr_fs(_o6026, hr_str(", sizeof(", 9)); }));
(void)(f264_ct(e_1840));
(void)(f263_ow(hr_str(")); ", 4)));
{ int32_t _e6030 = (x_1838).n_; for (int32_t _k6030 = 0; _k6030 < _e6030; _k6030++) { int32_t i_1842 = (int32_t)_k6030; (void)(({ hrv *_o6031 = &(g163); hr_fs(_o6031, hr_str("_p", 2)); hr_fi(_o6031, p_1841); hr_fs(_o6031, hr_str("[", 1)); hr_fi(_o6031, i_1842); hr_fs(_o6031, hr_str("] = ", 4)); }));
(void)(f297_gx(f90_kid(n_1837, ((int64_t)(i_1842)))));
(void)(f263_ow(hr_str("; ", 2)));
 } } _bk6029:; 
 }
(void)(f263_ow(hr_str("_t", 2)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str("; })", 4)));
return;
 }
if ((f287_is_fix(t_1839) || f288_is_lim(t_1839))) { (void)(f263_ow(hr_str("({ ", 3)));
(void)(f264_ct(t_1839));
(void)(f263_ow(hr_str(" _t", 3)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str("; ", 2)));
if ((((x_1838).a_) >= (((int32_t)0LL)))) { (void)(f264_ct(e_1840));
(void)(f263_ow(hr_str(" _v", 3)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(((int64_t)((x_1838).a_))));
(void)(({ hrv *_o6050 = &(g163); hr_fs(_o6050, hr_str("; for (int64_t _k = 0; _k < ", 28)); hr_fi(_o6050, ({ int64_t _r6051; if (f287_is_fix(t_1839)) { _r6051 = ((*({ hrv *_t6053 = &(g568); int64_t _i6053 = t_1839; (S1*)_t6053->b + hr_ix(_i6053, _t6053->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:346"); }))).b_;  } else { _r6051 = ((int64_t)0LL);  } _r6051; })); hr_fs(_o6050, hr_str("; _k++) _t", 10)); hr_fi(_o6050, p_1841); hr_fs(_o6050, hr_str(".e[_k] = _v", 11)); hr_fi(_o6050, p_1841); hr_fs(_o6050, hr_str("; ", 2)); }));
if (f288_is_lim(t_1839)) { (void)(f263_ow(hr_str("int64_t _c", 10)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(((int64_t)((x_1838).b_))));
(void)(({ hrv *_o6059 = &(g163); hr_fs(_o6059, hr_str("; for (int64_t _k = 0; _k < _c", 30)); hr_fi(_o6059, p_1841); hr_fs(_o6059, hr_str("; _k++) _t", 10)); hr_fi(_o6059, p_1841); hr_fs(_o6059, hr_str(".e[_k] = _v", 11)); hr_fi(_o6059, p_1841); hr_fs(_o6059, hr_str("; _t", 4)); hr_fi(_o6059, p_1841); hr_fs(_o6059, hr_str(".n = _c", 7)); hr_fi(_o6059, p_1841); hr_fs(_o6059, hr_str("; ", 2)); }));
 }
 } else { if (f288_is_lim(t_1839)) { (void)(({ hrv *_o6061 = &(g163); hr_fs(_o6061, hr_str("memset(&_t", 10)); hr_fi(_o6061, p_1841); hr_fs(_o6061, hr_str(", 0, sizeof _t", 14)); hr_fi(_o6061, p_1841); hr_fs(_o6061, hr_str("); _t", 5)); hr_fi(_o6061, p_1841); hr_fs(_o6061, hr_str(".n = ", 5)); hr_fi(_o6061, (x_1838).n_); hr_fs(_o6061, hr_str("; ", 2)); }));
 }
{ int32_t _e6063 = (x_1838).n_; for (int32_t _k6063 = 0; _k6063 < _e6063; _k6063++) { int32_t i_1843 = (int32_t)_k6063; (void)(({ hrv *_o6064 = &(g163); hr_fs(_o6064, hr_str("_t", 2)); hr_fi(_o6064, p_1841); hr_fs(_o6064, hr_str(".e[", 3)); hr_fi(_o6064, i_1843); hr_fs(_o6064, hr_str("] = ", 4)); }));
(void)(f297_gx(f90_kid(n_1837, ((int64_t)(i_1843)))));
(void)(f263_ow(hr_str("; ", 2)));
 } } _bk6062:; 
 }
(void)(f263_ow(hr_str("_t", 2)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str("; })", 4)));
return;
 }
if (f289_is_vimg(t_1839)) { if ((!(f303_vok(n_1837, t_1839)))) { return;
 }
g195++;
int64_t hb_1844 = ((int64_t)((int64_t)f151_isz(((int64_t)(((*({ hrv *_t6074 = &(g568); int64_t _i6074 = t_1839; (S1*)_t6074->b + hr_ix(_i6074, _t6074->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:354"); }))).c_))) * (int64_t)((int64_t)(((int64_t)((int64_t)f291_vlim(t_1839) + (int64_t)((int64_t)1LL))))))); 
(void)(f263_ow(hr_str("({ uint8_t *_t", 14)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str(" = ", 3)));
if ((((x_1838).c_) >= (((int32_t)0LL)))) { (void)(f263_ow(hr_str("hr_vmk(0, ", 10)));
(void)(f297_gx(((int64_t)((x_1838).c_))));
(void)(f290_vargs(t_1839));
(void)(f263_ow(hr_str(", sizeof(", 9)));
(void)(f264_ct(e_1840));
(void)(f263_ow(hr_str(")); ", 4)));
 } else { if ((((x_1838).a_) >= (((int32_t)0LL)))) { (void)(f263_ow(hr_str("hr_vmk(", 7)));
(void)(f297_gx(((int64_t)((x_1838).b_))));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f297_gx(((int64_t)((x_1838).b_))));
(void)(f290_vargs(t_1839));
(void)(f263_ow(hr_str(", sizeof(", 9)));
(void)(f264_ct(e_1840));
(void)(f263_ow(hr_str(")); ", 4)));
(void)(f264_ct(e_1840));
(void)(f263_ow(hr_str(" _v", 3)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(((int64_t)((x_1838).a_))));
(void)(f263_ow(hr_str("; ", 2)));
(void)(f264_ct(e_1840));
(void)(f263_ow(hr_str(" *_e", 4)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str(" = (", 4)));
(void)(f264_ct(e_1840));
(void)(({ hrv *_o6104 = &(g163); hr_fs(_o6104, hr_str("*)(_t", 5)); hr_fi(_o6104, p_1841); hr_fs(_o6104, hr_str(" + ", 3)); hr_fi(_o6104, hb_1844); hr_fs(_o6104, hr_str("); for (int64_t _k = 0; _k < hr_vsl(_t", 38)); hr_fi(_o6104, p_1841); }));
(void)(f290_vargs(t_1839));
(void)(({ hrv *_o6106 = &(g163); hr_fs(_o6106, hr_str(").n; _k++) _e", 13)); hr_fi(_o6106, p_1841); hr_fs(_o6106, hr_str("[_k] = _v", 9)); hr_fi(_o6106, p_1841); hr_fs(_o6106, hr_str("; ", 2)); }));
 } else { (void)(({ hrv *_o6107 = &(g163); hr_fs(_o6107, hr_str("hr_vmk(", 7)); hr_fi(_o6107, (x_1838).n_); hr_fs(_o6107, hr_str(", ", 2)); hr_fi(_o6107, (x_1838).n_); }));
(void)(f290_vargs(t_1839));
(void)(f263_ow(hr_str(", sizeof(", 9)));
(void)(f264_ct(e_1840));
(void)(f263_ow(hr_str(")); ", 4)));
(void)(f264_ct(e_1840));
(void)(f263_ow(hr_str(" *_e", 4)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str(" = (", 4)));
(void)(f264_ct(e_1840));
(void)(({ hrv *_o6117 = &(g163); hr_fs(_o6117, hr_str("*)(_t", 5)); hr_fi(_o6117, p_1841); hr_fs(_o6117, hr_str(" + ", 3)); hr_fi(_o6117, hb_1844); hr_fs(_o6117, hr_str("); ", 3)); }));
{ int32_t _e6119 = (x_1838).n_; for (int32_t _k6119 = 0; _k6119 < _e6119; _k6119++) { int32_t i_1845 = (int32_t)_k6119; (void)(({ hrv *_o6120 = &(g163); hr_fs(_o6120, hr_str("_e", 2)); hr_fi(_o6120, p_1841); hr_fs(_o6120, hr_str("[", 1)); hr_fi(_o6120, i_1845); hr_fs(_o6120, hr_str("] = ", 4)); }));
(void)(f297_gx(f90_kid(n_1837, ((int64_t)(i_1845)))));
(void)(f263_ow(hr_str("; ", 2)));
 } } _bk6118:; 
 }
 }
(void)(f263_ow(hr_str("_t", 2)));
(void)(f302_oi(p_1841));
(void)(f263_ow(hr_str("; })", 4)));
return;
 }
(void)(f295_gerr(n_1837, hr_str("unsupported array literal type", 30)));
}
static void f327_gslit(int64_t n_1846) {
S4 x_1847 = (*({ hrv *_t6128 = &(g721); int64_t _i6128 = n_1846; (S4*)_t6128->b + hr_ix(_i6128, _t6128->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:375"); })); 
int64_t t_1848 = f141_at(n_1846); 
int64_t si_1849 = f160_rv(n_1846); 
int64_t f0_1850 = ((int64_t)(((*({ hrv *_t6131 = &(g571); int64_t _i6131 = si_1849; (S10*)_t6131->b + hr_ix(_i6131, _t6131->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:378"); }))).f0_)); 
(void)(f263_ow(hr_str("((", 2)));
(void)(f264_ct(t_1848));
(void)(f263_ow(hr_str("){ ", 3)));
bool any_1851 = false; 
{ int32_t _e6136 = ((*({ hrv *_t6137 = &(g571); int64_t _i6137 = si_1849; (S10*)_t6137->b + hr_ix(_i6137, _t6137->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:381"); }))).fnum_; for (int32_t _k6136 = 0; _k6136 < _e6136; _k6136++) { int32_t j_1852 = (int32_t)_k6136; S11 f_1853 = (*({ hrv *_t6138 = &(g572); int64_t _i6138 = ((int64_t)((int64_t)f0_1850 + (int64_t)((int64_t)(j_1852)))); (S11*)_t6138->b + hr_ix(_i6138, _t6138->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:382"); })); 
if ((((f_1853).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t given_1854 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e6140 = (x_1847).n_; for (int32_t _k6140 = 0; _k6140 < _e6140; _k6140++) { int32_t i_1855 = (int32_t)_k6140; if (((f160_rv(f90_kid(n_1846, ((int64_t)(i_1855))))) == (((int64_t)(j_1852))))) { given_1854 = f90_kid(n_1846, ((int64_t)(i_1855)));
 }
 } } _bk6139:; 
if ((((given_1854) < (((int64_t)0LL))) && (((f_1853).def_) < (((int32_t)0LL))))) { continue;
 }
(void)(f263_ow(hr_str(".", 1)));
(void)(f270_fname_into((&(g163)), ((int64_t)((f_1853).name_))));
(void)(f263_ow(hr_str(" = ", 3)));
if (f277_is_rel(((int64_t)((f_1853).ty_)))) { if ((((given_1854) >= (((int64_t)0LL))) && ((((int64_t)(((*({ hrv *_t6148 = &(g721); int64_t _i6148 = ((*({ hrv *_t6149 = &(g721); int64_t _i6149 = given_1854; (S4*)_t6149->b + hr_ix(_i6149, _t6149->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:388"); }))).a_; (S4*)_t6148->b + hr_ix(_i6148, _t6148->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:388"); }))).k_))) != (((int64_t)6LL))))) { (void)(f295_gerr(given_1854, hr_str("a relative reference built inside a literal is not supported by the self-hosted compiler yet; store it with .= after placing the value", 134)));
 }
(void)(f263_ow(hr_str("0, ", 3)));
any_1851 = true;
continue;
 }
if (((given_1854) >= (((int64_t)0LL)))) { int64_t v_1856 = ((int64_t)(((*({ hrv *_t6152 = &(g721); int64_t _i6152 = given_1854; (S4*)_t6152->b + hr_ix(_i6152, _t6152->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:389"); }))).a_)); 
if (f271_is_res(((int64_t)((f_1853).ty_)))) { (void)(f272_gxo(v_1856));
 } else { (void)(f297_gx(v_1856));
 }
 } else { int64_t sa_1857 = g414; 
g414 = g416;
(void)(f297_gx(((int64_t)((f_1853).def_))));
g414 = sa_1857;
 }
(void)(f263_ow(hr_str(", ", 2)));
any_1851 = true;
 } } _bk6135:; 
if ((!(any_1851))) { (void)(f263_ow(hr_str("0", 1)));
 }
(void)(f263_ow(hr_str("})", 2)));
}
static void f328_gcall(int64_t n_1858) {
int64_t r_1859 = f159_rk(n_1858); 
if (((r_1859) == (((int64_t)4LL)))) { (void)(f329_gbuiltin(n_1858));
return;
 }
if (((r_1859) == (((int64_t)10LL)))) { (void)(f343_gblkcall(n_1858));
return;
 }
if (((r_1859) != (((int64_t)3LL)))) { (void)(f295_gerr(n_1858, hr_str("unsupported call", 16)));
return;
 }
int64_t inst_2099 = f160_rv(n_1858); 
int64_t recv_2100 = ({ int64_t _r6165; if ((((f220_ax(n_1858)) == (((int64_t)1LL))) && ((((*({ hrv *_t6167 = &(g721); int64_t _i6167 = ((*({ hrv *_t6168 = &(g721); int64_t _i6168 = n_1858; (S4*)_t6168->b + hr_ix(_i6168, _t6168->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:637"); }))).a_; (S4*)_t6167->b + hr_ix(_i6167, _t6167->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:637"); }))).k_) == (((uint8_t)14LL))))) { _r6165 = ((int64_t)(((*({ hrv *_t6169 = &(g721); int64_t _i6169 = ((*({ hrv *_t6170 = &(g721); int64_t _i6170 = n_1858; (S4*)_t6170->b + hr_ix(_i6170, _t6170->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:637"); }))).a_; (S4*)_t6169->b + hr_ix(_i6169, _t6169->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:637"); }))).a_));  } else { _r6165 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r6165; }); 
bool lrw_2102 = ((!(f369_is_ext(inst_2099))) && ((*({ hrv *_t6172 = &(g401); int64_t _i6172 = inst_2099; (S6*)_t6172->b + hr_ix(_i6172, _t6172->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:638"); }))).lr_); 
int64_t rt_2103 = ((int64_t)(((*({ hrv *_t6173 = &(g401); int64_t _i6173 = inst_2099; (S6*)_t6173->b + hr_ix(_i6173, _t6173->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:639"); }))).ret_)); 
bool vd_2104 = (((rt_2103) < (((int64_t)0LL))) || ((rt_2103) == (g575))); 
int64_t q_2105 = f301_nt(); 
if (lrw_2102) { (void)(f263_ow(hr_str("({ ", 3)));
if ((!(vd_2104))) { (void)(f264_ct(rt_2103));
(void)(({ hrv *_o6177 = &(g163); hr_fs(_o6177, hr_str(" _c", 3)); hr_fi(_o6177, q_2105); hr_fs(_o6177, hr_str(" = ", 3)); }));
 }
 }
if (f369_is_ext(inst_2099)) { (void)(f370_ext_name(inst_2099));
 } else { (void)(f332_fn_cname(inst_2099));
 }
(void)(f263_ow(hr_str("(", 1)));
(void)(f371_gcall_args(n_1858, inst_2099, recv_2100));
(void)(f263_ow(hr_str(")", 1)));
if (lrw_2102) { (void)(f263_ow(hr_str("; ", 2)));
(void)(f373_glrcheck());
if ((!(vd_2104))) { (void)(({ hrv *_o6186 = &(g163); hr_fs(_o6186, hr_str("_c", 2)); hr_fi(_o6186, q_2105); hr_fs(_o6186, hr_str("; ", 2)); }));
 }
(void)(f263_ow(hr_str("})", 2)));
 }
}
static void f329_gbuiltin(int64_t n_1860) {
S4 x_1861 = (*({ hrv *_t6188 = &(g721); int64_t _i6188 = n_1860; (S4*)_t6188->b + hr_ix(_i6188, _t6188->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:676"); })); 
int64_t b_1862 = f160_rv(n_1860); 
bool hasr_1863 = ((f220_ax(n_1860)) == (((int64_t)1LL))); 
int64_t recv_1864 = ({ int64_t _r6191; if (hasr_1863) { _r6191 = ((int64_t)(((*({ hrv *_t6192 = &(g721); int64_t _i6192 = (x_1861).a_; (S4*)_t6192->b + hr_ix(_i6192, _t6192->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:679"); }))).a_));  } else { _r6191 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r6191; }); 
int64_t total_1865 = ((int64_t)((int64_t)((int64_t)((x_1861).n_)) + (int64_t)({ int64_t _r6193; if (hasr_1863) { _r6193 = ((int64_t)1LL);  } else { _r6193 = ((int64_t)0LL);  } _r6193; }))); 

int64_t p_1867 = f301_nt(); 
if (((b_1862) == (((int64_t)1LL)))) { (void)(f263_ow(hr_str("({ ", 3)));
{ int32_t _e6197 = (x_1861).n_; for (int32_t _k6197 = 0; _k6197 < _e6197; _k6197++) { int32_t i_1868 = (int32_t)_k6197; int64_t c_1869 = f90_kid(n_1860, ((int64_t)(i_1868))); 
(void)(f331_gfmt(hr_str("&hr_ob", 6), c_1869, f284_fin(c_1869), true));
(void)(f263_ow(hr_str("; ", 2)));
 } } _bk6196:; 
(void)(f263_ow(hr_str("hr_println(); })", 16)));
return;
 }
if (((b_1862) == (((int64_t)2LL)))) { (void)(f263_ow(hr_str("({ hrv _o", 9)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" = {0}; ", 8)));
L101 nmo_1885 = ({ L101 _t6206; memset(&_t6206, 0, sizeof _t6206); _t6206.n = 0; _t6206; }); 
(void)(({ L101 *_l6207 = &(nmo_1885); hrv _o6207 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6207, hr_str("&_o", 3)); hr_fi(&_o6207, p_1867); if (_l6207->n + _o6207.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:684"); memcpy(_l6207->e + _l6207->n, _o6207.b, (size_t)_o6207.n); _l6207->n += _o6207.n; }));
{ int32_t _e6209 = (x_1861).n_; for (int32_t _k6209 = 0; _k6209 < _e6209; _k6209++) { int32_t i_1886 = (int32_t)_k6209; int64_t c_1887 = f90_kid(n_1860, ((int64_t)(i_1886))); 
(void)(f331_gfmt(({ hsl _t6212 = ({ L101 *_t6213 = &(nmo_1885); (hsl){ (uint8_t*)_t6213->e, _t6213->n }; }); int64_t _l6212 = 0, _h6212 = _t6212.n; if (_l6212 < 0 || _h6212 < _l6212 || _h6212 > _t6212.n) hr_slerr(_l6212, _h6212, _t6212.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:684"); (hsl){ _t6212.p + _l6212 * (int64_t)sizeof(uint8_t), _h6212 - _l6212 }; }), c_1887, f284_fin(c_1887), true));
(void)(f263_ow(hr_str("; ", 2)));
 } } _bk6208:; 
(void)(f263_ow(hr_str("_o", 2)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str("; })", 4)));
return;
 }
if ((((b_1862) == (((int64_t)3LL))) && f288_is_lim(f182_deref(f141_at(f330_arg(((int64_t)0LL), &recv_1864, &n_1860)))))) { int64_t lt_1888 = f182_deref(f141_at(f330_arg(((int64_t)0LL), &recv_1864, &n_1860))); 
(void)(f263_ow(hr_str("({ ", 3)));
(void)(f264_ct(lt_1888));
(void)(f263_ow(hr_str(" *_l", 4)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f334_grecv_ptr(f330_arg(((int64_t)0LL), &recv_1864, &n_1860)));
(void)(f263_ow(hr_str("; hrv _o", 8)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" __attribute__((cleanup(hr_rdrop))) = {0}; ", 43)));
L101 nmo_1892 = ({ L101 _t6236; memset(&_t6236, 0, sizeof _t6236); _t6236.n = 0; _t6236; }); 
(void)(({ L101 *_l6237 = &(nmo_1892); hrv _o6237 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6237, hr_str("&_o", 3)); hr_fi(&_o6237, p_1867); if (_l6237->n + _o6237.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:688"); memcpy(_l6237->e + _l6237->n, _o6237.b, (size_t)_o6237.n); _l6237->n += _o6237.n; }));
{ int64_t _e6239 = total_1865; for (int64_t _k6239 = ((int64_t)1LL); _k6239 < _e6239; _k6239++) { int64_t i_1893 = (int64_t)_k6239; int64_t c_1894 = f330_arg(i_1893, &recv_1864, &n_1860); 
(void)(f331_gfmt(({ hsl _t6242 = ({ L101 *_t6243 = &(nmo_1892); (hsl){ (uint8_t*)_t6243->e, _t6243->n }; }); int64_t _l6242 = 0, _h6242 = _t6242.n; if (_l6242 < 0 || _h6242 < _l6242 || _h6242 > _t6242.n) hr_slerr(_l6242, _h6242, _t6242.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:689"); (hsl){ _t6242.p + _l6242 * (int64_t)sizeof(uint8_t), _h6242 - _l6242 }; }), c_1894, f284_fin(c_1894), true));
(void)(f263_ow(hr_str("; ", 2)));
 } } _bk6238:; 
(void)(({ hrv *_o6246 = &(g163); hr_fs(_o6246, hr_str("if (_l", 6)); hr_fi(_o6246, p_1867); hr_fs(_o6246, hr_str("->n + _o", 8)); hr_fi(_o6246, p_1867); hr_fs(_o6246, hr_str(".n > ", 5)); hr_fi(_o6246, ((*({ hrv *_t6247 = &(g568); int64_t _i6247 = lt_1888; (S1*)_t6247->b + hr_ix(_i6247, _t6247->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:690"); }))).b_); hr_fs(_o6246, hr_str(") hr_die(\"format past a limited array's capacity\", ", 51)); }));
(void)(f321_wloc(n_1860));
(void)(({ hrv *_o6249 = &(g163); hr_fs(_o6249, hr_str("); memcpy(_l", 12)); hr_fi(_o6249, p_1867); hr_fs(_o6249, hr_str("->e + _l", 8)); hr_fi(_o6249, p_1867); hr_fs(_o6249, hr_str("->n, _o", 7)); hr_fi(_o6249, p_1867); hr_fs(_o6249, hr_str(".b, (size_t)_o", 14)); hr_fi(_o6249, p_1867); hr_fs(_o6249, hr_str(".n); _l", 7)); hr_fi(_o6249, p_1867); hr_fs(_o6249, hr_str("->n += _o", 9)); hr_fi(_o6249, p_1867); hr_fs(_o6249, hr_str(".n; })", 6)); }));
return;
 }
if (((b_1862) == (((int64_t)3LL)))) { (void)(f263_ow(hr_str("({ hrv *_o", 10)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f334_grecv_ptr(f330_arg(((int64_t)0LL), &recv_1864, &n_1860)));
(void)(f263_ow(hr_str("; ", 2)));
L101 nmo_1895 = ({ L101 _t6256; memset(&_t6256, 0, sizeof _t6256); _t6256.n = 0; _t6256; }); 
(void)(({ L101 *_l6257 = &(nmo_1895); hrv _o6257 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6257, hr_str("_o", 2)); hr_fi(&_o6257, p_1867); if (_l6257->n + _o6257.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:693"); memcpy(_l6257->e + _l6257->n, _o6257.b, (size_t)_o6257.n); _l6257->n += _o6257.n; }));
{ int64_t _e6259 = total_1865; for (int64_t _k6259 = ((int64_t)1LL); _k6259 < _e6259; _k6259++) { int64_t i_1896 = (int64_t)_k6259; int64_t c_1897 = f330_arg(i_1896, &recv_1864, &n_1860); 
(void)(f331_gfmt(({ hsl _t6262 = ({ L101 *_t6263 = &(nmo_1895); (hsl){ (uint8_t*)_t6263->e, _t6263->n }; }); int64_t _l6262 = 0, _h6262 = _t6262.n; if (_l6262 < 0 || _h6262 < _l6262 || _h6262 > _t6262.n) hr_slerr(_l6262, _h6262, _t6262.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:693"); (hsl){ _t6262.p + _l6262 * (int64_t)sizeof(uint8_t), _h6262 - _l6262 }; }), c_1897, f284_fin(c_1897), true));
(void)(f263_ow(hr_str("; ", 2)));
 } } _bk6258:; 
(void)(f263_ow(hr_str("})", 2)));
return;
 }
if (((b_1862) == (((int64_t)4LL)))) { (void)(f263_ow(hr_str("({ if (!(", 9)));
(void)(f297_gx(f330_arg(((int64_t)0LL), &recv_1864, &n_1860)));
(void)(f263_ow(hr_str(")) hr_assert_fail(", 18)));
(void)(f321_wloc(n_1860));
(void)(f263_ow(hr_str("); })", 5)));
return;
 }
if (((b_1862) == (((int64_t)5LL)))) { (void)(f263_ow(hr_str("hr_abort(", 9)));
(void)(f299_gas(f330_arg(((int64_t)0LL), &recv_1864, &n_1860)));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if (((b_1862) == (((int64_t)6LL)))) { (void)(f263_ow(hr_str("hr_exit(", 8)));
(void)(f297_gx(f330_arg(((int64_t)0LL), &recv_1864, &n_1860)));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if (((b_1862) == (((int64_t)8LL)))) { int64_t t_1898 = f141_at(n_1860); 
(void)(f263_ow(hr_str("({ ", 3)));
(void)(f264_ct(t_1898));
(void)(f263_ow(hr_str(" _d", 3)));
(void)(f302_oi(p_1867));
(void)(({ hrv *_o6286 = &(g163); hr_fs(_o6286, hr_str("; memset(&_d", 12)); hr_fi(_o6286, p_1867); hr_fs(_o6286, hr_str(", 0, sizeof _d", 14)); hr_fi(_o6286, p_1867); hr_fs(_o6286, hr_str("); _d", 5)); hr_fi(_o6286, p_1867); hr_fs(_o6286, hr_str("; })", 4)); }));
return;
 }
if (((b_1862) == (((int64_t)9LL)))) { int64_t c_1899 = f330_arg(((int64_t)0LL), &recv_1864, &n_1860); 
int64_t t_1900 = f182_deref(f284_fin(c_1899)); 
if (f287_is_fix(t_1900)) { (void)(({ hrv *_o6291 = &(g163); hr_fs(_o6291, hr_str("((int64_t)", 10)); hr_fi(_o6291, ((*({ hrv *_t6292 = &(g568); int64_t _i6292 = t_1900; (S1*)_t6292->b + hr_ix(_i6292, _t6292->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:698"); }))).b_); hr_fs(_o6291, hr_str(")", 1)); }));
return;
 }
(void)(f263_ow(hr_str("(", 1)));
(void)(f299_gas(c_1899));
(void)(f263_ow(hr_str(").n", 3)));
return;
 }
if (((b_1862) == (((int64_t)7LL)))) { int64_t c_1901 = f330_arg(((int64_t)0LL), &recv_1864, &n_1860); 
int64_t t_1902 = f182_deref(f284_fin(c_1901)); 
if ((((((*({ hrv *_t6299 = &(g568); int64_t _i6299 = t_1902; (S1*)_t6299->b + hr_ix(_i6299, _t6299->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:699"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t6300 = &(g568); int64_t _i6300 = t_1902; (S1*)_t6300->b + hr_ix(_i6300, _t6300->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:699"); }))).k_) == (((uint8_t)9LL))))) { (void)(f263_ow(hr_str("hr_rfrom(", 9)));
(void)(f299_gas(c_1901));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f335_esz(((int64_t)(((*({ hrv *_t6305 = &(g568); int64_t _i6305 = t_1902; (S1*)_t6305->b + hr_ix(_i6305, _t6305->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:699"); }))).a_))));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if (((f284_fin(c_1901)) != (t_1902))) { (void)(f263_ow(hr_str("(*", 2)));
(void)(f297_gx(c_1901));
(void)(f263_ow(hr_str(")", 1)));
 } else { (void)(f297_gx(c_1901));
 }
return;
 }
if (((b_1862) == (((int64_t)31LL)))) { int64_t c_1904 = f330_arg(((int64_t)0LL), &recv_1864, &n_1860); 
int64_t t_1905 = f182_deref(f284_fin(c_1904)); 
if ((((((*({ hrv *_t6315 = &(g568); int64_t _i6315 = t_1905; (S1*)_t6315->b + hr_ix(_i6315, _t6315->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:700"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t6316 = &(g568); int64_t _i6316 = t_1905; (S1*)_t6316->b + hr_ix(_i6316, _t6316->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:700"); }))).k_) == (((uint8_t)9LL))))) { int64_t q_1906 = f301_nt(); 
(void)(f263_ow(hr_str("({ hsl _s", 9)));
(void)(f302_oi(q_1906));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f299_gas(c_1904));
(void)(({ hrv *_o6322 = &(g163); hr_fs(_o6322, hr_str("; (hsl){ _s", 11)); hr_fi(_o6322, q_1906); hr_fs(_o6322, hr_str(".p, _s", 6)); hr_fi(_o6322, q_1906); hr_fs(_o6322, hr_str(".n * (int64_t)sizeof(", 21)); }));
(void)(f264_ct(((int64_t)(((*({ hrv *_t6324 = &(g568); int64_t _i6324 = t_1905; (S1*)_t6324->b + hr_ix(_i6324, _t6324->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:700"); }))).a_))));
(void)(f263_ow(hr_str(") }; })", 7)));
return;
 }
(void)(f263_ow(hr_str("((hsl){ (uint8_t*)", 18)));
(void)(f333_gaddr(c_1904));
(void)(f263_ow(hr_str(", sizeof(", 9)));
(void)(f264_ct(t_1905));
(void)(f263_ow(hr_str(") })", 4)));
return;
 }
if (((b_1862) == (((int64_t)30LL)))) { int64_t c_1907 = f330_arg(((int64_t)0LL), &recv_1864, &n_1860); 
int64_t t_1908 = f182_deref(f284_fin(c_1907)); 
(void)(f263_ow(hr_str("hr_rfrom(", 9)));
if ((((((*({ hrv *_t6335 = &(g568); int64_t _i6335 = t_1908; (S1*)_t6335->b + hr_ix(_i6335, _t6335->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:701"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t6336 = &(g568); int64_t _i6336 = t_1908; (S1*)_t6336->b + hr_ix(_i6336, _t6336->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:701"); }))).k_) == (((uint8_t)9LL))))) { int64_t q_1909 = f301_nt(); 
(void)(f263_ow(hr_str("({ hsl _s", 9)));
(void)(f302_oi(q_1909));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f299_gas(c_1907));
(void)(({ hrv *_o6342 = &(g163); hr_fs(_o6342, hr_str("; (hsl){ _s", 11)); hr_fi(_o6342, q_1909); hr_fs(_o6342, hr_str(".p, _s", 6)); hr_fi(_o6342, q_1909); hr_fs(_o6342, hr_str(".n * (int64_t)sizeof(", 21)); }));
(void)(f264_ct(((int64_t)(((*({ hrv *_t6344 = &(g568); int64_t _i6344 = t_1908; (S1*)_t6344->b + hr_ix(_i6344, _t6344->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:701"); }))).a_))));
(void)(f263_ow(hr_str(") }; })", 7)));
 } else { (void)(f263_ow(hr_str("((hsl){ (uint8_t*)", 18)));
(void)(f333_gaddr(c_1907));
(void)(f263_ow(hr_str(", sizeof(", 9)));
(void)(f264_ct(t_1908));
(void)(f263_ow(hr_str(") })", 4)));
 }
(void)(f263_ow(hr_str(", 1)", 4)));
return;
 }
if (((b_1862) == (((int64_t)33LL)))) { (void)(f336_gembed(n_1860, f330_arg(((int64_t)0LL), &recv_1864, &n_1860)));
return;
 }
if (((b_1862) == (((int64_t)32LL)))) { int64_t t_1918 = f141_at(n_1860); 
(void)(f263_ow(hr_str("({ hsl _s", 9)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f299_gas(f330_arg(((int64_t)0LL), &recv_1864, &n_1860)));
(void)(f263_ow(hr_str("; ", 2)));
(void)(f264_ct(t_1918));
(void)(({ hrv *_o6362 = &(g163); hr_fs(_o6362, hr_str(" _d", 3)); hr_fi(_o6362, p_1867); hr_fs(_o6362, hr_str("; if (_s", 8)); hr_fi(_o6362, p_1867); hr_fs(_o6362, hr_str(".n != sizeof _d", 15)); hr_fi(_o6362, p_1867); hr_fs(_o6362, hr_str(") hr_die(\"from_bytes: wrong byte count\", ", 41)); }));
(void)(f321_wloc(n_1860));
(void)(({ hrv *_o6364 = &(g163); hr_fs(_o6364, hr_str("); memcpy(&_d", 13)); hr_fi(_o6364, p_1867); hr_fs(_o6364, hr_str(", _s", 4)); hr_fi(_o6364, p_1867); hr_fs(_o6364, hr_str(".p, sizeof _d", 13)); hr_fi(_o6364, p_1867); hr_fs(_o6364, hr_str("); _d", 5)); hr_fi(_o6364, p_1867); hr_fs(_o6364, hr_str("; })", 4)); }));
return;
 }
if (((recv_1864) < (((int64_t)0LL)))) { (void)(f295_gerr(n_1860, hr_str("unsupported builtin call", 24)));
return;
 }
int64_t rt_1919 = f182_deref(f141_at(recv_1864)); 
int64_t e_1920 = ((int64_t)(((*({ hrv *_t6368 = &(g568); int64_t _i6368 = rt_1919; (S1*)_t6368->b + hr_ix(_i6368, _t6368->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:706"); }))).a_)); 
if (f288_is_lim(rt_1919)) { (void)(f263_ow(hr_str("({ ", 3)));
(void)(f264_ct(rt_1919));
(void)(f263_ow(hr_str(" *_v", 4)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f334_grecv_ptr(recv_1864));
(void)(f263_ow(hr_str("; ", 2)));
if (((b_1862) == (((int64_t)20LL)))) { (void)(f264_ct(e_1920));
(void)(f263_ow(hr_str(" _x", 3)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(f330_arg(((int64_t)1LL), &recv_1864, &n_1860)));
(void)(({ hrv *_o6383 = &(g163); hr_fs(_o6383, hr_str("; if (_v", 8)); hr_fi(_o6383, p_1867); hr_fs(_o6383, hr_str("->n >= ", 7)); hr_fi(_o6383, ((*({ hrv *_t6384 = &(g568); int64_t _i6384 = rt_1919; (S1*)_t6384->b + hr_ix(_i6384, _t6384->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:709"); }))).b_); hr_fs(_o6383, hr_str(") hr_die(\"push past a limited array's capacity\", ", 49)); }));
(void)(f321_wloc(n_1860));
(void)(({ hrv *_o6386 = &(g163); hr_fs(_o6386, hr_str("); _v", 5)); hr_fi(_o6386, p_1867); hr_fs(_o6386, hr_str("->e[_v", 6)); hr_fi(_o6386, p_1867); hr_fs(_o6386, hr_str("->n] = _x", 9)); hr_fi(_o6386, p_1867); hr_fs(_o6386, hr_str("; &_v", 5)); hr_fi(_o6386, p_1867); hr_fs(_o6386, hr_str("->e[_v", 6)); hr_fi(_o6386, p_1867); hr_fs(_o6386, hr_str("->n++]; })", 10)); }));
return;
 }
if (((b_1862) == (((int64_t)21LL)))) { (void)(({ hrv *_o6387 = &(g163); hr_fs(_o6387, hr_str("hsl _s", 6)); hr_fi(_o6387, p_1867); hr_fs(_o6387, hr_str(" = ", 3)); }));
(void)(f299_gas(f330_arg(((int64_t)1LL), &recv_1864, &n_1860)));
(void)(({ hrv *_o6390 = &(g163); hr_fs(_o6390, hr_str("; if (_v", 8)); hr_fi(_o6390, p_1867); hr_fs(_o6390, hr_str("->n + _s", 8)); hr_fi(_o6390, p_1867); hr_fs(_o6390, hr_str(".n > ", 5)); hr_fi(_o6390, ((*({ hrv *_t6391 = &(g568); int64_t _i6391 = rt_1919; (S1*)_t6391->b + hr_ix(_i6391, _t6391->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:710"); }))).b_); hr_fs(_o6390, hr_str(") hr_die(\"append past a limited array's capacity\", ", 51)); }));
(void)(f321_wloc(n_1860));
(void)(({ hrv *_o6393 = &(g163); hr_fs(_o6393, hr_str("); memmove(_v", 13)); hr_fi(_o6393, p_1867); hr_fs(_o6393, hr_str("->e + _v", 8)); hr_fi(_o6393, p_1867); hr_fs(_o6393, hr_str("->n, _s", 7)); hr_fi(_o6393, p_1867); hr_fs(_o6393, hr_str(".p, (size_t)_s", 14)); hr_fi(_o6393, p_1867); hr_fs(_o6393, hr_str(".n * sizeof _v", 14)); hr_fi(_o6393, p_1867); hr_fs(_o6393, hr_str("->e[0]); _v", 11)); hr_fi(_o6393, p_1867); hr_fs(_o6393, hr_str("->n += _s", 9)); hr_fi(_o6393, p_1867); hr_fs(_o6393, hr_str(".n; })", 6)); }));
return;
 }
if (((b_1862) == (((int64_t)22LL)))) { (void)(({ hrv *_o6394 = &(g163); hr_fs(_o6394, hr_str("if (!_v", 7)); hr_fi(_o6394, p_1867); hr_fs(_o6394, hr_str("->n) hr_die(\"pop of an empty array\", ", 37)); }));
(void)(f321_wloc(n_1860));
(void)(({ hrv *_o6396 = &(g163); hr_fs(_o6396, hr_str("); _v", 5)); hr_fi(_o6396, p_1867); hr_fs(_o6396, hr_str("->e[--_v", 8)); hr_fi(_o6396, p_1867); hr_fs(_o6396, hr_str("->n]; })", 8)); }));
return;
 }
if (((b_1862) == (((int64_t)23LL)))) { (void)(({ hrv *_o6397 = &(g163); hr_fs(_o6397, hr_str("int64_t _k", 10)); hr_fi(_o6397, p_1867); hr_fs(_o6397, hr_str(" = ", 3)); }));
(void)(f297_gx(f330_arg(((int64_t)1LL), &recv_1864, &n_1860)));
(void)(({ hrv *_o6400 = &(g163); hr_fs(_o6400, hr_str("; if (_k", 8)); hr_fi(_o6400, p_1867); hr_fs(_o6400, hr_str(" < 0 || _k", 10)); hr_fi(_o6400, p_1867); hr_fs(_o6400, hr_str(" > _v", 5)); hr_fi(_o6400, p_1867); hr_fs(_o6400, hr_str("->n) hr_die(\"pop_n past the length\", ", 37)); }));
(void)(f321_wloc(n_1860));
(void)(({ hrv *_o6402 = &(g163); hr_fs(_o6402, hr_str("); _v", 5)); hr_fi(_o6402, p_1867); hr_fs(_o6402, hr_str("->n -= _k", 9)); hr_fi(_o6402, p_1867); hr_fs(_o6402, hr_str("; })", 4)); }));
return;
 }
if (((b_1862) == (((int64_t)25LL)))) { (void)(({ hrv *_o6403 = &(g163); hr_fs(_o6403, hr_str("_v", 2)); hr_fi(_o6403, p_1867); hr_fs(_o6403, hr_str("->n = 0; })", 11)); }));
return;
 }
if (((b_1862) == (((int64_t)24LL)))) { (void)(({ hrv *_o6404 = &(g163); hr_fs(_o6404, hr_str("int64_t _k", 10)); hr_fi(_o6404, p_1867); hr_fs(_o6404, hr_str(" = ", 3)); }));
(void)(f297_gx(f330_arg(((int64_t)1LL), &recv_1864, &n_1860)));
(void)(({ hrv *_o6407 = &(g163); hr_fs(_o6407, hr_str("; if (_k", 8)); hr_fi(_o6407, p_1867); hr_fs(_o6407, hr_str(" < 0 || _k", 10)); hr_fi(_o6407, p_1867); hr_fs(_o6407, hr_str(" > ", 3)); hr_fi(_o6407, ((*({ hrv *_t6408 = &(g568); int64_t _i6408 = rt_1919; (S1*)_t6408->b + hr_ix(_i6408, _t6408->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:714"); }))).b_); hr_fs(_o6407, hr_str(") hr_die(\"resize past a limited array's capacity\", ", 51)); }));
(void)(f321_wloc(n_1860));
(void)(({ hrv *_o6410 = &(g163); hr_fs(_o6410, hr_str("); for (int64_t _j = _v", 23)); hr_fi(_o6410, p_1867); hr_fs(_o6410, hr_str("->n; _j < _k", 12)); hr_fi(_o6410, p_1867); hr_fs(_o6410, hr_str("; _j++) memset(&_v", 18)); hr_fi(_o6410, p_1867); hr_fs(_o6410, hr_str("->e[_j], 0, sizeof _v", 21)); hr_fi(_o6410, p_1867); hr_fs(_o6410, hr_str("->e[0]); ", 9)); }));
if (((total_1865) > (((int64_t)2LL)))) { (void)(({ hrv *_o6411 = &(g163); hr_fs(_o6411, hr_str("for (int64_t _j = _v", 20)); hr_fi(_o6411, p_1867); hr_fs(_o6411, hr_str("->n; _j < _k", 12)); hr_fi(_o6411, p_1867); hr_fs(_o6411, hr_str("; _j++) _v", 10)); hr_fi(_o6411, p_1867); hr_fs(_o6411, hr_str("->e[_j] = ", 10)); }));
(void)(f297_gx(f330_arg(((int64_t)2LL), &recv_1864, &n_1860)));
(void)(f263_ow(hr_str("; ", 2)));
 }
(void)(({ hrv *_o6415 = &(g163); hr_fs(_o6415, hr_str("_v", 2)); hr_fi(_o6415, p_1867); hr_fs(_o6415, hr_str("->n = _k", 8)); hr_fi(_o6415, p_1867); hr_fs(_o6415, hr_str("; })", 4)); }));
return;
 }
if (((b_1862) == (((int64_t)26LL)))) { (void)(f264_ct(e_1920));
(void)(f263_ow(hr_str(" _x", 3)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(f330_arg(((int64_t)1LL), &recv_1864, &n_1860)));
(void)(({ hrv *_o6422 = &(g163); hr_fs(_o6422, hr_str("; int64_t _r", 12)); hr_fi(_o6422, p_1867); hr_fs(_o6422, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6422, p_1867); hr_fs(_o6422, hr_str("->n; _j++) if (", 15)); }));
(void)(f337_heq_val_o(e_1920, p_1867));
(void)(({ hrv *_o6424 = &(g163); hr_fs(_o6424, hr_str(") { _r", 6)); hr_fi(_o6424, p_1867); hr_fs(_o6424, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6424, p_1867); hr_fs(_o6424, hr_str("; })", 4)); }));
return;
 }
(void)(f295_gerr(n_1860, hr_str("unsupported limited-array operation", 35)));
return;
 }
if ((((((*({ hrv *_t6426 = &(g568); int64_t _i6426 = rt_1919; (S1*)_t6426->b + hr_ix(_i6426, _t6426->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:718"); }))).k_) == (((uint8_t)9LL))) || f287_is_fix(rt_1919))) { if (((b_1862) == (((int64_t)26LL)))) { (void)(f263_ow(hr_str("({ hsl _v", 9)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f299_gas(recv_1864));
(void)(f263_ow(hr_str("; ", 2)));
(void)(f264_ct(e_1920));
(void)(f263_ow(hr_str(" _x", 3)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(f330_arg(((int64_t)1LL), &recv_1864, &n_1860)));
(void)(({ hrv *_o6439 = &(g163); hr_fs(_o6439, hr_str("; int64_t _r", 12)); hr_fi(_o6439, p_1867); hr_fs(_o6439, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6439, p_1867); hr_fs(_o6439, hr_str(".n; _j++) if (", 14)); }));
(void)(f341_heq_val_s(e_1920, p_1867));
(void)(({ hrv *_o6441 = &(g163); hr_fs(_o6441, hr_str(") { _r", 6)); hr_fi(_o6441, p_1867); hr_fs(_o6441, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6441, p_1867); hr_fs(_o6441, hr_str("; })", 4)); }));
return;
 }
(void)(f295_gerr(n_1860, hr_str("this operation needs a resizable array", 38)));
return;
 }
(void)(f263_ow(hr_str("({ hrv *_v", 10)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f334_grecv_ptr(recv_1864));
(void)(f263_ow(hr_str("; ", 2)));
if (((b_1862) == (((int64_t)20LL)))) { (void)(f264_ct(e_1920));
(void)(f263_ow(hr_str(" _x", 3)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(f330_arg(((int64_t)1LL), &recv_1864, &n_1860)));
(void)(f263_ow(hr_str("; ", 2)));
(void)(f264_ct(e_1920));
(void)(f263_ow(hr_str(" *_p", 4)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" = (", 4)));
(void)(f264_ct(e_1920));
(void)(({ hrv *_o6460 = &(g163); hr_fs(_o6460, hr_str("*)hr_grow(_v", 12)); hr_fi(_o6460, p_1867); hr_fs(_o6460, hr_str(", 1, sizeof _x", 14)); hr_fi(_o6460, p_1867); hr_fs(_o6460, hr_str("); *_p", 6)); hr_fi(_o6460, p_1867); hr_fs(_o6460, hr_str(" = _x", 5)); hr_fi(_o6460, p_1867); hr_fs(_o6460, hr_str("; _p", 4)); hr_fi(_o6460, p_1867); hr_fs(_o6460, hr_str("; })", 4)); }));
return;
 }
if (((b_1862) == (((int64_t)21LL)))) { (void)(({ hrv *_o6461 = &(g163); hr_fs(_o6461, hr_str("hsl _s", 6)); hr_fi(_o6461, p_1867); hr_fs(_o6461, hr_str(" = ", 3)); }));
(void)(f299_gas(f330_arg(((int64_t)1LL), &recv_1864, &n_1860)));
(void)(({ hrv *_o6464 = &(g163); hr_fs(_o6464, hr_str("; hr_append(_v", 14)); hr_fi(_o6464, p_1867); hr_fs(_o6464, hr_str(", _s", 4)); hr_fi(_o6464, p_1867); hr_fs(_o6464, hr_str(".p, _s", 6)); hr_fi(_o6464, p_1867); hr_fs(_o6464, hr_str(".n, sizeof(", 11)); }));
(void)(f264_ct(e_1920));
(void)(f263_ow(hr_str(")); })", 6)));
return;
 }
if (((b_1862) == (((int64_t)22LL)))) { (void)(({ hrv *_o6467 = &(g163); hr_fs(_o6467, hr_str("if (!_v", 7)); hr_fi(_o6467, p_1867); hr_fs(_o6467, hr_str("->n) hr_die(\"pop of an empty array\", ", 37)); }));
(void)(f321_wloc(n_1860));
(void)(({ hrv *_o6469 = &(g163); hr_fs(_o6469, hr_str("); ((", 5)); }));
(void)(f264_ct(e_1920));
(void)(({ hrv *_o6471 = &(g163); hr_fs(_o6471, hr_str("*)_v", 4)); hr_fi(_o6471, p_1867); hr_fs(_o6471, hr_str("->b)[--_v", 9)); hr_fi(_o6471, p_1867); hr_fs(_o6471, hr_str("->n]; })", 8)); }));
return;
 }
if (((b_1862) == (((int64_t)23LL)))) { (void)(({ hrv *_o6472 = &(g163); hr_fs(_o6472, hr_str("int64_t _k", 10)); hr_fi(_o6472, p_1867); hr_fs(_o6472, hr_str(" = ", 3)); }));
(void)(f297_gx(f330_arg(((int64_t)1LL), &recv_1864, &n_1860)));
(void)(({ hrv *_o6475 = &(g163); hr_fs(_o6475, hr_str("; if (_k", 8)); hr_fi(_o6475, p_1867); hr_fs(_o6475, hr_str(" < 0 || _k", 10)); hr_fi(_o6475, p_1867); hr_fs(_o6475, hr_str(" > _v", 5)); hr_fi(_o6475, p_1867); hr_fs(_o6475, hr_str("->n) hr_die(\"pop_n past the length\", ", 37)); }));
(void)(f321_wloc(n_1860));
(void)(({ hrv *_o6477 = &(g163); hr_fs(_o6477, hr_str("); _v", 5)); hr_fi(_o6477, p_1867); hr_fs(_o6477, hr_str("->n -= _k", 9)); hr_fi(_o6477, p_1867); hr_fs(_o6477, hr_str("; })", 4)); }));
return;
 }
if (((b_1862) == (((int64_t)25LL)))) { (void)(({ hrv *_o6478 = &(g163); hr_fs(_o6478, hr_str("_v", 2)); hr_fi(_o6478, p_1867); hr_fs(_o6478, hr_str("->n = 0; })", 11)); }));
return;
 }
if (((b_1862) == (((int64_t)24LL)))) { (void)(({ hrv *_o6479 = &(g163); hr_fs(_o6479, hr_str("int64_t _k", 10)); hr_fi(_o6479, p_1867); hr_fs(_o6479, hr_str(" = ", 3)); }));
(void)(f297_gx(f330_arg(((int64_t)1LL), &recv_1864, &n_1860)));
(void)(({ hrv *_o6482 = &(g163); hr_fs(_o6482, hr_str("; if (_k", 8)); hr_fi(_o6482, p_1867); hr_fs(_o6482, hr_str(" < 0) hr_die(\"resize to a negative length\", ", 44)); }));
(void)(f321_wloc(n_1860));
(void)(f263_ow(hr_str("); ", 3)));
if (((total_1865) > (((int64_t)2LL)))) { (void)(f264_ct(e_1920));
(void)(f263_ow(hr_str(" _x", 3)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(f330_arg(((int64_t)2LL), &recv_1864, &n_1860)));
(void)(({ hrv *_o6491 = &(g163); hr_fs(_o6491, hr_str("; int64_t _o", 12)); hr_fi(_o6491, p_1867); hr_fs(_o6491, hr_str(" = _v", 5)); hr_fi(_o6491, p_1867); hr_fs(_o6491, hr_str("->n; hr_resize(_v", 17)); hr_fi(_o6491, p_1867); hr_fs(_o6491, hr_str(", _k", 4)); hr_fi(_o6491, p_1867); hr_fs(_o6491, hr_str(", sizeof _x", 11)); hr_fi(_o6491, p_1867); hr_fs(_o6491, hr_str("); for (int64_t _j = _o", 23)); hr_fi(_o6491, p_1867); hr_fs(_o6491, hr_str("; _j < _k", 9)); hr_fi(_o6491, p_1867); hr_fs(_o6491, hr_str("; _j++) ((", 10)); }));
(void)(f264_ct(e_1920));
(void)(({ hrv *_o6493 = &(g163); hr_fs(_o6493, hr_str("*)_v", 4)); hr_fi(_o6493, p_1867); hr_fs(_o6493, hr_str("->b)[_j] = _x", 13)); hr_fi(_o6493, p_1867); hr_fs(_o6493, hr_str("; })", 4)); }));
return;
 }
(void)(({ hrv *_o6494 = &(g163); hr_fs(_o6494, hr_str("hr_resize(_v", 12)); hr_fi(_o6494, p_1867); hr_fs(_o6494, hr_str(", _k", 4)); hr_fi(_o6494, p_1867); hr_fs(_o6494, hr_str(", sizeof(", 9)); }));
(void)(f264_ct(e_1920));
(void)(f263_ow(hr_str(")); })", 6)));
return;
 }
if (((b_1862) == (((int64_t)26LL)))) { (void)(f264_ct(e_1920));
(void)(f263_ow(hr_str(" _x", 3)));
(void)(f302_oi(p_1867));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(f330_arg(((int64_t)1LL), &recv_1864, &n_1860)));
(void)(({ hrv *_o6503 = &(g163); hr_fs(_o6503, hr_str("; int64_t _r", 12)); hr_fi(_o6503, p_1867); hr_fs(_o6503, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6503, p_1867); hr_fs(_o6503, hr_str("->n; _j++) if (", 15)); }));
(void)(f342_heq_val_r(e_1920, p_1867));
(void)(({ hrv *_o6505 = &(g163); hr_fs(_o6505, hr_str(") { _r", 6)); hr_fi(_o6505, p_1867); hr_fs(_o6505, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6505, p_1867); hr_fs(_o6505, hr_str("; })", 4)); }));
return;
 }
(void)(f295_gerr(n_1860, hr_str("unsupported array operation", 27)));
}
static int64_t f330_arg(int64_t i_1866, int64_t *c1864, int64_t *c1860) {
return ({ int64_t _r6507; if ((((*c1864)) >= (((int64_t)0LL)))) { _r6507 = ({ int64_t _r6508; if (((i_1866) == (((int64_t)0LL)))) { _r6508 = (*c1864);  } else { _r6508 = f90_kid((*c1860), ((int64_t)((int64_t)i_1866 - (int64_t)((int64_t)1LL))));  } _r6508; });  } else { _r6507 = f90_kid((*c1860), i_1866);  } _r6507; });
}
static void f331_gfmt(hsl o_1870, int64_t n_1871, int64_t t_1872, bool top_1873) {
int64_t d_1874 = f182_deref(t_1872); 
int64_t k_1875 = ((int64_t)(((*({ hrv *_t6512 = &(g568); int64_t _i6512 = d_1874; (S1*)_t6512->b + hr_ix(_i6512, _t6512->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:398"); }))).k_)); 
int64_t hk_1876 = ({ int64_t _r6513; if (((d_1874) < ((g361).n))) { _r6513 = ((int64_t)((*({ hrv *_t6514 = &(g361); int64_t _i6514 = d_1874; (int32_t*)_t6514->b + hr_ix(_i6514, _t6514->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:399"); }))));  } else { _r6513 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r6513; }); 
if ((((hk_1876) >= (((int64_t)0LL))) && ((f182_deref(f213_ptype_of(hk_1876, ((int64_t)1LL)))) == (d_1874)))) { int64_t pt_1877 = f213_ptype_of(hk_1876, ((int64_t)1LL)); 
(void)(f332_fn_cname(hk_1876));
(void)(f263_ow(hr_str("(", 1)));
(void)(f263_ow(o_1870));
(void)(f263_ow(hr_str(", ", 2)));
if (((((*({ hrv *_t6522 = &(g568); int64_t _i6522 = pt_1877; (S1*)_t6522->b + hr_ix(_i6522, _t6522->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).k_) == (((uint8_t)10LL)))) { if (((((*({ hrv *_t6523 = &(g568); int64_t _i6523 = t_1872; (S1*)_t6523->b + hr_ix(_i6523, _t6523->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).k_) == (((uint8_t)10LL)))) { (void)(f297_gx(n_1871));
 } else { (void)(f333_gaddr(n_1871));
 }
 } else { if (((((*({ hrv *_t6526 = &(g568); int64_t _i6526 = t_1872; (S1*)_t6526->b + hr_ix(_i6526, _t6526->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:403"); }))).k_) == (((uint8_t)10LL)))) { (void)(f263_ow(hr_str("*", 1)));
 }
(void)(f297_gx(n_1871));
 }
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if ((((k_1875) == (((int64_t)18LL))) || f167_is_byte_arr(d_1874))) { if (top_1873) { (void)(f263_ow(hr_str("hr_fs(", 6)));
 } else { (void)(f263_ow(hr_str("hr_fq(", 6)));
 }
(void)(f263_ow(o_1870));
(void)(f263_ow(hr_str(", ", 2)));
if (((((*({ hrv *_t6535 = &(g568); int64_t _i6535 = f141_at(n_1871); (S1*)_t6535->b + hr_ix(_i6535, _t6535->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:407"); }))).k_) == (((uint8_t)18LL)))) { (void)(f297_gx(n_1871));
 } else { (void)(f299_gas(n_1871));
 }
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if (((k_1875) == (((int64_t)3LL)))) { (void)(f263_ow(({ hsl _r6541; if (f156_is_signed(d_1874)) { _r6541 = hr_str("hr_fi(", 6);  } else { _r6541 = hr_str("hr_fu(", 6);  } _r6541; })));
(void)(f263_ow(o_1870));
(void)(f263_ow(hr_str(", ", 2)));
if (((d_1874) != (t_1872))) { (void)(f263_ow(hr_str("*", 1)));
 }
(void)(f297_gx(n_1871));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if (((k_1875) == (((int64_t)12LL)))) { (void)(f263_ow(hr_str("hr_fi(", 6)));
(void)(f263_ow(o_1870));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f297_gx(n_1871));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if (((k_1875) == (((int64_t)4LL)))) { (void)(f263_ow(({ hsl _r6554; if (((((*({ hrv *_t6555 = &(g568); int64_t _i6555 = d_1874; (S1*)_t6555->b + hr_ix(_i6555, _t6555->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:410"); }))).s_) == (((uint8_t)4LL)))) { _r6554 = hr_str("hr_ff(", 6);  } else { _r6554 = hr_str("hr_fd(", 6);  } _r6554; })));
(void)(f263_ow(o_1870));
(void)(f263_ow(hr_str(", ", 2)));
if (((d_1874) != (t_1872))) { (void)(f263_ow(hr_str("*", 1)));
 }
(void)(f297_gx(n_1871));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if (((k_1875) == (((int64_t)13LL)))) { (void)(f263_ow(hr_str("hr_fd(", 6)));
(void)(f263_ow(o_1870));
(void)(f263_ow(hr_str(", ", 2)));
(void)(f297_gx(n_1871));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
if (((k_1875) == (((int64_t)2LL)))) { (void)(f263_ow(hr_str("hr_fc(", 6)));
(void)(f263_ow(o_1870));
(void)(f263_ow(hr_str(", (", 3)));
if (((d_1874) != (t_1872))) { (void)(f263_ow(hr_str("*", 1)));
 }
(void)(f297_gx(n_1871));
(void)(f263_ow(hr_str(") \077 \"true\" : \"false\")", 21)));
return;
 }
(void)(f263_ow(hr_str("hf", 2)));
(void)(f302_oi(d_1874));
(void)(f263_ow(hr_str("(", 1)));
(void)(f263_ow(o_1870));
(void)(f263_ow(hr_str(", ", 2)));
if (((d_1874) != (t_1872))) { (void)(f263_ow(hr_str("*", 1)));
 }
if ((((((k_1875) == (((int64_t)8LL))) && (!(f287_is_fix(d_1874)))) && (!(f288_is_lim(d_1874)))) || ((k_1875) == (((int64_t)9LL))))) { (void)(f300_gsl(n_1871, t_1872));
 } else { (void)(f297_gx(n_1871));
 }
(void)(f263_ow(hr_str(")", 1)));
(void)(f308_gen_hf(d_1874));
}
static void f332_fn_cname(int64_t i_1878) {
(void)(f311_fn_cname_to((&(g163)), i_1878));
}
static void f333_gaddr(int64_t n_1879) {
if (f275_is_place(n_1879)) { (void)(f263_ow(hr_str("(&(", 3)));
(void)(f280_gx0(n_1879));
(void)(f263_ow(hr_str("))", 2)));
return;
 }
int64_t t_1880 = f141_at(n_1879); 
int64_t c_1881 = f153_cv(n_1879); 
if (((((c_1881) >= (((int64_t)0LL))) && ((((*({ hrv *_t6591 = &(g568); int64_t _i6591 = c_1881; (S1*)_t6591->b + hr_ix(_i6591, _t6591->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:173"); }))).k_) == (((uint8_t)10LL)))) && ((((*({ hrv *_t6592 = &(g568); int64_t _i6592 = t_1880; (S1*)_t6592->b + hr_ix(_i6592, _t6592->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:173"); }))).k_) != (((uint8_t)10LL))))) { int64_t pt_1882 = ((int64_t)(((*({ hrv *_t6593 = &(g568); int64_t _i6593 = c_1881; (S1*)_t6593->b + hr_ix(_i6593, _t6593->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:174"); }))).a_)); 
int64_t k_1883 = f278_tmp(pt_1882, f271_is_res(pt_1882)); 
(void)(f263_ow(hr_str("(", 1)));
(void)(f279_ot(k_1883));
(void)(f263_ow(hr_str(" = (", 4)));
if (((pt_1882) == (t_1880))) { if (f271_is_res(t_1880)) { (void)(f280_gx0(n_1879));
 } else { (void)(f274_gx1(n_1879));
 }
 } else { (void)(f273_gcv(n_1879, t_1880, pt_1882));
 }
(void)(f263_ow(hr_str("), &", 4)));
(void)(f279_ot(k_1883));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
int64_t k_1884 = f278_tmp(t_1880, f271_is_res(t_1880)); 
(void)(f263_ow(hr_str("(", 1)));
(void)(f279_ot(k_1884));
(void)(f263_ow(hr_str(" = (", 4)));
(void)(f272_gxo(n_1879));
(void)(f263_ow(hr_str("), &", 4)));
(void)(f279_ot(k_1884));
(void)(f263_ow(hr_str(")", 1)));
}
static void f334_grecv_ptr(int64_t r_1889) {
int64_t t_1890 = f141_at(r_1889); 
if (((((*({ hrv *_t6616 = &(g568); int64_t _i6616 = t_1890; (S1*)_t6616->b + hr_ix(_i6616, _t6616->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:671"); }))).k_) == (((uint8_t)10LL)))) { (void)(f280_gx0(r_1889));
return;
 }
if (f275_is_place(r_1889)) { (void)(f263_ow(hr_str("&(", 2)));
(void)(f280_gx0(r_1889));
(void)(f263_ow(hr_str(")", 1)));
return;
 }
int64_t k_1891 = f278_tmp(t_1890, f271_is_res(t_1890)); 
(void)(f263_ow(hr_str("(", 1)));
(void)(f279_ot(k_1891));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f272_gxo(r_1889));
(void)(f263_ow(hr_str(", &", 3)));
(void)(f279_ot(k_1891));
(void)(f263_ow(hr_str(")", 1)));
}
static void f335_esz(int64_t t_1903) {
(void)(f263_ow(hr_str("sizeof(", 7)));
(void)(f264_ct(t_1903));
(void)(f263_ow(hr_str(")", 1)));
}
static void f336_gembed(int64_t n_1910, int64_t a_1911) {
if (((((*({ hrv *_t6634 = &(g721); int64_t _i6634 = a_1911; (S4*)_t6634->b + hr_ix(_i6634, _t6634->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:737"); }))).k_) != (((uint8_t)3LL)))) { (void)(f295_gerr(n_1910, hr_str("embed_file needs a string literal path", 38)));
return;
 }
int64_t f_1912 = ((int64_t)(((*({ hrv *_t6636 = &(g930); int64_t _i6636 = ((*({ hrv *_t6637 = &(g931); int64_t _i6637 = ((*({ hrv *_t6638 = &(g721); int64_t _i6638 = n_1910; (S4*)_t6638->b + hr_ix(_i6638, _t6638->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:738"); }))).t_; (S3*)_t6637->b + hr_ix(_i6637, _t6637->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:738"); }))).f_; (S2*)_t6636->b + hr_ix(_i6636, _t6636->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:738"); }))).name_)); 
L103 p_1913 = ({ L103 _t6639; memset(&_t6639, 0, sizeof _t6639); _t6639.n = 0; _t6639; }); 
int64_t sl_1914 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hsl _v6641 = f10_nm(f_1912); for (int64_t _k6641 = 0; _k6641 < _v6641.n; _k6641++) { uint8_t c_1915 = ((uint8_t*)_v6641.p)[_k6641]; int64_t i_1916 = (int64_t)_k6641; if (((c_1915) == (((uint8_t)47LL)))) { sl_1914 = i_1916;
 }
 } } _bk6640:; 
if (((sl_1914) >= (((int64_t)0LL)))) { (void)(({ L103 *_v6643 = &(p_1913); hsl _s6643 = ({ hsl _t6644 = f10_nm(f_1912); int64_t _l6644 = 0, _h6644 = ((int64_t)((int64_t)sl_1914 + (int64_t)((int64_t)1LL))); if (_l6644 < 0 || _h6644 < _l6644 || _h6644 > _t6644.n) hr_slerr(_l6644, _h6644, _t6644.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:742"); (hsl){ _t6644.p + _l6644 * (int64_t)sizeof(uint8_t), _h6644 - _l6644 }; }); if (_v6643->n + _s6643.n > 4096) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:742"); memmove(_v6643->e + _v6643->n, _s6643.p, (size_t)_s6643.n * sizeof _v6643->e[0]); _v6643->n += _s6643.n; }));
 }
(void)(({ L103 *_v6646 = &(p_1913); hsl _s6646 = f285_tok_str(((int64_t)(((*({ hrv *_t6648 = &(g721); int64_t _i6648 = a_1911; (S4*)_t6648->b + hr_ix(_i6648, _t6648->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:743"); }))).t_))); if (_v6646->n + _s6646.n > 4096) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:743"); memmove(_v6646->e + _v6646->n, _s6646.p, (size_t)_s6646.n * sizeof _v6646->e[0]); _v6646->n += _s6646.n; }));
hrv emb_1917 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(hr_os_read_file(({ hsl _t6651 = ({ L103 *_t6652 = &(p_1913); (hsl){ (uint8_t*)_t6652->e, _t6652->n }; }); int64_t _l6651 = 0, _h6651 = _t6651.n; if (_l6651 < 0 || _h6651 < _l6651 || _h6651 > _t6651.n) hr_slerr(_l6651, _h6651, _t6651.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:745"); (hsl){ _t6651.p + _l6651 * (int64_t)sizeof(uint8_t), _h6651 - _l6651 }; }), (&(emb_1917)))))) { (void)(f295_gerr(n_1910, hr_str("embed_file cannot read its file", 31)));
return;
 }
(void)(f263_ow(hr_str("hr_str(", 7)));
(void)(f286_cstr_lit(({ hsl _t6656 = hr_sl(emb_1917); int64_t _l6656 = 0, _h6656 = _t6656.n; if (_l6656 < 0 || _h6656 < _l6656 || _h6656 > _t6656.n) hr_slerr(_l6656, _h6656, _t6656.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:746"); (hsl){ _t6656.p + _l6656 * (int64_t)sizeof(uint8_t), _h6656 - _l6656 }; })));
(void)(({ hrv *_o6657 = &(g163); hr_fs(_o6657, hr_str(", ", 2)); hr_fi(_o6657, (emb_1917).n); hr_fs(_o6657, hr_str(")", 1)); }));
}
static void f337_heq_val_o(int64_t e_1921, int64_t p_1922) {
L102 a_1923 = ({ L102 _t6658; memset(&_t6658, 0, sizeof _t6658); _t6658.n = 0; _t6658; }); 
L102 b_1924 = ({ L102 _t6659; memset(&_t6659, 0, sizeof _t6659); _t6659.n = 0; _t6659; }); 
(void)(({ L102 *_l6660 = &(a_1923); hrv _o6660 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6660, hr_str("_v", 2)); hr_fi(&_o6660, p_1922); hr_fs(&_o6660, hr_str("->e[_j]", 7)); if (_l6660->n + _o6660.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:751"); memcpy(_l6660->e + _l6660->n, _o6660.b, (size_t)_o6660.n); _l6660->n += _o6660.n; }));
(void)(({ L102 *_l6661 = &(b_1924); hrv _o6661 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6661, hr_str("_x", 2)); hr_fi(&_o6661, p_1922); if (_l6661->n + _o6661.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:751"); memcpy(_l6661->e + _l6661->n, _o6661.b, (size_t)_o6661.n); _l6661->n += _o6661.n; }));
(void)(f338_heq_o(e_1921, ({ hsl _t6663 = ({ L102 *_t6664 = &(a_1923); (hsl){ (uint8_t*)_t6664->e, _t6664->n }; }); int64_t _l6663 = 0, _h6663 = _t6663.n; if (_l6663 < 0 || _h6663 < _l6663 || _h6663 > _t6663.n) hr_slerr(_l6663, _h6663, _t6663.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:751"); (hsl){ _t6663.p + _l6663 * (int64_t)sizeof(uint8_t), _h6663 - _l6663 }; }), ({ hsl _t6665 = ({ L102 *_t6666 = &(b_1924); (hsl){ (uint8_t*)_t6666->e, _t6666->n }; }); int64_t _l6665 = 0, _h6665 = _t6665.n; if (_l6665 < 0 || _h6665 < _l6665 || _h6665 > _t6665.n) hr_slerr(_l6665, _h6665, _t6665.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:751"); (hsl){ _t6665.p + _l6665 * (int64_t)sizeof(uint8_t), _h6665 - _l6665 }; })));
}
static void f338_heq_o(int64_t e_1925, hsl a_1926, hsl b_1927) {
(void)(f339_heq_pre(e_1925));
int64_t s0_1931 = (g169).n; 
(void)(f313_heq_val(e_1925, a_1926, b_1927));
(void)(({ hrv *_v6669 = &(g163); hsl _s6669 = ({ hsl _t6670 = hr_sl(g169); int64_t _l6670 = s0_1931, _h6670 = _t6670.n; if (_l6670 < 0 || _h6670 < _l6670 || _h6670 > _t6670.n) hr_slerr(_l6670, _h6670, _t6670.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:748"); (hsl){ _t6670.p + _l6670 * (int64_t)sizeof(uint8_t), _h6670 - _l6670 }; }); hr_append(_v6669, _s6669.p, _s6669.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6671 = &(g169); int64_t _k6671 = s0_1931; if (_k6671 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:748"); hr_resize(_v6671, _k6671, sizeof(uint8_t)); }));
}
static void f339_heq_pre(int64_t t_1928) {
if ((!(f340_scalar_ty(t_1928)))) { (void)(f304_gen_heq(t_1928));
 }
}
static bool f340_scalar_ty(int64_t t_1929) {
int64_t k_1930 = ((int64_t)(((*({ hrv *_t6674 = &(g568); int64_t _i6674 = t_1929; (S1*)_t6674->b + hr_ix(_i6674, _t6674->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:749"); }))).k_)); 
return (((((k_1930) == (((int64_t)3LL))) || ((k_1930) == (((int64_t)4LL)))) || ((k_1930) == (((int64_t)2LL)))) || ((k_1930) == (((int64_t)10LL))));
}
static void f341_heq_val_s(int64_t e_1932, int64_t p_1933) {
L100 a_1934 = ({ L100 _t6675; memset(&_t6675, 0, sizeof _t6675); _t6675.n = 0; _t6675; }); 
L102 b_1935 = ({ L102 _t6676; memset(&_t6676, 0, sizeof _t6676); _t6676.n = 0; _t6676; }); 
(void)(({ L100 *_v6677 = &(a_1934); hsl _s6677 = hr_str("((", 2); if (_v6677->n + _s6677.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); memmove(_v6677->e + _v6677->n, _s6677.p, (size_t)_s6677.n * sizeof _v6677->e[0]); _v6677->n += _s6677.n; }));
(void)(({ L100 *_v6678 = &(a_1934); hsl _s6678 = f267_cn(e_1932); if (_v6678->n + _s6678.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); memmove(_v6678->e + _v6678->n, _s6678.p, (size_t)_s6678.n * sizeof _v6678->e[0]); _v6678->n += _s6678.n; }));
(void)(({ L100 *_l6680 = &(a_1934); hrv _o6680 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6680, hr_str("*)_v", 4)); hr_fi(&_o6680, p_1933); hr_fs(&_o6680, hr_str(".p)[_j]", 7)); if (_l6680->n + _o6680.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); memcpy(_l6680->e + _l6680->n, _o6680.b, (size_t)_o6680.n); _l6680->n += _o6680.n; }));
(void)(({ L102 *_l6681 = &(b_1935); hrv _o6681 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6681, hr_str("_x", 2)); hr_fi(&_o6681, p_1933); if (_l6681->n + _o6681.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); memcpy(_l6681->e + _l6681->n, _o6681.b, (size_t)_o6681.n); _l6681->n += _o6681.n; }));
(void)(f338_heq_o(e_1932, ({ hsl _t6683 = ({ L100 *_t6684 = &(a_1934); (hsl){ (uint8_t*)_t6684->e, _t6684->n }; }); int64_t _l6683 = 0, _h6683 = _t6683.n; if (_l6683 < 0 || _h6683 < _l6683 || _h6683 > _t6683.n) hr_slerr(_l6683, _h6683, _t6683.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); (hsl){ _t6683.p + _l6683 * (int64_t)sizeof(uint8_t), _h6683 - _l6683 }; }), ({ hsl _t6685 = ({ L102 *_t6686 = &(b_1935); (hsl){ (uint8_t*)_t6686->e, _t6686->n }; }); int64_t _l6685 = 0, _h6685 = _t6685.n; if (_l6685 < 0 || _h6685 < _l6685 || _h6685 > _t6685.n) hr_slerr(_l6685, _h6685, _t6685.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:752"); (hsl){ _t6685.p + _l6685 * (int64_t)sizeof(uint8_t), _h6685 - _l6685 }; })));
}
static void f342_heq_val_r(int64_t e_1936, int64_t p_1937) {
L100 a_1938 = ({ L100 _t6687; memset(&_t6687, 0, sizeof _t6687); _t6687.n = 0; _t6687; }); 
L102 b_1939 = ({ L102 _t6688; memset(&_t6688, 0, sizeof _t6688); _t6688.n = 0; _t6688; }); 
(void)(({ L100 *_v6689 = &(a_1938); hsl _s6689 = hr_str("((", 2); if (_v6689->n + _s6689.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:753"); memmove(_v6689->e + _v6689->n, _s6689.p, (size_t)_s6689.n * sizeof _v6689->e[0]); _v6689->n += _s6689.n; }));
(void)(({ L100 *_v6690 = &(a_1938); hsl _s6690 = f267_cn(e_1936); if (_v6690->n + _s6690.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:753"); memmove(_v6690->e + _v6690->n, _s6690.p, (size_t)_s6690.n * sizeof _v6690->e[0]); _v6690->n += _s6690.n; }));
(void)(({ L100 *_l6692 = &(a_1938); hrv _o6692 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6692, hr_str("*)_v", 4)); hr_fi(&_o6692, p_1937); hr_fs(&_o6692, hr_str("->b)[_j]", 8)); if (_l6692->n + _o6692.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:753"); memcpy(_l6692->e + _l6692->n, _o6692.b, (size_t)_o6692.n); _l6692->n += _o6692.n; }));
(void)(({ L102 *_l6693 = &(b_1939); hrv _o6693 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6693, hr_str("_x", 2)); hr_fi(&_o6693, p_1937); if (_l6693->n + _o6693.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:753"); memcpy(_l6693->e + _l6693->n, _o6693.b, (size_t)_o6693.n); _l6693->n += _o6693.n; }));
(void)(f338_heq_o(e_1936, ({ hsl _t6695 = ({ L100 *_t6696 = &(a_1938); (hsl){ (uint8_t*)_t6696->e, _t6696->n }; }); int64_t _l6695 = 0, _h6695 = _t6695.n; if (_l6695 < 0 || _h6695 < _l6695 || _h6695 > _t6695.n) hr_slerr(_l6695, _h6695, _t6695.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:753"); (hsl){ _t6695.p + _l6695 * (int64_t)sizeof(uint8_t), _h6695 - _l6695 }; }), ({ hsl _t6697 = ({ L102 *_t6698 = &(b_1939); (hsl){ (uint8_t*)_t6698->e, _t6698->n }; }); int64_t _l6697 = 0, _h6697 = _t6697.n; if (_l6697 < 0 || _h6697 < _l6697 || _h6697 > _t6697.n) hr_slerr(_l6697, _h6697, _t6697.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:753"); (hsl){ _t6697.p + _l6697 * (int64_t)sizeof(uint8_t), _h6697 - _l6697 }; })));
}
static void f343_gblkcall(int64_t n_1940) {
int64_t bi_1941 = f160_rv(n_1940); 
int64_t fv_1942 = ((int64_t)(((*({ hrv *_t6700 = &(g401); int64_t _i6700 = bi_1941; (S6*)_t6700->b + hr_ix(_i6700, _t6700->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:651"); }))).node_)); 
int64_t sa_1943 = g414; 
(void)(f263_ow(hr_str("({ ", 3)));
int64_t np_1944 = ((int64_t)(((*({ hrv *_t6702 = &(g721); int64_t _i6702 = fv_1942; (S4*)_t6702->b + hr_ix(_i6702, _t6702->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:654"); }))).n_)); 
int64_t na_1945 = ((int64_t)(((*({ hrv *_t6703 = &(g721); int64_t _i6703 = n_1940; (S4*)_t6703->b + hr_ix(_i6703, _t6703->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:655"); }))).n_)); 
if (((((uint16_t)((uint64_t)((*({ hrv *_t6704 = &(g721); int64_t _i6704 = fv_1942; (S4*)_t6704->b + hr_ix(_i6704, _t6704->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:656"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { int64_t _e6706 = np_1944; for (int64_t _k6706 = 0; _k6706 < _e6706; _k6706++) { int64_t j_1946 = (int64_t)_k6706; int64_t p_1947 = f90_kid(fv_1942, j_1946); 
g414 = bi_1941;
int64_t v_1948 = f160_rv(p_1947); 
g414 = sa_1943;
if (((j_1946) < (na_1945))) { (void)(f264_ct(((int64_t)(((*({ hrv *_t6710 = &(g402); int64_t _i6710 = v_1948; (S12*)_t6710->b + hr_ix(_i6710, _t6710->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:657"); }))).ty_))));
(void)(f263_ow(hr_str(" ", 1)));
(void)(f294_lv_name(v_1948));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f315_gxas(f90_kid(n_1940, j_1946), ((int64_t)(((*({ hrv *_t6716 = &(g402); int64_t _i6716 = v_1948; (S12*)_t6716->b + hr_ix(_i6716, _t6716->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:657"); }))).ty_))));
(void)(f263_ow(hr_str("; ", 2)));
 }
 } } _bk6705:; 
 } else { if (((na_1945) >= (((int64_t)1LL)))) { g414 = bi_1941;
int64_t v_1949 = f160_rv(fv_1942); 
g414 = sa_1943;
if (((v_1949) >= (((int64_t)0LL)))) { (void)(f264_ct(((int64_t)(((*({ hrv *_t6720 = &(g402); int64_t _i6720 = v_1949; (S12*)_t6720->b + hr_ix(_i6720, _t6720->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:659"); }))).ty_))));
(void)(f263_ow(hr_str(" ", 1)));
(void)(f294_lv_name(v_1949));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f315_gxas(f90_kid(n_1940, ((int64_t)0LL)), ((int64_t)(((*({ hrv *_t6726 = &(g402); int64_t _i6726 = v_1949; (S12*)_t6726->b + hr_ix(_i6726, _t6726->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:659"); }))).ty_))));
(void)(f263_ow(hr_str("; ", 2)));
 } else { (void)(f263_ow(hr_str("(void)(", 7)));
(void)(f297_gx(f90_kid(n_1940, ((int64_t)0LL))));
(void)(f263_ow(hr_str("); ", 3)));
 }
 }
 }
g414 = bi_1941;
int64_t body_1950 = ((int64_t)(((*({ hrv *_t6732 = &(g721); int64_t _i6732 = fv_1942; (S4*)_t6732->b + hr_ix(_i6732, _t6732->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:662"); }))).a_)); 
{ int32_t _e6734 = ((*({ hrv *_t6735 = &(g721); int64_t _i6735 = body_1950; (S4*)_t6735->b + hr_ix(_i6735, _t6735->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:663"); }))).n_; for (int32_t _k6734 = 0; _k6734 < _e6734; _k6734++) { int32_t i_1951 = (int32_t)_k6734; (void)(f344_gstmt(f90_kid(body_1950, ((int64_t)(i_1951)))));
 } } _bk6733:; 
int64_t tl_2098 = ((int64_t)(((*({ hrv *_t6738 = &(g721); int64_t _i6738 = body_1950; (S4*)_t6738->b + hr_ix(_i6738, _t6738->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:664"); }))).a_)); 
if (((tl_2098) >= (((int64_t)0LL)))) { if ((((((int64_t)(((*({ hrv *_t6739 = &(g401); int64_t _i6739 = bi_1941; (S6*)_t6739->b + hr_ix(_i6739, _t6739->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:665"); }))).ret_))) != (g575)) && (!(f143_ends(tl_2098))))) { (void)(f297_gx(tl_2098));
(void)(f263_ow(hr_str("; ", 2)));
 } else { (void)(f344_gstmt(tl_2098));
 }
 }
g414 = sa_1943;
(void)(f263_ow(hr_str(" })", 3)));
}
static void f344_gstmt(int64_t n_1952) {
if (((n_1952) < (((int64_t)0LL)))) { return;
 }
int64_t sp_1953 = (g163).n; 
int64_t td_1954 = (g176).n; 
S4 x_1955 = (*({ hrv *_t6745 = &(g721); int64_t _i6745 = n_1952; (S4*)_t6745->b + hr_ix(_i6745, _t6745->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1103"); })); 
int64_t k_1956 = ((int64_t)((x_1955).k_)); 
bool decl_1957 = ((k_1956) == (((int64_t)33LL))); 
if (((k_1956) == (((int64_t)33LL)))) { (void)(f345_gvdecl(n_1952));
 } else { (void)(f347_gstmt1(n_1952));
 }
(void)(f263_ow(hr_str("\012", 1)));
if ((((g176).n) > (td_1954))) { (void)(({ hrv *_v6749 = &(g177); _v6749->n = 0; }));
(void)(({ hrv *_v6750 = &(g177); hsl _s6750 = ({ hsl _t6751 = hr_sl(g163); int64_t _l6751 = sp_1953, _h6751 = _t6751.n; if (_l6751 < 0 || _h6751 < _l6751 || _h6751 > _t6751.n) hr_slerr(_l6751, _h6751, _t6751.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1109"); (hsl){ _t6751.p + _l6751 * (int64_t)sizeof(uint8_t), _h6751 - _l6751 }; }); hr_append(_v6750, _s6750.p, _s6750.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6752 = &(g163); int64_t _k6752 = sp_1953; if (_k6752 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1109"); hr_resize(_v6752, _k6752, sizeof(uint8_t)); }));
if ((!(decl_1957))) { (void)(f263_ow(hr_str("{ ", 2)));
 }
(void)(({ hrv *_v6754 = &(g163); hsl _s6754 = ({ hsl _t6755 = hr_sl(g176); int64_t _l6755 = td_1954, _h6755 = _t6755.n; if (_l6755 < 0 || _h6755 < _l6755 || _h6755 > _t6755.n) hr_slerr(_l6755, _h6755, _t6755.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1111"); (hsl){ _t6755.p + _l6755 * (int64_t)sizeof(uint8_t), _h6755 - _l6755 }; }); hr_append(_v6754, _s6754.p, _s6754.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6756 = &(g176); int64_t _k6756 = td_1954; if (_k6756 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1111"); hr_resize(_v6756, _k6756, sizeof(uint8_t)); }));
(void)(({ hrv *_v6757 = &(g163); hsl _s6757 = ({ hsl _t6758 = hr_sl(g177); int64_t _l6758 = 0, _h6758 = _t6758.n; if (_l6758 < 0 || _h6758 < _l6758 || _h6758 > _t6758.n) hr_slerr(_l6758, _h6758, _t6758.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1112"); (hsl){ _t6758.p + _l6758 * (int64_t)sizeof(uint8_t), _h6758 - _l6758 }; }); hr_append(_v6757, _s6757.p, _s6757.n, sizeof(uint8_t)); }));
if ((!(decl_1957))) { (void)(f263_ow(hr_str("}\012", 2)));
 }
 }
}
static void f345_gvdecl(int64_t n_1958) {
S4 x_1959 = (*({ hrv *_t6760 = &(g721); int64_t _i6760 = n_1958; (S4*)_t6760->b + hr_ix(_i6760, _t6760->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:967"); })); 
if ((((x_1959).n_) > (((int32_t)1LL)))) { if (((f220_ax(n_1958)) == (((int64_t)1LL)))) { L89 ids_1960 = ({ L89 _t6762; memset(&_t6762, 0, sizeof _t6762); _t6762.n = 0; _t6762; }); 
{ int32_t _e6764 = (x_1959).n_; for (int32_t _k6764 = 0; _k6764 < _e6764; _k6764++) { int32_t i_1961 = (int32_t)_k6764; int64_t iv_1962 = f90_kid(((int64_t)((x_1959).b_)), ((int64_t)(i_1961))); 
int64_t p_1963 = f301_nt(); 
(void)(({ L89 *_v6767 = &(ids_1960); int32_t _x6767 = ((int32_t)(p_1963)); if (_v6767->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:971"); _v6767->e[_v6767->n] = _x6767; &_v6767->e[_v6767->n++]; }));
(void)(f264_ct(f284_fin(iv_1962)));
(void)(f263_ow(hr_str(" _t", 3)));
(void)(f302_oi(p_1963));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(iv_1962));
(void)(f263_ow(hr_str("; ", 2)));
 } } _bk6763:; 
int64_t v0_1964 = f160_rv(n_1958); 
{ int32_t _e6777 = (x_1959).n_; for (int32_t _k6777 = 0; _k6777 < _e6777; _k6777++) { int32_t i_1965 = (int32_t)_k6777; (void)(f346_decl_lv(((int64_t)((int64_t)v0_1964 + (int64_t)((int64_t)(i_1965))))));
(void)(({ hrv *_o6779 = &(g163); hr_fs(_o6779, hr_str(" = _t", 5)); hr_fi(_o6779, (*({ L89 *_t6780 = &(ids_1960); int64_t _i6780 = i_1965; _t6780->e + hr_ix(_i6780, _t6780->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:973"); }))); hr_fs(_o6779, hr_str("; ", 2)); }));
 } } _bk6776:; 
return;
 }
int64_t init_1968 = f90_kid(((int64_t)((x_1959).b_)), ((int64_t)0LL)); 
int64_t p_1969 = f301_nt(); 
(void)(f264_ct(f141_at(init_1968)));
(void)(f263_ow(hr_str(" _t", 3)));
(void)(f302_oi(p_1969));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(init_1968));
(void)(f263_ow(hr_str("; ", 2)));
int64_t v0_1970 = f160_rv(n_1958); 
{ int32_t _e6792 = (x_1959).n_; for (int32_t _k6792 = 0; _k6792 < _e6792; _k6792++) { int32_t i_1971 = (int32_t)_k6792; (void)(f346_decl_lv(((int64_t)((int64_t)v0_1970 + (int64_t)((int64_t)(i_1971))))));
(void)(({ hrv *_o6794 = &(g163); hr_fs(_o6794, hr_str(" = _t", 5)); hr_fi(_o6794, p_1969); hr_fs(_o6794, hr_str(".r", 2)); hr_fi(_o6794, i_1971); hr_fs(_o6794, hr_str("; ", 2)); }));
 } } _bk6791:; 
return;
 }
int64_t v_1972 = f160_rv(n_1958); 
int64_t t_1973 = ((int64_t)(((*({ hrv *_t6796 = &(g402); int64_t _i6796 = v_1972; (S12*)_t6796->b + hr_ix(_i6796, _t6796->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:984"); }))).ty_)); 
(void)(f346_decl_lv(v_1972));
(void)(f263_ow(hr_str(" = ", 3)));
if ((((x_1959).b_) < (((int32_t)0LL)))) { (void)(f263_ow(hr_str("{0}; ", 5)));
return;
 }
int64_t init_1974 = f90_kid(((int64_t)((x_1959).b_)), ((int64_t)0LL)); 
if (((((*({ hrv *_t6801 = &(g568); int64_t _i6801 = t_1973; (S1*)_t6801->b + hr_ix(_i6801, _t6801->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:989"); }))).k_) == (((uint8_t)10LL)))) { int64_t it_1975 = f284_fin(init_1974); 
if ((((((*({ hrv *_t6803 = &(g568); int64_t _i6803 = it_1975; (S1*)_t6803->b + hr_ix(_i6803, _t6803->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:989"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t6804 = &(g568); int64_t _i6804 = it_1975; (S1*)_t6804->b + hr_ix(_i6804, _t6804->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:989"); }))).k_) == (((uint8_t)11LL))))) { (void)(f297_gx(init_1974));
 } else { (void)(f333_gaddr(init_1974));
 }
(void)(f263_ow(hr_str("; ", 2)));
return;
 }
if (f271_is_res(t_1973)) { (void)(f272_gxo(init_1974));
(void)(f263_ow(hr_str("; ", 2)));
return;
 }
int64_t it_1976 = f141_at(init_1974); 
if (((((*({ hrv *_t6812 = &(g568); int64_t _i6812 = it_1976; (S1*)_t6812->b + hr_ix(_i6812, _t6812->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:992"); }))).k_) == (((uint8_t)14LL)))) { (void)(f297_gx(init_1974));
(void)(({ hrv *_o6814 = &(g163); hr_fs(_o6814, hr_str(".r0; ", 5)); }));
return;
 }
(void)(f297_gx(init_1974));
(void)(f263_ow(hr_str("; ", 2)));
}
static void f346_decl_lv(int64_t v_1966) {
int64_t t_1967 = ((int64_t)(((*({ hrv *_t6817 = &(g402); int64_t _i6817 = v_1966; (S12*)_t6817->b + hr_ix(_i6817, _t6817->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:996"); }))).ty_)); 
(void)(f264_ct(t_1967));
(void)(f263_ow(hr_str(" ", 1)));
if (f293_lv_isptr(v_1966)) { (void)(f263_ow(hr_str("*", 1)));
 }
(void)(f294_lv_name(v_1966));
if ((f271_is_res(t_1967) && (!(f293_lv_isptr(v_1966))))) { (void)(f263_ow(hr_str(" __attribute__((cleanup(hr_rdrop)))", 35)));
 }
}
static void f347_gstmt1(int64_t n_1977) {
S4 x_1978 = (*({ hrv *_t6826 = &(g721); int64_t _i6826 = n_1977; (S4*)_t6826->b + hr_ix(_i6826, _t6826->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1117"); })); 
int64_t k_1979 = ((int64_t)((x_1978).k_)); 
if (((k_1979) == (((int64_t)34LL)))) { (void)(f348_gassign(n_1977));
return;
 }
if (((k_1979) == (((int64_t)35LL)))) { int64_t a_2002 = ((int64_t)((x_1978).a_)); 
int64_t tt_2003 = f141_at(a_2002); 
if (((((*({ hrv *_t6829 = &(g568); int64_t _i6829 = tt_2003; (S1*)_t6829->b + hr_ix(_i6829, _t6829->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1120"); }))).k_) == (((uint8_t)10LL)))) { (void)(f263_ow(hr_str("(*", 2)));
(void)(f280_gx0(a_2002));
(void)(f263_ow(hr_str(")", 1)));
 } else { (void)(f297_gx(a_2002));
 }
(void)(f263_ow(({ hsl _r6835; if (((((int64_t)((x_1978).op_))) == (((int64_t)34LL)))) { _r6835 = hr_str("++;", 3);  } else { _r6835 = hr_str("--;", 3);  } _r6835; })));
return;
 }
if (((k_1979) == (((int64_t)50LL)))) { return;
 }
if (((k_1979) == (((int64_t)19LL)))) { (void)(f351_gif(n_1977, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1979) == (((int64_t)25LL)))) { (void)(f355_gwhile(n_1977));
return;
 }
if (((k_1979) == (((int64_t)26LL)))) { (void)(f358_gloop(n_1977, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1979) == (((int64_t)27LL)))) { (void)(f359_gfor(n_1977));
return;
 }
if (((k_1979) == (((int64_t)20LL)))) { (void)(f360_gmatch(n_1977, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1979) == (((int64_t)24LL)))) { (void)(f361_geblock(n_1977, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1979) == (((int64_t)23LL)))) { (void)(f263_ow(hr_str("{ ", 2)));
(void)(f352_gblk(n_1977, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f263_ow(hr_str(" }", 2)));
return;
 }
if (((k_1979) == (((int64_t)28LL)))) { (void)(f362_gret(n_1977));
return;
 }
if (((k_1979) == (((int64_t)29LL)))) { (void)(f367_gbreak(n_1977));
return;
 }
if (((k_1979) == (((int64_t)30LL)))) { (void)(f263_ow(hr_str("continue;", 9)));
return;
 }
if (((k_1979) == (((int64_t)37LL)))) { (void)(f295_gerr(n_1977, hr_str("const for is not supported by the self-hosted compiler yet", 58)));
return;
 }
if (f368_owned(n_1977)) { (void)(f263_ow(hr_str("hr_rgive(", 9)));
(void)(f280_gx0(n_1977));
(void)(f263_ow(hr_str(");", 2)));
return;
 }
(void)(f263_ow(hr_str("(void)(", 7)));
(void)(f297_gx(n_1977));
(void)(f263_ow(hr_str(");", 2)));
}
static void f348_gassign(int64_t n_1980) {
S4 x_1981 = (*({ hrv *_t6856 = &(g721); int64_t _i6856 = n_1980; (S4*)_t6856->b + hr_ix(_i6856, _t6856->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1003"); })); 
int64_t o_1982 = ((int64_t)((x_1981).op_)); 
if (((o_1982) == (((int64_t)11LL)))) { int64_t p_1983 = f301_nt(); 
(void)(f263_ow(hr_str("{ ", 2)));
(void)(f264_ct(f141_at(((int64_t)((x_1981).b_)))));
(void)(f263_ow(hr_str(" _t", 3)));
(void)(f302_oi(p_1983));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(((int64_t)((x_1981).b_))));
(void)(f263_ow(hr_str("; ", 2)));
int64_t tl_1984 = ((int64_t)((x_1981).a_)); 
{ int32_t _e6867 = ((*({ hrv *_t6868 = &(g721); int64_t _i6868 = tl_1984; (S4*)_t6868->b + hr_ix(_i6868, _t6868->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1009"); }))).n_; for (int32_t _k6867 = 0; _k6867 < _e6867; _k6867++) { int32_t i_1985 = (int32_t)_k6867; int64_t tg_1986 = f90_kid(tl_1984, ((int64_t)(i_1985))); 
(void)(f297_gx(tg_1986));
(void)(({ hrv *_o6871 = &(g163); hr_fs(_o6871, hr_str(" = _t", 5)); hr_fi(_o6871, p_1983); hr_fs(_o6871, hr_str(".r", 2)); hr_fi(_o6871, i_1985); hr_fs(_o6871, hr_str("; ", 2)); }));
 } } _bk6866:; 
(void)(f263_ow(hr_str("}", 1)));
return;
 }
int64_t a_1987 = ((int64_t)((x_1981).a_)); 
int64_t tt_1988 = f141_at(a_1987); 
int64_t d_1989 = f182_deref(tt_1988); 
if (((((o_1982) == (((int64_t)18LL))) || ((o_1982) == (((int64_t)36LL)))) && ((f276_rel_field(a_1987)) >= (((int64_t)0LL))))) { int64_t rt_1990 = f276_rel_field(a_1987); 
int64_t b_1991 = ((int64_t)((x_1981).b_)); 
(void)(f263_ow(hr_str("hr_rst(&(", 9)));
(void)(f349_grel_lv(a_1987));
(void)(f263_ow(hr_str("), (void*)(", 11)));
if ((((((*({ hrv *_t6880 = &(g568); int64_t _i6880 = f284_fin(b_1991); (S1*)_t6880->b + hr_ix(_i6880, _t6880->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1019"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t6882 = &(g568); int64_t _i6882 = f284_fin(b_1991); (S1*)_t6882->b + hr_ix(_i6882, _t6882->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1019"); }))).k_) == (((uint8_t)11LL))))) { (void)(f297_gx(b_1991));
 } else { (void)(f333_gaddr(b_1991));
 }
(void)(({ hrv *_o6886 = &(g163); hr_fs(_o6886, hr_str("), ", 3)); hr_fc(_o6886, (((((int64_t)((int64_t)((int64_t)(((*({ hrv *_t6887 = &(g568); int64_t _i6887 = rt_1990; (S1*)_t6887->b + hr_ix(_i6887, _t6887->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1019"); }))).fl_)) & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) ? "true" : "false"); hr_fs(_o6886, hr_str(", ", 2)); hr_fi(_o6886, ((int64_t)((((int64_t)8LL)) << ((((int64_t)((int64_t)((int64_t)(((*({ hrv *_t6888 = &(g568); int64_t _i6888 = rt_1990; (S1*)_t6888->b + hr_ix(_i6888, _t6888->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1019"); }))).c_)) & (int64_t)((int64_t)3LL)))) & 63)))); hr_fs(_o6886, hr_str(");", 2)); }));
return;
 }
if ((((o_1982) == (((int64_t)18LL))) && ((((*({ hrv *_t6889 = &(g568); int64_t _i6889 = tt_1988; (S1*)_t6889->b + hr_ix(_i6889, _t6889->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1022"); }))).k_) == (((uint8_t)10LL))))) { int64_t b_1998 = ((int64_t)((x_1981).b_)); 
(void)(f280_gx0(a_1987));
(void)(f263_ow(hr_str(" = ", 3)));
if ((((((*({ hrv *_t6892 = &(g568); int64_t _i6892 = f284_fin(b_1998); (S1*)_t6892->b + hr_ix(_i6892, _t6892->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1025"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t6894 = &(g568); int64_t _i6894 = f284_fin(b_1998); (S1*)_t6894->b + hr_ix(_i6894, _t6894->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1025"); }))).k_) == (((uint8_t)11LL))))) { (void)(f297_gx(b_1998));
 } else { (void)(f333_gaddr(b_1998));
 }
(void)(f263_ow(hr_str(";", 1)));
return;
 }
if ((((o_1982) == (((int64_t)36LL))) || ((o_1982) == (((int64_t)18LL))))) { if (f271_is_res(d_1989)) { (void)(f263_ow(hr_str("hr_rset(", 8)));
if (((((*({ hrv *_t6901 = &(g568); int64_t _i6901 = tt_1988; (S1*)_t6901->b + hr_ix(_i6901, _t6901->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1030"); }))).k_) == (((uint8_t)10LL)))) { (void)(f280_gx0(a_1987));
 } else { (void)(f263_ow(hr_str("&(", 2)));
(void)(f297_gx(a_1987));
(void)(f263_ow(hr_str(")", 1)));
 }
(void)(f263_ow(hr_str(", ", 2)));
(void)(f272_gxo(((int64_t)((x_1981).b_))));
(void)(f263_ow(hr_str(");", 2)));
return;
 }
if ((((((((*({ hrv *_t6909 = &(g568); int64_t _i6909 = tt_1988; (S1*)_t6909->b + hr_ix(_i6909, _t6909->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1031"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t6910 = &(g568); int64_t _i6910 = f141_at(((int64_t)((x_1981).b_))); (S1*)_t6910->b + hr_ix(_i6910, _t6910->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1031"); }))).k_) != (((uint8_t)10LL)))) && ((((*({ hrv *_t6912 = &(g568); int64_t _i6912 = f284_fin(((int64_t)((x_1981).b_))); (S1*)_t6912->b + hr_ix(_i6912, _t6912->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1031"); }))).k_) != (((uint8_t)10LL)))) && ((((*({ hrv *_t6914 = &(g568); int64_t _i6914 = f141_at(((int64_t)((x_1981).b_))); (S1*)_t6914->b + hr_ix(_i6914, _t6914->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1031"); }))).k_) != (((uint8_t)11LL))))) { (void)(f263_ow(hr_str("*", 1)));
(void)(f280_gx0(a_1987));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(((int64_t)((x_1981).b_))));
(void)(f263_ow(hr_str(";", 1)));
return;
 }
if (((((*({ hrv *_t6921 = &(g721); int64_t _i6921 = a_1987; (S4*)_t6921->b + hr_ix(_i6921, _t6921->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1032"); }))).k_) == (((uint8_t)8LL)))) { (void)(f297_gx(a_1987));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(((int64_t)((x_1981).b_))));
(void)(f263_ow(hr_str(";", 1)));
return;
 }
int64_t q_1999 = f301_nt(); 
(void)(f263_ow(hr_str("{ ", 2)));
(void)(f264_ct(d_1989));
(void)(f263_ow(hr_str(" *_t", 4)));
(void)(f302_oi(q_1999));
(void)(f263_ow(hr_str(" = &(", 5)));
(void)(f297_gx(a_1987));
(void)(f263_ow(hr_str("); *_t", 6)));
(void)(f302_oi(q_1999));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(((int64_t)((x_1981).b_))));
(void)(f263_ow(hr_str("; }", 3)));
return;
 }
int64_t p_2000 = f301_nt(); 
(void)(f263_ow(hr_str("{ ", 2)));
(void)(f264_ct(d_1989));
(void)(f263_ow(hr_str(" *_t", 4)));
(void)(f302_oi(p_2000));
(void)(f263_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t6944 = &(g568); int64_t _i6944 = tt_1988; (S1*)_t6944->b + hr_ix(_i6944, _t6944->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1039"); }))).k_) == (((uint8_t)10LL)))) { (void)(f280_gx0(a_1987));
 } else { (void)(f263_ow(hr_str("&(", 2)));
(void)(f297_gx(a_1987));
(void)(f263_ow(hr_str(")", 1)));
 }
(void)(f263_ow(hr_str("; *_t", 5)));
(void)(f302_oi(p_2000));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f316_garith(f350_base_op(o_1982), d_1989, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)((x_1981).b_)), p_2000, n_1980));
(void)(f263_ow(hr_str("; }", 3)));
}
static void f349_grel_lv(int64_t n_1992) {
int64_t a_1993 = ((int64_t)(((*({ hrv *_t6955 = &(g721); int64_t _i6955 = n_1992; (S4*)_t6955->b + hr_ix(_i6955, _t6955->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1059"); }))).a_)); 
int64_t bt_1994 = f141_at(a_1993); 
int64_t st_1995 = f182_deref(bt_1994); 
int64_t si_1996 = ({ int64_t _r6958; if (((((*({ hrv *_t6959 = &(g568); int64_t _i6959 = st_1995; (S1*)_t6959->b + hr_ix(_i6959, _t6959->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1060"); }))).k_) == (((uint8_t)5LL)))) { _r6958 = ((int64_t)(((*({ hrv *_t6960 = &(g568); int64_t _i6960 = st_1995; (S1*)_t6960->b + hr_ix(_i6960, _t6960->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1060"); }))).a_));  } else { _r6958 = f220_ax(n_1992);  } _r6958; }); 
S11 f_1997 = (*({ hrv *_t6962 = &(g572); int64_t _i6962 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t6963 = &(g571); int64_t _i6963 = si_1996; (S10*)_t6963->b + hr_ix(_i6963, _t6963->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1061"); }))).f0_)) + (int64_t)f160_rv(n_1992))); (S11*)_t6962->b + hr_ix(_i6962, _t6962->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1061"); })); 
(void)(f263_ow(hr_str("(", 1)));
if (((((*({ hrv *_t6966 = &(g568); int64_t _i6966 = bt_1994; (S1*)_t6966->b + hr_ix(_i6966, _t6966->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1063"); }))).k_) == (((uint8_t)10LL)))) { (void)(f280_gx0(a_1993));
(void)(f263_ow(hr_str(")->", 3)));
 } else { (void)(f297_gx(a_1993));
(void)(f263_ow(hr_str(").", 2)));
 }
(void)(f270_fname_into((&(g163)), ((int64_t)((f_1997).name_))));
}
static int64_t f350_base_op(int64_t o_2001) {
if (((o_2001) == (((int64_t)26LL)))) { return ((int64_t)21LL);
 }
if (((o_2001) == (((int64_t)27LL)))) { return ((int64_t)22LL);
 }
if (((o_2001) == (((int64_t)28LL)))) { return ((int64_t)23LL);
 }
if (((o_2001) == (((int64_t)29LL)))) { return ((int64_t)24LL);
 }
if (((o_2001) == (((int64_t)30LL)))) { return ((int64_t)25LL);
 }
if (((o_2001) == (((int64_t)31LL)))) { return ((int64_t)49LL);
 }
if (((o_2001) == (((int64_t)32LL)))) { return ((int64_t)50LL);
 }
if (((o_2001) == (((int64_t)33LL)))) { return ((int64_t)51LL);
 }
if (((o_2001) == (((int64_t)45LL)))) { return ((int64_t)43LL);
 }
if (((o_2001) == (((int64_t)46LL)))) { return ((int64_t)44LL);
 }
return o_2001;
}
static void f351_gif(int64_t n_2004, int64_t res_2005) {
S4 x_2006 = (*({ hrv *_t6972 = &(g721); int64_t _i6972 = n_2004; (S4*)_t6972->b + hr_ix(_i6972, _t6972->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:850"); })); 
(void)(f263_ow(hr_str("if (", 4)));
int64_t m_2007 = f220_ax(n_2004); 
if ((((m_2007) != (((int64_t)0LL))) && ((m_2007) != (((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))))) { (void)(f263_ow(hr_str("(", 1)));
(void)(f280_gx0(((int64_t)((x_2006).a_))));
(void)(f263_ow(hr_str(") != 0", 6)));
 } else { (void)(f297_gx(((int64_t)((x_2006).a_))));
 }
(void)(f263_ow(hr_str(") { ", 4)));
if (((m_2007) > (((int64_t)1LL)))) { int64_t v_2008 = ((int64_t)((int64_t)m_2007 & (int64_t)((int64_t)((int64_t)((int64_t)((((int64_t)1LL)) << ((((int64_t)30LL)) & 63))) - (int64_t)((int64_t)1LL))))); 
(void)(f264_ct(((int64_t)(((*({ hrv *_t6981 = &(g402); int64_t _i6981 = v_2008; (S12*)_t6981->b + hr_ix(_i6981, _t6981->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:855"); }))).ty_))));
(void)(f263_ow(hr_str(" *", 2)));
(void)(f294_lv_name(v_2008));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f280_gx0(((int64_t)((x_2006).a_))));
(void)(f263_ow(hr_str("; ", 2)));
 }
(void)(f352_gblk(((int64_t)((x_2006).b_)), res_2005, false));
(void)(f263_ow(hr_str(" }", 2)));
if ((((x_2006).c_) >= (((int32_t)0LL)))) { (void)(f263_ow(hr_str(" else { ", 8)));
if (((((*({ hrv *_t6990 = &(g721); int64_t _i6990 = (x_2006).c_; (S4*)_t6990->b + hr_ix(_i6990, _t6990->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:858"); }))).k_) == (((uint8_t)19LL)))) { (void)(f351_gif(((int64_t)((x_2006).c_)), res_2005));
 } else { (void)(f352_gblk(((int64_t)((x_2006).c_)), res_2005, false));
 }
(void)(f263_ow(hr_str(" }", 2)));
 }
}
static void f352_gblk(int64_t b_2009, int64_t res_2010, bool val_2011) {
S4 x_2012 = (*({ hrv *_t6994 = &(g721); int64_t _i6994 = b_2009; (S4*)_t6994->b + hr_ix(_i6994, _t6994->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:833"); })); 
if (((((int64_t)((x_2012).k_))) != (((int64_t)23LL)))) { if (((res_2010) >= (((int64_t)0LL)))) { (void)(f353_gtail(b_2009, res_2010));
 } else { if (val_2011) { (void)(f297_gx(b_2009));
(void)(f263_ow(hr_str(";", 1)));
 } else { (void)(f344_gstmt(b_2009));
 }
 }
return;
 }
int64_t bsp_2015 = (g163).n; 
int64_t bdu_2016 = g195; 
(void)(f354_gblk1(b_2009, res_2010, val_2011));
if (((((g195) > (bdu_2016)) && (!(f289_is_vimg(f284_fin(b_2009))))) && (!(f289_is_vimg(f141_at(b_2009)))))) { (void)(({ hrv *_v7004 = &(g196); _v7004->n = 0; }));
(void)(({ hrv *_v7005 = &(g196); hsl _s7005 = ({ hsl _t7006 = hr_sl(g163); int64_t _l7006 = bsp_2015, _h7006 = _t7006.n; if (_l7006 < 0 || _h7006 < _l7006 || _h7006 > _t7006.n) hr_slerr(_l7006, _h7006, _t7006.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:837"); (hsl){ _t7006.p + _l7006 * (int64_t)sizeof(uint8_t), _h7006 - _l7006 }; }); hr_append(_v7005, _s7005.p, _s7005.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v7007 = &(g163); int64_t _k7007 = bsp_2015; if (_k7007 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:837"); hr_resize(_v7007, _k7007, sizeof(uint8_t)); }));
(void)(f263_ow(hr_str("int64_t _bm", 11)));
(void)(f302_oi(f301_nt()));
(void)(f263_ow(hr_str(" __attribute__((cleanup(hr_dsr))) = hr_ds.n; ", 45)));
(void)(({ hrv *_v7012 = &(g163); hsl _s7012 = ({ hsl _t7013 = hr_sl(g196); int64_t _l7013 = 0, _h7013 = _t7013.n; if (_l7013 < 0 || _h7013 < _l7013 || _h7013 > _t7013.n) hr_slerr(_l7013, _h7013, _t7013.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:837"); (hsl){ _t7013.p + _l7013 * (int64_t)sizeof(uint8_t), _h7013 - _l7013 }; }); hr_append(_v7012, _s7012.p, _s7012.n, sizeof(uint8_t)); }));
 }
}
static void f353_gtail(int64_t tl_2013, int64_t res_2014) {
if ((((res_2014) >= (((int64_t)0LL))) && (!(f143_ends(tl_2013))))) { (void)(f263_ow(hr_str("_r", 2)));
(void)(f302_oi(res_2014));
(void)(f263_ow(hr_str(" = ", 3)));
if (f271_is_res(f284_fin(tl_2013))) { (void)(f272_gxo(tl_2013));
 } else { (void)(f297_gx(tl_2013));
 }
(void)(f263_ow(hr_str("; ", 2)));
return;
 }
(void)(f344_gstmt(tl_2013));
}
static void f354_gblk1(int64_t b_2017, int64_t res_2018, bool val_2019) {
S4 x_2020 = (*({ hrv *_t7024 = &(g721); int64_t _i7024 = b_2017; (S4*)_t7024->b + hr_ix(_i7024, _t7024->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:840"); })); 
{ int32_t _e7026 = (x_2020).n_; for (int32_t _k7026 = 0; _k7026 < _e7026; _k7026++) { int32_t i_2021 = (int32_t)_k7026; (void)(f344_gstmt(f90_kid(b_2017, ((int64_t)(i_2021)))));
 } } _bk7025:; 
if ((((x_2020).a_) >= (((int32_t)0LL)))) { int64_t tl_2022 = ((int64_t)((x_2020).a_)); 
if (((res_2018) >= (((int64_t)0LL)))) { (void)(f353_gtail(tl_2022, res_2018));
return;
 }
if (((val_2019 && ((f141_at(tl_2022)) != (g575))) && (!(f143_ends(tl_2022))))) { (void)(f297_gx(tl_2022));
(void)(f263_ow(hr_str("; ", 2)));
return;
 }
(void)(f344_gstmt(tl_2022));
 }
}
static void f355_gwhile(int64_t n_2023) {
S4 x_2024 = (*({ hrv *_t7035 = &(g721); int64_t _i7035 = n_2023; (S4*)_t7035->b + hr_ix(_i7035, _t7035->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:873"); })); 
int64_t l_2027 = f356_lbl_push(((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f263_ow(hr_str("while (", 7)));
if (((f220_ax(n_2023)) == (((int64_t)1LL)))) { (void)(f263_ow(hr_str("(", 1)));
(void)(f280_gx0(((int64_t)((x_2024).a_))));
(void)(f263_ow(hr_str(") != 0", 6)));
 } else { (void)(f297_gx(((int64_t)((x_2024).a_))));
 }
(void)(f263_ow(hr_str(") { ", 4)));
(void)(f352_gblk(((int64_t)((x_2024).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f263_ow(hr_str(" }", 2)));
(void)(f357_lbl_pop(l_2027));
}
static int64_t f356_lbl_push(int64_t res_2025) {
int64_t l_2026 = f301_nt(); 
(void)(({ hrv *_v7048 = &(g180); int32_t _x7048 = ((int32_t)(l_2026)); int32_t *_p7048 = (int32_t*)hr_grow(_v7048, 1, sizeof _x7048); *_p7048 = _x7048; _p7048; }));
(void)(({ hrv *_v7049 = &(g181); int32_t _x7049 = ((int32_t)(res_2025)); int32_t *_p7049 = (int32_t*)hr_grow(_v7049, 1, sizeof _x7049); *_p7049 = _x7049; _p7049; }));
return l_2026;
}
static void f357_lbl_pop(int64_t l_2028) {
(void)(({ hrv *_v7050 = &(g180); if (!_v7050->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:861"); ((int32_t*)_v7050->b)[--_v7050->n]; }));
(void)(({ hrv *_v7051 = &(g181); if (!_v7051->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:861"); ((int32_t*)_v7051->b)[--_v7051->n]; }));
(void)(({ hrv *_o7052 = &(g163); hr_fs(_o7052, hr_str(" _bk", 4)); hr_fi(_o7052, l_2028); hr_fs(_o7052, hr_str(":; ", 3)); }));
}
static void f358_gloop(int64_t n_2029, int64_t res_2030) {
int64_t l_2031 = f356_lbl_push(res_2030); 
(void)(f263_ow(hr_str("for (;;) { ", 11)));
(void)(f352_gblk(((int64_t)(((*({ hrv *_t7056 = &(g721); int64_t _i7056 = n_2029; (S4*)_t7056->b + hr_ix(_i7056, _t7056->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:864"); }))).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f263_ow(hr_str(" }", 2)));
(void)(f357_lbl_pop(l_2031));
}
static void f359_gfor(int64_t n_2032) {
S4 x_2033 = (*({ hrv *_t7059 = &(g721); int64_t _i7059 = n_2032; (S4*)_t7059->b + hr_ix(_i7059, _t7059->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:881"); })); 
int64_t v_2034 = f160_rv(n_2032); 
int64_t m_2035 = f220_ax(n_2032); 
int64_t iv_2036 = ({ int64_t _r7062; if ((((x_2033).c_) >= (((int32_t)0LL)))) { _r7062 = ((int64_t)((m_2035) >> ((((int64_t)2LL)) & 63)));  } else { _r7062 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r7062; }); 
int64_t l_2037 = f356_lbl_push(((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t p_2038 = f301_nt(); 
int64_t et_2039 = ((int64_t)(((*({ hrv *_t7065 = &(g402); int64_t _i7065 = v_2034; (S12*)_t7065->b + hr_ix(_i7065, _t7065->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:887"); }))).ty_)); 
if (((((int64_t)((int64_t)m_2035 & (int64_t)((int64_t)3LL)))) == (((int64_t)0LL)))) { int64_t rt0_2040 = f284_fin(({ int64_t _r7067; if ((((x_2033).b_) >= (((int32_t)0LL)))) { _r7067 = ((int64_t)((x_2033).b_));  } else { _r7067 = ((int64_t)((x_2033).a_));  } _r7067; })); 
int64_t ctt_2041 = ({ int64_t _r7068; if (((((*({ hrv *_t7069 = &(g568); int64_t _i7069 = rt0_2040; (S1*)_t7069->b + hr_ix(_i7069, _t7069->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:890"); }))).k_) == (((uint8_t)3LL)))) { _r7068 = rt0_2040;  } else { _r7068 = g580;  } _r7068; }); 
(void)(f263_ow(hr_str("{ ", 2)));
(void)(f264_ct(ctt_2041));
(void)(f263_ow(hr_str(" _e", 3)));
(void)(f302_oi(p_2038));
(void)(f263_ow(hr_str(" = ", 3)));
if ((((x_2033).b_) >= (((int32_t)0LL)))) { (void)(f297_gx(((int64_t)((x_2033).b_))));
 } else { (void)(f297_gx(((int64_t)((x_2033).a_))));
 }
(void)(f263_ow(hr_str("; for (", 7)));
(void)(f264_ct(ctt_2041));
(void)(({ hrv *_o7079 = &(g163); hr_fs(_o7079, hr_str(" _k", 3)); hr_fi(_o7079, p_2038); hr_fs(_o7079, hr_str(" = ", 3)); }));
if ((((x_2033).b_) >= (((int32_t)0LL)))) { (void)(f297_gx(((int64_t)((x_2033).a_))));
 } else { (void)(f263_ow(hr_str("0", 1)));
 }
(void)(({ hrv *_o7082 = &(g163); hr_fs(_o7082, hr_str("; _k", 4)); hr_fi(_o7082, p_2038); hr_fs(_o7082, hr_str(" < _e", 5)); hr_fi(_o7082, p_2038); hr_fs(_o7082, hr_str("; _k", 4)); hr_fi(_o7082, p_2038); hr_fs(_o7082, hr_str("++) { ", 6)); }));
(void)(f264_ct(et_2039));
(void)(f263_ow(hr_str(" ", 1)));
(void)(f294_lv_name(v_2034));
(void)(({ hrv *_o7086 = &(g163); hr_fs(_o7086, hr_str(" = (", 4)); }));
(void)(f264_ct(et_2039));
(void)(({ hrv *_o7088 = &(g163); hr_fs(_o7088, hr_str(")_k", 3)); hr_fi(_o7088, p_2038); hr_fs(_o7088, hr_str("; ", 2)); }));
if (((iv_2036) >= (((int64_t)0LL)))) { (void)(f264_ct(((int64_t)(((*({ hrv *_t7090 = &(g402); int64_t _i7090 = iv_2036; (S12*)_t7090->b + hr_ix(_i7090, _t7090->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:896"); }))).ty_))));
(void)(f263_ow(hr_str(" ", 1)));
(void)(f294_lv_name(iv_2036));
(void)(f263_ow(hr_str(" = (", 4)));
(void)(f264_ct(((int64_t)(((*({ hrv *_t7095 = &(g402); int64_t _i7095 = iv_2036; (S12*)_t7095->b + hr_ix(_i7095, _t7095->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:896"); }))).ty_))));
(void)(({ hrv *_o7096 = &(g163); hr_fs(_o7096, hr_str(")_k", 3)); hr_fi(_o7096, p_2038); hr_fs(_o7096, hr_str("; ", 2)); }));
 }
(void)(f352_gblk(((int64_t)((x_2033).d_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f263_ow(hr_str(" } }", 4)));
(void)(f357_lbl_pop(l_2037));
return;
 }
int64_t a_2042 = ((int64_t)((x_2033).a_)); 
int64_t bt_2043 = f141_at(a_2042); 
int64_t d_2044 = f182_deref(bt_2043); 
int64_t e_2045 = ((int64_t)(((*({ hrv *_t7102 = &(g568); int64_t _i7102 = d_2044; (S1*)_t7102->b + hr_ix(_i7102, _t7102->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:905"); }))).a_)); 
bool byref_2046 = ((((uint16_t)((uint64_t)(x_2033).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))); 
if (f271_is_res(d_2044)) { (void)(f263_ow(hr_str("{ hrv *_v", 9)));
(void)(f302_oi(p_2038));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f334_grecv_ptr(a_2042));
(void)(({ hrv *_o7108 = &(g163); hr_fs(_o7108, hr_str("; for (int64_t _k", 17)); hr_fi(_o7108, p_2038); hr_fs(_o7108, hr_str(" = 0; _k", 8)); hr_fi(_o7108, p_2038); hr_fs(_o7108, hr_str(" < _v", 5)); hr_fi(_o7108, p_2038); hr_fs(_o7108, hr_str("->n; _k", 7)); hr_fi(_o7108, p_2038); hr_fs(_o7108, hr_str("++) { ", 6)); }));
(void)(f264_ct(e_2045));
(void)(f263_ow(({ hsl _r7111; if (byref_2046) { _r7111 = hr_str(" *", 2);  } else { _r7111 = hr_str(" ", 1);  } _r7111; })));
(void)(f294_lv_name(v_2034));
(void)(f263_ow(({ hsl _r7114; if (byref_2046) { _r7114 = hr_str(" = &((", 6);  } else { _r7114 = hr_str(" = ((", 5);  } _r7114; })));
(void)(f264_ct(e_2045));
(void)(({ hrv *_o7116 = &(g163); hr_fs(_o7116, hr_str("*)_v", 4)); hr_fi(_o7116, p_2038); hr_fs(_o7116, hr_str("->b)[_k", 7)); hr_fi(_o7116, p_2038); hr_fs(_o7116, hr_str("]; ", 3)); }));
 } else { (void)(f263_ow(hr_str("{ hsl _v", 8)));
(void)(f302_oi(p_2038));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f300_gsl(a_2042, bt_2043));
(void)(({ hrv *_o7121 = &(g163); hr_fs(_o7121, hr_str("; for (int64_t _k", 17)); hr_fi(_o7121, p_2038); hr_fs(_o7121, hr_str(" = 0; _k", 8)); hr_fi(_o7121, p_2038); hr_fs(_o7121, hr_str(" < _v", 5)); hr_fi(_o7121, p_2038); hr_fs(_o7121, hr_str(".n; _k", 6)); hr_fi(_o7121, p_2038); hr_fs(_o7121, hr_str("++) { ", 6)); }));
(void)(f264_ct(e_2045));
(void)(f263_ow(({ hsl _r7124; if (byref_2046) { _r7124 = hr_str(" *", 2);  } else { _r7124 = hr_str(" ", 1);  } _r7124; })));
(void)(f294_lv_name(v_2034));
(void)(f263_ow(({ hsl _r7127; if (byref_2046) { _r7127 = hr_str(" = &((", 6);  } else { _r7127 = hr_str(" = ((", 5);  } _r7127; })));
(void)(f264_ct(e_2045));
(void)(({ hrv *_o7129 = &(g163); hr_fs(_o7129, hr_str("*)_v", 4)); hr_fi(_o7129, p_2038); hr_fs(_o7129, hr_str(".p)[_k", 6)); hr_fi(_o7129, p_2038); hr_fs(_o7129, hr_str("]; ", 3)); }));
 }
if (((iv_2036) >= (((int64_t)0LL)))) { (void)(f264_ct(((int64_t)(((*({ hrv *_t7131 = &(g402); int64_t _i7131 = iv_2036; (S12*)_t7131->b + hr_ix(_i7131, _t7131->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:914"); }))).ty_))));
(void)(f263_ow(hr_str(" ", 1)));
(void)(f294_lv_name(iv_2036));
(void)(f263_ow(hr_str(" = (", 4)));
(void)(f264_ct(((int64_t)(((*({ hrv *_t7136 = &(g402); int64_t _i7136 = iv_2036; (S12*)_t7136->b + hr_ix(_i7136, _t7136->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:914"); }))).ty_))));
(void)(({ hrv *_o7137 = &(g163); hr_fs(_o7137, hr_str(")_k", 3)); hr_fi(_o7137, p_2038); hr_fs(_o7137, hr_str("; ", 2)); }));
 }
(void)(f352_gblk(((int64_t)((x_2033).d_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f263_ow(hr_str(" } }", 4)));
(void)(f357_lbl_pop(l_2037));
}
static void f360_gmatch(int64_t n_2047, int64_t res_2048) {
S4 x_2049 = (*({ hrv *_t7141 = &(g721); int64_t _i7141 = n_2047; (S4*)_t7141->b + hr_ix(_i7141, _t7141->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:920"); })); 
int64_t a_2050 = ((int64_t)((x_2049).a_)); 
int64_t st_2051 = f141_at(a_2050); 
int64_t d_2052 = f182_deref(st_2051); 
int64_t p_2053 = f301_nt(); 
bool isenum_2054 = ((((*({ hrv *_t7145 = &(g568); int64_t _i7145 = d_2052; (S1*)_t7145->b + hr_ix(_i7145, _t7145->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:925"); }))).k_) == (((uint8_t)6LL))); 
(void)(f263_ow(hr_str("{ ", 2)));
if (isenum_2054) { (void)(f264_ct(d_2052));
(void)(f263_ow(hr_str(" *_m", 4)));
(void)(f302_oi(p_2053));
(void)(f263_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t7151 = &(g568); int64_t _i7151 = st_2051; (S1*)_t7151->b + hr_ix(_i7151, _t7151->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:927"); }))).k_) == (((uint8_t)10LL)))) { (void)(f280_gx0(a_2050));
 } else { if (f275_is_place(a_2050)) { (void)(f263_ow(hr_str("&(", 2)));
(void)(f297_gx(a_2050));
(void)(f263_ow(hr_str(")", 1)));
 } else { int64_t k0_2055 = f278_tmp(d_2052, false); 
(void)(f263_ow(hr_str("(", 1)));
(void)(f279_ot(k0_2055));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f272_gxo(a_2050));
(void)(f263_ow(hr_str(", &", 3)));
(void)(f279_ot(k0_2055));
(void)(f263_ow(hr_str(")", 1)));
 }
 }
(void)(f263_ow(hr_str("; ", 2)));
 } else { (void)(f264_ct(d_2052));
(void)(f263_ow(hr_str(" _m", 3)));
(void)(f302_oi(p_2053));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(a_2050));
(void)(f263_ow(hr_str("; ", 2)));
 }
bool first_2056 = true; 
{ int32_t _e7173 = (x_2049).n_; for (int32_t _k7173 = 0; _k7173 < _e7173; _k7173++) { int32_t i_2057 = (int32_t)_k7173; int64_t arm_2058 = f90_kid(n_2047, ((int64_t)(i_2057))); 
S4 ar_2059 = (*({ hrv *_t7175 = &(g721); int64_t _i7175 = arm_2058; (S4*)_t7175->b + hr_ix(_i7175, _t7175->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:932"); })); 
if ((!(first_2056))) { (void)(f263_ow(hr_str(" else ", 6)));
 }
first_2056 = false;
if (((((uint16_t)((uint64_t)(ar_2059).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(f263_ow(hr_str("{ ", 2)));
(void)(f352_gblk(((int64_t)((ar_2059).b_)), res_2048, false));
(void)(f263_ow(hr_str(" }", 2)));
continue;
 }
(void)(f263_ow(hr_str("if (", 4)));
{ int32_t _e7182 = (ar_2059).n_; for (int32_t _k7182 = 0; _k7182 < _e7182; _k7182++) { int32_t j_2060 = (int32_t)_k7182; if (((j_2060) > (((int32_t)0LL)))) { (void)(f263_ow(hr_str(" || ", 4)));
 }
int64_t it_2061 = f90_kid(arm_2058, ((int64_t)(j_2060))); 
int64_t lo_2062 = ((int64_t)(((*({ hrv *_t7185 = &(g721); int64_t _i7185 = it_2061; (S4*)_t7185->b + hr_ix(_i7185, _t7185->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:940"); }))).a_)); 
if (isenum_2054) { (void)(({ hrv *_o7186 = &(g163); hr_fs(_o7186, hr_str("_m", 2)); hr_fi(_o7186, p_2053); hr_fs(_o7186, hr_str("->tag == ", 9)); hr_fi(_o7186, f160_rv(lo_2062)); }));
 } else { if (((((*({ hrv *_t7188 = &(g721); int64_t _i7188 = it_2061; (S4*)_t7188->b + hr_ix(_i7188, _t7188->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:943"); }))).b_) >= (((int32_t)0LL)))) { (void)(({ hrv *_o7189 = &(g163); hr_fs(_o7189, hr_str("(_m", 3)); hr_fi(_o7189, p_2053); hr_fs(_o7189, hr_str(" >= ", 4)); }));
(void)(f297_gx(lo_2062));
(void)(({ hrv *_o7191 = &(g163); hr_fs(_o7191, hr_str(" && _m", 6)); hr_fi(_o7191, p_2053); hr_fs(_o7191, hr_str(" < ", 3)); }));
(void)(f297_gx(((int64_t)(((*({ hrv *_t7193 = &(g721); int64_t _i7193 = it_2061; (S4*)_t7193->b + hr_ix(_i7193, _t7193->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:943"); }))).b_))));
(void)(f263_ow(hr_str(")", 1)));
 } else { if (((((f183_leaf_kind(d_2052)) == (((int64_t)0LL))) && ((((*({ hrv *_t7196 = &(g568); int64_t _i7196 = d_2052; (S1*)_t7196->b + hr_ix(_i7196, _t7196->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:944"); }))).k_) != (((uint8_t)3LL)))) && ((((*({ hrv *_t7197 = &(g568); int64_t _i7197 = d_2052; (S1*)_t7197->b + hr_ix(_i7197, _t7197->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:944"); }))).k_) != (((uint8_t)2LL))))) { (void)(f263_ow(hr_str("heq", 3)));
(void)(f302_oi(d_2052));
(void)(({ hrv *_o7200 = &(g163); hr_fs(_o7200, hr_str("(_m", 3)); hr_fi(_o7200, p_2053); hr_fs(_o7200, hr_str(", ", 2)); }));
(void)(f297_gx(lo_2062));
(void)(f263_ow(hr_str(")", 1)));
(void)(f304_gen_heq(d_2052));
 } else { (void)(({ hrv *_o7204 = &(g163); hr_fs(_o7204, hr_str("_m", 2)); hr_fi(_o7204, p_2053); hr_fs(_o7204, hr_str(" == ", 4)); }));
(void)(f297_gx(lo_2062));
 }
 }
 }
 } } _bk7181:; 
(void)(f263_ow(hr_str(") { ", 4)));
if (((((ar_2059).s_) >= (((int32_t)0LL))) && isenum_2054)) { int64_t v_2063 = f160_rv(arm_2058); 
int64_t vi_2064 = f160_rv(((int64_t)(((*({ hrv *_t7209 = &(g721); int64_t _i7209 = f90_kid(arm_2058, ((int64_t)0LL)); (S4*)_t7209->b + hr_ix(_i7209, _t7209->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:950"); }))).a_))); 
int64_t lt_2065 = ((int64_t)(((*({ hrv *_t7211 = &(g402); int64_t _i7211 = v_2063; (S12*)_t7211->b + hr_ix(_i7211, _t7211->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:951"); }))).ty_)); 
int64_t vt_2066 = f182_deref(lt_2065); 
int64_t ei_2067 = ((int64_t)(((*({ hrv *_t7213 = &(g568); int64_t _i7213 = d_2052; (S1*)_t7213->b + hr_ix(_i7213, _t7213->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:953"); }))).a_)); 
S9 vv_2068 = (*({ hrv *_t7214 = &(g574); int64_t _i7214 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t7215 = &(g573); int64_t _i7215 = ei_2067; (S8*)_t7215->b + hr_ix(_i7215, _t7215->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:954"); }))).v0_)) + (int64_t)vi_2064)); (S9*)_t7214->b + hr_ix(_i7214, _t7214->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:954"); })); 
bool has_2069 = ((((vv_2068).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t7216 = &(g571); int64_t _i7216 = (vv_2068).si_; (S10*)_t7216->b + hr_ix(_i7216, _t7216->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:955"); }))).zero_))); 
(void)(f264_ct(lt_2065));
(void)(f263_ow(hr_str(" ", 1)));
(void)(f294_lv_name(v_2063));
(void)(f263_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t7221 = &(g568); int64_t _i7221 = lt_2065; (S1*)_t7221->b + hr_ix(_i7221, _t7221->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:957"); }))).k_) == (((uint8_t)10LL)))) { if (has_2069) { (void)(({ hrv *_o7222 = &(g163); hr_fs(_o7222, hr_str("&_m", 3)); hr_fi(_o7222, p_2053); hr_fs(_o7222, hr_str("->u.v", 5)); hr_fi(_o7222, vi_2064); hr_fs(_o7222, hr_str("; ", 2)); }));
 } else { (void)(f263_ow(hr_str("0; ", 3)));
 }
 } else { if (has_2069) { (void)(({ hrv *_o7224 = &(g163); hr_fs(_o7224, hr_str("_m", 2)); hr_fi(_o7224, p_2053); hr_fs(_o7224, hr_str("->u.v", 5)); hr_fi(_o7224, vi_2064); hr_fs(_o7224, hr_str("; ", 2)); }));
 } else { (void)(f263_ow(hr_str("0; ", 3)));
 }
 }
 }
(void)(f352_gblk(((int64_t)((ar_2059).b_)), res_2048, false));
(void)(f263_ow(hr_str(" }", 2)));
 } } _bk7172:; 
(void)(f263_ow(hr_str(" }", 2)));
}
static void f361_geblock(int64_t n_2070, int64_t res_2071) {
int64_t l_2072 = f356_lbl_push(res_2071); 
(void)(f263_ow(hr_str("{ ", 2)));
(void)(f352_gblk(((int64_t)(((*({ hrv *_t7232 = &(g721); int64_t _i7232 = n_2070; (S4*)_t7232->b + hr_ix(_i7232, _t7232->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:869"); }))).a_)), res_2071, false));
(void)(f263_ow(hr_str(" }", 2)));
(void)(f357_lbl_pop(l_2072));
}
static void f362_gret(int64_t n_2073) {
S4 x_2074 = (*({ hrv *_t7235 = &(g721); int64_t _i7235 = n_2073; (S4*)_t7235->b + hr_ix(_i7235, _t7235->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1072"); })); 
int64_t lt_2075 = f220_ax(n_2073); 
if ((((lt_2075) >= (((int64_t)0LL))) && ((lt_2075) != (g179)))) { int64_t rt0_2076 = ((int64_t)(((*({ hrv *_t7237 = &(g401); int64_t _i7237 = lt_2075; (S6*)_t7237->b + hr_ix(_i7237, _t7237->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1075"); }))).ret_)); 
(void)(f263_ow(hr_str("{ ", 2)));
if ((((x_2074).n_) > (((int32_t)1LL)))) { (void)(({ hrv *_o7239 = &(g163); hr_fs(_o7239, hr_str("_lrv", 4)); hr_fi(_o7239, lt_2075); hr_fs(_o7239, hr_str(" = (", 4)); }));
(void)(f264_ct(rt0_2076));
(void)(f263_ow(hr_str("){ ", 3)));
{ int32_t _e7243 = (x_2074).n_; for (int32_t _k7243 = 0; _k7243 < _e7243; _k7243++) { int32_t i_2077 = (int32_t)_k7243; if (((i_2077) > (((int32_t)0LL)))) { (void)(f263_ow(hr_str(", ", 2)));
 }
int64_t c_2078 = f90_kid(n_2073, ((int64_t)(i_2077))); 
if (f271_is_res(f284_fin(c_2078))) { (void)(f363_gmove(c_2078));
 } else { (void)(f297_gx(c_2078));
 }
 } } _bk7242:; 
(void)(f263_ow(hr_str(" }; ", 4)));
 } else { if ((((x_2074).n_) == (((int32_t)1LL)))) { (void)(({ hrv *_o7251 = &(g163); hr_fs(_o7251, hr_str("_lrv", 4)); hr_fi(_o7251, lt_2075); hr_fs(_o7251, hr_str(" = ", 3)); }));
int64_t c_2084 = f90_kid(n_2073, ((int64_t)0LL)); 
if (f271_is_res(rt0_2076)) { (void)(f363_gmove(c_2084));
 } else { (void)(f297_gx(c_2084));
 }
(void)(f263_ow(hr_str("; ", 2)));
 }
 }
(void)(({ hrv *_o7257 = &(g163); hr_fs(_o7257, hr_str("hr_lr = ", 8)); hr_fi(_o7257, ((int64_t)((int64_t)lt_2075 + (int64_t)((int64_t)1LL)))); hr_fs(_o7257, hr_str("; ", 2)); }));
(void)(f365_gdummy());
(void)(f263_ow(hr_str(" }", 2)));
return;
 }
if ((((x_2074).n_) == (((int32_t)0LL)))) { (void)(f263_ow(hr_str("return;", 7)));
return;
 }
int64_t f_2086 = ({ int64_t _r7261; if (((lt_2075) >= (((int64_t)0LL)))) { _r7261 = lt_2075;  } else { _r7261 = f224_ret_fn();  } _r7261; }); 
int64_t rt_2087 = ((int64_t)(((*({ hrv *_t7263 = &(g401); int64_t _i7263 = f_2086; (S6*)_t7263->b + hr_ix(_i7263, _t7263->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1084"); }))).ret_)); 
if ((((x_2074).n_) > (((int32_t)1LL)))) { (void)(f263_ow(hr_str("return (", 8)));
(void)(f264_ct(rt_2087));
(void)(f263_ow(hr_str("){ ", 3)));
{ int32_t _e7268 = (x_2074).n_; for (int32_t _k7268 = 0; _k7268 < _e7268; _k7268++) { int32_t i_2088 = (int32_t)_k7268; if (((i_2088) > (((int32_t)0LL)))) { (void)(f263_ow(hr_str(", ", 2)));
 }
int64_t c_2089 = f90_kid(n_2073, ((int64_t)(i_2088))); 
if (f271_is_res(f284_fin(c_2089))) { (void)(f363_gmove(c_2089));
 } else { (void)(f297_gx(c_2089));
 }
 } } _bk7267:; 
(void)(f263_ow(hr_str(" };", 3)));
return;
 }
int64_t c_2090 = f90_kid(n_2073, ((int64_t)0LL)); 
if (f289_is_vimg(rt_2087)) { (void)(f366_gvret(c_2090, rt_2087));
return;
 }
(void)(f263_ow(hr_str("return ", 7)));
if (f271_is_res(rt_2087)) { (void)(f363_gmove(c_2090));
 } else { (void)(f297_gx(c_2090));
 }
(void)(f263_ow(hr_str(";", 1)));
}
static void f363_gmove(int64_t c_2079) {
if (f364_movable_local(c_2079)) { int64_t v_2082 = f160_rv(c_2079); 
int64_t p_2083 = f301_nt(); 
(void)(f263_ow(hr_str("({ hrv _mv", 10)));
(void)(f302_oi(p_2083));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f294_lv_name(v_2082));
(void)(f263_ow(hr_str("; ", 2)));
(void)(f294_lv_name(v_2082));
(void)(f263_ow(hr_str(".b = 0; ", 8)));
(void)(f294_lv_name(v_2082));
(void)(({ hrv *_o7295 = &(g163); hr_fs(_o7295, hr_str(".n = 0; _mv", 11)); hr_fi(_o7295, p_2083); hr_fs(_o7295, hr_str("; })", 4)); }));
return;
 }
(void)(f272_gxo(c_2079));
}
static bool f364_movable_local(int64_t c_2080) {
if ((((((*({ hrv *_t7297 = &(g721); int64_t _i7297 = c_2080; (S4*)_t7297->b + hr_ix(_i7297, _t7297->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1066"); }))).k_) != (((uint8_t)8LL))) || ((f159_rk(c_2080)) != (((int64_t)1LL))))) { return false;
 }
int64_t v_2081 = f160_rv(c_2080); 
return (((((((int64_t)(((*({ hrv *_t7300 = &(g402); int64_t _i7300 = v_2081; (S12*)_t7300->b + hr_ix(_i7300, _t7300->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1066"); }))).cfn_))) == (g179)) && (!(f293_lv_isptr(v_2081)))) && ((((*({ hrv *_t7302 = &(g568); int64_t _i7302 = ((*({ hrv *_t7303 = &(g402); int64_t _i7303 = v_2081; (S12*)_t7303->b + hr_ix(_i7303, _t7303->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1066"); }))).ty_; (S1*)_t7302->b + hr_ix(_i7302, _t7302->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1066"); }))).k_) != (((uint8_t)10LL)))) && (((f153_cv(c_2080)) < (((int64_t)0LL))) || ((f153_cv(c_2080)) == (f141_at(c_2080)))));
}
static void f365_gdummy(void) {
int64_t rt_2085 = ((int64_t)(((*({ hrv *_t7307 = &(g401); int64_t _i7307 = g179; (S6*)_t7307->b + hr_ix(_i7307, _t7307->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1044"); }))).ret_)); 
if ((((rt_2085) < (((int64_t)0LL))) || ((rt_2085) == (g575)))) { (void)(f263_ow(hr_str("return;", 7)));
return;
 }
(void)(f263_ow(hr_str("{ ", 2)));
(void)(f264_ct(rt_2085));
(void)(f263_ow(hr_str(" _z; memset(&_z, 0, sizeof _z); return _z; }", 44)));
}
static void f366_gvret(int64_t c_2091, int64_t rt_2092) {
if ((!(f303_vok(c_2091, rt_2092)))) { return;
 }
g195++;
(void)(f263_ow(hr_str("return hr_dsret(", 16)));
(void)(f297_gx(c_2091));
(void)(f263_ow(hr_str(", _fm", 5)));
(void)(f290_vargs(rt_2092));
(void)(f263_ow(hr_str(", sizeof(", 9)));
(void)(f264_ct(((int64_t)(((*({ hrv *_t7319 = &(g568); int64_t _i7319 = rt_2092; (S1*)_t7319->b + hr_ix(_i7319, _t7319->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1090"); }))).a_))));
(void)(f263_ow(hr_str("));", 3)));
}
static void f367_gbreak(int64_t n_2093) {
S4 x_2094 = (*({ hrv *_t7321 = &(g721); int64_t _i7321 = n_2093; (S4*)_t7321->b + hr_ix(_i7321, _t7321->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1092"); })); 
if ((((g180).n) == (((int64_t)0LL)))) { (void)(f295_gerr(n_2093, hr_str("break outside a loop", 20)));
return;
 }
int64_t l_2095 = ((int64_t)((*({ hrv *_t7323 = &(g180); int64_t _i7323 = ((int64_t)((int64_t)(g180).n - (int64_t)((int64_t)1LL))); (int32_t*)_t7323->b + hr_ix(_i7323, _t7323->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1094"); })))); 
int64_t r_2096 = ((int64_t)((*({ hrv *_t7324 = &(g181); int64_t _i7324 = ((int64_t)((int64_t)(g181).n - (int64_t)((int64_t)1LL))); (int32_t*)_t7324->b + hr_ix(_i7324, _t7324->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1095"); })))); 
(void)(f263_ow(hr_str("{ ", 2)));
if ((((x_2094).a_) >= (((int32_t)0LL)))) { if (((r_2096) >= (((int64_t)0LL)))) { (void)(f263_ow(hr_str("_r", 2)));
(void)(f302_oi(r_2096));
(void)(f263_ow(hr_str(" = ", 3)));
(void)(f297_gx(((int64_t)((x_2094).a_))));
(void)(f263_ow(hr_str("; ", 2)));
 } else { (void)(f263_ow(hr_str("(void)(", 7)));
(void)(f297_gx(((int64_t)((x_2094).a_))));
(void)(f263_ow(hr_str("); ", 3)));
 }
 }
(void)(({ hrv *_o7334 = &(g163); hr_fs(_o7334, hr_str("goto _bk", 8)); hr_fi(_o7334, l_2095); hr_fs(_o7334, hr_str("; }", 3)); }));
}
static bool f368_owned(int64_t n_2097) {
return (f271_is_res(f284_fin(n_2097)) && (!(f275_is_place(n_2097))));
}
static bool f369_is_ext(int64_t i_2101) {
return ((((uint16_t)((uint64_t)((*({ hrv *_t7338 = &(g721); int64_t _i7338 = ((*({ hrv *_t7339 = &(g401); int64_t _i7339 = i_2101; (S6*)_t7339->b + hr_ix(_i7339, _t7339->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:604"); }))).node_; (S4*)_t7338->b + hr_ix(_i7338, _t7338->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:604"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)));
}
static void f370_ext_name(int64_t i_2106) {
int64_t node_2107 = ((int64_t)(((*({ hrv *_t7340 = &(g401); int64_t _i7340 = i_2106; (S6*)_t7340->b + hr_ix(_i7340, _t7340->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:599"); }))).node_)); 
int64_t x_2108 = ((int64_t)(((*({ hrv *_t7341 = &(g721); int64_t _i7341 = node_2107; (S4*)_t7341->b + hr_ix(_i7341, _t7341->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:600"); }))).e_)); 
if ((((x_2108) >= (((int64_t)0LL))) && ((((*({ hrv *_t7342 = &(g721); int64_t _i7342 = x_2108; (S4*)_t7342->b + hr_ix(_i7342, _t7342->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:601"); }))).a_) >= (((int32_t)0LL))))) { hsl s_2109 = f285_tok_str(((int64_t)(((*({ hrv *_t7344 = &(g721); int64_t _i7344 = x_2108; (S4*)_t7344->b + hr_ix(_i7344, _t7344->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:601"); }))).a_))); 
if (((((((s_2109).n) > (((int64_t)3LL))) && (((*({ hsl _t7345 = s_2109; int64_t _i7345 = ((int64_t)0LL); (uint8_t*)_t7345.p + hr_ix(_i7345, _t7345.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:601"); }))) == (((uint8_t)103LL)))) && (((*({ hsl _t7346 = s_2109; int64_t _i7346 = ((int64_t)1LL); (uint8_t*)_t7346.p + hr_ix(_i7346, _t7346.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:601"); }))) == (((uint8_t)115LL)))) && (((*({ hsl _t7347 = s_2109; int64_t _i7347 = ((int64_t)2LL); (uint8_t*)_t7347.p + hr_ix(_i7347, _t7347.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:601"); }))) == (((uint8_t)95LL))))) { (void)(f263_ow(hr_str("hr_", 3)));
(void)(f263_ow(({ hsl _t7350 = s_2109; int64_t _l7350 = ((int64_t)3LL), _h7350 = _t7350.n; if (_l7350 < 0 || _h7350 < _l7350 || _h7350 > _t7350.n) hr_slerr(_l7350, _h7350, _t7350.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:601"); (hsl){ _t7350.p + _l7350 * (int64_t)sizeof(uint8_t), _h7350 - _l7350 }; })));
return;
 }
(void)(f263_ow(s_2109));
return;
 }
(void)(f263_ow(f10_nm(((int64_t)(((*({ hrv *_t7354 = &(g721); int64_t _i7354 = node_2107; (S4*)_t7354->b + hr_ix(_i7354, _t7354->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:602"); }))).s_)))));
}
static void f371_gcall_args(int64_t n_2110, int64_t inst_2111, int64_t recv_2112) {
S4 x_2113 = (*({ hrv *_t7355 = &(g721); int64_t _i7355 = n_2110; (S4*)_t7355->b + hr_ix(_i7355, _t7355->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:606"); })); 
int64_t np_2114 = ((int64_t)(((*({ hrv *_t7356 = &(g721); int64_t _i7356 = ((*({ hrv *_t7357 = &(g401); int64_t _i7357 = inst_2111; (S6*)_t7357->b + hr_ix(_i7357, _t7357->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:607"); }))).node_; (S4*)_t7356->b + hr_ix(_i7356, _t7356->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:607"); }))).n_)); 
int64_t na_2115 = ((int64_t)((int64_t)((int64_t)((x_2113).n_)) + (int64_t)({ int64_t _r7358; if (((recv_2112) >= (((int64_t)0LL)))) { _r7358 = ((int64_t)1LL);  } else { _r7358 = ((int64_t)0LL);  } _r7358; }))); 
bool first_2116 = true; 
{ int64_t _e7360 = np_2114; for (int64_t _k7360 = 0; _k7360 < _e7360; _k7360++) { int64_t j_2117 = (int64_t)_k7360; int64_t pt_2118 = f213_ptype_of(inst_2111, j_2117); 
if ((!(first_2116))) { (void)(f263_ow(hr_str(", ", 2)));
 }
first_2116 = false;
if (((j_2117) >= (na_2115))) { int64_t p_2119 = f90_kid(((int64_t)(((*({ hrv *_t7364 = &(g401); int64_t _i7364 = inst_2111; (S6*)_t7364->b + hr_ix(_i7364, _t7364->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:615"); }))).node_)), j_2117); 
int64_t sa_2120 = g414; 
g414 = inst_2111;
(void)(f297_gx(((int64_t)(((*({ hrv *_t7366 = &(g721); int64_t _i7366 = p_2119; (S4*)_t7366->b + hr_ix(_i7366, _t7366->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:616"); }))).b_))));
g414 = sa_2120;
continue;
 }
int64_t c_2121 = ({ int64_t _r7367; if (((recv_2112) >= (((int64_t)0LL)))) { _r7367 = ({ int64_t _r7368; if (((j_2117) == (((int64_t)0LL)))) { _r7368 = recv_2112;  } else { _r7368 = f90_kid(n_2110, ((int64_t)((int64_t)j_2117 - (int64_t)((int64_t)1LL))));  } _r7368; });  } else { _r7367 = f90_kid(n_2110, j_2117);  } _r7367; }); 
int64_t ct0_2122 = f284_fin(c_2121); 
if ((((((*({ hrv *_t7372 = &(g568); int64_t _i7372 = pt_2118; (S1*)_t7372->b + hr_ix(_i7372, _t7372->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:621"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t7373 = &(g568); int64_t _i7373 = pt_2118; (S1*)_t7373->b + hr_ix(_i7373, _t7373->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:621"); }))).c_) < (((int32_t)0LL))))) { if ((((((*({ hrv *_t7374 = &(g568); int64_t _i7374 = ct0_2122; (S1*)_t7374->b + hr_ix(_i7374, _t7374->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:622"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t7375 = &(g568); int64_t _i7375 = ct0_2122; (S1*)_t7375->b + hr_ix(_i7375, _t7375->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:622"); }))).k_) == (((uint8_t)11LL))))) { (void)(f297_gx(c_2121));
 } else { (void)(f333_gaddr(c_2121));
 }
continue;
 }
if (f271_is_res(pt_2118)) { (void)(f272_gxo(c_2121));
continue;
 }
if (((((*({ hrv *_t7380 = &(g568); int64_t _i7380 = pt_2118; (S1*)_t7380->b + hr_ix(_i7380, _t7380->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:626"); }))).k_) == (((uint8_t)9LL)))) { (void)(f299_gas(c_2121));
continue;
 }
(void)(f297_gx(c_2121));
 } } _bk7359:; 
{ hrv *_v7384 = &(g405); for (int64_t _k7384 = 0; _k7384 < _v7384->n; _k7384++) { S13 cp_2123 = ((S13*)_v7384->b)[_k7384]; if (((((int64_t)((cp_2123).inst_))) == (inst_2111))) { if ((!(first_2116))) { (void)(f263_ow(hr_str(", ", 2)));
 }
first_2116 = false;
(void)(f372_lv_addr(((int64_t)((cp_2123).lv_))));
 }
 } } _bk7383:; 
}
static void f372_lv_addr(int64_t v_2124) {
if (((((int64_t)(((*({ hrv *_t7387 = &(g402); int64_t _i7387 = v_2124; (S12*)_t7387->b + hr_ix(_i7387, _t7387->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:125"); }))).cfn_))) != (g179))) { (void)(({ hrv *_o7388 = &(g163); hr_fs(_o7388, hr_str("c", 1)); hr_fi(_o7388, v_2124); }));
return;
 }
(void)(f263_ow(hr_str("&", 1)));
(void)(f294_lv_name(v_2124));
}
static void f373_glrcheck(void) {
(void)(f263_ow(hr_str("if (HR_UNLIKELY(hr_lr)) { ", 26)));
if (((*({ hrv *_t7392 = &(g401); int64_t _i7392 = g179; (S6*)_t7392->b + hr_ix(_i7392, _t7392->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1047"); }))).tg_) { int64_t rt_2125 = ((int64_t)(((*({ hrv *_t7393 = &(g401); int64_t _i7393 = g179; (S6*)_t7393->b + hr_ix(_i7393, _t7393->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1047"); }))).ret_)); 
(void)(({ hrv *_o7394 = &(g163); hr_fs(_o7394, hr_str("if (hr_lr == ", 13)); hr_fi(_o7394, ((int64_t)((int64_t)g179 + (int64_t)((int64_t)1LL)))); hr_fs(_o7394, hr_str(") { hr_lr = 0; ", 15)); }));
if ((((rt_2125) < (((int64_t)0LL))) || ((rt_2125) == (g575)))) { (void)(f263_ow(hr_str("return; } ", 10)));
 } else { (void)(({ hrv *_o7396 = &(g163); hr_fs(_o7396, hr_str("return _lrv", 11)); hr_fi(_o7396, g179); hr_fs(_o7396, hr_str("; } ", 4)); }));
 }
 }
(void)(f365_gdummy());
(void)(f263_ow(hr_str(" } ", 3)));
}
static void f374_gen_fn(int64_t i_2140) {
int64_t node_2141 = ((int64_t)(((*({ hrv *_t7399 = &(g401); int64_t _i7399 = i_2140; (S6*)_t7399->b + hr_ix(_i7399, _t7399->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1158"); }))).node_)); 
g414 = i_2140;
g179 = i_2140;
(void)(({ hrv *_v7400 = &(g180); _v7400->n = 0; }));
(void)(({ hrv *_v7401 = &(g181); _v7401->n = 0; }));
int64_t s0_2142 = (g163).n; 
(void)(f375_gsig(i_2140));
(void)(({ hrv *_v7403 = &(g166); hsl _s7403 = ({ hsl _t7404 = hr_sl(g163); int64_t _l7404 = s0_2142, _h7404 = _t7404.n; if (_l7404 < 0 || _h7404 < _l7404 || _h7404 > _t7404.n) hr_slerr(_l7404, _h7404, _t7404.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1163"); (hsl){ _t7404.p + _l7404 * (int64_t)sizeof(uint8_t), _h7404 - _l7404 }; }); hr_append(_v7403, _s7403.p, _s7403.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v7405 = &(g166); hsl _s7405 = hr_str(";\012", 2); hr_append(_v7405, _s7405.p, _s7405.n, sizeof(uint8_t)); }));
(void)(f263_ow(hr_str(" {\012", 3)));
int64_t fsp_2154 = (g163).n; 
int64_t du0_2155 = g195; 
{ int32_t _e7408 = ((*({ hrv *_t7409 = &(g721); int64_t _i7409 = node_2141; (S4*)_t7409->b + hr_ix(_i7409, _t7409->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1166"); }))).n_; for (int32_t _k7408 = 0; _k7408 < _e7408; _k7408++) { int32_t j_2156 = (int32_t)_k7408; int64_t p_2157 = f90_kid(node_2141, ((int64_t)(j_2156))); 
int64_t v_2158 = f160_rv(p_2157); 
if (f271_is_res(f213_ptype_of(i_2140, ((int64_t)(j_2156))))) { (void)(f263_ow(hr_str("hrv ", 4)));
(void)(f294_lv_name(v_2158));
(void)(f263_ow(hr_str(" __attribute__((cleanup(hr_rdrop))) = ", 38)));
(void)(f294_lv_name(v_2158));
(void)(f263_ow(hr_str("_in;\012", 5)));
 }
 } } _bk7407:; 
int64_t body_2159 = ((int64_t)(((*({ hrv *_t7419 = &(g721); int64_t _i7419 = node_2141; (S4*)_t7419->b + hr_ix(_i7419, _t7419->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1167"); }))).c_)); 
int64_t rt_2160 = ((int64_t)(((*({ hrv *_t7420 = &(g401); int64_t _i7420 = i_2140; (S6*)_t7420->b + hr_ix(_i7420, _t7420->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1168"); }))).ret_)); 
int64_t tl_2161 = ((int64_t)(((*({ hrv *_t7421 = &(g721); int64_t _i7421 = body_2159; (S4*)_t7421->b + hr_ix(_i7421, _t7421->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1169"); }))).a_)); 
{ int32_t _e7423 = ((*({ hrv *_t7424 = &(g721); int64_t _i7424 = body_2159; (S4*)_t7424->b + hr_ix(_i7424, _t7424->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1170"); }))).n_; for (int32_t _k7423 = 0; _k7423 < _e7423; _k7423++) { int32_t q_2162 = (int32_t)_k7423; (void)(f344_gstmt(f90_kid(body_2159, ((int64_t)(q_2162)))));
 } } _bk7422:; 
if (((tl_2161) >= (((int64_t)0LL)))) { if ((((((rt_2160) >= (((int64_t)0LL))) && ((rt_2160) != (g575))) && ((f141_at(tl_2161)) != (g575))) && (!(f143_ends(tl_2161))))) { int64_t sp_2163 = (g163).n; 
int64_t td_2164 = (g176).n; 
if (f289_is_vimg(rt_2160)) { (void)(f366_gvret(tl_2161, rt_2160));
(void)(f263_ow(hr_str("\012", 1)));
 } else { if ((((((*({ hrv *_t7432 = &(g568); int64_t _i7432 = rt_2160; (S1*)_t7432->b + hr_ix(_i7432, _t7432->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1175"); }))).k_) == (((uint8_t)14LL))) && ((((*({ hrv *_t7433 = &(g721); int64_t _i7433 = tl_2161; (S4*)_t7433->b + hr_ix(_i7433, _t7433->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1175"); }))).k_) == (((uint8_t)11LL))))) { (void)(f263_ow(hr_str("return ", 7)));
(void)(f297_gx(tl_2161));
(void)(f263_ow(hr_str(";\012", 2)));
 } else { (void)(f263_ow(hr_str("return ", 7)));
if (f271_is_res(rt_2160)) { (void)(f363_gmove(tl_2161));
 } else { (void)(f297_gx(tl_2161));
 }
(void)(f263_ow(hr_str(";\012", 2)));
 }
 }
if ((((g176).n) > (td_2164))) { (void)(({ hrv *_v7442 = &(g177); _v7442->n = 0; }));
(void)(({ hrv *_v7443 = &(g177); hsl _s7443 = ({ hsl _t7444 = hr_sl(g163); int64_t _l7444 = sp_2163, _h7444 = _t7444.n; if (_l7444 < 0 || _h7444 < _l7444 || _h7444 > _t7444.n) hr_slerr(_l7444, _h7444, _t7444.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1177"); (hsl){ _t7444.p + _l7444 * (int64_t)sizeof(uint8_t), _h7444 - _l7444 }; }); hr_append(_v7443, _s7443.p, _s7443.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v7445 = &(g163); int64_t _k7445 = sp_2163; if (_k7445 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1177"); hr_resize(_v7445, _k7445, sizeof(uint8_t)); }));
(void)(f263_ow(hr_str("{ ", 2)));
(void)(({ hrv *_v7447 = &(g163); hsl _s7447 = ({ hsl _t7448 = hr_sl(g176); int64_t _l7448 = td_2164, _h7448 = _t7448.n; if (_l7448 < 0 || _h7448 < _l7448 || _h7448 > _t7448.n) hr_slerr(_l7448, _h7448, _t7448.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1177"); (hsl){ _t7448.p + _l7448 * (int64_t)sizeof(uint8_t), _h7448 - _l7448 }; }); hr_append(_v7447, _s7447.p, _s7447.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v7449 = &(g176); int64_t _k7449 = td_2164; if (_k7449 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1177"); hr_resize(_v7449, _k7449, sizeof(uint8_t)); }));
(void)(({ hrv *_v7450 = &(g163); hsl _s7450 = ({ hsl _t7451 = hr_sl(g177); int64_t _l7451 = 0, _h7451 = _t7451.n; if (_l7451 < 0 || _h7451 < _l7451 || _h7451 > _t7451.n) hr_slerr(_l7451, _h7451, _t7451.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1177"); (hsl){ _t7451.p + _l7451 * (int64_t)sizeof(uint8_t), _h7451 - _l7451 }; }); hr_append(_v7450, _s7450.p, _s7450.n, sizeof(uint8_t)); }));
(void)(f263_ow(hr_str("}\012", 2)));
 }
 } else { (void)(f344_gstmt(tl_2161));
 }
 }
(void)(f263_ow(hr_str("}\012", 2)));
if ((((g195) > (du0_2155)) || f289_is_vimg(rt_2160))) { (void)(({ hrv *_v7456 = &(g196); _v7456->n = 0; }));
(void)(({ hrv *_v7457 = &(g196); hsl _s7457 = ({ hsl _t7458 = hr_sl(g163); int64_t _l7458 = fsp_2154, _h7458 = _t7458.n; if (_l7458 < 0 || _h7458 < _l7458 || _h7458 > _t7458.n) hr_slerr(_l7458, _h7458, _t7458.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1181"); (hsl){ _t7458.p + _l7458 * (int64_t)sizeof(uint8_t), _h7458 - _l7458 }; }); hr_append(_v7457, _s7457.p, _s7457.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v7459 = &(g163); int64_t _k7459 = fsp_2154; if (_k7459 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1181"); hr_resize(_v7459, _k7459, sizeof(uint8_t)); }));
(void)(f263_ow(({ hsl _r7461; if (f289_is_vimg(rt_2160)) { _r7461 = hr_str("int64_t _fm __attribute__((cleanup(hr_dsf))) = hr_ds.n;\012", 56);  } else { _r7461 = hr_str("int64_t _fm __attribute__((cleanup(hr_dsr))) = hr_ds.n;\012", 56);  } _r7461; })));
(void)(({ hrv *_v7463 = &(g163); hsl _s7463 = ({ hsl _t7464 = hr_sl(g196); int64_t _l7464 = 0, _h7464 = _t7464.n; if (_l7464 < 0 || _h7464 < _l7464 || _h7464 > _t7464.n) hr_slerr(_l7464, _h7464, _t7464.n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1181"); (hsl){ _t7464.p + _l7464 * (int64_t)sizeof(uint8_t), _h7464 - _l7464 }; }); hr_append(_v7463, _s7463.p, _s7463.n, sizeof(uint8_t)); }));
 }
}
static void f375_gsig(int64_t i_2143) {
int64_t rt_2144 = ((int64_t)(((*({ hrv *_t7465 = &(g401); int64_t _i7465 = i_2143; (S6*)_t7465->b + hr_ix(_i7465, _t7465->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1137"); }))).ret_)); 
(void)(f263_ow(hr_str("static ", 7)));
if (((rt_2144) < (((int64_t)0LL)))) { (void)(f263_ow(hr_str("void", 4)));
 } else { (void)(f264_ct(rt_2144));
 }
(void)(f263_ow(hr_str(" ", 1)));
(void)(f332_fn_cname(i_2143));
(void)(f263_ow(hr_str("(", 1)));
int64_t node_2145 = ((int64_t)(((*({ hrv *_t7472 = &(g401); int64_t _i7472 = i_2143; (S6*)_t7472->b + hr_ix(_i7472, _t7472->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1141"); }))).node_)); 
bool first_2146 = true; 
int64_t sa_2147 = g414; 
g414 = i_2143;
{ int32_t _e7474 = ((*({ hrv *_t7475 = &(g721); int64_t _i7475 = node_2145; (S4*)_t7475->b + hr_ix(_i7475, _t7475->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1144"); }))).n_; for (int32_t _k7474 = 0; _k7474 < _e7474; _k7474++) { int32_t j_2148 = (int32_t)_k7474; int64_t p_2149 = f90_kid(node_2145, ((int64_t)(j_2148))); 
int64_t v_2150 = f160_rv(p_2149); 
if ((!(first_2146))) { (void)(f263_ow(hr_str(", ", 2)));
 }
first_2146 = false;
int64_t t_2151 = f213_ptype_of(i_2143, ((int64_t)(j_2148))); 
(void)(f264_ct(t_2151));
(void)(f263_ow(hr_str(" ", 1)));
(void)(f294_lv_name(v_2150));
if (f271_is_res(t_2151)) { (void)(f263_ow(hr_str("_in", 3)));
 }
 } } _bk7473:; 
g414 = sa_2147;
{ hrv *_v7486 = &(g405); for (int64_t _k7486 = 0; _k7486 < _v7486->n; _k7486++) { S13 cp_2152 = ((S13*)_v7486->b)[_k7486]; if (((((int64_t)((cp_2152).inst_))) == (i_2143))) { if ((!(first_2146))) { (void)(f263_ow(hr_str(", ", 2)));
 }
first_2146 = false;
int64_t v_2153 = ((int64_t)((cp_2152).lv_)); 
(void)(f264_ct(((int64_t)(((*({ hrv *_t7489 = &(g402); int64_t _i7489 = v_2153; (S12*)_t7489->b + hr_ix(_i7489, _t7489->n, "/home/anmire/ai/amni-lang/helium-self/hc/gen.amni:1153"); }))).ty_))));
(void)(f263_ow(({ hsl _r7491; if (f293_lv_isptr(v_2153)) { _r7491 = hr_str(" **c", 4);  } else { _r7491 = hr_str(" *c", 3);  } _r7491; })));
(void)(f302_oi(v_2153));
 }
 } } _bk7485:; 
if (first_2146) { (void)(f263_ow(hr_str("void", 4)));
 }
(void)(f263_ow(hr_str(")", 1)));
}
static void hr_init_globals(void) {
g871 = ({ A25 _t1; _t1.e[0] = hr_str("import", 6); _t1.e[1] = hr_str("namespace", 9); _t1.e[2] = hr_str("struct", 6); _t1.e[3] = hr_str("enum", 4); _t1.e[4] = hr_str("type", 4); _t1.e[5] = hr_str("fn", 2); _t1.e[6] = hr_str("thread_fn", 9); _t1.e[7] = hr_str("export", 6); _t1.e[8] = hr_str("simd", 4); _t1.e[9] = hr_str("recursive", 9); _t1.e[10] = hr_str("let", 3); _t1.e[11] = hr_str("var", 3); _t1.e[12] = hr_str("extern", 6); _t1.e[13] = hr_str("const", 5); _t1.e[14] = hr_str("pad", 3); _t1.e[15] = hr_str("reusable", 8); _t1.e[16] = hr_str("if", 2); _t1.e[17] = hr_str("else", 4); _t1.e[18] = hr_str("while", 5); _t1.e[19] = hr_str("for", 3); _t1.e[20] = hr_str("in", 2); _t1.e[21] = hr_str("loop", 4); _t1.e[22] = hr_str("block", 5); _t1.e[23] = hr_str("guard", 5); _t1.e[24] = hr_str("match", 5); _t1.e[25] = hr_str("return", 6); _t1.e[26] = hr_str("break", 5); _t1.e[27] = hr_str("continue", 8); _t1.e[28] = hr_str("as", 2); _t1.e[29] = hr_str("true", 4); _t1.e[30] = hr_str("false", 5); _t1.e[31] = hr_str("null", 4); _t1.e[32] = hr_str("self", 4); _t1.e[33] = hr_str("bool", 4); _t1.e[34] = hr_str("varint", 6); _t1.e[35] = hr_str("i8", 2); _t1.e[36] = hr_str("i16", 3); _t1.e[37] = hr_str("i32", 3); _t1.e[38] = hr_str("i64", 3); _t1.e[39] = hr_str("u8", 2); _t1.e[40] = hr_str("u16", 3); _t1.e[41] = hr_str("u32", 3); _t1.e[42] = hr_str("u64", 3); _t1.e[43] = hr_str("f32", 3); _t1.e[44] = hr_str("f64", 3); _t1.e[45] = hr_str("int", 3); _t1.e[46] = hr_str("uint", 4); _t1.e[47] = hr_str("byte", 4); _t1.e[48] = hr_str("real", 4); _t1; });
g738 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g739 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g740 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g741 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g742 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g743 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g744 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g745 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g746 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g747 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g734 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g733 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g416 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g414 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g415 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g494 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g363 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g183 = ({ A62 _t2; _t2.e[0] = hr_str("int8_t", 6); _t2.e[1] = hr_str("int16_t", 7); _t2.e[2] = hr_str("int32_t", 7); _t2.e[3] = hr_str("int64_t", 7); _t2.e[4] = hr_str("uint8_t", 7); _t2.e[5] = hr_str("uint16_t", 8); _t2.e[6] = hr_str("uint32_t", 8); _t2.e[7] = hr_str("uint64_t", 8); _t2; });
g179 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g195 = ((int64_t)0LL);
g114 = ({ A104 _t3; _t3.e[0] = ((double)1e0); _t3.e[1] = ((double)1e1); _t3.e[2] = ((double)1e2); _t3.e[3] = ((double)1e3); _t3.e[4] = ((double)1e4); _t3.e[5] = ((double)1e5); _t3.e[6] = ((double)1e6); _t3.e[7] = ((double)1e7); _t3.e[8] = ((double)1e8); _t3.e[9] = ((double)1e9); _t3.e[10] = ((double)1e10); _t3.e[11] = ((double)1e11); _t3.e[12] = ((double)1e12); _t3.e[13] = ((double)1e13); _t3.e[14] = ((double)1e14); _t3.e[15] = ((double)1e15); _t3.e[16] = ((double)1e16); _t3.e[17] = ((double)1e17); _t3.e[18] = ((double)1e18); _t3.e[19] = ((double)1e19); _t3.e[20] = ((double)1e20); _t3.e[21] = ((double)1e21); _t3.e[22] = ((double)1e22); _t3; });
g154 = ((hrv){0});
g301 = ((int64_t)1LL);
g302 = ((int64_t)2LL);
g303 = ((int64_t)3LL);
g304 = ((int64_t)4LL);
g305 = ((int64_t)5LL);
g306 = ((int64_t)6LL);
g307 = ((int64_t)7LL);
g308 = ((int64_t)8LL);
g309 = ((int64_t)9LL);
g310 = ((int64_t)20LL);
g311 = ((int64_t)21LL);
g312 = ((int64_t)22LL);
g313 = ((int64_t)23LL);
g314 = ((int64_t)24LL);
g315 = ((int64_t)25LL);
g316 = ((int64_t)26LL);
g317 = ((int64_t)27LL);
g318 = ((int64_t)30LL);
g319 = ((int64_t)31LL);
g320 = ((int64_t)32LL);
g321 = ((int64_t)33LL);
g374 = ((int64_t)0LL);
g375 = ((int64_t)1LL);
g376 = ((int64_t)2LL);
g377 = ((int64_t)3LL);
g378 = ((int64_t)4LL);
g379 = ((int64_t)5LL);
g380 = ((int64_t)6LL);
g381 = ((int64_t)7LL);
g382 = ((int64_t)8LL);
g383 = ((int64_t)9LL);
g384 = ((int64_t)10LL);
g385 = ((int64_t)11LL);
g386 = ((int64_t)12LL);
g387 = ((int64_t)13LL);
g388 = ((int64_t)14LL);
g389 = ((int64_t)1LL);
g390 = ((int64_t)2LL);
g391 = ((int64_t)4LL);
g392 = ((int64_t)8LL);
g393 = ((int64_t)16LL);
g394 = ((int64_t)32LL);
g395 = ((int64_t)64LL);
g396 = ((int64_t)2LL);
g413 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g419 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g499 = ((int64_t)1LL);
g500 = ((int64_t)2LL);
g501 = ((int64_t)3LL);
g502 = ((int64_t)4LL);
g503 = ((int64_t)5LL);
g538 = ((int64_t)0LL);
g539 = ((int64_t)1LL);
g540 = ((int64_t)2LL);
g541 = ((int64_t)3LL);
g542 = ((int64_t)4LL);
g543 = ((int64_t)5LL);
g544 = ((int64_t)6LL);
g545 = ((int64_t)7LL);
g546 = ((int64_t)8LL);
g547 = ((int64_t)9LL);
g548 = ((int64_t)10LL);
g549 = ((int64_t)11LL);
g550 = ((int64_t)12LL);
g551 = ((int64_t)13LL);
g552 = ((int64_t)14LL);
g553 = ((int64_t)15LL);
g554 = ((int64_t)16LL);
g555 = ((int64_t)17LL);
g556 = ((int64_t)18LL);
g557 = ((int64_t)19LL);
g558 = ((int64_t)1LL);
g559 = ((int64_t)2LL);
g560 = ((int64_t)0LL);
g561 = ((int64_t)1LL);
g562 = ((int64_t)2LL);
g643 = ((int64_t)1LL);
g644 = ((int64_t)2LL);
g645 = ((int64_t)3LL);
g646 = ((int64_t)4LL);
g647 = ((int64_t)5LL);
g648 = ((int64_t)6LL);
g649 = ((int64_t)7LL);
g650 = ((int64_t)8LL);
g651 = ((int64_t)9LL);
g652 = ((int64_t)10LL);
g653 = ((int64_t)11LL);
g654 = ((int64_t)12LL);
g655 = ((int64_t)13LL);
g656 = ((int64_t)14LL);
g657 = ((int64_t)15LL);
g658 = ((int64_t)16LL);
g659 = ((int64_t)17LL);
g660 = ((int64_t)18LL);
g661 = ((int64_t)19LL);
g662 = ((int64_t)20LL);
g663 = ((int64_t)21LL);
g664 = ((int64_t)22LL);
g665 = ((int64_t)23LL);
g666 = ((int64_t)24LL);
g667 = ((int64_t)25LL);
g668 = ((int64_t)26LL);
g669 = ((int64_t)27LL);
g670 = ((int64_t)28LL);
g671 = ((int64_t)29LL);
g672 = ((int64_t)30LL);
g673 = ((int64_t)31LL);
g674 = ((int64_t)32LL);
g675 = ((int64_t)33LL);
g676 = ((int64_t)34LL);
g677 = ((int64_t)35LL);
g678 = ((int64_t)36LL);
g679 = ((int64_t)37LL);
g680 = ((int64_t)40LL);
g681 = ((int64_t)41LL);
g682 = ((int64_t)42LL);
g683 = ((int64_t)43LL);
g684 = ((int64_t)44LL);
g685 = ((int64_t)45LL);
g686 = ((int64_t)46LL);
g687 = ((int64_t)47LL);
g688 = ((int64_t)48LL);
g689 = ((int64_t)50LL);
g690 = ((int64_t)51LL);
g691 = ((int64_t)52LL);
g692 = ((int64_t)53LL);
g693 = ((int64_t)54LL);
g694 = ((int64_t)55LL);
g695 = ((int64_t)56LL);
g696 = ((int64_t)57LL);
g697 = ((int64_t)58LL);
g698 = ((int64_t)1LL);
g699 = ((int64_t)2LL);
g700 = ((int64_t)3LL);
g701 = ((int64_t)4LL);
g702 = ((int64_t)5LL);
g703 = ((int64_t)1LL);
g704 = ((int64_t)2LL);
g705 = ((int64_t)4LL);
g706 = ((int64_t)8LL);
g707 = ((int64_t)16LL);
g708 = ((int64_t)32LL);
g709 = ((int64_t)64LL);
g710 = ((int64_t)128LL);
g711 = ((int64_t)256LL);
g712 = ((int64_t)512LL);
g713 = ((int64_t)1LL);
g714 = ((int64_t)2LL);
g715 = ((int64_t)4LL);
g716 = ((int64_t)8LL);
g717 = ((int64_t)16LL);
g718 = ((int64_t)32LL);
g719 = ((int64_t)64LL);
g814 = ((int64_t)0LL);
g815 = ((int64_t)1LL);
g816 = ((int64_t)2LL);
g817 = ((int64_t)3LL);
g818 = ((int64_t)4LL);
g819 = ((int64_t)5LL);
g820 = ((int64_t)6LL);
g821 = ((int64_t)7LL);
g822 = ((int64_t)8LL);
g823 = ((int64_t)9LL);
g824 = ((int64_t)10LL);
g825 = ((int64_t)11LL);
g826 = ((int64_t)12LL);
g827 = ((int64_t)13LL);
g828 = ((int64_t)14LL);
g829 = ((int64_t)15LL);
g830 = ((int64_t)16LL);
g831 = ((int64_t)17LL);
g832 = ((int64_t)18LL);
g833 = ((int64_t)19LL);
g834 = ((int64_t)20LL);
g835 = ((int64_t)21LL);
g836 = ((int64_t)22LL);
g837 = ((int64_t)23LL);
g838 = ((int64_t)24LL);
g839 = ((int64_t)25LL);
g840 = ((int64_t)26LL);
g841 = ((int64_t)27LL);
g842 = ((int64_t)28LL);
g843 = ((int64_t)29LL);
g844 = ((int64_t)30LL);
g845 = ((int64_t)31LL);
g846 = ((int64_t)32LL);
g847 = ((int64_t)33LL);
g848 = ((int64_t)34LL);
g849 = ((int64_t)35LL);
g850 = ((int64_t)36LL);
g851 = ((int64_t)37LL);
g852 = ((int64_t)38LL);
g853 = ((int64_t)39LL);
g854 = ((int64_t)40LL);
g855 = ((int64_t)41LL);
g856 = ((int64_t)42LL);
g857 = ((int64_t)43LL);
g858 = ((int64_t)44LL);
g859 = ((int64_t)45LL);
g860 = ((int64_t)46LL);
g861 = ((int64_t)47LL);
g862 = ((int64_t)48LL);
g863 = ((int64_t)49LL);
g864 = ((int64_t)50LL);
g865 = ((int64_t)51LL);
g866 = ((int64_t)52LL);
g867 = ((int64_t)53LL);
g868 = ((int64_t)54LL);
g869 = ((int64_t)55LL);
g870 = ((int64_t)56LL);
g872 = ((int64_t)56LL);
g873 = ((int64_t)57LL);
g874 = ((int64_t)58LL);
g875 = ((int64_t)59LL);
g876 = ((int64_t)60LL);
g877 = ((int64_t)61LL);
g878 = ((int64_t)62LL);
g879 = ((int64_t)63LL);
g880 = ((int64_t)64LL);
g881 = ((int64_t)65LL);
g882 = ((int64_t)66LL);
g883 = ((int64_t)67LL);
g884 = ((int64_t)68LL);
g885 = ((int64_t)69LL);
g886 = ((int64_t)70LL);
g887 = ((int64_t)71LL);
g888 = ((int64_t)72LL);
g889 = ((int64_t)73LL);
g890 = ((int64_t)74LL);
g891 = ((int64_t)75LL);
g892 = ((int64_t)76LL);
g893 = ((int64_t)77LL);
g894 = ((int64_t)78LL);
g895 = ((int64_t)79LL);
g896 = ((int64_t)80LL);
g897 = ((int64_t)81LL);
g898 = ((int64_t)82LL);
g899 = ((int64_t)83LL);
g900 = ((int64_t)84LL);
g901 = ((int64_t)85LL);
g902 = ((int64_t)86LL);
g903 = ((int64_t)87LL);
g904 = ((int64_t)88LL);
g905 = ((int64_t)89LL);
g906 = ((int64_t)90LL);
g907 = ((int64_t)91LL);
g908 = ((int64_t)92LL);
g909 = ((int64_t)93LL);
g910 = ((int64_t)94LL);
g911 = ((int64_t)95LL);
g912 = ((int64_t)96LL);
g913 = ((int64_t)97LL);
g914 = ((int64_t)98LL);
g915 = ((int64_t)99LL);
g916 = ((int64_t)100LL);
g917 = ((int64_t)101LL);
g918 = ((int64_t)102LL);
g919 = ((int64_t)103LL);
g920 = ((int64_t)104LL);
g921 = ((int64_t)49LL);
}
static void hr_main(void) { f1_main(); }
