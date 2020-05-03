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
/* 2020/05/03 15:50 */
#define CG64 CodeGeneratorAArch64
void translateVROUNDPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  xa::LabelAArch64 L_zflag, L_cflag;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  unsigned int rounding_direction = a64.operands[2].uimm & 0x3;
  bool isValid = false;
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;
  xt_reg_idx_t zTmpIdx;

  /* Col=AA119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }

  /* Col=AH119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AJ119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    srcIdx = zTmpIdx;
  }
  /* Col=AK119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    CG64::ptrue(P_TMP.s, xa::VL4);
  }
  /* Col=AL119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    CG64::ptrue(P_TMP.s, xa::VL8);
  }
  /* Col=AN119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 128 && true)) {
    CG64::ldr(xa::QReg(srcIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AO119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 && true)) {
    CG64::ld1w(xa::ZRegS(srcIdx), P_TMP / xa::T_z, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AQ119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    switch (rounding_direction) {
    case 0:
      CG64::frintn(xa::VReg4S(dstIdx), xa::VReg4S(srcIdx));
      break;
    case 1:
      CG64::frintm(xa::VReg4S(dstIdx), xa::VReg4S(srcIdx));
      break;
    case 2:
      CG64::frintp(xa::VReg4S(dstIdx), xa::VReg4S(srcIdx));
      break;
    case 3:
      CG64::frintz(xa::VReg4S(dstIdx), xa::VReg4S(srcIdx));
      break;
    default:
      XT_UNIMPLEMENTED;
      break;
    }
  }

  /* Col=AR119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    switch (rounding_direction) {
    case 0:
      CG64::frintn(xa::ZRegS(dstIdx), P_TMP / xa::T_m, xa::ZRegS(srcIdx));
      break;
    case 1:
      CG64::frintm(xa::ZRegS(dstIdx), P_TMP / xa::T_m, xa::ZRegS(srcIdx));
      break;
    case 2:
      CG64::frintp(xa::ZRegS(dstIdx), P_TMP / xa::T_m, xa::ZRegS(srcIdx));
      break;
    case 3:
      CG64::frintz(xa::ZRegS(dstIdx), P_TMP / xa::T_m, xa::ZRegS(srcIdx));
      break;
    default:
      XT_UNIMPLEMENTED;
      break;
    }
  }
  /* Col=AW119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    CG64::mov(xa::ZRegS(dstIdx), P_MSB_256 / xa::T_m, 0);
  }

  /* Col=BS119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xt_pop_zreg();
  }
  /* Col=BU119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
