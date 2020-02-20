void translateVMOVAPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);
  if (a64.dstWidth == 128) {
    CodeGeneratorAArch64::mov(xa::VReg16B(a64.dstIdx), xa::VReg16B(a64.srcIdx));
  } else if (a64.dstWidth == 256) {
    CodeGeneratorAArch64::mov(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.srcIdx));
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_256 / xa::T_m, 0);
  } else if (a64.dstWidth == 512) {
    CodeGeneratorAArch64::mov(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.srcIdx));
  }
}
