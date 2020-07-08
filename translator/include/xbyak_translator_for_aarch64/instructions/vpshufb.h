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
/* 2020/07/03 15:52 */
#define CG64 CodeGeneratorAArch64
void translateVPSHUFB(xed_decoded_inst_t *p) {
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
  xt_reg_idx_t zTmp2Idx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmp3Idx = XT_REG_INVALID;

  /* Col=AD119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AE119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=AF119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    zTmp3Idx = xt_push_zreg(&a64);
  }
  /* Col=AG119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AH119*/
  if (false || (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
                a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
                a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
                a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
                a64_opt.operands[0].opWidth == 256 &&
                isAvailAll1Preg0_7() == true && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AI119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AJ119*/
  if (false || (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
                a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
                a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
                a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
                a64_opt.operands[0].opWidth == 256 &&
                isAvailAll1Preg0_7() == true && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AK119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AP119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    CG64::mov(xa::ZRegB(zTmpIdx), 15);
  }
  /* Col=AQ119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    CG64::and_(xa::ZRegB(zTmpIdx), P_ALL_ONE_0_7, xa::ZRegB(src2Idx));
  }
  /* Col=AT119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    for (int i = 0; i < 16; i++) {
      CG64::cmpeq(P_TMP_0.b, P_ALL_ONE_0_7, xa::ZRegB(zTmpIdx), i);
      CG64::dup(xa::ZRegB(zTmp2Idx), xa::ZRegB(srcIdx)[i]);
      CG64::mov(xa::ZRegB(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
    }
  }
  /* Col=AU119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    for (int i = 16; i < 32; i++) {
      CG64::cmpeq(P_TMP_0.b, P_ALL_ONE_0_7, xa::ZRegB(zTmpIdx), i - 16);
      CG64::and_(P_TMP_0.b, P_ALL_ONE_0_7, P_TMP_0.b, P_MSB_384.b);
      CG64::dup(xa::ZRegB(zTmp2Idx), xa::ZRegB(srcIdx)[i]);
      CG64::mov(xa::ZRegB(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
    }
  }
  /* Col=AX119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    CG64::cmplt(P_TMP_0.b, P_ALL_ONE_0_7, xa::ZRegB(src2Idx), 0);
  }
  /* Col=AY119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    CG64::mov(xa::ZRegD(dstIdx), xa::ZRegD(zTmp3Idx));
  }
  /* Col=AZ119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    CG64::orr(P_TMP_1.b, P_ALL_ONE, P_TMP_0.b, P_MSB_256.b);
  }
  /* Col=BB119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    CG64::mov(xa::ZRegB(dstIdx), P_TMP_1 / xa::T_m, 0);
  }
  /* Col=BE119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xt_pop_zreg();
  }
  /* Col=BF119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xt_pop_zreg();
  }
  /* Col=BG119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xt_pop_zreg();
  }
  /* Col=BY119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64_opt.operands[0].opWidth == 256 && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    return;
  }
  /* Col=T119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=U119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=V119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=W119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=X119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    zTmp3Idx = xt_push_zreg(&a64);
  }
  /* Col=Y119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=Z119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[1].regClass == XED_REG_CLASS_YMM &&
                a64.operands[0].opWidth == 256 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AA119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AB119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[1].regClass == XED_REG_CLASS_YMM &&
                a64.operands[0].opWidth == 256 && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AC119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AF119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    CG64::mov(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=AH119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    CG64::mov(xa::ZRegB(zTmpIdx), 15);
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    CG64::and_(xa::ZRegB(zTmpIdx), xa::PReg(pTmpIdx), xa::ZRegB(src2Idx));
  }
  /* Col=AL119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    for (int i = 0; i < 16; i++) {
      CG64::cmpeq(P_TMP_0.b, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), i);
      CG64::dup(xa::ZRegB(zTmp2Idx), xa::ZRegB(srcIdx)[i]);
      CG64::mov(xa::ZRegB(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
    }
  }
  /* Col=AM119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    for (int i = 16; i < 32; i++) {
      CG64::cmpeq(P_TMP_0.b, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), i - 16);
      CG64::and_(P_TMP_0.b, xa::PReg(pTmpIdx), P_TMP_0.b, P_MSB_384.b);
      CG64::dup(xa::ZRegB(zTmp2Idx), xa::ZRegB(srcIdx)[i]);
      CG64::mov(xa::ZRegB(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
    }
  }
  /* Col=AP119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    CG64::cmplt(P_TMP_0.b, xa::PReg(pTmpIdx), xa::ZRegB(src2Idx), 0);
  }
  /* Col=AQ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    CG64::mov(xa::ZRegD(dstIdx), xa::ZRegD(zTmp3Idx));
  }
  /* Col=AR119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    CG64::orr(xa::PRegB(pTmpIdx), P_ALL_ONE, P_TMP_0.b, P_MSB_256.b);
  }
  /* Col=AT119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    CG64::mov(xa::ZRegB(dstIdx), xa::PReg(pTmpIdx) / xa::T_m, 0);
  }
  /* Col=AW119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_zreg();
  }
  /* Col=AX119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_zreg();
  }
  /* Col=AY119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_zreg();
  }
  /* Col=AZ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_preg();
  }
  /* Col=BQ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
