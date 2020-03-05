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
  xed_uint64_t uimm;
  /* Col=T103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=U103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=V103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    pTmp2Idx = xt_push_preg(&a64);
  }
  /* Col=W103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=X103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=Y103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=Z103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AA103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AB103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    uimm = a64.operands[3].uimm;
  }
  /* Col=AC103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::mov(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }

  /* Col=AE103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::mov(xa::ZRegD(zTmpIdx), int32_t(0));
  }
  /* Col=AF103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::add(xa::ZRegD(zTmpIdx), uimm);
  }
  /* Col=AG103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::lsr(xa::ZRegD(zTmpIdx), xa::ZRegD(zTmpIdx), 4);
  }
  /* Col=AH103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::and_(xa::ZRegD(zTmpIdx), 3);
  }
  /* Col=AI103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::ptrue(P_TMP_0.d, xa::VL4);
  }
  /* Col=AJ103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::dup(xa::ZRegQ(zTmp2Idx), xa::ZRegQ(srcIdx)[0]);
  }
  /* Col=AK103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::cmpeq(xa::PReg(pTmp2Idx).b, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), 0);
  }
  /* Col=AL103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::and_(xa::PRegB(pTmp2Idx), xa::PReg(pTmpIdx), xa::PRegB(pTmp2Idx), P_TMP_0.b);
  }
  /* Col=AM103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::sel(xa::ZRegD(dstIdx), xa::PReg(pTmp2Idx), xa::ZRegD(zTmp2Idx), xa::ZRegD(dstIdx));
  }
  /* Col=AN103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::dup(xa::ZRegQ(zTmp2Idx), xa::ZRegQ(src2Idx)[0]);
  }
  /* Col=AO103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::cmpeq(xa::PReg(pTmp2Idx).b, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), 2);
  }
  /* Col=AP103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::and_(xa::PRegB(pTmp2Idx), xa::PReg(pTmpIdx), xa::PRegB(pTmp2Idx), P_TMP_0.b);
  }
  /* Col=AQ103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::sel(xa::ZRegD(dstIdx), xa::PReg(pTmp2Idx), xa::ZRegD(zTmp2Idx), xa::ZRegD(dstIdx));
  }
  /* Col=AR103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::dup(xa::ZRegQ(zTmp2Idx), xa::ZRegQ(srcIdx)[1]);
  }
  /* Col=AS103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::cmpeq(xa::PReg(pTmp2Idx).b, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), 1);
  }
  /* Col=AT103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::and_(xa::PRegB(pTmp2Idx), xa::PReg(pTmpIdx), xa::PRegB(pTmp2Idx), P_TMP_0.b);
  }
  /* Col=AU103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::sel(xa::ZRegD(dstIdx), xa::PReg(pTmp2Idx), xa::ZRegD(zTmp2Idx), xa::ZRegD(dstIdx));
  }
  /* Col=AV103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::dup(xa::ZRegQ(zTmp2Idx), xa::ZRegQ(src2Idx)[1]);
  }
  /* Col=AW103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::cmpeq(xa::PReg(pTmp2Idx).b, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), 3);
  }
  /* Col=AX103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::and_(xa::PRegB(pTmp2Idx), xa::PReg(pTmpIdx), xa::PRegB(pTmp2Idx), P_TMP_0.b);
  }
  /* Col=AY103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::sel(xa::ZRegD(dstIdx), xa::PReg(pTmp2Idx), xa::ZRegD(src2Idx), xa::ZRegD(dstIdx));
  }

  /* Col=BA103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::mov(xa::ZRegD(zTmpIdx), int32_t(0));
  }
  /* Col=BB103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::add(xa::ZRegD(zTmpIdx), uimm);
  }
  /* Col=BC103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::and_(xa::ZRegD(zTmpIdx), 3);
  }
  /* Col=BD103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::ptrue(P_TMP_0.d, xa::VL2);
  }
  /* Col=BE103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::cmpeq(xa::PReg(pTmp2Idx).b, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), 0);
  }
  /* Col=BF103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::and_(xa::PRegB(pTmp2Idx), xa::PReg(pTmpIdx), xa::PRegB(pTmp2Idx), P_TMP_0.b);
  }
  /* Col=BG103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::sel(xa::ZRegD(dstIdx), xa::PReg(pTmp2Idx), xa::ZRegD(srcIdx), xa::ZRegD(dstIdx));
  }
  /* Col=BH103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::cmpeq(xa::PReg(pTmp2Idx).b, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), 2);
  }
  /* Col=BI103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::and_(xa::PRegB(pTmp2Idx), xa::PReg(pTmpIdx), xa::PRegB(pTmp2Idx), P_TMP_0.b);
  }
  /* Col=BJ103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::sel(xa::ZRegD(dstIdx), xa::PReg(pTmp2Idx), xa::ZRegD(src2Idx), xa::ZRegD(dstIdx));
  }
  /* Col=BK103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::dup(xa::ZRegQ(zTmp2Idx), xa::ZRegQ(srcIdx)[1]);
  }
  /* Col=BL103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::cmpeq(xa::PReg(pTmp2Idx).b, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), 1);
  }
  /* Col=BM103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::and_(xa::PRegB(pTmp2Idx), xa::PReg(pTmpIdx), xa::PRegB(pTmp2Idx), P_TMP_0.b);
  }
  /* Col=BN103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::sel(xa::ZRegD(dstIdx), xa::PReg(pTmp2Idx), xa::ZRegD(zTmp2Idx), xa::ZRegD(dstIdx));
  }
  /* Col=BO103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::dup(xa::ZRegQ(zTmp2Idx), xa::ZRegQ(src2Idx)[1]);
  }
  /* Col=BP103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::cmpeq(xa::PReg(pTmp2Idx).b, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), 3);
  }
  /* Col=BQ103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::and_(xa::PRegB(pTmp2Idx), xa::PReg(pTmpIdx), xa::PRegB(pTmp2Idx), P_TMP_0.b);
  }
  /* Col=BR103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::sel(xa::ZRegD(dstIdx), xa::PReg(pTmp2Idx), xa::ZRegD(zTmp2Idx), xa::ZRegD(dstIdx));
  }

  /* Col=BT103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::mov(xa::ZRegD(zTmpIdx), int32_t(0));
  }
  /* Col=BU103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::add(xa::ZRegD(zTmpIdx), int32_t(uimm));
  }
  /* Col=BV103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::and_(xa::ZRegD(zTmpIdx), 8);
  }
  /* Col=BW103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::cmpeq(xa::PReg(pTmp2Idx).b, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), 8);
  }
  /* Col=BX103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::and_(xa::PRegB(pTmp2Idx), xa::PReg(pTmpIdx), xa::PRegB(pTmp2Idx), P_TMP_0.b);
  }
  /* Col=BY103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::mov(xa::ZRegD(dstIdx), xa::PReg(pTmp2Idx)/xa::T_m, 0);
  }
  /* Col=BZ103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::mov(xa::ZRegD(zTmpIdx), int32_t(0));
  }
  /* Col=CA103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::add(xa::ZRegD(zTmpIdx), uimm);
  }
  /* Col=CB103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::lsr(xa::ZRegD(zTmpIdx), xa::ZRegD(zTmpIdx), 7);
  }
  /* Col=CC103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::cmpeq(xa::PReg(pTmp2Idx).b, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), 1);
  }
  /* Col=CD103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::and_(xa::PRegB(pTmp2Idx), xa::PReg(pTmpIdx), xa::PRegB(pTmp2Idx), P_MSB_384.b);
  }
  /* Col=CE103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::mov(xa::ZRegD(dstIdx), xa::PReg(pTmp2Idx)/xa::T_m, 0);
  }

  /* Col=CG103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    CG64::mov(xa::ZRegD(dstIdx), P_MSB_256/xa::T_m, 0);
  }
  /* Col=CH103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    xt_pop_zreg();
  }
  /* Col=CI103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    xt_pop_zreg();
  }
  /* Col=CJ103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    xt_pop_preg();
  }
  /* Col=CK103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==256&&true)) {
    xt_pop_preg();
  }
  #undef CG64
  
  
}
