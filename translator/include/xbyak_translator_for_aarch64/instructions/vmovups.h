void translateVMOVUPS(xed_decoded_inst_t *p) {
  // unsigned int i, noperands, dstIdx, srcIdx;
  const xed_inst_t *xi = xed_decoded_inst_inst(p);

  const xed_operand_t *op1 =
      xed_inst_operand(xi, 0); // dstのオペランドのポインタを取得
  const xed_operand_t *op2 =
      xed_inst_operand(xi, 1); // dstのオペランドのポインタを取得
  xed_operand_enum_t isDst =
      xed_operand_name(op1); // dstのオペランドの名前を取得
  xed_operand_enum_t isSrc =
      xed_operand_name(op2); // srcのオペランドの名前を取得

  xed_uint_t dstWidth = xed_decoded_inst_operand_length_bits(p, 0);
  // xed_uint_t isSrcSize = xed_decoded_inst_operand_length_bits(p, 1);

  const xed_reg_class_enum_t DstRegClass =
      xed_reg_class(xed_decoded_inst_get_reg(p, isDst));
  const xed_reg_class_enum_t SrcRegClass =
      xed_reg_class(xed_decoded_inst_get_reg(p, isSrc));

  unsigned int a64_dstIdx;
  unsigned int a64_srcIdx;
  unsigned int a64_maskIdx;

  bool isMasking;
  bool isMerging;
  bool isZeroing;

  if (false ||
      (dstWidth == 128 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1) ||
      (dstWidth == 128 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1) ||
      (dstWidth == 128 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1) ||
      (dstWidth == 128 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m,
          Xbyak_aarch64::ZReg(a64_srcIdx).s);
    mov__(pTmp.b, p14.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_MEM0) ||
      (dstWidth == 128 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    ld1b(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    mov__(pTmp.b, p14.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_MEM0 && isSrc == XED_OPERAND_REG0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p14.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    mov__(pTmp.b, p15.b);
    st1b(Xbyak_aarch64::ZReg(a64_srcIdx).s, pTmp / Xbyak_aarch64::T_m,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1) ||
      (dstWidth == 256 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1) ||
      (dstWidth == 256 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1) ||
      (dstWidth == 256 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m,
          Xbyak_aarch64::ZReg(a64_srcIdx).s);
    mov__(pTmp.b, p13.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_MEM0) ||
      (dstWidth == 256 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    ld1b(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    mov__(pTmp.b, p13.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_MEM0 && isSrc == XED_OPERAND_REG0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p13.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    mov__(pTmp.b, p15.b);
    st1b(Xbyak_aarch64::ZReg(a64_srcIdx).s, pTmp / Xbyak_aarch64::T_m,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1) ||
      (dstWidth == 128 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1)) {
    not_(p8.b, p15 / Xbyak_aarch64::T_z, Xbyak_aarch64::PReg(a64_maskIdx).b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s,
          Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
          Xbyak_aarch64::ZReg(a64_srcIdx).s);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p8 / Xbyak_aarch64::T_m, 0);
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p14.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    not_(p8.b, p15 / Xbyak_aarch64::T_z, Xbyak_aarch64::PReg(a64_maskIdx).b);
    ld1b(Xbyak_aarch64::ZReg(a64_dstIdx).s,
         Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p8 / Xbyak_aarch64::T_m, 0);
    mov__(pTmp.b, p14.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1) ||
      (dstWidth == 128 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1)) {
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s,
          Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
          Xbyak_aarch64::ZReg(a64_srcIdx).s);
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p14.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    ld1b(zTmp.s, Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s,
          Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m, zTmp.s);
    xt_pop_zreg();
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p14.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1) ||
      (dstWidth == 256 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1)) {
    not_(p8.b, p15 / Xbyak_aarch64::T_z, Xbyak_aarch64::PReg(a64_maskIdx).b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s,
          Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
          Xbyak_aarch64::ZReg(a64_srcIdx).s);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p8 / Xbyak_aarch64::T_m, 0);
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p13.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_MEM0)) {
    not_(p8.b, p15 / Xbyak_aarch64::T_z, Xbyak_aarch64::PReg(a64_maskIdx).b);
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    ld1b(Xbyak_aarch64::ZReg(a64_dstIdx).s,
         Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p8 / Xbyak_aarch64::T_m, 0);
    mov__(pTmp.b, p13.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1) ||
      (dstWidth == 256 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1)) {
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s,
          Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
          Xbyak_aarch64::ZReg(a64_srcIdx).s);
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p13.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    ld1b(zTmp.s, Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s,
          Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m, zTmp.s);
    mov__(pTmp.b, p13.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
    xt_pop_zreg();
  }
  if (false ||
      (dstWidth == 512 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1) ||
      (dstWidth == 512 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m,
          Xbyak_aarch64::ZReg(a64_srcIdx).s);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 512 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    ld1b(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_z,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 512 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1) ||
      (dstWidth == 512 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1)) {
    not_(p8.b, p15 / Xbyak_aarch64::T_z, Xbyak_aarch64::PReg(a64_maskIdx).b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s,
          Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
          Xbyak_aarch64::ZReg(a64_srcIdx).s);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p8 / Xbyak_aarch64::T_m, 0);
  }
  if (false ||
      (dstWidth == 512 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_MEM0)) {
    not_(p8.b, p15 / Xbyak_aarch64::T_z, Xbyak_aarch64::PReg(a64_maskIdx).b);
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    ld1b(Xbyak_aarch64::ZReg(a64_dstIdx).s,
         Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, p8 / Xbyak_aarch64::T_m, 0);
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 512 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1) ||
      (dstWidth == 512 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_REG1)) {
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s,
          Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
          Xbyak_aarch64::ZReg(a64_srcIdx).s);
  }
  if (false ||
      (dstWidth == 512 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_REG0 && isSrc == XED_OPERAND_MEM0)) {
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    ld1b(zTmp.s, Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s,
          Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m, zTmp.s);
    xt_pop_zreg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_MEM0 && isSrc == XED_OPERAND_REG0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p14.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    mov__(pTmp.b, p15.b);
    st1b(Xbyak_aarch64::ZReg(a64_srcIdx).s, pTmp / Xbyak_aarch64::T_m,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_MEM0 && isSrc == XED_OPERAND_REG0)) {
    not_(p8.b, p15 / Xbyak_aarch64::T_z, Xbyak_aarch64::PReg(a64_maskIdx).b);
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(zTmp.s, Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
          Xbyak_aarch64::ZReg(a64_srcIdx).s);
    mov__(zTmp.s, p8 / Xbyak_aarch64::T_z, 0);
    mov__(pTmp.b, p14.b);
    mov__(zTmp.s, pTmp / Xbyak_aarch64::T_m, 0);
    mov__(pTmp.b, p15.b);
    st1b(zTmp.s, pTmp / Xbyak_aarch64::T_m, Xbyak_aarch64::ptr(X_TMP_ADDR));
    xt_pop_zreg();
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 128 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_MEM0 && isSrc == XED_OPERAND_REG0)) {
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    mov__(zTmp.s, pTmp / Xbyak_aarch64::T_m, Xbyak_aarch64::ZReg(a64_srcIdx).s);
    mov__(pTmp.b, p14.b);
    mov__(zTmp.s, pTmp / Xbyak_aarch64::T_m, 0);
    st1b(zTmp.s, Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    xt_pop_zreg();
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_MEM0 && isSrc == XED_OPERAND_REG0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p13.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).s, pTmp / Xbyak_aarch64::T_m, 0);
    mov__(pTmp.b, p15.b);
    st1b(Xbyak_aarch64::ZReg(a64_srcIdx).s, pTmp / Xbyak_aarch64::T_m,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_MEM0 && isSrc == XED_OPERAND_REG0)) {
    not_(p8.b, p15 / Xbyak_aarch64::T_z, Xbyak_aarch64::PReg(a64_maskIdx).b);
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(zTmp.s, Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
          Xbyak_aarch64::ZReg(a64_srcIdx).s);
    mov__(zTmp.s, p8 / Xbyak_aarch64::T_z, 0);
    mov__(pTmp.b, p13.b);
    mov__(zTmp.s, pTmp / Xbyak_aarch64::T_m, 0);
    mov__(pTmp.b, p15.b);
    st1b(zTmp.s, pTmp / Xbyak_aarch64::T_m, Xbyak_aarch64::ptr(X_TMP_ADDR));
    xt_pop_zreg();
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 256 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_MEM0 && isSrc == XED_OPERAND_REG0)) {
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    mov__(zTmp.s, pTmp / Xbyak_aarch64::T_m, Xbyak_aarch64::ZReg(a64_srcIdx).s);
    mov__(pTmp.b, p13.b);
    mov__(zTmp.s, pTmp / Xbyak_aarch64::T_m, 0);
    st1b(zTmp.s, Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    xt_pop_zreg();
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 512 && isMasking == 0 && isMerging == 0 && isZeroing == 0 &&
       isDst == XED_OPERAND_MEM0 && isSrc == XED_OPERAND_REG0)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    st1b(Xbyak_aarch64::ZReg(a64_srcIdx).s, pTmp / Xbyak_aarch64::T_m,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 512 && isMasking == 1 && isMerging == 0 && isZeroing == 1 &&
       isDst == XED_OPERAND_MEM0 && isSrc == XED_OPERAND_REG0)) {
    not_(p8.b, p15 / Xbyak_aarch64::T_z, Xbyak_aarch64::PReg(a64_maskIdx).b);
    Xbyak_aarch64::ZReg zTmp = xt_push_zreg();
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    mov__(zTmp.s, Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
          Xbyak_aarch64::ZReg(a64_srcIdx).s);
    mov__(zTmp.s, p8 / Xbyak_aarch64::T_z, 0);
    st1b(zTmp.s, pTmp / Xbyak_aarch64::T_m, Xbyak_aarch64::ptr(X_TMP_ADDR));
    xt_pop_zreg();
    xt_pop_preg();
  }
  if (false ||
      (dstWidth == 512 && isMasking == 1 && isMerging == 1 && isZeroing == 0 &&
       isDst == XED_OPERAND_MEM0 && isSrc == XED_OPERAND_REG0)) {
    st1b(Xbyak_aarch64::ZReg(a64_srcIdx).s,
         Xbyak_aarch64::PReg(a64_maskIdx) / Xbyak_aarch64::T_m,
         Xbyak_aarch64::ptr(X_TMP_ADDR));
  }
}