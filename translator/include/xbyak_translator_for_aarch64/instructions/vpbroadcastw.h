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
/* 2020/05/13 11:26 */
#define CG64 CodeGeneratorAArch64
void translateVPBROADCASTW(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;
  xt_reg_idx_t maskIdx;
  xt_reg_idx_t zTmpIdx;
  xt_reg_idx_t pTmpIdx;

  /* Col=X119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=Y119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=Z119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AC119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[2].regClass == XED_REG_CLASS_GPR &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    maskIdx = a64.operands[1].regIdx;
  }

  /* Col=AG119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[2].regClass == XED_REG_CLASS_GPR &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AH119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[2].regClass == XED_REG_CLASS_GPR &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=AJ119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[2].regClass == XED_REG_CLASS_GPR &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::zip1(xa::PReg(pTmpIdx).b, xa::PReg(maskIdx).b, xa::PReg(maskIdx).b);
  }

  /* Col=AN119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[2].regClass == XED_REG_CLASS_GPR &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true)) {
    CG64::orn(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_384.b,
              xa::PRegB(pTmpIdx));
  }
  /* Col=AO119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[2].regClass == XED_REG_CLASS_GPR &&
                a64.operands[0].opWidth == 256 &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true)) {
    CG64::orn(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_256.b,
              xa::PRegB(pTmpIdx));
  }
  /* Col=AP119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[2].regClass == XED_REG_CLASS_GPR &&
                a64.operands[0].opWidth == 512 &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true)) {
    CG64::not_(xa::PRegB(pTmpIdx), P_ALL_ONE.b, xa::PRegB(pTmpIdx));
  }
  /* Col=AQ119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[0].opWidth == 256 &&
                a64.predType == A64_PRED_ZERO && true)) {
    CG64::bic(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, xa::PRegB(pTmpIdx),
              P_MSB_256.b);
  }
  /* Col=AR119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    CG64::ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AS119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true)) {
    CG64::ld1r(xa::VReg8H(dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AT119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[0].opWidth == 256 &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true)) {
    CG64::ld1rh(xa::ZRegH(dstIdx), xa::PReg(pTmpIdx) / xa::T_z,
                xa::ptr(X_TMP_ADDR));
  }
  /* Col=AU119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::ld1rh(xa::ZRegH(zTmpIdx), xa::PReg(pTmpIdx) / xa::T_z,
                xa::ptr(X_TMP_ADDR));
  }
  /* Col=AV119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true)) {
    CG64::dup(xa::VReg8H(dstIdx), xa::WReg(srcIdx));
  }
  /* Col=AW119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true)) {
    CG64::dup(xa::ZRegH(dstIdx), xa::WReg(srcIdx));
  }

  /* Col=AY119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[2].regClass == XED_REG_CLASS_GPR &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::dup(xa::ZRegH(zTmpIdx), xa::WReg(srcIdx));
  }
  /* Col=AZ119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true)) {
    CG64::dup(xa::VReg8H(dstIdx), xa::VReg8H(srcIdx)[0]);
  }
  /* Col=BA119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true)) {
    CG64::dup(xa::ZRegH(dstIdx), xa::ZRegH(srcIdx)[0]);
  }
  /* Col=BC119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::dup(xa::ZRegH(zTmpIdx), xa::ZRegH(srcIdx)[0]);
  }
  /* Col=BD119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    CG64::dup(xa::ZRegH(dstIdx), W_TMP_0);
  }

  /* Col=BH119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[2].regClass == XED_REG_CLASS_GPR &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true)) {
    CG64::mov(xa::ZRegH(dstIdx), xa::PReg(pTmpIdx) / xa::T_m, 0);
  }
  /* Col=BI119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[2].regClass == XED_REG_CLASS_GPR &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::mov(xa::ZRegH(dstIdx), xa::PReg(pTmpIdx) / xa::T_m,
              xa::ZRegH(zTmpIdx));
  }
  /* Col=BJ119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::mov(xa::ZRegH(dstIdx), P_MSB_256 / xa::T_m, 0);
  }
  /* Col=BK119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    CG64::mov(xa::ZRegH(dstIdx), P_MSB_384 / xa::T_m, 0);
  }
  /* Col=BN119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[2].regClass == XED_REG_CLASS_GPR &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_preg();
  }
  /* Col=BO119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[2].regClass == XED_REG_CLASS_GPR &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BQ119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_GPR &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
