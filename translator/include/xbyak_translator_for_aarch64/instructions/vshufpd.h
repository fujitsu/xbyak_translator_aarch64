void translateVSHUFPD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/03/25 14:28 */
  bool isValid = false;
#define CG64 CodeGeneratorAArch64
  /* Col=S103*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
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
       a64.src2Type == A64_OP_REG && true) ||
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
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=V103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }

  /* Col=X103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.zTmpIdx).s, xa::PReg(15),
                              xa::ZReg(a64.srcIdx).s);
    if ((a64.uimm & 0x1) != 0) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
    }
  }
  /* Col=Y103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x2) / 2) == 0) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.src2Idx),
                                56);
    } else {
      CodeGeneratorAArch64::zip1(xa::PRegD(a64.pTmpIdx), xa::PRegD(13),
                                 xa::PRegD(15));
      CodeGeneratorAArch64::mov(xa::ZRegD(a64.zTmpIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegD(a64.src2Idx));
    }
  }
  /* Col=Z103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x4) / 4) == 0) {
      CodeGeneratorAArch64::mov(xa::ZRegD(a64.zTmpIdx), xa::PReg(14),
                                xa::ZRegD(a64.srcIdx));
    } else {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
      CodeGeneratorAArch64::zip1(xa::PRegD(a64.pTmpIdx), xa::PRegD(13),
                                 xa::PRegD(15));
      CodeGeneratorAArch64::and_(xa::PRegB(a64.pTmpIdx), xa::PReg(15),
                                 xa::PRegB(a64.pTmpIdx), xa::PRegB(14));
      CodeGeneratorAArch64::mov(xa::ZRegD(a64.zTmpIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegD(a64.srcIdx));
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
    }
  }
  /* Col=AA103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x8) / 8) == 0) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
      CodeGeneratorAArch64::eor(xa::PRegB(a64.pTmpIdx), xa::PReg(15),
                                xa::PRegB(13), xa::PRegB(14));
      CodeGeneratorAArch64::mov(xa::ZRegD(a64.zTmpIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegD(a64.src2Idx));
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
    } else {
      CodeGeneratorAArch64::zip1(xa::PRegD(a64.pTmpIdx), xa::PRegD(13),
                                 xa::PRegD(15));
      CodeGeneratorAArch64::and_(xa::PRegB(a64.pTmpIdx), xa::PReg(15),
                                 xa::PRegB(a64.pTmpIdx), xa::PRegB(14));
      CodeGeneratorAArch64::mov(xa::ZRegD(a64.zTmpIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegD(a64.src2Idx));
    }
  }

  /* Col=AX103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::ZRegB(a64.dstIdx), xa::PReg(15),
                              xa::ZRegB(a64.zTmpIdx));
  }

  /* Col=AZ103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_256 / xa::T_m, 0);
  }

  /* Col=BB103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    xt_pop_preg();
  }
  /* Col=BC103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    xt_pop_zreg();
  }
}
