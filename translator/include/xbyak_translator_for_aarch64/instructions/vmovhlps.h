void translateVMOVHLPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/14 11:06 */

  /* Col=V103*/
  if (false || (true)) {
    CodeGeneratorAArch64::ext(xa::VReg16B(a64.dstIdx), xa::VReg16B(a64.src2Idx),
                              xa::VReg16B(a64.srcIdx), 8);
  }
}
