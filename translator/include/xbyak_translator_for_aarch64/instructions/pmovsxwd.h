void translatePMOVSXWD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/03/23 11:38 */
  bool isValid = false;
#define CG64 CodeGeneratorAArch64

  /* Col=S143*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=AD143*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::sxtl(xa::VReg4S(a64.dstIdx), xa::VReg4H(a64.srcIdx));
  }

  /* Col=BP143*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
