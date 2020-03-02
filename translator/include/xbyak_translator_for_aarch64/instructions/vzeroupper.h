void translateVZEROUPPER(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

/* 2020/02/21 23:29 */
#define CG64 CodeGeneratorAArch64

  /* Col=X103*/
  if (false || (true)) {
    for (int i = 0; i < 16; i++) {
      CG64::mov(xa::ZRegD(i), P_MSB_384 / xa::T_m, 0);
    }
  }

#undef CG64
}
