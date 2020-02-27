void translateLEA(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

/* 2020/02/27 08:57 */
#define CG64 CodeGeneratorAArch64





/* Col=X103*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[0].opWidth==16&&true)) {
  CG64::and_(xa::XReg(a64.operands[0].regIdx), X_TMP_ADDR, 0xffff);
}
/* Col=Y103*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[0].opWidth==32&&true)) {
  CG64::and_(xa::XReg(a64.operands[0].regIdx), X_TMP_ADDR, 0xffffffff);
}
/* Col=Z103*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[0].opWidth==64&&true)) {
  CG64::mov(xa::XReg(a64.operands[0].regIdx), X_TMP_ADDR);
}





























#undef CG64
}
