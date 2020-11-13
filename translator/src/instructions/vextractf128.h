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
/* 2020/09/03 15:49 */

void translateVEXTRACTF128(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  uint uimm = 0;

  /* Col=T119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=AD119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AG119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AH119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 && true)) {
    uimm = a64.operands[2].uimm;
  }
  /* Col=AK119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 && true)) {
    if ((uimm & 1) == 0) {
      xa_->mov(xa::VReg(dstIdx).b16, xa::VReg(srcIdx).b16);
    } else {
      zTmpIdx = xt_push_zreg(&a64);
      xa_->mov(xa::ZRegD(zTmpIdx), xa::ZRegD(srcIdx));
      xa_->ext(xa::ZRegB(zTmpIdx), xa::ZRegB(srcIdx), 16);
      xa_->mov(xa::VReg(dstIdx).b16, xa::VReg(zTmpIdx).b16);
      xt_pop_zreg();
    }
  }
  /* Col=BQ119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
