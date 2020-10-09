/*******************************************************************************
 * Copyright 2020 FUJITSU LIMITED
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
/* 2020/09/07 23:07 */

void translatePEXTRB(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xed_uint64_t uimm = 0;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;

  /* Col=X119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 32 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=Y119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }

  /* Col=AF119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 && true)) {
    uimm = a64.operands[2].uimm & 0xf;
  }
  /* Col=AJ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 32 && true)) {
    xa_->umov(xa::WReg(dstIdx), xa::VReg16B(srcIdx)[uimm]);
  }

  /* Col=AO119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 && true)) {
    xa_->st1(xa::VReg16B(srcIdx)[uimm], xa::ptr(X_TMP_ADDR));
  }

  /* Col=BQ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
