void translateSHL(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

/* 2020/02/26 18:41 */
#define CG64 CodeGeneratorAArch64







/* Col=Z103*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==64&&true)) {
  CG64::lsl(xa::XReg(a64.operands[0].regIdx), xa::XReg(a64.operands[0].regIdx), a64.operands[1].uimm%64);
}
/* Col=AA103*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_IMM0&&a64.operands[0].opWidth==32&&true)) {
  CG64::lsl(xa::WReg(a64.operands[0].regIdx), xa::WReg(a64.operands[0].regIdx), a64.operands[1].uimm%32);
}


/* Col=AD103*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[0].opWidth==64&&true)) {
  CG64::lsl(xa::XReg(a64.operands[0].regIdx), xa::XReg(a64.operands[0].regIdx), xa::XReg(a64.operands[1].regIdx));
}
/* Col=AE103*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[0].opWidth==32&&true)) {
  CG64::lsl(xa::WReg(a64.operands[0].regIdx), xa::WReg(a64.operands[0].regIdx), xa::WReg(a64.operands[1].regIdx));
}
























#undef CG64
}
