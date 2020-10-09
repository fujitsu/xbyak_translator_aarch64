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
void translateKMOVD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

  /* 2020/03/10 09:06 */

  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t maskIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmp2Idx = XT_REG_INVALID;
  /* Col=T103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_GPR &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=V103*/
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
  /* Col=W103*/
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

  /* Col=Y103*/
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
  /* Col=Z103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AA103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_INVALID && true)) {
    srcIdx = W_TMP_0.getIdx();
  }
  /* Col=AB103*/
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
  /* Col=AC103*/
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

  /* Col=AE103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_INVALID && true)) {
    xa_->ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }

  /* Col=AG103*/
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
  /* Col=AH103*/
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
  /* Col=AI103*/
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

  /* Col=AK103*/
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

  /* Col=AM103*/
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

  /* Col=AP103*/
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

  /* Col=AS103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    xa_->mov(xa::PRegB(dstIdx), xa::PRegB(srcIdx));
  }

  /* Col=AV103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    xa_->ptrue(P_TMP_0.b, xa::VL32);
  }
  /* Col=AW103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    xa_->movs(xa::PRegB(dstIdx), P_TMP_0, xa::PRegB(dstIdx));
  }

  /* Col=AY103*/
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
  /* Col=AZ103*/
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
}
