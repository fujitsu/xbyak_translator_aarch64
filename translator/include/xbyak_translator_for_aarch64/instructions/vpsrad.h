void translateVPSRAD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/03/19 11:05 */
  bool isValid = false;
#define CG64 CodeGeneratorAArch64

  /* Col=S143*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=T143*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=U143*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AA143*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true)) {
    CodeGeneratorAArch64::mov(xa::ZRegS(a64.zTmpIdx), xa::PReg(15),
                              xa::ZRegS(a64.srcIdx));
  }
  /* Col=AB143*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true)) {
    CodeGeneratorAArch64::asrd(xa::ZRegS(a64.zTmpIdx), xa::PReg(15), a64.uimm);
  }

  /* Col=AD143*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::asr(xa::ZRegS(a64.dstIdx), xa::ZRegS(a64.srcIdx),
                              a64.uimm);
  }
  /* Col=AE143*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true)) {
    CodeGeneratorAArch64::asr(xa::XReg(a64.dstIdx), xa::XReg(a64.srcIdx),
                              a64.uimm);
  }
  /* Col=AI143*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true)) {
    CodeGeneratorAArch64::mov(xa::ZRegS(a64.dstIdx), xa::PReg(15),
                              xa::ZRegS(a64.zTmpIdx));
  }
  /* Col=AJ143*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_256 / xa::T_m, 0);
  }

  /* Col=AM143*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_384 / xa::T_m, 0);
  }

  /* Col=AW143*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true)) {
    xt_pop_zreg();
  }

  /* Col=BP143*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && a64.src2Type == A64_OP_IMM && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
