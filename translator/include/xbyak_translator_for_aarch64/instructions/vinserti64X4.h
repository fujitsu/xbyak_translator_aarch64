void translateVINSERTI64X4(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

/* 2020/03/04 10:21 */
/* Col=S103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.src2Type==A64_OP_MEM&&true)) {
  XT_UNIMPLEMENTED;
}

/* Col=U103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_MEM&&true)) {
  a64.zTmpIdx = xt_push_zreg(&a64);
}
/* Col=V103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_MEM&&true)) {
  a64.pTmpIdx = xt_push_preg(&a64);
}



/* Col=Z103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
}


/* Col=AC103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::ptrue(xa::PRegD(a64.pTmpIdx), xa::VL4);
}


/* Col=AF103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_REG&&true)) {
  if((a64.uimm & 0x1) == 0){CodeGeneratorAArch64::sel(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx), xa::ZRegD(a64.src2Idx), xa::ZRegD(a64.srcIdx));}
}

/* Col=AH103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_MEM&&true)) {
  if((a64.uimm & 0x1) == 0){CodeGeneratorAArch64::sel(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx), xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.srcIdx));}
}


/* Col=AK103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_MEM&&true)) {
  if((a64.uimm & 0x1) == 1){CodeGeneratorAArch64::mov(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.srcIdx));}
}

/* Col=AM103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_REG&&true)) {
  if(a64.uimm == 1) {CodeGeneratorAArch64::splice(xa::ZRegD(a64.dstIdx), xa::PRegD(a64.pTmpIdx), xa::ZRegD(a64.src2Idx) );}
}

/* Col=AO103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_MEM&&true)) {
  if((a64.uimm & 0x1) == 1) {CodeGeneratorAArch64::splice(xa::ZRegD(a64.dstIdx), xa::PRegD(a64.pTmpIdx), xa::ZRegD(a64.zTmpIdx) );}
}












/* Col=BB103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_MEM&&true)) {
  xt_pop_preg();
}
/* Col=BC103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.src2Type==A64_OP_MEM&&true)) {
  xt_pop_zreg();
}



}

