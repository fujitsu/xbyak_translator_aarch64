void translateMOVSD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/03/12 11:47 */
  bool isValid = false;
#define CG64 CodeGeneratorAArch64

  /* Col=T103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=U103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }

  /* Col=Y103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    CG64::ptrue(xa::PReg(a64.pTmpIdx).d, xa::VL1);
  }
  /* Col=Z103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    CG64::ptrue(xa::PReg(a64.pTmpIdx).d, xa::VL2);
  }
  /* Col=AA103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    CG64::ldr(xa::DReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AB103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    CG64::mov(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_m,
              xa::ZRegD(a64.srcIdx));
  }
  /* Col=AC103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    CG64::mov(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_m,
              xa::ZRegD(a64.zTmpIdx));
  }

  /* Col=AF103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_REG && true)) {
    CG64::str(xa::DReg(a64.srcIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AW103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    xt_pop_zreg();
  }
  /* Col=AX103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    xt_pop_preg();
  }
  /* Col=AY103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true)) {
    XT_VALID_CHECK;
  }

  XT_VALID_CHECK_IF
#undef CG64
}
