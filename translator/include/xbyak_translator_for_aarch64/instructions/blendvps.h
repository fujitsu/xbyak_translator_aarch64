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
/* 2020/07/02 10:46 */
#define CG64 CodeGeneratorAArch64
void translateBLENDVPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t maskIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;

  /* Col=AE119*/
  if (false || (a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
                isAvailAll1Preg0_7() == true && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AG119*/
  if (false ||
      (a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       isAvailAll1Preg0_7() == true && true)) {
    maskIdx = a64.operands[2].regIdx;
  }
  /* Col=AI119*/
  if (false || (a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
                isAvailAll1Preg0_7() == true && true)) {
    CG64::ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AL119*/
  if (false ||
      (a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       isAvailAll1Preg0_7() == true && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AO119*/
  if (false || (a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
                isAvailAll1Preg0_7() == true && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AQ119*/
  if (false || (a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
                isAvailAll1Preg0_7() == true && true)) {
    srcIdx = zTmpIdx;
  }
  /* Col=AV119*/
  if (false ||
      (a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       isAvailAll1Preg0_7() == true && true)) {
    CG64::cmplt(P_TMP_0.s, P_ALL_ONE_0_7 / xa::T_z, xa::ZReg(maskIdx).s, 0);
  }
  /* Col=AX119*/
  if (false ||
      (a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       isAvailAll1Preg0_7() == true && true)) {
    CG64::not_(P_TMP_1.b, P_ALL_ONE, P_MSB_384.b);
  }
  /* Col=AY119*/
  if (false ||
      (a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       isAvailAll1Preg0_7() == true && true)) {
    CG64::and_(P_TMP_0.b, P_ALL_ONE, P_TMP_0.b, P_TMP_1.b);
  }
  /* Col=BA119*/
  if (false ||
      (a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       isAvailAll1Preg0_7() == true && true)) {
    CG64::mov(xa::ZReg(dstIdx).s, P_TMP_0 / xa::T_m, xa::ZReg(srcIdx).s);
  }
  /* Col=BQ119*/
  if (false || (a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
                isAvailAll1Preg0_7() == true && true)) {
    xt_pop_zreg();
  }
  /* Col=BY119*/
  if (false ||
      (a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       isAvailAll1Preg0_7() == true && true)) {
    return;
  }
  /* Col=U119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=W119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=Y119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    maskIdx = a64.operands[2].regIdx;
  }
  /* Col=AA119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    CG64::ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
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
  /* Col=AI119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    srcIdx = zTmpIdx;
  }
  /* Col=AK119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    CG64::movs(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=AN119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    CG64::cmplt(P_TMP_0.s, xa::PReg(pTmpIdx) / xa::T_z, xa::ZReg(maskIdx).s, 0);
  }
  /* Col=AP119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    CG64::not_(xa::PRegB(pTmpIdx), P_ALL_ONE, P_MSB_384.b);
  }
  /* Col=AQ119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    CG64::and_(P_TMP_0.b, P_ALL_ONE, P_TMP_0.b, xa::PRegB(pTmpIdx));
  }
  /* Col=AS119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    CG64::mov(xa::ZReg(dstIdx).s, P_TMP_0 / xa::T_m, xa::ZReg(srcIdx).s);
  }
  /* Col=BI119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    xt_pop_zreg();
  }
  /* Col=BJ119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    xt_pop_preg();
  }
  /* Col=BQ119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
