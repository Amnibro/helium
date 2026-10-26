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
static void f239_cands_add(int64_t name_1267, int64_t ns_1268);
static bool f240_is_std_node(int64_t node_1277);
static int64_t f241_ck_builtin(int64_t n_1280, int64_t b_1281, int64_t recv_1282, int64_t want_1283);
static int64_t f242_arg(int64_t i_1286, int64_t *c1282, int64_t *c1280);
static int64_t f243_call_fn(int64_t n_1313, int64_t name_1314, int64_t recv_1315, int64_t want_1316);
static M94 f244_resolve(int64_t n_1320, int64_t name_1321, int64_t ns_1322, int64_t a0_1323, int64_t an_1324, int64_t blk_1325, int64_t tyargs_1326, bool report_1327);
static bool f245_match_ty(int64_t tn0_1351, int64_t t0_1352, int64_t g0_1353);
static int64_t f246_pend_default(int64_t a_1366);
static int64_t f247_arg_rank(int64_t n_1379, int64_t a_1380, int64_t p_1381);
static bool f248_is_construct(int64_t n_1389);
static bool f249_untyped_any(int64_t f_1392);
static int64_t f250_get_inst(int64_t node_1402, int64_t b0_1403, int64_t bn_1404, int64_t blk_1405, int64_t bown_1406);
static bool f251_same_binds(int64_t i_1410, int64_t b0_1411, int64_t bn_1412);
static int64_t f252_member_of(hsl name_1426);
static int64_t f253_ck_slit(int64_t n_1429, int64_t want_1430);
static bool f254_ORD_HAS(int64_t d_1453);
static void f255_propagate_calls(void);
static bool f256_gen_program(hrv* out_1465);
static void f257_ow(hsl s_1469);
static void f258_ct(int64_t t_1470);
static void f259_cbody(int64_t t_1471);
static void f260_cn_grow(void);
static hsl f261_cn(int64_t t_1474);
static void f262_cn_make(int64_t t_1475);
static void f263_fwd(int64_t s0_1484);
static void f264_fname_into(hrv* b_1496, int64_t name_1497);
static bool f265_is_res(int64_t t_1517);
static void f266_gxo(int64_t n_1518);
static void f267_gcv(int64_t n_1521, int64_t f_1522, int64_t t_1523);
static void f268_gx1(int64_t n_1524);
static bool f269_is_place(int64_t n_1525);
static int64_t f270_tmp(int64_t t_1530, bool clean_1531);
static void f271_ot(int64_t k_1533);
static void f272_gx0(int64_t n_1534);
static int64_t f273_fin_lit(int64_t n_1537);
static void f274_oint(int64_t v_1539, bool uns_1540, int64_t t_1541);
static void f275_gstr(int64_t n_1544);
static int64_t f276_fin(int64_t n_1545);
static hsl f277_tok_str(int64_t t_1549);
static void f278_cstr_lit(hsl s_1553);
static bool f279_is_fix(int64_t t_1555);
static bool f280_is_lim(int64_t t_1556);
static void f281_lv_expr(int64_t v_1558);
static bool f282_lv_isptr(int64_t v_1559);
static void f283_lv_name(int64_t v_1561);
static void f284_gerr(int64_t n_1563, hsl m_1564);
static void f285_gbin(int64_t n_1566);
static void f286_gx(int64_t n_1571);
static hsl f287_cmp_op(int64_t o_1578);
static void f288_gas(int64_t n_1579);
static void f289_gsl(int64_t n_1582, int64_t f_1583);
static int64_t f290_nt(void);
static void f291_oi(int64_t v_1587);
static void f292_gen_heq(int64_t t_1593);
static void f293_comp_pre(int64_t t_1597, bool fmt_1598);
static void f294_comp_one(int64_t t_1604, bool fmt_1605);
static bool f295_need_helper(int64_t t_1607);
static void f296_gen_hf(int64_t t_1609);
static void f297_hf_pre(int64_t t_1613);
static void f298_hh(hsl s_1616);
static void f299_hf_val(int64_t t_1624, hsl e_1625);
static void f300_heq_val(int64_t t_1668, hsl a_1669, hsl b_1670);
static bool f301_hsl_ty(int64_t t_1681);
static void f302_gxas(int64_t n_1682, int64_t t_1683);
static void f303_garith(int64_t o_1686, int64_t t0_1687, int64_t a_1688, int64_t b_1689, int64_t tv_1690, int64_t loc_1691);
static void f304_gopnd(int64_t n_1697, int64_t tv_1698);
static void f305_gen_hop(int64_t t_1699, int64_t o_1700, int64_t bt_1701);
static void f306_hop_body(int64_t t_1707, int64_t o_1708, hsl r_1709, hsl a_1710, hsl b_1711, bool sc_1712);
static hsl f307_ar_op(int64_t o_1714);
static void f308_wloc(int64_t n_1728);
static void f309_gun(int64_t n_1731);
static void f310_gen_hneg(int64_t t_1736);
static void f311_gidx(int64_t n_1750);
static void f312_gslice(int64_t n_1758);
static void f313_garr(int64_t n_1766);
static void f314_gslit(int64_t n_1773);
static void f315_gcall(int64_t n_1785);
static void f316_gbuiltin(int64_t n_1787);
static int64_t f317_arg(int64_t i_1793, int64_t *c1791, int64_t *c1787);
static void f318_gfmt(hsl o_1797, int64_t n_1798, int64_t t_1799, bool top_1800);
static void f319_grecv_ptr(int64_t r_1807);
static void f320_esz(int64_t t_1821);
static void f321_gaddr(int64_t n_1825);
static void f322_heq_val_o(int64_t e_1834, int64_t p_1835);
static void f323_heq_o(int64_t e_1838, hsl a_1839, hsl b_1840);
static void f324_heq_pre(int64_t t_1841);
static bool f325_scalar_ty(int64_t t_1842);
static void f326_heq_val_s(int64_t e_1845, int64_t p_1846);
static void f327_heq_val_r(int64_t e_1849, int64_t p_1850);
static void f328_gblkcall(int64_t n_1853);
static void f329_gstmt(int64_t n_1865);
static void f330_gvdecl(int64_t n_1871);
static void f331_decl_lv(int64_t v_1879);
static void f332_gstmt1(int64_t n_1890);
static void f333_gassign(int64_t n_1893);
static int64_t f334_base_op(int64_t o_1906);
static void f335_gif(int64_t n_1909, int64_t res_1910);
static void f336_gblk(int64_t b_1914, int64_t res_1915, bool val_1916);
static void f337_gtail(int64_t tl_1918, int64_t res_1919);
static void f338_gwhile(int64_t n_1922);
static int64_t f339_lbl_push(int64_t res_1924);
static void f340_lbl_pop(int64_t l_1927);
static void f341_gloop(int64_t n_1928, int64_t res_1929);
static void f342_gfor(int64_t n_1931);
static void f343_gmatch(int64_t n_1946, int64_t res_1947);
static void f344_geblock(int64_t n_1969, int64_t res_1970);
static void f345_gret(int64_t n_1972);
static void f346_gmove(int64_t c_1978);
static bool f347_movable_local(int64_t c_1979);
static void f348_gdummy(void);
static void f349_gbreak(int64_t n_1990);
static bool f350_owned(int64_t n_1994);
static bool f351_is_ext(int64_t i_1998);
static void f352_ext_name(int64_t i_2003);
static void f353_fn_cname(int64_t i_2007);
static void f354_gcall_args(int64_t n_2010, int64_t inst_2011, int64_t recv_2012);
static void f355_lv_addr(int64_t v_2024);
static void f356_glrcheck(void);
static void f357_gen_fn(int64_t i_2040);
static void f358_gsig(int64_t i_2043);
static hrv g485;
static hrv g903;
static A25 g846;
static hrv g904;
static hrv g901;
static int64_t g713;
static int64_t g714;
static int64_t g715;
static int64_t g716;
static int64_t g717;
static int64_t g718;
static int64_t g719;
static int64_t g720;
static int64_t g721;
static int64_t g722;
static hrv g543;
static int64_t g567;
static hrv g545;
static hrv g544;
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
static int64_t g563;
static int64_t g564;
static int64_t g565;
static int64_t g566;
static int64_t g569;
static int64_t g570;
static int64_t g568;
static hrv g484;
static hrv g905;
static hrv g699;
static hrv g906;
static hrv g907;
static hrv g900;
static hrv g902;
static hrv g702;
static int64_t g701;
static int64_t g709;
static int64_t g708;
static int64_t g703;
static bool g704;
static hrv g696;
static hrv g698;
static bool g748;
static hrv g710;
static hrv g697;
static bool g705;
static bool g706;
static bool g707;
static hrv g711;
static hrv g700;
static hrv g487;
static hrv g488;
static hrv g482;
static hrv g481;
static hrv g486;
static int64_t g395;
static hrv g380;
static hrv g387;
static hrv g386;
static hrv g388;
static hrv g389;
static hrv g390;
static hrv g391;
static int64_t g393;
static int64_t g394;
static int64_t g397;
static hrv g396;
static hrv g442;
static hrv g443;
static hrv g548;
static hrv g549;
static hrv g546;
static hrv g483;
static hrv g547;
static hrv g428;
static hrv g382;
static hrv g381;
static hrv g384;
static hrv g429;
static hrv g383;
static hrv g310;
static int64_t g399;
static hrv g460;
static hrv g400;
static hrv g314;
static hrv g385;
static hrv g311;
static hrv g312;
static hrv g401;
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
static int64_t g288;
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
static hrv g313;
static int64_t g354;
static int64_t g355;
static int64_t g356;
static int64_t g357;
static int64_t g358;
static int64_t g359;
static int64_t g360;
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
static int64_t g392;
static int64_t g398;
static int64_t g474;
static int64_t g475;
static int64_t g476;
static int64_t g477;
static int64_t g478;
static int64_t g513;
static int64_t g514;
static int64_t g515;
static int64_t g516;
static int64_t g517;
static int64_t g518;
static int64_t g519;
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
static int64_t g610;
static int64_t g618;
static int64_t g619;
static int64_t g620;
static int64_t g621;
static int64_t g622;
static int64_t g623;
static int64_t g624;
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
static int64_t g789;
static int64_t g790;
static int64_t g791;
static int64_t g792;
static int64_t g793;
static int64_t g794;
static int64_t g795;
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
(void)(({ hrv *_v15 = &(g485); hsl _s15 = hr_sl(lib_2); hr_append(_v15, _s15.p, _s15.n, sizeof(uint8_t)); }));
if ((!(f5_load_program(hr_sl(a_0))))) { (void)(({ hr_fs(&hr_ob, hr_sl(g487)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((!(f104_check_program()))) { (void)(({ hr_fs(&hr_ob, hr_sl(g396)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((((g487).n) > (((int64_t)0LL)))) { (void)(({ hr_fs(&hr_ob, hr_sl(g487)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
hrv c_1464 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(f256_gen_program((&(c_1464)))))) { (void)(({ hr_fs(&hr_ob, hr_sl(g182)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((!(hr_os_write_file(hr_sl(o_1), hr_sl(c_1464))))) { (void)(({ hr_fs(&hr_ob, hr_str("cannot write ", 13)); hr_fs(&hr_ob, hr_sl(o_1)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
}
static bool f5_load_program(hsl root_3) {
(void)(f6_parse_init());
(void)(f11_types_init());
int64_t d_38 = (root_3).n; 
while ((((d_38) > (((int64_t)0LL))) && (((*({ hsl _t34 = root_3; int64_t _i34 = ((int64_t)((int64_t)d_38 - (int64_t)((int64_t)1LL))); (uint8_t*)_t34.p + hr_ix(_i34, _t34.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:68"); }))) != (((uint8_t)47LL))))) { d_38--;
 } _bk33:; 
(void)(({ hrv *_v35 = &(g484); _v35->n = 0; }));
(void)(({ hrv *_v36 = &(g484); hsl _s36 = ({ hsl _r37; if (((d_38) > (((int64_t)0LL)))) { _r37 = ({ hsl _t38 = root_3; int64_t _l38 = 0, _h38 = ((int64_t)((int64_t)d_38 - (int64_t)((int64_t)1LL))); if (_l38 < 0 || _h38 < _l38 || _h38 > _t38.n) hr_slerr(_l38, _h38, _t38.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:69"); (hsl){ _t38.p + _l38 * (int64_t)sizeof(uint8_t), _h38 - _l38 }; });  } else { _r37 = hr_str(".", 1);  } _r37; }); hr_append(_v36, _s36.p, _s36.n, sizeof(uint8_t)); }));
return (((f19_try_load(root_3)) >= (((int64_t)0LL))) && (((g487).n) == (((int64_t)0LL))));
}
static void f6_parse_init(void) {
(void)(f7_lex_init());
if (((g713) < (((int64_t)0LL)))) { g713 = f8_intern(hr_str("from", 4));
g714 = f8_intern(hr_str("inline", 6));
g715 = f8_intern(hr_str("checkfree", 9));
g716 = f8_intern(hr_str("lut", 3));
g717 = f8_intern(hr_str("_", 1));
g718 = f8_intern(hr_str("upto", 4));
g719 = f8_intern(hr_str("fields", 6));
g720 = f8_intern(hr_str("types", 5));
g721 = f8_intern(hr_str("variants", 8));
g722 = f8_intern(hr_str("std", 3));
 }
}
static void f7_lex_init(void) {
if ((((g903).n) == (((int64_t)0LL)))) { { hsl _v52 = ({ A25 *_t53 = &(g846); (hsl){ (uint8_t*)_t53->e, 49 }; }); for (int64_t _k52 = 0; _k52 < _v52.n; _k52++) { hsl k_4 = ((hsl*)_v52.p)[_k52]; (void)(f8_intern(k_4));
 } } _bk51:; 
 }
}
static int64_t f8_intern(hsl s_5) {
if ((((g904).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v55 = &(g904); int64_t _k55 = ((int64_t)((((int64_t)1LL)) << ((((int64_t)16LL)) & 63))); if (_k55 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:32"); int32_t _x55 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o55 = _v55->n; hr_resize(_v55, _k55, sizeof _x55); for (int64_t _j = _o55; _j < _k55; _j++) ((int32_t*)_v55->b)[_j] = _x55; }));
 }
if (((((int64_t)((int64_t)(g903).n * (int64_t)((int64_t)2LL)))) >= ((g904).n))) { int64_t n_6 = ((int64_t)((int64_t)(g904).n * (int64_t)((int64_t)2LL))); 
(void)(({ hrv *_v56 = &(g904); _v56->n = 0; }));
(void)(({ hrv *_v57 = &(g904); int64_t _k57 = n_6; if (_k57 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:35"); int32_t _x57 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o57 = _v57->n; hr_resize(_v57, _k57, sizeof _x57); for (int64_t _j = _o57; _j < _k57; _j++) ((int32_t*)_v57->b)[_j] = _x57; }));
{ hrv *_v59 = &(g903); for (int64_t _k59 = 0; _k59 < _v59->n; _k59++) { S0 x_7 = ((S0*)_v59->b)[_k59]; int64_t i_8 = (int64_t)_k59; int64_t j_12 = ((int64_t)((int64_t)((int64_t)(f9_hash(({ hsl _t61 = hr_sl(g901); int64_t _l61 = ((int64_t)((x_7).s_)), _h61 = ((int64_t)(((int32_t)((int64_t)(x_7).s_ + (int64_t)(x_7).n_)))); if (_l61 < 0 || _h61 < _l61 || _h61 > _t61.n) hr_slerr(_l61, _h61, _t61.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:36"); (hsl){ _t61.p + _l61 * (int64_t)sizeof(uint8_t), _h61 - _l61 }; })))) & (int64_t)((int64_t)((int64_t)n_6 - (int64_t)((int64_t)1LL))))); 
while ((((*({ hrv *_t63 = &(g904); int64_t _i63 = j_12; (int32_t*)_t63->b + hr_ix(_i63, _t63->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:36"); }))) >= (((int32_t)0LL)))) { j_12 = ((int64_t)((int64_t)((int64_t)((int64_t)j_12 + (int64_t)((int64_t)1LL))) & (int64_t)((int64_t)((int64_t)n_6 - (int64_t)((int64_t)1LL)))));
 } _bk62:; 
{ int32_t *_t64 = &((*({ hrv *_t65 = &(g904); int64_t _i65 = j_12; (int32_t*)_t65->b + hr_ix(_i65, _t65->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:36"); }))); *_t64 = ((int32_t)(i_8)); }
 } } _bk58:; 
 }
int64_t m_13 = ((int64_t)((int64_t)(g904).n - (int64_t)((int64_t)1LL))); 
int64_t j_14 = ((int64_t)((int64_t)((int64_t)(f9_hash(s_5))) & (int64_t)m_13)); 
while ((((*({ hrv *_t68 = &(g904); int64_t _i68 = j_14; (int32_t*)_t68->b + hr_ix(_i68, _t68->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:40"); }))) >= (((int32_t)0LL)))) { if (hr_streq(f10_nm(((int64_t)((*({ hrv *_t70 = &(g904); int64_t _i70 = j_14; (int32_t*)_t70->b + hr_ix(_i70, _t70->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:40"); }))))), s_5)) { return ((int64_t)((*({ hrv *_t71 = &(g904); int64_t _i71 = j_14; (int32_t*)_t71->b + hr_ix(_i71, _t71->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:40"); }))));
 }
j_14 = ((int64_t)((int64_t)((int64_t)((int64_t)j_14 + (int64_t)((int64_t)1LL))) & (int64_t)m_13));
 } _bk67:; 
int64_t id_17 = (g903).n; 
(void)(({ hrv *_v72 = &(g903); S0 _x72 = ((S0){ .s_ = ((int32_t)((g901).n)), .n_ = ((int32_t)((s_5).n)), }); S0 *_p72 = (S0*)hr_grow(_v72, 1, sizeof _x72); *_p72 = _x72; _p72; }));
(void)(({ hrv *_v73 = &(g901); hsl _s73 = s_5; hr_append(_v73, _s73.p, _s73.n, sizeof(uint8_t)); }));
{ int32_t *_t74 = &((*({ hrv *_t75 = &(g904); int64_t _i75 = j_14; (int32_t*)_t75->b + hr_ix(_i75, _t75->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:44"); }))); *_t74 = ((int32_t)(id_17)); }
return id_17;
}
static uint64_t f9_hash(hsl s_9) {
uint64_t h_10 = ((uint64_t)1469598103934665603LL); 
{ hsl _v77 = s_9; for (int64_t _k77 = 0; _k77 < _v77.n; _k77++) { uint8_t c_11 = ((uint8_t*)_v77.p)[_k77]; h_10 = ((uint64_t)((uint64_t)((uint64_t)((uint64_t)h_10 ^ (uint64_t)((uint64_t)(c_11)))) * (uint64_t)((uint64_t)1099511628211LL)));
 } } _bk76:; 
return h_10;
}
static hsl f10_nm(int64_t id_15) {
S0 x_16 = (*({ hrv *_t78 = &(g903); int64_t _i78 = id_15; (S0*)_t78->b + hr_ix(_i78, _t78->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:29"); })); 
return ({ hsl _t79 = hr_sl(g901); int64_t _l79 = ((int64_t)((x_16).s_)), _h79 = ((int64_t)(((int32_t)((int64_t)(x_16).s_ + (int64_t)(x_16).n_)))); if (_l79 < 0 || _h79 < _l79 || _h79 > _t79.n) hr_slerr(_l79, _h79, _t79.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:29"); (hsl){ _t79.p + _l79 * (int64_t)sizeof(uint8_t), _h79 - _l79 }; });
}
static void f11_types_init(void) {
if ((((g543).n) > (((int64_t)0LL)))) { return;
 }
g567 = f12_tsimple(((int64_t)0LL), ((int64_t)0LL));
g550 = f12_tsimple(((int64_t)1LL), ((int64_t)0LL));
g551 = f12_tsimple(((int64_t)2LL), ((int64_t)0LL));
g552 = f17_t_int(((int64_t)0LL));
g553 = f17_t_int(((int64_t)1LL));
g554 = f17_t_int(((int64_t)2LL));
g555 = f17_t_int(((int64_t)3LL));
g556 = f17_t_int(((int64_t)4LL));
g557 = f17_t_int(((int64_t)5LL));
g558 = f17_t_int(((int64_t)6LL));
g559 = f17_t_int(((int64_t)7LL));
g560 = f12_tsimple(((int64_t)4LL), ((int64_t)4LL));
g561 = f12_tsimple(((int64_t)4LL), ((int64_t)8LL));
g562 = f12_tsimple(((int64_t)11LL), ((int64_t)0LL));
g563 = f12_tsimple(((int64_t)12LL), ((int64_t)0LL));
g564 = f12_tsimple(((int64_t)13LL), ((int64_t)0LL));
g565 = f12_tsimple(((int64_t)18LL), ((int64_t)0LL));
g566 = f12_tsimple(((int64_t)17LL), ((int64_t)0LL));
g569 = f12_tsimple(((int64_t)19LL), ((int64_t)0LL));
g570 = f12_tsimple(((int64_t)15LL), ((int64_t)0LL));
g568 = f18_t_slice(g556, true);
}
static int64_t f12_tsimple(int64_t k_18, int64_t s_19) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(k_18)), .s_ = ((uint8_t)(s_19)), .a_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f13_tmk(S1 t_20) {
if ((((g545).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v102 = &(g545); int64_t _k102 = ((int64_t)((((int64_t)1LL)) << ((((int64_t)14LL)) & 63))); if (_k102 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:27"); int32_t _x102 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o102 = _v102->n; hr_resize(_v102, _k102, sizeof _x102); for (int64_t _j = _o102; _j < _k102; _j++) ((int32_t*)_v102->b)[_j] = _x102; }));
 }
if (((((int64_t)((int64_t)(g543).n * (int64_t)((int64_t)2LL)))) >= ((g545).n))) { int64_t n_21 = ((int64_t)((int64_t)(g545).n * (int64_t)((int64_t)2LL))); 
(void)(({ hrv *_v103 = &(g545); _v103->n = 0; }));
(void)(({ hrv *_v104 = &(g545); int64_t _k104 = n_21; if (_k104 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:29"); int32_t _x104 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o104 = _v104->n; hr_resize(_v104, _k104, sizeof _x104); for (int64_t _j = _o104; _j < _k104; _j++) ((int32_t*)_v104->b)[_j] = _x104; }));
{ hrv *_v106 = &(g543); for (int64_t _k106 = 0; _k106 < _v106->n; _k106++) { S1 x_22 = ((S1*)_v106->b)[_k106]; int64_t i_23 = (int64_t)_k106; int64_t j_29 = ((int64_t)((int64_t)((int64_t)(f14_th(x_22))) & (int64_t)((int64_t)((int64_t)n_21 - (int64_t)((int64_t)1LL))))); 
while ((((*({ hrv *_t109 = &(g545); int64_t _i109 = j_29; (int32_t*)_t109->b + hr_ix(_i109, _t109->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:30"); }))) >= (((int32_t)0LL)))) { j_29 = ((int64_t)((int64_t)((int64_t)((int64_t)j_29 + (int64_t)((int64_t)1LL))) & (int64_t)((int64_t)((int64_t)n_21 - (int64_t)((int64_t)1LL)))));
 } _bk108:; 
{ int32_t *_t110 = &((*({ hrv *_t111 = &(g545); int64_t _i111 = j_29; (int32_t*)_t111->b + hr_ix(_i111, _t111->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:30"); }))); *_t110 = ((int32_t)(i_23)); }
 } } _bk105:; 
 }
int64_t m_30 = ((int64_t)((int64_t)(g545).n - (int64_t)((int64_t)1LL))); 
int64_t j_31 = ((int64_t)((int64_t)((int64_t)(f14_th(t_20))) & (int64_t)m_30)); 
while ((((*({ hrv *_t114 = &(g545); int64_t _i114 = j_31; (int32_t*)_t114->b + hr_ix(_i114, _t114->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:34"); }))) >= (((int32_t)0LL)))) { if (f16_teq((*({ hrv *_t116 = &(g543); int64_t _i116 = (*({ hrv *_t117 = &(g545); int64_t _i117 = j_31; (int32_t*)_t117->b + hr_ix(_i117, _t117->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:34"); })); (S1*)_t116->b + hr_ix(_i116, _t116->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:34"); })), t_20)) { return ((int64_t)((*({ hrv *_t118 = &(g545); int64_t _i118 = j_31; (int32_t*)_t118->b + hr_ix(_i118, _t118->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:34"); }))));
 }
j_31 = ((int64_t)((int64_t)((int64_t)((int64_t)j_31 + (int64_t)((int64_t)1LL))) & (int64_t)m_30));
 } _bk113:; 
(void)(({ hrv *_v119 = &(g543); S1 _x119 = t_20; S1 *_p119 = (S1*)hr_grow(_v119, 1, sizeof _x119); *_p119 = _x119; _p119; }));
{ int32_t *_t120 = &((*({ hrv *_t121 = &(g545); int64_t _i121 = j_31; (int32_t*)_t121->b + hr_ix(_i121, _t121->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:35"); }))); *_t120 = ((int32_t)(((int64_t)((int64_t)(g543).n - (int64_t)((int64_t)1LL))))); }
return ((int64_t)((int64_t)(g543).n - (int64_t)((int64_t)1LL)));
}
static uint64_t f14_th(S1 t_24) {
uint64_t h_27 = f15_hash_mix(((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((t_24).k_)) | (uint64_t)((uint64_t)((((uint64_t)((t_24).s_))) << ((((uint64_t)8LL)) & 63))))) | (uint64_t)((uint64_t)((((uint64_t)((t_24).fl_))) << ((((uint64_t)16LL)) & 63))))) | (uint64_t)((uint64_t)((((uint64_t)((t_24).a_))) << ((((uint64_t)32LL)) & 63)))))); 
h_27 = f15_hash_mix(((uint64_t)((uint64_t)((uint64_t)((uint64_t)h_27 ^ (uint64_t)((uint64_t)((t_24).c_)))) ^ (uint64_t)((uint64_t)((((uint64_t)((t_24).b_))) << ((((uint64_t)20LL)) & 63))))));
{ int32_t _e125 = (t_24).n_; for (int32_t _k125 = 0; _k125 < _e125; _k125++) { int32_t i_28 = (int32_t)_k125; h_27 = f15_hash_mix(((uint64_t)((uint64_t)h_27 ^ (uint64_t)((uint64_t)((*({ hrv *_t127 = &(g544); int64_t _i127 = ((int64_t)((int64_t)((int64_t)((t_24).l_)) + (int64_t)((int64_t)(i_28)))); (int32_t*)_t127->b + hr_ix(_i127, _t127->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:20"); })))))));
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
{ int32_t _e129 = (x_32).n_; for (int32_t _k129 = 0; _k129 < _e129; _k129++) { int32_t i_34 = (int32_t)_k129; if ((((*({ hrv *_t130 = &(g544); int64_t _i130 = ((int64_t)((int64_t)((int64_t)((x_32).l_)) + (int64_t)((int64_t)(i_34)))); (int32_t*)_t130->b + hr_ix(_i130, _t130->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:23"); }))) != ((*({ hrv *_t131 = &(g544); int64_t _i131 = ((int64_t)((int64_t)((int64_t)((y_33).l_)) + (int64_t)((int64_t)(i_34)))); (int32_t*)_t131->b + hr_ix(_i131, _t131->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:23"); }))))) { return false;
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
{ hrv *_v136 = &(g905); for (int64_t _k136 = 0; _k136 < _v136->n; _k136++) { S2 f_41 = ((S2*)_v136->b)[_k136]; int64_t i_42 = (int64_t)_k136; if (((((int64_t)((f_41).name_))) == (id_40))) { return i_42;
 }
 } } _bk135:; 
if ((!(hr_os_file_exists(path_39)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t t0_43 = (g699).n; 
if ((!(f21_parse_file(path_39)))) { (void)(({ hrv *_v139 = &(g487); hsl _s139 = hr_sl(g702); hr_append(_v139, _s139.p, _s139.n, sizeof(uint8_t)); }));
return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
int64_t f_439 = ((int64_t)((int64_t)(g905).n - (int64_t)((int64_t)1LL))); 
while ((((g488).n) < ((g905).n))) { (void)(({ hrv *_v141 = &(g488); int32_t _x141 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p141 = (int32_t*)hr_grow(_v141, 1, sizeof _x141); *_p141 = _x141; _p141; }));
 } _bk140:; 
{ int32_t *_t142 = &((*({ hrv *_t143 = &(g488); int64_t _i143 = f_439; (int32_t*)_t143->b + hr_ix(_i143, _t143->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:45"); }))); *_t142 = (*({ hrv *_t144 = &(g700); int64_t _i144 = ((int64_t)((int64_t)(g700).n - (int64_t)((int64_t)1LL))); (int32_t*)_t144->b + hr_ix(_i144, _t144->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:45"); })); }
(void)(f97_collect(f_439, t0_43, (g699).n));
int64_t t1_455 = (g699).n; 
int64_t im0_456 = (g486).n; 
{ int64_t _e147 = t1_455; for (int64_t _k147 = t0_43; _k147 < _e147; _k147++) { int64_t i_457 = (int64_t)_k147; if (((((*({ hrv *_t148 = &(g696); int64_t _i148 = (*({ hrv *_t149 = &(g699); int64_t _i149 = i_457; (int32_t*)_t149->b + hr_ix(_i149, _t149->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:49"); })); (S4*)_t148->b + hr_ix(_i148, _t148->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:49"); }))).k_) == (((uint8_t)54LL)))) { (void)(({ hrv *_v150 = &(g486); int32_t _x150 = (*({ hrv *_t151 = &(g699); int64_t _i151 = i_457; (int32_t*)_t151->b + hr_ix(_i151, _t151->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:49"); })); int32_t *_p150 = (int32_t*)hr_grow(_v150, 1, sizeof _x150); *_p150 = _x150; _p150; }));
 }
 } } _bk146:; 
int64_t im1_458 = (g486).n; 
L49 sp_461 = f100_lib_path(hr_str("std", 3)); 
bool isstd_462 = hr_streq(path_39, ({ hsl _t153 = ({ L49 *_t154 = &(sp_461); (hsl){ (uint8_t*)_t154->e, _t154->n }; }); int64_t _l153 = 0, _h153 = _t153.n; if (_l153 < 0 || _h153 < _l153 || _h153 > _t153.n) hr_slerr(_l153, _h153, _t153.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:51"); (hsl){ _t153.p + _l153 * (int64_t)sizeof(uint8_t), _h153 - _l153 }; })); 
if ((((*({ hrv *_t155 = &(g905); int64_t _i155 = f_439; (S2*)_t155->b + hr_ix(_i155, _t155->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:52"); }))).amni_ && (!(isstd_462)))) { if (((f101_load_import(g722, f_439, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
 }
{ int64_t _e158 = im1_458; for (int64_t _k158 = im0_456; _k158 < _e158; _k158++) { int64_t q_475 = (int64_t)_k158; int64_t n_476 = ((int64_t)((*({ hrv *_t159 = &(g486); int64_t _i159 = q_475; (int32_t*)_t159->b + hr_ix(_i159, _t159->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:53"); })))); 
if (((f101_load_import(((int64_t)(((*({ hrv *_t161 = &(g696); int64_t _i161 = n_476; (S4*)_t161->b + hr_ix(_i161, _t161->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:53"); }))).s_)), f_439, ((int64_t)(((*({ hrv *_t162 = &(g696); int64_t _i162 = n_476; (S4*)_t162->b + hr_ix(_i162, _t162->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:53"); }))).t_)))) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
 } } _bk157:; 
return f_439;
}
static bool f21_parse_file(hsl path_44) {
(void)(f6_parse_init());
int64_t t0_45 = (g906).n; 
if ((!(f22_lex_file(path_44)))) { (void)(({ hrv *_v165 = &(g702); hsl _s165 = hr_sl(g907); hr_append(_v165, _s165.p, _s165.n, sizeof(uint8_t)); }));
return false;
 }
g701 = t0_45;
g709 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
while ((((f31_tk()) != (((int64_t)0LL))) && (((g702).n) == (((int64_t)0LL))))) { (void)(f32_ptop());
 } _bk166:; 
(void)(({ hrv *_v169 = &(g700); int32_t _x169 = ((int32_t)(g709)); int32_t *_p169 = (int32_t*)hr_grow(_v169, 1, sizeof _x169); *_p169 = _x169; _p169; }));
return (((g702).n) == (((int64_t)0LL)));
}
static bool f22_lex_file(hsl path_46) {
(void)(f7_lex_init());
hrv body_47 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(hr_os_read_file(path_46, (&(body_47)))))) { (void)(({ hrv *_v173 = &(g907); hsl _s173 = hr_str("cannot read ", 12); hr_append(_v173, _s173.p, _s173.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v174 = &(g907); hsl _s174 = path_46; hr_append(_v174, _s174.p, _s174.n, sizeof(uint8_t)); }));
return false;
 }
int64_t f_48 = (g905).n; 
int64_t base_49 = (g900).n; 
int64_t skip_50 = ({ int64_t _r175; if (((((((body_47).n) >= (((int64_t)3LL))) && (((*({ hrv *_t176 = &(body_47); int64_t _i176 = ((int64_t)0LL); (uint8_t*)_t176->b + hr_ix(_i176, _t176->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:69"); }))) == (((uint8_t)239LL)))) && (((*({ hrv *_t177 = &(body_47); int64_t _i177 = ((int64_t)1LL); (uint8_t*)_t177->b + hr_ix(_i177, _t177->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:69"); }))) == (((uint8_t)187LL)))) && (((*({ hrv *_t178 = &(body_47); int64_t _i178 = ((int64_t)2LL); (uint8_t*)_t178->b + hr_ix(_i178, _t178->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:69"); }))) == (((uint8_t)191LL))))) { _r175 = ((int64_t)3LL);  } else { _r175 = ((int64_t)0LL);  } _r175; }); 
(void)(({ hrv *_v179 = &(g900); hsl _s179 = ({ hsl _t180 = hr_sl(body_47); int64_t _l180 = skip_50, _h180 = _t180.n; if (_l180 < 0 || _h180 < _l180 || _h180 > _t180.n) hr_slerr(_l180, _h180, _t180.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:70"); (hsl){ _t180.p + _l180 * (int64_t)sizeof(uint8_t), _h180 - _l180 }; }); hr_append(_v179, _s179.p, _s179.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v181 = &(g900); uint8_t _x181 = ((uint8_t)0LL); uint8_t *_p181 = (uint8_t*)hr_grow(_v181, 1, sizeof _x181); *_p181 = _x181; _p181; }));
(void)(({ hrv *_v182 = &(g900); uint8_t _x182 = ((uint8_t)0LL); uint8_t *_p182 = (uint8_t*)hr_grow(_v182, 1, sizeof _x182); *_p182 = _x182; _p182; }));
(void)(({ hrv *_v183 = &(g900); uint8_t _x183 = ((uint8_t)0LL); uint8_t *_p183 = (uint8_t*)hr_grow(_v183, 1, sizeof _x183); *_p183 = _x183; _p183; }));
(void)(({ hrv *_v184 = &(g900); uint8_t _x184 = ((uint8_t)0LL); uint8_t *_p184 = (uint8_t*)hr_grow(_v184, 1, sizeof _x184); *_p184 = _x184; _p184; }));
(void)(({ hrv *_v185 = &(g905); S2 _x185 = ((S2){ .s_ = ((int32_t)(base_49)), .n_ = ((int32_t)(((int64_t)((int64_t)(body_47).n - (int64_t)skip_50)))), .name_ = ((int32_t)(f8_intern(path_46))), .amni_ = ((((path_46).n) > (((int64_t)5LL))) && hr_streq(({ hsl _t187 = path_46; int64_t _l187 = _t187.n - ((int64_t)5LL), _h187 = _t187.n; if (_l187 < 0 || _h187 < _l187 || _h187 > _t187.n) hr_slerr(_l187, _h187, _t187.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:71"); (hsl){ _t187.p + _l187 * (int64_t)sizeof(uint8_t), _h187 - _l187 }; }), hr_str(".amni", 5))), }); S2 *_p185 = (S2*)hr_grow(_v185, 1, sizeof _x185); *_p185 = _x185; _p185; }));
bool amni_51 = ((*({ hrv *_t188 = &(g905); int64_t _i188 = f_48; (S2*)_t188->b + hr_ix(_i188, _t188->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:72"); }))).amni_; 
int64_t p_52 = base_49; 
int64_t line_53 = ((int64_t)1LL); 

for (;;) { uint8_t c_57 = (*({ hrv *_t190 = &(g900); int64_t _i190 = p_52; (uint8_t*)_t190->b + hr_ix(_i190, _t190->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:77"); })); 
while ((((((c_57) == (((uint8_t)32LL))) || ((c_57) == (((uint8_t)9LL)))) || ((c_57) == (((uint8_t)13LL)))) || ((c_57) == (((uint8_t)10LL))))) { if (((c_57) == (((uint8_t)10LL)))) { line_53++;
 }
p_52++;
c_57 = (*({ hrv *_t192 = &(g900); int64_t _i192 = p_52; (uint8_t*)_t192->b + hr_ix(_i192, _t192->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:78"); }));
 } _bk191:; 
if ((((c_57) == (((uint8_t)47LL))) && (((*({ hrv *_t193 = &(g900); int64_t _i193 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t193->b + hr_ix(_i193, _t193->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:79"); }))) == (((uint8_t)47LL))))) { while (((((*({ hrv *_t195 = &(g900); int64_t _i195 = p_52; (uint8_t*)_t195->b + hr_ix(_i195, _t195->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:79"); }))) != (((uint8_t)10LL))) && (((*({ hrv *_t196 = &(g900); int64_t _i196 = p_52; (uint8_t*)_t196->b + hr_ix(_i196, _t196->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:79"); }))) != (((uint8_t)0LL))))) { p_52++;
 } _bk194:; 
continue;
 }
if ((((c_57) == (((uint8_t)47LL))) && (((*({ hrv *_t197 = &(g900); int64_t _i197 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t197->b + hr_ix(_i197, _t197->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:80"); }))) == (((uint8_t)42LL))))) { { int64_t *_t198 = &(p_52); *_t198 = ((int64_t)((int64_t)(*_t198) + (int64_t)((int64_t)2LL))); }
int64_t nest_58 = ((int64_t)1LL); 
while (((nest_58) > (((int64_t)0LL)))) { uint8_t d_59 = (*({ hrv *_t200 = &(g900); int64_t _i200 = p_52; (uint8_t*)_t200->b + hr_ix(_i200, _t200->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:82"); })); 
if (((d_59) == (((uint8_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("unterminated /* comment", 23));
 }
if (((d_59) == (((uint8_t)10LL)))) { line_53++;
 }
if ((((d_59) == (((uint8_t)42LL))) && (((*({ hrv *_t202 = &(g900); int64_t _i202 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t202->b + hr_ix(_i202, _t202->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:82"); }))) == (((uint8_t)47LL))))) { nest_58--;
p_52++;
 } else { if ((((d_59) == (((uint8_t)47LL))) && (((*({ hrv *_t203 = &(g900); int64_t _i203 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t203->b + hr_ix(_i203, _t203->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:82"); }))) == (((uint8_t)42LL))))) { nest_58++;
p_52++;
 }
 }
p_52++;
 } _bk199:; 
continue;
 }
int64_t s_63 = p_52; 
uint8_t n1_64 = (*({ hrv *_t204 = &(g900); int64_t _i204 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t204->b + hr_ix(_i204, _t204->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:86"); })); 
uint8_t n2_65 = (*({ hrv *_t205 = &(g900); int64_t _i205 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t205->b + hr_ix(_i205, _t205->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:86"); })); 
if (((c_57) == (((uint8_t)0LL)))) { (void)(f23_put(((int64_t)0LL), s_63, s_63, &f_48, &line_53));
return true;
 }
if (f26_dig(c_57)) { if ((((c_57) == (((uint8_t)48LL))) && (((n1_64) == (((uint8_t)120LL))) || ((n1_64) == (((uint8_t)88LL)))))) { { int64_t *_t208 = &(p_52); *_t208 = ((int64_t)((int64_t)(*_t208) + (int64_t)((int64_t)2LL))); }
int64_t ds_67 = p_52; 
while (f27_hexd((*({ hrv *_t211 = &(g900); int64_t _i211 = p_52; (uint8_t*)_t211->b + hr_ix(_i211, _t211->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:90"); })))) { p_52++;
 } _bk209:; 
bool hf_69 = false; 
if (((((*({ hrv *_t212 = &(g900); int64_t _i212 = p_52; (uint8_t*)_t212->b + hr_ix(_i212, _t212->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:92"); }))) == (((uint8_t)46LL))) && f27_hexd((*({ hrv *_t214 = &(g900); int64_t _i214 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t214->b + hr_ix(_i214, _t214->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:92"); }))))) { hf_69 = true;
p_52++;
while (f27_hexd((*({ hrv *_t217 = &(g900); int64_t _i217 = p_52; (uint8_t*)_t217->b + hr_ix(_i217, _t217->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:92"); })))) { p_52++;
 } _bk215:; 
 }
if (((((*({ hrv *_t218 = &(g900); int64_t _i218 = p_52; (uint8_t*)_t218->b + hr_ix(_i218, _t218->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:93"); }))) == (((uint8_t)112LL))) || (((*({ hrv *_t219 = &(g900); int64_t _i219 = p_52; (uint8_t*)_t219->b + hr_ix(_i219, _t219->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:93"); }))) == (((uint8_t)80LL))))) { hf_69 = true;
p_52++;
if (((((*({ hrv *_t220 = &(g900); int64_t _i220 = p_52; (uint8_t*)_t220->b + hr_ix(_i220, _t220->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:93"); }))) == (((uint8_t)43LL))) || (((*({ hrv *_t221 = &(g900); int64_t _i221 = p_52; (uint8_t*)_t221->b + hr_ix(_i221, _t221->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:93"); }))) == (((uint8_t)45LL))))) { p_52++;
 }
while (f26_dig((*({ hrv *_t224 = &(g900); int64_t _i224 = p_52; (uint8_t*)_t224->b + hr_ix(_i224, _t224->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:93"); })))) { p_52++;
 } _bk222:; 
 }
if (hf_69) { (void)(f23_put(((int64_t)3LL), s_63, p_52, &f_48, &line_53));
continue;
 }
if (((((int64_t)((int64_t)p_52 - (int64_t)ds_67))) > (((int64_t)16LL)))) { return f25_lerr(f_48, line_53, hr_str("hex literal too large for 64 bits", 33));
 }
uint64_t v_70 = ((uint64_t)0LL); 
{ int64_t _e228 = p_52; for (int64_t _k228 = ds_67; _k228 < _e228; _k228++) { int64_t q_71 = (int64_t)_k228; v_70 = ((uint64_t)((uint64_t)((uint64_t)((v_70) << ((((uint64_t)4LL)) & 63))) | (uint64_t)((uint64_t)(f28_hexv((*({ hrv *_t230 = &(g900); int64_t _i230 = q_71; (uint8_t*)_t230->b + hr_ix(_i230, _t230->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:96"); })))))));
 } } _bk227:; 
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t232 = &(((*({ hrv *_t233 = &(g906); int64_t _i233 = ((int64_t)((int64_t)(g906).n - (int64_t)((int64_t)1LL))); (S3*)_t233->b + hr_ix(_i233, _t233->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:97"); }))).v_); *_t232 = ((int64_t)(v_70)); }
{ bool *_t234 = &(((*({ hrv *_t235 = &(g906); int64_t _i235 = ((int64_t)((int64_t)(g906).n - (int64_t)((int64_t)1LL))); (S3*)_t235->b + hr_ix(_i235, _t235->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:97"); }))).uns_); *_t234 = ((v_70) > (((uint64_t)9223372036854775807LL))); }
continue;
 }
while (f26_dig((*({ hrv *_t238 = &(g900); int64_t _i238 = p_52; (uint8_t*)_t238->b + hr_ix(_i238, _t238->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:99"); })))) { p_52++;
 } _bk236:; 
bool fl_73 = false; 
if (((((*({ hrv *_t239 = &(g900); int64_t _i239 = p_52; (uint8_t*)_t239->b + hr_ix(_i239, _t239->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:101"); }))) == (((uint8_t)46LL))) && f26_dig((*({ hrv *_t241 = &(g900); int64_t _i241 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t241->b + hr_ix(_i241, _t241->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:101"); }))))) { fl_73 = true;
p_52++;
while (f26_dig((*({ hrv *_t244 = &(g900); int64_t _i244 = p_52; (uint8_t*)_t244->b + hr_ix(_i244, _t244->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:101"); })))) { p_52++;
 } _bk242:; 
 }
if ((((((*({ hrv *_t245 = &(g900); int64_t _i245 = p_52; (uint8_t*)_t245->b + hr_ix(_i245, _t245->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:102"); }))) == (((uint8_t)101LL))) || (((*({ hrv *_t246 = &(g900); int64_t _i246 = p_52; (uint8_t*)_t246->b + hr_ix(_i246, _t246->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:102"); }))) == (((uint8_t)69LL)))) && (f26_dig((*({ hrv *_t248 = &(g900); int64_t _i248 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t248->b + hr_ix(_i248, _t248->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:102"); }))) || (((((*({ hrv *_t249 = &(g900); int64_t _i249 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t249->b + hr_ix(_i249, _t249->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:102"); }))) == (((uint8_t)43LL))) || (((*({ hrv *_t250 = &(g900); int64_t _i250 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t250->b + hr_ix(_i250, _t250->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:102"); }))) == (((uint8_t)45LL)))) && f26_dig((*({ hrv *_t252 = &(g900); int64_t _i252 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t252->b + hr_ix(_i252, _t252->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:102"); }))))))) { fl_73 = true;
{ int64_t *_t253 = &(p_52); *_t253 = ((int64_t)((int64_t)(*_t253) + (int64_t)((int64_t)2LL))); }
while (f26_dig((*({ hrv *_t256 = &(g900); int64_t _i256 = p_52; (uint8_t*)_t256->b + hr_ix(_i256, _t256->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:102"); })))) { p_52++;
 } _bk254:; 
 }
if (fl_73) { (void)(f23_put(((int64_t)3LL), s_63, p_52, &f_48, &line_53));
continue;
 }
uint64_t v_74 = ((uint64_t)0LL); 
{ int64_t _e259 = p_52; for (int64_t _k259 = s_63; _k259 < _e259; _k259++) { int64_t q_75 = (int64_t)_k259; uint64_t d_76 = ((uint64_t)(((uint8_t)((uint64_t)(*({ hrv *_t260 = &(g900); int64_t _i260 = q_75; (uint8_t*)_t260->b + hr_ix(_i260, _t260->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:105"); })) - (uint64_t)((uint8_t)48LL))))); 
if (((v_74) > (HR_UDIV(uint64_t, ((uint64_t)((uint64_t)((uint64_t)18446744073709551615ULL) - (uint64_t)d_76)), ((uint64_t)10LL), "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:105")))) { return f25_lerr(f_48, line_53, hr_str("integer literal too large for 64 bits", 37));
 }
v_74 = ((uint64_t)((uint64_t)((uint64_t)((uint64_t)v_74 * (uint64_t)((uint64_t)10LL))) + (uint64_t)d_76));
 } } _bk258:; 
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t263 = &(((*({ hrv *_t264 = &(g906); int64_t _i264 = ((int64_t)((int64_t)(g906).n - (int64_t)((int64_t)1LL))); (S3*)_t264->b + hr_ix(_i264, _t264->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:106"); }))).v_); *_t263 = ((int64_t)(v_74)); }
{ bool *_t265 = &(((*({ hrv *_t266 = &(g906); int64_t _i266 = ((int64_t)((int64_t)(g906).n - (int64_t)((int64_t)1LL))); (S3*)_t266->b + hr_ix(_i266, _t266->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:106"); }))).uns_); *_t265 = ((v_74) > (((uint64_t)9223372036854775807LL))); }
continue;
 }
if (f29_idc(c_57)) { while (f29_idc((*({ hrv *_t270 = &(g900); int64_t _i270 = p_52; (uint8_t*)_t270->b + hr_ix(_i270, _t270->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:109"); })))) { p_52++;
 } _bk268:; 
int64_t id_78 = f8_intern(({ hsl _t272 = hr_sl(g900); int64_t _l272 = s_63, _h272 = p_52; if (_l272 < 0 || _h272 < _l272 || _h272 > _t272.n) hr_slerr(_l272, _h272, _t272.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:110"); (hsl){ _t272.p + _l272 * (int64_t)sizeof(uint8_t), _h272 - _l272 }; })); 
int64_t k_79 = ({ int64_t _r273; if (((id_78) < (((int64_t)49LL)))) { _r273 = ((int64_t)((int64_t)((int64_t)56LL) + (int64_t)id_78));  } else { _r273 = ((int64_t)1LL);  } _r273; }); 
if (((!(amni_51)) && ((k_79) >= (((int64_t)101LL))))) { k_79 = ((int64_t)1LL);
 }
(void)(f23_put(k_79, s_63, p_52, &f_48, &line_53));
{ int64_t *_t275 = &(((*({ hrv *_t276 = &(g906); int64_t _i276 = ((int64_t)((int64_t)(g906).n - (int64_t)((int64_t)1LL))); (S3*)_t276->b + hr_ix(_i276, _t276->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:113"); }))).v_); *_t275 = id_78; }
continue;
 }
if (((c_57) == (((uint8_t)39LL)))) { p_52++;
int64_t v_86 = f30_esc((&(p_52)), f_48, line_53); 
if (((v_86) < (((int64_t)0LL)))) { return false;
 }
if ((((*({ hrv *_t278 = &(g900); int64_t _i278 = p_52; (uint8_t*)_t278->b + hr_ix(_i278, _t278->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:119"); }))) != (((uint8_t)39LL)))) { return f25_lerr(f_48, line_53, hr_str("expected closing ' of character literal", 39));
 }
p_52++;
(void)(f23_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t281 = &(((*({ hrv *_t282 = &(g906); int64_t _i282 = ((int64_t)((int64_t)(g906).n - (int64_t)((int64_t)1LL))); (S3*)_t282->b + hr_ix(_i282, _t282->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:120"); }))).v_); *_t281 = v_86; }
continue;
 }
if (((c_57) == (((uint8_t)34LL)))) { int64_t ss_87 = (g902).n; 
bool ml_88 = false; 
if ((((n1_64) == (((uint8_t)34LL))) && ((n2_65) == (((uint8_t)34LL))))) { { int64_t *_t283 = &(p_52); *_t283 = ((int64_t)((int64_t)(*_t283) + (int64_t)((int64_t)3LL))); }
int64_t q_89 = p_52; 
while ((((((*({ hrv *_t285 = &(g900); int64_t _i285 = q_89; (uint8_t*)_t285->b + hr_ix(_i285, _t285->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:127"); }))) == (((uint8_t)32LL))) || (((*({ hrv *_t286 = &(g900); int64_t _i286 = q_89; (uint8_t*)_t286->b + hr_ix(_i286, _t286->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:127"); }))) == (((uint8_t)9LL)))) || (((*({ hrv *_t287 = &(g900); int64_t _i287 = q_89; (uint8_t*)_t287->b + hr_ix(_i287, _t287->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:127"); }))) == (((uint8_t)13LL))))) { q_89++;
 } _bk284:; 
if ((((*({ hrv *_t288 = &(g900); int64_t _i288 = q_89; (uint8_t*)_t288->b + hr_ix(_i288, _t288->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:128"); }))) != (((uint8_t)10LL)))) { while ((!((((((*({ hrv *_t290 = &(g900); int64_t _i290 = p_52; (uint8_t*)_t290->b + hr_ix(_i290, _t290->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:129"); }))) == (((uint8_t)34LL))) && (((*({ hrv *_t291 = &(g900); int64_t _i291 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t291->b + hr_ix(_i291, _t291->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:129"); }))) == (((uint8_t)34LL)))) && (((*({ hrv *_t292 = &(g900); int64_t _i292 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t292->b + hr_ix(_i292, _t292->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:129"); }))) == (((uint8_t)34LL))))))) { if (((((*({ hrv *_t293 = &(g900); int64_t _i293 = p_52; (uint8_t*)_t293->b + hr_ix(_i293, _t293->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:129"); }))) == (((uint8_t)0LL))) || (((*({ hrv *_t294 = &(g900); int64_t _i294 = p_52; (uint8_t*)_t294->b + hr_ix(_i294, _t294->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:129"); }))) == (((uint8_t)10LL))))) { return f25_lerr(f_48, line_53, hr_str("unterminated \"\"\" string", 23));
 }
(void)(({ hrv *_v296 = &(g902); uint8_t _x296 = (*({ hrv *_t297 = &(g900); int64_t _i297 = p_52; (uint8_t*)_t297->b + hr_ix(_i297, _t297->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:129"); })); uint8_t *_p296 = (uint8_t*)hr_grow(_v296, 1, sizeof _x296); *_p296 = _x296; _p296; }));
p_52++;
 } _bk289:; 
{ int64_t *_t298 = &(p_52); *_t298 = ((int64_t)((int64_t)(*_t298) + (int64_t)((int64_t)3LL))); }
 } else { ml_88 = true;
int64_t first_90 = ((int64_t)((int64_t)q_89 + (int64_t)((int64_t)1LL))); 
int64_t close_91 = first_90; 
while ((!((((((*({ hrv *_t300 = &(g900); int64_t _i300 = close_91; (uint8_t*)_t300->b + hr_ix(_i300, _t300->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:135"); }))) == (((uint8_t)34LL))) && (((*({ hrv *_t301 = &(g900); int64_t _i301 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)1LL))); (uint8_t*)_t301->b + hr_ix(_i301, _t301->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:135"); }))) == (((uint8_t)34LL)))) && (((*({ hrv *_t302 = &(g900); int64_t _i302 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)2LL))); (uint8_t*)_t302->b + hr_ix(_i302, _t302->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:135"); }))) == (((uint8_t)34LL))))))) { if ((((*({ hrv *_t303 = &(g900); int64_t _i303 = close_91; (uint8_t*)_t303->b + hr_ix(_i303, _t303->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:135"); }))) == (((uint8_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("unterminated \"\"\" string", 23));
 }
close_91++;
 } _bk299:; 
int64_t cs_92 = close_91; 
while ((((cs_92) > (first_90)) && (((*({ hrv *_t306 = &(g900); int64_t _i306 = ((int64_t)((int64_t)cs_92 - (int64_t)((int64_t)1LL))); (uint8_t*)_t306->b + hr_ix(_i306, _t306->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:136"); }))) != (((uint8_t)10LL))))) { cs_92--;
 } _bk305:; 
int64_t mg_93 = ((int64_t)((int64_t)close_91 - (int64_t)cs_92)); 
{ int64_t _e308 = close_91; for (int64_t _k308 = cs_92; _k308 < _e308; _k308++) { int64_t q2_94 = (int64_t)_k308; if (((((*({ hrv *_t309 = &(g900); int64_t _i309 = q2_94; (uint8_t*)_t309->b + hr_ix(_i309, _t309->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:138"); }))) != (((uint8_t)32LL))) && (((*({ hrv *_t310 = &(g900); int64_t _i310 = q2_94; (uint8_t*)_t310->b + hr_ix(_i310, _t310->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:138"); }))) != (((uint8_t)9LL))))) { return f25_lerr(f_48, line_53, hr_str("only indentation may come before the closing \"\"\" of a multi-line string", 71));
 }
 } } _bk307:; 
int64_t l_95 = first_90; 
while (((l_95) < (cs_92))) { int64_t e_96 = l_95; 
while ((((*({ hrv *_t314 = &(g900); int64_t _i314 = e_96; (uint8_t*)_t314->b + hr_ix(_i314, _t314->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:141"); }))) != (((uint8_t)10LL)))) { e_96++;
 } _bk313:; 
int64_t te_97 = e_96; 
if ((((te_97) > (l_95)) && (((*({ hrv *_t315 = &(g900); int64_t _i315 = ((int64_t)((int64_t)te_97 - (int64_t)((int64_t)1LL))); (uint8_t*)_t315->b + hr_ix(_i315, _t315->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:142"); }))) == (((uint8_t)13LL))))) { te_97--;
 }
if (((l_95) != (first_90))) { (void)(({ hrv *_v316 = &(g902); uint8_t _x316 = ((uint8_t)10LL); uint8_t *_p316 = (uint8_t*)hr_grow(_v316, 1, sizeof _x316); *_p316 = _x316; _p316; }));
 }
bool ok_98 = ((((int64_t)((int64_t)te_97 - (int64_t)l_95))) >= (mg_93)); 
if (ok_98) { { int64_t _e318 = mg_93; for (int64_t _k318 = 0; _k318 < _e318; _k318++) { int64_t k_99 = (int64_t)_k318; if ((((*({ hrv *_t319 = &(g900); int64_t _i319 = ((int64_t)((int64_t)l_95 + (int64_t)k_99)); (uint8_t*)_t319->b + hr_ix(_i319, _t319->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:144"); }))) != ((*({ hrv *_t320 = &(g900); int64_t _i320 = ((int64_t)((int64_t)cs_92 + (int64_t)k_99)); (uint8_t*)_t320->b + hr_ix(_i320, _t320->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:144"); }))))) { ok_98 = false;
 }
 } } _bk317:; 
 }
if (ok_98) { (void)(({ hrv *_v321 = &(g902); hsl _s321 = ({ hsl _t322 = hr_sl(g900); int64_t _l322 = ((int64_t)((int64_t)l_95 + (int64_t)mg_93)), _h322 = te_97; if (_l322 < 0 || _h322 < _l322 || _h322 > _t322.n) hr_slerr(_l322, _h322, _t322.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:145"); (hsl){ _t322.p + _l322 * (int64_t)sizeof(uint8_t), _h322 - _l322 }; }); hr_append(_v321, _s321.p, _s321.n, sizeof(uint8_t)); }));
 } else { { int64_t _e324 = te_97; for (int64_t _k324 = l_95; _k324 < _e324; _k324++) { int64_t k_100 = (int64_t)_k324; if (((((*({ hrv *_t325 = &(g900); int64_t _i325 = k_100; (uint8_t*)_t325->b + hr_ix(_i325, _t325->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:145"); }))) != (((uint8_t)32LL))) && (((*({ hrv *_t326 = &(g900); int64_t _i326 = k_100; (uint8_t*)_t326->b + hr_ix(_i326, _t326->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:145"); }))) != (((uint8_t)9LL))))) { return f25_lerr(f_48, line_53, hr_str("a line of a multi-line string must start with the indentation of its closing \"\"\"", 80));
 }
 } } _bk323:; 
 }
l_95 = ((int64_t)((int64_t)e_96 + (int64_t)((int64_t)1LL)));
 } _bk312:; 
{ int64_t _e329 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)3LL))); for (int64_t _k329 = p_52; _k329 < _e329; _k329++) { int64_t k_101 = (int64_t)_k329; if ((((*({ hrv *_t330 = &(g900); int64_t _i330 = k_101; (uint8_t*)_t330->b + hr_ix(_i330, _t330->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:148"); }))) == (((uint8_t)10LL)))) { line_53++;
 }
 } } _bk328:; 
p_52 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)3LL)));
 }
 } else { p_52++;
while ((((*({ hrv *_t332 = &(g900); int64_t _i332 = p_52; (uint8_t*)_t332->b + hr_ix(_i332, _t332->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:153"); }))) != (((uint8_t)34LL)))) { if (((((*({ hrv *_t333 = &(g900); int64_t _i333 = p_52; (uint8_t*)_t333->b + hr_ix(_i333, _t333->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:153"); }))) == (((uint8_t)10LL))) || (((*({ hrv *_t334 = &(g900); int64_t _i334 = p_52; (uint8_t*)_t334->b + hr_ix(_i334, _t334->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:153"); }))) == (((uint8_t)0LL))))) { return f25_lerr(f_48, line_53, hr_str("unterminated string literal", 27));
 }
int64_t v_102 = f30_esc((&(p_52)), f_48, line_53); 
if (((v_102) < (((int64_t)0LL)))) { return false;
 }
(void)(({ hrv *_v337 = &(g902); uint8_t _x337 = ((uint8_t)(v_102)); uint8_t *_p337 = (uint8_t*)hr_grow(_v337, 1, sizeof _x337); *_p337 = _x337; _p337; }));
 } _bk331:; 
p_52++;
 }
(void)(f23_put(((int64_t)4LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t339 = &(((*({ hrv *_t340 = &(g906); int64_t _i340 = ((int64_t)((int64_t)(g906).n - (int64_t)((int64_t)1LL))); (S3*)_t340->b + hr_ix(_i340, _t340->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:156"); }))).v_); *_t339 = ss_87; }
{ int32_t *_t341 = &(((*({ hrv *_t342 = &(g906); int64_t _i342 = ((int64_t)((int64_t)(g906).n - (int64_t)((int64_t)1LL))); (S3*)_t342->b + hr_ix(_i342, _t342->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:156"); }))).w_); *_t341 = ((int32_t)(((int64_t)((int64_t)(g902).n - (int64_t)ss_87)))); }
{ bool *_t343 = &(((*({ hrv *_t344 = &(g906); int64_t _i344 = ((int64_t)((int64_t)(g906).n - (int64_t)((int64_t)1LL))); (S3*)_t344->b + hr_ix(_i344, _t344->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:156"); }))).ml_); *_t343 = ml_88; }
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
(void)(({ hrv *_v351 = &(g906); S3 _x351 = ((S3){ .k_ = ((uint8_t)(k_54)), .f_ = ((uint16_t)((*c48))), .line_ = ((int32_t)((*c53))), .s_ = ((int32_t)(s_55)), .n_ = ((int32_t)(((int64_t)((int64_t)e_56 - (int64_t)s_55)))), }); S3 *_p351 = (S3*)hr_grow(_v351, 1, sizeof _x351); *_p351 = _x351; _p351; }));
}
static bool f25_lerr(int64_t f_60, int64_t line_61, hsl m_62) {
if ((((g907).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v352 = &(g907); hsl _s352 = f10_nm(((int64_t)(((*({ hrv *_t354 = &(g905); int64_t _i354 = f_60; (S2*)_t354->b + hr_ix(_i354, _t354->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:52"); }))).name_))); hr_append(_v352, _s352.p, _s352.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o355 = &(g907); hr_fs(_o355, hr_str(":", 1)); hr_fi(_o355, line_61); hr_fs(_o355, hr_str(": error: ", 9)); hr_fs(_o355, m_62); }));
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
uint8_t c_83 = (*({ hrv *_t358 = &(g900); int64_t _i358 = (*p_80); (uint8_t*)_t358->b + hr_ix(_i358, _t358->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:54"); })); 
(*p_80)++;
if (((c_83) != (((uint8_t)92LL)))) { return ((int64_t)(c_83));
 }
uint8_t e_84 = (*({ hrv *_t359 = &(g900); int64_t _i359 = (*p_80); (uint8_t*)_t359->b + hr_ix(_i359, _t359->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:56"); })); 
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
if (((((e_84) == (((uint8_t)120LL))) && f27_hexd((*({ hrv *_t361 = &(g900); int64_t _i361 = (*p_80); (uint8_t*)_t361->b + hr_ix(_i361, _t361->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:59"); })))) && f27_hexd((*({ hrv *_t363 = &(g900); int64_t _i363 = ((int64_t)((int64_t)(*p_80) + (int64_t)((int64_t)1LL))); (uint8_t*)_t363->b + hr_ix(_i363, _t363->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:59"); }))))) { int64_t v_85 = ((int64_t)((int64_t)((int64_t)((int64_t)f28_hexv((*({ hrv *_t365 = &(g900); int64_t _i365 = (*p_80); (uint8_t*)_t365->b + hr_ix(_i365, _t365->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:59"); }))) * (int64_t)((int64_t)16LL))) + (int64_t)f28_hexv((*({ hrv *_t367 = &(g900); int64_t _i367 = ((int64_t)((int64_t)(*p_80) + (int64_t)((int64_t)1LL))); (uint8_t*)_t367->b + hr_ix(_i367, _t367->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:59"); }))))); 
{ int64_t *_t368 = p_80; *_t368 = ((int64_t)((int64_t)(*_t368) + (int64_t)((int64_t)2LL))); }
return v_85;
 }
(void)(f25_lerr(f_81, line_82, hr_str("unknown escape sequence", 23)));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f31_tk(void) {
return ((int64_t)(((*({ hrv *_t370 = &(g906); int64_t _i370 = g701; (S3*)_t370->b + hr_ix(_i370, _t370->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:32"); }))).k_));
}
static void f32_ptop(void) {
int64_t st_104 = g701; 
g708 = g709;
int64_t k_105 = f31_tk(); 
if (((k_105) == (((int64_t)57LL)))) { (void)(f33_nx());
g709 = f34_ident(hr_str("namespace declaration", 21));
g708 = g709;
(void)(f39_ex(((int64_t)12LL), hr_str("namespace declaration", 21)));
return;
 }
if (((k_105) == (((int64_t)56LL)))) { (void)(f33_nx());
int64_t n_121 = f40_mk(((int64_t)54LL), st_104); 
if (f41_is(((int64_t)16LL))) { { uint16_t *_t378 = &(((*({ hrv *_t379 = &(g696); int64_t _i379 = n_121; (S4*)_t379->b + hr_ix(_i379, _t379->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:699"); }))).fl_); *_t378 = ((uint16_t)1LL); }
 }
hrv path_123 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v381 = &(path_123); hsl _s381 = f10_nm(f34_ident(hr_str("import", 6))); hr_append(_v381, _s381.p, _s381.n, sizeof(uint8_t)); }));
while (f41_is(((int64_t)16LL))) { (void)(({ hrv *_v386 = &(path_123); uint8_t _x386 = ((uint8_t)47LL); uint8_t *_p386 = (uint8_t*)hr_grow(_v386, 1, sizeof _x386); *_p386 = _x386; _p386; }));
(void)(({ hrv *_v387 = &(path_123); hsl _s387 = f10_nm(f34_ident(hr_str("import", 6))); hr_append(_v387, _s387.p, _s387.n, sizeof(uint8_t)); }));
 } _bk384:; 
{ int64_t q__124 = f8_intern(hr_sl(path_123)); 
{ int32_t *_t391 = &(((*({ hrv *_t392 = &(g696); int64_t _i392 = n_121; (S4*)_t392->b + hr_ix(_i392, _t392->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:703"); }))).s_); *_t391 = ((int32_t)(q__124)); }
 }
if ((f42_at_from() || f43_at_word(g713))) { (void)(f33_nx());
if (((f31_tk()) != (((int64_t)4LL)))) { (void)(f38_perr(hr_str("expected the package's source, a string, after from", 51)));
 }
{ int32_t *_t398 = &(((*({ hrv *_t399 = &(g696); int64_t _i399 = n_121; (S4*)_t399->b + hr_ix(_i399, _t399->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:704"); }))).a_); *_t398 = ((int32_t)(g701)); }
(void)(f33_nx());
 }
(void)(f39_ex(((int64_t)12LL), hr_str("import", 6)));
(void)(({ hrv *_v402 = &(g699); int32_t _x402 = ((int32_t)(n_121)); int32_t *_p402 = (int32_t*)hr_grow(_v402, 1, sizeof _x402); *_p402 = _x402; _p402; }));
return;
 }
if (((f46_at_inline() || f47_at_checkfree()) || f48_at_lut())) { (void)(({ hrv *_v406 = &(g699); int32_t _x406 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p406 = (int32_t*)hr_grow(_v406, 1, sizeof _x406); *_p406 = _x406; _p406; }));
return;
 }
if (((k_105) == (((int64_t)58LL)))) { (void)(({ hrv *_v408 = &(g699); int32_t _x408 = ((int32_t)(f94_pstruct())); int32_t *_p408 = (int32_t*)hr_grow(_v408, 1, sizeof _x408); *_p408 = _x408; _p408; }));
return;
 }
if (((k_105) == (((int64_t)59LL)))) { (void)(({ hrv *_v410 = &(g699); int32_t _x410 = ((int32_t)(f96_penum())); int32_t *_p410 = (int32_t*)hr_grow(_v410, 1, sizeof _x410); *_p410 = _x410; _p410; }));
return;
 }
if (((k_105) == (((int64_t)60LL)))) { (void)(f33_nx());
int64_t n_433 = f40_mk(((int64_t)53LL), st_104); 
{ int64_t q__434 = f50_declname(hr_str("type alias", 10)); 
{ int32_t *_t415 = &(((*({ hrv *_t416 = &(g696); int64_t _i416 = n_433; (S4*)_t416->b + hr_ix(_i416, _t416->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:712"); }))).s_); *_t415 = ((int32_t)(q__434)); }
 }
{ int32_t *_t417 = &(((*({ hrv *_t418 = &(g696); int64_t _i418 = n_433; (S4*)_t418->b + hr_ix(_i418, _t418->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:712"); }))).a_); *_t417 = ((int32_t)(g708)); }
(void)(f39_ex(((int64_t)36LL), hr_str("type alias", 10)));
{ int64_t q__435 = f53_ptype(); 
{ int32_t *_t421 = &(((*({ hrv *_t422 = &(g696); int64_t _i422 = n_433; (S4*)_t422->b + hr_ix(_i422, _t422->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:712"); }))).b_); *_t421 = ((int32_t)(q__435)); }
 }
(void)(f39_ex(((int64_t)12LL), hr_str("type alias", 10)));
(void)(({ hrv *_v424 = &(g699); int32_t _x424 = ((int32_t)(n_433)); int32_t *_p424 = (int32_t*)hr_grow(_v424, 1, sizeof _x424); *_p424 = _x424; _p424; }));
return;
 }
if (((k_105) == (((int64_t)68LL)))) { (void)(f33_nx());
int64_t cs_436 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((f31_tk()) == (((int64_t)4LL)))) { cs_436 = g701;
(void)(f33_nx());
 }
if (((f31_tk()) == (((int64_t)9LL)))) { if (((cs_436) < (((int64_t)0LL)))) { (void)(f38_perr(hr_str("an extern block names the library it binds from: extern \"lib\" {", 63)));
 }
(void)(f33_nx());
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v434 = &(g699); int32_t _x434 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), cs_436))); int32_t *_p434 = (int32_t*)hr_grow(_v434, 1, sizeof _x434); *_p434 = _x434; _p434; }));
 } _bk431:; 
(void)(f39_ex(((int64_t)10LL), hr_str("extern block", 12)));
return;
 }
g701--;
if (((cs_436) >= (((int64_t)0LL)))) { g701--;
 }
(void)(({ hrv *_v437 = &(g699); int32_t _x437 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p437 = (int32_t*)hr_grow(_v437, 1, sizeof _x437); *_p437 = _x437; _p437; }));
return;
 }
if (((((((k_105) == (((int64_t)65LL))) || ((k_105) == (((int64_t)61LL)))) || ((k_105) == (((int64_t)62LL)))) || ((k_105) == (((int64_t)63LL)))) || ((k_105) == (((int64_t)64LL))))) { (void)(({ hrv *_v439 = &(g699); int32_t _x439 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p439 = (int32_t*)hr_grow(_v439, 1, sizeof _x439); *_p439 = _x439; _p439; }));
return;
 }
if ((((((k_105) == (((int64_t)71LL))) || ((k_105) == (((int64_t)66LL)))) || ((k_105) == (((int64_t)67LL)))) || ((k_105) == (((int64_t)69LL))))) { int64_t v_437 = f74_pvdecl(true); 
(void)(f39_ex(((int64_t)12LL), hr_str("global declaration", 18)));
(void)(({ hrv *_v443 = &(g699); int32_t _x443 = ((int32_t)(v_437)); int32_t *_p443 = (int32_t*)hr_grow(_v443, 1, sizeof _x443); *_p443 = _x443; _p443; }));
return;
 }
hrv m_438 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o445 = &(m_438); hr_fs(_o445, hr_str("top-level declaration expected, found '", 39)); hr_fs(_o445, f35_cur_text()); hr_fs(_o445, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_438)));
}
static void f33_nx(void) {
if (((((*({ hrv *_t448 = &(g906); int64_t _i448 = g701; (S3*)_t448->b + hr_ix(_i448, _t448->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:34"); }))).k_) != (((uint8_t)0LL)))) { g701++;
 }
}
static int64_t f34_ident(hsl ctx_106) {
if (((f31_tk()) != (((int64_t)1LL)))) { hrv m_107 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o451 = &(m_107); hr_fs(_o451, hr_str("expected identifier in ", 23)); hr_fs(_o451, ctx_106); hr_fs(_o451, hr_str(", found '", 9)); hr_fs(_o451, f35_cur_text()); hr_fs(_o451, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_107)));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t v_115 = ((int64_t)(((*({ hrv *_t454 = &(g906); int64_t _i454 = g701; (S3*)_t454->b + hr_ix(_i454, _t454->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:51"); }))).v_)); 
(void)(f33_nx());
return v_115;
}
static hsl f35_cur_text(void) {
int64_t k_108 = f31_tk(); 
return ({ hsl _r457; if (((((k_108) == (((int64_t)1LL))) || ((k_108) == (((int64_t)2LL)))) || ((k_108) == (((int64_t)3LL))))) { _r457 = f36_tok_text(g701);  } else { _r457 = f37_tname(k_108);  } _r457; });
}
static hsl f36_tok_text(int64_t t_109) {
S3 x_110 = (*({ hrv *_t460 = &(g906); int64_t _i460 = t_109; (S3*)_t460->b + hr_ix(_i460, _t460->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:181"); })); 
return ({ hsl _t461 = hr_sl(g900); int64_t _l461 = ((int64_t)((x_110).s_)), _h461 = ((int64_t)(((int32_t)((int64_t)(x_110).s_ + (int64_t)(x_110).n_)))); if (_l461 < 0 || _h461 < _l461 || _h461 > _t461.n) hr_slerr(_l461, _h461, _t461.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:181"); (hsl){ _t461.p + _l461 * (int64_t)sizeof(uint8_t), _h461 - _l461 }; });
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
return (pu_112).e[hr_ix(((int64_t)((int64_t)k_111 - (int64_t)((int64_t)5LL))), 51, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:40")];
}
static void f38_perr(hsl m_113) {
if (((g703) > (((int64_t)0LL)))) { g704 = true;
g701 = ((int64_t)((int64_t)(g906).n - (int64_t)((int64_t)1LL)));
return;
 }
if ((((g702).n) > (((int64_t)0LL)))) { return;
 }
S3 t_114 = (*({ hrv *_t465 = &(g906); int64_t _i465 = g701; (S3*)_t465->b + hr_ix(_i465, _t465->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:45"); })); 
(void)(({ hrv *_v466 = &(g702); hsl _s466 = f10_nm(((int64_t)(((*({ hrv *_t468 = &(g905); int64_t _i468 = (t_114).f_; (S2*)_t468->b + hr_ix(_i468, _t468->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:46"); }))).name_))); hr_append(_v466, _s466.p, _s466.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o469 = &(g702); hr_fs(_o469, hr_str(":", 1)); hr_fi(_o469, (t_114).line_); hr_fs(_o469, hr_str(": error: ", 9)); hr_fs(_o469, m_113); }));
g701 = ((int64_t)((int64_t)(g906).n - (int64_t)((int64_t)1LL)));
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
(void)(({ hrv *_v477 = &(g696); S4 _x477 = ((S4){ .k_ = ((uint8_t)(k_119)), .t_ = ((int32_t)(t_120)), .a_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .b_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .d_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .e_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .s_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .l_ = ((int32_t)0LL), .n_ = ((int32_t)0LL), }); S4 *_p477 = (S4*)hr_grow(_v477, 1, sizeof _x477); *_p477 = _x477; _p477; }));
return ((int64_t)((int64_t)(g696).n - (int64_t)((int64_t)1LL)));
}
static bool f41_is(int64_t k_122) {
if (((f31_tk()) == (k_122))) { (void)(f33_nx());
return true;
 }
return false;
}
static bool f42_at_from(void) {
return (f43_at_word(g713) && (((f44_tkat(((int64_t)((int64_t)g701 + (int64_t)((int64_t)1LL))))) == (((int64_t)1LL))) || ((f44_tkat(((int64_t)((int64_t)g701 + (int64_t)((int64_t)1LL))))) == (((int64_t)15LL)))));
}
static bool f43_at_word(int64_t w_125) {
return (((f31_tk()) == (((int64_t)1LL))) && ((((*({ hrv *_t484 = &(g906); int64_t _i484 = g701; (S3*)_t484->b + hr_ix(_i484, _t484->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:69"); }))).v_) == (w_125)));
}
static int64_t f44_tkat(int64_t i_126) {
return ((int64_t)(((*({ hrv *_t485 = &(g906); int64_t _i485 = f45_min(i_126, ((int64_t)((int64_t)(g906).n - (int64_t)((int64_t)1LL)))); (S3*)_t485->b + hr_ix(_i485, _t485->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:33"); }))).k_));
}
static int64_t f45_min(int64_t a_127, int64_t b_128) {
if (((b_128) < (a_127))) { return b_128;
 }
return a_127;
}
static bool f46_at_inline(void) {
return (f43_at_word(g714) && ((((f44_tkat(((int64_t)((int64_t)g701 + (int64_t)((int64_t)1LL))))) == (((int64_t)61LL))) || ((f44_tkat(((int64_t)((int64_t)g701 + (int64_t)((int64_t)1LL))))) == (((int64_t)65LL)))) || ((f44_tkat(((int64_t)((int64_t)g701 + (int64_t)((int64_t)1LL))))) == (((int64_t)62LL)))));
}
static bool f47_at_checkfree(void) {
int64_t n_129 = f44_tkat(((int64_t)((int64_t)g701 + (int64_t)((int64_t)1LL)))); 
return (f43_at_word(g715) && (((((((n_129) == (((int64_t)61LL))) || ((n_129) == (((int64_t)65LL)))) || ((n_129) == (((int64_t)62LL)))) || ((n_129) == (((int64_t)64LL)))) || ((n_129) == (((int64_t)68LL)))) || ((n_129) == (((int64_t)1LL)))));
}
static bool f48_at_lut(void) {
return (f43_at_word(g716) && ((f44_tkat(((int64_t)((int64_t)g701 + (int64_t)((int64_t)1LL))))) == (((int64_t)61LL))));
}
static int64_t f49_pfn(bool nested_130, int64_t cname_131, int64_t dylib_132) {
int64_t st_133 = g701; 
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
if (((f31_tk()) == (((int64_t)4LL)))) { cn_136 = g701;
(void)(f33_nx());
 }
 }
if (f41_is(((int64_t)68LL))) { { int64_t *_t509 = &(fl_135); *_t509 = ((int64_t)((int64_t)(*_t509) | (int64_t)((int64_t)1LL))); }
if (((f31_tk()) == (((int64_t)4LL)))) { cn_136 = g701;
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
{ int32_t *_t528 = &(((*({ hrv *_t529 = &(g696); int64_t _i529 = n_134; (S4*)_t529->b + hr_ix(_i529, _t529->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:657"); }))).s_); *_t528 = ((int32_t)(q__139)); }
 }
{ int32_t *_t530 = &(((*({ hrv *_t531 = &(g696); int64_t _i531 = n_134; (S4*)_t531->b + hr_ix(_i531, _t531->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:658"); }))).a_); *_t530 = ((int32_t)(g708)); }
{ int64_t q__403 = f51_pgenerics(); 
{ int32_t *_t533 = &(((*({ hrv *_t534 = &(g696); int64_t _i534 = n_134; (S4*)_t534->b + hr_ix(_i534, _t534->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:659"); }))).d_); *_t533 = ((int32_t)(q__403)); }
 }
(void)(f39_ex(((int64_t)5LL), hr_str("function declaration", 20)));
int64_t m_404 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t p_405 = f40_mk(((int64_t)32LL), g701); 
if (f41_is(((int64_t)67LL))) { { uint16_t *_t542 = &(((*({ hrv *_t543 = &(g696); int64_t _i543 = p_405; (S4*)_t543->b + hr_ix(_i543, _t543->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:664"); }))).fl_); *_t542 = ((uint16_t)1LL); }
 }
{ int64_t q__406 = f34_ident(hr_str("parameter list", 14)); 
{ int32_t *_t545 = &(((*({ hrv *_t546 = &(g696); int64_t _i546 = p_405; (S4*)_t546->b + hr_ix(_i546, _t546->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:665"); }))).s_); *_t545 = ((int32_t)(q__406)); }
 }
if ((f41_is(((int64_t)13LL)) || f75_amni_type())) { { int64_t q__407 = f53_ptype(); 
{ int32_t *_t550 = &(((*({ hrv *_t551 = &(g696); int64_t _i551 = p_405; (S4*)_t551->b + hr_ix(_i551, _t551->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:666"); }))).a_); *_t550 = ((int32_t)(q__407)); }
 }
 }
if (f41_is(((int64_t)36LL))) { { int64_t q__408 = f61_pexpr(); 
{ int32_t *_t554 = &(((*({ hrv *_t555 = &(g696); int64_t _i555 = p_405; (S4*)_t555->b + hr_ix(_i555, _t555->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:667"); }))).b_); *_t554 = ((int32_t)(q__408)); }
 }
 }
(void)(({ hrv *_v556 = &(g698); int32_t _x556 = ((int32_t)(p_405)); int32_t *_p556 = (int32_t*)hr_grow(_v556, 1, sizeof _x556); *_p556 = _x556; _p556; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk537; }
 }
 } _bk537:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function declaration", 20)));
(void)(f59_setl(n_134, m_404));
if ((f41_is(((int64_t)54LL)) || f75_amni_type())) { { int64_t *_t562 = &(fl_135); *_t562 = ((int64_t)((int64_t)(*_t562) | (int64_t)((int64_t)512LL))); }
int64_t r_409 = f40_mk(((int64_t)36LL), g701); 
int64_t m2_410 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v566 = &(g698); int32_t _x566 = ((int32_t)(f53_ptype())); int32_t *_p566 = (int32_t*)hr_grow(_v566, 1, sizeof _x566); *_p566 = _x566; _p566; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk565; }
 }
 } _bk565:; 
(void)(f59_setl(r_409, m2_410));
{ int32_t *_t570 = &(((*({ hrv *_t571 = &(g696); int64_t _i571 = n_134; (S4*)_t571->b + hr_ix(_i571, _t571->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:677"); }))).b_); *_t570 = ((int32_t)(r_409)); }
 }
if (((((int64_t)((int64_t)fl_135 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)))) { if (f41_is(((int64_t)36LL))) { if (((f31_tk()) != (((int64_t)4LL)))) { (void)(f38_perr(hr_str("an extern fn's symbol is a string: fn name(...) = \"symbol\"; (\302\2477.10)", 68)));
 }
cn_136 = g701;
(void)(f33_nx());
 }
(void)(f39_ex(((int64_t)12LL), hr_str("extern declaration", 18)));
int64_t x_411 = f40_mk(((int64_t)58LL), st_133); 
{ int32_t *_t578 = &(((*({ hrv *_t579 = &(g696); int64_t _i579 = x_411; (S4*)_t579->b + hr_ix(_i579, _t579->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:682"); }))).a_); *_t578 = ((int32_t)(cn_136)); }
{ int32_t *_t580 = &(((*({ hrv *_t581 = &(g696); int64_t _i581 = x_411; (S4*)_t581->b + hr_ix(_i581, _t581->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:682"); }))).b_); *_t580 = ((int32_t)(dylib_132)); }
{ int32_t *_t582 = &(((*({ hrv *_t583 = &(g696); int64_t _i583 = n_134; (S4*)_t583->b + hr_ix(_i583, _t583->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:682"); }))).e_); *_t582 = ((int32_t)(x_411)); }
 } else { if (((((int64_t)((int64_t)fl_135 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { int64_t x_412 = f40_mk(((int64_t)58LL), st_133); 
{ int32_t *_t585 = &(((*({ hrv *_t586 = &(g696); int64_t _i586 = x_412; (S4*)_t586->b + hr_ix(_i586, _t586->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:684"); }))).a_); *_t585 = ((int32_t)(cn_136)); }
{ int32_t *_t587 = &(((*({ hrv *_t588 = &(g696); int64_t _i588 = n_134; (S4*)_t588->b + hr_ix(_i588, _t588->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:684"); }))).e_); *_t587 = ((int32_t)(x_412)); }
 }
{ int64_t q__413 = f66_pblock(hr_str("function body", 13)); 
{ int32_t *_t590 = &(((*({ hrv *_t591 = &(g696); int64_t _i591 = n_134; (S4*)_t591->b + hr_ix(_i591, _t591->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:685"); }))).c_); *_t590 = ((int32_t)(q__413)); }
 }
 }
{ uint16_t *_t592 = &(((*({ hrv *_t593 = &(g696); int64_t _i593 = n_134; (S4*)_t593->b + hr_ix(_i593, _t593->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:687"); }))).fl_); *_t592 = ((uint16_t)(fl_135)); }
(void)(f88_set_end(n_134));
return n_134;
}
static int64_t f50_declname(hsl ctx_137) {
int64_t a_138 = ({ int64_t _r595; if (((f31_tk()) == (((int64_t)15LL)))) { _r595 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r595 = f34_ident(ctx_137);  } _r595; }); 
if (f41_is(((int64_t)15LL))) { g708 = a_138;
return f34_ident(ctx_137);
 }
return a_138;
}
static int64_t f51_pgenerics(void) {
if ((!(f41_is(((int64_t)39LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t l_140 = f40_mk(((int64_t)36LL), g701); 
int64_t m_141 = f52_wbeg(); 
for (;;) { int64_t g_142 = f40_mk(((int64_t)57LL), g701); 
{ int64_t q__143 = f34_ident(hr_str("generic parameter list", 22)); 
{ int32_t *_t606 = &(((*({ hrv *_t607 = &(g696); int64_t _i607 = g_142; (S4*)_t607->b + hr_ix(_i607, _t607->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:587"); }))).s_); *_t606 = ((int32_t)(q__143)); }
 }
if (f41_is(((int64_t)13LL))) { { int64_t q__402 = f53_ptype(); 
{ int32_t *_t610 = &(((*({ hrv *_t611 = &(g696); int64_t _i611 = g_142; (S4*)_t611->b + hr_ix(_i611, _t611->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:588"); }))).a_); *_t610 = ((int32_t)(q__402)); }
 }
 }
(void)(({ hrv *_v612 = &(g698); int32_t _x612 = ((int32_t)(g_142)); int32_t *_p612 = (int32_t*)hr_grow(_v612, 1, sizeof _x612); *_p612 = _x612; _p612; }));
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
return (g698).n;
}
static int64_t f53_ptype(void) {
bool cq_144 = f41_is(((int64_t)69LL)); 
int64_t t_175 = f54_ptype_prim(); 
bool q_176 = cq_144; 
for (;;) { int64_t st_177 = g701; 
if (f41_is(((int64_t)7LL))) { if (f41_is(((int64_t)13LL))) { (void)(f39_ex(((int64_t)8LL), hr_str("slice type", 10)));
int64_t n_178 = f40_mk(((int64_t)43LL), st_177); 
{ int32_t *_t625 = &(((*({ hrv *_t626 = &(g696); int64_t _i626 = n_178; (S4*)_t626->b + hr_ix(_i626, _t626->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:84"); }))).a_); *_t625 = ((int32_t)(t_175)); }
if (q_176) { { uint16_t *_t627 = &(((*({ hrv *_t628 = &(g696); int64_t _i628 = n_178; (S4*)_t628->b + hr_ix(_i628, _t628->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:84"); }))).fl_); *_t627 = ((uint16_t)1LL); }
q_176 = false;
 }
t_175 = n_178;
continue;
 }
int64_t n_179 = f40_mk(((int64_t)42LL), st_177); 
{ int32_t *_t630 = &(((*({ hrv *_t631 = &(g696); int64_t _i631 = n_179; (S4*)_t631->b + hr_ix(_i631, _t631->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:85"); }))).a_); *_t630 = ((int32_t)(t_175)); }
if (f41_is(((int64_t)8LL))) { { uint8_t *_t633 = &(((*({ hrv *_t634 = &(g696); int64_t _i634 = n_179; (S4*)_t634->b + hr_ix(_i634, _t634->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:86"); }))).op_); *_t633 = ((uint8_t)(((uint8_t)2LL))); }
t_175 = n_179;
continue;
 }
if (f41_is(((int64_t)17LL))) { { uint8_t *_t636 = &(((*({ hrv *_t637 = &(g696); int64_t _i637 = n_179; (S4*)_t637->b + hr_ix(_i637, _t637->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:87"); }))).op_); *_t636 = ((uint8_t)(((uint8_t)3LL))); }
if (((f31_tk()) != (((int64_t)8LL)))) { { int64_t q__391 = f61_pexpr(); 
{ int32_t *_t640 = &(((*({ hrv *_t641 = &(g696); int64_t _i641 = n_179; (S4*)_t641->b + hr_ix(_i641, _t641->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:87"); }))).b_); *_t640 = ((int32_t)(q__391)); }
 }
 }
 } else { if (f41_is(((int64_t)40LL))) { (void)(f39_ex(((int64_t)17LL), hr_str("resizable array type", 20)));
{ uint8_t *_t644 = &(((*({ hrv *_t645 = &(g696); int64_t _i645 = n_179; (S4*)_t645->b + hr_ix(_i645, _t645->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:88"); }))).op_); *_t644 = ({ uint8_t _r646; if (f41_is(((int64_t)39LL))) { _r646 = ((uint8_t)(((uint8_t)5LL)));  } else { _r646 = ((uint8_t)(((uint8_t)4LL)));  } _r646; }); }
 } else { if (f55_prim_tok(f31_tk())) { { uint8_t *_t650 = &(((*({ hrv *_t651 = &(g696); int64_t _i651 = n_179; (S4*)_t651->b + hr_ix(_i651, _t651->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:89"); }))).op_); *_t650 = ((uint8_t)(((uint8_t)2LL))); }
{ int64_t q__393 = f93_lenstore(); 
{ int32_t *_t653 = &(((*({ hrv *_t654 = &(g696); int64_t _i654 = n_179; (S4*)_t654->b + hr_ix(_i654, _t654->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:89"); }))).c_); *_t653 = ((int32_t)(q__393)); }
 }
 } else { { uint8_t *_t655 = &(((*({ hrv *_t656 = &(g696); int64_t _i656 = n_179; (S4*)_t656->b + hr_ix(_i656, _t656->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:90"); }))).op_); *_t655 = ((uint8_t)(((uint8_t)1LL))); }
{ int64_t q__394 = f61_pexpr(); 
{ int32_t *_t658 = &(((*({ hrv *_t659 = &(g696); int64_t _i659 = n_179; (S4*)_t659->b + hr_ix(_i659, _t659->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:90"); }))).b_); *_t658 = ((int32_t)(q__394)); }
 }
 }
 }
 }
(void)(f39_ex(((int64_t)8LL), hr_str("array type", 10)));
t_175 = n_179;
continue;
 }
if (f41_is(((int64_t)49LL))) { int64_t n_395 = f40_mk(((int64_t)44LL), st_177); 
{ int32_t *_t663 = &(((*({ hrv *_t664 = &(g696); int64_t _i664 = n_395; (S4*)_t664->b + hr_ix(_i664, _t664->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:95"); }))).a_); *_t663 = ((int32_t)(t_175)); }
if (q_176) { { uint16_t *_t665 = &(((*({ hrv *_t666 = &(g696); int64_t _i666 = n_395; (S4*)_t666->b + hr_ix(_i666, _t666->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:95"); }))).fl_); *_t665 = ((uint16_t)1LL); }
q_176 = false;
 }
if (f41_is(((int64_t)39LL))) { { int64_t q__396 = f93_lenstore(); 
{ int32_t *_t669 = &(((*({ hrv *_t670 = &(g696); int64_t _i670 = n_395; (S4*)_t670->b + hr_ix(_i670, _t670->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:96"); }))).c_); *_t669 = ((int32_t)(q__396)); }
 }
if (f41_is(((int64_t)76LL))) { { int64_t q__397 = f56_qname(hr_str("relative reference pool", 23)); 
{ int32_t *_t673 = &(((*({ hrv *_t674 = &(g696); int64_t _i674 = n_395; (S4*)_t674->b + hr_ix(_i674, _t674->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:96"); }))).s_); *_t673 = ((int32_t)(q__397)); }
 }
 }
(void)(f58_close_angle(hr_str("relative reference width", 24)));
 }
t_175 = n_395;
continue;
 }
if (f41_is(((int64_t)14LL))) { if (((((*({ hrv *_t677 = &(g696); int64_t _i677 = t_175; (S4*)_t677->b + hr_ix(_i677, _t677->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:100"); }))).k_) == (((uint8_t)44LL)))) { { uint16_t *_t678 = &(((*({ hrv *_t679 = &(g696); int64_t _i679 = t_175; (S4*)_t679->b + hr_ix(_i679, _t679->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:100"); }))).fl_); *_t678 = ((uint16_t)((uint64_t)(*_t678) | (uint64_t)((uint16_t)2LL))); }
 } else { int64_t n_398 = f40_mk(((int64_t)44LL), st_177); 
{ int32_t *_t681 = &(((*({ hrv *_t682 = &(g696); int64_t _i682 = n_398; (S4*)_t682->b + hr_ix(_i682, _t682->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:100"); }))).a_); *_t681 = ((int32_t)(t_175)); }
{ uint16_t *_t683 = &(((*({ hrv *_t684 = &(g696); int64_t _i684 = n_398; (S4*)_t684->b + hr_ix(_i684, _t684->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:100"); }))).fl_); *_t683 = ((uint16_t)2LL); }
if (q_176) { { uint16_t *_t685 = &(((*({ hrv *_t686 = &(g696); int64_t _i686 = n_398; (S4*)_t686->b + hr_ix(_i686, _t686->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:100"); }))).fl_); *_t685 = ((uint16_t)((uint64_t)(*_t685) | (uint64_t)((uint16_t)1LL))); }
q_176 = false;
 }
t_175 = n_398;
 }
continue;
 }
if (((f31_tk()) == (((int64_t)17LL)))) { (void)(f33_nx());
if (((((*({ hrv *_t689 = &(g696); int64_t _i689 = t_175; (S4*)_t689->b + hr_ix(_i689, _t689->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:103"); }))).k_) == (((uint8_t)41LL)))) { { uint16_t *_t690 = &(((*({ hrv *_t691 = &(g696); int64_t _i691 = t_175; (S4*)_t691->b + hr_ix(_i691, _t691->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:103"); }))).fl_); *_t690 = ((uint16_t)((uint64_t)(*_t690) | (uint64_t)((uint16_t)1LL))); }
 } else { (void)(f38_perr(hr_str("variable mode (..) applies only to ADT type names", 49)));
 }
continue;
 }
if (f41_is(((int64_t)16LL))) { int64_t n_399 = f40_mk(((int64_t)46LL), st_177); 
{ int32_t *_t695 = &(((*({ hrv *_t696 = &(g696); int64_t _i696 = n_399; (S4*)_t696->b + hr_ix(_i696, _t696->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:104"); }))).a_); *_t695 = ((int32_t)(t_175)); }
{ int64_t q__400 = f34_ident(hr_str("variant type", 12)); 
{ int32_t *_t698 = &(((*({ hrv *_t699 = &(g696); int64_t _i699 = n_399; (S4*)_t699->b + hr_ix(_i699, _t699->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:104"); }))).s_); *_t698 = ((int32_t)(q__400)); }
 }
t_175 = n_399;
continue;
 }
if (q_176) { int64_t n_401 = f40_mk(((int64_t)48LL), st_177); 
{ int32_t *_t701 = &(((*({ hrv *_t702 = &(g696); int64_t _i702 = n_401; (S4*)_t702->b + hr_ix(_i702, _t702->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:105"); }))).a_); *_t701 = ((int32_t)(t_175)); }
t_175 = n_401;
 }
return t_175;
 } _bk620:; 
}
static int64_t f54_ptype_prim(void) {
int64_t st_145 = g701; 
int64_t k_146 = f31_tk(); 
if (f55_prim_tok(k_146)) { (void)(f33_nx());
bool up_148 = f43_at_word(g718); 
if (((((((((k_146) >= (((int64_t)91LL))) && ((k_146) <= (((int64_t)98LL)))) || ((k_146) == (((int64_t)103LL)))) || ((k_146) == (((int64_t)102LL)))) || ((k_146) == (((int64_t)101LL)))) && (!(g748))) && (((f31_tk()) == (((int64_t)76LL))) || up_148))) { (void)(f33_nx());
int64_t n_149 = f40_mk(((int64_t)47LL), st_145); 
{ uint8_t *_t710 = &(((*({ hrv *_t711 = &(g696); int64_t _i711 = n_149; (S4*)_t711->b + hr_ix(_i711, _t711->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:116"); }))).op_); *_t710 = ((uint8_t)(k_146)); }
{ uint16_t *_t712 = &(((*({ hrv *_t713 = &(g696); int64_t _i713 = n_149; (S4*)_t713->b + hr_ix(_i713, _t713->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:116"); }))).fl_); *_t712 = ({ uint16_t _r714; if (up_148) { _r714 = ((uint16_t)1LL);  } else { _r714 = ((uint16_t)0LL);  } _r714; }); }
{ int64_t q__155 = f56_qname(hr_str("index type", 10)); 
{ int32_t *_t716 = &(((*({ hrv *_t717 = &(g696); int64_t _i717 = n_149; (S4*)_t717->b + hr_ix(_i717, _t717->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:116"); }))).s_); *_t716 = ((int32_t)(q__155)); }
 }
return n_149;
 }
int64_t n_156 = f40_mk(((int64_t)40LL), st_145); 
{ uint8_t *_t719 = &(((*({ hrv *_t720 = &(g696); int64_t _i720 = n_156; (S4*)_t720->b + hr_ix(_i720, _t720->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:118"); }))).op_); *_t719 = ((uint8_t)(k_146)); }
return n_156;
 }
if ((((k_146) == (((int64_t)1LL))) || ((k_146) == (((int64_t)15LL))))) { int64_t n_157 = f40_mk(((int64_t)41LL), st_145); 
{ int64_t q__158 = f56_qname(hr_str("type", 4)); 
{ int32_t *_t723 = &(((*({ hrv *_t724 = &(g696); int64_t _i724 = n_157; (S4*)_t724->b + hr_ix(_i724, _t724->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:121"); }))).s_); *_t723 = ((int32_t)(q__158)); }
 }
if (f41_is(((int64_t)39LL))) { int64_t m_159 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v728 = &(g698); int32_t _x728 = ((int32_t)(f53_ptype())); int32_t *_p728 = (int32_t*)hr_grow(_v728, 1, sizeof _x728); *_p728 = _x728; _p728; }));
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
if (f41_is(((int64_t)5LL))) { { uint16_t *_t738 = &(((*({ hrv *_t739 = &(g696); int64_t _i739 = n_168; (S4*)_t739->b + hr_ix(_i739, _t739->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:128"); }))).fl_); *_t738 = ((uint16_t)1LL); }
int64_t m_169 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v744 = &(g698); int32_t _x744 = ((int32_t)(f53_ptype())); int32_t *_p744 = (int32_t*)hr_grow(_v744, 1, sizeof _x744); *_p744 = _x744; _p744; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk741; }
 }
 } _bk741:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function type", 13)));
(void)(f59_setl(n_168, m_169));
if (f41_is(((int64_t)54LL))) { int64_t r_170 = f40_mk(((int64_t)36LL), g701); 
int64_t m2_171 = f52_wbeg(); 
if (f41_is(((int64_t)5LL))) { while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v756 = &(g698); int32_t _x756 = ((int32_t)(f53_ptype())); int32_t *_p756 = (int32_t*)hr_grow(_v756, 1, sizeof _x756); *_p756 = _x756; _p756; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk753; }
 }
 } _bk753:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function type return list", 25)));
 } else { (void)(({ hrv *_v760 = &(g698); int32_t _x760 = ((int32_t)(f53_ptype())); int32_t *_p760 = (int32_t*)hr_grow(_v760, 1, sizeof _x760); *_p760 = _x760; _p760; }));
 }
(void)(f59_setl(r_170, m2_171));
{ int32_t *_t763 = &(((*({ hrv *_t764 = &(g696); int64_t _i764 = n_168; (S4*)_t764->b + hr_ix(_i764, _t764->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:133"); }))).b_); *_t763 = ((int32_t)(r_170)); }
 }
 }
return n_168;
 }
if (f41_is(((int64_t)5LL))) { bool fb_172 = g748; 
g748 = false;
int64_t t_173 = f53_ptype(); 
g748 = fb_172;
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
if (((f31_tk()) == (((int64_t)44LL)))) { (void)(({ hrv *_v788 = &(g710); int64_t _x788 = g701; int64_t *_p788 = (int64_t*)hr_grow(_v788, 1, sizeof _x788); *_p788 = _x788; _p788; }));
{ uint8_t *_t789 = &(((*({ hrv *_t790 = &(g906); int64_t _i790 = g701; (S3*)_t790->b + hr_ix(_i790, _t790->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:52"); }))).k_); *_t789 = ((uint8_t)(((uint8_t)40LL))); }
return;
 }
(void)(f39_ex(((int64_t)40LL), ctx_160));
}
static void f59_setl(int64_t n_161, int64_t m_162) {
int64_t c_163 = ((int64_t)((int64_t)(g698).n - (int64_t)m_162)); 
{ int64_t q__167 = f60_wend(m_162); 
{ int32_t *_t793 = &(((*({ hrv *_t794 = &(g696); int64_t _i794 = n_161; (S4*)_t794->b + hr_ix(_i794, _t794->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:55"); }))).l_); *_t793 = ((int32_t)(q__167)); }
 }
{ int32_t *_t795 = &(((*({ hrv *_t796 = &(g696); int64_t _i796 = n_161; (S4*)_t796->b + hr_ix(_i796, _t796->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:55"); }))).n_); *_t795 = ((int32_t)(c_163)); }
}
static int64_t f60_wend(int64_t m_164) {
int64_t l_165 = (g697).n; 
{ int64_t _e798 = (g698).n; for (int64_t _k798 = m_164; _k798 < _e798; _k798++) { int64_t i_166 = (int64_t)_k798; (void)(({ hrv *_v799 = &(g697); int32_t _x799 = (*({ hrv *_t800 = &(g698); int64_t _i800 = i_166; (int32_t*)_t800->b + hr_ix(_i800, _t800->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:54"); })); int32_t *_p799 = (int32_t*)hr_grow(_v799, 1, sizeof _x799); *_p799 = _x799; _p799; }));
 } } _bk797:; 
(void)(({ hrv *_v801 = &(g698); int64_t _k801 = ((int64_t)((int64_t)(g698).n - (int64_t)m_164)); if (_k801 < 0 || _k801 > _v801->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:54"); _v801->n -= _k801; }));
return l_165;
}
static int64_t f61_pexpr(void) {
int64_t st_180 = g701; 
int64_t k_181 = f31_tk(); 
if (((k_181) == (((int64_t)72LL)))) { int64_t e_270 = f62_pif(); 
if (g706) { g707 = true;
 }
return e_270;
 }
if (((k_181) == (((int64_t)80LL)))) { int64_t e_274 = f78_pmatch(); 
if (g706) { g707 = true;
 }
return e_274;
 }
if (((k_181) == (((int64_t)78LL)))) { (void)(f33_nx());
int64_t e_275 = f40_mk(((int64_t)24LL), st_180); 
{ int64_t q__276 = f66_pblock(hr_str("block expression", 16)); 
{ int32_t *_t808 = &(((*({ hrv *_t809 = &(g696); int64_t _i809 = e_275; (S4*)_t809->b + hr_ix(_i809, _t809->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:147"); }))).a_); *_t808 = ((int32_t)(q__276)); }
 }
if (g706) { g707 = true;
 }
return e_275;
 }
if (((k_181) == (((int64_t)9LL)))) { int64_t e_277 = f66_pblock(hr_str("block", 5)); 
if (g706) { g707 = true;
 }
return e_277;
 }
if (((k_181) == (((int64_t)74LL)))) { (void)(f33_nx());
int64_t e_278 = f40_mk(((int64_t)25LL), st_180); 
{ int64_t q__279 = f63_pscrut(); 
{ int32_t *_t814 = &(((*({ hrv *_t815 = &(g696); int64_t _i815 = e_278; (S4*)_t815->b + hr_ix(_i815, _t815->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:149"); }))).a_); *_t814 = ((int32_t)(q__279)); }
 }
{ int64_t q__280 = f66_pblock(hr_str("while body", 10)); 
{ int32_t *_t817 = &(((*({ hrv *_t818 = &(g696); int64_t _i818 = e_278; (S4*)_t818->b + hr_ix(_i818, _t818->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:149"); }))).b_); *_t817 = ((int32_t)(q__280)); }
 }
if (g706) { g707 = true;
 }
return e_278;
 }
if (((k_181) == (((int64_t)77LL)))) { (void)(f33_nx());
int64_t e_281 = f40_mk(((int64_t)26LL), st_180); 
{ int64_t q__282 = f66_pblock(hr_str("loop body", 9)); 
{ int32_t *_t822 = &(((*({ hrv *_t823 = &(g696); int64_t _i823 = e_281; (S4*)_t823->b + hr_ix(_i823, _t823->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:150"); }))).a_); *_t822 = ((int32_t)(q__282)); }
 }
if (g706) { g707 = true;
 }
return e_281;
 }
if (((k_181) == (((int64_t)75LL)))) { int64_t e_294 = f79_pfor(); 
if (g706) { g707 = true;
 }
return e_294;
 }
if (((k_181) == (((int64_t)79LL)))) { (void)(f38_perr(hr_str("guard is a statement: it guards the rest of the block it is in", 62)));
return f40_mk(((int64_t)6LL), st_180);
 }
if (((k_181) == (((int64_t)81LL)))) { (void)(f33_nx());
bool sl_295 = g706; 
bool se_296 = g707; 
g706 = false;
g707 = false;
int64_t r_297 = f40_mk(((int64_t)28LL), st_180); 
if (((((f31_tk()) != (((int64_t)12LL))) && ((f31_tk()) != (((int64_t)10LL)))) && (!(f42_at_from())))) { int64_t m_298 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v834 = &(g698); int32_t _x834 = ((int32_t)(f61_pexpr())); int32_t *_p834 = (int32_t*)hr_grow(_v834, 1, sizeof _x834); *_p834 = _x834; _p834; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk833; }
 }
 } _bk833:; 
(void)(f59_setl(r_297, m_298));
 }
if (f42_at_from()) { (void)(f33_nx());
{ int64_t q__299 = f56_qname(hr_str("return from", 11)); 
{ int32_t *_t841 = &(((*({ hrv *_t842 = &(g696); int64_t _i842 = r_297; (S4*)_t842->b + hr_ix(_i842, _t842->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:158"); }))).s_); *_t841 = ((int32_t)(q__299)); }
 }
 }
g706 = sl_295;
g707 = se_296;
return r_297;
 }
if (((k_181) == (((int64_t)82LL)))) { (void)(f33_nx());
bool sl_300 = g706; 
bool se_301 = g707; 
g706 = false;
g707 = false;
int64_t r_302 = f40_mk(((int64_t)29LL), st_180); 
if ((((f31_tk()) != (((int64_t)12LL))) && ((f31_tk()) != (((int64_t)10LL))))) { { int64_t q__303 = f61_pexpr(); 
{ int32_t *_t848 = &(((*({ hrv *_t849 = &(g696); int64_t _i849 = r_302; (S4*)_t849->b + hr_ix(_i849, _t849->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:166"); }))).a_); *_t848 = ((int32_t)(q__303)); }
 }
 }
g706 = sl_300;
g707 = se_301;
return r_302;
 }
if (((k_181) == (((int64_t)83LL)))) { (void)(f33_nx());
return f40_mk(((int64_t)30LL), st_180);
 }
return f80_pbin(((int64_t)1LL));
}
static int64_t f62_pif(void) {
int64_t st_182 = g701; 
(void)(f33_nx());
int64_t n_183 = f40_mk(((int64_t)19LL), st_182); 
{ int64_t q__189 = f63_pscrut(); 
{ int32_t *_t856 = &(((*({ hrv *_t857 = &(g696); int64_t _i857 = n_183; (S4*)_t857->b + hr_ix(_i857, _t857->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:180"); }))).a_); *_t856 = ((int32_t)(q__189)); }
 }
{ int64_t q__268 = f66_pblock(hr_str("if body", 7)); 
{ int32_t *_t859 = &(((*({ hrv *_t860 = &(g696); int64_t _i860 = n_183; (S4*)_t860->b + hr_ix(_i860, _t860->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:181"); }))).b_); *_t859 = ((int32_t)(q__268)); }
 }
if (f41_is(((int64_t)73LL))) { { int64_t q__269 = ({ int64_t _r862; if (((f31_tk()) == (((int64_t)72LL)))) { _r862 = f62_pif();  } else { _r862 = f66_pblock(hr_str("else body", 9));  } _r862; }); 
{ int32_t *_t866 = &(((*({ hrv *_t867 = &(g696); int64_t _i867 = n_183; (S4*)_t867->b + hr_ix(_i867, _t867->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:182"); }))).c_); *_t866 = ((int32_t)(q__269)); }
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
int64_t s_185 = ((int64_t)((int64_t)((int64_t)((int64_t)({ int64_t _r871; if (g705) { _r871 = ((int64_t)1LL);  } else { _r871 = ((int64_t)0LL);  } _r871; }) | (int64_t)({ int64_t _r872; if (g706) { _r872 = ((int64_t)2LL);  } else { _r872 = ((int64_t)0LL);  } _r872; }))) | (int64_t)({ int64_t _r873; if (g707) { _r873 = ((int64_t)4LL);  } else { _r873 = ((int64_t)0LL);  } _r873; }))); 
g705 = nosl_184;
g706 = false;
g707 = false;
return s_185;
}
static void f65_sub_end(int64_t s_188) {
g705 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)));
g706 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)));
g707 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL)));
}
static int64_t f66_pblock(hsl ctx_190) {
int64_t st_191 = g701; 
(void)(f39_ex(((int64_t)9LL), ctx_190));
int64_t b_192 = f40_mk(((int64_t)23LL), st_191); 
(void)(f67_pbody(b_192));
return b_192;
}
static void f67_pbody(int64_t b_193) {
int64_t s_194 = f64_sub_begin(false); 
int64_t m_195 = f52_wbeg(); 
for (;;) { g706 = false;
g707 = false;
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
if (((((((((f46_at_inline() || f47_at_checkfree()) || f48_at_lut()) || ((k_197) == (((int64_t)65LL)))) || ((k_197) == (((int64_t)61LL)))) || ((k_197) == (((int64_t)62LL)))) || ((k_197) == (((int64_t)68LL)))) || ((k_197) == (((int64_t)63LL)))) || ((k_197) == (((int64_t)64LL))))) { (void)(({ hrv *_v890 = &(g698); int32_t _x890 = ((int32_t)(f49_pfn(true, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p890 = (int32_t*)hr_grow(_v890, 1, sizeof _x890); *_p890 = _x890; _p890; }));
return true;
 }
if ((((((k_197) == (((int64_t)66LL))) || ((k_197) == (((int64_t)67LL)))) || ((k_197) == (((int64_t)69LL)))) || ((k_197) == (((int64_t)71LL))))) { if ((((k_197) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g701 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v893 = &(g698); int32_t _x893 = ((int32_t)(f69_pcfor(((int64_t)0LL)))); int32_t *_p893 = (int32_t*)hr_grow(_v893, 1, sizeof _x893); *_p893 = _x893; _p893; }));
return true;
 }
int64_t v_247 = f74_pvdecl(false); 
(void)(f39_ex(((int64_t)12LL), hr_str("variable declaration", 20)));
(void)(({ hrv *_v897 = &(g698); int32_t _x897 = ((int32_t)(v_247)); int32_t *_p897 = (int32_t*)hr_grow(_v897, 1, sizeof _x897); *_p897 = _x897; _p897; }));
return true;
 }
if (((k_197) == (((int64_t)79LL)))) { (void)(f76_pguard(b_196));
return false;
 }
g706 = true;
int64_t e_254 = f61_pexpr(); 
g706 = false;
int64_t st_255 = g701; 
if ((!(g707))) { int64_t o_256 = f31_tk(); 
if ((((((((((((((o_256) == (((int64_t)36LL))) || ((o_256) == (((int64_t)18LL)))) || ((o_256) == (((int64_t)26LL)))) || ((o_256) == (((int64_t)27LL)))) || ((o_256) == (((int64_t)28LL)))) || ((o_256) == (((int64_t)29LL)))) || ((o_256) == (((int64_t)30LL)))) || ((o_256) == (((int64_t)31LL)))) || ((o_256) == (((int64_t)32LL)))) || ((o_256) == (((int64_t)33LL)))) || ((o_256) == (((int64_t)45LL)))) || ((o_256) == (((int64_t)46LL))))) { (void)(f33_nx());
int64_t r_257 = f61_pexpr(); 
(void)(f39_ex(((int64_t)12LL), hr_str("assignment statement", 20)));
int64_t n_258 = f40_mk(((int64_t)34LL), st_255); 
{ uint8_t *_t905 = &(((*({ hrv *_t906 = &(g696); int64_t _i906 = n_258; (S4*)_t906->b + hr_ix(_i906, _t906->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:528"); }))).op_); *_t905 = ((uint8_t)(o_256)); }
{ int32_t *_t907 = &(((*({ hrv *_t908 = &(g696); int64_t _i908 = n_258; (S4*)_t908->b + hr_ix(_i908, _t908->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:528"); }))).a_); *_t907 = ((int32_t)(e_254)); }
{ int32_t *_t909 = &(((*({ hrv *_t910 = &(g696); int64_t _i910 = n_258; (S4*)_t910->b + hr_ix(_i910, _t910->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:528"); }))).b_); *_t909 = ((int32_t)(r_257)); }
(void)(({ hrv *_v911 = &(g698); int32_t _x911 = ((int32_t)(n_258)); int32_t *_p911 = (int32_t*)hr_grow(_v911, 1, sizeof _x911); *_p911 = _x911; _p911; }));
return true;
 }
if ((((o_256) == (((int64_t)34LL))) || ((o_256) == (((int64_t)35LL))))) { (void)(f33_nx());
(void)(f39_ex(((int64_t)12LL), hr_str("increment statement", 19)));
int64_t n_259 = f40_mk(((int64_t)35LL), st_255); 
{ uint8_t *_t915 = &(((*({ hrv *_t916 = &(g696); int64_t _i916 = n_259; (S4*)_t916->b + hr_ix(_i916, _t916->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:530"); }))).op_); *_t915 = ((uint8_t)(o_256)); }
{ int32_t *_t917 = &(((*({ hrv *_t918 = &(g696); int64_t _i918 = n_259; (S4*)_t918->b + hr_ix(_i918, _t918->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:530"); }))).a_); *_t917 = ((int32_t)(e_254)); }
(void)(({ hrv *_v919 = &(g698); int32_t _x919 = ((int32_t)(n_259)); int32_t *_p919 = (int32_t*)hr_grow(_v919, 1, sizeof _x919); *_p919 = _x919; _p919; }));
return true;
 }
if (((o_256) == (((int64_t)11LL)))) { (void)(({ hrv *_v920 = &(g698); int32_t _x920 = ((int32_t)(f77_pmulti(e_254, st_255))); int32_t *_p920 = (int32_t*)hr_grow(_v920, 1, sizeof _x920); *_p920 = _x920; _p920; }));
return true;
 }
 }
if (f41_is(((int64_t)12LL))) { (void)(({ hrv *_v923 = &(g698); int32_t _x923 = ((int32_t)(e_254)); int32_t *_p923 = (int32_t*)hr_grow(_v923, 1, sizeof _x923); *_p923 = _x923; _p923; }));
return true;
 }
if (f41_is(((int64_t)10LL))) { { int32_t *_t925 = &(((*({ hrv *_t926 = &(g696); int64_t _i926 = b_196; (S4*)_t926->b + hr_ix(_i926, _t926->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:534"); }))).a_); *_t925 = ((int32_t)(e_254)); }
return false;
 }
if (g707) { (void)(({ hrv *_v927 = &(g698); int32_t _x927 = ((int32_t)(e_254)); int32_t *_p927 = (int32_t*)hr_grow(_v927, 1, sizeof _x927); *_p927 = _x927; _p927; }));
return true;
 }
hrv m_267 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o929 = &(m_267); hr_fs(_o929, hr_str("';' expected after expression, found '", 38)); hr_fs(_o929, f35_cur_text()); hr_fs(_o929, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_267)));
return false;
}
static int64_t f69_pcfor(int64_t mode_198) {
int64_t cf_199 = f40_mk(((int64_t)37LL), g701); 
(void)(f39_ex(((int64_t)69LL), hr_str("const for", 9)));
(void)(f39_ex(((int64_t)75LL), hr_str("const for", 9)));
(void)(f39_ex(((int64_t)39LL), hr_str("const for bindings", 18)));
int64_t nb_200 = f40_mk(((int64_t)36LL), g701); 
int64_t m_201 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v939 = &(g698); int32_t _x939 = ((int32_t)(f34_ident(hr_str("const for binding", 17)))); int32_t *_p939 = (int32_t*)hr_grow(_v939, 1, sizeof _x939); *_p939 = _x939; _p939; }));
if (((!(f41_is(((int64_t)11LL)))) || ((f31_tk()) == (((int64_t)40LL))))) { { goto _bk938; }
 }
 } _bk938:; 
(void)(f59_setl(nb_200, m_201));
(void)(f58_close_angle(hr_str("const for bindings", 18)));
(void)(f39_ex(((int64_t)76LL), hr_str("const for", 9)));
{ int32_t *_t946 = &(((*({ hrv *_t947 = &(g696); int64_t _i947 = cf_199; (S4*)_t947->b + hr_ix(_i947, _t947->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:426"); }))).a_); *_t946 = ((int32_t)(nb_200)); }
int64_t src_202 = f40_mk(((int64_t)36LL), g701); 
if (f41_is(((int64_t)7LL))) { { uint8_t *_t950 = &(((*({ hrv *_t951 = &(g696); int64_t _i951 = cf_199; (S4*)_t951->b + hr_ix(_i951, _t951->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:429"); }))).op_); *_t950 = ((uint8_t)1LL); }
int64_t s_203 = f64_sub_begin(false); 
int64_t m2_204 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)8LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v957 = &(g698); int32_t _x957 = ((int32_t)(f61_pexpr())); int32_t *_p957 = (int32_t*)hr_grow(_v957, 1, sizeof _x957); *_p957 = _x957; _p957; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk954; }
 }
 } _bk954:; 
(void)(f39_ex(((int64_t)8LL), hr_str("const for constant list", 23)));
(void)(f59_setl(src_202, m2_204));
(void)(f65_sub_end(s_203));
 } else { int64_t q_205 = f34_ident(hr_str("const for source", 16)); 
{ uint8_t *_t964 = &(((*({ hrv *_t965 = &(g696); int64_t _i965 = cf_199; (S4*)_t965->b + hr_ix(_i965, _t965->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:435"); }))).op_); *_t964 = ((uint8_t)(({ uint8_t _r966; if (((q_205) == (g719))) { _r966 = ((uint8_t)2LL);  } else { _r966 = ({ uint8_t _r967; if (((q_205) == (g721))) { _r967 = ((uint8_t)3LL);  } else { _r967 = ({ uint8_t _r968; if (((q_205) == (g720))) { _r968 = ((uint8_t)4LL);  } else { _r968 = ((uint8_t)0LL);  } _r968; });  } _r967; });  } _r966; }))); }
if (((((*({ hrv *_t969 = &(g696); int64_t _i969 = cf_199; (S4*)_t969->b + hr_ix(_i969, _t969->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:436"); }))).op_) == (((uint8_t)0LL)))) { (void)(f38_perr(hr_str("const for source must be fields<T>, variants<E>, types<...>, or [constants]", 75)));
 }
(void)(f39_ex(((int64_t)39LL), hr_str("const for source", 16)));
int64_t m2_206 = f52_wbeg(); 
while (((((f31_tk()) != (((int64_t)40LL))) && ((f31_tk()) != (((int64_t)44LL)))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v977 = &(g698); int32_t _x977 = ((int32_t)(f53_ptype())); int32_t *_p977 = (int32_t*)hr_grow(_v977, 1, sizeof _x977); *_p977 = _x977; _p977; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk973; }
 }
 } _bk973:; 
(void)(f58_close_angle(hr_str("const for source", 16)));
(void)(f59_setl(src_202, m2_206));
 }
{ int32_t *_t982 = &(((*({ hrv *_t983 = &(g696); int64_t _i983 = cf_199; (S4*)_t983->b + hr_ix(_i983, _t983->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:440"); }))).b_); *_t982 = ((int32_t)(src_202)); }
{ uint16_t *_t984 = &(((*({ hrv *_t985 = &(g696); int64_t _i985 = cf_199; (S4*)_t985->b + hr_ix(_i985, _t985->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:441"); }))).fl_); *_t984 = ((uint16_t)(mode_198)); }
if (((mode_198) == (((int64_t)1LL)))) { int64_t il_207 = f40_mk(((int64_t)36LL), g701); 
(void)(f70_pinits(il_207, true));
{ int32_t *_t988 = &(((*({ hrv *_t989 = &(g696); int64_t _i989 = cf_199; (S4*)_t989->b + hr_ix(_i989, _t989->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:442"); }))).c_); *_t988 = ((int32_t)(il_207)); }
 } else { if (((mode_198) == (((int64_t)2LL)))) { (void)(f39_ex(((int64_t)9LL), hr_str("const for arms", 14)));
int64_t al_214 = f40_mk(((int64_t)36LL), g701); 
(void)(f71_parms(al_214));
(void)(f39_ex(((int64_t)10LL), hr_str("const for arms", 14)));
{ int32_t *_t994 = &(((*({ hrv *_t995 = &(g696); int64_t _i995 = cf_199; (S4*)_t995->b + hr_ix(_i995, _t995->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:443"); }))).c_); *_t994 = ((int32_t)(al_214)); }
 } else { { int64_t q__237 = f66_pblock(hr_str("const for body", 14)); 
{ int32_t *_t997 = &(((*({ hrv *_t998 = &(g696); int64_t _i998 = cf_199; (S4*)_t998->b + hr_ix(_i998, _t998->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:443"); }))).c_); *_t997 = ((int32_t)(q__237)); }
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
{ uint16_t *_t1007 = &(((*({ hrv *_t1008 = &(g696); int64_t _i1008 = n_208; (S4*)_t1008->b + hr_ix(_i1008, _t1008->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:451"); }))).fl_); *_t1007 = ((uint16_t)((uint64_t)(*_t1007) | (uint64_t)((uint16_t)1LL))); }
{ goto _bk1002; }
 }
if ((((f31_tk()) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g701 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v1011 = &(g698); int32_t _x1011 = ((int32_t)(f69_pcfor(((int64_t)1LL)))); int32_t *_p1011 = (int32_t*)hr_grow(_v1011, 1, sizeof _x1011); *_p1011 = _x1011; _p1011; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1002; }
 }
continue;
 }
int64_t fi_212 = f40_mk(((int64_t)18LL), g701); 
if ((((f31_tk()) == (((int64_t)1LL))) && ((f44_tkat(((int64_t)((int64_t)g701 + (int64_t)((int64_t)1LL))))) == (((int64_t)13LL))))) { { int32_t *_t1017 = &(((*({ hrv *_t1018 = &(g696); int64_t _i1018 = fi_212; (S4*)_t1018->b + hr_ix(_i1018, _t1018->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:454"); }))).s_); *_t1017 = ((int32_t)(((*({ hrv *_t1019 = &(g906); int64_t _i1019 = g701; (S3*)_t1019->b + hr_ix(_i1019, _t1019->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:454"); }))).v_)); }
(void)(f33_nx());
(void)(f33_nx());
 }
{ int64_t q__213 = f61_pexpr(); 
{ int32_t *_t1023 = &(((*({ hrv *_t1024 = &(g696); int64_t _i1024 = fi_212; (S4*)_t1024->b + hr_ix(_i1024, _t1024->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:455"); }))).a_); *_t1023 = ((int32_t)(q__213)); }
 }
(void)(({ hrv *_v1025 = &(g698); int32_t _x1025 = ((int32_t)(fi_212)); int32_t *_p1025 = (int32_t*)hr_grow(_v1025, 1, sizeof _x1025); *_p1025 = _x1025; _p1025; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1002; }
 }
 } _bk1002:; 
(void)(f39_ex(((int64_t)10LL), hr_str("struct literal", 14)));
(void)(f59_setl(n_208, m_211));
(void)(f65_sub_end(s_210));
}
static void f71_parms(int64_t n_215) {
int64_t s_216 = f64_sub_begin(g705); 
int64_t m_217 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { if ((((f31_tk()) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g701 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v1037 = &(g698); int32_t _x1037 = ((int32_t)(f69_pcfor(((int64_t)2LL)))); int32_t *_p1037 = (int32_t*)hr_grow(_v1037, 1, sizeof _x1037); *_p1037 = _x1037; _p1037; }));
 } else { int64_t a_235 = f72_ppattern(); 
(void)(f39_ex(((int64_t)55LL), hr_str("match arm", 9)));
{ int64_t q__236 = f61_pexpr(); 
{ int32_t *_t1042 = &(((*({ hrv *_t1043 = &(g696); int64_t _i1043 = a_235; (S4*)_t1043->b + hr_ix(_i1043, _t1043->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:218"); }))).b_); *_t1042 = ((int32_t)(q__236)); }
 }
(void)(({ hrv *_v1044 = &(g698); int32_t _x1044 = ((int32_t)(a_235)); int32_t *_p1044 = (int32_t*)hr_grow(_v1044, 1, sizeof _x1044); *_p1044 = _x1044; _p1044; }));
 }
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1032; }
 }
 } _bk1032:; 
(void)(f59_setl(n_215, m_217));
(void)(f65_sub_end(s_216));
}
static int64_t f72_ppattern(void) {
int64_t a_218 = f40_mk(((int64_t)21LL), g701); 
if (f43_at_word(g717)) { (void)(f33_nx());
{ uint16_t *_t1051 = &(((*({ hrv *_t1052 = &(g696); int64_t _i1052 = a_218; (S4*)_t1052->b + hr_ix(_i1052, _t1052->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:226"); }))).fl_); *_t1051 = ((uint16_t)1LL); }
if (((f31_tk()) == (((int64_t)11LL)))) { (void)(f38_perr(hr_str("_ cannot be listed with other patterns", 38)));
 }
return a_218;
 }
int64_t m_219 = f52_wbeg(); 
for (;;) { int64_t it_220 = f40_mk(((int64_t)22LL), g701); 
{ int64_t q__229 = f73_pbound(); 
{ int32_t *_t1059 = &(((*({ hrv *_t1060 = &(g696); int64_t _i1060 = it_220; (S4*)_t1060->b + hr_ix(_i1060, _t1060->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:230"); }))).a_); *_t1059 = ((int32_t)(q__229)); }
 }
if (f41_is(((int64_t)17LL))) { { int64_t q__230 = f73_pbound(); 
{ int32_t *_t1063 = &(((*({ hrv *_t1064 = &(g696); int64_t _i1064 = it_220; (S4*)_t1064->b + hr_ix(_i1064, _t1064->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:231"); }))).b_); *_t1063 = ((int32_t)(q__230)); }
 }
 }
(void)(({ hrv *_v1065 = &(g698); int32_t _x1065 = ((int32_t)(it_220)); int32_t *_p1065 = (int32_t*)hr_grow(_v1065, 1, sizeof _x1065); *_p1065 = _x1065; _p1065; }));
int64_t lo_231 = ((int64_t)(((*({ hrv *_t1066 = &(g696); int64_t _i1066 = it_220; (S4*)_t1066->b + hr_ix(_i1066, _t1066->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:233"); }))).a_)); 
if (((((((*({ hrv *_t1067 = &(g696); int64_t _i1067 = lo_231; (S4*)_t1067->b + hr_ix(_i1067, _t1067->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:234"); }))).k_) == (((uint8_t)8LL))) && ((((*({ hrv *_t1068 = &(g696); int64_t _i1068 = it_220; (S4*)_t1068->b + hr_ix(_i1068, _t1068->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:234"); }))).b_) < (((int32_t)0LL)))) && (((f31_tk()) == (((int64_t)49LL))) || ((f31_tk()) == (((int64_t)1LL)))))) { bool hasq_232 = false; 
{ hsl _v1072 = f10_nm(((int64_t)(((*({ hrv *_t1074 = &(g696); int64_t _i1074 = lo_231; (S4*)_t1074->b + hr_ix(_i1074, _t1074->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:235"); }))).s_))); for (int64_t _k1072 = 0; _k1072 < _v1072.n; _k1072++) { uint8_t c_233 = ((uint8_t*)_v1072.p)[_k1072]; if (((c_233) == (((uint8_t)58LL)))) { hasq_232 = true;
 }
 } } _bk1071:; 
if ((!(hasq_232))) { if (((((int64_t)((int64_t)(g698).n - (int64_t)m_219))) > (((int64_t)1LL)))) { (void)(f38_perr(hr_str("a list of patterns binds no payload: give the variant an arm of its own", 71)));
 }
if (f41_is(((int64_t)49LL))) { { uint16_t *_t1077 = &(((*({ hrv *_t1078 = &(g696); int64_t _i1078 = a_218; (S4*)_t1078->b + hr_ix(_i1078, _t1078->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:238"); }))).fl_); *_t1077 = ((uint16_t)((uint64_t)(*_t1077) | (uint64_t)((uint16_t)2LL))); }
 }
{ int64_t q__234 = f34_ident(hr_str("match binding", 13)); 
{ int32_t *_t1080 = &(((*({ hrv *_t1081 = &(g696); int64_t _i1081 = a_218; (S4*)_t1081->b + hr_ix(_i1081, _t1081->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:239"); }))).s_); *_t1080 = ((int32_t)(q__234)); }
 }
if (((f31_tk()) == (((int64_t)11LL)))) { (void)(f38_perr(hr_str("a list of patterns binds no payload: give the variant an arm of its own", 71)));
 }
(void)(f59_setl(a_218, m_219));
return a_218;
 }
 }
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1056; }
 }
if (f43_at_word(g717)) { (void)(f38_perr(hr_str("_ cannot be listed with other patterns", 38)));
 }
 } _bk1056:; 
(void)(f59_setl(a_218, m_219));
return a_218;
}
static int64_t f73_pbound(void) {
int64_t st_221 = g701; 
bool neg_222 = f41_is(((int64_t)22LL)); 
if ((((f31_tk()) == (((int64_t)1LL))) || ((f31_tk()) == (((int64_t)15LL))))) { int64_t n_223 = f40_mk(((int64_t)8LL), g701); 
{ int64_t q__224 = f56_qname(hr_str("match pattern", 13)); 
{ int32_t *_t1094 = &(((*({ hrv *_t1095 = &(g696); int64_t _i1095 = n_223; (S4*)_t1095->b + hr_ix(_i1095, _t1095->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:254"); }))).s_); *_t1094 = ((int32_t)(q__224)); }
 }
if (neg_222) { int64_t u_225 = f40_mk(((int64_t)10LL), st_221); 
{ uint8_t *_t1097 = &(((*({ hrv *_t1098 = &(g696); int64_t _i1098 = u_225; (S4*)_t1098->b + hr_ix(_i1098, _t1098->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:254"); }))).op_); *_t1097 = ((uint8_t)(((uint8_t)22LL))); }
{ int32_t *_t1099 = &(((*({ hrv *_t1100 = &(g696); int64_t _i1100 = u_225; (S4*)_t1100->b + hr_ix(_i1100, _t1100->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:254"); }))).a_); *_t1099 = ((int32_t)(n_223)); }
return u_225;
 }
return n_223;
 }
if (((f31_tk()) != (((int64_t)2LL)))) { hrv m_226 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1103 = &(m_226); hr_fs(_o1103, hr_str("integer constant expected in match pattern, found '", 51)); hr_fs(_o1103, f35_cur_text()); hr_fs(_o1103, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_226)));
return f40_mk(((int64_t)1LL), st_221);
 }
int64_t n_227 = f40_mk(((int64_t)1LL), g701); 
(void)(f33_nx());
if (neg_222) { int64_t u_228 = f40_mk(((int64_t)10LL), st_221); 
{ uint8_t *_t1110 = &(((*({ hrv *_t1111 = &(g696); int64_t _i1111 = u_228; (S4*)_t1111->b + hr_ix(_i1111, _t1111->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:257"); }))).op_); *_t1110 = ((uint8_t)(((uint8_t)22LL))); }
{ int32_t *_t1112 = &(((*({ hrv *_t1113 = &(g696); int64_t _i1113 = u_228; (S4*)_t1113->b + hr_ix(_i1113, _t1113->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:257"); }))).a_); *_t1112 = ((int32_t)(n_227)); }
return u_228;
 }
return n_227;
}
static int64_t f74_pvdecl(bool glob_238) {
int64_t st_239 = g701; 
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
for (;;) { (void)(({ hrv *_v1129 = &(g698); int32_t _x1129 = ((int32_t)(({ int64_t _r1130; if (glob_238) { _r1130 = f50_declname(hr_str("global declaration", 18));  } else { _r1130 = f34_ident(hr_str("variable declaration", 20));  } _r1130; }))); int32_t *_p1129 = (int32_t*)hr_grow(_v1129, 1, sizeof _x1129); *_p1129 = _x1129; _p1129; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1128; }
 }
 } _bk1128:; 
(void)(f59_setl(v_241, m_242));
{ int32_t *_t1135 = &(((*({ hrv *_t1136 = &(g696); int64_t _i1136 = v_241; (S4*)_t1136->b + hr_ix(_i1136, _t1136->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:571"); }))).c_); *_t1135 = ((int32_t)(g708)); }
if ((f41_is(((int64_t)13LL)) || f75_amni_type())) { { int64_t q__244 = f53_ptype(); 
{ int32_t *_t1140 = &(((*({ hrv *_t1141 = &(g696); int64_t _i1141 = v_241; (S4*)_t1141->b + hr_ix(_i1141, _t1141->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:572"); }))).a_); *_t1140 = ((int32_t)(q__244)); }
 }
 }
if (f41_is(((int64_t)18LL))) { { int64_t *_t1143 = &(fl_240); *_t1143 = ((int64_t)((int64_t)(*_t1143) | (int64_t)((int64_t)4LL))); }
 }
if ((((((int64_t)((int64_t)fl_240 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL))) || f41_is(((int64_t)36LL)))) { int64_t il_245 = f40_mk(((int64_t)36LL), g701); 
int64_t m2_246 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v1148 = &(g698); int32_t _x1148 = ((int32_t)(f61_pexpr())); int32_t *_p1148 = (int32_t*)hr_grow(_v1148, 1, sizeof _x1148); *_p1148 = _x1148; _p1148; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1147; }
 }
 } _bk1147:; 
(void)(f59_setl(il_245, m2_246));
{ int32_t *_t1152 = &(((*({ hrv *_t1153 = &(g696); int64_t _i1153 = v_241; (S4*)_t1153->b + hr_ix(_i1153, _t1153->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:574"); }))).b_); *_t1152 = ((int32_t)(il_245)); }
 }
{ uint16_t *_t1154 = &(((*({ hrv *_t1155 = &(g696); int64_t _i1155 = v_241; (S4*)_t1155->b + hr_ix(_i1155, _t1155->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:575"); }))).fl_); *_t1154 = ((uint16_t)(fl_240)); }
if (glob_238) { if ((((((*({ hrv *_t1156 = &(g696); int64_t _i1156 = v_241; (S4*)_t1156->b + hr_ix(_i1156, _t1156->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:577"); }))).b_) < (((int32_t)0LL))) && ((((int64_t)((int64_t)fl_240 & (int64_t)((int64_t)1LL)))) == (((int64_t)0LL))))) { (void)(f38_perr(hr_str("let and const global declarations require an initializer", 56)));
 }
if (((((*({ hrv *_t1158 = &(g696); int64_t _i1158 = v_241; (S4*)_t1158->b + hr_ix(_i1158, _t1158->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:578"); }))).n_) != (((int32_t)1LL)))) { (void)(f38_perr(hr_str("global declarations declare a single name", 41)));
 }
 }
return v_241;
}
static bool f75_amni_type(void) {
int64_t k_243 = f31_tk(); 
return (((*({ hrv *_t1161 = &(g905); int64_t _i1161 = ((*({ hrv *_t1162 = &(g906); int64_t _i1162 = g701; (S3*)_t1162->b + hr_ix(_i1162, _t1162->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:74"); }))).f_; (S2*)_t1161->b + hr_ix(_i1161, _t1161->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:74"); }))).amni_ && (((((f55_prim_tok(k_243) || ((k_243) == (((int64_t)1LL)))) || ((k_243) == (((int64_t)15LL)))) || ((k_243) == (((int64_t)61LL)))) || ((k_243) == (((int64_t)5LL)))) || ((k_243) == (((int64_t)69LL)))));
}
static void f76_pguard(int64_t b_248) {
int64_t st_249 = g701; 
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
{ int32_t *_t1173 = &(((*({ hrv *_t1174 = &(g696); int64_t _i1174 = i_253; (S4*)_t1174->b + hr_ix(_i1174, _t1174->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:559"); }))).a_); *_t1173 = ((int32_t)(c_250)); }
{ int32_t *_t1175 = &(((*({ hrv *_t1176 = &(g696); int64_t _i1176 = i_253; (S4*)_t1176->b + hr_ix(_i1176, _t1176->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:559"); }))).b_); *_t1175 = ((int32_t)(rest_252)); }
{ int32_t *_t1177 = &(((*({ hrv *_t1178 = &(g696); int64_t _i1178 = i_253; (S4*)_t1178->b + hr_ix(_i1178, _t1178->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:559"); }))).c_); *_t1177 = ((int32_t)(eb_251)); }
{ uint16_t *_t1179 = &(((*({ hrv *_t1180 = &(g696); int64_t _i1180 = i_253; (S4*)_t1180->b + hr_ix(_i1180, _t1180->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:559"); }))).fl_); *_t1179 = ((uint16_t)1LL); }
if (((((*({ hrv *_t1181 = &(g696); int64_t _i1181 = rest_252; (S4*)_t1181->b + hr_ix(_i1181, _t1181->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:560"); }))).a_) >= (((int32_t)0LL)))) { { int32_t *_t1182 = &(((*({ hrv *_t1183 = &(g696); int64_t _i1183 = b_248; (S4*)_t1183->b + hr_ix(_i1183, _t1183->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:560"); }))).a_); *_t1182 = ((int32_t)(i_253)); }
 } else { (void)(({ hrv *_v1184 = &(g698); int32_t _x1184 = ((int32_t)(i_253)); int32_t *_p1184 = (int32_t*)hr_grow(_v1184, 1, sizeof _x1184); *_p1184 = _x1184; _p1184; }));
 }
}
static int64_t f77_pmulti(int64_t first_260, int64_t st_261) {
int64_t tl_262 = f40_mk(((int64_t)36LL), st_261); 
int64_t m_263 = f52_wbeg(); 
(void)(({ hrv *_v1187 = &(g698); int32_t _x1187 = ((int32_t)(first_260)); int32_t *_p1187 = (int32_t*)hr_grow(_v1187, 1, sizeof _x1187); *_p1187 = _x1187; _p1187; }));
while (f41_is(((int64_t)11LL))) { (void)(({ hrv *_v1190 = &(g698); int32_t _x1190 = ((int32_t)(f61_pexpr())); int32_t *_p1190 = (int32_t*)hr_grow(_v1190, 1, sizeof _x1190); *_p1190 = _x1190; _p1190; }));
 } _bk1188:; 
(void)(f59_setl(tl_262, m_263));
int64_t o_264 = f31_tk(); 
if (((((((((((((o_264) == (((int64_t)18LL))) || ((o_264) == (((int64_t)26LL)))) || ((o_264) == (((int64_t)27LL)))) || ((o_264) == (((int64_t)28LL)))) || ((o_264) == (((int64_t)29LL)))) || ((o_264) == (((int64_t)30LL)))) || ((o_264) == (((int64_t)31LL)))) || ((o_264) == (((int64_t)32LL)))) || ((o_264) == (((int64_t)33LL)))) || ((o_264) == (((int64_t)45LL)))) || ((o_264) == (((int64_t)46LL))))) { (void)(f38_perr(hr_str("several targets take a call's results with `=` alone (\302\2477.1)", 60)));
 }
if (((f31_tk()) != (((int64_t)36LL)))) { (void)(f38_perr(hr_str("several values exist only in `return a, b;` and in a call's results, so a block or branch cannot end in `a, b`: return from each branch instead (\302\2477.1)", 151)));
 }
(void)(f33_nx());
int64_t n_265 = f40_mk(((int64_t)34LL), st_261); 
{ uint8_t *_t1199 = &(((*({ hrv *_t1200 = &(g696); int64_t _i1200 = n_265; (S4*)_t1200->b + hr_ix(_i1200, _t1200->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:548"); }))).op_); *_t1199 = ((uint8_t)(((uint8_t)11LL))); }
{ int32_t *_t1201 = &(((*({ hrv *_t1202 = &(g696); int64_t _i1202 = n_265; (S4*)_t1202->b + hr_ix(_i1202, _t1202->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:548"); }))).a_); *_t1201 = ((int32_t)(tl_262)); }
{ int64_t q__266 = f61_pexpr(); 
{ int32_t *_t1204 = &(((*({ hrv *_t1205 = &(g696); int64_t _i1205 = n_265; (S4*)_t1205->b + hr_ix(_i1205, _t1205->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:548"); }))).b_); *_t1204 = ((int32_t)(q__266)); }
 }
(void)(f39_ex(((int64_t)12LL), hr_str("assignment statement", 20)));
return n_265;
}
static int64_t f78_pmatch(void) {
int64_t st_271 = g701; 
(void)(f33_nx());
int64_t n_272 = f40_mk(((int64_t)20LL), st_271); 
{ int64_t q__273 = f63_pscrut(); 
{ int32_t *_t1210 = &(((*({ hrv *_t1211 = &(g696); int64_t _i1211 = n_272; (S4*)_t1211->b + hr_ix(_i1211, _t1211->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:206"); }))).a_); *_t1210 = ((int32_t)(q__273)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("match expression", 16)));
(void)(f71_parms(n_272));
(void)(f39_ex(((int64_t)10LL), hr_str("match expression", 16)));
if ((((((*({ hrv *_t1215 = &(g696); int64_t _i1215 = n_272; (S4*)_t1215->b + hr_ix(_i1215, _t1215->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:210"); }))).n_) == (((int32_t)0LL))) && (((g702).n) == (((int64_t)0LL))))) { (void)(f38_perr(hr_str("match must have at least one arm", 32)));
 }
return n_272;
}
static int64_t f79_pfor(void) {
int64_t st_283 = g701; 
(void)(f33_nx());
int64_t n_284 = f40_mk(((int64_t)27LL), st_283); 
if (f41_is(((int64_t)49LL))) { { uint16_t *_t1220 = &(((*({ hrv *_t1221 = &(g696); int64_t _i1221 = n_284; (S4*)_t1221->b + hr_ix(_i1221, _t1221->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:188"); }))).fl_); *_t1220 = ((uint16_t)1LL); }
 }
{ int64_t q__285 = f34_ident(hr_str("for binding", 11)); 
{ int32_t *_t1223 = &(((*({ hrv *_t1224 = &(g696); int64_t _i1224 = n_284; (S4*)_t1224->b + hr_ix(_i1224, _t1224->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:189"); }))).s_); *_t1223 = ((int32_t)(q__285)); }
 }
bool fb_286 = g748; 
g748 = true;
{ int32_t *_t1225 = &(((*({ hrv *_t1226 = &(g696); int64_t _i1226 = n_284; (S4*)_t1226->b + hr_ix(_i1226, _t1226->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:191"); }))).l_); *_t1225 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
{ int32_t *_t1227 = &(((*({ hrv *_t1228 = &(g696); int64_t _i1228 = n_284; (S4*)_t1228->b + hr_ix(_i1228, _t1228->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:191"); }))).n_); *_t1227 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
if (f41_is(((int64_t)13LL))) { { int64_t q__287 = f53_ptype(); 
{ int32_t *_t1231 = &(((*({ hrv *_t1232 = &(g696); int64_t _i1232 = n_284; (S4*)_t1232->b + hr_ix(_i1232, _t1232->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:192"); }))).l_); *_t1231 = ((int32_t)(q__287)); }
 }
 }
if (f41_is(((int64_t)11LL))) { { int64_t q__288 = f34_ident(hr_str("for index binding", 17)); 
{ int32_t *_t1235 = &(((*({ hrv *_t1236 = &(g696); int64_t _i1236 = n_284; (S4*)_t1236->b + hr_ix(_i1236, _t1236->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:193"); }))).c_); *_t1235 = ((int32_t)(q__288)); }
 }
if (f41_is(((int64_t)13LL))) { { int64_t q__289 = f53_ptype(); 
{ int32_t *_t1239 = &(((*({ hrv *_t1240 = &(g696); int64_t _i1240 = n_284; (S4*)_t1240->b + hr_ix(_i1240, _t1240->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:193"); }))).n_); *_t1239 = ((int32_t)(q__289)); }
 }
 }
 }
g748 = fb_286;
(void)(f39_ex(((int64_t)76LL), hr_str("for statement", 13)));
int64_t s_290 = f64_sub_begin(true); 
{ int64_t q__291 = f61_pexpr(); 
{ int32_t *_t1244 = &(((*({ hrv *_t1245 = &(g696); int64_t _i1245 = n_284; (S4*)_t1245->b + hr_ix(_i1245, _t1245->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:197"); }))).a_); *_t1244 = ((int32_t)(q__291)); }
 }
if (f41_is(((int64_t)17LL))) { { int64_t q__292 = f61_pexpr(); 
{ int32_t *_t1248 = &(((*({ hrv *_t1249 = &(g696); int64_t _i1249 = n_284; (S4*)_t1249->b + hr_ix(_i1249, _t1249->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:198"); }))).b_); *_t1248 = ((int32_t)(q__292)); }
 }
 }
(void)(f65_sub_end(s_290));
{ int64_t q__293 = f66_pblock(hr_str("for body", 8)); 
{ int32_t *_t1252 = &(((*({ hrv *_t1253 = &(g696); int64_t _i1253 = n_284; (S4*)_t1253->b + hr_ix(_i1253, _t1253->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:200"); }))).d_); *_t1252 = ((int32_t)(q__293)); }
 }
return n_284;
}
static int64_t f80_pbin(int64_t minp_304) {
int64_t l_383 = f81_pun(); 
for (;;) { if (g707) { return l_383;
 }
int64_t pr_385 = f92_binprec(f31_tk()); 
if ((((pr_385) < (minp_304)) || ((pr_385) == (((int64_t)0LL))))) { return l_383;
 }
int64_t op_386 = f31_tk(); 
int64_t st_387 = g701; 
(void)(f33_nx());
int64_t s_388 = f64_sub_begin(g705); 
int64_t r_389 = f80_pbin(((int64_t)((int64_t)pr_385 + (int64_t)((int64_t)1LL)))); 
(void)(f65_sub_end(s_388));
int64_t n_390 = f40_mk(((int64_t)9LL), st_387); 
{ uint8_t *_t1264 = &(((*({ hrv *_t1265 = &(g696); int64_t _i1265 = n_390; (S4*)_t1265->b + hr_ix(_i1265, _t1265->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:280"); }))).op_); *_t1264 = ((uint8_t)(op_386)); }
{ int32_t *_t1266 = &(((*({ hrv *_t1267 = &(g696); int64_t _i1267 = n_390; (S4*)_t1267->b + hr_ix(_i1267, _t1267->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:280"); }))).a_); *_t1266 = ((int32_t)(l_383)); }
{ int32_t *_t1268 = &(((*({ hrv *_t1269 = &(g696); int64_t _i1269 = n_390; (S4*)_t1269->b + hr_ix(_i1269, _t1269->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:280"); }))).b_); *_t1268 = ((int32_t)(r_389)); }
l_383 = n_390;
 } _bk1255:; 
}
static int64_t f81_pun(void) {
int64_t k_305 = f31_tk(); 
if ((((((k_305) == (((int64_t)22LL))) || ((k_305) == (((int64_t)47LL)))) || ((k_305) == (((int64_t)48LL)))) || ((k_305) == (((int64_t)49LL))))) { int64_t st_306 = g701; 
(void)(f33_nx());
int64_t s_307 = f64_sub_begin(g705); 
int64_t a_308 = f81_pun(); 
(void)(f65_sub_end(s_307));
int64_t n_309 = f40_mk(((int64_t)10LL), st_306); 
{ uint8_t *_t1276 = &(((*({ hrv *_t1277 = &(g696); int64_t _i1277 = n_309; (S4*)_t1277->b + hr_ix(_i1277, _t1277->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:291"); }))).op_); *_t1276 = ((uint8_t)(k_305)); }
{ int32_t *_t1278 = &(((*({ hrv *_t1279 = &(g696); int64_t _i1279 = n_309; (S4*)_t1279->b + hr_ix(_i1279, _t1279->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:291"); }))).a_); *_t1278 = ((int32_t)(a_308)); }
return n_309;
 }
return f82_ppost();
}
static int64_t f82_ppost(void) {
int64_t e_367 = f83_pprim(); 
for (;;) { if (g707) { return e_367;
 }
int64_t st_368 = g701; 
if (f41_is(((int64_t)5LL))) { e_367 = f86_pcall(e_367, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), st_368);
continue;
 }
if (((f31_tk()) == (((int64_t)7LL)))) { e_367 = f91_pindex(e_367);
continue;
 }
if (f41_is(((int64_t)16LL))) { int64_t nmid_377 = f34_ident(hr_str("field access", 12)); 
if (((((f31_tk()) == (((int64_t)9LL))) && (!(g705))) && ((((*({ hrv *_t1290 = &(g696); int64_t _i1290 = e_367; (S4*)_t1290->b + hr_ix(_i1290, _t1290->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:305"); }))).k_) == (((uint8_t)8LL))))) { int64_t b_378 = f40_mk(((int64_t)41LL), ((int64_t)(((*({ hrv *_t1292 = &(g696); int64_t _i1292 = e_367; (S4*)_t1292->b + hr_ix(_i1292, _t1292->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:306"); }))).t_))); 
{ int32_t *_t1293 = &(((*({ hrv *_t1294 = &(g696); int64_t _i1294 = b_378; (S4*)_t1294->b + hr_ix(_i1294, _t1294->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:306"); }))).s_); *_t1293 = ((*({ hrv *_t1295 = &(g696); int64_t _i1295 = e_367; (S4*)_t1295->b + hr_ix(_i1295, _t1295->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:306"); }))).s_; }
int64_t v_379 = f40_mk(((int64_t)46LL), st_368); 
{ int32_t *_t1297 = &(((*({ hrv *_t1298 = &(g696); int64_t _i1298 = v_379; (S4*)_t1298->b + hr_ix(_i1298, _t1298->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:307"); }))).a_); *_t1297 = ((int32_t)(b_378)); }
{ int32_t *_t1299 = &(((*({ hrv *_t1300 = &(g696); int64_t _i1300 = v_379; (S4*)_t1300->b + hr_ix(_i1300, _t1300->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:307"); }))).s_); *_t1299 = ((int32_t)(nmid_377)); }
e_367 = f89_pslit(v_379, st_368);
 } else { int64_t d_380 = f40_mk(((int64_t)14LL), st_368); 
{ int32_t *_t1303 = &(((*({ hrv *_t1304 = &(g696); int64_t _i1304 = d_380; (S4*)_t1304->b + hr_ix(_i1304, _t1304->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:309"); }))).a_); *_t1303 = ((int32_t)(e_367)); }
{ int32_t *_t1305 = &(((*({ hrv *_t1306 = &(g696); int64_t _i1306 = d_380; (S4*)_t1306->b + hr_ix(_i1306, _t1306->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:309"); }))).s_); *_t1305 = ((int32_t)(nmid_377)); }
e_367 = d_380;
 }
continue;
 }
if (f41_is(((int64_t)84LL))) { int64_t n_381 = f40_mk(((int64_t)15LL), st_368); 
{ uint16_t *_t1309 = &(((*({ hrv *_t1310 = &(g696); int64_t _i1310 = n_381; (S4*)_t1310->b + hr_ix(_i1310, _t1310->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:312"); }))).fl_); *_t1309 = ({ uint16_t _r1311; if (f41_is(((int64_t)47LL))) { _r1311 = ((uint16_t)1LL);  } else { _r1311 = ((uint16_t)0LL);  } _r1311; }); }
{ int32_t *_t1313 = &(((*({ hrv *_t1314 = &(g696); int64_t _i1314 = n_381; (S4*)_t1314->b + hr_ix(_i1314, _t1314->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:312"); }))).a_); *_t1313 = ((int32_t)(e_367)); }
{ int64_t q__382 = f53_ptype(); 
{ int32_t *_t1316 = &(((*({ hrv *_t1317 = &(g696); int64_t _i1317 = n_381; (S4*)_t1317->b + hr_ix(_i1317, _t1317->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:312"); }))).b_); *_t1316 = ((int32_t)(q__382)); }
 }
e_367 = n_381;
continue;
 }
return e_367;
 } _bk1282:; 
}
static int64_t f83_pprim(void) {
int64_t st_310 = g701; 
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
{ int32_t *_t1344 = &(((*({ hrv *_t1345 = &(g696); int64_t _i1345 = id_332; (S4*)_t1345->b + hr_ix(_i1345, _t1345->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:364"); }))).s_); *_t1344 = ((int32_t)(name_321)); }
return f86_pcall(id_332, ta_331, st_310);
 }
int64_t t_352 = f40_mk(((int64_t)41LL), st_310); 
{ int32_t *_t1348 = &(((*({ hrv *_t1349 = &(g696); int64_t _i1349 = t_352; (S4*)_t1349->b + hr_ix(_i1349, _t1349->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:365"); }))).s_); *_t1348 = ((int32_t)(name_321)); }
{ int32_t *_t1350 = &(((*({ hrv *_t1351 = &(g696); int64_t _i1351 = t_352; (S4*)_t1351->b + hr_ix(_i1351, _t1351->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:365"); }))).l_); *_t1350 = ((*({ hrv *_t1352 = &(g696); int64_t _i1352 = ta_331; (S4*)_t1352->b + hr_ix(_i1352, _t1352->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:365"); }))).l_; }
{ int32_t *_t1353 = &(((*({ hrv *_t1354 = &(g696); int64_t _i1354 = t_352; (S4*)_t1354->b + hr_ix(_i1354, _t1354->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:365"); }))).n_); *_t1353 = ((*({ hrv *_t1355 = &(g696); int64_t _i1355 = ta_331; (S4*)_t1355->b + hr_ix(_i1355, _t1355->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:365"); }))).n_; }
if (f41_is(((int64_t)16LL))) { int64_t v_353 = f40_mk(((int64_t)46LL), st_310); 
{ int32_t *_t1358 = &(((*({ hrv *_t1359 = &(g696); int64_t _i1359 = v_353; (S4*)_t1359->b + hr_ix(_i1359, _t1359->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:366"); }))).a_); *_t1358 = ((int32_t)(t_352)); }
{ int64_t q__354 = f34_ident(hr_str("variant literal", 15)); 
{ int32_t *_t1361 = &(((*({ hrv *_t1362 = &(g696); int64_t _i1362 = v_353; (S4*)_t1362->b + hr_ix(_i1362, _t1362->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:366"); }))).s_); *_t1361 = ((int32_t)(q__354)); }
 }
return f89_pslit(v_353, st_310);
 }
return f89_pslit(t_352, st_310);
 }
 }
if ((((f31_tk()) == (((int64_t)9LL))) && (!(g705)))) { int64_t t_364 = f40_mk(((int64_t)41LL), st_310); 
{ int32_t *_t1367 = &(((*({ hrv *_t1368 = &(g696); int64_t _i1368 = t_364; (S4*)_t1368->b + hr_ix(_i1368, _t1368->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:370"); }))).s_); *_t1367 = ((int32_t)(name_321)); }
return f89_pslit(t_364, st_310);
 }
int64_t id_365 = f40_mk(((int64_t)8LL), st_310); 
{ int32_t *_t1371 = &(((*({ hrv *_t1372 = &(g696); int64_t _i1372 = id_365; (S4*)_t1372->b + hr_ix(_i1372, _t1372->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:371"); }))).s_); *_t1371 = ((int32_t)(name_321)); }
return id_365;
 }
hrv m_366 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1374 = &(m_366); hr_fs(_o1374, hr_str("expression expected, found '", 28)); hr_fs(_o1374, f35_cur_text()); hr_fs(_o1374, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_366)));
return f40_mk(((int64_t)6LL), st_310);
}
static int64_t f84_parray(void) {
int64_t st_314 = g701; 
(void)(f33_nx());
int64_t a_315 = f40_mk(((int64_t)16LL), st_314); 
int64_t s_316 = f64_sub_begin(false); 
if (f41_is(((int64_t)17LL))) { { int64_t q__317 = f61_pexpr(); 
{ int32_t *_t1383 = &(((*({ hrv *_t1384 = &(g696); int64_t _i1384 = a_315; (S4*)_t1384->b + hr_ix(_i1384, _t1384->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:406"); }))).c_); *_t1383 = ((int32_t)(q__317)); }
 }
 } else { if (((f31_tk()) != (((int64_t)8LL)))) { int64_t first_318 = f61_pexpr(); 
if (f41_is(((int64_t)12LL))) { { int32_t *_t1388 = &(((*({ hrv *_t1389 = &(g696); int64_t _i1389 = a_315; (S4*)_t1389->b + hr_ix(_i1389, _t1389->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:410"); }))).a_); *_t1388 = ((int32_t)(first_318)); }
{ int64_t q__319 = f61_pexpr(); 
{ int32_t *_t1391 = &(((*({ hrv *_t1392 = &(g696); int64_t _i1392 = a_315; (S4*)_t1392->b + hr_ix(_i1392, _t1392->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:410"); }))).b_); *_t1391 = ((int32_t)(q__319)); }
 }
 } else { int64_t m_320 = f52_wbeg(); 
(void)(({ hrv *_v1394 = &(g698); int32_t _x1394 = ((int32_t)(first_318)); int32_t *_p1394 = (int32_t*)hr_grow(_v1394, 1, sizeof _x1394); *_p1394 = _x1394; _p1394; }));
while ((f41_is(((int64_t)11LL)) && ((f31_tk()) != (((int64_t)8LL))))) { (void)(({ hrv *_v1398 = &(g698); int32_t _x1398 = ((int32_t)(f61_pexpr())); int32_t *_p1398 = (int32_t*)hr_grow(_v1398, 1, sizeof _x1398); *_p1398 = _x1398; _p1398; }));
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
int64_t save_322 = g701; 
int64_t nd0_323 = (g696).n; 
int64_t ls0_324 = (g697).n; 
int64_t sp0_325 = (g710).n; 
int64_t ws0_326 = (g698).n; 
g703++;
(void)(f33_nx());
int64_t l_327 = f40_mk(((int64_t)36LL), save_322); 
int64_t m_328 = f52_wbeg(); 
bool ok_329 = false; 
for (;;) { (void)(({ hrv *_v1407 = &(g698); int32_t _x1407 = ((int32_t)(f53_ptype())); int32_t *_p1407 = (int32_t*)hr_grow(_v1407, 1, sizeof _x1407); *_p1407 = _x1407; _p1407; }));
if ((g704 || (!(f41_is(((int64_t)11LL)))))) { { goto _bk1406; }
 }
if ((((f31_tk()) == (((int64_t)40LL))) || ((f31_tk()) == (((int64_t)44LL))))) { { goto _bk1406; }
 }
 } _bk1406:; 
if ((!(g704))) { if (((f31_tk()) == (((int64_t)44LL)))) { (void)(({ hrv *_v1413 = &(g710); int64_t _x1413 = g701; int64_t *_p1413 = (int64_t*)hr_grow(_v1413, 1, sizeof _x1413); *_p1413 = _x1413; _p1413; }));
{ uint8_t *_t1414 = &(((*({ hrv *_t1415 = &(g906); int64_t _i1415 = g701; (S3*)_t1415->b + hr_ix(_i1415, _t1415->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:386"); }))).k_); *_t1414 = ((uint8_t)(((uint8_t)40LL))); }
ok_329 = true;
 } else { if (((f31_tk()) == (((int64_t)40LL)))) { (void)(f33_nx());
ok_329 = true;
 }
 }
if (ok_329) { ok_329 = false;
if ((((f31_tk()) == (((int64_t)5LL))) || (((f31_tk()) == (((int64_t)9LL))) && (!(g705))))) { ok_329 = true;
 }
if ((((((f31_tk()) == (((int64_t)16LL))) && (!(g705))) && ((f44_tkat(((int64_t)((int64_t)g701 + (int64_t)((int64_t)1LL))))) == (((int64_t)1LL)))) && ((f44_tkat(((int64_t)((int64_t)g701 + (int64_t)((int64_t)2LL))))) == (((int64_t)9LL))))) { ok_329 = true;
 }
 }
 }
g703--;
if ((ok_329 && (!(g704)))) { (void)(f59_setl(l_327, m_328));
return l_327;
 }
g704 = false;
while ((((g710).n) > (sp0_325))) { int64_t q_330 = ({ hrv *_v1425 = &(g710); if (!_v1425->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:396"); ((int64_t*)_v1425->b)[--_v1425->n]; }); 
{ uint8_t *_t1426 = &(((*({ hrv *_t1427 = &(g906); int64_t _i1427 = q_330; (S3*)_t1427->b + hr_ix(_i1427, _t1427->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:396"); }))).k_); *_t1426 = ((uint8_t)(((uint8_t)44LL))); }
 } _bk1424:; 
if ((((g698).n) > (ws0_326))) { (void)(({ hrv *_v1428 = &(g698); int64_t _k1428 = ((int64_t)((int64_t)(g698).n - (int64_t)ws0_326)); if (_k1428 < 0 || _k1428 > _v1428->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:397"); _v1428->n -= _k1428; }));
 }
(void)(({ hrv *_v1429 = &(g696); int64_t _k1429 = nd0_323; if (_k1429 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:398"); S4 _x1429 = ((S4){ 0}); int64_t _o1429 = _v1429->n; hr_resize(_v1429, _k1429, sizeof _x1429); for (int64_t _j = _o1429; _j < _k1429; _j++) ((S4*)_v1429->b)[_j] = _x1429; }));
(void)(({ hrv *_v1430 = &(g697); int64_t _k1430 = ls0_324; if (_k1430 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:398"); int32_t _x1430 = ((int32_t)0LL); int64_t _o1430 = _v1430->n; hr_resize(_v1430, _k1430, sizeof _x1430); for (int64_t _j = _o1430; _j < _k1430; _j++) ((int32_t*)_v1430->b)[_j] = _x1430; }));
g701 = save_322;
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f86_pcall(int64_t callee_333, int64_t tyargs_334, int64_t st_335) {
int64_t c_336 = f40_mk(((int64_t)11LL), st_335); 
{ int32_t *_t1432 = &(((*({ hrv *_t1433 = &(g696); int64_t _i1433 = c_336; (S4*)_t1433->b + hr_ix(_i1433, _t1433->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:317"); }))).a_); *_t1432 = ((int32_t)(callee_333)); }
{ int32_t *_t1434 = &(((*({ hrv *_t1435 = &(g696); int64_t _i1435 = c_336; (S4*)_t1435->b + hr_ix(_i1435, _t1435->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:317"); }))).c_); *_t1434 = ((int32_t)(tyargs_334)); }
int64_t s_337 = f64_sub_begin(false); 
int64_t m_338 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v1441 = &(g698); int32_t _x1441 = ((int32_t)(f61_pexpr())); int32_t *_p1441 = (int32_t*)hr_grow(_v1441, 1, sizeof _x1441); *_p1441 = _x1441; _p1441; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1438; }
 }
 } _bk1438:; 
(void)(f39_ex(((int64_t)6LL), hr_str("call arguments", 14)));
(void)(f59_setl(c_336, m_338));
(void)(f65_sub_end(s_337));
if ((((f31_tk()) == (((int64_t)9LL))) && (!(g705)))) { { int64_t q__351 = f87_pfunval(); 
{ int32_t *_t1449 = &(((*({ hrv *_t1450 = &(g696); int64_t _i1450 = c_336; (S4*)_t1450->b + hr_ix(_i1450, _t1450->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:324"); }))).b_); *_t1449 = ((int32_t)(q__351)); }
 }
if (g706) { g707 = true;
 }
 }
return c_336;
}
static int64_t f87_pfunval(void) {
int64_t st_339 = g701; 
(void)(f39_ex(((int64_t)9LL), hr_str("function value", 14)));
int64_t fv_340 = f40_mk(((int64_t)31LL), st_339); 
int64_t b_341 = f40_mk(((int64_t)23LL), st_339); 
{ int32_t *_t1454 = &(((*({ hrv *_t1455 = &(g696); int64_t _i1455 = fv_340; (S4*)_t1455->b + hr_ix(_i1455, _t1455->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:476"); }))).a_); *_t1454 = ((int32_t)(b_341)); }
if ((((f31_tk()) == (((int64_t)1LL))) || ((f31_tk()) == (((int64_t)67LL))))) { int64_t save_342 = g701; 
int64_t nd0_343 = (g696).n; 
int64_t ws0_344 = (g698).n; 
g703++;
bool ok_345 = true; 
int64_t m_346 = f52_wbeg(); 
for (;;) { bool pv_347 = f41_is(((int64_t)67LL)); 
if (((f31_tk()) != (((int64_t)1LL)))) { ok_345 = false;
{ goto _bk1459; }
 }
int64_t p_348 = f40_mk(((int64_t)32LL), g701); 
{ int32_t *_t1463 = &(((*({ hrv *_t1464 = &(g696); int64_t _i1464 = p_348; (S4*)_t1464->b + hr_ix(_i1464, _t1464->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:485"); }))).s_); *_t1463 = ((int32_t)(((*({ hrv *_t1465 = &(g906); int64_t _i1465 = g701; (S3*)_t1465->b + hr_ix(_i1465, _t1465->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:485"); }))).v_)); }
if (pv_347) { { uint16_t *_t1466 = &(((*({ hrv *_t1467 = &(g696); int64_t _i1467 = p_348; (S4*)_t1467->b + hr_ix(_i1467, _t1467->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:485"); }))).fl_); *_t1466 = ((uint16_t)1LL); }
 }
(void)(f33_nx());
if (f41_is(((int64_t)13LL))) { { int64_t q__349 = f53_ptype(); 
{ int32_t *_t1471 = &(((*({ hrv *_t1472 = &(g696); int64_t _i1472 = p_348; (S4*)_t1472->b + hr_ix(_i1472, _t1472->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:486"); }))).a_); *_t1471 = ((int32_t)(q__349)); }
 }
 }
(void)(({ hrv *_v1473 = &(g698); int32_t _x1473 = ((int32_t)(p_348)); int32_t *_p1473 = (int32_t*)hr_grow(_v1473, 1, sizeof _x1473); *_p1473 = _x1473; _p1473; }));
if ((g704 || (!(f41_is(((int64_t)11LL)))))) { { goto _bk1459; }
 }
 } _bk1459:; 
if (((g704 || (!(ok_345))) || (!(f41_is(((int64_t)55LL)))))) { ok_345 = false;
 }
g703--;
if (ok_345) { (void)(f59_setl(fv_340, m_346));
{ uint16_t *_t1477 = &(((*({ hrv *_t1478 = &(g696); int64_t _i1478 = fv_340; (S4*)_t1478->b + hr_ix(_i1478, _t1478->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:492"); }))).fl_); *_t1477 = ((uint16_t)1LL); }
 } else { g704 = false;
if ((((g698).n) > (ws0_344))) { (void)(({ hrv *_v1479 = &(g698); int64_t _k1479 = ((int64_t)((int64_t)(g698).n - (int64_t)ws0_344)); if (_k1479 < 0 || _k1479 > _v1479->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:493"); _v1479->n -= _k1479; }));
 }
(void)(({ hrv *_v1480 = &(g696); int64_t _k1480 = nd0_343; if (_k1480 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:493"); S4 _x1480 = ((S4){ 0}); int64_t _o1480 = _v1480->n; hr_resize(_v1480, _k1480, sizeof _x1480); for (int64_t _j = _o1480; _j < _k1480; _j++) ((S4*)_v1480->b)[_j] = _x1480; }));
g701 = save_342;
 }
 }
(void)(f67_pbody(b_341));
(void)(f88_set_end(fv_340));
return fv_340;
}
static void f88_set_end(int64_t n_350) {
while ((((g711).n) < ((g696).n))) { (void)(({ hrv *_v1484 = &(g711); int32_t _x1484 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1484 = (int32_t*)hr_grow(_v1484, 1, sizeof _x1484); *_p1484 = _x1484; _p1484; }));
 } _bk1483:; 
{ int32_t *_t1485 = &((*({ hrv *_t1486 = &(g711); int64_t _i1486 = n_350; (int32_t*)_t1486->b + hr_ix(_i1486, _t1486->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:28"); }))); *_t1485 = ((int32_t)((g696).n)); }
}
static int64_t f89_pslit(int64_t ty_355, int64_t st_356) {
int64_t n_357 = f40_mk(((int64_t)17LL), st_356); 
{ int32_t *_t1488 = &(((*({ hrv *_t1489 = &(g696); int64_t _i1489 = n_357; (S4*)_t1489->b + hr_ix(_i1489, _t1489->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:464"); }))).a_); *_t1488 = ((int32_t)(ty_355)); }
(void)(f70_pinits(n_357, false));
int64_t named_358 = ((int64_t)0LL); 
bool cf_359 = false; 
{ int32_t _e1492 = ((*({ hrv *_t1493 = &(g696); int64_t _i1493 = n_357; (S4*)_t1493->b + hr_ix(_i1493, _t1493->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:467"); }))).n_; for (int32_t _k1492 = 0; _k1492 < _e1492; _k1492++) { int32_t i_360 = (int32_t)_k1492; int64_t fi_363 = f90_kid(n_357, ((int64_t)(i_360))); 
if (((((*({ hrv *_t1495 = &(g696); int64_t _i1495 = fi_363; (S4*)_t1495->b + hr_ix(_i1495, _t1495->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:467"); }))).k_) == (((uint8_t)37LL)))) { cf_359 = true;
 } else { if (((((*({ hrv *_t1496 = &(g696); int64_t _i1496 = fi_363; (S4*)_t1496->b + hr_ix(_i1496, _t1496->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:467"); }))).s_) >= (((int32_t)0LL)))) { named_358++;
 }
 }
 } } _bk1491:; 
if ((((!(cf_359)) && ((named_358) > (((int64_t)0LL)))) && ((named_358) != (((int64_t)(((*({ hrv *_t1497 = &(g696); int64_t _i1497 = n_357; (S4*)_t1497->b + hr_ix(_i1497, _t1497->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:468"); }))).n_)))))) { (void)(f38_perr(hr_str("struct literal mixes named and positional initializers", 54)));
 }
return n_357;
}
static int64_t f90_kid(int64_t n_361, int64_t i_362) {
return ((int64_t)((*({ hrv *_t1499 = &(g697); int64_t _i1499 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1500 = &(g696); int64_t _i1500 = n_361; (S4*)_t1500->b + hr_ix(_i1500, _t1500->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:56"); }))).l_)) + (int64_t)i_362)); (int32_t*)_t1499->b + hr_ix(_i1499, _t1499->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:56"); }))));
}
static int64_t f91_pindex(int64_t obj_369) {
int64_t st_370 = g701; 
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
{ int32_t *_t1509 = &(((*({ hrv *_t1510 = &(g696); int64_t _i1510 = r_375; (S4*)_t1510->b + hr_ix(_i1510, _t1510->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:336"); }))).a_); *_t1509 = ((int32_t)(obj_369)); }
{ int32_t *_t1511 = &(((*({ hrv *_t1512 = &(g696); int64_t _i1512 = r_375; (S4*)_t1512->b + hr_ix(_i1512, _t1512->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:336"); }))).b_); *_t1511 = ((int32_t)(lo_372)); }
if (lfe_373) { { uint16_t *_t1513 = &(((*({ hrv *_t1514 = &(g696); int64_t _i1514 = r_375; (S4*)_t1514->b + hr_ix(_i1514, _t1514->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:337"); }))).fl_); *_t1513 = ((uint16_t)1LL); }
 }
if (((f31_tk()) != (((int64_t)8LL)))) { if (f41_is(((int64_t)51LL))) { { uint16_t *_t1517 = &(((*({ hrv *_t1518 = &(g696); int64_t _i1518 = r_375; (S4*)_t1518->b + hr_ix(_i1518, _t1518->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:338"); }))).fl_); *_t1517 = ((uint16_t)((uint64_t)(*_t1517) | (uint64_t)((uint16_t)2LL))); }
 }
{ int64_t q__376 = f61_pexpr(); 
{ int32_t *_t1520 = &(((*({ hrv *_t1521 = &(g696); int64_t _i1521 = r_375; (S4*)_t1521->b + hr_ix(_i1521, _t1521->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:338"); }))).c_); *_t1520 = ((int32_t)(q__376)); }
 }
 }
 } else { if (lfe_373) { (void)(f38_perr(hr_str("'^' bounds are only valid in slices", 35)));
 }
r_375 = f40_mk(((int64_t)12LL), st_370);
{ int32_t *_t1524 = &(((*({ hrv *_t1525 = &(g696); int64_t _i1525 = r_375; (S4*)_t1525->b + hr_ix(_i1525, _t1525->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:341"); }))).a_); *_t1524 = ((int32_t)(obj_369)); }
{ int32_t *_t1526 = &(((*({ hrv *_t1527 = &(g696); int64_t _i1527 = r_375; (S4*)_t1527->b + hr_ix(_i1527, _t1527->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:341"); }))).b_); *_t1526 = ((int32_t)(lo_372)); }
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
int64_t st_414 = g701; 
(void)(f33_nx());
int64_t n_415 = f40_mk(((int64_t)51LL), st_414); 
{ int64_t q__416 = f50_declname(hr_str("struct declaration", 18)); 
{ int32_t *_t1536 = &(((*({ hrv *_t1537 = &(g696); int64_t _i1537 = n_415; (S4*)_t1537->b + hr_ix(_i1537, _t1537->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:618"); }))).s_); *_t1536 = ((int32_t)(q__416)); }
 }
{ int32_t *_t1538 = &(((*({ hrv *_t1539 = &(g696); int64_t _i1539 = n_415; (S4*)_t1539->b + hr_ix(_i1539, _t1539->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:618"); }))).a_); *_t1538 = ((int32_t)(g708)); }
{ int64_t q__417 = f51_pgenerics(); 
{ int32_t *_t1541 = &(((*({ hrv *_t1542 = &(g696); int64_t _i1542 = n_415; (S4*)_t1542->b + hr_ix(_i1542, _t1542->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:619"); }))).d_); *_t1541 = ((int32_t)(q__417)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("struct declaration", 18)));
(void)(f95_pfields(n_415, hr_str("struct body", 11)));
(void)(f39_ex(((int64_t)10LL), hr_str("struct declaration", 18)));
return n_415;
}
static void f95_pfields(int64_t n_418, hsl ctx_419) {
int64_t m_420 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t f_421 = f40_mk(((int64_t)55LL), g701); 
if (f41_is(((int64_t)70LL))) { { uint16_t *_t1552 = &(((*({ hrv *_t1553 = &(g696); int64_t _i1553 = f_421; (S4*)_t1553->b + hr_ix(_i1553, _t1553->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:601"); }))).fl_); *_t1552 = ((uint16_t)4LL); }
if (((f31_tk()) == (((int64_t)2LL)))) { { int32_t *_t1555 = &(((*({ hrv *_t1556 = &(g696); int64_t _i1556 = f_421; (S4*)_t1556->b + hr_ix(_i1556, _t1556->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:601"); }))).c_); *_t1555 = ((int32_t)(((*({ hrv *_t1557 = &(g906); int64_t _i1557 = g701; (S3*)_t1557->b + hr_ix(_i1557, _t1557->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:601"); }))).v_)); }
(void)(f33_nx());
 }
 } else { bool cq_422 = f41_is(((int64_t)69LL)); 
if ((cq_422 || f41_is(((int64_t)66LL)))) { { uint16_t *_t1561 = &(((*({ hrv *_t1562 = &(g696); int64_t _i1562 = f_421; (S4*)_t1562->b + hr_ix(_i1562, _t1562->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:604"); }))).fl_); *_t1561 = ({ uint16_t _r1563; if (cq_422) { _r1563 = ((uint16_t)3LL);  } else { _r1563 = ((uint16_t)1LL);  } _r1563; }); }
 }
{ int64_t q__423 = f34_ident(ctx_419); 
{ int32_t *_t1565 = &(((*({ hrv *_t1566 = &(g696); int64_t _i1566 = f_421; (S4*)_t1566->b + hr_ix(_i1566, _t1566->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:605"); }))).s_); *_t1565 = ((int32_t)(q__423)); }
 }
if ((!(f75_amni_type()))) { (void)(f39_ex(((int64_t)13LL), ctx_419));
 }
{ int64_t q__424 = f53_ptype(); 
{ int32_t *_t1570 = &(((*({ hrv *_t1571 = &(g696); int64_t _i1571 = f_421; (S4*)_t1571->b + hr_ix(_i1571, _t1571->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:607"); }))).a_); *_t1570 = ((int32_t)(q__424)); }
 }
if (f41_is(((int64_t)36LL))) { { int64_t q__425 = f61_pexpr(); 
{ int32_t *_t1574 = &(((*({ hrv *_t1575 = &(g696); int64_t _i1575 = f_421; (S4*)_t1575->b + hr_ix(_i1575, _t1575->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:608"); }))).b_); *_t1574 = ((int32_t)(q__425)); }
 }
 }
 }
(void)(({ hrv *_v1576 = &(g698); int32_t _x1576 = ((int32_t)(f_421)); int32_t *_p1576 = (int32_t*)hr_grow(_v1576, 1, sizeof _x1576); *_p1576 = _x1576; _p1576; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1547; }
 }
 } _bk1547:; 
(void)(f59_setl(n_418, m_420));
}
static int64_t f96_penum(void) {
int64_t st_426 = g701; 
(void)(f33_nx());
int64_t n_427 = f40_mk(((int64_t)52LL), st_426); 
{ int64_t q__428 = f50_declname(hr_str("enum declaration", 16)); 
{ int32_t *_t1582 = &(((*({ hrv *_t1583 = &(g696); int64_t _i1583 = n_427; (S4*)_t1583->b + hr_ix(_i1583, _t1583->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:628"); }))).s_); *_t1582 = ((int32_t)(q__428)); }
 }
{ int32_t *_t1584 = &(((*({ hrv *_t1585 = &(g696); int64_t _i1585 = n_427; (S4*)_t1585->b + hr_ix(_i1585, _t1585->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:628"); }))).a_); *_t1584 = ((int32_t)(g708)); }
{ int64_t q__429 = f51_pgenerics(); 
{ int32_t *_t1587 = &(((*({ hrv *_t1588 = &(g696); int64_t _i1588 = n_427; (S4*)_t1588->b + hr_ix(_i1588, _t1588->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:629"); }))).d_); *_t1587 = ((int32_t)(q__429)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("enum declaration", 16)));
int64_t m_430 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t v_431 = f40_mk(((int64_t)56LL), g701); 
{ int64_t q__432 = f34_ident(hr_str("enum variant", 12)); 
{ int32_t *_t1596 = &(((*({ hrv *_t1597 = &(g696); int64_t _i1597 = v_431; (S4*)_t1597->b + hr_ix(_i1597, _t1597->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:633"); }))).s_); *_t1596 = ((int32_t)(q__432)); }
 }
if (f41_is(((int64_t)9LL))) { { uint16_t *_t1599 = &(((*({ hrv *_t1600 = &(g696); int64_t _i1600 = v_431; (S4*)_t1600->b + hr_ix(_i1600, _t1600->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:634"); }))).fl_); *_t1599 = ((uint16_t)1LL); }
(void)(f95_pfields(v_431, hr_str("variant body", 12)));
(void)(f39_ex(((int64_t)10LL), hr_str("enum variant", 12)));
 }
(void)(({ hrv *_v1603 = &(g698); int32_t _x1603 = ((int32_t)(v_431)); int32_t *_p1603 = (int32_t*)hr_grow(_v1603, 1, sizeof _x1603); *_p1603 = _x1603; _p1603; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk1591; }
 }
 } _bk1591:; 
(void)(f59_setl(n_427, m_430));
(void)(f39_ex(((int64_t)10LL), hr_str("enum declaration", 16)));
return n_427;
}
static void f97_collect(int64_t file_440, int64_t t0_441, int64_t t1_442) {
{ int64_t _e1608 = t1_442; for (int64_t _k1608 = t0_441; _k1608 < _e1608; _k1608++) { int64_t i_443 = (int64_t)_k1608; int64_t n_444 = ((int64_t)((*({ hrv *_t1609 = &(g699); int64_t _i1609 = i_443; (int32_t*)_t1609->b + hr_ix(_i1609, _t1609->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:27"); })))); 
S4 x_445 = (*({ hrv *_t1610 = &(g696); int64_t _i1610 = n_444; (S4*)_t1610->b + hr_ix(_i1610, _t1610->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:28"); })); 
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
if (((k_446) == (((int64_t)33LL)))) { (void)(f99_dadd(((int64_t)5LL), n_444, file_440, f98_qual(((int64_t)((x_445).c_)), ((int64_t)((*({ hrv *_t1622 = &(g697); int64_t _i1622 = (x_445).l_; (int32_t*)_t1622->b + hr_ix(_i1622, _t1622->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:34"); })))))));
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
while ((((g482).n) <= (name_453))) { (void)(({ hrv *_v1632 = &(g482); int32_t _x1632 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1632 = (int32_t*)hr_grow(_v1632, 1, sizeof _x1632); *_p1632 = _x1632; _p1632; }));
 } _bk1631:; 
int64_t i_454 = (g481).n; 
(void)(({ hrv *_v1633 = &(g481); S5 _x1633 = ((S5){ .k_ = ((uint8_t)(k_450)), .node_ = ((int32_t)(node_451)), .file_ = ((int32_t)(file_452)), .next_ = (*({ hrv *_t1634 = &(g482); int64_t _i1634 = name_453; (int32_t*)_t1634->b + hr_ix(_i1634, _t1634->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:19"); })), .name_ = ((int32_t)(name_453)), }); S5 *_p1633 = (S5*)hr_grow(_v1633, 1, sizeof _x1633); *_p1633 = _x1633; _p1633; }));
{ int32_t *_t1635 = &((*({ hrv *_t1636 = &(g482); int64_t _i1636 = name_453; (int32_t*)_t1636->b + hr_ix(_i1636, _t1636->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:20"); }))); *_t1635 = ((int32_t)(i_454)); }
}
static L49 f100_lib_path(hsl name_459) {
L49 p_460 = ({ L49 _t1637; memset(&_t1637, 0, sizeof _t1637); _t1637.n = 0; _t1637; }); 
(void)(({ L49 *_v1638 = &(p_460); hsl _s1638 = hr_sl(g485); if (_v1638->n + _s1638.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:56"); memmove(_v1638->e + _v1638->n, _s1638.p, (size_t)_s1638.n * sizeof _v1638->e[0]); _v1638->n += _s1638.n; }));
(void)(({ L49 *_v1639 = &(p_460); uint8_t _x1639 = ((uint8_t)47LL); if (_v1639->n >= 1024) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:56"); _v1639->e[_v1639->n] = _x1639; &_v1639->e[_v1639->n++]; }));
(void)(({ L49 *_v1640 = &(p_460); hsl _s1640 = name_459; if (_v1640->n + _s1640.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:56"); memmove(_v1640->e + _v1640->n, _s1640.p, (size_t)_s1640.n * sizeof _v1640->e[0]); _v1640->n += _s1640.n; }));
(void)(({ L49 *_v1641 = &(p_460); hsl _s1641 = hr_str(".amni", 5); if (_v1641->n + _s1641.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:56"); memmove(_v1641->e + _v1641->n, _s1641.p, (size_t)_s1641.n * sizeof _v1641->e[0]); _v1641->n += _s1641.n; }));
return p_460;
}
static int64_t f101_load_import(int64_t name_463, int64_t from_464, int64_t t_465) {
L49 p_466 = ({ L49 _t1642; memset(&_t1642, 0, sizeof _t1642); _t1642.n = 0; _t1642; }); 
(void)(({ L49 *_v1643 = &(p_466); hsl _s1643 = hr_sl(g484); if (_v1643->n + _s1643.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:59"); memmove(_v1643->e + _v1643->n, _s1643.p, (size_t)_s1643.n * sizeof _v1643->e[0]); _v1643->n += _s1643.n; }));
(void)(({ L49 *_v1644 = &(p_466); uint8_t _x1644 = ((uint8_t)47LL); if (_v1644->n >= 1024) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:59"); _v1644->e[_v1644->n] = _x1644; &_v1644->e[_v1644->n++]; }));
(void)(({ L49 *_v1645 = &(p_466); hsl _s1645 = f10_nm(name_463); if (_v1645->n + _s1645.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:59"); memmove(_v1645->e + _v1645->n, _s1645.p, (size_t)_s1645.n * sizeof _v1645->e[0]); _v1645->n += _s1645.n; }));
(void)(({ L49 *_v1647 = &(p_466); hsl _s1647 = hr_str(".amni", 5); if (_v1647->n + _s1647.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:59"); memmove(_v1647->e + _v1647->n, _s1647.p, (size_t)_s1647.n * sizeof _v1647->e[0]); _v1647->n += _s1647.n; }));
int64_t r_467 = f19_try_load(({ hsl _t1649 = ({ L49 *_t1650 = &(p_466); (hsl){ (uint8_t*)_t1650->e, _t1650->n }; }); int64_t _l1649 = 0, _h1649 = _t1649.n; if (_l1649 < 0 || _h1649 < _l1649 || _h1649 > _t1649.n) hr_slerr(_l1649, _h1649, _t1649.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:60"); (hsl){ _t1649.p + _l1649 * (int64_t)sizeof(uint8_t), _h1649 - _l1649 }; })); 
if (((r_467) == (((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))) { L49 lp_468 = f100_lib_path(f10_nm(name_463)); 
r_467 = f19_try_load(({ hsl _t1654 = ({ L49 *_t1655 = &(lp_468); (hsl){ (uint8_t*)_t1655->e, _t1655->n }; }); int64_t _l1654 = 0, _h1654 = _t1654.n; if (_l1654 < 0 || _h1654 < _l1654 || _h1654 > _t1654.n) hr_slerr(_l1654, _h1654, _t1654.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:61"); (hsl){ _t1654.p + _l1654 * (int64_t)sizeof(uint8_t), _h1654 - _l1654 }; }));
 }
if (((r_467) == (((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))) { hrv m_469 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1657 = &(m_469); hr_fs(_o1657, hr_str("cannot find module ", 19)); hr_fs(_o1657, f10_nm(name_463)); }));
(void)(f102_derr(t_465, hr_sl(m_469)));
return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
return r_467;
}
static void f102_derr(int64_t t_470, hsl m_471) {
if ((((g487).n) > (((int64_t)0LL)))) { return;
 }
S3 x_474 = (*({ hrv *_t1660 = &(g906); int64_t _i1660 = f103_max(t_470, ((int64_t)0LL)); (S3*)_t1660->b + hr_ix(_i1660, _t1660->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:14"); })); 
(void)(({ hrv *_v1662 = &(g487); hsl _s1662 = f10_nm(((int64_t)(((*({ hrv *_t1664 = &(g905); int64_t _i1664 = (x_474).f_; (S2*)_t1664->b + hr_ix(_i1664, _t1664->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:14"); }))).name_))); hr_append(_v1662, _s1662.p, _s1662.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o1665 = &(g487); hr_fs(_o1665, hr_str(":", 1)); hr_fi(_o1665, (x_474).line_); hr_fs(_o1665, hr_str(": error: ", 9)); hr_fs(_o1665, m_471); }));
}
static int64_t f103_max(int64_t a_472, int64_t b_473) {
if (((a_472) < (b_473))) { return b_473;
 }
return a_472;
}
static bool f104_check_program(void) {
g395 = f105_new_inst(((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)0LL), (g696).n, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
{ uint8_t *_t1667 = &(((*({ hrv *_t1668 = &(g380); int64_t _i1668 = g395; (S6*)_t1668->b + hr_ix(_i1668, _t1668->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:455"); }))).st_); *_t1667 = ((uint8_t)2LL); }
g393 = g395;
g394 = g395;
int64_t md_489 = f106_lookup(f8_intern(hr_str("main", 4)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)4LL)); 
if (((md_489) < (((int64_t)0LL)))) { (void)(f108_cerr(((int64_t)0LL), hr_str("no main function", 16)));
return false;
 }
{ hrv *_v1673 = &(g481); for (int64_t _k1673 = 0; _k1673 < _v1673->n; _k1673++) { S5 d_493 = ((S5*)_v1673->b)[_k1673]; int64_t i_494 = (int64_t)_k1673; if ((((((int64_t)((d_493).k_))) == (((int64_t)5LL))) && (((d_493).file_) == (((int32_t)0LL))))) { (void)(f109_global_type(i_494));
 }
 } } _bk1672:; 
int64_t mi_1455 = f250_get_inst(((int64_t)(((*({ hrv *_t1676 = &(g481); int64_t _i1676 = md_489; (S5*)_t1676->b + hr_ix(_i1676, _t1676->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:460"); }))).node_)), (g312).n, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
{ hrv *_v1678 = &(g481); for (int64_t _k1678 = 0; _k1678 < _v1678->n; _k1678++) { S5 d_1456 = ((S5*)_v1678->b)[_k1678]; int64_t i_1457 = (int64_t)_k1678; if (((((int64_t)((d_1456).k_))) == (((int64_t)5LL)))) { (void)(f109_global_type(i_1457));
 }
 } } _bk1677:; 
(void)(f255_propagate_calls());
return ((g397) == (((int64_t)0LL)));
}
static int64_t f105_new_inst(int64_t node_477, int64_t lo_478, int64_t hi_479, int64_t par_480) {
int64_t i_481 = (g380).n; 
(void)(({ hrv *_v1681 = &(g380); S6 _x1681 = ((S6){ .node_ = ((int32_t)(node_477)), .lo_ = ((int32_t)(lo_478)), .hi_ = ((int32_t)(hi_479)), .ab_ = ((int32_t)((g387).n)), .par_ = ((int32_t)(par_480)), .cfn_ = ((int32_t)(i_481)), .g0_ = ((int32_t)((g386).n)), .gn_ = ((int32_t)0LL), .ret_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .p0_ = ((int32_t)0LL), .pn_ = ((int32_t)0LL), .st_ = ((uint8_t)0LL), .blk_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .bown_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .name_ = ({ int32_t _r1682; if (((node_477) >= (((int64_t)0LL)))) { _r1682 = ((*({ hrv *_t1683 = &(g696); int64_t _i1683 = node_477; (S4*)_t1683->b + hr_ix(_i1683, _t1683->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:30"); }))).s_;  } else { _r1682 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));  } _r1682; }), }); S6 *_p1681 = (S6*)hr_grow(_v1681, 1, sizeof _x1681); *_p1681 = _x1681; _p1681; }));
int64_t n_482 = ((int64_t)((int64_t)hi_479 - (int64_t)lo_478)); 
(void)(({ hrv *_v1684 = &(g387); int64_t _k1684 = ((int64_t)((int64_t)(g387).n + (int64_t)n_482)); if (_k1684 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:32"); int32_t _x1684 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1684 = _v1684->n; hr_resize(_v1684, _k1684, sizeof _x1684); for (int64_t _j = _o1684; _j < _k1684; _j++) ((int32_t*)_v1684->b)[_j] = _x1684; }));
(void)(({ hrv *_v1685 = &(g388); int64_t _k1685 = ((int64_t)((int64_t)(g388).n + (int64_t)n_482)); if (_k1685 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:32"); int32_t _x1685 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1685 = _v1685->n; hr_resize(_v1685, _k1685, sizeof _x1685); for (int64_t _j = _o1685; _j < _k1685; _j++) ((int32_t*)_v1685->b)[_j] = _x1685; }));
(void)(({ hrv *_v1686 = &(g389); int64_t _k1686 = ((int64_t)((int64_t)(g389).n + (int64_t)n_482)); if (_k1686 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:32"); uint8_t _x1686 = ((uint8_t)0LL); int64_t _o1686 = _v1686->n; hr_resize(_v1686, _k1686, sizeof _x1686); for (int64_t _j = _o1686; _j < _k1686; _j++) ((uint8_t*)_v1686->b)[_j] = _x1686; }));
(void)(({ hrv *_v1687 = &(g390); int64_t _k1687 = ((int64_t)((int64_t)(g390).n + (int64_t)n_482)); if (_k1687 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:32"); int32_t _x1687 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1687 = _v1687->n; hr_resize(_v1687, _k1687, sizeof _x1687); for (int64_t _j = _o1687; _j < _k1687; _j++) ((int32_t*)_v1687->b)[_j] = _x1687; }));
(void)(({ hrv *_v1688 = &(g391); int64_t _k1688 = ((int64_t)((int64_t)(g391).n + (int64_t)n_482)); if (_k1688 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:32"); int32_t _x1688 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o1688 = _v1688->n; hr_resize(_v1688, _k1688, sizeof _x1688); for (int64_t _j = _o1688; _j < _k1688; _j++) ((int32_t*)_v1688->b)[_j] = _x1688; }));
return i_481;
}
static int64_t f106_lookup(int64_t name_483, int64_t ns_484, int64_t k_485) {
if (((ns_484) >= (((int64_t)0LL)))) { int64_t d_487 = f107_dmap(f98_qual(ns_484, name_483)); 
while (((d_487) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1692 = &(g481); int64_t _i1692 = d_487; (S5*)_t1692->b + hr_ix(_i1692, _t1692->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:74"); }))).k_))) == (k_485))) { return d_487;
 }
d_487 = ((int64_t)(((*({ hrv *_t1693 = &(g481); int64_t _i1693 = d_487; (S5*)_t1693->b + hr_ix(_i1693, _t1693->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:74"); }))).next_));
 } _bk1691:; 
 }
int64_t d_488 = f107_dmap(name_483); 
while (((d_488) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1696 = &(g481); int64_t _i1696 = d_488; (S5*)_t1696->b + hr_ix(_i1696, _t1696->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:76"); }))).k_))) == (k_485))) { return d_488;
 }
d_488 = ((int64_t)(((*({ hrv *_t1697 = &(g481); int64_t _i1697 = d_488; (S5*)_t1697->b + hr_ix(_i1697, _t1697->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:76"); }))).next_));
 } _bk1695:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f107_dmap(int64_t name_486) {
return ({ int64_t _r1698; if ((((name_486) < (((int64_t)0LL))) || ((name_486) >= ((g482).n)))) { _r1698 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1698 = ((int64_t)((*({ hrv *_t1699 = &(g482); int64_t _i1699 = name_486; (int32_t*)_t1699->b + hr_ix(_i1699, _t1699->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:15"); }))));  } _r1698; });
}
static void f108_cerr(int64_t n_490, hsl m_491) {
g397++;
if ((((g396).n) > (((int64_t)0LL)))) { return;
 }
S3 x_492 = (*({ hrv *_t1700 = &(g906); int64_t _i1700 = ((*({ hrv *_t1701 = &(g696); int64_t _i1701 = f103_max(n_490, ((int64_t)0LL)); (S4*)_t1701->b + hr_ix(_i1701, _t1701->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:27"); }))).t_; (S3*)_t1700->b + hr_ix(_i1700, _t1700->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:27"); })); 
(void)(({ hrv *_v1703 = &(g396); hsl _s1703 = f10_nm(((int64_t)(((*({ hrv *_t1705 = &(g905); int64_t _i1705 = (x_492).f_; (S2*)_t1705->b + hr_ix(_i1705, _t1705->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:27"); }))).name_))); hr_append(_v1703, _s1703.p, _s1703.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o1706 = &(g396); hr_fs(_o1706, hr_str(":", 1)); hr_fi(_o1706, (x_492).line_); hr_fs(_o1706, hr_str(": error: ", 9)); hr_fs(_o1706, m_491); }));
}
static int64_t f109_global_type(int64_t d_495) {
while ((((g442).n) < ((g481).n))) { (void)(({ hrv *_v1708 = &(g442); int32_t _x1708 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1708 = (int32_t*)hr_grow(_v1708, 1, sizeof _x1708); *_p1708 = _x1708; _p1708; }));
(void)(({ hrv *_v1709 = &(g443); uint8_t _x1709 = ((uint8_t)0LL); uint8_t *_p1709 = (uint8_t*)hr_grow(_v1709, 1, sizeof _x1709); *_p1709 = _x1709; _p1709; }));
 } _bk1707:; 
if ((((*({ hrv *_t1710 = &(g442); int64_t _i1710 = d_495; (int32_t*)_t1710->b + hr_ix(_i1710, _t1710->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:380"); }))) >= (((int32_t)0LL)))) { return ((int64_t)((*({ hrv *_t1711 = &(g442); int64_t _i1711 = d_495; (int32_t*)_t1711->b + hr_ix(_i1711, _t1711->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:380"); }))));
 }
int64_t g_496 = ((int64_t)(((*({ hrv *_t1712 = &(g481); int64_t _i1712 = d_495; (S5*)_t1712->b + hr_ix(_i1712, _t1712->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:381"); }))).node_)); 
S4 x_497 = (*({ hrv *_t1713 = &(g696); int64_t _i1713 = g_496; (S4*)_t1713->b + hr_ix(_i1713, _t1713->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:382"); })); 
int64_t saved_498 = g393; 
int64_t sc_499 = g394; 
g393 = g395;
g394 = g395;
int64_t t_500 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((x_497).a_) >= (((int32_t)0LL)))) { t_500 = f113_rtype(((int64_t)((x_497).a_)), f110_ns_of(g_496));
{ int32_t *_t1716 = &((*({ hrv *_t1717 = &(g442); int64_t _i1717 = d_495; (int32_t*)_t1717->b + hr_ix(_i1717, _t1717->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:386"); }))); *_t1716 = ((int32_t)(t_500)); }
if ((((x_497).b_) >= (((int32_t)0LL)))) { int64_t iv_670 = f90_kid(((int64_t)((x_497).b_)), ((int64_t)0LL)); 
(void)(f137_ck(iv_670, t_500));
(void)(f140_conv(iv_670, t_500));
 }
 } else { if ((((*({ hrv *_t1721 = &(g443); int64_t _i1721 = d_495; (uint8_t*)_t1721->b + hr_ix(_i1721, _t1721->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:388"); }))) == (((uint8_t)1LL)))) { (void)(f108_cerr(g_496, hr_str("global initializer depends on itself", 36)));
g393 = saved_498;
g394 = sc_499;
return g567;
 }
{ uint8_t *_t1723 = &((*({ hrv *_t1724 = &(g443); int64_t _i1724 = d_495; (uint8_t*)_t1724->b + hr_ix(_i1724, _t1724->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:389"); }))); *_t1723 = ((uint8_t)1LL); }
int64_t iv_1452 = f90_kid(((int64_t)((x_497).b_)), ((int64_t)0LL)); 
(void)(f137_ck(iv_1452, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
t_500 = f184_default_t(iv_1452);
if (((((*({ hrv *_t1728 = &(g543); int64_t _i1728 = t_500; (S1*)_t1728->b + hr_ix(_i1728, _t1728->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:393"); }))).k_) == (((uint8_t)18LL)))) { t_500 = g568;
 }
if (((((((*({ hrv *_t1729 = &(g543); int64_t _i1729 = t_500; (S1*)_t1729->b + hr_ix(_i1729, _t1729->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:394"); }))).k_) == (((uint8_t)7LL))) && (((((*({ hrv *_t1730 = &(g696); int64_t _i1730 = iv_1452; (S4*)_t1730->b + hr_ix(_i1730, _t1730->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:394"); }))).k_) == (((uint8_t)14LL))) || ((((*({ hrv *_t1731 = &(g696); int64_t _i1731 = iv_1452; (S4*)_t1731->b + hr_ix(_i1731, _t1731->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:394"); }))).k_) == (((uint8_t)17LL))))) && ((((uint16_t)((uint64_t)(x_497).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))))) { t_500 = f136_t_enum(((int64_t)(((*({ hrv *_t1733 = &(g543); int64_t _i1733 = t_500; (S1*)_t1733->b + hr_ix(_i1733, _t1733->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:394"); }))).a_)), false);
(void)(f142_set_cv(iv_1452, t_500));
 }
{ int32_t *_t1735 = &((*({ hrv *_t1736 = &(g442); int64_t _i1736 = d_495; (int32_t*)_t1736->b + hr_ix(_i1736, _t1736->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:395"); }))); *_t1735 = ((int32_t)(t_500)); }
 }
if ((!(f254_ORD_HAS(d_495)))) { (void)(({ hrv *_v1738 = &(g401); int32_t _x1738 = ((int32_t)(d_495)); int32_t *_p1738 = (int32_t*)hr_grow(_v1738, 1, sizeof _x1738); *_p1738 = _x1738; _p1738; }));
 }
g393 = saved_498;
g394 = sc_499;
return t_500;
}
static int64_t f110_ns_of(int64_t n_501) {
return f112_file_ns(f111_node_file(n_501));
}
static int64_t f111_node_file(int64_t n_502) {
return ((int64_t)(((*({ hrv *_t1741 = &(g906); int64_t _i1741 = ((*({ hrv *_t1742 = &(g696); int64_t _i1742 = n_502; (S4*)_t1742->b + hr_ix(_i1742, _t1742->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:23"); }))).t_; (S3*)_t1741->b + hr_ix(_i1741, _t1741->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:23"); }))).f_));
}
static int64_t f112_file_ns(int64_t f_503) {
return ({ int64_t _r1743; if (((f_503) < ((g488).n))) { _r1743 = ((int64_t)((*({ hrv *_t1744 = &(g488); int64_t _i1744 = f_503; (int32_t*)_t1744->b + hr_ix(_i1744, _t1744->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:24"); }))));  } else { _r1743 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1743; });
}
static int64_t f113_rtype(int64_t n_504, int64_t ns_505) {
if (((n_504) < (((int64_t)0LL)))) { return g550;
 }
S4 x_506 = (*({ hrv *_t1745 = &(g696); int64_t _i1745 = n_504; (S4*)_t1745->b + hr_ix(_i1745, _t1745->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:93"); })); 
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
if ((((((*({ hrv *_t1757 = &(g543); int64_t _i1757 = e_512; (S1*)_t1757->b + hr_ix(_i1757, _t1757->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:107"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t1758 = &(g543); int64_t _i1758 = e_512; (S1*)_t1758->b + hr_ix(_i1758, _t1758->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:107"); }))).c_) < (((int32_t)0LL))))) { if (((((int64_t)((int64_t)fl_513 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { return f119_t_ref(((int64_t)(((*({ hrv *_t1760 = &(g543); int64_t _i1760 = e_512; (S1*)_t1760->b + hr_ix(_i1760, _t1760->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:107"); }))).a_)), ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1761 = &(g543); int64_t _i1761 = e_512; (S1*)_t1761->b + hr_ix(_i1761, _t1761->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:107"); }))).fl_)) | (int64_t)((int64_t)2LL))));
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
if (((((*({ hrv *_t1780 = &(g543); int64_t _i1780 = b_593; (S1*)_t1780->b + hr_ix(_i1780, _t1780->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:120"); }))).k_) != (((uint8_t)6LL)))) { (void)(f102_derr(((int64_t)((x_506).t_)), hr_str("variant type of a non-enum", 26)));
return g567;
 }
int64_t ei_594 = ((int64_t)(((*({ hrv *_t1782 = &(g543); int64_t _i1782 = b_593; (S1*)_t1782->b + hr_ix(_i1782, _t1782->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:121"); }))).a_)); 
{ int32_t _e1784 = ((*({ hrv *_t1785 = &(g548); int64_t _i1785 = ei_594; (S8*)_t1785->b + hr_ix(_i1785, _t1785->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:122"); }))).vnum_; for (int32_t _k1784 = 0; _k1784 < _e1784; _k1784++) { int32_t i_595 = (int32_t)_k1784; if (((((*({ hrv *_t1786 = &(g549); int64_t _i1786 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1787 = &(g548); int64_t _i1787 = ei_594; (S8*)_t1787->b + hr_ix(_i1787, _t1787->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:122"); }))).v0_)) + (int64_t)((int64_t)(i_595)))); (S9*)_t1786->b + hr_ix(_i1786, _t1786->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:122"); }))).name_) == ((x_506).s_))) { return f125_t_variant(ei_594, ((int64_t)(i_595)));
 }
 } } _bk1783:; 
hrv m_598 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1792 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1790 = &(m_598); hr_fs(_o1790, hr_str("no variant ", 11)); hr_fs(_o1790, f10_nm(((int64_t)((x_506).s_)))); hr_fs(_o1790, hr_str(" in ", 4)); hr_fs(_o1790, hr_sl(*hr_tmp(&_t1792, f126_ty_name(b_593)))); }));
}
(void)(f102_derr(((int64_t)((x_506).t_)), hr_sl(m_598)));
return g567;
 }
if (((k_507) == (((int64_t)45LL)))) { return g570;
 }
if (((k_507) == (((int64_t)41LL)))) { int64_t name_614 = ((int64_t)((x_506).s_)); 
if ((((x_506).n_) == (((int32_t)0LL)))) { int64_t g_617 = f130_gb_find(name_614); 
if (((g_617) >= (((int64_t)0LL)))) { return g_617;
 }
 }
L66 args_618 = ({ L66 _t1796; memset(&_t1796, 0, sizeof _t1796); _t1796.n = 0; _t1796; }); 
{ int32_t _e1798 = (x_506).n_; for (int32_t _k1798 = 0; _k1798 < _e1798; _k1798++) { int32_t i_619 = (int32_t)_k1798; int64_t at0_620 = f113_rtype(f90_kid(n_504, ((int64_t)(i_619))), ns_505); 
(void)(({ L66 *_v1801 = &(args_618); int32_t _x1801 = ((int32_t)(at0_620)); if (_v1801->n >= 16) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:131"); _v1801->e[_v1801->n] = _x1801; &_v1801->e[_v1801->n++]; }));
 } } _bk1797:; 
int64_t d_621 = f116_lookup_q(name_614, ns_505, ((int64_t)1LL)); 
if (((d_621) >= (((int64_t)0LL)))) { return f134_t_struct(f131_inst_struct(((int64_t)(((*({ hrv *_t1805 = &(g481); int64_t _i1805 = d_621; (S5*)_t1805->b + hr_ix(_i1805, _t1805->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:133"); }))).node_)), ({ hsl _t1806 = ({ L66 *_t1807 = &(args_618); (hsl){ (uint8_t*)_t1807->e, _t1807->n }; }); int64_t _l1806 = 0, _h1806 = _t1806.n; if (_l1806 < 0 || _h1806 < _l1806 || _h1806 > _t1806.n) hr_slerr(_l1806, _h1806, _t1806.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:133"); (hsl){ _t1806.p + _l1806 * (int64_t)sizeof(int32_t), _h1806 - _l1806 }; })));
 }
d_621 = f116_lookup_q(name_614, ns_505, ((int64_t)2LL));
if (((d_621) >= (((int64_t)0LL)))) { return f136_t_enum(f135_inst_enum(((int64_t)(((*({ hrv *_t1811 = &(g481); int64_t _i1811 = d_621; (S5*)_t1811->b + hr_ix(_i1811, _t1811->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:135"); }))).node_)), ({ hsl _t1812 = ({ L66 *_t1813 = &(args_618); (hsl){ (uint8_t*)_t1813->e, _t1813->n }; }); int64_t _l1812 = 0, _h1812 = _t1812.n; if (_l1812 < 0 || _h1812 < _l1812 || _h1812 > _t1812.n) hr_slerr(_l1812, _h1812, _t1812.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:135"); (hsl){ _t1812.p + _l1812 * (int64_t)sizeof(int32_t), _h1812 - _l1812 }; })), ((((uint16_t)((uint64_t)(x_506).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))));
 }
d_621 = f116_lookup_q(name_614, ns_505, ((int64_t)3LL));
if (((d_621) >= (((int64_t)0LL)))) { int64_t an_668 = ((int64_t)(((*({ hrv *_t1815 = &(g481); int64_t _i1815 = d_621; (S5*)_t1815->b + hr_ix(_i1815, _t1815->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:137"); }))).node_)); 
return f113_rtype(((int64_t)(((*({ hrv *_t1817 = &(g696); int64_t _i1817 = an_668; (S4*)_t1817->b + hr_ix(_i1817, _t1817->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:137"); }))).b_)), f110_ns_of(an_668));
 }
hrv m_669 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1820 = &(m_669); hr_fs(_o1820, hr_str("unknown type ", 13)); hr_fs(_o1820, f10_nm(name_614)); }));
(void)(f102_derr(((int64_t)((x_506).t_)), hr_sl(m_669)));
return g567;
 }
(void)(f102_derr(((int64_t)((x_506).t_)), hr_str("bad type", 8)));
return g567;
}
static int64_t f114_prim_type(int64_t k_508) {
if (((k_508) == (((int64_t)89LL)))) { return g551;
 }
if (((k_508) == (((int64_t)90LL)))) { return g566;
 }
if (((k_508) == (((int64_t)99LL)))) { return g560;
 }
if ((((k_508) == (((int64_t)100LL))) || ((k_508) == (((int64_t)104LL))))) { return g561;
 }
int64_t s_510 = f115_int_storage_of_tok(k_508); 
return ({ int64_t _r1825; if (((s_510) >= (((int64_t)0LL)))) { _r1825 = f17_t_int(s_510);  } else { _r1825 = g567;  } _r1825; });
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
while (((d_523) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1832 = &(g481); int64_t _i1832 = d_523; (S5*)_t1832->b + hr_ix(_i1832, _t1832->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:87"); }))).k_))) == (k_517))) { return d_523;
 }
d_523 = ((int64_t)(((*({ hrv *_t1833 = &(g481); int64_t _i1833 = d_523; (S5*)_t1833->b + hr_ix(_i1833, _t1833->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:87"); }))).next_));
 } _bk1831:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
return f106_lookup(b_522, ns_516, k_517);
}
static M55 f117_split_q(int64_t q_518) {
hsl s_519 = f10_nm(q_518); 
{ int64_t _e1837 = (s_519).n; for (int64_t _k1837 = 0; _k1837 < _e1837; _k1837++) { int64_t i_520 = (int64_t)_k1837; if ((((((*({ hsl _t1838 = s_519; int64_t _i1838 = i_520; (uint8_t*)_t1838.p + hr_ix(_i1838, _t1838.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:81"); }))) == (((uint8_t)58LL))) && ((((int64_t)((int64_t)i_520 + (int64_t)((int64_t)1LL)))) < ((s_519).n))) && (((*({ hsl _t1839 = s_519; int64_t _i1839 = ((int64_t)((int64_t)i_520 + (int64_t)((int64_t)1LL))); (uint8_t*)_t1839.p + hr_ix(_i1839, _t1839.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:81"); }))) == (((uint8_t)58LL))))) { if (((i_520) == (((int64_t)0LL)))) { return (M55){ ((int64_t)(0 - (uint64_t)(((int64_t)2LL)))), f8_intern(({ hsl _t1841 = s_519; int64_t _l1841 = ((int64_t)2LL), _h1841 = _t1841.n; if (_l1841 < 0 || _h1841 < _l1841 || _h1841 > _t1841.n) hr_slerr(_l1841, _h1841, _t1841.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:81"); (hsl){ _t1841.p + _l1841 * (int64_t)sizeof(uint8_t), _h1841 - _l1841 }; })) };
 }
return (M55){ f8_intern(({ hsl _t1843 = s_519; int64_t _l1843 = 0, _h1843 = i_520; if (_l1843 < 0 || _h1843 < _l1843 || _h1843 > _t1843.n) hr_slerr(_l1843, _h1843, _t1843.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:81"); (hsl){ _t1843.p + _l1843 * (int64_t)sizeof(uint8_t), _h1843 - _l1843 }; })), f8_intern(({ hsl _t1845 = s_519; int64_t _l1845 = ((int64_t)((int64_t)i_520 + (int64_t)((int64_t)2LL))), _h1845 = _t1845.n; if (_l1845 < 0 || _h1845 < _l1845 || _h1845 > _t1845.n) hr_slerr(_l1845, _h1845, _t1845.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:81"); (hsl){ _t1845.p + _l1845 * (int64_t)sizeof(uint8_t), _h1845 - _l1845 }; })) };
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
S4 x_537 = (*({ hrv *_t1850 = &(g696); int64_t _i1850 = n_535; (S4*)_t1850->b + hr_ix(_i1850, _t1850->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:205"); })); 
int64_t k_538 = ((int64_t)((x_537).k_)); 
if (((k_538) == (((int64_t)1LL)))) { return (M57){ ((*({ hrv *_t1851 = &(g906); int64_t _i1851 = (x_537).t_; (S3*)_t1851->b + hr_ix(_i1851, _t1851->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:207"); }))).v_, ({ int64_t _r1852; if (((*({ hrv *_t1853 = &(g906); int64_t _i1853 = (x_537).t_; (S3*)_t1853->b + hr_ix(_i1853, _t1853->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:207"); }))).uns_) { _r1852 = ((int64_t)7LL);  } else { _r1852 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1852; }), true };
 }
if (((k_538) == (((int64_t)10LL)))) { M57 _t1854 = f121_ceval3(((int64_t)((x_537).a_)), ns_536); int64_t v_539 = _t1854.r0; int64_t c_540 = _t1854.r1; bool ok_541 = _t1854.r2; 
if (((((int64_t)((x_537).op_))) == (((int64_t)22LL)))) { int64_t c2_542 = ({ int64_t _r1856; if ((((c_540) == (((int64_t)7LL))) && ((((*({ hrv *_t1857 = &(g696); int64_t _i1857 = (x_537).a_; (S4*)_t1857->b + hr_ix(_i1857, _t1857->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:210"); }))).k_) == (((uint8_t)1LL))))) { _r1856 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1856 = c_540;  } _r1856; }); 
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
if (un_555) { return (M57){ f122_cwrap(((int64_t)(HR_UDIV(uint64_t, ua_556, ub_557, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:224"))), c_554), c_554, true };
 }
if (((b_550) == (((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))) { return (M57){ f122_cwrap(((int64_t)((int64_t)((int64_t)0LL) - (int64_t)a_547)), c_554), c_554, true };
 }
return (M57){ f122_cwrap(HR_SDIV(int64_t, a_547, b_550, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:224"), c_554), c_554, true };
 }
if (((o_553) == (((int64_t)25LL)))) { if (((b_550) == (((int64_t)0LL)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
if (un_555) { return (M57){ f122_cwrap(((int64_t)(HR_UDIV_MOD(uint64_t, ua_556, ub_557, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:225"))), c_554), c_554, true };
 }
if ((((b_550) == (((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))) || ((b_550) == (((int64_t)1LL))))) { return (M57){ ((int64_t)0LL), c_554, true };
 }
int64_t r_559 = HR_SMOD(int64_t, a_547, b_550, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:225"); 
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
if (((((*({ hrv *_t1886 = &(g696); int64_t _i1886 = tn0_564; (S4*)_t1886->b + hr_ix(_i1886, _t1886->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:231"); }))).k_) == (((uint8_t)40LL)))) { int64_t tc_565 = f115_int_storage_of_tok(((int64_t)(((*({ hrv *_t1888 = &(g696); int64_t _i1888 = tn0_564; (S4*)_t1888->b + hr_ix(_i1888, _t1888->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:231"); }))).op_))); 
if (((tc_565) >= (((int64_t)0LL)))) { return (M57){ f122_cwrap(v_561, tc_565), tc_565, ok_563 };
 }
 }
return (M57){ v_561, c_562, ok_563 };
 }
if (((k_538) == (((int64_t)8LL)))) { int64_t d_566 = f116_lookup_q(((int64_t)((x_537).s_)), ns_536, ((int64_t)5LL)); 
if (((d_566) < (((int64_t)0LL)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
int64_t g_567 = ((int64_t)(((*({ hrv *_t1891 = &(g481); int64_t _i1891 = d_566; (S5*)_t1891->b + hr_ix(_i1891, _t1891->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:235"); }))).node_)); 
if ((((((uint16_t)((uint64_t)((*({ hrv *_t1892 = &(g696); int64_t _i1892 = g_567; (S4*)_t1892->b + hr_ix(_i1892, _t1892->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:236"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || ((((*({ hrv *_t1893 = &(g696); int64_t _i1893 = g_567; (S4*)_t1893->b + hr_ix(_i1893, _t1893->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:236"); }))).b_) < (((int32_t)0LL))))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
M57 _t1894 = f121_ceval3(f90_kid(((int64_t)(((*({ hrv *_t1897 = &(g696); int64_t _i1897 = g_567; (S4*)_t1897->b + hr_ix(_i1897, _t1897->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:237"); }))).b_)), ((int64_t)0LL)), f110_ns_of(g_567)); int64_t v_568 = _t1894.r0; int64_t c_569 = _t1894.r1; bool ok_570 = _t1894.r2; 
int64_t tn0_571 = ((int64_t)(((*({ hrv *_t1899 = &(g696); int64_t _i1899 = g_567; (S4*)_t1899->b + hr_ix(_i1899, _t1899->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:238"); }))).a_)); 
if ((((tn0_571) >= (((int64_t)0LL))) && ((((*({ hrv *_t1900 = &(g696); int64_t _i1900 = tn0_571; (S4*)_t1900->b + hr_ix(_i1900, _t1900->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:239"); }))).k_) == (((uint8_t)40LL))))) { int64_t tc_572 = f115_int_storage_of_tok(((int64_t)(((*({ hrv *_t1902 = &(g696); int64_t _i1902 = tn0_571; (S4*)_t1902->b + hr_ix(_i1902, _t1902->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:239"); }))).op_))); 
if (((tc_572) >= (((int64_t)0LL)))) { return (M57){ f122_cwrap(v_568, tc_572), tc_572, ok_570 };
 }
 }
return (M57){ v_568, c_569, ok_570 };
 }
if (((((k_538) == (((int64_t)14LL))) && hr_streq(f10_nm(((int64_t)((x_537).s_))), hr_str("len", 3))) && ((((*({ hrv *_t1905 = &(g696); int64_t _i1905 = (x_537).a_; (S4*)_t1905->b + hr_ix(_i1905, _t1905->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:242"); }))).k_) == (((uint8_t)8LL))))) { int64_t d_573 = f116_lookup_q(((int64_t)(((*({ hrv *_t1907 = &(g696); int64_t _i1907 = (x_537).a_; (S4*)_t1907->b + hr_ix(_i1907, _t1907->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:243"); }))).s_)), ns_536, ((int64_t)5LL)); 
if (((d_573) < (((int64_t)0LL)))) { return (M57){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
int64_t g_574 = ((int64_t)(((*({ hrv *_t1908 = &(g481); int64_t _i1908 = d_573; (S5*)_t1908->b + hr_ix(_i1908, _t1908->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:245"); }))).node_)); 
if (((((*({ hrv *_t1909 = &(g696); int64_t _i1909 = g_574; (S4*)_t1909->b + hr_ix(_i1909, _t1909->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:246"); }))).a_) >= (((int32_t)0LL)))) { int64_t t_575 = f113_rtype(((int64_t)(((*({ hrv *_t1911 = &(g696); int64_t _i1911 = g_574; (S4*)_t1911->b + hr_ix(_i1911, _t1911->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:246"); }))).a_)), f110_ns_of(g_574)); 
if ((((((*({ hrv *_t1913 = &(g543); int64_t _i1913 = t_575; (S1*)_t1913->b + hr_ix(_i1913, _t1913->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:246"); }))).k_) == (((uint8_t)8LL))) && ((((*({ hrv *_t1914 = &(g543); int64_t _i1914 = t_575; (S1*)_t1914->b + hr_ix(_i1914, _t1914->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:246"); }))).s_) == (((uint8_t)(((uint8_t)1LL))))))) { return (M57){ ((*({ hrv *_t1915 = &(g543); int64_t _i1915 = t_575; (S1*)_t1915->b + hr_ix(_i1915, _t1915->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:246"); }))).b_, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
 }
 }
if (((((*({ hrv *_t1916 = &(g696); int64_t _i1916 = g_574; (S4*)_t1916->b + hr_ix(_i1916, _t1916->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:247"); }))).b_) >= (((int32_t)0LL)))) { int64_t iv_576 = f90_kid(((int64_t)(((*({ hrv *_t1918 = &(g696); int64_t _i1918 = g_574; (S4*)_t1918->b + hr_ix(_i1918, _t1918->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:247"); }))).b_)), ((int64_t)0LL)); 
if (((((*({ hrv *_t1919 = &(g696); int64_t _i1919 = iv_576; (S4*)_t1919->b + hr_ix(_i1919, _t1919->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:247"); }))).k_) == (((uint8_t)16LL)))) { if (((((*({ hrv *_t1920 = &(g696); int64_t _i1920 = iv_576; (S4*)_t1920->b + hr_ix(_i1920, _t1920->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:247"); }))).b_) >= (((int32_t)0LL)))) { M57 _t1921 = f121_ceval3(((int64_t)(((*({ hrv *_t1923 = &(g696); int64_t _i1923 = iv_576; (S4*)_t1923->b + hr_ix(_i1923, _t1923->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:247"); }))).b_)), f110_ns_of(g_574)); int64_t v_577 = _t1921.r0; int64_t c_578 = _t1921.r1; bool ok_579 = _t1921.r2; 
return (M57){ v_577, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ok_579 };
 }
return (M57){ ((int64_t)(((*({ hrv *_t1925 = &(g696); int64_t _i1925 = iv_576; (S4*)_t1925->b + hr_ix(_i1925, _t1925->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:247"); }))).n_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
 }
if (((((*({ hrv *_t1926 = &(g696); int64_t _i1926 = iv_576; (S4*)_t1926->b + hr_ix(_i1926, _t1926->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:247"); }))).k_) == (((uint8_t)3LL)))) { return (M57){ ((int64_t)(((*({ hrv *_t1927 = &(g906); int64_t _i1927 = ((*({ hrv *_t1928 = &(g696); int64_t _i1928 = iv_576; (S4*)_t1928->b + hr_ix(_i1928, _t1928->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:247"); }))).t_; (S3*)_t1927->b + hr_ix(_i1927, _t1927->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:247"); }))).w_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
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
S1 x_603 = (*({ hrv *_t1937 = &(g543); int64_t _i1937 = t_601; (S1*)_t1937->b + hr_ix(_i1937, _t1937->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:199"); })); 
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
if (((k_604) == (((int64_t)5LL)))) { (void)(({ hrv *_v1951 = out_602; hsl _s1951 = f10_nm(((int64_t)(((*({ hrv *_t1953 = &(g546); int64_t _i1953 = (x_603).a_; (S10*)_t1953->b + hr_ix(_i1953, _t1953->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:212"); }))).name_))); hr_append(_v1951, _s1951.p, _s1951.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1955 = &(g546); int64_t _i1955 = (x_603).a_; (S10*)_t1955->b + hr_ix(_i1955, _t1955->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:212"); }))).ta_)), ((int64_t)(((*({ hrv *_t1956 = &(g546); int64_t _i1956 = (x_603).a_; (S10*)_t1956->b + hr_ix(_i1956, _t1956->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:212"); }))).tn_)), out_602));
return;
 }
if (((k_604) == (((int64_t)6LL)))) { (void)(({ hrv *_v1957 = out_602; hsl _s1957 = f10_nm(((int64_t)(((*({ hrv *_t1959 = &(g548); int64_t _i1959 = (x_603).a_; (S8*)_t1959->b + hr_ix(_i1959, _t1959->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:213"); }))).name_))); hr_append(_v1957, _s1957.p, _s1957.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1961 = &(g548); int64_t _i1961 = (x_603).a_; (S8*)_t1961->b + hr_ix(_i1961, _t1961->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:213"); }))).ta_)), ((int64_t)(((*({ hrv *_t1962 = &(g548); int64_t _i1962 = (x_603).a_; (S8*)_t1962->b + hr_ix(_i1962, _t1962->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:213"); }))).tn_)), out_602));
if (((((uint16_t)((uint64_t)(x_603).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v1963 = out_602; hsl _s1963 = hr_str("..", 2); hr_append(_v1963, _s1963.p, _s1963.n, sizeof(uint8_t)); }));
 }
return;
 }
if (((k_604) == (((int64_t)7LL)))) { (void)(({ hrv *_v1964 = out_602; hsl _s1964 = f10_nm(((int64_t)(((*({ hrv *_t1966 = &(g548); int64_t _i1966 = (x_603).a_; (S8*)_t1966->b + hr_ix(_i1966, _t1966->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:214"); }))).name_))); hr_append(_v1964, _s1964.p, _s1964.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t1968 = &(g548); int64_t _i1968 = (x_603).a_; (S8*)_t1968->b + hr_ix(_i1968, _t1968->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:214"); }))).ta_)), ((int64_t)(((*({ hrv *_t1969 = &(g548); int64_t _i1969 = (x_603).a_; (S8*)_t1969->b + hr_ix(_i1969, _t1969->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:214"); }))).tn_)), out_602));
(void)(({ hrv *_v1970 = out_602; uint8_t _x1970 = ((uint8_t)46LL); uint8_t *_p1970 = (uint8_t*)hr_grow(_v1970, 1, sizeof _x1970); *_p1970 = _x1970; _p1970; }));
(void)(({ hrv *_v1971 = out_602; hsl _s1971 = f10_nm(((int64_t)(((*({ hrv *_t1973 = &(g549); int64_t _i1973 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1974 = &(g548); int64_t _i1974 = (x_603).a_; (S8*)_t1974->b + hr_ix(_i1974, _t1974->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:214"); }))).v0_)) + (int64_t)((int64_t)((x_603).c_)))); (S9*)_t1973->b + hr_ix(_i1973, _t1973->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:214"); }))).name_))); hr_append(_v1971, _s1971.p, _s1971.n, sizeof(uint8_t)); }));
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
(void)(f127_ty_name_into(((int64_t)((*({ hrv *_t2002 = &(g544); int64_t _i2002 = ((int64_t)((int64_t)((int64_t)((x_603).l_)) + (int64_t)((int64_t)(i_613)))); (int32_t*)_t2002->b + hr_ix(_i2002, _t2002->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:232"); })))), out_602));
 } } _bk1998:; 
return;
 }
(void)(({ hrv *_v2003 = out_602; hsl _s2003 = hr_str("fn", 2); hr_append(_v2003, _s2003.p, _s2003.n, sizeof(uint8_t)); }));
}
static void f128_ls_kind_name(int64_t s_605, hrv* out_606) {
A62 names_607 = ({ A62 _t2004; _t2004.e[0] = hr_str("i8", 2); _t2004.e[1] = hr_str("i16", 3); _t2004.e[2] = hr_str("i32", 3); _t2004.e[3] = hr_str("i64", 3); _t2004.e[4] = hr_str("u8", 2); _t2004.e[5] = hr_str("u16", 3); _t2004.e[6] = hr_str("u32", 3); _t2004.e[7] = hr_str("u64", 3); _t2004; }); 
(void)(({ hrv *_v2005 = out_606; hsl _s2005 = (names_607).e[hr_ix(((int64_t)((int64_t)s_605 & (int64_t)((int64_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:197")]; hr_append(_v2005, _s2005.p, _s2005.n, sizeof(uint8_t)); }));
}
static void f129_targs_into(int64_t l_608, int64_t n_609, hrv* out_610) {
if (((n_609) == (((int64_t)0LL)))) { return;
 }
(void)(({ hrv *_v2007 = out_610; uint8_t _x2007 = ((uint8_t)60LL); uint8_t *_p2007 = (uint8_t*)hr_grow(_v2007, 1, sizeof _x2007); *_p2007 = _x2007; _p2007; }));
{ int64_t _e2009 = n_609; for (int64_t _k2009 = 0; _k2009 < _e2009; _k2009++) { int64_t i_611 = (int64_t)_k2009; if (((i_611) > (((int64_t)0LL)))) { (void)(({ hrv *_v2010 = out_610; hsl _s2010 = hr_str(", ", 2); hr_append(_v2010, _s2010.p, _s2010.n, sizeof(uint8_t)); }));
 }
(void)(f127_ty_name_into(((int64_t)((*({ hrv *_t2012 = &(g544); int64_t _i2012 = ((int64_t)((int64_t)l_608 + (int64_t)i_611)); (int32_t*)_t2012->b + hr_ix(_i2012, _t2012->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:235"); })))), out_610));
 } } _bk2008:; 
(void)(({ hrv *_v2013 = out_610; uint8_t _x2013 = ((uint8_t)62LL); uint8_t *_p2013 = (uint8_t*)hr_grow(_v2013, 1, sizeof _x2013); *_p2013 = _x2013; _p2013; }));
}
static int64_t f130_gb_find(int64_t name_615) {
int64_t i_616 = ((int64_t)((int64_t)(g483).n - (int64_t)((int64_t)1LL))); 
while (((i_616) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t2015 = &(g483); int64_t _i2015 = i_616; (S7*)_t2015->b + hr_ix(_i2015, _t2015->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:72"); }))).name_))) == (name_615))) { return ((int64_t)(((*({ hrv *_t2016 = &(g483); int64_t _i2016 = i_616; (S7*)_t2016->b + hr_ix(_i2016, _t2016->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:72"); }))).ty_));
 }
i_616--;
 } _bk2014:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f131_inst_struct(int64_t node_622, hsl args_623) {
{ hrv *_v2018 = &(g546); for (int64_t _k2018 = 0; _k2018 < _v2018->n; _k2018++) { S10 s_624 = ((S10*)_v2018->b)[_k2018]; int64_t i_625 = (int64_t)_k2018; if ((((((int64_t)((s_624).node_))) == (node_622)) && ((((int64_t)((s_624).tn_))) == ((args_623).n)))) { bool same_626 = true; 
{ int64_t _e2020 = (args_623).n; for (int64_t _k2020 = 0; _k2020 < _e2020; _k2020++) { int64_t j_627 = (int64_t)_k2020; if ((((*({ hrv *_t2021 = &(g544); int64_t _i2021 = ((int64_t)((int64_t)((int64_t)((s_624).ta_)) + (int64_t)j_627)); (int32_t*)_t2021->b + hr_ix(_i2021, _t2021->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:146"); }))) != ((*({ hsl _t2022 = args_623; int64_t _i2022 = j_627; (int32_t*)_t2022.p + hr_ix(_i2022, _t2022.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:146"); }))))) { same_626 = false;
 }
 } } _bk2019:; 
if (same_626) { return i_625;
 }
 }
 } } _bk2017:; 
int64_t ta_628 = (g544).n; 
(void)(({ hrv *_v2023 = &(g544); hsl _s2023 = args_623; hr_append(_v2023, _s2023.p, _s2023.n, sizeof(int32_t)); }));
int64_t si_629 = (g546).n; 
(void)(({ hrv *_v2024 = &(g546); S10 _x2024 = ((S10){ .node_ = ((int32_t)(node_622)), .ta_ = ((int32_t)(ta_628)), .tn_ = ((int32_t)((args_623).n)), .f0_ = ((int32_t)((g547).n)), .fnum_ = ((int32_t)0LL), .name_ = ((*({ hrv *_t2025 = &(g696); int64_t _i2025 = node_622; (S4*)_t2025->b + hr_ix(_i2025, _t2025->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:149"); }))).s_, }); S10 *_p2024 = (S10*)hr_grow(_v2024, 1, sizeof _x2024); *_p2024 = _x2024; _p2024; }));
L66 gn_630 = ({ L66 _t2026; memset(&_t2026, 0, sizeof _t2026); _t2026.n = 0; _t2026; }); 
(void)(f132_gen_names(((int64_t)(((*({ hrv *_t2028 = &(g696); int64_t _i2028 = node_622; (S4*)_t2028->b + hr_ix(_i2028, _t2028->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:150"); }))).d_)), (&(gn_630))));
if (((((int64_t)(gn_630).n)) != ((args_623).n))) { (void)(f102_derr(((int64_t)(((*({ hrv *_t2030 = &(g696); int64_t _i2030 = node_622; (S4*)_t2030->b + hr_ix(_i2030, _t2030->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:151"); }))).t_)), hr_str("wrong number of type arguments", 30)));
 }
int64_t g0_634 = (g483).n; 
{ int64_t _e2032 = f45_min(((int64_t)(gn_630).n), (args_623).n); for (int64_t _k2032 = 0; _k2032 < _e2032; _k2032++) { int64_t i_635 = (int64_t)_k2032; (void)(({ hrv *_v2034 = &(g483); S7 _x2034 = ((S7){ .name_ = (*({ L66 *_t2035 = &(gn_630); int64_t _i2035 = i_635; _t2035->e + hr_ix(_i2035, _t2035->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:153"); })), .ty_ = (*({ hsl _t2036 = args_623; int64_t _i2036 = i_635; (int32_t*)_t2036.p + hr_ix(_i2036, _t2036.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:153"); })), }); S7 *_p2034 = (S7*)hr_grow(_v2034, 1, sizeof _x2034); *_p2034 = _x2034; _p2034; }));
 } } _bk2031:; 
int64_t f0_644 = f133_fields_into(node_622, f110_ns_of(node_622)); 
{ int32_t *_t2039 = &(((*({ hrv *_t2040 = &(g546); int64_t _i2040 = si_629; (S10*)_t2040->b + hr_ix(_i2040, _t2040->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:155"); }))).f0_); *_t2039 = ((int32_t)(f0_644)); }
{ int32_t *_t2041 = &(((*({ hrv *_t2042 = &(g546); int64_t _i2042 = si_629; (S10*)_t2042->b + hr_ix(_i2042, _t2042->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:155"); }))).fnum_); *_t2041 = ((int32_t)(((int64_t)((int64_t)(g547).n - (int64_t)f0_644)))); }
(void)(({ hrv *_v2043 = &(g483); int64_t _k2043 = ((int64_t)((int64_t)(g483).n - (int64_t)g0_634)); if (_k2043 < 0 || _k2043 > _v2043->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:156"); _v2043->n -= _k2043; }));
return si_629;
}
static void f132_gen_names(int64_t gl_631, L66* out_632) {
if (((gl_631) >= (((int64_t)0LL)))) { { int32_t _e2045 = ((*({ hrv *_t2046 = &(g696); int64_t _i2046 = gl_631; (S4*)_t2046->b + hr_ix(_i2046, _t2046->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:144"); }))).n_; for (int32_t _k2045 = 0; _k2045 < _e2045; _k2045++) { int32_t i_633 = (int32_t)_k2045; (void)(({ L66 *_v2047 = out_632; int32_t _x2047 = ((*({ hrv *_t2048 = &(g696); int64_t _i2048 = f90_kid(gl_631, ((int64_t)(i_633))); (S4*)_t2048->b + hr_ix(_i2048, _t2048->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:144"); }))).s_; if (_v2047->n >= 16) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:144"); _v2047->e[_v2047->n] = _x2047; &_v2047->e[_v2047->n++]; }));
 } } _bk2044:; 
 }
}
static int64_t f133_fields_into(int64_t node_636, int64_t ns_637) {
L73 buf_638 = ({ L73 _t2050; memset(&_t2050, 0, sizeof _t2050); _t2050.n = 0; _t2050; }); 
{ int32_t _e2052 = ((*({ hrv *_t2053 = &(g696); int64_t _i2053 = node_636; (S4*)_t2053->b + hr_ix(_i2053, _t2053->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:161"); }))).n_; for (int32_t _k2052 = 0; _k2052 < _e2052; _k2052++) { int32_t i_639 = (int32_t)_k2052; int64_t f_640 = f90_kid(node_636, ((int64_t)(i_639))); 
S4 x_641 = (*({ hrv *_t2055 = &(g696); int64_t _i2055 = f_640; (S4*)_t2055->b + hr_ix(_i2055, _t2055->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:163"); })); 
if (((((uint16_t)((uint64_t)(x_641).fl_ & (uint64_t)((uint16_t)4LL)))) != (((uint16_t)0LL)))) { (void)(({ L73 *_v2056 = &(buf_638); S11 _x2056 = ((S11){ .name_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .def_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .fl_ = (x_641).fl_, .padn_ = (x_641).c_, .off_ = ((int64_t)0LL), }); if (_v2056->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:164"); _v2056->e[_v2056->n] = _x2056; &_v2056->e[_v2056->n++]; }));
continue;
 }
int64_t ft_642 = f113_rtype(((int64_t)((x_641).a_)), ns_637); 
(void)(({ L73 *_v2058 = &(buf_638); S11 _x2058 = ((S11){ .name_ = (x_641).s_, .ty_ = ((int32_t)(ft_642)), .def_ = (x_641).b_, .fl_ = (x_641).fl_, .padn_ = ((int32_t)0LL), .off_ = ((int64_t)0LL), }); if (_v2058->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:166"); _v2058->e[_v2058->n] = _x2058; &_v2058->e[_v2058->n++]; }));
 } } _bk2051:; 
int64_t f0_643 = (g547).n; 
(void)(({ hrv *_v2059 = &(g547); hsl _s2059 = ({ hsl _t2060 = ({ L73 *_t2061 = &(buf_638); (hsl){ (uint8_t*)_t2061->e, _t2061->n }; }); int64_t _l2060 = 0, _h2060 = _t2060.n; if (_l2060 < 0 || _h2060 < _l2060 || _h2060 > _t2060.n) hr_slerr(_l2060, _h2060, _t2060.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:169"); (hsl){ _t2060.p + _l2060 * (int64_t)sizeof(S11), _h2060 - _l2060 }; }); hr_append(_v2059, _s2059.p, _s2059.n, sizeof(S11)); }));
return f0_643;
}
static int64_t f134_t_struct(int64_t si_645) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)5LL))), .a_ = ((int32_t)(si_645)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f135_inst_enum(int64_t node_646, hsl args_647) {
{ hrv *_v2064 = &(g548); for (int64_t _k2064 = 0; _k2064 < _v2064->n; _k2064++) { S8 s_648 = ((S8*)_v2064->b)[_k2064]; int64_t i_649 = (int64_t)_k2064; if ((((((int64_t)((s_648).node_))) == (node_646)) && ((((int64_t)((s_648).tn_))) == ((args_647).n)))) { bool same_650 = true; 
{ int64_t _e2066 = (args_647).n; for (int64_t _k2066 = 0; _k2066 < _e2066; _k2066++) { int64_t j_651 = (int64_t)_k2066; if ((((*({ hrv *_t2067 = &(g544); int64_t _i2067 = ((int64_t)((int64_t)((int64_t)((s_648).ta_)) + (int64_t)j_651)); (int32_t*)_t2067->b + hr_ix(_i2067, _t2067->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:173"); }))) != ((*({ hsl _t2068 = args_647; int64_t _i2068 = j_651; (int32_t*)_t2068.p + hr_ix(_i2068, _t2068.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:173"); }))))) { same_650 = false;
 }
 } } _bk2065:; 
if (same_650) { return i_649;
 }
 }
 } } _bk2063:; 
int64_t ta_652 = (g544).n; 
(void)(({ hrv *_v2069 = &(g544); hsl _s2069 = args_647; hr_append(_v2069, _s2069.p, _s2069.n, sizeof(int32_t)); }));
int64_t ei_653 = (g548).n; 
int64_t nv_654 = ((int64_t)(((*({ hrv *_t2070 = &(g696); int64_t _i2070 = node_646; (S4*)_t2070->b + hr_ix(_i2070, _t2070->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:176"); }))).n_)); 
(void)(({ hrv *_v2071 = &(g548); S8 _x2071 = ((S8){ .node_ = ((int32_t)(node_646)), .ta_ = ((int32_t)(ta_652)), .tn_ = ((int32_t)((args_647).n)), .v0_ = ((int32_t)((g549).n)), .vnum_ = ((int32_t)(nv_654)), .name_ = ((*({ hrv *_t2072 = &(g696); int64_t _i2072 = node_646; (S4*)_t2072->b + hr_ix(_i2072, _t2072->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:177"); }))).s_, }); S8 *_p2071 = (S8*)hr_grow(_v2071, 1, sizeof _x2071); *_p2071 = _x2071; _p2071; }));
int64_t v0_655 = (g549).n; 
{ int64_t _e2074 = nv_654; for (int64_t _k2074 = 0; _k2074 < _e2074; _k2074++) { int64_t i_656 = (int64_t)_k2074; int64_t v_657 = f90_kid(node_646, i_656); 
(void)(({ hrv *_v2076 = &(g549); S9 _x2076 = ((S9){ .name_ = ((*({ hrv *_t2077 = &(g696); int64_t _i2077 = v_657; (S4*)_t2077->b + hr_ix(_i2077, _t2077->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:179"); }))).s_, .f0_ = ((int32_t)0LL), .fnum_ = ((int32_t)0LL), .si_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .size_ = ((int64_t)0LL), .haspay_ = ((((uint16_t)((uint64_t)((*({ hrv *_t2078 = &(g696); int64_t _i2078 = v_657; (S4*)_t2078->b + hr_ix(_i2078, _t2078->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:179"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))), }); S9 *_p2076 = (S9*)hr_grow(_v2076, 1, sizeof _x2076); *_p2076 = _x2076; _p2076; }));
 } } _bk2073:; 
L66 gn_658 = ({ L66 _t2079; memset(&_t2079, 0, sizeof _t2079); _t2079.n = 0; _t2079; }); 
(void)(f132_gen_names(((int64_t)(((*({ hrv *_t2081 = &(g696); int64_t _i2081 = node_646; (S4*)_t2081->b + hr_ix(_i2081, _t2081->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:180"); }))).d_)), (&(gn_658))));
int64_t g0_659 = (g483).n; 
{ int64_t _e2083 = f45_min(((int64_t)(gn_658).n), (args_647).n); for (int64_t _k2083 = 0; _k2083 < _e2083; _k2083++) { int64_t i_660 = (int64_t)_k2083; (void)(({ hrv *_v2085 = &(g483); S7 _x2085 = ((S7){ .name_ = (*({ L66 *_t2086 = &(gn_658); int64_t _i2086 = i_660; _t2086->e + hr_ix(_i2086, _t2086->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:182"); })), .ty_ = (*({ hsl _t2087 = args_647; int64_t _i2087 = i_660; (int32_t*)_t2087.p + hr_ix(_i2087, _t2087.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:182"); })), }); S7 *_p2085 = (S7*)hr_grow(_v2085, 1, sizeof _x2085); *_p2085 = _x2085; _p2085; }));
 } } _bk2082:; 
int64_t ns_661 = f110_ns_of(node_646); 
{ int64_t _e2090 = nv_654; for (int64_t _k2090 = 0; _k2090 < _e2090; _k2090++) { int64_t i_662 = (int64_t)_k2090; int64_t v_663 = f90_kid(node_646, i_662); 
int64_t si_664 = (g546).n; 
(void)(({ hrv *_v2092 = &(g546); S10 _x2092 = ((S10){ .node_ = ((int32_t)(v_663)), .ta_ = ((int32_t)(ta_652)), .tn_ = ((int32_t)((args_647).n)), .f0_ = ((int32_t)((g547).n)), .fnum_ = ((int32_t)0LL), .name_ = ((*({ hrv *_t2093 = &(g696); int64_t _i2093 = v_663; (S4*)_t2093->b + hr_ix(_i2093, _t2093->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:187"); }))).s_, }); S10 *_p2092 = (S10*)hr_grow(_v2092, 1, sizeof _x2092); *_p2092 = _x2092; _p2092; }));
int64_t f0_665 = f133_fields_into(v_663, ns_661); 
{ int32_t *_t2095 = &(((*({ hrv *_t2096 = &(g546); int64_t _i2096 = si_664; (S10*)_t2096->b + hr_ix(_i2096, _t2096->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:189"); }))).f0_); *_t2095 = ((int32_t)(f0_665)); }
{ int32_t *_t2097 = &(((*({ hrv *_t2098 = &(g546); int64_t _i2098 = si_664; (S10*)_t2098->b + hr_ix(_i2098, _t2098->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:189"); }))).fnum_); *_t2097 = ((int32_t)(((int64_t)((int64_t)(g547).n - (int64_t)f0_665)))); }
{ int32_t *_t2099 = &(((*({ hrv *_t2100 = &(g549); int64_t _i2100 = ((int64_t)((int64_t)v0_655 + (int64_t)i_662)); (S9*)_t2100->b + hr_ix(_i2100, _t2100->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:190"); }))).si_); *_t2099 = ((int32_t)(si_664)); }
 } } _bk2089:; 
(void)(({ hrv *_v2101 = &(g483); int64_t _k2101 = ((int64_t)((int64_t)(g483).n - (int64_t)g0_659)); if (_k2101 < 0 || _k2101 > _v2101->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:192"); _v2101->n -= _k2101; }));
return ei_653;
}
static int64_t f136_t_enum(int64_t ei_666, bool vm_667) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)6LL))), .fl_ = ({ uint16_t _r2103; if (vm_667) { _r2103 = ((uint16_t)1LL);  } else { _r2103 = ((uint16_t)0LL);  } _r2103; }), .a_ = ((int32_t)(ei_666)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f137_ck(int64_t n_671, int64_t want_672) {
if (((n_671) < (((int64_t)0LL)))) { return g550;
 }
S4 x_673 = (*({ hrv *_t2104 = &(g696); int64_t _i2104 = n_671; (S4*)_t2104->b + hr_ix(_i2104, _t2104->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:670"); })); 
int64_t k_674 = ((int64_t)((x_673).k_)); 
if (((k_674) == (((int64_t)1LL)))) { if ((((want_672) >= (((int64_t)0LL))) && ((((((*({ hrv *_t2105 = &(g543); int64_t _i2105 = want_672; (S1*)_t2105->b + hr_ix(_i2105, _t2105->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:672"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2106 = &(g543); int64_t _i2106 = want_672; (S1*)_t2106->b + hr_ix(_i2106, _t2106->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:672"); }))).k_) == (((uint8_t)4LL)))) || ((((*({ hrv *_t2107 = &(g543); int64_t _i2107 = want_672; (S1*)_t2107->b + hr_ix(_i2107, _t2107->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:672"); }))).k_) == (((uint8_t)17LL)))))) { (void)(f138_set_t(n_671, g563));
(void)(f140_conv(n_671, want_672));
return want_672;
 }
return f138_set_t(n_671, g563);
 }
if (((k_674) == (((int64_t)2LL)))) { if ((((want_672) >= (((int64_t)0LL))) && ((((*({ hrv *_t2111 = &(g543); int64_t _i2111 = want_672; (S1*)_t2111->b + hr_ix(_i2111, _t2111->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:673"); }))).k_) == (((uint8_t)4LL))))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g564);
 }
if (((k_674) == (((int64_t)3LL)))) { if ((((want_672) >= (((int64_t)0LL))) && f164_is_byte_arr(want_672))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g565);
 }
if ((((k_674) == (((int64_t)4LL))) || ((k_674) == (((int64_t)5LL))))) { return f138_set_t(n_671, g551);
 }
if (((k_674) == (((int64_t)6LL)))) { if ((((want_672) >= (((int64_t)0LL))) && f165_is_opt(want_672))) { return f138_set_t(n_671, want_672);
 }
return f138_set_t(n_671, g562);
 }
if (((k_674) == (((int64_t)7LL)))) { return f138_set_t(n_671, ({ int64_t _r2122; if (((want_672) >= (((int64_t)0LL)))) { _r2122 = want_672;  } else { _r2122 = g567;  } _r2122; }));
 }
if (((k_674) == (((int64_t)8LL)))) { return f166_ck_id(n_671, want_672);
 }
if (((k_674) == (((int64_t)9LL)))) { int64_t t_888 = f176_ck_bin(n_671, want_672); 
if (((((want_672) >= (((int64_t)0LL))) && f163_is_pending(t_888)) && (((((*({ hrv *_t2126 = &(g543); int64_t _i2126 = want_672; (S1*)_t2126->b + hr_ix(_i2126, _t2126->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:679"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2127 = &(g543); int64_t _i2127 = want_672; (S1*)_t2127->b + hr_ix(_i2127, _t2127->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:679"); }))).k_) == (((uint8_t)4LL)))))) { (void)(f140_conv(n_671, want_672));
return want_672;
 }
return t_888;
 }
if (((k_674) == (((int64_t)10LL)))) { int64_t t_915 = f183_ck_un(n_671, want_672); 
if (((((want_672) >= (((int64_t)0LL))) && f163_is_pending(t_915)) && (((((*({ hrv *_t2131 = &(g543); int64_t _i2131 = want_672; (S1*)_t2131->b + hr_ix(_i2131, _t2131->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:680"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2132 = &(g543); int64_t _i2132 = want_672; (S1*)_t2132->b + hr_ix(_i2132, _t2132->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:680"); }))).k_) == (((uint8_t)4LL)))))) { (void)(f140_conv(n_671, want_672));
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
if (((k_674) == (((int64_t)24LL)))) { (void)(({ hrv *_v2140 = &(g460); int32_t _x2140 = ({ int32_t _r2141; if ((((want_672) >= (((int64_t)0LL))) && ((want_672) != (g550)))) { _r2141 = ((int32_t)(want_672));  } else { _r2141 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));  } _r2141; }); int32_t *_p2140 = (int32_t*)hr_grow(_v2140, 1, sizeof _x2140); *_p2140 = _x2140; _p2140; }));
int64_t bt_1100 = f137_ck(((int64_t)((x_673).a_)), want_672); 
int64_t t_1101 = ((int64_t)(({ hrv *_v2143 = &(g460); if (!_v2143->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:687"); ((int32_t*)_v2143->b)[--_v2143->n]; }))); 
if ((((bt_1100) != (g550)) && (!(f163_is_pending(bt_1100))))) { return f138_set_t(n_671, bt_1100);
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
if (((k_674) == (((int64_t)30LL)))) { return f138_set_t(n_671, g550);
 }
if (((k_674) == (((int64_t)11LL)))) { return f223_ck_call(n_671, want_672);
 }
if (((k_674) == (((int64_t)17LL)))) { return f253_ck_slit(n_671, want_672);
 }
if (((k_674) == (((int64_t)31LL)))) { return f138_set_t(n_671, g570);
 }
(void)(f108_cerr(n_671, hr_str("unsupported expression", 22)));
return f138_set_t(n_671, g567);
}
static int64_t f138_set_t(int64_t n_675, int64_t t_676) {
{ int32_t *_t2162 = &((*({ hrv *_t2163 = &(g387); int64_t _i2163 = f139_aix(n_675); (int32_t*)_t2163->b + hr_ix(_i2163, _t2163->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:42"); }))); *_t2162 = ((int32_t)(t_676)); }
return t_676;
}
static int64_t f139_aix(int64_t n_677) {
int64_t i_678 = g393; 
while (((i_678) >= (((int64_t)0LL)))) { S6 f_679 = (*({ hrv *_t2166 = &(g380); int64_t _i2166 = i_678; (S6*)_t2166->b + hr_ix(_i2166, _t2166->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:37"); })); 
if ((((n_677) >= (((int64_t)((f_679).lo_)))) && ((n_677) < (((int64_t)((f_679).hi_)))))) { return ((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((f_679).ab_)) + (int64_t)n_677)) - (int64_t)((int64_t)((f_679).lo_))));
 }
i_678 = ((int64_t)((f_679).par_));
 } _bk2165:; 
S6 g_680 = (*({ hrv *_t2167 = &(g380); int64_t _i2167 = g395; (S6*)_t2167->b + hr_ix(_i2167, _t2167->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:38"); })); 
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
int64_t fk_685 = ((int64_t)(((*({ hrv *_t2169 = &(g543); int64_t _i2169 = f_684; (S1*)_t2169->b + hr_ix(_i2169, _t2169->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:148"); }))).k_)); 
int64_t tkd_686 = ((int64_t)(((*({ hrv *_t2170 = &(g543); int64_t _i2170 = t_682; (S1*)_t2170->b + hr_ix(_i2170, _t2170->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:149"); }))).k_)); 
if ((((tkd_686) == (((int64_t)0LL))) || ((fk_685) == (((int64_t)0LL))))) { return true;
 }
if (((((tkd_686) == (((int64_t)2LL))) && ((fk_685) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2171 = &(g543); int64_t _i2171 = f_684; (S1*)_t2171->b + hr_ix(_i2171, _t2171->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:151"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f142_set_cv(n_681, g551));
return true;
 }
if ((((((tkd_686) == (((int64_t)10LL))) && ((((*({ hrv *_t2173 = &(g543); int64_t _i2173 = t_682; (S1*)_t2173->b + hr_ix(_i2173, _t2173->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:152"); }))).c_) < (((int32_t)0LL)))) && ((fk_685) != (((int64_t)11LL)))) && ((fk_685) != (((int64_t)10LL))))) { if (((f143_tclass(t_682)) >= (((int64_t)0LL)))) { bool ok_735 = f140_conv(n_681, ((int64_t)(((*({ hrv *_t2176 = &(g543); int64_t _i2176 = t_682; (S1*)_t2176->b + hr_ix(_i2176, _t2176->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:152"); }))).a_))); 
if ((ok_735 && ((f150_cv(n_681)) < (((int64_t)0LL))))) { (void)(f142_set_cv(n_681, t_682));
 }
return ok_735;
 }
 }
if (((((fk_685) == (((int64_t)10LL))) && ((((*({ hrv *_t2179 = &(g543); int64_t _i2179 = f_684; (S1*)_t2179->b + hr_ix(_i2179, _t2179->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:153"); }))).c_) < (((int32_t)0LL)))) && ((tkd_686) != (((int64_t)10LL))))) { if (f151_conv_ok(((int64_t)(((*({ hrv *_t2181 = &(g543); int64_t _i2181 = f_684; (S1*)_t2181->b + hr_ix(_i2181, _t2181->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:153"); }))).a_)), t_682, n_681)) { (void)(f142_set_cv(n_681, t_682));
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
if ((((fk_685) == (((int64_t)18LL))) && (f164_is_byte_arr(t_682) || (((tkd_686) == (((int64_t)10LL))) && f164_is_byte_arr(((int64_t)(((*({ hrv *_t2196 = &(g543); int64_t _i2196 = t_682; (S1*)_t2196->b + hr_ix(_i2196, _t2196->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:160"); }))).a_))))))) { (void)(f162_commit(n_681, ({ int64_t _r2198; if (((tkd_686) == (((int64_t)10LL)))) { _r2198 = ((int64_t)(((*({ hrv *_t2199 = &(g543); int64_t _i2199 = t_682; (S1*)_t2199->b + hr_ix(_i2199, _t2199->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:160"); }))).a_));  } else { _r2198 = t_682;  } _r2198; })));
return true;
 }
if ((((fk_685) == (((int64_t)19LL))) && (((tkd_686) == (((int64_t)8LL))) || ((tkd_686) == (((int64_t)9LL)))))) { (void)(f162_commit(n_681, t_682));
return true;
 }
if (((((fk_685) == (((int64_t)11LL))) && ((tkd_686) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2201 = &(g543); int64_t _i2201 = t_682; (S1*)_t2201->b + hr_ix(_i2201, _t2201->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:162"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f162_commit(n_681, t_682));
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
return ((int64_t)((*({ hrv *_t2212 = &(g387); int64_t _i2212 = f139_aix(n_683); (int32_t*)_t2212->b + hr_ix(_i2212, _t2212->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:41"); }))));
}
static void f142_set_cv(int64_t n_687, int64_t t_688) {
{ int32_t *_t2214 = &((*({ hrv *_t2215 = &(g388); int64_t _i2215 = f139_aix(n_687); (int32_t*)_t2215->b + hr_ix(_i2215, _t2215->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:48"); }))); *_t2214 = ((int32_t)(t_688)); }
}
static int64_t f143_tclass(int64_t t_689) {
S1 x_690 = (*({ hrv *_t2217 = &(g543); int64_t _i2217 = t_689; (S1*)_t2217->b + hr_ix(_i2217, _t2217->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:83"); })); 
int64_t k_691 = ((int64_t)((x_690).k_)); 
if (((k_691) == (((int64_t)5LL)))) { (void)(f144_si_layout(((int64_t)((x_690).a_))));
return ((int64_t)(((*({ hrv *_t2219 = &(g546); int64_t _i2219 = (x_690).a_; (S10*)_t2219->b + hr_ix(_i2219, _t2219->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:85"); }))).cls_));
 }
if (((k_691) == (((int64_t)7LL)))) { (void)(f146_ei_layout(((int64_t)((x_690).a_))));
S9 v_732 = (*({ hrv *_t2221 = &(g549); int64_t _i2221 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2222 = &(g548); int64_t _i2222 = (x_690).a_; (S8*)_t2222->b + hr_ix(_i2222, _t2222->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:86"); }))).v0_)) + (int64_t)((int64_t)((x_690).c_)))); (S9*)_t2221->b + hr_ix(_i2221, _t2221->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:86"); })); 
if ((((v_732).si_) >= (((int32_t)0LL)))) { (void)(f144_si_layout(((int64_t)((v_732).si_))));
return ((int64_t)(((*({ hrv *_t2224 = &(g546); int64_t _i2224 = (v_732).si_; (S10*)_t2224->b + hr_ix(_i2224, _t2224->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:86"); }))).cls_));
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
if (((((*({ hrv *_t2228 = &(g546); int64_t _i2228 = si_692; (S10*)_t2228->b + hr_ix(_i2228, _t2228->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:127"); }))).done_) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t2229 = &(((*({ hrv *_t2230 = &(g546); int64_t _i2230 = si_692; (S10*)_t2230->b + hr_ix(_i2230, _t2230->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:128"); }))).done_); *_t2229 = ((uint8_t)1LL); }
int64_t off_693 = ((int64_t)0LL); 
int64_t cls_694 = ((int64_t)0LL); 
bool flat_695 = true; 
int64_t f0_696 = ((int64_t)(((*({ hrv *_t2231 = &(g546); int64_t _i2231 = si_692; (S10*)_t2231->b + hr_ix(_i2231, _t2231->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:130"); }))).f0_)); 
int64_t fnum_697 = ((int64_t)(((*({ hrv *_t2232 = &(g546); int64_t _i2232 = si_692; (S10*)_t2232->b + hr_ix(_i2232, _t2232->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:130"); }))).fnum_)); 
{ int64_t _e2234 = fnum_697; for (int64_t _k2234 = 0; _k2234 < _e2234; _k2234++) { int64_t i_698 = (int64_t)_k2234; int64_t fi_699 = ((int64_t)((int64_t)f0_696 + (int64_t)i_698)); 
int64_t ft_700 = ((int64_t)(((*({ hrv *_t2235 = &(g547); int64_t _i2235 = fi_699; (S11*)_t2235->b + hr_ix(_i2235, _t2235->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:133"); }))).ty_)); 
if (((ft_700) >= (((int64_t)0LL)))) { int64_t c_701 = f143_tclass(ft_700); 
if (((c_701) > (cls_694))) { cls_694 = c_701;
 }
if ((!(f145_tflat(ft_700)))) { flat_695 = false;
 }
 }
 } } _bk2233:; 
bool cur_var_715 = false; 
{ int64_t _e2239 = fnum_697; for (int64_t _k2239 = 0; _k2239 < _e2239; _k2239++) { int64_t i_716 = (int64_t)_k2239; int64_t fi_717 = ((int64_t)((int64_t)f0_696 + (int64_t)i_716)); 
int64_t ft_718 = ((int64_t)(((*({ hrv *_t2240 = &(g547); int64_t _i2240 = fi_717; (S11*)_t2240->b + hr_ix(_i2240, _t2240->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:143"); }))).ty_)); 
if (((ft_718) < (((int64_t)0LL)))) { if (((((*({ hrv *_t2241 = &(g547); int64_t _i2241 = fi_717; (S11*)_t2241->b + hr_ix(_i2241, _t2241->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:145"); }))).padn_) < (((int32_t)0LL)))) { if (((cls_694) == (((int64_t)0LL)))) { int64_t a_719 = ((int64_t)1LL); 
{ int64_t _e2243 = fnum_697; for (int64_t _k2243 = ((int64_t)((int64_t)i_716 + (int64_t)((int64_t)1LL))); _k2243 < _e2243; _k2243++) { int64_t j_720 = (int64_t)_k2243; if (((((*({ hrv *_t2244 = &(g547); int64_t _i2244 = ((int64_t)((int64_t)f0_696 + (int64_t)j_720)); (S11*)_t2244->b + hr_ix(_i2244, _t2244->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:148"); }))).ty_) >= (((int32_t)0LL)))) { a_719 = f147_pad_align(((int64_t)(((*({ hrv *_t2246 = &(g547); int64_t _i2246 = ((int64_t)((int64_t)f0_696 + (int64_t)j_720)); (S11*)_t2246->b + hr_ix(_i2246, _t2246->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:148"); }))).ty_)));
{ goto _bk2242; }
 }
 } } _bk2242:; 
int64_t next_off_725 = ((int64_t)((int64_t)HR_SDIV(int64_t, ((int64_t)((int64_t)((int64_t)((int64_t)off_693 + (int64_t)a_719)) - (int64_t)((int64_t)1LL))), a_719, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:149") * (int64_t)a_719)); 
{ int32_t *_t2247 = &(((*({ hrv *_t2248 = &(g547); int64_t _i2248 = fi_717; (S11*)_t2248->b + hr_ix(_i2248, _t2248->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:150"); }))).padn_); *_t2247 = ((int32_t)(((int64_t)((int64_t)next_off_725 - (int64_t)off_693)))); }
{ int64_t *_t2249 = &(((*({ hrv *_t2250 = &(g547); int64_t _i2250 = fi_717; (S11*)_t2250->b + hr_ix(_i2250, _t2250->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:151"); }))).off_); *_t2249 = off_693; }
off_693 = next_off_725;
 } else { { int32_t *_t2251 = &(((*({ hrv *_t2252 = &(g547); int64_t _i2252 = fi_717; (S11*)_t2252->b + hr_ix(_i2252, _t2252->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:154"); }))).padn_); *_t2251 = ((int32_t)0LL); }
{ int64_t *_t2253 = &(((*({ hrv *_t2254 = &(g547); int64_t _i2254 = fi_717; (S11*)_t2254->b + hr_ix(_i2254, _t2254->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:155"); }))).off_); *_t2253 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); }
 }
 } else { { int64_t *_t2255 = &(((*({ hrv *_t2256 = &(g547); int64_t _i2256 = fi_717; (S11*)_t2256->b + hr_ix(_i2256, _t2256->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:158"); }))).off_); *_t2255 = ({ int64_t _r2257; if ((!(cur_var_715))) { _r2257 = off_693;  } else { _r2257 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2257; }); }
if ((!(cur_var_715))) { { int64_t *_t2258 = &(off_693); *_t2258 = ((int64_t)((int64_t)(*_t2258) + (int64_t)((int64_t)(((*({ hrv *_t2259 = &(g547); int64_t _i2259 = fi_717; (S11*)_t2259->b + hr_ix(_i2259, _t2259->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:159"); }))).padn_)))); }
 }
 }
continue;
 }
int64_t c_726 = f143_tclass(ft_718); 
if (((c_726) != (((int64_t)0LL)))) { cur_var_715 = true;
 }
{ int64_t *_t2261 = &(((*({ hrv *_t2262 = &(g547); int64_t _i2262 = fi_717; (S11*)_t2262->b + hr_ix(_i2262, _t2262->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:165"); }))).off_); *_t2261 = ({ int64_t _r2263; if ((!(cur_var_715))) { _r2263 = off_693;  } else { _r2263 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2263; }); }
if ((!(cur_var_715))) { { int64_t *_t2264 = &(off_693); *_t2264 = ((int64_t)((int64_t)(*_t2264) + (int64_t)f149_tsize(ft_718))); }
 }
 } } _bk2238:; 
{ uint8_t *_t2266 = &(((*({ hrv *_t2267 = &(g546); int64_t _i2267 = si_692; (S10*)_t2267->b + hr_ix(_i2267, _t2267->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:168"); }))).cls_); *_t2266 = ((uint8_t)(cls_694)); }
{ bool *_t2268 = &(((*({ hrv *_t2269 = &(g546); int64_t _i2269 = si_692; (S10*)_t2269->b + hr_ix(_i2269, _t2269->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:168"); }))).flat_); *_t2268 = flat_695; }
{ int64_t *_t2270 = &(((*({ hrv *_t2271 = &(g546); int64_t _i2271 = si_692; (S10*)_t2271->b + hr_ix(_i2271, _t2271->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:169"); }))).size_); *_t2270 = ({ int64_t _r2272; if (((cls_694) == (((int64_t)0LL)))) { _r2272 = f103_max(off_693, ((int64_t)1LL));  } else { _r2272 = off_693;  } _r2272; }); }
{ bool *_t2274 = &(((*({ hrv *_t2275 = &(g546); int64_t _i2275 = si_692; (S10*)_t2275->b + hr_ix(_i2275, _t2275->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:170"); }))).zero_); *_t2274 = (((cls_694) == (((int64_t)0LL))) && ((off_693) == (((int64_t)0LL)))); }
{ uint8_t *_t2276 = &(((*({ hrv *_t2277 = &(g546); int64_t _i2277 = si_692; (S10*)_t2277->b + hr_ix(_i2277, _t2277->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:171"); }))).done_); *_t2276 = ((uint8_t)2LL); }
}
static bool f145_tflat(int64_t t_702) {
S1 x_703 = (*({ hrv *_t2278 = &(g543); int64_t _i2278 = t_702; (S1*)_t2278->b + hr_ix(_i2278, _t2278->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:118"); })); 
int64_t k_704 = ((int64_t)((x_703).k_)); 
if ((((k_704) == (((int64_t)10LL))) || ((k_704) == (((int64_t)9LL))))) { return false;
 }
if (((k_704) == (((int64_t)5LL)))) { (void)(f144_si_layout(((int64_t)((x_703).a_))));
return ((*({ hrv *_t2280 = &(g546); int64_t _i2280 = (x_703).a_; (S10*)_t2280->b + hr_ix(_i2280, _t2280->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:120"); }))).flat_;
 }
if ((((k_704) == (((int64_t)6LL))) || ((k_704) == (((int64_t)7LL))))) { (void)(f146_ei_layout(((int64_t)((x_703).a_))));
return ((*({ hrv *_t2282 = &(g548); int64_t _i2282 = (x_703).a_; (S8*)_t2282->b + hr_ix(_i2282, _t2282->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:121"); }))).flat_;
 }
if (((k_704) == (((int64_t)8LL)))) { return f145_tflat(((int64_t)((x_703).a_)));
 }
return true;
}
static void f146_ei_layout(int64_t ei_705) {
if (((((*({ hrv *_t2284 = &(g548); int64_t _i2284 = ei_705; (S8*)_t2284->b + hr_ix(_i2284, _t2284->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:174"); }))).done_) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t2285 = &(((*({ hrv *_t2286 = &(g548); int64_t _i2286 = ei_705; (S8*)_t2286->b + hr_ix(_i2286, _t2286->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:175"); }))).done_); *_t2285 = ((uint8_t)1LL); }
int64_t nv_706 = ((int64_t)(((*({ hrv *_t2287 = &(g548); int64_t _i2287 = ei_705; (S8*)_t2287->b + hr_ix(_i2287, _t2287->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:176"); }))).vnum_)); 
int64_t tz_707 = ({ int64_t _r2288; if (((nv_706) <= (((int64_t)256LL)))) { _r2288 = ((int64_t)1LL);  } else { _r2288 = ((int64_t)2LL);  } _r2288; }); 
{ uint8_t *_t2289 = &(((*({ hrv *_t2290 = &(g548); int64_t _i2290 = ei_705; (S8*)_t2290->b + hr_ix(_i2290, _t2290->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:178"); }))).tagsz_); *_t2289 = ((uint8_t)(tz_707)); }
int64_t mx_708 = ((int64_t)0LL); 
int64_t cls_709 = ((int64_t)0LL); 
bool flat_710 = true; 
{ int64_t _e2292 = nv_706; for (int64_t _k2292 = 0; _k2292 < _e2292; _k2292++) { int64_t i_711 = (int64_t)_k2292; int64_t v_712 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2293 = &(g548); int64_t _i2293 = ei_705; (S8*)_t2293->b + hr_ix(_i2293, _t2293->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:181"); }))).v0_)) + (int64_t)i_711)); 
if (((((*({ hrv *_t2294 = &(g549); int64_t _i2294 = v_712; (S9*)_t2294->b + hr_ix(_i2294, _t2294->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:182"); }))).si_) >= (((int32_t)0LL)))) { int64_t si_713 = ((int64_t)(((*({ hrv *_t2295 = &(g549); int64_t _i2295 = v_712; (S9*)_t2295->b + hr_ix(_i2295, _t2295->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:183"); }))).si_)); 
(void)(f144_si_layout(si_713));
if (((((int64_t)(((*({ hrv *_t2297 = &(g546); int64_t _i2297 = si_713; (S10*)_t2297->b + hr_ix(_i2297, _t2297->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:185"); }))).cls_))) > (cls_709))) { cls_709 = ((int64_t)(((*({ hrv *_t2298 = &(g546); int64_t _i2298 = si_713; (S10*)_t2298->b + hr_ix(_i2298, _t2298->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:185"); }))).cls_));
 }
if ((!(((*({ hrv *_t2299 = &(g546); int64_t _i2299 = si_713; (S10*)_t2299->b + hr_ix(_i2299, _t2299->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:186"); }))).flat_))) { flat_710 = false;
 }
int64_t ps_714 = ({ int64_t _r2300; if (((*({ hrv *_t2301 = &(g546); int64_t _i2301 = si_713; (S10*)_t2301->b + hr_ix(_i2301, _t2301->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:187"); }))).zero_) { _r2300 = ((int64_t)0LL);  } else { _r2300 = ((*({ hrv *_t2302 = &(g546); int64_t _i2302 = si_713; (S10*)_t2302->b + hr_ix(_i2302, _t2302->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:187"); }))).size_;  } _r2300; }); 
{ int64_t *_t2303 = &(((*({ hrv *_t2304 = &(g549); int64_t _i2304 = v_712; (S9*)_t2304->b + hr_ix(_i2304, _t2304->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:188"); }))).size_); *_t2303 = ps_714; }
if (((ps_714) > (mx_708))) { mx_708 = ps_714;
 }
 }
 } } _bk2291:; 
{ uint8_t *_t2305 = &(((*({ hrv *_t2306 = &(g548); int64_t _i2306 = ei_705; (S8*)_t2306->b + hr_ix(_i2306, _t2306->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:192"); }))).cls_); *_t2305 = ((uint8_t)(cls_709)); }
{ bool *_t2307 = &(((*({ hrv *_t2308 = &(g548); int64_t _i2308 = ei_705; (S8*)_t2308->b + hr_ix(_i2308, _t2308->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:192"); }))).flat_); *_t2307 = flat_710; }
{ int64_t *_t2309 = &(((*({ hrv *_t2310 = &(g548); int64_t _i2310 = ei_705; (S8*)_t2310->b + hr_ix(_i2310, _t2310->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:193"); }))).size_); *_t2309 = ((int64_t)((int64_t)((int64_t)(tz_707)) + (int64_t)mx_708)); }
{ uint8_t *_t2311 = &(((*({ hrv *_t2312 = &(g548); int64_t _i2312 = ei_705; (S8*)_t2312->b + hr_ix(_i2312, _t2312->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:194"); }))).done_); *_t2311 = ((uint8_t)2LL); }
}
static int64_t f147_pad_align(int64_t t_721) {
S1 x_722 = (*({ hrv *_t2313 = &(g543); int64_t _i2313 = t_721; (S1*)_t2313->b + hr_ix(_i2313, _t2313->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:96"); })); 
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
S1 x_728 = (*({ hrv *_t2317 = &(g543); int64_t _i2317 = t_727; (S1*)_t2317->b + hr_ix(_i2317, _t2317->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:104"); })); 
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
return ((*({ hrv *_t2321 = &(g546); int64_t _i2321 = (x_728).a_; (S10*)_t2321->b + hr_ix(_i2321, _t2321->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:111"); }))).size_;
 }
if (((k_729) == (((int64_t)7LL)))) { (void)(f146_ei_layout(((int64_t)((x_728).a_))));
S9 v_730 = (*({ hrv *_t2323 = &(g549); int64_t _i2323 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2324 = &(g548); int64_t _i2324 = (x_728).a_; (S8*)_t2324->b + hr_ix(_i2324, _t2324->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:112"); }))).v0_)) + (int64_t)((int64_t)((x_728).c_)))); (S9*)_t2323->b + hr_ix(_i2323, _t2323->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:112"); })); 
return (v_730).size_;
 }
if (((k_729) == (((int64_t)6LL)))) { (void)(f146_ei_layout(((int64_t)((x_728).a_))));
return ((*({ hrv *_t2326 = &(g548); int64_t _i2326 = (x_728).a_; (S8*)_t2326->b + hr_ix(_i2326, _t2326->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:113"); }))).size_;
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
return ((int64_t)((*({ hrv *_t2332 = &(g388); int64_t _i2332 = f139_aix(n_736); (int32_t*)_t2332->b + hr_ix(_i2332, _t2332->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:49"); }))));
}
static bool f151_conv_ok(int64_t f_737, int64_t t_738, int64_t n_739) {
if (((f_737) == (t_738))) { return true;
 }
S1 a_740 = (*({ hrv *_t2334 = &(g543); int64_t _i2334 = f_737; (S1*)_t2334->b + hr_ix(_i2334, _t2334->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:169"); })); 
S1 b_741 = (*({ hrv *_t2335 = &(g543); int64_t _i2335 = t_738; (S1*)_t2335->b + hr_ix(_i2335, _t2335->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:169"); })); 
if (f152_widens(f_737, t_738)) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)2LL))) && (((a_740).k_) == (((uint8_t)10LL)))) && ((((uint16_t)((uint64_t)(a_740).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)9LL))) && ((((a_740).k_) == (((uint8_t)8LL))) || (((a_740).k_) == (((uint8_t)9LL))))) && (((a_740).a_) == ((b_741).a_)))) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)9LL))) && (((a_740).k_) == (((uint8_t)18LL)))) && ((((int64_t)((b_741).a_))) == (g556)))) { return true;
 }
if ((((((b_741).k_) == (((uint8_t)10LL))) && (((a_740).k_) == (((uint8_t)10LL)))) && (((((uint16_t)((uint64_t)(b_741).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))) || ((((uint16_t)((uint64_t)(a_740).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))))) { if ((((a_740).a_) == ((b_741).a_))) { return true;
 }
if (((((((*({ hrv *_t2337 = &(g543); int64_t _i2337 = (b_741).a_; (S1*)_t2337->b + hr_ix(_i2337, _t2337->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:176"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t2338 = &(g543); int64_t _i2338 = (a_740).a_; (S1*)_t2338->b + hr_ix(_i2338, _t2338->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:176"); }))).k_) == (((uint8_t)7LL)))) && ((((*({ hrv *_t2339 = &(g543); int64_t _i2339 = (a_740).a_; (S1*)_t2339->b + hr_ix(_i2339, _t2339->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:176"); }))).a_) == (((*({ hrv *_t2340 = &(g543); int64_t _i2340 = (b_741).a_; (S1*)_t2340->b + hr_ix(_i2340, _t2340->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:176"); }))).a_)))) { return true;
 }
if (((((((*({ hrv *_t2341 = &(g543); int64_t _i2341 = (b_741).a_; (S1*)_t2341->b + hr_ix(_i2341, _t2341->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:177"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t2342 = &(g543); int64_t _i2342 = (a_740).a_; (S1*)_t2342->b + hr_ix(_i2342, _t2342->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:177"); }))).k_) == (((uint8_t)6LL)))) && ((((*({ hrv *_t2343 = &(g543); int64_t _i2343 = (a_740).a_; (S1*)_t2343->b + hr_ix(_i2343, _t2343->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:177"); }))).a_) == (((*({ hrv *_t2344 = &(g543); int64_t _i2344 = (b_741).a_; (S1*)_t2344->b + hr_ix(_i2344, _t2344->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:177"); }))).a_)))) { return true;
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
S1 a_744 = (*({ hrv *_t2345 = &(g543); int64_t _i2345 = f_742; (S1*)_t2345->b + hr_ix(_i2345, _t2345->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:115"); })); 
S1 b_745 = (*({ hrv *_t2346 = &(g543); int64_t _i2346 = t_743; (S1*)_t2346->b + hr_ix(_i2346, _t2346->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:115"); })); 
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
if (((((a_744).k_) == (((uint8_t)17LL))) && (((b_745).k_) == (((uint8_t)3LL))))) { return ((t_743) == (g555));
 }
return false;
}
static bool f153_is_signed(int64_t t_746) {
return ((((*({ hrv *_t2355 = &(g543); int64_t _i2355 = t_746; (S1*)_t2355->b + hr_ix(_i2355, _t2355->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:60"); }))).s_) < (((uint8_t)4LL)));
}
static int64_t f154_ibits(int64_t t_749) {
return ((int64_t)((((int64_t)8LL)) << ((((int64_t)(((uint8_t)((uint64_t)((*({ hrv *_t2356 = &(g543); int64_t _i2356 = t_749; (S1*)_t2356->b + hr_ix(_i2356, _t2356->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:61"); }))).s_ & (uint64_t)((uint8_t)3LL)))))) & 63)));
}
static M78 f155_cval(int64_t n_750) {
S4 x_751 = (*({ hrv *_t2357 = &(g696); int64_t _i2357 = n_750; (S4*)_t2357->b + hr_ix(_i2357, _t2357->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:124"); })); 
int64_t k_752 = ((int64_t)((x_751).k_)); 
if (((k_752) == (((int64_t)1LL)))) { return (M78){ ((*({ hrv *_t2358 = &(g906); int64_t _i2358 = (x_751).t_; (S3*)_t2358->b + hr_ix(_i2358, _t2358->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:125"); }))).v_, ((*({ hrv *_t2359 = &(g906); int64_t _i2359 = (x_751).t_; (S3*)_t2359->b + hr_ix(_i2359, _t2359->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:125"); }))).uns_, true };
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
if ((((k_752) == (((int64_t)8LL))) && ((f156_rk(n_750)) == (((int64_t)6LL))))) { return (M78){ (*({ hrv *_t2363 = &(g428); int64_t _i2363 = f157_rv(n_750); (int64_t*)_t2363->b + hr_ix(_i2363, _t2363->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:127"); })), false, true };
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
return (M78){ HR_SDIV(int64_t, a_758, b_761, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:133"), false, true };
 }
if (((o_764) == (((int64_t)25LL)))) { if (((b_761) == (((int64_t)0LL)))) { return (M78){ ((int64_t)0LL), false, false };
 }
return (M78){ HR_SMOD(int64_t, ((int64_t)((int64_t)HR_SMOD(int64_t, a_758, b_761, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:134") + (int64_t)b_761)), b_761, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:134"), false, true };
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
return ((int64_t)((*({ hrv *_t2369 = &(g389); int64_t _i2369 = f139_aix(n_756); (uint8_t*)_t2369->b + hr_ix(_i2369, _t2369->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:44"); }))));
}
static int64_t f157_rv(int64_t n_757) {
return ((int64_t)((*({ hrv *_t2371 = &(g390); int64_t _i2371 = f139_aix(n_757); (int32_t*)_t2371->b + hr_ix(_i2371, _t2371->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:45"); }))));
}
static bool f158_int_fits(int64_t v_768, bool uns_769, int64_t t_770) {
if (((((*({ hrv *_t2373 = &(g543); int64_t _i2373 = t_770; (S1*)_t2373->b + hr_ix(_i2373, _t2373->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:108"); }))).k_) != (((uint8_t)3LL)))) { return false;
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
S4 x_780 = (*({ hrv *_t2388 = &(g696); int64_t _i2388 = n_778; (S4*)_t2388->b + hr_ix(_i2388, _t2388->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:189"); })); 
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
if (((k_781) == (((int64_t)20LL)))) { { int32_t _e2404 = (x_780).n_; for (int32_t _k2404 = 0; _k2404 < _e2404; _k2404++) { int32_t i_786 = (int32_t)_k2404; (void)(f162_commit(((int64_t)(((*({ hrv *_t2406 = &(g696); int64_t _i2406 = f90_kid(n_778, ((int64_t)(i_786))); (S4*)_t2406->b + hr_ix(_i2406, _t2406->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:203"); }))).b_)), t_779));
 } } _bk2403:; 
return;
 }
if (((k_781) == (((int64_t)16LL)))) { int64_t e_787 = ({ int64_t _r2408; if ((((((*({ hrv *_t2409 = &(g543); int64_t _i2409 = t_779; (S1*)_t2409->b + hr_ix(_i2409, _t2409->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:205"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2410 = &(g543); int64_t _i2410 = t_779; (S1*)_t2410->b + hr_ix(_i2410, _t2410->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:205"); }))).k_) == (((uint8_t)9LL))))) { _r2408 = ((int64_t)(((*({ hrv *_t2411 = &(g543); int64_t _i2411 = t_779; (S1*)_t2411->b + hr_ix(_i2411, _t2411->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:205"); }))).a_));  } else { _r2408 = g567;  } _r2408; }); 
if ((((x_780).a_) >= (((int32_t)0LL)))) { (void)(f140_conv(((int64_t)((x_780).a_)), e_787));
(void)(f140_conv(((int64_t)((x_780).b_)), g555));
 }
{ int32_t _e2415 = (x_780).n_; for (int32_t _k2415 = 0; _k2415 < _e2415; _k2415++) { int32_t i_788 = (int32_t)_k2415; (void)(f140_conv(f90_kid(n_778, ((int64_t)(i_788))), e_787));
 } } _bk2414:; 
if (((((*({ hrv *_t2418 = &(g543); int64_t _i2418 = t_779; (S1*)_t2418->b + hr_ix(_i2418, _t2418->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:208"); }))).k_) == (((uint8_t)9LL)))) { (void)(f138_set_t(n_778, f123_t_arr(e_787, ((int64_t)1LL), f103_max(((int64_t)((x_780).n_)), ((int64_t)1LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f142_set_cv(n_778, t_779));
 }
return;
 }
}
static bool f163_is_pending(int64_t t_783) {
int64_t k_784 = ((int64_t)(((*({ hrv *_t2423 = &(g543); int64_t _i2423 = t_783; (S1*)_t2423->b + hr_ix(_i2423, _t2423->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:106"); }))).k_)); 
return ((((((k_784) == (((int64_t)12LL))) || ((k_784) == (((int64_t)13LL)))) || ((k_784) == (((int64_t)18LL)))) || ((k_784) == (((int64_t)19LL)))) || ((k_784) == (((int64_t)11LL))));
}
static bool f164_is_byte_arr(int64_t t_789) {
uint8_t k_790 = ((*({ hrv *_t2424 = &(g543); int64_t _i2424 = t_789; (S1*)_t2424->b + hr_ix(_i2424, _t2424->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:68"); }))).k_; 
return ((((k_790) == (((uint8_t)8LL))) || ((k_790) == (((uint8_t)9LL)))) && ((((int64_t)(((*({ hrv *_t2425 = &(g543); int64_t _i2425 = t_789; (S1*)_t2425->b + hr_ix(_i2425, _t2425->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:68"); }))).a_))) == (g556)));
}
static bool f165_is_opt(int64_t t_792) {
return (((((*({ hrv *_t2426 = &(g543); int64_t _i2426 = t_792; (S1*)_t2426->b + hr_ix(_i2426, _t2426->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:66"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2427 = &(g543); int64_t _i2427 = t_792; (S1*)_t2427->b + hr_ix(_i2427, _t2427->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:66"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))));
}
static int64_t f166_ck_id(int64_t n_793, int64_t want_794) {
int64_t name_795 = ((int64_t)(((*({ hrv *_t2428 = &(g696); int64_t _i2428 = n_793; (S4*)_t2428->b + hr_ix(_i2428, _t2428->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:338"); }))).s_)); 
int64_t v_803 = f167_find_lv(name_795); 
if (((v_803) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_793, ((int64_t)1LL), v_803));
(void)(f171_note_cap(v_803));
return f138_set_t(n_793, ((int64_t)(((*({ hrv *_t2433 = &(g381); int64_t _i2433 = v_803; (S12*)_t2433->b + hr_ix(_i2433, _t2433->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:340"); }))).ty_)));
 }
int64_t ns_814 = f110_ns_of(n_793); 
int64_t d_815 = f116_lookup_q(name_795, ns_814, ((int64_t)5LL)); 
if (((d_815) >= (((int64_t)0LL)))) { int64_t g_816 = ((int64_t)(((*({ hrv *_t2436 = &(g481); int64_t _i2436 = d_815; (S5*)_t2436->b + hr_ix(_i2436, _t2436->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:344"); }))).node_)); 
int64_t ci_829 = f173_const_of(d_815); 
if (((ci_829) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_793, ((int64_t)6LL), ci_829));
return f138_set_t(n_793, g563);
 }
(void)(f170_set_r(n_793, ((int64_t)2LL), d_815));
return f138_set_t(n_793, f109_global_type(d_815));
 }
d_815 = f116_lookup_q(name_795, ns_814, ((int64_t)4LL));
if (((d_815) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_793, ((int64_t)3LL), d_815));
(void)(f175_set_x(n_793, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_793, g570);
 }
hrv m_832 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o2448 = &(m_832); hr_fs(_o2448, hr_str("unknown name: ", 14)); hr_fs(_o2448, f10_nm(name_795)); }));
(void)(f108_cerr(n_793, hr_sl(m_832)));
return f138_set_t(n_793, g567);
}
static int64_t f167_find_lv(int64_t name_796) {
int64_t i_797 = ((int64_t)((int64_t)(g382).n - (int64_t)((int64_t)1LL))); 
while (((i_797) >= (((int64_t)0LL)))) { int64_t v_798 = ((int64_t)((*({ hrv *_t2453 = &(g382); int64_t _i2453 = i_797; (int32_t*)_t2453->b + hr_ix(_i2453, _t2453->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:60"); })))); 
if ((((((int64_t)(((*({ hrv *_t2454 = &(g381); int64_t _i2454 = v_798; (S12*)_t2454->b + hr_ix(_i2454, _t2454->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:60"); }))).name_))) == (name_796)) && f168_visible(((int64_t)(((*({ hrv *_t2456 = &(g381); int64_t _i2456 = v_798; (S12*)_t2456->b + hr_ix(_i2456, _t2456->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:60"); }))).own_))))) { return v_798;
 }
i_797--;
 } _bk2452:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f168_visible(int64_t own_799) {
return f169_visible_in(own_799, g393);
}
static bool f169_visible_in(int64_t own_800, int64_t cur_801) {
int64_t i_802 = cur_801; 
while (((i_802) >= (((int64_t)0LL)))) { if (((i_802) == (own_800))) { return true;
 }
i_802 = ((int64_t)(((*({ hrv *_t2459 = &(g380); int64_t _i2459 = i_802; (S6*)_t2459->b + hr_ix(_i2459, _t2459->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:56"); }))).par_));
 } _bk2458:; 
return false;
}
static void f170_set_r(int64_t n_804, int64_t k_805, int64_t v_806) {
int64_t i_807 = f139_aix(n_804); 
{ uint8_t *_t2461 = &((*({ hrv *_t2462 = &(g389); int64_t _i2462 = i_807; (uint8_t*)_t2462->b + hr_ix(_i2462, _t2462->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:43"); }))); *_t2461 = ((uint8_t)(k_805)); }
{ int32_t *_t2463 = &((*({ hrv *_t2464 = &(g390); int64_t _i2464 = i_807; (int32_t*)_t2464->b + hr_ix(_i2464, _t2464->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:43"); }))); *_t2463 = ((int32_t)(v_806)); }
}
static void f171_note_cap(int64_t v_808) {
int64_t own_809 = ((int64_t)(((*({ hrv *_t2465 = &(g381); int64_t _i2465 = v_808; (S12*)_t2465->b + hr_ix(_i2465, _t2465->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:70"); }))).own_)); 
int64_t a_810 = g393; 
while ((((a_810) >= (((int64_t)0LL))) && ((a_810) != (own_809)))) { (void)(f172_add_cap_one(((int64_t)(((*({ hrv *_t2468 = &(g380); int64_t _i2468 = a_810; (S6*)_t2468->b + hr_ix(_i2468, _t2468->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:73"); }))).cfn_)), v_808));
a_810 = ((int64_t)(((*({ hrv *_t2469 = &(g380); int64_t _i2469 = a_810; (S6*)_t2469->b + hr_ix(_i2469, _t2469->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:74"); }))).par_));
 } _bk2466:; 
}
static bool f172_add_cap_one(int64_t cf_811, int64_t v_812) {
if ((((cf_811) < (((int64_t)0LL))) || ((cf_811) == (((int64_t)(((*({ hrv *_t2470 = &(g381); int64_t _i2470 = v_812; (S12*)_t2470->b + hr_ix(_i2470, _t2470->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:64"); }))).cfn_)))))) { return false;
 }
{ hrv *_v2472 = &(g384); for (int64_t _k2472 = 0; _k2472 < _v2472->n; _k2472++) { S13 x_813 = ((S13*)_v2472->b)[_k2472]; if ((((((int64_t)((x_813).inst_))) == (cf_811)) && ((((int64_t)((x_813).lv_))) == (v_812)))) { return false;
 }
 } } _bk2471:; 
(void)(({ hrv *_v2473 = &(g384); S13 _x2473 = ((S13){ .inst_ = ((int32_t)(cf_811)), .lv_ = ((int32_t)(v_812)), }); S13 *_p2473 = (S13*)hr_grow(_v2473, 1, sizeof _x2473); *_p2473 = _x2473; _p2473; }));
return true;
}
static int64_t f173_const_of(int64_t d_817) {
{ hrv *_v2475 = &(g429); for (int64_t _k2475 = 0; _k2475 < _v2475->n; _k2475++) { int32_t c_818 = ((int32_t*)_v2475->b)[_k2475]; int64_t i_819 = (int64_t)_k2475; if (((((int64_t)(c_818))) == (d_817))) { return i_819;
 }
 } } _bk2474:; 
int64_t g_820 = ((int64_t)(((*({ hrv *_t2476 = &(g481); int64_t _i2476 = d_817; (S5*)_t2476->b + hr_ix(_i2476, _t2476->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:359"); }))).node_)); 
S4 x_821 = (*({ hrv *_t2477 = &(g696); int64_t _i2477 = g_820; (S4*)_t2477->b + hr_ix(_i2477, _t2477->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:360"); })); 
if (((((((uint16_t)((uint64_t)(x_821).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || (((x_821).a_) >= (((int32_t)0LL)))) || (((x_821).b_) < (((int32_t)0LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t iv_822 = f90_kid(((int64_t)((x_821).b_)), ((int64_t)0LL)); 
M56 _t2479 = f120_ceval(iv_822, f110_ns_of(g_820)); int64_t v_823 = _t2479.r0; bool ok_824 = _t2479.r1; 
if ((!(ok_824))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if ((!(f174_all_int(iv_822)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
(void)(({ hrv *_v2483 = &(g429); int32_t _x2483 = ((int32_t)(d_817)); int32_t *_p2483 = (int32_t*)hr_grow(_v2483, 1, sizeof _x2483); *_p2483 = _x2483; _p2483; }));
(void)(({ hrv *_v2484 = &(g428); int64_t _x2484 = v_823; int64_t *_p2484 = (int64_t*)hr_grow(_v2484, 1, sizeof _x2484); *_p2484 = _x2484; _p2484; }));
return ((int64_t)((int64_t)(g429).n - (int64_t)((int64_t)1LL)));
}
static bool f174_all_int(int64_t n_825) {
S4 x_826 = (*({ hrv *_t2485 = &(g696); int64_t _i2485 = n_825; (S4*)_t2485->b + hr_ix(_i2485, _t2485->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:370"); })); 
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
{ int32_t *_t2493 = &((*({ hrv *_t2494 = &(g391); int64_t _i2494 = f139_aix(n_830); (int32_t*)_t2494->b + hr_ix(_i2494, _t2494->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:46"); }))); *_t2493 = ((int32_t)(v_831)); }
}
static int64_t f176_ck_bin(int64_t n_833, int64_t want_834) {
S4 x_835 = (*({ hrv *_t2496 = &(g696); int64_t _i2496 = n_833; (S4*)_t2496->b + hr_ix(_i2496, _t2496->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:275"); })); 
int64_t o_836 = ((int64_t)((x_835).op_)); 
int64_t a_837 = ((int64_t)((x_835).a_)); 
int64_t b_838 = ((int64_t)((x_835).b_)); 
if (((o_836) == (((int64_t)52LL)))) { (void)(f137_ck(a_837, g551));
(void)(f140_conv(a_837, g551));
int64_t nm0_839 = (g383).n; 
(void)(f177_narrow_push(a_837));
(void)(f137_ck(b_838, g551));
(void)(f140_conv(b_838, g551));
(void)(f178_narrow_pop(nm0_839));
return f138_set_t(n_833, g551);
 }
if (((o_836) == (((int64_t)53LL)))) { (void)(f137_ck(a_837, g551));
(void)(f140_conv(a_837, g551));
(void)(f137_ck(b_838, g551));
(void)(f140_conv(b_838, g551));
return f138_set_t(n_833, g551);
 }
if ((((o_836) == (((int64_t)19LL))) || ((o_836) == (((int64_t)20LL))))) { (void)(f137_ck(a_837, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
(void)(f137_ck(b_838, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_833, g551);
 }
bool cmp_848 = (((((((o_836) == (((int64_t)37LL))) || ((o_836) == (((int64_t)38LL)))) || ((o_836) == (((int64_t)39LL)))) || ((o_836) == (((int64_t)40LL)))) || ((o_836) == (((int64_t)41LL)))) || ((o_836) == (((int64_t)42LL)))); 
int64_t w_849 = ({ int64_t _r2512; if (cmp_848) { _r2512 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2512 = want_834;  } _r2512; }); 
int64_t ta_850 = f137_ck(a_837, w_849); 
int64_t tb_852 = f137_ck(b_838, ({ int64_t _r2515; if (f163_is_pending(ta_850)) { _r2515 = w_849;  } else { _r2515 = f179_deref(ta_850);  } _r2515; })); 
if ((((o_836) == (((int64_t)43LL))) || ((o_836) == (((int64_t)44LL))))) { if (((((*({ hrv *_t2518 = &(g543); int64_t _i2518 = tb_852; (S1*)_t2518->b + hr_ix(_i2518, _t2518->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:291"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(b_838, g555));
 } else { if (((((*({ hrv *_t2520 = &(g543); int64_t _i2520 = f179_deref(tb_852); (S1*)_t2520->b + hr_ix(_i2520, _t2520->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:291"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(b_838, hr_str("shift count must be an integer", 30)));
 }
 }
int64_t da_853 = f179_deref(ta_850); 
if (((((*({ hrv *_t2524 = &(g543); int64_t _i2524 = da_853; (S1*)_t2524->b + hr_ix(_i2524, _t2524->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:293"); }))).k_) == (((uint8_t)12LL)))) { if ((((want_834) >= (((int64_t)0LL))) && ((((*({ hrv *_t2525 = &(g543); int64_t _i2525 = want_834; (S1*)_t2525->b + hr_ix(_i2525, _t2525->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:293"); }))).k_) == (((uint8_t)3LL))))) { (void)(f140_conv(a_837, want_834));
return f138_set_t(n_833, want_834);
 }
return f138_set_t(n_833, g563);
 }
if (((((*({ hrv *_t2529 = &(g543); int64_t _i2529 = da_853; (S1*)_t2529->b + hr_ix(_i2529, _t2529->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:294"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(a_837, hr_str("shift of a non-integer", 22)));
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
if ((((((cmp_848 && (((((*({ hrv *_t2552 = &(g543); int64_t _i2552 = da_854; (S1*)_t2552->b + hr_ix(_i2552, _t2552->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:306"); }))).k_) == (((uint8_t)3LL))) && ((((*({ hrv *_t2553 = &(g543); int64_t _i2553 = db_855; (S1*)_t2553->b + hr_ix(_i2553, _t2553->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:306"); }))).k_) == (((uint8_t)3LL))))) && ((f153_is_signed(da_854)) != (f153_is_signed(db_855)))) && (((f154_ibits(da_854)) == (((int64_t)64LL))) || ((f154_ibits(db_855)) == (((int64_t)64LL))))) && (!(f152_widens(da_854, db_855)))) && (!(f152_widens(db_855, da_854))))) { (void)(f175_set_x(n_833, ((int64_t)1LL)));
return f138_set_t(n_833, g551);
 }
if ((cmp_848 && (((o_836) == (((int64_t)37LL))) || ((o_836) == (((int64_t)38LL)))))) { int64_t ka_873 = ((int64_t)(((*({ hrv *_t2562 = &(g543); int64_t _i2562 = da_854; (S1*)_t2562->b + hr_ix(_i2562, _t2562->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:311"); }))).k_)); 
int64_t kb_874 = ((int64_t)(((*({ hrv *_t2563 = &(g543); int64_t _i2563 = db_855; (S1*)_t2563->b + hr_ix(_i2563, _t2563->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:311"); }))).k_)); 
if ((((ka_873) == (((int64_t)11LL))) || ((kb_874) == (((int64_t)11LL))))) { if ((((ka_873) == (((int64_t)11LL))) && ((kb_874) == (((int64_t)11LL))))) { return f138_set_t(n_833, g551);
 }
if (((ka_873) == (((int64_t)11LL)))) { (void)(f138_set_t(a_837, tb_852));
 } else { (void)(f138_set_t(b_838, ta_850));
 }
return f138_set_t(n_833, g551);
 }
if (((((ka_873) == (((int64_t)18LL))) || ((kb_874) == (((int64_t)18LL)))) || (f164_is_byte_arr(da_854) && f164_is_byte_arr(db_855)))) { if (((ka_873) == (((int64_t)18LL)))) { (void)(f138_set_t(a_837, g568));
 }
if (((kb_874) == (((int64_t)18LL)))) { (void)(f138_set_t(b_838, g568));
 }
(void)(f175_set_x(n_833, ((int64_t)2LL)));
return f138_set_t(n_833, g551);
 }
if ((((((((ka_873) == (((int64_t)5LL))) || ((ka_873) == (((int64_t)8LL)))) || ((ka_873) == (((int64_t)6LL)))) || ((ka_873) == (((int64_t)7LL)))) || ((ka_873) == (((int64_t)9LL)))) && ((da_854) == (db_855)))) { (void)(f175_set_x(n_833, ((int64_t)3LL)));
return f138_set_t(n_833, g551);
 }
if (((((ka_873) == (((int64_t)6LL))) && ((kb_874) == (((int64_t)7LL)))) || (((ka_873) == (((int64_t)7LL))) && ((kb_874) == (((int64_t)6LL)))))) { (void)(f175_set_x(n_833, ((int64_t)3LL)));
return f138_set_t(n_833, g551);
 }
if ((((ka_873) == (((int64_t)19LL))) || ((kb_874) == (((int64_t)19LL))))) { if (((ka_873) == (((int64_t)19LL)))) { (void)(f140_conv(a_837, db_855));
 } else { (void)(f140_conv(b_838, da_854));
 }
(void)(f175_set_x(n_833, ((int64_t)3LL)));
return f138_set_t(n_833, g551);
 }
 }
int64_t u_886 = f182_unify(n_833, a_837, b_838); 
if (cmp_848) { if (((((*({ hrv *_t2583 = &(g543); int64_t _i2583 = u_886; (S1*)_t2583->b + hr_ix(_i2583, _t2583->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:319"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(a_837, g555));
(void)(f140_conv(b_838, g555));
 }
if (((((*({ hrv *_t2586 = &(g543); int64_t _i2586 = u_886; (S1*)_t2586->b + hr_ix(_i2586, _t2586->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:319"); }))).k_) == (((uint8_t)13LL)))) { (void)(f140_conv(a_837, g561));
(void)(f140_conv(b_838, g561));
 }
return f138_set_t(n_833, g551);
 }
int64_t uk_887 = ((int64_t)(((*({ hrv *_t2590 = &(g543); int64_t _i2590 = u_886; (S1*)_t2590->b + hr_ix(_i2590, _t2590->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:320"); }))).k_)); 
if (((((((((o_836) == (((int64_t)49LL))) || ((o_836) == (((int64_t)50LL)))) || ((o_836) == (((int64_t)51LL)))) && ((uk_887) != (((int64_t)3LL)))) && ((uk_887) != (((int64_t)12LL)))) && ((uk_887) != (((int64_t)2LL)))) && ((uk_887) != (((int64_t)0LL))))) { (void)(f108_cerr(n_833, hr_str("bitwise operator on a non-integer", 33)));
 }
if ((((((uk_887) == (((int64_t)2LL))) && ((o_836) != (((int64_t)49LL)))) && ((o_836) != (((int64_t)50LL)))) && ((o_836) != (((int64_t)51LL))))) { (void)(f108_cerr(n_833, hr_str("arithmetic on bool", 18)));
 }
return f138_set_t(n_833, u_886);
}
static void f177_narrow_push(int64_t c_840) {
if (((c_840) < (((int64_t)0LL)))) { return;
 }
S4 x_841 = (*({ hrv *_t2594 = &(g696); int64_t _i2594 = c_840; (S4*)_t2594->b + hr_ix(_i2594, _t2594->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:84"); })); 
int64_t k_842 = ((int64_t)((x_841).k_)); 
if ((((k_842) == (((int64_t)8LL))) && ((f156_rk(c_840)) == (((int64_t)1LL))))) { int64_t v_843 = f157_rv(c_840); 
int64_t t_844 = ((int64_t)(((*({ hrv *_t2597 = &(g381); int64_t _i2597 = v_843; (S12*)_t2597->b + hr_ix(_i2597, _t2597->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:87"); }))).ty_)); 
if ((((((*({ hrv *_t2598 = &(g543); int64_t _i2598 = t_844; (S1*)_t2598->b + hr_ix(_i2598, _t2598->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:88"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t2599 = &(g543); int64_t _i2599 = t_844; (S1*)_t2599->b + hr_ix(_i2599, _t2599->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:88"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(({ hrv *_v2600 = &(g383); int32_t _x2600 = ((int32_t)(v_843)); int32_t *_p2600 = (int32_t*)hr_grow(_v2600, 1, sizeof _x2600); *_p2600 = _x2600; _p2600; }));
(void)(({ hrv *_v2601 = &(g383); int32_t _x2601 = ((int32_t)(t_844)); int32_t *_p2601 = (int32_t*)hr_grow(_v2601, 1, sizeof _x2601); *_p2601 = _x2601; _p2601; }));
{ int32_t *_t2602 = &(((*({ hrv *_t2603 = &(g381); int64_t _i2603 = v_843; (S12*)_t2603->b + hr_ix(_i2603, _t2603->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:90"); }))).ty_); *_t2602 = ((int32_t)(f119_t_ref(((int64_t)(((*({ hrv *_t2605 = &(g543); int64_t _i2605 = t_844; (S1*)_t2605->b + hr_ix(_i2605, _t2605->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:90"); }))).a_)), ((int64_t)0LL)))); }
 }
return;
 }
if ((((k_842) == (((int64_t)9LL))) && ((((int64_t)((x_841).op_))) == (((int64_t)52LL))))) { (void)(f177_narrow_push(((int64_t)((x_841).a_))));
(void)(f177_narrow_push(((int64_t)((x_841).b_))));
 }
}
static void f178_narrow_pop(int64_t m_845) {
while ((((g383).n) > (m_845))) { int32_t old_t_846 = ({ hrv *_v2609 = &(g383); if (!_v2609->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:101"); ((int32_t*)_v2609->b)[--_v2609->n]; }); 
int64_t v_847 = ((int64_t)(({ hrv *_v2610 = &(g383); if (!_v2610->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:102"); ((int32_t*)_v2610->b)[--_v2610->n]; }))); 
{ int32_t *_t2611 = &(((*({ hrv *_t2612 = &(g381); int64_t _i2612 = v_847; (S12*)_t2612->b + hr_ix(_i2612, _t2612->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:103"); }))).ty_); *_t2611 = old_t_846; }
 } _bk2608:; 
}
static int64_t f179_deref(int64_t t_851) {
return ({ int64_t _r2613; if ((((((*({ hrv *_t2614 = &(g543); int64_t _i2614 = t_851; (S1*)_t2614->b + hr_ix(_i2614, _t2614->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:67"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2615 = &(g543); int64_t _i2615 = t_851; (S1*)_t2615->b + hr_ix(_i2615, _t2615->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:67"); }))).c_) < (((int32_t)0LL))))) { _r2613 = ((int64_t)(((*({ hrv *_t2616 = &(g543); int64_t _i2616 = t_851; (S1*)_t2616->b + hr_ix(_i2616, _t2616->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:67"); }))).a_));  } else { _r2613 = t_851;  } _r2613; });
}
static int64_t f180_leaf_kind(int64_t t_856) {
S1 x_857 = (*({ hrv *_t2617 = &(g543); int64_t _i2617 = t_856; (S1*)_t2617->b + hr_ix(_i2617, _t2617->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:261"); })); 
int64_t k_858 = ((int64_t)((x_857).k_)); 
if (((k_858) == (((int64_t)3LL)))) { return ((int64_t)1LL);
 }
if (((k_858) == (((int64_t)4LL)))) { return ((int64_t)2LL);
 }
if (((k_858) == (((int64_t)5LL)))) { int64_t r_859 = ((int64_t)0LL); 
{ int32_t _e2619 = ((*({ hrv *_t2620 = &(g546); int64_t _i2620 = (x_857).a_; (S10*)_t2620->b + hr_ix(_i2620, _t2620->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:263"); }))).fnum_; for (int32_t _k2619 = 0; _k2619 < _e2619; _k2619++) { int32_t i_860 = (int32_t)_k2619; S11 f_861 = (*({ hrv *_t2621 = &(g547); int64_t _i2621 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2622 = &(g546); int64_t _i2622 = (x_857).a_; (S10*)_t2622->b + hr_ix(_i2622, _t2622->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:263"); }))).f0_)) + (int64_t)((int64_t)(i_860)))); (S11*)_t2621->b + hr_ix(_i2621, _t2621->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:263"); })); 
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
S1 x_867 = (*({ hrv *_t2625 = &(g543); int64_t _i2625 = t_866; (S1*)_t2625->b + hr_ix(_i2625, _t2625->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:268"); })); 
int64_t k_868 = ((int64_t)((x_867).k_)); 
if ((((k_868) == (((int64_t)3LL))) || ((k_868) == (((int64_t)4LL))))) { return t_866;
 }
if (((k_868) == (((int64_t)5LL)))) { int64_t r_869 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e2627 = ((*({ hrv *_t2628 = &(g546); int64_t _i2628 = (x_867).a_; (S10*)_t2628->b + hr_ix(_i2628, _t2628->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:270"); }))).fnum_; for (int32_t _k2627 = 0; _k2627 < _e2627; _k2627++) { int32_t i_870 = (int32_t)_k2627; S11 f_871 = (*({ hrv *_t2629 = &(g547); int64_t _i2629 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2630 = &(g546); int64_t _i2630 = (x_867).a_; (S10*)_t2630->b + hr_ix(_i2630, _t2630->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:270"); }))).f0_)) + (int64_t)((int64_t)(i_870)))); (S11*)_t2629->b + hr_ix(_i2629, _t2629->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:270"); })); 
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
if ((((ta_878) < (((int64_t)0LL))) || ((tb_879) < (((int64_t)0LL))))) { return g567;
 }
int64_t da_880 = f179_deref(ta_878); 
int64_t db_881 = f179_deref(tb_879); 
int64_t ka_882 = ((int64_t)(((*({ hrv *_t2637 = &(g543); int64_t _i2637 = da_880; (S1*)_t2637->b + hr_ix(_i2637, _t2637->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:237"); }))).k_)); 
int64_t kb_883 = ((int64_t)(((*({ hrv *_t2638 = &(g543); int64_t _i2638 = db_881; (S1*)_t2638->b + hr_ix(_i2638, _t2638->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:237"); }))).k_)); 
if ((((ka_882) == (((int64_t)0LL))) || ((kb_883) == (((int64_t)0LL))))) { return g567;
 }
if ((((ka_882) == (((int64_t)12LL))) && ((kb_883) == (((int64_t)12LL))))) { return g563;
 }
if (((((ka_882) == (((int64_t)12LL))) || ((ka_882) == (((int64_t)13LL)))) && ((kb_883) == (((int64_t)13LL))))) { return g564;
 }
if ((((ka_882) == (((int64_t)13LL))) && ((kb_883) == (((int64_t)12LL))))) { return g564;
 }
if ((((ka_882) == (((int64_t)18LL))) && ((kb_883) == (((int64_t)18LL))))) { (void)(f138_set_t(a_876, g568));
(void)(f138_set_t(b_877, g568));
return g568;
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
if (((kb_883) == (((int64_t)3LL)))) { return g564;
 }
 }
if (((kb_883) == (((int64_t)13LL)))) { if (((ka_882) == (((int64_t)4LL)))) { (void)(f140_conv(b_877, da_880));
return da_880;
 }
if (((ka_882) == (((int64_t)3LL)))) { return g564;
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
if (((((ka_882) == (((int64_t)7LL))) && ((kb_883) == (((int64_t)7LL)))) && ((((*({ hrv *_t2657 = &(g543); int64_t _i2657 = da_880; (S1*)_t2657->b + hr_ix(_i2657, _t2657->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:254"); }))).a_) == (((*({ hrv *_t2658 = &(g543); int64_t _i2658 = db_881; (S1*)_t2658->b + hr_ix(_i2658, _t2658->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:254"); }))).a_)))) { int64_t et_884 = f136_t_enum(((int64_t)(((*({ hrv *_t2660 = &(g543); int64_t _i2660 = da_880; (S1*)_t2660->b + hr_ix(_i2660, _t2660->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:254"); }))).a_)), false); 
(void)(f142_set_cv(a_876, et_884));
(void)(f142_set_cv(b_877, et_884));
return et_884;
 }
if (((((ka_882) == (((int64_t)6LL))) && ((kb_883) == (((int64_t)7LL)))) && ((((*({ hrv *_t2663 = &(g543); int64_t _i2663 = da_880; (S1*)_t2663->b + hr_ix(_i2663, _t2663->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:255"); }))).a_) == (((*({ hrv *_t2664 = &(g543); int64_t _i2664 = db_881; (S1*)_t2664->b + hr_ix(_i2664, _t2664->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:255"); }))).a_)))) { (void)(f142_set_cv(b_877, da_880));
if (((ta_878) != (da_880))) { (void)(f142_set_cv(a_876, da_880));
 }
return da_880;
 }
if (((((kb_883) == (((int64_t)6LL))) && ((ka_882) == (((int64_t)7LL)))) && ((((*({ hrv *_t2667 = &(g543); int64_t _i2667 = da_880; (S1*)_t2667->b + hr_ix(_i2667, _t2667->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:256"); }))).a_) == (((*({ hrv *_t2668 = &(g543); int64_t _i2668 = db_881; (S1*)_t2668->b + hr_ix(_i2668, _t2668->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:256"); }))).a_)))) { (void)(f142_set_cv(a_876, db_881));
if (((tb_879) != (db_881))) { (void)(f142_set_cv(b_877, db_881));
 }
return db_881;
 }
hrv m_885 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2673 __attribute__((cleanup(hr_rdrop))) = {0}; hrv _t2675 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2672 = &(m_885); hr_fs(_o2672, hr_str("operands of types ", 18)); hr_fs(_o2672, hr_sl(*hr_tmp(&_t2673, f161_tn(da_880)))); hr_fs(_o2672, hr_str(" and ", 5)); hr_fs(_o2672, hr_sl(*hr_tmp(&_t2675, f161_tn(db_881)))); hr_fs(_o2672, hr_str(" need a cast to a common type", 29)); }));
}
(void)(f108_cerr(n_875, hr_sl(m_885)));
return g567;
}
static int64_t f183_ck_un(int64_t n_889, int64_t want_890) {
S4 x_891 = (*({ hrv *_t2678 = &(g696); int64_t _i2678 = n_889; (S4*)_t2678->b + hr_ix(_i2678, _t2678->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:326"); })); 
int64_t o_892 = ((int64_t)((x_891).op_)); 
int64_t a_893 = ((int64_t)((x_891).a_)); 
if (((o_892) == (((int64_t)47LL)))) { (void)(f137_ck(a_893, g551));
(void)(f140_conv(a_893, g551));
return f138_set_t(n_889, g551);
 }
if (((o_892) == (((int64_t)49LL)))) { int64_t t_894 = f137_ck(a_893, ({ int64_t _r2683; if ((((want_890) >= (((int64_t)0LL))) && ((((*({ hrv *_t2684 = &(g543); int64_t _i2684 = want_890; (S1*)_t2684->b + hr_ix(_i2684, _t2684->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:329"); }))).k_) == (((uint8_t)10LL))))) { _r2683 = ((int64_t)(((*({ hrv *_t2685 = &(g543); int64_t _i2685 = want_890; (S1*)_t2685->b + hr_ix(_i2685, _t2685->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:329"); }))).a_));  } else { _r2683 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2683; })); 
if (f163_is_pending(t_894)) { (void)(f184_default_t(a_893));
 }
(void)(f175_set_x(n_889, ((int64_t)1LL)));
return f138_set_t(n_889, f141_at(a_893));
 }
int64_t t_913 = f137_ck(a_893, want_890); 
int64_t d_914 = f179_deref(t_913); 
if (((t_913) != (d_914))) { (void)(f142_set_cv(a_893, d_914));
 }
if (((((o_892) == (((int64_t)22LL))) && ((((*({ hrv *_t2694 = &(g543); int64_t _i2694 = d_914; (S1*)_t2694->b + hr_ix(_i2694, _t2694->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:333"); }))).k_) == (((uint8_t)3LL)))) && (!(f153_is_signed(d_914))))) { (void)(f108_cerr(n_889, hr_str("unary - of an unsigned integer", 30)));
 }
return f138_set_t(n_889, d_914);
}
static int64_t f184_default_t(int64_t n_895) {
int64_t t_896 = f141_at(n_895); 
if (((t_896) < (((int64_t)0LL)))) { return g550;
 }
int64_t k_897 = ((int64_t)(((*({ hrv *_t2699 = &(g543); int64_t _i2699 = t_896; (S1*)_t2699->b + hr_ix(_i2699, _t2699->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:215"); }))).k_)); 
if (((k_897) == (((int64_t)12LL)))) { M78 _t2700 = f155_cval(n_895); int64_t v_898 = _t2700.r0; bool u_899 = _t2700.r1; bool ok_900 = _t2700.r2; 
int64_t d_901 = ({ int64_t _r2702; if ((ok_900 && u_899)) { _r2702 = g559;  } else { _r2702 = g555;  } _r2702; }); 
(void)(f162_commit(n_895, d_901));
return d_901;
 }
if (((k_897) == (((int64_t)13LL)))) { (void)(f162_commit(n_895, g561));
return g561;
 }
if (((k_897) == (((int64_t)18LL)))) { (void)(f138_set_t(n_895, g568));
return g568;
 }
if (((k_897) == (((int64_t)19LL)))) { S4 x_902 = (*({ hrv *_t2706 = &(g696); int64_t _i2706 = n_895; (S4*)_t2706->b + hr_ix(_i2706, _t2706->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:220"); })); 
int64_t e_903 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((x_902).a_) >= (((int32_t)0LL)))) { e_903 = f184_default_t(((int64_t)((x_902).a_)));
M78 _t2708 = f155_cval(((int64_t)((x_902).b_))); int64_t cnt_904 = _t2708.r0; bool u0_905 = _t2708.r1; bool ok_906 = _t2708.r2; 
(void)(f140_conv(((int64_t)((x_902).b_)), g555));
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
return g567;
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
S4 x_918 = (*({ hrv *_t2727 = &(g696); int64_t _i2727 = n_916; (S4*)_t2727->b + hr_ix(_i2727, _t2727->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:405"); })); 
int64_t a_919 = ((int64_t)((x_918).a_)); 
int64_t name_920 = ((int64_t)((x_918).s_)); 
if ((((((*({ hrv *_t2728 = &(g696); int64_t _i2728 = a_919; (S4*)_t2728->b + hr_ix(_i2728, _t2728->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:408"); }))).k_) == (((uint8_t)8LL))) && ((f167_find_lv(((int64_t)(((*({ hrv *_t2730 = &(g696); int64_t _i2730 = a_919; (S4*)_t2730->b + hr_ix(_i2730, _t2730->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:408"); }))).s_)))) < (((int64_t)0LL))))) { int64_t ns_921 = f110_ns_of(a_919); 
int64_t de_922 = f116_lookup_q(((int64_t)(((*({ hrv *_t2733 = &(g696); int64_t _i2733 = a_919; (S4*)_t2733->b + hr_ix(_i2733, _t2733->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:410"); }))).s_)), ns_921, ((int64_t)2LL)); 
if ((((de_922) >= (((int64_t)0LL))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t2735 = &(g696); int64_t _i2735 = a_919; (S4*)_t2735->b + hr_ix(_i2735, _t2735->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:411"); }))).s_)), ns_921, ((int64_t)5LL))) < (((int64_t)0LL))))) { int64_t et_926 = f186_rtype_name_enum(de_922); 
int64_t ei_927 = ((int64_t)(((*({ hrv *_t2737 = &(g543); int64_t _i2737 = et_926; (S1*)_t2737->b + hr_ix(_i2737, _t2737->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:413"); }))).a_)); 
{ int32_t _e2739 = ((*({ hrv *_t2740 = &(g548); int64_t _i2740 = ei_927; (S8*)_t2740->b + hr_ix(_i2740, _t2740->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:414"); }))).vnum_; for (int32_t _k2739 = 0; _k2739 < _e2739; _k2739++) { int32_t i_928 = (int32_t)_k2739; if (((((int64_t)(((*({ hrv *_t2741 = &(g549); int64_t _i2741 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2742 = &(g548); int64_t _i2742 = ei_927; (S8*)_t2742->b + hr_ix(_i2742, _t2742->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:414"); }))).v0_)) + (int64_t)((int64_t)(i_928)))); (S9*)_t2741->b + hr_ix(_i2741, _t2741->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:414"); }))).name_))) == (name_920))) { (void)(f170_set_r(n_916, ((int64_t)7LL), ((int64_t)(i_928))));
return f138_set_t(n_916, f125_t_variant(ei_927, ((int64_t)(i_928))));
 }
 } } _bk2738:; 
hrv m_929 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2749 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2747 = &(m_929); hr_fs(_o2747, hr_str("no variant ", 11)); hr_fs(_o2747, f10_nm(name_920)); hr_fs(_o2747, hr_str(" in ", 4)); hr_fs(_o2747, hr_sl(*hr_tmp(&_t2749, f161_tn(et_926)))); }));
}
(void)(f108_cerr(n_916, hr_sl(m_929)));
return f138_set_t(n_916, g567);
 }
 }
int64_t t0_930 = f137_ck(a_919, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t t_931 = t0_930; 
if (((((*({ hrv *_t2754 = &(g543); int64_t _i2754 = t_931; (S1*)_t2754->b + hr_ix(_i2754, _t2754->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:420"); }))).k_) == (((uint8_t)18LL)))) { t_931 = g568;
(void)(f138_set_t(a_919, g568));
 }
if (((((*({ hrv *_t2756 = &(g543); int64_t _i2756 = t_931; (S1*)_t2756->b + hr_ix(_i2756, _t2756->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:421"); }))).k_) == (((uint8_t)19LL)))) { t_931 = f184_default_t(a_919);
 }
int64_t d_932 = f179_deref(t_931); 
int64_t k_933 = ((int64_t)(((*({ hrv *_t2759 = &(g543); int64_t _i2759 = d_932; (S1*)_t2759->b + hr_ix(_i2759, _t2759->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:423"); }))).k_)); 
if (((((k_933) == (((int64_t)8LL))) || ((k_933) == (((int64_t)9LL)))) && hr_streq(f10_nm(name_920), hr_str("len", 3)))) { (void)(f170_set_r(n_916, ((int64_t)8LL), ((int64_t)1LL)));
return f138_set_t(n_916, g555);
 }
if ((((k_933) == (((int64_t)8LL))) && hr_streq(f10_nm(name_920), hr_str("cap", 3)))) { (void)(f170_set_r(n_916, ((int64_t)8LL), ((int64_t)2LL)));
return f138_set_t(n_916, g555);
 }
if (((k_933) == (((int64_t)5LL)))) { int64_t si_934 = ((int64_t)(((*({ hrv *_t2766 = &(g543); int64_t _i2766 = d_932; (S1*)_t2766->b + hr_ix(_i2766, _t2766->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:427"); }))).a_)); 
int64_t fi_938 = f187_sfield(si_934, name_920); 
if (((fi_938) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_916, ((int64_t)5LL), fi_938));
int64_t ft_939 = ((int64_t)(((*({ hrv *_t2769 = &(g547); int64_t _i2769 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2770 = &(g546); int64_t _i2770 = si_934; (S10*)_t2770->b + hr_ix(_i2770, _t2770->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:429"); }))).f0_)) + (int64_t)fi_938)); (S11*)_t2769->b + hr_ix(_i2769, _t2769->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:429"); }))).ty_)); 
return f138_set_t(n_916, f188_decode_rel(ft_939));
 }
 }
if (((k_933) == (((int64_t)7LL)))) { S9 v_941 = (*({ hrv *_t2773 = &(g549); int64_t _i2773 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2774 = &(g548); int64_t _i2774 = ((*({ hrv *_t2775 = &(g543); int64_t _i2775 = d_932; (S1*)_t2775->b + hr_ix(_i2775, _t2775->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:432"); }))).a_; (S8*)_t2774->b + hr_ix(_i2774, _t2774->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:432"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t2776 = &(g543); int64_t _i2776 = d_932; (S1*)_t2776->b + hr_ix(_i2776, _t2776->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:432"); }))).c_)))); (S9*)_t2773->b + hr_ix(_i2773, _t2773->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:432"); })); 
if ((((v_941).si_) >= (((int32_t)0LL)))) { int64_t fi_942 = f187_sfield(((int64_t)((v_941).si_)), name_920); 
if (((fi_942) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_916, ((int64_t)5LL), fi_942));
(void)(f175_set_x(n_916, ((int64_t)((v_941).si_))));
return f138_set_t(n_916, f188_decode_rel(((int64_t)(((*({ hrv *_t2782 = &(g547); int64_t _i2782 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2783 = &(g546); int64_t _i2783 = (v_941).si_; (S10*)_t2783->b + hr_ix(_i2783, _t2783->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:433"); }))).f0_)) + (int64_t)fi_942)); (S11*)_t2782->b + hr_ix(_i2782, _t2782->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:433"); }))).ty_))));
 }
 }
 }
hrv m_943 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2787 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2785 = &(m_943); hr_fs(_o2785, hr_str("no field ", 9)); hr_fs(_o2785, f10_nm(name_920)); hr_fs(_o2785, hr_str(" in ", 4)); hr_fs(_o2785, hr_sl(*hr_tmp(&_t2787, f161_tn(d_932)))); }));
}
(void)(f108_cerr(n_916, hr_sl(m_943)));
return f138_set_t(n_916, g567);
}
static int64_t f186_rtype_name_enum(int64_t de_923) {
int64_t node_924 = ((int64_t)(((*({ hrv *_t2791 = &(g481); int64_t _i2791 = de_923; (S5*)_t2791->b + hr_ix(_i2791, _t2791->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:438"); }))).node_)); 
L84 none_925 = ({ L84 _t2792; memset(&_t2792, 0, sizeof _t2792); _t2792.n = 0; _t2792; }); 
return f136_t_enum(f135_inst_enum(node_924, ({ hsl _t2795 = ({ L84 *_t2796 = &(none_925); (hsl){ (uint8_t*)_t2796->e, _t2796->n }; }); int64_t _l2795 = 0, _h2795 = _t2795.n; if (_l2795 < 0 || _h2795 < _l2795 || _h2795 > _t2795.n) hr_slerr(_l2795, _h2795, _t2795.n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:438"); (hsl){ _t2795.p + _l2795 * (int64_t)sizeof(int32_t), _h2795 - _l2795 }; })), false);
}
static int64_t f187_sfield(int64_t si_935, int64_t name_936) {
{ int32_t _e2798 = ((*({ hrv *_t2799 = &(g546); int64_t _i2799 = si_935; (S10*)_t2799->b + hr_ix(_i2799, _t2799->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:196"); }))).fnum_; for (int32_t _k2798 = 0; _k2798 < _e2798; _k2798++) { int32_t i_937 = (int32_t)_k2798; if (((((int64_t)(((*({ hrv *_t2800 = &(g547); int64_t _i2800 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2801 = &(g546); int64_t _i2801 = si_935; (S10*)_t2801->b + hr_ix(_i2801, _t2801->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:196"); }))).f0_)) + (int64_t)((int64_t)(i_937)))); (S11*)_t2800->b + hr_ix(_i2800, _t2800->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:196"); }))).name_))) == (name_936))) { return ((int64_t)(i_937));
 }
 } } _bk2797:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f188_decode_rel(int64_t ft_940) {
return ({ int64_t _r2802; if ((((((*({ hrv *_t2803 = &(g543); int64_t _i2803 = ft_940; (S1*)_t2803->b + hr_ix(_i2803, _t2803->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:403"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2804 = &(g543); int64_t _i2804 = ft_940; (S1*)_t2804->b + hr_ix(_i2804, _t2804->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:403"); }))).c_) >= (((int32_t)0LL))))) { _r2802 = f119_t_ref(((int64_t)(((*({ hrv *_t2806 = &(g543); int64_t _i2806 = ft_940; (S1*)_t2806->b + hr_ix(_i2806, _t2806->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:403"); }))).a_)), ((int64_t)(((*({ hrv *_t2807 = &(g543); int64_t _i2807 = ft_940; (S1*)_t2807->b + hr_ix(_i2807, _t2807->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:403"); }))).fl_)));  } else { _r2802 = ft_940;  } _r2802; });
}
static int64_t f189_ck_idx(int64_t n_944, int64_t want_945) {
S4 x_946 = (*({ hrv *_t2808 = &(g696); int64_t _i2808 = n_944; (S4*)_t2808->b + hr_ix(_i2808, _t2808->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:440"); })); 
int64_t t_947 = f137_ck(((int64_t)((x_946).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t2810 = &(g543); int64_t _i2810 = t_947; (S1*)_t2810->b + hr_ix(_i2810, _t2810->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:442"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_946).a_)), g568));
t_947 = g568;
 }
if (((((*({ hrv *_t2812 = &(g543); int64_t _i2812 = t_947; (S1*)_t2812->b + hr_ix(_i2812, _t2812->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:443"); }))).k_) == (((uint8_t)19LL)))) { t_947 = f184_default_t(((int64_t)((x_946).a_)));
 }
int64_t d_948 = f179_deref(t_947); 
int64_t ti_949 = f137_ck(((int64_t)((x_946).b_)), g555); 
if (((((*({ hrv *_t2816 = &(g543); int64_t _i2816 = ti_949; (S1*)_t2816->b + hr_ix(_i2816, _t2816->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:446"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_946).b_)), g555));
 } else { int64_t di_950 = f179_deref(ti_949); 
if ((((((*({ hrv *_t2819 = &(g543); int64_t _i2819 = di_950; (S1*)_t2819->b + hr_ix(_i2819, _t2819->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:446"); }))).k_) != (((uint8_t)3LL))) && ((((*({ hrv *_t2820 = &(g543); int64_t _i2820 = di_950; (S1*)_t2820->b + hr_ix(_i2820, _t2820->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:446"); }))).k_) != (((uint8_t)17LL))))) { (void)(f108_cerr(((int64_t)((x_946).b_)), hr_str("index must be an integer", 24)));
 } else { if (((di_950) != (ti_949))) { (void)(f142_set_cv(((int64_t)((x_946).b_)), di_950));
 }
 }
 }
int64_t k_951 = ((int64_t)(((*({ hrv *_t2823 = &(g543); int64_t _i2823 = d_948; (S1*)_t2823->b + hr_ix(_i2823, _t2823->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:447"); }))).k_)); 
if ((((k_951) == (((int64_t)8LL))) || ((k_951) == (((int64_t)9LL))))) { return f138_set_t(n_944, f188_decode_rel(((int64_t)(((*({ hrv *_t2826 = &(g543); int64_t _i2826 = d_948; (S1*)_t2826->b + hr_ix(_i2826, _t2826->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:448"); }))).a_))));
 }
hrv m_952 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2829 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2828 = &(m_952); hr_fs(_o2828, hr_str("cannot index ", 13)); hr_fs(_o2828, hr_sl(*hr_tmp(&_t2829, f161_tn(d_948)))); }));
}
(void)(f108_cerr(n_944, hr_sl(m_952)));
return f138_set_t(n_944, g567);
}
static int64_t f190_ck_slice(int64_t n_953, int64_t want_954) {
S4 x_955 = (*({ hrv *_t2833 = &(g696); int64_t _i2833 = n_953; (S4*)_t2833->b + hr_ix(_i2833, _t2833->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:453"); })); 
int64_t t_956 = f137_ck(((int64_t)((x_955).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t2835 = &(g543); int64_t _i2835 = t_956; (S1*)_t2835->b + hr_ix(_i2835, _t2835->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:455"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_955).a_)), g568));
t_956 = g568;
 }
if (((((*({ hrv *_t2837 = &(g543); int64_t _i2837 = t_956; (S1*)_t2837->b + hr_ix(_i2837, _t2837->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:456"); }))).k_) == (((uint8_t)19LL)))) { t_956 = f184_default_t(((int64_t)((x_955).a_)));
 }
int64_t d_957 = f179_deref(t_956); 
if ((((x_955).b_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_955).b_)), g555));
(void)(f140_conv(((int64_t)((x_955).b_)), g555));
 }
if ((((x_955).c_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_955).c_)), g555));
(void)(f140_conv(((int64_t)((x_955).c_)), g555));
 }
int64_t k_958 = ((int64_t)(((*({ hrv *_t2844 = &(g543); int64_t _i2844 = d_957; (S1*)_t2844->b + hr_ix(_i2844, _t2844->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:460"); }))).k_)); 
if (((k_958) == (((int64_t)8LL)))) { return f138_set_t(n_953, f18_t_slice(((int64_t)(((*({ hrv *_t2847 = &(g543); int64_t _i2847 = d_957; (S1*)_t2847->b + hr_ix(_i2847, _t2847->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:461"); }))).a_)), false));
 }
if (((k_958) == (((int64_t)9LL)))) { return f138_set_t(n_953, d_957);
 }
hrv m_959 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2851 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2850 = &(m_959); hr_fs(_o2850, hr_str("cannot slice ", 13)); hr_fs(_o2850, hr_sl(*hr_tmp(&_t2851, f161_tn(d_957)))); }));
}
(void)(f108_cerr(n_953, hr_sl(m_959)));
return f138_set_t(n_953, g567);
}
static int64_t f191_ck_as(int64_t n_960, int64_t want_961) {
S4 x_962 = (*({ hrv *_t2855 = &(g696); int64_t _i2855 = n_960; (S4*)_t2855->b + hr_ix(_i2855, _t2855->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:467"); })); 
int64_t t_963 = f113_rtype(((int64_t)((x_962).b_)), f110_ns_of(n_960)); 
int64_t f_964 = f137_ck(((int64_t)((x_962).a_)), ({ int64_t _r2859; if ((((((*({ hrv *_t2860 = &(g543); int64_t _i2860 = t_963; (S1*)_t2860->b + hr_ix(_i2860, _t2860->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:469"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2861 = &(g543); int64_t _i2861 = t_963; (S1*)_t2861->b + hr_ix(_i2861, _t2861->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:469"); }))).k_) == (((uint8_t)4LL))))) { _r2859 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r2859 = t_963;  } _r2859; })); 
int64_t df_965 = f179_deref(f_964); 
if ((((((*({ hrv *_t2863 = &(g543); int64_t _i2863 = df_965; (S1*)_t2863->b + hr_ix(_i2863, _t2863->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:471"); }))).k_) == (((uint8_t)12LL))) || ((((*({ hrv *_t2864 = &(g543); int64_t _i2864 = df_965; (S1*)_t2864->b + hr_ix(_i2864, _t2864->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:471"); }))).k_) == (((uint8_t)13LL))))) { (void)(f140_conv(((int64_t)((x_962).a_)), ({ int64_t _r2866; if ((((((*({ hrv *_t2867 = &(g543); int64_t _i2867 = t_963; (S1*)_t2867->b + hr_ix(_i2867, _t2867->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:471"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t2868 = &(g543); int64_t _i2868 = t_963; (S1*)_t2868->b + hr_ix(_i2868, _t2868->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:471"); }))).k_) == (((uint8_t)4LL))))) { _r2866 = t_963;  } else { _r2866 = g555;  } _r2866; })));
 } else { if (((df_965) != (f_964))) { (void)(f142_set_cv(((int64_t)((x_962).a_)), df_965));
 }
 }
return f138_set_t(n_960, t_963);
}
static int64_t f192_ck_arr(int64_t n_966, int64_t want_967) {
S4 x_968 = (*({ hrv *_t2871 = &(g696); int64_t _i2871 = n_966; (S4*)_t2871->b + hr_ix(_i2871, _t2871->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:703"); })); 
int64_t e_969 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((want_967) >= (((int64_t)0LL))) && (((((*({ hrv *_t2872 = &(g543); int64_t _i2872 = want_967; (S1*)_t2872->b + hr_ix(_i2872, _t2872->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:705"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2873 = &(g543); int64_t _i2873 = want_967; (S1*)_t2873->b + hr_ix(_i2873, _t2873->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:705"); }))).k_) == (((uint8_t)9LL)))))) { e_969 = ((int64_t)(((*({ hrv *_t2874 = &(g543); int64_t _i2874 = want_967; (S1*)_t2874->b + hr_ix(_i2874, _t2874->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:705"); }))).a_));
 }
if ((((x_968).c_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_968).c_)), g555));
(void)(f140_conv(((int64_t)((x_968).c_)), g555));
if (((want_967) >= (((int64_t)0LL)))) { return f138_set_t(n_966, want_967);
 }
return f138_set_t(n_966, g569);
 }
if ((((x_968).a_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)((x_968).a_)), e_969));
(void)(f137_ck(((int64_t)((x_968).b_)), g555));
if (((e_969) >= (((int64_t)0LL)))) { (void)(f140_conv(((int64_t)((x_968).a_)), e_969));
(void)(f140_conv(((int64_t)((x_968).b_)), g555));
if (((((*({ hrv *_t2883 = &(g543); int64_t _i2883 = want_967; (S1*)_t2883->b + hr_ix(_i2883, _t2883->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:707"); }))).k_) == (((uint8_t)9LL)))) { M78 _t2884 = f155_cval(((int64_t)((x_968).b_))); int64_t cnt_970 = _t2884.r0; bool u0_971 = _t2884.r1; bool ok_972 = _t2884.r2; 
(void)(f138_set_t(n_966, f123_t_arr(e_969, ((int64_t)1LL), cnt_970, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f142_set_cv(n_966, want_967));
return want_967;
 }
return f138_set_t(n_966, want_967);
 }
return f138_set_t(n_966, g569);
 }
{ int32_t _e2892 = (x_968).n_; for (int32_t _k2892 = 0; _k2892 < _e2892; _k2892++) { int32_t i_973 = (int32_t)_k2892; (void)(f137_ck(f90_kid(n_966, ((int64_t)(i_973))), e_969));
 } } _bk2891:; 
if (((e_969) >= (((int64_t)0LL)))) { { int32_t _e2896 = (x_968).n_; for (int32_t _k2896 = 0; _k2896 < _e2896; _k2896++) { int32_t i_974 = (int32_t)_k2896; (void)(f140_conv(f90_kid(n_966, ((int64_t)(i_974))), e_969));
 } } _bk2895:; 
if (((((*({ hrv *_t2899 = &(g543); int64_t _i2899 = want_967; (S1*)_t2899->b + hr_ix(_i2899, _t2899->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:711"); }))).k_) == (((uint8_t)9LL)))) { (void)(f138_set_t(n_966, f123_t_arr(e_969, ((int64_t)1LL), f103_max(((int64_t)((x_968).n_)), ((int64_t)1LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f142_set_cv(n_966, want_967));
return want_967;
 }
return f138_set_t(n_966, want_967);
 }
return f138_set_t(n_966, g569);
}
static int64_t f193_ck_block(int64_t n_975, int64_t want_976) {
S4 x_977 = (*({ hrv *_t2906 = &(g696); int64_t _i2906 = n_975; (S4*)_t2906->b + hr_ix(_i2906, _t2906->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:476"); })); 
int64_t m_978 = (g382).n; 
int64_t nm0_979 = (g383).n; 
int64_t nf0_1013 = f194_pre_decl_block_fns(n_975); 
{ int32_t _e2909 = (x_977).n_; for (int32_t _k2909 = 0; _k2909 < _e2909; _k2909++) { int32_t i_1014 = (int32_t)_k2909; (void)(f200_cstmt(f90_kid(n_975, ((int64_t)(i_1014)))));
 } } _bk2908:; 
int64_t t_1098 = g550; 
if ((((x_977).a_) >= (((int32_t)0LL)))) { t_1098 = f137_ck(((int64_t)((x_977).a_)), want_976);
 }
(void)(f211_pop_block_fns(nf0_1013));
(void)(f178_narrow_pop(nm0_979));
(void)(({ hrv *_v2915 = &(g382); int64_t _k2915 = ((int64_t)((int64_t)(g382).n - (int64_t)m_978)); if (_k2915 < 0 || _k2915 > _v2915->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:485"); _v2915->n -= _k2915; }));
return f138_set_t(n_975, t_1098);
}
static int64_t f194_pre_decl_block_fns(int64_t b_980) {
int64_t m_981 = (g310).n; 
{ int32_t _e2918 = ((*({ hrv *_t2919 = &(g696); int64_t _i2919 = b_980; (S4*)_t2919->b + hr_ix(_i2919, _t2919->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:32"); }))).n_; for (int32_t _k2918 = 0; _k2918 < _e2918; _k2918++) { int32_t q_982 = (int32_t)_k2918; int64_t c_983 = f90_kid(b_980, ((int64_t)(q_982))); 
if (((((int64_t)(((*({ hrv *_t2921 = &(g696); int64_t _i2921 = c_983; (S4*)_t2921->b + hr_ix(_i2921, _t2921->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:32"); }))).k_))) == (((int64_t)50LL)))) { int64_t i_984 = f105_new_inst(c_983, c_983, ((int64_t)((*({ hrv *_t2923 = &(g711); int64_t _i2923 = c_983; (int32_t*)_t2923->b + hr_ix(_i2923, _t2923->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:32"); })))), g393); 
(void)(({ hrv *_v2924 = &(g310); S14 _x2924 = ((S14){ .name_ = ((*({ hrv *_t2925 = &(g696); int64_t _i2925 = c_983; (S4*)_t2925->b + hr_ix(_i2925, _t2925->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:32"); }))).s_, .node_ = ((int32_t)(c_983)), .inst_ = ((int32_t)(i_984)), .own_ = ((int32_t)(g393)), }); S14 *_p2924 = (S14*)hr_grow(_v2924, 1, sizeof _x2924); *_p2924 = _x2924; _p2924; }));
(void)(f195_sig_inst(i_984));
 }
 } } _bk2917:; 
return m_981;
}
static void f195_sig_inst(int64_t i_985) {
int64_t node_986 = ((int64_t)(((*({ hrv *_t2927 = &(g380); int64_t _i2927 = i_985; (S6*)_t2927->b + hr_ix(_i2927, _t2927->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:106"); }))).node_)); 
int64_t ns_987 = f110_ns_of(node_986); 
int64_t g0_988 = (g483).n; 
{ int32_t _e2930 = ((*({ hrv *_t2931 = &(g380); int64_t _i2931 = i_985; (S6*)_t2931->b + hr_ix(_i2931, _t2931->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:109"); }))).gn_; for (int32_t _k2930 = 0; _k2930 < _e2930; _k2930++) { int32_t j_989 = (int32_t)_k2930; (void)(({ hrv *_v2932 = &(g483); S7 _x2932 = (*({ hrv *_t2933 = &(g386); int64_t _i2933 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2934 = &(g380); int64_t _i2934 = i_985; (S6*)_t2934->b + hr_ix(_i2934, _t2934->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:109"); }))).g0_)) + (int64_t)((int64_t)(j_989)))); (S7*)_t2933->b + hr_ix(_i2933, _t2933->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:109"); })); S7 *_p2932 = (S7*)hr_grow(_v2932, 1, sizeof _x2932); *_p2932 = _x2932; _p2932; }));
 } } _bk2929:; 
int64_t p0_990 = (g544).n; 
L88 pts_991 = ({ L88 _t2935; memset(&_t2935, 0, sizeof _t2935); _t2935.n = 0; _t2935; }); 
{ int32_t _e2937 = ((*({ hrv *_t2938 = &(g696); int64_t _i2938 = node_986; (S4*)_t2938->b + hr_ix(_i2938, _t2938->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:112"); }))).n_; for (int32_t _k2937 = 0; _k2937 < _e2937; _k2937++) { int32_t j_992 = (int32_t)_k2937; int64_t p_993 = f90_kid(node_986, ((int64_t)(j_992))); 
int64_t t_994 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((*({ hrv *_t2940 = &(g696); int64_t _i2940 = p_993; (S4*)_t2940->b + hr_ix(_i2940, _t2940->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:115"); }))).a_) >= (((int32_t)0LL)))) { t_994 = f113_rtype(((int64_t)(((*({ hrv *_t2942 = &(g696); int64_t _i2942 = p_993; (S4*)_t2942->b + hr_ix(_i2942, _t2942->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:115"); }))).a_)), ns_987);
 } else { t_994 = f130_gb_find(f196_upname(p_993));
if (((t_994) < (((int64_t)0LL)))) { t_994 = g567;
 }
 }
(void)(({ L88 *_v2945 = &(pts_991); int32_t _x2945 = ((int32_t)(t_994)); if (_v2945->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:116"); _v2945->e[_v2945->n] = _x2945; &_v2945->e[_v2945->n++]; }));
 } } _bk2936:; 
{ int32_t *_t2946 = &(((*({ hrv *_t2947 = &(g380); int64_t _i2947 = i_985; (S6*)_t2947->b + hr_ix(_i2947, _t2947->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:118"); }))).p0_); *_t2946 = ((int32_t)((g544).n)); }
(void)(({ hrv *_v2948 = &(g544); hsl _s2948 = ({ hsl _t2949 = ({ L88 *_t2950 = &(pts_991); (hsl){ (uint8_t*)_t2950->e, _t2950->n }; }); int64_t _l2949 = 0, _h2949 = _t2949.n; if (_l2949 < 0 || _h2949 < _l2949 || _h2949 > _t2949.n) hr_slerr(_l2949, _h2949, _t2949.n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:118"); (hsl){ _t2949.p + _l2949 * (int64_t)sizeof(int32_t), _h2949 - _l2949 }; }); hr_append(_v2948, _s2948.p, _s2948.n, sizeof(int32_t)); }));
{ int32_t *_t2951 = &(((*({ hrv *_t2952 = &(g380); int64_t _i2952 = i_985; (S6*)_t2952->b + hr_ix(_i2952, _t2952->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:118"); }))).pn_); *_t2951 = ((int32_t)(((int64_t)(pts_991).n))); }
if (((((*({ hrv *_t2953 = &(g696); int64_t _i2953 = node_986; (S4*)_t2953->b + hr_ix(_i2953, _t2953->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:119"); }))).b_) >= (((int32_t)0LL)))) { int64_t rl_997 = ((int64_t)(((*({ hrv *_t2954 = &(g696); int64_t _i2954 = node_986; (S4*)_t2954->b + hr_ix(_i2954, _t2954->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:120"); }))).b_)); 
if (((((*({ hrv *_t2955 = &(g696); int64_t _i2955 = rl_997; (S4*)_t2955->b + hr_ix(_i2955, _t2955->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:121"); }))).n_) == (((int32_t)1LL)))) { { int32_t *_t2956 = &(((*({ hrv *_t2957 = &(g380); int64_t _i2957 = i_985; (S6*)_t2957->b + hr_ix(_i2957, _t2957->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:121"); }))).ret_); *_t2956 = ((int32_t)(f113_rtype(f90_kid(rl_997, ((int64_t)0LL)), ns_987))); }
 } else { L89 rs_998 = ({ L89 _t2960; memset(&_t2960, 0, sizeof _t2960); _t2960.n = 0; _t2960; }); 
{ int32_t _e2962 = ((*({ hrv *_t2963 = &(g696); int64_t _i2963 = rl_997; (S4*)_t2963->b + hr_ix(_i2963, _t2963->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:122"); }))).n_; for (int32_t _k2962 = 0; _k2962 < _e2962; _k2962++) { int32_t j_999 = (int32_t)_k2962; int64_t r0_1000 = f113_rtype(f90_kid(rl_997, ((int64_t)(j_999))), ns_987); 
(void)(({ L89 *_v2966 = &(rs_998); int32_t _x2966 = ((int32_t)(r0_1000)); if (_v2966->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:122"); _v2966->e[_v2966->n] = _x2966; &_v2966->e[_v2966->n++]; }));
 } } _bk2961:; 
{ int32_t *_t2967 = &(((*({ hrv *_t2968 = &(g380); int64_t _i2968 = i_985; (S6*)_t2968->b + hr_ix(_i2968, _t2968->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:122"); }))).ret_); *_t2967 = ((int32_t)(f197_tlist(((int64_t)14LL), ({ hsl _t2970 = ({ L89 *_t2971 = &(rs_998); (hsl){ (uint8_t*)_t2971->e, _t2971->n }; }); int64_t _l2970 = 0, _h2970 = _t2970.n; if (_l2970 < 0 || _h2970 < _l2970 || _h2970 > _t2970.n) hr_slerr(_l2970, _h2970, _t2970.n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:122"); (hsl){ _t2970.p + _l2970 * (int64_t)sizeof(int32_t), _h2970 - _l2970 }; }), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); }
 }
 } else { { int32_t *_t2972 = &(((*({ hrv *_t2973 = &(g380); int64_t _i2973 = i_985; (S6*)_t2973->b + hr_ix(_i2973, _t2973->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:123"); }))).ret_); *_t2972 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
{ bool *_t2974 = &(((*({ hrv *_t2975 = &(g380); int64_t _i2975 = i_985; (S6*)_t2975->b + hr_ix(_i2975, _t2975->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:123"); }))).rinf_); *_t2974 = true; }
if ((((((uint16_t)((uint64_t)((*({ hrv *_t2976 = &(g696); int64_t _i2976 = node_986; (S4*)_t2976->b + hr_ix(_i2976, _t2976->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:123"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || f198_surely_void(node_986))) { { int32_t *_t2978 = &(((*({ hrv *_t2979 = &(g380); int64_t _i2979 = i_985; (S6*)_t2979->b + hr_ix(_i2979, _t2979->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:123"); }))).ret_); *_t2978 = ((int32_t)(g550)); }
{ bool *_t2980 = &(((*({ hrv *_t2981 = &(g380); int64_t _i2981 = i_985; (S6*)_t2981->b + hr_ix(_i2981, _t2981->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:123"); }))).rinf_); *_t2980 = false; }
 }
 }
(void)(({ hrv *_v2982 = &(g483); int64_t _k2982 = ((int64_t)((int64_t)(g483).n - (int64_t)g0_988)); if (_k2982 < 0 || _k2982 > _v2982->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:124"); _v2982->n -= _k2982; }));
}
static int64_t f196_upname(int64_t p_995) {
hrv s_996 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v2984 = &(s_996); uint8_t _x2984 = ((uint8_t)36LL); uint8_t *_p2984 = (uint8_t*)hr_grow(_v2984, 1, sizeof _x2984); *_p2984 = _x2984; _p2984; }));
(void)(({ hrv *_v2985 = &(s_996); hsl _s2985 = f10_nm(((int64_t)(((*({ hrv *_t2987 = &(g696); int64_t _i2987 = p_995; (S4*)_t2987->b + hr_ix(_i2987, _t2987->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:60"); }))).s_))); hr_append(_v2985, _s2985.p, _s2985.n, sizeof(uint8_t)); }));
return f8_intern(hr_sl(s_996));
}
static int64_t f197_tlist(int64_t k_1001, hsl xs_1002, int64_t a_1003) {
int64_t l_1004 = (g544).n; 
(void)(({ hrv *_v2989 = &(g544); hsl _s2989 = xs_1002; hr_append(_v2989, _s2989.p, _s2989.n, sizeof(int32_t)); }));
return f13_tmk(((S1){ .k_ = ((uint8_t)(k_1001)), .a_ = ((int32_t)(a_1003)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .l_ = ((int32_t)(l_1004)), .n_ = ((int32_t)((xs_1002).n)), }));
}
static bool f198_surely_void(int64_t fnode_1005) {
int64_t body_1006 = ((int64_t)(((*({ hrv *_t2991 = &(g696); int64_t _i2991 = fnode_1005; (S4*)_t2991->b + hr_ix(_i2991, _t2991->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:127"); }))).c_)); 
if (((body_1006) < (((int64_t)0LL)))) { return true;
 }
int64_t tl_1007 = ((int64_t)(((*({ hrv *_t2992 = &(g696); int64_t _i2992 = body_1006; (S4*)_t2992->b + hr_ix(_i2992, _t2992->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:129"); }))).a_)); 
if (((tl_1007) >= (((int64_t)0LL)))) { int64_t k_1008 = ((int64_t)(((*({ hrv *_t2993 = &(g696); int64_t _i2993 = tl_1007; (S4*)_t2993->b + hr_ix(_i2993, _t2993->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:130"); }))).k_)); 
if ((!((((((((k_1008) == (((int64_t)25LL))) || ((k_1008) == (((int64_t)27LL)))) || ((k_1008) == (((int64_t)28LL)))) || ((k_1008) == (((int64_t)29LL)))) || ((k_1008) == (((int64_t)30LL)))) || (((k_1008) == (((int64_t)19LL))) && ((((*({ hrv *_t2994 = &(g696); int64_t _i2994 = tl_1007; (S4*)_t2994->b + hr_ix(_i2994, _t2994->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:130"); }))).c_) < (((int32_t)0LL)))))))) { return false;
 }
 }
return (!(f199_has_valret(body_1006)));
}
static bool f199_has_valret(int64_t n_1009) {
if (((n_1009) < (((int64_t)0LL)))) { return false;
 }
S4 x_1010 = (*({ hrv *_t2996 = &(g696); int64_t _i2996 = n_1009; (S4*)_t2996->b + hr_ix(_i2996, _t2996->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:135"); })); 
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
S4 x_1016 = (*({ hrv *_t3005 = &(g696); int64_t _i3005 = n_1015; (S4*)_t3005->b + hr_ix(_i3005, _t3005->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:717"); })); 
int64_t k_1017 = ((int64_t)((x_1016).k_)); 
if (((k_1017) == (((int64_t)33LL)))) { (void)(f201_ck_vdecl(n_1015));
return;
 }
if (((k_1017) == (((int64_t)34LL)))) { (void)(f205_ck_assign(n_1015));
return;
 }
if (((k_1017) == (((int64_t)35LL)))) { int64_t t_1062 = f137_ck(((int64_t)((x_1016).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if ((((((*({ hrv *_t3009 = &(g543); int64_t _i3009 = f179_deref(t_1062); (S1*)_t3009->b + hr_ix(_i3009, _t3009->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:721"); }))).k_) != (((uint8_t)3LL))) && ((((*({ hrv *_t3011 = &(g543); int64_t _i3011 = f179_deref(t_1062); (S1*)_t3011->b + hr_ix(_i3011, _t3011->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:721"); }))).k_) != (((uint8_t)17LL))))) { (void)(f108_cerr(n_1015, hr_str("++/-- needs an integer", 22)));
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
S4 x_1019 = (*({ hrv *_t3018 = &(g696); int64_t _i3018 = n_1018; (S4*)_t3018->b + hr_ix(_i3018, _t3018->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:728"); })); 
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
if (((((*({ hrv *_t3028 = &(g543); int64_t _i3028 = t_1026; (S1*)_t3028->b + hr_ix(_i3028, _t3028->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:738"); }))).k_) != (((uint8_t)14LL)))) { if (((((int64_t)(((*({ hrv *_t3029 = &(g696); int64_t _i3029 = (x_1019).b_; (S4*)_t3029->b + hr_ix(_i3029, _t3029->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:738"); }))).n_))) == (((int64_t)((x_1019).n_))))) { { int32_t _e3031 = (x_1019).n_; for (int32_t _k3031 = ((int32_t)1LL); _k3031 < _e3031; _k3031++) { int32_t i_1027 = (int32_t)_k3031; int64_t iv_1028 = f90_kid(((int64_t)((x_1019).b_)), ((int64_t)(i_1027))); 
(void)(f137_ck(iv_1028, dt_1023));
if (((dt_1023) >= (((int64_t)0LL)))) { (void)(f140_conv(iv_1028, dt_1023));
 } else { (void)(f184_default_t(iv_1028));
 }
 } } _bk3030:; 
if (((dt_1023) >= (((int64_t)0LL)))) { (void)(f140_conv(init_1025, dt_1023));
 } else { (void)(f184_default_t(init_1025));
 }
{ int32_t _e3039 = (x_1019).n_; for (int32_t _k3039 = 0; _k3039 < _e3039; _k3039++) { int32_t i_1029 = (int32_t)_k3039; int64_t iv_1030 = f90_kid(((int64_t)((x_1019).b_)), ((int64_t)(i_1029))); 
int64_t v_1037 = f203_add_lv(((int64_t)((*({ hrv *_t3042 = &(g697); int64_t _i3042 = ((int64_t)((int64_t)((int64_t)((x_1019).l_)) + (int64_t)((int64_t)(i_1029)))); (int32_t*)_t3042->b + hr_ix(_i3042, _t3042->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:738"); })))), ({ int64_t _r3043; if (((dt_1023) >= (((int64_t)0LL)))) { _r3043 = dt_1023;  } else { _r3043 = f202_fin_t(iv_1030);  } _r3043; }), lf_1024, n_1018); 
if (((i_1029) == (((int32_t)0LL)))) { (void)(f170_set_r(n_1018, ((int64_t)1LL), v_1037));
 }
 } } _bk3038:; 
(void)(f175_set_x(n_1018, ((int64_t)1LL)));
return;
 }
(void)(f108_cerr(n_1018, hr_str("several names need a call with as many results", 46)));
return;
 }
if (((((*({ hrv *_t3048 = &(g543); int64_t _i3048 = t_1026; (S1*)_t3048->b + hr_ix(_i3048, _t3048->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:739"); }))).n_) != ((x_1019).n_))) { (void)(f108_cerr(n_1018, hr_str("result count does not match the names", 37)));
 }
{ int32_t _e3051 = (x_1019).n_; for (int32_t _k3051 = 0; _k3051 < _e3051; _k3051++) { int32_t i_1038 = (int32_t)_k3051; int64_t et_1039 = ({ int64_t _r3052; if (((((int64_t)(i_1038))) < (((int64_t)(((*({ hrv *_t3053 = &(g543); int64_t _i3053 = t_1026; (S1*)_t3053->b + hr_ix(_i3053, _t3053->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:740"); }))).n_))))) { _r3052 = ((int64_t)((*({ hrv *_t3054 = &(g544); int64_t _i3054 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3055 = &(g543); int64_t _i3055 = t_1026; (S1*)_t3055->b + hr_ix(_i3055, _t3055->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:740"); }))).l_)) + (int64_t)((int64_t)(i_1038)))); (int32_t*)_t3054->b + hr_ix(_i3054, _t3054->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:740"); }))));  } else { _r3052 = g567;  } _r3052; }); 
int64_t v_1040 = f203_add_lv(((int64_t)((*({ hrv *_t3057 = &(g697); int64_t _i3057 = ((int64_t)((int64_t)((int64_t)((x_1019).l_)) + (int64_t)((int64_t)(i_1038)))); (int32_t*)_t3057->b + hr_ix(_i3057, _t3057->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:740"); })))), et_1039, lf_1024, n_1018); 
if (((i_1038) == (((int32_t)0LL)))) { (void)(f170_set_r(n_1018, ((int64_t)1LL), v_1040));
 }
 } } _bk3050:; 
return;
 }
int64_t t_1041 = dt_1023; 
if ((((x_1019).b_) >= (((int32_t)0LL)))) { int64_t init_1042 = f90_kid(((int64_t)((x_1019).b_)), ((int64_t)0LL)); 
if (((((((dt_1023) < (((int64_t)0LL))) && ((((*({ hrv *_t3060 = &(g696); int64_t _i3060 = init_1042; (S4*)_t3060->b + hr_ix(_i3060, _t3060->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:746"); }))).k_) == (((uint8_t)16LL)))) && ((((*({ hrv *_t3061 = &(g696); int64_t _i3061 = init_1042; (S4*)_t3061->b + hr_ix(_i3061, _t3061->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:746"); }))).n_) == (((int32_t)0LL)))) && ((((*({ hrv *_t3062 = &(g696); int64_t _i3062 = init_1042; (S4*)_t3062->b + hr_ix(_i3062, _t3062->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:746"); }))).a_) < (((int32_t)0LL)))) && ((((*({ hrv *_t3063 = &(g696); int64_t _i3063 = init_1042; (S4*)_t3063->b + hr_ix(_i3063, _t3063->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:746"); }))).c_) < (((int32_t)0LL))))) { t_1041 = f123_t_arr(g567, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
(void)(f138_set_t(init_1042, t_1041));
 } else { int64_t it_1043 = f137_ck(init_1042, dt_1023); 
if (((dt_1023) >= (((int64_t)0LL)))) { if (byref_1022) { if ((!(((((*({ hrv *_t3067 = &(g543); int64_t _i3067 = dt_1023; (S1*)_t3067->b + hr_ix(_i3067, _t3067->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:751"); }))).k_) == (((uint8_t)10LL)))))) { (void)(f140_conv(init_1042, dt_1023));
 }
 } else { (void)(f140_conv(init_1042, dt_1023));
 }
 } else { t_1041 = f184_default_t(init_1042);
if (((((*({ hrv *_t3071 = &(g543); int64_t _i3071 = t_1041; (S1*)_t3071->b + hr_ix(_i3071, _t3071->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:754"); }))).k_) == (((uint8_t)14LL)))) { t_1041 = ((int64_t)((*({ hrv *_t3072 = &(g544); int64_t _i3072 = ((*({ hrv *_t3073 = &(g543); int64_t _i3073 = t_1041; (S1*)_t3073->b + hr_ix(_i3073, _t3073->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:754"); }))).l_; (int32_t*)_t3072->b + hr_ix(_i3072, _t3072->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:754"); }))));
 }
if (((((((*({ hrv *_t3074 = &(g543); int64_t _i3074 = t_1041; (S1*)_t3074->b + hr_ix(_i3074, _t3074->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:755"); }))).k_) == (((uint8_t)7LL))) && (((((*({ hrv *_t3075 = &(g696); int64_t _i3075 = init_1042; (S4*)_t3075->b + hr_ix(_i3075, _t3075->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:755"); }))).k_) == (((uint8_t)14LL))) || ((((*({ hrv *_t3076 = &(g696); int64_t _i3076 = init_1042; (S4*)_t3076->b + hr_ix(_i3076, _t3076->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:755"); }))).k_) == (((uint8_t)17LL))))) && ((((int64_t)((int64_t)lf_1024 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL))))) { t_1041 = f136_t_enum(((int64_t)(((*({ hrv *_t3078 = &(g543); int64_t _i3078 = t_1041; (S1*)_t3078->b + hr_ix(_i3078, _t3078->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:755"); }))).a_)), false);
(void)(f142_set_cv(init_1042, t_1041));
 }
if ((byref_1022 || (((((*({ hrv *_t3080 = &(g696); int64_t _i3080 = init_1042; (S4*)_t3080->b + hr_ix(_i3080, _t3080->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:756"); }))).k_) == (((uint8_t)10LL))) && ((((int64_t)(((*({ hrv *_t3081 = &(g696); int64_t _i3081 = init_1042; (S4*)_t3081->b + hr_ix(_i3081, _t3081->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:756"); }))).op_))) == (((int64_t)49LL)))))) { if (((((*({ hrv *_t3082 = &(g543); int64_t _i3082 = t_1041; (S1*)_t3082->b + hr_ix(_i3082, _t3082->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:756"); }))).k_) != (((uint8_t)10LL)))) { t_1041 = f119_t_ref(t_1041, ((int64_t)0LL));
 }
 } else { if ((((((((*({ hrv *_t3084 = &(g543); int64_t _i3084 = t_1041; (S1*)_t3084->b + hr_ix(_i3084, _t3084->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:757"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t3085 = &(g543); int64_t _i3085 = t_1041; (S1*)_t3085->b + hr_ix(_i3085, _t3085->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:757"); }))).c_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t3086 = &(g543); int64_t _i3086 = t_1041; (S1*)_t3086->b + hr_ix(_i3086, _t3086->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:757"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))) && f204_is_fixed(((int64_t)(((*({ hrv *_t3088 = &(g543); int64_t _i3088 = t_1041; (S1*)_t3088->b + hr_ix(_i3088, _t3088->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:757"); }))).a_))))) { t_1041 = ((int64_t)(((*({ hrv *_t3089 = &(g543); int64_t _i3089 = t_1041; (S1*)_t3089->b + hr_ix(_i3089, _t3089->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:757"); }))).a_));
(void)(f142_set_cv(init_1042, t_1041));
 }
 }
 }
 }
 } else { if (((t_1041) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1018, hr_str("a declaration needs a type or an initializer", 44)));
t_1041 = g567;
 }
 }
if ((byref_1022 && ((((*({ hrv *_t3092 = &(g543); int64_t _i3092 = t_1041; (S1*)_t3092->b + hr_ix(_i3092, _t3092->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:763"); }))).k_) != (((uint8_t)10LL))))) { t_1041 = f119_t_ref(t_1041, ((int64_t)0LL));
 }
int64_t v_1045 = f203_add_lv(((int64_t)((*({ hrv *_t3095 = &(g697); int64_t _i3095 = (x_1019).l_; (int32_t*)_t3095->b + hr_ix(_i3095, _t3095->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:764"); })))), t_1041, lf_1024, n_1018); 
(void)(f170_set_r(n_1018, ((int64_t)1LL), v_1045));
}
static int64_t f202_fin_t(int64_t n_1031) {
int64_t c_1032 = f150_cv(n_1031); 
return ({ int64_t _r3098; if (((c_1032) >= (((int64_t)0LL)))) { _r3098 = c_1032;  } else { _r3098 = f141_at(n_1031);  } _r3098; });
}
static int64_t f203_add_lv(int64_t name_1033, int64_t t_1034, int64_t fl_1035, int64_t node_1036) {
(void)(({ hrv *_v3100 = &(g381); S12 _x3100 = ((S12){ .name_ = ((int32_t)(name_1033)), .ty_ = ((int32_t)(t_1034)), .fl_ = ((uint16_t)(fl_1035)), .cfn_ = ((int32_t)(g394)), .own_ = ((int32_t)(g393)), .node_ = ((int32_t)(node_1036)), .cnt_ = ((int32_t)0LL), }); S12 *_p3100 = (S12*)hr_grow(_v3100, 1, sizeof _x3100); *_p3100 = _x3100; _p3100; }));
(void)(({ hrv *_v3101 = &(g382); int32_t _x3101 = ((int32_t)(((int64_t)((int64_t)(g381).n - (int64_t)((int64_t)1LL))))); int32_t *_p3101 = (int32_t*)hr_grow(_v3101, 1, sizeof _x3101); *_p3101 = _x3101; _p3101; }));
return ((int64_t)((int64_t)(g381).n - (int64_t)((int64_t)1LL)));
}
static bool f204_is_fixed(int64_t t_1044) {
return ((f143_tclass(t_1044)) == (((int64_t)0LL)));
}
static void f205_ck_assign(int64_t n_1046) {
S4 x_1047 = (*({ hrv *_t3103 = &(g696); int64_t _i3103 = n_1046; (S4*)_t3103->b + hr_ix(_i3103, _t3103->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:768"); })); 
int64_t o_1048 = ((int64_t)((x_1047).op_)); 
if (((o_1048) == (((int64_t)11LL)))) { int64_t t_1049 = f137_ck(((int64_t)((x_1047).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t tl_1050 = ((int64_t)((x_1047).a_)); 
{ int32_t _e3106 = ((*({ hrv *_t3107 = &(g696); int64_t _i3107 = tl_1050; (S4*)_t3107->b + hr_ix(_i3107, _t3107->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:773"); }))).n_; for (int32_t _k3106 = 0; _k3106 < _e3106; _k3106++) { int32_t i_1051 = (int32_t)_k3106; int64_t tg_1052 = f90_kid(tl_1050, ((int64_t)(i_1051))); 
int64_t tt_1053 = f137_ck(tg_1052, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
 } } _bk3105:; 
return;
 }
if (((o_1048) == (((int64_t)18LL)))) { int64_t tt_1054 = f137_ck(((int64_t)((x_1047).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t rt_1055 = f137_ck(((int64_t)((x_1047).b_)), tt_1054); 
if (f163_is_pending(rt_1055)) { if ((((((*({ hrv *_t3113 = &(g543); int64_t _i3113 = rt_1055; (S1*)_t3113->b + hr_ix(_i3113, _t3113->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:780"); }))).k_) == (((uint8_t)11LL))) && ((((*({ hrv *_t3114 = &(g543); int64_t _i3114 = tt_1054; (S1*)_t3114->b + hr_ix(_i3114, _t3114->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:780"); }))).k_) == (((uint8_t)10LL))))) { (void)(f138_set_t(((int64_t)((x_1047).b_)), f119_t_ref(((int64_t)(((*({ hrv *_t3117 = &(g543); int64_t _i3117 = tt_1054; (S1*)_t3117->b + hr_ix(_i3117, _t3117->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:780"); }))).a_)), ((int64_t)2LL))));
 } else { (void)(f184_default_t(((int64_t)((x_1047).b_))));
 }
 }
if ((((((*({ hrv *_t3119 = &(g696); int64_t _i3119 = (x_1047).a_; (S4*)_t3119->b + hr_ix(_i3119, _t3119->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:783"); }))).k_) == (((uint8_t)8LL))) && ((f156_rk(((int64_t)((x_1047).a_)))) == (((int64_t)1LL))))) { int64_t v_1056 = f157_rv(((int64_t)((x_1047).a_))); 
if ((f165_is_opt(f141_at(((int64_t)((x_1047).b_)))) || ((((*({ hrv *_t3124 = &(g543); int64_t _i3124 = f141_at(((int64_t)((x_1047).b_))); (S1*)_t3124->b + hr_ix(_i3124, _t3124->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:785"); }))).k_) == (((uint8_t)11LL))))) { { int32_t *_t3126 = &(((*({ hrv *_t3127 = &(g381); int64_t _i3127 = v_1056; (S12*)_t3127->b + hr_ix(_i3127, _t3127->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:786"); }))).ty_); *_t3126 = ((int32_t)(f119_t_ref(((int64_t)(((*({ hrv *_t3129 = &(g543); int64_t _i3129 = ((*({ hrv *_t3130 = &(g381); int64_t _i3130 = v_1056; (S12*)_t3130->b + hr_ix(_i3130, _t3130->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:786"); }))).ty_; (S1*)_t3129->b + hr_ix(_i3129, _t3129->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:786"); }))).a_)), ((int64_t)2LL)))); }
 }
 }
return;
 }
int64_t tt_1057 = f137_ck(((int64_t)((x_1047).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t d_1058 = f179_deref(tt_1057); 
if (((o_1048) == (((int64_t)36LL)))) { if ((((((*({ hrv *_t3133 = &(g543); int64_t _i3133 = tt_1057; (S1*)_t3133->b + hr_ix(_i3133, _t3133->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:794"); }))).k_) == (((uint8_t)10LL))) && f165_is_opt(tt_1057))) { int64_t rt_1059 = f137_ck(((int64_t)((x_1047).b_)), tt_1057); 
if (((((*({ hrv *_t3136 = &(g543); int64_t _i3136 = rt_1059; (S1*)_t3136->b + hr_ix(_i3136, _t3136->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:796"); }))).k_) == (((uint8_t)11LL)))) { (void)(f162_commit(((int64_t)((x_1047).b_)), tt_1057));
return;
 }
if (((((*({ hrv *_t3138 = &(g543); int64_t _i3138 = rt_1059; (S1*)_t3138->b + hr_ix(_i3138, _t3138->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:797"); }))).k_) == (((uint8_t)10LL)))) { (void)(f140_conv(((int64_t)((x_1047).b_)), tt_1057));
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
if ((((o_1048) == (((int64_t)45LL))) || ((o_1048) == (((int64_t)46LL))))) { if (f163_is_pending(rt_1061)) { (void)(f140_conv(((int64_t)((x_1047).b_)), g555));
 }
return;
 }
(void)(f140_conv(((int64_t)((x_1047).b_)), d_1058));
}
static void f206_decl_nested(int64_t n_1063) {
int64_t i_1064 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v3152 = &(g310); for (int64_t _k3152 = 0; _k3152 < _v3152->n; _k3152++) { S14 f_1065 = ((S14*)_v3152->b)[_k3152]; if ((((((int64_t)((f_1065).node_))) == (n_1063)) && ((((int64_t)((f_1065).own_))) == (g393)))) { i_1064 = ((int64_t)((f_1065).inst_));
 }
 } } _bk3151:; 
if (((i_1064) < (((int64_t)0LL)))) { i_1064 = f105_new_inst(n_1063, n_1063, ((int64_t)((*({ hrv *_t3154 = &(g711); int64_t _i3154 = n_1063; (int32_t*)_t3154->b + hr_ix(_i3154, _t3154->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:27"); })))), g393);
(void)(({ hrv *_v3155 = &(g310); S14 _x3155 = ((S14){ .name_ = ((*({ hrv *_t3156 = &(g696); int64_t _i3156 = n_1063; (S4*)_t3156->b + hr_ix(_i3156, _t3156->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:27"); }))).s_, .node_ = ((int32_t)(n_1063)), .inst_ = ((int32_t)(i_1064)), .own_ = ((int32_t)(g393)), }); S14 *_p3155 = (S14*)hr_grow(_v3155, 1, sizeof _x3155); *_p3155 = _x3155; _p3155; }));
(void)(f195_sig_inst(i_1064));
 }
(void)(f207_check_inst(i_1064));
}
static void f207_check_inst(int64_t i_1066) {
if (((((*({ hrv *_t3159 = &(g380); int64_t _i3159 = i_1066; (S6*)_t3159->b + hr_ix(_i3159, _t3159->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:146"); }))).st_) != (((uint8_t)0LL)))) { return;
 }
int64_t node_1067 = ((int64_t)(((*({ hrv *_t3160 = &(g380); int64_t _i3160 = i_1066; (S6*)_t3160->b + hr_ix(_i3160, _t3160->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:147"); }))).node_)); 
{ uint8_t *_t3161 = &(((*({ hrv *_t3162 = &(g380); int64_t _i3162 = i_1066; (S6*)_t3162->b + hr_ix(_i3162, _t3162->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:148"); }))).st_); *_t3161 = ((uint8_t)1LL); }
if (((((uint16_t)((uint64_t)((*({ hrv *_t3163 = &(g696); int64_t _i3163 = node_1067; (S4*)_t3163->b + hr_ix(_i3163, _t3163->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:149"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { uint8_t *_t3164 = &(((*({ hrv *_t3165 = &(g380); int64_t _i3165 = i_1066; (S6*)_t3165->b + hr_ix(_i3165, _t3165->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:149"); }))).st_); *_t3164 = ((uint8_t)2LL); }
return;
 }
int64_t sa_1068 = g393; 
int64_t sc_1069 = g394; 
int64_t sm_1070 = (g382).n; 
int64_t ld_1071 = g399; 
int64_t bt_1072 = (g460).n; 
int64_t nm0_1073 = (g310).n; 
g393 = i_1066;
g394 = i_1066;
g399 = ((int64_t)0LL);
int64_t g0_1074 = (g483).n; 
{ int32_t _e3167 = ((*({ hrv *_t3168 = &(g380); int64_t _i3168 = i_1066; (S6*)_t3168->b + hr_ix(_i3168, _t3168->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:153"); }))).gn_; for (int32_t _k3167 = 0; _k3167 < _e3167; _k3167++) { int32_t j_1075 = (int32_t)_k3167; (void)(({ hrv *_v3169 = &(g483); S7 _x3169 = (*({ hrv *_t3170 = &(g386); int64_t _i3170 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3171 = &(g380); int64_t _i3171 = i_1066; (S6*)_t3171->b + hr_ix(_i3171, _t3171->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:153"); }))).g0_)) + (int64_t)((int64_t)(j_1075)))); (S7*)_t3170->b + hr_ix(_i3170, _t3170->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:153"); })); S7 *_p3169 = (S7*)hr_grow(_v3169, 1, sizeof _x3169); *_p3169 = _x3169; _p3169; }));
 } } _bk3166:; 
{ int32_t _e3173 = ((*({ hrv *_t3174 = &(g696); int64_t _i3174 = node_1067; (S4*)_t3174->b + hr_ix(_i3174, _t3174->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:154"); }))).n_; for (int32_t _k3173 = 0; _k3173 < _e3173; _k3173++) { int32_t j_1076 = (int32_t)_k3173; int64_t p_1077 = f90_kid(node_1067, ((int64_t)(j_1076))); 
if (((((*({ hrv *_t3176 = &(g696); int64_t _i3176 = p_1077; (S4*)_t3176->b + hr_ix(_i3176, _t3176->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:154"); }))).b_) >= (((int32_t)0LL)))) { int64_t pt_1080 = f208_ptype_of(i_1066, ((int64_t)(j_1076))); 
(void)(f137_ck(((int64_t)(((*({ hrv *_t3179 = &(g696); int64_t _i3179 = p_1077; (S4*)_t3179->b + hr_ix(_i3179, _t3179->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:154"); }))).b_)), pt_1080));
(void)(f140_conv(((int64_t)(((*({ hrv *_t3181 = &(g696); int64_t _i3181 = p_1077; (S4*)_t3181->b + hr_ix(_i3181, _t3181->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:154"); }))).b_)), pt_1080));
 }
 } } _bk3172:; 
{ int32_t _e3183 = ((*({ hrv *_t3184 = &(g696); int64_t _i3184 = node_1067; (S4*)_t3184->b + hr_ix(_i3184, _t3184->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:155"); }))).n_; for (int32_t _k3183 = 0; _k3183 < _e3183; _k3183++) { int32_t j_1081 = (int32_t)_k3183; int64_t p_1082 = f90_kid(node_1067, ((int64_t)(j_1081))); 
int64_t v_1083 = f203_add_lv(((int64_t)(((*({ hrv *_t3187 = &(g696); int64_t _i3187 = p_1082; (S4*)_t3187->b + hr_ix(_i3187, _t3187->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:155"); }))).s_)), f208_ptype_of(i_1066, ((int64_t)(j_1081))), ((int64_t)((int64_t)((int64_t)4LL) | (int64_t)({ int64_t _r3189; if (((((uint16_t)((uint64_t)((*({ hrv *_t3190 = &(g696); int64_t _i3190 = p_1082; (S4*)_t3190->b + hr_ix(_i3190, _t3190->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:155"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { _r3189 = ((int64_t)1LL);  } else { _r3189 = ((int64_t)0LL);  } _r3189; }))), p_1082); 
(void)(f170_set_r(p_1082, ((int64_t)1LL), v_1083));
 } } _bk3182:; 
int64_t body_1084 = ((int64_t)(((*({ hrv *_t3192 = &(g696); int64_t _i3192 = node_1067; (S4*)_t3192->b + hr_ix(_i3192, _t3192->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:156"); }))).c_)); 
int64_t rt_1085 = ((int64_t)(((*({ hrv *_t3193 = &(g380); int64_t _i3193 = i_1066; (S6*)_t3193->b + hr_ix(_i3193, _t3193->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:157"); }))).ret_)); 
int64_t t_1086 = f137_ck(body_1084, ({ int64_t _r3195; if (((rt_1085) >= (((int64_t)0LL)))) { _r3195 = rt_1085;  } else { _r3195 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3195; })); 
int64_t tail_1087 = ((int64_t)(((*({ hrv *_t3196 = &(g696); int64_t _i3196 = body_1084; (S4*)_t3196->b + hr_ix(_i3196, _t3196->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:159"); }))).a_)); 
if (((rt_1085) >= (((int64_t)0LL)))) { if ((((((tail_1087) >= (((int64_t)0LL))) && ((rt_1085) != (g550))) && ((t_1086) != (g550))) && (!(f209_ends(tail_1087))))) { (void)(f140_conv(tail_1087, rt_1085));
 }
 } else { if (((((*({ hrv *_t3199 = &(g380); int64_t _i3199 = i_1066; (S6*)_t3199->b + hr_ix(_i3199, _t3199->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:162"); }))).ret_) < (((int32_t)0LL)))) { if ((((tail_1087) >= (((int64_t)0LL))) && ((t_1086) != (g550)))) { { int32_t *_t3200 = &(((*({ hrv *_t3201 = &(g380); int64_t _i3201 = i_1066; (S6*)_t3201->b + hr_ix(_i3201, _t3201->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:162"); }))).ret_); *_t3200 = ((int32_t)(f184_default_t(tail_1087))); }
 } else { { int32_t *_t3203 = &(((*({ hrv *_t3204 = &(g380); int64_t _i3204 = i_1066; (S6*)_t3204->b + hr_ix(_i3204, _t3204->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:162"); }))).ret_); *_t3203 = ((int32_t)(g550)); }
 }
 } else { if (((((tail_1087) >= (((int64_t)0LL))) && ((t_1086) != (g550))) && ((((int64_t)(((*({ hrv *_t3205 = &(g380); int64_t _i3205 = i_1066; (S6*)_t3205->b + hr_ix(_i3205, _t3205->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:163"); }))).ret_))) != (g550)))) { (void)(f140_conv(tail_1087, ((int64_t)(((*({ hrv *_t3207 = &(g380); int64_t _i3207 = i_1066; (S6*)_t3207->b + hr_ix(_i3207, _t3207->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:163"); }))).ret_))));
 }
 }
 }
(void)(({ hrv *_v3208 = &(g483); int64_t _k3208 = ((int64_t)((int64_t)(g483).n - (int64_t)g0_1074)); if (_k3208 < 0 || _k3208 > _v3208->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:165"); _v3208->n -= _k3208; }));
(void)(({ hrv *_v3209 = &(g382); int64_t _k3209 = ((int64_t)((int64_t)(g382).n - (int64_t)sm_1070)); if (_k3209 < 0 || _k3209 > _v3209->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:166"); _v3209->n -= _k3209; }));
(void)(({ hrv *_v3210 = &(g310); int64_t _k3210 = ((int64_t)((int64_t)(g310).n - (int64_t)nm0_1073)); if (_k3210 < 0 || _k3210 > _v3210->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:166"); _v3210->n -= _k3210; }));
while ((((g460).n) > (bt_1072))) { (void)(({ hrv *_v3212 = &(g460); if (!_v3212->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:167"); ((int32_t*)_v3212->b)[--_v3212->n]; }));
 } _bk3211:; 
g393 = sa_1068;
g394 = sc_1069;
g399 = ld_1071;
{ uint8_t *_t3213 = &(((*({ hrv *_t3214 = &(g380); int64_t _i3214 = i_1066; (S6*)_t3214->b + hr_ix(_i3214, _t3214->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:169"); }))).st_); *_t3213 = ((uint8_t)2LL); }
}
static int64_t f208_ptype_of(int64_t i_1078, int64_t j_1079) {
return ((int64_t)((*({ hrv *_t3215 = &(g544); int64_t _i3215 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3216 = &(g380); int64_t _i3216 = i_1078; (S6*)_t3216->b + hr_ix(_i3216, _t3216->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:144"); }))).p0_)) + (int64_t)j_1079)); (int32_t*)_t3215->b + hr_ix(_i3215, _t3215->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:144"); }))));
}
static bool f209_ends(int64_t n_1088) {
if (((n_1088) < (((int64_t)0LL)))) { return false;
 }
int64_t k_1089 = ((int64_t)(((*({ hrv *_t3217 = &(g696); int64_t _i3217 = n_1088; (S4*)_t3217->b + hr_ix(_i3217, _t3217->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:490"); }))).k_)); 
if (((((k_1089) == (((int64_t)28LL))) || ((k_1089) == (((int64_t)29LL)))) || ((k_1089) == (((int64_t)30LL))))) { return true;
 }
if ((((k_1089) == (((int64_t)11LL))) && ((((*({ hrv *_t3218 = &(g696); int64_t _i3218 = ((*({ hrv *_t3219 = &(g696); int64_t _i3219 = n_1088; (S4*)_t3219->b + hr_ix(_i3219, _t3219->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:492"); }))).a_; (S4*)_t3218->b + hr_ix(_i3218, _t3218->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:492"); }))).k_) == (((uint8_t)8LL))))) { hsl s_1090 = f10_nm(((int64_t)(((*({ hrv *_t3221 = &(g696); int64_t _i3221 = ((*({ hrv *_t3222 = &(g696); int64_t _i3222 = n_1088; (S4*)_t3222->b + hr_ix(_i3222, _t3222->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:492"); }))).a_; (S4*)_t3221->b + hr_ix(_i3221, _t3221->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:492"); }))).s_))); 
if ((hr_streq(s_1090, hr_str("abort", 5)) || hr_streq(s_1090, hr_str("exit", 4)))) { return true;
 }
 }
if (((k_1089) == (((int64_t)23LL)))) { if (((((*({ hrv *_t3223 = &(g696); int64_t _i3223 = n_1088; (S4*)_t3223->b + hr_ix(_i3223, _t3223->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:493"); }))).a_) >= (((int32_t)0LL)))) { return f209_ends(((int64_t)(((*({ hrv *_t3225 = &(g696); int64_t _i3225 = n_1088; (S4*)_t3225->b + hr_ix(_i3225, _t3225->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:493"); }))).a_)));
 }
if (((((*({ hrv *_t3226 = &(g696); int64_t _i3226 = n_1088; (S4*)_t3226->b + hr_ix(_i3226, _t3226->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:493"); }))).n_) > (((int32_t)0LL)))) { return f209_ends(f90_kid(n_1088, ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3229 = &(g696); int64_t _i3229 = n_1088; (S4*)_t3229->b + hr_ix(_i3229, _t3229->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:493"); }))).n_)) - (int64_t)((int64_t)1LL)))));
 }
return false;
 }
if (((k_1089) == (((int64_t)19LL)))) { return ((((((*({ hrv *_t3230 = &(g696); int64_t _i3230 = n_1088; (S4*)_t3230->b + hr_ix(_i3230, _t3230->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:494"); }))).c_) >= (((int32_t)0LL))) && f209_ends(((int64_t)(((*({ hrv *_t3232 = &(g696); int64_t _i3232 = n_1088; (S4*)_t3232->b + hr_ix(_i3232, _t3232->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:494"); }))).b_)))) && f209_ends(((int64_t)(((*({ hrv *_t3234 = &(g696); int64_t _i3234 = n_1088; (S4*)_t3234->b + hr_ix(_i3234, _t3234->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:494"); }))).c_))));
 }
if (((k_1089) == (((int64_t)26LL)))) { return (!(f210_has_break(((int64_t)(((*({ hrv *_t3236 = &(g696); int64_t _i3236 = n_1088; (S4*)_t3236->b + hr_ix(_i3236, _t3236->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:495"); }))).a_)))));
 }
return false;
}
static bool f210_has_break(int64_t n_1091) {
if (((n_1091) < (((int64_t)0LL)))) { return false;
 }
S4 x_1092 = (*({ hrv *_t3237 = &(g696); int64_t _i3237 = n_1091; (S4*)_t3237->b + hr_ix(_i3237, _t3237->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:500"); })); 
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
if ((((k_1093) == (((int64_t)20LL))) && f210_has_break(((int64_t)(((*({ hrv *_t3253 = &(g696); int64_t _i3253 = c_1096; (S4*)_t3253->b + hr_ix(_i3253, _t3253->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:511"); }))).b_))))) { return true;
 }
 } } _bk3248:; 
 }
return false;
}
static void f211_pop_block_fns(int64_t m_1099) {
if ((((g310).n) > (m_1099))) { (void)(({ hrv *_v3254 = &(g310); int64_t _k3254 = ((int64_t)((int64_t)(g310).n - (int64_t)m_1099)); if (_k3254 < 0 || _k3254 > _v3254->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:35"); _v3254->n -= _k3254; }));
 }
}
static int64_t f212_ck_if(int64_t n_1102, int64_t want_1103) {
S4 x_1104 = (*({ hrv *_t3255 = &(g696); int64_t _i3255 = n_1102; (S4*)_t3255->b + hr_ix(_i3255, _t3255->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:517"); })); 
int64_t c_1105 = f137_ck(((int64_t)((x_1104).a_)), g551); 
(void)(f140_conv(((int64_t)((x_1104).a_)), g551));
int64_t m_1106 = (g382).n; 
int64_t nm0_1107 = (g383).n; 
(void)(f177_narrow_push(((int64_t)((x_1104).a_))));
int64_t tb_1108 = f137_ck(((int64_t)((x_1104).b_)), want_1103); 
(void)(f178_narrow_pop(nm0_1107));
(void)(({ hrv *_v3261 = &(g382); int64_t _k3261 = ((int64_t)((int64_t)(g382).n - (int64_t)m_1106)); if (_k3261 < 0 || _k3261 > _v3261->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:525"); _v3261->n -= _k3261; }));
if ((((x_1104).c_) < (((int32_t)0LL)))) { return f138_set_t(n_1102, g550);
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
if ((((tb_1108) == (g550)) || ((tc_1109) == (g550)))) { return f138_set_t(n_1102, g550);
 }
if (((tb_1108) == (tc_1109))) { return f138_set_t(n_1102, tb_1108);
 }
if ((((((want_1103) >= (((int64_t)0LL))) && ((want_1103) != (g550))) && (f163_is_pending(tb_1108) || f151_conv_ok(tb_1108, want_1103, ((int64_t)((x_1104).b_))))) && (f163_is_pending(tc_1109) || f151_conv_ok(tc_1109, want_1103, ((int64_t)((x_1104).c_)))))) { (void)(f140_conv(((int64_t)((x_1104).b_)), want_1103));
(void)(f140_conv(((int64_t)((x_1104).c_)), want_1103));
return f138_set_t(n_1102, want_1103);
 }
int64_t u_1112 = f182_unify(n_1102, ((int64_t)((x_1104).b_)), ((int64_t)((x_1104).c_))); 
return f138_set_t(n_1102, u_1112);
}
static int64_t f213_ck_while(int64_t n_1113) {
S4 x_1114 = (*({ hrv *_t3280 = &(g696); int64_t _i3280 = n_1113; (S4*)_t3280->b + hr_ix(_i3280, _t3280->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:539"); })); 
int64_t c_1115 = f137_ck(((int64_t)((x_1114).a_)), g551); 
(void)(f140_conv(((int64_t)((x_1114).a_)), g551));
int64_t nm0_1116 = (g383).n; 
(void)(f177_narrow_push(((int64_t)((x_1114).a_))));
g399++;
(void)(f137_ck(((int64_t)((x_1114).b_)), g550));
g399--;
(void)(f178_narrow_pop(nm0_1116));
return f138_set_t(n_1113, g550);
}
static int64_t f214_ck_loop(int64_t n_1117, int64_t want_1118) {
(void)(({ hrv *_v3287 = &(g460); int32_t _x3287 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p3287 = (int32_t*)hr_grow(_v3287, 1, sizeof _x3287); *_p3287 = _x3287; _p3287; }));
g399++;
(void)(f137_ck(((int64_t)(((*({ hrv *_t3289 = &(g696); int64_t _i3289 = n_1117; (S4*)_t3289->b + hr_ix(_i3289, _t3289->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:554"); }))).a_)), g550));
g399--;
int64_t t_1119 = ((int64_t)(({ hrv *_v3290 = &(g460); if (!_v3290->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:556"); ((int32_t*)_v3290->b)[--_v3290->n]; }))); 
return f138_set_t(n_1117, ({ int64_t _r3292; if (((t_1119) < (((int64_t)0LL)))) { _r3292 = g550;  } else { _r3292 = t_1119;  } _r3292; }));
}
static int64_t f215_ck_for(int64_t n_1120) {
S4 x_1121 = (*({ hrv *_t3293 = &(g696); int64_t _i3293 = n_1120; (S4*)_t3293->b + hr_ix(_i3293, _t3293->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:560"); })); 
int64_t m_1122 = (g382).n; 
int64_t et_1123 = g555; 
if ((((x_1121).b_) >= (((int32_t)0LL)))) { int64_t ta_1124 = f137_ck(((int64_t)((x_1121).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t tb_1125 = f137_ck(((int64_t)((x_1121).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t u_1126 = f182_unify(n_1120, ((int64_t)((x_1121).a_)), ((int64_t)((x_1121).b_))); 
et_1123 = ({ int64_t _r3297; if (((((*({ hrv *_t3298 = &(g543); int64_t _i3298 = u_1126; (S1*)_t3298->b + hr_ix(_i3298, _t3298->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:566"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1121).a_)), g555));
(void)(f140_conv(((int64_t)((x_1121).b_)), g555));
_r3297 = g555;  } else { _r3297 = u_1126;  } _r3297; });
(void)(f175_set_x(n_1120, ((int64_t)0LL)));
 } else { int64_t t_1127 = f137_ck(((int64_t)((x_1121).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3303 = &(g543); int64_t _i3303 = t_1127; (S1*)_t3303->b + hr_ix(_i3303, _t3303->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:570"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(((int64_t)((x_1121).a_)), g568));
t_1127 = g568;
 }
if (((((*({ hrv *_t3305 = &(g543); int64_t _i3305 = t_1127; (S1*)_t3305->b + hr_ix(_i3305, _t3305->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:571"); }))).k_) == (((uint8_t)19LL)))) { t_1127 = f184_default_t(((int64_t)((x_1121).a_)));
 }
int64_t d_1128 = f179_deref(t_1127); 
if (((((*({ hrv *_t3308 = &(g543); int64_t _i3308 = d_1128; (S1*)_t3308->b + hr_ix(_i3308, _t3308->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:573"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1121).a_)), g555));
et_1123 = g555;
(void)(f175_set_x(n_1120, ((int64_t)0LL)));
 } else { if ((((((*({ hrv *_t3311 = &(g543); int64_t _i3311 = d_1128; (S1*)_t3311->b + hr_ix(_i3311, _t3311->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:574"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t3312 = &(g543); int64_t _i3312 = d_1128; (S1*)_t3312->b + hr_ix(_i3312, _t3312->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:574"); }))).k_) == (((uint8_t)17LL))))) { et_1123 = ({ int64_t _r3313; if (((((*({ hrv *_t3314 = &(g543); int64_t _i3314 = d_1128; (S1*)_t3314->b + hr_ix(_i3314, _t3314->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:574"); }))).k_) == (((uint8_t)17LL)))) { _r3313 = g555;  } else { _r3313 = d_1128;  } _r3313; });
if (((et_1123) != (t_1127))) { (void)(f142_set_cv(((int64_t)((x_1121).a_)), et_1123));
 }
(void)(f175_set_x(n_1120, ((int64_t)0LL)));
 } else { if ((((((*({ hrv *_t3317 = &(g543); int64_t _i3317 = d_1128; (S1*)_t3317->b + hr_ix(_i3317, _t3317->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:575"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3318 = &(g543); int64_t _i3318 = d_1128; (S1*)_t3318->b + hr_ix(_i3318, _t3318->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:575"); }))).k_) == (((uint8_t)9LL))))) { et_1123 = f188_decode_rel(((int64_t)(((*({ hrv *_t3320 = &(g543); int64_t _i3320 = d_1128; (S1*)_t3320->b + hr_ix(_i3320, _t3320->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:575"); }))).a_)));
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
if ((((x_1121).c_) >= (((int32_t)0LL)))) { int64_t iv_1133 = f203_add_lv(((int64_t)((x_1121).c_)), ({ int64_t _r3336; if ((((x_1121).n_) >= (((int32_t)0LL)))) { _r3336 = f113_rtype(((int64_t)((x_1121).n_)), f110_ns_of(n_1120));  } else { _r3336 = g555;  } _r3336; }), ((int64_t)16LL), n_1120); 
(void)(f175_set_x(n_1120, ((int64_t)((int64_t)f217_ax(n_1120) | (int64_t)((int64_t)((iv_1133) << ((((int64_t)2LL)) & 63)))))));
 }
g399++;
(void)(f137_ck(((int64_t)((x_1121).d_)), g550));
g399--;
(void)(({ hrv *_v3342 = &(g382); int64_t _k3342 = ((int64_t)((int64_t)(g382).n - (int64_t)m_1122)); if (_k3342 < 0 || _k3342 > _v3342->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:586"); _v3342->n -= _k3342; }));
return f138_set_t(n_1120, g550);
}
static bool f216_is_bytes(int64_t t_1130) {
return ((((f143_tclass(t_1130)) == (((int64_t)1LL))) && ((((*({ hrv *_t3345 = &(g543); int64_t _i3345 = t_1130; (S1*)_t3345->b + hr_ix(_i3345, _t3345->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:93"); }))).k_) != (((uint8_t)17LL)))) && ((((*({ hrv *_t3346 = &(g543); int64_t _i3346 = t_1130; (S1*)_t3346->b + hr_ix(_i3346, _t3346->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:93"); }))).k_) != (((uint8_t)10LL))));
}
static int64_t f217_ax(int64_t n_1134) {
return ((int64_t)((*({ hrv *_t3347 = &(g391); int64_t _i3347 = f139_aix(n_1134); (int32_t*)_t3347->b + hr_ix(_i3347, _t3347->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:47"); }))));
}
static int64_t f218_ck_match(int64_t n_1135, int64_t want_1136) {
S4 x_1137 = (*({ hrv *_t3349 = &(g696); int64_t _i3349 = n_1135; (S4*)_t3349->b + hr_ix(_i3349, _t3349->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:590"); })); 
int64_t st_1138 = f137_ck(((int64_t)((x_1137).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3351 = &(g543); int64_t _i3351 = st_1138; (S1*)_t3351->b + hr_ix(_i3351, _t3351->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:592"); }))).k_) == (((uint8_t)12LL)))) { (void)(f140_conv(((int64_t)((x_1137).a_)), g555));
st_1138 = g555;
 }
if (((((*({ hrv *_t3353 = &(g543); int64_t _i3353 = st_1138; (S1*)_t3353->b + hr_ix(_i3353, _t3353->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:593"); }))).k_) == (((uint8_t)7LL)))) { st_1138 = f136_t_enum(((int64_t)(((*({ hrv *_t3355 = &(g543); int64_t _i3355 = st_1138; (S1*)_t3355->b + hr_ix(_i3355, _t3355->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:593"); }))).a_)), false);
(void)(f142_set_cv(((int64_t)((x_1137).a_)), st_1138));
 }
int64_t d_1139 = f179_deref(st_1138); 
int64_t rt_1140 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
bool allv_1141 = true; 
{ int32_t _e3359 = (x_1137).n_; for (int32_t _k3359 = 0; _k3359 < _e3359; _k3359++) { int32_t i_1142 = (int32_t)_k3359; int64_t arm_1143 = f90_kid(n_1135, ((int64_t)(i_1142))); 
int64_t m_1144 = (g382).n; 
S4 ax0_1145 = (*({ hrv *_t3361 = &(g696); int64_t _i3361 = arm_1143; (S4*)_t3361->b + hr_ix(_i3361, _t3361->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:600"); })); 
if (((((uint16_t)((uint64_t)(ax0_1145).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) { { int32_t _e3363 = (ax0_1145).n_; for (int32_t _k3363 = 0; _k3363 < _e3363; _k3363++) { int32_t j_1146 = (int32_t)_k3363; int64_t it_1147 = f90_kid(arm_1143, ((int64_t)(j_1146))); 
int64_t lo_1148 = ((int64_t)(((*({ hrv *_t3365 = &(g696); int64_t _i3365 = it_1147; (S4*)_t3365->b + hr_ix(_i3365, _t3365->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:604"); }))).a_)); 
if ((((((*({ hrv *_t3366 = &(g543); int64_t _i3366 = d_1139; (S1*)_t3366->b + hr_ix(_i3366, _t3366->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:605"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t3367 = &(g696); int64_t _i3367 = lo_1148; (S4*)_t3367->b + hr_ix(_i3367, _t3367->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:605"); }))).k_) == (((uint8_t)8LL))))) { int64_t ei_1149 = ((int64_t)(((*({ hrv *_t3368 = &(g543); int64_t _i3368 = d_1139; (S1*)_t3368->b + hr_ix(_i3368, _t3368->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:606"); }))).a_)); 
int64_t found_1150 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e3370 = ((*({ hrv *_t3371 = &(g548); int64_t _i3371 = ei_1149; (S8*)_t3371->b + hr_ix(_i3371, _t3371->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:608"); }))).vnum_; for (int32_t _k3370 = 0; _k3370 < _e3370; _k3370++) { int32_t q_1151 = (int32_t)_k3370; if (((((*({ hrv *_t3372 = &(g549); int64_t _i3372 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3373 = &(g548); int64_t _i3373 = ei_1149; (S8*)_t3373->b + hr_ix(_i3373, _t3373->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:608"); }))).v0_)) + (int64_t)((int64_t)(q_1151)))); (S9*)_t3372->b + hr_ix(_i3372, _t3372->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:608"); }))).name_) == (((*({ hrv *_t3374 = &(g696); int64_t _i3374 = lo_1148; (S4*)_t3374->b + hr_ix(_i3374, _t3374->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:608"); }))).s_))) { found_1150 = ((int64_t)(q_1151));
 }
 } } _bk3369:; 
if (((found_1150) < (((int64_t)0LL)))) { hrv mm_1152 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t3379 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o3376 = &(mm_1152); hr_fs(_o3376, hr_str("no variant ", 11)); hr_fs(_o3376, f10_nm(((int64_t)(((*({ hrv *_t3378 = &(g696); int64_t _i3378 = lo_1148; (S4*)_t3378->b + hr_ix(_i3378, _t3378->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:609"); }))).s_)))); hr_fs(_o3376, hr_str(" in ", 4)); hr_fs(_o3376, hr_sl(*hr_tmp(&_t3379, f161_tn(d_1139)))); }));
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
if (((((*({ hrv *_t3393 = &(g696); int64_t _i3393 = it_1147; (S4*)_t3393->b + hr_ix(_i3393, _t3393->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:614"); }))).b_) >= (((int32_t)0LL)))) { (void)(f137_ck(((int64_t)(((*({ hrv *_t3395 = &(g696); int64_t _i3395 = it_1147; (S4*)_t3395->b + hr_ix(_i3395, _t3395->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:614"); }))).b_)), d_1139));
(void)(f140_conv(((int64_t)(((*({ hrv *_t3397 = &(g696); int64_t _i3397 = it_1147; (S4*)_t3397->b + hr_ix(_i3397, _t3397->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:614"); }))).b_)), d_1139));
 }
 }
 } } _bk3362:; 
 }
int64_t bt_1156 = f137_ck(((int64_t)((ax0_1145).b_)), want_1136); 
(void)(({ hrv *_v3399 = &(g382); int64_t _k3399 = ((int64_t)((int64_t)(g382).n - (int64_t)m_1144)); if (_k3399 < 0 || _k3399 > _v3399->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:619"); _v3399->n -= _k3399; }));
if (((bt_1156) == (g550))) { allv_1141 = false;
 } else { if ((!(f209_ends(((int64_t)((ax0_1145).b_)))))) { if ((((rt_1140) < (((int64_t)0LL))) || f163_is_pending(rt_1140))) { rt_1140 = bt_1156;
 }
 }
 }
 } } _bk3358:; 
if (((!(allv_1141)) || ((rt_1140) < (((int64_t)0LL))))) { return f138_set_t(n_1135, g550);
 }
bool allw_1157 = (((want_1136) >= (((int64_t)0LL))) && ((want_1136) != (g550))); 
if (allw_1157) { { int32_t _e3404 = (x_1137).n_; for (int32_t _k3404 = 0; _k3404 < _e3404; _k3404++) { int32_t i_1158 = (int32_t)_k3404; int64_t b_1159 = ((int64_t)(((*({ hrv *_t3405 = &(g696); int64_t _i3405 = f90_kid(n_1135, ((int64_t)(i_1158))); (S4*)_t3405->b + hr_ix(_i3405, _t3405->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:624"); }))).b_)); 
int64_t bt_1160 = f141_at(b_1159); 
if ((((!(f209_ends(b_1159))) && (!(f163_is_pending(bt_1160)))) && (!(f151_conv_ok(bt_1160, want_1136, b_1159))))) { allw_1157 = false;
 }
 } } _bk3403:; 
 }
if (allw_1157) { { int32_t _e3412 = (x_1137).n_; for (int32_t _k3412 = 0; _k3412 < _e3412; _k3412++) { int32_t i_1161 = (int32_t)_k3412; int64_t b_1162 = ((int64_t)(((*({ hrv *_t3413 = &(g696); int64_t _i3413 = f90_kid(n_1135, ((int64_t)(i_1161))); (S4*)_t3413->b + hr_ix(_i3413, _t3413->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:625"); }))).b_)); 
if ((!(f209_ends(b_1162)))) { (void)(f140_conv(b_1162, want_1136));
 }
 } } _bk3411:; 
return f138_set_t(n_1135, want_1136);
 }
if (f163_is_pending(rt_1140)) { { int32_t _e3420 = (x_1137).n_; for (int32_t _k3420 = 0; _k3420 < _e3420; _k3420++) { int32_t i_1163 = (int32_t)_k3420; int64_t b_1164 = ((int64_t)(((*({ hrv *_t3421 = &(g696); int64_t _i3421 = f90_kid(n_1135, ((int64_t)(i_1163))); (S4*)_t3421->b + hr_ix(_i3421, _t3421->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:626"); }))).b_)); 
int64_t bt_1165 = f141_at(b_1164); 
if (((!(f163_is_pending(bt_1165))) && (!(f209_ends(b_1164))))) { rt_1140 = bt_1165;
 }
 } } _bk3419:; 
 }
if (f163_is_pending(rt_1140)) { int64_t b_1166 = ((int64_t)(((*({ hrv *_t3427 = &(g696); int64_t _i3427 = f90_kid(n_1135, ((int64_t)0LL)); (S4*)_t3427->b + hr_ix(_i3427, _t3427->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:627"); }))).b_)); 
rt_1140 = f184_default_t(b_1166);
 }
{ int32_t _e3431 = (x_1137).n_; for (int32_t _k3431 = 0; _k3431 < _e3431; _k3431++) { int32_t i_1167 = (int32_t)_k3431; int64_t b_1168 = ((int64_t)(((*({ hrv *_t3432 = &(g696); int64_t _i3432 = f90_kid(n_1135, ((int64_t)(i_1167))); (S4*)_t3432->b + hr_ix(_i3432, _t3432->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:628"); }))).b_)); 
if ((!(f209_ends(b_1168)))) { (void)(f140_conv(b_1168, rt_1140));
 }
 } } _bk3430:; 
return f138_set_t(n_1135, rt_1140);
}
static int64_t f219_ck_ret(int64_t n_1169) {
S4 x_1170 = (*({ hrv *_t3437 = &(g696); int64_t _i3437 = n_1169; (S4*)_t3437->b + hr_ix(_i3437, _t3437->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:640"); })); 
int64_t f_1174 = ({ int64_t _r3438; if ((((x_1170).s_) >= (((int32_t)0LL)))) { _r3438 = f220_find_from_fn(((int64_t)((x_1170).s_)));  } else { _r3438 = f221_ret_fn();  } _r3438; }); 
if (((f_1174) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1169, hr_str("return outside a function", 25)));
return g550;
 }
if (((f_1174) != (g394))) { { bool *_t3442 = &(((*({ hrv *_t3443 = &(g380); int64_t _i3443 = g394; (S6*)_t3443->b + hr_ix(_i3443, _t3443->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:643"); }))).lr_); *_t3442 = true; }
{ bool *_t3444 = &(((*({ hrv *_t3445 = &(g380); int64_t _i3445 = f_1174; (S6*)_t3445->b + hr_ix(_i3445, _t3445->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:643"); }))).tg_); *_t3444 = true; }
(void)(f175_set_x(n_1169, f_1174));
 } else { (void)(f175_set_x(n_1169, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
int64_t rt_1175 = ((int64_t)(((*({ hrv *_t3448 = &(g380); int64_t _i3448 = f_1174; (S6*)_t3448->b + hr_ix(_i3448, _t3448->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:644"); }))).ret_)); 
if ((((x_1170).n_) == (((int32_t)0LL)))) { if (((((rt_1175) >= (((int64_t)0LL))) && ((rt_1175) != (g550))) && (!(((*({ hrv *_t3449 = &(g380); int64_t _i3449 = f_1174; (S6*)_t3449->b + hr_ix(_i3449, _t3449->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:645"); }))).rinf_)))) { (void)(f108_cerr(n_1169, hr_str("return needs a value", 20)));
 }
if (((rt_1175) < (((int64_t)0LL)))) { { int32_t *_t3451 = &(((*({ hrv *_t3452 = &(g380); int64_t _i3452 = f_1174; (S6*)_t3452->b + hr_ix(_i3452, _t3452->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:645"); }))).ret_); *_t3451 = ((int32_t)(g550)); }
 }
return f138_set_t(n_1169, g550);
 }
if (((((rt_1175) >= (((int64_t)0LL))) && ((((*({ hrv *_t3454 = &(g543); int64_t _i3454 = rt_1175; (S1*)_t3454->b + hr_ix(_i3454, _t3454->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:646"); }))).k_) == (((uint8_t)14LL)))) && (((x_1170).n_) == (((int32_t)1LL))))) { int64_t c_1176 = f90_kid(n_1169, ((int64_t)0LL)); 
(void)(f137_ck(c_1176, rt_1175));
return f138_set_t(n_1169, g550);
 }
if ((((x_1170).n_) > (((int32_t)1LL)))) { if (((rt_1175) < (((int64_t)0LL)))) { L89 ts_1177 = ({ L89 _t3458; memset(&_t3458, 0, sizeof _t3458); _t3458.n = 0; _t3458; }); 
{ int32_t _e3460 = (x_1170).n_; for (int32_t _k3460 = 0; _k3460 < _e3460; _k3460++) { int32_t i_1178 = (int32_t)_k3460; (void)(f137_ck(f90_kid(n_1169, ((int64_t)(i_1178))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
int64_t dt0_1179 = f184_default_t(f90_kid(n_1169, ((int64_t)(i_1178)))); 
(void)(({ L89 *_v3465 = &(ts_1177); int32_t _x3465 = ((int32_t)(dt0_1179)); if (_v3465->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:648"); _v3465->e[_v3465->n] = _x3465; &_v3465->e[_v3465->n++]; }));
 } } _bk3459:; 
{ int32_t *_t3466 = &(((*({ hrv *_t3467 = &(g380); int64_t _i3467 = f_1174; (S6*)_t3467->b + hr_ix(_i3467, _t3467->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:648"); }))).ret_); *_t3466 = ((int32_t)(f197_tlist(((int64_t)14LL), ({ hsl _t3469 = ({ L89 *_t3470 = &(ts_1177); (hsl){ (uint8_t*)_t3470->e, _t3470->n }; }); int64_t _l3469 = 0, _h3469 = _t3469.n; if (_l3469 < 0 || _h3469 < _l3469 || _h3469 > _t3469.n) hr_slerr(_l3469, _h3469, _t3469.n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:648"); (hsl){ _t3469.p + _l3469 * (int64_t)sizeof(int32_t), _h3469 - _l3469 }; }), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); }
return f138_set_t(n_1169, g550);
 }
{ int32_t _e3473 = (x_1170).n_; for (int32_t _k3473 = 0; _k3473 < _e3473; _k3473++) { int32_t i_1180 = (int32_t)_k3473; int64_t et_1181 = ({ int64_t _r3474; if ((((((*({ hrv *_t3475 = &(g543); int64_t _i3475 = rt_1175; (S1*)_t3475->b + hr_ix(_i3475, _t3475->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:649"); }))).k_) == (((uint8_t)14LL))) && ((((int64_t)(i_1180))) < (((int64_t)(((*({ hrv *_t3476 = &(g543); int64_t _i3476 = rt_1175; (S1*)_t3476->b + hr_ix(_i3476, _t3476->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:649"); }))).n_)))))) { _r3474 = ((int64_t)((*({ hrv *_t3477 = &(g544); int64_t _i3477 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t3478 = &(g543); int64_t _i3478 = rt_1175; (S1*)_t3478->b + hr_ix(_i3478, _t3478->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:649"); }))).l_)) + (int64_t)((int64_t)(i_1180)))); (int32_t*)_t3477->b + hr_ix(_i3477, _t3477->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:649"); }))));  } else { _r3474 = g567;  } _r3474; }); 
(void)(f137_ck(f90_kid(n_1169, ((int64_t)(i_1180))), et_1181));
(void)(f140_conv(f90_kid(n_1169, ((int64_t)(i_1180))), et_1181));
 } } _bk3472:; 
return f138_set_t(n_1169, g550);
 }
int64_t c_1182 = f90_kid(n_1169, ((int64_t)0LL)); 
if (((rt_1175) < (((int64_t)0LL)))) { (void)(f137_ck(c_1182, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
int64_t t_1183 = f184_default_t(c_1182); 
{ int32_t *_t3487 = &(((*({ hrv *_t3488 = &(g380); int64_t _i3488 = f_1174; (S6*)_t3488->b + hr_ix(_i3488, _t3488->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:653"); }))).ret_); *_t3487 = ((int32_t)(t_1183)); }
return f138_set_t(n_1169, g550);
 }
(void)(f137_ck(c_1182, rt_1175));
(void)(f140_conv(c_1182, rt_1175));
return f138_set_t(n_1169, g550);
}
static int64_t f220_find_from_fn(int64_t name_1171) {
int64_t i_1172 = g393; 
while (((i_1172) >= (((int64_t)0LL)))) { if (((((((*({ hrv *_t3494 = &(g380); int64_t _i3494 = i_1172; (S6*)_t3494->b + hr_ix(_i3494, _t3494->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:634"); }))).node_) >= (((int32_t)0LL))) && ((((*({ hrv *_t3495 = &(g696); int64_t _i3495 = ((*({ hrv *_t3496 = &(g380); int64_t _i3496 = i_1172; (S6*)_t3496->b + hr_ix(_i3496, _t3496->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:634"); }))).node_; (S4*)_t3495->b + hr_ix(_i3495, _t3495->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:634"); }))).k_) == (((uint8_t)50LL)))) && ((((int64_t)(((*({ hrv *_t3497 = &(g380); int64_t _i3497 = i_1172; (S6*)_t3497->b + hr_ix(_i3497, _t3497->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:634"); }))).name_))) == (name_1171)))) { return i_1172;
 }
i_1172 = ({ int64_t _r3498; if (((((*({ hrv *_t3499 = &(g380); int64_t _i3499 = i_1172; (S6*)_t3499->b + hr_ix(_i3499, _t3499->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:635"); }))).bown_) >= (((int32_t)0LL)))) { _r3498 = ((int64_t)(((*({ hrv *_t3500 = &(g380); int64_t _i3500 = i_1172; (S6*)_t3500->b + hr_ix(_i3500, _t3500->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:635"); }))).bown_));  } else { _r3498 = ((int64_t)(((*({ hrv *_t3501 = &(g380); int64_t _i3501 = i_1172; (S6*)_t3501->b + hr_ix(_i3501, _t3501->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:635"); }))).par_));  } _r3498; });
 } _bk3493:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f221_ret_fn(void) {
int64_t i_1173 = g393; 
while (((i_1173) >= (((int64_t)0LL)))) { if ((((((*({ hrv *_t3503 = &(g380); int64_t _i3503 = i_1173; (S6*)_t3503->b + hr_ix(_i3503, _t3503->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:657"); }))).node_) >= (((int32_t)0LL))) && ((((*({ hrv *_t3504 = &(g696); int64_t _i3504 = ((*({ hrv *_t3505 = &(g380); int64_t _i3505 = i_1173; (S6*)_t3505->b + hr_ix(_i3505, _t3505->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:657"); }))).node_; (S4*)_t3504->b + hr_ix(_i3504, _t3504->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:657"); }))).k_) == (((uint8_t)50LL))))) { return i_1173;
 }
i_1173 = ((int64_t)(((*({ hrv *_t3506 = &(g380); int64_t _i3506 = i_1173; (S6*)_t3506->b + hr_ix(_i3506, _t3506->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:657"); }))).par_));
 } _bk3502:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f222_ck_break(int64_t n_1184) {
S4 x_1185 = (*({ hrv *_t3507 = &(g696); int64_t _i3507 = n_1184; (S4*)_t3507->b + hr_ix(_i3507, _t3507->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:659"); })); 
if ((((x_1185).a_) >= (((int32_t)0LL)))) { if ((((g460).n) == (((int64_t)0LL)))) { (void)(f108_cerr(n_1184, hr_str("break with a value outside loop or block", 40)));
return g550;
 }
int64_t w_1186 = ((int64_t)((*({ hrv *_t3509 = &(g460); int64_t _i3509 = ((int64_t)((int64_t)(g460).n - (int64_t)((int64_t)1LL))); (int32_t*)_t3509->b + hr_ix(_i3509, _t3509->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:662"); })))); 
int64_t t_1187 = f137_ck(((int64_t)((x_1185).a_)), ({ int64_t _r3511; if (((w_1186) >= (((int64_t)0LL)))) { _r3511 = w_1186;  } else { _r3511 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r3511; })); 
if (((w_1186) < (((int64_t)0LL)))) { { int32_t *_t3512 = &((*({ hrv *_t3513 = &(g460); int64_t _i3513 = ((int64_t)((int64_t)(g460).n - (int64_t)((int64_t)1LL))); (int32_t*)_t3513->b + hr_ix(_i3513, _t3513->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:664"); }))); *_t3512 = ((int32_t)(f184_default_t(((int64_t)((x_1185).a_))))); }
 } else { (void)(f140_conv(((int64_t)((x_1185).a_)), w_1186));
 }
 }
return f138_set_t(n_1184, g550);
}
static int64_t f223_ck_call(int64_t n_1188, int64_t want_1189) {
S4 x_1190 = (*({ hrv *_t3517 = &(g696); int64_t _i3517 = n_1188; (S4*)_t3517->b + hr_ix(_i3517, _t3517->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:256"); })); 
int64_t cal_1191 = ((int64_t)((x_1190).a_)); 
int64_t ck__1192 = ((int64_t)(((*({ hrv *_t3518 = &(g696); int64_t _i3518 = cal_1191; (S4*)_t3518->b + hr_ix(_i3518, _t3518->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:258"); }))).k_)); 
if (((ck__1192) == (((int64_t)8LL)))) { int64_t name_1193 = ((int64_t)(((*({ hrv *_t3519 = &(g696); int64_t _i3519 = cal_1191; (S4*)_t3519->b + hr_ix(_i3519, _t3519->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:260"); }))).s_)); 
int64_t v_1194 = f167_find_lv(name_1193); 
int64_t nf_1197 = f224_find_nest(name_1193); 
if ((((v_1194) < (((int64_t)0LL))) && ((nf_1197) >= (((int64_t)0LL))))) { return f225_call_nested(n_1188, nf_1197);
 }
if (((v_1194) < (((int64_t)0LL)))) { int64_t bg_1234 = f230_block_binding(name_1193); 
if (((bg_1234) >= (((int64_t)0LL)))) { return f235_call_block(n_1188, bg_1234);
 }
int64_t b_1264 = f237_builtin_of(f10_nm(name_1193)); 
if (((((b_1264) >= (((int64_t)0LL))) && (!((((b_1264) == (((int64_t)3LL))) && f238_user_format(n_1188))))) && (!((((b_1264) == (((int64_t)9LL))) && false))))) { return f241_ck_builtin(n_1188, b_1264, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), want_1189);
 }
return f243_call_fn(n_1188, name_1193, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), want_1189);
 }
 }
if (((ck__1192) == (((int64_t)14LL)))) { int64_t obj_1422 = ((int64_t)(((*({ hrv *_t3530 = &(g696); int64_t _i3530 = cal_1191; (S4*)_t3530->b + hr_ix(_i3530, _t3530->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:273"); }))).a_)); 
int64_t name_1423 = ((int64_t)(((*({ hrv *_t3531 = &(g696); int64_t _i3531 = cal_1191; (S4*)_t3531->b + hr_ix(_i3531, _t3531->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:274"); }))).s_)); 
if ((((((((*({ hrv *_t3532 = &(g696); int64_t _i3532 = obj_1422; (S4*)_t3532->b + hr_ix(_i3532, _t3532->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:275"); }))).k_) == (((uint8_t)8LL))) && ((f167_find_lv(((int64_t)(((*({ hrv *_t3534 = &(g696); int64_t _i3534 = obj_1422; (S4*)_t3534->b + hr_ix(_i3534, _t3534->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:275"); }))).s_)))) < (((int64_t)0LL)))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t3536 = &(g696); int64_t _i3536 = obj_1422; (S4*)_t3536->b + hr_ix(_i3536, _t3536->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:275"); }))).s_)), f110_ns_of(obj_1422), ((int64_t)2LL))) >= (((int64_t)0LL)))) && ((f116_lookup_q(((int64_t)(((*({ hrv *_t3539 = &(g696); int64_t _i3539 = obj_1422; (S4*)_t3539->b + hr_ix(_i3539, _t3539->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:275"); }))).s_)), f110_ns_of(obj_1422), ((int64_t)5LL))) < (((int64_t)0LL))))) { (void)(f108_cerr(n_1188, hr_str("a variant is constructed with { }", 33)));
return f138_set_t(n_1188, g567);
 }
int64_t ot_1424 = f137_ck(obj_1422, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t3544 = &(g543); int64_t _i3544 = ot_1424; (S1*)_t3544->b + hr_ix(_i3544, _t3544->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:277"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(obj_1422, g568));
ot_1424 = g568;
 }
int64_t d_1425 = f179_deref(ot_1424); 
int64_t mb_1427 = f252_member_of(f10_nm(name_1423)); 
if ((((mb_1427) >= (((int64_t)0LL))) && (((((*({ hrv *_t3549 = &(g543); int64_t _i3549 = d_1425; (S1*)_t3549->b + hr_ix(_i3549, _t3549->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:280"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3550 = &(g543); int64_t _i3550 = d_1425; (S1*)_t3550->b + hr_ix(_i3550, _t3550->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:280"); }))).k_) == (((uint8_t)9LL)))))) { return f241_ck_builtin(n_1188, mb_1427, obj_1422, want_1189);
 }
if (((((((*({ hrv *_t3552 = &(g543); int64_t _i3552 = ot_1424; (S1*)_t3552->b + hr_ix(_i3552, _t3552->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:281"); }))).k_) == (((uint8_t)19LL))) || ((((*({ hrv *_t3553 = &(g543); int64_t _i3553 = ot_1424; (S1*)_t3553->b + hr_ix(_i3553, _t3553->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:281"); }))).k_) == (((uint8_t)12LL)))) || ((((*({ hrv *_t3554 = &(g543); int64_t _i3554 = ot_1424; (S1*)_t3554->b + hr_ix(_i3554, _t3554->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:281"); }))).k_) == (((uint8_t)13LL))))) { (void)(f184_default_t(obj_1422));
 }
int64_t b_1428 = f237_builtin_of(f10_nm(name_1423)); 
if ((((((b_1428) == (((int64_t)3LL))) || ((b_1428) == (((int64_t)30LL)))) || ((b_1428) == (((int64_t)31LL)))) || ((b_1428) == (((int64_t)7LL))))) { return f241_ck_builtin(n_1188, b_1428, obj_1422, want_1189);
 }
(void)(f175_set_x(n_1188, ((int64_t)1LL)));
return f243_call_fn(n_1188, name_1423, obj_1422, want_1189);
 }
(void)(f108_cerr(n_1188, hr_str("this call's callee is not supported yet", 39)));
return f138_set_t(n_1188, g567);
}
static int64_t f224_find_nest(int64_t name_1195) {
int64_t i_1196 = ((int64_t)((int64_t)(g310).n - (int64_t)((int64_t)1LL))); 
while (((i_1196) >= (((int64_t)0LL)))) { if ((((((int64_t)(((*({ hrv *_t3564 = &(g310); int64_t _i3564 = i_1196; (S14*)_t3564->b + hr_ix(_i3564, _t3564->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:23"); }))).name_))) == (name_1195)) && f168_visible(((int64_t)(((*({ hrv *_t3566 = &(g310); int64_t _i3566 = i_1196; (S14*)_t3566->b + hr_ix(_i3566, _t3566->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:23"); }))).own_))))) { return i_1196;
 }
i_1196--;
 } _bk3563:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f225_call_nested(int64_t n_1198, int64_t nf_1199) {
int64_t i_1200 = ((int64_t)(((*({ hrv *_t3567 = &(g310); int64_t _i3567 = nf_1199; (S14*)_t3567->b + hr_ix(_i3567, _t3567->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:332"); }))).inst_)); 
int64_t s_1207 = f226_ck_args(n_1198, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
{ int32_t _e3570 = ((*({ hrv *_t3571 = &(g696); int64_t _i3571 = n_1198; (S4*)_t3571->b + hr_ix(_i3571, _t3571->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:334"); }))).n_; for (int32_t _k3570 = 0; _k3570 < _e3570; _k3570++) { int32_t j_1208 = (int32_t)_k3570; int64_t c_1209 = f90_kid(n_1198, ((int64_t)(j_1208))); 
if (((((int64_t)(j_1208))) < (((int64_t)(((*({ hrv *_t3573 = &(g380); int64_t _i3573 = i_1200; (S6*)_t3573->b + hr_ix(_i3573, _t3573->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:334"); }))).pn_))))) { (void)(f140_conv(c_1209, f208_ptype_of(i_1200, ((int64_t)(j_1208)))));
 }
 } } _bk3569:; 
(void)(f227_pop_args(s_1207));
(void)(f228_note_caps_of(i_1200));
(void)(f229_note_edge(i_1200));
(void)(f170_set_r(n_1198, ((int64_t)3LL), i_1200));
return f138_set_t(n_1198, ({ int64_t _r3581; if (((((*({ hrv *_t3582 = &(g380); int64_t _i3582 = i_1200; (S6*)_t3582->b + hr_ix(_i3582, _t3582->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:338"); }))).ret_) >= (((int32_t)0LL)))) { _r3581 = ((int64_t)(((*({ hrv *_t3583 = &(g380); int64_t _i3583 = i_1200; (S6*)_t3583->b + hr_ix(_i3583, _t3583->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:338"); }))).ret_));  } else { _r3581 = g550;  } _r3581; }));
}
static int64_t f226_ck_args(int64_t n_1201, int64_t a0n_1202, int64_t first_1203) {
int64_t start_1204 = (g400).n; 
if (((first_1203) >= (((int64_t)0LL)))) { (void)(({ hrv *_v3584 = &(g400); int32_t _x3584 = ((int32_t)(f141_at(first_1203))); int32_t *_p3584 = (int32_t*)hr_grow(_v3584, 1, sizeof _x3584); *_p3584 = _x3584; _p3584; }));
(void)(({ hrv *_v3586 = &(g314); int32_t _x3586 = ((int32_t)(first_1203)); int32_t *_p3586 = (int32_t*)hr_grow(_v3586, 1, sizeof _x3586); *_p3586 = _x3586; _p3586; }));
 }
{ int32_t _e3588 = ((*({ hrv *_t3589 = &(g696); int64_t _i3589 = n_1201; (S4*)_t3589->b + hr_ix(_i3589, _t3589->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:251"); }))).n_; for (int32_t _k3588 = 0; _k3588 < _e3588; _k3588++) { int32_t i_1205 = (int32_t)_k3588; int64_t c_1206 = f90_kid(n_1201, ((int64_t)(i_1205))); 
(void)(({ hrv *_v3591 = &(g400); int32_t _x3591 = ((int32_t)(f137_ck(c_1206, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p3591 = (int32_t*)hr_grow(_v3591, 1, sizeof _x3591); *_p3591 = _x3591; _p3591; }));
(void)(({ hrv *_v3593 = &(g314); int32_t _x3593 = ((int32_t)(c_1206)); int32_t *_p3593 = (int32_t*)hr_grow(_v3593, 1, sizeof _x3593); *_p3593 = _x3593; _p3593; }));
 } } _bk3587:; 
return start_1204;
}
static void f227_pop_args(int64_t s_1210) {
(void)(({ hrv *_v3594 = &(g400); int64_t _k3594 = ((int64_t)((int64_t)(g400).n - (int64_t)s_1210)); if (_k3594 < 0 || _k3594 > _v3594->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:254"); _v3594->n -= _k3594; }));
(void)(({ hrv *_v3595 = &(g314); int64_t _k3595 = ((int64_t)((int64_t)(g314).n - (int64_t)s_1210)); if (_k3595 < 0 || _k3595 > _v3595->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:254"); _v3595->n -= _k3595; }));
}
static void f228_note_caps_of(int64_t i_1211) {
{ hrv *_v3597 = &(g384); for (int64_t _k3597 = 0; _k3597 < _v3597->n; _k3597++) { S13 c_1212 = ((S13*)_v3597->b)[_k3597]; if (((((int64_t)((c_1212).inst_))) == (i_1211))) { int64_t v_1213 = ((int64_t)((c_1212).lv_)); 
if (((((int64_t)(((*({ hrv *_t3598 = &(g381); int64_t _i3598 = v_1213; (S12*)_t3598->b + hr_ix(_i3598, _t3598->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:341"); }))).cfn_))) != (g394))) { (void)(f171_note_cap(v_1213));
 }
 }
 } } _bk3596:; 
}
static void f229_note_edge(int64_t callee_1214) {
if (((((g394) < (((int64_t)0LL))) || ((callee_1214) < (((int64_t)0LL)))) || ((g394) == (callee_1214)))) { return;
 }
{ hrv *_v3601 = &(g385); for (int64_t _k3601 = 0; _k3601 < _v3601->n; _k3601++) { S15 e_1215 = ((S15*)_v3601->b)[_k3601]; if ((((((int64_t)((e_1215).caller_))) == (g394)) && ((((int64_t)((e_1215).callee_))) == (callee_1214)))) { return;
 }
 } } _bk3600:; 
(void)(({ hrv *_v3602 = &(g385); S15 _x3602 = ((S15){ .caller_ = ((int32_t)(g394)), .callee_ = ((int32_t)(callee_1214)), }); S15 *_p3602 = (S15*)hr_grow(_v3602, 1, sizeof _x3602); *_p3602 = _x3602; _p3602; }));
}
static int64_t f230_block_binding(int64_t name_1216) {
int64_t i_1217 = g393; 
while (((i_1217) >= (((int64_t)0LL)))) { S6 f_1218 = (*({ hrv *_t3604 = &(g380); int64_t _i3604 = i_1217; (S6*)_t3604->b + hr_ix(_i3604, _t3604->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:294"); })); 
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
{ int32_t _e3608 = ((*({ hrv *_t3609 = &(g696); int64_t _i3609 = gl_1222; (S4*)_t3609->b + hr_ix(_i3609, _t3609->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:59"); }))).n_; for (int32_t _k3608 = 0; _k3608 < _e3608; _k3608++) { int32_t i_1223 = (int32_t)_k3608; int64_t g_1224 = ((int64_t)(((*({ hrv *_t3610 = &(g696); int64_t _i3610 = f90_kid(gl_1222, ((int64_t)(i_1223))); (S4*)_t3610->b + hr_ix(_i3610, _t3610->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:59"); }))).s_)); 
if (f233_is_blockparam(fnode_1220, g_1224)) { return g_1224;
 }
 } } _bk3607:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f232_gen_list(int64_t fnode_1221) {
return ((int64_t)(((*({ hrv *_t3613 = &(g696); int64_t _i3613 = fnode_1221; (S4*)_t3613->b + hr_ix(_i3613, _t3613->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:47"); }))).d_));
}
static bool f233_is_blockparam(int64_t fnode_1225, int64_t gname_1226) {
{ int32_t _e3615 = ((*({ hrv *_t3616 = &(g696); int64_t _i3616 = fnode_1225; (S4*)_t3616->b + hr_ix(_i3616, _t3616->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:49"); }))).n_; for (int32_t _k3615 = 0; _k3615 < _e3615; _k3615++) { int32_t i_1227 = (int32_t)_k3615; int64_t p_1228 = f90_kid(fnode_1225, ((int64_t)(i_1227))); 
if ((((((*({ hrv *_t3618 = &(g696); int64_t _i3618 = p_1228; (S4*)_t3618->b + hr_ix(_i3618, _t3618->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:49"); }))).a_) >= (((int32_t)0LL))) && f234_mentions(((int64_t)(((*({ hrv *_t3620 = &(g696); int64_t _i3620 = p_1228; (S4*)_t3620->b + hr_ix(_i3620, _t3620->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:49"); }))).a_)), gname_1226))) { return false;
 }
 } } _bk3614:; 
return true;
}
static bool f234_mentions(int64_t t_1229, int64_t g_1230) {
if (((t_1229) < (((int64_t)0LL)))) { return false;
 }
S4 x_1231 = (*({ hrv *_t3621 = &(g696); int64_t _i3621 = t_1229; (S4*)_t3621->b + hr_ix(_i3621, _t3621->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:54"); })); 
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
int64_t fv_1237 = ((int64_t)(((*({ hrv *_t3627 = &(g380); int64_t _i3627 = inst_1236; (S6*)_t3627->b + hr_ix(_i3627, _t3627->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:301"); }))).blk_)); 
int64_t own_1238 = ((int64_t)(((*({ hrv *_t3628 = &(g380); int64_t _i3628 = inst_1236; (S6*)_t3628->b + hr_ix(_i3628, _t3628->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:302"); }))).bown_)); 
int64_t s_1239 = f226_ck_args(n_1235, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t na_1240 = ((int64_t)(((*({ hrv *_t3630 = &(g696); int64_t _i3630 = n_1235; (S4*)_t3630->b + hr_ix(_i3630, _t3630->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:304"); }))).n_)); 
{ int64_t _e3632 = na_1240; for (int64_t _k3632 = 0; _k3632 < _e3632; _k3632++) { int64_t j_1241 = (int64_t)_k3632; int64_t c_1242 = f90_kid(n_1235, j_1241); 
if (f163_is_pending(f141_at(c_1242))) { { int32_t *_t3636 = &((*({ hrv *_t3637 = &(g400); int64_t _i3637 = ((int64_t)((int64_t)s_1239 + (int64_t)j_1241)); (int32_t*)_t3637->b + hr_ix(_i3637, _t3637->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:305"); }))); *_t3636 = ((int32_t)(f184_default_t(c_1242))); }
 } else { { int32_t *_t3639 = &((*({ hrv *_t3640 = &(g400); int64_t _i3640 = ((int64_t)((int64_t)s_1239 + (int64_t)j_1241)); (int32_t*)_t3640->b + hr_ix(_i3640, _t3640->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:305"); }))); *_t3639 = ((int32_t)(f236_deref_val(f141_at(c_1242)))); }
 }
 } } _bk3631:; 
int64_t bi_1245 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v3644 = &(g380); for (int64_t _k3644 = 0; _k3644 < _v3644->n; _k3644++) { S6 f_1246 = ((S6*)_v3644->b)[_k3644]; int64_t i_1247 = (int64_t)_k3644; if (((((((int64_t)((f_1246).node_))) == (fv_1237)) && ((((int64_t)((f_1246).par_))) == (own_1238))) && (((f_1246).blk_) == (((int32_t)(inst_1236)))))) { bi_1245 = i_1247;
 }
 } } _bk3643:; 
if (((bi_1245) < (((int64_t)0LL)))) { bi_1245 = f105_new_inst(fv_1237, fv_1237, ((int64_t)((*({ hrv *_t3646 = &(g711); int64_t _i3646 = fv_1237; (int32_t*)_t3646->b + hr_ix(_i3646, _t3646->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:309"); })))), own_1238);
{ int32_t *_t3647 = &(((*({ hrv *_t3648 = &(g380); int64_t _i3648 = bi_1245; (S6*)_t3648->b + hr_ix(_i3648, _t3648->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:310"); }))).blk_); *_t3647 = ((int32_t)(inst_1236)); }
{ int32_t *_t3649 = &(((*({ hrv *_t3650 = &(g380); int64_t _i3650 = bi_1245; (S6*)_t3650->b + hr_ix(_i3650, _t3650->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:310"); }))).bown_); *_t3649 = ((int32_t)(own_1238)); }
{ int32_t *_t3651 = &(((*({ hrv *_t3652 = &(g380); int64_t _i3652 = bi_1245; (S6*)_t3652->b + hr_ix(_i3652, _t3652->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:311"); }))).cfn_); *_t3651 = ((int32_t)(g394)); }
int64_t sa_1248 = g393; 
int64_t sm_1249 = (g382).n; 
int64_t bt_1250 = (g460).n; 
int64_t ld_1251 = g399; 
g393 = bi_1245;
g399 = ((int64_t)0LL);
int64_t np_1252 = ((int64_t)(((*({ hrv *_t3653 = &(g696); int64_t _i3653 = fv_1237; (S4*)_t3653->b + hr_ix(_i3653, _t3653->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:314"); }))).n_)); 
if (((((uint16_t)((uint64_t)((*({ hrv *_t3654 = &(g696); int64_t _i3654 = fv_1237; (S4*)_t3654->b + hr_ix(_i3654, _t3654->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:315"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { int64_t _e3656 = np_1252; for (int64_t _k3656 = 0; _k3656 < _e3656; _k3656++) { int64_t j_1253 = (int64_t)_k3656; int64_t p_1254 = f90_kid(fv_1237, j_1253); 
int64_t pt_1255 = ({ int64_t _r3658; if (((j_1253) < (na_1240))) { _r3658 = ((int64_t)((*({ hrv *_t3659 = &(g400); int64_t _i3659 = ((int64_t)((int64_t)s_1239 + (int64_t)j_1253)); (int32_t*)_t3659->b + hr_ix(_i3659, _t3659->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:315"); }))));  } else { _r3658 = g567;  } _r3658; }); 
int64_t v_1256 = f203_add_lv(((int64_t)(((*({ hrv *_t3661 = &(g696); int64_t _i3661 = p_1254; (S4*)_t3661->b + hr_ix(_i3661, _t3661->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:315"); }))).s_)), pt_1255, ((int64_t)32LL), p_1254); 
(void)(f170_set_r(p_1254, ((int64_t)1LL), v_1256));
 } } _bk3655:; 
 } else { if (((na_1240) >= (((int64_t)1LL)))) { int64_t v_1257 = f203_add_lv(f8_intern(hr_str("it", 2)), ((int64_t)((*({ hrv *_t3665 = &(g400); int64_t _i3665 = s_1239; (int32_t*)_t3665->b + hr_ix(_i3665, _t3665->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:316"); })))), ((int64_t)32LL), fv_1237); 
(void)(f170_set_r(fv_1237, ((int64_t)1LL), v_1257));
 }
 }
int64_t body_1258 = ((int64_t)(((*({ hrv *_t3667 = &(g696); int64_t _i3667 = fv_1237; (S4*)_t3667->b + hr_ix(_i3667, _t3667->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:317"); }))).a_)); 
int64_t bt0_1259 = f137_ck(body_1258, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t rt_1260 = g550; 
if ((((((*({ hrv *_t3669 = &(g696); int64_t _i3669 = body_1258; (S4*)_t3669->b + hr_ix(_i3669, _t3669->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:320"); }))).a_) >= (((int32_t)0LL))) && ((bt0_1259) != (g550)))) { rt_1260 = ({ int64_t _r3670; if (f163_is_pending(bt0_1259)) { _r3670 = f184_default_t(((int64_t)(((*({ hrv *_t3673 = &(g696); int64_t _i3673 = body_1258; (S4*)_t3673->b + hr_ix(_i3673, _t3673->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:320"); }))).a_)));  } else { _r3670 = bt0_1259;  } _r3670; });
 }
{ int32_t *_t3674 = &(((*({ hrv *_t3675 = &(g380); int64_t _i3675 = bi_1245; (S6*)_t3675->b + hr_ix(_i3675, _t3675->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:321"); }))).ret_); *_t3674 = ((int32_t)(rt_1260)); }
(void)(({ hrv *_v3676 = &(g382); int64_t _k3676 = ((int64_t)((int64_t)(g382).n - (int64_t)sm_1249)); if (_k3676 < 0 || _k3676 > _v3676->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:322"); _v3676->n -= _k3676; }));
while ((((g460).n) > (bt_1250))) { (void)(({ hrv *_v3678 = &(g460); if (!_v3678->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:322"); ((int32_t*)_v3678->b)[--_v3678->n]; }));
 } _bk3677:; 
g393 = sa_1248;
g399 = ld_1251;
{ uint8_t *_t3679 = &(((*({ hrv *_t3680 = &(g380); int64_t _i3680 = bi_1245; (S6*)_t3680->b + hr_ix(_i3680, _t3680->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:324"); }))).st_); *_t3679 = ((uint8_t)2LL); }
 }
{ int64_t _e3682 = na_1240; for (int64_t _k3682 = 0; _k3682 < _e3682; _k3682++) { int64_t j_1261 = (int64_t)_k3682; int64_t c_1262 = f90_kid(n_1235, j_1261); 
if (f163_is_pending(f141_at(c_1262))) { (void)(f184_default_t(c_1262));
 }
 } } _bk3681:; 
(void)(f227_pop_args(s_1239));
(void)(f170_set_r(n_1235, ((int64_t)10LL), bi_1245));
return f138_set_t(n_1235, ((int64_t)(((*({ hrv *_t3690 = &(g380); int64_t _i3690 = bi_1245; (S6*)_t3690->b + hr_ix(_i3690, _t3690->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:329"); }))).ret_)));
}
static int64_t f236_deref_val(int64_t a_1243) {
int64_t d_1244 = f179_deref(a_1243); 
return ({ int64_t _r3692; if (((((*({ hrv *_t3693 = &(g543); int64_t _i3693 = d_1244; (S1*)_t3693->b + hr_ix(_i3693, _t3693->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:246"); }))).k_) == (((uint8_t)18LL)))) { _r3692 = g568;  } else { _r3692 = ({ int64_t _r3694; if (((((*({ hrv *_t3695 = &(g543); int64_t _i3695 = d_1244; (S1*)_t3695->b + hr_ix(_i3695, _t3695->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:246"); }))).k_) == (((uint8_t)7LL)))) { _r3694 = f136_t_enum(((int64_t)(((*({ hrv *_t3697 = &(g543); int64_t _i3697 = d_1244; (S1*)_t3697->b + hr_ix(_i3697, _t3697->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:246"); }))).a_)), false);  } else { _r3694 = d_1244;  } _r3694; });  } _r3692; });
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
if (((((*({ hrv *_t3698 = &(g696); int64_t _i3698 = n_1265; (S4*)_t3698->b + hr_ix(_i3698, _t3698->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:290"); }))).n_) != (((int32_t)2LL)))) { return false;
 }
int64_t c0_1266 = (g311).n; 
(void)(f239_cands_add(f8_intern(hr_str("format", 6)), f110_ns_of(n_1265)));
bool any_1275 = false; 
{ int64_t _e3703 = (g311).n; for (int64_t _k3703 = c0_1266; _k3703 < _e3703; _k3703++) { int64_t ci_1276 = (int64_t)_k3703; if ((!(f240_is_std_node(((int64_t)(((*({ hrv *_t3705 = &(g481); int64_t _i3705 = (*({ hrv *_t3706 = &(g311); int64_t _i3706 = ci_1276; (int32_t*)_t3706->b + hr_ix(_i3706, _t3706->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:290"); })); (S5*)_t3705->b + hr_ix(_i3705, _t3705->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:290"); }))).node_)))))) { any_1275 = true;
 }
 } } _bk3702:; 
(void)(({ hrv *_v3707 = &(g311); int64_t _k3707 = ((int64_t)((int64_t)(g311).n - (int64_t)c0_1266)); if (_k3707 < 0 || _k3707 > _v3707->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:290"); _v3707->n -= _k3707; }));
return any_1275;
}
static void f239_cands_add(int64_t name_1267, int64_t ns_1268) {
M55 _t3708 = f117_split_q(name_1267); int64_t a_1269 = _t3708.r0; int64_t b_1270 = _t3708.r1; 
if (((a_1269) >= (((int64_t)0LL)))) { int64_t d_1271 = f107_dmap(name_1267); 
while (((d_1271) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t3712 = &(g481); int64_t _i3712 = d_1271; (S5*)_t3712->b + hr_ix(_i3712, _t3712->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:190"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v3713 = &(g311); int32_t _x3713 = ((int32_t)(d_1271)); int32_t *_p3713 = (int32_t*)hr_grow(_v3713, 1, sizeof _x3713); *_p3713 = _x3713; _p3713; }));
 }
d_1271 = ((int64_t)(((*({ hrv *_t3714 = &(g481); int64_t _i3714 = d_1271; (S5*)_t3714->b + hr_ix(_i3714, _t3714->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:190"); }))).next_));
 } _bk3711:; 
return;
 }
if (((a_1269) == (((int64_t)(0 - (uint64_t)(((int64_t)2LL))))))) { int64_t d_1272 = f107_dmap(b_1270); 
while (((d_1272) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t3717 = &(g481); int64_t _i3717 = d_1272; (S5*)_t3717->b + hr_ix(_i3717, _t3717->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:191"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v3718 = &(g311); int32_t _x3718 = ((int32_t)(d_1272)); int32_t *_p3718 = (int32_t*)hr_grow(_v3718, 1, sizeof _x3718); *_p3718 = _x3718; _p3718; }));
 }
d_1272 = ((int64_t)(((*({ hrv *_t3719 = &(g481); int64_t _i3719 = d_1272; (S5*)_t3719->b + hr_ix(_i3719, _t3719->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:191"); }))).next_));
 } _bk3716:; 
return;
 }
if (((ns_1268) >= (((int64_t)0LL)))) { int64_t d_1273 = f107_dmap(f98_qual(ns_1268, name_1267)); 
while (((d_1273) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t3723 = &(g481); int64_t _i3723 = d_1273; (S5*)_t3723->b + hr_ix(_i3723, _t3723->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:192"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v3724 = &(g311); int32_t _x3724 = ((int32_t)(d_1273)); int32_t *_p3724 = (int32_t*)hr_grow(_v3724, 1, sizeof _x3724); *_p3724 = _x3724; _p3724; }));
 }
d_1273 = ((int64_t)(((*({ hrv *_t3725 = &(g481); int64_t _i3725 = d_1273; (S5*)_t3725->b + hr_ix(_i3725, _t3725->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:192"); }))).next_));
 } _bk3722:; 
 }
int64_t d_1274 = f107_dmap(name_1267); 
while (((d_1274) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t3728 = &(g481); int64_t _i3728 = d_1274; (S5*)_t3728->b + hr_ix(_i3728, _t3728->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:194"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v3729 = &(g311); int32_t _x3729 = ((int32_t)(d_1274)); int32_t *_p3729 = (int32_t*)hr_grow(_v3729, 1, sizeof _x3729); *_p3729 = _x3729; _p3729; }));
 }
d_1274 = ((int64_t)(((*({ hrv *_t3730 = &(g481); int64_t _i3730 = d_1274; (S5*)_t3730->b + hr_ix(_i3730, _t3730->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:194"); }))).next_));
 } _bk3727:; 
}
static bool f240_is_std_node(int64_t node_1277) {
int64_t f_1278 = f111_node_file(node_1277); 
L49 sp_1279 = f100_lib_path(hr_str("std", 3)); 
return hr_streq(f10_nm(((int64_t)(((*({ hrv *_t3734 = &(g905); int64_t _i3734 = f_1278; (S2*)_t3734->b + hr_ix(_i3734, _t3734->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:196"); }))).name_))), ({ hsl _t3735 = ({ L49 *_t3736 = &(sp_1279); (hsl){ (uint8_t*)_t3736->e, _t3736->n }; }); int64_t _l3735 = 0, _h3735 = _t3735.n; if (_l3735 < 0 || _h3735 < _l3735 || _h3735 > _t3735.n) hr_slerr(_l3735, _h3735, _t3735.n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:196"); (hsl){ _t3735.p + _l3735 * (int64_t)sizeof(uint8_t), _h3735 - _l3735 }; }));
}
static int64_t f241_ck_builtin(int64_t n_1280, int64_t b_1281, int64_t recv_1282, int64_t want_1283) {
S4 x_1284 = (*({ hrv *_t3737 = &(g696); int64_t _i3737 = n_1280; (S4*)_t3737->b + hr_ix(_i3737, _t3737->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:368"); })); 
(void)(f170_set_r(n_1280, ((int64_t)4LL), b_1281));
(void)(f175_set_x(n_1280, ({ int64_t _r3740; if (((recv_1282) >= (((int64_t)0LL)))) { _r3740 = ((int64_t)1LL);  } else { _r3740 = ((int64_t)0LL);  } _r3740; })));
int64_t na_1285 = ((int64_t)((x_1284).n_)); 

int64_t total_1287 = ((int64_t)((int64_t)na_1285 + (int64_t)({ int64_t _r3741; if (((recv_1282) >= (((int64_t)0LL)))) { _r3741 = ((int64_t)1LL);  } else { _r3741 = ((int64_t)0LL);  } _r3741; }))); 
if ((((b_1281) == (((int64_t)1LL))) || ((b_1281) == (((int64_t)2LL))))) { { int64_t _e3743 = na_1285; for (int64_t _k3743 = 0; _k3743 < _e3743; _k3743++) { int64_t i_1288 = (int64_t)_k3743; int64_t c_1289 = f90_kid(n_1280, i_1288); 
int64_t t_1290 = f137_ck(c_1289, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f163_is_pending(t_1290)) { (void)(f184_default_t(c_1289));
 }
 } } _bk3742:; 
return f138_set_t(n_1280, ({ int64_t _r3749; if (((b_1281) == (((int64_t)2LL)))) { _r3749 = f123_t_arr(g556, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));  } else { _r3749 = g550;  } _r3749; }));
 }
if (((b_1281) == (((int64_t)3LL)))) { int64_t o_1291 = f242_arg(((int64_t)0LL), &recv_1282, &n_1280); 
if (((recv_1282) < (((int64_t)0LL)))) { (void)(f137_ck(o_1291, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
{ int64_t _e3754 = total_1287; for (int64_t _k3754 = ((int64_t)1LL); _k3754 < _e3754; _k3754++) { int64_t i_1292 = (int64_t)_k3754; int64_t c_1293 = f242_arg(i_1292, &recv_1282, &n_1280); 
int64_t t_1294 = f137_ck(c_1293, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f163_is_pending(t_1294)) { (void)(f184_default_t(c_1293));
 }
 } } _bk3753:; 
return f138_set_t(n_1280, g550);
 }
if (((b_1281) == (((int64_t)4LL)))) { (void)(f137_ck(f242_arg(((int64_t)0LL), &recv_1282, &n_1280), g551));
(void)(f140_conv(f242_arg(((int64_t)0LL), &recv_1282, &n_1280), g551));
return f138_set_t(n_1280, g550);
 }
if (((b_1281) == (((int64_t)5LL)))) { int64_t t_1295 = f137_ck(f242_arg(((int64_t)0LL), &recv_1282, &n_1280), g568); 
if (f163_is_pending(t_1295)) { (void)(f184_default_t(f242_arg(((int64_t)0LL), &recv_1282, &n_1280)));
 }
return f138_set_t(n_1280, g550);
 }
if (((b_1281) == (((int64_t)6LL)))) { (void)(f137_ck(f242_arg(((int64_t)0LL), &recv_1282, &n_1280), g555));
(void)(f140_conv(f242_arg(((int64_t)0LL), &recv_1282, &n_1280), g555));
return f138_set_t(n_1280, g550);
 }
if (((b_1281) == (((int64_t)8LL)))) { int64_t ta_1296 = ((int64_t)((x_1284).c_)); 
if (((ta_1296) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1280, hr_str("default needs a type: default<T>()", 34)));
return f138_set_t(n_1280, g567);
 }
return f138_set_t(n_1280, f113_rtype(f90_kid(ta_1296, ((int64_t)0LL)), f110_ns_of(n_1280)));
 }
if (((b_1281) == (((int64_t)7LL)))) { int64_t c_1297 = f242_arg(((int64_t)0LL), &recv_1282, &n_1280); 
if (((recv_1282) < (((int64_t)0LL)))) { (void)(f137_ck(c_1297, want_1283));
 }
int64_t t_1298 = f141_at(c_1297); 
if (f163_is_pending(t_1298)) { t_1298 = f184_default_t(c_1297);
 }
int64_t d_1299 = f179_deref(t_1298); 
int64_t k_1300 = ((int64_t)(((*({ hrv *_t3788 = &(g543); int64_t _i3788 = d_1299; (S1*)_t3788->b + hr_ix(_i3788, _t3788->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:394"); }))).k_)); 
if (((k_1300) == (((int64_t)9LL)))) { return f138_set_t(n_1280, f123_t_arr(((int64_t)(((*({ hrv *_t3791 = &(g543); int64_t _i3791 = d_1299; (S1*)_t3791->b + hr_ix(_i3791, _t3791->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:395"); }))).a_)), ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
return f138_set_t(n_1280, d_1299);
 }
if (((b_1281) == (((int64_t)9LL)))) { int64_t c_1301 = f242_arg(((int64_t)0LL), &recv_1282, &n_1280); 
if (((recv_1282) < (((int64_t)0LL)))) { (void)(f137_ck(c_1301, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (((((*({ hrv *_t3795 = &(g543); int64_t _i3795 = f141_at(c_1301); (S1*)_t3795->b + hr_ix(_i3795, _t3795->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:398"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(c_1301, g568));
 }
return f138_set_t(n_1280, g555);
 }
if (((b_1281) == (((int64_t)31LL)))) { int64_t c_1302 = f242_arg(((int64_t)0LL), &recv_1282, &n_1280); 
if (((recv_1282) < (((int64_t)0LL)))) { (void)(f137_ck(c_1302, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (f163_is_pending(f141_at(c_1302))) { (void)(f184_default_t(c_1302));
 }
return f138_set_t(n_1280, g568);
 }
if (((b_1281) == (((int64_t)30LL)))) { int64_t c_1303 = f242_arg(((int64_t)0LL), &recv_1282, &n_1280); 
if (((recv_1282) < (((int64_t)0LL)))) { (void)(f137_ck(c_1303, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (f163_is_pending(f141_at(c_1303))) { (void)(f184_default_t(c_1303));
 }
if (((total_1287) > (((int64_t)1LL)))) { (void)(f137_ck(f242_arg(((int64_t)1LL), &recv_1282, &n_1280), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_1280, g550);
 }
return f138_set_t(n_1280, f123_t_arr(g556, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (((b_1281) == (((int64_t)32LL)))) { int64_t ta_1304 = ((int64_t)((x_1284).c_)); 
int64_t t_1305 = ({ int64_t _r3815; if (((ta_1304) >= (((int64_t)0LL)))) { _r3815 = f113_rtype(f90_kid(ta_1304, ((int64_t)0LL)), f110_ns_of(n_1280));  } else { _r3815 = g567;  } _r3815; }); 
(void)(f137_ck(f242_arg(((int64_t)0LL), &recv_1282, &n_1280), g568));
if (f163_is_pending(f141_at(f242_arg(((int64_t)0LL), &recv_1282, &n_1280)))) { (void)(f184_default_t(f242_arg(((int64_t)0LL), &recv_1282, &n_1280)));
 }
return f138_set_t(n_1280, t_1305);
 }
if (((b_1281) == (((int64_t)33LL)))) { (void)(f137_ck(f242_arg(((int64_t)0LL), &recv_1282, &n_1280), g568));
(void)(f184_default_t(f242_arg(((int64_t)0LL), &recv_1282, &n_1280)));
return f138_set_t(n_1280, g568);
 }
int64_t r_1306 = recv_1282; 
int64_t rt_1307 = f179_deref(f141_at(r_1306)); 
int64_t e_1308 = ((int64_t)(((*({ hrv *_t3834 = &(g543); int64_t _i3834 = rt_1307; (S1*)_t3834->b + hr_ix(_i3834, _t3834->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:405"); }))).a_)); 
if (((b_1281) == (((int64_t)20LL)))) { if (((total_1287) != (((int64_t)2LL)))) { (void)(f108_cerr(n_1280, hr_str("push takes one value", 20)));
return f138_set_t(n_1280, g567);
 }
int64_t c_1309 = f242_arg(((int64_t)1LL), &recv_1282, &n_1280); 
(void)(f137_ck(c_1309, e_1308));
(void)(f140_conv(c_1309, e_1308));
return f138_set_t(n_1280, f119_t_ref(e_1308, ((int64_t)0LL)));
 }
if (((b_1281) == (((int64_t)21LL)))) { int64_t c_1310 = f242_arg(((int64_t)1LL), &recv_1282, &n_1280); 
int64_t t_1311 = f137_ck(c_1310, f18_t_slice(e_1308, true)); 
if (((((*({ hrv *_t3845 = &(g543); int64_t _i3845 = t_1311; (S1*)_t3845->b + hr_ix(_i3845, _t3845->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:407"); }))).k_) == (((uint8_t)18LL)))) { (void)(f138_set_t(c_1310, g568));
 } else { if (((((*({ hrv *_t3847 = &(g543); int64_t _i3847 = t_1311; (S1*)_t3847->b + hr_ix(_i3847, _t3847->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:407"); }))).k_) == (((uint8_t)19LL)))) { (void)(f140_conv(c_1310, f123_t_arr(e_1308, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
 } else { int64_t dt_1312 = f179_deref(t_1311); 
if (((((((*({ hrv *_t3851 = &(g543); int64_t _i3851 = dt_1312; (S1*)_t3851->b + hr_ix(_i3851, _t3851->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:407"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t3852 = &(g543); int64_t _i3852 = dt_1312; (S1*)_t3852->b + hr_ix(_i3852, _t3852->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:407"); }))).k_) == (((uint8_t)9LL)))) && ((((int64_t)(((*({ hrv *_t3853 = &(g543); int64_t _i3853 = dt_1312; (S1*)_t3853->b + hr_ix(_i3853, _t3853->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:407"); }))).a_))) != (e_1308)))) { (void)(f108_cerr(c_1310, hr_str("append of a different element type", 34)));
 }
 }
 }
return f138_set_t(n_1280, g550);
 }
if (((b_1281) == (((int64_t)22LL)))) { return f138_set_t(n_1280, e_1308);
 }
if (((b_1281) == (((int64_t)23LL)))) { (void)(f137_ck(f242_arg(((int64_t)1LL), &recv_1282, &n_1280), g555));
(void)(f140_conv(f242_arg(((int64_t)1LL), &recv_1282, &n_1280), g555));
return f138_set_t(n_1280, g550);
 }
if (((b_1281) == (((int64_t)24LL)))) { (void)(f137_ck(f242_arg(((int64_t)1LL), &recv_1282, &n_1280), g555));
(void)(f140_conv(f242_arg(((int64_t)1LL), &recv_1282, &n_1280), g555));
if (((total_1287) > (((int64_t)2LL)))) { (void)(f137_ck(f242_arg(((int64_t)2LL), &recv_1282, &n_1280), e_1308));
(void)(f140_conv(f242_arg(((int64_t)2LL), &recv_1282, &n_1280), e_1308));
 }
return f138_set_t(n_1280, g550);
 }
if (((b_1281) == (((int64_t)25LL)))) { return f138_set_t(n_1280, g550);
 }
if (((b_1281) == (((int64_t)26LL)))) { (void)(f137_ck(f242_arg(((int64_t)1LL), &recv_1282, &n_1280), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f138_set_t(n_1280, g555);
 }
return f138_set_t(n_1280, g567);
}
static int64_t f242_arg(int64_t i_1286, int64_t *c1282, int64_t *c1280) {
return ({ int64_t _r3876; if ((((*c1282)) >= (((int64_t)0LL)))) { _r3876 = ({ int64_t _r3877; if (((i_1286) == (((int64_t)0LL)))) { _r3877 = (*c1282);  } else { _r3877 = f90_kid((*c1280), ((int64_t)((int64_t)i_1286 - (int64_t)((int64_t)1LL))));  } _r3877; });  } else { _r3876 = f90_kid((*c1280), i_1286);  } _r3876; });
}
static int64_t f243_call_fn(int64_t n_1313, int64_t name_1314, int64_t recv_1315, int64_t want_1316) {
int64_t s_1317 = f226_ck_args(n_1313, ((int64_t)0LL), recv_1315); 
int64_t an_1318 = ((int64_t)((int64_t)(g400).n - (int64_t)s_1317)); 
int64_t blk_1319 = ((int64_t)(((*({ hrv *_t3881 = &(g696); int64_t _i3881 = n_1313; (S4*)_t3881->b + hr_ix(_i3881, _t3881->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:346"); }))).b_)); 
M94 _t3882 = f244_resolve(n_1313, name_1314, f110_ns_of(n_1313), s_1317, an_1318, blk_1319, ((int64_t)(((*({ hrv *_t3885 = &(g696); int64_t _i3885 = n_1313; (S4*)_t3885->b + hr_ix(_i3885, _t3885->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:347"); }))).c_)), true); int64_t fnode_1397 = _t3882.r0; int64_t b0_1398 = _t3882.r1; int64_t bn_1399 = _t3882.r2; 
if (((fnode_1397) < (((int64_t)0LL)))) { hrv m_1400 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o3887 = &(m_1400); hr_fs(_o3887, hr_str("no function ", 12)); hr_fs(_o3887, f10_nm(name_1314)); hr_fs(_o3887, hr_str(" matches (", 10)); }));
{ int64_t _e3890 = an_1318; for (int64_t _k3890 = 0; _k3890 < _e3890; _k3890++) { int64_t j_1401 = (int64_t)_k3890; if (((j_1401) > (((int64_t)0LL)))) { (void)(({ hrv *_v3891 = &(m_1400); hsl _s3891 = hr_str(", ", 2); hr_append(_v3891, _s3891.p, _s3891.n, sizeof(uint8_t)); }));
 }
{ hrv _t3893 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_v3892 = &(m_1400); hsl _s3892 = hr_sl(*hr_tmp(&_t3893, f161_tn(((int64_t)((*({ hrv *_t3895 = &(g400); int64_t _i3895 = ((int64_t)((int64_t)s_1317 + (int64_t)j_1401)); (int32_t*)_t3895->b + hr_ix(_i3895, _t3895->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:350"); }))))))); hr_append(_v3892, _s3892.p, _s3892.n, sizeof(uint8_t)); }));
}
 } } _bk3889:; 
(void)(({ hrv *_v3896 = &(m_1400); hsl _s3896 = hr_str(")", 1); hr_append(_v3896, _s3896.p, _s3896.n, sizeof(uint8_t)); }));
(void)(f108_cerr(n_1313, hr_sl(m_1400)));
(void)(f227_pop_args(s_1317));
(void)(({ hrv *_v3899 = &(g312); int64_t _k3899 = ((int64_t)((int64_t)(g312).n - (int64_t)b0_1398)); if (_k3899 < 0 || _k3899 > _v3899->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:354"); _v3899->n -= _k3899; }));
return f138_set_t(n_1313, g567);
 }
int64_t inst_1416 = f250_get_inst(fnode_1397, b0_1398, bn_1399, blk_1319, g393); 
(void)(({ hrv *_v3902 = &(g312); int64_t _k3902 = ((int64_t)((int64_t)(g312).n - (int64_t)b0_1398)); if (_k3902 < 0 || _k3902 > _v3902->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:358"); _v3902->n -= _k3902; }));
{ int64_t _e3904 = an_1318; for (int64_t _k3904 = 0; _k3904 < _e3904; _k3904++) { int64_t j_1417 = (int64_t)_k3904; int64_t c_1418 = ((int64_t)((*({ hrv *_t3905 = &(g314); int64_t _i3905 = ((int64_t)((int64_t)s_1317 + (int64_t)j_1417)); (int32_t*)_t3905->b + hr_ix(_i3905, _t3905->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:359"); })))); 
int64_t pt_1419 = f208_ptype_of(inst_1416, j_1417); 
if ((((((pt_1419) >= (((int64_t)0LL))) && ((((*({ hrv *_t3907 = &(g543); int64_t _i3907 = pt_1419; (S1*)_t3907->b + hr_ix(_i3907, _t3907->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:359"); }))).k_) == (((uint8_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t3908 = &(g543); int64_t _i3908 = pt_1419; (S1*)_t3908->b + hr_ix(_i3908, _t3908->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:359"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))) && ((((*({ hrv *_t3909 = &(g543); int64_t _i3909 = pt_1419; (S1*)_t3909->b + hr_ix(_i3909, _t3909->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:359"); }))).c_) < (((int32_t)0LL))))) { if (f163_is_pending(f141_at(c_1418))) { (void)(f140_conv(c_1418, ((int64_t)(((*({ hrv *_t3913 = &(g543); int64_t _i3913 = pt_1419; (S1*)_t3913->b + hr_ix(_i3913, _t3913->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:359"); }))).a_))));
 }
 } else { (void)(f140_conv(c_1418, pt_1419));
 }
 } } _bk3903:; 
(void)(f227_pop_args(s_1317));
(void)(f228_note_caps_of(inst_1416));
(void)(f229_note_edge(inst_1416));
(void)(f170_set_r(n_1313, ((int64_t)3LL), inst_1416));
int64_t rt_1420 = ((int64_t)(((*({ hrv *_t3919 = &(g380); int64_t _i3919 = inst_1416; (S6*)_t3919->b + hr_ix(_i3919, _t3919->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:363"); }))).ret_)); 
if (((rt_1420) < (((int64_t)0LL)))) { if (((((*({ hrv *_t3920 = &(g380); int64_t _i3920 = inst_1416; (S6*)_t3920->b + hr_ix(_i3920, _t3920->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:364"); }))).st_) == (((uint8_t)1LL)))) { hrv m_1421 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o3922 = &(m_1421); hr_fs(_o3922, hr_str("recursive call to ", 18)); hr_fs(_o3922, f10_nm(name_1314)); hr_fs(_o3922, hr_str(" needs its result type written", 30)); }));
(void)(f108_cerr(n_1313, hr_sl(m_1421)));
 }
return f138_set_t(n_1313, g567);
 }
return f138_set_t(n_1313, rt_1420);
}
static M94 f244_resolve(int64_t n_1320, int64_t name_1321, int64_t ns_1322, int64_t a0_1323, int64_t an_1324, int64_t blk_1325, int64_t tyargs_1326, bool report_1327) {
int64_t c0_1328 = (g311).n; 
(void)(f239_cands_add(name_1321, ns_1322));
int64_t best_1329 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
int64_t bestr_1330 = ((int64_t)99LL); 
int64_t bestb0_1331 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
int64_t bestbn_1332 = ((int64_t)0LL); 
bool tie_1333 = false; 
bool bestuser_1334 = false; 
int64_t nb0_1335 = (g312).n; 
{ int64_t _e3929 = (g311).n; for (int64_t _k3929 = c0_1328; _k3929 < _e3929; _k3929++) { int64_t ci_1336 = (int64_t)_k3929; int64_t fnode_1337 = ((int64_t)(((*({ hrv *_t3930 = &(g481); int64_t _i3930 = (*({ hrv *_t3931 = &(g311); int64_t _i3931 = ci_1336; (int32_t*)_t3931->b + hr_ix(_i3931, _t3931->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:203"); })); (S5*)_t3930->b + hr_ix(_i3930, _t3930->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:203"); }))).node_)); 
int64_t np_1338 = ((int64_t)(((*({ hrv *_t3932 = &(g696); int64_t _i3932 = fnode_1337; (S4*)_t3932->b + hr_ix(_i3932, _t3932->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:204"); }))).n_)); 
int64_t nreq_1339 = ((int64_t)0LL); 
{ int64_t _e3934 = np_1338; for (int64_t _k3934 = 0; _k3934 < _e3934; _k3934++) { int64_t j_1340 = (int64_t)_k3934; if (((((*({ hrv *_t3935 = &(g696); int64_t _i3935 = f90_kid(fnode_1337, j_1340); (S4*)_t3935->b + hr_ix(_i3935, _t3935->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:206"); }))).b_) < (((int32_t)0LL)))) { nreq_1339 = ((int64_t)((int64_t)j_1340 + (int64_t)((int64_t)1LL)));
 }
 } } _bk3933:; 
if ((((an_1324) > (np_1338)) || ((an_1324) < (nreq_1339)))) { continue;
 }
int64_t bg_1341 = f231_blk_gen(fnode_1337); 
if ((((((blk_1325) >= (((int64_t)0LL)))) != (((bg_1341) >= (((int64_t)0LL))))) && (!(((((blk_1325) < (((int64_t)0LL))) && ((bg_1341) >= (((int64_t)0LL)))) && ((tyargs_1326) >= (((int64_t)0LL)))))))) { continue;
 }
int64_t b0_1342 = (g312).n; 
int64_t gl_1343 = f232_gen_list(fnode_1337); 
if (((gl_1343) >= (((int64_t)0LL)))) { { int32_t _e3940 = ((*({ hrv *_t3941 = &(g696); int64_t _i3941 = gl_1343; (S4*)_t3941->b + hr_ix(_i3941, _t3941->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:212"); }))).n_; for (int32_t _k3940 = 0; _k3940 < _e3940; _k3940++) { int32_t j_1344 = (int32_t)_k3940; (void)(({ hrv *_v3942 = &(g312); S7 _x3942 = ((S7){ .name_ = ((*({ hrv *_t3943 = &(g696); int64_t _i3943 = f90_kid(gl_1343, ((int64_t)(j_1344))); (S4*)_t3943->b + hr_ix(_i3943, _t3943->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:212"); }))).s_, .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }); S7 *_p3942 = (S7*)hr_grow(_v3942, 1, sizeof _x3942); *_p3942 = _x3942; _p3942; }));
 } } _bk3939:; 
 }
{ int64_t _e3946 = np_1338; for (int64_t _k3946 = 0; _k3946 < _e3946; _k3946++) { int64_t j_1345 = (int64_t)_k3946; int64_t p_1346 = f90_kid(fnode_1337, j_1345); 
if (((((*({ hrv *_t3948 = &(g696); int64_t _i3948 = p_1346; (S4*)_t3948->b + hr_ix(_i3948, _t3948->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:213"); }))).a_) < (((int32_t)0LL)))) { (void)(({ hrv *_v3949 = &(g312); S7 _x3949 = ((S7){ .name_ = ((int32_t)(f196_upname(p_1346))), .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }); S7 *_p3949 = (S7*)hr_grow(_v3949, 1, sizeof _x3949); *_p3949 = _x3949; _p3949; }));
 }
 } } _bk3945:; 
if (((tyargs_1326) >= (((int64_t)0LL)))) { { int64_t _e3952 = f45_min(((int64_t)(((*({ hrv *_t3954 = &(g696); int64_t _i3954 = tyargs_1326; (S4*)_t3954->b + hr_ix(_i3954, _t3954->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:214"); }))).n_)), ((int64_t)((int64_t)(g312).n - (int64_t)b0_1342))); for (int64_t _k3952 = 0; _k3952 < _e3952; _k3952++) { int64_t j_1347 = (int64_t)_k3952; { int32_t *_t3955 = &(((*({ hrv *_t3956 = &(g312); int64_t _i3956 = ((int64_t)((int64_t)b0_1342 + (int64_t)j_1347)); (S7*)_t3956->b + hr_ix(_i3956, _t3956->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:214"); }))).ty_); *_t3955 = ((int32_t)(f113_rtype(f90_kid(tyargs_1326, j_1347), ns_1322))); }
 } } _bk3951:; 
 }
{ int64_t _e3960 = an_1324; for (int64_t _k3960 = 0; _k3960 < _e3960; _k3960++) { int64_t j_1348 = (int64_t)_k3960; int64_t p_1349 = f90_kid(fnode_1337, j_1348); 
int64_t a_1350 = ((int64_t)((*({ hrv *_t3962 = &(g400); int64_t _i3962 = ((int64_t)((int64_t)a0_1323 + (int64_t)j_1348)); (int32_t*)_t3962->b + hr_ix(_i3962, _t3962->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:215"); })))); 
if ((!(f163_is_pending(a_1350)))) { if (((((*({ hrv *_t3964 = &(g696); int64_t _i3964 = p_1349; (S4*)_t3964->b + hr_ix(_i3964, _t3964->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:215"); }))).a_) >= (((int32_t)0LL)))) { (void)(f245_match_ty(((int64_t)(((*({ hrv *_t3966 = &(g696); int64_t _i3966 = p_1349; (S4*)_t3966->b + hr_ix(_i3966, _t3966->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:215"); }))).a_)), a_1350, b0_1342));
 } else { { int64_t _e3968 = (g312).n; for (int64_t _k3968 = b0_1342; _k3968 < _e3968; _k3968++) { int64_t q_1362 = (int64_t)_k3968; if ((((((int64_t)(((*({ hrv *_t3969 = &(g312); int64_t _i3969 = q_1362; (S7*)_t3969->b + hr_ix(_i3969, _t3969->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:215"); }))).name_))) == (f196_upname(p_1349))) && ((((*({ hrv *_t3971 = &(g312); int64_t _i3971 = q_1362; (S7*)_t3971->b + hr_ix(_i3971, _t3971->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:215"); }))).ty_) < (((int32_t)0LL))))) { { int32_t *_t3972 = &(((*({ hrv *_t3973 = &(g312); int64_t _i3973 = q_1362; (S7*)_t3973->b + hr_ix(_i3973, _t3973->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:215"); }))).ty_); *_t3972 = ((int32_t)(f236_deref_val(a_1350))); }
 }
 } } _bk3967:; 
 }
 }
 } } _bk3959:; 
{ int64_t _e3976 = an_1324; for (int64_t _k3976 = 0; _k3976 < _e3976; _k3976++) { int64_t j_1363 = (int64_t)_k3976; int64_t p_1364 = f90_kid(fnode_1337, j_1363); 
int64_t a_1365 = ((int64_t)((*({ hrv *_t3978 = &(g400); int64_t _i3978 = ((int64_t)((int64_t)a0_1323 + (int64_t)j_1363)); (int32_t*)_t3978->b + hr_ix(_i3978, _t3978->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:216"); })))); 
if (f163_is_pending(a_1365)) { int64_t dt_1368 = f246_pend_default(a_1365); 
if (((((*({ hrv *_t3981 = &(g696); int64_t _i3981 = p_1364; (S4*)_t3981->b + hr_ix(_i3981, _t3981->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:216"); }))).a_) >= (((int32_t)0LL)))) { (void)(f245_match_ty(((int64_t)(((*({ hrv *_t3983 = &(g696); int64_t _i3983 = p_1364; (S4*)_t3983->b + hr_ix(_i3983, _t3983->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:216"); }))).a_)), dt_1368, b0_1342));
 } else { { int64_t _e3985 = (g312).n; for (int64_t _k3985 = b0_1342; _k3985 < _e3985; _k3985++) { int64_t q_1369 = (int64_t)_k3985; if ((((((int64_t)(((*({ hrv *_t3986 = &(g312); int64_t _i3986 = q_1369; (S7*)_t3986->b + hr_ix(_i3986, _t3986->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:216"); }))).name_))) == (f196_upname(p_1364))) && ((((*({ hrv *_t3988 = &(g312); int64_t _i3988 = q_1369; (S7*)_t3988->b + hr_ix(_i3988, _t3988->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:216"); }))).ty_) < (((int32_t)0LL))))) { { int32_t *_t3989 = &(((*({ hrv *_t3990 = &(g312); int64_t _i3990 = q_1369; (S7*)_t3990->b + hr_ix(_i3990, _t3990->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:216"); }))).ty_); *_t3989 = ((int32_t)(dt_1368)); }
 }
 } } _bk3984:; 
 }
 }
 } } _bk3975:; 
bool ok_1370 = true; 
{ int64_t _e3992 = (g312).n; for (int64_t _k3992 = b0_1342; _k3992 < _e3992; _k3992++) { int64_t q_1371 = (int64_t)_k3992; if (((((*({ hrv *_t3993 = &(g312); int64_t _i3993 = q_1371; (S7*)_t3993->b + hr_ix(_i3993, _t3993->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:218"); }))).ty_) < (((int32_t)0LL)))) { if ((((bg_1341) >= (((int64_t)0LL))) && ((((int64_t)(((*({ hrv *_t3994 = &(g312); int64_t _i3994 = q_1371; (S7*)_t3994->b + hr_ix(_i3994, _t3994->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:218"); }))).name_))) == (bg_1341)))) { { int32_t *_t3995 = &(((*({ hrv *_t3996 = &(g312); int64_t _i3996 = q_1371; (S7*)_t3996->b + hr_ix(_i3996, _t3996->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:218"); }))).ty_); *_t3995 = ((int32_t)(g570)); }
 } else { ok_1370 = false;
 }
 }
 } } _bk3991:; 
if ((!(ok_1370))) { (void)(({ hrv *_v3997 = &(g312); int64_t _k3997 = ((int64_t)((int64_t)(g312).n - (int64_t)b0_1342)); if (_k3997 < 0 || _k3997 > _v3997->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:219"); _v3997->n -= _k3997; }));
continue;
 }
int64_t g0_1372 = (g483).n; 
{ int64_t _e3999 = (g312).n; for (int64_t _k3999 = b0_1342; _k3999 < _e3999; _k3999++) { int64_t q_1373 = (int64_t)_k3999; (void)(({ hrv *_v4000 = &(g483); S7 _x4000 = (*({ hrv *_t4001 = &(g312); int64_t _i4001 = q_1373; (S7*)_t4001->b + hr_ix(_i4001, _t4001->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:221"); })); S7 *_p4000 = (S7*)hr_grow(_v4000, 1, sizeof _x4000); *_p4000 = _x4000; _p4000; }));
 } } _bk3998:; 
int64_t fns_1374 = f110_ns_of(fnode_1337); 
int64_t worst_1375 = ((int64_t)0LL); 
{ int64_t _e4004 = an_1324; for (int64_t _k4004 = 0; _k4004 < _e4004; _k4004++) { int64_t j_1376 = (int64_t)_k4004; int64_t p_1377 = f90_kid(fnode_1337, j_1376); 
int64_t pt_1378 = ({ int64_t _r4006; if (((((*({ hrv *_t4007 = &(g696); int64_t _i4007 = p_1377; (S4*)_t4007->b + hr_ix(_i4007, _t4007->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:226"); }))).a_) >= (((int32_t)0LL)))) { _r4006 = f113_rtype(((int64_t)(((*({ hrv *_t4009 = &(g696); int64_t _i4009 = p_1377; (S4*)_t4009->b + hr_ix(_i4009, _t4009->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:226"); }))).a_)), fns_1374);  } else { _r4006 = f130_gb_find(f196_upname(p_1377));  } _r4006; }); 
int64_t r_1391 = f247_arg_rank(((int64_t)((*({ hrv *_t4013 = &(g314); int64_t _i4013 = ((int64_t)((int64_t)a0_1323 + (int64_t)j_1376)); (int32_t*)_t4013->b + hr_ix(_i4013, _t4013->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:227"); })))), ((int64_t)((*({ hrv *_t4014 = &(g400); int64_t _i4014 = ((int64_t)((int64_t)a0_1323 + (int64_t)j_1376)); (int32_t*)_t4014->b + hr_ix(_i4014, _t4014->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:227"); })))), pt_1378); 
if (((r_1391) < (((int64_t)0LL)))) { worst_1375 = ((int64_t)99LL);
{ goto _bk4003; }
 }
if (((r_1391) > (worst_1375))) { worst_1375 = r_1391;
 }
 } } _bk4003:; 
(void)(({ hrv *_v4015 = &(g483); int64_t _k4015 = ((int64_t)((int64_t)(g483).n - (int64_t)g0_1372)); if (_k4015 < 0 || _k4015 > _v4015->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:231"); _v4015->n -= _k4015; }));
if ((((worst_1375) < (((int64_t)2LL))) && (((gl_1343) >= (((int64_t)0LL))) || (((np_1338) > (((int64_t)0LL))) && f249_untyped_any(fnode_1337))))) { worst_1375 = f103_max(worst_1375, ((int64_t)1LL));
 }
if (((worst_1375) == (((int64_t)99LL)))) { (void)(({ hrv *_v4018 = &(g312); int64_t _k4018 = ((int64_t)((int64_t)(g312).n - (int64_t)b0_1342)); if (_k4018 < 0 || _k4018 > _v4018->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:233"); _v4018->n -= _k4018; }));
continue;
 }
bool user_1394 = (!(f240_is_std_node(fnode_1337))); 
if ((((worst_1375) < (bestr_1330)) || ((((worst_1375) == (bestr_1330)) && user_1394) && (!(bestuser_1334))))) { best_1329 = fnode_1337;
bestr_1330 = worst_1375;
bestb0_1331 = b0_1342;
bestbn_1332 = ((int64_t)((int64_t)(g312).n - (int64_t)b0_1342));
tie_1333 = false;
bestuser_1334 = user_1394;
 } else { if ((((worst_1375) == (bestr_1330)) && ((user_1394) == (bestuser_1334)))) { tie_1333 = true;
 }
 }
 } } _bk3928:; 
(void)(({ hrv *_v4020 = &(g311); int64_t _k4020 = ((int64_t)((int64_t)(g311).n - (int64_t)c0_1328)); if (_k4020 < 0 || _k4020 > _v4020->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:238"); _v4020->n -= _k4020; }));
if (((best_1329) < (((int64_t)0LL)))) { (void)(({ hrv *_v4021 = &(g312); int64_t _k4021 = ((int64_t)((int64_t)(g312).n - (int64_t)nb0_1335)); if (_k4021 < 0 || _k4021 > _v4021->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:239"); _v4021->n -= _k4021; }));
return (M94){ ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)0LL), ((int64_t)0LL) };
 }
if ((tie_1333 && report_1327)) { hrv m_1395 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o4023 = &(m_1395); hr_fs(_o4023, hr_str("ambiguous call to ", 18)); hr_fs(_o4023, f10_nm(name_1321)); }));
(void)(f108_cerr(n_1320, hr_sl(m_1395)));
 }
if (((bestb0_1331) > (nb0_1335))) { { int64_t _e4027 = bestbn_1332; for (int64_t _k4027 = ((int64_t)0LL); _k4027 < _e4027; _k4027++) { int64_t q_1396 = (int64_t)_k4027; { S7 *_t4028 = &((*({ hrv *_t4029 = &(g312); int64_t _i4029 = ((int64_t)((int64_t)nb0_1335 + (int64_t)q_1396)); (S7*)_t4029->b + hr_ix(_i4029, _t4029->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:241"); }))); *_t4028 = (*({ hrv *_t4030 = &(g312); int64_t _i4030 = ((int64_t)((int64_t)bestb0_1331 + (int64_t)q_1396)); (S7*)_t4030->b + hr_ix(_i4030, _t4030->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:241"); })); }
 } } _bk4026:; 
 }
(void)(({ hrv *_v4031 = &(g312); int64_t _k4031 = ((int64_t)((int64_t)((int64_t)((int64_t)(g312).n - (int64_t)nb0_1335)) - (int64_t)bestbn_1332)); if (_k4031 < 0 || _k4031 > _v4031->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:242"); _v4031->n -= _k4031; }));
return (M94){ best_1329, nb0_1335, bestbn_1332 };
}
static bool f245_match_ty(int64_t tn0_1351, int64_t t0_1352, int64_t g0_1353) {
if (((tn0_1351) < (((int64_t)0LL)))) { return true;
 }
S4 x_1354 = (*({ hrv *_t4032 = &(g696); int64_t _i4032 = tn0_1351; (S4*)_t4032->b + hr_ix(_i4032, _t4032->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:63"); })); 
int64_t k_1355 = ((int64_t)((x_1354).k_)); 
int64_t t_1356 = f179_deref(t0_1352); 
if (((k_1355) == (((int64_t)41LL)))) { if ((((x_1354).n_) == (((int32_t)0LL)))) { { int64_t _e4035 = (g312).n; for (int64_t _k4035 = g0_1353; _k4035 < _e4035; _k4035++) { int64_t i_1357 = (int64_t)_k4035; if (((((*({ hrv *_t4036 = &(g312); int64_t _i4036 = i_1357; (S7*)_t4036->b + hr_ix(_i4036, _t4036->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:67"); }))).name_) == ((x_1354).s_))) { if (((((*({ hrv *_t4037 = &(g312); int64_t _i4037 = i_1357; (S7*)_t4037->b + hr_ix(_i4037, _t4037->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:67"); }))).ty_) < (((int32_t)0LL)))) { { int32_t *_t4038 = &(((*({ hrv *_t4039 = &(g312); int64_t _i4039 = i_1357; (S7*)_t4039->b + hr_ix(_i4039, _t4039->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:67"); }))).ty_); *_t4038 = ((int32_t)(f236_deref_val(t_1356))); }
 }
return true;
 }
 } } _bk4034:; 
return true;
 }
if (((((*({ hrv *_t4041 = &(g543); int64_t _i4041 = t_1356; (S1*)_t4041->b + hr_ix(_i4041, _t4041->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:70"); }))).k_) == (((uint8_t)5LL)))) { int64_t si_1358 = ((int64_t)(((*({ hrv *_t4042 = &(g543); int64_t _i4042 = t_1356; (S1*)_t4042->b + hr_ix(_i4042, _t4042->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:70"); }))).a_)); 
if (((((*({ hrv *_t4043 = &(g546); int64_t _i4043 = si_1358; (S10*)_t4043->b + hr_ix(_i4043, _t4043->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:70"); }))).tn_) == ((x_1354).n_))) { { int32_t _e4045 = (x_1354).n_; for (int32_t _k4045 = 0; _k4045 < _e4045; _k4045++) { int32_t i_1359 = (int32_t)_k4045; (void)(f245_match_ty(f90_kid(tn0_1351, ((int64_t)(i_1359))), ((int64_t)((*({ hrv *_t4048 = &(g544); int64_t _i4048 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4049 = &(g546); int64_t _i4049 = si_1358; (S10*)_t4049->b + hr_ix(_i4049, _t4049->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:70"); }))).ta_)) + (int64_t)((int64_t)(i_1359)))); (int32_t*)_t4048->b + hr_ix(_i4048, _t4048->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:70"); })))), g0_1353));
 } } _bk4044:; 
 }
 }
if (((((*({ hrv *_t4050 = &(g543); int64_t _i4050 = t_1356; (S1*)_t4050->b + hr_ix(_i4050, _t4050->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:71"); }))).k_) == (((uint8_t)6LL)))) { int64_t ei_1360 = ((int64_t)(((*({ hrv *_t4051 = &(g543); int64_t _i4051 = t_1356; (S1*)_t4051->b + hr_ix(_i4051, _t4051->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:71"); }))).a_)); 
if (((((*({ hrv *_t4052 = &(g548); int64_t _i4052 = ei_1360; (S8*)_t4052->b + hr_ix(_i4052, _t4052->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:71"); }))).tn_) == ((x_1354).n_))) { { int32_t _e4054 = (x_1354).n_; for (int32_t _k4054 = 0; _k4054 < _e4054; _k4054++) { int32_t i_1361 = (int32_t)_k4054; (void)(f245_match_ty(f90_kid(tn0_1351, ((int64_t)(i_1361))), ((int64_t)((*({ hrv *_t4057 = &(g544); int64_t _i4057 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4058 = &(g548); int64_t _i4058 = ei_1360; (S8*)_t4058->b + hr_ix(_i4058, _t4058->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:71"); }))).ta_)) + (int64_t)((int64_t)(i_1361)))); (int32_t*)_t4057->b + hr_ix(_i4057, _t4057->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:71"); })))), g0_1353));
 } } _bk4053:; 
 }
 }
return true;
 }
if ((((k_1355) == (((int64_t)42LL))) || ((k_1355) == (((int64_t)43LL))))) { if ((((((*({ hrv *_t4059 = &(g543); int64_t _i4059 = t_1356; (S1*)_t4059->b + hr_ix(_i4059, _t4059->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:74"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t4060 = &(g543); int64_t _i4060 = t_1356; (S1*)_t4060->b + hr_ix(_i4060, _t4060->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:74"); }))).k_) == (((uint8_t)9LL))))) { return f245_match_ty(((int64_t)((x_1354).a_)), ((int64_t)(((*({ hrv *_t4062 = &(g543); int64_t _i4062 = t_1356; (S1*)_t4062->b + hr_ix(_i4062, _t4062->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:74"); }))).a_)), g0_1353);
 }
if (((((*({ hrv *_t4063 = &(g543); int64_t _i4063 = t_1356; (S1*)_t4063->b + hr_ix(_i4063, _t4063->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:74"); }))).k_) == (((uint8_t)18LL)))) { return f245_match_ty(((int64_t)((x_1354).a_)), g556, g0_1353);
 }
return true;
 }
if (((k_1355) == (((int64_t)44LL)))) { if (((((*({ hrv *_t4065 = &(g543); int64_t _i4065 = t0_1352; (S1*)_t4065->b + hr_ix(_i4065, _t4065->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:75"); }))).k_) == (((uint8_t)10LL)))) { return f245_match_ty(((int64_t)((x_1354).a_)), ((int64_t)(((*({ hrv *_t4067 = &(g543); int64_t _i4067 = t0_1352; (S1*)_t4067->b + hr_ix(_i4067, _t4067->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:75"); }))).a_)), g0_1353);
 }
return f245_match_ty(((int64_t)((x_1354).a_)), t_1356, g0_1353);
 }
if (((k_1355) == (((int64_t)48LL)))) { return f245_match_ty(((int64_t)((x_1354).a_)), t0_1352, g0_1353);
 }
return true;
}
static int64_t f246_pend_default(int64_t a_1366) {
int64_t k_1367 = ((int64_t)(((*({ hrv *_t4070 = &(g543); int64_t _i4070 = a_1366; (S1*)_t4070->b + hr_ix(_i4070, _t4070->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:247"); }))).k_)); 
return ({ int64_t _r4071; if (((k_1367) == (((int64_t)12LL)))) { _r4071 = g555;  } else { _r4071 = ({ int64_t _r4072; if (((k_1367) == (((int64_t)13LL)))) { _r4072 = g561;  } else { _r4072 = ({ int64_t _r4073; if (((k_1367) == (((int64_t)18LL)))) { _r4073 = g568;  } else { _r4073 = a_1366;  } _r4073; });  } _r4072; });  } _r4071; });
}
static int64_t f247_arg_rank(int64_t n_1379, int64_t a_1380, int64_t p_1381) {
if (((p_1381) < (((int64_t)0LL)))) { return ((int64_t)1LL);
 }
if (((a_1380) == (p_1381))) { return ((int64_t)0LL);
 }
int64_t ak_1382 = ((int64_t)(((*({ hrv *_t4074 = &(g543); int64_t _i4074 = a_1380; (S1*)_t4074->b + hr_ix(_i4074, _t4074->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:82"); }))).k_)); 
int64_t pk_1383 = ((int64_t)(((*({ hrv *_t4075 = &(g543); int64_t _i4075 = p_1381; (S1*)_t4075->b + hr_ix(_i4075, _t4075->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:82"); }))).k_)); 
if ((((pk_1383) == (((int64_t)0LL))) || ((ak_1382) == (((int64_t)0LL))))) { return ((int64_t)0LL);
 }
if (((((pk_1383) == (((int64_t)10LL))) && ((((*({ hrv *_t4076 = &(g543); int64_t _i4076 = p_1381; (S1*)_t4076->b + hr_ix(_i4076, _t4076->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:84"); }))).c_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4077 = &(g543); int64_t _i4077 = p_1381; (S1*)_t4077->b + hr_ix(_i4077, _t4077->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:84"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL))))) { int64_t tgt_1384 = ((int64_t)(((*({ hrv *_t4078 = &(g543); int64_t _i4078 = p_1381; (S1*)_t4078->b + hr_ix(_i4078, _t4078->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:84"); }))).a_)); 
if (((f179_deref(a_1380)) == (tgt_1384))) { return ((int64_t)0LL);
 }
if ((((ak_1382) == (((int64_t)12LL))) || ((ak_1382) == (((int64_t)13LL))))) { return f247_arg_rank(n_1379, a_1380, tgt_1384);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if ((((ak_1382) == (((int64_t)10LL))) && ((((*({ hrv *_t4081 = &(g543); int64_t _i4081 = a_1380; (S1*)_t4081->b + hr_ix(_i4081, _t4081->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:85"); }))).c_) < (((int32_t)0LL))))) { int64_t d_1385 = ((int64_t)(((*({ hrv *_t4082 = &(g543); int64_t _i4082 = a_1380; (S1*)_t4082->b + hr_ix(_i4082, _t4082->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:85"); }))).a_)); 
if (((d_1385) == (p_1381))) { return ((int64_t)0LL);
 }
if (((((pk_1383) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4083 = &(g543); int64_t _i4083 = p_1381; (S1*)_t4083->b + hr_ix(_i4083, _t4083->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:85"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && ((((*({ hrv *_t4084 = &(g543); int64_t _i4084 = p_1381; (S1*)_t4084->b + hr_ix(_i4084, _t4084->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:85"); }))).a_) == (((*({ hrv *_t4085 = &(g543); int64_t _i4085 = a_1380; (S1*)_t4085->b + hr_ix(_i4085, _t4085->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:85"); }))).a_)))) { return ((int64_t)0LL);
 }
return f247_arg_rank(n_1379, d_1385, p_1381);
 }
if (((ak_1382) == (((int64_t)12LL)))) { M78 _t4087 = f155_cval(n_1379); int64_t v_1386 = _t4087.r0; bool u_1387 = _t4087.r1; bool ok_1388 = _t4087.r2; 
if (((pk_1383) == (((int64_t)3LL)))) { if (((!(ok_1388)) || f158_int_fits(v_1386, u_1387, p_1381))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((pk_1383) == (((int64_t)4LL)))) { return ((int64_t)3LL);
 }
if (((pk_1383) == (((int64_t)17LL)))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1382) == (((int64_t)13LL)))) { if (((pk_1383) == (((int64_t)4LL)))) { return ({ int64_t _r4090; if (((((*({ hrv *_t4091 = &(g543); int64_t _i4091 = p_1381; (S1*)_t4091->b + hr_ix(_i4091, _t4091->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:93"); }))).s_) == (((uint8_t)8LL)))) { _r4090 = ((int64_t)1LL);  } else { _r4090 = ((int64_t)2LL);  } _r4090; });
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1382) == (((int64_t)18LL)))) { if ((((pk_1383) == (((int64_t)9LL))) && ((((int64_t)(((*({ hrv *_t4092 = &(g543); int64_t _i4092 = p_1381; (S1*)_t4092->b + hr_ix(_i4092, _t4092->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:94"); }))).a_))) == (g556)))) { return ((int64_t)0LL);
 }
if (f164_is_byte_arr(p_1381)) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1382) == (((int64_t)19LL)))) { if ((((pk_1383) == (((int64_t)8LL))) || ((pk_1383) == (((int64_t)9LL))))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1382) == (((int64_t)11LL)))) { if ((((pk_1383) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4094 = &(g543); int64_t _i4094 = p_1381; (S1*)_t4094->b + hr_ix(_i4094, _t4094->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:96"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { return ((int64_t)0LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((((pk_1383) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4095 = &(g543); int64_t _i4095 = p_1381; (S1*)_t4095->b + hr_ix(_i4095, _t4095->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:97"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && ((((int64_t)(((*({ hrv *_t4096 = &(g543); int64_t _i4096 = p_1381; (S1*)_t4096->b + hr_ix(_i4096, _t4096->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:97"); }))).a_))) == (a_1380)))) { return ((int64_t)0LL);
 }
if ((((ak_1382) == (((int64_t)3LL))) && ((pk_1383) == (((int64_t)4LL))))) { return ((int64_t)3LL);
 }
if (f152_widens(a_1380, p_1381)) { return ((int64_t)2LL);
 }
if (((((pk_1383) == (((int64_t)9LL))) && (((ak_1382) == (((int64_t)8LL))) || ((ak_1382) == (((int64_t)9LL))))) && ((((*({ hrv *_t4098 = &(g543); int64_t _i4098 = a_1380; (S1*)_t4098->b + hr_ix(_i4098, _t4098->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:100"); }))).a_) == (((*({ hrv *_t4099 = &(g543); int64_t _i4099 = p_1381; (S1*)_t4099->b + hr_ix(_i4099, _t4099->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:100"); }))).a_)))) { return ((int64_t)2LL);
 }
if (((((pk_1383) == (((int64_t)6LL))) && ((ak_1382) == (((int64_t)7LL)))) && ((((*({ hrv *_t4100 = &(g543); int64_t _i4100 = a_1380; (S1*)_t4100->b + hr_ix(_i4100, _t4100->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:101"); }))).a_) == (((*({ hrv *_t4101 = &(g543); int64_t _i4101 = p_1381; (S1*)_t4101->b + hr_ix(_i4101, _t4101->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:101"); }))).a_)))) { return ((int64_t)2LL);
 }
if ((((((pk_1383) == (((int64_t)8LL))) && (((ak_1382) == (((int64_t)8LL))) || ((ak_1382) == (((int64_t)9LL))))) && ((((*({ hrv *_t4102 = &(g543); int64_t _i4102 = a_1380; (S1*)_t4102->b + hr_ix(_i4102, _t4102->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:102"); }))).a_) == (((*({ hrv *_t4103 = &(g543); int64_t _i4103 = p_1381; (S1*)_t4103->b + hr_ix(_i4103, _t4103->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:102"); }))).a_))) && f248_is_construct(n_1379))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f248_is_construct(int64_t n_1389) {
int64_t k_1390 = ((int64_t)(((*({ hrv *_t4105 = &(g696); int64_t _i4105 = n_1389; (S4*)_t4105->b + hr_ix(_i4105, _t4105->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:186"); }))).k_)); 
return ((((k_1390) == (((int64_t)11LL))) || ((k_1390) == (((int64_t)16LL)))) || ((k_1390) == (((int64_t)3LL))));
}
static bool f249_untyped_any(int64_t f_1392) {
{ int32_t _e4107 = ((*({ hrv *_t4108 = &(g696); int64_t _i4108 = f_1392; (S4*)_t4108->b + hr_ix(_i4108, _t4108->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:245"); }))).n_; for (int32_t _k4107 = 0; _k4107 < _e4107; _k4107++) { int32_t j_1393 = (int32_t)_k4107; if (((((*({ hrv *_t4109 = &(g696); int64_t _i4109 = f90_kid(f_1392, ((int64_t)(j_1393))); (S4*)_t4109->b + hr_ix(_i4109, _t4109->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:245"); }))).a_) < (((int32_t)0LL)))) { return true;
 }
 } } _bk4106:; 
return false;
}
static int64_t f250_get_inst(int64_t node_1402, int64_t b0_1403, int64_t bn_1404, int64_t blk_1405, int64_t bown_1406) {
int64_t par_1407 = ({ int64_t _r4111; if (((((uint16_t)((uint64_t)((*({ hrv *_t4112 = &(g696); int64_t _i4112 = node_1402; (S4*)_t4112->b + hr_ix(_i4112, _t4112->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:177"); }))).fl_ & (uint64_t)((uint16_t)128LL)))) != (((uint16_t)0LL)))) { _r4111 = g393;  } else { _r4111 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r4111; }); 
if (((blk_1405) < (((int64_t)0LL)))) { { hrv *_v4114 = &(g380); for (int64_t _k4114 = 0; _k4114 < _v4114->n; _k4114++) { S6 f_1408 = ((S6*)_v4114->b)[_k4114]; int64_t i_1409 = (int64_t)_k4114; if ((((((((int64_t)((f_1408).node_))) == (node_1402)) && (((f_1408).blk_) < (((int32_t)0LL)))) && ((((int64_t)((f_1408).par_))) == (par_1407))) && f251_same_binds(i_1409, b0_1403, bn_1404))) { return i_1409;
 }
 } } _bk4113:; 
 }
int64_t i_1414 = f105_new_inst(node_1402, node_1402, ((int64_t)((*({ hrv *_t4117 = &(g711); int64_t _i4117 = node_1402; (int32_t*)_t4117->b + hr_ix(_i4117, _t4117->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:179"); })))), par_1407); 
{ int32_t *_t4118 = &(((*({ hrv *_t4119 = &(g380); int64_t _i4119 = i_1414; (S6*)_t4119->b + hr_ix(_i4119, _t4119->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:180"); }))).g0_); *_t4118 = ((int32_t)((g386).n)); }
{ int64_t _e4121 = bn_1404; for (int64_t _k4121 = 0; _k4121 < _e4121; _k4121++) { int64_t j_1415 = (int64_t)_k4121; (void)(({ hrv *_v4122 = &(g386); S7 _x4122 = (*({ hrv *_t4123 = &(g312); int64_t _i4123 = ((int64_t)((int64_t)b0_1403 + (int64_t)j_1415)); (S7*)_t4123->b + hr_ix(_i4123, _t4123->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:181"); })); S7 *_p4122 = (S7*)hr_grow(_v4122, 1, sizeof _x4122); *_p4122 = _x4122; _p4122; }));
 } } _bk4120:; 
{ int32_t *_t4124 = &(((*({ hrv *_t4125 = &(g380); int64_t _i4125 = i_1414; (S6*)_t4125->b + hr_ix(_i4125, _t4125->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:182"); }))).gn_); *_t4124 = ((int32_t)(bn_1404)); }
{ int32_t *_t4126 = &(((*({ hrv *_t4127 = &(g380); int64_t _i4127 = i_1414; (S6*)_t4127->b + hr_ix(_i4127, _t4127->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:183"); }))).blk_); *_t4126 = ((int32_t)(blk_1405)); }
{ int32_t *_t4128 = &(((*({ hrv *_t4129 = &(g380); int64_t _i4129 = i_1414; (S6*)_t4129->b + hr_ix(_i4129, _t4129->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:183"); }))).bown_); *_t4128 = ((int32_t)(bown_1406)); }
(void)(f195_sig_inst(i_1414));
(void)(f207_check_inst(i_1414));
return i_1414;
}
static bool f251_same_binds(int64_t i_1410, int64_t b0_1411, int64_t bn_1412) {
if (((((int64_t)(((*({ hrv *_t4132 = &(g380); int64_t _i4132 = i_1410; (S6*)_t4132->b + hr_ix(_i4132, _t4132->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:172"); }))).gn_))) != (bn_1412))) { return false;
 }
{ int64_t _e4134 = bn_1412; for (int64_t _k4134 = 0; _k4134 < _e4134; _k4134++) { int64_t j_1413 = (int64_t)_k4134; if ((((((*({ hrv *_t4135 = &(g386); int64_t _i4135 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4136 = &(g380); int64_t _i4136 = i_1410; (S6*)_t4136->b + hr_ix(_i4136, _t4136->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:173"); }))).g0_)) + (int64_t)j_1413)); (S7*)_t4135->b + hr_ix(_i4135, _t4135->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:173"); }))).ty_) != (((*({ hrv *_t4137 = &(g312); int64_t _i4137 = ((int64_t)((int64_t)b0_1411 + (int64_t)j_1413)); (S7*)_t4137->b + hr_ix(_i4137, _t4137->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:173"); }))).ty_)) || ((((*({ hrv *_t4138 = &(g386); int64_t _i4138 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4139 = &(g380); int64_t _i4139 = i_1410; (S6*)_t4139->b + hr_ix(_i4139, _t4139->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:173"); }))).g0_)) + (int64_t)j_1413)); (S7*)_t4138->b + hr_ix(_i4138, _t4138->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:173"); }))).name_) != (((*({ hrv *_t4140 = &(g312); int64_t _i4140 = ((int64_t)((int64_t)b0_1411 + (int64_t)j_1413)); (S7*)_t4140->b + hr_ix(_i4140, _t4140->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:173"); }))).name_)))) { return false;
 }
 } } _bk4133:; 
return true;
}
static int64_t f252_member_of(hsl name_1426) {
if (hr_streq(name_1426, hr_str("push", 4))) { return ((int64_t)20LL);
 }
if (hr_streq(name_1426, hr_str("append", 6))) { return ((int64_t)21LL);
 }
if (hr_streq(name_1426, hr_str("pop", 3))) { return ((int64_t)22LL);
 }
if (hr_streq(name_1426, hr_str("pop_n", 5))) { return ((int64_t)23LL);
 }
if (hr_streq(name_1426, hr_str("resize", 6))) { return ((int64_t)24LL);
 }
if (hr_streq(name_1426, hr_str("clear", 5))) { return ((int64_t)25LL);
 }
if (hr_streq(name_1426, hr_str("index_of", 8))) { return ((int64_t)26LL);
 }
if (hr_streq(name_1426, hr_str("len", 3))) { return ((int64_t)9LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f253_ck_slit(int64_t n_1429, int64_t want_1430) {
S4 x_1431 = (*({ hrv *_t4141 = &(g696); int64_t _i4141 = n_1429; (S4*)_t4141->b + hr_ix(_i4141, _t4141->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:416"); })); 
int64_t tnode_1432 = ((int64_t)((x_1431).a_)); 
int64_t ns_1433 = f110_ns_of(n_1429); 
int64_t t_1434 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((((*({ hrv *_t4143 = &(g696); int64_t _i4143 = tnode_1432; (S4*)_t4143->b + hr_ix(_i4143, _t4143->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:420"); }))).k_) == (((uint8_t)41LL))) && ((((*({ hrv *_t4144 = &(g696); int64_t _i4144 = tnode_1432; (S4*)_t4144->b + hr_ix(_i4144, _t4144->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:420"); }))).n_) == (((int32_t)0LL)))) && ((f130_gb_find(((int64_t)(((*({ hrv *_t4146 = &(g696); int64_t _i4146 = tnode_1432; (S4*)_t4146->b + hr_ix(_i4146, _t4146->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:420"); }))).s_)))) < (((int64_t)0LL))))) { int64_t d_1435 = f116_lookup_q(((int64_t)(((*({ hrv *_t4148 = &(g696); int64_t _i4148 = tnode_1432; (S4*)_t4148->b + hr_ix(_i4148, _t4148->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:421"); }))).s_)), ns_1433, ((int64_t)1LL)); 
if ((((d_1435) >= (((int64_t)0LL))) && ((((*({ hrv *_t4149 = &(g696); int64_t _i4149 = ((*({ hrv *_t4150 = &(g481); int64_t _i4150 = d_1435; (S5*)_t4150->b + hr_ix(_i4150, _t4150->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:422"); }))).node_; (S4*)_t4149->b + hr_ix(_i4149, _t4149->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:422"); }))).d_) >= (((int32_t)0LL))))) { if (((((want_1430) >= (((int64_t)0LL))) && ((((*({ hrv *_t4151 = &(g543); int64_t _i4151 = want_1430; (S1*)_t4151->b + hr_ix(_i4151, _t4151->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:422"); }))).k_) == (((uint8_t)5LL)))) && ((((*({ hrv *_t4152 = &(g546); int64_t _i4152 = ((*({ hrv *_t4153 = &(g543); int64_t _i4153 = want_1430; (S1*)_t4153->b + hr_ix(_i4153, _t4153->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:422"); }))).a_; (S10*)_t4152->b + hr_ix(_i4152, _t4152->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:422"); }))).node_) == (((*({ hrv *_t4154 = &(g481); int64_t _i4154 = d_1435; (S5*)_t4154->b + hr_ix(_i4154, _t4154->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:422"); }))).node_)))) { t_1434 = want_1430;
 }
 }
 }
if (((t_1434) < (((int64_t)0LL)))) { t_1434 = f113_rtype(tnode_1432, ns_1433);
 }
int64_t si_1436 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((*({ hrv *_t4156 = &(g543); int64_t _i4156 = t_1434; (S1*)_t4156->b + hr_ix(_i4156, _t4156->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:426"); }))).k_) == (((uint8_t)5LL)))) { si_1436 = ((int64_t)(((*({ hrv *_t4157 = &(g543); int64_t _i4157 = t_1434; (S1*)_t4157->b + hr_ix(_i4157, _t4157->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:426"); }))).a_));
 }
if (((((*({ hrv *_t4158 = &(g543); int64_t _i4158 = t_1434; (S1*)_t4158->b + hr_ix(_i4158, _t4158->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:427"); }))).k_) == (((uint8_t)7LL)))) { si_1436 = ((int64_t)(((*({ hrv *_t4159 = &(g549); int64_t _i4159 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4160 = &(g548); int64_t _i4160 = ((*({ hrv *_t4161 = &(g543); int64_t _i4161 = t_1434; (S1*)_t4161->b + hr_ix(_i4161, _t4161->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:427"); }))).a_; (S8*)_t4160->b + hr_ix(_i4160, _t4160->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:427"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t4162 = &(g543); int64_t _i4162 = t_1434; (S1*)_t4162->b + hr_ix(_i4162, _t4162->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:427"); }))).c_)))); (S9*)_t4159->b + hr_ix(_i4159, _t4159->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:427"); }))).si_));
 }
if (((si_1436) < (((int64_t)0LL)))) { if (((((*({ hrv *_t4163 = &(g543); int64_t _i4163 = t_1434; (S1*)_t4163->b + hr_ix(_i4163, _t4163->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:428"); }))).k_) != (((uint8_t)0LL)))) { (void)(f108_cerr(n_1429, hr_str("not a struct type", 17)));
 }
return f138_set_t(n_1429, g567);
 }
int64_t nf_1437 = ((int64_t)(((*({ hrv *_t4166 = &(g546); int64_t _i4166 = si_1436; (S10*)_t4166->b + hr_ix(_i4166, _t4166->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:429"); }))).fnum_)); 
bool named_1438 = ((((x_1431).n_) > (((int32_t)0LL))) && ((((*({ hrv *_t4167 = &(g696); int64_t _i4167 = f90_kid(n_1429, ((int64_t)0LL)); (S4*)_t4167->b + hr_ix(_i4167, _t4167->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:430"); }))).s_) >= (((int32_t)0LL)))); 
int64_t fpos_1439 = ((int64_t)0LL); 
{ int32_t _e4170 = (x_1431).n_; for (int32_t _k4170 = 0; _k4170 < _e4170; _k4170++) { int32_t i_1440 = (int32_t)_k4170; int64_t fi_1441 = f90_kid(n_1429, ((int64_t)(i_1440))); 
int64_t idx_1442 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (named_1438) { idx_1442 = f187_sfield(si_1436, ((int64_t)(((*({ hrv *_t4173 = &(g696); int64_t _i4173 = fi_1441; (S4*)_t4173->b + hr_ix(_i4173, _t4173->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:435"); }))).s_)));
if (((idx_1442) < (((int64_t)0LL)))) { hrv m_1443 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t4178 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o4175 = &(m_1443); hr_fs(_o4175, hr_str("no field ", 9)); hr_fs(_o4175, f10_nm(((int64_t)(((*({ hrv *_t4177 = &(g696); int64_t _i4177 = fi_1441; (S4*)_t4177->b + hr_ix(_i4177, _t4177->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:435"); }))).s_)))); hr_fs(_o4175, hr_str(" in ", 4)); hr_fs(_o4175, hr_sl(*hr_tmp(&_t4178, f161_tn(t_1434)))); }));
}
(void)(f108_cerr(fi_1441, hr_sl(m_1443)));
continue;
 }
 } else { while ((((fpos_1439) < (nf_1437)) && ((((*({ hrv *_t4182 = &(g547); int64_t _i4182 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4183 = &(g546); int64_t _i4183 = si_1436; (S10*)_t4183->b + hr_ix(_i4183, _t4183->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:436"); }))).f0_)) + (int64_t)fpos_1439)); (S11*)_t4182->b + hr_ix(_i4182, _t4182->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:436"); }))).ty_) < (((int32_t)0LL))))) { fpos_1439++;
 } _bk4181:; 
idx_1442 = fpos_1439;
fpos_1439++;
if (((idx_1442) >= (nf_1437))) { (void)(f108_cerr(fi_1441, hr_str("too many initializers", 21)));
continue;
 }
 }
int64_t ft_1444 = ((int64_t)(((*({ hrv *_t4185 = &(g547); int64_t _i4185 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4186 = &(g546); int64_t _i4186 = si_1436; (S10*)_t4186->b + hr_ix(_i4186, _t4186->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:437"); }))).f0_)) + (int64_t)idx_1442)); (S11*)_t4185->b + hr_ix(_i4185, _t4185->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:437"); }))).ty_)); 
(void)(f170_set_r(fi_1441, ((int64_t)5LL), idx_1442));
int64_t v_1445 = ((int64_t)(((*({ hrv *_t4188 = &(g696); int64_t _i4188 = fi_1441; (S4*)_t4188->b + hr_ix(_i4188, _t4188->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:439"); }))).a_)); 
(void)(f137_ck(v_1445, ft_1444));
(void)(f140_conv(v_1445, ft_1444));
 } } _bk4169:; 
{ int64_t _e4192 = nf_1437; for (int64_t _k4192 = 0; _k4192 < _e4192; _k4192++) { int64_t j_1446 = (int64_t)_k4192; S11 f_1447 = (*({ hrv *_t4193 = &(g547); int64_t _i4193 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4194 = &(g546); int64_t _i4194 = si_1436; (S10*)_t4194->b + hr_ix(_i4194, _t4194->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:443"); }))).f0_)) + (int64_t)j_1446)); (S11*)_t4193->b + hr_ix(_i4193, _t4193->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:443"); })); 
if ((((f_1447).ty_) < (((int32_t)0LL)))) { continue;
 }
bool given_1448 = false; 
{ int32_t _e4196 = (x_1431).n_; for (int32_t _k4196 = 0; _k4196 < _e4196; _k4196++) { int32_t i_1449 = (int32_t)_k4196; if (((f157_rv(f90_kid(n_1429, ((int64_t)(i_1449))))) == (j_1446))) { given_1448 = true;
 }
 } } _bk4195:; 
if (((!(given_1448)) && (((f_1447).def_) >= (((int32_t)0LL))))) { int64_t sa_1450 = g393; 
g393 = g395;
(void)(f137_ck(((int64_t)((f_1447).def_)), ((int64_t)((f_1447).ty_))));
(void)(f140_conv(((int64_t)((f_1447).def_)), ((int64_t)((f_1447).ty_))));
g393 = sa_1450;
 }
if (((((!(given_1448)) && (((f_1447).def_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)(x_1431).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) && (!(f165_is_opt(((int64_t)((f_1447).ty_))))))) { hrv m_1451 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t4205 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o4203 = &(m_1451); hr_fs(_o4203, hr_str("missing field ", 14)); hr_fs(_o4203, f10_nm(((int64_t)((f_1447).name_)))); hr_fs(_o4203, hr_str(" in ", 4)); hr_fs(_o4203, hr_sl(*hr_tmp(&_t4205, f161_tn(t_1434)))); }));
}
(void)(f108_cerr(n_1429, hr_sl(m_1451)));
 }
 } } _bk4191:; 
(void)(f170_set_r(n_1429, ((int64_t)9LL), si_1436));
return f138_set_t(n_1429, t_1434);
}
static bool f254_ORD_HAS(int64_t d_1453) {
{ hrv *_v4211 = &(g401); for (int64_t _k4211 = 0; _k4211 < _v4211->n; _k4211++) { int32_t o_1454 = ((int32_t*)_v4211->b)[_k4211]; if (((((int64_t)(o_1454))) == (d_1453))) { return true;
 }
 } } _bk4210:; 
return false;
}
static void f255_propagate_calls(void) {
bool changed_1458 = true; 
while (changed_1458) { changed_1458 = false;
{ hrv *_v4214 = &(g385); for (int64_t _k4214 = 0; _k4214 < _v4214->n; _k4214++) { S15 e_1459 = ((S15*)_v4214->b)[_k4214]; int64_t cr_1460 = ((int64_t)((e_1459).caller_)); 
int64_t ce_1461 = ((int64_t)((e_1459).callee_)); 
if ((((*({ hrv *_t4215 = &(g380); int64_t _i4215 = ce_1461; (S6*)_t4215->b + hr_ix(_i4215, _t4215->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:42"); }))).lr_ && (!(((*({ hrv *_t4216 = &(g380); int64_t _i4216 = cr_1460; (S6*)_t4216->b + hr_ix(_i4216, _t4216->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:42"); }))).lr_)))) { { bool *_t4217 = &(((*({ hrv *_t4218 = &(g380); int64_t _i4218 = cr_1460; (S6*)_t4218->b + hr_ix(_i4218, _t4218->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:42"); }))).lr_); *_t4217 = true; }
changed_1458 = true;
 }
{ hrv *_v4220 = &(g384); for (int64_t _k4220 = 0; _k4220 < _v4220->n; _k4220++) { S13 c_1462 = ((S13*)_v4220->b)[_k4220]; if (((((int64_t)((c_1462).inst_))) == (ce_1461))) { int64_t v_1463 = ((int64_t)((c_1462).lv_)); 
if ((f169_visible_in(((int64_t)(((*({ hrv *_t4222 = &(g381); int64_t _i4222 = v_1463; (S12*)_t4222->b + hr_ix(_i4222, _t4222->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:43"); }))).own_)), cr_1460) || ((((int64_t)(((*({ hrv *_t4223 = &(g381); int64_t _i4223 = v_1463; (S12*)_t4223->b + hr_ix(_i4223, _t4223->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:43"); }))).cfn_))) != (cr_1460)))) { if (f172_add_cap_one(cr_1460, v_1463)) { changed_1458 = true;
 }
 }
 }
 } } _bk4219:; 
 } } _bk4213:; 
 } _bk4212:; 
}
static bool f256_gen_program(hrv* out_1465) {
(void)(({ hrv *_v4225 = &(g163); _v4225->n = 0; }));
{ hrv *_v4227 = &(g380); for (int64_t _k4227 = 0; _k4227 < _v4227->n; _k4227++) { S6 f_1466 = ((S6*)_v4227->b)[_k4227]; int64_t i_1467 = (int64_t)_k4227; if ((((f_1466).tg_ && (((f_1466).ret_) >= (((int32_t)0LL)))) && ((((int64_t)((f_1466).ret_))) != (g550)))) { int64_t sv_1468 = (g163).n; 
(void)(f257_ow(hr_str("static __thread ", 16)));
(void)(f258_ct(((int64_t)((f_1466).ret_))));
(void)(({ hrv *_o4230 = &(g163); hr_fs(_o4230, hr_str(" _lrv", 5)); hr_fi(_o4230, i_1467); hr_fs(_o4230, hr_str(";\012", 2)); }));
(void)(({ hrv *_v4231 = &(g167); hsl _s4231 = ({ hsl _t4232 = hr_sl(g163); int64_t _l4232 = sv_1468, _h4232 = _t4232.n; if (_l4232 < 0 || _h4232 < _l4232 || _h4232 > _t4232.n) hr_slerr(_l4232, _h4232, _t4232.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1086"); (hsl){ _t4232.p + _l4232 * (int64_t)sizeof(uint8_t), _h4232 - _l4232 }; }); hr_append(_v4231, _s4231.p, _s4231.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4233 = &(g163); int64_t _k4233 = sv_1468; if (_k4233 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1086"); hr_resize(_v4233, _k4233, sizeof(uint8_t)); }));
 }
 } } _bk4226:; 
{ hrv *_v4235 = &(g401); for (int64_t _k4235 = 0; _k4235 < _v4235->n; _k4235++) { int32_t d_1509 = ((int32_t*)_v4235->b)[_k4235]; int64_t di_1510 = ((int64_t)(d_1509)); 
int64_t t_1511 = ((int64_t)((*({ hrv *_t4236 = &(g442); int64_t _i4236 = di_1510; (int32_t*)_t4236->b + hr_ix(_i4236, _t4236->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1089"); })))); 
int64_t g_1512 = ((int64_t)(((*({ hrv *_t4237 = &(g481); int64_t _i4237 = di_1510; (S5*)_t4237->b + hr_ix(_i4237, _t4237->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1090"); }))).node_)); 
if ((((f173_const_of(di_1510)) >= (((int64_t)0LL))) && ((((*({ hrv *_t4239 = &(g543); int64_t _i4239 = t_1511; (S1*)_t4239->b + hr_ix(_i4239, _t4239->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1091"); }))).k_) == (((uint8_t)12LL))))) { continue;
 }
int64_t sv_1513 = (g163).n; 
g393 = g395;
g179 = g395;
(void)(f257_ow(hr_str("static ", 7)));
(void)(f258_ct(t_1511));
(void)(({ hrv *_o4242 = &(g163); hr_fs(_o4242, hr_str(" g", 2)); hr_fi(_o4242, di_1510); hr_fs(_o4242, hr_str(";\012", 2)); }));
(void)(({ hrv *_v4243 = &(g167); hsl _s4243 = ({ hsl _t4244 = hr_sl(g163); int64_t _l4244 = sv_1513, _h4244 = _t4244.n; if (_l4244 < 0 || _h4244 < _l4244 || _h4244 > _t4244.n) hr_slerr(_l4244, _h4244, _t4244.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1095"); (hsl){ _t4244.p + _l4244 * (int64_t)sizeof(uint8_t), _h4244 - _l4244 }; }); hr_append(_v4243, _s4243.p, _s4243.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4245 = &(g163); int64_t _k4245 = sv_1513; if (_k4245 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1095"); hr_resize(_v4245, _k4245, sizeof(uint8_t)); }));
S4 x_1514 = (*({ hrv *_t4246 = &(g696); int64_t _i4246 = g_1512; (S4*)_t4246->b + hr_ix(_i4246, _t4246->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1096"); })); 
if ((((x_1514).b_) >= (((int32_t)0LL)))) { int64_t iv_1515 = f90_kid(((int64_t)((x_1514).b_)), ((int64_t)0LL)); 
int64_t sp_1516 = (g163).n; 
(void)(({ hrv *_o4248 = &(g163); hr_fs(_o4248, hr_str("g", 1)); hr_fi(_o4248, di_1510); hr_fs(_o4248, hr_str(" = ", 3)); }));
if (f265_is_res(t_1511)) { (void)(f266_gxo(iv_1515));
 } else { (void)(f286_gx(iv_1515));
 }
(void)(f257_ow(hr_str(";\012", 2)));
if ((((g176).n) > (((int64_t)0LL)))) { (void)(({ hrv *_v4253 = &(g177); _v4253->n = 0; }));
(void)(({ hrv *_v4254 = &(g177); hsl _s4254 = ({ hsl _t4255 = hr_sl(g163); int64_t _l4255 = sp_1516, _h4255 = _t4255.n; if (_l4255 < 0 || _h4255 < _l4255 || _h4255 > _t4255.n) hr_slerr(_l4255, _h4255, _t4255.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1103"); (hsl){ _t4255.p + _l4255 * (int64_t)sizeof(uint8_t), _h4255 - _l4255 }; }); hr_append(_v4254, _s4254.p, _s4254.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4256 = &(g163); int64_t _k4256 = sp_1516; if (_k4256 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1103"); hr_resize(_v4256, _k4256, sizeof(uint8_t)); }));
(void)(f257_ow(hr_str("{ ", 2)));
(void)(({ hrv *_v4258 = &(g163); hsl _s4258 = ({ hsl _t4259 = hr_sl(g176); int64_t _l4259 = 0, _h4259 = _t4259.n; if (_l4259 < 0 || _h4259 < _l4259 || _h4259 > _t4259.n) hr_slerr(_l4259, _h4259, _t4259.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1103"); (hsl){ _t4259.p + _l4259 * (int64_t)sizeof(uint8_t), _h4259 - _l4259 }; }); hr_append(_v4258, _s4258.p, _s4258.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4260 = &(g176); _v4260->n = 0; }));
(void)(({ hrv *_v4261 = &(g163); hsl _s4261 = ({ hsl _t4262 = hr_sl(g177); int64_t _l4262 = 0, _h4262 = _t4262.n; if (_l4262 < 0 || _h4262 < _l4262 || _h4262 > _t4262.n) hr_slerr(_l4262, _h4262, _t4262.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1103"); (hsl){ _t4262.p + _l4262 * (int64_t)sizeof(uint8_t), _h4262 - _l4262 }; }); hr_append(_v4261, _s4261.p, _s4261.n, sizeof(uint8_t)); }));
(void)(f257_ow(hr_str("}\012", 2)));
 }
(void)(({ hrv *_v4264 = &(g168); hsl _s4264 = ({ hsl _t4265 = hr_sl(g163); int64_t _l4265 = sp_1516, _h4265 = _t4265.n; if (_l4265 < 0 || _h4265 < _l4265 || _h4265 > _t4265.n) hr_slerr(_l4265, _h4265, _t4265.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1104"); (hsl){ _t4265.p + _l4265 * (int64_t)sizeof(uint8_t), _h4265 - _l4265 }; }); hr_append(_v4264, _s4264.p, _s4264.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4266 = &(g163); int64_t _k4266 = sp_1516; if (_k4266 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1104"); hr_resize(_v4266, _k4266, sizeof(uint8_t)); }));
 }
 } } _bk4234:; 
int64_t mi_2036 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v4268 = &(g380); for (int64_t _k4268 = 0; _k4268 < _v4268->n; _k4268++) { S6 f_2037 = ((S6*)_v4268->b)[_k4268]; int64_t i_2038 = (int64_t)_k4268; if (((((f_2037).node_) < (((int32_t)0LL))) || (((f_2037).st_) != (((uint8_t)2LL))))) { continue;
 }
int64_t node_2039 = ((int64_t)((f_2037).node_)); 
if ((((((*({ hrv *_t4269 = &(g696); int64_t _i4269 = node_2039; (S4*)_t4269->b + hr_ix(_i4269, _t4269->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1111"); }))).k_) != (((uint8_t)50LL))) || ((((uint16_t)((uint64_t)((*({ hrv *_t4270 = &(g696); int64_t _i4270 = node_2039; (S4*)_t4270->b + hr_ix(_i4270, _t4270->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1111"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))))) { continue;
 }
if (((((f_2037).par_) < (((int32_t)0LL))) && hr_streq(f10_nm(((int64_t)((f_2037).name_))), hr_str("main", 4)))) { mi_2036 = i_2038;
 }
(void)(f357_gen_fn(i_2038));
if ((((g182).n) > (((int64_t)0LL)))) { return false;
 }
 } } _bk4267:; 
(void)(({ hrv *_v4273 = out_1465; hsl _s4273 = hr_str("#include \"hrt.h\"\012", 17); hr_append(_v4273, _s4273.p, _s4273.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4274 = out_1465; hsl _s4274 = hr_sl(g164); hr_append(_v4274, _s4274.p, _s4274.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4275 = out_1465; hsl _s4275 = hr_str("#pragma pack(push, 1)\012", 22); hr_append(_v4275, _s4275.p, _s4275.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4276 = out_1465; hsl _s4276 = hr_sl(g165); hr_append(_v4276, _s4276.p, _s4276.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4277 = out_1465; hsl _s4277 = hr_str("#pragma pack(pop)\012", 18); hr_append(_v4277, _s4277.p, _s4277.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4278 = out_1465; hsl _s4278 = hr_sl(g166); hr_append(_v4278, _s4278.p, _s4278.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4279 = out_1465; hsl _s4279 = hr_sl(g167); hr_append(_v4279, _s4279.p, _s4279.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4280 = out_1465; hsl _s4280 = ({ hsl _t4281 = hr_sl(g169); int64_t _l4281 = 0, _h4281 = _t4281.n; if (_l4281 < 0 || _h4281 < _l4281 || _h4281 > _t4281.n) hr_slerr(_l4281, _h4281, _t4281.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1123"); (hsl){ _t4281.p + _l4281 * (int64_t)sizeof(uint8_t), _h4281 - _l4281 }; }); hr_append(_v4280, _s4280.p, _s4280.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4282 = out_1465; hsl _s4282 = ({ hsl _t4283 = hr_sl(g163); int64_t _l4283 = 0, _h4283 = _t4283.n; if (_l4283 < 0 || _h4283 < _l4283 || _h4283 > _t4283.n) hr_slerr(_l4283, _h4283, _t4283.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1124"); (hsl){ _t4283.p + _l4283 * (int64_t)sizeof(uint8_t), _h4283 - _l4283 }; }); hr_append(_v4282, _s4282.p, _s4282.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4284 = out_1465; hsl _s4284 = hr_str("static void hr_init_globals(void) {\012", 36); hr_append(_v4284, _s4284.p, _s4284.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4285 = out_1465; hsl _s4285 = hr_sl(g168); hr_append(_v4285, _s4285.p, _s4285.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4286 = out_1465; hsl _s4286 = hr_str("}\012", 2); hr_append(_v4286, _s4286.p, _s4286.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4287 = out_1465; hsl _s4287 = hr_str("static void hr_main(void) { ", 28); hr_append(_v4287, _s4287.p, _s4287.n, sizeof(uint8_t)); }));
if (((mi_2036) >= (((int64_t)0LL)))) { int64_t rt_2063 = ((int64_t)(((*({ hrv *_t4288 = &(g380); int64_t _i4288 = mi_2036; (S6*)_t4288->b + hr_ix(_i4288, _t4288->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1127"); }))).ret_)); 
if ((((rt_2063) >= (((int64_t)0LL))) && ((((*({ hrv *_t4289 = &(g543); int64_t _i4289 = rt_2063; (S1*)_t4289->b + hr_ix(_i4289, _t4289->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1127"); }))).k_) == (((uint8_t)3LL))))) { (void)(({ hrv *_v4290 = out_1465; hsl _s4290 = hr_str("hr_flush(); exit((int)", 22); hr_append(_v4290, _s4290.p, _s4290.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4291 = &(g163); _v4291->n = 0; }));
(void)(f353_fn_cname(mi_2036));
(void)(({ hrv *_v4293 = out_1465; hsl _s4293 = ({ hsl _t4294 = hr_sl(g163); int64_t _l4294 = 0, _h4294 = _t4294.n; if (_l4294 < 0 || _h4294 < _l4294 || _h4294 > _t4294.n) hr_slerr(_l4294, _h4294, _t4294.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1127"); (hsl){ _t4294.p + _l4294 * (int64_t)sizeof(uint8_t), _h4294 - _l4294 }; }); hr_append(_v4293, _s4293.p, _s4293.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4295 = out_1465; hsl _s4295 = hr_str("()", 2); hr_append(_v4295, _s4295.p, _s4295.n, sizeof(uint8_t)); }));
if ((((rt_2063) >= (((int64_t)0LL))) && ((((*({ hrv *_t4296 = &(g543); int64_t _i4296 = rt_2063; (S1*)_t4296->b + hr_ix(_i4296, _t4296->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1127"); }))).k_) == (((uint8_t)3LL))))) { (void)(({ hrv *_v4297 = out_1465; hsl _s4297 = hr_str(")", 1); hr_append(_v4297, _s4297.p, _s4297.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4298 = out_1465; hsl _s4298 = hr_str("; ", 2); hr_append(_v4298, _s4298.p, _s4298.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4299 = out_1465; hsl _s4299 = hr_str("}\012", 2); hr_append(_v4299, _s4299.p, _s4299.n, sizeof(uint8_t)); }));
return (((g182).n) == (((int64_t)0LL)));
}
static void f257_ow(hsl s_1469) {
(void)(({ hrv *_v4300 = &(g163); hsl _s4300 = s_1469; hr_append(_v4300, _s4300.p, _s4300.n, sizeof(uint8_t)); }));
}
static void f258_ct(int64_t t_1470) {
(void)(f259_cbody(t_1470));
(void)(f257_ow(f261_cn(t_1470)));
}
static void f259_cbody(int64_t t_1471) {
(void)(f260_cn_grow());
S1 x_1472 = (*({ hrv *_t4305 = &(g543); int64_t _i4305 = t_1471; (S1*)_t4305->b + hr_ix(_i4305, _t4305->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:51"); })); 
int64_t k_1473 = ((int64_t)((x_1472).k_)); 
if ((((k_1473) == (((int64_t)10LL))) || (((*({ hrv *_t4306 = &(g173); int64_t _i4306 = t_1471; (uint8_t*)_t4306->b + hr_ix(_i4306, _t4306->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:52"); }))) != (((uint8_t)0LL))))) { (void)(f261_cn(t_1471));
return;
 }
{ uint8_t *_t4308 = &((*({ hrv *_t4309 = &(g173); int64_t _i4309 = t_1471; (uint8_t*)_t4309->b + hr_ix(_i4309, _t4309->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:53"); }))); *_t4308 = ((uint8_t)1LL); }
(void)(f261_cn(t_1471));
if (((k_1473) == (((int64_t)7LL)))) { S9 v_1487 = (*({ hrv *_t4311 = &(g549); int64_t _i4311 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4312 = &(g548); int64_t _i4312 = (x_1472).a_; (S8*)_t4312->b + hr_ix(_i4312, _t4312->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:55"); }))).v0_)) + (int64_t)((int64_t)((x_1472).c_)))); (S9*)_t4311->b + hr_ix(_i4311, _t4311->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:55"); })); 
if ((((v_1487).si_) >= (((int32_t)0LL)))) { (void)(f259_cbody(f134_t_struct(((int64_t)((v_1487).si_)))));
 }
return;
 }
if (((k_1473) == (((int64_t)5LL)))) { int64_t si_1488 = ((int64_t)((x_1472).a_)); 
(void)(f144_si_layout(si_1488));
int64_t f0_1489 = ((int64_t)(((*({ hrv *_t4316 = &(g546); int64_t _i4316 = si_1488; (S10*)_t4316->b + hr_ix(_i4316, _t4316->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:58"); }))).f0_)); 
int64_t fnum_1490 = ((int64_t)(((*({ hrv *_t4317 = &(g546); int64_t _i4317 = si_1488; (S10*)_t4317->b + hr_ix(_i4317, _t4317->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:58"); }))).fnum_)); 
{ int64_t _e4319 = fnum_1490; for (int64_t _k4319 = 0; _k4319 < _e4319; _k4319++) { int64_t i_1491 = (int64_t)_k4319; int32_t ft_1492 = ((*({ hrv *_t4320 = &(g547); int64_t _i4320 = ((int64_t)((int64_t)f0_1489 + (int64_t)i_1491)); (S11*)_t4320->b + hr_ix(_i4320, _t4320->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:59"); }))).ty_; 
if (((ft_1492) >= (((int32_t)0LL)))) { (void)(f259_cbody(((int64_t)(ft_1492))));
 }
 } } _bk4318:; 
(void)(({ hrv *_v4322 = &(g165); hsl _s4322 = hr_str("struct ", 7); hr_append(_v4322, _s4322.p, _s4322.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4323 = &(g165); hsl _s4323 = f261_cn(t_1471); hr_append(_v4323, _s4323.p, _s4323.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4325 = &(g165); hsl _s4325 = hr_str(" { ", 3); hr_append(_v4325, _s4325.p, _s4325.n, sizeof(uint8_t)); }));
bool any_1493 = false; 
{ int64_t _e4327 = fnum_1490; for (int64_t _k4327 = 0; _k4327 < _e4327; _k4327++) { int64_t i_1494 = (int64_t)_k4327; S11 f_1495 = (*({ hrv *_t4328 = &(g547); int64_t _i4328 = ((int64_t)((int64_t)f0_1489 + (int64_t)i_1494)); (S11*)_t4328->b + hr_ix(_i4328, _t4328->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:63"); })); 
if ((((f_1495).ty_) < (((int32_t)0LL)))) { if ((((f_1495).padn_) > (((int32_t)0LL)))) { (void)(({ hrv *_o4329 = &(g165); hr_fs(_o4329, hr_str("uint8_t _p", 10)); hr_fi(_o4329, i_1494); hr_fs(_o4329, hr_str("[", 1)); hr_fi(_o4329, (f_1495).padn_); hr_fs(_o4329, hr_str("]; ", 3)); }));
any_1493 = true;
 }
continue;
 }
(void)(({ hrv *_v4330 = &(g165); hsl _s4330 = f261_cn(((int64_t)((f_1495).ty_))); hr_append(_v4330, _s4330.p, _s4330.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4332 = &(g165); uint8_t _x4332 = ((uint8_t)32LL); uint8_t *_p4332 = (uint8_t*)hr_grow(_v4332, 1, sizeof _x4332); *_p4332 = _x4332; _p4332; }));
(void)(f264_fname_into((&(g165)), ((int64_t)((f_1495).name_))));
(void)(({ hrv *_v4334 = &(g165); hsl _s4334 = hr_str("; ", 2); hr_append(_v4334, _s4334.p, _s4334.n, sizeof(uint8_t)); }));
any_1493 = true;
 } } _bk4326:; 
if ((!(any_1493))) { (void)(({ hrv *_v4335 = &(g165); hsl _s4335 = hr_str("uint8_t _e; ", 12); hr_append(_v4335, _s4335.p, _s4335.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4336 = &(g165); hsl _s4336 = hr_str("};\012", 3); hr_append(_v4336, _s4336.p, _s4336.n, sizeof(uint8_t)); }));
return;
 }
if (((k_1473) == (((int64_t)6LL)))) { int64_t ei_1499 = ((int64_t)((x_1472).a_)); 
(void)(f146_ei_layout(ei_1499));
int64_t v0_1500 = ((int64_t)(((*({ hrv *_t4338 = &(g548); int64_t _i4338 = ei_1499; (S8*)_t4338->b + hr_ix(_i4338, _t4338->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:73"); }))).v0_)); 
bool pay_1501 = false; 
{ int32_t _e4340 = ((*({ hrv *_t4341 = &(g548); int64_t _i4341 = ei_1499; (S8*)_t4341->b + hr_ix(_i4341, _t4341->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:75"); }))).vnum_; for (int32_t _k4340 = 0; _k4340 < _e4340; _k4340++) { int32_t i_1502 = (int32_t)_k4340; S9 v_1503 = (*({ hrv *_t4342 = &(g549); int64_t _i4342 = ((int64_t)((int64_t)v0_1500 + (int64_t)((int64_t)(i_1502)))); (S9*)_t4342->b + hr_ix(_i4342, _t4342->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:75"); })); 
if (((((v_1503).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4343 = &(g546); int64_t _i4343 = (v_1503).si_; (S10*)_t4343->b + hr_ix(_i4343, _t4343->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:75"); }))).zero_)))) { (void)(f259_cbody(f134_t_struct(((int64_t)((v_1503).si_)))));
pay_1501 = true;
 }
 } } _bk4339:; 
(void)(({ hrv *_v4346 = &(g165); hsl _s4346 = hr_str("struct ", 7); hr_append(_v4346, _s4346.p, _s4346.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4347 = &(g165); hsl _s4347 = f261_cn(t_1471); hr_append(_v4347, _s4347.p, _s4347.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4349 = &(g165); hsl _s4349 = ({ hsl _r4350; if (((((*({ hrv *_t4351 = &(g548); int64_t _i4351 = ei_1499; (S8*)_t4351->b + hr_ix(_i4351, _t4351->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:76"); }))).tagsz_) == (((uint8_t)1LL)))) { _r4350 = hr_str(" { uint8_t tag; ", 16);  } else { _r4350 = hr_str(" { uint16_t tag; ", 17);  } _r4350; }); hr_append(_v4349, _s4349.p, _s4349.n, sizeof(uint8_t)); }));
if (pay_1501) { (void)(({ hrv *_v4352 = &(g165); hsl _s4352 = hr_str("union { ", 8); hr_append(_v4352, _s4352.p, _s4352.n, sizeof(uint8_t)); }));
{ int32_t _e4354 = ((*({ hrv *_t4355 = &(g548); int64_t _i4355 = ei_1499; (S8*)_t4355->b + hr_ix(_i4355, _t4355->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:77"); }))).vnum_; for (int32_t _k4354 = 0; _k4354 < _e4354; _k4354++) { int32_t i_1504 = (int32_t)_k4354; S9 v_1505 = (*({ hrv *_t4356 = &(g549); int64_t _i4356 = ((int64_t)((int64_t)v0_1500 + (int64_t)((int64_t)(i_1504)))); (S9*)_t4356->b + hr_ix(_i4356, _t4356->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:77"); })); 
if (((((v_1505).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4357 = &(g546); int64_t _i4357 = (v_1505).si_; (S10*)_t4357->b + hr_ix(_i4357, _t4357->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:77"); }))).zero_)))) { (void)(({ hrv *_v4358 = &(g165); hsl _s4358 = f261_cn(f134_t_struct(((int64_t)((v_1505).si_)))); hr_append(_v4358, _s4358.p, _s4358.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4361 = &(g165); hr_fs(_o4361, hr_str(" v", 2)); hr_fi(_o4361, i_1504); hr_fs(_o4361, hr_str("; ", 2)); }));
 }
 } } _bk4353:; 
(void)(({ hrv *_v4362 = &(g165); hsl _s4362 = hr_str("} u; ", 5); hr_append(_v4362, _s4362.p, _s4362.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4363 = &(g165); hsl _s4363 = hr_str("};\012", 3); hr_append(_v4363, _s4363.p, _s4363.n, sizeof(uint8_t)); }));
return;
 }
if (((k_1473) == (((int64_t)8LL)))) { int64_t a_1506 = ((int64_t)((x_1472).s_)); 
if ((((a_1506) == (((int64_t)1LL))) || (((a_1506) == (((int64_t)3LL))) && (((x_1472).b_) >= (((int64_t)0LL)))))) { (void)(f259_cbody(((int64_t)((x_1472).a_))));
(void)(({ hrv *_v4365 = &(g165); hsl _s4365 = hr_str("struct ", 7); hr_append(_v4365, _s4365.p, _s4365.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4366 = &(g165); hsl _s4366 = f261_cn(t_1471); hr_append(_v4366, _s4366.p, _s4366.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4368 = &(g165); hsl _s4368 = hr_str(" { ", 3); hr_append(_v4368, _s4368.p, _s4368.n, sizeof(uint8_t)); }));
if (((a_1506) == (((int64_t)3LL)))) { (void)(({ hrv *_v4369 = &(g165); hsl _s4369 = (g183).e[hr_ix(((int64_t)((int64_t)f124_lim_lenstore((x_1472).b_) & (int64_t)((int64_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:86")]; hr_append(_v4369, _s4369.p, _s4369.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4372 = &(g165); hsl _s4372 = hr_str(" n; ", 4); hr_append(_v4372, _s4372.p, _s4372.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4373 = &(g165); hsl _s4373 = f261_cn(((int64_t)((x_1472).a_))); hr_append(_v4373, _s4373.p, _s4373.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4375 = &(g165); hr_fs(_o4375, hr_str(" e[", 3)); hr_fi(_o4375, f103_max((x_1472).b_, ((int64_t)1LL))); hr_fs(_o4375, hr_str("]; };\012", 6)); }));
 }
return;
 }
if (((k_1473) == (((int64_t)14LL)))) { { int32_t _e4378 = (x_1472).n_; for (int32_t _k4378 = 0; _k4378 < _e4378; _k4378++) { int32_t i_1507 = (int32_t)_k4378; (void)(f259_cbody(((int64_t)((*({ hrv *_t4380 = &(g544); int64_t _i4380 = ((int64_t)((int64_t)((int64_t)((x_1472).l_)) + (int64_t)((int64_t)(i_1507)))); (int32_t*)_t4380->b + hr_ix(_i4380, _t4380->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:92"); }))))));
 } } _bk4377:; 
(void)(({ hrv *_v4381 = &(g165); hsl _s4381 = hr_str("struct ", 7); hr_append(_v4381, _s4381.p, _s4381.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4382 = &(g165); hsl _s4382 = f261_cn(t_1471); hr_append(_v4382, _s4382.p, _s4382.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4384 = &(g165); hsl _s4384 = hr_str(" { ", 3); hr_append(_v4384, _s4384.p, _s4384.n, sizeof(uint8_t)); }));
{ int32_t _e4386 = (x_1472).n_; for (int32_t _k4386 = 0; _k4386 < _e4386; _k4386++) { int32_t i_1508 = (int32_t)_k4386; (void)(({ hrv *_v4387 = &(g165); hsl _s4387 = f261_cn(((int64_t)((*({ hrv *_t4389 = &(g544); int64_t _i4389 = ((int64_t)((int64_t)((int64_t)((x_1472).l_)) + (int64_t)((int64_t)(i_1508)))); (int32_t*)_t4389->b + hr_ix(_i4389, _t4389->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:94"); }))))); hr_append(_v4387, _s4387.p, _s4387.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4390 = &(g165); hr_fs(_o4390, hr_str(" r", 2)); hr_fi(_o4390, i_1508); hr_fs(_o4390, hr_str("; ", 2)); }));
 } } _bk4385:; 
(void)(({ hrv *_v4391 = &(g165); hsl _s4391 = hr_str("};\012", 3); hr_append(_v4391, _s4391.p, _s4391.n, sizeof(uint8_t)); }));
 }
}
static void f260_cn_grow(void) {
while ((((g171).n) < ((g543).n))) { (void)(({ hrv *_v4393 = &(g171); int32_t _x4393 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p4393 = (int32_t*)hr_grow(_v4393, 1, sizeof _x4393); *_p4393 = _x4393; _p4393; }));
(void)(({ hrv *_v4394 = &(g172); int32_t _x4394 = ((int32_t)0LL); int32_t *_p4394 = (int32_t*)hr_grow(_v4394, 1, sizeof _x4394); *_p4394 = _x4394; _p4394; }));
(void)(({ hrv *_v4395 = &(g173); uint8_t _x4395 = ((uint8_t)0LL); uint8_t *_p4395 = (uint8_t*)hr_grow(_v4395, 1, sizeof _x4395); *_p4395 = _x4395; _p4395; }));
(void)(({ hrv *_v4396 = &(g174); uint8_t _x4396 = ((uint8_t)0LL); uint8_t *_p4396 = (uint8_t*)hr_grow(_v4396, 1, sizeof _x4396); *_p4396 = _x4396; _p4396; }));
(void)(({ hrv *_v4397 = &(g175); uint8_t _x4397 = ((uint8_t)0LL); uint8_t *_p4397 = (uint8_t*)hr_grow(_v4397, 1, sizeof _x4397); *_p4397 = _x4397; _p4397; }));
 } _bk4392:; 
}
static hsl f261_cn(int64_t t_1474) {
(void)(f260_cn_grow());
if ((((*({ hrv *_t4399 = &(g171); int64_t _i4399 = t_1474; (int32_t*)_t4399->b + hr_ix(_i4399, _t4399->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:23"); }))) < (((int32_t)0LL)))) { (void)(f262_cn_make(t_1474));
 }
int64_t o_1486 = ((int64_t)((*({ hrv *_t4401 = &(g171); int64_t _i4401 = t_1474; (int32_t*)_t4401->b + hr_ix(_i4401, _t4401->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:24"); })))); 
return ({ hsl _t4402 = hr_sl(g170); int64_t _l4402 = o_1486, _h4402 = ((int64_t)((int64_t)o_1486 + (int64_t)((int64_t)((*({ hrv *_t4403 = &(g172); int64_t _i4403 = t_1474; (int32_t*)_t4403->b + hr_ix(_i4403, _t4403->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:25"); })))))); if (_l4402 < 0 || _h4402 < _l4402 || _h4402 > _t4402.n) hr_slerr(_l4402, _h4402, _t4402.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:25"); (hsl){ _t4402.p + _l4402 * (int64_t)sizeof(uint8_t), _h4402 - _l4402 }; });
}
static void f262_cn_make(int64_t t_1475) {
S1 x_1476 = (*({ hrv *_t4404 = &(g543); int64_t _i4404 = t_1475; (S1*)_t4404->b + hr_ix(_i4404, _t4404->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:28"); })); 
int64_t k_1477 = ((int64_t)((x_1476).k_)); 
if ((((k_1477) == (((int64_t)10LL))) && (((x_1476).c_) < (((int32_t)0LL))))) { hsl e_1478 = f261_cn(((int64_t)((x_1476).a_))); 
int64_t s0_1479 = (g170).n; 
(void)(({ hrv *_v4406 = &(g170); hsl _s4406 = e_1478; hr_append(_v4406, _s4406.p, _s4406.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4407 = &(g170); uint8_t _x4407 = ((uint8_t)42LL); uint8_t *_p4407 = (uint8_t*)hr_grow(_v4407, 1, sizeof _x4407); *_p4407 = _x4407; _p4407; }));
{ int32_t *_t4408 = &((*({ hrv *_t4409 = &(g171); int64_t _i4409 = t_1475; (int32_t*)_t4409->b + hr_ix(_i4409, _t4409->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:29"); }))); *_t4408 = ((int32_t)(s0_1479)); }
{ int32_t *_t4410 = &((*({ hrv *_t4411 = &(g172); int64_t _i4411 = t_1475; (int32_t*)_t4411->b + hr_ix(_i4411, _t4411->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:29"); }))); *_t4410 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1479)))); }
return;
 }
if (((k_1477) == (((int64_t)7LL)))) { S9 v_1480 = (*({ hrv *_t4412 = &(g549); int64_t _i4412 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4413 = &(g548); int64_t _i4413 = (x_1476).a_; (S8*)_t4413->b + hr_ix(_i4413, _t4413->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:30"); }))).v0_)) + (int64_t)((int64_t)((x_1476).c_)))); (S9*)_t4412->b + hr_ix(_i4412, _t4412->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:30"); })); 
if ((((v_1480).si_) >= (((int32_t)0LL)))) { hsl e_1481 = f261_cn(f134_t_struct(((int64_t)((v_1480).si_)))); 
int64_t s0_1482 = (g170).n; 
(void)(({ hrv *_v4416 = &(g170); hsl _s4416 = e_1481; hr_append(_v4416, _s4416.p, _s4416.n, sizeof(uint8_t)); }));
{ int32_t *_t4417 = &((*({ hrv *_t4418 = &(g171); int64_t _i4418 = t_1475; (int32_t*)_t4418->b + hr_ix(_i4418, _t4418->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:30"); }))); *_t4417 = ((int32_t)(s0_1482)); }
{ int32_t *_t4419 = &((*({ hrv *_t4420 = &(g172); int64_t _i4420 = t_1475; (int32_t*)_t4420->b + hr_ix(_i4420, _t4420->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:30"); }))); *_t4419 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1482)))); }
return;
 }
 }
int64_t s0_1483 = (g170).n; 
if (((k_1477) == (((int64_t)3LL)))) { (void)(({ hrv *_v4421 = &(g170); hsl _s4421 = (g183).e[hr_ix(((uint8_t)((uint64_t)(x_1476).s_ & (uint64_t)((uint8_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:32")]; hr_append(_v4421, _s4421.p, _s4421.n, sizeof(uint8_t)); }));
 } else { if (((k_1477) == (((int64_t)10LL)))) { (void)(({ hrv *_v4423 = &(g170); hsl _s4423 = (g183).e[hr_ix(((int32_t)((int64_t)((int32_t)((int64_t)(x_1476).c_ & (int64_t)((int32_t)3LL))) + (int64_t)((int32_t)4LL))), 8, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:33")]; hr_append(_v4423, _s4423.p, _s4423.n, sizeof(uint8_t)); }));
 } else { if (((k_1477) == (((int64_t)2LL)))) { (void)(({ hrv *_v4425 = &(g170); hsl _s4425 = hr_str("bool", 4); hr_append(_v4425, _s4425.p, _s4425.n, sizeof(uint8_t)); }));
 } else { if (((k_1477) == (((int64_t)4LL)))) { (void)(({ hrv *_v4426 = &(g170); hsl _s4426 = ({ hsl _r4427; if ((((x_1476).s_) == (((uint8_t)4LL)))) { _r4427 = hr_str("float", 5);  } else { _r4427 = hr_str("double", 6);  } _r4427; }); hr_append(_v4426, _s4426.p, _s4426.n, sizeof(uint8_t)); }));
 } else { if (((k_1477) == (((int64_t)1LL)))) { (void)(({ hrv *_v4428 = &(g170); hsl _s4428 = hr_str("void", 4); hr_append(_v4428, _s4428.p, _s4428.n, sizeof(uint8_t)); }));
 } else { if (((k_1477) == (((int64_t)5LL)))) { (void)(({ hrv *_o4429 = &(g170); hr_fs(_o4429, hr_str("S", 1)); hr_fi(_o4429, (x_1476).a_); }));
(void)(f263_fwd(s0_1483));
 } else { if (((k_1477) == (((int64_t)6LL)))) { (void)(({ hrv *_o4431 = &(g170); hr_fs(_o4431, hr_str("E", 1)); hr_fi(_o4431, (x_1476).a_); }));
(void)(f263_fwd(s0_1483));
 } else { if (((k_1477) == (((int64_t)7LL)))) { (void)(({ hrv *_v4433 = &(g170); hsl _s4433 = hr_str("hr_unit", 7); hr_append(_v4433, _s4433.p, _s4433.n, sizeof(uint8_t)); }));
 } else { if (((k_1477) == (((int64_t)8LL)))) { int64_t a_1485 = ((int64_t)((x_1476).s_)); 
if ((((a_1485) == (((int64_t)4LL))) || ((a_1485) == (((int64_t)5LL))))) { (void)(({ hrv *_v4434 = &(g170); hsl _s4434 = hr_str("hrv", 3); hr_append(_v4434, _s4434.p, _s4434.n, sizeof(uint8_t)); }));
 } else { if (((a_1485) == (((int64_t)1LL)))) { (void)(({ hrv *_o4435 = &(g170); hr_fs(_o4435, hr_str("A", 1)); hr_fi(_o4435, t_1475); }));
(void)(f263_fwd(s0_1483));
 } else { if ((((a_1485) == (((int64_t)3LL))) && (((x_1476).b_) >= (((int64_t)0LL))))) { (void)(({ hrv *_o4437 = &(g170); hr_fs(_o4437, hr_str("L", 1)); hr_fi(_o4437, t_1475); }));
(void)(f263_fwd(s0_1483));
 } else { (void)(({ hrv *_v4439 = &(g170); hsl _s4439 = hr_str("uint8_t*", 8); hr_append(_v4439, _s4439.p, _s4439.n, sizeof(uint8_t)); }));
 }
 }
 }
 } else { if (((((k_1477) == (((int64_t)9LL))) || ((k_1477) == (((int64_t)18LL)))) || ((k_1477) == (((int64_t)19LL))))) { (void)(({ hrv *_v4440 = &(g170); hsl _s4440 = hr_str("hsl", 3); hr_append(_v4440, _s4440.p, _s4440.n, sizeof(uint8_t)); }));
 } else { if (((k_1477) == (((int64_t)14LL)))) { (void)(({ hrv *_o4441 = &(g170); hr_fs(_o4441, hr_str("M", 1)); hr_fi(_o4441, t_1475); }));
(void)(f263_fwd(s0_1483));
 } else { if ((((k_1477) == (((int64_t)12LL))) || ((k_1477) == (((int64_t)17LL))))) { (void)(({ hrv *_v4443 = &(g170); hsl _s4443 = hr_str("int64_t", 7); hr_append(_v4443, _s4443.p, _s4443.n, sizeof(uint8_t)); }));
 } else { if (((k_1477) == (((int64_t)13LL)))) { (void)(({ hrv *_v4444 = &(g170); hsl _s4444 = hr_str("double", 6); hr_append(_v4444, _s4444.p, _s4444.n, sizeof(uint8_t)); }));
 } else { (void)(({ hrv *_v4445 = &(g170); hsl _s4445 = hr_str("void*", 5); hr_append(_v4445, _s4445.p, _s4445.n, sizeof(uint8_t)); }));
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
{ int32_t *_t4446 = &((*({ hrv *_t4447 = &(g171); int64_t _i4447 = t_1475; (int32_t*)_t4447->b + hr_ix(_i4447, _t4447->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:46"); }))); *_t4446 = ((int32_t)(s0_1483)); }
{ int32_t *_t4448 = &((*({ hrv *_t4449 = &(g172); int64_t _i4449 = t_1475; (int32_t*)_t4449->b + hr_ix(_i4449, _t4449->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:46"); }))); *_t4448 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1483)))); }
}
static void f263_fwd(int64_t s0_1484) {
(void)(({ hrv *_v4450 = &(g164); hsl _s4450 = hr_str("typedef struct ", 15); hr_append(_v4450, _s4450.p, _s4450.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4451 = &(g164); hsl _s4451 = ({ hsl _t4452 = hr_sl(g170); int64_t _l4452 = s0_1484, _h4452 = _t4452.n; if (_l4452 < 0 || _h4452 < _l4452 || _h4452 > _t4452.n) hr_slerr(_l4452, _h4452, _t4452.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:17"); (hsl){ _t4452.p + _l4452 * (int64_t)sizeof(uint8_t), _h4452 - _l4452 }; }); hr_append(_v4451, _s4451.p, _s4451.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4453 = &(g164); uint8_t _x4453 = ((uint8_t)32LL); uint8_t *_p4453 = (uint8_t*)hr_grow(_v4453, 1, sizeof _x4453); *_p4453 = _x4453; _p4453; }));
(void)(({ hrv *_v4454 = &(g164); hsl _s4454 = ({ hsl _t4455 = hr_sl(g170); int64_t _l4455 = s0_1484, _h4455 = _t4455.n; if (_l4455 < 0 || _h4455 < _l4455 || _h4455 > _t4455.n) hr_slerr(_l4455, _h4455, _t4455.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:17"); (hsl){ _t4455.p + _l4455 * (int64_t)sizeof(uint8_t), _h4455 - _l4455 }; }); hr_append(_v4454, _s4454.p, _s4454.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v4456 = &(g164); hsl _s4456 = hr_str(";\012", 2); hr_append(_v4456, _s4456.p, _s4456.n, sizeof(uint8_t)); }));
}
static void f264_fname_into(hrv* b_1496, int64_t name_1497) {
{ hsl _v4458 = f10_nm(name_1497); for (int64_t _k4458 = 0; _k4458 < _v4458.n; _k4458++) { uint8_t c_1498 = ((uint8_t*)_v4458.p)[_k4458]; (void)(({ hrv *_v4460 = b_1496; uint8_t _x4460 = ({ uint8_t _r4461; if (((c_1498) == (((uint8_t)58LL)))) { _r4461 = ((uint8_t)95LL);  } else { _r4461 = c_1498;  } _r4461; }); uint8_t *_p4460 = (uint8_t*)hr_grow(_v4460, 1, sizeof _x4460); *_p4460 = _x4460; _p4460; }));
 } } _bk4457:; 
(void)(({ hrv *_v4462 = b_1496; uint8_t _x4462 = ((uint8_t)95LL); uint8_t *_p4462 = (uint8_t*)hr_grow(_v4462, 1, sizeof _x4462); *_p4462 = _x4462; _p4462; }));
}
static bool f265_is_res(int64_t t_1517) {
return (((((*({ hrv *_t4463 = &(g543); int64_t _i4463 = t_1517; (S1*)_t4463->b + hr_ix(_i4463, _t4463->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:18"); }))).k_) == (((uint8_t)8LL))) && (((((int64_t)(((*({ hrv *_t4464 = &(g543); int64_t _i4464 = t_1517; (S1*)_t4464->b + hr_ix(_i4464, _t4464->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:18"); }))).s_))) == (((int64_t)4LL))) || ((((int64_t)(((*({ hrv *_t4465 = &(g543); int64_t _i4465 = t_1517; (S1*)_t4465->b + hr_ix(_i4465, _t4465->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:18"); }))).s_))) == (((int64_t)5LL)))));
}
static void f266_gxo(int64_t n_1518) {
int64_t c_1519 = f150_cv(n_1518); 
int64_t t_1520 = f141_at(n_1518); 
if ((((c_1519) >= (((int64_t)0LL))) && ((c_1519) != (t_1520)))) { if (f265_is_res(c_1519)) { (void)(f267_gcv(n_1518, t_1520, c_1519));
return;
 }
(void)(f286_gx(n_1518));
return;
 }
if ((f265_is_res(t_1520) && f269_is_place(n_1518))) { (void)(f257_ow(hr_str("hr_rdup(", 8)));
(void)(f272_gx0(n_1518));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f320_esz(((int64_t)(((*({ hrv *_t4477 = &(g543); int64_t _i4477 = t_1520; (S1*)_t4477->b + hr_ix(_i4477, _t4477->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:160"); }))).a_))));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
(void)(f272_gx0(n_1518));
}
static void f267_gcv(int64_t n_1521, int64_t f_1522, int64_t t_1523) {
if (((f_1522) == (t_1523))) { (void)(f268_gx1(n_1521));
return;
 }
int64_t fk_2028 = ((int64_t)(((*({ hrv *_t4481 = &(g543); int64_t _i4481 = f_1522; (S1*)_t4481->b + hr_ix(_i4481, _t4481->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:200"); }))).k_)); 
int64_t tk0_2029 = ((int64_t)(((*({ hrv *_t4482 = &(g543); int64_t _i4482 = t_1523; (S1*)_t4482->b + hr_ix(_i4482, _t4482->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:200"); }))).k_)); 
if (((((tk0_2029) == (((int64_t)2LL))) && ((fk_2028) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t4483 = &(g543); int64_t _i4483 = f_1522; (S1*)_t4483->b + hr_ix(_i4483, _t4483->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:201"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f257_ow(hr_str("((", 2)));
(void)(f268_gx1(n_1521));
(void)(f257_ow(hr_str(") != 0)", 7)));
return;
 }
if (((((fk_2028) == (((int64_t)10LL))) && ((((*({ hrv *_t4487 = &(g543); int64_t _i4487 = f_1522; (S1*)_t4487->b + hr_ix(_i4487, _t4487->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:202"); }))).c_) < (((int32_t)0LL)))) && ((tk0_2029) != (((int64_t)10LL))))) { int64_t m_2030 = ((int64_t)(((*({ hrv *_t4488 = &(g543); int64_t _i4488 = f_1522; (S1*)_t4488->b + hr_ix(_i4488, _t4488->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:203"); }))).a_)); 
if (((m_2030) == (t_1523))) { (void)(f257_ow(hr_str("(*", 2)));
(void)(f268_gx1(n_1521));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if ((((tk0_2029) == (((int64_t)9LL))) && (((((*({ hrv *_t4492 = &(g543); int64_t _i4492 = m_2030; (S1*)_t4492->b + hr_ix(_i4492, _t4492->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:205"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t4493 = &(g543); int64_t _i4493 = m_2030; (S1*)_t4493->b + hr_ix(_i4493, _t4493->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:205"); }))).k_) == (((uint8_t)9LL)))))) { (void)(f289_gsl(n_1521, f_1522));
return;
 }
if ((((tk0_2029) == (((int64_t)3LL))) || ((tk0_2029) == (((int64_t)4LL))))) { (void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(t_1523));
(void)(f257_ow(hr_str(")(*", 3)));
(void)(f268_gx1(n_1521));
(void)(f257_ow(hr_str("))", 2)));
return;
 }
if (f265_is_res(t_1523)) { (void)(f257_ow(hr_str("hr_rfrom(", 9)));
(void)(f289_gsl(n_1521, f_1522));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f320_esz(((int64_t)(((*({ hrv *_t4505 = &(g543); int64_t _i4505 = t_1523; (S1*)_t4505->b + hr_ix(_i4505, _t4505->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:207"); }))).a_))));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
(void)(f257_ow(hr_str("(*", 2)));
(void)(f268_gx1(n_1521));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if (((((tk0_2029) == (((int64_t)3LL))) || ((tk0_2029) == (((int64_t)4LL)))) && ((((fk_2028) == (((int64_t)3LL))) || ((fk_2028) == (((int64_t)4LL)))) || ((fk_2028) == (((int64_t)2LL)))))) { (void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(t_1523));
(void)(f257_ow(hr_str(")(", 2)));
(void)(f268_gx1(n_1521));
(void)(f257_ow(hr_str("))", 2)));
return;
 }
if (((tk0_2029) == (((int64_t)9LL)))) { (void)(f289_gsl(n_1521, f_1522));
return;
 }
if ((((tk0_2029) == (((int64_t)6LL))) && ((fk_2028) == (((int64_t)7LL))))) { int64_t vi_2031 = ((int64_t)(((*({ hrv *_t4516 = &(g543); int64_t _i4516 = f_1522; (S1*)_t4516->b + hr_ix(_i4516, _t4516->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:213"); }))).c_)); 
int64_t ei_2032 = ((int64_t)(((*({ hrv *_t4517 = &(g543); int64_t _i4517 = f_1522; (S1*)_t4517->b + hr_ix(_i4517, _t4517->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:213"); }))).a_)); 
S9 v_2033 = (*({ hrv *_t4518 = &(g549); int64_t _i4518 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4519 = &(g548); int64_t _i4519 = ei_2032; (S8*)_t4519->b + hr_ix(_i4519, _t4519->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:213"); }))).v0_)) + (int64_t)vi_2031)); (S9*)_t4518->b + hr_ix(_i4518, _t4518->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:213"); })); 
int64_t p_2034 = f290_nt(); 
(void)(f257_ow(hr_str("({ ", 3)));
(void)(f258_ct(t_1523));
(void)(f257_ow(hr_str(" _t", 3)));
(void)(f291_oi(p_2034));
(void)(f257_ow(hr_str("; memset(&_t", 12)));
(void)(f291_oi(p_2034));
(void)(f257_ow(hr_str(", 0, sizeof _t", 14)));
(void)(f291_oi(p_2034));
(void)(f257_ow(hr_str("); _t", 5)));
(void)(f291_oi(p_2034));
(void)(({ hrv *_o4531 = &(g163); hr_fs(_o4531, hr_str(".tag = ", 7)); hr_fi(_o4531, vi_2031); hr_fs(_o4531, hr_str("; ", 2)); }));
if (((((v_2033).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t4532 = &(g546); int64_t _i4532 = (v_2033).si_; (S10*)_t4532->b + hr_ix(_i4532, _t4532->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:216"); }))).zero_)))) { (void)(f257_ow(hr_str("_t", 2)));
(void)(f291_oi(p_2034));
(void)(({ hrv *_o4535 = &(g163); hr_fs(_o4535, hr_str(".u.v", 4)); hr_fi(_o4535, vi_2031); hr_fs(_o4535, hr_str(" = ", 3)); }));
(void)(f268_gx1(n_1521));
(void)(f257_ow(hr_str("; ", 2)));
 } else { (void)(f257_ow(hr_str("(void)(", 7)));
(void)(f268_gx1(n_1521));
(void)(f257_ow(hr_str("); ", 3)));
 }
(void)(f257_ow(hr_str("_t", 2)));
(void)(f291_oi(p_2034));
(void)(f257_ow(hr_str("; })", 4)));
return;
 }
if (((tk0_2029) == (((int64_t)10LL)))) { if (((fk_2028) == (((int64_t)10LL)))) { (void)(f268_gx1(n_1521));
return;
 }
(void)(f321_gaddr(n_1521));
return;
 }
if (f265_is_res(t_1523)) { (void)(f257_ow(hr_str("hr_rfrom(", 9)));
(void)(f289_gsl(n_1521, f_1522));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f320_esz(((int64_t)(((*({ hrv *_t4551 = &(g543); int64_t _i4551 = t_1523; (S1*)_t4551->b + hr_ix(_i4551, _t4551->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:221"); }))).a_))));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if ((f279_is_fix(t_1523) || f280_is_lim(t_1523))) { int64_t p_2035 = f290_nt(); 
(void)(f257_ow(hr_str("({ hsl _t", 9)));
(void)(f291_oi(p_2035));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f289_gsl(n_1521, f_1522));
(void)(f257_ow(hr_str("; ", 2)));
(void)(f258_ct(t_1523));
(void)(f257_ow(hr_str(" _r", 3)));
(void)(f291_oi(p_2035));
(void)(f257_ow(hr_str("; ", 2)));
if (f279_is_fix(t_1523)) { (void)(({ hrv *_o4566 = &(g163); hr_fs(_o4566, hr_str("if (_t", 6)); hr_fi(_o4566, p_2035); hr_fs(_o4566, hr_str(".n != ", 6)); hr_fi(_o4566, ((*({ hrv *_t4567 = &(g543); int64_t _i4567 = t_1523; (S1*)_t4567->b + hr_ix(_i4567, _t4567->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:225"); }))).b_); hr_fs(_o4566, hr_str(") hr_die(\"array length mismatch\", ", 34)); }));
(void)(f308_wloc(n_1521));
(void)(f257_ow(hr_str("); ", 3)));
 } else { (void)(({ hrv *_o4570 = &(g163); hr_fs(_o4570, hr_str("if (_t", 6)); hr_fi(_o4570, p_2035); hr_fs(_o4570, hr_str(".n > ", 5)); hr_fi(_o4570, ((*({ hrv *_t4571 = &(g543); int64_t _i4571 = t_1523; (S1*)_t4571->b + hr_ix(_i4571, _t4571->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:226"); }))).b_); hr_fs(_o4570, hr_str(") hr_die(\"too many elements for a limited array\", ", 50)); }));
(void)(f308_wloc(n_1521));
(void)(({ hrv *_o4573 = &(g163); hr_fs(_o4573, hr_str("); _r", 5)); hr_fi(_o4573, p_2035); hr_fs(_o4573, hr_str(".n = _t", 7)); hr_fi(_o4573, p_2035); hr_fs(_o4573, hr_str(".n; ", 4)); }));
 }
(void)(({ hrv *_o4574 = &(g163); hr_fs(_o4574, hr_str("memcpy(_r", 9)); hr_fi(_o4574, p_2035); hr_fs(_o4574, hr_str(".e, _t", 6)); hr_fi(_o4574, p_2035); hr_fs(_o4574, hr_str(".p, (size_t)_t", 14)); hr_fi(_o4574, p_2035); hr_fs(_o4574, hr_str(".n * sizeof _r", 14)); hr_fi(_o4574, p_2035); hr_fs(_o4574, hr_str(".e[0]); _r", 10)); hr_fi(_o4574, p_2035); hr_fs(_o4574, hr_str("; })", 4)); }));
return;
 }
(void)(f268_gx1(n_1521));
}
static void f268_gx1(int64_t n_1524) {
if ((f265_is_res(f141_at(n_1524)) && (!(f269_is_place(n_1524))))) { int64_t k_1532 = f270_tmp(f141_at(n_1524), true); 
(void)(f257_ow(hr_str("(*hr_tmp(&", 10)));
(void)(f271_ot(k_1532));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f272_gx0(n_1524));
(void)(f257_ow(hr_str("))", 2)));
return;
 }
(void)(f272_gx0(n_1524));
}
static bool f269_is_place(int64_t n_1525) {
S4 x_1526 = (*({ hrv *_t4587 = &(g696); int64_t _i4587 = n_1525; (S4*)_t4587->b + hr_ix(_i4587, _t4587->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:122"); })); 
int64_t k_1527 = ((int64_t)((x_1526).k_)); 
if (((k_1527) == (((int64_t)8LL)))) { int64_t r_1528 = f156_rk(n_1525); 
return (((r_1528) == (((int64_t)1LL))) || ((r_1528) == (((int64_t)2LL))));
 }
if (((k_1527) == (((int64_t)14LL)))) { return (((f156_rk(n_1525)) == (((int64_t)5LL))) && (f269_is_place(((int64_t)((x_1526).a_))) || ((((*({ hrv *_t4591 = &(g543); int64_t _i4591 = f141_at(((int64_t)((x_1526).a_))); (S1*)_t4591->b + hr_ix(_i4591, _t4591->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:124"); }))).k_) == (((uint8_t)10LL)))));
 }
if (((k_1527) == (((int64_t)12LL)))) { int64_t bt_1529 = f141_at(((int64_t)((x_1526).a_))); 
return ((((((*({ hrv *_t4594 = &(g543); int64_t _i4594 = f179_deref(bt_1529); (S1*)_t4594->b + hr_ix(_i4594, _t4594->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:125"); }))).k_) == (((uint8_t)9LL))) || f269_is_place(((int64_t)((x_1526).a_)))) || ((((*({ hrv *_t4597 = &(g543); int64_t _i4597 = bt_1529; (S1*)_t4597->b + hr_ix(_i4597, _t4597->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:125"); }))).k_) == (((uint8_t)10LL))));
 }
if ((((k_1527) == (((int64_t)10LL))) && ((((int64_t)((x_1526).op_))) == (((int64_t)49LL))))) { return f269_is_place(((int64_t)((x_1526).a_)));
 }
if (((((k_1527) == (((int64_t)11LL))) && ((f156_rk(n_1525)) == (((int64_t)4LL)))) && ((f157_rv(n_1525)) == (((int64_t)20LL))))) { return true;
 }
return false;
}
static int64_t f270_tmp(int64_t t_1530, bool clean_1531) {
(void)(f259_cbody(t_1530));
g178++;
(void)(({ hrv *_v4602 = &(g176); hsl _s4602 = f261_cn(t_1530); hr_append(_v4602, _s4602.p, _s4602.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4604 = &(g176); hr_fs(_o4604, hr_str(" _t", 3)); hr_fi(_o4604, g178); }));
if (clean_1531) { (void)(({ hrv *_v4605 = &(g176); hsl _s4605 = hr_str(" __attribute__((cleanup(hr_rdrop)))", 35); hr_append(_v4605, _s4605.p, _s4605.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v4606 = &(g176); hsl _s4606 = hr_str(" = {0}; ", 8); hr_append(_v4606, _s4606.p, _s4606.n, sizeof(uint8_t)); }));
return g178;
}
static void f271_ot(int64_t k_1533) {
(void)(({ hrv *_o4607 = &(g163); hr_fs(_o4607, hr_str("_t", 2)); hr_fi(_o4607, k_1533); }));
}
static void f272_gx0(int64_t n_1534) {
S4 x_1535 = (*({ hrv *_t4608 = &(g696); int64_t _i4608 = n_1534; (S4*)_t4608->b + hr_ix(_i4608, _t4608->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:693"); })); 
int64_t k_1536 = ((int64_t)((x_1535).k_)); 
if (((k_1536) == (((int64_t)1LL)))) { (void)(f274_oint(((*({ hrv *_t4610 = &(g906); int64_t _i4610 = (x_1535).t_; (S3*)_t4610->b + hr_ix(_i4610, _t4610->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:695"); }))).v_, ((*({ hrv *_t4611 = &(g906); int64_t _i4611 = (x_1535).t_; (S3*)_t4611->b + hr_ix(_i4611, _t4611->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:695"); }))).uns_, f273_fin_lit(n_1534)));
return;
 }
if (((k_1536) == (((int64_t)2LL)))) { int64_t t_1543 = f273_fin_lit(n_1534); 
(void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(({ int64_t _r4616; if (((((*({ hrv *_t4617 = &(g543); int64_t _i4617 = t_1543; (S1*)_t4617->b + hr_ix(_i4617, _t4617->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:696"); }))).k_) == (((uint8_t)4LL)))) { _r4616 = t_1543;  } else { _r4616 = g561;  } _r4616; })));
(void)(f257_ow(hr_str(")", 1)));
(void)(f257_ow(f36_tok_text(((int64_t)((x_1535).t_)))));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if (((k_1536) == (((int64_t)3LL)))) { (void)(f275_gstr(n_1534));
return;
 }
if (((k_1536) == (((int64_t)4LL)))) { (void)(f257_ow(hr_str("true", 4)));
return;
 }
if (((k_1536) == (((int64_t)5LL)))) { (void)(f257_ow(hr_str("false", 5)));
return;
 }
if (((k_1536) == (((int64_t)6LL)))) { (void)(f257_ow(hr_str("((void*)0)", 10)));
return;
 }
if (((k_1536) == (((int64_t)8LL)))) { int64_t r_1557 = f156_rk(n_1534); 
if (((r_1557) == (((int64_t)1LL)))) { (void)(f281_lv_expr(f157_rv(n_1534)));
return;
 }
if (((r_1557) == (((int64_t)2LL)))) { (void)(({ hrv *_o4629 = &(g163); hr_fs(_o4629, hr_str("g", 1)); hr_fi(_o4629, f157_rv(n_1534)); }));
return;
 }
if (((r_1557) == (((int64_t)6LL)))) { (void)(f274_oint((*({ hrv *_t4632 = &(g428); int64_t _i4632 = f157_rv(n_1534); (int64_t*)_t4632->b + hr_ix(_i4632, _t4632->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:705"); })), false, f273_fin_lit(n_1534)));
return;
 }
(void)(f284_gerr(n_1534, hr_str("unsupported name use", 20)));
return;
 }
if (((k_1536) == (((int64_t)9LL)))) { (void)(f285_gbin(n_1534));
return;
 }
if (((k_1536) == (((int64_t)10LL)))) { (void)(f309_gun(n_1534));
return;
 }
if (((k_1536) == (((int64_t)14LL)))) { int64_t r_1739 = f156_rk(n_1534); 
int64_t a_1740 = ((int64_t)((x_1535).a_)); 
if ((((r_1739) == (((int64_t)7LL))) && ((((*({ hrv *_t4639 = &(g543); int64_t _i4639 = f141_at(n_1534); (S1*)_t4639->b + hr_ix(_i4639, _t4639->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:713"); }))).k_) == (((uint8_t)7LL))))) { int64_t t_1741 = f141_at(n_1534); 
S9 v_1742 = (*({ hrv *_t4642 = &(g549); int64_t _i4642 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4643 = &(g548); int64_t _i4643 = ((*({ hrv *_t4644 = &(g543); int64_t _i4644 = t_1741; (S1*)_t4644->b + hr_ix(_i4644, _t4644->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:713"); }))).a_; (S8*)_t4643->b + hr_ix(_i4643, _t4643->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:713"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t4645 = &(g543); int64_t _i4645 = t_1741; (S1*)_t4645->b + hr_ix(_i4645, _t4645->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:713"); }))).c_)))); (S9*)_t4642->b + hr_ix(_i4642, _t4642->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:713"); })); 
if ((((v_1742).si_) >= (((int32_t)0LL)))) { (void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(t_1741));
(void)(f257_ow(hr_str("){0})", 5)));
 } else { (void)(f257_ow(hr_str("((hr_unit)0)", 12)));
 }
return;
 }
if (((r_1739) == (((int64_t)7LL)))) { int64_t t_1743 = f141_at(n_1534); 
int64_t p_1744 = f290_nt(); 
(void)(f257_ow(hr_str("({ ", 3)));
(void)(f258_ct(t_1743));
(void)(f257_ow(hr_str(" _t", 3)));
(void)(f291_oi(p_1744));
(void)(({ hrv *_o4656 = &(g163); hr_fs(_o4656, hr_str("; memset(&_t", 12)); hr_fi(_o4656, p_1744); hr_fs(_o4656, hr_str(", 0, sizeof _t", 14)); hr_fi(_o4656, p_1744); hr_fs(_o4656, hr_str("); _t", 5)); hr_fi(_o4656, p_1744); hr_fs(_o4656, hr_str(".tag = ", 7)); hr_fi(_o4656, f157_rv(n_1534)); hr_fs(_o4656, hr_str("; _t", 4)); hr_fi(_o4656, p_1744); hr_fs(_o4656, hr_str("; })", 4)); }));
return;
 }
if (((r_1739) == (((int64_t)8LL)))) { int64_t d_1745 = f179_deref(f141_at(a_1740)); 
if (((f157_rv(n_1534)) == (((int64_t)2LL)))) { (void)(({ hrv *_o4661 = &(g163); hr_fs(_o4661, hr_str("((int64_t)", 10)); hr_fi(_o4661, ((*({ hrv *_t4662 = &(g543); int64_t _i4662 = d_1745; (S1*)_t4662->b + hr_ix(_i4662, _t4662->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:717"); }))).b_); hr_fs(_o4661, hr_str(")", 1)); }));
return;
 }
if (f279_is_fix(d_1745)) { (void)(({ hrv *_o4664 = &(g163); hr_fs(_o4664, hr_str("((int64_t)", 10)); hr_fi(_o4664, ((*({ hrv *_t4665 = &(g543); int64_t _i4665 = d_1745; (S1*)_t4665->b + hr_ix(_i4665, _t4665->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:718"); }))).b_); hr_fs(_o4664, hr_str(")", 1)); }));
return;
 }
if (f280_is_lim(d_1745)) { (void)(f257_ow(hr_str("((int64_t)(", 11)));
if (((((*({ hrv *_t4668 = &(g543); int64_t _i4668 = f141_at(a_1740); (S1*)_t4668->b + hr_ix(_i4668, _t4668->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:719"); }))).k_) == (((uint8_t)10LL)))) { (void)(f272_gx0(a_1740));
(void)(f257_ow(hr_str(")->n)", 5)));
 } else { (void)(f286_gx(a_1740));
(void)(f257_ow(hr_str(").n)", 4)));
 }
return;
 }
if (((((*({ hrv *_t4674 = &(g543); int64_t _i4674 = f141_at(a_1740); (S1*)_t4674->b + hr_ix(_i4674, _t4674->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:720"); }))).k_) == (((uint8_t)10LL)))) { (void)(f257_ow(hr_str("((", 2)));
(void)(f272_gx0(a_1740));
(void)(f257_ow(hr_str(")->n)", 5)));
return;
 }
(void)(f257_ow(hr_str("(", 1)));
(void)(f286_gx(a_1740));
(void)(f257_ow(hr_str(").n", 3)));
return;
 }
if (((r_1739) == (((int64_t)5LL)))) { int64_t bt_1746 = f141_at(a_1740); 
int64_t st_1747 = f179_deref(bt_1746); 
int64_t si_1748 = ({ int64_t _r4684; if (((((*({ hrv *_t4685 = &(g543); int64_t _i4685 = st_1747; (S1*)_t4685->b + hr_ix(_i4685, _t4685->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:726"); }))).k_) == (((uint8_t)5LL)))) { _r4684 = ((int64_t)(((*({ hrv *_t4686 = &(g543); int64_t _i4686 = st_1747; (S1*)_t4686->b + hr_ix(_i4686, _t4686->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:726"); }))).a_));  } else { _r4684 = f217_ax(n_1534);  } _r4684; }); 
S11 f_1749 = (*({ hrv *_t4688 = &(g547); int64_t _i4688 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t4689 = &(g546); int64_t _i4689 = si_1748; (S10*)_t4689->b + hr_ix(_i4689, _t4689->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:727"); }))).f0_)) + (int64_t)f157_rv(n_1534))); (S11*)_t4688->b + hr_ix(_i4688, _t4688->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:727"); })); 
(void)(f257_ow(hr_str("(", 1)));
if (((((*({ hrv *_t4692 = &(g543); int64_t _i4692 = bt_1746; (S1*)_t4692->b + hr_ix(_i4692, _t4692->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:729"); }))).k_) == (((uint8_t)10LL)))) { (void)(f272_gx0(a_1740));
(void)(f257_ow(hr_str(")->", 3)));
 } else { (void)(f286_gx(a_1740));
(void)(f257_ow(hr_str(").", 2)));
 }
(void)(f264_fname_into((&(g163)), ((int64_t)((f_1749).name_))));
return;
 }
(void)(f284_gerr(n_1534, hr_str("unsupported member", 18)));
return;
 }
if (((k_1536) == (((int64_t)12LL)))) { (void)(f311_gidx(n_1534));
return;
 }
if (((k_1536) == (((int64_t)13LL)))) { (void)(f312_gslice(n_1534));
return;
 }
if (((k_1536) == (((int64_t)15LL)))) { int64_t t_1764 = f141_at(n_1534); 
int64_t ft_1765 = ((int64_t)(((*({ hrv *_t4702 = &(g543); int64_t _i4702 = f276_fin(((int64_t)((x_1535).a_))); (S1*)_t4702->b + hr_ix(_i4702, _t4702->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:737"); }))).k_)); 
if ((((((*({ hrv *_t4704 = &(g543); int64_t _i4704 = t_1764; (S1*)_t4704->b + hr_ix(_i4704, _t4704->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:737"); }))).k_) == (((uint8_t)3LL))) && (((ft_1765) == (((int64_t)4LL))) || ((ft_1765) == (((int64_t)13LL)))))) { (void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(t_1764));
(void)(f257_ow(hr_str(")hr_f2i(", 8)));
(void)(f286_gx(((int64_t)((x_1535).a_))));
(void)(f257_ow(hr_str("))", 2)));
return;
 }
(void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(t_1764));
(void)(f257_ow(hr_str(")(", 2)));
(void)(f286_gx(((int64_t)((x_1535).a_))));
(void)(f257_ow(hr_str("))", 2)));
return;
 }
if (((k_1536) == (((int64_t)16LL)))) { (void)(f313_garr(n_1534));
return;
 }
if (((k_1536) == (((int64_t)17LL)))) { (void)(f314_gslit(n_1534));
return;
 }
if (((k_1536) == (((int64_t)11LL)))) { (void)(f315_gcall(n_1534));
return;
 }
if (((k_1536) == (((int64_t)23LL)))) { (void)(f257_ow(hr_str("({ ", 3)));
(void)(f336_gblk(n_1534, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((f141_at(n_1534)) != (g550))));
(void)(f257_ow(hr_str(" })", 3)));
return;
 }
if ((((((k_1536) == (((int64_t)19LL))) || ((k_1536) == (((int64_t)20LL)))) || ((k_1536) == (((int64_t)24LL)))) || ((k_1536) == (((int64_t)26LL))))) { int64_t t_2026 = f141_at(n_1534); 
if ((((t_2026) == (g550)) || ((t_2026) < (((int64_t)0LL))))) { (void)(f257_ow(hr_str("({ ", 3)));
(void)(f329_gstmt(n_1534));
(void)(f257_ow(hr_str(" })", 3)));
return;
 }
int64_t r_2027 = f290_nt(); 
(void)(f257_ow(hr_str("({ ", 3)));
(void)(f258_ct(t_2026));
(void)(f257_ow(hr_str(" _r", 3)));
(void)(f291_oi(r_2027));
(void)(f257_ow(hr_str("; ", 2)));
if (((k_1536) == (((int64_t)19LL)))) { (void)(f335_gif(n_1534, r_2027));
 } else { if (((k_1536) == (((int64_t)20LL)))) { (void)(f343_gmatch(n_1534, r_2027));
 } else { if (((k_1536) == (((int64_t)24LL)))) { (void)(f344_geblock(n_1534, r_2027));
 } else { (void)(f341_gloop(n_1534, r_2027));
 }
 }
 }
(void)(f257_ow(hr_str(" _r", 3)));
(void)(f291_oi(r_2027));
(void)(f257_ow(hr_str("; })", 4)));
return;
 }
if (((((((k_1536) == (((int64_t)28LL))) || ((k_1536) == (((int64_t)29LL)))) || ((k_1536) == (((int64_t)30LL)))) || ((k_1536) == (((int64_t)25LL)))) || ((k_1536) == (((int64_t)27LL))))) { (void)(f257_ow(hr_str("({ ", 3)));
(void)(f329_gstmt(n_1534));
(void)(f257_ow(hr_str(" })", 3)));
return;
 }
(void)(f284_gerr(n_1534, hr_str("unsupported expression in codegen", 33)));
}
static int64_t f273_fin_lit(int64_t n_1537) {
int64_t t_1538 = f141_at(n_1537); 
return ({ int64_t _r4744; if ((((t_1538) < (((int64_t)0LL))) || ((((*({ hrv *_t4745 = &(g543); int64_t _i4745 = t_1538; (S1*)_t4745->b + hr_ix(_i4745, _t4745->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:756"); }))).k_) == (((uint8_t)12LL))))) { _r4744 = g555;  } else { _r4744 = ({ int64_t _r4746; if (((((*({ hrv *_t4747 = &(g543); int64_t _i4747 = t_1538; (S1*)_t4747->b + hr_ix(_i4747, _t4747->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:756"); }))).k_) == (((uint8_t)13LL)))) { _r4746 = g561;  } else { _r4746 = t_1538;  } _r4746; });  } _r4744; });
}
static void f274_oint(int64_t v_1539, bool uns_1540, int64_t t_1541) {
int64_t k_1542 = ((int64_t)(((*({ hrv *_t4748 = &(g543); int64_t _i4748 = t_1541; (S1*)_t4748->b + hr_ix(_i4748, _t4748->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:140"); }))).k_)); 
if (((k_1542) == (((int64_t)4LL)))) { (void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(t_1541));
(void)(f257_ow(hr_str(")", 1)));
if (uns_1540) { (void)(({ hrv *_o4752 = &(g163); hr_fu(_o4752, ((uint64_t)(v_1539))); hr_fs(_o4752, hr_str(".0", 2)); }));
 } else { (void)(({ hrv *_o4753 = &(g163); hr_fi(_o4753, v_1539); hr_fs(_o4753, hr_str(".0", 2)); }));
 }
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if (((k_1542) == (((int64_t)2LL)))) { (void)(f257_ow(({ hsl _r4756; if (((v_1539) != (((int64_t)0LL)))) { _r4756 = hr_str("true", 4);  } else { _r4756 = hr_str("false", 5);  } _r4756; })));
return;
 }
(void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(({ int64_t _r4759; if (((k_1542) == (((int64_t)3LL)))) { _r4759 = t_1541;  } else { _r4759 = g555;  } _r4759; })));
(void)(f257_ow(hr_str(")", 1)));
if (uns_1540) { (void)(({ hrv *_o4761 = &(g163); hr_fu(_o4761, ((uint64_t)(v_1539))); hr_fs(_o4761, hr_str("ULL)", 4)); }));
return;
 }
if (((v_1539) == (((int64_t)((int64_t)((int64_t)(0 - (uint64_t)(((int64_t)9223372036854775807LL)))) - (int64_t)((int64_t)1LL)))))) { (void)(f257_ow(hr_str("(-9223372036854775807LL-1))", 27)));
return;
 }
(void)(({ hrv *_o4763 = &(g163); hr_fi(_o4763, v_1539); hr_fs(_o4763, hr_str("LL)", 3)); }));
}
static void f275_gstr(int64_t n_1544) {
int64_t t_1548 = f276_fin(n_1544); 
hsl s_1551 = f277_tok_str(((int64_t)(((*({ hrv *_t4766 = &(g696); int64_t _i4766 = n_1544; (S4*)_t4766->b + hr_ix(_i4766, _t4766->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:338"); }))).t_))); 
int64_t a_1552 = f141_at(n_1544); 
if (f265_is_res(a_1552)) { (void)(f257_ow(hr_str("hr_rfrom(hr_str(", 16)));
(void)(f278_cstr_lit(s_1551));
(void)(({ hrv *_o4771 = &(g163); hr_fs(_o4771, hr_str(", ", 2)); hr_fi(_o4771, (s_1551).n); hr_fs(_o4771, hr_str("), 1)", 5)); }));
return;
 }
if (f279_is_fix(a_1552)) { (void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(a_1552));
(void)(f257_ow(hr_str("){ ", 3)));
(void)(f278_cstr_lit(s_1551));
(void)(f257_ow(hr_str(" })", 3)));
return;
 }
if (f280_is_lim(a_1552)) { (void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(a_1552));
(void)(({ hrv *_o4781 = &(g163); hr_fs(_o4781, hr_str("){ ", 3)); hr_fi(_o4781, (s_1551).n); hr_fs(_o4781, hr_str(", ", 2)); }));
(void)(f278_cstr_lit(s_1551));
(void)(f257_ow(hr_str(" })", 3)));
return;
 }
(void)(f257_ow(hr_str("hr_str(", 7)));
(void)(f278_cstr_lit(s_1551));
(void)(({ hrv *_o4786 = &(g163); hr_fs(_o4786, hr_str(", ", 2)); hr_fi(_o4786, (s_1551).n); hr_fs(_o4786, hr_str(")", 1)); }));
}
static int64_t f276_fin(int64_t n_1545) {
int64_t c_1546 = f150_cv(n_1545); 
return ({ int64_t _r4788; if (((c_1546) >= (((int64_t)0LL)))) { _r4788 = c_1546;  } else { int64_t t_1547 = f141_at(n_1545); 
_r4788 = ({ int64_t _r4790; if (((t_1547) < (((int64_t)0LL)))) { _r4790 = g550;  } else { _r4790 = t_1547;  } _r4790; });  } _r4788; });
}
static hsl f277_tok_str(int64_t t_1549) {
S3 x_1550 = (*({ hrv *_t4791 = &(g906); int64_t _i4791 = t_1549; (S3*)_t4791->b + hr_ix(_i4791, _t4791->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:182"); })); 
return ({ hsl _t4792 = hr_sl(g902); int64_t _l4792 = ((int64_t)((x_1550).v_)), _h4792 = ((int64_t)((int64_t)((int64_t)((x_1550).v_)) + (int64_t)((int64_t)((x_1550).w_)))); if (_l4792 < 0 || _h4792 < _l4792 || _h4792 > _t4792.n) hr_slerr(_l4792, _h4792, _t4792.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:182"); (hsl){ _t4792.p + _l4792 * (int64_t)sizeof(uint8_t), _h4792 - _l4792 }; });
}
static void f278_cstr_lit(hsl s_1553) {
(void)(({ hrv *_v4793 = &(g163); uint8_t _x4793 = ((uint8_t)34LL); uint8_t *_p4793 = (uint8_t*)hr_grow(_v4793, 1, sizeof _x4793); *_p4793 = _x4793; _p4793; }));
{ hsl _v4795 = s_1553; for (int64_t _k4795 = 0; _k4795 < _v4795.n; _k4795++) { uint8_t c_1554 = ((uint8_t*)_v4795.p)[_k4795]; if ((((c_1554) == (((uint8_t)34LL))) || ((c_1554) == (((uint8_t)92LL))))) { (void)(({ hrv *_v4796 = &(g163); uint8_t _x4796 = ((uint8_t)92LL); uint8_t *_p4796 = (uint8_t*)hr_grow(_v4796, 1, sizeof _x4796); *_p4796 = _x4796; _p4796; }));
(void)(({ hrv *_v4797 = &(g163); uint8_t _x4797 = c_1554; uint8_t *_p4797 = (uint8_t*)hr_grow(_v4797, 1, sizeof _x4797); *_p4797 = _x4797; _p4797; }));
 } else { if (((((c_1554) >= (((uint8_t)32LL))) && ((c_1554) < (((uint8_t)127LL)))) && ((c_1554) != (((uint8_t)63LL))))) { (void)(({ hrv *_v4798 = &(g163); uint8_t _x4798 = c_1554; uint8_t *_p4798 = (uint8_t*)hr_grow(_v4798, 1, sizeof _x4798); *_p4798 = _x4798; _p4798; }));
 } else { (void)(({ hrv *_v4799 = &(g163); uint8_t _x4799 = ((uint8_t)92LL); uint8_t *_p4799 = (uint8_t*)hr_grow(_v4799, 1, sizeof _x4799); *_p4799 = _x4799; _p4799; }));
(void)(({ hrv *_v4800 = &(g163); uint8_t _x4800 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)((uint8_t)((c_1554) >> ((((uint8_t)6LL)) & 7))) & (uint64_t)((uint8_t)7LL))))); uint8_t *_p4800 = (uint8_t*)hr_grow(_v4800, 1, sizeof _x4800); *_p4800 = _x4800; _p4800; }));
(void)(({ hrv *_v4801 = &(g163); uint8_t _x4801 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)((uint8_t)((c_1554) >> ((((uint8_t)3LL)) & 7))) & (uint64_t)((uint8_t)7LL))))); uint8_t *_p4801 = (uint8_t*)hr_grow(_v4801, 1, sizeof _x4801); *_p4801 = _x4801; _p4801; }));
(void)(({ hrv *_v4802 = &(g163); uint8_t _x4802 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)c_1554 & (uint64_t)((uint8_t)7LL))))); uint8_t *_p4802 = (uint8_t*)hr_grow(_v4802, 1, sizeof _x4802); *_p4802 = _x4802; _p4802; }));
 }
 }
 } } _bk4794:; 
(void)(({ hrv *_v4803 = &(g163); uint8_t _x4803 = ((uint8_t)34LL); uint8_t *_p4803 = (uint8_t*)hr_grow(_v4803, 1, sizeof _x4803); *_p4803 = _x4803; _p4803; }));
}
static bool f279_is_fix(int64_t t_1555) {
return (((((*({ hrv *_t4804 = &(g543); int64_t _i4804 = t_1555; (S1*)_t4804->b + hr_ix(_i4804, _t4804->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:20"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t4805 = &(g543); int64_t _i4805 = t_1555; (S1*)_t4805->b + hr_ix(_i4805, _t4805->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:20"); }))).s_))) == (((int64_t)1LL))));
}
static bool f280_is_lim(int64_t t_1556) {
return (((((*({ hrv *_t4806 = &(g543); int64_t _i4806 = t_1556; (S1*)_t4806->b + hr_ix(_i4806, _t4806->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:19"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t4807 = &(g543); int64_t _i4807 = t_1556; (S1*)_t4807->b + hr_ix(_i4807, _t4807->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:19"); }))).s_))) == (((int64_t)3LL))));
}
static void f281_lv_expr(int64_t v_1558) {
bool p_1560 = f282_lv_isptr(v_1558); 
if (((((int64_t)(((*({ hrv *_t4809 = &(g381); int64_t _i4809 = v_1558; (S12*)_t4809->b + hr_ix(_i4809, _t4809->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:115"); }))).cfn_))) != (g179))) { (void)(f257_ow(({ hsl _r4811; if (p_1560) { _r4811 = hr_str("(**c", 4);  } else { _r4811 = hr_str("(*c", 3);  } _r4811; })));
(void)(({ hrv *_o4812 = &(g163); hr_fi(_o4812, v_1558); hr_fs(_o4812, hr_str(")", 1)); }));
return;
 }
if (p_1560) { (void)(f257_ow(hr_str("(*", 2)));
(void)(f283_lv_name(v_1558));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
(void)(f283_lv_name(v_1558));
}
static bool f282_lv_isptr(int64_t v_1559) {
return (((((uint16_t)((uint64_t)((*({ hrv *_t4817 = &(g381); int64_t _i4817 = v_1559; (S12*)_t4817->b + hr_ix(_i4817, _t4817->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:112"); }))).fl_ & (uint64_t)((uint16_t)8LL)))) != (((uint16_t)0LL))) && ((((*({ hrv *_t4818 = &(g543); int64_t _i4818 = ((*({ hrv *_t4819 = &(g381); int64_t _i4819 = v_1559; (S12*)_t4819->b + hr_ix(_i4819, _t4819->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:112"); }))).ty_; (S1*)_t4818->b + hr_ix(_i4818, _t4818->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:112"); }))).k_) != (((uint8_t)10LL))));
}
static void f283_lv_name(int64_t v_1561) {
{ hsl _v4821 = f10_nm(((int64_t)(((*({ hrv *_t4823 = &(g381); int64_t _i4823 = v_1561; (S12*)_t4823->b + hr_ix(_i4823, _t4823->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:111"); }))).name_))); for (int64_t _k4821 = 0; _k4821 < _v4821.n; _k4821++) { uint8_t c_1562 = ((uint8_t*)_v4821.p)[_k4821]; (void)(({ hrv *_v4824 = &(g163); uint8_t _x4824 = ({ uint8_t _r4825; if ((((c_1562) == (((uint8_t)36LL))) || ((c_1562) == (((uint8_t)58LL))))) { _r4825 = ((uint8_t)95LL);  } else { _r4825 = c_1562;  } _r4825; }); uint8_t *_p4824 = (uint8_t*)hr_grow(_v4824, 1, sizeof _x4824); *_p4824 = _x4824; _p4824; }));
 } } _bk4820:; 
(void)(({ hrv *_o4826 = &(g163); hr_fs(_o4826, hr_str("_", 1)); hr_fi(_o4826, v_1561); }));
}
static void f284_gerr(int64_t n_1563, hsl m_1564) {
if ((((g182).n) > (((int64_t)0LL)))) { return;
 }
S3 x_1565 = (*({ hrv *_t4827 = &(g906); int64_t _i4827 = ((*({ hrv *_t4828 = &(g696); int64_t _i4828 = f103_max(n_1563, ((int64_t)0LL)); (S4*)_t4828->b + hr_ix(_i4828, _t4828->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:15"); }))).t_; (S3*)_t4827->b + hr_ix(_i4827, _t4827->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:15"); })); 
(void)(({ hrv *_v4830 = &(g182); hsl _s4830 = f10_nm(((int64_t)(((*({ hrv *_t4832 = &(g905); int64_t _i4832 = (x_1565).f_; (S2*)_t4832->b + hr_ix(_i4832, _t4832->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:15"); }))).name_))); hr_append(_v4830, _s4830.p, _s4830.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o4833 = &(g182); hr_fs(_o4833, hr_str(":", 1)); hr_fi(_o4833, (x_1565).line_); hr_fs(_o4833, hr_str(": error: ", 9)); hr_fs(_o4833, m_1564); }));
}
static void f285_gbin(int64_t n_1566) {
S4 x_1567 = (*({ hrv *_t4834 = &(g696); int64_t _i4834 = n_1566; (S4*)_t4834->b + hr_ix(_i4834, _t4834->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:256"); })); 
int64_t o_1568 = ((int64_t)((x_1567).op_)); 
int64_t a_1569 = ((int64_t)((x_1567).a_)); 
int64_t b_1570 = ((int64_t)((x_1567).b_)); 
if ((((o_1568) == (((int64_t)52LL))) || ((o_1568) == (((int64_t)53LL))))) { (void)(f257_ow(hr_str("(", 1)));
(void)(f286_gx(a_1569));
(void)(f257_ow(({ hsl _r4838; if (((o_1568) == (((int64_t)52LL)))) { _r4838 = hr_str(" && ", 4);  } else { _r4838 = hr_str(" || ", 4);  } _r4838; })));
(void)(f286_gx(b_1570));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
bool cmp_1574 = (((((((o_1568) == (((int64_t)37LL))) || ((o_1568) == (((int64_t)38LL)))) || ((o_1568) == (((int64_t)39LL)))) || ((o_1568) == (((int64_t)40LL)))) || ((o_1568) == (((int64_t)41LL)))) || ((o_1568) == (((int64_t)42LL)))); 
if (cmp_1574) { int64_t m_1575 = f217_ax(n_1566); 
int64_t ta_1576 = f276_fin(a_1569); 
int64_t tb_1577 = f276_fin(b_1570); 
if (((m_1575) == (((int64_t)1LL)))) { (void)(f257_ow(hr_str("((uint64_t)(", 12)));
(void)(f286_gx(a_1569));
(void)(f257_ow(hr_str(") ", 2)));
(void)(f257_ow(f287_cmp_op(o_1568)));
(void)(f257_ow(hr_str(" (uint64_t)(", 12)));
(void)(f286_gx(b_1570));
(void)(f257_ow(hr_str("))", 2)));
return;
 }
if (((m_1575) == (((int64_t)2LL)))) { if (((o_1568) == (((int64_t)38LL)))) { (void)(f257_ow(hr_str("!", 1)));
 }
(void)(f257_ow(hr_str("hr_streq(", 9)));
(void)(f288_gas(a_1569));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f288_gas(b_1570));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if (((m_1575) == (((int64_t)3LL)))) { int64_t et_1592 = ({ int64_t _r4858; if ((((((*({ hrv *_t4859 = &(g543); int64_t _i4859 = ta_1576; (S1*)_t4859->b + hr_ix(_i4859, _t4859->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:264"); }))).k_) == (((uint8_t)7LL))) || ((((*({ hrv *_t4860 = &(g543); int64_t _i4860 = ta_1576; (S1*)_t4860->b + hr_ix(_i4860, _t4860->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:264"); }))).k_) == (((uint8_t)19LL))))) { _r4858 = tb_1577;  } else { _r4858 = ta_1576;  } _r4858; }); 
(void)(f292_gen_heq(et_1592));
if (((o_1568) == (((int64_t)38LL)))) { (void)(f257_ow(hr_str("!", 1)));
 }
(void)(f257_ow(hr_str("heq", 3)));
(void)(f291_oi(et_1592));
(void)(f257_ow(hr_str("(", 1)));
if (f301_hsl_ty(et_1592)) { (void)(f288_gas(a_1569));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f288_gas(b_1570));
 } else { (void)(f302_gxas(a_1569, et_1592));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f302_gxas(b_1570, et_1592));
 }
(void)(f257_ow(hr_str(")", 1)));
return;
 }
int64_t ka_1685 = ((int64_t)(((*({ hrv *_t4874 = &(g543); int64_t _i4874 = ta_1576; (S1*)_t4874->b + hr_ix(_i4874, _t4874->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:265"); }))).k_)); 
if (((((ka_1685) == (((int64_t)10LL))) || ((ka_1685) == (((int64_t)11LL)))) || ((((*({ hrv *_t4875 = &(g543); int64_t _i4875 = tb_1577; (S1*)_t4875->b + hr_ix(_i4875, _t4875->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:266"); }))).k_) == (((uint8_t)10LL))))) { (void)(f257_ow(hr_str("((void*)(", 9)));
(void)(f286_gx(a_1569));
(void)(f257_ow(hr_str(") ", 2)));
(void)(f257_ow(f287_cmp_op(o_1568)));
(void)(f257_ow(hr_str(" (void*)(", 9)));
(void)(f286_gx(b_1570));
(void)(f257_ow(hr_str("))", 2)));
return;
 }
(void)(f257_ow(hr_str("((", 2)));
(void)(f286_gx(a_1569));
(void)(f257_ow(hr_str(") ", 2)));
(void)(f257_ow(f287_cmp_op(o_1568)));
(void)(f257_ow(hr_str(" (", 2)));
(void)(f286_gx(b_1570));
(void)(f257_ow(hr_str("))", 2)));
return;
 }
(void)(f303_garith(o_1568, f276_fin(n_1566), a_1569, b_1570, ((int64_t)0LL), n_1566));
}
static void f286_gx(int64_t n_1571) {
int64_t c_1572 = f150_cv(n_1571); 
int64_t t_1573 = f141_at(n_1571); 
if ((((c_1572) < (((int64_t)0LL))) || ((c_1572) == (t_1573)))) { (void)(f268_gx1(n_1571));
return;
 }
(void)(f267_gcv(n_1571, t_1573, c_1572));
}
static hsl f287_cmp_op(int64_t o_1578) {
if (((o_1578) == (((int64_t)37LL)))) { return hr_str("==", 2);
 }
if (((o_1578) == (((int64_t)38LL)))) { return hr_str("!=", 2);
 }
if (((o_1578) == (((int64_t)39LL)))) { return hr_str("<", 1);
 }
if (((o_1578) == (((int64_t)40LL)))) { return hr_str(">", 1);
 }
if (((o_1578) == (((int64_t)41LL)))) { return hr_str("<=", 2);
 }
if (((o_1578) == (((int64_t)42LL)))) { return hr_str(">=", 2);
 }
return hr_str("\077", 1);
}
static void f288_gas(int64_t n_1579) {
int64_t c_1580 = f150_cv(n_1579); 
int64_t t_1581 = f141_at(n_1579); 
if (((((c_1580) >= (((int64_t)0LL))) && ((c_1580) != (t_1581))) && ((((*({ hrv *_t4900 = &(g543); int64_t _i4900 = c_1580; (S1*)_t4900->b + hr_ix(_i4900, _t4900->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:194"); }))).k_) == (((uint8_t)9LL))))) { (void)(f289_gsl(n_1579, t_1581));
return;
 }
if ((((c_1580) >= (((int64_t)0LL))) && ((c_1580) != (t_1581)))) { int64_t p_1591 = f290_nt(); 
(void)(f257_ow(hr_str("({ ", 3)));
(void)(f258_ct(c_1580));
(void)(f257_ow(hr_str(" _t", 3)));
(void)(f291_oi(p_1591));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(n_1579));
(void)(f257_ow(hr_str("; ", 2)));
if (f265_is_res(c_1580)) { (void)(f257_ow(hr_str("hr_sl(_t", 8)));
(void)(f291_oi(p_1591));
(void)(f257_ow(hr_str(")", 1)));
 } else { if (f279_is_fix(c_1580)) { (void)(f257_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f291_oi(p_1591));
(void)(({ hrv *_o4917 = &(g163); hr_fs(_o4917, hr_str(".e, ", 4)); hr_fi(_o4917, ((*({ hrv *_t4918 = &(g543); int64_t _i4918 = c_1580; (S1*)_t4918->b + hr_ix(_i4918, _t4918->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:195"); }))).b_); hr_fs(_o4917, hr_str(" }", 2)); }));
 } else { if (((((*({ hrv *_t4919 = &(g543); int64_t _i4919 = c_1580; (S1*)_t4919->b + hr_ix(_i4919, _t4919->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:195"); }))).k_) == (((uint8_t)9LL)))) { (void)(f257_ow(hr_str("_t", 2)));
(void)(f291_oi(p_1591));
 } else { (void)(f257_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f291_oi(p_1591));
(void)(f257_ow(hr_str(".e, _t", 6)));
(void)(f291_oi(p_1591));
(void)(f257_ow(hr_str(".n }", 4)));
 }
 }
 }
(void)(f257_ow(hr_str("; })", 4)));
return;
 }
(void)(f289_gsl(n_1579, t_1581));
}
static void f289_gsl(int64_t n_1582, int64_t f_1583) {
int64_t d_1584 = f179_deref(f_1583); 
int64_t k_1585 = ((int64_t)(((*({ hrv *_t4930 = &(g543); int64_t _i4930 = d_1584; (S1*)_t4930->b + hr_ix(_i4930, _t4930->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:171"); }))).k_)); 
if ((((((*({ hrv *_t4931 = &(g543); int64_t _i4931 = f_1583; (S1*)_t4931->b + hr_ix(_i4931, _t4931->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:172"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t4932 = &(g543); int64_t _i4932 = f_1583; (S1*)_t4932->b + hr_ix(_i4932, _t4932->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:172"); }))).c_) < (((int32_t)0LL))))) { int64_t p_1586 = f290_nt(); 
(void)(f257_ow(hr_str("({ ", 3)));
(void)(f258_ct(f_1583));
(void)(f257_ow(hr_str(" _t", 3)));
(void)(f291_oi(p_1586));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f272_gx0(n_1582));
(void)(f257_ow(hr_str("; ", 2)));
if (((k_1585) == (((int64_t)9LL)))) { (void)(f257_ow(hr_str("*_t", 3)));
(void)(f291_oi(p_1586));
 } else { if (f265_is_res(d_1584)) { (void)(f257_ow(hr_str("hr_sl(*_t", 9)));
(void)(f291_oi(p_1586));
(void)(f257_ow(hr_str(")", 1)));
 } else { if (f279_is_fix(d_1584)) { (void)(f257_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f291_oi(p_1586));
(void)(({ hrv *_o4950 = &(g163); hr_fs(_o4950, hr_str("->e, ", 5)); hr_fi(_o4950, ((*({ hrv *_t4951 = &(g543); int64_t _i4951 = d_1584; (S1*)_t4951->b + hr_ix(_i4951, _t4951->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:177"); }))).b_); hr_fs(_o4950, hr_str(" }", 2)); }));
 } else { (void)(f257_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f291_oi(p_1586));
(void)(f257_ow(hr_str("->e, _t", 7)));
(void)(f291_oi(p_1586));
(void)(f257_ow(hr_str("->n }", 5)));
 }
 }
 }
(void)(f257_ow(hr_str("; })", 4)));
return;
 }
if ((((k_1585) == (((int64_t)9LL))) || ((k_1585) == (((int64_t)18LL))))) { (void)(f272_gx0(n_1582));
return;
 }
if (f265_is_res(d_1584)) { (void)(f257_ow(hr_str("hr_sl(", 6)));
if (f269_is_place(n_1582)) { (void)(f272_gx0(n_1582));
 } else { int64_t tk0_1588 = f270_tmp(d_1584, true); 
(void)(f257_ow(hr_str("*hr_tmp(&", 9)));
(void)(f271_ot(tk0_1588));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f272_gx0(n_1582));
(void)(f257_ow(hr_str(")", 1)));
 }
(void)(f257_ow(hr_str(")", 1)));
return;
 }
int64_t p_1589 = f290_nt(); 
(void)(f257_ow(hr_str("({ ", 3)));
(void)(f258_ct(d_1584));
(void)(f257_ow(hr_str(" *_t", 4)));
(void)(f291_oi(p_1589));
(void)(f257_ow(hr_str(" = ", 3)));
if (f269_is_place(n_1582)) { (void)(f257_ow(hr_str("&(", 2)));
(void)(f272_gx0(n_1582));
(void)(f257_ow(hr_str(")", 1)));
 } else { int64_t tk0_1590 = f270_tmp(d_1584, false); 
(void)(f257_ow(hr_str("&(", 2)));
(void)(f271_ot(tk0_1590));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f272_gx0(n_1582));
(void)(f257_ow(hr_str(")", 1)));
 }
(void)(f257_ow(hr_str("; ", 2)));
if (f279_is_fix(d_1584)) { (void)(f257_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f291_oi(p_1589));
(void)(({ hrv *_o4990 = &(g163); hr_fs(_o4990, hr_str("->e, ", 5)); hr_fi(_o4990, ((*({ hrv *_t4991 = &(g543); int64_t _i4991 = d_1584; (S1*)_t4991->b + hr_ix(_i4991, _t4991->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:188"); }))).b_); hr_fs(_o4990, hr_str(" }", 2)); }));
 } else { (void)(f257_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f291_oi(p_1589));
(void)(f257_ow(hr_str("->e, _t", 7)));
(void)(f291_oi(p_1589));
(void)(f257_ow(hr_str("->n }", 5)));
 }
(void)(f257_ow(hr_str("; })", 4)));
}
static int64_t f290_nt(void) {
g178++;
return g178;
}
static void f291_oi(int64_t v_1587) {
(void)(({ hrv *_o4998 = &(g163); hr_fi(_o4998, v_1587); }));
}
static void f292_gen_heq(int64_t t_1593) {
(void)(f260_cn_grow());
if ((((*({ hrv *_t5000 = &(g175); int64_t _i5000 = t_1593; (uint8_t*)_t5000->b + hr_ix(_i5000, _t5000->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:461"); }))) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t5001 = &((*({ hrv *_t5002 = &(g175); int64_t _i5002 = t_1593; (uint8_t*)_t5002->b + hr_ix(_i5002, _t5002->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:462"); }))); *_t5001 = ((uint8_t)1LL); }
S1 x_1594 = (*({ hrv *_t5003 = &(g543); int64_t _i5003 = t_1593; (S1*)_t5003->b + hr_ix(_i5003, _t5003->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:463"); })); 
int64_t k_1595 = ((int64_t)((x_1594).k_)); 
(void)(f259_cbody(t_1593));
bool sl_1596 = (((k_1595) == (((int64_t)9LL))) || ((((k_1595) == (((int64_t)8LL))) && (!(f279_is_fix(t_1593)))) && (!(f280_is_lim(t_1593))))); 
(void)(f293_comp_pre(t_1593, false));
L97 sig_1659 = ({ L97 _t5008; memset(&_t5008, 0, sizeof _t5008); _t5008.n = 0; _t5008; }); 
(void)(({ L97 *_l5009 = &(sig_1659); hrv _o5009 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5009, hr_str("static bool heq", 15)); hr_fi(&_o5009, t_1593); hr_fs(&_o5009, hr_str("(", 1)); if (_l5009->n + _o5009.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:468"); memcpy(_l5009->e + _l5009->n, _o5009.b, (size_t)_o5009.n); _l5009->n += _o5009.n; }));
hsl c_1660 = ({ hsl _r5010; if (sl_1596) { _r5010 = hr_str("hsl", 3);  } else { _r5010 = f261_cn(t_1593);  } _r5010; }); 
(void)(({ L97 *_v5012 = &(sig_1659); hsl _s5012 = c_1660; if (_v5012->n + _s5012.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:470"); memmove(_v5012->e + _v5012->n, _s5012.p, (size_t)_s5012.n * sizeof _v5012->e[0]); _v5012->n += _s5012.n; }));
(void)(({ L97 *_v5013 = &(sig_1659); hsl _s5013 = hr_str(" a, ", 4); if (_v5013->n + _s5013.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:470"); memmove(_v5013->e + _v5013->n, _s5013.p, (size_t)_s5013.n * sizeof _v5013->e[0]); _v5013->n += _s5013.n; }));
(void)(({ L97 *_v5014 = &(sig_1659); hsl _s5014 = c_1660; if (_v5014->n + _s5014.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:470"); memmove(_v5014->e + _v5014->n, _s5014.p, (size_t)_s5014.n * sizeof _v5014->e[0]); _v5014->n += _s5014.n; }));
(void)(({ L97 *_v5015 = &(sig_1659); hsl _s5015 = hr_str(" b)", 3); if (_v5015->n + _s5015.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:470"); memmove(_v5015->e + _v5015->n, _s5015.p, (size_t)_s5015.n * sizeof _v5015->e[0]); _v5015->n += _s5015.n; }));
(void)(({ hrv *_v5016 = &(g166); hsl _s5016 = ({ hsl _t5017 = ({ L97 *_t5018 = &(sig_1659); (hsl){ (uint8_t*)_t5018->e, _t5018->n }; }); int64_t _l5017 = 0, _h5017 = _t5017.n; if (_l5017 < 0 || _h5017 < _l5017 || _h5017 > _t5017.n) hr_slerr(_l5017, _h5017, _t5017.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:471"); (hsl){ _t5017.p + _l5017 * (int64_t)sizeof(uint8_t), _h5017 - _l5017 }; }); hr_append(_v5016, _s5016.p, _s5016.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5019 = &(g166); hsl _s5019 = hr_str(";\012", 2); hr_append(_v5019, _s5019.p, _s5019.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5020 = &(g169); hsl _s5020 = ({ hsl _t5021 = ({ L97 *_t5022 = &(sig_1659); (hsl){ (uint8_t*)_t5022->e, _t5022->n }; }); int64_t _l5021 = 0, _h5021 = _t5021.n; if (_l5021 < 0 || _h5021 < _l5021 || _h5021 > _t5021.n) hr_slerr(_l5021, _h5021, _t5021.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:472"); (hsl){ _t5021.p + _l5021 * (int64_t)sizeof(uint8_t), _h5021 - _l5021 }; }); hr_append(_v5020, _s5020.p, _s5020.n, sizeof(uint8_t)); }));
(void)(f298_hh(hr_str(" { ", 3)));
if ((((k_1595) == (((int64_t)5LL))) || ((k_1595) == (((int64_t)7LL))))) { int64_t si_1661 = ({ int64_t _r5024; if (((k_1595) == (((int64_t)5LL)))) { _r5024 = ((int64_t)((x_1594).a_));  } else { _r5024 = ((int64_t)(((*({ hrv *_t5025 = &(g549); int64_t _i5025 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5026 = &(g548); int64_t _i5026 = (x_1594).a_; (S8*)_t5026->b + hr_ix(_i5026, _t5026->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:474"); }))).v0_)) + (int64_t)((int64_t)((x_1594).c_)))); (S9*)_t5025->b + hr_ix(_i5025, _t5025->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:474"); }))).si_));  } _r5024; }); 
(void)(f298_hh(hr_str("return true", 11)));
if (((si_1661) >= (((int64_t)0LL)))) { int64_t f0_1662 = ((int64_t)(((*({ hrv *_t5028 = &(g546); int64_t _i5028 = si_1661; (S10*)_t5028->b + hr_ix(_i5028, _t5028->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:476"); }))).f0_)); 
{ int32_t _e5030 = ((*({ hrv *_t5031 = &(g546); int64_t _i5031 = si_1661; (S10*)_t5031->b + hr_ix(_i5031, _t5031->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:476"); }))).fnum_; for (int32_t _k5030 = 0; _k5030 < _e5030; _k5030++) { int32_t i_1663 = (int32_t)_k5030; S11 f_1664 = (*({ hrv *_t5032 = &(g547); int64_t _i5032 = ((int64_t)((int64_t)f0_1662 + (int64_t)((int64_t)(i_1663)))); (S11*)_t5032->b + hr_ix(_i5032, _t5032->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:476"); })); 
if ((((f_1664).ty_) < (((int32_t)0LL)))) { continue;
 }
L98 ea_1665 = ({ L98 _t5033; memset(&_t5033, 0, sizeof _t5033); _t5033.n = 0; _t5033; }); 
L98 eb_1666 = ({ L98 _t5034; memset(&_t5034, 0, sizeof _t5034); _t5034.n = 0; _t5034; }); 
(void)(({ L98 *_v5035 = &(ea_1665); hsl _s5035 = hr_str("a.", 2); if (_v5035->n + _s5035.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:476"); memmove(_v5035->e + _v5035->n, _s5035.p, (size_t)_s5035.n * sizeof _v5035->e[0]); _v5035->n += _s5035.n; }));
(void)(({ L98 *_v5036 = &(eb_1666); hsl _s5036 = hr_str("b.", 2); if (_v5036->n + _s5036.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:476"); memmove(_v5036->e + _v5036->n, _s5036.p, (size_t)_s5036.n * sizeof _v5036->e[0]); _v5036->n += _s5036.n; }));
{ hsl _v5038 = f10_nm(((int64_t)((f_1664).name_))); for (int64_t _k5038 = 0; _k5038 < _v5038.n; _k5038++) { uint8_t ch_1667 = ((uint8_t*)_v5038.p)[_k5038]; (void)(({ L98 *_v5040 = &(ea_1665); uint8_t _x5040 = ch_1667; if (_v5040->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:476"); _v5040->e[_v5040->n] = _x5040; &_v5040->e[_v5040->n++]; }));
(void)(({ L98 *_v5041 = &(eb_1666); uint8_t _x5041 = ch_1667; if (_v5041->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:476"); _v5041->e[_v5041->n] = _x5041; &_v5041->e[_v5041->n++]; }));
 } } _bk5037:; 
(void)(({ L98 *_v5042 = &(ea_1665); uint8_t _x5042 = ((uint8_t)95LL); if (_v5042->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:476"); _v5042->e[_v5042->n] = _x5042; &_v5042->e[_v5042->n++]; }));
(void)(({ L98 *_v5043 = &(eb_1666); uint8_t _x5043 = ((uint8_t)95LL); if (_v5043->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:476"); _v5043->e[_v5043->n] = _x5043; &_v5043->e[_v5043->n++]; }));
(void)(f298_hh(hr_str(" && ", 4)));
(void)(f300_heq_val(((int64_t)((f_1664).ty_)), ({ hsl _t5046 = ({ L98 *_t5047 = &(ea_1665); (hsl){ (uint8_t*)_t5047->e, _t5047->n }; }); int64_t _l5046 = 0, _h5046 = _t5046.n; if (_l5046 < 0 || _h5046 < _l5046 || _h5046 > _t5046.n) hr_slerr(_l5046, _h5046, _t5046.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:476"); (hsl){ _t5046.p + _l5046 * (int64_t)sizeof(uint8_t), _h5046 - _l5046 }; }), ({ hsl _t5048 = ({ L98 *_t5049 = &(eb_1666); (hsl){ (uint8_t*)_t5049->e, _t5049->n }; }); int64_t _l5048 = 0, _h5048 = _t5048.n; if (_l5048 < 0 || _h5048 < _l5048 || _h5048 > _t5048.n) hr_slerr(_l5048, _h5048, _t5048.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:476"); (hsl){ _t5048.p + _l5048 * (int64_t)sizeof(uint8_t), _h5048 - _l5048 }; })));
 } } _bk5029:; 
 }
(void)(f298_hh(hr_str("; ", 2)));
 }
if (((k_1595) == (((int64_t)6LL)))) { int64_t ei_1672 = ((int64_t)((x_1594).a_)); 
int64_t v0_1673 = ((int64_t)(((*({ hrv *_t5051 = &(g548); int64_t _i5051 = ei_1672; (S8*)_t5051->b + hr_ix(_i5051, _t5051->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:480"); }))).v0_)); 
(void)(f298_hh(hr_str("if (a.tag != b.tag) return false; ", 34)));
{ int32_t _e5054 = ((*({ hrv *_t5055 = &(g548); int64_t _i5055 = ei_1672; (S8*)_t5055->b + hr_ix(_i5055, _t5055->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:482"); }))).vnum_; for (int32_t _k5054 = 0; _k5054 < _e5054; _k5054++) { int32_t i_1674 = (int32_t)_k5054; S9 v_1675 = (*({ hrv *_t5056 = &(g549); int64_t _i5056 = ((int64_t)((int64_t)v0_1673 + (int64_t)((int64_t)(i_1674)))); (S9*)_t5056->b + hr_ix(_i5056, _t5056->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:482"); })); 
if (((((v_1675).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t5057 = &(g546); int64_t _i5057 = (v_1675).si_; (S10*)_t5057->b + hr_ix(_i5057, _t5057->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:482"); }))).zero_)))) { L100 ea_1676 = ({ L100 _t5058; memset(&_t5058, 0, sizeof _t5058); _t5058.n = 0; _t5058; }); 
L100 eb_1677 = ({ L100 _t5059; memset(&_t5059, 0, sizeof _t5059); _t5059.n = 0; _t5059; }); 
(void)(({ L100 *_l5060 = &(ea_1676); hrv _o5060 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5060, hr_str("a.u.v", 5)); hr_fi(&_o5060, i_1674); if (_l5060->n + _o5060.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:482"); memcpy(_l5060->e + _l5060->n, _o5060.b, (size_t)_o5060.n); _l5060->n += _o5060.n; }));
(void)(({ L100 *_l5061 = &(eb_1677); hrv _o5061 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5061, hr_str("b.u.v", 5)); hr_fi(&_o5061, i_1674); if (_l5061->n + _o5061.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:482"); memcpy(_l5061->e + _l5061->n, _o5061.b, (size_t)_o5061.n); _l5061->n += _o5061.n; }));
(void)(({ hrv *_o5062 = &(g169); hr_fs(_o5062, hr_str("if (a.tag == ", 13)); hr_fi(_o5062, i_1674); hr_fs(_o5062, hr_str(") return ", 9)); }));
(void)(f300_heq_val(f125_t_variant(ei_1672, ((int64_t)(i_1674))), ({ hsl _t5065 = ({ L100 *_t5066 = &(ea_1676); (hsl){ (uint8_t*)_t5066->e, _t5066->n }; }); int64_t _l5065 = 0, _h5065 = _t5065.n; if (_l5065 < 0 || _h5065 < _l5065 || _h5065 > _t5065.n) hr_slerr(_l5065, _h5065, _t5065.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:482"); (hsl){ _t5065.p + _l5065 * (int64_t)sizeof(uint8_t), _h5065 - _l5065 }; }), ({ hsl _t5067 = ({ L100 *_t5068 = &(eb_1677); (hsl){ (uint8_t*)_t5068->e, _t5068->n }; }); int64_t _l5067 = 0, _h5067 = _t5067.n; if (_l5067 < 0 || _h5067 < _l5067 || _h5067 > _t5067.n) hr_slerr(_l5067, _h5067, _t5067.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:482"); (hsl){ _t5067.p + _l5067 * (int64_t)sizeof(uint8_t), _h5067 - _l5067 }; })));
(void)(f298_hh(hr_str("; ", 2)));
 }
 } } _bk5053:; 
(void)(f298_hh(hr_str("return true; ", 13)));
 }
if ((((k_1595) == (((int64_t)8LL))) || ((k_1595) == (((int64_t)9LL))))) { int64_t e_1678 = ((int64_t)((x_1594).a_)); 
L98 ea_1679 = ({ L98 _t5071; memset(&_t5071, 0, sizeof _t5071); _t5071.n = 0; _t5071; }); 
L98 eb_1680 = ({ L98 _t5072; memset(&_t5072, 0, sizeof _t5072); _t5072.n = 0; _t5072; }); 
if (f279_is_fix(t_1593)) { (void)(({ hrv *_o5074 = &(g169); hr_fs(_o5074, hr_str("for (int64_t i = 0; i < ", 24)); hr_fi(_o5074, (x_1594).b_); hr_fs(_o5074, hr_str("; i++) if (!(", 13)); }));
(void)(({ L98 *_v5075 = &(ea_1679); hsl _s5075 = hr_str("a.e[i]", 6); if (_v5075->n + _s5075.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:488"); memmove(_v5075->e + _v5075->n, _s5075.p, (size_t)_s5075.n * sizeof _v5075->e[0]); _v5075->n += _s5075.n; }));
(void)(({ L98 *_v5076 = &(eb_1680); hsl _s5076 = hr_str("b.e[i]", 6); if (_v5076->n + _s5076.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:488"); memmove(_v5076->e + _v5076->n, _s5076.p, (size_t)_s5076.n * sizeof _v5076->e[0]); _v5076->n += _s5076.n; }));
 } else { if (f280_is_lim(t_1593)) { (void)(f298_hh(hr_str("if (a.n != b.n) return false; for (int64_t i = 0; i < a.n; i++) if (!(", 70)));
(void)(({ L98 *_v5079 = &(ea_1679); hsl _s5079 = hr_str("a.e[i]", 6); if (_v5079->n + _s5079.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:489"); memmove(_v5079->e + _v5079->n, _s5079.p, (size_t)_s5079.n * sizeof _v5079->e[0]); _v5079->n += _s5079.n; }));
(void)(({ L98 *_v5080 = &(eb_1680); hsl _s5080 = hr_str("b.e[i]", 6); if (_v5080->n + _s5080.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:489"); memmove(_v5080->e + _v5080->n, _s5080.p, (size_t)_s5080.n * sizeof _v5080->e[0]); _v5080->n += _s5080.n; }));
 } else { (void)(f298_hh(hr_str("if (a.n != b.n) return false; for (int64_t i = 0; i < a.n; i++) if (!(", 70)));
(void)(({ L98 *_v5082 = &(ea_1679); hsl _s5082 = hr_str("((", 2); if (_v5082->n + _s5082.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:490"); memmove(_v5082->e + _v5082->n, _s5082.p, (size_t)_s5082.n * sizeof _v5082->e[0]); _v5082->n += _s5082.n; }));
(void)(({ L98 *_v5083 = &(ea_1679); hsl _s5083 = f261_cn(e_1678); if (_v5083->n + _s5083.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:490"); memmove(_v5083->e + _v5083->n, _s5083.p, (size_t)_s5083.n * sizeof _v5083->e[0]); _v5083->n += _s5083.n; }));
(void)(({ L98 *_v5085 = &(ea_1679); hsl _s5085 = hr_str("*)a.p)[i]", 9); if (_v5085->n + _s5085.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:490"); memmove(_v5085->e + _v5085->n, _s5085.p, (size_t)_s5085.n * sizeof _v5085->e[0]); _v5085->n += _s5085.n; }));
(void)(({ L98 *_v5086 = &(eb_1680); hsl _s5086 = hr_str("((", 2); if (_v5086->n + _s5086.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:490"); memmove(_v5086->e + _v5086->n, _s5086.p, (size_t)_s5086.n * sizeof _v5086->e[0]); _v5086->n += _s5086.n; }));
(void)(({ L98 *_v5087 = &(eb_1680); hsl _s5087 = f261_cn(e_1678); if (_v5087->n + _s5087.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:490"); memmove(_v5087->e + _v5087->n, _s5087.p, (size_t)_s5087.n * sizeof _v5087->e[0]); _v5087->n += _s5087.n; }));
(void)(({ L98 *_v5089 = &(eb_1680); hsl _s5089 = hr_str("*)b.p)[i]", 9); if (_v5089->n + _s5089.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:490"); memmove(_v5089->e + _v5089->n, _s5089.p, (size_t)_s5089.n * sizeof _v5089->e[0]); _v5089->n += _s5089.n; }));
 }
 }
(void)(f300_heq_val(e_1678, ({ hsl _t5091 = ({ L98 *_t5092 = &(ea_1679); (hsl){ (uint8_t*)_t5092->e, _t5092->n }; }); int64_t _l5091 = 0, _h5091 = _t5091.n; if (_l5091 < 0 || _h5091 < _l5091 || _h5091 > _t5091.n) hr_slerr(_l5091, _h5091, _t5091.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:491"); (hsl){ _t5091.p + _l5091 * (int64_t)sizeof(uint8_t), _h5091 - _l5091 }; }), ({ hsl _t5093 = ({ L98 *_t5094 = &(eb_1680); (hsl){ (uint8_t*)_t5094->e, _t5094->n }; }); int64_t _l5093 = 0, _h5093 = _t5093.n; if (_l5093 < 0 || _h5093 < _l5093 || _h5093 > _t5093.n) hr_slerr(_l5093, _h5093, _t5093.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:491"); (hsl){ _t5093.p + _l5093 * (int64_t)sizeof(uint8_t), _h5093 - _l5093 }; })));
(void)(f298_hh(hr_str(")) return false; return true; ", 30)));
 }
if (((k_1595) == (((int64_t)14LL)))) { (void)(f298_hh(hr_str("return true; ", 13)));
 }
(void)(f298_hh(hr_str("}\012", 2)));
}
static void f293_comp_pre(int64_t t_1597, bool fmt_1598) {
S1 x_1599 = (*({ hrv *_t5098 = &(g543); int64_t _i5098 = t_1597; (S1*)_t5098->b + hr_ix(_i5098, _t5098->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:385"); })); 
int64_t k_1600 = ((int64_t)((x_1599).k_)); 
if (((k_1600) == (((int64_t)5LL)))) { int64_t si_1601 = ((int64_t)((x_1599).a_)); 
{ int32_t _e5100 = ((*({ hrv *_t5101 = &(g546); int64_t _i5101 = si_1601; (S10*)_t5101->b + hr_ix(_i5101, _t5101->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:386"); }))).fnum_; for (int32_t _k5100 = 0; _k5100 < _e5100; _k5100++) { int32_t i_1602 = (int32_t)_k5100; S11 f_1603 = (*({ hrv *_t5102 = &(g547); int64_t _i5102 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5103 = &(g546); int64_t _i5103 = si_1601; (S10*)_t5103->b + hr_ix(_i5103, _t5103->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:386"); }))).f0_)) + (int64_t)((int64_t)(i_1602)))); (S11*)_t5102->b + hr_ix(_i5102, _t5102->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:386"); })); 
if ((((f_1603).ty_) >= (((int32_t)0LL)))) { (void)(f294_comp_one(((int64_t)((f_1603).ty_)), fmt_1598));
 }
 } } _bk5099:; 
 }
if (((k_1600) == (((int64_t)7LL)))) { S9 v_1650 = (*({ hrv *_t5105 = &(g549); int64_t _i5105 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5106 = &(g548); int64_t _i5106 = (x_1599).a_; (S8*)_t5106->b + hr_ix(_i5106, _t5106->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:387"); }))).v0_)) + (int64_t)((int64_t)((x_1599).c_)))); (S9*)_t5105->b + hr_ix(_i5105, _t5105->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:387"); })); 
if ((((v_1650).si_) >= (((int32_t)0LL)))) { { int32_t _e5108 = ((*({ hrv *_t5109 = &(g546); int64_t _i5109 = (v_1650).si_; (S10*)_t5109->b + hr_ix(_i5109, _t5109->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:387"); }))).fnum_; for (int32_t _k5108 = 0; _k5108 < _e5108; _k5108++) { int32_t i_1651 = (int32_t)_k5108; S11 f_1652 = (*({ hrv *_t5110 = &(g547); int64_t _i5110 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5111 = &(g546); int64_t _i5111 = (v_1650).si_; (S10*)_t5111->b + hr_ix(_i5111, _t5111->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:387"); }))).f0_)) + (int64_t)((int64_t)(i_1651)))); (S11*)_t5110->b + hr_ix(_i5110, _t5110->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:387"); })); 
if ((((f_1652).ty_) >= (((int32_t)0LL)))) { (void)(f294_comp_one(((int64_t)((f_1652).ty_)), fmt_1598));
 }
 } } _bk5107:; 
 }
 }
if (((k_1600) == (((int64_t)6LL)))) { int64_t ei_1653 = ((int64_t)((x_1599).a_)); 
{ int32_t _e5114 = ((*({ hrv *_t5115 = &(g548); int64_t _i5115 = ei_1653; (S8*)_t5115->b + hr_ix(_i5115, _t5115->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:388"); }))).vnum_; for (int32_t _k5114 = 0; _k5114 < _e5114; _k5114++) { int32_t i_1654 = (int32_t)_k5114; S9 v_1655 = (*({ hrv *_t5116 = &(g549); int64_t _i5116 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5117 = &(g548); int64_t _i5117 = ei_1653; (S8*)_t5117->b + hr_ix(_i5117, _t5117->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:388"); }))).v0_)) + (int64_t)((int64_t)(i_1654)))); (S9*)_t5116->b + hr_ix(_i5116, _t5116->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:388"); })); 
if (((((v_1655).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t5118 = &(g546); int64_t _i5118 = (v_1655).si_; (S10*)_t5118->b + hr_ix(_i5118, _t5118->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:388"); }))).zero_)))) { if (fmt_1598) { { int32_t _e5120 = ((*({ hrv *_t5121 = &(g546); int64_t _i5121 = (v_1655).si_; (S10*)_t5121->b + hr_ix(_i5121, _t5121->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:388"); }))).fnum_; for (int32_t _k5120 = 0; _k5120 < _e5120; _k5120++) { int32_t j_1656 = (int32_t)_k5120; S11 f_1657 = (*({ hrv *_t5122 = &(g547); int64_t _i5122 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5123 = &(g546); int64_t _i5123 = (v_1655).si_; (S10*)_t5123->b + hr_ix(_i5123, _t5123->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:388"); }))).f0_)) + (int64_t)((int64_t)(j_1656)))); (S11*)_t5122->b + hr_ix(_i5122, _t5122->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:388"); })); 
if ((((f_1657).ty_) >= (((int32_t)0LL)))) { (void)(f294_comp_one(((int64_t)((f_1657).ty_)), fmt_1598));
 }
 } } _bk5119:; 
 } else { (void)(f292_gen_heq(f125_t_variant(ei_1653, ((int64_t)(i_1654)))));
 }
 }
 } } _bk5113:; 
 }
if ((((k_1600) == (((int64_t)8LL))) || ((k_1600) == (((int64_t)9LL))))) { (void)(f294_comp_one(((int64_t)((x_1599).a_)), fmt_1598));
 }
if (((k_1600) == (((int64_t)14LL)))) { { int32_t _e5129 = (x_1599).n_; for (int32_t _k5129 = 0; _k5129 < _e5129; _k5129++) { int32_t i_1658 = (int32_t)_k5129; (void)(f294_comp_one(((int64_t)((*({ hrv *_t5131 = &(g544); int64_t _i5131 = ((int64_t)((int64_t)((int64_t)((x_1599).l_)) + (int64_t)((int64_t)(i_1658)))); (int32_t*)_t5131->b + hr_ix(_i5131, _t5131->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:390"); })))), fmt_1598));
 } } _bk5128:; 
 }
}
static void f294_comp_one(int64_t t_1604, bool fmt_1605) {
int64_t u_1606 = ({ int64_t _r5132; if (((((*({ hrv *_t5133 = &(g543); int64_t _i5133 = t_1604; (S1*)_t5133->b + hr_ix(_i5133, _t5133->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:383"); }))).k_) == (((uint8_t)10LL)))) { _r5132 = ((int64_t)(((*({ hrv *_t5134 = &(g543); int64_t _i5134 = t_1604; (S1*)_t5134->b + hr_ix(_i5134, _t5134->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:383"); }))).a_));  } else { _r5132 = t_1604;  } _r5132; }); 
if ((((((*({ hrv *_t5135 = &(g543); int64_t _i5135 = t_1604; (S1*)_t5135->b + hr_ix(_i5135, _t5135->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:383"); }))).k_) == (((uint8_t)10LL))) && (!(fmt_1605)))) { return;
 }
if (f295_need_helper(u_1606)) { if (fmt_1605) { (void)(f296_gen_hf(u_1606));
 } else { (void)(f292_gen_heq(u_1606));
 }
 }
}
static bool f295_need_helper(int64_t t_1607) {
int64_t k_1608 = ((int64_t)(((*({ hrv *_t5139 = &(g543); int64_t _i5139 = t_1607; (S1*)_t5139->b + hr_ix(_i5139, _t5139->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:382"); }))).k_)); 
if (f164_is_byte_arr(t_1607)) { return false;
 }
if (((k_1608) == (((int64_t)10LL)))) { return f295_need_helper(((int64_t)(((*({ hrv *_t5142 = &(g543); int64_t _i5142 = t_1607; (S1*)_t5142->b + hr_ix(_i5142, _t5142->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:382"); }))).a_)));
 }
return (((((((k_1608) == (((int64_t)5LL))) || ((k_1608) == (((int64_t)6LL)))) || ((k_1608) == (((int64_t)7LL)))) || ((k_1608) == (((int64_t)8LL)))) || ((k_1608) == (((int64_t)9LL)))) || ((k_1608) == (((int64_t)14LL))));
}
static void f296_gen_hf(int64_t t_1609) {
(void)(f260_cn_grow());
if ((((*({ hrv *_t5144 = &(g174); int64_t _i5144 = t_1609; (uint8_t*)_t5144->b + hr_ix(_i5144, _t5144->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:405"); }))) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t5145 = &((*({ hrv *_t5146 = &(g174); int64_t _i5146 = t_1609; (uint8_t*)_t5146->b + hr_ix(_i5146, _t5146->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:406"); }))); *_t5145 = ((uint8_t)1LL); }
S1 x_1610 = (*({ hrv *_t5147 = &(g543); int64_t _i5147 = t_1609; (S1*)_t5147->b + hr_ix(_i5147, _t5147->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:407"); })); 
int64_t k_1611 = ((int64_t)((x_1610).k_)); 
(void)(f259_cbody(t_1609));
bool sl_1612 = (((k_1611) == (((int64_t)9LL))) || ((((k_1611) == (((int64_t)8LL))) && (!(f279_is_fix(t_1609)))) && (!(f280_is_lim(t_1609))))); 
(void)(f297_hf_pre(t_1609));
L97 sig_1614 = ({ L97 _t5152; memset(&_t5152, 0, sizeof _t5152); _t5152.n = 0; _t5152; }); 
(void)(({ L97 *_l5153 = &(sig_1614); hrv _o5153 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5153, hr_str("static void hf", 14)); hr_fi(&_o5153, t_1609); hr_fs(&_o5153, hr_str("(hrv *o, ", 9)); if (_l5153->n + _o5153.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:412"); memcpy(_l5153->e + _l5153->n, _o5153.b, (size_t)_o5153.n); _l5153->n += _o5153.n; }));
(void)(({ L97 *_v5154 = &(sig_1614); hsl _s5154 = ({ hsl _r5155; if (sl_1612) { _r5155 = hr_str("hsl", 3);  } else { _r5155 = f261_cn(t_1609);  } _r5155; }); if (_v5154->n + _s5154.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:413"); memmove(_v5154->e + _v5154->n, _s5154.p, (size_t)_s5154.n * sizeof _v5154->e[0]); _v5154->n += _s5154.n; }));
(void)(({ L97 *_v5157 = &(sig_1614); hsl _s5157 = hr_str(" v)", 3); if (_v5157->n + _s5157.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:414"); memmove(_v5157->e + _v5157->n, _s5157.p, (size_t)_s5157.n * sizeof _v5157->e[0]); _v5157->n += _s5157.n; }));
(void)(({ hrv *_v5158 = &(g166); hsl _s5158 = ({ hsl _t5159 = ({ L97 *_t5160 = &(sig_1614); (hsl){ (uint8_t*)_t5160->e, _t5160->n }; }); int64_t _l5159 = 0, _h5159 = _t5159.n; if (_l5159 < 0 || _h5159 < _l5159 || _h5159 > _t5159.n) hr_slerr(_l5159, _h5159, _t5159.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:415"); (hsl){ _t5159.p + _l5159 * (int64_t)sizeof(uint8_t), _h5159 - _l5159 }; }); hr_append(_v5158, _s5158.p, _s5158.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5161 = &(g166); hsl _s5161 = hr_str(";\012", 2); hr_append(_v5161, _s5161.p, _s5161.n, sizeof(uint8_t)); }));
int64_t s0_1615 = (g169).n; 
(void)(({ hrv *_v5162 = &(g169); hsl _s5162 = ({ hsl _t5163 = ({ L97 *_t5164 = &(sig_1614); (hsl){ (uint8_t*)_t5164->e, _t5164->n }; }); int64_t _l5163 = 0, _h5163 = _t5163.n; if (_l5163 < 0 || _h5163 < _l5163 || _h5163 > _t5163.n) hr_slerr(_l5163, _h5163, _t5163.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:417"); (hsl){ _t5163.p + _l5163 * (int64_t)sizeof(uint8_t), _h5163 - _l5163 }; }); hr_append(_v5162, _s5162.p, _s5162.n, sizeof(uint8_t)); }));
(void)(f298_hh(hr_str(" { ", 3)));
if (((k_1611) == (((int64_t)5LL)))) { int64_t si_1617 = ((int64_t)((x_1610).a_)); 
int64_t f0_1618 = ((int64_t)(((*({ hrv *_t5166 = &(g546); int64_t _i5166 = si_1617; (S10*)_t5166->b + hr_ix(_i5166, _t5166->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:419"); }))).f0_)); 
(void)(f298_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f298_hh(f10_nm(((int64_t)(((*({ hrv *_t5170 = &(g546); int64_t _i5170 = si_1617; (S10*)_t5170->b + hr_ix(_i5170, _t5170->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:420"); }))).name_)))));
(void)(f298_hh(hr_str(" { \"); ", 7)));
bool first_1619 = true; 
{ int32_t _e5173 = ((*({ hrv *_t5174 = &(g546); int64_t _i5174 = si_1617; (S10*)_t5174->b + hr_ix(_i5174, _t5174->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:422"); }))).fnum_; for (int32_t _k5173 = 0; _k5173 < _e5173; _k5173++) { int32_t i_1620 = (int32_t)_k5173; S11 f_1621 = (*({ hrv *_t5175 = &(g547); int64_t _i5175 = ((int64_t)((int64_t)f0_1618 + (int64_t)((int64_t)(i_1620)))); (S11*)_t5175->b + hr_ix(_i5175, _t5175->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:422"); })); 
if ((((f_1621).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1619))) { (void)(f298_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1619 = false;
L98 e_1622 = ({ L98 _t5177; memset(&_t5177, 0, sizeof _t5177); _t5177.n = 0; _t5177; }); 
(void)(({ L98 *_v5178 = &(e_1622); hsl _s5178 = hr_str("v.", 2); if (_v5178->n + _s5178.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:422"); memmove(_v5178->e + _v5178->n, _s5178.p, (size_t)_s5178.n * sizeof _v5178->e[0]); _v5178->n += _s5178.n; }));
{ hsl _v5180 = f10_nm(((int64_t)((f_1621).name_))); for (int64_t _k5180 = 0; _k5180 < _v5180.n; _k5180++) { uint8_t c_1623 = ((uint8_t*)_v5180.p)[_k5180]; (void)(({ L98 *_v5182 = &(e_1622); uint8_t _x5182 = c_1623; if (_v5182->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:422"); _v5182->e[_v5182->n] = _x5182; &_v5182->e[_v5182->n++]; }));
 } } _bk5179:; 
(void)(({ L98 *_v5183 = &(e_1622); uint8_t _x5183 = ((uint8_t)95LL); if (_v5183->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:422"); _v5183->e[_v5183->n] = _x5183; &_v5183->e[_v5183->n++]; }));
(void)(f299_hf_val(((int64_t)((f_1621).ty_)), ({ hsl _t5185 = ({ L98 *_t5186 = &(e_1622); (hsl){ (uint8_t*)_t5186->e, _t5186->n }; }); int64_t _l5185 = 0, _h5185 = _t5185.n; if (_l5185 < 0 || _h5185 < _l5185 || _h5185 > _t5185.n) hr_slerr(_l5185, _h5185, _t5185.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:422"); (hsl){ _t5185.p + _l5185 * (int64_t)sizeof(uint8_t), _h5185 - _l5185 }; })));
 } } _bk5172:; 
(void)(f298_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 }
if (((k_1611) == (((int64_t)6LL)))) { int64_t ei_1628 = ((int64_t)((x_1610).a_)); 
int64_t v0_1629 = ((int64_t)(((*({ hrv *_t5188 = &(g548); int64_t _i5188 = ei_1628; (S8*)_t5188->b + hr_ix(_i5188, _t5188->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:426"); }))).v0_)); 
{ int32_t _e5190 = ((*({ hrv *_t5191 = &(g548); int64_t _i5191 = ei_1628; (S8*)_t5191->b + hr_ix(_i5191, _t5191->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:427"); }))).vnum_; for (int32_t _k5190 = 0; _k5190 < _e5190; _k5190++) { int32_t i_1630 = (int32_t)_k5190; S9 v_1631 = (*({ hrv *_t5192 = &(g549); int64_t _i5192 = ((int64_t)((int64_t)v0_1629 + (int64_t)((int64_t)(i_1630)))); (S9*)_t5192->b + hr_ix(_i5192, _t5192->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:428"); })); 
(void)(({ hrv *_o5193 = &(g169); hr_fs(_o5193, hr_str("if (v.tag == ", 13)); hr_fi(_o5193, i_1630); hr_fs(_o5193, hr_str(") { ", 4)); }));
if (((((v_1631).si_) >= (((int32_t)0LL))) && ((((*({ hrv *_t5194 = &(g546); int64_t _i5194 = (v_1631).si_; (S10*)_t5194->b + hr_ix(_i5194, _t5194->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:430"); }))).fnum_) > (((int32_t)0LL))))) { (void)(f298_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f298_hh(f10_nm(((int64_t)((v_1631).name_)))));
(void)(f298_hh(hr_str(" { \"); ", 7)));
bool first_1632 = true; 
int64_t sf0_1633 = ((int64_t)(((*({ hrv *_t5199 = &(g546); int64_t _i5199 = (v_1631).si_; (S10*)_t5199->b + hr_ix(_i5199, _t5199->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:430"); }))).f0_)); 
{ int32_t _e5201 = ((*({ hrv *_t5202 = &(g546); int64_t _i5202 = (v_1631).si_; (S10*)_t5202->b + hr_ix(_i5202, _t5202->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:430"); }))).fnum_; for (int32_t _k5201 = 0; _k5201 < _e5201; _k5201++) { int32_t j_1634 = (int32_t)_k5201; S11 f_1635 = (*({ hrv *_t5203 = &(g547); int64_t _i5203 = ((int64_t)((int64_t)sf0_1633 + (int64_t)((int64_t)(j_1634)))); (S11*)_t5203->b + hr_ix(_i5203, _t5203->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:430"); })); 
if ((((f_1635).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1632))) { (void)(f298_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1632 = false;
L98 e_1636 = ({ L98 _t5205; memset(&_t5205, 0, sizeof _t5205); _t5205.n = 0; _t5205; }); 
(void)(({ L98 *_l5206 = &(e_1636); hrv _o5206 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5206, hr_str("v.u.v", 5)); hr_fi(&_o5206, i_1630); hr_fs(&_o5206, hr_str(".", 1)); if (_l5206->n + _o5206.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:430"); memcpy(_l5206->e + _l5206->n, _o5206.b, (size_t)_o5206.n); _l5206->n += _o5206.n; }));
{ hsl _v5208 = f10_nm(((int64_t)((f_1635).name_))); for (int64_t _k5208 = 0; _k5208 < _v5208.n; _k5208++) { uint8_t c_1637 = ((uint8_t*)_v5208.p)[_k5208]; (void)(({ L98 *_v5210 = &(e_1636); uint8_t _x5210 = c_1637; if (_v5210->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:430"); _v5210->e[_v5210->n] = _x5210; &_v5210->e[_v5210->n++]; }));
 } } _bk5207:; 
(void)(({ L98 *_v5211 = &(e_1636); uint8_t _x5211 = ((uint8_t)95LL); if (_v5211->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:430"); _v5211->e[_v5211->n] = _x5211; &_v5211->e[_v5211->n++]; }));
(void)(f299_hf_val(((int64_t)((f_1635).ty_)), ({ hsl _t5213 = ({ L98 *_t5214 = &(e_1636); (hsl){ (uint8_t*)_t5214->e, _t5214->n }; }); int64_t _l5213 = 0, _h5213 = _t5213.n; if (_l5213 < 0 || _h5213 < _l5213 || _h5213 > _t5213.n) hr_slerr(_l5213, _h5213, _t5213.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:430"); (hsl){ _t5213.p + _l5213 * (int64_t)sizeof(uint8_t), _h5213 - _l5213 }; })));
 } } _bk5200:; 
(void)(f298_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 } else { (void)(f298_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f298_hh(f10_nm(((int64_t)(((*({ hrv *_t5219 = &(g548); int64_t _i5219 = ei_1628; (S8*)_t5219->b + hr_ix(_i5219, _t5219->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:431"); }))).name_)))));
(void)(f298_hh(hr_str(".", 1)));
(void)(f298_hh(f10_nm(((int64_t)((v_1631).name_)))));
(void)(f298_hh(hr_str("\"); ", 4)));
 }
(void)(f298_hh(hr_str("} ", 2)));
 } } _bk5189:; 
 }
if (((k_1611) == (((int64_t)7LL)))) { int64_t ei_1638 = ((int64_t)((x_1610).a_)); 
S9 v_1639 = (*({ hrv *_t5225 = &(g549); int64_t _i5225 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t5226 = &(g548); int64_t _i5226 = ei_1638; (S8*)_t5226->b + hr_ix(_i5226, _t5226->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:436"); }))).v0_)) + (int64_t)((int64_t)((x_1610).c_)))); (S9*)_t5225->b + hr_ix(_i5225, _t5225->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:436"); })); 
if (((((v_1639).si_) >= (((int32_t)0LL))) && ((((*({ hrv *_t5227 = &(g546); int64_t _i5227 = (v_1639).si_; (S10*)_t5227->b + hr_ix(_i5227, _t5227->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:437"); }))).fnum_) > (((int32_t)0LL))))) { (void)(f298_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f298_hh(f10_nm(((int64_t)((v_1639).name_)))));
(void)(f298_hh(hr_str(" { \"); ", 7)));
bool first_1640 = true; 
int64_t sf0_1641 = ((int64_t)(((*({ hrv *_t5232 = &(g546); int64_t _i5232 = (v_1639).si_; (S10*)_t5232->b + hr_ix(_i5232, _t5232->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:437"); }))).f0_)); 
{ int32_t _e5234 = ((*({ hrv *_t5235 = &(g546); int64_t _i5235 = (v_1639).si_; (S10*)_t5235->b + hr_ix(_i5235, _t5235->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:437"); }))).fnum_; for (int32_t _k5234 = 0; _k5234 < _e5234; _k5234++) { int32_t j_1642 = (int32_t)_k5234; S11 f_1643 = (*({ hrv *_t5236 = &(g547); int64_t _i5236 = ((int64_t)((int64_t)sf0_1641 + (int64_t)((int64_t)(j_1642)))); (S11*)_t5236->b + hr_ix(_i5236, _t5236->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:437"); })); 
if ((((f_1643).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1640))) { (void)(f298_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1640 = false;
L98 e_1644 = ({ L98 _t5238; memset(&_t5238, 0, sizeof _t5238); _t5238.n = 0; _t5238; }); 
(void)(({ L98 *_v5239 = &(e_1644); hsl _s5239 = hr_str("v.", 2); if (_v5239->n + _s5239.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:437"); memmove(_v5239->e + _v5239->n, _s5239.p, (size_t)_s5239.n * sizeof _v5239->e[0]); _v5239->n += _s5239.n; }));
{ hsl _v5241 = f10_nm(((int64_t)((f_1643).name_))); for (int64_t _k5241 = 0; _k5241 < _v5241.n; _k5241++) { uint8_t c_1645 = ((uint8_t*)_v5241.p)[_k5241]; (void)(({ L98 *_v5243 = &(e_1644); uint8_t _x5243 = c_1645; if (_v5243->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:437"); _v5243->e[_v5243->n] = _x5243; &_v5243->e[_v5243->n++]; }));
 } } _bk5240:; 
(void)(({ L98 *_v5244 = &(e_1644); uint8_t _x5244 = ((uint8_t)95LL); if (_v5244->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:437"); _v5244->e[_v5244->n] = _x5244; &_v5244->e[_v5244->n++]; }));
(void)(f299_hf_val(((int64_t)((f_1643).ty_)), ({ hsl _t5246 = ({ L98 *_t5247 = &(e_1644); (hsl){ (uint8_t*)_t5247->e, _t5247->n }; }); int64_t _l5246 = 0, _h5246 = _t5246.n; if (_l5246 < 0 || _h5246 < _l5246 || _h5246 > _t5246.n) hr_slerr(_l5246, _h5246, _t5246.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:437"); (hsl){ _t5246.p + _l5246 * (int64_t)sizeof(uint8_t), _h5246 - _l5246 }; })));
 } } _bk5233:; 
(void)(f298_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 } else { (void)(f298_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f298_hh(f10_nm(((int64_t)(((*({ hrv *_t5252 = &(g548); int64_t _i5252 = ei_1638; (S8*)_t5252->b + hr_ix(_i5252, _t5252->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:438"); }))).name_)))));
(void)(f298_hh(hr_str(".", 1)));
(void)(f298_hh(f10_nm(((int64_t)((v_1639).name_)))));
(void)(f298_hh(hr_str("\"); ", 4)));
 }
 }
if ((((k_1611) == (((int64_t)8LL))) || ((k_1611) == (((int64_t)9LL))))) { int64_t e_1646 = ((int64_t)((x_1610).a_)); 
(void)(f259_cbody(e_1646));
(void)(f298_hh(hr_str("hr_fb(o, '['); ", 15)));
if (f279_is_fix(t_1609)) { (void)(({ hrv *_o5260 = &(g169); hr_fs(_o5260, hr_str("for (int64_t i = 0; i < ", 24)); hr_fi(_o5260, (x_1610).b_); hr_fs(_o5260, hr_str("; i++) { if (i) hr_fc(o, \", \"); ", 32)); }));
(void)(f299_hf_val(e_1646, hr_str("v.e[i]", 6)));
(void)(f298_hh(hr_str("} ", 2)));
 } else { if (f280_is_lim(t_1609)) { (void)(f298_hh(hr_str("for (int64_t i = 0; i < v.n; i++) { if (i) hr_fc(o, \", \"); ", 59)));
(void)(f299_hf_val(e_1646, hr_str("v.e[i]", 6)));
(void)(f298_hh(hr_str("} ", 2)));
 } else { (void)(f298_hh(hr_str("for (int64_t i = 0; i < v.n; i++) { if (i) hr_fc(o, \", \"); ", 59)));
L98 ex_1647 = ({ L98 _t5268; memset(&_t5268, 0, sizeof _t5268); _t5268.n = 0; _t5268; }); 
(void)(({ L98 *_v5269 = &(ex_1647); hsl _s5269 = hr_str("((", 2); if (_v5269->n + _s5269.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:446"); memmove(_v5269->e + _v5269->n, _s5269.p, (size_t)_s5269.n * sizeof _v5269->e[0]); _v5269->n += _s5269.n; }));
(void)(({ L98 *_v5270 = &(ex_1647); hsl _s5270 = f261_cn(e_1646); if (_v5270->n + _s5270.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:446"); memmove(_v5270->e + _v5270->n, _s5270.p, (size_t)_s5270.n * sizeof _v5270->e[0]); _v5270->n += _s5270.n; }));
(void)(({ L98 *_v5272 = &(ex_1647); hsl _s5272 = hr_str("*)v.p)[i]", 9); if (_v5272->n + _s5272.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:446"); memmove(_v5272->e + _v5272->n, _s5272.p, (size_t)_s5272.n * sizeof _v5272->e[0]); _v5272->n += _s5272.n; }));
(void)(f299_hf_val(e_1646, ({ hsl _t5274 = ({ L98 *_t5275 = &(ex_1647); (hsl){ (uint8_t*)_t5275->e, _t5275->n }; }); int64_t _l5274 = 0, _h5274 = _t5274.n; if (_l5274 < 0 || _h5274 < _l5274 || _h5274 > _t5274.n) hr_slerr(_l5274, _h5274, _t5274.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:446"); (hsl){ _t5274.p + _l5274 * (int64_t)sizeof(uint8_t), _h5274 - _l5274 }; })));
(void)(f298_hh(hr_str("} ", 2)));
 }
 }
(void)(f298_hh(hr_str("hr_fb(o, ']'); ", 15)));
 }
if (((k_1611) == (((int64_t)14LL)))) { { int32_t _e5279 = (x_1610).n_; for (int32_t _k5279 = 0; _k5279 < _e5279; _k5279++) { int32_t i_1648 = (int32_t)_k5279; if (((i_1648) > (((int32_t)0LL)))) { (void)(f298_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
L99 e_1649 = ({ L99 _t5281; memset(&_t5281, 0, sizeof _t5281); _t5281.n = 0; _t5281; }); 
(void)(({ L99 *_l5282 = &(e_1649); hrv _o5282 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5282, hr_str("v.r", 3)); hr_fi(&_o5282, i_1648); if (_l5282->n + _o5282.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:449"); memcpy(_l5282->e + _l5282->n, _o5282.b, (size_t)_o5282.n); _l5282->n += _o5282.n; }));
(void)(f299_hf_val(((int64_t)((*({ hrv *_t5284 = &(g544); int64_t _i5284 = ((int64_t)((int64_t)((int64_t)((x_1610).l_)) + (int64_t)((int64_t)(i_1648)))); (int32_t*)_t5284->b + hr_ix(_i5284, _t5284->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:449"); })))), ({ hsl _t5285 = ({ L99 *_t5286 = &(e_1649); (hsl){ (uint8_t*)_t5286->e, _t5286->n }; }); int64_t _l5285 = 0, _h5285 = _t5285.n; if (_l5285 < 0 || _h5285 < _l5285 || _h5285 > _t5285.n) hr_slerr(_l5285, _h5285, _t5285.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:449"); (hsl){ _t5285.p + _l5285 * (int64_t)sizeof(uint8_t), _h5285 - _l5285 }; })));
 } } _bk5278:; 
 }
(void)(f298_hh(hr_str("}\012", 2)));
}
static void f297_hf_pre(int64_t t_1613) {
(void)(f293_comp_pre(t_1613, true));
}
static void f298_hh(hsl s_1616) {
(void)(({ hrv *_v5289 = &(g169); hsl _s5289 = s_1616; hr_append(_v5289, _s5289.p, _s5289.n, sizeof(uint8_t)); }));
}
static void f299_hf_val(int64_t t_1624, hsl e_1625) {
int64_t k_1626 = ((int64_t)(((*({ hrv *_t5290 = &(g543); int64_t _i5290 = t_1624; (S1*)_t5290->b + hr_ix(_i5290, _t5290->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:394"); }))).k_)); 
if (f164_is_byte_arr(t_1624)) { if (f279_is_fix(t_1624)) { (void)(({ hrv *_o5293 = &(g169); hr_fs(_o5293, hr_str("hr_fq(o, (hsl){ (uint8_t*)(", 27)); hr_fs(_o5293, e_1625); hr_fs(_o5293, hr_str(").e, ", 5)); hr_fi(_o5293, ((*({ hrv *_t5294 = &(g543); int64_t _i5294 = t_1624; (S1*)_t5294->b + hr_ix(_i5294, _t5294->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:395"); }))).b_); hr_fs(_o5293, hr_str(" }); ", 5)); }));
return;
 }
if (f280_is_lim(t_1624)) { (void)(({ hrv *_o5296 = &(g169); hr_fs(_o5296, hr_str("hr_fq(o, (hsl){ (uint8_t*)(", 27)); hr_fs(_o5296, e_1625); hr_fs(_o5296, hr_str(").e, (", 6)); hr_fs(_o5296, e_1625); hr_fs(_o5296, hr_str(").n }); ", 8)); }));
return;
 }
if (((((*({ hrv *_t5297 = &(g543); int64_t _i5297 = t_1624; (S1*)_t5297->b + hr_ix(_i5297, _t5297->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:395"); }))).k_) == (((uint8_t)9LL)))) { (void)(({ hrv *_o5298 = &(g169); hr_fs(_o5298, hr_str("hr_fq(o, ", 9)); hr_fs(_o5298, e_1625); hr_fs(_o5298, hr_str("); ", 3)); }));
return;
 }
(void)(({ hrv *_o5299 = &(g169); hr_fs(_o5299, hr_str("hr_fq(o, hr_sl(", 15)); hr_fs(_o5299, e_1625); hr_fs(_o5299, hr_str(")); ", 4)); }));
return;
 }
if (((k_1626) == (((int64_t)3LL)))) { (void)(({ hrv *_o5300 = &(g169); hr_fs(_o5300, ({ hsl _r5301; if (f153_is_signed(t_1624)) { _r5301 = hr_str("hr_fi(o, ", 9);  } else { _r5301 = hr_str("hr_fu(o, ", 9);  } _r5301; })); hr_fs(_o5300, e_1625); hr_fs(_o5300, hr_str("); ", 3)); }));
return;
 }
if (((k_1626) == (((int64_t)4LL)))) { (void)(({ hrv *_o5303 = &(g169); hr_fs(_o5303, ({ hsl _r5304; if (((((*({ hrv *_t5305 = &(g543); int64_t _i5305 = t_1624; (S1*)_t5305->b + hr_ix(_i5305, _t5305->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:397"); }))).s_) == (((uint8_t)4LL)))) { _r5304 = hr_str("hr_ff(o, ", 9);  } else { _r5304 = hr_str("hr_fd(o, ", 9);  } _r5304; })); hr_fs(_o5303, e_1625); hr_fs(_o5303, hr_str("); ", 3)); }));
return;
 }
if (((k_1626) == (((int64_t)2LL)))) { (void)(({ hrv *_o5306 = &(g169); hr_fs(_o5306, hr_str("hr_fc(o, (", 10)); hr_fs(_o5306, e_1625); hr_fs(_o5306, hr_str(") \077 \"true\" : \"false\"); ", 23)); }));
return;
 }
if (((k_1626) == (((int64_t)10LL)))) { if (((((*({ hrv *_t5307 = &(g543); int64_t _i5307 = t_1624; (S1*)_t5307->b + hr_ix(_i5307, _t5307->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:399"); }))).c_) >= (((int32_t)0LL)))) { (void)(({ hrv *_o5308 = &(g169); hr_fs(_o5308, hr_str("hr_fu(o, ", 9)); hr_fs(_o5308, e_1625); hr_fs(_o5308, hr_str("); ", 3)); }));
return;
 }
L97 pe_1627 = ({ L97 _t5309; memset(&_t5309, 0, sizeof _t5309); _t5309.n = 0; _t5309; }); 
(void)(({ L97 *_l5310 = &(pe_1627); hrv _o5310 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5310, hr_str("(*(", 3)); hr_fs(&_o5310, e_1625); hr_fs(&_o5310, hr_str("))", 2)); if (_l5310->n + _o5310.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:399"); memcpy(_l5310->e + _l5310->n, _o5310.b, (size_t)_o5310.n); _l5310->n += _o5310.n; }));
(void)(({ hrv *_o5311 = &(g169); hr_fs(_o5311, hr_str("if (", 4)); hr_fs(_o5311, e_1625); hr_fs(_o5311, hr_str(") { ", 4)); }));
(void)(f299_hf_val(((int64_t)(((*({ hrv *_t5313 = &(g543); int64_t _i5313 = t_1624; (S1*)_t5313->b + hr_ix(_i5313, _t5313->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:399"); }))).a_)), ({ hsl _t5314 = ({ L97 *_t5315 = &(pe_1627); (hsl){ (uint8_t*)_t5315->e, _t5315->n }; }); int64_t _l5314 = 0, _h5314 = _t5314.n; if (_l5314 < 0 || _h5314 < _l5314 || _h5314 > _t5314.n) hr_slerr(_l5314, _h5314, _t5314.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:399"); (hsl){ _t5314.p + _l5314 * (int64_t)sizeof(uint8_t), _h5314 - _l5314 }; })));
(void)(f298_hh(hr_str("} else hr_fc(o, \"null\"); ", 25)));
return;
 }
if (((((k_1626) == (((int64_t)8LL))) && (!(f279_is_fix(t_1624)))) && (!(f280_is_lim(t_1624))))) { (void)(({ hrv *_o5319 = &(g169); hr_fs(_o5319, hr_str("hf", 2)); hr_fi(_o5319, t_1624); hr_fs(_o5319, hr_str("(o, hr_sl(", 10)); hr_fs(_o5319, e_1625); hr_fs(_o5319, hr_str(")); ", 4)); }));
return;
 }
(void)(({ hrv *_o5320 = &(g169); hr_fs(_o5320, hr_str("hf", 2)); hr_fi(_o5320, t_1624); hr_fs(_o5320, hr_str("(o, ", 4)); hr_fs(_o5320, e_1625); hr_fs(_o5320, hr_str("); ", 3)); }));
}
static void f300_heq_val(int64_t t_1668, hsl a_1669, hsl b_1670) {
int64_t k_1671 = ((int64_t)(((*({ hrv *_t5321 = &(g543); int64_t _i5321 = t_1668; (S1*)_t5321->b + hr_ix(_i5321, _t5321->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:453"); }))).k_)); 
if ((((((k_1671) == (((int64_t)3LL))) || ((k_1671) == (((int64_t)4LL)))) || ((k_1671) == (((int64_t)2LL)))) || ((k_1671) == (((int64_t)10LL))))) { (void)(({ hrv *_o5322 = &(g169); hr_fs(_o5322, hr_str("(", 1)); hr_fs(_o5322, a_1669); hr_fs(_o5322, hr_str(") == (", 6)); hr_fs(_o5322, b_1670); hr_fs(_o5322, hr_str(")", 1)); }));
return;
 }
(void)(f292_gen_heq(t_1668));
if ((((k_1671) == (((int64_t)9LL))) || ((((k_1671) == (((int64_t)8LL))) && (!(f279_is_fix(t_1668)))) && (!(f280_is_lim(t_1668)))))) { (void)(({ hrv *_o5326 = &(g169); hr_fs(_o5326, hr_str("heq", 3)); hr_fi(_o5326, t_1668); hr_fs(_o5326, hr_str("(hr_sl(", 7)); hr_fs(_o5326, a_1669); hr_fs(_o5326, hr_str("), hr_sl(", 9)); hr_fs(_o5326, b_1670); hr_fs(_o5326, hr_str("))", 2)); }));
return;
 }
(void)(({ hrv *_o5327 = &(g169); hr_fs(_o5327, hr_str("heq", 3)); hr_fi(_o5327, t_1668); hr_fs(_o5327, hr_str("(", 1)); hr_fs(_o5327, a_1669); hr_fs(_o5327, hr_str(", ", 2)); hr_fs(_o5327, b_1670); hr_fs(_o5327, hr_str(")", 1)); }));
}
static bool f301_hsl_ty(int64_t t_1681) {
return (((((*({ hrv *_t5328 = &(g543); int64_t _i5328 = t_1681; (S1*)_t5328->b + hr_ix(_i5328, _t5328->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:754"); }))).k_) == (((uint8_t)9LL))) || ((((((*({ hrv *_t5329 = &(g543); int64_t _i5329 = t_1681; (S1*)_t5329->b + hr_ix(_i5329, _t5329->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:754"); }))).k_) == (((uint8_t)8LL))) && (!(f279_is_fix(t_1681)))) && (!(f280_is_lim(t_1681)))));
}
static void f302_gxas(int64_t n_1682, int64_t t_1683) {
int64_t f_1684 = f276_fin(n_1682); 
if (((f_1684) == (t_1683))) { (void)(f286_gx(n_1682));
return;
 }
(void)(f267_gcv(n_1682, f141_at(n_1682), t_1683));
}
static void f303_garith(int64_t o_1686, int64_t t0_1687, int64_t a_1688, int64_t b_1689, int64_t tv_1690, int64_t loc_1691) {
int64_t t_1692 = ({ int64_t _r5336; if (((((*({ hrv *_t5337 = &(g543); int64_t _i5337 = t0_1687; (S1*)_t5337->b + hr_ix(_i5337, _t5337->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:237"); }))).k_) == (((uint8_t)12LL)))) { _r5336 = g555;  } else { _r5336 = ({ int64_t _r5338; if (((((*({ hrv *_t5339 = &(g543); int64_t _i5339 = t0_1687; (S1*)_t5339->b + hr_ix(_i5339, _t5339->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:237"); }))).k_) == (((uint8_t)13LL)))) { _r5338 = g561;  } else { _r5338 = t0_1687;  } _r5338; });  } _r5336; }); 
int64_t k_1693 = ((int64_t)(((*({ hrv *_t5340 = &(g543); int64_t _i5340 = t_1692; (S1*)_t5340->b + hr_ix(_i5340, _t5340->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:238"); }))).k_)); 
int64_t lk_1694 = f180_leaf_kind(t_1692); 
if (((lk_1694) >= (((int64_t)4LL)))) { int64_t ta_1695 = ({ int64_t _r5342; if (((a_1688) >= (((int64_t)0LL)))) { _r5342 = f276_fin(a_1688);  } else { _r5342 = t_1692;  } _r5342; }); 
int64_t tb_1696 = ({ int64_t _r5344; if (((b_1689) >= (((int64_t)0LL)))) { _r5344 = f276_fin(b_1689);  } else { _r5344 = t_1692;  } _r5344; }); 
if (((ta_1695) != (t_1692))) { if (((o_1686) != (((int64_t)23LL)))) { (void)(f284_gerr(loc_1691, hr_str("only * takes a scalar on the left of a struct or array", 54)));
return;
 }
(void)(f257_ow(hr_str("hop", 3)));
(void)(f291_oi(t_1692));
(void)(f257_ow(hr_str("_", 1)));
(void)(f291_oi(o_1686));
(void)(f257_ow(hr_str("(", 1)));
(void)(f304_gopnd(b_1689, tv_1690));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f304_gopnd(a_1688, tv_1690));
(void)(f257_ow(hr_str(")", 1)));
(void)(f305_gen_hop(t_1692, o_1686, ta_1695));
return;
 }
(void)(f257_ow(hr_str("hop", 3)));
(void)(f291_oi(t_1692));
(void)(f257_ow(hr_str("_", 1)));
(void)(f291_oi(o_1686));
(void)(f257_ow(hr_str("(", 1)));
(void)(f304_gopnd(a_1688, tv_1690));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f304_gopnd(b_1689, tv_1690));
(void)(f257_ow(hr_str(")", 1)));
(void)(f305_gen_hop(t_1692, o_1686, tb_1696));
return;
 }
if (((k_1693) == (((int64_t)4LL)))) { if (((o_1686) == (((int64_t)25LL)))) { (void)(f257_ow(({ hsl _r5368; if (((((*({ hrv *_t5369 = &(g543); int64_t _i5369 = t_1692; (S1*)_t5369->b + hr_ix(_i5369, _t5369->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:245"); }))).s_) == (((uint8_t)4LL)))) { _r5368 = hr_str("fmodf(", 6);  } else { _r5368 = hr_str("fmod(", 5);  } _r5368; })));
(void)(f304_gopnd(a_1688, tv_1690));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f304_gopnd(b_1689, tv_1690));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
(void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(t_1692));
(void)(f257_ow(hr_str(")(", 2)));
(void)(f304_gopnd(a_1688, tv_1690));
(void)(f257_ow(hr_str(" ", 1)));
(void)(f257_ow(f307_ar_op(o_1686)));
(void)(f257_ow(hr_str(" ", 1)));
(void)(f304_gopnd(b_1689, tv_1690));
(void)(f257_ow(hr_str("))", 2)));
return;
 }
if (((k_1693) == (((int64_t)2LL)))) { (void)(f257_ow(hr_str("((", 2)));
(void)(f304_gopnd(a_1688, tv_1690));
(void)(f257_ow(hr_str(") ", 2)));
(void)(f257_ow(f307_ar_op(o_1686)));
(void)(f257_ow(hr_str(" (", 2)));
(void)(f304_gopnd(b_1689, tv_1690));
(void)(f257_ow(hr_str("))", 2)));
return;
 }
bool sg_1727 = (((k_1693) == (((int64_t)3LL))) && f153_is_signed(t_1692)); 
if ((((o_1686) == (((int64_t)24LL))) || ((o_1686) == (((int64_t)25LL))))) { (void)(f257_ow(({ hsl _r5394; if (((o_1686) == (((int64_t)24LL)))) { _r5394 = ({ hsl _r5395; if (sg_1727) { _r5395 = hr_str("HR_SDIV(", 8);  } else { _r5395 = hr_str("HR_UDIV(", 8);  } _r5395; });  } else { _r5394 = ({ hsl _r5396; if (sg_1727) { _r5396 = hr_str("HR_SMOD(", 8);  } else { _r5396 = hr_str("HR_UDIV_MOD(", 12);  } _r5396; });  } _r5394; })));
(void)(f258_ct(t_1692));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f304_gopnd(a_1688, tv_1690));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f304_gopnd(b_1689, tv_1690));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f308_wloc(loc_1691));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if ((((o_1686) == (((int64_t)43LL))) || ((o_1686) == (((int64_t)44LL))))) { (void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(t_1692));
(void)(f257_ow(hr_str(")((", 3)));
(void)(f304_gopnd(a_1688, tv_1690));
(void)(f257_ow(hr_str(") ", 2)));
(void)(f257_ow(f307_ar_op(o_1686)));
(void)(f257_ow(hr_str(" ((", 3)));
(void)(f304_gopnd(b_1689, tv_1690));
(void)(({ hrv *_o5414 = &(g163); hr_fs(_o5414, hr_str(") & ", 4)); hr_fi(_o5414, ((int64_t)((int64_t)f154_ibits(t_1692) - (int64_t)((int64_t)1LL)))); hr_fs(_o5414, hr_str(")))", 3)); }));
return;
 }
(void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(t_1692));
(void)(f257_ow(hr_str(")(", 2)));
if (sg_1727) { (void)(f257_ow(hr_str("(int64_t)", 9)));
 } else { (void)(f257_ow(hr_str("(uint64_t)", 10)));
 }
(void)(f304_gopnd(a_1688, tv_1690));
(void)(f257_ow(hr_str(" ", 1)));
(void)(f257_ow(f307_ar_op(o_1686)));
(void)(f257_ow(hr_str(" ", 1)));
if (sg_1727) { (void)(f257_ow(hr_str("(int64_t)", 9)));
 } else { (void)(f257_ow(hr_str("(uint64_t)", 10)));
 }
(void)(f304_gopnd(b_1689, tv_1690));
(void)(f257_ow(hr_str("))", 2)));
}
static void f304_gopnd(int64_t n_1697, int64_t tv_1698) {
if (((n_1697) >= (((int64_t)0LL)))) { (void)(f286_gx(n_1697));
 } else { (void)(({ hrv *_o5431 = &(g163); hr_fs(_o5431, hr_str("(*_t", 4)); hr_fi(_o5431, tv_1698); hr_fs(_o5431, hr_str(")", 1)); }));
 }
}
static void f305_gen_hop(int64_t t_1699, int64_t o_1700, int64_t bt_1701) {
int64_t key_1702 = ((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)(t_1699)) * (int64_t)((int64_t)4096LL))) + (int64_t)((int64_t)((int64_t)((int64_t)(o_1700)) * (int64_t)((int64_t)64LL))))) + (int64_t)({ int64_t _r5432; if (((bt_1701) == (t_1699))) { _r5432 = ((int64_t)0LL);  } else { _r5432 = ((int64_t)1LL);  } _r5432; }))); 
{ hrv *_v5434 = &(g240); for (int64_t _k5434 = 0; _k5434 < _v5434->n; _k5434++) { int64_t h_1703 = ((int64_t*)_v5434->b)[_k5434]; if (((h_1703) == (key_1702))) { return;
 }
 } } _bk5433:; 
(void)(({ hrv *_v5435 = &(g240); int64_t _x5435 = key_1702; int64_t *_p5435 = (int64_t*)hr_grow(_v5435, 1, sizeof _x5435); *_p5435 = _x5435; _p5435; }));
(void)(f259_cbody(t_1699));
int64_t lt_1704 = f181_leaf_type(t_1699); 
bool sc_1705 = ((bt_1701) != (t_1699)); 
L97 sig_1706 = ({ L97 _t5438; memset(&_t5438, 0, sizeof _t5438); _t5438.n = 0; _t5438; }); 
(void)(({ L97 *_l5439 = &(sig_1706); hrv _o5439 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5439, hr_str("static ", 7)); if (_l5439->n + _o5439.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:506"); memcpy(_l5439->e + _l5439->n, _o5439.b, (size_t)_o5439.n); _l5439->n += _o5439.n; }));
(void)(({ L97 *_v5440 = &(sig_1706); hsl _s5440 = f261_cn(t_1699); if (_v5440->n + _s5440.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:506"); memmove(_v5440->e + _v5440->n, _s5440.p, (size_t)_s5440.n * sizeof _v5440->e[0]); _v5440->n += _s5440.n; }));
(void)(({ L97 *_l5442 = &(sig_1706); hrv _o5442 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5442, hr_str(" hop", 4)); hr_fi(&_o5442, t_1699); hr_fs(&_o5442, hr_str("_", 1)); hr_fi(&_o5442, o_1700); hr_fs(&_o5442, hr_str("(", 1)); if (_l5442->n + _o5442.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:506"); memcpy(_l5442->e + _l5442->n, _o5442.b, (size_t)_o5442.n); _l5442->n += _o5442.n; }));
(void)(({ L97 *_v5443 = &(sig_1706); hsl _s5443 = f261_cn(t_1699); if (_v5443->n + _s5443.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:507"); memmove(_v5443->e + _v5443->n, _s5443.p, (size_t)_s5443.n * sizeof _v5443->e[0]); _v5443->n += _s5443.n; }));
(void)(({ L97 *_v5445 = &(sig_1706); hsl _s5445 = hr_str(" a, ", 4); if (_v5445->n + _s5445.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:507"); memmove(_v5445->e + _v5445->n, _s5445.p, (size_t)_s5445.n * sizeof _v5445->e[0]); _v5445->n += _s5445.n; }));
(void)(({ L97 *_v5446 = &(sig_1706); hsl _s5446 = f261_cn(({ int64_t _r5448; if (sc_1705) { _r5448 = bt_1701;  } else { _r5448 = t_1699;  } _r5448; })); if (_v5446->n + _s5446.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:507"); memmove(_v5446->e + _v5446->n, _s5446.p, (size_t)_s5446.n * sizeof _v5446->e[0]); _v5446->n += _s5446.n; }));
(void)(({ L97 *_v5449 = &(sig_1706); hsl _s5449 = hr_str(" b)", 3); if (_v5449->n + _s5449.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:507"); memmove(_v5449->e + _v5449->n, _s5449.p, (size_t)_s5449.n * sizeof _v5449->e[0]); _v5449->n += _s5449.n; }));
(void)(({ hrv *_v5450 = &(g166); hsl _s5450 = ({ hsl _t5451 = ({ L97 *_t5452 = &(sig_1706); (hsl){ (uint8_t*)_t5452->e, _t5452->n }; }); int64_t _l5451 = 0, _h5451 = _t5451.n; if (_l5451 < 0 || _h5451 < _l5451 || _h5451 > _t5451.n) hr_slerr(_l5451, _h5451, _t5451.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:508"); (hsl){ _t5451.p + _l5451 * (int64_t)sizeof(uint8_t), _h5451 - _l5451 }; }); hr_append(_v5450, _s5450.p, _s5450.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5453 = &(g166); hsl _s5453 = hr_str(";\012", 2); hr_append(_v5453, _s5453.p, _s5453.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5454 = &(g169); hsl _s5454 = ({ hsl _t5455 = ({ L97 *_t5456 = &(sig_1706); (hsl){ (uint8_t*)_t5456->e, _t5456->n }; }); int64_t _l5455 = 0, _h5455 = _t5455.n; if (_l5455 < 0 || _h5455 < _l5455 || _h5455 > _t5455.n) hr_slerr(_l5455, _h5455, _t5455.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:509"); (hsl){ _t5455.p + _l5455 * (int64_t)sizeof(uint8_t), _h5455 - _l5455 }; }); hr_append(_v5454, _s5454.p, _s5454.n, sizeof(uint8_t)); }));
(void)(f298_hh(hr_str(" { ", 3)));
(void)(({ hrv *_v5458 = &(g169); hsl _s5458 = f261_cn(t_1699); hr_append(_v5458, _s5458.p, _s5458.n, sizeof(uint8_t)); }));
(void)(f298_hh(hr_str(" r; ", 4)));
(void)(f306_hop_body(t_1699, o_1700, hr_str("r", 1), hr_str("a", 1), hr_str("b", 1), sc_1705));
(void)(f298_hh(hr_str("return r; }\012", 12)));
}
static void f306_hop_body(int64_t t_1707, int64_t o_1708, hsl r_1709, hsl a_1710, hsl b_1711, bool sc_1712) {
int64_t k_1713 = ((int64_t)(((*({ hrv *_t5463 = &(g543); int64_t _i5463 = t_1707; (S1*)_t5463->b + hr_ix(_i5463, _t5463->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:514"); }))).k_)); 
if ((((k_1713) == (((int64_t)3LL))) || ((k_1713) == (((int64_t)4LL))))) { (void)(({ hrv *_o5464 = &(g169); hr_fs(_o5464, r_1709); hr_fs(_o5464, hr_str(" = (", 4)); }));
(void)(({ hrv *_v5465 = &(g169); hsl _s5465 = f261_cn(t_1707); hr_append(_v5465, _s5465.p, _s5465.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o5467 = &(g169); hr_fs(_o5467, hr_str(")((", 3)); hr_fs(_o5467, a_1710); hr_fs(_o5467, hr_str(") ", 2)); hr_fs(_o5467, f307_ar_op(o_1708)); hr_fs(_o5467, hr_str(" (", 2)); hr_fs(_o5467, b_1711); hr_fs(_o5467, hr_str(")); ", 4)); }));
return;
 }
if (((k_1713) == (((int64_t)5LL)))) { int64_t si_1715 = ((int64_t)(((*({ hrv *_t5469 = &(g543); int64_t _i5469 = t_1707; (S1*)_t5469->b + hr_ix(_i5469, _t5469->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:517"); }))).a_)); 
int64_t f0_1716 = ((int64_t)(((*({ hrv *_t5470 = &(g546); int64_t _i5470 = si_1715; (S10*)_t5470->b + hr_ix(_i5470, _t5470->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:517"); }))).f0_)); 
{ int32_t _e5472 = ((*({ hrv *_t5473 = &(g546); int64_t _i5473 = si_1715; (S10*)_t5473->b + hr_ix(_i5473, _t5473->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:518"); }))).fnum_; for (int32_t _k5472 = 0; _k5472 < _e5472; _k5472++) { int32_t i_1717 = (int32_t)_k5472; S11 f_1718 = (*({ hrv *_t5474 = &(g547); int64_t _i5474 = ((int64_t)((int64_t)f0_1716 + (int64_t)((int64_t)(i_1717)))); (S11*)_t5474->b + hr_ix(_i5474, _t5474->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:519"); })); 
if ((((f_1718).ty_) < (((int32_t)0LL)))) { continue;
 }
L97 rr_1719 = ({ L97 _t5475; memset(&_t5475, 0, sizeof _t5475); _t5475.n = 0; _t5475; }); 
L97 aa_1720 = ({ L97 _t5476; memset(&_t5476, 0, sizeof _t5476); _t5476.n = 0; _t5476; }); 
L97 bb_1721 = ({ L97 _t5477; memset(&_t5477, 0, sizeof _t5477); _t5477.n = 0; _t5477; }); 
(void)(({ L97 *_v5478 = &(rr_1719); hsl _s5478 = r_1709; if (_v5478->n + _s5478.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:521"); memmove(_v5478->e + _v5478->n, _s5478.p, (size_t)_s5478.n * sizeof _v5478->e[0]); _v5478->n += _s5478.n; }));
(void)(({ L97 *_v5479 = &(rr_1719); uint8_t _x5479 = ((uint8_t)46LL); if (_v5479->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:521"); _v5479->e[_v5479->n] = _x5479; &_v5479->e[_v5479->n++]; }));
(void)(({ L97 *_v5480 = &(aa_1720); hsl _s5480 = a_1710; if (_v5480->n + _s5480.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:521"); memmove(_v5480->e + _v5480->n, _s5480.p, (size_t)_s5480.n * sizeof _v5480->e[0]); _v5480->n += _s5480.n; }));
(void)(({ L97 *_v5481 = &(aa_1720); uint8_t _x5481 = ((uint8_t)46LL); if (_v5481->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:521"); _v5481->e[_v5481->n] = _x5481; &_v5481->e[_v5481->n++]; }));
(void)(({ L97 *_v5482 = &(bb_1721); hsl _s5482 = b_1711; if (_v5482->n + _s5482.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:521"); memmove(_v5482->e + _v5482->n, _s5482.p, (size_t)_s5482.n * sizeof _v5482->e[0]); _v5482->n += _s5482.n; }));
if ((!(sc_1712))) { (void)(({ L97 *_v5483 = &(bb_1721); uint8_t _x5483 = ((uint8_t)46LL); if (_v5483->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:521"); _v5483->e[_v5483->n] = _x5483; &_v5483->e[_v5483->n++]; }));
 }
{ hsl _v5485 = f10_nm(((int64_t)((f_1718).name_))); for (int64_t _k5485 = 0; _k5485 < _v5485.n; _k5485++) { uint8_t ch_1722 = ((uint8_t*)_v5485.p)[_k5485]; (void)(({ L97 *_v5487 = &(rr_1719); uint8_t _x5487 = ch_1722; if (_v5487->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:522"); _v5487->e[_v5487->n] = _x5487; &_v5487->e[_v5487->n++]; }));
(void)(({ L97 *_v5488 = &(aa_1720); uint8_t _x5488 = ch_1722; if (_v5488->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:522"); _v5488->e[_v5488->n] = _x5488; &_v5488->e[_v5488->n++]; }));
if ((!(sc_1712))) { (void)(({ L97 *_v5489 = &(bb_1721); uint8_t _x5489 = ch_1722; if (_v5489->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:522"); _v5489->e[_v5489->n] = _x5489; &_v5489->e[_v5489->n++]; }));
 }
 } } _bk5484:; 
(void)(({ L97 *_v5490 = &(rr_1719); uint8_t _x5490 = ((uint8_t)95LL); if (_v5490->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:523"); _v5490->e[_v5490->n] = _x5490; &_v5490->e[_v5490->n++]; }));
(void)(({ L97 *_v5491 = &(aa_1720); uint8_t _x5491 = ((uint8_t)95LL); if (_v5491->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:523"); _v5491->e[_v5491->n] = _x5491; &_v5491->e[_v5491->n++]; }));
if ((!(sc_1712))) { (void)(({ L97 *_v5492 = &(bb_1721); uint8_t _x5492 = ((uint8_t)95LL); if (_v5492->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:523"); _v5492->e[_v5492->n] = _x5492; &_v5492->e[_v5492->n++]; }));
 }
(void)(f306_hop_body(((int64_t)((f_1718).ty_)), o_1708, ({ hsl _t5494 = ({ L97 *_t5495 = &(rr_1719); (hsl){ (uint8_t*)_t5495->e, _t5495->n }; }); int64_t _l5494 = 0, _h5494 = _t5494.n; if (_l5494 < 0 || _h5494 < _l5494 || _h5494 > _t5494.n) hr_slerr(_l5494, _h5494, _t5494.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:524"); (hsl){ _t5494.p + _l5494 * (int64_t)sizeof(uint8_t), _h5494 - _l5494 }; }), ({ hsl _t5496 = ({ L97 *_t5497 = &(aa_1720); (hsl){ (uint8_t*)_t5497->e, _t5497->n }; }); int64_t _l5496 = 0, _h5496 = _t5496.n; if (_l5496 < 0 || _h5496 < _l5496 || _h5496 > _t5496.n) hr_slerr(_l5496, _h5496, _t5496.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:524"); (hsl){ _t5496.p + _l5496 * (int64_t)sizeof(uint8_t), _h5496 - _l5496 }; }), ({ hsl _t5498 = ({ L97 *_t5499 = &(bb_1721); (hsl){ (uint8_t*)_t5499->e, _t5499->n }; }); int64_t _l5498 = 0, _h5498 = _t5498.n; if (_l5498 < 0 || _h5498 < _l5498 || _h5498 > _t5498.n) hr_slerr(_l5498, _h5498, _t5498.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:524"); (hsl){ _t5498.p + _l5498 * (int64_t)sizeof(uint8_t), _h5498 - _l5498 }; }), sc_1712));
 } } _bk5471:; 
return;
 }
if (f279_is_fix(t_1707)) { int64_t p_1723 = f290_nt(); 
(void)(({ hrv *_o5502 = &(g169); hr_fs(_o5502, hr_str("for (int64_t _i", 15)); hr_fi(_o5502, p_1723); hr_fs(_o5502, hr_str(" = 0; _i", 8)); hr_fi(_o5502, p_1723); hr_fs(_o5502, hr_str(" < ", 3)); hr_fi(_o5502, ((*({ hrv *_t5503 = &(g543); int64_t _i5503 = t_1707; (S1*)_t5503->b + hr_ix(_i5503, _t5503->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:530"); }))).b_); hr_fs(_o5502, hr_str("; _i", 4)); hr_fi(_o5502, p_1723); hr_fs(_o5502, hr_str("++) { ", 6)); }));
L97 rr_1724 = ({ L97 _t5504; memset(&_t5504, 0, sizeof _t5504); _t5504.n = 0; _t5504; }); 
L97 aa_1725 = ({ L97 _t5505; memset(&_t5505, 0, sizeof _t5505); _t5505.n = 0; _t5505; }); 
L97 bb_1726 = ({ L97 _t5506; memset(&_t5506, 0, sizeof _t5506); _t5506.n = 0; _t5506; }); 
(void)(({ L97 *_l5507 = &(rr_1724); hrv _o5507 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5507, r_1709); hr_fs(&_o5507, hr_str(".e[_i", 5)); hr_fi(&_o5507, p_1723); hr_fs(&_o5507, hr_str("]", 1)); if (_l5507->n + _o5507.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:532"); memcpy(_l5507->e + _l5507->n, _o5507.b, (size_t)_o5507.n); _l5507->n += _o5507.n; }));
(void)(({ L97 *_l5508 = &(aa_1725); hrv _o5508 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5508, a_1710); hr_fs(&_o5508, hr_str(".e[_i", 5)); hr_fi(&_o5508, p_1723); hr_fs(&_o5508, hr_str("]", 1)); if (_l5508->n + _o5508.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:532"); memcpy(_l5508->e + _l5508->n, _o5508.b, (size_t)_o5508.n); _l5508->n += _o5508.n; }));
if (sc_1712) { (void)(({ L97 *_v5509 = &(bb_1726); hsl _s5509 = b_1711; if (_v5509->n + _s5509.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:532"); memmove(_v5509->e + _v5509->n, _s5509.p, (size_t)_s5509.n * sizeof _v5509->e[0]); _v5509->n += _s5509.n; }));
 } else { (void)(({ L97 *_l5510 = &(bb_1726); hrv _o5510 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5510, b_1711); hr_fs(&_o5510, hr_str(".e[_i", 5)); hr_fi(&_o5510, p_1723); hr_fs(&_o5510, hr_str("]", 1)); if (_l5510->n + _o5510.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:532"); memcpy(_l5510->e + _l5510->n, _o5510.b, (size_t)_o5510.n); _l5510->n += _o5510.n; }));
 }
(void)(f306_hop_body(((int64_t)(((*({ hrv *_t5512 = &(g543); int64_t _i5512 = t_1707; (S1*)_t5512->b + hr_ix(_i5512, _t5512->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:533"); }))).a_)), o_1708, ({ hsl _t5513 = ({ L97 *_t5514 = &(rr_1724); (hsl){ (uint8_t*)_t5514->e, _t5514->n }; }); int64_t _l5513 = 0, _h5513 = _t5513.n; if (_l5513 < 0 || _h5513 < _l5513 || _h5513 > _t5513.n) hr_slerr(_l5513, _h5513, _t5513.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:533"); (hsl){ _t5513.p + _l5513 * (int64_t)sizeof(uint8_t), _h5513 - _l5513 }; }), ({ hsl _t5515 = ({ L97 *_t5516 = &(aa_1725); (hsl){ (uint8_t*)_t5516->e, _t5516->n }; }); int64_t _l5515 = 0, _h5515 = _t5515.n; if (_l5515 < 0 || _h5515 < _l5515 || _h5515 > _t5515.n) hr_slerr(_l5515, _h5515, _t5515.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:533"); (hsl){ _t5515.p + _l5515 * (int64_t)sizeof(uint8_t), _h5515 - _l5515 }; }), ({ hsl _t5517 = ({ L97 *_t5518 = &(bb_1726); (hsl){ (uint8_t*)_t5518->e, _t5518->n }; }); int64_t _l5517 = 0, _h5517 = _t5517.n; if (_l5517 < 0 || _h5517 < _l5517 || _h5517 > _t5517.n) hr_slerr(_l5517, _h5517, _t5517.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:533"); (hsl){ _t5517.p + _l5517 * (int64_t)sizeof(uint8_t), _h5517 - _l5517 }; }), sc_1712));
(void)(f298_hh(hr_str("} ", 2)));
 }
}
static hsl f307_ar_op(int64_t o_1714) {
if ((((o_1714) == (((int64_t)21LL))) || ((o_1714) == (((int64_t)26LL))))) { return hr_str("+", 1);
 }
if ((((o_1714) == (((int64_t)22LL))) || ((o_1714) == (((int64_t)27LL))))) { return hr_str("-", 1);
 }
if ((((o_1714) == (((int64_t)23LL))) || ((o_1714) == (((int64_t)28LL))))) { return hr_str("*", 1);
 }
if ((((o_1714) == (((int64_t)24LL))) || ((o_1714) == (((int64_t)29LL))))) { return hr_str("/", 1);
 }
if ((((o_1714) == (((int64_t)25LL))) || ((o_1714) == (((int64_t)30LL))))) { return hr_str("%", 1);
 }
if ((((o_1714) == (((int64_t)49LL))) || ((o_1714) == (((int64_t)31LL))))) { return hr_str("&", 1);
 }
if ((((o_1714) == (((int64_t)50LL))) || ((o_1714) == (((int64_t)32LL))))) { return hr_str("|", 1);
 }
if ((((o_1714) == (((int64_t)51LL))) || ((o_1714) == (((int64_t)33LL))))) { return hr_str("^", 1);
 }
if ((((o_1714) == (((int64_t)43LL))) || ((o_1714) == (((int64_t)45LL))))) { return hr_str("<<", 2);
 }
if ((((o_1714) == (((int64_t)44LL))) || ((o_1714) == (((int64_t)46LL))))) { return hr_str(">>", 2);
 }
return hr_str("\077", 1);
}
static void f308_wloc(int64_t n_1728) {
S3 x_1729 = (*({ hrv *_t5520 = &(g906); int64_t _i5520 = ((*({ hrv *_t5521 = &(g696); int64_t _i5521 = f103_max(n_1728, ((int64_t)0LL)); (S4*)_t5521->b + hr_ix(_i5521, _t5521->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:100"); }))).t_; (S3*)_t5520->b + hr_ix(_i5520, _t5520->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:100"); })); 
(void)(f257_ow(hr_str("\"", 1)));
{ hsl _v5525 = f10_nm(((int64_t)(((*({ hrv *_t5527 = &(g905); int64_t _i5527 = (x_1729).f_; (S2*)_t5527->b + hr_ix(_i5527, _t5527->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:100"); }))).name_))); for (int64_t _k5525 = 0; _k5525 < _v5525.n; _k5525++) { uint8_t c_1730 = ((uint8_t*)_v5525.p)[_k5525]; if ((((c_1730) == (((uint8_t)34LL))) || ((c_1730) == (((uint8_t)92LL))))) { (void)(({ hrv *_v5528 = &(g163); uint8_t _x5528 = ((uint8_t)92LL); uint8_t *_p5528 = (uint8_t*)hr_grow(_v5528, 1, sizeof _x5528); *_p5528 = _x5528; _p5528; }));
 }
(void)(({ hrv *_v5529 = &(g163); uint8_t _x5529 = c_1730; uint8_t *_p5529 = (uint8_t*)hr_grow(_v5529, 1, sizeof _x5529); *_p5529 = _x5529; _p5529; }));
 } } _bk5524:; 
(void)(({ hrv *_o5530 = &(g163); hr_fs(_o5530, hr_str(":", 1)); hr_fi(_o5530, (x_1729).line_); hr_fs(_o5530, hr_str("\"", 1)); }));
}
static void f309_gun(int64_t n_1731) {
S4 x_1732 = (*({ hrv *_t5531 = &(g696); int64_t _i5531 = n_1731; (S4*)_t5531->b + hr_ix(_i5531, _t5531->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:272"); })); 
int64_t o_1733 = ((int64_t)((x_1732).op_)); 
int64_t a_1734 = ((int64_t)((x_1732).a_)); 
if (((o_1733) == (((int64_t)47LL)))) { (void)(f257_ow(hr_str("(!(", 3)));
(void)(f286_gx(a_1734));
(void)(f257_ow(hr_str("))", 2)));
return;
 }
if (((o_1733) == (((int64_t)49LL)))) { (void)(f286_gx(a_1734));
return;
 }
int64_t t_1735 = f276_fin(n_1731); 
if (((o_1733) == (((int64_t)22LL)))) { if (((((*({ hrv *_t5537 = &(g543); int64_t _i5537 = t_1735; (S1*)_t5537->b + hr_ix(_i5537, _t5537->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:276"); }))).k_) == (((uint8_t)4LL)))) { (void)(f257_ow(hr_str("(-(", 3)));
(void)(f286_gx(a_1734));
(void)(f257_ow(hr_str("))", 2)));
return;
 }
if (((f180_leaf_kind(t_1735)) >= (((int64_t)4LL)))) { (void)(f257_ow(hr_str("hneg", 4)));
(void)(f291_oi(t_1735));
(void)(f257_ow(hr_str("(", 1)));
(void)(f286_gx(a_1734));
(void)(f257_ow(hr_str(")", 1)));
(void)(f310_gen_hneg(t_1735));
return;
 }
(void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(t_1735));
(void)(f257_ow(hr_str(")(0 - (uint64_t)(", 17)));
(void)(f286_gx(a_1734));
(void)(f257_ow(hr_str(")))", 3)));
return;
 }
if (((o_1733) == (((int64_t)48LL)))) { (void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(t_1735));
(void)(f257_ow(hr_str(")~(", 3)));
(void)(f286_gx(a_1734));
(void)(f257_ow(hr_str("))", 2)));
return;
 }
if (((o_1733) == (((int64_t)23LL)))) { (void)(f257_ow(hr_str("(*", 2)));
(void)(f286_gx(a_1734));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if (((o_1733) == (((int64_t)21LL)))) { (void)(f286_gx(a_1734));
return;
 }
(void)(f284_gerr(n_1731, hr_str("unsupported unary operator", 26)));
}
static void f310_gen_hneg(int64_t t_1736) {
{ hrv *_v5564 = &(g243); for (int64_t _k5564 = 0; _k5564 < _v5564->n; _k5564++) { int32_t h_1737 = ((int32_t*)_v5564->b)[_k5564]; if (((((int64_t)(h_1737))) == (t_1736))) { return;
 }
 } } _bk5563:; 
(void)(({ hrv *_v5565 = &(g243); int32_t _x5565 = ((int32_t)(t_1736)); int32_t *_p5565 = (int32_t*)hr_grow(_v5565, 1, sizeof _x5565); *_p5565 = _x5565; _p5565; }));
(void)(f259_cbody(t_1736));
L97 sig_1738 = ({ L97 _t5567; memset(&_t5567, 0, sizeof _t5567); _t5567.n = 0; _t5567; }); 
(void)(({ L97 *_l5568 = &(sig_1738); hrv _o5568 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5568, hr_str("static ", 7)); if (_l5568->n + _o5568.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:543"); memcpy(_l5568->e + _l5568->n, _o5568.b, (size_t)_o5568.n); _l5568->n += _o5568.n; }));
(void)(({ L97 *_v5569 = &(sig_1738); hsl _s5569 = f261_cn(t_1736); if (_v5569->n + _s5569.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:543"); memmove(_v5569->e + _v5569->n, _s5569.p, (size_t)_s5569.n * sizeof _v5569->e[0]); _v5569->n += _s5569.n; }));
(void)(({ L97 *_l5571 = &(sig_1738); hrv _o5571 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5571, hr_str(" hneg", 5)); hr_fi(&_o5571, t_1736); hr_fs(&_o5571, hr_str("(", 1)); if (_l5571->n + _o5571.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:543"); memcpy(_l5571->e + _l5571->n, _o5571.b, (size_t)_o5571.n); _l5571->n += _o5571.n; }));
(void)(({ L97 *_v5572 = &(sig_1738); hsl _s5572 = f261_cn(t_1736); if (_v5572->n + _s5572.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:543"); memmove(_v5572->e + _v5572->n, _s5572.p, (size_t)_s5572.n * sizeof _v5572->e[0]); _v5572->n += _s5572.n; }));
(void)(({ L97 *_v5574 = &(sig_1738); hsl _s5574 = hr_str(" a)", 3); if (_v5574->n + _s5574.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:543"); memmove(_v5574->e + _v5574->n, _s5574.p, (size_t)_s5574.n * sizeof _v5574->e[0]); _v5574->n += _s5574.n; }));
(void)(({ hrv *_v5575 = &(g166); hsl _s5575 = ({ hsl _t5576 = ({ L97 *_t5577 = &(sig_1738); (hsl){ (uint8_t*)_t5577->e, _t5577->n }; }); int64_t _l5576 = 0, _h5576 = _t5576.n; if (_l5576 < 0 || _h5576 < _l5576 || _h5576 > _t5576.n) hr_slerr(_l5576, _h5576, _t5576.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:544"); (hsl){ _t5576.p + _l5576 * (int64_t)sizeof(uint8_t), _h5576 - _l5576 }; }); hr_append(_v5575, _s5575.p, _s5575.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5578 = &(g166); hsl _s5578 = hr_str(";\012", 2); hr_append(_v5578, _s5578.p, _s5578.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v5579 = &(g169); hsl _s5579 = ({ hsl _t5580 = ({ L97 *_t5581 = &(sig_1738); (hsl){ (uint8_t*)_t5581->e, _t5581->n }; }); int64_t _l5580 = 0, _h5580 = _t5580.n; if (_l5580 < 0 || _h5580 < _l5580 || _h5580 > _t5580.n) hr_slerr(_l5580, _h5580, _t5580.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:545"); (hsl){ _t5580.p + _l5580 * (int64_t)sizeof(uint8_t), _h5580 - _l5580 }; }); hr_append(_v5579, _s5579.p, _s5579.n, sizeof(uint8_t)); }));
(void)(f298_hh(hr_str(" { ", 3)));
(void)(({ hrv *_v5583 = &(g169); hsl _s5583 = f261_cn(t_1736); hr_append(_v5583, _s5583.p, _s5583.n, sizeof(uint8_t)); }));
(void)(f298_hh(hr_str(" z; memset(&z, 0, sizeof z); ", 29)));
(void)(({ hrv *_v5586 = &(g169); hsl _s5586 = f261_cn(t_1736); hr_append(_v5586, _s5586.p, _s5586.n, sizeof(uint8_t)); }));
(void)(f298_hh(hr_str(" r; ", 4)));
(void)(f306_hop_body(t_1736, ((int64_t)22LL), hr_str("r", 1), hr_str("z", 1), hr_str("a", 1), false));
(void)(f298_hh(hr_str("return r; }\012", 12)));
}
static void f311_gidx(int64_t n_1750) {
S4 x_1751 = (*({ hrv *_t5591 = &(g696); int64_t _i5591 = n_1750; (S4*)_t5591->b + hr_ix(_i5591, _t5591->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:283"); })); 
int64_t a_1752 = ((int64_t)((x_1751).a_)); 
int64_t bt_1753 = f141_at(a_1752); 
int64_t d_1754 = f179_deref(bt_1753); 
int64_t e_1755 = ((int64_t)(((*({ hrv *_t5594 = &(g543); int64_t _i5594 = d_1754; (S1*)_t5594->b + hr_ix(_i5594, _t5594->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:287"); }))).a_)); 
int64_t p_1756 = f290_nt(); 
if ((f279_is_fix(d_1754) && ((((*({ hrv *_t5597 = &(g543); int64_t _i5597 = bt_1753; (S1*)_t5597->b + hr_ix(_i5597, _t5597->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:289"); }))).k_) != (((uint8_t)10LL))))) { (void)(f257_ow(hr_str("(", 1)));
(void)(f286_gx(a_1752));
(void)(f257_ow(hr_str(").e[hr_ix(", 10)));
(void)(f286_gx(((int64_t)((x_1751).b_))));
(void)(({ hrv *_o5602 = &(g163); hr_fs(_o5602, hr_str(", ", 2)); hr_fi(_o5602, ((*({ hrv *_t5603 = &(g543); int64_t _i5603 = d_1754; (S1*)_t5603->b + hr_ix(_i5603, _t5603->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:290"); }))).b_); hr_fs(_o5602, hr_str(", ", 2)); }));
(void)(f308_wloc(n_1750));
(void)(f257_ow(hr_str(")]", 2)));
return;
 }
(void)(f257_ow(hr_str("(*({ ", 5)));
if (((((*({ hrv *_t5607 = &(g543); int64_t _i5607 = d_1754; (S1*)_t5607->b + hr_ix(_i5607, _t5607->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:293"); }))).k_) == (((uint8_t)9LL)))) { (void)(f257_ow(hr_str("hsl _t", 6)));
(void)(f291_oi(p_1756));
(void)(f257_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t5611 = &(g543); int64_t _i5611 = bt_1753; (S1*)_t5611->b + hr_ix(_i5611, _t5611->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:293"); }))).k_) == (((uint8_t)10LL)))) { (void)(f257_ow(hr_str("*", 1)));
(void)(f272_gx0(a_1752));
 } else { (void)(f286_gx(a_1752));
 }
(void)(f257_ow(hr_str("; int64_t _i", 12)));
(void)(f291_oi(p_1756));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(((int64_t)((x_1751).b_))));
(void)(f257_ow(hr_str("; (", 3)));
(void)(f258_ct(e_1755));
(void)(f257_ow(hr_str("*)_t", 4)));
(void)(f291_oi(p_1756));
(void)(({ hrv *_o5623 = &(g163); hr_fs(_o5623, hr_str(".p + hr_ix(_i", 13)); hr_fi(_o5623, p_1756); hr_fs(_o5623, hr_str(", _t", 4)); hr_fi(_o5623, p_1756); hr_fs(_o5623, hr_str(".n, ", 4)); }));
(void)(f308_wloc(n_1750));
(void)(f257_ow(hr_str("); }))", 6)));
return;
 }
(void)(f258_ct(d_1754));
(void)(f257_ow(hr_str(" *_t", 4)));
(void)(f291_oi(p_1756));
(void)(f257_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t5630 = &(g543); int64_t _i5630 = bt_1753; (S1*)_t5630->b + hr_ix(_i5630, _t5630->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:295"); }))).k_) == (((uint8_t)10LL)))) { (void)(f272_gx0(a_1752));
 } else { if (f269_is_place(a_1752)) { (void)(f257_ow(hr_str("&(", 2)));
(void)(f286_gx(a_1752));
(void)(f257_ow(hr_str(")", 1)));
 } else { int64_t k_1757 = f270_tmp(d_1754, f265_is_res(d_1754)); 
(void)(f257_ow(hr_str("&(", 2)));
(void)(f271_ot(k_1757));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f266_gxo(a_1752));
(void)(f257_ow(hr_str(")", 1)));
 }
 }
(void)(f257_ow(hr_str("; int64_t _i", 12)));
(void)(f291_oi(p_1756));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(((int64_t)((x_1751).b_))));
(void)(f257_ow(hr_str("; ", 2)));
if (f265_is_res(d_1754)) { (void)(f257_ow(hr_str("(", 1)));
(void)(f258_ct(e_1755));
(void)(f257_ow(hr_str("*)_t", 4)));
(void)(f291_oi(p_1756));
(void)(({ hrv *_o5653 = &(g163); hr_fs(_o5653, hr_str("->b + hr_ix(_i", 14)); hr_fi(_o5653, p_1756); hr_fs(_o5653, hr_str(", _t", 4)); hr_fi(_o5653, p_1756); hr_fs(_o5653, hr_str("->n, ", 5)); }));
(void)(f308_wloc(n_1750));
(void)(f257_ow(hr_str("); }))", 6)));
return;
 }
if (f279_is_fix(d_1754)) { (void)(({ hrv *_o5657 = &(g163); hr_fs(_o5657, hr_str("_t", 2)); hr_fi(_o5657, p_1756); hr_fs(_o5657, hr_str("->e + hr_ix(_i", 14)); hr_fi(_o5657, p_1756); hr_fs(_o5657, hr_str(", ", 2)); hr_fi(_o5657, ((*({ hrv *_t5658 = &(g543); int64_t _i5658 = d_1754; (S1*)_t5658->b + hr_ix(_i5658, _t5658->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:298"); }))).b_); hr_fs(_o5657, hr_str(", ", 2)); }));
(void)(f308_wloc(n_1750));
(void)(f257_ow(hr_str("); }))", 6)));
return;
 }
(void)(({ hrv *_o5661 = &(g163); hr_fs(_o5661, hr_str("_t", 2)); hr_fi(_o5661, p_1756); hr_fs(_o5661, hr_str("->e + hr_ix(_i", 14)); hr_fi(_o5661, p_1756); hr_fs(_o5661, hr_str(", _t", 4)); hr_fi(_o5661, p_1756); hr_fs(_o5661, hr_str("->n, ", 5)); }));
(void)(f308_wloc(n_1750));
(void)(f257_ow(hr_str("); }))", 6)));
}
static void f312_gslice(int64_t n_1758) {
S4 x_1759 = (*({ hrv *_t5664 = &(g696); int64_t _i5664 = n_1758; (S4*)_t5664->b + hr_ix(_i5664, _t5664->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:302"); })); 
int64_t a_1760 = ((int64_t)((x_1759).a_)); 
int64_t d_1761 = f179_deref(f141_at(a_1760)); 
int64_t e_1762 = ((int64_t)(((*({ hrv *_t5667 = &(g543); int64_t _i5667 = d_1761; (S1*)_t5667->b + hr_ix(_i5667, _t5667->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:305"); }))).a_)); 
int64_t p_1763 = f290_nt(); 
(void)(f257_ow(hr_str("({ hsl _t", 9)));
(void)(f291_oi(p_1763));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f289_gsl(a_1760, f141_at(a_1760)));
(void)(f257_ow(hr_str("; int64_t _l", 12)));
(void)(f291_oi(p_1763));
(void)(f257_ow(hr_str(" = ", 3)));
if ((((x_1759).b_) >= (((int32_t)0LL)))) { if (((((uint16_t)((uint64_t)(x_1759).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_o5677 = &(g163); hr_fs(_o5677, hr_str("_t", 2)); hr_fi(_o5677, p_1763); hr_fs(_o5677, hr_str(".n - ", 5)); }));
 }
(void)(f286_gx(((int64_t)((x_1759).b_))));
 } else { (void)(f257_ow(hr_str("0", 1)));
 }
(void)(f257_ow(hr_str(", _h", 4)));
(void)(f291_oi(p_1763));
(void)(f257_ow(hr_str(" = ", 3)));
if ((((x_1759).c_) >= (((int32_t)0LL)))) { if (((((uint16_t)((uint64_t)(x_1759).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_o5683 = &(g163); hr_fs(_o5683, hr_str("_t", 2)); hr_fi(_o5683, p_1763); hr_fs(_o5683, hr_str(".n - ", 5)); }));
 }
(void)(f286_gx(((int64_t)((x_1759).c_))));
 } else { (void)(({ hrv *_o5685 = &(g163); hr_fs(_o5685, hr_str("_t", 2)); hr_fi(_o5685, p_1763); hr_fs(_o5685, hr_str(".n", 2)); }));
 }
(void)(({ hrv *_o5686 = &(g163); hr_fs(_o5686, hr_str("; if (_l", 8)); hr_fi(_o5686, p_1763); hr_fs(_o5686, hr_str(" < 0 || _h", 10)); hr_fi(_o5686, p_1763); hr_fs(_o5686, hr_str(" < _l", 5)); hr_fi(_o5686, p_1763); hr_fs(_o5686, hr_str(" || _h", 6)); hr_fi(_o5686, p_1763); hr_fs(_o5686, hr_str(" > _t", 5)); hr_fi(_o5686, p_1763); hr_fs(_o5686, hr_str(".n) hr_slerr(_l", 15)); hr_fi(_o5686, p_1763); hr_fs(_o5686, hr_str(", _h", 4)); hr_fi(_o5686, p_1763); hr_fs(_o5686, hr_str(", _t", 4)); hr_fi(_o5686, p_1763); hr_fs(_o5686, hr_str(".n, ", 4)); }));
(void)(f308_wloc(n_1758));
(void)(({ hrv *_o5688 = &(g163); hr_fs(_o5688, hr_str("); (hsl){ _t", 12)); hr_fi(_o5688, p_1763); hr_fs(_o5688, hr_str(".p + _l", 7)); hr_fi(_o5688, p_1763); hr_fs(_o5688, hr_str(" * (int64_t)sizeof(", 19)); }));
(void)(f258_ct(e_1762));
(void)(({ hrv *_o5690 = &(g163); hr_fs(_o5690, hr_str("), _h", 5)); hr_fi(_o5690, p_1763); hr_fs(_o5690, hr_str(" - _l", 5)); hr_fi(_o5690, p_1763); hr_fs(_o5690, hr_str(" }; })", 6)); }));
}
static void f313_garr(int64_t n_1766) {
S4 x_1767 = (*({ hrv *_t5691 = &(g696); int64_t _i5691 = n_1766; (S4*)_t5691->b + hr_ix(_i5691, _t5691->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:315"); })); 
int64_t t_1768 = f141_at(n_1766); 
int64_t e_1769 = ((int64_t)(((*({ hrv *_t5693 = &(g543); int64_t _i5693 = t_1768; (S1*)_t5693->b + hr_ix(_i5693, _t5693->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:317"); }))).a_)); 
int64_t p_1770 = f290_nt(); 
if (f265_is_res(t_1768)) { if (((((x_1767).n_) == (((int32_t)0LL))) && (((x_1767).a_) < (((int32_t)0LL))))) { (void)(f257_ow(hr_str("((hrv){0})", 10)));
return;
 }
(void)(f257_ow(hr_str("({ hrv _t", 9)));
(void)(f291_oi(p_1770));
(void)(f257_ow(hr_str(" = {0}; ", 8)));
if ((((x_1767).a_) >= (((int32_t)0LL)))) { (void)(f257_ow(hr_str("int64_t _c", 10)));
(void)(f291_oi(p_1770));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(((int64_t)((x_1767).b_))));
(void)(f257_ow(hr_str("; ", 2)));
(void)(f258_ct(e_1769));
(void)(f257_ow(hr_str(" _v", 3)));
(void)(f291_oi(p_1770));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(((int64_t)((x_1767).a_))));
(void)(f257_ow(hr_str("; ", 2)));
(void)(f258_ct(e_1769));
(void)(f257_ow(hr_str(" *_p", 4)));
(void)(f291_oi(p_1770));
(void)(f257_ow(hr_str(" = (", 4)));
(void)(f258_ct(e_1769));
(void)(({ hrv *_o5716 = &(g163); hr_fs(_o5716, hr_str("*)hr_grow(&_t", 13)); hr_fi(_o5716, p_1770); hr_fs(_o5716, hr_str(", _c", 4)); hr_fi(_o5716, p_1770); hr_fs(_o5716, hr_str(", sizeof _v", 11)); hr_fi(_o5716, p_1770); hr_fs(_o5716, hr_str("); for (int64_t _k = 0; _k < _c", 31)); hr_fi(_o5716, p_1770); hr_fs(_o5716, hr_str("; _k++) _p", 10)); hr_fi(_o5716, p_1770); hr_fs(_o5716, hr_str("[_k] = _v", 9)); hr_fi(_o5716, p_1770); hr_fs(_o5716, hr_str("; ", 2)); }));
 } else { (void)(f258_ct(e_1769));
(void)(f257_ow(hr_str(" *_p", 4)));
(void)(f291_oi(p_1770));
(void)(f257_ow(hr_str(" = (", 4)));
(void)(f258_ct(e_1769));
(void)(({ hrv *_o5722 = &(g163); hr_fs(_o5722, hr_str("*)hr_grow(&_t", 13)); hr_fi(_o5722, p_1770); hr_fs(_o5722, hr_str(", ", 2)); hr_fi(_o5722, (x_1767).n_); hr_fs(_o5722, hr_str(", sizeof(", 9)); }));
(void)(f258_ct(e_1769));
(void)(f257_ow(hr_str(")); ", 4)));
{ int32_t _e5726 = (x_1767).n_; for (int32_t _k5726 = 0; _k5726 < _e5726; _k5726++) { int32_t i_1771 = (int32_t)_k5726; (void)(({ hrv *_o5727 = &(g163); hr_fs(_o5727, hr_str("_p", 2)); hr_fi(_o5727, p_1770); hr_fs(_o5727, hr_str("[", 1)); hr_fi(_o5727, i_1771); hr_fs(_o5727, hr_str("] = ", 4)); }));
(void)(f286_gx(f90_kid(n_1766, ((int64_t)(i_1771)))));
(void)(f257_ow(hr_str("; ", 2)));
 } } _bk5725:; 
 }
(void)(f257_ow(hr_str("_t", 2)));
(void)(f291_oi(p_1770));
(void)(f257_ow(hr_str("; })", 4)));
return;
 }
if ((f279_is_fix(t_1768) || f280_is_lim(t_1768))) { (void)(f257_ow(hr_str("({ ", 3)));
(void)(f258_ct(t_1768));
(void)(f257_ow(hr_str(" _t", 3)));
(void)(f291_oi(p_1770));
(void)(f257_ow(hr_str("; ", 2)));
if ((((x_1767).a_) >= (((int32_t)0LL)))) { (void)(f258_ct(e_1769));
(void)(f257_ow(hr_str(" _v", 3)));
(void)(f291_oi(p_1770));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(((int64_t)((x_1767).a_))));
(void)(({ hrv *_o5746 = &(g163); hr_fs(_o5746, hr_str("; for (int64_t _k = 0; _k < ", 28)); hr_fi(_o5746, ({ int64_t _r5747; if (f279_is_fix(t_1768)) { _r5747 = ((*({ hrv *_t5749 = &(g543); int64_t _i5749 = t_1768; (S1*)_t5749->b + hr_ix(_i5749, _t5749->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:329"); }))).b_;  } else { _r5747 = ((int64_t)0LL);  } _r5747; })); hr_fs(_o5746, hr_str("; _k++) _t", 10)); hr_fi(_o5746, p_1770); hr_fs(_o5746, hr_str(".e[_k] = _v", 11)); hr_fi(_o5746, p_1770); hr_fs(_o5746, hr_str("; ", 2)); }));
if (f280_is_lim(t_1768)) { (void)(f257_ow(hr_str("int64_t _c", 10)));
(void)(f291_oi(p_1770));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(((int64_t)((x_1767).b_))));
(void)(({ hrv *_o5755 = &(g163); hr_fs(_o5755, hr_str("; for (int64_t _k = 0; _k < _c", 30)); hr_fi(_o5755, p_1770); hr_fs(_o5755, hr_str("; _k++) _t", 10)); hr_fi(_o5755, p_1770); hr_fs(_o5755, hr_str(".e[_k] = _v", 11)); hr_fi(_o5755, p_1770); hr_fs(_o5755, hr_str("; _t", 4)); hr_fi(_o5755, p_1770); hr_fs(_o5755, hr_str(".n = _c", 7)); hr_fi(_o5755, p_1770); hr_fs(_o5755, hr_str("; ", 2)); }));
 }
 } else { if (f280_is_lim(t_1768)) { (void)(({ hrv *_o5757 = &(g163); hr_fs(_o5757, hr_str("memset(&_t", 10)); hr_fi(_o5757, p_1770); hr_fs(_o5757, hr_str(", 0, sizeof _t", 14)); hr_fi(_o5757, p_1770); hr_fs(_o5757, hr_str("); _t", 5)); hr_fi(_o5757, p_1770); hr_fs(_o5757, hr_str(".n = ", 5)); hr_fi(_o5757, (x_1767).n_); hr_fs(_o5757, hr_str("; ", 2)); }));
 }
{ int32_t _e5759 = (x_1767).n_; for (int32_t _k5759 = 0; _k5759 < _e5759; _k5759++) { int32_t i_1772 = (int32_t)_k5759; (void)(({ hrv *_o5760 = &(g163); hr_fs(_o5760, hr_str("_t", 2)); hr_fi(_o5760, p_1770); hr_fs(_o5760, hr_str(".e[", 3)); hr_fi(_o5760, i_1772); hr_fs(_o5760, hr_str("] = ", 4)); }));
(void)(f286_gx(f90_kid(n_1766, ((int64_t)(i_1772)))));
(void)(f257_ow(hr_str("; ", 2)));
 } } _bk5758:; 
 }
(void)(f257_ow(hr_str("_t", 2)));
(void)(f291_oi(p_1770));
(void)(f257_ow(hr_str("; })", 4)));
return;
 }
(void)(f284_gerr(n_1766, hr_str("unsupported array literal type", 30)));
}
static void f314_gslit(int64_t n_1773) {
S4 x_1774 = (*({ hrv *_t5768 = &(g696); int64_t _i5768 = n_1773; (S4*)_t5768->b + hr_ix(_i5768, _t5768->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:346"); })); 
int64_t t_1775 = f141_at(n_1773); 
int64_t si_1776 = f157_rv(n_1773); 
int64_t f0_1777 = ((int64_t)(((*({ hrv *_t5771 = &(g546); int64_t _i5771 = si_1776; (S10*)_t5771->b + hr_ix(_i5771, _t5771->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:349"); }))).f0_)); 
(void)(f257_ow(hr_str("((", 2)));
(void)(f258_ct(t_1775));
(void)(f257_ow(hr_str("){ ", 3)));
bool any_1778 = false; 
{ int32_t _e5776 = ((*({ hrv *_t5777 = &(g546); int64_t _i5777 = si_1776; (S10*)_t5777->b + hr_ix(_i5777, _t5777->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:352"); }))).fnum_; for (int32_t _k5776 = 0; _k5776 < _e5776; _k5776++) { int32_t j_1779 = (int32_t)_k5776; S11 f_1780 = (*({ hrv *_t5778 = &(g547); int64_t _i5778 = ((int64_t)((int64_t)f0_1777 + (int64_t)((int64_t)(j_1779)))); (S11*)_t5778->b + hr_ix(_i5778, _t5778->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:353"); })); 
if ((((f_1780).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t given_1781 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e5780 = (x_1774).n_; for (int32_t _k5780 = 0; _k5780 < _e5780; _k5780++) { int32_t i_1782 = (int32_t)_k5780; if (((f157_rv(f90_kid(n_1773, ((int64_t)(i_1782))))) == (((int64_t)(j_1779))))) { given_1781 = f90_kid(n_1773, ((int64_t)(i_1782)));
 }
 } } _bk5779:; 
if ((((given_1781) < (((int64_t)0LL))) && (((f_1780).def_) < (((int32_t)0LL))))) { continue;
 }
(void)(f257_ow(hr_str(".", 1)));
(void)(f264_fname_into((&(g163)), ((int64_t)((f_1780).name_))));
(void)(f257_ow(hr_str(" = ", 3)));
if (((given_1781) >= (((int64_t)0LL)))) { int64_t v_1783 = ((int64_t)(((*({ hrv *_t5787 = &(g696); int64_t _i5787 = given_1781; (S4*)_t5787->b + hr_ix(_i5787, _t5787->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:359"); }))).a_)); 
if (f265_is_res(((int64_t)((f_1780).ty_)))) { (void)(f266_gxo(v_1783));
 } else { (void)(f286_gx(v_1783));
 }
 } else { int64_t sa_1784 = g393; 
g393 = g395;
(void)(f286_gx(((int64_t)((f_1780).def_))));
g393 = sa_1784;
 }
(void)(f257_ow(hr_str(", ", 2)));
any_1778 = true;
 } } _bk5775:; 
if ((!(any_1778))) { (void)(f257_ow(hr_str("0", 1)));
 }
(void)(f257_ow(hr_str("})", 2)));
}
static void f315_gcall(int64_t n_1785) {
int64_t r_1786 = f156_rk(n_1785); 
if (((r_1786) == (((int64_t)4LL)))) { (void)(f316_gbuiltin(n_1785));
return;
 }
if (((r_1786) == (((int64_t)10LL)))) { (void)(f328_gblkcall(n_1785));
return;
 }
if (((r_1786) != (((int64_t)3LL)))) { (void)(f284_gerr(n_1785, hr_str("unsupported call", 16)));
return;
 }
int64_t inst_1996 = f157_rv(n_1785); 
int64_t recv_1997 = ({ int64_t _r5800; if ((((f217_ax(n_1785)) == (((int64_t)1LL))) && ((((*({ hrv *_t5802 = &(g696); int64_t _i5802 = ((*({ hrv *_t5803 = &(g696); int64_t _i5803 = n_1785; (S4*)_t5803->b + hr_ix(_i5803, _t5803->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:589"); }))).a_; (S4*)_t5802->b + hr_ix(_i5802, _t5802->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:589"); }))).k_) == (((uint8_t)14LL))))) { _r5800 = ((int64_t)(((*({ hrv *_t5804 = &(g696); int64_t _i5804 = ((*({ hrv *_t5805 = &(g696); int64_t _i5805 = n_1785; (S4*)_t5805->b + hr_ix(_i5805, _t5805->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:589"); }))).a_; (S4*)_t5804->b + hr_ix(_i5804, _t5804->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:589"); }))).a_));  } else { _r5800 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r5800; }); 
bool lrw_1999 = ((!(f351_is_ext(inst_1996))) && ((*({ hrv *_t5807 = &(g380); int64_t _i5807 = inst_1996; (S6*)_t5807->b + hr_ix(_i5807, _t5807->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:590"); }))).lr_); 
int64_t rt_2000 = ((int64_t)(((*({ hrv *_t5808 = &(g380); int64_t _i5808 = inst_1996; (S6*)_t5808->b + hr_ix(_i5808, _t5808->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:591"); }))).ret_)); 
bool vd_2001 = (((rt_2000) < (((int64_t)0LL))) || ((rt_2000) == (g550))); 
int64_t q_2002 = f290_nt(); 
if (lrw_1999) { (void)(f257_ow(hr_str("({ ", 3)));
if ((!(vd_2001))) { (void)(f258_ct(rt_2000));
(void)(({ hrv *_o5812 = &(g163); hr_fs(_o5812, hr_str(" _c", 3)); hr_fi(_o5812, q_2002); hr_fs(_o5812, hr_str(" = ", 3)); }));
 }
 }
if (f351_is_ext(inst_1996)) { (void)(f352_ext_name(inst_1996));
 } else { (void)(f353_fn_cname(inst_1996));
 }
(void)(f257_ow(hr_str("(", 1)));
(void)(f354_gcall_args(n_1785, inst_1996, recv_1997));
(void)(f257_ow(hr_str(")", 1)));
if (lrw_1999) { (void)(f257_ow(hr_str("; ", 2)));
(void)(f356_glrcheck());
if ((!(vd_2001))) { (void)(({ hrv *_o5821 = &(g163); hr_fs(_o5821, hr_str("_c", 2)); hr_fi(_o5821, q_2002); hr_fs(_o5821, hr_str("; ", 2)); }));
 }
(void)(f257_ow(hr_str("})", 2)));
 }
}
static void f316_gbuiltin(int64_t n_1787) {
S4 x_1788 = (*({ hrv *_t5823 = &(g696); int64_t _i5823 = n_1787; (S4*)_t5823->b + hr_ix(_i5823, _t5823->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:628"); })); 
int64_t b_1789 = f157_rv(n_1787); 
bool hasr_1790 = ((f217_ax(n_1787)) == (((int64_t)1LL))); 
int64_t recv_1791 = ({ int64_t _r5826; if (hasr_1790) { _r5826 = ((int64_t)(((*({ hrv *_t5827 = &(g696); int64_t _i5827 = (x_1788).a_; (S4*)_t5827->b + hr_ix(_i5827, _t5827->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:631"); }))).a_));  } else { _r5826 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r5826; }); 
int64_t total_1792 = ((int64_t)((int64_t)((int64_t)((x_1788).n_)) + (int64_t)({ int64_t _r5828; if (hasr_1790) { _r5828 = ((int64_t)1LL);  } else { _r5828 = ((int64_t)0LL);  } _r5828; }))); 

int64_t p_1794 = f290_nt(); 
if (((b_1789) == (((int64_t)1LL)))) { (void)(f257_ow(hr_str("({ ", 3)));
{ int32_t _e5832 = (x_1788).n_; for (int32_t _k5832 = 0; _k5832 < _e5832; _k5832++) { int32_t i_1795 = (int32_t)_k5832; int64_t c_1796 = f90_kid(n_1787, ((int64_t)(i_1795))); 
(void)(f318_gfmt(hr_str("&hr_ob", 6), c_1796, f276_fin(c_1796), true));
(void)(f257_ow(hr_str("; ", 2)));
 } } _bk5831:; 
(void)(f257_ow(hr_str("hr_println(); })", 16)));
return;
 }
if (((b_1789) == (((int64_t)2LL)))) { (void)(f257_ow(hr_str("({ hrv _o", 9)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" = {0}; ", 8)));
L99 nmo_1803 = ({ L99 _t5841; memset(&_t5841, 0, sizeof _t5841); _t5841.n = 0; _t5841; }); 
(void)(({ L99 *_l5842 = &(nmo_1803); hrv _o5842 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5842, hr_str("&_o", 3)); hr_fi(&_o5842, p_1794); if (_l5842->n + _o5842.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:636"); memcpy(_l5842->e + _l5842->n, _o5842.b, (size_t)_o5842.n); _l5842->n += _o5842.n; }));
{ int32_t _e5844 = (x_1788).n_; for (int32_t _k5844 = 0; _k5844 < _e5844; _k5844++) { int32_t i_1804 = (int32_t)_k5844; int64_t c_1805 = f90_kid(n_1787, ((int64_t)(i_1804))); 
(void)(f318_gfmt(({ hsl _t5847 = ({ L99 *_t5848 = &(nmo_1803); (hsl){ (uint8_t*)_t5848->e, _t5848->n }; }); int64_t _l5847 = 0, _h5847 = _t5847.n; if (_l5847 < 0 || _h5847 < _l5847 || _h5847 > _t5847.n) hr_slerr(_l5847, _h5847, _t5847.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:636"); (hsl){ _t5847.p + _l5847 * (int64_t)sizeof(uint8_t), _h5847 - _l5847 }; }), c_1805, f276_fin(c_1805), true));
(void)(f257_ow(hr_str("; ", 2)));
 } } _bk5843:; 
(void)(f257_ow(hr_str("_o", 2)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str("; })", 4)));
return;
 }
if ((((b_1789) == (((int64_t)3LL))) && f280_is_lim(f179_deref(f141_at(f317_arg(((int64_t)0LL), &recv_1791, &n_1787)))))) { int64_t lt_1806 = f179_deref(f141_at(f317_arg(((int64_t)0LL), &recv_1791, &n_1787))); 
(void)(f257_ow(hr_str("({ ", 3)));
(void)(f258_ct(lt_1806));
(void)(f257_ow(hr_str(" *_l", 4)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f319_grecv_ptr(f317_arg(((int64_t)0LL), &recv_1791, &n_1787)));
(void)(f257_ow(hr_str("; hrv _o", 8)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" __attribute__((cleanup(hr_rdrop))) = {0}; ", 43)));
L99 nmo_1810 = ({ L99 _t5871; memset(&_t5871, 0, sizeof _t5871); _t5871.n = 0; _t5871; }); 
(void)(({ L99 *_l5872 = &(nmo_1810); hrv _o5872 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5872, hr_str("&_o", 3)); hr_fi(&_o5872, p_1794); if (_l5872->n + _o5872.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:640"); memcpy(_l5872->e + _l5872->n, _o5872.b, (size_t)_o5872.n); _l5872->n += _o5872.n; }));
{ int64_t _e5874 = total_1792; for (int64_t _k5874 = ((int64_t)1LL); _k5874 < _e5874; _k5874++) { int64_t i_1811 = (int64_t)_k5874; int64_t c_1812 = f317_arg(i_1811, &recv_1791, &n_1787); 
(void)(f318_gfmt(({ hsl _t5877 = ({ L99 *_t5878 = &(nmo_1810); (hsl){ (uint8_t*)_t5878->e, _t5878->n }; }); int64_t _l5877 = 0, _h5877 = _t5877.n; if (_l5877 < 0 || _h5877 < _l5877 || _h5877 > _t5877.n) hr_slerr(_l5877, _h5877, _t5877.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:641"); (hsl){ _t5877.p + _l5877 * (int64_t)sizeof(uint8_t), _h5877 - _l5877 }; }), c_1812, f276_fin(c_1812), true));
(void)(f257_ow(hr_str("; ", 2)));
 } } _bk5873:; 
(void)(({ hrv *_o5881 = &(g163); hr_fs(_o5881, hr_str("if (_l", 6)); hr_fi(_o5881, p_1794); hr_fs(_o5881, hr_str("->n + _o", 8)); hr_fi(_o5881, p_1794); hr_fs(_o5881, hr_str(".n > ", 5)); hr_fi(_o5881, ((*({ hrv *_t5882 = &(g543); int64_t _i5882 = lt_1806; (S1*)_t5882->b + hr_ix(_i5882, _t5882->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:642"); }))).b_); hr_fs(_o5881, hr_str(") hr_die(\"format past a limited array's capacity\", ", 51)); }));
(void)(f308_wloc(n_1787));
(void)(({ hrv *_o5884 = &(g163); hr_fs(_o5884, hr_str("); memcpy(_l", 12)); hr_fi(_o5884, p_1794); hr_fs(_o5884, hr_str("->e + _l", 8)); hr_fi(_o5884, p_1794); hr_fs(_o5884, hr_str("->n, _o", 7)); hr_fi(_o5884, p_1794); hr_fs(_o5884, hr_str(".b, (size_t)_o", 14)); hr_fi(_o5884, p_1794); hr_fs(_o5884, hr_str(".n); _l", 7)); hr_fi(_o5884, p_1794); hr_fs(_o5884, hr_str("->n += _o", 9)); hr_fi(_o5884, p_1794); hr_fs(_o5884, hr_str(".n; })", 6)); }));
return;
 }
if (((b_1789) == (((int64_t)3LL)))) { (void)(f257_ow(hr_str("({ hrv *_o", 10)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f319_grecv_ptr(f317_arg(((int64_t)0LL), &recv_1791, &n_1787)));
(void)(f257_ow(hr_str("; ", 2)));
L99 nmo_1813 = ({ L99 _t5891; memset(&_t5891, 0, sizeof _t5891); _t5891.n = 0; _t5891; }); 
(void)(({ L99 *_l5892 = &(nmo_1813); hrv _o5892 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o5892, hr_str("_o", 2)); hr_fi(&_o5892, p_1794); if (_l5892->n + _o5892.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:645"); memcpy(_l5892->e + _l5892->n, _o5892.b, (size_t)_o5892.n); _l5892->n += _o5892.n; }));
{ int64_t _e5894 = total_1792; for (int64_t _k5894 = ((int64_t)1LL); _k5894 < _e5894; _k5894++) { int64_t i_1814 = (int64_t)_k5894; int64_t c_1815 = f317_arg(i_1814, &recv_1791, &n_1787); 
(void)(f318_gfmt(({ hsl _t5897 = ({ L99 *_t5898 = &(nmo_1813); (hsl){ (uint8_t*)_t5898->e, _t5898->n }; }); int64_t _l5897 = 0, _h5897 = _t5897.n; if (_l5897 < 0 || _h5897 < _l5897 || _h5897 > _t5897.n) hr_slerr(_l5897, _h5897, _t5897.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:645"); (hsl){ _t5897.p + _l5897 * (int64_t)sizeof(uint8_t), _h5897 - _l5897 }; }), c_1815, f276_fin(c_1815), true));
(void)(f257_ow(hr_str("; ", 2)));
 } } _bk5893:; 
(void)(f257_ow(hr_str("})", 2)));
return;
 }
if (((b_1789) == (((int64_t)4LL)))) { (void)(f257_ow(hr_str("({ if (!(", 9)));
(void)(f286_gx(f317_arg(((int64_t)0LL), &recv_1791, &n_1787)));
(void)(f257_ow(hr_str(")) hr_assert_fail(", 18)));
(void)(f308_wloc(n_1787));
(void)(f257_ow(hr_str("); })", 5)));
return;
 }
if (((b_1789) == (((int64_t)5LL)))) { (void)(f257_ow(hr_str("hr_abort(", 9)));
(void)(f288_gas(f317_arg(((int64_t)0LL), &recv_1791, &n_1787)));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if (((b_1789) == (((int64_t)6LL)))) { (void)(f257_ow(hr_str("hr_exit(", 8)));
(void)(f286_gx(f317_arg(((int64_t)0LL), &recv_1791, &n_1787)));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if (((b_1789) == (((int64_t)8LL)))) { int64_t t_1816 = f141_at(n_1787); 
(void)(f257_ow(hr_str("({ ", 3)));
(void)(f258_ct(t_1816));
(void)(f257_ow(hr_str(" _d", 3)));
(void)(f291_oi(p_1794));
(void)(({ hrv *_o5921 = &(g163); hr_fs(_o5921, hr_str("; memset(&_d", 12)); hr_fi(_o5921, p_1794); hr_fs(_o5921, hr_str(", 0, sizeof _d", 14)); hr_fi(_o5921, p_1794); hr_fs(_o5921, hr_str("); _d", 5)); hr_fi(_o5921, p_1794); hr_fs(_o5921, hr_str("; })", 4)); }));
return;
 }
if (((b_1789) == (((int64_t)9LL)))) { int64_t c_1817 = f317_arg(((int64_t)0LL), &recv_1791, &n_1787); 
int64_t t_1818 = f179_deref(f276_fin(c_1817)); 
if (f279_is_fix(t_1818)) { (void)(({ hrv *_o5926 = &(g163); hr_fs(_o5926, hr_str("((int64_t)", 10)); hr_fi(_o5926, ((*({ hrv *_t5927 = &(g543); int64_t _i5927 = t_1818; (S1*)_t5927->b + hr_ix(_i5927, _t5927->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:650"); }))).b_); hr_fs(_o5926, hr_str(")", 1)); }));
return;
 }
(void)(f257_ow(hr_str("(", 1)));
(void)(f288_gas(c_1817));
(void)(f257_ow(hr_str(").n", 3)));
return;
 }
if (((b_1789) == (((int64_t)7LL)))) { int64_t c_1819 = f317_arg(((int64_t)0LL), &recv_1791, &n_1787); 
int64_t t_1820 = f179_deref(f276_fin(c_1819)); 
if ((((((*({ hrv *_t5934 = &(g543); int64_t _i5934 = t_1820; (S1*)_t5934->b + hr_ix(_i5934, _t5934->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:651"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t5935 = &(g543); int64_t _i5935 = t_1820; (S1*)_t5935->b + hr_ix(_i5935, _t5935->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:651"); }))).k_) == (((uint8_t)9LL))))) { (void)(f257_ow(hr_str("hr_rfrom(", 9)));
(void)(f288_gas(c_1819));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f320_esz(((int64_t)(((*({ hrv *_t5940 = &(g543); int64_t _i5940 = t_1820; (S1*)_t5940->b + hr_ix(_i5940, _t5940->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:651"); }))).a_))));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if (((f276_fin(c_1819)) != (t_1820))) { (void)(f257_ow(hr_str("(*", 2)));
(void)(f286_gx(c_1819));
(void)(f257_ow(hr_str(")", 1)));
 } else { (void)(f286_gx(c_1819));
 }
return;
 }
if (((b_1789) == (((int64_t)31LL)))) { int64_t c_1822 = f317_arg(((int64_t)0LL), &recv_1791, &n_1787); 
int64_t t_1823 = f179_deref(f276_fin(c_1822)); 
if ((((((*({ hrv *_t5950 = &(g543); int64_t _i5950 = t_1823; (S1*)_t5950->b + hr_ix(_i5950, _t5950->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:652"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t5951 = &(g543); int64_t _i5951 = t_1823; (S1*)_t5951->b + hr_ix(_i5951, _t5951->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:652"); }))).k_) == (((uint8_t)9LL))))) { int64_t q_1824 = f290_nt(); 
(void)(f257_ow(hr_str("({ hsl _s", 9)));
(void)(f291_oi(q_1824));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f288_gas(c_1822));
(void)(({ hrv *_o5957 = &(g163); hr_fs(_o5957, hr_str("; (hsl){ _s", 11)); hr_fi(_o5957, q_1824); hr_fs(_o5957, hr_str(".p, _s", 6)); hr_fi(_o5957, q_1824); hr_fs(_o5957, hr_str(".n * (int64_t)sizeof(", 21)); }));
(void)(f258_ct(((int64_t)(((*({ hrv *_t5959 = &(g543); int64_t _i5959 = t_1823; (S1*)_t5959->b + hr_ix(_i5959, _t5959->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:652"); }))).a_))));
(void)(f257_ow(hr_str(") }; })", 7)));
return;
 }
(void)(f257_ow(hr_str("((hsl){ (uint8_t*)", 18)));
(void)(f321_gaddr(c_1822));
(void)(f257_ow(hr_str(", sizeof(", 9)));
(void)(f258_ct(t_1823));
(void)(f257_ow(hr_str(") })", 4)));
return;
 }
if (((b_1789) == (((int64_t)30LL)))) { int64_t c_1828 = f317_arg(((int64_t)0LL), &recv_1791, &n_1787); 
int64_t t_1829 = f179_deref(f276_fin(c_1828)); 
(void)(f257_ow(hr_str("hr_rfrom(", 9)));
if ((((((*({ hrv *_t5970 = &(g543); int64_t _i5970 = t_1829; (S1*)_t5970->b + hr_ix(_i5970, _t5970->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:653"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t5971 = &(g543); int64_t _i5971 = t_1829; (S1*)_t5971->b + hr_ix(_i5971, _t5971->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:653"); }))).k_) == (((uint8_t)9LL))))) { int64_t q_1830 = f290_nt(); 
(void)(f257_ow(hr_str("({ hsl _s", 9)));
(void)(f291_oi(q_1830));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f288_gas(c_1828));
(void)(({ hrv *_o5977 = &(g163); hr_fs(_o5977, hr_str("; (hsl){ _s", 11)); hr_fi(_o5977, q_1830); hr_fs(_o5977, hr_str(".p, _s", 6)); hr_fi(_o5977, q_1830); hr_fs(_o5977, hr_str(".n * (int64_t)sizeof(", 21)); }));
(void)(f258_ct(((int64_t)(((*({ hrv *_t5979 = &(g543); int64_t _i5979 = t_1829; (S1*)_t5979->b + hr_ix(_i5979, _t5979->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:653"); }))).a_))));
(void)(f257_ow(hr_str(") }; })", 7)));
 } else { (void)(f257_ow(hr_str("((hsl){ (uint8_t*)", 18)));
(void)(f321_gaddr(c_1828));
(void)(f257_ow(hr_str(", sizeof(", 9)));
(void)(f258_ct(t_1829));
(void)(f257_ow(hr_str(") })", 4)));
 }
(void)(f257_ow(hr_str(", 1)", 4)));
return;
 }
if (((b_1789) == (((int64_t)32LL)))) { int64_t t_1831 = f141_at(n_1787); 
(void)(f257_ow(hr_str("({ hsl _s", 9)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f288_gas(f317_arg(((int64_t)0LL), &recv_1791, &n_1787)));
(void)(f257_ow(hr_str("; ", 2)));
(void)(f258_ct(t_1831));
(void)(({ hrv *_o5995 = &(g163); hr_fs(_o5995, hr_str(" _d", 3)); hr_fi(_o5995, p_1794); hr_fs(_o5995, hr_str("; if (_s", 8)); hr_fi(_o5995, p_1794); hr_fs(_o5995, hr_str(".n != sizeof _d", 15)); hr_fi(_o5995, p_1794); hr_fs(_o5995, hr_str(") hr_die(\"from_bytes: wrong byte count\", ", 41)); }));
(void)(f308_wloc(n_1787));
(void)(({ hrv *_o5997 = &(g163); hr_fs(_o5997, hr_str("); memcpy(&_d", 13)); hr_fi(_o5997, p_1794); hr_fs(_o5997, hr_str(", _s", 4)); hr_fi(_o5997, p_1794); hr_fs(_o5997, hr_str(".p, sizeof _d", 13)); hr_fi(_o5997, p_1794); hr_fs(_o5997, hr_str("); _d", 5)); hr_fi(_o5997, p_1794); hr_fs(_o5997, hr_str("; })", 4)); }));
return;
 }
int64_t rt_1832 = f179_deref(f141_at(recv_1791)); 
int64_t e_1833 = ((int64_t)(((*({ hrv *_t6000 = &(g543); int64_t _i6000 = rt_1832; (S1*)_t6000->b + hr_ix(_i6000, _t6000->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:656"); }))).a_)); 
if (f280_is_lim(rt_1832)) { (void)(f257_ow(hr_str("({ ", 3)));
(void)(f258_ct(rt_1832));
(void)(f257_ow(hr_str(" *_v", 4)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f319_grecv_ptr(recv_1791));
(void)(f257_ow(hr_str("; ", 2)));
if (((b_1789) == (((int64_t)20LL)))) { (void)(f258_ct(e_1833));
(void)(f257_ow(hr_str(" _x", 3)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(f317_arg(((int64_t)1LL), &recv_1791, &n_1787)));
(void)(({ hrv *_o6015 = &(g163); hr_fs(_o6015, hr_str("; if (_v", 8)); hr_fi(_o6015, p_1794); hr_fs(_o6015, hr_str("->n >= ", 7)); hr_fi(_o6015, ((*({ hrv *_t6016 = &(g543); int64_t _i6016 = rt_1832; (S1*)_t6016->b + hr_ix(_i6016, _t6016->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:659"); }))).b_); hr_fs(_o6015, hr_str(") hr_die(\"push past a limited array's capacity\", ", 49)); }));
(void)(f308_wloc(n_1787));
(void)(({ hrv *_o6018 = &(g163); hr_fs(_o6018, hr_str("); _v", 5)); hr_fi(_o6018, p_1794); hr_fs(_o6018, hr_str("->e[_v", 6)); hr_fi(_o6018, p_1794); hr_fs(_o6018, hr_str("->n] = _x", 9)); hr_fi(_o6018, p_1794); hr_fs(_o6018, hr_str("; &_v", 5)); hr_fi(_o6018, p_1794); hr_fs(_o6018, hr_str("->e[_v", 6)); hr_fi(_o6018, p_1794); hr_fs(_o6018, hr_str("->n++]; })", 10)); }));
return;
 }
if (((b_1789) == (((int64_t)21LL)))) { (void)(({ hrv *_o6019 = &(g163); hr_fs(_o6019, hr_str("hsl _s", 6)); hr_fi(_o6019, p_1794); hr_fs(_o6019, hr_str(" = ", 3)); }));
(void)(f288_gas(f317_arg(((int64_t)1LL), &recv_1791, &n_1787)));
(void)(({ hrv *_o6022 = &(g163); hr_fs(_o6022, hr_str("; if (_v", 8)); hr_fi(_o6022, p_1794); hr_fs(_o6022, hr_str("->n + _s", 8)); hr_fi(_o6022, p_1794); hr_fs(_o6022, hr_str(".n > ", 5)); hr_fi(_o6022, ((*({ hrv *_t6023 = &(g543); int64_t _i6023 = rt_1832; (S1*)_t6023->b + hr_ix(_i6023, _t6023->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:660"); }))).b_); hr_fs(_o6022, hr_str(") hr_die(\"append past a limited array's capacity\", ", 51)); }));
(void)(f308_wloc(n_1787));
(void)(({ hrv *_o6025 = &(g163); hr_fs(_o6025, hr_str("); memmove(_v", 13)); hr_fi(_o6025, p_1794); hr_fs(_o6025, hr_str("->e + _v", 8)); hr_fi(_o6025, p_1794); hr_fs(_o6025, hr_str("->n, _s", 7)); hr_fi(_o6025, p_1794); hr_fs(_o6025, hr_str(".p, (size_t)_s", 14)); hr_fi(_o6025, p_1794); hr_fs(_o6025, hr_str(".n * sizeof _v", 14)); hr_fi(_o6025, p_1794); hr_fs(_o6025, hr_str("->e[0]); _v", 11)); hr_fi(_o6025, p_1794); hr_fs(_o6025, hr_str("->n += _s", 9)); hr_fi(_o6025, p_1794); hr_fs(_o6025, hr_str(".n; })", 6)); }));
return;
 }
if (((b_1789) == (((int64_t)22LL)))) { (void)(({ hrv *_o6026 = &(g163); hr_fs(_o6026, hr_str("if (!_v", 7)); hr_fi(_o6026, p_1794); hr_fs(_o6026, hr_str("->n) hr_die(\"pop of an empty array\", ", 37)); }));
(void)(f308_wloc(n_1787));
(void)(({ hrv *_o6028 = &(g163); hr_fs(_o6028, hr_str("); _v", 5)); hr_fi(_o6028, p_1794); hr_fs(_o6028, hr_str("->e[--_v", 8)); hr_fi(_o6028, p_1794); hr_fs(_o6028, hr_str("->n]; })", 8)); }));
return;
 }
if (((b_1789) == (((int64_t)23LL)))) { (void)(({ hrv *_o6029 = &(g163); hr_fs(_o6029, hr_str("int64_t _k", 10)); hr_fi(_o6029, p_1794); hr_fs(_o6029, hr_str(" = ", 3)); }));
(void)(f286_gx(f317_arg(((int64_t)1LL), &recv_1791, &n_1787)));
(void)(({ hrv *_o6032 = &(g163); hr_fs(_o6032, hr_str("; if (_k", 8)); hr_fi(_o6032, p_1794); hr_fs(_o6032, hr_str(" < 0 || _k", 10)); hr_fi(_o6032, p_1794); hr_fs(_o6032, hr_str(" > _v", 5)); hr_fi(_o6032, p_1794); hr_fs(_o6032, hr_str("->n) hr_die(\"pop_n past the length\", ", 37)); }));
(void)(f308_wloc(n_1787));
(void)(({ hrv *_o6034 = &(g163); hr_fs(_o6034, hr_str("); _v", 5)); hr_fi(_o6034, p_1794); hr_fs(_o6034, hr_str("->n -= _k", 9)); hr_fi(_o6034, p_1794); hr_fs(_o6034, hr_str("; })", 4)); }));
return;
 }
if (((b_1789) == (((int64_t)25LL)))) { (void)(({ hrv *_o6035 = &(g163); hr_fs(_o6035, hr_str("_v", 2)); hr_fi(_o6035, p_1794); hr_fs(_o6035, hr_str("->n = 0; })", 11)); }));
return;
 }
if (((b_1789) == (((int64_t)24LL)))) { (void)(({ hrv *_o6036 = &(g163); hr_fs(_o6036, hr_str("int64_t _k", 10)); hr_fi(_o6036, p_1794); hr_fs(_o6036, hr_str(" = ", 3)); }));
(void)(f286_gx(f317_arg(((int64_t)1LL), &recv_1791, &n_1787)));
(void)(({ hrv *_o6039 = &(g163); hr_fs(_o6039, hr_str("; if (_k", 8)); hr_fi(_o6039, p_1794); hr_fs(_o6039, hr_str(" < 0 || _k", 10)); hr_fi(_o6039, p_1794); hr_fs(_o6039, hr_str(" > ", 3)); hr_fi(_o6039, ((*({ hrv *_t6040 = &(g543); int64_t _i6040 = rt_1832; (S1*)_t6040->b + hr_ix(_i6040, _t6040->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:664"); }))).b_); hr_fs(_o6039, hr_str(") hr_die(\"resize past a limited array's capacity\", ", 51)); }));
(void)(f308_wloc(n_1787));
(void)(({ hrv *_o6042 = &(g163); hr_fs(_o6042, hr_str("); for (int64_t _j = _v", 23)); hr_fi(_o6042, p_1794); hr_fs(_o6042, hr_str("->n; _j < _k", 12)); hr_fi(_o6042, p_1794); hr_fs(_o6042, hr_str("; _j++) memset(&_v", 18)); hr_fi(_o6042, p_1794); hr_fs(_o6042, hr_str("->e[_j], 0, sizeof _v", 21)); hr_fi(_o6042, p_1794); hr_fs(_o6042, hr_str("->e[0]); ", 9)); }));
if (((total_1792) > (((int64_t)2LL)))) { (void)(({ hrv *_o6043 = &(g163); hr_fs(_o6043, hr_str("for (int64_t _j = _v", 20)); hr_fi(_o6043, p_1794); hr_fs(_o6043, hr_str("->n; _j < _k", 12)); hr_fi(_o6043, p_1794); hr_fs(_o6043, hr_str("; _j++) _v", 10)); hr_fi(_o6043, p_1794); hr_fs(_o6043, hr_str("->e[_j] = ", 10)); }));
(void)(f286_gx(f317_arg(((int64_t)2LL), &recv_1791, &n_1787)));
(void)(f257_ow(hr_str("; ", 2)));
 }
(void)(({ hrv *_o6047 = &(g163); hr_fs(_o6047, hr_str("_v", 2)); hr_fi(_o6047, p_1794); hr_fs(_o6047, hr_str("->n = _k", 8)); hr_fi(_o6047, p_1794); hr_fs(_o6047, hr_str("; })", 4)); }));
return;
 }
if (((b_1789) == (((int64_t)26LL)))) { (void)(f258_ct(e_1833));
(void)(f257_ow(hr_str(" _x", 3)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(f317_arg(((int64_t)1LL), &recv_1791, &n_1787)));
(void)(({ hrv *_o6054 = &(g163); hr_fs(_o6054, hr_str("; int64_t _r", 12)); hr_fi(_o6054, p_1794); hr_fs(_o6054, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6054, p_1794); hr_fs(_o6054, hr_str("->n; _j++) if (", 15)); }));
(void)(f322_heq_val_o(e_1833, p_1794));
(void)(({ hrv *_o6056 = &(g163); hr_fs(_o6056, hr_str(") { _r", 6)); hr_fi(_o6056, p_1794); hr_fs(_o6056, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6056, p_1794); hr_fs(_o6056, hr_str("; })", 4)); }));
return;
 }
(void)(f284_gerr(n_1787, hr_str("unsupported limited-array operation", 35)));
return;
 }
if ((((((*({ hrv *_t6058 = &(g543); int64_t _i6058 = rt_1832; (S1*)_t6058->b + hr_ix(_i6058, _t6058->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:668"); }))).k_) == (((uint8_t)9LL))) || f279_is_fix(rt_1832))) { if (((b_1789) == (((int64_t)26LL)))) { (void)(f257_ow(hr_str("({ hsl _v", 9)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f288_gas(recv_1791));
(void)(f257_ow(hr_str("; ", 2)));
(void)(f258_ct(e_1833));
(void)(f257_ow(hr_str(" _x", 3)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(f317_arg(((int64_t)1LL), &recv_1791, &n_1787)));
(void)(({ hrv *_o6071 = &(g163); hr_fs(_o6071, hr_str("; int64_t _r", 12)); hr_fi(_o6071, p_1794); hr_fs(_o6071, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6071, p_1794); hr_fs(_o6071, hr_str(".n; _j++) if (", 14)); }));
(void)(f326_heq_val_s(e_1833, p_1794));
(void)(({ hrv *_o6073 = &(g163); hr_fs(_o6073, hr_str(") { _r", 6)); hr_fi(_o6073, p_1794); hr_fs(_o6073, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6073, p_1794); hr_fs(_o6073, hr_str("; })", 4)); }));
return;
 }
(void)(f284_gerr(n_1787, hr_str("this operation needs a resizable array", 38)));
return;
 }
(void)(f257_ow(hr_str("({ hrv *_v", 10)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f319_grecv_ptr(recv_1791));
(void)(f257_ow(hr_str("; ", 2)));
if (((b_1789) == (((int64_t)20LL)))) { (void)(f258_ct(e_1833));
(void)(f257_ow(hr_str(" _x", 3)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(f317_arg(((int64_t)1LL), &recv_1791, &n_1787)));
(void)(f257_ow(hr_str("; ", 2)));
(void)(f258_ct(e_1833));
(void)(f257_ow(hr_str(" *_p", 4)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" = (", 4)));
(void)(f258_ct(e_1833));
(void)(({ hrv *_o6092 = &(g163); hr_fs(_o6092, hr_str("*)hr_grow(_v", 12)); hr_fi(_o6092, p_1794); hr_fs(_o6092, hr_str(", 1, sizeof _x", 14)); hr_fi(_o6092, p_1794); hr_fs(_o6092, hr_str("); *_p", 6)); hr_fi(_o6092, p_1794); hr_fs(_o6092, hr_str(" = _x", 5)); hr_fi(_o6092, p_1794); hr_fs(_o6092, hr_str("; _p", 4)); hr_fi(_o6092, p_1794); hr_fs(_o6092, hr_str("; })", 4)); }));
return;
 }
if (((b_1789) == (((int64_t)21LL)))) { (void)(({ hrv *_o6093 = &(g163); hr_fs(_o6093, hr_str("hsl _s", 6)); hr_fi(_o6093, p_1794); hr_fs(_o6093, hr_str(" = ", 3)); }));
(void)(f288_gas(f317_arg(((int64_t)1LL), &recv_1791, &n_1787)));
(void)(({ hrv *_o6096 = &(g163); hr_fs(_o6096, hr_str("; hr_append(_v", 14)); hr_fi(_o6096, p_1794); hr_fs(_o6096, hr_str(", _s", 4)); hr_fi(_o6096, p_1794); hr_fs(_o6096, hr_str(".p, _s", 6)); hr_fi(_o6096, p_1794); hr_fs(_o6096, hr_str(".n, sizeof(", 11)); }));
(void)(f258_ct(e_1833));
(void)(f257_ow(hr_str(")); })", 6)));
return;
 }
if (((b_1789) == (((int64_t)22LL)))) { (void)(({ hrv *_o6099 = &(g163); hr_fs(_o6099, hr_str("if (!_v", 7)); hr_fi(_o6099, p_1794); hr_fs(_o6099, hr_str("->n) hr_die(\"pop of an empty array\", ", 37)); }));
(void)(f308_wloc(n_1787));
(void)(({ hrv *_o6101 = &(g163); hr_fs(_o6101, hr_str("); ((", 5)); }));
(void)(f258_ct(e_1833));
(void)(({ hrv *_o6103 = &(g163); hr_fs(_o6103, hr_str("*)_v", 4)); hr_fi(_o6103, p_1794); hr_fs(_o6103, hr_str("->b)[--_v", 9)); hr_fi(_o6103, p_1794); hr_fs(_o6103, hr_str("->n]; })", 8)); }));
return;
 }
if (((b_1789) == (((int64_t)23LL)))) { (void)(({ hrv *_o6104 = &(g163); hr_fs(_o6104, hr_str("int64_t _k", 10)); hr_fi(_o6104, p_1794); hr_fs(_o6104, hr_str(" = ", 3)); }));
(void)(f286_gx(f317_arg(((int64_t)1LL), &recv_1791, &n_1787)));
(void)(({ hrv *_o6107 = &(g163); hr_fs(_o6107, hr_str("; if (_k", 8)); hr_fi(_o6107, p_1794); hr_fs(_o6107, hr_str(" < 0 || _k", 10)); hr_fi(_o6107, p_1794); hr_fs(_o6107, hr_str(" > _v", 5)); hr_fi(_o6107, p_1794); hr_fs(_o6107, hr_str("->n) hr_die(\"pop_n past the length\", ", 37)); }));
(void)(f308_wloc(n_1787));
(void)(({ hrv *_o6109 = &(g163); hr_fs(_o6109, hr_str("); _v", 5)); hr_fi(_o6109, p_1794); hr_fs(_o6109, hr_str("->n -= _k", 9)); hr_fi(_o6109, p_1794); hr_fs(_o6109, hr_str("; })", 4)); }));
return;
 }
if (((b_1789) == (((int64_t)25LL)))) { (void)(({ hrv *_o6110 = &(g163); hr_fs(_o6110, hr_str("_v", 2)); hr_fi(_o6110, p_1794); hr_fs(_o6110, hr_str("->n = 0; })", 11)); }));
return;
 }
if (((b_1789) == (((int64_t)24LL)))) { (void)(({ hrv *_o6111 = &(g163); hr_fs(_o6111, hr_str("int64_t _k", 10)); hr_fi(_o6111, p_1794); hr_fs(_o6111, hr_str(" = ", 3)); }));
(void)(f286_gx(f317_arg(((int64_t)1LL), &recv_1791, &n_1787)));
(void)(({ hrv *_o6114 = &(g163); hr_fs(_o6114, hr_str("; if (_k", 8)); hr_fi(_o6114, p_1794); hr_fs(_o6114, hr_str(" < 0) hr_die(\"resize to a negative length\", ", 44)); }));
(void)(f308_wloc(n_1787));
(void)(f257_ow(hr_str("); ", 3)));
if (((total_1792) > (((int64_t)2LL)))) { (void)(f258_ct(e_1833));
(void)(f257_ow(hr_str(" _x", 3)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(f317_arg(((int64_t)2LL), &recv_1791, &n_1787)));
(void)(({ hrv *_o6123 = &(g163); hr_fs(_o6123, hr_str("; int64_t _o", 12)); hr_fi(_o6123, p_1794); hr_fs(_o6123, hr_str(" = _v", 5)); hr_fi(_o6123, p_1794); hr_fs(_o6123, hr_str("->n; hr_resize(_v", 17)); hr_fi(_o6123, p_1794); hr_fs(_o6123, hr_str(", _k", 4)); hr_fi(_o6123, p_1794); hr_fs(_o6123, hr_str(", sizeof _x", 11)); hr_fi(_o6123, p_1794); hr_fs(_o6123, hr_str("); for (int64_t _j = _o", 23)); hr_fi(_o6123, p_1794); hr_fs(_o6123, hr_str("; _j < _k", 9)); hr_fi(_o6123, p_1794); hr_fs(_o6123, hr_str("; _j++) ((", 10)); }));
(void)(f258_ct(e_1833));
(void)(({ hrv *_o6125 = &(g163); hr_fs(_o6125, hr_str("*)_v", 4)); hr_fi(_o6125, p_1794); hr_fs(_o6125, hr_str("->b)[_j] = _x", 13)); hr_fi(_o6125, p_1794); hr_fs(_o6125, hr_str("; })", 4)); }));
return;
 }
(void)(({ hrv *_o6126 = &(g163); hr_fs(_o6126, hr_str("hr_resize(_v", 12)); hr_fi(_o6126, p_1794); hr_fs(_o6126, hr_str(", _k", 4)); hr_fi(_o6126, p_1794); hr_fs(_o6126, hr_str(", sizeof(", 9)); }));
(void)(f258_ct(e_1833));
(void)(f257_ow(hr_str(")); })", 6)));
return;
 }
if (((b_1789) == (((int64_t)26LL)))) { (void)(f258_ct(e_1833));
(void)(f257_ow(hr_str(" _x", 3)));
(void)(f291_oi(p_1794));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(f317_arg(((int64_t)1LL), &recv_1791, &n_1787)));
(void)(({ hrv *_o6135 = &(g163); hr_fs(_o6135, hr_str("; int64_t _r", 12)); hr_fi(_o6135, p_1794); hr_fs(_o6135, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o6135, p_1794); hr_fs(_o6135, hr_str("->n; _j++) if (", 15)); }));
(void)(f327_heq_val_r(e_1833, p_1794));
(void)(({ hrv *_o6137 = &(g163); hr_fs(_o6137, hr_str(") { _r", 6)); hr_fi(_o6137, p_1794); hr_fs(_o6137, hr_str(" = _j; break; } _r", 18)); hr_fi(_o6137, p_1794); hr_fs(_o6137, hr_str("; })", 4)); }));
return;
 }
(void)(f284_gerr(n_1787, hr_str("unsupported array operation", 27)));
}
static int64_t f317_arg(int64_t i_1793, int64_t *c1791, int64_t *c1787) {
return ({ int64_t _r6139; if ((((*c1791)) >= (((int64_t)0LL)))) { _r6139 = ({ int64_t _r6140; if (((i_1793) == (((int64_t)0LL)))) { _r6140 = (*c1791);  } else { _r6140 = f90_kid((*c1787), ((int64_t)((int64_t)i_1793 - (int64_t)((int64_t)1LL))));  } _r6140; });  } else { _r6139 = f90_kid((*c1787), i_1793);  } _r6139; });
}
static void f318_gfmt(hsl o_1797, int64_t n_1798, int64_t t_1799, bool top_1800) {
int64_t d_1801 = f179_deref(t_1799); 
int64_t k_1802 = ((int64_t)(((*({ hrv *_t6144 = &(g543); int64_t _i6144 = d_1801; (S1*)_t6144->b + hr_ix(_i6144, _t6144->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:368"); }))).k_)); 
if ((((k_1802) == (((int64_t)18LL))) || f164_is_byte_arr(d_1801))) { if (top_1800) { (void)(f257_ow(hr_str("hr_fs(", 6)));
 } else { (void)(f257_ow(hr_str("hr_fq(", 6)));
 }
(void)(f257_ow(o_1797));
(void)(f257_ow(hr_str(", ", 2)));
if (((((*({ hrv *_t6150 = &(g543); int64_t _i6150 = f141_at(n_1798); (S1*)_t6150->b + hr_ix(_i6150, _t6150->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:369"); }))).k_) == (((uint8_t)18LL)))) { (void)(f286_gx(n_1798));
 } else { (void)(f288_gas(n_1798));
 }
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if (((k_1802) == (((int64_t)3LL)))) { (void)(f257_ow(({ hsl _r6156; if (f153_is_signed(d_1801)) { _r6156 = hr_str("hr_fi(", 6);  } else { _r6156 = hr_str("hr_fu(", 6);  } _r6156; })));
(void)(f257_ow(o_1797));
(void)(f257_ow(hr_str(", ", 2)));
if (((d_1801) != (t_1799))) { (void)(f257_ow(hr_str("*", 1)));
 }
(void)(f286_gx(n_1798));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if (((k_1802) == (((int64_t)12LL)))) { (void)(f257_ow(hr_str("hr_fi(", 6)));
(void)(f257_ow(o_1797));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f286_gx(n_1798));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if (((k_1802) == (((int64_t)4LL)))) { (void)(f257_ow(({ hsl _r6169; if (((((*({ hrv *_t6170 = &(g543); int64_t _i6170 = d_1801; (S1*)_t6170->b + hr_ix(_i6170, _t6170->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:372"); }))).s_) == (((uint8_t)4LL)))) { _r6169 = hr_str("hr_ff(", 6);  } else { _r6169 = hr_str("hr_fd(", 6);  } _r6169; })));
(void)(f257_ow(o_1797));
(void)(f257_ow(hr_str(", ", 2)));
if (((d_1801) != (t_1799))) { (void)(f257_ow(hr_str("*", 1)));
 }
(void)(f286_gx(n_1798));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if (((k_1802) == (((int64_t)13LL)))) { (void)(f257_ow(hr_str("hr_fd(", 6)));
(void)(f257_ow(o_1797));
(void)(f257_ow(hr_str(", ", 2)));
(void)(f286_gx(n_1798));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
if (((k_1802) == (((int64_t)2LL)))) { (void)(f257_ow(hr_str("hr_fc(", 6)));
(void)(f257_ow(o_1797));
(void)(f257_ow(hr_str(", (", 3)));
if (((d_1801) != (t_1799))) { (void)(f257_ow(hr_str("*", 1)));
 }
(void)(f286_gx(n_1798));
(void)(f257_ow(hr_str(") \077 \"true\" : \"false\")", 21)));
return;
 }
(void)(f257_ow(hr_str("hf", 2)));
(void)(f291_oi(d_1801));
(void)(f257_ow(hr_str("(", 1)));
(void)(f257_ow(o_1797));
(void)(f257_ow(hr_str(", ", 2)));
if (((d_1801) != (t_1799))) { (void)(f257_ow(hr_str("*", 1)));
 }
if ((((((k_1802) == (((int64_t)8LL))) && (!(f279_is_fix(d_1801)))) && (!(f280_is_lim(d_1801)))) || ((k_1802) == (((int64_t)9LL))))) { (void)(f289_gsl(n_1798, t_1799));
 } else { (void)(f286_gx(n_1798));
 }
(void)(f257_ow(hr_str(")", 1)));
(void)(f296_gen_hf(d_1801));
}
static void f319_grecv_ptr(int64_t r_1807) {
int64_t t_1808 = f141_at(r_1807); 
if (((((*({ hrv *_t6200 = &(g543); int64_t _i6200 = t_1808; (S1*)_t6200->b + hr_ix(_i6200, _t6200->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:623"); }))).k_) == (((uint8_t)10LL)))) { (void)(f272_gx0(r_1807));
return;
 }
if (f269_is_place(r_1807)) { (void)(f257_ow(hr_str("&(", 2)));
(void)(f272_gx0(r_1807));
(void)(f257_ow(hr_str(")", 1)));
return;
 }
int64_t k_1809 = f270_tmp(t_1808, f265_is_res(t_1808)); 
(void)(f257_ow(hr_str("&(", 2)));
(void)(f271_ot(k_1809));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f266_gxo(r_1807));
(void)(f257_ow(hr_str(")", 1)));
}
static void f320_esz(int64_t t_1821) {
(void)(f257_ow(hr_str("sizeof(", 7)));
(void)(f258_ct(t_1821));
(void)(f257_ow(hr_str(")", 1)));
}
static void f321_gaddr(int64_t n_1825) {
if (f269_is_place(n_1825)) { (void)(f257_ow(hr_str("(&(", 3)));
(void)(f272_gx0(n_1825));
(void)(f257_ow(hr_str("))", 2)));
return;
 }
int64_t t_1826 = f141_at(n_1825); 
int64_t k_1827 = f270_tmp(t_1826, f265_is_res(t_1826)); 
(void)(f257_ow(hr_str("(&(", 3)));
(void)(f271_ot(k_1827));
(void)(f257_ow(hr_str(" = (", 4)));
(void)(f266_gxo(n_1825));
(void)(f257_ow(hr_str(")))", 3)));
}
static void f322_heq_val_o(int64_t e_1834, int64_t p_1835) {
L100 a_1836 = ({ L100 _t6228; memset(&_t6228, 0, sizeof _t6228); _t6228.n = 0; _t6228; }); 
L100 b_1837 = ({ L100 _t6229; memset(&_t6229, 0, sizeof _t6229); _t6229.n = 0; _t6229; }); 
(void)(({ L100 *_l6230 = &(a_1836); hrv _o6230 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6230, hr_str("_v", 2)); hr_fi(&_o6230, p_1835); hr_fs(&_o6230, hr_str("->e[_j]", 7)); if (_l6230->n + _o6230.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:689"); memcpy(_l6230->e + _l6230->n, _o6230.b, (size_t)_o6230.n); _l6230->n += _o6230.n; }));
(void)(({ L100 *_l6231 = &(b_1837); hrv _o6231 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6231, hr_str("_x", 2)); hr_fi(&_o6231, p_1835); if (_l6231->n + _o6231.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:689"); memcpy(_l6231->e + _l6231->n, _o6231.b, (size_t)_o6231.n); _l6231->n += _o6231.n; }));
(void)(f323_heq_o(e_1834, ({ hsl _t6233 = ({ L100 *_t6234 = &(a_1836); (hsl){ (uint8_t*)_t6234->e, _t6234->n }; }); int64_t _l6233 = 0, _h6233 = _t6233.n; if (_l6233 < 0 || _h6233 < _l6233 || _h6233 > _t6233.n) hr_slerr(_l6233, _h6233, _t6233.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:689"); (hsl){ _t6233.p + _l6233 * (int64_t)sizeof(uint8_t), _h6233 - _l6233 }; }), ({ hsl _t6235 = ({ L100 *_t6236 = &(b_1837); (hsl){ (uint8_t*)_t6236->e, _t6236->n }; }); int64_t _l6235 = 0, _h6235 = _t6235.n; if (_l6235 < 0 || _h6235 < _l6235 || _h6235 > _t6235.n) hr_slerr(_l6235, _h6235, _t6235.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:689"); (hsl){ _t6235.p + _l6235 * (int64_t)sizeof(uint8_t), _h6235 - _l6235 }; })));
}
static void f323_heq_o(int64_t e_1838, hsl a_1839, hsl b_1840) {
(void)(f324_heq_pre(e_1838));
int64_t s0_1844 = (g169).n; 
(void)(f300_heq_val(e_1838, a_1839, b_1840));
(void)(({ hrv *_v6239 = &(g163); hsl _s6239 = ({ hsl _t6240 = hr_sl(g169); int64_t _l6240 = s0_1844, _h6240 = _t6240.n; if (_l6240 < 0 || _h6240 < _l6240 || _h6240 > _t6240.n) hr_slerr(_l6240, _h6240, _t6240.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:686"); (hsl){ _t6240.p + _l6240 * (int64_t)sizeof(uint8_t), _h6240 - _l6240 }; }); hr_append(_v6239, _s6239.p, _s6239.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6241 = &(g169); int64_t _k6241 = s0_1844; if (_k6241 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:686"); hr_resize(_v6241, _k6241, sizeof(uint8_t)); }));
}
static void f324_heq_pre(int64_t t_1841) {
if ((!(f325_scalar_ty(t_1841)))) { (void)(f292_gen_heq(t_1841));
 }
}
static bool f325_scalar_ty(int64_t t_1842) {
int64_t k_1843 = ((int64_t)(((*({ hrv *_t6244 = &(g543); int64_t _i6244 = t_1842; (S1*)_t6244->b + hr_ix(_i6244, _t6244->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:687"); }))).k_)); 
return (((((k_1843) == (((int64_t)3LL))) || ((k_1843) == (((int64_t)4LL)))) || ((k_1843) == (((int64_t)2LL)))) || ((k_1843) == (((int64_t)10LL))));
}
static void f326_heq_val_s(int64_t e_1845, int64_t p_1846) {
L98 a_1847 = ({ L98 _t6245; memset(&_t6245, 0, sizeof _t6245); _t6245.n = 0; _t6245; }); 
L100 b_1848 = ({ L100 _t6246; memset(&_t6246, 0, sizeof _t6246); _t6246.n = 0; _t6246; }); 
(void)(({ L98 *_v6247 = &(a_1847); hsl _s6247 = hr_str("((", 2); if (_v6247->n + _s6247.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:690"); memmove(_v6247->e + _v6247->n, _s6247.p, (size_t)_s6247.n * sizeof _v6247->e[0]); _v6247->n += _s6247.n; }));
(void)(({ L98 *_v6248 = &(a_1847); hsl _s6248 = f261_cn(e_1845); if (_v6248->n + _s6248.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:690"); memmove(_v6248->e + _v6248->n, _s6248.p, (size_t)_s6248.n * sizeof _v6248->e[0]); _v6248->n += _s6248.n; }));
(void)(({ L98 *_l6250 = &(a_1847); hrv _o6250 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6250, hr_str("*)_v", 4)); hr_fi(&_o6250, p_1846); hr_fs(&_o6250, hr_str(".p)[_j]", 7)); if (_l6250->n + _o6250.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:690"); memcpy(_l6250->e + _l6250->n, _o6250.b, (size_t)_o6250.n); _l6250->n += _o6250.n; }));
(void)(({ L100 *_l6251 = &(b_1848); hrv _o6251 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6251, hr_str("_x", 2)); hr_fi(&_o6251, p_1846); if (_l6251->n + _o6251.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:690"); memcpy(_l6251->e + _l6251->n, _o6251.b, (size_t)_o6251.n); _l6251->n += _o6251.n; }));
(void)(f323_heq_o(e_1845, ({ hsl _t6253 = ({ L98 *_t6254 = &(a_1847); (hsl){ (uint8_t*)_t6254->e, _t6254->n }; }); int64_t _l6253 = 0, _h6253 = _t6253.n; if (_l6253 < 0 || _h6253 < _l6253 || _h6253 > _t6253.n) hr_slerr(_l6253, _h6253, _t6253.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:690"); (hsl){ _t6253.p + _l6253 * (int64_t)sizeof(uint8_t), _h6253 - _l6253 }; }), ({ hsl _t6255 = ({ L100 *_t6256 = &(b_1848); (hsl){ (uint8_t*)_t6256->e, _t6256->n }; }); int64_t _l6255 = 0, _h6255 = _t6255.n; if (_l6255 < 0 || _h6255 < _l6255 || _h6255 > _t6255.n) hr_slerr(_l6255, _h6255, _t6255.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:690"); (hsl){ _t6255.p + _l6255 * (int64_t)sizeof(uint8_t), _h6255 - _l6255 }; })));
}
static void f327_heq_val_r(int64_t e_1849, int64_t p_1850) {
L98 a_1851 = ({ L98 _t6257; memset(&_t6257, 0, sizeof _t6257); _t6257.n = 0; _t6257; }); 
L100 b_1852 = ({ L100 _t6258; memset(&_t6258, 0, sizeof _t6258); _t6258.n = 0; _t6258; }); 
(void)(({ L98 *_v6259 = &(a_1851); hsl _s6259 = hr_str("((", 2); if (_v6259->n + _s6259.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:691"); memmove(_v6259->e + _v6259->n, _s6259.p, (size_t)_s6259.n * sizeof _v6259->e[0]); _v6259->n += _s6259.n; }));
(void)(({ L98 *_v6260 = &(a_1851); hsl _s6260 = f261_cn(e_1849); if (_v6260->n + _s6260.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:691"); memmove(_v6260->e + _v6260->n, _s6260.p, (size_t)_s6260.n * sizeof _v6260->e[0]); _v6260->n += _s6260.n; }));
(void)(({ L98 *_l6262 = &(a_1851); hrv _o6262 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6262, hr_str("*)_v", 4)); hr_fi(&_o6262, p_1850); hr_fs(&_o6262, hr_str("->b)[_j]", 8)); if (_l6262->n + _o6262.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:691"); memcpy(_l6262->e + _l6262->n, _o6262.b, (size_t)_o6262.n); _l6262->n += _o6262.n; }));
(void)(({ L100 *_l6263 = &(b_1852); hrv _o6263 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o6263, hr_str("_x", 2)); hr_fi(&_o6263, p_1850); if (_l6263->n + _o6263.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:691"); memcpy(_l6263->e + _l6263->n, _o6263.b, (size_t)_o6263.n); _l6263->n += _o6263.n; }));
(void)(f323_heq_o(e_1849, ({ hsl _t6265 = ({ L98 *_t6266 = &(a_1851); (hsl){ (uint8_t*)_t6266->e, _t6266->n }; }); int64_t _l6265 = 0, _h6265 = _t6265.n; if (_l6265 < 0 || _h6265 < _l6265 || _h6265 > _t6265.n) hr_slerr(_l6265, _h6265, _t6265.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:691"); (hsl){ _t6265.p + _l6265 * (int64_t)sizeof(uint8_t), _h6265 - _l6265 }; }), ({ hsl _t6267 = ({ L100 *_t6268 = &(b_1852); (hsl){ (uint8_t*)_t6268->e, _t6268->n }; }); int64_t _l6267 = 0, _h6267 = _t6267.n; if (_l6267 < 0 || _h6267 < _l6267 || _h6267 > _t6267.n) hr_slerr(_l6267, _h6267, _t6267.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:691"); (hsl){ _t6267.p + _l6267 * (int64_t)sizeof(uint8_t), _h6267 - _l6267 }; })));
}
static void f328_gblkcall(int64_t n_1853) {
int64_t bi_1854 = f157_rv(n_1853); 
int64_t fv_1855 = ((int64_t)(((*({ hrv *_t6270 = &(g380); int64_t _i6270 = bi_1854; (S6*)_t6270->b + hr_ix(_i6270, _t6270->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:603"); }))).node_)); 
int64_t sa_1856 = g393; 
(void)(f257_ow(hr_str("({ ", 3)));
int64_t np_1857 = ((int64_t)(((*({ hrv *_t6272 = &(g696); int64_t _i6272 = fv_1855; (S4*)_t6272->b + hr_ix(_i6272, _t6272->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:606"); }))).n_)); 
int64_t na_1858 = ((int64_t)(((*({ hrv *_t6273 = &(g696); int64_t _i6273 = n_1853; (S4*)_t6273->b + hr_ix(_i6273, _t6273->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:607"); }))).n_)); 
if (((((uint16_t)((uint64_t)((*({ hrv *_t6274 = &(g696); int64_t _i6274 = fv_1855; (S4*)_t6274->b + hr_ix(_i6274, _t6274->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:608"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { int64_t _e6276 = np_1857; for (int64_t _k6276 = 0; _k6276 < _e6276; _k6276++) { int64_t j_1859 = (int64_t)_k6276; int64_t p_1860 = f90_kid(fv_1855, j_1859); 
g393 = bi_1854;
int64_t v_1861 = f157_rv(p_1860); 
g393 = sa_1856;
if (((j_1859) < (na_1858))) { (void)(f258_ct(((int64_t)(((*({ hrv *_t6280 = &(g381); int64_t _i6280 = v_1861; (S12*)_t6280->b + hr_ix(_i6280, _t6280->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:609"); }))).ty_))));
(void)(f257_ow(hr_str(" ", 1)));
(void)(f283_lv_name(v_1861));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(f90_kid(n_1853, j_1859)));
(void)(f257_ow(hr_str("; ", 2)));
 }
 } } _bk6275:; 
 } else { if (((na_1858) >= (((int64_t)1LL)))) { g393 = bi_1854;
int64_t v_1862 = f157_rv(fv_1855); 
g393 = sa_1856;
if (((v_1862) >= (((int64_t)0LL)))) { (void)(f258_ct(((int64_t)(((*({ hrv *_t6289 = &(g381); int64_t _i6289 = v_1862; (S12*)_t6289->b + hr_ix(_i6289, _t6289->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:611"); }))).ty_))));
(void)(f257_ow(hr_str(" ", 1)));
(void)(f283_lv_name(v_1862));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(f90_kid(n_1853, ((int64_t)0LL))));
(void)(f257_ow(hr_str("; ", 2)));
 } else { (void)(f257_ow(hr_str("(void)(", 7)));
(void)(f286_gx(f90_kid(n_1853, ((int64_t)0LL))));
(void)(f257_ow(hr_str("); ", 3)));
 }
 }
 }
g393 = bi_1854;
int64_t body_1863 = ((int64_t)(((*({ hrv *_t6300 = &(g696); int64_t _i6300 = fv_1855; (S4*)_t6300->b + hr_ix(_i6300, _t6300->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:614"); }))).a_)); 
{ int32_t _e6302 = ((*({ hrv *_t6303 = &(g696); int64_t _i6303 = body_1863; (S4*)_t6303->b + hr_ix(_i6303, _t6303->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:615"); }))).n_; for (int32_t _k6302 = 0; _k6302 < _e6302; _k6302++) { int32_t i_1864 = (int32_t)_k6302; (void)(f329_gstmt(f90_kid(body_1863, ((int64_t)(i_1864)))));
 } } _bk6301:; 
int64_t tl_1995 = ((int64_t)(((*({ hrv *_t6306 = &(g696); int64_t _i6306 = body_1863; (S4*)_t6306->b + hr_ix(_i6306, _t6306->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:616"); }))).a_)); 
if (((tl_1995) >= (((int64_t)0LL)))) { if ((((((int64_t)(((*({ hrv *_t6307 = &(g380); int64_t _i6307 = bi_1854; (S6*)_t6307->b + hr_ix(_i6307, _t6307->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:617"); }))).ret_))) != (g550)) && (!(f209_ends(tl_1995))))) { (void)(f286_gx(tl_1995));
(void)(f257_ow(hr_str("; ", 2)));
 } else { (void)(f329_gstmt(tl_1995));
 }
 }
g393 = sa_1856;
(void)(f257_ow(hr_str(" })", 3)));
}
static void f329_gstmt(int64_t n_1865) {
if (((n_1865) < (((int64_t)0LL)))) { return;
 }
int64_t sp_1866 = (g163).n; 
int64_t td_1867 = (g176).n; 
S4 x_1868 = (*({ hrv *_t6313 = &(g696); int64_t _i6313 = n_1865; (S4*)_t6313->b + hr_ix(_i6313, _t6313->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1007"); })); 
int64_t k_1869 = ((int64_t)((x_1868).k_)); 
bool decl_1870 = ((k_1869) == (((int64_t)33LL))); 
if (((k_1869) == (((int64_t)33LL)))) { (void)(f330_gvdecl(n_1865));
 } else { (void)(f332_gstmt1(n_1865));
 }
(void)(f257_ow(hr_str("\012", 1)));
if ((((g176).n) > (td_1867))) { (void)(({ hrv *_v6317 = &(g177); _v6317->n = 0; }));
(void)(({ hrv *_v6318 = &(g177); hsl _s6318 = ({ hsl _t6319 = hr_sl(g163); int64_t _l6319 = sp_1866, _h6319 = _t6319.n; if (_l6319 < 0 || _h6319 < _l6319 || _h6319 > _t6319.n) hr_slerr(_l6319, _h6319, _t6319.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1013"); (hsl){ _t6319.p + _l6319 * (int64_t)sizeof(uint8_t), _h6319 - _l6319 }; }); hr_append(_v6318, _s6318.p, _s6318.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6320 = &(g163); int64_t _k6320 = sp_1866; if (_k6320 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1013"); hr_resize(_v6320, _k6320, sizeof(uint8_t)); }));
if ((!(decl_1870))) { (void)(f257_ow(hr_str("{ ", 2)));
 }
(void)(({ hrv *_v6322 = &(g163); hsl _s6322 = ({ hsl _t6323 = hr_sl(g176); int64_t _l6323 = td_1867, _h6323 = _t6323.n; if (_l6323 < 0 || _h6323 < _l6323 || _h6323 > _t6323.n) hr_slerr(_l6323, _h6323, _t6323.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1015"); (hsl){ _t6323.p + _l6323 * (int64_t)sizeof(uint8_t), _h6323 - _l6323 }; }); hr_append(_v6322, _s6322.p, _s6322.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6324 = &(g176); int64_t _k6324 = td_1867; if (_k6324 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1015"); hr_resize(_v6324, _k6324, sizeof(uint8_t)); }));
(void)(({ hrv *_v6325 = &(g163); hsl _s6325 = ({ hsl _t6326 = hr_sl(g177); int64_t _l6326 = 0, _h6326 = _t6326.n; if (_l6326 < 0 || _h6326 < _l6326 || _h6326 > _t6326.n) hr_slerr(_l6326, _h6326, _t6326.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1016"); (hsl){ _t6326.p + _l6326 * (int64_t)sizeof(uint8_t), _h6326 - _l6326 }; }); hr_append(_v6325, _s6325.p, _s6325.n, sizeof(uint8_t)); }));
if ((!(decl_1870))) { (void)(f257_ow(hr_str("}\012", 2)));
 }
 }
}
static void f330_gvdecl(int64_t n_1871) {
S4 x_1872 = (*({ hrv *_t6328 = &(g696); int64_t _i6328 = n_1871; (S4*)_t6328->b + hr_ix(_i6328, _t6328->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:895"); })); 
if ((((x_1872).n_) > (((int32_t)1LL)))) { if (((f217_ax(n_1871)) == (((int64_t)1LL)))) { L89 ids_1873 = ({ L89 _t6330; memset(&_t6330, 0, sizeof _t6330); _t6330.n = 0; _t6330; }); 
{ int32_t _e6332 = (x_1872).n_; for (int32_t _k6332 = 0; _k6332 < _e6332; _k6332++) { int32_t i_1874 = (int32_t)_k6332; int64_t iv_1875 = f90_kid(((int64_t)((x_1872).b_)), ((int64_t)(i_1874))); 
int64_t p_1876 = f290_nt(); 
(void)(({ L89 *_v6335 = &(ids_1873); int32_t _x6335 = ((int32_t)(p_1876)); if (_v6335->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:899"); _v6335->e[_v6335->n] = _x6335; &_v6335->e[_v6335->n++]; }));
(void)(f258_ct(f276_fin(iv_1875)));
(void)(f257_ow(hr_str(" _t", 3)));
(void)(f291_oi(p_1876));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(iv_1875));
(void)(f257_ow(hr_str("; ", 2)));
 } } _bk6331:; 
int64_t v0_1877 = f157_rv(n_1871); 
{ int32_t _e6345 = (x_1872).n_; for (int32_t _k6345 = 0; _k6345 < _e6345; _k6345++) { int32_t i_1878 = (int32_t)_k6345; (void)(f331_decl_lv(((int64_t)((int64_t)v0_1877 + (int64_t)((int64_t)(i_1878))))));
(void)(({ hrv *_o6347 = &(g163); hr_fs(_o6347, hr_str(" = _t", 5)); hr_fi(_o6347, (*({ L89 *_t6348 = &(ids_1873); int64_t _i6348 = i_1878; _t6348->e + hr_ix(_i6348, _t6348->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:901"); }))); hr_fs(_o6347, hr_str("; ", 2)); }));
 } } _bk6344:; 
return;
 }
int64_t init_1881 = f90_kid(((int64_t)((x_1872).b_)), ((int64_t)0LL)); 
int64_t p_1882 = f290_nt(); 
(void)(f258_ct(f141_at(init_1881)));
(void)(f257_ow(hr_str(" _t", 3)));
(void)(f291_oi(p_1882));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(init_1881));
(void)(f257_ow(hr_str("; ", 2)));
int64_t v0_1883 = f157_rv(n_1871); 
{ int32_t _e6360 = (x_1872).n_; for (int32_t _k6360 = 0; _k6360 < _e6360; _k6360++) { int32_t i_1884 = (int32_t)_k6360; (void)(f331_decl_lv(((int64_t)((int64_t)v0_1883 + (int64_t)((int64_t)(i_1884))))));
(void)(({ hrv *_o6362 = &(g163); hr_fs(_o6362, hr_str(" = _t", 5)); hr_fi(_o6362, p_1882); hr_fs(_o6362, hr_str(".r", 2)); hr_fi(_o6362, i_1884); hr_fs(_o6362, hr_str("; ", 2)); }));
 } } _bk6359:; 
return;
 }
int64_t v_1885 = f157_rv(n_1871); 
int64_t t_1886 = ((int64_t)(((*({ hrv *_t6364 = &(g381); int64_t _i6364 = v_1885; (S12*)_t6364->b + hr_ix(_i6364, _t6364->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:912"); }))).ty_)); 
(void)(f331_decl_lv(v_1885));
(void)(f257_ow(hr_str(" = ", 3)));
if ((((x_1872).b_) < (((int32_t)0LL)))) { (void)(f257_ow(hr_str("{0}; ", 5)));
return;
 }
int64_t init_1887 = f90_kid(((int64_t)((x_1872).b_)), ((int64_t)0LL)); 
if (((((*({ hrv *_t6369 = &(g543); int64_t _i6369 = t_1886; (S1*)_t6369->b + hr_ix(_i6369, _t6369->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:917"); }))).k_) == (((uint8_t)10LL)))) { int64_t it_1888 = f276_fin(init_1887); 
if ((((((*({ hrv *_t6371 = &(g543); int64_t _i6371 = it_1888; (S1*)_t6371->b + hr_ix(_i6371, _t6371->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:917"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t6372 = &(g543); int64_t _i6372 = it_1888; (S1*)_t6372->b + hr_ix(_i6372, _t6372->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:917"); }))).k_) == (((uint8_t)11LL))))) { (void)(f286_gx(init_1887));
 } else { (void)(f321_gaddr(init_1887));
 }
(void)(f257_ow(hr_str("; ", 2)));
return;
 }
if (f265_is_res(t_1886)) { (void)(f266_gxo(init_1887));
(void)(f257_ow(hr_str("; ", 2)));
return;
 }
int64_t it_1889 = f141_at(init_1887); 
if (((((*({ hrv *_t6380 = &(g543); int64_t _i6380 = it_1889; (S1*)_t6380->b + hr_ix(_i6380, _t6380->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:920"); }))).k_) == (((uint8_t)14LL)))) { (void)(f286_gx(init_1887));
(void)(({ hrv *_o6382 = &(g163); hr_fs(_o6382, hr_str(".r0; ", 5)); }));
return;
 }
(void)(f286_gx(init_1887));
(void)(f257_ow(hr_str("; ", 2)));
}
static void f331_decl_lv(int64_t v_1879) {
int64_t t_1880 = ((int64_t)(((*({ hrv *_t6385 = &(g381); int64_t _i6385 = v_1879; (S12*)_t6385->b + hr_ix(_i6385, _t6385->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:924"); }))).ty_)); 
(void)(f258_ct(t_1880));
(void)(f257_ow(hr_str(" ", 1)));
if (f282_lv_isptr(v_1879)) { (void)(f257_ow(hr_str("*", 1)));
 }
(void)(f283_lv_name(v_1879));
if ((f265_is_res(t_1880) && (!(f282_lv_isptr(v_1879))))) { (void)(f257_ow(hr_str(" __attribute__((cleanup(hr_rdrop)))", 35)));
 }
}
static void f332_gstmt1(int64_t n_1890) {
S4 x_1891 = (*({ hrv *_t6394 = &(g696); int64_t _i6394 = n_1890; (S4*)_t6394->b + hr_ix(_i6394, _t6394->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1021"); })); 
int64_t k_1892 = ((int64_t)((x_1891).k_)); 
if (((k_1892) == (((int64_t)34LL)))) { (void)(f333_gassign(n_1890));
return;
 }
if (((k_1892) == (((int64_t)35LL)))) { int64_t a_1907 = ((int64_t)((x_1891).a_)); 
int64_t tt_1908 = f141_at(a_1907); 
if (((((*({ hrv *_t6397 = &(g543); int64_t _i6397 = tt_1908; (S1*)_t6397->b + hr_ix(_i6397, _t6397->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1024"); }))).k_) == (((uint8_t)10LL)))) { (void)(f257_ow(hr_str("(*", 2)));
(void)(f272_gx0(a_1907));
(void)(f257_ow(hr_str(")", 1)));
 } else { (void)(f286_gx(a_1907));
 }
(void)(f257_ow(({ hsl _r6403; if (((((int64_t)((x_1891).op_))) == (((int64_t)34LL)))) { _r6403 = hr_str("++;", 3);  } else { _r6403 = hr_str("--;", 3);  } _r6403; })));
return;
 }
if (((k_1892) == (((int64_t)50LL)))) { return;
 }
if (((k_1892) == (((int64_t)19LL)))) { (void)(f335_gif(n_1890, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1892) == (((int64_t)25LL)))) { (void)(f338_gwhile(n_1890));
return;
 }
if (((k_1892) == (((int64_t)26LL)))) { (void)(f341_gloop(n_1890, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1892) == (((int64_t)27LL)))) { (void)(f342_gfor(n_1890));
return;
 }
if (((k_1892) == (((int64_t)20LL)))) { (void)(f343_gmatch(n_1890, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1892) == (((int64_t)24LL)))) { (void)(f344_geblock(n_1890, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1892) == (((int64_t)23LL)))) { (void)(f257_ow(hr_str("{ ", 2)));
(void)(f336_gblk(n_1890, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f257_ow(hr_str(" }", 2)));
return;
 }
if (((k_1892) == (((int64_t)28LL)))) { (void)(f345_gret(n_1890));
return;
 }
if (((k_1892) == (((int64_t)29LL)))) { (void)(f349_gbreak(n_1890));
return;
 }
if (((k_1892) == (((int64_t)30LL)))) { (void)(f257_ow(hr_str("continue;", 9)));
return;
 }
if (((k_1892) == (((int64_t)37LL)))) { (void)(f284_gerr(n_1890, hr_str("const for is not supported by the self-hosted compiler yet", 58)));
return;
 }
if (f350_owned(n_1890)) { (void)(f257_ow(hr_str("hr_rgive(", 9)));
(void)(f272_gx0(n_1890));
(void)(f257_ow(hr_str(");", 2)));
return;
 }
(void)(f257_ow(hr_str("(void)(", 7)));
(void)(f286_gx(n_1890));
(void)(f257_ow(hr_str(");", 2)));
}
static void f333_gassign(int64_t n_1893) {
S4 x_1894 = (*({ hrv *_t6424 = &(g696); int64_t _i6424 = n_1893; (S4*)_t6424->b + hr_ix(_i6424, _t6424->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:931"); })); 
int64_t o_1895 = ((int64_t)((x_1894).op_)); 
if (((o_1895) == (((int64_t)11LL)))) { int64_t p_1896 = f290_nt(); 
(void)(f257_ow(hr_str("{ ", 2)));
(void)(f258_ct(f141_at(((int64_t)((x_1894).b_)))));
(void)(f257_ow(hr_str(" _t", 3)));
(void)(f291_oi(p_1896));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(((int64_t)((x_1894).b_))));
(void)(f257_ow(hr_str("; ", 2)));
int64_t tl_1897 = ((int64_t)((x_1894).a_)); 
{ int32_t _e6435 = ((*({ hrv *_t6436 = &(g696); int64_t _i6436 = tl_1897; (S4*)_t6436->b + hr_ix(_i6436, _t6436->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:937"); }))).n_; for (int32_t _k6435 = 0; _k6435 < _e6435; _k6435++) { int32_t i_1898 = (int32_t)_k6435; int64_t tg_1899 = f90_kid(tl_1897, ((int64_t)(i_1898))); 
(void)(f286_gx(tg_1899));
(void)(({ hrv *_o6439 = &(g163); hr_fs(_o6439, hr_str(" = _t", 5)); hr_fi(_o6439, p_1896); hr_fs(_o6439, hr_str(".r", 2)); hr_fi(_o6439, i_1898); hr_fs(_o6439, hr_str("; ", 2)); }));
 } } _bk6434:; 
(void)(f257_ow(hr_str("}", 1)));
return;
 }
int64_t a_1900 = ((int64_t)((x_1894).a_)); 
int64_t tt_1901 = f141_at(a_1900); 
int64_t d_1902 = f179_deref(tt_1901); 
if ((((o_1895) == (((int64_t)18LL))) && ((((*({ hrv *_t6443 = &(g543); int64_t _i6443 = tt_1901; (S1*)_t6443->b + hr_ix(_i6443, _t6443->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:944"); }))).k_) == (((uint8_t)10LL))))) { int64_t b_1903 = ((int64_t)((x_1894).b_)); 
(void)(f272_gx0(a_1900));
(void)(f257_ow(hr_str(" = ", 3)));
if ((((((*({ hrv *_t6446 = &(g543); int64_t _i6446 = f276_fin(b_1903); (S1*)_t6446->b + hr_ix(_i6446, _t6446->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:947"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t6448 = &(g543); int64_t _i6448 = f276_fin(b_1903); (S1*)_t6448->b + hr_ix(_i6448, _t6448->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:947"); }))).k_) == (((uint8_t)11LL))))) { (void)(f286_gx(b_1903));
 } else { (void)(f321_gaddr(b_1903));
 }
(void)(f257_ow(hr_str(";", 1)));
return;
 }
if ((((o_1895) == (((int64_t)36LL))) || ((o_1895) == (((int64_t)18LL))))) { if (f265_is_res(d_1902)) { (void)(f257_ow(hr_str("hr_rset(", 8)));
if (((((*({ hrv *_t6455 = &(g543); int64_t _i6455 = tt_1901; (S1*)_t6455->b + hr_ix(_i6455, _t6455->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:952"); }))).k_) == (((uint8_t)10LL)))) { (void)(f272_gx0(a_1900));
 } else { (void)(f257_ow(hr_str("&(", 2)));
(void)(f286_gx(a_1900));
(void)(f257_ow(hr_str(")", 1)));
 }
(void)(f257_ow(hr_str(", ", 2)));
(void)(f266_gxo(((int64_t)((x_1894).b_))));
(void)(f257_ow(hr_str(");", 2)));
return;
 }
if ((((((((*({ hrv *_t6463 = &(g543); int64_t _i6463 = tt_1901; (S1*)_t6463->b + hr_ix(_i6463, _t6463->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:953"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t6464 = &(g543); int64_t _i6464 = f141_at(((int64_t)((x_1894).b_))); (S1*)_t6464->b + hr_ix(_i6464, _t6464->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:953"); }))).k_) != (((uint8_t)10LL)))) && ((((*({ hrv *_t6466 = &(g543); int64_t _i6466 = f276_fin(((int64_t)((x_1894).b_))); (S1*)_t6466->b + hr_ix(_i6466, _t6466->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:953"); }))).k_) != (((uint8_t)10LL)))) && ((((*({ hrv *_t6468 = &(g543); int64_t _i6468 = f141_at(((int64_t)((x_1894).b_))); (S1*)_t6468->b + hr_ix(_i6468, _t6468->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:953"); }))).k_) != (((uint8_t)11LL))))) { (void)(f257_ow(hr_str("*", 1)));
(void)(f272_gx0(a_1900));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(((int64_t)((x_1894).b_))));
(void)(f257_ow(hr_str(";", 1)));
return;
 }
if (((((*({ hrv *_t6475 = &(g696); int64_t _i6475 = a_1900; (S4*)_t6475->b + hr_ix(_i6475, _t6475->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:954"); }))).k_) == (((uint8_t)8LL)))) { (void)(f286_gx(a_1900));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(((int64_t)((x_1894).b_))));
(void)(f257_ow(hr_str(";", 1)));
return;
 }
int64_t q_1904 = f290_nt(); 
(void)(f257_ow(hr_str("{ ", 2)));
(void)(f258_ct(d_1902));
(void)(f257_ow(hr_str(" *_t", 4)));
(void)(f291_oi(q_1904));
(void)(f257_ow(hr_str(" = &(", 5)));
(void)(f286_gx(a_1900));
(void)(f257_ow(hr_str("); *_t", 6)));
(void)(f291_oi(q_1904));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(((int64_t)((x_1894).b_))));
(void)(f257_ow(hr_str("; }", 3)));
return;
 }
int64_t p_1905 = f290_nt(); 
(void)(f257_ow(hr_str("{ ", 2)));
(void)(f258_ct(d_1902));
(void)(f257_ow(hr_str(" *_t", 4)));
(void)(f291_oi(p_1905));
(void)(f257_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t6498 = &(g543); int64_t _i6498 = tt_1901; (S1*)_t6498->b + hr_ix(_i6498, _t6498->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:961"); }))).k_) == (((uint8_t)10LL)))) { (void)(f272_gx0(a_1900));
 } else { (void)(f257_ow(hr_str("&(", 2)));
(void)(f286_gx(a_1900));
(void)(f257_ow(hr_str(")", 1)));
 }
(void)(f257_ow(hr_str("; *_t", 5)));
(void)(f291_oi(p_1905));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f303_garith(f334_base_op(o_1895), d_1902, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)((x_1894).b_)), p_1905, n_1893));
(void)(f257_ow(hr_str("; }", 3)));
}
static int64_t f334_base_op(int64_t o_1906) {
if (((o_1906) == (((int64_t)26LL)))) { return ((int64_t)21LL);
 }
if (((o_1906) == (((int64_t)27LL)))) { return ((int64_t)22LL);
 }
if (((o_1906) == (((int64_t)28LL)))) { return ((int64_t)23LL);
 }
if (((o_1906) == (((int64_t)29LL)))) { return ((int64_t)24LL);
 }
if (((o_1906) == (((int64_t)30LL)))) { return ((int64_t)25LL);
 }
if (((o_1906) == (((int64_t)31LL)))) { return ((int64_t)49LL);
 }
if (((o_1906) == (((int64_t)32LL)))) { return ((int64_t)50LL);
 }
if (((o_1906) == (((int64_t)33LL)))) { return ((int64_t)51LL);
 }
if (((o_1906) == (((int64_t)45LL)))) { return ((int64_t)43LL);
 }
if (((o_1906) == (((int64_t)46LL)))) { return ((int64_t)44LL);
 }
return o_1906;
}
static void f335_gif(int64_t n_1909, int64_t res_1910) {
S4 x_1911 = (*({ hrv *_t6509 = &(g696); int64_t _i6509 = n_1909; (S4*)_t6509->b + hr_ix(_i6509, _t6509->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:778"); })); 
(void)(f257_ow(hr_str("if (", 4)));
int64_t m_1912 = f217_ax(n_1909); 
if ((((m_1912) != (((int64_t)0LL))) && ((m_1912) != (((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))))) { (void)(f257_ow(hr_str("(", 1)));
(void)(f272_gx0(((int64_t)((x_1911).a_))));
(void)(f257_ow(hr_str(") != 0", 6)));
 } else { (void)(f286_gx(((int64_t)((x_1911).a_))));
 }
(void)(f257_ow(hr_str(") { ", 4)));
if (((m_1912) > (((int64_t)1LL)))) { int64_t v_1913 = ((int64_t)((int64_t)m_1912 & (int64_t)((int64_t)((int64_t)((int64_t)((((int64_t)1LL)) << ((((int64_t)30LL)) & 63))) - (int64_t)((int64_t)1LL))))); 
(void)(f258_ct(((int64_t)(((*({ hrv *_t6518 = &(g381); int64_t _i6518 = v_1913; (S12*)_t6518->b + hr_ix(_i6518, _t6518->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:783"); }))).ty_))));
(void)(f257_ow(hr_str(" *", 2)));
(void)(f283_lv_name(v_1913));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f272_gx0(((int64_t)((x_1911).a_))));
(void)(f257_ow(hr_str("; ", 2)));
 }
(void)(f336_gblk(((int64_t)((x_1911).b_)), res_1910, false));
(void)(f257_ow(hr_str(" }", 2)));
if ((((x_1911).c_) >= (((int32_t)0LL)))) { (void)(f257_ow(hr_str(" else { ", 8)));
if (((((*({ hrv *_t6527 = &(g696); int64_t _i6527 = (x_1911).c_; (S4*)_t6527->b + hr_ix(_i6527, _t6527->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:786"); }))).k_) == (((uint8_t)19LL)))) { (void)(f335_gif(((int64_t)((x_1911).c_)), res_1910));
 } else { (void)(f336_gblk(((int64_t)((x_1911).c_)), res_1910, false));
 }
(void)(f257_ow(hr_str(" }", 2)));
 }
}
static void f336_gblk(int64_t b_1914, int64_t res_1915, bool val_1916) {
S4 x_1917 = (*({ hrv *_t6531 = &(g696); int64_t _i6531 = b_1914; (S4*)_t6531->b + hr_ix(_i6531, _t6531->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:767"); })); 
if (((((int64_t)((x_1917).k_))) != (((int64_t)23LL)))) { if (((res_1915) >= (((int64_t)0LL)))) { (void)(f337_gtail(b_1914, res_1915));
 } else { if (val_1916) { (void)(f286_gx(b_1914));
(void)(f257_ow(hr_str(";", 1)));
 } else { (void)(f329_gstmt(b_1914));
 }
 }
return;
 }
{ int32_t _e6537 = (x_1917).n_; for (int32_t _k6537 = 0; _k6537 < _e6537; _k6537++) { int32_t i_1920 = (int32_t)_k6537; (void)(f329_gstmt(f90_kid(b_1914, ((int64_t)(i_1920)))));
 } } _bk6536:; 
if ((((x_1917).a_) >= (((int32_t)0LL)))) { int64_t tl_1921 = ((int64_t)((x_1917).a_)); 
if (((res_1915) >= (((int64_t)0LL)))) { (void)(f337_gtail(tl_1921, res_1915));
return;
 }
if (((val_1916 && ((f141_at(tl_1921)) != (g550))) && (!(f209_ends(tl_1921))))) { (void)(f286_gx(tl_1921));
(void)(f257_ow(hr_str("; ", 2)));
return;
 }
(void)(f329_gstmt(tl_1921));
 }
}
static void f337_gtail(int64_t tl_1918, int64_t res_1919) {
if ((((res_1919) >= (((int64_t)0LL))) && (!(f209_ends(tl_1918))))) { (void)(f257_ow(hr_str("_r", 2)));
(void)(f291_oi(res_1919));
(void)(f257_ow(hr_str(" = ", 3)));
if (f265_is_res(f276_fin(tl_1918))) { (void)(f266_gxo(tl_1918));
 } else { (void)(f286_gx(tl_1918));
 }
(void)(f257_ow(hr_str("; ", 2)));
return;
 }
(void)(f329_gstmt(tl_1918));
}
static void f338_gwhile(int64_t n_1922) {
S4 x_1923 = (*({ hrv *_t6556 = &(g696); int64_t _i6556 = n_1922; (S4*)_t6556->b + hr_ix(_i6556, _t6556->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:801"); })); 
int64_t l_1926 = f339_lbl_push(((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f257_ow(hr_str("while (", 7)));
if (((f217_ax(n_1922)) == (((int64_t)1LL)))) { (void)(f257_ow(hr_str("(", 1)));
(void)(f272_gx0(((int64_t)((x_1923).a_))));
(void)(f257_ow(hr_str(") != 0", 6)));
 } else { (void)(f286_gx(((int64_t)((x_1923).a_))));
 }
(void)(f257_ow(hr_str(") { ", 4)));
(void)(f336_gblk(((int64_t)((x_1923).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f257_ow(hr_str(" }", 2)));
(void)(f340_lbl_pop(l_1926));
}
static int64_t f339_lbl_push(int64_t res_1924) {
int64_t l_1925 = f290_nt(); 
(void)(({ hrv *_v6569 = &(g180); int32_t _x6569 = ((int32_t)(l_1925)); int32_t *_p6569 = (int32_t*)hr_grow(_v6569, 1, sizeof _x6569); *_p6569 = _x6569; _p6569; }));
(void)(({ hrv *_v6570 = &(g181); int32_t _x6570 = ((int32_t)(res_1924)); int32_t *_p6570 = (int32_t*)hr_grow(_v6570, 1, sizeof _x6570); *_p6570 = _x6570; _p6570; }));
return l_1925;
}
static void f340_lbl_pop(int64_t l_1927) {
(void)(({ hrv *_v6571 = &(g180); if (!_v6571->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:789"); ((int32_t*)_v6571->b)[--_v6571->n]; }));
(void)(({ hrv *_v6572 = &(g181); if (!_v6572->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:789"); ((int32_t*)_v6572->b)[--_v6572->n]; }));
(void)(({ hrv *_o6573 = &(g163); hr_fs(_o6573, hr_str(" _bk", 4)); hr_fi(_o6573, l_1927); hr_fs(_o6573, hr_str(":; ", 3)); }));
}
static void f341_gloop(int64_t n_1928, int64_t res_1929) {
int64_t l_1930 = f339_lbl_push(res_1929); 
(void)(f257_ow(hr_str("for (;;) { ", 11)));
(void)(f336_gblk(((int64_t)(((*({ hrv *_t6577 = &(g696); int64_t _i6577 = n_1928; (S4*)_t6577->b + hr_ix(_i6577, _t6577->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:792"); }))).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f257_ow(hr_str(" }", 2)));
(void)(f340_lbl_pop(l_1930));
}
static void f342_gfor(int64_t n_1931) {
S4 x_1932 = (*({ hrv *_t6580 = &(g696); int64_t _i6580 = n_1931; (S4*)_t6580->b + hr_ix(_i6580, _t6580->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:809"); })); 
int64_t v_1933 = f157_rv(n_1931); 
int64_t m_1934 = f217_ax(n_1931); 
int64_t iv_1935 = ({ int64_t _r6583; if ((((x_1932).c_) >= (((int32_t)0LL)))) { _r6583 = ((int64_t)((m_1934) >> ((((int64_t)2LL)) & 63)));  } else { _r6583 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r6583; }); 
int64_t l_1936 = f339_lbl_push(((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t p_1937 = f290_nt(); 
int64_t et_1938 = ((int64_t)(((*({ hrv *_t6586 = &(g381); int64_t _i6586 = v_1933; (S12*)_t6586->b + hr_ix(_i6586, _t6586->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:815"); }))).ty_)); 
if (((((int64_t)((int64_t)m_1934 & (int64_t)((int64_t)3LL)))) == (((int64_t)0LL)))) { int64_t rt0_1939 = f276_fin(({ int64_t _r6588; if ((((x_1932).b_) >= (((int32_t)0LL)))) { _r6588 = ((int64_t)((x_1932).b_));  } else { _r6588 = ((int64_t)((x_1932).a_));  } _r6588; })); 
int64_t ctt_1940 = ({ int64_t _r6589; if (((((*({ hrv *_t6590 = &(g543); int64_t _i6590 = rt0_1939; (S1*)_t6590->b + hr_ix(_i6590, _t6590->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:818"); }))).k_) == (((uint8_t)3LL)))) { _r6589 = rt0_1939;  } else { _r6589 = g555;  } _r6589; }); 
(void)(f257_ow(hr_str("{ ", 2)));
(void)(f258_ct(ctt_1940));
(void)(f257_ow(hr_str(" _e", 3)));
(void)(f291_oi(p_1937));
(void)(f257_ow(hr_str(" = ", 3)));
if ((((x_1932).b_) >= (((int32_t)0LL)))) { (void)(f286_gx(((int64_t)((x_1932).b_))));
 } else { (void)(f286_gx(((int64_t)((x_1932).a_))));
 }
(void)(f257_ow(hr_str("; for (", 7)));
(void)(f258_ct(ctt_1940));
(void)(({ hrv *_o6600 = &(g163); hr_fs(_o6600, hr_str(" _k", 3)); hr_fi(_o6600, p_1937); hr_fs(_o6600, hr_str(" = ", 3)); }));
if ((((x_1932).b_) >= (((int32_t)0LL)))) { (void)(f286_gx(((int64_t)((x_1932).a_))));
 } else { (void)(f257_ow(hr_str("0", 1)));
 }
(void)(({ hrv *_o6603 = &(g163); hr_fs(_o6603, hr_str("; _k", 4)); hr_fi(_o6603, p_1937); hr_fs(_o6603, hr_str(" < _e", 5)); hr_fi(_o6603, p_1937); hr_fs(_o6603, hr_str("; _k", 4)); hr_fi(_o6603, p_1937); hr_fs(_o6603, hr_str("++) { ", 6)); }));
(void)(f258_ct(et_1938));
(void)(f257_ow(hr_str(" ", 1)));
(void)(f283_lv_name(v_1933));
(void)(({ hrv *_o6607 = &(g163); hr_fs(_o6607, hr_str(" = (", 4)); }));
(void)(f258_ct(et_1938));
(void)(({ hrv *_o6609 = &(g163); hr_fs(_o6609, hr_str(")_k", 3)); hr_fi(_o6609, p_1937); hr_fs(_o6609, hr_str("; ", 2)); }));
if (((iv_1935) >= (((int64_t)0LL)))) { (void)(f258_ct(((int64_t)(((*({ hrv *_t6611 = &(g381); int64_t _i6611 = iv_1935; (S12*)_t6611->b + hr_ix(_i6611, _t6611->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:824"); }))).ty_))));
(void)(f257_ow(hr_str(" ", 1)));
(void)(f283_lv_name(iv_1935));
(void)(f257_ow(hr_str(" = (", 4)));
(void)(f258_ct(((int64_t)(((*({ hrv *_t6616 = &(g381); int64_t _i6616 = iv_1935; (S12*)_t6616->b + hr_ix(_i6616, _t6616->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:824"); }))).ty_))));
(void)(({ hrv *_o6617 = &(g163); hr_fs(_o6617, hr_str(")_k", 3)); hr_fi(_o6617, p_1937); hr_fs(_o6617, hr_str("; ", 2)); }));
 }
(void)(f336_gblk(((int64_t)((x_1932).d_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f257_ow(hr_str(" } }", 4)));
(void)(f340_lbl_pop(l_1936));
return;
 }
int64_t a_1941 = ((int64_t)((x_1932).a_)); 
int64_t bt_1942 = f141_at(a_1941); 
int64_t d_1943 = f179_deref(bt_1942); 
int64_t e_1944 = ((int64_t)(((*({ hrv *_t6623 = &(g543); int64_t _i6623 = d_1943; (S1*)_t6623->b + hr_ix(_i6623, _t6623->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:833"); }))).a_)); 
bool byref_1945 = ((((uint16_t)((uint64_t)(x_1932).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))); 
if (f265_is_res(d_1943)) { (void)(f257_ow(hr_str("{ hrv *_v", 9)));
(void)(f291_oi(p_1937));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f319_grecv_ptr(a_1941));
(void)(({ hrv *_o6629 = &(g163); hr_fs(_o6629, hr_str("; for (int64_t _k", 17)); hr_fi(_o6629, p_1937); hr_fs(_o6629, hr_str(" = 0; _k", 8)); hr_fi(_o6629, p_1937); hr_fs(_o6629, hr_str(" < _v", 5)); hr_fi(_o6629, p_1937); hr_fs(_o6629, hr_str("->n; _k", 7)); hr_fi(_o6629, p_1937); hr_fs(_o6629, hr_str("++) { ", 6)); }));
(void)(f258_ct(e_1944));
(void)(f257_ow(({ hsl _r6632; if (byref_1945) { _r6632 = hr_str(" *", 2);  } else { _r6632 = hr_str(" ", 1);  } _r6632; })));
(void)(f283_lv_name(v_1933));
(void)(f257_ow(({ hsl _r6635; if (byref_1945) { _r6635 = hr_str(" = &((", 6);  } else { _r6635 = hr_str(" = ((", 5);  } _r6635; })));
(void)(f258_ct(e_1944));
(void)(({ hrv *_o6637 = &(g163); hr_fs(_o6637, hr_str("*)_v", 4)); hr_fi(_o6637, p_1937); hr_fs(_o6637, hr_str("->b)[_k", 7)); hr_fi(_o6637, p_1937); hr_fs(_o6637, hr_str("]; ", 3)); }));
 } else { (void)(f257_ow(hr_str("{ hsl _v", 8)));
(void)(f291_oi(p_1937));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f289_gsl(a_1941, bt_1942));
(void)(({ hrv *_o6642 = &(g163); hr_fs(_o6642, hr_str("; for (int64_t _k", 17)); hr_fi(_o6642, p_1937); hr_fs(_o6642, hr_str(" = 0; _k", 8)); hr_fi(_o6642, p_1937); hr_fs(_o6642, hr_str(" < _v", 5)); hr_fi(_o6642, p_1937); hr_fs(_o6642, hr_str(".n; _k", 6)); hr_fi(_o6642, p_1937); hr_fs(_o6642, hr_str("++) { ", 6)); }));
(void)(f258_ct(e_1944));
(void)(f257_ow(({ hsl _r6645; if (byref_1945) { _r6645 = hr_str(" *", 2);  } else { _r6645 = hr_str(" ", 1);  } _r6645; })));
(void)(f283_lv_name(v_1933));
(void)(f257_ow(({ hsl _r6648; if (byref_1945) { _r6648 = hr_str(" = &((", 6);  } else { _r6648 = hr_str(" = ((", 5);  } _r6648; })));
(void)(f258_ct(e_1944));
(void)(({ hrv *_o6650 = &(g163); hr_fs(_o6650, hr_str("*)_v", 4)); hr_fi(_o6650, p_1937); hr_fs(_o6650, hr_str(".p)[_k", 6)); hr_fi(_o6650, p_1937); hr_fs(_o6650, hr_str("]; ", 3)); }));
 }
if (((iv_1935) >= (((int64_t)0LL)))) { (void)(f258_ct(((int64_t)(((*({ hrv *_t6652 = &(g381); int64_t _i6652 = iv_1935; (S12*)_t6652->b + hr_ix(_i6652, _t6652->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:842"); }))).ty_))));
(void)(f257_ow(hr_str(" ", 1)));
(void)(f283_lv_name(iv_1935));
(void)(f257_ow(hr_str(" = (", 4)));
(void)(f258_ct(((int64_t)(((*({ hrv *_t6657 = &(g381); int64_t _i6657 = iv_1935; (S12*)_t6657->b + hr_ix(_i6657, _t6657->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:842"); }))).ty_))));
(void)(({ hrv *_o6658 = &(g163); hr_fs(_o6658, hr_str(")_k", 3)); hr_fi(_o6658, p_1937); hr_fs(_o6658, hr_str("; ", 2)); }));
 }
(void)(f336_gblk(((int64_t)((x_1932).d_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f257_ow(hr_str(" } }", 4)));
(void)(f340_lbl_pop(l_1936));
}
static void f343_gmatch(int64_t n_1946, int64_t res_1947) {
S4 x_1948 = (*({ hrv *_t6662 = &(g696); int64_t _i6662 = n_1946; (S4*)_t6662->b + hr_ix(_i6662, _t6662->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:848"); })); 
int64_t a_1949 = ((int64_t)((x_1948).a_)); 
int64_t st_1950 = f141_at(a_1949); 
int64_t d_1951 = f179_deref(st_1950); 
int64_t p_1952 = f290_nt(); 
bool isenum_1953 = ((((*({ hrv *_t6666 = &(g543); int64_t _i6666 = d_1951; (S1*)_t6666->b + hr_ix(_i6666, _t6666->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:853"); }))).k_) == (((uint8_t)6LL))); 
(void)(f257_ow(hr_str("{ ", 2)));
if (isenum_1953) { (void)(f258_ct(d_1951));
(void)(f257_ow(hr_str(" *_m", 4)));
(void)(f291_oi(p_1952));
(void)(f257_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t6672 = &(g543); int64_t _i6672 = st_1950; (S1*)_t6672->b + hr_ix(_i6672, _t6672->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:855"); }))).k_) == (((uint8_t)10LL)))) { (void)(f272_gx0(a_1949));
 } else { if (f269_is_place(a_1949)) { (void)(f257_ow(hr_str("&(", 2)));
(void)(f286_gx(a_1949));
(void)(f257_ow(hr_str(")", 1)));
 } else { int64_t k0_1954 = f270_tmp(d_1951, false); 
(void)(f257_ow(hr_str("&(", 2)));
(void)(f271_ot(k0_1954));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f266_gxo(a_1949));
(void)(f257_ow(hr_str(")", 1)));
 }
 }
(void)(f257_ow(hr_str("; ", 2)));
 } else { (void)(f258_ct(d_1951));
(void)(f257_ow(hr_str(" _m", 3)));
(void)(f291_oi(p_1952));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(a_1949));
(void)(f257_ow(hr_str("; ", 2)));
 }
bool first_1955 = true; 
{ int32_t _e6692 = (x_1948).n_; for (int32_t _k6692 = 0; _k6692 < _e6692; _k6692++) { int32_t i_1956 = (int32_t)_k6692; int64_t arm_1957 = f90_kid(n_1946, ((int64_t)(i_1956))); 
S4 ar_1958 = (*({ hrv *_t6694 = &(g696); int64_t _i6694 = arm_1957; (S4*)_t6694->b + hr_ix(_i6694, _t6694->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:860"); })); 
if ((!(first_1955))) { (void)(f257_ow(hr_str(" else ", 6)));
 }
first_1955 = false;
if (((((uint16_t)((uint64_t)(ar_1958).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(f257_ow(hr_str("{ ", 2)));
(void)(f336_gblk(((int64_t)((ar_1958).b_)), res_1947, false));
(void)(f257_ow(hr_str(" }", 2)));
continue;
 }
(void)(f257_ow(hr_str("if (", 4)));
{ int32_t _e6701 = (ar_1958).n_; for (int32_t _k6701 = 0; _k6701 < _e6701; _k6701++) { int32_t j_1959 = (int32_t)_k6701; if (((j_1959) > (((int32_t)0LL)))) { (void)(f257_ow(hr_str(" || ", 4)));
 }
int64_t it_1960 = f90_kid(arm_1957, ((int64_t)(j_1959))); 
int64_t lo_1961 = ((int64_t)(((*({ hrv *_t6704 = &(g696); int64_t _i6704 = it_1960; (S4*)_t6704->b + hr_ix(_i6704, _t6704->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:868"); }))).a_)); 
if (isenum_1953) { (void)(({ hrv *_o6705 = &(g163); hr_fs(_o6705, hr_str("_m", 2)); hr_fi(_o6705, p_1952); hr_fs(_o6705, hr_str("->tag == ", 9)); hr_fi(_o6705, f157_rv(lo_1961)); }));
 } else { if (((((*({ hrv *_t6707 = &(g696); int64_t _i6707 = it_1960; (S4*)_t6707->b + hr_ix(_i6707, _t6707->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:871"); }))).b_) >= (((int32_t)0LL)))) { (void)(({ hrv *_o6708 = &(g163); hr_fs(_o6708, hr_str("(_m", 3)); hr_fi(_o6708, p_1952); hr_fs(_o6708, hr_str(" >= ", 4)); }));
(void)(f286_gx(lo_1961));
(void)(({ hrv *_o6710 = &(g163); hr_fs(_o6710, hr_str(" && _m", 6)); hr_fi(_o6710, p_1952); hr_fs(_o6710, hr_str(" < ", 3)); }));
(void)(f286_gx(((int64_t)(((*({ hrv *_t6712 = &(g696); int64_t _i6712 = it_1960; (S4*)_t6712->b + hr_ix(_i6712, _t6712->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:871"); }))).b_))));
(void)(f257_ow(hr_str(")", 1)));
 } else { if (((((f180_leaf_kind(d_1951)) == (((int64_t)0LL))) && ((((*({ hrv *_t6715 = &(g543); int64_t _i6715 = d_1951; (S1*)_t6715->b + hr_ix(_i6715, _t6715->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:872"); }))).k_) != (((uint8_t)3LL)))) && ((((*({ hrv *_t6716 = &(g543); int64_t _i6716 = d_1951; (S1*)_t6716->b + hr_ix(_i6716, _t6716->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:872"); }))).k_) != (((uint8_t)2LL))))) { (void)(f257_ow(hr_str("heq", 3)));
(void)(f291_oi(d_1951));
(void)(({ hrv *_o6719 = &(g163); hr_fs(_o6719, hr_str("(_m", 3)); hr_fi(_o6719, p_1952); hr_fs(_o6719, hr_str(", ", 2)); }));
(void)(f286_gx(lo_1961));
(void)(f257_ow(hr_str(")", 1)));
(void)(f292_gen_heq(d_1951));
 } else { (void)(({ hrv *_o6723 = &(g163); hr_fs(_o6723, hr_str("_m", 2)); hr_fi(_o6723, p_1952); hr_fs(_o6723, hr_str(" == ", 4)); }));
(void)(f286_gx(lo_1961));
 }
 }
 }
 } } _bk6700:; 
(void)(f257_ow(hr_str(") { ", 4)));
if (((((ar_1958).s_) >= (((int32_t)0LL))) && isenum_1953)) { int64_t v_1962 = f157_rv(arm_1957); 
int64_t vi_1963 = f157_rv(((int64_t)(((*({ hrv *_t6728 = &(g696); int64_t _i6728 = f90_kid(arm_1957, ((int64_t)0LL)); (S4*)_t6728->b + hr_ix(_i6728, _t6728->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:878"); }))).a_))); 
int64_t lt_1964 = ((int64_t)(((*({ hrv *_t6730 = &(g381); int64_t _i6730 = v_1962; (S12*)_t6730->b + hr_ix(_i6730, _t6730->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:879"); }))).ty_)); 
int64_t vt_1965 = f179_deref(lt_1964); 
int64_t ei_1966 = ((int64_t)(((*({ hrv *_t6732 = &(g543); int64_t _i6732 = d_1951; (S1*)_t6732->b + hr_ix(_i6732, _t6732->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:881"); }))).a_)); 
S9 vv_1967 = (*({ hrv *_t6733 = &(g549); int64_t _i6733 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t6734 = &(g548); int64_t _i6734 = ei_1966; (S8*)_t6734->b + hr_ix(_i6734, _t6734->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:882"); }))).v0_)) + (int64_t)vi_1963)); (S9*)_t6733->b + hr_ix(_i6733, _t6733->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:882"); })); 
bool has_1968 = ((((vv_1967).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t6735 = &(g546); int64_t _i6735 = (vv_1967).si_; (S10*)_t6735->b + hr_ix(_i6735, _t6735->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:883"); }))).zero_))); 
(void)(f258_ct(lt_1964));
(void)(f257_ow(hr_str(" ", 1)));
(void)(f283_lv_name(v_1962));
(void)(f257_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t6740 = &(g543); int64_t _i6740 = lt_1964; (S1*)_t6740->b + hr_ix(_i6740, _t6740->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:885"); }))).k_) == (((uint8_t)10LL)))) { if (has_1968) { (void)(({ hrv *_o6741 = &(g163); hr_fs(_o6741, hr_str("&_m", 3)); hr_fi(_o6741, p_1952); hr_fs(_o6741, hr_str("->u.v", 5)); hr_fi(_o6741, vi_1963); hr_fs(_o6741, hr_str("; ", 2)); }));
 } else { (void)(f257_ow(hr_str("0; ", 3)));
 }
 } else { if (has_1968) { (void)(({ hrv *_o6743 = &(g163); hr_fs(_o6743, hr_str("_m", 2)); hr_fi(_o6743, p_1952); hr_fs(_o6743, hr_str("->u.v", 5)); hr_fi(_o6743, vi_1963); hr_fs(_o6743, hr_str("; ", 2)); }));
 } else { (void)(f257_ow(hr_str("0; ", 3)));
 }
 }
 }
(void)(f336_gblk(((int64_t)((ar_1958).b_)), res_1947, false));
(void)(f257_ow(hr_str(" }", 2)));
 } } _bk6691:; 
(void)(f257_ow(hr_str(" }", 2)));
}
static void f344_geblock(int64_t n_1969, int64_t res_1970) {
int64_t l_1971 = f339_lbl_push(res_1970); 
(void)(f257_ow(hr_str("{ ", 2)));
(void)(f336_gblk(((int64_t)(((*({ hrv *_t6751 = &(g696); int64_t _i6751 = n_1969; (S4*)_t6751->b + hr_ix(_i6751, _t6751->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:797"); }))).a_)), res_1970, false));
(void)(f257_ow(hr_str(" }", 2)));
(void)(f340_lbl_pop(l_1971));
}
static void f345_gret(int64_t n_1972) {
S4 x_1973 = (*({ hrv *_t6754 = &(g696); int64_t _i6754 = n_1972; (S4*)_t6754->b + hr_ix(_i6754, _t6754->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:978"); })); 
int64_t lt_1974 = f217_ax(n_1972); 
if ((((lt_1974) >= (((int64_t)0LL))) && ((lt_1974) != (g179)))) { int64_t rt0_1975 = ((int64_t)(((*({ hrv *_t6756 = &(g380); int64_t _i6756 = lt_1974; (S6*)_t6756->b + hr_ix(_i6756, _t6756->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:981"); }))).ret_)); 
(void)(f257_ow(hr_str("{ ", 2)));
if ((((x_1973).n_) > (((int32_t)1LL)))) { (void)(({ hrv *_o6758 = &(g163); hr_fs(_o6758, hr_str("_lrv", 4)); hr_fi(_o6758, lt_1974); hr_fs(_o6758, hr_str(" = (", 4)); }));
(void)(f258_ct(rt0_1975));
(void)(f257_ow(hr_str("){ ", 3)));
{ int32_t _e6762 = (x_1973).n_; for (int32_t _k6762 = 0; _k6762 < _e6762; _k6762++) { int32_t i_1976 = (int32_t)_k6762; if (((i_1976) > (((int32_t)0LL)))) { (void)(f257_ow(hr_str(", ", 2)));
 }
int64_t c_1977 = f90_kid(n_1972, ((int64_t)(i_1976))); 
if (f265_is_res(f276_fin(c_1977))) { (void)(f346_gmove(c_1977));
 } else { (void)(f286_gx(c_1977));
 }
 } } _bk6761:; 
(void)(f257_ow(hr_str(" }; ", 4)));
 } else { if ((((x_1973).n_) == (((int32_t)1LL)))) { (void)(({ hrv *_o6770 = &(g163); hr_fs(_o6770, hr_str("_lrv", 4)); hr_fi(_o6770, lt_1974); hr_fs(_o6770, hr_str(" = ", 3)); }));
int64_t c_1983 = f90_kid(n_1972, ((int64_t)0LL)); 
if (f265_is_res(rt0_1975)) { (void)(f346_gmove(c_1983));
 } else { (void)(f286_gx(c_1983));
 }
(void)(f257_ow(hr_str("; ", 2)));
 }
 }
(void)(({ hrv *_o6776 = &(g163); hr_fs(_o6776, hr_str("hr_lr = ", 8)); hr_fi(_o6776, ((int64_t)((int64_t)lt_1974 + (int64_t)((int64_t)1LL)))); hr_fs(_o6776, hr_str("; ", 2)); }));
(void)(f348_gdummy());
(void)(f257_ow(hr_str(" }", 2)));
return;
 }
if ((((x_1973).n_) == (((int32_t)0LL)))) { (void)(f257_ow(hr_str("return;", 7)));
return;
 }
int64_t f_1985 = ({ int64_t _r6780; if (((lt_1974) >= (((int64_t)0LL)))) { _r6780 = lt_1974;  } else { _r6780 = f221_ret_fn();  } _r6780; }); 
int64_t rt_1986 = ((int64_t)(((*({ hrv *_t6782 = &(g380); int64_t _i6782 = f_1985; (S6*)_t6782->b + hr_ix(_i6782, _t6782->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:990"); }))).ret_)); 
if ((((x_1973).n_) > (((int32_t)1LL)))) { (void)(f257_ow(hr_str("return (", 8)));
(void)(f258_ct(rt_1986));
(void)(f257_ow(hr_str("){ ", 3)));
{ int32_t _e6787 = (x_1973).n_; for (int32_t _k6787 = 0; _k6787 < _e6787; _k6787++) { int32_t i_1987 = (int32_t)_k6787; if (((i_1987) > (((int32_t)0LL)))) { (void)(f257_ow(hr_str(", ", 2)));
 }
int64_t c_1988 = f90_kid(n_1972, ((int64_t)(i_1987))); 
if (f265_is_res(f276_fin(c_1988))) { (void)(f346_gmove(c_1988));
 } else { (void)(f286_gx(c_1988));
 }
 } } _bk6786:; 
(void)(f257_ow(hr_str(" };", 3)));
return;
 }
int64_t c_1989 = f90_kid(n_1972, ((int64_t)0LL)); 
(void)(f257_ow(hr_str("return ", 7)));
if (f265_is_res(rt_1986)) { (void)(f346_gmove(c_1989));
 } else { (void)(f286_gx(c_1989));
 }
(void)(f257_ow(hr_str(";", 1)));
}
static void f346_gmove(int64_t c_1978) {
if (f347_movable_local(c_1978)) { int64_t v_1981 = f157_rv(c_1978); 
int64_t p_1982 = f290_nt(); 
(void)(f257_ow(hr_str("({ hrv _mv", 10)));
(void)(f291_oi(p_1982));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f283_lv_name(v_1981));
(void)(f257_ow(hr_str("; ", 2)));
(void)(f283_lv_name(v_1981));
(void)(f257_ow(hr_str(".b = 0; ", 8)));
(void)(f283_lv_name(v_1981));
(void)(({ hrv *_o6812 = &(g163); hr_fs(_o6812, hr_str(".n = 0; _mv", 11)); hr_fi(_o6812, p_1982); hr_fs(_o6812, hr_str("; })", 4)); }));
return;
 }
(void)(f266_gxo(c_1978));
}
static bool f347_movable_local(int64_t c_1979) {
if ((((((*({ hrv *_t6814 = &(g696); int64_t _i6814 = c_1979; (S4*)_t6814->b + hr_ix(_i6814, _t6814->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:972"); }))).k_) != (((uint8_t)8LL))) || ((f156_rk(c_1979)) != (((int64_t)1LL))))) { return false;
 }
int64_t v_1980 = f157_rv(c_1979); 
return (((((((int64_t)(((*({ hrv *_t6817 = &(g381); int64_t _i6817 = v_1980; (S12*)_t6817->b + hr_ix(_i6817, _t6817->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:972"); }))).cfn_))) == (g179)) && (!(f282_lv_isptr(v_1980)))) && ((((*({ hrv *_t6819 = &(g543); int64_t _i6819 = ((*({ hrv *_t6820 = &(g381); int64_t _i6820 = v_1980; (S12*)_t6820->b + hr_ix(_i6820, _t6820->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:972"); }))).ty_; (S1*)_t6819->b + hr_ix(_i6819, _t6819->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:972"); }))).k_) != (((uint8_t)10LL)))) && (((f150_cv(c_1979)) < (((int64_t)0LL))) || ((f150_cv(c_1979)) == (f141_at(c_1979)))));
}
static void f348_gdummy(void) {
int64_t rt_1984 = ((int64_t)(((*({ hrv *_t6824 = &(g380); int64_t _i6824 = g179; (S6*)_t6824->b + hr_ix(_i6824, _t6824->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:966"); }))).ret_)); 
if ((((rt_1984) < (((int64_t)0LL))) || ((rt_1984) == (g550)))) { (void)(f257_ow(hr_str("return;", 7)));
return;
 }
(void)(f257_ow(hr_str("{ ", 2)));
(void)(f258_ct(rt_1984));
(void)(f257_ow(hr_str(" _z; memset(&_z, 0, sizeof _z); return _z; }", 44)));
}
static void f349_gbreak(int64_t n_1990) {
S4 x_1991 = (*({ hrv *_t6829 = &(g696); int64_t _i6829 = n_1990; (S4*)_t6829->b + hr_ix(_i6829, _t6829->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:996"); })); 
if ((((g180).n) == (((int64_t)0LL)))) { (void)(f284_gerr(n_1990, hr_str("break outside a loop", 20)));
return;
 }
int64_t l_1992 = ((int64_t)((*({ hrv *_t6831 = &(g180); int64_t _i6831 = ((int64_t)((int64_t)(g180).n - (int64_t)((int64_t)1LL))); (int32_t*)_t6831->b + hr_ix(_i6831, _t6831->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:998"); })))); 
int64_t r_1993 = ((int64_t)((*({ hrv *_t6832 = &(g181); int64_t _i6832 = ((int64_t)((int64_t)(g181).n - (int64_t)((int64_t)1LL))); (int32_t*)_t6832->b + hr_ix(_i6832, _t6832->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:999"); })))); 
(void)(f257_ow(hr_str("{ ", 2)));
if ((((x_1991).a_) >= (((int32_t)0LL)))) { if (((r_1993) >= (((int64_t)0LL)))) { (void)(f257_ow(hr_str("_r", 2)));
(void)(f291_oi(r_1993));
(void)(f257_ow(hr_str(" = ", 3)));
(void)(f286_gx(((int64_t)((x_1991).a_))));
(void)(f257_ow(hr_str("; ", 2)));
 } else { (void)(f257_ow(hr_str("(void)(", 7)));
(void)(f286_gx(((int64_t)((x_1991).a_))));
(void)(f257_ow(hr_str("); ", 3)));
 }
 }
(void)(({ hrv *_o6842 = &(g163); hr_fs(_o6842, hr_str("goto _bk", 8)); hr_fi(_o6842, l_1992); hr_fs(_o6842, hr_str("; }", 3)); }));
}
static bool f350_owned(int64_t n_1994) {
return (f265_is_res(f276_fin(n_1994)) && (!(f269_is_place(n_1994))));
}
static bool f351_is_ext(int64_t i_1998) {
return ((((uint16_t)((uint64_t)((*({ hrv *_t6846 = &(g696); int64_t _i6846 = ((*({ hrv *_t6847 = &(g380); int64_t _i6847 = i_1998; (S6*)_t6847->b + hr_ix(_i6847, _t6847->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:556"); }))).node_; (S4*)_t6846->b + hr_ix(_i6846, _t6846->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:556"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)));
}
static void f352_ext_name(int64_t i_2003) {
int64_t node_2004 = ((int64_t)(((*({ hrv *_t6848 = &(g380); int64_t _i6848 = i_2003; (S6*)_t6848->b + hr_ix(_i6848, _t6848->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:551"); }))).node_)); 
int64_t x_2005 = ((int64_t)(((*({ hrv *_t6849 = &(g696); int64_t _i6849 = node_2004; (S4*)_t6849->b + hr_ix(_i6849, _t6849->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:552"); }))).e_)); 
if ((((x_2005) >= (((int64_t)0LL))) && ((((*({ hrv *_t6850 = &(g696); int64_t _i6850 = x_2005; (S4*)_t6850->b + hr_ix(_i6850, _t6850->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:553"); }))).a_) >= (((int32_t)0LL))))) { hsl s_2006 = f277_tok_str(((int64_t)(((*({ hrv *_t6852 = &(g696); int64_t _i6852 = x_2005; (S4*)_t6852->b + hr_ix(_i6852, _t6852->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:553"); }))).a_))); 
if (((((((s_2006).n) > (((int64_t)3LL))) && (((*({ hsl _t6853 = s_2006; int64_t _i6853 = ((int64_t)0LL); (uint8_t*)_t6853.p + hr_ix(_i6853, _t6853.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:553"); }))) == (((uint8_t)103LL)))) && (((*({ hsl _t6854 = s_2006; int64_t _i6854 = ((int64_t)1LL); (uint8_t*)_t6854.p + hr_ix(_i6854, _t6854.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:553"); }))) == (((uint8_t)115LL)))) && (((*({ hsl _t6855 = s_2006; int64_t _i6855 = ((int64_t)2LL); (uint8_t*)_t6855.p + hr_ix(_i6855, _t6855.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:553"); }))) == (((uint8_t)95LL))))) { (void)(f257_ow(hr_str("hr_", 3)));
(void)(f257_ow(({ hsl _t6858 = s_2006; int64_t _l6858 = ((int64_t)3LL), _h6858 = _t6858.n; if (_l6858 < 0 || _h6858 < _l6858 || _h6858 > _t6858.n) hr_slerr(_l6858, _h6858, _t6858.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:553"); (hsl){ _t6858.p + _l6858 * (int64_t)sizeof(uint8_t), _h6858 - _l6858 }; })));
return;
 }
(void)(f257_ow(s_2006));
return;
 }
(void)(f257_ow(f10_nm(((int64_t)(((*({ hrv *_t6862 = &(g696); int64_t _i6862 = node_2004; (S4*)_t6862->b + hr_ix(_i6862, _t6862->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:554"); }))).s_)))));
}
static void f353_fn_cname(int64_t i_2007) {
(void)(({ hrv *_o6863 = &(g163); hr_fs(_o6863, hr_str("f", 1)); hr_fi(_o6863, i_2007); hr_fs(_o6863, hr_str("_", 1)); }));
int64_t s_2008 = ((int64_t)(((*({ hrv *_t6864 = &(g380); int64_t _i6864 = i_2007; (S6*)_t6864->b + hr_ix(_i6864, _t6864->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:549"); }))).name_)); 
if (((s_2008) >= (((int64_t)0LL)))) { { hsl _v6866 = f10_nm(s_2008); for (int64_t _k6866 = 0; _k6866 < _v6866.n; _k6866++) { uint8_t c_2009 = ((uint8_t*)_v6866.p)[_k6866]; (void)(({ hrv *_v6868 = &(g163); uint8_t _x6868 = ({ uint8_t _r6869; if (((c_2009) == (((uint8_t)58LL)))) { _r6869 = ((uint8_t)95LL);  } else { _r6869 = c_2009;  } _r6869; }); uint8_t *_p6868 = (uint8_t*)hr_grow(_v6868, 1, sizeof _x6868); *_p6868 = _x6868; _p6868; }));
 } } _bk6865:; 
 }
}
static void f354_gcall_args(int64_t n_2010, int64_t inst_2011, int64_t recv_2012) {
S4 x_2013 = (*({ hrv *_t6870 = &(g696); int64_t _i6870 = n_2010; (S4*)_t6870->b + hr_ix(_i6870, _t6870->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:558"); })); 
int64_t np_2014 = ((int64_t)(((*({ hrv *_t6871 = &(g696); int64_t _i6871 = ((*({ hrv *_t6872 = &(g380); int64_t _i6872 = inst_2011; (S6*)_t6872->b + hr_ix(_i6872, _t6872->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:559"); }))).node_; (S4*)_t6871->b + hr_ix(_i6871, _t6871->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:559"); }))).n_)); 
int64_t na_2015 = ((int64_t)((int64_t)((int64_t)((x_2013).n_)) + (int64_t)({ int64_t _r6873; if (((recv_2012) >= (((int64_t)0LL)))) { _r6873 = ((int64_t)1LL);  } else { _r6873 = ((int64_t)0LL);  } _r6873; }))); 
bool first_2016 = true; 
{ int64_t _e6875 = np_2014; for (int64_t _k6875 = 0; _k6875 < _e6875; _k6875++) { int64_t j_2017 = (int64_t)_k6875; int64_t pt_2018 = f208_ptype_of(inst_2011, j_2017); 
if ((!(first_2016))) { (void)(f257_ow(hr_str(", ", 2)));
 }
first_2016 = false;
if (((j_2017) >= (na_2015))) { int64_t p_2019 = f90_kid(((int64_t)(((*({ hrv *_t6879 = &(g380); int64_t _i6879 = inst_2011; (S6*)_t6879->b + hr_ix(_i6879, _t6879->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:567"); }))).node_)), j_2017); 
int64_t sa_2020 = g393; 
g393 = inst_2011;
(void)(f286_gx(((int64_t)(((*({ hrv *_t6881 = &(g696); int64_t _i6881 = p_2019; (S4*)_t6881->b + hr_ix(_i6881, _t6881->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:568"); }))).b_))));
g393 = sa_2020;
continue;
 }
int64_t c_2021 = ({ int64_t _r6882; if (((recv_2012) >= (((int64_t)0LL)))) { _r6882 = ({ int64_t _r6883; if (((j_2017) == (((int64_t)0LL)))) { _r6883 = recv_2012;  } else { _r6883 = f90_kid(n_2010, ((int64_t)((int64_t)j_2017 - (int64_t)((int64_t)1LL))));  } _r6883; });  } else { _r6882 = f90_kid(n_2010, j_2017);  } _r6882; }); 
int64_t ct0_2022 = f276_fin(c_2021); 
if ((((((*({ hrv *_t6887 = &(g543); int64_t _i6887 = pt_2018; (S1*)_t6887->b + hr_ix(_i6887, _t6887->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:573"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t6888 = &(g543); int64_t _i6888 = pt_2018; (S1*)_t6888->b + hr_ix(_i6888, _t6888->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:573"); }))).c_) < (((int32_t)0LL))))) { if ((((((*({ hrv *_t6889 = &(g543); int64_t _i6889 = ct0_2022; (S1*)_t6889->b + hr_ix(_i6889, _t6889->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:574"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t6890 = &(g543); int64_t _i6890 = ct0_2022; (S1*)_t6890->b + hr_ix(_i6890, _t6890->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:574"); }))).k_) == (((uint8_t)11LL))))) { (void)(f286_gx(c_2021));
 } else { (void)(f321_gaddr(c_2021));
 }
continue;
 }
if (f265_is_res(pt_2018)) { (void)(f266_gxo(c_2021));
continue;
 }
if (((((*({ hrv *_t6895 = &(g543); int64_t _i6895 = pt_2018; (S1*)_t6895->b + hr_ix(_i6895, _t6895->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:578"); }))).k_) == (((uint8_t)9LL)))) { (void)(f288_gas(c_2021));
continue;
 }
(void)(f286_gx(c_2021));
 } } _bk6874:; 
{ hrv *_v6899 = &(g384); for (int64_t _k6899 = 0; _k6899 < _v6899->n; _k6899++) { S13 cp_2023 = ((S13*)_v6899->b)[_k6899]; if (((((int64_t)((cp_2023).inst_))) == (inst_2011))) { if ((!(first_2016))) { (void)(f257_ow(hr_str(", ", 2)));
 }
first_2016 = false;
(void)(f355_lv_addr(((int64_t)((cp_2023).lv_))));
 }
 } } _bk6898:; 
}
static void f355_lv_addr(int64_t v_2024) {
if (((((int64_t)(((*({ hrv *_t6902 = &(g381); int64_t _i6902 = v_2024; (S12*)_t6902->b + hr_ix(_i6902, _t6902->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:119"); }))).cfn_))) != (g179))) { (void)(({ hrv *_o6903 = &(g163); hr_fs(_o6903, hr_str("c", 1)); hr_fi(_o6903, v_2024); }));
return;
 }
(void)(f257_ow(hr_str("&", 1)));
(void)(f283_lv_name(v_2024));
}
static void f356_glrcheck(void) {
(void)(f257_ow(hr_str("if (HR_UNLIKELY(hr_lr)) { ", 26)));
if (((*({ hrv *_t6907 = &(g380); int64_t _i6907 = g179; (S6*)_t6907->b + hr_ix(_i6907, _t6907->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:969"); }))).tg_) { int64_t rt_2025 = ((int64_t)(((*({ hrv *_t6908 = &(g380); int64_t _i6908 = g179; (S6*)_t6908->b + hr_ix(_i6908, _t6908->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:969"); }))).ret_)); 
(void)(({ hrv *_o6909 = &(g163); hr_fs(_o6909, hr_str("if (hr_lr == ", 13)); hr_fi(_o6909, ((int64_t)((int64_t)g179 + (int64_t)((int64_t)1LL)))); hr_fs(_o6909, hr_str(") { hr_lr = 0; ", 15)); }));
if ((((rt_2025) < (((int64_t)0LL))) || ((rt_2025) == (g550)))) { (void)(f257_ow(hr_str("return; } ", 10)));
 } else { (void)(({ hrv *_o6911 = &(g163); hr_fs(_o6911, hr_str("return _lrv", 11)); hr_fi(_o6911, g179); hr_fs(_o6911, hr_str("; } ", 4)); }));
 }
 }
(void)(f348_gdummy());
(void)(f257_ow(hr_str(" } ", 3)));
}
static void f357_gen_fn(int64_t i_2040) {
int64_t node_2041 = ((int64_t)(((*({ hrv *_t6914 = &(g380); int64_t _i6914 = i_2040; (S6*)_t6914->b + hr_ix(_i6914, _t6914->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1062"); }))).node_)); 
g393 = i_2040;
g179 = i_2040;
(void)(({ hrv *_v6915 = &(g180); _v6915->n = 0; }));
(void)(({ hrv *_v6916 = &(g181); _v6916->n = 0; }));
int64_t s0_2042 = (g163).n; 
(void)(f358_gsig(i_2040));
(void)(({ hrv *_v6918 = &(g166); hsl _s6918 = ({ hsl _t6919 = hr_sl(g163); int64_t _l6919 = s0_2042, _h6919 = _t6919.n; if (_l6919 < 0 || _h6919 < _l6919 || _h6919 > _t6919.n) hr_slerr(_l6919, _h6919, _t6919.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1067"); (hsl){ _t6919.p + _l6919 * (int64_t)sizeof(uint8_t), _h6919 - _l6919 }; }); hr_append(_v6918, _s6918.p, _s6918.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6920 = &(g166); hsl _s6920 = hr_str(";\012", 2); hr_append(_v6920, _s6920.p, _s6920.n, sizeof(uint8_t)); }));
(void)(f257_ow(hr_str(" {\012", 3)));
{ int32_t _e6923 = ((*({ hrv *_t6924 = &(g696); int64_t _i6924 = node_2041; (S4*)_t6924->b + hr_ix(_i6924, _t6924->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1069"); }))).n_; for (int32_t _k6923 = 0; _k6923 < _e6923; _k6923++) { int32_t j_2054 = (int32_t)_k6923; int64_t p_2055 = f90_kid(node_2041, ((int64_t)(j_2054))); 
int64_t v_2056 = f157_rv(p_2055); 
if (f265_is_res(f208_ptype_of(i_2040, ((int64_t)(j_2054))))) { (void)(f257_ow(hr_str("hrv ", 4)));
(void)(f283_lv_name(v_2056));
(void)(f257_ow(hr_str(" __attribute__((cleanup(hr_rdrop))) = ", 38)));
(void)(f283_lv_name(v_2056));
(void)(f257_ow(hr_str("_in;\012", 5)));
 }
 } } _bk6922:; 
int64_t body_2057 = ((int64_t)(((*({ hrv *_t6934 = &(g696); int64_t _i6934 = node_2041; (S4*)_t6934->b + hr_ix(_i6934, _t6934->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1070"); }))).c_)); 
int64_t rt_2058 = ((int64_t)(((*({ hrv *_t6935 = &(g380); int64_t _i6935 = i_2040; (S6*)_t6935->b + hr_ix(_i6935, _t6935->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1071"); }))).ret_)); 
int64_t tl_2059 = ((int64_t)(((*({ hrv *_t6936 = &(g696); int64_t _i6936 = body_2057; (S4*)_t6936->b + hr_ix(_i6936, _t6936->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1072"); }))).a_)); 
{ int32_t _e6938 = ((*({ hrv *_t6939 = &(g696); int64_t _i6939 = body_2057; (S4*)_t6939->b + hr_ix(_i6939, _t6939->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1073"); }))).n_; for (int32_t _k6938 = 0; _k6938 < _e6938; _k6938++) { int32_t q_2060 = (int32_t)_k6938; (void)(f329_gstmt(f90_kid(body_2057, ((int64_t)(q_2060)))));
 } } _bk6937:; 
if (((tl_2059) >= (((int64_t)0LL)))) { if ((((((rt_2058) >= (((int64_t)0LL))) && ((rt_2058) != (g550))) && ((f141_at(tl_2059)) != (g550))) && (!(f209_ends(tl_2059))))) { int64_t sp_2061 = (g163).n; 
int64_t td_2062 = (g176).n; 
if ((((((*({ hrv *_t6944 = &(g543); int64_t _i6944 = rt_2058; (S1*)_t6944->b + hr_ix(_i6944, _t6944->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1077"); }))).k_) == (((uint8_t)14LL))) && ((((*({ hrv *_t6945 = &(g696); int64_t _i6945 = tl_2059; (S4*)_t6945->b + hr_ix(_i6945, _t6945->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1077"); }))).k_) == (((uint8_t)11LL))))) { (void)(f257_ow(hr_str("return ", 7)));
(void)(f286_gx(tl_2059));
(void)(f257_ow(hr_str(";\012", 2)));
 } else { (void)(f257_ow(hr_str("return ", 7)));
if (f265_is_res(rt_2058)) { (void)(f346_gmove(tl_2059));
 } else { (void)(f286_gx(tl_2059));
 }
(void)(f257_ow(hr_str(";\012", 2)));
 }
if ((((g176).n) > (td_2062))) { (void)(({ hrv *_v6954 = &(g177); _v6954->n = 0; }));
(void)(({ hrv *_v6955 = &(g177); hsl _s6955 = ({ hsl _t6956 = hr_sl(g163); int64_t _l6956 = sp_2061, _h6956 = _t6956.n; if (_l6956 < 0 || _h6956 < _l6956 || _h6956 > _t6956.n) hr_slerr(_l6956, _h6956, _t6956.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1079"); (hsl){ _t6956.p + _l6956 * (int64_t)sizeof(uint8_t), _h6956 - _l6956 }; }); hr_append(_v6955, _s6955.p, _s6955.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6957 = &(g163); int64_t _k6957 = sp_2061; if (_k6957 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1079"); hr_resize(_v6957, _k6957, sizeof(uint8_t)); }));
(void)(f257_ow(hr_str("{ ", 2)));
(void)(({ hrv *_v6959 = &(g163); hsl _s6959 = ({ hsl _t6960 = hr_sl(g176); int64_t _l6960 = td_2062, _h6960 = _t6960.n; if (_l6960 < 0 || _h6960 < _l6960 || _h6960 > _t6960.n) hr_slerr(_l6960, _h6960, _t6960.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1079"); (hsl){ _t6960.p + _l6960 * (int64_t)sizeof(uint8_t), _h6960 - _l6960 }; }); hr_append(_v6959, _s6959.p, _s6959.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v6961 = &(g176); int64_t _k6961 = td_2062; if (_k6961 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1079"); hr_resize(_v6961, _k6961, sizeof(uint8_t)); }));
(void)(({ hrv *_v6962 = &(g163); hsl _s6962 = ({ hsl _t6963 = hr_sl(g177); int64_t _l6963 = 0, _h6963 = _t6963.n; if (_l6963 < 0 || _h6963 < _l6963 || _h6963 > _t6963.n) hr_slerr(_l6963, _h6963, _t6963.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1079"); (hsl){ _t6963.p + _l6963 * (int64_t)sizeof(uint8_t), _h6963 - _l6963 }; }); hr_append(_v6962, _s6962.p, _s6962.n, sizeof(uint8_t)); }));
(void)(f257_ow(hr_str("}\012", 2)));
 }
 } else { (void)(f329_gstmt(tl_2059));
 }
 }
(void)(f257_ow(hr_str("}\012", 2)));
}
static void f358_gsig(int64_t i_2043) {
int64_t rt_2044 = ((int64_t)(((*({ hrv *_t6967 = &(g380); int64_t _i6967 = i_2043; (S6*)_t6967->b + hr_ix(_i6967, _t6967->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1041"); }))).ret_)); 
(void)(f257_ow(hr_str("static ", 7)));
if (((rt_2044) < (((int64_t)0LL)))) { (void)(f257_ow(hr_str("void", 4)));
 } else { (void)(f258_ct(rt_2044));
 }
(void)(f257_ow(hr_str(" ", 1)));
(void)(f353_fn_cname(i_2043));
(void)(f257_ow(hr_str("(", 1)));
int64_t node_2045 = ((int64_t)(((*({ hrv *_t6974 = &(g380); int64_t _i6974 = i_2043; (S6*)_t6974->b + hr_ix(_i6974, _t6974->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1045"); }))).node_)); 
bool first_2046 = true; 
int64_t sa_2047 = g393; 
g393 = i_2043;
{ int32_t _e6976 = ((*({ hrv *_t6977 = &(g696); int64_t _i6977 = node_2045; (S4*)_t6977->b + hr_ix(_i6977, _t6977->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1048"); }))).n_; for (int32_t _k6976 = 0; _k6976 < _e6976; _k6976++) { int32_t j_2048 = (int32_t)_k6976; int64_t p_2049 = f90_kid(node_2045, ((int64_t)(j_2048))); 
int64_t v_2050 = f157_rv(p_2049); 
if ((!(first_2046))) { (void)(f257_ow(hr_str(", ", 2)));
 }
first_2046 = false;
int64_t t_2051 = f208_ptype_of(i_2043, ((int64_t)(j_2048))); 
(void)(f258_ct(t_2051));
(void)(f257_ow(hr_str(" ", 1)));
(void)(f283_lv_name(v_2050));
if (f265_is_res(t_2051)) { (void)(f257_ow(hr_str("_in", 3)));
 }
 } } _bk6975:; 
g393 = sa_2047;
{ hrv *_v6988 = &(g384); for (int64_t _k6988 = 0; _k6988 < _v6988->n; _k6988++) { S13 cp_2052 = ((S13*)_v6988->b)[_k6988]; if (((((int64_t)((cp_2052).inst_))) == (i_2043))) { if ((!(first_2046))) { (void)(f257_ow(hr_str(", ", 2)));
 }
first_2046 = false;
int64_t v_2053 = ((int64_t)((cp_2052).lv_)); 
(void)(f258_ct(((int64_t)(((*({ hrv *_t6991 = &(g381); int64_t _i6991 = v_2053; (S12*)_t6991->b + hr_ix(_i6991, _t6991->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1057"); }))).ty_))));
(void)(f257_ow(({ hsl _r6993; if (f282_lv_isptr(v_2053)) { _r6993 = hr_str(" **c", 4);  } else { _r6993 = hr_str(" *c", 3);  } _r6993; })));
(void)(f291_oi(v_2053));
 }
 } } _bk6987:; 
if (first_2046) { (void)(f257_ow(hr_str("void", 4)));
 }
(void)(f257_ow(hr_str(")", 1)));
}
static void hr_init_globals(void) {
g846 = ({ A25 _t1; _t1.e[0] = hr_str("import", 6); _t1.e[1] = hr_str("namespace", 9); _t1.e[2] = hr_str("struct", 6); _t1.e[3] = hr_str("enum", 4); _t1.e[4] = hr_str("type", 4); _t1.e[5] = hr_str("fn", 2); _t1.e[6] = hr_str("thread_fn", 9); _t1.e[7] = hr_str("export", 6); _t1.e[8] = hr_str("simd", 4); _t1.e[9] = hr_str("recursive", 9); _t1.e[10] = hr_str("let", 3); _t1.e[11] = hr_str("var", 3); _t1.e[12] = hr_str("extern", 6); _t1.e[13] = hr_str("const", 5); _t1.e[14] = hr_str("pad", 3); _t1.e[15] = hr_str("reusable", 8); _t1.e[16] = hr_str("if", 2); _t1.e[17] = hr_str("else", 4); _t1.e[18] = hr_str("while", 5); _t1.e[19] = hr_str("for", 3); _t1.e[20] = hr_str("in", 2); _t1.e[21] = hr_str("loop", 4); _t1.e[22] = hr_str("block", 5); _t1.e[23] = hr_str("guard", 5); _t1.e[24] = hr_str("match", 5); _t1.e[25] = hr_str("return", 6); _t1.e[26] = hr_str("break", 5); _t1.e[27] = hr_str("continue", 8); _t1.e[28] = hr_str("as", 2); _t1.e[29] = hr_str("true", 4); _t1.e[30] = hr_str("false", 5); _t1.e[31] = hr_str("null", 4); _t1.e[32] = hr_str("self", 4); _t1.e[33] = hr_str("bool", 4); _t1.e[34] = hr_str("varint", 6); _t1.e[35] = hr_str("i8", 2); _t1.e[36] = hr_str("i16", 3); _t1.e[37] = hr_str("i32", 3); _t1.e[38] = hr_str("i64", 3); _t1.e[39] = hr_str("u8", 2); _t1.e[40] = hr_str("u16", 3); _t1.e[41] = hr_str("u32", 3); _t1.e[42] = hr_str("u64", 3); _t1.e[43] = hr_str("f32", 3); _t1.e[44] = hr_str("f64", 3); _t1.e[45] = hr_str("int", 3); _t1.e[46] = hr_str("uint", 4); _t1.e[47] = hr_str("byte", 4); _t1.e[48] = hr_str("real", 4); _t1; });
g713 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g714 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g715 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g716 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g717 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g718 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g719 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g720 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g721 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g722 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g709 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g708 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g395 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g393 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g394 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g183 = ({ A62 _t2; _t2.e[0] = hr_str("int8_t", 6); _t2.e[1] = hr_str("int16_t", 7); _t2.e[2] = hr_str("int32_t", 7); _t2.e[3] = hr_str("int64_t", 7); _t2.e[4] = hr_str("uint8_t", 7); _t2.e[5] = hr_str("uint16_t", 8); _t2.e[6] = hr_str("uint32_t", 8); _t2.e[7] = hr_str("uint64_t", 8); _t2; });
g179 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g114 = ({ A101 _t3; _t3.e[0] = ((double)1e0); _t3.e[1] = ((double)1e1); _t3.e[2] = ((double)1e2); _t3.e[3] = ((double)1e3); _t3.e[4] = ((double)1e4); _t3.e[5] = ((double)1e5); _t3.e[6] = ((double)1e6); _t3.e[7] = ((double)1e7); _t3.e[8] = ((double)1e8); _t3.e[9] = ((double)1e9); _t3.e[10] = ((double)1e10); _t3.e[11] = ((double)1e11); _t3.e[12] = ((double)1e12); _t3.e[13] = ((double)1e13); _t3.e[14] = ((double)1e14); _t3.e[15] = ((double)1e15); _t3.e[16] = ((double)1e16); _t3.e[17] = ((double)1e17); _t3.e[18] = ((double)1e18); _t3.e[19] = ((double)1e19); _t3.e[20] = ((double)1e20); _t3.e[21] = ((double)1e21); _t3.e[22] = ((double)1e22); _t3; });
g154 = ((hrv){0});
g288 = ((int64_t)1LL);
g289 = ((int64_t)2LL);
g290 = ((int64_t)3LL);
g291 = ((int64_t)4LL);
g292 = ((int64_t)5LL);
g293 = ((int64_t)6LL);
g294 = ((int64_t)7LL);
g295 = ((int64_t)8LL);
g296 = ((int64_t)9LL);
g297 = ((int64_t)20LL);
g298 = ((int64_t)21LL);
g299 = ((int64_t)22LL);
g300 = ((int64_t)23LL);
g301 = ((int64_t)24LL);
g302 = ((int64_t)25LL);
g303 = ((int64_t)26LL);
g304 = ((int64_t)27LL);
g305 = ((int64_t)30LL);
g306 = ((int64_t)31LL);
g307 = ((int64_t)32LL);
g308 = ((int64_t)33LL);
g354 = ((int64_t)0LL);
g355 = ((int64_t)1LL);
g356 = ((int64_t)2LL);
g357 = ((int64_t)3LL);
g358 = ((int64_t)4LL);
g359 = ((int64_t)5LL);
g360 = ((int64_t)6LL);
g361 = ((int64_t)7LL);
g362 = ((int64_t)8LL);
g363 = ((int64_t)9LL);
g364 = ((int64_t)10LL);
g365 = ((int64_t)11LL);
g366 = ((int64_t)12LL);
g367 = ((int64_t)13LL);
g368 = ((int64_t)14LL);
g369 = ((int64_t)1LL);
g370 = ((int64_t)2LL);
g371 = ((int64_t)4LL);
g372 = ((int64_t)8LL);
g373 = ((int64_t)16LL);
g374 = ((int64_t)32LL);
g375 = ((int64_t)2LL);
g392 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g398 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g474 = ((int64_t)1LL);
g475 = ((int64_t)2LL);
g476 = ((int64_t)3LL);
g477 = ((int64_t)4LL);
g478 = ((int64_t)5LL);
g513 = ((int64_t)0LL);
g514 = ((int64_t)1LL);
g515 = ((int64_t)2LL);
g516 = ((int64_t)3LL);
g517 = ((int64_t)4LL);
g518 = ((int64_t)5LL);
g519 = ((int64_t)6LL);
g520 = ((int64_t)7LL);
g521 = ((int64_t)8LL);
g522 = ((int64_t)9LL);
g523 = ((int64_t)10LL);
g524 = ((int64_t)11LL);
g525 = ((int64_t)12LL);
g526 = ((int64_t)13LL);
g527 = ((int64_t)14LL);
g528 = ((int64_t)15LL);
g529 = ((int64_t)16LL);
g530 = ((int64_t)17LL);
g531 = ((int64_t)18LL);
g532 = ((int64_t)19LL);
g533 = ((int64_t)1LL);
g534 = ((int64_t)2LL);
g535 = ((int64_t)0LL);
g536 = ((int64_t)1LL);
g537 = ((int64_t)2LL);
g618 = ((int64_t)1LL);
g619 = ((int64_t)2LL);
g620 = ((int64_t)3LL);
g621 = ((int64_t)4LL);
g622 = ((int64_t)5LL);
g623 = ((int64_t)6LL);
g624 = ((int64_t)7LL);
g625 = ((int64_t)8LL);
g626 = ((int64_t)9LL);
g627 = ((int64_t)10LL);
g628 = ((int64_t)11LL);
g629 = ((int64_t)12LL);
g630 = ((int64_t)13LL);
g631 = ((int64_t)14LL);
g632 = ((int64_t)15LL);
g633 = ((int64_t)16LL);
g634 = ((int64_t)17LL);
g635 = ((int64_t)18LL);
g636 = ((int64_t)19LL);
g637 = ((int64_t)20LL);
g638 = ((int64_t)21LL);
g639 = ((int64_t)22LL);
g640 = ((int64_t)23LL);
g641 = ((int64_t)24LL);
g642 = ((int64_t)25LL);
g643 = ((int64_t)26LL);
g644 = ((int64_t)27LL);
g645 = ((int64_t)28LL);
g646 = ((int64_t)29LL);
g647 = ((int64_t)30LL);
g648 = ((int64_t)31LL);
g649 = ((int64_t)32LL);
g650 = ((int64_t)33LL);
g651 = ((int64_t)34LL);
g652 = ((int64_t)35LL);
g653 = ((int64_t)36LL);
g654 = ((int64_t)37LL);
g655 = ((int64_t)40LL);
g656 = ((int64_t)41LL);
g657 = ((int64_t)42LL);
g658 = ((int64_t)43LL);
g659 = ((int64_t)44LL);
g660 = ((int64_t)45LL);
g661 = ((int64_t)46LL);
g662 = ((int64_t)47LL);
g663 = ((int64_t)48LL);
g664 = ((int64_t)50LL);
g665 = ((int64_t)51LL);
g666 = ((int64_t)52LL);
g667 = ((int64_t)53LL);
g668 = ((int64_t)54LL);
g669 = ((int64_t)55LL);
g670 = ((int64_t)56LL);
g671 = ((int64_t)57LL);
g672 = ((int64_t)58LL);
g673 = ((int64_t)1LL);
g674 = ((int64_t)2LL);
g675 = ((int64_t)3LL);
g676 = ((int64_t)4LL);
g677 = ((int64_t)5LL);
g678 = ((int64_t)1LL);
g679 = ((int64_t)2LL);
g680 = ((int64_t)4LL);
g681 = ((int64_t)8LL);
g682 = ((int64_t)16LL);
g683 = ((int64_t)32LL);
g684 = ((int64_t)64LL);
g685 = ((int64_t)128LL);
g686 = ((int64_t)256LL);
g687 = ((int64_t)512LL);
g688 = ((int64_t)1LL);
g689 = ((int64_t)2LL);
g690 = ((int64_t)4LL);
g691 = ((int64_t)8LL);
g692 = ((int64_t)16LL);
g693 = ((int64_t)32LL);
g694 = ((int64_t)64LL);
g789 = ((int64_t)0LL);
g790 = ((int64_t)1LL);
g791 = ((int64_t)2LL);
g792 = ((int64_t)3LL);
g793 = ((int64_t)4LL);
g794 = ((int64_t)5LL);
g795 = ((int64_t)6LL);
g796 = ((int64_t)7LL);
g797 = ((int64_t)8LL);
g798 = ((int64_t)9LL);
g799 = ((int64_t)10LL);
g800 = ((int64_t)11LL);
g801 = ((int64_t)12LL);
g802 = ((int64_t)13LL);
g803 = ((int64_t)14LL);
g804 = ((int64_t)15LL);
g805 = ((int64_t)16LL);
g806 = ((int64_t)17LL);
g807 = ((int64_t)18LL);
g808 = ((int64_t)19LL);
g809 = ((int64_t)20LL);
g810 = ((int64_t)21LL);
g811 = ((int64_t)22LL);
g812 = ((int64_t)23LL);
g813 = ((int64_t)24LL);
g814 = ((int64_t)25LL);
g815 = ((int64_t)26LL);
g816 = ((int64_t)27LL);
g817 = ((int64_t)28LL);
g818 = ((int64_t)29LL);
g819 = ((int64_t)30LL);
g820 = ((int64_t)31LL);
g821 = ((int64_t)32LL);
g822 = ((int64_t)33LL);
g823 = ((int64_t)34LL);
g824 = ((int64_t)35LL);
g825 = ((int64_t)36LL);
g826 = ((int64_t)37LL);
g827 = ((int64_t)38LL);
g828 = ((int64_t)39LL);
g829 = ((int64_t)40LL);
g830 = ((int64_t)41LL);
g831 = ((int64_t)42LL);
g832 = ((int64_t)43LL);
g833 = ((int64_t)44LL);
g834 = ((int64_t)45LL);
g835 = ((int64_t)46LL);
g836 = ((int64_t)47LL);
g837 = ((int64_t)48LL);
g838 = ((int64_t)49LL);
g839 = ((int64_t)50LL);
g840 = ((int64_t)51LL);
g841 = ((int64_t)52LL);
g842 = ((int64_t)53LL);
g843 = ((int64_t)54LL);
g844 = ((int64_t)55LL);
g845 = ((int64_t)56LL);
g847 = ((int64_t)56LL);
g848 = ((int64_t)57LL);
g849 = ((int64_t)58LL);
g850 = ((int64_t)59LL);
g851 = ((int64_t)60LL);
g852 = ((int64_t)61LL);
g853 = ((int64_t)62LL);
g854 = ((int64_t)63LL);
g855 = ((int64_t)64LL);
g856 = ((int64_t)65LL);
g857 = ((int64_t)66LL);
g858 = ((int64_t)67LL);
g859 = ((int64_t)68LL);
g860 = ((int64_t)69LL);
g861 = ((int64_t)70LL);
g862 = ((int64_t)71LL);
g863 = ((int64_t)72LL);
g864 = ((int64_t)73LL);
g865 = ((int64_t)74LL);
g866 = ((int64_t)75LL);
g867 = ((int64_t)76LL);
g868 = ((int64_t)77LL);
g869 = ((int64_t)78LL);
g870 = ((int64_t)79LL);
g871 = ((int64_t)80LL);
g872 = ((int64_t)81LL);
g873 = ((int64_t)82LL);
g874 = ((int64_t)83LL);
g875 = ((int64_t)84LL);
g876 = ((int64_t)85LL);
g877 = ((int64_t)86LL);
g878 = ((int64_t)87LL);
g879 = ((int64_t)88LL);
g880 = ((int64_t)89LL);
g881 = ((int64_t)90LL);
g882 = ((int64_t)91LL);
g883 = ((int64_t)92LL);
g884 = ((int64_t)93LL);
g885 = ((int64_t)94LL);
g886 = ((int64_t)95LL);
g887 = ((int64_t)96LL);
g888 = ((int64_t)97LL);
g889 = ((int64_t)98LL);
g890 = ((int64_t)99LL);
g891 = ((int64_t)100LL);
g892 = ((int64_t)101LL);
g893 = ((int64_t)102LL);
g894 = ((int64_t)103LL);
g895 = ((int64_t)104LL);
g896 = ((int64_t)49LL);
}
static void hr_main(void) { f1_main(); }
