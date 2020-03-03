void translateVADDSS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

/* 2020/03/04 08:21 */
#define CG64 CodeGeneratorAArch64

/* Col=S103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  XT_UNIMPLEMENTED;
}

/* Col=U103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  a64.zTmpIdx = xt_push_zreg(&a64);
}
/* Col=V103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
}

/* Col=X103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).d, xa::ZReg(a64.srcIdx).d);
}
/* Col=Y103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_384/xa::T_m, 0);
}

/* Col=AA103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::fadd(xa::ZReg(a64.zTmpIdx).s, xa::ZReg(a64.srcIdx).s, xa::ZReg(a64.src2Idx).s);
}
/* Col=AB103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::fadd(xa::ZReg(a64.zTmpIdx).s, xa::ZReg(a64.srcIdx).s, xa::ZReg(a64.zTmpIdx).s);
}

/* Col=AD103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  a64.pTmpIdx = xt_push_preg(&a64);
}
/* Col=AE103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE.b, xa::PRegB(a64.maskIdx));
}
/* Col=AF103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::mov(xa::ZRegS(a64.zTmpIdx), xa::PReg(a64.pTmpIdx)/xa::T_m, 0);
}

/* Col=AH103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::mov(xa::ZRegS(a64.zTmpIdx), xa::PReg(a64.pTmpIdx)/xa::T_m, xa::ZRegS(a64.dstIdx));
}

/* Col=AJ103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::ptrue(xa::PReg(a64.pTmpIdx).s, xa::VL1);
}
/* Col=AK103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::mov(xa::ZRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx)/xa::T_m, xa::ZRegS(a64.zTmpIdx));
}

/* Col=AM103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  xt_pop_preg();
}
/* Col=AL103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  xt_pop_zreg(); // In some cases, xt_pop_zreg() should be called here.
}
#undef CG64
}
