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
/* 2020/09/08 17:36 */
#define CG64 CodeGeneratorAArch64
void translateVCVTSS2SI(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;

  /* Col=T119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=AD119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AG119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true)) {
    switch (a64.EVEXrc) {
    case 0:
      CG64::fcvtns(xa::XReg(dstIdx), xa::SReg(srcIdx));
      break;
    case 1:
      CG64::fcvtms(xa::XReg(dstIdx), xa::SReg(srcIdx));
      break;
    case 2:
      CG64::fcvtps(xa::XReg(dstIdx), xa::SReg(srcIdx));
      break;
    case 3:
      CG64::fcvtzs(xa::XReg(dstIdx), xa::SReg(srcIdx));
      break;
    default:
      XT_UNIMPLEMENTED;
    }
  }
  /* Col=BQ119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
