#pragma once
/*******************************************************************************
 * Copyright 2020 FUJITSU LIMITED
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
/* These #define used by test_generator2.h, even if x86_64 mode. */
#define NUM_INPUT_DATA 16
/* x86_64 has 16 gen registers. AArch64 has 32 gen registers. */
#define NUM_GEN_REG 32
#define NUM_GEN_REG_INTEL 16
/* x86_64 has 8 predicate registers. AArch64 has 16 predicate registers. */
#define NUM_PRED_REG 16
#define NUM_PRED_REG_INTEL 8
#define NUM_Z_REG 32
#define NUM_Z_REG_INTEL 32

#define SP_REG_IDX_X86_64 4
#define SP_REG_IDX_AARCH64 31
#define NUM_BYTES_GEN_REG 8
#define NUM_BYTES_PRED_REG 8
#define NUM_BYTES_Z_REG 64

#define TMP_PREG_START 7
#define TMP_PREG_END 0

#ifdef XBYAK_TRANSLATE_AARCH64
#include "xbyak_translator_debug.h"

#pragma GCC diagnostic warning "-Wunused-but-set-variable"
#pragma GCC diagnostic warning "-Wunused-variable"
// namespace xbyak_translator {
public:
Xbyak_aarch64::WReg W_TMP_0 = w24;
Xbyak_aarch64::WReg W_TMP_1 = w25;
Xbyak_aarch64::WReg W_TMP_2 = w26;
Xbyak_aarch64::WReg W_TMP_3 = w27;
Xbyak_aarch64::XReg X_TMP_0 = x24;
Xbyak_aarch64::XReg X_TMP_1 = x25;
Xbyak_aarch64::XReg X_TMP_2 = x26;
Xbyak_aarch64::XReg X_TMP_3 = x27;
Xbyak_aarch64::XReg X_TMP_ADDR = x28;
Xbyak_aarch64::PReg P_MSB_256 = p13;
Xbyak_aarch64::PReg P_MSB_384 = p14;
Xbyak_aarch64::PReg P_ALL_ONE = p15;

private:
#define XT_UNIMPLEMENTED                                                       \
  std::cerr << __FILE__ << ":" << __LINE__ << ":Unimplemented" << std::endl;   \
  assert(NULL);

enum x64_inst_t {
  X64_NO_ASSIGN = 0,
  X64_VBROADCASTSS = 0x18,
};

enum ModRM_t {
  DST_ADDR = 0,
  DST_ADDR_DISP8 = 1,
  DST_ADDR_DISP32 = 2,
  DST_SRC = 3,
};

enum VecLen_t {
  VL128 = 0,
  VL256 = 1,
  VL512 = 2,
};

enum xt_cmp_type_t {
  A64_CMP_EQ,
  A64_CMP_LT,
  A64_CMP_LE,
  A64_CMP_FALSE,
  A64_CMP_NEQ,
  A64_CMP_NLT,
  A64_CMP_NLE,
  A64_CMP_TRUE,
};

struct xt_a64fx_operands_struct_t {
  /* Index of DST register(1st operand) */
  //  unsigned int dstIdx = XT_REG_INVALID;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;

  /* Index of MASK register{k} */
  xt_reg_idx_t maskIdx = XT_REG_INVALID;

  /* Index of SRC register(2nd operand) */
  xt_reg_idx_t srcIdx = XT_REG_INVALID;

  /* Index of SRC2 register(3rd operand) */
  xt_reg_idx_t src2Idx = XT_REG_INVALID;

  /* In xt_construct_a64fx_operands function,
     pTmpIdx, vTmpIdx, zTmpIdx are not substituted values.
     If a temprary P register is needed,
     call xt_push_preg() in translateHOGE functions.
     After instruction translation is done,
     return temporary P register by calling xt_pop_preg().
     The same holds for V and Z registers. */
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t vTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;

  xt_predicate_type_t PredType = A64_PRED_NO;

  /* Type of operand
     A64_OP_REG:register operand
     A64_OP_MEM:memory operand
     A64_OP_MBCST:broadcast memory operand
  */
  xt_operand_type_t dstType;
  xt_operand_type_t srcType;
  xt_operand_type_t src2Type;

  /* Is EVEX.b set? */
  xed_uint_t EVEXb = 0;

  /* Bit width of destination operand.
     8(i.e. AL, etc),   16(i.e. AX, etc), 32(i.e. EAX, etc), 64(i.e. RAX, etc),
    128(i.e. Xmm0, etc), 256(i.e. Ymm0, etc), 512(i.e. Zmm0, etc) */
  xed_uint_t dstWidth;

  /* Immediate value opoerand */
  xed_uint_t ibits = 0;
  xed_uint64_t uimm = 0; /* unsigned */
  xed_int64_t simm = 0;  /* signedな */
  xed_uint_t immWidth;   /* IMM value width. 8, 16, 32, 64 */

  xed_uint64_t uimm2 = 0; /* 2nd immediate and its type is unsigned */
  xed_int64_t simm2 = 0;  /* 2nd immediate and its type is signed */

  xed_bool_t isDstMask =
      false; /* ture:dst operand is mask register, false:otherwise */
};

void db_clear() { CodeArray::size_ = 0; }

xt_reg_idx_t xt_get_register_index(const xed_reg_enum_t r) {
  if (XED_REG_RAX <= r && r <= XED_REG_R15) {
    return r - XED_REG_RAX;
  } else if (XED_REG_K0 <= r && r <= XED_REG_K7) {
    return r - XED_REG_K0;
  } else if (XED_REG_MMX0 <= r && r <= XED_REG_MMX7) {
    return r - XED_REG_MMX0;
  } else if (XED_REG_XMM0 <= r && r <= XED_REG_XMM31) {
    return r - XED_REG_XMM0;
  } else if (XED_REG_YMM0 <= r && r <= XED_REG_YMM31) {
    return r - XED_REG_YMM0;
  } else if (XED_REG_ZMM0 <= r && r <= XED_REG_ZMM31) {
    return r - XED_REG_ZMM0;
  } else if (XED_REG_EAX <= r && r <= XED_REG_R15D) {
    return r - XED_REG_EAX;
  } else if (r == XED_REG_RFLAGS) {
    /* In case of 2nd operand of DEC instruction, this "else if" is passed */
    return XT_REG_INVALID;
  } else {
    xt_msg_err(__FILE__, __LINE__, ":Under construction!");
    assert(NULL);
  }
}

xt_reg_idx_t xt_get_register_index(const xed_decoded_inst_t *p,
                                   unsigned int i) {
  const xed_inst_t *xi = xed_decoded_inst_inst(p);
  const xed_operand_t *op = xed_inst_operand(xi, i);
  xed_operand_enum_t op_name = xed_operand_name(op);
  xed_reg_enum_t r = xed_decoded_inst_get_reg(p, op_name);

  return xt_get_register_index(r);
}

Xbyak_aarch64::XReg xt_get_addr_reg(unsigned int base, xed_int64_t disp,
                                    unsigned int index, xed_uint_t scale,
                                    const Xbyak_aarch64::XReg tmp0,
                                    const Xbyak_aarch64::XReg tmp1,
                                    const Xbyak_aarch64::XReg tmp2) {

  unsigned int shift = 0;
  if (scale == 0) {
    /* Nothing to do */
  } else if (scale == 2) {
    shift = 1;
  } else if (scale == 4) {
    shift = 2;
  } else if (scale == 8) {
    shift = 3;
  } else {
    std::cerr << __FILE__ << ":" << __LINE__ << ":scale=" << scale
              << " is assumed to 2, 4, or 8!" << std::endl;
    exit(1);
  }

  Xbyak_aarch64::XReg retReg(tmp0);

  if (base != XT_REG_INVALID /* Base only */
      && disp == 0 && index == XT_REG_INVALID) {
    return Xbyak_aarch64::XReg(base);

  } else if (base != XT_REG_INVALID && disp != 0 /* Base + disp */
             && index == XT_REG_INVALID) {
    //    add_imm(retReg, Xbyak_aarch64::XReg(base), disp, tmp1);
    return retReg;
  } else if (base != XT_REG_INVALID && disp != 0 &&
             index != XT_REG_INVALID) { /* Base + disp + index (*scale) */
    //    add_imm(retReg, Xbyak_aarch64::XReg(base), disp, tmp1);

    if (shift == 0) {
      CodeGeneratorAArch64::add(retReg, retReg, Xbyak_aarch64::XReg(index));
      return retReg; /* Base + disp + index */
    } else {
      lsl(tmp1, Xbyak_aarch64::XReg(index), shift);
      CodeGeneratorAArch64::add(retReg, Xbyak_aarch64::XReg(base), tmp1);
      return retReg; /* Base + disp + index*scale */
    }
  } else if (base == XT_REG_INVALID /* disp + index (*scale) */
             && index != XT_REG_INVALID && disp != 0) {
    if (shift == 0) {
      //      add_imm(retReg, Xbyak_aarch64::XReg(index), disp, tmp1);
      return retReg; /* disp + index */
    } else {
      lsl(tmp1, Xbyak_aarch64::XReg(index), shift);
      CodeGeneratorAArch64::add(retReg, Xbyak_aarch64::XReg(index), tmp1);
      return retReg; /* disp + index*scale */
    }
  } else {
    xt_msg_err(__FILE__, __LINE__,
               ":Something wrong. Please contact to system administrator!");
  }

  return retReg;
}

unsigned int xt_push_vreg(xt_a64fx_operands_struct_t *a64) {
  xt_push_zreg(a64);
}

unsigned int xt_push_zreg(xt_a64fx_operands_struct_t *a64) {
  for (size_t i = AARCH64_NUM_ZREG - 1; i >= 0; i--) {
    if (a64->dstIdx != i && a64->srcIdx != i && a64->src2Idx != i) {
      if (zreg_tmp_used[i] == false) {
        zreg_tmp_used[i] = true;

        CodeGeneratorAArch64::sub(CodeGeneratorAArch64::sp,
                                  CodeGeneratorAArch64::sp, NUM_BYTES_Z_REG);
        CodeGeneratorAArch64::str(Xbyak_aarch64::ZReg(i),
                                  Xbyak_aarch64::ptr(CodeGeneratorAArch64::sp));
        return i;
      }
    }
  }

  std::cerr << __FILE__ << ":" << __LINE__ << ":Temporal ZReg allocation failed"
            << ". Please contact to system administrator!" << std::endl;
  assert(NULL);

  return 31;
}

unsigned int xt_push_preg(xt_a64fx_operands_struct_t *a64) {
  for (size_t i = TMP_PREG_START; i >= TMP_PREG_END; i--) {
    if (a64->dstIdx != i && a64->srcIdx != i && a64->src2Idx != i &&
        a64->maskIdx != i) {
      if (preg_tmp_used[i] == false) {
        preg_tmp_used[i] = true;

        CodeGeneratorAArch64::sub(CodeGeneratorAArch64::sp,
                                  CodeGeneratorAArch64::sp, NUM_BYTES_PRED_REG);
        CodeGeneratorAArch64::str(Xbyak_aarch64::PReg(i),
                                  Xbyak_aarch64::ptr(CodeGeneratorAArch64::sp));
        return i;
      }
    }
  }

  std::cerr << __FILE__ << ":" << __LINE__ << ":Temporal PReg allocation failed"
            << ". Please contact to system administrator!" << std::endl;
  assert(NULL);

  return 31;
}

void xt_pop_vreg() { xt_pop_zreg(); }

void xt_pop_zreg() {
  for (size_t i = 0; i < AARCH64_NUM_ZREG; i++) {
    if (zreg_tmp_used[i] == true) {
      CodeGeneratorAArch64::ldr(Xbyak_aarch64::ZReg(i),
                                Xbyak_aarch64::ptr(CodeGeneratorAArch64::sp));
      CodeGeneratorAArch64::add(CodeGeneratorAArch64::sp,
                                CodeGeneratorAArch64::sp, NUM_BYTES_Z_REG);
      zreg_tmp_used[i] = false;
      return;
    }
  }

  std::cerr << __FILE__ << ":" << __LINE__ << ":Restoreing temporal ZReg failed"
            << ". Please contact to system administrator!" << std::endl;
  assert(NULL);
}

void xt_pop_preg() {
  for (size_t i = TMP_PREG_END; i <= TMP_PREG_START; i++) {
    if (preg_tmp_used[i] == true) {
      CodeGeneratorAArch64::ldr(Xbyak_aarch64::PReg(i),
                                Xbyak_aarch64::ptr(CodeGeneratorAArch64::sp));
      CodeGeneratorAArch64::add(CodeGeneratorAArch64::sp,
                                CodeGeneratorAArch64::sp, NUM_BYTES_PRED_REG);
      preg_tmp_used[i] = false;
      return;
    }
  }

  std::cerr << __FILE__ << ":" << __LINE__ << ":Restoreing temporal PReg failed"
            << ". Please contact to system administrator!" << std::endl;
  assert(NULL);
}

#include "xbyak_translator_inc.h"

bool decodeOpcode() {
  xed_state_t dstate;
  xed_decoded_inst_t xedd;
  xed_error_enum_t xed_error;
  xed_chip_enum_t chip = XED_CHIP_INVALID;

  xed_tables_init();
  xed_state_zero(&dstate);

  dstate.mmode = XED_MACHINE_MODE_LONG_64;
  dstate.stack_addr_width = XED_ADDRESS_WIDTH_32b;

  xed_decoded_inst_zero_set_mode(&xedd, &dstate);
  xed_decoded_inst_set_input_chip(&xedd, chip);

  xed3_operand_set_mpxmode(&xedd, 0);
  xed3_operand_set_cet(&xedd, 0);

#if 0
  CodeArray::top_[0] = 0x62;
  CodeArray::top_[1] = 0xf2;
  CodeArray::top_[2] = 0x7d;
  CodeArray::top_[3] = 0x09;
  CodeArray::top_[4] = 0x18;
  CodeArray::top_[5] = 0xc2;
  CodeArray::size_ = 6;
#endif

  printf("Attempting to decode: ");
  for (unsigned int i = 0; i < CodeArray::size_; i++)
    printf("%02x ", XED_STATIC_CAST(xed_uint_t, CodeArray::top_[i]));
  printf("\n");

  xed_error = xed_decode(
      &xedd, XED_REINTERPRET_CAST(const xed_uint8_t *, CodeArray::top_),
      CodeArray::size_);

  switch (xed_error) {
  case XED_ERROR_NONE:
    break;
  case XED_ERROR_BUFFER_TOO_SHORT:
    printf("Not enough bytes provided\n");
    exit(1);
  case XED_ERROR_INVALID_FOR_CHIP:
    printf("The instruction was not valid for the specified chip.\n");
    exit(1);
  case XED_ERROR_GENERAL_ERROR:
    printf("Could not decode given input.\n");
    exit(1);
  default:
    printf("Unhandled error code %s\n", xed_error_enum_t2str(xed_error));
    exit(1);
  }

  /* Dump debugging info */
  xt_dump_x86_64_decoded_info(&xedd);

  xed_iclass_enum_t p = xed_decoded_inst_get_iclass(&xedd);

#include "xbyak_translator_switch.h"

  return true;
}

void xt_construct_a64fx_operands(xed_decoded_inst_t *p,
                                 xt_a64fx_operands_struct_t *a64) {
  unsigned int i, num_operands;

  unsigned int baseIdx = XT_REG_INVALID;
  unsigned int indexIdx = XT_REG_INVALID;
  unsigned int segIdx = XT_REG_INVALID;

  xed_uint_t scale = 0;
  xed_int64_t disp = 0;
  xed_bool_t isRegOperand;
  const xed_inst_t *xi = xed_decoded_inst_inst(p);
  //  xed_reg_enum_t dstReg = xed_decoded_inst_get_reg(p, opDst);
  xed_reg_enum_t seg, base, indx;
  xed_memop_t mem_op;
  xed_uint_t ibits;
  xed_bool_t isDstSet = false;
  xed_bool_t isMaskSet = false;
  xed_bool_t isSrcSet = false;
  xed_bool_t isSrc2Set = false;
  xed_bool_t isMemOpSet = false;

  /* Get EVEX.b bits */
  a64->EVEXb = xed_decoded_inst_is_broadcast(p);

  /* Get # of operands */
  num_operands = xed_inst_noperands(xi);

  for (int i = 0; i < num_operands; i++) {
    const xed_operand_t *op = xed_inst_operand(xi, i);
    xed_operand_enum_t opName = xed_operand_name(op);

    /* Begin: parsing register operand */
    xed_uint_t isReg = xed_operand_is_register(opName);
    if (isReg == 1) { /* Operand is register */
      xed_reg_enum_t r = xed_decoded_inst_get_reg(p, opName);
      unsigned int tmpIdx = xt_get_register_index(r);

      /* Target x86_64 contains masking(predicate) information */
      if (XED_REG_K0 <= r && r <= XED_REG_K7) {
        if (isMaskSet ==
            true) { /* Two mask registers exist in one instruction? */
          xt_msg_err(__FILE__, __LINE__,
                     "Unsupported mask pattern. Please contact to "
                     "system administrator!");
        }

        if (isDstSet ==
            false) { /* Mask create instruction. Dst is a mask register. */
          a64->dstIdx = tmpIdx;
          a64->isDstMask = true;
          isDstSet = true;
        } else {
          a64->maskIdx = tmpIdx;
          /* Decode predicate information */
          xed_bool_t isMasking = xed_decoded_inst_masking(p);
          xed_bool_t isMerging = xed_decoded_inst_merging(p);
          xed_bool_t isZeroing = xed_decoded_inst_zeroing(p);
          if (!isMasking) {
            a64->PredType = A64_PRED_NO;
          } else if (isMerging) {
            a64->PredType = A64_PRED_MERG;
          } else if (isZeroing) {
            a64->PredType = A64_PRED_ZERO;
          } else {
            xt_msg_err(__FILE__, __LINE__,
                       "Unknwon predicate type. Please contact to "
                       "system administrator!");
          }

          isMaskSet = true;
        }
      } else { // if(XED_REG_K0 <= r && r <= XED_REG_K7) {
        if (isDstSet == false) {
          a64->dstType = A64_OP_REG;
          a64->dstIdx = tmpIdx;
          isDstSet = true;
          a64->dstWidth = xed_decoded_inst_operand_length_bits(p, i);
        } else if (isSrcSet == false) {
          a64->srcType = A64_OP_REG;
          a64->srcIdx = tmpIdx;
          isSrcSet = true;
        } else if (isSrc2Set == false) {
          a64->src2Type = A64_OP_REG;
          a64->src2Idx = tmpIdx;
          isSrc2Set = true;
        } else {
          xt_msg_err(__FILE__, __LINE__,
                     "Unknwon # of register operands. Please contact to "
                     "system administrator!");
        }
      }
      continue; /* End of register operand process */
    }
    /* End: parsing register operand */

    /* Begin: parsing memory operand */
    if (opName == XED_OPERAND_MEM0) {
      if (isMemOpSet == true) {
        /* Two memory operands exist in one instruction? */
        xt_msg_err(__FILE__, __LINE__,
                   "Unsupported # of memory operands. Please contact to "
                   "system administrator!");
      }

      //      unsigned int memops =
      //      xed_decoded_inst_number_of_memory_operands(xedd);

      unsigned int width = xed_decoded_inst_get_memop_address_width(p, i);
      if (width != 64) {
        xt_msg_err(__FILE__, __LINE__,
                   "Unsupported address width=" + std::to_string(width) +
                       ". Please contact to system administrator!");
      }

      xed_reg_enum_t tmpReg;
      xed_int64_t tmpDisp;
      xed_uint32_t tmpScale;

      tmpReg = xed_decoded_inst_get_seg_reg(p, 0);
      if (tmpReg != XED_REG_INVALID) {
        segIdx = xt_get_register_index(tmpReg);
      }

      tmpReg = xed_decoded_inst_get_base_reg(p, 0);
      if (tmpReg != XED_REG_INVALID) {
        baseIdx = xt_get_register_index(tmpReg);
      }

      tmpReg = xed_decoded_inst_get_index_reg(p, 0);
      if (tmpReg != XED_REG_INVALID) {
        indexIdx = xt_get_register_index(tmpReg);
        tmpScale = xed_decoded_inst_get_scale(p, 0);
        if (tmpScale) {
          scale = tmpScale;
        }
      }

      disp = xed_decoded_inst_get_memory_displacement(p, 0);

      if (isDstSet == false) { /* This memory operand is for DST operand. */
        a64->dstType = A64_OP_MEM;
        isDstSet = true;
        a64->dstWidth = xed_decoded_inst_operand_length_bits(p, 0);
      } else if (isSrcSet == false) {
        a64->srcType = A64_OP_MEM;
        isSrcSet = true;
      } else if (isSrc2Set == false) {
        a64->src2Type = A64_OP_MEM;
        isSrc2Set = true;
      } else {
        xt_msg_err(__FILE__, __LINE__,
                   "Unknwon # of register operands. Please contact to "
                   "system administrator!");
      }

      X_TMP_ADDR = xt_get_addr_reg(baseIdx, disp, indexIdx, scale, X_TMP_ADDR,
                                   X_TMP_1, X_TMP_2);
      continue;
    }
    /* End: parsing memory operand */

    /* Begin: parsing immediate value operand */

    if (opName == XED_OPERAND_IMM0 || opName == XED_OPERAND_IMM0SIGNED) {
      if (isDstSet == false) { /* This memory operand is for DST operand. */
        a64->dstType = A64_OP_IMM;
        isDstSet = true;
        a64->dstWidth = xed_decoded_inst_operand_length_bits(p, 0);
      } else if (isSrcSet == false) {
        a64->srcType = A64_OP_IMM;
        isSrcSet = true;
      } else if (isSrc2Set == false) {
        a64->src2Type = A64_OP_IMM;
        isSrc2Set = true;
      } else {
        /* For example, VPINSRB instruction has dstReg, srcReg, src2Reg, and
           IMM, so that if program comes here, it's not a bug. */
      }
      if (opName == XED_OPERAND_IMM0) {
        const unsigned int no_leading_zeros = 0;
        xed_uint_t ibits;
        const xed_bool_t lowercase = 1;

        ibits = xed_decoded_inst_get_immediate_width_bits(p);
        if (xed_decoded_inst_get_immediate_is_signed(p)) {
          xed_uint_t rbits = ibits ? ibits : 8;
          xed_int32_t x = xed_decoded_inst_get_signed_immediate(p);
          a64->uimm = XED_STATIC_CAST(
              xed_uint64_t,
              xed_sign_extend_arbitrary_to_64((xed_uint64_t)x, ibits));
        } else {
          a64->uimm = xed_decoded_inst_get_unsigned_immediate(p);
        }

        a64->immWidth = xed_decoded_inst_get_immediate_width(p);
        continue;
      }
      if (opName == XED_OPERAND_IMM0SIGNED) {
        a64->immWidth = xed_decoded_inst_get_immediate_width(p);
        a64->simm = xed_decoded_inst_get_signed_immediate(p);
        continue;
      }
    }
    if (opName == XED_OPERAND_IMM1) {
      a64->uimm2 = xed_decoded_inst_get_second_immediate(p);
      continue;
    }

    xt_msg_err(__FILE__, __LINE__, "Unsupported opName");
  } // for (int i = 0; i < num_operands; i++) {

  /* Support for legacy xbyak_translate frame work */
  xed_iclass_enum_t iclass = xed_decoded_inst_get_iclass(p);
  if (iclass == XED_ICLASS_VANDPS && a64->EVEXb) {
    if (a64->src2Type != A64_OP_MEM) {
      xt_msg_err(__FILE__, __LINE__,
                 ":Something wrong. Please contact to system administrator!");
    }
    a64->src2Type = A64_OP_MBCST;
  }

  xt_dump_a64fx_operands(a64);
}

void decodeAndTransToAArch64() {
  decode_size_ = 0;
  decodeOpcode();
  db_clear();
}
#else  //#ifdef XBYAK_TRANSLATE_AARCH64
void decodeAndTransToAArch64() {}
#endif //#ifdef XBYAK_TRANSLATE_AARCH64

//} //namespace xbyak_translator {
