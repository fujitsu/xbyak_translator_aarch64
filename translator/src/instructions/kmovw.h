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
/* 2020/04/21 13:19 */

void translateKMOVW(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t maskIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmp2Idx = XT_REG_INVALID;

  /* Col=T119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_GPR &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=V119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=W119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=Y119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=Z119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AA119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_INVALID && true)) {
    srcIdx = W_TMP_0.getIdx();
  }
  /* Col=AB119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    maskIdx = a64.operands[0].regIdx;
  }
  /* Col=AC119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    xa_->mov(xa::PRegB(maskIdx), P_ALL_ONE.b);
  }
  /* Col=AE119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_INVALID && true)) {
    xa_->ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AG119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    xa_->index(xa::ZRegS(zTmpIdx), 0, 1);
  }
  /* Col=AH119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    xa_->mov(xa::ZRegS(zTmp2Idx), 1);
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    xa_->lsl(xa::ZRegS(zTmp2Idx), xa::PReg(maskIdx) / xa::T_m,
             xa::ZRegS(zTmpIdx));
  }
  /* Col=AK119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    xa_->dup(xa::ZRegS(zTmpIdx), xa::WReg(srcIdx));
  }
  /* Col=AM119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    xa_->and_(xa::ZRegD(zTmpIdx), xa::ZRegD(zTmpIdx), xa::ZRegD(zTmp2Idx));
  }
  /* Col=AP119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    xa_->cmpne(xa::PRegS(dstIdx), xa::PReg(maskIdx), xa::ZRegS(zTmpIdx), 0);
  }
  /* Col=AS119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    xa_->mov(xa::PRegB(dstIdx), xa::PRegB(srcIdx));
  }
  /* Col=AU119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    xa_->str(xa::PReg(srcIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AV119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    xa_->mov(X_TMP_2, 0);
  }
  /* Col=AW119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    xa_->ldr(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AX119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    for (int i = 0; i < 16; i++) {
      xa_->and_(X_TMP_1, X_TMP_0, uint64_t(1) << (4 * i));
      xa_->lsr(X_TMP_1, X_TMP_1, 3 * i);
      xa_->orr(X_TMP_2, X_TMP_2, X_TMP_1);
    }
  }
  /* Col=AY119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    xa_->str(X_TMP_2, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AZ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    xt_pop_zreg();
  }
  /* Col=BA119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    xt_pop_zreg();
  }
  /* Col=BK119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_GPR &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
