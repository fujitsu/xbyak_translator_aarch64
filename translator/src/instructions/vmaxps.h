/*******************************************************************************
 * Copyright 2020 FUJITSU LIMITED
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
/* 2020/08/26 14:13 */

void Xbyak::CodeGenerator::translateVMAXPS(xed_decoded_inst_t *p) {
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
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t vTmpIdx = XT_REG_INVALID;

  /* Col=AC119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AD119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AE119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AF119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AG119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AH119*/
  if (false || (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
                a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64_opt.operands[0].opWidth == 512 &&
                a64_opt.predType == A64_PRED_MERG && a64_opt.EVEXb == 0 &&
                isAvailAll1Preg0_7() == true && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AK119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }

  /* Col=AN119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AU119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZRegD(zTmpIdx), xa::ZRegD(src2Idx));
  }

  /* Col=AY119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->fmaxnm(xa::ZRegS(zTmpIdx), P_ALL_ONE_0_7, xa::ZRegS(srcIdx));
  }
  /* Col=BC119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->fmax(xa::ZRegS(zTmpIdx), P_ALL_ONE_0_7, xa::ZRegS(srcIdx));
  }
  /* Col=BE119*/
  if (false || (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
                a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64_opt.operands[0].opWidth == 512 &&
                a64_opt.predType == A64_PRED_MERG && a64_opt.EVEXb == 0 &&
                isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZRegS(dstIdx), xa::PReg(maskIdx) / xa::T_m,
             xa::ZRegS(zTmpIdx));
  }

  /* Col=BF119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZRegD(dstIdx), xa::ZRegD(zTmpIdx));
  }
  /* Col=BH119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_MSB_256 / xa::T_m, 0);
  }
  /* Col=BL119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    xt_pop_zreg();
  }

  /* Col=BY119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    return;
  }
  /* Col=T119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=U119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=V119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=W119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=X119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[1].regClass == XED_REG_CLASS_YMM &&
                a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true)) {
    src2Idx = a64.operands[2].regIdx;
  }

  /* Col=Y119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=Z119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AB119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true)) {
    vTmpIdx = xt_push_vreg(&a64);
  }
  /* Col=AC119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }

  /* Col=AD119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true)) {
    xa_->ld1(xa::VReg4S(vTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AE119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 1 && true)) {
    xa_->ld1r(xa::VReg4S(vTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AF119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xa_->ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AG119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xa_->ld1rw(xa::ZRegS(zTmpIdx), P_ALL_ONE / xa::T_z, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AH119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true)) {
    xa_->not_(xa::PRegB(pTmpIdx), P_ALL_ONE.b, xa::PRegB(maskIdx));
  }
  /* Col=AJ119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true)) {
    xa_->orn(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_256.b,
             xa::PRegB(maskIdx));
  }
  /* Col=AK119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true)) {
    xa_->orn(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_384.b,
             xa::PRegB(maskIdx));
  }
  /* Col=AL119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xa_->mov(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=AM119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xa_->mov(xa::ZRegD(zTmpIdx), xa::ZRegD(src2Idx));
  }

  /* Col=AO119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true)) {
    xa_->fmaxnm(xa::VReg4S(dstIdx), xa::VReg4S(srcIdx), xa::VReg4S(src2Idx));
  }
  /* Col=AP119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true)) {
    xa_->fmaxnm(xa::VReg4S(dstIdx), xa::VReg4S(srcIdx), xa::VReg4S(vTmpIdx));
  }
  /* Col=AQ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xa_->fmaxnm(xa::ZRegS(zTmpIdx), xa::PReg(pTmpIdx), xa::ZRegS(srcIdx));
  }
  /* Col=AS119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true)) {
    xa_->fmax(xa::VReg4S(dstIdx), xa::VReg4S(dstIdx), xa::VReg4S(src2Idx));
  }
  /* Col=AT119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true)) {
    xa_->fmax(xa::VReg4S(dstIdx), xa::VReg4S(dstIdx), xa::VReg4S(vTmpIdx));
  }
  /* Col=AU119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xa_->fmax(xa::ZRegS(zTmpIdx), xa::PReg(pTmpIdx), xa::ZRegS(srcIdx));
  }
  /* Col=AW119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xa_->mov(xa::ZRegS(dstIdx), xa::PReg(maskIdx) / xa::T_m,
             xa::ZRegS(zTmpIdx));
  }

  /* Col=AX119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true)) {
    xa_->mov(xa::ZRegD(dstIdx), xa::ZRegD(zTmpIdx));
  }
  /* Col=AY119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true)) {
    xa_->mov(xa::ZRegS(dstIdx), xa::PReg(pTmpIdx) / xa::T_m, 0);
  }
  /* Col=AZ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_MSB_256 / xa::T_m, 0);
  }
  /* Col=BA119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_MSB_384 / xa::T_m, 0);
  }
  /* Col=BC119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xt_pop_preg();
  }
  /* Col=BD119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xt_pop_zreg();
  }
  /* Col=BE119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true)) {
    xt_pop_vreg();
  }

  /* Col=BQ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
