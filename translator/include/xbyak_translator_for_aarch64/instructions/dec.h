void translateDEC(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/17 16:21 */
  /* Col=S103*/
  if (false || (a64.dstWidth == 8 && a64.dstType == A64_OP_REG && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=Y103*/
  if (false || (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldrb(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=Z103*/
  if (false || (a64.dstWidth == 16 && a64.dstType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldrh(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AA103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AB103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldr(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AC103*/
  if (false || (a64.dstWidth == 8 && a64.dstType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::decb(xa::XReg(a64.dstIdx));
  }
  /* Col=AD103*/
  if (false || (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::decb(X_TMP_0);
  }
  /* Col=AE103*/
  if (false || (a64.dstWidth == 16 && a64.dstType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::dech(xa::XReg(a64.dstIdx));
  }
  /* Col=AF103*/
  if (false || (a64.dstWidth == 16 && a64.dstType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::dech(X_TMP_0);
  }
  /* Col=AG103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::sub(xa::WReg(a64.dstIdx), xa::WReg(a64.dstIdx), 1);
  }
  /* Col=AH103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::sub(W_TMP_0, W_TMP_0, 1);
  }
  /* Col=AI103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::sub(xa::XReg(a64.dstIdx), xa::XReg(a64.dstIdx), 1);
  }
  /* Col=AJ103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::sub(X_TMP_0, X_TMP_0, 1);
  }

  /* Col=AL103*/
  if (false || (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::strb(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AM103*/
  if (false || (a64.dstWidth == 16 && a64.dstType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::strh(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AN103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::str(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AO103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::str(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }
}
