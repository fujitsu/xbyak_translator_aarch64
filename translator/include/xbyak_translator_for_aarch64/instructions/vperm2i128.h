void translateVPERM2I128(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

  /* 2020/03/05 19:06 */
#define CG64 CodeGeneratorAArch64

  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;
  xt_reg_idx_t src2Idx;
  xt_reg_idx_t src3Idx;
  xt_reg_idx_t maskIdx;
  xt_reg_idx_t zTmpIdx;
  xt_reg_idx_t zTmp2Idx;
  xt_reg_idx_t pTmpIdx;
  xt_reg_idx_t pTmp2Idx;
  xt_reg_idx_t spIdx;
  xed_uint64_t uimm;

  pTmpIdx = xt_push_preg(&a64);
  zTmpIdx = xt_push_zreg(&a64);
  zTmp2Idx = xt_push_zreg(&a64);
  dstIdx = a64.operands[0].regIdx;
  int lsbElem = 1;
  int msbElem = 0;

  switch (a64.operands[3].uimm & 0x3f) {
  case 0x01:
    srcIdx = a64.operands[1].regIdx;
    src2Idx = a64.operands[1].regIdx;
    break;
  case 0x03:
    srcIdx = a64.operands[2].regIdx;
    src2Idx = a64.operands[1].regIdx;
    break;
  case 0x21:
    srcIdx = a64.operands[1].regIdx;
    src2Idx = a64.operands[2].regIdx;
    break;
  case 0x23:
    srcIdx = a64.operands[2].regIdx;
    src2Idx = a64.operands[2].regIdx;
    break;
  default:
    xt_msg_err(__FILE__, __LINE__, "Something wrong");
    break;
  }
  CG64::ptrue(xa::PRegD(pTmpIdx), xa::VL2);
  CG64::dup(xa::ZRegQ(zTmpIdx), xa::ZRegQ(srcIdx)[lsbElem]);
  CG64::dup(xa::ZRegQ(zTmp2Idx), xa::ZRegQ(src2Idx)[msbElem]);
  CG64::sel(xa::ZRegD(dstIdx), xa::PReg(pTmpIdx), xa::ZRegD(zTmpIdx),
            xa::ZRegD(zTmp2Idx));
  CG64::mov(xa::ZRegD(dstIdx), P_MSB_256 / xa::T_m, 0);
  xt_pop_zreg();
  xt_pop_zreg();
  xt_pop_preg();
#undef CG64
}
