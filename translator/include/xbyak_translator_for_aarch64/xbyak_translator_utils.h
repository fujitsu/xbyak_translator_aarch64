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
#include <ostream>

typedef unsigned int xt_reg_idx_t;
typedef xed_int64_t xt_disp_t;
typedef xed_uint_t xt_scale_t;

#define XT_REG_INVALID std::numeric_limits<xt_reg_idx_t>::max()
#define XT_DISP_INVALID std::numeric_limits<xt_disp_t>::max()
#define XT_SCALE_INVALID std::numeric_limits<xt_scale_t>::max()

void xt_msg_warn(const char *fileName, const int lineNum,
                 const std::string &msg) {
  xt_msg_warn(fileName, lineNum, msg.c_str());
}

void xt_msg_warn(const char *fileName, const int lineNum, const char *msg) {
  std::cerr << "[WARN]:" << fileName << ":" << lineNum << ":" << msg
            << std::endl;
}

void xt_msg_err(const char *fileName, const int lineNum,
                const std::string &msg) {
  xt_msg_err(fileName, lineNum, msg.c_str());
}

void xt_msg_err(const char *fileName, const int lineNum, const char *msg) {
  std::cerr << "[ERR ]:" << fileName << ":" << lineNum << ":" << msg
            << std::endl;
  assert(NULL);
  exit(1);
}

const std::string xt_to_string(const xt_reg_idx_t idx) {
  // const char *xt_to_string(const xt_reg_idx_t idx) {
  std::string msg;

  if (idx == XT_REG_INVALID) {
    msg = "not assigned";
  } else {
    msg = std::to_string(idx);
  }

  return msg;
  //  return msg.c_str();
}

enum xt_predicate_type_t {
  /* Type of predicate (mask) mode
     A64_PRED_NO:No mask mode exist
     A64_PRED_MERG:Merge predicate
     A64_PRED_ZERO:Zeroing predicate */
  A64_PRED_INIT = 0,
  A64_PRED_NO,
  A64_PRED_MERG,
  A64_PRED_ZERO,
};

const std::string xt_to_string(const xt_predicate_type_t type) {
  std::string msg;

  switch (type) {
  case A64_PRED_INIT:
    msg = "A64_PRED_INIT";
    break;
  case A64_PRED_NO:
    msg = "A64_PRED_NO";
    break;
  case A64_PRED_MERG:
    msg = "A64_PRED_MERG";
    break;
  case A64_PRED_ZERO:
    msg = "A64_PRED_ZERO";
    break;
  default:
    msg = "Undefined xt_predicate_type_t";
    break;
  }

  return msg;
}

enum xt_operand_type_t {
  A64_OP_INIT = 0,
  A64_OP_REG,
  A64_OP_MEM,
  A64_OP_IMM,
};

const std::string xt_to_string(const xt_operand_type_t type) {
  std::string msg;

  switch (type) {
  case A64_OP_INIT:
    msg = "A64_OP_INIT";
    break;
  case A64_OP_REG:
    msg = "A64_OP_REG";
    break;
  case A64_OP_MEM:
    msg = "A64_OP_MEM";
    break;
  case A64_OP_IMM:
    msg = "A64_OP_IMM";
    break;
  default:
    msg = "Undefined xt_operand_type_t";
    break;
  }

  return msg;
}

/* This implementation is copied from Intel's xed/src/common/xed-util.c
   arbitrary sign extension from a qty of "bits" length to 64b */
xed_int64_t xed_sign_extend_arbitrary_to_64(xed_uint64_t x, unsigned int bits) {
  xed_uint64_t one = 1;
  xed_int64_t mask = one << (bits - 1);
  xed_int64_t vmask, o = 0;
  if (bits < 64) {
    vmask = (one << bits) - 1;
    o = ((x & vmask) ^ mask) - mask;
  } else if (bits == 64)
    o = x;
  else
    xed_assert(0);
  return o;
}
