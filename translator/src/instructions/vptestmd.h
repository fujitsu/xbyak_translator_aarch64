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
/* 2020/07/02 15:39 */

void translateVPTESTMD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t src2Idx = XT_REG_INVALID;
  xt_reg_idx_t maskIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmp2Idx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;

  /* Col=AE119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AF119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=AI119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->ldr(xa::ZReg(zTmp2Idx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AL119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AM119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AN119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AQ119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    src2Idx = zTmp2Idx;
  }
  /* Col=AV119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->and_(xa::ZRegD(zTmpIdx), xa::ZRegD(srcIdx), xa::ZRegD(src2Idx));
  }
  /* Col=AW119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->cmpne(xa::PRegS(dstIdx), P_ALL_ONE_0_7 / xa::T_z, xa::ZRegS(zTmpIdx),
               0);
  }
  /* Col=AY119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->not_(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b);
  }
  /* Col=AZ119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->not_(P_TMP_0.b, P_ALL_ONE, P_MSB_384.b);
  }
  /* Col=BB119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->and_(xa::PRegB(dstIdx), P_ALL_ONE, xa::PRegB(dstIdx), P_TMP_0.b);
  }
  /* Col=BP119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BQ119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BY119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && isAvailAll1Preg0_7() == true &&
       true)) {
    return;
  }
  /* Col=U119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=W119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=X119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=Y119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AA119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    xa_->ldr(xa::ZReg(zTmp2Idx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AD119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AE119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AF119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    src2Idx = zTmp2Idx;
  }
  /* Col=AJ119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true)) {
    xa_->movs(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=AK119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    xa_->and_(xa::PRegB(pTmpIdx), P_ALL_ONE, xa::PRegB(maskIdx), P_ALL_ONE.b);
  }
  /* Col=AN119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    xa_->and_(xa::ZRegD(zTmpIdx), xa::ZRegD(srcIdx), xa::ZRegD(src2Idx));
  }
  /* Col=AO119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    xa_->cmpne(xa::PRegS(dstIdx), xa::PReg(pTmpIdx) / xa::T_z,
               xa::ZRegS(zTmpIdx), 0);
  }
  /* Col=AQ119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true)) {
    xa_->not_(xa::PRegB(pTmpIdx), P_ALL_ONE, P_MSB_256.b);
  }
  /* Col=AR119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true)) {
    xa_->not_(xa::PRegB(pTmpIdx), P_ALL_ONE, P_MSB_384.b);
  }
  /* Col=AT119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true)) {
    xa_->and_(xa::PRegB(dstIdx), P_ALL_ONE, xa::PRegB(dstIdx),
              xa::PRegB(pTmpIdx));
  }
  /* Col=BH119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    xt_pop_zreg();
  }
  /* Col=BI119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    xt_pop_zreg();
  }
  /* Col=BJ119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    xt_pop_preg();
  }
  /* Col=BQ119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
