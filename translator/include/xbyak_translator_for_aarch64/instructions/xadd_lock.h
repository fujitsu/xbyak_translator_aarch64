void translateXADD_LOCK(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

/* 2020/02/26 22:49 */
#define CG64 CodeGeneratorAArch64
/* Col=S103*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[0].opWidth==8&&true)||(a64.operands[0].opName==XED_OPERAND_MEM0&&a64.operands[1].opName==XED_OPERAND_REG0&&a64.operands[0].opWidth==8&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[0].opWidth==16&&true)||(a64.operands[0].opName==XED_OPERAND_MEM0&&a64.operands[1].opName==XED_OPERAND_REG0&&a64.operands[0].opWidth==16&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[0].opWidth==32&&true)||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[0].opWidth==64&&true)) {
  XT_UNIMPLEMENTED;
}






/* Col=Z103*/
if(false ||(a64.operands[0].opName==XED_OPERAND_MEM0&&a64.operands[1].opName==XED_OPERAND_REG0&&a64.operands[0].opWidth==32&&true)) {
  CG64::ldadd(xa::WReg(a64.operands[1].regIdx), xa::WReg(a64.operands[1].regIdx), xa::ptr(X_TMP_ADDR));
}
/* Col=AA103*/
if(false ||(a64.operands[0].opName==XED_OPERAND_MEM0&&a64.operands[1].opName==XED_OPERAND_REG0&&a64.operands[0].opWidth==64&&true)) {
  CG64::ldadd(xa::XReg(a64.operands[1].regIdx), xa::XReg(a64.operands[1].regIdx), xa::ptr(X_TMP_ADDR));
}




























#undef CG64
}
