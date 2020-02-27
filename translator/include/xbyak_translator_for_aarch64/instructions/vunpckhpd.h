void translateVUNPCKHPD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/27 10:27 */
#define CG64 CodeGeneratorAArch64
  /* Col=S103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=Y103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CG64::trn2(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.srcIdx), xa::ZRegD(a64.src2Idx));
  }
  /* Col=AE103*/
  if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CG64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_384/xa::T_m, 0);
  }
  /* Col=AK103*/
  if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CG64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_256/xa::T_m, 0);
  }
#undef CG64
}
