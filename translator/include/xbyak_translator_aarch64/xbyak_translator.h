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

// namespace xbyak_translator {
private:
bool availAll1Preg0_7 = false;
constexpr static unsigned int translatorVersion = 1;

unsigned int P_ALL_ONE_0_7_IDX = XT_REG_INVALID;
bool genJitMode = true;
bool availablePReg[NUM_PRED_REG_INTEL] = {0};
bool unusedPReg[NUM_PRED_REG_INTEL] = {0};
bool availableZReg[NUM_Z_REG_INTEL] = {0};
bool unusedZReg[NUM_Z_REG_INTEL] = {0};

public:
constexpr static xt_reg_idx_t xtDefaultAddrIdx = 28;
// Stack size for translator >= (SVE reg. size) * 5 + (predicate reg. size) * 2
constexpr static unsigned int xt_stack_size = 512 * 8;
// If xt_stack_offset >= 4096, then use sub_imm() in preamble() in
// jit_generator.hpp
constexpr static unsigned int xt_stack_offset = 1024 * 128;

xa::WReg W_TMP_0 = w23;
xa::WReg W_TMP_1 = w24;
xa::WReg W_TMP_2 = w25;
xa::WReg W_TMP_3 = w26;
xa::WReg W_TMP_4 = w27;
xa::XReg X_TMP_0 = x23;
xa::XReg X_TMP_1 = x24;
xa::XReg X_TMP_2 = x25;
xa::XReg X_TMP_3 = x26;
xa::XReg X_TMP_4 = x27;
xa::XReg X_TMP_ADDR = x28;
const xa::XReg X_DEFAULT_ADDR = x28;
xa::XReg X_TRANSLATOR_STACK = x22;
xa::PReg P_TMP = p0;
xa::PReg P_TMP_0 = p11;
xa::PReg P_TMP_1 = p12;
xa::PReg P_ALL_ZERO = p10;
xa::PReg P_MSB_256 = p13;
xa::PReg P_MSB_384 = p14;
xa::PReg P_ALL_ONE = p15;
xa::PReg P_ALL_ONE_0_7{XT_REG_INVALID};

inline bool isAvailAll1Preg0_7() { return availAll1Preg0_7; }

uint32_t setAll1Preg0_7(uint32_t index) {
  if (index > 7) {
    xt_msg_err(__FILE__, __LINE__, ":Index of All1Preg0_7 must be 0 to 7!");
    assert(NULL);
  }

  P_ALL_ONE_0_7 = xa::PReg{index};
  xa_->ptrue(P_ALL_ONE_0_7.b);
  availAll1Preg0_7 = true;
  P_ALL_ONE_0_7_IDX = index;

  return index;
}

void clearAll1Preg0_7() {
  P_ALL_ONE_0_7 = xa::PReg{XT_REG_INVALID};
  availAll1Preg0_7 = false;
  P_ALL_ONE_0_7_IDX = XT_REG_INVALID;
}

uint64_t getTranslatorVersion() { return translatorVersion; }

void unSetGenJitMode() { genJitMode = false; }

void setGenJitMode() { genJitMode = true; }

void initSearchPReg() {
  for (int i = 0; i < NUM_PRED_REG_INTEL; i++) {
    availablePReg[i] = true;
    unusedPReg[i] = true;
  }
}

void initSearchZReg() {
  for (int i = 0; i < NUM_Z_REG_INTEL; i++) {
    availableZReg[i] = true;
    unusedZReg[i] = true;
  }
}

bool getGenJitMode() { return genJitMode; }

void binCommit() {
  size_t num32bits = Xbyak::CodeArray::size_;

  num32bits = (num32bits + 3) - ((num32bits + 3) % 4);
  num32bits /= 4;

  const uint32_t *tmp =
      reinterpret_cast<const uint32_t *>(Xbyak::CodeArray::top_);

  for (size_t i = 0; i < num32bits; i++) {
    xa_->dd(tmp[i]);
  }

  db_clear();
}

private:
#define XT_UNIMPLEMENTED                                                       \
  std::cerr << __FILE__ << ":" << __LINE__ << ":Unimplemented" << std::endl;   \
  assert(NULL);

#define XT_VALID_CHECK isValid = true;

#define XT_VALID_CHECK_IF                                                      \
  if (!isValid) {                                                              \
    std::cerr << __FILE__ << ":" << __LINE__                                   \
              << ":Unsupported operand variation" << std::endl;                \
    assert(NULL);                                                              \
  }

void db_clear() { Xbyak::CodeArray::size_ = 0; }

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
  } else if (XED_REG_AL <= r && r <= XED_REG_BPL) {
    return r - XED_REG_AL;
  } else if (XED_REG_AX <= r && r <= XED_REG_R15W) {
    return r - XED_REG_AX;
  } else if (XED_REG_AL <= r && r <= XED_REG_R15B) {
    return r - XED_REG_AL;
  } else if (r == XED_REG_RFLAGS) {
    /* In case of 2nd operand of DEC instruction, this "else if" is passed */
    return XT_REG_INVALID;
  } else if (r == XED_REG_STACKPOP) {
    return XT_REG_INVALID;
  } else if (r == XED_REG_RIP) {
    return XT_REG_INVALID;
  } else if (XED_REG_ES <= r && r <= XED_REG_GS) {
    return r - XED_REG_ES;
  } else {
    xt_msg_err(__FILE__, __LINE__, ":Under construction!");
    assert(NULL);
    return XT_REG_INVALID;
  }
  return XT_REG_INVALID;
}

xt_reg_idx_t xt_get_register_index(const xed_decoded_inst_t *p,
                                   unsigned int i) {
  const xed_inst_t *xi = xed_decoded_inst_inst(p);
  const xed_operand_t *op = xed_inst_operand(xi, i);
  xed_operand_enum_t op_name = xed_operand_name(op);
  xed_reg_enum_t r = xed_decoded_inst_get_reg(p, op_name);

  return xt_get_register_index(r);
}

xa::XReg xt_get_addr_reg(unsigned int base, xed_int64_t disp,
                         unsigned int index, xed_uint_t scale,
                         const xa::XReg tmp0, const xa::XReg tmp1,
                         const xa::XReg tmp2, bool vm64 = false) {

  unsigned int shift = 0;
  if (scale == 0) {
    /* Nothing to do */
  } else if (scale == 1) {
    /* Nothing to do */
  } else if (scale == 2) {
    shift = 1;
  } else if (scale == 4) {
    shift = 2;
  } else if (scale == 8) {
    shift = 3;
  } else {
    std::cerr << __FILE__ << ":" << __LINE__ << ":scale(=" << scale
              << ") is assumed to 1, 2, 4, or 8!" << std::endl;
    exit(1);
  }

#if 0  
  std::cout << "base=" << base << std::endl;
  std::cout << "disp=" << disp << std::endl;
  std::cout << "index=" << index << std::endl;
  std::cout << "scale=" << scale << std::endl;
  std::cout << "tmp0=" << tmp0.getIdx() << std::endl;
  std::cout << "tmp1=" << tmp1.getIdx() << std::endl;
  std::cout << "tmp2=" << tmp2.getIdx() << std::endl;
  std::cout << "vm64=" << vm64 << std::endl;
#endif

  xa::XReg retReg{xtDefaultAddrIdx};

  if (vm64) { /* VSIB addressing */
    index = XT_REG_INVALID;
  }

  if (base != XT_REG_INVALID /* Base only */
      && disp == 0 && index == XT_REG_INVALID) {
    return xa::XReg(base);
  } else if (base != XT_REG_INVALID && disp != 0 /* Base + disp */
             && index == XT_REG_INVALID) {
    xa_->add_imm(retReg, xa::XReg(base), disp, tmp1);
    return retReg;
  } else if (base != XT_REG_INVALID && disp == 0 /* Base + index (*scale) */
             && index != XT_REG_INVALID) {
    if (shift == 0) {
      xa_->add(retReg, xa::XReg(base), xa::XReg(index));
      return retReg; /* Base + disp + index */
    } else {
      xa_->lsl(retReg, xa::XReg(index), shift);
      xa_->add(retReg, xa::XReg(base), retReg);
      return retReg; /* Base + disp + index*scale */
    }
  } else if (base != XT_REG_INVALID && disp != 0 &&
             index != XT_REG_INVALID) { /* Base + disp + index (*scale) */
    xa_->add_imm(retReg, xa::XReg(base), disp, tmp1);

    if (shift == 0) {
      xa_->add(retReg, retReg, xa::XReg(index));
      return retReg; /* Base + disp + index */
    } else {
      xa_->lsl(tmp1, xa::XReg(index), shift);
      xa_->add(retReg, retReg, tmp1);
      return retReg; /* Base + disp + index*scale */
    }
  } else if (base == XT_REG_INVALID /* disp + index (*scale) */
             && index != XT_REG_INVALID && disp != 0) {
    if (shift == 0) {
      xa_->add_imm(retReg, xa::XReg(index), disp, tmp1);
      return retReg; /* disp + index */
    } else {
      xa_->lsl(retReg, xa::XReg(index), shift);
      xa_->add_imm(retReg, retReg, disp, tmp1);
      return retReg; /* disp + index*scale */
    }
  } else if (base == XT_REG_INVALID /* index (*scale) */
             && index != XT_REG_INVALID && disp == 0) {
    if (shift == 0) {
      return xa::XReg(index); /* index */
    } else {
      xa_->lsl(retReg, xa::XReg(index), shift);
      return retReg; /* index*scale */
    }
  }

  /* If xbyak_translator comes here, something wrong. */
  xt_msg_err(__FILE__, __LINE__,
             ":Something wrong. Please contact to system administrator!");
  return retReg;
}

unsigned int xt_push_vreg(xt_a64fx_operands_struct_t *a64) {
  return xt_push_zreg(a64);
}

unsigned int xt_push_vreg(xt_a64fx_operands_structV3_t *a64) {
  return xt_push_zreg(a64);
}

unsigned int xt_push_zreg(xt_a64fx_operands_struct_t *a64) {
  for (int i = 0; i < 32; i++) {
    if (availableZReg[i] == true && unusedZReg[i] == true) {
      unusedZReg[i] = false;
      return i;
    }
  }

  for (size_t i = AARCH64_NUM_ZREG - 1; i >= 0; i--) {
    if (a64->dstIdx != i && a64->srcIdx != i && a64->src2Idx != i) {
      if (zreg_tmp_used[i] == false) {
        zreg_tmp_used[i] = true;

#ifdef XT_AARCH64_STACK_REG
        xa_->sub(xa_->sp, xa_->sp, NUM_BYTES_Z_REG);
        xa_->mov(X_TMP_0, xa_->sp);
        xa_->str(xa::ZReg(i), xa::ptr(X_TMP_0));
#else //#ifdef XT_AARCH64_STACK_REG
        xa_->sub(X_TRANSLATOR_STACK, X_TRANSLATOR_STACK, NUM_BYTES_Z_REG);
        xa_->str(xa::ZReg(i), xa::ptr(X_TRANSLATOR_STACK));
#endif //#ifdef XT_AARCH64_STACK_REG
        return i;
      }
    }
  }

  std::cerr << __FILE__ << ":" << __LINE__ << ":Temporal ZReg allocation failed"
            << ". Please contact to system administrator!" << std::endl;
  assert(NULL);

  return 31;
}

unsigned int xt_push_zreg(xt_a64fx_operands_structV3_t *a64) {
  for (int i = 0; i < 32; i++) {
    if (availableZReg[i] == true && unusedZReg[i] == true) {
      unusedZReg[i] = false;
      return i;
    }
  }

  for (size_t i = AARCH64_NUM_ZREG - 1; i >= 0; i--) {
    bool conflict = false;
    if (zreg_tmp_used[i] == true) {
      continue;
    }

    for (unsigned int idx = 0; idx < xtNumOperands; idx++) {
      if (a64->operands[idx].regIdx == i) {
        conflict = true;
      }
    }

    if (conflict == false) {
      zreg_tmp_used[i] = true;
#ifdef XT_AARCH64_STACK_REG
      xa_->sub(xa_->sp, xa_->sp, NUM_BYTES_Z_REG);
      xa_->mov(X_TMP_0, xa_->sp);

      xa_->str(xa::ZReg(i), xa::ptr(X_TMP_0));
#else //#ifdef XT_AARCH64_STACK_REG
      xa_->sub(X_TRANSLATOR_STACK, X_TRANSLATOR_STACK, NUM_BYTES_Z_REG);
      xa_->str(xa::ZReg(i), xa::ptr(X_TRANSLATOR_STACK));
#endif //#ifdef XT_AARCH64_STACK_REG
      return i;
    }
  }

  std::cerr << __FILE__ << ":" << __LINE__ << ":Temporal PReg allocation failed"
            << ". Please contact to system administrator!" << std::endl;
  assert(NULL);

  return 31;
}

unsigned int xt_push_preg(xt_a64fx_operands_struct_t *a64) {
  for (int i = 0; i < 8; i++) {
    if (availablePReg[i] == true && unusedPReg[i] == true) {
      unusedPReg[i] = false;
      return i;
    }
  }

  for (size_t i = TMP_PREG_START; i >= TMP_PREG_END; i--) {
    if (a64->dstIdx != i && a64->srcIdx != i && a64->src2Idx != i &&
        a64->maskIdx != i && a64->mask2Idx != 0) {
      if (preg_tmp_used[i] == false) {
        preg_tmp_used[i] = true;

#ifdef XT_AARCH64_STACK_REG
        xa_->sub(xa_->sp, xa_->sp, NUM_BYTES_PRED_REG);
        xa_->mov(X_TMP_0, xa_->sp);
        xa_->str(xa::PReg(i), xa::ptr(X_TMP_0));
#else //#ifdef XT_AARCH64_STACK_REG
        xa_->sub(X_TRANSLATOR_STACK, X_TRANSLATOR_STACK, NUM_BYTES_PRED_REG);
        xa_->str(xa::PReg(i), xa::ptr(X_TRANSLATOR_STACK));
#endif //#ifdef XT_AARCH64_STACK_REG
        return i;
      }
    }
  }

  std::cerr << __FILE__ << ":" << __LINE__ << ":Temporal PReg allocation failed"
            << ". Please contact to system administrator!" << std::endl;
  assert(NULL);

  return 31;
}

unsigned int xt_push_preg(xt_a64fx_operands_structV3_t *a64) {

  for (int i = 0; i < 8; i++) {
    if (availablePReg[i] == true && unusedPReg[i] == true) {
      unusedPReg[i] = false;
      return i;
    }
  }

  for (size_t i = TMP_PREG_START; i >= TMP_PREG_END; i--) {
    bool conflict = false;
    if (preg_tmp_used[i] == true) {
      continue;
    }

    for (unsigned int idx = 0; idx < xtNumOperands; idx++) {
      if (a64->operands[idx].regIdx == i) {
        conflict = true;
      }
    }

    if (conflict == false) {
      preg_tmp_used[i] = true;

#ifdef XT_AARCH64_STACK_REG
      xa_->sub(xa_->sp, xa_->sp, NUM_BYTES_PRED_REG);
      xa_->mov(X_TMP_0, xa_->sp);
      xa_->str(xa::PReg(i), xa::ptr(X_TMP_0));
#else //#ifdef XT_AARCH64_STACK_REG
      xa_->sub(X_TRANSLATOR_STACK, X_TRANSLATOR_STACK, NUM_BYTES_PRED_REG);
      xa_->str(xa::PReg(i), xa::ptr(X_TRANSLATOR_STACK));
#endif //#ifdef XT_AARCH64_STACK_REG
      return i;
    }
  }

  std::cerr << __FILE__ << ":" << __LINE__ << ":Temporal PReg allocation failed"
            << ". Please contact to system administrator!" << std::endl;
  assert(NULL);

  return 31;
}

void xt_pop_vreg() { xt_pop_zreg(); }

void xt_pop_zreg() {
  for (int i = 0; i < 32; i++) {
    if (availableZReg[i] == true && unusedZReg[i] == false) {
      unusedZReg[i] = true;
      return;
    }
  }

  for (size_t i = 0; i < AARCH64_NUM_ZREG; i++) {
    if (zreg_tmp_used[i] == true) {
#ifdef XT_AARCH64_STACK_REG
      xa_->mov(X_TMP_0, xa_->sp);
      xa_->ldr(xa::ZReg(i), xa::ptr(X_TMP_0));
      xa_->add(xa_->sp, xa_->sp, NUM_BYTES_Z_REG);
#else //#ifdef XT_AARCH64_STACK_REG
      xa_->ldr(xa::ZReg(i), xa::ptr(X_TRANSLATOR_STACK));
      xa_->add(X_TRANSLATOR_STACK, X_TRANSLATOR_STACK, NUM_BYTES_Z_REG);
#endif //#ifdef XT_AARCH64_STACK_REG
      zreg_tmp_used[i] = false;
      return;
    }
  }

  std::cerr << __FILE__ << ":" << __LINE__ << ":Restoreing temporal ZReg failed"
            << ". Please contact to system administrator!" << std::endl;
  assert(NULL);
}

void xt_pop_preg() {

  for (int i = 0; i < 8; i++) {
    if (availablePReg[i] == true && unusedPReg[i] == false) {
      unusedPReg[i] = true;
      return;
    }
  }

  for (size_t i = TMP_PREG_END; i <= TMP_PREG_START; i++) {
    if (preg_tmp_used[i] == true) {
#ifdef XT_AARCH64_STACK_REG
      xa_->mov(X_TMP_0, xa_->sp);
      xa_->ldr(xa::PReg(i), xa::ptr(X_TMP_0));
      xa_->add(xa_->sp, xa_->sp, NUM_BYTES_PRED_REG);
#else //#ifdef XT_AARCH64_STACK_REG
      xa_->ldr(xa::PReg(i), xa::ptr(X_TRANSLATOR_STACK));
      xa_->add(X_TRANSLATOR_STACK, X_TRANSLATOR_STACK, NUM_BYTES_PRED_REG);
#endif //#ifdef XT_AARCH64_STACK_REG
      preg_tmp_used[i] = false;
      return;
    }
  }

  std::cerr << __FILE__ << ":" << __LINE__ << ":Restoreing temporal PReg failed"
            << ". Please contact to system administrator!" << std::endl;
  assert(NULL);
}

#include "xbyak_translator_inc_def.h"

bool decodeOpcode(const Label *label = nullptr) {
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

  const uint8_t *top = Xbyak::CodeArray::top_;
  size_t size = Xbyak::CodeArray::size_;
#ifdef XT_DEBUG
  printf("Attempting to decode: ");
  for (size_t i = 0; i < size; i++)
    printf("%02x ", top[i]);
  printf("\n");
#endif

  xed_error = xed_decode(&xedd, top, size);

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
#ifdef XT_DEBUG
  xt_dump_x86_64_decoded_info(&xedd);
#endif

  if (genJitMode == true) {
    xed_iclass_enum_t p = xed_decoded_inst_get_iclass(&xedd);
#include "xbyak_translator_switch.h"
  } else {
    searchPReg(&xedd);
    searchZReg(&xedd);
  }

  return true;
}

void xt_construct_a64fx_operands(xed_decoded_inst_t *p,
                                 xt_a64fx_operands_struct_t *a64) {
  unsigned int num_operands;

  unsigned int baseIdx = XT_REG_INVALID;
  unsigned int indexIdx = XT_REG_INVALID;

  xed_uint_t scale = 0;
  xed_int64_t disp = 0;
  const xed_inst_t *xi = xed_decoded_inst_inst(p);
  //  xed_reg_enum_t dstReg = xed_decoded_inst_get_reg(p, opDst);
  xed_bool_t isDstSet = false;
  xed_bool_t isMaskSet = false;
  xed_bool_t isSrcSet = false;
  xed_bool_t isSrc2Set = false;
  xed_bool_t isMemOpSet = false;

  /* Get EVEX.b bits */
  a64->EVEXb = xed_decoded_inst_is_broadcast(p);

  /* Get # of operands */
  num_operands = xed_inst_noperands(xi);

  for (unsigned int i = 0; i < num_operands; i++) {
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
          a64->dstRegClass = xed_reg_class(xed_decoded_inst_get_reg(p, opName));
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
            a64->PredType = A64_PRED_MERG;
            /*            xt_msg_err(__FILE__, __LINE__,
                       "Unknwon predicate type. Please contact to "
                       "system administrator!");*/
          }

          isMaskSet = true;
        }
      } else { // if(XED_REG_K0 <= r && r <= XED_REG_K7) {
        if (isDstSet == false) {
          a64->dstType = A64_OP_REG;
          a64->dstIdx = tmpIdx;
          isDstSet = true;
          a64->dstWidth = xed_decoded_inst_operand_length_bits(p, i);
          a64->dstRegClass = xed_reg_class(xed_decoded_inst_get_reg(p, opName));
        } else if (isSrcSet == false) {
          a64->srcType = A64_OP_REG;
          a64->srcIdx = tmpIdx;
          isSrcSet = true;
          a64->srcWidth = xed_decoded_inst_operand_length_bits(p, i);
          a64->srcRegClass = xed_reg_class(xed_decoded_inst_get_reg(p, opName));
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
      xed_uint32_t tmpScale;

      tmpReg = xed_decoded_inst_get_seg_reg(p, 0);
      if (tmpReg != XED_REG_INVALID) {
        xt_msg_err(__FILE__, __LINE__,
                   "Unsupported address mode. Please contact to system "
                   "administrator!");
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
        a64->srcWidth = xed_decoded_inst_operand_length_bits(p, i);
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
        a64->srcWidth = xed_decoded_inst_operand_length_bits(p, i);
      } else if (isSrc2Set == false) {
        a64->src2Type = A64_OP_IMM;
        isSrc2Set = true;
      } else {
        /* For example, VPINSRB instruction has dstReg, srcReg, src2Reg, and
           IMM, so that if program comes here, it's not a bug. */
      }
      if (opName == XED_OPERAND_IMM0) {
        xed_uint_t ibits;

        ibits = xed_decoded_inst_get_immediate_width_bits(p);
        if (xed_decoded_inst_get_immediate_is_signed(p)) {
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
    xt_msg_err(__FILE__, __LINE__,
               "Unsupported opName=" +
                   std::to_string(static_cast<int64_t>(opName)));
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

#ifdef XT_DEBUG
  xt_dump_a64fx_operands(a64);
#endif
}

void xt_construct_a64fx_operandsV3(xed_decoded_inst_t *p,
                                   xt_a64fx_operands_structV3_t *a64,
                                   bool vm64 = false, bool rawMemOp = false) {
  unsigned int num_operands;

  unsigned int baseIdx = XT_REG_INVALID;
  unsigned int indexIdx = XT_REG_INVALID;

  xed_uint_t scale = 0;
  xed_int64_t disp = 0;
  unsigned int memOpIdx = 0;
  X_TMP_ADDR = X_DEFAULT_ADDR;

  const xed_inst_t *xi = xed_decoded_inst_inst(p);

  /* Get EVEX.b bits */
  a64->EVEXb = xed_decoded_inst_is_broadcast(p);

  /* Get EVEX.rc bits */
  a64->EVEXrc = xed3_operand_get_roundc(p);

  /* Get # of operands */
  num_operands = xed_inst_noperands(xi);

  for (unsigned int i = 0; i < num_operands; i++) {
    const xed_operand_t *op = xed_inst_operand(xi, i);
    xed_operand_enum_t opName = xed_operand_name(op);

    /* Begin: parsing register operand */
    xed_uint_t isReg = xed_operand_is_register(opName);
    if (isReg == 1) { /* Operand is register */
      xed_reg_enum_t r = xed_decoded_inst_get_reg(p, opName);
      unsigned int tmpIdx = xt_get_register_index(r);
      bool isSet = false;

      for (int l = 0; l < 4 && isSet == false; l++) {
        if (a64->operands[l].opName == XED_OPERAND_INVALID) {
          a64->operands[l].opName = opName;
          a64->operands[l].regIdx = tmpIdx;
          a64->operands[l].regClass =
              xed_reg_class(xed_decoded_inst_get_reg(p, opName));
          a64->operands[l].opWidth = xed_decoded_inst_operand_length_bits(p, i);

          if (a64->operands[l].regClass == XED_REG_CLASS_MASK) {
            xed_bool_t isMasking = xed_decoded_inst_masking(p);
            xed_bool_t isMerging = xed_decoded_inst_merging(p);
            xed_bool_t isZeroing = xed_decoded_inst_zeroing(p);
            if (!isMasking) {
              a64->predType = A64_PRED_NO;
            } else if (isMerging) {
              a64->predType = A64_PRED_MERG;
            } else if (isZeroing) {
              a64->predType = A64_PRED_ZERO;
            } else {
              a64->predType = A64_PRED_MERG;
              /*            xt_msg_err(__FILE__, __LINE__,
                            "Unknwon predicate type. Please contact to "
                            "system administrator!");*/
            }
          }
          isSet = true;
        }
      }

      if (isSet == false) {
        xt_msg_err(__FILE__, __LINE__,
                   "Unknwon # of register operands. Please contact to "
                   "system administrator!");
      }
      continue; /* End of register operand process */
    }
    /* End: parsing register operand */

    /* Begin: parsing memory operand */
    if (opName == XED_OPERAND_MEM0 || opName == XED_OPERAND_AGEN) {
      unsigned int width =
          xed_decoded_inst_get_memop_address_width(p, memOpIdx);

      int tmpOpIdx = 0;
      bool isSet = false;

      for (int l = 0; l < 4 && isSet == false; l++) {
        if (a64->operands[l].opName == XED_OPERAND_INVALID) {
          a64->operands[l].opName = opName;
          a64->operands[l].opWidth = width;
          a64->operands[l].opWidth = xed_decoded_inst_operand_length_bits(p, i);
          isSet = true;
          tmpOpIdx = l;
        }
      }

      if (isSet == false) {
        xt_msg_err(__FILE__, __LINE__,
                   "Unknwon # of memory operands. Please contact to "
                   "system administrator!");
      }

      xed_reg_enum_t tmpReg;
      xed_uint32_t tmpScale;

      tmpReg = xed_decoded_inst_get_seg_reg(p, memOpIdx);
      if (tmpReg != XED_REG_INVALID) {
        /* use of segmentation register is legacy case. */
      }

      tmpReg = xed_decoded_inst_get_base_reg(p, memOpIdx);
      if (tmpReg != XED_REG_INVALID) {
        baseIdx = xt_get_register_index(tmpReg);
      }

      tmpReg = xed_decoded_inst_get_index_reg(p, memOpIdx);
      if (tmpReg != XED_REG_INVALID) {
        indexIdx = xt_get_register_index(tmpReg);

        if (vm64) {
          a64->operands[tmpOpIdx].vmIndexRegIdx = indexIdx;

          switch (xed_reg_class(tmpReg)) {
          case XED_REG_CLASS_XMM:
            a64->operands[tmpOpIdx].vmIndexRegWidth = 128;
            break;
          case XED_REG_CLASS_YMM:
            a64->operands[tmpOpIdx].vmIndexRegWidth = 256;
            break;
          case XED_REG_CLASS_ZMM:
            a64->operands[tmpOpIdx].vmIndexRegWidth = 512;
            break;
          default:
            xt_msg_err(__FILE__, __LINE__,
                       "Unknwon vm64 index register width. Please contact to "
                       "system administrator!");
          }
        }

        tmpScale = xed_decoded_inst_get_scale(p, memOpIdx);
        if (tmpScale) {
          scale = tmpScale;
        }
      }

      disp = xed_decoded_inst_get_memory_displacement(p, memOpIdx);

      if (rawMemOp) {
        a64->operands[tmpOpIdx].memBaseIdx = baseIdx;
        a64->operands[tmpOpIdx].memIndexIdx = indexIdx;
        a64->operands[tmpOpIdx].memScale = scale;
        a64->operands[tmpOpIdx].memDisp = disp;
      } else if (vm64) {
        a64->operands[tmpOpIdx].memBaseIdx = baseIdx;
        a64->operands[tmpOpIdx].memIndexIdx = indexIdx;
        a64->operands[tmpOpIdx].memScale = scale;
        xa_->add_imm(X_TMP_ADDR, xa::XReg(baseIdx), disp, X_TMP_1);
      } else {
        X_TMP_ADDR = xt_get_addr_reg(baseIdx, disp, indexIdx, scale, X_TMP_ADDR,
                                     X_TMP_1, X_TMP_2, vm64);
      }

      memOpIdx++;
      continue;
    }
    /* End: parsing memory operand */

    /* Begin: parsing immediate operand */
    if (opName == XED_OPERAND_IMM0) {
      bool isSet = false;

      for (unsigned int l = 0; l < xtNumOperands && isSet == false; l++) {
        if (a64->operands[l].opName == XED_OPERAND_INVALID) {
          a64->operands[l].opName = opName;

          xed_uint_t ibits;
          ibits = xed_decoded_inst_get_immediate_width_bits(p);
          if (xed_decoded_inst_get_immediate_is_signed(p)) {
            xed_int32_t x = xed_decoded_inst_get_signed_immediate(p);
            a64->operands[l].uimm = XED_STATIC_CAST(
                xed_uint64_t,
                xed_sign_extend_arbitrary_to_64((xed_uint64_t)x, ibits));
          } else {
            a64->operands[l].uimm = xed_decoded_inst_get_unsigned_immediate(p);
          }

          a64->operands[l].opWidth = ibits;
          isSet = true;
        }
      }

      if (isSet == false) {
        xt_msg_err(__FILE__, __LINE__,
                   "Unknwon # of register operands. Please contact to "
                   "system administrator!");
      }
      continue;
    }
    /* End: parsing immediate operand */

    /* Begin: parsing address generation operand */
    if (opName == XED_OPERAND_AGEN) {
      bool isSet = false;

      for (int l = 0; l < 4 && isSet == false; l++) {
        if (a64->operands[l].opName == XED_OPERAND_INVALID) {
          a64->operands[l].opName = opName;
          isSet = true;
        }
      }
      continue;
    }
    /* End: parsing address generation operand */

    xt_msg_err(__FILE__, __LINE__, "Unsupported opName");
  } // for (int i = 0; i < num_operands; i++) {

#ifdef XT_DEBUG
  if (!rawMemOp) {
    xt_dump_a64fx_operandsV3(a64);
  }
#endif
}

void xt_construct_a64fx_operandsV3_rawMemOp(xed_decoded_inst_t *p,
                                            xt_a64fx_operands_structV3_t *a64,
                                            bool vm64, bool rawMemOp) {
  xt_construct_a64fx_operandsV3(p, a64, vm64, rawMemOp);
  if (rawMemOp) {
    xt_dump_a64fx_operandsV3(a64);
  }
}

void searchPReg(xed_decoded_inst_t *p) {
  unsigned int num_operands;

  const xed_inst_t *xi = xed_decoded_inst_inst(p);

  /* Get # of operands */
  num_operands = xed_inst_noperands(xi);

  for (unsigned int i = 0; i < num_operands; i++) {
    const xed_operand_t *op = xed_inst_operand(xi, i);
    xed_operand_enum_t opName = xed_operand_name(op);

    /* Begin: parsing register operand */
    xed_uint_t isReg = xed_operand_is_register(opName);
    if (isReg == 1) { /* Operand is register */
      xed_reg_enum_t r = xed_decoded_inst_get_reg(p, opName);
      unsigned int tmpIdx = xt_get_register_index(r);
      // bool isSet = false;

      if (xed_reg_class(xed_decoded_inst_get_reg(p, opName)) ==
          XED_REG_CLASS_MASK) {
        if (availablePReg[tmpIdx] == true && tmpIdx != P_ALL_ONE_0_7_IDX) {
          availablePReg[tmpIdx] = false;
          unusedPReg[tmpIdx] = false;
        }
      }
      continue; /* End of register operand process */
    }
    /* End: parsing register operand */
  } // for (int i = 0; i < num_operands; i++) {
}

void searchZReg(xed_decoded_inst_t *p) {
  unsigned int num_operands;

  const xed_inst_t *xi = xed_decoded_inst_inst(p);

  /* Get # of operands */
  num_operands = xed_inst_noperands(xi);

  for (unsigned int i = 0; i < num_operands; i++) {
    const xed_operand_t *op = xed_inst_operand(xi, i);
    xed_operand_enum_t opName = xed_operand_name(op);

    /* Begin: parsing register operand */
    xed_uint_t isReg = xed_operand_is_register(opName);
    if (isReg == 1) { /* Operand is register */
      xed_reg_enum_t r = xed_decoded_inst_get_reg(p, opName);
      unsigned int tmpIdx = xt_get_register_index(r);
      // bool isSet = false;

      if (xed_reg_class(xed_decoded_inst_get_reg(p, opName)) ==
              XED_REG_CLASS_XMM ||
          xed_reg_class(xed_decoded_inst_get_reg(p, opName)) ==
              XED_REG_CLASS_YMM ||
          xed_reg_class(xed_decoded_inst_get_reg(p, opName)) ==
              XED_REG_CLASS_ZMM) {
        if (availableZReg[tmpIdx] == true) {
          availableZReg[tmpIdx] = false;
          unusedZReg[tmpIdx] = false;
        }
      }
      continue; /* End of register operand process */
    }
    /* End: parsing register operand */
  } // for (int i = 0; i < num_operands; i++) {
}

void decodeAndTransToAArch64() {
  decode_size_ = 0;
  decodeOpcode();
  db_clear();
}

void decodeAndTransToAArch64(xt_cmp_x86_64_t cmp_mode, const Label &label) {
  switch (cmp_mode) {
  case X86_64_A:
#if 0
  X86_64_AE:
#endif
    xt_msg_err(__FILE__, __LINE__, ":Unsupported branch condition!");
    break;
  case X86_64_B: {
    xa::Label L0, L1;
    xa_->mrs(X_TMP_2, 0x3, 0x3, 0x4, 0x2, 0x0); // Read NZCV register
    xa_->lsr(X_TMP_0, X_TMP_2, 28);

    /* (x86_64's CF)
       aarch64's ((V==1 &&C==0) || (V==0 && C==0)) */
    xa_->and_(X_TMP_1, X_TMP_0, 0x3); // extract C and V flags
    xa_->cmp(X_TMP_1, 0x1);           // Check if (C==0 && V==1)
    xa_->b(xa::NE, L0);
    xa_->msr(0x3, 0x3, 0x4, 0x2, 0x0, X_TMP_2); // Recover NZCV register
    xa_->b(label);
    xa_->L(L0);
    xa_->cmp(X_TMP_1, 0x0); // Check if (C==0 && V==0)
    xa_->b(xa::NE, L1);
    xa_->msr(0x3, 0x3, 0x4, 0x2, 0x0, X_TMP_2); // Recover NZCV register
    xa_->b(label);
    xa_->L(L1);

    xa_->msr(0x3, 0x3, 0x4, 0x2, 0x0, X_TMP_2); // Recover NZCV register
  } break;
  case X86_64_BE: {
    xa::Label L0, L1, L2;
    xa_->mrs(X_TMP_2, 0x3, 0x3, 0x4, 0x2, 0x0); // Read NZCV register
    xa_->lsr(X_TMP_0, X_TMP_2, 28);

    /* (x86_64's CF)
       aarch64's ((V==1 &&C==0) || (V==0 && C==0)) */
    xa_->and_(X_TMP_1, X_TMP_0, 0x3); // extract C and V flags
    xa_->cmp(X_TMP_1, 0x1);           // Check if (C==0 && V==1)
    xa_->b(xa::NE, L0);
    xa_->msr(0x3, 0x3, 0x4, 0x2, 0x0, X_TMP_2); // Recover NZCV register
    xa_->b(label);
    xa_->L(L0);
    xa_->cmp(X_TMP_1, 0x0); // Check if (C==0 && V==0)
    xa_->b(xa::NE, L1);
    xa_->msr(0x3, 0x3, 0x4, 0x2, 0x0, X_TMP_2); // Recover NZCV register
    xa_->b(label);
    xa_->L(L1);

    xa_->and_(X_TMP_1, X_TMP_0, 0x4);
    xa_->cmp(X_TMP_1, 0x4);
    xa_->b(xa::NE, L2);
    xa_->msr(0x3, 0x3, 0x4, 0x2, 0x0, X_TMP_2); // Recover NZCV register
    xa_->b(label);
    xa_->L(L2);
    xa_->msr(0x3, 0x3, 0x4, 0x2, 0x0, X_TMP_2); // Recover NZCV register
  } break;
#if 0
  X86_64_C:
  X86_64_CXZ:
  X86_64_ECXZ:
  X86_64_RCXZ:
    xt_msg_err(__FILE__, __LINE__, ":Unsupported branch condition!");
    break;
  X86_64_E:
    xa_->b(xa::EQ, label);
    break;
  X86_64_G:
    xa_->b(xa::GT, label);
    break;
  X86_64_GE:
    xa_->b(xa::GE, label);
    break;
  X86_64_L:
    xa_->b(xa::LT, label);
    break;
  X86_64_LE:
    xa_->b(xa::LE, label);
    break;
  X86_64_NA:
  X86_64_NAE:
  X86_64_NB:
  X86_64_NBE:
  X86_64_NC:
    xt_msg_err(__FILE__, __LINE__, ":Unsupported branch condition!");
    break;
  X86_64_NE:
    xa_->b(xa::NE, label);
    break;
  X86_64_NG:
  X86_64_NGE:
  X86_64_NL:
  X86_64_NLE:
  X86_64_NO:
  X86_64_NP:
  X86_64_NS:
  X86_64_NZ:
  X86_64_O:
  X86_64_P:
  X86_64_PE:
  X86_64_PO:
  X86_64_S:
  X86_64_Z:
    xt_msg_err(__FILE__, __LINE__, ":Unsupported branch condition!");
    break;
#endif
  default:
    xt_msg_err(__FILE__, __LINE__, ":Unsupported branch condition!");
    break;
  }
}
#else //#ifdef XBYAK_TRANSLATE_AARCH64
void decodeAndTransToAArch64() {}
#endif //#ifdef XBYAK_TRANSLATE_AARCH64

//} //namespace xbyak_translator {
