void translateVMOVNTPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

/* 2020/02/27 17:47 */
#define CG64 CodeGeneratorAArch64
xt_reg_idx_t dstIdx;
xt_reg_idx_t srcIdx;
xt_reg_idx_t src2Idx;
xt_reg_idx_t maskIdx;
xt_reg_idx_t zTmpIdx;

/* Col=U103*/
if(false ||(a64.operands[0].opWidth==128&&true)||(a64.operands[0].opWidth==256&&true)||(a64.operands[0].opWidth==512&&true)) {
  maskIdx = xt_push_preg(&a64);
}



/* Col=Y103*/
if(false ||(a64.operands[0].opWidth==128&&true)) {
  CG64::not_(xa::PRegB(maskIdx), P_ALL_ONE/xa::T_z, P_MSB_384.b);
}
/* Col=Z103*/
if(false ||(a64.operands[0].opWidth==256&&true)) {
  CG64::not_(xa::PRegB(maskIdx), P_ALL_ONE/xa::T_z, P_MSB_256.b);
}
/* Col=AA103*/
if(false ||(a64.operands[0].opWidth==512&&true)) {
  CG64::mov(xa::PRegB(maskIdx), P_ALL_ONE.b);
}


/* Col=AD103*/
if(false ||(a64.operands[0].opWidth==128&&true)||(a64.operands[0].opWidth==256&&true)||(a64.operands[0].opWidth==512&&true)) {
  CG64::stnt1d(xa::ZRegD(a64.operands[1].regIdx), xa::PReg(maskIdx), xa::ptr(X_TMP_ADDR));
}








/* Col=AM103*/
if(false ||(a64.operands[0].opWidth==128&&true)||(a64.operands[0].opWidth==256&&true)||(a64.operands[0].opWidth==512&&true)) {
  xt_pop_preg();
}






























#undef CG64
}
