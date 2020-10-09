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
/* 2020/10/04 22:03 */

void translateVFMSUB213PS(xed_decoded_inst_t *p) {
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

  /* Col=AB119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=AE119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AF119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AK119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->zip1(P_TMP_0.b, xa::PReg(maskIdx).b, xa::PReg(maskIdx).b);
  }

  /* Col=AL119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->zip1(P_TMP_0.h, P_TMP_0.h, P_TMP_0.h);
  }
  /* Col=AM119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->not_(P_TMP_0.b, P_ALL_ONE.b, P_TMP_0.b);
  }
  /* Col=AN119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->orn(P_TMP_0.b, P_ALL_ONE / xa::T_z, P_MSB_256.b, P_TMP_0.b);
  }
  /* Col=AO119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->orn(P_TMP_0.b, P_ALL_ONE / xa::T_z, P_MSB_384.b, P_TMP_0.b);
  }
  /* Col=AQ119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AR119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AS119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AT119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AU119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    src2Idx = a64.operands[3].regIdx;
  }

  /* Col=AW119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    ld1(xa::VReg(zTmpIdx).s4, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AY119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=BF119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->fnmsb(xa::ZRegS(dstIdx), P_ALL_ONE_0_7 / xa::T_m, xa::ZRegS(srcIdx),
                xa::ZRegS(src2Idx));
  }
  /* Col=BG119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->fnmsb(xa::ZRegS(dstIdx), P_ALL_ONE_0_7 / xa::T_m, xa::ZRegS(srcIdx),
                xa::ZRegS(zTmpIdx));
  }
  /* Col=BJ119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_MSB_256 / xa::T_m, 0);
  }
  /* Col=BK119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_MSB_384 / xa::T_m, 0);
  }
  /* Col=BL119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_TMP_0 / xa::T_m, 0);
  }

  /* Col=BV119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && a64_opt.EVEXb == 0 &&
       isAvailAll1Preg0_7() == true && true)) {
    xt_pop_zreg();
  }
  /* Col=BY119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[3].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true)) {
    return;
  }

  /* Col=T119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=U119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=W119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=X119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=Z119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    xa_->mov(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=AA119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xa_->zip1(xa::PReg(pTmpIdx).b, xa::PReg(maskIdx).b, xa::PReg(maskIdx).b);
  }
  /* Col=AB119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xa_->zip1(xa::PReg(pTmpIdx).h, xa::PReg(pTmpIdx).h, xa::PReg(pTmpIdx).h);
  }
  /* Col=AC119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    xa_->zip1(P_TMP_0.b, xa::PReg(maskIdx).b, xa::PReg(maskIdx).b);
  }

  /* Col=AD119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    xa_->zip1(P_TMP_0.h, P_TMP_0.h, P_TMP_0.h);
  }
  /* Col=AE119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    xa_->not_(P_TMP_0.b, P_ALL_ONE.b, P_TMP_0.b);
  }
  /* Col=AF119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    xa_->orn(P_TMP_0.b, P_ALL_ONE / xa::T_z, P_MSB_256.b, P_TMP_0.b);
  }
  /* Col=AG119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    xa_->orn(P_TMP_0.b, P_ALL_ONE / xa::T_z, P_MSB_384.b, P_TMP_0.b);
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AJ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AK119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AL119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AM119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    src2Idx = a64.operands[3].regIdx;
  }

  /* Col=AO119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    ld1(xa::VReg(zTmpIdx).s4, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AQ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AX119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xa_->fnmsb(xa::ZRegS(dstIdx), xa::PReg(pTmpIdx) / xa::T_m,
                xa::ZRegS(srcIdx), xa::ZRegS(src2Idx));
  }
  /* Col=AY119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xa_->fnmsb(xa::ZRegS(dstIdx), xa::PReg(pTmpIdx) / xa::T_m,
                xa::ZRegS(srcIdx), xa::ZRegS(zTmpIdx));
  }
  /* Col=BB119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_MSB_256 / xa::T_m, 0);
  }
  /* Col=BC119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_MSB_384 / xa::T_m, 0);
  }
  /* Col=BD119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_TMP_0 / xa::T_m, 0);
  }

  /* Col=BI119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xt_pop_zreg();
  }
  /* Col=BJ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xt_pop_preg();
  }
  /* Col=BQ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}

