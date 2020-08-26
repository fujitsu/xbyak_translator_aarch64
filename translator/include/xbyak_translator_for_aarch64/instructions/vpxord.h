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
/* 2020/07/03 16:58 */
#define CG64 Xbyak_aarch64::CodeGenerator
void translateVPXORD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t src2Idx = XT_REG_INVALID;
  xt_reg_idx_t maskIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t vTmpIdx = XT_REG_INVALID;

  /* Col=T119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=U119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true)) {
    vTmpIdx = xt_push_vreg(&a64);
  }
  /* Col=V119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=X119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=Y119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=Z119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AA119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AC119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true)) {
    CG64::ld1(xa::VReg(vTmpIdx).s4, xa::ptr(X_TMP_ADDR));
  }

  /* Col=AD119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 1 && true)) {
    CG64::ld1r(xa::VReg(vTmpIdx).s4, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AE119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    CG64::ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AF119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    CG64::ld1rw(xa::ZReg(zTmpIdx).s, xa::PReg(maskIdx) / xa::T_z,
                xa::ptr(X_TMP_ADDR));
  }
  /* Col=AH119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }

  /* Col=AN119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true)) {
    CG64::not_(xa::PRegB(pTmpIdx), P_ALL_ONE.b, xa::PRegB(maskIdx));
  }
  /* Col=AO119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true)) {
    CG64::orn(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_256.b,
              xa::PRegB(maskIdx));
  }
  /* Col=AP119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true)) {
    CG64::orn(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_384.b,
              xa::PRegB(maskIdx));
  }
  /* Col=AQ119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true)) {
    CG64::eor(xa::VReg16B(dstIdx), xa::VReg16B(srcIdx), xa::VReg16B(src2Idx));
  }
  /* Col=AR119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true)) {
    CG64::eor(xa::VReg16B(dstIdx), xa::VReg16B(srcIdx), xa::VReg16B(vTmpIdx));
  }
  /* Col=AS119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    CG64::eor(xa::ZRegD(dstIdx), xa::ZRegD(srcIdx), xa::ZRegD(src2Idx));
  }
  /* Col=AT119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true)) {
    CG64::eor(xa::ZRegD(dstIdx), xa::ZRegD(srcIdx), xa::ZRegD(zTmpIdx));
  }
  /* Col=AU119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    CG64::eor(xa::ZRegD(zTmpIdx), xa::ZRegD(srcIdx), xa::ZRegD(src2Idx));
  }
  /* Col=AV119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    CG64::eor(xa::ZRegD(zTmpIdx), xa::ZRegD(srcIdx), xa::ZRegD(zTmpIdx));
  }

  /* Col=AX119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    CG64::mov(xa::ZRegS(dstIdx), xa::PReg(maskIdx) / xa::T_m,
              xa::ZRegS(zTmpIdx));
  }
  /* Col=AY119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    CG64::mov(xa::ZReg(dstIdx).s, P_MSB_256 / xa::T_m, 0);
  }
  /* Col=AZ119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    CG64::mov(xa::ZReg(dstIdx).s, P_MSB_384 / xa::T_m, 0);
  }
  /* Col=BA119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true)) {
    CG64::mov(xa::ZReg(dstIdx).s, xa::PReg(pTmpIdx) / xa::T_m, 0);
  }
  /* Col=BD119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true)) {
    xt_pop_preg();
  }
  /* Col=BE119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xt_pop_zreg(); // In some cases, xt_pop_zreg() should be called here.
  }
  /* Col=BF119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true)) {
    xt_pop_vreg();
  }

  /* Col=BQ119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
