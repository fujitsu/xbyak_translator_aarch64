void translateVBLENDVPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/28 08:23 */
  #define CG64 CodeGeneratorAArch64
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;
  xt_reg_idx_t src2Idx;
  xt_reg_idx_t src3Idx;
  xt_reg_idx_t maskIdx;
  xt_reg_idx_t zTmpIdx;

  /* Col=U103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    maskIdx = xt_push_preg(&a64);
  }

  /* Col=W103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }






  /* Col=AD103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AE103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AF103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AG103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    src3Idx = a64.operands[3].regIdx;
  }








  /* Col=AP103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    CG64::lsr(xa::ZReg(zTmpIdx).s, xa::ZReg(src3Idx).s, 31);
  }
  /* Col=AQ103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    CG64::cmpgt(p10.s, xa::PReg(maskIdx)/xa::T_z, xa::ZReg(zTmpIdx).s, 0);
  }

  /* Col=AS103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    CG64::ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AU103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    CG64::mov(xa::ZReg(dstIdx).s, p10/xa::T_m, xa::ZReg(zTmpIdx).s);
  }
  /* Col=AV103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&true)) {
    CG64::mov(xa::ZReg(dstIdx).s, p10/xa::T_m, xa::ZReg(src2Idx).s);
  }
  /* Col=AW103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    CG64::not_(xa::PRegB(maskIdx), P_ALL_ONE, p10.b);
  }
  /* Col=AX103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    CG64::mov(xa::ZReg(dstIdx).s, xa::PReg(maskIdx)/xa::T_m, xa::ZReg(srcIdx).s);
  }


  /* Col=BA103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    CG64::mov(xa::ZReg(dstIdx).s, P_MSB_384/xa::T_m, 0);
  }







  /* Col=BI103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    xt_pop_zreg();
  }
  /* Col=BJ103*/
  if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==128&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_REG2&&a64.operands[0].opWidth==256&&true)) {
    xt_pop_preg();
  }







  #undef CG64
  
}
