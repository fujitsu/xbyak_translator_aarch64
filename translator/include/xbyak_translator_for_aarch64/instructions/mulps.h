void translateMULPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);
#define CG64 CodeGeneratorAArch64
  a64.zTmpIdx = xt_push_zreg(&a64);
  a64.pTmpIdx = xt_push_preg(&a64);
  CG64::mov(xa::PRegB(a64.pTmpIdx), P_MSB_384.b);
  CG64::mov(xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.dstIdx));
  // CG64::fmul(xa::VReg(a64.dstIdx).s4, xa::VReg(a64.dstIdx).s4,
  // xa::VReg(a64.srcIdx).s4);
  CG64::fmul(xa::ZRegS(a64.dstIdx), xa::ZRegS(a64.dstIdx),
             xa::ZRegS(a64.srcIdx));
  CG64::mov(xa::ZRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_m,
            xa::ZRegS(a64.zTmpIdx));
  xt_pop_preg();
  xt_pop_zreg();
}
