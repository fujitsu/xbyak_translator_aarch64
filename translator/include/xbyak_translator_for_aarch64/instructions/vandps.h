void translateVANDPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

if(a64.dstWidth==256 && a64.PredType==A64_PRED_INIT && a64.EVEXb == 0
   && a64.dstType==A64_OP_REG && a64.srcType==A64_OP_REG ) {
	a64.zTmpIdx = xt_push_zreg();
	CodeGeneratorAArch64::ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
	CodeGeneratorAArch64::and_(xa::ZReg(a64.dstIdx).d,xa::ZReg(a64.srcIdx).d, xa::ZReg(a64.zTmpIdx).d);
	xt_pop_zreg();
	CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).d, P_MSB_256/xa::T_m, 0);
}


























}
