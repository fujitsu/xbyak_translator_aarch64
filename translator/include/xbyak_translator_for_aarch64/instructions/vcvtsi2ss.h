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
/* 2020/09/08 14:20 */

void translateVCVTSI2SS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t src2Idx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;

  /* Col=T119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].opWidth == 32 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opWidth == 32 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opWidth == 64 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].opWidth == 32 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opWidth == 32 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opWidth == 64 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=AD119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].opWidth == 64 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].opWidth == 64 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AE119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].opWidth == 64 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].opWidth == 64 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AF119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].opWidth == 64 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].opWidth == 64 && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AM119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].opWidth == 64 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].opWidth == 64 && true)) {
    if (dstIdx != srcIdx) {
      xa_->scvtf(xa::SReg(dstIdx), xa::XReg(src2Idx));
      for (int i = 1; i < 4; i++) {
        xa_->mov(xa::VReg(dstIdx).s4[i], xa::VReg(srcIdx).s4[i]);
      }
    } else {
      zTmpIdx = xt_push_zreg(&a64);
      xa_->mov(xa::ZRegD(zTmpIdx), xa::ZRegD(srcIdx));
      xa_->scvtf(xa::SReg(dstIdx), xa::XReg(src2Idx));
      for (int i = 1; i < 4; i++) {
        xa_->mov(xa::VReg(dstIdx).s4[i], xa::VReg(zTmpIdx).s4[i]);
      }
      xt_pop_zreg();
    }
  }
  /* Col=BQ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].opWidth == 32 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opWidth == 32 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].opWidth == 64 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opWidth == 64 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].opWidth == 32 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opWidth == 32 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].opWidth == 64 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opWidth == 64 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
