void translateAND(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/04/07 10:12 */
  /* Col=S103*/
  if (false || (a64.dstWidth == 16 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG &&
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
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_IMM && true)) {
    if (std::numeric_limits<uint32_t>::max() < a64.uimm &&
        a64.uimm < ~uint64_t(0xFFFFFFFF)) {
      xt_msg_err(__FILE__, __LINE__,
                 "Invalid uimm=" + std::to_string(a64.uimm));
    }
    CodeGeneratorAArch64::and_(Xbyak_aarch64::WReg(a64.dstIdx),
                               Xbyak_aarch64::WReg(a64.dstIdx),
                               static_cast<uint32_t>(a64.uimm));
  }
  /* Col=U103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_IMM && true)) {
    if (a64.simm != 0) {
      CodeGeneratorAArch64::mov_imm(X_TMP_1, static_cast<int64_t>(a64.simm),
                                    X_TMP_0);
    } else {
      xed_uint64_t mask = ~uint64_t(0xffffffff);
      unsigned bits = (mask & a64.uimm) ? 64 : 32;
      xed_int64_t tmp = xed_sign_extend_arbitrary_to_64(a64.uimm, bits);
      CodeGeneratorAArch64::mov_imm(X_TMP_1, tmp, X_TMP_0);
    }
    CodeGeneratorAArch64::and_(Xbyak_aarch64::XReg(a64.dstIdx),
                               Xbyak_aarch64::XReg(a64.dstIdx), X_TMP_1);
  }

  /* Col=W103*/
  if (false || (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true)) {
    if (std::numeric_limits<uint32_t>::max() < a64.uimm &&
        a64.uimm < ~uint64_t(0xFFFFFFFF)) {
      xt_msg_err(__FILE__, __LINE__,
                 "Invalid uimm=" + std::to_string(a64.uimm));
    }
    xed_int64_t tmp = uint64_t(0xFFFFFFFFFFFFFF00);
    CodeGeneratorAArch64::mov_imm(X_TMP_1, tmp, X_TMP_0);
    CodeGeneratorAArch64::orr(X_TMP_1, X_TMP_1,
                              static_cast<uint32_t>(a64.uimm));
    CodeGeneratorAArch64::and_(Xbyak_aarch64::XReg(a64.dstIdx),
                               Xbyak_aarch64::XReg(a64.dstIdx), X_TMP_1);
  }
  /* Col=X103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=Y103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldr(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }

  /* Col=AB103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_IMM && true)) {
    if (std::numeric_limits<uint32_t>::max() < a64.uimm &&
        a64.uimm < ~uint64_t(0xFFFFFFFF)) {
      xt_msg_err(__FILE__, __LINE__,
                 "Invalid uimm=" + std::to_string(a64.uimm));
    }
    CodeGeneratorAArch64::and_(W_TMP_0, W_TMP_0,
                               static_cast<uint32_t>(a64.uimm));
  }
  /* Col=AC103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_IMM && true)) {
    CodeGeneratorAArch64::and_(X_TMP_0, X_TMP_0, a64.uimm);
  }

  /* Col=AF103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::and_(xa::WReg(a64.dstIdx), xa::WReg(a64.dstIdx),
                               xa::WReg(a64.srcIdx));
  }
  /* Col=AG103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::and_(xa::XReg(a64.dstIdx), xa::XReg(a64.dstIdx),
                               xa::XReg(a64.srcIdx));
  }

  /* Col=AK103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::and_(W_TMP_0, W_TMP_0, xa::WReg(a64.srcIdx));
  }
  /* Col=AL103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::and_(X_TMP_0, X_TMP_0, xa::XReg(a64.srcIdx));
  }

  /* Col=AR103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::and_(xa::WReg(a64.dstIdx), xa::WReg(a64.dstIdx),
                               W_TMP_0);
  }
  /* Col=AS103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::and_(xa::XReg(a64.dstIdx), xa::XReg(a64.dstIdx),
                               X_TMP_0);
  }

  /* Col=AU103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::str(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AV103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::str(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }
}
