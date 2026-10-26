#include "hrt.h"
typedef struct A25 A25;
typedef struct A62 A62;
typedef struct A98 A98;
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
typedef struct L66 L66;
typedef struct M56 M56;
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
typedef struct L89 L89;
typedef struct L90 L90;
typedef struct M91 M91;
typedef struct L94 L94;
typedef struct L95 L95;
typedef struct L97 L97;
typedef struct L96 L96;
#pragma pack(push, 1)
struct A25 { hsl e[49]; };
struct A62 { hsl e[8]; };
struct A98 { double e[23]; };
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
struct L66 { uint8_t n; int32_t e[16]; };
struct M56 { int64_t r0; int64_t r1; bool r2; };
struct M57 { int64_t r0; int64_t r1; };
struct S10 { int32_t node_; int32_t ta_; int32_t tn_; int32_t f0_; int32_t fnum_; uint8_t cls_; uint8_t done_; bool flat_; bool zero_; int64_t size_; int32_t name_; };
struct S7 { int32_t name_; int32_t ty_; };
struct S11 { int32_t name_; int32_t ty_; int32_t def_; uint16_t fl_; int32_t padn_; int64_t off_; };
struct L73 { uint16_t n; S11 e[256]; };
struct M78 { int64_t r0; bool r1; bool r2; };
struct S12 { int32_t name_; int32_t ty_; uint16_t fl_; int32_t cfn_; int32_t own_; int32_t node_; int32_t cnt_; };
struct S13 { int32_t inst_; int32_t lv_; };
struct L84 { uint8_t n; int32_t e[1]; };
struct S14 { int32_t name_; int32_t node_; int32_t inst_; int32_t own_; };
struct L89 { uint8_t n; int32_t e[128]; };
struct L90 { uint8_t n; int32_t e[64]; };
struct M91 { int64_t r0; int64_t r1; int64_t r2; };
struct L94 { uint16_t n; uint8_t e[256]; };
struct L95 { uint8_t n; uint8_t e[128]; };
struct L97 { uint8_t n; uint8_t e[64]; };
struct L96 { uint8_t n; uint8_t e[32]; };
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
static M56 f119_ceval3(int64_t n_524, int64_t ns_525);
static int64_t f120_cwrap(int64_t v_532, int64_t c_533);
static int64_t f121_lookup_q(int64_t q_555, int64_t ns_556, int64_t k_557);
static M57 f122_split_q(int64_t q_558);
static int64_t f123_t_arr(int64_t e_583, int64_t ak_584, int64_t size_585, int64_t ls_586);
static int64_t f124_lim_lenstore(int64_t cap_589);
static int64_t f125_t_variant(int64_t ei_594, int64_t vi_595);
static hrv f126_ty_name(int64_t t_597);
static void f127_ty_name_into(int64_t t_599, hrv* out_600);
static void f128_ls_kind_name(int64_t s_603, hrv* out_604);
static void f129_targs_into(int64_t l_606, int64_t n_607, hrv* out_608);
static int64_t f130_gb_find(int64_t name_613);
static int64_t f131_inst_struct(int64_t node_620, hsl args_621);
static void f132_gen_names(int64_t gl_629, L66* out_630);
static int64_t f133_fields_into(int64_t node_634, int64_t ns_635);
static int32_t f134_max(int32_t a_640, int32_t b_641);
static int64_t f135_t_struct(int64_t si_645);
static int64_t f136_inst_enum(int64_t node_646, hsl args_647);
static int64_t f137_t_enum(int64_t ei_666, bool vm_667);
static int64_t f138_ck(int64_t n_671, int64_t want_672);
static int64_t f139_set_t(int64_t n_675, int64_t t_676);
static int64_t f140_aix(int64_t n_677);
static bool f141_conv(int64_t n_681, int64_t t_682);
static int64_t f142_at(int64_t n_683);
static int64_t f143_tclass(int64_t t_687);
static void f144_si_layout(int64_t si_690);
static int64_t f145_tsize(int64_t t_698);
static int64_t f146_isz(int64_t s_701);
static void f147_ei_layout(int64_t ei_702);
static bool f148_tflat(int64_t t_714);
static int64_t f149_cv(int64_t n_721);
static void f150_set_cv(int64_t n_722, int64_t t_723);
static bool f151_conv_ok(int64_t f_724, int64_t t_725, int64_t n_726);
static bool f152_widens(int64_t f_729, int64_t t_730);
static bool f153_is_signed(int64_t t_733);
static int64_t f154_ibits(int64_t t_736);
static bool f155_is_construct(int64_t n_737);
static M78 f156_cval(int64_t n_739);
static int64_t f157_rk(int64_t n_745);
static int64_t f158_rv(int64_t n_746);
static bool f159_int_fits(int64_t v_757, bool uns_758, int64_t t_759);
static int64_t f160_int_min(int64_t t_760);
static uint64_t f161_int_max_u(int64_t t_762);
static hrv f162_tn(int64_t t_766);
static void f163_commit(int64_t n_767, int64_t t_768);
static bool f164_is_pending(int64_t t_772);
static bool f165_is_byte_arr(int64_t t_778);
static bool f166_is_opt(int64_t t_781);
static int64_t f167_ck_id(int64_t n_782, int64_t want_783);
static int64_t f168_find_lv(int64_t name_785);
static bool f169_visible(int64_t own_788);
static void f170_set_r(int64_t n_791, int64_t k_792, int64_t v_793);
static void f171_note_cap(int64_t v_795);
static int64_t f172_const_of(int64_t d_801);
static bool f173_all_int(int64_t n_809);
static void f174_set_x(int64_t n_814, int64_t v_815);
static int64_t f175_ck_bin(int64_t n_817, int64_t want_818);
static int64_t f176_deref(int64_t t_826);
static int64_t f177_leaf_kind(int64_t t_831);
static int64_t f178_leaf_type(int64_t t_841);
static int64_t f179_unify(int64_t n_850, int64_t a_851, int64_t b_852);
static int64_t f180_ck_un(int64_t n_863, int64_t want_864);
static int64_t f181_default_t(int64_t n_869);
static int64_t f182_ck_dot(int64_t n_890, int64_t want_891);
static int64_t f183_rtype_name_enum(int64_t de_897);
static int64_t f184_sfield(int64_t si_909, int64_t name_910);
static int64_t f185_ck_idx(int64_t n_917, int64_t want_918);
static int64_t f186_ck_slice(int64_t n_926, int64_t want_927);
static int64_t f187_ck_as(int64_t n_933, int64_t want_934);
static int64_t f188_ck_arr(int64_t n_939, int64_t want_940);
static int64_t f189_ck_block(int64_t n_948, int64_t want_949);
static void f190_cstmt(int64_t n_953);
static void f191_ck_vdecl(int64_t n_956);
static int64_t f192_fin_t(int64_t n_969);
static int64_t f193_add_lv(int64_t name_971, int64_t t_972, int64_t fl_973, int64_t node_974);
static bool f194_is_fixed(int64_t t_982);
static void f195_ck_assign(int64_t n_984);
static void f196_decl_nested(int64_t n_999);
static void f197_sig_inst(int64_t i_1001);
static int64_t f198_upname(int64_t p_1011);
static int64_t f199_tlist(int64_t k_1017, hsl xs_1018, int64_t a_1019);
static bool f200_surely_void(int64_t fnode_1021);
static bool f201_has_valret(int64_t n_1025);
static void f202_check_inst(int64_t i_1029);
static int64_t f203_ptype_of(int64_t i_1041, int64_t j_1042);
static bool f204_ends(int64_t n_1051);
static bool f205_has_break(int64_t n_1054);
static int64_t f206_ck_if(int64_t n_1063, int64_t want_1064);
static int64_t f207_narrow_of(int64_t c_1067);
static int64_t f208_ck_while(int64_t n_1078);
static int64_t f209_ck_loop(int64_t n_1082, int64_t want_1083);
static int64_t f210_ck_for(int64_t n_1085);
static int64_t f211_ax(int64_t n_1098);
static int64_t f212_ck_match(int64_t n_1099, int64_t want_1100);
static int64_t f213_ck_ret(int64_t n_1133);
static int64_t f214_ret_fn(void);
static int64_t f215_ck_break(int64_t n_1147);
static int64_t f216_ck_call(int64_t n_1151, int64_t want_1152);
static int64_t f217_find_nest(int64_t name_1158);
static int64_t f218_call_nested(int64_t n_1161, int64_t nf_1162);
static int64_t f219_ck_args(int64_t n_1164, int64_t a0n_1165, int64_t first_1166);
static void f220_pop_args(int64_t s_1173);
static void f221_note_caps_of(int64_t i_1174);
static int64_t f222_block_binding(int64_t name_1177);
static int64_t f223_blk_gen(int64_t fnode_1181);
static int64_t f224_gen_list(int64_t fnode_1182);
static bool f225_is_blockparam(int64_t fnode_1186, int64_t gname_1187);
static bool f226_mentions(int64_t t_1190, int64_t g_1191);
static int64_t f227_call_block(int64_t n_1196, int64_t inst_1197);
static int64_t f228_deref_val(int64_t a_1204);
static int64_t f229_builtin_of(hsl name_1224);
static bool f230_user_format(int64_t n_1226);
static void f231_cands_add(int64_t name_1228, int64_t ns_1229);
static bool f232_is_std_node(int64_t node_1238);
static int64_t f233_ck_builtin(int64_t n_1241, int64_t b_1242, int64_t recv_1243, int64_t want_1244);
static int64_t f234_arg(int64_t i_1247, int64_t *c1243, int64_t *c1241);
static int64_t f235_call_fn(int64_t n_1274, int64_t name_1275, int64_t recv_1276, int64_t want_1277);
static M91 f236_resolve(int64_t n_1281, int64_t name_1282, int64_t ns_1283, int64_t a0_1284, int64_t an_1285, int64_t blk_1286, int64_t tyargs_1287, bool report_1288);
static bool f237_match_ty(int64_t tn0_1312, int64_t t0_1313, int64_t g0_1314);
static int64_t f238_pend_default(int64_t a_1327);
static int64_t f239_arg_rank(int64_t n_1340, int64_t a_1341, int64_t p_1342);
static bool f240_untyped_any(int64_t f_1351);
static int64_t f241_get_inst(int64_t node_1361, int64_t b0_1362, int64_t bn_1363, int64_t blk_1364, int64_t bown_1365);
static bool f242_same_binds(int64_t i_1369, int64_t b0_1370, int64_t bn_1371);
static int64_t f243_member_of(hsl name_1385);
static int64_t f244_ck_slit(int64_t n_1388, int64_t want_1389);
static bool f245_ORD_HAS(int64_t d_1412);
static bool f246_gen_program(hrv* out_1418);
static void f247_ow(hsl s_1424);
static void f248_ct(int64_t t_1425);
static void f249_cbody(int64_t t_1426);
static void f250_cn_grow(void);
static hsl f251_cn(int64_t t_1429);
static void f252_cn_make(int64_t t_1430);
static void f253_fwd(int64_t s0_1439);
static void f254_fname_into(hrv* b_1451, int64_t name_1452);
static bool f255_is_res(int64_t t_1467);
static void f256_gxo(int64_t n_1468);
static void f257_gcv(int64_t n_1471, int64_t f_1472, int64_t t_1473);
static void f258_gx1(int64_t n_1474);
static bool f259_is_place(int64_t n_1475);
static int64_t f260_tmp(int64_t t_1480, bool clean_1481);
static void f261_ot(int64_t k_1483);
static void f262_gx0(int64_t n_1484);
static int64_t f263_fin_lit(int64_t n_1487);
static void f264_oint(int64_t v_1489, bool uns_1490, int64_t t_1491);
static void f265_gstr(int64_t n_1494);
static int64_t f266_fin(int64_t n_1495);
static hsl f267_tok_str(int64_t t_1499);
static void f268_cstr_lit(hsl s_1503);
static bool f269_is_fix(int64_t t_1505);
static bool f270_is_lim(int64_t t_1506);
static void f271_lv_expr(int64_t v_1508);
static bool f272_lv_isptr(int64_t v_1509);
static void f273_lv_name(int64_t v_1511);
static void f274_gerr(int64_t n_1513, hsl m_1514);
static void f275_gbin(int64_t n_1516);
static void f276_gx(int64_t n_1521);
static hsl f277_cmp_op(int64_t o_1528);
static void f278_gas(int64_t n_1529);
static void f279_gsl(int64_t n_1532, int64_t f_1533);
static int64_t f280_nt(void);
static void f281_oi(int64_t v_1537);
static void f282_gen_heq(int64_t t_1543);
static void f283_comp_pre(int64_t t_1547, bool fmt_1548);
static void f284_comp_one(int64_t t_1554, bool fmt_1555);
static bool f285_need_helper(int64_t t_1557);
static void f286_gen_hf(int64_t t_1559);
static void f287_hf_pre(int64_t t_1563);
static void f288_hh(hsl s_1566);
static void f289_hf_val(int64_t t_1574, hsl e_1575);
static void f290_heq_val(int64_t t_1618, hsl a_1619, hsl b_1620);
static bool f291_hsl_ty(int64_t t_1631);
static void f292_gxas(int64_t n_1632, int64_t t_1633);
static void f293_garith(int64_t o_1636, int64_t t0_1637, int64_t a_1638, int64_t b_1639, int64_t tv_1640, int64_t loc_1641);
static void f294_gopnd(int64_t n_1647, int64_t tv_1648);
static void f295_gen_hop(int64_t t_1649, int64_t o_1650, int64_t bt_1651);
static void f296_hop_body(int64_t t_1657, int64_t o_1658, hsl r_1659, hsl a_1660, hsl b_1661, bool sc_1662);
static hsl f297_ar_op(int64_t o_1664);
static void f298_wloc(int64_t n_1678);
static void f299_gun(int64_t n_1681);
static void f300_gen_hneg(int64_t t_1686);
static void f301_gidx(int64_t n_1698);
static void f302_gslice(int64_t n_1706);
static void f303_garr(int64_t n_1714);
static void f304_gslit(int64_t n_1721);
static void f305_gcall(int64_t n_1733);
static void f306_gbuiltin(int64_t n_1735);
static int64_t f307_arg(int64_t i_1741, int64_t *c1739, int64_t *c1735);
static void f308_gfmt(hsl o_1745, int64_t n_1746, int64_t t_1747, bool top_1748);
static void f309_grecv_ptr(int64_t r_1755);
static void f310_esz(int64_t t_1769);
static void f311_gaddr(int64_t n_1773);
static void f312_heq_val_o(int64_t e_1782, int64_t p_1783);
static void f313_heq_o(int64_t e_1786, hsl a_1787, hsl b_1788);
static void f314_heq_pre(int64_t t_1789);
static bool f315_scalar_ty(int64_t t_1790);
static void f316_heq_val_s(int64_t e_1793, int64_t p_1794);
static void f317_heq_val_r(int64_t e_1797, int64_t p_1798);
static void f318_gblkcall(int64_t n_1801);
static void f319_gstmt(int64_t n_1813);
static void f320_gvdecl(int64_t n_1819);
static void f321_decl_lv(int64_t v_1827);
static void f322_gstmt1(int64_t n_1838);
static void f323_gassign(int64_t n_1841);
static int64_t f324_base_op(int64_t o_1854);
static void f325_gif(int64_t n_1857, int64_t res_1858);
static void f326_gblk(int64_t b_1862, int64_t res_1863, bool val_1864);
static void f327_gtail(int64_t tl_1866, int64_t res_1867);
static void f328_gwhile(int64_t n_1870);
static int64_t f329_lbl_push(int64_t res_1872);
static void f330_lbl_pop(int64_t l_1875);
static void f331_gloop(int64_t n_1876, int64_t res_1877);
static void f332_gfor(int64_t n_1879);
static void f333_gmatch(int64_t n_1894, int64_t res_1895);
static void f334_geblock(int64_t n_1917, int64_t res_1918);
static void f335_gret(int64_t n_1920);
static void f336_gmove(int64_t c_1926);
static bool f337_movable_local(int64_t c_1927);
static void f338_gbreak(int64_t n_1932);
static bool f339_owned(int64_t n_1936);
static bool f340_is_ext(int64_t i_1940);
static void f341_ext_name(int64_t i_1941);
static void f342_fn_cname(int64_t i_1945);
static void f343_gcall_args(int64_t n_1948, int64_t inst_1949, int64_t recv_1950);
static void f344_lv_addr(int64_t v_1962);
static void f345_gen_fn(int64_t i_1977);
static void f346_gsig(int64_t i_1980);
static hrv g470;
static hrv g886;
static A25 g829;
static hrv g887;
static hrv g884;
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
static hrv g528;
static int64_t g552;
static hrv g530;
static hrv g529;
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
static int64_t g549;
static int64_t g550;
static int64_t g551;
static int64_t g554;
static int64_t g555;
static int64_t g553;
static hrv g469;
static hrv g888;
static hrv g682;
static hrv g889;
static hrv g890;
static hrv g883;
static hrv g885;
static hrv g685;
static int64_t g684;
static int64_t g692;
static int64_t g691;
static int64_t g686;
static bool g687;
static hrv g679;
static hrv g681;
static bool g731;
static hrv g693;
static hrv g680;
static bool g688;
static bool g689;
static bool g690;
static hrv g694;
static hrv g683;
static hrv g472;
static hrv g473;
static hrv g467;
static hrv g466;
static hrv g471;
static int64_t g386;
static hrv g373;
static hrv g378;
static hrv g377;
static hrv g379;
static hrv g380;
static hrv g381;
static hrv g382;
static int64_t g384;
static int64_t g385;
static int64_t g388;
static hrv g387;
static hrv g428;
static hrv g429;
static hrv g533;
static hrv g534;
static hrv g531;
static hrv g468;
static hrv g532;
static hrv g414;
static hrv g375;
static hrv g374;
static hrv g376;
static hrv g415;
static hrv g308;
static int64_t g390;
static hrv g446;
static hrv g391;
static hrv g312;
static hrv g309;
static hrv g310;
static hrv g392;
static hrv g163;
static int64_t g179;
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
static A98 g114;
static hrv g154;
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
static int64_t g305;
static int64_t g306;
static hrv g311;
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
static int64_t g368;
static int64_t g369;
static int64_t g383;
static int64_t g389;
static int64_t g459;
static int64_t g460;
static int64_t g461;
static int64_t g462;
static int64_t g463;
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
static int64_t g519;
static int64_t g520;
static int64_t g521;
static int64_t g522;
static int64_t g593;
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
static int64_t g674;
static int64_t g675;
static int64_t g676;
static int64_t g677;
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
static int64_t g825;
static int64_t g826;
static int64_t g827;
static int64_t g828;
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
static int64_t g876;
static int64_t g877;
static int64_t g878;
static int64_t g879;
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
(void)(({ hrv *_v11 = &(g470); hsl _s11 = hr_sl(lib_2); hr_append(_v11, _s11.p, _s11.n, sizeof(uint8_t)); }));
if ((!(f5_load_program(hr_sl(a_0))))) { (void)(({ hr_fs(&hr_ob, hr_sl(g472)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((!(f104_check_program()))) { (void)(({ hr_fs(&hr_ob, hr_sl(g387)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((((g472).n) > (((int64_t)0LL)))) { (void)(({ hr_fs(&hr_ob, hr_sl(g472)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
hrv c_1417 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(f246_gen_program((&(c_1417)))))) { (void)(({ hr_fs(&hr_ob, hr_sl(g182)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
if ((!(hr_os_write_file(hr_sl(o_1), hr_sl(c_1417))))) { (void)(({ hr_fs(&hr_ob, hr_str("cannot write ", 13)); hr_fs(&hr_ob, hr_sl(o_1)); hr_println(); }));
(void)(hr_exit(((int64_t)1LL)));
 }
}
static bool f5_load_program(hsl root_3) {
(void)(f6_parse_init());
(void)(f11_types_init());
int64_t d_38 = (root_3).n; 
while ((((d_38) > (((int64_t)0LL))) && (((*({ hsl _t24 = root_3; int64_t _i24 = ((int64_t)((int64_t)d_38 - (int64_t)((int64_t)1LL))); (uint8_t*)_t24.p + hr_ix(_i24, _t24.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:68"); }))) != (((uint8_t)47LL))))) { d_38--;
 } _bk23:; 
(void)(({ hrv *_v25 = &(g469); _v25->n = 0; }));
(void)(({ hrv *_v26 = &(g469); hsl _s26 = ({ hsl _r27; if (((d_38) > (((int64_t)0LL)))) { _r27 = ({ hsl _t28 = root_3; int64_t _l28 = 0, _h28 = ((int64_t)((int64_t)d_38 - (int64_t)((int64_t)1LL))); if (_l28 < 0 || _h28 < _l28 || _h28 > _t28.n) hr_slerr(_l28, _h28, _t28.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:69"); (hsl){ _t28.p + _l28 * (int64_t)sizeof(uint8_t), _h28 - _l28 }; });  } else { _r27 = hr_str(".", 1);  } _r27; }); hr_append(_v26, _s26.p, _s26.n, sizeof(uint8_t)); }));
return (((f19_try_load(root_3)) >= (((int64_t)0LL))) && (((g472).n) == (((int64_t)0LL))));
}
static void f6_parse_init(void) {
(void)(f7_lex_init());
if (((g696) < (((int64_t)0LL)))) { g696 = f8_intern(hr_str("from", 4));
g697 = f8_intern(hr_str("inline", 6));
g698 = f8_intern(hr_str("checkfree", 9));
g699 = f8_intern(hr_str("lut", 3));
g700 = f8_intern(hr_str("_", 1));
g701 = f8_intern(hr_str("upto", 4));
g702 = f8_intern(hr_str("fields", 6));
g703 = f8_intern(hr_str("types", 5));
g704 = f8_intern(hr_str("variants", 8));
g705 = f8_intern(hr_str("std", 3));
 }
}
static void f7_lex_init(void) {
if ((((g886).n) == (((int64_t)0LL)))) { { hsl _v30 = ({ A25 *_t31 = &(g829); (hsl){ (uint8_t*)_t31->e, 49 }; }); for (int64_t _k30 = 0; _k30 < _v30.n; _k30++) { hsl k_4 = ((hsl*)_v30.p)[_k30]; (void)(f8_intern(k_4));
 } } _bk29:; 
 }
}
static int64_t f8_intern(hsl s_5) {
if ((((g887).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v32 = &(g887); int64_t _k32 = ((int64_t)((((int64_t)1LL)) << ((((int64_t)16LL)) & 63))); if (_k32 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:32"); int32_t _x32 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o32 = _v32->n; hr_resize(_v32, _k32, sizeof _x32); for (int64_t _j = _o32; _j < _k32; _j++) ((int32_t*)_v32->b)[_j] = _x32; }));
 }
if (((((int64_t)((int64_t)(g886).n * (int64_t)((int64_t)2LL)))) >= ((g887).n))) { int64_t n_6 = ((int64_t)((int64_t)(g887).n * (int64_t)((int64_t)2LL))); 
(void)(({ hrv *_v33 = &(g887); _v33->n = 0; }));
(void)(({ hrv *_v34 = &(g887); int64_t _k34 = n_6; if (_k34 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:35"); int32_t _x34 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o34 = _v34->n; hr_resize(_v34, _k34, sizeof _x34); for (int64_t _j = _o34; _j < _k34; _j++) ((int32_t*)_v34->b)[_j] = _x34; }));
{ hrv *_v36 = &(g886); for (int64_t _k36 = 0; _k36 < _v36->n; _k36++) { S0 x_7 = ((S0*)_v36->b)[_k36]; int64_t i_8 = (int64_t)_k36; int64_t j_12 = ((int64_t)((int64_t)((int64_t)(f9_hash(({ hsl _t37 = hr_sl(g884); int64_t _l37 = ((int64_t)((x_7).s_)), _h37 = ((int64_t)(((int32_t)((int64_t)(x_7).s_ + (int64_t)(x_7).n_)))); if (_l37 < 0 || _h37 < _l37 || _h37 > _t37.n) hr_slerr(_l37, _h37, _t37.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:36"); (hsl){ _t37.p + _l37 * (int64_t)sizeof(uint8_t), _h37 - _l37 }; })))) & (int64_t)((int64_t)((int64_t)n_6 - (int64_t)((int64_t)1LL))))); 
while ((((*({ hrv *_t39 = &(g887); int64_t _i39 = j_12; (int32_t*)_t39->b + hr_ix(_i39, _t39->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:36"); }))) >= (((int32_t)0LL)))) { j_12 = ((int64_t)((int64_t)((int64_t)((int64_t)j_12 + (int64_t)((int64_t)1LL))) & (int64_t)((int64_t)((int64_t)n_6 - (int64_t)((int64_t)1LL)))));
 } _bk38:; 
{ int32_t *_t40 = &((*({ hrv *_t41 = &(g887); int64_t _i41 = j_12; (int32_t*)_t41->b + hr_ix(_i41, _t41->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:36"); }))); *_t40 = ((int32_t)(i_8)); }
 } } _bk35:; 
 }
int64_t m_13 = ((int64_t)((int64_t)(g887).n - (int64_t)((int64_t)1LL))); 
int64_t j_14 = ((int64_t)((int64_t)((int64_t)(f9_hash(s_5))) & (int64_t)m_13)); 
while ((((*({ hrv *_t43 = &(g887); int64_t _i43 = j_14; (int32_t*)_t43->b + hr_ix(_i43, _t43->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:40"); }))) >= (((int32_t)0LL)))) { if (hr_streq(f10_nm(((int64_t)((*({ hrv *_t44 = &(g887); int64_t _i44 = j_14; (int32_t*)_t44->b + hr_ix(_i44, _t44->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:40"); }))))), s_5)) { return ((int64_t)((*({ hrv *_t45 = &(g887); int64_t _i45 = j_14; (int32_t*)_t45->b + hr_ix(_i45, _t45->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:40"); }))));
 }
j_14 = ((int64_t)((int64_t)((int64_t)((int64_t)j_14 + (int64_t)((int64_t)1LL))) & (int64_t)m_13));
 } _bk42:; 
int64_t id_17 = (g886).n; 
(void)(({ hrv *_v46 = &(g886); S0 _x46 = ((S0){ .s_ = ((int32_t)((g884).n)), .n_ = ((int32_t)((s_5).n)), }); S0 *_p46 = (S0*)hr_grow(_v46, 1, sizeof _x46); *_p46 = _x46; _p46; }));
(void)(({ hrv *_v47 = &(g884); hsl _s47 = s_5; hr_append(_v47, _s47.p, _s47.n, sizeof(uint8_t)); }));
{ int32_t *_t48 = &((*({ hrv *_t49 = &(g887); int64_t _i49 = j_14; (int32_t*)_t49->b + hr_ix(_i49, _t49->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:44"); }))); *_t48 = ((int32_t)(id_17)); }
return id_17;
}
static uint64_t f9_hash(hsl s_9) {
uint64_t h_10 = ((uint64_t)1469598103934665603LL); 
{ hsl _v51 = s_9; for (int64_t _k51 = 0; _k51 < _v51.n; _k51++) { uint8_t c_11 = ((uint8_t*)_v51.p)[_k51]; h_10 = ((uint64_t)((uint64_t)((uint64_t)((uint64_t)h_10 ^ (uint64_t)((uint64_t)(c_11)))) * (uint64_t)((uint64_t)1099511628211LL)));
 } } _bk50:; 
return h_10;
}
static hsl f10_nm(int64_t id_15) {
S0 x_16 = (*({ hrv *_t52 = &(g886); int64_t _i52 = id_15; (S0*)_t52->b + hr_ix(_i52, _t52->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:29"); })); 
return ({ hsl _t53 = hr_sl(g884); int64_t _l53 = ((int64_t)((x_16).s_)), _h53 = ((int64_t)(((int32_t)((int64_t)(x_16).s_ + (int64_t)(x_16).n_)))); if (_l53 < 0 || _h53 < _l53 || _h53 > _t53.n) hr_slerr(_l53, _h53, _t53.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:29"); (hsl){ _t53.p + _l53 * (int64_t)sizeof(uint8_t), _h53 - _l53 }; });
}
static void f11_types_init(void) {
if ((((g528).n) > (((int64_t)0LL)))) { return;
 }
g552 = f12_tsimple(((int64_t)0LL), ((int64_t)0LL));
g535 = f12_tsimple(((int64_t)1LL), ((int64_t)0LL));
g536 = f12_tsimple(((int64_t)2LL), ((int64_t)0LL));
g537 = f17_t_int(((int64_t)0LL));
g538 = f17_t_int(((int64_t)1LL));
g539 = f17_t_int(((int64_t)2LL));
g540 = f17_t_int(((int64_t)3LL));
g541 = f17_t_int(((int64_t)4LL));
g542 = f17_t_int(((int64_t)5LL));
g543 = f17_t_int(((int64_t)6LL));
g544 = f17_t_int(((int64_t)7LL));
g545 = f12_tsimple(((int64_t)4LL), ((int64_t)4LL));
g546 = f12_tsimple(((int64_t)4LL), ((int64_t)8LL));
g547 = f12_tsimple(((int64_t)11LL), ((int64_t)0LL));
g548 = f12_tsimple(((int64_t)12LL), ((int64_t)0LL));
g549 = f12_tsimple(((int64_t)13LL), ((int64_t)0LL));
g550 = f12_tsimple(((int64_t)18LL), ((int64_t)0LL));
g551 = f12_tsimple(((int64_t)17LL), ((int64_t)0LL));
g554 = f12_tsimple(((int64_t)19LL), ((int64_t)0LL));
g555 = f12_tsimple(((int64_t)15LL), ((int64_t)0LL));
g553 = f18_t_slice(g541, true);
}
static int64_t f12_tsimple(int64_t k_18, int64_t s_19) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(k_18)), .s_ = ((uint8_t)(s_19)), .a_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f13_tmk(S1 t_20) {
if ((((g530).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v54 = &(g530); int64_t _k54 = ((int64_t)((((int64_t)1LL)) << ((((int64_t)14LL)) & 63))); if (_k54 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:27"); int32_t _x54 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o54 = _v54->n; hr_resize(_v54, _k54, sizeof _x54); for (int64_t _j = _o54; _j < _k54; _j++) ((int32_t*)_v54->b)[_j] = _x54; }));
 }
if (((((int64_t)((int64_t)(g528).n * (int64_t)((int64_t)2LL)))) >= ((g530).n))) { int64_t n_21 = ((int64_t)((int64_t)(g530).n * (int64_t)((int64_t)2LL))); 
(void)(({ hrv *_v55 = &(g530); _v55->n = 0; }));
(void)(({ hrv *_v56 = &(g530); int64_t _k56 = n_21; if (_k56 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:29"); int32_t _x56 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o56 = _v56->n; hr_resize(_v56, _k56, sizeof _x56); for (int64_t _j = _o56; _j < _k56; _j++) ((int32_t*)_v56->b)[_j] = _x56; }));
{ hrv *_v58 = &(g528); for (int64_t _k58 = 0; _k58 < _v58->n; _k58++) { S1 x_22 = ((S1*)_v58->b)[_k58]; int64_t i_23 = (int64_t)_k58; int64_t j_29 = ((int64_t)((int64_t)((int64_t)(f14_th(x_22))) & (int64_t)((int64_t)((int64_t)n_21 - (int64_t)((int64_t)1LL))))); 
while ((((*({ hrv *_t60 = &(g530); int64_t _i60 = j_29; (int32_t*)_t60->b + hr_ix(_i60, _t60->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:30"); }))) >= (((int32_t)0LL)))) { j_29 = ((int64_t)((int64_t)((int64_t)((int64_t)j_29 + (int64_t)((int64_t)1LL))) & (int64_t)((int64_t)((int64_t)n_21 - (int64_t)((int64_t)1LL)))));
 } _bk59:; 
{ int32_t *_t61 = &((*({ hrv *_t62 = &(g530); int64_t _i62 = j_29; (int32_t*)_t62->b + hr_ix(_i62, _t62->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:30"); }))); *_t61 = ((int32_t)(i_23)); }
 } } _bk57:; 
 }
int64_t m_30 = ((int64_t)((int64_t)(g530).n - (int64_t)((int64_t)1LL))); 
int64_t j_31 = ((int64_t)((int64_t)((int64_t)(f14_th(t_20))) & (int64_t)m_30)); 
while ((((*({ hrv *_t64 = &(g530); int64_t _i64 = j_31; (int32_t*)_t64->b + hr_ix(_i64, _t64->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:34"); }))) >= (((int32_t)0LL)))) { if (f16_teq((*({ hrv *_t65 = &(g528); int64_t _i65 = (*({ hrv *_t66 = &(g530); int64_t _i66 = j_31; (int32_t*)_t66->b + hr_ix(_i66, _t66->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:34"); })); (S1*)_t65->b + hr_ix(_i65, _t65->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:34"); })), t_20)) { return ((int64_t)((*({ hrv *_t67 = &(g530); int64_t _i67 = j_31; (int32_t*)_t67->b + hr_ix(_i67, _t67->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:34"); }))));
 }
j_31 = ((int64_t)((int64_t)((int64_t)((int64_t)j_31 + (int64_t)((int64_t)1LL))) & (int64_t)m_30));
 } _bk63:; 
(void)(({ hrv *_v68 = &(g528); S1 _x68 = t_20; S1 *_p68 = (S1*)hr_grow(_v68, 1, sizeof _x68); *_p68 = _x68; _p68; }));
{ int32_t *_t69 = &((*({ hrv *_t70 = &(g530); int64_t _i70 = j_31; (int32_t*)_t70->b + hr_ix(_i70, _t70->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:35"); }))); *_t69 = ((int32_t)(((int64_t)((int64_t)(g528).n - (int64_t)((int64_t)1LL))))); }
return ((int64_t)((int64_t)(g528).n - (int64_t)((int64_t)1LL)));
}
static uint64_t f14_th(S1 t_24) {
uint64_t h_27 = f15_hash_mix(((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((uint64_t)((t_24).k_)) | (uint64_t)((uint64_t)((((uint64_t)((t_24).s_))) << ((((uint64_t)8LL)) & 63))))) | (uint64_t)((uint64_t)((((uint64_t)((t_24).fl_))) << ((((uint64_t)16LL)) & 63))))) | (uint64_t)((uint64_t)((((uint64_t)((t_24).a_))) << ((((uint64_t)32LL)) & 63)))))); 
h_27 = f15_hash_mix(((uint64_t)((uint64_t)((uint64_t)((uint64_t)h_27 ^ (uint64_t)((uint64_t)((t_24).c_)))) ^ (uint64_t)((uint64_t)((((uint64_t)((t_24).b_))) << ((((uint64_t)20LL)) & 63))))));
{ int32_t _e72 = (t_24).n_; for (int32_t _k72 = 0; _k72 < _e72; _k72++) { int32_t i_28 = (int32_t)_k72; h_27 = f15_hash_mix(((uint64_t)((uint64_t)h_27 ^ (uint64_t)((uint64_t)((*({ hrv *_t73 = &(g529); int64_t _i73 = ((int64_t)((int64_t)((int64_t)((t_24).l_)) + (int64_t)((int64_t)(i_28)))); (int32_t*)_t73->b + hr_ix(_i73, _t73->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:20"); })))))));
 } } _bk71:; 
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
{ int32_t _e75 = (x_32).n_; for (int32_t _k75 = 0; _k75 < _e75; _k75++) { int32_t i_34 = (int32_t)_k75; if ((((*({ hrv *_t76 = &(g529); int64_t _i76 = ((int64_t)((int64_t)((int64_t)((x_32).l_)) + (int64_t)((int64_t)(i_34)))); (int32_t*)_t76->b + hr_ix(_i76, _t76->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:23"); }))) != ((*({ hrv *_t77 = &(g529); int64_t _i77 = ((int64_t)((int64_t)((int64_t)((y_33).l_)) + (int64_t)((int64_t)(i_34)))); (int32_t*)_t77->b + hr_ix(_i77, _t77->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:23"); }))))) { return false;
 }
 } } _bk74:; 
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
{ hrv *_v79 = &(g888); for (int64_t _k79 = 0; _k79 < _v79->n; _k79++) { S2 f_41 = ((S2*)_v79->b)[_k79]; int64_t i_42 = (int64_t)_k79; if (((((int64_t)((f_41).name_))) == (id_40))) { return i_42;
 }
 } } _bk78:; 
if ((!(hr_os_file_exists(path_39)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t t0_43 = (g682).n; 
if ((!(f21_parse_file(path_39)))) { (void)(({ hrv *_v80 = &(g472); hsl _s80 = hr_sl(g685); hr_append(_v80, _s80.p, _s80.n, sizeof(uint8_t)); }));
return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
int64_t f_439 = ((int64_t)((int64_t)(g888).n - (int64_t)((int64_t)1LL))); 
while ((((g473).n) < ((g888).n))) { (void)(({ hrv *_v82 = &(g473); int32_t _x82 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p82 = (int32_t*)hr_grow(_v82, 1, sizeof _x82); *_p82 = _x82; _p82; }));
 } _bk81:; 
{ int32_t *_t83 = &((*({ hrv *_t84 = &(g473); int64_t _i84 = f_439; (int32_t*)_t84->b + hr_ix(_i84, _t84->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:45"); }))); *_t83 = (*({ hrv *_t85 = &(g683); int64_t _i85 = ((int64_t)((int64_t)(g683).n - (int64_t)((int64_t)1LL))); (int32_t*)_t85->b + hr_ix(_i85, _t85->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:45"); })); }
(void)(f97_collect(f_439, t0_43, (g682).n));
int64_t t1_455 = (g682).n; 
int64_t im0_456 = (g471).n; 
{ int64_t _e87 = t1_455; for (int64_t _k87 = t0_43; _k87 < _e87; _k87++) { int64_t i_457 = (int64_t)_k87; if (((((*({ hrv *_t88 = &(g679); int64_t _i88 = (*({ hrv *_t89 = &(g682); int64_t _i89 = i_457; (int32_t*)_t89->b + hr_ix(_i89, _t89->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:49"); })); (S4*)_t88->b + hr_ix(_i88, _t88->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:49"); }))).k_) == (((uint8_t)54LL)))) { (void)(({ hrv *_v90 = &(g471); int32_t _x90 = (*({ hrv *_t91 = &(g682); int64_t _i91 = i_457; (int32_t*)_t91->b + hr_ix(_i91, _t91->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:49"); })); int32_t *_p90 = (int32_t*)hr_grow(_v90, 1, sizeof _x90); *_p90 = _x90; _p90; }));
 }
 } } _bk86:; 
int64_t im1_458 = (g471).n; 
L49 sp_461 = f100_lib_path(hr_str("std", 3)); 
bool isstd_462 = hr_streq(path_39, ({ hsl _t92 = ({ L49 *_t93 = &(sp_461); (hsl){ (uint8_t*)_t93->e, _t93->n }; }); int64_t _l92 = 0, _h92 = _t92.n; if (_l92 < 0 || _h92 < _l92 || _h92 > _t92.n) hr_slerr(_l92, _h92, _t92.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:51"); (hsl){ _t92.p + _l92 * (int64_t)sizeof(uint8_t), _h92 - _l92 }; })); 
if ((((*({ hrv *_t94 = &(g888); int64_t _i94 = f_439; (S2*)_t94->b + hr_ix(_i94, _t94->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:52"); }))).amni_ && (!(isstd_462)))) { if (((f101_load_import(g705, f_439, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
 }
{ int64_t _e96 = im1_458; for (int64_t _k96 = im0_456; _k96 < _e96; _k96++) { int64_t q_475 = (int64_t)_k96; int64_t n_476 = ((int64_t)((*({ hrv *_t97 = &(g471); int64_t _i97 = q_475; (int32_t*)_t97->b + hr_ix(_i97, _t97->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:53"); })))); 
if (((f101_load_import(((int64_t)(((*({ hrv *_t98 = &(g679); int64_t _i98 = n_476; (S4*)_t98->b + hr_ix(_i98, _t98->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:53"); }))).s_)), f_439, ((int64_t)(((*({ hrv *_t99 = &(g679); int64_t _i99 = n_476; (S4*)_t99->b + hr_ix(_i99, _t99->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:53"); }))).t_)))) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
 } } _bk95:; 
return f_439;
}
static bool f21_parse_file(hsl path_44) {
(void)(f6_parse_init());
int64_t t0_45 = (g889).n; 
if ((!(f22_lex_file(path_44)))) { (void)(({ hrv *_v100 = &(g685); hsl _s100 = hr_sl(g890); hr_append(_v100, _s100.p, _s100.n, sizeof(uint8_t)); }));
return false;
 }
g684 = t0_45;
g692 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
while ((((f31_tk()) != (((int64_t)0LL))) && (((g685).n) == (((int64_t)0LL))))) { (void)(f32_ptop());
 } _bk101:; 
(void)(({ hrv *_v102 = &(g683); int32_t _x102 = ((int32_t)(g692)); int32_t *_p102 = (int32_t*)hr_grow(_v102, 1, sizeof _x102); *_p102 = _x102; _p102; }));
return (((g685).n) == (((int64_t)0LL)));
}
static bool f22_lex_file(hsl path_46) {
(void)(f7_lex_init());
hrv body_47 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
if ((!(hr_os_read_file(path_46, (&(body_47)))))) { (void)(({ hrv *_v104 = &(g890); hsl _s104 = hr_str("cannot read ", 12); hr_append(_v104, _s104.p, _s104.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v105 = &(g890); hsl _s105 = path_46; hr_append(_v105, _s105.p, _s105.n, sizeof(uint8_t)); }));
return false;
 }
int64_t f_48 = (g888).n; 
int64_t base_49 = (g883).n; 
int64_t skip_50 = ({ int64_t _r106; if (((((((body_47).n) >= (((int64_t)3LL))) && (((*({ hrv *_t107 = &(body_47); int64_t _i107 = ((int64_t)0LL); (uint8_t*)_t107->b + hr_ix(_i107, _t107->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:69"); }))) == (((uint8_t)239LL)))) && (((*({ hrv *_t108 = &(body_47); int64_t _i108 = ((int64_t)1LL); (uint8_t*)_t108->b + hr_ix(_i108, _t108->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:69"); }))) == (((uint8_t)187LL)))) && (((*({ hrv *_t109 = &(body_47); int64_t _i109 = ((int64_t)2LL); (uint8_t*)_t109->b + hr_ix(_i109, _t109->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:69"); }))) == (((uint8_t)191LL))))) { _r106 = ((int64_t)3LL);  } else { _r106 = ((int64_t)0LL);  } _r106; }); 
(void)(({ hrv *_v110 = &(g883); hsl _s110 = ({ hsl _t111 = hr_sl(body_47); int64_t _l111 = skip_50, _h111 = _t111.n; if (_l111 < 0 || _h111 < _l111 || _h111 > _t111.n) hr_slerr(_l111, _h111, _t111.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:70"); (hsl){ _t111.p + _l111 * (int64_t)sizeof(uint8_t), _h111 - _l111 }; }); hr_append(_v110, _s110.p, _s110.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v112 = &(g883); uint8_t _x112 = ((uint8_t)0LL); uint8_t *_p112 = (uint8_t*)hr_grow(_v112, 1, sizeof _x112); *_p112 = _x112; _p112; }));
(void)(({ hrv *_v113 = &(g883); uint8_t _x113 = ((uint8_t)0LL); uint8_t *_p113 = (uint8_t*)hr_grow(_v113, 1, sizeof _x113); *_p113 = _x113; _p113; }));
(void)(({ hrv *_v114 = &(g883); uint8_t _x114 = ((uint8_t)0LL); uint8_t *_p114 = (uint8_t*)hr_grow(_v114, 1, sizeof _x114); *_p114 = _x114; _p114; }));
(void)(({ hrv *_v115 = &(g883); uint8_t _x115 = ((uint8_t)0LL); uint8_t *_p115 = (uint8_t*)hr_grow(_v115, 1, sizeof _x115); *_p115 = _x115; _p115; }));
(void)(({ hrv *_v116 = &(g888); S2 _x116 = ((S2){ .s_ = ((int32_t)(base_49)), .n_ = ((int32_t)(((int64_t)((int64_t)(body_47).n - (int64_t)skip_50)))), .name_ = ((int32_t)(f8_intern(path_46))), .amni_ = ((((path_46).n) > (((int64_t)5LL))) && hr_streq(({ hsl _t117 = path_46; int64_t _l117 = _t117.n - ((int64_t)5LL), _h117 = _t117.n; if (_l117 < 0 || _h117 < _l117 || _h117 > _t117.n) hr_slerr(_l117, _h117, _t117.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:71"); (hsl){ _t117.p + _l117 * (int64_t)sizeof(uint8_t), _h117 - _l117 }; }), hr_str(".amni", 5))), }); S2 *_p116 = (S2*)hr_grow(_v116, 1, sizeof _x116); *_p116 = _x116; _p116; }));
bool amni_51 = ((*({ hrv *_t118 = &(g888); int64_t _i118 = f_48; (S2*)_t118->b + hr_ix(_i118, _t118->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:72"); }))).amni_; 
int64_t p_52 = base_49; 
int64_t line_53 = ((int64_t)1LL); 

for (;;) { uint8_t c_57 = (*({ hrv *_t120 = &(g883); int64_t _i120 = p_52; (uint8_t*)_t120->b + hr_ix(_i120, _t120->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:77"); })); 
while ((((((c_57) == (((uint8_t)32LL))) || ((c_57) == (((uint8_t)9LL)))) || ((c_57) == (((uint8_t)13LL)))) || ((c_57) == (((uint8_t)10LL))))) { if (((c_57) == (((uint8_t)10LL)))) { line_53++;
 }
p_52++;
c_57 = (*({ hrv *_t122 = &(g883); int64_t _i122 = p_52; (uint8_t*)_t122->b + hr_ix(_i122, _t122->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:78"); }));
 } _bk121:; 
if ((((c_57) == (((uint8_t)47LL))) && (((*({ hrv *_t123 = &(g883); int64_t _i123 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t123->b + hr_ix(_i123, _t123->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:79"); }))) == (((uint8_t)47LL))))) { while (((((*({ hrv *_t125 = &(g883); int64_t _i125 = p_52; (uint8_t*)_t125->b + hr_ix(_i125, _t125->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:79"); }))) != (((uint8_t)10LL))) && (((*({ hrv *_t126 = &(g883); int64_t _i126 = p_52; (uint8_t*)_t126->b + hr_ix(_i126, _t126->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:79"); }))) != (((uint8_t)0LL))))) { p_52++;
 } _bk124:; 
continue;
 }
if ((((c_57) == (((uint8_t)47LL))) && (((*({ hrv *_t127 = &(g883); int64_t _i127 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t127->b + hr_ix(_i127, _t127->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:80"); }))) == (((uint8_t)42LL))))) { { int64_t *_t128 = &(p_52); *_t128 = ((int64_t)((int64_t)(*_t128) + (int64_t)((int64_t)2LL))); }
int64_t nest_58 = ((int64_t)1LL); 
while (((nest_58) > (((int64_t)0LL)))) { uint8_t d_59 = (*({ hrv *_t130 = &(g883); int64_t _i130 = p_52; (uint8_t*)_t130->b + hr_ix(_i130, _t130->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:82"); })); 
if (((d_59) == (((uint8_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("unterminated /* comment", 23));
 }
if (((d_59) == (((uint8_t)10LL)))) { line_53++;
 }
if ((((d_59) == (((uint8_t)42LL))) && (((*({ hrv *_t131 = &(g883); int64_t _i131 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t131->b + hr_ix(_i131, _t131->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:82"); }))) == (((uint8_t)47LL))))) { nest_58--;
p_52++;
 } else { if ((((d_59) == (((uint8_t)47LL))) && (((*({ hrv *_t132 = &(g883); int64_t _i132 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t132->b + hr_ix(_i132, _t132->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:82"); }))) == (((uint8_t)42LL))))) { nest_58++;
p_52++;
 }
 }
p_52++;
 } _bk129:; 
continue;
 }
int64_t s_63 = p_52; 
uint8_t n1_64 = (*({ hrv *_t133 = &(g883); int64_t _i133 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t133->b + hr_ix(_i133, _t133->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:86"); })); 
uint8_t n2_65 = (*({ hrv *_t134 = &(g883); int64_t _i134 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t134->b + hr_ix(_i134, _t134->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:86"); })); 
if (((c_57) == (((uint8_t)0LL)))) { (void)(f24_put(((int64_t)0LL), s_63, s_63, &f_48, &line_53));
return true;
 }
if (f26_dig(c_57)) { if ((((c_57) == (((uint8_t)48LL))) && (((n1_64) == (((uint8_t)120LL))) || ((n1_64) == (((uint8_t)88LL)))))) { { int64_t *_t135 = &(p_52); *_t135 = ((int64_t)((int64_t)(*_t135) + (int64_t)((int64_t)2LL))); }
int64_t ds_67 = p_52; 
while (f27_hexd((*({ hrv *_t137 = &(g883); int64_t _i137 = p_52; (uint8_t*)_t137->b + hr_ix(_i137, _t137->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:90"); })))) { p_52++;
 } _bk136:; 
bool hf_69 = false; 
if (((((*({ hrv *_t138 = &(g883); int64_t _i138 = p_52; (uint8_t*)_t138->b + hr_ix(_i138, _t138->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:92"); }))) == (((uint8_t)46LL))) && f27_hexd((*({ hrv *_t139 = &(g883); int64_t _i139 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t139->b + hr_ix(_i139, _t139->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:92"); }))))) { hf_69 = true;
p_52++;
while (f27_hexd((*({ hrv *_t141 = &(g883); int64_t _i141 = p_52; (uint8_t*)_t141->b + hr_ix(_i141, _t141->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:92"); })))) { p_52++;
 } _bk140:; 
 }
if (((((*({ hrv *_t142 = &(g883); int64_t _i142 = p_52; (uint8_t*)_t142->b + hr_ix(_i142, _t142->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:93"); }))) == (((uint8_t)112LL))) || (((*({ hrv *_t143 = &(g883); int64_t _i143 = p_52; (uint8_t*)_t143->b + hr_ix(_i143, _t143->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:93"); }))) == (((uint8_t)80LL))))) { hf_69 = true;
p_52++;
if (((((*({ hrv *_t144 = &(g883); int64_t _i144 = p_52; (uint8_t*)_t144->b + hr_ix(_i144, _t144->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:93"); }))) == (((uint8_t)43LL))) || (((*({ hrv *_t145 = &(g883); int64_t _i145 = p_52; (uint8_t*)_t145->b + hr_ix(_i145, _t145->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:93"); }))) == (((uint8_t)45LL))))) { p_52++;
 }
while (f26_dig((*({ hrv *_t147 = &(g883); int64_t _i147 = p_52; (uint8_t*)_t147->b + hr_ix(_i147, _t147->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:93"); })))) { p_52++;
 } _bk146:; 
 }
if (hf_69) { (void)(f24_put(((int64_t)3LL), s_63, p_52, &f_48, &line_53));
continue;
 }
if (((((int64_t)((int64_t)p_52 - (int64_t)ds_67))) > (((int64_t)16LL)))) { return f25_lerr(f_48, line_53, hr_str("hex literal too large for 64 bits", 33));
 }
uint64_t v_70 = ((uint64_t)0LL); 
{ int64_t _e149 = p_52; for (int64_t _k149 = ds_67; _k149 < _e149; _k149++) { int64_t q_71 = (int64_t)_k149; v_70 = ((uint64_t)((uint64_t)((uint64_t)((v_70) << ((((uint64_t)4LL)) & 63))) | (uint64_t)((uint64_t)(f28_hexv((*({ hrv *_t150 = &(g883); int64_t _i150 = q_71; (uint8_t*)_t150->b + hr_ix(_i150, _t150->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:96"); })))))));
 } } _bk148:; 
(void)(f24_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t151 = &(((*({ hrv *_t152 = &(g889); int64_t _i152 = ((int64_t)((int64_t)(g889).n - (int64_t)((int64_t)1LL))); (S3*)_t152->b + hr_ix(_i152, _t152->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:97"); }))).v_); *_t151 = ((int64_t)(v_70)); }
{ bool *_t153 = &(((*({ hrv *_t154 = &(g889); int64_t _i154 = ((int64_t)((int64_t)(g889).n - (int64_t)((int64_t)1LL))); (S3*)_t154->b + hr_ix(_i154, _t154->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:97"); }))).uns_); *_t153 = ((v_70) > (((uint64_t)9223372036854775807LL))); }
continue;
 }
while (f26_dig((*({ hrv *_t156 = &(g883); int64_t _i156 = p_52; (uint8_t*)_t156->b + hr_ix(_i156, _t156->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:99"); })))) { p_52++;
 } _bk155:; 
bool fl_73 = false; 
if (((((*({ hrv *_t157 = &(g883); int64_t _i157 = p_52; (uint8_t*)_t157->b + hr_ix(_i157, _t157->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:101"); }))) == (((uint8_t)46LL))) && f26_dig((*({ hrv *_t158 = &(g883); int64_t _i158 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t158->b + hr_ix(_i158, _t158->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:101"); }))))) { fl_73 = true;
p_52++;
while (f26_dig((*({ hrv *_t160 = &(g883); int64_t _i160 = p_52; (uint8_t*)_t160->b + hr_ix(_i160, _t160->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:101"); })))) { p_52++;
 } _bk159:; 
 }
if ((((((*({ hrv *_t161 = &(g883); int64_t _i161 = p_52; (uint8_t*)_t161->b + hr_ix(_i161, _t161->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:102"); }))) == (((uint8_t)101LL))) || (((*({ hrv *_t162 = &(g883); int64_t _i162 = p_52; (uint8_t*)_t162->b + hr_ix(_i162, _t162->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:102"); }))) == (((uint8_t)69LL)))) && (f26_dig((*({ hrv *_t163 = &(g883); int64_t _i163 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t163->b + hr_ix(_i163, _t163->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:102"); }))) || (((((*({ hrv *_t164 = &(g883); int64_t _i164 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t164->b + hr_ix(_i164, _t164->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:102"); }))) == (((uint8_t)43LL))) || (((*({ hrv *_t165 = &(g883); int64_t _i165 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t165->b + hr_ix(_i165, _t165->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:102"); }))) == (((uint8_t)45LL)))) && f26_dig((*({ hrv *_t166 = &(g883); int64_t _i166 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t166->b + hr_ix(_i166, _t166->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:102"); }))))))) { fl_73 = true;
{ int64_t *_t167 = &(p_52); *_t167 = ((int64_t)((int64_t)(*_t167) + (int64_t)((int64_t)2LL))); }
while (f26_dig((*({ hrv *_t169 = &(g883); int64_t _i169 = p_52; (uint8_t*)_t169->b + hr_ix(_i169, _t169->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:102"); })))) { p_52++;
 } _bk168:; 
 }
if (fl_73) { (void)(f24_put(((int64_t)3LL), s_63, p_52, &f_48, &line_53));
continue;
 }
uint64_t v_74 = ((uint64_t)0LL); 
{ int64_t _e171 = p_52; for (int64_t _k171 = s_63; _k171 < _e171; _k171++) { int64_t q_75 = (int64_t)_k171; uint64_t d_76 = ((uint64_t)(((uint8_t)((uint64_t)(*({ hrv *_t172 = &(g883); int64_t _i172 = q_75; (uint8_t*)_t172->b + hr_ix(_i172, _t172->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:105"); })) - (uint64_t)((uint8_t)48LL))))); 
if (((v_74) > (HR_UDIV(uint64_t, ((uint64_t)((uint64_t)((uint64_t)18446744073709551615ULL) - (uint64_t)d_76)), ((uint64_t)10LL), "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:105")))) { return f25_lerr(f_48, line_53, hr_str("integer literal too large for 64 bits", 37));
 }
v_74 = ((uint64_t)((uint64_t)((uint64_t)((uint64_t)v_74 * (uint64_t)((uint64_t)10LL))) + (uint64_t)d_76));
 } } _bk170:; 
(void)(f24_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t173 = &(((*({ hrv *_t174 = &(g889); int64_t _i174 = ((int64_t)((int64_t)(g889).n - (int64_t)((int64_t)1LL))); (S3*)_t174->b + hr_ix(_i174, _t174->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:106"); }))).v_); *_t173 = ((int64_t)(v_74)); }
{ bool *_t175 = &(((*({ hrv *_t176 = &(g889); int64_t _i176 = ((int64_t)((int64_t)(g889).n - (int64_t)((int64_t)1LL))); (S3*)_t176->b + hr_ix(_i176, _t176->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:106"); }))).uns_); *_t175 = ((v_74) > (((uint64_t)9223372036854775807LL))); }
continue;
 }
if (f29_idc(c_57)) { while (f29_idc((*({ hrv *_t178 = &(g883); int64_t _i178 = p_52; (uint8_t*)_t178->b + hr_ix(_i178, _t178->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:109"); })))) { p_52++;
 } _bk177:; 
int64_t id_78 = f8_intern(({ hsl _t179 = hr_sl(g883); int64_t _l179 = s_63, _h179 = p_52; if (_l179 < 0 || _h179 < _l179 || _h179 > _t179.n) hr_slerr(_l179, _h179, _t179.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:110"); (hsl){ _t179.p + _l179 * (int64_t)sizeof(uint8_t), _h179 - _l179 }; })); 
int64_t k_79 = ({ int64_t _r180; if (((id_78) < (((int64_t)49LL)))) { _r180 = ((int64_t)((int64_t)((int64_t)56LL) + (int64_t)id_78));  } else { _r180 = ((int64_t)1LL);  } _r180; }); 
if (((!(amni_51)) && ((k_79) >= (((int64_t)101LL))))) { k_79 = ((int64_t)1LL);
 }
(void)(f24_put(k_79, s_63, p_52, &f_48, &line_53));
{ int64_t *_t181 = &(((*({ hrv *_t182 = &(g889); int64_t _i182 = ((int64_t)((int64_t)(g889).n - (int64_t)((int64_t)1LL))); (S3*)_t182->b + hr_ix(_i182, _t182->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:113"); }))).v_); *_t181 = id_78; }
continue;
 }
if (((c_57) == (((uint8_t)39LL)))) { p_52++;
int64_t v_86 = f30_esc((&(p_52)), f_48, line_53); 
if (((v_86) < (((int64_t)0LL)))) { return false;
 }
if ((((*({ hrv *_t183 = &(g883); int64_t _i183 = p_52; (uint8_t*)_t183->b + hr_ix(_i183, _t183->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:119"); }))) != (((uint8_t)39LL)))) { return f25_lerr(f_48, line_53, hr_str("expected closing ' of character literal", 39));
 }
p_52++;
(void)(f24_put(((int64_t)2LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t184 = &(((*({ hrv *_t185 = &(g889); int64_t _i185 = ((int64_t)((int64_t)(g889).n - (int64_t)((int64_t)1LL))); (S3*)_t185->b + hr_ix(_i185, _t185->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:120"); }))).v_); *_t184 = v_86; }
continue;
 }
if (((c_57) == (((uint8_t)34LL)))) { int64_t ss_87 = (g885).n; 
bool ml_88 = false; 
if ((((n1_64) == (((uint8_t)34LL))) && ((n2_65) == (((uint8_t)34LL))))) { { int64_t *_t186 = &(p_52); *_t186 = ((int64_t)((int64_t)(*_t186) + (int64_t)((int64_t)3LL))); }
int64_t q_89 = p_52; 
while ((((((*({ hrv *_t188 = &(g883); int64_t _i188 = q_89; (uint8_t*)_t188->b + hr_ix(_i188, _t188->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:127"); }))) == (((uint8_t)32LL))) || (((*({ hrv *_t189 = &(g883); int64_t _i189 = q_89; (uint8_t*)_t189->b + hr_ix(_i189, _t189->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:127"); }))) == (((uint8_t)9LL)))) || (((*({ hrv *_t190 = &(g883); int64_t _i190 = q_89; (uint8_t*)_t190->b + hr_ix(_i190, _t190->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:127"); }))) == (((uint8_t)13LL))))) { q_89++;
 } _bk187:; 
if ((((*({ hrv *_t191 = &(g883); int64_t _i191 = q_89; (uint8_t*)_t191->b + hr_ix(_i191, _t191->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:128"); }))) != (((uint8_t)10LL)))) { while ((!((((((*({ hrv *_t193 = &(g883); int64_t _i193 = p_52; (uint8_t*)_t193->b + hr_ix(_i193, _t193->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:129"); }))) == (((uint8_t)34LL))) && (((*({ hrv *_t194 = &(g883); int64_t _i194 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)1LL))); (uint8_t*)_t194->b + hr_ix(_i194, _t194->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:129"); }))) == (((uint8_t)34LL)))) && (((*({ hrv *_t195 = &(g883); int64_t _i195 = ((int64_t)((int64_t)p_52 + (int64_t)((int64_t)2LL))); (uint8_t*)_t195->b + hr_ix(_i195, _t195->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:129"); }))) == (((uint8_t)34LL))))))) { if (((((*({ hrv *_t196 = &(g883); int64_t _i196 = p_52; (uint8_t*)_t196->b + hr_ix(_i196, _t196->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:129"); }))) == (((uint8_t)0LL))) || (((*({ hrv *_t197 = &(g883); int64_t _i197 = p_52; (uint8_t*)_t197->b + hr_ix(_i197, _t197->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:129"); }))) == (((uint8_t)10LL))))) { return f25_lerr(f_48, line_53, hr_str("unterminated \"\"\" string", 23));
 }
(void)(({ hrv *_v198 = &(g885); uint8_t _x198 = (*({ hrv *_t199 = &(g883); int64_t _i199 = p_52; (uint8_t*)_t199->b + hr_ix(_i199, _t199->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:129"); })); uint8_t *_p198 = (uint8_t*)hr_grow(_v198, 1, sizeof _x198); *_p198 = _x198; _p198; }));
p_52++;
 } _bk192:; 
{ int64_t *_t200 = &(p_52); *_t200 = ((int64_t)((int64_t)(*_t200) + (int64_t)((int64_t)3LL))); }
 } else { ml_88 = true;
int64_t first_90 = ((int64_t)((int64_t)q_89 + (int64_t)((int64_t)1LL))); 
int64_t close_91 = first_90; 
while ((!((((((*({ hrv *_t202 = &(g883); int64_t _i202 = close_91; (uint8_t*)_t202->b + hr_ix(_i202, _t202->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:135"); }))) == (((uint8_t)34LL))) && (((*({ hrv *_t203 = &(g883); int64_t _i203 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)1LL))); (uint8_t*)_t203->b + hr_ix(_i203, _t203->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:135"); }))) == (((uint8_t)34LL)))) && (((*({ hrv *_t204 = &(g883); int64_t _i204 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)2LL))); (uint8_t*)_t204->b + hr_ix(_i204, _t204->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:135"); }))) == (((uint8_t)34LL))))))) { if ((((*({ hrv *_t205 = &(g883); int64_t _i205 = close_91; (uint8_t*)_t205->b + hr_ix(_i205, _t205->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:135"); }))) == (((uint8_t)0LL)))) { return f25_lerr(f_48, line_53, hr_str("unterminated \"\"\" string", 23));
 }
close_91++;
 } _bk201:; 
int64_t cs_92 = close_91; 
while ((((cs_92) > (first_90)) && (((*({ hrv *_t207 = &(g883); int64_t _i207 = ((int64_t)((int64_t)cs_92 - (int64_t)((int64_t)1LL))); (uint8_t*)_t207->b + hr_ix(_i207, _t207->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:136"); }))) != (((uint8_t)10LL))))) { cs_92--;
 } _bk206:; 
int64_t mg_93 = ((int64_t)((int64_t)close_91 - (int64_t)cs_92)); 
{ int64_t _e209 = close_91; for (int64_t _k209 = cs_92; _k209 < _e209; _k209++) { int64_t q2_94 = (int64_t)_k209; if (((((*({ hrv *_t210 = &(g883); int64_t _i210 = q2_94; (uint8_t*)_t210->b + hr_ix(_i210, _t210->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:138"); }))) != (((uint8_t)32LL))) && (((*({ hrv *_t211 = &(g883); int64_t _i211 = q2_94; (uint8_t*)_t211->b + hr_ix(_i211, _t211->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:138"); }))) != (((uint8_t)9LL))))) { return f25_lerr(f_48, line_53, hr_str("only indentation may come before the closing \"\"\" of a multi-line string", 71));
 }
 } } _bk208:; 
int64_t l_95 = first_90; 
while (((l_95) < (cs_92))) { int64_t e_96 = l_95; 
while ((((*({ hrv *_t214 = &(g883); int64_t _i214 = e_96; (uint8_t*)_t214->b + hr_ix(_i214, _t214->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:141"); }))) != (((uint8_t)10LL)))) { e_96++;
 } _bk213:; 
int64_t te_97 = e_96; 
if ((((te_97) > (l_95)) && (((*({ hrv *_t215 = &(g883); int64_t _i215 = ((int64_t)((int64_t)te_97 - (int64_t)((int64_t)1LL))); (uint8_t*)_t215->b + hr_ix(_i215, _t215->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:142"); }))) == (((uint8_t)13LL))))) { te_97--;
 }
if (((l_95) != (first_90))) { (void)(({ hrv *_v216 = &(g885); uint8_t _x216 = ((uint8_t)10LL); uint8_t *_p216 = (uint8_t*)hr_grow(_v216, 1, sizeof _x216); *_p216 = _x216; _p216; }));
 }
bool ok_98 = ((((int64_t)((int64_t)te_97 - (int64_t)l_95))) >= (mg_93)); 
if (ok_98) { { int64_t _e218 = mg_93; for (int64_t _k218 = 0; _k218 < _e218; _k218++) { int64_t k_99 = (int64_t)_k218; if ((((*({ hrv *_t219 = &(g883); int64_t _i219 = ((int64_t)((int64_t)l_95 + (int64_t)k_99)); (uint8_t*)_t219->b + hr_ix(_i219, _t219->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:144"); }))) != ((*({ hrv *_t220 = &(g883); int64_t _i220 = ((int64_t)((int64_t)cs_92 + (int64_t)k_99)); (uint8_t*)_t220->b + hr_ix(_i220, _t220->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:144"); }))))) { ok_98 = false;
 }
 } } _bk217:; 
 }
if (ok_98) { (void)(({ hrv *_v221 = &(g885); hsl _s221 = ({ hsl _t222 = hr_sl(g883); int64_t _l222 = ((int64_t)((int64_t)l_95 + (int64_t)mg_93)), _h222 = te_97; if (_l222 < 0 || _h222 < _l222 || _h222 > _t222.n) hr_slerr(_l222, _h222, _t222.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:145"); (hsl){ _t222.p + _l222 * (int64_t)sizeof(uint8_t), _h222 - _l222 }; }); hr_append(_v221, _s221.p, _s221.n, sizeof(uint8_t)); }));
 } else { { int64_t _e224 = te_97; for (int64_t _k224 = l_95; _k224 < _e224; _k224++) { int64_t k_100 = (int64_t)_k224; if (((((*({ hrv *_t225 = &(g883); int64_t _i225 = k_100; (uint8_t*)_t225->b + hr_ix(_i225, _t225->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:145"); }))) != (((uint8_t)32LL))) && (((*({ hrv *_t226 = &(g883); int64_t _i226 = k_100; (uint8_t*)_t226->b + hr_ix(_i226, _t226->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:145"); }))) != (((uint8_t)9LL))))) { return f25_lerr(f_48, line_53, hr_str("a line of a multi-line string must start with the indentation of its closing \"\"\"", 80));
 }
 } } _bk223:; 
 }
l_95 = ((int64_t)((int64_t)e_96 + (int64_t)((int64_t)1LL)));
 } _bk212:; 
{ int64_t _e228 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)3LL))); for (int64_t _k228 = p_52; _k228 < _e228; _k228++) { int64_t k_101 = (int64_t)_k228; if ((((*({ hrv *_t229 = &(g883); int64_t _i229 = k_101; (uint8_t*)_t229->b + hr_ix(_i229, _t229->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:148"); }))) == (((uint8_t)10LL)))) { line_53++;
 }
 } } _bk227:; 
p_52 = ((int64_t)((int64_t)close_91 + (int64_t)((int64_t)3LL)));
 }
 } else { p_52++;
while ((((*({ hrv *_t231 = &(g883); int64_t _i231 = p_52; (uint8_t*)_t231->b + hr_ix(_i231, _t231->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:153"); }))) != (((uint8_t)34LL)))) { if (((((*({ hrv *_t232 = &(g883); int64_t _i232 = p_52; (uint8_t*)_t232->b + hr_ix(_i232, _t232->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:153"); }))) == (((uint8_t)10LL))) || (((*({ hrv *_t233 = &(g883); int64_t _i233 = p_52; (uint8_t*)_t233->b + hr_ix(_i233, _t233->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:153"); }))) == (((uint8_t)0LL))))) { return f25_lerr(f_48, line_53, hr_str("unterminated string literal", 27));
 }
int64_t v_102 = f30_esc((&(p_52)), f_48, line_53); 
if (((v_102) < (((int64_t)0LL)))) { return false;
 }
(void)(({ hrv *_v234 = &(g885); uint8_t _x234 = ((uint8_t)(v_102)); uint8_t *_p234 = (uint8_t*)hr_grow(_v234, 1, sizeof _x234); *_p234 = _x234; _p234; }));
 } _bk230:; 
p_52++;
 }
(void)(f24_put(((int64_t)4LL), s_63, p_52, &f_48, &line_53));
{ int64_t *_t235 = &(((*({ hrv *_t236 = &(g889); int64_t _i236 = ((int64_t)((int64_t)(g889).n - (int64_t)((int64_t)1LL))); (S3*)_t236->b + hr_ix(_i236, _t236->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:156"); }))).v_); *_t235 = ss_87; }
{ int32_t *_t237 = &(((*({ hrv *_t238 = &(g889); int64_t _i238 = ((int64_t)((int64_t)(g889).n - (int64_t)((int64_t)1LL))); (S3*)_t238->b + hr_ix(_i238, _t238->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:156"); }))).w_); *_t237 = ((int32_t)(((int64_t)((int64_t)(g885).n - (int64_t)ss_87)))); }
{ bool *_t239 = &(((*({ hrv *_t240 = &(g889); int64_t _i240 = ((int64_t)((int64_t)(g889).n - (int64_t)((int64_t)1LL))); (S3*)_t240->b + hr_ix(_i240, _t240->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:156"); }))).ml_); *_t239 = ml_88; }
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
 } else { if ((((n1_64) == (((uint8_t)61LL))) && ((n2_65) == (((uint8_t)61LL))))) { { int64_t *_t241 = &(p_52); *_t241 = ((int64_t)((int64_t)(*_t241) + (int64_t)((int64_t)2LL))); }
k_103 = ((int64_t)19LL);
 } else { if ((((n1_64) == (((uint8_t)33LL))) && ((n2_65) == (((uint8_t)61LL))))) { { int64_t *_t242 = &(p_52); *_t242 = ((int64_t)((int64_t)(*_t242) + (int64_t)((int64_t)2LL))); }
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
 } else { if ((((n1_64) == (((uint8_t)60LL))) && ((n2_65) == (((uint8_t)61LL))))) { { int64_t *_t243 = &(p_52); *_t243 = ((int64_t)((int64_t)(*_t243) + (int64_t)((int64_t)2LL))); }
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
 } else { if ((((n1_64) == (((uint8_t)62LL))) && ((n2_65) == (((uint8_t)61LL))))) { { int64_t *_t244 = &(p_52); *_t244 = ((int64_t)((int64_t)(*_t244) + (int64_t)((int64_t)2LL))); }
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
 } _bk119:; 
return true;
}
static void f24_put(int64_t k_54, int64_t s_55, int64_t e_56, int64_t *c48, int64_t *c53) {
(void)(({ hrv *_v245 = &(g889); S3 _x245 = ((S3){ .k_ = ((uint8_t)(k_54)), .f_ = ((uint16_t)((*c48))), .line_ = ((int32_t)((*c53))), .s_ = ((int32_t)(s_55)), .n_ = ((int32_t)(((int64_t)((int64_t)e_56 - (int64_t)s_55)))), }); S3 *_p245 = (S3*)hr_grow(_v245, 1, sizeof _x245); *_p245 = _x245; _p245; }));
}
static bool f25_lerr(int64_t f_60, int64_t line_61, hsl m_62) {
if ((((g890).n) == (((int64_t)0LL)))) { (void)(({ hrv *_v246 = &(g890); hsl _s246 = f10_nm(((int64_t)(((*({ hrv *_t247 = &(g888); int64_t _i247 = f_60; (S2*)_t247->b + hr_ix(_i247, _t247->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:52"); }))).name_))); hr_append(_v246, _s246.p, _s246.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o248 = &(g890); hr_fs(_o248, hr_str(":", 1)); hr_fi(_o248, line_61); hr_fs(_o248, hr_str(": error: ", 9)); hr_fs(_o248, m_62); }));
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
return ({ int64_t _r249; if (((c_72) <= (((uint8_t)57LL)))) { _r249 = ((int64_t)(((uint8_t)((uint64_t)c_72 - (uint64_t)((uint8_t)48LL)))));  } else { _r249 = ((int64_t)((int64_t)((int64_t)(((uint8_t)((uint64_t)((uint8_t)((uint64_t)c_72 | (uint64_t)((uint8_t)32LL))) - (uint64_t)((uint8_t)97LL))))) + (int64_t)((int64_t)10LL)));  } _r249; });
}
static bool f29_idc(uint8_t c_77) {
return ((((((c_77) >= (((uint8_t)97LL))) && ((c_77) <= (((uint8_t)122LL)))) || (((c_77) >= (((uint8_t)65LL))) && ((c_77) <= (((uint8_t)90LL))))) || ((c_77) == (((uint8_t)95LL)))) || (((c_77) >= (((uint8_t)48LL))) && ((c_77) <= (((uint8_t)57LL)))));
}
static int64_t f30_esc(int64_t* p_80, int64_t f_81, int64_t line_82) {
uint8_t c_83 = (*({ hrv *_t250 = &(g883); int64_t _i250 = (*p_80); (uint8_t*)_t250->b + hr_ix(_i250, _t250->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:54"); })); 
(*p_80)++;
if (((c_83) != (((uint8_t)92LL)))) { return ((int64_t)(c_83));
 }
uint8_t e_84 = (*({ hrv *_t251 = &(g883); int64_t _i251 = (*p_80); (uint8_t*)_t251->b + hr_ix(_i251, _t251->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:56"); })); 
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
if (((((e_84) == (((uint8_t)120LL))) && f27_hexd((*({ hrv *_t252 = &(g883); int64_t _i252 = (*p_80); (uint8_t*)_t252->b + hr_ix(_i252, _t252->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:59"); })))) && f27_hexd((*({ hrv *_t253 = &(g883); int64_t _i253 = ((int64_t)((int64_t)(*p_80) + (int64_t)((int64_t)1LL))); (uint8_t*)_t253->b + hr_ix(_i253, _t253->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:59"); }))))) { int64_t v_85 = ((int64_t)((int64_t)((int64_t)((int64_t)f28_hexv((*({ hrv *_t254 = &(g883); int64_t _i254 = (*p_80); (uint8_t*)_t254->b + hr_ix(_i254, _t254->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:59"); }))) * (int64_t)((int64_t)16LL))) + (int64_t)f28_hexv((*({ hrv *_t255 = &(g883); int64_t _i255 = ((int64_t)((int64_t)(*p_80) + (int64_t)((int64_t)1LL))); (uint8_t*)_t255->b + hr_ix(_i255, _t255->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:59"); }))))); 
{ int64_t *_t256 = p_80; *_t256 = ((int64_t)((int64_t)(*_t256) + (int64_t)((int64_t)2LL))); }
return v_85;
 }
(void)(f25_lerr(f_81, line_82, hr_str("unknown escape sequence", 23)));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f31_tk(void) {
return ((int64_t)(((*({ hrv *_t257 = &(g889); int64_t _i257 = g684; (S3*)_t257->b + hr_ix(_i257, _t257->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:32"); }))).k_));
}
static void f32_ptop(void) {
int64_t st_104 = g684; 
g691 = g692;
int64_t k_105 = f31_tk(); 
if (((k_105) == (((int64_t)57LL)))) { (void)(f33_nx());
g692 = f34_ident(hr_str("namespace declaration", 21));
g691 = g692;
(void)(f39_ex(((int64_t)12LL), hr_str("namespace declaration", 21)));
return;
 }
if (((k_105) == (((int64_t)56LL)))) { (void)(f33_nx());
int64_t n_121 = f40_mk(((int64_t)54LL), st_104); 
if (f41_is(((int64_t)16LL))) { { uint16_t *_t258 = &(((*({ hrv *_t259 = &(g679); int64_t _i259 = n_121; (S4*)_t259->b + hr_ix(_i259, _t259->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:699"); }))).fl_); *_t258 = ((uint16_t)1LL); }
 }
hrv path_123 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v261 = &(path_123); hsl _s261 = f10_nm(f34_ident(hr_str("import", 6))); hr_append(_v261, _s261.p, _s261.n, sizeof(uint8_t)); }));
while (f41_is(((int64_t)16LL))) { (void)(({ hrv *_v263 = &(path_123); uint8_t _x263 = ((uint8_t)47LL); uint8_t *_p263 = (uint8_t*)hr_grow(_v263, 1, sizeof _x263); *_p263 = _x263; _p263; }));
(void)(({ hrv *_v264 = &(path_123); hsl _s264 = f10_nm(f34_ident(hr_str("import", 6))); hr_append(_v264, _s264.p, _s264.n, sizeof(uint8_t)); }));
 } _bk262:; 
{ int64_t q__124 = f8_intern(hr_sl(path_123)); 
{ int32_t *_t265 = &(((*({ hrv *_t266 = &(g679); int64_t _i266 = n_121; (S4*)_t266->b + hr_ix(_i266, _t266->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:703"); }))).s_); *_t265 = ((int32_t)(q__124)); }
 }
if ((f42_at_from() || f43_at_word(g696))) { (void)(f33_nx());
if (((f31_tk()) != (((int64_t)4LL)))) { (void)(f38_perr(hr_str("expected the package's source, a string, after from", 51)));
 }
{ int32_t *_t267 = &(((*({ hrv *_t268 = &(g679); int64_t _i268 = n_121; (S4*)_t268->b + hr_ix(_i268, _t268->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:704"); }))).a_); *_t267 = ((int32_t)(g684)); }
(void)(f33_nx());
 }
(void)(f39_ex(((int64_t)12LL), hr_str("import", 6)));
(void)(({ hrv *_v269 = &(g682); int32_t _x269 = ((int32_t)(n_121)); int32_t *_p269 = (int32_t*)hr_grow(_v269, 1, sizeof _x269); *_p269 = _x269; _p269; }));
return;
 }
if (((f46_at_inline() || f47_at_checkfree()) || f48_at_lut())) { (void)(({ hrv *_v270 = &(g682); int32_t _x270 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p270 = (int32_t*)hr_grow(_v270, 1, sizeof _x270); *_p270 = _x270; _p270; }));
return;
 }
if (((k_105) == (((int64_t)58LL)))) { (void)(({ hrv *_v271 = &(g682); int32_t _x271 = ((int32_t)(f94_pstruct())); int32_t *_p271 = (int32_t*)hr_grow(_v271, 1, sizeof _x271); *_p271 = _x271; _p271; }));
return;
 }
if (((k_105) == (((int64_t)59LL)))) { (void)(({ hrv *_v272 = &(g682); int32_t _x272 = ((int32_t)(f96_penum())); int32_t *_p272 = (int32_t*)hr_grow(_v272, 1, sizeof _x272); *_p272 = _x272; _p272; }));
return;
 }
if (((k_105) == (((int64_t)60LL)))) { (void)(f33_nx());
int64_t n_433 = f40_mk(((int64_t)53LL), st_104); 
{ int64_t q__434 = f50_declname(hr_str("type alias", 10)); 
{ int32_t *_t273 = &(((*({ hrv *_t274 = &(g679); int64_t _i274 = n_433; (S4*)_t274->b + hr_ix(_i274, _t274->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:712"); }))).s_); *_t273 = ((int32_t)(q__434)); }
 }
{ int32_t *_t275 = &(((*({ hrv *_t276 = &(g679); int64_t _i276 = n_433; (S4*)_t276->b + hr_ix(_i276, _t276->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:712"); }))).a_); *_t275 = ((int32_t)(g691)); }
(void)(f39_ex(((int64_t)36LL), hr_str("type alias", 10)));
{ int64_t q__435 = f53_ptype(); 
{ int32_t *_t277 = &(((*({ hrv *_t278 = &(g679); int64_t _i278 = n_433; (S4*)_t278->b + hr_ix(_i278, _t278->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:712"); }))).b_); *_t277 = ((int32_t)(q__435)); }
 }
(void)(f39_ex(((int64_t)12LL), hr_str("type alias", 10)));
(void)(({ hrv *_v279 = &(g682); int32_t _x279 = ((int32_t)(n_433)); int32_t *_p279 = (int32_t*)hr_grow(_v279, 1, sizeof _x279); *_p279 = _x279; _p279; }));
return;
 }
if (((k_105) == (((int64_t)68LL)))) { (void)(f33_nx());
int64_t cs_436 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((f31_tk()) == (((int64_t)4LL)))) { cs_436 = g684;
(void)(f33_nx());
 }
if (((f31_tk()) == (((int64_t)9LL)))) { if (((cs_436) < (((int64_t)0LL)))) { (void)(f38_perr(hr_str("an extern block names the library it binds from: extern \"lib\" {", 63)));
 }
(void)(f33_nx());
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v281 = &(g682); int32_t _x281 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), cs_436))); int32_t *_p281 = (int32_t*)hr_grow(_v281, 1, sizeof _x281); *_p281 = _x281; _p281; }));
 } _bk280:; 
(void)(f39_ex(((int64_t)10LL), hr_str("extern block", 12)));
return;
 }
g684--;
if (((cs_436) >= (((int64_t)0LL)))) { g684--;
 }
(void)(({ hrv *_v282 = &(g682); int32_t _x282 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p282 = (int32_t*)hr_grow(_v282, 1, sizeof _x282); *_p282 = _x282; _p282; }));
return;
 }
if (((((((k_105) == (((int64_t)65LL))) || ((k_105) == (((int64_t)61LL)))) || ((k_105) == (((int64_t)62LL)))) || ((k_105) == (((int64_t)63LL)))) || ((k_105) == (((int64_t)64LL))))) { (void)(({ hrv *_v283 = &(g682); int32_t _x283 = ((int32_t)(f49_pfn(false, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p283 = (int32_t*)hr_grow(_v283, 1, sizeof _x283); *_p283 = _x283; _p283; }));
return;
 }
if ((((((k_105) == (((int64_t)71LL))) || ((k_105) == (((int64_t)66LL)))) || ((k_105) == (((int64_t)67LL)))) || ((k_105) == (((int64_t)69LL))))) { int64_t v_437 = f74_pvdecl(true); 
(void)(f39_ex(((int64_t)12LL), hr_str("global declaration", 18)));
(void)(({ hrv *_v284 = &(g682); int32_t _x284 = ((int32_t)(v_437)); int32_t *_p284 = (int32_t*)hr_grow(_v284, 1, sizeof _x284); *_p284 = _x284; _p284; }));
return;
 }
hrv m_438 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o286 = &(m_438); hr_fs(_o286, hr_str("top-level declaration expected, found '", 39)); hr_fs(_o286, f35_cur_text()); hr_fs(_o286, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_438)));
}
static void f33_nx(void) {
if (((((*({ hrv *_t287 = &(g889); int64_t _i287 = g684; (S3*)_t287->b + hr_ix(_i287, _t287->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:34"); }))).k_) != (((uint8_t)0LL)))) { g684++;
 }
}
static int64_t f34_ident(hsl ctx_106) {
if (((f31_tk()) != (((int64_t)1LL)))) { hrv m_107 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o289 = &(m_107); hr_fs(_o289, hr_str("expected identifier in ", 23)); hr_fs(_o289, ctx_106); hr_fs(_o289, hr_str(", found '", 9)); hr_fs(_o289, f35_cur_text()); hr_fs(_o289, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_107)));
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t v_115 = ((int64_t)(((*({ hrv *_t290 = &(g889); int64_t _i290 = g684; (S3*)_t290->b + hr_ix(_i290, _t290->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:51"); }))).v_)); 
(void)(f33_nx());
return v_115;
}
static hsl f35_cur_text(void) {
int64_t k_108 = f31_tk(); 
return ({ hsl _r291; if (((((k_108) == (((int64_t)1LL))) || ((k_108) == (((int64_t)2LL)))) || ((k_108) == (((int64_t)3LL))))) { _r291 = f36_tok_text(g684);  } else { _r291 = f37_tname(k_108);  } _r291; });
}
static hsl f36_tok_text(int64_t t_109) {
S3 x_110 = (*({ hrv *_t292 = &(g889); int64_t _i292 = t_109; (S3*)_t292->b + hr_ix(_i292, _t292->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:181"); })); 
return ({ hsl _t293 = hr_sl(g883); int64_t _l293 = ((int64_t)((x_110).s_)), _h293 = ((int64_t)(((int32_t)((int64_t)(x_110).s_ + (int64_t)(x_110).n_)))); if (_l293 < 0 || _h293 < _l293 || _h293 > _t293.n) hr_slerr(_l293, _h293, _t293.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:181"); (hsl){ _t293.p + _l293 * (int64_t)sizeof(uint8_t), _h293 - _l293 }; });
}
static hsl f37_tname(int64_t k_111) {
A39 pu_112 = ({ A39 _t294; _t294.e[0] = hr_str("(", 1); _t294.e[1] = hr_str(")", 1); _t294.e[2] = hr_str("[", 1); _t294.e[3] = hr_str("]", 1); _t294.e[4] = hr_str("{", 1); _t294.e[5] = hr_str("}", 1); _t294.e[6] = hr_str(",", 1); _t294.e[7] = hr_str(";", 1); _t294.e[8] = hr_str(":", 1); _t294.e[9] = hr_str("\077", 1); _t294.e[10] = hr_str("::", 2); _t294.e[11] = hr_str(".", 1); _t294.e[12] = hr_str("..", 2); _t294.e[13] = hr_str(".=", 2); _t294.e[14] = hr_str(".==", 3); _t294.e[15] = hr_str(".!=", 3); _t294.e[16] = hr_str("+", 1); _t294.e[17] = hr_str("-", 1); _t294.e[18] = hr_str("*", 1); _t294.e[19] = hr_str("/", 1); _t294.e[20] = hr_str("%", 1); _t294.e[21] = hr_str("+=", 2); _t294.e[22] = hr_str("-=", 2); _t294.e[23] = hr_str("*=", 2); _t294.e[24] = hr_str("/=", 2); _t294.e[25] = hr_str("%=", 2); _t294.e[26] = hr_str("&=", 2); _t294.e[27] = hr_str("|=", 2); _t294.e[28] = hr_str("^=", 2); _t294.e[29] = hr_str("++", 2); _t294.e[30] = hr_str("--", 2); _t294.e[31] = hr_str("=", 1); _t294.e[32] = hr_str("==", 2); _t294.e[33] = hr_str("!=", 2); _t294.e[34] = hr_str("<", 1); _t294.e[35] = hr_str(">", 1); _t294.e[36] = hr_str("<=", 2); _t294.e[37] = hr_str(">=", 2); _t294.e[38] = hr_str("<<", 2); _t294.e[39] = hr_str(">>", 2); _t294.e[40] = hr_str("<<=", 3); _t294.e[41] = hr_str(">>=", 3); _t294.e[42] = hr_str("!", 1); _t294.e[43] = hr_str("~", 1); _t294.e[44] = hr_str("&", 1); _t294.e[45] = hr_str("|", 1); _t294.e[46] = hr_str("^", 1); _t294.e[47] = hr_str("&&", 2); _t294.e[48] = hr_str("||", 2); _t294.e[49] = hr_str("->", 2); _t294.e[50] = hr_str("=>", 2); _t294; }); 
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
if (((g686) > (((int64_t)0LL)))) { g687 = true;
g684 = ((int64_t)((int64_t)(g889).n - (int64_t)((int64_t)1LL)));
return;
 }
if ((((g685).n) > (((int64_t)0LL)))) { return;
 }
S3 t_114 = (*({ hrv *_t296 = &(g889); int64_t _i296 = g684; (S3*)_t296->b + hr_ix(_i296, _t296->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:45"); })); 
(void)(({ hrv *_v297 = &(g685); hsl _s297 = f10_nm(((int64_t)(((*({ hrv *_t298 = &(g888); int64_t _i298 = (t_114).f_; (S2*)_t298->b + hr_ix(_i298, _t298->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:46"); }))).name_))); hr_append(_v297, _s297.p, _s297.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o299 = &(g685); hr_fs(_o299, hr_str(":", 1)); hr_fi(_o299, (t_114).line_); hr_fs(_o299, hr_str(": error: ", 9)); hr_fs(_o299, m_113); }));
g684 = ((int64_t)((int64_t)(g889).n - (int64_t)((int64_t)1LL)));
}
static void f39_ex(int64_t k_116, hsl ctx_117) {
if (((f31_tk()) != (k_116))) { hrv m_118 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o301 = &(m_118); hr_fs(_o301, hr_str("expected '", 10)); hr_fs(_o301, f37_tname(k_116)); hr_fs(_o301, hr_str("' in ", 5)); hr_fs(_o301, ctx_117); hr_fs(_o301, hr_str(", found '", 9)); hr_fs(_o301, f35_cur_text()); hr_fs(_o301, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_118)));
return;
 }
(void)(f33_nx());
}
static int64_t f40_mk(int64_t k_119, int64_t t_120) {
(void)(({ hrv *_v302 = &(g679); S4 _x302 = ((S4){ .k_ = ((uint8_t)(k_119)), .t_ = ((int32_t)(t_120)), .a_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .b_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .d_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .e_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .s_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .l_ = ((int32_t)0LL), .n_ = ((int32_t)0LL), }); S4 *_p302 = (S4*)hr_grow(_v302, 1, sizeof _x302); *_p302 = _x302; _p302; }));
return ((int64_t)((int64_t)(g679).n - (int64_t)((int64_t)1LL)));
}
static bool f41_is(int64_t k_122) {
if (((f31_tk()) == (k_122))) { (void)(f33_nx());
return true;
 }
return false;
}
static bool f42_at_from(void) {
return (f43_at_word(g696) && (((f44_tkat(((int64_t)((int64_t)g684 + (int64_t)((int64_t)1LL))))) == (((int64_t)1LL))) || ((f44_tkat(((int64_t)((int64_t)g684 + (int64_t)((int64_t)1LL))))) == (((int64_t)15LL)))));
}
static bool f43_at_word(int64_t w_125) {
return (((f31_tk()) == (((int64_t)1LL))) && ((((*({ hrv *_t303 = &(g889); int64_t _i303 = g684; (S3*)_t303->b + hr_ix(_i303, _t303->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:69"); }))).v_) == (w_125)));
}
static int64_t f44_tkat(int64_t i_126) {
return ((int64_t)(((*({ hrv *_t304 = &(g889); int64_t _i304 = f45_min(i_126, ((int64_t)((int64_t)(g889).n - (int64_t)((int64_t)1LL)))); (S3*)_t304->b + hr_ix(_i304, _t304->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:33"); }))).k_));
}
static int64_t f45_min(int64_t a_127, int64_t b_128) {
if (((b_128) < (a_127))) { return b_128;
 }
return a_127;
}
static bool f46_at_inline(void) {
return (f43_at_word(g697) && ((((f44_tkat(((int64_t)((int64_t)g684 + (int64_t)((int64_t)1LL))))) == (((int64_t)61LL))) || ((f44_tkat(((int64_t)((int64_t)g684 + (int64_t)((int64_t)1LL))))) == (((int64_t)65LL)))) || ((f44_tkat(((int64_t)((int64_t)g684 + (int64_t)((int64_t)1LL))))) == (((int64_t)62LL)))));
}
static bool f47_at_checkfree(void) {
int64_t n_129 = f44_tkat(((int64_t)((int64_t)g684 + (int64_t)((int64_t)1LL)))); 
return (f43_at_word(g698) && (((((((n_129) == (((int64_t)61LL))) || ((n_129) == (((int64_t)65LL)))) || ((n_129) == (((int64_t)62LL)))) || ((n_129) == (((int64_t)64LL)))) || ((n_129) == (((int64_t)68LL)))) || ((n_129) == (((int64_t)1LL)))));
}
static bool f48_at_lut(void) {
return (f43_at_word(g699) && ((f44_tkat(((int64_t)((int64_t)g684 + (int64_t)((int64_t)1LL))))) == (((int64_t)61LL))));
}
static int64_t f49_pfn(bool nested_130, int64_t cname_131, int64_t dylib_132) {
int64_t st_133 = g684; 
int64_t n_134 = f40_mk(((int64_t)50LL), st_133); 
int64_t fl_135 = ({ int64_t _r305; if (nested_130) { _r305 = ((int64_t)128LL);  } else { _r305 = ((int64_t)0LL);  } _r305; }); 
int64_t cn_136 = cname_131; 
if ((((cname_131) >= (((int64_t)0LL))) || ((dylib_132) >= (((int64_t)0LL))))) { { int64_t *_t306 = &(fl_135); *_t306 = ((int64_t)((int64_t)(*_t306) | (int64_t)((int64_t)1LL))); }
 }
if (f48_at_lut()) { (void)(f33_nx());
{ int64_t *_t307 = &(fl_135); *_t307 = ((int64_t)((int64_t)(*_t307) | (int64_t)((int64_t)256LL))); }
 }
if (f47_at_checkfree()) { (void)(f33_nx());
{ int64_t *_t308 = &(fl_135); *_t308 = ((int64_t)((int64_t)(*_t308) | (int64_t)((int64_t)64LL))); }
 }
if (f41_is(((int64_t)63LL))) { { int64_t *_t309 = &(fl_135); *_t309 = ((int64_t)((int64_t)(*_t309) | (int64_t)((int64_t)2LL))); }
if (((f31_tk()) == (((int64_t)4LL)))) { cn_136 = g684;
(void)(f33_nx());
 }
 }
if (f41_is(((int64_t)68LL))) { { int64_t *_t310 = &(fl_135); *_t310 = ((int64_t)((int64_t)(*_t310) | (int64_t)((int64_t)1LL))); }
if (((f31_tk()) == (((int64_t)4LL)))) { cn_136 = g684;
(void)(f33_nx());
 }
 }
if (f47_at_checkfree()) { (void)(f33_nx());
{ int64_t *_t311 = &(fl_135); *_t311 = ((int64_t)((int64_t)(*_t311) | (int64_t)((int64_t)64LL))); }
 }
if (f41_is(((int64_t)64LL))) { { int64_t *_t312 = &(fl_135); *_t312 = ((int64_t)((int64_t)(*_t312) | (int64_t)((int64_t)4LL))); }
 }
if (f46_at_inline()) { (void)(f33_nx());
{ int64_t *_t313 = &(fl_135); *_t313 = ((int64_t)((int64_t)(*_t313) | (int64_t)((int64_t)8LL))); }
 }
if (f41_is(((int64_t)65LL))) { { int64_t *_t314 = &(fl_135); *_t314 = ((int64_t)((int64_t)(*_t314) | (int64_t)((int64_t)16LL))); }
 }
if (f41_is(((int64_t)62LL))) { { int64_t *_t315 = &(fl_135); *_t315 = ((int64_t)((int64_t)(*_t315) | (int64_t)((int64_t)32LL))); }
 } else { (void)(f39_ex(((int64_t)61LL), hr_str("function declaration", 20)));
 }
{ int64_t q__139 = ({ int64_t _r316; if (nested_130) { _r316 = f34_ident(hr_str("function declaration", 20));  } else { _r316 = f50_declname(hr_str("function declaration", 20));  } _r316; }); 
{ int32_t *_t317 = &(((*({ hrv *_t318 = &(g679); int64_t _i318 = n_134; (S4*)_t318->b + hr_ix(_i318, _t318->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:657"); }))).s_); *_t317 = ((int32_t)(q__139)); }
 }
{ int32_t *_t319 = &(((*({ hrv *_t320 = &(g679); int64_t _i320 = n_134; (S4*)_t320->b + hr_ix(_i320, _t320->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:658"); }))).a_); *_t319 = ((int32_t)(g691)); }
{ int64_t q__403 = f51_pgenerics(); 
{ int32_t *_t321 = &(((*({ hrv *_t322 = &(g679); int64_t _i322 = n_134; (S4*)_t322->b + hr_ix(_i322, _t322->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:659"); }))).d_); *_t321 = ((int32_t)(q__403)); }
 }
(void)(f39_ex(((int64_t)5LL), hr_str("function declaration", 20)));
int64_t m_404 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t p_405 = f40_mk(((int64_t)32LL), g684); 
if (f41_is(((int64_t)67LL))) { { uint16_t *_t324 = &(((*({ hrv *_t325 = &(g679); int64_t _i325 = p_405; (S4*)_t325->b + hr_ix(_i325, _t325->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:664"); }))).fl_); *_t324 = ((uint16_t)1LL); }
 }
{ int64_t q__406 = f34_ident(hr_str("parameter list", 14)); 
{ int32_t *_t326 = &(((*({ hrv *_t327 = &(g679); int64_t _i327 = p_405; (S4*)_t327->b + hr_ix(_i327, _t327->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:665"); }))).s_); *_t326 = ((int32_t)(q__406)); }
 }
if ((f41_is(((int64_t)13LL)) || f75_amni_type())) { { int64_t q__407 = f53_ptype(); 
{ int32_t *_t328 = &(((*({ hrv *_t329 = &(g679); int64_t _i329 = p_405; (S4*)_t329->b + hr_ix(_i329, _t329->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:666"); }))).a_); *_t328 = ((int32_t)(q__407)); }
 }
 }
if (f41_is(((int64_t)36LL))) { { int64_t q__408 = f61_pexpr(); 
{ int32_t *_t330 = &(((*({ hrv *_t331 = &(g679); int64_t _i331 = p_405; (S4*)_t331->b + hr_ix(_i331, _t331->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:667"); }))).b_); *_t330 = ((int32_t)(q__408)); }
 }
 }
(void)(({ hrv *_v332 = &(g681); int32_t _x332 = ((int32_t)(p_405)); int32_t *_p332 = (int32_t*)hr_grow(_v332, 1, sizeof _x332); *_p332 = _x332; _p332; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk323; }
 }
 } _bk323:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function declaration", 20)));
(void)(f59_setl(n_134, m_404));
if ((f41_is(((int64_t)54LL)) || f75_amni_type())) { { int64_t *_t333 = &(fl_135); *_t333 = ((int64_t)((int64_t)(*_t333) | (int64_t)((int64_t)512LL))); }
int64_t r_409 = f40_mk(((int64_t)36LL), g684); 
int64_t m2_410 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v335 = &(g681); int32_t _x335 = ((int32_t)(f53_ptype())); int32_t *_p335 = (int32_t*)hr_grow(_v335, 1, sizeof _x335); *_p335 = _x335; _p335; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk334; }
 }
 } _bk334:; 
(void)(f59_setl(r_409, m2_410));
{ int32_t *_t336 = &(((*({ hrv *_t337 = &(g679); int64_t _i337 = n_134; (S4*)_t337->b + hr_ix(_i337, _t337->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:677"); }))).b_); *_t336 = ((int32_t)(r_409)); }
 }
if (((((int64_t)((int64_t)fl_135 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)))) { if (f41_is(((int64_t)36LL))) { if (((f31_tk()) != (((int64_t)4LL)))) { (void)(f38_perr(hr_str("an extern fn's symbol is a string: fn name(...) = \"symbol\"; (\302\2477.10)", 68)));
 }
cn_136 = g684;
(void)(f33_nx());
 }
(void)(f39_ex(((int64_t)12LL), hr_str("extern declaration", 18)));
int64_t x_411 = f40_mk(((int64_t)58LL), st_133); 
{ int32_t *_t338 = &(((*({ hrv *_t339 = &(g679); int64_t _i339 = x_411; (S4*)_t339->b + hr_ix(_i339, _t339->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:682"); }))).a_); *_t338 = ((int32_t)(cn_136)); }
{ int32_t *_t340 = &(((*({ hrv *_t341 = &(g679); int64_t _i341 = x_411; (S4*)_t341->b + hr_ix(_i341, _t341->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:682"); }))).b_); *_t340 = ((int32_t)(dylib_132)); }
{ int32_t *_t342 = &(((*({ hrv *_t343 = &(g679); int64_t _i343 = n_134; (S4*)_t343->b + hr_ix(_i343, _t343->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:682"); }))).e_); *_t342 = ((int32_t)(x_411)); }
 } else { if (((((int64_t)((int64_t)fl_135 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { int64_t x_412 = f40_mk(((int64_t)58LL), st_133); 
{ int32_t *_t344 = &(((*({ hrv *_t345 = &(g679); int64_t _i345 = x_412; (S4*)_t345->b + hr_ix(_i345, _t345->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:684"); }))).a_); *_t344 = ((int32_t)(cn_136)); }
{ int32_t *_t346 = &(((*({ hrv *_t347 = &(g679); int64_t _i347 = n_134; (S4*)_t347->b + hr_ix(_i347, _t347->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:684"); }))).e_); *_t346 = ((int32_t)(x_412)); }
 }
{ int64_t q__413 = f66_pblock(hr_str("function body", 13)); 
{ int32_t *_t348 = &(((*({ hrv *_t349 = &(g679); int64_t _i349 = n_134; (S4*)_t349->b + hr_ix(_i349, _t349->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:685"); }))).c_); *_t348 = ((int32_t)(q__413)); }
 }
 }
{ uint16_t *_t350 = &(((*({ hrv *_t351 = &(g679); int64_t _i351 = n_134; (S4*)_t351->b + hr_ix(_i351, _t351->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:687"); }))).fl_); *_t350 = ((uint16_t)(fl_135)); }
(void)(f88_set_end(n_134));
return n_134;
}
static int64_t f50_declname(hsl ctx_137) {
int64_t a_138 = ({ int64_t _r352; if (((f31_tk()) == (((int64_t)15LL)))) { _r352 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r352 = f34_ident(ctx_137);  } _r352; }); 
if (f41_is(((int64_t)15LL))) { g691 = a_138;
return f34_ident(ctx_137);
 }
return a_138;
}
static int64_t f51_pgenerics(void) {
if ((!(f41_is(((int64_t)39LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t l_140 = f40_mk(((int64_t)36LL), g684); 
int64_t m_141 = f52_wbeg(); 
for (;;) { int64_t g_142 = f40_mk(((int64_t)57LL), g684); 
{ int64_t q__143 = f34_ident(hr_str("generic parameter list", 22)); 
{ int32_t *_t354 = &(((*({ hrv *_t355 = &(g679); int64_t _i355 = g_142; (S4*)_t355->b + hr_ix(_i355, _t355->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:587"); }))).s_); *_t354 = ((int32_t)(q__143)); }
 }
if (f41_is(((int64_t)13LL))) { { int64_t q__402 = f53_ptype(); 
{ int32_t *_t356 = &(((*({ hrv *_t357 = &(g679); int64_t _i357 = g_142; (S4*)_t357->b + hr_ix(_i357, _t357->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:588"); }))).a_); *_t356 = ((int32_t)(q__402)); }
 }
 }
(void)(({ hrv *_v358 = &(g681); int32_t _x358 = ((int32_t)(g_142)); int32_t *_p358 = (int32_t*)hr_grow(_v358, 1, sizeof _x358); *_p358 = _x358; _p358; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk353; }
 }
if ((((f31_tk()) == (((int64_t)40LL))) || ((f31_tk()) == (((int64_t)44LL))))) { { goto _bk353; }
 }
 } _bk353:; 
(void)(f58_close_angle(hr_str("generic parameter list", 22)));
(void)(f59_setl(l_140, m_141));
return l_140;
}
static int64_t f52_wbeg(void) {
return (g681).n;
}
static int64_t f53_ptype(void) {
bool cq_144 = f41_is(((int64_t)69LL)); 
int64_t t_175 = f54_ptype_prim(); 
bool q_176 = cq_144; 
for (;;) { int64_t st_177 = g684; 
if (f41_is(((int64_t)7LL))) { if (f41_is(((int64_t)13LL))) { (void)(f39_ex(((int64_t)8LL), hr_str("slice type", 10)));
int64_t n_178 = f40_mk(((int64_t)43LL), st_177); 
{ int32_t *_t360 = &(((*({ hrv *_t361 = &(g679); int64_t _i361 = n_178; (S4*)_t361->b + hr_ix(_i361, _t361->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:84"); }))).a_); *_t360 = ((int32_t)(t_175)); }
if (q_176) { { uint16_t *_t362 = &(((*({ hrv *_t363 = &(g679); int64_t _i363 = n_178; (S4*)_t363->b + hr_ix(_i363, _t363->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:84"); }))).fl_); *_t362 = ((uint16_t)1LL); }
q_176 = false;
 }
t_175 = n_178;
continue;
 }
int64_t n_179 = f40_mk(((int64_t)42LL), st_177); 
{ int32_t *_t364 = &(((*({ hrv *_t365 = &(g679); int64_t _i365 = n_179; (S4*)_t365->b + hr_ix(_i365, _t365->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:85"); }))).a_); *_t364 = ((int32_t)(t_175)); }
if (f41_is(((int64_t)8LL))) { { uint8_t *_t366 = &(((*({ hrv *_t367 = &(g679); int64_t _i367 = n_179; (S4*)_t367->b + hr_ix(_i367, _t367->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:86"); }))).op_); *_t366 = ((uint8_t)(((uint8_t)2LL))); }
t_175 = n_179;
continue;
 }
if (f41_is(((int64_t)17LL))) { { uint8_t *_t368 = &(((*({ hrv *_t369 = &(g679); int64_t _i369 = n_179; (S4*)_t369->b + hr_ix(_i369, _t369->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:87"); }))).op_); *_t368 = ((uint8_t)(((uint8_t)3LL))); }
if (((f31_tk()) != (((int64_t)8LL)))) { { int64_t q__391 = f61_pexpr(); 
{ int32_t *_t370 = &(((*({ hrv *_t371 = &(g679); int64_t _i371 = n_179; (S4*)_t371->b + hr_ix(_i371, _t371->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:87"); }))).b_); *_t370 = ((int32_t)(q__391)); }
 }
 }
 } else { if (f41_is(((int64_t)40LL))) { (void)(f39_ex(((int64_t)17LL), hr_str("resizable array type", 20)));
{ uint8_t *_t372 = &(((*({ hrv *_t373 = &(g679); int64_t _i373 = n_179; (S4*)_t373->b + hr_ix(_i373, _t373->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:88"); }))).op_); *_t372 = ({ uint8_t _r374; if (f41_is(((int64_t)39LL))) { _r374 = ((uint8_t)(((uint8_t)5LL)));  } else { _r374 = ((uint8_t)(((uint8_t)4LL)));  } _r374; }); }
 } else { if (f55_prim_tok(f31_tk())) { { uint8_t *_t375 = &(((*({ hrv *_t376 = &(g679); int64_t _i376 = n_179; (S4*)_t376->b + hr_ix(_i376, _t376->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:89"); }))).op_); *_t375 = ((uint8_t)(((uint8_t)2LL))); }
{ int64_t q__393 = f93_lenstore(); 
{ int32_t *_t377 = &(((*({ hrv *_t378 = &(g679); int64_t _i378 = n_179; (S4*)_t378->b + hr_ix(_i378, _t378->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:89"); }))).c_); *_t377 = ((int32_t)(q__393)); }
 }
 } else { { uint8_t *_t379 = &(((*({ hrv *_t380 = &(g679); int64_t _i380 = n_179; (S4*)_t380->b + hr_ix(_i380, _t380->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:90"); }))).op_); *_t379 = ((uint8_t)(((uint8_t)1LL))); }
{ int64_t q__394 = f61_pexpr(); 
{ int32_t *_t381 = &(((*({ hrv *_t382 = &(g679); int64_t _i382 = n_179; (S4*)_t382->b + hr_ix(_i382, _t382->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:90"); }))).b_); *_t381 = ((int32_t)(q__394)); }
 }
 }
 }
 }
(void)(f39_ex(((int64_t)8LL), hr_str("array type", 10)));
t_175 = n_179;
continue;
 }
if (f41_is(((int64_t)49LL))) { int64_t n_395 = f40_mk(((int64_t)44LL), st_177); 
{ int32_t *_t383 = &(((*({ hrv *_t384 = &(g679); int64_t _i384 = n_395; (S4*)_t384->b + hr_ix(_i384, _t384->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:95"); }))).a_); *_t383 = ((int32_t)(t_175)); }
if (q_176) { { uint16_t *_t385 = &(((*({ hrv *_t386 = &(g679); int64_t _i386 = n_395; (S4*)_t386->b + hr_ix(_i386, _t386->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:95"); }))).fl_); *_t385 = ((uint16_t)1LL); }
q_176 = false;
 }
if (f41_is(((int64_t)39LL))) { { int64_t q__396 = f93_lenstore(); 
{ int32_t *_t387 = &(((*({ hrv *_t388 = &(g679); int64_t _i388 = n_395; (S4*)_t388->b + hr_ix(_i388, _t388->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:96"); }))).c_); *_t387 = ((int32_t)(q__396)); }
 }
if (f41_is(((int64_t)76LL))) { { int64_t q__397 = f56_qname(hr_str("relative reference pool", 23)); 
{ int32_t *_t389 = &(((*({ hrv *_t390 = &(g679); int64_t _i390 = n_395; (S4*)_t390->b + hr_ix(_i390, _t390->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:96"); }))).s_); *_t389 = ((int32_t)(q__397)); }
 }
 }
(void)(f58_close_angle(hr_str("relative reference width", 24)));
 }
t_175 = n_395;
continue;
 }
if (f41_is(((int64_t)14LL))) { if (((((*({ hrv *_t391 = &(g679); int64_t _i391 = t_175; (S4*)_t391->b + hr_ix(_i391, _t391->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:100"); }))).k_) == (((uint8_t)44LL)))) { { uint16_t *_t392 = &(((*({ hrv *_t393 = &(g679); int64_t _i393 = t_175; (S4*)_t393->b + hr_ix(_i393, _t393->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:100"); }))).fl_); *_t392 = ((uint16_t)((uint64_t)(*_t392) | (uint64_t)((uint16_t)2LL))); }
 } else { int64_t n_398 = f40_mk(((int64_t)44LL), st_177); 
{ int32_t *_t394 = &(((*({ hrv *_t395 = &(g679); int64_t _i395 = n_398; (S4*)_t395->b + hr_ix(_i395, _t395->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:100"); }))).a_); *_t394 = ((int32_t)(t_175)); }
{ uint16_t *_t396 = &(((*({ hrv *_t397 = &(g679); int64_t _i397 = n_398; (S4*)_t397->b + hr_ix(_i397, _t397->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:100"); }))).fl_); *_t396 = ((uint16_t)2LL); }
if (q_176) { { uint16_t *_t398 = &(((*({ hrv *_t399 = &(g679); int64_t _i399 = n_398; (S4*)_t399->b + hr_ix(_i399, _t399->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:100"); }))).fl_); *_t398 = ((uint16_t)((uint64_t)(*_t398) | (uint64_t)((uint16_t)1LL))); }
q_176 = false;
 }
t_175 = n_398;
 }
continue;
 }
if (((f31_tk()) == (((int64_t)17LL)))) { (void)(f33_nx());
if (((((*({ hrv *_t400 = &(g679); int64_t _i400 = t_175; (S4*)_t400->b + hr_ix(_i400, _t400->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:103"); }))).k_) == (((uint8_t)41LL)))) { { uint16_t *_t401 = &(((*({ hrv *_t402 = &(g679); int64_t _i402 = t_175; (S4*)_t402->b + hr_ix(_i402, _t402->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:103"); }))).fl_); *_t401 = ((uint16_t)((uint64_t)(*_t401) | (uint64_t)((uint16_t)1LL))); }
 } else { (void)(f38_perr(hr_str("variable mode (..) applies only to ADT type names", 49)));
 }
continue;
 }
if (f41_is(((int64_t)16LL))) { int64_t n_399 = f40_mk(((int64_t)46LL), st_177); 
{ int32_t *_t403 = &(((*({ hrv *_t404 = &(g679); int64_t _i404 = n_399; (S4*)_t404->b + hr_ix(_i404, _t404->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:104"); }))).a_); *_t403 = ((int32_t)(t_175)); }
{ int64_t q__400 = f34_ident(hr_str("variant type", 12)); 
{ int32_t *_t405 = &(((*({ hrv *_t406 = &(g679); int64_t _i406 = n_399; (S4*)_t406->b + hr_ix(_i406, _t406->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:104"); }))).s_); *_t405 = ((int32_t)(q__400)); }
 }
t_175 = n_399;
continue;
 }
if (q_176) { int64_t n_401 = f40_mk(((int64_t)48LL), st_177); 
{ int32_t *_t407 = &(((*({ hrv *_t408 = &(g679); int64_t _i408 = n_401; (S4*)_t408->b + hr_ix(_i408, _t408->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:105"); }))).a_); *_t407 = ((int32_t)(t_175)); }
t_175 = n_401;
 }
return t_175;
 } _bk359:; 
}
static int64_t f54_ptype_prim(void) {
int64_t st_145 = g684; 
int64_t k_146 = f31_tk(); 
if (f55_prim_tok(k_146)) { (void)(f33_nx());
bool up_148 = f43_at_word(g701); 
if (((((((((k_146) >= (((int64_t)91LL))) && ((k_146) <= (((int64_t)98LL)))) || ((k_146) == (((int64_t)103LL)))) || ((k_146) == (((int64_t)102LL)))) || ((k_146) == (((int64_t)101LL)))) && (!(g731))) && (((f31_tk()) == (((int64_t)76LL))) || up_148))) { (void)(f33_nx());
int64_t n_149 = f40_mk(((int64_t)47LL), st_145); 
{ uint8_t *_t409 = &(((*({ hrv *_t410 = &(g679); int64_t _i410 = n_149; (S4*)_t410->b + hr_ix(_i410, _t410->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:116"); }))).op_); *_t409 = ((uint8_t)(k_146)); }
{ uint16_t *_t411 = &(((*({ hrv *_t412 = &(g679); int64_t _i412 = n_149; (S4*)_t412->b + hr_ix(_i412, _t412->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:116"); }))).fl_); *_t411 = ({ uint16_t _r413; if (up_148) { _r413 = ((uint16_t)1LL);  } else { _r413 = ((uint16_t)0LL);  } _r413; }); }
{ int64_t q__155 = f56_qname(hr_str("index type", 10)); 
{ int32_t *_t414 = &(((*({ hrv *_t415 = &(g679); int64_t _i415 = n_149; (S4*)_t415->b + hr_ix(_i415, _t415->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:116"); }))).s_); *_t414 = ((int32_t)(q__155)); }
 }
return n_149;
 }
int64_t n_156 = f40_mk(((int64_t)40LL), st_145); 
{ uint8_t *_t416 = &(((*({ hrv *_t417 = &(g679); int64_t _i417 = n_156; (S4*)_t417->b + hr_ix(_i417, _t417->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:118"); }))).op_); *_t416 = ((uint8_t)(k_146)); }
return n_156;
 }
if ((((k_146) == (((int64_t)1LL))) || ((k_146) == (((int64_t)15LL))))) { int64_t n_157 = f40_mk(((int64_t)41LL), st_145); 
{ int64_t q__158 = f56_qname(hr_str("type", 4)); 
{ int32_t *_t418 = &(((*({ hrv *_t419 = &(g679); int64_t _i419 = n_157; (S4*)_t419->b + hr_ix(_i419, _t419->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:121"); }))).s_); *_t418 = ((int32_t)(q__158)); }
 }
if (f41_is(((int64_t)39LL))) { int64_t m_159 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v421 = &(g681); int32_t _x421 = ((int32_t)(f53_ptype())); int32_t *_p421 = (int32_t*)hr_grow(_v421, 1, sizeof _x421); *_p421 = _x421; _p421; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk420; }
 }
if ((((f31_tk()) == (((int64_t)40LL))) || ((f31_tk()) == (((int64_t)44LL))))) { { goto _bk420; }
 }
 } _bk420:; 
(void)(f58_close_angle(hr_str("type argument list", 18)));
(void)(f59_setl(n_157, m_159));
 }
return n_157;
 }
if (f41_is(((int64_t)61LL))) { int64_t n_168 = f40_mk(((int64_t)45LL), st_145); 
if (f41_is(((int64_t)5LL))) { { uint16_t *_t422 = &(((*({ hrv *_t423 = &(g679); int64_t _i423 = n_168; (S4*)_t423->b + hr_ix(_i423, _t423->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:128"); }))).fl_); *_t422 = ((uint16_t)1LL); }
int64_t m_169 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v425 = &(g681); int32_t _x425 = ((int32_t)(f53_ptype())); int32_t *_p425 = (int32_t*)hr_grow(_v425, 1, sizeof _x425); *_p425 = _x425; _p425; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk424; }
 }
 } _bk424:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function type", 13)));
(void)(f59_setl(n_168, m_169));
if (f41_is(((int64_t)54LL))) { int64_t r_170 = f40_mk(((int64_t)36LL), g684); 
int64_t m2_171 = f52_wbeg(); 
if (f41_is(((int64_t)5LL))) { while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v427 = &(g681); int32_t _x427 = ((int32_t)(f53_ptype())); int32_t *_p427 = (int32_t*)hr_grow(_v427, 1, sizeof _x427); *_p427 = _x427; _p427; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk426; }
 }
 } _bk426:; 
(void)(f39_ex(((int64_t)6LL), hr_str("function type return list", 25)));
 } else { (void)(({ hrv *_v428 = &(g681); int32_t _x428 = ((int32_t)(f53_ptype())); int32_t *_p428 = (int32_t*)hr_grow(_v428, 1, sizeof _x428); *_p428 = _x428; _p428; }));
 }
(void)(f59_setl(r_170, m2_171));
{ int32_t *_t429 = &(((*({ hrv *_t430 = &(g679); int64_t _i430 = n_168; (S4*)_t430->b + hr_ix(_i430, _t430->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:133"); }))).b_); *_t429 = ((int32_t)(r_170)); }
 }
 }
return n_168;
 }
if (f41_is(((int64_t)5LL))) { bool fb_172 = g731; 
g731 = false;
int64_t t_173 = f53_ptype(); 
g731 = fb_172;
(void)(f39_ex(((int64_t)6LL), hr_str("parenthesized type", 18)));
return t_173;
 }
hrv m_174 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o432 = &(m_174); hr_fs(_o432, hr_str("type expected, found '", 22)); hr_fs(_o432, f35_cur_text()); hr_fs(_o432, hr_str("'", 1)); }));
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
if (((a_151) >= (((int64_t)0LL)))) { (void)(({ hrv *_v434 = &(s_153); hsl _s434 = f10_nm(a_151); hr_append(_v434, _s434.p, _s434.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v435 = &(s_153); hsl _s435 = hr_str("::", 2); hr_append(_v435, _s435.p, _s435.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v436 = &(s_153); hsl _s436 = f10_nm(b_152); hr_append(_v436, _s436.p, _s436.n, sizeof(uint8_t)); }));
return f8_intern(hr_sl(s_153));
}
static void f58_close_angle(hsl ctx_160) {
if (((f31_tk()) == (((int64_t)44LL)))) { (void)(({ hrv *_v437 = &(g693); int64_t _x437 = g684; int64_t *_p437 = (int64_t*)hr_grow(_v437, 1, sizeof _x437); *_p437 = _x437; _p437; }));
{ uint8_t *_t438 = &(((*({ hrv *_t439 = &(g889); int64_t _i439 = g684; (S3*)_t439->b + hr_ix(_i439, _t439->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:52"); }))).k_); *_t438 = ((uint8_t)(((uint8_t)40LL))); }
return;
 }
(void)(f39_ex(((int64_t)40LL), ctx_160));
}
static void f59_setl(int64_t n_161, int64_t m_162) {
int64_t c_163 = ((int64_t)((int64_t)(g681).n - (int64_t)m_162)); 
{ int64_t q__167 = f60_wend(m_162); 
{ int32_t *_t440 = &(((*({ hrv *_t441 = &(g679); int64_t _i441 = n_161; (S4*)_t441->b + hr_ix(_i441, _t441->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:55"); }))).l_); *_t440 = ((int32_t)(q__167)); }
 }
{ int32_t *_t442 = &(((*({ hrv *_t443 = &(g679); int64_t _i443 = n_161; (S4*)_t443->b + hr_ix(_i443, _t443->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:55"); }))).n_); *_t442 = ((int32_t)(c_163)); }
}
static int64_t f60_wend(int64_t m_164) {
int64_t l_165 = (g680).n; 
{ int64_t _e445 = (g681).n; for (int64_t _k445 = m_164; _k445 < _e445; _k445++) { int64_t i_166 = (int64_t)_k445; (void)(({ hrv *_v446 = &(g680); int32_t _x446 = (*({ hrv *_t447 = &(g681); int64_t _i447 = i_166; (int32_t*)_t447->b + hr_ix(_i447, _t447->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:54"); })); int32_t *_p446 = (int32_t*)hr_grow(_v446, 1, sizeof _x446); *_p446 = _x446; _p446; }));
 } } _bk444:; 
(void)(({ hrv *_v448 = &(g681); int64_t _k448 = ((int64_t)((int64_t)(g681).n - (int64_t)m_164)); if (_k448 < 0 || _k448 > _v448->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:54"); _v448->n -= _k448; }));
return l_165;
}
static int64_t f61_pexpr(void) {
int64_t st_180 = g684; 
int64_t k_181 = f31_tk(); 
if (((k_181) == (((int64_t)72LL)))) { int64_t e_270 = f62_pif(); 
if (g689) { g690 = true;
 }
return e_270;
 }
if (((k_181) == (((int64_t)80LL)))) { int64_t e_274 = f78_pmatch(); 
if (g689) { g690 = true;
 }
return e_274;
 }
if (((k_181) == (((int64_t)78LL)))) { (void)(f33_nx());
int64_t e_275 = f40_mk(((int64_t)24LL), st_180); 
{ int64_t q__276 = f66_pblock(hr_str("block expression", 16)); 
{ int32_t *_t449 = &(((*({ hrv *_t450 = &(g679); int64_t _i450 = e_275; (S4*)_t450->b + hr_ix(_i450, _t450->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:147"); }))).a_); *_t449 = ((int32_t)(q__276)); }
 }
if (g689) { g690 = true;
 }
return e_275;
 }
if (((k_181) == (((int64_t)9LL)))) { int64_t e_277 = f66_pblock(hr_str("block", 5)); 
if (g689) { g690 = true;
 }
return e_277;
 }
if (((k_181) == (((int64_t)74LL)))) { (void)(f33_nx());
int64_t e_278 = f40_mk(((int64_t)25LL), st_180); 
{ int64_t q__279 = f63_pscrut(); 
{ int32_t *_t451 = &(((*({ hrv *_t452 = &(g679); int64_t _i452 = e_278; (S4*)_t452->b + hr_ix(_i452, _t452->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:149"); }))).a_); *_t451 = ((int32_t)(q__279)); }
 }
{ int64_t q__280 = f66_pblock(hr_str("while body", 10)); 
{ int32_t *_t453 = &(((*({ hrv *_t454 = &(g679); int64_t _i454 = e_278; (S4*)_t454->b + hr_ix(_i454, _t454->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:149"); }))).b_); *_t453 = ((int32_t)(q__280)); }
 }
if (g689) { g690 = true;
 }
return e_278;
 }
if (((k_181) == (((int64_t)77LL)))) { (void)(f33_nx());
int64_t e_281 = f40_mk(((int64_t)26LL), st_180); 
{ int64_t q__282 = f66_pblock(hr_str("loop body", 9)); 
{ int32_t *_t455 = &(((*({ hrv *_t456 = &(g679); int64_t _i456 = e_281; (S4*)_t456->b + hr_ix(_i456, _t456->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:150"); }))).a_); *_t455 = ((int32_t)(q__282)); }
 }
if (g689) { g690 = true;
 }
return e_281;
 }
if (((k_181) == (((int64_t)75LL)))) { int64_t e_294 = f79_pfor(); 
if (g689) { g690 = true;
 }
return e_294;
 }
if (((k_181) == (((int64_t)79LL)))) { (void)(f38_perr(hr_str("guard is a statement: it guards the rest of the block it is in", 62)));
return f40_mk(((int64_t)6LL), st_180);
 }
if (((k_181) == (((int64_t)81LL)))) { (void)(f33_nx());
bool sl_295 = g689; 
bool se_296 = g690; 
g689 = false;
g690 = false;
int64_t r_297 = f40_mk(((int64_t)28LL), st_180); 
if (((((f31_tk()) != (((int64_t)12LL))) && ((f31_tk()) != (((int64_t)10LL)))) && (!(f42_at_from())))) { int64_t m_298 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v458 = &(g681); int32_t _x458 = ((int32_t)(f61_pexpr())); int32_t *_p458 = (int32_t*)hr_grow(_v458, 1, sizeof _x458); *_p458 = _x458; _p458; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk457; }
 }
 } _bk457:; 
(void)(f59_setl(r_297, m_298));
 }
if (f42_at_from()) { (void)(f33_nx());
{ int64_t q__299 = f56_qname(hr_str("return from", 11)); 
{ int32_t *_t459 = &(((*({ hrv *_t460 = &(g679); int64_t _i460 = r_297; (S4*)_t460->b + hr_ix(_i460, _t460->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:158"); }))).s_); *_t459 = ((int32_t)(q__299)); }
 }
 }
g689 = sl_295;
g690 = se_296;
return r_297;
 }
if (((k_181) == (((int64_t)82LL)))) { (void)(f33_nx());
bool sl_300 = g689; 
bool se_301 = g690; 
g689 = false;
g690 = false;
int64_t r_302 = f40_mk(((int64_t)29LL), st_180); 
if ((((f31_tk()) != (((int64_t)12LL))) && ((f31_tk()) != (((int64_t)10LL))))) { { int64_t q__303 = f61_pexpr(); 
{ int32_t *_t461 = &(((*({ hrv *_t462 = &(g679); int64_t _i462 = r_302; (S4*)_t462->b + hr_ix(_i462, _t462->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:166"); }))).a_); *_t461 = ((int32_t)(q__303)); }
 }
 }
g689 = sl_300;
g690 = se_301;
return r_302;
 }
if (((k_181) == (((int64_t)83LL)))) { (void)(f33_nx());
return f40_mk(((int64_t)30LL), st_180);
 }
return f80_pbin(((int64_t)1LL));
}
static int64_t f62_pif(void) {
int64_t st_182 = g684; 
(void)(f33_nx());
int64_t n_183 = f40_mk(((int64_t)19LL), st_182); 
{ int64_t q__189 = f63_pscrut(); 
{ int32_t *_t463 = &(((*({ hrv *_t464 = &(g679); int64_t _i464 = n_183; (S4*)_t464->b + hr_ix(_i464, _t464->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:180"); }))).a_); *_t463 = ((int32_t)(q__189)); }
 }
{ int64_t q__268 = f66_pblock(hr_str("if body", 7)); 
{ int32_t *_t465 = &(((*({ hrv *_t466 = &(g679); int64_t _i466 = n_183; (S4*)_t466->b + hr_ix(_i466, _t466->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:181"); }))).b_); *_t465 = ((int32_t)(q__268)); }
 }
if (f41_is(((int64_t)73LL))) { { int64_t q__269 = ({ int64_t _r467; if (((f31_tk()) == (((int64_t)72LL)))) { _r467 = f62_pif();  } else { _r467 = f66_pblock(hr_str("else body", 9));  } _r467; }); 
{ int32_t *_t468 = &(((*({ hrv *_t469 = &(g679); int64_t _i469 = n_183; (S4*)_t469->b + hr_ix(_i469, _t469->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:182"); }))).c_); *_t468 = ((int32_t)(q__269)); }
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
int64_t s_185 = ((int64_t)((int64_t)((int64_t)((int64_t)({ int64_t _r470; if (g688) { _r470 = ((int64_t)1LL);  } else { _r470 = ((int64_t)0LL);  } _r470; }) | (int64_t)({ int64_t _r471; if (g689) { _r471 = ((int64_t)2LL);  } else { _r471 = ((int64_t)0LL);  } _r471; }))) | (int64_t)({ int64_t _r472; if (g690) { _r472 = ((int64_t)4LL);  } else { _r472 = ((int64_t)0LL);  } _r472; }))); 
g688 = nosl_184;
g689 = false;
g690 = false;
return s_185;
}
static void f65_sub_end(int64_t s_188) {
g688 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)));
g689 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)));
g690 = ((((int64_t)((int64_t)s_188 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL)));
}
static int64_t f66_pblock(hsl ctx_190) {
int64_t st_191 = g684; 
(void)(f39_ex(((int64_t)9LL), ctx_190));
int64_t b_192 = f40_mk(((int64_t)23LL), st_191); 
(void)(f67_pbody(b_192));
return b_192;
}
static void f67_pbody(int64_t b_193) {
int64_t s_194 = f64_sub_begin(false); 
int64_t m_195 = f52_wbeg(); 
for (;;) { g689 = false;
g690 = false;
if (f41_is(((int64_t)10LL))) { { goto _bk473; }
 }
if (((f31_tk()) == (((int64_t)0LL)))) { (void)(f38_perr(hr_str("expected '}' before end of file", 31)));
{ goto _bk473; }
 }
if ((!(f68_pstmt(b_193)))) { { goto _bk473; }
 }
 } _bk473:; 
(void)(f59_setl(b_193, m_195));
(void)(f65_sub_end(s_194));
}
static bool f68_pstmt(int64_t b_196) {
int64_t k_197 = f31_tk(); 
if (((((((((f46_at_inline() || f47_at_checkfree()) || f48_at_lut()) || ((k_197) == (((int64_t)65LL)))) || ((k_197) == (((int64_t)61LL)))) || ((k_197) == (((int64_t)62LL)))) || ((k_197) == (((int64_t)68LL)))) || ((k_197) == (((int64_t)63LL)))) || ((k_197) == (((int64_t)64LL))))) { (void)(({ hrv *_v474 = &(g681); int32_t _x474 = ((int32_t)(f49_pfn(true, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p474 = (int32_t*)hr_grow(_v474, 1, sizeof _x474); *_p474 = _x474; _p474; }));
return true;
 }
if ((((((k_197) == (((int64_t)66LL))) || ((k_197) == (((int64_t)67LL)))) || ((k_197) == (((int64_t)69LL)))) || ((k_197) == (((int64_t)71LL))))) { if ((((k_197) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g684 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v475 = &(g681); int32_t _x475 = ((int32_t)(f69_pcfor(((int64_t)0LL)))); int32_t *_p475 = (int32_t*)hr_grow(_v475, 1, sizeof _x475); *_p475 = _x475; _p475; }));
return true;
 }
int64_t v_247 = f74_pvdecl(false); 
(void)(f39_ex(((int64_t)12LL), hr_str("variable declaration", 20)));
(void)(({ hrv *_v476 = &(g681); int32_t _x476 = ((int32_t)(v_247)); int32_t *_p476 = (int32_t*)hr_grow(_v476, 1, sizeof _x476); *_p476 = _x476; _p476; }));
return true;
 }
if (((k_197) == (((int64_t)79LL)))) { (void)(f76_pguard(b_196));
return false;
 }
g689 = true;
int64_t e_254 = f61_pexpr(); 
g689 = false;
int64_t st_255 = g684; 
if ((!(g690))) { int64_t o_256 = f31_tk(); 
if ((((((((((((((o_256) == (((int64_t)36LL))) || ((o_256) == (((int64_t)18LL)))) || ((o_256) == (((int64_t)26LL)))) || ((o_256) == (((int64_t)27LL)))) || ((o_256) == (((int64_t)28LL)))) || ((o_256) == (((int64_t)29LL)))) || ((o_256) == (((int64_t)30LL)))) || ((o_256) == (((int64_t)31LL)))) || ((o_256) == (((int64_t)32LL)))) || ((o_256) == (((int64_t)33LL)))) || ((o_256) == (((int64_t)45LL)))) || ((o_256) == (((int64_t)46LL))))) { (void)(f33_nx());
int64_t r_257 = f61_pexpr(); 
(void)(f39_ex(((int64_t)12LL), hr_str("assignment statement", 20)));
int64_t n_258 = f40_mk(((int64_t)34LL), st_255); 
{ uint8_t *_t477 = &(((*({ hrv *_t478 = &(g679); int64_t _i478 = n_258; (S4*)_t478->b + hr_ix(_i478, _t478->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:528"); }))).op_); *_t477 = ((uint8_t)(o_256)); }
{ int32_t *_t479 = &(((*({ hrv *_t480 = &(g679); int64_t _i480 = n_258; (S4*)_t480->b + hr_ix(_i480, _t480->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:528"); }))).a_); *_t479 = ((int32_t)(e_254)); }
{ int32_t *_t481 = &(((*({ hrv *_t482 = &(g679); int64_t _i482 = n_258; (S4*)_t482->b + hr_ix(_i482, _t482->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:528"); }))).b_); *_t481 = ((int32_t)(r_257)); }
(void)(({ hrv *_v483 = &(g681); int32_t _x483 = ((int32_t)(n_258)); int32_t *_p483 = (int32_t*)hr_grow(_v483, 1, sizeof _x483); *_p483 = _x483; _p483; }));
return true;
 }
if ((((o_256) == (((int64_t)34LL))) || ((o_256) == (((int64_t)35LL))))) { (void)(f33_nx());
(void)(f39_ex(((int64_t)12LL), hr_str("increment statement", 19)));
int64_t n_259 = f40_mk(((int64_t)35LL), st_255); 
{ uint8_t *_t484 = &(((*({ hrv *_t485 = &(g679); int64_t _i485 = n_259; (S4*)_t485->b + hr_ix(_i485, _t485->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:530"); }))).op_); *_t484 = ((uint8_t)(o_256)); }
{ int32_t *_t486 = &(((*({ hrv *_t487 = &(g679); int64_t _i487 = n_259; (S4*)_t487->b + hr_ix(_i487, _t487->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:530"); }))).a_); *_t486 = ((int32_t)(e_254)); }
(void)(({ hrv *_v488 = &(g681); int32_t _x488 = ((int32_t)(n_259)); int32_t *_p488 = (int32_t*)hr_grow(_v488, 1, sizeof _x488); *_p488 = _x488; _p488; }));
return true;
 }
if (((o_256) == (((int64_t)11LL)))) { (void)(({ hrv *_v489 = &(g681); int32_t _x489 = ((int32_t)(f77_pmulti(e_254, st_255))); int32_t *_p489 = (int32_t*)hr_grow(_v489, 1, sizeof _x489); *_p489 = _x489; _p489; }));
return true;
 }
 }
if (f41_is(((int64_t)12LL))) { (void)(({ hrv *_v490 = &(g681); int32_t _x490 = ((int32_t)(e_254)); int32_t *_p490 = (int32_t*)hr_grow(_v490, 1, sizeof _x490); *_p490 = _x490; _p490; }));
return true;
 }
if (f41_is(((int64_t)10LL))) { { int32_t *_t491 = &(((*({ hrv *_t492 = &(g679); int64_t _i492 = b_196; (S4*)_t492->b + hr_ix(_i492, _t492->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:534"); }))).a_); *_t491 = ((int32_t)(e_254)); }
return false;
 }
if (g690) { (void)(({ hrv *_v493 = &(g681); int32_t _x493 = ((int32_t)(e_254)); int32_t *_p493 = (int32_t*)hr_grow(_v493, 1, sizeof _x493); *_p493 = _x493; _p493; }));
return true;
 }
hrv m_267 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o495 = &(m_267); hr_fs(_o495, hr_str("';' expected after expression, found '", 38)); hr_fs(_o495, f35_cur_text()); hr_fs(_o495, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_267)));
return false;
}
static int64_t f69_pcfor(int64_t mode_198) {
int64_t cf_199 = f40_mk(((int64_t)37LL), g684); 
(void)(f39_ex(((int64_t)69LL), hr_str("const for", 9)));
(void)(f39_ex(((int64_t)75LL), hr_str("const for", 9)));
(void)(f39_ex(((int64_t)39LL), hr_str("const for bindings", 18)));
int64_t nb_200 = f40_mk(((int64_t)36LL), g684); 
int64_t m_201 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v497 = &(g681); int32_t _x497 = ((int32_t)(f34_ident(hr_str("const for binding", 17)))); int32_t *_p497 = (int32_t*)hr_grow(_v497, 1, sizeof _x497); *_p497 = _x497; _p497; }));
if (((!(f41_is(((int64_t)11LL)))) || ((f31_tk()) == (((int64_t)40LL))))) { { goto _bk496; }
 }
 } _bk496:; 
(void)(f59_setl(nb_200, m_201));
(void)(f58_close_angle(hr_str("const for bindings", 18)));
(void)(f39_ex(((int64_t)76LL), hr_str("const for", 9)));
{ int32_t *_t498 = &(((*({ hrv *_t499 = &(g679); int64_t _i499 = cf_199; (S4*)_t499->b + hr_ix(_i499, _t499->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:426"); }))).a_); *_t498 = ((int32_t)(nb_200)); }
int64_t src_202 = f40_mk(((int64_t)36LL), g684); 
if (f41_is(((int64_t)7LL))) { { uint8_t *_t500 = &(((*({ hrv *_t501 = &(g679); int64_t _i501 = cf_199; (S4*)_t501->b + hr_ix(_i501, _t501->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:429"); }))).op_); *_t500 = ((uint8_t)1LL); }
int64_t s_203 = f64_sub_begin(false); 
int64_t m2_204 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)8LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v503 = &(g681); int32_t _x503 = ((int32_t)(f61_pexpr())); int32_t *_p503 = (int32_t*)hr_grow(_v503, 1, sizeof _x503); *_p503 = _x503; _p503; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk502; }
 }
 } _bk502:; 
(void)(f39_ex(((int64_t)8LL), hr_str("const for constant list", 23)));
(void)(f59_setl(src_202, m2_204));
(void)(f65_sub_end(s_203));
 } else { int64_t q_205 = f34_ident(hr_str("const for source", 16)); 
{ uint8_t *_t504 = &(((*({ hrv *_t505 = &(g679); int64_t _i505 = cf_199; (S4*)_t505->b + hr_ix(_i505, _t505->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:435"); }))).op_); *_t504 = ((uint8_t)(({ uint8_t _r506; if (((q_205) == (g702))) { _r506 = ((uint8_t)2LL);  } else { _r506 = ({ uint8_t _r507; if (((q_205) == (g704))) { _r507 = ((uint8_t)3LL);  } else { _r507 = ({ uint8_t _r508; if (((q_205) == (g703))) { _r508 = ((uint8_t)4LL);  } else { _r508 = ((uint8_t)0LL);  } _r508; });  } _r507; });  } _r506; }))); }
if (((((*({ hrv *_t509 = &(g679); int64_t _i509 = cf_199; (S4*)_t509->b + hr_ix(_i509, _t509->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:436"); }))).op_) == (((uint8_t)0LL)))) { (void)(f38_perr(hr_str("const for source must be fields<T>, variants<E>, types<...>, or [constants]", 75)));
 }
(void)(f39_ex(((int64_t)39LL), hr_str("const for source", 16)));
int64_t m2_206 = f52_wbeg(); 
while (((((f31_tk()) != (((int64_t)40LL))) && ((f31_tk()) != (((int64_t)44LL)))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v511 = &(g681); int32_t _x511 = ((int32_t)(f53_ptype())); int32_t *_p511 = (int32_t*)hr_grow(_v511, 1, sizeof _x511); *_p511 = _x511; _p511; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk510; }
 }
 } _bk510:; 
(void)(f58_close_angle(hr_str("const for source", 16)));
(void)(f59_setl(src_202, m2_206));
 }
{ int32_t *_t512 = &(((*({ hrv *_t513 = &(g679); int64_t _i513 = cf_199; (S4*)_t513->b + hr_ix(_i513, _t513->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:440"); }))).b_); *_t512 = ((int32_t)(src_202)); }
{ uint16_t *_t514 = &(((*({ hrv *_t515 = &(g679); int64_t _i515 = cf_199; (S4*)_t515->b + hr_ix(_i515, _t515->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:441"); }))).fl_); *_t514 = ((uint16_t)(mode_198)); }
if (((mode_198) == (((int64_t)1LL)))) { int64_t il_207 = f40_mk(((int64_t)36LL), g684); 
(void)(f70_pinits(il_207, true));
{ int32_t *_t516 = &(((*({ hrv *_t517 = &(g679); int64_t _i517 = cf_199; (S4*)_t517->b + hr_ix(_i517, _t517->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:442"); }))).c_); *_t516 = ((int32_t)(il_207)); }
 } else { if (((mode_198) == (((int64_t)2LL)))) { (void)(f39_ex(((int64_t)9LL), hr_str("const for arms", 14)));
int64_t al_214 = f40_mk(((int64_t)36LL), g684); 
(void)(f71_parms(al_214));
(void)(f39_ex(((int64_t)10LL), hr_str("const for arms", 14)));
{ int32_t *_t518 = &(((*({ hrv *_t519 = &(g679); int64_t _i519 = cf_199; (S4*)_t519->b + hr_ix(_i519, _t519->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:443"); }))).c_); *_t518 = ((int32_t)(al_214)); }
 } else { { int64_t q__237 = f66_pblock(hr_str("const for body", 14)); 
{ int32_t *_t520 = &(((*({ hrv *_t521 = &(g679); int64_t _i521 = cf_199; (S4*)_t521->b + hr_ix(_i521, _t521->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:443"); }))).c_); *_t520 = ((int32_t)(q__237)); }
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
{ uint16_t *_t523 = &(((*({ hrv *_t524 = &(g679); int64_t _i524 = n_208; (S4*)_t524->b + hr_ix(_i524, _t524->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:451"); }))).fl_); *_t523 = ((uint16_t)((uint64_t)(*_t523) | (uint64_t)((uint16_t)1LL))); }
{ goto _bk522; }
 }
if ((((f31_tk()) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g684 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v525 = &(g681); int32_t _x525 = ((int32_t)(f69_pcfor(((int64_t)1LL)))); int32_t *_p525 = (int32_t*)hr_grow(_v525, 1, sizeof _x525); *_p525 = _x525; _p525; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk522; }
 }
continue;
 }
int64_t fi_212 = f40_mk(((int64_t)18LL), g684); 
if ((((f31_tk()) == (((int64_t)1LL))) && ((f44_tkat(((int64_t)((int64_t)g684 + (int64_t)((int64_t)1LL))))) == (((int64_t)13LL))))) { { int32_t *_t526 = &(((*({ hrv *_t527 = &(g679); int64_t _i527 = fi_212; (S4*)_t527->b + hr_ix(_i527, _t527->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:454"); }))).s_); *_t526 = ((int32_t)(((*({ hrv *_t528 = &(g889); int64_t _i528 = g684; (S3*)_t528->b + hr_ix(_i528, _t528->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:454"); }))).v_)); }
(void)(f33_nx());
(void)(f33_nx());
 }
{ int64_t q__213 = f61_pexpr(); 
{ int32_t *_t529 = &(((*({ hrv *_t530 = &(g679); int64_t _i530 = fi_212; (S4*)_t530->b + hr_ix(_i530, _t530->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:455"); }))).a_); *_t529 = ((int32_t)(q__213)); }
 }
(void)(({ hrv *_v531 = &(g681); int32_t _x531 = ((int32_t)(fi_212)); int32_t *_p531 = (int32_t*)hr_grow(_v531, 1, sizeof _x531); *_p531 = _x531; _p531; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk522; }
 }
 } _bk522:; 
(void)(f39_ex(((int64_t)10LL), hr_str("struct literal", 14)));
(void)(f59_setl(n_208, m_211));
(void)(f65_sub_end(s_210));
}
static void f71_parms(int64_t n_215) {
int64_t s_216 = f64_sub_begin(g688); 
int64_t m_217 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { if ((((f31_tk()) == (((int64_t)69LL))) && ((f44_tkat(((int64_t)((int64_t)g684 + (int64_t)((int64_t)1LL))))) == (((int64_t)75LL))))) { (void)(({ hrv *_v533 = &(g681); int32_t _x533 = ((int32_t)(f69_pcfor(((int64_t)2LL)))); int32_t *_p533 = (int32_t*)hr_grow(_v533, 1, sizeof _x533); *_p533 = _x533; _p533; }));
 } else { int64_t a_235 = f72_ppattern(); 
(void)(f39_ex(((int64_t)55LL), hr_str("match arm", 9)));
{ int64_t q__236 = f61_pexpr(); 
{ int32_t *_t534 = &(((*({ hrv *_t535 = &(g679); int64_t _i535 = a_235; (S4*)_t535->b + hr_ix(_i535, _t535->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:218"); }))).b_); *_t534 = ((int32_t)(q__236)); }
 }
(void)(({ hrv *_v536 = &(g681); int32_t _x536 = ((int32_t)(a_235)); int32_t *_p536 = (int32_t*)hr_grow(_v536, 1, sizeof _x536); *_p536 = _x536; _p536; }));
 }
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk532; }
 }
 } _bk532:; 
(void)(f59_setl(n_215, m_217));
(void)(f65_sub_end(s_216));
}
static int64_t f72_ppattern(void) {
int64_t a_218 = f40_mk(((int64_t)21LL), g684); 
if (f43_at_word(g700)) { (void)(f33_nx());
{ uint16_t *_t537 = &(((*({ hrv *_t538 = &(g679); int64_t _i538 = a_218; (S4*)_t538->b + hr_ix(_i538, _t538->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:226"); }))).fl_); *_t537 = ((uint16_t)1LL); }
if (((f31_tk()) == (((int64_t)11LL)))) { (void)(f38_perr(hr_str("_ cannot be listed with other patterns", 38)));
 }
return a_218;
 }
int64_t m_219 = f52_wbeg(); 
for (;;) { int64_t it_220 = f40_mk(((int64_t)22LL), g684); 
{ int64_t q__229 = f73_pbound(); 
{ int32_t *_t540 = &(((*({ hrv *_t541 = &(g679); int64_t _i541 = it_220; (S4*)_t541->b + hr_ix(_i541, _t541->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:230"); }))).a_); *_t540 = ((int32_t)(q__229)); }
 }
if (f41_is(((int64_t)17LL))) { { int64_t q__230 = f73_pbound(); 
{ int32_t *_t542 = &(((*({ hrv *_t543 = &(g679); int64_t _i543 = it_220; (S4*)_t543->b + hr_ix(_i543, _t543->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:231"); }))).b_); *_t542 = ((int32_t)(q__230)); }
 }
 }
(void)(({ hrv *_v544 = &(g681); int32_t _x544 = ((int32_t)(it_220)); int32_t *_p544 = (int32_t*)hr_grow(_v544, 1, sizeof _x544); *_p544 = _x544; _p544; }));
int64_t lo_231 = ((int64_t)(((*({ hrv *_t545 = &(g679); int64_t _i545 = it_220; (S4*)_t545->b + hr_ix(_i545, _t545->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:233"); }))).a_)); 
if (((((((*({ hrv *_t546 = &(g679); int64_t _i546 = lo_231; (S4*)_t546->b + hr_ix(_i546, _t546->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:234"); }))).k_) == (((uint8_t)8LL))) && ((((*({ hrv *_t547 = &(g679); int64_t _i547 = it_220; (S4*)_t547->b + hr_ix(_i547, _t547->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:234"); }))).b_) < (((int32_t)0LL)))) && (((f31_tk()) == (((int64_t)49LL))) || ((f31_tk()) == (((int64_t)1LL)))))) { bool hasq_232 = false; 
{ hsl _v549 = f10_nm(((int64_t)(((*({ hrv *_t550 = &(g679); int64_t _i550 = lo_231; (S4*)_t550->b + hr_ix(_i550, _t550->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:235"); }))).s_))); for (int64_t _k549 = 0; _k549 < _v549.n; _k549++) { uint8_t c_233 = ((uint8_t*)_v549.p)[_k549]; if (((c_233) == (((uint8_t)58LL)))) { hasq_232 = true;
 }
 } } _bk548:; 
if ((!(hasq_232))) { if (((((int64_t)((int64_t)(g681).n - (int64_t)m_219))) > (((int64_t)1LL)))) { (void)(f38_perr(hr_str("a list of patterns binds no payload: give the variant an arm of its own", 71)));
 }
if (f41_is(((int64_t)49LL))) { { uint16_t *_t551 = &(((*({ hrv *_t552 = &(g679); int64_t _i552 = a_218; (S4*)_t552->b + hr_ix(_i552, _t552->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:238"); }))).fl_); *_t551 = ((uint16_t)((uint64_t)(*_t551) | (uint64_t)((uint16_t)2LL))); }
 }
{ int64_t q__234 = f34_ident(hr_str("match binding", 13)); 
{ int32_t *_t553 = &(((*({ hrv *_t554 = &(g679); int64_t _i554 = a_218; (S4*)_t554->b + hr_ix(_i554, _t554->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:239"); }))).s_); *_t553 = ((int32_t)(q__234)); }
 }
if (((f31_tk()) == (((int64_t)11LL)))) { (void)(f38_perr(hr_str("a list of patterns binds no payload: give the variant an arm of its own", 71)));
 }
(void)(f59_setl(a_218, m_219));
return a_218;
 }
 }
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk539; }
 }
if (f43_at_word(g700)) { (void)(f38_perr(hr_str("_ cannot be listed with other patterns", 38)));
 }
 } _bk539:; 
(void)(f59_setl(a_218, m_219));
return a_218;
}
static int64_t f73_pbound(void) {
int64_t st_221 = g684; 
bool neg_222 = f41_is(((int64_t)22LL)); 
if ((((f31_tk()) == (((int64_t)1LL))) || ((f31_tk()) == (((int64_t)15LL))))) { int64_t n_223 = f40_mk(((int64_t)8LL), g684); 
{ int64_t q__224 = f56_qname(hr_str("match pattern", 13)); 
{ int32_t *_t555 = &(((*({ hrv *_t556 = &(g679); int64_t _i556 = n_223; (S4*)_t556->b + hr_ix(_i556, _t556->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:254"); }))).s_); *_t555 = ((int32_t)(q__224)); }
 }
if (neg_222) { int64_t u_225 = f40_mk(((int64_t)10LL), st_221); 
{ uint8_t *_t557 = &(((*({ hrv *_t558 = &(g679); int64_t _i558 = u_225; (S4*)_t558->b + hr_ix(_i558, _t558->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:254"); }))).op_); *_t557 = ((uint8_t)(((uint8_t)22LL))); }
{ int32_t *_t559 = &(((*({ hrv *_t560 = &(g679); int64_t _i560 = u_225; (S4*)_t560->b + hr_ix(_i560, _t560->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:254"); }))).a_); *_t559 = ((int32_t)(n_223)); }
return u_225;
 }
return n_223;
 }
if (((f31_tk()) != (((int64_t)2LL)))) { hrv m_226 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o562 = &(m_226); hr_fs(_o562, hr_str("integer constant expected in match pattern, found '", 51)); hr_fs(_o562, f35_cur_text()); hr_fs(_o562, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_226)));
return f40_mk(((int64_t)1LL), st_221);
 }
int64_t n_227 = f40_mk(((int64_t)1LL), g684); 
(void)(f33_nx());
if (neg_222) { int64_t u_228 = f40_mk(((int64_t)10LL), st_221); 
{ uint8_t *_t563 = &(((*({ hrv *_t564 = &(g679); int64_t _i564 = u_228; (S4*)_t564->b + hr_ix(_i564, _t564->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:257"); }))).op_); *_t563 = ((uint8_t)(((uint8_t)22LL))); }
{ int32_t *_t565 = &(((*({ hrv *_t566 = &(g679); int64_t _i566 = u_228; (S4*)_t566->b + hr_ix(_i566, _t566->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:257"); }))).a_); *_t565 = ((int32_t)(n_227)); }
return u_228;
 }
return n_227;
}
static int64_t f74_pvdecl(bool glob_238) {
int64_t st_239 = g684; 
int64_t fl_240 = ({ int64_t _r567; if (glob_238) { _r567 = ((int64_t)8LL);  } else { _r567 = ((int64_t)0LL);  } _r567; }); 
if (f41_is(((int64_t)71LL))) { { int64_t *_t568 = &(fl_240); *_t568 = ((int64_t)((int64_t)(*_t568) | (int64_t)((int64_t)16LL))); }
if (f41_is(((int64_t)7LL))) { (void)(f39_ex(((int64_t)8LL), hr_str("reusable[]", 10)));
{ int64_t *_t569 = &(fl_240); *_t569 = ((int64_t)((int64_t)(*_t569) | (int64_t)((int64_t)32LL))); }
 }
 }
if (f41_is(((int64_t)67LL))) { { int64_t *_t570 = &(fl_240); *_t570 = ((int64_t)((int64_t)(*_t570) | (int64_t)((int64_t)1LL))); }
 } else { if (f41_is(((int64_t)66LL))) {  } else { if (f41_is(((int64_t)69LL))) { { int64_t *_t571 = &(fl_240); *_t571 = ((int64_t)((int64_t)(*_t571) | (int64_t)((int64_t)2LL))); }
 } else { (void)(f38_perr(hr_str("let, var or const expected", 26)));
 }
 }
 }
int64_t v_241 = f40_mk(((int64_t)33LL), st_239); 
int64_t m_242 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v573 = &(g681); int32_t _x573 = ((int32_t)(({ int64_t _r574; if (glob_238) { _r574 = f50_declname(hr_str("global declaration", 18));  } else { _r574 = f34_ident(hr_str("variable declaration", 20));  } _r574; }))); int32_t *_p573 = (int32_t*)hr_grow(_v573, 1, sizeof _x573); *_p573 = _x573; _p573; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk572; }
 }
 } _bk572:; 
(void)(f59_setl(v_241, m_242));
{ int32_t *_t575 = &(((*({ hrv *_t576 = &(g679); int64_t _i576 = v_241; (S4*)_t576->b + hr_ix(_i576, _t576->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:571"); }))).c_); *_t575 = ((int32_t)(g691)); }
if ((f41_is(((int64_t)13LL)) || f75_amni_type())) { { int64_t q__244 = f53_ptype(); 
{ int32_t *_t577 = &(((*({ hrv *_t578 = &(g679); int64_t _i578 = v_241; (S4*)_t578->b + hr_ix(_i578, _t578->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:572"); }))).a_); *_t577 = ((int32_t)(q__244)); }
 }
 }
if (f41_is(((int64_t)18LL))) { { int64_t *_t579 = &(fl_240); *_t579 = ((int64_t)((int64_t)(*_t579) | (int64_t)((int64_t)4LL))); }
 }
if ((((((int64_t)((int64_t)fl_240 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL))) || f41_is(((int64_t)36LL)))) { int64_t il_245 = f40_mk(((int64_t)36LL), g684); 
int64_t m2_246 = f52_wbeg(); 
for (;;) { (void)(({ hrv *_v581 = &(g681); int32_t _x581 = ((int32_t)(f61_pexpr())); int32_t *_p581 = (int32_t*)hr_grow(_v581, 1, sizeof _x581); *_p581 = _x581; _p581; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk580; }
 }
 } _bk580:; 
(void)(f59_setl(il_245, m2_246));
{ int32_t *_t582 = &(((*({ hrv *_t583 = &(g679); int64_t _i583 = v_241; (S4*)_t583->b + hr_ix(_i583, _t583->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:574"); }))).b_); *_t582 = ((int32_t)(il_245)); }
 }
{ uint16_t *_t584 = &(((*({ hrv *_t585 = &(g679); int64_t _i585 = v_241; (S4*)_t585->b + hr_ix(_i585, _t585->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:575"); }))).fl_); *_t584 = ((uint16_t)(fl_240)); }
if (glob_238) { if ((((((*({ hrv *_t586 = &(g679); int64_t _i586 = v_241; (S4*)_t586->b + hr_ix(_i586, _t586->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:577"); }))).b_) < (((int32_t)0LL))) && ((((int64_t)((int64_t)fl_240 & (int64_t)((int64_t)1LL)))) == (((int64_t)0LL))))) { (void)(f38_perr(hr_str("let and const global declarations require an initializer", 56)));
 }
if (((((*({ hrv *_t587 = &(g679); int64_t _i587 = v_241; (S4*)_t587->b + hr_ix(_i587, _t587->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:578"); }))).n_) != (((int32_t)1LL)))) { (void)(f38_perr(hr_str("global declarations declare a single name", 41)));
 }
 }
return v_241;
}
static bool f75_amni_type(void) {
int64_t k_243 = f31_tk(); 
return (((*({ hrv *_t588 = &(g888); int64_t _i588 = ((*({ hrv *_t589 = &(g889); int64_t _i589 = g684; (S3*)_t589->b + hr_ix(_i589, _t589->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:74"); }))).f_; (S2*)_t588->b + hr_ix(_i588, _t588->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:74"); }))).amni_ && (((((f55_prim_tok(k_243) || ((k_243) == (((int64_t)1LL)))) || ((k_243) == (((int64_t)15LL)))) || ((k_243) == (((int64_t)61LL)))) || ((k_243) == (((int64_t)5LL)))) || ((k_243) == (((int64_t)69LL)))));
}
static void f76_pguard(int64_t b_248) {
int64_t st_249 = g684; 
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
{ int32_t *_t590 = &(((*({ hrv *_t591 = &(g679); int64_t _i591 = i_253; (S4*)_t591->b + hr_ix(_i591, _t591->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:559"); }))).a_); *_t590 = ((int32_t)(c_250)); }
{ int32_t *_t592 = &(((*({ hrv *_t593 = &(g679); int64_t _i593 = i_253; (S4*)_t593->b + hr_ix(_i593, _t593->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:559"); }))).b_); *_t592 = ((int32_t)(rest_252)); }
{ int32_t *_t594 = &(((*({ hrv *_t595 = &(g679); int64_t _i595 = i_253; (S4*)_t595->b + hr_ix(_i595, _t595->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:559"); }))).c_); *_t594 = ((int32_t)(eb_251)); }
{ uint16_t *_t596 = &(((*({ hrv *_t597 = &(g679); int64_t _i597 = i_253; (S4*)_t597->b + hr_ix(_i597, _t597->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:559"); }))).fl_); *_t596 = ((uint16_t)1LL); }
if (((((*({ hrv *_t598 = &(g679); int64_t _i598 = rest_252; (S4*)_t598->b + hr_ix(_i598, _t598->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:560"); }))).a_) >= (((int32_t)0LL)))) { { int32_t *_t599 = &(((*({ hrv *_t600 = &(g679); int64_t _i600 = b_248; (S4*)_t600->b + hr_ix(_i600, _t600->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:560"); }))).a_); *_t599 = ((int32_t)(i_253)); }
 } else { (void)(({ hrv *_v601 = &(g681); int32_t _x601 = ((int32_t)(i_253)); int32_t *_p601 = (int32_t*)hr_grow(_v601, 1, sizeof _x601); *_p601 = _x601; _p601; }));
 }
}
static int64_t f77_pmulti(int64_t first_260, int64_t st_261) {
int64_t tl_262 = f40_mk(((int64_t)36LL), st_261); 
int64_t m_263 = f52_wbeg(); 
(void)(({ hrv *_v602 = &(g681); int32_t _x602 = ((int32_t)(first_260)); int32_t *_p602 = (int32_t*)hr_grow(_v602, 1, sizeof _x602); *_p602 = _x602; _p602; }));
while (f41_is(((int64_t)11LL))) { (void)(({ hrv *_v604 = &(g681); int32_t _x604 = ((int32_t)(f61_pexpr())); int32_t *_p604 = (int32_t*)hr_grow(_v604, 1, sizeof _x604); *_p604 = _x604; _p604; }));
 } _bk603:; 
(void)(f59_setl(tl_262, m_263));
int64_t o_264 = f31_tk(); 
if (((((((((((((o_264) == (((int64_t)18LL))) || ((o_264) == (((int64_t)26LL)))) || ((o_264) == (((int64_t)27LL)))) || ((o_264) == (((int64_t)28LL)))) || ((o_264) == (((int64_t)29LL)))) || ((o_264) == (((int64_t)30LL)))) || ((o_264) == (((int64_t)31LL)))) || ((o_264) == (((int64_t)32LL)))) || ((o_264) == (((int64_t)33LL)))) || ((o_264) == (((int64_t)45LL)))) || ((o_264) == (((int64_t)46LL))))) { (void)(f38_perr(hr_str("several targets take a call's results with `=` alone (\302\2477.1)", 60)));
 }
if (((f31_tk()) != (((int64_t)36LL)))) { (void)(f38_perr(hr_str("several values exist only in `return a, b;` and in a call's results, so a block or branch cannot end in `a, b`: return from each branch instead (\302\2477.1)", 151)));
 }
(void)(f33_nx());
int64_t n_265 = f40_mk(((int64_t)34LL), st_261); 
{ uint8_t *_t605 = &(((*({ hrv *_t606 = &(g679); int64_t _i606 = n_265; (S4*)_t606->b + hr_ix(_i606, _t606->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:548"); }))).op_); *_t605 = ((uint8_t)(((uint8_t)11LL))); }
{ int32_t *_t607 = &(((*({ hrv *_t608 = &(g679); int64_t _i608 = n_265; (S4*)_t608->b + hr_ix(_i608, _t608->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:548"); }))).a_); *_t607 = ((int32_t)(tl_262)); }
{ int64_t q__266 = f61_pexpr(); 
{ int32_t *_t609 = &(((*({ hrv *_t610 = &(g679); int64_t _i610 = n_265; (S4*)_t610->b + hr_ix(_i610, _t610->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:548"); }))).b_); *_t609 = ((int32_t)(q__266)); }
 }
(void)(f39_ex(((int64_t)12LL), hr_str("assignment statement", 20)));
return n_265;
}
static int64_t f78_pmatch(void) {
int64_t st_271 = g684; 
(void)(f33_nx());
int64_t n_272 = f40_mk(((int64_t)20LL), st_271); 
{ int64_t q__273 = f63_pscrut(); 
{ int32_t *_t611 = &(((*({ hrv *_t612 = &(g679); int64_t _i612 = n_272; (S4*)_t612->b + hr_ix(_i612, _t612->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:206"); }))).a_); *_t611 = ((int32_t)(q__273)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("match expression", 16)));
(void)(f71_parms(n_272));
(void)(f39_ex(((int64_t)10LL), hr_str("match expression", 16)));
if ((((((*({ hrv *_t613 = &(g679); int64_t _i613 = n_272; (S4*)_t613->b + hr_ix(_i613, _t613->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:210"); }))).n_) == (((int32_t)0LL))) && (((g685).n) == (((int64_t)0LL))))) { (void)(f38_perr(hr_str("match must have at least one arm", 32)));
 }
return n_272;
}
static int64_t f79_pfor(void) {
int64_t st_283 = g684; 
(void)(f33_nx());
int64_t n_284 = f40_mk(((int64_t)27LL), st_283); 
if (f41_is(((int64_t)49LL))) { { uint16_t *_t614 = &(((*({ hrv *_t615 = &(g679); int64_t _i615 = n_284; (S4*)_t615->b + hr_ix(_i615, _t615->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:188"); }))).fl_); *_t614 = ((uint16_t)1LL); }
 }
{ int64_t q__285 = f34_ident(hr_str("for binding", 11)); 
{ int32_t *_t616 = &(((*({ hrv *_t617 = &(g679); int64_t _i617 = n_284; (S4*)_t617->b + hr_ix(_i617, _t617->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:189"); }))).s_); *_t616 = ((int32_t)(q__285)); }
 }
bool fb_286 = g731; 
g731 = true;
{ int32_t *_t618 = &(((*({ hrv *_t619 = &(g679); int64_t _i619 = n_284; (S4*)_t619->b + hr_ix(_i619, _t619->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:191"); }))).l_); *_t618 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
{ int32_t *_t620 = &(((*({ hrv *_t621 = &(g679); int64_t _i621 = n_284; (S4*)_t621->b + hr_ix(_i621, _t621->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:191"); }))).n_); *_t620 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
if (f41_is(((int64_t)13LL))) { { int64_t q__287 = f53_ptype(); 
{ int32_t *_t622 = &(((*({ hrv *_t623 = &(g679); int64_t _i623 = n_284; (S4*)_t623->b + hr_ix(_i623, _t623->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:192"); }))).l_); *_t622 = ((int32_t)(q__287)); }
 }
 }
if (f41_is(((int64_t)11LL))) { { int64_t q__288 = f34_ident(hr_str("for index binding", 17)); 
{ int32_t *_t624 = &(((*({ hrv *_t625 = &(g679); int64_t _i625 = n_284; (S4*)_t625->b + hr_ix(_i625, _t625->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:193"); }))).c_); *_t624 = ((int32_t)(q__288)); }
 }
if (f41_is(((int64_t)13LL))) { { int64_t q__289 = f53_ptype(); 
{ int32_t *_t626 = &(((*({ hrv *_t627 = &(g679); int64_t _i627 = n_284; (S4*)_t627->b + hr_ix(_i627, _t627->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:193"); }))).n_); *_t626 = ((int32_t)(q__289)); }
 }
 }
 }
g731 = fb_286;
(void)(f39_ex(((int64_t)76LL), hr_str("for statement", 13)));
int64_t s_290 = f64_sub_begin(true); 
{ int64_t q__291 = f61_pexpr(); 
{ int32_t *_t628 = &(((*({ hrv *_t629 = &(g679); int64_t _i629 = n_284; (S4*)_t629->b + hr_ix(_i629, _t629->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:197"); }))).a_); *_t628 = ((int32_t)(q__291)); }
 }
if (f41_is(((int64_t)17LL))) { { int64_t q__292 = f61_pexpr(); 
{ int32_t *_t630 = &(((*({ hrv *_t631 = &(g679); int64_t _i631 = n_284; (S4*)_t631->b + hr_ix(_i631, _t631->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:198"); }))).b_); *_t630 = ((int32_t)(q__292)); }
 }
 }
(void)(f65_sub_end(s_290));
{ int64_t q__293 = f66_pblock(hr_str("for body", 8)); 
{ int32_t *_t632 = &(((*({ hrv *_t633 = &(g679); int64_t _i633 = n_284; (S4*)_t633->b + hr_ix(_i633, _t633->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:200"); }))).d_); *_t632 = ((int32_t)(q__293)); }
 }
return n_284;
}
static int64_t f80_pbin(int64_t minp_304) {
int64_t l_383 = f81_pun(); 
for (;;) { if (g690) { return l_383;
 }
int64_t pr_385 = f92_binprec(f31_tk()); 
if ((((pr_385) < (minp_304)) || ((pr_385) == (((int64_t)0LL))))) { return l_383;
 }
int64_t op_386 = f31_tk(); 
int64_t st_387 = g684; 
(void)(f33_nx());
int64_t s_388 = f64_sub_begin(g688); 
int64_t r_389 = f80_pbin(((int64_t)((int64_t)pr_385 + (int64_t)((int64_t)1LL)))); 
(void)(f65_sub_end(s_388));
int64_t n_390 = f40_mk(((int64_t)9LL), st_387); 
{ uint8_t *_t635 = &(((*({ hrv *_t636 = &(g679); int64_t _i636 = n_390; (S4*)_t636->b + hr_ix(_i636, _t636->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:280"); }))).op_); *_t635 = ((uint8_t)(op_386)); }
{ int32_t *_t637 = &(((*({ hrv *_t638 = &(g679); int64_t _i638 = n_390; (S4*)_t638->b + hr_ix(_i638, _t638->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:280"); }))).a_); *_t637 = ((int32_t)(l_383)); }
{ int32_t *_t639 = &(((*({ hrv *_t640 = &(g679); int64_t _i640 = n_390; (S4*)_t640->b + hr_ix(_i640, _t640->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:280"); }))).b_); *_t639 = ((int32_t)(r_389)); }
l_383 = n_390;
 } _bk634:; 
}
static int64_t f81_pun(void) {
int64_t k_305 = f31_tk(); 
if ((((((k_305) == (((int64_t)22LL))) || ((k_305) == (((int64_t)47LL)))) || ((k_305) == (((int64_t)48LL)))) || ((k_305) == (((int64_t)49LL))))) { int64_t st_306 = g684; 
(void)(f33_nx());
int64_t s_307 = f64_sub_begin(g688); 
int64_t a_308 = f81_pun(); 
(void)(f65_sub_end(s_307));
int64_t n_309 = f40_mk(((int64_t)10LL), st_306); 
{ uint8_t *_t641 = &(((*({ hrv *_t642 = &(g679); int64_t _i642 = n_309; (S4*)_t642->b + hr_ix(_i642, _t642->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:291"); }))).op_); *_t641 = ((uint8_t)(k_305)); }
{ int32_t *_t643 = &(((*({ hrv *_t644 = &(g679); int64_t _i644 = n_309; (S4*)_t644->b + hr_ix(_i644, _t644->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:291"); }))).a_); *_t643 = ((int32_t)(a_308)); }
return n_309;
 }
return f82_ppost();
}
static int64_t f82_ppost(void) {
int64_t e_367 = f83_pprim(); 
for (;;) { if (g690) { return e_367;
 }
int64_t st_368 = g684; 
if (f41_is(((int64_t)5LL))) { e_367 = f86_pcall(e_367, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), st_368);
continue;
 }
if (((f31_tk()) == (((int64_t)7LL)))) { e_367 = f91_pindex(e_367);
continue;
 }
if (f41_is(((int64_t)16LL))) { int64_t nmid_377 = f34_ident(hr_str("field access", 12)); 
if (((((f31_tk()) == (((int64_t)9LL))) && (!(g688))) && ((((*({ hrv *_t646 = &(g679); int64_t _i646 = e_367; (S4*)_t646->b + hr_ix(_i646, _t646->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:305"); }))).k_) == (((uint8_t)8LL))))) { int64_t b_378 = f40_mk(((int64_t)41LL), ((int64_t)(((*({ hrv *_t647 = &(g679); int64_t _i647 = e_367; (S4*)_t647->b + hr_ix(_i647, _t647->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:306"); }))).t_))); 
{ int32_t *_t648 = &(((*({ hrv *_t649 = &(g679); int64_t _i649 = b_378; (S4*)_t649->b + hr_ix(_i649, _t649->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:306"); }))).s_); *_t648 = ((*({ hrv *_t650 = &(g679); int64_t _i650 = e_367; (S4*)_t650->b + hr_ix(_i650, _t650->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:306"); }))).s_; }
int64_t v_379 = f40_mk(((int64_t)46LL), st_368); 
{ int32_t *_t651 = &(((*({ hrv *_t652 = &(g679); int64_t _i652 = v_379; (S4*)_t652->b + hr_ix(_i652, _t652->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:307"); }))).a_); *_t651 = ((int32_t)(b_378)); }
{ int32_t *_t653 = &(((*({ hrv *_t654 = &(g679); int64_t _i654 = v_379; (S4*)_t654->b + hr_ix(_i654, _t654->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:307"); }))).s_); *_t653 = ((int32_t)(nmid_377)); }
e_367 = f89_pslit(v_379, st_368);
 } else { int64_t d_380 = f40_mk(((int64_t)14LL), st_368); 
{ int32_t *_t655 = &(((*({ hrv *_t656 = &(g679); int64_t _i656 = d_380; (S4*)_t656->b + hr_ix(_i656, _t656->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:309"); }))).a_); *_t655 = ((int32_t)(e_367)); }
{ int32_t *_t657 = &(((*({ hrv *_t658 = &(g679); int64_t _i658 = d_380; (S4*)_t658->b + hr_ix(_i658, _t658->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:309"); }))).s_); *_t657 = ((int32_t)(nmid_377)); }
e_367 = d_380;
 }
continue;
 }
if (f41_is(((int64_t)84LL))) { int64_t n_381 = f40_mk(((int64_t)15LL), st_368); 
{ uint16_t *_t659 = &(((*({ hrv *_t660 = &(g679); int64_t _i660 = n_381; (S4*)_t660->b + hr_ix(_i660, _t660->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:312"); }))).fl_); *_t659 = ({ uint16_t _r661; if (f41_is(((int64_t)47LL))) { _r661 = ((uint16_t)1LL);  } else { _r661 = ((uint16_t)0LL);  } _r661; }); }
{ int32_t *_t662 = &(((*({ hrv *_t663 = &(g679); int64_t _i663 = n_381; (S4*)_t663->b + hr_ix(_i663, _t663->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:312"); }))).a_); *_t662 = ((int32_t)(e_367)); }
{ int64_t q__382 = f53_ptype(); 
{ int32_t *_t664 = &(((*({ hrv *_t665 = &(g679); int64_t _i665 = n_381; (S4*)_t665->b + hr_ix(_i665, _t665->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:312"); }))).b_); *_t664 = ((int32_t)(q__382)); }
 }
e_367 = n_381;
continue;
 }
return e_367;
 } _bk645:; 
}
static int64_t f83_pprim(void) {
int64_t st_310 = g684; 
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
{ int32_t *_t666 = &(((*({ hrv *_t667 = &(g679); int64_t _i667 = id_332; (S4*)_t667->b + hr_ix(_i667, _t667->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:364"); }))).s_); *_t666 = ((int32_t)(name_321)); }
return f86_pcall(id_332, ta_331, st_310);
 }
int64_t t_352 = f40_mk(((int64_t)41LL), st_310); 
{ int32_t *_t668 = &(((*({ hrv *_t669 = &(g679); int64_t _i669 = t_352; (S4*)_t669->b + hr_ix(_i669, _t669->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:365"); }))).s_); *_t668 = ((int32_t)(name_321)); }
{ int32_t *_t670 = &(((*({ hrv *_t671 = &(g679); int64_t _i671 = t_352; (S4*)_t671->b + hr_ix(_i671, _t671->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:365"); }))).l_); *_t670 = ((*({ hrv *_t672 = &(g679); int64_t _i672 = ta_331; (S4*)_t672->b + hr_ix(_i672, _t672->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:365"); }))).l_; }
{ int32_t *_t673 = &(((*({ hrv *_t674 = &(g679); int64_t _i674 = t_352; (S4*)_t674->b + hr_ix(_i674, _t674->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:365"); }))).n_); *_t673 = ((*({ hrv *_t675 = &(g679); int64_t _i675 = ta_331; (S4*)_t675->b + hr_ix(_i675, _t675->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:365"); }))).n_; }
if (f41_is(((int64_t)16LL))) { int64_t v_353 = f40_mk(((int64_t)46LL), st_310); 
{ int32_t *_t676 = &(((*({ hrv *_t677 = &(g679); int64_t _i677 = v_353; (S4*)_t677->b + hr_ix(_i677, _t677->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:366"); }))).a_); *_t676 = ((int32_t)(t_352)); }
{ int64_t q__354 = f34_ident(hr_str("variant literal", 15)); 
{ int32_t *_t678 = &(((*({ hrv *_t679 = &(g679); int64_t _i679 = v_353; (S4*)_t679->b + hr_ix(_i679, _t679->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:366"); }))).s_); *_t678 = ((int32_t)(q__354)); }
 }
return f89_pslit(v_353, st_310);
 }
return f89_pslit(t_352, st_310);
 }
 }
if ((((f31_tk()) == (((int64_t)9LL))) && (!(g688)))) { int64_t t_364 = f40_mk(((int64_t)41LL), st_310); 
{ int32_t *_t680 = &(((*({ hrv *_t681 = &(g679); int64_t _i681 = t_364; (S4*)_t681->b + hr_ix(_i681, _t681->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:370"); }))).s_); *_t680 = ((int32_t)(name_321)); }
return f89_pslit(t_364, st_310);
 }
int64_t id_365 = f40_mk(((int64_t)8LL), st_310); 
{ int32_t *_t682 = &(((*({ hrv *_t683 = &(g679); int64_t _i683 = id_365; (S4*)_t683->b + hr_ix(_i683, _t683->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:371"); }))).s_); *_t682 = ((int32_t)(name_321)); }
return id_365;
 }
hrv m_366 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o685 = &(m_366); hr_fs(_o685, hr_str("expression expected, found '", 28)); hr_fs(_o685, f35_cur_text()); hr_fs(_o685, hr_str("'", 1)); }));
(void)(f38_perr(hr_sl(m_366)));
return f40_mk(((int64_t)6LL), st_310);
}
static int64_t f84_parray(void) {
int64_t st_314 = g684; 
(void)(f33_nx());
int64_t a_315 = f40_mk(((int64_t)16LL), st_314); 
int64_t s_316 = f64_sub_begin(false); 
if (f41_is(((int64_t)17LL))) { { int64_t q__317 = f61_pexpr(); 
{ int32_t *_t686 = &(((*({ hrv *_t687 = &(g679); int64_t _i687 = a_315; (S4*)_t687->b + hr_ix(_i687, _t687->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:406"); }))).c_); *_t686 = ((int32_t)(q__317)); }
 }
 } else { if (((f31_tk()) != (((int64_t)8LL)))) { int64_t first_318 = f61_pexpr(); 
if (f41_is(((int64_t)12LL))) { { int32_t *_t688 = &(((*({ hrv *_t689 = &(g679); int64_t _i689 = a_315; (S4*)_t689->b + hr_ix(_i689, _t689->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:410"); }))).a_); *_t688 = ((int32_t)(first_318)); }
{ int64_t q__319 = f61_pexpr(); 
{ int32_t *_t690 = &(((*({ hrv *_t691 = &(g679); int64_t _i691 = a_315; (S4*)_t691->b + hr_ix(_i691, _t691->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:410"); }))).b_); *_t690 = ((int32_t)(q__319)); }
 }
 } else { int64_t m_320 = f52_wbeg(); 
(void)(({ hrv *_v692 = &(g681); int32_t _x692 = ((int32_t)(first_318)); int32_t *_p692 = (int32_t*)hr_grow(_v692, 1, sizeof _x692); *_p692 = _x692; _p692; }));
while ((f41_is(((int64_t)11LL)) && ((f31_tk()) != (((int64_t)8LL))))) { (void)(({ hrv *_v694 = &(g681); int32_t _x694 = ((int32_t)(f61_pexpr())); int32_t *_p694 = (int32_t*)hr_grow(_v694, 1, sizeof _x694); *_p694 = _x694; _p694; }));
 } _bk693:; 
(void)(f59_setl(a_315, m_320));
 }
 }
 }
(void)(f39_ex(((int64_t)8LL), hr_str("array literal", 13)));
(void)(f65_sub_end(s_316));
return a_315;
}
static int64_t f85_try_tyargs(void) {
int64_t save_322 = g684; 
int64_t nd0_323 = (g679).n; 
int64_t ls0_324 = (g680).n; 
int64_t sp0_325 = (g693).n; 
int64_t ws0_326 = (g681).n; 
g686++;
(void)(f33_nx());
int64_t l_327 = f40_mk(((int64_t)36LL), save_322); 
int64_t m_328 = f52_wbeg(); 
bool ok_329 = false; 
for (;;) { (void)(({ hrv *_v696 = &(g681); int32_t _x696 = ((int32_t)(f53_ptype())); int32_t *_p696 = (int32_t*)hr_grow(_v696, 1, sizeof _x696); *_p696 = _x696; _p696; }));
if ((g687 || (!(f41_is(((int64_t)11LL)))))) { { goto _bk695; }
 }
if ((((f31_tk()) == (((int64_t)40LL))) || ((f31_tk()) == (((int64_t)44LL))))) { { goto _bk695; }
 }
 } _bk695:; 
if ((!(g687))) { if (((f31_tk()) == (((int64_t)44LL)))) { (void)(({ hrv *_v697 = &(g693); int64_t _x697 = g684; int64_t *_p697 = (int64_t*)hr_grow(_v697, 1, sizeof _x697); *_p697 = _x697; _p697; }));
{ uint8_t *_t698 = &(((*({ hrv *_t699 = &(g889); int64_t _i699 = g684; (S3*)_t699->b + hr_ix(_i699, _t699->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:386"); }))).k_); *_t698 = ((uint8_t)(((uint8_t)40LL))); }
ok_329 = true;
 } else { if (((f31_tk()) == (((int64_t)40LL)))) { (void)(f33_nx());
ok_329 = true;
 }
 }
if (ok_329) { ok_329 = false;
if ((((f31_tk()) == (((int64_t)5LL))) || (((f31_tk()) == (((int64_t)9LL))) && (!(g688))))) { ok_329 = true;
 }
if ((((((f31_tk()) == (((int64_t)16LL))) && (!(g688))) && ((f44_tkat(((int64_t)((int64_t)g684 + (int64_t)((int64_t)1LL))))) == (((int64_t)1LL)))) && ((f44_tkat(((int64_t)((int64_t)g684 + (int64_t)((int64_t)2LL))))) == (((int64_t)9LL))))) { ok_329 = true;
 }
 }
 }
g686--;
if ((ok_329 && (!(g687)))) { (void)(f59_setl(l_327, m_328));
return l_327;
 }
g687 = false;
while ((((g693).n) > (sp0_325))) { int64_t q_330 = ({ hrv *_v701 = &(g693); if (!_v701->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:396"); ((int64_t*)_v701->b)[--_v701->n]; }); 
{ uint8_t *_t702 = &(((*({ hrv *_t703 = &(g889); int64_t _i703 = q_330; (S3*)_t703->b + hr_ix(_i703, _t703->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:396"); }))).k_); *_t702 = ((uint8_t)(((uint8_t)44LL))); }
 } _bk700:; 
if ((((g681).n) > (ws0_326))) { (void)(({ hrv *_v704 = &(g681); int64_t _k704 = ((int64_t)((int64_t)(g681).n - (int64_t)ws0_326)); if (_k704 < 0 || _k704 > _v704->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:397"); _v704->n -= _k704; }));
 }
(void)(({ hrv *_v705 = &(g679); int64_t _k705 = nd0_323; if (_k705 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:398"); S4 _x705 = ((S4){ 0}); int64_t _o705 = _v705->n; hr_resize(_v705, _k705, sizeof _x705); for (int64_t _j = _o705; _j < _k705; _j++) ((S4*)_v705->b)[_j] = _x705; }));
(void)(({ hrv *_v706 = &(g680); int64_t _k706 = ls0_324; if (_k706 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:398"); int32_t _x706 = ((int32_t)0LL); int64_t _o706 = _v706->n; hr_resize(_v706, _k706, sizeof _x706); for (int64_t _j = _o706; _j < _k706; _j++) ((int32_t*)_v706->b)[_j] = _x706; }));
g684 = save_322;
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f86_pcall(int64_t callee_333, int64_t tyargs_334, int64_t st_335) {
int64_t c_336 = f40_mk(((int64_t)11LL), st_335); 
{ int32_t *_t707 = &(((*({ hrv *_t708 = &(g679); int64_t _i708 = c_336; (S4*)_t708->b + hr_ix(_i708, _t708->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:317"); }))).a_); *_t707 = ((int32_t)(callee_333)); }
{ int32_t *_t709 = &(((*({ hrv *_t710 = &(g679); int64_t _i710 = c_336; (S4*)_t710->b + hr_ix(_i710, _t710->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:317"); }))).c_); *_t709 = ((int32_t)(tyargs_334)); }
int64_t s_337 = f64_sub_begin(false); 
int64_t m_338 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)6LL))) && ((f31_tk()) != (((int64_t)0LL))))) { (void)(({ hrv *_v712 = &(g681); int32_t _x712 = ((int32_t)(f61_pexpr())); int32_t *_p712 = (int32_t*)hr_grow(_v712, 1, sizeof _x712); *_p712 = _x712; _p712; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk711; }
 }
 } _bk711:; 
(void)(f39_ex(((int64_t)6LL), hr_str("call arguments", 14)));
(void)(f59_setl(c_336, m_338));
(void)(f65_sub_end(s_337));
if ((((f31_tk()) == (((int64_t)9LL))) && (!(g688)))) { { int64_t q__351 = f87_pfunval(); 
{ int32_t *_t713 = &(((*({ hrv *_t714 = &(g679); int64_t _i714 = c_336; (S4*)_t714->b + hr_ix(_i714, _t714->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:324"); }))).b_); *_t713 = ((int32_t)(q__351)); }
 }
if (g689) { g690 = true;
 }
 }
return c_336;
}
static int64_t f87_pfunval(void) {
int64_t st_339 = g684; 
(void)(f39_ex(((int64_t)9LL), hr_str("function value", 14)));
int64_t fv_340 = f40_mk(((int64_t)31LL), st_339); 
int64_t b_341 = f40_mk(((int64_t)23LL), st_339); 
{ int32_t *_t715 = &(((*({ hrv *_t716 = &(g679); int64_t _i716 = fv_340; (S4*)_t716->b + hr_ix(_i716, _t716->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:476"); }))).a_); *_t715 = ((int32_t)(b_341)); }
if ((((f31_tk()) == (((int64_t)1LL))) || ((f31_tk()) == (((int64_t)67LL))))) { int64_t save_342 = g684; 
int64_t nd0_343 = (g679).n; 
int64_t ws0_344 = (g681).n; 
g686++;
bool ok_345 = true; 
int64_t m_346 = f52_wbeg(); 
for (;;) { bool pv_347 = f41_is(((int64_t)67LL)); 
if (((f31_tk()) != (((int64_t)1LL)))) { ok_345 = false;
{ goto _bk717; }
 }
int64_t p_348 = f40_mk(((int64_t)32LL), g684); 
{ int32_t *_t718 = &(((*({ hrv *_t719 = &(g679); int64_t _i719 = p_348; (S4*)_t719->b + hr_ix(_i719, _t719->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:485"); }))).s_); *_t718 = ((int32_t)(((*({ hrv *_t720 = &(g889); int64_t _i720 = g684; (S3*)_t720->b + hr_ix(_i720, _t720->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:485"); }))).v_)); }
if (pv_347) { { uint16_t *_t721 = &(((*({ hrv *_t722 = &(g679); int64_t _i722 = p_348; (S4*)_t722->b + hr_ix(_i722, _t722->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:485"); }))).fl_); *_t721 = ((uint16_t)1LL); }
 }
(void)(f33_nx());
if (f41_is(((int64_t)13LL))) { { int64_t q__349 = f53_ptype(); 
{ int32_t *_t723 = &(((*({ hrv *_t724 = &(g679); int64_t _i724 = p_348; (S4*)_t724->b + hr_ix(_i724, _t724->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:486"); }))).a_); *_t723 = ((int32_t)(q__349)); }
 }
 }
(void)(({ hrv *_v725 = &(g681); int32_t _x725 = ((int32_t)(p_348)); int32_t *_p725 = (int32_t*)hr_grow(_v725, 1, sizeof _x725); *_p725 = _x725; _p725; }));
if ((g687 || (!(f41_is(((int64_t)11LL)))))) { { goto _bk717; }
 }
 } _bk717:; 
if (((g687 || (!(ok_345))) || (!(f41_is(((int64_t)55LL)))))) { ok_345 = false;
 }
g686--;
if (ok_345) { (void)(f59_setl(fv_340, m_346));
{ uint16_t *_t726 = &(((*({ hrv *_t727 = &(g679); int64_t _i727 = fv_340; (S4*)_t727->b + hr_ix(_i727, _t727->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:492"); }))).fl_); *_t726 = ((uint16_t)1LL); }
 } else { g687 = false;
if ((((g681).n) > (ws0_344))) { (void)(({ hrv *_v728 = &(g681); int64_t _k728 = ((int64_t)((int64_t)(g681).n - (int64_t)ws0_344)); if (_k728 < 0 || _k728 > _v728->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:493"); _v728->n -= _k728; }));
 }
(void)(({ hrv *_v729 = &(g679); int64_t _k729 = nd0_343; if (_k729 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:493"); S4 _x729 = ((S4){ 0}); int64_t _o729 = _v729->n; hr_resize(_v729, _k729, sizeof _x729); for (int64_t _j = _o729; _j < _k729; _j++) ((S4*)_v729->b)[_j] = _x729; }));
g684 = save_342;
 }
 }
(void)(f67_pbody(b_341));
(void)(f88_set_end(fv_340));
return fv_340;
}
static void f88_set_end(int64_t n_350) {
while ((((g694).n) < ((g679).n))) { (void)(({ hrv *_v731 = &(g694); int32_t _x731 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p731 = (int32_t*)hr_grow(_v731, 1, sizeof _x731); *_p731 = _x731; _p731; }));
 } _bk730:; 
{ int32_t *_t732 = &((*({ hrv *_t733 = &(g694); int64_t _i733 = n_350; (int32_t*)_t733->b + hr_ix(_i733, _t733->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:28"); }))); *_t732 = ((int32_t)((g679).n)); }
}
static int64_t f89_pslit(int64_t ty_355, int64_t st_356) {
int64_t n_357 = f40_mk(((int64_t)17LL), st_356); 
{ int32_t *_t734 = &(((*({ hrv *_t735 = &(g679); int64_t _i735 = n_357; (S4*)_t735->b + hr_ix(_i735, _t735->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:464"); }))).a_); *_t734 = ((int32_t)(ty_355)); }
(void)(f70_pinits(n_357, false));
int64_t named_358 = ((int64_t)0LL); 
bool cf_359 = false; 
{ int32_t _e737 = ((*({ hrv *_t738 = &(g679); int64_t _i738 = n_357; (S4*)_t738->b + hr_ix(_i738, _t738->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:467"); }))).n_; for (int32_t _k737 = 0; _k737 < _e737; _k737++) { int32_t i_360 = (int32_t)_k737; int64_t fi_363 = f90_kid(n_357, ((int64_t)(i_360))); 
if (((((*({ hrv *_t739 = &(g679); int64_t _i739 = fi_363; (S4*)_t739->b + hr_ix(_i739, _t739->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:467"); }))).k_) == (((uint8_t)37LL)))) { cf_359 = true;
 } else { if (((((*({ hrv *_t740 = &(g679); int64_t _i740 = fi_363; (S4*)_t740->b + hr_ix(_i740, _t740->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:467"); }))).s_) >= (((int32_t)0LL)))) { named_358++;
 }
 }
 } } _bk736:; 
if ((((!(cf_359)) && ((named_358) > (((int64_t)0LL)))) && ((named_358) != (((int64_t)(((*({ hrv *_t741 = &(g679); int64_t _i741 = n_357; (S4*)_t741->b + hr_ix(_i741, _t741->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:468"); }))).n_)))))) { (void)(f38_perr(hr_str("struct literal mixes named and positional initializers", 54)));
 }
return n_357;
}
static int64_t f90_kid(int64_t n_361, int64_t i_362) {
return ((int64_t)((*({ hrv *_t742 = &(g680); int64_t _i742 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t743 = &(g679); int64_t _i743 = n_361; (S4*)_t743->b + hr_ix(_i743, _t743->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:56"); }))).l_)) + (int64_t)i_362)); (int32_t*)_t742->b + hr_ix(_i742, _t742->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:56"); }))));
}
static int64_t f91_pindex(int64_t obj_369) {
int64_t st_370 = g684; 
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
{ int32_t *_t744 = &(((*({ hrv *_t745 = &(g679); int64_t _i745 = r_375; (S4*)_t745->b + hr_ix(_i745, _t745->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:336"); }))).a_); *_t744 = ((int32_t)(obj_369)); }
{ int32_t *_t746 = &(((*({ hrv *_t747 = &(g679); int64_t _i747 = r_375; (S4*)_t747->b + hr_ix(_i747, _t747->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:336"); }))).b_); *_t746 = ((int32_t)(lo_372)); }
if (lfe_373) { { uint16_t *_t748 = &(((*({ hrv *_t749 = &(g679); int64_t _i749 = r_375; (S4*)_t749->b + hr_ix(_i749, _t749->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:337"); }))).fl_); *_t748 = ((uint16_t)1LL); }
 }
if (((f31_tk()) != (((int64_t)8LL)))) { if (f41_is(((int64_t)51LL))) { { uint16_t *_t750 = &(((*({ hrv *_t751 = &(g679); int64_t _i751 = r_375; (S4*)_t751->b + hr_ix(_i751, _t751->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:338"); }))).fl_); *_t750 = ((uint16_t)((uint64_t)(*_t750) | (uint64_t)((uint16_t)2LL))); }
 }
{ int64_t q__376 = f61_pexpr(); 
{ int32_t *_t752 = &(((*({ hrv *_t753 = &(g679); int64_t _i753 = r_375; (S4*)_t753->b + hr_ix(_i753, _t753->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:338"); }))).c_); *_t752 = ((int32_t)(q__376)); }
 }
 }
 } else { if (lfe_373) { (void)(f38_perr(hr_str("'^' bounds are only valid in slices", 35)));
 }
r_375 = f40_mk(((int64_t)12LL), st_370);
{ int32_t *_t754 = &(((*({ hrv *_t755 = &(g679); int64_t _i755 = r_375; (S4*)_t755->b + hr_ix(_i755, _t755->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:341"); }))).a_); *_t754 = ((int32_t)(obj_369)); }
{ int32_t *_t756 = &(((*({ hrv *_t757 = &(g679); int64_t _i757 = r_375; (S4*)_t757->b + hr_ix(_i757, _t757->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:341"); }))).b_); *_t756 = ((int32_t)(lo_372)); }
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
int64_t st_414 = g684; 
(void)(f33_nx());
int64_t n_415 = f40_mk(((int64_t)51LL), st_414); 
{ int64_t q__416 = f50_declname(hr_str("struct declaration", 18)); 
{ int32_t *_t758 = &(((*({ hrv *_t759 = &(g679); int64_t _i759 = n_415; (S4*)_t759->b + hr_ix(_i759, _t759->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:618"); }))).s_); *_t758 = ((int32_t)(q__416)); }
 }
{ int32_t *_t760 = &(((*({ hrv *_t761 = &(g679); int64_t _i761 = n_415; (S4*)_t761->b + hr_ix(_i761, _t761->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:618"); }))).a_); *_t760 = ((int32_t)(g691)); }
{ int64_t q__417 = f51_pgenerics(); 
{ int32_t *_t762 = &(((*({ hrv *_t763 = &(g679); int64_t _i763 = n_415; (S4*)_t763->b + hr_ix(_i763, _t763->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:619"); }))).d_); *_t762 = ((int32_t)(q__417)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("struct declaration", 18)));
(void)(f95_pfields(n_415, hr_str("struct body", 11)));
(void)(f39_ex(((int64_t)10LL), hr_str("struct declaration", 18)));
return n_415;
}
static void f95_pfields(int64_t n_418, hsl ctx_419) {
int64_t m_420 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t f_421 = f40_mk(((int64_t)55LL), g684); 
if (f41_is(((int64_t)70LL))) { { uint16_t *_t765 = &(((*({ hrv *_t766 = &(g679); int64_t _i766 = f_421; (S4*)_t766->b + hr_ix(_i766, _t766->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:601"); }))).fl_); *_t765 = ((uint16_t)4LL); }
if (((f31_tk()) == (((int64_t)2LL)))) { { int32_t *_t767 = &(((*({ hrv *_t768 = &(g679); int64_t _i768 = f_421; (S4*)_t768->b + hr_ix(_i768, _t768->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:601"); }))).c_); *_t767 = ((int32_t)(((*({ hrv *_t769 = &(g889); int64_t _i769 = g684; (S3*)_t769->b + hr_ix(_i769, _t769->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:601"); }))).v_)); }
(void)(f33_nx());
 }
 } else { bool cq_422 = f41_is(((int64_t)69LL)); 
if ((cq_422 || f41_is(((int64_t)66LL)))) { { uint16_t *_t770 = &(((*({ hrv *_t771 = &(g679); int64_t _i771 = f_421; (S4*)_t771->b + hr_ix(_i771, _t771->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:604"); }))).fl_); *_t770 = ({ uint16_t _r772; if (cq_422) { _r772 = ((uint16_t)3LL);  } else { _r772 = ((uint16_t)1LL);  } _r772; }); }
 }
{ int64_t q__423 = f34_ident(ctx_419); 
{ int32_t *_t773 = &(((*({ hrv *_t774 = &(g679); int64_t _i774 = f_421; (S4*)_t774->b + hr_ix(_i774, _t774->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:605"); }))).s_); *_t773 = ((int32_t)(q__423)); }
 }
if ((!(f75_amni_type()))) { (void)(f39_ex(((int64_t)13LL), ctx_419));
 }
{ int64_t q__424 = f53_ptype(); 
{ int32_t *_t775 = &(((*({ hrv *_t776 = &(g679); int64_t _i776 = f_421; (S4*)_t776->b + hr_ix(_i776, _t776->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:607"); }))).a_); *_t775 = ((int32_t)(q__424)); }
 }
if (f41_is(((int64_t)36LL))) { { int64_t q__425 = f61_pexpr(); 
{ int32_t *_t777 = &(((*({ hrv *_t778 = &(g679); int64_t _i778 = f_421; (S4*)_t778->b + hr_ix(_i778, _t778->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:608"); }))).b_); *_t777 = ((int32_t)(q__425)); }
 }
 }
 }
(void)(({ hrv *_v779 = &(g681); int32_t _x779 = ((int32_t)(f_421)); int32_t *_p779 = (int32_t*)hr_grow(_v779, 1, sizeof _x779); *_p779 = _x779; _p779; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk764; }
 }
 } _bk764:; 
(void)(f59_setl(n_418, m_420));
}
static int64_t f96_penum(void) {
int64_t st_426 = g684; 
(void)(f33_nx());
int64_t n_427 = f40_mk(((int64_t)52LL), st_426); 
{ int64_t q__428 = f50_declname(hr_str("enum declaration", 16)); 
{ int32_t *_t780 = &(((*({ hrv *_t781 = &(g679); int64_t _i781 = n_427; (S4*)_t781->b + hr_ix(_i781, _t781->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:628"); }))).s_); *_t780 = ((int32_t)(q__428)); }
 }
{ int32_t *_t782 = &(((*({ hrv *_t783 = &(g679); int64_t _i783 = n_427; (S4*)_t783->b + hr_ix(_i783, _t783->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:628"); }))).a_); *_t782 = ((int32_t)(g691)); }
{ int64_t q__429 = f51_pgenerics(); 
{ int32_t *_t784 = &(((*({ hrv *_t785 = &(g679); int64_t _i785 = n_427; (S4*)_t785->b + hr_ix(_i785, _t785->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:629"); }))).d_); *_t784 = ((int32_t)(q__429)); }
 }
(void)(f39_ex(((int64_t)9LL), hr_str("enum declaration", 16)));
int64_t m_430 = f52_wbeg(); 
while ((((f31_tk()) != (((int64_t)10LL))) && ((f31_tk()) != (((int64_t)0LL))))) { int64_t v_431 = f40_mk(((int64_t)56LL), g684); 
{ int64_t q__432 = f34_ident(hr_str("enum variant", 12)); 
{ int32_t *_t787 = &(((*({ hrv *_t788 = &(g679); int64_t _i788 = v_431; (S4*)_t788->b + hr_ix(_i788, _t788->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:633"); }))).s_); *_t787 = ((int32_t)(q__432)); }
 }
if (f41_is(((int64_t)9LL))) { { uint16_t *_t789 = &(((*({ hrv *_t790 = &(g679); int64_t _i790 = v_431; (S4*)_t790->b + hr_ix(_i790, _t790->n, "/home/anmire/ai/amni-lang/helium-fix/hc/parse.amni:634"); }))).fl_); *_t789 = ((uint16_t)1LL); }
(void)(f95_pfields(v_431, hr_str("variant body", 12)));
(void)(f39_ex(((int64_t)10LL), hr_str("enum variant", 12)));
 }
(void)(({ hrv *_v791 = &(g681); int32_t _x791 = ((int32_t)(v_431)); int32_t *_p791 = (int32_t*)hr_grow(_v791, 1, sizeof _x791); *_p791 = _x791; _p791; }));
if ((!(f41_is(((int64_t)11LL))))) { { goto _bk786; }
 }
 } _bk786:; 
(void)(f59_setl(n_427, m_430));
(void)(f39_ex(((int64_t)10LL), hr_str("enum declaration", 16)));
return n_427;
}
static void f97_collect(int64_t file_440, int64_t t0_441, int64_t t1_442) {
{ int64_t _e793 = t1_442; for (int64_t _k793 = t0_441; _k793 < _e793; _k793++) { int64_t i_443 = (int64_t)_k793; int64_t n_444 = ((int64_t)((*({ hrv *_t794 = &(g682); int64_t _i794 = i_443; (int32_t*)_t794->b + hr_ix(_i794, _t794->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:27"); })))); 
S4 x_445 = (*({ hrv *_t795 = &(g679); int64_t _i795 = n_444; (S4*)_t795->b + hr_ix(_i795, _t795->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:28"); })); 
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
if (((k_446) == (((int64_t)33LL)))) { (void)(f99_dadd(((int64_t)5LL), n_444, file_440, f98_qual(((int64_t)((x_445).c_)), ((int64_t)((*({ hrv *_t796 = &(g680); int64_t _i796 = (x_445).l_; (int32_t*)_t796->b + hr_ix(_i796, _t796->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:34"); })))))));
 }
 } } _bk792:; 
}
static int64_t f98_qual(int64_t ns_447, int64_t name_448) {
return ({ int64_t _r797; if (((ns_447) < (((int64_t)0LL)))) { _r797 = name_448;  } else { hrv s_449 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v799 = &(s_449); hsl _s799 = f10_nm(ns_447); hr_append(_v799, _s799.p, _s799.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v800 = &(s_449); hsl _s800 = hr_str("::", 2); hr_append(_v800, _s800.p, _s800.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v801 = &(s_449); hsl _s801 = f10_nm(name_448); hr_append(_v801, _s801.p, _s801.n, sizeof(uint8_t)); }));
_r797 = f8_intern(hr_sl(s_449));  } _r797; });
}
static void f99_dadd(int64_t k_450, int64_t node_451, int64_t file_452, int64_t name_453) {
while ((((g467).n) <= (name_453))) { (void)(({ hrv *_v803 = &(g467); int32_t _x803 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p803 = (int32_t*)hr_grow(_v803, 1, sizeof _x803); *_p803 = _x803; _p803; }));
 } _bk802:; 
int64_t i_454 = (g466).n; 
(void)(({ hrv *_v804 = &(g466); S5 _x804 = ((S5){ .k_ = ((uint8_t)(k_450)), .node_ = ((int32_t)(node_451)), .file_ = ((int32_t)(file_452)), .next_ = (*({ hrv *_t805 = &(g467); int64_t _i805 = name_453; (int32_t*)_t805->b + hr_ix(_i805, _t805->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:19"); })), .name_ = ((int32_t)(name_453)), }); S5 *_p804 = (S5*)hr_grow(_v804, 1, sizeof _x804); *_p804 = _x804; _p804; }));
{ int32_t *_t806 = &((*({ hrv *_t807 = &(g467); int64_t _i807 = name_453; (int32_t*)_t807->b + hr_ix(_i807, _t807->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:20"); }))); *_t806 = ((int32_t)(i_454)); }
}
static L49 f100_lib_path(hsl name_459) {
L49 p_460 = ({ L49 _t808; memset(&_t808, 0, sizeof _t808); _t808.n = 0; _t808; }); 
(void)(({ L49 *_v809 = &(p_460); hsl _s809 = hr_sl(g470); if (_v809->n + _s809.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:56"); memmove(_v809->e + _v809->n, _s809.p, (size_t)_s809.n * sizeof _v809->e[0]); _v809->n += _s809.n; }));
(void)(({ L49 *_v810 = &(p_460); uint8_t _x810 = ((uint8_t)47LL); if (_v810->n >= 1024) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:56"); _v810->e[_v810->n] = _x810; &_v810->e[_v810->n++]; }));
(void)(({ L49 *_v811 = &(p_460); hsl _s811 = name_459; if (_v811->n + _s811.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:56"); memmove(_v811->e + _v811->n, _s811.p, (size_t)_s811.n * sizeof _v811->e[0]); _v811->n += _s811.n; }));
(void)(({ L49 *_v812 = &(p_460); hsl _s812 = hr_str(".amni", 5); if (_v812->n + _s812.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:56"); memmove(_v812->e + _v812->n, _s812.p, (size_t)_s812.n * sizeof _v812->e[0]); _v812->n += _s812.n; }));
return p_460;
}
static int64_t f101_load_import(int64_t name_463, int64_t from_464, int64_t t_465) {
L49 p_466 = ({ L49 _t813; memset(&_t813, 0, sizeof _t813); _t813.n = 0; _t813; }); 
(void)(({ L49 *_v814 = &(p_466); hsl _s814 = hr_sl(g469); if (_v814->n + _s814.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:59"); memmove(_v814->e + _v814->n, _s814.p, (size_t)_s814.n * sizeof _v814->e[0]); _v814->n += _s814.n; }));
(void)(({ L49 *_v815 = &(p_466); uint8_t _x815 = ((uint8_t)47LL); if (_v815->n >= 1024) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:59"); _v815->e[_v815->n] = _x815; &_v815->e[_v815->n++]; }));
(void)(({ L49 *_v816 = &(p_466); hsl _s816 = f10_nm(name_463); if (_v816->n + _s816.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:59"); memmove(_v816->e + _v816->n, _s816.p, (size_t)_s816.n * sizeof _v816->e[0]); _v816->n += _s816.n; }));
(void)(({ L49 *_v817 = &(p_466); hsl _s817 = hr_str(".amni", 5); if (_v817->n + _s817.n > 1024) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:59"); memmove(_v817->e + _v817->n, _s817.p, (size_t)_s817.n * sizeof _v817->e[0]); _v817->n += _s817.n; }));
int64_t r_467 = f19_try_load(({ hsl _t818 = ({ L49 *_t819 = &(p_466); (hsl){ (uint8_t*)_t819->e, _t819->n }; }); int64_t _l818 = 0, _h818 = _t818.n; if (_l818 < 0 || _h818 < _l818 || _h818 > _t818.n) hr_slerr(_l818, _h818, _t818.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:60"); (hsl){ _t818.p + _l818 * (int64_t)sizeof(uint8_t), _h818 - _l818 }; })); 
if (((r_467) == (((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))) { L49 lp_468 = f100_lib_path(f10_nm(name_463)); 
r_467 = f19_try_load(({ hsl _t820 = ({ L49 *_t821 = &(lp_468); (hsl){ (uint8_t*)_t821->e, _t821->n }; }); int64_t _l820 = 0, _h820 = _t820.n; if (_l820 < 0 || _h820 < _l820 || _h820 > _t820.n) hr_slerr(_l820, _h820, _t820.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:61"); (hsl){ _t820.p + _l820 * (int64_t)sizeof(uint8_t), _h820 - _l820 }; }));
 }
if (((r_467) == (((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))) { hrv m_469 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o823 = &(m_469); hr_fs(_o823, hr_str("cannot find module ", 19)); hr_fs(_o823, f10_nm(name_463)); }));
(void)(f102_derr(t_465, hr_sl(m_469)));
return ((int64_t)(0 - (uint64_t)(((int64_t)2LL))));
 }
return r_467;
}
static void f102_derr(int64_t t_470, hsl m_471) {
if ((((g472).n) > (((int64_t)0LL)))) { return;
 }
S3 x_474 = (*({ hrv *_t824 = &(g889); int64_t _i824 = f103_max(t_470, ((int64_t)0LL)); (S3*)_t824->b + hr_ix(_i824, _t824->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:14"); })); 
(void)(({ hrv *_v825 = &(g472); hsl _s825 = f10_nm(((int64_t)(((*({ hrv *_t826 = &(g888); int64_t _i826 = (x_474).f_; (S2*)_t826->b + hr_ix(_i826, _t826->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:14"); }))).name_))); hr_append(_v825, _s825.p, _s825.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o827 = &(g472); hr_fs(_o827, hr_str(":", 1)); hr_fi(_o827, (x_474).line_); hr_fs(_o827, hr_str(": error: ", 9)); hr_fs(_o827, m_471); }));
}
static int64_t f103_max(int64_t a_472, int64_t b_473) {
if (((a_472) < (b_473))) { return b_473;
 }
return a_472;
}
static bool f104_check_program(void) {
g386 = f105_new_inst(((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)0LL), (g679).n, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
{ uint8_t *_t828 = &(((*({ hrv *_t829 = &(g373); int64_t _i829 = g386; (S6*)_t829->b + hr_ix(_i829, _t829->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:439"); }))).st_); *_t828 = ((uint8_t)2LL); }
g384 = g386;
g385 = g386;
int64_t md_489 = f106_lookup(f8_intern(hr_str("main", 4)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)4LL)); 
if (((md_489) < (((int64_t)0LL)))) { (void)(f108_cerr(((int64_t)0LL), hr_str("no main function", 16)));
return false;
 }
{ hrv *_v831 = &(g466); for (int64_t _k831 = 0; _k831 < _v831->n; _k831++) { S5 d_493 = ((S5*)_v831->b)[_k831]; int64_t i_494 = (int64_t)_k831; if ((((((int64_t)((d_493).k_))) == (((int64_t)5LL))) && (((d_493).file_) == (((int32_t)0LL))))) { (void)(f109_global_type(i_494));
 }
 } } _bk830:; 
int64_t mi_1414 = f241_get_inst(((int64_t)(((*({ hrv *_t832 = &(g466); int64_t _i832 = md_489; (S5*)_t832->b + hr_ix(_i832, _t832->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:444"); }))).node_)), (g310).n, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
{ hrv *_v834 = &(g466); for (int64_t _k834 = 0; _k834 < _v834->n; _k834++) { S5 d_1415 = ((S5*)_v834->b)[_k834]; int64_t i_1416 = (int64_t)_k834; if (((((int64_t)((d_1415).k_))) == (((int64_t)5LL)))) { (void)(f109_global_type(i_1416));
 }
 } } _bk833:; 
return ((g388) == (((int64_t)0LL)));
}
static int64_t f105_new_inst(int64_t node_477, int64_t lo_478, int64_t hi_479, int64_t par_480) {
int64_t i_481 = (g373).n; 
(void)(({ hrv *_v835 = &(g373); S6 _x835 = ((S6){ .node_ = ((int32_t)(node_477)), .lo_ = ((int32_t)(lo_478)), .hi_ = ((int32_t)(hi_479)), .ab_ = ((int32_t)((g378).n)), .par_ = ((int32_t)(par_480)), .cfn_ = ((int32_t)(i_481)), .g0_ = ((int32_t)((g377).n)), .gn_ = ((int32_t)0LL), .ret_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .p0_ = ((int32_t)0LL), .pn_ = ((int32_t)0LL), .st_ = ((uint8_t)0LL), .blk_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .bown_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .name_ = ({ int32_t _r836; if (((node_477) >= (((int64_t)0LL)))) { _r836 = ((*({ hrv *_t837 = &(g679); int64_t _i837 = node_477; (S4*)_t837->b + hr_ix(_i837, _t837->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:27"); }))).s_;  } else { _r836 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));  } _r836; }), }); S6 *_p835 = (S6*)hr_grow(_v835, 1, sizeof _x835); *_p835 = _x835; _p835; }));
int64_t n_482 = ((int64_t)((int64_t)hi_479 - (int64_t)lo_478)); 
(void)(({ hrv *_v838 = &(g378); int64_t _k838 = ((int64_t)((int64_t)(g378).n + (int64_t)n_482)); if (_k838 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:29"); int32_t _x838 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o838 = _v838->n; hr_resize(_v838, _k838, sizeof _x838); for (int64_t _j = _o838; _j < _k838; _j++) ((int32_t*)_v838->b)[_j] = _x838; }));
(void)(({ hrv *_v839 = &(g379); int64_t _k839 = ((int64_t)((int64_t)(g379).n + (int64_t)n_482)); if (_k839 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:29"); int32_t _x839 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o839 = _v839->n; hr_resize(_v839, _k839, sizeof _x839); for (int64_t _j = _o839; _j < _k839; _j++) ((int32_t*)_v839->b)[_j] = _x839; }));
(void)(({ hrv *_v840 = &(g380); int64_t _k840 = ((int64_t)((int64_t)(g380).n + (int64_t)n_482)); if (_k840 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:29"); uint8_t _x840 = ((uint8_t)0LL); int64_t _o840 = _v840->n; hr_resize(_v840, _k840, sizeof _x840); for (int64_t _j = _o840; _j < _k840; _j++) ((uint8_t*)_v840->b)[_j] = _x840; }));
(void)(({ hrv *_v841 = &(g381); int64_t _k841 = ((int64_t)((int64_t)(g381).n + (int64_t)n_482)); if (_k841 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:29"); int32_t _x841 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o841 = _v841->n; hr_resize(_v841, _k841, sizeof _x841); for (int64_t _j = _o841; _j < _k841; _j++) ((int32_t*)_v841->b)[_j] = _x841; }));
(void)(({ hrv *_v842 = &(g382); int64_t _k842 = ((int64_t)((int64_t)(g382).n + (int64_t)n_482)); if (_k842 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:29"); int32_t _x842 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int64_t _o842 = _v842->n; hr_resize(_v842, _k842, sizeof _x842); for (int64_t _j = _o842; _j < _k842; _j++) ((int32_t*)_v842->b)[_j] = _x842; }));
return i_481;
}
static int64_t f106_lookup(int64_t name_483, int64_t ns_484, int64_t k_485) {
if (((ns_484) >= (((int64_t)0LL)))) { int64_t d_487 = f107_dmap(f98_qual(ns_484, name_483)); 
while (((d_487) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t844 = &(g466); int64_t _i844 = d_487; (S5*)_t844->b + hr_ix(_i844, _t844->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:74"); }))).k_))) == (k_485))) { return d_487;
 }
d_487 = ((int64_t)(((*({ hrv *_t845 = &(g466); int64_t _i845 = d_487; (S5*)_t845->b + hr_ix(_i845, _t845->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:74"); }))).next_));
 } _bk843:; 
 }
int64_t d_488 = f107_dmap(name_483); 
while (((d_488) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t847 = &(g466); int64_t _i847 = d_488; (S5*)_t847->b + hr_ix(_i847, _t847->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:76"); }))).k_))) == (k_485))) { return d_488;
 }
d_488 = ((int64_t)(((*({ hrv *_t848 = &(g466); int64_t _i848 = d_488; (S5*)_t848->b + hr_ix(_i848, _t848->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:76"); }))).next_));
 } _bk846:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f107_dmap(int64_t name_486) {
return ({ int64_t _r849; if ((((name_486) < (((int64_t)0LL))) || ((name_486) >= ((g467).n)))) { _r849 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r849 = ((int64_t)((*({ hrv *_t850 = &(g467); int64_t _i850 = name_486; (int32_t*)_t850->b + hr_ix(_i850, _t850->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:15"); }))));  } _r849; });
}
static void f108_cerr(int64_t n_490, hsl m_491) {
g388++;
if ((((g387).n) > (((int64_t)0LL)))) { return;
 }
S3 x_492 = (*({ hrv *_t851 = &(g889); int64_t _i851 = ((*({ hrv *_t852 = &(g679); int64_t _i852 = f103_max(n_490, ((int64_t)0LL)); (S4*)_t852->b + hr_ix(_i852, _t852->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:24"); }))).t_; (S3*)_t851->b + hr_ix(_i851, _t851->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:24"); })); 
(void)(({ hrv *_v853 = &(g387); hsl _s853 = f10_nm(((int64_t)(((*({ hrv *_t854 = &(g888); int64_t _i854 = (x_492).f_; (S2*)_t854->b + hr_ix(_i854, _t854->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:24"); }))).name_))); hr_append(_v853, _s853.p, _s853.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o855 = &(g387); hr_fs(_o855, hr_str(":", 1)); hr_fi(_o855, (x_492).line_); hr_fs(_o855, hr_str(": error: ", 9)); hr_fs(_o855, m_491); }));
}
static int64_t f109_global_type(int64_t d_495) {
while ((((g428).n) < ((g466).n))) { (void)(({ hrv *_v857 = &(g428); int32_t _x857 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p857 = (int32_t*)hr_grow(_v857, 1, sizeof _x857); *_p857 = _x857; _p857; }));
(void)(({ hrv *_v858 = &(g429); uint8_t _x858 = ((uint8_t)0LL); uint8_t *_p858 = (uint8_t*)hr_grow(_v858, 1, sizeof _x858); *_p858 = _x858; _p858; }));
 } _bk856:; 
if ((((*({ hrv *_t859 = &(g428); int64_t _i859 = d_495; (int32_t*)_t859->b + hr_ix(_i859, _t859->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:322"); }))) >= (((int32_t)0LL)))) { return ((int64_t)((*({ hrv *_t860 = &(g428); int64_t _i860 = d_495; (int32_t*)_t860->b + hr_ix(_i860, _t860->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:322"); }))));
 }
int64_t g_496 = ((int64_t)(((*({ hrv *_t861 = &(g466); int64_t _i861 = d_495; (S5*)_t861->b + hr_ix(_i861, _t861->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:323"); }))).node_)); 
S4 x_497 = (*({ hrv *_t862 = &(g679); int64_t _i862 = g_496; (S4*)_t862->b + hr_ix(_i862, _t862->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:324"); })); 
int64_t saved_498 = g384; 
int64_t sc_499 = g385; 
g384 = g386;
g385 = g386;
int64_t t_500 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((x_497).a_) >= (((int32_t)0LL)))) { t_500 = f113_rtype(((int64_t)((x_497).a_)), f110_ns_of(g_496));
{ int32_t *_t863 = &((*({ hrv *_t864 = &(g428); int64_t _i864 = d_495; (int32_t*)_t864->b + hr_ix(_i864, _t864->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:328"); }))); *_t863 = ((int32_t)(t_500)); }
if ((((x_497).b_) >= (((int32_t)0LL)))) { int64_t iv_670 = f90_kid(((int64_t)((x_497).b_)), ((int64_t)0LL)); 
(void)(f138_ck(iv_670, t_500));
(void)(f141_conv(iv_670, t_500));
 }
 } else { if ((((*({ hrv *_t865 = &(g429); int64_t _i865 = d_495; (uint8_t*)_t865->b + hr_ix(_i865, _t865->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:330"); }))) == (((uint8_t)1LL)))) { (void)(f108_cerr(g_496, hr_str("global initializer depends on itself", 36)));
g384 = saved_498;
g385 = sc_499;
return g552;
 }
{ uint8_t *_t866 = &((*({ hrv *_t867 = &(g429); int64_t _i867 = d_495; (uint8_t*)_t867->b + hr_ix(_i867, _t867->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:331"); }))); *_t866 = ((uint8_t)1LL); }
int64_t iv_1411 = f90_kid(((int64_t)((x_497).b_)), ((int64_t)0LL)); 
(void)(f138_ck(iv_1411, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
t_500 = f181_default_t(iv_1411);
if (((((*({ hrv *_t868 = &(g528); int64_t _i868 = t_500; (S1*)_t868->b + hr_ix(_i868, _t868->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:335"); }))).k_) == (((uint8_t)18LL)))) { t_500 = g553;
 }
{ int32_t *_t869 = &((*({ hrv *_t870 = &(g428); int64_t _i870 = d_495; (int32_t*)_t870->b + hr_ix(_i870, _t870->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:336"); }))); *_t869 = ((int32_t)(t_500)); }
 }
if ((!(f245_ORD_HAS(d_495)))) { (void)(({ hrv *_v871 = &(g392); int32_t _x871 = ((int32_t)(d_495)); int32_t *_p871 = (int32_t*)hr_grow(_v871, 1, sizeof _x871); *_p871 = _x871; _p871; }));
 }
g384 = saved_498;
g385 = sc_499;
return t_500;
}
static int64_t f110_ns_of(int64_t n_501) {
return f112_file_ns(f111_node_file(n_501));
}
static int64_t f111_node_file(int64_t n_502) {
return ((int64_t)(((*({ hrv *_t872 = &(g889); int64_t _i872 = ((*({ hrv *_t873 = &(g679); int64_t _i873 = n_502; (S4*)_t873->b + hr_ix(_i873, _t873->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:23"); }))).t_; (S3*)_t872->b + hr_ix(_i872, _t872->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:23"); }))).f_));
}
static int64_t f112_file_ns(int64_t f_503) {
return ({ int64_t _r874; if (((f_503) < ((g473).n))) { _r874 = ((int64_t)((*({ hrv *_t875 = &(g473); int64_t _i875 = f_503; (int32_t*)_t875->b + hr_ix(_i875, _t875->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:24"); }))));  } else { _r874 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r874; });
}
static int64_t f113_rtype(int64_t n_504, int64_t ns_505) {
if (((n_504) < (((int64_t)0LL)))) { return g535;
 }
S4 x_506 = (*({ hrv *_t876 = &(g679); int64_t _i876 = n_504; (S4*)_t876->b + hr_ix(_i876, _t876->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:93"); })); 
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
if ((((((*({ hrv *_t877 = &(g528); int64_t _i877 = e_512; (S1*)_t877->b + hr_ix(_i877, _t877->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:103"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t878 = &(g528); int64_t _i878 = e_512; (S1*)_t878->b + hr_ix(_i878, _t878->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:103"); }))).c_) < (((int32_t)0LL))))) { if (((((int64_t)((int64_t)fl_513 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { return f117_t_ref(((int64_t)(((*({ hrv *_t879 = &(g528); int64_t _i879 = e_512; (S1*)_t879->b + hr_ix(_i879, _t879->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:103"); }))).a_)), ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t880 = &(g528); int64_t _i880 = e_512; (S1*)_t880->b + hr_ix(_i880, _t880->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:103"); }))).fl_)) | (int64_t)((int64_t)2LL))));
 }
return e_512;
 }
return f117_t_ref(e_512, fl_513);
 }
if (((k_507) == (((int64_t)42LL)))) { int64_t e_520 = f113_rtype(((int64_t)((x_506).a_)), ns_505); 
int64_t a_521 = ((int64_t)((x_506).op_)); 
if (((a_521) == (((int64_t)1LL)))) { M55 _t881 = f118_ceval(((int64_t)((x_506).b_)), ns_505); int64_t v_581 = _t881.r0; bool ok_582 = _t881.r1; 
if ((!(ok_582))) { (void)(f102_derr(((int64_t)((x_506).t_)), hr_str("array size must be a constant", 29)));
 }
return f123_t_arr(e_520, ((int64_t)1LL), v_581, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
 }
if (((a_521) == (((int64_t)3LL)))) { if ((((x_506).b_) < (((int32_t)0LL)))) { return f123_t_arr(e_520, ((int64_t)3LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)6LL));
 }
M55 _t882 = f118_ceval(((int64_t)((x_506).b_)), ns_505); int64_t v_587 = _t882.r0; bool ok_588 = _t882.r1; 
if ((!(ok_588))) { (void)(f102_derr(((int64_t)((x_506).t_)), hr_str("capacity must be a constant", 27)));
 }
return f123_t_arr(e_520, ((int64_t)3LL), v_587, f124_lim_lenstore(v_587));
 }
if (((a_521) == (((int64_t)2LL)))) { int64_t ls_590 = ({ int64_t _r883; if ((((x_506).c_) < (((int32_t)0LL)))) { _r883 = ((int64_t)6LL);  } else { _r883 = ({ int64_t _r884; if (((((int64_t)((x_506).c_))) == (((int64_t)90LL)))) { _r884 = ((int64_t)8LL);  } else { _r884 = f115_int_storage_of_tok(((int64_t)((x_506).c_)));  } _r884; });  } _r883; }); 
return f123_t_arr(e_520, ((int64_t)2LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ls_590);
 }
return f123_t_arr(e_520, a_521, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));
 }
if (((k_507) == (((int64_t)46LL)))) { int64_t b_591 = f113_rtype(((int64_t)((x_506).a_)), ns_505); 
if (((((*({ hrv *_t885 = &(g528); int64_t _i885 = b_591; (S1*)_t885->b + hr_ix(_i885, _t885->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:116"); }))).k_) != (((uint8_t)6LL)))) { (void)(f102_derr(((int64_t)((x_506).t_)), hr_str("variant type of a non-enum", 26)));
return g552;
 }
int64_t ei_592 = ((int64_t)(((*({ hrv *_t886 = &(g528); int64_t _i886 = b_591; (S1*)_t886->b + hr_ix(_i886, _t886->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:117"); }))).a_)); 
{ int32_t _e888 = ((*({ hrv *_t889 = &(g533); int64_t _i889 = ei_592; (S8*)_t889->b + hr_ix(_i889, _t889->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:118"); }))).vnum_; for (int32_t _k888 = 0; _k888 < _e888; _k888++) { int32_t i_593 = (int32_t)_k888; if (((((*({ hrv *_t890 = &(g534); int64_t _i890 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t891 = &(g533); int64_t _i891 = ei_592; (S8*)_t891->b + hr_ix(_i891, _t891->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:118"); }))).v0_)) + (int64_t)((int64_t)(i_593)))); (S9*)_t890->b + hr_ix(_i890, _t890->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:118"); }))).name_) == ((x_506).s_))) { return f125_t_variant(ei_592, ((int64_t)(i_593)));
 }
 } } _bk887:; 
hrv m_596 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t894 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o893 = &(m_596); hr_fs(_o893, hr_str("no variant ", 11)); hr_fs(_o893, f10_nm(((int64_t)((x_506).s_)))); hr_fs(_o893, hr_str(" in ", 4)); hr_fs(_o893, hr_sl(*hr_tmp(&_t894, f126_ty_name(b_591)))); }));
}
(void)(f102_derr(((int64_t)((x_506).t_)), hr_sl(m_596)));
return g552;
 }
if (((k_507) == (((int64_t)45LL)))) { return g555;
 }
if (((k_507) == (((int64_t)41LL)))) { int64_t name_612 = ((int64_t)((x_506).s_)); 
if ((((x_506).n_) == (((int32_t)0LL)))) { int64_t g_615 = f130_gb_find(name_612); 
if (((g_615) >= (((int64_t)0LL)))) { return g_615;
 }
 }
L66 args_616 = ({ L66 _t895; memset(&_t895, 0, sizeof _t895); _t895.n = 0; _t895; }); 
{ int32_t _e897 = (x_506).n_; for (int32_t _k897 = 0; _k897 < _e897; _k897++) { int32_t i_617 = (int32_t)_k897; int64_t at0_618 = f113_rtype(f90_kid(n_504, ((int64_t)(i_617))), ns_505); 
(void)(({ L66 *_v898 = &(args_616); int32_t _x898 = ((int32_t)(at0_618)); if (_v898->n >= 16) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:127"); _v898->e[_v898->n] = _x898; &_v898->e[_v898->n++]; }));
 } } _bk896:; 
int64_t d_619 = f121_lookup_q(name_612, ns_505, ((int64_t)1LL)); 
if (((d_619) >= (((int64_t)0LL)))) { return f135_t_struct(f131_inst_struct(((int64_t)(((*({ hrv *_t899 = &(g466); int64_t _i899 = d_619; (S5*)_t899->b + hr_ix(_i899, _t899->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:129"); }))).node_)), ({ hsl _t900 = ({ L66 *_t901 = &(args_616); (hsl){ (uint8_t*)_t901->e, _t901->n }; }); int64_t _l900 = 0, _h900 = _t900.n; if (_l900 < 0 || _h900 < _l900 || _h900 > _t900.n) hr_slerr(_l900, _h900, _t900.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:129"); (hsl){ _t900.p + _l900 * (int64_t)sizeof(int32_t), _h900 - _l900 }; })));
 }
d_619 = f121_lookup_q(name_612, ns_505, ((int64_t)2LL));
if (((d_619) >= (((int64_t)0LL)))) { return f137_t_enum(f136_inst_enum(((int64_t)(((*({ hrv *_t902 = &(g466); int64_t _i902 = d_619; (S5*)_t902->b + hr_ix(_i902, _t902->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:131"); }))).node_)), ({ hsl _t903 = ({ L66 *_t904 = &(args_616); (hsl){ (uint8_t*)_t904->e, _t904->n }; }); int64_t _l903 = 0, _h903 = _t903.n; if (_l903 < 0 || _h903 < _l903 || _h903 > _t903.n) hr_slerr(_l903, _h903, _t903.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:131"); (hsl){ _t903.p + _l903 * (int64_t)sizeof(int32_t), _h903 - _l903 }; })), ((((uint16_t)((uint64_t)(x_506).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))));
 }
d_619 = f121_lookup_q(name_612, ns_505, ((int64_t)3LL));
if (((d_619) >= (((int64_t)0LL)))) { int64_t an_668 = ((int64_t)(((*({ hrv *_t905 = &(g466); int64_t _i905 = d_619; (S5*)_t905->b + hr_ix(_i905, _t905->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:133"); }))).node_)); 
return f113_rtype(((int64_t)(((*({ hrv *_t906 = &(g679); int64_t _i906 = an_668; (S4*)_t906->b + hr_ix(_i906, _t906->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:133"); }))).b_)), f110_ns_of(an_668));
 }
hrv m_669 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o908 = &(m_669); hr_fs(_o908, hr_str("unknown type ", 13)); hr_fs(_o908, f10_nm(name_612)); }));
(void)(f102_derr(((int64_t)((x_506).t_)), hr_sl(m_669)));
return g552;
 }
(void)(f102_derr(((int64_t)((x_506).t_)), hr_str("bad type", 8)));
return g552;
}
static int64_t f114_prim_type(int64_t k_508) {
if (((k_508) == (((int64_t)89LL)))) { return g536;
 }
if (((k_508) == (((int64_t)90LL)))) { return g551;
 }
if (((k_508) == (((int64_t)99LL)))) { return g545;
 }
if ((((k_508) == (((int64_t)100LL))) || ((k_508) == (((int64_t)104LL))))) { return g546;
 }
int64_t s_510 = f115_int_storage_of_tok(k_508); 
return ({ int64_t _r909; if (((s_510) >= (((int64_t)0LL)))) { _r909 = f17_t_int(s_510);  } else { _r909 = g552;  } _r909; });
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
M56 _t910 = f119_ceval3(n_522, ns_523); int64_t v_578 = _t910.r0; int64_t c_579 = _t910.r1; bool ok_580 = _t910.r2; 
return (M55){ v_578, ok_580 };
}
static M56 f119_ceval3(int64_t n_524, int64_t ns_525) {
if (((n_524) < (((int64_t)0LL)))) { return (M56){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
S4 x_526 = (*({ hrv *_t911 = &(g679); int64_t _i911 = n_524; (S4*)_t911->b + hr_ix(_i911, _t911->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:201"); })); 
int64_t k_527 = ((int64_t)((x_526).k_)); 
if (((k_527) == (((int64_t)1LL)))) { return (M56){ ((*({ hrv *_t912 = &(g889); int64_t _i912 = (x_526).t_; (S3*)_t912->b + hr_ix(_i912, _t912->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:203"); }))).v_, ({ int64_t _r913; if (((*({ hrv *_t914 = &(g889); int64_t _i914 = (x_526).t_; (S3*)_t914->b + hr_ix(_i914, _t914->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:203"); }))).uns_) { _r913 = ((int64_t)7LL);  } else { _r913 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r913; }), true };
 }
if (((k_527) == (((int64_t)10LL)))) { M56 _t915 = f119_ceval3(((int64_t)((x_526).a_)), ns_525); int64_t v_528 = _t915.r0; int64_t c_529 = _t915.r1; bool ok_530 = _t915.r2; 
if (((((int64_t)((x_526).op_))) == (((int64_t)22LL)))) { int64_t c2_531 = ({ int64_t _r916; if ((((c_529) == (((int64_t)7LL))) && ((((*({ hrv *_t917 = &(g679); int64_t _i917 = (x_526).a_; (S4*)_t917->b + hr_ix(_i917, _t917->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:206"); }))).k_) == (((uint8_t)1LL))))) { _r916 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r916 = c_529;  } _r916; }); 
return (M56){ f120_cwrap(((int64_t)((int64_t)((int64_t)0LL) - (int64_t)v_528)), c2_531), c2_531, ok_530 };
 }
if (((((int64_t)((x_526).op_))) == (((int64_t)48LL)))) { return (M56){ f120_cwrap(((int64_t)~(v_528)), c_529), c_529, ok_530 };
 }
return (M56){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
if (((k_527) == (((int64_t)9LL)))) { M56 _t918 = f119_ceval3(((int64_t)((x_526).a_)), ns_525); int64_t a_536 = _t918.r0; int64_t ca_537 = _t918.r1; bool oa_538 = _t918.r2; 
M56 _t919 = f119_ceval3(((int64_t)((x_526).b_)), ns_525); int64_t b_539 = _t919.r0; int64_t cb_540 = _t919.r1; bool ob_541 = _t919.r2; 
if (((!(oa_538)) || (!(ob_541)))) { return (M56){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
int64_t o_542 = ((int64_t)((x_526).op_)); 
int64_t c_543 = ({ int64_t _r920; if ((((o_542) == (((int64_t)43LL))) || ((o_542) == (((int64_t)44LL))))) { _r920 = ca_537;  } else { _r920 = ({ int64_t _r921; if (((ca_537) >= (((int64_t)0LL)))) { _r921 = ca_537;  } else { _r921 = cb_540;  } _r921; });  } _r920; }); 
bool un_544 = ((c_543) >= (((int64_t)4LL))); 
uint64_t ua_545 = ((uint64_t)(a_536)); 
uint64_t ub_546 = ((uint64_t)(b_539)); 
uint64_t sh_547 = ({ uint64_t _r922; if (((c_543) >= (((int64_t)0LL)))) { _r922 = ((uint64_t)(((uint64_t)((uint64_t)((uint64_t)((((uint64_t)8LL)) << ((((int64_t)(((int64_t)((int64_t)c_543 & (int64_t)((int64_t)3LL)))))) & 63))) - (uint64_t)((uint64_t)1LL)))));  } else { _r922 = ((uint64_t)63LL);  } _r922; }); 
if (((o_542) == (((int64_t)21LL)))) { return (M56){ f120_cwrap(((int64_t)((int64_t)a_536 + (int64_t)b_539)), c_543), c_543, true };
 }
if (((o_542) == (((int64_t)22LL)))) { return (M56){ f120_cwrap(((int64_t)((int64_t)a_536 - (int64_t)b_539)), c_543), c_543, true };
 }
if (((o_542) == (((int64_t)23LL)))) { return (M56){ f120_cwrap(((int64_t)((int64_t)a_536 * (int64_t)b_539)), c_543), c_543, true };
 }
if (((o_542) == (((int64_t)24LL)))) { if (((b_539) == (((int64_t)0LL)))) { return (M56){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
if (un_544) { return (M56){ f120_cwrap(((int64_t)(HR_UDIV(uint64_t, ua_545, ub_546, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:220"))), c_543), c_543, true };
 }
if (((b_539) == (((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))) { return (M56){ f120_cwrap(((int64_t)((int64_t)((int64_t)0LL) - (int64_t)a_536)), c_543), c_543, true };
 }
return (M56){ f120_cwrap(HR_SDIV(int64_t, a_536, b_539, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:220"), c_543), c_543, true };
 }
if (((o_542) == (((int64_t)25LL)))) { if (((b_539) == (((int64_t)0LL)))) { return (M56){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
if (un_544) { return (M56){ f120_cwrap(((int64_t)(HR_UDIV_MOD(uint64_t, ua_545, ub_546, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:221"))), c_543), c_543, true };
 }
if ((((b_539) == (((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))) || ((b_539) == (((int64_t)1LL))))) { return (M56){ ((int64_t)0LL), c_543, true };
 }
int64_t r_548 = HR_SMOD(int64_t, a_536, b_539, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:221"); 
return (M56){ f120_cwrap(({ int64_t _r923; if (((r_548) < (((int64_t)0LL)))) { _r923 = ({ int64_t _r924; if (((b_539) < (((int64_t)0LL)))) { _r924 = ((int64_t)((int64_t)r_548 - (int64_t)b_539));  } else { _r924 = ((int64_t)((int64_t)r_548 + (int64_t)b_539));  } _r924; });  } else { _r923 = r_548;  } _r923; }), c_543), c_543, true };
 }
if (((o_542) == (((int64_t)43LL)))) { return (M56){ f120_cwrap(((int64_t)((a_536) << ((((uint64_t)((uint64_t)ub_546 & (uint64_t)sh_547))) & 63))), c_543), c_543, true };
 }
if (((o_542) == (((int64_t)44LL)))) { if (un_544) { uint64_t w_549 = ({ uint64_t _r925; if ((((c_543) >= (((int64_t)0LL))) && ((((int64_t)((int64_t)c_543 & (int64_t)((int64_t)3LL)))) != (((int64_t)3LL))))) { _r925 = ((uint64_t)((uint64_t)((uint64_t)(a_536)) & (uint64_t)((uint64_t)((uint64_t)((uint64_t)((((uint64_t)1LL)) << ((((uint64_t)((uint64_t)sh_547 + (uint64_t)((uint64_t)1LL)))) & 63))) - (uint64_t)((uint64_t)1LL)))));  } else { _r925 = ua_545;  } _r925; }); 
return (M56){ f120_cwrap(((int64_t)(((uint64_t)((w_549) >> ((((uint64_t)((uint64_t)ub_546 & (uint64_t)sh_547))) & 63))))), c_543), c_543, true };
 }
return (M56){ f120_cwrap(((int64_t)((a_536) >> ((((uint64_t)((uint64_t)ub_546 & (uint64_t)sh_547))) & 63))), c_543), c_543, true };
 }
if (((o_542) == (((int64_t)49LL)))) { return (M56){ f120_cwrap(((int64_t)((int64_t)a_536 & (int64_t)b_539)), c_543), c_543, true };
 }
if (((o_542) == (((int64_t)50LL)))) { return (M56){ f120_cwrap(((int64_t)((int64_t)a_536 | (int64_t)b_539)), c_543), c_543, true };
 }
if (((o_542) == (((int64_t)51LL)))) { return (M56){ f120_cwrap(((int64_t)((int64_t)a_536 ^ (int64_t)b_539)), c_543), c_543, true };
 }
return (M56){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
if (((k_527) == (((int64_t)15LL)))) { M56 _t926 = f119_ceval3(((int64_t)((x_526).a_)), ns_525); int64_t v_550 = _t926.r0; int64_t c_551 = _t926.r1; bool ok_552 = _t926.r2; 
int64_t tn0_553 = ((int64_t)((x_526).b_)); 
if (((((*({ hrv *_t927 = &(g679); int64_t _i927 = tn0_553; (S4*)_t927->b + hr_ix(_i927, _t927->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:227"); }))).k_) == (((uint8_t)40LL)))) { int64_t tc_554 = f115_int_storage_of_tok(((int64_t)(((*({ hrv *_t928 = &(g679); int64_t _i928 = tn0_553; (S4*)_t928->b + hr_ix(_i928, _t928->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:227"); }))).op_))); 
if (((tc_554) >= (((int64_t)0LL)))) { return (M56){ f120_cwrap(v_550, tc_554), tc_554, ok_552 };
 }
 }
return (M56){ v_550, c_551, ok_552 };
 }
if (((k_527) == (((int64_t)8LL)))) { int64_t d_564 = f121_lookup_q(((int64_t)((x_526).s_)), ns_525, ((int64_t)5LL)); 
if (((d_564) < (((int64_t)0LL)))) { return (M56){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
int64_t g_565 = ((int64_t)(((*({ hrv *_t929 = &(g466); int64_t _i929 = d_564; (S5*)_t929->b + hr_ix(_i929, _t929->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:231"); }))).node_)); 
if ((((((uint16_t)((uint64_t)((*({ hrv *_t930 = &(g679); int64_t _i930 = g_565; (S4*)_t930->b + hr_ix(_i930, _t930->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:232"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || ((((*({ hrv *_t931 = &(g679); int64_t _i931 = g_565; (S4*)_t931->b + hr_ix(_i931, _t931->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:232"); }))).b_) < (((int32_t)0LL))))) { return (M56){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
M56 _t932 = f119_ceval3(f90_kid(((int64_t)(((*({ hrv *_t933 = &(g679); int64_t _i933 = g_565; (S4*)_t933->b + hr_ix(_i933, _t933->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:233"); }))).b_)), ((int64_t)0LL)), f110_ns_of(g_565)); int64_t v_566 = _t932.r0; int64_t c_567 = _t932.r1; bool ok_568 = _t932.r2; 
int64_t tn0_569 = ((int64_t)(((*({ hrv *_t934 = &(g679); int64_t _i934 = g_565; (S4*)_t934->b + hr_ix(_i934, _t934->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:234"); }))).a_)); 
if ((((tn0_569) >= (((int64_t)0LL))) && ((((*({ hrv *_t935 = &(g679); int64_t _i935 = tn0_569; (S4*)_t935->b + hr_ix(_i935, _t935->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:235"); }))).k_) == (((uint8_t)40LL))))) { int64_t tc_570 = f115_int_storage_of_tok(((int64_t)(((*({ hrv *_t936 = &(g679); int64_t _i936 = tn0_569; (S4*)_t936->b + hr_ix(_i936, _t936->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:235"); }))).op_))); 
if (((tc_570) >= (((int64_t)0LL)))) { return (M56){ f120_cwrap(v_566, tc_570), tc_570, ok_568 };
 }
 }
return (M56){ v_566, c_567, ok_568 };
 }
if (((((k_527) == (((int64_t)14LL))) && hr_streq(f10_nm(((int64_t)((x_526).s_))), hr_str("len", 3))) && ((((*({ hrv *_t937 = &(g679); int64_t _i937 = (x_526).a_; (S4*)_t937->b + hr_ix(_i937, _t937->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:238"); }))).k_) == (((uint8_t)8LL))))) { int64_t d_571 = f121_lookup_q(((int64_t)(((*({ hrv *_t938 = &(g679); int64_t _i938 = (x_526).a_; (S4*)_t938->b + hr_ix(_i938, _t938->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:239"); }))).s_)), ns_525, ((int64_t)5LL)); 
if (((d_571) < (((int64_t)0LL)))) { return (M56){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
int64_t g_572 = ((int64_t)(((*({ hrv *_t939 = &(g466); int64_t _i939 = d_571; (S5*)_t939->b + hr_ix(_i939, _t939->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:241"); }))).node_)); 
if (((((*({ hrv *_t940 = &(g679); int64_t _i940 = g_572; (S4*)_t940->b + hr_ix(_i940, _t940->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:242"); }))).a_) >= (((int32_t)0LL)))) { int64_t t_573 = f113_rtype(((int64_t)(((*({ hrv *_t941 = &(g679); int64_t _i941 = g_572; (S4*)_t941->b + hr_ix(_i941, _t941->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:242"); }))).a_)), f110_ns_of(g_572)); 
if ((((((*({ hrv *_t942 = &(g528); int64_t _i942 = t_573; (S1*)_t942->b + hr_ix(_i942, _t942->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:242"); }))).k_) == (((uint8_t)8LL))) && ((((*({ hrv *_t943 = &(g528); int64_t _i943 = t_573; (S1*)_t943->b + hr_ix(_i943, _t943->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:242"); }))).s_) == (((uint8_t)(((uint8_t)1LL))))))) { return (M56){ ((*({ hrv *_t944 = &(g528); int64_t _i944 = t_573; (S1*)_t944->b + hr_ix(_i944, _t944->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:242"); }))).b_, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
 }
 }
if (((((*({ hrv *_t945 = &(g679); int64_t _i945 = g_572; (S4*)_t945->b + hr_ix(_i945, _t945->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:243"); }))).b_) >= (((int32_t)0LL)))) { int64_t iv_574 = f90_kid(((int64_t)(((*({ hrv *_t946 = &(g679); int64_t _i946 = g_572; (S4*)_t946->b + hr_ix(_i946, _t946->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:243"); }))).b_)), ((int64_t)0LL)); 
if (((((*({ hrv *_t947 = &(g679); int64_t _i947 = iv_574; (S4*)_t947->b + hr_ix(_i947, _t947->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:243"); }))).k_) == (((uint8_t)16LL)))) { if (((((*({ hrv *_t948 = &(g679); int64_t _i948 = iv_574; (S4*)_t948->b + hr_ix(_i948, _t948->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:243"); }))).b_) >= (((int32_t)0LL)))) { M56 _t949 = f119_ceval3(((int64_t)(((*({ hrv *_t950 = &(g679); int64_t _i950 = iv_574; (S4*)_t950->b + hr_ix(_i950, _t950->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:243"); }))).b_)), f110_ns_of(g_572)); int64_t v_575 = _t949.r0; int64_t c_576 = _t949.r1; bool ok_577 = _t949.r2; 
return (M56){ v_575, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ok_577 };
 }
return (M56){ ((int64_t)(((*({ hrv *_t951 = &(g679); int64_t _i951 = iv_574; (S4*)_t951->b + hr_ix(_i951, _t951->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:243"); }))).n_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
 }
if (((((*({ hrv *_t952 = &(g679); int64_t _i952 = iv_574; (S4*)_t952->b + hr_ix(_i952, _t952->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:243"); }))).k_) == (((uint8_t)3LL)))) { return (M56){ ((int64_t)(((*({ hrv *_t953 = &(g889); int64_t _i953 = ((*({ hrv *_t954 = &(g679); int64_t _i954 = iv_574; (S4*)_t954->b + hr_ix(_i954, _t954->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:243"); }))).t_; (S3*)_t953->b + hr_ix(_i953, _t953->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:243"); }))).w_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), true };
 }
 }
return (M56){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
 }
return (M56){ ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false };
}
static int64_t f120_cwrap(int64_t v_532, int64_t c_533) {
if ((((c_533) < (((int64_t)0LL))) || ((((int64_t)((int64_t)c_533 & (int64_t)((int64_t)3LL)))) == (((int64_t)3LL))))) { return v_532;
 }
int64_t b_534 = ((int64_t)((((int64_t)8LL)) << ((((int64_t)(((int64_t)((int64_t)c_533 & (int64_t)((int64_t)3LL)))))) & 63))); 
uint64_t u_535 = ((uint64_t)((uint64_t)((uint64_t)(v_532)) & (uint64_t)((uint64_t)((uint64_t)((uint64_t)((((uint64_t)1LL)) << ((((uint64_t)(b_534))) & 63))) - (uint64_t)((uint64_t)1LL))))); 
if ((((c_533) < (((int64_t)4LL))) && ((u_535) >= (((uint64_t)((((uint64_t)1LL)) << ((((uint64_t)(((int64_t)((int64_t)b_534 - (int64_t)((int64_t)1LL)))))) & 63))))))) { return ((int64_t)((int64_t)((int64_t)(u_535)) - (int64_t)((int64_t)((((int64_t)1LL)) << ((b_534) & 63)))));
 }
return ((int64_t)(u_535));
}
static int64_t f121_lookup_q(int64_t q_555, int64_t ns_556, int64_t k_557) {
M57 _t955 = f122_split_q(q_555); int64_t a_561 = _t955.r0; int64_t b_562 = _t955.r1; 
if (((a_561) == (((int64_t)(0 - (uint64_t)(((int64_t)2LL))))))) { return f106_lookup(b_562, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), k_557);
 }
if (((a_561) >= (((int64_t)0LL)))) { int64_t d_563 = f107_dmap(q_555); 
while (((d_563) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t957 = &(g466); int64_t _i957 = d_563; (S5*)_t957->b + hr_ix(_i957, _t957->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:87"); }))).k_))) == (k_557))) { return d_563;
 }
d_563 = ((int64_t)(((*({ hrv *_t958 = &(g466); int64_t _i958 = d_563; (S5*)_t958->b + hr_ix(_i958, _t958->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:87"); }))).next_));
 } _bk956:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
return f106_lookup(b_562, ns_556, k_557);
}
static M57 f122_split_q(int64_t q_558) {
hsl s_559 = f10_nm(q_558); 
{ int64_t _e960 = (s_559).n; for (int64_t _k960 = 0; _k960 < _e960; _k960++) { int64_t i_560 = (int64_t)_k960; if ((((((*({ hsl _t961 = s_559; int64_t _i961 = i_560; (uint8_t*)_t961.p + hr_ix(_i961, _t961.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:81"); }))) == (((uint8_t)58LL))) && ((((int64_t)((int64_t)i_560 + (int64_t)((int64_t)1LL)))) < ((s_559).n))) && (((*({ hsl _t962 = s_559; int64_t _i962 = ((int64_t)((int64_t)i_560 + (int64_t)((int64_t)1LL))); (uint8_t*)_t962.p + hr_ix(_i962, _t962.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:81"); }))) == (((uint8_t)58LL))))) { if (((i_560) == (((int64_t)0LL)))) { return (M57){ ((int64_t)(0 - (uint64_t)(((int64_t)2LL)))), f8_intern(({ hsl _t963 = s_559; int64_t _l963 = ((int64_t)2LL), _h963 = _t963.n; if (_l963 < 0 || _h963 < _l963 || _h963 > _t963.n) hr_slerr(_l963, _h963, _t963.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:81"); (hsl){ _t963.p + _l963 * (int64_t)sizeof(uint8_t), _h963 - _l963 }; })) };
 }
return (M57){ f8_intern(({ hsl _t964 = s_559; int64_t _l964 = 0, _h964 = i_560; if (_l964 < 0 || _h964 < _l964 || _h964 > _t964.n) hr_slerr(_l964, _h964, _t964.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:81"); (hsl){ _t964.p + _l964 * (int64_t)sizeof(uint8_t), _h964 - _l964 }; })), f8_intern(({ hsl _t965 = s_559; int64_t _l965 = ((int64_t)((int64_t)i_560 + (int64_t)((int64_t)2LL))), _h965 = _t965.n; if (_l965 < 0 || _h965 < _l965 || _h965 > _t965.n) hr_slerr(_l965, _h965, _t965.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:81"); (hsl){ _t965.p + _l965 * (int64_t)sizeof(uint8_t), _h965 - _l965 }; })) };
 }
 } } _bk959:; 
return (M57){ ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), q_558 };
}
static int64_t f123_t_arr(int64_t e_583, int64_t ak_584, int64_t size_585, int64_t ls_586) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)8LL))), .s_ = ((uint8_t)(ak_584)), .a_ = ((int32_t)(e_583)), .c_ = ((int32_t)(ls_586)), .b_ = size_585, }));
}
static int64_t f124_lim_lenstore(int64_t cap_589) {
return ({ int64_t _r966; if (((cap_589) < (((int64_t)256LL)))) { _r966 = ((int64_t)4LL);  } else { _r966 = ({ int64_t _r967; if (((cap_589) < (((int64_t)65536LL)))) { _r967 = ((int64_t)5LL);  } else { _r967 = ({ int64_t _r968; if (((cap_589) < (((int64_t)4294967296LL)))) { _r968 = ((int64_t)6LL);  } else { _r968 = ((int64_t)7LL);  } _r968; });  } _r967; });  } _r966; });
}
static int64_t f125_t_variant(int64_t ei_594, int64_t vi_595) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)7LL))), .a_ = ((int32_t)(ei_594)), .c_ = ((int32_t)(vi_595)), }));
}
static hrv f126_ty_name(int64_t t_597) {
hrv s_598 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(f127_ty_name_into(t_597, (&(s_598))));
return ({ hrv _mv970 = s_598; s_598.b = 0; s_598.n = 0; _mv970; });
}
static void f127_ty_name_into(int64_t t_599, hrv* out_600) {
S1 x_601 = (*({ hrv *_t971 = &(g528); int64_t _i971 = t_599; (S1*)_t971->b + hr_ix(_i971, _t971->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:162"); })); 
int64_t k_602 = ((int64_t)((x_601).k_)); 
if (((k_602) == (((int64_t)0LL)))) { (void)(({ hrv *_v972 = out_600; hsl _s972 = hr_str("<error>", 7); hr_append(_v972, _s972.p, _s972.n, sizeof(uint8_t)); }));
return;
 }
if (((k_602) == (((int64_t)1LL)))) { (void)(({ hrv *_v973 = out_600; hsl _s973 = hr_str("void", 4); hr_append(_v973, _s973.p, _s973.n, sizeof(uint8_t)); }));
return;
 }
if (((k_602) == (((int64_t)2LL)))) { (void)(({ hrv *_v974 = out_600; hsl _s974 = hr_str("bool", 4); hr_append(_v974, _s974.p, _s974.n, sizeof(uint8_t)); }));
return;
 }
if (((k_602) == (((int64_t)3LL)))) { (void)(f128_ls_kind_name(((int64_t)((x_601).s_)), out_600));
return;
 }
if (((k_602) == (((int64_t)4LL)))) { (void)(({ hrv *_v975 = out_600; hsl _s975 = ({ hsl _r976; if ((((x_601).s_) == (((uint8_t)4LL)))) { _r976 = hr_str("f32", 3);  } else { _r976 = hr_str("f64", 3);  } _r976; }); hr_append(_v975, _s975.p, _s975.n, sizeof(uint8_t)); }));
return;
 }
if (((k_602) == (((int64_t)17LL)))) { (void)(({ hrv *_v977 = out_600; hsl _s977 = hr_str("varint", 6); hr_append(_v977, _s977.p, _s977.n, sizeof(uint8_t)); }));
return;
 }
if (((k_602) == (((int64_t)11LL)))) { (void)(({ hrv *_v978 = out_600; hsl _s978 = hr_str("null", 4); hr_append(_v978, _s978.p, _s978.n, sizeof(uint8_t)); }));
return;
 }
if (((k_602) == (((int64_t)12LL)))) { (void)(({ hrv *_v979 = out_600; hsl _s979 = hr_str("integer constant", 16); hr_append(_v979, _s979.p, _s979.n, sizeof(uint8_t)); }));
return;
 }
if (((k_602) == (((int64_t)13LL)))) { (void)(({ hrv *_v980 = out_600; hsl _s980 = hr_str("float constant", 14); hr_append(_v980, _s980.p, _s980.n, sizeof(uint8_t)); }));
return;
 }
if (((k_602) == (((int64_t)18LL)))) { (void)(({ hrv *_v981 = out_600; hsl _s981 = hr_str("const u8[:]", 11); hr_append(_v981, _s981.p, _s981.n, sizeof(uint8_t)); }));
return;
 }
if (((k_602) == (((int64_t)16LL)))) { (void)(({ hrv *_v982 = out_600; hsl _s982 = f10_nm(((int64_t)((x_601).a_))); hr_append(_v982, _s982.p, _s982.n, sizeof(uint8_t)); }));
return;
 }
if (((k_602) == (((int64_t)5LL)))) { (void)(({ hrv *_v983 = out_600; hsl _s983 = f10_nm(((int64_t)(((*({ hrv *_t984 = &(g531); int64_t _i984 = (x_601).a_; (S10*)_t984->b + hr_ix(_i984, _t984->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:175"); }))).name_))); hr_append(_v983, _s983.p, _s983.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t985 = &(g531); int64_t _i985 = (x_601).a_; (S10*)_t985->b + hr_ix(_i985, _t985->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:175"); }))).ta_)), ((int64_t)(((*({ hrv *_t986 = &(g531); int64_t _i986 = (x_601).a_; (S10*)_t986->b + hr_ix(_i986, _t986->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:175"); }))).tn_)), out_600));
return;
 }
if (((k_602) == (((int64_t)6LL)))) { (void)(({ hrv *_v987 = out_600; hsl _s987 = f10_nm(((int64_t)(((*({ hrv *_t988 = &(g533); int64_t _i988 = (x_601).a_; (S8*)_t988->b + hr_ix(_i988, _t988->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:176"); }))).name_))); hr_append(_v987, _s987.p, _s987.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t989 = &(g533); int64_t _i989 = (x_601).a_; (S8*)_t989->b + hr_ix(_i989, _t989->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:176"); }))).ta_)), ((int64_t)(((*({ hrv *_t990 = &(g533); int64_t _i990 = (x_601).a_; (S8*)_t990->b + hr_ix(_i990, _t990->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:176"); }))).tn_)), out_600));
if (((((uint16_t)((uint64_t)(x_601).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v991 = out_600; hsl _s991 = hr_str("..", 2); hr_append(_v991, _s991.p, _s991.n, sizeof(uint8_t)); }));
 }
return;
 }
if (((k_602) == (((int64_t)7LL)))) { (void)(({ hrv *_v992 = out_600; hsl _s992 = f10_nm(((int64_t)(((*({ hrv *_t993 = &(g533); int64_t _i993 = (x_601).a_; (S8*)_t993->b + hr_ix(_i993, _t993->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:177"); }))).name_))); hr_append(_v992, _s992.p, _s992.n, sizeof(uint8_t)); }));
(void)(f129_targs_into(((int64_t)(((*({ hrv *_t994 = &(g533); int64_t _i994 = (x_601).a_; (S8*)_t994->b + hr_ix(_i994, _t994->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:177"); }))).ta_)), ((int64_t)(((*({ hrv *_t995 = &(g533); int64_t _i995 = (x_601).a_; (S8*)_t995->b + hr_ix(_i995, _t995->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:177"); }))).tn_)), out_600));
(void)(({ hrv *_v996 = out_600; uint8_t _x996 = ((uint8_t)46LL); uint8_t *_p996 = (uint8_t*)hr_grow(_v996, 1, sizeof _x996); *_p996 = _x996; _p996; }));
(void)(({ hrv *_v997 = out_600; hsl _s997 = f10_nm(((int64_t)(((*({ hrv *_t998 = &(g534); int64_t _i998 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t999 = &(g533); int64_t _i999 = (x_601).a_; (S8*)_t999->b + hr_ix(_i999, _t999->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:177"); }))).v0_)) + (int64_t)((int64_t)((x_601).c_)))); (S9*)_t998->b + hr_ix(_i998, _t998->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:177"); }))).name_))); hr_append(_v997, _s997.p, _s997.n, sizeof(uint8_t)); }));
return;
 }
if (((k_602) == (((int64_t)9LL)))) { if (((((uint16_t)((uint64_t)(x_601).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v1000 = out_600; hsl _s1000 = hr_str("const ", 6); hr_append(_v1000, _s1000.p, _s1000.n, sizeof(uint8_t)); }));
 }
(void)(f127_ty_name_into(((int64_t)((x_601).a_)), out_600));
(void)(({ hrv *_v1001 = out_600; hsl _s1001 = hr_str("[:]", 3); hr_append(_v1001, _s1001.p, _s1001.n, sizeof(uint8_t)); }));
return;
 }
if (((k_602) == (((int64_t)10LL)))) { if (((((uint16_t)((uint64_t)(x_601).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v1002 = out_600; hsl _s1002 = hr_str("const ", 6); hr_append(_v1002, _s1002.p, _s1002.n, sizeof(uint8_t)); }));
 }
(void)(f127_ty_name_into(((int64_t)((x_601).a_)), out_600));
if ((((x_601).c_) >= (((int32_t)0LL)))) { (void)(({ hrv *_v1003 = out_600; hsl _s1003 = hr_str("&<", 2); hr_append(_v1003, _s1003.p, _s1003.n, sizeof(uint8_t)); }));
(void)(f128_ls_kind_name(((int64_t)((x_601).c_)), out_600));
(void)(({ hrv *_v1004 = out_600; uint8_t _x1004 = ((uint8_t)62LL); uint8_t *_p1004 = (uint8_t*)hr_grow(_v1004, 1, sizeof _x1004); *_p1004 = _x1004; _p1004; }));
if (((((uint16_t)((uint64_t)(x_601).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_v1005 = out_600; uint8_t _x1005 = ((uint8_t)63LL); uint8_t *_p1005 = (uint8_t*)hr_grow(_v1005, 1, sizeof _x1005); *_p1005 = _x1005; _p1005; }));
 }
return;
 }
(void)(({ hrv *_v1006 = out_600; hsl _s1006 = ({ hsl _r1007; if (((((uint16_t)((uint64_t)(x_601).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) { _r1007 = hr_str("\077", 1);  } else { _r1007 = hr_str("&", 1);  } _r1007; }); hr_append(_v1006, _s1006.p, _s1006.n, sizeof(uint8_t)); }));
return;
 }
if (((k_602) == (((int64_t)8LL)))) { (void)(f127_ty_name_into(((int64_t)((x_601).a_)), out_600));
int64_t a_610 = ((int64_t)((x_601).s_)); 
if (((a_610) == (((int64_t)1LL)))) { (void)(({ hrv *_o1008 = out_600; hr_fs(_o1008, hr_str("[", 1)); hr_fi(_o1008, (x_601).b_); hr_fs(_o1008, hr_str("]", 1)); }));
 }
if (((a_610) == (((int64_t)2LL)))) { (void)(({ hrv *_v1009 = out_600; hsl _s1009 = ({ hsl _r1010; if (((((x_601).c_) >= (((int32_t)0LL))) && (((x_601).c_) != (((int32_t)6LL))))) { _r1010 = hr_str("[", 1);  } else { _r1010 = hr_str("[]", 2);  } _r1010; }); hr_append(_v1009, _s1009.p, _s1009.n, sizeof(uint8_t)); }));
if (((((x_601).c_) >= (((int32_t)0LL))) && (((x_601).c_) != (((int32_t)6LL))))) { if ((((x_601).c_) == (((int32_t)8LL)))) { (void)(({ hrv *_v1011 = out_600; hsl _s1011 = hr_str("varint", 6); hr_append(_v1011, _s1011.p, _s1011.n, sizeof(uint8_t)); }));
 } else { (void)(f128_ls_kind_name(((int64_t)((x_601).c_)), out_600));
 }
(void)(({ hrv *_v1012 = out_600; uint8_t _x1012 = ((uint8_t)93LL); uint8_t *_p1012 = (uint8_t*)hr_grow(_v1012, 1, sizeof _x1012); *_p1012 = _x1012; _p1012; }));
 }
 }
if (((a_610) == (((int64_t)3LL)))) { if ((((x_601).b_) >= (((int64_t)0LL)))) { (void)(({ hrv *_o1013 = out_600; hr_fs(_o1013, hr_str("[..", 3)); hr_fi(_o1013, (x_601).b_); hr_fs(_o1013, hr_str("]", 1)); }));
 } else { (void)(({ hrv *_v1014 = out_600; hsl _s1014 = hr_str("[..]", 4); hr_append(_v1014, _s1014.p, _s1014.n, sizeof(uint8_t)); }));
 }
 }
if (((a_610) == (((int64_t)4LL)))) { (void)(({ hrv *_v1015 = out_600; hsl _s1015 = hr_str("[>..]", 5); hr_append(_v1015, _s1015.p, _s1015.n, sizeof(uint8_t)); }));
 }
if (((a_610) == (((int64_t)5LL)))) { (void)(({ hrv *_v1016 = out_600; hsl _s1016 = hr_str("[>..<]", 6); hr_append(_v1016, _s1016.p, _s1016.n, sizeof(uint8_t)); }));
 }
return;
 }
if (((k_602) == (((int64_t)14LL)))) { { int32_t _e1018 = (x_601).n_; for (int32_t _k1018 = 0; _k1018 < _e1018; _k1018++) { int32_t i_611 = (int32_t)_k1018; if (((i_611) > (((int32_t)0LL)))) { (void)(({ hrv *_v1019 = out_600; hsl _s1019 = hr_str(", ", 2); hr_append(_v1019, _s1019.p, _s1019.n, sizeof(uint8_t)); }));
 }
(void)(f127_ty_name_into(((int64_t)((*({ hrv *_t1020 = &(g529); int64_t _i1020 = ((int64_t)((int64_t)((int64_t)((x_601).l_)) + (int64_t)((int64_t)(i_611)))); (int32_t*)_t1020->b + hr_ix(_i1020, _t1020->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:195"); })))), out_600));
 } } _bk1017:; 
return;
 }
(void)(({ hrv *_v1021 = out_600; hsl _s1021 = hr_str("fn", 2); hr_append(_v1021, _s1021.p, _s1021.n, sizeof(uint8_t)); }));
}
static void f128_ls_kind_name(int64_t s_603, hrv* out_604) {
A62 names_605 = ({ A62 _t1022; _t1022.e[0] = hr_str("i8", 2); _t1022.e[1] = hr_str("i16", 3); _t1022.e[2] = hr_str("i32", 3); _t1022.e[3] = hr_str("i64", 3); _t1022.e[4] = hr_str("u8", 2); _t1022.e[5] = hr_str("u16", 3); _t1022.e[6] = hr_str("u32", 3); _t1022.e[7] = hr_str("u64", 3); _t1022; }); 
(void)(({ hrv *_v1023 = out_604; hsl _s1023 = (names_605).e[hr_ix(((int64_t)((int64_t)s_603 & (int64_t)((int64_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:160")]; hr_append(_v1023, _s1023.p, _s1023.n, sizeof(uint8_t)); }));
}
static void f129_targs_into(int64_t l_606, int64_t n_607, hrv* out_608) {
if (((n_607) == (((int64_t)0LL)))) { return;
 }
(void)(({ hrv *_v1025 = out_608; uint8_t _x1025 = ((uint8_t)60LL); uint8_t *_p1025 = (uint8_t*)hr_grow(_v1025, 1, sizeof _x1025); *_p1025 = _x1025; _p1025; }));
{ int64_t _e1027 = n_607; for (int64_t _k1027 = 0; _k1027 < _e1027; _k1027++) { int64_t i_609 = (int64_t)_k1027; if (((i_609) > (((int64_t)0LL)))) { (void)(({ hrv *_v1028 = out_608; hsl _s1028 = hr_str(", ", 2); hr_append(_v1028, _s1028.p, _s1028.n, sizeof(uint8_t)); }));
 }
(void)(f127_ty_name_into(((int64_t)((*({ hrv *_t1029 = &(g529); int64_t _i1029 = ((int64_t)((int64_t)l_606 + (int64_t)i_609)); (int32_t*)_t1029->b + hr_ix(_i1029, _t1029->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:198"); })))), out_608));
 } } _bk1026:; 
(void)(({ hrv *_v1030 = out_608; uint8_t _x1030 = ((uint8_t)62LL); uint8_t *_p1030 = (uint8_t*)hr_grow(_v1030, 1, sizeof _x1030); *_p1030 = _x1030; _p1030; }));
}
static int64_t f130_gb_find(int64_t name_613) {
int64_t i_614 = ((int64_t)((int64_t)(g468).n - (int64_t)((int64_t)1LL))); 
while (((i_614) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1032 = &(g468); int64_t _i1032 = i_614; (S7*)_t1032->b + hr_ix(_i1032, _t1032->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:72"); }))).name_))) == (name_613))) { return ((int64_t)(((*({ hrv *_t1033 = &(g468); int64_t _i1033 = i_614; (S7*)_t1033->b + hr_ix(_i1033, _t1033->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:72"); }))).ty_));
 }
i_614--;
 } _bk1031:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f131_inst_struct(int64_t node_620, hsl args_621) {
{ hrv *_v1035 = &(g531); for (int64_t _k1035 = 0; _k1035 < _v1035->n; _k1035++) { S10 s_622 = ((S10*)_v1035->b)[_k1035]; int64_t i_623 = (int64_t)_k1035; if ((((((int64_t)((s_622).node_))) == (node_620)) && ((((int64_t)((s_622).tn_))) == ((args_621).n)))) { bool same_624 = true; 
{ int64_t _e1037 = (args_621).n; for (int64_t _k1037 = 0; _k1037 < _e1037; _k1037++) { int64_t j_625 = (int64_t)_k1037; if ((((*({ hrv *_t1038 = &(g529); int64_t _i1038 = ((int64_t)((int64_t)((int64_t)((s_622).ta_)) + (int64_t)j_625)); (int32_t*)_t1038->b + hr_ix(_i1038, _t1038->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:142"); }))) != ((*({ hsl _t1039 = args_621; int64_t _i1039 = j_625; (int32_t*)_t1039.p + hr_ix(_i1039, _t1039.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:142"); }))))) { same_624 = false;
 }
 } } _bk1036:; 
if (same_624) { return i_623;
 }
 }
 } } _bk1034:; 
int64_t ta_626 = (g529).n; 
(void)(({ hrv *_v1040 = &(g529); hsl _s1040 = args_621; hr_append(_v1040, _s1040.p, _s1040.n, sizeof(int32_t)); }));
int64_t si_627 = (g531).n; 
(void)(({ hrv *_v1041 = &(g531); S10 _x1041 = ((S10){ .node_ = ((int32_t)(node_620)), .ta_ = ((int32_t)(ta_626)), .tn_ = ((int32_t)((args_621).n)), .f0_ = ((int32_t)((g532).n)), .fnum_ = ((int32_t)0LL), .name_ = ((*({ hrv *_t1042 = &(g679); int64_t _i1042 = node_620; (S4*)_t1042->b + hr_ix(_i1042, _t1042->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:145"); }))).s_, }); S10 *_p1041 = (S10*)hr_grow(_v1041, 1, sizeof _x1041); *_p1041 = _x1041; _p1041; }));
L66 gn_628 = ({ L66 _t1043; memset(&_t1043, 0, sizeof _t1043); _t1043.n = 0; _t1043; }); 
(void)(f132_gen_names(((int64_t)(((*({ hrv *_t1044 = &(g679); int64_t _i1044 = node_620; (S4*)_t1044->b + hr_ix(_i1044, _t1044->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:146"); }))).d_)), (&(gn_628))));
if (((((int64_t)(gn_628).n)) != ((args_621).n))) { (void)(f102_derr(((int64_t)(((*({ hrv *_t1045 = &(g679); int64_t _i1045 = node_620; (S4*)_t1045->b + hr_ix(_i1045, _t1045->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:147"); }))).t_)), hr_str("wrong number of type arguments", 30)));
 }
int64_t g0_632 = (g468).n; 
{ int64_t _e1047 = f45_min(((int64_t)(gn_628).n), (args_621).n); for (int64_t _k1047 = 0; _k1047 < _e1047; _k1047++) { int64_t i_633 = (int64_t)_k1047; (void)(({ hrv *_v1048 = &(g468); S7 _x1048 = ((S7){ .name_ = (*({ L66 *_t1049 = &(gn_628); int64_t _i1049 = i_633; _t1049->e + hr_ix(_i1049, _t1049->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:149"); })), .ty_ = (*({ hsl _t1050 = args_621; int64_t _i1050 = i_633; (int32_t*)_t1050.p + hr_ix(_i1050, _t1050.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:149"); })), }); S7 *_p1048 = (S7*)hr_grow(_v1048, 1, sizeof _x1048); *_p1048 = _x1048; _p1048; }));
 } } _bk1046:; 
int64_t f0_644 = f133_fields_into(node_620, f110_ns_of(node_620)); 
{ int32_t *_t1051 = &(((*({ hrv *_t1052 = &(g531); int64_t _i1052 = si_627; (S10*)_t1052->b + hr_ix(_i1052, _t1052->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:151"); }))).f0_); *_t1051 = ((int32_t)(f0_644)); }
{ int32_t *_t1053 = &(((*({ hrv *_t1054 = &(g531); int64_t _i1054 = si_627; (S10*)_t1054->b + hr_ix(_i1054, _t1054->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:151"); }))).fnum_); *_t1053 = ((int32_t)(((int64_t)((int64_t)(g532).n - (int64_t)f0_644)))); }
(void)(({ hrv *_v1055 = &(g468); int64_t _k1055 = ((int64_t)((int64_t)(g468).n - (int64_t)g0_632)); if (_k1055 < 0 || _k1055 > _v1055->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:152"); _v1055->n -= _k1055; }));
return si_627;
}
static void f132_gen_names(int64_t gl_629, L66* out_630) {
if (((gl_629) >= (((int64_t)0LL)))) { { int32_t _e1057 = ((*({ hrv *_t1058 = &(g679); int64_t _i1058 = gl_629; (S4*)_t1058->b + hr_ix(_i1058, _t1058->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:140"); }))).n_; for (int32_t _k1057 = 0; _k1057 < _e1057; _k1057++) { int32_t i_631 = (int32_t)_k1057; (void)(({ L66 *_v1059 = out_630; int32_t _x1059 = ((*({ hrv *_t1060 = &(g679); int64_t _i1060 = f90_kid(gl_629, ((int64_t)(i_631))); (S4*)_t1060->b + hr_ix(_i1060, _t1060->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:140"); }))).s_; if (_v1059->n >= 16) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:140"); _v1059->e[_v1059->n] = _x1059; &_v1059->e[_v1059->n++]; }));
 } } _bk1056:; 
 }
}
static int64_t f133_fields_into(int64_t node_634, int64_t ns_635) {
L73 buf_636 = ({ L73 _t1061; memset(&_t1061, 0, sizeof _t1061); _t1061.n = 0; _t1061; }); 
{ int32_t _e1063 = ((*({ hrv *_t1064 = &(g679); int64_t _i1064 = node_634; (S4*)_t1064->b + hr_ix(_i1064, _t1064->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:157"); }))).n_; for (int32_t _k1063 = 0; _k1063 < _e1063; _k1063++) { int32_t i_637 = (int32_t)_k1063; int64_t f_638 = f90_kid(node_634, ((int64_t)(i_637))); 
S4 x_639 = (*({ hrv *_t1065 = &(g679); int64_t _i1065 = f_638; (S4*)_t1065->b + hr_ix(_i1065, _t1065->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:159"); })); 
if (((((uint16_t)((uint64_t)(x_639).fl_ & (uint64_t)((uint16_t)4LL)))) != (((uint16_t)0LL)))) { (void)(({ L73 *_v1066 = &(buf_636); S11 _x1066 = ((S11){ .name_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .def_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .fl_ = (x_639).fl_, .padn_ = f134_max((x_639).c_, ((int32_t)0LL)), .off_ = ((int64_t)0LL), }); if (_v1066->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:160"); _v1066->e[_v1066->n] = _x1066; &_v1066->e[_v1066->n++]; }));
continue;
 }
int64_t ft_642 = f113_rtype(((int64_t)((x_639).a_)), ns_635); 
(void)(({ L73 *_v1067 = &(buf_636); S11 _x1067 = ((S11){ .name_ = (x_639).s_, .ty_ = ((int32_t)(ft_642)), .def_ = (x_639).b_, .fl_ = (x_639).fl_, .padn_ = ((int32_t)0LL), .off_ = ((int64_t)0LL), }); if (_v1067->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:162"); _v1067->e[_v1067->n] = _x1067; &_v1067->e[_v1067->n++]; }));
 } } _bk1062:; 
int64_t f0_643 = (g532).n; 
(void)(({ hrv *_v1068 = &(g532); hsl _s1068 = ({ hsl _t1069 = ({ L73 *_t1070 = &(buf_636); (hsl){ (uint8_t*)_t1070->e, _t1070->n }; }); int64_t _l1069 = 0, _h1069 = _t1069.n; if (_l1069 < 0 || _h1069 < _l1069 || _h1069 > _t1069.n) hr_slerr(_l1069, _h1069, _t1069.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:165"); (hsl){ _t1069.p + _l1069 * (int64_t)sizeof(S11), _h1069 - _l1069 }; }); hr_append(_v1068, _s1068.p, _s1068.n, sizeof(S11)); }));
return f0_643;
}
static int32_t f134_max(int32_t a_640, int32_t b_641) {
if (((a_640) < (b_641))) { return b_641;
 }
return a_640;
}
static int64_t f135_t_struct(int64_t si_645) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)5LL))), .a_ = ((int32_t)(si_645)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f136_inst_enum(int64_t node_646, hsl args_647) {
{ hrv *_v1072 = &(g533); for (int64_t _k1072 = 0; _k1072 < _v1072->n; _k1072++) { S8 s_648 = ((S8*)_v1072->b)[_k1072]; int64_t i_649 = (int64_t)_k1072; if ((((((int64_t)((s_648).node_))) == (node_646)) && ((((int64_t)((s_648).tn_))) == ((args_647).n)))) { bool same_650 = true; 
{ int64_t _e1074 = (args_647).n; for (int64_t _k1074 = 0; _k1074 < _e1074; _k1074++) { int64_t j_651 = (int64_t)_k1074; if ((((*({ hrv *_t1075 = &(g529); int64_t _i1075 = ((int64_t)((int64_t)((int64_t)((s_648).ta_)) + (int64_t)j_651)); (int32_t*)_t1075->b + hr_ix(_i1075, _t1075->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:169"); }))) != ((*({ hsl _t1076 = args_647; int64_t _i1076 = j_651; (int32_t*)_t1076.p + hr_ix(_i1076, _t1076.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:169"); }))))) { same_650 = false;
 }
 } } _bk1073:; 
if (same_650) { return i_649;
 }
 }
 } } _bk1071:; 
int64_t ta_652 = (g529).n; 
(void)(({ hrv *_v1077 = &(g529); hsl _s1077 = args_647; hr_append(_v1077, _s1077.p, _s1077.n, sizeof(int32_t)); }));
int64_t ei_653 = (g533).n; 
int64_t nv_654 = ((int64_t)(((*({ hrv *_t1078 = &(g679); int64_t _i1078 = node_646; (S4*)_t1078->b + hr_ix(_i1078, _t1078->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:172"); }))).n_)); 
(void)(({ hrv *_v1079 = &(g533); S8 _x1079 = ((S8){ .node_ = ((int32_t)(node_646)), .ta_ = ((int32_t)(ta_652)), .tn_ = ((int32_t)((args_647).n)), .v0_ = ((int32_t)((g534).n)), .vnum_ = ((int32_t)(nv_654)), .name_ = ((*({ hrv *_t1080 = &(g679); int64_t _i1080 = node_646; (S4*)_t1080->b + hr_ix(_i1080, _t1080->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:173"); }))).s_, }); S8 *_p1079 = (S8*)hr_grow(_v1079, 1, sizeof _x1079); *_p1079 = _x1079; _p1079; }));
int64_t v0_655 = (g534).n; 
{ int64_t _e1082 = nv_654; for (int64_t _k1082 = 0; _k1082 < _e1082; _k1082++) { int64_t i_656 = (int64_t)_k1082; int64_t v_657 = f90_kid(node_646, i_656); 
(void)(({ hrv *_v1083 = &(g534); S9 _x1083 = ((S9){ .name_ = ((*({ hrv *_t1084 = &(g679); int64_t _i1084 = v_657; (S4*)_t1084->b + hr_ix(_i1084, _t1084->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:175"); }))).s_, .f0_ = ((int32_t)0LL), .fnum_ = ((int32_t)0LL), .si_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .size_ = ((int64_t)0LL), .haspay_ = ((((uint16_t)((uint64_t)((*({ hrv *_t1085 = &(g679); int64_t _i1085 = v_657; (S4*)_t1085->b + hr_ix(_i1085, _t1085->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:175"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))), }); S9 *_p1083 = (S9*)hr_grow(_v1083, 1, sizeof _x1083); *_p1083 = _x1083; _p1083; }));
 } } _bk1081:; 
L66 gn_658 = ({ L66 _t1086; memset(&_t1086, 0, sizeof _t1086); _t1086.n = 0; _t1086; }); 
(void)(f132_gen_names(((int64_t)(((*({ hrv *_t1087 = &(g679); int64_t _i1087 = node_646; (S4*)_t1087->b + hr_ix(_i1087, _t1087->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:176"); }))).d_)), (&(gn_658))));
int64_t g0_659 = (g468).n; 
{ int64_t _e1089 = f45_min(((int64_t)(gn_658).n), (args_647).n); for (int64_t _k1089 = 0; _k1089 < _e1089; _k1089++) { int64_t i_660 = (int64_t)_k1089; (void)(({ hrv *_v1090 = &(g468); S7 _x1090 = ((S7){ .name_ = (*({ L66 *_t1091 = &(gn_658); int64_t _i1091 = i_660; _t1091->e + hr_ix(_i1091, _t1091->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:178"); })), .ty_ = (*({ hsl _t1092 = args_647; int64_t _i1092 = i_660; (int32_t*)_t1092.p + hr_ix(_i1092, _t1092.n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:178"); })), }); S7 *_p1090 = (S7*)hr_grow(_v1090, 1, sizeof _x1090); *_p1090 = _x1090; _p1090; }));
 } } _bk1088:; 
int64_t ns_661 = f110_ns_of(node_646); 
{ int64_t _e1094 = nv_654; for (int64_t _k1094 = 0; _k1094 < _e1094; _k1094++) { int64_t i_662 = (int64_t)_k1094; int64_t v_663 = f90_kid(node_646, i_662); 
int64_t si_664 = (g531).n; 
(void)(({ hrv *_v1095 = &(g531); S10 _x1095 = ((S10){ .node_ = ((int32_t)(v_663)), .ta_ = ((int32_t)(ta_652)), .tn_ = ((int32_t)((args_647).n)), .f0_ = ((int32_t)((g532).n)), .fnum_ = ((int32_t)0LL), .name_ = ((*({ hrv *_t1096 = &(g679); int64_t _i1096 = v_663; (S4*)_t1096->b + hr_ix(_i1096, _t1096->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:183"); }))).s_, }); S10 *_p1095 = (S10*)hr_grow(_v1095, 1, sizeof _x1095); *_p1095 = _x1095; _p1095; }));
int64_t f0_665 = f133_fields_into(v_663, ns_661); 
{ int32_t *_t1097 = &(((*({ hrv *_t1098 = &(g531); int64_t _i1098 = si_664; (S10*)_t1098->b + hr_ix(_i1098, _t1098->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:185"); }))).f0_); *_t1097 = ((int32_t)(f0_665)); }
{ int32_t *_t1099 = &(((*({ hrv *_t1100 = &(g531); int64_t _i1100 = si_664; (S10*)_t1100->b + hr_ix(_i1100, _t1100->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:185"); }))).fnum_); *_t1099 = ((int32_t)(((int64_t)((int64_t)(g532).n - (int64_t)f0_665)))); }
{ int32_t *_t1101 = &(((*({ hrv *_t1102 = &(g534); int64_t _i1102 = ((int64_t)((int64_t)v0_655 + (int64_t)i_662)); (S9*)_t1102->b + hr_ix(_i1102, _t1102->n, "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:186"); }))).si_); *_t1101 = ((int32_t)(si_664)); }
 } } _bk1093:; 
(void)(({ hrv *_v1103 = &(g468); int64_t _k1103 = ((int64_t)((int64_t)(g468).n - (int64_t)g0_659)); if (_k1103 < 0 || _k1103 > _v1103->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/decl.amni:188"); _v1103->n -= _k1103; }));
return ei_653;
}
static int64_t f137_t_enum(int64_t ei_666, bool vm_667) {
return f13_tmk(((S1){ .k_ = ((uint8_t)(((uint8_t)6LL))), .fl_ = ({ uint16_t _r1104; if (vm_667) { _r1104 = ((uint16_t)1LL);  } else { _r1104 = ((uint16_t)0LL);  } _r1104; }), .a_ = ((int32_t)(ei_666)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }));
}
static int64_t f138_ck(int64_t n_671, int64_t want_672) {
if (((n_671) < (((int64_t)0LL)))) { return g535;
 }
S4 x_673 = (*({ hrv *_t1105 = &(g679); int64_t _i1105 = n_671; (S4*)_t1105->b + hr_ix(_i1105, _t1105->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:594"); })); 
int64_t k_674 = ((int64_t)((x_673).k_)); 
if (((k_674) == (((int64_t)1LL)))) { if ((((want_672) >= (((int64_t)0LL))) && ((((((*({ hrv *_t1106 = &(g528); int64_t _i1106 = want_672; (S1*)_t1106->b + hr_ix(_i1106, _t1106->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:596"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t1107 = &(g528); int64_t _i1107 = want_672; (S1*)_t1107->b + hr_ix(_i1107, _t1107->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:596"); }))).k_) == (((uint8_t)4LL)))) || ((((*({ hrv *_t1108 = &(g528); int64_t _i1108 = want_672; (S1*)_t1108->b + hr_ix(_i1108, _t1108->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:596"); }))).k_) == (((uint8_t)17LL)))))) { (void)(f139_set_t(n_671, g548));
(void)(f141_conv(n_671, want_672));
return want_672;
 }
return f139_set_t(n_671, g548);
 }
if (((k_674) == (((int64_t)2LL)))) { if ((((want_672) >= (((int64_t)0LL))) && ((((*({ hrv *_t1109 = &(g528); int64_t _i1109 = want_672; (S1*)_t1109->b + hr_ix(_i1109, _t1109->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:597"); }))).k_) == (((uint8_t)4LL))))) { return f139_set_t(n_671, want_672);
 }
return f139_set_t(n_671, g549);
 }
if (((k_674) == (((int64_t)3LL)))) { if ((((want_672) >= (((int64_t)0LL))) && f165_is_byte_arr(want_672))) { return f139_set_t(n_671, want_672);
 }
return f139_set_t(n_671, g550);
 }
if ((((k_674) == (((int64_t)4LL))) || ((k_674) == (((int64_t)5LL))))) { return f139_set_t(n_671, g536);
 }
if (((k_674) == (((int64_t)6LL)))) { if ((((want_672) >= (((int64_t)0LL))) && f166_is_opt(want_672))) { return f139_set_t(n_671, want_672);
 }
return f139_set_t(n_671, g547);
 }
if (((k_674) == (((int64_t)8LL)))) { return f167_ck_id(n_671, want_672);
 }
if (((k_674) == (((int64_t)9LL)))) { int64_t t_862 = f175_ck_bin(n_671, want_672); 
if (((((want_672) >= (((int64_t)0LL))) && f164_is_pending(t_862)) && (((((*({ hrv *_t1110 = &(g528); int64_t _i1110 = want_672; (S1*)_t1110->b + hr_ix(_i1110, _t1110->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:602"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t1111 = &(g528); int64_t _i1111 = want_672; (S1*)_t1111->b + hr_ix(_i1111, _t1111->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:602"); }))).k_) == (((uint8_t)4LL)))))) { (void)(f141_conv(n_671, want_672));
return want_672;
 }
return t_862;
 }
if (((k_674) == (((int64_t)10LL)))) { int64_t t_889 = f180_ck_un(n_671, want_672); 
if (((((want_672) >= (((int64_t)0LL))) && f164_is_pending(t_889)) && (((((*({ hrv *_t1112 = &(g528); int64_t _i1112 = want_672; (S1*)_t1112->b + hr_ix(_i1112, _t1112->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:603"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t1113 = &(g528); int64_t _i1113 = want_672; (S1*)_t1113->b + hr_ix(_i1113, _t1113->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:603"); }))).k_) == (((uint8_t)4LL)))))) { (void)(f141_conv(n_671, want_672));
return want_672;
 }
return t_889;
 }
if (((k_674) == (((int64_t)14LL)))) { return f182_ck_dot(n_671, want_672);
 }
if (((k_674) == (((int64_t)12LL)))) { return f185_ck_idx(n_671, want_672);
 }
if (((k_674) == (((int64_t)13LL)))) { return f186_ck_slice(n_671, want_672);
 }
if (((k_674) == (((int64_t)15LL)))) { return f187_ck_as(n_671, want_672);
 }
if (((k_674) == (((int64_t)16LL)))) { return f188_ck_arr(n_671, want_672);
 }
if (((k_674) == (((int64_t)23LL)))) { return f189_ck_block(n_671, want_672);
 }
if (((k_674) == (((int64_t)24LL)))) { (void)(({ hrv *_v1114 = &(g446); int32_t _x1114 = ({ int32_t _r1115; if ((((want_672) >= (((int64_t)0LL))) && ((want_672) != (g535)))) { _r1115 = ((int32_t)(want_672));  } else { _r1115 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL))));  } _r1115; }); int32_t *_p1114 = (int32_t*)hr_grow(_v1114, 1, sizeof _x1114); *_p1114 = _x1114; _p1114; }));
int64_t bt_1061 = f138_ck(((int64_t)((x_673).a_)), want_672); 
int64_t t_1062 = ((int64_t)(({ hrv *_v1116 = &(g446); if (!_v1116->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:610"); ((int32_t*)_v1116->b)[--_v1116->n]; }))); 
if ((((bt_1061) != (g535)) && (!(f164_is_pending(bt_1061))))) { return f139_set_t(n_671, bt_1061);
 }
if (((t_1062) >= (((int64_t)0LL)))) { (void)(f141_conv(((int64_t)((x_673).a_)), t_1062));
return f139_set_t(n_671, t_1062);
 }
return f139_set_t(n_671, bt_1061);
 }
if (((k_674) == (((int64_t)19LL)))) { return f206_ck_if(n_671, want_672);
 }
if (((k_674) == (((int64_t)25LL)))) { return f208_ck_while(n_671);
 }
if (((k_674) == (((int64_t)26LL)))) { return f209_ck_loop(n_671, want_672);
 }
if (((k_674) == (((int64_t)27LL)))) { return f210_ck_for(n_671);
 }
if (((k_674) == (((int64_t)20LL)))) { return f212_ck_match(n_671, want_672);
 }
if (((k_674) == (((int64_t)28LL)))) { return f213_ck_ret(n_671);
 }
if (((k_674) == (((int64_t)29LL)))) { return f215_ck_break(n_671);
 }
if (((k_674) == (((int64_t)30LL)))) { return f139_set_t(n_671, g535);
 }
if (((k_674) == (((int64_t)11LL)))) { return f216_ck_call(n_671, want_672);
 }
if (((k_674) == (((int64_t)17LL)))) { return f244_ck_slit(n_671, want_672);
 }
if (((k_674) == (((int64_t)31LL)))) { return f139_set_t(n_671, g555);
 }
(void)(f108_cerr(n_671, hr_str("unsupported expression", 22)));
return f139_set_t(n_671, g552);
}
static int64_t f139_set_t(int64_t n_675, int64_t t_676) {
{ int32_t *_t1117 = &((*({ hrv *_t1118 = &(g378); int64_t _i1118 = f140_aix(n_675); (int32_t*)_t1118->b + hr_ix(_i1118, _t1118->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:39"); }))); *_t1117 = ((int32_t)(t_676)); }
return t_676;
}
static int64_t f140_aix(int64_t n_677) {
int64_t i_678 = g384; 
while (((i_678) >= (((int64_t)0LL)))) { S6 f_679 = (*({ hrv *_t1120 = &(g373); int64_t _i1120 = i_678; (S6*)_t1120->b + hr_ix(_i1120, _t1120->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:34"); })); 
if ((((n_677) >= (((int64_t)((f_679).lo_)))) && ((n_677) < (((int64_t)((f_679).hi_)))))) { return ((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((f_679).ab_)) + (int64_t)n_677)) - (int64_t)((int64_t)((f_679).lo_))));
 }
i_678 = ((int64_t)((f_679).par_));
 } _bk1119:; 
S6 g_680 = (*({ hrv *_t1121 = &(g373); int64_t _i1121 = g386; (S6*)_t1121->b + hr_ix(_i1121, _t1121->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:35"); })); 
return ((int64_t)((int64_t)((int64_t)((g_680).ab_)) + (int64_t)n_677));
}
static bool f141_conv(int64_t n_681, int64_t t_682) {
if ((((t_682) < (((int64_t)0LL))) || ((n_681) < (((int64_t)0LL))))) { return true;
 }
int64_t f_684 = f142_at(n_681); 
if (((f_684) < (((int64_t)0LL)))) { return true;
 }
if (((f_684) == (t_682))) { return true;
 }
int64_t fk_685 = ((int64_t)(((*({ hrv *_t1122 = &(g528); int64_t _i1122 = f_684; (S1*)_t1122->b + hr_ix(_i1122, _t1122->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:107"); }))).k_)); 
int64_t tkd_686 = ((int64_t)(((*({ hrv *_t1123 = &(g528); int64_t _i1123 = t_682; (S1*)_t1123->b + hr_ix(_i1123, _t1123->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:108"); }))).k_)); 
if ((((tkd_686) == (((int64_t)0LL))) || ((fk_685) == (((int64_t)0LL))))) { return true;
 }
if ((((((tkd_686) == (((int64_t)10LL))) && ((((*({ hrv *_t1124 = &(g528); int64_t _i1124 = t_682; (S1*)_t1124->b + hr_ix(_i1124, _t1124->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:110"); }))).c_) < (((int32_t)0LL)))) && ((fk_685) != (((int64_t)11LL)))) && ((fk_685) != (((int64_t)10LL))))) { if (((f143_tclass(t_682)) >= (((int64_t)0LL)))) { bool ok_720 = f141_conv(n_681, ((int64_t)(((*({ hrv *_t1125 = &(g528); int64_t _i1125 = t_682; (S1*)_t1125->b + hr_ix(_i1125, _t1125->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:110"); }))).a_))); 
if ((ok_720 && ((f149_cv(n_681)) < (((int64_t)0LL))))) { (void)(f150_set_cv(n_681, t_682));
 }
return ok_720;
 }
 }
if (((((fk_685) == (((int64_t)10LL))) && ((((*({ hrv *_t1126 = &(g528); int64_t _i1126 = f_684; (S1*)_t1126->b + hr_ix(_i1126, _t1126->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:111"); }))).c_) < (((int32_t)0LL)))) && ((tkd_686) != (((int64_t)10LL))))) { if (f151_conv_ok(((int64_t)(((*({ hrv *_t1127 = &(g528); int64_t _i1127 = f_684; (S1*)_t1127->b + hr_ix(_i1127, _t1127->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:111"); }))).a_)), t_682, n_681)) { (void)(f150_set_cv(n_681, t_682));
return true;
 }
 }
if (((fk_685) == (((int64_t)12LL)))) { M78 _t1128 = f156_cval(n_681); int64_t v_754 = _t1128.r0; bool u_755 = _t1128.r1; bool ok_756 = _t1128.r2; 
if (((tkd_686) == (((int64_t)3LL)))) { if ((ok_756 && (!(f159_int_fits(v_754, u_755, t_682))))) { hrv m_765 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1131 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1130 = &(m_765); hr_fs(_o1130, hr_str("constant ", 9)); hr_fi(_o1130, v_754); hr_fs(_o1130, hr_str(" does not fit in ", 17)); hr_fs(_o1130, hr_sl(*hr_tmp(&_t1131, f162_tn(t_682)))); }));
}
(void)(f108_cerr(n_681, hr_sl(m_765)));
return false;
 }
(void)(f163_commit(n_681, t_682));
return true;
 }
if ((((tkd_686) == (((int64_t)4LL))) || ((tkd_686) == (((int64_t)17LL))))) { (void)(f163_commit(n_681, t_682));
return true;
 }
 }
if ((((fk_685) == (((int64_t)13LL))) && ((tkd_686) == (((int64_t)4LL))))) { (void)(f163_commit(n_681, t_682));
return true;
 }
if ((((fk_685) == (((int64_t)18LL))) && (f165_is_byte_arr(t_682) || (((tkd_686) == (((int64_t)10LL))) && f165_is_byte_arr(((int64_t)(((*({ hrv *_t1132 = &(g528); int64_t _i1132 = t_682; (S1*)_t1132->b + hr_ix(_i1132, _t1132->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:118"); }))).a_))))))) { (void)(f163_commit(n_681, ({ int64_t _r1133; if (((tkd_686) == (((int64_t)10LL)))) { _r1133 = ((int64_t)(((*({ hrv *_t1134 = &(g528); int64_t _i1134 = t_682; (S1*)_t1134->b + hr_ix(_i1134, _t1134->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:118"); }))).a_));  } else { _r1133 = t_682;  } _r1133; })));
return true;
 }
if ((((fk_685) == (((int64_t)19LL))) && (((tkd_686) == (((int64_t)8LL))) || ((tkd_686) == (((int64_t)9LL)))))) { (void)(f163_commit(n_681, t_682));
return true;
 }
if (((((fk_685) == (((int64_t)11LL))) && ((tkd_686) == (((int64_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1135 = &(g528); int64_t _i1135 = t_682; (S1*)_t1135->b + hr_ix(_i1135, _t1135->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:120"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { (void)(f163_commit(n_681, t_682));
return true;
 }
if (f151_conv_ok(f_684, t_682, n_681)) { (void)(f150_set_cv(n_681, t_682));
return true;
 }
hrv m_780 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1138 __attribute__((cleanup(hr_rdrop))) = {0}; hrv _t1139 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1137 = &(m_780); hr_fs(_o1137, hr_str("cannot convert ", 15)); hr_fs(_o1137, hr_sl(*hr_tmp(&_t1138, f162_tn(f_684)))); hr_fs(_o1137, hr_str(" to ", 4)); hr_fs(_o1137, hr_sl(*hr_tmp(&_t1139, f162_tn(t_682)))); }));
}
(void)(f108_cerr(n_681, hr_sl(m_780)));
return false;
}
static int64_t f142_at(int64_t n_683) {
return ((int64_t)((*({ hrv *_t1140 = &(g378); int64_t _i1140 = f140_aix(n_683); (int32_t*)_t1140->b + hr_ix(_i1140, _t1140->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:38"); }))));
}
static int64_t f143_tclass(int64_t t_687) {
S1 x_688 = (*({ hrv *_t1141 = &(g528); int64_t _i1141 = t_687; (S1*)_t1141->b + hr_ix(_i1141, _t1141->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:83"); })); 
int64_t k_689 = ((int64_t)((x_688).k_)); 
if (((k_689) == (((int64_t)5LL)))) { (void)(f144_si_layout(((int64_t)((x_688).a_))));
return ((int64_t)(((*({ hrv *_t1142 = &(g531); int64_t _i1142 = (x_688).a_; (S10*)_t1142->b + hr_ix(_i1142, _t1142->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:85"); }))).cls_));
 }
if (((k_689) == (((int64_t)7LL)))) { (void)(f147_ei_layout(((int64_t)((x_688).a_))));
S9 v_717 = (*({ hrv *_t1143 = &(g534); int64_t _i1143 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1144 = &(g533); int64_t _i1144 = (x_688).a_; (S8*)_t1144->b + hr_ix(_i1144, _t1144->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:86"); }))).v0_)) + (int64_t)((int64_t)((x_688).c_)))); (S9*)_t1143->b + hr_ix(_i1143, _t1143->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:86"); })); 
if ((((v_717).si_) >= (((int32_t)0LL)))) { (void)(f144_si_layout(((int64_t)((v_717).si_))));
return ((int64_t)(((*({ hrv *_t1145 = &(g531); int64_t _i1145 = (v_717).si_; (S10*)_t1145->b + hr_ix(_i1145, _t1145->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:86"); }))).cls_));
 }
return ((int64_t)0LL);
 }
if (((k_689) == (((int64_t)6LL)))) { (void)(f147_ei_layout(((int64_t)((x_688).a_))));
if (((((uint16_t)((uint64_t)(x_688).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) { return ((int64_t)0LL);
 }
return ((int64_t)(((*({ hrv *_t1146 = &(g533); int64_t _i1146 = (x_688).a_; (S8*)_t1146->b + hr_ix(_i1146, _t1146->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:87"); }))).cls_));
 }
if (((k_689) == (((int64_t)8LL)))) { int64_t a_718 = ((int64_t)((x_688).s_)); 
if ((((a_718) == (((int64_t)4LL))) || ((a_718) == (((int64_t)5LL))))) { return ((int64_t)2LL);
 }
if (((a_718) == (((int64_t)2LL)))) { return ((int64_t)1LL);
 }
if ((((a_718) == (((int64_t)3LL))) && (((x_688).b_) < (((int64_t)0LL))))) { return ((int64_t)1LL);
 }
int64_t ec_719 = f143_tclass(((int64_t)((x_688).a_))); 
return ({ int64_t _r1147; if (((ec_719) > (((int64_t)0LL)))) { _r1147 = ((int64_t)1LL);  } else { _r1147 = ((int64_t)0LL);  } _r1147; });
 }
if (((k_689) == (((int64_t)17LL)))) { return ((int64_t)1LL);
 }
return ((int64_t)0LL);
}
static void f144_si_layout(int64_t si_690) {
if (((((*({ hrv *_t1148 = &(g531); int64_t _i1148 = si_690; (S10*)_t1148->b + hr_ix(_i1148, _t1148->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:118"); }))).done_) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t1149 = &(((*({ hrv *_t1150 = &(g531); int64_t _i1150 = si_690; (S10*)_t1150->b + hr_ix(_i1150, _t1150->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:119"); }))).done_); *_t1149 = ((uint8_t)1LL); }
int64_t off_691 = ((int64_t)0LL); 
int64_t cls_692 = ((int64_t)0LL); 
bool flat_693 = true; 
{ int32_t _e1152 = ((*({ hrv *_t1153 = &(g531); int64_t _i1153 = si_690; (S10*)_t1153->b + hr_ix(_i1153, _t1153->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:121"); }))).fnum_; for (int32_t _k1152 = 0; _k1152 < _e1152; _k1152++) { int32_t i_694 = (int32_t)_k1152; int64_t fi_695 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1154 = &(g531); int64_t _i1154 = si_690; (S10*)_t1154->b + hr_ix(_i1154, _t1154->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:122"); }))).f0_)) + (int64_t)((int64_t)(i_694)))); 
int64_t ft_696 = ((int64_t)(((*({ hrv *_t1155 = &(g532); int64_t _i1155 = fi_695; (S11*)_t1155->b + hr_ix(_i1155, _t1155->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:123"); }))).ty_)); 
if (((ft_696) < (((int64_t)0LL)))) { { int64_t *_t1156 = &(((*({ hrv *_t1157 = &(g532); int64_t _i1157 = fi_695; (S11*)_t1157->b + hr_ix(_i1157, _t1157->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:124"); }))).off_); *_t1156 = off_691; }
{ int64_t *_t1158 = &(off_691); *_t1158 = ((int64_t)((int64_t)(*_t1158) + (int64_t)((int64_t)(((*({ hrv *_t1159 = &(g532); int64_t _i1159 = fi_695; (S11*)_t1159->b + hr_ix(_i1159, _t1159->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:124"); }))).padn_)))); }
continue;
 }
int64_t c_697 = f143_tclass(ft_696); 
{ int64_t *_t1160 = &(((*({ hrv *_t1161 = &(g532); int64_t _i1161 = fi_695; (S11*)_t1161->b + hr_ix(_i1161, _t1161->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:126"); }))).off_); *_t1160 = ({ int64_t _r1162; if (((cls_692) == (((int64_t)0LL)))) { _r1162 = off_691;  } else { _r1162 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1162; }); }
if (((c_697) > (cls_692))) { cls_692 = c_697;
 }
if (((c_697) == (((int64_t)0LL)))) { { int64_t *_t1163 = &(off_691); *_t1163 = ((int64_t)((int64_t)(*_t1163) + (int64_t)f145_tsize(ft_696))); }
 } else { if (((cls_692) == (((int64_t)0LL)))) { cls_692 = c_697;
 }
 }
if ((!(f148_tflat(ft_696)))) { flat_693 = false;
 }
 } } _bk1151:; 
{ uint8_t *_t1164 = &(((*({ hrv *_t1165 = &(g531); int64_t _i1165 = si_690; (S10*)_t1165->b + hr_ix(_i1165, _t1165->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:131"); }))).cls_); *_t1164 = ((uint8_t)(cls_692)); }
{ bool *_t1166 = &(((*({ hrv *_t1167 = &(g531); int64_t _i1167 = si_690; (S10*)_t1167->b + hr_ix(_i1167, _t1167->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:131"); }))).flat_); *_t1166 = flat_693; }
{ int64_t *_t1168 = &(((*({ hrv *_t1169 = &(g531); int64_t _i1169 = si_690; (S10*)_t1169->b + hr_ix(_i1169, _t1169->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:132"); }))).size_); *_t1168 = ({ int64_t _r1170; if (((cls_692) == (((int64_t)0LL)))) { _r1170 = f103_max(off_691, ((int64_t)1LL));  } else { _r1170 = off_691;  } _r1170; }); }
{ bool *_t1171 = &(((*({ hrv *_t1172 = &(g531); int64_t _i1172 = si_690; (S10*)_t1172->b + hr_ix(_i1172, _t1172->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:133"); }))).zero_); *_t1171 = ((off_691) == (((int64_t)0LL))); }
{ uint8_t *_t1173 = &(((*({ hrv *_t1174 = &(g531); int64_t _i1174 = si_690; (S10*)_t1174->b + hr_ix(_i1174, _t1174->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:134"); }))).done_); *_t1173 = ((uint8_t)2LL); }
}
static int64_t f145_tsize(int64_t t_698) {
S1 x_699 = (*({ hrv *_t1175 = &(g528); int64_t _i1175 = t_698; (S1*)_t1175->b + hr_ix(_i1175, _t1175->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:95"); })); 
int64_t k_700 = ((int64_t)((x_699).k_)); 
if (((k_700) == (((int64_t)2LL)))) { return ((int64_t)1LL);
 }
if (((k_700) == (((int64_t)3LL)))) { return f146_isz(((int64_t)((x_699).s_)));
 }
if (((k_700) == (((int64_t)4LL)))) { return ((int64_t)((x_699).s_));
 }
if (((k_700) == (((int64_t)10LL)))) { if ((((x_699).c_) >= (((int32_t)0LL)))) { return f146_isz(((int64_t)((x_699).c_)));
 }
return ((int64_t)8LL);
 }
if (((k_700) == (((int64_t)9LL)))) { return ((int64_t)16LL);
 }
if (((k_700) == (((int64_t)5LL)))) { (void)(f144_si_layout(((int64_t)((x_699).a_))));
return ((*({ hrv *_t1176 = &(g531); int64_t _i1176 = (x_699).a_; (S10*)_t1176->b + hr_ix(_i1176, _t1176->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:102"); }))).size_;
 }
if (((k_700) == (((int64_t)7LL)))) { (void)(f147_ei_layout(((int64_t)((x_699).a_))));
S9 v_712 = (*({ hrv *_t1177 = &(g534); int64_t _i1177 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1178 = &(g533); int64_t _i1178 = (x_699).a_; (S8*)_t1178->b + hr_ix(_i1178, _t1178->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:103"); }))).v0_)) + (int64_t)((int64_t)((x_699).c_)))); (S9*)_t1177->b + hr_ix(_i1177, _t1177->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:103"); })); 
return (v_712).size_;
 }
if (((k_700) == (((int64_t)6LL)))) { (void)(f147_ei_layout(((int64_t)((x_699).a_))));
return ((*({ hrv *_t1179 = &(g533); int64_t _i1179 = (x_699).a_; (S8*)_t1179->b + hr_ix(_i1179, _t1179->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:104"); }))).size_;
 }
if (((k_700) == (((int64_t)8LL)))) { int64_t a_713 = ((int64_t)((x_699).s_)); 
if (((a_713) == (((int64_t)1LL)))) { return ((int64_t)((int64_t)f103_max((x_699).b_, ((int64_t)1LL)) * (int64_t)f145_tsize(((int64_t)((x_699).a_)))));
 }
if (((a_713) == (((int64_t)3LL)))) { return ((int64_t)((int64_t)f146_isz(((int64_t)((x_699).c_))) + (int64_t)((int64_t)((int64_t)f103_max((x_699).b_, ((int64_t)1LL)) * (int64_t)f145_tsize(((int64_t)((x_699).a_)))))));
 }
 }
return ((int64_t)0LL);
}
static int64_t f146_isz(int64_t s_701) {
return ((int64_t)((((int64_t)1LL)) << ((((int64_t)(((int64_t)((int64_t)s_701 & (int64_t)((int64_t)3LL)))))) & 63)));
}
static void f147_ei_layout(int64_t ei_702) {
if (((((*({ hrv *_t1180 = &(g533); int64_t _i1180 = ei_702; (S8*)_t1180->b + hr_ix(_i1180, _t1180->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:137"); }))).done_) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t1181 = &(((*({ hrv *_t1182 = &(g533); int64_t _i1182 = ei_702; (S8*)_t1182->b + hr_ix(_i1182, _t1182->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:138"); }))).done_); *_t1181 = ((uint8_t)1LL); }
int64_t nv_703 = ((int64_t)(((*({ hrv *_t1183 = &(g533); int64_t _i1183 = ei_702; (S8*)_t1183->b + hr_ix(_i1183, _t1183->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:139"); }))).vnum_)); 
int64_t tz_704 = ({ int64_t _r1184; if (((nv_703) <= (((int64_t)256LL)))) { _r1184 = ((int64_t)1LL);  } else { _r1184 = ((int64_t)2LL);  } _r1184; }); 
{ uint8_t *_t1185 = &(((*({ hrv *_t1186 = &(g533); int64_t _i1186 = ei_702; (S8*)_t1186->b + hr_ix(_i1186, _t1186->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:141"); }))).tagsz_); *_t1185 = ((uint8_t)(tz_704)); }
int64_t mx_705 = ((int64_t)0LL); 
int64_t cls_706 = ((int64_t)0LL); 
bool flat_707 = true; 
{ int64_t _e1188 = nv_703; for (int64_t _k1188 = 0; _k1188 < _e1188; _k1188++) { int64_t i_708 = (int64_t)_k1188; int64_t v_709 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1189 = &(g533); int64_t _i1189 = ei_702; (S8*)_t1189->b + hr_ix(_i1189, _t1189->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:144"); }))).v0_)) + (int64_t)i_708)); 
if (((((*({ hrv *_t1190 = &(g534); int64_t _i1190 = v_709; (S9*)_t1190->b + hr_ix(_i1190, _t1190->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:145"); }))).si_) >= (((int32_t)0LL)))) { int64_t si_710 = ((int64_t)(((*({ hrv *_t1191 = &(g534); int64_t _i1191 = v_709; (S9*)_t1191->b + hr_ix(_i1191, _t1191->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:146"); }))).si_)); 
(void)(f144_si_layout(si_710));
if (((((int64_t)(((*({ hrv *_t1192 = &(g531); int64_t _i1192 = si_710; (S10*)_t1192->b + hr_ix(_i1192, _t1192->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:148"); }))).cls_))) > (cls_706))) { cls_706 = ((int64_t)(((*({ hrv *_t1193 = &(g531); int64_t _i1193 = si_710; (S10*)_t1193->b + hr_ix(_i1193, _t1193->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:148"); }))).cls_));
 }
if ((!(((*({ hrv *_t1194 = &(g531); int64_t _i1194 = si_710; (S10*)_t1194->b + hr_ix(_i1194, _t1194->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:149"); }))).flat_))) { flat_707 = false;
 }
int64_t ps_711 = ({ int64_t _r1195; if (((*({ hrv *_t1196 = &(g531); int64_t _i1196 = si_710; (S10*)_t1196->b + hr_ix(_i1196, _t1196->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:150"); }))).zero_) { _r1195 = ((int64_t)0LL);  } else { _r1195 = ((*({ hrv *_t1197 = &(g531); int64_t _i1197 = si_710; (S10*)_t1197->b + hr_ix(_i1197, _t1197->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:150"); }))).size_;  } _r1195; }); 
{ int64_t *_t1198 = &(((*({ hrv *_t1199 = &(g534); int64_t _i1199 = v_709; (S9*)_t1199->b + hr_ix(_i1199, _t1199->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:151"); }))).size_); *_t1198 = ps_711; }
if (((ps_711) > (mx_705))) { mx_705 = ps_711;
 }
 }
 } } _bk1187:; 
{ uint8_t *_t1200 = &(((*({ hrv *_t1201 = &(g533); int64_t _i1201 = ei_702; (S8*)_t1201->b + hr_ix(_i1201, _t1201->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:155"); }))).cls_); *_t1200 = ((uint8_t)(cls_706)); }
{ bool *_t1202 = &(((*({ hrv *_t1203 = &(g533); int64_t _i1203 = ei_702; (S8*)_t1203->b + hr_ix(_i1203, _t1203->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:155"); }))).flat_); *_t1202 = flat_707; }
{ int64_t *_t1204 = &(((*({ hrv *_t1205 = &(g533); int64_t _i1205 = ei_702; (S8*)_t1205->b + hr_ix(_i1205, _t1205->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:156"); }))).size_); *_t1204 = ((int64_t)((int64_t)((int64_t)(tz_704)) + (int64_t)mx_705)); }
{ uint8_t *_t1206 = &(((*({ hrv *_t1207 = &(g533); int64_t _i1207 = ei_702; (S8*)_t1207->b + hr_ix(_i1207, _t1207->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:157"); }))).done_); *_t1206 = ((uint8_t)2LL); }
}
static bool f148_tflat(int64_t t_714) {
S1 x_715 = (*({ hrv *_t1208 = &(g528); int64_t _i1208 = t_714; (S1*)_t1208->b + hr_ix(_i1208, _t1208->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:109"); })); 
int64_t k_716 = ((int64_t)((x_715).k_)); 
if ((((k_716) == (((int64_t)10LL))) || ((k_716) == (((int64_t)9LL))))) { return false;
 }
if (((k_716) == (((int64_t)5LL)))) { (void)(f144_si_layout(((int64_t)((x_715).a_))));
return ((*({ hrv *_t1209 = &(g531); int64_t _i1209 = (x_715).a_; (S10*)_t1209->b + hr_ix(_i1209, _t1209->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:111"); }))).flat_;
 }
if ((((k_716) == (((int64_t)6LL))) || ((k_716) == (((int64_t)7LL))))) { (void)(f147_ei_layout(((int64_t)((x_715).a_))));
return ((*({ hrv *_t1210 = &(g533); int64_t _i1210 = (x_715).a_; (S8*)_t1210->b + hr_ix(_i1210, _t1210->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:112"); }))).flat_;
 }
if (((k_716) == (((int64_t)8LL)))) { return f148_tflat(((int64_t)((x_715).a_)));
 }
return true;
}
static int64_t f149_cv(int64_t n_721) {
return ((int64_t)((*({ hrv *_t1211 = &(g379); int64_t _i1211 = f140_aix(n_721); (int32_t*)_t1211->b + hr_ix(_i1211, _t1211->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:46"); }))));
}
static void f150_set_cv(int64_t n_722, int64_t t_723) {
{ int32_t *_t1212 = &((*({ hrv *_t1213 = &(g379); int64_t _i1213 = f140_aix(n_722); (int32_t*)_t1213->b + hr_ix(_i1213, _t1213->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:45"); }))); *_t1212 = ((int32_t)(t_723)); }
}
static bool f151_conv_ok(int64_t f_724, int64_t t_725, int64_t n_726) {
if (((f_724) == (t_725))) { return true;
 }
S1 a_727 = (*({ hrv *_t1214 = &(g528); int64_t _i1214 = f_724; (S1*)_t1214->b + hr_ix(_i1214, _t1214->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:127"); })); 
S1 b_728 = (*({ hrv *_t1215 = &(g528); int64_t _i1215 = t_725; (S1*)_t1215->b + hr_ix(_i1215, _t1215->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:127"); })); 
if (f152_widens(f_724, t_725)) { return true;
 }
if ((((((b_728).k_) == (((uint8_t)9LL))) && ((((a_727).k_) == (((uint8_t)8LL))) || (((a_727).k_) == (((uint8_t)9LL))))) && (((a_727).a_) == ((b_728).a_)))) { return true;
 }
if ((((((b_728).k_) == (((uint8_t)9LL))) && (((a_727).k_) == (((uint8_t)18LL)))) && ((((int64_t)((b_728).a_))) == (g541)))) { return true;
 }
if (((((((b_728).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)(b_728).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && (((a_727).k_) == (((uint8_t)10LL)))) && (((a_727).a_) == ((b_728).a_)))) { return true;
 }
if ((((((b_728).k_) == (((uint8_t)10LL))) && (((b_728).c_) < (((int32_t)0LL)))) && ((((int64_t)((b_728).a_))) == (f_724)))) { return true;
 }
if ((((((b_728).k_) == (((uint8_t)6LL))) && (((a_727).k_) == (((uint8_t)7LL)))) && (((a_727).a_) == ((b_728).a_)))) { return true;
 }
if ((((((((b_728).k_) == (((uint8_t)8LL))) && (((a_727).k_) == (((uint8_t)8LL)))) && (((a_727).a_) == ((b_728).a_))) && ((n_726) >= (((int64_t)0LL)))) && f155_is_construct(n_726))) { return true;
 }
if ((((((((b_728).k_) == (((uint8_t)8LL))) && (((a_727).k_) == (((uint8_t)9LL)))) && (((a_727).a_) == ((b_728).a_))) && ((n_726) >= (((int64_t)0LL)))) && f155_is_construct(n_726))) { return true;
 }
return false;
}
static bool f152_widens(int64_t f_729, int64_t t_730) {
if (((f_729) == (t_730))) { return true;
 }
S1 a_731 = (*({ hrv *_t1216 = &(g528); int64_t _i1216 = f_729; (S1*)_t1216->b + hr_ix(_i1216, _t1216->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:74"); })); 
S1 b_732 = (*({ hrv *_t1217 = &(g528); int64_t _i1217 = t_730; (S1*)_t1217->b + hr_ix(_i1217, _t1217->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:74"); })); 
if (((((a_731).k_) == (((uint8_t)3LL))) && (((b_732).k_) == (((uint8_t)3LL))))) { bool fs_734 = f153_is_signed(f_729); 
bool ts_735 = f153_is_signed(t_730); 
if (((fs_734) == (ts_735))) { return ((f154_ibits(t_730)) > (f154_ibits(f_729)));
 }
return (((!(fs_734)) && ts_735) && ((f154_ibits(t_730)) > (f154_ibits(f_729))));
 }
if (((((a_731).k_) == (((uint8_t)3LL))) && (((b_732).k_) == (((uint8_t)4LL))))) { return true;
 }
if (((((a_731).k_) == (((uint8_t)4LL))) && (((b_732).k_) == (((uint8_t)4LL))))) { return (((b_732).s_) > ((a_731).s_));
 }
if (((((a_731).k_) == (((uint8_t)3LL))) && (((b_732).k_) == (((uint8_t)17LL))))) { return (!((((f154_ibits(f_729)) == (((int64_t)64LL))) && (!(f153_is_signed(f_729))))));
 }
if (((((a_731).k_) == (((uint8_t)17LL))) && (((b_732).k_) == (((uint8_t)3LL))))) { return ((t_730) == (g540));
 }
return false;
}
static bool f153_is_signed(int64_t t_733) {
return ((((*({ hrv *_t1218 = &(g528); int64_t _i1218 = t_733; (S1*)_t1218->b + hr_ix(_i1218, _t1218->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:60"); }))).s_) < (((uint8_t)4LL)));
}
static int64_t f154_ibits(int64_t t_736) {
return ((int64_t)((((int64_t)8LL)) << ((((int64_t)(((uint8_t)((uint64_t)((*({ hrv *_t1219 = &(g528); int64_t _i1219 = t_736; (S1*)_t1219->b + hr_ix(_i1219, _t1219->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:61"); }))).s_ & (uint64_t)((uint8_t)3LL)))))) & 63)));
}
static bool f155_is_construct(int64_t n_737) {
int64_t k_738 = ((int64_t)(((*({ hrv *_t1220 = &(g679); int64_t _i1220 = n_737; (S4*)_t1220->b + hr_ix(_i1220, _t1220->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:138"); }))).k_)); 
return ((((k_738) == (((int64_t)11LL))) || ((k_738) == (((int64_t)16LL)))) || ((k_738) == (((int64_t)3LL))));
}
static M78 f156_cval(int64_t n_739) {
S4 x_740 = (*({ hrv *_t1221 = &(g679); int64_t _i1221 = n_739; (S4*)_t1221->b + hr_ix(_i1221, _t1221->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:83"); })); 
int64_t k_741 = ((int64_t)((x_740).k_)); 
if (((k_741) == (((int64_t)1LL)))) { return (M78){ ((*({ hrv *_t1222 = &(g889); int64_t _i1222 = (x_740).t_; (S3*)_t1222->b + hr_ix(_i1222, _t1222->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:84"); }))).v_, ((*({ hrv *_t1223 = &(g889); int64_t _i1223 = (x_740).t_; (S3*)_t1223->b + hr_ix(_i1223, _t1223->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:84"); }))).uns_, true };
 }
if (((k_741) == (((int64_t)10LL)))) { M78 _t1224 = f156_cval(((int64_t)((x_740).a_))); int64_t v_742 = _t1224.r0; bool u_743 = _t1224.r1; bool ok_744 = _t1224.r2; 
if ((!(ok_744))) { return (M78){ ((int64_t)0LL), false, false };
 }
if (((((int64_t)((x_740).op_))) == (((int64_t)22LL)))) { return (M78){ ((int64_t)(0 - (uint64_t)(v_742))), false, true };
 }
if (((((int64_t)((x_740).op_))) == (((int64_t)48LL)))) { return (M78){ ((int64_t)~(v_742)), false, true };
 }
return (M78){ ((int64_t)0LL), false, false };
 }
if ((((k_741) == (((int64_t)8LL))) && ((f157_rk(n_739)) == (((int64_t)6LL))))) { return (M78){ (*({ hrv *_t1225 = &(g414); int64_t _i1225 = f158_rv(n_739); (int64_t*)_t1225->b + hr_ix(_i1225, _t1225->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:86"); })), false, true };
 }
if (((k_741) == (((int64_t)9LL)))) { M78 _t1226 = f156_cval(((int64_t)((x_740).a_))); int64_t a_747 = _t1226.r0; bool ua_748 = _t1226.r1; bool oa_749 = _t1226.r2; 
M78 _t1227 = f156_cval(((int64_t)((x_740).b_))); int64_t b_750 = _t1227.r0; bool ub_751 = _t1227.r1; bool ob_752 = _t1227.r2; 
if (((!(oa_749)) || (!(ob_752)))) { return (M78){ ((int64_t)0LL), false, false };
 }
int64_t o_753 = ((int64_t)((x_740).op_)); 
if (((o_753) == (((int64_t)21LL)))) { return (M78){ ((int64_t)((int64_t)a_747 + (int64_t)b_750)), false, true };
 }
if (((o_753) == (((int64_t)22LL)))) { return (M78){ ((int64_t)((int64_t)a_747 - (int64_t)b_750)), false, true };
 }
if (((o_753) == (((int64_t)23LL)))) { return (M78){ ((int64_t)((int64_t)a_747 * (int64_t)b_750)), false, true };
 }
if (((o_753) == (((int64_t)24LL)))) { if (((b_750) == (((int64_t)0LL)))) { return (M78){ ((int64_t)0LL), false, false };
 }
return (M78){ HR_SDIV(int64_t, a_747, b_750, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:92"), false, true };
 }
if (((o_753) == (((int64_t)25LL)))) { if (((b_750) == (((int64_t)0LL)))) { return (M78){ ((int64_t)0LL), false, false };
 }
return (M78){ HR_SMOD(int64_t, ((int64_t)((int64_t)HR_SMOD(int64_t, a_747, b_750, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:93") + (int64_t)b_750)), b_750, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:93"), false, true };
 }
if (((o_753) == (((int64_t)43LL)))) { return (M78){ ((int64_t)((a_747) << ((b_750) & 63))), false, true };
 }
if (((o_753) == (((int64_t)44LL)))) { return (M78){ ((int64_t)((a_747) >> ((b_750) & 63))), false, true };
 }
if (((o_753) == (((int64_t)49LL)))) { return (M78){ ((int64_t)((int64_t)a_747 & (int64_t)b_750)), false, true };
 }
if (((o_753) == (((int64_t)50LL)))) { return (M78){ ((int64_t)((int64_t)a_747 | (int64_t)b_750)), false, true };
 }
if (((o_753) == (((int64_t)51LL)))) { return (M78){ ((int64_t)((int64_t)a_747 ^ (int64_t)b_750)), false, true };
 }
 }
if ((((k_741) == (((int64_t)19LL))) || ((k_741) == (((int64_t)23LL))))) { return (M78){ ((int64_t)0LL), false, false };
 }
return (M78){ ((int64_t)0LL), false, false };
}
static int64_t f157_rk(int64_t n_745) {
return ((int64_t)((*({ hrv *_t1228 = &(g380); int64_t _i1228 = f140_aix(n_745); (uint8_t*)_t1228->b + hr_ix(_i1228, _t1228->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:41"); }))));
}
static int64_t f158_rv(int64_t n_746) {
return ((int64_t)((*({ hrv *_t1229 = &(g381); int64_t _i1229 = f140_aix(n_746); (int32_t*)_t1229->b + hr_ix(_i1229, _t1229->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:42"); }))));
}
static bool f159_int_fits(int64_t v_757, bool uns_758, int64_t t_759) {
if (((((*({ hrv *_t1230 = &(g528); int64_t _i1230 = t_759; (S1*)_t1230->b + hr_ix(_i1230, _t1230->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:67"); }))).k_) != (((uint8_t)3LL)))) { return false;
 }
if (uns_758) { return ((!(f153_is_signed(t_759))) && ((f154_ibits(t_759)) == (((int64_t)64LL))));
 }
if (((v_757) < (((int64_t)0LL)))) { return (f153_is_signed(t_759) && ((v_757) >= (f160_int_min(t_759))));
 }
return ((((uint64_t)(v_757))) <= (f161_int_max_u(t_759)));
}
static int64_t f160_int_min(int64_t t_760) {
if ((!(f153_is_signed(t_760)))) { return ((int64_t)0LL);
 }
int64_t b_761 = f154_ibits(t_760); 
return ({ int64_t _r1231; if (((b_761) == (((int64_t)64LL)))) { _r1231 = ((int64_t)((int64_t)((int64_t)(0 - (uint64_t)(((int64_t)9223372036854775807LL)))) - (int64_t)((int64_t)1LL)));  } else { _r1231 = ((int64_t)(0 - (uint64_t)(((int64_t)((((int64_t)1LL)) << ((((int64_t)((int64_t)b_761 - (int64_t)((int64_t)1LL)))) & 63))))));  } _r1231; });
}
static uint64_t f161_int_max_u(int64_t t_762) {
int64_t b_763 = f154_ibits(t_762); 
bool sg_764 = f153_is_signed(t_762); 
return ({ uint64_t _r1232; if (((b_763) == (((int64_t)64LL)))) { _r1232 = ({ uint64_t _r1233; if (sg_764) { _r1233 = ((uint64_t)9223372036854775807LL);  } else { _r1233 = ((uint64_t)18446744073709551615ULL);  } _r1233; });  } else { _r1232 = ({ uint64_t _r1234; if (sg_764) { _r1234 = ((uint64_t)((uint64_t)((uint64_t)((((uint64_t)1LL)) << ((((int64_t)((int64_t)b_763 - (int64_t)((int64_t)1LL)))) & 63))) - (uint64_t)((uint64_t)1LL)));  } else { _r1234 = ((uint64_t)((uint64_t)((uint64_t)((((uint64_t)1LL)) << ((b_763) & 63))) - (uint64_t)((uint64_t)1LL)));  } _r1234; });  } _r1232; });
}
static hrv f162_tn(int64_t t_766) {
return f126_ty_name(t_766);
}
static void f163_commit(int64_t n_767, int64_t t_768) {
if (((n_767) < (((int64_t)0LL)))) { return;
 }
S4 x_769 = (*({ hrv *_t1235 = &(g679); int64_t _i1235 = n_767; (S4*)_t1235->b + hr_ix(_i1235, _t1235->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:141"); })); 
int64_t k_770 = ((int64_t)((x_769).k_)); 
int64_t f_771 = f142_at(n_767); 
if ((((f_771) >= (((int64_t)0LL))) && (!(f164_is_pending(f_771))))) { if ((((f_771) != (t_768)) && f151_conv_ok(f_771, t_768, n_767))) { (void)(f150_set_cv(n_767, t_768));
 }
return;
 }
(void)(f139_set_t(n_767, t_768));
if (((k_770) == (((int64_t)10LL)))) { (void)(f163_commit(((int64_t)((x_769).a_)), t_768));
return;
 }
if (((k_770) == (((int64_t)9LL)))) { int64_t o_774 = ((int64_t)((x_769).op_)); 
if ((((o_774) == (((int64_t)43LL))) || ((o_774) == (((int64_t)44LL))))) { (void)(f163_commit(((int64_t)((x_769).a_)), t_768));
return;
 }
if (((f92_binprec(o_774)) >= (((int64_t)5LL)))) { (void)(f163_commit(((int64_t)((x_769).a_)), t_768));
(void)(f163_commit(((int64_t)((x_769).b_)), t_768));
 }
return;
 }
if (((k_770) == (((int64_t)19LL)))) { (void)(f163_commit(((int64_t)((x_769).b_)), t_768));
if ((((x_769).c_) >= (((int32_t)0LL)))) { (void)(f163_commit(((int64_t)((x_769).c_)), t_768));
 }
return;
 }
if (((k_770) == (((int64_t)23LL)))) { if ((((x_769).a_) >= (((int32_t)0LL)))) { (void)(f163_commit(((int64_t)((x_769).a_)), t_768));
 }
return;
 }
if (((k_770) == (((int64_t)24LL)))) { (void)(f163_commit(((int64_t)((x_769).a_)), t_768));
return;
 }
if (((k_770) == (((int64_t)20LL)))) { { int32_t _e1237 = (x_769).n_; for (int32_t _k1237 = 0; _k1237 < _e1237; _k1237++) { int32_t i_775 = (int32_t)_k1237; (void)(f163_commit(((int64_t)(((*({ hrv *_t1238 = &(g679); int64_t _i1238 = f90_kid(n_767, ((int64_t)(i_775))); (S4*)_t1238->b + hr_ix(_i1238, _t1238->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:155"); }))).b_)), t_768));
 } } _bk1236:; 
return;
 }
if (((k_770) == (((int64_t)16LL)))) { int64_t e_776 = ({ int64_t _r1239; if ((((((*({ hrv *_t1240 = &(g528); int64_t _i1240 = t_768; (S1*)_t1240->b + hr_ix(_i1240, _t1240->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:157"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t1241 = &(g528); int64_t _i1241 = t_768; (S1*)_t1241->b + hr_ix(_i1241, _t1241->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:157"); }))).k_) == (((uint8_t)9LL))))) { _r1239 = ((int64_t)(((*({ hrv *_t1242 = &(g528); int64_t _i1242 = t_768; (S1*)_t1242->b + hr_ix(_i1242, _t1242->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:157"); }))).a_));  } else { _r1239 = g552;  } _r1239; }); 
if ((((x_769).a_) >= (((int32_t)0LL)))) { (void)(f141_conv(((int64_t)((x_769).a_)), e_776));
(void)(f141_conv(((int64_t)((x_769).b_)), g540));
 }
{ int32_t _e1244 = (x_769).n_; for (int32_t _k1244 = 0; _k1244 < _e1244; _k1244++) { int32_t i_777 = (int32_t)_k1244; (void)(f141_conv(f90_kid(n_767, ((int64_t)(i_777))), e_776));
 } } _bk1243:; 
if (((((*({ hrv *_t1245 = &(g528); int64_t _i1245 = t_768; (S1*)_t1245->b + hr_ix(_i1245, _t1245->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:160"); }))).k_) == (((uint8_t)9LL)))) { (void)(f139_set_t(n_767, f123_t_arr(e_776, ((int64_t)1LL), f103_max(((int64_t)((x_769).n_)), ((int64_t)1LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f150_set_cv(n_767, t_768));
 }
return;
 }
}
static bool f164_is_pending(int64_t t_772) {
int64_t k_773 = ((int64_t)(((*({ hrv *_t1246 = &(g528); int64_t _i1246 = t_772; (S1*)_t1246->b + hr_ix(_i1246, _t1246->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:65"); }))).k_)); 
return ((((((k_773) == (((int64_t)12LL))) || ((k_773) == (((int64_t)13LL)))) || ((k_773) == (((int64_t)18LL)))) || ((k_773) == (((int64_t)19LL)))) || ((k_773) == (((int64_t)11LL))));
}
static bool f165_is_byte_arr(int64_t t_778) {
uint8_t k_779 = ((*({ hrv *_t1247 = &(g528); int64_t _i1247 = t_778; (S1*)_t1247->b + hr_ix(_i1247, _t1247->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:68"); }))).k_; 
return ((((k_779) == (((uint8_t)8LL))) || ((k_779) == (((uint8_t)9LL)))) && ((((int64_t)(((*({ hrv *_t1248 = &(g528); int64_t _i1248 = t_778; (S1*)_t1248->b + hr_ix(_i1248, _t1248->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:68"); }))).a_))) == (g541)));
}
static bool f166_is_opt(int64_t t_781) {
return (((((*({ hrv *_t1249 = &(g528); int64_t _i1249 = t_781; (S1*)_t1249->b + hr_ix(_i1249, _t1249->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:66"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1250 = &(g528); int64_t _i1250 = t_781; (S1*)_t1250->b + hr_ix(_i1250, _t1250->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:66"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))));
}
static int64_t f167_ck_id(int64_t n_782, int64_t want_783) {
int64_t name_784 = ((int64_t)(((*({ hrv *_t1251 = &(g679); int64_t _i1251 = n_782; (S4*)_t1251->b + hr_ix(_i1251, _t1251->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:280"); }))).s_)); 
int64_t v_790 = f168_find_lv(name_784); 
if (((v_790) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_782, ((int64_t)1LL), v_790));
(void)(f171_note_cap(v_790));
return f139_set_t(n_782, ((int64_t)(((*({ hrv *_t1252 = &(g374); int64_t _i1252 = v_790; (S12*)_t1252->b + hr_ix(_i1252, _t1252->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:282"); }))).ty_)));
 }
int64_t ns_798 = f110_ns_of(n_782); 
int64_t d_799 = f121_lookup_q(name_784, ns_798, ((int64_t)5LL)); 
if (((d_799) >= (((int64_t)0LL)))) { int64_t g_800 = ((int64_t)(((*({ hrv *_t1253 = &(g466); int64_t _i1253 = d_799; (S5*)_t1253->b + hr_ix(_i1253, _t1253->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:286"); }))).node_)); 
int64_t ci_813 = f172_const_of(d_799); 
if (((ci_813) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_782, ((int64_t)6LL), ci_813));
return f139_set_t(n_782, g548);
 }
(void)(f170_set_r(n_782, ((int64_t)2LL), d_799));
return f139_set_t(n_782, f109_global_type(d_799));
 }
d_799 = f121_lookup_q(name_784, ns_798, ((int64_t)4LL));
if (((d_799) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_782, ((int64_t)3LL), d_799));
(void)(f174_set_x(n_782, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f139_set_t(n_782, g555);
 }
hrv m_816 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1255 = &(m_816); hr_fs(_o1255, hr_str("unknown name: ", 14)); hr_fs(_o1255, f10_nm(name_784)); }));
(void)(f108_cerr(n_782, hr_sl(m_816)));
return f139_set_t(n_782, g552);
}
static int64_t f168_find_lv(int64_t name_785) {
int64_t i_786 = ((int64_t)((int64_t)(g375).n - (int64_t)((int64_t)1LL))); 
while (((i_786) >= (((int64_t)0LL)))) { int64_t v_787 = ((int64_t)((*({ hrv *_t1257 = &(g375); int64_t _i1257 = i_786; (int32_t*)_t1257->b + hr_ix(_i1257, _t1257->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:56"); })))); 
if ((((((int64_t)(((*({ hrv *_t1258 = &(g374); int64_t _i1258 = v_787; (S12*)_t1258->b + hr_ix(_i1258, _t1258->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:56"); }))).name_))) == (name_785)) && f169_visible(((int64_t)(((*({ hrv *_t1259 = &(g374); int64_t _i1259 = v_787; (S12*)_t1259->b + hr_ix(_i1259, _t1259->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:56"); }))).own_))))) { return v_787;
 }
i_786--;
 } _bk1256:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f169_visible(int64_t own_788) {
int64_t i_789 = g384; 
while (((i_789) >= (((int64_t)0LL)))) { if (((i_789) == (own_788))) { return true;
 }
i_789 = ((int64_t)(((*({ hrv *_t1261 = &(g373); int64_t _i1261 = i_789; (S6*)_t1261->b + hr_ix(_i1261, _t1261->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:53"); }))).par_));
 } _bk1260:; 
return false;
}
static void f170_set_r(int64_t n_791, int64_t k_792, int64_t v_793) {
int64_t i_794 = f140_aix(n_791); 
{ uint8_t *_t1262 = &((*({ hrv *_t1263 = &(g380); int64_t _i1263 = i_794; (uint8_t*)_t1263->b + hr_ix(_i1263, _t1263->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:40"); }))); *_t1262 = ((uint8_t)(k_792)); }
{ int32_t *_t1264 = &((*({ hrv *_t1265 = &(g381); int64_t _i1265 = i_794; (int32_t*)_t1265->b + hr_ix(_i1265, _t1265->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:40"); }))); *_t1264 = ((int32_t)(v_793)); }
}
static void f171_note_cap(int64_t v_795) {
int64_t c_796 = ((int64_t)(((*({ hrv *_t1266 = &(g374); int64_t _i1266 = v_795; (S12*)_t1266->b + hr_ix(_i1266, _t1266->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:60"); }))).cfn_)); 
if (((c_796) == (g385))) { return;
 }
{ hrv *_v1268 = &(g376); for (int64_t _k1268 = 0; _k1268 < _v1268->n; _k1268++) { S13 x_797 = ((S13*)_v1268->b)[_k1268]; if ((((((int64_t)((x_797).inst_))) == (g385)) && ((((int64_t)((x_797).lv_))) == (v_795)))) { return;
 }
 } } _bk1267:; 
(void)(({ hrv *_v1269 = &(g376); S13 _x1269 = ((S13){ .inst_ = ((int32_t)(g385)), .lv_ = ((int32_t)(v_795)), }); S13 *_p1269 = (S13*)hr_grow(_v1269, 1, sizeof _x1269); *_p1269 = _x1269; _p1269; }));
}
static int64_t f172_const_of(int64_t d_801) {
{ hrv *_v1271 = &(g415); for (int64_t _k1271 = 0; _k1271 < _v1271->n; _k1271++) { int32_t c_802 = ((int32_t*)_v1271->b)[_k1271]; int64_t i_803 = (int64_t)_k1271; if (((((int64_t)(c_802))) == (d_801))) { return i_803;
 }
 } } _bk1270:; 
int64_t g_804 = ((int64_t)(((*({ hrv *_t1272 = &(g466); int64_t _i1272 = d_801; (S5*)_t1272->b + hr_ix(_i1272, _t1272->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:301"); }))).node_)); 
S4 x_805 = (*({ hrv *_t1273 = &(g679); int64_t _i1273 = g_804; (S4*)_t1273->b + hr_ix(_i1273, _t1273->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:302"); })); 
if (((((((uint16_t)((uint64_t)(x_805).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || (((x_805).a_) >= (((int32_t)0LL)))) || (((x_805).b_) < (((int32_t)0LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t iv_806 = f90_kid(((int64_t)((x_805).b_)), ((int64_t)0LL)); 
M55 _t1274 = f118_ceval(iv_806, f110_ns_of(g_804)); int64_t v_807 = _t1274.r0; bool ok_808 = _t1274.r1; 
if ((!(ok_808))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if ((!(f173_all_int(iv_806)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
(void)(({ hrv *_v1275 = &(g415); int32_t _x1275 = ((int32_t)(d_801)); int32_t *_p1275 = (int32_t*)hr_grow(_v1275, 1, sizeof _x1275); *_p1275 = _x1275; _p1275; }));
(void)(({ hrv *_v1276 = &(g414); int64_t _x1276 = v_807; int64_t *_p1276 = (int64_t*)hr_grow(_v1276, 1, sizeof _x1276); *_p1276 = _x1276; _p1276; }));
return ((int64_t)((int64_t)(g415).n - (int64_t)((int64_t)1LL)));
}
static bool f173_all_int(int64_t n_809) {
S4 x_810 = (*({ hrv *_t1277 = &(g679); int64_t _i1277 = n_809; (S4*)_t1277->b + hr_ix(_i1277, _t1277->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:312"); })); 
int64_t k_811 = ((int64_t)((x_810).k_)); 
if (((k_811) == (((int64_t)1LL)))) { return true;
 }
if (((k_811) == (((int64_t)10LL)))) { return f173_all_int(((int64_t)((x_810).a_)));
 }
if (((k_811) == (((int64_t)9LL)))) { return (f173_all_int(((int64_t)((x_810).a_))) && f173_all_int(((int64_t)((x_810).b_))));
 }
if (((k_811) == (((int64_t)8LL)))) { int64_t d_812 = f121_lookup_q(((int64_t)((x_810).s_)), f110_ns_of(n_809), ((int64_t)5LL)); 
if (((d_812) < (((int64_t)0LL)))) { return false;
 }
return ((f172_const_of(d_812)) >= (((int64_t)0LL)));
 }
if (((k_811) == (((int64_t)14LL)))) { return hr_streq(f10_nm(((int64_t)((x_810).s_))), hr_str("len", 3));
 }
return false;
}
static void f174_set_x(int64_t n_814, int64_t v_815) {
{ int32_t *_t1278 = &((*({ hrv *_t1279 = &(g382); int64_t _i1279 = f140_aix(n_814); (int32_t*)_t1279->b + hr_ix(_i1279, _t1279->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:43"); }))); *_t1278 = ((int32_t)(v_815)); }
}
static int64_t f175_ck_bin(int64_t n_817, int64_t want_818) {
S4 x_819 = (*({ hrv *_t1280 = &(g679); int64_t _i1280 = n_817; (S4*)_t1280->b + hr_ix(_i1280, _t1280->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:224"); })); 
int64_t o_820 = ((int64_t)((x_819).op_)); 
int64_t a_821 = ((int64_t)((x_819).a_)); 
int64_t b_822 = ((int64_t)((x_819).b_)); 
if ((((o_820) == (((int64_t)52LL))) || ((o_820) == (((int64_t)53LL))))) { (void)(f138_ck(a_821, g536));
(void)(f141_conv(a_821, g536));
(void)(f138_ck(b_822, g536));
(void)(f141_conv(b_822, g536));
return f139_set_t(n_817, g536);
 }
if ((((o_820) == (((int64_t)19LL))) || ((o_820) == (((int64_t)20LL))))) { (void)(f138_ck(a_821, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
(void)(f138_ck(b_822, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f139_set_t(n_817, g536);
 }
bool cmp_823 = (((((((o_820) == (((int64_t)37LL))) || ((o_820) == (((int64_t)38LL)))) || ((o_820) == (((int64_t)39LL)))) || ((o_820) == (((int64_t)40LL)))) || ((o_820) == (((int64_t)41LL)))) || ((o_820) == (((int64_t)42LL)))); 
int64_t w_824 = ({ int64_t _r1281; if (cmp_823) { _r1281 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1281 = want_818;  } _r1281; }); 
int64_t ta_825 = f138_ck(a_821, w_824); 
int64_t tb_827 = f138_ck(b_822, ({ int64_t _r1282; if (f164_is_pending(ta_825)) { _r1282 = w_824;  } else { _r1282 = f176_deref(ta_825);  } _r1282; })); 
if ((((o_820) == (((int64_t)43LL))) || ((o_820) == (((int64_t)44LL))))) { if (((((*({ hrv *_t1283 = &(g528); int64_t _i1283 = tb_827; (S1*)_t1283->b + hr_ix(_i1283, _t1283->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:233"); }))).k_) == (((uint8_t)12LL)))) { (void)(f141_conv(b_822, g540));
 } else { if (((((*({ hrv *_t1284 = &(g528); int64_t _i1284 = f176_deref(tb_827); (S1*)_t1284->b + hr_ix(_i1284, _t1284->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:233"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(b_822, hr_str("shift count must be an integer", 30)));
 }
 }
int64_t da_828 = f176_deref(ta_825); 
if (((((*({ hrv *_t1285 = &(g528); int64_t _i1285 = da_828; (S1*)_t1285->b + hr_ix(_i1285, _t1285->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:235"); }))).k_) == (((uint8_t)12LL)))) { if ((((want_818) >= (((int64_t)0LL))) && ((((*({ hrv *_t1286 = &(g528); int64_t _i1286 = want_818; (S1*)_t1286->b + hr_ix(_i1286, _t1286->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:235"); }))).k_) == (((uint8_t)3LL))))) { (void)(f141_conv(a_821, want_818));
return f139_set_t(n_817, want_818);
 }
return f139_set_t(n_817, g548);
 }
if (((((*({ hrv *_t1287 = &(g528); int64_t _i1287 = da_828; (S1*)_t1287->b + hr_ix(_i1287, _t1287->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:236"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(a_821, hr_str("shift of a non-integer", 22)));
 }
if (((ta_825) != (da_828))) { (void)(f150_set_cv(a_821, da_828));
 }
return f139_set_t(n_817, da_828);
 }
int64_t da_829 = f176_deref(ta_825); 
int64_t db_830 = f176_deref(tb_827); 
int64_t la_839 = f177_leaf_kind(da_829); 
int64_t lb_840 = f177_leaf_kind(db_830); 
if (((((la_839) >= (((int64_t)4LL))) || ((lb_840) >= (((int64_t)4LL)))) && (!(cmp_823)))) { if (((da_829) == (db_830))) { if (((ta_825) != (da_829))) { (void)(f150_set_cv(a_821, da_829));
 }
if (((tb_827) != (db_830))) { (void)(f150_set_cv(b_822, db_830));
 }
return f139_set_t(n_817, da_829);
 }
if ((((la_839) >= (((int64_t)4LL))) && (((o_820) == (((int64_t)23LL))) || ((o_820) == (((int64_t)24LL)))))) { (void)(f141_conv(b_822, f178_leaf_type(da_829)));
if (((ta_825) != (da_829))) { (void)(f150_set_cv(a_821, da_829));
 }
return f139_set_t(n_817, da_829);
 }
if ((((lb_840) >= (((int64_t)4LL))) && ((o_820) == (((int64_t)23LL))))) { (void)(f141_conv(a_821, f178_leaf_type(db_830)));
if (((tb_827) != (db_830))) { (void)(f150_set_cv(b_822, db_830));
 }
return f139_set_t(n_817, db_830);
 }
if ((((lb_840) >= (((int64_t)4LL))) && ((o_820) == (((int64_t)24LL))))) { (void)(f141_conv(a_821, f178_leaf_type(db_830)));
if (((tb_827) != (db_830))) { (void)(f150_set_cv(b_822, db_830));
 }
return f139_set_t(n_817, db_830);
 }
 }
if ((((((cmp_823 && (((((*({ hrv *_t1288 = &(g528); int64_t _i1288 = da_829; (S1*)_t1288->b + hr_ix(_i1288, _t1288->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:248"); }))).k_) == (((uint8_t)3LL))) && ((((*({ hrv *_t1289 = &(g528); int64_t _i1289 = db_830; (S1*)_t1289->b + hr_ix(_i1289, _t1289->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:248"); }))).k_) == (((uint8_t)3LL))))) && ((f153_is_signed(da_829)) != (f153_is_signed(db_830)))) && (((f154_ibits(da_829)) == (((int64_t)64LL))) || ((f154_ibits(db_830)) == (((int64_t)64LL))))) && (!(f152_widens(da_829, db_830)))) && (!(f152_widens(db_830, da_829))))) { (void)(f174_set_x(n_817, ((int64_t)1LL)));
return f139_set_t(n_817, g536);
 }
if ((cmp_823 && (((o_820) == (((int64_t)37LL))) || ((o_820) == (((int64_t)38LL)))))) { int64_t ka_848 = ((int64_t)(((*({ hrv *_t1290 = &(g528); int64_t _i1290 = da_829; (S1*)_t1290->b + hr_ix(_i1290, _t1290->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:253"); }))).k_)); 
int64_t kb_849 = ((int64_t)(((*({ hrv *_t1291 = &(g528); int64_t _i1291 = db_830; (S1*)_t1291->b + hr_ix(_i1291, _t1291->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:253"); }))).k_)); 
if ((((ka_848) == (((int64_t)11LL))) || ((kb_849) == (((int64_t)11LL))))) { if ((((ka_848) == (((int64_t)11LL))) && ((kb_849) == (((int64_t)11LL))))) { return f139_set_t(n_817, g536);
 }
if (((ka_848) == (((int64_t)11LL)))) { (void)(f139_set_t(a_821, tb_827));
 } else { (void)(f139_set_t(b_822, ta_825));
 }
return f139_set_t(n_817, g536);
 }
if (((((ka_848) == (((int64_t)18LL))) || ((kb_849) == (((int64_t)18LL)))) || (f165_is_byte_arr(da_829) && f165_is_byte_arr(db_830)))) { if (((ka_848) == (((int64_t)18LL)))) { (void)(f139_set_t(a_821, g553));
 }
if (((kb_849) == (((int64_t)18LL)))) { (void)(f139_set_t(b_822, g553));
 }
(void)(f174_set_x(n_817, ((int64_t)2LL)));
return f139_set_t(n_817, g536);
 }
if ((((((((ka_848) == (((int64_t)5LL))) || ((ka_848) == (((int64_t)8LL)))) || ((ka_848) == (((int64_t)6LL)))) || ((ka_848) == (((int64_t)7LL)))) || ((ka_848) == (((int64_t)9LL)))) && ((da_829) == (db_830)))) { (void)(f174_set_x(n_817, ((int64_t)3LL)));
return f139_set_t(n_817, g536);
 }
if (((((ka_848) == (((int64_t)6LL))) && ((kb_849) == (((int64_t)7LL)))) || (((ka_848) == (((int64_t)7LL))) && ((kb_849) == (((int64_t)6LL)))))) { (void)(f174_set_x(n_817, ((int64_t)3LL)));
return f139_set_t(n_817, g536);
 }
if ((((ka_848) == (((int64_t)19LL))) || ((kb_849) == (((int64_t)19LL))))) { if (((ka_848) == (((int64_t)19LL)))) { (void)(f141_conv(a_821, db_830));
 } else { (void)(f141_conv(b_822, da_829));
 }
(void)(f174_set_x(n_817, ((int64_t)3LL)));
return f139_set_t(n_817, g536);
 }
 }
int64_t u_860 = f179_unify(n_817, a_821, b_822); 
if (cmp_823) { if (((((*({ hrv *_t1292 = &(g528); int64_t _i1292 = u_860; (S1*)_t1292->b + hr_ix(_i1292, _t1292->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:261"); }))).k_) == (((uint8_t)12LL)))) { (void)(f141_conv(a_821, g540));
(void)(f141_conv(b_822, g540));
 }
if (((((*({ hrv *_t1293 = &(g528); int64_t _i1293 = u_860; (S1*)_t1293->b + hr_ix(_i1293, _t1293->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:261"); }))).k_) == (((uint8_t)13LL)))) { (void)(f141_conv(a_821, g546));
(void)(f141_conv(b_822, g546));
 }
return f139_set_t(n_817, g536);
 }
int64_t uk_861 = ((int64_t)(((*({ hrv *_t1294 = &(g528); int64_t _i1294 = u_860; (S1*)_t1294->b + hr_ix(_i1294, _t1294->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:262"); }))).k_)); 
if (((((((((o_820) == (((int64_t)49LL))) || ((o_820) == (((int64_t)50LL)))) || ((o_820) == (((int64_t)51LL)))) && ((uk_861) != (((int64_t)3LL)))) && ((uk_861) != (((int64_t)12LL)))) && ((uk_861) != (((int64_t)2LL)))) && ((uk_861) != (((int64_t)0LL))))) { (void)(f108_cerr(n_817, hr_str("bitwise operator on a non-integer", 33)));
 }
if ((((((uk_861) == (((int64_t)2LL))) && ((o_820) != (((int64_t)49LL)))) && ((o_820) != (((int64_t)50LL)))) && ((o_820) != (((int64_t)51LL))))) { (void)(f108_cerr(n_817, hr_str("arithmetic on bool", 18)));
 }
return f139_set_t(n_817, u_860);
}
static int64_t f176_deref(int64_t t_826) {
return ({ int64_t _r1295; if ((((((*({ hrv *_t1296 = &(g528); int64_t _i1296 = t_826; (S1*)_t1296->b + hr_ix(_i1296, _t1296->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:67"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t1297 = &(g528); int64_t _i1297 = t_826; (S1*)_t1297->b + hr_ix(_i1297, _t1297->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:67"); }))).c_) < (((int32_t)0LL))))) { _r1295 = ((int64_t)(((*({ hrv *_t1298 = &(g528); int64_t _i1298 = t_826; (S1*)_t1298->b + hr_ix(_i1298, _t1298->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:67"); }))).a_));  } else { _r1295 = t_826;  } _r1295; });
}
static int64_t f177_leaf_kind(int64_t t_831) {
S1 x_832 = (*({ hrv *_t1299 = &(g528); int64_t _i1299 = t_831; (S1*)_t1299->b + hr_ix(_i1299, _t1299->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:210"); })); 
int64_t k_833 = ((int64_t)((x_832).k_)); 
if (((k_833) == (((int64_t)3LL)))) { return ((int64_t)1LL);
 }
if (((k_833) == (((int64_t)4LL)))) { return ((int64_t)2LL);
 }
if (((k_833) == (((int64_t)5LL)))) { int64_t r_834 = ((int64_t)0LL); 
{ int32_t _e1301 = ((*({ hrv *_t1302 = &(g531); int64_t _i1302 = (x_832).a_; (S10*)_t1302->b + hr_ix(_i1302, _t1302->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:212"); }))).fnum_; for (int32_t _k1301 = 0; _k1301 < _e1301; _k1301++) { int32_t i_835 = (int32_t)_k1301; S11 f_836 = (*({ hrv *_t1303 = &(g532); int64_t _i1303 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1304 = &(g531); int64_t _i1304 = (x_832).a_; (S10*)_t1304->b + hr_ix(_i1304, _t1304->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:212"); }))).f0_)) + (int64_t)((int64_t)(i_835)))); (S11*)_t1303->b + hr_ix(_i1303, _t1303->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:212"); })); 
if ((((f_836).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t l_837 = f177_leaf_kind(((int64_t)((f_836).ty_))); 
if ((((l_837) == (((int64_t)0LL))) || (((r_834) != (((int64_t)0LL))) && ((r_834) != (l_837))))) { return ((int64_t)0LL);
 }
r_834 = l_837;
 } } _bk1300:; 
return ((int64_t)((int64_t)r_834 + (int64_t)((int64_t)4LL)));
 }
if ((((k_833) == (((int64_t)8LL))) && (((x_832).s_) == (((uint8_t)(((uint8_t)1LL))))))) { int64_t l_838 = f177_leaf_kind(((int64_t)((x_832).a_))); 
if (((l_838) == (((int64_t)0LL)))) { return ((int64_t)0LL);
 }
return ((int64_t)((int64_t)((int64_t)((int64_t)l_838 & (int64_t)((int64_t)3LL))) + (int64_t)((int64_t)4LL)));
 }
return ((int64_t)0LL);
}
static int64_t f178_leaf_type(int64_t t_841) {
S1 x_842 = (*({ hrv *_t1305 = &(g528); int64_t _i1305 = t_841; (S1*)_t1305->b + hr_ix(_i1305, _t1305->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:217"); })); 
int64_t k_843 = ((int64_t)((x_842).k_)); 
if ((((k_843) == (((int64_t)3LL))) || ((k_843) == (((int64_t)4LL))))) { return t_841;
 }
if (((k_843) == (((int64_t)5LL)))) { int64_t r_844 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e1307 = ((*({ hrv *_t1308 = &(g531); int64_t _i1308 = (x_842).a_; (S10*)_t1308->b + hr_ix(_i1308, _t1308->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:219"); }))).fnum_; for (int32_t _k1307 = 0; _k1307 < _e1307; _k1307++) { int32_t i_845 = (int32_t)_k1307; S11 f_846 = (*({ hrv *_t1309 = &(g532); int64_t _i1309 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1310 = &(g531); int64_t _i1310 = (x_842).a_; (S10*)_t1310->b + hr_ix(_i1310, _t1310->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:219"); }))).f0_)) + (int64_t)((int64_t)(i_845)))); (S11*)_t1309->b + hr_ix(_i1309, _t1309->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:219"); })); 
if ((((f_846).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t l_847 = f178_leaf_type(((int64_t)((f_846).ty_))); 
if ((((l_847) < (((int64_t)0LL))) || (((r_844) >= (((int64_t)0LL))) && ((r_844) != (l_847))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
r_844 = l_847;
 } } _bk1306:; 
return r_844;
 }
if ((((k_843) == (((int64_t)8LL))) && (((x_842).s_) == (((uint8_t)(((uint8_t)1LL))))))) { return f178_leaf_type(((int64_t)((x_842).a_)));
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f179_unify(int64_t n_850, int64_t a_851, int64_t b_852) {
int64_t ta_853 = f142_at(a_851); 
int64_t tb_854 = f142_at(b_852); 
if ((((ta_853) < (((int64_t)0LL))) || ((tb_854) < (((int64_t)0LL))))) { return g552;
 }
int64_t da_855 = f176_deref(ta_853); 
int64_t db_856 = f176_deref(tb_854); 
int64_t ka_857 = ((int64_t)(((*({ hrv *_t1311 = &(g528); int64_t _i1311 = da_855; (S1*)_t1311->b + hr_ix(_i1311, _t1311->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:189"); }))).k_)); 
int64_t kb_858 = ((int64_t)(((*({ hrv *_t1312 = &(g528); int64_t _i1312 = db_856; (S1*)_t1312->b + hr_ix(_i1312, _t1312->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:189"); }))).k_)); 
if ((((ka_857) == (((int64_t)0LL))) || ((kb_858) == (((int64_t)0LL))))) { return g552;
 }
if ((((ka_857) == (((int64_t)12LL))) && ((kb_858) == (((int64_t)12LL))))) { return g548;
 }
if (((((ka_857) == (((int64_t)12LL))) || ((ka_857) == (((int64_t)13LL)))) && ((kb_858) == (((int64_t)13LL))))) { return g549;
 }
if ((((ka_857) == (((int64_t)13LL))) && ((kb_858) == (((int64_t)12LL))))) { return g549;
 }
if ((((ka_857) == (((int64_t)18LL))) && ((kb_858) == (((int64_t)18LL))))) { (void)(f139_set_t(a_851, g553));
(void)(f139_set_t(b_852, g553));
return g553;
 }
if (((((ka_857) == (((int64_t)18LL))) || ((ka_857) == (((int64_t)19LL)))) || ((ka_857) == (((int64_t)11LL))))) { (void)(f141_conv(a_851, db_856));
return db_856;
 }
if (((((kb_858) == (((int64_t)18LL))) || ((kb_858) == (((int64_t)19LL)))) || ((kb_858) == (((int64_t)11LL))))) { (void)(f141_conv(b_852, da_855));
return da_855;
 }
if (((ka_857) == (((int64_t)12LL)))) { (void)(f141_conv(a_851, db_856));
return db_856;
 }
if (((kb_858) == (((int64_t)12LL)))) { (void)(f141_conv(b_852, da_855));
return da_855;
 }
if (((ka_857) == (((int64_t)13LL)))) { if (((kb_858) == (((int64_t)4LL)))) { (void)(f141_conv(a_851, db_856));
return db_856;
 }
if (((kb_858) == (((int64_t)3LL)))) { return g549;
 }
 }
if (((kb_858) == (((int64_t)13LL)))) { if (((ka_857) == (((int64_t)4LL)))) { (void)(f141_conv(b_852, da_855));
return da_855;
 }
if (((ka_857) == (((int64_t)3LL)))) { return g549;
 }
 }
if (((da_855) == (db_856))) { if (((ta_853) != (da_855))) { (void)(f150_set_cv(a_851, da_855));
 }
if (((tb_854) != (db_856))) { (void)(f150_set_cv(b_852, db_856));
 }
return da_855;
 }
if ((f152_widens(da_855, db_856) && (!((((ka_857) == (((int64_t)4LL))) && ((kb_858) == (((int64_t)3LL)))))))) { (void)(f150_set_cv(a_851, db_856));
if (((tb_854) != (db_856))) { (void)(f150_set_cv(b_852, db_856));
 }
return db_856;
 }
if ((f152_widens(db_856, da_855) && (!((((kb_858) == (((int64_t)4LL))) && ((ka_857) == (((int64_t)3LL)))))))) { (void)(f150_set_cv(b_852, da_855));
if (((ta_853) != (da_855))) { (void)(f150_set_cv(a_851, da_855));
 }
return da_855;
 }
if ((((ka_857) == (((int64_t)3LL))) && ((kb_858) == (((int64_t)4LL))))) { (void)(f150_set_cv(a_851, db_856));
return db_856;
 }
if ((((kb_858) == (((int64_t)3LL))) && ((ka_857) == (((int64_t)4LL))))) { (void)(f150_set_cv(b_852, da_855));
return da_855;
 }
hrv m_859 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1315 __attribute__((cleanup(hr_rdrop))) = {0}; hrv _t1316 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1314 = &(m_859); hr_fs(_o1314, hr_str("operands of types ", 18)); hr_fs(_o1314, hr_sl(*hr_tmp(&_t1315, f162_tn(da_855)))); hr_fs(_o1314, hr_str(" and ", 5)); hr_fs(_o1314, hr_sl(*hr_tmp(&_t1316, f162_tn(db_856)))); hr_fs(_o1314, hr_str(" need a cast to a common type", 29)); }));
}
(void)(f108_cerr(n_850, hr_sl(m_859)));
return g552;
}
static int64_t f180_ck_un(int64_t n_863, int64_t want_864) {
S4 x_865 = (*({ hrv *_t1317 = &(g679); int64_t _i1317 = n_863; (S4*)_t1317->b + hr_ix(_i1317, _t1317->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:268"); })); 
int64_t o_866 = ((int64_t)((x_865).op_)); 
int64_t a_867 = ((int64_t)((x_865).a_)); 
if (((o_866) == (((int64_t)47LL)))) { (void)(f138_ck(a_867, g536));
(void)(f141_conv(a_867, g536));
return f139_set_t(n_863, g536);
 }
if (((o_866) == (((int64_t)49LL)))) { int64_t t_868 = f138_ck(a_867, ({ int64_t _r1318; if ((((want_864) >= (((int64_t)0LL))) && ((((*({ hrv *_t1319 = &(g528); int64_t _i1319 = want_864; (S1*)_t1319->b + hr_ix(_i1319, _t1319->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:271"); }))).k_) == (((uint8_t)10LL))))) { _r1318 = ((int64_t)(((*({ hrv *_t1320 = &(g528); int64_t _i1320 = want_864; (S1*)_t1320->b + hr_ix(_i1320, _t1320->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:271"); }))).a_));  } else { _r1318 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1318; })); 
if (f164_is_pending(t_868)) { (void)(f181_default_t(a_867));
 }
(void)(f174_set_x(n_863, ((int64_t)1LL)));
return f139_set_t(n_863, f142_at(a_867));
 }
int64_t t_887 = f138_ck(a_867, want_864); 
int64_t d_888 = f176_deref(t_887); 
if (((t_887) != (d_888))) { (void)(f150_set_cv(a_867, d_888));
 }
if (((((o_866) == (((int64_t)22LL))) && ((((*({ hrv *_t1321 = &(g528); int64_t _i1321 = d_888; (S1*)_t1321->b + hr_ix(_i1321, _t1321->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:275"); }))).k_) == (((uint8_t)3LL)))) && (!(f153_is_signed(d_888))))) { (void)(f108_cerr(n_863, hr_str("unary - of an unsigned integer", 30)));
 }
return f139_set_t(n_863, d_888);
}
static int64_t f181_default_t(int64_t n_869) {
int64_t t_870 = f142_at(n_869); 
if (((t_870) < (((int64_t)0LL)))) { return g535;
 }
int64_t k_871 = ((int64_t)(((*({ hrv *_t1322 = &(g528); int64_t _i1322 = t_870; (S1*)_t1322->b + hr_ix(_i1322, _t1322->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:167"); }))).k_)); 
if (((k_871) == (((int64_t)12LL)))) { M78 _t1323 = f156_cval(n_869); int64_t v_872 = _t1323.r0; bool u_873 = _t1323.r1; bool ok_874 = _t1323.r2; 
int64_t d_875 = ({ int64_t _r1324; if ((ok_874 && u_873)) { _r1324 = g544;  } else { _r1324 = g540;  } _r1324; }); 
(void)(f163_commit(n_869, d_875));
return d_875;
 }
if (((k_871) == (((int64_t)13LL)))) { (void)(f163_commit(n_869, g546));
return g546;
 }
if (((k_871) == (((int64_t)18LL)))) { (void)(f139_set_t(n_869, g553));
return g553;
 }
if (((k_871) == (((int64_t)19LL)))) { S4 x_876 = (*({ hrv *_t1325 = &(g679); int64_t _i1325 = n_869; (S4*)_t1325->b + hr_ix(_i1325, _t1325->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:172"); })); 
int64_t e_877 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((x_876).a_) >= (((int32_t)0LL)))) { e_877 = f181_default_t(((int64_t)((x_876).a_)));
M78 _t1326 = f156_cval(((int64_t)((x_876).b_))); int64_t cnt_878 = _t1326.r0; bool u0_879 = _t1326.r1; bool ok_880 = _t1326.r2; 
(void)(f141_conv(((int64_t)((x_876).b_)), g540));
int64_t a_881 = f123_t_arr(e_877, ((int64_t)1LL), cnt_878, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f139_set_t(n_869, a_881));
return a_881;
 }
{ int32_t _e1328 = (x_876).n_; for (int32_t _k1328 = 0; _k1328 < _e1328; _k1328++) { int32_t i_882 = (int32_t)_k1328; int64_t c_883 = f90_kid(n_869, ((int64_t)(i_882))); 
int64_t ct_884 = f142_at(c_883); 
if ((!(f164_is_pending(ct_884)))) { e_877 = ct_884;
 }
 } } _bk1327:; 
if ((((e_877) < (((int64_t)0LL))) && (((x_876).n_) > (((int32_t)0LL))))) { e_877 = f181_default_t(f90_kid(n_869, ((int64_t)0LL)));
 }
if (((e_877) < (((int64_t)0LL)))) { (void)(f108_cerr(n_869, hr_str("an empty [] has no element type here", 36)));
return g552;
 }
{ int32_t _e1330 = (x_876).n_; for (int32_t _k1330 = 0; _k1330 < _e1330; _k1330++) { int32_t i_885 = (int32_t)_k1330; (void)(f141_conv(f90_kid(n_869, ((int64_t)(i_885))), e_877));
 } } _bk1329:; 
int64_t a_886 = f123_t_arr(e_877, ((int64_t)1LL), ((int64_t)((x_876).n_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f139_set_t(n_869, a_886));
return a_886;
 }
return t_870;
}
static int64_t f182_ck_dot(int64_t n_890, int64_t want_891) {
S4 x_892 = (*({ hrv *_t1331 = &(g679); int64_t _i1331 = n_890; (S4*)_t1331->b + hr_ix(_i1331, _t1331->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:345"); })); 
int64_t a_893 = ((int64_t)((x_892).a_)); 
int64_t name_894 = ((int64_t)((x_892).s_)); 
if ((((((*({ hrv *_t1332 = &(g679); int64_t _i1332 = a_893; (S4*)_t1332->b + hr_ix(_i1332, _t1332->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:348"); }))).k_) == (((uint8_t)8LL))) && ((f168_find_lv(((int64_t)(((*({ hrv *_t1333 = &(g679); int64_t _i1333 = a_893; (S4*)_t1333->b + hr_ix(_i1333, _t1333->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:348"); }))).s_)))) < (((int64_t)0LL))))) { int64_t ns_895 = f110_ns_of(a_893); 
int64_t de_896 = f121_lookup_q(((int64_t)(((*({ hrv *_t1334 = &(g679); int64_t _i1334 = a_893; (S4*)_t1334->b + hr_ix(_i1334, _t1334->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:350"); }))).s_)), ns_895, ((int64_t)2LL)); 
if ((((de_896) >= (((int64_t)0LL))) && ((f121_lookup_q(((int64_t)(((*({ hrv *_t1335 = &(g679); int64_t _i1335 = a_893; (S4*)_t1335->b + hr_ix(_i1335, _t1335->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:351"); }))).s_)), ns_895, ((int64_t)5LL))) < (((int64_t)0LL))))) { int64_t et_900 = f183_rtype_name_enum(de_896); 
int64_t ei_901 = ((int64_t)(((*({ hrv *_t1336 = &(g528); int64_t _i1336 = et_900; (S1*)_t1336->b + hr_ix(_i1336, _t1336->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:353"); }))).a_)); 
{ int32_t _e1338 = ((*({ hrv *_t1339 = &(g533); int64_t _i1339 = ei_901; (S8*)_t1339->b + hr_ix(_i1339, _t1339->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:354"); }))).vnum_; for (int32_t _k1338 = 0; _k1338 < _e1338; _k1338++) { int32_t i_902 = (int32_t)_k1338; if (((((int64_t)(((*({ hrv *_t1340 = &(g534); int64_t _i1340 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1341 = &(g533); int64_t _i1341 = ei_901; (S8*)_t1341->b + hr_ix(_i1341, _t1341->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:354"); }))).v0_)) + (int64_t)((int64_t)(i_902)))); (S9*)_t1340->b + hr_ix(_i1340, _t1340->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:354"); }))).name_))) == (name_894))) { (void)(f170_set_r(n_890, ((int64_t)7LL), ((int64_t)(i_902))));
return f139_set_t(n_890, et_900);
 }
 } } _bk1337:; 
hrv m_903 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1344 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1343 = &(m_903); hr_fs(_o1343, hr_str("no variant ", 11)); hr_fs(_o1343, f10_nm(name_894)); hr_fs(_o1343, hr_str(" in ", 4)); hr_fs(_o1343, hr_sl(*hr_tmp(&_t1344, f162_tn(et_900)))); }));
}
(void)(f108_cerr(n_890, hr_sl(m_903)));
return f139_set_t(n_890, g552);
 }
 }
int64_t t0_904 = f138_ck(a_893, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t t_905 = t0_904; 
if (((((*({ hrv *_t1345 = &(g528); int64_t _i1345 = t_905; (S1*)_t1345->b + hr_ix(_i1345, _t1345->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:360"); }))).k_) == (((uint8_t)18LL)))) { t_905 = g553;
(void)(f139_set_t(a_893, g553));
 }
if (((((*({ hrv *_t1346 = &(g528); int64_t _i1346 = t_905; (S1*)_t1346->b + hr_ix(_i1346, _t1346->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:361"); }))).k_) == (((uint8_t)19LL)))) { t_905 = f181_default_t(a_893);
 }
int64_t d_906 = f176_deref(t_905); 
int64_t k_907 = ((int64_t)(((*({ hrv *_t1347 = &(g528); int64_t _i1347 = d_906; (S1*)_t1347->b + hr_ix(_i1347, _t1347->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:363"); }))).k_)); 
if (((((k_907) == (((int64_t)8LL))) || ((k_907) == (((int64_t)9LL)))) && hr_streq(f10_nm(name_894), hr_str("len", 3)))) { (void)(f170_set_r(n_890, ((int64_t)8LL), ((int64_t)1LL)));
return f139_set_t(n_890, g540);
 }
if ((((k_907) == (((int64_t)8LL))) && hr_streq(f10_nm(name_894), hr_str("cap", 3)))) { (void)(f170_set_r(n_890, ((int64_t)8LL), ((int64_t)2LL)));
return f139_set_t(n_890, g540);
 }
if (((k_907) == (((int64_t)5LL)))) { int64_t si_908 = ((int64_t)(((*({ hrv *_t1348 = &(g528); int64_t _i1348 = d_906; (S1*)_t1348->b + hr_ix(_i1348, _t1348->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:367"); }))).a_)); 
int64_t fi_912 = f184_sfield(si_908, name_894); 
if (((fi_912) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_890, ((int64_t)5LL), fi_912));
int64_t ft_913 = ((int64_t)(((*({ hrv *_t1349 = &(g532); int64_t _i1349 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1350 = &(g531); int64_t _i1350 = si_908; (S10*)_t1350->b + hr_ix(_i1350, _t1350->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:369"); }))).f0_)) + (int64_t)fi_912)); (S11*)_t1349->b + hr_ix(_i1349, _t1349->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:369"); }))).ty_)); 
return f139_set_t(n_890, ft_913);
 }
 }
if (((k_907) == (((int64_t)7LL)))) { S9 v_914 = (*({ hrv *_t1351 = &(g534); int64_t _i1351 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1352 = &(g533); int64_t _i1352 = ((*({ hrv *_t1353 = &(g528); int64_t _i1353 = d_906; (S1*)_t1353->b + hr_ix(_i1353, _t1353->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:372"); }))).a_; (S8*)_t1352->b + hr_ix(_i1352, _t1352->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:372"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t1354 = &(g528); int64_t _i1354 = d_906; (S1*)_t1354->b + hr_ix(_i1354, _t1354->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:372"); }))).c_)))); (S9*)_t1351->b + hr_ix(_i1351, _t1351->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:372"); })); 
if ((((v_914).si_) >= (((int32_t)0LL)))) { int64_t fi_915 = f184_sfield(((int64_t)((v_914).si_)), name_894); 
if (((fi_915) >= (((int64_t)0LL)))) { (void)(f170_set_r(n_890, ((int64_t)5LL), fi_915));
(void)(f174_set_x(n_890, ((int64_t)((v_914).si_))));
return f139_set_t(n_890, ((int64_t)(((*({ hrv *_t1355 = &(g532); int64_t _i1355 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1356 = &(g531); int64_t _i1356 = (v_914).si_; (S10*)_t1356->b + hr_ix(_i1356, _t1356->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:373"); }))).f0_)) + (int64_t)fi_915)); (S11*)_t1355->b + hr_ix(_i1355, _t1355->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:373"); }))).ty_)));
 }
 }
 }
hrv m_916 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1359 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1358 = &(m_916); hr_fs(_o1358, hr_str("no field ", 9)); hr_fs(_o1358, f10_nm(name_894)); hr_fs(_o1358, hr_str(" in ", 4)); hr_fs(_o1358, hr_sl(*hr_tmp(&_t1359, f162_tn(d_906)))); }));
}
(void)(f108_cerr(n_890, hr_sl(m_916)));
return f139_set_t(n_890, g552);
}
static int64_t f183_rtype_name_enum(int64_t de_897) {
int64_t node_898 = ((int64_t)(((*({ hrv *_t1360 = &(g466); int64_t _i1360 = de_897; (S5*)_t1360->b + hr_ix(_i1360, _t1360->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:378"); }))).node_)); 
L84 none_899 = ({ L84 _t1361; memset(&_t1361, 0, sizeof _t1361); _t1361.n = 0; _t1361; }); 
return f137_t_enum(f136_inst_enum(node_898, ({ hsl _t1362 = ({ L84 *_t1363 = &(none_899); (hsl){ (uint8_t*)_t1363->e, _t1363->n }; }); int64_t _l1362 = 0, _h1362 = _t1362.n; if (_l1362 < 0 || _h1362 < _l1362 || _h1362 > _t1362.n) hr_slerr(_l1362, _h1362, _t1362.n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:378"); (hsl){ _t1362.p + _l1362 * (int64_t)sizeof(int32_t), _h1362 - _l1362 }; })), false);
}
static int64_t f184_sfield(int64_t si_909, int64_t name_910) {
{ int32_t _e1365 = ((*({ hrv *_t1366 = &(g531); int64_t _i1366 = si_909; (S10*)_t1366->b + hr_ix(_i1366, _t1366->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:159"); }))).fnum_; for (int32_t _k1365 = 0; _k1365 < _e1365; _k1365++) { int32_t i_911 = (int32_t)_k1365; if (((((int64_t)(((*({ hrv *_t1367 = &(g532); int64_t _i1367 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1368 = &(g531); int64_t _i1368 = si_909; (S10*)_t1368->b + hr_ix(_i1368, _t1368->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:159"); }))).f0_)) + (int64_t)((int64_t)(i_911)))); (S11*)_t1367->b + hr_ix(_i1367, _t1367->n, "/home/anmire/ai/amni-lang/helium-fix/hc/types.amni:159"); }))).name_))) == (name_910))) { return ((int64_t)(i_911));
 }
 } } _bk1364:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f185_ck_idx(int64_t n_917, int64_t want_918) {
S4 x_919 = (*({ hrv *_t1369 = &(g679); int64_t _i1369 = n_917; (S4*)_t1369->b + hr_ix(_i1369, _t1369->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:380"); })); 
int64_t t_920 = f138_ck(((int64_t)((x_919).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t1370 = &(g528); int64_t _i1370 = t_920; (S1*)_t1370->b + hr_ix(_i1370, _t1370->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:382"); }))).k_) == (((uint8_t)18LL)))) { (void)(f139_set_t(((int64_t)((x_919).a_)), g553));
t_920 = g553;
 }
if (((((*({ hrv *_t1371 = &(g528); int64_t _i1371 = t_920; (S1*)_t1371->b + hr_ix(_i1371, _t1371->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:383"); }))).k_) == (((uint8_t)19LL)))) { t_920 = f181_default_t(((int64_t)((x_919).a_)));
 }
int64_t d_921 = f176_deref(t_920); 
int64_t ti_922 = f138_ck(((int64_t)((x_919).b_)), g540); 
if (((((*({ hrv *_t1372 = &(g528); int64_t _i1372 = ti_922; (S1*)_t1372->b + hr_ix(_i1372, _t1372->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:386"); }))).k_) == (((uint8_t)12LL)))) { (void)(f141_conv(((int64_t)((x_919).b_)), g540));
 } else { int64_t di_923 = f176_deref(ti_922); 
if (((((*({ hrv *_t1373 = &(g528); int64_t _i1373 = di_923; (S1*)_t1373->b + hr_ix(_i1373, _t1373->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:386"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(((int64_t)((x_919).b_)), hr_str("index must be an integer", 24)));
 } else { if (((di_923) != (ti_922))) { (void)(f150_set_cv(((int64_t)((x_919).b_)), di_923));
 }
 }
 }
int64_t k_924 = ((int64_t)(((*({ hrv *_t1374 = &(g528); int64_t _i1374 = d_921; (S1*)_t1374->b + hr_ix(_i1374, _t1374->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:387"); }))).k_)); 
if ((((k_924) == (((int64_t)8LL))) || ((k_924) == (((int64_t)9LL))))) { return f139_set_t(n_917, ((int64_t)(((*({ hrv *_t1375 = &(g528); int64_t _i1375 = d_921; (S1*)_t1375->b + hr_ix(_i1375, _t1375->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:388"); }))).a_)));
 }
hrv m_925 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1378 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1377 = &(m_925); hr_fs(_o1377, hr_str("cannot index ", 13)); hr_fs(_o1377, hr_sl(*hr_tmp(&_t1378, f162_tn(d_921)))); }));
}
(void)(f108_cerr(n_917, hr_sl(m_925)));
return f139_set_t(n_917, g552);
}
static int64_t f186_ck_slice(int64_t n_926, int64_t want_927) {
S4 x_928 = (*({ hrv *_t1379 = &(g679); int64_t _i1379 = n_926; (S4*)_t1379->b + hr_ix(_i1379, _t1379->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:393"); })); 
int64_t t_929 = f138_ck(((int64_t)((x_928).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t1380 = &(g528); int64_t _i1380 = t_929; (S1*)_t1380->b + hr_ix(_i1380, _t1380->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:395"); }))).k_) == (((uint8_t)18LL)))) { (void)(f139_set_t(((int64_t)((x_928).a_)), g553));
t_929 = g553;
 }
if (((((*({ hrv *_t1381 = &(g528); int64_t _i1381 = t_929; (S1*)_t1381->b + hr_ix(_i1381, _t1381->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:396"); }))).k_) == (((uint8_t)19LL)))) { t_929 = f181_default_t(((int64_t)((x_928).a_)));
 }
int64_t d_930 = f176_deref(t_929); 
if ((((x_928).b_) >= (((int32_t)0LL)))) { (void)(f138_ck(((int64_t)((x_928).b_)), g540));
(void)(f141_conv(((int64_t)((x_928).b_)), g540));
 }
if ((((x_928).c_) >= (((int32_t)0LL)))) { (void)(f138_ck(((int64_t)((x_928).c_)), g540));
(void)(f141_conv(((int64_t)((x_928).c_)), g540));
 }
int64_t k_931 = ((int64_t)(((*({ hrv *_t1382 = &(g528); int64_t _i1382 = d_930; (S1*)_t1382->b + hr_ix(_i1382, _t1382->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:400"); }))).k_)); 
if (((k_931) == (((int64_t)8LL)))) { return f139_set_t(n_926, f18_t_slice(((int64_t)(((*({ hrv *_t1383 = &(g528); int64_t _i1383 = d_930; (S1*)_t1383->b + hr_ix(_i1383, _t1383->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:401"); }))).a_)), false));
 }
if (((k_931) == (((int64_t)9LL)))) { return f139_set_t(n_926, d_930);
 }
hrv m_932 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1386 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1385 = &(m_932); hr_fs(_o1385, hr_str("cannot slice ", 13)); hr_fs(_o1385, hr_sl(*hr_tmp(&_t1386, f162_tn(d_930)))); }));
}
(void)(f108_cerr(n_926, hr_sl(m_932)));
return f139_set_t(n_926, g552);
}
static int64_t f187_ck_as(int64_t n_933, int64_t want_934) {
S4 x_935 = (*({ hrv *_t1387 = &(g679); int64_t _i1387 = n_933; (S4*)_t1387->b + hr_ix(_i1387, _t1387->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:407"); })); 
int64_t t_936 = f113_rtype(((int64_t)((x_935).b_)), f110_ns_of(n_933)); 
int64_t f_937 = f138_ck(((int64_t)((x_935).a_)), ({ int64_t _r1388; if ((((((*({ hrv *_t1389 = &(g528); int64_t _i1389 = t_936; (S1*)_t1389->b + hr_ix(_i1389, _t1389->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:409"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t1390 = &(g528); int64_t _i1390 = t_936; (S1*)_t1390->b + hr_ix(_i1390, _t1390->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:409"); }))).k_) == (((uint8_t)4LL))))) { _r1388 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1388 = t_936;  } _r1388; })); 
int64_t df_938 = f176_deref(f_937); 
if ((((((*({ hrv *_t1391 = &(g528); int64_t _i1391 = df_938; (S1*)_t1391->b + hr_ix(_i1391, _t1391->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:411"); }))).k_) == (((uint8_t)12LL))) || ((((*({ hrv *_t1392 = &(g528); int64_t _i1392 = df_938; (S1*)_t1392->b + hr_ix(_i1392, _t1392->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:411"); }))).k_) == (((uint8_t)13LL))))) { (void)(f141_conv(((int64_t)((x_935).a_)), ({ int64_t _r1393; if ((((((*({ hrv *_t1394 = &(g528); int64_t _i1394 = t_936; (S1*)_t1394->b + hr_ix(_i1394, _t1394->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:411"); }))).k_) == (((uint8_t)3LL))) || ((((*({ hrv *_t1395 = &(g528); int64_t _i1395 = t_936; (S1*)_t1395->b + hr_ix(_i1395, _t1395->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:411"); }))).k_) == (((uint8_t)4LL))))) { _r1393 = t_936;  } else { _r1393 = g540;  } _r1393; })));
 } else { if (((df_938) != (f_937))) { (void)(f150_set_cv(((int64_t)((x_935).a_)), df_938));
 }
 }
return f139_set_t(n_933, t_936);
}
static int64_t f188_ck_arr(int64_t n_939, int64_t want_940) {
S4 x_941 = (*({ hrv *_t1396 = &(g679); int64_t _i1396 = n_939; (S4*)_t1396->b + hr_ix(_i1396, _t1396->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:626"); })); 
int64_t e_942 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if ((((want_940) >= (((int64_t)0LL))) && (((((*({ hrv *_t1397 = &(g528); int64_t _i1397 = want_940; (S1*)_t1397->b + hr_ix(_i1397, _t1397->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:628"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t1398 = &(g528); int64_t _i1398 = want_940; (S1*)_t1398->b + hr_ix(_i1398, _t1398->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:628"); }))).k_) == (((uint8_t)9LL)))))) { e_942 = ((int64_t)(((*({ hrv *_t1399 = &(g528); int64_t _i1399 = want_940; (S1*)_t1399->b + hr_ix(_i1399, _t1399->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:628"); }))).a_));
 }
if ((((x_941).c_) >= (((int32_t)0LL)))) { (void)(f138_ck(((int64_t)((x_941).c_)), g540));
(void)(f141_conv(((int64_t)((x_941).c_)), g540));
if (((want_940) >= (((int64_t)0LL)))) { return f139_set_t(n_939, want_940);
 }
return f139_set_t(n_939, g554);
 }
if ((((x_941).a_) >= (((int32_t)0LL)))) { (void)(f138_ck(((int64_t)((x_941).a_)), e_942));
(void)(f138_ck(((int64_t)((x_941).b_)), g540));
if (((e_942) >= (((int64_t)0LL)))) { (void)(f141_conv(((int64_t)((x_941).a_)), e_942));
(void)(f141_conv(((int64_t)((x_941).b_)), g540));
if (((((*({ hrv *_t1400 = &(g528); int64_t _i1400 = want_940; (S1*)_t1400->b + hr_ix(_i1400, _t1400->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:630"); }))).k_) == (((uint8_t)9LL)))) { M78 _t1401 = f156_cval(((int64_t)((x_941).b_))); int64_t cnt_943 = _t1401.r0; bool u0_944 = _t1401.r1; bool ok_945 = _t1401.r2; 
(void)(f139_set_t(n_939, f123_t_arr(e_942, ((int64_t)1LL), cnt_943, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f150_set_cv(n_939, want_940));
return want_940;
 }
return f139_set_t(n_939, want_940);
 }
return f139_set_t(n_939, g554);
 }
{ int32_t _e1403 = (x_941).n_; for (int32_t _k1403 = 0; _k1403 < _e1403; _k1403++) { int32_t i_946 = (int32_t)_k1403; (void)(f138_ck(f90_kid(n_939, ((int64_t)(i_946))), e_942));
 } } _bk1402:; 
if (((e_942) >= (((int64_t)0LL)))) { { int32_t _e1405 = (x_941).n_; for (int32_t _k1405 = 0; _k1405 < _e1405; _k1405++) { int32_t i_947 = (int32_t)_k1405; (void)(f141_conv(f90_kid(n_939, ((int64_t)(i_947))), e_942));
 } } _bk1404:; 
if (((((*({ hrv *_t1406 = &(g528); int64_t _i1406 = want_940; (S1*)_t1406->b + hr_ix(_i1406, _t1406->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:634"); }))).k_) == (((uint8_t)9LL)))) { (void)(f139_set_t(n_939, f123_t_arr(e_942, ((int64_t)1LL), f103_max(((int64_t)((x_941).n_)), ((int64_t)1LL)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
(void)(f150_set_cv(n_939, want_940));
return want_940;
 }
return f139_set_t(n_939, want_940);
 }
return f139_set_t(n_939, g554);
}
static int64_t f189_ck_block(int64_t n_948, int64_t want_949) {
S4 x_950 = (*({ hrv *_t1407 = &(g679); int64_t _i1407 = n_948; (S4*)_t1407->b + hr_ix(_i1407, _t1407->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:416"); })); 
int64_t m_951 = (g375).n; 
{ int32_t _e1409 = (x_950).n_; for (int32_t _k1409 = 0; _k1409 < _e1409; _k1409++) { int32_t i_952 = (int32_t)_k1409; (void)(f190_cstmt(f90_kid(n_948, ((int64_t)(i_952)))));
 } } _bk1408:; 
int64_t t_1060 = g535; 
if ((((x_950).a_) >= (((int32_t)0LL)))) { t_1060 = f138_ck(((int64_t)((x_950).a_)), want_949);
if ((((((want_949) >= (((int64_t)0LL))) && ((t_1060) != (g535))) && (!(f164_is_pending(t_1060)))) && ((want_949) != (g535)))) {  }
 }
(void)(({ hrv *_v1410 = &(g375); int64_t _k1410 = ((int64_t)((int64_t)(g375).n - (int64_t)m_951)); if (_k1410 < 0 || _k1410 > _v1410->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:421"); _v1410->n -= _k1410; }));
return f139_set_t(n_948, t_1060);
}
static void f190_cstmt(int64_t n_953) {
S4 x_954 = (*({ hrv *_t1411 = &(g679); int64_t _i1411 = n_953; (S4*)_t1411->b + hr_ix(_i1411, _t1411->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:640"); })); 
int64_t k_955 = ((int64_t)((x_954).k_)); 
if (((k_955) == (((int64_t)33LL)))) { (void)(f191_ck_vdecl(n_953));
return;
 }
if (((k_955) == (((int64_t)34LL)))) { (void)(f195_ck_assign(n_953));
return;
 }
if (((k_955) == (((int64_t)35LL)))) { int64_t t_998 = f138_ck(((int64_t)((x_954).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t1412 = &(g528); int64_t _i1412 = f176_deref(t_998); (S1*)_t1412->b + hr_ix(_i1412, _t1412->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:644"); }))).k_) != (((uint8_t)3LL)))) { (void)(f108_cerr(n_953, hr_str("++/-- needs an integer", 22)));
 }
return;
 }
if (((k_955) == (((int64_t)50LL)))) { (void)(f196_decl_nested(n_953));
return;
 }
int64_t t_1059 = f138_ck(n_953, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f164_is_pending(t_1059)) { (void)(f181_default_t(n_953));
 }
}
static void f191_ck_vdecl(int64_t n_956) {
S4 x_957 = (*({ hrv *_t1413 = &(g679); int64_t _i1413 = n_956; (S4*)_t1413->b + hr_ix(_i1413, _t1413->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:651"); })); 
int64_t fl_958 = ((int64_t)((x_957).fl_)); 
int64_t ns_959 = f110_ns_of(n_956); 
bool byref_960 = ((((int64_t)((int64_t)fl_958 & (int64_t)((int64_t)4LL)))) != (((int64_t)0LL))); 
int64_t dt_961 = ({ int64_t _r1414; if ((((x_957).a_) >= (((int32_t)0LL)))) { _r1414 = f113_rtype(((int64_t)((x_957).a_)), ns_959);  } else { _r1414 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1414; }); 
int64_t lf_962 = ((int64_t)((int64_t)((int64_t)((int64_t)({ int64_t _r1415; if (((((int64_t)((int64_t)fl_958 & (int64_t)((int64_t)1LL)))) != (((int64_t)0LL)))) { _r1415 = ((int64_t)1LL);  } else { _r1415 = ((int64_t)0LL);  } _r1415; }) | (int64_t)({ int64_t _r1416; if (((((int64_t)((int64_t)fl_958 & (int64_t)((int64_t)2LL)))) != (((int64_t)0LL)))) { _r1416 = ((int64_t)2LL);  } else { _r1416 = ((int64_t)0LL);  } _r1416; }))) | (int64_t)({ int64_t _r1417; if (byref_960) { _r1417 = ((int64_t)8LL);  } else { _r1417 = ((int64_t)0LL);  } _r1417; }))); 
if ((((x_957).n_) > (((int32_t)1LL)))) { if ((((x_957).b_) < (((int32_t)0LL)))) { (void)(f108_cerr(n_956, hr_str("several names need a call's results", 35)));
return;
 }
int64_t init_963 = f90_kid(((int64_t)((x_957).b_)), ((int64_t)0LL)); 
int64_t t_964 = f138_ck(init_963, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t1418 = &(g528); int64_t _i1418 = t_964; (S1*)_t1418->b + hr_ix(_i1418, _t1418->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:661"); }))).k_) != (((uint8_t)14LL)))) { if (((((int64_t)(((*({ hrv *_t1419 = &(g679); int64_t _i1419 = (x_957).b_; (S4*)_t1419->b + hr_ix(_i1419, _t1419->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:661"); }))).n_))) == (((int64_t)((x_957).n_))))) { { int32_t _e1421 = (x_957).n_; for (int32_t _k1421 = ((int32_t)1LL); _k1421 < _e1421; _k1421++) { int32_t i_965 = (int32_t)_k1421; int64_t iv_966 = f90_kid(((int64_t)((x_957).b_)), ((int64_t)(i_965))); 
(void)(f138_ck(iv_966, dt_961));
if (((dt_961) >= (((int64_t)0LL)))) { (void)(f141_conv(iv_966, dt_961));
 } else { (void)(f181_default_t(iv_966));
 }
 } } _bk1420:; 
if (((dt_961) >= (((int64_t)0LL)))) { (void)(f141_conv(init_963, dt_961));
 } else { (void)(f181_default_t(init_963));
 }
{ int32_t _e1423 = (x_957).n_; for (int32_t _k1423 = 0; _k1423 < _e1423; _k1423++) { int32_t i_967 = (int32_t)_k1423; int64_t iv_968 = f90_kid(((int64_t)((x_957).b_)), ((int64_t)(i_967))); 
int64_t v_975 = f193_add_lv(((int64_t)((*({ hrv *_t1424 = &(g680); int64_t _i1424 = ((int64_t)((int64_t)((int64_t)((x_957).l_)) + (int64_t)((int64_t)(i_967)))); (int32_t*)_t1424->b + hr_ix(_i1424, _t1424->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:661"); })))), ({ int64_t _r1425; if (((dt_961) >= (((int64_t)0LL)))) { _r1425 = dt_961;  } else { _r1425 = f192_fin_t(iv_968);  } _r1425; }), lf_962, n_956); 
if (((i_967) == (((int32_t)0LL)))) { (void)(f170_set_r(n_956, ((int64_t)1LL), v_975));
 }
 } } _bk1422:; 
(void)(f174_set_x(n_956, ((int64_t)1LL)));
return;
 }
(void)(f108_cerr(n_956, hr_str("several names need a call with as many results", 46)));
return;
 }
if (((((*({ hrv *_t1426 = &(g528); int64_t _i1426 = t_964; (S1*)_t1426->b + hr_ix(_i1426, _t1426->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:662"); }))).n_) != ((x_957).n_))) { (void)(f108_cerr(n_956, hr_str("result count does not match the names", 37)));
 }
{ int32_t _e1428 = (x_957).n_; for (int32_t _k1428 = 0; _k1428 < _e1428; _k1428++) { int32_t i_976 = (int32_t)_k1428; int64_t et_977 = ({ int64_t _r1429; if (((((int64_t)(i_976))) < (((int64_t)(((*({ hrv *_t1430 = &(g528); int64_t _i1430 = t_964; (S1*)_t1430->b + hr_ix(_i1430, _t1430->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:663"); }))).n_))))) { _r1429 = ((int64_t)((*({ hrv *_t1431 = &(g529); int64_t _i1431 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1432 = &(g528); int64_t _i1432 = t_964; (S1*)_t1432->b + hr_ix(_i1432, _t1432->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:663"); }))).l_)) + (int64_t)((int64_t)(i_976)))); (int32_t*)_t1431->b + hr_ix(_i1431, _t1431->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:663"); }))));  } else { _r1429 = g552;  } _r1429; }); 
int64_t v_978 = f193_add_lv(((int64_t)((*({ hrv *_t1433 = &(g680); int64_t _i1433 = ((int64_t)((int64_t)((int64_t)((x_957).l_)) + (int64_t)((int64_t)(i_976)))); (int32_t*)_t1433->b + hr_ix(_i1433, _t1433->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:663"); })))), et_977, lf_962, n_956); 
if (((i_976) == (((int32_t)0LL)))) { (void)(f170_set_r(n_956, ((int64_t)1LL), v_978));
 }
 } } _bk1427:; 
return;
 }
int64_t t_979 = dt_961; 
if ((((x_957).b_) >= (((int32_t)0LL)))) { int64_t init_980 = f90_kid(((int64_t)((x_957).b_)), ((int64_t)0LL)); 
int64_t it_981 = f138_ck(init_980, dt_961); 
if (((dt_961) >= (((int64_t)0LL)))) { if (byref_960) { if ((!(((((*({ hrv *_t1434 = &(g528); int64_t _i1434 = dt_961; (S1*)_t1434->b + hr_ix(_i1434, _t1434->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:670"); }))).k_) == (((uint8_t)10LL)))))) { (void)(f141_conv(init_980, dt_961));
 }
 } else { (void)(f141_conv(init_980, dt_961));
 }
 } else { t_979 = f181_default_t(init_980);
if (((((*({ hrv *_t1435 = &(g528); int64_t _i1435 = t_979; (S1*)_t1435->b + hr_ix(_i1435, _t1435->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:673"); }))).k_) == (((uint8_t)14LL)))) { t_979 = ((int64_t)((*({ hrv *_t1436 = &(g529); int64_t _i1436 = ((*({ hrv *_t1437 = &(g528); int64_t _i1437 = t_979; (S1*)_t1437->b + hr_ix(_i1437, _t1437->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:673"); }))).l_; (int32_t*)_t1436->b + hr_ix(_i1436, _t1436->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:673"); }))));
 }
if ((byref_960 || (((((*({ hrv *_t1438 = &(g679); int64_t _i1438 = init_980; (S4*)_t1438->b + hr_ix(_i1438, _t1438->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:674"); }))).k_) == (((uint8_t)10LL))) && ((((int64_t)(((*({ hrv *_t1439 = &(g679); int64_t _i1439 = init_980; (S4*)_t1439->b + hr_ix(_i1439, _t1439->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:674"); }))).op_))) == (((int64_t)49LL)))))) { if (((((*({ hrv *_t1440 = &(g528); int64_t _i1440 = t_979; (S1*)_t1440->b + hr_ix(_i1440, _t1440->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:674"); }))).k_) != (((uint8_t)10LL)))) { t_979 = f117_t_ref(t_979, ((int64_t)0LL));
 }
 } else { if ((((((((*({ hrv *_t1441 = &(g528); int64_t _i1441 = t_979; (S1*)_t1441->b + hr_ix(_i1441, _t1441->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:675"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t1442 = &(g528); int64_t _i1442 = t_979; (S1*)_t1442->b + hr_ix(_i1442, _t1442->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:675"); }))).c_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1443 = &(g528); int64_t _i1443 = t_979; (S1*)_t1443->b + hr_ix(_i1443, _t1443->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:675"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))) && f194_is_fixed(((int64_t)(((*({ hrv *_t1444 = &(g528); int64_t _i1444 = t_979; (S1*)_t1444->b + hr_ix(_i1444, _t1444->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:675"); }))).a_))))) { t_979 = ((int64_t)(((*({ hrv *_t1445 = &(g528); int64_t _i1445 = t_979; (S1*)_t1445->b + hr_ix(_i1445, _t1445->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:675"); }))).a_));
(void)(f150_set_cv(init_980, t_979));
 }
 }
 }
 } else { if (((t_979) < (((int64_t)0LL)))) { (void)(f108_cerr(n_956, hr_str("a declaration needs a type or an initializer", 44)));
t_979 = g552;
 }
 }
if ((byref_960 && ((((*({ hrv *_t1446 = &(g528); int64_t _i1446 = t_979; (S1*)_t1446->b + hr_ix(_i1446, _t1446->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:680"); }))).k_) != (((uint8_t)10LL))))) { t_979 = f117_t_ref(t_979, ((int64_t)0LL));
 }
int64_t v_983 = f193_add_lv(((int64_t)((*({ hrv *_t1447 = &(g680); int64_t _i1447 = (x_957).l_; (int32_t*)_t1447->b + hr_ix(_i1447, _t1447->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:681"); })))), t_979, lf_962, n_956); 
(void)(f170_set_r(n_956, ((int64_t)1LL), v_983));
}
static int64_t f192_fin_t(int64_t n_969) {
int64_t c_970 = f149_cv(n_969); 
return ({ int64_t _r1448; if (((c_970) >= (((int64_t)0LL)))) { _r1448 = c_970;  } else { _r1448 = f142_at(n_969);  } _r1448; });
}
static int64_t f193_add_lv(int64_t name_971, int64_t t_972, int64_t fl_973, int64_t node_974) {
(void)(({ hrv *_v1449 = &(g374); S12 _x1449 = ((S12){ .name_ = ((int32_t)(name_971)), .ty_ = ((int32_t)(t_972)), .fl_ = ((uint16_t)(fl_973)), .cfn_ = ((int32_t)(g385)), .own_ = ((int32_t)(g384)), .node_ = ((int32_t)(node_974)), .cnt_ = ((int32_t)0LL), }); S12 *_p1449 = (S12*)hr_grow(_v1449, 1, sizeof _x1449); *_p1449 = _x1449; _p1449; }));
(void)(({ hrv *_v1450 = &(g375); int32_t _x1450 = ((int32_t)(((int64_t)((int64_t)(g374).n - (int64_t)((int64_t)1LL))))); int32_t *_p1450 = (int32_t*)hr_grow(_v1450, 1, sizeof _x1450); *_p1450 = _x1450; _p1450; }));
return ((int64_t)((int64_t)(g374).n - (int64_t)((int64_t)1LL)));
}
static bool f194_is_fixed(int64_t t_982) {
return ((f143_tclass(t_982)) == (((int64_t)0LL)));
}
static void f195_ck_assign(int64_t n_984) {
S4 x_985 = (*({ hrv *_t1451 = &(g679); int64_t _i1451 = n_984; (S4*)_t1451->b + hr_ix(_i1451, _t1451->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:685"); })); 
int64_t o_986 = ((int64_t)((x_985).op_)); 
if (((o_986) == (((int64_t)11LL)))) { int64_t t_987 = f138_ck(((int64_t)((x_985).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t tl_988 = ((int64_t)((x_985).a_)); 
{ int32_t _e1453 = ((*({ hrv *_t1454 = &(g679); int64_t _i1454 = tl_988; (S4*)_t1454->b + hr_ix(_i1454, _t1454->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:690"); }))).n_; for (int32_t _k1453 = 0; _k1453 < _e1453; _k1453++) { int32_t i_989 = (int32_t)_k1453; int64_t tg_990 = f90_kid(tl_988, ((int64_t)(i_989))); 
int64_t tt_991 = f138_ck(tg_990, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
 } } _bk1452:; 
return;
 }
if (((o_986) == (((int64_t)18LL)))) { int64_t tt_992 = f138_ck(((int64_t)((x_985).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t rt_993 = f138_ck(((int64_t)((x_985).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f164_is_pending(rt_993)) { (void)(f181_default_t(((int64_t)((x_985).b_))));
 }
return;
 }
int64_t tt_994 = f138_ck(((int64_t)((x_985).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t d_995 = f176_deref(tt_994); 
if (((o_986) == (((int64_t)36LL)))) { (void)(f138_ck(((int64_t)((x_985).b_)), d_995));
(void)(f141_conv(((int64_t)((x_985).b_)), d_995));
return;
 }
int64_t lk_996 = f177_leaf_kind(d_995); 
int64_t rt_997 = f138_ck(((int64_t)((x_985).b_)), ({ int64_t _r1455; if ((((lk_996) >= (((int64_t)4LL))) && (((o_986) == (((int64_t)28LL))) || ((o_986) == (((int64_t)29LL)))))) { _r1455 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } else { _r1455 = d_995;  } _r1455; })); 
if (((((lk_996) >= (((int64_t)4LL))) && (((o_986) == (((int64_t)28LL))) || ((o_986) == (((int64_t)29LL))))) && ((f176_deref(rt_997)) != (d_995)))) { (void)(f141_conv(((int64_t)((x_985).b_)), f178_leaf_type(d_995)));
return;
 }
if ((((o_986) == (((int64_t)45LL))) || ((o_986) == (((int64_t)46LL))))) { if (f164_is_pending(rt_997)) { (void)(f141_conv(((int64_t)((x_985).b_)), g540));
 }
return;
 }
(void)(f141_conv(((int64_t)((x_985).b_)), d_995));
}
static void f196_decl_nested(int64_t n_999) {
int64_t i_1000 = f105_new_inst(n_999, n_999, ((int64_t)((*({ hrv *_t1456 = &(g694); int64_t _i1456 = n_999; (int32_t*)_t1456->b + hr_ix(_i1456, _t1456->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:25"); })))), g384); 
(void)(({ hrv *_v1457 = &(g308); S14 _x1457 = ((S14){ .name_ = ((*({ hrv *_t1458 = &(g679); int64_t _i1458 = n_999; (S4*)_t1458->b + hr_ix(_i1458, _t1458->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:26"); }))).s_, .node_ = ((int32_t)(n_999)), .inst_ = ((int32_t)(i_1000)), .own_ = ((int32_t)(g384)), }); S14 *_p1457 = (S14*)hr_grow(_v1457, 1, sizeof _x1457); *_p1457 = _x1457; _p1457; }));
(void)(f197_sig_inst(i_1000));
(void)(f202_check_inst(i_1000));
}
static void f197_sig_inst(int64_t i_1001) {
int64_t node_1002 = ((int64_t)(((*({ hrv *_t1459 = &(g373); int64_t _i1459 = i_1001; (S6*)_t1459->b + hr_ix(_i1459, _t1459->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:89"); }))).node_)); 
int64_t ns_1003 = f110_ns_of(node_1002); 
int64_t g0_1004 = (g468).n; 
{ int32_t _e1461 = ((*({ hrv *_t1462 = &(g373); int64_t _i1462 = i_1001; (S6*)_t1462->b + hr_ix(_i1462, _t1462->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:92"); }))).gn_; for (int32_t _k1461 = 0; _k1461 < _e1461; _k1461++) { int32_t j_1005 = (int32_t)_k1461; (void)(({ hrv *_v1463 = &(g468); S7 _x1463 = (*({ hrv *_t1464 = &(g377); int64_t _i1464 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1465 = &(g373); int64_t _i1465 = i_1001; (S6*)_t1465->b + hr_ix(_i1465, _t1465->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:92"); }))).g0_)) + (int64_t)((int64_t)(j_1005)))); (S7*)_t1464->b + hr_ix(_i1464, _t1464->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:92"); })); S7 *_p1463 = (S7*)hr_grow(_v1463, 1, sizeof _x1463); *_p1463 = _x1463; _p1463; }));
 } } _bk1460:; 
int64_t p0_1006 = (g529).n; 
L89 pts_1007 = ({ L89 _t1466; memset(&_t1466, 0, sizeof _t1466); _t1466.n = 0; _t1466; }); 
{ int32_t _e1468 = ((*({ hrv *_t1469 = &(g679); int64_t _i1469 = node_1002; (S4*)_t1469->b + hr_ix(_i1469, _t1469->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:95"); }))).n_; for (int32_t _k1468 = 0; _k1468 < _e1468; _k1468++) { int32_t j_1008 = (int32_t)_k1468; int64_t p_1009 = f90_kid(node_1002, ((int64_t)(j_1008))); 
int64_t t_1010 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((*({ hrv *_t1470 = &(g679); int64_t _i1470 = p_1009; (S4*)_t1470->b + hr_ix(_i1470, _t1470->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:98"); }))).a_) >= (((int32_t)0LL)))) { t_1010 = f113_rtype(((int64_t)(((*({ hrv *_t1471 = &(g679); int64_t _i1471 = p_1009; (S4*)_t1471->b + hr_ix(_i1471, _t1471->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:98"); }))).a_)), ns_1003);
 } else { t_1010 = f130_gb_find(f198_upname(p_1009));
if (((t_1010) < (((int64_t)0LL)))) { t_1010 = g552;
 }
 }
(void)(({ L89 *_v1472 = &(pts_1007); int32_t _x1472 = ((int32_t)(t_1010)); if (_v1472->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:99"); _v1472->e[_v1472->n] = _x1472; &_v1472->e[_v1472->n++]; }));
 } } _bk1467:; 
{ int32_t *_t1473 = &(((*({ hrv *_t1474 = &(g373); int64_t _i1474 = i_1001; (S6*)_t1474->b + hr_ix(_i1474, _t1474->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:101"); }))).p0_); *_t1473 = ((int32_t)((g529).n)); }
(void)(({ hrv *_v1475 = &(g529); hsl _s1475 = ({ hsl _t1476 = ({ L89 *_t1477 = &(pts_1007); (hsl){ (uint8_t*)_t1477->e, _t1477->n }; }); int64_t _l1476 = 0, _h1476 = _t1476.n; if (_l1476 < 0 || _h1476 < _l1476 || _h1476 > _t1476.n) hr_slerr(_l1476, _h1476, _t1476.n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:101"); (hsl){ _t1476.p + _l1476 * (int64_t)sizeof(int32_t), _h1476 - _l1476 }; }); hr_append(_v1475, _s1475.p, _s1475.n, sizeof(int32_t)); }));
{ int32_t *_t1478 = &(((*({ hrv *_t1479 = &(g373); int64_t _i1479 = i_1001; (S6*)_t1479->b + hr_ix(_i1479, _t1479->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:101"); }))).pn_); *_t1478 = ((int32_t)(((int64_t)(pts_1007).n))); }
if (((((*({ hrv *_t1480 = &(g679); int64_t _i1480 = node_1002; (S4*)_t1480->b + hr_ix(_i1480, _t1480->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:102"); }))).b_) >= (((int32_t)0LL)))) { int64_t rl_1013 = ((int64_t)(((*({ hrv *_t1481 = &(g679); int64_t _i1481 = node_1002; (S4*)_t1481->b + hr_ix(_i1481, _t1481->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:103"); }))).b_)); 
if (((((*({ hrv *_t1482 = &(g679); int64_t _i1482 = rl_1013; (S4*)_t1482->b + hr_ix(_i1482, _t1482->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:104"); }))).n_) == (((int32_t)1LL)))) { { int32_t *_t1483 = &(((*({ hrv *_t1484 = &(g373); int64_t _i1484 = i_1001; (S6*)_t1484->b + hr_ix(_i1484, _t1484->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:104"); }))).ret_); *_t1483 = ((int32_t)(f113_rtype(f90_kid(rl_1013, ((int64_t)0LL)), ns_1003))); }
 } else { L90 rs_1014 = ({ L90 _t1485; memset(&_t1485, 0, sizeof _t1485); _t1485.n = 0; _t1485; }); 
{ int32_t _e1487 = ((*({ hrv *_t1488 = &(g679); int64_t _i1488 = rl_1013; (S4*)_t1488->b + hr_ix(_i1488, _t1488->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:105"); }))).n_; for (int32_t _k1487 = 0; _k1487 < _e1487; _k1487++) { int32_t j_1015 = (int32_t)_k1487; int64_t r0_1016 = f113_rtype(f90_kid(rl_1013, ((int64_t)(j_1015))), ns_1003); 
(void)(({ L90 *_v1489 = &(rs_1014); int32_t _x1489 = ((int32_t)(r0_1016)); if (_v1489->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:105"); _v1489->e[_v1489->n] = _x1489; &_v1489->e[_v1489->n++]; }));
 } } _bk1486:; 
{ int32_t *_t1490 = &(((*({ hrv *_t1491 = &(g373); int64_t _i1491 = i_1001; (S6*)_t1491->b + hr_ix(_i1491, _t1491->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:105"); }))).ret_); *_t1490 = ((int32_t)(f199_tlist(((int64_t)14LL), ({ hsl _t1492 = ({ L90 *_t1493 = &(rs_1014); (hsl){ (uint8_t*)_t1493->e, _t1493->n }; }); int64_t _l1492 = 0, _h1492 = _t1492.n; if (_l1492 < 0 || _h1492 < _l1492 || _h1492 > _t1492.n) hr_slerr(_l1492, _h1492, _t1492.n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:105"); (hsl){ _t1492.p + _l1492 * (int64_t)sizeof(int32_t), _h1492 - _l1492 }; }), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); }
 }
 } else { { int32_t *_t1494 = &(((*({ hrv *_t1495 = &(g373); int64_t _i1495 = i_1001; (S6*)_t1495->b + hr_ix(_i1495, _t1495->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:106"); }))).ret_); *_t1494 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); }
{ bool *_t1496 = &(((*({ hrv *_t1497 = &(g373); int64_t _i1497 = i_1001; (S6*)_t1497->b + hr_ix(_i1497, _t1497->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:106"); }))).rinf_); *_t1496 = true; }
if ((((((uint16_t)((uint64_t)((*({ hrv *_t1498 = &(g679); int64_t _i1498 = node_1002; (S4*)_t1498->b + hr_ix(_i1498, _t1498->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:106"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))) || f200_surely_void(node_1002))) { { int32_t *_t1499 = &(((*({ hrv *_t1500 = &(g373); int64_t _i1500 = i_1001; (S6*)_t1500->b + hr_ix(_i1500, _t1500->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:106"); }))).ret_); *_t1499 = ((int32_t)(g535)); }
{ bool *_t1501 = &(((*({ hrv *_t1502 = &(g373); int64_t _i1502 = i_1001; (S6*)_t1502->b + hr_ix(_i1502, _t1502->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:106"); }))).rinf_); *_t1501 = false; }
 }
 }
(void)(({ hrv *_v1503 = &(g468); int64_t _k1503 = ((int64_t)((int64_t)(g468).n - (int64_t)g0_1004)); if (_k1503 < 0 || _k1503 > _v1503->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:107"); _v1503->n -= _k1503; }));
}
static int64_t f198_upname(int64_t p_1011) {
hrv s_1012 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_v1505 = &(s_1012); uint8_t _x1505 = ((uint8_t)36LL); uint8_t *_p1505 = (uint8_t*)hr_grow(_v1505, 1, sizeof _x1505); *_p1505 = _x1505; _p1505; }));
(void)(({ hrv *_v1506 = &(s_1012); hsl _s1506 = f10_nm(((int64_t)(((*({ hrv *_t1507 = &(g679); int64_t _i1507 = p_1011; (S4*)_t1507->b + hr_ix(_i1507, _t1507->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:43"); }))).s_))); hr_append(_v1506, _s1506.p, _s1506.n, sizeof(uint8_t)); }));
return f8_intern(hr_sl(s_1012));
}
static int64_t f199_tlist(int64_t k_1017, hsl xs_1018, int64_t a_1019) {
int64_t l_1020 = (g529).n; 
(void)(({ hrv *_v1508 = &(g529); hsl _s1508 = xs_1018; hr_append(_v1508, _s1508.p, _s1508.n, sizeof(int32_t)); }));
return f13_tmk(((S1){ .k_ = ((uint8_t)(k_1017)), .a_ = ((int32_t)(a_1019)), .c_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), .l_ = ((int32_t)(l_1020)), .n_ = ((int32_t)((xs_1018).n)), }));
}
static bool f200_surely_void(int64_t fnode_1021) {
int64_t body_1022 = ((int64_t)(((*({ hrv *_t1509 = &(g679); int64_t _i1509 = fnode_1021; (S4*)_t1509->b + hr_ix(_i1509, _t1509->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:110"); }))).c_)); 
if (((body_1022) < (((int64_t)0LL)))) { return true;
 }
int64_t tl_1023 = ((int64_t)(((*({ hrv *_t1510 = &(g679); int64_t _i1510 = body_1022; (S4*)_t1510->b + hr_ix(_i1510, _t1510->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:112"); }))).a_)); 
if (((tl_1023) >= (((int64_t)0LL)))) { int64_t k_1024 = ((int64_t)(((*({ hrv *_t1511 = &(g679); int64_t _i1511 = tl_1023; (S4*)_t1511->b + hr_ix(_i1511, _t1511->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:113"); }))).k_)); 
if ((!((((((((k_1024) == (((int64_t)25LL))) || ((k_1024) == (((int64_t)27LL)))) || ((k_1024) == (((int64_t)28LL)))) || ((k_1024) == (((int64_t)29LL)))) || ((k_1024) == (((int64_t)30LL)))) || (((k_1024) == (((int64_t)19LL))) && ((((*({ hrv *_t1512 = &(g679); int64_t _i1512 = tl_1023; (S4*)_t1512->b + hr_ix(_i1512, _t1512->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:113"); }))).c_) < (((int32_t)0LL)))))))) { return false;
 }
 }
return (!(f201_has_valret(body_1022)));
}
static bool f201_has_valret(int64_t n_1025) {
if (((n_1025) < (((int64_t)0LL)))) { return false;
 }
S4 x_1026 = (*({ hrv *_t1513 = &(g679); int64_t _i1513 = n_1025; (S4*)_t1513->b + hr_ix(_i1513, _t1513->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:118"); })); 
int64_t k_1027 = ((int64_t)((x_1026).k_)); 
if (((k_1027) == (((int64_t)28LL)))) { return ((((x_1026).n_) > (((int32_t)0LL))) && (((x_1026).s_) < (((int32_t)0LL))));
 }
if (((k_1027) == (((int64_t)50LL)))) { return false;
 }
if ((((((k_1027) == (((int64_t)1LL))) || ((k_1027) == (((int64_t)2LL)))) || ((k_1027) == (((int64_t)3LL)))) || ((k_1027) == (((int64_t)8LL))))) { return false;
 }
if ((((k_1027) >= (((int64_t)40LL))) && ((k_1027) < (((int64_t)50LL))))) { return false;
 }
if ((((f201_has_valret(((int64_t)((x_1026).a_))) || f201_has_valret(((int64_t)((x_1026).b_)))) || f201_has_valret(((int64_t)((x_1026).c_)))) || f201_has_valret(((int64_t)((x_1026).d_))))) { return true;
 }
if ((((((((((k_1027) == (((int64_t)23LL))) || ((k_1027) == (((int64_t)11LL)))) || ((k_1027) == (((int64_t)20LL)))) || ((k_1027) == (((int64_t)21LL)))) || ((k_1027) == (((int64_t)36LL)))) || ((k_1027) == (((int64_t)16LL)))) || ((k_1027) == (((int64_t)17LL)))) || ((k_1027) == (((int64_t)28LL))))) { { int32_t _e1515 = (x_1026).n_; for (int32_t _k1515 = 0; _k1515 < _e1515; _k1515++) { int32_t i_1028 = (int32_t)_k1515; if (f201_has_valret(f90_kid(n_1025, ((int64_t)(i_1028))))) { return true;
 }
 } } _bk1514:; 
 }
return false;
}
static void f202_check_inst(int64_t i_1029) {
if (((((*({ hrv *_t1516 = &(g373); int64_t _i1516 = i_1029; (S6*)_t1516->b + hr_ix(_i1516, _t1516->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:129"); }))).st_) != (((uint8_t)0LL)))) { return;
 }
int64_t node_1030 = ((int64_t)(((*({ hrv *_t1517 = &(g373); int64_t _i1517 = i_1029; (S6*)_t1517->b + hr_ix(_i1517, _t1517->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:130"); }))).node_)); 
{ uint8_t *_t1518 = &(((*({ hrv *_t1519 = &(g373); int64_t _i1519 = i_1029; (S6*)_t1519->b + hr_ix(_i1519, _t1519->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:131"); }))).st_); *_t1518 = ((uint8_t)1LL); }
if (((((uint16_t)((uint64_t)((*({ hrv *_t1520 = &(g679); int64_t _i1520 = node_1030; (S4*)_t1520->b + hr_ix(_i1520, _t1520->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:132"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { uint8_t *_t1521 = &(((*({ hrv *_t1522 = &(g373); int64_t _i1522 = i_1029; (S6*)_t1522->b + hr_ix(_i1522, _t1522->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:132"); }))).st_); *_t1521 = ((uint8_t)2LL); }
return;
 }
int64_t sa_1031 = g384; 
int64_t sc_1032 = g385; 
int64_t sm_1033 = (g375).n; 
int64_t ld_1034 = g390; 
int64_t bt_1035 = (g446).n; 
int64_t nm0_1036 = (g308).n; 
g384 = i_1029;
g385 = i_1029;
g390 = ((int64_t)0LL);
int64_t g0_1037 = (g468).n; 
{ int32_t _e1524 = ((*({ hrv *_t1525 = &(g373); int64_t _i1525 = i_1029; (S6*)_t1525->b + hr_ix(_i1525, _t1525->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:136"); }))).gn_; for (int32_t _k1524 = 0; _k1524 < _e1524; _k1524++) { int32_t j_1038 = (int32_t)_k1524; (void)(({ hrv *_v1526 = &(g468); S7 _x1526 = (*({ hrv *_t1527 = &(g377); int64_t _i1527 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1528 = &(g373); int64_t _i1528 = i_1029; (S6*)_t1528->b + hr_ix(_i1528, _t1528->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:136"); }))).g0_)) + (int64_t)((int64_t)(j_1038)))); (S7*)_t1527->b + hr_ix(_i1527, _t1527->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:136"); })); S7 *_p1526 = (S7*)hr_grow(_v1526, 1, sizeof _x1526); *_p1526 = _x1526; _p1526; }));
 } } _bk1523:; 
{ int32_t _e1530 = ((*({ hrv *_t1531 = &(g679); int64_t _i1531 = node_1030; (S4*)_t1531->b + hr_ix(_i1531, _t1531->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:137"); }))).n_; for (int32_t _k1530 = 0; _k1530 < _e1530; _k1530++) { int32_t j_1039 = (int32_t)_k1530; int64_t p_1040 = f90_kid(node_1030, ((int64_t)(j_1039))); 
if (((((*({ hrv *_t1532 = &(g679); int64_t _i1532 = p_1040; (S4*)_t1532->b + hr_ix(_i1532, _t1532->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:137"); }))).b_) >= (((int32_t)0LL)))) { int64_t pt_1043 = f203_ptype_of(i_1029, ((int64_t)(j_1039))); 
(void)(f138_ck(((int64_t)(((*({ hrv *_t1533 = &(g679); int64_t _i1533 = p_1040; (S4*)_t1533->b + hr_ix(_i1533, _t1533->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:137"); }))).b_)), pt_1043));
(void)(f141_conv(((int64_t)(((*({ hrv *_t1534 = &(g679); int64_t _i1534 = p_1040; (S4*)_t1534->b + hr_ix(_i1534, _t1534->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:137"); }))).b_)), pt_1043));
 }
 } } _bk1529:; 
{ int32_t _e1536 = ((*({ hrv *_t1537 = &(g679); int64_t _i1537 = node_1030; (S4*)_t1537->b + hr_ix(_i1537, _t1537->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:138"); }))).n_; for (int32_t _k1536 = 0; _k1536 < _e1536; _k1536++) { int32_t j_1044 = (int32_t)_k1536; int64_t p_1045 = f90_kid(node_1030, ((int64_t)(j_1044))); 
int64_t v_1046 = f193_add_lv(((int64_t)(((*({ hrv *_t1538 = &(g679); int64_t _i1538 = p_1045; (S4*)_t1538->b + hr_ix(_i1538, _t1538->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:138"); }))).s_)), f203_ptype_of(i_1029, ((int64_t)(j_1044))), ((int64_t)((int64_t)((int64_t)4LL) | (int64_t)({ int64_t _r1539; if (((((uint16_t)((uint64_t)((*({ hrv *_t1540 = &(g679); int64_t _i1540 = p_1045; (S4*)_t1540->b + hr_ix(_i1540, _t1540->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:138"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { _r1539 = ((int64_t)1LL);  } else { _r1539 = ((int64_t)0LL);  } _r1539; }))), p_1045); 
(void)(f170_set_r(p_1045, ((int64_t)1LL), v_1046));
 } } _bk1535:; 
int64_t body_1047 = ((int64_t)(((*({ hrv *_t1541 = &(g679); int64_t _i1541 = node_1030; (S4*)_t1541->b + hr_ix(_i1541, _t1541->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:139"); }))).c_)); 
int64_t rt_1048 = ((int64_t)(((*({ hrv *_t1542 = &(g373); int64_t _i1542 = i_1029; (S6*)_t1542->b + hr_ix(_i1542, _t1542->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:140"); }))).ret_)); 
int64_t t_1049 = f138_ck(body_1047, ({ int64_t _r1543; if (((rt_1048) >= (((int64_t)0LL)))) { _r1543 = rt_1048;  } else { _r1543 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1543; })); 
int64_t tail_1050 = ((int64_t)(((*({ hrv *_t1544 = &(g679); int64_t _i1544 = body_1047; (S4*)_t1544->b + hr_ix(_i1544, _t1544->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:142"); }))).a_)); 
if (((rt_1048) >= (((int64_t)0LL)))) { if ((((((tail_1050) >= (((int64_t)0LL))) && ((rt_1048) != (g535))) && ((t_1049) != (g535))) && (!(f204_ends(tail_1050))))) { (void)(f141_conv(tail_1050, rt_1048));
 }
 } else { if (((((*({ hrv *_t1545 = &(g373); int64_t _i1545 = i_1029; (S6*)_t1545->b + hr_ix(_i1545, _t1545->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:145"); }))).ret_) < (((int32_t)0LL)))) { if ((((tail_1050) >= (((int64_t)0LL))) && ((t_1049) != (g535)))) { { int32_t *_t1546 = &(((*({ hrv *_t1547 = &(g373); int64_t _i1547 = i_1029; (S6*)_t1547->b + hr_ix(_i1547, _t1547->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:145"); }))).ret_); *_t1546 = ((int32_t)(f181_default_t(tail_1050))); }
 } else { { int32_t *_t1548 = &(((*({ hrv *_t1549 = &(g373); int64_t _i1549 = i_1029; (S6*)_t1549->b + hr_ix(_i1549, _t1549->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:145"); }))).ret_); *_t1548 = ((int32_t)(g535)); }
 }
 } else { if (((((tail_1050) >= (((int64_t)0LL))) && ((t_1049) != (g535))) && ((((int64_t)(((*({ hrv *_t1550 = &(g373); int64_t _i1550 = i_1029; (S6*)_t1550->b + hr_ix(_i1550, _t1550->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:146"); }))).ret_))) != (g535)))) { (void)(f141_conv(tail_1050, ((int64_t)(((*({ hrv *_t1551 = &(g373); int64_t _i1551 = i_1029; (S6*)_t1551->b + hr_ix(_i1551, _t1551->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:146"); }))).ret_))));
 }
 }
 }
(void)(({ hrv *_v1552 = &(g468); int64_t _k1552 = ((int64_t)((int64_t)(g468).n - (int64_t)g0_1037)); if (_k1552 < 0 || _k1552 > _v1552->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:148"); _v1552->n -= _k1552; }));
(void)(({ hrv *_v1553 = &(g375); int64_t _k1553 = ((int64_t)((int64_t)(g375).n - (int64_t)sm_1033)); if (_k1553 < 0 || _k1553 > _v1553->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:149"); _v1553->n -= _k1553; }));
(void)(({ hrv *_v1554 = &(g308); int64_t _k1554 = ((int64_t)((int64_t)(g308).n - (int64_t)nm0_1036)); if (_k1554 < 0 || _k1554 > _v1554->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:149"); _v1554->n -= _k1554; }));
while ((((g446).n) > (bt_1035))) { (void)(({ hrv *_v1556 = &(g446); if (!_v1556->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:150"); ((int32_t*)_v1556->b)[--_v1556->n]; }));
 } _bk1555:; 
g384 = sa_1031;
g385 = sc_1032;
g390 = ld_1034;
{ uint8_t *_t1557 = &(((*({ hrv *_t1558 = &(g373); int64_t _i1558 = i_1029; (S6*)_t1558->b + hr_ix(_i1558, _t1558->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:152"); }))).st_); *_t1557 = ((uint8_t)2LL); }
}
static int64_t f203_ptype_of(int64_t i_1041, int64_t j_1042) {
return ((int64_t)((*({ hrv *_t1559 = &(g529); int64_t _i1559 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1560 = &(g373); int64_t _i1560 = i_1041; (S6*)_t1560->b + hr_ix(_i1560, _t1560->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:127"); }))).p0_)) + (int64_t)j_1042)); (int32_t*)_t1559->b + hr_ix(_i1559, _t1559->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:127"); }))));
}
static bool f204_ends(int64_t n_1051) {
if (((n_1051) < (((int64_t)0LL)))) { return false;
 }
int64_t k_1052 = ((int64_t)(((*({ hrv *_t1561 = &(g679); int64_t _i1561 = n_1051; (S4*)_t1561->b + hr_ix(_i1561, _t1561->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:426"); }))).k_)); 
if (((((k_1052) == (((int64_t)28LL))) || ((k_1052) == (((int64_t)29LL)))) || ((k_1052) == (((int64_t)30LL))))) { return true;
 }
if ((((k_1052) == (((int64_t)11LL))) && ((((*({ hrv *_t1562 = &(g679); int64_t _i1562 = ((*({ hrv *_t1563 = &(g679); int64_t _i1563 = n_1051; (S4*)_t1563->b + hr_ix(_i1563, _t1563->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:428"); }))).a_; (S4*)_t1562->b + hr_ix(_i1562, _t1562->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:428"); }))).k_) == (((uint8_t)8LL))))) { hsl s_1053 = f10_nm(((int64_t)(((*({ hrv *_t1564 = &(g679); int64_t _i1564 = ((*({ hrv *_t1565 = &(g679); int64_t _i1565 = n_1051; (S4*)_t1565->b + hr_ix(_i1565, _t1565->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:428"); }))).a_; (S4*)_t1564->b + hr_ix(_i1564, _t1564->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:428"); }))).s_))); 
if ((hr_streq(s_1053, hr_str("abort", 5)) || hr_streq(s_1053, hr_str("exit", 4)))) { return true;
 }
 }
if (((k_1052) == (((int64_t)23LL)))) { if (((((*({ hrv *_t1566 = &(g679); int64_t _i1566 = n_1051; (S4*)_t1566->b + hr_ix(_i1566, _t1566->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:429"); }))).a_) >= (((int32_t)0LL)))) { return f204_ends(((int64_t)(((*({ hrv *_t1567 = &(g679); int64_t _i1567 = n_1051; (S4*)_t1567->b + hr_ix(_i1567, _t1567->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:429"); }))).a_)));
 }
if (((((*({ hrv *_t1568 = &(g679); int64_t _i1568 = n_1051; (S4*)_t1568->b + hr_ix(_i1568, _t1568->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:429"); }))).n_) > (((int32_t)0LL)))) { return f204_ends(f90_kid(n_1051, ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1569 = &(g679); int64_t _i1569 = n_1051; (S4*)_t1569->b + hr_ix(_i1569, _t1569->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:429"); }))).n_)) - (int64_t)((int64_t)1LL)))));
 }
return false;
 }
if (((k_1052) == (((int64_t)19LL)))) { return ((((((*({ hrv *_t1570 = &(g679); int64_t _i1570 = n_1051; (S4*)_t1570->b + hr_ix(_i1570, _t1570->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:430"); }))).c_) >= (((int32_t)0LL))) && f204_ends(((int64_t)(((*({ hrv *_t1571 = &(g679); int64_t _i1571 = n_1051; (S4*)_t1571->b + hr_ix(_i1571, _t1571->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:430"); }))).b_)))) && f204_ends(((int64_t)(((*({ hrv *_t1572 = &(g679); int64_t _i1572 = n_1051; (S4*)_t1572->b + hr_ix(_i1572, _t1572->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:430"); }))).c_))));
 }
if (((k_1052) == (((int64_t)26LL)))) { return (!(f205_has_break(((int64_t)(((*({ hrv *_t1573 = &(g679); int64_t _i1573 = n_1051; (S4*)_t1573->b + hr_ix(_i1573, _t1573->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:431"); }))).a_)))));
 }
return false;
}
static bool f205_has_break(int64_t n_1054) {
if (((n_1054) < (((int64_t)0LL)))) { return false;
 }
S4 x_1055 = (*({ hrv *_t1574 = &(g679); int64_t _i1574 = n_1054; (S4*)_t1574->b + hr_ix(_i1574, _t1574->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:436"); })); 
int64_t k_1056 = ((int64_t)((x_1055).k_)); 
if (((k_1056) == (((int64_t)29LL)))) { return true;
 }
if (((((((k_1056) == (((int64_t)25LL))) || ((k_1056) == (((int64_t)26LL)))) || ((k_1056) == (((int64_t)27LL)))) || ((k_1056) == (((int64_t)50LL)))) || ((k_1056) == (((int64_t)31LL))))) { return false;
 }
if (((f205_has_break(((int64_t)((x_1055).a_))) || f205_has_break(((int64_t)((x_1055).b_)))) || f205_has_break(((int64_t)((x_1055).c_))))) { return true;
 }
if ((((k_1056) == (((int64_t)23LL))) || ((k_1056) == (((int64_t)20LL))))) { { int32_t _e1576 = (x_1055).n_; for (int32_t _k1576 = 0; _k1576 < _e1576; _k1576++) { int32_t i_1057 = (int32_t)_k1576; int64_t c_1058 = f90_kid(n_1054, ((int64_t)(i_1057))); 
if (f205_has_break(c_1058)) { return true;
 }
if ((((k_1056) == (((int64_t)20LL))) && f205_has_break(((int64_t)(((*({ hrv *_t1577 = &(g679); int64_t _i1577 = c_1058; (S4*)_t1577->b + hr_ix(_i1577, _t1577->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:440"); }))).b_))))) { return true;
 }
 } } _bk1575:; 
 }
return false;
}
static int64_t f206_ck_if(int64_t n_1063, int64_t want_1064) {
S4 x_1065 = (*({ hrv *_t1578 = &(g679); int64_t _i1578 = n_1063; (S4*)_t1578->b + hr_ix(_i1578, _t1578->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:444"); })); 
int64_t c_1066 = f138_ck(((int64_t)((x_1065).a_)), g536); 
if ((((((*({ hrv *_t1579 = &(g528); int64_t _i1579 = f176_deref(c_1066); (S1*)_t1579->b + hr_ix(_i1579, _t1579->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:446"); }))).k_) == (((uint8_t)10LL))) || (((((*({ hrv *_t1580 = &(g528); int64_t _i1580 = c_1066; (S1*)_t1580->b + hr_ix(_i1580, _t1580->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:446"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1581 = &(g528); int64_t _i1581 = c_1066; (S1*)_t1581->b + hr_ix(_i1581, _t1581->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:446"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))))) { (void)(f174_set_x(n_1063, ((int64_t)1LL)));
 } else { (void)(f141_conv(((int64_t)((x_1065).a_)), g536));
 }
int64_t narrow_1070 = f207_narrow_of(((int64_t)((x_1065).a_))); 
int64_t m_1071 = (g375).n; 
if (((narrow_1070) >= (((int64_t)0LL)))) { S12 v_1072 = (*({ hrv *_t1582 = &(g374); int64_t _i1582 = narrow_1070; (S12*)_t1582->b + hr_ix(_i1582, _t1582->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:450"); })); 
(void)(f193_add_lv(((int64_t)((v_1072).name_)), ((int64_t)(((*({ hrv *_t1583 = &(g528); int64_t _i1583 = (v_1072).ty_; (S1*)_t1583->b + hr_ix(_i1583, _t1583->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:450"); }))).a_)), ((int64_t)((int64_t)((int64_t)((v_1072).fl_)) | (int64_t)((int64_t)8LL))), ((int64_t)((x_1065).a_))));
(void)(f174_set_x(n_1063, ((int64_t)((int64_t)((int64_t)((int64_t)(g374).n - (int64_t)((int64_t)1LL))) | (int64_t)((int64_t)((((int64_t)1LL)) << ((((int64_t)30LL)) & 63)))))));
 }
int64_t tb_1073 = f138_ck(((int64_t)((x_1065).b_)), want_1064); 
(void)(({ hrv *_v1584 = &(g375); int64_t _k1584 = ((int64_t)((int64_t)(g375).n - (int64_t)m_1071)); if (_k1584 < 0 || _k1584 > _v1584->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:452"); _v1584->n -= _k1584; }));
if ((((x_1065).c_) < (((int32_t)0LL)))) { return f139_set_t(n_1063, g535);
 }
int64_t tc_1074 = f138_ck(((int64_t)((x_1065).c_)), want_1064); 
bool eb_1075 = f204_ends(((int64_t)((x_1065).b_))); 
bool ec_1076 = f204_ends(((int64_t)((x_1065).c_))); 
if ((eb_1075 && (!(ec_1076)))) { return f139_set_t(n_1063, tc_1074);
 }
if ((ec_1076 && (!(eb_1075)))) { return f139_set_t(n_1063, tb_1073);
 }
if ((eb_1075 && ec_1076)) { return f139_set_t(n_1063, tb_1073);
 }
if ((((tb_1073) == (g535)) || ((tc_1074) == (g535)))) { return f139_set_t(n_1063, g535);
 }
if (((tb_1073) == (tc_1074))) { return f139_set_t(n_1063, tb_1073);
 }
if ((((((want_1064) >= (((int64_t)0LL))) && ((want_1064) != (g535))) && (f164_is_pending(tb_1073) || f151_conv_ok(tb_1073, want_1064, ((int64_t)((x_1065).b_))))) && (f164_is_pending(tc_1074) || f151_conv_ok(tc_1074, want_1064, ((int64_t)((x_1065).c_)))))) { (void)(f141_conv(((int64_t)((x_1065).b_)), want_1064));
(void)(f141_conv(((int64_t)((x_1065).c_)), want_1064));
return f139_set_t(n_1063, want_1064);
 }
int64_t u_1077 = f179_unify(n_1063, ((int64_t)((x_1065).b_)), ((int64_t)((x_1065).c_))); 
return f139_set_t(n_1063, u_1077);
}
static int64_t f207_narrow_of(int64_t c_1067) {
if ((((((*({ hrv *_t1585 = &(g679); int64_t _i1585 = c_1067; (S4*)_t1585->b + hr_ix(_i1585, _t1585->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:466"); }))).k_) != (((uint8_t)8LL))) || ((f157_rk(c_1067)) != (((int64_t)1LL))))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
int64_t v_1068 = f158_rv(c_1067); 
int64_t t_1069 = ((int64_t)(((*({ hrv *_t1586 = &(g374); int64_t _i1586 = v_1068; (S12*)_t1586->b + hr_ix(_i1586, _t1586->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:468"); }))).ty_)); 
if ((((((*({ hrv *_t1587 = &(g528); int64_t _i1587 = t_1069; (S1*)_t1587->b + hr_ix(_i1587, _t1587->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:469"); }))).k_) == (((uint8_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1588 = &(g528); int64_t _i1588 = t_1069; (S1*)_t1588->b + hr_ix(_i1588, _t1588->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:469"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { return v_1068;
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f208_ck_while(int64_t n_1078) {
S4 x_1079 = (*({ hrv *_t1589 = &(g679); int64_t _i1589 = n_1078; (S4*)_t1589->b + hr_ix(_i1589, _t1589->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:473"); })); 
int64_t c_1080 = f138_ck(((int64_t)((x_1079).a_)), g536); 
int64_t narrow_1081 = f207_narrow_of(((int64_t)((x_1079).a_))); 
if (((narrow_1081) < (((int64_t)0LL)))) { (void)(f141_conv(((int64_t)((x_1079).a_)), g536));
 } else { (void)(f174_set_x(n_1078, ((int64_t)1LL)));
 }
g390++;
(void)(f138_ck(((int64_t)((x_1079).b_)), g535));
g390--;
return f139_set_t(n_1078, g535);
}
static int64_t f209_ck_loop(int64_t n_1082, int64_t want_1083) {
(void)(({ hrv *_v1590 = &(g446); int32_t _x1590 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p1590 = (int32_t*)hr_grow(_v1590, 1, sizeof _x1590); *_p1590 = _x1590; _p1590; }));
g390++;
(void)(f138_ck(((int64_t)(((*({ hrv *_t1591 = &(g679); int64_t _i1591 = n_1082; (S4*)_t1591->b + hr_ix(_i1591, _t1591->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:486"); }))).a_)), g535));
g390--;
int64_t t_1084 = ((int64_t)(({ hrv *_v1592 = &(g446); if (!_v1592->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:488"); ((int32_t*)_v1592->b)[--_v1592->n]; }))); 
return f139_set_t(n_1082, ({ int64_t _r1593; if (((t_1084) < (((int64_t)0LL)))) { _r1593 = g535;  } else { _r1593 = t_1084;  } _r1593; }));
}
static int64_t f210_ck_for(int64_t n_1085) {
S4 x_1086 = (*({ hrv *_t1594 = &(g679); int64_t _i1594 = n_1085; (S4*)_t1594->b + hr_ix(_i1594, _t1594->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:492"); })); 
int64_t m_1087 = (g375).n; 
int64_t et_1088 = g540; 
if ((((x_1086).b_) >= (((int32_t)0LL)))) { int64_t ta_1089 = f138_ck(((int64_t)((x_1086).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t tb_1090 = f138_ck(((int64_t)((x_1086).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t u_1091 = f179_unify(n_1085, ((int64_t)((x_1086).a_)), ((int64_t)((x_1086).b_))); 
et_1088 = ({ int64_t _r1595; if (((((*({ hrv *_t1596 = &(g528); int64_t _i1596 = u_1091; (S1*)_t1596->b + hr_ix(_i1596, _t1596->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:498"); }))).k_) == (((uint8_t)12LL)))) { (void)(f141_conv(((int64_t)((x_1086).a_)), g540));
(void)(f141_conv(((int64_t)((x_1086).b_)), g540));
_r1595 = g540;  } else { _r1595 = u_1091;  } _r1595; });
(void)(f174_set_x(n_1085, ((int64_t)0LL)));
 } else { int64_t t_1092 = f138_ck(((int64_t)((x_1086).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t1597 = &(g528); int64_t _i1597 = t_1092; (S1*)_t1597->b + hr_ix(_i1597, _t1597->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:502"); }))).k_) == (((uint8_t)18LL)))) { (void)(f139_set_t(((int64_t)((x_1086).a_)), g553));
t_1092 = g553;
 }
if (((((*({ hrv *_t1598 = &(g528); int64_t _i1598 = t_1092; (S1*)_t1598->b + hr_ix(_i1598, _t1598->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:503"); }))).k_) == (((uint8_t)19LL)))) { t_1092 = f181_default_t(((int64_t)((x_1086).a_)));
 }
int64_t d_1093 = f176_deref(t_1092); 
if (((((*({ hrv *_t1599 = &(g528); int64_t _i1599 = d_1093; (S1*)_t1599->b + hr_ix(_i1599, _t1599->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:505"); }))).k_) == (((uint8_t)12LL)))) { (void)(f141_conv(((int64_t)((x_1086).a_)), g540));
et_1088 = g540;
(void)(f174_set_x(n_1085, ((int64_t)0LL)));
 } else { if (((((*({ hrv *_t1600 = &(g528); int64_t _i1600 = d_1093; (S1*)_t1600->b + hr_ix(_i1600, _t1600->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:506"); }))).k_) == (((uint8_t)3LL)))) { et_1088 = d_1093;
if (((d_1093) != (t_1092))) { (void)(f150_set_cv(((int64_t)((x_1086).a_)), d_1093));
 }
(void)(f174_set_x(n_1085, ((int64_t)0LL)));
 } else { if ((((((*({ hrv *_t1601 = &(g528); int64_t _i1601 = d_1093; (S1*)_t1601->b + hr_ix(_i1601, _t1601->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:507"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t1602 = &(g528); int64_t _i1602 = d_1093; (S1*)_t1602->b + hr_ix(_i1602, _t1602->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:507"); }))).k_) == (((uint8_t)9LL))))) { et_1088 = ((int64_t)(((*({ hrv *_t1603 = &(g528); int64_t _i1603 = d_1093; (S1*)_t1603->b + hr_ix(_i1603, _t1603->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:507"); }))).a_));
(void)(f174_set_x(n_1085, ((int64_t)1LL)));
 } else { hrv mm_1094 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1606 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1605 = &(mm_1094); hr_fs(_o1605, hr_str("cannot iterate over ", 20)); hr_fs(_o1605, hr_sl(*hr_tmp(&_t1606, f162_tn(d_1093)))); }));
}
(void)(f108_cerr(n_1085, hr_sl(mm_1094)));
 }
 }
 }
 }
if ((((x_1086).l_) >= (((int32_t)0LL)))) { et_1088 = f113_rtype(((int64_t)((x_1086).l_)), f110_ns_of(n_1085));
 }
bool byref_1095 = ((((uint16_t)((uint64_t)(x_1086).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))); 
int64_t v_1096 = f193_add_lv(((int64_t)((x_1086).s_)), ({ int64_t _r1607; if (byref_1095) { _r1607 = f117_t_ref(et_1088, ((int64_t)0LL));  } else { _r1607 = et_1088;  } _r1607; }), ((int64_t)((int64_t)((int64_t)16LL) | (int64_t)({ int64_t _r1608; if (byref_1095) { _r1608 = ((int64_t)8LL);  } else { _r1608 = ((int64_t)0LL);  } _r1608; }))), n_1085); 
(void)(f170_set_r(n_1085, ((int64_t)1LL), v_1096));
if ((((x_1086).c_) >= (((int32_t)0LL)))) { int64_t iv_1097 = f193_add_lv(((int64_t)((x_1086).c_)), ({ int64_t _r1609; if ((((x_1086).n_) >= (((int32_t)0LL)))) { _r1609 = f113_rtype(((int64_t)((x_1086).n_)), f110_ns_of(n_1085));  } else { _r1609 = g540;  } _r1609; }), ((int64_t)16LL), n_1085); 
(void)(f174_set_x(n_1085, ((int64_t)((int64_t)f211_ax(n_1085) | (int64_t)((int64_t)((iv_1097) << ((((int64_t)2LL)) & 63)))))));
 }
g390++;
(void)(f138_ck(((int64_t)((x_1086).d_)), g535));
g390--;
(void)(({ hrv *_v1610 = &(g375); int64_t _k1610 = ((int64_t)((int64_t)(g375).n - (int64_t)m_1087)); if (_k1610 < 0 || _k1610 > _v1610->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:518"); _v1610->n -= _k1610; }));
return f139_set_t(n_1085, g535);
}
static int64_t f211_ax(int64_t n_1098) {
return ((int64_t)((*({ hrv *_t1611 = &(g382); int64_t _i1611 = f140_aix(n_1098); (int32_t*)_t1611->b + hr_ix(_i1611, _t1611->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:44"); }))));
}
static int64_t f212_ck_match(int64_t n_1099, int64_t want_1100) {
S4 x_1101 = (*({ hrv *_t1612 = &(g679); int64_t _i1612 = n_1099; (S4*)_t1612->b + hr_ix(_i1612, _t1612->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:522"); })); 
int64_t st_1102 = f138_ck(((int64_t)((x_1101).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t1613 = &(g528); int64_t _i1613 = st_1102; (S1*)_t1613->b + hr_ix(_i1613, _t1613->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:524"); }))).k_) == (((uint8_t)12LL)))) { (void)(f141_conv(((int64_t)((x_1101).a_)), g540));
st_1102 = g540;
 }
int64_t d_1103 = f176_deref(st_1102); 
int64_t rt_1104 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
bool allv_1105 = true; 
{ int32_t _e1615 = (x_1101).n_; for (int32_t _k1615 = 0; _k1615 < _e1615; _k1615++) { int32_t i_1106 = (int32_t)_k1615; int64_t arm_1107 = f90_kid(n_1099, ((int64_t)(i_1106))); 
int64_t m_1108 = (g375).n; 
S4 ax0_1109 = (*({ hrv *_t1616 = &(g679); int64_t _i1616 = arm_1107; (S4*)_t1616->b + hr_ix(_i1616, _t1616->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:531"); })); 
if (((((uint16_t)((uint64_t)(ax0_1109).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) { { int32_t _e1618 = (ax0_1109).n_; for (int32_t _k1618 = 0; _k1618 < _e1618; _k1618++) { int32_t j_1110 = (int32_t)_k1618; int64_t it_1111 = f90_kid(arm_1107, ((int64_t)(j_1110))); 
int64_t lo_1112 = ((int64_t)(((*({ hrv *_t1619 = &(g679); int64_t _i1619 = it_1111; (S4*)_t1619->b + hr_ix(_i1619, _t1619->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:535"); }))).a_)); 
if ((((((*({ hrv *_t1620 = &(g528); int64_t _i1620 = d_1103; (S1*)_t1620->b + hr_ix(_i1620, _t1620->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:536"); }))).k_) == (((uint8_t)6LL))) && ((((*({ hrv *_t1621 = &(g679); int64_t _i1621 = lo_1112; (S4*)_t1621->b + hr_ix(_i1621, _t1621->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:536"); }))).k_) == (((uint8_t)8LL))))) { int64_t ei_1113 = ((int64_t)(((*({ hrv *_t1622 = &(g528); int64_t _i1622 = d_1103; (S1*)_t1622->b + hr_ix(_i1622, _t1622->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:537"); }))).a_)); 
int64_t found_1114 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e1624 = ((*({ hrv *_t1625 = &(g533); int64_t _i1625 = ei_1113; (S8*)_t1625->b + hr_ix(_i1625, _t1625->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:539"); }))).vnum_; for (int32_t _k1624 = 0; _k1624 < _e1624; _k1624++) { int32_t q_1115 = (int32_t)_k1624; if (((((*({ hrv *_t1626 = &(g534); int64_t _i1626 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1627 = &(g533); int64_t _i1627 = ei_1113; (S8*)_t1627->b + hr_ix(_i1627, _t1627->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:539"); }))).v0_)) + (int64_t)((int64_t)(q_1115)))); (S9*)_t1626->b + hr_ix(_i1626, _t1626->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:539"); }))).name_) == (((*({ hrv *_t1628 = &(g679); int64_t _i1628 = lo_1112; (S4*)_t1628->b + hr_ix(_i1628, _t1628->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:539"); }))).s_))) { found_1114 = ((int64_t)(q_1115));
 }
 } } _bk1623:; 
if (((found_1114) < (((int64_t)0LL)))) { hrv mm_1116 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t1632 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o1630 = &(mm_1116); hr_fs(_o1630, hr_str("no variant ", 11)); hr_fs(_o1630, f10_nm(((int64_t)(((*({ hrv *_t1631 = &(g679); int64_t _i1631 = lo_1112; (S4*)_t1631->b + hr_ix(_i1631, _t1631->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:540"); }))).s_)))); hr_fs(_o1630, hr_str(" in ", 4)); hr_fs(_o1630, hr_sl(*hr_tmp(&_t1632, f162_tn(d_1103)))); }));
}
(void)(f108_cerr(lo_1112, hr_sl(mm_1116)));
 }
(void)(f170_set_r(lo_1112, ((int64_t)7LL), found_1114));
(void)(f139_set_t(lo_1112, d_1103));
if (((((ax0_1109).s_) >= (((int32_t)0LL))) && ((found_1114) >= (((int64_t)0LL))))) { int64_t vt_1117 = f125_t_variant(ei_1113, found_1114); 
bool byr_1118 = ((((uint16_t)((uint64_t)(ax0_1109).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))); 
int64_t v_1119 = f193_add_lv(((int64_t)((ax0_1109).s_)), ({ int64_t _r1633; if (byr_1118) { _r1633 = f117_t_ref(vt_1117, ((int64_t)0LL));  } else { _r1633 = vt_1117;  } _r1633; }), ({ int64_t _r1634; if (byr_1118) { _r1634 = ((int64_t)8LL);  } else { _r1634 = ((int64_t)0LL);  } _r1634; }), arm_1107); 
(void)(f170_set_r(arm_1107, ((int64_t)1LL), v_1119));
 }
 } else { (void)(f138_ck(lo_1112, d_1103));
(void)(f141_conv(lo_1112, d_1103));
if (((((*({ hrv *_t1635 = &(g679); int64_t _i1635 = it_1111; (S4*)_t1635->b + hr_ix(_i1635, _t1635->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:545"); }))).b_) >= (((int32_t)0LL)))) { (void)(f138_ck(((int64_t)(((*({ hrv *_t1636 = &(g679); int64_t _i1636 = it_1111; (S4*)_t1636->b + hr_ix(_i1636, _t1636->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:545"); }))).b_)), d_1103));
(void)(f141_conv(((int64_t)(((*({ hrv *_t1637 = &(g679); int64_t _i1637 = it_1111; (S4*)_t1637->b + hr_ix(_i1637, _t1637->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:545"); }))).b_)), d_1103));
 }
 }
 } } _bk1617:; 
 }
int64_t bt_1120 = f138_ck(((int64_t)((ax0_1109).b_)), want_1100); 
(void)(({ hrv *_v1638 = &(g375); int64_t _k1638 = ((int64_t)((int64_t)(g375).n - (int64_t)m_1108)); if (_k1638 < 0 || _k1638 > _v1638->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:550"); _v1638->n -= _k1638; }));
if (((bt_1120) == (g535))) { allv_1105 = false;
 } else { if ((!(f204_ends(((int64_t)((ax0_1109).b_)))))) { if ((((rt_1104) < (((int64_t)0LL))) || f164_is_pending(rt_1104))) { rt_1104 = bt_1120;
 }
 }
 }
 } } _bk1614:; 
if (((!(allv_1105)) || ((rt_1104) < (((int64_t)0LL))))) { return f139_set_t(n_1099, g535);
 }
bool allw_1121 = (((want_1100) >= (((int64_t)0LL))) && ((want_1100) != (g535))); 
if (allw_1121) { { int32_t _e1640 = (x_1101).n_; for (int32_t _k1640 = 0; _k1640 < _e1640; _k1640++) { int32_t i_1122 = (int32_t)_k1640; int64_t b_1123 = ((int64_t)(((*({ hrv *_t1641 = &(g679); int64_t _i1641 = f90_kid(n_1099, ((int64_t)(i_1122))); (S4*)_t1641->b + hr_ix(_i1641, _t1641->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:555"); }))).b_)); 
int64_t bt_1124 = f142_at(b_1123); 
if ((((!(f204_ends(b_1123))) && (!(f164_is_pending(bt_1124)))) && (!(f151_conv_ok(bt_1124, want_1100, b_1123))))) { allw_1121 = false;
 }
 } } _bk1639:; 
 }
if (allw_1121) { { int32_t _e1643 = (x_1101).n_; for (int32_t _k1643 = 0; _k1643 < _e1643; _k1643++) { int32_t i_1125 = (int32_t)_k1643; int64_t b_1126 = ((int64_t)(((*({ hrv *_t1644 = &(g679); int64_t _i1644 = f90_kid(n_1099, ((int64_t)(i_1125))); (S4*)_t1644->b + hr_ix(_i1644, _t1644->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:556"); }))).b_)); 
if ((!(f204_ends(b_1126)))) { (void)(f141_conv(b_1126, want_1100));
 }
 } } _bk1642:; 
return f139_set_t(n_1099, want_1100);
 }
if (f164_is_pending(rt_1104)) { { int32_t _e1646 = (x_1101).n_; for (int32_t _k1646 = 0; _k1646 < _e1646; _k1646++) { int32_t i_1127 = (int32_t)_k1646; int64_t b_1128 = ((int64_t)(((*({ hrv *_t1647 = &(g679); int64_t _i1647 = f90_kid(n_1099, ((int64_t)(i_1127))); (S4*)_t1647->b + hr_ix(_i1647, _t1647->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:557"); }))).b_)); 
int64_t bt_1129 = f142_at(b_1128); 
if (((!(f164_is_pending(bt_1129))) && (!(f204_ends(b_1128))))) { rt_1104 = bt_1129;
 }
 } } _bk1645:; 
 }
if (f164_is_pending(rt_1104)) { int64_t b_1130 = ((int64_t)(((*({ hrv *_t1648 = &(g679); int64_t _i1648 = f90_kid(n_1099, ((int64_t)0LL)); (S4*)_t1648->b + hr_ix(_i1648, _t1648->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:558"); }))).b_)); 
rt_1104 = f181_default_t(b_1130);
 }
{ int32_t _e1650 = (x_1101).n_; for (int32_t _k1650 = 0; _k1650 < _e1650; _k1650++) { int32_t i_1131 = (int32_t)_k1650; int64_t b_1132 = ((int64_t)(((*({ hrv *_t1651 = &(g679); int64_t _i1651 = f90_kid(n_1099, ((int64_t)(i_1131))); (S4*)_t1651->b + hr_ix(_i1651, _t1651->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:559"); }))).b_)); 
if ((!(f204_ends(b_1132)))) { (void)(f141_conv(b_1132, rt_1104));
 }
 } } _bk1649:; 
return f139_set_t(n_1099, rt_1104);
}
static int64_t f213_ck_ret(int64_t n_1133) {
S4 x_1134 = (*({ hrv *_t1652 = &(g679); int64_t _i1652 = n_1133; (S4*)_t1652->b + hr_ix(_i1652, _t1652->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:563"); })); 
if ((((x_1134).s_) >= (((int32_t)0LL)))) { { int32_t _e1654 = (x_1134).n_; for (int32_t _k1654 = 0; _k1654 < _e1654; _k1654++) { int32_t i_1135 = (int32_t)_k1654; (void)(f138_ck(f90_kid(n_1133, ((int64_t)(i_1135))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
(void)(f181_default_t(f90_kid(n_1133, ((int64_t)(i_1135)))));
 } } _bk1653:; 
(void)(f139_set_t(n_1133, g535));
return g535;
 }
int64_t f_1137 = f214_ret_fn(); 
if (((f_1137) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1133, hr_str("return outside a function", 25)));
return g535;
 }
if (((f_1137) != (g385))) { { bool *_t1655 = &(((*({ hrv *_t1656 = &(g373); int64_t _i1656 = g385; (S6*)_t1656->b + hr_ix(_i1656, _t1656->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:567"); }))).lr_); *_t1655 = true; }
(void)(f174_set_x(n_1133, f_1137));
 } else { (void)(f174_set_x(n_1133, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
int64_t rt_1138 = ((int64_t)(((*({ hrv *_t1657 = &(g373); int64_t _i1657 = f_1137; (S6*)_t1657->b + hr_ix(_i1657, _t1657->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:568"); }))).ret_)); 
if ((((x_1134).n_) == (((int32_t)0LL)))) { if (((((rt_1138) >= (((int64_t)0LL))) && ((rt_1138) != (g535))) && (!(((*({ hrv *_t1658 = &(g373); int64_t _i1658 = f_1137; (S6*)_t1658->b + hr_ix(_i1658, _t1658->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:569"); }))).rinf_)))) { (void)(f108_cerr(n_1133, hr_str("return needs a value", 20)));
 }
if (((rt_1138) < (((int64_t)0LL)))) { { int32_t *_t1659 = &(((*({ hrv *_t1660 = &(g373); int64_t _i1660 = f_1137; (S6*)_t1660->b + hr_ix(_i1660, _t1660->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:569"); }))).ret_); *_t1659 = ((int32_t)(g535)); }
 }
return f139_set_t(n_1133, g535);
 }
if (((((rt_1138) >= (((int64_t)0LL))) && ((((*({ hrv *_t1661 = &(g528); int64_t _i1661 = rt_1138; (S1*)_t1661->b + hr_ix(_i1661, _t1661->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:570"); }))).k_) == (((uint8_t)14LL)))) && (((x_1134).n_) == (((int32_t)1LL))))) { int64_t c_1139 = f90_kid(n_1133, ((int64_t)0LL)); 
(void)(f138_ck(c_1139, rt_1138));
return f139_set_t(n_1133, g535);
 }
if ((((x_1134).n_) > (((int32_t)1LL)))) { if (((rt_1138) < (((int64_t)0LL)))) { L90 ts_1140 = ({ L90 _t1662; memset(&_t1662, 0, sizeof _t1662); _t1662.n = 0; _t1662; }); 
{ int32_t _e1664 = (x_1134).n_; for (int32_t _k1664 = 0; _k1664 < _e1664; _k1664++) { int32_t i_1141 = (int32_t)_k1664; (void)(f138_ck(f90_kid(n_1133, ((int64_t)(i_1141))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
int64_t dt0_1142 = f181_default_t(f90_kid(n_1133, ((int64_t)(i_1141)))); 
(void)(({ L90 *_v1665 = &(ts_1140); int32_t _x1665 = ((int32_t)(dt0_1142)); if (_v1665->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:572"); _v1665->e[_v1665->n] = _x1665; &_v1665->e[_v1665->n++]; }));
 } } _bk1663:; 
{ int32_t *_t1666 = &(((*({ hrv *_t1667 = &(g373); int64_t _i1667 = f_1137; (S6*)_t1667->b + hr_ix(_i1667, _t1667->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:572"); }))).ret_); *_t1666 = ((int32_t)(f199_tlist(((int64_t)14LL), ({ hsl _t1668 = ({ L90 *_t1669 = &(ts_1140); (hsl){ (uint8_t*)_t1669->e, _t1669->n }; }); int64_t _l1668 = 0, _h1668 = _t1668.n; if (_l1668 < 0 || _h1668 < _l1668 || _h1668 > _t1668.n) hr_slerr(_l1668, _h1668, _t1668.n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:572"); (hsl){ _t1668.p + _l1668 * (int64_t)sizeof(int32_t), _h1668 - _l1668 }; }), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); }
return f139_set_t(n_1133, g535);
 }
{ int32_t _e1671 = (x_1134).n_; for (int32_t _k1671 = 0; _k1671 < _e1671; _k1671++) { int32_t i_1143 = (int32_t)_k1671; int64_t et_1144 = ({ int64_t _r1672; if ((((((*({ hrv *_t1673 = &(g528); int64_t _i1673 = rt_1138; (S1*)_t1673->b + hr_ix(_i1673, _t1673->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:573"); }))).k_) == (((uint8_t)14LL))) && ((((int64_t)(i_1143))) < (((int64_t)(((*({ hrv *_t1674 = &(g528); int64_t _i1674 = rt_1138; (S1*)_t1674->b + hr_ix(_i1674, _t1674->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:573"); }))).n_)))))) { _r1672 = ((int64_t)((*({ hrv *_t1675 = &(g529); int64_t _i1675 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1676 = &(g528); int64_t _i1676 = rt_1138; (S1*)_t1676->b + hr_ix(_i1676, _t1676->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:573"); }))).l_)) + (int64_t)((int64_t)(i_1143)))); (int32_t*)_t1675->b + hr_ix(_i1675, _t1675->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:573"); }))));  } else { _r1672 = g552;  } _r1672; }); 
(void)(f138_ck(f90_kid(n_1133, ((int64_t)(i_1143))), et_1144));
(void)(f141_conv(f90_kid(n_1133, ((int64_t)(i_1143))), et_1144));
 } } _bk1670:; 
return f139_set_t(n_1133, g535);
 }
int64_t c_1145 = f90_kid(n_1133, ((int64_t)0LL)); 
if (((rt_1138) < (((int64_t)0LL)))) { (void)(f138_ck(c_1145, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
int64_t t_1146 = f181_default_t(c_1145); 
{ int32_t *_t1677 = &(((*({ hrv *_t1678 = &(g373); int64_t _i1678 = f_1137; (S6*)_t1678->b + hr_ix(_i1678, _t1678->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:577"); }))).ret_); *_t1677 = ((int32_t)(t_1146)); }
return f139_set_t(n_1133, g535);
 }
(void)(f138_ck(c_1145, rt_1138));
(void)(f141_conv(c_1145, rt_1138));
return f139_set_t(n_1133, g535);
}
static int64_t f214_ret_fn(void) {
int64_t i_1136 = g384; 
while (((i_1136) >= (((int64_t)0LL)))) { if ((((((*({ hrv *_t1680 = &(g373); int64_t _i1680 = i_1136; (S6*)_t1680->b + hr_ix(_i1680, _t1680->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:581"); }))).node_) >= (((int32_t)0LL))) && ((((*({ hrv *_t1681 = &(g679); int64_t _i1681 = ((*({ hrv *_t1682 = &(g373); int64_t _i1682 = i_1136; (S6*)_t1682->b + hr_ix(_i1682, _t1682->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:581"); }))).node_; (S4*)_t1681->b + hr_ix(_i1681, _t1681->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:581"); }))).k_) == (((uint8_t)50LL))))) { return i_1136;
 }
i_1136 = ((int64_t)(((*({ hrv *_t1683 = &(g373); int64_t _i1683 = i_1136; (S6*)_t1683->b + hr_ix(_i1683, _t1683->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:581"); }))).par_));
 } _bk1679:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f215_ck_break(int64_t n_1147) {
S4 x_1148 = (*({ hrv *_t1684 = &(g679); int64_t _i1684 = n_1147; (S4*)_t1684->b + hr_ix(_i1684, _t1684->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:583"); })); 
if ((((x_1148).a_) >= (((int32_t)0LL)))) { if ((((g446).n) == (((int64_t)0LL)))) { (void)(f108_cerr(n_1147, hr_str("break with a value outside loop or block", 40)));
return g535;
 }
int64_t w_1149 = ((int64_t)((*({ hrv *_t1685 = &(g446); int64_t _i1685 = ((int64_t)((int64_t)(g446).n - (int64_t)((int64_t)1LL))); (int32_t*)_t1685->b + hr_ix(_i1685, _t1685->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:586"); })))); 
int64_t t_1150 = f138_ck(((int64_t)((x_1148).a_)), ({ int64_t _r1686; if (((w_1149) >= (((int64_t)0LL)))) { _r1686 = w_1149;  } else { _r1686 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1686; })); 
if (((w_1149) < (((int64_t)0LL)))) { { int32_t *_t1687 = &((*({ hrv *_t1688 = &(g446); int64_t _i1688 = ((int64_t)((int64_t)(g446).n - (int64_t)((int64_t)1LL))); (int32_t*)_t1688->b + hr_ix(_i1688, _t1688->n, "/home/anmire/ai/amni-lang/helium-fix/hc/check.amni:588"); }))); *_t1687 = ((int32_t)(f181_default_t(((int64_t)((x_1148).a_))))); }
 } else { (void)(f141_conv(((int64_t)((x_1148).a_)), w_1149));
 }
 }
return f139_set_t(n_1147, g535);
}
static int64_t f216_ck_call(int64_t n_1151, int64_t want_1152) {
S4 x_1153 = (*({ hrv *_t1689 = &(g679); int64_t _i1689 = n_1151; (S4*)_t1689->b + hr_ix(_i1689, _t1689->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:239"); })); 
int64_t cal_1154 = ((int64_t)((x_1153).a_)); 
int64_t ck__1155 = ((int64_t)(((*({ hrv *_t1690 = &(g679); int64_t _i1690 = cal_1154; (S4*)_t1690->b + hr_ix(_i1690, _t1690->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:241"); }))).k_)); 
if (((ck__1155) == (((int64_t)8LL)))) { int64_t name_1156 = ((int64_t)(((*({ hrv *_t1691 = &(g679); int64_t _i1691 = cal_1154; (S4*)_t1691->b + hr_ix(_i1691, _t1691->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:243"); }))).s_)); 
int64_t v_1157 = f168_find_lv(name_1156); 
int64_t nf_1160 = f217_find_nest(name_1156); 
if ((((v_1157) < (((int64_t)0LL))) && ((nf_1160) >= (((int64_t)0LL))))) { return f218_call_nested(n_1151, nf_1160);
 }
if (((v_1157) < (((int64_t)0LL)))) { int64_t bg_1195 = f222_block_binding(name_1156); 
if (((bg_1195) >= (((int64_t)0LL)))) { return f227_call_block(n_1151, bg_1195);
 }
int64_t b_1225 = f229_builtin_of(f10_nm(name_1156)); 
if (((((b_1225) >= (((int64_t)0LL))) && (!((((b_1225) == (((int64_t)3LL))) && f230_user_format(n_1151))))) && (!((((b_1225) == (((int64_t)9LL))) && false))))) { return f233_ck_builtin(n_1151, b_1225, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), want_1152);
 }
return f235_call_fn(n_1151, name_1156, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), want_1152);
 }
 }
if (((ck__1155) == (((int64_t)14LL)))) { int64_t obj_1381 = ((int64_t)(((*({ hrv *_t1692 = &(g679); int64_t _i1692 = cal_1154; (S4*)_t1692->b + hr_ix(_i1692, _t1692->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:256"); }))).a_)); 
int64_t name_1382 = ((int64_t)(((*({ hrv *_t1693 = &(g679); int64_t _i1693 = cal_1154; (S4*)_t1693->b + hr_ix(_i1693, _t1693->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:257"); }))).s_)); 
if ((((((((*({ hrv *_t1694 = &(g679); int64_t _i1694 = obj_1381; (S4*)_t1694->b + hr_ix(_i1694, _t1694->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:258"); }))).k_) == (((uint8_t)8LL))) && ((f168_find_lv(((int64_t)(((*({ hrv *_t1695 = &(g679); int64_t _i1695 = obj_1381; (S4*)_t1695->b + hr_ix(_i1695, _t1695->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:258"); }))).s_)))) < (((int64_t)0LL)))) && ((f121_lookup_q(((int64_t)(((*({ hrv *_t1696 = &(g679); int64_t _i1696 = obj_1381; (S4*)_t1696->b + hr_ix(_i1696, _t1696->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:258"); }))).s_)), f110_ns_of(obj_1381), ((int64_t)2LL))) >= (((int64_t)0LL)))) && ((f121_lookup_q(((int64_t)(((*({ hrv *_t1697 = &(g679); int64_t _i1697 = obj_1381; (S4*)_t1697->b + hr_ix(_i1697, _t1697->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:258"); }))).s_)), f110_ns_of(obj_1381), ((int64_t)5LL))) < (((int64_t)0LL))))) { (void)(f108_cerr(n_1151, hr_str("a variant is constructed with { }", 33)));
return f139_set_t(n_1151, g552);
 }
int64_t ot_1383 = f138_ck(obj_1381, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (((((*({ hrv *_t1698 = &(g528); int64_t _i1698 = ot_1383; (S1*)_t1698->b + hr_ix(_i1698, _t1698->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:260"); }))).k_) == (((uint8_t)18LL)))) { (void)(f139_set_t(obj_1381, g553));
ot_1383 = g553;
 }
int64_t d_1384 = f176_deref(ot_1383); 
int64_t mb_1386 = f243_member_of(f10_nm(name_1382)); 
if ((((mb_1386) >= (((int64_t)0LL))) && (((((*({ hrv *_t1699 = &(g528); int64_t _i1699 = d_1384; (S1*)_t1699->b + hr_ix(_i1699, _t1699->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:263"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t1700 = &(g528); int64_t _i1700 = d_1384; (S1*)_t1700->b + hr_ix(_i1700, _t1700->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:263"); }))).k_) == (((uint8_t)9LL)))))) { return f233_ck_builtin(n_1151, mb_1386, obj_1381, want_1152);
 }
if (((((((*({ hrv *_t1701 = &(g528); int64_t _i1701 = ot_1383; (S1*)_t1701->b + hr_ix(_i1701, _t1701->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:264"); }))).k_) == (((uint8_t)19LL))) || ((((*({ hrv *_t1702 = &(g528); int64_t _i1702 = ot_1383; (S1*)_t1702->b + hr_ix(_i1702, _t1702->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:264"); }))).k_) == (((uint8_t)12LL)))) || ((((*({ hrv *_t1703 = &(g528); int64_t _i1703 = ot_1383; (S1*)_t1703->b + hr_ix(_i1703, _t1703->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:264"); }))).k_) == (((uint8_t)13LL))))) { (void)(f181_default_t(obj_1381));
 }
int64_t b_1387 = f229_builtin_of(f10_nm(name_1382)); 
if ((((((b_1387) == (((int64_t)3LL))) || ((b_1387) == (((int64_t)30LL)))) || ((b_1387) == (((int64_t)31LL)))) || ((b_1387) == (((int64_t)7LL))))) { return f233_ck_builtin(n_1151, b_1387, obj_1381, want_1152);
 }
(void)(f174_set_x(n_1151, ((int64_t)1LL)));
return f235_call_fn(n_1151, name_1382, obj_1381, want_1152);
 }
(void)(f108_cerr(n_1151, hr_str("this call's callee is not supported yet", 39)));
return f139_set_t(n_1151, g552);
}
static int64_t f217_find_nest(int64_t name_1158) {
int64_t i_1159 = ((int64_t)((int64_t)(g308).n - (int64_t)((int64_t)1LL))); 
while (((i_1159) >= (((int64_t)0LL)))) { if ((((((int64_t)(((*({ hrv *_t1705 = &(g308); int64_t _i1705 = i_1159; (S14*)_t1705->b + hr_ix(_i1705, _t1705->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:23"); }))).name_))) == (name_1158)) && f169_visible(((int64_t)(((*({ hrv *_t1706 = &(g308); int64_t _i1706 = i_1159; (S14*)_t1706->b + hr_ix(_i1706, _t1706->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:23"); }))).own_))))) { return i_1159;
 }
i_1159--;
 } _bk1704:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f218_call_nested(int64_t n_1161, int64_t nf_1162) {
int64_t i_1163 = ((int64_t)(((*({ hrv *_t1707 = &(g308); int64_t _i1707 = nf_1162; (S14*)_t1707->b + hr_ix(_i1707, _t1707->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:315"); }))).inst_)); 
int64_t s_1170 = f219_ck_args(n_1161, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
{ int32_t _e1709 = ((*({ hrv *_t1710 = &(g679); int64_t _i1710 = n_1161; (S4*)_t1710->b + hr_ix(_i1710, _t1710->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:317"); }))).n_; for (int32_t _k1709 = 0; _k1709 < _e1709; _k1709++) { int32_t j_1171 = (int32_t)_k1709; int64_t c_1172 = f90_kid(n_1161, ((int64_t)(j_1171))); 
if (((((int64_t)(j_1171))) < (((int64_t)(((*({ hrv *_t1711 = &(g373); int64_t _i1711 = i_1163; (S6*)_t1711->b + hr_ix(_i1711, _t1711->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:317"); }))).pn_))))) { (void)(f141_conv(c_1172, f203_ptype_of(i_1163, ((int64_t)(j_1171)))));
 }
 } } _bk1708:; 
(void)(f220_pop_args(s_1170));
(void)(f221_note_caps_of(i_1163));
(void)(f170_set_r(n_1161, ((int64_t)3LL), i_1163));
return f139_set_t(n_1161, ({ int64_t _r1712; if (((((*({ hrv *_t1713 = &(g373); int64_t _i1713 = i_1163; (S6*)_t1713->b + hr_ix(_i1713, _t1713->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:321"); }))).ret_) >= (((int32_t)0LL)))) { _r1712 = ((int64_t)(((*({ hrv *_t1714 = &(g373); int64_t _i1714 = i_1163; (S6*)_t1714->b + hr_ix(_i1714, _t1714->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:321"); }))).ret_));  } else { _r1712 = g535;  } _r1712; }));
}
static int64_t f219_ck_args(int64_t n_1164, int64_t a0n_1165, int64_t first_1166) {
int64_t start_1167 = (g391).n; 
if (((first_1166) >= (((int64_t)0LL)))) { (void)(({ hrv *_v1715 = &(g391); int32_t _x1715 = ((int32_t)(f142_at(first_1166))); int32_t *_p1715 = (int32_t*)hr_grow(_v1715, 1, sizeof _x1715); *_p1715 = _x1715; _p1715; }));
(void)(({ hrv *_v1716 = &(g312); int32_t _x1716 = ((int32_t)(first_1166)); int32_t *_p1716 = (int32_t*)hr_grow(_v1716, 1, sizeof _x1716); *_p1716 = _x1716; _p1716; }));
 }
{ int32_t _e1718 = ((*({ hrv *_t1719 = &(g679); int64_t _i1719 = n_1164; (S4*)_t1719->b + hr_ix(_i1719, _t1719->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:234"); }))).n_; for (int32_t _k1718 = 0; _k1718 < _e1718; _k1718++) { int32_t i_1168 = (int32_t)_k1718; int64_t c_1169 = f90_kid(n_1164, ((int64_t)(i_1168))); 
(void)(({ hrv *_v1720 = &(g391); int32_t _x1720 = ((int32_t)(f138_ck(c_1169, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))))); int32_t *_p1720 = (int32_t*)hr_grow(_v1720, 1, sizeof _x1720); *_p1720 = _x1720; _p1720; }));
(void)(({ hrv *_v1721 = &(g312); int32_t _x1721 = ((int32_t)(c_1169)); int32_t *_p1721 = (int32_t*)hr_grow(_v1721, 1, sizeof _x1721); *_p1721 = _x1721; _p1721; }));
 } } _bk1717:; 
return start_1167;
}
static void f220_pop_args(int64_t s_1173) {
(void)(({ hrv *_v1722 = &(g391); int64_t _k1722 = ((int64_t)((int64_t)(g391).n - (int64_t)s_1173)); if (_k1722 < 0 || _k1722 > _v1722->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:237"); _v1722->n -= _k1722; }));
(void)(({ hrv *_v1723 = &(g312); int64_t _k1723 = ((int64_t)((int64_t)(g312).n - (int64_t)s_1173)); if (_k1723 < 0 || _k1723 > _v1723->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:237"); _v1723->n -= _k1723; }));
}
static void f221_note_caps_of(int64_t i_1174) {
{ hrv *_v1725 = &(g376); for (int64_t _k1725 = 0; _k1725 < _v1725->n; _k1725++) { S13 c_1175 = ((S13*)_v1725->b)[_k1725]; if (((((int64_t)((c_1175).inst_))) == (i_1174))) { int64_t v_1176 = ((int64_t)((c_1175).lv_)); 
if (((((int64_t)(((*({ hrv *_t1726 = &(g374); int64_t _i1726 = v_1176; (S12*)_t1726->b + hr_ix(_i1726, _t1726->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:324"); }))).cfn_))) != (g385))) { (void)(f171_note_cap(v_1176));
 }
 }
 } } _bk1724:; 
}
static int64_t f222_block_binding(int64_t name_1177) {
int64_t i_1178 = g384; 
while (((i_1178) >= (((int64_t)0LL)))) { S6 f_1179 = (*({ hrv *_t1728 = &(g373); int64_t _i1728 = i_1178; (S6*)_t1728->b + hr_ix(_i1728, _t1728->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:277"); })); 
if ((((f_1179).blk_) >= (((int32_t)0LL)))) { int64_t fnode_1180 = ((int64_t)((f_1179).node_)); 
if (((f223_blk_gen(fnode_1180)) == (name_1177))) { return i_1178;
 }
 }
i_1178 = ((int64_t)((f_1179).par_));
 } _bk1727:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f223_blk_gen(int64_t fnode_1181) {
int64_t gl_1183 = f224_gen_list(fnode_1181); 
if (((gl_1183) < (((int64_t)0LL)))) { return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
{ int32_t _e1730 = ((*({ hrv *_t1731 = &(g679); int64_t _i1731 = gl_1183; (S4*)_t1731->b + hr_ix(_i1731, _t1731->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:42"); }))).n_; for (int32_t _k1730 = 0; _k1730 < _e1730; _k1730++) { int32_t i_1184 = (int32_t)_k1730; int64_t g_1185 = ((int64_t)(((*({ hrv *_t1732 = &(g679); int64_t _i1732 = f90_kid(gl_1183, ((int64_t)(i_1184))); (S4*)_t1732->b + hr_ix(_i1732, _t1732->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:42"); }))).s_)); 
if (f225_is_blockparam(fnode_1181, g_1185)) { return g_1185;
 }
 } } _bk1729:; 
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f224_gen_list(int64_t fnode_1182) {
return ((int64_t)(((*({ hrv *_t1733 = &(g679); int64_t _i1733 = fnode_1182; (S4*)_t1733->b + hr_ix(_i1733, _t1733->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:30"); }))).d_));
}
static bool f225_is_blockparam(int64_t fnode_1186, int64_t gname_1187) {
{ int32_t _e1735 = ((*({ hrv *_t1736 = &(g679); int64_t _i1736 = fnode_1186; (S4*)_t1736->b + hr_ix(_i1736, _t1736->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:32"); }))).n_; for (int32_t _k1735 = 0; _k1735 < _e1735; _k1735++) { int32_t i_1188 = (int32_t)_k1735; int64_t p_1189 = f90_kid(fnode_1186, ((int64_t)(i_1188))); 
if ((((((*({ hrv *_t1737 = &(g679); int64_t _i1737 = p_1189; (S4*)_t1737->b + hr_ix(_i1737, _t1737->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:32"); }))).a_) >= (((int32_t)0LL))) && f226_mentions(((int64_t)(((*({ hrv *_t1738 = &(g679); int64_t _i1738 = p_1189; (S4*)_t1738->b + hr_ix(_i1738, _t1738->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:32"); }))).a_)), gname_1187))) { return false;
 }
 } } _bk1734:; 
return true;
}
static bool f226_mentions(int64_t t_1190, int64_t g_1191) {
if (((t_1190) < (((int64_t)0LL)))) { return false;
 }
S4 x_1192 = (*({ hrv *_t1739 = &(g679); int64_t _i1739 = t_1190; (S4*)_t1739->b + hr_ix(_i1739, _t1739->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:37"); })); 
int64_t k_1193 = ((int64_t)((x_1192).k_)); 
if (((k_1193) == (((int64_t)41LL)))) { if (((((int64_t)((x_1192).s_))) == (g_1191))) { return true;
 }
{ int32_t _e1741 = (x_1192).n_; for (int32_t _k1741 = 0; _k1741 < _e1741; _k1741++) { int32_t i_1194 = (int32_t)_k1741; if (f226_mentions(f90_kid(t_1190, ((int64_t)(i_1194))), g_1191)) { return true;
 }
 } } _bk1740:; 
return false;
 }
if (((((((k_1193) == (((int64_t)42LL))) || ((k_1193) == (((int64_t)43LL)))) || ((k_1193) == (((int64_t)44LL)))) || ((k_1193) == (((int64_t)48LL)))) || ((k_1193) == (((int64_t)46LL))))) { return f226_mentions(((int64_t)((x_1192).a_)), g_1191);
 }
return false;
}
static int64_t f227_call_block(int64_t n_1196, int64_t inst_1197) {
int64_t fv_1198 = ((int64_t)(((*({ hrv *_t1742 = &(g373); int64_t _i1742 = inst_1197; (S6*)_t1742->b + hr_ix(_i1742, _t1742->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:284"); }))).blk_)); 
int64_t own_1199 = ((int64_t)(((*({ hrv *_t1743 = &(g373); int64_t _i1743 = inst_1197; (S6*)_t1743->b + hr_ix(_i1743, _t1743->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:285"); }))).bown_)); 
int64_t s_1200 = f219_ck_args(n_1196, ((int64_t)0LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t na_1201 = ((int64_t)(((*({ hrv *_t1744 = &(g679); int64_t _i1744 = n_1196; (S4*)_t1744->b + hr_ix(_i1744, _t1744->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:287"); }))).n_)); 
{ int64_t _e1746 = na_1201; for (int64_t _k1746 = 0; _k1746 < _e1746; _k1746++) { int64_t j_1202 = (int64_t)_k1746; int64_t c_1203 = f90_kid(n_1196, j_1202); 
if (f164_is_pending(f142_at(c_1203))) { { int32_t *_t1747 = &((*({ hrv *_t1748 = &(g391); int64_t _i1748 = ((int64_t)((int64_t)s_1200 + (int64_t)j_1202)); (int32_t*)_t1748->b + hr_ix(_i1748, _t1748->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:288"); }))); *_t1747 = ((int32_t)(f181_default_t(c_1203))); }
 } else { { int32_t *_t1749 = &((*({ hrv *_t1750 = &(g391); int64_t _i1750 = ((int64_t)((int64_t)s_1200 + (int64_t)j_1202)); (int32_t*)_t1750->b + hr_ix(_i1750, _t1750->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:288"); }))); *_t1749 = ((int32_t)(f228_deref_val(f142_at(c_1203)))); }
 }
 } } _bk1745:; 
int64_t bi_1206 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v1752 = &(g373); for (int64_t _k1752 = 0; _k1752 < _v1752->n; _k1752++) { S6 f_1207 = ((S6*)_v1752->b)[_k1752]; int64_t i_1208 = (int64_t)_k1752; if (((((((int64_t)((f_1207).node_))) == (fv_1198)) && ((((int64_t)((f_1207).par_))) == (own_1199))) && (((f_1207).blk_) == (((int32_t)(inst_1197)))))) { bi_1206 = i_1208;
 }
 } } _bk1751:; 
if (((bi_1206) < (((int64_t)0LL)))) { bi_1206 = f105_new_inst(fv_1198, fv_1198, ((int64_t)((*({ hrv *_t1753 = &(g694); int64_t _i1753 = fv_1198; (int32_t*)_t1753->b + hr_ix(_i1753, _t1753->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:292"); })))), own_1199);
{ int32_t *_t1754 = &(((*({ hrv *_t1755 = &(g373); int64_t _i1755 = bi_1206; (S6*)_t1755->b + hr_ix(_i1755, _t1755->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:293"); }))).blk_); *_t1754 = ((int32_t)(inst_1197)); }
{ int32_t *_t1756 = &(((*({ hrv *_t1757 = &(g373); int64_t _i1757 = bi_1206; (S6*)_t1757->b + hr_ix(_i1757, _t1757->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:293"); }))).bown_); *_t1756 = ((int32_t)(own_1199)); }
{ int32_t *_t1758 = &(((*({ hrv *_t1759 = &(g373); int64_t _i1759 = bi_1206; (S6*)_t1759->b + hr_ix(_i1759, _t1759->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:294"); }))).cfn_); *_t1758 = ((int32_t)(g385)); }
int64_t sa_1209 = g384; 
int64_t sm_1210 = (g375).n; 
int64_t bt_1211 = (g446).n; 
int64_t ld_1212 = g390; 
g384 = bi_1206;
g390 = ((int64_t)0LL);
int64_t np_1213 = ((int64_t)(((*({ hrv *_t1760 = &(g679); int64_t _i1760 = fv_1198; (S4*)_t1760->b + hr_ix(_i1760, _t1760->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:297"); }))).n_)); 
if (((((uint16_t)((uint64_t)((*({ hrv *_t1761 = &(g679); int64_t _i1761 = fv_1198; (S4*)_t1761->b + hr_ix(_i1761, _t1761->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:298"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { int64_t _e1763 = np_1213; for (int64_t _k1763 = 0; _k1763 < _e1763; _k1763++) { int64_t j_1214 = (int64_t)_k1763; int64_t p_1215 = f90_kid(fv_1198, j_1214); 
int64_t pt_1216 = ({ int64_t _r1764; if (((j_1214) < (na_1201))) { _r1764 = ((int64_t)((*({ hrv *_t1765 = &(g391); int64_t _i1765 = ((int64_t)((int64_t)s_1200 + (int64_t)j_1214)); (int32_t*)_t1765->b + hr_ix(_i1765, _t1765->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:298"); }))));  } else { _r1764 = g552;  } _r1764; }); 
int64_t v_1217 = f193_add_lv(((int64_t)(((*({ hrv *_t1766 = &(g679); int64_t _i1766 = p_1215; (S4*)_t1766->b + hr_ix(_i1766, _t1766->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:298"); }))).s_)), pt_1216, ((int64_t)32LL), p_1215); 
(void)(f170_set_r(p_1215, ((int64_t)1LL), v_1217));
 } } _bk1762:; 
 } else { if (((na_1201) >= (((int64_t)1LL)))) { int64_t v_1218 = f193_add_lv(f8_intern(hr_str("it", 2)), ((int64_t)((*({ hrv *_t1767 = &(g391); int64_t _i1767 = s_1200; (int32_t*)_t1767->b + hr_ix(_i1767, _t1767->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:299"); })))), ((int64_t)32LL), fv_1198); 
(void)(f170_set_r(fv_1198, ((int64_t)1LL), v_1218));
 }
 }
int64_t body_1219 = ((int64_t)(((*({ hrv *_t1768 = &(g679); int64_t _i1768 = fv_1198; (S4*)_t1768->b + hr_ix(_i1768, _t1768->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:300"); }))).a_)); 
int64_t bt0_1220 = f138_ck(body_1219, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t rt_1221 = g535; 
if ((((((*({ hrv *_t1769 = &(g679); int64_t _i1769 = body_1219; (S4*)_t1769->b + hr_ix(_i1769, _t1769->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:303"); }))).a_) >= (((int32_t)0LL))) && ((bt0_1220) != (g535)))) { rt_1221 = ({ int64_t _r1770; if (f164_is_pending(bt0_1220)) { _r1770 = f181_default_t(((int64_t)(((*({ hrv *_t1771 = &(g679); int64_t _i1771 = body_1219; (S4*)_t1771->b + hr_ix(_i1771, _t1771->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:303"); }))).a_)));  } else { _r1770 = bt0_1220;  } _r1770; });
 }
{ int32_t *_t1772 = &(((*({ hrv *_t1773 = &(g373); int64_t _i1773 = bi_1206; (S6*)_t1773->b + hr_ix(_i1773, _t1773->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:304"); }))).ret_); *_t1772 = ((int32_t)(rt_1221)); }
(void)(({ hrv *_v1774 = &(g375); int64_t _k1774 = ((int64_t)((int64_t)(g375).n - (int64_t)sm_1210)); if (_k1774 < 0 || _k1774 > _v1774->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:305"); _v1774->n -= _k1774; }));
while ((((g446).n) > (bt_1211))) { (void)(({ hrv *_v1776 = &(g446); if (!_v1776->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:305"); ((int32_t*)_v1776->b)[--_v1776->n]; }));
 } _bk1775:; 
g384 = sa_1209;
g390 = ld_1212;
{ uint8_t *_t1777 = &(((*({ hrv *_t1778 = &(g373); int64_t _i1778 = bi_1206; (S6*)_t1778->b + hr_ix(_i1778, _t1778->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:307"); }))).st_); *_t1777 = ((uint8_t)2LL); }
 }
{ int64_t _e1780 = na_1201; for (int64_t _k1780 = 0; _k1780 < _e1780; _k1780++) { int64_t j_1222 = (int64_t)_k1780; int64_t c_1223 = f90_kid(n_1196, j_1222); 
if (f164_is_pending(f142_at(c_1223))) { (void)(f181_default_t(c_1223));
 }
 } } _bk1779:; 
(void)(f220_pop_args(s_1200));
(void)(f170_set_r(n_1196, ((int64_t)10LL), bi_1206));
return f139_set_t(n_1196, ((int64_t)(((*({ hrv *_t1781 = &(g373); int64_t _i1781 = bi_1206; (S6*)_t1781->b + hr_ix(_i1781, _t1781->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:312"); }))).ret_)));
}
static int64_t f228_deref_val(int64_t a_1204) {
int64_t d_1205 = f176_deref(a_1204); 
return ({ int64_t _r1782; if (((((*({ hrv *_t1783 = &(g528); int64_t _i1783 = d_1205; (S1*)_t1783->b + hr_ix(_i1783, _t1783->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:229"); }))).k_) == (((uint8_t)18LL)))) { _r1782 = g553;  } else { _r1782 = d_1205;  } _r1782; });
}
static int64_t f229_builtin_of(hsl name_1224) {
if (hr_streq(name_1224, hr_str("print", 5))) { return ((int64_t)1LL);
 }
if (hr_streq(name_1224, hr_str("str", 3))) { return ((int64_t)2LL);
 }
if (hr_streq(name_1224, hr_str("format", 6))) { return ((int64_t)3LL);
 }
if (hr_streq(name_1224, hr_str("assert", 6))) { return ((int64_t)4LL);
 }
if (hr_streq(name_1224, hr_str("abort", 5))) { return ((int64_t)5LL);
 }
if (hr_streq(name_1224, hr_str("exit", 4))) { return ((int64_t)6LL);
 }
if (hr_streq(name_1224, hr_str("copy", 4))) { return ((int64_t)7LL);
 }
if (hr_streq(name_1224, hr_str("default", 7))) { return ((int64_t)8LL);
 }
if (hr_streq(name_1224, hr_str("to_bytes", 8))) { return ((int64_t)30LL);
 }
if (hr_streq(name_1224, hr_str("bytes_of", 8))) { return ((int64_t)31LL);
 }
if (hr_streq(name_1224, hr_str("from_bytes", 10))) { return ((int64_t)32LL);
 }
if (hr_streq(name_1224, hr_str("embed_file", 10))) { return ((int64_t)33LL);
 }
if (hr_streq(name_1224, hr_str("len", 3))) { return ((int64_t)9LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f230_user_format(int64_t n_1226) {
if (((((*({ hrv *_t1784 = &(g679); int64_t _i1784 = n_1226; (S4*)_t1784->b + hr_ix(_i1784, _t1784->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:273"); }))).n_) != (((int32_t)2LL)))) { return false;
 }
int64_t c0_1227 = (g309).n; 
(void)(f231_cands_add(f8_intern(hr_str("format", 6)), f110_ns_of(n_1226)));
bool any_1236 = false; 
{ int64_t _e1786 = (g309).n; for (int64_t _k1786 = c0_1227; _k1786 < _e1786; _k1786++) { int64_t ci_1237 = (int64_t)_k1786; if ((!(f232_is_std_node(((int64_t)(((*({ hrv *_t1787 = &(g466); int64_t _i1787 = (*({ hrv *_t1788 = &(g309); int64_t _i1788 = ci_1237; (int32_t*)_t1788->b + hr_ix(_i1788, _t1788->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:273"); })); (S5*)_t1787->b + hr_ix(_i1787, _t1787->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:273"); }))).node_)))))) { any_1236 = true;
 }
 } } _bk1785:; 
(void)(({ hrv *_v1789 = &(g309); int64_t _k1789 = ((int64_t)((int64_t)(g309).n - (int64_t)c0_1227)); if (_k1789 < 0 || _k1789 > _v1789->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:273"); _v1789->n -= _k1789; }));
return any_1236;
}
static void f231_cands_add(int64_t name_1228, int64_t ns_1229) {
M57 _t1790 = f122_split_q(name_1228); int64_t a_1230 = _t1790.r0; int64_t b_1231 = _t1790.r1; 
if (((a_1230) >= (((int64_t)0LL)))) { int64_t d_1232 = f107_dmap(name_1228); 
while (((d_1232) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1792 = &(g466); int64_t _i1792 = d_1232; (S5*)_t1792->b + hr_ix(_i1792, _t1792->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:173"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v1793 = &(g309); int32_t _x1793 = ((int32_t)(d_1232)); int32_t *_p1793 = (int32_t*)hr_grow(_v1793, 1, sizeof _x1793); *_p1793 = _x1793; _p1793; }));
 }
d_1232 = ((int64_t)(((*({ hrv *_t1794 = &(g466); int64_t _i1794 = d_1232; (S5*)_t1794->b + hr_ix(_i1794, _t1794->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:173"); }))).next_));
 } _bk1791:; 
return;
 }
if (((a_1230) == (((int64_t)(0 - (uint64_t)(((int64_t)2LL))))))) { int64_t d_1233 = f107_dmap(b_1231); 
while (((d_1233) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1796 = &(g466); int64_t _i1796 = d_1233; (S5*)_t1796->b + hr_ix(_i1796, _t1796->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:174"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v1797 = &(g309); int32_t _x1797 = ((int32_t)(d_1233)); int32_t *_p1797 = (int32_t*)hr_grow(_v1797, 1, sizeof _x1797); *_p1797 = _x1797; _p1797; }));
 }
d_1233 = ((int64_t)(((*({ hrv *_t1798 = &(g466); int64_t _i1798 = d_1233; (S5*)_t1798->b + hr_ix(_i1798, _t1798->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:174"); }))).next_));
 } _bk1795:; 
return;
 }
if (((ns_1229) >= (((int64_t)0LL)))) { int64_t d_1234 = f107_dmap(f98_qual(ns_1229, name_1228)); 
while (((d_1234) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1800 = &(g466); int64_t _i1800 = d_1234; (S5*)_t1800->b + hr_ix(_i1800, _t1800->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:175"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v1801 = &(g309); int32_t _x1801 = ((int32_t)(d_1234)); int32_t *_p1801 = (int32_t*)hr_grow(_v1801, 1, sizeof _x1801); *_p1801 = _x1801; _p1801; }));
 }
d_1234 = ((int64_t)(((*({ hrv *_t1802 = &(g466); int64_t _i1802 = d_1234; (S5*)_t1802->b + hr_ix(_i1802, _t1802->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:175"); }))).next_));
 } _bk1799:; 
 }
int64_t d_1235 = f107_dmap(name_1228); 
while (((d_1235) >= (((int64_t)0LL)))) { if (((((int64_t)(((*({ hrv *_t1804 = &(g466); int64_t _i1804 = d_1235; (S5*)_t1804->b + hr_ix(_i1804, _t1804->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:177"); }))).k_))) == (((int64_t)4LL)))) { (void)(({ hrv *_v1805 = &(g309); int32_t _x1805 = ((int32_t)(d_1235)); int32_t *_p1805 = (int32_t*)hr_grow(_v1805, 1, sizeof _x1805); *_p1805 = _x1805; _p1805; }));
 }
d_1235 = ((int64_t)(((*({ hrv *_t1806 = &(g466); int64_t _i1806 = d_1235; (S5*)_t1806->b + hr_ix(_i1806, _t1806->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:177"); }))).next_));
 } _bk1803:; 
}
static bool f232_is_std_node(int64_t node_1238) {
int64_t f_1239 = f111_node_file(node_1238); 
L49 sp_1240 = f100_lib_path(hr_str("std", 3)); 
return hr_streq(f10_nm(((int64_t)(((*({ hrv *_t1807 = &(g888); int64_t _i1807 = f_1239; (S2*)_t1807->b + hr_ix(_i1807, _t1807->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:179"); }))).name_))), ({ hsl _t1808 = ({ L49 *_t1809 = &(sp_1240); (hsl){ (uint8_t*)_t1809->e, _t1809->n }; }); int64_t _l1808 = 0, _h1808 = _t1808.n; if (_l1808 < 0 || _h1808 < _l1808 || _h1808 > _t1808.n) hr_slerr(_l1808, _h1808, _t1808.n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:179"); (hsl){ _t1808.p + _l1808 * (int64_t)sizeof(uint8_t), _h1808 - _l1808 }; }));
}
static int64_t f233_ck_builtin(int64_t n_1241, int64_t b_1242, int64_t recv_1243, int64_t want_1244) {
S4 x_1245 = (*({ hrv *_t1810 = &(g679); int64_t _i1810 = n_1241; (S4*)_t1810->b + hr_ix(_i1810, _t1810->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:352"); })); 
(void)(f170_set_r(n_1241, ((int64_t)4LL), b_1242));
(void)(f174_set_x(n_1241, ({ int64_t _r1811; if (((recv_1243) >= (((int64_t)0LL)))) { _r1811 = ((int64_t)1LL);  } else { _r1811 = ((int64_t)0LL);  } _r1811; })));
int64_t na_1246 = ((int64_t)((x_1245).n_)); 

int64_t total_1248 = ((int64_t)((int64_t)na_1246 + (int64_t)({ int64_t _r1812; if (((recv_1243) >= (((int64_t)0LL)))) { _r1812 = ((int64_t)1LL);  } else { _r1812 = ((int64_t)0LL);  } _r1812; }))); 
if ((((b_1242) == (((int64_t)1LL))) || ((b_1242) == (((int64_t)2LL))))) { { int64_t _e1814 = na_1246; for (int64_t _k1814 = 0; _k1814 < _e1814; _k1814++) { int64_t i_1249 = (int64_t)_k1814; int64_t c_1250 = f90_kid(n_1241, i_1249); 
int64_t t_1251 = f138_ck(c_1250, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f164_is_pending(t_1251)) { (void)(f181_default_t(c_1250));
 }
 } } _bk1813:; 
return f139_set_t(n_1241, ({ int64_t _r1815; if (((b_1242) == (((int64_t)2LL)))) { _r1815 = f123_t_arr(g541, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))));  } else { _r1815 = g535;  } _r1815; }));
 }
if (((b_1242) == (((int64_t)3LL)))) { int64_t o_1252 = f234_arg(((int64_t)0LL), &recv_1243, &n_1241); 
if (((recv_1243) < (((int64_t)0LL)))) { (void)(f138_ck(o_1252, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
{ int64_t _e1817 = total_1248; for (int64_t _k1817 = ((int64_t)1LL); _k1817 < _e1817; _k1817++) { int64_t i_1253 = (int64_t)_k1817; int64_t c_1254 = f234_arg(i_1253, &recv_1243, &n_1241); 
int64_t t_1255 = f138_ck(c_1254, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
if (f164_is_pending(t_1255)) { (void)(f181_default_t(c_1254));
 }
 } } _bk1816:; 
return f139_set_t(n_1241, g535);
 }
if (((b_1242) == (((int64_t)4LL)))) { (void)(f138_ck(f234_arg(((int64_t)0LL), &recv_1243, &n_1241), g536));
(void)(f141_conv(f234_arg(((int64_t)0LL), &recv_1243, &n_1241), g536));
return f139_set_t(n_1241, g535);
 }
if (((b_1242) == (((int64_t)5LL)))) { int64_t t_1256 = f138_ck(f234_arg(((int64_t)0LL), &recv_1243, &n_1241), g553); 
if (f164_is_pending(t_1256)) { (void)(f181_default_t(f234_arg(((int64_t)0LL), &recv_1243, &n_1241)));
 }
return f139_set_t(n_1241, g535);
 }
if (((b_1242) == (((int64_t)6LL)))) { (void)(f138_ck(f234_arg(((int64_t)0LL), &recv_1243, &n_1241), g540));
(void)(f141_conv(f234_arg(((int64_t)0LL), &recv_1243, &n_1241), g540));
return f139_set_t(n_1241, g535);
 }
if (((b_1242) == (((int64_t)8LL)))) { int64_t ta_1257 = ((int64_t)((x_1245).c_)); 
if (((ta_1257) < (((int64_t)0LL)))) { (void)(f108_cerr(n_1241, hr_str("default needs a type: default<T>()", 34)));
return f139_set_t(n_1241, g552);
 }
return f139_set_t(n_1241, f113_rtype(f90_kid(ta_1257, ((int64_t)0LL)), f110_ns_of(n_1241)));
 }
if (((b_1242) == (((int64_t)7LL)))) { int64_t c_1258 = f234_arg(((int64_t)0LL), &recv_1243, &n_1241); 
if (((recv_1243) < (((int64_t)0LL)))) { (void)(f138_ck(c_1258, want_1244));
 }
int64_t t_1259 = f142_at(c_1258); 
if (f164_is_pending(t_1259)) { t_1259 = f181_default_t(c_1258);
 }
int64_t d_1260 = f176_deref(t_1259); 
int64_t k_1261 = ((int64_t)(((*({ hrv *_t1818 = &(g528); int64_t _i1818 = d_1260; (S1*)_t1818->b + hr_ix(_i1818, _t1818->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:378"); }))).k_)); 
if (((k_1261) == (((int64_t)9LL)))) { return f139_set_t(n_1241, f123_t_arr(((int64_t)(((*({ hrv *_t1819 = &(g528); int64_t _i1819 = d_1260; (S1*)_t1819->b + hr_ix(_i1819, _t1819->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:379"); }))).a_)), ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
return f139_set_t(n_1241, d_1260);
 }
if (((b_1242) == (((int64_t)9LL)))) { int64_t c_1262 = f234_arg(((int64_t)0LL), &recv_1243, &n_1241); 
if (((recv_1243) < (((int64_t)0LL)))) { (void)(f138_ck(c_1262, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (((((*({ hrv *_t1820 = &(g528); int64_t _i1820 = f142_at(c_1262); (S1*)_t1820->b + hr_ix(_i1820, _t1820->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:382"); }))).k_) == (((uint8_t)18LL)))) { (void)(f139_set_t(c_1262, g553));
 }
return f139_set_t(n_1241, g540);
 }
if (((b_1242) == (((int64_t)31LL)))) { int64_t c_1263 = f234_arg(((int64_t)0LL), &recv_1243, &n_1241); 
if (((recv_1243) < (((int64_t)0LL)))) { (void)(f138_ck(c_1263, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (f164_is_pending(f142_at(c_1263))) { (void)(f181_default_t(c_1263));
 }
return f139_set_t(n_1241, g553);
 }
if (((b_1242) == (((int64_t)30LL)))) { int64_t c_1264 = f234_arg(((int64_t)0LL), &recv_1243, &n_1241); 
if (((recv_1243) < (((int64_t)0LL)))) { (void)(f138_ck(c_1264, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (f164_is_pending(f142_at(c_1264))) { (void)(f181_default_t(c_1264));
 }
if (((total_1248) > (((int64_t)1LL)))) { (void)(f138_ck(f234_arg(((int64_t)1LL), &recv_1243, &n_1241), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f139_set_t(n_1241, g535);
 }
return f139_set_t(n_1241, f123_t_arr(g541, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
 }
if (((b_1242) == (((int64_t)32LL)))) { int64_t ta_1265 = ((int64_t)((x_1245).c_)); 
int64_t t_1266 = ({ int64_t _r1821; if (((ta_1265) >= (((int64_t)0LL)))) { _r1821 = f113_rtype(f90_kid(ta_1265, ((int64_t)0LL)), f110_ns_of(n_1241));  } else { _r1821 = g552;  } _r1821; }); 
(void)(f138_ck(f234_arg(((int64_t)0LL), &recv_1243, &n_1241), g553));
if (f164_is_pending(f142_at(f234_arg(((int64_t)0LL), &recv_1243, &n_1241)))) { (void)(f181_default_t(f234_arg(((int64_t)0LL), &recv_1243, &n_1241)));
 }
return f139_set_t(n_1241, t_1266);
 }
if (((b_1242) == (((int64_t)33LL)))) { (void)(f138_ck(f234_arg(((int64_t)0LL), &recv_1243, &n_1241), g553));
(void)(f181_default_t(f234_arg(((int64_t)0LL), &recv_1243, &n_1241)));
return f139_set_t(n_1241, g553);
 }
int64_t r_1267 = recv_1243; 
int64_t rt_1268 = f176_deref(f142_at(r_1267)); 
int64_t e_1269 = ((int64_t)(((*({ hrv *_t1822 = &(g528); int64_t _i1822 = rt_1268; (S1*)_t1822->b + hr_ix(_i1822, _t1822->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:389"); }))).a_)); 
if (((b_1242) == (((int64_t)20LL)))) { if (((total_1248) != (((int64_t)2LL)))) { (void)(f108_cerr(n_1241, hr_str("push takes one value", 20)));
return f139_set_t(n_1241, g552);
 }
int64_t c_1270 = f234_arg(((int64_t)1LL), &recv_1243, &n_1241); 
(void)(f138_ck(c_1270, e_1269));
(void)(f141_conv(c_1270, e_1269));
return f139_set_t(n_1241, f117_t_ref(e_1269, ((int64_t)0LL)));
 }
if (((b_1242) == (((int64_t)21LL)))) { int64_t c_1271 = f234_arg(((int64_t)1LL), &recv_1243, &n_1241); 
int64_t t_1272 = f138_ck(c_1271, f18_t_slice(e_1269, true)); 
if (((((*({ hrv *_t1823 = &(g528); int64_t _i1823 = t_1272; (S1*)_t1823->b + hr_ix(_i1823, _t1823->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:391"); }))).k_) == (((uint8_t)18LL)))) { (void)(f139_set_t(c_1271, g553));
 } else { if (((((*({ hrv *_t1824 = &(g528); int64_t _i1824 = t_1272; (S1*)_t1824->b + hr_ix(_i1824, _t1824->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:391"); }))).k_) == (((uint8_t)19LL)))) { (void)(f141_conv(c_1271, f123_t_arr(e_1269, ((int64_t)4LL), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))));
 } else { int64_t dt_1273 = f176_deref(t_1272); 
if (((((((*({ hrv *_t1825 = &(g528); int64_t _i1825 = dt_1273; (S1*)_t1825->b + hr_ix(_i1825, _t1825->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:391"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t1826 = &(g528); int64_t _i1826 = dt_1273; (S1*)_t1826->b + hr_ix(_i1826, _t1826->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:391"); }))).k_) == (((uint8_t)9LL)))) && ((((int64_t)(((*({ hrv *_t1827 = &(g528); int64_t _i1827 = dt_1273; (S1*)_t1827->b + hr_ix(_i1827, _t1827->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:391"); }))).a_))) != (e_1269)))) { (void)(f108_cerr(c_1271, hr_str("append of a different element type", 34)));
 }
 }
 }
return f139_set_t(n_1241, g535);
 }
if (((b_1242) == (((int64_t)22LL)))) { return f139_set_t(n_1241, e_1269);
 }
if (((b_1242) == (((int64_t)23LL)))) { (void)(f138_ck(f234_arg(((int64_t)1LL), &recv_1243, &n_1241), g540));
(void)(f141_conv(f234_arg(((int64_t)1LL), &recv_1243, &n_1241), g540));
return f139_set_t(n_1241, g535);
 }
if (((b_1242) == (((int64_t)24LL)))) { (void)(f138_ck(f234_arg(((int64_t)1LL), &recv_1243, &n_1241), g540));
(void)(f141_conv(f234_arg(((int64_t)1LL), &recv_1243, &n_1241), g540));
if (((total_1248) > (((int64_t)2LL)))) { (void)(f138_ck(f234_arg(((int64_t)2LL), &recv_1243, &n_1241), e_1269));
(void)(f141_conv(f234_arg(((int64_t)2LL), &recv_1243, &n_1241), e_1269));
 }
return f139_set_t(n_1241, g535);
 }
if (((b_1242) == (((int64_t)25LL)))) { return f139_set_t(n_1241, g535);
 }
if (((b_1242) == (((int64_t)26LL)))) { (void)(f138_ck(f234_arg(((int64_t)1LL), &recv_1243, &n_1241), ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return f139_set_t(n_1241, g540);
 }
return f139_set_t(n_1241, g552);
}
static int64_t f234_arg(int64_t i_1247, int64_t *c1243, int64_t *c1241) {
return ({ int64_t _r1828; if ((((*c1243)) >= (((int64_t)0LL)))) { _r1828 = ({ int64_t _r1829; if (((i_1247) == (((int64_t)0LL)))) { _r1829 = (*c1243);  } else { _r1829 = f90_kid((*c1241), ((int64_t)((int64_t)i_1247 - (int64_t)((int64_t)1LL))));  } _r1829; });  } else { _r1828 = f90_kid((*c1241), i_1247);  } _r1828; });
}
static int64_t f235_call_fn(int64_t n_1274, int64_t name_1275, int64_t recv_1276, int64_t want_1277) {
int64_t s_1278 = f219_ck_args(n_1274, ((int64_t)0LL), recv_1276); 
int64_t an_1279 = ((int64_t)((int64_t)(g391).n - (int64_t)s_1278)); 
int64_t blk_1280 = ((int64_t)(((*({ hrv *_t1830 = &(g679); int64_t _i1830 = n_1274; (S4*)_t1830->b + hr_ix(_i1830, _t1830->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:329"); }))).b_)); 
M91 _t1831 = f236_resolve(n_1274, name_1275, f110_ns_of(n_1274), s_1278, an_1279, blk_1280, ((int64_t)(((*({ hrv *_t1832 = &(g679); int64_t _i1832 = n_1274; (S4*)_t1832->b + hr_ix(_i1832, _t1832->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:330"); }))).c_)), true); int64_t fnode_1356 = _t1831.r0; int64_t b0_1357 = _t1831.r1; int64_t bn_1358 = _t1831.r2; 
if (((fnode_1356) < (((int64_t)0LL)))) { hrv m_1359 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1834 = &(m_1359); hr_fs(_o1834, hr_str("no function ", 12)); hr_fs(_o1834, f10_nm(name_1275)); hr_fs(_o1834, hr_str(" matches (", 10)); }));
{ int64_t _e1836 = an_1279; for (int64_t _k1836 = 0; _k1836 < _e1836; _k1836++) { int64_t j_1360 = (int64_t)_k1836; if (((j_1360) > (((int64_t)0LL)))) { (void)(({ hrv *_v1837 = &(m_1359); hsl _s1837 = hr_str(", ", 2); hr_append(_v1837, _s1837.p, _s1837.n, sizeof(uint8_t)); }));
 }
{ hrv _t1839 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_v1838 = &(m_1359); hsl _s1838 = hr_sl(*hr_tmp(&_t1839, f162_tn(((int64_t)((*({ hrv *_t1840 = &(g391); int64_t _i1840 = ((int64_t)((int64_t)s_1278 + (int64_t)j_1360)); (int32_t*)_t1840->b + hr_ix(_i1840, _t1840->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:333"); }))))))); hr_append(_v1838, _s1838.p, _s1838.n, sizeof(uint8_t)); }));
}
 } } _bk1835:; 
(void)(({ hrv *_v1841 = &(m_1359); hsl _s1841 = hr_str(")", 1); hr_append(_v1841, _s1841.p, _s1841.n, sizeof(uint8_t)); }));
(void)(f108_cerr(n_1274, hr_sl(m_1359)));
(void)(f220_pop_args(s_1278));
(void)(({ hrv *_v1842 = &(g310); int64_t _k1842 = ((int64_t)((int64_t)(g310).n - (int64_t)b0_1357)); if (_k1842 < 0 || _k1842 > _v1842->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:337"); _v1842->n -= _k1842; }));
return f139_set_t(n_1274, g552);
 }
int64_t inst_1375 = f241_get_inst(fnode_1356, b0_1357, bn_1358, blk_1280, g384); 
(void)(({ hrv *_v1843 = &(g310); int64_t _k1843 = ((int64_t)((int64_t)(g310).n - (int64_t)b0_1357)); if (_k1843 < 0 || _k1843 > _v1843->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:341"); _v1843->n -= _k1843; }));
{ int64_t _e1845 = an_1279; for (int64_t _k1845 = 0; _k1845 < _e1845; _k1845++) { int64_t j_1376 = (int64_t)_k1845; int64_t c_1377 = ((int64_t)((*({ hrv *_t1846 = &(g312); int64_t _i1846 = ((int64_t)((int64_t)s_1278 + (int64_t)j_1376)); (int32_t*)_t1846->b + hr_ix(_i1846, _t1846->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:342"); })))); 
int64_t pt_1378 = f203_ptype_of(inst_1375, j_1376); 
if ((((((pt_1378) >= (((int64_t)0LL))) && ((((*({ hrv *_t1847 = &(g528); int64_t _i1847 = pt_1378; (S1*)_t1847->b + hr_ix(_i1847, _t1847->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:342"); }))).k_) == (((uint8_t)10LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1848 = &(g528); int64_t _i1848 = pt_1378; (S1*)_t1848->b + hr_ix(_i1848, _t1848->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:342"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL)))) && ((((*({ hrv *_t1849 = &(g528); int64_t _i1849 = pt_1378; (S1*)_t1849->b + hr_ix(_i1849, _t1849->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:342"); }))).c_) < (((int32_t)0LL))))) { if (f164_is_pending(f142_at(c_1377))) { (void)(f141_conv(c_1377, ((int64_t)(((*({ hrv *_t1850 = &(g528); int64_t _i1850 = pt_1378; (S1*)_t1850->b + hr_ix(_i1850, _t1850->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:342"); }))).a_))));
 }
 } else { (void)(f141_conv(c_1377, pt_1378));
 }
 } } _bk1844:; 
(void)(f220_pop_args(s_1278));
(void)(f221_note_caps_of(inst_1375));
if (((*({ hrv *_t1851 = &(g373); int64_t _i1851 = inst_1375; (S6*)_t1851->b + hr_ix(_i1851, _t1851->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:345"); }))).lr_) { { bool *_t1852 = &(((*({ hrv *_t1853 = &(g373); int64_t _i1853 = g385; (S6*)_t1853->b + hr_ix(_i1853, _t1853->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:345"); }))).lr_); *_t1852 = true; }
 }
(void)(f170_set_r(n_1274, ((int64_t)3LL), inst_1375));
int64_t rt_1379 = ((int64_t)(((*({ hrv *_t1854 = &(g373); int64_t _i1854 = inst_1375; (S6*)_t1854->b + hr_ix(_i1854, _t1854->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:347"); }))).ret_)); 
if (((rt_1379) < (((int64_t)0LL)))) { if (((((*({ hrv *_t1855 = &(g373); int64_t _i1855 = inst_1375; (S6*)_t1855->b + hr_ix(_i1855, _t1855->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:348"); }))).st_) == (((uint8_t)1LL)))) { hrv m_1380 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1857 = &(m_1380); hr_fs(_o1857, hr_str("recursive call to ", 18)); hr_fs(_o1857, f10_nm(name_1275)); hr_fs(_o1857, hr_str(" needs its result type written", 30)); }));
(void)(f108_cerr(n_1274, hr_sl(m_1380)));
 }
return f139_set_t(n_1274, g552);
 }
return f139_set_t(n_1274, rt_1379);
}
static M91 f236_resolve(int64_t n_1281, int64_t name_1282, int64_t ns_1283, int64_t a0_1284, int64_t an_1285, int64_t blk_1286, int64_t tyargs_1287, bool report_1288) {
int64_t c0_1289 = (g309).n; 
(void)(f231_cands_add(name_1282, ns_1283));
int64_t best_1290 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
int64_t bestr_1291 = ((int64_t)99LL); 
int64_t bestb0_1292 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
int64_t bestbn_1293 = ((int64_t)0LL); 
bool tie_1294 = false; 
bool bestuser_1295 = false; 
int64_t nb0_1296 = (g310).n; 
{ int64_t _e1859 = (g309).n; for (int64_t _k1859 = c0_1289; _k1859 < _e1859; _k1859++) { int64_t ci_1297 = (int64_t)_k1859; int64_t fnode_1298 = ((int64_t)(((*({ hrv *_t1860 = &(g466); int64_t _i1860 = (*({ hrv *_t1861 = &(g309); int64_t _i1861 = ci_1297; (int32_t*)_t1861->b + hr_ix(_i1861, _t1861->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:186"); })); (S5*)_t1860->b + hr_ix(_i1860, _t1860->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:186"); }))).node_)); 
int64_t np_1299 = ((int64_t)(((*({ hrv *_t1862 = &(g679); int64_t _i1862 = fnode_1298; (S4*)_t1862->b + hr_ix(_i1862, _t1862->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:187"); }))).n_)); 
int64_t nreq_1300 = ((int64_t)0LL); 
{ int64_t _e1864 = np_1299; for (int64_t _k1864 = 0; _k1864 < _e1864; _k1864++) { int64_t j_1301 = (int64_t)_k1864; if (((((*({ hrv *_t1865 = &(g679); int64_t _i1865 = f90_kid(fnode_1298, j_1301); (S4*)_t1865->b + hr_ix(_i1865, _t1865->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:189"); }))).b_) < (((int32_t)0LL)))) { nreq_1300 = ((int64_t)((int64_t)j_1301 + (int64_t)((int64_t)1LL)));
 }
 } } _bk1863:; 
if ((((an_1285) > (np_1299)) || ((an_1285) < (nreq_1300)))) { continue;
 }
int64_t bg_1302 = f223_blk_gen(fnode_1298); 
if ((((((blk_1286) >= (((int64_t)0LL)))) != (((bg_1302) >= (((int64_t)0LL))))) && (!(((((blk_1286) < (((int64_t)0LL))) && ((bg_1302) >= (((int64_t)0LL)))) && ((tyargs_1287) >= (((int64_t)0LL)))))))) { continue;
 }
int64_t b0_1303 = (g310).n; 
int64_t gl_1304 = f224_gen_list(fnode_1298); 
if (((gl_1304) >= (((int64_t)0LL)))) { { int32_t _e1867 = ((*({ hrv *_t1868 = &(g679); int64_t _i1868 = gl_1304; (S4*)_t1868->b + hr_ix(_i1868, _t1868->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:195"); }))).n_; for (int32_t _k1867 = 0; _k1867 < _e1867; _k1867++) { int32_t j_1305 = (int32_t)_k1867; (void)(({ hrv *_v1869 = &(g310); S7 _x1869 = ((S7){ .name_ = ((*({ hrv *_t1870 = &(g679); int64_t _i1870 = f90_kid(gl_1304, ((int64_t)(j_1305))); (S4*)_t1870->b + hr_ix(_i1870, _t1870->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:195"); }))).s_, .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }); S7 *_p1869 = (S7*)hr_grow(_v1869, 1, sizeof _x1869); *_p1869 = _x1869; _p1869; }));
 } } _bk1866:; 
 }
{ int64_t _e1872 = np_1299; for (int64_t _k1872 = 0; _k1872 < _e1872; _k1872++) { int64_t j_1306 = (int64_t)_k1872; int64_t p_1307 = f90_kid(fnode_1298, j_1306); 
if (((((*({ hrv *_t1873 = &(g679); int64_t _i1873 = p_1307; (S4*)_t1873->b + hr_ix(_i1873, _t1873->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:196"); }))).a_) < (((int32_t)0LL)))) { (void)(({ hrv *_v1874 = &(g310); S7 _x1874 = ((S7){ .name_ = ((int32_t)(f198_upname(p_1307))), .ty_ = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))), }); S7 *_p1874 = (S7*)hr_grow(_v1874, 1, sizeof _x1874); *_p1874 = _x1874; _p1874; }));
 }
 } } _bk1871:; 
if (((tyargs_1287) >= (((int64_t)0LL)))) { { int64_t _e1876 = f45_min(((int64_t)(((*({ hrv *_t1877 = &(g679); int64_t _i1877 = tyargs_1287; (S4*)_t1877->b + hr_ix(_i1877, _t1877->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:197"); }))).n_)), ((int64_t)((int64_t)(g310).n - (int64_t)b0_1303))); for (int64_t _k1876 = 0; _k1876 < _e1876; _k1876++) { int64_t j_1308 = (int64_t)_k1876; { int32_t *_t1878 = &(((*({ hrv *_t1879 = &(g310); int64_t _i1879 = ((int64_t)((int64_t)b0_1303 + (int64_t)j_1308)); (S7*)_t1879->b + hr_ix(_i1879, _t1879->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:197"); }))).ty_); *_t1878 = ((int32_t)(f113_rtype(f90_kid(tyargs_1287, j_1308), ns_1283))); }
 } } _bk1875:; 
 }
{ int64_t _e1881 = an_1285; for (int64_t _k1881 = 0; _k1881 < _e1881; _k1881++) { int64_t j_1309 = (int64_t)_k1881; int64_t p_1310 = f90_kid(fnode_1298, j_1309); 
int64_t a_1311 = ((int64_t)((*({ hrv *_t1882 = &(g391); int64_t _i1882 = ((int64_t)((int64_t)a0_1284 + (int64_t)j_1309)); (int32_t*)_t1882->b + hr_ix(_i1882, _t1882->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:198"); })))); 
if ((!(f164_is_pending(a_1311)))) { if (((((*({ hrv *_t1883 = &(g679); int64_t _i1883 = p_1310; (S4*)_t1883->b + hr_ix(_i1883, _t1883->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:198"); }))).a_) >= (((int32_t)0LL)))) { (void)(f237_match_ty(((int64_t)(((*({ hrv *_t1884 = &(g679); int64_t _i1884 = p_1310; (S4*)_t1884->b + hr_ix(_i1884, _t1884->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:198"); }))).a_)), a_1311, b0_1303));
 } else { { int64_t _e1886 = (g310).n; for (int64_t _k1886 = b0_1303; _k1886 < _e1886; _k1886++) { int64_t q_1323 = (int64_t)_k1886; if ((((((int64_t)(((*({ hrv *_t1887 = &(g310); int64_t _i1887 = q_1323; (S7*)_t1887->b + hr_ix(_i1887, _t1887->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:198"); }))).name_))) == (f198_upname(p_1310))) && ((((*({ hrv *_t1888 = &(g310); int64_t _i1888 = q_1323; (S7*)_t1888->b + hr_ix(_i1888, _t1888->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:198"); }))).ty_) < (((int32_t)0LL))))) { { int32_t *_t1889 = &(((*({ hrv *_t1890 = &(g310); int64_t _i1890 = q_1323; (S7*)_t1890->b + hr_ix(_i1890, _t1890->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:198"); }))).ty_); *_t1889 = ((int32_t)(f228_deref_val(a_1311))); }
 }
 } } _bk1885:; 
 }
 }
 } } _bk1880:; 
{ int64_t _e1892 = an_1285; for (int64_t _k1892 = 0; _k1892 < _e1892; _k1892++) { int64_t j_1324 = (int64_t)_k1892; int64_t p_1325 = f90_kid(fnode_1298, j_1324); 
int64_t a_1326 = ((int64_t)((*({ hrv *_t1893 = &(g391); int64_t _i1893 = ((int64_t)((int64_t)a0_1284 + (int64_t)j_1324)); (int32_t*)_t1893->b + hr_ix(_i1893, _t1893->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:199"); })))); 
if (f164_is_pending(a_1326)) { int64_t dt_1329 = f238_pend_default(a_1326); 
if (((((*({ hrv *_t1894 = &(g679); int64_t _i1894 = p_1325; (S4*)_t1894->b + hr_ix(_i1894, _t1894->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:199"); }))).a_) >= (((int32_t)0LL)))) { (void)(f237_match_ty(((int64_t)(((*({ hrv *_t1895 = &(g679); int64_t _i1895 = p_1325; (S4*)_t1895->b + hr_ix(_i1895, _t1895->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:199"); }))).a_)), dt_1329, b0_1303));
 } else { { int64_t _e1897 = (g310).n; for (int64_t _k1897 = b0_1303; _k1897 < _e1897; _k1897++) { int64_t q_1330 = (int64_t)_k1897; if ((((((int64_t)(((*({ hrv *_t1898 = &(g310); int64_t _i1898 = q_1330; (S7*)_t1898->b + hr_ix(_i1898, _t1898->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:199"); }))).name_))) == (f198_upname(p_1325))) && ((((*({ hrv *_t1899 = &(g310); int64_t _i1899 = q_1330; (S7*)_t1899->b + hr_ix(_i1899, _t1899->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:199"); }))).ty_) < (((int32_t)0LL))))) { { int32_t *_t1900 = &(((*({ hrv *_t1901 = &(g310); int64_t _i1901 = q_1330; (S7*)_t1901->b + hr_ix(_i1901, _t1901->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:199"); }))).ty_); *_t1900 = ((int32_t)(dt_1329)); }
 }
 } } _bk1896:; 
 }
 }
 } } _bk1891:; 
bool ok_1331 = true; 
{ int64_t _e1903 = (g310).n; for (int64_t _k1903 = b0_1303; _k1903 < _e1903; _k1903++) { int64_t q_1332 = (int64_t)_k1903; if (((((*({ hrv *_t1904 = &(g310); int64_t _i1904 = q_1332; (S7*)_t1904->b + hr_ix(_i1904, _t1904->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:201"); }))).ty_) < (((int32_t)0LL)))) { if ((((bg_1302) >= (((int64_t)0LL))) && ((((int64_t)(((*({ hrv *_t1905 = &(g310); int64_t _i1905 = q_1332; (S7*)_t1905->b + hr_ix(_i1905, _t1905->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:201"); }))).name_))) == (bg_1302)))) { { int32_t *_t1906 = &(((*({ hrv *_t1907 = &(g310); int64_t _i1907 = q_1332; (S7*)_t1907->b + hr_ix(_i1907, _t1907->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:201"); }))).ty_); *_t1906 = ((int32_t)(g555)); }
 } else { ok_1331 = false;
 }
 }
 } } _bk1902:; 
if ((!(ok_1331))) { (void)(({ hrv *_v1908 = &(g310); int64_t _k1908 = ((int64_t)((int64_t)(g310).n - (int64_t)b0_1303)); if (_k1908 < 0 || _k1908 > _v1908->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:202"); _v1908->n -= _k1908; }));
continue;
 }
int64_t g0_1333 = (g468).n; 
{ int64_t _e1910 = (g310).n; for (int64_t _k1910 = b0_1303; _k1910 < _e1910; _k1910++) { int64_t q_1334 = (int64_t)_k1910; (void)(({ hrv *_v1911 = &(g468); S7 _x1911 = (*({ hrv *_t1912 = &(g310); int64_t _i1912 = q_1334; (S7*)_t1912->b + hr_ix(_i1912, _t1912->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:204"); })); S7 *_p1911 = (S7*)hr_grow(_v1911, 1, sizeof _x1911); *_p1911 = _x1911; _p1911; }));
 } } _bk1909:; 
int64_t fns_1335 = f110_ns_of(fnode_1298); 
int64_t worst_1336 = ((int64_t)0LL); 
{ int64_t _e1914 = an_1285; for (int64_t _k1914 = 0; _k1914 < _e1914; _k1914++) { int64_t j_1337 = (int64_t)_k1914; int64_t p_1338 = f90_kid(fnode_1298, j_1337); 
int64_t pt_1339 = ({ int64_t _r1915; if (((((*({ hrv *_t1916 = &(g679); int64_t _i1916 = p_1338; (S4*)_t1916->b + hr_ix(_i1916, _t1916->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:209"); }))).a_) >= (((int32_t)0LL)))) { _r1915 = f113_rtype(((int64_t)(((*({ hrv *_t1917 = &(g679); int64_t _i1917 = p_1338; (S4*)_t1917->b + hr_ix(_i1917, _t1917->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:209"); }))).a_)), fns_1335);  } else { _r1915 = f130_gb_find(f198_upname(p_1338));  } _r1915; }); 
int64_t r_1350 = f239_arg_rank(((int64_t)((*({ hrv *_t1918 = &(g312); int64_t _i1918 = ((int64_t)((int64_t)a0_1284 + (int64_t)j_1337)); (int32_t*)_t1918->b + hr_ix(_i1918, _t1918->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:210"); })))), ((int64_t)((*({ hrv *_t1919 = &(g391); int64_t _i1919 = ((int64_t)((int64_t)a0_1284 + (int64_t)j_1337)); (int32_t*)_t1919->b + hr_ix(_i1919, _t1919->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:210"); })))), pt_1339); 
if (((r_1350) < (((int64_t)0LL)))) { worst_1336 = ((int64_t)99LL);
{ goto _bk1913; }
 }
if (((r_1350) > (worst_1336))) { worst_1336 = r_1350;
 }
 } } _bk1913:; 
(void)(({ hrv *_v1920 = &(g468); int64_t _k1920 = ((int64_t)((int64_t)(g468).n - (int64_t)g0_1333)); if (_k1920 < 0 || _k1920 > _v1920->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:214"); _v1920->n -= _k1920; }));
if ((((worst_1336) < (((int64_t)2LL))) && (((gl_1304) >= (((int64_t)0LL))) || (((np_1299) > (((int64_t)0LL))) && f240_untyped_any(fnode_1298))))) { worst_1336 = f103_max(worst_1336, ((int64_t)1LL));
 }
if (((worst_1336) == (((int64_t)99LL)))) { (void)(({ hrv *_v1921 = &(g310); int64_t _k1921 = ((int64_t)((int64_t)(g310).n - (int64_t)b0_1303)); if (_k1921 < 0 || _k1921 > _v1921->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:216"); _v1921->n -= _k1921; }));
continue;
 }
bool user_1353 = (!(f232_is_std_node(fnode_1298))); 
if ((((worst_1336) < (bestr_1291)) || ((((worst_1336) == (bestr_1291)) && user_1353) && (!(bestuser_1295))))) { best_1290 = fnode_1298;
bestr_1291 = worst_1336;
bestb0_1292 = b0_1303;
bestbn_1293 = ((int64_t)((int64_t)(g310).n - (int64_t)b0_1303));
tie_1294 = false;
bestuser_1295 = user_1353;
 } else { if ((((worst_1336) == (bestr_1291)) && ((user_1353) == (bestuser_1295)))) { tie_1294 = true;
 }
 }
 } } _bk1858:; 
(void)(({ hrv *_v1922 = &(g309); int64_t _k1922 = ((int64_t)((int64_t)(g309).n - (int64_t)c0_1289)); if (_k1922 < 0 || _k1922 > _v1922->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:221"); _v1922->n -= _k1922; }));
if (((best_1290) < (((int64_t)0LL)))) { (void)(({ hrv *_v1923 = &(g310); int64_t _k1923 = ((int64_t)((int64_t)(g310).n - (int64_t)nb0_1296)); if (_k1923 < 0 || _k1923 > _v1923->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:222"); _v1923->n -= _k1923; }));
return (M91){ ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)0LL), ((int64_t)0LL) };
 }
if ((tie_1294 && report_1288)) { hrv m_1354 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
(void)(({ hrv *_o1925 = &(m_1354); hr_fs(_o1925, hr_str("ambiguous call to ", 18)); hr_fs(_o1925, f10_nm(name_1282)); }));
(void)(f108_cerr(n_1281, hr_sl(m_1354)));
 }
if (((bestb0_1292) > (nb0_1296))) { { int64_t _e1927 = bestbn_1293; for (int64_t _k1927 = ((int64_t)0LL); _k1927 < _e1927; _k1927++) { int64_t q_1355 = (int64_t)_k1927; { S7 *_t1928 = &((*({ hrv *_t1929 = &(g310); int64_t _i1929 = ((int64_t)((int64_t)nb0_1296 + (int64_t)q_1355)); (S7*)_t1929->b + hr_ix(_i1929, _t1929->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:224"); }))); *_t1928 = (*({ hrv *_t1930 = &(g310); int64_t _i1930 = ((int64_t)((int64_t)bestb0_1292 + (int64_t)q_1355)); (S7*)_t1930->b + hr_ix(_i1930, _t1930->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:224"); })); }
 } } _bk1926:; 
 }
(void)(({ hrv *_v1931 = &(g310); int64_t _k1931 = ((int64_t)((int64_t)((int64_t)((int64_t)(g310).n - (int64_t)nb0_1296)) - (int64_t)bestbn_1293)); if (_k1931 < 0 || _k1931 > _v1931->n) hr_die("pop_n past the length", "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:225"); _v1931->n -= _k1931; }));
return (M91){ best_1290, nb0_1296, bestbn_1293 };
}
static bool f237_match_ty(int64_t tn0_1312, int64_t t0_1313, int64_t g0_1314) {
if (((tn0_1312) < (((int64_t)0LL)))) { return true;
 }
S4 x_1315 = (*({ hrv *_t1932 = &(g679); int64_t _i1932 = tn0_1312; (S4*)_t1932->b + hr_ix(_i1932, _t1932->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:46"); })); 
int64_t k_1316 = ((int64_t)((x_1315).k_)); 
int64_t t_1317 = f176_deref(t0_1313); 
if (((k_1316) == (((int64_t)41LL)))) { if ((((x_1315).n_) == (((int32_t)0LL)))) { { int64_t _e1934 = (g310).n; for (int64_t _k1934 = g0_1314; _k1934 < _e1934; _k1934++) { int64_t i_1318 = (int64_t)_k1934; if (((((*({ hrv *_t1935 = &(g310); int64_t _i1935 = i_1318; (S7*)_t1935->b + hr_ix(_i1935, _t1935->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:50"); }))).name_) == ((x_1315).s_))) { if (((((*({ hrv *_t1936 = &(g310); int64_t _i1936 = i_1318; (S7*)_t1936->b + hr_ix(_i1936, _t1936->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:50"); }))).ty_) < (((int32_t)0LL)))) { { int32_t *_t1937 = &(((*({ hrv *_t1938 = &(g310); int64_t _i1938 = i_1318; (S7*)_t1938->b + hr_ix(_i1938, _t1938->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:50"); }))).ty_); *_t1937 = ((int32_t)(t_1317)); }
 }
return true;
 }
 } } _bk1933:; 
return true;
 }
if (((((*({ hrv *_t1939 = &(g528); int64_t _i1939 = t_1317; (S1*)_t1939->b + hr_ix(_i1939, _t1939->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:53"); }))).k_) == (((uint8_t)5LL)))) { int64_t si_1319 = ((int64_t)(((*({ hrv *_t1940 = &(g528); int64_t _i1940 = t_1317; (S1*)_t1940->b + hr_ix(_i1940, _t1940->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:53"); }))).a_)); 
if (((((*({ hrv *_t1941 = &(g531); int64_t _i1941 = si_1319; (S10*)_t1941->b + hr_ix(_i1941, _t1941->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:53"); }))).tn_) == ((x_1315).n_))) { { int32_t _e1943 = (x_1315).n_; for (int32_t _k1943 = 0; _k1943 < _e1943; _k1943++) { int32_t i_1320 = (int32_t)_k1943; (void)(f237_match_ty(f90_kid(tn0_1312, ((int64_t)(i_1320))), ((int64_t)((*({ hrv *_t1944 = &(g529); int64_t _i1944 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1945 = &(g531); int64_t _i1945 = si_1319; (S10*)_t1945->b + hr_ix(_i1945, _t1945->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:53"); }))).ta_)) + (int64_t)((int64_t)(i_1320)))); (int32_t*)_t1944->b + hr_ix(_i1944, _t1944->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:53"); })))), g0_1314));
 } } _bk1942:; 
 }
 }
if (((((*({ hrv *_t1946 = &(g528); int64_t _i1946 = t_1317; (S1*)_t1946->b + hr_ix(_i1946, _t1946->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:54"); }))).k_) == (((uint8_t)6LL)))) { int64_t ei_1321 = ((int64_t)(((*({ hrv *_t1947 = &(g528); int64_t _i1947 = t_1317; (S1*)_t1947->b + hr_ix(_i1947, _t1947->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:54"); }))).a_)); 
if (((((*({ hrv *_t1948 = &(g533); int64_t _i1948 = ei_1321; (S8*)_t1948->b + hr_ix(_i1948, _t1948->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:54"); }))).tn_) == ((x_1315).n_))) { { int32_t _e1950 = (x_1315).n_; for (int32_t _k1950 = 0; _k1950 < _e1950; _k1950++) { int32_t i_1322 = (int32_t)_k1950; (void)(f237_match_ty(f90_kid(tn0_1312, ((int64_t)(i_1322))), ((int64_t)((*({ hrv *_t1951 = &(g529); int64_t _i1951 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t1952 = &(g533); int64_t _i1952 = ei_1321; (S8*)_t1952->b + hr_ix(_i1952, _t1952->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:54"); }))).ta_)) + (int64_t)((int64_t)(i_1322)))); (int32_t*)_t1951->b + hr_ix(_i1951, _t1951->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:54"); })))), g0_1314));
 } } _bk1949:; 
 }
 }
return true;
 }
if ((((k_1316) == (((int64_t)42LL))) || ((k_1316) == (((int64_t)43LL))))) { if ((((((*({ hrv *_t1953 = &(g528); int64_t _i1953 = t_1317; (S1*)_t1953->b + hr_ix(_i1953, _t1953->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:57"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t1954 = &(g528); int64_t _i1954 = t_1317; (S1*)_t1954->b + hr_ix(_i1954, _t1954->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:57"); }))).k_) == (((uint8_t)9LL))))) { return f237_match_ty(((int64_t)((x_1315).a_)), ((int64_t)(((*({ hrv *_t1955 = &(g528); int64_t _i1955 = t_1317; (S1*)_t1955->b + hr_ix(_i1955, _t1955->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:57"); }))).a_)), g0_1314);
 }
if (((((*({ hrv *_t1956 = &(g528); int64_t _i1956 = t_1317; (S1*)_t1956->b + hr_ix(_i1956, _t1956->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:57"); }))).k_) == (((uint8_t)18LL)))) { return f237_match_ty(((int64_t)((x_1315).a_)), g541, g0_1314);
 }
return true;
 }
if (((k_1316) == (((int64_t)44LL)))) { if (((((*({ hrv *_t1957 = &(g528); int64_t _i1957 = t0_1313; (S1*)_t1957->b + hr_ix(_i1957, _t1957->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:58"); }))).k_) == (((uint8_t)10LL)))) { return f237_match_ty(((int64_t)((x_1315).a_)), ((int64_t)(((*({ hrv *_t1958 = &(g528); int64_t _i1958 = t0_1313; (S1*)_t1958->b + hr_ix(_i1958, _t1958->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:58"); }))).a_)), g0_1314);
 }
return f237_match_ty(((int64_t)((x_1315).a_)), t_1317, g0_1314);
 }
if (((k_1316) == (((int64_t)48LL)))) { return f237_match_ty(((int64_t)((x_1315).a_)), t0_1313, g0_1314);
 }
return true;
}
static int64_t f238_pend_default(int64_t a_1327) {
int64_t k_1328 = ((int64_t)(((*({ hrv *_t1959 = &(g528); int64_t _i1959 = a_1327; (S1*)_t1959->b + hr_ix(_i1959, _t1959->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:230"); }))).k_)); 
return ({ int64_t _r1960; if (((k_1328) == (((int64_t)12LL)))) { _r1960 = g540;  } else { _r1960 = ({ int64_t _r1961; if (((k_1328) == (((int64_t)13LL)))) { _r1961 = g546;  } else { _r1961 = ({ int64_t _r1962; if (((k_1328) == (((int64_t)18LL)))) { _r1962 = g553;  } else { _r1962 = a_1327;  } _r1962; });  } _r1961; });  } _r1960; });
}
static int64_t f239_arg_rank(int64_t n_1340, int64_t a_1341, int64_t p_1342) {
if (((p_1342) < (((int64_t)0LL)))) { return ((int64_t)1LL);
 }
if (((a_1341) == (p_1342))) { return ((int64_t)0LL);
 }
int64_t ak_1343 = ((int64_t)(((*({ hrv *_t1963 = &(g528); int64_t _i1963 = a_1341; (S1*)_t1963->b + hr_ix(_i1963, _t1963->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:65"); }))).k_)); 
int64_t pk_1344 = ((int64_t)(((*({ hrv *_t1964 = &(g528); int64_t _i1964 = p_1342; (S1*)_t1964->b + hr_ix(_i1964, _t1964->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:65"); }))).k_)); 
if ((((pk_1344) == (((int64_t)0LL))) || ((ak_1343) == (((int64_t)0LL))))) { return ((int64_t)0LL);
 }
if (((((pk_1344) == (((int64_t)10LL))) && ((((*({ hrv *_t1965 = &(g528); int64_t _i1965 = p_1342; (S1*)_t1965->b + hr_ix(_i1965, _t1965->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:67"); }))).c_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1966 = &(g528); int64_t _i1966 = p_1342; (S1*)_t1966->b + hr_ix(_i1966, _t1966->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:67"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) == (((uint16_t)0LL))))) { int64_t tgt_1345 = ((int64_t)(((*({ hrv *_t1967 = &(g528); int64_t _i1967 = p_1342; (S1*)_t1967->b + hr_ix(_i1967, _t1967->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:67"); }))).a_)); 
if (((f176_deref(a_1341)) == (tgt_1345))) { return ((int64_t)0LL);
 }
if ((((ak_1343) == (((int64_t)12LL))) || ((ak_1343) == (((int64_t)13LL))))) { return f239_arg_rank(n_1340, a_1341, tgt_1345);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if ((((ak_1343) == (((int64_t)10LL))) && ((((*({ hrv *_t1968 = &(g528); int64_t _i1968 = a_1341; (S1*)_t1968->b + hr_ix(_i1968, _t1968->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:68"); }))).c_) < (((int32_t)0LL))))) { int64_t d_1346 = ((int64_t)(((*({ hrv *_t1969 = &(g528); int64_t _i1969 = a_1341; (S1*)_t1969->b + hr_ix(_i1969, _t1969->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:68"); }))).a_)); 
if (((d_1346) == (p_1342))) { return ((int64_t)0LL);
 }
if (((((pk_1344) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1970 = &(g528); int64_t _i1970 = p_1342; (S1*)_t1970->b + hr_ix(_i1970, _t1970->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:68"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && ((((*({ hrv *_t1971 = &(g528); int64_t _i1971 = p_1342; (S1*)_t1971->b + hr_ix(_i1971, _t1971->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:68"); }))).a_) == (((*({ hrv *_t1972 = &(g528); int64_t _i1972 = a_1341; (S1*)_t1972->b + hr_ix(_i1972, _t1972->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:68"); }))).a_)))) { return ((int64_t)0LL);
 }
return f239_arg_rank(n_1340, d_1346, p_1342);
 }
if (((ak_1343) == (((int64_t)12LL)))) { M78 _t1973 = f156_cval(n_1340); int64_t v_1347 = _t1973.r0; bool u_1348 = _t1973.r1; bool ok_1349 = _t1973.r2; 
if (((pk_1344) == (((int64_t)3LL)))) { if (((!(ok_1349)) || f159_int_fits(v_1347, u_1348, p_1342))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((pk_1344) == (((int64_t)4LL)))) { return ((int64_t)3LL);
 }
if (((pk_1344) == (((int64_t)17LL)))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1343) == (((int64_t)13LL)))) { if (((pk_1344) == (((int64_t)4LL)))) { return ({ int64_t _r1974; if (((((*({ hrv *_t1975 = &(g528); int64_t _i1975 = p_1342; (S1*)_t1975->b + hr_ix(_i1975, _t1975->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:76"); }))).s_) == (((uint8_t)8LL)))) { _r1974 = ((int64_t)1LL);  } else { _r1974 = ((int64_t)2LL);  } _r1974; });
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1343) == (((int64_t)18LL)))) { if ((((pk_1344) == (((int64_t)9LL))) && ((((int64_t)(((*({ hrv *_t1976 = &(g528); int64_t _i1976 = p_1342; (S1*)_t1976->b + hr_ix(_i1976, _t1976->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:77"); }))).a_))) == (g541)))) { return ((int64_t)0LL);
 }
if (f165_is_byte_arr(p_1342)) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1343) == (((int64_t)19LL)))) { if ((((pk_1344) == (((int64_t)8LL))) || ((pk_1344) == (((int64_t)9LL))))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((ak_1343) == (((int64_t)11LL)))) { if ((((pk_1344) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1977 = &(g528); int64_t _i1977 = p_1342; (S1*)_t1977->b + hr_ix(_i1977, _t1977->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:79"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL))))) { return ((int64_t)0LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
 }
if (((((pk_1344) == (((int64_t)10LL))) && ((((uint16_t)((uint64_t)((*({ hrv *_t1978 = &(g528); int64_t _i1978 = p_1342; (S1*)_t1978->b + hr_ix(_i1978, _t1978->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:80"); }))).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) && ((((int64_t)(((*({ hrv *_t1979 = &(g528); int64_t _i1979 = p_1342; (S1*)_t1979->b + hr_ix(_i1979, _t1979->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:80"); }))).a_))) == (a_1341)))) { return ((int64_t)0LL);
 }
if ((((ak_1343) == (((int64_t)3LL))) && ((pk_1344) == (((int64_t)4LL))))) { return ((int64_t)3LL);
 }
if (f152_widens(a_1341, p_1342)) { return ((int64_t)2LL);
 }
if (((((pk_1344) == (((int64_t)9LL))) && (((ak_1343) == (((int64_t)8LL))) || ((ak_1343) == (((int64_t)9LL))))) && ((((*({ hrv *_t1980 = &(g528); int64_t _i1980 = a_1341; (S1*)_t1980->b + hr_ix(_i1980, _t1980->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:83"); }))).a_) == (((*({ hrv *_t1981 = &(g528); int64_t _i1981 = p_1342; (S1*)_t1981->b + hr_ix(_i1981, _t1981->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:83"); }))).a_)))) { return ((int64_t)2LL);
 }
if (((((pk_1344) == (((int64_t)6LL))) && ((ak_1343) == (((int64_t)7LL)))) && ((((*({ hrv *_t1982 = &(g528); int64_t _i1982 = a_1341; (S1*)_t1982->b + hr_ix(_i1982, _t1982->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:84"); }))).a_) == (((*({ hrv *_t1983 = &(g528); int64_t _i1983 = p_1342; (S1*)_t1983->b + hr_ix(_i1983, _t1983->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:84"); }))).a_)))) { return ((int64_t)2LL);
 }
if ((((((pk_1344) == (((int64_t)8LL))) && (((ak_1343) == (((int64_t)8LL))) || ((ak_1343) == (((int64_t)9LL))))) && ((((*({ hrv *_t1984 = &(g528); int64_t _i1984 = a_1341; (S1*)_t1984->b + hr_ix(_i1984, _t1984->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:85"); }))).a_) == (((*({ hrv *_t1985 = &(g528); int64_t _i1985 = p_1342; (S1*)_t1985->b + hr_ix(_i1985, _t1985->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:85"); }))).a_))) && f155_is_construct(n_1340))) { return ((int64_t)2LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static bool f240_untyped_any(int64_t f_1351) {
{ int32_t _e1987 = ((*({ hrv *_t1988 = &(g679); int64_t _i1988 = f_1351; (S4*)_t1988->b + hr_ix(_i1988, _t1988->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:228"); }))).n_; for (int32_t _k1987 = 0; _k1987 < _e1987; _k1987++) { int32_t j_1352 = (int32_t)_k1987; if (((((*({ hrv *_t1989 = &(g679); int64_t _i1989 = f90_kid(f_1351, ((int64_t)(j_1352))); (S4*)_t1989->b + hr_ix(_i1989, _t1989->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:228"); }))).a_) < (((int32_t)0LL)))) { return true;
 }
 } } _bk1986:; 
return false;
}
static int64_t f241_get_inst(int64_t node_1361, int64_t b0_1362, int64_t bn_1363, int64_t blk_1364, int64_t bown_1365) {
int64_t par_1366 = ({ int64_t _r1990; if (((((uint16_t)((uint64_t)((*({ hrv *_t1991 = &(g679); int64_t _i1991 = node_1361; (S4*)_t1991->b + hr_ix(_i1991, _t1991->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:160"); }))).fl_ & (uint64_t)((uint16_t)128LL)))) != (((uint16_t)0LL)))) { _r1990 = g384;  } else { _r1990 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r1990; }); 
if (((blk_1364) < (((int64_t)0LL)))) { { hrv *_v1993 = &(g373); for (int64_t _k1993 = 0; _k1993 < _v1993->n; _k1993++) { S6 f_1367 = ((S6*)_v1993->b)[_k1993]; int64_t i_1368 = (int64_t)_k1993; if ((((((((int64_t)((f_1367).node_))) == (node_1361)) && (((f_1367).blk_) < (((int32_t)0LL)))) && ((((int64_t)((f_1367).par_))) == (par_1366))) && f242_same_binds(i_1368, b0_1362, bn_1363))) { return i_1368;
 }
 } } _bk1992:; 
 }
int64_t i_1373 = f105_new_inst(node_1361, node_1361, ((int64_t)((*({ hrv *_t1994 = &(g694); int64_t _i1994 = node_1361; (int32_t*)_t1994->b + hr_ix(_i1994, _t1994->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:162"); })))), par_1366); 
{ int32_t *_t1995 = &(((*({ hrv *_t1996 = &(g373); int64_t _i1996 = i_1373; (S6*)_t1996->b + hr_ix(_i1996, _t1996->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:163"); }))).g0_); *_t1995 = ((int32_t)((g377).n)); }
{ int64_t _e1998 = bn_1363; for (int64_t _k1998 = 0; _k1998 < _e1998; _k1998++) { int64_t j_1374 = (int64_t)_k1998; (void)(({ hrv *_v1999 = &(g377); S7 _x1999 = (*({ hrv *_t2000 = &(g310); int64_t _i2000 = ((int64_t)((int64_t)b0_1362 + (int64_t)j_1374)); (S7*)_t2000->b + hr_ix(_i2000, _t2000->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:164"); })); S7 *_p1999 = (S7*)hr_grow(_v1999, 1, sizeof _x1999); *_p1999 = _x1999; _p1999; }));
 } } _bk1997:; 
{ int32_t *_t2001 = &(((*({ hrv *_t2002 = &(g373); int64_t _i2002 = i_1373; (S6*)_t2002->b + hr_ix(_i2002, _t2002->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:165"); }))).gn_); *_t2001 = ((int32_t)(bn_1363)); }
{ int32_t *_t2003 = &(((*({ hrv *_t2004 = &(g373); int64_t _i2004 = i_1373; (S6*)_t2004->b + hr_ix(_i2004, _t2004->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:166"); }))).blk_); *_t2003 = ((int32_t)(blk_1364)); }
{ int32_t *_t2005 = &(((*({ hrv *_t2006 = &(g373); int64_t _i2006 = i_1373; (S6*)_t2006->b + hr_ix(_i2006, _t2006->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:166"); }))).bown_); *_t2005 = ((int32_t)(bown_1365)); }
(void)(f197_sig_inst(i_1373));
(void)(f202_check_inst(i_1373));
return i_1373;
}
static bool f242_same_binds(int64_t i_1369, int64_t b0_1370, int64_t bn_1371) {
if (((((int64_t)(((*({ hrv *_t2007 = &(g373); int64_t _i2007 = i_1369; (S6*)_t2007->b + hr_ix(_i2007, _t2007->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:155"); }))).gn_))) != (bn_1371))) { return false;
 }
{ int64_t _e2009 = bn_1371; for (int64_t _k2009 = 0; _k2009 < _e2009; _k2009++) { int64_t j_1372 = (int64_t)_k2009; if ((((((*({ hrv *_t2010 = &(g377); int64_t _i2010 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2011 = &(g373); int64_t _i2011 = i_1369; (S6*)_t2011->b + hr_ix(_i2011, _t2011->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:156"); }))).g0_)) + (int64_t)j_1372)); (S7*)_t2010->b + hr_ix(_i2010, _t2010->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:156"); }))).ty_) != (((*({ hrv *_t2012 = &(g310); int64_t _i2012 = ((int64_t)((int64_t)b0_1370 + (int64_t)j_1372)); (S7*)_t2012->b + hr_ix(_i2012, _t2012->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:156"); }))).ty_)) || ((((*({ hrv *_t2013 = &(g377); int64_t _i2013 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2014 = &(g373); int64_t _i2014 = i_1369; (S6*)_t2014->b + hr_ix(_i2014, _t2014->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:156"); }))).g0_)) + (int64_t)j_1372)); (S7*)_t2013->b + hr_ix(_i2013, _t2013->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:156"); }))).name_) != (((*({ hrv *_t2015 = &(g310); int64_t _i2015 = ((int64_t)((int64_t)b0_1370 + (int64_t)j_1372)); (S7*)_t2015->b + hr_ix(_i2015, _t2015->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:156"); }))).name_)))) { return false;
 }
 } } _bk2008:; 
return true;
}
static int64_t f243_member_of(hsl name_1385) {
if (hr_streq(name_1385, hr_str("push", 4))) { return ((int64_t)20LL);
 }
if (hr_streq(name_1385, hr_str("append", 6))) { return ((int64_t)21LL);
 }
if (hr_streq(name_1385, hr_str("pop", 3))) { return ((int64_t)22LL);
 }
if (hr_streq(name_1385, hr_str("pop_n", 5))) { return ((int64_t)23LL);
 }
if (hr_streq(name_1385, hr_str("resize", 6))) { return ((int64_t)24LL);
 }
if (hr_streq(name_1385, hr_str("clear", 5))) { return ((int64_t)25LL);
 }
if (hr_streq(name_1385, hr_str("index_of", 8))) { return ((int64_t)26LL);
 }
if (hr_streq(name_1385, hr_str("len", 3))) { return ((int64_t)9LL);
 }
return ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
}
static int64_t f244_ck_slit(int64_t n_1388, int64_t want_1389) {
S4 x_1390 = (*({ hrv *_t2016 = &(g679); int64_t _i2016 = n_1388; (S4*)_t2016->b + hr_ix(_i2016, _t2016->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:400"); })); 
int64_t tnode_1391 = ((int64_t)((x_1390).a_)); 
int64_t ns_1392 = f110_ns_of(n_1388); 
int64_t t_1393 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((((*({ hrv *_t2017 = &(g679); int64_t _i2017 = tnode_1391; (S4*)_t2017->b + hr_ix(_i2017, _t2017->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:404"); }))).k_) == (((uint8_t)41LL))) && ((((*({ hrv *_t2018 = &(g679); int64_t _i2018 = tnode_1391; (S4*)_t2018->b + hr_ix(_i2018, _t2018->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:404"); }))).n_) == (((int32_t)0LL)))) && ((f130_gb_find(((int64_t)(((*({ hrv *_t2019 = &(g679); int64_t _i2019 = tnode_1391; (S4*)_t2019->b + hr_ix(_i2019, _t2019->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:404"); }))).s_)))) < (((int64_t)0LL))))) { int64_t d_1394 = f121_lookup_q(((int64_t)(((*({ hrv *_t2020 = &(g679); int64_t _i2020 = tnode_1391; (S4*)_t2020->b + hr_ix(_i2020, _t2020->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:405"); }))).s_)), ns_1392, ((int64_t)1LL)); 
if ((((d_1394) >= (((int64_t)0LL))) && ((((*({ hrv *_t2021 = &(g679); int64_t _i2021 = ((*({ hrv *_t2022 = &(g466); int64_t _i2022 = d_1394; (S5*)_t2022->b + hr_ix(_i2022, _t2022->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:406"); }))).node_; (S4*)_t2021->b + hr_ix(_i2021, _t2021->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:406"); }))).d_) >= (((int32_t)0LL))))) { if (((((want_1389) >= (((int64_t)0LL))) && ((((*({ hrv *_t2023 = &(g528); int64_t _i2023 = want_1389; (S1*)_t2023->b + hr_ix(_i2023, _t2023->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:406"); }))).k_) == (((uint8_t)5LL)))) && ((((*({ hrv *_t2024 = &(g531); int64_t _i2024 = ((*({ hrv *_t2025 = &(g528); int64_t _i2025 = want_1389; (S1*)_t2025->b + hr_ix(_i2025, _t2025->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:406"); }))).a_; (S10*)_t2024->b + hr_ix(_i2024, _t2024->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:406"); }))).node_) == (((*({ hrv *_t2026 = &(g466); int64_t _i2026 = d_1394; (S5*)_t2026->b + hr_ix(_i2026, _t2026->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:406"); }))).node_)))) { t_1393 = want_1389;
 }
 }
 }
if (((t_1393) < (((int64_t)0LL)))) { t_1393 = f113_rtype(tnode_1391, ns_1392);
 }
int64_t si_1395 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (((((*({ hrv *_t2027 = &(g528); int64_t _i2027 = t_1393; (S1*)_t2027->b + hr_ix(_i2027, _t2027->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:410"); }))).k_) == (((uint8_t)5LL)))) { si_1395 = ((int64_t)(((*({ hrv *_t2028 = &(g528); int64_t _i2028 = t_1393; (S1*)_t2028->b + hr_ix(_i2028, _t2028->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:410"); }))).a_));
 }
if (((((*({ hrv *_t2029 = &(g528); int64_t _i2029 = t_1393; (S1*)_t2029->b + hr_ix(_i2029, _t2029->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:411"); }))).k_) == (((uint8_t)7LL)))) { si_1395 = ((int64_t)(((*({ hrv *_t2030 = &(g534); int64_t _i2030 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2031 = &(g533); int64_t _i2031 = ((*({ hrv *_t2032 = &(g528); int64_t _i2032 = t_1393; (S1*)_t2032->b + hr_ix(_i2032, _t2032->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:411"); }))).a_; (S8*)_t2031->b + hr_ix(_i2031, _t2031->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:411"); }))).v0_)) + (int64_t)((int64_t)(((*({ hrv *_t2033 = &(g528); int64_t _i2033 = t_1393; (S1*)_t2033->b + hr_ix(_i2033, _t2033->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:411"); }))).c_)))); (S9*)_t2030->b + hr_ix(_i2030, _t2030->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:411"); }))).si_));
 }
if (((si_1395) < (((int64_t)0LL)))) { if (((((*({ hrv *_t2034 = &(g528); int64_t _i2034 = t_1393; (S1*)_t2034->b + hr_ix(_i2034, _t2034->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:412"); }))).k_) != (((uint8_t)0LL)))) { (void)(f108_cerr(n_1388, hr_str("not a struct type", 17)));
 }
return f139_set_t(n_1388, g552);
 }
int64_t nf_1396 = ((int64_t)(((*({ hrv *_t2035 = &(g531); int64_t _i2035 = si_1395; (S10*)_t2035->b + hr_ix(_i2035, _t2035->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:413"); }))).fnum_)); 
bool named_1397 = ((((x_1390).n_) > (((int32_t)0LL))) && ((((*({ hrv *_t2036 = &(g679); int64_t _i2036 = f90_kid(n_1388, ((int64_t)0LL)); (S4*)_t2036->b + hr_ix(_i2036, _t2036->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:414"); }))).s_) >= (((int32_t)0LL)))); 
int64_t fpos_1398 = ((int64_t)0LL); 
{ int32_t _e2038 = (x_1390).n_; for (int32_t _k2038 = 0; _k2038 < _e2038; _k2038++) { int32_t i_1399 = (int32_t)_k2038; int64_t fi_1400 = f90_kid(n_1388, ((int64_t)(i_1399))); 
int64_t idx_1401 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
if (named_1397) { idx_1401 = f184_sfield(si_1395, ((int64_t)(((*({ hrv *_t2039 = &(g679); int64_t _i2039 = fi_1400; (S4*)_t2039->b + hr_ix(_i2039, _t2039->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:419"); }))).s_)));
if (((idx_1401) < (((int64_t)0LL)))) { hrv m_1402 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2043 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2041 = &(m_1402); hr_fs(_o2041, hr_str("no field ", 9)); hr_fs(_o2041, f10_nm(((int64_t)(((*({ hrv *_t2042 = &(g679); int64_t _i2042 = fi_1400; (S4*)_t2042->b + hr_ix(_i2042, _t2042->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:419"); }))).s_)))); hr_fs(_o2041, hr_str(" in ", 4)); hr_fs(_o2041, hr_sl(*hr_tmp(&_t2043, f162_tn(t_1393)))); }));
}
(void)(f108_cerr(fi_1400, hr_sl(m_1402)));
continue;
 }
 } else { while ((((fpos_1398) < (nf_1396)) && ((((*({ hrv *_t2045 = &(g532); int64_t _i2045 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2046 = &(g531); int64_t _i2046 = si_1395; (S10*)_t2046->b + hr_ix(_i2046, _t2046->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:420"); }))).f0_)) + (int64_t)fpos_1398)); (S11*)_t2045->b + hr_ix(_i2045, _t2045->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:420"); }))).ty_) < (((int32_t)0LL))))) { fpos_1398++;
 } _bk2044:; 
idx_1401 = fpos_1398;
fpos_1398++;
if (((idx_1401) >= (nf_1396))) { (void)(f108_cerr(fi_1400, hr_str("too many initializers", 21)));
continue;
 }
 }
int64_t ft_1403 = ((int64_t)(((*({ hrv *_t2047 = &(g532); int64_t _i2047 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2048 = &(g531); int64_t _i2048 = si_1395; (S10*)_t2048->b + hr_ix(_i2048, _t2048->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:421"); }))).f0_)) + (int64_t)idx_1401)); (S11*)_t2047->b + hr_ix(_i2047, _t2047->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:421"); }))).ty_)); 
(void)(f170_set_r(fi_1400, ((int64_t)5LL), idx_1401));
int64_t v_1404 = ((int64_t)(((*({ hrv *_t2049 = &(g679); int64_t _i2049 = fi_1400; (S4*)_t2049->b + hr_ix(_i2049, _t2049->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:423"); }))).a_)); 
(void)(f138_ck(v_1404, ft_1403));
(void)(f141_conv(v_1404, ft_1403));
 } } _bk2037:; 
{ int64_t _e2051 = nf_1396; for (int64_t _k2051 = 0; _k2051 < _e2051; _k2051++) { int64_t j_1405 = (int64_t)_k2051; S11 f_1406 = (*({ hrv *_t2052 = &(g532); int64_t _i2052 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2053 = &(g531); int64_t _i2053 = si_1395; (S10*)_t2053->b + hr_ix(_i2053, _t2053->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:427"); }))).f0_)) + (int64_t)j_1405)); (S11*)_t2052->b + hr_ix(_i2052, _t2052->n, "/home/anmire/ai/amni-lang/helium-fix/hc/calls.amni:427"); })); 
if ((((f_1406).ty_) < (((int32_t)0LL)))) { continue;
 }
bool given_1407 = false; 
{ int32_t _e2055 = (x_1390).n_; for (int32_t _k2055 = 0; _k2055 < _e2055; _k2055++) { int32_t i_1408 = (int32_t)_k2055; if (((f158_rv(f90_kid(n_1388, ((int64_t)(i_1408))))) == (j_1405))) { given_1407 = true;
 }
 } } _bk2054:; 
if (((!(given_1407)) && (((f_1406).def_) >= (((int32_t)0LL))))) { int64_t sa_1409 = g384; 
g384 = g386;
(void)(f138_ck(((int64_t)((f_1406).def_)), ((int64_t)((f_1406).ty_))));
(void)(f141_conv(((int64_t)((f_1406).def_)), ((int64_t)((f_1406).ty_))));
g384 = sa_1409;
 }
if (((((!(given_1407)) && (((f_1406).def_) < (((int32_t)0LL)))) && ((((uint16_t)((uint64_t)(x_1390).fl_ & (uint64_t)((uint16_t)1LL)))) == (((uint16_t)0LL)))) && (!(f166_is_opt(((int64_t)((f_1406).ty_))))))) { hrv m_1410 __attribute__((cleanup(hr_rdrop))) = ((hrv){0}); 
{ hrv _t2058 __attribute__((cleanup(hr_rdrop))) = {0}; (void)(({ hrv *_o2057 = &(m_1410); hr_fs(_o2057, hr_str("missing field ", 14)); hr_fs(_o2057, f10_nm(((int64_t)((f_1406).name_)))); hr_fs(_o2057, hr_str(" in ", 4)); hr_fs(_o2057, hr_sl(*hr_tmp(&_t2058, f162_tn(t_1393)))); }));
}
(void)(f108_cerr(n_1388, hr_sl(m_1410)));
 }
 } } _bk2050:; 
(void)(f170_set_r(n_1388, ((int64_t)9LL), si_1395));
return f139_set_t(n_1388, t_1393);
}
static bool f245_ORD_HAS(int64_t d_1412) {
{ hrv *_v2060 = &(g392); for (int64_t _k2060 = 0; _k2060 < _v2060->n; _k2060++) { int32_t o_1413 = ((int32_t*)_v2060->b)[_k2060]; if (((((int64_t)(o_1413))) == (d_1412))) { return true;
 }
 } } _bk2059:; 
return false;
}
static bool f246_gen_program(hrv* out_1418) {
(void)(({ hrv *_v2061 = &(g163); _v2061->n = 0; }));
{ hrv *_v2063 = &(g392); for (int64_t _k2063 = 0; _k2063 < _v2063->n; _k2063++) { int32_t d_1419 = ((int32_t*)_v2063->b)[_k2063]; int64_t di_1420 = ((int64_t)(d_1419)); 
int64_t t_1421 = ((int64_t)((*({ hrv *_t2064 = &(g428); int64_t _i2064 = di_1420; (int32_t*)_t2064->b + hr_ix(_i2064, _t2064->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1067"); })))); 
int64_t g_1422 = ((int64_t)(((*({ hrv *_t2065 = &(g466); int64_t _i2065 = di_1420; (S5*)_t2065->b + hr_ix(_i2065, _t2065->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1068"); }))).node_)); 
if ((((f172_const_of(di_1420)) >= (((int64_t)0LL))) && ((((*({ hrv *_t2066 = &(g528); int64_t _i2066 = t_1421; (S1*)_t2066->b + hr_ix(_i2066, _t2066->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1069"); }))).k_) == (((uint8_t)12LL))))) { continue;
 }
int64_t sv_1423 = (g163).n; 
g384 = g386;
g179 = g386;
(void)(f247_ow(hr_str("static ", 7)));
(void)(f248_ct(t_1421));
(void)(({ hrv *_o2067 = &(g163); hr_fs(_o2067, hr_str(" g", 2)); hr_fi(_o2067, di_1420); hr_fs(_o2067, hr_str(";\012", 2)); }));
(void)(({ hrv *_v2068 = &(g167); hsl _s2068 = ({ hsl _t2069 = hr_sl(g163); int64_t _l2069 = sv_1423, _h2069 = _t2069.n; if (_l2069 < 0 || _h2069 < _l2069 || _h2069 > _t2069.n) hr_slerr(_l2069, _h2069, _t2069.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1073"); (hsl){ _t2069.p + _l2069 * (int64_t)sizeof(uint8_t), _h2069 - _l2069 }; }); hr_append(_v2068, _s2068.p, _s2068.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2070 = &(g163); int64_t _k2070 = sv_1423; if (_k2070 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1073"); hr_resize(_v2070, _k2070, sizeof(uint8_t)); }));
S4 x_1464 = (*({ hrv *_t2071 = &(g679); int64_t _i2071 = g_1422; (S4*)_t2071->b + hr_ix(_i2071, _t2071->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1074"); })); 
if ((((x_1464).b_) >= (((int32_t)0LL)))) { int64_t iv_1465 = f90_kid(((int64_t)((x_1464).b_)), ((int64_t)0LL)); 
int64_t sp_1466 = (g163).n; 
(void)(({ hrv *_o2072 = &(g163); hr_fs(_o2072, hr_str("g", 1)); hr_fi(_o2072, di_1420); hr_fs(_o2072, hr_str(" = ", 3)); }));
if (f255_is_res(t_1421)) { (void)(f256_gxo(iv_1465));
 } else { (void)(f276_gx(iv_1465));
 }
(void)(f247_ow(hr_str(";\012", 2)));
if ((((g176).n) > (((int64_t)0LL)))) { (void)(({ hrv *_v2073 = &(g177); _v2073->n = 0; }));
(void)(({ hrv *_v2074 = &(g177); hsl _s2074 = ({ hsl _t2075 = hr_sl(g163); int64_t _l2075 = sp_1466, _h2075 = _t2075.n; if (_l2075 < 0 || _h2075 < _l2075 || _h2075 > _t2075.n) hr_slerr(_l2075, _h2075, _t2075.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1081"); (hsl){ _t2075.p + _l2075 * (int64_t)sizeof(uint8_t), _h2075 - _l2075 }; }); hr_append(_v2074, _s2074.p, _s2074.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2076 = &(g163); int64_t _k2076 = sp_1466; if (_k2076 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1081"); hr_resize(_v2076, _k2076, sizeof(uint8_t)); }));
(void)(f247_ow(hr_str("{ ", 2)));
(void)(({ hrv *_v2077 = &(g163); hsl _s2077 = ({ hsl _t2078 = hr_sl(g176); int64_t _l2078 = 0, _h2078 = _t2078.n; if (_l2078 < 0 || _h2078 < _l2078 || _h2078 > _t2078.n) hr_slerr(_l2078, _h2078, _t2078.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1081"); (hsl){ _t2078.p + _l2078 * (int64_t)sizeof(uint8_t), _h2078 - _l2078 }; }); hr_append(_v2077, _s2077.p, _s2077.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2079 = &(g176); _v2079->n = 0; }));
(void)(({ hrv *_v2080 = &(g163); hsl _s2080 = ({ hsl _t2081 = hr_sl(g177); int64_t _l2081 = 0, _h2081 = _t2081.n; if (_l2081 < 0 || _h2081 < _l2081 || _h2081 > _t2081.n) hr_slerr(_l2081, _h2081, _t2081.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1081"); (hsl){ _t2081.p + _l2081 * (int64_t)sizeof(uint8_t), _h2081 - _l2081 }; }); hr_append(_v2080, _s2080.p, _s2080.n, sizeof(uint8_t)); }));
(void)(f247_ow(hr_str("}\012", 2)));
 }
(void)(({ hrv *_v2082 = &(g168); hsl _s2082 = ({ hsl _t2083 = hr_sl(g163); int64_t _l2083 = sp_1466, _h2083 = _t2083.n; if (_l2083 < 0 || _h2083 < _l2083 || _h2083 > _t2083.n) hr_slerr(_l2083, _h2083, _t2083.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1082"); (hsl){ _t2083.p + _l2083 * (int64_t)sizeof(uint8_t), _h2083 - _l2083 }; }); hr_append(_v2082, _s2082.p, _s2082.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2084 = &(g163); int64_t _k2084 = sp_1466; if (_k2084 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1082"); hr_resize(_v2084, _k2084, sizeof(uint8_t)); }));
 }
 } } _bk2062:; 
int64_t mi_1973 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ hrv *_v2086 = &(g373); for (int64_t _k2086 = 0; _k2086 < _v2086->n; _k2086++) { S6 f_1974 = ((S6*)_v2086->b)[_k2086]; int64_t i_1975 = (int64_t)_k2086; if (((((f_1974).node_) < (((int32_t)0LL))) || (((f_1974).st_) != (((uint8_t)2LL))))) { continue;
 }
int64_t node_1976 = ((int64_t)((f_1974).node_)); 
if ((((((*({ hrv *_t2087 = &(g679); int64_t _i2087 = node_1976; (S4*)_t2087->b + hr_ix(_i2087, _t2087->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1089"); }))).k_) != (((uint8_t)50LL))) || ((((uint16_t)((uint64_t)((*({ hrv *_t2088 = &(g679); int64_t _i2088 = node_1976; (S4*)_t2088->b + hr_ix(_i2088, _t2088->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1089"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))))) { continue;
 }
if (((((f_1974).par_) < (((int32_t)0LL))) && hr_streq(f10_nm(((int64_t)((f_1974).name_))), hr_str("main", 4)))) { mi_1973 = i_1975;
 }
(void)(f345_gen_fn(i_1975));
if ((((g182).n) > (((int64_t)0LL)))) { return false;
 }
 } } _bk2085:; 
(void)(({ hrv *_v2089 = out_1418; hsl _s2089 = hr_str("#include \"hrt.h\"\012", 17); hr_append(_v2089, _s2089.p, _s2089.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2090 = out_1418; hsl _s2090 = hr_sl(g164); hr_append(_v2090, _s2090.p, _s2090.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2091 = out_1418; hsl _s2091 = hr_str("#pragma pack(push, 1)\012", 22); hr_append(_v2091, _s2091.p, _s2091.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2092 = out_1418; hsl _s2092 = hr_sl(g165); hr_append(_v2092, _s2092.p, _s2092.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2093 = out_1418; hsl _s2093 = hr_str("#pragma pack(pop)\012", 18); hr_append(_v2093, _s2093.p, _s2093.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2094 = out_1418; hsl _s2094 = hr_sl(g166); hr_append(_v2094, _s2094.p, _s2094.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2095 = out_1418; hsl _s2095 = hr_sl(g167); hr_append(_v2095, _s2095.p, _s2095.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2096 = out_1418; hsl _s2096 = ({ hsl _t2097 = hr_sl(g169); int64_t _l2097 = 0, _h2097 = _t2097.n; if (_l2097 < 0 || _h2097 < _l2097 || _h2097 > _t2097.n) hr_slerr(_l2097, _h2097, _t2097.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1101"); (hsl){ _t2097.p + _l2097 * (int64_t)sizeof(uint8_t), _h2097 - _l2097 }; }); hr_append(_v2096, _s2096.p, _s2096.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2098 = out_1418; hsl _s2098 = ({ hsl _t2099 = hr_sl(g163); int64_t _l2099 = 0, _h2099 = _t2099.n; if (_l2099 < 0 || _h2099 < _l2099 || _h2099 > _t2099.n) hr_slerr(_l2099, _h2099, _t2099.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1102"); (hsl){ _t2099.p + _l2099 * (int64_t)sizeof(uint8_t), _h2099 - _l2099 }; }); hr_append(_v2098, _s2098.p, _s2098.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2100 = out_1418; hsl _s2100 = hr_str("static void hr_init_globals(void) {\012", 36); hr_append(_v2100, _s2100.p, _s2100.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2101 = out_1418; hsl _s2101 = hr_sl(g168); hr_append(_v2101, _s2101.p, _s2101.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2102 = out_1418; hsl _s2102 = hr_str("}\012", 2); hr_append(_v2102, _s2102.p, _s2102.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2103 = out_1418; hsl _s2103 = hr_str("static void hr_main(void) { ", 28); hr_append(_v2103, _s2103.p, _s2103.n, sizeof(uint8_t)); }));
if (((mi_1973) >= (((int64_t)0LL)))) { int64_t rt_2000 = ((int64_t)(((*({ hrv *_t2104 = &(g373); int64_t _i2104 = mi_1973; (S6*)_t2104->b + hr_ix(_i2104, _t2104->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1105"); }))).ret_)); 
if ((((rt_2000) >= (((int64_t)0LL))) && ((((*({ hrv *_t2105 = &(g528); int64_t _i2105 = rt_2000; (S1*)_t2105->b + hr_ix(_i2105, _t2105->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1105"); }))).k_) == (((uint8_t)3LL))))) { (void)(({ hrv *_v2106 = out_1418; hsl _s2106 = hr_str("hr_flush(); exit((int)", 22); hr_append(_v2106, _s2106.p, _s2106.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v2107 = &(g163); _v2107->n = 0; }));
(void)(f342_fn_cname(mi_1973));
(void)(({ hrv *_v2108 = out_1418; hsl _s2108 = ({ hsl _t2109 = hr_sl(g163); int64_t _l2109 = 0, _h2109 = _t2109.n; if (_l2109 < 0 || _h2109 < _l2109 || _h2109 > _t2109.n) hr_slerr(_l2109, _h2109, _t2109.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1105"); (hsl){ _t2109.p + _l2109 * (int64_t)sizeof(uint8_t), _h2109 - _l2109 }; }); hr_append(_v2108, _s2108.p, _s2108.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2110 = out_1418; hsl _s2110 = hr_str("()", 2); hr_append(_v2110, _s2110.p, _s2110.n, sizeof(uint8_t)); }));
if ((((rt_2000) >= (((int64_t)0LL))) && ((((*({ hrv *_t2111 = &(g528); int64_t _i2111 = rt_2000; (S1*)_t2111->b + hr_ix(_i2111, _t2111->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1105"); }))).k_) == (((uint8_t)3LL))))) { (void)(({ hrv *_v2112 = out_1418; hsl _s2112 = hr_str(")", 1); hr_append(_v2112, _s2112.p, _s2112.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v2113 = out_1418; hsl _s2113 = hr_str("; ", 2); hr_append(_v2113, _s2113.p, _s2113.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v2114 = out_1418; hsl _s2114 = hr_str("}\012", 2); hr_append(_v2114, _s2114.p, _s2114.n, sizeof(uint8_t)); }));
return (((g182).n) == (((int64_t)0LL)));
}
static void f247_ow(hsl s_1424) {
(void)(({ hrv *_v2115 = &(g163); hsl _s2115 = s_1424; hr_append(_v2115, _s2115.p, _s2115.n, sizeof(uint8_t)); }));
}
static void f248_ct(int64_t t_1425) {
(void)(f249_cbody(t_1425));
(void)(f247_ow(f251_cn(t_1425)));
}
static void f249_cbody(int64_t t_1426) {
(void)(f250_cn_grow());
S1 x_1427 = (*({ hrv *_t2116 = &(g528); int64_t _i2116 = t_1426; (S1*)_t2116->b + hr_ix(_i2116, _t2116->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:51"); })); 
int64_t k_1428 = ((int64_t)((x_1427).k_)); 
if ((((k_1428) == (((int64_t)10LL))) || (((*({ hrv *_t2117 = &(g173); int64_t _i2117 = t_1426; (uint8_t*)_t2117->b + hr_ix(_i2117, _t2117->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:52"); }))) != (((uint8_t)0LL))))) { (void)(f251_cn(t_1426));
return;
 }
{ uint8_t *_t2118 = &((*({ hrv *_t2119 = &(g173); int64_t _i2119 = t_1426; (uint8_t*)_t2119->b + hr_ix(_i2119, _t2119->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:53"); }))); *_t2118 = ((uint8_t)1LL); }
(void)(f251_cn(t_1426));
if (((k_1428) == (((int64_t)7LL)))) { S9 v_1442 = (*({ hrv *_t2120 = &(g534); int64_t _i2120 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2121 = &(g533); int64_t _i2121 = (x_1427).a_; (S8*)_t2121->b + hr_ix(_i2121, _t2121->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:55"); }))).v0_)) + (int64_t)((int64_t)((x_1427).c_)))); (S9*)_t2120->b + hr_ix(_i2120, _t2120->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:55"); })); 
if ((((v_1442).si_) >= (((int32_t)0LL)))) { (void)(f249_cbody(f135_t_struct(((int64_t)((v_1442).si_)))));
 }
return;
 }
if (((k_1428) == (((int64_t)5LL)))) { int64_t si_1443 = ((int64_t)((x_1427).a_)); 
(void)(f144_si_layout(si_1443));
int64_t f0_1444 = ((int64_t)(((*({ hrv *_t2122 = &(g531); int64_t _i2122 = si_1443; (S10*)_t2122->b + hr_ix(_i2122, _t2122->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:58"); }))).f0_)); 
int64_t fnum_1445 = ((int64_t)(((*({ hrv *_t2123 = &(g531); int64_t _i2123 = si_1443; (S10*)_t2123->b + hr_ix(_i2123, _t2123->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:58"); }))).fnum_)); 
{ int64_t _e2125 = fnum_1445; for (int64_t _k2125 = 0; _k2125 < _e2125; _k2125++) { int64_t i_1446 = (int64_t)_k2125; int32_t ft_1447 = ((*({ hrv *_t2126 = &(g532); int64_t _i2126 = ((int64_t)((int64_t)f0_1444 + (int64_t)i_1446)); (S11*)_t2126->b + hr_ix(_i2126, _t2126->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:59"); }))).ty_; 
if (((ft_1447) >= (((int32_t)0LL)))) { (void)(f249_cbody(((int64_t)(ft_1447))));
 }
 } } _bk2124:; 
(void)(({ hrv *_v2127 = &(g165); hsl _s2127 = hr_str("struct ", 7); hr_append(_v2127, _s2127.p, _s2127.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2128 = &(g165); hsl _s2128 = f251_cn(t_1426); hr_append(_v2128, _s2128.p, _s2128.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2129 = &(g165); hsl _s2129 = hr_str(" { ", 3); hr_append(_v2129, _s2129.p, _s2129.n, sizeof(uint8_t)); }));
bool any_1448 = false; 
{ int64_t _e2131 = fnum_1445; for (int64_t _k2131 = 0; _k2131 < _e2131; _k2131++) { int64_t i_1449 = (int64_t)_k2131; S11 f_1450 = (*({ hrv *_t2132 = &(g532); int64_t _i2132 = ((int64_t)((int64_t)f0_1444 + (int64_t)i_1449)); (S11*)_t2132->b + hr_ix(_i2132, _t2132->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:63"); })); 
if ((((f_1450).ty_) < (((int32_t)0LL)))) { if ((((f_1450).padn_) > (((int32_t)0LL)))) { (void)(({ hrv *_o2133 = &(g165); hr_fs(_o2133, hr_str("uint8_t _p", 10)); hr_fi(_o2133, i_1449); hr_fs(_o2133, hr_str("[", 1)); hr_fi(_o2133, (f_1450).padn_); hr_fs(_o2133, hr_str("]; ", 3)); }));
any_1448 = true;
 }
continue;
 }
(void)(({ hrv *_v2134 = &(g165); hsl _s2134 = f251_cn(((int64_t)((f_1450).ty_))); hr_append(_v2134, _s2134.p, _s2134.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2135 = &(g165); uint8_t _x2135 = ((uint8_t)32LL); uint8_t *_p2135 = (uint8_t*)hr_grow(_v2135, 1, sizeof _x2135); *_p2135 = _x2135; _p2135; }));
(void)(f254_fname_into((&(g165)), ((int64_t)((f_1450).name_))));
(void)(({ hrv *_v2136 = &(g165); hsl _s2136 = hr_str("; ", 2); hr_append(_v2136, _s2136.p, _s2136.n, sizeof(uint8_t)); }));
any_1448 = true;
 } } _bk2130:; 
if ((!(any_1448))) { (void)(({ hrv *_v2137 = &(g165); hsl _s2137 = hr_str("uint8_t _e; ", 12); hr_append(_v2137, _s2137.p, _s2137.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v2138 = &(g165); hsl _s2138 = hr_str("};\012", 3); hr_append(_v2138, _s2138.p, _s2138.n, sizeof(uint8_t)); }));
return;
 }
if (((k_1428) == (((int64_t)6LL)))) { int64_t ei_1454 = ((int64_t)((x_1427).a_)); 
(void)(f147_ei_layout(ei_1454));
int64_t v0_1455 = ((int64_t)(((*({ hrv *_t2139 = &(g533); int64_t _i2139 = ei_1454; (S8*)_t2139->b + hr_ix(_i2139, _t2139->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:73"); }))).v0_)); 
bool pay_1456 = false; 
{ int32_t _e2141 = ((*({ hrv *_t2142 = &(g533); int64_t _i2142 = ei_1454; (S8*)_t2142->b + hr_ix(_i2142, _t2142->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:75"); }))).vnum_; for (int32_t _k2141 = 0; _k2141 < _e2141; _k2141++) { int32_t i_1457 = (int32_t)_k2141; S9 v_1458 = (*({ hrv *_t2143 = &(g534); int64_t _i2143 = ((int64_t)((int64_t)v0_1455 + (int64_t)((int64_t)(i_1457)))); (S9*)_t2143->b + hr_ix(_i2143, _t2143->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:75"); })); 
if (((((v_1458).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t2144 = &(g531); int64_t _i2144 = (v_1458).si_; (S10*)_t2144->b + hr_ix(_i2144, _t2144->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:75"); }))).zero_)))) { (void)(f249_cbody(f135_t_struct(((int64_t)((v_1458).si_)))));
pay_1456 = true;
 }
 } } _bk2140:; 
(void)(({ hrv *_v2145 = &(g165); hsl _s2145 = hr_str("struct ", 7); hr_append(_v2145, _s2145.p, _s2145.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2146 = &(g165); hsl _s2146 = f251_cn(t_1426); hr_append(_v2146, _s2146.p, _s2146.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2147 = &(g165); hsl _s2147 = ({ hsl _r2148; if (((((*({ hrv *_t2149 = &(g533); int64_t _i2149 = ei_1454; (S8*)_t2149->b + hr_ix(_i2149, _t2149->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:76"); }))).tagsz_) == (((uint8_t)1LL)))) { _r2148 = hr_str(" { uint8_t tag; ", 16);  } else { _r2148 = hr_str(" { uint16_t tag; ", 17);  } _r2148; }); hr_append(_v2147, _s2147.p, _s2147.n, sizeof(uint8_t)); }));
if (pay_1456) { (void)(({ hrv *_v2150 = &(g165); hsl _s2150 = hr_str("union { ", 8); hr_append(_v2150, _s2150.p, _s2150.n, sizeof(uint8_t)); }));
{ int32_t _e2152 = ((*({ hrv *_t2153 = &(g533); int64_t _i2153 = ei_1454; (S8*)_t2153->b + hr_ix(_i2153, _t2153->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:77"); }))).vnum_; for (int32_t _k2152 = 0; _k2152 < _e2152; _k2152++) { int32_t i_1459 = (int32_t)_k2152; S9 v_1460 = (*({ hrv *_t2154 = &(g534); int64_t _i2154 = ((int64_t)((int64_t)v0_1455 + (int64_t)((int64_t)(i_1459)))); (S9*)_t2154->b + hr_ix(_i2154, _t2154->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:77"); })); 
if (((((v_1460).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t2155 = &(g531); int64_t _i2155 = (v_1460).si_; (S10*)_t2155->b + hr_ix(_i2155, _t2155->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:77"); }))).zero_)))) { (void)(({ hrv *_v2156 = &(g165); hsl _s2156 = f251_cn(f135_t_struct(((int64_t)((v_1460).si_)))); hr_append(_v2156, _s2156.p, _s2156.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o2157 = &(g165); hr_fs(_o2157, hr_str(" v", 2)); hr_fi(_o2157, i_1459); hr_fs(_o2157, hr_str("; ", 2)); }));
 }
 } } _bk2151:; 
(void)(({ hrv *_v2158 = &(g165); hsl _s2158 = hr_str("} u; ", 5); hr_append(_v2158, _s2158.p, _s2158.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v2159 = &(g165); hsl _s2159 = hr_str("};\012", 3); hr_append(_v2159, _s2159.p, _s2159.n, sizeof(uint8_t)); }));
return;
 }
if (((k_1428) == (((int64_t)8LL)))) { int64_t a_1461 = ((int64_t)((x_1427).s_)); 
if ((((a_1461) == (((int64_t)1LL))) || (((a_1461) == (((int64_t)3LL))) && (((x_1427).b_) >= (((int64_t)0LL)))))) { (void)(f249_cbody(((int64_t)((x_1427).a_))));
(void)(({ hrv *_v2160 = &(g165); hsl _s2160 = hr_str("struct ", 7); hr_append(_v2160, _s2160.p, _s2160.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2161 = &(g165); hsl _s2161 = f251_cn(t_1426); hr_append(_v2161, _s2161.p, _s2161.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2162 = &(g165); hsl _s2162 = hr_str(" { ", 3); hr_append(_v2162, _s2162.p, _s2162.n, sizeof(uint8_t)); }));
if (((a_1461) == (((int64_t)3LL)))) { (void)(({ hrv *_v2163 = &(g165); hsl _s2163 = (g183).e[hr_ix(((int64_t)((int64_t)f124_lim_lenstore((x_1427).b_) & (int64_t)((int64_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:86")]; hr_append(_v2163, _s2163.p, _s2163.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2165 = &(g165); hsl _s2165 = hr_str(" n; ", 4); hr_append(_v2165, _s2165.p, _s2165.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v2166 = &(g165); hsl _s2166 = f251_cn(((int64_t)((x_1427).a_))); hr_append(_v2166, _s2166.p, _s2166.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o2167 = &(g165); hr_fs(_o2167, hr_str(" e[", 3)); hr_fi(_o2167, f103_max((x_1427).b_, ((int64_t)1LL))); hr_fs(_o2167, hr_str("]; };\012", 6)); }));
 }
return;
 }
if (((k_1428) == (((int64_t)14LL)))) { { int32_t _e2169 = (x_1427).n_; for (int32_t _k2169 = 0; _k2169 < _e2169; _k2169++) { int32_t i_1462 = (int32_t)_k2169; (void)(f249_cbody(((int64_t)((*({ hrv *_t2170 = &(g529); int64_t _i2170 = ((int64_t)((int64_t)((int64_t)((x_1427).l_)) + (int64_t)((int64_t)(i_1462)))); (int32_t*)_t2170->b + hr_ix(_i2170, _t2170->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:92"); }))))));
 } } _bk2168:; 
(void)(({ hrv *_v2171 = &(g165); hsl _s2171 = hr_str("struct ", 7); hr_append(_v2171, _s2171.p, _s2171.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2172 = &(g165); hsl _s2172 = f251_cn(t_1426); hr_append(_v2172, _s2172.p, _s2172.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2173 = &(g165); hsl _s2173 = hr_str(" { ", 3); hr_append(_v2173, _s2173.p, _s2173.n, sizeof(uint8_t)); }));
{ int32_t _e2175 = (x_1427).n_; for (int32_t _k2175 = 0; _k2175 < _e2175; _k2175++) { int32_t i_1463 = (int32_t)_k2175; (void)(({ hrv *_v2176 = &(g165); hsl _s2176 = f251_cn(((int64_t)((*({ hrv *_t2177 = &(g529); int64_t _i2177 = ((int64_t)((int64_t)((int64_t)((x_1427).l_)) + (int64_t)((int64_t)(i_1463)))); (int32_t*)_t2177->b + hr_ix(_i2177, _t2177->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:94"); }))))); hr_append(_v2176, _s2176.p, _s2176.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o2178 = &(g165); hr_fs(_o2178, hr_str(" r", 2)); hr_fi(_o2178, i_1463); hr_fs(_o2178, hr_str("; ", 2)); }));
 } } _bk2174:; 
(void)(({ hrv *_v2179 = &(g165); hsl _s2179 = hr_str("};\012", 3); hr_append(_v2179, _s2179.p, _s2179.n, sizeof(uint8_t)); }));
 }
}
static void f250_cn_grow(void) {
while ((((g171).n) < ((g528).n))) { (void)(({ hrv *_v2181 = &(g171); int32_t _x2181 = ((int32_t)(0 - (uint64_t)(((int32_t)1LL)))); int32_t *_p2181 = (int32_t*)hr_grow(_v2181, 1, sizeof _x2181); *_p2181 = _x2181; _p2181; }));
(void)(({ hrv *_v2182 = &(g172); int32_t _x2182 = ((int32_t)0LL); int32_t *_p2182 = (int32_t*)hr_grow(_v2182, 1, sizeof _x2182); *_p2182 = _x2182; _p2182; }));
(void)(({ hrv *_v2183 = &(g173); uint8_t _x2183 = ((uint8_t)0LL); uint8_t *_p2183 = (uint8_t*)hr_grow(_v2183, 1, sizeof _x2183); *_p2183 = _x2183; _p2183; }));
(void)(({ hrv *_v2184 = &(g174); uint8_t _x2184 = ((uint8_t)0LL); uint8_t *_p2184 = (uint8_t*)hr_grow(_v2184, 1, sizeof _x2184); *_p2184 = _x2184; _p2184; }));
(void)(({ hrv *_v2185 = &(g175); uint8_t _x2185 = ((uint8_t)0LL); uint8_t *_p2185 = (uint8_t*)hr_grow(_v2185, 1, sizeof _x2185); *_p2185 = _x2185; _p2185; }));
 } _bk2180:; 
}
static hsl f251_cn(int64_t t_1429) {
(void)(f250_cn_grow());
if ((((*({ hrv *_t2186 = &(g171); int64_t _i2186 = t_1429; (int32_t*)_t2186->b + hr_ix(_i2186, _t2186->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:23"); }))) < (((int32_t)0LL)))) { (void)(f252_cn_make(t_1429));
 }
int64_t o_1441 = ((int64_t)((*({ hrv *_t2187 = &(g171); int64_t _i2187 = t_1429; (int32_t*)_t2187->b + hr_ix(_i2187, _t2187->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:24"); })))); 
return ({ hsl _t2188 = hr_sl(g170); int64_t _l2188 = o_1441, _h2188 = ((int64_t)((int64_t)o_1441 + (int64_t)((int64_t)((*({ hrv *_t2189 = &(g172); int64_t _i2189 = t_1429; (int32_t*)_t2189->b + hr_ix(_i2189, _t2189->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:25"); })))))); if (_l2188 < 0 || _h2188 < _l2188 || _h2188 > _t2188.n) hr_slerr(_l2188, _h2188, _t2188.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:25"); (hsl){ _t2188.p + _l2188 * (int64_t)sizeof(uint8_t), _h2188 - _l2188 }; });
}
static void f252_cn_make(int64_t t_1430) {
S1 x_1431 = (*({ hrv *_t2190 = &(g528); int64_t _i2190 = t_1430; (S1*)_t2190->b + hr_ix(_i2190, _t2190->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:28"); })); 
int64_t k_1432 = ((int64_t)((x_1431).k_)); 
if ((((k_1432) == (((int64_t)10LL))) && (((x_1431).c_) < (((int32_t)0LL))))) { hsl e_1433 = f251_cn(((int64_t)((x_1431).a_))); 
int64_t s0_1434 = (g170).n; 
(void)(({ hrv *_v2191 = &(g170); hsl _s2191 = e_1433; hr_append(_v2191, _s2191.p, _s2191.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2192 = &(g170); uint8_t _x2192 = ((uint8_t)42LL); uint8_t *_p2192 = (uint8_t*)hr_grow(_v2192, 1, sizeof _x2192); *_p2192 = _x2192; _p2192; }));
{ int32_t *_t2193 = &((*({ hrv *_t2194 = &(g171); int64_t _i2194 = t_1430; (int32_t*)_t2194->b + hr_ix(_i2194, _t2194->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:29"); }))); *_t2193 = ((int32_t)(s0_1434)); }
{ int32_t *_t2195 = &((*({ hrv *_t2196 = &(g172); int64_t _i2196 = t_1430; (int32_t*)_t2196->b + hr_ix(_i2196, _t2196->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:29"); }))); *_t2195 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1434)))); }
return;
 }
if (((k_1432) == (((int64_t)7LL)))) { S9 v_1435 = (*({ hrv *_t2197 = &(g534); int64_t _i2197 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2198 = &(g533); int64_t _i2198 = (x_1431).a_; (S8*)_t2198->b + hr_ix(_i2198, _t2198->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:30"); }))).v0_)) + (int64_t)((int64_t)((x_1431).c_)))); (S9*)_t2197->b + hr_ix(_i2197, _t2197->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:30"); })); 
if ((((v_1435).si_) >= (((int32_t)0LL)))) { hsl e_1436 = f251_cn(f135_t_struct(((int64_t)((v_1435).si_)))); 
int64_t s0_1437 = (g170).n; 
(void)(({ hrv *_v2199 = &(g170); hsl _s2199 = e_1436; hr_append(_v2199, _s2199.p, _s2199.n, sizeof(uint8_t)); }));
{ int32_t *_t2200 = &((*({ hrv *_t2201 = &(g171); int64_t _i2201 = t_1430; (int32_t*)_t2201->b + hr_ix(_i2201, _t2201->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:30"); }))); *_t2200 = ((int32_t)(s0_1437)); }
{ int32_t *_t2202 = &((*({ hrv *_t2203 = &(g172); int64_t _i2203 = t_1430; (int32_t*)_t2203->b + hr_ix(_i2203, _t2203->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:30"); }))); *_t2202 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1437)))); }
return;
 }
 }
int64_t s0_1438 = (g170).n; 
if (((k_1432) == (((int64_t)3LL)))) { (void)(({ hrv *_v2204 = &(g170); hsl _s2204 = (g183).e[hr_ix(((uint8_t)((uint64_t)(x_1431).s_ & (uint64_t)((uint8_t)7LL))), 8, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:32")]; hr_append(_v2204, _s2204.p, _s2204.n, sizeof(uint8_t)); }));
 } else { if (((k_1432) == (((int64_t)10LL)))) { (void)(({ hrv *_v2206 = &(g170); hsl _s2206 = (g183).e[hr_ix(((int32_t)((int64_t)((int32_t)((int64_t)(x_1431).c_ & (int64_t)((int32_t)3LL))) + (int64_t)((int32_t)4LL))), 8, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:33")]; hr_append(_v2206, _s2206.p, _s2206.n, sizeof(uint8_t)); }));
 } else { if (((k_1432) == (((int64_t)2LL)))) { (void)(({ hrv *_v2208 = &(g170); hsl _s2208 = hr_str("bool", 4); hr_append(_v2208, _s2208.p, _s2208.n, sizeof(uint8_t)); }));
 } else { if (((k_1432) == (((int64_t)4LL)))) { (void)(({ hrv *_v2209 = &(g170); hsl _s2209 = ({ hsl _r2210; if ((((x_1431).s_) == (((uint8_t)4LL)))) { _r2210 = hr_str("float", 5);  } else { _r2210 = hr_str("double", 6);  } _r2210; }); hr_append(_v2209, _s2209.p, _s2209.n, sizeof(uint8_t)); }));
 } else { if (((k_1432) == (((int64_t)1LL)))) { (void)(({ hrv *_v2211 = &(g170); hsl _s2211 = hr_str("void", 4); hr_append(_v2211, _s2211.p, _s2211.n, sizeof(uint8_t)); }));
 } else { if (((k_1432) == (((int64_t)5LL)))) { (void)(({ hrv *_o2212 = &(g170); hr_fs(_o2212, hr_str("S", 1)); hr_fi(_o2212, (x_1431).a_); }));
(void)(f253_fwd(s0_1438));
 } else { if (((k_1432) == (((int64_t)6LL)))) { (void)(({ hrv *_o2213 = &(g170); hr_fs(_o2213, hr_str("E", 1)); hr_fi(_o2213, (x_1431).a_); }));
(void)(f253_fwd(s0_1438));
 } else { if (((k_1432) == (((int64_t)7LL)))) { (void)(({ hrv *_v2214 = &(g170); hsl _s2214 = hr_str("hr_unit", 7); hr_append(_v2214, _s2214.p, _s2214.n, sizeof(uint8_t)); }));
 } else { if (((k_1432) == (((int64_t)8LL)))) { int64_t a_1440 = ((int64_t)((x_1431).s_)); 
if ((((a_1440) == (((int64_t)4LL))) || ((a_1440) == (((int64_t)5LL))))) { (void)(({ hrv *_v2215 = &(g170); hsl _s2215 = hr_str("hrv", 3); hr_append(_v2215, _s2215.p, _s2215.n, sizeof(uint8_t)); }));
 } else { if (((a_1440) == (((int64_t)1LL)))) { (void)(({ hrv *_o2216 = &(g170); hr_fs(_o2216, hr_str("A", 1)); hr_fi(_o2216, t_1430); }));
(void)(f253_fwd(s0_1438));
 } else { if ((((a_1440) == (((int64_t)3LL))) && (((x_1431).b_) >= (((int64_t)0LL))))) { (void)(({ hrv *_o2217 = &(g170); hr_fs(_o2217, hr_str("L", 1)); hr_fi(_o2217, t_1430); }));
(void)(f253_fwd(s0_1438));
 } else { (void)(({ hrv *_v2218 = &(g170); hsl _s2218 = hr_str("uint8_t*", 8); hr_append(_v2218, _s2218.p, _s2218.n, sizeof(uint8_t)); }));
 }
 }
 }
 } else { if (((((k_1432) == (((int64_t)9LL))) || ((k_1432) == (((int64_t)18LL)))) || ((k_1432) == (((int64_t)19LL))))) { (void)(({ hrv *_v2219 = &(g170); hsl _s2219 = hr_str("hsl", 3); hr_append(_v2219, _s2219.p, _s2219.n, sizeof(uint8_t)); }));
 } else { if (((k_1432) == (((int64_t)14LL)))) { (void)(({ hrv *_o2220 = &(g170); hr_fs(_o2220, hr_str("M", 1)); hr_fi(_o2220, t_1430); }));
(void)(f253_fwd(s0_1438));
 } else { if ((((k_1432) == (((int64_t)12LL))) || ((k_1432) == (((int64_t)17LL))))) { (void)(({ hrv *_v2221 = &(g170); hsl _s2221 = hr_str("int64_t", 7); hr_append(_v2221, _s2221.p, _s2221.n, sizeof(uint8_t)); }));
 } else { if (((k_1432) == (((int64_t)13LL)))) { (void)(({ hrv *_v2222 = &(g170); hsl _s2222 = hr_str("double", 6); hr_append(_v2222, _s2222.p, _s2222.n, sizeof(uint8_t)); }));
 } else { (void)(({ hrv *_v2223 = &(g170); hsl _s2223 = hr_str("void*", 5); hr_append(_v2223, _s2223.p, _s2223.n, sizeof(uint8_t)); }));
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
{ int32_t *_t2224 = &((*({ hrv *_t2225 = &(g171); int64_t _i2225 = t_1430; (int32_t*)_t2225->b + hr_ix(_i2225, _t2225->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:46"); }))); *_t2224 = ((int32_t)(s0_1438)); }
{ int32_t *_t2226 = &((*({ hrv *_t2227 = &(g172); int64_t _i2227 = t_1430; (int32_t*)_t2227->b + hr_ix(_i2227, _t2227->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:46"); }))); *_t2226 = ((int32_t)(((int64_t)((int64_t)(g170).n - (int64_t)s0_1438)))); }
}
static void f253_fwd(int64_t s0_1439) {
(void)(({ hrv *_v2228 = &(g164); hsl _s2228 = hr_str("typedef struct ", 15); hr_append(_v2228, _s2228.p, _s2228.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2229 = &(g164); hsl _s2229 = ({ hsl _t2230 = hr_sl(g170); int64_t _l2230 = s0_1439, _h2230 = _t2230.n; if (_l2230 < 0 || _h2230 < _l2230 || _h2230 > _t2230.n) hr_slerr(_l2230, _h2230, _t2230.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:17"); (hsl){ _t2230.p + _l2230 * (int64_t)sizeof(uint8_t), _h2230 - _l2230 }; }); hr_append(_v2229, _s2229.p, _s2229.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2231 = &(g164); uint8_t _x2231 = ((uint8_t)32LL); uint8_t *_p2231 = (uint8_t*)hr_grow(_v2231, 1, sizeof _x2231); *_p2231 = _x2231; _p2231; }));
(void)(({ hrv *_v2232 = &(g164); hsl _s2232 = ({ hsl _t2233 = hr_sl(g170); int64_t _l2233 = s0_1439, _h2233 = _t2233.n; if (_l2233 < 0 || _h2233 < _l2233 || _h2233 > _t2233.n) hr_slerr(_l2233, _h2233, _t2233.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:17"); (hsl){ _t2233.p + _l2233 * (int64_t)sizeof(uint8_t), _h2233 - _l2233 }; }); hr_append(_v2232, _s2232.p, _s2232.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2234 = &(g164); hsl _s2234 = hr_str(";\012", 2); hr_append(_v2234, _s2234.p, _s2234.n, sizeof(uint8_t)); }));
}
static void f254_fname_into(hrv* b_1451, int64_t name_1452) {
{ hsl _v2236 = f10_nm(name_1452); for (int64_t _k2236 = 0; _k2236 < _v2236.n; _k2236++) { uint8_t c_1453 = ((uint8_t*)_v2236.p)[_k2236]; (void)(({ hrv *_v2237 = b_1451; uint8_t _x2237 = ({ uint8_t _r2238; if (((c_1453) == (((uint8_t)58LL)))) { _r2238 = ((uint8_t)95LL);  } else { _r2238 = c_1453;  } _r2238; }); uint8_t *_p2237 = (uint8_t*)hr_grow(_v2237, 1, sizeof _x2237); *_p2237 = _x2237; _p2237; }));
 } } _bk2235:; 
(void)(({ hrv *_v2239 = b_1451; uint8_t _x2239 = ((uint8_t)95LL); uint8_t *_p2239 = (uint8_t*)hr_grow(_v2239, 1, sizeof _x2239); *_p2239 = _x2239; _p2239; }));
}
static bool f255_is_res(int64_t t_1467) {
return (((((*({ hrv *_t2240 = &(g528); int64_t _i2240 = t_1467; (S1*)_t2240->b + hr_ix(_i2240, _t2240->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:18"); }))).k_) == (((uint8_t)8LL))) && (((((int64_t)(((*({ hrv *_t2241 = &(g528); int64_t _i2241 = t_1467; (S1*)_t2241->b + hr_ix(_i2241, _t2241->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:18"); }))).s_))) == (((int64_t)4LL))) || ((((int64_t)(((*({ hrv *_t2242 = &(g528); int64_t _i2242 = t_1467; (S1*)_t2242->b + hr_ix(_i2242, _t2242->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:18"); }))).s_))) == (((int64_t)5LL)))));
}
static void f256_gxo(int64_t n_1468) {
int64_t c_1469 = f149_cv(n_1468); 
int64_t t_1470 = f142_at(n_1468); 
if ((((c_1469) >= (((int64_t)0LL))) && ((c_1469) != (t_1470)))) { if (f255_is_res(c_1469)) { (void)(f257_gcv(n_1468, t_1470, c_1469));
return;
 }
(void)(f276_gx(n_1468));
return;
 }
if ((f255_is_res(t_1470) && f259_is_place(n_1468))) { (void)(f247_ow(hr_str("hr_rdup(", 8)));
(void)(f262_gx0(n_1468));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f310_esz(((int64_t)(((*({ hrv *_t2243 = &(g528); int64_t _i2243 = t_1470; (S1*)_t2243->b + hr_ix(_i2243, _t2243->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:160"); }))).a_))));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
(void)(f262_gx0(n_1468));
}
static void f257_gcv(int64_t n_1471, int64_t f_1472, int64_t t_1473) {
if (((f_1472) == (t_1473))) { (void)(f258_gx1(n_1471));
return;
 }
int64_t fk_1965 = ((int64_t)(((*({ hrv *_t2244 = &(g528); int64_t _i2244 = f_1472; (S1*)_t2244->b + hr_ix(_i2244, _t2244->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:200"); }))).k_)); 
int64_t tk0_1966 = ((int64_t)(((*({ hrv *_t2245 = &(g528); int64_t _i2245 = t_1473; (S1*)_t2245->b + hr_ix(_i2245, _t2245->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:200"); }))).k_)); 
if (((((fk_1965) == (((int64_t)10LL))) && ((((*({ hrv *_t2246 = &(g528); int64_t _i2246 = f_1472; (S1*)_t2246->b + hr_ix(_i2246, _t2246->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:201"); }))).c_) < (((int32_t)0LL)))) && ((tk0_1966) != (((int64_t)10LL))))) { int64_t m_1967 = ((int64_t)(((*({ hrv *_t2247 = &(g528); int64_t _i2247 = f_1472; (S1*)_t2247->b + hr_ix(_i2247, _t2247->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:202"); }))).a_)); 
if (((m_1967) == (t_1473))) { (void)(f247_ow(hr_str("(*", 2)));
(void)(f258_gx1(n_1471));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if ((((tk0_1966) == (((int64_t)9LL))) && (((((*({ hrv *_t2248 = &(g528); int64_t _i2248 = m_1967; (S1*)_t2248->b + hr_ix(_i2248, _t2248->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:204"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2249 = &(g528); int64_t _i2249 = m_1967; (S1*)_t2249->b + hr_ix(_i2249, _t2249->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:204"); }))).k_) == (((uint8_t)9LL)))))) { (void)(f279_gsl(n_1471, f_1472));
return;
 }
if ((((tk0_1966) == (((int64_t)3LL))) || ((tk0_1966) == (((int64_t)4LL))))) { (void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(t_1473));
(void)(f247_ow(hr_str(")(*", 3)));
(void)(f258_gx1(n_1471));
(void)(f247_ow(hr_str("))", 2)));
return;
 }
if (f255_is_res(t_1473)) { (void)(f247_ow(hr_str("hr_rfrom(", 9)));
(void)(f279_gsl(n_1471, f_1472));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f310_esz(((int64_t)(((*({ hrv *_t2250 = &(g528); int64_t _i2250 = t_1473; (S1*)_t2250->b + hr_ix(_i2250, _t2250->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:206"); }))).a_))));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
(void)(f247_ow(hr_str("(*", 2)));
(void)(f258_gx1(n_1471));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if (((((tk0_1966) == (((int64_t)3LL))) || ((tk0_1966) == (((int64_t)4LL)))) && ((((fk_1965) == (((int64_t)3LL))) || ((fk_1965) == (((int64_t)4LL)))) || ((fk_1965) == (((int64_t)2LL)))))) { (void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(t_1473));
(void)(f247_ow(hr_str(")(", 2)));
(void)(f258_gx1(n_1471));
(void)(f247_ow(hr_str("))", 2)));
return;
 }
if (((tk0_1966) == (((int64_t)9LL)))) { (void)(f279_gsl(n_1471, f_1472));
return;
 }
if ((((tk0_1966) == (((int64_t)6LL))) && ((fk_1965) == (((int64_t)7LL))))) { int64_t vi_1968 = ((int64_t)(((*({ hrv *_t2251 = &(g528); int64_t _i2251 = f_1472; (S1*)_t2251->b + hr_ix(_i2251, _t2251->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:212"); }))).c_)); 
int64_t ei_1969 = ((int64_t)(((*({ hrv *_t2252 = &(g528); int64_t _i2252 = f_1472; (S1*)_t2252->b + hr_ix(_i2252, _t2252->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:212"); }))).a_)); 
S9 v_1970 = (*({ hrv *_t2253 = &(g534); int64_t _i2253 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2254 = &(g533); int64_t _i2254 = ei_1969; (S8*)_t2254->b + hr_ix(_i2254, _t2254->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:212"); }))).v0_)) + (int64_t)vi_1968)); (S9*)_t2253->b + hr_ix(_i2253, _t2253->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:212"); })); 
int64_t p_1971 = f280_nt(); 
(void)(f247_ow(hr_str("({ ", 3)));
(void)(f248_ct(t_1473));
(void)(f247_ow(hr_str(" _t", 3)));
(void)(f281_oi(p_1971));
(void)(f247_ow(hr_str("; memset(&_t", 12)));
(void)(f281_oi(p_1971));
(void)(f247_ow(hr_str(", 0, sizeof _t", 14)));
(void)(f281_oi(p_1971));
(void)(f247_ow(hr_str("); _t", 5)));
(void)(f281_oi(p_1971));
(void)(({ hrv *_o2255 = &(g163); hr_fs(_o2255, hr_str(".tag = ", 7)); hr_fi(_o2255, vi_1968); hr_fs(_o2255, hr_str("; ", 2)); }));
if (((((v_1970).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t2256 = &(g531); int64_t _i2256 = (v_1970).si_; (S10*)_t2256->b + hr_ix(_i2256, _t2256->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:215"); }))).zero_)))) { (void)(f247_ow(hr_str("_t", 2)));
(void)(f281_oi(p_1971));
(void)(({ hrv *_o2257 = &(g163); hr_fs(_o2257, hr_str(".u.v", 4)); hr_fi(_o2257, vi_1968); hr_fs(_o2257, hr_str(" = ", 3)); }));
(void)(f258_gx1(n_1471));
(void)(f247_ow(hr_str("; ", 2)));
 } else { (void)(f247_ow(hr_str("(void)(", 7)));
(void)(f258_gx1(n_1471));
(void)(f247_ow(hr_str("); ", 3)));
 }
(void)(f247_ow(hr_str("_t", 2)));
(void)(f281_oi(p_1971));
(void)(f247_ow(hr_str("; })", 4)));
return;
 }
if (((tk0_1966) == (((int64_t)10LL)))) { if (((fk_1965) == (((int64_t)10LL)))) { (void)(f258_gx1(n_1471));
return;
 }
(void)(f311_gaddr(n_1471));
return;
 }
if (f255_is_res(t_1473)) { (void)(f247_ow(hr_str("hr_rfrom(", 9)));
(void)(f279_gsl(n_1471, f_1472));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f310_esz(((int64_t)(((*({ hrv *_t2258 = &(g528); int64_t _i2258 = t_1473; (S1*)_t2258->b + hr_ix(_i2258, _t2258->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:220"); }))).a_))));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if ((f269_is_fix(t_1473) || f270_is_lim(t_1473))) { int64_t p_1972 = f280_nt(); 
(void)(f247_ow(hr_str("({ hsl _t", 9)));
(void)(f281_oi(p_1972));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f279_gsl(n_1471, f_1472));
(void)(f247_ow(hr_str("; ", 2)));
(void)(f248_ct(t_1473));
(void)(f247_ow(hr_str(" _r", 3)));
(void)(f281_oi(p_1972));
(void)(f247_ow(hr_str("; ", 2)));
if (f269_is_fix(t_1473)) { (void)(({ hrv *_o2259 = &(g163); hr_fs(_o2259, hr_str("if (_t", 6)); hr_fi(_o2259, p_1972); hr_fs(_o2259, hr_str(".n != ", 6)); hr_fi(_o2259, ((*({ hrv *_t2260 = &(g528); int64_t _i2260 = t_1473; (S1*)_t2260->b + hr_ix(_i2260, _t2260->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:224"); }))).b_); hr_fs(_o2259, hr_str(") hr_die(\"array length mismatch\", ", 34)); }));
(void)(f298_wloc(n_1471));
(void)(f247_ow(hr_str("); ", 3)));
 } else { (void)(({ hrv *_o2261 = &(g163); hr_fs(_o2261, hr_str("if (_t", 6)); hr_fi(_o2261, p_1972); hr_fs(_o2261, hr_str(".n > ", 5)); hr_fi(_o2261, ((*({ hrv *_t2262 = &(g528); int64_t _i2262 = t_1473; (S1*)_t2262->b + hr_ix(_i2262, _t2262->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:225"); }))).b_); hr_fs(_o2261, hr_str(") hr_die(\"too many elements for a limited array\", ", 50)); }));
(void)(f298_wloc(n_1471));
(void)(({ hrv *_o2263 = &(g163); hr_fs(_o2263, hr_str("); _r", 5)); hr_fi(_o2263, p_1972); hr_fs(_o2263, hr_str(".n = _t", 7)); hr_fi(_o2263, p_1972); hr_fs(_o2263, hr_str(".n; ", 4)); }));
 }
(void)(({ hrv *_o2264 = &(g163); hr_fs(_o2264, hr_str("memcpy(_r", 9)); hr_fi(_o2264, p_1972); hr_fs(_o2264, hr_str(".e, _t", 6)); hr_fi(_o2264, p_1972); hr_fs(_o2264, hr_str(".p, (size_t)_t", 14)); hr_fi(_o2264, p_1972); hr_fs(_o2264, hr_str(".n * sizeof _r", 14)); hr_fi(_o2264, p_1972); hr_fs(_o2264, hr_str(".e[0]); _r", 10)); hr_fi(_o2264, p_1972); hr_fs(_o2264, hr_str("; })", 4)); }));
return;
 }
(void)(f258_gx1(n_1471));
}
static void f258_gx1(int64_t n_1474) {
if ((f255_is_res(f142_at(n_1474)) && (!(f259_is_place(n_1474))))) { int64_t k_1482 = f260_tmp(f142_at(n_1474), true); 
(void)(f247_ow(hr_str("(*hr_tmp(&", 10)));
(void)(f261_ot(k_1482));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f262_gx0(n_1474));
(void)(f247_ow(hr_str("))", 2)));
return;
 }
(void)(f262_gx0(n_1474));
}
static bool f259_is_place(int64_t n_1475) {
S4 x_1476 = (*({ hrv *_t2265 = &(g679); int64_t _i2265 = n_1475; (S4*)_t2265->b + hr_ix(_i2265, _t2265->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:122"); })); 
int64_t k_1477 = ((int64_t)((x_1476).k_)); 
if (((k_1477) == (((int64_t)8LL)))) { int64_t r_1478 = f157_rk(n_1475); 
return (((r_1478) == (((int64_t)1LL))) || ((r_1478) == (((int64_t)2LL))));
 }
if (((k_1477) == (((int64_t)14LL)))) { return (((f157_rk(n_1475)) == (((int64_t)5LL))) && (f259_is_place(((int64_t)((x_1476).a_))) || ((((*({ hrv *_t2266 = &(g528); int64_t _i2266 = f142_at(((int64_t)((x_1476).a_))); (S1*)_t2266->b + hr_ix(_i2266, _t2266->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:124"); }))).k_) == (((uint8_t)10LL)))));
 }
if (((k_1477) == (((int64_t)12LL)))) { int64_t bt_1479 = f142_at(((int64_t)((x_1476).a_))); 
return ((((((*({ hrv *_t2267 = &(g528); int64_t _i2267 = f176_deref(bt_1479); (S1*)_t2267->b + hr_ix(_i2267, _t2267->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:125"); }))).k_) == (((uint8_t)9LL))) || f259_is_place(((int64_t)((x_1476).a_)))) || ((((*({ hrv *_t2268 = &(g528); int64_t _i2268 = bt_1479; (S1*)_t2268->b + hr_ix(_i2268, _t2268->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:125"); }))).k_) == (((uint8_t)10LL))));
 }
if ((((k_1477) == (((int64_t)10LL))) && ((((int64_t)((x_1476).op_))) == (((int64_t)49LL))))) { return f259_is_place(((int64_t)((x_1476).a_)));
 }
if (((((k_1477) == (((int64_t)11LL))) && ((f157_rk(n_1475)) == (((int64_t)4LL)))) && ((f158_rv(n_1475)) == (((int64_t)20LL))))) { return true;
 }
return false;
}
static int64_t f260_tmp(int64_t t_1480, bool clean_1481) {
(void)(f249_cbody(t_1480));
g178++;
(void)(({ hrv *_v2269 = &(g176); hsl _s2269 = f251_cn(t_1480); hr_append(_v2269, _s2269.p, _s2269.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o2270 = &(g176); hr_fs(_o2270, hr_str(" _t", 3)); hr_fi(_o2270, g178); }));
if (clean_1481) { (void)(({ hrv *_v2271 = &(g176); hsl _s2271 = hr_str(" __attribute__((cleanup(hr_rdrop)))", 35); hr_append(_v2271, _s2271.p, _s2271.n, sizeof(uint8_t)); }));
 }
(void)(({ hrv *_v2272 = &(g176); hsl _s2272 = hr_str(" = {0}; ", 8); hr_append(_v2272, _s2272.p, _s2272.n, sizeof(uint8_t)); }));
return g178;
}
static void f261_ot(int64_t k_1483) {
(void)(({ hrv *_o2273 = &(g163); hr_fs(_o2273, hr_str("_t", 2)); hr_fi(_o2273, k_1483); }));
}
static void f262_gx0(int64_t n_1484) {
S4 x_1485 = (*({ hrv *_t2274 = &(g679); int64_t _i2274 = n_1484; (S4*)_t2274->b + hr_ix(_i2274, _t2274->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:686"); })); 
int64_t k_1486 = ((int64_t)((x_1485).k_)); 
if (((k_1486) == (((int64_t)1LL)))) { (void)(f264_oint(((*({ hrv *_t2275 = &(g889); int64_t _i2275 = (x_1485).t_; (S3*)_t2275->b + hr_ix(_i2275, _t2275->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:688"); }))).v_, ((*({ hrv *_t2276 = &(g889); int64_t _i2276 = (x_1485).t_; (S3*)_t2276->b + hr_ix(_i2276, _t2276->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:688"); }))).uns_, f263_fin_lit(n_1484)));
return;
 }
if (((k_1486) == (((int64_t)2LL)))) { int64_t t_1493 = f263_fin_lit(n_1484); 
(void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(({ int64_t _r2277; if (((((*({ hrv *_t2278 = &(g528); int64_t _i2278 = t_1493; (S1*)_t2278->b + hr_ix(_i2278, _t2278->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:689"); }))).k_) == (((uint8_t)4LL)))) { _r2277 = t_1493;  } else { _r2277 = g546;  } _r2277; })));
(void)(f247_ow(hr_str(")", 1)));
(void)(f247_ow(f36_tok_text(((int64_t)((x_1485).t_)))));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if (((k_1486) == (((int64_t)3LL)))) { (void)(f265_gstr(n_1484));
return;
 }
if (((k_1486) == (((int64_t)4LL)))) { (void)(f247_ow(hr_str("true", 4)));
return;
 }
if (((k_1486) == (((int64_t)5LL)))) { (void)(f247_ow(hr_str("false", 5)));
return;
 }
if (((k_1486) == (((int64_t)6LL)))) { (void)(f247_ow(hr_str("((void*)0)", 10)));
return;
 }
if (((k_1486) == (((int64_t)8LL)))) { int64_t r_1507 = f157_rk(n_1484); 
if (((r_1507) == (((int64_t)1LL)))) { (void)(f271_lv_expr(f158_rv(n_1484)));
return;
 }
if (((r_1507) == (((int64_t)2LL)))) { (void)(({ hrv *_o2279 = &(g163); hr_fs(_o2279, hr_str("g", 1)); hr_fi(_o2279, f158_rv(n_1484)); }));
return;
 }
if (((r_1507) == (((int64_t)6LL)))) { (void)(f264_oint((*({ hrv *_t2280 = &(g414); int64_t _i2280 = f158_rv(n_1484); (int64_t*)_t2280->b + hr_ix(_i2280, _t2280->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:698"); })), false, f263_fin_lit(n_1484)));
return;
 }
(void)(f274_gerr(n_1484, hr_str("unsupported name use", 20)));
return;
 }
if (((k_1486) == (((int64_t)9LL)))) { (void)(f275_gbin(n_1484));
return;
 }
if (((k_1486) == (((int64_t)10LL)))) { (void)(f299_gun(n_1484));
return;
 }
if (((k_1486) == (((int64_t)14LL)))) { int64_t r_1689 = f157_rk(n_1484); 
int64_t a_1690 = ((int64_t)((x_1485).a_)); 
if (((r_1689) == (((int64_t)7LL)))) { int64_t t_1691 = f142_at(n_1484); 
int64_t p_1692 = f280_nt(); 
(void)(f247_ow(hr_str("({ ", 3)));
(void)(f248_ct(t_1691));
(void)(f247_ow(hr_str(" _t", 3)));
(void)(f281_oi(p_1692));
(void)(({ hrv *_o2281 = &(g163); hr_fs(_o2281, hr_str("; memset(&_t", 12)); hr_fi(_o2281, p_1692); hr_fs(_o2281, hr_str(", 0, sizeof _t", 14)); hr_fi(_o2281, p_1692); hr_fs(_o2281, hr_str("); _t", 5)); hr_fi(_o2281, p_1692); hr_fs(_o2281, hr_str(".tag = ", 7)); hr_fi(_o2281, f158_rv(n_1484)); hr_fs(_o2281, hr_str("; _t", 4)); hr_fi(_o2281, p_1692); hr_fs(_o2281, hr_str("; })", 4)); }));
return;
 }
if (((r_1689) == (((int64_t)8LL)))) { int64_t d_1693 = f176_deref(f142_at(a_1690)); 
if (((f158_rv(n_1484)) == (((int64_t)2LL)))) { (void)(({ hrv *_o2282 = &(g163); hr_fs(_o2282, hr_str("((int64_t)", 10)); hr_fi(_o2282, ((*({ hrv *_t2283 = &(g528); int64_t _i2283 = d_1693; (S1*)_t2283->b + hr_ix(_i2283, _t2283->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:709"); }))).b_); hr_fs(_o2282, hr_str(")", 1)); }));
return;
 }
if (f269_is_fix(d_1693)) { (void)(({ hrv *_o2284 = &(g163); hr_fs(_o2284, hr_str("((int64_t)", 10)); hr_fi(_o2284, ((*({ hrv *_t2285 = &(g528); int64_t _i2285 = d_1693; (S1*)_t2285->b + hr_ix(_i2285, _t2285->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:710"); }))).b_); hr_fs(_o2284, hr_str(")", 1)); }));
return;
 }
if (f270_is_lim(d_1693)) { (void)(f247_ow(hr_str("((int64_t)(", 11)));
if (((((*({ hrv *_t2286 = &(g528); int64_t _i2286 = f142_at(a_1690); (S1*)_t2286->b + hr_ix(_i2286, _t2286->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:711"); }))).k_) == (((uint8_t)10LL)))) { (void)(f262_gx0(a_1690));
(void)(f247_ow(hr_str(")->n)", 5)));
 } else { (void)(f276_gx(a_1690));
(void)(f247_ow(hr_str(").n)", 4)));
 }
return;
 }
if (((((*({ hrv *_t2287 = &(g528); int64_t _i2287 = f142_at(a_1690); (S1*)_t2287->b + hr_ix(_i2287, _t2287->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:712"); }))).k_) == (((uint8_t)10LL)))) { (void)(f247_ow(hr_str("((", 2)));
(void)(f262_gx0(a_1690));
(void)(f247_ow(hr_str(")->n)", 5)));
return;
 }
(void)(f247_ow(hr_str("(", 1)));
(void)(f276_gx(a_1690));
(void)(f247_ow(hr_str(").n", 3)));
return;
 }
if (((r_1689) == (((int64_t)5LL)))) { int64_t bt_1694 = f142_at(a_1690); 
int64_t st_1695 = f176_deref(bt_1694); 
int64_t si_1696 = ({ int64_t _r2288; if (((((*({ hrv *_t2289 = &(g528); int64_t _i2289 = st_1695; (S1*)_t2289->b + hr_ix(_i2289, _t2289->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:718"); }))).k_) == (((uint8_t)5LL)))) { _r2288 = ((int64_t)(((*({ hrv *_t2290 = &(g528); int64_t _i2290 = st_1695; (S1*)_t2290->b + hr_ix(_i2290, _t2290->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:718"); }))).a_));  } else { _r2288 = f211_ax(n_1484);  } _r2288; }); 
S11 f_1697 = (*({ hrv *_t2291 = &(g532); int64_t _i2291 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2292 = &(g531); int64_t _i2292 = si_1696; (S10*)_t2292->b + hr_ix(_i2292, _t2292->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:719"); }))).f0_)) + (int64_t)f158_rv(n_1484))); (S11*)_t2291->b + hr_ix(_i2291, _t2291->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:719"); })); 
(void)(f247_ow(hr_str("(", 1)));
if (((((*({ hrv *_t2293 = &(g528); int64_t _i2293 = bt_1694; (S1*)_t2293->b + hr_ix(_i2293, _t2293->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:721"); }))).k_) == (((uint8_t)10LL)))) { (void)(f262_gx0(a_1690));
(void)(f247_ow(hr_str(")->", 3)));
 } else { (void)(f276_gx(a_1690));
(void)(f247_ow(hr_str(").", 2)));
 }
(void)(f254_fname_into((&(g163)), ((int64_t)((f_1697).name_))));
return;
 }
(void)(f274_gerr(n_1484, hr_str("unsupported member", 18)));
return;
 }
if (((k_1486) == (((int64_t)12LL)))) { (void)(f301_gidx(n_1484));
return;
 }
if (((k_1486) == (((int64_t)13LL)))) { (void)(f302_gslice(n_1484));
return;
 }
if (((k_1486) == (((int64_t)15LL)))) { int64_t t_1712 = f142_at(n_1484); 
int64_t ft_1713 = ((int64_t)(((*({ hrv *_t2294 = &(g528); int64_t _i2294 = f266_fin(((int64_t)((x_1485).a_))); (S1*)_t2294->b + hr_ix(_i2294, _t2294->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:729"); }))).k_)); 
if ((((((*({ hrv *_t2295 = &(g528); int64_t _i2295 = t_1712; (S1*)_t2295->b + hr_ix(_i2295, _t2295->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:729"); }))).k_) == (((uint8_t)3LL))) && (((ft_1713) == (((int64_t)4LL))) || ((ft_1713) == (((int64_t)13LL)))))) { (void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(t_1712));
(void)(f247_ow(hr_str(")hr_f2i(", 8)));
(void)(f276_gx(((int64_t)((x_1485).a_))));
(void)(f247_ow(hr_str("))", 2)));
return;
 }
(void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(t_1712));
(void)(f247_ow(hr_str(")(", 2)));
(void)(f276_gx(((int64_t)((x_1485).a_))));
(void)(f247_ow(hr_str("))", 2)));
return;
 }
if (((k_1486) == (((int64_t)16LL)))) { (void)(f303_garr(n_1484));
return;
 }
if (((k_1486) == (((int64_t)17LL)))) { (void)(f304_gslit(n_1484));
return;
 }
if (((k_1486) == (((int64_t)11LL)))) { (void)(f305_gcall(n_1484));
return;
 }
if (((k_1486) == (((int64_t)23LL)))) { (void)(f247_ow(hr_str("({ ", 3)));
(void)(f326_gblk(n_1484, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((f142_at(n_1484)) != (g535))));
(void)(f247_ow(hr_str(" })", 3)));
return;
 }
if ((((((k_1486) == (((int64_t)19LL))) || ((k_1486) == (((int64_t)20LL)))) || ((k_1486) == (((int64_t)24LL)))) || ((k_1486) == (((int64_t)26LL))))) { int64_t t_1963 = f142_at(n_1484); 
if ((((t_1963) == (g535)) || ((t_1963) < (((int64_t)0LL))))) { (void)(f247_ow(hr_str("({ ", 3)));
(void)(f319_gstmt(n_1484));
(void)(f247_ow(hr_str(" })", 3)));
return;
 }
int64_t r_1964 = f280_nt(); 
(void)(f247_ow(hr_str("({ ", 3)));
(void)(f248_ct(t_1963));
(void)(f247_ow(hr_str(" _r", 3)));
(void)(f281_oi(r_1964));
(void)(f247_ow(hr_str("; ", 2)));
if (((k_1486) == (((int64_t)19LL)))) { (void)(f325_gif(n_1484, r_1964));
 } else { if (((k_1486) == (((int64_t)20LL)))) { (void)(f333_gmatch(n_1484, r_1964));
 } else { if (((k_1486) == (((int64_t)24LL)))) { (void)(f334_geblock(n_1484, r_1964));
 } else { (void)(f331_gloop(n_1484, r_1964));
 }
 }
 }
(void)(f247_ow(hr_str(" _r", 3)));
(void)(f281_oi(r_1964));
(void)(f247_ow(hr_str("; })", 4)));
return;
 }
if (((((((k_1486) == (((int64_t)28LL))) || ((k_1486) == (((int64_t)29LL)))) || ((k_1486) == (((int64_t)30LL)))) || ((k_1486) == (((int64_t)25LL)))) || ((k_1486) == (((int64_t)27LL))))) { (void)(f247_ow(hr_str("({ ", 3)));
(void)(f319_gstmt(n_1484));
(void)(f247_ow(hr_str(" })", 3)));
return;
 }
(void)(f274_gerr(n_1484, hr_str("unsupported expression in codegen", 33)));
}
static int64_t f263_fin_lit(int64_t n_1487) {
int64_t t_1488 = f142_at(n_1487); 
return ({ int64_t _r2296; if ((((t_1488) < (((int64_t)0LL))) || ((((*({ hrv *_t2297 = &(g528); int64_t _i2297 = t_1488; (S1*)_t2297->b + hr_ix(_i2297, _t2297->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:748"); }))).k_) == (((uint8_t)12LL))))) { _r2296 = g540;  } else { _r2296 = ({ int64_t _r2298; if (((((*({ hrv *_t2299 = &(g528); int64_t _i2299 = t_1488; (S1*)_t2299->b + hr_ix(_i2299, _t2299->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:748"); }))).k_) == (((uint8_t)13LL)))) { _r2298 = g546;  } else { _r2298 = t_1488;  } _r2298; });  } _r2296; });
}
static void f264_oint(int64_t v_1489, bool uns_1490, int64_t t_1491) {
int64_t k_1492 = ((int64_t)(((*({ hrv *_t2300 = &(g528); int64_t _i2300 = t_1491; (S1*)_t2300->b + hr_ix(_i2300, _t2300->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:140"); }))).k_)); 
if (((k_1492) == (((int64_t)4LL)))) { (void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(t_1491));
(void)(f247_ow(hr_str(")", 1)));
if (uns_1490) { (void)(({ hrv *_o2301 = &(g163); hr_fu(_o2301, ((uint64_t)(v_1489))); hr_fs(_o2301, hr_str(".0", 2)); }));
 } else { (void)(({ hrv *_o2302 = &(g163); hr_fi(_o2302, v_1489); hr_fs(_o2302, hr_str(".0", 2)); }));
 }
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if (((k_1492) == (((int64_t)2LL)))) { (void)(f247_ow(({ hsl _r2303; if (((v_1489) != (((int64_t)0LL)))) { _r2303 = hr_str("true", 4);  } else { _r2303 = hr_str("false", 5);  } _r2303; })));
return;
 }
(void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(({ int64_t _r2304; if (((k_1492) == (((int64_t)3LL)))) { _r2304 = t_1491;  } else { _r2304 = g540;  } _r2304; })));
(void)(f247_ow(hr_str(")", 1)));
if (uns_1490) { (void)(({ hrv *_o2305 = &(g163); hr_fu(_o2305, ((uint64_t)(v_1489))); hr_fs(_o2305, hr_str("ULL)", 4)); }));
return;
 }
if (((v_1489) == (((int64_t)((int64_t)((int64_t)(0 - (uint64_t)(((int64_t)9223372036854775807LL)))) - (int64_t)((int64_t)1LL)))))) { (void)(f247_ow(hr_str("(-9223372036854775807LL-1))", 27)));
return;
 }
(void)(({ hrv *_o2306 = &(g163); hr_fi(_o2306, v_1489); hr_fs(_o2306, hr_str("LL)", 3)); }));
}
static void f265_gstr(int64_t n_1494) {
int64_t t_1498 = f266_fin(n_1494); 
hsl s_1501 = f267_tok_str(((int64_t)(((*({ hrv *_t2307 = &(g679); int64_t _i2307 = n_1494; (S4*)_t2307->b + hr_ix(_i2307, _t2307->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:337"); }))).t_))); 
int64_t a_1502 = f142_at(n_1494); 
if (f255_is_res(a_1502)) { (void)(f247_ow(hr_str("hr_rfrom(hr_str(", 16)));
(void)(f268_cstr_lit(s_1501));
(void)(({ hrv *_o2308 = &(g163); hr_fs(_o2308, hr_str(", ", 2)); hr_fi(_o2308, (s_1501).n); hr_fs(_o2308, hr_str("), 1)", 5)); }));
return;
 }
if (f269_is_fix(a_1502)) { (void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(a_1502));
(void)(f247_ow(hr_str("){ ", 3)));
(void)(f268_cstr_lit(s_1501));
(void)(f247_ow(hr_str(" })", 3)));
return;
 }
if (f270_is_lim(a_1502)) { (void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(a_1502));
(void)(({ hrv *_o2309 = &(g163); hr_fs(_o2309, hr_str("){ ", 3)); hr_fi(_o2309, (s_1501).n); hr_fs(_o2309, hr_str(", ", 2)); }));
(void)(f268_cstr_lit(s_1501));
(void)(f247_ow(hr_str(" })", 3)));
return;
 }
(void)(f247_ow(hr_str("hr_str(", 7)));
(void)(f268_cstr_lit(s_1501));
(void)(({ hrv *_o2310 = &(g163); hr_fs(_o2310, hr_str(", ", 2)); hr_fi(_o2310, (s_1501).n); hr_fs(_o2310, hr_str(")", 1)); }));
}
static int64_t f266_fin(int64_t n_1495) {
int64_t c_1496 = f149_cv(n_1495); 
return ({ int64_t _r2311; if (((c_1496) >= (((int64_t)0LL)))) { _r2311 = c_1496;  } else { int64_t t_1497 = f142_at(n_1495); 
_r2311 = ({ int64_t _r2312; if (((t_1497) < (((int64_t)0LL)))) { _r2312 = g535;  } else { _r2312 = t_1497;  } _r2312; });  } _r2311; });
}
static hsl f267_tok_str(int64_t t_1499) {
S3 x_1500 = (*({ hrv *_t2313 = &(g889); int64_t _i2313 = t_1499; (S3*)_t2313->b + hr_ix(_i2313, _t2313->n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:182"); })); 
return ({ hsl _t2314 = hr_sl(g885); int64_t _l2314 = ((int64_t)((x_1500).v_)), _h2314 = ((int64_t)((int64_t)((int64_t)((x_1500).v_)) + (int64_t)((int64_t)((x_1500).w_)))); if (_l2314 < 0 || _h2314 < _l2314 || _h2314 > _t2314.n) hr_slerr(_l2314, _h2314, _t2314.n, "/home/anmire/ai/amni-lang/helium-fix/hc/lex.amni:182"); (hsl){ _t2314.p + _l2314 * (int64_t)sizeof(uint8_t), _h2314 - _l2314 }; });
}
static void f268_cstr_lit(hsl s_1503) {
(void)(({ hrv *_v2315 = &(g163); uint8_t _x2315 = ((uint8_t)34LL); uint8_t *_p2315 = (uint8_t*)hr_grow(_v2315, 1, sizeof _x2315); *_p2315 = _x2315; _p2315; }));
{ hsl _v2317 = s_1503; for (int64_t _k2317 = 0; _k2317 < _v2317.n; _k2317++) { uint8_t c_1504 = ((uint8_t*)_v2317.p)[_k2317]; if ((((c_1504) == (((uint8_t)34LL))) || ((c_1504) == (((uint8_t)92LL))))) { (void)(({ hrv *_v2318 = &(g163); uint8_t _x2318 = ((uint8_t)92LL); uint8_t *_p2318 = (uint8_t*)hr_grow(_v2318, 1, sizeof _x2318); *_p2318 = _x2318; _p2318; }));
(void)(({ hrv *_v2319 = &(g163); uint8_t _x2319 = c_1504; uint8_t *_p2319 = (uint8_t*)hr_grow(_v2319, 1, sizeof _x2319); *_p2319 = _x2319; _p2319; }));
 } else { if (((((c_1504) >= (((uint8_t)32LL))) && ((c_1504) < (((uint8_t)127LL)))) && ((c_1504) != (((uint8_t)63LL))))) { (void)(({ hrv *_v2320 = &(g163); uint8_t _x2320 = c_1504; uint8_t *_p2320 = (uint8_t*)hr_grow(_v2320, 1, sizeof _x2320); *_p2320 = _x2320; _p2320; }));
 } else { (void)(({ hrv *_v2321 = &(g163); uint8_t _x2321 = ((uint8_t)92LL); uint8_t *_p2321 = (uint8_t*)hr_grow(_v2321, 1, sizeof _x2321); *_p2321 = _x2321; _p2321; }));
(void)(({ hrv *_v2322 = &(g163); uint8_t _x2322 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)((uint8_t)((c_1504) >> ((((uint8_t)6LL)) & 7))) & (uint64_t)((uint8_t)7LL))))); uint8_t *_p2322 = (uint8_t*)hr_grow(_v2322, 1, sizeof _x2322); *_p2322 = _x2322; _p2322; }));
(void)(({ hrv *_v2323 = &(g163); uint8_t _x2323 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)((uint8_t)((c_1504) >> ((((uint8_t)3LL)) & 7))) & (uint64_t)((uint8_t)7LL))))); uint8_t *_p2323 = (uint8_t*)hr_grow(_v2323, 1, sizeof _x2323); *_p2323 = _x2323; _p2323; }));
(void)(({ hrv *_v2324 = &(g163); uint8_t _x2324 = ((uint8_t)((uint64_t)((uint8_t)48LL) + (uint64_t)((uint8_t)((uint64_t)c_1504 & (uint64_t)((uint8_t)7LL))))); uint8_t *_p2324 = (uint8_t*)hr_grow(_v2324, 1, sizeof _x2324); *_p2324 = _x2324; _p2324; }));
 }
 }
 } } _bk2316:; 
(void)(({ hrv *_v2325 = &(g163); uint8_t _x2325 = ((uint8_t)34LL); uint8_t *_p2325 = (uint8_t*)hr_grow(_v2325, 1, sizeof _x2325); *_p2325 = _x2325; _p2325; }));
}
static bool f269_is_fix(int64_t t_1505) {
return (((((*({ hrv *_t2326 = &(g528); int64_t _i2326 = t_1505; (S1*)_t2326->b + hr_ix(_i2326, _t2326->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:20"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t2327 = &(g528); int64_t _i2327 = t_1505; (S1*)_t2327->b + hr_ix(_i2327, _t2327->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:20"); }))).s_))) == (((int64_t)1LL))));
}
static bool f270_is_lim(int64_t t_1506) {
return (((((*({ hrv *_t2328 = &(g528); int64_t _i2328 = t_1506; (S1*)_t2328->b + hr_ix(_i2328, _t2328->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:19"); }))).k_) == (((uint8_t)8LL))) && ((((int64_t)(((*({ hrv *_t2329 = &(g528); int64_t _i2329 = t_1506; (S1*)_t2329->b + hr_ix(_i2329, _t2329->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:19"); }))).s_))) == (((int64_t)3LL))));
}
static void f271_lv_expr(int64_t v_1508) {
bool p_1510 = f272_lv_isptr(v_1508); 
if (((((int64_t)(((*({ hrv *_t2330 = &(g374); int64_t _i2330 = v_1508; (S12*)_t2330->b + hr_ix(_i2330, _t2330->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:115"); }))).cfn_))) != (g179))) { (void)(f247_ow(({ hsl _r2331; if (p_1510) { _r2331 = hr_str("(**c", 4);  } else { _r2331 = hr_str("(*c", 3);  } _r2331; })));
(void)(({ hrv *_o2332 = &(g163); hr_fi(_o2332, v_1508); hr_fs(_o2332, hr_str(")", 1)); }));
return;
 }
if (p_1510) { (void)(f247_ow(hr_str("(*", 2)));
(void)(f273_lv_name(v_1508));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
(void)(f273_lv_name(v_1508));
}
static bool f272_lv_isptr(int64_t v_1509) {
return (((((uint16_t)((uint64_t)((*({ hrv *_t2333 = &(g374); int64_t _i2333 = v_1509; (S12*)_t2333->b + hr_ix(_i2333, _t2333->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:112"); }))).fl_ & (uint64_t)((uint16_t)8LL)))) != (((uint16_t)0LL))) && ((((*({ hrv *_t2334 = &(g528); int64_t _i2334 = ((*({ hrv *_t2335 = &(g374); int64_t _i2335 = v_1509; (S12*)_t2335->b + hr_ix(_i2335, _t2335->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:112"); }))).ty_; (S1*)_t2334->b + hr_ix(_i2334, _t2334->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:112"); }))).k_) != (((uint8_t)10LL))));
}
static void f273_lv_name(int64_t v_1511) {
{ hsl _v2337 = f10_nm(((int64_t)(((*({ hrv *_t2338 = &(g374); int64_t _i2338 = v_1511; (S12*)_t2338->b + hr_ix(_i2338, _t2338->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:111"); }))).name_))); for (int64_t _k2337 = 0; _k2337 < _v2337.n; _k2337++) { uint8_t c_1512 = ((uint8_t*)_v2337.p)[_k2337]; (void)(({ hrv *_v2339 = &(g163); uint8_t _x2339 = ({ uint8_t _r2340; if ((((c_1512) == (((uint8_t)36LL))) || ((c_1512) == (((uint8_t)58LL))))) { _r2340 = ((uint8_t)95LL);  } else { _r2340 = c_1512;  } _r2340; }); uint8_t *_p2339 = (uint8_t*)hr_grow(_v2339, 1, sizeof _x2339); *_p2339 = _x2339; _p2339; }));
 } } _bk2336:; 
(void)(({ hrv *_o2341 = &(g163); hr_fs(_o2341, hr_str("_", 1)); hr_fi(_o2341, v_1511); }));
}
static void f274_gerr(int64_t n_1513, hsl m_1514) {
if ((((g182).n) > (((int64_t)0LL)))) { return;
 }
S3 x_1515 = (*({ hrv *_t2342 = &(g889); int64_t _i2342 = ((*({ hrv *_t2343 = &(g679); int64_t _i2343 = f103_max(n_1513, ((int64_t)0LL)); (S4*)_t2343->b + hr_ix(_i2343, _t2343->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:15"); }))).t_; (S3*)_t2342->b + hr_ix(_i2342, _t2342->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:15"); })); 
(void)(({ hrv *_v2344 = &(g182); hsl _s2344 = f10_nm(((int64_t)(((*({ hrv *_t2345 = &(g888); int64_t _i2345 = (x_1515).f_; (S2*)_t2345->b + hr_ix(_i2345, _t2345->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:15"); }))).name_))); hr_append(_v2344, _s2344.p, _s2344.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o2346 = &(g182); hr_fs(_o2346, hr_str(":", 1)); hr_fi(_o2346, (x_1515).line_); hr_fs(_o2346, hr_str(": error: ", 9)); hr_fs(_o2346, m_1514); }));
}
static void f275_gbin(int64_t n_1516) {
S4 x_1517 = (*({ hrv *_t2347 = &(g679); int64_t _i2347 = n_1516; (S4*)_t2347->b + hr_ix(_i2347, _t2347->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:255"); })); 
int64_t o_1518 = ((int64_t)((x_1517).op_)); 
int64_t a_1519 = ((int64_t)((x_1517).a_)); 
int64_t b_1520 = ((int64_t)((x_1517).b_)); 
if ((((o_1518) == (((int64_t)52LL))) || ((o_1518) == (((int64_t)53LL))))) { (void)(f247_ow(hr_str("(", 1)));
(void)(f276_gx(a_1519));
(void)(f247_ow(({ hsl _r2348; if (((o_1518) == (((int64_t)52LL)))) { _r2348 = hr_str(" && ", 4);  } else { _r2348 = hr_str(" || ", 4);  } _r2348; })));
(void)(f276_gx(b_1520));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
bool cmp_1524 = (((((((o_1518) == (((int64_t)37LL))) || ((o_1518) == (((int64_t)38LL)))) || ((o_1518) == (((int64_t)39LL)))) || ((o_1518) == (((int64_t)40LL)))) || ((o_1518) == (((int64_t)41LL)))) || ((o_1518) == (((int64_t)42LL)))); 
if (cmp_1524) { int64_t m_1525 = f211_ax(n_1516); 
int64_t ta_1526 = f266_fin(a_1519); 
int64_t tb_1527 = f266_fin(b_1520); 
if (((m_1525) == (((int64_t)1LL)))) { (void)(f247_ow(hr_str("((uint64_t)(", 12)));
(void)(f276_gx(a_1519));
(void)(f247_ow(hr_str(") ", 2)));
(void)(f247_ow(f277_cmp_op(o_1518)));
(void)(f247_ow(hr_str(" (uint64_t)(", 12)));
(void)(f276_gx(b_1520));
(void)(f247_ow(hr_str("))", 2)));
return;
 }
if (((m_1525) == (((int64_t)2LL)))) { if (((o_1518) == (((int64_t)38LL)))) { (void)(f247_ow(hr_str("!", 1)));
 }
(void)(f247_ow(hr_str("hr_streq(", 9)));
(void)(f278_gas(a_1519));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f278_gas(b_1520));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if (((m_1525) == (((int64_t)3LL)))) { int64_t et_1542 = ({ int64_t _r2349; if ((((((*({ hrv *_t2350 = &(g528); int64_t _i2350 = ta_1526; (S1*)_t2350->b + hr_ix(_i2350, _t2350->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:263"); }))).k_) == (((uint8_t)7LL))) || ((((*({ hrv *_t2351 = &(g528); int64_t _i2351 = ta_1526; (S1*)_t2351->b + hr_ix(_i2351, _t2351->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:263"); }))).k_) == (((uint8_t)19LL))))) { _r2349 = tb_1527;  } else { _r2349 = ta_1526;  } _r2349; }); 
(void)(f282_gen_heq(et_1542));
if (((o_1518) == (((int64_t)38LL)))) { (void)(f247_ow(hr_str("!", 1)));
 }
(void)(f247_ow(hr_str("heq", 3)));
(void)(f281_oi(et_1542));
(void)(f247_ow(hr_str("(", 1)));
if (f291_hsl_ty(et_1542)) { (void)(f278_gas(a_1519));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f278_gas(b_1520));
 } else { (void)(f292_gxas(a_1519, et_1542));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f292_gxas(b_1520, et_1542));
 }
(void)(f247_ow(hr_str(")", 1)));
return;
 }
int64_t ka_1635 = ((int64_t)(((*({ hrv *_t2352 = &(g528); int64_t _i2352 = ta_1526; (S1*)_t2352->b + hr_ix(_i2352, _t2352->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:264"); }))).k_)); 
if (((((ka_1635) == (((int64_t)10LL))) || ((ka_1635) == (((int64_t)11LL)))) || ((((*({ hrv *_t2353 = &(g528); int64_t _i2353 = tb_1527; (S1*)_t2353->b + hr_ix(_i2353, _t2353->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:265"); }))).k_) == (((uint8_t)10LL))))) { (void)(f247_ow(hr_str("((void*)(", 9)));
(void)(f276_gx(a_1519));
(void)(f247_ow(hr_str(") ", 2)));
(void)(f247_ow(f277_cmp_op(o_1518)));
(void)(f247_ow(hr_str(" (void*)(", 9)));
(void)(f276_gx(b_1520));
(void)(f247_ow(hr_str("))", 2)));
return;
 }
(void)(f247_ow(hr_str("((", 2)));
(void)(f276_gx(a_1519));
(void)(f247_ow(hr_str(") ", 2)));
(void)(f247_ow(f277_cmp_op(o_1518)));
(void)(f247_ow(hr_str(" (", 2)));
(void)(f276_gx(b_1520));
(void)(f247_ow(hr_str("))", 2)));
return;
 }
(void)(f293_garith(o_1518, f266_fin(n_1516), a_1519, b_1520, ((int64_t)0LL), n_1516));
}
static void f276_gx(int64_t n_1521) {
int64_t c_1522 = f149_cv(n_1521); 
int64_t t_1523 = f142_at(n_1521); 
if ((((c_1522) < (((int64_t)0LL))) || ((c_1522) == (t_1523)))) { (void)(f258_gx1(n_1521));
return;
 }
(void)(f257_gcv(n_1521, t_1523, c_1522));
}
static hsl f277_cmp_op(int64_t o_1528) {
if (((o_1528) == (((int64_t)37LL)))) { return hr_str("==", 2);
 }
if (((o_1528) == (((int64_t)38LL)))) { return hr_str("!=", 2);
 }
if (((o_1528) == (((int64_t)39LL)))) { return hr_str("<", 1);
 }
if (((o_1528) == (((int64_t)40LL)))) { return hr_str(">", 1);
 }
if (((o_1528) == (((int64_t)41LL)))) { return hr_str("<=", 2);
 }
if (((o_1528) == (((int64_t)42LL)))) { return hr_str(">=", 2);
 }
return hr_str("\077", 1);
}
static void f278_gas(int64_t n_1529) {
int64_t c_1530 = f149_cv(n_1529); 
int64_t t_1531 = f142_at(n_1529); 
if (((((c_1530) >= (((int64_t)0LL))) && ((c_1530) != (t_1531))) && ((((*({ hrv *_t2354 = &(g528); int64_t _i2354 = c_1530; (S1*)_t2354->b + hr_ix(_i2354, _t2354->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:194"); }))).k_) == (((uint8_t)9LL))))) { (void)(f279_gsl(n_1529, t_1531));
return;
 }
if ((((c_1530) >= (((int64_t)0LL))) && ((c_1530) != (t_1531)))) { int64_t p_1541 = f280_nt(); 
(void)(f247_ow(hr_str("({ ", 3)));
(void)(f248_ct(c_1530));
(void)(f247_ow(hr_str(" _t", 3)));
(void)(f281_oi(p_1541));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(n_1529));
(void)(f247_ow(hr_str("; ", 2)));
if (f255_is_res(c_1530)) { (void)(f247_ow(hr_str("hr_sl(_t", 8)));
(void)(f281_oi(p_1541));
(void)(f247_ow(hr_str(")", 1)));
 } else { if (f269_is_fix(c_1530)) { (void)(f247_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f281_oi(p_1541));
(void)(({ hrv *_o2355 = &(g163); hr_fs(_o2355, hr_str(".e, ", 4)); hr_fi(_o2355, ((*({ hrv *_t2356 = &(g528); int64_t _i2356 = c_1530; (S1*)_t2356->b + hr_ix(_i2356, _t2356->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:195"); }))).b_); hr_fs(_o2355, hr_str(" }", 2)); }));
 } else { if (((((*({ hrv *_t2357 = &(g528); int64_t _i2357 = c_1530; (S1*)_t2357->b + hr_ix(_i2357, _t2357->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:195"); }))).k_) == (((uint8_t)9LL)))) { (void)(f247_ow(hr_str("_t", 2)));
(void)(f281_oi(p_1541));
 } else { (void)(f247_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f281_oi(p_1541));
(void)(f247_ow(hr_str(".e, _t", 6)));
(void)(f281_oi(p_1541));
(void)(f247_ow(hr_str(".n }", 4)));
 }
 }
 }
(void)(f247_ow(hr_str("; })", 4)));
return;
 }
(void)(f279_gsl(n_1529, t_1531));
}
static void f279_gsl(int64_t n_1532, int64_t f_1533) {
int64_t d_1534 = f176_deref(f_1533); 
int64_t k_1535 = ((int64_t)(((*({ hrv *_t2358 = &(g528); int64_t _i2358 = d_1534; (S1*)_t2358->b + hr_ix(_i2358, _t2358->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:171"); }))).k_)); 
if ((((((*({ hrv *_t2359 = &(g528); int64_t _i2359 = f_1533; (S1*)_t2359->b + hr_ix(_i2359, _t2359->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:172"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2360 = &(g528); int64_t _i2360 = f_1533; (S1*)_t2360->b + hr_ix(_i2360, _t2360->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:172"); }))).c_) < (((int32_t)0LL))))) { int64_t p_1536 = f280_nt(); 
(void)(f247_ow(hr_str("({ ", 3)));
(void)(f248_ct(f_1533));
(void)(f247_ow(hr_str(" _t", 3)));
(void)(f281_oi(p_1536));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f262_gx0(n_1532));
(void)(f247_ow(hr_str("; ", 2)));
if (((k_1535) == (((int64_t)9LL)))) { (void)(f247_ow(hr_str("*_t", 3)));
(void)(f281_oi(p_1536));
 } else { if (f255_is_res(d_1534)) { (void)(f247_ow(hr_str("hr_sl(*_t", 9)));
(void)(f281_oi(p_1536));
(void)(f247_ow(hr_str(")", 1)));
 } else { if (f269_is_fix(d_1534)) { (void)(f247_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f281_oi(p_1536));
(void)(({ hrv *_o2361 = &(g163); hr_fs(_o2361, hr_str("->e, ", 5)); hr_fi(_o2361, ((*({ hrv *_t2362 = &(g528); int64_t _i2362 = d_1534; (S1*)_t2362->b + hr_ix(_i2362, _t2362->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:177"); }))).b_); hr_fs(_o2361, hr_str(" }", 2)); }));
 } else { (void)(f247_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f281_oi(p_1536));
(void)(f247_ow(hr_str("->e, _t", 7)));
(void)(f281_oi(p_1536));
(void)(f247_ow(hr_str("->n }", 5)));
 }
 }
 }
(void)(f247_ow(hr_str("; })", 4)));
return;
 }
if ((((k_1535) == (((int64_t)9LL))) || ((k_1535) == (((int64_t)18LL))))) { (void)(f262_gx0(n_1532));
return;
 }
if (f255_is_res(d_1534)) { (void)(f247_ow(hr_str("hr_sl(", 6)));
if (f259_is_place(n_1532)) { (void)(f262_gx0(n_1532));
 } else { int64_t tk0_1538 = f260_tmp(d_1534, true); 
(void)(f247_ow(hr_str("*hr_tmp(&", 9)));
(void)(f261_ot(tk0_1538));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f262_gx0(n_1532));
(void)(f247_ow(hr_str(")", 1)));
 }
(void)(f247_ow(hr_str(")", 1)));
return;
 }
int64_t p_1539 = f280_nt(); 
(void)(f247_ow(hr_str("({ ", 3)));
(void)(f248_ct(d_1534));
(void)(f247_ow(hr_str(" *_t", 4)));
(void)(f281_oi(p_1539));
(void)(f247_ow(hr_str(" = ", 3)));
if (f259_is_place(n_1532)) { (void)(f247_ow(hr_str("&(", 2)));
(void)(f262_gx0(n_1532));
(void)(f247_ow(hr_str(")", 1)));
 } else { int64_t tk0_1540 = f260_tmp(d_1534, false); 
(void)(f247_ow(hr_str("&(", 2)));
(void)(f261_ot(tk0_1540));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f262_gx0(n_1532));
(void)(f247_ow(hr_str(")", 1)));
 }
(void)(f247_ow(hr_str("; ", 2)));
if (f269_is_fix(d_1534)) { (void)(f247_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f281_oi(p_1539));
(void)(({ hrv *_o2363 = &(g163); hr_fs(_o2363, hr_str("->e, ", 5)); hr_fi(_o2363, ((*({ hrv *_t2364 = &(g528); int64_t _i2364 = d_1534; (S1*)_t2364->b + hr_ix(_i2364, _t2364->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:188"); }))).b_); hr_fs(_o2363, hr_str(" }", 2)); }));
 } else { (void)(f247_ow(hr_str("(hsl){ (uint8_t*)_t", 19)));
(void)(f281_oi(p_1539));
(void)(f247_ow(hr_str("->e, _t", 7)));
(void)(f281_oi(p_1539));
(void)(f247_ow(hr_str("->n }", 5)));
 }
(void)(f247_ow(hr_str("; })", 4)));
}
static int64_t f280_nt(void) {
g178++;
return g178;
}
static void f281_oi(int64_t v_1537) {
(void)(({ hrv *_o2365 = &(g163); hr_fi(_o2365, v_1537); }));
}
static void f282_gen_heq(int64_t t_1543) {
(void)(f250_cn_grow());
if ((((*({ hrv *_t2366 = &(g175); int64_t _i2366 = t_1543; (uint8_t*)_t2366->b + hr_ix(_i2366, _t2366->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:460"); }))) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t2367 = &((*({ hrv *_t2368 = &(g175); int64_t _i2368 = t_1543; (uint8_t*)_t2368->b + hr_ix(_i2368, _t2368->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:461"); }))); *_t2367 = ((uint8_t)1LL); }
S1 x_1544 = (*({ hrv *_t2369 = &(g528); int64_t _i2369 = t_1543; (S1*)_t2369->b + hr_ix(_i2369, _t2369->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:462"); })); 
int64_t k_1545 = ((int64_t)((x_1544).k_)); 
(void)(f249_cbody(t_1543));
bool sl_1546 = (((k_1545) == (((int64_t)9LL))) || ((((k_1545) == (((int64_t)8LL))) && (!(f269_is_fix(t_1543)))) && (!(f270_is_lim(t_1543))))); 
(void)(f283_comp_pre(t_1543, false));
L94 sig_1609 = ({ L94 _t2370; memset(&_t2370, 0, sizeof _t2370); _t2370.n = 0; _t2370; }); 
(void)(({ L94 *_l2371 = &(sig_1609); hrv _o2371 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2371, hr_str("static bool heq", 15)); hr_fi(&_o2371, t_1543); hr_fs(&_o2371, hr_str("(", 1)); if (_l2371->n + _o2371.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:467"); memcpy(_l2371->e + _l2371->n, _o2371.b, (size_t)_o2371.n); _l2371->n += _o2371.n; }));
hsl c_1610 = ({ hsl _r2372; if (sl_1546) { _r2372 = hr_str("hsl", 3);  } else { _r2372 = f251_cn(t_1543);  } _r2372; }); 
(void)(({ L94 *_v2373 = &(sig_1609); hsl _s2373 = c_1610; if (_v2373->n + _s2373.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:469"); memmove(_v2373->e + _v2373->n, _s2373.p, (size_t)_s2373.n * sizeof _v2373->e[0]); _v2373->n += _s2373.n; }));
(void)(({ L94 *_v2374 = &(sig_1609); hsl _s2374 = hr_str(" a, ", 4); if (_v2374->n + _s2374.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:469"); memmove(_v2374->e + _v2374->n, _s2374.p, (size_t)_s2374.n * sizeof _v2374->e[0]); _v2374->n += _s2374.n; }));
(void)(({ L94 *_v2375 = &(sig_1609); hsl _s2375 = c_1610; if (_v2375->n + _s2375.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:469"); memmove(_v2375->e + _v2375->n, _s2375.p, (size_t)_s2375.n * sizeof _v2375->e[0]); _v2375->n += _s2375.n; }));
(void)(({ L94 *_v2376 = &(sig_1609); hsl _s2376 = hr_str(" b)", 3); if (_v2376->n + _s2376.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:469"); memmove(_v2376->e + _v2376->n, _s2376.p, (size_t)_s2376.n * sizeof _v2376->e[0]); _v2376->n += _s2376.n; }));
(void)(({ hrv *_v2377 = &(g166); hsl _s2377 = ({ hsl _t2378 = ({ L94 *_t2379 = &(sig_1609); (hsl){ (uint8_t*)_t2379->e, _t2379->n }; }); int64_t _l2378 = 0, _h2378 = _t2378.n; if (_l2378 < 0 || _h2378 < _l2378 || _h2378 > _t2378.n) hr_slerr(_l2378, _h2378, _t2378.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:470"); (hsl){ _t2378.p + _l2378 * (int64_t)sizeof(uint8_t), _h2378 - _l2378 }; }); hr_append(_v2377, _s2377.p, _s2377.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2380 = &(g166); hsl _s2380 = hr_str(";\012", 2); hr_append(_v2380, _s2380.p, _s2380.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2381 = &(g169); hsl _s2381 = ({ hsl _t2382 = ({ L94 *_t2383 = &(sig_1609); (hsl){ (uint8_t*)_t2383->e, _t2383->n }; }); int64_t _l2382 = 0, _h2382 = _t2382.n; if (_l2382 < 0 || _h2382 < _l2382 || _h2382 > _t2382.n) hr_slerr(_l2382, _h2382, _t2382.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:471"); (hsl){ _t2382.p + _l2382 * (int64_t)sizeof(uint8_t), _h2382 - _l2382 }; }); hr_append(_v2381, _s2381.p, _s2381.n, sizeof(uint8_t)); }));
(void)(f288_hh(hr_str(" { ", 3)));
if ((((k_1545) == (((int64_t)5LL))) || ((k_1545) == (((int64_t)7LL))))) { int64_t si_1611 = ({ int64_t _r2384; if (((k_1545) == (((int64_t)5LL)))) { _r2384 = ((int64_t)((x_1544).a_));  } else { _r2384 = ((int64_t)(((*({ hrv *_t2385 = &(g534); int64_t _i2385 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2386 = &(g533); int64_t _i2386 = (x_1544).a_; (S8*)_t2386->b + hr_ix(_i2386, _t2386->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:473"); }))).v0_)) + (int64_t)((int64_t)((x_1544).c_)))); (S9*)_t2385->b + hr_ix(_i2385, _t2385->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:473"); }))).si_));  } _r2384; }); 
(void)(f288_hh(hr_str("return true", 11)));
if (((si_1611) >= (((int64_t)0LL)))) { int64_t f0_1612 = ((int64_t)(((*({ hrv *_t2387 = &(g531); int64_t _i2387 = si_1611; (S10*)_t2387->b + hr_ix(_i2387, _t2387->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:475"); }))).f0_)); 
{ int32_t _e2389 = ((*({ hrv *_t2390 = &(g531); int64_t _i2390 = si_1611; (S10*)_t2390->b + hr_ix(_i2390, _t2390->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:475"); }))).fnum_; for (int32_t _k2389 = 0; _k2389 < _e2389; _k2389++) { int32_t i_1613 = (int32_t)_k2389; S11 f_1614 = (*({ hrv *_t2391 = &(g532); int64_t _i2391 = ((int64_t)((int64_t)f0_1612 + (int64_t)((int64_t)(i_1613)))); (S11*)_t2391->b + hr_ix(_i2391, _t2391->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:475"); })); 
if ((((f_1614).ty_) < (((int32_t)0LL)))) { continue;
 }
L95 ea_1615 = ({ L95 _t2392; memset(&_t2392, 0, sizeof _t2392); _t2392.n = 0; _t2392; }); 
L95 eb_1616 = ({ L95 _t2393; memset(&_t2393, 0, sizeof _t2393); _t2393.n = 0; _t2393; }); 
(void)(({ L95 *_v2394 = &(ea_1615); hsl _s2394 = hr_str("a.", 2); if (_v2394->n + _s2394.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:475"); memmove(_v2394->e + _v2394->n, _s2394.p, (size_t)_s2394.n * sizeof _v2394->e[0]); _v2394->n += _s2394.n; }));
(void)(({ L95 *_v2395 = &(eb_1616); hsl _s2395 = hr_str("b.", 2); if (_v2395->n + _s2395.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:475"); memmove(_v2395->e + _v2395->n, _s2395.p, (size_t)_s2395.n * sizeof _v2395->e[0]); _v2395->n += _s2395.n; }));
{ hsl _v2397 = f10_nm(((int64_t)((f_1614).name_))); for (int64_t _k2397 = 0; _k2397 < _v2397.n; _k2397++) { uint8_t ch_1617 = ((uint8_t*)_v2397.p)[_k2397]; (void)(({ L95 *_v2398 = &(ea_1615); uint8_t _x2398 = ch_1617; if (_v2398->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:475"); _v2398->e[_v2398->n] = _x2398; &_v2398->e[_v2398->n++]; }));
(void)(({ L95 *_v2399 = &(eb_1616); uint8_t _x2399 = ch_1617; if (_v2399->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:475"); _v2399->e[_v2399->n] = _x2399; &_v2399->e[_v2399->n++]; }));
 } } _bk2396:; 
(void)(({ L95 *_v2400 = &(ea_1615); uint8_t _x2400 = ((uint8_t)95LL); if (_v2400->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:475"); _v2400->e[_v2400->n] = _x2400; &_v2400->e[_v2400->n++]; }));
(void)(({ L95 *_v2401 = &(eb_1616); uint8_t _x2401 = ((uint8_t)95LL); if (_v2401->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:475"); _v2401->e[_v2401->n] = _x2401; &_v2401->e[_v2401->n++]; }));
(void)(f288_hh(hr_str(" && ", 4)));
(void)(f290_heq_val(((int64_t)((f_1614).ty_)), ({ hsl _t2402 = ({ L95 *_t2403 = &(ea_1615); (hsl){ (uint8_t*)_t2403->e, _t2403->n }; }); int64_t _l2402 = 0, _h2402 = _t2402.n; if (_l2402 < 0 || _h2402 < _l2402 || _h2402 > _t2402.n) hr_slerr(_l2402, _h2402, _t2402.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:475"); (hsl){ _t2402.p + _l2402 * (int64_t)sizeof(uint8_t), _h2402 - _l2402 }; }), ({ hsl _t2404 = ({ L95 *_t2405 = &(eb_1616); (hsl){ (uint8_t*)_t2405->e, _t2405->n }; }); int64_t _l2404 = 0, _h2404 = _t2404.n; if (_l2404 < 0 || _h2404 < _l2404 || _h2404 > _t2404.n) hr_slerr(_l2404, _h2404, _t2404.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:475"); (hsl){ _t2404.p + _l2404 * (int64_t)sizeof(uint8_t), _h2404 - _l2404 }; })));
 } } _bk2388:; 
 }
(void)(f288_hh(hr_str("; ", 2)));
 }
if (((k_1545) == (((int64_t)6LL)))) { int64_t ei_1622 = ((int64_t)((x_1544).a_)); 
int64_t v0_1623 = ((int64_t)(((*({ hrv *_t2406 = &(g533); int64_t _i2406 = ei_1622; (S8*)_t2406->b + hr_ix(_i2406, _t2406->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:479"); }))).v0_)); 
(void)(f288_hh(hr_str("if (a.tag != b.tag) return false; ", 34)));
{ int32_t _e2408 = ((*({ hrv *_t2409 = &(g533); int64_t _i2409 = ei_1622; (S8*)_t2409->b + hr_ix(_i2409, _t2409->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:481"); }))).vnum_; for (int32_t _k2408 = 0; _k2408 < _e2408; _k2408++) { int32_t i_1624 = (int32_t)_k2408; S9 v_1625 = (*({ hrv *_t2410 = &(g534); int64_t _i2410 = ((int64_t)((int64_t)v0_1623 + (int64_t)((int64_t)(i_1624)))); (S9*)_t2410->b + hr_ix(_i2410, _t2410->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:481"); })); 
if (((((v_1625).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t2411 = &(g531); int64_t _i2411 = (v_1625).si_; (S10*)_t2411->b + hr_ix(_i2411, _t2411->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:481"); }))).zero_)))) { L97 ea_1626 = ({ L97 _t2412; memset(&_t2412, 0, sizeof _t2412); _t2412.n = 0; _t2412; }); 
L97 eb_1627 = ({ L97 _t2413; memset(&_t2413, 0, sizeof _t2413); _t2413.n = 0; _t2413; }); 
(void)(({ L97 *_l2414 = &(ea_1626); hrv _o2414 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2414, hr_str("a.u.v", 5)); hr_fi(&_o2414, i_1624); if (_l2414->n + _o2414.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:481"); memcpy(_l2414->e + _l2414->n, _o2414.b, (size_t)_o2414.n); _l2414->n += _o2414.n; }));
(void)(({ L97 *_l2415 = &(eb_1627); hrv _o2415 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2415, hr_str("b.u.v", 5)); hr_fi(&_o2415, i_1624); if (_l2415->n + _o2415.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:481"); memcpy(_l2415->e + _l2415->n, _o2415.b, (size_t)_o2415.n); _l2415->n += _o2415.n; }));
(void)(({ hrv *_o2416 = &(g169); hr_fs(_o2416, hr_str("if (a.tag == ", 13)); hr_fi(_o2416, i_1624); hr_fs(_o2416, hr_str(") return ", 9)); }));
(void)(f290_heq_val(f125_t_variant(ei_1622, ((int64_t)(i_1624))), ({ hsl _t2417 = ({ L97 *_t2418 = &(ea_1626); (hsl){ (uint8_t*)_t2418->e, _t2418->n }; }); int64_t _l2417 = 0, _h2417 = _t2417.n; if (_l2417 < 0 || _h2417 < _l2417 || _h2417 > _t2417.n) hr_slerr(_l2417, _h2417, _t2417.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:481"); (hsl){ _t2417.p + _l2417 * (int64_t)sizeof(uint8_t), _h2417 - _l2417 }; }), ({ hsl _t2419 = ({ L97 *_t2420 = &(eb_1627); (hsl){ (uint8_t*)_t2420->e, _t2420->n }; }); int64_t _l2419 = 0, _h2419 = _t2419.n; if (_l2419 < 0 || _h2419 < _l2419 || _h2419 > _t2419.n) hr_slerr(_l2419, _h2419, _t2419.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:481"); (hsl){ _t2419.p + _l2419 * (int64_t)sizeof(uint8_t), _h2419 - _l2419 }; })));
(void)(f288_hh(hr_str("; ", 2)));
 }
 } } _bk2407:; 
(void)(f288_hh(hr_str("return true; ", 13)));
 }
if ((((k_1545) == (((int64_t)8LL))) || ((k_1545) == (((int64_t)9LL))))) { int64_t e_1628 = ((int64_t)((x_1544).a_)); 
L95 ea_1629 = ({ L95 _t2421; memset(&_t2421, 0, sizeof _t2421); _t2421.n = 0; _t2421; }); 
L95 eb_1630 = ({ L95 _t2422; memset(&_t2422, 0, sizeof _t2422); _t2422.n = 0; _t2422; }); 
if (f269_is_fix(t_1543)) { (void)(({ hrv *_o2423 = &(g169); hr_fs(_o2423, hr_str("for (int64_t i = 0; i < ", 24)); hr_fi(_o2423, (x_1544).b_); hr_fs(_o2423, hr_str("; i++) if (!(", 13)); }));
(void)(({ L95 *_v2424 = &(ea_1629); hsl _s2424 = hr_str("a.e[i]", 6); if (_v2424->n + _s2424.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:487"); memmove(_v2424->e + _v2424->n, _s2424.p, (size_t)_s2424.n * sizeof _v2424->e[0]); _v2424->n += _s2424.n; }));
(void)(({ L95 *_v2425 = &(eb_1630); hsl _s2425 = hr_str("b.e[i]", 6); if (_v2425->n + _s2425.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:487"); memmove(_v2425->e + _v2425->n, _s2425.p, (size_t)_s2425.n * sizeof _v2425->e[0]); _v2425->n += _s2425.n; }));
 } else { if (f270_is_lim(t_1543)) { (void)(f288_hh(hr_str("if (a.n != b.n) return false; for (int64_t i = 0; i < a.n; i++) if (!(", 70)));
(void)(({ L95 *_v2426 = &(ea_1629); hsl _s2426 = hr_str("a.e[i]", 6); if (_v2426->n + _s2426.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:488"); memmove(_v2426->e + _v2426->n, _s2426.p, (size_t)_s2426.n * sizeof _v2426->e[0]); _v2426->n += _s2426.n; }));
(void)(({ L95 *_v2427 = &(eb_1630); hsl _s2427 = hr_str("b.e[i]", 6); if (_v2427->n + _s2427.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:488"); memmove(_v2427->e + _v2427->n, _s2427.p, (size_t)_s2427.n * sizeof _v2427->e[0]); _v2427->n += _s2427.n; }));
 } else { (void)(f288_hh(hr_str("if (a.n != b.n) return false; for (int64_t i = 0; i < a.n; i++) if (!(", 70)));
(void)(({ L95 *_v2428 = &(ea_1629); hsl _s2428 = hr_str("((", 2); if (_v2428->n + _s2428.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:489"); memmove(_v2428->e + _v2428->n, _s2428.p, (size_t)_s2428.n * sizeof _v2428->e[0]); _v2428->n += _s2428.n; }));
(void)(({ L95 *_v2429 = &(ea_1629); hsl _s2429 = f251_cn(e_1628); if (_v2429->n + _s2429.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:489"); memmove(_v2429->e + _v2429->n, _s2429.p, (size_t)_s2429.n * sizeof _v2429->e[0]); _v2429->n += _s2429.n; }));
(void)(({ L95 *_v2430 = &(ea_1629); hsl _s2430 = hr_str("*)a.p)[i]", 9); if (_v2430->n + _s2430.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:489"); memmove(_v2430->e + _v2430->n, _s2430.p, (size_t)_s2430.n * sizeof _v2430->e[0]); _v2430->n += _s2430.n; }));
(void)(({ L95 *_v2431 = &(eb_1630); hsl _s2431 = hr_str("((", 2); if (_v2431->n + _s2431.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:489"); memmove(_v2431->e + _v2431->n, _s2431.p, (size_t)_s2431.n * sizeof _v2431->e[0]); _v2431->n += _s2431.n; }));
(void)(({ L95 *_v2432 = &(eb_1630); hsl _s2432 = f251_cn(e_1628); if (_v2432->n + _s2432.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:489"); memmove(_v2432->e + _v2432->n, _s2432.p, (size_t)_s2432.n * sizeof _v2432->e[0]); _v2432->n += _s2432.n; }));
(void)(({ L95 *_v2433 = &(eb_1630); hsl _s2433 = hr_str("*)b.p)[i]", 9); if (_v2433->n + _s2433.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:489"); memmove(_v2433->e + _v2433->n, _s2433.p, (size_t)_s2433.n * sizeof _v2433->e[0]); _v2433->n += _s2433.n; }));
 }
 }
(void)(f290_heq_val(e_1628, ({ hsl _t2434 = ({ L95 *_t2435 = &(ea_1629); (hsl){ (uint8_t*)_t2435->e, _t2435->n }; }); int64_t _l2434 = 0, _h2434 = _t2434.n; if (_l2434 < 0 || _h2434 < _l2434 || _h2434 > _t2434.n) hr_slerr(_l2434, _h2434, _t2434.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:490"); (hsl){ _t2434.p + _l2434 * (int64_t)sizeof(uint8_t), _h2434 - _l2434 }; }), ({ hsl _t2436 = ({ L95 *_t2437 = &(eb_1630); (hsl){ (uint8_t*)_t2437->e, _t2437->n }; }); int64_t _l2436 = 0, _h2436 = _t2436.n; if (_l2436 < 0 || _h2436 < _l2436 || _h2436 > _t2436.n) hr_slerr(_l2436, _h2436, _t2436.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:490"); (hsl){ _t2436.p + _l2436 * (int64_t)sizeof(uint8_t), _h2436 - _l2436 }; })));
(void)(f288_hh(hr_str(")) return false; return true; ", 30)));
 }
if (((k_1545) == (((int64_t)14LL)))) { (void)(f288_hh(hr_str("return true; ", 13)));
 }
(void)(f288_hh(hr_str("}\012", 2)));
}
static void f283_comp_pre(int64_t t_1547, bool fmt_1548) {
S1 x_1549 = (*({ hrv *_t2438 = &(g528); int64_t _i2438 = t_1547; (S1*)_t2438->b + hr_ix(_i2438, _t2438->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:384"); })); 
int64_t k_1550 = ((int64_t)((x_1549).k_)); 
if (((k_1550) == (((int64_t)5LL)))) { int64_t si_1551 = ((int64_t)((x_1549).a_)); 
{ int32_t _e2440 = ((*({ hrv *_t2441 = &(g531); int64_t _i2441 = si_1551; (S10*)_t2441->b + hr_ix(_i2441, _t2441->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:385"); }))).fnum_; for (int32_t _k2440 = 0; _k2440 < _e2440; _k2440++) { int32_t i_1552 = (int32_t)_k2440; S11 f_1553 = (*({ hrv *_t2442 = &(g532); int64_t _i2442 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2443 = &(g531); int64_t _i2443 = si_1551; (S10*)_t2443->b + hr_ix(_i2443, _t2443->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:385"); }))).f0_)) + (int64_t)((int64_t)(i_1552)))); (S11*)_t2442->b + hr_ix(_i2442, _t2442->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:385"); })); 
if ((((f_1553).ty_) >= (((int32_t)0LL)))) { (void)(f284_comp_one(((int64_t)((f_1553).ty_)), fmt_1548));
 }
 } } _bk2439:; 
 }
if (((k_1550) == (((int64_t)7LL)))) { S9 v_1600 = (*({ hrv *_t2444 = &(g534); int64_t _i2444 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2445 = &(g533); int64_t _i2445 = (x_1549).a_; (S8*)_t2445->b + hr_ix(_i2445, _t2445->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:386"); }))).v0_)) + (int64_t)((int64_t)((x_1549).c_)))); (S9*)_t2444->b + hr_ix(_i2444, _t2444->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:386"); })); 
if ((((v_1600).si_) >= (((int32_t)0LL)))) { { int32_t _e2447 = ((*({ hrv *_t2448 = &(g531); int64_t _i2448 = (v_1600).si_; (S10*)_t2448->b + hr_ix(_i2448, _t2448->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:386"); }))).fnum_; for (int32_t _k2447 = 0; _k2447 < _e2447; _k2447++) { int32_t i_1601 = (int32_t)_k2447; S11 f_1602 = (*({ hrv *_t2449 = &(g532); int64_t _i2449 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2450 = &(g531); int64_t _i2450 = (v_1600).si_; (S10*)_t2450->b + hr_ix(_i2450, _t2450->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:386"); }))).f0_)) + (int64_t)((int64_t)(i_1601)))); (S11*)_t2449->b + hr_ix(_i2449, _t2449->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:386"); })); 
if ((((f_1602).ty_) >= (((int32_t)0LL)))) { (void)(f284_comp_one(((int64_t)((f_1602).ty_)), fmt_1548));
 }
 } } _bk2446:; 
 }
 }
if (((k_1550) == (((int64_t)6LL)))) { int64_t ei_1603 = ((int64_t)((x_1549).a_)); 
{ int32_t _e2452 = ((*({ hrv *_t2453 = &(g533); int64_t _i2453 = ei_1603; (S8*)_t2453->b + hr_ix(_i2453, _t2453->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:387"); }))).vnum_; for (int32_t _k2452 = 0; _k2452 < _e2452; _k2452++) { int32_t i_1604 = (int32_t)_k2452; S9 v_1605 = (*({ hrv *_t2454 = &(g534); int64_t _i2454 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2455 = &(g533); int64_t _i2455 = ei_1603; (S8*)_t2455->b + hr_ix(_i2455, _t2455->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:387"); }))).v0_)) + (int64_t)((int64_t)(i_1604)))); (S9*)_t2454->b + hr_ix(_i2454, _t2454->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:387"); })); 
if (((((v_1605).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t2456 = &(g531); int64_t _i2456 = (v_1605).si_; (S10*)_t2456->b + hr_ix(_i2456, _t2456->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:387"); }))).zero_)))) { if (fmt_1548) { { int32_t _e2458 = ((*({ hrv *_t2459 = &(g531); int64_t _i2459 = (v_1605).si_; (S10*)_t2459->b + hr_ix(_i2459, _t2459->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:387"); }))).fnum_; for (int32_t _k2458 = 0; _k2458 < _e2458; _k2458++) { int32_t j_1606 = (int32_t)_k2458; S11 f_1607 = (*({ hrv *_t2460 = &(g532); int64_t _i2460 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2461 = &(g531); int64_t _i2461 = (v_1605).si_; (S10*)_t2461->b + hr_ix(_i2461, _t2461->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:387"); }))).f0_)) + (int64_t)((int64_t)(j_1606)))); (S11*)_t2460->b + hr_ix(_i2460, _t2460->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:387"); })); 
if ((((f_1607).ty_) >= (((int32_t)0LL)))) { (void)(f284_comp_one(((int64_t)((f_1607).ty_)), fmt_1548));
 }
 } } _bk2457:; 
 } else { (void)(f282_gen_heq(f125_t_variant(ei_1603, ((int64_t)(i_1604)))));
 }
 }
 } } _bk2451:; 
 }
if ((((k_1550) == (((int64_t)8LL))) || ((k_1550) == (((int64_t)9LL))))) { (void)(f284_comp_one(((int64_t)((x_1549).a_)), fmt_1548));
 }
if (((k_1550) == (((int64_t)14LL)))) { { int32_t _e2463 = (x_1549).n_; for (int32_t _k2463 = 0; _k2463 < _e2463; _k2463++) { int32_t i_1608 = (int32_t)_k2463; (void)(f284_comp_one(((int64_t)((*({ hrv *_t2464 = &(g529); int64_t _i2464 = ((int64_t)((int64_t)((int64_t)((x_1549).l_)) + (int64_t)((int64_t)(i_1608)))); (int32_t*)_t2464->b + hr_ix(_i2464, _t2464->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:389"); })))), fmt_1548));
 } } _bk2462:; 
 }
}
static void f284_comp_one(int64_t t_1554, bool fmt_1555) {
int64_t u_1556 = ({ int64_t _r2465; if (((((*({ hrv *_t2466 = &(g528); int64_t _i2466 = t_1554; (S1*)_t2466->b + hr_ix(_i2466, _t2466->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:382"); }))).k_) == (((uint8_t)10LL)))) { _r2465 = ((int64_t)(((*({ hrv *_t2467 = &(g528); int64_t _i2467 = t_1554; (S1*)_t2467->b + hr_ix(_i2467, _t2467->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:382"); }))).a_));  } else { _r2465 = t_1554;  } _r2465; }); 
if ((((((*({ hrv *_t2468 = &(g528); int64_t _i2468 = t_1554; (S1*)_t2468->b + hr_ix(_i2468, _t2468->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:382"); }))).k_) == (((uint8_t)10LL))) && (!(fmt_1555)))) { return;
 }
if (f285_need_helper(u_1556)) { if (fmt_1555) { (void)(f286_gen_hf(u_1556));
 } else { (void)(f282_gen_heq(u_1556));
 }
 }
}
static bool f285_need_helper(int64_t t_1557) {
int64_t k_1558 = ((int64_t)(((*({ hrv *_t2469 = &(g528); int64_t _i2469 = t_1557; (S1*)_t2469->b + hr_ix(_i2469, _t2469->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:381"); }))).k_)); 
if (f165_is_byte_arr(t_1557)) { return false;
 }
if (((k_1558) == (((int64_t)10LL)))) { return f285_need_helper(((int64_t)(((*({ hrv *_t2470 = &(g528); int64_t _i2470 = t_1557; (S1*)_t2470->b + hr_ix(_i2470, _t2470->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:381"); }))).a_)));
 }
return (((((((k_1558) == (((int64_t)5LL))) || ((k_1558) == (((int64_t)6LL)))) || ((k_1558) == (((int64_t)7LL)))) || ((k_1558) == (((int64_t)8LL)))) || ((k_1558) == (((int64_t)9LL)))) || ((k_1558) == (((int64_t)14LL))));
}
static void f286_gen_hf(int64_t t_1559) {
(void)(f250_cn_grow());
if ((((*({ hrv *_t2471 = &(g174); int64_t _i2471 = t_1559; (uint8_t*)_t2471->b + hr_ix(_i2471, _t2471->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:404"); }))) != (((uint8_t)0LL)))) { return;
 }
{ uint8_t *_t2472 = &((*({ hrv *_t2473 = &(g174); int64_t _i2473 = t_1559; (uint8_t*)_t2473->b + hr_ix(_i2473, _t2473->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:405"); }))); *_t2472 = ((uint8_t)1LL); }
S1 x_1560 = (*({ hrv *_t2474 = &(g528); int64_t _i2474 = t_1559; (S1*)_t2474->b + hr_ix(_i2474, _t2474->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:406"); })); 
int64_t k_1561 = ((int64_t)((x_1560).k_)); 
(void)(f249_cbody(t_1559));
bool sl_1562 = (((k_1561) == (((int64_t)9LL))) || ((((k_1561) == (((int64_t)8LL))) && (!(f269_is_fix(t_1559)))) && (!(f270_is_lim(t_1559))))); 
(void)(f287_hf_pre(t_1559));
L94 sig_1564 = ({ L94 _t2475; memset(&_t2475, 0, sizeof _t2475); _t2475.n = 0; _t2475; }); 
(void)(({ L94 *_l2476 = &(sig_1564); hrv _o2476 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2476, hr_str("static void hf", 14)); hr_fi(&_o2476, t_1559); hr_fs(&_o2476, hr_str("(hrv *o, ", 9)); if (_l2476->n + _o2476.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:411"); memcpy(_l2476->e + _l2476->n, _o2476.b, (size_t)_o2476.n); _l2476->n += _o2476.n; }));
(void)(({ L94 *_v2477 = &(sig_1564); hsl _s2477 = ({ hsl _r2478; if (sl_1562) { _r2478 = hr_str("hsl", 3);  } else { _r2478 = f251_cn(t_1559);  } _r2478; }); if (_v2477->n + _s2477.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:412"); memmove(_v2477->e + _v2477->n, _s2477.p, (size_t)_s2477.n * sizeof _v2477->e[0]); _v2477->n += _s2477.n; }));
(void)(({ L94 *_v2479 = &(sig_1564); hsl _s2479 = hr_str(" v)", 3); if (_v2479->n + _s2479.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:413"); memmove(_v2479->e + _v2479->n, _s2479.p, (size_t)_s2479.n * sizeof _v2479->e[0]); _v2479->n += _s2479.n; }));
(void)(({ hrv *_v2480 = &(g166); hsl _s2480 = ({ hsl _t2481 = ({ L94 *_t2482 = &(sig_1564); (hsl){ (uint8_t*)_t2482->e, _t2482->n }; }); int64_t _l2481 = 0, _h2481 = _t2481.n; if (_l2481 < 0 || _h2481 < _l2481 || _h2481 > _t2481.n) hr_slerr(_l2481, _h2481, _t2481.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:414"); (hsl){ _t2481.p + _l2481 * (int64_t)sizeof(uint8_t), _h2481 - _l2481 }; }); hr_append(_v2480, _s2480.p, _s2480.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2483 = &(g166); hsl _s2483 = hr_str(";\012", 2); hr_append(_v2483, _s2483.p, _s2483.n, sizeof(uint8_t)); }));
int64_t s0_1565 = (g169).n; 
(void)(({ hrv *_v2484 = &(g169); hsl _s2484 = ({ hsl _t2485 = ({ L94 *_t2486 = &(sig_1564); (hsl){ (uint8_t*)_t2486->e, _t2486->n }; }); int64_t _l2485 = 0, _h2485 = _t2485.n; if (_l2485 < 0 || _h2485 < _l2485 || _h2485 > _t2485.n) hr_slerr(_l2485, _h2485, _t2485.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:416"); (hsl){ _t2485.p + _l2485 * (int64_t)sizeof(uint8_t), _h2485 - _l2485 }; }); hr_append(_v2484, _s2484.p, _s2484.n, sizeof(uint8_t)); }));
(void)(f288_hh(hr_str(" { ", 3)));
if (((k_1561) == (((int64_t)5LL)))) { int64_t si_1567 = ((int64_t)((x_1560).a_)); 
int64_t f0_1568 = ((int64_t)(((*({ hrv *_t2487 = &(g531); int64_t _i2487 = si_1567; (S10*)_t2487->b + hr_ix(_i2487, _t2487->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:418"); }))).f0_)); 
(void)(f288_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f288_hh(f10_nm(((int64_t)(((*({ hrv *_t2488 = &(g531); int64_t _i2488 = si_1567; (S10*)_t2488->b + hr_ix(_i2488, _t2488->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:419"); }))).name_)))));
(void)(f288_hh(hr_str(" { \"); ", 7)));
bool first_1569 = true; 
{ int32_t _e2490 = ((*({ hrv *_t2491 = &(g531); int64_t _i2491 = si_1567; (S10*)_t2491->b + hr_ix(_i2491, _t2491->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:421"); }))).fnum_; for (int32_t _k2490 = 0; _k2490 < _e2490; _k2490++) { int32_t i_1570 = (int32_t)_k2490; S11 f_1571 = (*({ hrv *_t2492 = &(g532); int64_t _i2492 = ((int64_t)((int64_t)f0_1568 + (int64_t)((int64_t)(i_1570)))); (S11*)_t2492->b + hr_ix(_i2492, _t2492->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:421"); })); 
if ((((f_1571).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1569))) { (void)(f288_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1569 = false;
L95 e_1572 = ({ L95 _t2493; memset(&_t2493, 0, sizeof _t2493); _t2493.n = 0; _t2493; }); 
(void)(({ L95 *_v2494 = &(e_1572); hsl _s2494 = hr_str("v.", 2); if (_v2494->n + _s2494.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:421"); memmove(_v2494->e + _v2494->n, _s2494.p, (size_t)_s2494.n * sizeof _v2494->e[0]); _v2494->n += _s2494.n; }));
{ hsl _v2496 = f10_nm(((int64_t)((f_1571).name_))); for (int64_t _k2496 = 0; _k2496 < _v2496.n; _k2496++) { uint8_t c_1573 = ((uint8_t*)_v2496.p)[_k2496]; (void)(({ L95 *_v2497 = &(e_1572); uint8_t _x2497 = c_1573; if (_v2497->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:421"); _v2497->e[_v2497->n] = _x2497; &_v2497->e[_v2497->n++]; }));
 } } _bk2495:; 
(void)(({ L95 *_v2498 = &(e_1572); uint8_t _x2498 = ((uint8_t)95LL); if (_v2498->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:421"); _v2498->e[_v2498->n] = _x2498; &_v2498->e[_v2498->n++]; }));
(void)(f289_hf_val(((int64_t)((f_1571).ty_)), ({ hsl _t2499 = ({ L95 *_t2500 = &(e_1572); (hsl){ (uint8_t*)_t2500->e, _t2500->n }; }); int64_t _l2499 = 0, _h2499 = _t2499.n; if (_l2499 < 0 || _h2499 < _l2499 || _h2499 > _t2499.n) hr_slerr(_l2499, _h2499, _t2499.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:421"); (hsl){ _t2499.p + _l2499 * (int64_t)sizeof(uint8_t), _h2499 - _l2499 }; })));
 } } _bk2489:; 
(void)(f288_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 }
if (((k_1561) == (((int64_t)6LL)))) { int64_t ei_1578 = ((int64_t)((x_1560).a_)); 
int64_t v0_1579 = ((int64_t)(((*({ hrv *_t2501 = &(g533); int64_t _i2501 = ei_1578; (S8*)_t2501->b + hr_ix(_i2501, _t2501->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:425"); }))).v0_)); 
{ int32_t _e2503 = ((*({ hrv *_t2504 = &(g533); int64_t _i2504 = ei_1578; (S8*)_t2504->b + hr_ix(_i2504, _t2504->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:426"); }))).vnum_; for (int32_t _k2503 = 0; _k2503 < _e2503; _k2503++) { int32_t i_1580 = (int32_t)_k2503; S9 v_1581 = (*({ hrv *_t2505 = &(g534); int64_t _i2505 = ((int64_t)((int64_t)v0_1579 + (int64_t)((int64_t)(i_1580)))); (S9*)_t2505->b + hr_ix(_i2505, _t2505->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:427"); })); 
(void)(({ hrv *_o2506 = &(g169); hr_fs(_o2506, hr_str("if (v.tag == ", 13)); hr_fi(_o2506, i_1580); hr_fs(_o2506, hr_str(") { ", 4)); }));
if (((((v_1581).si_) >= (((int32_t)0LL))) && ((((*({ hrv *_t2507 = &(g531); int64_t _i2507 = (v_1581).si_; (S10*)_t2507->b + hr_ix(_i2507, _t2507->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:429"); }))).fnum_) > (((int32_t)0LL))))) { (void)(f288_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f288_hh(f10_nm(((int64_t)((v_1581).name_)))));
(void)(f288_hh(hr_str(" { \"); ", 7)));
bool first_1582 = true; 
int64_t sf0_1583 = ((int64_t)(((*({ hrv *_t2508 = &(g531); int64_t _i2508 = (v_1581).si_; (S10*)_t2508->b + hr_ix(_i2508, _t2508->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:429"); }))).f0_)); 
{ int32_t _e2510 = ((*({ hrv *_t2511 = &(g531); int64_t _i2511 = (v_1581).si_; (S10*)_t2511->b + hr_ix(_i2511, _t2511->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:429"); }))).fnum_; for (int32_t _k2510 = 0; _k2510 < _e2510; _k2510++) { int32_t j_1584 = (int32_t)_k2510; S11 f_1585 = (*({ hrv *_t2512 = &(g532); int64_t _i2512 = ((int64_t)((int64_t)sf0_1583 + (int64_t)((int64_t)(j_1584)))); (S11*)_t2512->b + hr_ix(_i2512, _t2512->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:429"); })); 
if ((((f_1585).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1582))) { (void)(f288_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1582 = false;
L95 e_1586 = ({ L95 _t2513; memset(&_t2513, 0, sizeof _t2513); _t2513.n = 0; _t2513; }); 
(void)(({ L95 *_l2514 = &(e_1586); hrv _o2514 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2514, hr_str("v.u.v", 5)); hr_fi(&_o2514, i_1580); hr_fs(&_o2514, hr_str(".", 1)); if (_l2514->n + _o2514.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:429"); memcpy(_l2514->e + _l2514->n, _o2514.b, (size_t)_o2514.n); _l2514->n += _o2514.n; }));
{ hsl _v2516 = f10_nm(((int64_t)((f_1585).name_))); for (int64_t _k2516 = 0; _k2516 < _v2516.n; _k2516++) { uint8_t c_1587 = ((uint8_t*)_v2516.p)[_k2516]; (void)(({ L95 *_v2517 = &(e_1586); uint8_t _x2517 = c_1587; if (_v2517->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:429"); _v2517->e[_v2517->n] = _x2517; &_v2517->e[_v2517->n++]; }));
 } } _bk2515:; 
(void)(({ L95 *_v2518 = &(e_1586); uint8_t _x2518 = ((uint8_t)95LL); if (_v2518->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:429"); _v2518->e[_v2518->n] = _x2518; &_v2518->e[_v2518->n++]; }));
(void)(f289_hf_val(((int64_t)((f_1585).ty_)), ({ hsl _t2519 = ({ L95 *_t2520 = &(e_1586); (hsl){ (uint8_t*)_t2520->e, _t2520->n }; }); int64_t _l2519 = 0, _h2519 = _t2519.n; if (_l2519 < 0 || _h2519 < _l2519 || _h2519 > _t2519.n) hr_slerr(_l2519, _h2519, _t2519.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:429"); (hsl){ _t2519.p + _l2519 * (int64_t)sizeof(uint8_t), _h2519 - _l2519 }; })));
 } } _bk2509:; 
(void)(f288_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 } else { (void)(f288_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f288_hh(f10_nm(((int64_t)(((*({ hrv *_t2521 = &(g533); int64_t _i2521 = ei_1578; (S8*)_t2521->b + hr_ix(_i2521, _t2521->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:430"); }))).name_)))));
(void)(f288_hh(hr_str(".", 1)));
(void)(f288_hh(f10_nm(((int64_t)((v_1581).name_)))));
(void)(f288_hh(hr_str("\"); ", 4)));
 }
(void)(f288_hh(hr_str("} ", 2)));
 } } _bk2502:; 
 }
if (((k_1561) == (((int64_t)7LL)))) { int64_t ei_1588 = ((int64_t)((x_1560).a_)); 
S9 v_1589 = (*({ hrv *_t2522 = &(g534); int64_t _i2522 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2523 = &(g533); int64_t _i2523 = ei_1588; (S8*)_t2523->b + hr_ix(_i2523, _t2523->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:435"); }))).v0_)) + (int64_t)((int64_t)((x_1560).c_)))); (S9*)_t2522->b + hr_ix(_i2522, _t2522->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:435"); })); 
if (((((v_1589).si_) >= (((int32_t)0LL))) && ((((*({ hrv *_t2524 = &(g531); int64_t _i2524 = (v_1589).si_; (S10*)_t2524->b + hr_ix(_i2524, _t2524->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:436"); }))).fnum_) > (((int32_t)0LL))))) { (void)(f288_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f288_hh(f10_nm(((int64_t)((v_1589).name_)))));
(void)(f288_hh(hr_str(" { \"); ", 7)));
bool first_1590 = true; 
int64_t sf0_1591 = ((int64_t)(((*({ hrv *_t2525 = &(g531); int64_t _i2525 = (v_1589).si_; (S10*)_t2525->b + hr_ix(_i2525, _t2525->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:436"); }))).f0_)); 
{ int32_t _e2527 = ((*({ hrv *_t2528 = &(g531); int64_t _i2528 = (v_1589).si_; (S10*)_t2528->b + hr_ix(_i2528, _t2528->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:436"); }))).fnum_; for (int32_t _k2527 = 0; _k2527 < _e2527; _k2527++) { int32_t j_1592 = (int32_t)_k2527; S11 f_1593 = (*({ hrv *_t2529 = &(g532); int64_t _i2529 = ((int64_t)((int64_t)sf0_1591 + (int64_t)((int64_t)(j_1592)))); (S11*)_t2529->b + hr_ix(_i2529, _t2529->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:436"); })); 
if ((((f_1593).ty_) < (((int32_t)0LL)))) { continue;
 }
if ((!(first_1590))) { (void)(f288_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
first_1590 = false;
L95 e_1594 = ({ L95 _t2530; memset(&_t2530, 0, sizeof _t2530); _t2530.n = 0; _t2530; }); 
(void)(({ L95 *_v2531 = &(e_1594); hsl _s2531 = hr_str("v.", 2); if (_v2531->n + _s2531.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:436"); memmove(_v2531->e + _v2531->n, _s2531.p, (size_t)_s2531.n * sizeof _v2531->e[0]); _v2531->n += _s2531.n; }));
{ hsl _v2533 = f10_nm(((int64_t)((f_1593).name_))); for (int64_t _k2533 = 0; _k2533 < _v2533.n; _k2533++) { uint8_t c_1595 = ((uint8_t*)_v2533.p)[_k2533]; (void)(({ L95 *_v2534 = &(e_1594); uint8_t _x2534 = c_1595; if (_v2534->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:436"); _v2534->e[_v2534->n] = _x2534; &_v2534->e[_v2534->n++]; }));
 } } _bk2532:; 
(void)(({ L95 *_v2535 = &(e_1594); uint8_t _x2535 = ((uint8_t)95LL); if (_v2535->n >= 128) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:436"); _v2535->e[_v2535->n] = _x2535; &_v2535->e[_v2535->n++]; }));
(void)(f289_hf_val(((int64_t)((f_1593).ty_)), ({ hsl _t2536 = ({ L95 *_t2537 = &(e_1594); (hsl){ (uint8_t*)_t2537->e, _t2537->n }; }); int64_t _l2536 = 0, _h2536 = _t2536.n; if (_l2536 < 0 || _h2536 < _l2536 || _h2536 > _t2536.n) hr_slerr(_l2536, _h2536, _t2536.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:436"); (hsl){ _t2536.p + _l2536 * (int64_t)sizeof(uint8_t), _h2536 - _l2536 }; })));
 } } _bk2526:; 
(void)(f288_hh(hr_str("hr_fc(o, \" }\"); ", 16)));
 } else { (void)(f288_hh(hr_str("hr_fc(o, \"", 10)));
(void)(f288_hh(f10_nm(((int64_t)(((*({ hrv *_t2538 = &(g533); int64_t _i2538 = ei_1588; (S8*)_t2538->b + hr_ix(_i2538, _t2538->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:437"); }))).name_)))));
(void)(f288_hh(hr_str(".", 1)));
(void)(f288_hh(f10_nm(((int64_t)((v_1589).name_)))));
(void)(f288_hh(hr_str("\"); ", 4)));
 }
 }
if ((((k_1561) == (((int64_t)8LL))) || ((k_1561) == (((int64_t)9LL))))) { int64_t e_1596 = ((int64_t)((x_1560).a_)); 
(void)(f249_cbody(e_1596));
(void)(f288_hh(hr_str("hr_fb(o, '['); ", 15)));
if (f269_is_fix(t_1559)) { (void)(({ hrv *_o2539 = &(g169); hr_fs(_o2539, hr_str("for (int64_t i = 0; i < ", 24)); hr_fi(_o2539, (x_1560).b_); hr_fs(_o2539, hr_str("; i++) { if (i) hr_fc(o, \", \"); ", 32)); }));
(void)(f289_hf_val(e_1596, hr_str("v.e[i]", 6)));
(void)(f288_hh(hr_str("} ", 2)));
 } else { if (f270_is_lim(t_1559)) { (void)(f288_hh(hr_str("for (int64_t i = 0; i < v.n; i++) { if (i) hr_fc(o, \", \"); ", 59)));
(void)(f289_hf_val(e_1596, hr_str("v.e[i]", 6)));
(void)(f288_hh(hr_str("} ", 2)));
 } else { (void)(f288_hh(hr_str("for (int64_t i = 0; i < v.n; i++) { if (i) hr_fc(o, \", \"); ", 59)));
L95 ex_1597 = ({ L95 _t2540; memset(&_t2540, 0, sizeof _t2540); _t2540.n = 0; _t2540; }); 
(void)(({ L95 *_v2541 = &(ex_1597); hsl _s2541 = hr_str("((", 2); if (_v2541->n + _s2541.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:445"); memmove(_v2541->e + _v2541->n, _s2541.p, (size_t)_s2541.n * sizeof _v2541->e[0]); _v2541->n += _s2541.n; }));
(void)(({ L95 *_v2542 = &(ex_1597); hsl _s2542 = f251_cn(e_1596); if (_v2542->n + _s2542.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:445"); memmove(_v2542->e + _v2542->n, _s2542.p, (size_t)_s2542.n * sizeof _v2542->e[0]); _v2542->n += _s2542.n; }));
(void)(({ L95 *_v2543 = &(ex_1597); hsl _s2543 = hr_str("*)v.p)[i]", 9); if (_v2543->n + _s2543.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:445"); memmove(_v2543->e + _v2543->n, _s2543.p, (size_t)_s2543.n * sizeof _v2543->e[0]); _v2543->n += _s2543.n; }));
(void)(f289_hf_val(e_1596, ({ hsl _t2544 = ({ L95 *_t2545 = &(ex_1597); (hsl){ (uint8_t*)_t2545->e, _t2545->n }; }); int64_t _l2544 = 0, _h2544 = _t2544.n; if (_l2544 < 0 || _h2544 < _l2544 || _h2544 > _t2544.n) hr_slerr(_l2544, _h2544, _t2544.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:445"); (hsl){ _t2544.p + _l2544 * (int64_t)sizeof(uint8_t), _h2544 - _l2544 }; })));
(void)(f288_hh(hr_str("} ", 2)));
 }
 }
(void)(f288_hh(hr_str("hr_fb(o, ']'); ", 15)));
 }
if (((k_1561) == (((int64_t)14LL)))) { { int32_t _e2547 = (x_1560).n_; for (int32_t _k2547 = 0; _k2547 < _e2547; _k2547++) { int32_t i_1598 = (int32_t)_k2547; if (((i_1598) > (((int32_t)0LL)))) { (void)(f288_hh(hr_str("hr_fc(o, \", \"); ", 16)));
 }
L96 e_1599 = ({ L96 _t2548; memset(&_t2548, 0, sizeof _t2548); _t2548.n = 0; _t2548; }); 
(void)(({ L96 *_l2549 = &(e_1599); hrv _o2549 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2549, hr_str("v.r", 3)); hr_fi(&_o2549, i_1598); if (_l2549->n + _o2549.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:448"); memcpy(_l2549->e + _l2549->n, _o2549.b, (size_t)_o2549.n); _l2549->n += _o2549.n; }));
(void)(f289_hf_val(((int64_t)((*({ hrv *_t2550 = &(g529); int64_t _i2550 = ((int64_t)((int64_t)((int64_t)((x_1560).l_)) + (int64_t)((int64_t)(i_1598)))); (int32_t*)_t2550->b + hr_ix(_i2550, _t2550->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:448"); })))), ({ hsl _t2551 = ({ L96 *_t2552 = &(e_1599); (hsl){ (uint8_t*)_t2552->e, _t2552->n }; }); int64_t _l2551 = 0, _h2551 = _t2551.n; if (_l2551 < 0 || _h2551 < _l2551 || _h2551 > _t2551.n) hr_slerr(_l2551, _h2551, _t2551.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:448"); (hsl){ _t2551.p + _l2551 * (int64_t)sizeof(uint8_t), _h2551 - _l2551 }; })));
 } } _bk2546:; 
 }
(void)(f288_hh(hr_str("}\012", 2)));
}
static void f287_hf_pre(int64_t t_1563) {
(void)(f283_comp_pre(t_1563, true));
}
static void f288_hh(hsl s_1566) {
(void)(({ hrv *_v2553 = &(g169); hsl _s2553 = s_1566; hr_append(_v2553, _s2553.p, _s2553.n, sizeof(uint8_t)); }));
}
static void f289_hf_val(int64_t t_1574, hsl e_1575) {
int64_t k_1576 = ((int64_t)(((*({ hrv *_t2554 = &(g528); int64_t _i2554 = t_1574; (S1*)_t2554->b + hr_ix(_i2554, _t2554->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:393"); }))).k_)); 
if (f165_is_byte_arr(t_1574)) { if (f269_is_fix(t_1574)) { (void)(({ hrv *_o2555 = &(g169); hr_fs(_o2555, hr_str("hr_fq(o, (hsl){ (uint8_t*)(", 27)); hr_fs(_o2555, e_1575); hr_fs(_o2555, hr_str(").e, ", 5)); hr_fi(_o2555, ((*({ hrv *_t2556 = &(g528); int64_t _i2556 = t_1574; (S1*)_t2556->b + hr_ix(_i2556, _t2556->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:394"); }))).b_); hr_fs(_o2555, hr_str(" }); ", 5)); }));
return;
 }
if (f270_is_lim(t_1574)) { (void)(({ hrv *_o2557 = &(g169); hr_fs(_o2557, hr_str("hr_fq(o, (hsl){ (uint8_t*)(", 27)); hr_fs(_o2557, e_1575); hr_fs(_o2557, hr_str(").e, (", 6)); hr_fs(_o2557, e_1575); hr_fs(_o2557, hr_str(").n }); ", 8)); }));
return;
 }
if (((((*({ hrv *_t2558 = &(g528); int64_t _i2558 = t_1574; (S1*)_t2558->b + hr_ix(_i2558, _t2558->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:394"); }))).k_) == (((uint8_t)9LL)))) { (void)(({ hrv *_o2559 = &(g169); hr_fs(_o2559, hr_str("hr_fq(o, ", 9)); hr_fs(_o2559, e_1575); hr_fs(_o2559, hr_str("); ", 3)); }));
return;
 }
(void)(({ hrv *_o2560 = &(g169); hr_fs(_o2560, hr_str("hr_fq(o, hr_sl(", 15)); hr_fs(_o2560, e_1575); hr_fs(_o2560, hr_str(")); ", 4)); }));
return;
 }
if (((k_1576) == (((int64_t)3LL)))) { (void)(({ hrv *_o2561 = &(g169); hr_fs(_o2561, ({ hsl _r2562; if (f153_is_signed(t_1574)) { _r2562 = hr_str("hr_fi(o, ", 9);  } else { _r2562 = hr_str("hr_fu(o, ", 9);  } _r2562; })); hr_fs(_o2561, e_1575); hr_fs(_o2561, hr_str("); ", 3)); }));
return;
 }
if (((k_1576) == (((int64_t)4LL)))) { (void)(({ hrv *_o2563 = &(g169); hr_fs(_o2563, ({ hsl _r2564; if (((((*({ hrv *_t2565 = &(g528); int64_t _i2565 = t_1574; (S1*)_t2565->b + hr_ix(_i2565, _t2565->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:396"); }))).s_) == (((uint8_t)4LL)))) { _r2564 = hr_str("hr_ff(o, ", 9);  } else { _r2564 = hr_str("hr_fd(o, ", 9);  } _r2564; })); hr_fs(_o2563, e_1575); hr_fs(_o2563, hr_str("); ", 3)); }));
return;
 }
if (((k_1576) == (((int64_t)2LL)))) { (void)(({ hrv *_o2566 = &(g169); hr_fs(_o2566, hr_str("hr_fc(o, (", 10)); hr_fs(_o2566, e_1575); hr_fs(_o2566, hr_str(") \077 \"true\" : \"false\"); ", 23)); }));
return;
 }
if (((k_1576) == (((int64_t)10LL)))) { if (((((*({ hrv *_t2567 = &(g528); int64_t _i2567 = t_1574; (S1*)_t2567->b + hr_ix(_i2567, _t2567->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:398"); }))).c_) >= (((int32_t)0LL)))) { (void)(({ hrv *_o2568 = &(g169); hr_fs(_o2568, hr_str("hr_fu(o, ", 9)); hr_fs(_o2568, e_1575); hr_fs(_o2568, hr_str("); ", 3)); }));
return;
 }
L94 pe_1577 = ({ L94 _t2569; memset(&_t2569, 0, sizeof _t2569); _t2569.n = 0; _t2569; }); 
(void)(({ L94 *_l2570 = &(pe_1577); hrv _o2570 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2570, hr_str("(*(", 3)); hr_fs(&_o2570, e_1575); hr_fs(&_o2570, hr_str("))", 2)); if (_l2570->n + _o2570.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:398"); memcpy(_l2570->e + _l2570->n, _o2570.b, (size_t)_o2570.n); _l2570->n += _o2570.n; }));
(void)(({ hrv *_o2571 = &(g169); hr_fs(_o2571, hr_str("if (", 4)); hr_fs(_o2571, e_1575); hr_fs(_o2571, hr_str(") { ", 4)); }));
(void)(f289_hf_val(((int64_t)(((*({ hrv *_t2572 = &(g528); int64_t _i2572 = t_1574; (S1*)_t2572->b + hr_ix(_i2572, _t2572->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:398"); }))).a_)), ({ hsl _t2573 = ({ L94 *_t2574 = &(pe_1577); (hsl){ (uint8_t*)_t2574->e, _t2574->n }; }); int64_t _l2573 = 0, _h2573 = _t2573.n; if (_l2573 < 0 || _h2573 < _l2573 || _h2573 > _t2573.n) hr_slerr(_l2573, _h2573, _t2573.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:398"); (hsl){ _t2573.p + _l2573 * (int64_t)sizeof(uint8_t), _h2573 - _l2573 }; })));
(void)(f288_hh(hr_str("} else hr_fc(o, \"null\"); ", 25)));
return;
 }
if (((((k_1576) == (((int64_t)8LL))) && (!(f269_is_fix(t_1574)))) && (!(f270_is_lim(t_1574))))) { (void)(({ hrv *_o2575 = &(g169); hr_fs(_o2575, hr_str("hf", 2)); hr_fi(_o2575, t_1574); hr_fs(_o2575, hr_str("(o, hr_sl(", 10)); hr_fs(_o2575, e_1575); hr_fs(_o2575, hr_str(")); ", 4)); }));
return;
 }
(void)(({ hrv *_o2576 = &(g169); hr_fs(_o2576, hr_str("hf", 2)); hr_fi(_o2576, t_1574); hr_fs(_o2576, hr_str("(o, ", 4)); hr_fs(_o2576, e_1575); hr_fs(_o2576, hr_str("); ", 3)); }));
}
static void f290_heq_val(int64_t t_1618, hsl a_1619, hsl b_1620) {
int64_t k_1621 = ((int64_t)(((*({ hrv *_t2577 = &(g528); int64_t _i2577 = t_1618; (S1*)_t2577->b + hr_ix(_i2577, _t2577->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:452"); }))).k_)); 
if ((((((k_1621) == (((int64_t)3LL))) || ((k_1621) == (((int64_t)4LL)))) || ((k_1621) == (((int64_t)2LL)))) || ((k_1621) == (((int64_t)10LL))))) { (void)(({ hrv *_o2578 = &(g169); hr_fs(_o2578, hr_str("(", 1)); hr_fs(_o2578, a_1619); hr_fs(_o2578, hr_str(") == (", 6)); hr_fs(_o2578, b_1620); hr_fs(_o2578, hr_str(")", 1)); }));
return;
 }
(void)(f282_gen_heq(t_1618));
if ((((k_1621) == (((int64_t)9LL))) || ((((k_1621) == (((int64_t)8LL))) && (!(f269_is_fix(t_1618)))) && (!(f270_is_lim(t_1618)))))) { (void)(({ hrv *_o2579 = &(g169); hr_fs(_o2579, hr_str("heq", 3)); hr_fi(_o2579, t_1618); hr_fs(_o2579, hr_str("(hr_sl(", 7)); hr_fs(_o2579, a_1619); hr_fs(_o2579, hr_str("), hr_sl(", 9)); hr_fs(_o2579, b_1620); hr_fs(_o2579, hr_str("))", 2)); }));
return;
 }
(void)(({ hrv *_o2580 = &(g169); hr_fs(_o2580, hr_str("heq", 3)); hr_fi(_o2580, t_1618); hr_fs(_o2580, hr_str("(", 1)); hr_fs(_o2580, a_1619); hr_fs(_o2580, hr_str(", ", 2)); hr_fs(_o2580, b_1620); hr_fs(_o2580, hr_str(")", 1)); }));
}
static bool f291_hsl_ty(int64_t t_1631) {
return (((((*({ hrv *_t2581 = &(g528); int64_t _i2581 = t_1631; (S1*)_t2581->b + hr_ix(_i2581, _t2581->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:746"); }))).k_) == (((uint8_t)9LL))) || ((((((*({ hrv *_t2582 = &(g528); int64_t _i2582 = t_1631; (S1*)_t2582->b + hr_ix(_i2582, _t2582->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:746"); }))).k_) == (((uint8_t)8LL))) && (!(f269_is_fix(t_1631)))) && (!(f270_is_lim(t_1631)))));
}
static void f292_gxas(int64_t n_1632, int64_t t_1633) {
int64_t f_1634 = f266_fin(n_1632); 
if (((f_1634) == (t_1633))) { (void)(f276_gx(n_1632));
return;
 }
(void)(f257_gcv(n_1632, f142_at(n_1632), t_1633));
}
static void f293_garith(int64_t o_1636, int64_t t0_1637, int64_t a_1638, int64_t b_1639, int64_t tv_1640, int64_t loc_1641) {
int64_t t_1642 = ({ int64_t _r2583; if (((((*({ hrv *_t2584 = &(g528); int64_t _i2584 = t0_1637; (S1*)_t2584->b + hr_ix(_i2584, _t2584->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:236"); }))).k_) == (((uint8_t)12LL)))) { _r2583 = g540;  } else { _r2583 = ({ int64_t _r2585; if (((((*({ hrv *_t2586 = &(g528); int64_t _i2586 = t0_1637; (S1*)_t2586->b + hr_ix(_i2586, _t2586->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:236"); }))).k_) == (((uint8_t)13LL)))) { _r2585 = g546;  } else { _r2585 = t0_1637;  } _r2585; });  } _r2583; }); 
int64_t k_1643 = ((int64_t)(((*({ hrv *_t2587 = &(g528); int64_t _i2587 = t_1642; (S1*)_t2587->b + hr_ix(_i2587, _t2587->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:237"); }))).k_)); 
int64_t lk_1644 = f177_leaf_kind(t_1642); 
if (((lk_1644) >= (((int64_t)4LL)))) { int64_t ta_1645 = ({ int64_t _r2588; if (((a_1638) >= (((int64_t)0LL)))) { _r2588 = f266_fin(a_1638);  } else { _r2588 = t_1642;  } _r2588; }); 
int64_t tb_1646 = ({ int64_t _r2589; if (((b_1639) >= (((int64_t)0LL)))) { _r2589 = f266_fin(b_1639);  } else { _r2589 = t_1642;  } _r2589; }); 
if (((ta_1645) != (t_1642))) { if (((o_1636) != (((int64_t)23LL)))) { (void)(f274_gerr(loc_1641, hr_str("only * takes a scalar on the left of a struct or array", 54)));
return;
 }
(void)(f247_ow(hr_str("hop", 3)));
(void)(f281_oi(t_1642));
(void)(f247_ow(hr_str("_", 1)));
(void)(f281_oi(o_1636));
(void)(f247_ow(hr_str("(", 1)));
(void)(f294_gopnd(b_1639, tv_1640));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f294_gopnd(a_1638, tv_1640));
(void)(f247_ow(hr_str(")", 1)));
(void)(f295_gen_hop(t_1642, o_1636, ta_1645));
return;
 }
(void)(f247_ow(hr_str("hop", 3)));
(void)(f281_oi(t_1642));
(void)(f247_ow(hr_str("_", 1)));
(void)(f281_oi(o_1636));
(void)(f247_ow(hr_str("(", 1)));
(void)(f294_gopnd(a_1638, tv_1640));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f294_gopnd(b_1639, tv_1640));
(void)(f247_ow(hr_str(")", 1)));
(void)(f295_gen_hop(t_1642, o_1636, tb_1646));
return;
 }
if (((k_1643) == (((int64_t)4LL)))) { if (((o_1636) == (((int64_t)25LL)))) { (void)(f247_ow(({ hsl _r2590; if (((((*({ hrv *_t2591 = &(g528); int64_t _i2591 = t_1642; (S1*)_t2591->b + hr_ix(_i2591, _t2591->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:244"); }))).s_) == (((uint8_t)4LL)))) { _r2590 = hr_str("fmodf(", 6);  } else { _r2590 = hr_str("fmod(", 5);  } _r2590; })));
(void)(f294_gopnd(a_1638, tv_1640));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f294_gopnd(b_1639, tv_1640));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
(void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(t_1642));
(void)(f247_ow(hr_str(")(", 2)));
(void)(f294_gopnd(a_1638, tv_1640));
(void)(f247_ow(hr_str(" ", 1)));
(void)(f247_ow(f297_ar_op(o_1636)));
(void)(f247_ow(hr_str(" ", 1)));
(void)(f294_gopnd(b_1639, tv_1640));
(void)(f247_ow(hr_str("))", 2)));
return;
 }
if (((k_1643) == (((int64_t)2LL)))) { (void)(f247_ow(hr_str("((", 2)));
(void)(f294_gopnd(a_1638, tv_1640));
(void)(f247_ow(hr_str(") ", 2)));
(void)(f247_ow(f297_ar_op(o_1636)));
(void)(f247_ow(hr_str(" (", 2)));
(void)(f294_gopnd(b_1639, tv_1640));
(void)(f247_ow(hr_str("))", 2)));
return;
 }
bool sg_1677 = (((k_1643) == (((int64_t)3LL))) && f153_is_signed(t_1642)); 
if ((((o_1636) == (((int64_t)24LL))) || ((o_1636) == (((int64_t)25LL))))) { (void)(f247_ow(({ hsl _r2592; if (((o_1636) == (((int64_t)24LL)))) { _r2592 = ({ hsl _r2593; if (sg_1677) { _r2593 = hr_str("HR_SDIV(", 8);  } else { _r2593 = hr_str("HR_UDIV(", 8);  } _r2593; });  } else { _r2592 = ({ hsl _r2594; if (sg_1677) { _r2594 = hr_str("HR_SMOD(", 8);  } else { _r2594 = hr_str("HR_UDIV_MOD(", 12);  } _r2594; });  } _r2592; })));
(void)(f248_ct(t_1642));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f294_gopnd(a_1638, tv_1640));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f294_gopnd(b_1639, tv_1640));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f298_wloc(loc_1641));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if ((((o_1636) == (((int64_t)43LL))) || ((o_1636) == (((int64_t)44LL))))) { (void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(t_1642));
(void)(f247_ow(hr_str(")((", 3)));
(void)(f294_gopnd(a_1638, tv_1640));
(void)(f247_ow(hr_str(") ", 2)));
(void)(f247_ow(f297_ar_op(o_1636)));
(void)(f247_ow(hr_str(" ((", 3)));
(void)(f294_gopnd(b_1639, tv_1640));
(void)(({ hrv *_o2595 = &(g163); hr_fs(_o2595, hr_str(") & ", 4)); hr_fi(_o2595, ((int64_t)((int64_t)f154_ibits(t_1642) - (int64_t)((int64_t)1LL)))); hr_fs(_o2595, hr_str(")))", 3)); }));
return;
 }
(void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(t_1642));
(void)(f247_ow(hr_str(")(", 2)));
if (sg_1677) { (void)(f247_ow(hr_str("(int64_t)", 9)));
 } else { (void)(f247_ow(hr_str("(uint64_t)", 10)));
 }
(void)(f294_gopnd(a_1638, tv_1640));
(void)(f247_ow(hr_str(" ", 1)));
(void)(f247_ow(f297_ar_op(o_1636)));
(void)(f247_ow(hr_str(" ", 1)));
if (sg_1677) { (void)(f247_ow(hr_str("(int64_t)", 9)));
 } else { (void)(f247_ow(hr_str("(uint64_t)", 10)));
 }
(void)(f294_gopnd(b_1639, tv_1640));
(void)(f247_ow(hr_str("))", 2)));
}
static void f294_gopnd(int64_t n_1647, int64_t tv_1648) {
if (((n_1647) >= (((int64_t)0LL)))) { (void)(f276_gx(n_1647));
 } else { (void)(({ hrv *_o2596 = &(g163); hr_fs(_o2596, hr_str("(*_t", 4)); hr_fi(_o2596, tv_1648); hr_fs(_o2596, hr_str(")", 1)); }));
 }
}
static void f295_gen_hop(int64_t t_1649, int64_t o_1650, int64_t bt_1651) {
int64_t key_1652 = ((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)((int64_t)(t_1649)) * (int64_t)((int64_t)4096LL))) + (int64_t)((int64_t)((int64_t)((int64_t)(o_1650)) * (int64_t)((int64_t)64LL))))) + (int64_t)({ int64_t _r2597; if (((bt_1651) == (t_1649))) { _r2597 = ((int64_t)0LL);  } else { _r2597 = ((int64_t)1LL);  } _r2597; }))); 
{ hrv *_v2599 = &(g240); for (int64_t _k2599 = 0; _k2599 < _v2599->n; _k2599++) { int64_t h_1653 = ((int64_t*)_v2599->b)[_k2599]; if (((h_1653) == (key_1652))) { return;
 }
 } } _bk2598:; 
(void)(({ hrv *_v2600 = &(g240); int64_t _x2600 = key_1652; int64_t *_p2600 = (int64_t*)hr_grow(_v2600, 1, sizeof _x2600); *_p2600 = _x2600; _p2600; }));
(void)(f249_cbody(t_1649));
int64_t lt_1654 = f178_leaf_type(t_1649); 
bool sc_1655 = ((bt_1651) != (t_1649)); 
L94 sig_1656 = ({ L94 _t2601; memset(&_t2601, 0, sizeof _t2601); _t2601.n = 0; _t2601; }); 
(void)(({ L94 *_l2602 = &(sig_1656); hrv _o2602 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2602, hr_str("static ", 7)); if (_l2602->n + _o2602.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:505"); memcpy(_l2602->e + _l2602->n, _o2602.b, (size_t)_o2602.n); _l2602->n += _o2602.n; }));
(void)(({ L94 *_v2603 = &(sig_1656); hsl _s2603 = f251_cn(t_1649); if (_v2603->n + _s2603.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:505"); memmove(_v2603->e + _v2603->n, _s2603.p, (size_t)_s2603.n * sizeof _v2603->e[0]); _v2603->n += _s2603.n; }));
(void)(({ L94 *_l2604 = &(sig_1656); hrv _o2604 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2604, hr_str(" hop", 4)); hr_fi(&_o2604, t_1649); hr_fs(&_o2604, hr_str("_", 1)); hr_fi(&_o2604, o_1650); hr_fs(&_o2604, hr_str("(", 1)); if (_l2604->n + _o2604.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:505"); memcpy(_l2604->e + _l2604->n, _o2604.b, (size_t)_o2604.n); _l2604->n += _o2604.n; }));
(void)(({ L94 *_v2605 = &(sig_1656); hsl _s2605 = f251_cn(t_1649); if (_v2605->n + _s2605.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:506"); memmove(_v2605->e + _v2605->n, _s2605.p, (size_t)_s2605.n * sizeof _v2605->e[0]); _v2605->n += _s2605.n; }));
(void)(({ L94 *_v2606 = &(sig_1656); hsl _s2606 = hr_str(" a, ", 4); if (_v2606->n + _s2606.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:506"); memmove(_v2606->e + _v2606->n, _s2606.p, (size_t)_s2606.n * sizeof _v2606->e[0]); _v2606->n += _s2606.n; }));
(void)(({ L94 *_v2607 = &(sig_1656); hsl _s2607 = f251_cn(({ int64_t _r2608; if (sc_1655) { _r2608 = bt_1651;  } else { _r2608 = t_1649;  } _r2608; })); if (_v2607->n + _s2607.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:506"); memmove(_v2607->e + _v2607->n, _s2607.p, (size_t)_s2607.n * sizeof _v2607->e[0]); _v2607->n += _s2607.n; }));
(void)(({ L94 *_v2609 = &(sig_1656); hsl _s2609 = hr_str(" b)", 3); if (_v2609->n + _s2609.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:506"); memmove(_v2609->e + _v2609->n, _s2609.p, (size_t)_s2609.n * sizeof _v2609->e[0]); _v2609->n += _s2609.n; }));
(void)(({ hrv *_v2610 = &(g166); hsl _s2610 = ({ hsl _t2611 = ({ L94 *_t2612 = &(sig_1656); (hsl){ (uint8_t*)_t2612->e, _t2612->n }; }); int64_t _l2611 = 0, _h2611 = _t2611.n; if (_l2611 < 0 || _h2611 < _l2611 || _h2611 > _t2611.n) hr_slerr(_l2611, _h2611, _t2611.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:507"); (hsl){ _t2611.p + _l2611 * (int64_t)sizeof(uint8_t), _h2611 - _l2611 }; }); hr_append(_v2610, _s2610.p, _s2610.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2613 = &(g166); hsl _s2613 = hr_str(";\012", 2); hr_append(_v2613, _s2613.p, _s2613.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2614 = &(g169); hsl _s2614 = ({ hsl _t2615 = ({ L94 *_t2616 = &(sig_1656); (hsl){ (uint8_t*)_t2616->e, _t2616->n }; }); int64_t _l2615 = 0, _h2615 = _t2615.n; if (_l2615 < 0 || _h2615 < _l2615 || _h2615 > _t2615.n) hr_slerr(_l2615, _h2615, _t2615.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:508"); (hsl){ _t2615.p + _l2615 * (int64_t)sizeof(uint8_t), _h2615 - _l2615 }; }); hr_append(_v2614, _s2614.p, _s2614.n, sizeof(uint8_t)); }));
(void)(f288_hh(hr_str(" { ", 3)));
(void)(({ hrv *_v2617 = &(g169); hsl _s2617 = f251_cn(t_1649); hr_append(_v2617, _s2617.p, _s2617.n, sizeof(uint8_t)); }));
(void)(f288_hh(hr_str(" r; ", 4)));
(void)(f296_hop_body(t_1649, o_1650, hr_str("r", 1), hr_str("a", 1), hr_str("b", 1), sc_1655));
(void)(f288_hh(hr_str("return r; }\012", 12)));
}
static void f296_hop_body(int64_t t_1657, int64_t o_1658, hsl r_1659, hsl a_1660, hsl b_1661, bool sc_1662) {
int64_t k_1663 = ((int64_t)(((*({ hrv *_t2618 = &(g528); int64_t _i2618 = t_1657; (S1*)_t2618->b + hr_ix(_i2618, _t2618->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:513"); }))).k_)); 
if ((((k_1663) == (((int64_t)3LL))) || ((k_1663) == (((int64_t)4LL))))) { (void)(({ hrv *_o2619 = &(g169); hr_fs(_o2619, r_1659); hr_fs(_o2619, hr_str(" = (", 4)); }));
(void)(({ hrv *_v2620 = &(g169); hsl _s2620 = f251_cn(t_1657); hr_append(_v2620, _s2620.p, _s2620.n, sizeof(uint8_t)); }));
(void)(({ hrv *_o2621 = &(g169); hr_fs(_o2621, hr_str(")((", 3)); hr_fs(_o2621, a_1660); hr_fs(_o2621, hr_str(") ", 2)); hr_fs(_o2621, f297_ar_op(o_1658)); hr_fs(_o2621, hr_str(" (", 2)); hr_fs(_o2621, b_1661); hr_fs(_o2621, hr_str(")); ", 4)); }));
return;
 }
if (((k_1663) == (((int64_t)5LL)))) { int64_t si_1665 = ((int64_t)(((*({ hrv *_t2622 = &(g528); int64_t _i2622 = t_1657; (S1*)_t2622->b + hr_ix(_i2622, _t2622->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:516"); }))).a_)); 
int64_t f0_1666 = ((int64_t)(((*({ hrv *_t2623 = &(g531); int64_t _i2623 = si_1665; (S10*)_t2623->b + hr_ix(_i2623, _t2623->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:516"); }))).f0_)); 
{ int32_t _e2625 = ((*({ hrv *_t2626 = &(g531); int64_t _i2626 = si_1665; (S10*)_t2626->b + hr_ix(_i2626, _t2626->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:517"); }))).fnum_; for (int32_t _k2625 = 0; _k2625 < _e2625; _k2625++) { int32_t i_1667 = (int32_t)_k2625; S11 f_1668 = (*({ hrv *_t2627 = &(g532); int64_t _i2627 = ((int64_t)((int64_t)f0_1666 + (int64_t)((int64_t)(i_1667)))); (S11*)_t2627->b + hr_ix(_i2627, _t2627->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:518"); })); 
if ((((f_1668).ty_) < (((int32_t)0LL)))) { continue;
 }
L94 rr_1669 = ({ L94 _t2628; memset(&_t2628, 0, sizeof _t2628); _t2628.n = 0; _t2628; }); 
L94 aa_1670 = ({ L94 _t2629; memset(&_t2629, 0, sizeof _t2629); _t2629.n = 0; _t2629; }); 
L94 bb_1671 = ({ L94 _t2630; memset(&_t2630, 0, sizeof _t2630); _t2630.n = 0; _t2630; }); 
(void)(({ L94 *_v2631 = &(rr_1669); hsl _s2631 = r_1659; if (_v2631->n + _s2631.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:520"); memmove(_v2631->e + _v2631->n, _s2631.p, (size_t)_s2631.n * sizeof _v2631->e[0]); _v2631->n += _s2631.n; }));
(void)(({ L94 *_v2632 = &(rr_1669); uint8_t _x2632 = ((uint8_t)46LL); if (_v2632->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:520"); _v2632->e[_v2632->n] = _x2632; &_v2632->e[_v2632->n++]; }));
(void)(({ L94 *_v2633 = &(aa_1670); hsl _s2633 = a_1660; if (_v2633->n + _s2633.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:520"); memmove(_v2633->e + _v2633->n, _s2633.p, (size_t)_s2633.n * sizeof _v2633->e[0]); _v2633->n += _s2633.n; }));
(void)(({ L94 *_v2634 = &(aa_1670); uint8_t _x2634 = ((uint8_t)46LL); if (_v2634->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:520"); _v2634->e[_v2634->n] = _x2634; &_v2634->e[_v2634->n++]; }));
(void)(({ L94 *_v2635 = &(bb_1671); hsl _s2635 = b_1661; if (_v2635->n + _s2635.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:520"); memmove(_v2635->e + _v2635->n, _s2635.p, (size_t)_s2635.n * sizeof _v2635->e[0]); _v2635->n += _s2635.n; }));
if ((!(sc_1662))) { (void)(({ L94 *_v2636 = &(bb_1671); uint8_t _x2636 = ((uint8_t)46LL); if (_v2636->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:520"); _v2636->e[_v2636->n] = _x2636; &_v2636->e[_v2636->n++]; }));
 }
{ hsl _v2638 = f10_nm(((int64_t)((f_1668).name_))); for (int64_t _k2638 = 0; _k2638 < _v2638.n; _k2638++) { uint8_t ch_1672 = ((uint8_t*)_v2638.p)[_k2638]; (void)(({ L94 *_v2639 = &(rr_1669); uint8_t _x2639 = ch_1672; if (_v2639->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:521"); _v2639->e[_v2639->n] = _x2639; &_v2639->e[_v2639->n++]; }));
(void)(({ L94 *_v2640 = &(aa_1670); uint8_t _x2640 = ch_1672; if (_v2640->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:521"); _v2640->e[_v2640->n] = _x2640; &_v2640->e[_v2640->n++]; }));
if ((!(sc_1662))) { (void)(({ L94 *_v2641 = &(bb_1671); uint8_t _x2641 = ch_1672; if (_v2641->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:521"); _v2641->e[_v2641->n] = _x2641; &_v2641->e[_v2641->n++]; }));
 }
 } } _bk2637:; 
(void)(({ L94 *_v2642 = &(rr_1669); uint8_t _x2642 = ((uint8_t)95LL); if (_v2642->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:522"); _v2642->e[_v2642->n] = _x2642; &_v2642->e[_v2642->n++]; }));
(void)(({ L94 *_v2643 = &(aa_1670); uint8_t _x2643 = ((uint8_t)95LL); if (_v2643->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:522"); _v2643->e[_v2643->n] = _x2643; &_v2643->e[_v2643->n++]; }));
if ((!(sc_1662))) { (void)(({ L94 *_v2644 = &(bb_1671); uint8_t _x2644 = ((uint8_t)95LL); if (_v2644->n >= 256) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:522"); _v2644->e[_v2644->n] = _x2644; &_v2644->e[_v2644->n++]; }));
 }
(void)(f296_hop_body(((int64_t)((f_1668).ty_)), o_1658, ({ hsl _t2645 = ({ L94 *_t2646 = &(rr_1669); (hsl){ (uint8_t*)_t2646->e, _t2646->n }; }); int64_t _l2645 = 0, _h2645 = _t2645.n; if (_l2645 < 0 || _h2645 < _l2645 || _h2645 > _t2645.n) hr_slerr(_l2645, _h2645, _t2645.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:523"); (hsl){ _t2645.p + _l2645 * (int64_t)sizeof(uint8_t), _h2645 - _l2645 }; }), ({ hsl _t2647 = ({ L94 *_t2648 = &(aa_1670); (hsl){ (uint8_t*)_t2648->e, _t2648->n }; }); int64_t _l2647 = 0, _h2647 = _t2647.n; if (_l2647 < 0 || _h2647 < _l2647 || _h2647 > _t2647.n) hr_slerr(_l2647, _h2647, _t2647.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:523"); (hsl){ _t2647.p + _l2647 * (int64_t)sizeof(uint8_t), _h2647 - _l2647 }; }), ({ hsl _t2649 = ({ L94 *_t2650 = &(bb_1671); (hsl){ (uint8_t*)_t2650->e, _t2650->n }; }); int64_t _l2649 = 0, _h2649 = _t2649.n; if (_l2649 < 0 || _h2649 < _l2649 || _h2649 > _t2649.n) hr_slerr(_l2649, _h2649, _t2649.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:523"); (hsl){ _t2649.p + _l2649 * (int64_t)sizeof(uint8_t), _h2649 - _l2649 }; }), sc_1662));
 } } _bk2624:; 
return;
 }
if (f269_is_fix(t_1657)) { int64_t p_1673 = f280_nt(); 
(void)(({ hrv *_o2651 = &(g169); hr_fs(_o2651, hr_str("for (int64_t _i", 15)); hr_fi(_o2651, p_1673); hr_fs(_o2651, hr_str(" = 0; _i", 8)); hr_fi(_o2651, p_1673); hr_fs(_o2651, hr_str(" < ", 3)); hr_fi(_o2651, ((*({ hrv *_t2652 = &(g528); int64_t _i2652 = t_1657; (S1*)_t2652->b + hr_ix(_i2652, _t2652->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:529"); }))).b_); hr_fs(_o2651, hr_str("; _i", 4)); hr_fi(_o2651, p_1673); hr_fs(_o2651, hr_str("++) { ", 6)); }));
L94 rr_1674 = ({ L94 _t2653; memset(&_t2653, 0, sizeof _t2653); _t2653.n = 0; _t2653; }); 
L94 aa_1675 = ({ L94 _t2654; memset(&_t2654, 0, sizeof _t2654); _t2654.n = 0; _t2654; }); 
L94 bb_1676 = ({ L94 _t2655; memset(&_t2655, 0, sizeof _t2655); _t2655.n = 0; _t2655; }); 
(void)(({ L94 *_l2656 = &(rr_1674); hrv _o2656 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2656, r_1659); hr_fs(&_o2656, hr_str(".e[_i", 5)); hr_fi(&_o2656, p_1673); hr_fs(&_o2656, hr_str("]", 1)); if (_l2656->n + _o2656.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:531"); memcpy(_l2656->e + _l2656->n, _o2656.b, (size_t)_o2656.n); _l2656->n += _o2656.n; }));
(void)(({ L94 *_l2657 = &(aa_1675); hrv _o2657 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2657, a_1660); hr_fs(&_o2657, hr_str(".e[_i", 5)); hr_fi(&_o2657, p_1673); hr_fs(&_o2657, hr_str("]", 1)); if (_l2657->n + _o2657.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:531"); memcpy(_l2657->e + _l2657->n, _o2657.b, (size_t)_o2657.n); _l2657->n += _o2657.n; }));
if (sc_1662) { (void)(({ L94 *_v2658 = &(bb_1676); hsl _s2658 = b_1661; if (_v2658->n + _s2658.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:531"); memmove(_v2658->e + _v2658->n, _s2658.p, (size_t)_s2658.n * sizeof _v2658->e[0]); _v2658->n += _s2658.n; }));
 } else { (void)(({ L94 *_l2659 = &(bb_1676); hrv _o2659 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2659, b_1661); hr_fs(&_o2659, hr_str(".e[_i", 5)); hr_fi(&_o2659, p_1673); hr_fs(&_o2659, hr_str("]", 1)); if (_l2659->n + _o2659.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:531"); memcpy(_l2659->e + _l2659->n, _o2659.b, (size_t)_o2659.n); _l2659->n += _o2659.n; }));
 }
(void)(f296_hop_body(((int64_t)(((*({ hrv *_t2660 = &(g528); int64_t _i2660 = t_1657; (S1*)_t2660->b + hr_ix(_i2660, _t2660->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:532"); }))).a_)), o_1658, ({ hsl _t2661 = ({ L94 *_t2662 = &(rr_1674); (hsl){ (uint8_t*)_t2662->e, _t2662->n }; }); int64_t _l2661 = 0, _h2661 = _t2661.n; if (_l2661 < 0 || _h2661 < _l2661 || _h2661 > _t2661.n) hr_slerr(_l2661, _h2661, _t2661.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:532"); (hsl){ _t2661.p + _l2661 * (int64_t)sizeof(uint8_t), _h2661 - _l2661 }; }), ({ hsl _t2663 = ({ L94 *_t2664 = &(aa_1675); (hsl){ (uint8_t*)_t2664->e, _t2664->n }; }); int64_t _l2663 = 0, _h2663 = _t2663.n; if (_l2663 < 0 || _h2663 < _l2663 || _h2663 > _t2663.n) hr_slerr(_l2663, _h2663, _t2663.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:532"); (hsl){ _t2663.p + _l2663 * (int64_t)sizeof(uint8_t), _h2663 - _l2663 }; }), ({ hsl _t2665 = ({ L94 *_t2666 = &(bb_1676); (hsl){ (uint8_t*)_t2666->e, _t2666->n }; }); int64_t _l2665 = 0, _h2665 = _t2665.n; if (_l2665 < 0 || _h2665 < _l2665 || _h2665 > _t2665.n) hr_slerr(_l2665, _h2665, _t2665.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:532"); (hsl){ _t2665.p + _l2665 * (int64_t)sizeof(uint8_t), _h2665 - _l2665 }; }), sc_1662));
(void)(f288_hh(hr_str("} ", 2)));
 }
}
static hsl f297_ar_op(int64_t o_1664) {
if ((((o_1664) == (((int64_t)21LL))) || ((o_1664) == (((int64_t)26LL))))) { return hr_str("+", 1);
 }
if ((((o_1664) == (((int64_t)22LL))) || ((o_1664) == (((int64_t)27LL))))) { return hr_str("-", 1);
 }
if ((((o_1664) == (((int64_t)23LL))) || ((o_1664) == (((int64_t)28LL))))) { return hr_str("*", 1);
 }
if ((((o_1664) == (((int64_t)24LL))) || ((o_1664) == (((int64_t)29LL))))) { return hr_str("/", 1);
 }
if ((((o_1664) == (((int64_t)25LL))) || ((o_1664) == (((int64_t)30LL))))) { return hr_str("%", 1);
 }
if ((((o_1664) == (((int64_t)49LL))) || ((o_1664) == (((int64_t)31LL))))) { return hr_str("&", 1);
 }
if ((((o_1664) == (((int64_t)50LL))) || ((o_1664) == (((int64_t)32LL))))) { return hr_str("|", 1);
 }
if ((((o_1664) == (((int64_t)51LL))) || ((o_1664) == (((int64_t)33LL))))) { return hr_str("^", 1);
 }
if ((((o_1664) == (((int64_t)43LL))) || ((o_1664) == (((int64_t)45LL))))) { return hr_str("<<", 2);
 }
if ((((o_1664) == (((int64_t)44LL))) || ((o_1664) == (((int64_t)46LL))))) { return hr_str(">>", 2);
 }
return hr_str("\077", 1);
}
static void f298_wloc(int64_t n_1678) {
S3 x_1679 = (*({ hrv *_t2667 = &(g889); int64_t _i2667 = ((*({ hrv *_t2668 = &(g679); int64_t _i2668 = f103_max(n_1678, ((int64_t)0LL)); (S4*)_t2668->b + hr_ix(_i2668, _t2668->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:100"); }))).t_; (S3*)_t2667->b + hr_ix(_i2667, _t2667->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:100"); })); 
(void)(f247_ow(hr_str("\"", 1)));
{ hsl _v2670 = f10_nm(((int64_t)(((*({ hrv *_t2671 = &(g888); int64_t _i2671 = (x_1679).f_; (S2*)_t2671->b + hr_ix(_i2671, _t2671->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:100"); }))).name_))); for (int64_t _k2670 = 0; _k2670 < _v2670.n; _k2670++) { uint8_t c_1680 = ((uint8_t*)_v2670.p)[_k2670]; if ((((c_1680) == (((uint8_t)34LL))) || ((c_1680) == (((uint8_t)92LL))))) { (void)(({ hrv *_v2672 = &(g163); uint8_t _x2672 = ((uint8_t)92LL); uint8_t *_p2672 = (uint8_t*)hr_grow(_v2672, 1, sizeof _x2672); *_p2672 = _x2672; _p2672; }));
 }
(void)(({ hrv *_v2673 = &(g163); uint8_t _x2673 = c_1680; uint8_t *_p2673 = (uint8_t*)hr_grow(_v2673, 1, sizeof _x2673); *_p2673 = _x2673; _p2673; }));
 } } _bk2669:; 
(void)(({ hrv *_o2674 = &(g163); hr_fs(_o2674, hr_str(":", 1)); hr_fi(_o2674, (x_1679).line_); hr_fs(_o2674, hr_str("\"", 1)); }));
}
static void f299_gun(int64_t n_1681) {
S4 x_1682 = (*({ hrv *_t2675 = &(g679); int64_t _i2675 = n_1681; (S4*)_t2675->b + hr_ix(_i2675, _t2675->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:271"); })); 
int64_t o_1683 = ((int64_t)((x_1682).op_)); 
int64_t a_1684 = ((int64_t)((x_1682).a_)); 
if (((o_1683) == (((int64_t)47LL)))) { (void)(f247_ow(hr_str("(!(", 3)));
(void)(f276_gx(a_1684));
(void)(f247_ow(hr_str("))", 2)));
return;
 }
if (((o_1683) == (((int64_t)49LL)))) { (void)(f276_gx(a_1684));
return;
 }
int64_t t_1685 = f266_fin(n_1681); 
if (((o_1683) == (((int64_t)22LL)))) { if (((((*({ hrv *_t2676 = &(g528); int64_t _i2676 = t_1685; (S1*)_t2676->b + hr_ix(_i2676, _t2676->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:275"); }))).k_) == (((uint8_t)4LL)))) { (void)(f247_ow(hr_str("(-(", 3)));
(void)(f276_gx(a_1684));
(void)(f247_ow(hr_str("))", 2)));
return;
 }
if (((f177_leaf_kind(t_1685)) >= (((int64_t)4LL)))) { (void)(f247_ow(hr_str("hneg", 4)));
(void)(f281_oi(t_1685));
(void)(f247_ow(hr_str("(", 1)));
(void)(f276_gx(a_1684));
(void)(f247_ow(hr_str(")", 1)));
(void)(f300_gen_hneg(t_1685));
return;
 }
(void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(t_1685));
(void)(f247_ow(hr_str(")(0 - (uint64_t)(", 17)));
(void)(f276_gx(a_1684));
(void)(f247_ow(hr_str(")))", 3)));
return;
 }
if (((o_1683) == (((int64_t)48LL)))) { (void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(t_1685));
(void)(f247_ow(hr_str(")~(", 3)));
(void)(f276_gx(a_1684));
(void)(f247_ow(hr_str("))", 2)));
return;
 }
if (((o_1683) == (((int64_t)23LL)))) { (void)(f247_ow(hr_str("(*", 2)));
(void)(f276_gx(a_1684));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if (((o_1683) == (((int64_t)21LL)))) { (void)(f276_gx(a_1684));
return;
 }
(void)(f274_gerr(n_1681, hr_str("unsupported unary operator", 26)));
}
static void f300_gen_hneg(int64_t t_1686) {
{ hrv *_v2678 = &(g243); for (int64_t _k2678 = 0; _k2678 < _v2678->n; _k2678++) { int32_t h_1687 = ((int32_t*)_v2678->b)[_k2678]; if (((((int64_t)(h_1687))) == (t_1686))) { return;
 }
 } } _bk2677:; 
(void)(({ hrv *_v2679 = &(g243); int32_t _x2679 = ((int32_t)(t_1686)); int32_t *_p2679 = (int32_t*)hr_grow(_v2679, 1, sizeof _x2679); *_p2679 = _x2679; _p2679; }));
(void)(f249_cbody(t_1686));
L94 sig_1688 = ({ L94 _t2680; memset(&_t2680, 0, sizeof _t2680); _t2680.n = 0; _t2680; }); 
(void)(({ L94 *_l2681 = &(sig_1688); hrv _o2681 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2681, hr_str("static ", 7)); if (_l2681->n + _o2681.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:542"); memcpy(_l2681->e + _l2681->n, _o2681.b, (size_t)_o2681.n); _l2681->n += _o2681.n; }));
(void)(({ L94 *_v2682 = &(sig_1688); hsl _s2682 = f251_cn(t_1686); if (_v2682->n + _s2682.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:542"); memmove(_v2682->e + _v2682->n, _s2682.p, (size_t)_s2682.n * sizeof _v2682->e[0]); _v2682->n += _s2682.n; }));
(void)(({ L94 *_l2683 = &(sig_1688); hrv _o2683 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2683, hr_str(" hneg", 5)); hr_fi(&_o2683, t_1686); hr_fs(&_o2683, hr_str("(", 1)); if (_l2683->n + _o2683.n > 256) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:542"); memcpy(_l2683->e + _l2683->n, _o2683.b, (size_t)_o2683.n); _l2683->n += _o2683.n; }));
(void)(({ L94 *_v2684 = &(sig_1688); hsl _s2684 = f251_cn(t_1686); if (_v2684->n + _s2684.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:542"); memmove(_v2684->e + _v2684->n, _s2684.p, (size_t)_s2684.n * sizeof _v2684->e[0]); _v2684->n += _s2684.n; }));
(void)(({ L94 *_v2685 = &(sig_1688); hsl _s2685 = hr_str(" a)", 3); if (_v2685->n + _s2685.n > 256) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:542"); memmove(_v2685->e + _v2685->n, _s2685.p, (size_t)_s2685.n * sizeof _v2685->e[0]); _v2685->n += _s2685.n; }));
(void)(({ hrv *_v2686 = &(g166); hsl _s2686 = ({ hsl _t2687 = ({ L94 *_t2688 = &(sig_1688); (hsl){ (uint8_t*)_t2688->e, _t2688->n }; }); int64_t _l2687 = 0, _h2687 = _t2687.n; if (_l2687 < 0 || _h2687 < _l2687 || _h2687 > _t2687.n) hr_slerr(_l2687, _h2687, _t2687.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:543"); (hsl){ _t2687.p + _l2687 * (int64_t)sizeof(uint8_t), _h2687 - _l2687 }; }); hr_append(_v2686, _s2686.p, _s2686.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2689 = &(g166); hsl _s2689 = hr_str(";\012", 2); hr_append(_v2689, _s2689.p, _s2689.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2690 = &(g169); hsl _s2690 = ({ hsl _t2691 = ({ L94 *_t2692 = &(sig_1688); (hsl){ (uint8_t*)_t2692->e, _t2692->n }; }); int64_t _l2691 = 0, _h2691 = _t2691.n; if (_l2691 < 0 || _h2691 < _l2691 || _h2691 > _t2691.n) hr_slerr(_l2691, _h2691, _t2691.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:544"); (hsl){ _t2691.p + _l2691 * (int64_t)sizeof(uint8_t), _h2691 - _l2691 }; }); hr_append(_v2690, _s2690.p, _s2690.n, sizeof(uint8_t)); }));
(void)(f288_hh(hr_str(" { ", 3)));
(void)(({ hrv *_v2693 = &(g169); hsl _s2693 = f251_cn(t_1686); hr_append(_v2693, _s2693.p, _s2693.n, sizeof(uint8_t)); }));
(void)(f288_hh(hr_str(" z; memset(&z, 0, sizeof z); ", 29)));
(void)(({ hrv *_v2694 = &(g169); hsl _s2694 = f251_cn(t_1686); hr_append(_v2694, _s2694.p, _s2694.n, sizeof(uint8_t)); }));
(void)(f288_hh(hr_str(" r; ", 4)));
(void)(f296_hop_body(t_1686, ((int64_t)22LL), hr_str("r", 1), hr_str("z", 1), hr_str("a", 1), false));
(void)(f288_hh(hr_str("return r; }\012", 12)));
}
static void f301_gidx(int64_t n_1698) {
S4 x_1699 = (*({ hrv *_t2695 = &(g679); int64_t _i2695 = n_1698; (S4*)_t2695->b + hr_ix(_i2695, _t2695->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:282"); })); 
int64_t a_1700 = ((int64_t)((x_1699).a_)); 
int64_t bt_1701 = f142_at(a_1700); 
int64_t d_1702 = f176_deref(bt_1701); 
int64_t e_1703 = ((int64_t)(((*({ hrv *_t2696 = &(g528); int64_t _i2696 = d_1702; (S1*)_t2696->b + hr_ix(_i2696, _t2696->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:286"); }))).a_)); 
int64_t p_1704 = f280_nt(); 
if ((f269_is_fix(d_1702) && ((((*({ hrv *_t2697 = &(g528); int64_t _i2697 = bt_1701; (S1*)_t2697->b + hr_ix(_i2697, _t2697->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:288"); }))).k_) != (((uint8_t)10LL))))) { (void)(f247_ow(hr_str("(", 1)));
(void)(f276_gx(a_1700));
(void)(f247_ow(hr_str(").e[hr_ix(", 10)));
(void)(f276_gx(((int64_t)((x_1699).b_))));
(void)(({ hrv *_o2698 = &(g163); hr_fs(_o2698, hr_str(", ", 2)); hr_fi(_o2698, ((*({ hrv *_t2699 = &(g528); int64_t _i2699 = d_1702; (S1*)_t2699->b + hr_ix(_i2699, _t2699->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:289"); }))).b_); hr_fs(_o2698, hr_str(", ", 2)); }));
(void)(f298_wloc(n_1698));
(void)(f247_ow(hr_str(")]", 2)));
return;
 }
(void)(f247_ow(hr_str("(*({ ", 5)));
if (((((*({ hrv *_t2700 = &(g528); int64_t _i2700 = d_1702; (S1*)_t2700->b + hr_ix(_i2700, _t2700->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:292"); }))).k_) == (((uint8_t)9LL)))) { (void)(f247_ow(hr_str("hsl _t", 6)));
(void)(f281_oi(p_1704));
(void)(f247_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t2701 = &(g528); int64_t _i2701 = bt_1701; (S1*)_t2701->b + hr_ix(_i2701, _t2701->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:292"); }))).k_) == (((uint8_t)10LL)))) { (void)(f247_ow(hr_str("*", 1)));
(void)(f262_gx0(a_1700));
 } else { (void)(f276_gx(a_1700));
 }
(void)(f247_ow(hr_str("; int64_t _i", 12)));
(void)(f281_oi(p_1704));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(((int64_t)((x_1699).b_))));
(void)(f247_ow(hr_str("; (", 3)));
(void)(f248_ct(e_1703));
(void)(f247_ow(hr_str("*)_t", 4)));
(void)(f281_oi(p_1704));
(void)(({ hrv *_o2702 = &(g163); hr_fs(_o2702, hr_str(".p + hr_ix(_i", 13)); hr_fi(_o2702, p_1704); hr_fs(_o2702, hr_str(", _t", 4)); hr_fi(_o2702, p_1704); hr_fs(_o2702, hr_str(".n, ", 4)); }));
(void)(f298_wloc(n_1698));
(void)(f247_ow(hr_str("); }))", 6)));
return;
 }
(void)(f248_ct(d_1702));
(void)(f247_ow(hr_str(" *_t", 4)));
(void)(f281_oi(p_1704));
(void)(f247_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t2703 = &(g528); int64_t _i2703 = bt_1701; (S1*)_t2703->b + hr_ix(_i2703, _t2703->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:294"); }))).k_) == (((uint8_t)10LL)))) { (void)(f262_gx0(a_1700));
 } else { if (f259_is_place(a_1700)) { (void)(f247_ow(hr_str("&(", 2)));
(void)(f276_gx(a_1700));
(void)(f247_ow(hr_str(")", 1)));
 } else { int64_t k_1705 = f260_tmp(d_1702, f255_is_res(d_1702)); 
(void)(f247_ow(hr_str("&(", 2)));
(void)(f261_ot(k_1705));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f256_gxo(a_1700));
(void)(f247_ow(hr_str(")", 1)));
 }
 }
(void)(f247_ow(hr_str("; int64_t _i", 12)));
(void)(f281_oi(p_1704));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(((int64_t)((x_1699).b_))));
(void)(f247_ow(hr_str("; ", 2)));
if (f255_is_res(d_1702)) { (void)(f247_ow(hr_str("(", 1)));
(void)(f248_ct(e_1703));
(void)(f247_ow(hr_str("*)_t", 4)));
(void)(f281_oi(p_1704));
(void)(({ hrv *_o2704 = &(g163); hr_fs(_o2704, hr_str("->b + hr_ix(_i", 14)); hr_fi(_o2704, p_1704); hr_fs(_o2704, hr_str(", _t", 4)); hr_fi(_o2704, p_1704); hr_fs(_o2704, hr_str("->n, ", 5)); }));
(void)(f298_wloc(n_1698));
(void)(f247_ow(hr_str("); }))", 6)));
return;
 }
if (f269_is_fix(d_1702)) { (void)(({ hrv *_o2705 = &(g163); hr_fs(_o2705, hr_str("_t", 2)); hr_fi(_o2705, p_1704); hr_fs(_o2705, hr_str("->e + hr_ix(_i", 14)); hr_fi(_o2705, p_1704); hr_fs(_o2705, hr_str(", ", 2)); hr_fi(_o2705, ((*({ hrv *_t2706 = &(g528); int64_t _i2706 = d_1702; (S1*)_t2706->b + hr_ix(_i2706, _t2706->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:297"); }))).b_); hr_fs(_o2705, hr_str(", ", 2)); }));
(void)(f298_wloc(n_1698));
(void)(f247_ow(hr_str("); }))", 6)));
return;
 }
(void)(({ hrv *_o2707 = &(g163); hr_fs(_o2707, hr_str("_t", 2)); hr_fi(_o2707, p_1704); hr_fs(_o2707, hr_str("->e + hr_ix(_i", 14)); hr_fi(_o2707, p_1704); hr_fs(_o2707, hr_str(", _t", 4)); hr_fi(_o2707, p_1704); hr_fs(_o2707, hr_str("->n, ", 5)); }));
(void)(f298_wloc(n_1698));
(void)(f247_ow(hr_str("); }))", 6)));
}
static void f302_gslice(int64_t n_1706) {
S4 x_1707 = (*({ hrv *_t2708 = &(g679); int64_t _i2708 = n_1706; (S4*)_t2708->b + hr_ix(_i2708, _t2708->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:301"); })); 
int64_t a_1708 = ((int64_t)((x_1707).a_)); 
int64_t d_1709 = f176_deref(f142_at(a_1708)); 
int64_t e_1710 = ((int64_t)(((*({ hrv *_t2709 = &(g528); int64_t _i2709 = d_1709; (S1*)_t2709->b + hr_ix(_i2709, _t2709->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:304"); }))).a_)); 
int64_t p_1711 = f280_nt(); 
(void)(f247_ow(hr_str("({ hsl _t", 9)));
(void)(f281_oi(p_1711));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f279_gsl(a_1708, f142_at(a_1708)));
(void)(f247_ow(hr_str("; int64_t _l", 12)));
(void)(f281_oi(p_1711));
(void)(f247_ow(hr_str(" = ", 3)));
if ((((x_1707).b_) >= (((int32_t)0LL)))) { if (((((uint16_t)((uint64_t)(x_1707).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_o2710 = &(g163); hr_fs(_o2710, hr_str("_t", 2)); hr_fi(_o2710, p_1711); hr_fs(_o2710, hr_str(".n - ", 5)); }));
 }
(void)(f276_gx(((int64_t)((x_1707).b_))));
 } else { (void)(f247_ow(hr_str("0", 1)));
 }
(void)(f247_ow(hr_str(", _h", 4)));
(void)(f281_oi(p_1711));
(void)(f247_ow(hr_str(" = ", 3)));
if ((((x_1707).c_) >= (((int32_t)0LL)))) { if (((((uint16_t)((uint64_t)(x_1707).fl_ & (uint64_t)((uint16_t)2LL)))) != (((uint16_t)0LL)))) { (void)(({ hrv *_o2711 = &(g163); hr_fs(_o2711, hr_str("_t", 2)); hr_fi(_o2711, p_1711); hr_fs(_o2711, hr_str(".n - ", 5)); }));
 }
(void)(f276_gx(((int64_t)((x_1707).c_))));
 } else { (void)(({ hrv *_o2712 = &(g163); hr_fs(_o2712, hr_str("_t", 2)); hr_fi(_o2712, p_1711); hr_fs(_o2712, hr_str(".n", 2)); }));
 }
(void)(({ hrv *_o2713 = &(g163); hr_fs(_o2713, hr_str("; if (_l", 8)); hr_fi(_o2713, p_1711); hr_fs(_o2713, hr_str(" < 0 || _h", 10)); hr_fi(_o2713, p_1711); hr_fs(_o2713, hr_str(" < _l", 5)); hr_fi(_o2713, p_1711); hr_fs(_o2713, hr_str(" || _h", 6)); hr_fi(_o2713, p_1711); hr_fs(_o2713, hr_str(" > _t", 5)); hr_fi(_o2713, p_1711); hr_fs(_o2713, hr_str(".n) hr_slerr(_l", 15)); hr_fi(_o2713, p_1711); hr_fs(_o2713, hr_str(", _h", 4)); hr_fi(_o2713, p_1711); hr_fs(_o2713, hr_str(", _t", 4)); hr_fi(_o2713, p_1711); hr_fs(_o2713, hr_str(".n, ", 4)); }));
(void)(f298_wloc(n_1706));
(void)(({ hrv *_o2714 = &(g163); hr_fs(_o2714, hr_str("); (hsl){ _t", 12)); hr_fi(_o2714, p_1711); hr_fs(_o2714, hr_str(".p + _l", 7)); hr_fi(_o2714, p_1711); hr_fs(_o2714, hr_str(" * (int64_t)sizeof(", 19)); }));
(void)(f248_ct(e_1710));
(void)(({ hrv *_o2715 = &(g163); hr_fs(_o2715, hr_str("), _h", 5)); hr_fi(_o2715, p_1711); hr_fs(_o2715, hr_str(" - _l", 5)); hr_fi(_o2715, p_1711); hr_fs(_o2715, hr_str(" }; })", 6)); }));
}
static void f303_garr(int64_t n_1714) {
S4 x_1715 = (*({ hrv *_t2716 = &(g679); int64_t _i2716 = n_1714; (S4*)_t2716->b + hr_ix(_i2716, _t2716->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:314"); })); 
int64_t t_1716 = f142_at(n_1714); 
int64_t e_1717 = ((int64_t)(((*({ hrv *_t2717 = &(g528); int64_t _i2717 = t_1716; (S1*)_t2717->b + hr_ix(_i2717, _t2717->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:316"); }))).a_)); 
int64_t p_1718 = f280_nt(); 
if (f255_is_res(t_1716)) { if (((((x_1715).n_) == (((int32_t)0LL))) && (((x_1715).a_) < (((int32_t)0LL))))) { (void)(f247_ow(hr_str("((hrv){0})", 10)));
return;
 }
(void)(f247_ow(hr_str("({ hrv _t", 9)));
(void)(f281_oi(p_1718));
(void)(f247_ow(hr_str(" = {0}; ", 8)));
if ((((x_1715).a_) >= (((int32_t)0LL)))) { (void)(f247_ow(hr_str("int64_t _c", 10)));
(void)(f281_oi(p_1718));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(((int64_t)((x_1715).b_))));
(void)(f247_ow(hr_str("; ", 2)));
(void)(f248_ct(e_1717));
(void)(f247_ow(hr_str(" _v", 3)));
(void)(f281_oi(p_1718));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(((int64_t)((x_1715).a_))));
(void)(f247_ow(hr_str("; ", 2)));
(void)(f248_ct(e_1717));
(void)(f247_ow(hr_str(" *_p", 4)));
(void)(f281_oi(p_1718));
(void)(f247_ow(hr_str(" = (", 4)));
(void)(f248_ct(e_1717));
(void)(({ hrv *_o2718 = &(g163); hr_fs(_o2718, hr_str("*)hr_grow(&_t", 13)); hr_fi(_o2718, p_1718); hr_fs(_o2718, hr_str(", _c", 4)); hr_fi(_o2718, p_1718); hr_fs(_o2718, hr_str(", sizeof _v", 11)); hr_fi(_o2718, p_1718); hr_fs(_o2718, hr_str("); for (int64_t _k = 0; _k < _c", 31)); hr_fi(_o2718, p_1718); hr_fs(_o2718, hr_str("; _k++) _p", 10)); hr_fi(_o2718, p_1718); hr_fs(_o2718, hr_str("[_k] = _v", 9)); hr_fi(_o2718, p_1718); hr_fs(_o2718, hr_str("; ", 2)); }));
 } else { (void)(f248_ct(e_1717));
(void)(f247_ow(hr_str(" *_p", 4)));
(void)(f281_oi(p_1718));
(void)(f247_ow(hr_str(" = (", 4)));
(void)(f248_ct(e_1717));
(void)(({ hrv *_o2719 = &(g163); hr_fs(_o2719, hr_str("*)hr_grow(&_t", 13)); hr_fi(_o2719, p_1718); hr_fs(_o2719, hr_str(", ", 2)); hr_fi(_o2719, (x_1715).n_); hr_fs(_o2719, hr_str(", sizeof(", 9)); }));
(void)(f248_ct(e_1717));
(void)(f247_ow(hr_str(")); ", 4)));
{ int32_t _e2721 = (x_1715).n_; for (int32_t _k2721 = 0; _k2721 < _e2721; _k2721++) { int32_t i_1719 = (int32_t)_k2721; (void)(({ hrv *_o2722 = &(g163); hr_fs(_o2722, hr_str("_p", 2)); hr_fi(_o2722, p_1718); hr_fs(_o2722, hr_str("[", 1)); hr_fi(_o2722, i_1719); hr_fs(_o2722, hr_str("] = ", 4)); }));
(void)(f276_gx(f90_kid(n_1714, ((int64_t)(i_1719)))));
(void)(f247_ow(hr_str("; ", 2)));
 } } _bk2720:; 
 }
(void)(f247_ow(hr_str("_t", 2)));
(void)(f281_oi(p_1718));
(void)(f247_ow(hr_str("; })", 4)));
return;
 }
if ((f269_is_fix(t_1716) || f270_is_lim(t_1716))) { (void)(f247_ow(hr_str("({ ", 3)));
(void)(f248_ct(t_1716));
(void)(f247_ow(hr_str(" _t", 3)));
(void)(f281_oi(p_1718));
(void)(f247_ow(hr_str("; ", 2)));
if ((((x_1715).a_) >= (((int32_t)0LL)))) { (void)(f248_ct(e_1717));
(void)(f247_ow(hr_str(" _v", 3)));
(void)(f281_oi(p_1718));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(((int64_t)((x_1715).a_))));
(void)(({ hrv *_o2723 = &(g163); hr_fs(_o2723, hr_str("; for (int64_t _k = 0; _k < ", 28)); hr_fi(_o2723, ({ int64_t _r2724; if (f269_is_fix(t_1716)) { _r2724 = ((*({ hrv *_t2725 = &(g528); int64_t _i2725 = t_1716; (S1*)_t2725->b + hr_ix(_i2725, _t2725->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:328"); }))).b_;  } else { _r2724 = ((int64_t)0LL);  } _r2724; })); hr_fs(_o2723, hr_str("; _k++) _t", 10)); hr_fi(_o2723, p_1718); hr_fs(_o2723, hr_str(".e[_k] = _v", 11)); hr_fi(_o2723, p_1718); hr_fs(_o2723, hr_str("; ", 2)); }));
if (f270_is_lim(t_1716)) { (void)(f247_ow(hr_str("int64_t _c", 10)));
(void)(f281_oi(p_1718));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(((int64_t)((x_1715).b_))));
(void)(({ hrv *_o2726 = &(g163); hr_fs(_o2726, hr_str("; for (int64_t _k = 0; _k < _c", 30)); hr_fi(_o2726, p_1718); hr_fs(_o2726, hr_str("; _k++) _t", 10)); hr_fi(_o2726, p_1718); hr_fs(_o2726, hr_str(".e[_k] = _v", 11)); hr_fi(_o2726, p_1718); hr_fs(_o2726, hr_str("; _t", 4)); hr_fi(_o2726, p_1718); hr_fs(_o2726, hr_str(".n = _c", 7)); hr_fi(_o2726, p_1718); hr_fs(_o2726, hr_str("; ", 2)); }));
 }
 } else { if (f270_is_lim(t_1716)) { (void)(({ hrv *_o2727 = &(g163); hr_fs(_o2727, hr_str("memset(&_t", 10)); hr_fi(_o2727, p_1718); hr_fs(_o2727, hr_str(", 0, sizeof _t", 14)); hr_fi(_o2727, p_1718); hr_fs(_o2727, hr_str("); _t", 5)); hr_fi(_o2727, p_1718); hr_fs(_o2727, hr_str(".n = ", 5)); hr_fi(_o2727, (x_1715).n_); hr_fs(_o2727, hr_str("; ", 2)); }));
 }
{ int32_t _e2729 = (x_1715).n_; for (int32_t _k2729 = 0; _k2729 < _e2729; _k2729++) { int32_t i_1720 = (int32_t)_k2729; (void)(({ hrv *_o2730 = &(g163); hr_fs(_o2730, hr_str("_t", 2)); hr_fi(_o2730, p_1718); hr_fs(_o2730, hr_str(".e[", 3)); hr_fi(_o2730, i_1720); hr_fs(_o2730, hr_str("] = ", 4)); }));
(void)(f276_gx(f90_kid(n_1714, ((int64_t)(i_1720)))));
(void)(f247_ow(hr_str("; ", 2)));
 } } _bk2728:; 
 }
(void)(f247_ow(hr_str("_t", 2)));
(void)(f281_oi(p_1718));
(void)(f247_ow(hr_str("; })", 4)));
return;
 }
(void)(f274_gerr(n_1714, hr_str("unsupported array literal type", 30)));
}
static void f304_gslit(int64_t n_1721) {
S4 x_1722 = (*({ hrv *_t2731 = &(g679); int64_t _i2731 = n_1721; (S4*)_t2731->b + hr_ix(_i2731, _t2731->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:345"); })); 
int64_t t_1723 = f142_at(n_1721); 
int64_t si_1724 = f158_rv(n_1721); 
int64_t f0_1725 = ((int64_t)(((*({ hrv *_t2732 = &(g531); int64_t _i2732 = si_1724; (S10*)_t2732->b + hr_ix(_i2732, _t2732->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:348"); }))).f0_)); 
(void)(f247_ow(hr_str("((", 2)));
(void)(f248_ct(t_1723));
(void)(f247_ow(hr_str("){ ", 3)));
bool any_1726 = false; 
{ int32_t _e2734 = ((*({ hrv *_t2735 = &(g531); int64_t _i2735 = si_1724; (S10*)_t2735->b + hr_ix(_i2735, _t2735->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:351"); }))).fnum_; for (int32_t _k2734 = 0; _k2734 < _e2734; _k2734++) { int32_t j_1727 = (int32_t)_k2734; S11 f_1728 = (*({ hrv *_t2736 = &(g532); int64_t _i2736 = ((int64_t)((int64_t)f0_1725 + (int64_t)((int64_t)(j_1727)))); (S11*)_t2736->b + hr_ix(_i2736, _t2736->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:352"); })); 
if ((((f_1728).ty_) < (((int32_t)0LL)))) { continue;
 }
int64_t given_1729 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))); 
{ int32_t _e2738 = (x_1722).n_; for (int32_t _k2738 = 0; _k2738 < _e2738; _k2738++) { int32_t i_1730 = (int32_t)_k2738; if (((f158_rv(f90_kid(n_1721, ((int64_t)(i_1730))))) == (((int64_t)(j_1727))))) { given_1729 = f90_kid(n_1721, ((int64_t)(i_1730)));
 }
 } } _bk2737:; 
if ((((given_1729) < (((int64_t)0LL))) && (((f_1728).def_) < (((int32_t)0LL))))) { continue;
 }
(void)(f247_ow(hr_str(".", 1)));
(void)(f254_fname_into((&(g163)), ((int64_t)((f_1728).name_))));
(void)(f247_ow(hr_str(" = ", 3)));
if (((given_1729) >= (((int64_t)0LL)))) { int64_t v_1731 = ((int64_t)(((*({ hrv *_t2739 = &(g679); int64_t _i2739 = given_1729; (S4*)_t2739->b + hr_ix(_i2739, _t2739->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:358"); }))).a_)); 
if (f255_is_res(((int64_t)((f_1728).ty_)))) { (void)(f256_gxo(v_1731));
 } else { (void)(f276_gx(v_1731));
 }
 } else { int64_t sa_1732 = g384; 
g384 = g386;
(void)(f276_gx(((int64_t)((f_1728).def_))));
g384 = sa_1732;
 }
(void)(f247_ow(hr_str(", ", 2)));
any_1726 = true;
 } } _bk2733:; 
if ((!(any_1726))) { (void)(f247_ow(hr_str("0", 1)));
 }
(void)(f247_ow(hr_str("})", 2)));
}
static void f305_gcall(int64_t n_1733) {
int64_t r_1734 = f157_rk(n_1733); 
if (((r_1734) == (((int64_t)4LL)))) { (void)(f306_gbuiltin(n_1733));
return;
 }
if (((r_1734) == (((int64_t)10LL)))) { (void)(f318_gblkcall(n_1733));
return;
 }
if (((r_1734) != (((int64_t)3LL)))) { (void)(f274_gerr(n_1733, hr_str("unsupported call", 16)));
return;
 }
int64_t inst_1938 = f158_rv(n_1733); 
int64_t recv_1939 = ({ int64_t _r2740; if ((((f211_ax(n_1733)) == (((int64_t)1LL))) && ((((*({ hrv *_t2741 = &(g679); int64_t _i2741 = ((*({ hrv *_t2742 = &(g679); int64_t _i2742 = n_1733; (S4*)_t2742->b + hr_ix(_i2742, _t2742->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:588"); }))).a_; (S4*)_t2741->b + hr_ix(_i2741, _t2741->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:588"); }))).k_) == (((uint8_t)14LL))))) { _r2740 = ((int64_t)(((*({ hrv *_t2743 = &(g679); int64_t _i2743 = ((*({ hrv *_t2744 = &(g679); int64_t _i2744 = n_1733; (S4*)_t2744->b + hr_ix(_i2744, _t2744->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:588"); }))).a_; (S4*)_t2743->b + hr_ix(_i2743, _t2743->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:588"); }))).a_));  } else { _r2740 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2740; }); 
if (f340_is_ext(inst_1938)) { (void)(f341_ext_name(inst_1938));
 } else { (void)(f342_fn_cname(inst_1938));
 }
(void)(f247_ow(hr_str("(", 1)));
(void)(f343_gcall_args(n_1733, inst_1938, recv_1939));
(void)(f247_ow(hr_str(")", 1)));
}
static void f306_gbuiltin(int64_t n_1735) {
S4 x_1736 = (*({ hrv *_t2745 = &(g679); int64_t _i2745 = n_1735; (S4*)_t2745->b + hr_ix(_i2745, _t2745->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:621"); })); 
int64_t b_1737 = f158_rv(n_1735); 
bool hasr_1738 = ((f211_ax(n_1735)) == (((int64_t)1LL))); 
int64_t recv_1739 = ({ int64_t _r2746; if (hasr_1738) { _r2746 = ((int64_t)(((*({ hrv *_t2747 = &(g679); int64_t _i2747 = (x_1736).a_; (S4*)_t2747->b + hr_ix(_i2747, _t2747->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:624"); }))).a_));  } else { _r2746 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2746; }); 
int64_t total_1740 = ((int64_t)((int64_t)((int64_t)((x_1736).n_)) + (int64_t)({ int64_t _r2748; if (hasr_1738) { _r2748 = ((int64_t)1LL);  } else { _r2748 = ((int64_t)0LL);  } _r2748; }))); 

int64_t p_1742 = f280_nt(); 
if (((b_1737) == (((int64_t)1LL)))) { (void)(f247_ow(hr_str("({ ", 3)));
{ int32_t _e2750 = (x_1736).n_; for (int32_t _k2750 = 0; _k2750 < _e2750; _k2750++) { int32_t i_1743 = (int32_t)_k2750; int64_t c_1744 = f90_kid(n_1735, ((int64_t)(i_1743))); 
(void)(f308_gfmt(hr_str("&hr_ob", 6), c_1744, f266_fin(c_1744), true));
(void)(f247_ow(hr_str("; ", 2)));
 } } _bk2749:; 
(void)(f247_ow(hr_str("hr_println(); })", 16)));
return;
 }
if (((b_1737) == (((int64_t)2LL)))) { (void)(f247_ow(hr_str("({ hrv _o", 9)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" = {0}; ", 8)));
L96 nmo_1751 = ({ L96 _t2751; memset(&_t2751, 0, sizeof _t2751); _t2751.n = 0; _t2751; }); 
(void)(({ L96 *_l2752 = &(nmo_1751); hrv _o2752 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2752, hr_str("&_o", 3)); hr_fi(&_o2752, p_1742); if (_l2752->n + _o2752.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:629"); memcpy(_l2752->e + _l2752->n, _o2752.b, (size_t)_o2752.n); _l2752->n += _o2752.n; }));
{ int32_t _e2754 = (x_1736).n_; for (int32_t _k2754 = 0; _k2754 < _e2754; _k2754++) { int32_t i_1752 = (int32_t)_k2754; int64_t c_1753 = f90_kid(n_1735, ((int64_t)(i_1752))); 
(void)(f308_gfmt(({ hsl _t2755 = ({ L96 *_t2756 = &(nmo_1751); (hsl){ (uint8_t*)_t2756->e, _t2756->n }; }); int64_t _l2755 = 0, _h2755 = _t2755.n; if (_l2755 < 0 || _h2755 < _l2755 || _h2755 > _t2755.n) hr_slerr(_l2755, _h2755, _t2755.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:629"); (hsl){ _t2755.p + _l2755 * (int64_t)sizeof(uint8_t), _h2755 - _l2755 }; }), c_1753, f266_fin(c_1753), true));
(void)(f247_ow(hr_str("; ", 2)));
 } } _bk2753:; 
(void)(f247_ow(hr_str("_o", 2)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str("; })", 4)));
return;
 }
if ((((b_1737) == (((int64_t)3LL))) && f270_is_lim(f176_deref(f142_at(f307_arg(((int64_t)0LL), &recv_1739, &n_1735)))))) { int64_t lt_1754 = f176_deref(f142_at(f307_arg(((int64_t)0LL), &recv_1739, &n_1735))); 
(void)(f247_ow(hr_str("({ ", 3)));
(void)(f248_ct(lt_1754));
(void)(f247_ow(hr_str(" *_l", 4)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f309_grecv_ptr(f307_arg(((int64_t)0LL), &recv_1739, &n_1735)));
(void)(f247_ow(hr_str("; hrv _o", 8)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" __attribute__((cleanup(hr_rdrop))) = {0}; ", 43)));
L96 nmo_1758 = ({ L96 _t2757; memset(&_t2757, 0, sizeof _t2757); _t2757.n = 0; _t2757; }); 
(void)(({ L96 *_l2758 = &(nmo_1758); hrv _o2758 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2758, hr_str("&_o", 3)); hr_fi(&_o2758, p_1742); if (_l2758->n + _o2758.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:633"); memcpy(_l2758->e + _l2758->n, _o2758.b, (size_t)_o2758.n); _l2758->n += _o2758.n; }));
{ int64_t _e2760 = total_1740; for (int64_t _k2760 = ((int64_t)1LL); _k2760 < _e2760; _k2760++) { int64_t i_1759 = (int64_t)_k2760; int64_t c_1760 = f307_arg(i_1759, &recv_1739, &n_1735); 
(void)(f308_gfmt(({ hsl _t2761 = ({ L96 *_t2762 = &(nmo_1758); (hsl){ (uint8_t*)_t2762->e, _t2762->n }; }); int64_t _l2761 = 0, _h2761 = _t2761.n; if (_l2761 < 0 || _h2761 < _l2761 || _h2761 > _t2761.n) hr_slerr(_l2761, _h2761, _t2761.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:634"); (hsl){ _t2761.p + _l2761 * (int64_t)sizeof(uint8_t), _h2761 - _l2761 }; }), c_1760, f266_fin(c_1760), true));
(void)(f247_ow(hr_str("; ", 2)));
 } } _bk2759:; 
(void)(({ hrv *_o2763 = &(g163); hr_fs(_o2763, hr_str("if (_l", 6)); hr_fi(_o2763, p_1742); hr_fs(_o2763, hr_str("->n + _o", 8)); hr_fi(_o2763, p_1742); hr_fs(_o2763, hr_str(".n > ", 5)); hr_fi(_o2763, ((*({ hrv *_t2764 = &(g528); int64_t _i2764 = lt_1754; (S1*)_t2764->b + hr_ix(_i2764, _t2764->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:635"); }))).b_); hr_fs(_o2763, hr_str(") hr_die(\"format past a limited array's capacity\", ", 51)); }));
(void)(f298_wloc(n_1735));
(void)(({ hrv *_o2765 = &(g163); hr_fs(_o2765, hr_str("); memcpy(_l", 12)); hr_fi(_o2765, p_1742); hr_fs(_o2765, hr_str("->e + _l", 8)); hr_fi(_o2765, p_1742); hr_fs(_o2765, hr_str("->n, _o", 7)); hr_fi(_o2765, p_1742); hr_fs(_o2765, hr_str(".b, (size_t)_o", 14)); hr_fi(_o2765, p_1742); hr_fs(_o2765, hr_str(".n); _l", 7)); hr_fi(_o2765, p_1742); hr_fs(_o2765, hr_str("->n += _o", 9)); hr_fi(_o2765, p_1742); hr_fs(_o2765, hr_str(".n; })", 6)); }));
return;
 }
if (((b_1737) == (((int64_t)3LL)))) { (void)(f247_ow(hr_str("({ hrv *_o", 10)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f309_grecv_ptr(f307_arg(((int64_t)0LL), &recv_1739, &n_1735)));
(void)(f247_ow(hr_str("; ", 2)));
L96 nmo_1761 = ({ L96 _t2766; memset(&_t2766, 0, sizeof _t2766); _t2766.n = 0; _t2766; }); 
(void)(({ L96 *_l2767 = &(nmo_1761); hrv _o2767 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2767, hr_str("_o", 2)); hr_fi(&_o2767, p_1742); if (_l2767->n + _o2767.n > 32) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:638"); memcpy(_l2767->e + _l2767->n, _o2767.b, (size_t)_o2767.n); _l2767->n += _o2767.n; }));
{ int64_t _e2769 = total_1740; for (int64_t _k2769 = ((int64_t)1LL); _k2769 < _e2769; _k2769++) { int64_t i_1762 = (int64_t)_k2769; int64_t c_1763 = f307_arg(i_1762, &recv_1739, &n_1735); 
(void)(f308_gfmt(({ hsl _t2770 = ({ L96 *_t2771 = &(nmo_1761); (hsl){ (uint8_t*)_t2771->e, _t2771->n }; }); int64_t _l2770 = 0, _h2770 = _t2770.n; if (_l2770 < 0 || _h2770 < _l2770 || _h2770 > _t2770.n) hr_slerr(_l2770, _h2770, _t2770.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:638"); (hsl){ _t2770.p + _l2770 * (int64_t)sizeof(uint8_t), _h2770 - _l2770 }; }), c_1763, f266_fin(c_1763), true));
(void)(f247_ow(hr_str("; ", 2)));
 } } _bk2768:; 
(void)(f247_ow(hr_str("})", 2)));
return;
 }
if (((b_1737) == (((int64_t)4LL)))) { (void)(f247_ow(hr_str("({ if (!(", 9)));
(void)(f276_gx(f307_arg(((int64_t)0LL), &recv_1739, &n_1735)));
(void)(f247_ow(hr_str(")) hr_assert_fail(", 18)));
(void)(f298_wloc(n_1735));
(void)(f247_ow(hr_str("); })", 5)));
return;
 }
if (((b_1737) == (((int64_t)5LL)))) { (void)(f247_ow(hr_str("hr_abort(", 9)));
(void)(f278_gas(f307_arg(((int64_t)0LL), &recv_1739, &n_1735)));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if (((b_1737) == (((int64_t)6LL)))) { (void)(f247_ow(hr_str("hr_exit(", 8)));
(void)(f276_gx(f307_arg(((int64_t)0LL), &recv_1739, &n_1735)));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if (((b_1737) == (((int64_t)8LL)))) { int64_t t_1764 = f142_at(n_1735); 
(void)(f247_ow(hr_str("({ ", 3)));
(void)(f248_ct(t_1764));
(void)(f247_ow(hr_str(" _d", 3)));
(void)(f281_oi(p_1742));
(void)(({ hrv *_o2772 = &(g163); hr_fs(_o2772, hr_str("; memset(&_d", 12)); hr_fi(_o2772, p_1742); hr_fs(_o2772, hr_str(", 0, sizeof _d", 14)); hr_fi(_o2772, p_1742); hr_fs(_o2772, hr_str("); _d", 5)); hr_fi(_o2772, p_1742); hr_fs(_o2772, hr_str("; })", 4)); }));
return;
 }
if (((b_1737) == (((int64_t)9LL)))) { int64_t c_1765 = f307_arg(((int64_t)0LL), &recv_1739, &n_1735); 
int64_t t_1766 = f176_deref(f266_fin(c_1765)); 
if (f269_is_fix(t_1766)) { (void)(({ hrv *_o2773 = &(g163); hr_fs(_o2773, hr_str("((int64_t)", 10)); hr_fi(_o2773, ((*({ hrv *_t2774 = &(g528); int64_t _i2774 = t_1766; (S1*)_t2774->b + hr_ix(_i2774, _t2774->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:643"); }))).b_); hr_fs(_o2773, hr_str(")", 1)); }));
return;
 }
(void)(f247_ow(hr_str("(", 1)));
(void)(f278_gas(c_1765));
(void)(f247_ow(hr_str(").n", 3)));
return;
 }
if (((b_1737) == (((int64_t)7LL)))) { int64_t c_1767 = f307_arg(((int64_t)0LL), &recv_1739, &n_1735); 
int64_t t_1768 = f176_deref(f266_fin(c_1767)); 
if ((((((*({ hrv *_t2775 = &(g528); int64_t _i2775 = t_1768; (S1*)_t2775->b + hr_ix(_i2775, _t2775->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:644"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2776 = &(g528); int64_t _i2776 = t_1768; (S1*)_t2776->b + hr_ix(_i2776, _t2776->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:644"); }))).k_) == (((uint8_t)9LL))))) { (void)(f247_ow(hr_str("hr_rfrom(", 9)));
(void)(f278_gas(c_1767));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f310_esz(((int64_t)(((*({ hrv *_t2777 = &(g528); int64_t _i2777 = t_1768; (S1*)_t2777->b + hr_ix(_i2777, _t2777->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:644"); }))).a_))));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if (((f266_fin(c_1767)) != (t_1768))) { (void)(f247_ow(hr_str("(*", 2)));
(void)(f276_gx(c_1767));
(void)(f247_ow(hr_str(")", 1)));
 } else { (void)(f276_gx(c_1767));
 }
return;
 }
if (((b_1737) == (((int64_t)31LL)))) { int64_t c_1770 = f307_arg(((int64_t)0LL), &recv_1739, &n_1735); 
int64_t t_1771 = f176_deref(f266_fin(c_1770)); 
if ((((((*({ hrv *_t2778 = &(g528); int64_t _i2778 = t_1771; (S1*)_t2778->b + hr_ix(_i2778, _t2778->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:645"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2779 = &(g528); int64_t _i2779 = t_1771; (S1*)_t2779->b + hr_ix(_i2779, _t2779->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:645"); }))).k_) == (((uint8_t)9LL))))) { int64_t q_1772 = f280_nt(); 
(void)(f247_ow(hr_str("({ hsl _s", 9)));
(void)(f281_oi(q_1772));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f278_gas(c_1770));
(void)(({ hrv *_o2780 = &(g163); hr_fs(_o2780, hr_str("; (hsl){ _s", 11)); hr_fi(_o2780, q_1772); hr_fs(_o2780, hr_str(".p, _s", 6)); hr_fi(_o2780, q_1772); hr_fs(_o2780, hr_str(".n * (int64_t)sizeof(", 21)); }));
(void)(f248_ct(((int64_t)(((*({ hrv *_t2781 = &(g528); int64_t _i2781 = t_1771; (S1*)_t2781->b + hr_ix(_i2781, _t2781->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:645"); }))).a_))));
(void)(f247_ow(hr_str(") }; })", 7)));
return;
 }
(void)(f247_ow(hr_str("((hsl){ (uint8_t*)", 18)));
(void)(f311_gaddr(c_1770));
(void)(f247_ow(hr_str(", sizeof(", 9)));
(void)(f248_ct(t_1771));
(void)(f247_ow(hr_str(") })", 4)));
return;
 }
if (((b_1737) == (((int64_t)30LL)))) { int64_t c_1776 = f307_arg(((int64_t)0LL), &recv_1739, &n_1735); 
int64_t t_1777 = f176_deref(f266_fin(c_1776)); 
(void)(f247_ow(hr_str("hr_rfrom(", 9)));
if ((((((*({ hrv *_t2782 = &(g528); int64_t _i2782 = t_1777; (S1*)_t2782->b + hr_ix(_i2782, _t2782->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:646"); }))).k_) == (((uint8_t)8LL))) || ((((*({ hrv *_t2783 = &(g528); int64_t _i2783 = t_1777; (S1*)_t2783->b + hr_ix(_i2783, _t2783->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:646"); }))).k_) == (((uint8_t)9LL))))) { int64_t q_1778 = f280_nt(); 
(void)(f247_ow(hr_str("({ hsl _s", 9)));
(void)(f281_oi(q_1778));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f278_gas(c_1776));
(void)(({ hrv *_o2784 = &(g163); hr_fs(_o2784, hr_str("; (hsl){ _s", 11)); hr_fi(_o2784, q_1778); hr_fs(_o2784, hr_str(".p, _s", 6)); hr_fi(_o2784, q_1778); hr_fs(_o2784, hr_str(".n * (int64_t)sizeof(", 21)); }));
(void)(f248_ct(((int64_t)(((*({ hrv *_t2785 = &(g528); int64_t _i2785 = t_1777; (S1*)_t2785->b + hr_ix(_i2785, _t2785->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:646"); }))).a_))));
(void)(f247_ow(hr_str(") }; })", 7)));
 } else { (void)(f247_ow(hr_str("((hsl){ (uint8_t*)", 18)));
(void)(f311_gaddr(c_1776));
(void)(f247_ow(hr_str(", sizeof(", 9)));
(void)(f248_ct(t_1777));
(void)(f247_ow(hr_str(") })", 4)));
 }
(void)(f247_ow(hr_str(", 1)", 4)));
return;
 }
if (((b_1737) == (((int64_t)32LL)))) { int64_t t_1779 = f142_at(n_1735); 
(void)(f247_ow(hr_str("({ hsl _s", 9)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f278_gas(f307_arg(((int64_t)0LL), &recv_1739, &n_1735)));
(void)(f247_ow(hr_str("; ", 2)));
(void)(f248_ct(t_1779));
(void)(({ hrv *_o2786 = &(g163); hr_fs(_o2786, hr_str(" _d", 3)); hr_fi(_o2786, p_1742); hr_fs(_o2786, hr_str("; if (_s", 8)); hr_fi(_o2786, p_1742); hr_fs(_o2786, hr_str(".n != sizeof _d", 15)); hr_fi(_o2786, p_1742); hr_fs(_o2786, hr_str(") hr_die(\"from_bytes: wrong byte count\", ", 41)); }));
(void)(f298_wloc(n_1735));
(void)(({ hrv *_o2787 = &(g163); hr_fs(_o2787, hr_str("); memcpy(&_d", 13)); hr_fi(_o2787, p_1742); hr_fs(_o2787, hr_str(", _s", 4)); hr_fi(_o2787, p_1742); hr_fs(_o2787, hr_str(".p, sizeof _d", 13)); hr_fi(_o2787, p_1742); hr_fs(_o2787, hr_str("); _d", 5)); hr_fi(_o2787, p_1742); hr_fs(_o2787, hr_str("; })", 4)); }));
return;
 }
int64_t rt_1780 = f176_deref(f142_at(recv_1739)); 
int64_t e_1781 = ((int64_t)(((*({ hrv *_t2788 = &(g528); int64_t _i2788 = rt_1780; (S1*)_t2788->b + hr_ix(_i2788, _t2788->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:649"); }))).a_)); 
if (f270_is_lim(rt_1780)) { (void)(f247_ow(hr_str("({ ", 3)));
(void)(f248_ct(rt_1780));
(void)(f247_ow(hr_str(" *_v", 4)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f309_grecv_ptr(recv_1739));
(void)(f247_ow(hr_str("; ", 2)));
if (((b_1737) == (((int64_t)20LL)))) { (void)(f248_ct(e_1781));
(void)(f247_ow(hr_str(" _x", 3)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(f307_arg(((int64_t)1LL), &recv_1739, &n_1735)));
(void)(({ hrv *_o2789 = &(g163); hr_fs(_o2789, hr_str("; if (_v", 8)); hr_fi(_o2789, p_1742); hr_fs(_o2789, hr_str("->n >= ", 7)); hr_fi(_o2789, ((*({ hrv *_t2790 = &(g528); int64_t _i2790 = rt_1780; (S1*)_t2790->b + hr_ix(_i2790, _t2790->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:652"); }))).b_); hr_fs(_o2789, hr_str(") hr_die(\"push past a limited array's capacity\", ", 49)); }));
(void)(f298_wloc(n_1735));
(void)(({ hrv *_o2791 = &(g163); hr_fs(_o2791, hr_str("); _v", 5)); hr_fi(_o2791, p_1742); hr_fs(_o2791, hr_str("->e[_v", 6)); hr_fi(_o2791, p_1742); hr_fs(_o2791, hr_str("->n] = _x", 9)); hr_fi(_o2791, p_1742); hr_fs(_o2791, hr_str("; &_v", 5)); hr_fi(_o2791, p_1742); hr_fs(_o2791, hr_str("->e[_v", 6)); hr_fi(_o2791, p_1742); hr_fs(_o2791, hr_str("->n++]; })", 10)); }));
return;
 }
if (((b_1737) == (((int64_t)21LL)))) { (void)(({ hrv *_o2792 = &(g163); hr_fs(_o2792, hr_str("hsl _s", 6)); hr_fi(_o2792, p_1742); hr_fs(_o2792, hr_str(" = ", 3)); }));
(void)(f278_gas(f307_arg(((int64_t)1LL), &recv_1739, &n_1735)));
(void)(({ hrv *_o2793 = &(g163); hr_fs(_o2793, hr_str("; if (_v", 8)); hr_fi(_o2793, p_1742); hr_fs(_o2793, hr_str("->n + _s", 8)); hr_fi(_o2793, p_1742); hr_fs(_o2793, hr_str(".n > ", 5)); hr_fi(_o2793, ((*({ hrv *_t2794 = &(g528); int64_t _i2794 = rt_1780; (S1*)_t2794->b + hr_ix(_i2794, _t2794->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:653"); }))).b_); hr_fs(_o2793, hr_str(") hr_die(\"append past a limited array's capacity\", ", 51)); }));
(void)(f298_wloc(n_1735));
(void)(({ hrv *_o2795 = &(g163); hr_fs(_o2795, hr_str("); memmove(_v", 13)); hr_fi(_o2795, p_1742); hr_fs(_o2795, hr_str("->e + _v", 8)); hr_fi(_o2795, p_1742); hr_fs(_o2795, hr_str("->n, _s", 7)); hr_fi(_o2795, p_1742); hr_fs(_o2795, hr_str(".p, (size_t)_s", 14)); hr_fi(_o2795, p_1742); hr_fs(_o2795, hr_str(".n * sizeof _v", 14)); hr_fi(_o2795, p_1742); hr_fs(_o2795, hr_str("->e[0]); _v", 11)); hr_fi(_o2795, p_1742); hr_fs(_o2795, hr_str("->n += _s", 9)); hr_fi(_o2795, p_1742); hr_fs(_o2795, hr_str(".n; })", 6)); }));
return;
 }
if (((b_1737) == (((int64_t)22LL)))) { (void)(({ hrv *_o2796 = &(g163); hr_fs(_o2796, hr_str("if (!_v", 7)); hr_fi(_o2796, p_1742); hr_fs(_o2796, hr_str("->n) hr_die(\"pop of an empty array\", ", 37)); }));
(void)(f298_wloc(n_1735));
(void)(({ hrv *_o2797 = &(g163); hr_fs(_o2797, hr_str("); _v", 5)); hr_fi(_o2797, p_1742); hr_fs(_o2797, hr_str("->e[--_v", 8)); hr_fi(_o2797, p_1742); hr_fs(_o2797, hr_str("->n]; })", 8)); }));
return;
 }
if (((b_1737) == (((int64_t)23LL)))) { (void)(({ hrv *_o2798 = &(g163); hr_fs(_o2798, hr_str("int64_t _k", 10)); hr_fi(_o2798, p_1742); hr_fs(_o2798, hr_str(" = ", 3)); }));
(void)(f276_gx(f307_arg(((int64_t)1LL), &recv_1739, &n_1735)));
(void)(({ hrv *_o2799 = &(g163); hr_fs(_o2799, hr_str("; if (_k", 8)); hr_fi(_o2799, p_1742); hr_fs(_o2799, hr_str(" < 0 || _k", 10)); hr_fi(_o2799, p_1742); hr_fs(_o2799, hr_str(" > _v", 5)); hr_fi(_o2799, p_1742); hr_fs(_o2799, hr_str("->n) hr_die(\"pop_n past the length\", ", 37)); }));
(void)(f298_wloc(n_1735));
(void)(({ hrv *_o2800 = &(g163); hr_fs(_o2800, hr_str("); _v", 5)); hr_fi(_o2800, p_1742); hr_fs(_o2800, hr_str("->n -= _k", 9)); hr_fi(_o2800, p_1742); hr_fs(_o2800, hr_str("; })", 4)); }));
return;
 }
if (((b_1737) == (((int64_t)25LL)))) { (void)(({ hrv *_o2801 = &(g163); hr_fs(_o2801, hr_str("_v", 2)); hr_fi(_o2801, p_1742); hr_fs(_o2801, hr_str("->n = 0; })", 11)); }));
return;
 }
if (((b_1737) == (((int64_t)24LL)))) { (void)(({ hrv *_o2802 = &(g163); hr_fs(_o2802, hr_str("int64_t _k", 10)); hr_fi(_o2802, p_1742); hr_fs(_o2802, hr_str(" = ", 3)); }));
(void)(f276_gx(f307_arg(((int64_t)1LL), &recv_1739, &n_1735)));
(void)(({ hrv *_o2803 = &(g163); hr_fs(_o2803, hr_str("; if (_k", 8)); hr_fi(_o2803, p_1742); hr_fs(_o2803, hr_str(" < 0 || _k", 10)); hr_fi(_o2803, p_1742); hr_fs(_o2803, hr_str(" > ", 3)); hr_fi(_o2803, ((*({ hrv *_t2804 = &(g528); int64_t _i2804 = rt_1780; (S1*)_t2804->b + hr_ix(_i2804, _t2804->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:657"); }))).b_); hr_fs(_o2803, hr_str(") hr_die(\"resize past a limited array's capacity\", ", 51)); }));
(void)(f298_wloc(n_1735));
(void)(({ hrv *_o2805 = &(g163); hr_fs(_o2805, hr_str("); for (int64_t _j = _v", 23)); hr_fi(_o2805, p_1742); hr_fs(_o2805, hr_str("->n; _j < _k", 12)); hr_fi(_o2805, p_1742); hr_fs(_o2805, hr_str("; _j++) memset(&_v", 18)); hr_fi(_o2805, p_1742); hr_fs(_o2805, hr_str("->e[_j], 0, sizeof _v", 21)); hr_fi(_o2805, p_1742); hr_fs(_o2805, hr_str("->e[0]); ", 9)); }));
if (((total_1740) > (((int64_t)2LL)))) { (void)(({ hrv *_o2806 = &(g163); hr_fs(_o2806, hr_str("for (int64_t _j = _v", 20)); hr_fi(_o2806, p_1742); hr_fs(_o2806, hr_str("->n; _j < _k", 12)); hr_fi(_o2806, p_1742); hr_fs(_o2806, hr_str("; _j++) _v", 10)); hr_fi(_o2806, p_1742); hr_fs(_o2806, hr_str("->e[_j] = ", 10)); }));
(void)(f276_gx(f307_arg(((int64_t)2LL), &recv_1739, &n_1735)));
(void)(f247_ow(hr_str("; ", 2)));
 }
(void)(({ hrv *_o2807 = &(g163); hr_fs(_o2807, hr_str("_v", 2)); hr_fi(_o2807, p_1742); hr_fs(_o2807, hr_str("->n = _k", 8)); hr_fi(_o2807, p_1742); hr_fs(_o2807, hr_str("; })", 4)); }));
return;
 }
if (((b_1737) == (((int64_t)26LL)))) { (void)(f248_ct(e_1781));
(void)(f247_ow(hr_str(" _x", 3)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(f307_arg(((int64_t)1LL), &recv_1739, &n_1735)));
(void)(({ hrv *_o2808 = &(g163); hr_fs(_o2808, hr_str("; int64_t _r", 12)); hr_fi(_o2808, p_1742); hr_fs(_o2808, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o2808, p_1742); hr_fs(_o2808, hr_str("->n; _j++) if (", 15)); }));
(void)(f312_heq_val_o(e_1781, p_1742));
(void)(({ hrv *_o2809 = &(g163); hr_fs(_o2809, hr_str(") { _r", 6)); hr_fi(_o2809, p_1742); hr_fs(_o2809, hr_str(" = _j; break; } _r", 18)); hr_fi(_o2809, p_1742); hr_fs(_o2809, hr_str("; })", 4)); }));
return;
 }
(void)(f274_gerr(n_1735, hr_str("unsupported limited-array operation", 35)));
return;
 }
if ((((((*({ hrv *_t2810 = &(g528); int64_t _i2810 = rt_1780; (S1*)_t2810->b + hr_ix(_i2810, _t2810->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:661"); }))).k_) == (((uint8_t)9LL))) || f269_is_fix(rt_1780))) { if (((b_1737) == (((int64_t)26LL)))) { (void)(f247_ow(hr_str("({ hsl _v", 9)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f278_gas(recv_1739));
(void)(f247_ow(hr_str("; ", 2)));
(void)(f248_ct(e_1781));
(void)(f247_ow(hr_str(" _x", 3)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(f307_arg(((int64_t)1LL), &recv_1739, &n_1735)));
(void)(({ hrv *_o2811 = &(g163); hr_fs(_o2811, hr_str("; int64_t _r", 12)); hr_fi(_o2811, p_1742); hr_fs(_o2811, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o2811, p_1742); hr_fs(_o2811, hr_str(".n; _j++) if (", 14)); }));
(void)(f316_heq_val_s(e_1781, p_1742));
(void)(({ hrv *_o2812 = &(g163); hr_fs(_o2812, hr_str(") { _r", 6)); hr_fi(_o2812, p_1742); hr_fs(_o2812, hr_str(" = _j; break; } _r", 18)); hr_fi(_o2812, p_1742); hr_fs(_o2812, hr_str("; })", 4)); }));
return;
 }
(void)(f274_gerr(n_1735, hr_str("this operation needs a resizable array", 38)));
return;
 }
(void)(f247_ow(hr_str("({ hrv *_v", 10)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f309_grecv_ptr(recv_1739));
(void)(f247_ow(hr_str("; ", 2)));
if (((b_1737) == (((int64_t)20LL)))) { (void)(f248_ct(e_1781));
(void)(f247_ow(hr_str(" _x", 3)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(f307_arg(((int64_t)1LL), &recv_1739, &n_1735)));
(void)(f247_ow(hr_str("; ", 2)));
(void)(f248_ct(e_1781));
(void)(f247_ow(hr_str(" *_p", 4)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" = (", 4)));
(void)(f248_ct(e_1781));
(void)(({ hrv *_o2813 = &(g163); hr_fs(_o2813, hr_str("*)hr_grow(_v", 12)); hr_fi(_o2813, p_1742); hr_fs(_o2813, hr_str(", 1, sizeof _x", 14)); hr_fi(_o2813, p_1742); hr_fs(_o2813, hr_str("); *_p", 6)); hr_fi(_o2813, p_1742); hr_fs(_o2813, hr_str(" = _x", 5)); hr_fi(_o2813, p_1742); hr_fs(_o2813, hr_str("; _p", 4)); hr_fi(_o2813, p_1742); hr_fs(_o2813, hr_str("; })", 4)); }));
return;
 }
if (((b_1737) == (((int64_t)21LL)))) { (void)(({ hrv *_o2814 = &(g163); hr_fs(_o2814, hr_str("hsl _s", 6)); hr_fi(_o2814, p_1742); hr_fs(_o2814, hr_str(" = ", 3)); }));
(void)(f278_gas(f307_arg(((int64_t)1LL), &recv_1739, &n_1735)));
(void)(({ hrv *_o2815 = &(g163); hr_fs(_o2815, hr_str("; hr_append(_v", 14)); hr_fi(_o2815, p_1742); hr_fs(_o2815, hr_str(", _s", 4)); hr_fi(_o2815, p_1742); hr_fs(_o2815, hr_str(".p, _s", 6)); hr_fi(_o2815, p_1742); hr_fs(_o2815, hr_str(".n, sizeof(", 11)); }));
(void)(f248_ct(e_1781));
(void)(f247_ow(hr_str(")); })", 6)));
return;
 }
if (((b_1737) == (((int64_t)22LL)))) { (void)(({ hrv *_o2816 = &(g163); hr_fs(_o2816, hr_str("if (!_v", 7)); hr_fi(_o2816, p_1742); hr_fs(_o2816, hr_str("->n) hr_die(\"pop of an empty array\", ", 37)); }));
(void)(f298_wloc(n_1735));
(void)(({ hrv *_o2817 = &(g163); hr_fs(_o2817, hr_str("); ((", 5)); }));
(void)(f248_ct(e_1781));
(void)(({ hrv *_o2818 = &(g163); hr_fs(_o2818, hr_str("*)_v", 4)); hr_fi(_o2818, p_1742); hr_fs(_o2818, hr_str("->b)[--_v", 9)); hr_fi(_o2818, p_1742); hr_fs(_o2818, hr_str("->n]; })", 8)); }));
return;
 }
if (((b_1737) == (((int64_t)23LL)))) { (void)(({ hrv *_o2819 = &(g163); hr_fs(_o2819, hr_str("int64_t _k", 10)); hr_fi(_o2819, p_1742); hr_fs(_o2819, hr_str(" = ", 3)); }));
(void)(f276_gx(f307_arg(((int64_t)1LL), &recv_1739, &n_1735)));
(void)(({ hrv *_o2820 = &(g163); hr_fs(_o2820, hr_str("; if (_k", 8)); hr_fi(_o2820, p_1742); hr_fs(_o2820, hr_str(" < 0 || _k", 10)); hr_fi(_o2820, p_1742); hr_fs(_o2820, hr_str(" > _v", 5)); hr_fi(_o2820, p_1742); hr_fs(_o2820, hr_str("->n) hr_die(\"pop_n past the length\", ", 37)); }));
(void)(f298_wloc(n_1735));
(void)(({ hrv *_o2821 = &(g163); hr_fs(_o2821, hr_str("); _v", 5)); hr_fi(_o2821, p_1742); hr_fs(_o2821, hr_str("->n -= _k", 9)); hr_fi(_o2821, p_1742); hr_fs(_o2821, hr_str("; })", 4)); }));
return;
 }
if (((b_1737) == (((int64_t)25LL)))) { (void)(({ hrv *_o2822 = &(g163); hr_fs(_o2822, hr_str("_v", 2)); hr_fi(_o2822, p_1742); hr_fs(_o2822, hr_str("->n = 0; })", 11)); }));
return;
 }
if (((b_1737) == (((int64_t)24LL)))) { (void)(({ hrv *_o2823 = &(g163); hr_fs(_o2823, hr_str("int64_t _k", 10)); hr_fi(_o2823, p_1742); hr_fs(_o2823, hr_str(" = ", 3)); }));
(void)(f276_gx(f307_arg(((int64_t)1LL), &recv_1739, &n_1735)));
(void)(({ hrv *_o2824 = &(g163); hr_fs(_o2824, hr_str("; if (_k", 8)); hr_fi(_o2824, p_1742); hr_fs(_o2824, hr_str(" < 0) hr_die(\"resize to a negative length\", ", 44)); }));
(void)(f298_wloc(n_1735));
(void)(f247_ow(hr_str("); ", 3)));
if (((total_1740) > (((int64_t)2LL)))) { (void)(f248_ct(e_1781));
(void)(f247_ow(hr_str(" _x", 3)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(f307_arg(((int64_t)2LL), &recv_1739, &n_1735)));
(void)(({ hrv *_o2825 = &(g163); hr_fs(_o2825, hr_str("; int64_t _o", 12)); hr_fi(_o2825, p_1742); hr_fs(_o2825, hr_str(" = _v", 5)); hr_fi(_o2825, p_1742); hr_fs(_o2825, hr_str("->n; hr_resize(_v", 17)); hr_fi(_o2825, p_1742); hr_fs(_o2825, hr_str(", _k", 4)); hr_fi(_o2825, p_1742); hr_fs(_o2825, hr_str(", sizeof _x", 11)); hr_fi(_o2825, p_1742); hr_fs(_o2825, hr_str("); for (int64_t _j = _o", 23)); hr_fi(_o2825, p_1742); hr_fs(_o2825, hr_str("; _j < _k", 9)); hr_fi(_o2825, p_1742); hr_fs(_o2825, hr_str("; _j++) ((", 10)); }));
(void)(f248_ct(e_1781));
(void)(({ hrv *_o2826 = &(g163); hr_fs(_o2826, hr_str("*)_v", 4)); hr_fi(_o2826, p_1742); hr_fs(_o2826, hr_str("->b)[_j] = _x", 13)); hr_fi(_o2826, p_1742); hr_fs(_o2826, hr_str("; })", 4)); }));
return;
 }
(void)(({ hrv *_o2827 = &(g163); hr_fs(_o2827, hr_str("hr_resize(_v", 12)); hr_fi(_o2827, p_1742); hr_fs(_o2827, hr_str(", _k", 4)); hr_fi(_o2827, p_1742); hr_fs(_o2827, hr_str(", sizeof(", 9)); }));
(void)(f248_ct(e_1781));
(void)(f247_ow(hr_str(")); })", 6)));
return;
 }
if (((b_1737) == (((int64_t)26LL)))) { (void)(f248_ct(e_1781));
(void)(f247_ow(hr_str(" _x", 3)));
(void)(f281_oi(p_1742));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(f307_arg(((int64_t)1LL), &recv_1739, &n_1735)));
(void)(({ hrv *_o2828 = &(g163); hr_fs(_o2828, hr_str("; int64_t _r", 12)); hr_fi(_o2828, p_1742); hr_fs(_o2828, hr_str(" = -1; for (int64_t _j = 0; _j < _v", 35)); hr_fi(_o2828, p_1742); hr_fs(_o2828, hr_str("->n; _j++) if (", 15)); }));
(void)(f317_heq_val_r(e_1781, p_1742));
(void)(({ hrv *_o2829 = &(g163); hr_fs(_o2829, hr_str(") { _r", 6)); hr_fi(_o2829, p_1742); hr_fs(_o2829, hr_str(" = _j; break; } _r", 18)); hr_fi(_o2829, p_1742); hr_fs(_o2829, hr_str("; })", 4)); }));
return;
 }
(void)(f274_gerr(n_1735, hr_str("unsupported array operation", 27)));
}
static int64_t f307_arg(int64_t i_1741, int64_t *c1739, int64_t *c1735) {
return ({ int64_t _r2830; if ((((*c1739)) >= (((int64_t)0LL)))) { _r2830 = ({ int64_t _r2831; if (((i_1741) == (((int64_t)0LL)))) { _r2831 = (*c1739);  } else { _r2831 = f90_kid((*c1735), ((int64_t)((int64_t)i_1741 - (int64_t)((int64_t)1LL))));  } _r2831; });  } else { _r2830 = f90_kid((*c1735), i_1741);  } _r2830; });
}
static void f308_gfmt(hsl o_1745, int64_t n_1746, int64_t t_1747, bool top_1748) {
int64_t d_1749 = f176_deref(t_1747); 
int64_t k_1750 = ((int64_t)(((*({ hrv *_t2832 = &(g528); int64_t _i2832 = d_1749; (S1*)_t2832->b + hr_ix(_i2832, _t2832->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:367"); }))).k_)); 
if ((((k_1750) == (((int64_t)18LL))) || f165_is_byte_arr(d_1749))) { if (top_1748) { (void)(f247_ow(hr_str("hr_fs(", 6)));
 } else { (void)(f247_ow(hr_str("hr_fq(", 6)));
 }
(void)(f247_ow(o_1745));
(void)(f247_ow(hr_str(", ", 2)));
if (((((*({ hrv *_t2833 = &(g528); int64_t _i2833 = f142_at(n_1746); (S1*)_t2833->b + hr_ix(_i2833, _t2833->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:368"); }))).k_) == (((uint8_t)18LL)))) { (void)(f276_gx(n_1746));
 } else { (void)(f278_gas(n_1746));
 }
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if (((k_1750) == (((int64_t)3LL)))) { (void)(f247_ow(({ hsl _r2834; if (f153_is_signed(d_1749)) { _r2834 = hr_str("hr_fi(", 6);  } else { _r2834 = hr_str("hr_fu(", 6);  } _r2834; })));
(void)(f247_ow(o_1745));
(void)(f247_ow(hr_str(", ", 2)));
if (((d_1749) != (t_1747))) { (void)(f247_ow(hr_str("*", 1)));
 }
(void)(f276_gx(n_1746));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if (((k_1750) == (((int64_t)12LL)))) { (void)(f247_ow(hr_str("hr_fi(", 6)));
(void)(f247_ow(o_1745));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f276_gx(n_1746));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if (((k_1750) == (((int64_t)4LL)))) { (void)(f247_ow(({ hsl _r2835; if (((((*({ hrv *_t2836 = &(g528); int64_t _i2836 = d_1749; (S1*)_t2836->b + hr_ix(_i2836, _t2836->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:371"); }))).s_) == (((uint8_t)4LL)))) { _r2835 = hr_str("hr_ff(", 6);  } else { _r2835 = hr_str("hr_fd(", 6);  } _r2835; })));
(void)(f247_ow(o_1745));
(void)(f247_ow(hr_str(", ", 2)));
if (((d_1749) != (t_1747))) { (void)(f247_ow(hr_str("*", 1)));
 }
(void)(f276_gx(n_1746));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if (((k_1750) == (((int64_t)13LL)))) { (void)(f247_ow(hr_str("hr_fd(", 6)));
(void)(f247_ow(o_1745));
(void)(f247_ow(hr_str(", ", 2)));
(void)(f276_gx(n_1746));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
if (((k_1750) == (((int64_t)2LL)))) { (void)(f247_ow(hr_str("hr_fc(", 6)));
(void)(f247_ow(o_1745));
(void)(f247_ow(hr_str(", (", 3)));
if (((d_1749) != (t_1747))) { (void)(f247_ow(hr_str("*", 1)));
 }
(void)(f276_gx(n_1746));
(void)(f247_ow(hr_str(") \077 \"true\" : \"false\")", 21)));
return;
 }
(void)(f247_ow(hr_str("hf", 2)));
(void)(f281_oi(d_1749));
(void)(f247_ow(hr_str("(", 1)));
(void)(f247_ow(o_1745));
(void)(f247_ow(hr_str(", ", 2)));
if (((d_1749) != (t_1747))) { (void)(f247_ow(hr_str("*", 1)));
 }
if ((((((k_1750) == (((int64_t)8LL))) && (!(f269_is_fix(d_1749)))) && (!(f270_is_lim(d_1749)))) || ((k_1750) == (((int64_t)9LL))))) { (void)(f279_gsl(n_1746, t_1747));
 } else { (void)(f276_gx(n_1746));
 }
(void)(f247_ow(hr_str(")", 1)));
(void)(f286_gen_hf(d_1749));
}
static void f309_grecv_ptr(int64_t r_1755) {
int64_t t_1756 = f142_at(r_1755); 
if (((((*({ hrv *_t2837 = &(g528); int64_t _i2837 = t_1756; (S1*)_t2837->b + hr_ix(_i2837, _t2837->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:616"); }))).k_) == (((uint8_t)10LL)))) { (void)(f262_gx0(r_1755));
return;
 }
if (f259_is_place(r_1755)) { (void)(f247_ow(hr_str("&(", 2)));
(void)(f262_gx0(r_1755));
(void)(f247_ow(hr_str(")", 1)));
return;
 }
int64_t k_1757 = f260_tmp(t_1756, f255_is_res(t_1756)); 
(void)(f247_ow(hr_str("&(", 2)));
(void)(f261_ot(k_1757));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f256_gxo(r_1755));
(void)(f247_ow(hr_str(")", 1)));
}
static void f310_esz(int64_t t_1769) {
(void)(f247_ow(hr_str("sizeof(", 7)));
(void)(f248_ct(t_1769));
(void)(f247_ow(hr_str(")", 1)));
}
static void f311_gaddr(int64_t n_1773) {
if (f259_is_place(n_1773)) { (void)(f247_ow(hr_str("(&(", 3)));
(void)(f262_gx0(n_1773));
(void)(f247_ow(hr_str("))", 2)));
return;
 }
int64_t t_1774 = f142_at(n_1773); 
int64_t k_1775 = f260_tmp(t_1774, f255_is_res(t_1774)); 
(void)(f247_ow(hr_str("(&(", 3)));
(void)(f261_ot(k_1775));
(void)(f247_ow(hr_str(" = (", 4)));
(void)(f256_gxo(n_1773));
(void)(f247_ow(hr_str(")))", 3)));
}
static void f312_heq_val_o(int64_t e_1782, int64_t p_1783) {
L97 a_1784 = ({ L97 _t2838; memset(&_t2838, 0, sizeof _t2838); _t2838.n = 0; _t2838; }); 
L97 b_1785 = ({ L97 _t2839; memset(&_t2839, 0, sizeof _t2839); _t2839.n = 0; _t2839; }); 
(void)(({ L97 *_l2840 = &(a_1784); hrv _o2840 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2840, hr_str("_v", 2)); hr_fi(&_o2840, p_1783); hr_fs(&_o2840, hr_str("->e[_j]", 7)); if (_l2840->n + _o2840.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:682"); memcpy(_l2840->e + _l2840->n, _o2840.b, (size_t)_o2840.n); _l2840->n += _o2840.n; }));
(void)(({ L97 *_l2841 = &(b_1785); hrv _o2841 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2841, hr_str("_x", 2)); hr_fi(&_o2841, p_1783); if (_l2841->n + _o2841.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:682"); memcpy(_l2841->e + _l2841->n, _o2841.b, (size_t)_o2841.n); _l2841->n += _o2841.n; }));
(void)(f313_heq_o(e_1782, ({ hsl _t2842 = ({ L97 *_t2843 = &(a_1784); (hsl){ (uint8_t*)_t2843->e, _t2843->n }; }); int64_t _l2842 = 0, _h2842 = _t2842.n; if (_l2842 < 0 || _h2842 < _l2842 || _h2842 > _t2842.n) hr_slerr(_l2842, _h2842, _t2842.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:682"); (hsl){ _t2842.p + _l2842 * (int64_t)sizeof(uint8_t), _h2842 - _l2842 }; }), ({ hsl _t2844 = ({ L97 *_t2845 = &(b_1785); (hsl){ (uint8_t*)_t2845->e, _t2845->n }; }); int64_t _l2844 = 0, _h2844 = _t2844.n; if (_l2844 < 0 || _h2844 < _l2844 || _h2844 > _t2844.n) hr_slerr(_l2844, _h2844, _t2844.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:682"); (hsl){ _t2844.p + _l2844 * (int64_t)sizeof(uint8_t), _h2844 - _l2844 }; })));
}
static void f313_heq_o(int64_t e_1786, hsl a_1787, hsl b_1788) {
(void)(f314_heq_pre(e_1786));
int64_t s0_1792 = (g169).n; 
(void)(f290_heq_val(e_1786, a_1787, b_1788));
(void)(({ hrv *_v2846 = &(g163); hsl _s2846 = ({ hsl _t2847 = hr_sl(g169); int64_t _l2847 = s0_1792, _h2847 = _t2847.n; if (_l2847 < 0 || _h2847 < _l2847 || _h2847 > _t2847.n) hr_slerr(_l2847, _h2847, _t2847.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:679"); (hsl){ _t2847.p + _l2847 * (int64_t)sizeof(uint8_t), _h2847 - _l2847 }; }); hr_append(_v2846, _s2846.p, _s2846.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2848 = &(g169); int64_t _k2848 = s0_1792; if (_k2848 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:679"); hr_resize(_v2848, _k2848, sizeof(uint8_t)); }));
}
static void f314_heq_pre(int64_t t_1789) {
if ((!(f315_scalar_ty(t_1789)))) { (void)(f282_gen_heq(t_1789));
 }
}
static bool f315_scalar_ty(int64_t t_1790) {
int64_t k_1791 = ((int64_t)(((*({ hrv *_t2849 = &(g528); int64_t _i2849 = t_1790; (S1*)_t2849->b + hr_ix(_i2849, _t2849->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:680"); }))).k_)); 
return (((((k_1791) == (((int64_t)3LL))) || ((k_1791) == (((int64_t)4LL)))) || ((k_1791) == (((int64_t)2LL)))) || ((k_1791) == (((int64_t)10LL))));
}
static void f316_heq_val_s(int64_t e_1793, int64_t p_1794) {
L95 a_1795 = ({ L95 _t2850; memset(&_t2850, 0, sizeof _t2850); _t2850.n = 0; _t2850; }); 
L97 b_1796 = ({ L97 _t2851; memset(&_t2851, 0, sizeof _t2851); _t2851.n = 0; _t2851; }); 
(void)(({ L95 *_v2852 = &(a_1795); hsl _s2852 = hr_str("((", 2); if (_v2852->n + _s2852.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:683"); memmove(_v2852->e + _v2852->n, _s2852.p, (size_t)_s2852.n * sizeof _v2852->e[0]); _v2852->n += _s2852.n; }));
(void)(({ L95 *_v2853 = &(a_1795); hsl _s2853 = f251_cn(e_1793); if (_v2853->n + _s2853.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:683"); memmove(_v2853->e + _v2853->n, _s2853.p, (size_t)_s2853.n * sizeof _v2853->e[0]); _v2853->n += _s2853.n; }));
(void)(({ L95 *_l2854 = &(a_1795); hrv _o2854 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2854, hr_str("*)_v", 4)); hr_fi(&_o2854, p_1794); hr_fs(&_o2854, hr_str(".p)[_j]", 7)); if (_l2854->n + _o2854.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:683"); memcpy(_l2854->e + _l2854->n, _o2854.b, (size_t)_o2854.n); _l2854->n += _o2854.n; }));
(void)(({ L97 *_l2855 = &(b_1796); hrv _o2855 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2855, hr_str("_x", 2)); hr_fi(&_o2855, p_1794); if (_l2855->n + _o2855.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:683"); memcpy(_l2855->e + _l2855->n, _o2855.b, (size_t)_o2855.n); _l2855->n += _o2855.n; }));
(void)(f313_heq_o(e_1793, ({ hsl _t2856 = ({ L95 *_t2857 = &(a_1795); (hsl){ (uint8_t*)_t2857->e, _t2857->n }; }); int64_t _l2856 = 0, _h2856 = _t2856.n; if (_l2856 < 0 || _h2856 < _l2856 || _h2856 > _t2856.n) hr_slerr(_l2856, _h2856, _t2856.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:683"); (hsl){ _t2856.p + _l2856 * (int64_t)sizeof(uint8_t), _h2856 - _l2856 }; }), ({ hsl _t2858 = ({ L97 *_t2859 = &(b_1796); (hsl){ (uint8_t*)_t2859->e, _t2859->n }; }); int64_t _l2858 = 0, _h2858 = _t2858.n; if (_l2858 < 0 || _h2858 < _l2858 || _h2858 > _t2858.n) hr_slerr(_l2858, _h2858, _t2858.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:683"); (hsl){ _t2858.p + _l2858 * (int64_t)sizeof(uint8_t), _h2858 - _l2858 }; })));
}
static void f317_heq_val_r(int64_t e_1797, int64_t p_1798) {
L95 a_1799 = ({ L95 _t2860; memset(&_t2860, 0, sizeof _t2860); _t2860.n = 0; _t2860; }); 
L97 b_1800 = ({ L97 _t2861; memset(&_t2861, 0, sizeof _t2861); _t2861.n = 0; _t2861; }); 
(void)(({ L95 *_v2862 = &(a_1799); hsl _s2862 = hr_str("((", 2); if (_v2862->n + _s2862.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:684"); memmove(_v2862->e + _v2862->n, _s2862.p, (size_t)_s2862.n * sizeof _v2862->e[0]); _v2862->n += _s2862.n; }));
(void)(({ L95 *_v2863 = &(a_1799); hsl _s2863 = f251_cn(e_1797); if (_v2863->n + _s2863.n > 128) hr_die("append past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:684"); memmove(_v2863->e + _v2863->n, _s2863.p, (size_t)_s2863.n * sizeof _v2863->e[0]); _v2863->n += _s2863.n; }));
(void)(({ L95 *_l2864 = &(a_1799); hrv _o2864 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2864, hr_str("*)_v", 4)); hr_fi(&_o2864, p_1798); hr_fs(&_o2864, hr_str("->b)[_j]", 8)); if (_l2864->n + _o2864.n > 128) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:684"); memcpy(_l2864->e + _l2864->n, _o2864.b, (size_t)_o2864.n); _l2864->n += _o2864.n; }));
(void)(({ L97 *_l2865 = &(b_1800); hrv _o2865 __attribute__((cleanup(hr_rdrop))) = {0}; hr_fs(&_o2865, hr_str("_x", 2)); hr_fi(&_o2865, p_1798); if (_l2865->n + _o2865.n > 64) hr_die("format past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:684"); memcpy(_l2865->e + _l2865->n, _o2865.b, (size_t)_o2865.n); _l2865->n += _o2865.n; }));
(void)(f313_heq_o(e_1797, ({ hsl _t2866 = ({ L95 *_t2867 = &(a_1799); (hsl){ (uint8_t*)_t2867->e, _t2867->n }; }); int64_t _l2866 = 0, _h2866 = _t2866.n; if (_l2866 < 0 || _h2866 < _l2866 || _h2866 > _t2866.n) hr_slerr(_l2866, _h2866, _t2866.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:684"); (hsl){ _t2866.p + _l2866 * (int64_t)sizeof(uint8_t), _h2866 - _l2866 }; }), ({ hsl _t2868 = ({ L97 *_t2869 = &(b_1800); (hsl){ (uint8_t*)_t2869->e, _t2869->n }; }); int64_t _l2868 = 0, _h2868 = _t2868.n; if (_l2868 < 0 || _h2868 < _l2868 || _h2868 > _t2868.n) hr_slerr(_l2868, _h2868, _t2868.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:684"); (hsl){ _t2868.p + _l2868 * (int64_t)sizeof(uint8_t), _h2868 - _l2868 }; })));
}
static void f318_gblkcall(int64_t n_1801) {
int64_t bi_1802 = f158_rv(n_1801); 
int64_t fv_1803 = ((int64_t)(((*({ hrv *_t2870 = &(g373); int64_t _i2870 = bi_1802; (S6*)_t2870->b + hr_ix(_i2870, _t2870->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:596"); }))).node_)); 
int64_t sa_1804 = g384; 
(void)(f247_ow(hr_str("({ ", 3)));
int64_t np_1805 = ((int64_t)(((*({ hrv *_t2871 = &(g679); int64_t _i2871 = fv_1803; (S4*)_t2871->b + hr_ix(_i2871, _t2871->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:599"); }))).n_)); 
int64_t na_1806 = ((int64_t)(((*({ hrv *_t2872 = &(g679); int64_t _i2872 = n_1801; (S4*)_t2872->b + hr_ix(_i2872, _t2872->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:600"); }))).n_)); 
if (((((uint16_t)((uint64_t)((*({ hrv *_t2873 = &(g679); int64_t _i2873 = fv_1803; (S4*)_t2873->b + hr_ix(_i2873, _t2873->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:601"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { { int64_t _e2875 = np_1805; for (int64_t _k2875 = 0; _k2875 < _e2875; _k2875++) { int64_t j_1807 = (int64_t)_k2875; int64_t p_1808 = f90_kid(fv_1803, j_1807); 
g384 = bi_1802;
int64_t v_1809 = f158_rv(p_1808); 
g384 = sa_1804;
if (((j_1807) < (na_1806))) { (void)(f248_ct(((int64_t)(((*({ hrv *_t2876 = &(g374); int64_t _i2876 = v_1809; (S12*)_t2876->b + hr_ix(_i2876, _t2876->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:602"); }))).ty_))));
(void)(f247_ow(hr_str(" ", 1)));
(void)(f273_lv_name(v_1809));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(f90_kid(n_1801, j_1807)));
(void)(f247_ow(hr_str("; ", 2)));
 }
 } } _bk2874:; 
 } else { if (((na_1806) >= (((int64_t)1LL)))) { g384 = bi_1802;
int64_t v_1810 = f158_rv(fv_1803); 
g384 = sa_1804;
if (((v_1810) >= (((int64_t)0LL)))) { (void)(f248_ct(((int64_t)(((*({ hrv *_t2877 = &(g374); int64_t _i2877 = v_1810; (S12*)_t2877->b + hr_ix(_i2877, _t2877->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:604"); }))).ty_))));
(void)(f247_ow(hr_str(" ", 1)));
(void)(f273_lv_name(v_1810));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(f90_kid(n_1801, ((int64_t)0LL))));
(void)(f247_ow(hr_str("; ", 2)));
 } else { (void)(f247_ow(hr_str("(void)(", 7)));
(void)(f276_gx(f90_kid(n_1801, ((int64_t)0LL))));
(void)(f247_ow(hr_str("); ", 3)));
 }
 }
 }
g384 = bi_1802;
int64_t body_1811 = ((int64_t)(((*({ hrv *_t2878 = &(g679); int64_t _i2878 = fv_1803; (S4*)_t2878->b + hr_ix(_i2878, _t2878->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:607"); }))).a_)); 
{ int32_t _e2880 = ((*({ hrv *_t2881 = &(g679); int64_t _i2881 = body_1811; (S4*)_t2881->b + hr_ix(_i2881, _t2881->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:608"); }))).n_; for (int32_t _k2880 = 0; _k2880 < _e2880; _k2880++) { int32_t i_1812 = (int32_t)_k2880; (void)(f319_gstmt(f90_kid(body_1811, ((int64_t)(i_1812)))));
 } } _bk2879:; 
int64_t tl_1937 = ((int64_t)(((*({ hrv *_t2882 = &(g679); int64_t _i2882 = body_1811; (S4*)_t2882->b + hr_ix(_i2882, _t2882->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:609"); }))).a_)); 
if (((tl_1937) >= (((int64_t)0LL)))) { if ((((((int64_t)(((*({ hrv *_t2883 = &(g373); int64_t _i2883 = bi_1802; (S6*)_t2883->b + hr_ix(_i2883, _t2883->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:610"); }))).ret_))) != (g535)) && (!(f204_ends(tl_1937))))) { (void)(f276_gx(tl_1937));
(void)(f247_ow(hr_str("; ", 2)));
 } else { (void)(f319_gstmt(tl_1937));
 }
 }
g384 = sa_1804;
(void)(f247_ow(hr_str(" })", 3)));
}
static void f319_gstmt(int64_t n_1813) {
if (((n_1813) < (((int64_t)0LL)))) { return;
 }
int64_t sp_1814 = (g163).n; 
int64_t td_1815 = (g176).n; 
S4 x_1816 = (*({ hrv *_t2884 = &(g679); int64_t _i2884 = n_1813; (S4*)_t2884->b + hr_ix(_i2884, _t2884->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:986"); })); 
int64_t k_1817 = ((int64_t)((x_1816).k_)); 
bool decl_1818 = ((k_1817) == (((int64_t)33LL))); 
if (((k_1817) == (((int64_t)33LL)))) { (void)(f320_gvdecl(n_1813));
 } else { (void)(f322_gstmt1(n_1813));
 }
(void)(f247_ow(hr_str("\012", 1)));
if ((((g176).n) > (td_1815))) { (void)(({ hrv *_v2885 = &(g177); _v2885->n = 0; }));
(void)(({ hrv *_v2886 = &(g177); hsl _s2886 = ({ hsl _t2887 = hr_sl(g163); int64_t _l2887 = sp_1814, _h2887 = _t2887.n; if (_l2887 < 0 || _h2887 < _l2887 || _h2887 > _t2887.n) hr_slerr(_l2887, _h2887, _t2887.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:992"); (hsl){ _t2887.p + _l2887 * (int64_t)sizeof(uint8_t), _h2887 - _l2887 }; }); hr_append(_v2886, _s2886.p, _s2886.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2888 = &(g163); int64_t _k2888 = sp_1814; if (_k2888 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:992"); hr_resize(_v2888, _k2888, sizeof(uint8_t)); }));
if ((!(decl_1818))) { (void)(f247_ow(hr_str("{ ", 2)));
 }
(void)(({ hrv *_v2889 = &(g163); hsl _s2889 = ({ hsl _t2890 = hr_sl(g176); int64_t _l2890 = td_1815, _h2890 = _t2890.n; if (_l2890 < 0 || _h2890 < _l2890 || _h2890 > _t2890.n) hr_slerr(_l2890, _h2890, _t2890.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:994"); (hsl){ _t2890.p + _l2890 * (int64_t)sizeof(uint8_t), _h2890 - _l2890 }; }); hr_append(_v2889, _s2889.p, _s2889.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v2891 = &(g176); int64_t _k2891 = td_1815; if (_k2891 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:994"); hr_resize(_v2891, _k2891, sizeof(uint8_t)); }));
(void)(({ hrv *_v2892 = &(g163); hsl _s2892 = ({ hsl _t2893 = hr_sl(g177); int64_t _l2893 = 0, _h2893 = _t2893.n; if (_l2893 < 0 || _h2893 < _l2893 || _h2893 > _t2893.n) hr_slerr(_l2893, _h2893, _t2893.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:995"); (hsl){ _t2893.p + _l2893 * (int64_t)sizeof(uint8_t), _h2893 - _l2893 }; }); hr_append(_v2892, _s2892.p, _s2892.n, sizeof(uint8_t)); }));
if ((!(decl_1818))) { (void)(f247_ow(hr_str("}\012", 2)));
 }
 }
}
static void f320_gvdecl(int64_t n_1819) {
S4 x_1820 = (*({ hrv *_t2894 = &(g679); int64_t _i2894 = n_1819; (S4*)_t2894->b + hr_ix(_i2894, _t2894->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:887"); })); 
if ((((x_1820).n_) > (((int32_t)1LL)))) { if (((f211_ax(n_1819)) == (((int64_t)1LL)))) { L90 ids_1821 = ({ L90 _t2895; memset(&_t2895, 0, sizeof _t2895); _t2895.n = 0; _t2895; }); 
{ int32_t _e2897 = (x_1820).n_; for (int32_t _k2897 = 0; _k2897 < _e2897; _k2897++) { int32_t i_1822 = (int32_t)_k2897; int64_t iv_1823 = f90_kid(((int64_t)((x_1820).b_)), ((int64_t)(i_1822))); 
int64_t p_1824 = f280_nt(); 
(void)(({ L90 *_v2898 = &(ids_1821); int32_t _x2898 = ((int32_t)(p_1824)); if (_v2898->n >= 64) hr_die("push past a limited array's capacity", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:891"); _v2898->e[_v2898->n] = _x2898; &_v2898->e[_v2898->n++]; }));
(void)(f248_ct(f266_fin(iv_1823)));
(void)(f247_ow(hr_str(" _t", 3)));
(void)(f281_oi(p_1824));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(iv_1823));
(void)(f247_ow(hr_str("; ", 2)));
 } } _bk2896:; 
int64_t v0_1825 = f158_rv(n_1819); 
{ int32_t _e2900 = (x_1820).n_; for (int32_t _k2900 = 0; _k2900 < _e2900; _k2900++) { int32_t i_1826 = (int32_t)_k2900; (void)(f321_decl_lv(((int64_t)((int64_t)v0_1825 + (int64_t)((int64_t)(i_1826))))));
(void)(({ hrv *_o2901 = &(g163); hr_fs(_o2901, hr_str(" = _t", 5)); hr_fi(_o2901, (*({ L90 *_t2902 = &(ids_1821); int64_t _i2902 = i_1826; _t2902->e + hr_ix(_i2902, _t2902->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:893"); }))); hr_fs(_o2901, hr_str("; ", 2)); }));
 } } _bk2899:; 
return;
 }
int64_t init_1829 = f90_kid(((int64_t)((x_1820).b_)), ((int64_t)0LL)); 
int64_t p_1830 = f280_nt(); 
(void)(f248_ct(f142_at(init_1829)));
(void)(f247_ow(hr_str(" _t", 3)));
(void)(f281_oi(p_1830));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(init_1829));
(void)(f247_ow(hr_str("; ", 2)));
int64_t v0_1831 = f158_rv(n_1819); 
{ int32_t _e2904 = (x_1820).n_; for (int32_t _k2904 = 0; _k2904 < _e2904; _k2904++) { int32_t i_1832 = (int32_t)_k2904; (void)(f321_decl_lv(((int64_t)((int64_t)v0_1831 + (int64_t)((int64_t)(i_1832))))));
(void)(({ hrv *_o2905 = &(g163); hr_fs(_o2905, hr_str(" = _t", 5)); hr_fi(_o2905, p_1830); hr_fs(_o2905, hr_str(".r", 2)); hr_fi(_o2905, i_1832); hr_fs(_o2905, hr_str("; ", 2)); }));
 } } _bk2903:; 
return;
 }
int64_t v_1833 = f158_rv(n_1819); 
int64_t t_1834 = ((int64_t)(((*({ hrv *_t2906 = &(g374); int64_t _i2906 = v_1833; (S12*)_t2906->b + hr_ix(_i2906, _t2906->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:904"); }))).ty_)); 
(void)(f321_decl_lv(v_1833));
(void)(f247_ow(hr_str(" = ", 3)));
if ((((x_1820).b_) < (((int32_t)0LL)))) { (void)(f247_ow(hr_str("{0}; ", 5)));
return;
 }
int64_t init_1835 = f90_kid(((int64_t)((x_1820).b_)), ((int64_t)0LL)); 
if (((((*({ hrv *_t2907 = &(g528); int64_t _i2907 = t_1834; (S1*)_t2907->b + hr_ix(_i2907, _t2907->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:909"); }))).k_) == (((uint8_t)10LL)))) { int64_t it_1836 = f266_fin(init_1835); 
if ((((((*({ hrv *_t2908 = &(g528); int64_t _i2908 = it_1836; (S1*)_t2908->b + hr_ix(_i2908, _t2908->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:909"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t2909 = &(g528); int64_t _i2909 = it_1836; (S1*)_t2909->b + hr_ix(_i2909, _t2909->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:909"); }))).k_) == (((uint8_t)11LL))))) { (void)(f276_gx(init_1835));
 } else { (void)(f311_gaddr(init_1835));
 }
(void)(f247_ow(hr_str("; ", 2)));
return;
 }
if (f255_is_res(t_1834)) { (void)(f256_gxo(init_1835));
(void)(f247_ow(hr_str("; ", 2)));
return;
 }
int64_t it_1837 = f142_at(init_1835); 
if (((((*({ hrv *_t2910 = &(g528); int64_t _i2910 = it_1837; (S1*)_t2910->b + hr_ix(_i2910, _t2910->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:912"); }))).k_) == (((uint8_t)14LL)))) { (void)(f276_gx(init_1835));
(void)(({ hrv *_o2911 = &(g163); hr_fs(_o2911, hr_str(".r0; ", 5)); }));
return;
 }
(void)(f276_gx(init_1835));
(void)(f247_ow(hr_str("; ", 2)));
}
static void f321_decl_lv(int64_t v_1827) {
int64_t t_1828 = ((int64_t)(((*({ hrv *_t2912 = &(g374); int64_t _i2912 = v_1827; (S12*)_t2912->b + hr_ix(_i2912, _t2912->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:916"); }))).ty_)); 
(void)(f248_ct(t_1828));
(void)(f247_ow(hr_str(" ", 1)));
if (f272_lv_isptr(v_1827)) { (void)(f247_ow(hr_str("*", 1)));
 }
(void)(f273_lv_name(v_1827));
if ((f255_is_res(t_1828) && (!(f272_lv_isptr(v_1827))))) { (void)(f247_ow(hr_str(" __attribute__((cleanup(hr_rdrop)))", 35)));
 }
}
static void f322_gstmt1(int64_t n_1838) {
S4 x_1839 = (*({ hrv *_t2913 = &(g679); int64_t _i2913 = n_1838; (S4*)_t2913->b + hr_ix(_i2913, _t2913->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1000"); })); 
int64_t k_1840 = ((int64_t)((x_1839).k_)); 
if (((k_1840) == (((int64_t)34LL)))) { (void)(f323_gassign(n_1838));
return;
 }
if (((k_1840) == (((int64_t)35LL)))) { int64_t a_1855 = ((int64_t)((x_1839).a_)); 
int64_t tt_1856 = f142_at(a_1855); 
if (((((*({ hrv *_t2914 = &(g528); int64_t _i2914 = tt_1856; (S1*)_t2914->b + hr_ix(_i2914, _t2914->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1003"); }))).k_) == (((uint8_t)10LL)))) { (void)(f247_ow(hr_str("(*", 2)));
(void)(f262_gx0(a_1855));
(void)(f247_ow(hr_str(")", 1)));
 } else { (void)(f276_gx(a_1855));
 }
(void)(f247_ow(({ hsl _r2915; if (((((int64_t)((x_1839).op_))) == (((int64_t)34LL)))) { _r2915 = hr_str("++;", 3);  } else { _r2915 = hr_str("--;", 3);  } _r2915; })));
return;
 }
if (((k_1840) == (((int64_t)50LL)))) { return;
 }
if (((k_1840) == (((int64_t)19LL)))) { (void)(f325_gif(n_1838, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1840) == (((int64_t)25LL)))) { (void)(f328_gwhile(n_1838));
return;
 }
if (((k_1840) == (((int64_t)26LL)))) { (void)(f331_gloop(n_1838, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1840) == (((int64_t)27LL)))) { (void)(f332_gfor(n_1838));
return;
 }
if (((k_1840) == (((int64_t)20LL)))) { (void)(f333_gmatch(n_1838, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1840) == (((int64_t)24LL)))) { (void)(f334_geblock(n_1838, ((int64_t)(0 - (uint64_t)(((int64_t)1LL))))));
return;
 }
if (((k_1840) == (((int64_t)23LL)))) { (void)(f247_ow(hr_str("{ ", 2)));
(void)(f326_gblk(n_1838, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f247_ow(hr_str(" }", 2)));
return;
 }
if (((k_1840) == (((int64_t)28LL)))) { (void)(f335_gret(n_1838));
return;
 }
if (((k_1840) == (((int64_t)29LL)))) { (void)(f338_gbreak(n_1838));
return;
 }
if (((k_1840) == (((int64_t)30LL)))) { (void)(f247_ow(hr_str("continue;", 9)));
return;
 }
if (((k_1840) == (((int64_t)37LL)))) { (void)(f274_gerr(n_1838, hr_str("const for is not supported by the self-hosted compiler yet", 58)));
return;
 }
if (f339_owned(n_1838)) { (void)(f247_ow(hr_str("hr_rgive(", 9)));
(void)(f262_gx0(n_1838));
(void)(f247_ow(hr_str(");", 2)));
return;
 }
(void)(f247_ow(hr_str("(void)(", 7)));
(void)(f276_gx(n_1838));
(void)(f247_ow(hr_str(");", 2)));
}
static void f323_gassign(int64_t n_1841) {
S4 x_1842 = (*({ hrv *_t2916 = &(g679); int64_t _i2916 = n_1841; (S4*)_t2916->b + hr_ix(_i2916, _t2916->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:923"); })); 
int64_t o_1843 = ((int64_t)((x_1842).op_)); 
if (((o_1843) == (((int64_t)11LL)))) { int64_t p_1844 = f280_nt(); 
(void)(f247_ow(hr_str("{ ", 2)));
(void)(f248_ct(f142_at(((int64_t)((x_1842).b_)))));
(void)(f247_ow(hr_str(" _t", 3)));
(void)(f281_oi(p_1844));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(((int64_t)((x_1842).b_))));
(void)(f247_ow(hr_str("; ", 2)));
int64_t tl_1845 = ((int64_t)((x_1842).a_)); 
{ int32_t _e2918 = ((*({ hrv *_t2919 = &(g679); int64_t _i2919 = tl_1845; (S4*)_t2919->b + hr_ix(_i2919, _t2919->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:929"); }))).n_; for (int32_t _k2918 = 0; _k2918 < _e2918; _k2918++) { int32_t i_1846 = (int32_t)_k2918; int64_t tg_1847 = f90_kid(tl_1845, ((int64_t)(i_1846))); 
(void)(f276_gx(tg_1847));
(void)(({ hrv *_o2920 = &(g163); hr_fs(_o2920, hr_str(" = _t", 5)); hr_fi(_o2920, p_1844); hr_fs(_o2920, hr_str(".r", 2)); hr_fi(_o2920, i_1846); hr_fs(_o2920, hr_str("; ", 2)); }));
 } } _bk2917:; 
(void)(f247_ow(hr_str("}", 1)));
return;
 }
int64_t a_1848 = ((int64_t)((x_1842).a_)); 
int64_t tt_1849 = f142_at(a_1848); 
int64_t d_1850 = f176_deref(tt_1849); 
if ((((o_1843) == (((int64_t)18LL))) && ((((*({ hrv *_t2921 = &(g528); int64_t _i2921 = tt_1849; (S1*)_t2921->b + hr_ix(_i2921, _t2921->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:936"); }))).k_) == (((uint8_t)10LL))))) { int64_t b_1851 = ((int64_t)((x_1842).b_)); 
(void)(f262_gx0(a_1848));
(void)(f247_ow(hr_str(" = ", 3)));
if ((((((*({ hrv *_t2922 = &(g528); int64_t _i2922 = f266_fin(b_1851); (S1*)_t2922->b + hr_ix(_i2922, _t2922->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:939"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t2923 = &(g528); int64_t _i2923 = f266_fin(b_1851); (S1*)_t2923->b + hr_ix(_i2923, _t2923->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:939"); }))).k_) == (((uint8_t)11LL))))) { (void)(f276_gx(b_1851));
 } else { (void)(f311_gaddr(b_1851));
 }
(void)(f247_ow(hr_str(";", 1)));
return;
 }
if ((((o_1843) == (((int64_t)36LL))) || ((o_1843) == (((int64_t)18LL))))) { if (f255_is_res(d_1850)) { (void)(f247_ow(hr_str("hr_rset(", 8)));
if (((((*({ hrv *_t2924 = &(g528); int64_t _i2924 = tt_1849; (S1*)_t2924->b + hr_ix(_i2924, _t2924->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:944"); }))).k_) == (((uint8_t)10LL)))) { (void)(f262_gx0(a_1848));
 } else { (void)(f247_ow(hr_str("&(", 2)));
(void)(f276_gx(a_1848));
(void)(f247_ow(hr_str(")", 1)));
 }
(void)(f247_ow(hr_str(", ", 2)));
(void)(f256_gxo(((int64_t)((x_1842).b_))));
(void)(f247_ow(hr_str(");", 2)));
return;
 }
if ((((((((*({ hrv *_t2925 = &(g528); int64_t _i2925 = tt_1849; (S1*)_t2925->b + hr_ix(_i2925, _t2925->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:945"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t2926 = &(g528); int64_t _i2926 = f142_at(((int64_t)((x_1842).b_))); (S1*)_t2926->b + hr_ix(_i2926, _t2926->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:945"); }))).k_) != (((uint8_t)10LL)))) && ((((*({ hrv *_t2927 = &(g528); int64_t _i2927 = f266_fin(((int64_t)((x_1842).b_))); (S1*)_t2927->b + hr_ix(_i2927, _t2927->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:945"); }))).k_) != (((uint8_t)10LL)))) && ((((*({ hrv *_t2928 = &(g528); int64_t _i2928 = f142_at(((int64_t)((x_1842).b_))); (S1*)_t2928->b + hr_ix(_i2928, _t2928->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:945"); }))).k_) != (((uint8_t)11LL))))) { (void)(f247_ow(hr_str("*", 1)));
(void)(f262_gx0(a_1848));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(((int64_t)((x_1842).b_))));
(void)(f247_ow(hr_str(";", 1)));
return;
 }
if (((((*({ hrv *_t2929 = &(g679); int64_t _i2929 = a_1848; (S4*)_t2929->b + hr_ix(_i2929, _t2929->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:946"); }))).k_) == (((uint8_t)8LL)))) { (void)(f276_gx(a_1848));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(((int64_t)((x_1842).b_))));
(void)(f247_ow(hr_str(";", 1)));
return;
 }
int64_t q_1852 = f280_nt(); 
(void)(f247_ow(hr_str("{ ", 2)));
(void)(f248_ct(d_1850));
(void)(f247_ow(hr_str(" *_t", 4)));
(void)(f281_oi(q_1852));
(void)(f247_ow(hr_str(" = &(", 5)));
(void)(f276_gx(a_1848));
(void)(f247_ow(hr_str("); *_t", 6)));
(void)(f281_oi(q_1852));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(((int64_t)((x_1842).b_))));
(void)(f247_ow(hr_str("; }", 3)));
return;
 }
int64_t p_1853 = f280_nt(); 
(void)(f247_ow(hr_str("{ ", 2)));
(void)(f248_ct(d_1850));
(void)(f247_ow(hr_str(" *_t", 4)));
(void)(f281_oi(p_1853));
(void)(f247_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t2930 = &(g528); int64_t _i2930 = tt_1849; (S1*)_t2930->b + hr_ix(_i2930, _t2930->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:953"); }))).k_) == (((uint8_t)10LL)))) { (void)(f262_gx0(a_1848));
 } else { (void)(f247_ow(hr_str("&(", 2)));
(void)(f276_gx(a_1848));
(void)(f247_ow(hr_str(")", 1)));
 }
(void)(f247_ow(hr_str("; *_t", 5)));
(void)(f281_oi(p_1853));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f293_garith(f324_base_op(o_1843), d_1850, ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), ((int64_t)((x_1842).b_)), p_1853, n_1841));
(void)(f247_ow(hr_str("; }", 3)));
}
static int64_t f324_base_op(int64_t o_1854) {
if (((o_1854) == (((int64_t)26LL)))) { return ((int64_t)21LL);
 }
if (((o_1854) == (((int64_t)27LL)))) { return ((int64_t)22LL);
 }
if (((o_1854) == (((int64_t)28LL)))) { return ((int64_t)23LL);
 }
if (((o_1854) == (((int64_t)29LL)))) { return ((int64_t)24LL);
 }
if (((o_1854) == (((int64_t)30LL)))) { return ((int64_t)25LL);
 }
if (((o_1854) == (((int64_t)31LL)))) { return ((int64_t)49LL);
 }
if (((o_1854) == (((int64_t)32LL)))) { return ((int64_t)50LL);
 }
if (((o_1854) == (((int64_t)33LL)))) { return ((int64_t)51LL);
 }
if (((o_1854) == (((int64_t)45LL)))) { return ((int64_t)43LL);
 }
if (((o_1854) == (((int64_t)46LL)))) { return ((int64_t)44LL);
 }
return o_1854;
}
static void f325_gif(int64_t n_1857, int64_t res_1858) {
S4 x_1859 = (*({ hrv *_t2931 = &(g679); int64_t _i2931 = n_1857; (S4*)_t2931->b + hr_ix(_i2931, _t2931->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:770"); })); 
(void)(f247_ow(hr_str("if (", 4)));
int64_t m_1860 = f211_ax(n_1857); 
if ((((m_1860) != (((int64_t)0LL))) && ((m_1860) != (((int64_t)(0 - (uint64_t)(((int64_t)1LL)))))))) { (void)(f247_ow(hr_str("(", 1)));
(void)(f262_gx0(((int64_t)((x_1859).a_))));
(void)(f247_ow(hr_str(") != 0", 6)));
 } else { (void)(f276_gx(((int64_t)((x_1859).a_))));
 }
(void)(f247_ow(hr_str(") { ", 4)));
if (((m_1860) > (((int64_t)1LL)))) { int64_t v_1861 = ((int64_t)((int64_t)m_1860 & (int64_t)((int64_t)((int64_t)((int64_t)((((int64_t)1LL)) << ((((int64_t)30LL)) & 63))) - (int64_t)((int64_t)1LL))))); 
(void)(f248_ct(((int64_t)(((*({ hrv *_t2932 = &(g374); int64_t _i2932 = v_1861; (S12*)_t2932->b + hr_ix(_i2932, _t2932->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:775"); }))).ty_))));
(void)(f247_ow(hr_str(" *", 2)));
(void)(f273_lv_name(v_1861));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f262_gx0(((int64_t)((x_1859).a_))));
(void)(f247_ow(hr_str("; ", 2)));
 }
(void)(f326_gblk(((int64_t)((x_1859).b_)), res_1858, false));
(void)(f247_ow(hr_str(" }", 2)));
if ((((x_1859).c_) >= (((int32_t)0LL)))) { (void)(f247_ow(hr_str(" else { ", 8)));
if (((((*({ hrv *_t2933 = &(g679); int64_t _i2933 = (x_1859).c_; (S4*)_t2933->b + hr_ix(_i2933, _t2933->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:778"); }))).k_) == (((uint8_t)19LL)))) { (void)(f325_gif(((int64_t)((x_1859).c_)), res_1858));
 } else { (void)(f326_gblk(((int64_t)((x_1859).c_)), res_1858, false));
 }
(void)(f247_ow(hr_str(" }", 2)));
 }
}
static void f326_gblk(int64_t b_1862, int64_t res_1863, bool val_1864) {
S4 x_1865 = (*({ hrv *_t2934 = &(g679); int64_t _i2934 = b_1862; (S4*)_t2934->b + hr_ix(_i2934, _t2934->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:759"); })); 
if (((((int64_t)((x_1865).k_))) != (((int64_t)23LL)))) { if (((res_1863) >= (((int64_t)0LL)))) { (void)(f327_gtail(b_1862, res_1863));
 } else { if (val_1864) { (void)(f276_gx(b_1862));
(void)(f247_ow(hr_str(";", 1)));
 } else { (void)(f319_gstmt(b_1862));
 }
 }
return;
 }
{ int32_t _e2936 = (x_1865).n_; for (int32_t _k2936 = 0; _k2936 < _e2936; _k2936++) { int32_t i_1868 = (int32_t)_k2936; (void)(f319_gstmt(f90_kid(b_1862, ((int64_t)(i_1868)))));
 } } _bk2935:; 
if ((((x_1865).a_) >= (((int32_t)0LL)))) { int64_t tl_1869 = ((int64_t)((x_1865).a_)); 
if (((res_1863) >= (((int64_t)0LL)))) { (void)(f327_gtail(tl_1869, res_1863));
return;
 }
if (((val_1864 && ((f142_at(tl_1869)) != (g535))) && (!(f204_ends(tl_1869))))) { (void)(f276_gx(tl_1869));
(void)(f247_ow(hr_str("; ", 2)));
return;
 }
(void)(f319_gstmt(tl_1869));
 }
}
static void f327_gtail(int64_t tl_1866, int64_t res_1867) {
if ((((res_1867) >= (((int64_t)0LL))) && (!(f204_ends(tl_1866))))) { (void)(f247_ow(hr_str("_r", 2)));
(void)(f281_oi(res_1867));
(void)(f247_ow(hr_str(" = ", 3)));
if (f255_is_res(f266_fin(tl_1866))) { (void)(f256_gxo(tl_1866));
 } else { (void)(f276_gx(tl_1866));
 }
(void)(f247_ow(hr_str("; ", 2)));
return;
 }
(void)(f319_gstmt(tl_1866));
}
static void f328_gwhile(int64_t n_1870) {
S4 x_1871 = (*({ hrv *_t2937 = &(g679); int64_t _i2937 = n_1870; (S4*)_t2937->b + hr_ix(_i2937, _t2937->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:793"); })); 
int64_t l_1874 = f329_lbl_push(((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
(void)(f247_ow(hr_str("while (", 7)));
if (((f211_ax(n_1870)) == (((int64_t)1LL)))) { (void)(f247_ow(hr_str("(", 1)));
(void)(f262_gx0(((int64_t)((x_1871).a_))));
(void)(f247_ow(hr_str(") != 0", 6)));
 } else { (void)(f276_gx(((int64_t)((x_1871).a_))));
 }
(void)(f247_ow(hr_str(") { ", 4)));
(void)(f326_gblk(((int64_t)((x_1871).b_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f247_ow(hr_str(" }", 2)));
(void)(f330_lbl_pop(l_1874));
}
static int64_t f329_lbl_push(int64_t res_1872) {
int64_t l_1873 = f280_nt(); 
(void)(({ hrv *_v2938 = &(g180); int32_t _x2938 = ((int32_t)(l_1873)); int32_t *_p2938 = (int32_t*)hr_grow(_v2938, 1, sizeof _x2938); *_p2938 = _x2938; _p2938; }));
(void)(({ hrv *_v2939 = &(g181); int32_t _x2939 = ((int32_t)(res_1872)); int32_t *_p2939 = (int32_t*)hr_grow(_v2939, 1, sizeof _x2939); *_p2939 = _x2939; _p2939; }));
return l_1873;
}
static void f330_lbl_pop(int64_t l_1875) {
(void)(({ hrv *_v2940 = &(g180); if (!_v2940->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:781"); ((int32_t*)_v2940->b)[--_v2940->n]; }));
(void)(({ hrv *_v2941 = &(g181); if (!_v2941->n) hr_die("pop of an empty array", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:781"); ((int32_t*)_v2941->b)[--_v2941->n]; }));
(void)(({ hrv *_o2942 = &(g163); hr_fs(_o2942, hr_str(" _bk", 4)); hr_fi(_o2942, l_1875); hr_fs(_o2942, hr_str(":; ", 3)); }));
}
static void f331_gloop(int64_t n_1876, int64_t res_1877) {
int64_t l_1878 = f329_lbl_push(res_1877); 
(void)(f247_ow(hr_str("for (;;) { ", 11)));
(void)(f326_gblk(((int64_t)(((*({ hrv *_t2943 = &(g679); int64_t _i2943 = n_1876; (S4*)_t2943->b + hr_ix(_i2943, _t2943->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:784"); }))).a_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f247_ow(hr_str(" }", 2)));
(void)(f330_lbl_pop(l_1878));
}
static void f332_gfor(int64_t n_1879) {
S4 x_1880 = (*({ hrv *_t2944 = &(g679); int64_t _i2944 = n_1879; (S4*)_t2944->b + hr_ix(_i2944, _t2944->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:801"); })); 
int64_t v_1881 = f158_rv(n_1879); 
int64_t m_1882 = f211_ax(n_1879); 
int64_t iv_1883 = ({ int64_t _r2945; if ((((x_1880).c_) >= (((int32_t)0LL)))) { _r2945 = ((int64_t)((m_1882) >> ((((int64_t)2LL)) & 63)));  } else { _r2945 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));  } _r2945; }); 
int64_t l_1884 = f329_lbl_push(((int64_t)(0 - (uint64_t)(((int64_t)1LL))))); 
int64_t p_1885 = f280_nt(); 
int64_t et_1886 = ((int64_t)(((*({ hrv *_t2946 = &(g374); int64_t _i2946 = v_1881; (S12*)_t2946->b + hr_ix(_i2946, _t2946->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:807"); }))).ty_)); 
if (((((int64_t)((int64_t)m_1882 & (int64_t)((int64_t)3LL)))) == (((int64_t)0LL)))) { int64_t rt0_1887 = f266_fin(({ int64_t _r2947; if ((((x_1880).b_) >= (((int32_t)0LL)))) { _r2947 = ((int64_t)((x_1880).b_));  } else { _r2947 = ((int64_t)((x_1880).a_));  } _r2947; })); 
int64_t ctt_1888 = ({ int64_t _r2948; if (((((*({ hrv *_t2949 = &(g528); int64_t _i2949 = rt0_1887; (S1*)_t2949->b + hr_ix(_i2949, _t2949->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:810"); }))).k_) == (((uint8_t)3LL)))) { _r2948 = rt0_1887;  } else { _r2948 = g540;  } _r2948; }); 
(void)(f247_ow(hr_str("{ ", 2)));
(void)(f248_ct(ctt_1888));
(void)(f247_ow(hr_str(" _e", 3)));
(void)(f281_oi(p_1885));
(void)(f247_ow(hr_str(" = ", 3)));
if ((((x_1880).b_) >= (((int32_t)0LL)))) { (void)(f276_gx(((int64_t)((x_1880).b_))));
 } else { (void)(f276_gx(((int64_t)((x_1880).a_))));
 }
(void)(f247_ow(hr_str("; for (", 7)));
(void)(f248_ct(ctt_1888));
(void)(({ hrv *_o2950 = &(g163); hr_fs(_o2950, hr_str(" _k", 3)); hr_fi(_o2950, p_1885); hr_fs(_o2950, hr_str(" = ", 3)); }));
if ((((x_1880).b_) >= (((int32_t)0LL)))) { (void)(f276_gx(((int64_t)((x_1880).a_))));
 } else { (void)(f247_ow(hr_str("0", 1)));
 }
(void)(({ hrv *_o2951 = &(g163); hr_fs(_o2951, hr_str("; _k", 4)); hr_fi(_o2951, p_1885); hr_fs(_o2951, hr_str(" < _e", 5)); hr_fi(_o2951, p_1885); hr_fs(_o2951, hr_str("; _k", 4)); hr_fi(_o2951, p_1885); hr_fs(_o2951, hr_str("++) { ", 6)); }));
(void)(f248_ct(et_1886));
(void)(f247_ow(hr_str(" ", 1)));
(void)(f273_lv_name(v_1881));
(void)(({ hrv *_o2952 = &(g163); hr_fs(_o2952, hr_str(" = (", 4)); }));
(void)(f248_ct(et_1886));
(void)(({ hrv *_o2953 = &(g163); hr_fs(_o2953, hr_str(")_k", 3)); hr_fi(_o2953, p_1885); hr_fs(_o2953, hr_str("; ", 2)); }));
if (((iv_1883) >= (((int64_t)0LL)))) { (void)(f248_ct(((int64_t)(((*({ hrv *_t2954 = &(g374); int64_t _i2954 = iv_1883; (S12*)_t2954->b + hr_ix(_i2954, _t2954->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:816"); }))).ty_))));
(void)(f247_ow(hr_str(" ", 1)));
(void)(f273_lv_name(iv_1883));
(void)(f247_ow(hr_str(" = (", 4)));
(void)(f248_ct(((int64_t)(((*({ hrv *_t2955 = &(g374); int64_t _i2955 = iv_1883; (S12*)_t2955->b + hr_ix(_i2955, _t2955->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:816"); }))).ty_))));
(void)(({ hrv *_o2956 = &(g163); hr_fs(_o2956, hr_str(")_k", 3)); hr_fi(_o2956, p_1885); hr_fs(_o2956, hr_str("; ", 2)); }));
 }
(void)(f326_gblk(((int64_t)((x_1880).d_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f247_ow(hr_str(" } }", 4)));
(void)(f330_lbl_pop(l_1884));
return;
 }
int64_t a_1889 = ((int64_t)((x_1880).a_)); 
int64_t bt_1890 = f142_at(a_1889); 
int64_t d_1891 = f176_deref(bt_1890); 
int64_t e_1892 = ((int64_t)(((*({ hrv *_t2957 = &(g528); int64_t _i2957 = d_1891; (S1*)_t2957->b + hr_ix(_i2957, _t2957->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:825"); }))).a_)); 
bool byref_1893 = ((((uint16_t)((uint64_t)(x_1880).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL))); 
if (f255_is_res(d_1891)) { (void)(f247_ow(hr_str("{ hrv *_v", 9)));
(void)(f281_oi(p_1885));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f309_grecv_ptr(a_1889));
(void)(({ hrv *_o2958 = &(g163); hr_fs(_o2958, hr_str("; for (int64_t _k", 17)); hr_fi(_o2958, p_1885); hr_fs(_o2958, hr_str(" = 0; _k", 8)); hr_fi(_o2958, p_1885); hr_fs(_o2958, hr_str(" < _v", 5)); hr_fi(_o2958, p_1885); hr_fs(_o2958, hr_str("->n; _k", 7)); hr_fi(_o2958, p_1885); hr_fs(_o2958, hr_str("++) { ", 6)); }));
(void)(f248_ct(e_1892));
(void)(f247_ow(({ hsl _r2959; if (byref_1893) { _r2959 = hr_str(" *", 2);  } else { _r2959 = hr_str(" ", 1);  } _r2959; })));
(void)(f273_lv_name(v_1881));
(void)(f247_ow(({ hsl _r2960; if (byref_1893) { _r2960 = hr_str(" = &((", 6);  } else { _r2960 = hr_str(" = ((", 5);  } _r2960; })));
(void)(f248_ct(e_1892));
(void)(({ hrv *_o2961 = &(g163); hr_fs(_o2961, hr_str("*)_v", 4)); hr_fi(_o2961, p_1885); hr_fs(_o2961, hr_str("->b)[_k", 7)); hr_fi(_o2961, p_1885); hr_fs(_o2961, hr_str("]; ", 3)); }));
 } else { (void)(f247_ow(hr_str("{ hsl _v", 8)));
(void)(f281_oi(p_1885));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f279_gsl(a_1889, bt_1890));
(void)(({ hrv *_o2962 = &(g163); hr_fs(_o2962, hr_str("; for (int64_t _k", 17)); hr_fi(_o2962, p_1885); hr_fs(_o2962, hr_str(" = 0; _k", 8)); hr_fi(_o2962, p_1885); hr_fs(_o2962, hr_str(" < _v", 5)); hr_fi(_o2962, p_1885); hr_fs(_o2962, hr_str(".n; _k", 6)); hr_fi(_o2962, p_1885); hr_fs(_o2962, hr_str("++) { ", 6)); }));
(void)(f248_ct(e_1892));
(void)(f247_ow(({ hsl _r2963; if (byref_1893) { _r2963 = hr_str(" *", 2);  } else { _r2963 = hr_str(" ", 1);  } _r2963; })));
(void)(f273_lv_name(v_1881));
(void)(f247_ow(({ hsl _r2964; if (byref_1893) { _r2964 = hr_str(" = &((", 6);  } else { _r2964 = hr_str(" = ((", 5);  } _r2964; })));
(void)(f248_ct(e_1892));
(void)(({ hrv *_o2965 = &(g163); hr_fs(_o2965, hr_str("*)_v", 4)); hr_fi(_o2965, p_1885); hr_fs(_o2965, hr_str(".p)[_k", 6)); hr_fi(_o2965, p_1885); hr_fs(_o2965, hr_str("]; ", 3)); }));
 }
if (((iv_1883) >= (((int64_t)0LL)))) { (void)(f248_ct(((int64_t)(((*({ hrv *_t2966 = &(g374); int64_t _i2966 = iv_1883; (S12*)_t2966->b + hr_ix(_i2966, _t2966->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:834"); }))).ty_))));
(void)(f247_ow(hr_str(" ", 1)));
(void)(f273_lv_name(iv_1883));
(void)(f247_ow(hr_str(" = (", 4)));
(void)(f248_ct(((int64_t)(((*({ hrv *_t2967 = &(g374); int64_t _i2967 = iv_1883; (S12*)_t2967->b + hr_ix(_i2967, _t2967->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:834"); }))).ty_))));
(void)(({ hrv *_o2968 = &(g163); hr_fs(_o2968, hr_str(")_k", 3)); hr_fi(_o2968, p_1885); hr_fs(_o2968, hr_str("; ", 2)); }));
 }
(void)(f326_gblk(((int64_t)((x_1880).d_)), ((int64_t)(0 - (uint64_t)(((int64_t)1LL)))), false));
(void)(f247_ow(hr_str(" } }", 4)));
(void)(f330_lbl_pop(l_1884));
}
static void f333_gmatch(int64_t n_1894, int64_t res_1895) {
S4 x_1896 = (*({ hrv *_t2969 = &(g679); int64_t _i2969 = n_1894; (S4*)_t2969->b + hr_ix(_i2969, _t2969->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:840"); })); 
int64_t a_1897 = ((int64_t)((x_1896).a_)); 
int64_t st_1898 = f142_at(a_1897); 
int64_t d_1899 = f176_deref(st_1898); 
int64_t p_1900 = f280_nt(); 
bool isenum_1901 = ((((*({ hrv *_t2970 = &(g528); int64_t _i2970 = d_1899; (S1*)_t2970->b + hr_ix(_i2970, _t2970->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:845"); }))).k_) == (((uint8_t)6LL))); 
(void)(f247_ow(hr_str("{ ", 2)));
if (isenum_1901) { (void)(f248_ct(d_1899));
(void)(f247_ow(hr_str(" *_m", 4)));
(void)(f281_oi(p_1900));
(void)(f247_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t2971 = &(g528); int64_t _i2971 = st_1898; (S1*)_t2971->b + hr_ix(_i2971, _t2971->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:847"); }))).k_) == (((uint8_t)10LL)))) { (void)(f262_gx0(a_1897));
 } else { if (f259_is_place(a_1897)) { (void)(f247_ow(hr_str("&(", 2)));
(void)(f276_gx(a_1897));
(void)(f247_ow(hr_str(")", 1)));
 } else { int64_t k0_1902 = f260_tmp(d_1899, false); 
(void)(f247_ow(hr_str("&(", 2)));
(void)(f261_ot(k0_1902));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f256_gxo(a_1897));
(void)(f247_ow(hr_str(")", 1)));
 }
 }
(void)(f247_ow(hr_str("; ", 2)));
 } else { (void)(f248_ct(d_1899));
(void)(f247_ow(hr_str(" _m", 3)));
(void)(f281_oi(p_1900));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(a_1897));
(void)(f247_ow(hr_str("; ", 2)));
 }
bool first_1903 = true; 
{ int32_t _e2973 = (x_1896).n_; for (int32_t _k2973 = 0; _k2973 < _e2973; _k2973++) { int32_t i_1904 = (int32_t)_k2973; int64_t arm_1905 = f90_kid(n_1894, ((int64_t)(i_1904))); 
S4 ar_1906 = (*({ hrv *_t2974 = &(g679); int64_t _i2974 = arm_1905; (S4*)_t2974->b + hr_ix(_i2974, _t2974->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:852"); })); 
if ((!(first_1903))) { (void)(f247_ow(hr_str(" else ", 6)));
 }
first_1903 = false;
if (((((uint16_t)((uint64_t)(ar_1906).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)))) { (void)(f247_ow(hr_str("{ ", 2)));
(void)(f326_gblk(((int64_t)((ar_1906).b_)), res_1895, false));
(void)(f247_ow(hr_str(" }", 2)));
continue;
 }
(void)(f247_ow(hr_str("if (", 4)));
{ int32_t _e2976 = (ar_1906).n_; for (int32_t _k2976 = 0; _k2976 < _e2976; _k2976++) { int32_t j_1907 = (int32_t)_k2976; if (((j_1907) > (((int32_t)0LL)))) { (void)(f247_ow(hr_str(" || ", 4)));
 }
int64_t it_1908 = f90_kid(arm_1905, ((int64_t)(j_1907))); 
int64_t lo_1909 = ((int64_t)(((*({ hrv *_t2977 = &(g679); int64_t _i2977 = it_1908; (S4*)_t2977->b + hr_ix(_i2977, _t2977->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:860"); }))).a_)); 
if (isenum_1901) { (void)(({ hrv *_o2978 = &(g163); hr_fs(_o2978, hr_str("_m", 2)); hr_fi(_o2978, p_1900); hr_fs(_o2978, hr_str("->tag == ", 9)); hr_fi(_o2978, f158_rv(lo_1909)); }));
 } else { if (((((*({ hrv *_t2979 = &(g679); int64_t _i2979 = it_1908; (S4*)_t2979->b + hr_ix(_i2979, _t2979->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:863"); }))).b_) >= (((int32_t)0LL)))) { (void)(({ hrv *_o2980 = &(g163); hr_fs(_o2980, hr_str("(_m", 3)); hr_fi(_o2980, p_1900); hr_fs(_o2980, hr_str(" >= ", 4)); }));
(void)(f276_gx(lo_1909));
(void)(({ hrv *_o2981 = &(g163); hr_fs(_o2981, hr_str(" && _m", 6)); hr_fi(_o2981, p_1900); hr_fs(_o2981, hr_str(" < ", 3)); }));
(void)(f276_gx(((int64_t)(((*({ hrv *_t2982 = &(g679); int64_t _i2982 = it_1908; (S4*)_t2982->b + hr_ix(_i2982, _t2982->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:863"); }))).b_))));
(void)(f247_ow(hr_str(")", 1)));
 } else { if (((((f177_leaf_kind(d_1899)) == (((int64_t)0LL))) && ((((*({ hrv *_t2983 = &(g528); int64_t _i2983 = d_1899; (S1*)_t2983->b + hr_ix(_i2983, _t2983->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:864"); }))).k_) != (((uint8_t)3LL)))) && ((((*({ hrv *_t2984 = &(g528); int64_t _i2984 = d_1899; (S1*)_t2984->b + hr_ix(_i2984, _t2984->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:864"); }))).k_) != (((uint8_t)2LL))))) { (void)(f247_ow(hr_str("heq", 3)));
(void)(f281_oi(d_1899));
(void)(({ hrv *_o2985 = &(g163); hr_fs(_o2985, hr_str("(_m", 3)); hr_fi(_o2985, p_1900); hr_fs(_o2985, hr_str(", ", 2)); }));
(void)(f276_gx(lo_1909));
(void)(f247_ow(hr_str(")", 1)));
(void)(f282_gen_heq(d_1899));
 } else { (void)(({ hrv *_o2986 = &(g163); hr_fs(_o2986, hr_str("_m", 2)); hr_fi(_o2986, p_1900); hr_fs(_o2986, hr_str(" == ", 4)); }));
(void)(f276_gx(lo_1909));
 }
 }
 }
 } } _bk2975:; 
(void)(f247_ow(hr_str(") { ", 4)));
if (((((ar_1906).s_) >= (((int32_t)0LL))) && isenum_1901)) { int64_t v_1910 = f158_rv(arm_1905); 
int64_t vi_1911 = f158_rv(((int64_t)(((*({ hrv *_t2987 = &(g679); int64_t _i2987 = f90_kid(arm_1905, ((int64_t)0LL)); (S4*)_t2987->b + hr_ix(_i2987, _t2987->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:870"); }))).a_))); 
int64_t lt_1912 = ((int64_t)(((*({ hrv *_t2988 = &(g374); int64_t _i2988 = v_1910; (S12*)_t2988->b + hr_ix(_i2988, _t2988->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:871"); }))).ty_)); 
int64_t vt_1913 = f176_deref(lt_1912); 
int64_t ei_1914 = ((int64_t)(((*({ hrv *_t2989 = &(g528); int64_t _i2989 = d_1899; (S1*)_t2989->b + hr_ix(_i2989, _t2989->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:873"); }))).a_)); 
S9 vv_1915 = (*({ hrv *_t2990 = &(g534); int64_t _i2990 = ((int64_t)((int64_t)((int64_t)(((*({ hrv *_t2991 = &(g533); int64_t _i2991 = ei_1914; (S8*)_t2991->b + hr_ix(_i2991, _t2991->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:874"); }))).v0_)) + (int64_t)vi_1911)); (S9*)_t2990->b + hr_ix(_i2990, _t2990->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:874"); })); 
bool has_1916 = ((((vv_1915).si_) >= (((int32_t)0LL))) && (!(((*({ hrv *_t2992 = &(g531); int64_t _i2992 = (vv_1915).si_; (S10*)_t2992->b + hr_ix(_i2992, _t2992->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:875"); }))).zero_))); 
(void)(f248_ct(lt_1912));
(void)(f247_ow(hr_str(" ", 1)));
(void)(f273_lv_name(v_1910));
(void)(f247_ow(hr_str(" = ", 3)));
if (((((*({ hrv *_t2993 = &(g528); int64_t _i2993 = lt_1912; (S1*)_t2993->b + hr_ix(_i2993, _t2993->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:877"); }))).k_) == (((uint8_t)10LL)))) { if (has_1916) { (void)(({ hrv *_o2994 = &(g163); hr_fs(_o2994, hr_str("&_m", 3)); hr_fi(_o2994, p_1900); hr_fs(_o2994, hr_str("->u.v", 5)); hr_fi(_o2994, vi_1911); hr_fs(_o2994, hr_str("; ", 2)); }));
 } else { (void)(f247_ow(hr_str("0; ", 3)));
 }
 } else { if (has_1916) { (void)(({ hrv *_o2995 = &(g163); hr_fs(_o2995, hr_str("_m", 2)); hr_fi(_o2995, p_1900); hr_fs(_o2995, hr_str("->u.v", 5)); hr_fi(_o2995, vi_1911); hr_fs(_o2995, hr_str("; ", 2)); }));
 } else { (void)(f247_ow(hr_str("0; ", 3)));
 }
 }
 }
(void)(f326_gblk(((int64_t)((ar_1906).b_)), res_1895, false));
(void)(f247_ow(hr_str(" }", 2)));
 } } _bk2972:; 
(void)(f247_ow(hr_str(" }", 2)));
}
static void f334_geblock(int64_t n_1917, int64_t res_1918) {
int64_t l_1919 = f329_lbl_push(res_1918); 
(void)(f247_ow(hr_str("{ ", 2)));
(void)(f326_gblk(((int64_t)(((*({ hrv *_t2996 = &(g679); int64_t _i2996 = n_1917; (S4*)_t2996->b + hr_ix(_i2996, _t2996->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:789"); }))).a_)), res_1918, false));
(void)(f247_ow(hr_str(" }", 2)));
(void)(f330_lbl_pop(l_1919));
}
static void f335_gret(int64_t n_1920) {
S4 x_1921 = (*({ hrv *_t2997 = &(g679); int64_t _i2997 = n_1920; (S4*)_t2997->b + hr_ix(_i2997, _t2997->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:964"); })); 
if (((f211_ax(n_1920)) >= (((int64_t)0LL)))) { (void)(f274_gerr(n_1920, hr_str("return from inside a block is not supported by the self-hosted compiler yet", 75)));
return;
 }
if ((((x_1921).s_) >= (((int32_t)0LL)))) { (void)(f274_gerr(n_1920, hr_str("return from an enclosing function is not supported by the self-hosted compiler yet", 82)));
return;
 }
if ((((x_1921).n_) == (((int32_t)0LL)))) { (void)(f247_ow(hr_str("return;", 7)));
return;
 }
int64_t f_1922 = f214_ret_fn(); 
int64_t rt_1923 = ((int64_t)(((*({ hrv *_t2998 = &(g373); int64_t _i2998 = f_1922; (S6*)_t2998->b + hr_ix(_i2998, _t2998->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:969"); }))).ret_)); 
if ((((x_1921).n_) > (((int32_t)1LL)))) { (void)(f247_ow(hr_str("return (", 8)));
(void)(f248_ct(rt_1923));
(void)(f247_ow(hr_str("){ ", 3)));
{ int32_t _e3000 = (x_1921).n_; for (int32_t _k3000 = 0; _k3000 < _e3000; _k3000++) { int32_t i_1924 = (int32_t)_k3000; if (((i_1924) > (((int32_t)0LL)))) { (void)(f247_ow(hr_str(", ", 2)));
 }
int64_t c_1925 = f90_kid(n_1920, ((int64_t)(i_1924))); 
if (f255_is_res(f266_fin(c_1925))) { (void)(f336_gmove(c_1925));
 } else { (void)(f276_gx(c_1925));
 }
 } } _bk2999:; 
(void)(f247_ow(hr_str(" };", 3)));
return;
 }
int64_t c_1931 = f90_kid(n_1920, ((int64_t)0LL)); 
(void)(f247_ow(hr_str("return ", 7)));
if (f255_is_res(rt_1923)) { (void)(f336_gmove(c_1931));
 } else { (void)(f276_gx(c_1931));
 }
(void)(f247_ow(hr_str(";", 1)));
}
static void f336_gmove(int64_t c_1926) {
if (f337_movable_local(c_1926)) { int64_t v_1929 = f158_rv(c_1926); 
int64_t p_1930 = f280_nt(); 
(void)(f247_ow(hr_str("({ hrv _mv", 10)));
(void)(f281_oi(p_1930));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f273_lv_name(v_1929));
(void)(f247_ow(hr_str("; ", 2)));
(void)(f273_lv_name(v_1929));
(void)(f247_ow(hr_str(".b = 0; ", 8)));
(void)(f273_lv_name(v_1929));
(void)(({ hrv *_o3001 = &(g163); hr_fs(_o3001, hr_str(".n = 0; _mv", 11)); hr_fi(_o3001, p_1930); hr_fs(_o3001, hr_str("; })", 4)); }));
return;
 }
(void)(f256_gxo(c_1926));
}
static bool f337_movable_local(int64_t c_1927) {
if ((((((*({ hrv *_t3002 = &(g679); int64_t _i3002 = c_1927; (S4*)_t3002->b + hr_ix(_i3002, _t3002->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:958"); }))).k_) != (((uint8_t)8LL))) || ((f157_rk(c_1927)) != (((int64_t)1LL))))) { return false;
 }
int64_t v_1928 = f158_rv(c_1927); 
return (((((((int64_t)(((*({ hrv *_t3003 = &(g374); int64_t _i3003 = v_1928; (S12*)_t3003->b + hr_ix(_i3003, _t3003->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:958"); }))).cfn_))) == (g179)) && (!(f272_lv_isptr(v_1928)))) && ((((*({ hrv *_t3004 = &(g528); int64_t _i3004 = ((*({ hrv *_t3005 = &(g374); int64_t _i3005 = v_1928; (S12*)_t3005->b + hr_ix(_i3005, _t3005->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:958"); }))).ty_; (S1*)_t3004->b + hr_ix(_i3004, _t3004->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:958"); }))).k_) != (((uint8_t)10LL)))) && (((f149_cv(c_1927)) < (((int64_t)0LL))) || ((f149_cv(c_1927)) == (f142_at(c_1927)))));
}
static void f338_gbreak(int64_t n_1932) {
S4 x_1933 = (*({ hrv *_t3006 = &(g679); int64_t _i3006 = n_1932; (S4*)_t3006->b + hr_ix(_i3006, _t3006->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:975"); })); 
if ((((g180).n) == (((int64_t)0LL)))) { (void)(f274_gerr(n_1932, hr_str("break outside a loop", 20)));
return;
 }
int64_t l_1934 = ((int64_t)((*({ hrv *_t3007 = &(g180); int64_t _i3007 = ((int64_t)((int64_t)(g180).n - (int64_t)((int64_t)1LL))); (int32_t*)_t3007->b + hr_ix(_i3007, _t3007->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:977"); })))); 
int64_t r_1935 = ((int64_t)((*({ hrv *_t3008 = &(g181); int64_t _i3008 = ((int64_t)((int64_t)(g181).n - (int64_t)((int64_t)1LL))); (int32_t*)_t3008->b + hr_ix(_i3008, _t3008->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:978"); })))); 
(void)(f247_ow(hr_str("{ ", 2)));
if ((((x_1933).a_) >= (((int32_t)0LL)))) { if (((r_1935) >= (((int64_t)0LL)))) { (void)(f247_ow(hr_str("_r", 2)));
(void)(f281_oi(r_1935));
(void)(f247_ow(hr_str(" = ", 3)));
(void)(f276_gx(((int64_t)((x_1933).a_))));
(void)(f247_ow(hr_str("; ", 2)));
 } else { (void)(f247_ow(hr_str("(void)(", 7)));
(void)(f276_gx(((int64_t)((x_1933).a_))));
(void)(f247_ow(hr_str("); ", 3)));
 }
 }
(void)(({ hrv *_o3009 = &(g163); hr_fs(_o3009, hr_str("goto _bk", 8)); hr_fi(_o3009, l_1934); hr_fs(_o3009, hr_str("; }", 3)); }));
}
static bool f339_owned(int64_t n_1936) {
return (f255_is_res(f266_fin(n_1936)) && (!(f259_is_place(n_1936))));
}
static bool f340_is_ext(int64_t i_1940) {
return ((((uint16_t)((uint64_t)((*({ hrv *_t3010 = &(g679); int64_t _i3010 = ((*({ hrv *_t3011 = &(g373); int64_t _i3011 = i_1940; (S6*)_t3011->b + hr_ix(_i3011, _t3011->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:555"); }))).node_; (S4*)_t3010->b + hr_ix(_i3010, _t3010->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:555"); }))).fl_ & (uint64_t)((uint16_t)1LL)))) != (((uint16_t)0LL)));
}
static void f341_ext_name(int64_t i_1941) {
int64_t node_1942 = ((int64_t)(((*({ hrv *_t3012 = &(g373); int64_t _i3012 = i_1941; (S6*)_t3012->b + hr_ix(_i3012, _t3012->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:550"); }))).node_)); 
int64_t x_1943 = ((int64_t)(((*({ hrv *_t3013 = &(g679); int64_t _i3013 = node_1942; (S4*)_t3013->b + hr_ix(_i3013, _t3013->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:551"); }))).e_)); 
if ((((x_1943) >= (((int64_t)0LL))) && ((((*({ hrv *_t3014 = &(g679); int64_t _i3014 = x_1943; (S4*)_t3014->b + hr_ix(_i3014, _t3014->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:552"); }))).a_) >= (((int32_t)0LL))))) { hsl s_1944 = f267_tok_str(((int64_t)(((*({ hrv *_t3015 = &(g679); int64_t _i3015 = x_1943; (S4*)_t3015->b + hr_ix(_i3015, _t3015->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:552"); }))).a_))); 
if (((((((s_1944).n) > (((int64_t)3LL))) && (((*({ hsl _t3016 = s_1944; int64_t _i3016 = ((int64_t)0LL); (uint8_t*)_t3016.p + hr_ix(_i3016, _t3016.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:552"); }))) == (((uint8_t)103LL)))) && (((*({ hsl _t3017 = s_1944; int64_t _i3017 = ((int64_t)1LL); (uint8_t*)_t3017.p + hr_ix(_i3017, _t3017.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:552"); }))) == (((uint8_t)115LL)))) && (((*({ hsl _t3018 = s_1944; int64_t _i3018 = ((int64_t)2LL); (uint8_t*)_t3018.p + hr_ix(_i3018, _t3018.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:552"); }))) == (((uint8_t)95LL))))) { (void)(f247_ow(hr_str("hr_", 3)));
(void)(f247_ow(({ hsl _t3019 = s_1944; int64_t _l3019 = ((int64_t)3LL), _h3019 = _t3019.n; if (_l3019 < 0 || _h3019 < _l3019 || _h3019 > _t3019.n) hr_slerr(_l3019, _h3019, _t3019.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:552"); (hsl){ _t3019.p + _l3019 * (int64_t)sizeof(uint8_t), _h3019 - _l3019 }; })));
return;
 }
(void)(f247_ow(s_1944));
return;
 }
(void)(f247_ow(f10_nm(((int64_t)(((*({ hrv *_t3020 = &(g679); int64_t _i3020 = node_1942; (S4*)_t3020->b + hr_ix(_i3020, _t3020->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:553"); }))).s_)))));
}
static void f342_fn_cname(int64_t i_1945) {
(void)(({ hrv *_o3021 = &(g163); hr_fs(_o3021, hr_str("f", 1)); hr_fi(_o3021, i_1945); hr_fs(_o3021, hr_str("_", 1)); }));
int64_t s_1946 = ((int64_t)(((*({ hrv *_t3022 = &(g373); int64_t _i3022 = i_1945; (S6*)_t3022->b + hr_ix(_i3022, _t3022->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:548"); }))).name_)); 
if (((s_1946) >= (((int64_t)0LL)))) { { hsl _v3024 = f10_nm(s_1946); for (int64_t _k3024 = 0; _k3024 < _v3024.n; _k3024++) { uint8_t c_1947 = ((uint8_t*)_v3024.p)[_k3024]; (void)(({ hrv *_v3025 = &(g163); uint8_t _x3025 = ({ uint8_t _r3026; if (((c_1947) == (((uint8_t)58LL)))) { _r3026 = ((uint8_t)95LL);  } else { _r3026 = c_1947;  } _r3026; }); uint8_t *_p3025 = (uint8_t*)hr_grow(_v3025, 1, sizeof _x3025); *_p3025 = _x3025; _p3025; }));
 } } _bk3023:; 
 }
}
static void f343_gcall_args(int64_t n_1948, int64_t inst_1949, int64_t recv_1950) {
S4 x_1951 = (*({ hrv *_t3027 = &(g679); int64_t _i3027 = n_1948; (S4*)_t3027->b + hr_ix(_i3027, _t3027->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:557"); })); 
int64_t np_1952 = ((int64_t)(((*({ hrv *_t3028 = &(g679); int64_t _i3028 = ((*({ hrv *_t3029 = &(g373); int64_t _i3029 = inst_1949; (S6*)_t3029->b + hr_ix(_i3029, _t3029->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:558"); }))).node_; (S4*)_t3028->b + hr_ix(_i3028, _t3028->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:558"); }))).n_)); 
int64_t na_1953 = ((int64_t)((int64_t)((int64_t)((x_1951).n_)) + (int64_t)({ int64_t _r3030; if (((recv_1950) >= (((int64_t)0LL)))) { _r3030 = ((int64_t)1LL);  } else { _r3030 = ((int64_t)0LL);  } _r3030; }))); 
bool first_1954 = true; 
{ int64_t _e3032 = np_1952; for (int64_t _k3032 = 0; _k3032 < _e3032; _k3032++) { int64_t j_1955 = (int64_t)_k3032; int64_t pt_1956 = f203_ptype_of(inst_1949, j_1955); 
if ((!(first_1954))) { (void)(f247_ow(hr_str(", ", 2)));
 }
first_1954 = false;
if (((j_1955) >= (na_1953))) { int64_t p_1957 = f90_kid(((int64_t)(((*({ hrv *_t3033 = &(g373); int64_t _i3033 = inst_1949; (S6*)_t3033->b + hr_ix(_i3033, _t3033->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:566"); }))).node_)), j_1955); 
int64_t sa_1958 = g384; 
g384 = inst_1949;
(void)(f276_gx(((int64_t)(((*({ hrv *_t3034 = &(g679); int64_t _i3034 = p_1957; (S4*)_t3034->b + hr_ix(_i3034, _t3034->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:567"); }))).b_))));
g384 = sa_1958;
continue;
 }
int64_t c_1959 = ({ int64_t _r3035; if (((recv_1950) >= (((int64_t)0LL)))) { _r3035 = ({ int64_t _r3036; if (((j_1955) == (((int64_t)0LL)))) { _r3036 = recv_1950;  } else { _r3036 = f90_kid(n_1948, ((int64_t)((int64_t)j_1955 - (int64_t)((int64_t)1LL))));  } _r3036; });  } else { _r3035 = f90_kid(n_1948, j_1955);  } _r3035; }); 
int64_t ct0_1960 = f266_fin(c_1959); 
if ((((((*({ hrv *_t3037 = &(g528); int64_t _i3037 = pt_1956; (S1*)_t3037->b + hr_ix(_i3037, _t3037->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:572"); }))).k_) == (((uint8_t)10LL))) && ((((*({ hrv *_t3038 = &(g528); int64_t _i3038 = pt_1956; (S1*)_t3038->b + hr_ix(_i3038, _t3038->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:572"); }))).c_) < (((int32_t)0LL))))) { if ((((((*({ hrv *_t3039 = &(g528); int64_t _i3039 = ct0_1960; (S1*)_t3039->b + hr_ix(_i3039, _t3039->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:573"); }))).k_) == (((uint8_t)10LL))) || ((((*({ hrv *_t3040 = &(g528); int64_t _i3040 = ct0_1960; (S1*)_t3040->b + hr_ix(_i3040, _t3040->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:573"); }))).k_) == (((uint8_t)11LL))))) { (void)(f276_gx(c_1959));
 } else { (void)(f311_gaddr(c_1959));
 }
continue;
 }
if (f255_is_res(pt_1956)) { (void)(f256_gxo(c_1959));
continue;
 }
if (((((*({ hrv *_t3041 = &(g528); int64_t _i3041 = pt_1956; (S1*)_t3041->b + hr_ix(_i3041, _t3041->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:577"); }))).k_) == (((uint8_t)9LL)))) { (void)(f278_gas(c_1959));
continue;
 }
(void)(f276_gx(c_1959));
 } } _bk3031:; 
{ hrv *_v3043 = &(g376); for (int64_t _k3043 = 0; _k3043 < _v3043->n; _k3043++) { S13 cp_1961 = ((S13*)_v3043->b)[_k3043]; if (((((int64_t)((cp_1961).inst_))) == (inst_1949))) { if ((!(first_1954))) { (void)(f247_ow(hr_str(", ", 2)));
 }
first_1954 = false;
(void)(f344_lv_addr(((int64_t)((cp_1961).lv_))));
 }
 } } _bk3042:; 
}
static void f344_lv_addr(int64_t v_1962) {
if (((((int64_t)(((*({ hrv *_t3044 = &(g374); int64_t _i3044 = v_1962; (S12*)_t3044->b + hr_ix(_i3044, _t3044->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:119"); }))).cfn_))) != (g179))) { (void)(({ hrv *_o3045 = &(g163); hr_fs(_o3045, hr_str("c", 1)); hr_fi(_o3045, v_1962); }));
return;
 }
(void)(f247_ow(hr_str("&", 1)));
(void)(f273_lv_name(v_1962));
}
static void f345_gen_fn(int64_t i_1977) {
int64_t node_1978 = ((int64_t)(((*({ hrv *_t3046 = &(g373); int64_t _i3046 = i_1977; (S6*)_t3046->b + hr_ix(_i3046, _t3046->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1041"); }))).node_)); 
g384 = i_1977;
g179 = i_1977;
(void)(({ hrv *_v3047 = &(g180); _v3047->n = 0; }));
(void)(({ hrv *_v3048 = &(g181); _v3048->n = 0; }));
int64_t s0_1979 = (g163).n; 
(void)(f346_gsig(i_1977));
(void)(({ hrv *_v3049 = &(g166); hsl _s3049 = ({ hsl _t3050 = hr_sl(g163); int64_t _l3050 = s0_1979, _h3050 = _t3050.n; if (_l3050 < 0 || _h3050 < _l3050 || _h3050 > _t3050.n) hr_slerr(_l3050, _h3050, _t3050.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1046"); (hsl){ _t3050.p + _l3050 * (int64_t)sizeof(uint8_t), _h3050 - _l3050 }; }); hr_append(_v3049, _s3049.p, _s3049.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v3051 = &(g166); hsl _s3051 = hr_str(";\012", 2); hr_append(_v3051, _s3051.p, _s3051.n, sizeof(uint8_t)); }));
(void)(f247_ow(hr_str(" {\012", 3)));
{ int32_t _e3053 = ((*({ hrv *_t3054 = &(g679); int64_t _i3054 = node_1978; (S4*)_t3054->b + hr_ix(_i3054, _t3054->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1048"); }))).n_; for (int32_t _k3053 = 0; _k3053 < _e3053; _k3053++) { int32_t j_1991 = (int32_t)_k3053; int64_t p_1992 = f90_kid(node_1978, ((int64_t)(j_1991))); 
int64_t v_1993 = f158_rv(p_1992); 
if (f255_is_res(f203_ptype_of(i_1977, ((int64_t)(j_1991))))) { (void)(f247_ow(hr_str("hrv ", 4)));
(void)(f273_lv_name(v_1993));
(void)(f247_ow(hr_str(" __attribute__((cleanup(hr_rdrop))) = ", 38)));
(void)(f273_lv_name(v_1993));
(void)(f247_ow(hr_str("_in;\012", 5)));
 }
 } } _bk3052:; 
int64_t body_1994 = ((int64_t)(((*({ hrv *_t3055 = &(g679); int64_t _i3055 = node_1978; (S4*)_t3055->b + hr_ix(_i3055, _t3055->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1049"); }))).c_)); 
int64_t rt_1995 = ((int64_t)(((*({ hrv *_t3056 = &(g373); int64_t _i3056 = i_1977; (S6*)_t3056->b + hr_ix(_i3056, _t3056->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1050"); }))).ret_)); 
int64_t tl_1996 = ((int64_t)(((*({ hrv *_t3057 = &(g679); int64_t _i3057 = body_1994; (S4*)_t3057->b + hr_ix(_i3057, _t3057->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1051"); }))).a_)); 
{ int32_t _e3059 = ((*({ hrv *_t3060 = &(g679); int64_t _i3060 = body_1994; (S4*)_t3060->b + hr_ix(_i3060, _t3060->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1052"); }))).n_; for (int32_t _k3059 = 0; _k3059 < _e3059; _k3059++) { int32_t q_1997 = (int32_t)_k3059; (void)(f319_gstmt(f90_kid(body_1994, ((int64_t)(q_1997)))));
 } } _bk3058:; 
if (((tl_1996) >= (((int64_t)0LL)))) { if ((((((rt_1995) >= (((int64_t)0LL))) && ((rt_1995) != (g535))) && ((f142_at(tl_1996)) != (g535))) && (!(f204_ends(tl_1996))))) { int64_t sp_1998 = (g163).n; 
int64_t td_1999 = (g176).n; 
if ((((((*({ hrv *_t3061 = &(g528); int64_t _i3061 = rt_1995; (S1*)_t3061->b + hr_ix(_i3061, _t3061->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1056"); }))).k_) == (((uint8_t)14LL))) && ((((*({ hrv *_t3062 = &(g679); int64_t _i3062 = tl_1996; (S4*)_t3062->b + hr_ix(_i3062, _t3062->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1056"); }))).k_) == (((uint8_t)11LL))))) { (void)(f247_ow(hr_str("return ", 7)));
(void)(f276_gx(tl_1996));
(void)(f247_ow(hr_str(";\012", 2)));
 } else { (void)(f247_ow(hr_str("return ", 7)));
if (f255_is_res(rt_1995)) { (void)(f336_gmove(tl_1996));
 } else { (void)(f276_gx(tl_1996));
 }
(void)(f247_ow(hr_str(";\012", 2)));
 }
if ((((g176).n) > (td_1999))) { (void)(({ hrv *_v3063 = &(g177); _v3063->n = 0; }));
(void)(({ hrv *_v3064 = &(g177); hsl _s3064 = ({ hsl _t3065 = hr_sl(g163); int64_t _l3065 = sp_1998, _h3065 = _t3065.n; if (_l3065 < 0 || _h3065 < _l3065 || _h3065 > _t3065.n) hr_slerr(_l3065, _h3065, _t3065.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1058"); (hsl){ _t3065.p + _l3065 * (int64_t)sizeof(uint8_t), _h3065 - _l3065 }; }); hr_append(_v3064, _s3064.p, _s3064.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v3066 = &(g163); int64_t _k3066 = sp_1998; if (_k3066 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1058"); hr_resize(_v3066, _k3066, sizeof(uint8_t)); }));
(void)(f247_ow(hr_str("{ ", 2)));
(void)(({ hrv *_v3067 = &(g163); hsl _s3067 = ({ hsl _t3068 = hr_sl(g176); int64_t _l3068 = td_1999, _h3068 = _t3068.n; if (_l3068 < 0 || _h3068 < _l3068 || _h3068 > _t3068.n) hr_slerr(_l3068, _h3068, _t3068.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1058"); (hsl){ _t3068.p + _l3068 * (int64_t)sizeof(uint8_t), _h3068 - _l3068 }; }); hr_append(_v3067, _s3067.p, _s3067.n, sizeof(uint8_t)); }));
(void)(({ hrv *_v3069 = &(g176); int64_t _k3069 = td_1999; if (_k3069 < 0) hr_die("resize to a negative length", "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1058"); hr_resize(_v3069, _k3069, sizeof(uint8_t)); }));
(void)(({ hrv *_v3070 = &(g163); hsl _s3070 = ({ hsl _t3071 = hr_sl(g177); int64_t _l3071 = 0, _h3071 = _t3071.n; if (_l3071 < 0 || _h3071 < _l3071 || _h3071 > _t3071.n) hr_slerr(_l3071, _h3071, _t3071.n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1058"); (hsl){ _t3071.p + _l3071 * (int64_t)sizeof(uint8_t), _h3071 - _l3071 }; }); hr_append(_v3070, _s3070.p, _s3070.n, sizeof(uint8_t)); }));
(void)(f247_ow(hr_str("}\012", 2)));
 }
 } else { (void)(f319_gstmt(tl_1996));
 }
 }
(void)(f247_ow(hr_str("}\012", 2)));
}
static void f346_gsig(int64_t i_1980) {
int64_t rt_1981 = ((int64_t)(((*({ hrv *_t3072 = &(g373); int64_t _i3072 = i_1980; (S6*)_t3072->b + hr_ix(_i3072, _t3072->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1020"); }))).ret_)); 
(void)(f247_ow(hr_str("static ", 7)));
if (((rt_1981) < (((int64_t)0LL)))) { (void)(f247_ow(hr_str("void", 4)));
 } else { (void)(f248_ct(rt_1981));
 }
(void)(f247_ow(hr_str(" ", 1)));
(void)(f342_fn_cname(i_1980));
(void)(f247_ow(hr_str("(", 1)));
int64_t node_1982 = ((int64_t)(((*({ hrv *_t3073 = &(g373); int64_t _i3073 = i_1980; (S6*)_t3073->b + hr_ix(_i3073, _t3073->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1024"); }))).node_)); 
bool first_1983 = true; 
int64_t sa_1984 = g384; 
g384 = i_1980;
{ int32_t _e3075 = ((*({ hrv *_t3076 = &(g679); int64_t _i3076 = node_1982; (S4*)_t3076->b + hr_ix(_i3076, _t3076->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1027"); }))).n_; for (int32_t _k3075 = 0; _k3075 < _e3075; _k3075++) { int32_t j_1985 = (int32_t)_k3075; int64_t p_1986 = f90_kid(node_1982, ((int64_t)(j_1985))); 
int64_t v_1987 = f158_rv(p_1986); 
if ((!(first_1983))) { (void)(f247_ow(hr_str(", ", 2)));
 }
first_1983 = false;
int64_t t_1988 = f203_ptype_of(i_1980, ((int64_t)(j_1985))); 
(void)(f248_ct(t_1988));
(void)(f247_ow(hr_str(" ", 1)));
(void)(f273_lv_name(v_1987));
if (f255_is_res(t_1988)) { (void)(f247_ow(hr_str("_in", 3)));
 }
 } } _bk3074:; 
g384 = sa_1984;
{ hrv *_v3078 = &(g376); for (int64_t _k3078 = 0; _k3078 < _v3078->n; _k3078++) { S13 cp_1989 = ((S13*)_v3078->b)[_k3078]; if (((((int64_t)((cp_1989).inst_))) == (i_1980))) { if ((!(first_1983))) { (void)(f247_ow(hr_str(", ", 2)));
 }
first_1983 = false;
int64_t v_1990 = ((int64_t)((cp_1989).lv_)); 
(void)(f248_ct(((int64_t)(((*({ hrv *_t3079 = &(g374); int64_t _i3079 = v_1990; (S12*)_t3079->b + hr_ix(_i3079, _t3079->n, "/home/anmire/ai/amni-lang/helium-fix/hc/gen.amni:1036"); }))).ty_))));
(void)(f247_ow(({ hsl _r3080; if (f272_lv_isptr(v_1990)) { _r3080 = hr_str(" **c", 4);  } else { _r3080 = hr_str(" *c", 3);  } _r3080; })));
(void)(f281_oi(v_1990));
 }
 } } _bk3077:; 
if (first_1983) { (void)(f247_ow(hr_str("void", 4)));
 }
(void)(f247_ow(hr_str(")", 1)));
}
static void hr_init_globals(void) {
g829 = ({ A25 _t1; _t1.e[0] = hr_str("import", 6); _t1.e[1] = hr_str("namespace", 9); _t1.e[2] = hr_str("struct", 6); _t1.e[3] = hr_str("enum", 4); _t1.e[4] = hr_str("type", 4); _t1.e[5] = hr_str("fn", 2); _t1.e[6] = hr_str("thread_fn", 9); _t1.e[7] = hr_str("export", 6); _t1.e[8] = hr_str("simd", 4); _t1.e[9] = hr_str("recursive", 9); _t1.e[10] = hr_str("let", 3); _t1.e[11] = hr_str("var", 3); _t1.e[12] = hr_str("extern", 6); _t1.e[13] = hr_str("const", 5); _t1.e[14] = hr_str("pad", 3); _t1.e[15] = hr_str("reusable", 8); _t1.e[16] = hr_str("if", 2); _t1.e[17] = hr_str("else", 4); _t1.e[18] = hr_str("while", 5); _t1.e[19] = hr_str("for", 3); _t1.e[20] = hr_str("in", 2); _t1.e[21] = hr_str("loop", 4); _t1.e[22] = hr_str("block", 5); _t1.e[23] = hr_str("guard", 5); _t1.e[24] = hr_str("match", 5); _t1.e[25] = hr_str("return", 6); _t1.e[26] = hr_str("break", 5); _t1.e[27] = hr_str("continue", 8); _t1.e[28] = hr_str("as", 2); _t1.e[29] = hr_str("true", 4); _t1.e[30] = hr_str("false", 5); _t1.e[31] = hr_str("null", 4); _t1.e[32] = hr_str("self", 4); _t1.e[33] = hr_str("bool", 4); _t1.e[34] = hr_str("varint", 6); _t1.e[35] = hr_str("i8", 2); _t1.e[36] = hr_str("i16", 3); _t1.e[37] = hr_str("i32", 3); _t1.e[38] = hr_str("i64", 3); _t1.e[39] = hr_str("u8", 2); _t1.e[40] = hr_str("u16", 3); _t1.e[41] = hr_str("u32", 3); _t1.e[42] = hr_str("u64", 3); _t1.e[43] = hr_str("f32", 3); _t1.e[44] = hr_str("f64", 3); _t1.e[45] = hr_str("int", 3); _t1.e[46] = hr_str("uint", 4); _t1.e[47] = hr_str("byte", 4); _t1.e[48] = hr_str("real", 4); _t1; });
g696 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g697 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g698 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g699 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g700 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g701 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g702 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g703 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g704 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g705 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g692 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g691 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g386 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g384 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g385 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g179 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g183 = ({ A62 _t2; _t2.e[0] = hr_str("int8_t", 6); _t2.e[1] = hr_str("int16_t", 7); _t2.e[2] = hr_str("int32_t", 7); _t2.e[3] = hr_str("int64_t", 7); _t2.e[4] = hr_str("uint8_t", 7); _t2.e[5] = hr_str("uint16_t", 8); _t2.e[6] = hr_str("uint32_t", 8); _t2.e[7] = hr_str("uint64_t", 8); _t2; });
g114 = ({ A98 _t3; _t3.e[0] = ((double)1e0); _t3.e[1] = ((double)1e1); _t3.e[2] = ((double)1e2); _t3.e[3] = ((double)1e3); _t3.e[4] = ((double)1e4); _t3.e[5] = ((double)1e5); _t3.e[6] = ((double)1e6); _t3.e[7] = ((double)1e7); _t3.e[8] = ((double)1e8); _t3.e[9] = ((double)1e9); _t3.e[10] = ((double)1e10); _t3.e[11] = ((double)1e11); _t3.e[12] = ((double)1e12); _t3.e[13] = ((double)1e13); _t3.e[14] = ((double)1e14); _t3.e[15] = ((double)1e15); _t3.e[16] = ((double)1e16); _t3.e[17] = ((double)1e17); _t3.e[18] = ((double)1e18); _t3.e[19] = ((double)1e19); _t3.e[20] = ((double)1e20); _t3.e[21] = ((double)1e21); _t3.e[22] = ((double)1e22); _t3; });
g154 = ((hrv){0});
g286 = ((int64_t)1LL);
g287 = ((int64_t)2LL);
g288 = ((int64_t)3LL);
g289 = ((int64_t)4LL);
g290 = ((int64_t)5LL);
g291 = ((int64_t)6LL);
g292 = ((int64_t)7LL);
g293 = ((int64_t)8LL);
g294 = ((int64_t)9LL);
g295 = ((int64_t)20LL);
g296 = ((int64_t)21LL);
g297 = ((int64_t)22LL);
g298 = ((int64_t)23LL);
g299 = ((int64_t)24LL);
g300 = ((int64_t)25LL);
g301 = ((int64_t)26LL);
g302 = ((int64_t)27LL);
g303 = ((int64_t)30LL);
g304 = ((int64_t)31LL);
g305 = ((int64_t)32LL);
g306 = ((int64_t)33LL);
g349 = ((int64_t)0LL);
g350 = ((int64_t)1LL);
g351 = ((int64_t)2LL);
g352 = ((int64_t)3LL);
g353 = ((int64_t)4LL);
g354 = ((int64_t)5LL);
g355 = ((int64_t)6LL);
g356 = ((int64_t)7LL);
g357 = ((int64_t)8LL);
g358 = ((int64_t)9LL);
g359 = ((int64_t)10LL);
g360 = ((int64_t)11LL);
g361 = ((int64_t)12LL);
g362 = ((int64_t)13LL);
g363 = ((int64_t)1LL);
g364 = ((int64_t)2LL);
g365 = ((int64_t)4LL);
g366 = ((int64_t)8LL);
g367 = ((int64_t)16LL);
g368 = ((int64_t)32LL);
g369 = ((int64_t)2LL);
g383 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g389 = ((int64_t)(0 - (uint64_t)(((int64_t)1LL))));
g459 = ((int64_t)1LL);
g460 = ((int64_t)2LL);
g461 = ((int64_t)3LL);
g462 = ((int64_t)4LL);
g463 = ((int64_t)5LL);
g498 = ((int64_t)0LL);
g499 = ((int64_t)1LL);
g500 = ((int64_t)2LL);
g501 = ((int64_t)3LL);
g502 = ((int64_t)4LL);
g503 = ((int64_t)5LL);
g504 = ((int64_t)6LL);
g505 = ((int64_t)7LL);
g506 = ((int64_t)8LL);
g507 = ((int64_t)9LL);
g508 = ((int64_t)10LL);
g509 = ((int64_t)11LL);
g510 = ((int64_t)12LL);
g511 = ((int64_t)13LL);
g512 = ((int64_t)14LL);
g513 = ((int64_t)15LL);
g514 = ((int64_t)16LL);
g515 = ((int64_t)17LL);
g516 = ((int64_t)18LL);
g517 = ((int64_t)19LL);
g518 = ((int64_t)1LL);
g519 = ((int64_t)2LL);
g520 = ((int64_t)0LL);
g521 = ((int64_t)1LL);
g522 = ((int64_t)2LL);
g601 = ((int64_t)1LL);
g602 = ((int64_t)2LL);
g603 = ((int64_t)3LL);
g604 = ((int64_t)4LL);
g605 = ((int64_t)5LL);
g606 = ((int64_t)6LL);
g607 = ((int64_t)7LL);
g608 = ((int64_t)8LL);
g609 = ((int64_t)9LL);
g610 = ((int64_t)10LL);
g611 = ((int64_t)11LL);
g612 = ((int64_t)12LL);
g613 = ((int64_t)13LL);
g614 = ((int64_t)14LL);
g615 = ((int64_t)15LL);
g616 = ((int64_t)16LL);
g617 = ((int64_t)17LL);
g618 = ((int64_t)18LL);
g619 = ((int64_t)19LL);
g620 = ((int64_t)20LL);
g621 = ((int64_t)21LL);
g622 = ((int64_t)22LL);
g623 = ((int64_t)23LL);
g624 = ((int64_t)24LL);
g625 = ((int64_t)25LL);
g626 = ((int64_t)26LL);
g627 = ((int64_t)27LL);
g628 = ((int64_t)28LL);
g629 = ((int64_t)29LL);
g630 = ((int64_t)30LL);
g631 = ((int64_t)31LL);
g632 = ((int64_t)32LL);
g633 = ((int64_t)33LL);
g634 = ((int64_t)34LL);
g635 = ((int64_t)35LL);
g636 = ((int64_t)36LL);
g637 = ((int64_t)37LL);
g638 = ((int64_t)40LL);
g639 = ((int64_t)41LL);
g640 = ((int64_t)42LL);
g641 = ((int64_t)43LL);
g642 = ((int64_t)44LL);
g643 = ((int64_t)45LL);
g644 = ((int64_t)46LL);
g645 = ((int64_t)47LL);
g646 = ((int64_t)48LL);
g647 = ((int64_t)50LL);
g648 = ((int64_t)51LL);
g649 = ((int64_t)52LL);
g650 = ((int64_t)53LL);
g651 = ((int64_t)54LL);
g652 = ((int64_t)55LL);
g653 = ((int64_t)56LL);
g654 = ((int64_t)57LL);
g655 = ((int64_t)58LL);
g656 = ((int64_t)1LL);
g657 = ((int64_t)2LL);
g658 = ((int64_t)3LL);
g659 = ((int64_t)4LL);
g660 = ((int64_t)5LL);
g661 = ((int64_t)1LL);
g662 = ((int64_t)2LL);
g663 = ((int64_t)4LL);
g664 = ((int64_t)8LL);
g665 = ((int64_t)16LL);
g666 = ((int64_t)32LL);
g667 = ((int64_t)64LL);
g668 = ((int64_t)128LL);
g669 = ((int64_t)256LL);
g670 = ((int64_t)512LL);
g671 = ((int64_t)1LL);
g672 = ((int64_t)2LL);
g673 = ((int64_t)4LL);
g674 = ((int64_t)8LL);
g675 = ((int64_t)16LL);
g676 = ((int64_t)32LL);
g677 = ((int64_t)64LL);
g772 = ((int64_t)0LL);
g773 = ((int64_t)1LL);
g774 = ((int64_t)2LL);
g775 = ((int64_t)3LL);
g776 = ((int64_t)4LL);
g777 = ((int64_t)5LL);
g778 = ((int64_t)6LL);
g779 = ((int64_t)7LL);
g780 = ((int64_t)8LL);
g781 = ((int64_t)9LL);
g782 = ((int64_t)10LL);
g783 = ((int64_t)11LL);
g784 = ((int64_t)12LL);
g785 = ((int64_t)13LL);
g786 = ((int64_t)14LL);
g787 = ((int64_t)15LL);
g788 = ((int64_t)16LL);
g789 = ((int64_t)17LL);
g790 = ((int64_t)18LL);
g791 = ((int64_t)19LL);
g792 = ((int64_t)20LL);
g793 = ((int64_t)21LL);
g794 = ((int64_t)22LL);
g795 = ((int64_t)23LL);
g796 = ((int64_t)24LL);
g797 = ((int64_t)25LL);
g798 = ((int64_t)26LL);
g799 = ((int64_t)27LL);
g800 = ((int64_t)28LL);
g801 = ((int64_t)29LL);
g802 = ((int64_t)30LL);
g803 = ((int64_t)31LL);
g804 = ((int64_t)32LL);
g805 = ((int64_t)33LL);
g806 = ((int64_t)34LL);
g807 = ((int64_t)35LL);
g808 = ((int64_t)36LL);
g809 = ((int64_t)37LL);
g810 = ((int64_t)38LL);
g811 = ((int64_t)39LL);
g812 = ((int64_t)40LL);
g813 = ((int64_t)41LL);
g814 = ((int64_t)42LL);
g815 = ((int64_t)43LL);
g816 = ((int64_t)44LL);
g817 = ((int64_t)45LL);
g818 = ((int64_t)46LL);
g819 = ((int64_t)47LL);
g820 = ((int64_t)48LL);
g821 = ((int64_t)49LL);
g822 = ((int64_t)50LL);
g823 = ((int64_t)51LL);
g824 = ((int64_t)52LL);
g825 = ((int64_t)53LL);
g826 = ((int64_t)54LL);
g827 = ((int64_t)55LL);
g828 = ((int64_t)56LL);
g830 = ((int64_t)56LL);
g831 = ((int64_t)57LL);
g832 = ((int64_t)58LL);
g833 = ((int64_t)59LL);
g834 = ((int64_t)60LL);
g835 = ((int64_t)61LL);
g836 = ((int64_t)62LL);
g837 = ((int64_t)63LL);
g838 = ((int64_t)64LL);
g839 = ((int64_t)65LL);
g840 = ((int64_t)66LL);
g841 = ((int64_t)67LL);
g842 = ((int64_t)68LL);
g843 = ((int64_t)69LL);
g844 = ((int64_t)70LL);
g845 = ((int64_t)71LL);
g846 = ((int64_t)72LL);
g847 = ((int64_t)73LL);
g848 = ((int64_t)74LL);
g849 = ((int64_t)75LL);
g850 = ((int64_t)76LL);
g851 = ((int64_t)77LL);
g852 = ((int64_t)78LL);
g853 = ((int64_t)79LL);
g854 = ((int64_t)80LL);
g855 = ((int64_t)81LL);
g856 = ((int64_t)82LL);
g857 = ((int64_t)83LL);
g858 = ((int64_t)84LL);
g859 = ((int64_t)85LL);
g860 = ((int64_t)86LL);
g861 = ((int64_t)87LL);
g862 = ((int64_t)88LL);
g863 = ((int64_t)89LL);
g864 = ((int64_t)90LL);
g865 = ((int64_t)91LL);
g866 = ((int64_t)92LL);
g867 = ((int64_t)93LL);
g868 = ((int64_t)94LL);
g869 = ((int64_t)95LL);
g870 = ((int64_t)96LL);
g871 = ((int64_t)97LL);
g872 = ((int64_t)98LL);
g873 = ((int64_t)99LL);
g874 = ((int64_t)100LL);
g875 = ((int64_t)101LL);
g876 = ((int64_t)102LL);
g877 = ((int64_t)103LL);
g878 = ((int64_t)104LL);
g879 = ((int64_t)49LL);
}
static void hr_main(void) { f1_main(); }
