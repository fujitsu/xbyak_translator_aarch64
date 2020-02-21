void translateVMOVD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/21 14:56 */

  /* Col=V103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::bic(xa::VReg(a64.dstIdx).s4, 0);
  }

  /* Col=Z103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::fmov(xa::SReg(a64.dstIdx), xa::WReg(a64.srcIdx));
  }
  /* Col=AA103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::fmov(xa::WReg(a64.dstIdx), xa::SReg(a64.srcIdx));
  }

  /* Col=AC103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldr(xa::SReg(a64.dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AD103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::str(xa::SReg(a64.srcIdx), xa::ptr(X_TMP_ADDR));
  }
}
