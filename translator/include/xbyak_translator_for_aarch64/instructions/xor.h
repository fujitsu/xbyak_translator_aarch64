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
/* 2020/04/29 17:18 */

void translateXOR(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;

  /* Col=Y119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 64 &&
       true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=AA119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 64 &&
       true)) {
    dstIdx = X_TMP_1.getIdx();
  }
  /* Col=AB119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 64 &&
       true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AC119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 64 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 64 &&
       true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AD119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 16 &&
       true)) {
    srcIdx = X_TMP_0.getIdx();
  }
  /* Col=AG119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[0].opWidth == 32 &&
                a64.operands[1].opWidth == 32 && true)) {
    xa_->ldr(xa::WReg(dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AH119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[0].opWidth == 64 &&
                a64.operands[1].opWidth == 64 && true)) {
    xa_->ldr(xa::XReg(dstIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AO119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true)) {
    xa_->mov(W_TMP_0, a64.operands[1].uimm & 0xff);
  }
  /* Col=AP119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_IMM0 &&
                a64.operands[0].opWidth == 16 &&
                a64.operands[1].opWidth == 16 && true)) {
    xa_->mov(W_TMP_0, a64.operands[1].uimm & 0xffff);
  }
  /* Col=AQ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 32 &&
       true)) {
    xa_->eor(xa::WReg(dstIdx), xa::WReg(dstIdx), xa::WReg(srcIdx));
  }
  /* Col=AR119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 64 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 64 &&
       true)) {
    xa_->eor(xa::XReg(dstIdx), xa::XReg(dstIdx), xa::XReg(srcIdx));
  }

  /* Col=BI119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[0].opWidth == 32 &&
                a64.operands[1].opWidth == 32 && true)) {
    xa_->str(xa::WReg(dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=BJ119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[0].opWidth == 64 &&
                a64.operands[1].opWidth == 64 && true)) {
    xa_->str(xa::XReg(dstIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=BP119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 64 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 64 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 8 && a64.operands[1].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && a64.operands[1].opWidth == 16 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && a64.operands[1].opWidth == 32 &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && a64.operands[1].opWidth == 64 &&
       true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
