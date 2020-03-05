void translateVPORD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

/* 2020/03/05 13:42 */
/* Col=S103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)) {
  XT_UNIMPLEMENTED;
}

/* Col=U103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)) {
  a64.zTmpIdx = xt_push_zreg(&a64);
}
/* Col=V103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)) {
  a64.pTmpIdx = xt_push_preg(&a64);
}
/* Col=W103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::mov(xa::PReg(a64.pTmpIdx).b, xa::PReg(15).b);
}


/* Col=Z103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
}



/* Col=AD103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::ld1rsw(xa::ZRegD(a64.zTmpIdx), xa::PReg(a64.pTmpIdx), xa::ptr(X_TMP_ADDR));
}



/* Col=AH103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::uzp1(xa::ZReg(a64.zTmpIdx).s, xa::ZReg(a64.zTmpIdx).s, xa::ZReg(a64.zTmpIdx).s );
}



/* Col=AL103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::orr(xa::ZReg(a64.dstIdx).d,xa::ZReg(a64.srcIdx).d, xa::ZReg(a64.zTmpIdx).d);
}














/* Col=BA103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)) {
  xt_pop_preg();
}

/* Col=BC103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.src2Type==A64_OP_MEM&&true)) {
  xt_pop_zreg();
}


}
