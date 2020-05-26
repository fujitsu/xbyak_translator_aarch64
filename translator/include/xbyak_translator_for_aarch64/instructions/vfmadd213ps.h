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
/* 2020/04/10 13:05 */
#define CG64 CodeGeneratorAArch64
void translateVFMADD213PS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;
  xt_reg_idx_t src2Idx;
  xt_reg_idx_t maskIdx;
  xt_reg_idx_t zTmpIdx;
  xt_reg_idx_t pTmpIdx;

  /* Col=T119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
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
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
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
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
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
    CG64::mov(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
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
    CG64::zip1(xa::PReg(pTmpIdx).b, xa::PReg(maskIdx).b, xa::PReg(maskIdx).b);
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
    CG64::zip1(xa::PReg(pTmpIdx).h, xa::PReg(pTmpIdx).h, xa::PReg(pTmpIdx).h);
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
    CG64::zip1(P_TMP_0.b, xa::PReg(maskIdx).b, xa::PReg(maskIdx).b);
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
    CG64::zip1(P_TMP_0.h, P_TMP_0.h, P_TMP_0.h);
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
    CG64::not_(P_TMP_0.b, P_ALL_ONE.b, P_TMP_0.b);
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
    CG64::orn(P_TMP_0.b, P_ALL_ONE / xa::T_z, P_MSB_256.b, P_TMP_0.b);
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
    CG64::orn(P_TMP_0.b, P_ALL_ONE / xa::T_z, P_MSB_384.b, P_TMP_0.b);
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
    CG64::fmad(xa::ZRegS(dstIdx), xa::PReg(pTmpIdx) / xa::T_m,
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
    CG64::fmad(xa::ZRegS(dstIdx), xa::PReg(pTmpIdx) / xa::T_m,
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
    CG64::mov(xa::ZRegS(dstIdx), P_MSB_256 / xa::T_m, 0);
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
    CG64::mov(xa::ZRegS(dstIdx), P_MSB_384 / xa::T_m, 0);
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
    CG64::mov(xa::ZRegS(dstIdx), P_TMP_0 / xa::T_m, 0);
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
#undef CG64
