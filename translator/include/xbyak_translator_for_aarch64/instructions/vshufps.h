void translateVSHUFPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/09/29 15:35 */
  /* Col=S103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=U103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }

  /* Col=X103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_ALL_ONE,
                              xa::ZReg(a64.srcIdx).s);
    if ((a64.uimm & 0x3) == 1) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
    if ((a64.uimm & 0x3) == 2) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
    }
    if ((a64.uimm & 0x3) == 3) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                12);
    }
  }
  /* Col=Y103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc) / 4) == 0) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.srcIdx),
                                60);
    }
    if (((a64.uimm & 0xc) / 4) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
    }
    if (((a64.uimm & 0xc) / 4) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_384.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
    if (((a64.uimm & 0xc) / 4) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
    }
  }
  /* Col=Z103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x30) / 16) == 0) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.src2Idx),
                                56);
    }
    if (((a64.uimm & 0x30) / 16) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
    }
    if (((a64.uimm & 0x30) / 16) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
    }
    if (((a64.uimm & 0x30) / 16) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
  }
  /* Col=AA103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc0) / 64) == 0) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                12);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.src2Idx),
                                52);
    }
    if (((a64.uimm & 0xc0) / 64) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
    }
    if (((a64.uimm & 0xc0) / 64) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
    }
    if (((a64.uimm & 0xc0) / 64) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
    }
  }
  /* Col=AB103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 0) {
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_MSB_384,
                                xa::ZReg(a64.srcIdx).s);
    }
    if ((a64.uimm & 0x3) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
    if ((a64.uimm & 0x3) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
    }
    if ((a64.uimm & 0x3) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                52);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                12);
    }
  }
  /* Col=AC103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc) / 4) == 0) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
    }
    if (((a64.uimm & 0xc) / 4) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
    }
    if (((a64.uimm & 0xc) / 4) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
    if (((a64.uimm & 0xc) / 4) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
    }
  }
  /* Col=AD103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x30) / 16) == 0) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
    }
    if (((a64.uimm & 0x30) / 16) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
    }
    if (((a64.uimm & 0x30) / 16) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
    }
    if (((a64.uimm & 0x30) / 16) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
  }
  /* Col=AE103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc0) / 64) == 0) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                12);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                52);
    }
    if (((a64.uimm & 0xc0) / 64) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
    }
    if (((a64.uimm & 0xc0) / 64) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
    }
    if (((a64.uimm & 0xc0) / 64) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
    }
  }

  /* Col=AG103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 0) {
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_MSB_256,
                                xa::ZReg(a64.srcIdx).s);
    }
    if ((a64.uimm & 0x3) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
    if ((a64.uimm & 0x3) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
    }
    if ((a64.uimm & 0x3) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                52);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                12);
    }
  }
  /* Col=AH103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc) / 4) == 0) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
    }
    if (((a64.uimm & 0xc) / 4) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
    }
    if (((a64.uimm & 0xc) / 4) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
    if (((a64.uimm & 0xc) / 4) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
    }
  }
  /* Col=AI103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x30) / 16) == 0) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
    }
    if (((a64.uimm & 0x30) / 16) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
    }
    if (((a64.uimm & 0x30) / 16) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
    }
    if (((a64.uimm & 0x30) / 16) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
  }
  /* Col=AJ103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc0) / 64) == 0) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                12);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                52);
    }
    if (((a64.uimm & 0xc0) / 64) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
    }
    if (((a64.uimm & 0xc0) / 64) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
    }
    if (((a64.uimm & 0xc0) / 64) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
    }
  }
  /* Col=AK103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 0) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
    }
    if ((a64.uimm & 0x3) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
    if ((a64.uimm & 0x3) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
    }
    if ((a64.uimm & 0x3) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                52);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                12);
    }
  }
  /* Col=AL103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc) / 4) == 0) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
    }
    if (((a64.uimm & 0xc) / 4) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
    }
    if (((a64.uimm & 0xc) / 4) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
    if (((a64.uimm & 0xc) / 4) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
    }
  }
  /* Col=AM103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x30) / 16) == 0) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
    }
    if (((a64.uimm & 0x30) / 16) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
    }
    if (((a64.uimm & 0x30) / 16) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
    }
    if (((a64.uimm & 0x30) / 16) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
  }
  /* Col=AN103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc0) / 64) == 0) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                12);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                52);
    }
    if (((a64.uimm & 0xc0) / 64) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
    }
    if (((a64.uimm & 0xc0) / 64) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
    }
    if (((a64.uimm & 0xc0) / 64) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->and_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.src2Idx).s);
    }
  }

  /* Col=AX103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    xa_->mov(xa::ZRegB(a64.dstIdx), P_ALL_ONE,
                              xa::ZRegB(a64.zTmpIdx));
  }
  /* Col=AY103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    xa_->mov(xa::ZReg(a64.dstIdx).s, P_MSB_384 / xa::T_m, 0);
  }
  /* Col=AZ103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    xa_->mov(xa::ZReg(a64.dstIdx).s, P_MSB_256 / xa::T_m, 0);
  }

  /* Col=BC103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    xt_pop_zreg();
  }
}
