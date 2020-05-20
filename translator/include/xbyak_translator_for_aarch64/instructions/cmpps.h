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
/* 2020/05/20 22:07 */
#define CG64 CodeGeneratorAArch64
void translateCMPPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;
  xt_reg_idx_t src2Idx;
  xt_reg_idx_t zTmpIdx;
  xt_reg_idx_t pTmpIdx;
  xt_reg_idx_t cmpDstIdx;
  xt_reg_idx_t cmpMaskIdx;
  xt_reg_idx_t cmpSrcIdx;
  xt_reg_idx_t cmpSrc2Idx;
  uint32_t uimm;

  /* Col=Y119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=AA119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AG119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AJ119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    srcIdx = a64.operands[0].regIdx;
  }
  /* Col=AK119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true)) {
    src2Idx = a64.operands[1].regIdx;
  }
  /* Col=AL119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    uimm = a64.operands[2].uimm;
  }
  /* Col=AM119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    CG64::not_(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_384.b);
  }
  /* Col=AR119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    cmpDstIdx = pTmpIdx;
  }
  /* Col=AU119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    cmpMaskIdx = pTmpIdx;
  }
  /* Col=AW119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    cmpSrcIdx = srcIdx;
  }
  /* Col=AX119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true)) {
    cmpSrc2Idx = src2Idx;
  }
  /* Col=AY119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    cmpSrc2Idx = zTmpIdx;
  }
  /* Col=BA119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    CG64::ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=BD119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    switch (uimm) {
    case EQ_OQ:
      CG64::fcmeq(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                  xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case LT_OS:
      CG64::fcmlt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                  xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case LE_OS:
      CG64::fcmle(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                  xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NEQ_UQ:
      CG64::fcmne(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                  xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NLT_US:
      CG64::fcmge(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                  xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NLE_US:
      CG64::fcmgt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                  xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;

    case UNORD_Q:
    case ORD_Q:
    default:
      xt_msg_err(__FILE__, __LINE__, "Unsupported compare mode");
      break;
      break;
    }
  }
  /* Col=BG119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    CG64::cpy(xa::ZRegS(zTmpIdx), xa::PReg(pTmpIdx) / xa::T_z, 255);
  }
  /* Col=BH119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    CG64::not_(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_384.b);
  }
  /* Col=BI119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    CG64::mov(xa::ZRegS(dstIdx), xa::PReg(pTmpIdx) / xa::T_m,
              xa::ZRegS(zTmpIdx));
  }
  /* Col=BM119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    xt_pop_zreg();
  }
  /* Col=BN119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    xt_pop_preg();
  }
  /* Col=BO119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
