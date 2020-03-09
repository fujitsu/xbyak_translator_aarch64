void translateMOVQ(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

/* 2020/03/06 19:44 */
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
  xed_uint64_t uimm;
  /* Col=T103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MMX &&
       a64.operands[1].regClass == XED_REG_CLASS_MMX && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MMX &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MMX && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MMX &&
       a64.operands[1].regClass == XED_REG_CLASS_MMX && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=Y103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=Z103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM && true)) {
    srcIdx = a64.operands[1].regIdx;
  }

  /* Col=AB103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AC103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_INVALID && true)) {
    CG64::ldr(X_TMP_1, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AD103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true)) {
    CG64::mov(X_TMP_0, 0);
  }
  /* Col=AE103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM && true)) {
    CG64::mov(xa::VReg2D(dstIdx)[0], xa::VReg2D(srcIdx)[0]);
  }

  /* Col=AJ103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM && true)) {
    CG64::str(xa::DReg(srcIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AN103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_INVALID && true)) {
    CG64::mov(xa::VReg2D(dstIdx)[0], X_TMP_1);
  }
  /* Col=AO103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true)) {
    CG64::mov(xa::VReg2D(dstIdx)[1], X_TMP_0);
  }

#undef CG64
}
