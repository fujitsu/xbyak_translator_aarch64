void translateVMOVDQU16(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/20 20:07 */




/* Col=W103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::mov(xa::VReg16B(a64.dstIdx), xa::VReg16B(a64.srcIdx));
}





/* Col=AC103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::ldr(xa::QReg(a64.dstIdx), xa::ptr(X_TMP_ADDR));
}
/* Col=AD103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::str(xa::QReg(a64.srcIdx), xa::ptr(X_TMP_ADDR));
}

/* Col=AF103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  a64.zTmpIdx = xt_push_zreg(&a64);
}
/* Col=AG103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  a64.pTmpIdx = xt_push_preg(&a64);
}


/* Col=AJ103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::ld1b(xa::ZReg(a64.dstIdx).h, xa::PReg(a64.maskIdx)/xa::T_z, xa::ptr(X_TMP_ADDR));
}
/* Col=AK103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, xa::PReg(a64.maskIdx).b);
}
/* Col=AL103*/
if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).h, xa::PReg(a64.maskIdx)/xa::T_m, xa::ZReg(a64.srcIdx).h);
}
/* Col=AM103*/
if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).h, xa::PReg(a64.pTmpIdx)/xa::T_m, 0);
}
/* Col=AN103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::movs(xa::PRegB(a64.pTmpIdx), P_ALL_ONE.b);
}
/* Col=AO103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::ld1b(xa::ZReg(a64.zTmpIdx).h, xa::PReg(a64.pTmpIdx)/xa::T_z, xa::ptr(X_TMP_ADDR));
}
/* Col=AP103*/
if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::movs(xa::PRegB(a64.pTmpIdx), P_MSB_256.b);
}
/* Col=AQ103*/
if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, P_MSB_256.b);
}
/* Col=AR103*/
if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::mov(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.srcIdx));
}
/* Col=AS103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).h, xa::PReg(a64.maskIdx)/xa::T_m, xa::ZReg(a64.srcIdx).h);
}
/* Col=AT103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).h, xa::PReg(a64.pTmpIdx)/xa::T_m, 0);
}
/* Col=AU103*/
if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::ld1b(xa::ZReg(a64.dstIdx).h, xa::PReg(a64.pTmpIdx)/xa::T_z, xa::ptr(X_TMP_ADDR));
}
/* Col=AV103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).h, xa::PReg(a64.maskIdx)/xa::T_m, xa::ZReg(a64.zTmpIdx).h);
}
/* Col=AW103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::mov(xa::ZReg(a64.zTmpIdx).h, xa::PReg(a64.maskIdx)/xa::T_m, xa::ZReg(a64.srcIdx).h);
}

/* Col=AY103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::mov(xa::ZReg(a64.zTmpIdx).h, xa::PReg(a64.pTmpIdx)/xa::T_m, 0);
}
/* Col=AZ103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::movs(xa::PRegB(a64.pTmpIdx), P_ALL_ONE.b);
}
/* Col=BA103*/
if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::st1b(xa::ZReg(a64.srcIdx).h, xa::PReg(a64.pTmpIdx)/xa::T_z, xa::ptr(X_TMP_ADDR));
}
/* Col=BB103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::st1b(xa::ZReg(a64.zTmpIdx).h, xa::PReg(a64.pTmpIdx)/xa::T_m, xa::ptr(X_TMP_ADDR));
}
/* Col=BC103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::st1b(xa::ZReg(a64.srcIdx).h, xa::PReg(a64.maskIdx)/xa::T_m, xa::ptr(X_TMP_ADDR));
}
/* Col=BD103*/
if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::movs(xa::PRegB(a64.pTmpIdx), P_MSB_256.b);
}
/* Col=BE103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::movs(xa::PRegB(a64.pTmpIdx), P_MSB_384.b);
}
/* Col=BF103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).h, xa::PReg(a64.pTmpIdx)/xa::T_m, 0);
}
/* Col=BG103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::mov(xa::ZReg(a64.zTmpIdx).h, xa::PReg(a64.pTmpIdx)/xa::T_m, 0);
}
/* Col=BH103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::st1b(xa::ZReg(a64.zTmpIdx).h, xa::PReg(a64.pTmpIdx)/xa::T_m, xa::ptr(X_TMP_ADDR));
}
/* Col=BI103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  xt_pop_preg();
}
/* Col=BJ103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  xt_pop_zreg();
}
    
}
