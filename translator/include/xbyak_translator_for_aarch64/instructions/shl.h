void translateSHL(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);
  CodeGeneratorAArch64::lsl(xa::XReg(a64.dstIdx), xa::XReg(a64.dstIdx),
                            a64.uimm);
}
