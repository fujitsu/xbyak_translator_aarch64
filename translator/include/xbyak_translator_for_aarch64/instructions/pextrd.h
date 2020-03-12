void translatePEXTRD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

/* 2020/03/11 15:39 */
#define CG64 CodeGeneratorAArch64
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;
  xed_uint64_t uimm;
  uint32_t sel;

  /* Col=W103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=X103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }

  /* Col=AB103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 && true)) {
    uimm = a64.operands[2].uimm;
  }

  /* Col=AE103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 && true)) {
    sel = uimm & 3;
  }
  /* Col=AF103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true)) {
    CG64::mov(xa::WReg(dstIdx), xa::VReg(srcIdx).s[sel]);
  }
  /* Col=AG103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 && true)) {
    CG64::mov(W_TMP_0, xa::VReg(srcIdx).s[sel]);
  }
  /* Col=AH103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 && true)) {
    CG64::str(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }

#undef CG64
}
