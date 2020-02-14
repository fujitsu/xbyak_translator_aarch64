void translateVMOVHLPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/14 14:03 */

  /* Col=V103*/
  if (false || (true)) {
    CodeGeneratorAArch64::mov(xa::VReg2D(a64.dstIdx)[1],
                              xa::VReg2D(a64.srcIdx)[1]);
  }
  /* Col=W103*/
  if (false || (true)) {
    CodeGeneratorAArch64::mov(xa::VReg2D(a64.dstIdx)[0],
                              xa::VReg2D(a64.src2Idx)[1]);
  }
}
