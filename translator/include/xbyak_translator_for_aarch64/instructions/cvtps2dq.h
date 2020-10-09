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
/* 2020/09/08 01:10 */

void translateCVTPS2DQ(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;

  /* Col=U119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AC119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    xa_->ptrue(P_TMP_0.s, xa::VL4);
  }

  /* Col=AD119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AG119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AH119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    srcIdx = zTmpIdx;
  }
  /* Col=AL119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    xa_->ld1(xa::VReg4S(srcIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AO119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    xa_->frinti(xa::VReg4S(zTmpIdx), xa::VReg4S(srcIdx));
  }
  /* Col=AP119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    xa_->fcvtzs(xa::VReg4S(zTmpIdx), xa::VReg4S(zTmpIdx));
  }

  /* Col=BC119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_TMP_0 / xa::T_m, xa::ZRegS(zTmpIdx));
  }

  /* Col=BI119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    xt_pop_zreg();
  }
  /* Col=BQ119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}

