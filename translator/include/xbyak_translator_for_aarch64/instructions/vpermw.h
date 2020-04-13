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
/* 2020/04/13 22:19 */
#define CG64 CodeGeneratorAArch64
void translateVPERMW(xed_decoded_inst_t *p) {
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
  xt_reg_idx_t zTmp3Idx;
  xt_reg_idx_t zTmp4Idx;
  xt_reg_idx_t pTmpIdx;

  /* Col=U103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=V103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=W103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=X103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmp3Idx = xt_push_zreg(&a64);
  }
  /* Col=Y103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmp4Idx = xt_push_zreg(&a64);
  }
  /* Col=Z103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AB103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    srcIdx = a64.operands[2].regIdx;
  }

  /* Col=AD103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AE103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    src2Idx = zTmp4Idx;
  }
  /* Col=AF103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AH103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::not_(xa::PRegB(pTmpIdx), P_ALL_ONE, P_MSB_256.b);
  }
  /* Col=AI103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::ldr(xa::QReg(zTmp4Idx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AJ103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::ld1h(xa::ZRegH(zTmp4Idx), xa::PReg(pTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AK103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::ldr(xa::ZReg(zTmp4Idx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AL103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::mov(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=AM103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::mov(xa::ZRegH(zTmpIdx), 7);
  }

  /* Col=AN103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::mov(xa::ZRegH(zTmpIdx), 15);
  }
  /* Col=AO103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::mov(xa::ZRegH(zTmpIdx), 31);
  }
  /* Col=AP103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::and_(xa::ZRegB(zTmpIdx), xa::PReg(pTmpIdx), xa::ZRegB(srcIdx));
  }
  /* Col=AR103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    for (int i = 0; i < 8; i++) {
      CG64::cmpeq(P_TMP_0.h, xa::PReg(pTmpIdx), xa::ZRegH(zTmpIdx), i);
      CG64::dup(xa::ZRegH(zTmp2Idx), xa::ZRegH(src2Idx)[i]);
      CG64::mov(xa::ZRegH(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegH(zTmp2Idx));
    }
  }
  /* Col=AS103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    for (int i = 0; i < 16; i++) {
      CG64::cmpeq(P_TMP_0.h, xa::PReg(pTmpIdx), xa::ZRegH(zTmpIdx), i);
      CG64::dup(xa::ZRegH(zTmp2Idx), xa::ZRegH(src2Idx)[i]);
      CG64::mov(xa::ZRegH(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegH(zTmp2Idx));
    }
  }
  /* Col=AT103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::sub(xa::ZRegH(zTmpIdx), 16);
  }
  /* Col=AU103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    for (int i = 0; i < 16; i++) {
      CG64::cmpeq(P_TMP_0.h, xa::PReg(pTmpIdx), xa::ZRegH(zTmpIdx), i);
      CG64::dup(xa::ZRegH(zTmp2Idx), xa::ZRegH(src2Idx)[16 + i]);
      CG64::mov(xa::ZRegH(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegH(zTmp2Idx));
    }
  }

  /* Col=AX103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    CG64::mov(xa::ZRegD(dstIdx), xa::ZRegD(zTmp3Idx));
  }
  /* Col=AY103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true)) {
    CG64::mov(xa::ZRegH(dstIdx), 0);
  }
  /* Col=AZ103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::mov(xa::ZRegH(dstIdx), xa::PReg(maskIdx) / xa::T_m,
              xa::ZRegH(zTmp3Idx));
  }
  /* Col=BC103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::mov(xa::ZRegH(dstIdx), P_MSB_384 / xa::T_m, 0);
  }
  /* Col=BD103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::mov(xa::ZRegH(dstIdx), P_MSB_256 / xa::T_m, 0);
  }
  /* Col=BG103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_zreg();
  }

  /* Col=BH103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BI103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BJ103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BK103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_preg();
  }
  /* Col=BQ103*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
