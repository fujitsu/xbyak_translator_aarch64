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
/* 2020/09/08 11:17 */

void translateMOVSX(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;

  /* Col=U119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=Y119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 16 &&
       true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=Z119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 16 &&
       true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AA119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true)) {
    srcIdx = W_TMP_0.getIdx();
  }

  /* Col=AE119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true)) {
    xa_->sxtb(W_TMP_0, xa::WReg(srcIdx));
  }
  /* Col=AF119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true)) {
    xa_->ldrsb(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AG119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 8 && true)) {
    xa_->sxtb(xa::WReg(dstIdx), xa::WReg(srcIdx));
  }
  /* Col=AH119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 8 && true)) {
    xa_->ldrsb(xa::WReg(dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 8 && true)) {
    xa_->sxtb(xa::XReg(dstIdx), xa::WReg(srcIdx));
  }
  /* Col=AJ119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 8 && true)) {
    xa_->ldrsb(xa::XReg(dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AK119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 32 &&
                a64.operands[1].opWidth == 16 && true)) {
    xa_->sxth(xa::WReg(dstIdx), xa::WReg(srcIdx));
  }
  /* Col=AL119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 32 &&
                a64.operands[1].opWidth == 16 && true)) {
    xa_->ldrsh(xa::WReg(dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AM119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 64 &&
                a64.operands[1].opWidth == 16 && true)) {
    xa_->sxth(xa::XReg(dstIdx), xa::WReg(srcIdx));
  }
  /* Col=AN119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 64 &&
                a64.operands[1].opWidth == 16 && true)) {
    xa_->ldrsh(xa::XReg(dstIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AO119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true)) {
    xa_->bfxil(xa::XReg(dstIdx), X_TMP_0, 0, 16);
  }

  /* Col=BR119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 16 &&
       true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}

