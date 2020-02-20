void translateVMOVAPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);
  /* 2020/02/21 13:23 */
  /* Col=S103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=X103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::VReg16B(a64.dstIdx), xa::VReg16B(a64.srcIdx));
  }
  /* Col=AC103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.srcIdx));
  }
  /* Col=AH103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_256 / xa::T_m, 0);
  }
  /* Col=AM103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.srcIdx));
  }
}
