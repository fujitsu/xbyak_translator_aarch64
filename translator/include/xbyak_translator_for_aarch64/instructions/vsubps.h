void translateVSUBPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

/* 2020/02/27 09:25 */
#define CG64 CodeGeneratorAArch64
  /* Col=S103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=T103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=U103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=V103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    CG64::ld1(xa::VReg(a64.zTmpIdx).s4, xa::ptr(X_TMP_ADDR));
  }
  /* Col=W103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    CG64::ld1r(xa::VReg(a64.zTmpIdx).s4, xa::ptr(X_TMP_ADDR));
  }
  /* Col=X103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    CG64::ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=Y103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    CG64::ld1rw(xa::ZReg(a64.zTmpIdx).s, xa::PReg(a64.maskIdx) / xa::T_z,
                xa::ptr(X_TMP_ADDR));
  }
  /* Col=Z103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    CG64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE.b, xa::PRegB(a64.maskIdx));
  }
  /* Col=AA103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    CG64::orn(xa::PRegB(a64.pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_256.b,
              xa::PRegB(a64.maskIdx));
  }
  /* Col=AB103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    CG64::orn(xa::PRegB(a64.pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_384.b,
              xa::PRegB(a64.maskIdx));
  }
  /* Col=AC103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true)) {
    CG64::fsub(xa::VReg(a64.dstIdx).s4, xa::VReg(a64.srcIdx).s4,
               xa::VReg(a64.src2Idx).s4);
  }
  /* Col=AD103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    CG64::fsub(xa::VReg(a64.dstIdx).s4, xa::VReg(a64.srcIdx).s4,
               xa::VReg(a64.zTmpIdx).s4);
  }
  /* Col=AE103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true)) {
    CG64::fsub(xa::ZReg(a64.dstIdx).s, xa::ZReg(a64.srcIdx).s,
               xa::ZReg(a64.src2Idx).s);
  }
  /* Col=AF103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    CG64::fsub(xa::ZReg(a64.dstIdx).s, xa::ZReg(a64.srcIdx).s,
               xa::ZReg(a64.zTmpIdx).s);
  }
  /* Col=AG103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true)) {
    CG64::fsub(xa::ZReg(a64.zTmpIdx).s, xa::ZReg(a64.srcIdx).s,
               xa::ZReg(a64.src2Idx).s);
  }
  /* Col=AH103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    CG64::fsub(xa::ZReg(a64.zTmpIdx).s, xa::ZReg(a64.srcIdx).s,
               xa::ZReg(a64.zTmpIdx).s);
  }

  /* Col=AJ103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    xt_pop_zreg();
  }
  /* Col=AK103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    CG64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_256 / xa::T_m, 0);
  }
  /* Col=AL103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    CG64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_384 / xa::T_m, 0);
  }
  /* Col=AM103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    CG64::mov(xa::ZReg(a64.dstIdx).s, xa::PReg(a64.pTmpIdx) / xa::T_m, 0);
  }
  /* Col=AN103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    CG64::mov(xa::ZRegS(a64.dstIdx), xa::PReg(a64.maskIdx) / xa::T_m,
              xa::ZRegS(a64.zTmpIdx));
  }
  /* Col=AO103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    xt_pop_zreg(); // In some cases, xt_pop_zreg() should be called here.
  }

  /* Col=AQ103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
       a64.src2Type == A64_OP_MEM && true)) {
    xt_pop_preg();
  }

#undef CG64
}