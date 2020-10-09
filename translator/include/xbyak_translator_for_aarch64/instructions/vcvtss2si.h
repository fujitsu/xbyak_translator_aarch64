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
/* 2020/09/10 00:04 */

void translateVCVTSS2SI(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;

  /* Col=T119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.EVEXb == 0 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.EVEXb == 1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=W119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 64 && a64.EVEXb == 0 && true)) {
    if (a64.EVEXrc == 0) {
      zTmpIdx = xt_push_zreg(&a64);
    }
  }

  /* Col=AD119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 64 && a64.EVEXb == 0 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AG119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 64 && a64.EVEXb == 0 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AI119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 64 && a64.EVEXb == 0 && true)) {
    switch (a64.EVEXrc) {
    case 0:
      xa_->frinti(xa::SReg(zTmpIdx), xa::SReg(srcIdx));
      xa_->fcvtzs(xa::XReg(dstIdx), xa::SReg(zTmpIdx));
      break;
    case 1: // Round to nearest even (00B)
      xa_->fcvtns(xa::XReg(dstIdx), xa::SReg(srcIdx));
      break;
    case 2: // Round down(01B)
      xa_->fcvtms(xa::XReg(dstIdx), xa::SReg(srcIdx));
      break;
    case 3: // Round up(10B)
      xa_->fcvtps(xa::XReg(dstIdx), xa::SReg(srcIdx));
      break;
    case 4: // Round toward zero(11B)
      xa_->fcvtzs(xa::XReg(dstIdx), xa::SReg(srcIdx));
      break;
    default:
      XT_UNIMPLEMENTED;
    }
  }

  /* Col=BI119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 64 && a64.EVEXb == 0 && true)) {
    if (a64.EVEXrc == 0) {
      xt_pop_zreg();
    }
  }
  /* Col=BQ119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.EVEXb == 0 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.EVEXb == 1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && a64.EVEXb == 0 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
