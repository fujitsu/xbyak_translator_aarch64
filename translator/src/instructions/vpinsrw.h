/*******************************************************************************
 * Copyright 2020 FUJITSU LIMITED
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
/* 2020/05/26 22:09 */

void Xbyak::CodeGenerator::translateVPINSRW(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t src2Idx = XT_REG_INVALID;
  xed_uint64_t uimm = 0;

  /* Col=AH119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AK119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AL119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AM119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 && true)) {
    uimm = a64.operands[3].uimm;
    ;
  }
  /* Col=AO119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 && true)) {
    xa_->ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AQ119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 && true)) {
    xa_->mov(xa::VReg(dstIdx).b16, xa::VReg(srcIdx).b16);
  }
  /* Col=AS119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 && true)) {
    xa_->ins_(xa::VReg8H(dstIdx)[uimm], xa::WReg(src2Idx));
  }
  /* Col=AT119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 && true)) {
    xa_->ins_(xa::VReg8H(dstIdx)[uimm], W_TMP_0);
  }
  /* Col=BO119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
