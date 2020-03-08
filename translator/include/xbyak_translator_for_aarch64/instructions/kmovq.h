void translateKMOVQ(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

/* 2020/03/07 10:02 */
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
  xt_reg_idx_t xTmpIdx;
  /* Col=T103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_GPR &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=V103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=W103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=X103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=Y103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=Z103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    xTmpIdx = X_TMP_0.getIdx();
  }
  /* Col=AA103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_INVALID && true)) {
    srcIdx = W_TMP_0.getIdx();
  }
  /* Col=AB103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    maskIdx = a64.operands[0].regIdx;
  }
  /* Col=AC103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    CG64::mov(xa::PRegB(maskIdx), P_ALL_ONE.b);
  }

  /* Col=AE103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_INVALID && true)) {
    CG64::ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }

  /* Col=AG103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    CG64::index(xa::ZRegB(zTmpIdx), 0, 1);
  }
  /* Col=AH103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    CG64::mov(xa::ZRegB(zTmp2Idx), 1);
  }
  /* Col=AI103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    CG64::lsl(xa::ZRegB(zTmp2Idx), xa::PReg(maskIdx) / xa::T_m,
              xa::ZRegB(zTmpIdx));
  }
  /* Col=AJ103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    CG64::mov(xa::XReg(xTmpIdx), xa::XReg(srcIdx));
  }
  /* Col=AK103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    CG64::dup(xa::ZRegS(zTmpIdx), xa::WReg(xTmpIdx));
  }
  /* Col=AL103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_INVALID && true)) {
    CG64::dup(xa::ZRegB(zTmpIdx), xa::WReg(srcIdx));
  }
  /* Col=AM103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    CG64::and_(xa::ZRegD(zTmpIdx), xa::ZRegD(zTmpIdx), xa::ZRegD(zTmp2Idx));
  }

  /* Col=AP103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    CG64::cmpne(xa::PRegB(dstIdx), xa::PReg(maskIdx), xa::ZRegB(zTmpIdx), 0);
  }

  /* Col=AS103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    CG64::mov(xa::PRegB(dstIdx), xa::PRegB(srcIdx));
  }

  /* Col=AW103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    xt_pop_zreg();
  }
  /* Col=AX103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    xt_pop_zreg();
  }
#undef CG64
}
