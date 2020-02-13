void translateVMOVLPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);
  xt_dump_a64fx_operands(&a64);
  if (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM) {
    a64.vTmpIdx = xt_push_vreg(&a64);
    CodeGeneratorAArch64::mov(xa::VReg2D(a64.dstIdx)[1], xa::VReg2D(a64.srcIdx)[1]);
    CodeGeneratorAArch64::ldr(xa::ZReg(a64.vTmpIdx), xa::ptr(X_TMP_ADDR));
    CodeGeneratorAArch64::mov(xa::VReg2D(a64.dstIdx)[0], xa::VReg2D(a64.vTmpIdx)[0]);
    xt_pop_vreg();
  } else if (a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG) {
    CodeGeneratorAArch64::str(xa::ZReg(a64.srcIdx), xa::ptr(X_TMP_ADDR));
  }
}
