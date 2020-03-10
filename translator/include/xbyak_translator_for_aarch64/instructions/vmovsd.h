void translateVMOVSD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

/* 2020/03/10 22:22 */
#define CG64 CodeGeneratorAArch64
  bool isValid = false;
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;
  xt_reg_idx_t src2Idx;
  xt_reg_idx_t src3Idx;
  xt_reg_idx_t maskIdx;
  xt_reg_idx_t zTmpIdx;
  xt_reg_idx_t zTmp2Idx;
  xt_reg_idx_t pTmpIdx;
  xt_reg_idx_t pTmp2Idx;
  xed_uint64_t uimm;

  /* Col=U103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }

  /* Col=W103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_MERG && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=X103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=Y103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=Z103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AA103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AB103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AC103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_NO && true)) {
    srcIdx = a64.operands[3].regIdx;
  }

  /* Col=AE103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AF103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[2].opName == XED_OPERAND_INVALID &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true)) {
    CG64::ptrue(P_TMP_0.d, xa::VL1);
  }
  /* Col=AG103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    CG64::ptrue(xa::PReg(pTmpIdx).d, xa::VL1);
  }
  /* Col=AH103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_MERG && true)) {
    CG64::not_(P_TMP_0.b, P_ALL_ONE, xa::PRegB(pTmpIdx));
  }
  /* Col=AI103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    CG64::and_(xa::PRegB(pTmpIdx), P_ALL_ONE, xa::PRegB(maskIdx),
               xa::PRegB(pTmpIdx));
  }
  /* Col=AJ103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[2].opName == XED_OPERAND_REG1 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    CG64::and_(xa::PRegB(pTmpIdx), P_ALL_ONE, xa::PRegB(maskIdx),
               xa::PRegB(pTmpIdx));
  }
  /* Col=AK103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_MERG && true)) {
    CG64::and_(P_TMP_0.b, P_ALL_ONE, xa::PRegB(maskIdx), P_TMP_0.b);
  }

  /* Col=AM103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[2].opName == XED_OPERAND_INVALID &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true)) {
    CG64::not_(P_TMP_0.b, P_ALL_ONE, P_TMP_0.b);
  }

  /* Col=AO103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_ZERO && true)) {
    CG64::orn(P_TMP_0.b, P_ALL_ONE, P_MSB_384.b, xa::PRegB(maskIdx));
  }
  /* Col=AP103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_ZERO && true)) {
    CG64::ld1d(xa::ZRegD(dstIdx), xa::PReg(pTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AQ103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_MERG && true)) {
    CG64::ld1d(xa::ZRegD(zTmpIdx), xa::PReg(pTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AR103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[2].opName == XED_OPERAND_INVALID &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true)) {
    CG64::ld1(xa::VReg2D(dstIdx)[0], xa::ptr(X_TMP_ADDR));
  }
  /* Col=AS103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[2].opName == XED_OPERAND_INVALID &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true)) {
    CG64::st1(xa::VReg2D(srcIdx)[0], xa::ptr(X_TMP_ADDR));
  }
  /* Col=AT103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[2].opName == XED_OPERAND_REG1 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    CG64::st1d(xa::ZRegD(srcIdx), xa::PReg(pTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AU103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_NO && true)) {
    CG64::sel(xa::ZRegD(dstIdx), P_TMP_0, xa::ZRegD(srcIdx),
              xa::ZRegD(src2Idx));
  }
  /* Col=AV103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_NO && true)) {
    CG64::mov(xa::VReg2D(dstIdx)[1], xa::VReg2D(srcIdx)[1]);
  }
  /* Col=AW103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true)) {
    CG64::mov(xa::VReg2D(dstIdx)[0], xa::VReg2D(src2Idx)[0]);
  }

  /* Col=AX103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_MERG && true)) {
    CG64::mov(xa::ZRegD(dstIdx), P_TMP_0 / xa::T_m, xa::ZRegD(src2Idx));
  }
  /* Col=AY103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[2].opName == XED_OPERAND_INVALID &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true)) {
    CG64::mov(xa::ZRegD(dstIdx), P_TMP_0 / xa::T_m, 0);
  }
  /* Col=AZ103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true)) {
    CG64::mov(xa::ZRegD(dstIdx), P_MSB_384 / xa::T_m, 0);
  }
  /* Col=BA103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_MERG && true)) {
    CG64::mov(xa::ZRegD(dstIdx), P_TMP_0 / xa::T_m, 0);
  }
  /* Col=BB103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_MERG && true)) {
    CG64::mov(xa::ZRegD(dstIdx), xa::PReg(pTmpIdx) / xa::T_m,
              xa::ZRegD(zTmpIdx));
  }
  /* Col=BC103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true)) {
    CG64::mov(xa::VReg2D(dstIdx)[1], xa::VReg2D(srcIdx)[1]);
  }
  /* Col=BD103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_MERG && true)) {
    xt_pop_zreg();
  }
  /* Col=BE103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    xt_pop_preg();
  }
  /* Col=BF103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    XT_VALID_CHECK;
  }

  XT_VALID_CHECK_IF;
#undef CG64
}
