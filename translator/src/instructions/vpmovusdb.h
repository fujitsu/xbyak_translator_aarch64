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
/* 2020/07/03 14:15 */

void translateVPMOVUSDB(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t maskIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;

  /* Col=AD119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AF119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AG119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AL119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZRegS(zTmpIdx), P_ALL_ONE / xa::T_m, 0);
  }
  /* Col=AM119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->add(xa::ZRegS(zTmpIdx), 255);
  }
  /* Col=AN119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZRegD(dstIdx), xa::ZRegD(srcIdx));
  }
  /* Col=AO119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->cmphi(P_TMP_0.s, P_ALL_ONE_0_7, xa::ZRegS(srcIdx), xa::ZRegS(zTmpIdx));
  }
  /* Col=AR119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_TMP_0 / xa::T_m, xa::ZRegS(zTmpIdx));
  }
  /* Col=AS119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZRegD(zTmpIdx), xa::ZRegD(srcIdx));
  }
  /* Col=AV119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->uzp1(xa::ZRegB(dstIdx), xa::ZRegB(dstIdx), xa::ZRegB(dstIdx));
  }
  /* Col=AW119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->uzp1(xa::ZRegB(dstIdx), xa::ZRegB(dstIdx), xa::ZRegB(dstIdx));
  }
  /* Col=BA119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->ptrue(P_TMP_0.b, xa::VL4);
  }
  /* Col=BB119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->not_(P_TMP_0.b, P_ALL_ONE, P_TMP_0.b);
  }
  /* Col=BC119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZReg(dstIdx).s, P_MSB_384 / xa::T_m, 0);
  }
  /* Col=BD119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZReg(dstIdx).s, P_TMP_0 / xa::T_m, 0);
  }
  /* Col=BE119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->umin(xa::ZRegS(zTmpIdx), 255);
  }
  /* Col=BJ119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->st1b(xa::ZRegS(zTmpIdx), P_ALL_ONE_0_7, xa::ptr(X_TMP_ADDR));
  }
  /* Col=BQ119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xt_pop_zreg();
  }
  /* Col=BY119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    return;
  }
  /* Col=T119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=U119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=V119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=X119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=Y119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AA119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_MERG && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AC119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=AD119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegS(zTmpIdx), P_ALL_ONE / xa::T_m, 0);
  }
  /* Col=AE119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    xa_->add(xa::ZRegS(zTmpIdx), 255);
  }
  /* Col=AF119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegD(dstIdx), xa::ZRegD(srcIdx));
  }
  /* Col=AG119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    xa_->cmphi(P_TMP_0.s, xa::PRegS(pTmpIdx), xa::ZRegS(srcIdx),
               xa::ZRegS(zTmpIdx));
  }
  /* Col=AJ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_TMP_0 / xa::T_m, xa::ZRegS(zTmpIdx));
  }
  /* Col=AK119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->mov(xa::ZRegD(zTmpIdx), xa::ZRegD(srcIdx));
  }
  /* Col=AN119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    xa_->uzp1(xa::ZRegB(dstIdx), xa::ZRegB(dstIdx), xa::ZRegB(dstIdx));
  }
  /* Col=AO119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    xa_->uzp1(xa::ZRegB(dstIdx), xa::ZRegB(dstIdx), xa::ZRegB(dstIdx));
  }
  /* Col=AS119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    xa_->ptrue(xa::PRegB(pTmpIdx), xa::VL4);
  }
  /* Col=AT119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    xa_->not_(xa::PRegB(pTmpIdx), P_ALL_ONE, xa::PRegB(pTmpIdx));
  }
  /* Col=AU119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZReg(dstIdx).s, P_MSB_384 / xa::T_m, 0);
  }
  /* Col=AV119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZReg(dstIdx).s, xa::PReg(pTmpIdx) / xa::T_m, 0);
  }
  /* Col=AW119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->umin(xa::ZRegS(zTmpIdx), 255);
  }
  /* Col=BB119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    xa_->st1b(xa::ZRegS(zTmpIdx), xa::PReg(pTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=BC119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_MERG && true)) {
    xa_->st1b(xa::ZRegS(zTmpIdx), xa::PReg(maskIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=BI119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BJ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_preg();
  }
  /* Col=BQ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
