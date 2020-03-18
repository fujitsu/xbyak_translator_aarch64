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
/* 2020/03/18 11:20 */
#define CG64 CodeGeneratorAArch64
void translateVPUNPCKHBW(xed_decoded_inst_t *p) {
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

  /* Col=U119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=V119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=W119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=X119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmp3Idx = xt_push_zreg(&a64);
  }
  /* Col=Y119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmp4Idx = xt_push_zreg(&a64);
  }
  /* Col=Z119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AA119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AB119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AC119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    srcIdx = a64.operands[2].regIdx;
  }

  /* Col=AD119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AE119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AF119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && true)) {
    CG64::ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AG119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::ldr(xa::ZReg(zTmp4Idx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AH119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 128 && true)) {
    for (int i = 0; i < 8; i++) {
      CG64::mov(xa::VReg(zTmpIdx).b[2 * i], xa::VReg(srcIdx).b[i + 8]);
    }
  }
  /* Col=AI119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 128 && true)) {
    for (int i = 0; i < 8; i++) {
      CG64::mov(xa::VReg(zTmp2Idx).b[2 * i], xa::VReg(srcIdx).b[i + 8]);
    }
  }
  /* Col=AJ119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 128 && true)) {
    for (int i = 0; i < 8; i++) {
      CG64::mov(xa::VReg(zTmpIdx).b[2 * i + 1], xa::VReg(src2Idx).b[i + 8]);
    }
  }
  /* Col=AK119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 128 && true)) {
    for (int i = 0; i < 8; i++) {
      CG64::mov(xa::VReg(zTmp2Idx).b[2 * i + 1], xa::VReg(zTmpIdx).b[i + 8]);
    }
  }
  /* Col=AL119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && true)) {
    CG64::not_(P_TMP_0.b, P_ALL_ONE, P_MSB_384.b);
  }
  /* Col=AM119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 128 && true)) {
    CG64::mov(xa::ZRegB(dstIdx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmpIdx));
  }

  /* Col=AN119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 128 && true)) {
    CG64::mov(xa::ZRegB(dstIdx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
  }
  /* Col=AP119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::index(ZRegB(zTmpIdx), 0, 1);
  }
  /* Col=AQ119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::movs(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
    CG64::dup(ZRegB(zTmp2Idx), ZReg(srcIdx).b[i + 16]);
    CG64::cmphs(
		CG64::mov(xa::VReg(zTmpIdx).b[2*i], xa::VReg(srcIdx).b[i+8]);
  }
}
/* Col=AR119*/
if (false ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true)) {
  CG64::and_(xa::PRegB(pTmpIdx), P_ALL_ONE, xa::PRegB(pTmpIdx),
             xa::PRegB(maskIdx));
}
/* Col=AS119*/
if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
              a64.operands[1].opName == XED_OPERAND_REG1 &&
              a64.operands[2].opName == XED_OPERAND_REG2 &&
              a64.operands[3].opName == XED_OPERAND_INVALID &&
              a64.operands[0].opWidth == 256 && true)) {
  for (int i = 0; i < 16; i++) {
    CG64::dup(ZRegB(zTmp2Idx), ZReg(srcIdx).b[i + 16]);
    CG64::cmphs(P_TMP_0, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), i * 2);
    CG64::mov(xa::ZRegB(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
    CG64::dup(ZRegB(zTmp2Idx), ZReg(src2Idx).b[i + 16]);
    CG64::cmphs(P_TMP_0, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), i * 2 + 1);
    CG64::mov(xa::ZRegB(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
  }
}
/* Col=AT119*/
if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
              a64.operands[1].opName == XED_OPERAND_REG1 &&
              a64.operands[2].opName == XED_OPERAND_MEM0 &&
              a64.operands[3].opName == XED_OPERAND_INVALID &&
              a64.operands[0].opWidth == 256 && true)) {
  for (int i = 0; i < 16; i++) {
    CG64::dup(ZRegB(zTmp2Idx), ZReg(srcIdx).b[i + 16]);
    CG64::cmphs(P_TMP_0, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), i * 2);
    CG64::mov(xa::ZRegB(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
    CG64::dup(ZRegB(zTmp2Idx), ZReg(zTmp4Idx).b[i + 16]);
    CG64::cmphs(P_TMP_0, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), i * 2 + 1);
    CG64::mov(xa::ZRegB(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
  }
}
/* Col=AU119*/
if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
              a64.operands[1].opName == XED_OPERAND_REG1 &&
              a64.operands[2].opName == XED_OPERAND_REG2 &&
              a64.operands[3].opName == XED_OPERAND_INVALID &&
              a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_MEM0 &&
     a64.operands[3].opName == XED_OPERAND_INVALID &&
     a64.operands[0].opWidth == 256 && true)) {
  CG64::not_(P_TMP_0.b, P_ALL_ONE, P_MSB_384.b);
}
/* Col=AV119*/
if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
              a64.operands[1].opName == XED_OPERAND_REG1 &&
              a64.operands[2].opName == XED_OPERAND_REG2 &&
              a64.operands[3].opName == XED_OPERAND_INVALID &&
              a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_MEM0 &&
     a64.operands[3].opName == XED_OPERAND_INVALID &&
     a64.operands[0].opWidth == 256 && true)) {
  CG64::mov(xa::ZRegB(dstIdx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp3Idx));
}
/* Col=AW119*/
if (false ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true)) {
  for (int i = 0; i < 32; i++) {
    CG64::dup(ZRegB(zTmp2Idx), ZReg(srcIdx).b[i + 32]);
    CG64::cmphs(P_TMP_0, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), i * 2);
    CG64::mov(xa::ZRegB(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
    CG64::dup(ZRegB(zTmp2Idx), ZReg(src2Idx).b[i + 32]);
    CG64::cmphs(P_TMP_0, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), i * 2 + 1);
    CG64::mov(xa::ZRegB(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
  }
}

/* Col=AX119*/
if (false ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true)) {
  for (int i = 0; i < 32; i++) {
    CG64::dup(ZRegB(zTmp2Idx), ZReg(srcIdx).b[i + 32]);
    CG64::cmphs(P_TMP_0, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), i * 2);
    CG64::mov(xa::ZRegB(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
    CG64::dup(ZRegB(zTmp2Idx), ZReg(zTmp4Idx).b[i + 32]);
    CG64::cmphs(P_TMP_0, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx), i * 2 + 1);
    CG64::mov(xa::ZRegB(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegB(zTmp2Idx));
  }
}
/* Col=AY119*/
if (false ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true)) {
  CG64::mov(xa::ZRegB(dstIdx), xa::PReg(pTmpIdx) / xa::T_m,
            xa::ZRegB(zTmp3Idx));
}
/* Col=AZ119*/
if (false ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true)) {
  CG64::not_(xa::PRegB(pTmpIdx), P_ALL_ONE, xa::PRegB(pTmpIdx));
}
/* Col=BA119*/
if (false ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true)) {
  CG64::and_(xa::PRegB(pTmpIdx), P_ALL_ONE, xa::PRegB(pTmpIdx), P_MSB_256.b);
}
/* Col=BB119*/
if (false ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true)) {
  CG64::and_(xa::PRegB(pTmpIdx), P_ALL_ONE, xa::PRegB(pTmpIdx), P_MSB_384.b);
}
/* Col=BC119*/
if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
              a64.operands[1].opName == XED_OPERAND_REG1 &&
              a64.operands[2].opName == XED_OPERAND_REG2 &&
              a64.operands[3].opName == XED_OPERAND_INVALID &&
              a64.operands[0].opWidth == 128 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_MEM0 &&
     a64.operands[3].opName == XED_OPERAND_INVALID &&
     a64.operands[0].opWidth == 128 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true)) {
  CG64::mov(xa::ZRegB(dstIdx), P_MSB_384 / xa::T_m, 0);
}
/* Col=BD119*/
if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
              a64.operands[1].opName == XED_OPERAND_REG1 &&
              a64.operands[2].opName == XED_OPERAND_REG2 &&
              a64.operands[3].opName == XED_OPERAND_INVALID &&
              a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_MEM0 &&
     a64.operands[3].opName == XED_OPERAND_INVALID &&
     a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true)) {
  CG64::mov(xa::ZRegB(dstIdx), P_MSB_256 / xa::T_m, 0);
}
/* Col=BE119*/
if (false ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true)) {
  CG64::mov(xa::ZRegB(dstIdx), xa::PRegB(pTmpIdx) / xa::T_m, 0);
}
/* Col=BF119*/
if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
              a64.operands[1].opName == XED_OPERAND_REG1 &&
              a64.operands[2].opName == XED_OPERAND_MEM0 &&
              a64.operands[3].opName == XED_OPERAND_INVALID &&
              a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true)) {
  xt_pop_zreg();
}
/* Col=BG119*/
if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
              a64.operands[1].opName == XED_OPERAND_REG1 &&
              a64.operands[2].opName == XED_OPERAND_REG2 &&
              a64.operands[3].opName == XED_OPERAND_INVALID &&
              a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_MEM0 &&
     a64.operands[3].opName == XED_OPERAND_INVALID &&
     a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true)) {
  xt_pop_zreg();
}

/* Col=BH119*/
if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
              a64.operands[1].opName == XED_OPERAND_REG1 &&
              a64.operands[2].opName == XED_OPERAND_REG2 &&
              a64.operands[3].opName == XED_OPERAND_INVALID &&
              a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_MEM0 &&
     a64.operands[3].opName == XED_OPERAND_INVALID &&
     a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true)) {
  xt_pop_zreg();
}
/* Col=BI119*/
if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
              a64.operands[1].opName == XED_OPERAND_REG1 &&
              a64.operands[2].opName == XED_OPERAND_REG2 &&
              a64.operands[3].opName == XED_OPERAND_INVALID &&
              a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_MEM0 &&
     a64.operands[3].opName == XED_OPERAND_INVALID &&
     a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true)) {
  xt_pop_zreg();
}
/* Col=BJ119*/
if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
              a64.operands[1].opName == XED_OPERAND_REG1 &&
              a64.operands[2].opName == XED_OPERAND_REG2 &&
              a64.operands[3].opName == XED_OPERAND_INVALID &&
              a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_MEM0 &&
     a64.operands[3].opName == XED_OPERAND_INVALID &&
     a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true)) {
  xt_pop_preg();
}
/* Col=BK119*/
if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
              a64.operands[1].opName == XED_OPERAND_REG1 &&
              a64.operands[2].opName == XED_OPERAND_REG2 &&
              a64.operands[3].opName == XED_OPERAND_INVALID &&
              a64.operands[0].opWidth == 128 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_MEM0 &&
     a64.operands[3].opName == XED_OPERAND_INVALID &&
     a64.operands[0].opWidth == 128 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_INVALID &&
     a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_MEM0 &&
     a64.operands[3].opName == XED_OPERAND_INVALID &&
     a64.operands[0].opWidth == 256 && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_REG3 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true) ||
    (a64.operands[0].opName == XED_OPERAND_REG0 &&
     a64.operands[1].opName == XED_OPERAND_REG1 &&
     a64.operands[2].opName == XED_OPERAND_REG2 &&
     a64.operands[3].opName == XED_OPERAND_MEM0 &&
     a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG && true)) {
  XT_VALID_CHECK;
}
XT_VALID_CHECK_IF;
}
#undef CG64
