void translateMULPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);
  CodeGeneratorAArch64::fmul(xa::VReg(a64.dstIdx).s4, xa::VReg(a64.dstIdx).s4,
                             xa::VReg(a64.srcIdx).s4);
  // XT_UNIMPLEMENTED;
}
