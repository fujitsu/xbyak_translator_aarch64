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
/* 2020/09/09 15:41 */

void translateCMOVZ(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;

  /* Col=Z119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AA119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AB119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true)) {
    srcIdx = X_TMP_0.getIdx();
  }
  /* Col=AC119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 16 && true)) {
    xa_->ldrh(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }

  /* Col=AD119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && true)) {
    xa_->mov(X_TMP_1, xa::XReg(dstIdx));
  }
  /* Col=AF119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 32 && true)) {
    xa_->ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AG119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 64 && true)) {
    xa_->ldr(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AK119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && true)) {
    xa_->csel(xa::WReg(dstIdx), xa::WReg(srcIdx), xa::WReg(dstIdx), xa::EQ);
  }
  /* Col=AL119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true)) {
    xa_->csel(xa::XReg(dstIdx), xa::XReg(srcIdx), xa::XReg(dstIdx), xa::EQ);
  }

  /* Col=AP119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && true)) {
    xa_->bfxil(X_TMP_1, xa::XReg(srcIdx), 0, 16);
  }
  /* Col=AU119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && true)) {
    xa_->csel(xa::XReg(dstIdx), X_TMP_1, xa::XReg(dstIdx), xa::EQ);
  }

  /* Col=BQ119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}

