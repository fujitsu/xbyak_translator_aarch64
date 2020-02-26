void translateMOVDQU(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/26 09:07 */
  #define CG64 CodeGeneratorAArch64

  /* Col=T103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=U103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }

  /* Col=W103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    CG64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, P_MSB_384.b);
  }
  /* Col=X103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    CG64::ld1b(xa::ZReg(a64.zTmpIdx).b, xa::PReg(a64.pTmpIdx)/xa::T_z, xa::ptr(X_TMP_ADDR));
  }

  /* Col=Z103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)) {
    CG64::mov(xa::ZRegB(a64.dstIdx), xa::PReg(a64.pTmpIdx)/xa::T_m, xa::ZRegB(a64.srcIdx));
  }
  /* Col=AA103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    CG64::mov(xa::ZRegB(a64.dstIdx), xa::PReg(a64.pTmpIdx)/xa::T_m, xa::ZRegB(a64.zTmpIdx));
  }




  /* Col=AF103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
    CG64::str(xa::QReg(a64.srcIdx), xa::ptr(X_TMP_ADDR));
  }
















  /* Col=AW103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    xt_pop_zreg();
  }
  /* Col=AX103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_MEM&&true)) {
    xt_pop_preg();
  }





  #undef CG64
}
