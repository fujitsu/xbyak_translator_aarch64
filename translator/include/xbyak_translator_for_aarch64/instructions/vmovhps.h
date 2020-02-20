void translateVMOVHPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/20 11:08 */

  /* Col=U103*/
  if (false || (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
                a64.src2Type == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldr(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }

  /* Col=Y103*/
  if (false || (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
                a64.src2Type == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::mov(xa::VReg2D(a64.dstIdx)[0],
                              xa::VReg2D(a64.srcIdx)[0]);
  }

  /* Col=AH103*/
  if (false || (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
                a64.src2Type == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::mov(xa::VReg2D(a64.dstIdx)[1], X_TMP_0);
  }

  /* Col=AJ103*/
  if (false || (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
                a64.src2Type == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_384 / xa::T_m, 0);
  }

  /* Col=AP103*/
  if (false ||
      (a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::st1(xa::VReg2D(a64.srcIdx)[1], xa::ptr(X_TMP_ADDR));
  }
}
