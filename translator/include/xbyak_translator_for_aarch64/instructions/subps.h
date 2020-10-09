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
/* 2020/09/01 09:32 */

void translateSUBPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;

  /* Col=T119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=U119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=AD119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AG119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AJ119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true)) {
    xa_->not_(xa::PRegB(pTmpIdx), P_ALL_ONE.b, P_MSB_384.b);
  }
  /* Col=AO119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true)) {
    xa_->fsub(xa::ZRegS(dstIdx), xa::PReg(pTmpIdx), xa::ZRegS(srcIdx));
  }
  /* Col=BJ119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true)) {
    xt_pop_preg();
  }
  /* Col=BQ119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}

