void translateVMOVSD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/27 08:24 */
  #define CG64 CodeGeneratorAArch64


  /* Col=U103*/
  if(false ||(a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }

  /* Col=W103*/
  if(false ||(a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    CG64::fmov(xa::VReg(a64.dstIdx).d, 0);
  }


  /* Col=Z103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CG64::mov(xa::VReg(a64.dstIdx).d[1], xa::VReg(a64.srcIdx).d[0]);
  }
  /* Col=AA103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CG64::mov(xa::VReg(a64.dstIdx).d[0], xa::VReg(a64.src2Idx).d[0]);
  }

  /* Col=AC103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    CG64::ldr(xa::DReg(a64.dstIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AE103*/
  if(false ||(a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    CG64::mov(xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.dstIdx));
  }
  /* Col=AF103*/
  if(false ||(a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    CG64::mov(xa::VReg(a64.dstIdx).d[0], xa::VReg(a64.zTmpIdx).d[0]);
  }


  /* Col=AI103*/
  if(false ||(a64.dstWidth==64&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
    CG64::str(xa::DReg(a64.srcIdx), xa::ptr(X_TMP_ADDR));
  }













  /* Col=AW103*/
  if(false ||(a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    xt_pop_zreg();
  }






  #undef CG64
  
}
