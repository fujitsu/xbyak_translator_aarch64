void translateVPBROADCASTB(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/03/02 16:28 */
  /* Col=S103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=U103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=V103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }

  /* Col=X103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)) {
    CodeGeneratorAArch64::orn(xa::PRegB(a64.pTmpIdx), P_ALL_ONE/xa::T_z, P_MSB_384.b, xa::PRegB(a64.maskIdx));
  }
  /* Col=Y103*/
  if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)) {
    CodeGeneratorAArch64::orn(xa::PRegB(a64.pTmpIdx), P_ALL_ONE/xa::T_z, P_MSB_256.b, xa::PRegB(a64.maskIdx));
  }
  /* Col=Z103*/
  if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)) {
    CodeGeneratorAArch64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE.b, xa::PRegB(a64.maskIdx));
  }

  /* Col=AB103*/
  if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)) {
    CodeGeneratorAArch64::ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AC103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)) {
    CodeGeneratorAArch64::ld1r(xa::VReg16B(a64.dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AD103*/
  if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)) {
    CodeGeneratorAArch64::ld1rb(xa::ZRegB(a64.dstIdx), xa::PReg(a64.maskIdx)/xa::T_z, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AE103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)) {
    CodeGeneratorAArch64::ld1rb(xa::ZRegB(a64.zTmpIdx), xa::PReg(a64.maskIdx)/xa::T_z, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AF103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)) {
    CodeGeneratorAArch64::dup(xa::VReg16B(a64.dstIdx), xa::WReg(a64.srcIdx));
  }
  /* Col=AG103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)) {
    CodeGeneratorAArch64::dup(xa::ZRegB(a64.dstIdx), xa::WReg(a64.srcIdx));
  }

  /* Col=AI103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)) {
    CodeGeneratorAArch64::dup(xa::ZRegB(a64.zTmpIdx), xa::WReg(a64.srcIdx));
  }
  /* Col=AJ103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)) {
    CodeGeneratorAArch64::dup(xa::VReg16B(a64.dstIdx), xa::VReg16B(a64.srcIdx)[a64.uimm]);
  }
  /* Col=AK103*/
  if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)) {
    CodeGeneratorAArch64::dup(xa::ZRegB(a64.dstIdx), xa::ZRegB(a64.srcIdx)[a64.uimm]);
  }

  /* Col=AM103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)) {
    CodeGeneratorAArch64::dup(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.srcIdx)[a64.uimm]);
  }
  /* Col=AN103*/
  if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)) {
    CodeGeneratorAArch64::dup(xa::ZRegB(a64.dstIdx), W_TMP_0);
  }



  /* Col=AR103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)) {
    CodeGeneratorAArch64::mov(xa::ZRegB(a64.dstIdx), xa::PReg(a64.pTmpIdx)/xa::T_m, 0);
  }
  /* Col=AS103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)) {
    CodeGeneratorAArch64::mov(xa::ZRegB(a64.dstIdx), xa::PReg(a64.maskIdx)/xa::T_m, xa::ZRegB(a64.zTmpIdx));
  }
  /* Col=AT103*/
  if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)) {
    CodeGeneratorAArch64::mov(xa::ZRegB(a64.dstIdx), P_MSB_256/xa::T_m, 0);
  }


  /* Col=AW103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)) {
    xt_pop_zreg();
  }
  /* Col=AX103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_GPR&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&a64.srcRegClass==XED_REG_CLASS_INVALID&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.srcRegClass==XED_REG_CLASS_XMM&&true)) {
    xt_pop_preg();
  }
  
}
