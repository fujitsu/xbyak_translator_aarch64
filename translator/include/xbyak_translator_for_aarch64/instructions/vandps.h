void translateVANDPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

/* 2020/02/13 10:03 */
/* Col=M103*/
if(false ||(a64.dstWidth==128&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==128&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==128&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==128&& a64.PredType==A64_PRED_NO && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==128&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==128&& a64.PredType==A64_PRED_NO && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==128&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==128&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==128&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==128&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==128&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==128&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==128&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==128&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==128&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==128&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==512&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==512&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==512&& a64.PredType==A64_PRED_NO && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==512&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==512&& a64.PredType==A64_PRED_NO && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==512&& a64.PredType==A64_PRED_NO && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==512&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==512&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==512&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==512&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==512&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==512&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==512&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==512&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==512&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==512&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 1 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)) {
  XT_UNIMPLEMENTED;
}

/* Col=O103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)) {
  a64.zTmpIdx = xt_push_zreg();
}


/* Col=R103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)) {
  CodeGeneratorAArch64::ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
}
/* Col=S103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)) {
  CodeGeneratorAArch64::ld1rw(xa::ZReg(a64.zTmpIdx).s, xa::PReg(a64.maskIdx)/xa::T_z, xa::ptr(X_TMP_ADDR));
}

/* Col=U103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)) {
  a64.zTmpIdx = xt_push_zreg();
}

/* Col=W103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)) {
  CodeGeneratorAArch64::orn(xa::PRegB(a64.zTmpIdx), P_ALL_ONE/xa::T_z, P_MSB_256.b, xa::PRegB(a64.maskIdx));
}

/* Col=Y103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)) {
  CodeGeneratorAArch64::and_(xa::VReg(a64.dstIdx).b, xa::VReg(a64.srcIdx).b, xa::VReg(a64.src2Idx).b);
}

/* Col=AA103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)) {
  CodeGeneratorAArch64::and_(xa::ZReg(a64.dstIdx).b,xa::PReg(a64.maskIdx)/xa::T_z, xa::ZReg(a64.src2Idx).b);
}
/* Col=AB103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)) {
  CodeGeneratorAArch64::and_(xa::ZReg(a64.dstIdx).b,xa::PReg(a64.maskIdx)/xa::T_z, xa::ZReg(a64.zTmpIdx).b);
}

/* Col=AD103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)) {
  CodeGeneratorAArch64::and_(xa::ZReg(a64.zTmpIdx).b, xa::PReg(a64.maskIdx)/xa::T_z, xa::ZReg(a64.zTmpIdx).b);
}

/* Col=AF103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)) {
  xt_pop_zreg();
}
/* Col=AG103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_NO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)) {
  CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_256/xa::T_m, 0);
}

/* Col=AI103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)) {
  CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, xa::PReg(a64.zTmpIdx)/xa::T_m, 0);
}
/* Col=AJ103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)) {
  CodeGeneratorAArch64::mov(xa::ZRegS(a64.dstIdx), xa::PReg(a64.maskIdx)/xa::T_m, xa::ZRegS(a64.zTmpIdx));
}
/* Col=AK103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_MERG && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)) {
  xt_pop_zreg(); // In some cases, xt_pop_zreg() should be called here.
}
/* Col=AL103*/
if(false ||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_REG)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MEM)||(a64.dstWidth==256&& a64.PredType==A64_PRED_ZERO && a64.EVEXb == 0 && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG && a64.src2Type==A64_OP_MBCST)) {
  xt_pop_zreg();
}


}
