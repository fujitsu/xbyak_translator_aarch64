void translateVPSHUFB(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

/* 2020/03/04 19:53 */
#define CG64 CodeGeneratorAArch64
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;
  xt_reg_idx_t src2Idx;
  xt_reg_idx_t zTmpIdx;
  xt_reg_idx_t zTmp2Idx;
  xt_reg_idx_t zTmp3Idx;
  xt_reg_idx_t pTmpIdx;
  /* Col=T103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=U103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=V103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=W103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=X103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    zTmp3Idx = xt_push_zreg(&a64);
  }
  /* Col=Y103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=Z103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[1].regClass == XED_REG_CLASS_YMM &&
                a64.operands[0].opWidth == 256 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AA103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AB103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[1].regClass == XED_REG_CLASS_YMM &&
                a64.operands[0].opWidth == 256 && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AC103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    src2Idx = a64.operands[3].regIdx;
  }

  /* Col=AF103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    CG64::mov(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }

  /* Col=AH103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    CG64::mov(xa::ZRegB(zTmpIdx), 15);
  }
  /* Col=AI103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    CG64::and_(xa::ZRegB(zTmpIdx), xa::PReg(pTmpIdx), xa::ZRegB(src2Idx));
  }

  /* Col=AL103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    for (int i = 0; i < 16; i++) {
      CG64::cmpeq(P_TMP_0.b, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), i);
      CG64::dup(xa::ZRegB(zTmp2Idx), xa::ZRegB(srcIdx)[i]);
      CG64::mov(xa::ZRegB(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
    }
  }
  /* Col=AM103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    for (int i = 16; i < 32; i++) {
      CG64::cmpeq(P_TMP_0.b, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), i - 16);
      CG64::and_(P_TMP_0.b, xa::PReg(pTmpIdx), P_TMP_0.b, P_MSB_384.b);
      CG64::dup(xa::ZRegB(zTmp2Idx), xa::ZRegB(srcIdx)[i]);
      CG64::mov(xa::ZRegB(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
    }
  }

  /* Col=AP103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    CG64::cmplt(P_TMP_0.b, xa::PReg(pTmpIdx), xa::ZRegB(src2Idx), 0);
  }
  /* Col=AQ103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    CG64::mov(xa::ZRegD(dstIdx), xa::ZRegD(zTmp3Idx));
  }
  /* Col=AR103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    CG64::orr(xa::PRegB(pTmpIdx), P_ALL_ONE, P_TMP_0.b, P_MSB_256.b);
  }

  /* Col=AT103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    CG64::mov(xa::ZRegB(dstIdx), xa::PReg(pTmpIdx) / xa::T_m, 0);
  }

  /* Col=BN103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_zreg();
  }
  /* Col=BO103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_zreg();
  }
  /* Col=BP103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_zreg();
  }
  /* Col=BQ103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_preg();
  }
#undef CG64
}
