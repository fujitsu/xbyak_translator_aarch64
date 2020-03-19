void translateADDSS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/03/19 15:51 */
  bool isValid = false;
#define CG64 CodeGeneratorAArch64

  /* Col=T143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=U143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_MEM && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=W143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::not_(xa::PRegB(a64.pTmpIdx), xa::PReg(15),
                               xa::PRegB(15));
  }
  /* Col=X143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::zip1(xa::PRegS(a64.pTmpIdx), xa::PRegS(15),
                               xa::PRegS(a64.pTmpIdx));
  }
  /* Col=Y143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::zip1(xa::PRegS(a64.pTmpIdx), xa::PRegS(a64.pTmpIdx),
                               xa::PRegS(13));
  }
  /* Col=Z143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::zip1(xa::PRegS(a64.pTmpIdx), xa::PRegS(a64.pTmpIdx),
                               xa::PRegS(13));
  }
  /* Col=AA143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::zip1(xa::PRegS(a64.pTmpIdx), xa::PRegS(a64.pTmpIdx),
                               xa::PRegS(13));
  }

  /* Col=AG143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AM143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::add(xa::ZRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx),
                              xa::ZRegS(a64.srcIdx));
  }
  /* Col=AO143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::add(xa::ZRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx),
                              xa::ZRegS(a64.zTmpIdx));
  }

  /* Col=AW143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_MEM && true)) {
    xt_pop_zreg();
  }
  /* Col=AX143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    xt_pop_preg();
  }

  /* Col=BP143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
