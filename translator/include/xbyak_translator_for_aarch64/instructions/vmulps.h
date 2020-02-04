/*
 */
void translateVMULPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
    

  unsigned int i, noperands;
  unsigned int a64_dstIdx = XT_REG_INVALID;
  unsigned int a64_maskIdx = XT_REG_INVALID;
  unsigned int a64_srcIdx = XT_REG_INVALID;
  unsigned int a64_src2Idx = XT_REG_INVALID;
  unsigned int a64_vTmpIdx = XT_REG_INVALID;
  unsigned int a64_zTmpIdx = XT_REG_INVALID;
  
  unsigned int baseIdx = XT_REG_INVALID;
  unsigned int indexIdx = XT_REG_INVALID;
  unsigned int segIdx = XT_REG_INVALID;

  xed_uint_t scale = 0;
  xed_int64_t disp = 0;
  xed_bool_t isRegOperand;
  xed_bool_t isMasking = xed_decoded_inst_masking(p);
  xed_bool_t isMerging = xed_decoded_inst_merging(p);
  xed_bool_t isZeroing = xed_decoded_inst_zeroing(p);
  const xed_inst_t *xi = xed_decoded_inst_inst(p);
  //  xed_reg_enum_t dstReg = xed_decoded_inst_get_reg(p, opDst);
  xed_reg_enum_t seg, base, indx;
  xed_memop_t mem_op;
  xt_predicate_type_t a64_PredType = A64_PRED_NO;
  xt_operand_type_t a64_dstType, a64_srcType, a64_src2Type;
  xed_uint_t dstWidth;
    
  /* Decode predicate information */
  if(!isMasking) {
    a64_PredType = A64_PRED_NO;
  } else if(isMerging) {
    a64_PredType = A64_PRED_MERG;
  } else if(isZeroing) {
    a64_PredType = A64_PRED_ZERO;
  } else {
    std::cerr << __FILE__ << ":" << __LINE__
	      << ":Unsupported predicate type. Please contact to "
      "system administrator!"
	      << std::endl;
    exit(1);
  }    

  /* Get # of operands */
  noperands = xed_inst_noperands(xi);
  if(!(noperands==3 || noperands==4)) { /* Either (Dst, src, src2) or (Dst, mask, src, src2) is assumed. */
    std::cerr << __FILE__ << ":" << __LINE__
	      << ":Unsupported # of operands. Please contact to "
      "system administrator!"
	      << std::endl;
    exit(1);
  }    

  /* Get Dst register index */
  const xed_operand_t *opDst = xed_inst_operand(xi, 0);
  assert((static_cast<xed_bool_t>(xed_operand_is_register(xed_operand_name(opDst)))));
  a64_dstType = A64_OP_REG;
  a64_dstIdx = xt_get_register_index(p, 0);
  /* Check if dst is xmm, ymm, or zmm. */
  dstWidth = xed_decoded_inst_operand_length_bits(p, 0);
  xed_assert(dstWidth == 128 || dstBits == 256 || dstBits == 512);

  /* If mask info exist, get mask register index */
  if(noperands==4) {
    const xed_operand_t *opMask = xed_inst_operand(xi, 1);
    assert((static_cast<xed_bool_t>(xed_operand_is_register(xed_operand_name(opMask)))));
    a64_maskIdx = xt_get_register_index(p, 1);
  }

  /* Get Src register index */
  i = noperands==3 ? 1 : 2;
  const xed_operand_t *opSrc = xed_inst_operand(xi, i);
  assert((static_cast<xed_bool_t>(xed_operand_is_register(xed_operand_name(opSrc)))));
  a64_srcType = A64_OP_REG;
  a64_srcIdx = xt_get_register_index(p, i);

  /* Get Src2 information */
  i = noperands==3 ? 2 : 3;
  const xed_operand_t *opSrc2 = xed_inst_operand(xi, i);
  
  if((static_cast<xed_bool_t>(xed_operand_is_register(xed_operand_name(opSrc))))) {
    a64_src2Type = A64_OP_REG;
    a64_src2Idx = xt_get_register_index(p, i);
  } else {
    if(xed_decoded_inst_is_broadcast(p)) {
      a64_src2Type = A64_OP_MBCST;
    } else {
      a64_src2Type = A64_OP_MEM;
    }

    xt_decode_memory_operand_designated(p, i, &baseIdx, &disp, &indexIdx, &scale,
                              &segIdx);
    if (segIdx != XT_REG_INVALID) {
      std::cerr << __FILE__ << ":" << __LINE__
                << ":Unsupported addressing mode. Please contact to "
                   "system administrator!"
                << std::endl;
      exit(1);
    }
    xed_assert(segIdx == XT_REG_INVALID);

    /* Construct address register */
    xt_get_addr_reg(base, disp, indexIdx, scale, X_TMP_ADDR, X_TMP_0, X_TMP_1);
  }



  

  /* Begin:Copy code from Excel. */
#include "instructions/vmulps_body.h"
  /* End:Copy code from Excel. */
}
