void translateVMASKMOVPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

/* 2020/02/28 15:31 */
#define CG64 CodeGeneratorAArch64

  /* Col=T103*/
  if (false ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }

  /* Col=AB103*/
  if (false ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true)) {
    CG64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, P_MSB_384.b);
  }
  /* Col=AC103*/
  if (false ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true)) {
    CG64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, P_MSB_256.b);
  }

  /* Col=AG103*/
  if (false ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true)) {
    CG64::cmplt(xa::PRegS(a64.pTmpIdx), xa::PReg(a64.pTmpIdx) / xa::T_z,
                xa::ZReg(a64.srcIdx).s, 0);
  }

  /* Col=AM103*/
  if (false ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true)) {
    CG64::ld1w(xa::ZRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_z,
               xa::ptr(X_TMP_ADDR));
  }

  /* Col=AP103*/
  if (false ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true)) {
    CG64::st1w(xa::ZReg(a64.src2Idx).s, xa::PReg(a64.pTmpIdx) / xa::T_m,
               xa::ptr(X_TMP_ADDR));
  }

  /* Col=AX103*/
  if (false ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true)) {
    xt_pop_preg();
  }

#undef CG64
}
