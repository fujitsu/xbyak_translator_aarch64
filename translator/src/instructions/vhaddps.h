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
/* 2020/09/09 11:53 */

void Xbyak::CodeGenerator::translateVHADDPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t src2Idx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmp2Idx = XT_REG_INVALID;
  xt_reg_idx_t zTmp3Idx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;

  /* Col=T119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=U119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=W119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=X119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=Y119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    zTmp3Idx = xt_push_zreg(&a64);
  }
  /* Col=Z119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AC119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AD119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AG119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM && true)) {
    xa_->faddp(xa::VReg(dstIdx).s4, xa::VReg(srcIdx).s4, xa::VReg(src2Idx).s4);
  }
  /* Col=AH119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->faddp(xa::VReg(zTmp3Idx).s4, xa::VReg(srcIdx).s4,
               xa::VReg(src2Idx).s4);
  }
  /* Col=AJ119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->mov(xa::ZRegD(zTmpIdx), xa::ZRegD(srcIdx));
  }
  /* Col=AK119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->mov(xa::ZRegD(zTmp2Idx), xa::ZRegD(src2Idx));
  }
  /* Col=AM119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->not_(xa::PRegB(pTmpIdx), P_ALL_ONE, P_MSB_256.b);
  }
  /* Col=AO119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->ext(xa::ZRegB(zTmpIdx), xa::ZRegB(zTmpIdx), 16);
  }
  /* Col=AP119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->ext(xa::ZRegB(zTmp2Idx), xa::ZRegB(zTmp2Idx), 16);
  }
  /* Col=AS119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->faddp(xa::VReg(zTmpIdx).s4, xa::VReg(zTmpIdx).s4,
               xa::VReg(zTmp2Idx).s4);
  }
  /* Col=AU119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->ext(xa::ZRegB(zTmpIdx), xa::ZRegB(zTmpIdx), 48);
  }
  /* Col=AV119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->fadd(xa::ZRegS(dstIdx), xa::ZRegS(zTmp3Idx), xa::ZRegS(zTmpIdx));
  }
  /* Col=BG119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    xt_pop_zreg();
  }
  /* Col=BH119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    xt_pop_zreg();
  }
  /* Col=BI119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    xt_pop_zreg();
  }
  /* Col=BJ119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    xt_pop_preg();
  }
  /* Col=BQ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
