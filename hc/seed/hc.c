#include "hrt.h"
typedef struct A25 A25;
typedef struct A61 A61;
typedef struct A97 A97;
typedef struct S0 S0;
typedef struct S1 S1;
typedef struct S2 S2;
typedef struct S4 S4;
typedef struct L49 L49;
typedef struct S3 S3;
typedef struct A39 A39;
typedef struct S5 S5;
typedef struct S6 S6;
typedef struct M55 M55;
typedef struct S8 S8;
typedef struct S9 S9;
typedef struct L65 L65;
typedef struct M56 M56;
typedef struct S10 S10;
typedef struct S7 S7;
typedef struct L72 L72;
typedef struct S11 S11;
typedef struct M77 M77;
typedef struct S12 S12;
typedef struct S13 S13;
typedef struct L83 L83;
typedef struct S14 S14;
typedef struct L88 L88;
typedef struct L89 L89;
typedef struct M90 M90;
typedef struct L93 L93;
typedef struct L94 L94;
typedef struct L96 L96;
typedef struct L95 L95;
#pragma pack(push, 1)
struct A25 { hsl e[49]; };
struct A61 { hsl e[8]; };
struct A97 { double e[23]; };
struct S0 { int32_t s_; int32_t n_; };
struct S1 { uint8_t k_; uint8_t s_; uint16_t fl_; int32_t a_; int32_t c_; int32_t l_; int32_t n_; int64_t b_; };
struct S2 { int32_t s_; int32_t n_; int32_t name_; bool amni_; };
struct S4 { uint8_t k_; uint8_t op_; uint16_t fl_; int32_t t_; int32_t a_; int32_t b_; int32_t c_; int32_t d_; int32_t e_; int32_t s_; int32_t l_; int32_t n_; };
struct L49 { uint16_t n; uint8_t e[1024]; };
struct S3 { uint8_t k_; bool ml_; bool uns_; uint16_t f_; int32_t line_; int32_t s_; int32_t n_; int32_t w_; int64_t v_; };
struct A39 { hsl e[51]; };
struct S5 { uint8_t k_; int32_t node_; int32_t file_; int32_t next_; int32_t name_; };
struct S6 { int32_t node_; int32_t lo_; int32_t hi_; int32_t ab_; int32_t par_; int32_t cfn_; int32_t g0_; int32_t gn_; int32_t ret_; int32_t p0_; int32_t pn_; uint8_t st_; bool lr_; int32_t blk_; int32_t bown_; int32_t name_; uint16_t fl_; bool rinf_; };
struct M55 { int64_t r0; bool r1; };
struct S8 { int32_t node_; int32_t ta_; int32_t tn_; int32_t v0_; int32_t vnum_; uint8_t cls_; uint8_t done_; uint8_t tagsz_; bool flat_; int64_t size_; int32_t name_; };
struct S9 { int32_t name_; int32_t f0_; int32_t fnum_; int32_t si_; int64_t size_; bool haspay_; };
struct L65 { uint8_t n; int32_t e[16]; };
struct M56 { int64_t r0; int64_t r1; };
struct S10 { int32_t node_; int32_t ta_; int32_t tn_; int32_t f0_; int32_t fnum_; uint8_t cls_; uint8_t done_; bool flat_; bool zero_; int64_t size_; int32_t name_; };
struct S7 { int32_t name_; int32_t ty_; };
struct S11 { int32_t name_; int32_t ty_; int32_t def_; uint16_t fl_; int32_t padn_; int64_t off_; };
struct L72 { uint16_t n; S11 e[256]; };
struct M77 { int64_t r0; bool r1; bool r2; };
struct S12 { int32_t name_; int32_t ty_; uint16_t fl_; int32_t cfn_; int32_t own_; int32_t node_; int32_t cnt_; };
struct S13 { int32_t inst_; int32_t lv_; };
struct L83 { uint8_t n; int32_t e[1]; };
struct S14 { int32_t name_; int32_t node_; int32_t inst_; int32_t own_; };
struct L88 { uint8_t n; int32_t e[128]; };
struct L89 { uint8_t n; int32_t e[64]; };
struct M90 { int64_t r0; int64_t r1; int64_t r2; };
struct L93 { uint16_t n; uint8_t e[256]; };
struct L94 { uint8_t n; uint8_t e[128]; };
struct L96 { uint8_t n; uint8_t e[64]; };
struct L95 { uint8_t n; uint8_t e[32]; };
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
static void f24_put(int64_t k_54, int64_t s_55, int64_t e_56, int64_t *c48, int64_t *c53);
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
static int64_t f116_t_rel(int64_t e_514, int64_t fl_515, int64_t w_516, int64_t pool_517);
static int64_t f117_t_ref(int64_t e_518, int64_t fl_519);
static M55 f118_ceval(int64_t n_522, int64_t ns_523);
static int64_t f119_lookup_q(int64_t q_533, int64_t ns_534, int64_t k_535);
static M56 f120_split_q(int64_t q_536);
static int64_t f121_t_arr(int64_t e_550, int64_t ak_551, int64_t size_552, int64_t ls_553);
static int64_t f122_lim_lenstore(int64_t cap_556);
static int64_t f123_t_variant(int64_t ei_561, int64_t vi_562);
static hrv f124_ty_name(int64_t t_564);
static void f125_ty_name_into(int64_t t_566, hrv* out_567);
static void f126_ls_kind_name(int64_t s_570, hrv* out_571);
static void f127_targs_into(int64_t l_573, int64_t n_574, hrv* out_575);
static int64_t f128_gb_find(int64_t name_580);
static int64_t f129_inst_struct(int64_t node_587, hsl args_588);
static void f130_gen_names(int64_t gl_596, L65* out_597);
static int64_t f131_fields_into(int64_t node_601, int64_t ns_602);
static int32_t f132_max(int32_t a_607, int32_t b_608);
static int64_t f133_t_struct(int64_t si_612);
static int64_t f134_inst_enum(int64_t node_613, hsl args_614);
static int64_t f135_t_enum(int64_t ei_633, bool vm_634);
static int64_t f136_ck(int64_t n_638, int64_t want_639);
static int64_t f137_set_t(int64_t n_642, int64_t t_643);
static int64_t f138_aix(int64_t n_644);
static bool f139_conv(int64_t n_648, int64_t t_649);
static int64_t f140_at(int64_t n_650);
static int64_t f141_tclass(int64_t t_654);
static void f142_si_layout(int64_t si_657);
static int64_t f143_tsize(int64_t t_665);
static int64_t f144_isz(int64_t s_668);
static void f145_ei_layout(int64_t ei_669);
static bool f146_tflat(int64_t t_681);
static int64_t f147_cv(int64_t n_688);
static void f148_set_cv(int64_t n_689, int64_t t_690);
static bool f149_conv_ok(int64_t f_691, int64_t t_692, int64_t n_693);
static bool f150_widens(int64_t f_696, int64_t t_697);
static bool f151_is_signed(int64_t t_700);
static int64_t f152_ibits(int64_t t_703);
static bool f153_is_construct(int64_t n_704);
static M77 f154_cval(int64_t n_706);
static int64_t f155_rk(int64_t n_712);
static int64_t f156_rv(int64_t n_713);
static bool f157_int_fits(int64_t v_724, bool uns_725, int64_t t_726);
static int64_t f158_int_min(int64_t t_727);
static uint64_t f159_int_max_u(int64_t t_729);
static hrv f160_tn(int64_t t_733);
static void f161_commit(int64_t n_734, int64_t t_735);
static bool f162_is_pending(int64_t t_739);
static bool f163_is_byte_arr(int64_t t_745);
static bool f164_is_opt(int64_t t_748);
static int64_t f165_ck_id(int64_t n_749, int64_t want_750);
static int64_t f166_find_lv(int64_t name_752);
static bool f167_visible(int64_t own_755);
static void f168_set_r(int64_t n_758, int64_t k_759, int64_t v_760);
static void f169_note_cap(int64_t v_762);
static int64_t f170_const_of(int64_t d_768);
static bool f171_all_int(int64_t n_776);
static void f172_set_x(int64_t n_781, int64_t v_782);
static int64_t f173_ck_bin(int64_t n_784, int64_t want_785);
static int64_t f174_deref(int64_t t_793);
static int64_t f175_leaf_kind(int64_t t_798);
static int64_t f176_leaf_type(int64_t t_808);
static int64_t f177_unify(int64_t n_817, int64_t a_818, int64_t b_819);
static int64_t f178_ck_un(int64_t n_830, int64_t want_831);
static int64_t f179_default_t(int64_t n_836);
static int64_t f180_ck_dot(int64_t n_857, int64_t want_858);
static int64_t f181_rtype_name_enum(int64_t de_864);
static int64_t f182_sfield(int64_t si_876, int64_t name_877);
static int64_t f183_ck_idx(int64_t n_884, int64_t want_885);
static int64_t f184_ck_slice(int64_t n_893, int64_t want_894);
static int64_t f185_ck_as(int64_t n_900, int64_t want_901);
static int64_t f186_ck_arr(int64_t n_906, int64_t want_907);
static int64_t f187_ck_block(int64_t n_915, int64_t want_916);
static void f188_cstmt(int64_t n_920);
static void f189_ck_vdecl(int64_t n_923);
static int64_t f190_fin_t(int64_t n_936);
static int64_t f191_add_lv(int64_t name_938, int64_t t_939, int64_t fl_940, int64_t node_941);
static bool f192_is_fixed(int64_t t_949);
static void f193_ck_assign(int64_t n_951);
static void f194_decl_nested(int64_t n_966);
static void f195_sig_inst(int64_t i_968);
static int64_t f196_upname(int64_t p_978);
static int64_t f197_tlist(int64_t k_984, hsl xs_985, int64_t a_986);
static bool f198_surely_void(int64_t fnode_988);
static bool f199_has_valret(int64_t n_992);
static void f200_check_inst(int64_t i_996);
static int64_t f201_ptype_of(int64_t i_1008, int64_t j_1009);
static bool f202_ends(int64_t n_1018);
static bool f203_has_break(int64_t n_1021);
static int64_t f204_ck_if(int64_t n_1030, int64_t want_1031);
static int64_t f205_narrow_of(int64_t c_1034);
static int64_t f206_ck_while(int64_t n_1045);
static int64_t f207_ck_loop(int64_t n_1049, int64_t want_1050);
static int64_t f208_ck_for(int64_t n_1052);
static int64_t f209_ax(int64_t n_1065);
static int64_t f210_ck_match(int64_t n_1066, int64_t want_1067);
static int64_t f211_ck_ret(int64_t n_1100);
static int64_t f212_ret_fn(void);
static int64_t f213_ck_break(int64_t n_1114);
static int64_t f214_ck_call(int64_t n_1118, int64_t want_1119);
static int64_t f215_find_nest(int64_t name_1125);
static int64_t f216_call_nested(int64_t n_1128, int64_t nf_1129);
static int64_t f217_ck_args(int64_t n_1131, int64_t a0n_1132, int64_t first_1133);
static void f218_pop_args(int64_t s_1140);
static void f219_note_caps_of(int64_t i_1141);
static int64_t f220_block_binding(int64_t name_1144);
static int64_t f221_blk_gen(int64_t fnode_1148);
static int64_t f222_gen_list(int64_t fnode_1149);
static bool f223_is_blockparam(int64_t fnode_1153, int64_t gname_1154);
static bool f224_mentions(int64_t t_1157, int64_t g_1158);
static int64_t f225_call_block(int64_t n_1163, int64_t inst_1164);
static int64_t f226_deref_val(int64_t a_1171);
static int64_t f227_builtin_of(hsl name_1191);
static bool f228_user_format(int64_t n_1193);
static void f229_cands_add(int64_t name_1195, int64_t ns_1196);
static bool f230_is_std_node(int64_t node_1205);
static int64_t f231_ck_builtin(int64_t n_1208, int64_t b_1209, int64_t recv_1210, int64_t want_1211);
static int64_t f232_arg(int64_t i_1214, int64_t *c1210, int64_t *c1208);
static int64_t f233_call_fn(int64_t n_1241, int64_t name_1242, int64_t recv_1243, int64_t want_1244);
static M90 f234_resolve(int64_t n_1248, int64_t name_1249, int64_t ns_1250, int64_t a0_1251, int64_t an_1252, int64_t blk_1253, int64_t tyargs_1254, bool report_1255);
static bool f235_match_ty(int64_t tn0_1279, int64_t t0_1280, int64_t g0_1281);
static int64_t f236_pend_default(int64_t a_1294);
static int64_t f237_arg_rank(int64_t n_1307, int64_t a_1308, int64_t p_1309);
static bool f238_untyped_any(int64_t f_1318);
static int64_t f239_get_inst(int64_t node_1328, int64_t b0_1329, int64_t bn_1330, int64_t blk_1331, int64_t bown_1332);
static bool f240_same_binds(int64_t i_1336, int64_t b0_1337, int64_t bn_1338);
static int64_t f241_member_of(hsl name_1352);
static int64_t f242_ck_slit(int64_t n_1355, int64_t want_1356);
static bool f243_ORD_HAS(int64_t d_1379);
static bool f244_gen_program(hrv* out_1385);
static void f245_ow(hsl s_1391);
static void f246_ct(int64_t t_1392);
static void f247_cbody(int64_t t_1393);
static void f248_cn_grow(void);
static hsl f249_cn(int64_t t_1396);
static void f250_cn_make(int64_t t_1397);
static void f251_fwd(int64_t s0_1406);
static void f252_fname_into(hrv* b_1418, int64_t name_1419);
static bool f253_is_res(int64_t t_1434);
static void f254_gxo(int64_t n_1435);
static void f255_gcv(int64_t n_1438, int64_t f_1439, int64_t t_1440);
static void f256_gx1(int64_t n_1441);
static bool f257_is_place(int64_t n_1442);
static int64_t f258_tmp(int64_t t_1447, bool clean_1448);
static void f259_ot(int64_t k_1450);
static void f260_gx0(int64_t n_1451);
static int64_t f261_fin_lit(int64_t n_1454);
static void f262_oint(int64_t v_1456, bool uns_1457, int64_t t_1458);
static void f263_gstr(int64_t n_1461);
static int64_t f264_fin(int64_t n_1462);
static hsl f265_tok_str(int64_t t_1466);
static void f266_cstr_lit(hsl s_1470);
static bool f267_is_fix(int64_t t_1472);
static bool f268_is_lim(int64_t t_1473);
static void f269_lv_expr(int64_t v_1475);
static bool f270_lv_isptr(int64_t v_1476);
static void f271_lv_name(int64_t v_1478);
static void f272_gerr(int64_t n_1480, hsl m_1481);
static void f273_gbin(int64_t n_1483);
static void f274_gx(int64_t n_1488);
static hsl f275_cmp_op(int64_t o_1495);
static void f276_gas(int64_t n_1496);
static void f277_gsl(int64_t n_1499, int64_t f_1500);
static int64_t f278_nt(void);
static void f279_oi(int64_t v_1504);
static void f280_gen_heq(int64_t t_1510);
static void f281_comp_pre(int64_t t_1514, bool fmt_1515);
static void f282_comp_one(int64_t t_1521, bool fmt_1522);
static bool f283_need_helper(int64_t t_1524);
static void f284_gen_hf(int64_t t_1526);
static void f285_hf_pre(int64_t t_1530);
static void f286_hh(hsl s_1533);
static void f287_hf_val(int64_t t_1541, hsl e_1542);
static void f288_heq_val(int64_t t_1585, hsl a_1586, hsl b_1587);
static bool f289_hsl_ty(int64_t t_1598);
static void f290_gxas(int64_t n_1599, int64_t t_1600);
static void f291_garith(int64_t o_1603, int64_t t0_1604, int64_t a_1605, int64_t b_1606, int64_t tv_1607, int64_t loc_1608);
static void f292_gopnd(int64_t n_1614, int64_t tv_1615);
static void f293_gen_hop(int64_t t_1616, int64_t o_1617, int64_t bt_1618);
static void f294_hop_body(int64_t t_1624, int64_t o_1625, hsl r_1626, hsl a_1627, hsl b_1628, bool sc_1629);
static hsl f295_ar_op(int64_t o_1631);
static void f296_wloc(int64_t n_1645);
static void f297_gun(int64_t n_1648);
static void f298_gen_hneg(int64_t t_1653);
static void f299_gidx(int64_t n_1665);
static void f300_gslice(int64_t n_1673);
static void f301_garr(int64_t n_1680);
static void f302_gslit(int64_t n_1687);
static void f303_gcall(int64_t n_1699);
static void f304_gbuiltin(int64_t n_1701);
static int64_t f305_arg(int64_t i_1707, int64_t *c1705, int64_t *c1701);
static void f306_gfmt(hsl o_1711, int64_t n_1712, int64_t t_1713, bool top_1714);
static void f307_grecv_ptr(int64_t r_1721);
static void f308_esz(int64_t t_1735);
static void f309_gaddr(int64_t n_1739);
static void f310_heq_val_o(int64_t e_1748, int64_t p_1749);
static void f311_heq_o(int64_t e_1752, hsl a_1753, hsl b_1754);
static void f312_heq_pre(int64_t t_1755);
static bool f313_scalar_ty(int64_t t_1756);
static void f314_heq_val_s(int64_t e_1759, int64_t p_1760);
static void f315_heq_val_r(int64_t e_1763, int64_t p_1764);
static void f316_gblkcall(int64_t n_1767);
static void f317_gstmt(int64_t n_1779);
static void f318_gvdecl(int64_t n_1785);
static void f319_decl_lv(int64_t v_1793);
static void f320_gstmt1(int64_t n_1804);
static void f321_gassign(int64_t n_1807);
static int64_t f322_base_op(int64_t o_1818);
static void f323_gif(int64_t n_1821, int64_t res_1822);
static void f324_gblk(int64_t b_1826, int64_t res_1827, bool val_1828);
static void f325_gtail(int64_t tl_1830, int64_t res_1831);
static void f326_gwhile(int64_t n_1834);
static int64_t f327_lbl_push(int64_t res_1836);
static void f328_lbl_pop(int64_t l_1839);
static void f329_gloop(int64_t n_1840, int64_t res_1841);
static void f330_gfor(int64_t n_1843);
static void f331_gmatch(int64_t n_1856, int64_t res_1857);
static void f332_geblock(int64_t n_1879, int64_t res_1880);
static void f333_gret(int64_t n_1882);
static void f334_gbreak(int64_t n_1889);
static bool f335_owned(int64_t n_1893);
static bool f336_is_ext(int64_t i_1897);
static void f337_ext_name(int64_t i_1898);
static void f338_fn_cname(int64_t i_1902);
static void f339_gcall_args(int64_t n_1905, int64_t inst_1906, int64_t recv_1907);
static void f340_lv_addr(int64_t v_1919);
static void f341_gen_fn(int64_t i_1934);
static void f342_gsig(int64_t i_1937);
static hrv g468;
static hrv g882;
static A25 g825;
static hrv g883;
static hrv g880;
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
static hrv g524;
static int64_t g548;
static hrv g526;
static hrv g525;
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
static int64_t g550;
static int64_t g551;
static int64_t g549;
static hrv g467;
static hrv g884;
static hrv g678;
static hrv g885;
static hrv g886;
static hrv g879;
static hrv g881;
static hrv g681;
static int64_t g680;
static int64_t g688;
static int64_t g687;
static int64_t g682;
static bool g683;
static hrv g675;
static hrv g677;
static bool g727;
static hrv g689;
static hrv g676;
static bool g684;
static bool g685;
static bool g686;
static hrv g690;
static hrv g679;
static hrv g470;
static hrv g471;
static hrv g465;
static hrv g464;
static hrv g469;
static int64_t g384;
static hrv g371;
static hrv g376;
static hrv g375;
static hrv g377;
static hrv g378;
static hrv g379;
static hrv g380;
static int64_t g382;
static int64_t g383;
static int64_t g386;
static hrv g385;
static hrv g426;
static hrv g427;
static hrv g529;
static hrv g530;
static hrv g527;
static hrv g466;
static hrv g528;
static hrv g412;
static hrv g373;
static hrv g372;
static hrv g374;
static hrv g413;
static hrv g306;
static int64_t g388;
static hrv g444;
static hrv g389;
static hrv g310;
static hrv g307;
static hrv g308;
static hrv g390;
static hrv g163;
static int64_t g179;
static hrv g171;
static hrv g172;
static hrv g173;
static hrv g174;
static hrv g175;
static hrv g170;
static A61 g183;
static hrv g164;
static hrv g165;
static hrv g167;
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
static A97 g114;
static hrv g154;
static int64_t g284;
static int64_t g285;
static int64_t g286;
static int64_t g287;
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
static hrv g309;
static int64_t g347;
static int64_t g348;
static int64_t g349;
static int64_t g350;
static int64_t g351;
static int64_t g352;
static int64_t g353;
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
static int64_t g381;
static int64_t g387;
static int64_t g457;
static int64_t g458;
static int64_t g459;
static int64_t g460;
static int64_t g461;
static int64_t g494;
static int64_t g495;
static int64_t g496;
static int64_t g497;
static int64_t g498;
static int64_t g499;
static int64_t g500;
static int64_t g501;
static int64_t g502;
static int64_t g503;
static int64_t g504;
static int64_t g505;
static int64_t g506;
static int64_t g507;
static int64_t g508;
static int64_t g509;
static int64_t g510;
static int64_t g511;
static int64_t g512;
static int64_t g513;
static int64_t g514;
static int64_t g515;
static int64_t g516;
static int64_t g517;
static int64_t g518;
static int64_t g589;
static int64_t g597;
static int64_t g598;
static int64_t g599;
static int64_t g600;
static int64_t g601;
static int64_t g602;
static int64_t g603;
static int64_t g604;
static int64_t g605;
static int64_t g606;
static int64_t g607;
static int64_t g608;
static int64_t g609;
static int64_t g610;
static int64_t g611;
static int64_t g612;
static int64_t g613;
static int64_t g614;
static int64_t g615;
static int64_t g616;
static int64_t g617;
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
static int64_t g768;
static int64_t g769;
static int64_t g770;
static int64_t g771;
static int64_t g772;
static int64_t g773;
static int64_t g774;
static int64_t g775;
static int64_t g776;
static int64_t g777;
static int64_t g778;
static int64_t g779;
static int64_t g780;
static int64_t g781;
static int64_t g782;
static int64_t g783;
static int64_t g784;
static int64_t g785;
static int64_t g786;
static int64_t g787;
static int64_t g788;
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
static int64_t g871;
static int64_t g872;
static int64_t g873;
static int64_t g874;
static int64_t g875;
static void f1_main(void) {
hrv a_0 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
hrv o_1 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if (((hr_os_arg_count()) < (((int64_t)3LL)))) { (void)(({ hr_fs(&hr_ob, hr_str("usage: hc file.amni out.c", 25)); hr_println(); }));
(void)(hr_exit(((int64_t)2LL)));
 }
(void)(hr_os_arg(((int64_t)1LL), (&(a_0))));
(void)(hr_os_arg(((int64_t)2LL), (&(o_1))));
hrv lib_2 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(hr_os_getenv(hr_str("HC_LIB", 6), (&(lib_2)))))) { (void)(({ hrv *_v10 = &(lib_2); hsl _s10 = hr_str("hc/lib", 6); hr_append(_v10, _s10.p, _s10.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v11 = &(g468); hsl _s11 = hr_sl(lib_2); hr_append(_v11, _s11.p, _s11.n, sizeof(uint8_t)); }));
if ((!(f5_load_program(hr_sl(a_0))))) { (void)(({ hr_fs(&hr_ob, hr_sl(g470)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((!(f104_check_program()))) { (void)(({ hr_fs(&hr_ob, hr_sl(g385)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((((g470).n) > (((int64_t)0LL)))) { (void)(({ hr_fs(&hr_ob, hr_sl(g470)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
hrv c_1384 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(f244_gen_program((&(c_1384)))))) { (void)(({ hr_fs(&hr_ob, hr_sl(g182)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((!(hr_os_write_file(hr_sl(o_1), hr_sl(c_1384))))) { (void)(({ hr_fs(&hr_ob, hr_str("cannot write ", 13)); hr_fs(&hr_ob, hr_sl(o_1)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
}
static bool f5_load_program(hsl root_3) {
(void)(f6_parse_init());
(void)(f11_types_init());
int64_t d_38 = (root_3).n; 
while ((((d_38) > (((int64_t)0LL))) && (((*({ hsl _t24 = root_3; int64_t _i24 = ((int64_t)((int64_t)d_38 - (int64_t)((int64_t)1LL))); (uint8_t*)_t24.p + hr_ix(_i24, _t24.n, "hc/decl.amni:68"); }))) != (((uint8_t)47LL))))) { d_38--;
 } _bk23:; 
(void)(({ hrv *_v25 = &(g467); _v25->n = 0; }));
(void)(({ hrv *_v26 = &(g467); hsl _s26 = ({ hsl _r27; if (((d_38) > (((int64_t)0LL)))) { _r27 = ({ hsl _t28 = root_3; int64_t _l28 = 0, _h28 = ((int64_t)((int64_t)d_38 - (int64_t)((int64_t)1LL))); if (_l28 < 0 || _h28 < _l28 || _h28 > _t28.n) hr_slerr(_l28, _h28, _t28.n, "hc/decl.amni:69"); (hsl){ _t28.p + _l28 * (int64_t)sizeof(uint8_t), _h28 - _l28 }; });  } else { _r27 = hr_str(".", 1);  } _r27; }); hr_append(_v26, _s26.p, _s26.n, sizeof(uint8_t)); }));
return (((f19_try_load(root_3)) >= (((int64_t)0LL))) && (((g470).n) == (((int64_t)0LL))));
}
static void f6_parse_init(void) {
(void)(f7_lex_init());
if (((g692) < (((int64_t)0LL)))) { g692 = f8_intern(hr_str("from", 4));
g693 = f8_intern(hr_str("inline", 6));
g694 = f8_intern(hr_str("checkfree", 9));
g695 = f8_intern(hr_str("lut", 3));
g696 = f8_intern(hr_str("_", 1));
g697 = f8_intern(hr_str("upto", 4));
g698 = f8_intern(hr_str("fields", 6));
g699 = f8_intern(hr_str("types", 5));
g700 = f8_intern(hr_str("variants", 8));
g701 = f8_intern(hr_str("std", 3));
 }
}
static void f7_lex_init(void) {
if ((((g882).n) == (((int64_t)0LL)))) { { hsl _v30 = ({ A25 *_t31 = &(g825); (hsl){ (uint8_t*)_t31->e, 49 }; }); for (int64_t _k30 = 0; _k30 < _v30.n; _k30++) { hsl k_4 = ((hsl*)_v30.p)[_k30]; (void)(f8_intern(k_4));
 } } _bk29:; 
 }
}
static int64_t f8_intern(hsl s_5) {
if ((((g883).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v32 = &(g883); int64_t _k32 = ((int64_t)((((int64_t)1LL)) << ((((int64_t)16LL)) & 63))); if (_k32 < 0) hr_die("resize to a negative length", "hc/lex.amni:32"); int32_t _x32 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o32 = _v32->n; hr_resize(_v32, _k32, sizeof _x32); for (int64_t _j = _o32; _j < _k32; _j++) ((int32_t*)_v32->b)[_j] = _x32; }));
 }
if (((((int64_t)((int64_t)(g882).n * (int64_t)((int64_t)2LL)))) >= ((g883).n))) { int64_t n_6 = ((int64_t)((int64_t)(g883).n * (int64_t)((int64_t)2LL))); 
(void)(({ hrv *_v33 = &(g883); _v33->n = 0; }));
(void)(({ hrv *_v34 = &(g883); int64_t _k34 = n_6; if (_k34 < 0) hr_die("resize to a negative length", "hc/lex.amni:35"); int32_t _x34 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o34 = _v34->n; hr_resize(_v34, _k34, sizeof _x34); for (int64_t _j = _o34; _j < _k34; _j++) ((int32_t*)_v34->b)[_j] = _x34; }));
{ hrv *_v36 = &(g882); for (int64_t _k36 = 0; _k36 < _v36->n; _k36++) { S0 x_7 = ((S0*)_v36->b)[_k36]; int64_t i_8 = _k36; int64_t j_12 = ((int64_t)((int64_t)((int64_t)(f9_hash(({ hsl _t37 = hr_sl(g880); int64_t _l37 = ((int64_t)((x_7).s_)), _h37 = ((int64_t)(((int32_t)((int64_t)(x_7).s_ + (int64_t)(x_7).n_)))); if (_l37 < 0 || _h37 < _l37 || _h37 > _t37.n) hr_slerr(_l37, _h37, _t37.n, "hc/lex.amni:36"); (hsl){ _t37.p + _l37 * (int64_t)sizeof(uint8_t), _h37 - _l37 }; })))) & (int64_t)((int64_t)((int64_t)n_6 - (int64_t)((int64_t)1LL))))); 
while ((((*({ hrv *_t39 = &(g883); int64_t _i39 = j_12; (int32_t*)_t39->b + hr_ix(_i39, _t39->n, "hc/lex.amni:36"); }))) >= (((int32_t)0LL)))) { j_12 = ((int64_t)((int64_t)((int64_t)((int64_t)j_12 + (int64_t)((int64_t)1LL))) & (int64_t)((int64_t)((int64_t)n_6 - (int64_t)((int64_t)1LL)))));
 } _bk38:; 
(*({ hrv *_t40 = &(g883); int64_t _i40 = j_12; (int32_t*)_t40->b + hr_ix(_i40, _t40->n, "hc/lex.amni:36"); })) = ((int32_t)(i_8));
 } } _bk35:; 
 }
int64_t m_13 = ((int64_t)((int64_t)(g883).n - (int64_t)((int64_t)1LL))); 
int64_t j_14 = ((int64_t)((int64_t)((int64_t)(f9_hash(s_5))) & (int64_t)m_13)); 
while ((((*({ hrv *_t42 = &(g883); int64_t _i42 = j_14; (int32_t*)_t42->b + hr_ix(_i42, _t42->n, "hc/lex.amni:40"); }))) >= (((int32_t)0LL)))) { if (hr_streq(f10_nm(((int64_t)((*({ hrv *_t43 = &(g883); int64_t _i43 = j_14; (int32_t*)_t43->b + hr_ix(_i43, _t43->n, "hc/lex.amni:40"); }))))), s_5)) { return ((int64_t)((*({ hrv *_t44 = &(g883); int64_t _i44 = j_14; (int32_t*)_t44->b + hr_ix(_i44, _t44->n, "hc/lex.amni:40"); }))));
 }
j_14 = ((int64_t)((int64_t)((int64_t)((int64_t)j_14 + (int64_t)((int64_t)1LL))) & (int64_t)m_13));
 } _bk41:; 
int64_t id_17 = (g882).n; 
(void)(({ hrv *_v45 = &(g882); S0 _x45 = ((S0){ .s_ = ((int32_t)((g880).n)), .n_ = ((int32_t)((s_5).n)), }); S0 *_p45 = (S0*)hr_grow(_v45, 1, sizeof _x45); *_p45 = _x45; _p45; }));
(void)(({ hrv *_v46 = &(g880); hsl _s46 = s_5; hr_append(_v46, _s46.p, _s46.n, sizeof(uint8_t)); }));
(*({ hrv *_t47 = &(g883); int64_t _i47 = j_14; (int32_t*)_t47->b + hr_ix(_i47, _t47->n, "hc/lex.amni:44"); })) = ((int32_t)(id_17));
return id_17;
}
static uint64_t f9_hash(hsl s_9) {
uint64_t h_10 = ((uint64_t)1469598103934665603LL); 
{ hsl _v49 = s_9; for (int64_t _k49 = 0; _k49 < _v49.n; _k49++) { uint8_t c_11 = ((uint8_t*)_v49.p)[_k49]; h_10 = ((uint64_t)((uint64_t)((uint64_t)((uint64_t)h_10 ^ (uint64_t)((uint64_t)(c_11)))) * (uint64_t)((uint64_t)1099511628211LL)));
 } } _bk48:; 
return h_10;
}
static hsl f10_nm(int64_t id_15) {
S0 x_16 = (*({ hrv *_t50 = &(g882); int64_t _i50 = id_15; (S0*)_t50->b + hr_ix(_i50, _t50->n, "hc/lex.amni:29"); })); 
return ({ hsl _t51 = hr_sl(g880); int64_t _l51 = ((int64_t)((x_16).s_)), _h51 = ((int64_t)(((int32_t)((int64_t)(x_16).s_ + (int64_t)(x_16).n_)))); if (_l51 < 0 || _h51 < _l51 || _h51 > _t51.n) hr_slerr(_l51, _h51, _t51.n, "hc/lex.amni:29"); (hsl){ _t51.p + _l51 * (int64_t)sizeof(uint8_t), _h51 - _l51 }; });
}
static void f11_types_init(void) {
if ((((g524).n) > (((int64_t)0LL)))) { return;
 }
g548 = f12_tsimple(((int64_t)0LL), ((int64_t)0LL));
g531 = f12_tsimple(((int64_t)1LL), ((int64_t)0LL));
g532 = f12_tsimple(((int64_t)2LL), ((int64_t)0LL));
g533 = f17_t_int(((int64_t)0LL));
g534 = f17_t_int(((int64_t)1LL));
g535 = f17_t_int(((int64_t)2LL));
g536 = f17_t_int(((int64_t)3LL));
g537 = f17_t_int(((int64_t)4LL));
g538 = f17_t_int(((int64_t)5LL));
g539 = f17_t_int(((int64_t)6LL));
g540 = f17_t_int(((int64_t)7LL));
g541 = f12_tsimple(((int64_t)4LL), ((int64_t)4LL));
g542 = f12_tsimple(((int64_t)4LL), ((int64_t)8LL));
g543 = f12_tsimple(((int64_t)11LL), ((int64_t)0LL));
g544 = f12_tsimple(((int64_t)12LL), ((int64_t)0LL));
g545 = f12_tsimple(((int64_t)13LL), ((int64_t)0LL));
g546 = f12_tsimple(((int64_t)18LL), ((int64_t)0LL));
g547 = f12_tsimple(((int64_t)17LL), ((int64_t)0LL));
g550 = f12_tsimple(((int64_t)19LL), ((int64_t)0LL));
g551 = f12_tsimple(((int64_t)15LL), ((int64_t)0LL));
g549 = f18_t_slice(g537, true);
}
static int64_t f12_tsimple(int64_t k_18, int64_t s_19) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(k_18)), .s_ = ((uint8_t)(s_19)), .a_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f13_tmk(S1 t_20) {
if ((((g526).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v52 = &(g526); int64_t _k52 = ((int64_t)((((int64_t)1LL)) << ((((int64_t)14LL)) & 63))); if (_k52 < 0) hr_die("resize to a negative length", "hc/types.amni:27"); int32_t _x52 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o52 = _v52->n; hr_resize(_v52, _k52, sizeof _x52); for (int64_t _j = _o52; _j < _k52; _j++) ((int32_t*)_v52->b)[_j] = _x52; }));
 }
if (((((int64_t)((int64_t)(g524).n * (int64_t)((int64_t)2LL)))) >= ((g526).n))) { int64_t n_21 = ((int64_t)((int64_t)(g526).n * (int64_t)((int64_t)2LL))); 
(void)(({ hrv *_v53 = &(g526); _v53->n = 0; }));
(void)(({ hrv *_v54 = &(g526); int64_t _k54 = n_21; if (_k54 < 0) hr_die("resize to a negative length", "hc/types.amni:29"); int32_t _x54 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o54 = _v54->n; hr_resize(_v54, _k54, sizeof _x54); for (int64_t _j = _o54; _j < _k54; _j++) ((int32_t*)_v54->b)[_j] = _x54; }));
{ hrv *_v56 = &(g524); for (int64_t _k56 = 0; _k56 < _v56->n; _k56++) { S1 x_22 = ((S1*)_v56->b)[_k56]; int64_t i_23 = _k56; int64_t j_29 = ((int64_t)((int64_t)((int64_t)(f14_th(x_22))) & (int64_t)((int64_t)((int64_t)n_21 - (int64_t)((int64_t)1LL))))); 
while ((((*({ hrv *_t58 = &(g526); int64_t _i58 = j_29; (int32_t*)_t58->b + hr_ix(_i58, _t58->n, "hc/types.amni:30"); }))) >= (((int32_t)0LL)))) { j_29 = ((int64_t)((int64_t)((int64_t)((int64_t)j_29 + (int64_t)((int64_t)1LL))) & (int64_t)((int64_t)((int64_t)n_21 - (int64_t)((int64_t)1LL)))));
 } _bk57:; 
(*({ hrv *_t59 = &(g526); int64_t _i59 = j_29; (int32_t*)_t59->b + hr_ix(_i59, _t59->n, "hc/types.amni:30"); })) = ((int32_t)(i_23));
 } } _bk55:; 
 }
int64_t m_30 = ((int64_t)((int64_t)(g526).n - (int64_t)((int64_t)1LL))); 
int64_t j_31 = ((int64_t)((int64_t)((int64_t)(f14_th(t_20))) & (int64_t)m_30)); 
while ((((*({ hrv *_t61 = &(g526); int64_t _i61 = j_31; (int32_t*)_t61->b + hr_ix(_i61, _t61->n, "hc/types.amni:34"); }))) >= (((int32_t)0LL)))) { if (f16_teq((*({ hrv *_t62 = &(g524); int64_t _i62 = (*({ hrv *_t63 = &(g526); int64_t _i63 = j_31; (int32_t*)_t63->b + hr_ix(_i63, _t63->n, "hc/types.amni:34"); })); (S1*)_t62->b + hr_ix(_i62, _t62->n, "hc/types.amni:34"); })), t_20)) { return ((int64_t)((*({ hrv *_t64 = &(g526); int64_t _i64 = j_31; (int32_t*)_t64->b + hr_ix(_i64, _t64->n, "hc/types.amni:34"); }))));
 }
j_31 = ((int64_t)((int64_t)((int64_t)((int64_t)j_31 + (int64_t)((int64_t)1LL))) & (int64_t)m_30));
 } _bk60:; 
(void)(({ hrv *_v65 = &(g524); S1 _x65 = t_20; S1 *_p65 = (S1*)hr_grow(_v65, 1, sizeof _x65); *_p65 = _x65; _p65; }));
(*({ hrv *_t66 = &(g526); int64_t _i66 = j_31; (int32_t*)_t66->b + hr_ix(_i66, _t66->n, "hc/types.amni:35"); })) = ((int32_t)(((int64_t)((int64_t)(g524).n - (int64_t)((int64_t)1LL)))));
return ((int64_t)((int64_t)(g524).n - (int64_t)((int64_t)1LL)));
}
static uint64_t f14_th(S1 t_24) {
uint64_t h_27 = f15_hash_mix(((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((t_24).k_)) | (uint64_t)((uint64_t)((((uint64_t)((t_24).s_))) << ((((uint64_t)8LL)) & 63))))) | (uint64_t)((uint64_t)((((uint64_t)((t_24).fl_))) << ((((uint64_t)16LL)) & 63))))) | (uint64_t)((uint64_t)((((uint64_t)((t_24).a_))) << ((((uint64_t)32LL)) & 63)))))); 
h_27 = f15_hash_mix(((uint64_t)((uint64_t)((uint64_t)((uint64_t)h_27 ^ (uint64_t)((uint64_t)((t_24).c_)))) ^ (uint64_t)((uint64_t)((((uint64_t)((t_24).b_))) << ((((uint64_t)20LL)) & 63))))));
{ int32_t _e68 = (t_24).n_; for (int32_t i_28 = 0; i_28 < _e68; i_28++) { h_27 = f15_hash_mix(((uint64_t)((uint64_t)h_27 ^ (uint64_t)((uint64_t)((*({ hrv *_t69 = &(g525); int64_t _i69 = ((int64_t)((int64_t)((int64_t)((t_24).l_)) + (int64_t)((int64_t)(i_28)))); (int32_t*)_t69->b + hr_ix(_i69, _t69->n, "hc/types.amni:20"); })))))));
 } } _bk67:; 
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
{ int32_t _e71 = (x_32).n_; for (int32_t i_34 = 0; i_34 < _e71; i_34++) { if ((((*({ hrv *_t72 = &(g525); int64_t _i72 = ((int64_t)((int64_t)((int64_t)((x_32).l_)) + (int64_t)((int64_t)(i_34)))); (int32_t*)_t72->b + hr_ix(_i72, _t72->n, "hc/types.amni:23"); }))) != ((*({ hrv *_t73 = &(g525); int64_t _i73 = ((int64_t)((int64_t)((int64_t)((y_33).l_)) + (int64_t)((int64_t)(i_34)))); (int32_t*)_t73->b + hr_ix(_i73, _t73->n, "hc/types.amni:23"); }))))) { return false;
 }
 } } _bk70:; 
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
{ hrv *_v75 = &(g884); for (int64_t _k75 = 0; _k75 < _v75->n; _k75++) { S2 f_41 = ((S2*)_v75->b)[_k75]; int64_t i_42 = _k75; if (((((int64_t)((f_41).name_))) == (id_40))) { return i_42;
 }
 } } _bk74:; 
if ((!(hr_os_file_exists(path_39)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t t0_43 = (g678).n; 
if ((!(f21_parse_file(path_39)))) { (void)(({ hrv *_v76 = &(g470); hsl _s76 = hr_sl(g681); hr_append(_v76, _s76.p, _s76.n, sizeof(uint8_t)); }));
return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
int64_t f_439 = ((int64_t)((int64_t)(g884).n - (int64_t)((int64_t)1LL))); 
while ((((g471).n) < ((g884).n))) { (void)(({ hrv *_v78 = &(g471); int32_t _x78 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p78 = (int32_t*)hr_grow(_v78, 1, sizeof _x78); *_p78 = _x78; _p78; }));
 } _bk77:; 
(*({ hrv *_t79 = &(g471); int64_t _i79 = f_439; (int32_t*)_t79->b + hr_ix(_i79, _t79->n, "hc/decl.amni:45"); })) = (*({ hrv *_t80 = &(g679); int64_t _i80 = ((int64_t)((int64_t)(g679).n - (int64_t)((int64_t)1LL))); (int32_t*)_t80->b + hr_ix(_i80, _t80->n, "hc/decl.amni:45"); }));
(void)(f97_collect(f_439, t0_43, (g678).n));
int64_t t1_455 = (g678).n; 
int64_t im0_456 = (g469).n; 
{ int64_t _e82 = t1_455; for (int64_t i_457 = t0_43; i_457 < _e82; i_457++) { if (((((*({ hrv *_t83 = &(g675); int64_t _i83 = (*({ hrv *_t84 = &(g678); int64_t _i84 = i_457; (int32_t*)_t84->b + hr_ix(_i84, _t84->n, "hc/decl.amni:49"); })); (S4*)_t83->b + hr_ix(_i83, _t83->n, "hc/decl.amni:49"); }))).k_) == (((uint8_t)54LL)))) { (void)(({ hrv *_v85 = &(g469); int32_t _x85 = (*({ hrv *_t86 = &(g678); int64_t _i86 = i_457; (int32_t*)_t86->b + hr_ix(_i86, _t86->n, "hc/decl.amni:49"); })); int32_t *_p85 = (int32_t*)hr_grow(_v85, 1, sizeof _x85); *_p85 = _x85; _p85; }));
 }
 } } _bk81:; 
int64_t im1_458 = (g469).n; 
L49 sp_461 = f100_lib_path(hr_str("std", 3)); 
bool isstd_462 = hr_streq(path_39, ({ hsl _t87 = ({ L49 *_t88 = &(sp_461); (hsl){ (uint8_t*)_t88->e, _t88->n }; }); int64_t _l87 = 0, _h87 = _t87.n; if (_l87 < 0 || _h87 < _l87 || _h87 > _t87.n) hr_slerr(_l87, _h87, _t87.n, "hc/decl.amni:51"); (hsl){ _t87.p + _l87 * (int64_t)sizeof(uint8_t), _h87 - _l87 }; })); 
if ((((*({ hrv *_t89 = &(g884); int64_t _i89 = f_439; (S2*)_t89->b + hr_ix(_i89, _t89->n, "hc/decl.amni:52"); }))).amni_ && (!(isstd_462)))) { if (((f101_load_import(g701, f_439, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
 }
{ int64_t _e91 = im1_458; for (int64_t q_475 = im0_456; q_475 < _e91; q_475++) { int64_t n_476 = ((int64_t)((*({ hrv *_t92 = &(g469); int64_t _i92 = q_475; (int32_t*)_t92->b + hr_ix(_i92, _t92->n, "hc/decl.amni:53"); })))); 
if (((f101_load_import(((int64_t)(((*({ hrv *_t93 = &(g675); int64_t _i93 = n_476; (S4*)_t93->b + hr_ix(_i93, _t93->n, "hc/decl.amni:53"); }))).s_)), f_439, ((int64_t)(((*({ hrv *_t94 = &(g675); int64_t _i94 = n_476; (S4*)_t94->b + hr_ix(_i94, _t94->n, "hc/decl.amni:53"); }))).t_)))) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
 } } _bk90:; 
return f_439;
}
static bool f21_parse_file(hsl path_44) {
(void)(f6_parse_init());
int64_t t0_45 = (g885).n; 
if ((!(f22_lex_file(path_44)))) { (void)(({ hrv *_v95 = &(g681); hsl _s95 = hr_sl(g886); hr_append(_v95, _s95.p, _s95.n, sizeof(uint8_t)); }));
return false;
 }
g680 = t0_45;
g688 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
while ((((f31_tk()) != (((int64_t)0LL))) && (((g681).n) == (((int64_t)0LL))))) { (void)(f32_ptop());
 } _bk96:; 
(void)(({ hrv *_v97 = &(g679); int32_t _x97 = ((int32_t)(g688)); int32_t *_p97 = (int32_t*)hr_grow(_v97, 1, sizeof _x97); *_p97 = _x97; _p97; }));
return (((g681).n) == (((int64_t)0LL)));
}
static bool f22_lex_file(hsl path_46) {
(void)(f7_lex_init());
hrv body_47 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(hr_os_read_file(path_46, (&(body_47)))))) { (void)(({ hrv *_v99 = &(g886); hsl _s99 = hr_str("cannot read ", 12); hr_append(_v99, _s99.p, _s99.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v100 = &(g886); hsl _s100 = path_46; hr_append(_v100, _s100.p, _s100.n, sizeof(uint8_t)); }));
return false;
 }
int64_t f_48 = (g884).n; 
int64_t base_49 = (g879).n; 
int64_t skip_50 = ({ int64_t _r101; if (((((((body_47).n) >= (((int64_t)3LL))) && (((*({ hrv *_t102 = &(body_47); int64_t _i102 = ((int64_t)0LL); (uint8_t*)_t102->b + hr_ix(_i102, _t102->n, "hc/lex.amni:69"); }))) == (((uint8_t)239LL)))) && (((*({ hrv *_t103 = &(body_47); int64_t _i103 = ((int64_t)1LL); (uint8_t*)_t103->b + hr_ix(_i103, _t103->n, "hc/lex.amni:69"); }))) == (((uint8_t)187LL)))) && (((*({ hrv *_t104 = &(body_47); int64_t _i104 = ((int64_t)2LL); (uint8_t*)_t104->b + hr_ix(_i104, _t104->n, "hc/lex.amni:69"); }))) == (((uint8_t)191LL))))) { _r101 = ((int64_t)3LL);  } else { _r101 = ((int64_t)0LL);  } _r101; }); 
(void)(({ hrv *_v105 = &(g879); hsl _s105 = ({ hsl _t106 = hr_sl(body_47); int64_t _l106 = skip_50, _h106 = _t106.n; if (_l106 < 0 || _h106 < _l106 || _h106 > _t106.n) hr_slerr(_l106, _h106, _t106.n, "hc/lex.amni:70"); (hsl){ _t106.p + _l106 * (int64_t)sizeof(uint8_t), _h106 - _l106 }; }); hr_append(_v105, _s105.p, _s105.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v107 = &(g879); uint8_t _x107 = ((uint8_t)0LL); uint8_t *_p107 = (uint8_t*)hr_grow(_v107, 1, sizeof _x107); *_p107 = _x107; _p107; }));
(void)(({ hrv *_v108 = &(g879); uint8_t _x108 = ((uint8_t)0LL); uint8_t *_p108 = (uint8_t*)hr_grow(_v108, 1, sizeof _x108); *_p108 = _x108; _p108; }));
(void)(({ hrv *_v109 = &(g879); uint8_t _x109 = ((uint8_t)0LL); uint8_t *_p109 = (uint8_t*)hr_grow(_v109, 1, sizeof _x109); *_p109 = _x109; _p109; }));
(void)(({ hrv *_v110 = &(g879); uint8_t _x110 = ((uint8_t)0LL); uint8_t *_p110 = (uint8_t*)hr_grow(_v110, 1, sizeof _x110); *_p110 = _x110; _p110; }));
(void)(({ hrv *_v111 = &(g884); S2 _x111 = ((S2){ .s_ = ((int32_t)(base_49)), .n_ = ((int32_t)(((int64_t)((int64_t)(body_47).n - (int64_t)skip_50)))), .name_ = ((int32_t)(f8_intern(path_46))), .amni_ = ((((path_46).n) > (((int64_t)5LL))) && hr_streq(({ hsl _t112 = path_46; int64_t _l112 = _t112.n - ((int64_t)5LL), _h112 = _t112.n; if (_l112 < 0 || _h112 < _l112 || _h112 > _t112.n) hr_slerr(_l112, _h112, _t112.n, "hc/lex.amni:71"); (hsl){ _t112.p + _l112 * (int64_t)sizeof(uint8_t), _h112 - _l112 }; }), hr_str(".amni", 5))), }); S2 *_p111 = (S2*)hr_grow(_v111, 1, sizeof _x111); *_p111 = _x111; _p111; }));
bool amni_51 = ((*({ hrv *_t113 = &(g884); int64_t _i113 = f_48; (S2*)_t113->b + hr_ix(_i113, _t113->n, "hc/lex.amni:72"); }))).amni_; 
int64_t p_52 = base_49; 
int64_t line_53 = ((int64_t)1LL); 

for (;;) { uint8_t c_57 = (*({ hrv *_t115 = &(g879); int64_t _i115 = p_52; (uint8_t*)_t115->b + hr_ix(_i115, _t115->n, "hc/lex.amni:77"); })); 
while ((((((c_57) == (((uint8_t)32LL))) || ((c_57) == (((uint8_t)9LL)))) || ((c_57) == (((uint8_t)13LL)))) || ((c_57) == (((uint8_t)10LL))))) { if (((c_57) == (((uint8_t)10LL)))) { line_53++;
 }
p_52++;
c_57 = (*({ hrv *_t117 = &(g879); int64_t _i117 = p_52; (uint8_t*)_t117->b + hr_ix(_i117, _t117->n, "hc/lex.amni:78"); }));
 } _bk116:; 
if ((((c_57) == (((uint8_t)47LL))) && (((*({ hrv *_t118 = &(g879); int64_t _i118 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t118->b + hr_ix(_i118, _t118->n, "hc/lex.amni:79"); }))) == (((uint8_t)47LL))))) { while (((((*({ hrv *_t120 = &(g879); int64_t _i120 = p_52; (uint8_t*)_t120->b + hr_ix(_i120, _t120->n, "hc/lex.amni:79"); }))) != (((uint8_t)10LL))) && (((*({ hrv *_t121 = &(g879); int64_t _i121 = p_52; (uint8_t*)_t121->b + hr_ix(_i121, _t121->n, "hc/lex.amni:79"); }))) != (((uint8_t)0LL))))) { p_52++;
 } _bk119:; 
continue;
 }
if ((((c_57) == (((uint8_t)47LL))) && (((*({ hrv *_t122 = &(g879); int64_t _i122 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t122->b + hr_ix(_i122, _t122->n, "hc/lex.amni:80"); }))) == (((uint8_t)42LL))))) { { int64_t *_t123 = &(p_52); *_t123 = ((int64_t)((int64_t)(*_t123) + (int64_t)((int64_t)2LL))); }
int64_t nest_58 = ((int64_t)1LL); 
while (((nest_58) > (((int64_t)0LL)))) { uint8_t d_59 = (*({ hrv *_t125 = &(g879); int64_t _i125 = p_52; (uint8_t*)_t125->b + hr_ix(_i125, _t125->n, "hc/lex.amni:82"); })); 
if (((d_59) == (((uint8_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("unterminated /* comment", 23));
 }
if (((d_59) == (((uint8_t)10LL)))) { line_53++;
 }
if ((((d_59) == (((uint8_t)42LL))) && (((*({ hrv *_t126 = &(g879); int64_t _i126 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t126->b + hr_ix(_i126, _t126->n, "hc/lex.amni:82"); }))) == (((uint8_t)47LL))))) { nest_58--;
p_52++;
 } else { if ((((d_59) == (((uint8_t)47LL))) && (((*({ hrv *_t127 = &(g879); int64_t _i127 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t127->b + hr_ix(_i127, _t127->n, "hc/lex.amni:82"); }))) == (((uint8_t)42LL))))) { nest_58++;
p_52++;
 }
 }
p_52++;
 } _bk124:; 
continue;
 }
int64_t s_63 = p_52; 
uint8_t n1_64 = (*({ hrv *_t128 = &(g879); int64_t _i128 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t128->b + hr_ix(_i128, _t128->n, "hc/lex.amni:86"); })); 
uint8_t n2_65 = (*({ hrv *_t129 = &(g879); int64_t _i129 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t129->b + hr_ix(_i129, _t129->n, "hc/lex.amni:86"); })); 
if (((c_57) == (((uint8_t)0LL)))) { (void)(f24_put(((int64_t)0LL), s_63, s_63, &f_48, &line_53));
return true;
 }
if (f26_dig(c_57)) { if ((((c_57) == (((uint8_t)48LL))) && (((n1_64) == (((uint8_t)120LL))) || ((n1_64) == (((uint8_t)88LL)))))) { { int64_t *_t130 = &(p_52); *_t130 = ((int64_t)((int64_t)(*_t130) + (int64_t)((int64_t)2LL))); }
int64_t ds_67 = p_52; 
while (f27_hexd((*({ hrv *_t132 = &(g879); int64_t _i132 = p_52; (uint8_t*)_t132->b + hr_ix(_i132, _t132->n, "hc/lex.amni:90"); })))) { p_52++;
 } _bk131:; 
bool hf_69 = false; 
if (((((*({ hrv *_t133 = &(g879); int64_t _i133 = p_52; (uint8_t*)_t133->b + hr_ix(_i133, _t133->n, "hc/lex.amni:92"); }))) == (((uint8_t)46LL))) && f27_hexd((*({ hrv *_t134 = &(g879); int64_t _i134 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t134->b + hr_ix(_i134, _t134->n, "hc/lex.amni:92"); }))))) { hf_69 = true;
p_52++;
while (f27_hexd((*({ hrv *_t136 = &(g879); int64_t _i136 = p_52; (uint8_t*)_t136->b + hr_ix(_i136, _t136->n, "hc/lex.amni:92"); })))) { p_52++;
 } _bk135:; 
 }
if (((((*({ hrv *_t137 = &(g879); int64_t _i137 = p_52; (uint8_t*)_t137->b + hr_ix(_i137, _t137->n, "hc/lex.amni:93"); }))) == (((uint8_t)112LL))) || (((*({ hrv *_t138 = &(g879); int64_t _i138 = p_52; (uint8_t*)_t138->b + hr_ix(_i138, _t138->n, "hc/lex.amni:93"); }))) == (((uint8_t)80LL))))) { hf_69 = true;
p_52++;
if (((((*({ hrv *_t139 = &(g879); int64_t _i139 = p_52; (uint8_t*)_t139->b + hr_ix(_i139, _t139->n, "hc/lex.amni:93"); }))) == (((uint8_t)43LL))) || (((*({ hrv *_t140 = &(g879); int64_t _i140 = p_52; (uint8_t*)_t140->b + hr_ix(_i140, _t140->n, "hc/lex.amni:93"); }))) == (((uint8_t)45LL))))) { p_52++;
 }
while (f26_dig((*({ hrv *_t142 = &(g879); int64_t _i142 = p_52; (uint8_t*)_t142->b + hr_ix(_i142, _t142->n, "hc/lex.amni:93"); })))) { p_52++;
 } _bk141:; 
 }
if (hf_69) { (void)(f24_put(((int64_t)3LL), s_63, p_52, &f_48, &line_53));
continue;
 }
if (((((int64_t)((int64_t)p_52 - (int64_t)ds_67))) > (((int64_t)16LL)))) { return f25_lerr(f_48, line_53, hr_str("hex literal too large for 64 bits", 33));
 }
uint64_t v_70 = ((uint64_t)0LL); 
{ int64_t _e144 = p_52; for (int64_t q_71 = ds_67; q_71 < _e144; q_71++) { v_70 = ((uint64_t)((uint64_t)((uint64_t)((v_70) << ((((uint64_t)4LL)) & 63))) | (uint64_t)((uint64_t)(f28_hexv((*({ hrv *_t145 = &(g879); int64_t _i145 = q_71; (uint8_t*)_t145->b + hr_ix(_i145, _t145->n, "hc/lex.amni:96"); })))))));
 } } _bk143:; 
(void)(f24_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
((*({ hrv *_t146 = &(g885); int64_t _i146 = ((int64_t)((int64_t)(g885).n - (int64_t)((int64_t)1LL))); (S3*)_t146->b + hr_ix(_i146, _t146->n, "hc/lex.amni:97"); }))).v_ = ((int64_t)(v_70));
((*({ hrv *_t147 = &(g885); int64_t _i147 = ((int64_t)((int64_t)(g885).n - (int64_t)((int64_t)1LL))); (S3*)_t147->b + hr_ix(_i147, _t147->n, "hc/lex.amni:97"); }))).uns_ = ((v_70) > (((uint64_t)9223372036854775807LL)));
continue;
 }
while (f26_dig((*({ hrv *_t149 = &(g879); int64_t _i149 = p_52; (uint8_t*)_t149->b + hr_ix(_i149, _t149->n, "hc/lex.amni:99"); })))) { p_52++;
 } _bk148:; 
bool fl_73 = false; 
if (((((*({ hrv *_t150 = &(g879); int64_t _i150 = p_52; (uint8_t*)_t150->b + hr_ix(_i150, _t150->n, "hc/lex.amni:101"); }))) == (((uint8_t)46LL))) && f26_dig((*({ hrv *_t151 = &(g879); int64_t _i151 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t151->b + hr_ix(_i151, _t151->n, "hc/lex.amni:101"); }))))) { fl_73 = true;
p_52++;
while (f26_dig((*({ hrv *_t153 = &(g879); int64_t _i153 = p_52; (uint8_t*)_t153->b + hr_ix(_i153, _t153->n, "hc/lex.amni:101"); })))) { p_52++;
 } _bk152:; 
 }
if ((((((*({ hrv *_t154 = &(g879); int64_t _i154 = p_52; (uint8_t*)_t154->b + hr_ix(_i154, _t154->n, "hc/lex.amni:102"); }))) == (((uint8_t)101LL))) || (((*({ hrv *_t155 = &(g879); int64_t _i155 = p_52; (uint8_t*)_t155->b + hr_ix(_i155, _t155->n, "hc/lex.amni:102"); }))) == (((uint8_t)69LL)))) && (f26_dig((*({ hrv *_t156 = &(g879); int64_t _i156 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t156->b + hr_ix(_i156, _t156->n, "hc/lex.amni:102"); }))) || (((((*({ hrv *_t157 = &(g879); int64_t _i157 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t157->b + hr_ix(_i157, _t157->n, "hc/lex.amni:102"); }))) == (((uint8_t)43LL))) || (((*({ hrv *_t158 = &(g879); int64_t _i158 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t158->b + hr_ix(_i158, _t158->n, "hc/lex.amni:102"); }))) == (((uint8_t)45LL)))) && f26_dig((*({ hrv *_t159 = &(g879); int64_t _i159 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t159->b + hr_ix(_i159, _t159->n, "hc/lex.amni:102"); }))))))) { fl_73 = true;
{ int64_t *_t160 = &(p_52); *_t160 = ((int64_t)((int64_t)(*_t160) + (int64_t)((int64_t)2LL))); }
while (f26_dig((*({ hrv *_t162 = &(g879); int64_t _i162 = p_52; (uint8_t*)_t162->b + hr_ix(_i162, _t162->n, "hc/lex.amni:102"); })))) { p_52++;
 } _bk161:; 
 }
if (fl_73) { (void)(f24_put(((int64_t)3LL), s_63, p_52, &f_48, &line_53));
continue;
 }
uint64_t v_74 = ((uint64_t)0LL); 
{ int64_t _e164 = p_52; for (int64_t q_75 = s_63; q_75 < _e164; q_75++) { uint64_t d_76 = ((uint64_t)(((uint8_t)((uint64_t)(*({ hrv *_t165 = &(g879); int64_t _i165 = q_75; (uint8_t*)_t165->b + hr_ix(_i165, _t165->n, "hc/lex.amni:105"); })) - (uint64_t)((uint8_t)48LL))))); 
if (((v_74) > (HR_UDIV(uint64_t, ((uint64_t)((uint64_t)((uint64_t)18446744073709551615ULL) - (uint64_t)d_76)), ((uint64_t)10LL), "hc/lex.amni:105")))) { return f25_lerr(f_48, line_53, hr_str("integer literal too large for 64 bits", 37));
 }
v_74 = ((uint64_t)((uint64_t)((uint64_t)((uint64_t)v_74 * (uint64_t)((uint64_t)10LL))) + (uint64_t)d_76));
 } } _bk163:; 
(void)(f24_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
((*({ hrv *_t166 = &(g885); int64_t _i166 = ((int64_t)((int64_t)(g885).n - (int64_t)((int64_t)1LL))); (S3*)_t166->b + hr_ix(_i166, _t166->n, "hc/lex.amni:106"); }))).v_ = ((int64_t)(v_74));
((*({ hrv *_t167 = &(g885); int64_t _i167 = ((int64_t)((int64_t)(g885).n - (int64_t)((int64_t)1LL))); (S3*)_t167->b + hr_ix(_i167, _t167->n, "hc/lex.amni:106"); }))).uns_ = ((v_74) > (((uint64_t)9223372036854775807LL)));
continue;
 }
if (f29_idc(c_57)) { while (f29_idc((*({ hrv *_t169 = &(g879); int64_t _i169 = p_52; (uint8_t*)_t169->b + hr_ix(_i169, _t169->n, "hc/lex.amni:109"); })))) { p_52++;
 } _bk168:; 
int64_t id_78 = f8_intern(({ hsl _t170 = hr_sl(g879); int64_t _l170 = s_63, _h170 = p_52; if (_l170 < 0 || _h170 < _l170 || _h170 > _t170.n) hr_slerr(_l170, _h170, _t170.n, "hc/lex.amni:110"); (hsl){ _t170.p + _l170 * (int64_t)sizeof(uint8_t), _h170 - _l170 }; })); 
int64_t k_79 = ({ int64_t _r171; if (((id_78) < (((int64_t)49LL)))) { _r171 = ((int64_t)((int64_t)((int64_t)56LL) + (int64_t)id_78));  } else { _r171 = ((int64_t)1LL);  } _r171; }); 
if (((!(amni_51)) && ((k_79) >= (((int64_t)101LL))))) { k_79 = ((int64_t)1LL);
 }
(void)(f24_put(k_79, s_63, p_52, &f_48, &line_53));
((*({ hrv *_t172 = &(g885); int64_t _i172 = ((int64_t)((int64_t)(g885).n - (int64_t)((int64_t)1LL))); (S3*)_t172->b + hr_ix(_i172, _t172->n, "hc/lex.amni:113"); }))).v_ = id_78;
continue;
 }
if (((c_57) == (((uint8_t)39LL)))) { p_52++;
int64_t v_86 = f30_esc((&(p_52)), f_48, line_53); 
if (((v_86) < (((int64_t)0LL)))) { return false;
 }
if ((((*({ hrv *_t173 = &(g879); int64_t _i173 = p_52; (uint8_t*)_t173->b + hr_ix(_i173, _t173->n, "hc/lex.amni:119"); }))) != (((uint8_t)39LL)))) { return f25_lerr(f_48, line_53, hr_str("expected closing ' of character literal", 39));
 }
p_52++;
(void)(f24_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
((*({ hrv *_t174 = &(g885); int64_t _i174 = ((int64_t)((int64_t)(g885).n - (int64_t)((int64_t)1LL))); (S3*)_t174->b + hr_ix(_i174, _t174->n, "hc/lex.amni:120"); }))).v_ = v_86;
continue;
 }
if (((c_57) == (((uint8_t)34LL)))) { int64_t ss_87 = (g881).n; 
bool ml_88 = false; 
if ((((n1_64) == (((uint8_t)34LL))) && ((n2_65) == (((uint8_t)34LL))))) { { int64_t *_t175 = &(p_52); *_t175 = ((int64_t)((int64_t)(*_t175) + (int64_t)((int64_t)3LL))); }
int64_t q_89 = p_52; 
while ((((((*({ hrv *_t177 = &(g879); int64_t _i177 = q_89; (uint8_t*)_t177->b + hr_ix(_i177, _t177->n, "hc/lex.amni:127"); }))) == (((uint8_t)32LL))) || (((*({ hrv *_t178 = &(g879); int64_t _i178 = q_89; (uint8_t*)_t178->b + hr_ix(_i178, _t178->n, "hc/lex.amni:127"); }))) == (((uint8_t)9LL)))) || (((*({ hrv *_t179 = &(g879); int64_t _i179 = q_89; (uint8_t*)_t179->b + hr_ix(_i179, _t179->n, "hc/lex.amni:127"); }))) == (((uint8_t)13LL))))) { q_89++;
 } _bk176:; 
if ((((*({ hrv *_t180 = &(g879); int64_t _i180 = q_89; (uint8_t*)_t180->b + hr_ix(_i180, _t180->n, "hc/lex.amni:128"); }))) != (((uint8_t)10LL)))) { while ((!((((((*({ hrv *_t182 = &(g879); int64_t _i182 = p_52; (uint8_t*)_t182->b + hr_ix(_i182, _t182->n, "hc/lex.amni:129"); }))) == (((uint8_t)34LL))) && (((*({ hrv *_t183 = &(g879); int64_t _i183 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t183->b + hr_ix(_i183, _t183->n, "hc/lex.amni:129"); }))) == (((uint8_t)34LL)))) && (((*({ hrv *_t184 = &(g879); int64_t _i184 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t184->b + hr_ix(_i184, _t184->n, "hc/lex.amni:129"); }))) == (((uint8_t)34LL))))))) { if (((((*({ hrv *_t185 = &(g879); int64_t _i185 = p_52; (uint8_t*)_t185->b + hr_ix(_i185, _t185->n, "hc/lex.amni:129"); }))) == (((uint8_t)0LL))) || (((*({ hrv *_t186 = &(g879); int64_t _i186 = p_52; (uint8_t*)_t186->b + hr_ix(_i186, _t186->n, "hc/lex.amni:129"); }))) == (((uint8_t)10LL))))) { return f25_lerr(f_48, line_53, hr_str("unterminated \"\"\" string", 23));
 }
(void)(({ hrv *_v187 = &(g881); uint8_t _x187 = (*({ hrv *_t188 = &(g879); int64_t _i188 = p_52; (uint8_t*)_t188->b + hr_ix(_i188, _t188->n, "hc/lex.amni:129"); })); uint8_t *_p187 = (uint8_t*)hr_grow(_v187, 1, sizeof _x187); *_p187 = _x187; _p187; }));
p_52++;
 } _bk181:; 
{ int64_t *_t189 = &(p_52); *_t189 = ((int64_t)((int64_t)(*_t189) + (int64_t)((int64_t)3LL))); }
 } else { ml_88 = true;
int64_t first_90 = ((int64_t)((int64_t)q_89 + (int64_t)((int64_t)1LL))); 
int64_t close_91 = first_90; 
while ((!((((((*({ hrv *_t191 = &(g879); int64_t _i191 = close_91; (uint8_t*)_t191->b + hr_ix(_i191, _t191->n, "hc/lex.amni:135"); }))) == (((uint8_t)34LL))) && (((*({ hrv *_t192 = &(g879); int64_t _i192 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)1LL))); (uint8_t*)_t192->b + hr_ix(_i192, _t192->n, "hc/lex.amni:135"); }))) == (((uint8_t)34LL)))) && (((*({ hrv *_t193 = &(g879); int64_t _i193 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)2LL))); (uint8_t*)_t193->b + hr_ix(_i193, _t193->n, "hc/lex.amni:135"); }))) == (((uint8_t)34LL))))))) { if ((((*({ hrv *_t194 = &(g879); int64_t _i194 = close_91; (uint8_t*)_t194->b + hr_ix(_i194, _t194->n, "hc/lex.amni:135"); }))) == (((uint8_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("unterminated \"\"\" string", 23));
 }
close_91++;
 } _bk190:; 
int64_t cs_92 = close_91; 
while ((((cs_92) > (first_90)) && (((*({ hrv *_t196 = &(g879); int64_t _i196 = ((int64_t)((int64_t)cs_92 - (int64_t)((int64_t)1LL))); (uint8_t*)_t196->b + hr_ix(_i196, _t196->n, "hc/lex.amni:136"); }))) != (((uint8_t)10LL))))) { cs_92--;
 } _bk195:; 
int64_t mg_93 = ((int64_t)((int64_t)close_91 - (int64_t)cs_92)); 
{ int64_t _e198 = close_91; for (int64_t q2_94 = cs_92; q2_94 < _e198; q2_94++) { if (((((*({ hrv *_t199 = &(g879); int64_t _i199 = q2_94; (uint8_t*)_t199->b + hr_ix(_i199, _t199->n, "hc/lex.amni:138"); }))) != (((uint8_t)32LL))) && (((*({ hrv *_t200 = &(g879); int64_t _i200 = q2_94; (uint8_t*)_t200->b + hr_ix(_i200, _t200->n, "hc/lex.amni:138"); }))) != (((uint8_t)9LL))))) { return f25_lerr(f_48, line_53, hr_str("only indentation may come before the closing \"\"\" of a multi-line string", 71));
 }
 } } _bk197:; 
int64_t l_95 = first_90; 
while (((l_95) < (cs_92))) { int64_t e_96 = l_95; 
while ((((*({ hrv *_t203 = &(g879); int64_t _i203 = e_96; (uint8_t*)_t203->b + hr_ix(_i203, _t203->n, "hc/lex.amni:141"); }))) != (((uint8_t)10LL)))) { e_96++;
 } _bk202:; 
int64_t te_97 = e_96; 
if ((((te_97) > (l_95)) && (((*({ hrv *_t204 = &(g879); int64_t _i204 = ((int64_t)((int64_t)te_97 - (int64_t)((int64_t)1LL))); (uint8_t*)_t204->b + hr_ix(_i204, _t204->n, "hc/lex.amni:142"); }))) == (((uint8_t)13LL))))) { te_97--;
 }
if (((l_95) != (first_90))) { (void)(({ hrv *_v205 = &(g881); uint8_t _x205 = ((uint8_t)10LL); uint8_t *_p205 = (uint8_t*)hr_grow(_v205, 1, sizeof _x205); *_p205 = _x205; _p205; }));
 }
bool ok_98 = ((((int64_t)((int64_t)te_97 - (int64_t)l_95))) >= (mg_93)); 
if (ok_98) { { int64_t _e207 = mg_93; for (int64_t k_99 = 0; k_99 < _e207; k_99++) { if ((((*({ hrv *_t208 = &(g879); int64_t _i208 = ((int64_t)((int64_t)l_95 + (int64_t)k_99)); (uint8_t*)_t208->b + hr_ix(_i208, _t208->n, "hc/lex.amni:144"); }))) != ((*({ hrv *_t209 = &(g879); int64_t _i209 = ((int64_t)((int64_t)cs_92 + (int64_t)k_99)); (uint8_t*)_t209->b + hr_ix(_i209, _t209->n, "hc/lex.amni:144"); }))))) { ok_98 = false;
 }
 } } _bk206:; 
 }
if (ok_98) { (void)(({ hrv *_v210 = &(g881); hsl _s210 = ({ hsl _t211 = hr_sl(g879); int64_t _l211 = ((int64_t)((int64_t)l_95 + (int64_t)mg_93)), _h211 = te_97; if (_l211 < 0 || _h211 < _l211 || _h211 > _t211.n) hr_slerr(_l211, _h211, _t211.n, "hc/lex.amni:145"); (hsl){ _t211.p + _l211 * (int64_t)sizeof(uint8_t), _h211 - _l211 }; }); hr_append(_v210, _s210.p, _s210.n, sizeof(uint8_t)); }));
 } else { { int64_t _e213 = te_97; for (int64_t k_100 = l_95; k_100 < _e213; k_100++) { if (((((*({ hrv *_t214 = &(g879); int64_t _i214 = k_100; (uint8_t*)_t214->b + hr_ix(_i214, _t214->n, "hc/lex.amni:145"); }))) != (((uint8_t)32LL))) && (((*({ hrv *_t215 = &(g879); int64_t _i215 = k_100; (uint8_t*)_t215->b + hr_ix(_i215, _t215->n, "hc/lex.amni:145"); }))) != (((uint8_t)9LL))))) { return f25_lerr(f_48, line_53, hr_str("a line of a multi-line string must start with the indentation of its closing \"\"\"", 80));
 }
 } } _bk212:; 
 }
l_95 = ((int64_t)((int64_t)e_96 + (int64_t)((int64_t)1LL)));
 } _bk201:; 
{ int64_t _e217 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)3LL))); for (int64_t k_101 = p_52; k_101 < _e217; k_101++) { if ((((*({ hrv *_t218 = &(g879); int64_t _i218 = k_101; (uint8_t*)_t218->b + hr_ix(_i218, _t218->n, "hc/lex.amni:148"); }))) == (((uint8_t)10LL)))) { line_53++;
 }
 } } _bk216:; 
p_52 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)3LL)));
 }
 } else { p_52++;
while ((((*({ hrv *_t220 = &(g879); int64_t _i220 = p_52; (uint8_t*)_t220->b + hr_ix(_i220, _t220->n, "hc/lex.amni:153"); }))) != (((uint8_t)34LL)))) { if (((((*({ hrv *_t221 = &(g879); int64_t _i221 = p_52; (uint8_t*)_t221->b + hr_ix(_i221, _t221->n, "hc/lex.amni:153"); }))) == (((uint8_t)10LL))) || (((*({ hrv *_t222 = &(g879); int64_t _i222 = p_52; (uint8_t*)_t222->b + hr_ix(_i222, _t222->n, "hc/lex.amni:153"); }))) == (((uint8_t)0LL))))) { return f25_lerr(f_48, line_53, hr_str("unterminated string literal", 27));
 }
int64_t v_102 = f30_esc((&(p_52)), f_48, line_53); 
if (((v_102) < (((int64_t)0LL)))) { return false;
 }
(void)(({ hrv *_v223 = &(g881); uint8_t _x223 = ((uint8_t)(v_102)); uint8_t *_p223 = (uint8_t*)hr_grow(_v223, 1, sizeof _x223); *_p223 = _x223; _p223; }));
 } _bk219:; 
p_52++;
 }
(void)(f24_put(((int64_t)4LL), s_63, p_52, &f_48, &line_53));
((*({ hrv *_t224 = &(g885); int64_t _i224 = ((int64_t)((int64_t)(g885).n - (int64_t)((int64_t)1LL))); (S3*)_t224->b + hr_ix(_i224, _t224->n, "hc/lex.amni:156"); }))).v_ = ss_87;
((*({ hrv *_t225 = &(g885); int64_t _i225 = ((int64_t)((int64_t)(g885).n - (int64_t)((int64_t)1LL))); (S3*)_t225->b + hr_ix(_i225, _t225->n, "hc/lex.amni:156"); }))).w_ = ((int32_t)(((int64_t)((int64_t)(g881).n - (int64_t)ss_87))));
((*({ hrv *_t226 = &(g885); int64_t _i226 = ((int64_t)((int64_t)(g885).n - (int64_t)((int64_t)1LL))); (S3*)_t226->b + hr_ix(_i226, _t226->n, "hc/lex.amni:156"); }))).ml_ = ml_88;
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
 } else { if ((((n1_64) == (((uint8_t)61LL))) && ((n2_65) == (((uint8_t)61LL))))) { { int64_t *_t227 = &(p_52); *_t227 = ((int64_t)((int64_t)(*_t227) + (int64_t)((int64_t)2LL))); }
k_103 = ((int64_t)19LL);
 } else { if ((((n1_64) == (((uint8_t)33LL))) && ((n2_65) == (((uint8_t)61LL))))) { { int64_t *_t228 = &(p_52); *_t228 = ((int64_t)((int64_t)(*_t228) + (int64_t)((int64_t)2LL))); }
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
 } else { if ((((n1_64) == (((uint8_t)60LL))) && ((n2_65) == (((uint8_t)61LL))))) { { int64_t *_t229 = &(p_52); *_t229 = ((int64_t)((int64_t)(*_t229) + (int64_t)((int64_t)2LL))); }
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
 } else { if ((((n1_64) == (((uint8_t)62LL))) && ((n2_65) == (((uint8_t)61LL))))) { { int64_t *_t230 = &(p_52); *_t230 = ((int64_t)((int64_t)(*_t230) + (int64_t)((int64_t)2LL))); }
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
(void)(f24_put(k_103, s_63, p_52, &f_48, &line_53));
 } _bk114:; 
return true;
}
static void f24_put(int64_t k_54, int64_t s_55, int64_t e_56, int64_t *c48, int64_t *c53) {
(void)(({ hrv *_v231 = &(g885); S3 _x231 = ((S3){ .k_ = ((uint8_t)(k_54)), .f_ = ((uint16_t)((*c48))), .line_ = ((int32_t)((*c53))), .s_ = ((int32_t)(s_55)), .n_ = ((int32_t)(((int64_t)((int64_t)e_56 - (int64_t)s_55)))), }); S3 *_p231 = (S3*)hr_grow(_v231, 1, sizeof _x231); *_p231 = _x231; _p231; }));
}
static bool f25_lerr(int64_t f_60, int64_t line_61, hsl m_62) {
if ((((g886).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v232 = &(g886); hsl _s232 = f10_nm(((int64_t)(((*({ hrv *_t233 = &(g884); int64_t _i233 = f_60; (S2*)_t233->b + hr_ix(_i233, _t233->n, "hc/lex.amni:52"); }))).name_))); hr_append(_v232, _s232.p, _s232.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o234 = &(g886); hr_fs(_o234, hr_str(":", 1)); hr_fi(_o234, line_61); hr_fs(_o234, hr_str(": error: ", 9)); hr_fs(_o234, m_62); }));
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
return ({ int64_t _r235; if (((c_72) <= (((uint8_t)57LL)))) { _r235 = ((int64_t)(((uint8_t)((uint64_t)c_72 - (uint64_t)((uint8_t)48LL)))));  } else { _r235 = ((int64_t)((int64_t)((int64_t)(((uint8_t)((uint64_t)((uint8_t)((uint64_t)c_72 | (uint64_t)((uint8_t)32LL))) - (uint64_t)((uint8_t)97LL))))) + (int64_t)((int64_t)10LL)));  } _r235; });
}
static bool f29_idc(uint8_t c_77) {
return ((((((c_77) >= (((uint8_t)97LL))) && ((c_77) <= (((uint8_t)122LL)))) || (((c_77) >= (((uint8_t)65LL))) && ((c_77) <= (((uint8_t)90LL))))) || ((c_77) == (((uint8_t)95LL)))) || (((c_77) >= (((uint8_t)48LL))) && ((c_77) <= (((uint8_t)57LL)))));
}
static int64_t f30_esc(int64_t* p_80, int64_t f_81, int64_t line_82) {
uint8_t c_83 = (*({ hrv *_t236 = &(g879); int64_t _i236 = (*p_80); (uint8_t*)_t236->b + hr_ix(_i236, _t236->n, "hc/lex.amni:54"); })); 
(*p_80)++;
if (((c_83) != (((uint8_t)92LL)))) { return ((int64_t)(c_83));
 }
uint8_t e_84 = (*({ hrv *_t237 = &(g879); int64_t _i237 = (*p_80); (uint8_t*)_t237->b + hr_ix(_i237, _t237->n, "hc/lex.amni:56"); })); 
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
if (((((e_84) == (((uint8_t)120LL))) && f27_hexd((*({ hrv *_t238 = &(g879); int64_t _i238 = (*p_80); (uint8_t*)_t238->b + hr_ix(_i238, _t238->n, "hc/lex.amni:59"); })))) && f27_hexd((*({ hrv *_t239 = &(g879); int64_t _i239 = ((int64_t)((int64_t)(*p_80) + (int64_t)((int64_t)1LL))); (uint8_t*)_t239->b + hr_ix(_i239, _t239->n, "hc/lex.amni:59"); }))))) { int64_t v_85 = ((int64_t)((int64_t)((int64_t)((int64_t)f28_hexv((*({ hrv *_t240 = &(g879); int64_t _i240 = (*p_80); (uint8_t*)_t240->b + hr_ix(_i240, _t240->n, "hc/lex.amni:59"); }))) * (int64_t)((int64_t)16LL))) + (int64_t)f28_hexv((*({ hrv *_t241 = &(g879); int64_t _i241 = ((int64_t)((int64_t)(*p_80) + (int64_t)((int64_t)1LL))); (uint8_t*)_t241->b + hr_ix(_i241, _t241->n, "hc/lex.amni:59"); }))))); 
{ int64_t *_t242 = p_80; *_t242 = ((int64_t)((int64_t)(*_t242) + (int64_t)((int64_t)2LL))); }
return v_85;
 }
(void)(f25_lerr(f_81, line_82, hr_str("unknown escape sequence", 23)));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f31_tk(void) {
return ((int64_t)(((*({ hrv *_t243 = &(g885); int64_t _i243 = g680; (S3*)_t243->b + hr_ix(_i243, _t243->n, "hc/parse.amni:32"); }))).k_));
}
static void f32_ptop(void) {
int64_t st_104 = g680; 
g687 = g688;
int64_t k_105 = f31_tk(); 
if (((k_105) == (((int64_t)57LL)))) { (void)(f33_nx());
g688 = f34_ident(hr_str("namespace declaration", 21));
g687 = g688;
(void)(f39_ex(((int64_t)12LL), hr_str("namespace declaration", 21)));
return;
 }
if (((k_105) == (((int64_t)56LL)))) { (void)(f33_nx());
int64_t n_121 = f40_mk(((int64_t)54LL), st_104); 
if (f41_is(((int64_t)16LL))) { ((*({ hrv *_t244 = &(g675); int64_t _i244 = n_121; (S4*)_t244->b + hr_ix(_i244, _t244->n, "hc/parse.amni:699"); }))).fl_ = ((uint16_t)1LL);
 }
hrv path_123 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v246 = &(path_123); hsl _s246 = f10_nm(f34_ident(hr_str("import", 6))); hr_append(_v246, _s246.p, _s246.n, sizeof(uint8_t)); }));
while (f41_is(((int64_t)16LL))) { (void)(({ hrv *_v248 = &(path_123); uint8_t _x248 = ((uint8_t)47LL); uint8_t *_p248 = (uint8_t*)hr_grow(_v248, 1, sizeof _x248); *_p248 = _x248; _p248; }));
(void)(({ hrv *_v249 = &(path_123); hsl _s249 = f10_nm(f34_ident(hr_str("import", 6))); hr_append(_v249, _s249.p, _s249.n, sizeof(uint8_t)); }));
 } _bk247:; 
{ int64_t q__124 = f8_intern(hr_sl(path_123)); 
((*({ hrv *_t250 = &(g675); int64_t _i250 = n_121; (S4*)_t250->b + hr_ix(_i250, _t250->n, "hc/parse.amni:703"); }))).s_ = ((int32_t)(q__124));
 }
if ((f42_at_from() || f43_at_word(g692))) { (void)(f33_nx());
if (((f31_tk()) != (((int64_t)4LL)))) { (void)(f38_perr(hr_str("expected the package's source, a string, after from", 51)));
 }
((*({ hrv *_t251 = &(g675); int64_t _i251 = n_121; (S4*)_t251->b + hr_ix(_i251, _t251->n, "hc/parse.amni:704"); }))).a_ = ((int32_t)(g680));
(void)(f33_nx());
 }
(void)(f39_ex(((int64_t)12LL), hr_str("import", 6)));
(void)(({ hrv *_v252 = &(g678); int32_t _x252 = ((int32_t)(n_121)); int32_t *_p252 = (int32_t*)hr_grow(_v252, 1, sizeof _x252); *_p252 = _x252; _p252; }));
return;
 }
if (((f46_at_inline() || f47_at_checkfree()) || f48_at_lut())) { (void)(({ hrv *_v253 = &(g678); int32_t _x253 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p253 = (int32_t*)hr_grow(_v253, 1, sizeof _x253); *_p253 = _x253; _p253; }));
return;
 }
if (((k_105) == (((int64_t)58LL)))) { (void)(({ hrv *_v254 = &(g678); int32_t _x254 = ((int32_t)(f94_pstruct())); int32_t *_p254 = (int32_t*)hr_grow(_v254, 1, sizeof _x254); *_p254 = _x254; _p254; }));
return;
 }
if (((k_105) == (((int64_t)59LL)))) { (void)(({ hrv *_v255 = &(g678); int32_t _x255 = ((int32_t)(f96_penum())); int32_t *_p255 = (int32_t*)hr_grow(_v255, 1, sizeof _x255); *_p255 = _x255; _p255; }));
return;
 }
if (((k_105) == (((int64_t)60LL)))) { (void)(f33_nx());
int64_t n_433 = f40_mk(((int64_t)53LL), st_104); 
{ int64_t q__434 = f50_declname(hr_str("type alias", 10)); 
((*({ hrv *_t256 = &(g675); int64_t _i256 = n_433; (S4*)_t256->b + hr_ix(_i256, _t256->n, "hc/parse.amni:712"); }))).s_ = ((int32_t)(q__434));
 }
((*({ hrv *_t257 = &(g675); int64_t _i257 = n_433; (S4*)_t257->b + hr_ix(_i257, _t257->n, "hc/parse.amni:712"); }))).a_ = ((int32_t)(g687));
(void)(f39_ex(((int64_t)36LL), hr_str("type alias", 10)));
{ int64_t q__435 = f53_ptype(); 
((*({ hrv *_t258 = &(g675); int64_t _i258 = n_433; (S4*)_t258->b + hr_ix(_i258, _t258->n, "hc/parse.amni:712"); }))).b_ = ((int32_t)(q__435));
 }
(void)(f39_ex(((int64_t)12LL), hr_str("type alias", 10)));
(void)(({ hrv *_v259 = &(g678); int32_t _x259 = ((int32_t)(n_433)); int32_t *_p259 = (int32_t*)hr_grow(_v259, 1, sizeof _x259); *_p259 = _x259; _p259; }));
return;
 }
if (((k_105) == (((int64_t)68LL)))) { (void)(f33_nx());
int64_t cs_436 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((f31_tk()) == (((int64_t)4LL)))) { cs_436 = g680;
(void)(f33_nx());
 }
if (((f31_tk()) == (((int64_t)9LL)))) { if (((cs_436) < (((int64_t)0LL)))) { (void)(f38_perr(hr_str("an extern block names the library it binds from: extern \"lib\" {", 63)));
 }
(void)(f33_nx());
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v261 = &(g678); int32_t _x261 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), cs_436))); int32_t *_p261 = (int32_t*)hr_grow(_v261, 1, sizeof _x261); *_p261 = _x261; _p261; }));
 } _bk260:; 
(void)(f39_ex(((int64_t)10LL), hr_str("extern block", 12)));
return;
 }
g680--;
if (((cs_436) >= (((int64_t)0LL)))) { g680--;
 }
(void)(({ hrv *_v262 = &(g678); int32_t _x262 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p262 = (int32_t*)hr_grow(_v262, 1, sizeof _x262); *_p262 = _x262; _p262; }));
return;
 }
if (((((((k_105) == (((int64_t)65LL))) || ((k_105) == (((int64_t)61LL)))) || ((k_105) == (((int64_t)62LL)))) || ((k_105) == (((int64_t)63LL)))) || ((k_105) == (((int64_t)64LL))))) { (void)(({ hrv *_v263 = &(g678); int32_t _x263 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p263 = (int32_t*)hr_grow(_v263, 1, sizeof _x263); *_p263 = _x263; _p263; }));
return;
 }
if ((((((k_105) == (((int64_t)71LL))) || ((k_105) == (((int64_t)66LL)))) || ((k_105) == (((int64_t)67LL)))) || ((k_105) == (((int64_t)69LL))))) { int64_t v_437 = f74_pvdecl(true); 
(void)(f39_ex(((int64_t)12LL), hr_str("global declaration", 18)));
(void)(({ hrv *_v264 = &(g678); int32_t _x264 = ((int32_t)(v_437)); int32_t *_p264 = (int32_t*)hr_grow(_v264, 1, sizeof _x264); *_p264 = _x264; _p264; }));
return;
 }
hrv m_438 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o266 = &(m_438); hr_fs(_o266, hr_str("top-level declaration expected, found '", 39)); hr_fs(_o266, f35_cur_text()); hr_fs(_o266, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_438)));
}
static void f33_nx(void) {
if (((((*({ hrv *_t267 = &(g885); int64_t _i267 = g680; (S3*)_t267->b + hr_ix(_i267, _t267->n, "hc/parse.amni:34"); }))).k_) != (((uint8_t)0LL)))) { g680++;
 }
}
static int64_t f34_ident(hsl ctx_106) {
if (((f31_tk()) != (((int64_t)1LL)))) { hrv m_107 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o269 = &(m_107); hr_fs(_o269, hr_str("expected identifier in ", 23)); hr_fs(_o269, ctx_106); hr_fs(_o269, hr_str(", found '", 9)); hr_fs(_o269, f35_cur_text()); hr_fs(_o269, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_107)));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t v_115 = ((int64_t)(((*({ hrv *_t270 = &(g885); int64_t _i270 = g680; (S3*)_t270->b + hr_ix(_i270, _t270->n, "hc/parse.amni:51"); }))).v_)); 
(void)(f33_nx());
return v_115;
}
static hsl f35_cur_text(void) {
int64_t k_108 = f31_tk(); 
return ({ hsl _r271; if (((((k_108) == (((int64_t)1LL))) || ((k_108) == (((int64_t)2LL)))) || ((k_108) == (((int64_t)3LL))))) { _r271 = f36_tok_text(g680);  } else { _r271 = f37_tname(k_108);  } _r271; });
}
static hsl f36_tok_text(int64_t t_109) {
S3 x_110 = (*({ hrv *_t272 = &(g885); int64_t _i272 = t_109; (S3*)_t272->b + hr_ix(_i272, _t272->n, "hc/lex.amni:181"); })); 
return ({ hsl _t273 = hr_sl(g879); int64_t _l273 = ((int64_t)((x_110).s_)), _h273 = ((int64_t)(((int32_t)((int64_t)(x_110).s_ + (int64_t)(x_110).n_)))); if (_l273 < 0 || _h273 < _l273 || _h273 > _t273.n) hr_slerr(_l273, _h273, _t273.n, "hc/lex.amni:181"); (hsl){ _t273.p + _l273 * (int64_t)sizeof(uint8_t), _h273 - _l273 }; });
}
static hsl f37_tname(int64_t k_111) {
A39 pu_112 = ({ A39 _t274; _t274.e[0] = hr_str("(", 1); _t274.e[1] = hr_str(")", 1); _t274.e[2] = hr_str("[", 1); _t274.e[3] = hr_str("]", 1); _t274.e[4] = hr_str("{", 1); _t274.e[5] = hr_str("}", 1); _t274.e[6] = hr_str(",", 1); _t274.e[7] = hr_str(";", 1); _t274.e[8] = hr_str(":", 1); _t274.e[9] = hr_str("\077", 1); _t274.e[10] = hr_str("::", 2); _t274.e[11] = hr_str(".", 1); _t274.e[12] = hr_str("..", 2); _t274.e[13] = hr_str(".=", 2); _t274.e[14] = hr_str(".==", 3); _t274.e[15] = hr_str(".!=", 3); _t274.e[16] = hr_str("+", 1); _t274.e[17] = hr_str("-", 1); _t274.e[18] = hr_str("*", 1); _t274.e[19] = hr_str("/", 1); _t274.e[20] = hr_str("%", 1); _t274.e[21] = hr_str("+=", 2); _t274.e[22] = hr_str("-=", 2); _t274.e[23] = hr_str("*=", 2); _t274.e[24] = hr_str("/=", 2); _t274.e[25] = hr_str("%=", 2); _t274.e[26] = hr_str("&=", 2); _t274.e[27] = hr_str("|=", 2); _t274.e[28] = hr_str("^=", 2); _t274.e[29] = hr_str("++", 2); _t274.e[30] = hr_str("--", 2); _t274.e[31] = hr_str("=", 1); _t274.e[32] = hr_str("==", 2); _t274.e[33] = hr_str("!=", 2); _t274.e[34] = hr_str("<", 1); _t274.e[35] = hr_str(">", 1); _t274.e[36] = hr_str("<=", 2); _t274.e[37] = hr_str(">=", 2); _t274.e[38] = hr_str("<<", 2); _t274.e[39] = hr_str(">>", 2); _t274.e[40] = hr_str("<<=", 3); _t274.e[41] = hr_str(">>=", 3); _t274.e[42] = hr_str("!", 1); _t274.e[43] = hr_str("~", 1); _t274.e[44] = hr_str("&", 1); _t274.e[45] = hr_str("|", 1); _t274.e[46] = hr_str("^", 1); _t274.e[47] = hr_str("&&", 2); _t274.e[48] = hr_str("||", 2); _t274.e[49] = hr_str("->", 2); _t274.e[50] = hr_str("=>", 2); _t274; }); 
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
return (pu_112).e[hr_ix(((int64_t)((int64_t)k_111 - (int64_t)((int64_t)5LL))), 51, "hc/parse.amni:40")];
}
static void f38_perr(hsl m_113) {
if (((g682) > (((int64_t)0LL)))) { g683 = true;
g680 = ((int64_t)((int64_t)(g885).n - (int64_t)((int64_t)1LL)));
return;
 }
if ((((g681).n) > (((int64_t)0LL)))) { return;
 }
S3 t_114 = (*({ hrv *_t276 = &(g885); int64_t _i276 = g680; (S3*)_t276->b + hr_ix(_i276, _t276->n, "hc/parse.amni:45"); })); 
(void)(({ hrv *_v277 = &(g681); hsl _s277 = f10_nm(((int64_t)(((*({ hrv *_t278 = &(g884); int64_t _i278 = (t_114).f_; (S2*)_t278->b + hr_ix(_i278, _t278->n, "hc/parse.amni:46"); }))).name_))); hr_append(_v277, _s277.p, _s277.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o279 = &(g681); hr_fs(_o279, hr_str(":", 1)); hr_fi(_o279, (t_114).line_); hr_fs(_o279, hr_str(": error: ", 9)); hr_fs(_o279, m_113); }));
g680 = ((int64_t)((int64_t)(g885).n - (int64_t)((int64_t)1LL)));
}
static void f39_ex(int64_t k_116, hsl ctx_117) {
if (((f31_tk()) != (k_116))) { hrv m_118 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o281 = &(m_118); hr_fs(_o281, hr_str("expected '", 10)); hr_fs(_o281, f37_tname(k_116)); hr_fs(_o281, hr_str("' in ", 5)); hr_fs(_o281, ctx_117); hr_fs(_o281, hr_str(", found '", 9)); hr_fs(_o281, f35_cur_text()); hr_fs(_o281, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_118)));
return;
 }
(void)(f33_nx());
}
static int64_t f40_mk(int64_t k_119, int64_t t_120) {
(void)(({ hrv *_v282 = &(g675); S4 _x282 = ((S4){ .k_ = ((uint8_t)(k_119)), .t_ = ((int32_t)(t_120)), .a_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .b_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .d_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .e_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .s_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .l_ = ((int32_t)0LL), .n_ = ((int32_t)0LL), }); S4 *_p282 = (S4*)hr_grow(_v282, 1, sizeof _x282); *_p282 = _x282; _p282; }));
return ((int64_t)((int64_t)(g675).n - (int64_t)((int64_t)1LL)));
}
static bool f41_is(int64_t k_122) {
if (((f31_tk()) == (k_122))) { (void)(f33_nx());
return true;
 }
return false;
}
static bool f42_at_from(void) {
return (f43_at_word(g692) && (((f44_tkat(((int64_t)((int64_t)g680 + (int64_t)((int64_t)1LL))))) == (((int64_t)1LL))) || ((f44_tkat(((int64_t)((int64_t)g680 + (int64_t)((int64_t)1LL))))) == (((int64_t)15LL)))));
}
static bool f43_at_word(int64_t w_125) {
return (((f31_tk()) == (((int64_t)1LL))) && ((((*({ hrv *_t283 = &(g885); int64_t _i283 = g680; (S3*)_t283->b + hr_ix(_i283, _t283->n, "hc/parse.amni:69"); }))).v_) == (w_125)));
}
static int64_t f44_tkat(int64_t i_126) {
return ((int64_t)(((*({ hrv *_t284 = &(g885); int64_t _i284 = f45_min(i_126, ((int64_t)((int64_t)(g885).n - (int64_t)((int64_t)1LL)))); (S3*)_t284->b + hr_ix(_i284, _t284->n, "hc/parse.amni:33"); }))).k_));
}
static int64_t f45_min(int64_t a_127, int64_t b_128) {
if (((b_128) < (a_127))) { return b_128;
 }
return a_127;
}
static bool f46_at_inline(void) {
return (f43_at_word(g693) && ((((f44_tkat(((int64_t)((int64_t)g680 + (int64_t)((int64_t)1LL))))) == (((int64_t)61LL))) || ((f44_tkat(((int64_t)((int64_t)g680 + (int64_t)((int64_t)1LL))))) == (((int64_t)65LL)))) || ((f44_tkat(((int64_t)((int64_t)g680 + (int64_t)((int64_t)1LL))))) == (((int64_t)62LL)))));
}
static bool f47_at_checkfree(void) {
int64_t n_129 = f44_tkat(((int64_t)((int64_t)g680 + (int64_t)((int64_t)1LL)))); 
return (f43_at_word(g694) && (((((((n_129) == (((int64_t)61LL))) || ((n_129) == (((int64_t)65LL)))) || ((n_129) == (((int64_t)62LL)))) || ((n_129) == (((int64_t)64LL)))) || ((n_129) == (((int64_t)68LL)))) || ((n_129) == (((int64_t)1LL)))));
}
static bool f48_at_lut(void) {
return (f43_at_word(g695) && ((f44_tkat(((int64_t)((int64_t)g680 + (int64_t)((int64_t)1LL))))) == (((int64_t)61LL))));
}
static int64_t f49_pfn(bool nested_130, int64_t cname_131, int64_t dylib_132) {
int64_t st_133 = g680; 
int64_t n_134 = f40_mk(((int64_t)50LL), st_133); 
int64_t fl_135 = ({ int64_t _r285; if (nested_130) { _r285 = ((int64_t)128LL);  } else { _r285 = ((int64_t)0LL);  } _r285; }); 
int64_t cn_136 = cname_131; 
if ((((cname_131) >= (((int64_t)0LL))) || ((dylib_132) >= (((int64_t)0LL))))) { { int64_t *_t286 = &(fl_135); *_t286 = ((int64_t)((int64_t)(*_t286) | (int64_t)((int64_t)1LL))); }
 }
if (f48_at_lut()) { (void)(f33_nx());
{ int64_t *_t287 = &(fl_135); *_t287 = ((int64_t)((int64_t)(*_t287) | (int64_t)((int64_t)256LL))); }
 }
if (f47_at_checkfree()) { (void)(f33_nx());
{ int64_t *_t288 = &(fl_135); *_t288 = ((int64_t)((int64_t)(*_t288) | (int64_t)((int64_t)64LL))); }
 }
if (f41_is(((int64_t)63LL))) { { int64_t *_t289 = &(fl_135); *_t289 = ((int64_t)((int64_t)(*_t289) | (int64_t)((int64_t)2LL))); }
if (((f31_tk()) == (((int64_t)4LL)))) { cn_136 = g680;
(void)(f33_nx());
 }
 }
if (f41_is(((int64_t)68LL))) { { int64_t *_t290 = &(fl_135); *_t290 = ((int64_t)((int64_t)(*_t290) | (int64_t)((int64_t)1LL))); }
if (((f31_tk()) == (((int64_t)4LL)))) { cn_136 = g680;
(void)(f33_nx());
 }
 }
if (f47_at_checkfree()) { (void)(f33_nx());
{ int64_t *_t291 = &(fl_135); *_t291 = ((int64_t)((int64_t)(*_t291) | (int64_t)((int64_t)64LL))); }
 }
if (f41_is(((int64_t)64LL))) { { int64_t *_t292 = &(fl_135); *_t292 = ((int64_t)((int64_t)(*_t292) | (int64_t)((int64_t)4LL))); }
 }
if (f46_at_inline()) { (void)(f33_nx());
{ int64_t *_t293 = &(fl_135); *_t293 = ((int64_t)((int64_t)(*_t293) | (int64_t)((int64_t)8LL))); }
 }
if (f41_is(((int64_t)65LL))) { { int64_t *_t294 = &(fl_135); *_t294 = ((int64_t)((int64_t)(*_t294) | (int64_t)((int64_t)16LL))); }
 }
if (f41_is(((int64_t)62LL))) { { int64_t *_t295 = &(fl_135); *_t295 = ((int64_t)((int64_t)(*_t295) | (int64_t)((int64_t)32LL))); }
 } else { (void)(f39_ex(((int64_t)61LL), hr_str("function declaration", 20)));
 }
{ int64_t q__139 = ({ int64_t _r296; if (nested_130) { _r296 = f34_ident(hr_str("function declaration", 20));  } else { _r296 = f50_declname(hr_str("function declaration", 20));  } _r296; }); 
((*({ hrv *_t297 = &(g675); int64_t _i297 = n_134; (S4*)_t297->b + hr_ix(_i297, _t297->n, "hc/parse.amni:657"); }))).s_ = ((int32_t)(q__139));
 }
((*({ hrv *_t298 = &(g675); int64_t _i298 = n_134; (S4*)_t298->b + hr_ix(_i298, _t298->n, "hc/parse.amni:658"); }))).a_ = ((int32_t)(g687));
{ int64_t q__403 = f51_pgenerics(); 
((*({ hrv *_t299 = &(g675); int64_t _i299 = n_134; (S4*)_t299->b + hr_ix(_i299, _t299->n, "hc/parse.amni:659"); }))).d_ = ((int32_t)(q__403));
 }
(void)(f39_ex(((int64_t)5LL), hr_str("function declaration", 20)));
int64_t m_404 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t p_405 = f40_mk(((int64_t)32LL), g680); 
if (f41_is(((int64_t)67LL))) { ((*({ hrv *_t301 = &(g675); int64_t _i301 = p_405; (S4*)_t301->b + hr_ix(_i301, _t301->n, "hc/parse.amni:664"); }))).fl_ = ((uint16_t)1LL);
 }
{ int64_t q__406 = f34_ident(hr_str("parameter list", 14)); 
((*({ hrv *_t302 = &(g675); int64_t _i302 = p_405; (S4*)_t302->b + hr_ix(_i302, _t302->n, "hc/parse.amni:665"); }))).s_ = ((int32_t)(q__406));
 }
if ((f41_is(((int64_t)13LL)) || f75_amni_type())) { { int64_t q__407 = f53_ptype(); 
((*({ hrv *_t303 = &(g675); int64_t _i303 = p_405; (S4*)_t303->b + hr_ix(_i303, _t303->n, "hc/parse.amni:666"); }))).a_ = ((int32_t)(q__407));
 }
 }
if (f41_is(((int64_t)36LL))) { { int64_t q__408 = f61_pexpr(); 
((*({ hrv *_t304 = &(g675); int64_t _i304 = p_405; (S4*)_t304->b + hr_ix(_i304, _t304->n, "hc/parse.amni:667"); }))).b_ = ((int32_t)(q__408));
 }
 }
(void)(({ hrv *_v305 = &(g677); int32_t _x305 = ((int32_t)(p_405)); int32_t *_p305 = (int32_t*)hr_grow(_v305, 1, sizeof _x305); *_p305 = _x305; _p305; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk300; }
 }
 } _bk300:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function declaration", 20)));
(void)(f59_setl(n_134, m_404));
if ((f41_is(((int64_t)54LL)) || f75_amni_type())) { { int64_t *_t306 = &(fl_135); *_t306 = ((int64_t)((int64_t)(*_t306) | (int64_t)((int64_t)512LL))); }
int64_t r_409 = f40_mk(((int64_t)36LL), g680); 
int64_t m2_410 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v308 = &(g677); int32_t _x308 = ((int32_t)(f53_ptype())); int32_t *_p308 = (int32_t*)hr_grow(_v308, 1, sizeof _x308); *_p308 = _x308; _p308; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk307; }
 }
 } _bk307:; 
(void)(f59_setl(r_409, m2_410));
((*({ hrv *_t309 = &(g675); int64_t _i309 = n_134; (S4*)_t309->b + hr_ix(_i309, _t309->n, "hc/parse.amni:677"); }))).b_ = ((int32_t)(r_409));
 }
if (((((int64_t)((int64_t)fl_135 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)))) { if (f41_is(((int64_t)36LL))) { if (((f31_tk()) != (((int64_t)4LL)))) { (void)(f38_perr(hr_str("an extern fn's symbol is a string: fn name(...) = \"symbol\"; (\302\2477.10)", 68)));
 }
cn_136 = g680;
(void)(f33_nx());
 }
(void)(f39_ex(((int64_t)12LL), hr_str("extern declaration", 18)));
int64_t x_411 = f40_mk(((int64_t)58LL), st_133); 
((*({ hrv *_t310 = &(g675); int64_t _i310 = x_411; (S4*)_t310->b + hr_ix(_i310, _t310->n, "hc/parse.amni:682"); }))).a_ = ((int32_t)(cn_136));
((*({ hrv *_t311 = &(g675); int64_t _i311 = x_411; (S4*)_t311->b + hr_ix(_i311, _t311->n, "hc/parse.amni:682"); }))).b_ = ((int32_t)(dylib_132));
((*({ hrv *_t312 = &(g675); int64_t _i312 = n_134; (S4*)_t312->b + hr_ix(_i312, _t312->n, "hc/parse.amni:682"); }))).e_ = ((int32_t)(x_411));
 } else { if (((((int64_t)((int64_t)fl_135 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { int64_t x_412 = f40_mk(((int64_t)58LL), st_133); 
((*({ hrv *_t313 = &(g675); int64_t _i313 = x_412; (S4*)_t313->b + hr_ix(_i313, _t313->n, "hc/parse.amni:684"); }))).a_ = ((int32_t)(cn_136));
((*({ hrv *_t314 = &(g675); int64_t _i314 = n_134; (S4*)_t314->b + hr_ix(_i314, _t314->n, "hc/parse.amni:684"); }))).e_ = ((int32_t)(x_412));
 }
{ int64_t q__413 = f66_pblock(hr_str("function body", 13)); 
((*({ hrv *_t315 = &(g675); int64_t _i315 = n_134; (S4*)_t315->b + hr_ix(_i315, _t315->n, "hc/parse.amni:685"); }))).c_ = ((int32_t)(q__413));
 }
 }
((*({ hrv *_t316 = &(g675); int64_t _i316 = n_134; (S4*)_t316->b + hr_ix(_i316, _t316->n, "hc/parse.amni:687"); }))).fl_ = ((uint16_t)(fl_135));
(void)(f88_set_end(n_134));
return n_134;
}
static int64_t f50_declname(hsl ctx_137) {
int64_t a_138 = ({ int64_t _r317; if (((f31_tk()) == (((int64_t)15LL)))) { _r317 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r317 = f34_ident(ctx_137);  } _r317; }); 
if (f41_is(((int64_t)15LL))) { g687 = a_138;
return f34_ident(ctx_137);
 }
return a_138;
}
static int64_t f51_pgenerics(void) {
if ((!(f41_is(((int64_t)39LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t l_140 = f40_mk(((int64_t)36LL), g680); 
int64_t m_141 = f52_wbeg(); 
for (;;) { int64_t g_142 = f40_mk(((int64_t)57LL), g680); 
{ int64_t q__143 = f34_ident(hr_str("generic parameter list", 22)); 
((*({ hrv *_t319 = &(g675); int64_t _i319 = g_142; (S4*)_t319->b + hr_ix(_i319, _t319->n, "hc/parse.amni:587"); }))).s_ = ((int32_t)(q__143));
 }
if (f41_is(((int64_t)13LL))) { { int64_t q__402 = f53_ptype(); 
((*({ hrv *_t320 = &(g675); int64_t _i320 = g_142; (S4*)_t320->b + hr_ix(_i320, _t320->n, "hc/parse.amni:588"); }))).a_ = ((int32_t)(q__402));
 }
 }
(void)(({ hrv *_v321 = &(g677); int32_t _x321 = ((int32_t)(g_142)); int32_t *_p321 = (int32_t*)hr_grow(_v321, 1, sizeof _x321); *_p321 = _x321; _p321; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk318; }
 }
if ((((f31_tk()) == (((int64_t)40LL))) || ((f31_tk()) == (((int64_t)44LL))))) { { goto _bk318; }
 }
 } _bk318:; 
(void)(f58_close_angle(hr_str("generic parameter list", 22)));
(void)(f59_setl(l_140, m_141));
return l_140;
}
static int64_t f52_wbeg(void) {
return (g677).n;
}
static int64_t f53_ptype(void) {
bool cq_144 = f41_is(((int64_t)69LL)); 
int64_t t_175 = f54_ptype_prim(); 
bool q_176 = cq_144; 
for (;;) { int64_t st_177 = g680; 
if (f41_is(((int64_t)7LL))) { if (f41_is(((int64_t)13LL))) { (void)(f39_ex(((int64_t)8LL), hr_str("slice type", 10)));
int64_t n_178 = f40_mk(((int64_t)43LL), st_177); 
((*({ hrv *_t323 = &(g675); int64_t _i323 = n_178; (S4*)_t323->b + hr_ix(_i323, _t323->n, "hc/parse.amni:84"); }))).a_ = ((int32_t)(t_175));
if (q_176) { ((*({ hrv *_t324 = &(g675); int64_t _i324 = n_178; (S4*)_t324->b + hr_ix(_i324, _t324->n, "hc/parse.amni:84"); }))).fl_ = ((uint16_t)1LL);
q_176 = false;
 }
t_175 = n_178;
continue;
 }
int64_t n_179 = f40_mk(((int64_t)42LL), st_177); 
((*({ hrv *_t325 = &(g675); int64_t _i325 = n_179; (S4*)_t325->b + hr_ix(_i325, _t325->n, "hc/parse.amni:85"); }))).a_ = ((int32_t)(t_175));
if (f41_is(((int64_t)8LL))) { ((*({ hrv *_t326 = &(g675); int64_t _i326 = n_179; (S4*)_t326->b + hr_ix(_i326, _t326->n, "hc/parse.amni:86"); }))).op_ = ((uint8_t)(((uint8_t)2LL)));
t_175 = n_179;
continue;
 }
if (f41_is(((int64_t)17LL))) { ((*({ hrv *_t327 = &(g675); int64_t _i327 = n_179; (S4*)_t327->b + hr_ix(_i327, _t327->n, "hc/parse.amni:87"); }))).op_ = ((uint8_t)(((uint8_t)3LL)));
if (((f31_tk()) != (((int64_t)8LL)))) { { int64_t q__391 = f61_pexpr(); 
((*({ hrv *_t328 = &(g675); int64_t _i328 = n_179; (S4*)_t328->b + hr_ix(_i328, _t328->n, "hc/parse.amni:87"); }))).b_ = ((int32_t)(q__391));
 }
 }
 } else { if (f41_is(((int64_t)40LL))) { (void)(f39_ex(((int64_t)17LL), hr_str("resizable array type", 20)));
((*({ hrv *_t329 = &(g675); int64_t _i329 = n_179; (S4*)_t329->b + hr_ix(_i329, _t329->n, "hc/parse.amni:88"); }))).op_ = ({ uint8_t _r330; if (f41_is(((int64_t)39LL))) { _r330 = ((uint8_t)(((uint8_t)5LL)));  } else { _r330 = ((uint8_t)(((uint8_t)4LL)));  } _r330; });
 } else { if (f55_prim_tok(f31_tk())) { ((*({ hrv *_t331 = &(g675); int64_t _i331 = n_179; (S4*)_t331->b + hr_ix(_i331, _t331->n, "hc/parse.amni:89"); }))).op_ = ((uint8_t)(((uint8_t)2LL)));
{ int64_t q__393 = f93_lenstore(); 
((*({ hrv *_t332 = &(g675); int64_t _i332 = n_179; (S4*)_t332->b + hr_ix(_i332, _t332->n, "hc/parse.amni:89"); }))).c_ = ((int32_t)(q__393));
 }
 } else { ((*({ hrv *_t333 = &(g675); int64_t _i333 = n_179; (S4*)_t333->b + hr_ix(_i333, _t333->n, "hc/parse.amni:90"); }))).op_ = ((uint8_t)(((uint8_t)1LL)));
{ int64_t q__394 = f61_pexpr(); 
((*({ hrv *_t334 = &(g675); int64_t _i334 = n_179; (S4*)_t334->b + hr_ix(_i334, _t334->n, "hc/parse.amni:90"); }))).b_ = ((int32_t)(q__394));
 }
 }
 }
 }
(void)(f39_ex(((int64_t)8LL), hr_str("array type", 10)));
t_175 = n_179;
continue;
 }
if (f41_is(((int64_t)49LL))) { int64_t n_395 = f40_mk(((int64_t)44LL), st_177); 
((*({ hrv *_t335 = &(g675); int64_t _i335 = n_395; (S4*)_t335->b + hr_ix(_i335, _t335->n, "hc/parse.amni:95"); }))).a_ = ((int32_t)(t_175));
if (q_176) { ((*({ hrv *_t336 = &(g675); int64_t _i336 = n_395; (S4*)_t336->b + hr_ix(_i336, _t336->n, "hc/parse.amni:95"); }))).fl_ = ((uint16_t)1LL);
q_176 = false;
 }
if (f41_is(((int64_t)39LL))) { { int64_t q__396 = f93_lenstore(); 
((*({ hrv *_t337 = &(g675); int64_t _i337 = n_395; (S4*)_t337->b + hr_ix(_i337, _t337->n, "hc/parse.amni:96"); }))).c_ = ((int32_t)(q__396));
 }
if (f41_is(((int64_t)76LL))) { { int64_t q__397 = f56_qname(hr_str("relative reference pool", 23)); 
((*({ hrv *_t338 = &(g675); int64_t _i338 = n_395; (S4*)_t338->b + hr_ix(_i338, _t338->n, "hc/parse.amni:96"); }))).s_ = ((int32_t)(q__397));
 }
 }
(void)(f58_close_angle(hr_str("relative reference width", 24)));
 }
t_175 = n_395;
continue;
 }
if (f41_is(((int64_t)14LL))) { if (((((*({ hrv *_t339 = &(g675); int64_t _i339 = t_175; (S4*)_t339->b + hr_ix(_i339, _t339->n, "hc/parse.amni:100"); }))).k_) == (((uint8_t)44LL)))) { { uint16_t *_t340 = &(((*({ hrv *_t341 = &(g675); int64_t _i341 = t_175; (S4*)_t341->b + hr_ix(_i341, _t341->n, "hc/parse.amni:100"); }))).fl_); *_t340 = ((uint16_t)((uint64_t)(*_t340) | (uint64_t)((uint16_t)2LL))); }
 } else { int64_t n_398 = f40_mk(((int64_t)44LL), st_177); 
((*({ hrv *_t342 = &(g675); int64_t _i342 = n_398; (S4*)_t342->b + hr_ix(_i342, _t342->n, "hc/parse.amni:100"); }))).a_ = ((int32_t)(t_175));
((*({ hrv *_t343 = &(g675); int64_t _i343 = n_398; (S4*)_t343->b + hr_ix(_i343, _t343->n, "hc/parse.amni:100"); }))).fl_ = ((uint16_t)2LL);
if (q_176) { { uint16_t *_t344 = &(((*({ hrv *_t345 = &(g675); int64_t _i345 = n_398; (S4*)_t345->b + hr_ix(_i345, _t345->n, "hc/parse.amni:100"); }))).fl_); *_t344 = ((uint16_t)((uint64_t)(*_t344) | (uint64_t)((uint16_t)1LL))); }
q_176 = false;
 }
t_175 = n_398;
 }
continue;
 }
if (((f31_tk()) == (((int64_t)17LL)))) { (void)(f33_nx());
if (((((*({ hrv *_t346 = &(g675); int64_t _i346 = t_175; (S4*)_t346->b + hr_ix(_i346, _t346->n, "hc/parse.amni:103"); }))).k_) == (((uint8_t)41LL)))) { { uint16_t *_t347 = &(((*({ hrv *_t348 = &(g675); int64_t _i348 = t_175; (S4*)_t348->b + hr_ix(_i348, _t348->n, "hc/parse.amni:103"); }))).fl_); *_t347 = ((uint16_t)((uint64_t)(*_t347) | (uint64_t)((uint16_t)1LL))); }
 } else { (void)(f38_perr(hr_str("variable mode (..) applies only to ADT type names", 49)));
 }
continue;
 }
if (f41_is(((int64_t)16LL))) { int64_t n_399 = f40_mk(((int64_t)46LL), st_177); 
((*({ hrv *_t349 = &(g675); int64_t _i349 = n_399; (S4*)_t349->b + hr_ix(_i349, _t349->n, "hc/parse.amni:104"); }))).a_ = ((int32_t)(t_175));
{ int64_t q__400 = f34_ident(hr_str("variant type", 12)); 
((*({ hrv *_t350 = &(g675); int64_t _i350 = n_399; (S4*)_t350->b + hr_ix(_i350, _t350->n, "hc/parse.amni:104"); }))).s_ = ((int32_t)(q__400));
 }
t_175 = n_399;
continue;
 }
if (q_176) { int64_t n_401 = f40_mk(((int64_t)48LL), st_177); 
((*({ hrv *_t351 = &(g675); int64_t _i351 = n_401; (S4*)_t351->b + hr_ix(_i351, _t351->n, "hc/parse.amni:105"); }))).a_ = ((int32_t)(t_175));
t_175 = n_401;
 }
return t_175;
 } _bk322:; 
}
static int64_t f54_ptype_prim(void) {
int64_t st_145 = g680; 
int64_t k_146 = f31_tk(); 
if (f55_prim_tok(k_146)) { (void)(f33_nx());
bool up_148 = f43_at_word(g697); 
if (((((((((k_146) >= (((int64_t)91LL))) && ((k_146) <= (((int64_t)98LL)))) || ((k_146) == (((int64_t)103LL)))) || ((k_146) == (((int64_t)102LL)))) || ((k_146) == (((int64_t)101LL)))) && (!(g727))) && (((f31_tk()) == (((int64_t)76LL))) || up_148))) { (void)(f33_nx());
int64_t n_149 = f40_mk(((int64_t)47LL), st_145); 
((*({ hrv *_t352 = &(g675); int64_t _i352 = n_149; (S4*)_t352->b + hr_ix(_i352, _t352->n, "hc/parse.amni:116"); }))).op_ = ((uint8_t)(k_146));
((*({ hrv *_t353 = &(g675); int64_t _i353 = n_149; (S4*)_t353->b + hr_ix(_i353, _t353->n, "hc/parse.amni:116"); }))).fl_ = ({ uint16_t _r354; if (up_148) { _r354 = ((uint16_t)1LL);  } else { _r354 = ((uint16_t)0LL);  } _r354; });
{ int64_t q__155 = f56_qname(hr_str("index type", 10)); 
((*({ hrv *_t355 = &(g675); int64_t _i355 = n_149; (S4*)_t355->b + hr_ix(_i355, _t355->n, "hc/parse.amni:116"); }))).s_ = ((int32_t)(q__155));
 }
return n_149;
 }
int64_t n_156 = f40_mk(((int64_t)40LL), st_145); 
((*({ hrv *_t356 = &(g675); int64_t _i356 = n_156; (S4*)_t356->b + hr_ix(_i356, _t356->n, "hc/parse.amni:118"); }))).op_ = ((uint8_t)(k_146));
return n_156;
 }
if ((((k_146) == (((int64_t)1LL))) || ((k_146) == (((int64_t)15LL))))) { int64_t n_157 = f40_mk(((int64_t)41LL), st_145); 
{ int64_t q__158 = f56_qname(hr_str("type", 4)); 
((*({ hrv *_t357 = &(g675); int64_t _i357 = n_157; (S4*)_t357->b + hr_ix(_i357, _t357->n, "hc/parse.amni:121"); }))).s_ = ((int32_t)(q__158));
 }
if (f41_is(((int64_t)39LL))) { int64_t m_159 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v359 = &(g677); int32_t _x359 = ((int32_t)(f53_ptype())); int32_t *_p359 = (int32_t*)hr_grow(_v359, 1, sizeof _x359); *_p359 = _x359; _p359; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk358; }
 }
if ((((f31_tk()) == (((int64_t)40LL))) || ((f31_tk()) == (((int64_t)44LL))))) { { goto _bk358; }
 }
 } _bk358:; 
(void)(f58_close_angle(hr_str("type argument list", 18)));
(void)(f59_setl(n_157, m_159));
 }
return n_157;
 }
if (f41_is(((int64_t)61LL))) { int64_t n_168 = f40_mk(((int64_t)45LL), st_145); 
if (f41_is(((int64_t)5LL))) { ((*({ hrv *_t360 = &(g675); int64_t _i360 = n_168; (S4*)_t360->b + hr_ix(_i360, _t360->n, "hc/parse.amni:128"); }))).fl_ = ((uint16_t)1LL);
int64_t m_169 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v362 = &(g677); int32_t _x362 = ((int32_t)(f53_ptype())); int32_t *_p362 = (int32_t*)hr_grow(_v362, 1, sizeof _x362); *_p362 = _x362; _p362; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk361; }
 }
 } _bk361:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function type", 13)));
(void)(f59_setl(n_168, m_169));
if (f41_is(((int64_t)54LL))) { int64_t r_170 = f40_mk(((int64_t)36LL), g680); 
int64_t m2_171 = f52_wbeg(); 
if (f41_is(((int64_t)5LL))) { while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v364 = &(g677); int32_t _x364 = ((int32_t)(f53_ptype())); int32_t *_p364 = (int32_t*)hr_grow(_v364, 1, sizeof _x364); *_p364 = _x364; _p364; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk363; }
 }
 } _bk363:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function type return list", 25)));
 } else { (void)(({ hrv *_v365 = &(g677); int32_t _x365 = ((int32_t)(f53_ptype())); int32_t *_p365 = (int32_t*)hr_grow(_v365, 1, sizeof _x365); *_p365 = _x365; _p365; }));
 }
(void)(f59_setl(r_170, m2_171));
((*({ hrv *_t366 = &(g675); int64_t _i366 = n_168; (S4*)_t366->b + hr_ix(_i366, _t366->n, "hc/parse.amni:133"); }))).b_ = ((int32_t)(r_170));
 }
 }
return n_168;
 }
if (f41_is(((int64_t)5LL))) { bool fb_172 = g727; 
g727 = false;
int64_t t_173 = f53_ptype(); 
g727 = fb_172;
(void)(f39_ex(((int64_t)6LL), hr_str("parenthesized type", 18)));
return t_173;
 }
hrv m_174 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o368 = &(m_174); hr_fs(_o368, hr_str("type expected, found '", 22)); hr_fs(_o368, f35_cur_text()); hr_fs(_o368, hr_str("'", 1)); }));
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
if (((a_151) >= (((int64_t)0LL)))) { (void)(({ hrv *_v370 = &(s_153); hsl _s370 = f10_nm(a_151); hr_append(_v370, _s370.p, _s370.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v371 = &(s_153); hsl _s371 = hr_str("::", 2); hr_append(_v371, _s371.p, _s371.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v372 = &(s_153); hsl _s372 = f10_nm(b_152); hr_append(_v372, _s372.p, _s372.n, sizeof(uint8_t)); }));
return f8_intern(hr_sl(s_153));
}
static void f58_close_angle(hsl ctx_160) {
if (((f31_tk()) == (((int64_t)44LL)))) { (void)(({ hrv *_v373 = &(g689); int64_t _x373 = g680; int64_t *_p373 = (int64_t*)hr_grow(_v373, 1, sizeof _x373); *_p373 = _x373; _p373; }));
((*({ hrv *_t374 = &(g885); int64_t _i374 = g680; (S3*)_t374->b + hr_ix(_i374, _t374->n, "hc/parse.amni:52"); }))).k_ = ((uint8_t)(((uint8_t)40LL)));
return;
 }
(void)(f39_ex(((int64_t)40LL), ctx_160));
}
static void f59_setl(int64_t n_161, int64_t m_162) {
int64_t c_163 = ((int64_t)((int64_t)(g677).n - (int64_t)m_162)); 
{ int64_t q__167 = f60_wend(m_162); 
((*({ hrv *_t375 = &(g675); int64_t _i375 = n_161; (S4*)_t375->b + hr_ix(_i375, _t375->n, "hc/parse.amni:55"); }))).l_ = ((int32_t)(q__167));
 }
((*({ hrv *_t376 = &(g675); int64_t _i376 = n_161; (S4*)_t376->b + hr_ix(_i376, _t376->n, "hc/parse.amni:55"); }))).n_ = ((int32_t)(c_163));
}
static int64_t f60_wend(int64_t m_164) {
int64_t l_165 = (g676).n; 
{ int64_t _e378 = (g677).n; for (int64_t i_166 = m_164; i_166 < _e378; i_166++) { (void)(({ hrv *_v379 = &(g676); int32_t _x379 = (*({ hrv *_t380 = &(g677); int64_t _i380 = i_166; (int32_t*)_t380->b + hr_ix(_i380, _t380->n, "hc/parse.amni:54"); })); int32_t *_p379 = (int32_t*)hr_grow(_v379, 1, sizeof _x379); *_p379 = _x379; _p379; }));
 } } _bk377:; 
(void)(({ hrv *_v381 = &(g677); int64_t _k381 = ((int64_t)((int64_t)(g677).n - (int64_t)m_164)); if (_k381 < 0 || _k381 > _v381->n) hr_die("pop_n past the length", "hc/parse.amni:54"); _v381->n -= _k381; }));
return l_165;
}
static int64_t f61_pexpr(void) {
int64_t st_180 = g680; 
int64_t k_181 = f31_tk(); 
if (((k_181) == (((int64_t)72LL)))) { int64_t e_270 = f62_pif(); 
if (g685) { g686 = true;
 }
return e_270;
 }
if (((k_181) == (((int64_t)80LL)))) { int64_t e_274 = f78_pmatch(); 
if (g685) { g686 = true;
 }
return e_274;
 }
if (((k_181) == (((int64_t)78LL)))) { (void)(f33_nx());
int64_t e_275 = f40_mk(((int64_t)24LL), st_180); 
{ int64_t q__276 = f66_pblock(hr_str("block expression", 16)); 
((*({ hrv *_t382 = &(g675); int64_t _i382 = e_275; (S4*)_t382->b + hr_ix(_i382, _t382->n, "hc/parse.amni:147"); }))).a_ = ((int32_t)(q__276));
 }
if (g685) { g686 = true;
 }
return e_275;
 }
if (((k_181) == (((int64_t)9LL)))) { int64_t e_277 = f66_pblock(hr_str("block", 5)); 
if (g685) { g686 = true;
 }
return e_277;
 }
if (((k_181) == (((int64_t)74LL)))) { (void)(f33_nx());
int64_t e_278 = f40_mk(((int64_t)25LL), st_180); 
{ int64_t q__279 = f63_pscrut(); 
((*({ hrv *_t383 = &(g675); int64_t _i383 = e_278; (S4*)_t383->b + hr_ix(_i383, _t383->n, "hc/parse.amni:149"); }))).a_ = ((int32_t)(q__279));
 }
{ int64_t q__280 = f66_pblock(hr_str("while body", 10)); 
((*({ hrv *_t384 = &(g675); int64_t _i384 = e_278; (S4*)_t384->b + hr_ix(_i384, _t384->n, "hc/parse.amni:149"); }))).b_ = ((int32_t)(q__280));
 }
if (g685) { g686 = true;
 }
return e_278;
 }
if (((k_181) == (((int64_t)77LL)))) { (void)(f33_nx());
int64_t e_281 = f40_mk(((int64_t)26LL), st_180); 
{ int64_t q__282 = f66_pblock(hr_str("loop body", 9)); 
((*({ hrv *_t385 = &(g675); int64_t _i385 = e_281; (S4*)_t385->b + hr_ix(_i385, _t385->n, "hc/parse.amni:150"); }))).a_ = ((int32_t)(q__282));
 }
if (g685) { g686 = true;
 }
return e_281;
 }
if (((k_181) == (((int64_t)75LL)))) { int64_t e_294 = f79_pfor(); 
if (g685) { g686 = true;
 }
return e_294;
 }
if (((k_181) == (((int64_t)79LL)))) { (void)(f38_perr(hr_str("guard is a statement: it guards the rest of the block it is in", 62)));
return f40_mk(((int64_t)6LL), st_180);
 }
if (((k_181) == (((int64_t)81LL)))) { (void)(f33_nx());
bool sl_295 = g685; 
bool se_296 = g686; 
g685 = false;
g686 = false;
int64_t r_297 = f40_mk(((int64_t)28LL), st_180); 
if (((((f31_tk()) != (((int64_t)12LL))) && ((f31_tk()) != (((int64_t)10LL)))) && (!(f42_at_from())))) { int64_t m_298 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v387 = &(g677); int32_t _x387 = ((int32_t)(f61_pexpr())); int32_t *_p387 = (int32_t*)hr_grow(_v387, 1, sizeof _x387); *_p387 = _x387; _p387; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk386; }
 }
 } _bk386:; 
(void)(f59_setl(r_297, m_298));
 }
if (f42_at_from()) { (void)(f33_nx());
{ int64_t q__299 = f56_qname(hr_str("return from", 11)); 
((*({ hrv *_t388 = &(g675); int64_t _i388 = r_297; (S4*)_t388->b + hr_ix(_i388, _t388->n, "hc/parse.amni:158"); }))).s_ = ((int32_t)(q__299));
 }
 }
g685 = sl_295;
g686 = se_296;
return r_297;
 }
if (((k_181) == (((int64_t)82LL)))) { (void)(f33_nx());
bool sl_300 = g685; 
bool se_301 = g686; 
g685 = false;
g686 = false;
int64_t r_302 = f40_mk(((int64_t)29LL), st_180); 
if ((((f31_tk()) != (((int64_t)12LL))) && ((f31_tk()) != (((int64_t)10LL))))) { { int64_t q__303 = f61_pexpr(); 
((*({ hrv *_t389 = &(g675); int64_t _i389 = r_302; (S4*)_t389->b + hr_ix(_i389, _t389->n, "hc/parse.amni:166"); }))).a_ = ((int32_t)(q__303));
 }
 }
g685 = sl_300;
g686 = se_301;
return r_302;
 }
if (((k_181) == (((int64_t)83LL)))) { (void)(f33_nx());
return f40_mk(((int64_t)30LL), st_180);
 }
return f80_pbin(((int64_t)1LL));
}
static int64_t f62_pif(void) {
int64_t st_182 = g680; 
(void)(f33_nx());
int64_t n_183 = f40_mk(((int64_t)19LL), st_182); 
{ int64_t q__189 = f63_pscrut(); 
((*({ hrv *_t390 = &(g675); int64_t _i390 = n_183; (S4*)_t390->b + hr_ix(_i390, _t390->n, "hc/parse.amni:180"); }))).a_ = ((int32_t)(q__189));
 }
{ int64_t q__268 = f66_pblock(hr_str("if body", 7)); 
((*({ hrv *_t391 = &(g675); int64_t _i391 = n_183; (S4*)_t391->b + hr_ix(_i391, _t391->n, "hc/parse.amni:181"); }))).b_ = ((int32_t)(q__268));
 }
if (f41_is(((int64_t)73LL))) { { int64_t q__269 = ({ int64_t _r392; if (((f31_tk()) == (((int64_t)72LL)))) { _r392 = f62_pif();  } else { _r392 = f66_pblock(hr_str("else body", 9));  } _r392; }); 
((*({ hrv *_t393 = &(g675); int64_t _i393 = n_183; (S4*)_t393->b + hr_ix(_i393, _t393->n, "hc/parse.amni:182"); }))).c_ = ((int32_t)(q__269));
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
int64_t s_185 = ((int64_t)((int64_t)((int64_t)((int64_t)({ int64_t _r394; if (g684) { _r394 = ((int64_t)1LL);  } else { _r394 = ((int64_t)0LL);  } _r394; }) | (int64_t)({ int64_t _r395; if (g685) { _r395 = ((int64_t)2LL);  } else { _r395 = ((int64_t)0LL);  } _r395; }))) | (int64_t)({ int64_t _r396; if (g686) { _r396 = ((int64_t)4LL);  } else { _r396 = ((int64_t)0LL);  } _r396; }))); 
g684 = nosl_184;
g685 = false;
g686 = false;
return s_185;
}
static void f65_sub_end(int64_t s_188) {
g684 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)));
g685 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)));
g686 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL)));
}
static int64_t f66_pblock(hsl ctx_190) {
int64_t st_191 = g680; 
(void)(f39_ex(((int64_t)9LL), ctx_190));
int64_t b_192 = f40_mk(((int64_t)23LL), st_191); 
(void)(f67_pbody(b_192));
return b_192;
}
static void f67_pbody(int64_t b_193) {
int64_t s_194 = f64_sub_begin(false); 
int64_t m_195 = f52_wbeg(); 
for (;;) { g685 = false;
g686 = false;
if (f41_is(((int64_t)10LL))) { { goto _bk397; }
 }
if (((f31_tk()) == (((int64_t)0LL)))) { (void)(f38_perr(hr_str("expected '}' before end of file", 31)));
{ goto _bk397; }
 }
if ((!(f68_pstmt(b_193)))) { { goto _bk397; }
 }
 } _bk397:; 
(void)(f59_setl(b_193, m_195));
(void)(f65_sub_end(s_194));
}
static bool f68_pstmt(int64_t b_196) {
int64_t k_197 = f31_tk(); 
if (((((((((f46_at_inline() || f47_at_checkfree()) || f48_at_lut()) || ((k_197) == (((int64_t)65LL)))) || ((k_197) == (((int64_t)61LL)))) || ((k_197) == (((int64_t)62LL)))) || ((k_197) == (((int64_t)68LL)))) || ((k_197) == (((int64_t)63LL)))) || ((k_197) == (((int64_t)64LL))))) { (void)(({ hrv *_v398 = &(g677); int32_t _x398 = ((int32_t)(f49_pfn(true, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p398 = (int32_t*)hr_grow(_v398, 1, sizeof _x398); *_p398 = _x398; _p398; }));
return true;
 }
if ((((((k_197) == (((int64_t)66LL))) || ((k_197) == (((int64_t)67LL)))) || ((k_197) == (((int64_t)69LL)))) || ((k_197) == (((int64_t)71LL))))) { if ((((k_197) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g680 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v399 = &(g677); int32_t _x399 = ((int32_t)(f69_pcfor(((int64_t)0LL)))); int32_t *_p399 = (int32_t*)hr_grow(_v399, 1, sizeof _x399); *_p399 = _x399; _p399; }));
return true;
 }
int64_t v_247 = f74_pvdecl(false); 
(void)(f39_ex(((int64_t)12LL), hr_str("variable declaration", 20)));
(void)(({ hrv *_v400 = &(g677); int32_t _x400 = ((int32_t)(v_247)); int32_t *_p400 = (int32_t*)hr_grow(_v400, 1, sizeof _x400); *_p400 = _x400; _p400; }));
return true;
 }
if (((k_197) == (((int64_t)79LL)))) { (void)(f76_pguard(b_196));
return false;
 }
g685 = true;
int64_t e_254 = f61_pexpr(); 
g685 = false;
int64_t st_255 = g680; 
if ((!(g686))) { int64_t o_256 = f31_tk(); 
if ((((((((((((((o_256) == (((int64_t)36LL))) || ((o_256) == (((int64_t)18LL)))) || ((o_256) == (((int64_t)26LL)))) || ((o_256) == (((int64_t)27LL)))) || ((o_256) == (((int64_t)28LL)))) || ((o_256) == (((int64_t)29LL)))) || ((o_256) == (((int64_t)30LL)))) || ((o_256) == (((int64_t)31LL)))) || ((o_256) == (((int64_t)32LL)))) || ((o_256) == (((int64_t)33LL)))) || ((o_256) == (((int64_t)45LL)))) || ((o_256) == (((int64_t)46LL))))) { (void)(f33_nx());
int64_t r_257 = f61_pexpr(); 
(void)(f39_ex(((int64_t)12LL), hr_str("assignment statement", 20)));
int64_t n_258 = f40_mk(((int64_t)34LL), st_255); 
((*({ hrv *_t401 = &(g675); int64_t _i401 = n_258; (S4*)_t401->b + hr_ix(_i401, _t401->n, "hc/parse.amni:528"); }))).op_ = ((uint8_t)(o_256));
((*({ hrv *_t402 = &(g675); int64_t _i402 = n_258; (S4*)_t402->b + hr_ix(_i402, _t402->n, "hc/parse.amni:528"); }))).a_ = ((int32_t)(e_254));
((*({ hrv *_t403 = &(g675); int64_t _i403 = n_258; (S4*)_t403->b + hr_ix(_i403, _t403->n, "hc/parse.amni:528"); }))).b_ = ((int32_t)(r_257));
(void)(({ hrv *_v404 = &(g677); int32_t _x404 = ((int32_t)(n_258)); int32_t *_p404 = (int32_t*)hr_grow(_v404, 1, sizeof _x404); *_p404 = _x404; _p404; }));
return true;
 }
if ((((o_256) == (((int64_t)34LL))) || ((o_256) == (((int64_t)35LL))))) { (void)(f33_nx());
(void)(f39_ex(((int64_t)12LL), hr_str("increment statement", 19)));
int64_t n_259 = f40_mk(((int64_t)35LL), st_255); 
((*({ hrv *_t405 = &(g675); int64_t _i405 = n_259; (S4*)_t405->b + hr_ix(_i405, _t405->n, "hc/parse.amni:530"); }))).op_ = ((uint8_t)(o_256));
((*({ hrv *_t406 = &(g675); int64_t _i406 = n_259; (S4*)_t406->b + hr_ix(_i406, _t406->n, "hc/parse.amni:530"); }))).a_ = ((int32_t)(e_254));
(void)(({ hrv *_v407 = &(g677); int32_t _x407 = ((int32_t)(n_259)); int32_t *_p407 = (int32_t*)hr_grow(_v407, 1, sizeof _x407); *_p407 = _x407; _p407; }));
return true;
 }
if (((o_256) == (((int64_t)11LL)))) { (void)(({ hrv *_v408 = &(g677); int32_t _x408 = ((int32_t)(f77_pmulti(e_254, st_255))); int32_t *_p408 = (int32_t*)hr_grow(_v408, 1, sizeof _x408); *_p408 = _x408; _p408; }));
return true;
 }
 }
if (f41_is(((int64_t)12LL))) { (void)(({ hrv *_v409 = &(g677); int32_t _x409 = ((int32_t)(e_254)); int32_t *_p409 = (int32_t*)hr_grow(_v409, 1, sizeof _x409); *_p409 = _x409; _p409; }));
return true;
 }
if (f41_is(((int64_t)10LL))) { ((*({ hrv *_t410 = &(g675); int64_t _i410 = b_196; (S4*)_t410->b + hr_ix(_i410, _t410->n, "hc/parse.amni:534"); }))).a_ = ((int32_t)(e_254));
return false;
 }
if (g686) { (void)(({ hrv *_v411 = &(g677); int32_t _x411 = ((int32_t)(e_254)); int32_t *_p411 = (int32_t*)hr_grow(_v411, 1, sizeof _x411); *_p411 = _x411; _p411; }));
return true;
 }
hrv m_267 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o413 = &(m_267); hr_fs(_o413, hr_str("';' expected after expression, found '", 38)); hr_fs(_o413, f35_cur_text()); hr_fs(_o413, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_267)));
return false;
}
static int64_t f69_pcfor(int64_t mode_198) {
int64_t cf_199 = f40_mk(((int64_t)37LL), g680); 
(void)(f39_ex(((int64_t)69LL), hr_str("const for", 9)));
(void)(f39_ex(((int64_t)75LL), hr_str("const for", 9)));
(void)(f39_ex(((int64_t)39LL), hr_str("const for bindings", 18)));
int64_t nb_200 = f40_mk(((int64_t)36LL), g680); 
int64_t m_201 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v415 = &(g677); int32_t _x415 = ((int32_t)(f34_ident(hr_str("const for binding", 17)))); int32_t *_p415 = (int32_t*)hr_grow(_v415, 1, sizeof _x415); *_p415 = _x415; _p415; }));
if (((!(f41_is(((int64_t)11LL)))) || ((f31_tk()) == (((int64_t)40LL))))) { { goto _bk414; }
 }
 } _bk414:; 
(void)(f59_setl(nb_200, m_201));
(void)(f58_close_angle(hr_str("const for bindings", 18)));
(void)(f39_ex(((int64_t)76LL), hr_str("const for", 9)));
((*({ hrv *_t416 = &(g675); int64_t _i416 = cf_199; (S4*)_t416->b + hr_ix(_i416, _t416->n, "hc/parse.amni:426"); }))).a_ = ((int32_t)(nb_200));
int64_t src_202 = f40_mk(((int64_t)36LL), g680); 
if (f41_is(((int64_t)7LL))) { ((*({ hrv *_t417 = &(g675); int64_t _i417 = cf_199; (S4*)_t417->b + hr_ix(_i417, _t417->n, "hc/parse.amni:429"); }))).op_ = ((uint8_t)1LL);
int64_t s_203 = f64_sub_begin(false); 
int64_t m2_204 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)8LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v419 = &(g677); int32_t _x419 = ((int32_t)(f61_pexpr())); int32_t *_p419 = (int32_t*)hr_grow(_v419, 1, sizeof _x419); *_p419 = _x419; _p419; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk418; }
 }
 } _bk418:; 
(void)(f39_ex(((int64_t)8LL), hr_str("const for constant list", 23)));
(void)(f59_setl(src_202, m2_204));
(void)(f65_sub_end(s_203));
 } else { int64_t q_205 = f34_ident(hr_str("const for source", 16)); 
((*({ hrv *_t420 = &(g675); int64_t _i420 = cf_199; (S4*)_t420->b + hr_ix(_i420, _t420->n, "hc/parse.amni:435"); }))).op_ = ((uint8_t)(({ uint8_t _r421; if (((q_205) == (g698))) { _r421 = ((uint8_t)2LL);  } else { _r421 = ({ uint8_t _r422; if (((q_205) == (g700))) { _r422 = ((uint8_t)3LL);  } else { _r422 = ({ uint8_t _r423; if (((q_205) == (g699))) { _r423 = ((uint8_t)4LL);  } else { _r423 = ((uint8_t)0LL);  } _r423; });  } _r422; });  } _r421; })));
if (((((*({ hrv *_t424 = &(g675); int64_t _i424 = cf_199; (S4*)_t424->b + hr_ix(_i424, _t424->n, "hc/parse.amni:436"); }))).op_) == (((uint8_t)0LL)))) { (void)(f38_perr(hr_str("const for source must be fields<T>, variants<E>, types<...>, or [constants]", 75)));
 }
(void)(f39_ex(((int64_t)39LL), hr_str("const for source", 16)));
int64_t m2_206 = f52_wbeg(); 
while (((((f31_tk()) != (((int64_t)40LL))) && ((f31_tk()) != (((int64_t)44LL)))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v426 = &(g677); int32_t _x426 = ((int32_t)(f53_ptype())); int32_t *_p426 = (int32_t*)hr_grow(_v426, 1, sizeof _x426); *_p426 = _x426; _p426; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk425; }
 }
 } _bk425:; 
(void)(f58_close_angle(hr_str("const for source", 16)));
(void)(f59_setl(src_202, m2_206));
 }
((*({ hrv *_t427 = &(g675); int64_t _i427 = cf_199; (S4*)_t427->b + hr_ix(_i427, _t427->n, "hc/parse.amni:440"); }))).b_ = ((int32_t)(src_202));
((*({ hrv *_t428 = &(g675); int64_t _i428 = cf_199; (S4*)_t428->b + hr_ix(_i428, _t428->n, "hc/parse.amni:441"); }))).fl_ = ((uint16_t)(mode_198));
if (((mode_198) == (((int64_t)1LL)))) { int64_t il_207 = f40_mk(((int64_t)36LL), g680); 
(void)(f70_pinits(il_207, true));
((*({ hrv *_t429 = &(g675); int64_t _i429 = cf_199; (S4*)_t429->b + hr_ix(_i429, _t429->n, "hc/parse.amni:442"); }))).c_ = ((int32_t)(il_207));
 } else { if (((mode_198) == (((int64_t)2LL)))) { (void)(f39_ex(((int64_t)9LL), hr_str("const for arms", 14)));
int64_t al_214 = f40_mk(((int64_t)36LL), g680); 
(void)(f71_parms(al_214));
(void)(f39_ex(((int64_t)10LL), hr_str("const for arms", 14)));
((*({ hrv *_t430 = &(g675); int64_t _i430 = cf_199; (S4*)_t430->b + hr_ix(_i430, _t430->n, "hc/parse.amni:443"); }))).c_ = ((int32_t)(al_214));
 } else { { int64_t q__237 = f66_pblock(hr_str("const for body", 14)); 
((*({ hrv *_t431 = &(g675); int64_t _i431 = cf_199; (S4*)_t431->b + hr_ix(_i431, _t431->n, "hc/parse.amni:443"); }))).c_ = ((int32_t)(q__237));
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
{ uint16_t *_t433 = &(((*({ hrv *_t434 = &(g675); int64_t _i434 = n_208; (S4*)_t434->b + hr_ix(_i434, _t434->n, "hc/parse.amni:451"); }))).fl_); *_t433 = ((uint16_t)((uint64_t)(*_t433) | (uint64_t)((uint16_t)1LL))); }
{ goto _bk432; }
 }
if ((((f31_tk()) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g680 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v435 = &(g677); int32_t _x435 = ((int32_t)(f69_pcfor(((int64_t)1LL)))); int32_t *_p435 = (int32_t*)hr_grow(_v435, 1, sizeof _x435); *_p435 = _x435; _p435; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk432; }
 }
continue;
 }
int64_t fi_212 = f40_mk(((int64_t)18LL), g680); 
if ((((f31_tk()) == (((int64_t)1LL))) && ((f44_tkat(((int64_t)((int64_t)g680 + (int64_t)((int64_t)1LL))))) == (((int64_t)13LL))))) { ((*({ hrv *_t436 = &(g675); int64_t _i436 = fi_212; (S4*)_t436->b + hr_ix(_i436, _t436->n, "hc/parse.amni:454"); }))).s_ = ((int32_t)(((*({ hrv *_t437 = &(g885); int64_t _i437 = g680; (S3*)_t437->b + hr_ix(_i437, _t437->n, "hc/parse.amni:454"); }))).v_));
(void)(f33_nx());
(void)(f33_nx());
 }
{ int64_t q__213 = f61_pexpr(); 
((*({ hrv *_t438 = &(g675); int64_t _i438 = fi_212; (S4*)_t438->b + hr_ix(_i438, _t438->n, "hc/parse.amni:455"); }))).a_ = ((int32_t)(q__213));
 }
(void)(({ hrv *_v439 = &(g677); int32_t _x439 = ((int32_t)(fi_212)); int32_t *_p439 = (int32_t*)hr_grow(_v439, 1, sizeof _x439); *_p439 = _x439; _p439; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk432; }
 }
 } _bk432:; 
(void)(f39_ex(((int64_t)10LL), hr_str("struct literal", 14)));
(void)(f59_setl(n_208, m_211));
(void)(f65_sub_end(s_210));
}
static void f71_parms(int64_t n_215) {
int64_t s_216 = f64_sub_begin(g684); 
int64_t m_217 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { if ((((f31_tk()) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g680 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v441 = &(g677); int32_t _x441 = ((int32_t)(f69_pcfor(((int64_t)2LL)))); int32_t *_p441 = (int32_t*)hr_grow(_v441, 1, sizeof _x441); *_p441 = _x441; _p441; }));
 } else { int64_t a_235 = f72_ppattern(); 
(void)(f39_ex(((int64_t)55LL), hr_str("match arm", 9)));
{ int64_t q__236 = f61_pexpr(); 
((*({ hrv *_t442 = &(g675); int64_t _i442 = a_235; (S4*)_t442->b + hr_ix(_i442, _t442->n, "hc/parse.amni:218"); }))).b_ = ((int32_t)(q__236));
 }
(void)(({ hrv *_v443 = &(g677); int32_t _x443 = ((int32_t)(a_235)); int32_t *_p443 = (int32_t*)hr_grow(_v443, 1, sizeof _x443); *_p443 = _x443; _p443; }));
 }
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk440; }
 }
 } _bk440:; 
(void)(f59_setl(n_215, m_217));
(void)(f65_sub_end(s_216));
}
static int64_t f72_ppattern(void) {
int64_t a_218 = f40_mk(((int64_t)21LL), g680); 
if (f43_at_word(g696)) { (void)(f33_nx());
((*({ hrv *_t444 = &(g675); int64_t _i444 = a_218; (S4*)_t444->b + hr_ix(_i444, _t444->n, "hc/parse.amni:226"); }))).fl_ = ((uint16_t)1LL);
if (((f31_tk()) == (((int64_t)11LL)))) { (void)(f38_perr(hr_str("_ cannot be listed with other patterns", 38)));
 }
return a_218;
 }
int64_t m_219 = f52_wbeg(); 
for (;;) { int64_t it_220 = f40_mk(((int64_t)22LL), g680); 
{ int64_t q__229 = f73_pbound(); 
((*({ hrv *_t446 = &(g675); int64_t _i446 = it_220; (S4*)_t446->b + hr_ix(_i446, _t446->n, "hc/parse.amni:230"); }))).a_ = ((int32_t)(q__229));
 }
if (f41_is(((int64_t)17LL))) { { int64_t q__230 = f73_pbound(); 
((*({ hrv *_t447 = &(g675); int64_t _i447 = it_220; (S4*)_t447->b + hr_ix(_i447, _t447->n, "hc/parse.amni:231"); }))).b_ = ((int32_t)(q__230));
 }
 }
(void)(({ hrv *_v448 = &(g677); int32_t _x448 = ((int32_t)(it_220)); int32_t *_p448 = (int32_t*)hr_grow(_v448, 1, sizeof _x448); *_p448 = _x448; _p448; }));
int64_t lo_231 = ((int64_t)(((*({ hrv *_t449 = &(g675); int64_t _i449 = it_220; (S4*)_t449->b + hr_ix(_i449, _t449->n, "hc/parse.amni:233"); }))).a_)); 
if (((((((*({ hrv *_t450 = &(g675); int64_t _i450 = lo_231; (S4*)_t450->b + hr_ix(_i450, _t450->n, "hc/parse.amni:234"); }))).k_) == (((uint8_t)8LL))) && ((((*({ hrv *_t451 = &(g675); int64_t _i451 = it_220; (S4*)_t451->b + hr_ix(_i451, _t451->n, "hc/parse.amni:234"); }))).b_) < (((int32_t)0LL)))) && (((f31_tk()) == (((int64_t)49LL))) || ((f31_tk()) == (((int64_t)1LL)))))) { bool hasq_232 = false; 
{ hsl _v453 = f10_nm(((int64_t)(((*({ hrv *_t454 = &(g675); int64_t _i454 = lo_231; (S4*)_t454->b + hr_ix(_i454, _t454->n, "hc/parse.amni:235"); }))).s_))); for (int64_t _k453 = 0; _k453 < _v453.n; _k453++) { uint8_t c_233 = ((uint8_t*)_v453.p)[_k453]; if (((c_233) == (((uint8_t)58LL)))) { hasq_232 = true;
 }
 } } _bk452:; 
if ((!(hasq_232))) { if (((((int64_t)((int64_t)(g677).n - (int64_t)m_219))) > (((int64_t)1LL)))) { (void)(f38_perr(hr_str("a list of patterns binds no payload: give the variant an arm of its own", 71)));
 }
if (f41_is(((int64_t)49LL))) { { uint16_t *_t455 = &(((*({ hrv *_t456 = &(g675); int64_t _i456 = a_218; (S4*)_t456->b + hr_ix(_i456, _t456->n, "hc/parse.amni:238"); }))).fl_); *_t455 = ((uint16_t)((uint64_t)(*_t455) | (uint64_t)((uint16_t)2LL))); }
 }
{ int64_t q__234 = f34_ident(hr_str("match binding", 13)); 
((*({ hrv *_t457 = &(g675); int64_t _i457 = a_218; (S4*)_t457->b + hr_ix(_i457, _t457->n, "hc/parse.amni:239"); }))).s_ = ((int32_t)(q__234));
 }
if (((f31_tk()) == (((int64_t)11LL)))) { (void)(f38_perr(hr_str("a list of patterns binds no payload: give the variant an arm of its own", 71)));
 }
(void)(f59_setl(a_218, m_219));
return a_218;
 }
 }
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk445; }
 }
if (f43_at_word(g696)) { (void)(f38_perr(hr_str("_ cannot be listed with other patterns", 38)));
 }
 } _bk445:; 
(void)(f59_setl(a_218, m_219));
return a_218;
}
static int64_t f73_pbound(void) {
int64_t st_221 = g680; 
bool neg_222 = f41_is(((int64_t)22LL)); 
if ((((f31_tk()) == (((int64_t)1LL))) || ((f31_tk()) == (((int64_t)15LL))))) { int64_t n_223 = f40_mk(((int64_t)8LL), g680); 
{ int64_t q__224 = f56_qname(hr_str("match pattern", 13)); 
((*({ hrv *_t458 = &(g675); int64_t _i458 = n_223; (S4*)_t458->b + hr_ix(_i458, _t458->n, "hc/parse.amni:254"); }))).s_ = ((int32_t)(q__224));
 }
if (neg_222) { int64_t u_225 = f40_mk(((int64_t)10LL), st_221); 
((*({ hrv *_t459 = &(g675); int64_t _i459 = u_225; (S4*)_t459->b + hr_ix(_i459, _t459->n, "hc/parse.amni:254"); }))).op_ = ((uint8_t)(((uint8_t)22LL)));
((*({ hrv *_t460 = &(g675); int64_t _i460 = u_225; (S4*)_t460->b + hr_ix(_i460, _t460->n, "hc/parse.amni:254"); }))).a_ = ((int32_t)(n_223));
return u_225;
 }
return n_223;
 }
if (((f31_tk()) != (((int64_t)2LL)))) { hrv m_226 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o462 = &(m_226); hr_fs(_o462, hr_str("integer constant expected in match pattern, found '", 51)); hr_fs(_o462, f35_cur_text()); hr_fs(_o462, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_226)));
return f40_mk(((int64_t)1LL), st_221);
 }
int64_t n_227 = f40_mk(((int64_t)1LL), g680); 
(void)(f33_nx());
if (neg_222) { int64_t u_228 = f40_mk(((int64_t)10LL), st_221); 
((*({ hrv *_t463 = &(g675); int64_t _i463 = u_228; (S4*)_t463->b + hr_ix(_i463, _t463->n, "hc/parse.amni:257"); }))).op_ = ((uint8_t)(((uint8_t)22LL)));
((*({ hrv *_t464 = &(g675); int64_t _i464 = u_228; (S4*)_t464->b + hr_ix(_i464, _t464->n, "hc/parse.amni:257"); }))).a_ = ((int32_t)(n_227));
return u_228;
 }
return n_227;
}
static int64_t f74_pvdecl(bool glob_238) {
int64_t st_239 = g680; 
int64_t fl_240 = ({ int64_t _r465; if (glob_238) { _r465 = ((int64_t)8LL);  } else { _r465 = ((int64_t)0LL);  } _r465; }); 
if (f41_is(((int64_t)71LL))) { { int64_t *_t466 = &(fl_240); *_t466 = ((int64_t)((int64_t)(*_t466) | (int64_t)((int64_t)16LL))); }
if (f41_is(((int64_t)7LL))) { (void)(f39_ex(((int64_t)8LL), hr_str("reusable[]", 10)));
{ int64_t *_t467 = &(fl_240); *_t467 = ((int64_t)((int64_t)(*_t467) | (int64_t)((int64_t)32LL))); }
 }
 }
if (f41_is(((int64_t)67LL))) { { int64_t *_t468 = &(fl_240); *_t468 = ((int64_t)((int64_t)(*_t468) | (int64_t)((int64_t)1LL))); }
 } else { if (f41_is(((int64_t)66LL))) {  } else { if (f41_is(((int64_t)69LL))) { { int64_t *_t469 = &(fl_240); *_t469 = ((int64_t)((int64_t)(*_t469) | (int64_t)((int64_t)2LL))); }
 } else { (void)(f38_perr(hr_str("let, var or const expected", 26)));
 }
 }
 }
int64_t v_241 = f40_mk(((int64_t)33LL), st_239); 
int64_t m_242 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v471 = &(g677); int32_t _x471 = ((int32_t)(({ int64_t _r472; if (glob_238) { _r472 = f50_declname(hr_str("global declaration", 18));  } else { _r472 = f34_ident(hr_str("variable declaration", 20));  } _r472; }))); int32_t *_p471 = (int32_t*)hr_grow(_v471, 1, sizeof _x471); *_p471 = _x471; _p471; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk470; }
 }
 } _bk470:; 
(void)(f59_setl(v_241, m_242));
((*({ hrv *_t473 = &(g675); int64_t _i473 = v_241; (S4*)_t473->b + hr_ix(_i473, _t473->n, "hc/parse.amni:571"); }))).c_ = ((int32_t)(g687));
if ((f41_is(((int64_t)13LL)) || f75_amni_type())) { { int64_t q__244 = f53_ptype(); 
((*({ hrv *_t474 = &(g675); int64_t _i474 = v_241; (S4*)_t474->b + hr_ix(_i474, _t474->n, "hc/parse.amni:572"); }))).a_ = ((int32_t)(q__244));
 }
 }
if (f41_is(((int64_t)18LL))) { { int64_t *_t475 = &(fl_240); *_t475 = ((int64_t)((int64_t)(*_t475) | (int64_t)((int64_t)4LL))); }
 }
if ((((((int64_t)((int64_t)fl_240 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL))) || f41_is(((int64_t)36LL)))) { int64_t il_245 = f40_mk(((int64_t)36LL), g680); 
int64_t m2_246 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v477 = &(g677); int32_t _x477 = ((int32_t)(f61_pexpr())); int32_t *_p477 = (int32_t*)hr_grow(_v477, 1, sizeof _x477); *_p477 = _x477; _p477; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk476; }
 }
 } _bk476:; 
(void)(f59_setl(il_245, m2_246));
((*({ hrv *_t478 = &(g675); int64_t _i478 = v_241; (S4*)_t478->b + hr_ix(_i478, _t478->n, "hc/parse.amni:574"); }))).b_ = ((int32_t)(il_245));
 }
((*({ hrv *_t479 = &(g675); int64_t _i479 = v_241; (S4*)_t479->b + hr_ix(_i479, _t479->n, "hc/parse.amni:575"); }))).fl_ = ((uint16_t)(fl_240));
if (glob_238) { if ((((((*({ hrv *_t480 = &(g675); int64_t _i480 = v_241; (S4*)_t480->b + hr_ix(_i480, _t480->n, "hc/parse.amni:577"); }))).b_) < (((int32_t)0LL))) && ((((int64_t)((int64_t)fl_240 & (int64_t)((int64_t)1LL)))) == (((int64_t)0LL))))) { (void)(f38_perr(hr_str("let and const global declarations require an initializer", 56)));
 }
if (((((*({ hrv *_t481 = &(g675); int64_t _i481 = v_241; (S4*)_t481->b + hr_ix(_i481, _t481->n, "hc/parse.amni:578"); }))).n_) != (((int32_t)1LL)))) { (void)(f38_perr(hr_str("global declarations declare a single name", 41)));
 }
 }
return v_241;
}
static bool f75_amni_type(void) {
int64_t k_243 = f31_tk(); 
return (((*({ hrv *_t482 = &(g884); int64_t _i482 = ((*({ hrv *_t483 = &(g885); int64_t _i483 = g680; (S3*)_t483->b + hr_ix(_i483, _t483->n, "hc/parse.amni:74"); }))).f_; (S2*)_t482->b + hr_ix(_i482, _t482->n, "hc/parse.amni:74"); }))).amni_ && (((((f55_prim_tok(k_243) || ((k_243) == (((int64_t)1LL)))) || ((k_243) == (((int64_t)15LL)))) || ((k_243) == (((int64_t)61LL)))) || ((k_243) == (((int64_t)5LL)))) || ((k_243) == (((int64_t)69LL)))));
}
static void f76_pguard(int64_t b_248) {
int64_t st_249 = g680; 
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
((*({ hrv *_t484 = &(g675); int64_t _i484 = i_253; (S4*)_t484->b + hr_ix(_i484, _t484->n, "hc/parse.amni:559"); }))).a_ = ((int32_t)(c_250));
((*({ hrv *_t485 = &(g675); int64_t _i485 = i_253; (S4*)_t485->b + hr_ix(_i485, _t485->n, "hc/parse.amni:559"); }))).b_ = ((int32_t)(rest_252));
((*({ hrv *_t486 = &(g675); int64_t _i486 = i_253; (S4*)_t486->b + hr_ix(_i486, _t486->n, "hc/parse.amni:559"); }))).c_ = ((int32_t)(eb_251));
((*({ hrv *_t487 = &(g675); int64_t _i487 = i_253; (S4*)_t487->b + hr_ix(_i487, _t487->n, "hc/parse.amni:559"); }))).fl_ = ((uint16_t)1LL);
if (((((*({ hrv *_t488 = &(g675); int64_t _i488 = rest_252; (S4*)_t488->b + hr_ix(_i488, _t488->n, "hc/parse.amni:560"); }))).a_) >= (((int32_t)0LL)))) { ((*({ hrv *_t489 = &(g675); int64_t _i489 = b_248; (S4*)_t489->b + hr_ix(_i489, _t489->n, "hc/parse.amni:560"); }))).a_ = ((int32_t)(i_253));
 } else { (void)(({ hrv *_v490 = &(g677); int32_t _x490 = ((int32_t)(i_253)); int32_t *_p490 = (int32_t*)hr_grow(_v490, 1, sizeof _x490); *_p490 = _x490; _p490; }));
 }
}
static int64_t f77_pmulti(int64_t first_260, int64_t st_261) {
int64_t tl_262 = f40_mk(((int64_t)36LL), st_261); 
int64_t m_263 = f52_wbeg(); 
(void)(({ hrv *_v491 = &(g677); int32_t _x491 = ((int32_t)(first_260)); int32_t *_p491 = (int32_t*)hr_grow(_v491, 1, sizeof _x491); *_p491 = _x491; _p491; }));
while (f41_is(((int64_t)11LL))) { (void)(({ hrv *_v493 = &(g677); int32_t _x493 = ((int32_t)(f61_pexpr())); int32_t *_p493 = (int32_t*)hr_grow(_v493, 1, sizeof _x493); *_p493 = _x493; _p493; }));
 } _bk492:; 
(void)(f59_setl(tl_262, m_263));
int64_t o_264 = f31_tk(); 
if (((((((((((((o_264) == (((int64_t)18LL))) || ((o_264) == (((int64_t)26LL)))) || ((o_264) == (((int64_t)27LL)))) || ((o_264) == (((int64_t)28LL)))) || ((o_264) == (((int64_t)29LL)))) || ((o_264) == (((int64_t)30LL)))) || ((o_264) == (((int64_t)31LL)))) || ((o_264) == (((int64_t)32LL)))) || ((o_264) == (((int64_t)33LL)))) || ((o_264) == (((int64_t)45LL)))) || ((o_264) == (((int64_t)46LL))))) { (void)(f38_perr(hr_str("several targets take a call's results with `=` alone (\302\2477.1)", 60)));
 }
if (((f31_tk()) != (((int64_t)36LL)))) { (void)(f38_perr(hr_str("several values exist only in `return a, b;` and in a call's results, so a block or branch cannot end in `a, b`: return from each branch instead (\302\2477.1)", 151)));
 }
(void)(f33_nx());
int64_t n_265 = f40_mk(((int64_t)34LL), st_261); 
((*({ hrv *_t494 = &(g675); int64_t _i494 = n_265; (S4*)_t494->b + hr_ix(_i494, _t494->n, "hc/parse.amni:548"); }))).op_ = ((uint8_t)(((uint8_t)11LL)));
((*({ hrv *_t495 = &(g675); int64_t _i495 = n_265; (S4*)_t495->b + hr_ix(_i495, _t495->n, "hc/parse.amni:548"); }))).a_ = ((int32_t)(tl_262));
{ int64_t q__266 = f61_pexpr(); 
((*({ hrv *_t496 = &(g675); int64_t _i496 = n_265; (S4*)_t496->b + hr_ix(_i496, _t496->n, "hc/parse.amni:548"); }))).b_ = ((int32_t)(q__266));
 }
(void)(f39_ex(((int64_t)12LL), hr_str("assignment statement", 20)));
return n_265;
}
static int64_t f78_pmatch(void) {
int64_t st_271 = g680; 
(void)(f33_nx());
int64_t n_272 = f40_mk(((int64_t)20LL), st_271); 
{ int64_t q__273 = f63_pscrut(); 
((*({ hrv *_t497 = &(g675); int64_t _i497 = n_272; (S4*)_t497->b + hr_ix(_i497, _t497->n, "hc/parse.amni:206"); }))).a_ = ((int32_t)(q__273));
 }
(void)(f39_ex(((int64_t)9LL), hr_str("match expression", 16)));
(void)(f71_parms(n_272));
(void)(f39_ex(((int64_t)10LL), hr_str("match expression", 16)));
if ((((((*({ hrv *_t498 = &(g675); int64_t _i498 = n_272; (S4*)_t498->b + hr_ix(_i498, _t498->n, "hc/parse.amni:210"); }))).n_) == (((int32_t)0LL))) && (((g681).n) == (((int64_t)0LL))))) { (void)(f38_perr(hr_str("match must have at least one arm", 32)));
 }
return n_272;
}
static int64_t f79_pfor(void) {
int64_t st_283 = g680; 
(void)(f33_nx());
int64_t n_284 = f40_mk(((int64_t)27LL), st_283); 
if (f41_is(((int64_t)49LL))) { ((*({ hrv *_t499 = &(g675); int64_t _i499 = n_284; (S4*)_t499->b + hr_ix(_i499, _t499->n, "hc/parse.amni:188"); }))).fl_ = ((uint16_t)1LL);
 }
{ int64_t q__285 = f34_ident(hr_str("for binding", 11)); 
((*({ hrv *_t500 = &(g675); int64_t _i500 = n_284; (S4*)_t500->b + hr_ix(_i500, _t500->n, "hc/parse.amni:189"); }))).s_ = ((int32_t)(q__285));
 }
bool fb_286 = g727; 
g727 = true;
((*({ hrv *_t501 = &(g675); int64_t _i501 = n_284; (S4*)_t501->b + hr_ix(_i501, _t501->n, "hc/parse.amni:191"); }))).l_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));
((*({ hrv *_t502 = &(g675); int64_t _i502 = n_284; (S4*)_t502->b + hr_ix(_i502, _t502->n, "hc/parse.amni:191"); }))).n_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));
if (f41_is(((int64_t)13LL))) { { int64_t q__287 = f53_ptype(); 
((*({ hrv *_t503 = &(g675); int64_t _i503 = n_284; (S4*)_t503->b + hr_ix(_i503, _t503->n, "hc/parse.amni:192"); }))).l_ = ((int32_t)(q__287));
 }
 }
if (f41_is(((int64_t)11LL))) { { int64_t q__288 = f34_ident(hr_str("for index binding", 17)); 
((*({ hrv *_t504 = &(g675); int64_t _i504 = n_284; (S4*)_t504->b + hr_ix(_i504, _t504->n, "hc/parse.amni:193"); }))).c_ = ((int32_t)(q__288));
 }
if (f41_is(((int64_t)13LL))) { { int64_t q__289 = f53_ptype(); 
((*({ hrv *_t505 = &(g675); int64_t _i505 = n_284; (S4*)_t505->b + hr_ix(_i505, _t505->n, "hc/parse.amni:193"); }))).n_ = ((int32_t)(q__289));
 }
 }
 }
g727 = fb_286;
(void)(f39_ex(((int64_t)76LL), hr_str("for statement", 13)));
int64_t s_290 = f64_sub_begin(true); 
{ int64_t q__291 = f61_pexpr(); 
((*({ hrv *_t506 = &(g675); int64_t _i506 = n_284; (S4*)_t506->b + hr_ix(_i506, _t506->n, "hc/parse.amni:197"); }))).a_ = ((int32_t)(q__291));
 }
if (f41_is(((int64_t)17LL))) { { int64_t q__292 = f61_pexpr(); 
((*({ hrv *_t507 = &(g675); int64_t _i507 = n_284; (S4*)_t507->b + hr_ix(_i507, _t507->n, "hc/parse.amni:198"); }))).b_ = ((int32_t)(q__292));
 }
 }
(void)(f65_sub_end(s_290));
{ int64_t q__293 = f66_pblock(hr_str("for body", 8)); 
((*({ hrv *_t508 = &(g675); int64_t _i508 = n_284; (S4*)_t508->b + hr_ix(_i508, _t508->n, "hc/parse.amni:200"); }))).d_ = ((int32_t)(q__293));
 }
return n_284;
}
static int64_t f80_pbin(int64_t minp_304) {
int64_t l_383 = f81_pun(); 
for (;;) { if (g686) { return l_383;
 }
int64_t pr_385 = f92_binprec(f31_tk()); 
if ((((pr_385) < (minp_304)) || ((pr_385) == (((int64_t)0LL))))) { return l_383;
 }
int64_t op_386 = f31_tk(); 
int64_t st_387 = g680; 
(void)(f33_nx());
int64_t s_388 = f64_sub_begin(g684); 
int64_t r_389 = f80_pbin(((int64_t)((int64_t)pr_385 + (int64_t)((int64_t)1LL)))); 
(void)(f65_sub_end(s_388));
int64_t n_390 = f40_mk(((int64_t)9LL), st_387); 
((*({ hrv *_t510 = &(g675); int64_t _i510 = n_390; (S4*)_t510->b + hr_ix(_i510, _t510->n, "hc/parse.amni:280"); }))).op_ = ((uint8_t)(op_386));
((*({ hrv *_t511 = &(g675); int64_t _i511 = n_390; (S4*)_t511->b + hr_ix(_i511, _t511->n, "hc/parse.amni:280"); }))).a_ = ((int32_t)(l_383));
((*({ hrv *_t512 = &(g675); int64_t _i512 = n_390; (S4*)_t512->b + hr_ix(_i512, _t512->n, "hc/parse.amni:280"); }))).b_ = ((int32_t)(r_389));
l_383 = n_390;
 } _bk509:; 
}
static int64_t f81_pun(void) {
int64_t k_305 = f31_tk(); 
if ((((((k_305) == (((int64_t)22LL))) || ((k_305) == (((int64_t)47LL)))) || ((k_305) == (((int64_t)48LL)))) || ((k_305) == (((int64_t)49LL))))) { int64_t st_306 = g680; 
(void)(f33_nx());
int64_t s_307 = f64_sub_begin(g684); 
int64_t a_308 = f81_pun(); 
(void)(f65_sub_end(s_307));
int64_t n_309 = f40_mk(((int64_t)10LL), st_306); 
((*({ hrv *_t513 = &(g675); int64_t _i513 = n_309; (S4*)_t513->b + hr_ix(_i513, _t513->n, "hc/parse.amni:291"); }))).op_ = ((uint8_t)(k_305));
((*({ hrv *_t514 = &(g675); int64_t _i514 = n_309; (S4*)_t514->b + hr_ix(_i514, _t514->n, "hc/parse.amni:291"); }))).a_ = ((int32_t)(a_308));
return n_309;
 }
return f82_ppost();
}
static int64_t f82_ppost(void) {
int64_t e_367 = f83_pprim(); 
for (;;) { if (g686) { return e_367;
 }
int64_t st_368 = g680; 
if (f41_is(((int64_t)5LL))) { e_367 = f86_pcall(e_367, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), st_368);
continue;
 }
if (((f31_tk()) == (((int64_t)7LL)))) { e_367 = f91_pindex(e_367);
continue;
 }
if (f41_is(((int64_t)16LL))) { int64_t nmid_377 = f34_ident(hr_str("field access", 12)); 
if (((((f31_tk()) == (((int64_t)9LL))) && (!(g684))) && ((((*({ hrv *_t516 = &(g675); int64_t _i516 = e_367; (S4*)_t516->b + hr_ix(_i516, _t516->n, "hc/parse.amni:305"); }))).k_) == (((uint8_t)8LL))))) { int64_t b_378 = f40_mk(((int64_t)41LL), ((int64_t)(((*({ hrv *_t517 = &(g675); int64_t _i517 = e_367; (S4*)_t517->b + hr_ix(_i517, _t517->n, "hc/parse.amni:306"); }))).t_))); 
((*({ hrv *_t518 = &(g675); int64_t _i518 = b_378; (S4*)_t518->b + hr_ix(_i518, _t518->n, "hc/parse.amni:306"); }))).s_ = ((*({ hrv *_t519 = &(g675); int64_t _i519 = e_367; (S4*)_t519->b + hr_ix(_i519, _t519->n, "hc/parse.amni:306"); }))).s_;
int64_t v_379 = f40_mk(((int64_t)46LL), st_368); 
((*({ hrv *_t520 = &(g675); int64_t _i520 = v_379; (S4*)_t520->b + hr_ix(_i520, _t520->n, "hc/parse.amni:307"); }))).a_ = ((int32_t)(b_378));
((*({ hrv *_t521 = &(g675); int64_t _i521 = v_379; (S4*)_t521->b + hr_ix(_i521, _t521->n, "hc/parse.amni:307"); }))).s_ = ((int32_t)(nmid_377));
e_367 = f89_pslit(v_379, st_368);
 } else { int64_t d_380 = f40_mk(((int64_t)14LL), st_368); 
((*({ hrv *_t522 = &(g675); int64_t _i522 = d_380; (S4*)_t522->b + hr_ix(_i522, _t522->n, "hc/parse.amni:309"); }))).a_ = ((int32_t)(e_367));
((*({ hrv *_t523 = &(g675); int64_t _i523 = d_380; (S4*)_t523->b + hr_ix(_i523, _t523->n, "hc/parse.amni:309"); }))).s_ = ((int32_t)(nmid_377));
e_367 = d_380;
 }
continue;
 }
if (f41_is(((int64_t)84LL))) { int64_t n_381 = f40_mk(((int64_t)15LL), st_368); 
((*({ hrv *_t524 = &(g675); int64_t _i524 = n_381; (S4*)_t524->b + hr_ix(_i524, _t524->n, "hc/parse.amni:312"); }))).fl_ = ({ uint16_t _r525; if (f41_is(((int64_t)47LL))) { _r525 = ((uint16_t)1LL);  } else { _r525 = ((uint16_t)0LL);  } _r525; });
((*({ hrv *_t526 = &(g675); int64_t _i526 = n_381; (S4*)_t526->b + hr_ix(_i526, _t526->n, "hc/parse.amni:312"); }))).a_ = ((int32_t)(e_367));
{ int64_t q__382 = f53_ptype(); 
((*({ hrv *_t527 = &(g675); int64_t _i527 = n_381; (S4*)_t527->b + hr_ix(_i527, _t527->n, "hc/parse.amni:312"); }))).b_ = ((int32_t)(q__382));
 }
e_367 = n_381;
continue;
 }
return e_367;
 } _bk515:; 
}
static int64_t f83_pprim(void) {
int64_t st_310 = g680; 
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
((*({ hrv *_t528 = &(g675); int64_t _i528 = id_332; (S4*)_t528->b + hr_ix(_i528, _t528->n, "hc/parse.amni:364"); }))).s_ = ((int32_t)(name_321));
return f86_pcall(id_332, ta_331, st_310);
 }
int64_t t_352 = f40_mk(((int64_t)41LL), st_310); 
((*({ hrv *_t529 = &(g675); int64_t _i529 = t_352; (S4*)_t529->b + hr_ix(_i529, _t529->n, "hc/parse.amni:365"); }))).s_ = ((int32_t)(name_321));
((*({ hrv *_t530 = &(g675); int64_t _i530 = t_352; (S4*)_t530->b + hr_ix(_i530, _t530->n, "hc/parse.amni:365"); }))).l_ = ((*({ hrv *_t531 = &(g675); int64_t _i531 = ta_331; (S4*)_t531->b + hr_ix(_i531, _t531->n, "hc/parse.amni:365"); }))).l_;
((*({ hrv *_t532 = &(g675); int64_t _i532 = t_352; (S4*)_t532->b + hr_ix(_i532, _t532->n, "hc/parse.amni:365"); }))).n_ = ((*({ hrv *_t533 = &(g675); int64_t _i533 = ta_331; (S4*)_t533->b + hr_ix(_i533, _t533->n, "hc/parse.amni:365"); }))).n_;
if (f41_is(((int64_t)16LL))) { int64_t v_353 = f40_mk(((int64_t)46LL), st_310); 
((*({ hrv *_t534 = &(g675); int64_t _i534 = v_353; (S4*)_t534->b + hr_ix(_i534, _t534->n, "hc/parse.amni:366"); }))).a_ = ((int32_t)(t_352));
{ int64_t q__354 = f34_ident(hr_str("variant literal", 15)); 
((*({ hrv *_t535 = &(g675); int64_t _i535 = v_353; (S4*)_t535->b + hr_ix(_i535, _t535->n, "hc/parse.amni:366"); }))).s_ = ((int32_t)(q__354));
 }
return f89_pslit(v_353, st_310);
 }
return f89_pslit(t_352, st_310);
 }
 }
if ((((f31_tk()) == (((int64_t)9LL))) && (!(g684)))) { int64_t t_364 = f40_mk(((int64_t)41LL), st_310); 
((*({ hrv *_t536 = &(g675); int64_t _i536 = t_364; (S4*)_t536->b + hr_ix(_i536, _t536->n, "hc/parse.amni:370"); }))).s_ = ((int32_t)(name_321));
return f89_pslit(t_364, st_310);
 }
int64_t id_365 = f40_mk(((int64_t)8LL), st_310); 
((*({ hrv *_t537 = &(g675); int64_t _i537 = id_365; (S4*)_t537->b + hr_ix(_i537, _t537->n, "hc/parse.amni:371"); }))).s_ = ((int32_t)(name_321));
return id_365;
 }
hrv m_366 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o539 = &(m_366); hr_fs(_o539, hr_str("expression expected, found '", 28)); hr_fs(_o539, f35_cur_text()); hr_fs(_o539, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_366)));
return f40_mk(((int64_t)6LL), st_310);
}
static int64_t f84_parray(void) {
int64_t st_314 = g680; 
(void)(f33_nx());
int64_t a_315 = f40_mk(((int64_t)16LL), st_314); 
int64_t s_316 = f64_sub_begin(false); 
if (f41_is(((int64_t)17LL))) { { int64_t q__317 = f61_pexpr(); 
((*({ hrv *_t540 = &(g675); int64_t _i540 = a_315; (S4*)_t540->b + hr_ix(_i540, _t540->n, "hc/parse.amni:406"); }))).c_ = ((int32_t)(q__317));
 }
 } else { if (((f31_tk()) != (((int64_t)8LL)))) { int64_t first_318 = f61_pexpr(); 
if (f41_is(((int64_t)12LL))) { ((*({ hrv *_t541 = &(g675); int64_t _i541 = a_315; (S4*)_t541->b + hr_ix(_i541, _t541->n, "hc/parse.amni:410"); }))).a_ = ((int32_t)(first_318));
{ int64_t q__319 = f61_pexpr(); 
((*({ hrv *_t542 = &(g675); int64_t _i542 = a_315; (S4*)_t542->b + hr_ix(_i542, _t542->n, "hc/parse.amni:410"); }))).b_ = ((int32_t)(q__319));
 }
 } else { int64_t m_320 = f52_wbeg(); 
(void)(({ hrv *_v543 = &(g677); int32_t _x543 = ((int32_t)(first_318)); int32_t *_p543 = (int32_t*)hr_grow(_v543, 1, sizeof _x543); *_p543 = _x543; _p543; }));
while ((f41_is(((int64_t)11LL)) && ((f31_tk()) != (((int64_t)8LL))))) { (void)(({ hrv *_v545 = &(g677); int32_t _x545 = ((int32_t)(f61_pexpr())); int32_t *_p545 = (int32_t*)hr_grow(_v545, 1, sizeof _x545); *_p545 = _x545; _p545; }));
 } _bk544:; 
(void)(f59_setl(a_315, m_320));
 }
 }
 }
(void)(f39_ex(((int64_t)8LL), hr_str("array literal", 13)));
(void)(f65_sub_end(s_316));
return a_315;
}
static int64_t f85_try_tyargs(void) {
int64_t save_322 = g680; 
int64_t nd0_323 = (g675).n; 
int64_t ls0_324 = (g676).n; 
int64_t sp0_325 = (g689).n; 
int64_t ws0_326 = (g677).n; 
g682++;
(void)(f33_nx());
int64_t l_327 = f40_mk(((int64_t)36LL), save_322); 
int64_t m_328 = f52_wbeg(); 
bool ok_329 = false; 
for (;;) { (void)(({ hrv *_v547 = &(g677); int32_t _x547 = ((int32_t)(f53_ptype())); int32_t *_p547 = (int32_t*)hr_grow(_v547, 1, sizeof _x547); *_p547 = _x547; _p547; }));
if ((g683 || (!(f41_is(((int64_t)11LL)))))) { { goto _bk546; }
 }
if ((((f31_tk()) == (((int64_t)40LL))) || ((f31_tk()) == (((int64_t)44LL))))) { { goto _bk546; }
 }
 } _bk546:; 
if ((!(g683))) { if (((f31_tk()) == (((int64_t)44LL)))) { (void)(({ hrv *_v548 = &(g689); int64_t _x548 = g680; int64_t *_p548 = (int64_t*)hr_grow(_v548, 1, sizeof _x548); *_p548 = _x548; _p548; }));
((*({ hrv *_t549 = &(g885); int64_t _i549 = g680; (S3*)_t549->b + hr_ix(_i549, _t549->n, "hc/parse.amni:386"); }))).k_ = ((uint8_t)(((uint8_t)40LL)));
ok_329 = true;
 } else { if (((f31_tk()) == (((int64_t)40LL)))) { (void)(f33_nx());
ok_329 = true;
 }
 }
if (ok_329) { ok_329 = false;
if ((((f31_tk()) == (((int64_t)5LL))) || (((f31_tk()) == (((int64_t)9LL))) && (!(g684))))) { ok_329 = true;
 }
if ((((((f31_tk()) == (((int64_t)16LL))) && (!(g684))) && ((f44_tkat(((int64_t)((int64_t)g680 + (int64_t)((int64_t)1LL))))) == (((int64_t)1LL)))) && ((f44_tkat(((int64_t)((int64_t)g680 + (int64_t)((int64_t)2LL))))) == (((int64_t)9LL))))) { ok_329 = true;
 }
 }
 }
g682--;
if ((ok_329 && (!(g683)))) { (void)(f59_setl(l_327, m_328));
return l_327;
 }
g683 = false;
while ((((g689).n) > (sp0_325))) { int64_t q_330 = ({ hrv *_v551 = &(g689); if (!_v551->n) hr_die("pop of an empty array", "hc/parse.amni:396"); ((int64_t*)_v551->b)[--_v551->n]; }); 
((*({ hrv *_t552 = &(g885); int64_t _i552 = q_330; (S3*)_t552->b + hr_ix(_i552, _t552->n, "hc/parse.amni:396"); }))).k_ = ((uint8_t)(((uint8_t)44LL)));
 } _bk550:; 
if ((((g677).n) > (ws0_326))) { (void)(({ hrv *_v553 = &(g677); int64_t _k553 = ((int64_t)((int64_t)(g677).n - (int64_t)ws0_326)); if (_k553 < 0 || _k553 > _v553->n) hr_die("pop_n past the length", "hc/parse.amni:397"); _v553->n -= _k553; }));
 }
(void)(({ hrv *_v554 = &(g675); int64_t _k554 = nd0_323; if (_k554 < 0) hr_die("resize to a negative length", "hc/parse.amni:398"); S4 _x554 = ((S4){ 0}); int64_t _o554 = _v554->n; hr_resize(_v554, _k554, sizeof _x554); for (int64_t _j = _o554; _j < _k554; _j++) ((S4*)_v554->b)[_j] = _x554; }));
(void)(({ hrv *_v555 = &(g676); int64_t _k555 = ls0_324; if (_k555 < 0) hr_die("resize to a negative length", "hc/parse.amni:398"); int32_t _x555 = ((int32_t)0LL); int64_t _o555 = _v555->n; hr_resize(_v555, _k555, sizeof _x555); for (int64_t _j = _o555; _j < _k555; _j++) ((int32_t*)_v555->b)[_j] = _x555; }));
g680 = save_322;
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f86_pcall(int64_t callee_333, int64_t tyargs_334, int64_t st_335) {
int64_t c_336 = f40_mk(((int64_t)11LL), st_335); 
((*({ hrv *_t556 = &(g675); int64_t _i556 = c_336; (S4*)_t556->b + hr_ix(_i556, _t556->n, "hc/parse.amni:317"); }))).a_ = ((int32_t)(callee_333));
((*({ hrv *_t557 = &(g675); int64_t _i557 = c_336; (S4*)_t557->b + hr_ix(_i557, _t557->n, "hc/parse.amni:317"); }))).c_ = ((int32_t)(tyargs_334));
int64_t s_337 = f64_sub_begin(false); 
int64_t m_338 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v559 = &(g677); int32_t _x559 = ((int32_t)(f61_pexpr())); int32_t *_p559 = (int32_t*)hr_grow(_v559, 1, sizeof _x559); *_p559 = _x559; _p559; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk558; }
 }
 } _bk558:; 
(void)(f39_ex(((int64_t)6LL), hr_str("call arguments", 14)));
(void)(f59_setl(c_336, m_338));
(void)(f65_sub_end(s_337));
if ((((f31_tk()) == (((int64_t)9LL))) && (!(g684)))) { { int64_t q__351 = f87_pfunval(); 
((*({ hrv *_t560 = &(g675); int64_t _i560 = c_336; (S4*)_t560->b + hr_ix(_i560, _t560->n, "hc/parse.amni:324"); }))).b_ = ((int32_t)(q__351));
 }
if (g685) { g686 = true;
 }
 }
return c_336;
}
static int64_t f87_pfunval(void) {
int64_t st_339 = g680; 
(void)(f39_ex(((int64_t)9LL), hr_str("function value", 14)));
int64_t fv_340 = f40_mk(((int64_t)31LL), st_339); 
int64_t b_341 = f40_mk(((int64_t)23LL), st_339); 
((*({ hrv *_t561 = &(g675); int64_t _i561 = fv_340; (S4*)_t561->b + hr_ix(_i561, _t561->n, "hc/parse.amni:476"); }))).a_ = ((int32_t)(b_341));
if ((((f31_tk()) == (((int64_t)1LL))) || ((f31_tk()) == (((int64_t)67LL))))) { int64_t save_342 = g680; 
int64_t nd0_343 = (g675).n; 
int64_t ws0_344 = (g677).n; 
g682++;
bool ok_345 = true; 
int64_t m_346 = f52_wbeg(); 
for (;;) { bool pv_347 = f41_is(((int64_t)67LL)); 
if (((f31_tk()) != (((int64_t)1LL)))) { ok_345 = false;
{ goto _bk562; }
 }
int64_t p_348 = f40_mk(((int64_t)32LL), g680); 
((*({ hrv *_t563 = &(g675); int64_t _i563 = p_348; (S4*)_t563->b + hr_ix(_i563, _t563->n, "hc/parse.amni:485"); }))).s_ = ((int32_t)(((*({ hrv *_t564 = &(g885); int64_t _i564 = g680; (S3*)_t564->b + hr_ix(_i564, _t564->n, "hc/parse.amni:485"); }))).v_));
if (pv_347) { ((*({ hrv *_t565 = &(g675); int64_t _i565 = p_348; (S4*)_t565->b + hr_ix(_i565, _t565->n, "hc/parse.amni:485"); }))).fl_ = ((uint16_t)1LL);
 }
(void)(f33_nx());
if (f41_is(((int64_t)13LL))) { { int64_t q__349 = f53_ptype(); 
((*({ hrv *_t566 = &(g675); int64_t _i566 = p_348; (S4*)_t566->b + hr_ix(_i566, _t566->n, "hc/parse.amni:486"); }))).a_ = ((int32_t)(q__349));
 }
 }
(void)(({ hrv *_v567 = &(g677); int32_t _x567 = ((int32_t)(p_348)); int32_t *_p567 = (int32_t*)hr_grow(_v567, 1, sizeof _x567); *_p567 = _x567; _p567; }));
if ((g683 || (!(f41_is(((int64_t)11LL)))))) { { goto _bk562; }
 }
 } _bk562:; 
if (((g683 || (!(ok_345))) || (!(f41_is(((int64_t)55LL)))))) { ok_345 = false;
 }
g682--;
if (ok_345) { (void)(f59_setl(fv_340, m_346));
((*({ hrv *_t568 = &(g675); int64_t _i568 = fv_340; (S4*)_t568->b + hr_ix(_i568, _t568->n, "hc/parse.amni:492"); }))).fl_ = ((uint16_t)1LL);
 } else { g683 = false;
if ((((g677).n) > (ws0_344))) { (void)(({ hrv *_v569 = &(g677); int64_t _k569 = ((int64_t)((int64_t)(g677).n - (int64_t)ws0_344)); if (_k569 < 0 || _k569 > _v569->n) hr_die("pop_n past the length", "hc/parse.amni:493"); _v569->n -= _k569; }));
 }
(void)(({ hrv *_v570 = &(g675); int64_t _k570 = nd0_343; if (_k570 < 0) hr_die("resize to a negative length", "hc/parse.amni:493"); S4 _x570 = ((S4){ 0}); int64_t _o570 = _v570->n; hr_resize(_v570, _k570, sizeof _x570); for (int64_t _j = _o570; _j < _k570; _j++) ((S4*)_v570->b)[_j] = _x570; }));
g680 = save_342;
 }
 }
(void)(f67_pbody(b_341));
(void)(f88_set_end(fv_340));
return fv_340;
}
static void f88_set_end(int64_t n_350) {
while ((((g690).n) < ((g675).n))) { (void)(({ hrv *_v572 = &(g690); int32_t _x572 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p572 = (int32_t*)hr_grow(_v572, 1, sizeof _x572); *_p572 = _x572; _p572; }));
 } _bk571:; 
(*({ hrv *_t573 = &(g690); int64_t _i573 = n_350; (int32_t*)_t573->b + hr_ix(_i573, _t573->n, "hc/parse.amni:28"); })) = ((int32_t)((g675).n));
}
static int64_t f89_pslit(int64_t ty_355, int64_t st_356) {
int64_t n_357 = f40_mk(((int64_t)17LL), st_356); 
((*({ hrv *_t574 = &(g675); int64_t _i574 = n_357; (S4*)_t574->b + hr_ix(_i574, _t574->n, "hc/parse.amni:464"); }))).a_ = ((int32_t)(ty_355));
(void)(f70_pinits(n_357, false));
int64_t named_358 = ((int64_t)0LL); 
bool cf_359 = false; 
{ int32_t _e576 = ((*({ hrv *_t577 = &(g675); int64_t _i577 = n_357; (S4*)_t577->b + hr_ix(_i577, _t577->n, "hc/parse.amni:467"); }))).n_; for (int32_t i_360 = 0; i_360 < _e576; i_360++) { int64_t fi_363 = f90_kid(n_357, ((int64_t)(i_360))); 
if (((((*({ hrv *_t578 = &(g675); int64_t _i578 = fi_363; (S4*)_t578->b + hr_ix(_i578, _t578->n, "hc/parse.amni:467"); }))).k_) == (((uint8_t)37LL)))) { cf_359 = true;
 } else { if (((((*({ hrv *_t579 = &(g675); int64_t _i579 = fi_363; (S4*)_t579->b + hr_ix(_i579, _t579->n, "hc/parse.amni:467"); }))).s_) >= (((int32_t)0LL)))) { named_358++;
 }
 }
 } } _bk575:; 
if ((((!(cf_359)) && ((named_358) > (((int64_t)0LL)))) && ((named_358) != (((int64_t)(((*({ hrv *_t580 = &(g675); int64_t _i580 = n_357; (S4*)_t580->b + hr_ix(_i580, _t580->n, "hc/parse.amni:468"); }))).n_)))))) { (void)(f38_perr(hr_str("struct literal mixes named and positional initializers", 54)));
 }
return n_357;
}
static int64_t f90_kid(int64_t n_361, int64_t i_362) {
return ((int64_t)((*({ hrv *_t581 = &(g676); int64_t _i581 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t582 = &(g675); int64_t _i582 = n_361; (S4*)_t582->b + hr_ix(_i582, _t582->n, "hc/parse.amni:56"); }))).l_)) + (int64_t)i_362)); (int32_t*)_t581->b + hr_ix(_i581, _t581->n, "hc/parse.amni:56"); }))));
}
static int64_t f91_pindex(int64_t obj_369) {
int64_t st_370 = g680; 
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
((*({ hrv *_t583 = &(g675); int64_t _i583 = r_375; (S4*)_t583->b + hr_ix(_i583, _t583->n, "hc/parse.amni:336"); }))).a_ = ((int32_t)(obj_369));
((*({ hrv *_t584 = &(g675); int64_t _i584 = r_375; (S4*)_t584->b + hr_ix(_i584, _t584->n, "hc/parse.amni:336"); }))).b_ = ((int32_t)(lo_372));
if (lfe_373) { ((*({ hrv *_t585 = &(g675); int64_t _i585 = r_375; (S4*)_t585->b + hr_ix(_i585, _t585->n, "hc/parse.amni:337"); }))).fl_ = ((uint16_t)1LL);
 }
if (((f31_tk()) != (((int64_t)8LL)))) { if (f41_is(((int64_t)51LL))) { { uint16_t *_t586 = &(((*({ hrv *_t587 = &(g675); int64_t _i587 = r_375; (S4*)_t587->b + hr_ix(_i587, _t587->n, "hc/parse.amni:338"); }))).fl_); *_t586 = ((uint16_t)((uint64_t)(*_t586) | (uint64_t)((uint16_t)2LL))); }
 }
{ int64_t q__376 = f61_pexpr(); 
((*({ hrv *_t588 = &(g675); int64_t _i588 = r_375; (S4*)_t588->b + hr_ix(_i588, _t588->n, "hc/parse.amni:338"); }))).c_ = ((int32_t)(q__376));
 }
 }
 } else { if (lfe_373) { (void)(f38_perr(hr_str("'^' bounds are only valid in slices", 35)));
 }
r_375 = f40_mk(((int64_t)12LL), st_370);
((*({ hrv *_t589 = &(g675); int64_t _i589 = r_375; (S4*)_t589->b + hr_ix(_i589, _t589->n, "hc/parse.amni:341"); }))).a_ = ((int32_t)(obj_369));
((*({ hrv *_t590 = &(g675); int64_t _i590 = r_375; (S4*)_t590->b + hr_ix(_i590, _t590->n, "hc/parse.amni:341"); }))).b_ = ((int32_t)(lo_372));
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
int64_t st_414 = g680; 
(void)(f33_nx());
int64_t n_415 = f40_mk(((int64_t)51LL), st_414); 
{ int64_t q__416 = f50_declname(hr_str("struct declaration", 18)); 
((*({ hrv *_t591 = &(g675); int64_t _i591 = n_415; (S4*)_t591->b + hr_ix(_i591, _t591->n, "hc/parse.amni:618"); }))).s_ = ((int32_t)(q__416));
 }
((*({ hrv *_t592 = &(g675); int64_t _i592 = n_415; (S4*)_t592->b + hr_ix(_i592, _t592->n, "hc/parse.amni:618"); }))).a_ = ((int32_t)(g687));
{ int64_t q__417 = f51_pgenerics(); 
((*({ hrv *_t593 = &(g675); int64_t _i593 = n_415; (S4*)_t593->b + hr_ix(_i593, _t593->n, "hc/parse.amni:619"); }))).d_ = ((int32_t)(q__417));
 }
(void)(f39_ex(((int64_t)9LL), hr_str("struct declaration", 18)));
(void)(f95_pfields(n_415, hr_str("struct body", 11)));
(void)(f39_ex(((int64_t)10LL), hr_str("struct declaration", 18)));
return n_415;
}
static void f95_pfields(int64_t n_418, hsl ctx_419) {
int64_t m_420 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t f_421 = f40_mk(((int64_t)55LL), g680); 
if (f41_is(((int64_t)70LL))) { ((*({ hrv *_t595 = &(g675); int64_t _i595 = f_421; (S4*)_t595->b + hr_ix(_i595, _t595->n, "hc/parse.amni:601"); }))).fl_ = ((uint16_t)4LL);
if (((f31_tk()) == (((int64_t)2LL)))) { ((*({ hrv *_t596 = &(g675); int64_t _i596 = f_421; (S4*)_t596->b + hr_ix(_i596, _t596->n, "hc/parse.amni:601"); }))).c_ = ((int32_t)(((*({ hrv *_t597 = &(g885); int64_t _i597 = g680; (S3*)_t597->b + hr_ix(_i597, _t597->n, "hc/parse.amni:601"); }))).v_));
(void)(f33_nx());
 }
 } else { bool cq_422 = f41_is(((int64_t)69LL)); 
if ((cq_422 || f41_is(((int64_t)66LL)))) { ((*({ hrv *_t598 = &(g675); int64_t _i598 = f_421; (S4*)_t598->b + hr_ix(_i598, _t598->n, "hc/parse.amni:604"); }))).fl_ = ({ uint16_t _r599; if (cq_422) { _r599 = ((uint16_t)3LL);  } else { _r599 = ((uint16_t)1LL);  } _r599; });
 }
{ int64_t q__423 = f34_ident(ctx_419); 
((*({ hrv *_t600 = &(g675); int64_t _i600 = f_421; (S4*)_t600->b + hr_ix(_i600, _t600->n, "hc/parse.amni:605"); }))).s_ = ((int32_t)(q__423));
 }
if ((!(f75_amni_type()))) { (void)(f39_ex(((int64_t)13LL), ctx_419));
 }
{ int64_t q__424 = f53_ptype(); 
((*({ hrv *_t601 = &(g675); int64_t _i601 = f_421; (S4*)_t601->b + hr_ix(_i601, _t601->n, "hc/parse.amni:607"); }))).a_ = ((int32_t)(q__424));
 }
if (f41_is(((int64_t)36LL))) { { int64_t q__425 = f61_pexpr(); 
((*({ hrv *_t602 = &(g675); int64_t _i602 = f_421; (S4*)_t602->b + hr_ix(_i602, _t602->n, "hc/parse.amni:608"); }))).b_ = ((int32_t)(q__425));
 }
 }
 }
(void)(({ hrv *_v603 = &(g677); int32_t _x603 = ((int32_t)(f_421)); int32_t *_p603 = (int32_t*)hr_grow(_v603, 1, sizeof _x603); *_p603 = _x603; _p603; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk594; }
 }
 } _bk594:; 
(void)(f59_setl(n_418, m_420));
}
static int64_t f96_penum(void) {
int64_t st_426 = g680; 
(void)(f33_nx());
int64_t n_427 = f40_mk(((int64_t)52LL), st_426); 
{ int64_t q__428 = f50_declname(hr_str("enum declaration", 16)); 
((*({ hrv *_t604 = &(g675); int64_t _i604 = n_427; (S4*)_t604->b + hr_ix(_i604, _t604->n, "hc/parse.amni:628"); }))).s_ = ((int32_t)(q__428));
 }
((*({ hrv *_t605 = &(g675); int64_t _i605 = n_427; (S4*)_t605->b + hr_ix(_i605, _t605->n, "hc/parse.amni:628"); }))).a_ = ((int32_t)(g687));
{ int64_t q__429 = f51_pgenerics(); 
((*({ hrv *_t606 = &(g675); int64_t _i606 = n_427; (S4*)_t606->b + hr_ix(_i606, _t606->n, "hc/parse.amni:629"); }))).d_ = ((int32_t)(q__429));
 }
(void)(f39_ex(((int64_t)9LL), hr_str("enum declaration", 16)));
int64_t m_430 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t v_431 = f40_mk(((int64_t)56LL), g680); 
{ int64_t q__432 = f34_ident(hr_str("enum variant", 12)); 
((*({ hrv *_t608 = &(g675); int64_t _i608 = v_431; (S4*)_t608->b + hr_ix(_i608, _t608->n, "hc/parse.amni:633"); }))).s_ = ((int32_t)(q__432));
 }
if (f41_is(((int64_t)9LL))) { ((*({ hrv *_t609 = &(g675); int64_t _i609 = v_431; (S4*)_t609->b + hr_ix(_i609, _t609->n, "hc/parse.amni:634"); }))).fl_ = ((uint16_t)1LL);
(void)(f95_pfields(v_431, hr_str("variant body", 12)));
(void)(f39_ex(((int64_t)10LL), hr_str("enum variant", 12)));
 }
(void)(({ hrv *_v610 = &(g677); int32_t _x610 = ((int32_t)(v_431)); int32_t *_p610 = (int32_t*)hr_grow(_v610, 1, sizeof _x610); *_p610 = _x610; _p610; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk607; }
 }
 } _bk607:; 
(void)(f59_setl(n_427, m_430));
(void)(f39_ex(((int64_t)10LL), hr_str("enum declaration", 16)));
return n_427;
}
static void f97_collect(int64_t file_440, int64_t t0_441, int64_t t1_442) {
{ int64_t _e612 = t1_442; for (int64_t i_443 = t0_441; i_443 < _e612; i_443++) { int64_t n_444 = ((int64_t)((*({ hrv *_t613 = &(g678); int64_t _i613 = i_443; (int32_t*)_t613->b + hr_ix(_i613, _t613->n, "hc/decl.amni:27"); })))); 
S4 x_445 = (*({ hrv *_t614 = &(g675); int64_t _i614 = n_444; (S4*)_t614->b + hr_ix(_i614, _t614->n, "hc/decl.amni:28"); })); 
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
if (((k_446) == (((int64_t)33LL)))) { (void)(f99_dadd(((int64_t)5LL), n_444, file_440, f98_qual(((int64_t)((x_445).c_)), ((int64_t)((*({ hrv *_t615 = &(g676); int64_t _i615 = (x_445).l_; (int32_t*)_t615->b + hr_ix(_i615, _t615->n, "hc/decl.amni:34"); })))))));
 }
 } } _bk611:; 
}
static int64_t f98_qual(int64_t ns_447, int64_t name_448) {
return ({ int64_t _r616; if (((ns_447) < (((int64_t)0LL)))) { _r616 = name_448;  } else { hrv s_449 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v618 = &(s_449); hsl _s618 = f10_nm(ns_447); hr_append(_v618, _s618.p, _s618.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v619 = &(s_449); hsl _s619 = hr_str("::", 2); hr_append(_v619, _s619.p, _s619.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v620 = &(s_449); hsl _s620 = f10_nm(name_448); hr_append(_v620, _s620.p, _s620.n, sizeof(uint8_t)); }));
_r616 = f8_intern(hr_sl(s_449));  } _r616; });
}
static void f99_dadd(int64_t k_450, int64_t node_451, int64_t file_452, int64_t name_453) {
while ((((g465).n) <= (name_453))) { (void)(({ hrv *_v622 = &(g465); int32_t _x622 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p622 = (int32_t*)hr_grow(_v622, 1, sizeof _x622); *_p622 = _x622; _p622; }));
 } _bk621:; 
int64_t i_454 = (g464).n; 
(void)(({ hrv *_v623 = &(g464); S5 _x623 = ((S5){ .k_ = ((uint8_t)(k_450)), .node_ = ((int32_t)(node_451)), .file_ = ((int32_t)(file_452)), .next_ = (*({ hrv *_t624 = &(g465); int64_t _i624 = name_453; (int32_t*)_t624->b + hr_ix(_i624, _t624->n, "hc/decl.amni:19"); })), .name_ = ((int32_t)(name_453)), }); S5 *_p623 = (S5*)hr_grow(_v623, 1, sizeof _x623); *_p623 = _x623; _p623; }));
(*({ hrv *_t625 = &(g465); int64_t _i625 = name_453; (int32_t*)_t625->b + hr_ix(_i625, _t625->n, "hc/decl.amni:20"); })) = ((int32_t)(i_454));
}
static L49 f100_lib_path(hsl name_459) {
L49 p_460 = ({ L49 _t626; memset(&_t626, 0, sizeof _t626); _t626.n = 0; _t626; }); 
(void)(({ L49 *_v627 = &(p_460); hsl _s627 = hr_sl(g468); if (_v627->n + _s627.n > 1024) hr_die("append past a limited array's capacity", "hc/decl.amni:56"); memmove(_v627->e + _v627->n, _s627.p, (size_t)_s627.n * sizeof _v627->e[0]); _v627->n += _s627.n; }));
(void)(({ L49 *_v628 = &(p_460); uint8_t _x628 = ((uint8_t)47LL); if (_v628->n >= 1024) hr_die("push past a limited array's capacity", "hc/decl.amni:56"); _v628->e[_v628->n] = _x628; &_v628->e[_v628->n++]; }));
(void)(({ L49 *_v629 = &(p_460); hsl _s629 = name_459; if (_v629->n + _s629.n > 1024) hr_die("append past a limited array's capacity", "hc/decl.amni:56"); memmove(_v629->e + _v629->n, _s629.p, (size_t)_s629.n * sizeof _v629->e[0]); _v629->n += _s629.n; }));
(void)(({ L49 *_v630 = &(p_460); hsl _s630 = hr_str(".amni", 5); if (_v630->n + _s630.n > 1024) hr_die("append past a limited array's capacity", "hc/decl.amni:56"); memmove(_v630->e + _v630->n, _s630.p, (size_t)_s630.n * sizeof _v630->e[0]); _v630->n += _s630.n; }));
return p_460;
}
static int64_t f101_load_import(int64_t name_463, int64_t from_464, int64_t t_465) {
L49 p_466 = ({ L49 _t631; memset(&_t631, 0, sizeof _t631); _t631.n = 0; _t631; }); 
(void)(({ L49 *_v632 = &(p_466); hsl _s632 = hr_sl(g467); if (_v632->n + _s632.n > 1024) hr_die("append past a limited array's capacity", "hc/decl.amni:59"); memmove(_v632->e + _v632->n, _s632.p, (size_t)_s632.n * sizeof _v632->e[0]); _v632->n += _s632.n; }));
(void)(({ L49 *_v633 = &(p_466); uint8_t _x633 = ((uint8_t)47LL); if (_v633->n >= 1024) hr_die("push past a limited array's capacity", "hc/decl.amni:59"); _v633->e[_v633->n] = _x633; &_v633->e[_v633->n++]; }));
(void)(({ L49 *_v634 = &(p_466); hsl _s634 = f10_nm(name_463); if (_v634->n + _s634.n > 1024) hr_die("append past a limited array's capacity", "hc/decl.amni:59"); memmove(_v634->e + _v634->n, _s634.p, (size_t)_s634.n * sizeof _v634->e[0]); _v634->n += _s634.n; }));
(void)(({ L49 *_v635 = &(p_466); hsl _s635 = hr_str(".amni", 5); if (_v635->n + _s635.n > 1024) hr_die("append past a limited array's capacity", "hc/decl.amni:59"); memmove(_v635->e + _v635->n, _s635.p, (size_t)_s635.n * sizeof _v635->e[0]); _v635->n += _s635.n; }));
int64_t r_467 = f19_try_load(({ hsl _t636 = ({ L49 *_t637 = &(p_466); (hsl){ (uint8_t*)_t637->e, _t637->n }; }); int64_t _l636 = 0, _h636 = _t636.n; if (_l636 < 0 || _h636 < _l636 || _h636 > _t636.n) hr_slerr(_l636, _h636, _t636.n, "hc/decl.amni:60"); (hsl){ _t636.p + _l636 * (int64_t)sizeof(uint8_t), _h636 - _l636 }; })); 
if (((r_467) == (((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))) { L49 lp_468 = f100_lib_path(f10_nm(name_463)); 
r_467 = f19_try_load(({ hsl _t638 = ({ L49 *_t639 = &(lp_468); (hsl){ (uint8_t*)_t639->e, _t639->n }; }); int64_t _l638 = 0, _h638 = _t638.n; if (_l638 < 0 || _h638 < _l638 || _h638 > _t638.n) hr_slerr(_l638, _h638, _t638.n, "hc/decl.amni:61"); (hsl){ _t638.p + _l638 * (int64_t)sizeof(uint8_t), _h638 - _l638 }; }));
 }
if (((r_467) == (((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))) { hrv m_469 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o641 = &(m_469); hr_fs(_o641, hr_str("cannot find module ", 19)); hr_fs(_o641, f10_nm(name_463)); }));
(void)(f102_derr(t_465, hr_sl(m_469)));
return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
return r_467;
}
static void f102_derr(int64_t t_470, hsl m_471) {
if ((((g470).n) > (((int64_t)0LL)))) { return;
 }
S3 x_474 = (*({ hrv *_t642 = &(g885); int64_t _i642 = f103_max(t_470, ((int64_t)0LL)); (S3*)_t642->b + hr_ix(_i642, _t642->n, "hc/decl.amni:14"); })); 
(void)(({ hrv *_v643 = &(g470); hsl _s643 = f10_nm(((int64_t)(((*({ hrv *_t644 = &(g884); int64_t _i644 = (x_474).f_; (S2*)_t644->b + hr_ix(_i644, _t644->n, "hc/decl.amni:14"); }))).name_))); hr_append(_v643, _s643.p, _s643.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o645 = &(g470); hr_fs(_o645, hr_str(":", 1)); hr_fi(_o645, (x_474).line_); hr_fs(_o645, hr_str(": error: ", 9)); hr_fs(_o645, m_471); }));
}
static int64_t f103_max(int64_t a_472, int64_t b_473) {
if (((a_472) < (b_473))) { return b_473;
 }
return a_472;
}
static bool f104_check_program(void) {
g384 = f105_new_inst(((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)0LL), (g675).n, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
((*({ hrv *_t646 = &(g371); int64_t _i646 = g384; (S6*)_t646->b + hr_ix(_i646, _t646->n, "hc/calls.amni:439"); }))).st_ = ((uint8_t)2LL);
g382 = g384;
g383 = g384;
int64_t md_489 = f106_lookup(f8_intern(hr_str("main", 4)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)4LL)); 
if (((md_489) < (((int64_t)0LL)))) { (void)(f108_cerr(((int64_t)0LL), hr_str("no main function", 16)));
return false;
 }
{ hrv *_v648 = &(g464); for (int64_t _k648 = 0; _k648 < _v648->n; _k648++) { S5 d_493 = ((S5*)_v648->b)[_k648]; int64_t i_494 = _k648; if ((((((int64_t)((d_493).k_))) == (((int64_t)5LL))) && (((d_493).file_) == (((int32_t)0LL))))) { (void)(f109_global_type(i_494));
 }
 } } _bk647:; 
int64_t mi_1381 = f239_get_inst(((int64_t)(((*({ hrv *_t649 = &(g464); int64_t _i649 = md_489; (S5*)_t649->b + hr_ix(_i649, _t649->n, "hc/calls.amni:444"); }))).node_)), (g308).n, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
{ hrv *_v651 = &(g464); for (int64_t _k651 = 0; _k651 < _v651->n; _k651++) { S5 d_1382 = ((S5*)_v651->b)[_k651]; int64_t i_1383 = _k651; if (((((int64_t)((d_1382).k_))) == (((int64_t)5LL)))) { (void)(f109_global_type(i_1383));
 }
 } } _bk650:; 
return ((g386) == (((int64_t)0LL)));
}
static int64_t f105_new_inst(int64_t node_477, int64_t lo_478, int64_t hi_479, int64_t par_480) {
int64_t i_481 = (g371).n; 
(void)(({ hrv *_v652 = &(g371); S6 _x652 = ((S6){ .node_ = ((int32_t)(node_477)), .lo_ = ((int32_t)(lo_478)), .hi_ = ((int32_t)(hi_479)), .ab_ = ((int32_t)((g376).n)), .par_ = ((int32_t)(par_480)), .cfn_ = ((int32_t)(i_481)), .g0_ = ((int32_t)((g375).n)), .gn_ = ((int32_t)0LL), .ret_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .p0_ = ((int32_t)0LL), .pn_ = ((int32_t)0LL), .st_ = ((uint8_t)0LL), .blk_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .bown_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .name_ = ({ int32_t _r653; if (((node_477) >= (((int64_t)0LL)))) { _r653 = ((*({ hrv *_t654 = &(g675); int64_t _i654 = node_477; (S4*)_t654->b + hr_ix(_i654, _t654->n, "hc/check.amni:27"); }))).s_;  } else { _r653 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));  } _r653; }), }); S6 *_p652 = (S6*)hr_grow(_v652, 1, sizeof _x652); *_p652 = _x652; _p652; }));
int64_t n_482 = ((int64_t)((int64_t)hi_479 - (int64_t)lo_478)); 
(void)(({ hrv *_v655 = &(g376); int64_t _k655 = ((int64_t)((int64_t)(g376).n + (int64_t)n_482)); if (_k655 < 0) hr_die("resize to a negative length", "hc/check.amni:29"); int32_t _x655 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o655 = _v655->n; hr_resize(_v655, _k655, sizeof _x655); for (int64_t _j = _o655; _j < _k655; _j++) ((int32_t*)_v655->b)[_j] = _x655; }));
(void)(({ hrv *_v656 = &(g377); int64_t _k656 = ((int64_t)((int64_t)(g377).n + (int64_t)n_482)); if (_k656 < 0) hr_die("resize to a negative length", "hc/check.amni:29"); int32_t _x656 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o656 = _v656->n; hr_resize(_v656, _k656, sizeof _x656); for (int64_t _j = _o656; _j < _k656; _j++) ((int32_t*)_v656->b)[_j] = _x656; }));
(void)(({ hrv *_v657 = &(g378); int64_t _k657 = ((int64_t)((int64_t)(g378).n + (int64_t)n_482)); if (_k657 < 0) hr_die("resize to a negative length", "hc/check.amni:29"); uint8_t _x657 = ((uint8_t)0LL); int64_t _o657 = _v657->n; hr_resize(_v657, _k657, sizeof _x657); for (int64_t _j = _o657; _j < _k657; _j++) ((uint8_t*)_v657->b)[_j] = _x657; }));
(void)(({ hrv *_v658 = &(g379); int64_t _k658 = ((int64_t)((int64_t)(g379).n + (int64_t)n_482)); if (_k658 < 0) hr_die("resize to a negative length", "hc/check.amni:29"); int32_t _x658 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o658 = _v658->n; hr_resize(_v658, _k658, sizeof _x658); for (int64_t _j = _o658; _j < _k658; _j++) ((int32_t*)_v658->b)[_j] = _x658; }));
(void)(({ hrv *_v659 = &(g380); int64_t _k659 = ((int64_t)((int64_t)(g380).n + (int64_t)n_482)); if (_k659 < 0) hr_die("resize to a negative length", "hc/check.amni:29"); int32_t _x659 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o659 = _v659->n; hr_resize(_v659, _k659, sizeof _x659); for (int64_t _j = _o659; _j < _k659; _j++) ((int32_t*)_v659->b)[_j] = _x659; }));
return i_481;
}
static int64_t f106_lookup(int64_t name_483, int64_t ns_484, int64_t k_485) {
if (((ns_484) >= (((int64_t)0LL)))) { int64_t d_487 = f107_dmap(f98_qual(ns_484, name_483)); 
while (((d_487) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t661 = &(g464); int64_t _i661 = d_487; (S5*)_t661->b + hr_ix(_i661, _t661->n, "hc/decl.amni:74"); }))).k_))) == (k_485))) { return d_487;
 }
d_487 = ((int64_t)(((*({ hrv *_t662 = &(g464); int64_t _i662 = d_487; (S5*)_t662->b + hr_ix(_i662, _t662->n, "hc/decl.amni:74"); }))).next_));
 } _bk660:; 
 }
int64_t d_488 = f107_dmap(name_483); 
while (((d_488) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t664 = &(g464); int64_t _i664 = d_488; (S5*)_t664->b + hr_ix(_i664, _t664->n, "hc/decl.amni:76"); }))).k_))) == (k_485))) { return d_488;
 }
d_488 = ((int64_t)(((*({ hrv *_t665 = &(g464); int64_t _i665 = d_488; (S5*)_t665->b + hr_ix(_i665, _t665->n, "hc/decl.amni:76"); }))).next_));
 } _bk663:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f107_dmap(int64_t name_486) {
return ({ int64_t _r666; if ((((name_486) < (((int64_t)0LL))) || ((name_486) >= ((g465).n)))) { _r666 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r666 = ((int64_t)((*({ hrv *_t667 = &(g465); int64_t _i667 = name_486; (int32_t*)_t667->b + hr_ix(_i667, _t667->n, "hc/decl.amni:15"); }))));  } _r666; });
}
static void f108_cerr(int64_t n_490, hsl m_491) {
g386++;
if ((((g385).n) > (((int64_t)0LL)))) { return;
 }
S3 x_492 = (*({ hrv *_t668 = &(g885); int64_t _i668 = ((*({ hrv *_t669 = &(g675); int64_t _i669 = f103_max(n_490, ((int64_t)0LL)); (S4*)_t669->b + hr_ix(_i669, _t669->n, "hc/check.amni:24"); }))).t_; (S3*)_t668->b + hr_ix(_i668, _t668->n, "hc/check.amni:24"); })); 
(void)(({ hrv *_v670 = &(g385); hsl _s670 = f10_nm(((int64_t)(((*({ hrv *_t671 = &(g884); int64_t _i671 = (x_492).f_; (S2*)_t671->b + hr_ix(_i671, _t671->n, "hc/check.amni:24"); }))).name_))); hr_append(_v670, _s670.p, _s670.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o672 = &(g385); hr_fs(_o672, hr_str(":", 1)); hr_fi(_o672, (x_492).line_); hr_fs(_o672, hr_str(": error: ", 9)); hr_fs(_o672, m_491); }));
}
static int64_t f109_global_type(int64_t d_495) {
while ((((g426).n) < ((g464).n))) { (void)(({ hrv *_v674 = &(g426); int32_t _x674 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p674 = (int32_t*)hr_grow(_v674, 1, sizeof _x674); *_p674 = _x674; _p674; }));
(void)(({ hrv *_v675 = &(g427); uint8_t _x675 = ((uint8_t)0LL); uint8_t *_p675 = (uint8_t*)hr_grow(_v675, 1, sizeof _x675); *_p675 = _x675; _p675; }));
 } _bk673:; 
if ((((*({ hrv *_t676 = &(g426); int64_t _i676 = d_495; (int32_t*)_t676->b + hr_ix(_i676, _t676->n, "hc/check.amni:322"); }))) >= (((int32_t)0LL)))) { return ((int64_t)((*({ hrv *_t677 = &(g426); int64_t _i677 = d_495; (int32_t*)_t677->b + hr_ix(_i677, _t677->n, "hc/check.amni:322"); }))));
 }
int64_t g_496 = ((int64_t)(((*({ hrv *_t678 = &(g464); int64_t _i678 = d_495; (S5*)_t678->b + hr_ix(_i678, _t678->n, "hc/check.amni:323"); }))).node_)); 
S4 x_497 = (*({ hrv *_t679 = &(g675); int64_t _i679 = g_496; (S4*)_t679->b + hr_ix(_i679, _t679->n, "hc/check.amni:324"); })); 
int64_t saved_498 = g382; 
int64_t sc_499 = g383; 
g382 = g384;
g383 = g384;
int64_t t_500 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((x_497).a_) >= (((int32_t)0LL)))) { t_500 = f113_rtype(((int64_t)((x_497).a_)), f110_ns_of(g_496));
(*({ hrv *_t680 = &(g426); int64_t _i680 = d_495; (int32_t*)_t680->b + hr_ix(_i680, _t680->n, "hc/check.amni:328"); })) = ((int32_t)(t_500));
if ((((x_497).b_) >= (((int32_t)0LL)))) { int64_t iv_637 = f90_kid(((int64_t)((x_497).b_)), ((int64_t)0LL)); 
(void)(f136_ck(iv_637, t_500));
(void)(f139_conv(iv_637, t_500));
 }
 } else { if ((((*({ hrv *_t681 = &(g427); int64_t _i681 = d_495; (uint8_t*)_t681->b + hr_ix(_i681, _t681->n, "hc/check.amni:330"); }))) == (((uint8_t)1LL)))) { (void)(f108_cerr(g_496, hr_str("global initializer depends on itself", 36)));
g382 = saved_498;
g383 = sc_499;
return g548;
 }
(*({ hrv *_t682 = &(g427); int64_t _i682 = d_495; (uint8_t*)_t682->b + hr_ix(_i682, _t682->n, "hc/check.amni:331"); })) = ((uint8_t)1LL);
int64_t iv_1378 = f90_kid(((int64_t)((x_497).b_)), ((int64_t)0LL)); 
(void)(f136_ck(iv_1378, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
t_500 = f179_default_t(iv_1378);
if (((((*({ hrv *_t683 = &(g524); int64_t _i683 = t_500; (S1*)_t683->b + hr_ix(_i683, _t683->n, "hc/check.amni:335"); }))).k_) == (((uint8_t)18LL)))) { t_500 = g549;
 }
(*({ hrv *_t684 = &(g426); int64_t _i684 = d_495; (int32_t*)_t684->b + hr_ix(_i684, _t684->n, "hc/check.amni:336"); })) = ((int32_t)(t_500));
 }
if ((!(f243_ORD_HAS(d_495)))) { (void)(({ hrv *_v685 = &(g390); int32_t _x685 = ((int32_t)(d_495)); int32_t *_p685 = (int32_t*)hr_grow(_v685, 1, sizeof _x685); *_p685 = _x685; _p685; }));
 }
g382 = saved_498;
g383 = sc_499;
return t_500;
}
static int64_t f110_ns_of(int64_t n_501) {
return f112_file_ns(f111_node_file(n_501));
}
static int64_t f111_node_file(int64_t n_502) {
return ((int64_t)(((*({ hrv *_t686 = &(g885); int64_t _i686 = ((*({ hrv *_t687 = &(g675); int64_t _i687 = n_502; (S4*)_t687->b + hr_ix(_i687, _t687->n, "hc/decl.amni:23"); }))).t_; (S3*)_t686->b + hr_ix(_i686, _t686->n, "hc/decl.amni:23"); }))).f_));
}
static int64_t f112_file_ns(int64_t f_503) {
return ({ int64_t _r688; if (((f_503) < ((g471).n))) { _r688 = ((int64_t)((*({ hrv *_t689 = &(g471); int64_t _i689 = f_503; (int32_t*)_t689->b + hr_ix(_i689, _t689->n, "hc/decl.amni:24"); }))));  } else { _r688 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r688; });
}
static int64_t f113_rtype(int64_t n_504, int64_t ns_505) {
if (((n_504) < (((int64_t)0LL)))) { return g531;
 }
S4 x_506 = (*({ hrv *_t690 = &(g675); int64_t _i690 = n_504; (S4*)_t690->b + hr_ix(_i690, _t690->n, "hc/decl.amni:93"); })); 
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
if ((((x_506).c_) >= (((int32_t)0LL)))) { return f116_t_rel(e_512, fl_513, f115_int_storage_of_tok(((int64_t)((x_506).c_))), ((int64_t)((x_506).s_)));
 }
if ((((((*({ hrv *_t691 = &(g524); int64_t _i691 = e_512; (S1*)_t691->b + hr_ix(_i691, _t691->n, "hc/decl.amni:103"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t692 = &(g524); int64_t _i692 = e_512; (S1*)_t692->b + hr_ix(_i692, _t692->n, "hc/decl.amni:103"); }))).c_) < (((int32_t)0LL))))) { if (((((int64_t)((int64_t)fl_513 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { return f117_t_ref(((int64_t)(((*({ hrv *_t693 = &(g524); int64_t _i693 = e_512; (S1*)_t693->b + hr_ix(_i693, _t693->n, "hc/decl.amni:103"); }))).a_)), ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t694 = &(g524); int64_t _i694 = e_512; (S1*)_t694->b + hr_ix(_i694, _t694->n, "hc/decl.amni:103"); }))).fl_)) | (int64_t)((int64_t)2LL))));
 }
return e_512;
 }
return f117_t_ref(e_512, fl_513);
 }
if (((k_507) == (((int64_t)42LL)))) { int64_t e_520 = f113_rtype(((int64_t)((x_506).a_)), ns_505); 
int64_t a_521 = ((int64_t)((x_506).op_)); 
if (((a_521) == (((int64_t)1LL)))) { M55 _t695 = f118_ceval(((int64_t)((x_506).b_)), ns_505); int64_t v_548 = _t695.r0; bool ok_549 = _t695.r1; 
if ((!(ok_549))) { (void)(f102_derr(((int64_t)((x_506).t_)), hr_str("array size must be a constant", 29)));
 }
return f121_t_arr(e_520, ((int64_t)1LL), v_548, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
 }
if (((a_521) == (((int64_t)3LL)))) { if ((((x_506).b_) < (((int32_t)0LL)))) { return f121_t_arr(e_520, ((int64_t)3LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)6LL));
 }
M55 _t696 = f118_ceval(((int64_t)((x_506).b_)), ns_505); int64_t v_554 = _t696.r0; bool ok_555 = _t696.r1; 
if ((!(ok_555))) { (void)(f102_derr(((int64_t)((x_506).t_)), hr_str("capacity must be a constant", 27)));
 }
return f121_t_arr(e_520, ((int64_t)3LL), v_554, f122_lim_lenstore(v_554));
 }
if (((a_521) == (((int64_t)2LL)))) { int64_t ls_557 = ({ int64_t _r697; if ((((x_506).c_) < (((int32_t)0LL)))) { _r697 = ((int64_t)6LL);  } else { _r697 = ({ int64_t _r698; if (((((int64_t)((x_506).c_))) == (((int64_t)90LL)))) { _r698 = ((int64_t)8LL);  } else { _r698 = f115_int_storage_of_tok(((int64_t)((x_506).c_)));  } _r698; });  } _r697; }); 
return f121_t_arr(e_520, ((int64_t)2LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ls_557);
 }
return f121_t_arr(e_520, a_521, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
 }
if (((k_507) == (((int64_t)46LL)))) { int64_t b_558 = f113_rtype(((int64_t)((x_506).a_)), ns_505); 
if (((((*({ hrv *_t699 = &(g524); int64_t _i699 = b_558; (S1*)_t699->b + hr_ix(_i699, _t699->n, "hc/decl.amni:116"); }))).k_) != (((uint8_t)6LL)))) { (void)(f102_derr(((int64_t)((x_506).t_)), hr_str("variant type of a non-enum", 26)));
return g548;
 }
int64_t ei_559 = ((int64_t)(((*({ hrv *_t700 = &(g524); int64_t _i700 = b_558; (S1*)_t700->b + hr_ix(_i700, _t700->n, "hc/decl.amni:117"); }))).a_)); 
{ int32_t _e702 = ((*({ hrv *_t703 = &(g529); int64_t _i703 = ei_559; (S8*)_t703->b + hr_ix(_i703, _t703->n, "hc/decl.amni:118"); }))).vnum_; for (int32_t i_560 = 0; i_560 < _e702; i_560++) { if (((((*({ hrv *_t704 = &(g530); int64_t _i704 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t705 = &(g529); int64_t _i705 = ei_559; (S8*)_t705->b + hr_ix(_i705, _t705->n, "hc/decl.amni:118"); }))).v0_)) + (int64_t)((int64_t)(i_560)))); (S9*)_t704->b + hr_ix(_i704, _t704->n, "hc/decl.amni:118"); }))).name_) == ((x_506).s_))) { return f123_t_variant(ei_559, ((int64_t)(i_560)));
 }
 } } _bk701:; 
hrv m_563 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t708 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o707 = &(m_563); hr_fs(_o707, hr_str("no variant ", 11)); hr_fs(_o707, f10_nm(((int64_t)((x_506).s_)))); hr_fs(_o707, hr_str(" in ", 4)); hr_fs(_o707, hr_sl(*hr_tmp(&_t708, f124_ty_name(b_558)))); }));
}
(void)(f102_derr(((int64_t)((x_506).t_)), hr_sl(m_563)));
return g548;
 }
if (((k_507) == (((int64_t)45LL)))) { return g551;
 }
if (((k_507) == (((int64_t)41LL)))) { int64_t name_579 = ((int64_t)((x_506).s_)); 
if ((((x_506).n_) == (((int32_t)0LL)))) { int64_t g_582 = f128_gb_find(name_579); 
if (((g_582) >= (((int64_t)0LL)))) { return g_582;
 }
 }
L65 args_583 = ({ L65 _t709; memset(&_t709, 0, sizeof _t709); _t709.n = 0; _t709; }); 
{ int32_t _e711 = (x_506).n_; for (int32_t i_584 = 0; i_584 < _e711; i_584++) { int64_t at0_585 = f113_rtype(f90_kid(n_504, ((int64_t)(i_584))), ns_505); 
(void)(({ L65 *_v712 = &(args_583); int32_t _x712 = ((int32_t)(at0_585)); if (_v712->n >= 16) hr_die("push past a limited array's capacity", "hc/decl.amni:127"); _v712->e[_v712->n] = _x712; &_v712->e[_v712->n++]; }));
 } } _bk710:; 
int64_t d_586 = f119_lookup_q(name_579, ns_505, ((int64_t)1LL)); 
if (((d_586) >= (((int64_t)0LL)))) { return f133_t_struct(f129_inst_struct(((int64_t)(((*({ hrv *_t713 = &(g464); int64_t _i713 = d_586; (S5*)_t713->b + hr_ix(_i713, _t713->n, "hc/decl.amni:129"); }))).node_)), ({ hsl _t714 = ({ L65 *_t715 = &(args_583); (hsl){ (uint8_t*)_t715->e, _t715->n }; }); int64_t _l714 = 0, _h714 = _t714.n; if (_l714 < 0 || _h714 < _l714 || _h714 > _t714.n) hr_slerr(_l714, _h714, _t714.n, "hc/decl.amni:129"); (hsl){ _t714.p + _l714 * (int64_t)sizeof(int32_t), _h714 - _l714 }; })));
 }
d_586 = f119_lookup_q(name_579, ns_505, ((int64_t)2LL));
if (((d_586) >= (((int64_t)0LL)))) { return f135_t_enum(f134_inst_enum(((int64_t)(((*({ hrv *_t716 = &(g464); int64_t _i716 = d_586; (S5*)_t716->b + hr_ix(_i716, _t716->n, "hc/decl.amni:131"); }))).node_)), ({ hsl _t717 = ({ L65 *_t718 = &(args_583); (hsl){ (uint8_t*)_t718->e, _t718->n }; }); int64_t _l717 = 0, _h717 = _t717.n; if (_l717 < 0 || _h717 < _l717 || _h717 > _t717.n) hr_slerr(_l717, _h717, _t717.n, "hc/decl.amni:131"); (hsl){ _t717.p + _l717 * (int64_t)sizeof(int32_t), _h717 - _l717 }; })), ((((uint16_t)((uint64_t)(x_506).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))));
 }
d_586 = f119_lookup_q(name_579, ns_505, ((int64_t)3LL));
if (((d_586) >= (((int64_t)0LL)))) { int64_t an_635 = ((int64_t)(((*({ hrv *_t719 = &(g464); int64_t _i719 = d_586; (S5*)_t719->b + hr_ix(_i719, _t719->n, "hc/decl.amni:133"); }))).node_)); 
return f113_rtype(((int64_t)(((*({ hrv *_t720 = &(g675); int64_t _i720 = an_635; (S4*)_t720->b + hr_ix(_i720, _t720->n, "hc/decl.amni:133"); }))).b_)), f110_ns_of(an_635));
 }
hrv m_636 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o722 = &(m_636); hr_fs(_o722, hr_str("unknown type ", 13)); hr_fs(_o722, f10_nm(name_579)); }));
(void)(f102_derr(((int64_t)((x_506).t_)), hr_sl(m_636)));
return g548;
 }
(void)(f102_derr(((int64_t)((x_506).t_)), hr_str("bad type", 8)));
return g548;
}
static int64_t f114_prim_type(int64_t k_508) {
if (((k_508) == (((int64_t)89LL)))) { return g532;
 }
if (((k_508) == (((int64_t)90LL)))) { return g547;
 }
if (((k_508) == (((int64_t)99LL)))) { return g541;
 }
if ((((k_508) == (((int64_t)100LL))) || ((k_508) == (((int64_t)104LL))))) { return g542;
 }
int64_t s_510 = f115_int_storage_of_tok(k_508); 
return ({ int64_t _r723; if (((s_510) >= (((int64_t)0LL)))) { _r723 = f17_t_int(s_510);  } else { _r723 = g548;  } _r723; });
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
static int64_t f116_t_rel(int64_t e_514, int64_t fl_515, int64_t w_516, int64_t pool_517) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)10LL))), .fl_ = ((uint16_t)(fl_515)), .a_ = ((int32_t)(e_514)), .c_ = ((int32_t)(w_516)), .b_ = pool_517, }));
}
static int64_t f117_t_ref(int64_t e_518, int64_t fl_519) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)10LL))), .fl_ = ((uint16_t)(((int64_t)((int64_t)fl_519 & (int64_t)((int64_t)2LL))))), .a_ = ((int32_t)(e_518)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static M55 f118_ceval(int64_t n_522, int64_t ns_523) {
if (((n_522) < (((int64_t)0LL)))) { return (M55){ ((int64_t)0LL), false };
 }
S4 x_524 = (*({ hrv *_t724 = &(g675); int64_t _i724 = n_522; (S4*)_t724->b + hr_ix(_i724, _t724->n, "hc/decl.amni:193"); })); 
int64_t k_525 = ((int64_t)((x_524).k_)); 
if (((k_525) == (((int64_t)1LL)))) { return (M55){ ((*({ hrv *_t725 = &(g885); int64_t _i725 = (x_524).t_; (S3*)_t725->b + hr_ix(_i725, _t725->n, "hc/decl.amni:195"); }))).v_, true };
 }
if (((k_525) == (((int64_t)10LL)))) { M55 _t726 = f118_ceval(((int64_t)((x_524).a_)), ns_523); int64_t v_526 = _t726.r0; bool ok_527 = _t726.r1; 
if (((((int64_t)((x_524).op_))) == (((int64_t)22LL)))) { return (M55){ ((int64_t)(0 - (uint64_t)(v_526))), ok_527 };
 }
if (((((int64_t)((x_524).op_))) == (((int64_t)48LL)))) { return (M55){ ((int64_t)~(v_526)), ok_527 };
 }
return (M55){ ((int64_t)0LL), false };
 }
if (((k_525) == (((int64_t)9LL)))) { M55 _t727 = f118_ceval(((int64_t)((x_524).a_)), ns_523); int64_t a_528 = _t727.r0; bool oa_529 = _t727.r1; 
M55 _t728 = f118_ceval(((int64_t)((x_524).b_)), ns_523); int64_t b_530 = _t728.r0; bool ob_531 = _t728.r1; 
if (((!(oa_529)) || (!(ob_531)))) { return (M55){ ((int64_t)0LL), false };
 }
int64_t o_532 = ((int64_t)((x_524).op_)); 
if (((o_532) == (((int64_t)21LL)))) { return (M55){ ((int64_t)((int64_t)a_528 + (int64_t)b_530)), true };
 }
if (((o_532) == (((int64_t)22LL)))) { return (M55){ ((int64_t)((int64_t)a_528 - (int64_t)b_530)), true };
 }
if (((o_532) == (((int64_t)23LL)))) { return (M55){ ((int64_t)((int64_t)a_528 * (int64_t)b_530)), true };
 }
if (((o_532) == (((int64_t)24LL)))) { if (((b_530) == (((int64_t)0LL)))) { return (M55){ ((int64_t)0LL), false };
 }
return (M55){ HR_SDIV(int64_t, a_528, b_530, "hc/decl.amni:208"), true };
 }
if (((o_532) == (((int64_t)25LL)))) { if (((b_530) == (((int64_t)0LL)))) { return (M55){ ((int64_t)0LL), false };
 }
return (M55){ HR_SMOD(int64_t, ((int64_t)((int64_t)HR_SMOD(int64_t, a_528, b_530, "hc/decl.amni:209") + (int64_t)b_530)), b_530, "hc/decl.amni:209"), true };
 }
if (((o_532) == (((int64_t)43LL)))) { return (M55){ ((int64_t)((a_528) << ((b_530) & 63))), true };
 }
if (((o_532) == (((int64_t)44LL)))) { return (M55){ ((int64_t)((a_528) >> ((b_530) & 63))), true };
 }
if (((o_532) == (((int64_t)49LL)))) { return (M55){ ((int64_t)((int64_t)a_528 & (int64_t)b_530)), true };
 }
if (((o_532) == (((int64_t)50LL)))) { return (M55){ ((int64_t)((int64_t)a_528 | (int64_t)b_530)), true };
 }
if (((o_532) == (((int64_t)51LL)))) { return (M55){ ((int64_t)((int64_t)a_528 ^ (int64_t)b_530)), true };
 }
return (M55){ ((int64_t)0LL), false };
 }
if (((k_525) == (((int64_t)15LL)))) { return f118_ceval(((int64_t)((x_524).a_)), ns_523);
 }
if (((k_525) == (((int64_t)8LL)))) { int64_t d_542 = f119_lookup_q(((int64_t)((x_524).s_)), ns_523, ((int64_t)5LL)); 
if (((d_542) < (((int64_t)0LL)))) { return (M55){ ((int64_t)0LL), false };
 }
int64_t g_543 = ((int64_t)(((*({ hrv *_t729 = &(g464); int64_t _i729 = d_542; (S5*)_t729->b + hr_ix(_i729, _t729->n, "hc/decl.amni:218"); }))).node_)); 
if (((((((uint16_t)((uint64_t)((*({ hrv *_t730 = &(g675); int64_t _i730 = g_543; (S4*)_t730->b + hr_ix(_i730, _t730->n, "hc/decl.amni:219"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || ((((*({ hrv *_t731 = &(g675); int64_t _i731 = g_543; (S4*)_t731->b + hr_ix(_i731, _t731->n, "hc/decl.amni:219"); }))).b_) < (((int32_t)0LL)))) || (((((*({ hrv *_t732 = &(g675); int64_t _i732 = g_543; (S4*)_t732->b + hr_ix(_i732, _t732->n, "hc/decl.amni:219"); }))).a_) >= (((int32_t)0LL))) && false))) { return (M55){ ((int64_t)0LL), false };
 }
return f118_ceval(f90_kid(((int64_t)(((*({ hrv *_t733 = &(g675); int64_t _i733 = g_543; (S4*)_t733->b + hr_ix(_i733, _t733->n, "hc/decl.amni:220"); }))).b_)), ((int64_t)0LL)), f110_ns_of(g_543));
 }
if (((((k_525) == (((int64_t)14LL))) && hr_streq(f10_nm(((int64_t)((x_524).s_))), hr_str("len", 3))) && ((((*({ hrv *_t734 = &(g675); int64_t _i734 = (x_524).a_; (S4*)_t734->b + hr_ix(_i734, _t734->n, "hc/decl.amni:222"); }))).k_) == (((uint8_t)8LL))))) { int64_t d_544 = f119_lookup_q(((int64_t)(((*({ hrv *_t735 = &(g675); int64_t _i735 = (x_524).a_; (S4*)_t735->b + hr_ix(_i735, _t735->n, "hc/decl.amni:223"); }))).s_)), ns_523, ((int64_t)5LL)); 
if (((d_544) < (((int64_t)0LL)))) { return (M55){ ((int64_t)0LL), false };
 }
int64_t g_545 = ((int64_t)(((*({ hrv *_t736 = &(g464); int64_t _i736 = d_544; (S5*)_t736->b + hr_ix(_i736, _t736->n, "hc/decl.amni:225"); }))).node_)); 
if (((((*({ hrv *_t737 = &(g675); int64_t _i737 = g_545; (S4*)_t737->b + hr_ix(_i737, _t737->n, "hc/decl.amni:226"); }))).a_) >= (((int32_t)0LL)))) { int64_t t_546 = f113_rtype(((int64_t)(((*({ hrv *_t738 = &(g675); int64_t _i738 = g_545; (S4*)_t738->b + hr_ix(_i738, _t738->n, "hc/decl.amni:226"); }))).a_)), f110_ns_of(g_545)); 
if ((((((*({ hrv *_t739 = &(g524); int64_t _i739 = t_546; (S1*)_t739->b + hr_ix(_i739, _t739->n, "hc/decl.amni:226"); }))).k_) == (((uint8_t)8LL))) && ((((*({ hrv *_t740 = &(g524); int64_t _i740 = t_546; (S1*)_t740->b + hr_ix(_i740, _t740->n, "hc/decl.amni:226"); }))).s_) == (((uint8_t)(((uint8_t)1LL))))))) { return (M55){ ((*({ hrv *_t741 = &(g524); int64_t _i741 = t_546; (S1*)_t741->b + hr_ix(_i741, _t741->n, "hc/decl.amni:226"); }))).b_, true };
 }
 }
if (((((*({ hrv *_t742 = &(g675); int64_t _i742 = g_545; (S4*)_t742->b + hr_ix(_i742, _t742->n, "hc/decl.amni:227"); }))).b_) >= (((int32_t)0LL)))) { int64_t iv_547 = f90_kid(((int64_t)(((*({ hrv *_t743 = &(g675); int64_t _i743 = g_545; (S4*)_t743->b + hr_ix(_i743, _t743->n, "hc/decl.amni:227"); }))).b_)), ((int64_t)0LL)); 
if (((((*({ hrv *_t744 = &(g675); int64_t _i744 = iv_547; (S4*)_t744->b + hr_ix(_i744, _t744->n, "hc/decl.amni:227"); }))).k_) == (((uint8_t)16LL)))) { if (((((*({ hrv *_t745 = &(g675); int64_t _i745 = iv_547; (S4*)_t745->b + hr_ix(_i745, _t745->n, "hc/decl.amni:227"); }))).b_) >= (((int32_t)0LL)))) { return f118_ceval(((int64_t)(((*({ hrv *_t746 = &(g675); int64_t _i746 = iv_547; (S4*)_t746->b + hr_ix(_i746, _t746->n, "hc/decl.amni:227"); }))).b_)), f110_ns_of(g_545));
 }
return (M55){ ((int64_t)(((*({ hrv *_t747 = &(g675); int64_t _i747 = iv_547; (S4*)_t747->b + hr_ix(_i747, _t747->n, "hc/decl.amni:227"); }))).n_)), true };
 }
if (((((*({ hrv *_t748 = &(g675); int64_t _i748 = iv_547; (S4*)_t748->b + hr_ix(_i748, _t748->n, "hc/decl.amni:227"); }))).k_) == (((uint8_t)3LL)))) { return (M55){ ((int64_t)(((*({ hrv *_t749 = &(g885); int64_t _i749 = ((*({ hrv *_t750 = &(g675); int64_t _i750 = iv_547; (S4*)_t750->b + hr_ix(_i750, _t750->n, "hc/decl.amni:227"); }))).t_; (S3*)_t749->b + hr_ix(_i749, _t749->n, "hc/decl.amni:227"); }))).w_)), true };
 }
 }
return (M55){ ((int64_t)0LL), false };
 }
return (M55){ ((int64_t)0LL), false };
}
static int64_t f119_lookup_q(int64_t q_533, int64_t ns_534, int64_t k_535) {
M56 _t751 = f120_split_q(q_533); int64_t a_539 = _t751.r0; int64_t b_540 = _t751.r1; 
if (((a_539) == (((int64_t)(0 - (uint64_t)(((int64_t)2LL))))))) { return f106_lookup(b_540, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), k_535);
 }
if (((a_539) >= (((int64_t)0LL)))) { int64_t d_541 = f107_dmap(q_533); 
while (((d_541) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t753 = &(g464); int64_t _i753 = d_541; (S5*)_t753->b + hr_ix(_i753, _t753->n, "hc/decl.amni:87"); }))).k_))) == (k_535))) { return d_541;
 }
d_541 = ((int64_t)(((*({ hrv *_t754 = &(g464); int64_t _i754 = d_541; (S5*)_t754->b + hr_ix(_i754, _t754->n, "hc/decl.amni:87"); }))).next_));
 } _bk752:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
return f106_lookup(b_540, ns_534, k_535);
}
static M56 f120_split_q(int64_t q_536) {
hsl s_537 = f10_nm(q_536); 
{ int64_t _e756 = (s_537).n; for (int64_t i_538 = 0; i_538 < _e756; i_538++) { if ((((((*({ hsl _t757 = s_537; int64_t _i757 = i_538; (uint8_t*)_t757.p + hr_ix(_i757, _t757.n, "hc/decl.amni:81"); }))) == (((uint8_t)58LL))) && ((((int64_t)((int64_t)i_538 + (int64_t)((int64_t)1LL)))) < ((s_537).n))) && (((*({ hsl _t758 = s_537; int64_t _i758 = ((int64_t)((int64_t)i_538 + (int64_t)((int64_t)1LL))); (uint8_t*)_t758.p + hr_ix(_i758, _t758.n, "hc/decl.amni:81"); }))) == (((uint8_t)58LL))))) { if (((i_538) == (((int64_t)0LL)))) { return (M56){ ((int64_t)(0 - (uint64_t)(((int64_t)2LL)))), f8_intern(({ hsl _t759 = s_537; int64_t _l759 = ((int64_t)2LL), _h759 = _t759.n; if (_l759 < 0 || _h759 < _l759 || _h759 > _t759.n) hr_slerr(_l759, _h759, _t759.n, "hc/decl.amni:81"); (hsl){ _t759.p + _l759 * (int64_t)sizeof(uint8_t), _h759 - _l759 }; })) };
 }
return (M56){ f8_intern(({ hsl _t760 = s_537; int64_t _l760 = 0, _h760 = i_538; if (_l760 < 0 || _h760 < _l760 || _h760 > _t760.n) hr_slerr(_l760, _h760, _t760.n, "hc/decl.amni:81"); (hsl){ _t760.p + _l760 * (int64_t)sizeof(uint8_t), _h760 - _l760 }; })), f8_intern(({ hsl _t761 = s_537; int64_t _l761 = ((int64_t)((int64_t)i_538 + (int64_t)((int64_t)2LL))), _h761 = _t761.n; if (_l761 < 0 || _h761 < _l761 || _h761 > _t761.n) hr_slerr(_l761, _h761, _t761.n, "hc/decl.amni:81"); (hsl){ _t761.p + _l761 * (int64_t)sizeof(uint8_t), _h761 - _l761 }; })) };
 }
 } } _bk755:; 
return (M56){ ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), q_536 };
}
static int64_t f121_t_arr(int64_t e_550, int64_t ak_551, int64_t size_552, int64_t ls_553) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)8LL))), .s_ = ((uint8_t)(ak_551)), .a_ = ((int32_t)(e_550)), .c_ = ((int32_t)(ls_553)), .b_ = size_552, }));
}
static int64_t f122_lim_lenstore(int64_t cap_556) {
return ({ int64_t _r762; if (((cap_556) < (((int64_t)256LL)))) { _r762 = ((int64_t)4LL);  } else { _r762 = ({ int64_t _r763; if (((cap_556) < (((int64_t)65536LL)))) { _r763 = ((int64_t)5LL);  } else { _r763 = ({ int64_t _r764; if (((cap_556) < (((int64_t)4294967296LL)))) { _r764 = ((int64_t)6LL);  } else { _r764 = ((int64_t)7LL);  } _r764; });  } _r763; });  } _r762; });
}
static int64_t f123_t_variant(int64_t ei_561, int64_t vi_562) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)7LL))), .a_ = ((int32_t)(ei_561)), .c_ = ((int32_t)(vi_562)), }));
}
static hrv f124_ty_name(int64_t t_564) {
hrv s_565 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(f125_ty_name_into(t_564, (&(s_565))));
{ hrv _rv = s_565; s_565.b = 0; s_565.n = 0; return _rv; }
}
static void f125_ty_name_into(int64_t t_566, hrv* out_567) {
S1 x_568 = (*({ hrv *_t766 = &(g524); int64_t _i766 = t_566; (S1*)_t766->b + hr_ix(_i766, _t766->n, "hc/types.amni:162"); })); 
int64_t k_569 = ((int64_t)((x_568).k_)); 
if (((k_569) == (((int64_t)0LL)))) { (void)(({ hrv *_v767 = out_567; hsl _s767 = hr_str("<error>", 7); hr_append(_v767, _s767.p, _s767.n, sizeof(uint8_t)); }));
return;
 }
if (((k_569) == (((int64_t)1LL)))) { (void)(({ hrv *_v768 = out_567; hsl _s768 = hr_str("void", 4); hr_append(_v768, _s768.p, _s768.n, sizeof(uint8_t)); }));
return;
 }
if (((k_569) == (((int64_t)2LL)))) { (void)(({ hrv *_v769 = out_567; hsl _s769 = hr_str("bool", 4); hr_append(_v769, _s769.p, _s769.n, sizeof(uint8_t)); }));
return;
 }
if (((k_569) == (((int64_t)3LL)))) { (void)(f126_ls_kind_name(((int64_t)((x_568).s_)), out_567));
return;
 }
if (((k_569) == (((int64_t)4LL)))) { (void)(({ hrv *_v770 = out_567; hsl _s770 = ({ hsl _r771; if ((((x_568).s_) == (((uint8_t)4LL)))) { _r771 = hr_str("f32", 3);  } else { _r771 = hr_str("f64", 3);  } _r771; }); hr_append(_v770, _s770.p, _s770.n, sizeof(uint8_t)); }));
return;
 }
if (((k_569) == (((int64_t)17LL)))) { (void)(({ hrv *_v772 = out_567; hsl _s772 = hr_str("varint", 6); hr_append(_v772, _s772.p, _s772.n, sizeof(uint8_t)); }));
return;
 }
if (((k_569) == (((int64_t)11LL)))) { (void)(({ hrv *_v773 = out_567; hsl _s773 = hr_str("null", 4); hr_append(_v773, _s773.p, _s773.n, sizeof(uint8_t)); }));
return;
 }
if (((k_569) == (((int64_t)12LL)))) { (void)(({ hrv *_v774 = out_567; hsl _s774 = hr_str("integer constant", 16); hr_append(_v774, _s774.p, _s774.n, sizeof(uint8_t)); }));
return;
 }
if (((k_569) == (((int64_t)13LL)))) { (void)(({ hrv *_v775 = out_567; hsl _s775 = hr_str("float constant", 14); hr_append(_v775, _s775.p, _s775.n, sizeof(uint8_t)); }));
return;
 }
if (((k_569) == (((int64_t)18LL)))) { (void)(({ hrv *_v776 = out_567; hsl _s776 = hr_str("const u8[:]", 11); hr_append(_v776, _s776.p, _s776.n, sizeof(uint8_t)); }));
return;
 }
if (((k_569) == (((int64_t)16LL)))) { (void)(({ hrv *_v777 = out_567; hsl _s777 = f10_nm(((int64_t)((x_568).a_))); hr_append(_v777, _s777.p, _s777.n, sizeof(uint8_t)); }));
return;
 }
if (((k_569) == (((int64_t)5LL)))) { (void)(({ hrv *_v778 = out_567; hsl _s778 = f10_nm(((int64_t)(((*({ hrv *_t779 = &(g527); int64_t _i779 = (x_568).a_; (S10*)_t779->b + hr_ix(_i779, _t779->n, "hc/types.amni:175"); }))).name_))); hr_append(_v778, _s778.p, _s778.n, sizeof(uint8_t)); }));
(void)(f127_targs_into(((int64_t)(((*({ hrv *_t780 = &(g527); int64_t _i780 = (x_568).a_; (S10*)_t780->b + hr_ix(_i780, _t780->n, "hc/types.amni:175"); }))).ta_)), ((int64_t)(((*({ hrv *_t781 = &(g527); int64_t _i781 = (x_568).a_; (S10*)_t781->b + hr_ix(_i781, _t781->n, "hc/types.amni:175"); }))).tn_)), out_567));
return;
 }
if (((k_569) == (((int64_t)6LL)))) { (void)(({ hrv *_v782 = out_567; hsl _s782 = f10_nm(((int64_t)(((*({ hrv *_t783 = &(g529); int64_t _i783 = (x_568).a_; (S8*)_t783->b + hr_ix(_i783, _t783->n, "hc/types.amni:176"); }))).name_))); hr_append(_v782, _s782.p, _s782.n, sizeof(uint8_t)); }));
(void)(f127_targs_into(((int64_t)(((*({ hrv *_t784 = &(g529); int64_t _i784 = (x_568).a_; (S8*)_t784->b + hr_ix(_i784, _t784->n, "hc/types.amni:176"); }))).ta_)), ((int64_t)(((*({ hrv *_t785 = &(g529); int64_t _i785 = (x_568).a_; (S8*)_t785->b + hr_ix(_i785, _t785->n, "hc/types.amni:176"); }))).tn_)), out_567));
if (((((uint16_t)((uint64_t)(x_568).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v786 = out_567; hsl _s786 = hr_str("..", 2); hr_append(_v786, _s786.p, _s786.n, sizeof(uint8_t)); }));
 }
return;
 }
if (((k_569) == (((int64_t)7LL)))) { (void)(({ hrv *_v787 = out_567; hsl _s787 = f10_nm(((int64_t)(((*({ hrv *_t788 = &(g529); int64_t _i788 = (x_568).a_; (S8*)_t788->b + hr_ix(_i788, _t788->n, "hc/types.amni:177"); }))).name_))); hr_append(_v787, _s787.p, _s787.n, sizeof(uint8_t)); }));
(void)(f127_targs_into(((int64_t)(((*({ hrv *_t789 = &(g529); int64_t _i789 = (x_568).a_; (S8*)_t789->b + hr_ix(_i789, _t789->n, "hc/types.amni:177"); }))).ta_)), ((int64_t)(((*({ hrv *_t790 = &(g529); int64_t _i790 = (x_568).a_; (S8*)_t790->b + hr_ix(_i790, _t790->n, "hc/types.amni:177"); }))).tn_)), out_567));
(void)(({ hrv *_v791 = out_567; uint8_t _x791 = ((uint8_t)46LL); uint8_t *_p791 = (uint8_t*)hr_grow(_v791, 1, sizeof _x791); *_p791 = _x791; _p791; }));
(void)(({ hrv *_v792 = out_567; hsl _s792 = f10_nm(((int64_t)(((*({ hrv *_t793 = &(g530); int64_t _i793 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t794 = &(g529); int64_t _i794 = (x_568).a_; (S8*)_t794->b + hr_ix(_i794, _t794->n, "hc/types.amni:177"); }))).v0_)) + (int64_t)((int64_t)((x_568).c_)))); (S9*)_t793->b + hr_ix(_i793, _t793->n, "hc/types.amni:177"); }))).name_))); hr_append(_v792, _s792.p, _s792.n, sizeof(uint8_t)); }));
return;
 }
if (((k_569) == (((int64_t)9LL)))) { if (((((uint16_t)((uint64_t)(x_568).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v795 = out_567; hsl _s795 = hr_str("const ", 6); hr_append(_v795, _s795.p, _s795.n, sizeof(uint8_t)); }));
 }
(void)(f125_ty_name_into(((int64_t)((x_568).a_)), out_567));
(void)(({ hrv *_v796 = out_567; hsl _s796 = hr_str("[:]", 3); hr_append(_v796, _s796.p, _s796.n, sizeof(uint8_t)); }));
return;
 }
if (((k_569) == (((int64_t)10LL)))) { if (((((uint16_t)((uint64_t)(x_568).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v797 = out_567; hsl _s797 = hr_str("const ", 6); hr_append(_v797, _s797.p, _s797.n, sizeof(uint8_t)); }));
 }
(void)(f125_ty_name_into(((int64_t)((x_568).a_)), out_567));
if ((((x_568).c_) >= (((int32_t)0LL)))) { (void)(({ hrv *_v798 = out_567; hsl _s798 = hr_str("&<", 2); hr_append(_v798, _s798.p, _s798.n, sizeof(uint8_t)); }));
(void)(f126_ls_kind_name(((int64_t)((x_568).c_)), out_567));
(void)(({ hrv *_v799 = out_567; uint8_t _x799 = ((uint8_t)62LL); uint8_t *_p799 = (uint8_t*)hr_grow(_v799, 1, sizeof _x799); *_p799 = _x799; _p799; }));
if (((((uint16_t)((uint64_t)(x_568).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v800 = out_567; uint8_t _x800 = ((uint8_t)63LL); uint8_t *_p800 = (uint8_t*)hr_grow(_v800, 1, sizeof _x800); *_p800 = _x800; _p800; }));
 }
return;
 }
(void)(({ hrv *_v801 = out_567; hsl _s801 = ({ hsl _r802; if (((((uint16_t)((uint64_t)(x_568).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) { _r802 = hr_str("\077", 1);  } else { _r802 = hr_str("&", 1);  } _r802; }); hr_append(_v801, _s801.p, _s801.n, sizeof(uint8_t)); }));
return;
 }
if (((k_569) == (((int64_t)8LL)))) { (void)(f125_ty_name_into(((int64_t)((x_568).a_)), out_567));
int64_t a_577 = ((int64_t)((x_568).s_)); 
if (((a_577) == (((int64_t)1LL)))) { (void)(({ hrv *_o803 = out_567; hr_fs(_o803, hr_str("[", 1)); hr_fi(_o803, (x_568).b_); hr_fs(_o803, hr_str("]", 1)); }));
 }
if (((a_577) == (((int64_t)2LL)))) { (void)(({ hrv *_v804 = out_567; hsl _s804 = ({ hsl _r805; if (((((x_568).c_) >= (((int32_t)0LL))) && (((x_568).c_) != (((int32_t)6LL))))) { _r805 = hr_str("[", 1);  } else { _r805 = hr_str("[]", 2);  } _r805; }); hr_append(_v804, _s804.p, _s804.n, sizeof(uint8_t)); }));
if (((((x_568).c_) >= (((int32_t)0LL))) && (((x_568).c_) != (((int32_t)6LL))))) { if ((((x_568).c_) == (((int32_t)8LL)))) { (void)(({ hrv *_v806 = out_567; hsl _s806 = hr_str("varint", 6); hr_append(_v806, _s806.p, _s806.n, sizeof(uint8_t)); }));
 } else { (void)(f126_ls_kind_name(((int64_t)((x_568).c_)), out_567));
 }
(void)(({ hrv *_v807 = out_567; uint8_t _x807 = ((uint8_t)93LL); uint8_t *_p807 = (uint8_t*)hr_grow(_v807, 1, sizeof _x807); *_p807 = _x807; _p807; }));
 }
 }
if (((a_577) == (((int64_t)3LL)))) { if ((((x_568).b_) >= (((int64_t)0LL)))) { (void)(({ hrv *_o808 = out_567; hr_fs(_o808, hr_str("[..", 3)); hr_fi(_o808, (x_568).b_); hr_fs(_o808, hr_str("]", 1)); }));
 } else { (void)(({ hrv *_v809 = out_567; hsl _s809 = hr_str("[..]", 4); hr_append(_v809, _s809.p, _s809.n, sizeof(uint8_t)); }));
 }
 }
if (((a_577) == (((int64_t)4LL)))) { (void)(({ hrv *_v810 = out_567; hsl _s810 = hr_str("[>..]", 5); hr_append(_v810, _s810.p, _s810.n, sizeof(uint8_t)); }));
 }
if (((a_577) == (((int64_t)5LL)))) { (void)(({ hrv *_v811 = out_567; hsl _s811 = hr_str("[>..<]", 6); hr_append(_v811, _s811.p, _s811.n, sizeof(uint8_t)); }));
 }
return;
 }
if (((k_569) == (((int64_t)14LL)))) { { int32_t _e813 = (x_568).n_; for (int32_t i_578 = 0; i_578 < _e813; i_578++) { if (((i_578) > (((int32_t)0LL)))) { (void)(({ hrv *_v814 = out_567; hsl _s814 = hr_str(", ", 2); hr_append(_v814, _s814.p, _s814.n, sizeof(uint8_t)); }));
 }
(void)(f125_ty_name_into(((int64_t)((*({ hrv *_t815 = &(g525); int64_t _i815 = ((int64_t)((int64_t)((int64_t)((x_568).l_)) + (int64_t)((int64_t)(i_578)))); (int32_t*)_t815->b + hr_ix(_i815, _t815->n, "hc/types.amni:195"); })))), out_567));
 } } _bk812:; 
return;
 }
(void)(({ hrv *_v816 = out_567; hsl _s816 = hr_str("fn", 2); hr_append(_v816, _s816.p, _s816.n, sizeof(uint8_t)); }));
}
static void f126_ls_kind_name(int64_t s_570, hrv* out_571) {
A61 names_572 = ({ A61 _t817; _t817.e[0] = hr_str("i8", 2); _t817.e[1] = hr_str("i16", 3); _t817.e[2] = hr_str("i32", 3); _t817.e[3] = hr_str("i64", 3); _t817.e[4] = hr_str("u8", 2); _t817.e[5] = hr_str("u16", 3); _t817.e[6] = hr_str("u32", 3); _t817.e[7] = hr_str("u64", 3); _t817; }); 
(void)(({ hrv *_v818 = out_571; hsl _s818 = (names_572).e[hr_ix(((int64_t)((int64_t)s_570 & (int64_t)((int64_t)7LL))), 8, "hc/types.amni:160")]; hr_append(_v818, _s818.p, _s818.n, sizeof(uint8_t)); }));
}
static void f127_targs_into(int64_t l_573, int64_t n_574, hrv* out_575) {
if (((n_574) == (((int64_t)0LL)))) { return;
 }
(void)(({ hrv *_v820 = out_575; uint8_t _x820 = ((uint8_t)60LL); uint8_t *_p820 = (uint8_t*)hr_grow(_v820, 1, sizeof _x820); *_p820 = _x820; _p820; }));
{ int64_t _e822 = n_574; for (int64_t i_576 = 0; i_576 < _e822; i_576++) { if (((i_576) > (((int64_t)0LL)))) { (void)(({ hrv *_v823 = out_575; hsl _s823 = hr_str(", ", 2); hr_append(_v823, _s823.p, _s823.n, sizeof(uint8_t)); }));
 }
(void)(f125_ty_name_into(((int64_t)((*({ hrv *_t824 = &(g525); int64_t _i824 = ((int64_t)((int64_t)l_573 + (int64_t)i_576)); (int32_t*)_t824->b + hr_ix(_i824, _t824->n, "hc/types.amni:198"); })))), out_575));
 } } _bk821:; 
(void)(({ hrv *_v825 = out_575; uint8_t _x825 = ((uint8_t)62LL); uint8_t *_p825 = (uint8_t*)hr_grow(_v825, 1, sizeof _x825); *_p825 = _x825; _p825; }));
}
static int64_t f128_gb_find(int64_t name_580) {
int64_t i_581 = ((int64_t)((int64_t)(g466).n - (int64_t)((int64_t)1LL))); 
while (((i_581) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t827 = &(g466); int64_t _i827 = i_581; (S7*)_t827->b + hr_ix(_i827, _t827->n, "hc/decl.amni:72"); }))).name_))) == (name_580))) { return ((int64_t)(((*({ hrv *_t828 = &(g466); int64_t _i828 = i_581; (S7*)_t828->b + hr_ix(_i828, _t828->n, "hc/decl.amni:72"); }))).ty_));
 }
i_581--;
 } _bk826:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f129_inst_struct(int64_t node_587, hsl args_588) {
{ hrv *_v830 = &(g527); for (int64_t _k830 = 0; _k830 < _v830->n; _k830++) { S10 s_589 = ((S10*)_v830->b)[_k830]; int64_t i_590 = _k830; if ((((((int64_t)((s_589).node_))) == (node_587)) && ((((int64_t)((s_589).tn_))) == ((args_588).n)))) { bool same_591 = true; 
{ int64_t _e832 = (args_588).n; for (int64_t j_592 = 0; j_592 < _e832; j_592++) { if ((((*({ hrv *_t833 = &(g525); int64_t _i833 = ((int64_t)((int64_t)((int64_t)((s_589).ta_)) + (int64_t)j_592)); (int32_t*)_t833->b + hr_ix(_i833, _t833->n, "hc/decl.amni:142"); }))) != ((*({ hsl _t834 = args_588; int64_t _i834 = j_592; (int32_t*)_t834.p + hr_ix(_i834, _t834.n, "hc/decl.amni:142"); }))))) { same_591 = false;
 }
 } } _bk831:; 
if (same_591) { return i_590;
 }
 }
 } } _bk829:; 
int64_t ta_593 = (g525).n; 
(void)(({ hrv *_v835 = &(g525); hsl _s835 = args_588; hr_append(_v835, _s835.p, _s835.n, sizeof(int32_t)); }));
int64_t si_594 = (g527).n; 
(void)(({ hrv *_v836 = &(g527); S10 _x836 = ((S10){ .node_ = ((int32_t)(node_587)), .ta_ = ((int32_t)(ta_593)), .tn_ = ((int32_t)((args_588).n)), .f0_ = ((int32_t)((g528).n)), .fnum_ = ((int32_t)0LL), .name_ = ((*({ hrv *_t837 = &(g675); int64_t _i837 = node_587; (S4*)_t837->b + hr_ix(_i837, _t837->n, "hc/decl.amni:145"); }))).s_, }); S10 *_p836 = (S10*)hr_grow(_v836, 1, sizeof _x836); *_p836 = _x836; _p836; }));
L65 gn_595 = ({ L65 _t838; memset(&_t838, 0, sizeof _t838); _t838.n = 0; _t838; }); 
(void)(f130_gen_names(((int64_t)(((*({ hrv *_t839 = &(g675); int64_t _i839 = node_587; (S4*)_t839->b + hr_ix(_i839, _t839->n, "hc/decl.amni:146"); }))).d_)), (&(gn_595))));
if (((((int64_t)(gn_595).n)) != ((args_588).n))) { (void)(f102_derr(((int64_t)(((*({ hrv *_t840 = &(g675); int64_t _i840 = node_587; (S4*)_t840->b + hr_ix(_i840, _t840->n, "hc/decl.amni:147"); }))).t_)), hr_str("wrong number of type arguments", 30)));
 }
int64_t g0_599 = (g466).n; 
{ int64_t _e842 = f45_min(((int64_t)(gn_595).n), (args_588).n); for (int64_t i_600 = 0; i_600 < _e842; i_600++) { (void)(({ hrv *_v843 = &(g466); S7 _x843 = ((S7){ .name_ = (*({ L65 *_t844 = &(gn_595); int64_t _i844 = i_600; _t844->e + hr_ix(_i844, _t844->n, "hc/decl.amni:149"); })), .ty_ = (*({ hsl _t845 = args_588; int64_t _i845 = i_600; (int32_t*)_t845.p + hr_ix(_i845, _t845.n, "hc/decl.amni:149"); })), }); S7 *_p843 = (S7*)hr_grow(_v843, 1, sizeof _x843); *_p843 = _x843; _p843; }));
 } } _bk841:; 
int64_t f0_611 = f131_fields_into(node_587, f110_ns_of(node_587)); 
((*({ hrv *_t846 = &(g527); int64_t _i846 = si_594; (S10*)_t846->b + hr_ix(_i846, _t846->n, "hc/decl.amni:151"); }))).f0_ = ((int32_t)(f0_611));
((*({ hrv *_t847 = &(g527); int64_t _i847 = si_594; (S10*)_t847->b + hr_ix(_i847, _t847->n, "hc/decl.amni:151"); }))).fnum_ = ((int32_t)(((int64_t)((int64_t)(g528).n - (int64_t)f0_611))));
(void)(({ hrv *_v848 = &(g466); int64_t _k848 = ((int64_t)((int64_t)(g466).n - (int64_t)g0_599)); if (_k848 < 0 || _k848 > _v848->n) hr_die("pop_n past the length", "hc/decl.amni:152"); _v848->n -= _k848; }));
return si_594;
}
static void f130_gen_names(int64_t gl_596, L65* out_597) {
if (((gl_596) >= (((int64_t)0LL)))) { { int32_t _e850 = ((*({ hrv *_t851 = &(g675); int64_t _i851 = gl_596; (S4*)_t851->b + hr_ix(_i851, _t851->n, "hc/decl.amni:140"); }))).n_; for (int32_t i_598 = 0; i_598 < _e850; i_598++) { (void)(({ L65 *_v852 = out_597; int32_t _x852 = ((*({ hrv *_t853 = &(g675); int64_t _i853 = f90_kid(gl_596, ((int64_t)(i_598))); (S4*)_t853->b + hr_ix(_i853, _t853->n, "hc/decl.amni:140"); }))).s_; if (_v852->n >= 16) hr_die("push past a limited array's capacity", "hc/decl.amni:140"); _v852->e[_v852->n] = _x852; &_v852->e[_v852->n++]; }));
 } } _bk849:; 
 }
}
static int64_t f131_fields_into(int64_t node_601, int64_t ns_602) {
L72 buf_603 = ({ L72 _t854; memset(&_t854, 0, sizeof _t854); _t854.n = 0; _t854; }); 
{ int32_t _e856 = ((*({ hrv *_t857 = &(g675); int64_t _i857 = node_601; (S4*)_t857->b + hr_ix(_i857, _t857->n, "hc/decl.amni:157"); }))).n_; for (int32_t i_604 = 0; i_604 < _e856; i_604++) { int64_t f_605 = f90_kid(node_601, ((int64_t)(i_604))); 
S4 x_606 = (*({ hrv *_t858 = &(g675); int64_t _i858 = f_605; (S4*)_t858->b + hr_ix(_i858, _t858->n, "hc/decl.amni:159"); })); 
if (((((uint16_t)((uint64_t)(x_606).fl_ & (uint64_t)((uint16_t)4LL)))) != (((uint16_t)0LL)))) { (void)(({ L72 *_v859 = &(buf_603); S11 _x859 = ((S11){ .name_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .def_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .fl_ = (x_606).fl_, .padn_ = f132_max((x_606).c_, ((int32_t)0LL)), .off_ = ((int64_t)0LL), }); if (_v859->n >= 256) hr_die("push past a limited array's capacity", "hc/decl.amni:160"); _v859->e[_v859->n] = _x859; &_v859->e[_v859->n++]; }));
continue;
 }
int64_t ft_609 = f113_rtype(((int64_t)((x_606).a_)), ns_602); 
(void)(({ L72 *_v860 = &(buf_603); S11 _x860 = ((S11){ .name_ = (x_606).s_, .ty_ = ((int32_t)(ft_609)), .def_ = (x_606).b_, .fl_ = (x_606).fl_, .padn_ = ((int32_t)0LL), .off_ = ((int64_t)0LL), }); if (_v860->n >= 256) hr_die("push past a limited array's capacity", "hc/decl.amni:162"); _v860->e[_v860->n] = _x860; &_v860->e[_v860->n++]; }));
 } } _bk855:; 
int64_t f0_610 = (g528).n; 
(void)(({ hrv *_v861 = &(g528); hsl _s861 = ({ hsl _t862 = ({ L72 *_t863 = &(buf_603); (hsl){ (uint8_t*)_t863->e, _t863->n }; }); int64_t _l862 = 0, _h862 = _t862.n; if (_l862 < 0 || _h862 < _l862 || _h862 > _t862.n) hr_slerr(_l862, _h862, _t862.n, "hc/decl.amni:165"); (hsl){ _t862.p + _l862 * (int64_t)sizeof(S11), _h862 - _l862 }; }); hr_append(_v861, _s861.p, _s861.n, sizeof(S11)); }));
return f0_610;
}
static int32_t f132_max(int32_t a_607, int32_t b_608) {
if (((a_607) < (b_608))) { return b_608;
 }
return a_607;
}
static int64_t f133_t_struct(int64_t si_612) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)5LL))), .a_ = ((int32_t)(si_612)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f134_inst_enum(int64_t node_613, hsl args_614) {
{ hrv *_v865 = &(g529); for (int64_t _k865 = 0; _k865 < _v865->n; _k865++) { S8 s_615 = ((S8*)_v865->b)[_k865]; int64_t i_616 = _k865; if ((((((int64_t)((s_615).node_))) == (node_613)) && ((((int64_t)((s_615).tn_))) == ((args_614).n)))) { bool same_617 = true; 
{ int64_t _e867 = (args_614).n; for (int64_t j_618 = 0; j_618 < _e867; j_618++) { if ((((*({ hrv *_t868 = &(g525); int64_t _i868 = ((int64_t)((int64_t)((int64_t)((s_615).ta_)) + (int64_t)j_618)); (int32_t*)_t868->b + hr_ix(_i868, _t868->n, "hc/decl.amni:169"); }))) != ((*({ hsl _t869 = args_614; int64_t _i869 = j_618; (int32_t*)_t869.p + hr_ix(_i869, _t869.n, "hc/decl.amni:169"); }))))) { same_617 = false;
 }
 } } _bk866:; 
if (same_617) { return i_616;
 }
 }
 } } _bk864:; 
int64_t ta_619 = (g525).n; 
(void)(({ hrv *_v870 = &(g525); hsl _s870 = args_614; hr_append(_v870, _s870.p, _s870.n, sizeof(int32_t)); }));
int64_t ei_620 = (g529).n; 
int64_t nv_621 = ((int64_t)(((*({ hrv *_t871 = &(g675); int64_t _i871 = node_613; (S4*)_t871->b + hr_ix(_i871, _t871->n, "hc/decl.amni:172"); }))).n_)); 
(void)(({ hrv *_v872 = &(g529); S8 _x872 = ((S8){ .node_ = ((int32_t)(node_613)), .ta_ = ((int32_t)(ta_619)), .tn_ = ((int32_t)((args_614).n)), .v0_ = ((int32_t)((g530).n)), .vnum_ = ((int32_t)(nv_621)), .name_ = ((*({ hrv *_t873 = &(g675); int64_t _i873 = node_613; (S4*)_t873->b + hr_ix(_i873, _t873->n, "hc/decl.amni:173"); }))).s_, }); S8 *_p872 = (S8*)hr_grow(_v872, 1, sizeof _x872); *_p872 = _x872; _p872; }));
int64_t v0_622 = (g530).n; 
{ int64_t _e875 = nv_621; for (int64_t i_623 = 0; i_623 < _e875; i_623++) { int64_t v_624 = f90_kid(node_613, i_623); 
(void)(({ hrv *_v876 = &(g530); S9 _x876 = ((S9){ .name_ = ((*({ hrv *_t877 = &(g675); int64_t _i877 = v_624; (S4*)_t877->b + hr_ix(_i877, _t877->n, "hc/decl.amni:175"); }))).s_, .f0_ = ((int32_t)0LL), .fnum_ = ((int32_t)0LL), .si_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .size_ = ((int64_t)0LL), .haspay_ = ((((uint16_t)((uint64_t)((*({ hrv *_t878 = &(g675); int64_t _i878 = v_624; (S4*)_t878->b + hr_ix(_i878, _t878->n, "hc/decl.amni:175"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))), }); S9 *_p876 = (S9*)hr_grow(_v876, 1, sizeof _x876); *_p876 = _x876; _p876; }));
 } } _bk874:; 
L65 gn_625 = ({ L65 _t879; memset(&_t879, 0, sizeof _t879); _t879.n = 0; _t879; }); 
(void)(f130_gen_names(((int64_t)(((*({ hrv *_t880 = &(g675); int64_t _i880 = node_613; (S4*)_t880->b + hr_ix(_i880, _t880->n, "hc/decl.amni:176"); }))).d_)), (&(gn_625))));
int64_t g0_626 = (g466).n; 
{ int64_t _e882 = f45_min(((int64_t)(gn_625).n), (args_614).n); for (int64_t i_627 = 0; i_627 < _e882; i_627++) { (void)(({ hrv *_v883 = &(g466); S7 _x883 = ((S7){ .name_ = (*({ L65 *_t884 = &(gn_625); int64_t _i884 = i_627; _t884->e + hr_ix(_i884, _t884->n, "hc/decl.amni:178"); })), .ty_ = (*({ hsl _t885 = args_614; int64_t _i885 = i_627; (int32_t*)_t885.p + hr_ix(_i885, _t885.n, "hc/decl.amni:178"); })), }); S7 *_p883 = (S7*)hr_grow(_v883, 1, sizeof _x883); *_p883 = _x883; _p883; }));
 } } _bk881:; 
int64_t ns_628 = f110_ns_of(node_613); 
{ int64_t _e887 = nv_621; for (int64_t i_629 = 0; i_629 < _e887; i_629++) { int64_t v_630 = f90_kid(node_613, i_629); 
int64_t si_631 = (g527).n; 
(void)(({ hrv *_v888 = &(g527); S10 _x888 = ((S10){ .node_ = ((int32_t)(v_630)), .ta_ = ((int32_t)(ta_619)), .tn_ = ((int32_t)((args_614).n)), .f0_ = ((int32_t)((g528).n)), .fnum_ = ((int32_t)0LL), .name_ = ((*({ hrv *_t889 = &(g675); int64_t _i889 = v_630; (S4*)_t889->b + hr_ix(_i889, _t889->n, "hc/decl.amni:183"); }))).s_, }); S10 *_p888 = (S10*)hr_grow(_v888, 1, sizeof _x888); *_p888 = _x888; _p888; }));
int64_t f0_632 = f131_fields_into(v_630, ns_628); 
((*({ hrv *_t890 = &(g527); int64_t _i890 = si_631; (S10*)_t890->b + hr_ix(_i890, _t890->n, "hc/decl.amni:185"); }))).f0_ = ((int32_t)(f0_632));
((*({ hrv *_t891 = &(g527); int64_t _i891 = si_631; (S10*)_t891->b + hr_ix(_i891, _t891->n, "hc/decl.amni:185"); }))).fnum_ = ((int32_t)(((int64_t)((int64_t)(g528).n - (int64_t)f0_632))));
((*({ hrv *_t892 = &(g530); int64_t _i892 = ((int64_t)((int64_t)v0_622 + (int64_t)i_629)); (S9*)_t892->b + hr_ix(_i892, _t892->n, "hc/decl.amni:186"); }))).si_ = ((int32_t)(si_631));
 } } _bk886:; 
(void)(({ hrv *_v893 = &(g466); int64_t _k893 = ((int64_t)((int64_t)(g466).n - (int64_t)g0_626)); if (_k893 < 0 || _k893 > _v893->n) hr_die("pop_n past the length", "hc/decl.amni:188"); _v893->n -= _k893; }));
return ei_620;
}
static int64_t f135_t_enum(int64_t ei_633, bool vm_634) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)6LL))), .fl_ = ({ uint16_t _r894; if (vm_634) { _r894 = ((uint16_t)1LL);  } else { _r894 = ((uint16_t)0LL);  } _r894; }), .a_ = ((int32_t)(ei_633)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f136_ck(int64_t n_638, int64_t want_639) {
if (((n_638) < (((int64_t)0LL)))) { return g531;
 }
S4 x_640 = (*({ hrv *_t895 = &(g675); int64_t _i895 = n_638; (S4*)_t895->b + hr_ix(_i895, _t895->n, "hc/check.amni:594"); })); 
int64_t k_641 = ((int64_t)((x_640).k_)); 
if (((k_641) == (((int64_t)1LL)))) { if ((((want_639) >= (((int64_t)0LL))) && ((((((*({ hrv *_t896 = &(g524); int64_t _i896 = want_639; (S1*)_t896->b + hr_ix(_i896, _t896->n, "hc/check.amni:596"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t897 = &(g524); int64_t _i897 = want_639; (S1*)_t897->b + hr_ix(_i897, _t897->n, "hc/check.amni:596"); }))).k_) == (((uint8_t)4LL)))) || ((((*({ hrv *_t898 = &(g524); int64_t _i898 = want_639; (S1*)_t898->b + hr_ix(_i898, _t898->n, "hc/check.amni:596"); }))).k_) == (((uint8_t)17LL)))))) { (void)(f137_set_t(n_638, g544));
(void)(f139_conv(n_638, want_639));
return want_639;
 }
return f137_set_t(n_638, g544);
 }
if (((k_641) == (((int64_t)2LL)))) { if ((((want_639) >= (((int64_t)0LL))) && ((((*({ hrv *_t899 = &(g524); int64_t _i899 = want_639; (S1*)_t899->b + hr_ix(_i899, _t899->n, "hc/check.amni:597"); }))).k_) == (((uint8_t)4LL))))) { return f137_set_t(n_638, want_639);
 }
return f137_set_t(n_638, g545);
 }
if (((k_641) == (((int64_t)3LL)))) { if ((((want_639) >= (((int64_t)0LL))) && f163_is_byte_arr(want_639))) { return f137_set_t(n_638, want_639);
 }
return f137_set_t(n_638, g546);
 }
if ((((k_641) == (((int64_t)4LL))) || ((k_641) == (((int64_t)5LL))))) { return f137_set_t(n_638, g532);
 }
if (((k_641) == (((int64_t)6LL)))) { if ((((want_639) >= (((int64_t)0LL))) && f164_is_opt(want_639))) { return f137_set_t(n_638, want_639);
 }
return f137_set_t(n_638, g543);
 }
if (((k_641) == (((int64_t)8LL)))) { return f165_ck_id(n_638, want_639);
 }
if (((k_641) == (((int64_t)9LL)))) { int64_t t_829 = f173_ck_bin(n_638, want_639); 
if (((((want_639) >= (((int64_t)0LL))) && f162_is_pending(t_829)) && (((((*({ hrv *_t900 = &(g524); int64_t _i900 = want_639; (S1*)_t900->b + hr_ix(_i900, _t900->n, "hc/check.amni:602"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t901 = &(g524); int64_t _i901 = want_639; (S1*)_t901->b + hr_ix(_i901, _t901->n, "hc/check.amni:602"); }))).k_) == (((uint8_t)4LL)))))) { (void)(f139_conv(n_638, want_639));
return want_639;
 }
return t_829;
 }
if (((k_641) == (((int64_t)10LL)))) { int64_t t_856 = f178_ck_un(n_638, want_639); 
if (((((want_639) >= (((int64_t)0LL))) && f162_is_pending(t_856)) && (((((*({ hrv *_t902 = &(g524); int64_t _i902 = want_639; (S1*)_t902->b + hr_ix(_i902, _t902->n, "hc/check.amni:603"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t903 = &(g524); int64_t _i903 = want_639; (S1*)_t903->b + hr_ix(_i903, _t903->n, "hc/check.amni:603"); }))).k_) == (((uint8_t)4LL)))))) { (void)(f139_conv(n_638, want_639));
return want_639;
 }
return t_856;
 }
if (((k_641) == (((int64_t)14LL)))) { return f180_ck_dot(n_638, want_639);
 }
if (((k_641) == (((int64_t)12LL)))) { return f183_ck_idx(n_638, want_639);
 }
if (((k_641) == (((int64_t)13LL)))) { return f184_ck_slice(n_638, want_639);
 }
if (((k_641) == (((int64_t)15LL)))) { return f185_ck_as(n_638, want_639);
 }
if (((k_641) == (((int64_t)16LL)))) { return f186_ck_arr(n_638, want_639);
 }
if (((k_641) == (((int64_t)23LL)))) { return f187_ck_block(n_638, want_639);
 }
if (((k_641) == (((int64_t)24LL)))) { (void)(({ hrv *_v904 = &(g444); int32_t _x904 = ({ int32_t _r905; if ((((want_639) >= (((int64_t)0LL))) && ((want_639) != (g531)))) { _r905 = ((int32_t)(want_639));  } else { _r905 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));  } _r905; }); int32_t *_p904 = (int32_t*)hr_grow(_v904, 1, sizeof _x904); *_p904 = _x904; _p904; }));
int64_t bt_1028 = f136_ck(((int64_t)((x_640).a_)), want_639); 
int64_t t_1029 = ((int64_t)(({ hrv *_v906 = &(g444); if (!_v906->n) hr_die("pop of an empty array", "hc/check.amni:610"); ((int32_t*)_v906->b)[--_v906->n]; }))); 
if ((((bt_1028) != (g531)) && (!(f162_is_pending(bt_1028))))) { return f137_set_t(n_638, bt_1028);
 }
if (((t_1029) >= (((int64_t)0LL)))) { (void)(f139_conv(((int64_t)((x_640).a_)), t_1029));
return f137_set_t(n_638, t_1029);
 }
return f137_set_t(n_638, bt_1028);
 }
if (((k_641) == (((int64_t)19LL)))) { return f204_ck_if(n_638, want_639);
 }
if (((k_641) == (((int64_t)25LL)))) { return f206_ck_while(n_638);
 }
if (((k_641) == (((int64_t)26LL)))) { return f207_ck_loop(n_638, want_639);
 }
if (((k_641) == (((int64_t)27LL)))) { return f208_ck_for(n_638);
 }
if (((k_641) == (((int64_t)20LL)))) { return f210_ck_match(n_638, want_639);
 }
if (((k_641) == (((int64_t)28LL)))) { return f211_ck_ret(n_638);
 }
if (((k_641) == (((int64_t)29LL)))) { return f213_ck_break(n_638);
 }
if (((k_641) == (((int64_t)30LL)))) { return f137_set_t(n_638, g531);
 }
if (((k_641) == (((int64_t)11LL)))) { return f214_ck_call(n_638, want_639);
 }
if (((k_641) == (((int64_t)17LL)))) { return f242_ck_slit(n_638, want_639);
 }
if (((k_641) == (((int64_t)31LL)))) { return f137_set_t(n_638, g551);
 }
(void)(f108_cerr(n_638, hr_str("unsupported expression", 22)));
return f137_set_t(n_638, g548);
}
static int64_t f137_set_t(int64_t n_642, int64_t t_643) {
(*({ hrv *_t907 = &(g376); int64_t _i907 = f138_aix(n_642); (int32_t*)_t907->b + hr_ix(_i907, _t907->n, "hc/check.amni:39"); })) = ((int32_t)(t_643));
return t_643;
}
static int64_t f138_aix(int64_t n_644) {
int64_t i_645 = g382; 
while (((i_645) >= (((int64_t)0LL)))) { S6 f_646 = (*({ hrv *_t909 = &(g371); int64_t _i909 = i_645; (S6*)_t909->b + hr_ix(_i909, _t909->n, "hc/check.amni:34"); })); 
if ((((n_644) >= (((int64_t)((f_646).lo_)))) && ((n_644) < (((int64_t)((f_646).hi_)))))) { return ((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((f_646).ab_)) + (int64_t)n_644)) - (int64_t)((int64_t)((f_646).lo_))));
 }
i_645 = ((int64_t)((f_646).par_));
 } _bk908:; 
S6 g_647 = (*({ hrv *_t910 = &(g371); int64_t _i910 = g384; (S6*)_t910->b + hr_ix(_i910, _t910->n, "hc/check.amni:35"); })); 
return ((int64_t)((int64_t)((int64_t)((g_647).ab_)) + (int64_t)n_644));
}
static bool f139_conv(int64_t n_648, int64_t t_649) {
if ((((t_649) < (((int64_t)0LL))) || ((n_648) < (((int64_t)0LL))))) { return true;
 }
int64_t f_651 = f140_at(n_648); 
if (((f_651) < (((int64_t)0LL)))) { return true;
 }
if (((f_651) == (t_649))) { return true;
 }
int64_t fk_652 = ((int64_t)(((*({ hrv *_t911 = &(g524); int64_t _i911 = f_651; (S1*)_t911->b + hr_ix(_i911, _t911->n, "hc/check.amni:107"); }))).k_)); 
int64_t tkd_653 = ((int64_t)(((*({ hrv *_t912 = &(g524); int64_t _i912 = t_649; (S1*)_t912->b + hr_ix(_i912, _t912->n, "hc/check.amni:108"); }))).k_)); 
if ((((tkd_653) == (((int64_t)0LL))) || ((fk_652) == (((int64_t)0LL))))) { return true;
 }
if ((((((tkd_653) == (((int64_t)10LL))) && ((((*({ hrv *_t913 = &(g524); int64_t _i913 = t_649; (S1*)_t913->b + hr_ix(_i913, _t913->n, "hc/check.amni:110"); }))).c_) < (((int32_t)0LL)))) && ((fk_652) != (((int64_t)11LL)))) && ((fk_652) != (((int64_t)10LL))))) { if (((f141_tclass(t_649)) >= (((int64_t)0LL)))) { bool ok_687 = f139_conv(n_648, ((int64_t)(((*({ hrv *_t914 = &(g524); int64_t _i914 = t_649; (S1*)_t914->b + hr_ix(_i914, _t914->n, "hc/check.amni:110"); }))).a_))); 
if ((ok_687 && ((f147_cv(n_648)) < (((int64_t)0LL))))) { (void)(f148_set_cv(n_648, t_649));
 }
return ok_687;
 }
 }
if (((((fk_652) == (((int64_t)10LL))) && ((((*({ hrv *_t915 = &(g524); int64_t _i915 = f_651; (S1*)_t915->b + hr_ix(_i915, _t915->n, "hc/check.amni:111"); }))).c_) < (((int32_t)0LL)))) && ((tkd_653) != (((int64_t)10LL))))) { if (f149_conv_ok(((int64_t)(((*({ hrv *_t916 = &(g524); int64_t _i916 = f_651; (S1*)_t916->b + hr_ix(_i916, _t916->n, "hc/check.amni:111"); }))).a_)), t_649, n_648)) { (void)(f148_set_cv(n_648, t_649));
return true;
 }
 }
if (((fk_652) == (((int64_t)12LL)))) { M77 _t917 = f154_cval(n_648); int64_t v_721 = _t917.r0; bool u_722 = _t917.r1; bool ok_723 = _t917.r2; 
if (((tkd_653) == (((int64_t)3LL)))) { if ((ok_723 && (!(f157_int_fits(v_721, u_722, t_649))))) { hrv m_732 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t920 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o919 = &(m_732); hr_fs(_o919, hr_str("constant ", 9)); hr_fi(_o919, v_721); hr_fs(_o919, hr_str(" does not fit in ", 17)); hr_fs(_o919, hr_sl(*hr_tmp(&_t920, f160_tn(t_649)))); }));
}
(void)(f108_cerr(n_648, hr_sl(m_732)));
return false;
 }
(void)(f161_commit(n_648, t_649));
return true;
 }
if ((((tkd_653) == (((int64_t)4LL))) || ((tkd_653) == (((int64_t)17LL))))) { (void)(f161_commit(n_648, t_649));
return true;
 }
 }
if ((((fk_652) == (((int64_t)13LL))) && ((tkd_653) == (((int64_t)4LL))))) { (void)(f161_commit(n_648, t_649));
return true;
 }
if ((((fk_652) == (((int64_t)18LL))) && (f163_is_byte_arr(t_649) || (((tkd_653) == (((int64_t)10LL))) && f163_is_byte_arr(((int64_t)(((*({ hrv *_t921 = &(g524); int64_t _i921 = t_649; (S1*)_t921->b + hr_ix(_i921, _t921->n, "hc/check.amni:118"); }))).a_))))))) { (void)(f161_commit(n_648, ({ int64_t _r922; if (((tkd_653) == (((int64_t)10LL)))) { _r922 = ((int64_t)(((*({ hrv *_t923 = &(g524); int64_t _i923 = t_649; (S1*)_t923->b + hr_ix(_i923, _t923->n, "hc/check.amni:118"); }))).a_));  } else { _r922 = t_649;  } _r922; })));
return true;
 }
if ((((fk_652) == (((int64_t)19LL))) && (((tkd_653) == (((int64_t)8LL))) || ((tkd_653) == (((int64_t)9LL)))))) { (void)(f161_commit(n_648, t_649));
return true;
 }
if (((((fk_652) == (((int64_t)11LL))) && ((tkd_653) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t924 = &(g524); int64_t _i924 = t_649; (S1*)_t924->b + hr_ix(_i924, _t924->n, "hc/check.amni:120"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f161_commit(n_648, t_649));
return true;
 }
if (f149_conv_ok(f_651, t_649, n_648)) { (void)(f148_set_cv(n_648, t_649));
return true;
 }
hrv m_747 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t927 __attribute__((cleanup(hr_rdrop))) = {0}; hrv _t928 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o926 = &(m_747); hr_fs(_o926, hr_str("cannot convert ", 15)); hr_fs(_o926, hr_sl(*hr_tmp(&_t927, f160_tn(f_651)))); hr_fs(_o926, hr_str(" to ", 4)); hr_fs(_o926, hr_sl(*hr_tmp(&_t928, f160_tn(t_649)))); }));
}
(void)(f108_cerr(n_648, hr_sl(m_747)));
return false;
}
static int64_t f140_at(int64_t n_650) {
return ((int64_t)((*({ hrv *_t929 = &(g376); int64_t _i929 = f138_aix(n_650); (int32_t*)_t929->b + hr_ix(_i929, _t929->n, "hc/check.amni:38"); }))));
}
static int64_t f141_tclass(int64_t t_654) {
S1 x_655 = (*({ hrv *_t930 = &(g524); int64_t _i930 = t_654; (S1*)_t930->b + hr_ix(_i930, _t930->n, "hc/types.amni:83"); })); 
int64_t k_656 = ((int64_t)((x_655).k_)); 
if (((k_656) == (((int64_t)5LL)))) { (void)(f142_si_layout(((int64_t)((x_655).a_))));
return ((int64_t)(((*({ hrv *_t931 = &(g527); int64_t _i931 = (x_655).a_; (S10*)_t931->b + hr_ix(_i931, _t931->n, "hc/types.amni:85"); }))).cls_));
 }
if (((k_656) == (((int64_t)7LL)))) { (void)(f145_ei_layout(((int64_t)((x_655).a_))));
S9 v_684 = (*({ hrv *_t932 = &(g530); int64_t _i932 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t933 = &(g529); int64_t _i933 = (x_655).a_; (S8*)_t933->b + hr_ix(_i933, _t933->n, "hc/types.amni:86"); }))).v0_)) + (int64_t)((int64_t)((x_655).c_)))); (S9*)_t932->b + hr_ix(_i932, _t932->n, "hc/types.amni:86"); })); 
if ((((v_684).si_) >= (((int32_t)0LL)))) { (void)(f142_si_layout(((int64_t)((v_684).si_))));
return ((int64_t)(((*({ hrv *_t934 = &(g527); int64_t _i934 = (v_684).si_; (S10*)_t934->b + hr_ix(_i934, _t934->n, "hc/types.amni:86"); }))).cls_));
 }
return ((int64_t)0LL);
 }
if (((k_656) == (((int64_t)6LL)))) { (void)(f145_ei_layout(((int64_t)((x_655).a_))));
if (((((uint16_t)((uint64_t)(x_655).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) { return ((int64_t)0LL);
 }
return ((int64_t)(((*({ hrv *_t935 = &(g529); int64_t _i935 = (x_655).a_; (S8*)_t935->b + hr_ix(_i935, _t935->n, "hc/types.amni:87"); }))).cls_));
 }
if (((k_656) == (((int64_t)8LL)))) { int64_t a_685 = ((int64_t)((x_655).s_)); 
if ((((a_685) == (((int64_t)4LL))) || ((a_685) == (((int64_t)5LL))))) { return ((int64_t)2LL);
 }
if (((a_685) == (((int64_t)2LL)))) { return ((int64_t)1LL);
 }
if ((((a_685) == (((int64_t)3LL))) && (((x_655).b_) < (((int64_t)0LL))))) { return ((int64_t)1LL);
 }
int64_t ec_686 = f141_tclass(((int64_t)((x_655).a_))); 
return ({ int64_t _r936; if (((ec_686) > (((int64_t)0LL)))) { _r936 = ((int64_t)1LL);  } else { _r936 = ((int64_t)0LL);  } _r936; });
 }
if (((k_656) == (((int64_t)17LL)))) { return ((int64_t)1LL);
 }
return ((int64_t)0LL);
}
static void f142_si_layout(int64_t si_657) {
if (((((*({ hrv *_t937 = &(g527); int64_t _i937 = si_657; (S10*)_t937->b + hr_ix(_i937, _t937->n, "hc/types.amni:118"); }))).done_) != (((uint8_t)0LL)))) { return;
 }
((*({ hrv *_t938 = &(g527); int64_t _i938 = si_657; (S10*)_t938->b + hr_ix(_i938, _t938->n, "hc/types.amni:119"); }))).done_ = ((uint8_t)1LL);
int64_t off_658 = ((int64_t)0LL); 
int64_t cls_659 = ((int64_t)0LL); 
bool flat_660 = true; 
{ int32_t _e940 = ((*({ hrv *_t941 = &(g527); int64_t _i941 = si_657; (S10*)_t941->b + hr_ix(_i941, _t941->n, "hc/types.amni:121"); }))).fnum_; for (int32_t i_661 = 0; i_661 < _e940; i_661++) { int64_t fi_662 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t942 = &(g527); int64_t _i942 = si_657; (S10*)_t942->b + hr_ix(_i942, _t942->n, "hc/types.amni:122"); }))).f0_)) + (int64_t)((int64_t)(i_661)))); 
int64_t ft_663 = ((int64_t)(((*({ hrv *_t943 = &(g528); int64_t _i943 = fi_662; (S11*)_t943->b + hr_ix(_i943, _t943->n, "hc/types.amni:123"); }))).ty_)); 
if (((ft_663) < (((int64_t)0LL)))) { ((*({ hrv *_t944 = &(g528); int64_t _i944 = fi_662; (S11*)_t944->b + hr_ix(_i944, _t944->n, "hc/types.amni:124"); }))).off_ = off_658;
{ int64_t *_t945 = &(off_658); *_t945 = ((int64_t)((int64_t)(*_t945) + (int64_t)((int64_t)(((*({ hrv *_t946 = &(g528); int64_t _i946 = fi_662; (S11*)_t946->b + hr_ix(_i946, _t946->n, "hc/types.amni:124"); }))).padn_)))); }
continue;
 }
int64_t c_664 = f141_tclass(ft_663); 
((*({ hrv *_t947 = &(g528); int64_t _i947 = fi_662; (S11*)_t947->b + hr_ix(_i947, _t947->n, "hc/types.amni:126"); }))).off_ = ({ int64_t _r948; if (((cls_659) == (((int64_t)0LL)))) { _r948 = off_658;  } else { _r948 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r948; });
if (((c_664) > (cls_659))) { cls_659 = c_664;
 }
if (((c_664) == (((int64_t)0LL)))) { { int64_t *_t949 = &(off_658); *_t949 = ((int64_t)((int64_t)(*_t949) + (int64_t)f143_tsize(ft_663))); }
 } else { if (((cls_659) == (((int64_t)0LL)))) { cls_659 = c_664;
 }
 }
if ((!(f146_tflat(ft_663)))) { flat_660 = false;
 }
 } } _bk939:; 
((*({ hrv *_t950 = &(g527); int64_t _i950 = si_657; (S10*)_t950->b + hr_ix(_i950, _t950->n, "hc/types.amni:131"); }))).cls_ = ((uint8_t)(cls_659));
((*({ hrv *_t951 = &(g527); int64_t _i951 = si_657; (S10*)_t951->b + hr_ix(_i951, _t951->n, "hc/types.amni:131"); }))).flat_ = flat_660;
((*({ hrv *_t952 = &(g527); int64_t _i952 = si_657; (S10*)_t952->b + hr_ix(_i952, _t952->n, "hc/types.amni:132"); }))).size_ = ({ int64_t _r953; if (((cls_659) == (((int64_t)0LL)))) { _r953 = f103_max(off_658, ((int64_t)1LL));  } else { _r953 = off_658;  } _r953; });
((*({ hrv *_t954 = &(g527); int64_t _i954 = si_657; (S10*)_t954->b + hr_ix(_i954, _t954->n, "hc/types.amni:133"); }))).zero_ = ((off_658) == (((int64_t)0LL)));
((*({ hrv *_t955 = &(g527); int64_t _i955 = si_657; (S10*)_t955->b + hr_ix(_i955, _t955->n, "hc/types.amni:134"); }))).done_ = ((uint8_t)2LL);
}
static int64_t f143_tsize(int64_t t_665) {
S1 x_666 = (*({ hrv *_t956 = &(g524); int64_t _i956 = t_665; (S1*)_t956->b + hr_ix(_i956, _t956->n, "hc/types.amni:95"); })); 
int64_t k_667 = ((int64_t)((x_666).k_)); 
if (((k_667) == (((int64_t)2LL)))) { return ((int64_t)1LL);
 }
if (((k_667) == (((int64_t)3LL)))) { return f144_isz(((int64_t)((x_666).s_)));
 }
if (((k_667) == (((int64_t)4LL)))) { return ((int64_t)((x_666).s_));
 }
if (((k_667) == (((int64_t)10LL)))) { if ((((x_666).c_) >= (((int32_t)0LL)))) { return f144_isz(((int64_t)((x_666).c_)));
 }
return ((int64_t)8LL);
 }
if (((k_667) == (((int64_t)9LL)))) { return ((int64_t)16LL);
 }
if (((k_667) == (((int64_t)5LL)))) { (void)(f142_si_layout(((int64_t)((x_666).a_))));
return ((*({ hrv *_t957 = &(g527); int64_t _i957 = (x_666).a_; (S10*)_t957->b + hr_ix(_i957, _t957->n, "hc/types.amni:102"); }))).size_;
 }
if (((k_667) == (((int64_t)7LL)))) { (void)(f145_ei_layout(((int64_t)((x_666).a_))));
S9 v_679 = (*({ hrv *_t958 = &(g530); int64_t _i958 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t959 = &(g529); int64_t _i959 = (x_666).a_; (S8*)_t959->b + hr_ix(_i959, _t959->n, "hc/types.amni:103"); }))).v0_)) + (int64_t)((int64_t)((x_666).c_)))); (S9*)_t958->b + hr_ix(_i958, _t958->n, "hc/types.amni:103"); })); 
return (v_679).size_;
 }
if (((k_667) == (((int64_t)6LL)))) { (void)(f145_ei_layout(((int64_t)((x_666).a_))));
return ((*({ hrv *_t960 = &(g529); int64_t _i960 = (x_666).a_; (S8*)_t960->b + hr_ix(_i960, _t960->n, "hc/types.amni:104"); }))).size_;
 }
if (((k_667) == (((int64_t)8LL)))) { int64_t a_680 = ((int64_t)((x_666).s_)); 
if (((a_680) == (((int64_t)1LL)))) { return ((int64_t)((int64_t)f103_max((x_666).b_, ((int64_t)1LL)) * (int64_t)f143_tsize(((int64_t)((x_666).a_)))));
 }
if (((a_680) == (((int64_t)3LL)))) { return ((int64_t)((int64_t)f144_isz(((int64_t)((x_666).c_))) + (int64_t)((int64_t)((int64_t)f103_max((x_666).b_, ((int64_t)1LL)) * (int64_t)f143_tsize(((int64_t)((x_666).a_)))))));
 }
 }
return ((int64_t)0LL);
}
static int64_t f144_isz(int64_t s_668) {
return ((int64_t)((((int64_t)1LL)) << ((((int64_t)(((int64_t)((int64_t)s_668 & (int64_t)((int64_t)3LL)))))) & 63)));
}
static void f145_ei_layout(int64_t ei_669) {
if (((((*({ hrv *_t961 = &(g529); int64_t _i961 = ei_669; (S8*)_t961->b + hr_ix(_i961, _t961->n, "hc/types.amni:137"); }))).done_) != (((uint8_t)0LL)))) { return;
 }
((*({ hrv *_t962 = &(g529); int64_t _i962 = ei_669; (S8*)_t962->b + hr_ix(_i962, _t962->n, "hc/types.amni:138"); }))).done_ = ((uint8_t)1LL);
int64_t nv_670 = ((int64_t)(((*({ hrv *_t963 = &(g529); int64_t _i963 = ei_669; (S8*)_t963->b + hr_ix(_i963, _t963->n, "hc/types.amni:139"); }))).vnum_)); 
int64_t tz_671 = ({ int64_t _r964; if (((nv_670) <= (((int64_t)256LL)))) { _r964 = ((int64_t)1LL);  } else { _r964 = ((int64_t)2LL);  } _r964; }); 
((*({ hrv *_t965 = &(g529); int64_t _i965 = ei_669; (S8*)_t965->b + hr_ix(_i965, _t965->n, "hc/types.amni:141"); }))).tagsz_ = ((uint8_t)(tz_671));
int64_t mx_672 = ((int64_t)0LL); 
int64_t cls_673 = ((int64_t)0LL); 
bool flat_674 = true; 
{ int64_t _e967 = nv_670; for (int64_t i_675 = 0; i_675 < _e967; i_675++) { int64_t v_676 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t968 = &(g529); int64_t _i968 = ei_669; (S8*)_t968->b + hr_ix(_i968, _t968->n, "hc/types.amni:144"); }))).v0_)) + (int64_t)i_675)); 
if (((((*({ hrv *_t969 = &(g530); int64_t _i969 = v_676; (S9*)_t969->b + hr_ix(_i969, _t969->n, "hc/types.amni:145"); }))).si_) >= (((int32_t)0LL)))) { int64_t si_677 = ((int64_t)(((*({ hrv *_t970 = &(g530); int64_t _i970 = v_676; (S9*)_t970->b + hr_ix(_i970, _t970->n, "hc/types.amni:146"); }))).si_)); 
(void)(f142_si_layout(si_677));
if (((((int64_t)(((*({ hrv *_t971 = &(g527); int64_t _i971 = si_677; (S10*)_t971->b + hr_ix(_i971, _t971->n, "hc/types.amni:148"); }))).cls_))) > (cls_673))) { cls_673 = ((int64_t)(((*({ hrv *_t972 = &(g527); int64_t _i972 = si_677; (S10*)_t972->b + hr_ix(_i972, _t972->n, "hc/types.amni:148"); }))).cls_));
 }
if ((!(((*({ hrv *_t973 = &(g527); int64_t _i973 = si_677; (S10*)_t973->b + hr_ix(_i973, _t973->n, "hc/types.amni:149"); }))).flat_))) { flat_674 = false;
 }
int64_t ps_678 = ({ int64_t _r974; if (((*({ hrv *_t975 = &(g527); int64_t _i975 = si_677; (S10*)_t975->b + hr_ix(_i975, _t975->n, "hc/types.amni:150"); }))).zero_) { _r974 = ((int64_t)0LL);  } else { _r974 = ((*({ hrv *_t976 = &(g527); int64_t _i976 = si_677; (S10*)_t976->b + hr_ix(_i976, _t976->n, "hc/types.amni:150"); }))).size_;  } _r974; }); 
((*({ hrv *_t977 = &(g530); int64_t _i977 = v_676; (S9*)_t977->b + hr_ix(_i977, _t977->n, "hc/types.amni:151"); }))).size_ = ps_678;
if (((ps_678) > (mx_672))) { mx_672 = ps_678;
 }
 }
 } } _bk966:; 
((*({ hrv *_t978 = &(g529); int64_t _i978 = ei_669; (S8*)_t978->b + hr_ix(_i978, _t978->n, "hc/types.amni:155"); }))).cls_ = ((uint8_t)(cls_673));
((*({ hrv *_t979 = &(g529); int64_t _i979 = ei_669; (S8*)_t979->b + hr_ix(_i979, _t979->n, "hc/types.amni:155"); }))).flat_ = flat_674;
((*({ hrv *_t980 = &(g529); int64_t _i980 = ei_669; (S8*)_t980->b + hr_ix(_i980, _t980->n, "hc/types.amni:156"); }))).size_ = ((int64_t)((int64_t)((int64_t)(tz_671)) + (int64_t)mx_672));
((*({ hrv *_t981 = &(g529); int64_t _i981 = ei_669; (S8*)_t981->b + hr_ix(_i981, _t981->n, "hc/types.amni:157"); }))).done_ = ((uint8_t)2LL);
}
static bool f146_tflat(int64_t t_681) {
S1 x_682 = (*({ hrv *_t982 = &(g524); int64_t _i982 = t_681; (S1*)_t982->b + hr_ix(_i982, _t982->n, "hc/types.amni:109"); })); 
int64_t k_683 = ((int64_t)((x_682).k_)); 
if ((((k_683) == (((int64_t)10LL))) || ((k_683) == (((int64_t)9LL))))) { return false;
 }
if (((k_683) == (((int64_t)5LL)))) { (void)(f142_si_layout(((int64_t)((x_682).a_))));
return ((*({ hrv *_t983 = &(g527); int64_t _i983 = (x_682).a_; (S10*)_t983->b + hr_ix(_i983, _t983->n, "hc/types.amni:111"); }))).flat_;
 }
if ((((k_683) == (((int64_t)6LL))) || ((k_683) == (((int64_t)7LL))))) { (void)(f145_ei_layout(((int64_t)((x_682).a_))));
return ((*({ hrv *_t984 = &(g529); int64_t _i984 = (x_682).a_; (S8*)_t984->b + hr_ix(_i984, _t984->n, "hc/types.amni:112"); }))).flat_;
 }
if (((k_683) == (((int64_t)8LL)))) { return f146_tflat(((int64_t)((x_682).a_)));
 }
return true;
}
static int64_t f147_cv(int64_t n_688) {
return ((int64_t)((*({ hrv *_t985 = &(g377); int64_t _i985 = f138_aix(n_688); (int32_t*)_t985->b + hr_ix(_i985, _t985->n, "hc/check.amni:46"); }))));
}
static void f148_set_cv(int64_t n_689, int64_t t_690) {
(*({ hrv *_t986 = &(g377); int64_t _i986 = f138_aix(n_689); (int32_t*)_t986->b + hr_ix(_i986, _t986->n, "hc/check.amni:45"); })) = ((int32_t)(t_690));
}
static bool f149_conv_ok(int64_t f_691, int64_t t_692, int64_t n_693) {
if (((f_691) == (t_692))) { return true;
 }
S1 a_694 = (*({ hrv *_t987 = &(g524); int64_t _i987 = f_691; (S1*)_t987->b + hr_ix(_i987, _t987->n, "hc/check.amni:127"); })); 
S1 b_695 = (*({ hrv *_t988 = &(g524); int64_t _i988 = t_692; (S1*)_t988->b + hr_ix(_i988, _t988->n, "hc/check.amni:127"); })); 
if (f150_widens(f_691, t_692)) { return true;
 }
if ((((((b_695).k_) == (((uint8_t)9LL))) && ((((a_694).k_) == (((uint8_t)8LL))) || (((a_694).k_) == (((uint8_t)9LL))))) && (((a_694).a_) == ((b_695).a_)))) { return true;
 }
if ((((((b_695).k_) == (((uint8_t)9LL))) && (((a_694).k_) == (((uint8_t)18LL)))) && ((((int64_t)((b_695).a_))) == (g537)))) { return true;
 }
if (((((((b_695).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)(b_695).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && (((a_694).k_) == (((uint8_t)10LL)))) && (((a_694).a_) == ((b_695).a_)))) { return true;
 }
if ((((((b_695).k_) == (((uint8_t)10LL))) && (((b_695).c_) < (((int32_t)0LL)))) && ((((int64_t)((b_695).a_))) == (f_691)))) { return true;
 }
if ((((((b_695).k_) == (((uint8_t)6LL))) && (((a_694).k_) == (((uint8_t)7LL)))) && (((a_694).a_) == ((b_695).a_)))) { return true;
 }
if ((((((((b_695).k_) == (((uint8_t)8LL))) && (((a_694).k_) == (((uint8_t)8LL)))) && (((a_694).a_) == ((b_695).a_))) && ((n_693) >= (((int64_t)0LL)))) && f153_is_construct(n_693))) { return true;
 }
if ((((((((b_695).k_) == (((uint8_t)8LL))) && (((a_694).k_) == (((uint8_t)9LL)))) && (((a_694).a_) == ((b_695).a_))) && ((n_693) >= (((int64_t)0LL)))) && f153_is_construct(n_693))) { return true;
 }
return false;
}
static bool f150_widens(int64_t f_696, int64_t t_697) {
if (((f_696) == (t_697))) { return true;
 }
S1 a_698 = (*({ hrv *_t989 = &(g524); int64_t _i989 = f_696; (S1*)_t989->b + hr_ix(_i989, _t989->n, "hc/check.amni:74"); })); 
S1 b_699 = (*({ hrv *_t990 = &(g524); int64_t _i990 = t_697; (S1*)_t990->b + hr_ix(_i990, _t990->n, "hc/check.amni:74"); })); 
if (((((a_698).k_) == (((uint8_t)3LL))) && (((b_699).k_) == (((uint8_t)3LL))))) { bool fs_701 = f151_is_signed(f_696); 
bool ts_702 = f151_is_signed(t_697); 
if (((fs_701) == (ts_702))) { return ((f152_ibits(t_697)) > (f152_ibits(f_696)));
 }
return (((!(fs_701)) && ts_702) && ((f152_ibits(t_697)) > (f152_ibits(f_696))));
 }
if (((((a_698).k_) == (((uint8_t)3LL))) && (((b_699).k_) == (((uint8_t)4LL))))) { return true;
 }
if (((((a_698).k_) == (((uint8_t)4LL))) && (((b_699).k_) == (((uint8_t)4LL))))) { return (((b_699).s_) > ((a_698).s_));
 }
if (((((a_698).k_) == (((uint8_t)3LL))) && (((b_699).k_) == (((uint8_t)17LL))))) { return (!((((f152_ibits(f_696)) == (((int64_t)64LL))) && (!(f151_is_signed(f_696))))));
 }
if (((((a_698).k_) == (((uint8_t)17LL))) && (((b_699).k_) == (((uint8_t)3LL))))) { return ((t_697) == (g536));
 }
return false;
}
static bool f151_is_signed(int64_t t_700) {
return ((((*({ hrv *_t991 = &(g524); int64_t _i991 = t_700; (S1*)_t991->b + hr_ix(_i991, _t991->n, "hc/types.amni:60"); }))).s_) < (((uint8_t)4LL)));
}
static int64_t f152_ibits(int64_t t_703) {
return ((int64_t)((((int64_t)8LL)) << ((((int64_t)(((uint8_t)((uint64_t)((*({ hrv *_t992 = &(g524); int64_t _i992 = t_703; (S1*)_t992->b + hr_ix(_i992, _t992->n, "hc/types.amni:61"); }))).s_ & (uint64_t)((uint8_t)3LL)))))) & 63)));
}
static bool f153_is_construct(int64_t n_704) {
int64_t k_705 = ((int64_t)(((*({ hrv *_t993 = &(g675); int64_t _i993 = n_704; (S4*)_t993->b + hr_ix(_i993, _t993->n, "hc/check.amni:138"); }))).k_)); 
return ((((k_705) == (((int64_t)11LL))) || ((k_705) == (((int64_t)16LL)))) || ((k_705) == (((int64_t)3LL))));
}
static M77 f154_cval(int64_t n_706) {
S4 x_707 = (*({ hrv *_t994 = &(g675); int64_t _i994 = n_706; (S4*)_t994->b + hr_ix(_i994, _t994->n, "hc/check.amni:83"); })); 
int64_t k_708 = ((int64_t)((x_707).k_)); 
if (((k_708) == (((int64_t)1LL)))) { return (M77){ ((*({ hrv *_t995 = &(g885); int64_t _i995 = (x_707).t_; (S3*)_t995->b + hr_ix(_i995, _t995->n, "hc/check.amni:84"); }))).v_, ((*({ hrv *_t996 = &(g885); int64_t _i996 = (x_707).t_; (S3*)_t996->b + hr_ix(_i996, _t996->n, "hc/check.amni:84"); }))).uns_, true };
 }
if (((k_708) == (((int64_t)10LL)))) { M77 _t997 = f154_cval(((int64_t)((x_707).a_))); int64_t v_709 = _t997.r0; bool u_710 = _t997.r1; bool ok_711 = _t997.r2; 
if ((!(ok_711))) { return (M77){ ((int64_t)0LL), false, false };
 }
if (((((int64_t)((x_707).op_))) == (((int64_t)22LL)))) { return (M77){ ((int64_t)(0 - (uint64_t)(v_709))), false, true };
 }
if (((((int64_t)((x_707).op_))) == (((int64_t)48LL)))) { return (M77){ ((int64_t)~(v_709)), false, true };
 }
return (M77){ ((int64_t)0LL), false, false };
 }
if ((((k_708) == (((int64_t)8LL))) && ((f155_rk(n_706)) == (((int64_t)6LL))))) { return (M77){ (*({ hrv *_t998 = &(g412); int64_t _i998 = f156_rv(n_706); (int64_t*)_t998->b + hr_ix(_i998, _t998->n, "hc/check.amni:86"); })), false, true };
 }
if (((k_708) == (((int64_t)9LL)))) { M77 _t999 = f154_cval(((int64_t)((x_707).a_))); int64_t a_714 = _t999.r0; bool ua_715 = _t999.r1; bool oa_716 = _t999.r2; 
M77 _t1000 = f154_cval(((int64_t)((x_707).b_))); int64_t b_717 = _t1000.r0; bool ub_718 = _t1000.r1; bool ob_719 = _t1000.r2; 
if (((!(oa_716)) || (!(ob_719)))) { return (M77){ ((int64_t)0LL), false, false };
 }
int64_t o_720 = ((int64_t)((x_707).op_)); 
if (((o_720) == (((int64_t)21LL)))) { return (M77){ ((int64_t)((int64_t)a_714 + (int64_t)b_717)), false, true };
 }
if (((o_720) == (((int64_t)22LL)))) { return (M77){ ((int64_t)((int64_t)a_714 - (int64_t)b_717)), false, true };
 }
if (((o_720) == (((int64_t)23LL)))) { return (M77){ ((int64_t)((int64_t)a_714 * (int64_t)b_717)), false, true };
 }
if (((o_720) == (((int64_t)24LL)))) { if (((b_717) == (((int64_t)0LL)))) { return (M77){ ((int64_t)0LL), false, false };
 }
return (M77){ HR_SDIV(int64_t, a_714, b_717, "hc/check.amni:92"), false, true };
 }
if (((o_720) == (((int64_t)25LL)))) { if (((b_717) == (((int64_t)0LL)))) { return (M77){ ((int64_t)0LL), false, false };
 }
return (M77){ HR_SMOD(int64_t, ((int64_t)((int64_t)HR_SMOD(int64_t, a_714, b_717, "hc/check.amni:93") + (int64_t)b_717)), b_717, "hc/check.amni:93"), false, true };
 }
if (((o_720) == (((int64_t)43LL)))) { return (M77){ ((int64_t)((a_714) << ((b_717) & 63))), false, true };
 }
if (((o_720) == (((int64_t)44LL)))) { return (M77){ ((int64_t)((a_714) >> ((b_717) & 63))), false, true };
 }
if (((o_720) == (((int64_t)49LL)))) { return (M77){ ((int64_t)((int64_t)a_714 & (int64_t)b_717)), false, true };
 }
if (((o_720) == (((int64_t)50LL)))) { return (M77){ ((int64_t)((int64_t)a_714 | (int64_t)b_717)), false, true };
 }
if (((o_720) == (((int64_t)51LL)))) { return (M77){ ((int64_t)((int64_t)a_714 ^ (int64_t)b_717)), false, true };
 }
 }
if ((((k_708) == (((int64_t)19LL))) || ((k_708) == (((int64_t)23LL))))) { return (M77){ ((int64_t)0LL), false, false };
 }
return (M77){ ((int64_t)0LL), false, false };
}
static int64_t f155_rk(int64_t n_712) {
return ((int64_t)((*({ hrv *_t1001 = &(g378); int64_t _i1001 = f138_aix(n_712); (uint8_t*)_t1001->b + hr_ix(_i1001, _t1001->n, "hc/check.amni:41"); }))));
}
static int64_t f156_rv(int64_t n_713) {
return ((int64_t)((*({ hrv *_t1002 = &(g379); int64_t _i1002 = f138_aix(n_713); (int32_t*)_t1002->b + hr_ix(_i1002, _t1002->n, "hc/check.amni:42"); }))));
}
static bool f157_int_fits(int64_t v_724, bool uns_725, int64_t t_726) {
if (((((*({ hrv *_t1003 = &(g524); int64_t _i1003 = t_726; (S1*)_t1003->b + hr_ix(_i1003, _t1003->n, "hc/check.amni:67"); }))).k_) != (((uint8_t)3LL)))) { return false;
 }
if (uns_725) { return ((!(f151_is_signed(t_726))) && ((f152_ibits(t_726)) == (((int64_t)64LL))));
 }
if (((v_724) < (((int64_t)0LL)))) { return (f151_is_signed(t_726) && ((v_724) >= (f158_int_min(t_726))));
 }
return ((((uint64_t)(v_724))) <= (f159_int_max_u(t_726)));
}
static int64_t f158_int_min(int64_t t_727) {
if ((!(f151_is_signed(t_727)))) { return ((int64_t)0LL);
 }
int64_t b_728 = f152_ibits(t_727); 
return ({ int64_t _r1004; if (((b_728) == (((int64_t)64LL)))) { _r1004 = ((int64_t)((int64_t)((int64_t)(0 - (uint64_t)(((int64_t)9223372036854775807LL)))) - (int64_t)((int64_t)1LL)));  } else { _r1004 = ((int64_t)(0 - (uint64_t)(((int64_t)((((int64_t)1LL)) << ((((int64_t)((int64_t)b_728 - (int64_t)((int64_t)1LL)))) & 63))))));  } _r1004; });
}
static uint64_t f159_int_max_u(int64_t t_729) {
int64_t b_730 = f152_ibits(t_729); 
bool sg_731 = f151_is_signed(t_729); 
return ({ uint64_t _r1005; if (((b_730) == (((int64_t)64LL)))) { _r1005 = ({ uint64_t _r1006; if (sg_731) { _r1006 = ((uint64_t)9223372036854775807LL);  } else { _r1006 = ((uint64_t)18446744073709551615ULL);  } _r1006; });  } else { _r1005 = ({ uint64_t _r1007; if (sg_731) { _r1007 = ((uint64_t)((uint64_t)((uint64_t)((((uint64_t)1LL)) << ((((int64_t)((int64_t)b_730 - (int64_t)((int64_t)1LL)))) & 63))) - (uint64_t)((uint64_t)1LL)));  } else { _r1007 = ((uint64_t)((uint64_t)((uint64_t)((((uint64_t)1LL)) << ((b_730) & 63))) - (uint64_t)((uint64_t)1LL)));  } _r1007; });  } _r1005; });
}
static hrv f160_tn(int64_t t_733) {
return f124_ty_name(t_733);
}
static void f161_commit(int64_t n_734, int64_t t_735) {
if (((n_734) < (((int64_t)0LL)))) { return;
 }
S4 x_736 = (*({ hrv *_t1008 = &(g675); int64_t _i1008 = n_734; (S4*)_t1008->b + hr_ix(_i1008, _t1008->n, "hc/check.amni:141"); })); 
int64_t k_737 = ((int64_t)((x_736).k_)); 
int64_t f_738 = f140_at(n_734); 
if ((((f_738) >= (((int64_t)0LL))) && (!(f162_is_pending(f_738))))) { if ((((f_738) != (t_735)) && f149_conv_ok(f_738, t_735, n_734))) { (void)(f148_set_cv(n_734, t_735));
 }
return;
 }
(void)(f137_set_t(n_734, t_735));
if (((k_737) == (((int64_t)10LL)))) { (void)(f161_commit(((int64_t)((x_736).a_)), t_735));
return;
 }
if (((k_737) == (((int64_t)9LL)))) { int64_t o_741 = ((int64_t)((x_736).op_)); 
if ((((o_741) == (((int64_t)43LL))) || ((o_741) == (((int64_t)44LL))))) { (void)(f161_commit(((int64_t)((x_736).a_)), t_735));
return;
 }
if (((f92_binprec(o_741)) >= (((int64_t)5LL)))) { (void)(f161_commit(((int64_t)((x_736).a_)), t_735));
(void)(f161_commit(((int64_t)((x_736).b_)), t_735));
 }
return;
 }
if (((k_737) == (((int64_t)19LL)))) { (void)(f161_commit(((int64_t)((x_736).b_)), t_735));
if ((((x_736).c_) >= (((int32_t)0LL)))) { (void)(f161_commit(((int64_t)((x_736).c_)), t_735));
 }
return;
 }
if (((k_737) == (((int64_t)23LL)))) { if ((((x_736).a_) >= (((int32_t)0LL)))) { (void)(f161_commit(((int64_t)((x_736).a_)), t_735));
 }
return;
 }
if (((k_737) == (((int64_t)24LL)))) { (void)(f161_commit(((int64_t)((x_736).a_)), t_735));
return;
 }
if (((k_737) == (((int64_t)20LL)))) { { int32_t _e1010 = (x_736).n_; for (int32_t i_742 = 0; i_742 < _e1010; i_742++) { (void)(f161_commit(((int64_t)(((*({ hrv *_t1011 = &(g675); int64_t _i1011 = f90_kid(n_734, ((int64_t)(i_742))); (S4*)_t1011->b + hr_ix(_i1011, _t1011->n, "hc/check.amni:155"); }))).b_)), t_735));
 } } _bk1009:; 
return;
 }
if (((k_737) == (((int64_t)16LL)))) { int64_t e_743 = ({ int64_t _r1012; if ((((((*({ hrv *_t1013 = &(g524); int64_t _i1013 = t_735; (S1*)_t1013->b + hr_ix(_i1013, _t1013->n, "hc/check.amni:157"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t1014 = &(g524); int64_t _i1014 = t_735; (S1*)_t1014->b + hr_ix(_i1014, _t1014->n, "hc/check.amni:157"); }))).k_) == (((uint8_t)9LL))))) { _r1012 = ((int64_t)(((*({ hrv *_t1015 = &(g524); int64_t _i1015 = t_735; (S1*)_t1015->b + hr_ix(_i1015, _t1015->n, "hc/check.amni:157"); }))).a_));  } else { _r1012 = g548;  } _r1012; }); 
if ((((x_736).a_) >= (((int32_t)0LL)))) { (void)(f139_conv(((int64_t)((x_736).a_)), e_743));
(void)(f139_conv(((int64_t)((x_736).b_)), g536));
 }
{ int32_t _e1017 = (x_736).n_; for (int32_t i_744 = 0; i_744 < _e1017; i_744++) { (void)(f139_conv(f90_kid(n_734, ((int64_t)(i_744))), e_743));
 } } _bk1016:; 
if (((((*({ hrv *_t1018 = &(g524); int64_t _i1018 = t_735; (S1*)_t1018->b + hr_ix(_i1018, _t1018->n, "hc/check.amni:160"); }))).k_) == (((uint8_t)9LL)))) { (void)(f137_set_t(n_734, f121_t_arr(e_743, ((int64_t)1LL), f103_max(((int64_t)((x_736).n_)), ((int64_t)1LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f148_set_cv(n_734, t_735));
 }
return;
 }
}
static bool f162_is_pending(int64_t t_739) {
int64_t k_740 = ((int64_t)(((*({ hrv *_t1019 = &(g524); int64_t _i1019 = t_739; (S1*)_t1019->b + hr_ix(_i1019, _t1019->n, "hc/check.amni:65"); }))).k_)); 
return ((((((k_740) == (((int64_t)12LL))) || ((k_740) == (((int64_t)13LL)))) || ((k_740) == (((int64_t)18LL)))) || ((k_740) == (((int64_t)19LL)))) || ((k_740) == (((int64_t)11LL))));
}
static bool f163_is_byte_arr(int64_t t_745) {
uint8_t k_746 = ((*({ hrv *_t1020 = &(g524); int64_t _i1020 = t_745; (S1*)_t1020->b + hr_ix(_i1020, _t1020->n, "hc/types.amni:68"); }))).k_; 
return ((((k_746) == (((uint8_t)8LL))) || ((k_746) == (((uint8_t)9LL)))) && ((((int64_t)(((*({ hrv *_t1021 = &(g524); int64_t _i1021 = t_745; (S1*)_t1021->b + hr_ix(_i1021, _t1021->n, "hc/types.amni:68"); }))).a_))) == (g537)));
}
static bool f164_is_opt(int64_t t_748) {
return (((((*({ hrv *_t1022 = &(g524); int64_t _i1022 = t_748; (S1*)_t1022->b + hr_ix(_i1022, _t1022->n, "hc/types.amni:66"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1023 = &(g524); int64_t _i1023 = t_748; (S1*)_t1023->b + hr_ix(_i1023, _t1023->n, "hc/types.amni:66"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))));
}
static int64_t f165_ck_id(int64_t n_749, int64_t want_750) {
int64_t name_751 = ((int64_t)(((*({ hrv *_t1024 = &(g675); int64_t _i1024 = n_749; (S4*)_t1024->b + hr_ix(_i1024, _t1024->n, "hc/check.amni:280"); }))).s_)); 
int64_t v_757 = f166_find_lv(name_751); 
if (((v_757) >= (((int64_t)0LL)))) { (void)(f168_set_r(n_749, ((int64_t)1LL), v_757));
(void)(f169_note_cap(v_757));
return f137_set_t(n_749, ((int64_t)(((*({ hrv *_t1025 = &(g372); int64_t _i1025 = v_757; (S12*)_t1025->b + hr_ix(_i1025, _t1025->n, "hc/check.amni:282"); }))).ty_)));
 }
int64_t ns_765 = f110_ns_of(n_749); 
int64_t d_766 = f119_lookup_q(name_751, ns_765, ((int64_t)5LL)); 
if (((d_766) >= (((int64_t)0LL)))) { int64_t g_767 = ((int64_t)(((*({ hrv *_t1026 = &(g464); int64_t _i1026 = d_766; (S5*)_t1026->b + hr_ix(_i1026, _t1026->n, "hc/check.amni:286"); }))).node_)); 
int64_t ci_780 = f170_const_of(d_766); 
if (((ci_780) >= (((int64_t)0LL)))) { (void)(f168_set_r(n_749, ((int64_t)6LL), ci_780));
return f137_set_t(n_749, g544);
 }
(void)(f168_set_r(n_749, ((int64_t)2LL), d_766));
return f137_set_t(n_749, f109_global_type(d_766));
 }
d_766 = f119_lookup_q(name_751, ns_765, ((int64_t)4LL));
if (((d_766) >= (((int64_t)0LL)))) { (void)(f168_set_r(n_749, ((int64_t)3LL), d_766));
(void)(f172_set_x(n_749, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f137_set_t(n_749, g551);
 }
hrv m_783 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1028 = &(m_783); hr_fs(_o1028, hr_str("unknown name: ", 14)); hr_fs(_o1028, f10_nm(name_751)); }));
(void)(f108_cerr(n_749, hr_sl(m_783)));
return f137_set_t(n_749, g548);
}
static int64_t f166_find_lv(int64_t name_752) {
int64_t i_753 = ((int64_t)((int64_t)(g373).n - (int64_t)((int64_t)1LL))); 
while (((i_753) >= (((int64_t)0LL)))) { int64_t v_754 = ((int64_t)((*({ hrv *_t1030 = &(g373); int64_t _i1030 = i_753; (int32_t*)_t1030->b + hr_ix(_i1030, _t1030->n, "hc/check.amni:56"); })))); 
if ((((((int64_t)(((*({ hrv *_t1031 = &(g372); int64_t _i1031 = v_754; (S12*)_t1031->b + hr_ix(_i1031, _t1031->n, "hc/check.amni:56"); }))).name_))) == (name_752)) && f167_visible(((int64_t)(((*({ hrv *_t1032 = &(g372); int64_t _i1032 = v_754; (S12*)_t1032->b + hr_ix(_i1032, _t1032->n, "hc/check.amni:56"); }))).own_))))) { return v_754;
 }
i_753--;
 } _bk1029:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f167_visible(int64_t own_755) {
int64_t i_756 = g382; 
while (((i_756) >= (((int64_t)0LL)))) { if (((i_756) == (own_755))) { return true;
 }
i_756 = ((int64_t)(((*({ hrv *_t1034 = &(g371); int64_t _i1034 = i_756; (S6*)_t1034->b + hr_ix(_i1034, _t1034->n, "hc/check.amni:53"); }))).par_));
 } _bk1033:; 
return false;
}
static void f168_set_r(int64_t n_758, int64_t k_759, int64_t v_760) {
int64_t i_761 = f138_aix(n_758); 
(*({ hrv *_t1035 = &(g378); int64_t _i1035 = i_761; (uint8_t*)_t1035->b + hr_ix(_i1035, _t1035->n, "hc/check.amni:40"); })) = ((uint8_t)(k_759));
(*({ hrv *_t1036 = &(g379); int64_t _i1036 = i_761; (int32_t*)_t1036->b + hr_ix(_i1036, _t1036->n, "hc/check.amni:40"); })) = ((int32_t)(v_760));
}
static void f169_note_cap(int64_t v_762) {
int64_t c_763 = ((int64_t)(((*({ hrv *_t1037 = &(g372); int64_t _i1037 = v_762; (S12*)_t1037->b + hr_ix(_i1037, _t1037->n, "hc/check.amni:60"); }))).cfn_)); 
if (((c_763) == (g383))) { return;
 }
{ hrv *_v1039 = &(g374); for (int64_t _k1039 = 0; _k1039 < _v1039->n; _k1039++) { S13 x_764 = ((S13*)_v1039->b)[_k1039]; if ((((((int64_t)((x_764).inst_))) == (g383)) && ((((int64_t)((x_764).lv_))) == (v_762)))) { return;
 }
 } } _bk1038:; 
(void)(({ hrv *_v1040 = &(g374); S13 _x1040 = ((S13){ .inst_ = ((int32_t)(g383)), .lv_ = ((int32_t)(v_762)), }); S13 *_p1040 = (S13*)hr_grow(_v1040, 1, sizeof _x1040); *_p1040 = _x1040; _p1040; }));
}
static int64_t f170_const_of(int64_t d_768) {
{ hrv *_v1042 = &(g413); for (int64_t _k1042 = 0; _k1042 < _v1042->n; _k1042++) { int32_t c_769 = ((int32_t*)_v1042->b)[_k1042]; int64_t i_770 = _k1042; if (((((int64_t)(c_769))) == (d_768))) { return i_770;
 }
 } } _bk1041:; 
int64_t g_771 = ((int64_t)(((*({ hrv *_t1043 = &(g464); int64_t _i1043 = d_768; (S5*)_t1043->b + hr_ix(_i1043, _t1043->n, "hc/check.amni:301"); }))).node_)); 
S4 x_772 = (*({ hrv *_t1044 = &(g675); int64_t _i1044 = g_771; (S4*)_t1044->b + hr_ix(_i1044, _t1044->n, "hc/check.amni:302"); })); 
if (((((((uint16_t)((uint64_t)(x_772).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || (((x_772).a_) >= (((int32_t)0LL)))) || (((x_772).b_) < (((int32_t)0LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t iv_773 = f90_kid(((int64_t)((x_772).b_)), ((int64_t)0LL)); 
M55 _t1045 = f118_ceval(iv_773, f110_ns_of(g_771)); int64_t v_774 = _t1045.r0; bool ok_775 = _t1045.r1; 
if ((!(ok_775))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if ((!(f171_all_int(iv_773)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
(void)(({ hrv *_v1046 = &(g413); int32_t _x1046 = ((int32_t)(d_768)); int32_t *_p1046 = (int32_t*)hr_grow(_v1046, 1, sizeof _x1046); *_p1046 = _x1046; _p1046; }));
(void)(({ hrv *_v1047 = &(g412); int64_t _x1047 = v_774; int64_t *_p1047 = (int64_t*)hr_grow(_v1047, 1, sizeof _x1047); *_p1047 = _x1047; _p1047; }));
return ((int64_t)((int64_t)(g413).n - (int64_t)((int64_t)1LL)));
}
static bool f171_all_int(int64_t n_776) {
S4 x_777 = (*({ hrv *_t1048 = &(g675); int64_t _i1048 = n_776; (S4*)_t1048->b + hr_ix(_i1048, _t1048->n, "hc/check.amni:312"); })); 
int64_t k_778 = ((int64_t)((x_777).k_)); 
if (((k_778) == (((int64_t)1LL)))) { return true;
 }
if (((k_778) == (((int64_t)10LL)))) { return f171_all_int(((int64_t)((x_777).a_)));
 }
if (((k_778) == (((int64_t)9LL)))) { return (f171_all_int(((int64_t)((x_777).a_))) && f171_all_int(((int64_t)((x_777).b_))));
 }
if (((k_778) == (((int64_t)8LL)))) { int64_t d_779 = f119_lookup_q(((int64_t)((x_777).s_)), f110_ns_of(n_776), ((int64_t)5LL)); 
if (((d_779) < (((int64_t)0LL)))) { return false;
 }
return ((f170_const_of(d_779)) >= (((int64_t)0LL)));
 }
if (((k_778) == (((int64_t)14LL)))) { return hr_streq(f10_nm(((int64_t)((x_777).s_))), hr_str("len", 3));
 }
return false;
}
static void f172_set_x(int64_t n_781, int64_t v_782) {
(*({ hrv *_t1049 = &(g380); int64_t _i1049 = f138_aix(n_781); (int32_t*)_t1049->b + hr_ix(_i1049, _t1049->n, "hc/check.amni:43"); })) = ((int32_t)(v_782));
}
static int64_t f173_ck_bin(int64_t n_784, int64_t want_785) {
S4 x_786 = (*({ hrv *_t1050 = &(g675); int64_t _i1050 = n_784; (S4*)_t1050->b + hr_ix(_i1050, _t1050->n, "hc/check.amni:224"); })); 
int64_t o_787 = ((int64_t)((x_786).op_)); 
int64_t a_788 = ((int64_t)((x_786).a_)); 
int64_t b_789 = ((int64_t)((x_786).b_)); 
if ((((o_787) == (((int64_t)52LL))) || ((o_787) == (((int64_t)53LL))))) { (void)(f136_ck(a_788, g532));
(void)(f139_conv(a_788, g532));
(void)(f136_ck(b_789, g532));
(void)(f139_conv(b_789, g532));
return f137_set_t(n_784, g532);
 }
if ((((o_787) == (((int64_t)19LL))) || ((o_787) == (((int64_t)20LL))))) { (void)(f136_ck(a_788, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
(void)(f136_ck(b_789, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f137_set_t(n_784, g532);
 }
bool cmp_790 = (((((((o_787) == (((int64_t)37LL))) || ((o_787) == (((int64_t)38LL)))) || ((o_787) == (((int64_t)39LL)))) || ((o_787) == (((int64_t)40LL)))) || ((o_787) == (((int64_t)41LL)))) || ((o_787) == (((int64_t)42LL)))); 
int64_t w_791 = ({ int64_t _r1051; if (cmp_790) { _r1051 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1051 = want_785;  } _r1051; }); 
int64_t ta_792 = f136_ck(a_788, w_791); 
int64_t tb_794 = f136_ck(b_789, ({ int64_t _r1052; if (f162_is_pending(ta_792)) { _r1052 = w_791;  } else { _r1052 = f174_deref(ta_792);  } _r1052; })); 
if ((((o_787) == (((int64_t)43LL))) || ((o_787) == (((int64_t)44LL))))) { if (((((*({ hrv *_t1053 = &(g524); int64_t _i1053 = tb_794; (S1*)_t1053->b + hr_ix(_i1053, _t1053->n, "hc/check.amni:233"); }))).k_) == (((uint8_t)12LL)))) { (void)(f139_conv(b_789, g536));
 } else { if (((((*({ hrv *_t1054 = &(g524); int64_t _i1054 = f174_deref(tb_794); (S1*)_t1054->b + hr_ix(_i1054, _t1054->n, "hc/check.amni:233"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(b_789, hr_str("shift count must be an integer", 30)));
 }
 }
int64_t da_795 = f174_deref(ta_792); 
if (((((*({ hrv *_t1055 = &(g524); int64_t _i1055 = da_795; (S1*)_t1055->b + hr_ix(_i1055, _t1055->n, "hc/check.amni:235"); }))).k_) == (((uint8_t)12LL)))) { if ((((want_785) >= (((int64_t)0LL))) && ((((*({ hrv *_t1056 = &(g524); int64_t _i1056 = want_785; (S1*)_t1056->b + hr_ix(_i1056, _t1056->n, "hc/check.amni:235"); }))).k_) == (((uint8_t)3LL))))) { (void)(f139_conv(a_788, want_785));
return f137_set_t(n_784, want_785);
 }
return f137_set_t(n_784, g544);
 }
if (((((*({ hrv *_t1057 = &(g524); int64_t _i1057 = da_795; (S1*)_t1057->b + hr_ix(_i1057, _t1057->n, "hc/check.amni:236"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(a_788, hr_str("shift of a non-integer", 22)));
 }
if (((ta_792) != (da_795))) { (void)(f148_set_cv(a_788, da_795));
 }
return f137_set_t(n_784, da_795);
 }
int64_t da_796 = f174_deref(ta_792); 
int64_t db_797 = f174_deref(tb_794); 
int64_t la_806 = f175_leaf_kind(da_796); 
int64_t lb_807 = f175_leaf_kind(db_797); 
if (((((la_806) >= (((int64_t)4LL))) || ((lb_807) >= (((int64_t)4LL)))) && (!(cmp_790)))) { if (((da_796) == (db_797))) { if (((ta_792) != (da_796))) { (void)(f148_set_cv(a_788, da_796));
 }
if (((tb_794) != (db_797))) { (void)(f148_set_cv(b_789, db_797));
 }
return f137_set_t(n_784, da_796);
 }
if ((((la_806) >= (((int64_t)4LL))) && (((o_787) == (((int64_t)23LL))) || ((o_787) == (((int64_t)24LL)))))) { (void)(f139_conv(b_789, f176_leaf_type(da_796)));
if (((ta_792) != (da_796))) { (void)(f148_set_cv(a_788, da_796));
 }
return f137_set_t(n_784, da_796);
 }
if ((((lb_807) >= (((int64_t)4LL))) && ((o_787) == (((int64_t)23LL))))) { (void)(f139_conv(a_788, f176_leaf_type(db_797)));
if (((tb_794) != (db_797))) { (void)(f148_set_cv(b_789, db_797));
 }
return f137_set_t(n_784, db_797);
 }
if ((((lb_807) >= (((int64_t)4LL))) && ((o_787) == (((int64_t)24LL))))) { (void)(f139_conv(a_788, f176_leaf_type(db_797)));
if (((tb_794) != (db_797))) { (void)(f148_set_cv(b_789, db_797));
 }
return f137_set_t(n_784, db_797);
 }
 }
if ((((((cmp_790 && (((((*({ hrv *_t1058 = &(g524); int64_t _i1058 = da_796; (S1*)_t1058->b + hr_ix(_i1058, _t1058->n, "hc/check.amni:248"); }))).k_) == (((uint8_t)3LL))) && ((((*({ hrv *_t1059 = &(g524); int64_t _i1059 = db_797; (S1*)_t1059->b + hr_ix(_i1059, _t1059->n, "hc/check.amni:248"); }))).k_) == (((uint8_t)3LL))))) && ((f151_is_signed(da_796)) != (f151_is_signed(db_797)))) && (((f152_ibits(da_796)) == (((int64_t)64LL))) || ((f152_ibits(db_797)) == (((int64_t)64LL))))) && (!(f150_widens(da_796, db_797)))) && (!(f150_widens(db_797, da_796))))) { (void)(f172_set_x(n_784, ((int64_t)1LL)));
return f137_set_t(n_784, g532);
 }
if ((cmp_790 && (((o_787) == (((int64_t)37LL))) || ((o_787) == (((int64_t)38LL)))))) { int64_t ka_815 = ((int64_t)(((*({ hrv *_t1060 = &(g524); int64_t _i1060 = da_796; (S1*)_t1060->b + hr_ix(_i1060, _t1060->n, "hc/check.amni:253"); }))).k_)); 
int64_t kb_816 = ((int64_t)(((*({ hrv *_t1061 = &(g524); int64_t _i1061 = db_797; (S1*)_t1061->b + hr_ix(_i1061, _t1061->n, "hc/check.amni:253"); }))).k_)); 
if ((((ka_815) == (((int64_t)11LL))) || ((kb_816) == (((int64_t)11LL))))) { if ((((ka_815) == (((int64_t)11LL))) && ((kb_816) == (((int64_t)11LL))))) { return f137_set_t(n_784, g532);
 }
if (((ka_815) == (((int64_t)11LL)))) { (void)(f137_set_t(a_788, tb_794));
 } else { (void)(f137_set_t(b_789, ta_792));
 }
return f137_set_t(n_784, g532);
 }
if (((((ka_815) == (((int64_t)18LL))) || ((kb_816) == (((int64_t)18LL)))) || (f163_is_byte_arr(da_796) && f163_is_byte_arr(db_797)))) { if (((ka_815) == (((int64_t)18LL)))) { (void)(f137_set_t(a_788, g549));
 }
if (((kb_816) == (((int64_t)18LL)))) { (void)(f137_set_t(b_789, g549));
 }
(void)(f172_set_x(n_784, ((int64_t)2LL)));
return f137_set_t(n_784, g532);
 }
if ((((((((ka_815) == (((int64_t)5LL))) || ((ka_815) == (((int64_t)8LL)))) || ((ka_815) == (((int64_t)6LL)))) || ((ka_815) == (((int64_t)7LL)))) || ((ka_815) == (((int64_t)9LL)))) && ((da_796) == (db_797)))) { (void)(f172_set_x(n_784, ((int64_t)3LL)));
return f137_set_t(n_784, g532);
 }
if (((((ka_815) == (((int64_t)6LL))) && ((kb_816) == (((int64_t)7LL)))) || (((ka_815) == (((int64_t)7LL))) && ((kb_816) == (((int64_t)6LL)))))) { (void)(f172_set_x(n_784, ((int64_t)3LL)));
return f137_set_t(n_784, g532);
 }
if ((((ka_815) == (((int64_t)19LL))) || ((kb_816) == (((int64_t)19LL))))) { if (((ka_815) == (((int64_t)19LL)))) { (void)(f139_conv(a_788, db_797));
 } else { (void)(f139_conv(b_789, da_796));
 }
(void)(f172_set_x(n_784, ((int64_t)3LL)));
return f137_set_t(n_784, g532);
 }
 }
int64_t u_827 = f177_unify(n_784, a_788, b_789); 
if (cmp_790) { if (((((*({ hrv *_t1062 = &(g524); int64_t _i1062 = u_827; (S1*)_t1062->b + hr_ix(_i1062, _t1062->n, "hc/check.amni:261"); }))).k_) == (((uint8_t)12LL)))) { (void)(f139_conv(a_788, g536));
(void)(f139_conv(b_789, g536));
 }
if (((((*({ hrv *_t1063 = &(g524); int64_t _i1063 = u_827; (S1*)_t1063->b + hr_ix(_i1063, _t1063->n, "hc/check.amni:261"); }))).k_) == (((uint8_t)13LL)))) { (void)(f139_conv(a_788, g542));
(void)(f139_conv(b_789, g542));
 }
return f137_set_t(n_784, g532);
 }
int64_t uk_828 = ((int64_t)(((*({ hrv *_t1064 = &(g524); int64_t _i1064 = u_827; (S1*)_t1064->b + hr_ix(_i1064, _t1064->n, "hc/check.amni:262"); }))).k_)); 
if (((((((((o_787) == (((int64_t)49LL))) || ((o_787) == (((int64_t)50LL)))) || ((o_787) == (((int64_t)51LL)))) && ((uk_828) != (((int64_t)3LL)))) && ((uk_828) != (((int64_t)12LL)))) && ((uk_828) != (((int64_t)2LL)))) && ((uk_828) != (((int64_t)0LL))))) { (void)(f108_cerr(n_784, hr_str("bitwise operator on a non-integer", 33)));
 }
if ((((((uk_828) == (((int64_t)2LL))) && ((o_787) != (((int64_t)49LL)))) && ((o_787) != (((int64_t)50LL)))) && ((o_787) != (((int64_t)51LL))))) { (void)(f108_cerr(n_784, hr_str("arithmetic on bool", 18)));
 }
return f137_set_t(n_784, u_827);
}
static int64_t f174_deref(int64_t t_793) {
return ({ int64_t _r1065; if ((((((*({ hrv *_t1066 = &(g524); int64_t _i1066 = t_793; (S1*)_t1066->b + hr_ix(_i1066, _t1066->n, "hc/types.amni:67"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t1067 = &(g524); int64_t _i1067 = t_793; (S1*)_t1067->b + hr_ix(_i1067, _t1067->n, "hc/types.amni:67"); }))).c_) < (((int32_t)0LL))))) { _r1065 = ((int64_t)(((*({ hrv *_t1068 = &(g524); int64_t _i1068 = t_793; (S1*)_t1068->b + hr_ix(_i1068, _t1068->n, "hc/types.amni:67"); }))).a_));  } else { _r1065 = t_793;  } _r1065; });
}
static int64_t f175_leaf_kind(int64_t t_798) {
S1 x_799 = (*({ hrv *_t1069 = &(g524); int64_t _i1069 = t_798; (S1*)_t1069->b + hr_ix(_i1069, _t1069->n, "hc/check.amni:210"); })); 
int64_t k_800 = ((int64_t)((x_799).k_)); 
if (((k_800) == (((int64_t)3LL)))) { return ((int64_t)1LL);
 }
if (((k_800) == (((int64_t)4LL)))) { return ((int64_t)2LL);
 }
if (((k_800) == (((int64_t)5LL)))) { int64_t r_801 = ((int64_t)0LL); 
{ int32_t _e1071 = ((*({ hrv *_t1072 = &(g527); int64_t _i1072 = (x_799).a_; (S10*)_t1072->b + hr_ix(_i1072, _t1072->n, "hc/check.amni:212"); }))).fnum_; for (int32_t i_802 = 0; i_802 < _e1071; i_802++) { S11 f_803 = (*({ hrv *_t1073 = &(g528); int64_t _i1073 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1074 = &(g527); int64_t _i1074 = (x_799).a_; (S10*)_t1074->b + hr_ix(_i1074, _t1074->n, "hc/check.amni:212"); }))).f0_)) + (int64_t)((int64_t)(i_802)))); (S11*)_t1073->b + hr_ix(_i1073, _t1073->n, "hc/check.amni:212"); })); 
if ((((f_803).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t l_804 = f175_leaf_kind(((int64_t)((f_803).ty_))); 
if ((((l_804) == (((int64_t)0LL))) || (((r_801) != (((int64_t)0LL))) && ((r_801) != (l_804))))) { return ((int64_t)0LL);
 }
r_801 = l_804;
 } } _bk1070:; 
return ((int64_t)((int64_t)r_801 + (int64_t)((int64_t)4LL)));
 }
if ((((k_800) == (((int64_t)8LL))) && (((x_799).s_) == (((uint8_t)(((uint8_t)1LL))))))) { int64_t l_805 = f175_leaf_kind(((int64_t)((x_799).a_))); 
if (((l_805) == (((int64_t)0LL)))) { return ((int64_t)0LL);
 }
return ((int64_t)((int64_t)((int64_t)((int64_t)l_805 & (int64_t)((int64_t)3LL))) + (int64_t)((int64_t)4LL)));
 }
return ((int64_t)0LL);
}
static int64_t f176_leaf_type(int64_t t_808) {
S1 x_809 = (*({ hrv *_t1075 = &(g524); int64_t _i1075 = t_808; (S1*)_t1075->b + hr_ix(_i1075, _t1075->n, "hc/check.amni:217"); })); 
int64_t k_810 = ((int64_t)((x_809).k_)); 
if ((((k_810) == (((int64_t)3LL))) || ((k_810) == (((int64_t)4LL))))) { return t_808;
 }
if (((k_810) == (((int64_t)5LL)))) { int64_t r_811 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e1077 = ((*({ hrv *_t1078 = &(g527); int64_t _i1078 = (x_809).a_; (S10*)_t1078->b + hr_ix(_i1078, _t1078->n, "hc/check.amni:219"); }))).fnum_; for (int32_t i_812 = 0; i_812 < _e1077; i_812++) { S11 f_813 = (*({ hrv *_t1079 = &(g528); int64_t _i1079 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1080 = &(g527); int64_t _i1080 = (x_809).a_; (S10*)_t1080->b + hr_ix(_i1080, _t1080->n, "hc/check.amni:219"); }))).f0_)) + (int64_t)((int64_t)(i_812)))); (S11*)_t1079->b + hr_ix(_i1079, _t1079->n, "hc/check.amni:219"); })); 
if ((((f_813).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t l_814 = f176_leaf_type(((int64_t)((f_813).ty_))); 
if ((((l_814) < (((int64_t)0LL))) || (((r_811) >= (((int64_t)0LL))) && ((r_811) != (l_814))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
r_811 = l_814;
 } } _bk1076:; 
return r_811;
 }
if ((((k_810) == (((int64_t)8LL))) && (((x_809).s_) == (((uint8_t)(((uint8_t)1LL))))))) { return f176_leaf_type(((int64_t)((x_809).a_)));
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f177_unify(int64_t n_817, int64_t a_818, int64_t b_819) {
int64_t ta_820 = f140_at(a_818); 
int64_t tb_821 = f140_at(b_819); 
if ((((ta_820) < (((int64_t)0LL))) || ((tb_821) < (((int64_t)0LL))))) { return g548;
 }
int64_t da_822 = f174_deref(ta_820); 
int64_t db_823 = f174_deref(tb_821); 
int64_t ka_824 = ((int64_t)(((*({ hrv *_t1081 = &(g524); int64_t _i1081 = da_822; (S1*)_t1081->b + hr_ix(_i1081, _t1081->n, "hc/check.amni:189"); }))).k_)); 
int64_t kb_825 = ((int64_t)(((*({ hrv *_t1082 = &(g524); int64_t _i1082 = db_823; (S1*)_t1082->b + hr_ix(_i1082, _t1082->n, "hc/check.amni:189"); }))).k_)); 
if ((((ka_824) == (((int64_t)0LL))) || ((kb_825) == (((int64_t)0LL))))) { return g548;
 }
if ((((ka_824) == (((int64_t)12LL))) && ((kb_825) == (((int64_t)12LL))))) { return g544;
 }
if (((((ka_824) == (((int64_t)12LL))) || ((ka_824) == (((int64_t)13LL)))) && ((kb_825) == (((int64_t)13LL))))) { return g545;
 }
if ((((ka_824) == (((int64_t)13LL))) && ((kb_825) == (((int64_t)12LL))))) { return g545;
 }
if ((((ka_824) == (((int64_t)18LL))) && ((kb_825) == (((int64_t)18LL))))) { (void)(f137_set_t(a_818, g549));
(void)(f137_set_t(b_819, g549));
return g549;
 }
if (((((ka_824) == (((int64_t)18LL))) || ((ka_824) == (((int64_t)19LL)))) || ((ka_824) == (((int64_t)11LL))))) { (void)(f139_conv(a_818, db_823));
return db_823;
 }
if (((((kb_825) == (((int64_t)18LL))) || ((kb_825) == (((int64_t)19LL)))) || ((kb_825) == (((int64_t)11LL))))) { (void)(f139_conv(b_819, da_822));
return da_822;
 }
if (((ka_824) == (((int64_t)12LL)))) { (void)(f139_conv(a_818, db_823));
return db_823;
 }
if (((kb_825) == (((int64_t)12LL)))) { (void)(f139_conv(b_819, da_822));
return da_822;
 }
if (((ka_824) == (((int64_t)13LL)))) { if (((kb_825) == (((int64_t)4LL)))) { (void)(f139_conv(a_818, db_823));
return db_823;
 }
if (((kb_825) == (((int64_t)3LL)))) { return g545;
 }
 }
if (((kb_825) == (((int64_t)13LL)))) { if (((ka_824) == (((int64_t)4LL)))) { (void)(f139_conv(b_819, da_822));
return da_822;
 }
if (((ka_824) == (((int64_t)3LL)))) { return g545;
 }
 }
if (((da_822) == (db_823))) { if (((ta_820) != (da_822))) { (void)(f148_set_cv(a_818, da_822));
 }
if (((tb_821) != (db_823))) { (void)(f148_set_cv(b_819, db_823));
 }
return da_822;
 }
if ((f150_widens(da_822, db_823) && (!((((ka_824) == (((int64_t)4LL))) && ((kb_825) == (((int64_t)3LL)))))))) { (void)(f148_set_cv(a_818, db_823));
if (((tb_821) != (db_823))) { (void)(f148_set_cv(b_819, db_823));
 }
return db_823;
 }
if ((f150_widens(db_823, da_822) && (!((((kb_825) == (((int64_t)4LL))) && ((ka_824) == (((int64_t)3LL)))))))) { (void)(f148_set_cv(b_819, da_822));
if (((ta_820) != (da_822))) { (void)(f148_set_cv(a_818, da_822));
 }
return da_822;
 }
if ((((ka_824) == (((int64_t)3LL))) && ((kb_825) == (((int64_t)4LL))))) { (void)(f148_set_cv(a_818, db_823));
return db_823;
 }
if ((((kb_825) == (((int64_t)3LL))) && ((ka_824) == (((int64_t)4LL))))) { (void)(f148_set_cv(b_819, da_822));
return da_822;
 }
hrv m_826 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1085 __attribute__((cleanup(hr_rdrop))) = {0}; hrv _t1086 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1084 = &(m_826); hr_fs(_o1084, hr_str("operands of types ", 18)); hr_fs(_o1084, hr_sl(*hr_tmp(&_t1085, f160_tn(da_822)))); hr_fs(_o1084, hr_str(" and ", 5)); hr_fs(_o1084, hr_sl(*hr_tmp(&_t1086, f160_tn(db_823)))); hr_fs(_o1084, hr_str(" need a cast to a common type", 29)); }));
}
(void)(f108_cerr(n_817, hr_sl(m_826)));
return g548;
}
static int64_t f178_ck_un(int64_t n_830, int64_t want_831) {
S4 x_832 = (*({ hrv *_t1087 = &(g675); int64_t _i1087 = n_830; (S4*)_t1087->b + hr_ix(_i1087, _t1087->n, "hc/check.amni:268"); })); 
int64_t o_833 = ((int64_t)((x_832).op_)); 
int64_t a_834 = ((int64_t)((x_832).a_)); 
if (((o_833) == (((int64_t)47LL)))) { (void)(f136_ck(a_834, g532));
(void)(f139_conv(a_834, g532));
return f137_set_t(n_830, g532);
 }
if (((o_833) == (((int64_t)49LL)))) { int64_t t_835 = f136_ck(a_834, ({ int64_t _r1088; if ((((want_831) >= (((int64_t)0LL))) && ((((*({ hrv *_t1089 = &(g524); int64_t _i1089 = want_831; (S1*)_t1089->b + hr_ix(_i1089, _t1089->n, "hc/check.amni:271"); }))).k_) == (((uint8_t)10LL))))) { _r1088 = ((int64_t)(((*({ hrv *_t1090 = &(g524); int64_t _i1090 = want_831; (S1*)_t1090->b + hr_ix(_i1090, _t1090->n, "hc/check.amni:271"); }))).a_));  } else { _r1088 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1088; })); 
if (f162_is_pending(t_835)) { (void)(f179_default_t(a_834));
 }
(void)(f172_set_x(n_830, ((int64_t)1LL)));
return f137_set_t(n_830, f140_at(a_834));
 }
int64_t t_854 = f136_ck(a_834, want_831); 
int64_t d_855 = f174_deref(t_854); 
if (((t_854) != (d_855))) { (void)(f148_set_cv(a_834, d_855));
 }
if (((((o_833) == (((int64_t)22LL))) && ((((*({ hrv *_t1091 = &(g524); int64_t _i1091 = d_855; (S1*)_t1091->b + hr_ix(_i1091, _t1091->n, "hc/check.amni:275"); }))).k_) == (((uint8_t)3LL)))) && (!(f151_is_signed(d_855))))) { (void)(f108_cerr(n_830, hr_str("unary - of an unsigned integer", 30)));
 }
return f137_set_t(n_830, d_855);
}
static int64_t f179_default_t(int64_t n_836) {
int64_t t_837 = f140_at(n_836); 
if (((t_837) < (((int64_t)0LL)))) { return g531;
 }
int64_t k_838 = ((int64_t)(((*({ hrv *_t1092 = &(g524); int64_t _i1092 = t_837; (S1*)_t1092->b + hr_ix(_i1092, _t1092->n, "hc/check.amni:167"); }))).k_)); 
if (((k_838) == (((int64_t)12LL)))) { M77 _t1093 = f154_cval(n_836); int64_t v_839 = _t1093.r0; bool u_840 = _t1093.r1; bool ok_841 = _t1093.r2; 
int64_t d_842 = ({ int64_t _r1094; if ((ok_841 && u_840)) { _r1094 = g540;  } else { _r1094 = g536;  } _r1094; }); 
(void)(f161_commit(n_836, d_842));
return d_842;
 }
if (((k_838) == (((int64_t)13LL)))) { (void)(f161_commit(n_836, g542));
return g542;
 }
if (((k_838) == (((int64_t)18LL)))) { (void)(f137_set_t(n_836, g549));
return g549;
 }
if (((k_838) == (((int64_t)19LL)))) { S4 x_843 = (*({ hrv *_t1095 = &(g675); int64_t _i1095 = n_836; (S4*)_t1095->b + hr_ix(_i1095, _t1095->n, "hc/check.amni:172"); })); 
int64_t e_844 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((x_843).a_) >= (((int32_t)0LL)))) { e_844 = f179_default_t(((int64_t)((x_843).a_)));
M77 _t1096 = f154_cval(((int64_t)((x_843).b_))); int64_t cnt_845 = _t1096.r0; bool u0_846 = _t1096.r1; bool ok_847 = _t1096.r2; 
(void)(f139_conv(((int64_t)((x_843).b_)), g536));
int64_t a_848 = f121_t_arr(e_844, ((int64_t)1LL), cnt_845, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f137_set_t(n_836, a_848));
return a_848;
 }
{ int32_t _e1098 = (x_843).n_; for (int32_t i_849 = 0; i_849 < _e1098; i_849++) { int64_t c_850 = f90_kid(n_836, ((int64_t)(i_849))); 
int64_t ct_851 = f140_at(c_850); 
if ((!(f162_is_pending(ct_851)))) { e_844 = ct_851;
 }
 } } _bk1097:; 
if ((((e_844) < (((int64_t)0LL))) && (((x_843).n_) > (((int32_t)0LL))))) { e_844 = f179_default_t(f90_kid(n_836, ((int64_t)0LL)));
 }
if (((e_844) < (((int64_t)0LL)))) { (void)(f108_cerr(n_836, hr_str("an empty [] has no element type here", 36)));
return g548;
 }
{ int32_t _e1100 = (x_843).n_; for (int32_t i_852 = 0; i_852 < _e1100; i_852++) { (void)(f139_conv(f90_kid(n_836, ((int64_t)(i_852))), e_844));
 } } _bk1099:; 
int64_t a_853 = f121_t_arr(e_844, ((int64_t)1LL), ((int64_t)((x_843).n_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f137_set_t(n_836, a_853));
return a_853;
 }
return t_837;
}
static int64_t f180_ck_dot(int64_t n_857, int64_t want_858) {
S4 x_859 = (*({ hrv *_t1101 = &(g675); int64_t _i1101 = n_857; (S4*)_t1101->b + hr_ix(_i1101, _t1101->n, "hc/check.amni:345"); })); 
int64_t a_860 = ((int64_t)((x_859).a_)); 
int64_t name_861 = ((int64_t)((x_859).s_)); 
if ((((((*({ hrv *_t1102 = &(g675); int64_t _i1102 = a_860; (S4*)_t1102->b + hr_ix(_i1102, _t1102->n, "hc/check.amni:348"); }))).k_) == (((uint8_t)8LL))) && ((f166_find_lv(((int64_t)(((*({ hrv *_t1103 = &(g675); int64_t _i1103 = a_860; (S4*)_t1103->b + hr_ix(_i1103, _t1103->n, "hc/check.amni:348"); }))).s_)))) < (((int64_t)0LL))))) { int64_t ns_862 = f110_ns_of(a_860); 
int64_t de_863 = f119_lookup_q(((int64_t)(((*({ hrv *_t1104 = &(g675); int64_t _i1104 = a_860; (S4*)_t1104->b + hr_ix(_i1104, _t1104->n, "hc/check.amni:350"); }))).s_)), ns_862, ((int64_t)2LL)); 
if ((((de_863) >= (((int64_t)0LL))) && ((f119_lookup_q(((int64_t)(((*({ hrv *_t1105 = &(g675); int64_t _i1105 = a_860; (S4*)_t1105->b + hr_ix(_i1105, _t1105->n, "hc/check.amni:351"); }))).s_)), ns_862, ((int64_t)5LL))) < (((int64_t)0LL))))) { int64_t et_867 = f181_rtype_name_enum(de_863); 
int64_t ei_868 = ((int64_t)(((*({ hrv *_t1106 = &(g524); int64_t _i1106 = et_867; (S1*)_t1106->b + hr_ix(_i1106, _t1106->n, "hc/check.amni:353"); }))).a_)); 
{ int32_t _e1108 = ((*({ hrv *_t1109 = &(g529); int64_t _i1109 = ei_868; (S8*)_t1109->b + hr_ix(_i1109, _t1109->n, "hc/check.amni:354"); }))).vnum_; for (int32_t i_869 = 0; i_869 < _e1108; i_869++) { if (((((int64_t)(((*({ hrv *_t1110 = &(g530); int64_t _i1110 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1111 = &(g529); int64_t _i1111 = ei_868; (S8*)_t1111->b + hr_ix(_i1111, _t1111->n, "hc/check.amni:354"); }))).v0_)) + (int64_t)((int64_t)(i_869)))); (S9*)_t1110->b + hr_ix(_i1110, _t1110->n, "hc/check.amni:354"); }))).name_))) == (name_861))) { (void)(f168_set_r(n_857, ((int64_t)7LL), ((int64_t)(i_869))));
return f137_set_t(n_857, et_867);
 }
 } } _bk1107:; 
hrv m_870 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1114 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1113 = &(m_870); hr_fs(_o1113, hr_str("no variant ", 11)); hr_fs(_o1113, f10_nm(name_861)); hr_fs(_o1113, hr_str(" in ", 4)); hr_fs(_o1113, hr_sl(*hr_tmp(&_t1114, f160_tn(et_867)))); }));
}
(void)(f108_cerr(n_857, hr_sl(m_870)));
return f137_set_t(n_857, g548);
 }
 }
int64_t t0_871 = f136_ck(a_860, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t t_872 = t0_871; 
if (((((*({ hrv *_t1115 = &(g524); int64_t _i1115 = t_872; (S1*)_t1115->b + hr_ix(_i1115, _t1115->n, "hc/check.amni:360"); }))).k_) == (((uint8_t)18LL)))) { t_872 = g549;
(void)(f137_set_t(a_860, g549));
 }
if (((((*({ hrv *_t1116 = &(g524); int64_t _i1116 = t_872; (S1*)_t1116->b + hr_ix(_i1116, _t1116->n, "hc/check.amni:361"); }))).k_) == (((uint8_t)19LL)))) { t_872 = f179_default_t(a_860);
 }
int64_t d_873 = f174_deref(t_872); 
int64_t k_874 = ((int64_t)(((*({ hrv *_t1117 = &(g524); int64_t _i1117 = d_873; (S1*)_t1117->b + hr_ix(_i1117, _t1117->n, "hc/check.amni:363"); }))).k_)); 
if (((((k_874) == (((int64_t)8LL))) || ((k_874) == (((int64_t)9LL)))) && hr_streq(f10_nm(name_861), hr_str("len", 3)))) { (void)(f168_set_r(n_857, ((int64_t)8LL), ((int64_t)1LL)));
return f137_set_t(n_857, g536);
 }
if ((((k_874) == (((int64_t)8LL))) && hr_streq(f10_nm(name_861), hr_str("cap", 3)))) { (void)(f168_set_r(n_857, ((int64_t)8LL), ((int64_t)2LL)));
return f137_set_t(n_857, g536);
 }
if (((k_874) == (((int64_t)5LL)))) { int64_t si_875 = ((int64_t)(((*({ hrv *_t1118 = &(g524); int64_t _i1118 = d_873; (S1*)_t1118->b + hr_ix(_i1118, _t1118->n, "hc/check.amni:367"); }))).a_)); 
int64_t fi_879 = f182_sfield(si_875, name_861); 
if (((fi_879) >= (((int64_t)0LL)))) { (void)(f168_set_r(n_857, ((int64_t)5LL), fi_879));
int64_t ft_880 = ((int64_t)(((*({ hrv *_t1119 = &(g528); int64_t _i1119 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1120 = &(g527); int64_t _i1120 = si_875; (S10*)_t1120->b + hr_ix(_i1120, _t1120->n, "hc/check.amni:369"); }))).f0_)) + (int64_t)fi_879)); (S11*)_t1119->b + hr_ix(_i1119, _t1119->n, "hc/check.amni:369"); }))).ty_)); 
return f137_set_t(n_857, ft_880);
 }
 }
if (((k_874) == (((int64_t)7LL)))) { S9 v_881 = (*({ hrv *_t1121 = &(g530); int64_t _i1121 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1122 = &(g529); int64_t _i1122 = ((*({ hrv *_t1123 = &(g524); int64_t _i1123 = d_873; (S1*)_t1123->b + hr_ix(_i1123, _t1123->n, "hc/check.amni:372"); }))).a_; (S8*)_t1122->b + hr_ix(_i1122, _t1122->n, "hc/check.amni:372"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t1124 = &(g524); int64_t _i1124 = d_873; (S1*)_t1124->b + hr_ix(_i1124, _t1124->n, "hc/check.amni:372"); }))).c_)))); (S9*)_t1121->b + hr_ix(_i1121, _t1121->n, "hc/check.amni:372"); })); 
if ((((v_881).si_) >= (((int32_t)0LL)))) { int64_t fi_882 = f182_sfield(((int64_t)((v_881).si_)), name_861); 
if (((fi_882) >= (((int64_t)0LL)))) { (void)(f168_set_r(n_857, ((int64_t)5LL), fi_882));
(void)(f172_set_x(n_857, ((int64_t)((v_881).si_))));
return f137_set_t(n_857, ((int64_t)(((*({ hrv *_t1125 = &(g528); int64_t _i1125 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1126 = &(g527); int64_t _i1126 = (v_881).si_; (S10*)_t1126->b + hr_ix(_i1126, _t1126->n, "hc/check.amni:373"); }))).f0_)) + (int64_t)fi_882)); (S11*)_t1125->b + hr_ix(_i1125, _t1125->n, "hc/check.amni:373"); }))).ty_)));
 }
 }
 }
hrv m_883 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1129 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1128 = &(m_883); hr_fs(_o1128, hr_str("no field ", 9)); hr_fs(_o1128, f10_nm(name_861)); hr_fs(_o1128, hr_str(" in ", 4)); hr_fs(_o1128, hr_sl(*hr_tmp(&_t1129, f160_tn(d_873)))); }));
}
(void)(f108_cerr(n_857, hr_sl(m_883)));
return f137_set_t(n_857, g548);
}
static int64_t f181_rtype_name_enum(int64_t de_864) {
int64_t node_865 = ((int64_t)(((*({ hrv *_t1130 = &(g464); int64_t _i1130 = de_864; (S5*)_t1130->b + hr_ix(_i1130, _t1130->n, "hc/check.amni:378"); }))).node_)); 
L83 none_866 = ({ L83 _t1131; memset(&_t1131, 0, sizeof _t1131); _t1131.n = 0; _t1131; }); 
return f135_t_enum(f134_inst_enum(node_865, ({ hsl _t1132 = ({ L83 *_t1133 = &(none_866); (hsl){ (uint8_t*)_t1133->e, _t1133->n }; }); int64_t _l1132 = 0, _h1132 = _t1132.n; if (_l1132 < 0 || _h1132 < _l1132 || _h1132 > _t1132.n) hr_slerr(_l1132, _h1132, _t1132.n, "hc/check.amni:378"); (hsl){ _t1132.p + _l1132 * (int64_t)sizeof(int32_t), _h1132 - _l1132 }; })), false);
}
static int64_t f182_sfield(int64_t si_876, int64_t name_877) {
{ int32_t _e1135 = ((*({ hrv *_t1136 = &(g527); int64_t _i1136 = si_876; (S10*)_t1136->b + hr_ix(_i1136, _t1136->n, "hc/types.amni:159"); }))).fnum_; for (int32_t i_878 = 0; i_878 < _e1135; i_878++) { if (((((int64_t)(((*({ hrv *_t1137 = &(g528); int64_t _i1137 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1138 = &(g527); int64_t _i1138 = si_876; (S10*)_t1138->b + hr_ix(_i1138, _t1138->n, "hc/types.amni:159"); }))).f0_)) + (int64_t)((int64_t)(i_878)))); (S11*)_t1137->b + hr_ix(_i1137, _t1137->n, "hc/types.amni:159"); }))).name_))) == (name_877))) { return ((int64_t)(i_878));
 }
 } } _bk1134:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f183_ck_idx(int64_t n_884, int64_t want_885) {
S4 x_886 = (*({ hrv *_t1139 = &(g675); int64_t _i1139 = n_884; (S4*)_t1139->b + hr_ix(_i1139, _t1139->n, "hc/check.amni:380"); })); 
int64_t t_887 = f136_ck(((int64_t)((x_886).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t1140 = &(g524); int64_t _i1140 = t_887; (S1*)_t1140->b + hr_ix(_i1140, _t1140->n, "hc/check.amni:382"); }))).k_) == (((uint8_t)18LL)))) { (void)(f137_set_t(((int64_t)((x_886).a_)), g549));
t_887 = g549;
 }
if (((((*({ hrv *_t1141 = &(g524); int64_t _i1141 = t_887; (S1*)_t1141->b + hr_ix(_i1141, _t1141->n, "hc/check.amni:383"); }))).k_) == (((uint8_t)19LL)))) { t_887 = f179_default_t(((int64_t)((x_886).a_)));
 }
int64_t d_888 = f174_deref(t_887); 
int64_t ti_889 = f136_ck(((int64_t)((x_886).b_)), g536); 
if (((((*({ hrv *_t1142 = &(g524); int64_t _i1142 = ti_889; (S1*)_t1142->b + hr_ix(_i1142, _t1142->n, "hc/check.amni:386"); }))).k_) == (((uint8_t)12LL)))) { (void)(f139_conv(((int64_t)((x_886).b_)), g536));
 } else { int64_t di_890 = f174_deref(ti_889); 
if (((((*({ hrv *_t1143 = &(g524); int64_t _i1143 = di_890; (S1*)_t1143->b + hr_ix(_i1143, _t1143->n, "hc/check.amni:386"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(((int64_t)((x_886).b_)), hr_str("index must be an integer", 24)));
 } else { if (((di_890) != (ti_889))) { (void)(f148_set_cv(((int64_t)((x_886).b_)), di_890));
 }
 }
 }
int64_t k_891 = ((int64_t)(((*({ hrv *_t1144 = &(g524); int64_t _i1144 = d_888; (S1*)_t1144->b + hr_ix(_i1144, _t1144->n, "hc/check.amni:387"); }))).k_)); 
if ((((k_891) == (((int64_t)8LL))) || ((k_891) == (((int64_t)9LL))))) { return f137_set_t(n_884, ((int64_t)(((*({ hrv *_t1145 = &(g524); int64_t _i1145 = d_888; (S1*)_t1145->b + hr_ix(_i1145, _t1145->n, "hc/check.amni:388"); }))).a_)));
 }
hrv m_892 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1148 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1147 = &(m_892); hr_fs(_o1147, hr_str("cannot index ", 13)); hr_fs(_o1147, hr_sl(*hr_tmp(&_t1148, f160_tn(d_888)))); }));
}
(void)(f108_cerr(n_884, hr_sl(m_892)));
return f137_set_t(n_884, g548);
}
static int64_t f184_ck_slice(int64_t n_893, int64_t want_894) {
S4 x_895 = (*({ hrv *_t1149 = &(g675); int64_t _i1149 = n_893; (S4*)_t1149->b + hr_ix(_i1149, _t1149->n, "hc/check.amni:393"); })); 
int64_t t_896 = f136_ck(((int64_t)((x_895).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t1150 = &(g524); int64_t _i1150 = t_896; (S1*)_t1150->b + hr_ix(_i1150, _t1150->n, "hc/check.amni:395"); }))).k_) == (((uint8_t)18LL)))) { (void)(f137_set_t(((int64_t)((x_895).a_)), g549));
t_896 = g549;
 }
if (((((*({ hrv *_t1151 = &(g524); int64_t _i1151 = t_896; (S1*)_t1151->b + hr_ix(_i1151, _t1151->n, "hc/check.amni:396"); }))).k_) == (((uint8_t)19LL)))) { t_896 = f179_default_t(((int64_t)((x_895).a_)));
 }
int64_t d_897 = f174_deref(t_896); 
if ((((x_895).b_) >= (((int32_t)0LL)))) { (void)(f136_ck(((int64_t)((x_895).b_)), g536));
(void)(f139_conv(((int64_t)((x_895).b_)), g536));
 }
if ((((x_895).c_) >= (((int32_t)0LL)))) { (void)(f136_ck(((int64_t)((x_895).c_)), g536));
(void)(f139_conv(((int64_t)((x_895).c_)), g536));
 }
int64_t k_898 = ((int64_t)(((*({ hrv *_t1152 = &(g524); int64_t _i1152 = d_897; (S1*)_t1152->b + hr_ix(_i1152, _t1152->n, "hc/check.amni:400"); }))).k_)); 
if (((k_898) == (((int64_t)8LL)))) { return f137_set_t(n_893, f18_t_slice(((int64_t)(((*({ hrv *_t1153 = &(g524); int64_t _i1153 = d_897; (S1*)_t1153->b + hr_ix(_i1153, _t1153->n, "hc/check.amni:401"); }))).a_)), false));
 }
if (((k_898) == (((int64_t)9LL)))) { return f137_set_t(n_893, d_897);
 }
hrv m_899 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1156 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1155 = &(m_899); hr_fs(_o1155, hr_str("cannot slice ", 13)); hr_fs(_o1155, hr_sl(*hr_tmp(&_t1156, f160_tn(d_897)))); }));
}
(void)(f108_cerr(n_893, hr_sl(m_899)));
return f137_set_t(n_893, g548);
}
static int64_t f185_ck_as(int64_t n_900, int64_t want_901) {
S4 x_902 = (*({ hrv *_t1157 = &(g675); int64_t _i1157 = n_900; (S4*)_t1157->b + hr_ix(_i1157, _t1157->n, "hc/check.amni:407"); })); 
int64_t t_903 = f113_rtype(((int64_t)((x_902).b_)), f110_ns_of(n_900)); 
int64_t f_904 = f136_ck(((int64_t)((x_902).a_)), ({ int64_t _r1158; if ((((((*({ hrv *_t1159 = &(g524); int64_t _i1159 = t_903; (S1*)_t1159->b + hr_ix(_i1159, _t1159->n, "hc/check.amni:409"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t1160 = &(g524); int64_t _i1160 = t_903; (S1*)_t1160->b + hr_ix(_i1160, _t1160->n, "hc/check.amni:409"); }))).k_) == (((uint8_t)4LL))))) { _r1158 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1158 = t_903;  } _r1158; })); 
int64_t df_905 = f174_deref(f_904); 
if ((((((*({ hrv *_t1161 = &(g524); int64_t _i1161 = df_905; (S1*)_t1161->b + hr_ix(_i1161, _t1161->n, "hc/check.amni:411"); }))).k_) == (((uint8_t)12LL))) || ((((*({ hrv *_t1162 = &(g524); int64_t _i1162 = df_905; (S1*)_t1162->b + hr_ix(_i1162, _t1162->n, "hc/check.amni:411"); }))).k_) == (((uint8_t)13LL))))) { (void)(f139_conv(((int64_t)((x_902).a_)), ({ int64_t _r1163; if ((((((*({ hrv *_t1164 = &(g524); int64_t _i1164 = t_903; (S1*)_t1164->b + hr_ix(_i1164, _t1164->n, "hc/check.amni:411"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t1165 = &(g524); int64_t _i1165 = t_903; (S1*)_t1165->b + hr_ix(_i1165, _t1165->n, "hc/check.amni:411"); }))).k_) == (((uint8_t)4LL))))) { _r1163 = t_903;  } else { _r1163 = g536;  } _r1163; })));
 } else { if (((df_905) != (f_904))) { (void)(f148_set_cv(((int64_t)((x_902).a_)), df_905));
 }
 }
return f137_set_t(n_900, t_903);
}
static int64_t f186_ck_arr(int64_t n_906, int64_t want_907) {
S4 x_908 = (*({ hrv *_t1166 = &(g675); int64_t _i1166 = n_906; (S4*)_t1166->b + hr_ix(_i1166, _t1166->n, "hc/check.amni:626"); })); 
int64_t e_909 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((want_907) >= (((int64_t)0LL))) && (((((*({ hrv *_t1167 = &(g524); int64_t _i1167 = want_907; (S1*)_t1167->b + hr_ix(_i1167, _t1167->n, "hc/check.amni:628"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t1168 = &(g524); int64_t _i1168 = want_907; (S1*)_t1168->b + hr_ix(_i1168, _t1168->n, "hc/check.amni:628"); }))).k_) == (((uint8_t)9LL)))))) { e_909 = ((int64_t)(((*({ hrv *_t1169 = &(g524); int64_t _i1169 = want_907; (S1*)_t1169->b + hr_ix(_i1169, _t1169->n, "hc/check.amni:628"); }))).a_));
 }
if ((((x_908).c_) >= (((int32_t)0LL)))) { (void)(f136_ck(((int64_t)((x_908).c_)), g536));
(void)(f139_conv(((int64_t)((x_908).c_)), g536));
if (((want_907) >= (((int64_t)0LL)))) { return f137_set_t(n_906, want_907);
 }
return f137_set_t(n_906, g550);
 }
if ((((x_908).a_) >= (((int32_t)0LL)))) { (void)(f136_ck(((int64_t)((x_908).a_)), e_909));
(void)(f136_ck(((int64_t)((x_908).b_)), g536));
if (((e_909) >= (((int64_t)0LL)))) { (void)(f139_conv(((int64_t)((x_908).a_)), e_909));
(void)(f139_conv(((int64_t)((x_908).b_)), g536));
if (((((*({ hrv *_t1170 = &(g524); int64_t _i1170 = want_907; (S1*)_t1170->b + hr_ix(_i1170, _t1170->n, "hc/check.amni:630"); }))).k_) == (((uint8_t)9LL)))) { M77 _t1171 = f154_cval(((int64_t)((x_908).b_))); int64_t cnt_910 = _t1171.r0; bool u0_911 = _t1171.r1; bool ok_912 = _t1171.r2; 
(void)(f137_set_t(n_906, f121_t_arr(e_909, ((int64_t)1LL), cnt_910, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f148_set_cv(n_906, want_907));
return want_907;
 }
return f137_set_t(n_906, want_907);
 }
return f137_set_t(n_906, g550);
 }
{ int32_t _e1173 = (x_908).n_; for (int32_t i_913 = 0; i_913 < _e1173; i_913++) { (void)(f136_ck(f90_kid(n_906, ((int64_t)(i_913))), e_909));
 } } _bk1172:; 
if (((e_909) >= (((int64_t)0LL)))) { { int32_t _e1175 = (x_908).n_; for (int32_t i_914 = 0; i_914 < _e1175; i_914++) { (void)(f139_conv(f90_kid(n_906, ((int64_t)(i_914))), e_909));
 } } _bk1174:; 
if (((((*({ hrv *_t1176 = &(g524); int64_t _i1176 = want_907; (S1*)_t1176->b + hr_ix(_i1176, _t1176->n, "hc/check.amni:634"); }))).k_) == (((uint8_t)9LL)))) { (void)(f137_set_t(n_906, f121_t_arr(e_909, ((int64_t)1LL), f103_max(((int64_t)((x_908).n_)), ((int64_t)1LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f148_set_cv(n_906, want_907));
return want_907;
 }
return f137_set_t(n_906, want_907);
 }
return f137_set_t(n_906, g550);
}
static int64_t f187_ck_block(int64_t n_915, int64_t want_916) {
S4 x_917 = (*({ hrv *_t1177 = &(g675); int64_t _i1177 = n_915; (S4*)_t1177->b + hr_ix(_i1177, _t1177->n, "hc/check.amni:416"); })); 
int64_t m_918 = (g373).n; 
{ int32_t _e1179 = (x_917).n_; for (int32_t i_919 = 0; i_919 < _e1179; i_919++) { (void)(f188_cstmt(f90_kid(n_915, ((int64_t)(i_919)))));
 } } _bk1178:; 
int64_t t_1027 = g531; 
if ((((x_917).a_) >= (((int32_t)0LL)))) { t_1027 = f136_ck(((int64_t)((x_917).a_)), want_916);
if ((((((want_916) >= (((int64_t)0LL))) && ((t_1027) != (g531))) && (!(f162_is_pending(t_1027)))) && ((want_916) != (g531)))) {  }
 }
(void)(({ hrv *_v1180 = &(g373); int64_t _k1180 = ((int64_t)((int64_t)(g373).n - (int64_t)m_918)); if (_k1180 < 0 || _k1180 > _v1180->n) hr_die("pop_n past the length", "hc/check.amni:421"); _v1180->n -= _k1180; }));
return f137_set_t(n_915, t_1027);
}
static void f188_cstmt(int64_t n_920) {
S4 x_921 = (*({ hrv *_t1181 = &(g675); int64_t _i1181 = n_920; (S4*)_t1181->b + hr_ix(_i1181, _t1181->n, "hc/check.amni:640"); })); 
int64_t k_922 = ((int64_t)((x_921).k_)); 
if (((k_922) == (((int64_t)33LL)))) { (void)(f189_ck_vdecl(n_920));
return;
 }
if (((k_922) == (((int64_t)34LL)))) { (void)(f193_ck_assign(n_920));
return;
 }
if (((k_922) == (((int64_t)35LL)))) { int64_t t_965 = f136_ck(((int64_t)((x_921).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t1182 = &(g524); int64_t _i1182 = f174_deref(t_965); (S1*)_t1182->b + hr_ix(_i1182, _t1182->n, "hc/check.amni:644"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(n_920, hr_str("++/-- needs an integer", 22)));
 }
return;
 }
if (((k_922) == (((int64_t)50LL)))) { (void)(f194_decl_nested(n_920));
return;
 }
int64_t t_1026 = f136_ck(n_920, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f162_is_pending(t_1026)) { (void)(f179_default_t(n_920));
 }
}
static void f189_ck_vdecl(int64_t n_923) {
S4 x_924 = (*({ hrv *_t1183 = &(g675); int64_t _i1183 = n_923; (S4*)_t1183->b + hr_ix(_i1183, _t1183->n, "hc/check.amni:651"); })); 
int64_t fl_925 = ((int64_t)((x_924).fl_)); 
int64_t ns_926 = f110_ns_of(n_923); 
bool byref_927 = ((((int64_t)((int64_t)fl_925 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL))); 
int64_t dt_928 = ({ int64_t _r1184; if ((((x_924).a_) >= (((int32_t)0LL)))) { _r1184 = f113_rtype(((int64_t)((x_924).a_)), ns_926);  } else { _r1184 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1184; }); 
int64_t lf_929 = ((int64_t)((int64_t)((int64_t)((int64_t)({ int64_t _r1185; if (((((int64_t)((int64_t)fl_925 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)))) { _r1185 = ((int64_t)1LL);  } else { _r1185 = ((int64_t)0LL);  } _r1185; }) | (int64_t)({ int64_t _r1186; if (((((int64_t)((int64_t)fl_925 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { _r1186 = ((int64_t)2LL);  } else { _r1186 = ((int64_t)0LL);  } _r1186; }))) | (int64_t)({ int64_t _r1187; if (byref_927) { _r1187 = ((int64_t)8LL);  } else { _r1187 = ((int64_t)0LL);  } _r1187; }))); 
if ((((x_924).n_) > (((int32_t)1LL)))) { if ((((x_924).b_) < (((int32_t)0LL)))) { (void)(f108_cerr(n_923, hr_str("several names need a call's results", 35)));
return;
 }
int64_t init_930 = f90_kid(((int64_t)((x_924).b_)), ((int64_t)0LL)); 
int64_t t_931 = f136_ck(init_930, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t1188 = &(g524); int64_t _i1188 = t_931; (S1*)_t1188->b + hr_ix(_i1188, _t1188->n, "hc/check.amni:661"); }))).k_) != (((uint8_t)14LL)))) { if (((((int64_t)(((*({ hrv *_t1189 = &(g675); int64_t _i1189 = (x_924).b_; (S4*)_t1189->b + hr_ix(_i1189, _t1189->n, "hc/check.amni:661"); }))).n_))) == (((int64_t)((x_924).n_))))) { { int32_t _e1191 = (x_924).n_; for (int32_t i_932 = ((int32_t)1LL); i_932 < _e1191; i_932++) { int64_t iv_933 = f90_kid(((int64_t)((x_924).b_)), ((int64_t)(i_932))); 
(void)(f136_ck(iv_933, dt_928));
if (((dt_928) >= (((int64_t)0LL)))) { (void)(f139_conv(iv_933, dt_928));
 } else { (void)(f179_default_t(iv_933));
 }
 } } _bk1190:; 
if (((dt_928) >= (((int64_t)0LL)))) { (void)(f139_conv(init_930, dt_928));
 } else { (void)(f179_default_t(init_930));
 }
{ int32_t _e1193 = (x_924).n_; for (int32_t i_934 = 0; i_934 < _e1193; i_934++) { int64_t iv_935 = f90_kid(((int64_t)((x_924).b_)), ((int64_t)(i_934))); 
int64_t v_942 = f191_add_lv(((int64_t)((*({ hrv *_t1194 = &(g676); int64_t _i1194 = ((int64_t)((int64_t)((int64_t)((x_924).l_)) + (int64_t)((int64_t)(i_934)))); (int32_t*)_t1194->b + hr_ix(_i1194, _t1194->n, "hc/check.amni:661"); })))), ({ int64_t _r1195; if (((dt_928) >= (((int64_t)0LL)))) { _r1195 = dt_928;  } else { _r1195 = f190_fin_t(iv_935);  } _r1195; }), lf_929, n_923); 
if (((i_934) == (((int32_t)0LL)))) { (void)(f168_set_r(n_923, ((int64_t)1LL), v_942));
 }
 } } _bk1192:; 
(void)(f172_set_x(n_923, ((int64_t)1LL)));
return;
 }
(void)(f108_cerr(n_923, hr_str("several names need a call with as many results", 46)));
return;
 }
if (((((*({ hrv *_t1196 = &(g524); int64_t _i1196 = t_931; (S1*)_t1196->b + hr_ix(_i1196, _t1196->n, "hc/check.amni:662"); }))).n_) != ((x_924).n_))) { (void)(f108_cerr(n_923, hr_str("result count does not match the names", 37)));
 }
{ int32_t _e1198 = (x_924).n_; for (int32_t i_943 = 0; i_943 < _e1198; i_943++) { int64_t et_944 = ({ int64_t _r1199; if (((((int64_t)(i_943))) < (((int64_t)(((*({ hrv *_t1200 = &(g524); int64_t _i1200 = t_931; (S1*)_t1200->b + hr_ix(_i1200, _t1200->n, "hc/check.amni:663"); }))).n_))))) { _r1199 = ((int64_t)((*({ hrv *_t1201 = &(g525); int64_t _i1201 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1202 = &(g524); int64_t _i1202 = t_931; (S1*)_t1202->b + hr_ix(_i1202, _t1202->n, "hc/check.amni:663"); }))).l_)) + (int64_t)((int64_t)(i_943)))); (int32_t*)_t1201->b + hr_ix(_i1201, _t1201->n, "hc/check.amni:663"); }))));  } else { _r1199 = g548;  } _r1199; }); 
int64_t v_945 = f191_add_lv(((int64_t)((*({ hrv *_t1203 = &(g676); int64_t _i1203 = ((int64_t)((int64_t)((int64_t)((x_924).l_)) + (int64_t)((int64_t)(i_943)))); (int32_t*)_t1203->b + hr_ix(_i1203, _t1203->n, "hc/check.amni:663"); })))), et_944, lf_929, n_923); 
if (((i_943) == (((int32_t)0LL)))) { (void)(f168_set_r(n_923, ((int64_t)1LL), v_945));
 }
 } } _bk1197:; 
return;
 }
int64_t t_946 = dt_928; 
if ((((x_924).b_) >= (((int32_t)0LL)))) { int64_t init_947 = f90_kid(((int64_t)((x_924).b_)), ((int64_t)0LL)); 
int64_t it_948 = f136_ck(init_947, dt_928); 
if (((dt_928) >= (((int64_t)0LL)))) { if (byref_927) { if ((!(((((*({ hrv *_t1204 = &(g524); int64_t _i1204 = dt_928; (S1*)_t1204->b + hr_ix(_i1204, _t1204->n, "hc/check.amni:670"); }))).k_) == (((uint8_t)10LL)))))) { (void)(f139_conv(init_947, dt_928));
 }
 } else { (void)(f139_conv(init_947, dt_928));
 }
 } else { t_946 = f179_default_t(init_947);
if (((((*({ hrv *_t1205 = &(g524); int64_t _i1205 = t_946; (S1*)_t1205->b + hr_ix(_i1205, _t1205->n, "hc/check.amni:673"); }))).k_) == (((uint8_t)14LL)))) { t_946 = ((int64_t)((*({ hrv *_t1206 = &(g525); int64_t _i1206 = ((*({ hrv *_t1207 = &(g524); int64_t _i1207 = t_946; (S1*)_t1207->b + hr_ix(_i1207, _t1207->n, "hc/check.amni:673"); }))).l_; (int32_t*)_t1206->b + hr_ix(_i1206, _t1206->n, "hc/check.amni:673"); }))));
 }
if (byref_927) { if (((((*({ hrv *_t1208 = &(g524); int64_t _i1208 = t_946; (S1*)_t1208->b + hr_ix(_i1208, _t1208->n, "hc/check.amni:674"); }))).k_) != (((uint8_t)10LL)))) { t_946 = f117_t_ref(t_946, ((int64_t)0LL));
 }
 } else { if ((((((((*({ hrv *_t1209 = &(g524); int64_t _i1209 = t_946; (S1*)_t1209->b + hr_ix(_i1209, _t1209->n, "hc/check.amni:675"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t1210 = &(g524); int64_t _i1210 = t_946; (S1*)_t1210->b + hr_ix(_i1210, _t1210->n, "hc/check.amni:675"); }))).c_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1211 = &(g524); int64_t _i1211 = t_946; (S1*)_t1211->b + hr_ix(_i1211, _t1211->n, "hc/check.amni:675"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))) && f192_is_fixed(((int64_t)(((*({ hrv *_t1212 = &(g524); int64_t _i1212 = t_946; (S1*)_t1212->b + hr_ix(_i1212, _t1212->n, "hc/check.amni:675"); }))).a_))))) { t_946 = ((int64_t)(((*({ hrv *_t1213 = &(g524); int64_t _i1213 = t_946; (S1*)_t1213->b + hr_ix(_i1213, _t1213->n, "hc/check.amni:675"); }))).a_));
(void)(f148_set_cv(init_947, t_946));
 }
 }
 }
 } else { if (((t_946) < (((int64_t)0LL)))) { (void)(f108_cerr(n_923, hr_str("a declaration needs a type or an initializer", 44)));
t_946 = g548;
 }
 }
if ((byref_927 && ((((*({ hrv *_t1214 = &(g524); int64_t _i1214 = t_946; (S1*)_t1214->b + hr_ix(_i1214, _t1214->n, "hc/check.amni:680"); }))).k_) != (((uint8_t)10LL))))) { t_946 = f117_t_ref(t_946, ((int64_t)0LL));
 }
int64_t v_950 = f191_add_lv(((int64_t)((*({ hrv *_t1215 = &(g676); int64_t _i1215 = (x_924).l_; (int32_t*)_t1215->b + hr_ix(_i1215, _t1215->n, "hc/check.amni:681"); })))), t_946, lf_929, n_923); 
(void)(f168_set_r(n_923, ((int64_t)1LL), v_950));
}
static int64_t f190_fin_t(int64_t n_936) {
int64_t c_937 = f147_cv(n_936); 
return ({ int64_t _r1216; if (((c_937) >= (((int64_t)0LL)))) { _r1216 = c_937;  } else { _r1216 = f140_at(n_936);  } _r1216; });
}
static int64_t f191_add_lv(int64_t name_938, int64_t t_939, int64_t fl_940, int64_t node_941) {
(void)(({ hrv *_v1217 = &(g372); S12 _x1217 = ((S12){ .name_ = ((int32_t)(name_938)), .ty_ = ((int32_t)(t_939)), .fl_ = ((uint16_t)(fl_940)), .cfn_ = ((int32_t)(g383)), .own_ = ((int32_t)(g382)), .node_ = ((int32_t)(node_941)), .cnt_ = ((int32_t)0LL), }); S12 *_p1217 = (S12*)hr_grow(_v1217, 1, sizeof _x1217); *_p1217 = _x1217; _p1217; }));
(void)(({ hrv *_v1218 = &(g373); int32_t _x1218 = ((int32_t)(((int64_t)((int64_t)(g372).n - (int64_t)((int64_t)1LL))))); int32_t *_p1218 = (int32_t*)hr_grow(_v1218, 1, sizeof _x1218); *_p1218 = _x1218; _p1218; }));
return ((int64_t)((int64_t)(g372).n - (int64_t)((int64_t)1LL)));
}
static bool f192_is_fixed(int64_t t_949) {
return ((f141_tclass(t_949)) == (((int64_t)0LL)));
}
static void f193_ck_assign(int64_t n_951) {
S4 x_952 = (*({ hrv *_t1219 = &(g675); int64_t _i1219 = n_951; (S4*)_t1219->b + hr_ix(_i1219, _t1219->n, "hc/check.amni:685"); })); 
int64_t o_953 = ((int64_t)((x_952).op_)); 
if (((o_953) == (((int64_t)11LL)))) { int64_t t_954 = f136_ck(((int64_t)((x_952).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t tl_955 = ((int64_t)((x_952).a_)); 
{ int32_t _e1221 = ((*({ hrv *_t1222 = &(g675); int64_t _i1222 = tl_955; (S4*)_t1222->b + hr_ix(_i1222, _t1222->n, "hc/check.amni:690"); }))).n_; for (int32_t i_956 = 0; i_956 < _e1221; i_956++) { int64_t tg_957 = f90_kid(tl_955, ((int64_t)(i_956))); 
int64_t tt_958 = f136_ck(tg_957, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
 } } _bk1220:; 
return;
 }
if (((o_953) == (((int64_t)18LL)))) { int64_t tt_959 = f136_ck(((int64_t)((x_952).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t rt_960 = f136_ck(((int64_t)((x_952).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f162_is_pending(rt_960)) { (void)(f179_default_t(((int64_t)((x_952).b_))));
 }
return;
 }
int64_t tt_961 = f136_ck(((int64_t)((x_952).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t d_962 = f174_deref(tt_961); 
if (((o_953) == (((int64_t)36LL)))) { (void)(f136_ck(((int64_t)((x_952).b_)), d_962));
(void)(f139_conv(((int64_t)((x_952).b_)), d_962));
return;
 }
int64_t lk_963 = f175_leaf_kind(d_962); 
int64_t rt_964 = f136_ck(((int64_t)((x_952).b_)), ({ int64_t _r1223; if ((((lk_963) >= (((int64_t)4LL))) && (((o_953) == (((int64_t)28LL))) || ((o_953) == (((int64_t)29LL)))))) { _r1223 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1223 = d_962;  } _r1223; })); 
if (((((lk_963) >= (((int64_t)4LL))) && (((o_953) == (((int64_t)28LL))) || ((o_953) == (((int64_t)29LL))))) && ((f174_deref(rt_964)) != (d_962)))) { (void)(f139_conv(((int64_t)((x_952).b_)), f176_leaf_type(d_962)));
return;
 }
if ((((o_953) == (((int64_t)45LL))) || ((o_953) == (((int64_t)46LL))))) { if (f162_is_pending(rt_964)) { (void)(f139_conv(((int64_t)((x_952).b_)), g536));
 }
return;
 }
(void)(f139_conv(((int64_t)((x_952).b_)), d_962));
}
static void f194_decl_nested(int64_t n_966) {
int64_t i_967 = f105_new_inst(n_966, n_966, ((int64_t)((*({ hrv *_t1224 = &(g690); int64_t _i1224 = n_966; (int32_t*)_t1224->b + hr_ix(_i1224, _t1224->n, "hc/calls.amni:25"); })))), g382); 
(void)(({ hrv *_v1225 = &(g306); S14 _x1225 = ((S14){ .name_ = ((*({ hrv *_t1226 = &(g675); int64_t _i1226 = n_966; (S4*)_t1226->b + hr_ix(_i1226, _t1226->n, "hc/calls.amni:26"); }))).s_, .node_ = ((int32_t)(n_966)), .inst_ = ((int32_t)(i_967)), .own_ = ((int32_t)(g382)), }); S14 *_p1225 = (S14*)hr_grow(_v1225, 1, sizeof _x1225); *_p1225 = _x1225; _p1225; }));
(void)(f195_sig_inst(i_967));
(void)(f200_check_inst(i_967));
}
static void f195_sig_inst(int64_t i_968) {
int64_t node_969 = ((int64_t)(((*({ hrv *_t1227 = &(g371); int64_t _i1227 = i_968; (S6*)_t1227->b + hr_ix(_i1227, _t1227->n, "hc/calls.amni:89"); }))).node_)); 
int64_t ns_970 = f110_ns_of(node_969); 
int64_t g0_971 = (g466).n; 
{ int32_t _e1229 = ((*({ hrv *_t1230 = &(g371); int64_t _i1230 = i_968; (S6*)_t1230->b + hr_ix(_i1230, _t1230->n, "hc/calls.amni:92"); }))).gn_; for (int32_t j_972 = 0; j_972 < _e1229; j_972++) { (void)(({ hrv *_v1231 = &(g466); S7 _x1231 = (*({ hrv *_t1232 = &(g375); int64_t _i1232 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1233 = &(g371); int64_t _i1233 = i_968; (S6*)_t1233->b + hr_ix(_i1233, _t1233->n, "hc/calls.amni:92"); }))).g0_)) + (int64_t)((int64_t)(j_972)))); (S7*)_t1232->b + hr_ix(_i1232, _t1232->n, "hc/calls.amni:92"); })); S7 *_p1231 = (S7*)hr_grow(_v1231, 1, sizeof _x1231); *_p1231 = _x1231; _p1231; }));
 } } _bk1228:; 
int64_t p0_973 = (g525).n; 
L88 pts_974 = ({ L88 _t1234; memset(&_t1234, 0, sizeof _t1234); _t1234.n = 0; _t1234; }); 
{ int32_t _e1236 = ((*({ hrv *_t1237 = &(g675); int64_t _i1237 = node_969; (S4*)_t1237->b + hr_ix(_i1237, _t1237->n, "hc/calls.amni:95"); }))).n_; for (int32_t j_975 = 0; j_975 < _e1236; j_975++) { int64_t p_976 = f90_kid(node_969, ((int64_t)(j_975))); 
int64_t t_977 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((*({ hrv *_t1238 = &(g675); int64_t _i1238 = p_976; (S4*)_t1238->b + hr_ix(_i1238, _t1238->n, "hc/calls.amni:98"); }))).a_) >= (((int32_t)0LL)))) { t_977 = f113_rtype(((int64_t)(((*({ hrv *_t1239 = &(g675); int64_t _i1239 = p_976; (S4*)_t1239->b + hr_ix(_i1239, _t1239->n, "hc/calls.amni:98"); }))).a_)), ns_970);
 } else { t_977 = f128_gb_find(f196_upname(p_976));
if (((t_977) < (((int64_t)0LL)))) { t_977 = g548;
 }
 }
(void)(({ L88 *_v1240 = &(pts_974); int32_t _x1240 = ((int32_t)(t_977)); if (_v1240->n >= 128) hr_die("push past a limited array's capacity", "hc/calls.amni:99"); _v1240->e[_v1240->n] = _x1240; &_v1240->e[_v1240->n++]; }));
 } } _bk1235:; 
((*({ hrv *_t1241 = &(g371); int64_t _i1241 = i_968; (S6*)_t1241->b + hr_ix(_i1241, _t1241->n, "hc/calls.amni:101"); }))).p0_ = ((int32_t)((g525).n));
(void)(({ hrv *_v1242 = &(g525); hsl _s1242 = ({ hsl _t1243 = ({ L88 *_t1244 = &(pts_974); (hsl){ (uint8_t*)_t1244->e, _t1244->n }; }); int64_t _l1243 = 0, _h1243 = _t1243.n; if (_l1243 < 0 || _h1243 < _l1243 || _h1243 > _t1243.n) hr_slerr(_l1243, _h1243, _t1243.n, "hc/calls.amni:101"); (hsl){ _t1243.p + _l1243 * (int64_t)sizeof(int32_t), _h1243 - _l1243 }; }); hr_append(_v1242, _s1242.p, _s1242.n, sizeof(int32_t)); }));
((*({ hrv *_t1245 = &(g371); int64_t _i1245 = i_968; (S6*)_t1245->b + hr_ix(_i1245, _t1245->n, "hc/calls.amni:101"); }))).pn_ = ((int32_t)(((int64_t)(pts_974).n)));
if (((((*({ hrv *_t1246 = &(g675); int64_t _i1246 = node_969; (S4*)_t1246->b + hr_ix(_i1246, _t1246->n, "hc/calls.amni:102"); }))).b_) >= (((int32_t)0LL)))) { int64_t rl_980 = ((int64_t)(((*({ hrv *_t1247 = &(g675); int64_t _i1247 = node_969; (S4*)_t1247->b + hr_ix(_i1247, _t1247->n, "hc/calls.amni:103"); }))).b_)); 
if (((((*({ hrv *_t1248 = &(g675); int64_t _i1248 = rl_980; (S4*)_t1248->b + hr_ix(_i1248, _t1248->n, "hc/calls.amni:104"); }))).n_) == (((int32_t)1LL)))) { ((*({ hrv *_t1249 = &(g371); int64_t _i1249 = i_968; (S6*)_t1249->b + hr_ix(_i1249, _t1249->n, "hc/calls.amni:104"); }))).ret_ = ((int32_t)(f113_rtype(f90_kid(rl_980, ((int64_t)0LL)), ns_970)));
 } else { L89 rs_981 = ({ L89 _t1250; memset(&_t1250, 0, sizeof _t1250); _t1250.n = 0; _t1250; }); 
{ int32_t _e1252 = ((*({ hrv *_t1253 = &(g675); int64_t _i1253 = rl_980; (S4*)_t1253->b + hr_ix(_i1253, _t1253->n, "hc/calls.amni:105"); }))).n_; for (int32_t j_982 = 0; j_982 < _e1252; j_982++) { int64_t r0_983 = f113_rtype(f90_kid(rl_980, ((int64_t)(j_982))), ns_970); 
(void)(({ L89 *_v1254 = &(rs_981); int32_t _x1254 = ((int32_t)(r0_983)); if (_v1254->n >= 64) hr_die("push past a limited array's capacity", "hc/calls.amni:105"); _v1254->e[_v1254->n] = _x1254; &_v1254->e[_v1254->n++]; }));
 } } _bk1251:; 
((*({ hrv *_t1255 = &(g371); int64_t _i1255 = i_968; (S6*)_t1255->b + hr_ix(_i1255, _t1255->n, "hc/calls.amni:105"); }))).ret_ = ((int32_t)(f197_tlist(((int64_t)14LL), ({ hsl _t1256 = ({ L89 *_t1257 = &(rs_981); (hsl){ (uint8_t*)_t1257->e, _t1257->n }; }); int64_t _l1256 = 0, _h1256 = _t1256.n; if (_l1256 < 0 || _h1256 < _l1256 || _h1256 > _t1256.n) hr_slerr(_l1256, _h1256, _t1256.n, "hc/calls.amni:105"); (hsl){ _t1256.p + _l1256 * (int64_t)sizeof(int32_t), _h1256 - _l1256 }; }), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
 }
 } else { ((*({ hrv *_t1258 = &(g371); int64_t _i1258 = i_968; (S6*)_t1258->b + hr_ix(_i1258, _t1258->n, "hc/calls.amni:106"); }))).ret_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));
((*({ hrv *_t1259 = &(g371); int64_t _i1259 = i_968; (S6*)_t1259->b + hr_ix(_i1259, _t1259->n, "hc/calls.amni:106"); }))).rinf_ = true;
if ((((((uint16_t)((uint64_t)((*({ hrv *_t1260 = &(g675); int64_t _i1260 = node_969; (S4*)_t1260->b + hr_ix(_i1260, _t1260->n, "hc/calls.amni:106"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || f198_surely_void(node_969))) { ((*({ hrv *_t1261 = &(g371); int64_t _i1261 = i_968; (S6*)_t1261->b + hr_ix(_i1261, _t1261->n, "hc/calls.amni:106"); }))).ret_ = ((int32_t)(g531));
((*({ hrv *_t1262 = &(g371); int64_t _i1262 = i_968; (S6*)_t1262->b + hr_ix(_i1262, _t1262->n, "hc/calls.amni:106"); }))).rinf_ = false;
 }
 }
(void)(({ hrv *_v1263 = &(g466); int64_t _k1263 = ((int64_t)((int64_t)(g466).n - (int64_t)g0_971)); if (_k1263 < 0 || _k1263 > _v1263->n) hr_die("pop_n past the length", "hc/calls.amni:107"); _v1263->n -= _k1263; }));
}
static int64_t f196_upname(int64_t p_978) {
hrv s_979 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v1265 = &(s_979); uint8_t _x1265 = ((uint8_t)36LL); uint8_t *_p1265 = (uint8_t*)hr_grow(_v1265, 1, sizeof _x1265); *_p1265 = _x1265; _p1265; }));
(void)(({ hrv *_v1266 = &(s_979); hsl _s1266 = f10_nm(((int64_t)(((*({ hrv *_t1267 = &(g675); int64_t _i1267 = p_978; (S4*)_t1267->b + hr_ix(_i1267, _t1267->n, "hc/calls.amni:43"); }))).s_))); hr_append(_v1266, _s1266.p, _s1266.n, sizeof(uint8_t)); }));
return f8_intern(hr_sl(s_979));
}
static int64_t f197_tlist(int64_t k_984, hsl xs_985, int64_t a_986) {
int64_t l_987 = (g525).n; 
(void)(({ hrv *_v1268 = &(g525); hsl _s1268 = xs_985; hr_append(_v1268, _s1268.p, _s1268.n, sizeof(int32_t)); }));
return f13_tmk(((S1){ .k_ = ((uint8_t)(k_984)), .a_ = ((int32_t)(a_986)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .l_ = ((int32_t)(l_987)), .n_ = ((int32_t)((xs_985).n)), }));
}
static bool f198_surely_void(int64_t fnode_988) {
int64_t body_989 = ((int64_t)(((*({ hrv *_t1269 = &(g675); int64_t _i1269 = fnode_988; (S4*)_t1269->b + hr_ix(_i1269, _t1269->n, "hc/calls.amni:110"); }))).c_)); 
if (((body_989) < (((int64_t)0LL)))) { return true;
 }
int64_t tl_990 = ((int64_t)(((*({ hrv *_t1270 = &(g675); int64_t _i1270 = body_989; (S4*)_t1270->b + hr_ix(_i1270, _t1270->n, "hc/calls.amni:112"); }))).a_)); 
if (((tl_990) >= (((int64_t)0LL)))) { int64_t k_991 = ((int64_t)(((*({ hrv *_t1271 = &(g675); int64_t _i1271 = tl_990; (S4*)_t1271->b + hr_ix(_i1271, _t1271->n, "hc/calls.amni:113"); }))).k_)); 
if ((!((((((((k_991) == (((int64_t)25LL))) || ((k_991) == (((int64_t)27LL)))) || ((k_991) == (((int64_t)28LL)))) || ((k_991) == (((int64_t)29LL)))) || ((k_991) == (((int64_t)30LL)))) || (((k_991) == (((int64_t)19LL))) && ((((*({ hrv *_t1272 = &(g675); int64_t _i1272 = tl_990; (S4*)_t1272->b + hr_ix(_i1272, _t1272->n, "hc/calls.amni:113"); }))).c_) < (((int32_t)0LL)))))))) { return false;
 }
 }
return (!(f199_has_valret(body_989)));
}
static bool f199_has_valret(int64_t n_992) {
if (((n_992) < (((int64_t)0LL)))) { return false;
 }
S4 x_993 = (*({ hrv *_t1273 = &(g675); int64_t _i1273 = n_992; (S4*)_t1273->b + hr_ix(_i1273, _t1273->n, "hc/calls.amni:118"); })); 
int64_t k_994 = ((int64_t)((x_993).k_)); 
if (((k_994) == (((int64_t)28LL)))) { return ((((x_993).n_) > (((int32_t)0LL))) && (((x_993).s_) < (((int32_t)0LL))));
 }
if (((k_994) == (((int64_t)50LL)))) { return false;
 }
if ((((((k_994) == (((int64_t)1LL))) || ((k_994) == (((int64_t)2LL)))) || ((k_994) == (((int64_t)3LL)))) || ((k_994) == (((int64_t)8LL))))) { return false;
 }
if ((((k_994) >= (((int64_t)40LL))) && ((k_994) < (((int64_t)50LL))))) { return false;
 }
if ((((f199_has_valret(((int64_t)((x_993).a_))) || f199_has_valret(((int64_t)((x_993).b_)))) || f199_has_valret(((int64_t)((x_993).c_)))) || f199_has_valret(((int64_t)((x_993).d_))))) { return true;
 }
if ((((((((((k_994) == (((int64_t)23LL))) || ((k_994) == (((int64_t)11LL)))) || ((k_994) == (((int64_t)20LL)))) || ((k_994) == (((int64_t)21LL)))) || ((k_994) == (((int64_t)36LL)))) || ((k_994) == (((int64_t)16LL)))) || ((k_994) == (((int64_t)17LL)))) || ((k_994) == (((int64_t)28LL))))) { { int32_t _e1275 = (x_993).n_; for (int32_t i_995 = 0; i_995 < _e1275; i_995++) { if (f199_has_valret(f90_kid(n_992, ((int64_t)(i_995))))) { return true;
 }
 } } _bk1274:; 
 }
return false;
}
static void f200_check_inst(int64_t i_996) {
if (((((*({ hrv *_t1276 = &(g371); int64_t _i1276 = i_996; (S6*)_t1276->b + hr_ix(_i1276, _t1276->n, "hc/calls.amni:129"); }))).st_) != (((uint8_t)0LL)))) { return;
 }
int64_t node_997 = ((int64_t)(((*({ hrv *_t1277 = &(g371); int64_t _i1277 = i_996; (S6*)_t1277->b + hr_ix(_i1277, _t1277->n, "hc/calls.amni:130"); }))).node_)); 
((*({ hrv *_t1278 = &(g371); int64_t _i1278 = i_996; (S6*)_t1278->b + hr_ix(_i1278, _t1278->n, "hc/calls.amni:131"); }))).st_ = ((uint8_t)1LL);
if (((((uint16_t)((uint64_t)((*({ hrv *_t1279 = &(g675); int64_t _i1279 = node_997; (S4*)_t1279->b + hr_ix(_i1279, _t1279->n, "hc/calls.amni:132"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { ((*({ hrv *_t1280 = &(g371); int64_t _i1280 = i_996; (S6*)_t1280->b + hr_ix(_i1280, _t1280->n, "hc/calls.amni:132"); }))).st_ = ((uint8_t)2LL);
return;
 }
int64_t sa_998 = g382; 
int64_t sc_999 = g383; 
int64_t sm_1000 = (g373).n; 
int64_t ld_1001 = g388; 
int64_t bt_1002 = (g444).n; 
int64_t nm0_1003 = (g306).n; 
g382 = i_996;
g383 = i_996;
g388 = ((int64_t)0LL);
int64_t g0_1004 = (g466).n; 
{ int32_t _e1282 = ((*({ hrv *_t1283 = &(g371); int64_t _i1283 = i_996; (S6*)_t1283->b + hr_ix(_i1283, _t1283->n, "hc/calls.amni:136"); }))).gn_; for (int32_t j_1005 = 0; j_1005 < _e1282; j_1005++) { (void)(({ hrv *_v1284 = &(g466); S7 _x1284 = (*({ hrv *_t1285 = &(g375); int64_t _i1285 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1286 = &(g371); int64_t _i1286 = i_996; (S6*)_t1286->b + hr_ix(_i1286, _t1286->n, "hc/calls.amni:136"); }))).g0_)) + (int64_t)((int64_t)(j_1005)))); (S7*)_t1285->b + hr_ix(_i1285, _t1285->n, "hc/calls.amni:136"); })); S7 *_p1284 = (S7*)hr_grow(_v1284, 1, sizeof _x1284); *_p1284 = _x1284; _p1284; }));
 } } _bk1281:; 
{ int32_t _e1288 = ((*({ hrv *_t1289 = &(g675); int64_t _i1289 = node_997; (S4*)_t1289->b + hr_ix(_i1289, _t1289->n, "hc/calls.amni:137"); }))).n_; for (int32_t j_1006 = 0; j_1006 < _e1288; j_1006++) { int64_t p_1007 = f90_kid(node_997, ((int64_t)(j_1006))); 
if (((((*({ hrv *_t1290 = &(g675); int64_t _i1290 = p_1007; (S4*)_t1290->b + hr_ix(_i1290, _t1290->n, "hc/calls.amni:137"); }))).b_) >= (((int32_t)0LL)))) { int64_t pt_1010 = f201_ptype_of(i_996, ((int64_t)(j_1006))); 
(void)(f136_ck(((int64_t)(((*({ hrv *_t1291 = &(g675); int64_t _i1291 = p_1007; (S4*)_t1291->b + hr_ix(_i1291, _t1291->n, "hc/calls.amni:137"); }))).b_)), pt_1010));
(void)(f139_conv(((int64_t)(((*({ hrv *_t1292 = &(g675); int64_t _i1292 = p_1007; (S4*)_t1292->b + hr_ix(_i1292, _t1292->n, "hc/calls.amni:137"); }))).b_)), pt_1010));
 }
 } } _bk1287:; 
{ int32_t _e1294 = ((*({ hrv *_t1295 = &(g675); int64_t _i1295 = node_997; (S4*)_t1295->b + hr_ix(_i1295, _t1295->n, "hc/calls.amni:138"); }))).n_; for (int32_t j_1011 = 0; j_1011 < _e1294; j_1011++) { int64_t p_1012 = f90_kid(node_997, ((int64_t)(j_1011))); 
int64_t v_1013 = f191_add_lv(((int64_t)(((*({ hrv *_t1296 = &(g675); int64_t _i1296 = p_1012; (S4*)_t1296->b + hr_ix(_i1296, _t1296->n, "hc/calls.amni:138"); }))).s_)), f201_ptype_of(i_996, ((int64_t)(j_1011))), ((int64_t)((int64_t)((int64_t)4LL) | (int64_t)({ int64_t _r1297; if (((((uint16_t)((uint64_t)((*({ hrv *_t1298 = &(g675); int64_t _i1298 = p_1012; (S4*)_t1298->b + hr_ix(_i1298, _t1298->n, "hc/calls.amni:138"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { _r1297 = ((int64_t)1LL);  } else { _r1297 = ((int64_t)0LL);  } _r1297; }))), p_1012); 
(void)(f168_set_r(p_1012, ((int64_t)1LL), v_1013));
 } } _bk1293:; 
int64_t body_1014 = ((int64_t)(((*({ hrv *_t1299 = &(g675); int64_t _i1299 = node_997; (S4*)_t1299->b + hr_ix(_i1299, _t1299->n, "hc/calls.amni:139"); }))).c_)); 
int64_t rt_1015 = ((int64_t)(((*({ hrv *_t1300 = &(g371); int64_t _i1300 = i_996; (S6*)_t1300->b + hr_ix(_i1300, _t1300->n, "hc/calls.amni:140"); }))).ret_)); 
int64_t t_1016 = f136_ck(body_1014, ({ int64_t _r1301; if (((rt_1015) >= (((int64_t)0LL)))) { _r1301 = rt_1015;  } else { _r1301 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1301; })); 
int64_t tail_1017 = ((int64_t)(((*({ hrv *_t1302 = &(g675); int64_t _i1302 = body_1014; (S4*)_t1302->b + hr_ix(_i1302, _t1302->n, "hc/calls.amni:142"); }))).a_)); 
if (((rt_1015) >= (((int64_t)0LL)))) { if ((((((tail_1017) >= (((int64_t)0LL))) && ((rt_1015) != (g531))) && ((t_1016) != (g531))) && (!(f202_ends(tail_1017))))) { (void)(f139_conv(tail_1017, rt_1015));
 }
 } else { if (((((*({ hrv *_t1303 = &(g371); int64_t _i1303 = i_996; (S6*)_t1303->b + hr_ix(_i1303, _t1303->n, "hc/calls.amni:145"); }))).ret_) < (((int32_t)0LL)))) { if ((((tail_1017) >= (((int64_t)0LL))) && ((t_1016) != (g531)))) { ((*({ hrv *_t1304 = &(g371); int64_t _i1304 = i_996; (S6*)_t1304->b + hr_ix(_i1304, _t1304->n, "hc/calls.amni:145"); }))).ret_ = ((int32_t)(f179_default_t(tail_1017)));
 } else { ((*({ hrv *_t1305 = &(g371); int64_t _i1305 = i_996; (S6*)_t1305->b + hr_ix(_i1305, _t1305->n, "hc/calls.amni:145"); }))).ret_ = ((int32_t)(g531));
 }
 } else { if (((((tail_1017) >= (((int64_t)0LL))) && ((t_1016) != (g531))) && ((((int64_t)(((*({ hrv *_t1306 = &(g371); int64_t _i1306 = i_996; (S6*)_t1306->b + hr_ix(_i1306, _t1306->n, "hc/calls.amni:146"); }))).ret_))) != (g531)))) { (void)(f139_conv(tail_1017, ((int64_t)(((*({ hrv *_t1307 = &(g371); int64_t _i1307 = i_996; (S6*)_t1307->b + hr_ix(_i1307, _t1307->n, "hc/calls.amni:146"); }))).ret_))));
 }
 }
 }
(void)(({ hrv *_v1308 = &(g466); int64_t _k1308 = ((int64_t)((int64_t)(g466).n - (int64_t)g0_1004)); if (_k1308 < 0 || _k1308 > _v1308->n) hr_die("pop_n past the length", "hc/calls.amni:148"); _v1308->n -= _k1308; }));
(void)(({ hrv *_v1309 = &(g373); int64_t _k1309 = ((int64_t)((int64_t)(g373).n - (int64_t)sm_1000)); if (_k1309 < 0 || _k1309 > _v1309->n) hr_die("pop_n past the length", "hc/calls.amni:149"); _v1309->n -= _k1309; }));
(void)(({ hrv *_v1310 = &(g306); int64_t _k1310 = ((int64_t)((int64_t)(g306).n - (int64_t)nm0_1003)); if (_k1310 < 0 || _k1310 > _v1310->n) hr_die("pop_n past the length", "hc/calls.amni:149"); _v1310->n -= _k1310; }));
while ((((g444).n) > (bt_1002))) { (void)(({ hrv *_v1312 = &(g444); if (!_v1312->n) hr_die("pop of an empty array", "hc/calls.amni:150"); ((int32_t*)_v1312->b)[--_v1312->n]; }));
 } _bk1311:; 
g382 = sa_998;
g383 = sc_999;
g388 = ld_1001;
((*({ hrv *_t1313 = &(g371); int64_t _i1313 = i_996; (S6*)_t1313->b + hr_ix(_i1313, _t1313->n, "hc/calls.amni:152"); }))).st_ = ((uint8_t)2LL);
}
static int64_t f201_ptype_of(int64_t i_1008, int64_t j_1009) {
return ((int64_t)((*({ hrv *_t1314 = &(g525); int64_t _i1314 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1315 = &(g371); int64_t _i1315 = i_1008; (S6*)_t1315->b + hr_ix(_i1315, _t1315->n, "hc/calls.amni:127"); }))).p0_)) + (int64_t)j_1009)); (int32_t*)_t1314->b + hr_ix(_i1314, _t1314->n, "hc/calls.amni:127"); }))));
}
static bool f202_ends(int64_t n_1018) {
if (((n_1018) < (((int64_t)0LL)))) { return false;
 }
int64_t k_1019 = ((int64_t)(((*({ hrv *_t1316 = &(g675); int64_t _i1316 = n_1018; (S4*)_t1316->b + hr_ix(_i1316, _t1316->n, "hc/check.amni:426"); }))).k_)); 
if (((((k_1019) == (((int64_t)28LL))) || ((k_1019) == (((int64_t)29LL)))) || ((k_1019) == (((int64_t)30LL))))) { return true;
 }
if ((((k_1019) == (((int64_t)11LL))) && ((((*({ hrv *_t1317 = &(g675); int64_t _i1317 = ((*({ hrv *_t1318 = &(g675); int64_t _i1318 = n_1018; (S4*)_t1318->b + hr_ix(_i1318, _t1318->n, "hc/check.amni:428"); }))).a_; (S4*)_t1317->b + hr_ix(_i1317, _t1317->n, "hc/check.amni:428"); }))).k_) == (((uint8_t)8LL))))) { hsl s_1020 = f10_nm(((int64_t)(((*({ hrv *_t1319 = &(g675); int64_t _i1319 = ((*({ hrv *_t1320 = &(g675); int64_t _i1320 = n_1018; (S4*)_t1320->b + hr_ix(_i1320, _t1320->n, "hc/check.amni:428"); }))).a_; (S4*)_t1319->b + hr_ix(_i1319, _t1319->n, "hc/check.amni:428"); }))).s_))); 
if ((hr_streq(s_1020, hr_str("abort", 5)) || hr_streq(s_1020, hr_str("exit", 4)))) { return true;
 }
 }
if (((k_1019) == (((int64_t)23LL)))) { if (((((*({ hrv *_t1321 = &(g675); int64_t _i1321 = n_1018; (S4*)_t1321->b + hr_ix(_i1321, _t1321->n, "hc/check.amni:429"); }))).a_) >= (((int32_t)0LL)))) { return f202_ends(((int64_t)(((*({ hrv *_t1322 = &(g675); int64_t _i1322 = n_1018; (S4*)_t1322->b + hr_ix(_i1322, _t1322->n, "hc/check.amni:429"); }))).a_)));
 }
if (((((*({ hrv *_t1323 = &(g675); int64_t _i1323 = n_1018; (S4*)_t1323->b + hr_ix(_i1323, _t1323->n, "hc/check.amni:429"); }))).n_) > (((int32_t)0LL)))) { return f202_ends(f90_kid(n_1018, ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1324 = &(g675); int64_t _i1324 = n_1018; (S4*)_t1324->b + hr_ix(_i1324, _t1324->n, "hc/check.amni:429"); }))).n_)) - (int64_t)((int64_t)1LL)))));
 }
return false;
 }
if (((k_1019) == (((int64_t)19LL)))) { return ((((((*({ hrv *_t1325 = &(g675); int64_t _i1325 = n_1018; (S4*)_t1325->b + hr_ix(_i1325, _t1325->n, "hc/check.amni:430"); }))).c_) >= (((int32_t)0LL))) && f202_ends(((int64_t)(((*({ hrv *_t1326 = &(g675); int64_t _i1326 = n_1018; (S4*)_t1326->b + hr_ix(_i1326, _t1326->n, "hc/check.amni:430"); }))).b_)))) && f202_ends(((int64_t)(((*({ hrv *_t1327 = &(g675); int64_t _i1327 = n_1018; (S4*)_t1327->b + hr_ix(_i1327, _t1327->n, "hc/check.amni:430"); }))).c_))));
 }
if (((k_1019) == (((int64_t)26LL)))) { return (!(f203_has_break(((int64_t)(((*({ hrv *_t1328 = &(g675); int64_t _i1328 = n_1018; (S4*)_t1328->b + hr_ix(_i1328, _t1328->n, "hc/check.amni:431"); }))).a_)))));
 }
return false;
}
static bool f203_has_break(int64_t n_1021) {
if (((n_1021) < (((int64_t)0LL)))) { return false;
 }
S4 x_1022 = (*({ hrv *_t1329 = &(g675); int64_t _i1329 = n_1021; (S4*)_t1329->b + hr_ix(_i1329, _t1329->n, "hc/check.amni:436"); })); 
int64_t k_1023 = ((int64_t)((x_1022).k_)); 
if (((k_1023) == (((int64_t)29LL)))) { return true;
 }
if (((((((k_1023) == (((int64_t)25LL))) || ((k_1023) == (((int64_t)26LL)))) || ((k_1023) == (((int64_t)27LL)))) || ((k_1023) == (((int64_t)50LL)))) || ((k_1023) == (((int64_t)31LL))))) { return false;
 }
if (((f203_has_break(((int64_t)((x_1022).a_))) || f203_has_break(((int64_t)((x_1022).b_)))) || f203_has_break(((int64_t)((x_1022).c_))))) { return true;
 }
if ((((k_1023) == (((int64_t)23LL))) || ((k_1023) == (((int64_t)20LL))))) { { int32_t _e1331 = (x_1022).n_; for (int32_t i_1024 = 0; i_1024 < _e1331; i_1024++) { int64_t c_1025 = f90_kid(n_1021, ((int64_t)(i_1024))); 
if (f203_has_break(c_1025)) { return true;
 }
if ((((k_1023) == (((int64_t)20LL))) && f203_has_break(((int64_t)(((*({ hrv *_t1332 = &(g675); int64_t _i1332 = c_1025; (S4*)_t1332->b + hr_ix(_i1332, _t1332->n, "hc/check.amni:440"); }))).b_))))) { return true;
 }
 } } _bk1330:; 
 }
return false;
}
static int64_t f204_ck_if(int64_t n_1030, int64_t want_1031) {
S4 x_1032 = (*({ hrv *_t1333 = &(g675); int64_t _i1333 = n_1030; (S4*)_t1333->b + hr_ix(_i1333, _t1333->n, "hc/check.amni:444"); })); 
int64_t c_1033 = f136_ck(((int64_t)((x_1032).a_)), g532); 
if ((((((*({ hrv *_t1334 = &(g524); int64_t _i1334 = f174_deref(c_1033); (S1*)_t1334->b + hr_ix(_i1334, _t1334->n, "hc/check.amni:446"); }))).k_) == (((uint8_t)10LL))) || (((((*({ hrv *_t1335 = &(g524); int64_t _i1335 = c_1033; (S1*)_t1335->b + hr_ix(_i1335, _t1335->n, "hc/check.amni:446"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1336 = &(g524); int64_t _i1336 = c_1033; (S1*)_t1336->b + hr_ix(_i1336, _t1336->n, "hc/check.amni:446"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))))) { (void)(f172_set_x(n_1030, ((int64_t)1LL)));
 } else { (void)(f139_conv(((int64_t)((x_1032).a_)), g532));
 }
int64_t narrow_1037 = f205_narrow_of(((int64_t)((x_1032).a_))); 
int64_t m_1038 = (g373).n; 
if (((narrow_1037) >= (((int64_t)0LL)))) { S12 v_1039 = (*({ hrv *_t1337 = &(g372); int64_t _i1337 = narrow_1037; (S12*)_t1337->b + hr_ix(_i1337, _t1337->n, "hc/check.amni:450"); })); 
(void)(f191_add_lv(((int64_t)((v_1039).name_)), ((int64_t)(((*({ hrv *_t1338 = &(g524); int64_t _i1338 = (v_1039).ty_; (S1*)_t1338->b + hr_ix(_i1338, _t1338->n, "hc/check.amni:450"); }))).a_)), ((int64_t)((int64_t)((int64_t)((v_1039).fl_)) | (int64_t)((int64_t)8LL))), ((int64_t)((x_1032).a_))));
(void)(f172_set_x(n_1030, ((int64_t)((int64_t)((int64_t)((int64_t)(g372).n - (int64_t)((int64_t)1LL))) | (int64_t)((int64_t)((((int64_t)1LL)) << ((((int64_t)30LL)) & 63)))))));
 }
int64_t tb_1040 = f136_ck(((int64_t)((x_1032).b_)), want_1031); 
(void)(({ hrv *_v1339 = &(g373); int64_t _k1339 = ((int64_t)((int64_t)(g373).n - (int64_t)m_1038)); if (_k1339 < 0 || _k1339 > _v1339->n) hr_die("pop_n past the length", "hc/check.amni:452"); _v1339->n -= _k1339; }));
if ((((x_1032).c_) < (((int32_t)0LL)))) { return f137_set_t(n_1030, g531);
 }
int64_t tc_1041 = f136_ck(((int64_t)((x_1032).c_)), want_1031); 
bool eb_1042 = f202_ends(((int64_t)((x_1032).b_))); 
bool ec_1043 = f202_ends(((int64_t)((x_1032).c_))); 
if ((eb_1042 && (!(ec_1043)))) { return f137_set_t(n_1030, tc_1041);
 }
if ((ec_1043 && (!(eb_1042)))) { return f137_set_t(n_1030, tb_1040);
 }
if ((eb_1042 && ec_1043)) { return f137_set_t(n_1030, tb_1040);
 }
if ((((tb_1040) == (g531)) || ((tc_1041) == (g531)))) { return f137_set_t(n_1030, g531);
 }
if (((tb_1040) == (tc_1041))) { return f137_set_t(n_1030, tb_1040);
 }
if ((((((want_1031) >= (((int64_t)0LL))) && ((want_1031) != (g531))) && (f162_is_pending(tb_1040) || f149_conv_ok(tb_1040, want_1031, ((int64_t)((x_1032).b_))))) && (f162_is_pending(tc_1041) || f149_conv_ok(tc_1041, want_1031, ((int64_t)((x_1032).c_)))))) { (void)(f139_conv(((int64_t)((x_1032).b_)), want_1031));
(void)(f139_conv(((int64_t)((x_1032).c_)), want_1031));
return f137_set_t(n_1030, want_1031);
 }
int64_t u_1044 = f177_unify(n_1030, ((int64_t)((x_1032).b_)), ((int64_t)((x_1032).c_))); 
return f137_set_t(n_1030, u_1044);
}
static int64_t f205_narrow_of(int64_t c_1034) {
if ((((((*({ hrv *_t1340 = &(g675); int64_t _i1340 = c_1034; (S4*)_t1340->b + hr_ix(_i1340, _t1340->n, "hc/check.amni:466"); }))).k_) != (((uint8_t)8LL))) || ((f155_rk(c_1034)) != (((int64_t)1LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t v_1035 = f156_rv(c_1034); 
int64_t t_1036 = ((int64_t)(((*({ hrv *_t1341 = &(g372); int64_t _i1341 = v_1035; (S12*)_t1341->b + hr_ix(_i1341, _t1341->n, "hc/check.amni:468"); }))).ty_)); 
if ((((((*({ hrv *_t1342 = &(g524); int64_t _i1342 = t_1036; (S1*)_t1342->b + hr_ix(_i1342, _t1342->n, "hc/check.amni:469"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1343 = &(g524); int64_t _i1343 = t_1036; (S1*)_t1343->b + hr_ix(_i1343, _t1343->n, "hc/check.amni:469"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { return v_1035;
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f206_ck_while(int64_t n_1045) {
S4 x_1046 = (*({ hrv *_t1344 = &(g675); int64_t _i1344 = n_1045; (S4*)_t1344->b + hr_ix(_i1344, _t1344->n, "hc/check.amni:473"); })); 
int64_t c_1047 = f136_ck(((int64_t)((x_1046).a_)), g532); 
int64_t narrow_1048 = f205_narrow_of(((int64_t)((x_1046).a_))); 
if (((narrow_1048) < (((int64_t)0LL)))) { (void)(f139_conv(((int64_t)((x_1046).a_)), g532));
 } else { (void)(f172_set_x(n_1045, ((int64_t)1LL)));
 }
g388++;
(void)(f136_ck(((int64_t)((x_1046).b_)), g531));
g388--;
return f137_set_t(n_1045, g531);
}
static int64_t f207_ck_loop(int64_t n_1049, int64_t want_1050) {
(void)(({ hrv *_v1345 = &(g444); int32_t _x1345 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1345 = (int32_t*)hr_grow(_v1345, 1, sizeof _x1345); *_p1345 = _x1345; _p1345; }));
g388++;
(void)(f136_ck(((int64_t)(((*({ hrv *_t1346 = &(g675); int64_t _i1346 = n_1049; (S4*)_t1346->b + hr_ix(_i1346, _t1346->n, "hc/check.amni:486"); }))).a_)), g531));
g388--;
int64_t t_1051 = ((int64_t)(({ hrv *_v1347 = &(g444); if (!_v1347->n) hr_die("pop of an empty array", "hc/check.amni:488"); ((int32_t*)_v1347->b)[--_v1347->n]; }))); 
return f137_set_t(n_1049, ({ int64_t _r1348; if (((t_1051) < (((int64_t)0LL)))) { _r1348 = g531;  } else { _r1348 = t_1051;  } _r1348; }));
}
static int64_t f208_ck_for(int64_t n_1052) {
S4 x_1053 = (*({ hrv *_t1349 = &(g675); int64_t _i1349 = n_1052; (S4*)_t1349->b + hr_ix(_i1349, _t1349->n, "hc/check.amni:492"); })); 
int64_t m_1054 = (g373).n; 
int64_t et_1055 = g536; 
if ((((x_1053).b_) >= (((int32_t)0LL)))) { int64_t ta_1056 = f136_ck(((int64_t)((x_1053).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t tb_1057 = f136_ck(((int64_t)((x_1053).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t u_1058 = f177_unify(n_1052, ((int64_t)((x_1053).a_)), ((int64_t)((x_1053).b_))); 
et_1055 = ({ int64_t _r1350; if (((((*({ hrv *_t1351 = &(g524); int64_t _i1351 = u_1058; (S1*)_t1351->b + hr_ix(_i1351, _t1351->n, "hc/check.amni:498"); }))).k_) == (((uint8_t)12LL)))) { (void)(f139_conv(((int64_t)((x_1053).a_)), g536));
(void)(f139_conv(((int64_t)((x_1053).b_)), g536));
_r1350 = g536;  } else { _r1350 = u_1058;  } _r1350; });
(void)(f172_set_x(n_1052, ((int64_t)0LL)));
 } else { int64_t t_1059 = f136_ck(((int64_t)((x_1053).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t1352 = &(g524); int64_t _i1352 = t_1059; (S1*)_t1352->b + hr_ix(_i1352, _t1352->n, "hc/check.amni:502"); }))).k_) == (((uint8_t)18LL)))) { (void)(f137_set_t(((int64_t)((x_1053).a_)), g549));
t_1059 = g549;
 }
if (((((*({ hrv *_t1353 = &(g524); int64_t _i1353 = t_1059; (S1*)_t1353->b + hr_ix(_i1353, _t1353->n, "hc/check.amni:503"); }))).k_) == (((uint8_t)19LL)))) { t_1059 = f179_default_t(((int64_t)((x_1053).a_)));
 }
int64_t d_1060 = f174_deref(t_1059); 
if (((((*({ hrv *_t1354 = &(g524); int64_t _i1354 = d_1060; (S1*)_t1354->b + hr_ix(_i1354, _t1354->n, "hc/check.amni:505"); }))).k_) == (((uint8_t)12LL)))) { (void)(f139_conv(((int64_t)((x_1053).a_)), g536));
et_1055 = g536;
(void)(f172_set_x(n_1052, ((int64_t)0LL)));
 } else { if (((((*({ hrv *_t1355 = &(g524); int64_t _i1355 = d_1060; (S1*)_t1355->b + hr_ix(_i1355, _t1355->n, "hc/check.amni:506"); }))).k_) == (((uint8_t)3LL)))) { et_1055 = d_1060;
if (((d_1060) != (t_1059))) { (void)(f148_set_cv(((int64_t)((x_1053).a_)), d_1060));
 }
(void)(f172_set_x(n_1052, ((int64_t)0LL)));
 } else { if ((((((*({ hrv *_t1356 = &(g524); int64_t _i1356 = d_1060; (S1*)_t1356->b + hr_ix(_i1356, _t1356->n, "hc/check.amni:507"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t1357 = &(g524); int64_t _i1357 = d_1060; (S1*)_t1357->b + hr_ix(_i1357, _t1357->n, "hc/check.amni:507"); }))).k_) == (((uint8_t)9LL))))) { et_1055 = ((int64_t)(((*({ hrv *_t1358 = &(g524); int64_t _i1358 = d_1060; (S1*)_t1358->b + hr_ix(_i1358, _t1358->n, "hc/check.amni:507"); }))).a_));
(void)(f172_set_x(n_1052, ((int64_t)1LL)));
 } else { hrv mm_1061 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1361 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1360 = &(mm_1061); hr_fs(_o1360, hr_str("cannot iterate over ", 20)); hr_fs(_o1360, hr_sl(*hr_tmp(&_t1361, f160_tn(d_1060)))); }));
}
(void)(f108_cerr(n_1052, hr_sl(mm_1061)));
 }
 }
 }
 }
if ((((x_1053).l_) >= (((int32_t)0LL)))) { et_1055 = f113_rtype(((int64_t)((x_1053).l_)), f110_ns_of(n_1052));
 }
bool byref_1062 = ((((uint16_t)((uint64_t)(x_1053).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))); 
int64_t v_1063 = f191_add_lv(((int64_t)((x_1053).s_)), ({ int64_t _r1362; if (byref_1062) { _r1362 = f117_t_ref(et_1055, ((int64_t)0LL));  } else { _r1362 = et_1055;  } _r1362; }), ((int64_t)((int64_t)((int64_t)16LL) | (int64_t)({ int64_t _r1363; if (byref_1062) { _r1363 = ((int64_t)8LL);  } else { _r1363 = ((int64_t)0LL);  } _r1363; }))), n_1052); 
(void)(f168_set_r(n_1052, ((int64_t)1LL), v_1063));
if ((((x_1053).c_) >= (((int32_t)0LL)))) { int64_t iv_1064 = f191_add_lv(((int64_t)((x_1053).c_)), g536, ((int64_t)16LL), n_1052); 
(void)(f172_set_x(n_1052, ((int64_t)((int64_t)f209_ax(n_1052) | (int64_t)((int64_t)((iv_1064) << ((((int64_t)2LL)) & 63)))))));
 }
g388++;
(void)(f136_ck(((int64_t)((x_1053).d_)), g531));
g388--;
(void)(({ hrv *_v1364 = &(g373); int64_t _k1364 = ((int64_t)((int64_t)(g373).n - (int64_t)m_1054)); if (_k1364 < 0 || _k1364 > _v1364->n) hr_die("pop_n past the length", "hc/check.amni:518"); _v1364->n -= _k1364; }));
return f137_set_t(n_1052, g531);
}
static int64_t f209_ax(int64_t n_1065) {
return ((int64_t)((*({ hrv *_t1365 = &(g380); int64_t _i1365 = f138_aix(n_1065); (int32_t*)_t1365->b + hr_ix(_i1365, _t1365->n, "hc/check.amni:44"); }))));
}
static int64_t f210_ck_match(int64_t n_1066, int64_t want_1067) {
S4 x_1068 = (*({ hrv *_t1366 = &(g675); int64_t _i1366 = n_1066; (S4*)_t1366->b + hr_ix(_i1366, _t1366->n, "hc/check.amni:522"); })); 
int64_t st_1069 = f136_ck(((int64_t)((x_1068).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t1367 = &(g524); int64_t _i1367 = st_1069; (S1*)_t1367->b + hr_ix(_i1367, _t1367->n, "hc/check.amni:524"); }))).k_) == (((uint8_t)12LL)))) { (void)(f139_conv(((int64_t)((x_1068).a_)), g536));
st_1069 = g536;
 }
int64_t d_1070 = f174_deref(st_1069); 
int64_t rt_1071 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
bool allv_1072 = true; 
{ int32_t _e1369 = (x_1068).n_; for (int32_t i_1073 = 0; i_1073 < _e1369; i_1073++) { int64_t arm_1074 = f90_kid(n_1066, ((int64_t)(i_1073))); 
int64_t m_1075 = (g373).n; 
S4 ax0_1076 = (*({ hrv *_t1370 = &(g675); int64_t _i1370 = arm_1074; (S4*)_t1370->b + hr_ix(_i1370, _t1370->n, "hc/check.amni:531"); })); 
if (((((uint16_t)((uint64_t)(ax0_1076).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) { { int32_t _e1372 = (ax0_1076).n_; for (int32_t j_1077 = 0; j_1077 < _e1372; j_1077++) { int64_t it_1078 = f90_kid(arm_1074, ((int64_t)(j_1077))); 
int64_t lo_1079 = ((int64_t)(((*({ hrv *_t1373 = &(g675); int64_t _i1373 = it_1078; (S4*)_t1373->b + hr_ix(_i1373, _t1373->n, "hc/check.amni:535"); }))).a_)); 
if ((((((*({ hrv *_t1374 = &(g524); int64_t _i1374 = d_1070; (S1*)_t1374->b + hr_ix(_i1374, _t1374->n, "hc/check.amni:536"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t1375 = &(g675); int64_t _i1375 = lo_1079; (S4*)_t1375->b + hr_ix(_i1375, _t1375->n, "hc/check.amni:536"); }))).k_) == (((uint8_t)8LL))))) { int64_t ei_1080 = ((int64_t)(((*({ hrv *_t1376 = &(g524); int64_t _i1376 = d_1070; (S1*)_t1376->b + hr_ix(_i1376, _t1376->n, "hc/check.amni:537"); }))).a_)); 
int64_t found_1081 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e1378 = ((*({ hrv *_t1379 = &(g529); int64_t _i1379 = ei_1080; (S8*)_t1379->b + hr_ix(_i1379, _t1379->n, "hc/check.amni:539"); }))).vnum_; for (int32_t q_1082 = 0; q_1082 < _e1378; q_1082++) { if (((((*({ hrv *_t1380 = &(g530); int64_t _i1380 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1381 = &(g529); int64_t _i1381 = ei_1080; (S8*)_t1381->b + hr_ix(_i1381, _t1381->n, "hc/check.amni:539"); }))).v0_)) + (int64_t)((int64_t)(q_1082)))); (S9*)_t1380->b + hr_ix(_i1380, _t1380->n, "hc/check.amni:539"); }))).name_) == (((*({ hrv *_t1382 = &(g675); int64_t _i1382 = lo_1079; (S4*)_t1382->b + hr_ix(_i1382, _t1382->n, "hc/check.amni:539"); }))).s_))) { found_1081 = ((int64_t)(q_1082));
 }
 } } _bk1377:; 
if (((found_1081) < (((int64_t)0LL)))) { hrv mm_1083 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1386 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1384 = &(mm_1083); hr_fs(_o1384, hr_str("no variant ", 11)); hr_fs(_o1384, f10_nm(((int64_t)(((*({ hrv *_t1385 = &(g675); int64_t _i1385 = lo_1079; (S4*)_t1385->b + hr_ix(_i1385, _t1385->n, "hc/check.amni:540"); }))).s_)))); hr_fs(_o1384, hr_str(" in ", 4)); hr_fs(_o1384, hr_sl(*hr_tmp(&_t1386, f160_tn(d_1070)))); }));
}
(void)(f108_cerr(lo_1079, hr_sl(mm_1083)));
 }
(void)(f168_set_r(lo_1079, ((int64_t)7LL), found_1081));
(void)(f137_set_t(lo_1079, d_1070));
if (((((ax0_1076).s_) >= (((int32_t)0LL))) && ((found_1081) >= (((int64_t)0LL))))) { int64_t vt_1084 = f123_t_variant(ei_1080, found_1081); 
bool byr_1085 = ((((uint16_t)((uint64_t)(ax0_1076).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))); 
int64_t v_1086 = f191_add_lv(((int64_t)((ax0_1076).s_)), ({ int64_t _r1387; if (byr_1085) { _r1387 = f117_t_ref(vt_1084, ((int64_t)0LL));  } else { _r1387 = vt_1084;  } _r1387; }), ({ int64_t _r1388; if (byr_1085) { _r1388 = ((int64_t)8LL);  } else { _r1388 = ((int64_t)0LL);  } _r1388; }), arm_1074); 
(void)(f168_set_r(arm_1074, ((int64_t)1LL), v_1086));
 }
 } else { (void)(f136_ck(lo_1079, d_1070));
(void)(f139_conv(lo_1079, d_1070));
if (((((*({ hrv *_t1389 = &(g675); int64_t _i1389 = it_1078; (S4*)_t1389->b + hr_ix(_i1389, _t1389->n, "hc/check.amni:545"); }))).b_) >= (((int32_t)0LL)))) { (void)(f136_ck(((int64_t)(((*({ hrv *_t1390 = &(g675); int64_t _i1390 = it_1078; (S4*)_t1390->b + hr_ix(_i1390, _t1390->n, "hc/check.amni:545"); }))).b_)), d_1070));
(void)(f139_conv(((int64_t)(((*({ hrv *_t1391 = &(g675); int64_t _i1391 = it_1078; (S4*)_t1391->b + hr_ix(_i1391, _t1391->n, "hc/check.amni:545"); }))).b_)), d_1070));
 }
 }
 } } _bk1371:; 
 }
int64_t bt_1087 = f136_ck(((int64_t)((ax0_1076).b_)), want_1067); 
(void)(({ hrv *_v1392 = &(g373); int64_t _k1392 = ((int64_t)((int64_t)(g373).n - (int64_t)m_1075)); if (_k1392 < 0 || _k1392 > _v1392->n) hr_die("pop_n past the length", "hc/check.amni:550"); _v1392->n -= _k1392; }));
if (((bt_1087) == (g531))) { allv_1072 = false;
 } else { if ((!(f202_ends(((int64_t)((ax0_1076).b_)))))) { if ((((rt_1071) < (((int64_t)0LL))) || f162_is_pending(rt_1071))) { rt_1071 = bt_1087;
 }
 }
 }
 } } _bk1368:; 
if (((!(allv_1072)) || ((rt_1071) < (((int64_t)0LL))))) { return f137_set_t(n_1066, g531);
 }
bool allw_1088 = (((want_1067) >= (((int64_t)0LL))) && ((want_1067) != (g531))); 
if (allw_1088) { { int32_t _e1394 = (x_1068).n_; for (int32_t i_1089 = 0; i_1089 < _e1394; i_1089++) { int64_t b_1090 = ((int64_t)(((*({ hrv *_t1395 = &(g675); int64_t _i1395 = f90_kid(n_1066, ((int64_t)(i_1089))); (S4*)_t1395->b + hr_ix(_i1395, _t1395->n, "hc/check.amni:555"); }))).b_)); 
int64_t bt_1091 = f140_at(b_1090); 
if ((((!(f202_ends(b_1090))) && (!(f162_is_pending(bt_1091)))) && (!(f149_conv_ok(bt_1091, want_1067, b_1090))))) { allw_1088 = false;
 }
 } } _bk1393:; 
 }
if (allw_1088) { { int32_t _e1397 = (x_1068).n_; for (int32_t i_1092 = 0; i_1092 < _e1397; i_1092++) { int64_t b_1093 = ((int64_t)(((*({ hrv *_t1398 = &(g675); int64_t _i1398 = f90_kid(n_1066, ((int64_t)(i_1092))); (S4*)_t1398->b + hr_ix(_i1398, _t1398->n, "hc/check.amni:556"); }))).b_)); 
if ((!(f202_ends(b_1093)))) { (void)(f139_conv(b_1093, want_1067));
 }
 } } _bk1396:; 
return f137_set_t(n_1066, want_1067);
 }
if (f162_is_pending(rt_1071)) { { int32_t _e1400 = (x_1068).n_; for (int32_t i_1094 = 0; i_1094 < _e1400; i_1094++) { int64_t b_1095 = ((int64_t)(((*({ hrv *_t1401 = &(g675); int64_t _i1401 = f90_kid(n_1066, ((int64_t)(i_1094))); (S4*)_t1401->b + hr_ix(_i1401, _t1401->n, "hc/check.amni:557"); }))).b_)); 
int64_t bt_1096 = f140_at(b_1095); 
if (((!(f162_is_pending(bt_1096))) && (!(f202_ends(b_1095))))) { rt_1071 = bt_1096;
 }
 } } _bk1399:; 
 }
if (f162_is_pending(rt_1071)) { int64_t b_1097 = ((int64_t)(((*({ hrv *_t1402 = &(g675); int64_t _i1402 = f90_kid(n_1066, ((int64_t)0LL)); (S4*)_t1402->b + hr_ix(_i1402, _t1402->n, "hc/check.amni:558"); }))).b_)); 
rt_1071 = f179_default_t(b_1097);
 }
{ int32_t _e1404 = (x_1068).n_; for (int32_t i_1098 = 0; i_1098 < _e1404; i_1098++) { int64_t b_1099 = ((int64_t)(((*({ hrv *_t1405 = &(g675); int64_t _i1405 = f90_kid(n_1066, ((int64_t)(i_1098))); (S4*)_t1405->b + hr_ix(_i1405, _t1405->n, "hc/check.amni:559"); }))).b_)); 
if ((!(f202_ends(b_1099)))) { (void)(f139_conv(b_1099, rt_1071));
 }
 } } _bk1403:; 
return f137_set_t(n_1066, rt_1071);
}
static int64_t f211_ck_ret(int64_t n_1100) {
S4 x_1101 = (*({ hrv *_t1406 = &(g675); int64_t _i1406 = n_1100; (S4*)_t1406->b + hr_ix(_i1406, _t1406->n, "hc/check.amni:563"); })); 
if ((((x_1101).s_) >= (((int32_t)0LL)))) { { int32_t _e1408 = (x_1101).n_; for (int32_t i_1102 = 0; i_1102 < _e1408; i_1102++) { (void)(f136_ck(f90_kid(n_1100, ((int64_t)(i_1102))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
(void)(f179_default_t(f90_kid(n_1100, ((int64_t)(i_1102)))));
 } } _bk1407:; 
(void)(f137_set_t(n_1100, g531));
return g531;
 }
int64_t f_1104 = f212_ret_fn(); 
if (((f_1104) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1100, hr_str("return outside a function", 25)));
return g531;
 }
if (((f_1104) != (g383))) { ((*({ hrv *_t1409 = &(g371); int64_t _i1409 = g383; (S6*)_t1409->b + hr_ix(_i1409, _t1409->n, "hc/check.amni:567"); }))).lr_ = true;
(void)(f172_set_x(n_1100, f_1104));
 } else { (void)(f172_set_x(n_1100, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
int64_t rt_1105 = ((int64_t)(((*({ hrv *_t1410 = &(g371); int64_t _i1410 = f_1104; (S6*)_t1410->b + hr_ix(_i1410, _t1410->n, "hc/check.amni:568"); }))).ret_)); 
if ((((x_1101).n_) == (((int32_t)0LL)))) { if (((((rt_1105) >= (((int64_t)0LL))) && ((rt_1105) != (g531))) && (!(((*({ hrv *_t1411 = &(g371); int64_t _i1411 = f_1104; (S6*)_t1411->b + hr_ix(_i1411, _t1411->n, "hc/check.amni:569"); }))).rinf_)))) { (void)(f108_cerr(n_1100, hr_str("return needs a value", 20)));
 }
if (((rt_1105) < (((int64_t)0LL)))) { ((*({ hrv *_t1412 = &(g371); int64_t _i1412 = f_1104; (S6*)_t1412->b + hr_ix(_i1412, _t1412->n, "hc/check.amni:569"); }))).ret_ = ((int32_t)(g531));
 }
return f137_set_t(n_1100, g531);
 }
if (((((rt_1105) >= (((int64_t)0LL))) && ((((*({ hrv *_t1413 = &(g524); int64_t _i1413 = rt_1105; (S1*)_t1413->b + hr_ix(_i1413, _t1413->n, "hc/check.amni:570"); }))).k_) == (((uint8_t)14LL)))) && (((x_1101).n_) == (((int32_t)1LL))))) { int64_t c_1106 = f90_kid(n_1100, ((int64_t)0LL)); 
(void)(f136_ck(c_1106, rt_1105));
return f137_set_t(n_1100, g531);
 }
if ((((x_1101).n_) > (((int32_t)1LL)))) { if (((rt_1105) < (((int64_t)0LL)))) { L89 ts_1107 = ({ L89 _t1414; memset(&_t1414, 0, sizeof _t1414); _t1414.n = 0; _t1414; }); 
{ int32_t _e1416 = (x_1101).n_; for (int32_t i_1108 = 0; i_1108 < _e1416; i_1108++) { (void)(f136_ck(f90_kid(n_1100, ((int64_t)(i_1108))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
int64_t dt0_1109 = f179_default_t(f90_kid(n_1100, ((int64_t)(i_1108)))); 
(void)(({ L89 *_v1417 = &(ts_1107); int32_t _x1417 = ((int32_t)(dt0_1109)); if (_v1417->n >= 64) hr_die("push past a limited array's capacity", "hc/check.amni:572"); _v1417->e[_v1417->n] = _x1417; &_v1417->e[_v1417->n++]; }));
 } } _bk1415:; 
((*({ hrv *_t1418 = &(g371); int64_t _i1418 = f_1104; (S6*)_t1418->b + hr_ix(_i1418, _t1418->n, "hc/check.amni:572"); }))).ret_ = ((int32_t)(f197_tlist(((int64_t)14LL), ({ hsl _t1419 = ({ L89 *_t1420 = &(ts_1107); (hsl){ (uint8_t*)_t1420->e, _t1420->n }; }); int64_t _l1419 = 0, _h1419 = _t1419.n; if (_l1419 < 0 || _h1419 < _l1419 || _h1419 > _t1419.n) hr_slerr(_l1419, _h1419, _t1419.n, "hc/check.amni:572"); (hsl){ _t1419.p + _l1419 * (int64_t)sizeof(int32_t), _h1419 - _l1419 }; }), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
return f137_set_t(n_1100, g531);
 }
{ int32_t _e1422 = (x_1101).n_; for (int32_t i_1110 = 0; i_1110 < _e1422; i_1110++) { int64_t et_1111 = ({ int64_t _r1423; if ((((((*({ hrv *_t1424 = &(g524); int64_t _i1424 = rt_1105; (S1*)_t1424->b + hr_ix(_i1424, _t1424->n, "hc/check.amni:573"); }))).k_) == (((uint8_t)14LL))) && ((((int64_t)(i_1110))) < (((int64_t)(((*({ hrv *_t1425 = &(g524); int64_t _i1425 = rt_1105; (S1*)_t1425->b + hr_ix(_i1425, _t1425->n, "hc/check.amni:573"); }))).n_)))))) { _r1423 = ((int64_t)((*({ hrv *_t1426 = &(g525); int64_t _i1426 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1427 = &(g524); int64_t _i1427 = rt_1105; (S1*)_t1427->b + hr_ix(_i1427, _t1427->n, "hc/check.amni:573"); }))).l_)) + (int64_t)((int64_t)(i_1110)))); (int32_t*)_t1426->b + hr_ix(_i1426, _t1426->n, "hc/check.amni:573"); }))));  } else { _r1423 = g548;  } _r1423; }); 
(void)(f136_ck(f90_kid(n_1100, ((int64_t)(i_1110))), et_1111));
(void)(f139_conv(f90_kid(n_1100, ((int64_t)(i_1110))), et_1111));
 } } _bk1421:; 
return f137_set_t(n_1100, g531);
 }
int64_t c_1112 = f90_kid(n_1100, ((int64_t)0LL)); 
if (((rt_1105) < (((int64_t)0LL)))) { (void)(f136_ck(c_1112, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
int64_t t_1113 = f179_default_t(c_1112); 
((*({ hrv *_t1428 = &(g371); int64_t _i1428 = f_1104; (S6*)_t1428->b + hr_ix(_i1428, _t1428->n, "hc/check.amni:577"); }))).ret_ = ((int32_t)(t_1113));
return f137_set_t(n_1100, g531);
 }
(void)(f136_ck(c_1112, rt_1105));
(void)(f139_conv(c_1112, rt_1105));
return f137_set_t(n_1100, g531);
}
static int64_t f212_ret_fn(void) {
int64_t i_1103 = g382; 
while (((i_1103) >= (((int64_t)0LL)))) { if ((((((*({ hrv *_t1430 = &(g371); int64_t _i1430 = i_1103; (S6*)_t1430->b + hr_ix(_i1430, _t1430->n, "hc/check.amni:581"); }))).node_) >= (((int32_t)0LL))) && ((((*({ hrv *_t1431 = &(g675); int64_t _i1431 = ((*({ hrv *_t1432 = &(g371); int64_t _i1432 = i_1103; (S6*)_t1432->b + hr_ix(_i1432, _t1432->n, "hc/check.amni:581"); }))).node_; (S4*)_t1431->b + hr_ix(_i1431, _t1431->n, "hc/check.amni:581"); }))).k_) == (((uint8_t)50LL))))) { return i_1103;
 }
i_1103 = ((int64_t)(((*({ hrv *_t1433 = &(g371); int64_t _i1433 = i_1103; (S6*)_t1433->b + hr_ix(_i1433, _t1433->n, "hc/check.amni:581"); }))).par_));
 } _bk1429:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f213_ck_break(int64_t n_1114) {
S4 x_1115 = (*({ hrv *_t1434 = &(g675); int64_t _i1434 = n_1114; (S4*)_t1434->b + hr_ix(_i1434, _t1434->n, "hc/check.amni:583"); })); 
if ((((x_1115).a_) >= (((int32_t)0LL)))) { if ((((g444).n) == (((int64_t)0LL)))) { (void)(f108_cerr(n_1114, hr_str("break with a value outside loop or block", 40)));
return g531;
 }
int64_t w_1116 = ((int64_t)((*({ hrv *_t1435 = &(g444); int64_t _i1435 = ((int64_t)((int64_t)(g444).n - (int64_t)((int64_t)1LL))); (int32_t*)_t1435->b + hr_ix(_i1435, _t1435->n, "hc/check.amni:586"); })))); 
int64_t t_1117 = f136_ck(((int64_t)((x_1115).a_)), ({ int64_t _r1436; if (((w_1116) >= (((int64_t)0LL)))) { _r1436 = w_1116;  } else { _r1436 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1436; })); 
if (((w_1116) < (((int64_t)0LL)))) { (*({ hrv *_t1437 = &(g444); int64_t _i1437 = ((int64_t)((int64_t)(g444).n - (int64_t)((int64_t)1LL))); (int32_t*)_t1437->b + hr_ix(_i1437, _t1437->n, "hc/check.amni:588"); })) = ((int32_t)(f179_default_t(((int64_t)((x_1115).a_)))));
 } else { (void)(f139_conv(((int64_t)((x_1115).a_)), w_1116));
 }
 }
return f137_set_t(n_1114, g531);
}
static int64_t f214_ck_call(int64_t n_1118, int64_t want_1119) {
S4 x_1120 = (*({ hrv *_t1438 = &(g675); int64_t _i1438 = n_1118; (S4*)_t1438->b + hr_ix(_i1438, _t1438->n, "hc/calls.amni:239"); })); 
int64_t cal_1121 = ((int64_t)((x_1120).a_)); 
int64_t ck__1122 = ((int64_t)(((*({ hrv *_t1439 = &(g675); int64_t _i1439 = cal_1121; (S4*)_t1439->b + hr_ix(_i1439, _t1439->n, "hc/calls.amni:241"); }))).k_)); 
if (((ck__1122) == (((int64_t)8LL)))) { int64_t name_1123 = ((int64_t)(((*({ hrv *_t1440 = &(g675); int64_t _i1440 = cal_1121; (S4*)_t1440->b + hr_ix(_i1440, _t1440->n, "hc/calls.amni:243"); }))).s_)); 
int64_t v_1124 = f166_find_lv(name_1123); 
int64_t nf_1127 = f215_find_nest(name_1123); 
if ((((v_1124) < (((int64_t)0LL))) && ((nf_1127) >= (((int64_t)0LL))))) { return f216_call_nested(n_1118, nf_1127);
 }
if (((v_1124) < (((int64_t)0LL)))) { int64_t bg_1162 = f220_block_binding(name_1123); 
if (((bg_1162) >= (((int64_t)0LL)))) { return f225_call_block(n_1118, bg_1162);
 }
int64_t b_1192 = f227_builtin_of(f10_nm(name_1123)); 
if (((((b_1192) >= (((int64_t)0LL))) && (!((((b_1192) == (((int64_t)3LL))) && f228_user_format(n_1118))))) && (!((((b_1192) == (((int64_t)9LL))) && false))))) { return f231_ck_builtin(n_1118, b_1192, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), want_1119);
 }
return f233_call_fn(n_1118, name_1123, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), want_1119);
 }
 }
if (((ck__1122) == (((int64_t)14LL)))) { int64_t obj_1348 = ((int64_t)(((*({ hrv *_t1441 = &(g675); int64_t _i1441 = cal_1121; (S4*)_t1441->b + hr_ix(_i1441, _t1441->n, "hc/calls.amni:256"); }))).a_)); 
int64_t name_1349 = ((int64_t)(((*({ hrv *_t1442 = &(g675); int64_t _i1442 = cal_1121; (S4*)_t1442->b + hr_ix(_i1442, _t1442->n, "hc/calls.amni:257"); }))).s_)); 
if ((((((((*({ hrv *_t1443 = &(g675); int64_t _i1443 = obj_1348; (S4*)_t1443->b + hr_ix(_i1443, _t1443->n, "hc/calls.amni:258"); }))).k_) == (((uint8_t)8LL))) && ((f166_find_lv(((int64_t)(((*({ hrv *_t1444 = &(g675); int64_t _i1444 = obj_1348; (S4*)_t1444->b + hr_ix(_i1444, _t1444->n, "hc/calls.amni:258"); }))).s_)))) < (((int64_t)0LL)))) && ((f119_lookup_q(((int64_t)(((*({ hrv *_t1445 = &(g675); int64_t _i1445 = obj_1348; (S4*)_t1445->b + hr_ix(_i1445, _t1445->n, "hc/calls.amni:258"); }))).s_)), f110_ns_of(obj_1348), ((int64_t)2LL))) >= (((int64_t)0LL)))) && ((f119_lookup_q(((int64_t)(((*({ hrv *_t1446 = &(g675); int64_t _i1446 = obj_1348; (S4*)_t1446->b + hr_ix(_i1446, _t1446->n, "hc/calls.amni:258"); }))).s_)), f110_ns_of(obj_1348), ((int64_t)5LL))) < (((int64_t)0LL))))) { (void)(f108_cerr(n_1118, hr_str("a variant is constructed with { }", 33)));
return f137_set_t(n_1118, g548);
 }
int64_t ot_1350 = f136_ck(obj_1348, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t1447 = &(g524); int64_t _i1447 = ot_1350; (S1*)_t1447->b + hr_ix(_i1447, _t1447->n, "hc/calls.amni:260"); }))).k_) == (((uint8_t)18LL)))) { (void)(f137_set_t(obj_1348, g549));
ot_1350 = g549;
 }
int64_t d_1351 = f174_deref(ot_1350); 
int64_t mb_1353 = f241_member_of(f10_nm(name_1349)); 
if ((((mb_1353) >= (((int64_t)0LL))) && (((((*({ hrv *_t1448 = &(g524); int64_t _i1448 = d_1351; (S1*)_t1448->b + hr_ix(_i1448, _t1448->n, "hc/calls.amni:263"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t1449 = &(g524); int64_t _i1449 = d_1351; (S1*)_t1449->b + hr_ix(_i1449, _t1449->n, "hc/calls.amni:263"); }))).k_) == (((uint8_t)9LL)))))) { return f231_ck_builtin(n_1118, mb_1353, obj_1348, want_1119);
 }
if (((((((*({ hrv *_t1450 = &(g524); int64_t _i1450 = ot_1350; (S1*)_t1450->b + hr_ix(_i1450, _t1450->n, "hc/calls.amni:264"); }))).k_) == (((uint8_t)19LL))) || ((((*({ hrv *_t1451 = &(g524); int64_t _i1451 = ot_1350; (S1*)_t1451->b + hr_ix(_i1451, _t1451->n, "hc/calls.amni:264"); }))).k_) == (((uint8_t)12LL)))) || ((((*({ hrv *_t1452 = &(g524); int64_t _i1452 = ot_1350; (S1*)_t1452->b + hr_ix(_i1452, _t1452->n, "hc/calls.amni:264"); }))).k_) == (((uint8_t)13LL))))) { (void)(f179_default_t(obj_1348));
 }
int64_t b_1354 = f227_builtin_of(f10_nm(name_1349)); 
if ((((((b_1354) == (((int64_t)3LL))) || ((b_1354) == (((int64_t)30LL)))) || ((b_1354) == (((int64_t)31LL)))) || ((b_1354) == (((int64_t)7LL))))) { return f231_ck_builtin(n_1118, b_1354, obj_1348, want_1119);
 }
(void)(f172_set_x(n_1118, ((int64_t)1LL)));
return f233_call_fn(n_1118, name_1349, obj_1348, want_1119);
 }
(void)(f108_cerr(n_1118, hr_str("this call's callee is not supported yet", 39)));
return f137_set_t(n_1118, g548);
}
static int64_t f215_find_nest(int64_t name_1125) {
int64_t i_1126 = ((int64_t)((int64_t)(g306).n - (int64_t)((int64_t)1LL))); 
while (((i_1126) >= (((int64_t)0LL)))) { if ((((((int64_t)(((*({ hrv *_t1454 = &(g306); int64_t _i1454 = i_1126; (S14*)_t1454->b + hr_ix(_i1454, _t1454->n, "hc/calls.amni:23"); }))).name_))) == (name_1125)) && f167_visible(((int64_t)(((*({ hrv *_t1455 = &(g306); int64_t _i1455 = i_1126; (S14*)_t1455->b + hr_ix(_i1455, _t1455->n, "hc/calls.amni:23"); }))).own_))))) { return i_1126;
 }
i_1126--;
 } _bk1453:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f216_call_nested(int64_t n_1128, int64_t nf_1129) {
int64_t i_1130 = ((int64_t)(((*({ hrv *_t1456 = &(g306); int64_t _i1456 = nf_1129; (S14*)_t1456->b + hr_ix(_i1456, _t1456->n, "hc/calls.amni:315"); }))).inst_)); 
int64_t s_1137 = f217_ck_args(n_1128, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
{ int32_t _e1458 = ((*({ hrv *_t1459 = &(g675); int64_t _i1459 = n_1128; (S4*)_t1459->b + hr_ix(_i1459, _t1459->n, "hc/calls.amni:317"); }))).n_; for (int32_t j_1138 = 0; j_1138 < _e1458; j_1138++) { int64_t c_1139 = f90_kid(n_1128, ((int64_t)(j_1138))); 
if (((((int64_t)(j_1138))) < (((int64_t)(((*({ hrv *_t1460 = &(g371); int64_t _i1460 = i_1130; (S6*)_t1460->b + hr_ix(_i1460, _t1460->n, "hc/calls.amni:317"); }))).pn_))))) { (void)(f139_conv(c_1139, f201_ptype_of(i_1130, ((int64_t)(j_1138)))));
 }
 } } _bk1457:; 
(void)(f218_pop_args(s_1137));
(void)(f219_note_caps_of(i_1130));
(void)(f168_set_r(n_1128, ((int64_t)3LL), i_1130));
return f137_set_t(n_1128, ({ int64_t _r1461; if (((((*({ hrv *_t1462 = &(g371); int64_t _i1462 = i_1130; (S6*)_t1462->b + hr_ix(_i1462, _t1462->n, "hc/calls.amni:321"); }))).ret_) >= (((int32_t)0LL)))) { _r1461 = ((int64_t)(((*({ hrv *_t1463 = &(g371); int64_t _i1463 = i_1130; (S6*)_t1463->b + hr_ix(_i1463, _t1463->n, "hc/calls.amni:321"); }))).ret_));  } else { _r1461 = g531;  } _r1461; }));
}
static int64_t f217_ck_args(int64_t n_1131, int64_t a0n_1132, int64_t first_1133) {
int64_t start_1134 = (g389).n; 
if (((first_1133) >= (((int64_t)0LL)))) { (void)(({ hrv *_v1464 = &(g389); int32_t _x1464 = ((int32_t)(f140_at(first_1133))); int32_t *_p1464 = (int32_t*)hr_grow(_v1464, 1, sizeof _x1464); *_p1464 = _x1464; _p1464; }));
(void)(({ hrv *_v1465 = &(g310); int32_t _x1465 = ((int32_t)(first_1133)); int32_t *_p1465 = (int32_t*)hr_grow(_v1465, 1, sizeof _x1465); *_p1465 = _x1465; _p1465; }));
 }
{ int32_t _e1467 = ((*({ hrv *_t1468 = &(g675); int64_t _i1468 = n_1131; (S4*)_t1468->b + hr_ix(_i1468, _t1468->n, "hc/calls.amni:234"); }))).n_; for (int32_t i_1135 = 0; i_1135 < _e1467; i_1135++) { int64_t c_1136 = f90_kid(n_1131, ((int64_t)(i_1135))); 
(void)(({ hrv *_v1469 = &(g389); int32_t _x1469 = ((int32_t)(f136_ck(c_1136, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p1469 = (int32_t*)hr_grow(_v1469, 1, sizeof _x1469); *_p1469 = _x1469; _p1469; }));
(void)(({ hrv *_v1470 = &(g310); int32_t _x1470 = ((int32_t)(c_1136)); int32_t *_p1470 = (int32_t*)hr_grow(_v1470, 1, sizeof _x1470); *_p1470 = _x1470; _p1470; }));
 } } _bk1466:; 
return start_1134;
}
static void f218_pop_args(int64_t s_1140) {
(void)(({ hrv *_v1471 = &(g389); int64_t _k1471 = ((int64_t)((int64_t)(g389).n - (int64_t)s_1140)); if (_k1471 < 0 || _k1471 > _v1471->n) hr_die("pop_n past the length", "hc/calls.amni:237"); _v1471->n -= _k1471; }));
(void)(({ hrv *_v1472 = &(g310); int64_t _k1472 = ((int64_t)((int64_t)(g310).n - (int64_t)s_1140)); if (_k1472 < 0 || _k1472 > _v1472->n) hr_die("pop_n past the length", "hc/calls.amni:237"); _v1472->n -= _k1472; }));
}
static void f219_note_caps_of(int64_t i_1141) {
{ hrv *_v1474 = &(g374); for (int64_t _k1474 = 0; _k1474 < _v1474->n; _k1474++) { S13 c_1142 = ((S13*)_v1474->b)[_k1474]; if (((((int64_t)((c_1142).inst_))) == (i_1141))) { int64_t v_1143 = ((int64_t)((c_1142).lv_)); 
if (((((int64_t)(((*({ hrv *_t1475 = &(g372); int64_t _i1475 = v_1143; (S12*)_t1475->b + hr_ix(_i1475, _t1475->n, "hc/calls.amni:324"); }))).cfn_))) != (g383))) { (void)(f169_note_cap(v_1143));
 }
 }
 } } _bk1473:; 
}
static int64_t f220_block_binding(int64_t name_1144) {
int64_t i_1145 = g382; 
while (((i_1145) >= (((int64_t)0LL)))) { S6 f_1146 = (*({ hrv *_t1477 = &(g371); int64_t _i1477 = i_1145; (S6*)_t1477->b + hr_ix(_i1477, _t1477->n, "hc/calls.amni:277"); })); 
if ((((f_1146).blk_) >= (((int32_t)0LL)))) { int64_t fnode_1147 = ((int64_t)((f_1146).node_)); 
if (((f221_blk_gen(fnode_1147)) == (name_1144))) { return i_1145;
 }
 }
i_1145 = ((int64_t)((f_1146).par_));
 } _bk1476:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f221_blk_gen(int64_t fnode_1148) {
int64_t gl_1150 = f222_gen_list(fnode_1148); 
if (((gl_1150) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
{ int32_t _e1479 = ((*({ hrv *_t1480 = &(g675); int64_t _i1480 = gl_1150; (S4*)_t1480->b + hr_ix(_i1480, _t1480->n, "hc/calls.amni:42"); }))).n_; for (int32_t i_1151 = 0; i_1151 < _e1479; i_1151++) { int64_t g_1152 = ((int64_t)(((*({ hrv *_t1481 = &(g675); int64_t _i1481 = f90_kid(gl_1150, ((int64_t)(i_1151))); (S4*)_t1481->b + hr_ix(_i1481, _t1481->n, "hc/calls.amni:42"); }))).s_)); 
if (f223_is_blockparam(fnode_1148, g_1152)) { return g_1152;
 }
 } } _bk1478:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f222_gen_list(int64_t fnode_1149) {
return ((int64_t)(((*({ hrv *_t1482 = &(g675); int64_t _i1482 = fnode_1149; (S4*)_t1482->b + hr_ix(_i1482, _t1482->n, "hc/calls.amni:30"); }))).d_));
}
static bool f223_is_blockparam(int64_t fnode_1153, int64_t gname_1154) {
{ int32_t _e1484 = ((*({ hrv *_t1485 = &(g675); int64_t _i1485 = fnode_1153; (S4*)_t1485->b + hr_ix(_i1485, _t1485->n, "hc/calls.amni:32"); }))).n_; for (int32_t i_1155 = 0; i_1155 < _e1484; i_1155++) { int64_t p_1156 = f90_kid(fnode_1153, ((int64_t)(i_1155))); 
if ((((((*({ hrv *_t1486 = &(g675); int64_t _i1486 = p_1156; (S4*)_t1486->b + hr_ix(_i1486, _t1486->n, "hc/calls.amni:32"); }))).a_) >= (((int32_t)0LL))) && f224_mentions(((int64_t)(((*({ hrv *_t1487 = &(g675); int64_t _i1487 = p_1156; (S4*)_t1487->b + hr_ix(_i1487, _t1487->n, "hc/calls.amni:32"); }))).a_)), gname_1154))) { return false;
 }
 } } _bk1483:; 
return true;
}
static bool f224_mentions(int64_t t_1157, int64_t g_1158) {
if (((t_1157) < (((int64_t)0LL)))) { return false;
 }
S4 x_1159 = (*({ hrv *_t1488 = &(g675); int64_t _i1488 = t_1157; (S4*)_t1488->b + hr_ix(_i1488, _t1488->n, "hc/calls.amni:37"); })); 
int64_t k_1160 = ((int64_t)((x_1159).k_)); 
if (((k_1160) == (((int64_t)41LL)))) { if (((((int64_t)((x_1159).s_))) == (g_1158))) { return true;
 }
{ int32_t _e1490 = (x_1159).n_; for (int32_t i_1161 = 0; i_1161 < _e1490; i_1161++) { if (f224_mentions(f90_kid(t_1157, ((int64_t)(i_1161))), g_1158)) { return true;
 }
 } } _bk1489:; 
return false;
 }
if (((((((k_1160) == (((int64_t)42LL))) || ((k_1160) == (((int64_t)43LL)))) || ((k_1160) == (((int64_t)44LL)))) || ((k_1160) == (((int64_t)48LL)))) || ((k_1160) == (((int64_t)46LL))))) { return f224_mentions(((int64_t)((x_1159).a_)), g_1158);
 }
return false;
}
static int64_t f225_call_block(int64_t n_1163, int64_t inst_1164) {
int64_t fv_1165 = ((int64_t)(((*({ hrv *_t1491 = &(g371); int64_t _i1491 = inst_1164; (S6*)_t1491->b + hr_ix(_i1491, _t1491->n, "hc/calls.amni:284"); }))).blk_)); 
int64_t own_1166 = ((int64_t)(((*({ hrv *_t1492 = &(g371); int64_t _i1492 = inst_1164; (S6*)_t1492->b + hr_ix(_i1492, _t1492->n, "hc/calls.amni:285"); }))).bown_)); 
int64_t s_1167 = f217_ck_args(n_1163, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t na_1168 = ((int64_t)(((*({ hrv *_t1493 = &(g675); int64_t _i1493 = n_1163; (S4*)_t1493->b + hr_ix(_i1493, _t1493->n, "hc/calls.amni:287"); }))).n_)); 
{ int64_t _e1495 = na_1168; for (int64_t j_1169 = 0; j_1169 < _e1495; j_1169++) { int64_t c_1170 = f90_kid(n_1163, j_1169); 
if (f162_is_pending(f140_at(c_1170))) { (*({ hrv *_t1496 = &(g389); int64_t _i1496 = ((int64_t)((int64_t)s_1167 + (int64_t)j_1169)); (int32_t*)_t1496->b + hr_ix(_i1496, _t1496->n, "hc/calls.amni:288"); })) = ((int32_t)(f179_default_t(c_1170)));
 } else { (*({ hrv *_t1497 = &(g389); int64_t _i1497 = ((int64_t)((int64_t)s_1167 + (int64_t)j_1169)); (int32_t*)_t1497->b + hr_ix(_i1497, _t1497->n, "hc/calls.amni:288"); })) = ((int32_t)(f226_deref_val(f140_at(c_1170))));
 }
 } } _bk1494:; 
int64_t bi_1173 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v1499 = &(g371); for (int64_t _k1499 = 0; _k1499 < _v1499->n; _k1499++) { S6 f_1174 = ((S6*)_v1499->b)[_k1499]; int64_t i_1175 = _k1499; if (((((((int64_t)((f_1174).node_))) == (fv_1165)) && ((((int64_t)((f_1174).par_))) == (own_1166))) && (((f_1174).blk_) == (((int32_t)(inst_1164)))))) { bi_1173 = i_1175;
 }
 } } _bk1498:; 
if (((bi_1173) < (((int64_t)0LL)))) { bi_1173 = f105_new_inst(fv_1165, fv_1165, ((int64_t)((*({ hrv *_t1500 = &(g690); int64_t _i1500 = fv_1165; (int32_t*)_t1500->b + hr_ix(_i1500, _t1500->n, "hc/calls.amni:292"); })))), own_1166);
((*({ hrv *_t1501 = &(g371); int64_t _i1501 = bi_1173; (S6*)_t1501->b + hr_ix(_i1501, _t1501->n, "hc/calls.amni:293"); }))).blk_ = ((int32_t)(inst_1164));
((*({ hrv *_t1502 = &(g371); int64_t _i1502 = bi_1173; (S6*)_t1502->b + hr_ix(_i1502, _t1502->n, "hc/calls.amni:293"); }))).bown_ = ((int32_t)(own_1166));
((*({ hrv *_t1503 = &(g371); int64_t _i1503 = bi_1173; (S6*)_t1503->b + hr_ix(_i1503, _t1503->n, "hc/calls.amni:294"); }))).cfn_ = ((int32_t)(g383));
int64_t sa_1176 = g382; 
int64_t sm_1177 = (g373).n; 
int64_t bt_1178 = (g444).n; 
int64_t ld_1179 = g388; 
g382 = bi_1173;
g388 = ((int64_t)0LL);
int64_t np_1180 = ((int64_t)(((*({ hrv *_t1504 = &(g675); int64_t _i1504 = fv_1165; (S4*)_t1504->b + hr_ix(_i1504, _t1504->n, "hc/calls.amni:297"); }))).n_)); 
if (((((uint16_t)((uint64_t)((*({ hrv *_t1505 = &(g675); int64_t _i1505 = fv_1165; (S4*)_t1505->b + hr_ix(_i1505, _t1505->n, "hc/calls.amni:298"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { int64_t _e1507 = np_1180; for (int64_t j_1181 = 0; j_1181 < _e1507; j_1181++) { int64_t p_1182 = f90_kid(fv_1165, j_1181); 
int64_t pt_1183 = ({ int64_t _r1508; if (((j_1181) < (na_1168))) { _r1508 = ((int64_t)((*({ hrv *_t1509 = &(g389); int64_t _i1509 = ((int64_t)((int64_t)s_1167 + (int64_t)j_1181)); (int32_t*)_t1509->b + hr_ix(_i1509, _t1509->n, "hc/calls.amni:298"); }))));  } else { _r1508 = g548;  } _r1508; }); 
int64_t v_1184 = f191_add_lv(((int64_t)(((*({ hrv *_t1510 = &(g675); int64_t _i1510 = p_1182; (S4*)_t1510->b + hr_ix(_i1510, _t1510->n, "hc/calls.amni:298"); }))).s_)), pt_1183, ((int64_t)32LL), p_1182); 
(void)(f168_set_r(p_1182, ((int64_t)1LL), v_1184));
 } } _bk1506:; 
 } else { if (((na_1168) >= (((int64_t)1LL)))) { int64_t v_1185 = f191_add_lv(f8_intern(hr_str("it", 2)), ((int64_t)((*({ hrv *_t1511 = &(g389); int64_t _i1511 = s_1167; (int32_t*)_t1511->b + hr_ix(_i1511, _t1511->n, "hc/calls.amni:299"); })))), ((int64_t)32LL), fv_1165); 
(void)(f168_set_r(fv_1165, ((int64_t)1LL), v_1185));
 }
 }
int64_t body_1186 = ((int64_t)(((*({ hrv *_t1512 = &(g675); int64_t _i1512 = fv_1165; (S4*)_t1512->b + hr_ix(_i1512, _t1512->n, "hc/calls.amni:300"); }))).a_)); 
int64_t bt0_1187 = f136_ck(body_1186, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t rt_1188 = g531; 
if ((((((*({ hrv *_t1513 = &(g675); int64_t _i1513 = body_1186; (S4*)_t1513->b + hr_ix(_i1513, _t1513->n, "hc/calls.amni:303"); }))).a_) >= (((int32_t)0LL))) && ((bt0_1187) != (g531)))) { rt_1188 = ({ int64_t _r1514; if (f162_is_pending(bt0_1187)) { _r1514 = f179_default_t(((int64_t)(((*({ hrv *_t1515 = &(g675); int64_t _i1515 = body_1186; (S4*)_t1515->b + hr_ix(_i1515, _t1515->n, "hc/calls.amni:303"); }))).a_)));  } else { _r1514 = bt0_1187;  } _r1514; });
 }
((*({ hrv *_t1516 = &(g371); int64_t _i1516 = bi_1173; (S6*)_t1516->b + hr_ix(_i1516, _t1516->n, "hc/calls.amni:304"); }))).ret_ = ((int32_t)(rt_1188));
(void)(({ hrv *_v1517 = &(g373); int64_t _k1517 = ((int64_t)((int64_t)(g373).n - (int64_t)sm_1177)); if (_k1517 < 0 || _k1517 > _v1517->n) hr_die("pop_n past the length", "hc/calls.amni:305"); _v1517->n -= _k1517; }));
while ((((g444).n) > (bt_1178))) { (void)(({ hrv *_v1519 = &(g444); if (!_v1519->n) hr_die("pop of an empty array", "hc/calls.amni:305"); ((int32_t*)_v1519->b)[--_v1519->n]; }));
 } _bk1518:; 
g382 = sa_1176;
g388 = ld_1179;
((*({ hrv *_t1520 = &(g371); int64_t _i1520 = bi_1173; (S6*)_t1520->b + hr_ix(_i1520, _t1520->n, "hc/calls.amni:307"); }))).st_ = ((uint8_t)2LL);
 }
{ int64_t _e1522 = na_1168; for (int64_t j_1189 = 0; j_1189 < _e1522; j_1189++) { int64_t c_1190 = f90_kid(n_1163, j_1189); 
if (f162_is_pending(f140_at(c_1190))) { (void)(f179_default_t(c_1190));
 }
 } } _bk1521:; 
(void)(f218_pop_args(s_1167));
(void)(f168_set_r(n_1163, ((int64_t)10LL), bi_1173));
return f137_set_t(n_1163, ((int64_t)(((*({ hrv *_t1523 = &(g371); int64_t _i1523 = bi_1173; (S6*)_t1523->b + hr_ix(_i1523, _t1523->n, "hc/calls.amni:312"); }))).ret_)));
}
static int64_t f226_deref_val(int64_t a_1171) {
int64_t d_1172 = f174_deref(a_1171); 
return ({ int64_t _r1524; if (((((*({ hrv *_t1525 = &(g524); int64_t _i1525 = d_1172; (S1*)_t1525->b + hr_ix(_i1525, _t1525->n, "hc/calls.amni:229"); }))).k_) == (((uint8_t)18LL)))) { _r1524 = g549;  } else { _r1524 = d_1172;  } _r1524; });
}
static int64_t f227_builtin_of(hsl name_1191) {
if (hr_streq(name_1191, hr_str("print", 5))) { return ((int64_t)1LL);
 }
if (hr_streq(name_1191, hr_str("str", 3))) { return ((int64_t)2LL);
 }
if (hr_streq(name_1191, hr_str("format", 6))) { return ((int64_t)3LL);
 }
if (hr_streq(name_1191, hr_str("assert", 6))) { return ((int64_t)4LL);
 }
if (hr_streq(name_1191, hr_str("abort", 5))) { return ((int64_t)5LL);
 }
if (hr_streq(name_1191, hr_str("exit", 4))) { return ((int64_t)6LL);
 }
if (hr_streq(name_1191, hr_str("copy", 4))) { return ((int64_t)7LL);
 }
if (hr_streq(name_1191, hr_str("default", 7))) { return ((int64_t)8LL);
 }
if (hr_streq(name_1191, hr_str("to_bytes", 8))) { return ((int64_t)30LL);
 }
if (hr_streq(name_1191, hr_str("bytes_of", 8))) { return ((int64_t)31LL);
 }
if (hr_streq(name_1191, hr_str("from_bytes", 10))) { return ((int64_t)32LL);
 }
if (hr_streq(name_1191, hr_str("embed_file", 10))) { return ((int64_t)33LL);
 }
if (hr_streq(name_1191, hr_str("len", 3))) { return ((int64_t)9LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f228_user_format(int64_t n_1193) {
if (((((*({ hrv *_t1526 = &(g675); int64_t _i1526 = n_1193; (S4*)_t1526->b + hr_ix(_i1526, _t1526->n, "hc/calls.amni:273"); }))).n_) != (((int32_t)2LL)))) { return false;
 }
int64_t c0_1194 = (g307).n; 
(void)(f229_cands_add(f8_intern(hr_str("format", 6)), f110_ns_of(n_1193)));
bool any_1203 = false; 
{ int64_t _e1528 = (g307).n; for (int64_t ci_1204 = c0_1194; ci_1204 < _e1528; ci_1204++) { if ((!(f230_is_std_node(((int64_t)(((*({ hrv *_t1529 = &(g464); int64_t _i1529 = (*({ hrv *_t1530 = &(g307); int64_t _i1530 = ci_1204; (int32_t*)_t1530->b + hr_ix(_i1530, _t1530->n, "hc/calls.amni:273"); })); (S5*)_t1529->b + hr_ix(_i1529, _t1529->n, "hc/calls.amni:273"); }))).node_)))))) { any_1203 = true;
 }
 } } _bk1527:; 
(void)(({ hrv *_v1531 = &(g307); int64_t _k1531 = ((int64_t)((int64_t)(g307).n - (int64_t)c0_1194)); if (_k1531 < 0 || _k1531 > _v1531->n) hr_die("pop_n past the length", "hc/calls.amni:273"); _v1531->n -= _k1531; }));
return any_1203;
}
static void f229_cands_add(int64_t name_1195, int64_t ns_1196) {
M56 _t1532 = f120_split_q(name_1195); int64_t a_1197 = _t1532.r0; int64_t b_1198 = _t1532.r1; 
if (((a_1197) >= (((int64_t)0LL)))) { int64_t d_1199 = f107_dmap(name_1195); 
while (((d_1199) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1534 = &(g464); int64_t _i1534 = d_1199; (S5*)_t1534->b + hr_ix(_i1534, _t1534->n, "hc/calls.amni:173"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v1535 = &(g307); int32_t _x1535 = ((int32_t)(d_1199)); int32_t *_p1535 = (int32_t*)hr_grow(_v1535, 1, sizeof _x1535); *_p1535 = _x1535; _p1535; }));
 }
d_1199 = ((int64_t)(((*({ hrv *_t1536 = &(g464); int64_t _i1536 = d_1199; (S5*)_t1536->b + hr_ix(_i1536, _t1536->n, "hc/calls.amni:173"); }))).next_));
 } _bk1533:; 
return;
 }
if (((a_1197) == (((int64_t)(0 - (uint64_t)(((int64_t)2LL))))))) { int64_t d_1200 = f107_dmap(b_1198); 
while (((d_1200) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1538 = &(g464); int64_t _i1538 = d_1200; (S5*)_t1538->b + hr_ix(_i1538, _t1538->n, "hc/calls.amni:174"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v1539 = &(g307); int32_t _x1539 = ((int32_t)(d_1200)); int32_t *_p1539 = (int32_t*)hr_grow(_v1539, 1, sizeof _x1539); *_p1539 = _x1539; _p1539; }));
 }
d_1200 = ((int64_t)(((*({ hrv *_t1540 = &(g464); int64_t _i1540 = d_1200; (S5*)_t1540->b + hr_ix(_i1540, _t1540->n, "hc/calls.amni:174"); }))).next_));
 } _bk1537:; 
return;
 }
if (((ns_1196) >= (((int64_t)0LL)))) { int64_t d_1201 = f107_dmap(f98_qual(ns_1196, name_1195)); 
while (((d_1201) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1542 = &(g464); int64_t _i1542 = d_1201; (S5*)_t1542->b + hr_ix(_i1542, _t1542->n, "hc/calls.amni:175"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v1543 = &(g307); int32_t _x1543 = ((int32_t)(d_1201)); int32_t *_p1543 = (int32_t*)hr_grow(_v1543, 1, sizeof _x1543); *_p1543 = _x1543; _p1543; }));
 }
d_1201 = ((int64_t)(((*({ hrv *_t1544 = &(g464); int64_t _i1544 = d_1201; (S5*)_t1544->b + hr_ix(_i1544, _t1544->n, "hc/calls.amni:175"); }))).next_));
 } _bk1541:; 
 }
int64_t d_1202 = f107_dmap(name_1195); 
while (((d_1202) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1546 = &(g464); int64_t _i1546 = d_1202; (S5*)_t1546->b + hr_ix(_i1546, _t1546->n, "hc/calls.amni:177"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v1547 = &(g307); int32_t _x1547 = ((int32_t)(d_1202)); int32_t *_p1547 = (int32_t*)hr_grow(_v1547, 1, sizeof _x1547); *_p1547 = _x1547; _p1547; }));
 }
d_1202 = ((int64_t)(((*({ hrv *_t1548 = &(g464); int64_t _i1548 = d_1202; (S5*)_t1548->b + hr_ix(_i1548, _t1548->n, "hc/calls.amni:177"); }))).next_));
 } _bk1545:; 
}
static bool f230_is_std_node(int64_t node_1205) {
int64_t f_1206 = f111_node_file(node_1205); 
L49 sp_1207 = f100_lib_path(hr_str("std", 3)); 
return hr_streq(f10_nm(((int64_t)(((*({ hrv *_t1549 = &(g884); int64_t _i1549 = f_1206; (S2*)_t1549->b + hr_ix(_i1549, _t1549->n, "hc/calls.amni:179"); }))).name_))), ({ hsl _t1550 = ({ L49 *_t1551 = &(sp_1207); (hsl){ (uint8_t*)_t1551->e, _t1551->n }; }); int64_t _l1550 = 0, _h1550 = _t1550.n; if (_l1550 < 0 || _h1550 < _l1550 || _h1550 > _t1550.n) hr_slerr(_l1550, _h1550, _t1550.n, "hc/calls.amni:179"); (hsl){ _t1550.p + _l1550 * (int64_t)sizeof(uint8_t), _h1550 - _l1550 }; }));
}
static int64_t f231_ck_builtin(int64_t n_1208, int64_t b_1209, int64_t recv_1210, int64_t want_1211) {
S4 x_1212 = (*({ hrv *_t1552 = &(g675); int64_t _i1552 = n_1208; (S4*)_t1552->b + hr_ix(_i1552, _t1552->n, "hc/calls.amni:352"); })); 
(void)(f168_set_r(n_1208, ((int64_t)4LL), b_1209));
(void)(f172_set_x(n_1208, ({ int64_t _r1553; if (((recv_1210) >= (((int64_t)0LL)))) { _r1553 = ((int64_t)1LL);  } else { _r1553 = ((int64_t)0LL);  } _r1553; })));
int64_t na_1213 = ((int64_t)((x_1212).n_)); 

int64_t total_1215 = ((int64_t)((int64_t)na_1213 + (int64_t)({ int64_t _r1554; if (((recv_1210) >= (((int64_t)0LL)))) { _r1554 = ((int64_t)1LL);  } else { _r1554 = ((int64_t)0LL);  } _r1554; }))); 
if ((((b_1209) == (((int64_t)1LL))) || ((b_1209) == (((int64_t)2LL))))) { { int64_t _e1556 = na_1213; for (int64_t i_1216 = 0; i_1216 < _e1556; i_1216++) { int64_t c_1217 = f90_kid(n_1208, i_1216); 
int64_t t_1218 = f136_ck(c_1217, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f162_is_pending(t_1218)) { (void)(f179_default_t(c_1217));
 }
 } } _bk1555:; 
return f137_set_t(n_1208, ({ int64_t _r1557; if (((b_1209) == (((int64_t)2LL)))) { _r1557 = f121_t_arr(g537, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));  } else { _r1557 = g531;  } _r1557; }));
 }
if (((b_1209) == (((int64_t)3LL)))) { int64_t o_1219 = f232_arg(((int64_t)0LL), &recv_1210, &n_1208); 
if (((recv_1210) < (((int64_t)0LL)))) { (void)(f136_ck(o_1219, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
{ int64_t _e1559 = total_1215; for (int64_t i_1220 = ((int64_t)1LL); i_1220 < _e1559; i_1220++) { int64_t c_1221 = f232_arg(i_1220, &recv_1210, &n_1208); 
int64_t t_1222 = f136_ck(c_1221, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f162_is_pending(t_1222)) { (void)(f179_default_t(c_1221));
 }
 } } _bk1558:; 
return f137_set_t(n_1208, g531);
 }
if (((b_1209) == (((int64_t)4LL)))) { (void)(f136_ck(f232_arg(((int64_t)0LL), &recv_1210, &n_1208), g532));
(void)(f139_conv(f232_arg(((int64_t)0LL), &recv_1210, &n_1208), g532));
return f137_set_t(n_1208, g531);
 }
if (((b_1209) == (((int64_t)5LL)))) { int64_t t_1223 = f136_ck(f232_arg(((int64_t)0LL), &recv_1210, &n_1208), g549); 
if (f162_is_pending(t_1223)) { (void)(f179_default_t(f232_arg(((int64_t)0LL), &recv_1210, &n_1208)));
 }
return f137_set_t(n_1208, g531);
 }
if (((b_1209) == (((int64_t)6LL)))) { (void)(f136_ck(f232_arg(((int64_t)0LL), &recv_1210, &n_1208), g536));
(void)(f139_conv(f232_arg(((int64_t)0LL), &recv_1210, &n_1208), g536));
return f137_set_t(n_1208, g531);
 }
if (((b_1209) == (((int64_t)8LL)))) { int64_t ta_1224 = ((int64_t)((x_1212).c_)); 
if (((ta_1224) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1208, hr_str("default needs a type: default<T>()", 34)));
return f137_set_t(n_1208, g548);
 }
return f137_set_t(n_1208, f113_rtype(f90_kid(ta_1224, ((int64_t)0LL)), f110_ns_of(n_1208)));
 }
if (((b_1209) == (((int64_t)7LL)))) { int64_t c_1225 = f232_arg(((int64_t)0LL), &recv_1210, &n_1208); 
if (((recv_1210) < (((int64_t)0LL)))) { (void)(f136_ck(c_1225, want_1211));
 }
int64_t t_1226 = f140_at(c_1225); 
if (f162_is_pending(t_1226)) { t_1226 = f179_default_t(c_1225);
 }
int64_t d_1227 = f174_deref(t_1226); 
int64_t k_1228 = ((int64_t)(((*({ hrv *_t1560 = &(g524); int64_t _i1560 = d_1227; (S1*)_t1560->b + hr_ix(_i1560, _t1560->n, "hc/calls.amni:378"); }))).k_)); 
if (((k_1228) == (((int64_t)9LL)))) { return f137_set_t(n_1208, f121_t_arr(((int64_t)(((*({ hrv *_t1561 = &(g524); int64_t _i1561 = d_1227; (S1*)_t1561->b + hr_ix(_i1561, _t1561->n, "hc/calls.amni:379"); }))).a_)), ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
return f137_set_t(n_1208, d_1227);
 }
if (((b_1209) == (((int64_t)9LL)))) { int64_t c_1229 = f232_arg(((int64_t)0LL), &recv_1210, &n_1208); 
if (((recv_1210) < (((int64_t)0LL)))) { (void)(f136_ck(c_1229, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (((((*({ hrv *_t1562 = &(g524); int64_t _i1562 = f140_at(c_1229); (S1*)_t1562->b + hr_ix(_i1562, _t1562->n, "hc/calls.amni:382"); }))).k_) == (((uint8_t)18LL)))) { (void)(f137_set_t(c_1229, g549));
 }
return f137_set_t(n_1208, g536);
 }
if (((b_1209) == (((int64_t)31LL)))) { int64_t c_1230 = f232_arg(((int64_t)0LL), &recv_1210, &n_1208); 
if (((recv_1210) < (((int64_t)0LL)))) { (void)(f136_ck(c_1230, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (f162_is_pending(f140_at(c_1230))) { (void)(f179_default_t(c_1230));
 }
return f137_set_t(n_1208, g549);
 }
if (((b_1209) == (((int64_t)30LL)))) { int64_t c_1231 = f232_arg(((int64_t)0LL), &recv_1210, &n_1208); 
if (((recv_1210) < (((int64_t)0LL)))) { (void)(f136_ck(c_1231, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (f162_is_pending(f140_at(c_1231))) { (void)(f179_default_t(c_1231));
 }
if (((total_1215) > (((int64_t)1LL)))) { (void)(f136_ck(f232_arg(((int64_t)1LL), &recv_1210, &n_1208), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f137_set_t(n_1208, g531);
 }
return f137_set_t(n_1208, f121_t_arr(g537, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (((b_1209) == (((int64_t)32LL)))) { int64_t ta_1232 = ((int64_t)((x_1212).c_)); 
int64_t t_1233 = ({ int64_t _r1563; if (((ta_1232) >= (((int64_t)0LL)))) { _r1563 = f113_rtype(f90_kid(ta_1232, ((int64_t)0LL)), f110_ns_of(n_1208));  } else { _r1563 = g548;  } _r1563; }); 
(void)(f136_ck(f232_arg(((int64_t)0LL), &recv_1210, &n_1208), g549));
if (f162_is_pending(f140_at(f232_arg(((int64_t)0LL), &recv_1210, &n_1208)))) { (void)(f179_default_t(f232_arg(((int64_t)0LL), &recv_1210, &n_1208)));
 }
return f137_set_t(n_1208, t_1233);
 }
if (((b_1209) == (((int64_t)33LL)))) { (void)(f136_ck(f232_arg(((int64_t)0LL), &recv_1210, &n_1208), g549));
(void)(f179_default_t(f232_arg(((int64_t)0LL), &recv_1210, &n_1208)));
return f137_set_t(n_1208, g549);
 }
int64_t r_1234 = recv_1210; 
int64_t rt_1235 = f174_deref(f140_at(r_1234)); 
int64_t e_1236 = ((int64_t)(((*({ hrv *_t1564 = &(g524); int64_t _i1564 = rt_1235; (S1*)_t1564->b + hr_ix(_i1564, _t1564->n, "hc/calls.amni:389"); }))).a_)); 
if (((b_1209) == (((int64_t)20LL)))) { if (((total_1215) != (((int64_t)2LL)))) { (void)(f108_cerr(n_1208, hr_str("push takes one value", 20)));
return f137_set_t(n_1208, g548);
 }
int64_t c_1237 = f232_arg(((int64_t)1LL), &recv_1210, &n_1208); 
(void)(f136_ck(c_1237, e_1236));
(void)(f139_conv(c_1237, e_1236));
return f137_set_t(n_1208, f117_t_ref(e_1236, ((int64_t)0LL)));
 }
if (((b_1209) == (((int64_t)21LL)))) { int64_t c_1238 = f232_arg(((int64_t)1LL), &recv_1210, &n_1208); 
int64_t t_1239 = f136_ck(c_1238, f18_t_slice(e_1236, true)); 
if (((((*({ hrv *_t1565 = &(g524); int64_t _i1565 = t_1239; (S1*)_t1565->b + hr_ix(_i1565, _t1565->n, "hc/calls.amni:391"); }))).k_) == (((uint8_t)18LL)))) { (void)(f137_set_t(c_1238, g549));
 } else { if (((((*({ hrv *_t1566 = &(g524); int64_t _i1566 = t_1239; (S1*)_t1566->b + hr_ix(_i1566, _t1566->n, "hc/calls.amni:391"); }))).k_) == (((uint8_t)19LL)))) { (void)(f139_conv(c_1238, f121_t_arr(e_1236, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
 } else { int64_t dt_1240 = f174_deref(t_1239); 
if (((((((*({ hrv *_t1567 = &(g524); int64_t _i1567 = dt_1240; (S1*)_t1567->b + hr_ix(_i1567, _t1567->n, "hc/calls.amni:391"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t1568 = &(g524); int64_t _i1568 = dt_1240; (S1*)_t1568->b + hr_ix(_i1568, _t1568->n, "hc/calls.amni:391"); }))).k_) == (((uint8_t)9LL)))) && ((((int64_t)(((*({ hrv *_t1569 = &(g524); int64_t _i1569 = dt_1240; (S1*)_t1569->b + hr_ix(_i1569, _t1569->n, "hc/calls.amni:391"); }))).a_))) != (e_1236)))) { (void)(f108_cerr(c_1238, hr_str("append of a different element type", 34)));
 }
 }
 }
return f137_set_t(n_1208, g531);
 }
if (((b_1209) == (((int64_t)22LL)))) { return f137_set_t(n_1208, e_1236);
 }
if (((b_1209) == (((int64_t)23LL)))) { (void)(f136_ck(f232_arg(((int64_t)1LL), &recv_1210, &n_1208), g536));
(void)(f139_conv(f232_arg(((int64_t)1LL), &recv_1210, &n_1208), g536));
return f137_set_t(n_1208, g531);
 }
if (((b_1209) == (((int64_t)24LL)))) { (void)(f136_ck(f232_arg(((int64_t)1LL), &recv_1210, &n_1208), g536));
(void)(f139_conv(f232_arg(((int64_t)1LL), &recv_1210, &n_1208), g536));
if (((total_1215) > (((int64_t)2LL)))) { (void)(f136_ck(f232_arg(((int64_t)2LL), &recv_1210, &n_1208), e_1236));
(void)(f139_conv(f232_arg(((int64_t)2LL), &recv_1210, &n_1208), e_1236));
 }
return f137_set_t(n_1208, g531);
 }
if (((b_1209) == (((int64_t)25LL)))) { return f137_set_t(n_1208, g531);
 }
if (((b_1209) == (((int64_t)26LL)))) { (void)(f136_ck(f232_arg(((int64_t)1LL), &recv_1210, &n_1208), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f137_set_t(n_1208, g536);
 }
return f137_set_t(n_1208, g548);
}
static int64_t f232_arg(int64_t i_1214, int64_t *c1210, int64_t *c1208) {
return ({ int64_t _r1570; if ((((*c1210)) >= (((int64_t)0LL)))) { _r1570 = ({ int64_t _r1571; if (((i_1214) == (((int64_t)0LL)))) { _r1571 = (*c1210);  } else { _r1571 = f90_kid((*c1208), ((int64_t)((int64_t)i_1214 - (int64_t)((int64_t)1LL))));  } _r1571; });  } else { _r1570 = f90_kid((*c1208), i_1214);  } _r1570; });
}
static int64_t f233_call_fn(int64_t n_1241, int64_t name_1242, int64_t recv_1243, int64_t want_1244) {
int64_t s_1245 = f217_ck_args(n_1241, ((int64_t)0LL), recv_1243); 
int64_t an_1246 = ((int64_t)((int64_t)(g389).n - (int64_t)s_1245)); 
int64_t blk_1247 = ((int64_t)(((*({ hrv *_t1572 = &(g675); int64_t _i1572 = n_1241; (S4*)_t1572->b + hr_ix(_i1572, _t1572->n, "hc/calls.amni:329"); }))).b_)); 
M90 _t1573 = f234_resolve(n_1241, name_1242, f110_ns_of(n_1241), s_1245, an_1246, blk_1247, ((int64_t)(((*({ hrv *_t1574 = &(g675); int64_t _i1574 = n_1241; (S4*)_t1574->b + hr_ix(_i1574, _t1574->n, "hc/calls.amni:330"); }))).c_)), true); int64_t fnode_1323 = _t1573.r0; int64_t b0_1324 = _t1573.r1; int64_t bn_1325 = _t1573.r2; 
if (((fnode_1323) < (((int64_t)0LL)))) { hrv m_1326 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1576 = &(m_1326); hr_fs(_o1576, hr_str("no function ", 12)); hr_fs(_o1576, f10_nm(name_1242)); hr_fs(_o1576, hr_str(" matches (", 10)); }));
{ int64_t _e1578 = an_1246; for (int64_t j_1327 = 0; j_1327 < _e1578; j_1327++) { if (((j_1327) > (((int64_t)0LL)))) { (void)(({ hrv *_v1579 = &(m_1326); hsl _s1579 = hr_str(", ", 2); hr_append(_v1579, _s1579.p, _s1579.n, sizeof(uint8_t)); }));
 }
{ hrv _t1581 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_v1580 = &(m_1326); hsl _s1580 = hr_sl(*hr_tmp(&_t1581, f160_tn(((int64_t)((*({ hrv *_t1582 = &(g389); int64_t _i1582 = ((int64_t)((int64_t)s_1245 + (int64_t)j_1327)); (int32_t*)_t1582->b + hr_ix(_i1582, _t1582->n, "hc/calls.amni:333"); }))))))); hr_append(_v1580, _s1580.p, _s1580.n, sizeof(uint8_t)); }));
}
 } } _bk1577:; 
(void)(({ hrv *_v1583 = &(m_1326); hsl _s1583 = hr_str(")", 1); hr_append(_v1583, _s1583.p, _s1583.n, sizeof(uint8_t)); }));
(void)(f108_cerr(n_1241, hr_sl(m_1326)));
(void)(f218_pop_args(s_1245));
(void)(({ hrv *_v1584 = &(g308); int64_t _k1584 = ((int64_t)((int64_t)(g308).n - (int64_t)b0_1324)); if (_k1584 < 0 || _k1584 > _v1584->n) hr_die("pop_n past the length", "hc/calls.amni:337"); _v1584->n -= _k1584; }));
return f137_set_t(n_1241, g548);
 }
int64_t inst_1342 = f239_get_inst(fnode_1323, b0_1324, bn_1325, blk_1247, g382); 
(void)(({ hrv *_v1585 = &(g308); int64_t _k1585 = ((int64_t)((int64_t)(g308).n - (int64_t)b0_1324)); if (_k1585 < 0 || _k1585 > _v1585->n) hr_die("pop_n past the length", "hc/calls.amni:341"); _v1585->n -= _k1585; }));
{ int64_t _e1587 = an_1246; for (int64_t j_1343 = 0; j_1343 < _e1587; j_1343++) { int64_t c_1344 = ((int64_t)((*({ hrv *_t1588 = &(g310); int64_t _i1588 = ((int64_t)((int64_t)s_1245 + (int64_t)j_1343)); (int32_t*)_t1588->b + hr_ix(_i1588, _t1588->n, "hc/calls.amni:342"); })))); 
int64_t pt_1345 = f201_ptype_of(inst_1342, j_1343); 
if ((((((pt_1345) >= (((int64_t)0LL))) && ((((*({ hrv *_t1589 = &(g524); int64_t _i1589 = pt_1345; (S1*)_t1589->b + hr_ix(_i1589, _t1589->n, "hc/calls.amni:342"); }))).k_) == (((uint8_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1590 = &(g524); int64_t _i1590 = pt_1345; (S1*)_t1590->b + hr_ix(_i1590, _t1590->n, "hc/calls.amni:342"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))) && ((((*({ hrv *_t1591 = &(g524); int64_t _i1591 = pt_1345; (S1*)_t1591->b + hr_ix(_i1591, _t1591->n, "hc/calls.amni:342"); }))).c_) < (((int32_t)0LL))))) { if (f162_is_pending(f140_at(c_1344))) { (void)(f139_conv(c_1344, ((int64_t)(((*({ hrv *_t1592 = &(g524); int64_t _i1592 = pt_1345; (S1*)_t1592->b + hr_ix(_i1592, _t1592->n, "hc/calls.amni:342"); }))).a_))));
 }
 } else { (void)(f139_conv(c_1344, pt_1345));
 }
 } } _bk1586:; 
(void)(f218_pop_args(s_1245));
(void)(f219_note_caps_of(inst_1342));
if (((*({ hrv *_t1593 = &(g371); int64_t _i1593 = inst_1342; (S6*)_t1593->b + hr_ix(_i1593, _t1593->n, "hc/calls.amni:345"); }))).lr_) { ((*({ hrv *_t1594 = &(g371); int64_t _i1594 = g383; (S6*)_t1594->b + hr_ix(_i1594, _t1594->n, "hc/calls.amni:345"); }))).lr_ = true;
 }
(void)(f168_set_r(n_1241, ((int64_t)3LL), inst_1342));
int64_t rt_1346 = ((int64_t)(((*({ hrv *_t1595 = &(g371); int64_t _i1595 = inst_1342; (S6*)_t1595->b + hr_ix(_i1595, _t1595->n, "hc/calls.amni:347"); }))).ret_)); 
if (((rt_1346) < (((int64_t)0LL)))) { if (((((*({ hrv *_t1596 = &(g371); int64_t _i1596 = inst_1342; (S6*)_t1596->b + hr_ix(_i1596, _t1596->n, "hc/calls.amni:348"); }))).st_) == (((uint8_t)1LL)))) { hrv m_1347 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1598 = &(m_1347); hr_fs(_o1598, hr_str("recursive call to ", 18)); hr_fs(_o1598, f10_nm(name_1242)); hr_fs(_o1598, hr_str(" needs its result type written", 30)); }));
(void)(f108_cerr(n_1241, hr_sl(m_1347)));
 }
return f137_set_t(n_1241, g548);
 }
return f137_set_t(n_1241, rt_1346);
}
static M90 f234_resolve(int64_t n_1248, int64_t name_1249, int64_t ns_1250, int64_t a0_1251, int64_t an_1252, int64_t blk_1253, int64_t tyargs_1254, bool report_1255) {
int64_t c0_1256 = (g307).n; 
(void)(f229_cands_add(name_1249, ns_1250));
int64_t best_1257 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
int64_t bestr_1258 = ((int64_t)99LL); 
int64_t bestb0_1259 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
int64_t bestbn_1260 = ((int64_t)0LL); 
bool tie_1261 = false; 
bool bestuser_1262 = false; 
int64_t nb0_1263 = (g308).n; 
{ int64_t _e1600 = (g307).n; for (int64_t ci_1264 = c0_1256; ci_1264 < _e1600; ci_1264++) { int64_t fnode_1265 = ((int64_t)(((*({ hrv *_t1601 = &(g464); int64_t _i1601 = (*({ hrv *_t1602 = &(g307); int64_t _i1602 = ci_1264; (int32_t*)_t1602->b + hr_ix(_i1602, _t1602->n, "hc/calls.amni:186"); })); (S5*)_t1601->b + hr_ix(_i1601, _t1601->n, "hc/calls.amni:186"); }))).node_)); 
int64_t np_1266 = ((int64_t)(((*({ hrv *_t1603 = &(g675); int64_t _i1603 = fnode_1265; (S4*)_t1603->b + hr_ix(_i1603, _t1603->n, "hc/calls.amni:187"); }))).n_)); 
int64_t nreq_1267 = ((int64_t)0LL); 
{ int64_t _e1605 = np_1266; for (int64_t j_1268 = 0; j_1268 < _e1605; j_1268++) { if (((((*({ hrv *_t1606 = &(g675); int64_t _i1606 = f90_kid(fnode_1265, j_1268); (S4*)_t1606->b + hr_ix(_i1606, _t1606->n, "hc/calls.amni:189"); }))).b_) < (((int32_t)0LL)))) { nreq_1267 = ((int64_t)((int64_t)j_1268 + (int64_t)((int64_t)1LL)));
 }
 } } _bk1604:; 
if ((((an_1252) > (np_1266)) || ((an_1252) < (nreq_1267)))) { continue;
 }
int64_t bg_1269 = f221_blk_gen(fnode_1265); 
if ((((((blk_1253) >= (((int64_t)0LL)))) != (((bg_1269) >= (((int64_t)0LL))))) && (!(((((blk_1253) < (((int64_t)0LL))) && ((bg_1269) >= (((int64_t)0LL)))) && ((tyargs_1254) >= (((int64_t)0LL)))))))) { continue;
 }
int64_t b0_1270 = (g308).n; 
int64_t gl_1271 = f222_gen_list(fnode_1265); 
if (((gl_1271) >= (((int64_t)0LL)))) { { int32_t _e1608 = ((*({ hrv *_t1609 = &(g675); int64_t _i1609 = gl_1271; (S4*)_t1609->b + hr_ix(_i1609, _t1609->n, "hc/calls.amni:195"); }))).n_; for (int32_t j_1272 = 0; j_1272 < _e1608; j_1272++) { (void)(({ hrv *_v1610 = &(g308); S7 _x1610 = ((S7){ .name_ = ((*({ hrv *_t1611 = &(g675); int64_t _i1611 = f90_kid(gl_1271, ((int64_t)(j_1272))); (S4*)_t1611->b + hr_ix(_i1611, _t1611->n, "hc/calls.amni:195"); }))).s_, .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }); S7 *_p1610 = (S7*)hr_grow(_v1610, 1, sizeof _x1610); *_p1610 = _x1610; _p1610; }));
 } } _bk1607:; 
 }
{ int64_t _e1613 = np_1266; for (int64_t j_1273 = 0; j_1273 < _e1613; j_1273++) { int64_t p_1274 = f90_kid(fnode_1265, j_1273); 
if (((((*({ hrv *_t1614 = &(g675); int64_t _i1614 = p_1274; (S4*)_t1614->b + hr_ix(_i1614, _t1614->n, "hc/calls.amni:196"); }))).a_) < (((int32_t)0LL)))) { (void)(({ hrv *_v1615 = &(g308); S7 _x1615 = ((S7){ .name_ = ((int32_t)(f196_upname(p_1274))), .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }); S7 *_p1615 = (S7*)hr_grow(_v1615, 1, sizeof _x1615); *_p1615 = _x1615; _p1615; }));
 }
 } } _bk1612:; 
if (((tyargs_1254) >= (((int64_t)0LL)))) { { int64_t _e1617 = f45_min(((int64_t)(((*({ hrv *_t1618 = &(g675); int64_t _i1618 = tyargs_1254; (S4*)_t1618->b + hr_ix(_i1618, _t1618->n, "hc/calls.amni:197"); }))).n_)), ((int64_t)((int64_t)(g308).n - (int64_t)b0_1270))); for (int64_t j_1275 = 0; j_1275 < _e1617; j_1275++) { ((*({ hrv *_t1619 = &(g308); int64_t _i1619 = ((int64_t)((int64_t)b0_1270 + (int64_t)j_1275)); (S7*)_t1619->b + hr_ix(_i1619, _t1619->n, "hc/calls.amni:197"); }))).ty_ = ((int32_t)(f113_rtype(f90_kid(tyargs_1254, j_1275), ns_1250)));
 } } _bk1616:; 
 }
{ int64_t _e1621 = an_1252; for (int64_t j_1276 = 0; j_1276 < _e1621; j_1276++) { int64_t p_1277 = f90_kid(fnode_1265, j_1276); 
int64_t a_1278 = ((int64_t)((*({ hrv *_t1622 = &(g389); int64_t _i1622 = ((int64_t)((int64_t)a0_1251 + (int64_t)j_1276)); (int32_t*)_t1622->b + hr_ix(_i1622, _t1622->n, "hc/calls.amni:198"); })))); 
if ((!(f162_is_pending(a_1278)))) { if (((((*({ hrv *_t1623 = &(g675); int64_t _i1623 = p_1277; (S4*)_t1623->b + hr_ix(_i1623, _t1623->n, "hc/calls.amni:198"); }))).a_) >= (((int32_t)0LL)))) { (void)(f235_match_ty(((int64_t)(((*({ hrv *_t1624 = &(g675); int64_t _i1624 = p_1277; (S4*)_t1624->b + hr_ix(_i1624, _t1624->n, "hc/calls.amni:198"); }))).a_)), a_1278, b0_1270));
 } else { { int64_t _e1626 = (g308).n; for (int64_t q_1290 = b0_1270; q_1290 < _e1626; q_1290++) { if ((((((int64_t)(((*({ hrv *_t1627 = &(g308); int64_t _i1627 = q_1290; (S7*)_t1627->b + hr_ix(_i1627, _t1627->n, "hc/calls.amni:198"); }))).name_))) == (f196_upname(p_1277))) && ((((*({ hrv *_t1628 = &(g308); int64_t _i1628 = q_1290; (S7*)_t1628->b + hr_ix(_i1628, _t1628->n, "hc/calls.amni:198"); }))).ty_) < (((int32_t)0LL))))) { ((*({ hrv *_t1629 = &(g308); int64_t _i1629 = q_1290; (S7*)_t1629->b + hr_ix(_i1629, _t1629->n, "hc/calls.amni:198"); }))).ty_ = ((int32_t)(f226_deref_val(a_1278)));
 }
 } } _bk1625:; 
 }
 }
 } } _bk1620:; 
{ int64_t _e1631 = an_1252; for (int64_t j_1291 = 0; j_1291 < _e1631; j_1291++) { int64_t p_1292 = f90_kid(fnode_1265, j_1291); 
int64_t a_1293 = ((int64_t)((*({ hrv *_t1632 = &(g389); int64_t _i1632 = ((int64_t)((int64_t)a0_1251 + (int64_t)j_1291)); (int32_t*)_t1632->b + hr_ix(_i1632, _t1632->n, "hc/calls.amni:199"); })))); 
if (f162_is_pending(a_1293)) { int64_t dt_1296 = f236_pend_default(a_1293); 
if (((((*({ hrv *_t1633 = &(g675); int64_t _i1633 = p_1292; (S4*)_t1633->b + hr_ix(_i1633, _t1633->n, "hc/calls.amni:199"); }))).a_) >= (((int32_t)0LL)))) { (void)(f235_match_ty(((int64_t)(((*({ hrv *_t1634 = &(g675); int64_t _i1634 = p_1292; (S4*)_t1634->b + hr_ix(_i1634, _t1634->n, "hc/calls.amni:199"); }))).a_)), dt_1296, b0_1270));
 } else { { int64_t _e1636 = (g308).n; for (int64_t q_1297 = b0_1270; q_1297 < _e1636; q_1297++) { if ((((((int64_t)(((*({ hrv *_t1637 = &(g308); int64_t _i1637 = q_1297; (S7*)_t1637->b + hr_ix(_i1637, _t1637->n, "hc/calls.amni:199"); }))).name_))) == (f196_upname(p_1292))) && ((((*({ hrv *_t1638 = &(g308); int64_t _i1638 = q_1297; (S7*)_t1638->b + hr_ix(_i1638, _t1638->n, "hc/calls.amni:199"); }))).ty_) < (((int32_t)0LL))))) { ((*({ hrv *_t1639 = &(g308); int64_t _i1639 = q_1297; (S7*)_t1639->b + hr_ix(_i1639, _t1639->n, "hc/calls.amni:199"); }))).ty_ = ((int32_t)(dt_1296));
 }
 } } _bk1635:; 
 }
 }
 } } _bk1630:; 
bool ok_1298 = true; 
{ int64_t _e1641 = (g308).n; for (int64_t q_1299 = b0_1270; q_1299 < _e1641; q_1299++) { if (((((*({ hrv *_t1642 = &(g308); int64_t _i1642 = q_1299; (S7*)_t1642->b + hr_ix(_i1642, _t1642->n, "hc/calls.amni:201"); }))).ty_) < (((int32_t)0LL)))) { if ((((bg_1269) >= (((int64_t)0LL))) && ((((int64_t)(((*({ hrv *_t1643 = &(g308); int64_t _i1643 = q_1299; (S7*)_t1643->b + hr_ix(_i1643, _t1643->n, "hc/calls.amni:201"); }))).name_))) == (bg_1269)))) { ((*({ hrv *_t1644 = &(g308); int64_t _i1644 = q_1299; (S7*)_t1644->b + hr_ix(_i1644, _t1644->n, "hc/calls.amni:201"); }))).ty_ = ((int32_t)(g551));
 } else { ok_1298 = false;
 }
 }
 } } _bk1640:; 
if ((!(ok_1298))) { (void)(({ hrv *_v1645 = &(g308); int64_t _k1645 = ((int64_t)((int64_t)(g308).n - (int64_t)b0_1270)); if (_k1645 < 0 || _k1645 > _v1645->n) hr_die("pop_n past the length", "hc/calls.amni:202"); _v1645->n -= _k1645; }));
continue;
 }
int64_t g0_1300 = (g466).n; 
{ int64_t _e1647 = (g308).n; for (int64_t q_1301 = b0_1270; q_1301 < _e1647; q_1301++) { (void)(({ hrv *_v1648 = &(g466); S7 _x1648 = (*({ hrv *_t1649 = &(g308); int64_t _i1649 = q_1301; (S7*)_t1649->b + hr_ix(_i1649, _t1649->n, "hc/calls.amni:204"); })); S7 *_p1648 = (S7*)hr_grow(_v1648, 1, sizeof _x1648); *_p1648 = _x1648; _p1648; }));
 } } _bk1646:; 
int64_t fns_1302 = f110_ns_of(fnode_1265); 
int64_t worst_1303 = ((int64_t)0LL); 
{ int64_t _e1651 = an_1252; for (int64_t j_1304 = 0; j_1304 < _e1651; j_1304++) { int64_t p_1305 = f90_kid(fnode_1265, j_1304); 
int64_t pt_1306 = ({ int64_t _r1652; if (((((*({ hrv *_t1653 = &(g675); int64_t _i1653 = p_1305; (S4*)_t1653->b + hr_ix(_i1653, _t1653->n, "hc/calls.amni:209"); }))).a_) >= (((int32_t)0LL)))) { _r1652 = f113_rtype(((int64_t)(((*({ hrv *_t1654 = &(g675); int64_t _i1654 = p_1305; (S4*)_t1654->b + hr_ix(_i1654, _t1654->n, "hc/calls.amni:209"); }))).a_)), fns_1302);  } else { _r1652 = f128_gb_find(f196_upname(p_1305));  } _r1652; }); 
int64_t r_1317 = f237_arg_rank(((int64_t)((*({ hrv *_t1655 = &(g310); int64_t _i1655 = ((int64_t)((int64_t)a0_1251 + (int64_t)j_1304)); (int32_t*)_t1655->b + hr_ix(_i1655, _t1655->n, "hc/calls.amni:210"); })))), ((int64_t)((*({ hrv *_t1656 = &(g389); int64_t _i1656 = ((int64_t)((int64_t)a0_1251 + (int64_t)j_1304)); (int32_t*)_t1656->b + hr_ix(_i1656, _t1656->n, "hc/calls.amni:210"); })))), pt_1306); 
if (((r_1317) < (((int64_t)0LL)))) { worst_1303 = ((int64_t)99LL);
{ goto _bk1650; }
 }
if (((r_1317) > (worst_1303))) { worst_1303 = r_1317;
 }
 } } _bk1650:; 
(void)(({ hrv *_v1657 = &(g466); int64_t _k1657 = ((int64_t)((int64_t)(g466).n - (int64_t)g0_1300)); if (_k1657 < 0 || _k1657 > _v1657->n) hr_die("pop_n past the length", "hc/calls.amni:214"); _v1657->n -= _k1657; }));
if ((((worst_1303) < (((int64_t)2LL))) && (((gl_1271) >= (((int64_t)0LL))) || (((np_1266) > (((int64_t)0LL))) && f238_untyped_any(fnode_1265))))) { worst_1303 = f103_max(worst_1303, ((int64_t)1LL));
 }
if (((worst_1303) == (((int64_t)99LL)))) { (void)(({ hrv *_v1658 = &(g308); int64_t _k1658 = ((int64_t)((int64_t)(g308).n - (int64_t)b0_1270)); if (_k1658 < 0 || _k1658 > _v1658->n) hr_die("pop_n past the length", "hc/calls.amni:216"); _v1658->n -= _k1658; }));
continue;
 }
bool user_1320 = (!(f230_is_std_node(fnode_1265))); 
if ((((worst_1303) < (bestr_1258)) || ((((worst_1303) == (bestr_1258)) && user_1320) && (!(bestuser_1262))))) { best_1257 = fnode_1265;
bestr_1258 = worst_1303;
bestb0_1259 = b0_1270;
bestbn_1260 = ((int64_t)((int64_t)(g308).n - (int64_t)b0_1270));
tie_1261 = false;
bestuser_1262 = user_1320;
 } else { if ((((worst_1303) == (bestr_1258)) && ((user_1320) == (bestuser_1262)))) { tie_1261 = true;
 }
 }
 } } _bk1599:; 
(void)(({ hrv *_v1659 = &(g307); int64_t _k1659 = ((int64_t)((int64_t)(g307).n - (int64_t)c0_1256)); if (_k1659 < 0 || _k1659 > _v1659->n) hr_die("pop_n past the length", "hc/calls.amni:221"); _v1659->n -= _k1659; }));
if (((best_1257) < (((int64_t)0LL)))) { (void)(({ hrv *_v1660 = &(g308); int64_t _k1660 = ((int64_t)((int64_t)(g308).n - (int64_t)nb0_1263)); if (_k1660 < 0 || _k1660 > _v1660->n) hr_die("pop_n past the length", "hc/calls.amni:222"); _v1660->n -= _k1660; }));
return (M90){ ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)0LL), ((int64_t)0LL) };
 }
if ((tie_1261 && report_1255)) { hrv m_1321 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1662 = &(m_1321); hr_fs(_o1662, hr_str("ambiguous call to ", 18)); hr_fs(_o1662, f10_nm(name_1249)); }));
(void)(f108_cerr(n_1248, hr_sl(m_1321)));
 }
if (((bestb0_1259) > (nb0_1263))) { { int64_t _e1664 = bestbn_1260; for (int64_t q_1322 = ((int64_t)0LL); q_1322 < _e1664; q_1322++) { (*({ hrv *_t1665 = &(g308); int64_t _i1665 = ((int64_t)((int64_t)nb0_1263 + (int64_t)q_1322)); (S7*)_t1665->b + hr_ix(_i1665, _t1665->n, "hc/calls.amni:224"); })) = (*({ hrv *_t1666 = &(g308); int64_t _i1666 = ((int64_t)((int64_t)bestb0_1259 + (int64_t)q_1322)); (S7*)_t1666->b + hr_ix(_i1666, _t1666->n, "hc/calls.amni:224"); }));
 } } _bk1663:; 
 }
(void)(({ hrv *_v1667 = &(g308); int64_t _k1667 = ((int64_t)((int64_t)((int64_t)((int64_t)(g308).n - (int64_t)nb0_1263)) - (int64_t)bestbn_1260)); if (_k1667 < 0 || _k1667 > _v1667->n) hr_die("pop_n past the length", "hc/calls.amni:225"); _v1667->n -= _k1667; }));
return (M90){ best_1257, nb0_1263, bestbn_1260 };
}
static bool f235_match_ty(int64_t tn0_1279, int64_t t0_1280, int64_t g0_1281) {
if (((tn0_1279) < (((int64_t)0LL)))) { return true;
 }
S4 x_1282 = (*({ hrv *_t1668 = &(g675); int64_t _i1668 = tn0_1279; (S4*)_t1668->b + hr_ix(_i1668, _t1668->n, "hc/calls.amni:46"); })); 
int64_t k_1283 = ((int64_t)((x_1282).k_)); 
int64_t t_1284 = f174_deref(t0_1280); 
if (((k_1283) == (((int64_t)41LL)))) { if ((((x_1282).n_) == (((int32_t)0LL)))) { { int64_t _e1670 = (g308).n; for (int64_t i_1285 = g0_1281; i_1285 < _e1670; i_1285++) { if (((((*({ hrv *_t1671 = &(g308); int64_t _i1671 = i_1285; (S7*)_t1671->b + hr_ix(_i1671, _t1671->n, "hc/calls.amni:50"); }))).name_) == ((x_1282).s_))) { if (((((*({ hrv *_t1672 = &(g308); int64_t _i1672 = i_1285; (S7*)_t1672->b + hr_ix(_i1672, _t1672->n, "hc/calls.amni:50"); }))).ty_) < (((int32_t)0LL)))) { ((*({ hrv *_t1673 = &(g308); int64_t _i1673 = i_1285; (S7*)_t1673->b + hr_ix(_i1673, _t1673->n, "hc/calls.amni:50"); }))).ty_ = ((int32_t)(t_1284));
 }
return true;
 }
 } } _bk1669:; 
return true;
 }
if (((((*({ hrv *_t1674 = &(g524); int64_t _i1674 = t_1284; (S1*)_t1674->b + hr_ix(_i1674, _t1674->n, "hc/calls.amni:53"); }))).k_) == (((uint8_t)5LL)))) { int64_t si_1286 = ((int64_t)(((*({ hrv *_t1675 = &(g524); int64_t _i1675 = t_1284; (S1*)_t1675->b + hr_ix(_i1675, _t1675->n, "hc/calls.amni:53"); }))).a_)); 
if (((((*({ hrv *_t1676 = &(g527); int64_t _i1676 = si_1286; (S10*)_t1676->b + hr_ix(_i1676, _t1676->n, "hc/calls.amni:53"); }))).tn_) == ((x_1282).n_))) { { int32_t _e1678 = (x_1282).n_; for (int32_t i_1287 = 0; i_1287 < _e1678; i_1287++) { (void)(f235_match_ty(f90_kid(tn0_1279, ((int64_t)(i_1287))), ((int64_t)((*({ hrv *_t1679 = &(g525); int64_t _i1679 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1680 = &(g527); int64_t _i1680 = si_1286; (S10*)_t1680->b + hr_ix(_i1680, _t1680->n, "hc/calls.amni:53"); }))).ta_)) + (int64_t)((int64_t)(i_1287)))); (int32_t*)_t1679->b + hr_ix(_i1679, _t1679->n, "hc/calls.amni:53"); })))), g0_1281));
 } } _bk1677:; 
 }
 }
if (((((*({ hrv *_t1681 = &(g524); int64_t _i1681 = t_1284; (S1*)_t1681->b + hr_ix(_i1681, _t1681->n, "hc/calls.amni:54"); }))).k_) == (((uint8_t)6LL)))) { int64_t ei_1288 = ((int64_t)(((*({ hrv *_t1682 = &(g524); int64_t _i1682 = t_1284; (S1*)_t1682->b + hr_ix(_i1682, _t1682->n, "hc/calls.amni:54"); }))).a_)); 
if (((((*({ hrv *_t1683 = &(g529); int64_t _i1683 = ei_1288; (S8*)_t1683->b + hr_ix(_i1683, _t1683->n, "hc/calls.amni:54"); }))).tn_) == ((x_1282).n_))) { { int32_t _e1685 = (x_1282).n_; for (int32_t i_1289 = 0; i_1289 < _e1685; i_1289++) { (void)(f235_match_ty(f90_kid(tn0_1279, ((int64_t)(i_1289))), ((int64_t)((*({ hrv *_t1686 = &(g525); int64_t _i1686 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1687 = &(g529); int64_t _i1687 = ei_1288; (S8*)_t1687->b + hr_ix(_i1687, _t1687->n, "hc/calls.amni:54"); }))).ta_)) + (int64_t)((int64_t)(i_1289)))); (int32_t*)_t1686->b + hr_ix(_i1686, _t1686->n, "hc/calls.amni:54"); })))), g0_1281));
 } } _bk1684:; 
 }
 }
return true;
 }
if ((((k_1283) == (((int64_t)42LL))) || ((k_1283) == (((int64_t)43LL))))) { if ((((((*({ hrv *_t1688 = &(g524); int64_t _i1688 = t_1284; (S1*)_t1688->b + hr_ix(_i1688, _t1688->n, "hc/calls.amni:57"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t1689 = &(g524); int64_t _i1689 = t_1284; (S1*)_t1689->b + hr_ix(_i1689, _t1689->n, "hc/calls.amni:57"); }))).k_) == (((uint8_t)9LL))))) { return f235_match_ty(((int64_t)((x_1282).a_)), ((int64_t)(((*({ hrv *_t1690 = &(g524); int64_t _i1690 = t_1284; (S1*)_t1690->b + hr_ix(_i1690, _t1690->n, "hc/calls.amni:57"); }))).a_)), g0_1281);
 }
if (((((*({ hrv *_t1691 = &(g524); int64_t _i1691 = t_1284; (S1*)_t1691->b + hr_ix(_i1691, _t1691->n, "hc/calls.amni:57"); }))).k_) == (((uint8_t)18LL)))) { return f235_match_ty(((int64_t)((x_1282).a_)), g537, g0_1281);
 }
return true;
 }
if (((k_1283) == (((int64_t)44LL)))) { if (((((*({ hrv *_t1692 = &(g524); int64_t _i1692 = t0_1280; (S1*)_t1692->b + hr_ix(_i1692, _t1692->n, "hc/calls.amni:58"); }))).k_) == (((uint8_t)10LL)))) { return f235_match_ty(((int64_t)((x_1282).a_)), ((int64_t)(((*({ hrv *_t1693 = &(g524); int64_t _i1693 = t0_1280; (S1*)_t1693->b + hr_ix(_i1693, _t1693->n, "hc/calls.amni:58"); }))).a_)), g0_1281);
 }
return f235_match_ty(((int64_t)((x_1282).a_)), t_1284, g0_1281);
 }
if (((k_1283) == (((int64_t)48LL)))) { return f235_match_ty(((int64_t)((x_1282).a_)), t0_1280, g0_1281);
 }
return true;
}
static int64_t f236_pend_default(int64_t a_1294) {
int64_t k_1295 = ((int64_t)(((*({ hrv *_t1694 = &(g524); int64_t _i1694 = a_1294; (S1*)_t1694->b + hr_ix(_i1694, _t1694->n, "hc/calls.amni:230"); }))).k_)); 
return ({ int64_t _r1695; if (((k_1295) == (((int64_t)12LL)))) { _r1695 = g536;  } else { _r1695 = ({ int64_t _r1696; if (((k_1295) == (((int64_t)13LL)))) { _r1696 = g542;  } else { _r1696 = ({ int64_t _r1697; if (((k_1295) == (((int64_t)18LL)))) { _r1697 = g549;  } else { _r1697 = a_1294;  } _r1697; });  } _r1696; });  } _r1695; });
}
static int64_t f237_arg_rank(int64_t n_1307, int64_t a_1308, int64_t p_1309) {
if (((p_1309) < (((int64_t)0LL)))) { return ((int64_t)1LL);
 }
if (((a_1308) == (p_1309))) { return ((int64_t)0LL);
 }
int64_t ak_1310 = ((int64_t)(((*({ hrv *_t1698 = &(g524); int64_t _i1698 = a_1308; (S1*)_t1698->b + hr_ix(_i1698, _t1698->n, "hc/calls.amni:65"); }))).k_)); 
int64_t pk_1311 = ((int64_t)(((*({ hrv *_t1699 = &(g524); int64_t _i1699 = p_1309; (S1*)_t1699->b + hr_ix(_i1699, _t1699->n, "hc/calls.amni:65"); }))).k_)); 
if ((((pk_1311) == (((int64_t)0LL))) || ((ak_1310) == (((int64_t)0LL))))) { return ((int64_t)0LL);
 }
if (((((pk_1311) == (((int64_t)10LL))) && ((((*({ hrv *_t1700 = &(g524); int64_t _i1700 = p_1309; (S1*)_t1700->b + hr_ix(_i1700, _t1700->n, "hc/calls.amni:67"); }))).c_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1701 = &(g524); int64_t _i1701 = p_1309; (S1*)_t1701->b + hr_ix(_i1701, _t1701->n, "hc/calls.amni:67"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL))))) { int64_t tgt_1312 = ((int64_t)(((*({ hrv *_t1702 = &(g524); int64_t _i1702 = p_1309; (S1*)_t1702->b + hr_ix(_i1702, _t1702->n, "hc/calls.amni:67"); }))).a_)); 
if (((f174_deref(a_1308)) == (tgt_1312))) { return ((int64_t)0LL);
 }
if ((((ak_1310) == (((int64_t)12LL))) || ((ak_1310) == (((int64_t)13LL))))) { return f237_arg_rank(n_1307, a_1308, tgt_1312);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if ((((ak_1310) == (((int64_t)10LL))) && ((((*({ hrv *_t1703 = &(g524); int64_t _i1703 = a_1308; (S1*)_t1703->b + hr_ix(_i1703, _t1703->n, "hc/calls.amni:68"); }))).c_) < (((int32_t)0LL))))) { int64_t d_1313 = ((int64_t)(((*({ hrv *_t1704 = &(g524); int64_t _i1704 = a_1308; (S1*)_t1704->b + hr_ix(_i1704, _t1704->n, "hc/calls.amni:68"); }))).a_)); 
if (((d_1313) == (p_1309))) { return ((int64_t)0LL);
 }
if (((((pk_1311) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1705 = &(g524); int64_t _i1705 = p_1309; (S1*)_t1705->b + hr_ix(_i1705, _t1705->n, "hc/calls.amni:68"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && ((((*({ hrv *_t1706 = &(g524); int64_t _i1706 = p_1309; (S1*)_t1706->b + hr_ix(_i1706, _t1706->n, "hc/calls.amni:68"); }))).a_) == (((*({ hrv *_t1707 = &(g524); int64_t _i1707 = a_1308; (S1*)_t1707->b + hr_ix(_i1707, _t1707->n, "hc/calls.amni:68"); }))).a_)))) { return ((int64_t)0LL);
 }
return f237_arg_rank(n_1307, d_1313, p_1309);
 }
if (((ak_1310) == (((int64_t)12LL)))) { M77 _t1708 = f154_cval(n_1307); int64_t v_1314 = _t1708.r0; bool u_1315 = _t1708.r1; bool ok_1316 = _t1708.r2; 
if (((pk_1311) == (((int64_t)3LL)))) { if (((!(ok_1316)) || f157_int_fits(v_1314, u_1315, p_1309))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((pk_1311) == (((int64_t)4LL)))) { return ((int64_t)3LL);
 }
if (((pk_1311) == (((int64_t)17LL)))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1310) == (((int64_t)13LL)))) { if (((pk_1311) == (((int64_t)4LL)))) { return ({ int64_t _r1709; if (((((*({ hrv *_t1710 = &(g524); int64_t _i1710 = p_1309; (S1*)_t1710->b + hr_ix(_i1710, _t1710->n, "hc/calls.amni:76"); }))).s_) == (((uint8_t)8LL)))) { _r1709 = ((int64_t)1LL);  } else { _r1709 = ((int64_t)2LL);  } _r1709; });
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1310) == (((int64_t)18LL)))) { if ((((pk_1311) == (((int64_t)9LL))) && ((((int64_t)(((*({ hrv *_t1711 = &(g524); int64_t _i1711 = p_1309; (S1*)_t1711->b + hr_ix(_i1711, _t1711->n, "hc/calls.amni:77"); }))).a_))) == (g537)))) { return ((int64_t)0LL);
 }
if (f163_is_byte_arr(p_1309)) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1310) == (((int64_t)19LL)))) { if ((((pk_1311) == (((int64_t)8LL))) || ((pk_1311) == (((int64_t)9LL))))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1310) == (((int64_t)11LL)))) { if ((((pk_1311) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1712 = &(g524); int64_t _i1712 = p_1309; (S1*)_t1712->b + hr_ix(_i1712, _t1712->n, "hc/calls.amni:79"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { return ((int64_t)0LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((((pk_1311) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1713 = &(g524); int64_t _i1713 = p_1309; (S1*)_t1713->b + hr_ix(_i1713, _t1713->n, "hc/calls.amni:80"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && ((((int64_t)(((*({ hrv *_t1714 = &(g524); int64_t _i1714 = p_1309; (S1*)_t1714->b + hr_ix(_i1714, _t1714->n, "hc/calls.amni:80"); }))).a_))) == (a_1308)))) { return ((int64_t)0LL);
 }
if ((((ak_1310) == (((int64_t)3LL))) && ((pk_1311) == (((int64_t)4LL))))) { return ((int64_t)3LL);
 }
if (f150_widens(a_1308, p_1309)) { return ((int64_t)2LL);
 }
if (((((pk_1311) == (((int64_t)9LL))) && (((ak_1310) == (((int64_t)8LL))) || ((ak_1310) == (((int64_t)9LL))))) && ((((*({ hrv *_t1715 = &(g524); int64_t _i1715 = a_1308; (S1*)_t1715->b + hr_ix(_i1715, _t1715->n, "hc/calls.amni:83"); }))).a_) == (((*({ hrv *_t1716 = &(g524); int64_t _i1716 = p_1309; (S1*)_t1716->b + hr_ix(_i1716, _t1716->n, "hc/calls.amni:83"); }))).a_)))) { return ((int64_t)2LL);
 }
if (((((pk_1311) == (((int64_t)6LL))) && ((ak_1310) == (((int64_t)7LL)))) && ((((*({ hrv *_t1717 = &(g524); int64_t _i1717 = a_1308; (S1*)_t1717->b + hr_ix(_i1717, _t1717->n, "hc/calls.amni:84"); }))).a_) == (((*({ hrv *_t1718 = &(g524); int64_t _i1718 = p_1309; (S1*)_t1718->b + hr_ix(_i1718, _t1718->n, "hc/calls.amni:84"); }))).a_)))) { return ((int64_t)2LL);
 }
if ((((((pk_1311) == (((int64_t)8LL))) && (((ak_1310) == (((int64_t)8LL))) || ((ak_1310) == (((int64_t)9LL))))) && ((((*({ hrv *_t1719 = &(g524); int64_t _i1719 = a_1308; (S1*)_t1719->b + hr_ix(_i1719, _t1719->n, "hc/calls.amni:85"); }))).a_) == (((*({ hrv *_t1720 = &(g524); int64_t _i1720 = p_1309; (S1*)_t1720->b + hr_ix(_i1720, _t1720->n, "hc/calls.amni:85"); }))).a_))) && f153_is_construct(n_1307))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f238_untyped_any(int64_t f_1318) {
{ int32_t _e1722 = ((*({ hrv *_t1723 = &(g675); int64_t _i1723 = f_1318; (S4*)_t1723->b + hr_ix(_i1723, _t1723->n, "hc/calls.amni:228"); }))).n_; for (int32_t j_1319 = 0; j_1319 < _e1722; j_1319++) { if (((((*({ hrv *_t1724 = &(g675); int64_t _i1724 = f90_kid(f_1318, ((int64_t)(j_1319))); (S4*)_t1724->b + hr_ix(_i1724, _t1724->n, "hc/calls.amni:228"); }))).a_) < (((int32_t)0LL)))) { return true;
 }
 } } _bk1721:; 
return false;
}
static int64_t f239_get_inst(int64_t node_1328, int64_t b0_1329, int64_t bn_1330, int64_t blk_1331, int64_t bown_1332) {
int64_t par_1333 = ({ int64_t _r1725; if (((((uint16_t)((uint64_t)((*({ hrv *_t1726 = &(g675); int64_t _i1726 = node_1328; (S4*)_t1726->b + hr_ix(_i1726, _t1726->n, "hc/calls.amni:160"); }))).fl_ & (uint64_t)((uint16_t)128LL)))) != (((uint16_t)0LL)))) { _r1725 = g382;  } else { _r1725 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1725; }); 
if (((blk_1331) < (((int64_t)0LL)))) { { hrv *_v1728 = &(g371); for (int64_t _k1728 = 0; _k1728 < _v1728->n; _k1728++) { S6 f_1334 = ((S6*)_v1728->b)[_k1728]; int64_t i_1335 = _k1728; if ((((((((int64_t)((f_1334).node_))) == (node_1328)) && (((f_1334).blk_) < (((int32_t)0LL)))) && ((((int64_t)((f_1334).par_))) == (par_1333))) && f240_same_binds(i_1335, b0_1329, bn_1330))) { return i_1335;
 }
 } } _bk1727:; 
 }
int64_t i_1340 = f105_new_inst(node_1328, node_1328, ((int64_t)((*({ hrv *_t1729 = &(g690); int64_t _i1729 = node_1328; (int32_t*)_t1729->b + hr_ix(_i1729, _t1729->n, "hc/calls.amni:162"); })))), par_1333); 
((*({ hrv *_t1730 = &(g371); int64_t _i1730 = i_1340; (S6*)_t1730->b + hr_ix(_i1730, _t1730->n, "hc/calls.amni:163"); }))).g0_ = ((int32_t)((g375).n));
{ int64_t _e1732 = bn_1330; for (int64_t j_1341 = 0; j_1341 < _e1732; j_1341++) { (void)(({ hrv *_v1733 = &(g375); S7 _x1733 = (*({ hrv *_t1734 = &(g308); int64_t _i1734 = ((int64_t)((int64_t)b0_1329 + (int64_t)j_1341)); (S7*)_t1734->b + hr_ix(_i1734, _t1734->n, "hc/calls.amni:164"); })); S7 *_p1733 = (S7*)hr_grow(_v1733, 1, sizeof _x1733); *_p1733 = _x1733; _p1733; }));
 } } _bk1731:; 
((*({ hrv *_t1735 = &(g371); int64_t _i1735 = i_1340; (S6*)_t1735->b + hr_ix(_i1735, _t1735->n, "hc/calls.amni:165"); }))).gn_ = ((int32_t)(bn_1330));
((*({ hrv *_t1736 = &(g371); int64_t _i1736 = i_1340; (S6*)_t1736->b + hr_ix(_i1736, _t1736->n, "hc/calls.amni:166"); }))).blk_ = ((int32_t)(blk_1331));
((*({ hrv *_t1737 = &(g371); int64_t _i1737 = i_1340; (S6*)_t1737->b + hr_ix(_i1737, _t1737->n, "hc/calls.amni:166"); }))).bown_ = ((int32_t)(bown_1332));
(void)(f195_sig_inst(i_1340));
(void)(f200_check_inst(i_1340));
return i_1340;
}
static bool f240_same_binds(int64_t i_1336, int64_t b0_1337, int64_t bn_1338) {
if (((((int64_t)(((*({ hrv *_t1738 = &(g371); int64_t _i1738 = i_1336; (S6*)_t1738->b + hr_ix(_i1738, _t1738->n, "hc/calls.amni:155"); }))).gn_))) != (bn_1338))) { return false;
 }
{ int64_t _e1740 = bn_1338; for (int64_t j_1339 = 0; j_1339 < _e1740; j_1339++) { if ((((((*({ hrv *_t1741 = &(g375); int64_t _i1741 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1742 = &(g371); int64_t _i1742 = i_1336; (S6*)_t1742->b + hr_ix(_i1742, _t1742->n, "hc/calls.amni:156"); }))).g0_)) + (int64_t)j_1339)); (S7*)_t1741->b + hr_ix(_i1741, _t1741->n, "hc/calls.amni:156"); }))).ty_) != (((*({ hrv *_t1743 = &(g308); int64_t _i1743 = ((int64_t)((int64_t)b0_1337 + (int64_t)j_1339)); (S7*)_t1743->b + hr_ix(_i1743, _t1743->n, "hc/calls.amni:156"); }))).ty_)) || ((((*({ hrv *_t1744 = &(g375); int64_t _i1744 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1745 = &(g371); int64_t _i1745 = i_1336; (S6*)_t1745->b + hr_ix(_i1745, _t1745->n, "hc/calls.amni:156"); }))).g0_)) + (int64_t)j_1339)); (S7*)_t1744->b + hr_ix(_i1744, _t1744->n, "hc/calls.amni:156"); }))).name_) != (((*({ hrv *_t1746 = &(g308); int64_t _i1746 = ((int64_t)((int64_t)b0_1337 + (int64_t)j_1339)); (S7*)_t1746->b + hr_ix(_i1746, _t1746->n, "hc/calls.amni:156"); }))).name_)))) { return false;
 }
 } } _bk1739:; 
return true;
}
static int64_t f241_member_of(hsl name_1352) {
if (hr_streq(name_1352, hr_str("push", 4))) { return ((int64_t)20LL);
 }
if (hr_streq(name_1352, hr_str("append", 6))) { return ((int64_t)21LL);
 }
if (hr_streq(name_1352, hr_str("pop", 3))) { return ((int64_t)22LL);
 }
if (hr_streq(name_1352, hr_str("pop_n", 5))) { return ((int64_t)23LL);
 }
if (hr_streq(name_1352, hr_str("resize", 6))) { return ((int64_t)24LL);
 }
if (hr_streq(name_1352, hr_str("clear", 5))) { return ((int64_t)25LL);
 }
if (hr_streq(name_1352, hr_str("index_of", 8))) { return ((int64_t)26LL);
 }
if (hr_streq(name_1352, hr_str("len", 3))) { return ((int64_t)9LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f242_ck_slit(int64_t n_1355, int64_t want_1356) {
S4 x_1357 = (*({ hrv *_t1747 = &(g675); int64_t _i1747 = n_1355; (S4*)_t1747->b + hr_ix(_i1747, _t1747->n, "hc/calls.amni:400"); })); 
int64_t tnode_1358 = ((int64_t)((x_1357).a_)); 
int64_t ns_1359 = f110_ns_of(n_1355); 
int64_t t_1360 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((((*({ hrv *_t1748 = &(g675); int64_t _i1748 = tnode_1358; (S4*)_t1748->b + hr_ix(_i1748, _t1748->n, "hc/calls.amni:404"); }))).k_) == (((uint8_t)41LL))) && ((((*({ hrv *_t1749 = &(g675); int64_t _i1749 = tnode_1358; (S4*)_t1749->b + hr_ix(_i1749, _t1749->n, "hc/calls.amni:404"); }))).n_) == (((int32_t)0LL)))) && ((f128_gb_find(((int64_t)(((*({ hrv *_t1750 = &(g675); int64_t _i1750 = tnode_1358; (S4*)_t1750->b + hr_ix(_i1750, _t1750->n, "hc/calls.amni:404"); }))).s_)))) < (((int64_t)0LL))))) { int64_t d_1361 = f119_lookup_q(((int64_t)(((*({ hrv *_t1751 = &(g675); int64_t _i1751 = tnode_1358; (S4*)_t1751->b + hr_ix(_i1751, _t1751->n, "hc/calls.amni:405"); }))).s_)), ns_1359, ((int64_t)1LL)); 
if ((((d_1361) >= (((int64_t)0LL))) && ((((*({ hrv *_t1752 = &(g675); int64_t _i1752 = ((*({ hrv *_t1753 = &(g464); int64_t _i1753 = d_1361; (S5*)_t1753->b + hr_ix(_i1753, _t1753->n, "hc/calls.amni:406"); }))).node_; (S4*)_t1752->b + hr_ix(_i1752, _t1752->n, "hc/calls.amni:406"); }))).d_) >= (((int32_t)0LL))))) { if (((((want_1356) >= (((int64_t)0LL))) && ((((*({ hrv *_t1754 = &(g524); int64_t _i1754 = want_1356; (S1*)_t1754->b + hr_ix(_i1754, _t1754->n, "hc/calls.amni:406"); }))).k_) == (((uint8_t)5LL)))) && ((((*({ hrv *_t1755 = &(g527); int64_t _i1755 = ((*({ hrv *_t1756 = &(g524); int64_t _i1756 = want_1356; (S1*)_t1756->b + hr_ix(_i1756, _t1756->n, "hc/calls.amni:406"); }))).a_; (S10*)_t1755->b + hr_ix(_i1755, _t1755->n, "hc/calls.amni:406"); }))).node_) == (((*({ hrv *_t1757 = &(g464); int64_t _i1757 = d_1361; (S5*)_t1757->b + hr_ix(_i1757, _t1757->n, "hc/calls.amni:406"); }))).node_)))) { t_1360 = want_1356;
 }
 }
 }
if (((t_1360) < (((int64_t)0LL)))) { t_1360 = f113_rtype(tnode_1358, ns_1359);
 }
int64_t si_1362 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((*({ hrv *_t1758 = &(g524); int64_t _i1758 = t_1360; (S1*)_t1758->b + hr_ix(_i1758, _t1758->n, "hc/calls.amni:410"); }))).k_) == (((uint8_t)5LL)))) { si_1362 = ((int64_t)(((*({ hrv *_t1759 = &(g524); int64_t _i1759 = t_1360; (S1*)_t1759->b + hr_ix(_i1759, _t1759->n, "hc/calls.amni:410"); }))).a_));
 }
if (((((*({ hrv *_t1760 = &(g524); int64_t _i1760 = t_1360; (S1*)_t1760->b + hr_ix(_i1760, _t1760->n, "hc/calls.amni:411"); }))).k_) == (((uint8_t)7LL)))) { si_1362 = ((int64_t)(((*({ hrv *_t1761 = &(g530); int64_t _i1761 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1762 = &(g529); int64_t _i1762 = ((*({ hrv *_t1763 = &(g524); int64_t _i1763 = t_1360; (S1*)_t1763->b + hr_ix(_i1763, _t1763->n, "hc/calls.amni:411"); }))).a_; (S8*)_t1762->b + hr_ix(_i1762, _t1762->n, "hc/calls.amni:411"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t1764 = &(g524); int64_t _i1764 = t_1360; (S1*)_t1764->b + hr_ix(_i1764, _t1764->n, "hc/calls.amni:411"); }))).c_)))); (S9*)_t1761->b + hr_ix(_i1761, _t1761->n, "hc/calls.amni:411"); }))).si_));
 }
if (((si_1362) < (((int64_t)0LL)))) { if (((((*({ hrv *_t1765 = &(g524); int64_t _i1765 = t_1360; (S1*)_t1765->b + hr_ix(_i1765, _t1765->n, "hc/calls.amni:412"); }))).k_) != (((uint8_t)0LL)))) { (void)(f108_cerr(n_1355, hr_str("not a struct type", 17)));
 }
return f137_set_t(n_1355, g548);
 }
int64_t nf_1363 = ((int64_t)(((*({ hrv *_t1766 = &(g527); int64_t _i1766 = si_1362; (S10*)_t1766->b + hr_ix(_i1766, _t1766->n, "hc/calls.amni:413"); }))).fnum_)); 
bool named_1364 = ((((x_1357).n_) > (((int32_t)0LL))) && ((((*({ hrv *_t1767 = &(g675); int64_t _i1767 = f90_kid(n_1355, ((int64_t)0LL)); (S4*)_t1767->b + hr_ix(_i1767, _t1767->n, "hc/calls.amni:414"); }))).s_) >= (((int32_t)0LL)))); 
int64_t fpos_1365 = ((int64_t)0LL); 
{ int32_t _e1769 = (x_1357).n_; for (int32_t i_1366 = 0; i_1366 < _e1769; i_1366++) { int64_t fi_1367 = f90_kid(n_1355, ((int64_t)(i_1366))); 
int64_t idx_1368 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (named_1364) { idx_1368 = f182_sfield(si_1362, ((int64_t)(((*({ hrv *_t1770 = &(g675); int64_t _i1770 = fi_1367; (S4*)_t1770->b + hr_ix(_i1770, _t1770->n, "hc/calls.amni:419"); }))).s_)));
if (((idx_1368) < (((int64_t)0LL)))) { hrv m_1369 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1774 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1772 = &(m_1369); hr_fs(_o1772, hr_str("no field ", 9)); hr_fs(_o1772, f10_nm(((int64_t)(((*({ hrv *_t1773 = &(g675); int64_t _i1773 = fi_1367; (S4*)_t1773->b + hr_ix(_i1773, _t1773->n, "hc/calls.amni:419"); }))).s_)))); hr_fs(_o1772, hr_str(" in ", 4)); hr_fs(_o1772, hr_sl(*hr_tmp(&_t1774, f160_tn(t_1360)))); }));
}
(void)(f108_cerr(fi_1367, hr_sl(m_1369)));
continue;
 }
 } else { while ((((fpos_1365) < (nf_1363)) && ((((*({ hrv *_t1776 = &(g528); int64_t _i1776 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1777 = &(g527); int64_t _i1777 = si_1362; (S10*)_t1777->b + hr_ix(_i1777, _t1777->n, "hc/calls.amni:420"); }))).f0_)) + (int64_t)fpos_1365)); (S11*)_t1776->b + hr_ix(_i1776, _t1776->n, "hc/calls.amni:420"); }))).ty_) < (((int32_t)0LL))))) { fpos_1365++;
 } _bk1775:; 
idx_1368 = fpos_1365;
fpos_1365++;
if (((idx_1368) >= (nf_1363))) { (void)(f108_cerr(fi_1367, hr_str("too many initializers", 21)));
continue;
 }
 }
int64_t ft_1370 = ((int64_t)(((*({ hrv *_t1778 = &(g528); int64_t _i1778 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1779 = &(g527); int64_t _i1779 = si_1362; (S10*)_t1779->b + hr_ix(_i1779, _t1779->n, "hc/calls.amni:421"); }))).f0_)) + (int64_t)idx_1368)); (S11*)_t1778->b + hr_ix(_i1778, _t1778->n, "hc/calls.amni:421"); }))).ty_)); 
(void)(f168_set_r(fi_1367, ((int64_t)5LL), idx_1368));
int64_t v_1371 = ((int64_t)(((*({ hrv *_t1780 = &(g675); int64_t _i1780 = fi_1367; (S4*)_t1780->b + hr_ix(_i1780, _t1780->n, "hc/calls.amni:423"); }))).a_)); 
(void)(f136_ck(v_1371, ft_1370));
(void)(f139_conv(v_1371, ft_1370));
 } } _bk1768:; 
{ int64_t _e1782 = nf_1363; for (int64_t j_1372 = 0; j_1372 < _e1782; j_1372++) { S11 f_1373 = (*({ hrv *_t1783 = &(g528); int64_t _i1783 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1784 = &(g527); int64_t _i1784 = si_1362; (S10*)_t1784->b + hr_ix(_i1784, _t1784->n, "hc/calls.amni:427"); }))).f0_)) + (int64_t)j_1372)); (S11*)_t1783->b + hr_ix(_i1783, _t1783->n, "hc/calls.amni:427"); })); 
if ((((f_1373).ty_) < (((int32_t)0LL)))) { continue;
 }
bool given_1374 = false; 
{ int32_t _e1786 = (x_1357).n_; for (int32_t i_1375 = 0; i_1375 < _e1786; i_1375++) { if (((f156_rv(f90_kid(n_1355, ((int64_t)(i_1375))))) == (j_1372))) { given_1374 = true;
 }
 } } _bk1785:; 
if (((!(given_1374)) && (((f_1373).def_) >= (((int32_t)0LL))))) { int64_t sa_1376 = g382; 
g382 = g384;
(void)(f136_ck(((int64_t)((f_1373).def_)), ((int64_t)((f_1373).ty_))));
(void)(f139_conv(((int64_t)((f_1373).def_)), ((int64_t)((f_1373).ty_))));
g382 = sa_1376;
 }
if (((((!(given_1374)) && (((f_1373).def_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)(x_1357).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) && (!(f164_is_opt(((int64_t)((f_1373).ty_))))))) { hrv m_1377 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1789 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1788 = &(m_1377); hr_fs(_o1788, hr_str("missing field ", 14)); hr_fs(_o1788, f10_nm(((int64_t)((f_1373).name_)))); hr_fs(_o1788, hr_str(" in ", 4)); hr_fs(_o1788, hr_sl(*hr_tmp(&_t1789, f160_tn(t_1360)))); }));
}
(void)(f108_cerr(n_1355, hr_sl(m_1377)));
 }
 } } _bk1781:; 
(void)(f168_set_r(n_1355, ((int64_t)9LL), si_1362));
return f137_set_t(n_1355, t_1360);
}
static bool f243_ORD_HAS(int64_t d_1379) {
{ hrv *_v1791 = &(g390); for (int64_t _k1791 = 0; _k1791 < _v1791->n; _k1791++) { int32_t o_1380 = ((int32_t*)_v1791->b)[_k1791]; if (((((int64_t)(o_1380))) == (d_1379))) { return true;
 }
 } } _bk1790:; 
return false;
}
static bool f244_gen_program(hrv* out_1385) {
(void)(({ hrv *_v1792 = &(g163); _v1792->n = 0; }));
{ hrv *_v1794 = &(g390); for (int64_t _k1794 = 0; _k1794 < _v1794->n; _k1794++) { int32_t d_1386 = ((int32_t*)_v1794->b)[_k1794]; int64_t di_1387 = ((int64_t)(d_1386)); 
int64_t t_1388 = ((int64_t)((*({ hrv *_t1795 = &(g426); int64_t _i1795 = di_1387; (int32_t*)_t1795->b + hr_ix(_i1795, _t1795->n, "hc/gen.amni:1051"); })))); 
int64_t g_1389 = ((int64_t)(((*({ hrv *_t1796 = &(g464); int64_t _i1796 = di_1387; (S5*)_t1796->b + hr_ix(_i1796, _t1796->n, "hc/gen.amni:1052"); }))).node_)); 
if ((((f170_const_of(di_1387)) >= (((int64_t)0LL))) && ((((*({ hrv *_t1797 = &(g524); int64_t _i1797 = t_1388; (S1*)_t1797->b + hr_ix(_i1797, _t1797->n, "hc/gen.amni:1053"); }))).k_) == (((uint8_t)12LL))))) { continue;
 }
int64_t sv_1390 = (g163).n; 
g382 = g384;
g179 = g384;
(void)(f245_ow(hr_str("static ", 7)));
(void)(f246_ct(t_1388));
(void)(({ hrv *_o1798 = &(g163); hr_fs(_o1798, hr_str(" g", 2)); hr_fi(_o1798, di_1387); hr_fs(_o1798, hr_str(";\012", 2)); }));
(void)(({ hrv *_v1799 = &(g167); hsl _s1799 = ({ hsl _t1800 = hr_sl(g163); int64_t _l1800 = sv_1390, _h1800 = _t1800.n; if (_l1800 < 0 || _h1800 < _l1800 || _h1800 > _t1800.n) hr_slerr(_l1800, _h1800, _t1800.n, "hc/gen.amni:1057"); (hsl){ _t1800.p + _l1800 * (int64_t)sizeof(uint8_t), _h1800 - _l1800 }; }); hr_append(_v1799, _s1799.p, _s1799.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1801 = &(g163); int64_t _k1801 = sv_1390; if (_k1801 < 0) hr_die("resize to a negative length", "hc/gen.amni:1057"); hr_resize(_v1801, _k1801, sizeof(uint8_t)); }));
S4 x_1431 = (*({ hrv *_t1802 = &(g675); int64_t _i1802 = g_1389; (S4*)_t1802->b + hr_ix(_i1802, _t1802->n, "hc/gen.amni:1058"); })); 
if ((((x_1431).b_) >= (((int32_t)0LL)))) { int64_t iv_1432 = f90_kid(((int64_t)((x_1431).b_)), ((int64_t)0LL)); 
int64_t sp_1433 = (g163).n; 
(void)(({ hrv *_o1803 = &(g163); hr_fs(_o1803, hr_str("g", 1)); hr_fi(_o1803, di_1387); hr_fs(_o1803, hr_str(" = ", 3)); }));
if (f253_is_res(t_1388)) { (void)(f254_gxo(iv_1432));
 } else { (void)(f274_gx(iv_1432));
 }
(void)(f245_ow(hr_str(";\012", 2)));
if ((((g176).n) > (((int64_t)0LL)))) { (void)(({ hrv *_v1804 = &(g177); _v1804->n = 0; }));
(void)(({ hrv *_v1805 = &(g177); hsl _s1805 = ({ hsl _t1806 = hr_sl(g163); int64_t _l1806 = sp_1433, _h1806 = _t1806.n; if (_l1806 < 0 || _h1806 < _l1806 || _h1806 > _t1806.n) hr_slerr(_l1806, _h1806, _t1806.n, "hc/gen.amni:1065"); (hsl){ _t1806.p + _l1806 * (int64_t)sizeof(uint8_t), _h1806 - _l1806 }; }); hr_append(_v1805, _s1805.p, _s1805.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1807 = &(g163); int64_t _k1807 = sp_1433; if (_k1807 < 0) hr_die("resize to a negative length", "hc/gen.amni:1065"); hr_resize(_v1807, _k1807, sizeof(uint8_t)); }));
(void)(f245_ow(hr_str("{ ", 2)));
(void)(({ hrv *_v1808 = &(g163); hsl _s1808 = ({ hsl _t1809 = hr_sl(g176); int64_t _l1809 = 0, _h1809 = _t1809.n; if (_l1809 < 0 || _h1809 < _l1809 || _h1809 > _t1809.n) hr_slerr(_l1809, _h1809, _t1809.n, "hc/gen.amni:1065"); (hsl){ _t1809.p + _l1809 * (int64_t)sizeof(uint8_t), _h1809 - _l1809 }; }); hr_append(_v1808, _s1808.p, _s1808.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1810 = &(g176); _v1810->n = 0; }));
(void)(({ hrv *_v1811 = &(g163); hsl _s1811 = ({ hsl _t1812 = hr_sl(g177); int64_t _l1812 = 0, _h1812 = _t1812.n; if (_l1812 < 0 || _h1812 < _l1812 || _h1812 > _t1812.n) hr_slerr(_l1812, _h1812, _t1812.n, "hc/gen.amni:1065"); (hsl){ _t1812.p + _l1812 * (int64_t)sizeof(uint8_t), _h1812 - _l1812 }; }); hr_append(_v1811, _s1811.p, _s1811.n, sizeof(uint8_t)); }));
(void)(f245_ow(hr_str("}\012", 2)));
 }
(void)(({ hrv *_v1813 = &(g168); hsl _s1813 = ({ hsl _t1814 = hr_sl(g163); int64_t _l1814 = sp_1433, _h1814 = _t1814.n; if (_l1814 < 0 || _h1814 < _l1814 || _h1814 > _t1814.n) hr_slerr(_l1814, _h1814, _t1814.n, "hc/gen.amni:1066"); (hsl){ _t1814.p + _l1814 * (int64_t)sizeof(uint8_t), _h1814 - _l1814 }; }); hr_append(_v1813, _s1813.p, _s1813.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1815 = &(g163); int64_t _k1815 = sp_1433; if (_k1815 < 0) hr_die("resize to a negative length", "hc/gen.amni:1066"); hr_resize(_v1815, _k1815, sizeof(uint8_t)); }));
 }
 } } _bk1793:; 
int64_t mi_1930 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v1817 = &(g371); for (int64_t _k1817 = 0; _k1817 < _v1817->n; _k1817++) { S6 f_1931 = ((S6*)_v1817->b)[_k1817]; int64_t i_1932 = _k1817; if (((((f_1931).node_) < (((int32_t)0LL))) || (((f_1931).st_) != (((uint8_t)2LL))))) { continue;
 }
int64_t node_1933 = ((int64_t)((f_1931).node_)); 
if ((((((*({ hrv *_t1818 = &(g675); int64_t _i1818 = node_1933; (S4*)_t1818->b + hr_ix(_i1818, _t1818->n, "hc/gen.amni:1073"); }))).k_) != (((uint8_t)50LL))) || ((((uint16_t)((uint64_t)((*({ hrv *_t1819 = &(g675); int64_t _i1819 = node_1933; (S4*)_t1819->b + hr_ix(_i1819, _t1819->n, "hc/gen.amni:1073"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))))) { continue;
 }
if (((((f_1931).par_) < (((int32_t)0LL))) && hr_streq(f10_nm(((int64_t)((f_1931).name_))), hr_str("main", 4)))) { mi_1930 = i_1932;
 }
(void)(f341_gen_fn(i_1932));
if ((((g182).n) > (((int64_t)0LL)))) { return false;
 }
 } } _bk1816:; 
(void)(({ hrv *_v1820 = out_1385; hsl _s1820 = hr_str("#include \"hrt.h\"\012", 17); hr_append(_v1820, _s1820.p, _s1820.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1821 = out_1385; hsl _s1821 = hr_sl(g164); hr_append(_v1821, _s1821.p, _s1821.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1822 = out_1385; hsl _s1822 = hr_str("#pragma pack(push, 1)\012", 22); hr_append(_v1822, _s1822.p, _s1822.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1823 = out_1385; hsl _s1823 = hr_sl(g165); hr_append(_v1823, _s1823.p, _s1823.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1824 = out_1385; hsl _s1824 = hr_str("#pragma pack(pop)\012", 18); hr_append(_v1824, _s1824.p, _s1824.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1825 = out_1385; hsl _s1825 = hr_sl(g166); hr_append(_v1825, _s1825.p, _s1825.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1826 = out_1385; hsl _s1826 = hr_sl(g167); hr_append(_v1826, _s1826.p, _s1826.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1827 = out_1385; hsl _s1827 = ({ hsl _t1828 = hr_sl(g169); int64_t _l1828 = 0, _h1828 = _t1828.n; if (_l1828 < 0 || _h1828 < _l1828 || _h1828 > _t1828.n) hr_slerr(_l1828, _h1828, _t1828.n, "hc/gen.amni:1085"); (hsl){ _t1828.p + _l1828 * (int64_t)sizeof(uint8_t), _h1828 - _l1828 }; }); hr_append(_v1827, _s1827.p, _s1827.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1829 = out_1385; hsl _s1829 = ({ hsl _t1830 = hr_sl(g163); int64_t _l1830 = 0, _h1830 = _t1830.n; if (_l1830 < 0 || _h1830 < _l1830 || _h1830 > _t1830.n) hr_slerr(_l1830, _h1830, _t1830.n, "hc/gen.amni:1086"); (hsl){ _t1830.p + _l1830 * (int64_t)sizeof(uint8_t), _h1830 - _l1830 }; }); hr_append(_v1829, _s1829.p, _s1829.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1831 = out_1385; hsl _s1831 = hr_str("static void hr_init_globals(void) {\012", 36); hr_append(_v1831, _s1831.p, _s1831.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1832 = out_1385; hsl _s1832 = hr_sl(g168); hr_append(_v1832, _s1832.p, _s1832.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1833 = out_1385; hsl _s1833 = hr_str("}\012", 2); hr_append(_v1833, _s1833.p, _s1833.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1834 = out_1385; hsl _s1834 = hr_str("static void hr_main(void) { ", 28); hr_append(_v1834, _s1834.p, _s1834.n, sizeof(uint8_t)); }));
if (((mi_1930) >= (((int64_t)0LL)))) { int64_t rt_1958 = ((int64_t)(((*({ hrv *_t1835 = &(g371); int64_t _i1835 = mi_1930; (S6*)_t1835->b + hr_ix(_i1835, _t1835->n, "hc/gen.amni:1089"); }))).ret_)); 
if ((((rt_1958) >= (((int64_t)0LL))) && ((((*({ hrv *_t1836 = &(g524); int64_t _i1836 = rt_1958; (S1*)_t1836->b + hr_ix(_i1836, _t1836->n, "hc/gen.amni:1089"); }))).k_) == (((uint8_t)3LL))))) { (void)(({ hrv *_v1837 = out_1385; hsl _s1837 = hr_str("hr_flush(); exit((int)", 22); hr_append(_v1837, _s1837.p, _s1837.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v1838 = &(g163); _v1838->n = 0; }));
(void)(f338_fn_cname(mi_1930));
(void)(({ hrv *_v1839 = out_1385; hsl _s1839 = ({ hsl _t1840 = hr_sl(g163); int64_t _l1840 = 0, _h1840 = _t1840.n; if (_l1840 < 0 || _h1840 < _l1840 || _h1840 > _t1840.n) hr_slerr(_l1840, _h1840, _t1840.n, "hc/gen.amni:1089"); (hsl){ _t1840.p + _l1840 * (int64_t)sizeof(uint8_t), _h1840 - _l1840 }; }); hr_append(_v1839, _s1839.p, _s1839.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1841 = out_1385; hsl _s1841 = hr_str("()", 2); hr_append(_v1841, _s1841.p, _s1841.n, sizeof(uint8_t)); }));
if ((((rt_1958) >= (((int64_t)0LL))) && ((((*({ hrv *_t1842 = &(g524); int64_t _i1842 = rt_1958; (S1*)_t1842->b + hr_ix(_i1842, _t1842->n, "hc/gen.amni:1089"); }))).k_) == (((uint8_t)3LL))))) { (void)(({ hrv *_v1843 = out_1385; hsl _s1843 = hr_str(")", 1); hr_append(_v1843, _s1843.p, _s1843.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v1844 = out_1385; hsl _s1844 = hr_str("; ", 2); hr_append(_v1844, _s1844.p, _s1844.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v1845 = out_1385; hsl _s1845 = hr_str("}\012", 2); hr_append(_v1845, _s1845.p, _s1845.n, sizeof(uint8_t)); }));
return (((g182).n) == (((int64_t)0LL)));
}
static void f245_ow(hsl s_1391) {
(void)(({ hrv *_v1846 = &(g163); hsl _s1846 = s_1391; hr_append(_v1846, _s1846.p, _s1846.n, sizeof(uint8_t)); }));
}
static void f246_ct(int64_t t_1392) {
(void)(f247_cbody(t_1392));
(void)(f245_ow(f249_cn(t_1392)));
}
static void f247_cbody(int64_t t_1393) {
(void)(f248_cn_grow());
S1 x_1394 = (*({ hrv *_t1847 = &(g524); int64_t _i1847 = t_1393; (S1*)_t1847->b + hr_ix(_i1847, _t1847->n, "hc/gen.amni:51"); })); 
int64_t k_1395 = ((int64_t)((x_1394).k_)); 
if ((((k_1395) == (((int64_t)10LL))) || (((*({ hrv *_t1848 = &(g173); int64_t _i1848 = t_1393; (uint8_t*)_t1848->b + hr_ix(_i1848, _t1848->n, "hc/gen.amni:52"); }))) != (((uint8_t)0LL))))) { (void)(f249_cn(t_1393));
return;
 }
(*({ hrv *_t1849 = &(g173); int64_t _i1849 = t_1393; (uint8_t*)_t1849->b + hr_ix(_i1849, _t1849->n, "hc/gen.amni:53"); })) = ((uint8_t)1LL);
(void)(f249_cn(t_1393));
if (((k_1395) == (((int64_t)7LL)))) { S9 v_1409 = (*({ hrv *_t1850 = &(g530); int64_t _i1850 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1851 = &(g529); int64_t _i1851 = (x_1394).a_; (S8*)_t1851->b + hr_ix(_i1851, _t1851->n, "hc/gen.amni:55"); }))).v0_)) + (int64_t)((int64_t)((x_1394).c_)))); (S9*)_t1850->b + hr_ix(_i1850, _t1850->n, "hc/gen.amni:55"); })); 
if ((((v_1409).si_) >= (((int32_t)0LL)))) { (void)(f247_cbody(f133_t_struct(((int64_t)((v_1409).si_)))));
 }
return;
 }
if (((k_1395) == (((int64_t)5LL)))) { int64_t si_1410 = ((int64_t)((x_1394).a_)); 
(void)(f142_si_layout(si_1410));
int64_t f0_1411 = ((int64_t)(((*({ hrv *_t1852 = &(g527); int64_t _i1852 = si_1410; (S10*)_t1852->b + hr_ix(_i1852, _t1852->n, "hc/gen.amni:58"); }))).f0_)); 
int64_t fnum_1412 = ((int64_t)(((*({ hrv *_t1853 = &(g527); int64_t _i1853 = si_1410; (S10*)_t1853->b + hr_ix(_i1853, _t1853->n, "hc/gen.amni:58"); }))).fnum_)); 
{ int64_t _e1855 = fnum_1412; for (int64_t i_1413 = 0; i_1413 < _e1855; i_1413++) { int32_t ft_1414 = ((*({ hrv *_t1856 = &(g528); int64_t _i1856 = ((int64_t)((int64_t)f0_1411 + (int64_t)i_1413)); (S11*)_t1856->b + hr_ix(_i1856, _t1856->n, "hc/gen.amni:59"); }))).ty_; 
if (((ft_1414) >= (((int32_t)0LL)))) { (void)(f247_cbody(((int64_t)(ft_1414))));
 }
 } } _bk1854:; 
(void)(({ hrv *_v1857 = &(g165); hsl _s1857 = hr_str("struct ", 7); hr_append(_v1857, _s1857.p, _s1857.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1858 = &(g165); hsl _s1858 = f249_cn(t_1393); hr_append(_v1858, _s1858.p, _s1858.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1859 = &(g165); hsl _s1859 = hr_str(" { ", 3); hr_append(_v1859, _s1859.p, _s1859.n, sizeof(uint8_t)); }));
bool any_1415 = false; 
{ int64_t _e1861 = fnum_1412; for (int64_t i_1416 = 0; i_1416 < _e1861; i_1416++) { S11 f_1417 = (*({ hrv *_t1862 = &(g528); int64_t _i1862 = ((int64_t)((int64_t)f0_1411 + (int64_t)i_1416)); (S11*)_t1862->b + hr_ix(_i1862, _t1862->n, "hc/gen.amni:63"); })); 
if ((((f_1417).ty_) < (((int32_t)0LL)))) { if ((((f_1417).padn_) > (((int32_t)0LL)))) { (void)(({ hrv *_o1863 = &(g165); hr_fs(_o1863, hr_str("uint8_t _p", 10)); hr_fi(_o1863, i_1416); hr_fs(_o1863, hr_str("[", 1)); hr_fi(_o1863, (f_1417).padn_); hr_fs(_o1863, hr_str("]; ", 3)); }));
any_1415 = true;
 }
continue;
 }
(void)(({ hrv *_v1864 = &(g165); hsl _s1864 = f249_cn(((int64_t)((f_1417).ty_))); hr_append(_v1864, _s1864.p, _s1864.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1865 = &(g165); uint8_t _x1865 = ((uint8_t)32LL); uint8_t *_p1865 = (uint8_t*)hr_grow(_v1865, 1, sizeof _x1865); *_p1865 = _x1865; _p1865; }));
(void)(f252_fname_into((&(g165)), ((int64_t)((f_1417).name_))));
(void)(({ hrv *_v1866 = &(g165); hsl _s1866 = hr_str("; ", 2); hr_append(_v1866, _s1866.p, _s1866.n, sizeof(uint8_t)); }));
any_1415 = true;
 } } _bk1860:; 
if ((!(any_1415))) { (void)(({ hrv *_v1867 = &(g165); hsl _s1867 = hr_str("uint8_t _e; ", 12); hr_append(_v1867, _s1867.p, _s1867.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v1868 = &(g165); hsl _s1868 = hr_str("};\012", 3); hr_append(_v1868, _s1868.p, _s1868.n, sizeof(uint8_t)); }));
return;
 }
if (((k_1395) == (((int64_t)6LL)))) { int64_t ei_1421 = ((int64_t)((x_1394).a_)); 
(void)(f145_ei_layout(ei_1421));
int64_t v0_1422 = ((int64_t)(((*({ hrv *_t1869 = &(g529); int64_t _i1869 = ei_1421; (S8*)_t1869->b + hr_ix(_i1869, _t1869->n, "hc/gen.amni:73"); }))).v0_)); 
bool pay_1423 = false; 
{ int32_t _e1871 = ((*({ hrv *_t1872 = &(g529); int64_t _i1872 = ei_1421; (S8*)_t1872->b + hr_ix(_i1872, _t1872->n, "hc/gen.amni:75"); }))).vnum_; for (int32_t i_1424 = 0; i_1424 < _e1871; i_1424++) { S9 v_1425 = (*({ hrv *_t1873 = &(g530); int64_t _i1873 = ((int64_t)((int64_t)v0_1422 + (int64_t)((int64_t)(i_1424)))); (S9*)_t1873->b + hr_ix(_i1873, _t1873->n, "hc/gen.amni:75"); })); 
if (((((v_1425).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t1874 = &(g527); int64_t _i1874 = (v_1425).si_; (S10*)_t1874->b + hr_ix(_i1874, _t1874->n, "hc/gen.amni:75"); }))).zero_)))) { (void)(f247_cbody(f133_t_struct(((int64_t)((v_1425).si_)))));
pay_1423 = true;
 }
 } } _bk1870:; 
(void)(({ hrv *_v1875 = &(g165); hsl _s1875 = hr_str("struct ", 7); hr_append(_v1875, _s1875.p, _s1875.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1876 = &(g165); hsl _s1876 = f249_cn(t_1393); hr_append(_v1876, _s1876.p, _s1876.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1877 = &(g165); hsl _s1877 = ({ hsl _r1878; if (((((*({ hrv *_t1879 = &(g529); int64_t _i1879 = ei_1421; (S8*)_t1879->b + hr_ix(_i1879, _t1879->n, "hc/gen.amni:76"); }))).tagsz_) == (((uint8_t)1LL)))) { _r1878 = hr_str(" { uint8_t tag; ", 16);  } else { _r1878 = hr_str(" { uint16_t tag; ", 17);  } _r1878; }); hr_append(_v1877, _s1877.p, _s1877.n, sizeof(uint8_t)); }));
if (pay_1423) { (void)(({ hrv *_v1880 = &(g165); hsl _s1880 = hr_str("union { ", 8); hr_append(_v1880, _s1880.p, _s1880.n, sizeof(uint8_t)); }));
{ int32_t _e1882 = ((*({ hrv *_t1883 = &(g529); int64_t _i1883 = ei_1421; (S8*)_t1883->b + hr_ix(_i1883, _t1883->n, "hc/gen.amni:77"); }))).vnum_; for (int32_t i_1426 = 0; i_1426 < _e1882; i_1426++) { S9 v_1427 = (*({ hrv *_t1884 = &(g530); int64_t _i1884 = ((int64_t)((int64_t)v0_1422 + (int64_t)((int64_t)(i_1426)))); (S9*)_t1884->b + hr_ix(_i1884, _t1884->n, "hc/gen.amni:77"); })); 
if (((((v_1427).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t1885 = &(g527); int64_t _i1885 = (v_1427).si_; (S10*)_t1885->b + hr_ix(_i1885, _t1885->n, "hc/gen.amni:77"); }))).zero_)))) { (void)(({ hrv *_v1886 = &(g165); hsl _s1886 = f249_cn(f133_t_struct(((int64_t)((v_1427).si_)))); hr_append(_v1886, _s1886.p, _s1886.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o1887 = &(g165); hr_fs(_o1887, hr_str(" v", 2)); hr_fi(_o1887, i_1426); hr_fs(_o1887, hr_str("; ", 2)); }));
 }
 } } _bk1881:; 
(void)(({ hrv *_v1888 = &(g165); hsl _s1888 = hr_str("} u; ", 5); hr_append(_v1888, _s1888.p, _s1888.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v1889 = &(g165); hsl _s1889 = hr_str("};\012", 3); hr_append(_v1889, _s1889.p, _s1889.n, sizeof(uint8_t)); }));
return;
 }
if (((k_1395) == (((int64_t)8LL)))) { int64_t a_1428 = ((int64_t)((x_1394).s_)); 
if ((((a_1428) == (((int64_t)1LL))) || (((a_1428) == (((int64_t)3LL))) && (((x_1394).b_) >= (((int64_t)0LL)))))) { (void)(f247_cbody(((int64_t)((x_1394).a_))));
(void)(({ hrv *_v1890 = &(g165); hsl _s1890 = hr_str("struct ", 7); hr_append(_v1890, _s1890.p, _s1890.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1891 = &(g165); hsl _s1891 = f249_cn(t_1393); hr_append(_v1891, _s1891.p, _s1891.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1892 = &(g165); hsl _s1892 = hr_str(" { ", 3); hr_append(_v1892, _s1892.p, _s1892.n, sizeof(uint8_t)); }));
if (((a_1428) == (((int64_t)3LL)))) { (void)(({ hrv *_v1893 = &(g165); hsl _s1893 = (g183).e[hr_ix(((int64_t)((int64_t)f122_lim_lenstore((x_1394).b_) & (int64_t)((int64_t)7LL))), 8, "hc/gen.amni:86")]; hr_append(_v1893, _s1893.p, _s1893.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1895 = &(g165); hsl _s1895 = hr_str(" n; ", 4); hr_append(_v1895, _s1895.p, _s1895.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v1896 = &(g165); hsl _s1896 = f249_cn(((int64_t)((x_1394).a_))); hr_append(_v1896, _s1896.p, _s1896.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o1897 = &(g165); hr_fs(_o1897, hr_str(" e[", 3)); hr_fi(_o1897, f103_max((x_1394).b_, ((int64_t)1LL))); hr_fs(_o1897, hr_str("]; };\012", 6)); }));
 }
return;
 }
if (((k_1395) == (((int64_t)14LL)))) { { int32_t _e1899 = (x_1394).n_; for (int32_t i_1429 = 0; i_1429 < _e1899; i_1429++) { (void)(f247_cbody(((int64_t)((*({ hrv *_t1900 = &(g525); int64_t _i1900 = ((int64_t)((int64_t)((int64_t)((x_1394).l_)) + (int64_t)((int64_t)(i_1429)))); (int32_t*)_t1900->b + hr_ix(_i1900, _t1900->n, "hc/gen.amni:92"); }))))));
 } } _bk1898:; 
(void)(({ hrv *_v1901 = &(g165); hsl _s1901 = hr_str("struct ", 7); hr_append(_v1901, _s1901.p, _s1901.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1902 = &(g165); hsl _s1902 = f249_cn(t_1393); hr_append(_v1902, _s1902.p, _s1902.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1903 = &(g165); hsl _s1903 = hr_str(" { ", 3); hr_append(_v1903, _s1903.p, _s1903.n, sizeof(uint8_t)); }));
{ int32_t _e1905 = (x_1394).n_; for (int32_t i_1430 = 0; i_1430 < _e1905; i_1430++) { (void)(({ hrv *_v1906 = &(g165); hsl _s1906 = f249_cn(((int64_t)((*({ hrv *_t1907 = &(g525); int64_t _i1907 = ((int64_t)((int64_t)((int64_t)((x_1394).l_)) + (int64_t)((int64_t)(i_1430)))); (int32_t*)_t1907->b + hr_ix(_i1907, _t1907->n, "hc/gen.amni:94"); }))))); hr_append(_v1906, _s1906.p, _s1906.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o1908 = &(g165); hr_fs(_o1908, hr_str(" r", 2)); hr_fi(_o1908, i_1430); hr_fs(_o1908, hr_str("; ", 2)); }));
 } } _bk1904:; 
(void)(({ hrv *_v1909 = &(g165); hsl _s1909 = hr_str("};\012", 3); hr_append(_v1909, _s1909.p, _s1909.n, sizeof(uint8_t)); }));
 }
}
static void f248_cn_grow(void) {
while ((((g171).n) < ((g524).n))) { (void)(({ hrv *_v1911 = &(g171); int32_t _x1911 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1911 = (int32_t*)hr_grow(_v1911, 1, sizeof _x1911); *_p1911 = _x1911; _p1911; }));
(void)(({ hrv *_v1912 = &(g172); int32_t _x1912 = ((int32_t)0LL); int32_t *_p1912 = (int32_t*)hr_grow(_v1912, 1, sizeof _x1912); *_p1912 = _x1912; _p1912; }));
(void)(({ hrv *_v1913 = &(g173); uint8_t _x1913 = ((uint8_t)0LL); uint8_t *_p1913 = (uint8_t*)hr_grow(_v1913, 1, sizeof _x1913); *_p1913 = _x1913; _p1913; }));
(void)(({ hrv *_v1914 = &(g174); uint8_t _x1914 = ((uint8_t)0LL); uint8_t *_p1914 = (uint8_t*)hr_grow(_v1914, 1, sizeof _x1914); *_p1914 = _x1914; _p1914; }));
(void)(({ hrv *_v1915 = &(g175); uint8_t _x1915 = ((uint8_t)0LL); uint8_t *_p1915 = (uint8_t*)hr_grow(_v1915, 1, sizeof _x1915); *_p1915 = _x1915; _p1915; }));
 } _bk1910:; 
}
static hsl f249_cn(int64_t t_1396) {
(void)(f248_cn_grow());
if ((((*({ hrv *_t1916 = &(g171); int64_t _i1916 = t_1396; (int32_t*)_t1916->b + hr_ix(_i1916, _t1916->n, "hc/gen.amni:23"); }))) < (((int32_t)0LL)))) { (void)(f250_cn_make(t_1396));
 }
int64_t o_1408 = ((int64_t)((*({ hrv *_t1917 = &(g171); int64_t _i1917 = t_1396; (int32_t*)_t1917->b + hr_ix(_i1917, _t1917->n, "hc/gen.amni:24"); })))); 
return ({ hsl _t1918 = hr_sl(g170); int64_t _l1918 = o_1408, _h1918 = ((int64_t)((int64_t)o_1408 + (int64_t)((int64_t)((*({ hrv *_t1919 = &(g172); int64_t _i1919 = t_1396; (int32_t*)_t1919->b + hr_ix(_i1919, _t1919->n, "hc/gen.amni:25"); })))))); if (_l1918 < 0 || _h1918 < _l1918 || _h1918 > _t1918.n) hr_slerr(_l1918, _h1918, _t1918.n, "hc/gen.amni:25"); (hsl){ _t1918.p + _l1918 * (int64_t)sizeof(uint8_t), _h1918 - _l1918 }; });
}
static void f250_cn_make(int64_t t_1397) {
S1 x_1398 = (*({ hrv *_t1920 = &(g524); int64_t _i1920 = t_1397; (S1*)_t1920->b + hr_ix(_i1920, _t1920->n, "hc/gen.amni:28"); })); 
int64_t k_1399 = ((int64_t)((x_1398).k_)); 
if ((((k_1399) == (((int64_t)10LL))) && (((x_1398).c_) < (((int32_t)0LL))))) { hsl e_1400 = f249_cn(((int64_t)((x_1398).a_))); 
int64_t s0_1401 = (g170).n; 
(void)(({ hrv *_v1921 = &(g170); hsl _s1921 = e_1400; hr_append(_v1921, _s1921.p, _s1921.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1922 = &(g170); uint8_t _x1922 = ((uint8_t)42LL); uint8_t *_p1922 = (uint8_t*)hr_grow(_v1922, 1, sizeof _x1922); *_p1922 = _x1922; _p1922; }));
(*({ hrv *_t1923 = &(g171); int64_t _i1923 = t_1397; (int32_t*)_t1923->b + hr_ix(_i1923, _t1923->n, "hc/gen.amni:29"); })) = ((int32_t)(s0_1401));
(*({ hrv *_t1924 = &(g172); int64_t _i1924 = t_1397; (int32_t*)_t1924->b + hr_ix(_i1924, _t1924->n, "hc/gen.amni:29"); })) = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1401))));
return;
 }
if (((k_1399) == (((int64_t)7LL)))) { S9 v_1402 = (*({ hrv *_t1925 = &(g530); int64_t _i1925 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1926 = &(g529); int64_t _i1926 = (x_1398).a_; (S8*)_t1926->b + hr_ix(_i1926, _t1926->n, "hc/gen.amni:30"); }))).v0_)) + (int64_t)((int64_t)((x_1398).c_)))); (S9*)_t1925->b + hr_ix(_i1925, _t1925->n, "hc/gen.amni:30"); })); 
if ((((v_1402).si_) >= (((int32_t)0LL)))) { hsl e_1403 = f249_cn(f133_t_struct(((int64_t)((v_1402).si_)))); 
int64_t s0_1404 = (g170).n; 
(void)(({ hrv *_v1927 = &(g170); hsl _s1927 = e_1403; hr_append(_v1927, _s1927.p, _s1927.n, sizeof(uint8_t)); }));
(*({ hrv *_t1928 = &(g171); int64_t _i1928 = t_1397; (int32_t*)_t1928->b + hr_ix(_i1928, _t1928->n, "hc/gen.amni:30"); })) = ((int32_t)(s0_1404));
(*({ hrv *_t1929 = &(g172); int64_t _i1929 = t_1397; (int32_t*)_t1929->b + hr_ix(_i1929, _t1929->n, "hc/gen.amni:30"); })) = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1404))));
return;
 }
 }
int64_t s0_1405 = (g170).n; 
if (((k_1399) == (((int64_t)3LL)))) { (void)(({ hrv *_v1930 = &(g170); hsl _s1930 = (g183).e[hr_ix(((uint8_t)((uint64_t)(x_1398).s_ & (uint64_t)((uint8_t)7LL))), 8, "hc/gen.amni:32")]; hr_append(_v1930, _s1930.p, _s1930.n, sizeof(uint8_t)); }));
 } else { if (((k_1399) == (((int64_t)10LL)))) { (void)(({ hrv *_v1932 = &(g170); hsl _s1932 = (g183).e[hr_ix(((int32_t)((int64_t)((int32_t)((int64_t)(x_1398).c_ & (int64_t)((int32_t)3LL))) + (int64_t)((int32_t)4LL))), 8, "hc/gen.amni:33")]; hr_append(_v1932, _s1932.p, _s1932.n, sizeof(uint8_t)); }));
 } else { if (((k_1399) == (((int64_t)2LL)))) { (void)(({ hrv *_v1934 = &(g170); hsl _s1934 = hr_str("bool", 4); hr_append(_v1934, _s1934.p, _s1934.n, sizeof(uint8_t)); }));
 } else { if (((k_1399) == (((int64_t)4LL)))) { (void)(({ hrv *_v1935 = &(g170); hsl _s1935 = ({ hsl _r1936; if ((((x_1398).s_) == (((uint8_t)4LL)))) { _r1936 = hr_str("float", 5);  } else { _r1936 = hr_str("double", 6);  } _r1936; }); hr_append(_v1935, _s1935.p, _s1935.n, sizeof(uint8_t)); }));
 } else { if (((k_1399) == (((int64_t)1LL)))) { (void)(({ hrv *_v1937 = &(g170); hsl _s1937 = hr_str("void", 4); hr_append(_v1937, _s1937.p, _s1937.n, sizeof(uint8_t)); }));
 } else { if (((k_1399) == (((int64_t)5LL)))) { (void)(({ hrv *_o1938 = &(g170); hr_fs(_o1938, hr_str("S", 1)); hr_fi(_o1938, (x_1398).a_); }));
(void)(f251_fwd(s0_1405));
 } else { if (((k_1399) == (((int64_t)6LL)))) { (void)(({ hrv *_o1939 = &(g170); hr_fs(_o1939, hr_str("E", 1)); hr_fi(_o1939, (x_1398).a_); }));
(void)(f251_fwd(s0_1405));
 } else { if (((k_1399) == (((int64_t)7LL)))) { (void)(({ hrv *_v1940 = &(g170); hsl _s1940 = hr_str("hr_unit", 7); hr_append(_v1940, _s1940.p, _s1940.n, sizeof(uint8_t)); }));
 } else { if (((k_1399) == (((int64_t)8LL)))) { int64_t a_1407 = ((int64_t)((x_1398).s_)); 
if ((((a_1407) == (((int64_t)4LL))) || ((a_1407) == (((int64_t)5LL))))) { (void)(({ hrv *_v1941 = &(g170); hsl _s1941 = hr_str("hrv", 3); hr_append(_v1941, _s1941.p, _s1941.n, sizeof(uint8_t)); }));
 } else { if (((a_1407) == (((int64_t)1LL)))) { (void)(({ hrv *_o1942 = &(g170); hr_fs(_o1942, hr_str("A", 1)); hr_fi(_o1942, t_1397); }));
(void)(f251_fwd(s0_1405));
 } else { if ((((a_1407) == (((int64_t)3LL))) && (((x_1398).b_) >= (((int64_t)0LL))))) { (void)(({ hrv *_o1943 = &(g170); hr_fs(_o1943, hr_str("L", 1)); hr_fi(_o1943, t_1397); }));
(void)(f251_fwd(s0_1405));
 } else { (void)(({ hrv *_v1944 = &(g170); hsl _s1944 = hr_str("uint8_t*", 8); hr_append(_v1944, _s1944.p, _s1944.n, sizeof(uint8_t)); }));
 }
 }
 }
 } else { if (((((k_1399) == (((int64_t)9LL))) || ((k_1399) == (((int64_t)18LL)))) || ((k_1399) == (((int64_t)19LL))))) { (void)(({ hrv *_v1945 = &(g170); hsl _s1945 = hr_str("hsl", 3); hr_append(_v1945, _s1945.p, _s1945.n, sizeof(uint8_t)); }));
 } else { if (((k_1399) == (((int64_t)14LL)))) { (void)(({ hrv *_o1946 = &(g170); hr_fs(_o1946, hr_str("M", 1)); hr_fi(_o1946, t_1397); }));
(void)(f251_fwd(s0_1405));
 } else { if ((((k_1399) == (((int64_t)12LL))) || ((k_1399) == (((int64_t)17LL))))) { (void)(({ hrv *_v1947 = &(g170); hsl _s1947 = hr_str("int64_t", 7); hr_append(_v1947, _s1947.p, _s1947.n, sizeof(uint8_t)); }));
 } else { if (((k_1399) == (((int64_t)13LL)))) { (void)(({ hrv *_v1948 = &(g170); hsl _s1948 = hr_str("double", 6); hr_append(_v1948, _s1948.p, _s1948.n, sizeof(uint8_t)); }));
 } else { (void)(({ hrv *_v1949 = &(g170); hsl _s1949 = hr_str("void*", 5); hr_append(_v1949, _s1949.p, _s1949.n, sizeof(uint8_t)); }));
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
(*({ hrv *_t1950 = &(g171); int64_t _i1950 = t_1397; (int32_t*)_t1950->b + hr_ix(_i1950, _t1950->n, "hc/gen.amni:46"); })) = ((int32_t)(s0_1405));
(*({ hrv *_t1951 = &(g172); int64_t _i1951 = t_1397; (int32_t*)_t1951->b + hr_ix(_i1951, _t1951->n, "hc/gen.amni:46"); })) = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1405))));
}
static void f251_fwd(int64_t s0_1406) {
(void)(({ hrv *_v1952 = &(g164); hsl _s1952 = hr_str("typedef struct ", 15); hr_append(_v1952, _s1952.p, _s1952.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1953 = &(g164); hsl _s1953 = ({ hsl _t1954 = hr_sl(g170); int64_t _l1954 = s0_1406, _h1954 = _t1954.n; if (_l1954 < 0 || _h1954 < _l1954 || _h1954 > _t1954.n) hr_slerr(_l1954, _h1954, _t1954.n, "hc/gen.amni:17"); (hsl){ _t1954.p + _l1954 * (int64_t)sizeof(uint8_t), _h1954 - _l1954 }; }); hr_append(_v1953, _s1953.p, _s1953.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1955 = &(g164); uint8_t _x1955 = ((uint8_t)32LL); uint8_t *_p1955 = (uint8_t*)hr_grow(_v1955, 1, sizeof _x1955); *_p1955 = _x1955; _p1955; }));
(void)(({ hrv *_v1956 = &(g164); hsl _s1956 = ({ hsl _t1957 = hr_sl(g170); int64_t _l1957 = s0_1406, _h1957 = _t1957.n; if (_l1957 < 0 || _h1957 < _l1957 || _h1957 > _t1957.n) hr_slerr(_l1957, _h1957, _t1957.n, "hc/gen.amni:17"); (hsl){ _t1957.p + _l1957 * (int64_t)sizeof(uint8_t), _h1957 - _l1957 }; }); hr_append(_v1956, _s1956.p, _s1956.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v1958 = &(g164); hsl _s1958 = hr_str(";\012", 2); hr_append(_v1958, _s1958.p, _s1958.n, sizeof(uint8_t)); }));
}
static void f252_fname_into(hrv* b_1418, int64_t name_1419) {
{ hsl _v1960 = f10_nm(name_1419); for (int64_t _k1960 = 0; _k1960 < _v1960.n; _k1960++) { uint8_t c_1420 = ((uint8_t*)_v1960.p)[_k1960]; (void)(({ hrv *_v1961 = b_1418; uint8_t _x1961 = ({ uint8_t _r1962; if (((c_1420) == (((uint8_t)58LL)))) { _r1962 = ((uint8_t)95LL);  } else { _r1962 = c_1420;  } _r1962; }); uint8_t *_p1961 = (uint8_t*)hr_grow(_v1961, 1, sizeof _x1961); *_p1961 = _x1961; _p1961; }));
 } } _bk1959:; 
(void)(({ hrv *_v1963 = b_1418; uint8_t _x1963 = ((uint8_t)95LL); uint8_t *_p1963 = (uint8_t*)hr_grow(_v1963, 1, sizeof _x1963); *_p1963 = _x1963; _p1963; }));
}
static bool f253_is_res(int64_t t_1434) {
return (((((*({ hrv *_t1964 = &(g524); int64_t _i1964 = t_1434; (S1*)_t1964->b + hr_ix(_i1964, _t1964->n, "hc/gen.amni:18"); }))).k_) == (((uint8_t)8LL))) && (((((int64_t)(((*({ hrv *_t1965 = &(g524); int64_t _i1965 = t_1434; (S1*)_t1965->b + hr_ix(_i1965, _t1965->n, "hc/gen.amni:18"); }))).s_))) == (((int64_t)4LL))) || ((((int64_t)(((*({ hrv *_t1966 = &(g524); int64_t _i1966 = t_1434; (S1*)_t1966->b + hr_ix(_i1966, _t1966->n, "hc/gen.amni:18"); }))).s_))) == (((int64_t)5LL)))));
}
static void f254_gxo(int64_t n_1435) {
int64_t c_1436 = f147_cv(n_1435); 
int64_t t_1437 = f140_at(n_1435); 
if ((((c_1436) >= (((int64_t)0LL))) && ((c_1436) != (t_1437)))) { if (f253_is_res(c_1436)) { (void)(f255_gcv(n_1435, t_1437, c_1436));
return;
 }
(void)(f274_gx(n_1435));
return;
 }
if ((f253_is_res(t_1437) && f257_is_place(n_1435))) { (void)(f245_ow(hr_str("hr_rdup(", 8)));
(void)(f260_gx0(n_1435));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f308_esz(((int64_t)(((*({ hrv *_t1967 = &(g524); int64_t _i1967 = t_1437; (S1*)_t1967->b + hr_ix(_i1967, _t1967->n, "hc/gen.amni:160"); }))).a_))));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
(void)(f260_gx0(n_1435));
}
static void f255_gcv(int64_t n_1438, int64_t f_1439, int64_t t_1440) {
if (((f_1439) == (t_1440))) { (void)(f256_gx1(n_1438));
return;
 }
int64_t fk_1922 = ((int64_t)(((*({ hrv *_t1968 = &(g524); int64_t _i1968 = f_1439; (S1*)_t1968->b + hr_ix(_i1968, _t1968->n, "hc/gen.amni:200"); }))).k_)); 
int64_t tk0_1923 = ((int64_t)(((*({ hrv *_t1969 = &(g524); int64_t _i1969 = t_1440; (S1*)_t1969->b + hr_ix(_i1969, _t1969->n, "hc/gen.amni:200"); }))).k_)); 
if (((((fk_1922) == (((int64_t)10LL))) && ((((*({ hrv *_t1970 = &(g524); int64_t _i1970 = f_1439; (S1*)_t1970->b + hr_ix(_i1970, _t1970->n, "hc/gen.amni:201"); }))).c_) < (((int32_t)0LL)))) && ((tk0_1923) != (((int64_t)10LL))))) { int64_t m_1924 = ((int64_t)(((*({ hrv *_t1971 = &(g524); int64_t _i1971 = f_1439; (S1*)_t1971->b + hr_ix(_i1971, _t1971->n, "hc/gen.amni:202"); }))).a_)); 
if (((m_1924) == (t_1440))) { (void)(f245_ow(hr_str("(*", 2)));
(void)(f256_gx1(n_1438));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if ((((tk0_1923) == (((int64_t)9LL))) && (((((*({ hrv *_t1972 = &(g524); int64_t _i1972 = m_1924; (S1*)_t1972->b + hr_ix(_i1972, _t1972->n, "hc/gen.amni:204"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t1973 = &(g524); int64_t _i1973 = m_1924; (S1*)_t1973->b + hr_ix(_i1973, _t1973->n, "hc/gen.amni:204"); }))).k_) == (((uint8_t)9LL)))))) { (void)(f277_gsl(n_1438, f_1439));
return;
 }
if ((((tk0_1923) == (((int64_t)3LL))) || ((tk0_1923) == (((int64_t)4LL))))) { (void)(f245_ow(hr_str("((", 2)));
(void)(f246_ct(t_1440));
(void)(f245_ow(hr_str(")(*", 3)));
(void)(f256_gx1(n_1438));
(void)(f245_ow(hr_str("))", 2)));
return;
 }
if (f253_is_res(t_1440)) { (void)(f245_ow(hr_str("hr_rfrom(", 9)));
(void)(f277_gsl(n_1438, f_1439));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f308_esz(((int64_t)(((*({ hrv *_t1974 = &(g524); int64_t _i1974 = t_1440; (S1*)_t1974->b + hr_ix(_i1974, _t1974->n, "hc/gen.amni:206"); }))).a_))));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
(void)(f245_ow(hr_str("(*", 2)));
(void)(f256_gx1(n_1438));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if (((((tk0_1923) == (((int64_t)3LL))) || ((tk0_1923) == (((int64_t)4LL)))) && ((((fk_1922) == (((int64_t)3LL))) || ((fk_1922) == (((int64_t)4LL)))) || ((fk_1922) == (((int64_t)2LL)))))) { (void)(f245_ow(hr_str("((", 2)));
(void)(f246_ct(t_1440));
(void)(f245_ow(hr_str(")(", 2)));
(void)(f256_gx1(n_1438));
(void)(f245_ow(hr_str("))", 2)));
return;
 }
if (((tk0_1923) == (((int64_t)9LL)))) { (void)(f277_gsl(n_1438, f_1439));
return;
 }
if ((((tk0_1923) == (((int64_t)6LL))) && ((fk_1922) == (((int64_t)7LL))))) { int64_t vi_1925 = ((int64_t)(((*({ hrv *_t1975 = &(g524); int64_t _i1975 = f_1439; (S1*)_t1975->b + hr_ix(_i1975, _t1975->n, "hc/gen.amni:212"); }))).c_)); 
int64_t ei_1926 = ((int64_t)(((*({ hrv *_t1976 = &(g524); int64_t _i1976 = f_1439; (S1*)_t1976->b + hr_ix(_i1976, _t1976->n, "hc/gen.amni:212"); }))).a_)); 
S9 v_1927 = (*({ hrv *_t1977 = &(g530); int64_t _i1977 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1978 = &(g529); int64_t _i1978 = ei_1926; (S8*)_t1978->b + hr_ix(_i1978, _t1978->n, "hc/gen.amni:212"); }))).v0_)) + (int64_t)vi_1925)); (S9*)_t1977->b + hr_ix(_i1977, _t1977->n, "hc/gen.amni:212"); })); 
int64_t p_1928 = f278_nt(); 
(void)(f245_ow(hr_str("({ ", 3)));
(void)(f246_ct(t_1440));
(void)(f245_ow(hr_str(" _t", 3)));
(void)(f279_oi(p_1928));
(void)(f245_ow(hr_str("; memset(&_t", 12)));
(void)(f279_oi(p_1928));
(void)(f245_ow(hr_str(", 0, sizeof _t", 14)));
(void)(f279_oi(p_1928));
(void)(f245_ow(hr_str("); _t", 5)));
(void)(f279_oi(p_1928));
(void)(({ hrv *_o1979 = &(g163); hr_fs(_o1979, hr_str(".tag = ", 7)); hr_fi(_o1979, vi_1925); hr_fs(_o1979, hr_str("; ", 2)); }));
if (((((v_1927).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t1980 = &(g527); int64_t _i1980 = (v_1927).si_; (S10*)_t1980->b + hr_ix(_i1980, _t1980->n, "hc/gen.amni:215"); }))).zero_)))) { (void)(f245_ow(hr_str("_t", 2)));
(void)(f279_oi(p_1928));
(void)(({ hrv *_o1981 = &(g163); hr_fs(_o1981, hr_str(".u.v", 4)); hr_fi(_o1981, vi_1925); hr_fs(_o1981, hr_str(" = ", 3)); }));
(void)(f256_gx1(n_1438));
(void)(f245_ow(hr_str("; ", 2)));
 } else { (void)(f245_ow(hr_str("(void)(", 7)));
(void)(f256_gx1(n_1438));
(void)(f245_ow(hr_str("); ", 3)));
 }
(void)(f245_ow(hr_str("_t", 2)));
(void)(f279_oi(p_1928));
(void)(f245_ow(hr_str("; })", 4)));
return;
 }
if (((tk0_1923) == (((int64_t)10LL)))) { if (((fk_1922) == (((int64_t)10LL)))) { (void)(f256_gx1(n_1438));
return;
 }
(void)(f309_gaddr(n_1438));
return;
 }
if (f253_is_res(t_1440)) { (void)(f245_ow(hr_str("hr_rfrom(", 9)));
(void)(f277_gsl(n_1438, f_1439));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f308_esz(((int64_t)(((*({ hrv *_t1982 = &(g524); int64_t _i1982 = t_1440; (S1*)_t1982->b + hr_ix(_i1982, _t1982->n, "hc/gen.amni:220"); }))).a_))));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if ((f267_is_fix(t_1440) || f268_is_lim(t_1440))) { int64_t p_1929 = f278_nt(); 
(void)(f245_ow(hr_str("({ hsl _t", 9)));
(void)(f279_oi(p_1929));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f277_gsl(n_1438, f_1439));
(void)(f245_ow(hr_str("; ", 2)));
(void)(f246_ct(t_1440));
(void)(f245_ow(hr_str(" _r", 3)));
(void)(f279_oi(p_1929));
(void)(f245_ow(hr_str("; ", 2)));
if (f267_is_fix(t_1440)) { (void)(({ hrv *_o1983 = &(g163); hr_fs(_o1983, hr_str("if (_t", 6)); hr_fi(_o1983, p_1929); hr_fs(_o1983, hr_str(".n != ", 6)); hr_fi(_o1983, ((*({ hrv *_t1984 = &(g524); int64_t _i1984 = t_1440; (S1*)_t1984->b + hr_ix(_i1984, _t1984->n, "hc/gen.amni:224"); }))).b_); hr_fs(_o1983, hr_str(") hr_die(\"array length mismatch\", ", 34)); }));
(void)(f296_wloc(n_1438));
(void)(f245_ow(hr_str("); ", 3)));
 } else { (void)(({ hrv *_o1985 = &(g163); hr_fs(_o1985, hr_str("if (_t", 6)); hr_fi(_o1985, p_1929); hr_fs(_o1985, hr_str(".n > ", 5)); hr_fi(_o1985, ((*({ hrv *_t1986 = &(g524); int64_t _i1986 = t_1440; (S1*)_t1986->b + hr_ix(_i1986, _t1986->n, "hc/gen.amni:225"); }))).b_); hr_fs(_o1985, hr_str(") hr_die(\"too many elements for a limited array\", ", 50)); }));
(void)(f296_wloc(n_1438));
(void)(({ hrv *_o1987 = &(g163); hr_fs(_o1987, hr_str("); _r", 5)); hr_fi(_o1987, p_1929); hr_fs(_o1987, hr_str(".n = _t", 7)); hr_fi(_o1987, p_1929); hr_fs(_o1987, hr_str(".n; ", 4)); }));
 }
(void)(({ hrv *_o1988 = &(g163); hr_fs(_o1988, hr_str("memcpy(_r", 9)); hr_fi(_o1988, p_1929); hr_fs(_o1988, hr_str(".e, _t", 6)); hr_fi(_o1988, p_1929); hr_fs(_o1988, hr_str(".p, (size_t)_t", 14)); hr_fi(_o1988, p_1929); hr_fs(_o1988, hr_str(".n * sizeof _r", 14)); hr_fi(_o1988, p_1929); hr_fs(_o1988, hr_str(".e[0]); _r", 10)); hr_fi(_o1988, p_1929); hr_fs(_o1988, hr_str("; })", 4)); }));
return;
 }
(void)(f256_gx1(n_1438));
}
static void f256_gx1(int64_t n_1441) {
if ((f253_is_res(f140_at(n_1441)) && (!(f257_is_place(n_1441))))) { int64_t k_1449 = f258_tmp(f140_at(n_1441), true); 
(void)(f245_ow(hr_str("(*hr_tmp(&", 10)));
(void)(f259_ot(k_1449));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f260_gx0(n_1441));
(void)(f245_ow(hr_str("))", 2)));
return;
 }
(void)(f260_gx0(n_1441));
}
static bool f257_is_place(int64_t n_1442) {
S4 x_1443 = (*({ hrv *_t1989 = &(g675); int64_t _i1989 = n_1442; (S4*)_t1989->b + hr_ix(_i1989, _t1989->n, "hc/gen.amni:122"); })); 
int64_t k_1444 = ((int64_t)((x_1443).k_)); 
if (((k_1444) == (((int64_t)8LL)))) { int64_t r_1445 = f155_rk(n_1442); 
return (((r_1445) == (((int64_t)1LL))) || ((r_1445) == (((int64_t)2LL))));
 }
if (((k_1444) == (((int64_t)14LL)))) { return (((f155_rk(n_1442)) == (((int64_t)5LL))) && (f257_is_place(((int64_t)((x_1443).a_))) || ((((*({ hrv *_t1990 = &(g524); int64_t _i1990 = f140_at(((int64_t)((x_1443).a_))); (S1*)_t1990->b + hr_ix(_i1990, _t1990->n, "hc/gen.amni:124"); }))).k_) == (((uint8_t)10LL)))));
 }
if (((k_1444) == (((int64_t)12LL)))) { int64_t bt_1446 = f140_at(((int64_t)((x_1443).a_))); 
return ((((((*({ hrv *_t1991 = &(g524); int64_t _i1991 = f174_deref(bt_1446); (S1*)_t1991->b + hr_ix(_i1991, _t1991->n, "hc/gen.amni:125"); }))).k_) == (((uint8_t)9LL))) || f257_is_place(((int64_t)((x_1443).a_)))) || ((((*({ hrv *_t1992 = &(g524); int64_t _i1992 = bt_1446; (S1*)_t1992->b + hr_ix(_i1992, _t1992->n, "hc/gen.amni:125"); }))).k_) == (((uint8_t)10LL))));
 }
if ((((k_1444) == (((int64_t)10LL))) && ((((int64_t)((x_1443).op_))) == (((int64_t)49LL))))) { return f257_is_place(((int64_t)((x_1443).a_)));
 }
if (((((k_1444) == (((int64_t)11LL))) && ((f155_rk(n_1442)) == (((int64_t)4LL)))) && ((f156_rv(n_1442)) == (((int64_t)20LL))))) { return true;
 }
return false;
}
static int64_t f258_tmp(int64_t t_1447, bool clean_1448) {
(void)(f247_cbody(t_1447));
g178++;
(void)(({ hrv *_v1993 = &(g176); hsl _s1993 = f249_cn(t_1447); hr_append(_v1993, _s1993.p, _s1993.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o1994 = &(g176); hr_fs(_o1994, hr_str(" _t", 3)); hr_fi(_o1994, g178); }));
if (clean_1448) { (void)(({ hrv *_v1995 = &(g176); hsl _s1995 = hr_str(" __attribute__((cleanup(hr_rdrop)))", 35); hr_append(_v1995, _s1995.p, _s1995.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v1996 = &(g176); hsl _s1996 = hr_str(" = {0}; ", 8); hr_append(_v1996, _s1996.p, _s1996.n, sizeof(uint8_t)); }));
return g178;
}
static void f259_ot(int64_t k_1450) {
(void)(({ hrv *_o1997 = &(g163); hr_fs(_o1997, hr_str("_t", 2)); hr_fi(_o1997, k_1450); }));
}
static void f260_gx0(int64_t n_1451) {
S4 x_1452 = (*({ hrv *_t1998 = &(g675); int64_t _i1998 = n_1451; (S4*)_t1998->b + hr_ix(_i1998, _t1998->n, "hc/gen.amni:686"); })); 
int64_t k_1453 = ((int64_t)((x_1452).k_)); 
if (((k_1453) == (((int64_t)1LL)))) { (void)(f262_oint(((*({ hrv *_t1999 = &(g885); int64_t _i1999 = (x_1452).t_; (S3*)_t1999->b + hr_ix(_i1999, _t1999->n, "hc/gen.amni:688"); }))).v_, ((*({ hrv *_t2000 = &(g885); int64_t _i2000 = (x_1452).t_; (S3*)_t2000->b + hr_ix(_i2000, _t2000->n, "hc/gen.amni:688"); }))).uns_, f261_fin_lit(n_1451)));
return;
 }
if (((k_1453) == (((int64_t)2LL)))) { int64_t t_1460 = f261_fin_lit(n_1451); 
(void)(f245_ow(hr_str("((", 2)));
(void)(f246_ct(({ int64_t _r2001; if (((((*({ hrv *_t2002 = &(g524); int64_t _i2002 = t_1460; (S1*)_t2002->b + hr_ix(_i2002, _t2002->n, "hc/gen.amni:689"); }))).k_) == (((uint8_t)4LL)))) { _r2001 = t_1460;  } else { _r2001 = g542;  } _r2001; })));
(void)(f245_ow(hr_str(")", 1)));
(void)(f245_ow(f36_tok_text(((int64_t)((x_1452).t_)))));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if (((k_1453) == (((int64_t)3LL)))) { (void)(f263_gstr(n_1451));
return;
 }
if (((k_1453) == (((int64_t)4LL)))) { (void)(f245_ow(hr_str("true", 4)));
return;
 }
if (((k_1453) == (((int64_t)5LL)))) { (void)(f245_ow(hr_str("false", 5)));
return;
 }
if (((k_1453) == (((int64_t)6LL)))) { (void)(f245_ow(hr_str("((void*)0)", 10)));
return;
 }
if (((k_1453) == (((int64_t)8LL)))) { int64_t r_1474 = f155_rk(n_1451); 
if (((r_1474) == (((int64_t)1LL)))) { (void)(f269_lv_expr(f156_rv(n_1451)));
return;
 }
if (((r_1474) == (((int64_t)2LL)))) { (void)(({ hrv *_o2003 = &(g163); hr_fs(_o2003, hr_str("g", 1)); hr_fi(_o2003, f156_rv(n_1451)); }));
return;
 }
if (((r_1474) == (((int64_t)6LL)))) { (void)(f262_oint((*({ hrv *_t2004 = &(g412); int64_t _i2004 = f156_rv(n_1451); (int64_t*)_t2004->b + hr_ix(_i2004, _t2004->n, "hc/gen.amni:698"); })), false, f261_fin_lit(n_1451)));
return;
 }
(void)(f272_gerr(n_1451, hr_str("unsupported name use", 20)));
return;
 }
if (((k_1453) == (((int64_t)9LL)))) { (void)(f273_gbin(n_1451));
return;
 }
if (((k_1453) == (((int64_t)10LL)))) { (void)(f297_gun(n_1451));
return;
 }
if (((k_1453) == (((int64_t)14LL)))) { int64_t r_1656 = f155_rk(n_1451); 
int64_t a_1657 = ((int64_t)((x_1452).a_)); 
if (((r_1656) == (((int64_t)7LL)))) { int64_t t_1658 = f140_at(n_1451); 
int64_t p_1659 = f278_nt(); 
(void)(f245_ow(hr_str("({ ", 3)));
(void)(f246_ct(t_1658));
(void)(f245_ow(hr_str(" _t", 3)));
(void)(f279_oi(p_1659));
(void)(({ hrv *_o2005 = &(g163); hr_fs(_o2005, hr_str("; memset(&_t", 12)); hr_fi(_o2005, p_1659); hr_fs(_o2005, hr_str(", 0, sizeof _t", 14)); hr_fi(_o2005, p_1659); hr_fs(_o2005, hr_str("); _t", 5)); hr_fi(_o2005, p_1659); hr_fs(_o2005, hr_str(".tag = ", 7)); hr_fi(_o2005, f156_rv(n_1451)); hr_fs(_o2005, hr_str("; _t", 4)); hr_fi(_o2005, p_1659); hr_fs(_o2005, hr_str("; })", 4)); }));
return;
 }
if (((r_1656) == (((int64_t)8LL)))) { int64_t d_1660 = f174_deref(f140_at(a_1657)); 
if (((f156_rv(n_1451)) == (((int64_t)2LL)))) { (void)(({ hrv *_o2006 = &(g163); hr_fs(_o2006, hr_str("((int64_t)", 10)); hr_fi(_o2006, ((*({ hrv *_t2007 = &(g524); int64_t _i2007 = d_1660; (S1*)_t2007->b + hr_ix(_i2007, _t2007->n, "hc/gen.amni:709"); }))).b_); hr_fs(_o2006, hr_str(")", 1)); }));
return;
 }
if (f267_is_fix(d_1660)) { (void)(({ hrv *_o2008 = &(g163); hr_fs(_o2008, hr_str("((int64_t)", 10)); hr_fi(_o2008, ((*({ hrv *_t2009 = &(g524); int64_t _i2009 = d_1660; (S1*)_t2009->b + hr_ix(_i2009, _t2009->n, "hc/gen.amni:710"); }))).b_); hr_fs(_o2008, hr_str(")", 1)); }));
return;
 }
if (f268_is_lim(d_1660)) { (void)(f245_ow(hr_str("((int64_t)(", 11)));
if (((((*({ hrv *_t2010 = &(g524); int64_t _i2010 = f140_at(a_1657); (S1*)_t2010->b + hr_ix(_i2010, _t2010->n, "hc/gen.amni:711"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_gx0(a_1657));
(void)(f245_ow(hr_str(")->n)", 5)));
 } else { (void)(f274_gx(a_1657));
(void)(f245_ow(hr_str(").n)", 4)));
 }
return;
 }
if (((((*({ hrv *_t2011 = &(g524); int64_t _i2011 = f140_at(a_1657); (S1*)_t2011->b + hr_ix(_i2011, _t2011->n, "hc/gen.amni:712"); }))).k_) == (((uint8_t)10LL)))) { (void)(f245_ow(hr_str("((", 2)));
(void)(f260_gx0(a_1657));
(void)(f245_ow(hr_str(")->n)", 5)));
return;
 }
(void)(f245_ow(hr_str("(", 1)));
(void)(f274_gx(a_1657));
(void)(f245_ow(hr_str(").n", 3)));
return;
 }
if (((r_1656) == (((int64_t)5LL)))) { int64_t bt_1661 = f140_at(a_1657); 
int64_t st_1662 = f174_deref(bt_1661); 
int64_t si_1663 = ({ int64_t _r2012; if (((((*({ hrv *_t2013 = &(g524); int64_t _i2013 = st_1662; (S1*)_t2013->b + hr_ix(_i2013, _t2013->n, "hc/gen.amni:718"); }))).k_) == (((uint8_t)5LL)))) { _r2012 = ((int64_t)(((*({ hrv *_t2014 = &(g524); int64_t _i2014 = st_1662; (S1*)_t2014->b + hr_ix(_i2014, _t2014->n, "hc/gen.amni:718"); }))).a_));  } else { _r2012 = f209_ax(n_1451);  } _r2012; }); 
S11 f_1664 = (*({ hrv *_t2015 = &(g528); int64_t _i2015 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2016 = &(g527); int64_t _i2016 = si_1663; (S10*)_t2016->b + hr_ix(_i2016, _t2016->n, "hc/gen.amni:719"); }))).f0_)) + (int64_t)f156_rv(n_1451))); (S11*)_t2015->b + hr_ix(_i2015, _t2015->n, "hc/gen.amni:719"); })); 
(void)(f245_ow(hr_str("(", 1)));
if (((((*({ hrv *_t2017 = &(g524); int64_t _i2017 = bt_1661; (S1*)_t2017->b + hr_ix(_i2017, _t2017->n, "hc/gen.amni:721"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_gx0(a_1657));
(void)(f245_ow(hr_str(")->", 3)));
 } else { (void)(f274_gx(a_1657));
(void)(f245_ow(hr_str(").", 2)));
 }
(void)(f252_fname_into((&(g163)), ((int64_t)((f_1664).name_))));
return;
 }
(void)(f272_gerr(n_1451, hr_str("unsupported member", 18)));
return;
 }
if (((k_1453) == (((int64_t)12LL)))) { (void)(f299_gidx(n_1451));
return;
 }
if (((k_1453) == (((int64_t)13LL)))) { (void)(f300_gslice(n_1451));
return;
 }
if (((k_1453) == (((int64_t)15LL)))) { int64_t t_1679 = f140_at(n_1451); 
(void)(f245_ow(hr_str("((", 2)));
(void)(f246_ct(t_1679));
(void)(f245_ow(hr_str(")(", 2)));
(void)(f274_gx(((int64_t)((x_1452).a_))));
(void)(f245_ow(hr_str("))", 2)));
return;
 }
if (((k_1453) == (((int64_t)16LL)))) { (void)(f301_garr(n_1451));
return;
 }
if (((k_1453) == (((int64_t)17LL)))) { (void)(f302_gslit(n_1451));
return;
 }
if (((k_1453) == (((int64_t)11LL)))) { (void)(f303_gcall(n_1451));
return;
 }
if (((k_1453) == (((int64_t)23LL)))) { (void)(f245_ow(hr_str("({ ", 3)));
(void)(f324_gblk(n_1451, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((f140_at(n_1451)) != (g531))));
(void)(f245_ow(hr_str(" })", 3)));
return;
 }
if ((((((k_1453) == (((int64_t)19LL))) || ((k_1453) == (((int64_t)20LL)))) || ((k_1453) == (((int64_t)24LL)))) || ((k_1453) == (((int64_t)26LL))))) { int64_t t_1920 = f140_at(n_1451); 
if ((((t_1920) == (g531)) || ((t_1920) < (((int64_t)0LL))))) { (void)(f245_ow(hr_str("({ ", 3)));
(void)(f317_gstmt(n_1451));
(void)(f245_ow(hr_str(" })", 3)));
return;
 }
int64_t r_1921 = f278_nt(); 
(void)(f245_ow(hr_str("({ ", 3)));
(void)(f246_ct(t_1920));
(void)(f245_ow(hr_str(" _r", 3)));
(void)(f279_oi(r_1921));
(void)(f245_ow(hr_str("; ", 2)));
if (((k_1453) == (((int64_t)19LL)))) { (void)(f323_gif(n_1451, r_1921));
 } else { if (((k_1453) == (((int64_t)20LL)))) { (void)(f331_gmatch(n_1451, r_1921));
 } else { if (((k_1453) == (((int64_t)24LL)))) { (void)(f332_geblock(n_1451, r_1921));
 } else { (void)(f329_gloop(n_1451, r_1921));
 }
 }
 }
(void)(f245_ow(hr_str(" _r", 3)));
(void)(f279_oi(r_1921));
(void)(f245_ow(hr_str("; })", 4)));
return;
 }
if (((((((k_1453) == (((int64_t)28LL))) || ((k_1453) == (((int64_t)29LL)))) || ((k_1453) == (((int64_t)30LL)))) || ((k_1453) == (((int64_t)25LL)))) || ((k_1453) == (((int64_t)27LL))))) { (void)(f245_ow(hr_str("({ ", 3)));
(void)(f317_gstmt(n_1451));
(void)(f245_ow(hr_str(" })", 3)));
return;
 }
(void)(f272_gerr(n_1451, hr_str("unsupported expression in codegen", 33)));
}
static int64_t f261_fin_lit(int64_t n_1454) {
int64_t t_1455 = f140_at(n_1454); 
return ({ int64_t _r2018; if ((((t_1455) < (((int64_t)0LL))) || ((((*({ hrv *_t2019 = &(g524); int64_t _i2019 = t_1455; (S1*)_t2019->b + hr_ix(_i2019, _t2019->n, "hc/gen.amni:748"); }))).k_) == (((uint8_t)12LL))))) { _r2018 = g536;  } else { _r2018 = ({ int64_t _r2020; if (((((*({ hrv *_t2021 = &(g524); int64_t _i2021 = t_1455; (S1*)_t2021->b + hr_ix(_i2021, _t2021->n, "hc/gen.amni:748"); }))).k_) == (((uint8_t)13LL)))) { _r2020 = g542;  } else { _r2020 = t_1455;  } _r2020; });  } _r2018; });
}
static void f262_oint(int64_t v_1456, bool uns_1457, int64_t t_1458) {
int64_t k_1459 = ((int64_t)(((*({ hrv *_t2022 = &(g524); int64_t _i2022 = t_1458; (S1*)_t2022->b + hr_ix(_i2022, _t2022->n, "hc/gen.amni:140"); }))).k_)); 
if (((k_1459) == (((int64_t)4LL)))) { (void)(f245_ow(hr_str("((", 2)));
(void)(f246_ct(t_1458));
(void)(f245_ow(hr_str(")", 1)));
if (uns_1457) { (void)(({ hrv *_o2023 = &(g163); hr_fu(_o2023, ((uint64_t)(v_1456))); hr_fs(_o2023, hr_str(".0", 2)); }));
 } else { (void)(({ hrv *_o2024 = &(g163); hr_fi(_o2024, v_1456); hr_fs(_o2024, hr_str(".0", 2)); }));
 }
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if (((k_1459) == (((int64_t)2LL)))) { (void)(f245_ow(({ hsl _r2025; if (((v_1456) != (((int64_t)0LL)))) { _r2025 = hr_str("true", 4);  } else { _r2025 = hr_str("false", 5);  } _r2025; })));
return;
 }
(void)(f245_ow(hr_str("((", 2)));
(void)(f246_ct(({ int64_t _r2026; if (((k_1459) == (((int64_t)3LL)))) { _r2026 = t_1458;  } else { _r2026 = g536;  } _r2026; })));
(void)(f245_ow(hr_str(")", 1)));
if (uns_1457) { (void)(({ hrv *_o2027 = &(g163); hr_fu(_o2027, ((uint64_t)(v_1456))); hr_fs(_o2027, hr_str("ULL)", 4)); }));
return;
 }
if (((v_1456) == (((int64_t)((int64_t)((int64_t)(0 - (uint64_t)(((int64_t)9223372036854775807LL)))) - (int64_t)((int64_t)1LL)))))) { (void)(f245_ow(hr_str("(-9223372036854775807LL-1))", 27)));
return;
 }
(void)(({ hrv *_o2028 = &(g163); hr_fi(_o2028, v_1456); hr_fs(_o2028, hr_str("LL)", 3)); }));
}
static void f263_gstr(int64_t n_1461) {
int64_t t_1465 = f264_fin(n_1461); 
hsl s_1468 = f265_tok_str(((int64_t)(((*({ hrv *_t2029 = &(g675); int64_t _i2029 = n_1461; (S4*)_t2029->b + hr_ix(_i2029, _t2029->n, "hc/gen.amni:337"); }))).t_))); 
int64_t a_1469 = f140_at(n_1461); 
if (f253_is_res(a_1469)) { (void)(f245_ow(hr_str("hr_rfrom(hr_str(", 16)));
(void)(f266_cstr_lit(s_1468));
(void)(({ hrv *_o2030 = &(g163); hr_fs(_o2030, hr_str(", ", 2)); hr_fi(_o2030, (s_1468).n); hr_fs(_o2030, hr_str("), 1)", 5)); }));
return;
 }
if (f267_is_fix(a_1469)) { (void)(f245_ow(hr_str("((", 2)));
(void)(f246_ct(a_1469));
(void)(f245_ow(hr_str("){ ", 3)));
(void)(f266_cstr_lit(s_1468));
(void)(f245_ow(hr_str(" })", 3)));
return;
 }
if (f268_is_lim(a_1469)) { (void)(f245_ow(hr_str("((", 2)));
(void)(f246_ct(a_1469));
(void)(({ hrv *_o2031 = &(g163); hr_fs(_o2031, hr_str("){ ", 3)); hr_fi(_o2031, (s_1468).n); hr_fs(_o2031, hr_str(", ", 2)); }));
(void)(f266_cstr_lit(s_1468));
(void)(f245_ow(hr_str(" })", 3)));
return;
 }
(void)(f245_ow(hr_str("hr_str(", 7)));
(void)(f266_cstr_lit(s_1468));
(void)(({ hrv *_o2032 = &(g163); hr_fs(_o2032, hr_str(", ", 2)); hr_fi(_o2032, (s_1468).n); hr_fs(_o2032, hr_str(")", 1)); }));
}
static int64_t f264_fin(int64_t n_1462) {
int64_t c_1463 = f147_cv(n_1462); 
return ({ int64_t _r2033; if (((c_1463) >= (((int64_t)0LL)))) { _r2033 = c_1463;  } else { int64_t t_1464 = f140_at(n_1462); 
_r2033 = ({ int64_t _r2034; if (((t_1464) < (((int64_t)0LL)))) { _r2034 = g531;  } else { _r2034 = t_1464;  } _r2034; });  } _r2033; });
}
static hsl f265_tok_str(int64_t t_1466) {
S3 x_1467 = (*({ hrv *_t2035 = &(g885); int64_t _i2035 = t_1466; (S3*)_t2035->b + hr_ix(_i2035, _t2035->n, "hc/lex.amni:182"); })); 
return ({ hsl _t2036 = hr_sl(g881); int64_t _l2036 = ((int64_t)((x_1467).v_)), _h2036 = ((int64_t)((int64_t)((int64_t)((x_1467).v_)) + (int64_t)((int64_t)((x_1467).w_)))); if (_l2036 < 0 || _h2036 < _l2036 || _h2036 > _t2036.n) hr_slerr(_l2036, _h2036, _t2036.n, "hc/lex.amni:182"); (hsl){ _t2036.p + _l2036 * (int64_t)sizeof(uint8_t), _h2036 - _l2036 }; });
}
static void f266_cstr_lit(hsl s_1470) {
(void)(({ hrv *_v2037 = &(g163); uint8_t _x2037 = ((uint8_t)34LL); uint8_t *_p2037 = (uint8_t*)hr_grow(_v2037, 1, sizeof _x2037); *_p2037 = _x2037; _p2037; }));
{ hsl _v2039 = s_1470; for (int64_t _k2039 = 0; _k2039 < _v2039.n; _k2039++) { uint8_t c_1471 = ((uint8_t*)_v2039.p)[_k2039]; if ((((c_1471) == (((uint8_t)34LL))) || ((c_1471) == (((uint8_t)92LL))))) { (void)(({ hrv *_v2040 = &(g163); uint8_t _x2040 = ((uint8_t)92LL); uint8_t *_p2040 = (uint8_t*)hr_grow(_v2040, 1, sizeof _x2040); *_p2040 = _x2040; _p2040; }));
(void)(({ hrv *_v2041 = &(g163); uint8_t _x2041 = c_1471; uint8_t *_p2041 = (uint8_t*)hr_grow(_v2041, 1, sizeof _x2041); *_p2041 = _x2041; _p2041; }));
 } else { if (((((c_1471) >= (((uint8_t)32LL))) && ((c_1471) < (((uint8_t)127LL)))) && ((c_1471) != (((uint8_t)63LL))))) { (void)(({ hrv *_v2042 = &(g163); uint8_t _x2042 = c_1471; uint8_t *_p2042 = (uint8_t*)hr_grow(_v2042, 1, sizeof _x2042); *_p2042 = _x2042; _p2042; }));
 } else { (void)(({ hrv *_v2043 = &(g163); uint8_t _x2043 = ((uint8_t)92LL); uint8_t *_p2043 = (uint8_t*)hr_grow(_v2043, 1, sizeof _x2043); *_p2043 = _x2043; _p2043; }));
(void)(({ hrv *_v2044 = &(g163); uint8_t _x2044 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)((uint8_t)((c_1471) >> ((((uint8_t)6LL)) & 7))) & (uint64_t)((uint8_t)7LL))))); uint8_t *_p2044 = (uint8_t*)hr_grow(_v2044, 1, sizeof _x2044); *_p2044 = _x2044; _p2044; }));
(void)(({ hrv *_v2045 = &(g163); uint8_t _x2045 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)((uint8_t)((c_1471) >> ((((uint8_t)3LL)) & 7))) & (uint64_t)((uint8_t)7LL))))); uint8_t *_p2045 = (uint8_t*)hr_grow(_v2045, 1, sizeof _x2045); *_p2045 = _x2045; _p2045; }));
(void)(({ hrv *_v2046 = &(g163); uint8_t _x2046 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)c_1471 & (uint64_t)((uint8_t)7LL))))); uint8_t *_p2046 = (uint8_t*)hr_grow(_v2046, 1, sizeof _x2046); *_p2046 = _x2046; _p2046; }));
 }
 }
 } } _bk2038:; 
(void)(({ hrv *_v2047 = &(g163); uint8_t _x2047 = ((uint8_t)34LL); uint8_t *_p2047 = (uint8_t*)hr_grow(_v2047, 1, sizeof _x2047); *_p2047 = _x2047; _p2047; }));
}
static bool f267_is_fix(int64_t t_1472) {
return (((((*({ hrv *_t2048 = &(g524); int64_t _i2048 = t_1472; (S1*)_t2048->b + hr_ix(_i2048, _t2048->n, "hc/gen.amni:20"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t2049 = &(g524); int64_t _i2049 = t_1472; (S1*)_t2049->b + hr_ix(_i2049, _t2049->n, "hc/gen.amni:20"); }))).s_))) == (((int64_t)1LL))));
}
static bool f268_is_lim(int64_t t_1473) {
return (((((*({ hrv *_t2050 = &(g524); int64_t _i2050 = t_1473; (S1*)_t2050->b + hr_ix(_i2050, _t2050->n, "hc/gen.amni:19"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t2051 = &(g524); int64_t _i2051 = t_1473; (S1*)_t2051->b + hr_ix(_i2051, _t2051->n, "hc/gen.amni:19"); }))).s_))) == (((int64_t)3LL))));
}
static void f269_lv_expr(int64_t v_1475) {
bool p_1477 = f270_lv_isptr(v_1475); 
if (((((int64_t)(((*({ hrv *_t2052 = &(g372); int64_t _i2052 = v_1475; (S12*)_t2052->b + hr_ix(_i2052, _t2052->n, "hc/gen.amni:115"); }))).cfn_))) != (g179))) { (void)(f245_ow(({ hsl _r2053; if (p_1477) { _r2053 = hr_str("(**c", 4);  } else { _r2053 = hr_str("(*c", 3);  } _r2053; })));
(void)(({ hrv *_o2054 = &(g163); hr_fi(_o2054, v_1475); hr_fs(_o2054, hr_str(")", 1)); }));
return;
 }
if (p_1477) { (void)(f245_ow(hr_str("(*", 2)));
(void)(f271_lv_name(v_1475));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
(void)(f271_lv_name(v_1475));
}
static bool f270_lv_isptr(int64_t v_1476) {
return (((((uint16_t)((uint64_t)((*({ hrv *_t2055 = &(g372); int64_t _i2055 = v_1476; (S12*)_t2055->b + hr_ix(_i2055, _t2055->n, "hc/gen.amni:112"); }))).fl_ & (uint64_t)((uint16_t)8LL)))) != (((uint16_t)0LL))) && ((((*({ hrv *_t2056 = &(g524); int64_t _i2056 = ((*({ hrv *_t2057 = &(g372); int64_t _i2057 = v_1476; (S12*)_t2057->b + hr_ix(_i2057, _t2057->n, "hc/gen.amni:112"); }))).ty_; (S1*)_t2056->b + hr_ix(_i2056, _t2056->n, "hc/gen.amni:112"); }))).k_) != (((uint8_t)10LL))));
}
static void f271_lv_name(int64_t v_1478) {
{ hsl _v2059 = f10_nm(((int64_t)(((*({ hrv *_t2060 = &(g372); int64_t _i2060 = v_1478; (S12*)_t2060->b + hr_ix(_i2060, _t2060->n, "hc/gen.amni:111"); }))).name_))); for (int64_t _k2059 = 0; _k2059 < _v2059.n; _k2059++) { uint8_t c_1479 = ((uint8_t*)_v2059.p)[_k2059]; (void)(({ hrv *_v2061 = &(g163); uint8_t _x2061 = ({ uint8_t _r2062; if ((((c_1479) == (((uint8_t)36LL))) || ((c_1479) == (((uint8_t)58LL))))) { _r2062 = ((uint8_t)95LL);  } else { _r2062 = c_1479;  } _r2062; }); uint8_t *_p2061 = (uint8_t*)hr_grow(_v2061, 1, sizeof _x2061); *_p2061 = _x2061; _p2061; }));
 } } _bk2058:; 
(void)(({ hrv *_o2063 = &(g163); hr_fs(_o2063, hr_str("_", 1)); hr_fi(_o2063, v_1478); }));
}
static void f272_gerr(int64_t n_1480, hsl m_1481) {
if ((((g182).n) > (((int64_t)0LL)))) { return;
 }
S3 x_1482 = (*({ hrv *_t2064 = &(g885); int64_t _i2064 = ((*({ hrv *_t2065 = &(g675); int64_t _i2065 = f103_max(n_1480, ((int64_t)0LL)); (S4*)_t2065->b + hr_ix(_i2065, _t2065->n, "hc/gen.amni:15"); }))).t_; (S3*)_t2064->b + hr_ix(_i2064, _t2064->n, "hc/gen.amni:15"); })); 
(void)(({ hrv *_v2066 = &(g182); hsl _s2066 = f10_nm(((int64_t)(((*({ hrv *_t2067 = &(g884); int64_t _i2067 = (x_1482).f_; (S2*)_t2067->b + hr_ix(_i2067, _t2067->n, "hc/gen.amni:15"); }))).name_))); hr_append(_v2066, _s2066.p, _s2066.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o2068 = &(g182); hr_fs(_o2068, hr_str(":", 1)); hr_fi(_o2068, (x_1482).line_); hr_fs(_o2068, hr_str(": error: ", 9)); hr_fs(_o2068, m_1481); }));
}
static void f273_gbin(int64_t n_1483) {
S4 x_1484 = (*({ hrv *_t2069 = &(g675); int64_t _i2069 = n_1483; (S4*)_t2069->b + hr_ix(_i2069, _t2069->n, "hc/gen.amni:255"); })); 
int64_t o_1485 = ((int64_t)((x_1484).op_)); 
int64_t a_1486 = ((int64_t)((x_1484).a_)); 
int64_t b_1487 = ((int64_t)((x_1484).b_)); 
if ((((o_1485) == (((int64_t)52LL))) || ((o_1485) == (((int64_t)53LL))))) { (void)(f245_ow(hr_str("(", 1)));
(void)(f274_gx(a_1486));
(void)(f245_ow(({ hsl _r2070; if (((o_1485) == (((int64_t)52LL)))) { _r2070 = hr_str(" && ", 4);  } else { _r2070 = hr_str(" || ", 4);  } _r2070; })));
(void)(f274_gx(b_1487));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
bool cmp_1491 = (((((((o_1485) == (((int64_t)37LL))) || ((o_1485) == (((int64_t)38LL)))) || ((o_1485) == (((int64_t)39LL)))) || ((o_1485) == (((int64_t)40LL)))) || ((o_1485) == (((int64_t)41LL)))) || ((o_1485) == (((int64_t)42LL)))); 
if (cmp_1491) { int64_t m_1492 = f209_ax(n_1483); 
int64_t ta_1493 = f264_fin(a_1486); 
int64_t tb_1494 = f264_fin(b_1487); 
if (((m_1492) == (((int64_t)1LL)))) { (void)(f245_ow(hr_str("((uint64_t)(", 12)));
(void)(f274_gx(a_1486));
(void)(f245_ow(hr_str(") ", 2)));
(void)(f245_ow(f275_cmp_op(o_1485)));
(void)(f245_ow(hr_str(" (uint64_t)(", 12)));
(void)(f274_gx(b_1487));
(void)(f245_ow(hr_str("))", 2)));
return;
 }
if (((m_1492) == (((int64_t)2LL)))) { if (((o_1485) == (((int64_t)38LL)))) { (void)(f245_ow(hr_str("!", 1)));
 }
(void)(f245_ow(hr_str("hr_streq(", 9)));
(void)(f276_gas(a_1486));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f276_gas(b_1487));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if (((m_1492) == (((int64_t)3LL)))) { int64_t et_1509 = ({ int64_t _r2071; if ((((((*({ hrv *_t2072 = &(g524); int64_t _i2072 = ta_1493; (S1*)_t2072->b + hr_ix(_i2072, _t2072->n, "hc/gen.amni:263"); }))).k_) == (((uint8_t)7LL))) || ((((*({ hrv *_t2073 = &(g524); int64_t _i2073 = ta_1493; (S1*)_t2073->b + hr_ix(_i2073, _t2073->n, "hc/gen.amni:263"); }))).k_) == (((uint8_t)19LL))))) { _r2071 = tb_1494;  } else { _r2071 = ta_1493;  } _r2071; }); 
(void)(f280_gen_heq(et_1509));
if (((o_1485) == (((int64_t)38LL)))) { (void)(f245_ow(hr_str("!", 1)));
 }
(void)(f245_ow(hr_str("heq", 3)));
(void)(f279_oi(et_1509));
(void)(f245_ow(hr_str("(", 1)));
if (f289_hsl_ty(et_1509)) { (void)(f276_gas(a_1486));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f276_gas(b_1487));
 } else { (void)(f290_gxas(a_1486, et_1509));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f290_gxas(b_1487, et_1509));
 }
(void)(f245_ow(hr_str(")", 1)));
return;
 }
int64_t ka_1602 = ((int64_t)(((*({ hrv *_t2074 = &(g524); int64_t _i2074 = ta_1493; (S1*)_t2074->b + hr_ix(_i2074, _t2074->n, "hc/gen.amni:264"); }))).k_)); 
if (((((ka_1602) == (((int64_t)10LL))) || ((ka_1602) == (((int64_t)11LL)))) || ((((*({ hrv *_t2075 = &(g524); int64_t _i2075 = tb_1494; (S1*)_t2075->b + hr_ix(_i2075, _t2075->n, "hc/gen.amni:265"); }))).k_) == (((uint8_t)10LL))))) { (void)(f245_ow(hr_str("((void*)(", 9)));
(void)(f274_gx(a_1486));
(void)(f245_ow(hr_str(") ", 2)));
(void)(f245_ow(f275_cmp_op(o_1485)));
(void)(f245_ow(hr_str(" (void*)(", 9)));
(void)(f274_gx(b_1487));
(void)(f245_ow(hr_str("))", 2)));
return;
 }
(void)(f245_ow(hr_str("((", 2)));
(void)(f274_gx(a_1486));
(void)(f245_ow(hr_str(") ", 2)));
(void)(f245_ow(f275_cmp_op(o_1485)));
(void)(f245_ow(hr_str(" (", 2)));
(void)(f274_gx(b_1487));
(void)(f245_ow(hr_str("))", 2)));
return;
 }
(void)(f291_garith(o_1485, f264_fin(n_1483), a_1486, b_1487, ((int64_t)0LL), n_1483));
}
static void f274_gx(int64_t n_1488) {
int64_t c_1489 = f147_cv(n_1488); 
int64_t t_1490 = f140_at(n_1488); 
if ((((c_1489) < (((int64_t)0LL))) || ((c_1489) == (t_1490)))) { (void)(f256_gx1(n_1488));
return;
 }
(void)(f255_gcv(n_1488, t_1490, c_1489));
}
static hsl f275_cmp_op(int64_t o_1495) {
if (((o_1495) == (((int64_t)37LL)))) { return hr_str("==", 2);
 }
if (((o_1495) == (((int64_t)38LL)))) { return hr_str("!=", 2);
 }
if (((o_1495) == (((int64_t)39LL)))) { return hr_str("<", 1);
 }
if (((o_1495) == (((int64_t)40LL)))) { return hr_str(">", 1);
 }
if (((o_1495) == (((int64_t)41LL)))) { return hr_str("<=", 2);
 }
if (((o_1495) == (((int64_t)42LL)))) { return hr_str(">=", 2);
 }
return hr_str("\077", 1);
}
static void f276_gas(int64_t n_1496) {
int64_t c_1497 = f147_cv(n_1496); 
int64_t t_1498 = f140_at(n_1496); 
if (((((c_1497) >= (((int64_t)0LL))) && ((c_1497) != (t_1498))) && ((((*({ hrv *_t2076 = &(g524); int64_t _i2076 = c_1497; (S1*)_t2076->b + hr_ix(_i2076, _t2076->n, "hc/gen.amni:194"); }))).k_) == (((uint8_t)9LL))))) { (void)(f277_gsl(n_1496, t_1498));
return;
 }
if ((((c_1497) >= (((int64_t)0LL))) && ((c_1497) != (t_1498)))) { int64_t p_1508 = f278_nt(); 
(void)(f245_ow(hr_str("({ ", 3)));
(void)(f246_ct(c_1497));
(void)(f245_ow(hr_str(" _t", 3)));
(void)(f279_oi(p_1508));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(n_1496));
(void)(f245_ow(hr_str("; ", 2)));
if (f253_is_res(c_1497)) { (void)(f245_ow(hr_str("hr_sl(_t", 8)));
(void)(f279_oi(p_1508));
(void)(f245_ow(hr_str(")", 1)));
 } else { if (f267_is_fix(c_1497)) { (void)(f245_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f279_oi(p_1508));
(void)(({ hrv *_o2077 = &(g163); hr_fs(_o2077, hr_str(".e, ", 4)); hr_fi(_o2077, ((*({ hrv *_t2078 = &(g524); int64_t _i2078 = c_1497; (S1*)_t2078->b + hr_ix(_i2078, _t2078->n, "hc/gen.amni:195"); }))).b_); hr_fs(_o2077, hr_str(" }", 2)); }));
 } else { if (((((*({ hrv *_t2079 = &(g524); int64_t _i2079 = c_1497; (S1*)_t2079->b + hr_ix(_i2079, _t2079->n, "hc/gen.amni:195"); }))).k_) == (((uint8_t)9LL)))) { (void)(f245_ow(hr_str("_t", 2)));
(void)(f279_oi(p_1508));
 } else { (void)(f245_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f279_oi(p_1508));
(void)(f245_ow(hr_str(".e, _t", 6)));
(void)(f279_oi(p_1508));
(void)(f245_ow(hr_str(".n }", 4)));
 }
 }
 }
(void)(f245_ow(hr_str("; })", 4)));
return;
 }
(void)(f277_gsl(n_1496, t_1498));
}
static void f277_gsl(int64_t n_1499, int64_t f_1500) {
int64_t d_1501 = f174_deref(f_1500); 
int64_t k_1502 = ((int64_t)(((*({ hrv *_t2080 = &(g524); int64_t _i2080 = d_1501; (S1*)_t2080->b + hr_ix(_i2080, _t2080->n, "hc/gen.amni:171"); }))).k_)); 
if ((((((*({ hrv *_t2081 = &(g524); int64_t _i2081 = f_1500; (S1*)_t2081->b + hr_ix(_i2081, _t2081->n, "hc/gen.amni:172"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2082 = &(g524); int64_t _i2082 = f_1500; (S1*)_t2082->b + hr_ix(_i2082, _t2082->n, "hc/gen.amni:172"); }))).c_) < (((int32_t)0LL))))) { int64_t p_1503 = f278_nt(); 
(void)(f245_ow(hr_str("({ ", 3)));
(void)(f246_ct(f_1500));
(void)(f245_ow(hr_str(" _t", 3)));
(void)(f279_oi(p_1503));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f260_gx0(n_1499));
(void)(f245_ow(hr_str("; ", 2)));
if (((k_1502) == (((int64_t)9LL)))) { (void)(f245_ow(hr_str("*_t", 3)));
(void)(f279_oi(p_1503));
 } else { if (f253_is_res(d_1501)) { (void)(f245_ow(hr_str("hr_sl(*_t", 9)));
(void)(f279_oi(p_1503));
(void)(f245_ow(hr_str(")", 1)));
 } else { if (f267_is_fix(d_1501)) { (void)(f245_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f279_oi(p_1503));
(void)(({ hrv *_o2083 = &(g163); hr_fs(_o2083, hr_str("->e, ", 5)); hr_fi(_o2083, ((*({ hrv *_t2084 = &(g524); int64_t _i2084 = d_1501; (S1*)_t2084->b + hr_ix(_i2084, _t2084->n, "hc/gen.amni:177"); }))).b_); hr_fs(_o2083, hr_str(" }", 2)); }));
 } else { (void)(f245_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f279_oi(p_1503));
(void)(f245_ow(hr_str("->e, _t", 7)));
(void)(f279_oi(p_1503));
(void)(f245_ow(hr_str("->n }", 5)));
 }
 }
 }
(void)(f245_ow(hr_str("; })", 4)));
return;
 }
if ((((k_1502) == (((int64_t)9LL))) || ((k_1502) == (((int64_t)18LL))))) { (void)(f260_gx0(n_1499));
return;
 }
if (f253_is_res(d_1501)) { (void)(f245_ow(hr_str("hr_sl(", 6)));
if (f257_is_place(n_1499)) { (void)(f260_gx0(n_1499));
 } else { int64_t tk0_1505 = f258_tmp(d_1501, true); 
(void)(f245_ow(hr_str("*hr_tmp(&", 9)));
(void)(f259_ot(tk0_1505));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f260_gx0(n_1499));
(void)(f245_ow(hr_str(")", 1)));
 }
(void)(f245_ow(hr_str(")", 1)));
return;
 }
int64_t p_1506 = f278_nt(); 
(void)(f245_ow(hr_str("({ ", 3)));
(void)(f246_ct(d_1501));
(void)(f245_ow(hr_str(" *_t", 4)));
(void)(f279_oi(p_1506));
(void)(f245_ow(hr_str(" = ", 3)));
if (f257_is_place(n_1499)) { (void)(f245_ow(hr_str("&(", 2)));
(void)(f260_gx0(n_1499));
(void)(f245_ow(hr_str(")", 1)));
 } else { int64_t tk0_1507 = f258_tmp(d_1501, false); 
(void)(f245_ow(hr_str("&(", 2)));
(void)(f259_ot(tk0_1507));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f260_gx0(n_1499));
(void)(f245_ow(hr_str(")", 1)));
 }
(void)(f245_ow(hr_str("; ", 2)));
if (f267_is_fix(d_1501)) { (void)(f245_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f279_oi(p_1506));
(void)(({ hrv *_o2085 = &(g163); hr_fs(_o2085, hr_str("->e, ", 5)); hr_fi(_o2085, ((*({ hrv *_t2086 = &(g524); int64_t _i2086 = d_1501; (S1*)_t2086->b + hr_ix(_i2086, _t2086->n, "hc/gen.amni:188"); }))).b_); hr_fs(_o2085, hr_str(" }", 2)); }));
 } else { (void)(f245_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f279_oi(p_1506));
(void)(f245_ow(hr_str("->e, _t", 7)));
(void)(f279_oi(p_1506));
(void)(f245_ow(hr_str("->n }", 5)));
 }
(void)(f245_ow(hr_str("; })", 4)));
}
static int64_t f278_nt(void) {
g178++;
return g178;
}
static void f279_oi(int64_t v_1504) {
(void)(({ hrv *_o2087 = &(g163); hr_fi(_o2087, v_1504); }));
}
static void f280_gen_heq(int64_t t_1510) {
(void)(f248_cn_grow());
if ((((*({ hrv *_t2088 = &(g175); int64_t _i2088 = t_1510; (uint8_t*)_t2088->b + hr_ix(_i2088, _t2088->n, "hc/gen.amni:460"); }))) != (((uint8_t)0LL)))) { return;
 }
(*({ hrv *_t2089 = &(g175); int64_t _i2089 = t_1510; (uint8_t*)_t2089->b + hr_ix(_i2089, _t2089->n, "hc/gen.amni:461"); })) = ((uint8_t)1LL);
S1 x_1511 = (*({ hrv *_t2090 = &(g524); int64_t _i2090 = t_1510; (S1*)_t2090->b + hr_ix(_i2090, _t2090->n, "hc/gen.amni:462"); })); 
int64_t k_1512 = ((int64_t)((x_1511).k_)); 
(void)(f247_cbody(t_1510));
bool sl_1513 = (((k_1512) == (((int64_t)9LL))) || ((((k_1512) == (((int64_t)8LL))) && (!(f267_is_fix(t_1510)))) && (!(f268_is_lim(t_1510))))); 
(void)(f281_comp_pre(t_1510, false));
L93 sig_1576 = ({ L93 _t2091; memset(&_t2091, 0, sizeof _t2091); _t2091.n = 0; _t2091; }); 
(void)(({ L93 *_l2092 = &(sig_1576); hrv _o2092 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2092, hr_str("static bool heq", 15)); hr_fi(&_o2092, t_1510); hr_fs(&_o2092, hr_str("(", 1)); if (_l2092->n + _o2092.n > 256) hr_die("format past a limited array's capacity", "hc/gen.amni:467"); memcpy(_l2092->e + _l2092->n, _o2092.b, (size_t)_o2092.n); _l2092->n += _o2092.n; }));
hsl c_1577 = ({ hsl _r2093; if (sl_1513) { _r2093 = hr_str("hsl", 3);  } else { _r2093 = f249_cn(t_1510);  } _r2093; }); 
(void)(({ L93 *_v2094 = &(sig_1576); hsl _s2094 = c_1577; if (_v2094->n + _s2094.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:469"); memmove(_v2094->e + _v2094->n, _s2094.p, (size_t)_s2094.n * sizeof _v2094->e[0]); _v2094->n += _s2094.n; }));
(void)(({ L93 *_v2095 = &(sig_1576); hsl _s2095 = hr_str(" a, ", 4); if (_v2095->n + _s2095.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:469"); memmove(_v2095->e + _v2095->n, _s2095.p, (size_t)_s2095.n * sizeof _v2095->e[0]); _v2095->n += _s2095.n; }));
(void)(({ L93 *_v2096 = &(sig_1576); hsl _s2096 = c_1577; if (_v2096->n + _s2096.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:469"); memmove(_v2096->e + _v2096->n, _s2096.p, (size_t)_s2096.n * sizeof _v2096->e[0]); _v2096->n += _s2096.n; }));
(void)(({ L93 *_v2097 = &(sig_1576); hsl _s2097 = hr_str(" b)", 3); if (_v2097->n + _s2097.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:469"); memmove(_v2097->e + _v2097->n, _s2097.p, (size_t)_s2097.n * sizeof _v2097->e[0]); _v2097->n += _s2097.n; }));
(void)(({ hrv *_v2098 = &(g166); hsl _s2098 = ({ hsl _t2099 = ({ L93 *_t2100 = &(sig_1576); (hsl){ (uint8_t*)_t2100->e, _t2100->n }; }); int64_t _l2099 = 0, _h2099 = _t2099.n; if (_l2099 < 0 || _h2099 < _l2099 || _h2099 > _t2099.n) hr_slerr(_l2099, _h2099, _t2099.n, "hc/gen.amni:470"); (hsl){ _t2099.p + _l2099 * (int64_t)sizeof(uint8_t), _h2099 - _l2099 }; }); hr_append(_v2098, _s2098.p, _s2098.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2101 = &(g166); hsl _s2101 = hr_str(";\012", 2); hr_append(_v2101, _s2101.p, _s2101.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2102 = &(g169); hsl _s2102 = ({ hsl _t2103 = ({ L93 *_t2104 = &(sig_1576); (hsl){ (uint8_t*)_t2104->e, _t2104->n }; }); int64_t _l2103 = 0, _h2103 = _t2103.n; if (_l2103 < 0 || _h2103 < _l2103 || _h2103 > _t2103.n) hr_slerr(_l2103, _h2103, _t2103.n, "hc/gen.amni:471"); (hsl){ _t2103.p + _l2103 * (int64_t)sizeof(uint8_t), _h2103 - _l2103 }; }); hr_append(_v2102, _s2102.p, _s2102.n, sizeof(uint8_t)); }));
(void)(f286_hh(hr_str(" { ", 3)));
if ((((k_1512) == (((int64_t)5LL))) || ((k_1512) == (((int64_t)7LL))))) { int64_t si_1578 = ({ int64_t _r2105; if (((k_1512) == (((int64_t)5LL)))) { _r2105 = ((int64_t)((x_1511).a_));  } else { _r2105 = ((int64_t)(((*({ hrv *_t2106 = &(g530); int64_t _i2106 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2107 = &(g529); int64_t _i2107 = (x_1511).a_; (S8*)_t2107->b + hr_ix(_i2107, _t2107->n, "hc/gen.amni:473"); }))).v0_)) + (int64_t)((int64_t)((x_1511).c_)))); (S9*)_t2106->b + hr_ix(_i2106, _t2106->n, "hc/gen.amni:473"); }))).si_));  } _r2105; }); 
(void)(f286_hh(hr_str("return true", 11)));
if (((si_1578) >= (((int64_t)0LL)))) { int64_t f0_1579 = ((int64_t)(((*({ hrv *_t2108 = &(g527); int64_t _i2108 = si_1578; (S10*)_t2108->b + hr_ix(_i2108, _t2108->n, "hc/gen.amni:475"); }))).f0_)); 
{ int32_t _e2110 = ((*({ hrv *_t2111 = &(g527); int64_t _i2111 = si_1578; (S10*)_t2111->b + hr_ix(_i2111, _t2111->n, "hc/gen.amni:475"); }))).fnum_; for (int32_t i_1580 = 0; i_1580 < _e2110; i_1580++) { S11 f_1581 = (*({ hrv *_t2112 = &(g528); int64_t _i2112 = ((int64_t)((int64_t)f0_1579 + (int64_t)((int64_t)(i_1580)))); (S11*)_t2112->b + hr_ix(_i2112, _t2112->n, "hc/gen.amni:475"); })); 
if ((((f_1581).ty_) < (((int32_t)0LL)))) { continue;
 }
L94 ea_1582 = ({ L94 _t2113; memset(&_t2113, 0, sizeof _t2113); _t2113.n = 0; _t2113; }); 
L94 eb_1583 = ({ L94 _t2114; memset(&_t2114, 0, sizeof _t2114); _t2114.n = 0; _t2114; }); 
(void)(({ L94 *_v2115 = &(ea_1582); hsl _s2115 = hr_str("a.", 2); if (_v2115->n + _s2115.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:475"); memmove(_v2115->e + _v2115->n, _s2115.p, (size_t)_s2115.n * sizeof _v2115->e[0]); _v2115->n += _s2115.n; }));
(void)(({ L94 *_v2116 = &(eb_1583); hsl _s2116 = hr_str("b.", 2); if (_v2116->n + _s2116.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:475"); memmove(_v2116->e + _v2116->n, _s2116.p, (size_t)_s2116.n * sizeof _v2116->e[0]); _v2116->n += _s2116.n; }));
{ hsl _v2118 = f10_nm(((int64_t)((f_1581).name_))); for (int64_t _k2118 = 0; _k2118 < _v2118.n; _k2118++) { uint8_t ch_1584 = ((uint8_t*)_v2118.p)[_k2118]; (void)(({ L94 *_v2119 = &(ea_1582); uint8_t _x2119 = ch_1584; if (_v2119->n >= 128) hr_die("push past a limited array's capacity", "hc/gen.amni:475"); _v2119->e[_v2119->n] = _x2119; &_v2119->e[_v2119->n++]; }));
(void)(({ L94 *_v2120 = &(eb_1583); uint8_t _x2120 = ch_1584; if (_v2120->n >= 128) hr_die("push past a limited array's capacity", "hc/gen.amni:475"); _v2120->e[_v2120->n] = _x2120; &_v2120->e[_v2120->n++]; }));
 } } _bk2117:; 
(void)(({ L94 *_v2121 = &(ea_1582); uint8_t _x2121 = ((uint8_t)95LL); if (_v2121->n >= 128) hr_die("push past a limited array's capacity", "hc/gen.amni:475"); _v2121->e[_v2121->n] = _x2121; &_v2121->e[_v2121->n++]; }));
(void)(({ L94 *_v2122 = &(eb_1583); uint8_t _x2122 = ((uint8_t)95LL); if (_v2122->n >= 128) hr_die("push past a limited array's capacity", "hc/gen.amni:475"); _v2122->e[_v2122->n] = _x2122; &_v2122->e[_v2122->n++]; }));
(void)(f286_hh(hr_str(" && ", 4)));
(void)(f288_heq_val(((int64_t)((f_1581).ty_)), ({ hsl _t2123 = ({ L94 *_t2124 = &(ea_1582); (hsl){ (uint8_t*)_t2124->e, _t2124->n }; }); int64_t _l2123 = 0, _h2123 = _t2123.n; if (_l2123 < 0 || _h2123 < _l2123 || _h2123 > _t2123.n) hr_slerr(_l2123, _h2123, _t2123.n, "hc/gen.amni:475"); (hsl){ _t2123.p + _l2123 * (int64_t)sizeof(uint8_t), _h2123 - _l2123 }; }), ({ hsl _t2125 = ({ L94 *_t2126 = &(eb_1583); (hsl){ (uint8_t*)_t2126->e, _t2126->n }; }); int64_t _l2125 = 0, _h2125 = _t2125.n; if (_l2125 < 0 || _h2125 < _l2125 || _h2125 > _t2125.n) hr_slerr(_l2125, _h2125, _t2125.n, "hc/gen.amni:475"); (hsl){ _t2125.p + _l2125 * (int64_t)sizeof(uint8_t), _h2125 - _l2125 }; })));
 } } _bk2109:; 
 }
(void)(f286_hh(hr_str("; ", 2)));
 }
if (((k_1512) == (((int64_t)6LL)))) { int64_t ei_1589 = ((int64_t)((x_1511).a_)); 
int64_t v0_1590 = ((int64_t)(((*({ hrv *_t2127 = &(g529); int64_t _i2127 = ei_1589; (S8*)_t2127->b + hr_ix(_i2127, _t2127->n, "hc/gen.amni:479"); }))).v0_)); 
(void)(f286_hh(hr_str("if (a.tag != b.tag) return false; ", 34)));
{ int32_t _e2129 = ((*({ hrv *_t2130 = &(g529); int64_t _i2130 = ei_1589; (S8*)_t2130->b + hr_ix(_i2130, _t2130->n, "hc/gen.amni:481"); }))).vnum_; for (int32_t i_1591 = 0; i_1591 < _e2129; i_1591++) { S9 v_1592 = (*({ hrv *_t2131 = &(g530); int64_t _i2131 = ((int64_t)((int64_t)v0_1590 + (int64_t)((int64_t)(i_1591)))); (S9*)_t2131->b + hr_ix(_i2131, _t2131->n, "hc/gen.amni:481"); })); 
if (((((v_1592).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t2132 = &(g527); int64_t _i2132 = (v_1592).si_; (S10*)_t2132->b + hr_ix(_i2132, _t2132->n, "hc/gen.amni:481"); }))).zero_)))) { L96 ea_1593 = ({ L96 _t2133; memset(&_t2133, 0, sizeof _t2133); _t2133.n = 0; _t2133; }); 
L96 eb_1594 = ({ L96 _t2134; memset(&_t2134, 0, sizeof _t2134); _t2134.n = 0; _t2134; }); 
(void)(({ L96 *_l2135 = &(ea_1593); hrv _o2135 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2135, hr_str("a.u.v", 5)); hr_fi(&_o2135, i_1591); if (_l2135->n + _o2135.n > 64) hr_die("format past a limited array's capacity", "hc/gen.amni:481"); memcpy(_l2135->e + _l2135->n, _o2135.b, (size_t)_o2135.n); _l2135->n += _o2135.n; }));
(void)(({ L96 *_l2136 = &(eb_1594); hrv _o2136 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2136, hr_str("b.u.v", 5)); hr_fi(&_o2136, i_1591); if (_l2136->n + _o2136.n > 64) hr_die("format past a limited array's capacity", "hc/gen.amni:481"); memcpy(_l2136->e + _l2136->n, _o2136.b, (size_t)_o2136.n); _l2136->n += _o2136.n; }));
(void)(({ hrv *_o2137 = &(g169); hr_fs(_o2137, hr_str("if (a.tag == ", 13)); hr_fi(_o2137, i_1591); hr_fs(_o2137, hr_str(") return ", 9)); }));
(void)(f288_heq_val(f123_t_variant(ei_1589, ((int64_t)(i_1591))), ({ hsl _t2138 = ({ L96 *_t2139 = &(ea_1593); (hsl){ (uint8_t*)_t2139->e, _t2139->n }; }); int64_t _l2138 = 0, _h2138 = _t2138.n; if (_l2138 < 0 || _h2138 < _l2138 || _h2138 > _t2138.n) hr_slerr(_l2138, _h2138, _t2138.n, "hc/gen.amni:481"); (hsl){ _t2138.p + _l2138 * (int64_t)sizeof(uint8_t), _h2138 - _l2138 }; }), ({ hsl _t2140 = ({ L96 *_t2141 = &(eb_1594); (hsl){ (uint8_t*)_t2141->e, _t2141->n }; }); int64_t _l2140 = 0, _h2140 = _t2140.n; if (_l2140 < 0 || _h2140 < _l2140 || _h2140 > _t2140.n) hr_slerr(_l2140, _h2140, _t2140.n, "hc/gen.amni:481"); (hsl){ _t2140.p + _l2140 * (int64_t)sizeof(uint8_t), _h2140 - _l2140 }; })));
(void)(f286_hh(hr_str("; ", 2)));
 }
 } } _bk2128:; 
(void)(f286_hh(hr_str("return true; ", 13)));
 }
if ((((k_1512) == (((int64_t)8LL))) || ((k_1512) == (((int64_t)9LL))))) { int64_t e_1595 = ((int64_t)((x_1511).a_)); 
L94 ea_1596 = ({ L94 _t2142; memset(&_t2142, 0, sizeof _t2142); _t2142.n = 0; _t2142; }); 
L94 eb_1597 = ({ L94 _t2143; memset(&_t2143, 0, sizeof _t2143); _t2143.n = 0; _t2143; }); 
if (f267_is_fix(t_1510)) { (void)(({ hrv *_o2144 = &(g169); hr_fs(_o2144, hr_str("for (int64_t i = 0; i < ", 24)); hr_fi(_o2144, (x_1511).b_); hr_fs(_o2144, hr_str("; i++) if (!(", 13)); }));
(void)(({ L94 *_v2145 = &(ea_1596); hsl _s2145 = hr_str("a.e[i]", 6); if (_v2145->n + _s2145.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:487"); memmove(_v2145->e + _v2145->n, _s2145.p, (size_t)_s2145.n * sizeof _v2145->e[0]); _v2145->n += _s2145.n; }));
(void)(({ L94 *_v2146 = &(eb_1597); hsl _s2146 = hr_str("b.e[i]", 6); if (_v2146->n + _s2146.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:487"); memmove(_v2146->e + _v2146->n, _s2146.p, (size_t)_s2146.n * sizeof _v2146->e[0]); _v2146->n += _s2146.n; }));
 } else { if (f268_is_lim(t_1510)) { (void)(f286_hh(hr_str("if (a.n != b.n) return false; for (int64_t i = 0; i < a.n; i++) if (!(", 70)));
(void)(({ L94 *_v2147 = &(ea_1596); hsl _s2147 = hr_str("a.e[i]", 6); if (_v2147->n + _s2147.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:488"); memmove(_v2147->e + _v2147->n, _s2147.p, (size_t)_s2147.n * sizeof _v2147->e[0]); _v2147->n += _s2147.n; }));
(void)(({ L94 *_v2148 = &(eb_1597); hsl _s2148 = hr_str("b.e[i]", 6); if (_v2148->n + _s2148.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:488"); memmove(_v2148->e + _v2148->n, _s2148.p, (size_t)_s2148.n * sizeof _v2148->e[0]); _v2148->n += _s2148.n; }));
 } else { (void)(f286_hh(hr_str("if (a.n != b.n) return false; for (int64_t i = 0; i < a.n; i++) if (!(", 70)));
(void)(({ L94 *_v2149 = &(ea_1596); hsl _s2149 = hr_str("((", 2); if (_v2149->n + _s2149.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:489"); memmove(_v2149->e + _v2149->n, _s2149.p, (size_t)_s2149.n * sizeof _v2149->e[0]); _v2149->n += _s2149.n; }));
(void)(({ L94 *_v2150 = &(ea_1596); hsl _s2150 = f249_cn(e_1595); if (_v2150->n + _s2150.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:489"); memmove(_v2150->e + _v2150->n, _s2150.p, (size_t)_s2150.n * sizeof _v2150->e[0]); _v2150->n += _s2150.n; }));
(void)(({ L94 *_v2151 = &(ea_1596); hsl _s2151 = hr_str("*)a.p)[i]", 9); if (_v2151->n + _s2151.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:489"); memmove(_v2151->e + _v2151->n, _s2151.p, (size_t)_s2151.n * sizeof _v2151->e[0]); _v2151->n += _s2151.n; }));
(void)(({ L94 *_v2152 = &(eb_1597); hsl _s2152 = hr_str("((", 2); if (_v2152->n + _s2152.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:489"); memmove(_v2152->e + _v2152->n, _s2152.p, (size_t)_s2152.n * sizeof _v2152->e[0]); _v2152->n += _s2152.n; }));
(void)(({ L94 *_v2153 = &(eb_1597); hsl _s2153 = f249_cn(e_1595); if (_v2153->n + _s2153.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:489"); memmove(_v2153->e + _v2153->n, _s2153.p, (size_t)_s2153.n * sizeof _v2153->e[0]); _v2153->n += _s2153.n; }));
(void)(({ L94 *_v2154 = &(eb_1597); hsl _s2154 = hr_str("*)b.p)[i]", 9); if (_v2154->n + _s2154.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:489"); memmove(_v2154->e + _v2154->n, _s2154.p, (size_t)_s2154.n * sizeof _v2154->e[0]); _v2154->n += _s2154.n; }));
 }
 }
(void)(f288_heq_val(e_1595, ({ hsl _t2155 = ({ L94 *_t2156 = &(ea_1596); (hsl){ (uint8_t*)_t2156->e, _t2156->n }; }); int64_t _l2155 = 0, _h2155 = _t2155.n; if (_l2155 < 0 || _h2155 < _l2155 || _h2155 > _t2155.n) hr_slerr(_l2155, _h2155, _t2155.n, "hc/gen.amni:490"); (hsl){ _t2155.p + _l2155 * (int64_t)sizeof(uint8_t), _h2155 - _l2155 }; }), ({ hsl _t2157 = ({ L94 *_t2158 = &(eb_1597); (hsl){ (uint8_t*)_t2158->e, _t2158->n }; }); int64_t _l2157 = 0, _h2157 = _t2157.n; if (_l2157 < 0 || _h2157 < _l2157 || _h2157 > _t2157.n) hr_slerr(_l2157, _h2157, _t2157.n, "hc/gen.amni:490"); (hsl){ _t2157.p + _l2157 * (int64_t)sizeof(uint8_t), _h2157 - _l2157 }; })));
(void)(f286_hh(hr_str(")) return false; return true; ", 30)));
 }
if (((k_1512) == (((int64_t)14LL)))) { (void)(f286_hh(hr_str("return true; ", 13)));
 }
(void)(f286_hh(hr_str("}\012", 2)));
}
static void f281_comp_pre(int64_t t_1514, bool fmt_1515) {
S1 x_1516 = (*({ hrv *_t2159 = &(g524); int64_t _i2159 = t_1514; (S1*)_t2159->b + hr_ix(_i2159, _t2159->n, "hc/gen.amni:384"); })); 
int64_t k_1517 = ((int64_t)((x_1516).k_)); 
if (((k_1517) == (((int64_t)5LL)))) { int64_t si_1518 = ((int64_t)((x_1516).a_)); 
{ int32_t _e2161 = ((*({ hrv *_t2162 = &(g527); int64_t _i2162 = si_1518; (S10*)_t2162->b + hr_ix(_i2162, _t2162->n, "hc/gen.amni:385"); }))).fnum_; for (int32_t i_1519 = 0; i_1519 < _e2161; i_1519++) { S11 f_1520 = (*({ hrv *_t2163 = &(g528); int64_t _i2163 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2164 = &(g527); int64_t _i2164 = si_1518; (S10*)_t2164->b + hr_ix(_i2164, _t2164->n, "hc/gen.amni:385"); }))).f0_)) + (int64_t)((int64_t)(i_1519)))); (S11*)_t2163->b + hr_ix(_i2163, _t2163->n, "hc/gen.amni:385"); })); 
if ((((f_1520).ty_) >= (((int32_t)0LL)))) { (void)(f282_comp_one(((int64_t)((f_1520).ty_)), fmt_1515));
 }
 } } _bk2160:; 
 }
if (((k_1517) == (((int64_t)7LL)))) { S9 v_1567 = (*({ hrv *_t2165 = &(g530); int64_t _i2165 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2166 = &(g529); int64_t _i2166 = (x_1516).a_; (S8*)_t2166->b + hr_ix(_i2166, _t2166->n, "hc/gen.amni:386"); }))).v0_)) + (int64_t)((int64_t)((x_1516).c_)))); (S9*)_t2165->b + hr_ix(_i2165, _t2165->n, "hc/gen.amni:386"); })); 
if ((((v_1567).si_) >= (((int32_t)0LL)))) { { int32_t _e2168 = ((*({ hrv *_t2169 = &(g527); int64_t _i2169 = (v_1567).si_; (S10*)_t2169->b + hr_ix(_i2169, _t2169->n, "hc/gen.amni:386"); }))).fnum_; for (int32_t i_1568 = 0; i_1568 < _e2168; i_1568++) { S11 f_1569 = (*({ hrv *_t2170 = &(g528); int64_t _i2170 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2171 = &(g527); int64_t _i2171 = (v_1567).si_; (S10*)_t2171->b + hr_ix(_i2171, _t2171->n, "hc/gen.amni:386"); }))).f0_)) + (int64_t)((int64_t)(i_1568)))); (S11*)_t2170->b + hr_ix(_i2170, _t2170->n, "hc/gen.amni:386"); })); 
if ((((f_1569).ty_) >= (((int32_t)0LL)))) { (void)(f282_comp_one(((int64_t)((f_1569).ty_)), fmt_1515));
 }
 } } _bk2167:; 
 }
 }
if (((k_1517) == (((int64_t)6LL)))) { int64_t ei_1570 = ((int64_t)((x_1516).a_)); 
{ int32_t _e2173 = ((*({ hrv *_t2174 = &(g529); int64_t _i2174 = ei_1570; (S8*)_t2174->b + hr_ix(_i2174, _t2174->n, "hc/gen.amni:387"); }))).vnum_; for (int32_t i_1571 = 0; i_1571 < _e2173; i_1571++) { S9 v_1572 = (*({ hrv *_t2175 = &(g530); int64_t _i2175 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2176 = &(g529); int64_t _i2176 = ei_1570; (S8*)_t2176->b + hr_ix(_i2176, _t2176->n, "hc/gen.amni:387"); }))).v0_)) + (int64_t)((int64_t)(i_1571)))); (S9*)_t2175->b + hr_ix(_i2175, _t2175->n, "hc/gen.amni:387"); })); 
if (((((v_1572).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t2177 = &(g527); int64_t _i2177 = (v_1572).si_; (S10*)_t2177->b + hr_ix(_i2177, _t2177->n, "hc/gen.amni:387"); }))).zero_)))) { if (fmt_1515) { { int32_t _e2179 = ((*({ hrv *_t2180 = &(g527); int64_t _i2180 = (v_1572).si_; (S10*)_t2180->b + hr_ix(_i2180, _t2180->n, "hc/gen.amni:387"); }))).fnum_; for (int32_t j_1573 = 0; j_1573 < _e2179; j_1573++) { S11 f_1574 = (*({ hrv *_t2181 = &(g528); int64_t _i2181 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2182 = &(g527); int64_t _i2182 = (v_1572).si_; (S10*)_t2182->b + hr_ix(_i2182, _t2182->n, "hc/gen.amni:387"); }))).f0_)) + (int64_t)((int64_t)(j_1573)))); (S11*)_t2181->b + hr_ix(_i2181, _t2181->n, "hc/gen.amni:387"); })); 
if ((((f_1574).ty_) >= (((int32_t)0LL)))) { (void)(f282_comp_one(((int64_t)((f_1574).ty_)), fmt_1515));
 }
 } } _bk2178:; 
 } else { (void)(f280_gen_heq(f123_t_variant(ei_1570, ((int64_t)(i_1571)))));
 }
 }
 } } _bk2172:; 
 }
if ((((k_1517) == (((int64_t)8LL))) || ((k_1517) == (((int64_t)9LL))))) { (void)(f282_comp_one(((int64_t)((x_1516).a_)), fmt_1515));
 }
if (((k_1517) == (((int64_t)14LL)))) { { int32_t _e2184 = (x_1516).n_; for (int32_t i_1575 = 0; i_1575 < _e2184; i_1575++) { (void)(f282_comp_one(((int64_t)((*({ hrv *_t2185 = &(g525); int64_t _i2185 = ((int64_t)((int64_t)((int64_t)((x_1516).l_)) + (int64_t)((int64_t)(i_1575)))); (int32_t*)_t2185->b + hr_ix(_i2185, _t2185->n, "hc/gen.amni:389"); })))), fmt_1515));
 } } _bk2183:; 
 }
}
static void f282_comp_one(int64_t t_1521, bool fmt_1522) {
int64_t u_1523 = ({ int64_t _r2186; if (((((*({ hrv *_t2187 = &(g524); int64_t _i2187 = t_1521; (S1*)_t2187->b + hr_ix(_i2187, _t2187->n, "hc/gen.amni:382"); }))).k_) == (((uint8_t)10LL)))) { _r2186 = ((int64_t)(((*({ hrv *_t2188 = &(g524); int64_t _i2188 = t_1521; (S1*)_t2188->b + hr_ix(_i2188, _t2188->n, "hc/gen.amni:382"); }))).a_));  } else { _r2186 = t_1521;  } _r2186; }); 
if ((((((*({ hrv *_t2189 = &(g524); int64_t _i2189 = t_1521; (S1*)_t2189->b + hr_ix(_i2189, _t2189->n, "hc/gen.amni:382"); }))).k_) == (((uint8_t)10LL))) && (!(fmt_1522)))) { return;
 }
if (f283_need_helper(u_1523)) { if (fmt_1522) { (void)(f284_gen_hf(u_1523));
 } else { (void)(f280_gen_heq(u_1523));
 }
 }
}
static bool f283_need_helper(int64_t t_1524) {
int64_t k_1525 = ((int64_t)(((*({ hrv *_t2190 = &(g524); int64_t _i2190 = t_1524; (S1*)_t2190->b + hr_ix(_i2190, _t2190->n, "hc/gen.amni:381"); }))).k_)); 
if (f163_is_byte_arr(t_1524)) { return false;
 }
if (((k_1525) == (((int64_t)10LL)))) { return f283_need_helper(((int64_t)(((*({ hrv *_t2191 = &(g524); int64_t _i2191 = t_1524; (S1*)_t2191->b + hr_ix(_i2191, _t2191->n, "hc/gen.amni:381"); }))).a_)));
 }
return (((((((k_1525) == (((int64_t)5LL))) || ((k_1525) == (((int64_t)6LL)))) || ((k_1525) == (((int64_t)7LL)))) || ((k_1525) == (((int64_t)8LL)))) || ((k_1525) == (((int64_t)9LL)))) || ((k_1525) == (((int64_t)14LL))));
}
static void f284_gen_hf(int64_t t_1526) {
(void)(f248_cn_grow());
if ((((*({ hrv *_t2192 = &(g174); int64_t _i2192 = t_1526; (uint8_t*)_t2192->b + hr_ix(_i2192, _t2192->n, "hc/gen.amni:404"); }))) != (((uint8_t)0LL)))) { return;
 }
(*({ hrv *_t2193 = &(g174); int64_t _i2193 = t_1526; (uint8_t*)_t2193->b + hr_ix(_i2193, _t2193->n, "hc/gen.amni:405"); })) = ((uint8_t)1LL);
S1 x_1527 = (*({ hrv *_t2194 = &(g524); int64_t _i2194 = t_1526; (S1*)_t2194->b + hr_ix(_i2194, _t2194->n, "hc/gen.amni:406"); })); 
int64_t k_1528 = ((int64_t)((x_1527).k_)); 
(void)(f247_cbody(t_1526));
bool sl_1529 = (((k_1528) == (((int64_t)9LL))) || ((((k_1528) == (((int64_t)8LL))) && (!(f267_is_fix(t_1526)))) && (!(f268_is_lim(t_1526))))); 
(void)(f285_hf_pre(t_1526));
L93 sig_1531 = ({ L93 _t2195; memset(&_t2195, 0, sizeof _t2195); _t2195.n = 0; _t2195; }); 
(void)(({ L93 *_l2196 = &(sig_1531); hrv _o2196 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2196, hr_str("static void hf", 14)); hr_fi(&_o2196, t_1526); hr_fs(&_o2196, hr_str("(hrv *o, ", 9)); if (_l2196->n + _o2196.n > 256) hr_die("format past a limited array's capacity", "hc/gen.amni:411"); memcpy(_l2196->e + _l2196->n, _o2196.b, (size_t)_o2196.n); _l2196->n += _o2196.n; }));
(void)(({ L93 *_v2197 = &(sig_1531); hsl _s2197 = ({ hsl _r2198; if (sl_1529) { _r2198 = hr_str("hsl", 3);  } else { _r2198 = f249_cn(t_1526);  } _r2198; }); if (_v2197->n + _s2197.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:412"); memmove(_v2197->e + _v2197->n, _s2197.p, (size_t)_s2197.n * sizeof _v2197->e[0]); _v2197->n += _s2197.n; }));
(void)(({ L93 *_v2199 = &(sig_1531); hsl _s2199 = hr_str(" v)", 3); if (_v2199->n + _s2199.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:413"); memmove(_v2199->e + _v2199->n, _s2199.p, (size_t)_s2199.n * sizeof _v2199->e[0]); _v2199->n += _s2199.n; }));
(void)(({ hrv *_v2200 = &(g166); hsl _s2200 = ({ hsl _t2201 = ({ L93 *_t2202 = &(sig_1531); (hsl){ (uint8_t*)_t2202->e, _t2202->n }; }); int64_t _l2201 = 0, _h2201 = _t2201.n; if (_l2201 < 0 || _h2201 < _l2201 || _h2201 > _t2201.n) hr_slerr(_l2201, _h2201, _t2201.n, "hc/gen.amni:414"); (hsl){ _t2201.p + _l2201 * (int64_t)sizeof(uint8_t), _h2201 - _l2201 }; }); hr_append(_v2200, _s2200.p, _s2200.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2203 = &(g166); hsl _s2203 = hr_str(";\012", 2); hr_append(_v2203, _s2203.p, _s2203.n, sizeof(uint8_t)); }));
int64_t s0_1532 = (g169).n; 
(void)(({ hrv *_v2204 = &(g169); hsl _s2204 = ({ hsl _t2205 = ({ L93 *_t2206 = &(sig_1531); (hsl){ (uint8_t*)_t2206->e, _t2206->n }; }); int64_t _l2205 = 0, _h2205 = _t2205.n; if (_l2205 < 0 || _h2205 < _l2205 || _h2205 > _t2205.n) hr_slerr(_l2205, _h2205, _t2205.n, "hc/gen.amni:416"); (hsl){ _t2205.p + _l2205 * (int64_t)sizeof(uint8_t), _h2205 - _l2205 }; }); hr_append(_v2204, _s2204.p, _s2204.n, sizeof(uint8_t)); }));
(void)(f286_hh(hr_str(" { ", 3)));
if (((k_1528) == (((int64_t)5LL)))) { int64_t si_1534 = ((int64_t)((x_1527).a_)); 
int64_t f0_1535 = ((int64_t)(((*({ hrv *_t2207 = &(g527); int64_t _i2207 = si_1534; (S10*)_t2207->b + hr_ix(_i2207, _t2207->n, "hc/gen.amni:418"); }))).f0_)); 
(void)(f286_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f286_hh(f10_nm(((int64_t)(((*({ hrv *_t2208 = &(g527); int64_t _i2208 = si_1534; (S10*)_t2208->b + hr_ix(_i2208, _t2208->n, "hc/gen.amni:419"); }))).name_)))));
(void)(f286_hh(hr_str(" { \"); ", 7)));
bool first_1536 = true; 
{ int32_t _e2210 = ((*({ hrv *_t2211 = &(g527); int64_t _i2211 = si_1534; (S10*)_t2211->b + hr_ix(_i2211, _t2211->n, "hc/gen.amni:421"); }))).fnum_; for (int32_t i_1537 = 0; i_1537 < _e2210; i_1537++) { S11 f_1538 = (*({ hrv *_t2212 = &(g528); int64_t _i2212 = ((int64_t)((int64_t)f0_1535 + (int64_t)((int64_t)(i_1537)))); (S11*)_t2212->b + hr_ix(_i2212, _t2212->n, "hc/gen.amni:421"); })); 
if ((((f_1538).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1536))) { (void)(f286_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1536 = false;
L94 e_1539 = ({ L94 _t2213; memset(&_t2213, 0, sizeof _t2213); _t2213.n = 0; _t2213; }); 
(void)(({ L94 *_v2214 = &(e_1539); hsl _s2214 = hr_str("v.", 2); if (_v2214->n + _s2214.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:421"); memmove(_v2214->e + _v2214->n, _s2214.p, (size_t)_s2214.n * sizeof _v2214->e[0]); _v2214->n += _s2214.n; }));
{ hsl _v2216 = f10_nm(((int64_t)((f_1538).name_))); for (int64_t _k2216 = 0; _k2216 < _v2216.n; _k2216++) { uint8_t c_1540 = ((uint8_t*)_v2216.p)[_k2216]; (void)(({ L94 *_v2217 = &(e_1539); uint8_t _x2217 = c_1540; if (_v2217->n >= 128) hr_die("push past a limited array's capacity", "hc/gen.amni:421"); _v2217->e[_v2217->n] = _x2217; &_v2217->e[_v2217->n++]; }));
 } } _bk2215:; 
(void)(({ L94 *_v2218 = &(e_1539); uint8_t _x2218 = ((uint8_t)95LL); if (_v2218->n >= 128) hr_die("push past a limited array's capacity", "hc/gen.amni:421"); _v2218->e[_v2218->n] = _x2218; &_v2218->e[_v2218->n++]; }));
(void)(f287_hf_val(((int64_t)((f_1538).ty_)), ({ hsl _t2219 = ({ L94 *_t2220 = &(e_1539); (hsl){ (uint8_t*)_t2220->e, _t2220->n }; }); int64_t _l2219 = 0, _h2219 = _t2219.n; if (_l2219 < 0 || _h2219 < _l2219 || _h2219 > _t2219.n) hr_slerr(_l2219, _h2219, _t2219.n, "hc/gen.amni:421"); (hsl){ _t2219.p + _l2219 * (int64_t)sizeof(uint8_t), _h2219 - _l2219 }; })));
 } } _bk2209:; 
(void)(f286_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 }
if (((k_1528) == (((int64_t)6LL)))) { int64_t ei_1545 = ((int64_t)((x_1527).a_)); 
int64_t v0_1546 = ((int64_t)(((*({ hrv *_t2221 = &(g529); int64_t _i2221 = ei_1545; (S8*)_t2221->b + hr_ix(_i2221, _t2221->n, "hc/gen.amni:425"); }))).v0_)); 
{ int32_t _e2223 = ((*({ hrv *_t2224 = &(g529); int64_t _i2224 = ei_1545; (S8*)_t2224->b + hr_ix(_i2224, _t2224->n, "hc/gen.amni:426"); }))).vnum_; for (int32_t i_1547 = 0; i_1547 < _e2223; i_1547++) { S9 v_1548 = (*({ hrv *_t2225 = &(g530); int64_t _i2225 = ((int64_t)((int64_t)v0_1546 + (int64_t)((int64_t)(i_1547)))); (S9*)_t2225->b + hr_ix(_i2225, _t2225->n, "hc/gen.amni:427"); })); 
(void)(({ hrv *_o2226 = &(g169); hr_fs(_o2226, hr_str("if (v.tag == ", 13)); hr_fi(_o2226, i_1547); hr_fs(_o2226, hr_str(") { ", 4)); }));
if (((((v_1548).si_) >= (((int32_t)0LL))) && ((((*({ hrv *_t2227 = &(g527); int64_t _i2227 = (v_1548).si_; (S10*)_t2227->b + hr_ix(_i2227, _t2227->n, "hc/gen.amni:429"); }))).fnum_) > (((int32_t)0LL))))) { (void)(f286_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f286_hh(f10_nm(((int64_t)((v_1548).name_)))));
(void)(f286_hh(hr_str(" { \"); ", 7)));
bool first_1549 = true; 
int64_t sf0_1550 = ((int64_t)(((*({ hrv *_t2228 = &(g527); int64_t _i2228 = (v_1548).si_; (S10*)_t2228->b + hr_ix(_i2228, _t2228->n, "hc/gen.amni:429"); }))).f0_)); 
{ int32_t _e2230 = ((*({ hrv *_t2231 = &(g527); int64_t _i2231 = (v_1548).si_; (S10*)_t2231->b + hr_ix(_i2231, _t2231->n, "hc/gen.amni:429"); }))).fnum_; for (int32_t j_1551 = 0; j_1551 < _e2230; j_1551++) { S11 f_1552 = (*({ hrv *_t2232 = &(g528); int64_t _i2232 = ((int64_t)((int64_t)sf0_1550 + (int64_t)((int64_t)(j_1551)))); (S11*)_t2232->b + hr_ix(_i2232, _t2232->n, "hc/gen.amni:429"); })); 
if ((((f_1552).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1549))) { (void)(f286_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1549 = false;
L94 e_1553 = ({ L94 _t2233; memset(&_t2233, 0, sizeof _t2233); _t2233.n = 0; _t2233; }); 
(void)(({ L94 *_l2234 = &(e_1553); hrv _o2234 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2234, hr_str("v.u.v", 5)); hr_fi(&_o2234, i_1547); hr_fs(&_o2234, hr_str(".", 1)); if (_l2234->n + _o2234.n > 128) hr_die("format past a limited array's capacity", "hc/gen.amni:429"); memcpy(_l2234->e + _l2234->n, _o2234.b, (size_t)_o2234.n); _l2234->n += _o2234.n; }));
{ hsl _v2236 = f10_nm(((int64_t)((f_1552).name_))); for (int64_t _k2236 = 0; _k2236 < _v2236.n; _k2236++) { uint8_t c_1554 = ((uint8_t*)_v2236.p)[_k2236]; (void)(({ L94 *_v2237 = &(e_1553); uint8_t _x2237 = c_1554; if (_v2237->n >= 128) hr_die("push past a limited array's capacity", "hc/gen.amni:429"); _v2237->e[_v2237->n] = _x2237; &_v2237->e[_v2237->n++]; }));
 } } _bk2235:; 
(void)(({ L94 *_v2238 = &(e_1553); uint8_t _x2238 = ((uint8_t)95LL); if (_v2238->n >= 128) hr_die("push past a limited array's capacity", "hc/gen.amni:429"); _v2238->e[_v2238->n] = _x2238; &_v2238->e[_v2238->n++]; }));
(void)(f287_hf_val(((int64_t)((f_1552).ty_)), ({ hsl _t2239 = ({ L94 *_t2240 = &(e_1553); (hsl){ (uint8_t*)_t2240->e, _t2240->n }; }); int64_t _l2239 = 0, _h2239 = _t2239.n; if (_l2239 < 0 || _h2239 < _l2239 || _h2239 > _t2239.n) hr_slerr(_l2239, _h2239, _t2239.n, "hc/gen.amni:429"); (hsl){ _t2239.p + _l2239 * (int64_t)sizeof(uint8_t), _h2239 - _l2239 }; })));
 } } _bk2229:; 
(void)(f286_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 } else { (void)(f286_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f286_hh(f10_nm(((int64_t)(((*({ hrv *_t2241 = &(g529); int64_t _i2241 = ei_1545; (S8*)_t2241->b + hr_ix(_i2241, _t2241->n, "hc/gen.amni:430"); }))).name_)))));
(void)(f286_hh(hr_str(".", 1)));
(void)(f286_hh(f10_nm(((int64_t)((v_1548).name_)))));
(void)(f286_hh(hr_str("\"); ", 4)));
 }
(void)(f286_hh(hr_str("} ", 2)));
 } } _bk2222:; 
 }
if (((k_1528) == (((int64_t)7LL)))) { int64_t ei_1555 = ((int64_t)((x_1527).a_)); 
S9 v_1556 = (*({ hrv *_t2242 = &(g530); int64_t _i2242 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2243 = &(g529); int64_t _i2243 = ei_1555; (S8*)_t2243->b + hr_ix(_i2243, _t2243->n, "hc/gen.amni:435"); }))).v0_)) + (int64_t)((int64_t)((x_1527).c_)))); (S9*)_t2242->b + hr_ix(_i2242, _t2242->n, "hc/gen.amni:435"); })); 
if (((((v_1556).si_) >= (((int32_t)0LL))) && ((((*({ hrv *_t2244 = &(g527); int64_t _i2244 = (v_1556).si_; (S10*)_t2244->b + hr_ix(_i2244, _t2244->n, "hc/gen.amni:436"); }))).fnum_) > (((int32_t)0LL))))) { (void)(f286_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f286_hh(f10_nm(((int64_t)((v_1556).name_)))));
(void)(f286_hh(hr_str(" { \"); ", 7)));
bool first_1557 = true; 
int64_t sf0_1558 = ((int64_t)(((*({ hrv *_t2245 = &(g527); int64_t _i2245 = (v_1556).si_; (S10*)_t2245->b + hr_ix(_i2245, _t2245->n, "hc/gen.amni:436"); }))).f0_)); 
{ int32_t _e2247 = ((*({ hrv *_t2248 = &(g527); int64_t _i2248 = (v_1556).si_; (S10*)_t2248->b + hr_ix(_i2248, _t2248->n, "hc/gen.amni:436"); }))).fnum_; for (int32_t j_1559 = 0; j_1559 < _e2247; j_1559++) { S11 f_1560 = (*({ hrv *_t2249 = &(g528); int64_t _i2249 = ((int64_t)((int64_t)sf0_1558 + (int64_t)((int64_t)(j_1559)))); (S11*)_t2249->b + hr_ix(_i2249, _t2249->n, "hc/gen.amni:436"); })); 
if ((((f_1560).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1557))) { (void)(f286_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1557 = false;
L94 e_1561 = ({ L94 _t2250; memset(&_t2250, 0, sizeof _t2250); _t2250.n = 0; _t2250; }); 
(void)(({ L94 *_v2251 = &(e_1561); hsl _s2251 = hr_str("v.", 2); if (_v2251->n + _s2251.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:436"); memmove(_v2251->e + _v2251->n, _s2251.p, (size_t)_s2251.n * sizeof _v2251->e[0]); _v2251->n += _s2251.n; }));
{ hsl _v2253 = f10_nm(((int64_t)((f_1560).name_))); for (int64_t _k2253 = 0; _k2253 < _v2253.n; _k2253++) { uint8_t c_1562 = ((uint8_t*)_v2253.p)[_k2253]; (void)(({ L94 *_v2254 = &(e_1561); uint8_t _x2254 = c_1562; if (_v2254->n >= 128) hr_die("push past a limited array's capacity", "hc/gen.amni:436"); _v2254->e[_v2254->n] = _x2254; &_v2254->e[_v2254->n++]; }));
 } } _bk2252:; 
(void)(({ L94 *_v2255 = &(e_1561); uint8_t _x2255 = ((uint8_t)95LL); if (_v2255->n >= 128) hr_die("push past a limited array's capacity", "hc/gen.amni:436"); _v2255->e[_v2255->n] = _x2255; &_v2255->e[_v2255->n++]; }));
(void)(f287_hf_val(((int64_t)((f_1560).ty_)), ({ hsl _t2256 = ({ L94 *_t2257 = &(e_1561); (hsl){ (uint8_t*)_t2257->e, _t2257->n }; }); int64_t _l2256 = 0, _h2256 = _t2256.n; if (_l2256 < 0 || _h2256 < _l2256 || _h2256 > _t2256.n) hr_slerr(_l2256, _h2256, _t2256.n, "hc/gen.amni:436"); (hsl){ _t2256.p + _l2256 * (int64_t)sizeof(uint8_t), _h2256 - _l2256 }; })));
 } } _bk2246:; 
(void)(f286_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 } else { (void)(f286_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f286_hh(f10_nm(((int64_t)(((*({ hrv *_t2258 = &(g529); int64_t _i2258 = ei_1555; (S8*)_t2258->b + hr_ix(_i2258, _t2258->n, "hc/gen.amni:437"); }))).name_)))));
(void)(f286_hh(hr_str(".", 1)));
(void)(f286_hh(f10_nm(((int64_t)((v_1556).name_)))));
(void)(f286_hh(hr_str("\"); ", 4)));
 }
 }
if ((((k_1528) == (((int64_t)8LL))) || ((k_1528) == (((int64_t)9LL))))) { int64_t e_1563 = ((int64_t)((x_1527).a_)); 
(void)(f247_cbody(e_1563));
(void)(f286_hh(hr_str("hr_fb(o, '['); ", 15)));
if (f267_is_fix(t_1526)) { (void)(({ hrv *_o2259 = &(g169); hr_fs(_o2259, hr_str("for (int64_t i = 0; i < ", 24)); hr_fi(_o2259, (x_1527).b_); hr_fs(_o2259, hr_str("; i++) { if (i) hr_fc(o, \", \"); ", 32)); }));
(void)(f287_hf_val(e_1563, hr_str("v.e[i]", 6)));
(void)(f286_hh(hr_str("} ", 2)));
 } else { if (f268_is_lim(t_1526)) { (void)(f286_hh(hr_str("for (int64_t i = 0; i < v.n; i++) { if (i) hr_fc(o, \", \"); ", 59)));
(void)(f287_hf_val(e_1563, hr_str("v.e[i]", 6)));
(void)(f286_hh(hr_str("} ", 2)));
 } else { (void)(f286_hh(hr_str("for (int64_t i = 0; i < v.n; i++) { if (i) hr_fc(o, \", \"); ", 59)));
L94 ex_1564 = ({ L94 _t2260; memset(&_t2260, 0, sizeof _t2260); _t2260.n = 0; _t2260; }); 
(void)(({ L94 *_v2261 = &(ex_1564); hsl _s2261 = hr_str("((", 2); if (_v2261->n + _s2261.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:445"); memmove(_v2261->e + _v2261->n, _s2261.p, (size_t)_s2261.n * sizeof _v2261->e[0]); _v2261->n += _s2261.n; }));
(void)(({ L94 *_v2262 = &(ex_1564); hsl _s2262 = f249_cn(e_1563); if (_v2262->n + _s2262.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:445"); memmove(_v2262->e + _v2262->n, _s2262.p, (size_t)_s2262.n * sizeof _v2262->e[0]); _v2262->n += _s2262.n; }));
(void)(({ L94 *_v2263 = &(ex_1564); hsl _s2263 = hr_str("*)v.p)[i]", 9); if (_v2263->n + _s2263.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:445"); memmove(_v2263->e + _v2263->n, _s2263.p, (size_t)_s2263.n * sizeof _v2263->e[0]); _v2263->n += _s2263.n; }));
(void)(f287_hf_val(e_1563, ({ hsl _t2264 = ({ L94 *_t2265 = &(ex_1564); (hsl){ (uint8_t*)_t2265->e, _t2265->n }; }); int64_t _l2264 = 0, _h2264 = _t2264.n; if (_l2264 < 0 || _h2264 < _l2264 || _h2264 > _t2264.n) hr_slerr(_l2264, _h2264, _t2264.n, "hc/gen.amni:445"); (hsl){ _t2264.p + _l2264 * (int64_t)sizeof(uint8_t), _h2264 - _l2264 }; })));
(void)(f286_hh(hr_str("} ", 2)));
 }
 }
(void)(f286_hh(hr_str("hr_fb(o, ']'); ", 15)));
 }
if (((k_1528) == (((int64_t)14LL)))) { { int32_t _e2267 = (x_1527).n_; for (int32_t i_1565 = 0; i_1565 < _e2267; i_1565++) { if (((i_1565) > (((int32_t)0LL)))) { (void)(f286_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
L95 e_1566 = ({ L95 _t2268; memset(&_t2268, 0, sizeof _t2268); _t2268.n = 0; _t2268; }); 
(void)(({ L95 *_l2269 = &(e_1566); hrv _o2269 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2269, hr_str("v.r", 3)); hr_fi(&_o2269, i_1565); if (_l2269->n + _o2269.n > 32) hr_die("format past a limited array's capacity", "hc/gen.amni:448"); memcpy(_l2269->e + _l2269->n, _o2269.b, (size_t)_o2269.n); _l2269->n += _o2269.n; }));
(void)(f287_hf_val(((int64_t)((*({ hrv *_t2270 = &(g525); int64_t _i2270 = ((int64_t)((int64_t)((int64_t)((x_1527).l_)) + (int64_t)((int64_t)(i_1565)))); (int32_t*)_t2270->b + hr_ix(_i2270, _t2270->n, "hc/gen.amni:448"); })))), ({ hsl _t2271 = ({ L95 *_t2272 = &(e_1566); (hsl){ (uint8_t*)_t2272->e, _t2272->n }; }); int64_t _l2271 = 0, _h2271 = _t2271.n; if (_l2271 < 0 || _h2271 < _l2271 || _h2271 > _t2271.n) hr_slerr(_l2271, _h2271, _t2271.n, "hc/gen.amni:448"); (hsl){ _t2271.p + _l2271 * (int64_t)sizeof(uint8_t), _h2271 - _l2271 }; })));
 } } _bk2266:; 
 }
(void)(f286_hh(hr_str("}\012", 2)));
}
static void f285_hf_pre(int64_t t_1530) {
(void)(f281_comp_pre(t_1530, true));
}
static void f286_hh(hsl s_1533) {
(void)(({ hrv *_v2273 = &(g169); hsl _s2273 = s_1533; hr_append(_v2273, _s2273.p, _s2273.n, sizeof(uint8_t)); }));
}
static void f287_hf_val(int64_t t_1541, hsl e_1542) {
int64_t k_1543 = ((int64_t)(((*({ hrv *_t2274 = &(g524); int64_t _i2274 = t_1541; (S1*)_t2274->b + hr_ix(_i2274, _t2274->n, "hc/gen.amni:393"); }))).k_)); 
if (f163_is_byte_arr(t_1541)) { if (f267_is_fix(t_1541)) { (void)(({ hrv *_o2275 = &(g169); hr_fs(_o2275, hr_str("hr_fq(o, (hsl){ (uint8_t*)(", 27)); hr_fs(_o2275, e_1542); hr_fs(_o2275, hr_str(").e, ", 5)); hr_fi(_o2275, ((*({ hrv *_t2276 = &(g524); int64_t _i2276 = t_1541; (S1*)_t2276->b + hr_ix(_i2276, _t2276->n, "hc/gen.amni:394"); }))).b_); hr_fs(_o2275, hr_str(" }); ", 5)); }));
return;
 }
if (f268_is_lim(t_1541)) { (void)(({ hrv *_o2277 = &(g169); hr_fs(_o2277, hr_str("hr_fq(o, (hsl){ (uint8_t*)(", 27)); hr_fs(_o2277, e_1542); hr_fs(_o2277, hr_str(").e, (", 6)); hr_fs(_o2277, e_1542); hr_fs(_o2277, hr_str(").n }); ", 8)); }));
return;
 }
if (((((*({ hrv *_t2278 = &(g524); int64_t _i2278 = t_1541; (S1*)_t2278->b + hr_ix(_i2278, _t2278->n, "hc/gen.amni:394"); }))).k_) == (((uint8_t)9LL)))) { (void)(({ hrv *_o2279 = &(g169); hr_fs(_o2279, hr_str("hr_fq(o, ", 9)); hr_fs(_o2279, e_1542); hr_fs(_o2279, hr_str("); ", 3)); }));
return;
 }
(void)(({ hrv *_o2280 = &(g169); hr_fs(_o2280, hr_str("hr_fq(o, hr_sl(", 15)); hr_fs(_o2280, e_1542); hr_fs(_o2280, hr_str(")); ", 4)); }));
return;
 }
if (((k_1543) == (((int64_t)3LL)))) { (void)(({ hrv *_o2281 = &(g169); hr_fs(_o2281, ({ hsl _r2282; if (f151_is_signed(t_1541)) { _r2282 = hr_str("hr_fi(o, ", 9);  } else { _r2282 = hr_str("hr_fu(o, ", 9);  } _r2282; })); hr_fs(_o2281, e_1542); hr_fs(_o2281, hr_str("); ", 3)); }));
return;
 }
if (((k_1543) == (((int64_t)4LL)))) { (void)(({ hrv *_o2283 = &(g169); hr_fs(_o2283, ({ hsl _r2284; if (((((*({ hrv *_t2285 = &(g524); int64_t _i2285 = t_1541; (S1*)_t2285->b + hr_ix(_i2285, _t2285->n, "hc/gen.amni:396"); }))).s_) == (((uint8_t)4LL)))) { _r2284 = hr_str("hr_ff(o, ", 9);  } else { _r2284 = hr_str("hr_fd(o, ", 9);  } _r2284; })); hr_fs(_o2283, e_1542); hr_fs(_o2283, hr_str("); ", 3)); }));
return;
 }
if (((k_1543) == (((int64_t)2LL)))) { (void)(({ hrv *_o2286 = &(g169); hr_fs(_o2286, hr_str("hr_fc(o, (", 10)); hr_fs(_o2286, e_1542); hr_fs(_o2286, hr_str(") \077 \"true\" : \"false\"); ", 23)); }));
return;
 }
if (((k_1543) == (((int64_t)10LL)))) { if (((((*({ hrv *_t2287 = &(g524); int64_t _i2287 = t_1541; (S1*)_t2287->b + hr_ix(_i2287, _t2287->n, "hc/gen.amni:398"); }))).c_) >= (((int32_t)0LL)))) { (void)(({ hrv *_o2288 = &(g169); hr_fs(_o2288, hr_str("hr_fu(o, ", 9)); hr_fs(_o2288, e_1542); hr_fs(_o2288, hr_str("); ", 3)); }));
return;
 }
L93 pe_1544 = ({ L93 _t2289; memset(&_t2289, 0, sizeof _t2289); _t2289.n = 0; _t2289; }); 
(void)(({ L93 *_l2290 = &(pe_1544); hrv _o2290 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2290, hr_str("(*(", 3)); hr_fs(&_o2290, e_1542); hr_fs(&_o2290, hr_str("))", 2)); if (_l2290->n + _o2290.n > 256) hr_die("format past a limited array's capacity", "hc/gen.amni:398"); memcpy(_l2290->e + _l2290->n, _o2290.b, (size_t)_o2290.n); _l2290->n += _o2290.n; }));
(void)(({ hrv *_o2291 = &(g169); hr_fs(_o2291, hr_str("if (", 4)); hr_fs(_o2291, e_1542); hr_fs(_o2291, hr_str(") { ", 4)); }));
(void)(f287_hf_val(((int64_t)(((*({ hrv *_t2292 = &(g524); int64_t _i2292 = t_1541; (S1*)_t2292->b + hr_ix(_i2292, _t2292->n, "hc/gen.amni:398"); }))).a_)), ({ hsl _t2293 = ({ L93 *_t2294 = &(pe_1544); (hsl){ (uint8_t*)_t2294->e, _t2294->n }; }); int64_t _l2293 = 0, _h2293 = _t2293.n; if (_l2293 < 0 || _h2293 < _l2293 || _h2293 > _t2293.n) hr_slerr(_l2293, _h2293, _t2293.n, "hc/gen.amni:398"); (hsl){ _t2293.p + _l2293 * (int64_t)sizeof(uint8_t), _h2293 - _l2293 }; })));
(void)(f286_hh(hr_str("} else hr_fc(o, \"null\"); ", 25)));
return;
 }
if (((((k_1543) == (((int64_t)8LL))) && (!(f267_is_fix(t_1541)))) && (!(f268_is_lim(t_1541))))) { (void)(({ hrv *_o2295 = &(g169); hr_fs(_o2295, hr_str("hf", 2)); hr_fi(_o2295, t_1541); hr_fs(_o2295, hr_str("(o, hr_sl(", 10)); hr_fs(_o2295, e_1542); hr_fs(_o2295, hr_str(")); ", 4)); }));
return;
 }
(void)(({ hrv *_o2296 = &(g169); hr_fs(_o2296, hr_str("hf", 2)); hr_fi(_o2296, t_1541); hr_fs(_o2296, hr_str("(o, ", 4)); hr_fs(_o2296, e_1542); hr_fs(_o2296, hr_str("); ", 3)); }));
}
static void f288_heq_val(int64_t t_1585, hsl a_1586, hsl b_1587) {
int64_t k_1588 = ((int64_t)(((*({ hrv *_t2297 = &(g524); int64_t _i2297 = t_1585; (S1*)_t2297->b + hr_ix(_i2297, _t2297->n, "hc/gen.amni:452"); }))).k_)); 
if ((((((k_1588) == (((int64_t)3LL))) || ((k_1588) == (((int64_t)4LL)))) || ((k_1588) == (((int64_t)2LL)))) || ((k_1588) == (((int64_t)10LL))))) { (void)(({ hrv *_o2298 = &(g169); hr_fs(_o2298, hr_str("(", 1)); hr_fs(_o2298, a_1586); hr_fs(_o2298, hr_str(") == (", 6)); hr_fs(_o2298, b_1587); hr_fs(_o2298, hr_str(")", 1)); }));
return;
 }
(void)(f280_gen_heq(t_1585));
if ((((k_1588) == (((int64_t)9LL))) || ((((k_1588) == (((int64_t)8LL))) && (!(f267_is_fix(t_1585)))) && (!(f268_is_lim(t_1585)))))) { (void)(({ hrv *_o2299 = &(g169); hr_fs(_o2299, hr_str("heq", 3)); hr_fi(_o2299, t_1585); hr_fs(_o2299, hr_str("(hr_sl(", 7)); hr_fs(_o2299, a_1586); hr_fs(_o2299, hr_str("), hr_sl(", 9)); hr_fs(_o2299, b_1587); hr_fs(_o2299, hr_str("))", 2)); }));
return;
 }
(void)(({ hrv *_o2300 = &(g169); hr_fs(_o2300, hr_str("heq", 3)); hr_fi(_o2300, t_1585); hr_fs(_o2300, hr_str("(", 1)); hr_fs(_o2300, a_1586); hr_fs(_o2300, hr_str(", ", 2)); hr_fs(_o2300, b_1587); hr_fs(_o2300, hr_str(")", 1)); }));
}
static bool f289_hsl_ty(int64_t t_1598) {
return (((((*({ hrv *_t2301 = &(g524); int64_t _i2301 = t_1598; (S1*)_t2301->b + hr_ix(_i2301, _t2301->n, "hc/gen.amni:746"); }))).k_) == (((uint8_t)9LL))) || ((((((*({ hrv *_t2302 = &(g524); int64_t _i2302 = t_1598; (S1*)_t2302->b + hr_ix(_i2302, _t2302->n, "hc/gen.amni:746"); }))).k_) == (((uint8_t)8LL))) && (!(f267_is_fix(t_1598)))) && (!(f268_is_lim(t_1598)))));
}
static void f290_gxas(int64_t n_1599, int64_t t_1600) {
int64_t f_1601 = f264_fin(n_1599); 
if (((f_1601) == (t_1600))) { (void)(f274_gx(n_1599));
return;
 }
(void)(f255_gcv(n_1599, f140_at(n_1599), t_1600));
}
static void f291_garith(int64_t o_1603, int64_t t0_1604, int64_t a_1605, int64_t b_1606, int64_t tv_1607, int64_t loc_1608) {
int64_t t_1609 = ({ int64_t _r2303; if (((((*({ hrv *_t2304 = &(g524); int64_t _i2304 = t0_1604; (S1*)_t2304->b + hr_ix(_i2304, _t2304->n, "hc/gen.amni:236"); }))).k_) == (((uint8_t)12LL)))) { _r2303 = g536;  } else { _r2303 = ({ int64_t _r2305; if (((((*({ hrv *_t2306 = &(g524); int64_t _i2306 = t0_1604; (S1*)_t2306->b + hr_ix(_i2306, _t2306->n, "hc/gen.amni:236"); }))).k_) == (((uint8_t)13LL)))) { _r2305 = g542;  } else { _r2305 = t0_1604;  } _r2305; });  } _r2303; }); 
int64_t k_1610 = ((int64_t)(((*({ hrv *_t2307 = &(g524); int64_t _i2307 = t_1609; (S1*)_t2307->b + hr_ix(_i2307, _t2307->n, "hc/gen.amni:237"); }))).k_)); 
int64_t lk_1611 = f175_leaf_kind(t_1609); 
if (((lk_1611) >= (((int64_t)4LL)))) { int64_t ta_1612 = ({ int64_t _r2308; if (((a_1605) >= (((int64_t)0LL)))) { _r2308 = f264_fin(a_1605);  } else { _r2308 = t_1609;  } _r2308; }); 
int64_t tb_1613 = ({ int64_t _r2309; if (((b_1606) >= (((int64_t)0LL)))) { _r2309 = f264_fin(b_1606);  } else { _r2309 = t_1609;  } _r2309; }); 
if (((ta_1612) != (t_1609))) { if (((o_1603) != (((int64_t)23LL)))) { (void)(f272_gerr(loc_1608, hr_str("only * takes a scalar on the left of a struct or array", 54)));
return;
 }
(void)(f245_ow(hr_str("hop", 3)));
(void)(f279_oi(t_1609));
(void)(f245_ow(hr_str("_", 1)));
(void)(f279_oi(o_1603));
(void)(f245_ow(hr_str("(", 1)));
(void)(f292_gopnd(b_1606, tv_1607));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f292_gopnd(a_1605, tv_1607));
(void)(f245_ow(hr_str(")", 1)));
(void)(f293_gen_hop(t_1609, o_1603, ta_1612));
return;
 }
(void)(f245_ow(hr_str("hop", 3)));
(void)(f279_oi(t_1609));
(void)(f245_ow(hr_str("_", 1)));
(void)(f279_oi(o_1603));
(void)(f245_ow(hr_str("(", 1)));
(void)(f292_gopnd(a_1605, tv_1607));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f292_gopnd(b_1606, tv_1607));
(void)(f245_ow(hr_str(")", 1)));
(void)(f293_gen_hop(t_1609, o_1603, tb_1613));
return;
 }
if (((k_1610) == (((int64_t)4LL)))) { if (((o_1603) == (((int64_t)25LL)))) { (void)(f245_ow(({ hsl _r2310; if (((((*({ hrv *_t2311 = &(g524); int64_t _i2311 = t_1609; (S1*)_t2311->b + hr_ix(_i2311, _t2311->n, "hc/gen.amni:244"); }))).s_) == (((uint8_t)4LL)))) { _r2310 = hr_str("fmodf(", 6);  } else { _r2310 = hr_str("fmod(", 5);  } _r2310; })));
(void)(f292_gopnd(a_1605, tv_1607));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f292_gopnd(b_1606, tv_1607));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
(void)(f245_ow(hr_str("((", 2)));
(void)(f246_ct(t_1609));
(void)(f245_ow(hr_str(")(", 2)));
(void)(f292_gopnd(a_1605, tv_1607));
(void)(f245_ow(hr_str(" ", 1)));
(void)(f245_ow(f295_ar_op(o_1603)));
(void)(f245_ow(hr_str(" ", 1)));
(void)(f292_gopnd(b_1606, tv_1607));
(void)(f245_ow(hr_str("))", 2)));
return;
 }
if (((k_1610) == (((int64_t)2LL)))) { (void)(f245_ow(hr_str("((", 2)));
(void)(f292_gopnd(a_1605, tv_1607));
(void)(f245_ow(hr_str(") ", 2)));
(void)(f245_ow(f295_ar_op(o_1603)));
(void)(f245_ow(hr_str(" (", 2)));
(void)(f292_gopnd(b_1606, tv_1607));
(void)(f245_ow(hr_str("))", 2)));
return;
 }
bool sg_1644 = (((k_1610) == (((int64_t)3LL))) && f151_is_signed(t_1609)); 
if ((((o_1603) == (((int64_t)24LL))) || ((o_1603) == (((int64_t)25LL))))) { (void)(f245_ow(({ hsl _r2312; if (((o_1603) == (((int64_t)24LL)))) { _r2312 = ({ hsl _r2313; if (sg_1644) { _r2313 = hr_str("HR_SDIV(", 8);  } else { _r2313 = hr_str("HR_UDIV(", 8);  } _r2313; });  } else { _r2312 = ({ hsl _r2314; if (sg_1644) { _r2314 = hr_str("HR_SMOD(", 8);  } else { _r2314 = hr_str("HR_UDIV_MOD(", 12);  } _r2314; });  } _r2312; })));
(void)(f246_ct(t_1609));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f292_gopnd(a_1605, tv_1607));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f292_gopnd(b_1606, tv_1607));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f296_wloc(loc_1608));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if ((((o_1603) == (((int64_t)43LL))) || ((o_1603) == (((int64_t)44LL))))) { (void)(f245_ow(hr_str("((", 2)));
(void)(f246_ct(t_1609));
(void)(f245_ow(hr_str(")((", 3)));
(void)(f292_gopnd(a_1605, tv_1607));
(void)(f245_ow(hr_str(") ", 2)));
(void)(f245_ow(f295_ar_op(o_1603)));
(void)(f245_ow(hr_str(" ((", 3)));
(void)(f292_gopnd(b_1606, tv_1607));
(void)(({ hrv *_o2315 = &(g163); hr_fs(_o2315, hr_str(") & ", 4)); hr_fi(_o2315, ((int64_t)((int64_t)f152_ibits(t_1609) - (int64_t)((int64_t)1LL)))); hr_fs(_o2315, hr_str(")))", 3)); }));
return;
 }
(void)(f245_ow(hr_str("((", 2)));
(void)(f246_ct(t_1609));
(void)(f245_ow(hr_str(")(", 2)));
if (sg_1644) { (void)(f245_ow(hr_str("(int64_t)", 9)));
 } else { (void)(f245_ow(hr_str("(uint64_t)", 10)));
 }
(void)(f292_gopnd(a_1605, tv_1607));
(void)(f245_ow(hr_str(" ", 1)));
(void)(f245_ow(f295_ar_op(o_1603)));
(void)(f245_ow(hr_str(" ", 1)));
if (sg_1644) { (void)(f245_ow(hr_str("(int64_t)", 9)));
 } else { (void)(f245_ow(hr_str("(uint64_t)", 10)));
 }
(void)(f292_gopnd(b_1606, tv_1607));
(void)(f245_ow(hr_str("))", 2)));
}
static void f292_gopnd(int64_t n_1614, int64_t tv_1615) {
if (((n_1614) >= (((int64_t)0LL)))) { (void)(f274_gx(n_1614));
 } else { (void)(({ hrv *_o2316 = &(g163); hr_fs(_o2316, hr_str("(*_t", 4)); hr_fi(_o2316, tv_1615); hr_fs(_o2316, hr_str(")", 1)); }));
 }
}
static void f293_gen_hop(int64_t t_1616, int64_t o_1617, int64_t bt_1618) {
int64_t key_1619 = ((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)(t_1616)) * (int64_t)((int64_t)4096LL))) + (int64_t)((int64_t)((int64_t)((int64_t)(o_1617)) * (int64_t)((int64_t)64LL))))) + (int64_t)({ int64_t _r2317; if (((bt_1618) == (t_1616))) { _r2317 = ((int64_t)0LL);  } else { _r2317 = ((int64_t)1LL);  } _r2317; }))); 
{ hrv *_v2319 = &(g240); for (int64_t _k2319 = 0; _k2319 < _v2319->n; _k2319++) { int64_t h_1620 = ((int64_t*)_v2319->b)[_k2319]; if (((h_1620) == (key_1619))) { return;
 }
 } } _bk2318:; 
(void)(({ hrv *_v2320 = &(g240); int64_t _x2320 = key_1619; int64_t *_p2320 = (int64_t*)hr_grow(_v2320, 1, sizeof _x2320); *_p2320 = _x2320; _p2320; }));
(void)(f247_cbody(t_1616));
int64_t lt_1621 = f176_leaf_type(t_1616); 
bool sc_1622 = ((bt_1618) != (t_1616)); 
L93 sig_1623 = ({ L93 _t2321; memset(&_t2321, 0, sizeof _t2321); _t2321.n = 0; _t2321; }); 
(void)(({ L93 *_l2322 = &(sig_1623); hrv _o2322 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2322, hr_str("static ", 7)); if (_l2322->n + _o2322.n > 256) hr_die("format past a limited array's capacity", "hc/gen.amni:505"); memcpy(_l2322->e + _l2322->n, _o2322.b, (size_t)_o2322.n); _l2322->n += _o2322.n; }));
(void)(({ L93 *_v2323 = &(sig_1623); hsl _s2323 = f249_cn(t_1616); if (_v2323->n + _s2323.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:505"); memmove(_v2323->e + _v2323->n, _s2323.p, (size_t)_s2323.n * sizeof _v2323->e[0]); _v2323->n += _s2323.n; }));
(void)(({ L93 *_l2324 = &(sig_1623); hrv _o2324 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2324, hr_str(" hop", 4)); hr_fi(&_o2324, t_1616); hr_fs(&_o2324, hr_str("_", 1)); hr_fi(&_o2324, o_1617); hr_fs(&_o2324, hr_str("(", 1)); if (_l2324->n + _o2324.n > 256) hr_die("format past a limited array's capacity", "hc/gen.amni:505"); memcpy(_l2324->e + _l2324->n, _o2324.b, (size_t)_o2324.n); _l2324->n += _o2324.n; }));
(void)(({ L93 *_v2325 = &(sig_1623); hsl _s2325 = f249_cn(t_1616); if (_v2325->n + _s2325.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:506"); memmove(_v2325->e + _v2325->n, _s2325.p, (size_t)_s2325.n * sizeof _v2325->e[0]); _v2325->n += _s2325.n; }));
(void)(({ L93 *_v2326 = &(sig_1623); hsl _s2326 = hr_str(" a, ", 4); if (_v2326->n + _s2326.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:506"); memmove(_v2326->e + _v2326->n, _s2326.p, (size_t)_s2326.n * sizeof _v2326->e[0]); _v2326->n += _s2326.n; }));
(void)(({ L93 *_v2327 = &(sig_1623); hsl _s2327 = f249_cn(({ int64_t _r2328; if (sc_1622) { _r2328 = bt_1618;  } else { _r2328 = t_1616;  } _r2328; })); if (_v2327->n + _s2327.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:506"); memmove(_v2327->e + _v2327->n, _s2327.p, (size_t)_s2327.n * sizeof _v2327->e[0]); _v2327->n += _s2327.n; }));
(void)(({ L93 *_v2329 = &(sig_1623); hsl _s2329 = hr_str(" b)", 3); if (_v2329->n + _s2329.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:506"); memmove(_v2329->e + _v2329->n, _s2329.p, (size_t)_s2329.n * sizeof _v2329->e[0]); _v2329->n += _s2329.n; }));
(void)(({ hrv *_v2330 = &(g166); hsl _s2330 = ({ hsl _t2331 = ({ L93 *_t2332 = &(sig_1623); (hsl){ (uint8_t*)_t2332->e, _t2332->n }; }); int64_t _l2331 = 0, _h2331 = _t2331.n; if (_l2331 < 0 || _h2331 < _l2331 || _h2331 > _t2331.n) hr_slerr(_l2331, _h2331, _t2331.n, "hc/gen.amni:507"); (hsl){ _t2331.p + _l2331 * (int64_t)sizeof(uint8_t), _h2331 - _l2331 }; }); hr_append(_v2330, _s2330.p, _s2330.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2333 = &(g166); hsl _s2333 = hr_str(";\012", 2); hr_append(_v2333, _s2333.p, _s2333.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2334 = &(g169); hsl _s2334 = ({ hsl _t2335 = ({ L93 *_t2336 = &(sig_1623); (hsl){ (uint8_t*)_t2336->e, _t2336->n }; }); int64_t _l2335 = 0, _h2335 = _t2335.n; if (_l2335 < 0 || _h2335 < _l2335 || _h2335 > _t2335.n) hr_slerr(_l2335, _h2335, _t2335.n, "hc/gen.amni:508"); (hsl){ _t2335.p + _l2335 * (int64_t)sizeof(uint8_t), _h2335 - _l2335 }; }); hr_append(_v2334, _s2334.p, _s2334.n, sizeof(uint8_t)); }));
(void)(f286_hh(hr_str(" { ", 3)));
(void)(({ hrv *_v2337 = &(g169); hsl _s2337 = f249_cn(t_1616); hr_append(_v2337, _s2337.p, _s2337.n, sizeof(uint8_t)); }));
(void)(f286_hh(hr_str(" r; ", 4)));
(void)(f294_hop_body(t_1616, o_1617, hr_str("r", 1), hr_str("a", 1), hr_str("b", 1), sc_1622));
(void)(f286_hh(hr_str("return r; }\012", 12)));
}
static void f294_hop_body(int64_t t_1624, int64_t o_1625, hsl r_1626, hsl a_1627, hsl b_1628, bool sc_1629) {
int64_t k_1630 = ((int64_t)(((*({ hrv *_t2338 = &(g524); int64_t _i2338 = t_1624; (S1*)_t2338->b + hr_ix(_i2338, _t2338->n, "hc/gen.amni:513"); }))).k_)); 
if ((((k_1630) == (((int64_t)3LL))) || ((k_1630) == (((int64_t)4LL))))) { (void)(({ hrv *_o2339 = &(g169); hr_fs(_o2339, r_1626); hr_fs(_o2339, hr_str(" = (", 4)); }));
(void)(({ hrv *_v2340 = &(g169); hsl _s2340 = f249_cn(t_1624); hr_append(_v2340, _s2340.p, _s2340.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o2341 = &(g169); hr_fs(_o2341, hr_str(")((", 3)); hr_fs(_o2341, a_1627); hr_fs(_o2341, hr_str(") ", 2)); hr_fs(_o2341, f295_ar_op(o_1625)); hr_fs(_o2341, hr_str(" (", 2)); hr_fs(_o2341, b_1628); hr_fs(_o2341, hr_str(")); ", 4)); }));
return;
 }
if (((k_1630) == (((int64_t)5LL)))) { int64_t si_1632 = ((int64_t)(((*({ hrv *_t2342 = &(g524); int64_t _i2342 = t_1624; (S1*)_t2342->b + hr_ix(_i2342, _t2342->n, "hc/gen.amni:516"); }))).a_)); 
int64_t f0_1633 = ((int64_t)(((*({ hrv *_t2343 = &(g527); int64_t _i2343 = si_1632; (S10*)_t2343->b + hr_ix(_i2343, _t2343->n, "hc/gen.amni:516"); }))).f0_)); 
{ int32_t _e2345 = ((*({ hrv *_t2346 = &(g527); int64_t _i2346 = si_1632; (S10*)_t2346->b + hr_ix(_i2346, _t2346->n, "hc/gen.amni:517"); }))).fnum_; for (int32_t i_1634 = 0; i_1634 < _e2345; i_1634++) { S11 f_1635 = (*({ hrv *_t2347 = &(g528); int64_t _i2347 = ((int64_t)((int64_t)f0_1633 + (int64_t)((int64_t)(i_1634)))); (S11*)_t2347->b + hr_ix(_i2347, _t2347->n, "hc/gen.amni:518"); })); 
if ((((f_1635).ty_) < (((int32_t)0LL)))) { continue;
 }
L93 rr_1636 = ({ L93 _t2348; memset(&_t2348, 0, sizeof _t2348); _t2348.n = 0; _t2348; }); 
L93 aa_1637 = ({ L93 _t2349; memset(&_t2349, 0, sizeof _t2349); _t2349.n = 0; _t2349; }); 
L93 bb_1638 = ({ L93 _t2350; memset(&_t2350, 0, sizeof _t2350); _t2350.n = 0; _t2350; }); 
(void)(({ L93 *_v2351 = &(rr_1636); hsl _s2351 = r_1626; if (_v2351->n + _s2351.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:520"); memmove(_v2351->e + _v2351->n, _s2351.p, (size_t)_s2351.n * sizeof _v2351->e[0]); _v2351->n += _s2351.n; }));
(void)(({ L93 *_v2352 = &(rr_1636); uint8_t _x2352 = ((uint8_t)46LL); if (_v2352->n >= 256) hr_die("push past a limited array's capacity", "hc/gen.amni:520"); _v2352->e[_v2352->n] = _x2352; &_v2352->e[_v2352->n++]; }));
(void)(({ L93 *_v2353 = &(aa_1637); hsl _s2353 = a_1627; if (_v2353->n + _s2353.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:520"); memmove(_v2353->e + _v2353->n, _s2353.p, (size_t)_s2353.n * sizeof _v2353->e[0]); _v2353->n += _s2353.n; }));
(void)(({ L93 *_v2354 = &(aa_1637); uint8_t _x2354 = ((uint8_t)46LL); if (_v2354->n >= 256) hr_die("push past a limited array's capacity", "hc/gen.amni:520"); _v2354->e[_v2354->n] = _x2354; &_v2354->e[_v2354->n++]; }));
(void)(({ L93 *_v2355 = &(bb_1638); hsl _s2355 = b_1628; if (_v2355->n + _s2355.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:520"); memmove(_v2355->e + _v2355->n, _s2355.p, (size_t)_s2355.n * sizeof _v2355->e[0]); _v2355->n += _s2355.n; }));
if ((!(sc_1629))) { (void)(({ L93 *_v2356 = &(bb_1638); uint8_t _x2356 = ((uint8_t)46LL); if (_v2356->n >= 256) hr_die("push past a limited array's capacity", "hc/gen.amni:520"); _v2356->e[_v2356->n] = _x2356; &_v2356->e[_v2356->n++]; }));
 }
{ hsl _v2358 = f10_nm(((int64_t)((f_1635).name_))); for (int64_t _k2358 = 0; _k2358 < _v2358.n; _k2358++) { uint8_t ch_1639 = ((uint8_t*)_v2358.p)[_k2358]; (void)(({ L93 *_v2359 = &(rr_1636); uint8_t _x2359 = ch_1639; if (_v2359->n >= 256) hr_die("push past a limited array's capacity", "hc/gen.amni:521"); _v2359->e[_v2359->n] = _x2359; &_v2359->e[_v2359->n++]; }));
(void)(({ L93 *_v2360 = &(aa_1637); uint8_t _x2360 = ch_1639; if (_v2360->n >= 256) hr_die("push past a limited array's capacity", "hc/gen.amni:521"); _v2360->e[_v2360->n] = _x2360; &_v2360->e[_v2360->n++]; }));
if ((!(sc_1629))) { (void)(({ L93 *_v2361 = &(bb_1638); uint8_t _x2361 = ch_1639; if (_v2361->n >= 256) hr_die("push past a limited array's capacity", "hc/gen.amni:521"); _v2361->e[_v2361->n] = _x2361; &_v2361->e[_v2361->n++]; }));
 }
 } } _bk2357:; 
(void)(({ L93 *_v2362 = &(rr_1636); uint8_t _x2362 = ((uint8_t)95LL); if (_v2362->n >= 256) hr_die("push past a limited array's capacity", "hc/gen.amni:522"); _v2362->e[_v2362->n] = _x2362; &_v2362->e[_v2362->n++]; }));
(void)(({ L93 *_v2363 = &(aa_1637); uint8_t _x2363 = ((uint8_t)95LL); if (_v2363->n >= 256) hr_die("push past a limited array's capacity", "hc/gen.amni:522"); _v2363->e[_v2363->n] = _x2363; &_v2363->e[_v2363->n++]; }));
if ((!(sc_1629))) { (void)(({ L93 *_v2364 = &(bb_1638); uint8_t _x2364 = ((uint8_t)95LL); if (_v2364->n >= 256) hr_die("push past a limited array's capacity", "hc/gen.amni:522"); _v2364->e[_v2364->n] = _x2364; &_v2364->e[_v2364->n++]; }));
 }
(void)(f294_hop_body(((int64_t)((f_1635).ty_)), o_1625, ({ hsl _t2365 = ({ L93 *_t2366 = &(rr_1636); (hsl){ (uint8_t*)_t2366->e, _t2366->n }; }); int64_t _l2365 = 0, _h2365 = _t2365.n; if (_l2365 < 0 || _h2365 < _l2365 || _h2365 > _t2365.n) hr_slerr(_l2365, _h2365, _t2365.n, "hc/gen.amni:523"); (hsl){ _t2365.p + _l2365 * (int64_t)sizeof(uint8_t), _h2365 - _l2365 }; }), ({ hsl _t2367 = ({ L93 *_t2368 = &(aa_1637); (hsl){ (uint8_t*)_t2368->e, _t2368->n }; }); int64_t _l2367 = 0, _h2367 = _t2367.n; if (_l2367 < 0 || _h2367 < _l2367 || _h2367 > _t2367.n) hr_slerr(_l2367, _h2367, _t2367.n, "hc/gen.amni:523"); (hsl){ _t2367.p + _l2367 * (int64_t)sizeof(uint8_t), _h2367 - _l2367 }; }), ({ hsl _t2369 = ({ L93 *_t2370 = &(bb_1638); (hsl){ (uint8_t*)_t2370->e, _t2370->n }; }); int64_t _l2369 = 0, _h2369 = _t2369.n; if (_l2369 < 0 || _h2369 < _l2369 || _h2369 > _t2369.n) hr_slerr(_l2369, _h2369, _t2369.n, "hc/gen.amni:523"); (hsl){ _t2369.p + _l2369 * (int64_t)sizeof(uint8_t), _h2369 - _l2369 }; }), sc_1629));
 } } _bk2344:; 
return;
 }
if (f267_is_fix(t_1624)) { int64_t p_1640 = f278_nt(); 
(void)(({ hrv *_o2371 = &(g169); hr_fs(_o2371, hr_str("for (int64_t _i", 15)); hr_fi(_o2371, p_1640); hr_fs(_o2371, hr_str(" = 0; _i", 8)); hr_fi(_o2371, p_1640); hr_fs(_o2371, hr_str(" < ", 3)); hr_fi(_o2371, ((*({ hrv *_t2372 = &(g524); int64_t _i2372 = t_1624; (S1*)_t2372->b + hr_ix(_i2372, _t2372->n, "hc/gen.amni:529"); }))).b_); hr_fs(_o2371, hr_str("; _i", 4)); hr_fi(_o2371, p_1640); hr_fs(_o2371, hr_str("++) { ", 6)); }));
L93 rr_1641 = ({ L93 _t2373; memset(&_t2373, 0, sizeof _t2373); _t2373.n = 0; _t2373; }); 
L93 aa_1642 = ({ L93 _t2374; memset(&_t2374, 0, sizeof _t2374); _t2374.n = 0; _t2374; }); 
L93 bb_1643 = ({ L93 _t2375; memset(&_t2375, 0, sizeof _t2375); _t2375.n = 0; _t2375; }); 
(void)(({ L93 *_l2376 = &(rr_1641); hrv _o2376 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2376, r_1626); hr_fs(&_o2376, hr_str(".e[_i", 5)); hr_fi(&_o2376, p_1640); hr_fs(&_o2376, hr_str("]", 1)); if (_l2376->n + _o2376.n > 256) hr_die("format past a limited array's capacity", "hc/gen.amni:531"); memcpy(_l2376->e + _l2376->n, _o2376.b, (size_t)_o2376.n); _l2376->n += _o2376.n; }));
(void)(({ L93 *_l2377 = &(aa_1642); hrv _o2377 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2377, a_1627); hr_fs(&_o2377, hr_str(".e[_i", 5)); hr_fi(&_o2377, p_1640); hr_fs(&_o2377, hr_str("]", 1)); if (_l2377->n + _o2377.n > 256) hr_die("format past a limited array's capacity", "hc/gen.amni:531"); memcpy(_l2377->e + _l2377->n, _o2377.b, (size_t)_o2377.n); _l2377->n += _o2377.n; }));
if (sc_1629) { (void)(({ L93 *_v2378 = &(bb_1643); hsl _s2378 = b_1628; if (_v2378->n + _s2378.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:531"); memmove(_v2378->e + _v2378->n, _s2378.p, (size_t)_s2378.n * sizeof _v2378->e[0]); _v2378->n += _s2378.n; }));
 } else { (void)(({ L93 *_l2379 = &(bb_1643); hrv _o2379 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2379, b_1628); hr_fs(&_o2379, hr_str(".e[_i", 5)); hr_fi(&_o2379, p_1640); hr_fs(&_o2379, hr_str("]", 1)); if (_l2379->n + _o2379.n > 256) hr_die("format past a limited array's capacity", "hc/gen.amni:531"); memcpy(_l2379->e + _l2379->n, _o2379.b, (size_t)_o2379.n); _l2379->n += _o2379.n; }));
 }
(void)(f294_hop_body(((int64_t)(((*({ hrv *_t2380 = &(g524); int64_t _i2380 = t_1624; (S1*)_t2380->b + hr_ix(_i2380, _t2380->n, "hc/gen.amni:532"); }))).a_)), o_1625, ({ hsl _t2381 = ({ L93 *_t2382 = &(rr_1641); (hsl){ (uint8_t*)_t2382->e, _t2382->n }; }); int64_t _l2381 = 0, _h2381 = _t2381.n; if (_l2381 < 0 || _h2381 < _l2381 || _h2381 > _t2381.n) hr_slerr(_l2381, _h2381, _t2381.n, "hc/gen.amni:532"); (hsl){ _t2381.p + _l2381 * (int64_t)sizeof(uint8_t), _h2381 - _l2381 }; }), ({ hsl _t2383 = ({ L93 *_t2384 = &(aa_1642); (hsl){ (uint8_t*)_t2384->e, _t2384->n }; }); int64_t _l2383 = 0, _h2383 = _t2383.n; if (_l2383 < 0 || _h2383 < _l2383 || _h2383 > _t2383.n) hr_slerr(_l2383, _h2383, _t2383.n, "hc/gen.amni:532"); (hsl){ _t2383.p + _l2383 * (int64_t)sizeof(uint8_t), _h2383 - _l2383 }; }), ({ hsl _t2385 = ({ L93 *_t2386 = &(bb_1643); (hsl){ (uint8_t*)_t2386->e, _t2386->n }; }); int64_t _l2385 = 0, _h2385 = _t2385.n; if (_l2385 < 0 || _h2385 < _l2385 || _h2385 > _t2385.n) hr_slerr(_l2385, _h2385, _t2385.n, "hc/gen.amni:532"); (hsl){ _t2385.p + _l2385 * (int64_t)sizeof(uint8_t), _h2385 - _l2385 }; }), sc_1629));
(void)(f286_hh(hr_str("} ", 2)));
 }
}
static hsl f295_ar_op(int64_t o_1631) {
if ((((o_1631) == (((int64_t)21LL))) || ((o_1631) == (((int64_t)26LL))))) { return hr_str("+", 1);
 }
if ((((o_1631) == (((int64_t)22LL))) || ((o_1631) == (((int64_t)27LL))))) { return hr_str("-", 1);
 }
if ((((o_1631) == (((int64_t)23LL))) || ((o_1631) == (((int64_t)28LL))))) { return hr_str("*", 1);
 }
if ((((o_1631) == (((int64_t)24LL))) || ((o_1631) == (((int64_t)29LL))))) { return hr_str("/", 1);
 }
if ((((o_1631) == (((int64_t)25LL))) || ((o_1631) == (((int64_t)30LL))))) { return hr_str("%", 1);
 }
if ((((o_1631) == (((int64_t)49LL))) || ((o_1631) == (((int64_t)31LL))))) { return hr_str("&", 1);
 }
if ((((o_1631) == (((int64_t)50LL))) || ((o_1631) == (((int64_t)32LL))))) { return hr_str("|", 1);
 }
if ((((o_1631) == (((int64_t)51LL))) || ((o_1631) == (((int64_t)33LL))))) { return hr_str("^", 1);
 }
if ((((o_1631) == (((int64_t)43LL))) || ((o_1631) == (((int64_t)45LL))))) { return hr_str("<<", 2);
 }
if ((((o_1631) == (((int64_t)44LL))) || ((o_1631) == (((int64_t)46LL))))) { return hr_str(">>", 2);
 }
return hr_str("\077", 1);
}
static void f296_wloc(int64_t n_1645) {
S3 x_1646 = (*({ hrv *_t2387 = &(g885); int64_t _i2387 = ((*({ hrv *_t2388 = &(g675); int64_t _i2388 = f103_max(n_1645, ((int64_t)0LL)); (S4*)_t2388->b + hr_ix(_i2388, _t2388->n, "hc/gen.amni:100"); }))).t_; (S3*)_t2387->b + hr_ix(_i2387, _t2387->n, "hc/gen.amni:100"); })); 
(void)(f245_ow(hr_str("\"", 1)));
{ hsl _v2390 = f10_nm(((int64_t)(((*({ hrv *_t2391 = &(g884); int64_t _i2391 = (x_1646).f_; (S2*)_t2391->b + hr_ix(_i2391, _t2391->n, "hc/gen.amni:100"); }))).name_))); for (int64_t _k2390 = 0; _k2390 < _v2390.n; _k2390++) { uint8_t c_1647 = ((uint8_t*)_v2390.p)[_k2390]; if ((((c_1647) == (((uint8_t)34LL))) || ((c_1647) == (((uint8_t)92LL))))) { (void)(({ hrv *_v2392 = &(g163); uint8_t _x2392 = ((uint8_t)92LL); uint8_t *_p2392 = (uint8_t*)hr_grow(_v2392, 1, sizeof _x2392); *_p2392 = _x2392; _p2392; }));
 }
(void)(({ hrv *_v2393 = &(g163); uint8_t _x2393 = c_1647; uint8_t *_p2393 = (uint8_t*)hr_grow(_v2393, 1, sizeof _x2393); *_p2393 = _x2393; _p2393; }));
 } } _bk2389:; 
(void)(({ hrv *_o2394 = &(g163); hr_fs(_o2394, hr_str(":", 1)); hr_fi(_o2394, (x_1646).line_); hr_fs(_o2394, hr_str("\"", 1)); }));
}
static void f297_gun(int64_t n_1648) {
S4 x_1649 = (*({ hrv *_t2395 = &(g675); int64_t _i2395 = n_1648; (S4*)_t2395->b + hr_ix(_i2395, _t2395->n, "hc/gen.amni:271"); })); 
int64_t o_1650 = ((int64_t)((x_1649).op_)); 
int64_t a_1651 = ((int64_t)((x_1649).a_)); 
if (((o_1650) == (((int64_t)47LL)))) { (void)(f245_ow(hr_str("(!(", 3)));
(void)(f274_gx(a_1651));
(void)(f245_ow(hr_str("))", 2)));
return;
 }
if (((o_1650) == (((int64_t)49LL)))) { (void)(f274_gx(a_1651));
return;
 }
int64_t t_1652 = f264_fin(n_1648); 
if (((o_1650) == (((int64_t)22LL)))) { if (((((*({ hrv *_t2396 = &(g524); int64_t _i2396 = t_1652; (S1*)_t2396->b + hr_ix(_i2396, _t2396->n, "hc/gen.amni:275"); }))).k_) == (((uint8_t)4LL)))) { (void)(f245_ow(hr_str("(-(", 3)));
(void)(f274_gx(a_1651));
(void)(f245_ow(hr_str("))", 2)));
return;
 }
if (((f175_leaf_kind(t_1652)) >= (((int64_t)4LL)))) { (void)(f245_ow(hr_str("hneg", 4)));
(void)(f279_oi(t_1652));
(void)(f245_ow(hr_str("(", 1)));
(void)(f274_gx(a_1651));
(void)(f245_ow(hr_str(")", 1)));
(void)(f298_gen_hneg(t_1652));
return;
 }
(void)(f245_ow(hr_str("((", 2)));
(void)(f246_ct(t_1652));
(void)(f245_ow(hr_str(")(0 - (uint64_t)(", 17)));
(void)(f274_gx(a_1651));
(void)(f245_ow(hr_str(")))", 3)));
return;
 }
if (((o_1650) == (((int64_t)48LL)))) { (void)(f245_ow(hr_str("((", 2)));
(void)(f246_ct(t_1652));
(void)(f245_ow(hr_str(")~(", 3)));
(void)(f274_gx(a_1651));
(void)(f245_ow(hr_str("))", 2)));
return;
 }
if (((o_1650) == (((int64_t)23LL)))) { (void)(f245_ow(hr_str("(*", 2)));
(void)(f274_gx(a_1651));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if (((o_1650) == (((int64_t)21LL)))) { (void)(f274_gx(a_1651));
return;
 }
(void)(f272_gerr(n_1648, hr_str("unsupported unary operator", 26)));
}
static void f298_gen_hneg(int64_t t_1653) {
{ hrv *_v2398 = &(g243); for (int64_t _k2398 = 0; _k2398 < _v2398->n; _k2398++) { int32_t h_1654 = ((int32_t*)_v2398->b)[_k2398]; if (((((int64_t)(h_1654))) == (t_1653))) { return;
 }
 } } _bk2397:; 
(void)(({ hrv *_v2399 = &(g243); int32_t _x2399 = ((int32_t)(t_1653)); int32_t *_p2399 = (int32_t*)hr_grow(_v2399, 1, sizeof _x2399); *_p2399 = _x2399; _p2399; }));
(void)(f247_cbody(t_1653));
L93 sig_1655 = ({ L93 _t2400; memset(&_t2400, 0, sizeof _t2400); _t2400.n = 0; _t2400; }); 
(void)(({ L93 *_l2401 = &(sig_1655); hrv _o2401 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2401, hr_str("static ", 7)); if (_l2401->n + _o2401.n > 256) hr_die("format past a limited array's capacity", "hc/gen.amni:542"); memcpy(_l2401->e + _l2401->n, _o2401.b, (size_t)_o2401.n); _l2401->n += _o2401.n; }));
(void)(({ L93 *_v2402 = &(sig_1655); hsl _s2402 = f249_cn(t_1653); if (_v2402->n + _s2402.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:542"); memmove(_v2402->e + _v2402->n, _s2402.p, (size_t)_s2402.n * sizeof _v2402->e[0]); _v2402->n += _s2402.n; }));
(void)(({ L93 *_l2403 = &(sig_1655); hrv _o2403 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2403, hr_str(" hneg", 5)); hr_fi(&_o2403, t_1653); hr_fs(&_o2403, hr_str("(", 1)); if (_l2403->n + _o2403.n > 256) hr_die("format past a limited array's capacity", "hc/gen.amni:542"); memcpy(_l2403->e + _l2403->n, _o2403.b, (size_t)_o2403.n); _l2403->n += _o2403.n; }));
(void)(({ L93 *_v2404 = &(sig_1655); hsl _s2404 = f249_cn(t_1653); if (_v2404->n + _s2404.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:542"); memmove(_v2404->e + _v2404->n, _s2404.p, (size_t)_s2404.n * sizeof _v2404->e[0]); _v2404->n += _s2404.n; }));
(void)(({ L93 *_v2405 = &(sig_1655); hsl _s2405 = hr_str(" a)", 3); if (_v2405->n + _s2405.n > 256) hr_die("append past a limited array's capacity", "hc/gen.amni:542"); memmove(_v2405->e + _v2405->n, _s2405.p, (size_t)_s2405.n * sizeof _v2405->e[0]); _v2405->n += _s2405.n; }));
(void)(({ hrv *_v2406 = &(g166); hsl _s2406 = ({ hsl _t2407 = ({ L93 *_t2408 = &(sig_1655); (hsl){ (uint8_t*)_t2408->e, _t2408->n }; }); int64_t _l2407 = 0, _h2407 = _t2407.n; if (_l2407 < 0 || _h2407 < _l2407 || _h2407 > _t2407.n) hr_slerr(_l2407, _h2407, _t2407.n, "hc/gen.amni:543"); (hsl){ _t2407.p + _l2407 * (int64_t)sizeof(uint8_t), _h2407 - _l2407 }; }); hr_append(_v2406, _s2406.p, _s2406.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2409 = &(g166); hsl _s2409 = hr_str(";\012", 2); hr_append(_v2409, _s2409.p, _s2409.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2410 = &(g169); hsl _s2410 = ({ hsl _t2411 = ({ L93 *_t2412 = &(sig_1655); (hsl){ (uint8_t*)_t2412->e, _t2412->n }; }); int64_t _l2411 = 0, _h2411 = _t2411.n; if (_l2411 < 0 || _h2411 < _l2411 || _h2411 > _t2411.n) hr_slerr(_l2411, _h2411, _t2411.n, "hc/gen.amni:544"); (hsl){ _t2411.p + _l2411 * (int64_t)sizeof(uint8_t), _h2411 - _l2411 }; }); hr_append(_v2410, _s2410.p, _s2410.n, sizeof(uint8_t)); }));
(void)(f286_hh(hr_str(" { ", 3)));
(void)(({ hrv *_v2413 = &(g169); hsl _s2413 = f249_cn(t_1653); hr_append(_v2413, _s2413.p, _s2413.n, sizeof(uint8_t)); }));
(void)(f286_hh(hr_str(" z; memset(&z, 0, sizeof z); ", 29)));
(void)(({ hrv *_v2414 = &(g169); hsl _s2414 = f249_cn(t_1653); hr_append(_v2414, _s2414.p, _s2414.n, sizeof(uint8_t)); }));
(void)(f286_hh(hr_str(" r; ", 4)));
(void)(f294_hop_body(t_1653, ((int64_t)22LL), hr_str("r", 1), hr_str("z", 1), hr_str("a", 1), false));
(void)(f286_hh(hr_str("return r; }\012", 12)));
}
static void f299_gidx(int64_t n_1665) {
S4 x_1666 = (*({ hrv *_t2415 = &(g675); int64_t _i2415 = n_1665; (S4*)_t2415->b + hr_ix(_i2415, _t2415->n, "hc/gen.amni:282"); })); 
int64_t a_1667 = ((int64_t)((x_1666).a_)); 
int64_t bt_1668 = f140_at(a_1667); 
int64_t d_1669 = f174_deref(bt_1668); 
int64_t e_1670 = ((int64_t)(((*({ hrv *_t2416 = &(g524); int64_t _i2416 = d_1669; (S1*)_t2416->b + hr_ix(_i2416, _t2416->n, "hc/gen.amni:286"); }))).a_)); 
int64_t p_1671 = f278_nt(); 
if ((f267_is_fix(d_1669) && ((((*({ hrv *_t2417 = &(g524); int64_t _i2417 = bt_1668; (S1*)_t2417->b + hr_ix(_i2417, _t2417->n, "hc/gen.amni:288"); }))).k_) != (((uint8_t)10LL))))) { (void)(f245_ow(hr_str("(", 1)));
(void)(f274_gx(a_1667));
(void)(f245_ow(hr_str(").e[hr_ix(", 10)));
(void)(f274_gx(((int64_t)((x_1666).b_))));
(void)(({ hrv *_o2418 = &(g163); hr_fs(_o2418, hr_str(", ", 2)); hr_fi(_o2418, ((*({ hrv *_t2419 = &(g524); int64_t _i2419 = d_1669; (S1*)_t2419->b + hr_ix(_i2419, _t2419->n, "hc/gen.amni:289"); }))).b_); hr_fs(_o2418, hr_str(", ", 2)); }));
(void)(f296_wloc(n_1665));
(void)(f245_ow(hr_str(")]", 2)));
return;
 }
(void)(f245_ow(hr_str("(*({ ", 5)));
if (((((*({ hrv *_t2420 = &(g524); int64_t _i2420 = d_1669; (S1*)_t2420->b + hr_ix(_i2420, _t2420->n, "hc/gen.amni:292"); }))).k_) == (((uint8_t)9LL)))) { (void)(f245_ow(hr_str("hsl _t", 6)));
(void)(f279_oi(p_1671));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(a_1667));
(void)(f245_ow(hr_str("; int64_t _i", 12)));
(void)(f279_oi(p_1671));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(((int64_t)((x_1666).b_))));
(void)(f245_ow(hr_str("; (", 3)));
(void)(f246_ct(e_1670));
(void)(f245_ow(hr_str("*)_t", 4)));
(void)(f279_oi(p_1671));
(void)(({ hrv *_o2421 = &(g163); hr_fs(_o2421, hr_str(".p + hr_ix(_i", 13)); hr_fi(_o2421, p_1671); hr_fs(_o2421, hr_str(", _t", 4)); hr_fi(_o2421, p_1671); hr_fs(_o2421, hr_str(".n, ", 4)); }));
(void)(f296_wloc(n_1665));
(void)(f245_ow(hr_str("); }))", 6)));
return;
 }
(void)(f246_ct(d_1669));
(void)(f245_ow(hr_str(" *_t", 4)));
(void)(f279_oi(p_1671));
(void)(f245_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t2422 = &(g524); int64_t _i2422 = bt_1668; (S1*)_t2422->b + hr_ix(_i2422, _t2422->n, "hc/gen.amni:294"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_gx0(a_1667));
 } else { if (f257_is_place(a_1667)) { (void)(f245_ow(hr_str("&(", 2)));
(void)(f274_gx(a_1667));
(void)(f245_ow(hr_str(")", 1)));
 } else { int64_t k_1672 = f258_tmp(d_1669, f253_is_res(d_1669)); 
(void)(f245_ow(hr_str("&(", 2)));
(void)(f259_ot(k_1672));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f254_gxo(a_1667));
(void)(f245_ow(hr_str(")", 1)));
 }
 }
(void)(f245_ow(hr_str("; int64_t _i", 12)));
(void)(f279_oi(p_1671));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(((int64_t)((x_1666).b_))));
(void)(f245_ow(hr_str("; ", 2)));
if (f253_is_res(d_1669)) { (void)(f245_ow(hr_str("(", 1)));
(void)(f246_ct(e_1670));
(void)(f245_ow(hr_str("*)_t", 4)));
(void)(f279_oi(p_1671));
(void)(({ hrv *_o2423 = &(g163); hr_fs(_o2423, hr_str("->b + hr_ix(_i", 14)); hr_fi(_o2423, p_1671); hr_fs(_o2423, hr_str(", _t", 4)); hr_fi(_o2423, p_1671); hr_fs(_o2423, hr_str("->n, ", 5)); }));
(void)(f296_wloc(n_1665));
(void)(f245_ow(hr_str("); }))", 6)));
return;
 }
if (f267_is_fix(d_1669)) { (void)(({ hrv *_o2424 = &(g163); hr_fs(_o2424, hr_str("_t", 2)); hr_fi(_o2424, p_1671); hr_fs(_o2424, hr_str("->e + hr_ix(_i", 14)); hr_fi(_o2424, p_1671); hr_fs(_o2424, hr_str(", ", 2)); hr_fi(_o2424, ((*({ hrv *_t2425 = &(g524); int64_t _i2425 = d_1669; (S1*)_t2425->b + hr_ix(_i2425, _t2425->n, "hc/gen.amni:297"); }))).b_); hr_fs(_o2424, hr_str(", ", 2)); }));
(void)(f296_wloc(n_1665));
(void)(f245_ow(hr_str("); }))", 6)));
return;
 }
(void)(({ hrv *_o2426 = &(g163); hr_fs(_o2426, hr_str("_t", 2)); hr_fi(_o2426, p_1671); hr_fs(_o2426, hr_str("->e + hr_ix(_i", 14)); hr_fi(_o2426, p_1671); hr_fs(_o2426, hr_str(", _t", 4)); hr_fi(_o2426, p_1671); hr_fs(_o2426, hr_str("->n, ", 5)); }));
(void)(f296_wloc(n_1665));
(void)(f245_ow(hr_str("); }))", 6)));
}
static void f300_gslice(int64_t n_1673) {
S4 x_1674 = (*({ hrv *_t2427 = &(g675); int64_t _i2427 = n_1673; (S4*)_t2427->b + hr_ix(_i2427, _t2427->n, "hc/gen.amni:301"); })); 
int64_t a_1675 = ((int64_t)((x_1674).a_)); 
int64_t d_1676 = f174_deref(f140_at(a_1675)); 
int64_t e_1677 = ((int64_t)(((*({ hrv *_t2428 = &(g524); int64_t _i2428 = d_1676; (S1*)_t2428->b + hr_ix(_i2428, _t2428->n, "hc/gen.amni:304"); }))).a_)); 
int64_t p_1678 = f278_nt(); 
(void)(f245_ow(hr_str("({ hsl _t", 9)));
(void)(f279_oi(p_1678));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f277_gsl(a_1675, f140_at(a_1675)));
(void)(f245_ow(hr_str("; int64_t _l", 12)));
(void)(f279_oi(p_1678));
(void)(f245_ow(hr_str(" = ", 3)));
if ((((x_1674).b_) >= (((int32_t)0LL)))) { if (((((uint16_t)((uint64_t)(x_1674).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_o2429 = &(g163); hr_fs(_o2429, hr_str("_t", 2)); hr_fi(_o2429, p_1678); hr_fs(_o2429, hr_str(".n - ", 5)); }));
 }
(void)(f274_gx(((int64_t)((x_1674).b_))));
 } else { (void)(f245_ow(hr_str("0", 1)));
 }
(void)(f245_ow(hr_str(", _h", 4)));
(void)(f279_oi(p_1678));
(void)(f245_ow(hr_str(" = ", 3)));
if ((((x_1674).c_) >= (((int32_t)0LL)))) { if (((((uint16_t)((uint64_t)(x_1674).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_o2430 = &(g163); hr_fs(_o2430, hr_str("_t", 2)); hr_fi(_o2430, p_1678); hr_fs(_o2430, hr_str(".n - ", 5)); }));
 }
(void)(f274_gx(((int64_t)((x_1674).c_))));
 } else { (void)(({ hrv *_o2431 = &(g163); hr_fs(_o2431, hr_str("_t", 2)); hr_fi(_o2431, p_1678); hr_fs(_o2431, hr_str(".n", 2)); }));
 }
(void)(({ hrv *_o2432 = &(g163); hr_fs(_o2432, hr_str("; if (_l", 8)); hr_fi(_o2432, p_1678); hr_fs(_o2432, hr_str(" < 0 || _h", 10)); hr_fi(_o2432, p_1678); hr_fs(_o2432, hr_str(" < _l", 5)); hr_fi(_o2432, p_1678); hr_fs(_o2432, hr_str(" || _h", 6)); hr_fi(_o2432, p_1678); hr_fs(_o2432, hr_str(" > _t", 5)); hr_fi(_o2432, p_1678); hr_fs(_o2432, hr_str(".n) hr_slerr(_l", 15)); hr_fi(_o2432, p_1678); hr_fs(_o2432, hr_str(", _h", 4)); hr_fi(_o2432, p_1678); hr_fs(_o2432, hr_str(", _t", 4)); hr_fi(_o2432, p_1678); hr_fs(_o2432, hr_str(".n, ", 4)); }));
(void)(f296_wloc(n_1673));
(void)(({ hrv *_o2433 = &(g163); hr_fs(_o2433, hr_str("); (hsl){ _t", 12)); hr_fi(_o2433, p_1678); hr_fs(_o2433, hr_str(".p + _l", 7)); hr_fi(_o2433, p_1678); hr_fs(_o2433, hr_str(" * (int64_t)sizeof(", 19)); }));
(void)(f246_ct(e_1677));
(void)(({ hrv *_o2434 = &(g163); hr_fs(_o2434, hr_str("), _h", 5)); hr_fi(_o2434, p_1678); hr_fs(_o2434, hr_str(" - _l", 5)); hr_fi(_o2434, p_1678); hr_fs(_o2434, hr_str(" }; })", 6)); }));
}
static void f301_garr(int64_t n_1680) {
S4 x_1681 = (*({ hrv *_t2435 = &(g675); int64_t _i2435 = n_1680; (S4*)_t2435->b + hr_ix(_i2435, _t2435->n, "hc/gen.amni:314"); })); 
int64_t t_1682 = f140_at(n_1680); 
int64_t e_1683 = ((int64_t)(((*({ hrv *_t2436 = &(g524); int64_t _i2436 = t_1682; (S1*)_t2436->b + hr_ix(_i2436, _t2436->n, "hc/gen.amni:316"); }))).a_)); 
int64_t p_1684 = f278_nt(); 
if (f253_is_res(t_1682)) { if (((((x_1681).n_) == (((int32_t)0LL))) && (((x_1681).a_) < (((int32_t)0LL))))) { (void)(f245_ow(hr_str("((hrv){0})", 10)));
return;
 }
(void)(f245_ow(hr_str("({ hrv _t", 9)));
(void)(f279_oi(p_1684));
(void)(f245_ow(hr_str(" = {0}; ", 8)));
if ((((x_1681).a_) >= (((int32_t)0LL)))) { (void)(f245_ow(hr_str("int64_t _c", 10)));
(void)(f279_oi(p_1684));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(((int64_t)((x_1681).b_))));
(void)(f245_ow(hr_str("; ", 2)));
(void)(f246_ct(e_1683));
(void)(f245_ow(hr_str(" _v", 3)));
(void)(f279_oi(p_1684));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(((int64_t)((x_1681).a_))));
(void)(f245_ow(hr_str("; ", 2)));
(void)(f246_ct(e_1683));
(void)(f245_ow(hr_str(" *_p", 4)));
(void)(f279_oi(p_1684));
(void)(f245_ow(hr_str(" = (", 4)));
(void)(f246_ct(e_1683));
(void)(({ hrv *_o2437 = &(g163); hr_fs(_o2437, hr_str("*)hr_grow(&_t", 13)); hr_fi(_o2437, p_1684); hr_fs(_o2437, hr_str(", _c", 4)); hr_fi(_o2437, p_1684); hr_fs(_o2437, hr_str(", sizeof _v", 11)); hr_fi(_o2437, p_1684); hr_fs(_o2437, hr_str("); for (int64_t _k = 0; _k < _c", 31)); hr_fi(_o2437, p_1684); hr_fs(_o2437, hr_str("; _k++) _p", 10)); hr_fi(_o2437, p_1684); hr_fs(_o2437, hr_str("[_k] = _v", 9)); hr_fi(_o2437, p_1684); hr_fs(_o2437, hr_str("; ", 2)); }));
 } else { (void)(f246_ct(e_1683));
(void)(f245_ow(hr_str(" *_p", 4)));
(void)(f279_oi(p_1684));
(void)(f245_ow(hr_str(" = (", 4)));
(void)(f246_ct(e_1683));
(void)(({ hrv *_o2438 = &(g163); hr_fs(_o2438, hr_str("*)hr_grow(&_t", 13)); hr_fi(_o2438, p_1684); hr_fs(_o2438, hr_str(", ", 2)); hr_fi(_o2438, (x_1681).n_); hr_fs(_o2438, hr_str(", sizeof(", 9)); }));
(void)(f246_ct(e_1683));
(void)(f245_ow(hr_str(")); ", 4)));
{ int32_t _e2440 = (x_1681).n_; for (int32_t i_1685 = 0; i_1685 < _e2440; i_1685++) { (void)(({ hrv *_o2441 = &(g163); hr_fs(_o2441, hr_str("_p", 2)); hr_fi(_o2441, p_1684); hr_fs(_o2441, hr_str("[", 1)); hr_fi(_o2441, i_1685); hr_fs(_o2441, hr_str("] = ", 4)); }));
(void)(f274_gx(f90_kid(n_1680, ((int64_t)(i_1685)))));
(void)(f245_ow(hr_str("; ", 2)));
 } } _bk2439:; 
 }
(void)(f245_ow(hr_str("_t", 2)));
(void)(f279_oi(p_1684));
(void)(f245_ow(hr_str("; })", 4)));
return;
 }
if ((f267_is_fix(t_1682) || f268_is_lim(t_1682))) { (void)(f245_ow(hr_str("({ ", 3)));
(void)(f246_ct(t_1682));
(void)(f245_ow(hr_str(" _t", 3)));
(void)(f279_oi(p_1684));
(void)(f245_ow(hr_str("; ", 2)));
if ((((x_1681).a_) >= (((int32_t)0LL)))) { (void)(f246_ct(e_1683));
(void)(f245_ow(hr_str(" _v", 3)));
(void)(f279_oi(p_1684));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(((int64_t)((x_1681).a_))));
(void)(({ hrv *_o2442 = &(g163); hr_fs(_o2442, hr_str("; for (int64_t _k = 0; _k < ", 28)); hr_fi(_o2442, ({ int64_t _r2443; if (f267_is_fix(t_1682)) { _r2443 = ((*({ hrv *_t2444 = &(g524); int64_t _i2444 = t_1682; (S1*)_t2444->b + hr_ix(_i2444, _t2444->n, "hc/gen.amni:328"); }))).b_;  } else { _r2443 = ((int64_t)0LL);  } _r2443; })); hr_fs(_o2442, hr_str("; _k++) _t", 10)); hr_fi(_o2442, p_1684); hr_fs(_o2442, hr_str(".e[_k] = _v", 11)); hr_fi(_o2442, p_1684); hr_fs(_o2442, hr_str("; ", 2)); }));
if (f268_is_lim(t_1682)) { (void)(f245_ow(hr_str("int64_t _c", 10)));
(void)(f279_oi(p_1684));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(((int64_t)((x_1681).b_))));
(void)(({ hrv *_o2445 = &(g163); hr_fs(_o2445, hr_str("; for (int64_t _k = 0; _k < _c", 30)); hr_fi(_o2445, p_1684); hr_fs(_o2445, hr_str("; _k++) _t", 10)); hr_fi(_o2445, p_1684); hr_fs(_o2445, hr_str(".e[_k] = _v", 11)); hr_fi(_o2445, p_1684); hr_fs(_o2445, hr_str("; _t", 4)); hr_fi(_o2445, p_1684); hr_fs(_o2445, hr_str(".n = _c", 7)); hr_fi(_o2445, p_1684); hr_fs(_o2445, hr_str("; ", 2)); }));
 }
 } else { if (f268_is_lim(t_1682)) { (void)(({ hrv *_o2446 = &(g163); hr_fs(_o2446, hr_str("memset(&_t", 10)); hr_fi(_o2446, p_1684); hr_fs(_o2446, hr_str(", 0, sizeof _t", 14)); hr_fi(_o2446, p_1684); hr_fs(_o2446, hr_str("); _t", 5)); hr_fi(_o2446, p_1684); hr_fs(_o2446, hr_str(".n = ", 5)); hr_fi(_o2446, (x_1681).n_); hr_fs(_o2446, hr_str("; ", 2)); }));
 }
{ int32_t _e2448 = (x_1681).n_; for (int32_t i_1686 = 0; i_1686 < _e2448; i_1686++) { (void)(({ hrv *_o2449 = &(g163); hr_fs(_o2449, hr_str("_t", 2)); hr_fi(_o2449, p_1684); hr_fs(_o2449, hr_str(".e[", 3)); hr_fi(_o2449, i_1686); hr_fs(_o2449, hr_str("] = ", 4)); }));
(void)(f274_gx(f90_kid(n_1680, ((int64_t)(i_1686)))));
(void)(f245_ow(hr_str("; ", 2)));
 } } _bk2447:; 
 }
(void)(f245_ow(hr_str("_t", 2)));
(void)(f279_oi(p_1684));
(void)(f245_ow(hr_str("; })", 4)));
return;
 }
(void)(f272_gerr(n_1680, hr_str("unsupported array literal type", 30)));
}
static void f302_gslit(int64_t n_1687) {
S4 x_1688 = (*({ hrv *_t2450 = &(g675); int64_t _i2450 = n_1687; (S4*)_t2450->b + hr_ix(_i2450, _t2450->n, "hc/gen.amni:345"); })); 
int64_t t_1689 = f140_at(n_1687); 
int64_t si_1690 = f156_rv(n_1687); 
int64_t f0_1691 = ((int64_t)(((*({ hrv *_t2451 = &(g527); int64_t _i2451 = si_1690; (S10*)_t2451->b + hr_ix(_i2451, _t2451->n, "hc/gen.amni:348"); }))).f0_)); 
(void)(f245_ow(hr_str("((", 2)));
(void)(f246_ct(t_1689));
(void)(f245_ow(hr_str("){ ", 3)));
bool any_1692 = false; 
{ int32_t _e2453 = ((*({ hrv *_t2454 = &(g527); int64_t _i2454 = si_1690; (S10*)_t2454->b + hr_ix(_i2454, _t2454->n, "hc/gen.amni:351"); }))).fnum_; for (int32_t j_1693 = 0; j_1693 < _e2453; j_1693++) { S11 f_1694 = (*({ hrv *_t2455 = &(g528); int64_t _i2455 = ((int64_t)((int64_t)f0_1691 + (int64_t)((int64_t)(j_1693)))); (S11*)_t2455->b + hr_ix(_i2455, _t2455->n, "hc/gen.amni:352"); })); 
if ((((f_1694).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t given_1695 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e2457 = (x_1688).n_; for (int32_t i_1696 = 0; i_1696 < _e2457; i_1696++) { if (((f156_rv(f90_kid(n_1687, ((int64_t)(i_1696))))) == (((int64_t)(j_1693))))) { given_1695 = f90_kid(n_1687, ((int64_t)(i_1696)));
 }
 } } _bk2456:; 
if ((((given_1695) < (((int64_t)0LL))) && (((f_1694).def_) < (((int32_t)0LL))))) { continue;
 }
(void)(f245_ow(hr_str(".", 1)));
(void)(f252_fname_into((&(g163)), ((int64_t)((f_1694).name_))));
(void)(f245_ow(hr_str(" = ", 3)));
if (((given_1695) >= (((int64_t)0LL)))) { int64_t v_1697 = ((int64_t)(((*({ hrv *_t2458 = &(g675); int64_t _i2458 = given_1695; (S4*)_t2458->b + hr_ix(_i2458, _t2458->n, "hc/gen.amni:358"); }))).a_)); 
if (f253_is_res(((int64_t)((f_1694).ty_)))) { (void)(f254_gxo(v_1697));
 } else { (void)(f274_gx(v_1697));
 }
 } else { int64_t sa_1698 = g382; 
g382 = g384;
(void)(f274_gx(((int64_t)((f_1694).def_))));
g382 = sa_1698;
 }
(void)(f245_ow(hr_str(", ", 2)));
any_1692 = true;
 } } _bk2452:; 
if ((!(any_1692))) { (void)(f245_ow(hr_str("0", 1)));
 }
(void)(f245_ow(hr_str("})", 2)));
}
static void f303_gcall(int64_t n_1699) {
int64_t r_1700 = f155_rk(n_1699); 
if (((r_1700) == (((int64_t)4LL)))) { (void)(f304_gbuiltin(n_1699));
return;
 }
if (((r_1700) == (((int64_t)10LL)))) { (void)(f316_gblkcall(n_1699));
return;
 }
if (((r_1700) != (((int64_t)3LL)))) { (void)(f272_gerr(n_1699, hr_str("unsupported call", 16)));
return;
 }
int64_t inst_1895 = f156_rv(n_1699); 
int64_t recv_1896 = ({ int64_t _r2459; if ((((f209_ax(n_1699)) == (((int64_t)1LL))) && ((((*({ hrv *_t2460 = &(g675); int64_t _i2460 = ((*({ hrv *_t2461 = &(g675); int64_t _i2461 = n_1699; (S4*)_t2461->b + hr_ix(_i2461, _t2461->n, "hc/gen.amni:588"); }))).a_; (S4*)_t2460->b + hr_ix(_i2460, _t2460->n, "hc/gen.amni:588"); }))).k_) == (((uint8_t)14LL))))) { _r2459 = ((int64_t)(((*({ hrv *_t2462 = &(g675); int64_t _i2462 = ((*({ hrv *_t2463 = &(g675); int64_t _i2463 = n_1699; (S4*)_t2463->b + hr_ix(_i2463, _t2463->n, "hc/gen.amni:588"); }))).a_; (S4*)_t2462->b + hr_ix(_i2462, _t2462->n, "hc/gen.amni:588"); }))).a_));  } else { _r2459 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2459; }); 
if (f336_is_ext(inst_1895)) { (void)(f337_ext_name(inst_1895));
 } else { (void)(f338_fn_cname(inst_1895));
 }
(void)(f245_ow(hr_str("(", 1)));
(void)(f339_gcall_args(n_1699, inst_1895, recv_1896));
(void)(f245_ow(hr_str(")", 1)));
}
static void f304_gbuiltin(int64_t n_1701) {
S4 x_1702 = (*({ hrv *_t2464 = &(g675); int64_t _i2464 = n_1701; (S4*)_t2464->b + hr_ix(_i2464, _t2464->n, "hc/gen.amni:621"); })); 
int64_t b_1703 = f156_rv(n_1701); 
bool hasr_1704 = ((f209_ax(n_1701)) == (((int64_t)1LL))); 
int64_t recv_1705 = ({ int64_t _r2465; if (hasr_1704) { _r2465 = ((int64_t)(((*({ hrv *_t2466 = &(g675); int64_t _i2466 = (x_1702).a_; (S4*)_t2466->b + hr_ix(_i2466, _t2466->n, "hc/gen.amni:624"); }))).a_));  } else { _r2465 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2465; }); 
int64_t total_1706 = ((int64_t)((int64_t)((int64_t)((x_1702).n_)) + (int64_t)({ int64_t _r2467; if (hasr_1704) { _r2467 = ((int64_t)1LL);  } else { _r2467 = ((int64_t)0LL);  } _r2467; }))); 

int64_t p_1708 = f278_nt(); 
if (((b_1703) == (((int64_t)1LL)))) { (void)(f245_ow(hr_str("({ ", 3)));
{ int32_t _e2469 = (x_1702).n_; for (int32_t i_1709 = 0; i_1709 < _e2469; i_1709++) { int64_t c_1710 = f90_kid(n_1701, ((int64_t)(i_1709))); 
(void)(f306_gfmt(hr_str("&hr_ob", 6), c_1710, f264_fin(c_1710), true));
(void)(f245_ow(hr_str("; ", 2)));
 } } _bk2468:; 
(void)(f245_ow(hr_str("hr_println(); })", 16)));
return;
 }
if (((b_1703) == (((int64_t)2LL)))) { (void)(f245_ow(hr_str("({ hrv _o", 9)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" = {0}; ", 8)));
L95 nmo_1717 = ({ L95 _t2470; memset(&_t2470, 0, sizeof _t2470); _t2470.n = 0; _t2470; }); 
(void)(({ L95 *_l2471 = &(nmo_1717); hrv _o2471 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2471, hr_str("&_o", 3)); hr_fi(&_o2471, p_1708); if (_l2471->n + _o2471.n > 32) hr_die("format past a limited array's capacity", "hc/gen.amni:629"); memcpy(_l2471->e + _l2471->n, _o2471.b, (size_t)_o2471.n); _l2471->n += _o2471.n; }));
{ int32_t _e2473 = (x_1702).n_; for (int32_t i_1718 = 0; i_1718 < _e2473; i_1718++) { int64_t c_1719 = f90_kid(n_1701, ((int64_t)(i_1718))); 
(void)(f306_gfmt(({ hsl _t2474 = ({ L95 *_t2475 = &(nmo_1717); (hsl){ (uint8_t*)_t2475->e, _t2475->n }; }); int64_t _l2474 = 0, _h2474 = _t2474.n; if (_l2474 < 0 || _h2474 < _l2474 || _h2474 > _t2474.n) hr_slerr(_l2474, _h2474, _t2474.n, "hc/gen.amni:629"); (hsl){ _t2474.p + _l2474 * (int64_t)sizeof(uint8_t), _h2474 - _l2474 }; }), c_1719, f264_fin(c_1719), true));
(void)(f245_ow(hr_str("; ", 2)));
 } } _bk2472:; 
(void)(f245_ow(hr_str("_o", 2)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str("; })", 4)));
return;
 }
if ((((b_1703) == (((int64_t)3LL))) && f268_is_lim(f174_deref(f140_at(f305_arg(((int64_t)0LL), &recv_1705, &n_1701)))))) { int64_t lt_1720 = f174_deref(f140_at(f305_arg(((int64_t)0LL), &recv_1705, &n_1701))); 
(void)(f245_ow(hr_str("({ ", 3)));
(void)(f246_ct(lt_1720));
(void)(f245_ow(hr_str(" *_l", 4)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f307_grecv_ptr(f305_arg(((int64_t)0LL), &recv_1705, &n_1701)));
(void)(f245_ow(hr_str("; hrv _o", 8)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" __attribute__((cleanup(hr_rdrop))) = {0}; ", 43)));
L95 nmo_1724 = ({ L95 _t2476; memset(&_t2476, 0, sizeof _t2476); _t2476.n = 0; _t2476; }); 
(void)(({ L95 *_l2477 = &(nmo_1724); hrv _o2477 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2477, hr_str("&_o", 3)); hr_fi(&_o2477, p_1708); if (_l2477->n + _o2477.n > 32) hr_die("format past a limited array's capacity", "hc/gen.amni:633"); memcpy(_l2477->e + _l2477->n, _o2477.b, (size_t)_o2477.n); _l2477->n += _o2477.n; }));
{ int64_t _e2479 = total_1706; for (int64_t i_1725 = ((int64_t)1LL); i_1725 < _e2479; i_1725++) { int64_t c_1726 = f305_arg(i_1725, &recv_1705, &n_1701); 
(void)(f306_gfmt(({ hsl _t2480 = ({ L95 *_t2481 = &(nmo_1724); (hsl){ (uint8_t*)_t2481->e, _t2481->n }; }); int64_t _l2480 = 0, _h2480 = _t2480.n; if (_l2480 < 0 || _h2480 < _l2480 || _h2480 > _t2480.n) hr_slerr(_l2480, _h2480, _t2480.n, "hc/gen.amni:634"); (hsl){ _t2480.p + _l2480 * (int64_t)sizeof(uint8_t), _h2480 - _l2480 }; }), c_1726, f264_fin(c_1726), true));
(void)(f245_ow(hr_str("; ", 2)));
 } } _bk2478:; 
(void)(({ hrv *_o2482 = &(g163); hr_fs(_o2482, hr_str("if (_l", 6)); hr_fi(_o2482, p_1708); hr_fs(_o2482, hr_str("->n + _o", 8)); hr_fi(_o2482, p_1708); hr_fs(_o2482, hr_str(".n > ", 5)); hr_fi(_o2482, ((*({ hrv *_t2483 = &(g524); int64_t _i2483 = lt_1720; (S1*)_t2483->b + hr_ix(_i2483, _t2483->n, "hc/gen.amni:635"); }))).b_); hr_fs(_o2482, hr_str(") hr_die(\"format past a limited array's capacity\", ", 51)); }));
(void)(f296_wloc(n_1701));
(void)(({ hrv *_o2484 = &(g163); hr_fs(_o2484, hr_str("); memcpy(_l", 12)); hr_fi(_o2484, p_1708); hr_fs(_o2484, hr_str("->e + _l", 8)); hr_fi(_o2484, p_1708); hr_fs(_o2484, hr_str("->n, _o", 7)); hr_fi(_o2484, p_1708); hr_fs(_o2484, hr_str(".b, (size_t)_o", 14)); hr_fi(_o2484, p_1708); hr_fs(_o2484, hr_str(".n); _l", 7)); hr_fi(_o2484, p_1708); hr_fs(_o2484, hr_str("->n += _o", 9)); hr_fi(_o2484, p_1708); hr_fs(_o2484, hr_str(".n; })", 6)); }));
return;
 }
if (((b_1703) == (((int64_t)3LL)))) { (void)(f245_ow(hr_str("({ hrv *_o", 10)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f307_grecv_ptr(f305_arg(((int64_t)0LL), &recv_1705, &n_1701)));
(void)(f245_ow(hr_str("; ", 2)));
L95 nmo_1727 = ({ L95 _t2485; memset(&_t2485, 0, sizeof _t2485); _t2485.n = 0; _t2485; }); 
(void)(({ L95 *_l2486 = &(nmo_1727); hrv _o2486 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2486, hr_str("_o", 2)); hr_fi(&_o2486, p_1708); if (_l2486->n + _o2486.n > 32) hr_die("format past a limited array's capacity", "hc/gen.amni:638"); memcpy(_l2486->e + _l2486->n, _o2486.b, (size_t)_o2486.n); _l2486->n += _o2486.n; }));
{ int64_t _e2488 = total_1706; for (int64_t i_1728 = ((int64_t)1LL); i_1728 < _e2488; i_1728++) { int64_t c_1729 = f305_arg(i_1728, &recv_1705, &n_1701); 
(void)(f306_gfmt(({ hsl _t2489 = ({ L95 *_t2490 = &(nmo_1727); (hsl){ (uint8_t*)_t2490->e, _t2490->n }; }); int64_t _l2489 = 0, _h2489 = _t2489.n; if (_l2489 < 0 || _h2489 < _l2489 || _h2489 > _t2489.n) hr_slerr(_l2489, _h2489, _t2489.n, "hc/gen.amni:638"); (hsl){ _t2489.p + _l2489 * (int64_t)sizeof(uint8_t), _h2489 - _l2489 }; }), c_1729, f264_fin(c_1729), true));
(void)(f245_ow(hr_str("; ", 2)));
 } } _bk2487:; 
(void)(f245_ow(hr_str("})", 2)));
return;
 }
if (((b_1703) == (((int64_t)4LL)))) { (void)(f245_ow(hr_str("({ if (!(", 9)));
(void)(f274_gx(f305_arg(((int64_t)0LL), &recv_1705, &n_1701)));
(void)(f245_ow(hr_str(")) hr_assert_fail(", 18)));
(void)(f296_wloc(n_1701));
(void)(f245_ow(hr_str("); })", 5)));
return;
 }
if (((b_1703) == (((int64_t)5LL)))) { (void)(f245_ow(hr_str("hr_abort(", 9)));
(void)(f276_gas(f305_arg(((int64_t)0LL), &recv_1705, &n_1701)));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if (((b_1703) == (((int64_t)6LL)))) { (void)(f245_ow(hr_str("hr_exit(", 8)));
(void)(f274_gx(f305_arg(((int64_t)0LL), &recv_1705, &n_1701)));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if (((b_1703) == (((int64_t)8LL)))) { int64_t t_1730 = f140_at(n_1701); 
(void)(f245_ow(hr_str("({ ", 3)));
(void)(f246_ct(t_1730));
(void)(f245_ow(hr_str(" _d", 3)));
(void)(f279_oi(p_1708));
(void)(({ hrv *_o2491 = &(g163); hr_fs(_o2491, hr_str("; memset(&_d", 12)); hr_fi(_o2491, p_1708); hr_fs(_o2491, hr_str(", 0, sizeof _d", 14)); hr_fi(_o2491, p_1708); hr_fs(_o2491, hr_str("); _d", 5)); hr_fi(_o2491, p_1708); hr_fs(_o2491, hr_str("; })", 4)); }));
return;
 }
if (((b_1703) == (((int64_t)9LL)))) { int64_t c_1731 = f305_arg(((int64_t)0LL), &recv_1705, &n_1701); 
int64_t t_1732 = f174_deref(f264_fin(c_1731)); 
if (f267_is_fix(t_1732)) { (void)(({ hrv *_o2492 = &(g163); hr_fs(_o2492, hr_str("((int64_t)", 10)); hr_fi(_o2492, ((*({ hrv *_t2493 = &(g524); int64_t _i2493 = t_1732; (S1*)_t2493->b + hr_ix(_i2493, _t2493->n, "hc/gen.amni:643"); }))).b_); hr_fs(_o2492, hr_str(")", 1)); }));
return;
 }
(void)(f245_ow(hr_str("(", 1)));
(void)(f276_gas(c_1731));
(void)(f245_ow(hr_str(").n", 3)));
return;
 }
if (((b_1703) == (((int64_t)7LL)))) { int64_t c_1733 = f305_arg(((int64_t)0LL), &recv_1705, &n_1701); 
int64_t t_1734 = f174_deref(f264_fin(c_1733)); 
if ((((((*({ hrv *_t2494 = &(g524); int64_t _i2494 = t_1734; (S1*)_t2494->b + hr_ix(_i2494, _t2494->n, "hc/gen.amni:644"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2495 = &(g524); int64_t _i2495 = t_1734; (S1*)_t2495->b + hr_ix(_i2495, _t2495->n, "hc/gen.amni:644"); }))).k_) == (((uint8_t)9LL))))) { (void)(f245_ow(hr_str("hr_rfrom(", 9)));
(void)(f276_gas(c_1733));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f308_esz(((int64_t)(((*({ hrv *_t2496 = &(g524); int64_t _i2496 = t_1734; (S1*)_t2496->b + hr_ix(_i2496, _t2496->n, "hc/gen.amni:644"); }))).a_))));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if (((f264_fin(c_1733)) != (t_1734))) { (void)(f245_ow(hr_str("(*", 2)));
(void)(f274_gx(c_1733));
(void)(f245_ow(hr_str(")", 1)));
 } else { (void)(f274_gx(c_1733));
 }
return;
 }
if (((b_1703) == (((int64_t)31LL)))) { int64_t c_1736 = f305_arg(((int64_t)0LL), &recv_1705, &n_1701); 
int64_t t_1737 = f174_deref(f264_fin(c_1736)); 
if ((((((*({ hrv *_t2497 = &(g524); int64_t _i2497 = t_1737; (S1*)_t2497->b + hr_ix(_i2497, _t2497->n, "hc/gen.amni:645"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2498 = &(g524); int64_t _i2498 = t_1737; (S1*)_t2498->b + hr_ix(_i2498, _t2498->n, "hc/gen.amni:645"); }))).k_) == (((uint8_t)9LL))))) { int64_t q_1738 = f278_nt(); 
(void)(f245_ow(hr_str("({ hsl _s", 9)));
(void)(f279_oi(q_1738));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f276_gas(c_1736));
(void)(({ hrv *_o2499 = &(g163); hr_fs(_o2499, hr_str("; (hsl){ _s", 11)); hr_fi(_o2499, q_1738); hr_fs(_o2499, hr_str(".p, _s", 6)); hr_fi(_o2499, q_1738); hr_fs(_o2499, hr_str(".n * (int64_t)sizeof(", 21)); }));
(void)(f246_ct(((int64_t)(((*({ hrv *_t2500 = &(g524); int64_t _i2500 = t_1737; (S1*)_t2500->b + hr_ix(_i2500, _t2500->n, "hc/gen.amni:645"); }))).a_))));
(void)(f245_ow(hr_str(") }; })", 7)));
return;
 }
(void)(f245_ow(hr_str("((hsl){ (uint8_t*)", 18)));
(void)(f309_gaddr(c_1736));
(void)(f245_ow(hr_str(", sizeof(", 9)));
(void)(f246_ct(t_1737));
(void)(f245_ow(hr_str(") })", 4)));
return;
 }
if (((b_1703) == (((int64_t)30LL)))) { int64_t c_1742 = f305_arg(((int64_t)0LL), &recv_1705, &n_1701); 
int64_t t_1743 = f174_deref(f264_fin(c_1742)); 
(void)(f245_ow(hr_str("hr_rfrom(", 9)));
if ((((((*({ hrv *_t2501 = &(g524); int64_t _i2501 = t_1743; (S1*)_t2501->b + hr_ix(_i2501, _t2501->n, "hc/gen.amni:646"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2502 = &(g524); int64_t _i2502 = t_1743; (S1*)_t2502->b + hr_ix(_i2502, _t2502->n, "hc/gen.amni:646"); }))).k_) == (((uint8_t)9LL))))) { int64_t q_1744 = f278_nt(); 
(void)(f245_ow(hr_str("({ hsl _s", 9)));
(void)(f279_oi(q_1744));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f276_gas(c_1742));
(void)(({ hrv *_o2503 = &(g163); hr_fs(_o2503, hr_str("; (hsl){ _s", 11)); hr_fi(_o2503, q_1744); hr_fs(_o2503, hr_str(".p, _s", 6)); hr_fi(_o2503, q_1744); hr_fs(_o2503, hr_str(".n * (int64_t)sizeof(", 21)); }));
(void)(f246_ct(((int64_t)(((*({ hrv *_t2504 = &(g524); int64_t _i2504 = t_1743; (S1*)_t2504->b + hr_ix(_i2504, _t2504->n, "hc/gen.amni:646"); }))).a_))));
(void)(f245_ow(hr_str(") }; })", 7)));
 } else { (void)(f245_ow(hr_str("((hsl){ (uint8_t*)", 18)));
(void)(f309_gaddr(c_1742));
(void)(f245_ow(hr_str(", sizeof(", 9)));
(void)(f246_ct(t_1743));
(void)(f245_ow(hr_str(") })", 4)));
 }
(void)(f245_ow(hr_str(", 1)", 4)));
return;
 }
if (((b_1703) == (((int64_t)32LL)))) { int64_t t_1745 = f140_at(n_1701); 
(void)(f245_ow(hr_str("({ hsl _s", 9)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f276_gas(f305_arg(((int64_t)0LL), &recv_1705, &n_1701)));
(void)(f245_ow(hr_str("; ", 2)));
(void)(f246_ct(t_1745));
(void)(({ hrv *_o2505 = &(g163); hr_fs(_o2505, hr_str(" _d", 3)); hr_fi(_o2505, p_1708); hr_fs(_o2505, hr_str("; if (_s", 8)); hr_fi(_o2505, p_1708); hr_fs(_o2505, hr_str(".n != sizeof _d", 15)); hr_fi(_o2505, p_1708); hr_fs(_o2505, hr_str(") hr_die(\"from_bytes: wrong byte count\", ", 41)); }));
(void)(f296_wloc(n_1701));
(void)(({ hrv *_o2506 = &(g163); hr_fs(_o2506, hr_str("); memcpy(&_d", 13)); hr_fi(_o2506, p_1708); hr_fs(_o2506, hr_str(", _s", 4)); hr_fi(_o2506, p_1708); hr_fs(_o2506, hr_str(".p, sizeof _d", 13)); hr_fi(_o2506, p_1708); hr_fs(_o2506, hr_str("); _d", 5)); hr_fi(_o2506, p_1708); hr_fs(_o2506, hr_str("; })", 4)); }));
return;
 }
int64_t rt_1746 = f174_deref(f140_at(recv_1705)); 
int64_t e_1747 = ((int64_t)(((*({ hrv *_t2507 = &(g524); int64_t _i2507 = rt_1746; (S1*)_t2507->b + hr_ix(_i2507, _t2507->n, "hc/gen.amni:649"); }))).a_)); 
if (f268_is_lim(rt_1746)) { (void)(f245_ow(hr_str("({ ", 3)));
(void)(f246_ct(rt_1746));
(void)(f245_ow(hr_str(" *_v", 4)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f307_grecv_ptr(recv_1705));
(void)(f245_ow(hr_str("; ", 2)));
if (((b_1703) == (((int64_t)20LL)))) { (void)(f246_ct(e_1747));
(void)(f245_ow(hr_str(" _x", 3)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(f305_arg(((int64_t)1LL), &recv_1705, &n_1701)));
(void)(({ hrv *_o2508 = &(g163); hr_fs(_o2508, hr_str("; if (_v", 8)); hr_fi(_o2508, p_1708); hr_fs(_o2508, hr_str("->n >= ", 7)); hr_fi(_o2508, ((*({ hrv *_t2509 = &(g524); int64_t _i2509 = rt_1746; (S1*)_t2509->b + hr_ix(_i2509, _t2509->n, "hc/gen.amni:652"); }))).b_); hr_fs(_o2508, hr_str(") hr_die(\"push past a limited array's capacity\", ", 49)); }));
(void)(f296_wloc(n_1701));
(void)(({ hrv *_o2510 = &(g163); hr_fs(_o2510, hr_str("); _v", 5)); hr_fi(_o2510, p_1708); hr_fs(_o2510, hr_str("->e[_v", 6)); hr_fi(_o2510, p_1708); hr_fs(_o2510, hr_str("->n] = _x", 9)); hr_fi(_o2510, p_1708); hr_fs(_o2510, hr_str("; &_v", 5)); hr_fi(_o2510, p_1708); hr_fs(_o2510, hr_str("->e[_v", 6)); hr_fi(_o2510, p_1708); hr_fs(_o2510, hr_str("->n++]; })", 10)); }));
return;
 }
if (((b_1703) == (((int64_t)21LL)))) { (void)(({ hrv *_o2511 = &(g163); hr_fs(_o2511, hr_str("hsl _s", 6)); hr_fi(_o2511, p_1708); hr_fs(_o2511, hr_str(" = ", 3)); }));
(void)(f276_gas(f305_arg(((int64_t)1LL), &recv_1705, &n_1701)));
(void)(({ hrv *_o2512 = &(g163); hr_fs(_o2512, hr_str("; if (_v", 8)); hr_fi(_o2512, p_1708); hr_fs(_o2512, hr_str("->n + _s", 8)); hr_fi(_o2512, p_1708); hr_fs(_o2512, hr_str(".n > ", 5)); hr_fi(_o2512, ((*({ hrv *_t2513 = &(g524); int64_t _i2513 = rt_1746; (S1*)_t2513->b + hr_ix(_i2513, _t2513->n, "hc/gen.amni:653"); }))).b_); hr_fs(_o2512, hr_str(") hr_die(\"append past a limited array's capacity\", ", 51)); }));
(void)(f296_wloc(n_1701));
(void)(({ hrv *_o2514 = &(g163); hr_fs(_o2514, hr_str("); memmove(_v", 13)); hr_fi(_o2514, p_1708); hr_fs(_o2514, hr_str("->e + _v", 8)); hr_fi(_o2514, p_1708); hr_fs(_o2514, hr_str("->n, _s", 7)); hr_fi(_o2514, p_1708); hr_fs(_o2514, hr_str(".p, (size_t)_s", 14)); hr_fi(_o2514, p_1708); hr_fs(_o2514, hr_str(".n * sizeof _v", 14)); hr_fi(_o2514, p_1708); hr_fs(_o2514, hr_str("->e[0]); _v", 11)); hr_fi(_o2514, p_1708); hr_fs(_o2514, hr_str("->n += _s", 9)); hr_fi(_o2514, p_1708); hr_fs(_o2514, hr_str(".n; })", 6)); }));
return;
 }
if (((b_1703) == (((int64_t)22LL)))) { (void)(({ hrv *_o2515 = &(g163); hr_fs(_o2515, hr_str("if (!_v", 7)); hr_fi(_o2515, p_1708); hr_fs(_o2515, hr_str("->n) hr_die(\"pop of an empty array\", ", 37)); }));
(void)(f296_wloc(n_1701));
(void)(({ hrv *_o2516 = &(g163); hr_fs(_o2516, hr_str("); _v", 5)); hr_fi(_o2516, p_1708); hr_fs(_o2516, hr_str("->e[--_v", 8)); hr_fi(_o2516, p_1708); hr_fs(_o2516, hr_str("->n]; })", 8)); }));
return;
 }
if (((b_1703) == (((int64_t)23LL)))) { (void)(({ hrv *_o2517 = &(g163); hr_fs(_o2517, hr_str("int64_t _k", 10)); hr_fi(_o2517, p_1708); hr_fs(_o2517, hr_str(" = ", 3)); }));
(void)(f274_gx(f305_arg(((int64_t)1LL), &recv_1705, &n_1701)));
(void)(({ hrv *_o2518 = &(g163); hr_fs(_o2518, hr_str("; if (_k", 8)); hr_fi(_o2518, p_1708); hr_fs(_o2518, hr_str(" < 0 || _k", 10)); hr_fi(_o2518, p_1708); hr_fs(_o2518, hr_str(" > _v", 5)); hr_fi(_o2518, p_1708); hr_fs(_o2518, hr_str("->n) hr_die(\"pop_n past the length\", ", 37)); }));
(void)(f296_wloc(n_1701));
(void)(({ hrv *_o2519 = &(g163); hr_fs(_o2519, hr_str("); _v", 5)); hr_fi(_o2519, p_1708); hr_fs(_o2519, hr_str("->n -= _k", 9)); hr_fi(_o2519, p_1708); hr_fs(_o2519, hr_str("; })", 4)); }));
return;
 }
if (((b_1703) == (((int64_t)25LL)))) { (void)(({ hrv *_o2520 = &(g163); hr_fs(_o2520, hr_str("_v", 2)); hr_fi(_o2520, p_1708); hr_fs(_o2520, hr_str("->n = 0; })", 11)); }));
return;
 }
if (((b_1703) == (((int64_t)24LL)))) { (void)(({ hrv *_o2521 = &(g163); hr_fs(_o2521, hr_str("int64_t _k", 10)); hr_fi(_o2521, p_1708); hr_fs(_o2521, hr_str(" = ", 3)); }));
(void)(f274_gx(f305_arg(((int64_t)1LL), &recv_1705, &n_1701)));
(void)(({ hrv *_o2522 = &(g163); hr_fs(_o2522, hr_str("; if (_k", 8)); hr_fi(_o2522, p_1708); hr_fs(_o2522, hr_str(" < 0 || _k", 10)); hr_fi(_o2522, p_1708); hr_fs(_o2522, hr_str(" > ", 3)); hr_fi(_o2522, ((*({ hrv *_t2523 = &(g524); int64_t _i2523 = rt_1746; (S1*)_t2523->b + hr_ix(_i2523, _t2523->n, "hc/gen.amni:657"); }))).b_); hr_fs(_o2522, hr_str(") hr_die(\"resize past a limited array's capacity\", ", 51)); }));
(void)(f296_wloc(n_1701));
(void)(({ hrv *_o2524 = &(g163); hr_fs(_o2524, hr_str("); for (int64_t _j = _v", 23)); hr_fi(_o2524, p_1708); hr_fs(_o2524, hr_str("->n; _j < _k", 12)); hr_fi(_o2524, p_1708); hr_fs(_o2524, hr_str("; _j++) memset(&_v", 18)); hr_fi(_o2524, p_1708); hr_fs(_o2524, hr_str("->e[_j], 0, sizeof _v", 21)); hr_fi(_o2524, p_1708); hr_fs(_o2524, hr_str("->e[0]); ", 9)); }));
if (((total_1706) > (((int64_t)2LL)))) { (void)(({ hrv *_o2525 = &(g163); hr_fs(_o2525, hr_str("for (int64_t _j = _v", 20)); hr_fi(_o2525, p_1708); hr_fs(_o2525, hr_str("->n; _j < _k", 12)); hr_fi(_o2525, p_1708); hr_fs(_o2525, hr_str("; _j++) _v", 10)); hr_fi(_o2525, p_1708); hr_fs(_o2525, hr_str("->e[_j] = ", 10)); }));
(void)(f274_gx(f305_arg(((int64_t)2LL), &recv_1705, &n_1701)));
(void)(f245_ow(hr_str("; ", 2)));
 }
(void)(({ hrv *_o2526 = &(g163); hr_fs(_o2526, hr_str("_v", 2)); hr_fi(_o2526, p_1708); hr_fs(_o2526, hr_str("->n = _k", 8)); hr_fi(_o2526, p_1708); hr_fs(_o2526, hr_str("; })", 4)); }));
return;
 }
if (((b_1703) == (((int64_t)26LL)))) { (void)(f246_ct(e_1747));
(void)(f245_ow(hr_str(" _x", 3)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(f305_arg(((int64_t)1LL), &recv_1705, &n_1701)));
(void)(({ hrv *_o2527 = &(g163); hr_fs(_o2527, hr_str("; int64_t _r", 12)); hr_fi(_o2527, p_1708); hr_fs(_o2527, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o2527, p_1708); hr_fs(_o2527, hr_str("->n; _j++) if (", 15)); }));
(void)(f310_heq_val_o(e_1747, p_1708));
(void)(({ hrv *_o2528 = &(g163); hr_fs(_o2528, hr_str(") { _r", 6)); hr_fi(_o2528, p_1708); hr_fs(_o2528, hr_str(" = _j; break; } _r", 18)); hr_fi(_o2528, p_1708); hr_fs(_o2528, hr_str("; })", 4)); }));
return;
 }
(void)(f272_gerr(n_1701, hr_str("unsupported limited-array operation", 35)));
return;
 }
if ((((((*({ hrv *_t2529 = &(g524); int64_t _i2529 = rt_1746; (S1*)_t2529->b + hr_ix(_i2529, _t2529->n, "hc/gen.amni:661"); }))).k_) == (((uint8_t)9LL))) || f267_is_fix(rt_1746))) { if (((b_1703) == (((int64_t)26LL)))) { (void)(f245_ow(hr_str("({ hsl _v", 9)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f276_gas(recv_1705));
(void)(f245_ow(hr_str("; ", 2)));
(void)(f246_ct(e_1747));
(void)(f245_ow(hr_str(" _x", 3)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(f305_arg(((int64_t)1LL), &recv_1705, &n_1701)));
(void)(({ hrv *_o2530 = &(g163); hr_fs(_o2530, hr_str("; int64_t _r", 12)); hr_fi(_o2530, p_1708); hr_fs(_o2530, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o2530, p_1708); hr_fs(_o2530, hr_str(".n; _j++) if (", 14)); }));
(void)(f314_heq_val_s(e_1747, p_1708));
(void)(({ hrv *_o2531 = &(g163); hr_fs(_o2531, hr_str(") { _r", 6)); hr_fi(_o2531, p_1708); hr_fs(_o2531, hr_str(" = _j; break; } _r", 18)); hr_fi(_o2531, p_1708); hr_fs(_o2531, hr_str("; })", 4)); }));
return;
 }
(void)(f272_gerr(n_1701, hr_str("this operation needs a resizable array", 38)));
return;
 }
(void)(f245_ow(hr_str("({ hrv *_v", 10)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f307_grecv_ptr(recv_1705));
(void)(f245_ow(hr_str("; ", 2)));
if (((b_1703) == (((int64_t)20LL)))) { (void)(f246_ct(e_1747));
(void)(f245_ow(hr_str(" _x", 3)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(f305_arg(((int64_t)1LL), &recv_1705, &n_1701)));
(void)(f245_ow(hr_str("; ", 2)));
(void)(f246_ct(e_1747));
(void)(f245_ow(hr_str(" *_p", 4)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" = (", 4)));
(void)(f246_ct(e_1747));
(void)(({ hrv *_o2532 = &(g163); hr_fs(_o2532, hr_str("*)hr_grow(_v", 12)); hr_fi(_o2532, p_1708); hr_fs(_o2532, hr_str(", 1, sizeof _x", 14)); hr_fi(_o2532, p_1708); hr_fs(_o2532, hr_str("); *_p", 6)); hr_fi(_o2532, p_1708); hr_fs(_o2532, hr_str(" = _x", 5)); hr_fi(_o2532, p_1708); hr_fs(_o2532, hr_str("; _p", 4)); hr_fi(_o2532, p_1708); hr_fs(_o2532, hr_str("; })", 4)); }));
return;
 }
if (((b_1703) == (((int64_t)21LL)))) { (void)(({ hrv *_o2533 = &(g163); hr_fs(_o2533, hr_str("hsl _s", 6)); hr_fi(_o2533, p_1708); hr_fs(_o2533, hr_str(" = ", 3)); }));
(void)(f276_gas(f305_arg(((int64_t)1LL), &recv_1705, &n_1701)));
(void)(({ hrv *_o2534 = &(g163); hr_fs(_o2534, hr_str("; hr_append(_v", 14)); hr_fi(_o2534, p_1708); hr_fs(_o2534, hr_str(", _s", 4)); hr_fi(_o2534, p_1708); hr_fs(_o2534, hr_str(".p, _s", 6)); hr_fi(_o2534, p_1708); hr_fs(_o2534, hr_str(".n, sizeof(", 11)); }));
(void)(f246_ct(e_1747));
(void)(f245_ow(hr_str(")); })", 6)));
return;
 }
if (((b_1703) == (((int64_t)22LL)))) { (void)(({ hrv *_o2535 = &(g163); hr_fs(_o2535, hr_str("if (!_v", 7)); hr_fi(_o2535, p_1708); hr_fs(_o2535, hr_str("->n) hr_die(\"pop of an empty array\", ", 37)); }));
(void)(f296_wloc(n_1701));
(void)(({ hrv *_o2536 = &(g163); hr_fs(_o2536, hr_str("); ((", 5)); }));
(void)(f246_ct(e_1747));
(void)(({ hrv *_o2537 = &(g163); hr_fs(_o2537, hr_str("*)_v", 4)); hr_fi(_o2537, p_1708); hr_fs(_o2537, hr_str("->b)[--_v", 9)); hr_fi(_o2537, p_1708); hr_fs(_o2537, hr_str("->n]; })", 8)); }));
return;
 }
if (((b_1703) == (((int64_t)23LL)))) { (void)(({ hrv *_o2538 = &(g163); hr_fs(_o2538, hr_str("int64_t _k", 10)); hr_fi(_o2538, p_1708); hr_fs(_o2538, hr_str(" = ", 3)); }));
(void)(f274_gx(f305_arg(((int64_t)1LL), &recv_1705, &n_1701)));
(void)(({ hrv *_o2539 = &(g163); hr_fs(_o2539, hr_str("; if (_k", 8)); hr_fi(_o2539, p_1708); hr_fs(_o2539, hr_str(" < 0 || _k", 10)); hr_fi(_o2539, p_1708); hr_fs(_o2539, hr_str(" > _v", 5)); hr_fi(_o2539, p_1708); hr_fs(_o2539, hr_str("->n) hr_die(\"pop_n past the length\", ", 37)); }));
(void)(f296_wloc(n_1701));
(void)(({ hrv *_o2540 = &(g163); hr_fs(_o2540, hr_str("); _v", 5)); hr_fi(_o2540, p_1708); hr_fs(_o2540, hr_str("->n -= _k", 9)); hr_fi(_o2540, p_1708); hr_fs(_o2540, hr_str("; })", 4)); }));
return;
 }
if (((b_1703) == (((int64_t)25LL)))) { (void)(({ hrv *_o2541 = &(g163); hr_fs(_o2541, hr_str("_v", 2)); hr_fi(_o2541, p_1708); hr_fs(_o2541, hr_str("->n = 0; })", 11)); }));
return;
 }
if (((b_1703) == (((int64_t)24LL)))) { (void)(({ hrv *_o2542 = &(g163); hr_fs(_o2542, hr_str("int64_t _k", 10)); hr_fi(_o2542, p_1708); hr_fs(_o2542, hr_str(" = ", 3)); }));
(void)(f274_gx(f305_arg(((int64_t)1LL), &recv_1705, &n_1701)));
(void)(({ hrv *_o2543 = &(g163); hr_fs(_o2543, hr_str("; if (_k", 8)); hr_fi(_o2543, p_1708); hr_fs(_o2543, hr_str(" < 0) hr_die(\"resize to a negative length\", ", 44)); }));
(void)(f296_wloc(n_1701));
(void)(f245_ow(hr_str("); ", 3)));
if (((total_1706) > (((int64_t)2LL)))) { (void)(f246_ct(e_1747));
(void)(f245_ow(hr_str(" _x", 3)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(f305_arg(((int64_t)2LL), &recv_1705, &n_1701)));
(void)(({ hrv *_o2544 = &(g163); hr_fs(_o2544, hr_str("; int64_t _o", 12)); hr_fi(_o2544, p_1708); hr_fs(_o2544, hr_str(" = _v", 5)); hr_fi(_o2544, p_1708); hr_fs(_o2544, hr_str("->n; hr_resize(_v", 17)); hr_fi(_o2544, p_1708); hr_fs(_o2544, hr_str(", _k", 4)); hr_fi(_o2544, p_1708); hr_fs(_o2544, hr_str(", sizeof _x", 11)); hr_fi(_o2544, p_1708); hr_fs(_o2544, hr_str("); for (int64_t _j = _o", 23)); hr_fi(_o2544, p_1708); hr_fs(_o2544, hr_str("; _j < _k", 9)); hr_fi(_o2544, p_1708); hr_fs(_o2544, hr_str("; _j++) ((", 10)); }));
(void)(f246_ct(e_1747));
(void)(({ hrv *_o2545 = &(g163); hr_fs(_o2545, hr_str("*)_v", 4)); hr_fi(_o2545, p_1708); hr_fs(_o2545, hr_str("->b)[_j] = _x", 13)); hr_fi(_o2545, p_1708); hr_fs(_o2545, hr_str("; })", 4)); }));
return;
 }
(void)(({ hrv *_o2546 = &(g163); hr_fs(_o2546, hr_str("hr_resize(_v", 12)); hr_fi(_o2546, p_1708); hr_fs(_o2546, hr_str(", _k", 4)); hr_fi(_o2546, p_1708); hr_fs(_o2546, hr_str(", sizeof(", 9)); }));
(void)(f246_ct(e_1747));
(void)(f245_ow(hr_str(")); })", 6)));
return;
 }
if (((b_1703) == (((int64_t)26LL)))) { (void)(f246_ct(e_1747));
(void)(f245_ow(hr_str(" _x", 3)));
(void)(f279_oi(p_1708));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(f305_arg(((int64_t)1LL), &recv_1705, &n_1701)));
(void)(({ hrv *_o2547 = &(g163); hr_fs(_o2547, hr_str("; int64_t _r", 12)); hr_fi(_o2547, p_1708); hr_fs(_o2547, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o2547, p_1708); hr_fs(_o2547, hr_str("->n; _j++) if (", 15)); }));
(void)(f315_heq_val_r(e_1747, p_1708));
(void)(({ hrv *_o2548 = &(g163); hr_fs(_o2548, hr_str(") { _r", 6)); hr_fi(_o2548, p_1708); hr_fs(_o2548, hr_str(" = _j; break; } _r", 18)); hr_fi(_o2548, p_1708); hr_fs(_o2548, hr_str("; })", 4)); }));
return;
 }
(void)(f272_gerr(n_1701, hr_str("unsupported array operation", 27)));
}
static int64_t f305_arg(int64_t i_1707, int64_t *c1705, int64_t *c1701) {
return ({ int64_t _r2549; if ((((*c1705)) >= (((int64_t)0LL)))) { _r2549 = ({ int64_t _r2550; if (((i_1707) == (((int64_t)0LL)))) { _r2550 = (*c1705);  } else { _r2550 = f90_kid((*c1701), ((int64_t)((int64_t)i_1707 - (int64_t)((int64_t)1LL))));  } _r2550; });  } else { _r2549 = f90_kid((*c1701), i_1707);  } _r2549; });
}
static void f306_gfmt(hsl o_1711, int64_t n_1712, int64_t t_1713, bool top_1714) {
int64_t d_1715 = f174_deref(t_1713); 
int64_t k_1716 = ((int64_t)(((*({ hrv *_t2551 = &(g524); int64_t _i2551 = d_1715; (S1*)_t2551->b + hr_ix(_i2551, _t2551->n, "hc/gen.amni:367"); }))).k_)); 
if ((((k_1716) == (((int64_t)18LL))) || f163_is_byte_arr(d_1715))) { if (top_1714) { (void)(f245_ow(hr_str("hr_fs(", 6)));
 } else { (void)(f245_ow(hr_str("hr_fq(", 6)));
 }
(void)(f245_ow(o_1711));
(void)(f245_ow(hr_str(", ", 2)));
if (((((*({ hrv *_t2552 = &(g524); int64_t _i2552 = f140_at(n_1712); (S1*)_t2552->b + hr_ix(_i2552, _t2552->n, "hc/gen.amni:368"); }))).k_) == (((uint8_t)18LL)))) { (void)(f274_gx(n_1712));
 } else { (void)(f276_gas(n_1712));
 }
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if (((k_1716) == (((int64_t)3LL)))) { (void)(f245_ow(({ hsl _r2553; if (f151_is_signed(d_1715)) { _r2553 = hr_str("hr_fi(", 6);  } else { _r2553 = hr_str("hr_fu(", 6);  } _r2553; })));
(void)(f245_ow(o_1711));
(void)(f245_ow(hr_str(", ", 2)));
if (((d_1715) != (t_1713))) { (void)(f245_ow(hr_str("*", 1)));
 }
(void)(f274_gx(n_1712));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if (((k_1716) == (((int64_t)12LL)))) { (void)(f245_ow(hr_str("hr_fi(", 6)));
(void)(f245_ow(o_1711));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f274_gx(n_1712));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if (((k_1716) == (((int64_t)4LL)))) { (void)(f245_ow(({ hsl _r2554; if (((((*({ hrv *_t2555 = &(g524); int64_t _i2555 = d_1715; (S1*)_t2555->b + hr_ix(_i2555, _t2555->n, "hc/gen.amni:371"); }))).s_) == (((uint8_t)4LL)))) { _r2554 = hr_str("hr_ff(", 6);  } else { _r2554 = hr_str("hr_fd(", 6);  } _r2554; })));
(void)(f245_ow(o_1711));
(void)(f245_ow(hr_str(", ", 2)));
if (((d_1715) != (t_1713))) { (void)(f245_ow(hr_str("*", 1)));
 }
(void)(f274_gx(n_1712));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if (((k_1716) == (((int64_t)13LL)))) { (void)(f245_ow(hr_str("hr_fd(", 6)));
(void)(f245_ow(o_1711));
(void)(f245_ow(hr_str(", ", 2)));
(void)(f274_gx(n_1712));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
if (((k_1716) == (((int64_t)2LL)))) { (void)(f245_ow(hr_str("hr_fc(", 6)));
(void)(f245_ow(o_1711));
(void)(f245_ow(hr_str(", (", 3)));
if (((d_1715) != (t_1713))) { (void)(f245_ow(hr_str("*", 1)));
 }
(void)(f274_gx(n_1712));
(void)(f245_ow(hr_str(") \077 \"true\" : \"false\")", 21)));
return;
 }
(void)(f245_ow(hr_str("hf", 2)));
(void)(f279_oi(d_1715));
(void)(f245_ow(hr_str("(", 1)));
(void)(f245_ow(o_1711));
(void)(f245_ow(hr_str(", ", 2)));
if (((d_1715) != (t_1713))) { (void)(f245_ow(hr_str("*", 1)));
 }
if ((((((k_1716) == (((int64_t)8LL))) && (!(f267_is_fix(d_1715)))) && (!(f268_is_lim(d_1715)))) || ((k_1716) == (((int64_t)9LL))))) { (void)(f277_gsl(n_1712, t_1713));
 } else { (void)(f274_gx(n_1712));
 }
(void)(f245_ow(hr_str(")", 1)));
(void)(f284_gen_hf(d_1715));
}
static void f307_grecv_ptr(int64_t r_1721) {
int64_t t_1722 = f140_at(r_1721); 
if (((((*({ hrv *_t2556 = &(g524); int64_t _i2556 = t_1722; (S1*)_t2556->b + hr_ix(_i2556, _t2556->n, "hc/gen.amni:616"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_gx0(r_1721));
return;
 }
if (f257_is_place(r_1721)) { (void)(f245_ow(hr_str("&(", 2)));
(void)(f260_gx0(r_1721));
(void)(f245_ow(hr_str(")", 1)));
return;
 }
int64_t k_1723 = f258_tmp(t_1722, f253_is_res(t_1722)); 
(void)(f245_ow(hr_str("&(", 2)));
(void)(f259_ot(k_1723));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f254_gxo(r_1721));
(void)(f245_ow(hr_str(")", 1)));
}
static void f308_esz(int64_t t_1735) {
(void)(f245_ow(hr_str("sizeof(", 7)));
(void)(f246_ct(t_1735));
(void)(f245_ow(hr_str(")", 1)));
}
static void f309_gaddr(int64_t n_1739) {
if (f257_is_place(n_1739)) { (void)(f245_ow(hr_str("(&(", 3)));
(void)(f260_gx0(n_1739));
(void)(f245_ow(hr_str("))", 2)));
return;
 }
int64_t t_1740 = f140_at(n_1739); 
int64_t k_1741 = f258_tmp(t_1740, f253_is_res(t_1740)); 
(void)(f245_ow(hr_str("(&(", 3)));
(void)(f259_ot(k_1741));
(void)(f245_ow(hr_str(" = (", 4)));
(void)(f254_gxo(n_1739));
(void)(f245_ow(hr_str(")))", 3)));
}
static void f310_heq_val_o(int64_t e_1748, int64_t p_1749) {
L96 a_1750 = ({ L96 _t2557; memset(&_t2557, 0, sizeof _t2557); _t2557.n = 0; _t2557; }); 
L96 b_1751 = ({ L96 _t2558; memset(&_t2558, 0, sizeof _t2558); _t2558.n = 0; _t2558; }); 
(void)(({ L96 *_l2559 = &(a_1750); hrv _o2559 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2559, hr_str("_v", 2)); hr_fi(&_o2559, p_1749); hr_fs(&_o2559, hr_str("->e[_j]", 7)); if (_l2559->n + _o2559.n > 64) hr_die("format past a limited array's capacity", "hc/gen.amni:682"); memcpy(_l2559->e + _l2559->n, _o2559.b, (size_t)_o2559.n); _l2559->n += _o2559.n; }));
(void)(({ L96 *_l2560 = &(b_1751); hrv _o2560 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2560, hr_str("_x", 2)); hr_fi(&_o2560, p_1749); if (_l2560->n + _o2560.n > 64) hr_die("format past a limited array's capacity", "hc/gen.amni:682"); memcpy(_l2560->e + _l2560->n, _o2560.b, (size_t)_o2560.n); _l2560->n += _o2560.n; }));
(void)(f311_heq_o(e_1748, ({ hsl _t2561 = ({ L96 *_t2562 = &(a_1750); (hsl){ (uint8_t*)_t2562->e, _t2562->n }; }); int64_t _l2561 = 0, _h2561 = _t2561.n; if (_l2561 < 0 || _h2561 < _l2561 || _h2561 > _t2561.n) hr_slerr(_l2561, _h2561, _t2561.n, "hc/gen.amni:682"); (hsl){ _t2561.p + _l2561 * (int64_t)sizeof(uint8_t), _h2561 - _l2561 }; }), ({ hsl _t2563 = ({ L96 *_t2564 = &(b_1751); (hsl){ (uint8_t*)_t2564->e, _t2564->n }; }); int64_t _l2563 = 0, _h2563 = _t2563.n; if (_l2563 < 0 || _h2563 < _l2563 || _h2563 > _t2563.n) hr_slerr(_l2563, _h2563, _t2563.n, "hc/gen.amni:682"); (hsl){ _t2563.p + _l2563 * (int64_t)sizeof(uint8_t), _h2563 - _l2563 }; })));
}
static void f311_heq_o(int64_t e_1752, hsl a_1753, hsl b_1754) {
(void)(f312_heq_pre(e_1752));
int64_t s0_1758 = (g169).n; 
(void)(f288_heq_val(e_1752, a_1753, b_1754));
(void)(({ hrv *_v2565 = &(g163); hsl _s2565 = ({ hsl _t2566 = hr_sl(g169); int64_t _l2566 = s0_1758, _h2566 = _t2566.n; if (_l2566 < 0 || _h2566 < _l2566 || _h2566 > _t2566.n) hr_slerr(_l2566, _h2566, _t2566.n, "hc/gen.amni:679"); (hsl){ _t2566.p + _l2566 * (int64_t)sizeof(uint8_t), _h2566 - _l2566 }; }); hr_append(_v2565, _s2565.p, _s2565.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2567 = &(g169); int64_t _k2567 = s0_1758; if (_k2567 < 0) hr_die("resize to a negative length", "hc/gen.amni:679"); hr_resize(_v2567, _k2567, sizeof(uint8_t)); }));
}
static void f312_heq_pre(int64_t t_1755) {
if ((!(f313_scalar_ty(t_1755)))) { (void)(f280_gen_heq(t_1755));
 }
}
static bool f313_scalar_ty(int64_t t_1756) {
int64_t k_1757 = ((int64_t)(((*({ hrv *_t2568 = &(g524); int64_t _i2568 = t_1756; (S1*)_t2568->b + hr_ix(_i2568, _t2568->n, "hc/gen.amni:680"); }))).k_)); 
return (((((k_1757) == (((int64_t)3LL))) || ((k_1757) == (((int64_t)4LL)))) || ((k_1757) == (((int64_t)2LL)))) || ((k_1757) == (((int64_t)10LL))));
}
static void f314_heq_val_s(int64_t e_1759, int64_t p_1760) {
L94 a_1761 = ({ L94 _t2569; memset(&_t2569, 0, sizeof _t2569); _t2569.n = 0; _t2569; }); 
L96 b_1762 = ({ L96 _t2570; memset(&_t2570, 0, sizeof _t2570); _t2570.n = 0; _t2570; }); 
(void)(({ L94 *_v2571 = &(a_1761); hsl _s2571 = hr_str("((", 2); if (_v2571->n + _s2571.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:683"); memmove(_v2571->e + _v2571->n, _s2571.p, (size_t)_s2571.n * sizeof _v2571->e[0]); _v2571->n += _s2571.n; }));
(void)(({ L94 *_v2572 = &(a_1761); hsl _s2572 = f249_cn(e_1759); if (_v2572->n + _s2572.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:683"); memmove(_v2572->e + _v2572->n, _s2572.p, (size_t)_s2572.n * sizeof _v2572->e[0]); _v2572->n += _s2572.n; }));
(void)(({ L94 *_l2573 = &(a_1761); hrv _o2573 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2573, hr_str("*)_v", 4)); hr_fi(&_o2573, p_1760); hr_fs(&_o2573, hr_str(".p)[_j]", 7)); if (_l2573->n + _o2573.n > 128) hr_die("format past a limited array's capacity", "hc/gen.amni:683"); memcpy(_l2573->e + _l2573->n, _o2573.b, (size_t)_o2573.n); _l2573->n += _o2573.n; }));
(void)(({ L96 *_l2574 = &(b_1762); hrv _o2574 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2574, hr_str("_x", 2)); hr_fi(&_o2574, p_1760); if (_l2574->n + _o2574.n > 64) hr_die("format past a limited array's capacity", "hc/gen.amni:683"); memcpy(_l2574->e + _l2574->n, _o2574.b, (size_t)_o2574.n); _l2574->n += _o2574.n; }));
(void)(f311_heq_o(e_1759, ({ hsl _t2575 = ({ L94 *_t2576 = &(a_1761); (hsl){ (uint8_t*)_t2576->e, _t2576->n }; }); int64_t _l2575 = 0, _h2575 = _t2575.n; if (_l2575 < 0 || _h2575 < _l2575 || _h2575 > _t2575.n) hr_slerr(_l2575, _h2575, _t2575.n, "hc/gen.amni:683"); (hsl){ _t2575.p + _l2575 * (int64_t)sizeof(uint8_t), _h2575 - _l2575 }; }), ({ hsl _t2577 = ({ L96 *_t2578 = &(b_1762); (hsl){ (uint8_t*)_t2578->e, _t2578->n }; }); int64_t _l2577 = 0, _h2577 = _t2577.n; if (_l2577 < 0 || _h2577 < _l2577 || _h2577 > _t2577.n) hr_slerr(_l2577, _h2577, _t2577.n, "hc/gen.amni:683"); (hsl){ _t2577.p + _l2577 * (int64_t)sizeof(uint8_t), _h2577 - _l2577 }; })));
}
static void f315_heq_val_r(int64_t e_1763, int64_t p_1764) {
L94 a_1765 = ({ L94 _t2579; memset(&_t2579, 0, sizeof _t2579); _t2579.n = 0; _t2579; }); 
L96 b_1766 = ({ L96 _t2580; memset(&_t2580, 0, sizeof _t2580); _t2580.n = 0; _t2580; }); 
(void)(({ L94 *_v2581 = &(a_1765); hsl _s2581 = hr_str("((", 2); if (_v2581->n + _s2581.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:684"); memmove(_v2581->e + _v2581->n, _s2581.p, (size_t)_s2581.n * sizeof _v2581->e[0]); _v2581->n += _s2581.n; }));
(void)(({ L94 *_v2582 = &(a_1765); hsl _s2582 = f249_cn(e_1763); if (_v2582->n + _s2582.n > 128) hr_die("append past a limited array's capacity", "hc/gen.amni:684"); memmove(_v2582->e + _v2582->n, _s2582.p, (size_t)_s2582.n * sizeof _v2582->e[0]); _v2582->n += _s2582.n; }));
(void)(({ L94 *_l2583 = &(a_1765); hrv _o2583 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2583, hr_str("*)_v", 4)); hr_fi(&_o2583, p_1764); hr_fs(&_o2583, hr_str("->b)[_j]", 8)); if (_l2583->n + _o2583.n > 128) hr_die("format past a limited array's capacity", "hc/gen.amni:684"); memcpy(_l2583->e + _l2583->n, _o2583.b, (size_t)_o2583.n); _l2583->n += _o2583.n; }));
(void)(({ L96 *_l2584 = &(b_1766); hrv _o2584 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2584, hr_str("_x", 2)); hr_fi(&_o2584, p_1764); if (_l2584->n + _o2584.n > 64) hr_die("format past a limited array's capacity", "hc/gen.amni:684"); memcpy(_l2584->e + _l2584->n, _o2584.b, (size_t)_o2584.n); _l2584->n += _o2584.n; }));
(void)(f311_heq_o(e_1763, ({ hsl _t2585 = ({ L94 *_t2586 = &(a_1765); (hsl){ (uint8_t*)_t2586->e, _t2586->n }; }); int64_t _l2585 = 0, _h2585 = _t2585.n; if (_l2585 < 0 || _h2585 < _l2585 || _h2585 > _t2585.n) hr_slerr(_l2585, _h2585, _t2585.n, "hc/gen.amni:684"); (hsl){ _t2585.p + _l2585 * (int64_t)sizeof(uint8_t), _h2585 - _l2585 }; }), ({ hsl _t2587 = ({ L96 *_t2588 = &(b_1766); (hsl){ (uint8_t*)_t2588->e, _t2588->n }; }); int64_t _l2587 = 0, _h2587 = _t2587.n; if (_l2587 < 0 || _h2587 < _l2587 || _h2587 > _t2587.n) hr_slerr(_l2587, _h2587, _t2587.n, "hc/gen.amni:684"); (hsl){ _t2587.p + _l2587 * (int64_t)sizeof(uint8_t), _h2587 - _l2587 }; })));
}
static void f316_gblkcall(int64_t n_1767) {
int64_t bi_1768 = f156_rv(n_1767); 
int64_t fv_1769 = ((int64_t)(((*({ hrv *_t2589 = &(g371); int64_t _i2589 = bi_1768; (S6*)_t2589->b + hr_ix(_i2589, _t2589->n, "hc/gen.amni:596"); }))).node_)); 
int64_t sa_1770 = g382; 
(void)(f245_ow(hr_str("({ ", 3)));
int64_t np_1771 = ((int64_t)(((*({ hrv *_t2590 = &(g675); int64_t _i2590 = fv_1769; (S4*)_t2590->b + hr_ix(_i2590, _t2590->n, "hc/gen.amni:599"); }))).n_)); 
int64_t na_1772 = ((int64_t)(((*({ hrv *_t2591 = &(g675); int64_t _i2591 = n_1767; (S4*)_t2591->b + hr_ix(_i2591, _t2591->n, "hc/gen.amni:600"); }))).n_)); 
if (((((uint16_t)((uint64_t)((*({ hrv *_t2592 = &(g675); int64_t _i2592 = fv_1769; (S4*)_t2592->b + hr_ix(_i2592, _t2592->n, "hc/gen.amni:601"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { int64_t _e2594 = np_1771; for (int64_t j_1773 = 0; j_1773 < _e2594; j_1773++) { int64_t p_1774 = f90_kid(fv_1769, j_1773); 
g382 = bi_1768;
int64_t v_1775 = f156_rv(p_1774); 
g382 = sa_1770;
if (((j_1773) < (na_1772))) { (void)(f246_ct(((int64_t)(((*({ hrv *_t2595 = &(g372); int64_t _i2595 = v_1775; (S12*)_t2595->b + hr_ix(_i2595, _t2595->n, "hc/gen.amni:602"); }))).ty_))));
(void)(f245_ow(hr_str(" ", 1)));
(void)(f271_lv_name(v_1775));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(f90_kid(n_1767, j_1773)));
(void)(f245_ow(hr_str("; ", 2)));
 }
 } } _bk2593:; 
 } else { if (((na_1772) >= (((int64_t)1LL)))) { g382 = bi_1768;
int64_t v_1776 = f156_rv(fv_1769); 
g382 = sa_1770;
if (((v_1776) >= (((int64_t)0LL)))) { (void)(f246_ct(((int64_t)(((*({ hrv *_t2596 = &(g372); int64_t _i2596 = v_1776; (S12*)_t2596->b + hr_ix(_i2596, _t2596->n, "hc/gen.amni:604"); }))).ty_))));
(void)(f245_ow(hr_str(" ", 1)));
(void)(f271_lv_name(v_1776));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(f90_kid(n_1767, ((int64_t)0LL))));
(void)(f245_ow(hr_str("; ", 2)));
 } else { (void)(f245_ow(hr_str("(void)(", 7)));
(void)(f274_gx(f90_kid(n_1767, ((int64_t)0LL))));
(void)(f245_ow(hr_str("); ", 3)));
 }
 }
 }
g382 = bi_1768;
int64_t body_1777 = ((int64_t)(((*({ hrv *_t2597 = &(g675); int64_t _i2597 = fv_1769; (S4*)_t2597->b + hr_ix(_i2597, _t2597->n, "hc/gen.amni:607"); }))).a_)); 
{ int32_t _e2599 = ((*({ hrv *_t2600 = &(g675); int64_t _i2600 = body_1777; (S4*)_t2600->b + hr_ix(_i2600, _t2600->n, "hc/gen.amni:608"); }))).n_; for (int32_t i_1778 = 0; i_1778 < _e2599; i_1778++) { (void)(f317_gstmt(f90_kid(body_1777, ((int64_t)(i_1778)))));
 } } _bk2598:; 
int64_t tl_1894 = ((int64_t)(((*({ hrv *_t2601 = &(g675); int64_t _i2601 = body_1777; (S4*)_t2601->b + hr_ix(_i2601, _t2601->n, "hc/gen.amni:609"); }))).a_)); 
if (((tl_1894) >= (((int64_t)0LL)))) { if ((((((int64_t)(((*({ hrv *_t2602 = &(g371); int64_t _i2602 = bi_1768; (S6*)_t2602->b + hr_ix(_i2602, _t2602->n, "hc/gen.amni:610"); }))).ret_))) != (g531)) && (!(f202_ends(tl_1894))))) { (void)(f274_gx(tl_1894));
(void)(f245_ow(hr_str("; ", 2)));
 } else { (void)(f317_gstmt(tl_1894));
 }
 }
g382 = sa_1770;
(void)(f245_ow(hr_str(" })", 3)));
}
static void f317_gstmt(int64_t n_1779) {
if (((n_1779) < (((int64_t)0LL)))) { return;
 }
int64_t sp_1780 = (g163).n; 
int64_t td_1781 = (g176).n; 
S4 x_1782 = (*({ hrv *_t2603 = &(g675); int64_t _i2603 = n_1779; (S4*)_t2603->b + hr_ix(_i2603, _t2603->n, "hc/gen.amni:970"); })); 
int64_t k_1783 = ((int64_t)((x_1782).k_)); 
bool decl_1784 = ((k_1783) == (((int64_t)33LL))); 
if (((k_1783) == (((int64_t)33LL)))) { (void)(f318_gvdecl(n_1779));
 } else { (void)(f320_gstmt1(n_1779));
 }
(void)(f245_ow(hr_str("\012", 1)));
if ((((g176).n) > (td_1781))) { (void)(({ hrv *_v2604 = &(g177); _v2604->n = 0; }));
(void)(({ hrv *_v2605 = &(g177); hsl _s2605 = ({ hsl _t2606 = hr_sl(g163); int64_t _l2606 = sp_1780, _h2606 = _t2606.n; if (_l2606 < 0 || _h2606 < _l2606 || _h2606 > _t2606.n) hr_slerr(_l2606, _h2606, _t2606.n, "hc/gen.amni:976"); (hsl){ _t2606.p + _l2606 * (int64_t)sizeof(uint8_t), _h2606 - _l2606 }; }); hr_append(_v2605, _s2605.p, _s2605.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2607 = &(g163); int64_t _k2607 = sp_1780; if (_k2607 < 0) hr_die("resize to a negative length", "hc/gen.amni:976"); hr_resize(_v2607, _k2607, sizeof(uint8_t)); }));
if ((!(decl_1784))) { (void)(f245_ow(hr_str("{ ", 2)));
 }
(void)(({ hrv *_v2608 = &(g163); hsl _s2608 = ({ hsl _t2609 = hr_sl(g176); int64_t _l2609 = td_1781, _h2609 = _t2609.n; if (_l2609 < 0 || _h2609 < _l2609 || _h2609 > _t2609.n) hr_slerr(_l2609, _h2609, _t2609.n, "hc/gen.amni:978"); (hsl){ _t2609.p + _l2609 * (int64_t)sizeof(uint8_t), _h2609 - _l2609 }; }); hr_append(_v2608, _s2608.p, _s2608.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2610 = &(g176); int64_t _k2610 = td_1781; if (_k2610 < 0) hr_die("resize to a negative length", "hc/gen.amni:978"); hr_resize(_v2610, _k2610, sizeof(uint8_t)); }));
(void)(({ hrv *_v2611 = &(g163); hsl _s2611 = ({ hsl _t2612 = hr_sl(g177); int64_t _l2612 = 0, _h2612 = _t2612.n; if (_l2612 < 0 || _h2612 < _l2612 || _h2612 > _t2612.n) hr_slerr(_l2612, _h2612, _t2612.n, "hc/gen.amni:979"); (hsl){ _t2612.p + _l2612 * (int64_t)sizeof(uint8_t), _h2612 - _l2612 }; }); hr_append(_v2611, _s2611.p, _s2611.n, sizeof(uint8_t)); }));
if ((!(decl_1784))) { (void)(f245_ow(hr_str("}\012", 2)));
 }
 }
}
static void f318_gvdecl(int64_t n_1785) {
S4 x_1786 = (*({ hrv *_t2613 = &(g675); int64_t _i2613 = n_1785; (S4*)_t2613->b + hr_ix(_i2613, _t2613->n, "hc/gen.amni:885"); })); 
if ((((x_1786).n_) > (((int32_t)1LL)))) { if (((f209_ax(n_1785)) == (((int64_t)1LL)))) { L89 ids_1787 = ({ L89 _t2614; memset(&_t2614, 0, sizeof _t2614); _t2614.n = 0; _t2614; }); 
{ int32_t _e2616 = (x_1786).n_; for (int32_t i_1788 = 0; i_1788 < _e2616; i_1788++) { int64_t iv_1789 = f90_kid(((int64_t)((x_1786).b_)), ((int64_t)(i_1788))); 
int64_t p_1790 = f278_nt(); 
(void)(({ L89 *_v2617 = &(ids_1787); int32_t _x2617 = ((int32_t)(p_1790)); if (_v2617->n >= 64) hr_die("push past a limited array's capacity", "hc/gen.amni:889"); _v2617->e[_v2617->n] = _x2617; &_v2617->e[_v2617->n++]; }));
(void)(f246_ct(f264_fin(iv_1789)));
(void)(f245_ow(hr_str(" _t", 3)));
(void)(f279_oi(p_1790));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(iv_1789));
(void)(f245_ow(hr_str("; ", 2)));
 } } _bk2615:; 
int64_t v0_1791 = f156_rv(n_1785); 
{ int32_t _e2619 = (x_1786).n_; for (int32_t i_1792 = 0; i_1792 < _e2619; i_1792++) { (void)(f319_decl_lv(((int64_t)((int64_t)v0_1791 + (int64_t)((int64_t)(i_1792))))));
(void)(({ hrv *_o2620 = &(g163); hr_fs(_o2620, hr_str(" = _t", 5)); hr_fi(_o2620, (*({ L89 *_t2621 = &(ids_1787); int64_t _i2621 = i_1792; _t2621->e + hr_ix(_i2621, _t2621->n, "hc/gen.amni:891"); }))); hr_fs(_o2620, hr_str("; ", 2)); }));
 } } _bk2618:; 
return;
 }
int64_t init_1795 = f90_kid(((int64_t)((x_1786).b_)), ((int64_t)0LL)); 
int64_t p_1796 = f278_nt(); 
(void)(f246_ct(f140_at(init_1795)));
(void)(f245_ow(hr_str(" _t", 3)));
(void)(f279_oi(p_1796));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(init_1795));
(void)(f245_ow(hr_str("; ", 2)));
int64_t v0_1797 = f156_rv(n_1785); 
{ int32_t _e2623 = (x_1786).n_; for (int32_t i_1798 = 0; i_1798 < _e2623; i_1798++) { (void)(f319_decl_lv(((int64_t)((int64_t)v0_1797 + (int64_t)((int64_t)(i_1798))))));
(void)(({ hrv *_o2624 = &(g163); hr_fs(_o2624, hr_str(" = _t", 5)); hr_fi(_o2624, p_1796); hr_fs(_o2624, hr_str(".r", 2)); hr_fi(_o2624, i_1798); hr_fs(_o2624, hr_str("; ", 2)); }));
 } } _bk2622:; 
return;
 }
int64_t v_1799 = f156_rv(n_1785); 
int64_t t_1800 = ((int64_t)(((*({ hrv *_t2625 = &(g372); int64_t _i2625 = v_1799; (S12*)_t2625->b + hr_ix(_i2625, _t2625->n, "hc/gen.amni:902"); }))).ty_)); 
(void)(f319_decl_lv(v_1799));
(void)(f245_ow(hr_str(" = ", 3)));
if ((((x_1786).b_) < (((int32_t)0LL)))) { (void)(f245_ow(hr_str("{0}; ", 5)));
return;
 }
int64_t init_1801 = f90_kid(((int64_t)((x_1786).b_)), ((int64_t)0LL)); 
if ((((((*({ hrv *_t2626 = &(g524); int64_t _i2626 = t_1800; (S1*)_t2626->b + hr_ix(_i2626, _t2626->n, "hc/gen.amni:907"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)(x_1786).fl_ & (uint64_t)((uint16_t)4LL)))) != (((uint16_t)0LL))))) { int64_t it_1802 = f264_fin(init_1801); 
if (((((*({ hrv *_t2627 = &(g524); int64_t _i2627 = it_1802; (S1*)_t2627->b + hr_ix(_i2627, _t2627->n, "hc/gen.amni:907"); }))).k_) == (((uint8_t)10LL)))) { (void)(f274_gx(init_1801));
 } else { (void)(f245_ow(hr_str("&(", 2)));
(void)(f274_gx(init_1801));
(void)(f245_ow(hr_str(")", 1)));
 }
(void)(f245_ow(hr_str("; ", 2)));
return;
 }
if (f253_is_res(t_1800)) { (void)(f254_gxo(init_1801));
(void)(f245_ow(hr_str("; ", 2)));
return;
 }
int64_t it_1803 = f140_at(init_1801); 
if (((((*({ hrv *_t2628 = &(g524); int64_t _i2628 = it_1803; (S1*)_t2628->b + hr_ix(_i2628, _t2628->n, "hc/gen.amni:910"); }))).k_) == (((uint8_t)14LL)))) { (void)(f274_gx(init_1801));
(void)(({ hrv *_o2629 = &(g163); hr_fs(_o2629, hr_str(".r0; ", 5)); }));
return;
 }
(void)(f274_gx(init_1801));
(void)(f245_ow(hr_str("; ", 2)));
}
static void f319_decl_lv(int64_t v_1793) {
int64_t t_1794 = ((int64_t)(((*({ hrv *_t2630 = &(g372); int64_t _i2630 = v_1793; (S12*)_t2630->b + hr_ix(_i2630, _t2630->n, "hc/gen.amni:914"); }))).ty_)); 
(void)(f246_ct(t_1794));
(void)(f245_ow(hr_str(" ", 1)));
if (f270_lv_isptr(v_1793)) { (void)(f245_ow(hr_str("*", 1)));
 }
(void)(f271_lv_name(v_1793));
if ((f253_is_res(t_1794) && (!(f270_lv_isptr(v_1793))))) { (void)(f245_ow(hr_str(" __attribute__((cleanup(hr_rdrop)))", 35)));
 }
}
static void f320_gstmt1(int64_t n_1804) {
S4 x_1805 = (*({ hrv *_t2631 = &(g675); int64_t _i2631 = n_1804; (S4*)_t2631->b + hr_ix(_i2631, _t2631->n, "hc/gen.amni:984"); })); 
int64_t k_1806 = ((int64_t)((x_1805).k_)); 
if (((k_1806) == (((int64_t)34LL)))) { (void)(f321_gassign(n_1804));
return;
 }
if (((k_1806) == (((int64_t)35LL)))) { int64_t a_1819 = ((int64_t)((x_1805).a_)); 
int64_t tt_1820 = f140_at(a_1819); 
if (((((*({ hrv *_t2632 = &(g524); int64_t _i2632 = tt_1820; (S1*)_t2632->b + hr_ix(_i2632, _t2632->n, "hc/gen.amni:987"); }))).k_) == (((uint8_t)10LL)))) { (void)(f245_ow(hr_str("(*", 2)));
(void)(f260_gx0(a_1819));
(void)(f245_ow(hr_str(")", 1)));
 } else { (void)(f274_gx(a_1819));
 }
(void)(f245_ow(({ hsl _r2633; if (((((int64_t)((x_1805).op_))) == (((int64_t)34LL)))) { _r2633 = hr_str("++;", 3);  } else { _r2633 = hr_str("--;", 3);  } _r2633; })));
return;
 }
if (((k_1806) == (((int64_t)50LL)))) { return;
 }
if (((k_1806) == (((int64_t)19LL)))) { (void)(f323_gif(n_1804, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1806) == (((int64_t)25LL)))) { (void)(f326_gwhile(n_1804));
return;
 }
if (((k_1806) == (((int64_t)26LL)))) { (void)(f329_gloop(n_1804, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1806) == (((int64_t)27LL)))) { (void)(f330_gfor(n_1804));
return;
 }
if (((k_1806) == (((int64_t)20LL)))) { (void)(f331_gmatch(n_1804, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1806) == (((int64_t)24LL)))) { (void)(f332_geblock(n_1804, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1806) == (((int64_t)23LL)))) { (void)(f245_ow(hr_str("{ ", 2)));
(void)(f324_gblk(n_1804, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f245_ow(hr_str(" }", 2)));
return;
 }
if (((k_1806) == (((int64_t)28LL)))) { (void)(f333_gret(n_1804));
return;
 }
if (((k_1806) == (((int64_t)29LL)))) { (void)(f334_gbreak(n_1804));
return;
 }
if (((k_1806) == (((int64_t)30LL)))) { (void)(f245_ow(hr_str("continue;", 9)));
return;
 }
if (((k_1806) == (((int64_t)37LL)))) { (void)(f272_gerr(n_1804, hr_str("const for is not supported by the self-hosted compiler yet", 58)));
return;
 }
if (f335_owned(n_1804)) { (void)(f245_ow(hr_str("hr_rgive(", 9)));
(void)(f260_gx0(n_1804));
(void)(f245_ow(hr_str(");", 2)));
return;
 }
(void)(f245_ow(hr_str("(void)(", 7)));
(void)(f274_gx(n_1804));
(void)(f245_ow(hr_str(");", 2)));
}
static void f321_gassign(int64_t n_1807) {
S4 x_1808 = (*({ hrv *_t2634 = &(g675); int64_t _i2634 = n_1807; (S4*)_t2634->b + hr_ix(_i2634, _t2634->n, "hc/gen.amni:921"); })); 
int64_t o_1809 = ((int64_t)((x_1808).op_)); 
if (((o_1809) == (((int64_t)11LL)))) { int64_t p_1810 = f278_nt(); 
(void)(f245_ow(hr_str("{ ", 2)));
(void)(f246_ct(f140_at(((int64_t)((x_1808).b_)))));
(void)(f245_ow(hr_str(" _t", 3)));
(void)(f279_oi(p_1810));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(((int64_t)((x_1808).b_))));
(void)(f245_ow(hr_str("; ", 2)));
int64_t tl_1811 = ((int64_t)((x_1808).a_)); 
{ int32_t _e2636 = ((*({ hrv *_t2637 = &(g675); int64_t _i2637 = tl_1811; (S4*)_t2637->b + hr_ix(_i2637, _t2637->n, "hc/gen.amni:927"); }))).n_; for (int32_t i_1812 = 0; i_1812 < _e2636; i_1812++) { int64_t tg_1813 = f90_kid(tl_1811, ((int64_t)(i_1812))); 
(void)(f274_gx(tg_1813));
(void)(({ hrv *_o2638 = &(g163); hr_fs(_o2638, hr_str(" = _t", 5)); hr_fi(_o2638, p_1810); hr_fs(_o2638, hr_str(".r", 2)); hr_fi(_o2638, i_1812); hr_fs(_o2638, hr_str("; ", 2)); }));
 } } _bk2635:; 
(void)(f245_ow(hr_str("}", 1)));
return;
 }
int64_t a_1814 = ((int64_t)((x_1808).a_)); 
int64_t tt_1815 = f140_at(a_1814); 
int64_t d_1816 = f174_deref(tt_1815); 
if ((((o_1809) == (((int64_t)36LL))) || ((o_1809) == (((int64_t)18LL))))) { if (f253_is_res(d_1816)) { (void)(f245_ow(hr_str("hr_rset(", 8)));
if (((((*({ hrv *_t2639 = &(g524); int64_t _i2639 = tt_1815; (S1*)_t2639->b + hr_ix(_i2639, _t2639->n, "hc/gen.amni:935"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_gx0(a_1814));
 } else { (void)(f245_ow(hr_str("&(", 2)));
(void)(f274_gx(a_1814));
(void)(f245_ow(hr_str(")", 1)));
 }
(void)(f245_ow(hr_str(", ", 2)));
(void)(f254_gxo(((int64_t)((x_1808).b_))));
(void)(f245_ow(hr_str(");", 2)));
return;
 }
if ((((((((*({ hrv *_t2640 = &(g524); int64_t _i2640 = tt_1815; (S1*)_t2640->b + hr_ix(_i2640, _t2640->n, "hc/gen.amni:936"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2641 = &(g524); int64_t _i2641 = f140_at(((int64_t)((x_1808).b_))); (S1*)_t2641->b + hr_ix(_i2641, _t2641->n, "hc/gen.amni:936"); }))).k_) != (((uint8_t)10LL)))) && ((((*({ hrv *_t2642 = &(g524); int64_t _i2642 = f264_fin(((int64_t)((x_1808).b_))); (S1*)_t2642->b + hr_ix(_i2642, _t2642->n, "hc/gen.amni:936"); }))).k_) != (((uint8_t)10LL)))) && ((((*({ hrv *_t2643 = &(g524); int64_t _i2643 = f140_at(((int64_t)((x_1808).b_))); (S1*)_t2643->b + hr_ix(_i2643, _t2643->n, "hc/gen.amni:936"); }))).k_) != (((uint8_t)11LL))))) { (void)(f245_ow(hr_str("*", 1)));
(void)(f260_gx0(a_1814));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(((int64_t)((x_1808).b_))));
(void)(f245_ow(hr_str(";", 1)));
return;
 }
(void)(f274_gx(a_1814));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(((int64_t)((x_1808).b_))));
(void)(f245_ow(hr_str(";", 1)));
return;
 }
int64_t p_1817 = f278_nt(); 
(void)(f245_ow(hr_str("{ ", 2)));
(void)(f246_ct(d_1816));
(void)(f245_ow(hr_str(" *_t", 4)));
(void)(f279_oi(p_1817));
(void)(f245_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t2644 = &(g524); int64_t _i2644 = tt_1815; (S1*)_t2644->b + hr_ix(_i2644, _t2644->n, "hc/gen.amni:942"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_gx0(a_1814));
 } else { (void)(f245_ow(hr_str("&(", 2)));
(void)(f274_gx(a_1814));
(void)(f245_ow(hr_str(")", 1)));
 }
(void)(f245_ow(hr_str("; *_t", 5)));
(void)(f279_oi(p_1817));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f291_garith(f322_base_op(o_1809), d_1816, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)((x_1808).b_)), p_1817, n_1807));
(void)(f245_ow(hr_str("; }", 3)));
}
static int64_t f322_base_op(int64_t o_1818) {
if (((o_1818) == (((int64_t)26LL)))) { return ((int64_t)21LL);
 }
if (((o_1818) == (((int64_t)27LL)))) { return ((int64_t)22LL);
 }
if (((o_1818) == (((int64_t)28LL)))) { return ((int64_t)23LL);
 }
if (((o_1818) == (((int64_t)29LL)))) { return ((int64_t)24LL);
 }
if (((o_1818) == (((int64_t)30LL)))) { return ((int64_t)25LL);
 }
if (((o_1818) == (((int64_t)31LL)))) { return ((int64_t)49LL);
 }
if (((o_1818) == (((int64_t)32LL)))) { return ((int64_t)50LL);
 }
if (((o_1818) == (((int64_t)33LL)))) { return ((int64_t)51LL);
 }
if (((o_1818) == (((int64_t)45LL)))) { return ((int64_t)43LL);
 }
if (((o_1818) == (((int64_t)46LL)))) { return ((int64_t)44LL);
 }
return o_1818;
}
static void f323_gif(int64_t n_1821, int64_t res_1822) {
S4 x_1823 = (*({ hrv *_t2645 = &(g675); int64_t _i2645 = n_1821; (S4*)_t2645->b + hr_ix(_i2645, _t2645->n, "hc/gen.amni:770"); })); 
(void)(f245_ow(hr_str("if (", 4)));
int64_t m_1824 = f209_ax(n_1821); 
if ((((m_1824) != (((int64_t)0LL))) && ((m_1824) != (((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))))) { (void)(f245_ow(hr_str("(", 1)));
(void)(f260_gx0(((int64_t)((x_1823).a_))));
(void)(f245_ow(hr_str(") != 0", 6)));
 } else { (void)(f274_gx(((int64_t)((x_1823).a_))));
 }
(void)(f245_ow(hr_str(") { ", 4)));
if (((m_1824) > (((int64_t)1LL)))) { int64_t v_1825 = ((int64_t)((int64_t)m_1824 & (int64_t)((int64_t)((int64_t)((int64_t)((((int64_t)1LL)) << ((((int64_t)30LL)) & 63))) - (int64_t)((int64_t)1LL))))); 
(void)(f246_ct(((int64_t)(((*({ hrv *_t2646 = &(g372); int64_t _i2646 = v_1825; (S12*)_t2646->b + hr_ix(_i2646, _t2646->n, "hc/gen.amni:775"); }))).ty_))));
(void)(f245_ow(hr_str(" *", 2)));
(void)(f271_lv_name(v_1825));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f260_gx0(((int64_t)((x_1823).a_))));
(void)(f245_ow(hr_str("; ", 2)));
 }
(void)(f324_gblk(((int64_t)((x_1823).b_)), res_1822, false));
(void)(f245_ow(hr_str(" }", 2)));
if ((((x_1823).c_) >= (((int32_t)0LL)))) { (void)(f245_ow(hr_str(" else { ", 8)));
if (((((*({ hrv *_t2647 = &(g675); int64_t _i2647 = (x_1823).c_; (S4*)_t2647->b + hr_ix(_i2647, _t2647->n, "hc/gen.amni:778"); }))).k_) == (((uint8_t)19LL)))) { (void)(f323_gif(((int64_t)((x_1823).c_)), res_1822));
 } else { (void)(f324_gblk(((int64_t)((x_1823).c_)), res_1822, false));
 }
(void)(f245_ow(hr_str(" }", 2)));
 }
}
static void f324_gblk(int64_t b_1826, int64_t res_1827, bool val_1828) {
S4 x_1829 = (*({ hrv *_t2648 = &(g675); int64_t _i2648 = b_1826; (S4*)_t2648->b + hr_ix(_i2648, _t2648->n, "hc/gen.amni:759"); })); 
if (((((int64_t)((x_1829).k_))) != (((int64_t)23LL)))) { if (((res_1827) >= (((int64_t)0LL)))) { (void)(f325_gtail(b_1826, res_1827));
 } else { if (val_1828) { (void)(f274_gx(b_1826));
(void)(f245_ow(hr_str(";", 1)));
 } else { (void)(f317_gstmt(b_1826));
 }
 }
return;
 }
{ int32_t _e2650 = (x_1829).n_; for (int32_t i_1832 = 0; i_1832 < _e2650; i_1832++) { (void)(f317_gstmt(f90_kid(b_1826, ((int64_t)(i_1832)))));
 } } _bk2649:; 
if ((((x_1829).a_) >= (((int32_t)0LL)))) { int64_t tl_1833 = ((int64_t)((x_1829).a_)); 
if (((res_1827) >= (((int64_t)0LL)))) { (void)(f325_gtail(tl_1833, res_1827));
return;
 }
if (((val_1828 && ((f140_at(tl_1833)) != (g531))) && (!(f202_ends(tl_1833))))) { (void)(f274_gx(tl_1833));
(void)(f245_ow(hr_str("; ", 2)));
return;
 }
(void)(f317_gstmt(tl_1833));
 }
}
static void f325_gtail(int64_t tl_1830, int64_t res_1831) {
if ((((res_1831) >= (((int64_t)0LL))) && (!(f202_ends(tl_1830))))) { (void)(f245_ow(hr_str("_r", 2)));
(void)(f279_oi(res_1831));
(void)(f245_ow(hr_str(" = ", 3)));
if (f253_is_res(f264_fin(tl_1830))) { (void)(f254_gxo(tl_1830));
 } else { (void)(f274_gx(tl_1830));
 }
(void)(f245_ow(hr_str("; ", 2)));
return;
 }
(void)(f317_gstmt(tl_1830));
}
static void f326_gwhile(int64_t n_1834) {
S4 x_1835 = (*({ hrv *_t2651 = &(g675); int64_t _i2651 = n_1834; (S4*)_t2651->b + hr_ix(_i2651, _t2651->n, "hc/gen.amni:793"); })); 
int64_t l_1838 = f327_lbl_push(((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f245_ow(hr_str("while (", 7)));
if (((f209_ax(n_1834)) == (((int64_t)1LL)))) { (void)(f245_ow(hr_str("(", 1)));
(void)(f260_gx0(((int64_t)((x_1835).a_))));
(void)(f245_ow(hr_str(") != 0", 6)));
 } else { (void)(f274_gx(((int64_t)((x_1835).a_))));
 }
(void)(f245_ow(hr_str(") { ", 4)));
(void)(f324_gblk(((int64_t)((x_1835).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f245_ow(hr_str(" }", 2)));
(void)(f328_lbl_pop(l_1838));
}
static int64_t f327_lbl_push(int64_t res_1836) {
int64_t l_1837 = f278_nt(); 
(void)(({ hrv *_v2652 = &(g180); int32_t _x2652 = ((int32_t)(l_1837)); int32_t *_p2652 = (int32_t*)hr_grow(_v2652, 1, sizeof _x2652); *_p2652 = _x2652; _p2652; }));
(void)(({ hrv *_v2653 = &(g181); int32_t _x2653 = ((int32_t)(res_1836)); int32_t *_p2653 = (int32_t*)hr_grow(_v2653, 1, sizeof _x2653); *_p2653 = _x2653; _p2653; }));
return l_1837;
}
static void f328_lbl_pop(int64_t l_1839) {
(void)(({ hrv *_v2654 = &(g180); if (!_v2654->n) hr_die("pop of an empty array", "hc/gen.amni:781"); ((int32_t*)_v2654->b)[--_v2654->n]; }));
(void)(({ hrv *_v2655 = &(g181); if (!_v2655->n) hr_die("pop of an empty array", "hc/gen.amni:781"); ((int32_t*)_v2655->b)[--_v2655->n]; }));
(void)(({ hrv *_o2656 = &(g163); hr_fs(_o2656, hr_str(" _bk", 4)); hr_fi(_o2656, l_1839); hr_fs(_o2656, hr_str(":; ", 3)); }));
}
static void f329_gloop(int64_t n_1840, int64_t res_1841) {
int64_t l_1842 = f327_lbl_push(res_1841); 
(void)(f245_ow(hr_str("for (;;) { ", 11)));
(void)(f324_gblk(((int64_t)(((*({ hrv *_t2657 = &(g675); int64_t _i2657 = n_1840; (S4*)_t2657->b + hr_ix(_i2657, _t2657->n, "hc/gen.amni:784"); }))).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f245_ow(hr_str(" }", 2)));
(void)(f328_lbl_pop(l_1842));
}
static void f330_gfor(int64_t n_1843) {
S4 x_1844 = (*({ hrv *_t2658 = &(g675); int64_t _i2658 = n_1843; (S4*)_t2658->b + hr_ix(_i2658, _t2658->n, "hc/gen.amni:801"); })); 
int64_t v_1845 = f156_rv(n_1843); 
int64_t m_1846 = f209_ax(n_1843); 
int64_t iv_1847 = ({ int64_t _r2659; if ((((x_1844).c_) >= (((int32_t)0LL)))) { _r2659 = ((int64_t)((m_1846) >> ((((int64_t)2LL)) & 63)));  } else { _r2659 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2659; }); 
int64_t l_1848 = f327_lbl_push(((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t p_1849 = f278_nt(); 
int64_t et_1850 = ((int64_t)(((*({ hrv *_t2660 = &(g372); int64_t _i2660 = v_1845; (S12*)_t2660->b + hr_ix(_i2660, _t2660->n, "hc/gen.amni:807"); }))).ty_)); 
if (((((int64_t)((int64_t)m_1846 & (int64_t)((int64_t)3LL)))) == (((int64_t)0LL)))) { (void)(f245_ow(hr_str("{ ", 2)));
(void)(f246_ct(et_1850));
(void)(f245_ow(hr_str(" _e", 3)));
(void)(f279_oi(p_1849));
(void)(f245_ow(hr_str(" = ", 3)));
if ((((x_1844).b_) >= (((int32_t)0LL)))) { (void)(f274_gx(((int64_t)((x_1844).b_))));
 } else { (void)(f274_gx(((int64_t)((x_1844).a_))));
 }
(void)(f245_ow(hr_str("; for (", 7)));
(void)(f246_ct(et_1850));
(void)(f245_ow(hr_str(" ", 1)));
(void)(f271_lv_name(v_1845));
(void)(f245_ow(hr_str(" = ", 3)));
if ((((x_1844).b_) >= (((int32_t)0LL)))) { (void)(f274_gx(((int64_t)((x_1844).a_))));
 } else { (void)(f245_ow(hr_str("0", 1)));
 }
(void)(f245_ow(hr_str("; ", 2)));
(void)(f271_lv_name(v_1845));
(void)(({ hrv *_o2661 = &(g163); hr_fs(_o2661, hr_str(" < _e", 5)); hr_fi(_o2661, p_1849); hr_fs(_o2661, hr_str("; ", 2)); }));
(void)(f271_lv_name(v_1845));
(void)(f245_ow(hr_str("++) { ", 6)));
if (((iv_1847) >= (((int64_t)0LL)))) { (void)(f245_ow(hr_str("int64_t ", 8)));
(void)(f271_lv_name(iv_1847));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f271_lv_name(v_1845));
(void)(f245_ow(hr_str("; ", 2)));
 }
(void)(f324_gblk(((int64_t)((x_1844).d_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f245_ow(hr_str(" } }", 4)));
(void)(f328_lbl_pop(l_1848));
return;
 }
int64_t a_1851 = ((int64_t)((x_1844).a_)); 
int64_t bt_1852 = f140_at(a_1851); 
int64_t d_1853 = f174_deref(bt_1852); 
int64_t e_1854 = ((int64_t)(((*({ hrv *_t2662 = &(g524); int64_t _i2662 = d_1853; (S1*)_t2662->b + hr_ix(_i2662, _t2662->n, "hc/gen.amni:823"); }))).a_)); 
bool byref_1855 = ((((uint16_t)((uint64_t)(x_1844).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))); 
if (f253_is_res(d_1853)) { (void)(f245_ow(hr_str("{ hrv *_v", 9)));
(void)(f279_oi(p_1849));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f307_grecv_ptr(a_1851));
(void)(({ hrv *_o2663 = &(g163); hr_fs(_o2663, hr_str("; for (int64_t _k", 17)); hr_fi(_o2663, p_1849); hr_fs(_o2663, hr_str(" = 0; _k", 8)); hr_fi(_o2663, p_1849); hr_fs(_o2663, hr_str(" < _v", 5)); hr_fi(_o2663, p_1849); hr_fs(_o2663, hr_str("->n; _k", 7)); hr_fi(_o2663, p_1849); hr_fs(_o2663, hr_str("++) { ", 6)); }));
(void)(f246_ct(e_1854));
(void)(f245_ow(({ hsl _r2664; if (byref_1855) { _r2664 = hr_str(" *", 2);  } else { _r2664 = hr_str(" ", 1);  } _r2664; })));
(void)(f271_lv_name(v_1845));
(void)(f245_ow(({ hsl _r2665; if (byref_1855) { _r2665 = hr_str(" = &((", 6);  } else { _r2665 = hr_str(" = ((", 5);  } _r2665; })));
(void)(f246_ct(e_1854));
(void)(({ hrv *_o2666 = &(g163); hr_fs(_o2666, hr_str("*)_v", 4)); hr_fi(_o2666, p_1849); hr_fs(_o2666, hr_str("->b)[_k", 7)); hr_fi(_o2666, p_1849); hr_fs(_o2666, hr_str("]; ", 3)); }));
 } else { (void)(f245_ow(hr_str("{ hsl _v", 8)));
(void)(f279_oi(p_1849));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f277_gsl(a_1851, bt_1852));
(void)(({ hrv *_o2667 = &(g163); hr_fs(_o2667, hr_str("; for (int64_t _k", 17)); hr_fi(_o2667, p_1849); hr_fs(_o2667, hr_str(" = 0; _k", 8)); hr_fi(_o2667, p_1849); hr_fs(_o2667, hr_str(" < _v", 5)); hr_fi(_o2667, p_1849); hr_fs(_o2667, hr_str(".n; _k", 6)); hr_fi(_o2667, p_1849); hr_fs(_o2667, hr_str("++) { ", 6)); }));
(void)(f246_ct(e_1854));
(void)(f245_ow(({ hsl _r2668; if (byref_1855) { _r2668 = hr_str(" *", 2);  } else { _r2668 = hr_str(" ", 1);  } _r2668; })));
(void)(f271_lv_name(v_1845));
(void)(f245_ow(({ hsl _r2669; if (byref_1855) { _r2669 = hr_str(" = &((", 6);  } else { _r2669 = hr_str(" = ((", 5);  } _r2669; })));
(void)(f246_ct(e_1854));
(void)(({ hrv *_o2670 = &(g163); hr_fs(_o2670, hr_str("*)_v", 4)); hr_fi(_o2670, p_1849); hr_fs(_o2670, hr_str(".p)[_k", 6)); hr_fi(_o2670, p_1849); hr_fs(_o2670, hr_str("]; ", 3)); }));
 }
if (((iv_1847) >= (((int64_t)0LL)))) { (void)(f245_ow(hr_str("int64_t ", 8)));
(void)(f271_lv_name(iv_1847));
(void)(({ hrv *_o2671 = &(g163); hr_fs(_o2671, hr_str(" = _k", 5)); hr_fi(_o2671, p_1849); hr_fs(_o2671, hr_str("; ", 2)); }));
 }
(void)(f324_gblk(((int64_t)((x_1844).d_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f245_ow(hr_str(" } }", 4)));
(void)(f328_lbl_pop(l_1848));
}
static void f331_gmatch(int64_t n_1856, int64_t res_1857) {
S4 x_1858 = (*({ hrv *_t2672 = &(g675); int64_t _i2672 = n_1856; (S4*)_t2672->b + hr_ix(_i2672, _t2672->n, "hc/gen.amni:838"); })); 
int64_t a_1859 = ((int64_t)((x_1858).a_)); 
int64_t st_1860 = f140_at(a_1859); 
int64_t d_1861 = f174_deref(st_1860); 
int64_t p_1862 = f278_nt(); 
bool isenum_1863 = ((((*({ hrv *_t2673 = &(g524); int64_t _i2673 = d_1861; (S1*)_t2673->b + hr_ix(_i2673, _t2673->n, "hc/gen.amni:843"); }))).k_) == (((uint8_t)6LL))); 
(void)(f245_ow(hr_str("{ ", 2)));
if (isenum_1863) { (void)(f246_ct(d_1861));
(void)(f245_ow(hr_str(" *_m", 4)));
(void)(f279_oi(p_1862));
(void)(f245_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t2674 = &(g524); int64_t _i2674 = st_1860; (S1*)_t2674->b + hr_ix(_i2674, _t2674->n, "hc/gen.amni:845"); }))).k_) == (((uint8_t)10LL)))) { (void)(f260_gx0(a_1859));
 } else { if (f257_is_place(a_1859)) { (void)(f245_ow(hr_str("&(", 2)));
(void)(f274_gx(a_1859));
(void)(f245_ow(hr_str(")", 1)));
 } else { int64_t k0_1864 = f258_tmp(d_1861, false); 
(void)(f245_ow(hr_str("&(", 2)));
(void)(f259_ot(k0_1864));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f254_gxo(a_1859));
(void)(f245_ow(hr_str(")", 1)));
 }
 }
(void)(f245_ow(hr_str("; ", 2)));
 } else { (void)(f246_ct(d_1861));
(void)(f245_ow(hr_str(" _m", 3)));
(void)(f279_oi(p_1862));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(a_1859));
(void)(f245_ow(hr_str("; ", 2)));
 }
bool first_1865 = true; 
{ int32_t _e2676 = (x_1858).n_; for (int32_t i_1866 = 0; i_1866 < _e2676; i_1866++) { int64_t arm_1867 = f90_kid(n_1856, ((int64_t)(i_1866))); 
S4 ar_1868 = (*({ hrv *_t2677 = &(g675); int64_t _i2677 = arm_1867; (S4*)_t2677->b + hr_ix(_i2677, _t2677->n, "hc/gen.amni:850"); })); 
if ((!(first_1865))) { (void)(f245_ow(hr_str(" else ", 6)));
 }
first_1865 = false;
if (((((uint16_t)((uint64_t)(ar_1868).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(f245_ow(hr_str("{ ", 2)));
(void)(f324_gblk(((int64_t)((ar_1868).b_)), res_1857, false));
(void)(f245_ow(hr_str(" }", 2)));
continue;
 }
(void)(f245_ow(hr_str("if (", 4)));
{ int32_t _e2679 = (ar_1868).n_; for (int32_t j_1869 = 0; j_1869 < _e2679; j_1869++) { if (((j_1869) > (((int32_t)0LL)))) { (void)(f245_ow(hr_str(" || ", 4)));
 }
int64_t it_1870 = f90_kid(arm_1867, ((int64_t)(j_1869))); 
int64_t lo_1871 = ((int64_t)(((*({ hrv *_t2680 = &(g675); int64_t _i2680 = it_1870; (S4*)_t2680->b + hr_ix(_i2680, _t2680->n, "hc/gen.amni:858"); }))).a_)); 
if (isenum_1863) { (void)(({ hrv *_o2681 = &(g163); hr_fs(_o2681, hr_str("_m", 2)); hr_fi(_o2681, p_1862); hr_fs(_o2681, hr_str("->tag == ", 9)); hr_fi(_o2681, f156_rv(lo_1871)); }));
 } else { if (((((*({ hrv *_t2682 = &(g675); int64_t _i2682 = it_1870; (S4*)_t2682->b + hr_ix(_i2682, _t2682->n, "hc/gen.amni:861"); }))).b_) >= (((int32_t)0LL)))) { (void)(({ hrv *_o2683 = &(g163); hr_fs(_o2683, hr_str("(_m", 3)); hr_fi(_o2683, p_1862); hr_fs(_o2683, hr_str(" >= ", 4)); }));
(void)(f274_gx(lo_1871));
(void)(({ hrv *_o2684 = &(g163); hr_fs(_o2684, hr_str(" && _m", 6)); hr_fi(_o2684, p_1862); hr_fs(_o2684, hr_str(" <= ", 4)); }));
(void)(f274_gx(((int64_t)(((*({ hrv *_t2685 = &(g675); int64_t _i2685 = it_1870; (S4*)_t2685->b + hr_ix(_i2685, _t2685->n, "hc/gen.amni:861"); }))).b_))));
(void)(f245_ow(hr_str(")", 1)));
 } else { if (((((f175_leaf_kind(d_1861)) == (((int64_t)0LL))) && ((((*({ hrv *_t2686 = &(g524); int64_t _i2686 = d_1861; (S1*)_t2686->b + hr_ix(_i2686, _t2686->n, "hc/gen.amni:862"); }))).k_) != (((uint8_t)3LL)))) && ((((*({ hrv *_t2687 = &(g524); int64_t _i2687 = d_1861; (S1*)_t2687->b + hr_ix(_i2687, _t2687->n, "hc/gen.amni:862"); }))).k_) != (((uint8_t)2LL))))) { (void)(f245_ow(hr_str("heq", 3)));
(void)(f279_oi(d_1861));
(void)(({ hrv *_o2688 = &(g163); hr_fs(_o2688, hr_str("(_m", 3)); hr_fi(_o2688, p_1862); hr_fs(_o2688, hr_str(", ", 2)); }));
(void)(f274_gx(lo_1871));
(void)(f245_ow(hr_str(")", 1)));
(void)(f280_gen_heq(d_1861));
 } else { (void)(({ hrv *_o2689 = &(g163); hr_fs(_o2689, hr_str("_m", 2)); hr_fi(_o2689, p_1862); hr_fs(_o2689, hr_str(" == ", 4)); }));
(void)(f274_gx(lo_1871));
 }
 }
 }
 } } _bk2678:; 
(void)(f245_ow(hr_str(") { ", 4)));
if (((((ar_1868).s_) >= (((int32_t)0LL))) && isenum_1863)) { int64_t v_1872 = f156_rv(arm_1867); 
int64_t vi_1873 = f156_rv(((int64_t)(((*({ hrv *_t2690 = &(g675); int64_t _i2690 = f90_kid(arm_1867, ((int64_t)0LL)); (S4*)_t2690->b + hr_ix(_i2690, _t2690->n, "hc/gen.amni:868"); }))).a_))); 
int64_t lt_1874 = ((int64_t)(((*({ hrv *_t2691 = &(g372); int64_t _i2691 = v_1872; (S12*)_t2691->b + hr_ix(_i2691, _t2691->n, "hc/gen.amni:869"); }))).ty_)); 
int64_t vt_1875 = f174_deref(lt_1874); 
int64_t ei_1876 = ((int64_t)(((*({ hrv *_t2692 = &(g524); int64_t _i2692 = d_1861; (S1*)_t2692->b + hr_ix(_i2692, _t2692->n, "hc/gen.amni:871"); }))).a_)); 
S9 vv_1877 = (*({ hrv *_t2693 = &(g530); int64_t _i2693 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2694 = &(g529); int64_t _i2694 = ei_1876; (S8*)_t2694->b + hr_ix(_i2694, _t2694->n, "hc/gen.amni:872"); }))).v0_)) + (int64_t)vi_1873)); (S9*)_t2693->b + hr_ix(_i2693, _t2693->n, "hc/gen.amni:872"); })); 
bool has_1878 = ((((vv_1877).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t2695 = &(g527); int64_t _i2695 = (vv_1877).si_; (S10*)_t2695->b + hr_ix(_i2695, _t2695->n, "hc/gen.amni:873"); }))).zero_))); 
(void)(f246_ct(lt_1874));
(void)(f245_ow(hr_str(" ", 1)));
(void)(f271_lv_name(v_1872));
(void)(f245_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t2696 = &(g524); int64_t _i2696 = lt_1874; (S1*)_t2696->b + hr_ix(_i2696, _t2696->n, "hc/gen.amni:875"); }))).k_) == (((uint8_t)10LL)))) { if (has_1878) { (void)(({ hrv *_o2697 = &(g163); hr_fs(_o2697, hr_str("&_m", 3)); hr_fi(_o2697, p_1862); hr_fs(_o2697, hr_str("->u.v", 5)); hr_fi(_o2697, vi_1873); hr_fs(_o2697, hr_str("; ", 2)); }));
 } else { (void)(f245_ow(hr_str("0; ", 3)));
 }
 } else { if (has_1878) { (void)(({ hrv *_o2698 = &(g163); hr_fs(_o2698, hr_str("_m", 2)); hr_fi(_o2698, p_1862); hr_fs(_o2698, hr_str("->u.v", 5)); hr_fi(_o2698, vi_1873); hr_fs(_o2698, hr_str("; ", 2)); }));
 } else { (void)(f245_ow(hr_str("0; ", 3)));
 }
 }
 }
(void)(f324_gblk(((int64_t)((ar_1868).b_)), res_1857, false));
(void)(f245_ow(hr_str(" }", 2)));
 } } _bk2675:; 
(void)(f245_ow(hr_str(" }", 2)));
}
static void f332_geblock(int64_t n_1879, int64_t res_1880) {
int64_t l_1881 = f327_lbl_push(res_1880); 
(void)(f245_ow(hr_str("{ ", 2)));
(void)(f324_gblk(((int64_t)(((*({ hrv *_t2699 = &(g675); int64_t _i2699 = n_1879; (S4*)_t2699->b + hr_ix(_i2699, _t2699->n, "hc/gen.amni:789"); }))).a_)), res_1880, false));
(void)(f245_ow(hr_str(" }", 2)));
(void)(f328_lbl_pop(l_1881));
}
static void f333_gret(int64_t n_1882) {
S4 x_1883 = (*({ hrv *_t2700 = &(g675); int64_t _i2700 = n_1882; (S4*)_t2700->b + hr_ix(_i2700, _t2700->n, "hc/gen.amni:948"); })); 
if (((f209_ax(n_1882)) >= (((int64_t)0LL)))) { (void)(f272_gerr(n_1882, hr_str("return from inside a block is not supported by the self-hosted compiler yet", 75)));
return;
 }
if ((((x_1883).n_) == (((int32_t)0LL)))) { (void)(f245_ow(hr_str("return;", 7)));
return;
 }
int64_t f_1884 = f212_ret_fn(); 
int64_t rt_1885 = ((int64_t)(((*({ hrv *_t2701 = &(g371); int64_t _i2701 = f_1884; (S6*)_t2701->b + hr_ix(_i2701, _t2701->n, "hc/gen.amni:952"); }))).ret_)); 
if ((((x_1883).n_) > (((int32_t)1LL)))) { (void)(f245_ow(hr_str("return (", 8)));
(void)(f246_ct(rt_1885));
(void)(f245_ow(hr_str("){ ", 3)));
{ int32_t _e2703 = (x_1883).n_; for (int32_t i_1886 = 0; i_1886 < _e2703; i_1886++) { if (((i_1886) > (((int32_t)0LL)))) { (void)(f245_ow(hr_str(", ", 2)));
 }
(void)(f274_gx(f90_kid(n_1882, ((int64_t)(i_1886)))));
 } } _bk2702:; 
(void)(f245_ow(hr_str(" };", 3)));
return;
 }
int64_t c_1887 = f90_kid(n_1882, ((int64_t)0LL)); 
if ((((((f253_is_res(rt_1885) && ((((*({ hrv *_t2704 = &(g675); int64_t _i2704 = c_1887; (S4*)_t2704->b + hr_ix(_i2704, _t2704->n, "hc/gen.amni:955"); }))).k_) == (((uint8_t)8LL)))) && ((f155_rk(c_1887)) == (((int64_t)1LL)))) && ((((int64_t)(((*({ hrv *_t2705 = &(g372); int64_t _i2705 = f156_rv(c_1887); (S12*)_t2705->b + hr_ix(_i2705, _t2705->n, "hc/gen.amni:955"); }))).cfn_))) == (g179))) && (!(f270_lv_isptr(f156_rv(c_1887))))) && ((((*({ hrv *_t2706 = &(g524); int64_t _i2706 = ((*({ hrv *_t2707 = &(g372); int64_t _i2707 = f156_rv(c_1887); (S12*)_t2707->b + hr_ix(_i2707, _t2707->n, "hc/gen.amni:955"); }))).ty_; (S1*)_t2706->b + hr_ix(_i2706, _t2706->n, "hc/gen.amni:955"); }))).k_) != (((uint8_t)10LL))))) { int64_t v_1888 = f156_rv(c_1887); 
(void)(f245_ow(hr_str("{ hrv _rv = ", 12)));
(void)(f271_lv_name(v_1888));
(void)(f245_ow(hr_str("; ", 2)));
(void)(f271_lv_name(v_1888));
(void)(f245_ow(hr_str(".b = 0; ", 8)));
(void)(f271_lv_name(v_1888));
(void)(f245_ow(hr_str(".n = 0; return _rv; }", 21)));
return;
 }
(void)(f245_ow(hr_str("return ", 7)));
if (f253_is_res(rt_1885)) { (void)(f254_gxo(c_1887));
 } else { (void)(f274_gx(c_1887));
 }
(void)(f245_ow(hr_str(";", 1)));
}
static void f334_gbreak(int64_t n_1889) {
S4 x_1890 = (*({ hrv *_t2708 = &(g675); int64_t _i2708 = n_1889; (S4*)_t2708->b + hr_ix(_i2708, _t2708->n, "hc/gen.amni:959"); })); 
if ((((g180).n) == (((int64_t)0LL)))) { (void)(f272_gerr(n_1889, hr_str("break outside a loop", 20)));
return;
 }
int64_t l_1891 = ((int64_t)((*({ hrv *_t2709 = &(g180); int64_t _i2709 = ((int64_t)((int64_t)(g180).n - (int64_t)((int64_t)1LL))); (int32_t*)_t2709->b + hr_ix(_i2709, _t2709->n, "hc/gen.amni:961"); })))); 
int64_t r_1892 = ((int64_t)((*({ hrv *_t2710 = &(g181); int64_t _i2710 = ((int64_t)((int64_t)(g181).n - (int64_t)((int64_t)1LL))); (int32_t*)_t2710->b + hr_ix(_i2710, _t2710->n, "hc/gen.amni:962"); })))); 
(void)(f245_ow(hr_str("{ ", 2)));
if ((((x_1890).a_) >= (((int32_t)0LL)))) { if (((r_1892) >= (((int64_t)0LL)))) { (void)(f245_ow(hr_str("_r", 2)));
(void)(f279_oi(r_1892));
(void)(f245_ow(hr_str(" = ", 3)));
(void)(f274_gx(((int64_t)((x_1890).a_))));
(void)(f245_ow(hr_str("; ", 2)));
 } else { (void)(f245_ow(hr_str("(void)(", 7)));
(void)(f274_gx(((int64_t)((x_1890).a_))));
(void)(f245_ow(hr_str("); ", 3)));
 }
 }
(void)(({ hrv *_o2711 = &(g163); hr_fs(_o2711, hr_str("goto _bk", 8)); hr_fi(_o2711, l_1891); hr_fs(_o2711, hr_str("; }", 3)); }));
}
static bool f335_owned(int64_t n_1893) {
return (f253_is_res(f264_fin(n_1893)) && (!(f257_is_place(n_1893))));
}
static bool f336_is_ext(int64_t i_1897) {
return ((((uint16_t)((uint64_t)((*({ hrv *_t2712 = &(g675); int64_t _i2712 = ((*({ hrv *_t2713 = &(g371); int64_t _i2713 = i_1897; (S6*)_t2713->b + hr_ix(_i2713, _t2713->n, "hc/gen.amni:555"); }))).node_; (S4*)_t2712->b + hr_ix(_i2712, _t2712->n, "hc/gen.amni:555"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)));
}
static void f337_ext_name(int64_t i_1898) {
int64_t node_1899 = ((int64_t)(((*({ hrv *_t2714 = &(g371); int64_t _i2714 = i_1898; (S6*)_t2714->b + hr_ix(_i2714, _t2714->n, "hc/gen.amni:550"); }))).node_)); 
int64_t x_1900 = ((int64_t)(((*({ hrv *_t2715 = &(g675); int64_t _i2715 = node_1899; (S4*)_t2715->b + hr_ix(_i2715, _t2715->n, "hc/gen.amni:551"); }))).e_)); 
if ((((x_1900) >= (((int64_t)0LL))) && ((((*({ hrv *_t2716 = &(g675); int64_t _i2716 = x_1900; (S4*)_t2716->b + hr_ix(_i2716, _t2716->n, "hc/gen.amni:552"); }))).a_) >= (((int32_t)0LL))))) { hsl s_1901 = f265_tok_str(((int64_t)(((*({ hrv *_t2717 = &(g675); int64_t _i2717 = x_1900; (S4*)_t2717->b + hr_ix(_i2717, _t2717->n, "hc/gen.amni:552"); }))).a_))); 
if (((((((s_1901).n) > (((int64_t)3LL))) && (((*({ hsl _t2718 = s_1901; int64_t _i2718 = ((int64_t)0LL); (uint8_t*)_t2718.p + hr_ix(_i2718, _t2718.n, "hc/gen.amni:552"); }))) == (((uint8_t)103LL)))) && (((*({ hsl _t2719 = s_1901; int64_t _i2719 = ((int64_t)1LL); (uint8_t*)_t2719.p + hr_ix(_i2719, _t2719.n, "hc/gen.amni:552"); }))) == (((uint8_t)115LL)))) && (((*({ hsl _t2720 = s_1901; int64_t _i2720 = ((int64_t)2LL); (uint8_t*)_t2720.p + hr_ix(_i2720, _t2720.n, "hc/gen.amni:552"); }))) == (((uint8_t)95LL))))) { (void)(f245_ow(hr_str("hr_", 3)));
(void)(f245_ow(({ hsl _t2721 = s_1901; int64_t _l2721 = ((int64_t)3LL), _h2721 = _t2721.n; if (_l2721 < 0 || _h2721 < _l2721 || _h2721 > _t2721.n) hr_slerr(_l2721, _h2721, _t2721.n, "hc/gen.amni:552"); (hsl){ _t2721.p + _l2721 * (int64_t)sizeof(uint8_t), _h2721 - _l2721 }; })));
return;
 }
(void)(f245_ow(s_1901));
return;
 }
(void)(f245_ow(f10_nm(((int64_t)(((*({ hrv *_t2722 = &(g675); int64_t _i2722 = node_1899; (S4*)_t2722->b + hr_ix(_i2722, _t2722->n, "hc/gen.amni:553"); }))).s_)))));
}
static void f338_fn_cname(int64_t i_1902) {
(void)(({ hrv *_o2723 = &(g163); hr_fs(_o2723, hr_str("f", 1)); hr_fi(_o2723, i_1902); hr_fs(_o2723, hr_str("_", 1)); }));
int64_t s_1903 = ((int64_t)(((*({ hrv *_t2724 = &(g371); int64_t _i2724 = i_1902; (S6*)_t2724->b + hr_ix(_i2724, _t2724->n, "hc/gen.amni:548"); }))).name_)); 
if (((s_1903) >= (((int64_t)0LL)))) { { hsl _v2726 = f10_nm(s_1903); for (int64_t _k2726 = 0; _k2726 < _v2726.n; _k2726++) { uint8_t c_1904 = ((uint8_t*)_v2726.p)[_k2726]; (void)(({ hrv *_v2727 = &(g163); uint8_t _x2727 = ({ uint8_t _r2728; if (((c_1904) == (((uint8_t)58LL)))) { _r2728 = ((uint8_t)95LL);  } else { _r2728 = c_1904;  } _r2728; }); uint8_t *_p2727 = (uint8_t*)hr_grow(_v2727, 1, sizeof _x2727); *_p2727 = _x2727; _p2727; }));
 } } _bk2725:; 
 }
}
static void f339_gcall_args(int64_t n_1905, int64_t inst_1906, int64_t recv_1907) {
S4 x_1908 = (*({ hrv *_t2729 = &(g675); int64_t _i2729 = n_1905; (S4*)_t2729->b + hr_ix(_i2729, _t2729->n, "hc/gen.amni:557"); })); 
int64_t np_1909 = ((int64_t)(((*({ hrv *_t2730 = &(g675); int64_t _i2730 = ((*({ hrv *_t2731 = &(g371); int64_t _i2731 = inst_1906; (S6*)_t2731->b + hr_ix(_i2731, _t2731->n, "hc/gen.amni:558"); }))).node_; (S4*)_t2730->b + hr_ix(_i2730, _t2730->n, "hc/gen.amni:558"); }))).n_)); 
int64_t na_1910 = ((int64_t)((int64_t)((int64_t)((x_1908).n_)) + (int64_t)({ int64_t _r2732; if (((recv_1907) >= (((int64_t)0LL)))) { _r2732 = ((int64_t)1LL);  } else { _r2732 = ((int64_t)0LL);  } _r2732; }))); 
bool first_1911 = true; 
{ int64_t _e2734 = np_1909; for (int64_t j_1912 = 0; j_1912 < _e2734; j_1912++) { int64_t pt_1913 = f201_ptype_of(inst_1906, j_1912); 
if ((!(first_1911))) { (void)(f245_ow(hr_str(", ", 2)));
 }
first_1911 = false;
if (((j_1912) >= (na_1910))) { int64_t p_1914 = f90_kid(((int64_t)(((*({ hrv *_t2735 = &(g371); int64_t _i2735 = inst_1906; (S6*)_t2735->b + hr_ix(_i2735, _t2735->n, "hc/gen.amni:566"); }))).node_)), j_1912); 
int64_t sa_1915 = g382; 
g382 = inst_1906;
(void)(f274_gx(((int64_t)(((*({ hrv *_t2736 = &(g675); int64_t _i2736 = p_1914; (S4*)_t2736->b + hr_ix(_i2736, _t2736->n, "hc/gen.amni:567"); }))).b_))));
g382 = sa_1915;
continue;
 }
int64_t c_1916 = ({ int64_t _r2737; if (((recv_1907) >= (((int64_t)0LL)))) { _r2737 = ({ int64_t _r2738; if (((j_1912) == (((int64_t)0LL)))) { _r2738 = recv_1907;  } else { _r2738 = f90_kid(n_1905, ((int64_t)((int64_t)j_1912 - (int64_t)((int64_t)1LL))));  } _r2738; });  } else { _r2737 = f90_kid(n_1905, j_1912);  } _r2737; }); 
int64_t ct0_1917 = f264_fin(c_1916); 
if ((((((*({ hrv *_t2739 = &(g524); int64_t _i2739 = pt_1913; (S1*)_t2739->b + hr_ix(_i2739, _t2739->n, "hc/gen.amni:572"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2740 = &(g524); int64_t _i2740 = pt_1913; (S1*)_t2740->b + hr_ix(_i2740, _t2740->n, "hc/gen.amni:572"); }))).c_) < (((int32_t)0LL))))) { if ((((((*({ hrv *_t2741 = &(g524); int64_t _i2741 = ct0_1917; (S1*)_t2741->b + hr_ix(_i2741, _t2741->n, "hc/gen.amni:573"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t2742 = &(g524); int64_t _i2742 = ct0_1917; (S1*)_t2742->b + hr_ix(_i2742, _t2742->n, "hc/gen.amni:573"); }))).k_) == (((uint8_t)11LL))))) { (void)(f274_gx(c_1916));
 } else { (void)(f309_gaddr(c_1916));
 }
continue;
 }
if (f253_is_res(pt_1913)) { (void)(f254_gxo(c_1916));
continue;
 }
if (((((*({ hrv *_t2743 = &(g524); int64_t _i2743 = pt_1913; (S1*)_t2743->b + hr_ix(_i2743, _t2743->n, "hc/gen.amni:577"); }))).k_) == (((uint8_t)9LL)))) { (void)(f276_gas(c_1916));
continue;
 }
(void)(f274_gx(c_1916));
 } } _bk2733:; 
{ hrv *_v2745 = &(g374); for (int64_t _k2745 = 0; _k2745 < _v2745->n; _k2745++) { S13 cp_1918 = ((S13*)_v2745->b)[_k2745]; if (((((int64_t)((cp_1918).inst_))) == (inst_1906))) { if ((!(first_1911))) { (void)(f245_ow(hr_str(", ", 2)));
 }
first_1911 = false;
(void)(f340_lv_addr(((int64_t)((cp_1918).lv_))));
 }
 } } _bk2744:; 
}
static void f340_lv_addr(int64_t v_1919) {
if (((((int64_t)(((*({ hrv *_t2746 = &(g372); int64_t _i2746 = v_1919; (S12*)_t2746->b + hr_ix(_i2746, _t2746->n, "hc/gen.amni:119"); }))).cfn_))) != (g179))) { (void)(({ hrv *_o2747 = &(g163); hr_fs(_o2747, hr_str("c", 1)); hr_fi(_o2747, v_1919); }));
return;
 }
(void)(f245_ow(hr_str("&", 1)));
(void)(f271_lv_name(v_1919));
}
static void f341_gen_fn(int64_t i_1934) {
int64_t node_1935 = ((int64_t)(((*({ hrv *_t2748 = &(g371); int64_t _i2748 = i_1934; (S6*)_t2748->b + hr_ix(_i2748, _t2748->n, "hc/gen.amni:1025"); }))).node_)); 
g382 = i_1934;
g179 = i_1934;
(void)(({ hrv *_v2749 = &(g180); _v2749->n = 0; }));
(void)(({ hrv *_v2750 = &(g181); _v2750->n = 0; }));
int64_t s0_1936 = (g163).n; 
(void)(f342_gsig(i_1934));
(void)(({ hrv *_v2751 = &(g166); hsl _s2751 = ({ hsl _t2752 = hr_sl(g163); int64_t _l2752 = s0_1936, _h2752 = _t2752.n; if (_l2752 < 0 || _h2752 < _l2752 || _h2752 > _t2752.n) hr_slerr(_l2752, _h2752, _t2752.n, "hc/gen.amni:1030"); (hsl){ _t2752.p + _l2752 * (int64_t)sizeof(uint8_t), _h2752 - _l2752 }; }); hr_append(_v2751, _s2751.p, _s2751.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2753 = &(g166); hsl _s2753 = hr_str(";\012", 2); hr_append(_v2753, _s2753.p, _s2753.n, sizeof(uint8_t)); }));
(void)(f245_ow(hr_str(" {\012", 3)));
{ int32_t _e2755 = ((*({ hrv *_t2756 = &(g675); int64_t _i2756 = node_1935; (S4*)_t2756->b + hr_ix(_i2756, _t2756->n, "hc/gen.amni:1032"); }))).n_; for (int32_t j_1948 = 0; j_1948 < _e2755; j_1948++) { int64_t p_1949 = f90_kid(node_1935, ((int64_t)(j_1948))); 
int64_t v_1950 = f156_rv(p_1949); 
if (f253_is_res(f201_ptype_of(i_1934, ((int64_t)(j_1948))))) { (void)(f245_ow(hr_str("hrv ", 4)));
(void)(f271_lv_name(v_1950));
(void)(f245_ow(hr_str(" __attribute__((cleanup(hr_rdrop))) = ", 38)));
(void)(f271_lv_name(v_1950));
(void)(f245_ow(hr_str("_in;\012", 5)));
 }
 } } _bk2754:; 
int64_t body_1951 = ((int64_t)(((*({ hrv *_t2757 = &(g675); int64_t _i2757 = node_1935; (S4*)_t2757->b + hr_ix(_i2757, _t2757->n, "hc/gen.amni:1033"); }))).c_)); 
int64_t rt_1952 = ((int64_t)(((*({ hrv *_t2758 = &(g371); int64_t _i2758 = i_1934; (S6*)_t2758->b + hr_ix(_i2758, _t2758->n, "hc/gen.amni:1034"); }))).ret_)); 
int64_t tl_1953 = ((int64_t)(((*({ hrv *_t2759 = &(g675); int64_t _i2759 = body_1951; (S4*)_t2759->b + hr_ix(_i2759, _t2759->n, "hc/gen.amni:1035"); }))).a_)); 
{ int32_t _e2761 = ((*({ hrv *_t2762 = &(g675); int64_t _i2762 = body_1951; (S4*)_t2762->b + hr_ix(_i2762, _t2762->n, "hc/gen.amni:1036"); }))).n_; for (int32_t q_1954 = 0; q_1954 < _e2761; q_1954++) { (void)(f317_gstmt(f90_kid(body_1951, ((int64_t)(q_1954)))));
 } } _bk2760:; 
if (((tl_1953) >= (((int64_t)0LL)))) { if ((((((rt_1952) >= (((int64_t)0LL))) && ((rt_1952) != (g531))) && ((f140_at(tl_1953)) != (g531))) && (!(f202_ends(tl_1953))))) { int64_t sp_1955 = (g163).n; 
int64_t td_1956 = (g176).n; 
if (((((f253_is_res(rt_1952) && ((((*({ hrv *_t2763 = &(g675); int64_t _i2763 = tl_1953; (S4*)_t2763->b + hr_ix(_i2763, _t2763->n, "hc/gen.amni:1040"); }))).k_) == (((uint8_t)8LL)))) && ((f155_rk(tl_1953)) == (((int64_t)1LL)))) && ((((int64_t)(((*({ hrv *_t2764 = &(g372); int64_t _i2764 = f156_rv(tl_1953); (S12*)_t2764->b + hr_ix(_i2764, _t2764->n, "hc/gen.amni:1040"); }))).cfn_))) == (i_1934))) && (!(f270_lv_isptr(f156_rv(tl_1953)))))) { int64_t v_1957 = f156_rv(tl_1953); 
(void)(f245_ow(hr_str("{ hrv _rv = ", 12)));
(void)(f271_lv_name(v_1957));
(void)(f245_ow(hr_str("; ", 2)));
(void)(f271_lv_name(v_1957));
(void)(f245_ow(hr_str(".b = 0; ", 8)));
(void)(f271_lv_name(v_1957));
(void)(f245_ow(hr_str(".n = 0; return _rv; }\012", 22)));
 } else { (void)(f245_ow(hr_str("return ", 7)));
if (f253_is_res(rt_1952)) { (void)(f254_gxo(tl_1953));
 } else { (void)(f274_gx(tl_1953));
 }
(void)(f245_ow(hr_str(";\012", 2)));
 }
if ((((g176).n) > (td_1956))) { (void)(({ hrv *_v2765 = &(g177); _v2765->n = 0; }));
(void)(({ hrv *_v2766 = &(g177); hsl _s2766 = ({ hsl _t2767 = hr_sl(g163); int64_t _l2767 = sp_1955, _h2767 = _t2767.n; if (_l2767 < 0 || _h2767 < _l2767 || _h2767 > _t2767.n) hr_slerr(_l2767, _h2767, _t2767.n, "hc/gen.amni:1042"); (hsl){ _t2767.p + _l2767 * (int64_t)sizeof(uint8_t), _h2767 - _l2767 }; }); hr_append(_v2766, _s2766.p, _s2766.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2768 = &(g163); int64_t _k2768 = sp_1955; if (_k2768 < 0) hr_die("resize to a negative length", "hc/gen.amni:1042"); hr_resize(_v2768, _k2768, sizeof(uint8_t)); }));
(void)(f245_ow(hr_str("{ ", 2)));
(void)(({ hrv *_v2769 = &(g163); hsl _s2769 = ({ hsl _t2770 = hr_sl(g176); int64_t _l2770 = td_1956, _h2770 = _t2770.n; if (_l2770 < 0 || _h2770 < _l2770 || _h2770 > _t2770.n) hr_slerr(_l2770, _h2770, _t2770.n, "hc/gen.amni:1042"); (hsl){ _t2770.p + _l2770 * (int64_t)sizeof(uint8_t), _h2770 - _l2770 }; }); hr_append(_v2769, _s2769.p, _s2769.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2771 = &(g176); int64_t _k2771 = td_1956; if (_k2771 < 0) hr_die("resize to a negative length", "hc/gen.amni:1042"); hr_resize(_v2771, _k2771, sizeof(uint8_t)); }));
(void)(({ hrv *_v2772 = &(g163); hsl _s2772 = ({ hsl _t2773 = hr_sl(g177); int64_t _l2773 = 0, _h2773 = _t2773.n; if (_l2773 < 0 || _h2773 < _l2773 || _h2773 > _t2773.n) hr_slerr(_l2773, _h2773, _t2773.n, "hc/gen.amni:1042"); (hsl){ _t2773.p + _l2773 * (int64_t)sizeof(uint8_t), _h2773 - _l2773 }; }); hr_append(_v2772, _s2772.p, _s2772.n, sizeof(uint8_t)); }));
(void)(f245_ow(hr_str("}\012", 2)));
 }
 } else { (void)(f317_gstmt(tl_1953));
 }
 }
(void)(f245_ow(hr_str("}\012", 2)));
}
static void f342_gsig(int64_t i_1937) {
int64_t rt_1938 = ((int64_t)(((*({ hrv *_t2774 = &(g371); int64_t _i2774 = i_1937; (S6*)_t2774->b + hr_ix(_i2774, _t2774->n, "hc/gen.amni:1004"); }))).ret_)); 
(void)(f245_ow(hr_str("static ", 7)));
if (((rt_1938) < (((int64_t)0LL)))) { (void)(f245_ow(hr_str("void", 4)));
 } else { (void)(f246_ct(rt_1938));
 }
(void)(f245_ow(hr_str(" ", 1)));
(void)(f338_fn_cname(i_1937));
(void)(f245_ow(hr_str("(", 1)));
int64_t node_1939 = ((int64_t)(((*({ hrv *_t2775 = &(g371); int64_t _i2775 = i_1937; (S6*)_t2775->b + hr_ix(_i2775, _t2775->n, "hc/gen.amni:1008"); }))).node_)); 
bool first_1940 = true; 
int64_t sa_1941 = g382; 
g382 = i_1937;
{ int32_t _e2777 = ((*({ hrv *_t2778 = &(g675); int64_t _i2778 = node_1939; (S4*)_t2778->b + hr_ix(_i2778, _t2778->n, "hc/gen.amni:1011"); }))).n_; for (int32_t j_1942 = 0; j_1942 < _e2777; j_1942++) { int64_t p_1943 = f90_kid(node_1939, ((int64_t)(j_1942))); 
int64_t v_1944 = f156_rv(p_1943); 
if ((!(first_1940))) { (void)(f245_ow(hr_str(", ", 2)));
 }
first_1940 = false;
int64_t t_1945 = f201_ptype_of(i_1937, ((int64_t)(j_1942))); 
(void)(f246_ct(t_1945));
(void)(f245_ow(hr_str(" ", 1)));
(void)(f271_lv_name(v_1944));
if (f253_is_res(t_1945)) { (void)(f245_ow(hr_str("_in", 3)));
 }
 } } _bk2776:; 
g382 = sa_1941;
{ hrv *_v2780 = &(g374); for (int64_t _k2780 = 0; _k2780 < _v2780->n; _k2780++) { S13 cp_1946 = ((S13*)_v2780->b)[_k2780]; if (((((int64_t)((cp_1946).inst_))) == (i_1937))) { if ((!(first_1940))) { (void)(f245_ow(hr_str(", ", 2)));
 }
first_1940 = false;
int64_t v_1947 = ((int64_t)((cp_1946).lv_)); 
(void)(f246_ct(((int64_t)(((*({ hrv *_t2781 = &(g372); int64_t _i2781 = v_1947; (S12*)_t2781->b + hr_ix(_i2781, _t2781->n, "hc/gen.amni:1020"); }))).ty_))));
(void)(f245_ow(({ hsl _r2782; if (f270_lv_isptr(v_1947)) { _r2782 = hr_str(" **c", 4);  } else { _r2782 = hr_str(" *c", 3);  } _r2782; })));
(void)(f279_oi(v_1947));
 }
 } } _bk2779:; 
if (first_1940) { (void)(f245_ow(hr_str("void", 4)));
 }
(void)(f245_ow(hr_str(")", 1)));
}
static void hr_init_globals(void) {
g825 = ({ A25 _t1; _t1.e[0] = hr_str("import", 6); _t1.e[1] = hr_str("namespace", 9); _t1.e[2] = hr_str("struct", 6); _t1.e[3] = hr_str("enum", 4); _t1.e[4] = hr_str("type", 4); _t1.e[5] = hr_str("fn", 2); _t1.e[6] = hr_str("thread_fn", 9); _t1.e[7] = hr_str("export", 6); _t1.e[8] = hr_str("simd", 4); _t1.e[9] = hr_str("recursive", 9); _t1.e[10] = hr_str("let", 3); _t1.e[11] = hr_str("var", 3); _t1.e[12] = hr_str("extern", 6); _t1.e[13] = hr_str("const", 5); _t1.e[14] = hr_str("pad", 3); _t1.e[15] = hr_str("reusable", 8); _t1.e[16] = hr_str("if", 2); _t1.e[17] = hr_str("else", 4); _t1.e[18] = hr_str("while", 5); _t1.e[19] = hr_str("for", 3); _t1.e[20] = hr_str("in", 2); _t1.e[21] = hr_str("loop", 4); _t1.e[22] = hr_str("block", 5); _t1.e[23] = hr_str("guard", 5); _t1.e[24] = hr_str("match", 5); _t1.e[25] = hr_str("return", 6); _t1.e[26] = hr_str("break", 5); _t1.e[27] = hr_str("continue", 8); _t1.e[28] = hr_str("as", 2); _t1.e[29] = hr_str("true", 4); _t1.e[30] = hr_str("false", 5); _t1.e[31] = hr_str("null", 4); _t1.e[32] = hr_str("self", 4); _t1.e[33] = hr_str("bool", 4); _t1.e[34] = hr_str("varint", 6); _t1.e[35] = hr_str("i8", 2); _t1.e[36] = hr_str("i16", 3); _t1.e[37] = hr_str("i32", 3); _t1.e[38] = hr_str("i64", 3); _t1.e[39] = hr_str("u8", 2); _t1.e[40] = hr_str("u16", 3); _t1.e[41] = hr_str("u32", 3); _t1.e[42] = hr_str("u64", 3); _t1.e[43] = hr_str("f32", 3); _t1.e[44] = hr_str("f64", 3); _t1.e[45] = hr_str("int", 3); _t1.e[46] = hr_str("uint", 4); _t1.e[47] = hr_str("byte", 4); _t1.e[48] = hr_str("real", 4); _t1; });
g692 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g693 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g694 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g695 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g696 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g697 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g698 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g699 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g700 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g701 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g688 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g687 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g384 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g382 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g383 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g179 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g183 = ({ A61 _t2; _t2.e[0] = hr_str("int8_t", 6); _t2.e[1] = hr_str("int16_t", 7); _t2.e[2] = hr_str("int32_t", 7); _t2.e[3] = hr_str("int64_t", 7); _t2.e[4] = hr_str("uint8_t", 7); _t2.e[5] = hr_str("uint16_t", 8); _t2.e[6] = hr_str("uint32_t", 8); _t2.e[7] = hr_str("uint64_t", 8); _t2; });
g114 = ({ A97 _t3; _t3.e[0] = ((double)1e0); _t3.e[1] = ((double)1e1); _t3.e[2] = ((double)1e2); _t3.e[3] = ((double)1e3); _t3.e[4] = ((double)1e4); _t3.e[5] = ((double)1e5); _t3.e[6] = ((double)1e6); _t3.e[7] = ((double)1e7); _t3.e[8] = ((double)1e8); _t3.e[9] = ((double)1e9); _t3.e[10] = ((double)1e10); _t3.e[11] = ((double)1e11); _t3.e[12] = ((double)1e12); _t3.e[13] = ((double)1e13); _t3.e[14] = ((double)1e14); _t3.e[15] = ((double)1e15); _t3.e[16] = ((double)1e16); _t3.e[17] = ((double)1e17); _t3.e[18] = ((double)1e18); _t3.e[19] = ((double)1e19); _t3.e[20] = ((double)1e20); _t3.e[21] = ((double)1e21); _t3.e[22] = ((double)1e22); _t3; });
g154 = ((hrv){0});
g284 = ((int64_t)1LL);
g285 = ((int64_t)2LL);
g286 = ((int64_t)3LL);
g287 = ((int64_t)4LL);
g288 = ((int64_t)5LL);
g289 = ((int64_t)6LL);
g290 = ((int64_t)7LL);
g291 = ((int64_t)8LL);
g292 = ((int64_t)9LL);
g293 = ((int64_t)20LL);
g294 = ((int64_t)21LL);
g295 = ((int64_t)22LL);
g296 = ((int64_t)23LL);
g297 = ((int64_t)24LL);
g298 = ((int64_t)25LL);
g299 = ((int64_t)26LL);
g300 = ((int64_t)27LL);
g301 = ((int64_t)30LL);
g302 = ((int64_t)31LL);
g303 = ((int64_t)32LL);
g304 = ((int64_t)33LL);
g347 = ((int64_t)0LL);
g348 = ((int64_t)1LL);
g349 = ((int64_t)2LL);
g350 = ((int64_t)3LL);
g351 = ((int64_t)4LL);
g352 = ((int64_t)5LL);
g353 = ((int64_t)6LL);
g354 = ((int64_t)7LL);
g355 = ((int64_t)8LL);
g356 = ((int64_t)9LL);
g357 = ((int64_t)10LL);
g358 = ((int64_t)11LL);
g359 = ((int64_t)12LL);
g360 = ((int64_t)13LL);
g361 = ((int64_t)1LL);
g362 = ((int64_t)2LL);
g363 = ((int64_t)4LL);
g364 = ((int64_t)8LL);
g365 = ((int64_t)16LL);
g366 = ((int64_t)32LL);
g367 = ((int64_t)2LL);
g381 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g387 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g457 = ((int64_t)1LL);
g458 = ((int64_t)2LL);
g459 = ((int64_t)3LL);
g460 = ((int64_t)4LL);
g461 = ((int64_t)5LL);
g494 = ((int64_t)0LL);
g495 = ((int64_t)1LL);
g496 = ((int64_t)2LL);
g497 = ((int64_t)3LL);
g498 = ((int64_t)4LL);
g499 = ((int64_t)5LL);
g500 = ((int64_t)6LL);
g501 = ((int64_t)7LL);
g502 = ((int64_t)8LL);
g503 = ((int64_t)9LL);
g504 = ((int64_t)10LL);
g505 = ((int64_t)11LL);
g506 = ((int64_t)12LL);
g507 = ((int64_t)13LL);
g508 = ((int64_t)14LL);
g509 = ((int64_t)15LL);
g510 = ((int64_t)16LL);
g511 = ((int64_t)17LL);
g512 = ((int64_t)18LL);
g513 = ((int64_t)19LL);
g514 = ((int64_t)1LL);
g515 = ((int64_t)2LL);
g516 = ((int64_t)0LL);
g517 = ((int64_t)1LL);
g518 = ((int64_t)2LL);
g597 = ((int64_t)1LL);
g598 = ((int64_t)2LL);
g599 = ((int64_t)3LL);
g600 = ((int64_t)4LL);
g601 = ((int64_t)5LL);
g602 = ((int64_t)6LL);
g603 = ((int64_t)7LL);
g604 = ((int64_t)8LL);
g605 = ((int64_t)9LL);
g606 = ((int64_t)10LL);
g607 = ((int64_t)11LL);
g608 = ((int64_t)12LL);
g609 = ((int64_t)13LL);
g610 = ((int64_t)14LL);
g611 = ((int64_t)15LL);
g612 = ((int64_t)16LL);
g613 = ((int64_t)17LL);
g614 = ((int64_t)18LL);
g615 = ((int64_t)19LL);
g616 = ((int64_t)20LL);
g617 = ((int64_t)21LL);
g618 = ((int64_t)22LL);
g619 = ((int64_t)23LL);
g620 = ((int64_t)24LL);
g621 = ((int64_t)25LL);
g622 = ((int64_t)26LL);
g623 = ((int64_t)27LL);
g624 = ((int64_t)28LL);
g625 = ((int64_t)29LL);
g626 = ((int64_t)30LL);
g627 = ((int64_t)31LL);
g628 = ((int64_t)32LL);
g629 = ((int64_t)33LL);
g630 = ((int64_t)34LL);
g631 = ((int64_t)35LL);
g632 = ((int64_t)36LL);
g633 = ((int64_t)37LL);
g634 = ((int64_t)40LL);
g635 = ((int64_t)41LL);
g636 = ((int64_t)42LL);
g637 = ((int64_t)43LL);
g638 = ((int64_t)44LL);
g639 = ((int64_t)45LL);
g640 = ((int64_t)46LL);
g641 = ((int64_t)47LL);
g642 = ((int64_t)48LL);
g643 = ((int64_t)50LL);
g644 = ((int64_t)51LL);
g645 = ((int64_t)52LL);
g646 = ((int64_t)53LL);
g647 = ((int64_t)54LL);
g648 = ((int64_t)55LL);
g649 = ((int64_t)56LL);
g650 = ((int64_t)57LL);
g651 = ((int64_t)58LL);
g652 = ((int64_t)1LL);
g653 = ((int64_t)2LL);
g654 = ((int64_t)3LL);
g655 = ((int64_t)4LL);
g656 = ((int64_t)5LL);
g657 = ((int64_t)1LL);
g658 = ((int64_t)2LL);
g659 = ((int64_t)4LL);
g660 = ((int64_t)8LL);
g661 = ((int64_t)16LL);
g662 = ((int64_t)32LL);
g663 = ((int64_t)64LL);
g664 = ((int64_t)128LL);
g665 = ((int64_t)256LL);
g666 = ((int64_t)512LL);
g667 = ((int64_t)1LL);
g668 = ((int64_t)2LL);
g669 = ((int64_t)4LL);
g670 = ((int64_t)8LL);
g671 = ((int64_t)16LL);
g672 = ((int64_t)32LL);
g673 = ((int64_t)64LL);
g768 = ((int64_t)0LL);
g769 = ((int64_t)1LL);
g770 = ((int64_t)2LL);
g771 = ((int64_t)3LL);
g772 = ((int64_t)4LL);
g773 = ((int64_t)5LL);
g774 = ((int64_t)6LL);
g775 = ((int64_t)7LL);
g776 = ((int64_t)8LL);
g777 = ((int64_t)9LL);
g778 = ((int64_t)10LL);
g779 = ((int64_t)11LL);
g780 = ((int64_t)12LL);
g781 = ((int64_t)13LL);
g782 = ((int64_t)14LL);
g783 = ((int64_t)15LL);
g784 = ((int64_t)16LL);
g785 = ((int64_t)17LL);
g786 = ((int64_t)18LL);
g787 = ((int64_t)19LL);
g788 = ((int64_t)20LL);
g789 = ((int64_t)21LL);
g790 = ((int64_t)22LL);
g791 = ((int64_t)23LL);
g792 = ((int64_t)24LL);
g793 = ((int64_t)25LL);
g794 = ((int64_t)26LL);
g795 = ((int64_t)27LL);
g796 = ((int64_t)28LL);
g797 = ((int64_t)29LL);
g798 = ((int64_t)30LL);
g799 = ((int64_t)31LL);
g800 = ((int64_t)32LL);
g801 = ((int64_t)33LL);
g802 = ((int64_t)34LL);
g803 = ((int64_t)35LL);
g804 = ((int64_t)36LL);
g805 = ((int64_t)37LL);
g806 = ((int64_t)38LL);
g807 = ((int64_t)39LL);
g808 = ((int64_t)40LL);
g809 = ((int64_t)41LL);
g810 = ((int64_t)42LL);
g811 = ((int64_t)43LL);
g812 = ((int64_t)44LL);
g813 = ((int64_t)45LL);
g814 = ((int64_t)46LL);
g815 = ((int64_t)47LL);
g816 = ((int64_t)48LL);
g817 = ((int64_t)49LL);
g818 = ((int64_t)50LL);
g819 = ((int64_t)51LL);
g820 = ((int64_t)52LL);
g821 = ((int64_t)53LL);
g822 = ((int64_t)54LL);
g823 = ((int64_t)55LL);
g824 = ((int64_t)56LL);
g826 = ((int64_t)56LL);
g827 = ((int64_t)57LL);
g828 = ((int64_t)58LL);
g829 = ((int64_t)59LL);
g830 = ((int64_t)60LL);
g831 = ((int64_t)61LL);
g832 = ((int64_t)62LL);
g833 = ((int64_t)63LL);
g834 = ((int64_t)64LL);
g835 = ((int64_t)65LL);
g836 = ((int64_t)66LL);
g837 = ((int64_t)67LL);
g838 = ((int64_t)68LL);
g839 = ((int64_t)69LL);
g840 = ((int64_t)70LL);
g841 = ((int64_t)71LL);
g842 = ((int64_t)72LL);
g843 = ((int64_t)73LL);
g844 = ((int64_t)74LL);
g845 = ((int64_t)75LL);
g846 = ((int64_t)76LL);
g847 = ((int64_t)77LL);
g848 = ((int64_t)78LL);
g849 = ((int64_t)79LL);
g850 = ((int64_t)80LL);
g851 = ((int64_t)81LL);
g852 = ((int64_t)82LL);
g853 = ((int64_t)83LL);
g854 = ((int64_t)84LL);
g855 = ((int64_t)85LL);
g856 = ((int64_t)86LL);
g857 = ((int64_t)87LL);
g858 = ((int64_t)88LL);
g859 = ((int64_t)89LL);
g860 = ((int64_t)90LL);
g861 = ((int64_t)91LL);
g862 = ((int64_t)92LL);
g863 = ((int64_t)93LL);
g864 = ((int64_t)94LL);
g865 = ((int64_t)95LL);
g866 = ((int64_t)96LL);
g867 = ((int64_t)97LL);
g868 = ((int64_t)98LL);
g869 = ((int64_t)99LL);
g870 = ((int64_t)100LL);
g871 = ((int64_t)101LL);
g872 = ((int64_t)102LL);
g873 = ((int64_t)103LL);
g874 = ((int64_t)104LL);
g875 = ((int64_t)49LL);
}
static void hr_main(void) { f1_main(); }
