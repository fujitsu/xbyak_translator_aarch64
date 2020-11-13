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
/* 2020/09/09 08:09 */

void translateVPSUBD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t src2Idx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;

  /* Col=T119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=W119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=Z119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AA119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AB119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    src2Idx = a64.operands[2].regIdx;
  }

  /* Col=AD119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AE119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AG119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    xa_->ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AH119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    src2Idx = zTmpIdx;
  }

  /* Col=AN119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true)) {
    xa_->sub(xa::VReg(dstIdx).s4, xa::VReg(srcIdx).s4, xa::VReg(src2Idx).s4);
  }
  /* Col=AO119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    xa_->sub(xa::ZRegS(dstIdx), xa::ZRegS(srcIdx), xa::ZRegS(src2Idx));
  }

  /* Col=BD119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    xa_->mov(xa::ZReg(dstIdx).b, P_MSB_256 / xa::T_m, 0);
  }

  /* Col=BI119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true)) {
    xt_pop_zreg();
  }
  /* Col=BQ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_MERG && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_NO && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_MERG && a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.predType == A64_PRED_ZERO && a64.EVEXb == 1 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
