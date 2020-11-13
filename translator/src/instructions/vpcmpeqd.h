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
/* 2020/06/29 17:29 */

void Xbyak::CodeGenerator::translateVPCMPEQD(xed_decoded_inst_t *p) {
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

  /* Col=AB119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 1 &&
       isAvailAll1Preg0_7() == true && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=AC119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 1 &&
       isAvailAll1Preg0_7() == true && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AE119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 1 &&
       isAvailAll1Preg0_7() == true && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AG119*/
  if (false || (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
                a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
                a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
                a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 0 &&
                isAvailAll1Preg0_7() == true && true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AH119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 1 &&
       isAvailAll1Preg0_7() == true && true)) {
    maskIdx = a64.operands[1].regIdx;
  }

  /* Col=AL119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 1 &&
       isAvailAll1Preg0_7() == true && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AO119*/
  if (false || (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
                a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
                a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
                a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 0 &&
                isAvailAll1Preg0_7() == true && true)) {
    xa_->ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AP119*/
  if (false || (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
                a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
                a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
                a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 1 &&
                isAvailAll1Preg0_7() == true && true)) {
    xa_->ld1rw(xa::ZRegS(zTmpIdx), xa::PReg(maskIdx) / xa::T_z,
               xa::ptr(X_TMP_ADDR));
  }

  /* Col=BB119*/
  if (false || (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
                a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
                a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
                a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 0 &&
                isAvailAll1Preg0_7() == true && true)) {
    xa_->cmpeq(xa::PRegS(dstIdx), P_ALL_ONE_0_7 / xa::T_z, xa::ZRegS(srcIdx),
               xa::ZRegS(src2Idx));
  }
  /* Col=BC119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 1 &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->cmpeq(xa::PRegS(dstIdx), P_ALL_ONE_0_7 / xa::T_z, xa::ZRegS(srcIdx),
               xa::ZRegS(zTmpIdx));
  }

  /* Col=BH119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 1 &&
       isAvailAll1Preg0_7() == true && true)) {
    xt_pop_zreg();
  }

  /* Col=BY119*/
  if (false || (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
                a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
                a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
                a64_opt.predType == A64_PRED_NO && a64_opt.EVEXb == 0 &&
                isAvailAll1Preg0_7() == true && true)) {
    return;
  }

  /* Col=T119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=U119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=V119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=W119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=X119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=Y119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=Z119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AC119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    vTmpIdx = xt_push_vreg(&a64);
  }

  /* Col=AD119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AE119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    xa_->ld1(xa::VReg4S(vTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AG119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true)) {
    xa_->ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AH119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    xa_->ld1rw(xa::ZRegS(zTmpIdx), xa::PReg(maskIdx) / xa::T_z,
               xa::ptr(X_TMP_ADDR));
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=AJ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true)) {
    xa_->mov(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=AK119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    xa_->mov(xa::PRegB(pTmpIdx), xa::PRegB(maskIdx));
  }
  /* Col=AL119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true)) {
    xa_->not_(xa::PRegB(pTmpIdx), P_ALL_ONE.b, P_MSB_256.b);
  }
  /* Col=AM119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true)) {
    xa_->not_(xa::PRegB(pTmpIdx), P_ALL_ONE.b, P_MSB_384.b);
  }

  /* Col=AN119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    xa_->orn(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_256.b,
             xa::PRegB(maskIdx));
  }
  /* Col=AO119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    xa_->orn(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_384.b,
             xa::PRegB(maskIdx));
  }
  /* Col=AP119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    xa_->cmeq(xa::VReg4S(dstIdx), xa::VReg4S(srcIdx), xa::VReg4S(src2Idx));
  }
  /* Col=AQ119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    xa_->cmeq(xa::VReg4S(dstIdx), xa::VReg4S(srcIdx), xa::VReg4S(vTmpIdx));
  }
  /* Col=AR119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[1].regClass == XED_REG_CLASS_YMM &&
                a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    xa_->cmpeq(xa::PRegS(pTmpIdx), xa::PReg(pTmpIdx) / xa::T_z,
               xa::ZRegS(srcIdx), xa::ZRegS(src2Idx));
  }
  /* Col=AS119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].regClass == XED_REG_CLASS_YMM &&
                a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    xa_->cmpeq(xa::PRegS(pTmpIdx), xa::PReg(pTmpIdx) / xa::T_z,
               xa::ZRegS(srcIdx), xa::ZRegS(zTmpIdx));
  }
  /* Col=AT119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true)) {
    xa_->cmpeq(xa::PRegS(dstIdx), xa::PReg(pTmpIdx) / xa::T_z,
               xa::ZRegS(srcIdx), xa::ZRegS(src2Idx));
  }
  /* Col=AU119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    xa_->cmpeq(xa::PRegS(dstIdx), xa::PReg(pTmpIdx) / xa::T_z,
               xa::ZRegS(srcIdx), xa::ZRegS(zTmpIdx));
  }
  /* Col=AV119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    xa_->mov(xa::ZRegD(dstIdx), 0x0); // 全ビット0埋め
  }
  /* Col=AW119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    xa_->orn(W_TMP_0, W_TMP_0, W_TMP_0); // 全ビット1埋め
  }

  /* Col=AX119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    xa_->mov(xa::ZRegS(dstIdx), xa::PReg(pTmpIdx) / xa::T_m, W_TMP_0);
  }
  /* Col=AY119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    xt_pop_vreg();
  }
  /* Col=AZ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    xt_pop_zreg();
  }
  /* Col=BA119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    xt_pop_preg();
  }

  /* Col=BQ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
