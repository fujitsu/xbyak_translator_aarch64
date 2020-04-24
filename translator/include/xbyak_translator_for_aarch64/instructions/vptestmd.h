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
/* 2020/04/24 10:47 */
#define CG64 CodeGeneratorAArch64
void translateVPTESTMD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;
  xt_reg_idx_t src2Idx;
  xt_reg_idx_t maskIdx;
  xt_reg_idx_t zTmpIdx;
  xt_reg_idx_t zTmp2Idx;
  xt_reg_idx_t pTmpIdx;

  /* Col=Y119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
  /* Col=AA119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
  /* Col=AB119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_MEM0 &&
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
  /* Col=AC119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
  /* Col=AE119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_MEM0 &&
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
    CG64::ldr(xa::ZReg(zTmp2Idx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AH119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
  /* Col=AI119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
  /* Col=AJ119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
  /* Col=AM119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_MEM0 &&
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
  /* Col=AN119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
    CG64::movs(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=AO119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
    CG64::and_(xa::PRegB(pTmpIdx), P_ALL_ONE, xa::PRegB(maskIdx), P_ALL_ONE.b);
  }
  /* Col=AR119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
    CG64::and_(xa::ZRegD(zTmpIdx), xa::ZRegD(srcIdx), xa::ZRegD(src2Idx));
  }
  /* Col=AS119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
    CG64::cmpne(xa::PRegS(dstIdx), xa::PReg(pTmpIdx) / xa::T_z,
                xa::ZRegS(zTmpIdx), 0);
  }
  /* Col=AU119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
    CG64::not_(xa::PRegB(pTmpIdx), P_ALL_ONE, P_MSB_256.b);
  }
  /* Col=AV119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
    CG64::not_(xa::PRegB(pTmpIdx), P_ALL_ONE, P_MSB_384.b);
  }
  /* Col=AX119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
    CG64::and_(xa::PRegB(dstIdx), P_ALL_ONE, xa::PRegB(dstIdx),
               xa::PRegB(pTmpIdx));
  }
  /* Col=BL119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_MEM0 &&
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
  /* Col=BM119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
  /* Col=BN119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
  /* Col=BO119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
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
#undef CG64
