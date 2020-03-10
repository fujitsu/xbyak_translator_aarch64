void translateVPERM2I128(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);


/* 2020/03/10 12:45 */
#define CG64 CodeGeneratorAArch64
  bool isValid = false;
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;
  xt_reg_idx_t src2Idx;
  xt_reg_idx_t src3Idx;
  xt_reg_idx_t maskIdx;
  xt_reg_idx_t zTmpIdx;
  xt_reg_idx_t zTmp2Idx;
  xt_reg_idx_t pTmpIdx;
  xt_reg_idx_t pTmp2Idx;
  xt_reg_idx_t spIdx;
  xed_uint64_t uimm = a64.operands[3].uimm;
  int lsbElem;
  int msbElem;
  dstIdx = a64.operands[0].regIdx;

  switch (uimm & 0xbb) {
  case 0x00:
  case 0x11:
  case 0x22:
  case 0x33:
    switch (uimm & 0xbb) {
    case 0x00:
      srcIdx = a64.operands[1].regIdx;
      lsbElem = 0;
      break;
    case 0x11:
      srcIdx = a64.operands[1].regIdx;
      lsbElem = 1;
      break;
    case 0x22:
      srcIdx = a64.operands[2].regIdx;
      lsbElem = 0;
      break;
    case 0x33:
      srcIdx = a64.operands[2].regIdx;
      lsbElem = 1;
      break;
    }
    CG64::dup(xa::ZRegQ(dstIdx), xa::ZRegQ(srcIdx)[lsbElem]);
    CG64::mov(xa::ZRegD(dstIdx), P_MSB_256 / xa::T_m, 0);
    isValid = true;
    break;
  }

  switch (uimm & 0xbb) {
  case 0x10:
  case 0x12:
  case 0x30:
  case 0x32:
    lsbElem = 0;
    msbElem = 1;
    pTmpIdx = xt_push_preg(&a64);
    switch (uimm & 0xbb) {
    case 0x10:
      srcIdx = a64.operands[1].regIdx;
      src2Idx = a64.operands[1].regIdx;
      break;
    case 0x12:
      srcIdx = a64.operands[2].regIdx;
      src2Idx = a64.operands[1].regIdx;
      break;

    case 0x30:
      srcIdx = a64.operands[1].regIdx;
      src2Idx = a64.operands[2].regIdx;
      break;
    case 0x32:
      srcIdx = a64.operands[2].regIdx;
      src2Idx = a64.operands[2].regIdx;
      break;
    }
    CG64::ptrue(xa::PRegD(pTmpIdx), xa::VL2);
    CG64::sel(xa::ZRegD(dstIdx), xa::PReg(pTmpIdx), xa::ZRegD(srcIdx),
              xa::ZRegD(src2Idx));
    CG64::mov(xa::ZRegD(dstIdx), P_MSB_256 / xa::T_m, 0);
    xt_pop_preg();
    isValid = true;
    break;
  }

  switch (uimm & 0xbb) {
  case 0x01:
  case 0x03:
  case 0x21:
  case 0x23:
  case 0x13:
  case 0x31:
  case 0x02:
  case 0x20:
    pTmpIdx = xt_push_preg(&a64);
    zTmpIdx = xt_push_zreg(&a64);
    zTmp2Idx = xt_push_zreg(&a64);
    switch (uimm & 0xbb) {
    case 0x01:
      srcIdx = a64.operands[1].regIdx;
      src2Idx = a64.operands[1].regIdx;
      lsbElem = 1;
      msbElem = 0;
      break;
    case 0x03:
      srcIdx = a64.operands[2].regIdx;
      src2Idx = a64.operands[1].regIdx;
      lsbElem = 1;
      msbElem = 0;
      break;
    case 0x21:
      srcIdx = a64.operands[1].regIdx;
      src2Idx = a64.operands[2].regIdx;
      lsbElem = 1;
      msbElem = 0;
      break;
    case 0x23:
      srcIdx = a64.operands[2].regIdx;
      src2Idx = a64.operands[2].regIdx;
      lsbElem = 1;
      msbElem = 0;
      break;
    case 0x13:
      srcIdx = a64.operands[2].regIdx;
      src2Idx = a64.operands[1].regIdx;
      lsbElem = 1;
      msbElem = 1;
      break;
    case 0x31:
      srcIdx = a64.operands[1].regIdx;
      src2Idx = a64.operands[2].regIdx;
      lsbElem = 1;
      msbElem = 1;
      break;
    case 0x02:
      srcIdx = a64.operands[2].regIdx;
      src2Idx = a64.operands[1].regIdx;
      lsbElem = 0;
      msbElem = 0;
      break;
    case 0x20:
      srcIdx = a64.operands[1].regIdx;
      src2Idx = a64.operands[2].regIdx;
      lsbElem = 0;
      msbElem = 0;
      break;
    }
    CG64::ptrue(xa::PRegD(pTmpIdx), xa::VL2);
    CG64::dup(xa::ZRegQ(zTmpIdx), xa::ZRegQ(srcIdx)[lsbElem]);
    CG64::dup(xa::ZRegQ(zTmp2Idx), xa::ZRegQ(src2Idx)[msbElem]);
    CG64::sel(xa::ZRegD(dstIdx), xa::PReg(pTmpIdx), xa::ZRegD(zTmpIdx),
              xa::ZRegD(zTmp2Idx));
    CG64::mov(xa::ZRegD(dstIdx), P_MSB_256 / xa::T_m, 0);
    xt_pop_zreg();
    xt_pop_zreg();
    xt_pop_preg();
    isValid = true;
    break;
  }

  switch (uimm & 0xb8) {
  case 0x08:
  case 0x28:
    switch (uimm & 0xb8) {
    case 0x08:
      srcIdx = a64.operands[1].regIdx;
      break;
    case 0x28:
      srcIdx = a64.operands[2].regIdx;
      break;
    }
    CG64::ptrue(P_TMP_0.d, xa::VL2);
    CG64::orr(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
    CG64::dup(xa::ZRegQ(dstIdx), xa::ZRegQ(srcIdx)[0]);
    CG64::mov(xa::ZRegD(dstIdx), P_TMP_0 / xa::T_m, 0);
    isValid = true;
    break;
  }

  switch (uimm & 0xb8) {
  case 0x18:
  case 0x38:
    switch (uimm & 0xb8) {
    case 0x18:
      srcIdx = a64.operands[1].regIdx;
      break;
    case 0x38:
      srcIdx = a64.operands[2].regIdx;
      break;
    }
    CG64::ptrue(P_TMP_0.d, xa::VL2);
    CG64::orr(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_TMP_0.b);
    if (dstIdx != srcIdx) {
      CG64::mov(xa::ZRegD(dstIdx), xa::ZRegD(srcIdx));
    }
    CG64::mov(xa::ZRegD(dstIdx), P_TMP_0 / xa::T_m, 0);
    isValid = true;
    break;
  }

  switch (uimm & 0x8b) {
  case 0x80:
  case 0x82:
    switch (uimm & 0x8b) {
    case 0x80:
      srcIdx = a64.operands[1].regIdx;
      break;
    case 0x82:
      srcIdx = a64.operands[2].regIdx;
      break;
    }
    if (dstIdx != srcIdx) {
      CG64::mov(xa::ZRegD(dstIdx), xa::ZRegD(srcIdx));
    }
    CG64::mov(xa::ZRegD(dstIdx), P_MSB_384 / xa::T_m, 0);
    isValid = true;
    break;
  }

  switch (uimm & 0x8b) {
  case 0x81:
  case 0x83:
    switch (uimm & 0x8b) {
    case 0x81:
      srcIdx = a64.operands[1].regIdx;
      break;
    case 0x83:
      srcIdx = a64.operands[2].regIdx;
      break;
    }
    CG64::dup(xa::ZRegQ(dstIdx), xa::ZRegQ(srcIdx)[1]);
    CG64::mov(xa::ZRegD(dstIdx), P_MSB_384 / xa::T_m, 0);
    isValid = true;
    break;
  }

  XT_VALID_CHECK_IF;
#undef CG64
}
