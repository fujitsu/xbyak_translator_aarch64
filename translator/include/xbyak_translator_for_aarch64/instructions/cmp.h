void translateCMP(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/21 19:26 */
  /* Col=S103*/
  if (false ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=T103*/
  if (false ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true)) {
    uint32_t uimm32 = static_cast<uint32_t>(a64.uimm & uint64_t(0xFFFFFFFF));
    CodeGeneratorAArch64::mov_imm(W_TMP_0, uimm32, W_TMP_1);
  }
  /* Col=U103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true)) {
    CodeGeneratorAArch64::mov_imm(X_TMP_0, a64.uimm, X_TMP_1);
  }

  /* Col=Y103*/
  if (false ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldr(W_TMP_2, xa::ptr(X_TMP_ADDR));
  }
  /* Col=Z103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldr(X_TMP_2, xa::ptr(X_TMP_ADDR));
  }

  /* Col=AQ103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_IMM && true)) {
    CodeGeneratorAArch64::cmp(xa::WReg(a64.dstIdx), W_TMP_0);
  }
  /* Col=AR103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_IMM && true)) {
    CodeGeneratorAArch64::cmp(xa::XReg(a64.dstIdx), X_TMP_0);
  }
  /* Col=AS103*/
  if (false ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::cmp(W_TMP_2, W_TMP_0);
  }
  /* Col=AT103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::cmp(X_TMP_2, X_TMP_0);
  }
  /* Col=AU103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::cmp(xa::WReg(a64.dstIdx), xa::WReg(a64.srcIdx));
  }
  /* Col=AV103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::cmp(xa::XReg(a64.dstIdx), xa::XReg(a64.srcIdx));
  }
  /* Col=AW103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::cmp(xa::WReg(a64.dstIdx), W_TMP_2);
  }
  /* Col=AX103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::cmp(xa::XReg(a64.dstIdx), X_TMP_2);
  }
  /* Col=AY103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::cmp(W_TMP_2, xa::WReg(a64.srcIdx));
  }
  /* Col=AZ103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::cmp(X_TMP_2, xa::XReg(a64.srcIdx));
  }
}
