void translateVMASKMOVPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/27 14:45 */
  #define CG64 CodeGeneratorAArch64

  /* Col=T103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=U103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }



  /* Col=Y103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CG64::lsr(xa::ZReg(a64.zTmpIdx).s, xa::ZReg(a64.srcIdx).s, 31);
  }

  /* Col=AA103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
    CG64::mov(xa::ZReg(a64.dstIdx).s, P_ALL_ONE, 0);
  }
  /* Col=AB103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CG64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, P_MSB_384.b);
  }
  /* Col=AC103*/
  if(false ||(a64.dstWidth==256&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CG64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, P_MSB_256.b);
  }


  /* Col=AF103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CG64::cmpgt(p10.s, xa::PReg(a64.pTmpIdx)/xa::T_z, xa::ZReg(a64.zTmpIdx).s, 0);
  }


  /* Col=AI103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CG64::mov(xa::PReg(a64.pTmpIdx).b, p10.b);
  }


  /* Col=AL103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
    CG64::ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
  }


  /* Col=AO103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
    CG64::mov(xa::ZReg(a64.dstIdx).s, xa::PReg(a64.pTmpIdx)/xa::T_z, xa::ZReg(a64.zTmpIdx).s);
  }
  /* Col=AP103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CG64::st1w(xa::ZReg(a64.src2Idx).s, xa::PReg(a64.pTmpIdx)/xa::T_m, xa::ptr(X_TMP_ADDR));
  }






  /* Col=AW103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    xt_pop_zreg();
  }
  /* Col=AX103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    xt_pop_preg();
  }





  #undef CG64
  
}
