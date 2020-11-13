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
/* 2020/06/03 15:22 */

void translatePINSRW(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  uint64_t uimm = 0;
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;

  /* Col=X119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=AC119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AD119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AE119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 128 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }

  /* Col=AH119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    uimm = a64.operands[2].uimm & 0x7;
  }
  /* Col=AK119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 128 && true)) {
    xa_->mov(xa::VReg8H(zTmpIdx)[uimm], xa::WReg(srcIdx));
  }
  /* Col=AL119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 128 && true)) {
    xa_->ld1r(xa::VReg8H(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AO119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    xa_->ptrue(P_TMP_0.h, static_cast<xa::Pattern>(uimm + 1));
  }
  /* Col=AP119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    if (uimm) {
      xa_->ptrue(P_TMP_1.h, static_cast<xa::Pattern>(uimm));
    } else {
      xa_->pfalse(P_TMP_1.b);
    }
  }
  /* Col=AQ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    xa_->bic(P_TMP_0.b, P_ALL_ONE / xa::T_z, P_TMP_0.b, P_TMP_1.b);
  }

  /* Col=AV119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    xa_->sel(xa::ZRegH(dstIdx), P_TMP_0 / xa::T_m, xa::ZRegH(zTmpIdx),
             xa::ZRegH(dstIdx));
  }

  /* Col=BB119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    xt_pop_zreg();
  }

  /* Col=BO119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
