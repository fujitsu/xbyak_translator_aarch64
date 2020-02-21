void translateMOVD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/21 20:35 */
  /* Col=S103*/
  if(false ||(a64.dstWidth==64&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==64&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    XT_UNIMPLEMENTED;
  }




  /* Col=X103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=Y103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=Z103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    CodeGeneratorAArch64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, P_MSB_384.b);
  }

  /* Col=AB103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).b, xa::PReg(a64.pTmpIdx)/xa::T_m, 0);
  }

  /* Col=AD103*/
  if(false ||(a64.dstWidth==32&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)) {
    CodeGeneratorAArch64::fmov(xa::WReg(a64.dstIdx), xa::SReg(a64.srcIdx));
  }
  /* Col=AE103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    CodeGeneratorAArch64::ptrue(xa::PReg(a64.pTmpIdx).s, xa::VL1);
  }

  /* Col=AG103*/
  if(false ||(a64.dstWidth==32&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
    CodeGeneratorAArch64::str(xa::SReg(a64.srcIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AH103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, xa::PReg(a64.pTmpIdx)/xa::T_m, xa::WReg(a64.srcIdx));
  }
  /* Col=AI103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    CodeGeneratorAArch64::ld1w(xa::ZReg(a64.zTmpIdx).s, xa::PReg(a64.pTmpIdx)/xa::T_z, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AJ103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, xa::PReg(a64.pTmpIdx)/xa::T_m, xa::ZReg(a64.zTmpIdx).s);
  }


  /* Col=AM103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    xt_pop_zreg();
  }
  /* Col=AN103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    xt_pop_preg();
  }

  
}
