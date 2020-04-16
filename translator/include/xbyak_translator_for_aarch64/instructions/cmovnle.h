void translateCMOVNLE(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/04/15 13:12 */
  bool isValid = false;
#define CG64 CodeGeneratorAArch64
  enum Xbyak::Xbyak_aarch64::Cond condGT = Xbyak::Xbyak_aarch64::GT;

  /* Col=S143*/
  if (false ||
      (a64.dstWidth == 16 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 16 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 64 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=AD143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::csel(xa::WReg(a64.dstIdx), xa::WReg(a64.srcIdx),
                               xa::WReg(a64.dstIdx), condGT);
  }
  /* Col=AG143*/
  if (false || (a64.dstWidth == 64 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::csel(xa::XReg(a64.dstIdx), xa::XReg(a64.srcIdx),
                               xa::XReg(a64.dstIdx), condGT);
  }

  /* Col=BP143*/
  if (false ||
      (a64.dstWidth == 16 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 16 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 64 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 64 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
