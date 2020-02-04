/* Broadcatst single-precison floating-point element
   To implement translateVBROADCASTSS, the following is assumed.
   Source operand is always 32-bit width. It is either a xmm register or memory
   operand. Destination is a xmm or ymm or zmm register. # of operands is two
   (dst, src) or three (dst, mask, src).
*/
void translateVBROADCASTSS(xed_decoded_inst_t *p) {
  unsigned int i, noperands, dstIdx;
  unsigned int srcIdx = XT_REG_INVALID;
  ;
  unsigned int maskIdx = XT_REG_INVALID;
  unsigned int baseIdx = XT_REG_INVALID;
  unsigned int indexIdx = XT_REG_INVALID;
  unsigned int segIdx = XT_REG_INVALID;
  xed_uint_t scale = 0;
  xed_int64_t disp = 0;
  xed_bool_t isRegOperand;
  xed_bool_t isMasking = xed_decoded_inst_masking(p);
  xed_bool_t isZeroing = xed_decoded_inst_zeroing(p);
  xed_bool_t isMerging = xed_decoded_inst_merging(p);
  const xed_inst_t *xi = xed_decoded_inst_inst(p);
  const xed_operand_t *opDst = xed_inst_operand(xi, 0);
  //  xed_operand_t* opMask, opBase, opIndex;
  const xed_operand_t *opSrc;
  //  xed_reg_enum_t dstReg = xed_decoded_inst_get_reg(p, opDst);
  xed_reg_enum_t seg, base, indx;
  xed_memop_t mem_op;

  /* Get # of operands */
  noperands = xed_inst_noperands(xi);

  dstIdx = xt_get_register_index(p, 0);

  /* If operand does not exist, xed_inst_oeprand asserts error. */
  if (noperands == 2) {
    srcIdx = xt_get_register_index(p, 1);
    opSrc = xed_inst_operand(xi, 1);
  } else if (noperands == 3) {
    //    opMask= xed_inst_operand(xi, 1);
    maskIdx = xt_get_register_index(p, 1);
    opSrc = xed_inst_operand(xi, 2);
  } else {
    std::cerr << __FILE__ << ":" << __LINE__ << ":Under construction!"
              << std::endl;
    xed_assert(noperands == 2 || noperands == 3);
  }

  isRegOperand =
      static_cast<xed_bool_t>(xed_operand_is_register(xed_operand_name(opSrc)));
  i = (maskIdx == XT_REG_INVALID) ? 1 : 2;
  if (isRegOperand) {
    srcIdx = xt_get_register_index(p, i);
  } else {
    print_memops(p);

    xt_decode_memory_operand(p, i, &baseIdx, &disp, &indexIdx, &scale,
                              &segIdx);
    if (segIdx != XT_REG_INVALID) {
      std::cerr << __FILE__ << ":" << __LINE__
                << ":Unsupported addressing mode. Please contact to "
                   "system administrator!"
                << std::endl;
      exit(1);
    }
    xed_assert(segIdx == XT_REG_INVALID);
  }

  /* Check if dst is xmm, ymm, or zmm. */
  xed_uint_t dstBits = xed_decoded_inst_operand_length_bits(p, 0);
  xed_assert(dstBits == 128 || dstBits == 256 || dstBits == 512);

  /* Begin:Flow chart part */
  Xbyak_aarch64::ZRegS a64fx_dstZRegS(dstIdx);
  Xbyak_aarch64::PReg a64fx_maskPReg(maskIdx);
  Xbyak_aarch64::ZRegS a64fx_srcZRegS(srcIdx);

  if (isMasking) {
    if (isZeroing && isRegOperand) {
      dup(a64fx_dstZRegS, a64fx_srcZRegS[0]);
      nots(P_TMP_0.b, P_ALL_ONE / Xbyak_aarch64::T_z, a64fx_maskPReg.b);
      CodeGeneratorAArch64::mov(a64fx_dstZRegS, P_TMP_0 / Xbyak_aarch64::T_m, 0);
    } else if (isMerging && isRegOperand) {
      Xbyak_aarch64::VReg4S a64fx_srcVReg4S(srcIdx);
      CodeGeneratorAArch64::mov(W_TMP_0, a64fx_srcVReg4S[0]);
      CodeGeneratorAArch64::mov(a64fx_dstZRegS, a64fx_maskPReg.b, W_TMP_0);
      /*    } else if (isZeroing && !isRegOperand) {
      ld1rw(a64fx_dstZRegS, a64fx_maskPReg / Xbyak_aarch64::T_z,
              Xbyak_aarch64::AdrNoOfs(xt_get_addr_reg(
	      baseIdx, disp, indexIdx, scale, X_TMP_0, X_TMP_1)));*/
    } else if (isMerging && !isRegOperand) {
      if (baseIdx != XT_REG_INVALID && indexIdx == XT_REG_INVALID &&
          disp == 0) {
        ldr(W_TMP_0, Xbyak_aarch64::AdrNoOfs(Xbyak_aarch64::XReg(baseIdx)));
      } else if (baseIdx != XT_REG_INVALID && indexIdx != XT_REG_INVALID &&
                 scale == 4 && disp == 0) {
        ldr(W_TMP_0, Xbyak_aarch64::AdrReg(Xbyak_aarch64::XReg(baseIdx),
                                           Xbyak_aarch64::XReg(indexIdx)));
      } else {
        ldr(W_TMP_0, Xbyak_aarch64::AdrNoOfs(xt_get_addr_reg(
							     baseIdx, disp, indexIdx, scale, X_TMP_0, X_TMP_1, X_TMP_2)));
      }

      CodeGeneratorAArch64::mov(a64fx_dstZRegS, a64fx_maskPReg.b, W_TMP_0);
    } else {
      std::cerr << __FILE__ << ":" << __LINE__ << ":Something wrong!"
                << std::endl;
    }
  } else {
    Xbyak_aarch64::VReg4S a64fx_dstVReg4S(dstIdx);
    Xbyak_aarch64::VReg4S a64fx_srcVReg4S(srcIdx);

    switch (dstBits) {
    case 128:
      if (isRegOperand) {
        dup(a64fx_dstVReg4S, a64fx_srcVReg4S[0]);
      } else {
        if (baseIdx != XT_REG_INVALID && indexIdx == XT_REG_INVALID &&
            disp == 0) {
          ldr(W_TMP_0, Xbyak_aarch64::AdrNoOfs(Xbyak_aarch64::XReg(baseIdx)));
        } else if (baseIdx != XT_REG_INVALID && indexIdx != XT_REG_INVALID &&
                   scale == 4 && disp == 0) {
          ldr(W_TMP_0, Xbyak_aarch64::AdrReg(Xbyak_aarch64::XReg(baseIdx),
                                             Xbyak_aarch64::XReg(indexIdx)));
        } else {
          ldr(W_TMP_0, Xbyak_aarch64::AdrNoOfs(xt_get_addr_reg(
							       baseIdx, disp, indexIdx, scale, X_TMP_0, X_TMP_1, X_TMP_2)));
        }

        dup(a64fx_dstVReg4S, W_TMP_0);
      }
      break;

    case 256:
    case 512:
      if (isRegOperand) {
        dup(a64fx_dstZRegS, a64fx_srcZRegS[0]);
      } else {
        ld1rw(a64fx_dstZRegS, P_ALL_ONE / Xbyak_aarch64::T_z,
                Xbyak_aarch64::AdrNoOfs(xt_get_addr_reg(
							baseIdx, disp, indexIdx, scale, X_TMP_0, X_TMP_1, X_TMP_2)));
      }
      break;

    default:
      std::cerr << __FILE__ << ":" << __LINE__ << ":Wrong dstBits=" << dstBits
                << "!" << std::endl;
      exit(1);
      break;
    }
  }
  /* End:Flow chart part */
}
