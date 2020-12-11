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
/*BEGIN_LEGAL

Copyright (c) 2019 Intel Corporation

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

END_LEGAL */
#include "xed-examples-util_aarch64.h"
#include "xed/xed-interface.h"

constexpr static unsigned int xtNumOperands = 5;

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

enum xt_cmp_x86_64_t {
  X86_64_A,
  X86_64_AE,
  X86_64_B,
  X86_64_BE,
  X86_64_C,
  X86_64_CXZ,
  X86_64_ECXZ,
  X86_64_RCXZ,
  X86_64_E,
  X86_64_G,
  X86_64_GE,
  X86_64_L,
  X86_64_LE,
  X86_64_NA,
  X86_64_NAE,
  X86_64_NB,
  X86_64_NBE,
  X86_64_NC,
  X86_64_NE,
  X86_64_NG,
  X86_64_NGE,
  X86_64_NL,
  X86_64_NLE,
  X86_64_NO,
  X86_64_NP,
  X86_64_NS,
  X86_64_NZ,
  X86_64_O,
  X86_64_P,
  X86_64_PE,
  X86_64_PO,
  X86_64_S,
  X86_64_Z,
};

enum xt_vcmp_x86_64_t {
  EQ_OQ = 0,
  LT_OS = 1,
  LE_OS = 2,
  UNORD_Q = 3,
  NEQ_UQ = 4,
  NLT_US = 5,
  NLE_US = 6,
  ORD_Q = 7,
  EQ_UQ = 8,
  NGE_US = 9,
  NGT_US = 10,
  FALSE_OQ = 11,
  NEQ_OQ = 12,
  GE_OS = 13,
  GT_OS = 14,
  TRUE_UQ = 15,
  EQ_OS = 16,
  LT_OQ = 17,
  LE_OQ = 18,
  UNORD_S = 19,
  NEQ_US = 20,
  NLT_UQ = 21,
  NLE_UQ = 22,
  ORD_S = 23,
  EQ_US = 24,
  NGE_UQ = 25,
  NGT_UQ = 26,
  FALSE_OS = 27,
  NEQ_OS = 28,
  GE_OQ = 29,
  GT_OQ = 30,
  TRUE_US = 31,
};

struct xt_a64fx_operands_structV3_core_t {
  xed_operand_enum_t opName = XED_OPERAND_INVALID;
  xt_reg_idx_t regIdx = XT_REG_INVALID;
  xed_uint_t opWidth = 0;
  xed_reg_class_enum_t regClass = XED_REG_CLASS_INVALID;
  xed_uint64_t uimm = 0;

  /* For operand of vm64(x|y|z) */
  xt_reg_idx_t vmIndexRegIdx = XT_REG_INVALID;
  xed_uint_t vmIndexRegWidth = 0;

  /* For memory operand */
  xt_reg_idx_t memBaseIdx = XT_REG_INVALID;
  xt_reg_idx_t memIndexIdx = XT_REG_INVALID;
  xed_uint_t memScale = 0;
  xed_int_t memDisp = 0;
};

struct xt_a64fx_operands_structV3_t {
  /* Is EVEX.b set? */
  xed_uint_t EVEXb = 0;
  xt_predicate_type_t predType = A64_PRED_NO;

  /* Rounding control (EVEX.RC) */
  xed_uint_t EVEXrc = 0;

  xt_a64fx_operands_structV3_core_t operands[xtNumOperands];
};

struct xt_a64fx_operands_struct_t {
  /* Index of DST register(1st operand) */
  //  unsigned int dstIdx = XT_REG_INVALID;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;

  /* Index of MASK register{k} */
  xt_reg_idx_t maskIdx = XT_REG_INVALID;
  xt_reg_idx_t mask2Idx = XT_REG_INVALID;

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
  xed_uint_t dstWidth = 0;
  xed_uint_t srcWidth = 0;

  xed_reg_class_enum_t dstRegClass = XED_REG_CLASS_INVALID;
  xed_reg_class_enum_t srcRegClass = XED_REG_CLASS_INVALID;

  /* Immediate value opoerand */
  xed_uint_t ibits = 0;
  xed_uint64_t uimm = 0; /* unsigned */
  xed_int64_t simm = 0;  /* signed */
  xed_uint_t immWidth;   /* IMM value width. 8, 16, 32, 64 */

  xed_uint64_t uimm2 = 0; /* 2nd immediate and its type is unsigned */
  xed_int64_t simm2 = 0;  /* 2nd immediate and its type is signed */

  xed_bool_t isDstMask =
      false; /* ture:dst operand is mask register, false:otherwise */
};

struct xt_a64fx_operands_structV3_t;
struct xt_a64fx_operands_struct_t;

void print_misc(xed_decoded_inst_t *xedd);
void print_attributes(xed_decoded_inst_t *xedd);
void print_reads_zf_flag(xed_decoded_inst_t *xedd);
void print_flags(xed_decoded_inst_t *xedd);
void print_memops(xed_decoded_inst_t *xedd);
void print_operands(xed_decoded_inst_t *xedd);
void xt_dump_a64fx_operandsV3(xt_a64fx_operands_structV3_t *a64);
void xt_dump_a64fx_operands(xt_a64fx_operands_struct_t *a64);
void xt_dump_x86_64_decoded_info(xed_decoded_inst_t *p);
