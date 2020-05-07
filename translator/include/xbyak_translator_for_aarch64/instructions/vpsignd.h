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
/* 2020/05/07 09:08 */
#define CG64 CodeGeneratorAArch64
void translateVPSIGND(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  xa::LabelAArch64 L_zflag, L_cflag;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;
  xt_reg_idx_t src2Idx;
  xt_reg_idx_t zTmpIdx;

  /* Col=AA119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AG119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }

  /* Col=AH119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    src2Idx = zTmpIdx;
  }
  /* Col=AJ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AL119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    CG64::mov(xa::ZRegS(dstIdx), P_MSB_384 / xa::T_m, 0);
  }
  /* Col=AM119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    CG64::mov(xa::ZRegS(dstIdx), P_MSB_256 / xa::T_m, 0);
  }
  /* Col=AO119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    CG64::ptrue(P_TMP.s, xa::VL4);
  }
  /* Col=AP119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    CG64::ptrue(P_TMP.s, xa::VL8);
  }
  /* Col=AQ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    CG64::ptrue(P_TMP_1.s, xa::VL4);
  }

  /* Col=AR119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    CG64::ptrue(P_TMP_1.s, xa::VL8);
  }
  /* Col=AT119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 128 && true)) {
    CG64::ldr(xa::QReg(src2Idx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AU119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 && true)) {
    CG64::ld1w(xa::ZRegS(src2Idx), P_TMP / xa::T_z, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AW119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    CG64::cmpeq(P_TMP_0.s, P_TMP / xa::T_z, xa::ZRegS(src2Idx), 0);
  }
  /* Col=AX119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    CG64::cmplt(P_TMP.s, P_TMP / xa::T_z, xa::ZRegS(src2Idx), 0);
  }
  /* Col=BA119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    CG64::mov(xa::ZRegS(dstIdx), P_TMP_1 / xa::T_m, xa::ZRegS(srcIdx));
  }

  /* Col=BB119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    CG64::mov(xa::ZRegS(dstIdx), P_TMP_0 / xa::T_m, 0);
  }
  /* Col=BC119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    CG64::neg(xa::ZRegS(dstIdx), P_TMP / xa::T_m, xa::ZRegS(srcIdx));
  }

  /* Col=BS119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xt_pop_zreg();
  }
  /* Col=BU119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
