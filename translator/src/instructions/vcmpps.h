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
/* 2020/06/30 22:56 */

void Xbyak::CodeGenerator::translateVCMPPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t maskIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t cmpDstIdx = XT_REG_INVALID;
  xt_reg_idx_t cmpMaskIdx = XT_REG_INVALID;
  xt_reg_idx_t cmpSrcIdx = XT_REG_INVALID;
  xt_reg_idx_t cmpSrc2Idx = XT_REG_INVALID;
  uint32_t uimm = 0;

  /* Col=AD119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 1 && isAvailAll1Preg0_7() == true && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AE119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 1 && isAvailAll1Preg0_7() == true && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AH119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 1 && isAvailAll1Preg0_7() == true && true)) {
    uimm = a64.operands[4].uimm;
  }
  /* Col=AR119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 1 && isAvailAll1Preg0_7() == true && true)) {
    cmpDstIdx = dstIdx;
  }
  /* Col=AV119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 1 && isAvailAll1Preg0_7() == true && true)) {
    cmpSrcIdx = a64.operands[2].regIdx;
  }
  /* Col=AW119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true)) {
    cmpSrc2Idx = a64.operands[3].regIdx;
  }
  /* Col=AX119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 1 && isAvailAll1Preg0_7() == true && true)) {
    cmpSrc2Idx = zTmpIdx;
  }
  /* Col=AZ119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true)) {
    xa_->ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=BA119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 1 && isAvailAll1Preg0_7() == true && true)) {
    xa_->ld1rw(xa::ZRegS(zTmpIdx), P_ALL_ONE_0_7 / xa::T_z,
               xa::ptr(X_TMP_ADDR));
  }
  /* Col=BC119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 1 && isAvailAll1Preg0_7() == true && true)) {
    switch (uimm) {
    case EQ_OQ:
      xa_->fcmeq(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case LT_OS:
      xa_->fcmlt(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case LE_OS:
      xa_->fcmle(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NEQ_UQ:
      xa_->fcmne(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NLT_US:
      xa_->fcmge(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NLE_US:
      xa_->fcmgt(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case EQ_UQ:
      xa_->fcmeq(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NGE_US:
      xa_->fcmlt(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NGT_US:
      xa_->fcmle(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NEQ_OQ:
      xa_->fcmne(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case GE_OS:
      xa_->fcmge(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case GT_OS:
      xa_->fcmgt(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case EQ_OS:
      xa_->fcmeq(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case LT_OQ:
      xa_->fcmlt(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case LE_OQ:
      xa_->fcmle(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NEQ_US:
      xa_->fcmne(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NLT_UQ:
      xa_->fcmge(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NLE_UQ:
      xa_->fcmgt(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case EQ_US:
      xa_->fcmeq(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NGE_UQ:
      xa_->fcmlt(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NGT_UQ:
      xa_->fcmle(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NEQ_OS:
      xa_->fcmne(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case GE_OQ:
      xa_->fcmge(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case GT_OQ:
      xa_->fcmgt(xa::PRegS(cmpDstIdx), P_ALL_ONE_0_7 / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;

    case UNORD_Q:
    case ORD_Q:
    case FALSE_OQ:
    case TRUE_UQ:
    case UNORD_S:
    case ORD_S:
    case FALSE_OS:
    case TRUE_US:
    default:
      xt_msg_err(__FILE__, __LINE__, "Unsupported compare mode");
      break;
      break;
    }
  }
  /* Col=BV119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 1 && isAvailAll1Preg0_7() == true && true)) {
    xt_pop_zreg();
  }
  /* Col=BY119*/
  if (false ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 0 && isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64_opt.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64_opt.operands[0].opWidth == 64 && a64_opt.predType == A64_PRED_NO &&
       a64_opt.EVEXb == 1 && isAvailAll1Preg0_7() == true && true)) {
    return;
  }
  /* Col=T119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=U119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=V119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=W119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=X119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=Y119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true)) {
    uimm = a64.operands[3].uimm;
  }
  /* Col=Z119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    uimm = a64.operands[4].uimm;
  }
  /* Col=AA119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xa_->bic(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, xa::PRegB(maskIdx),
             P_MSB_384.b);
  }
  /* Col=AB119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xa_->bic(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, xa::PRegB(maskIdx),
             P_MSB_256.b);
  }
  /* Col=AC119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xa_->not_(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_384.b);
  }
  /* Col=AD119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xa_->not_(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_256.b);
  }
  /* Col=AF119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xa_->mov(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_ALL_ONE.b);
  }
  /* Col=AG119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
                a64.operands[0].opWidth == 64 &&
                a64.predType == A64_PRED_MERG && a64.EVEXb == 0 && true)) {
    xa_->mov(xa::PRegB(pTmpIdx), xa::PRegB(maskIdx));
  }
  /* Col=AH119*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_IMM0 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true)) {
    xa_->ldr(xa::QReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    cmpDstIdx = pTmpIdx;
  }
  /* Col=AJ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true)) {
    cmpDstIdx = dstIdx;
  }
  /* Col=AK119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AL119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    cmpMaskIdx = pTmpIdx;
  }
  /* Col=AM119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    cmpMaskIdx = a64.operands[1].regIdx;
  }
  /* Col=AN119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    cmpSrcIdx = a64.operands[2].regIdx;
  }
  /* Col=AO119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    cmpSrc2Idx = a64.operands[3].regIdx;
  }
  /* Col=AP119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true)) {
    cmpSrcIdx = a64.operands[1].regIdx;
  }
  /* Col=AQ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true)) {
    cmpSrc2Idx = a64.operands[2].regIdx;
  }
  /* Col=AR119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    cmpSrc2Idx = zTmpIdx;
  }
  /* Col=AS119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xa_->ld1w(xa::ZRegS(zTmpIdx), xa::PReg(pTmpIdx) / xa::T_z,
              xa::ptr(X_TMP_ADDR));
  }
  /* Col=AT119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xa_->ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AU119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true)) {
    xa_->ld1rw(xa::ZRegS(zTmpIdx), xa::PReg(pTmpIdx) / xa::T_z,
               xa::ptr(X_TMP_ADDR));
  }
  /* Col=AV119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xa_->ld1rw(xa::ZRegS(zTmpIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
               xa::ptr(X_TMP_ADDR));
  }
  /* Col=AW119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    switch (uimm) {
    case EQ_OQ:
      xa_->fcmeq(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case LT_OS:
      xa_->fcmlt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case LE_OS:
      xa_->fcmle(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NEQ_UQ:
      xa_->fcmne(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NLT_US:
      xa_->fcmge(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NLE_US:
      xa_->fcmgt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case EQ_UQ:
      xa_->fcmeq(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NGE_US:
      xa_->fcmlt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NGT_US:
      xa_->fcmle(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NEQ_OQ:
      xa_->fcmne(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case GE_OS:
      xa_->fcmge(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case GT_OS:
      xa_->fcmgt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case EQ_OS:
      xa_->fcmeq(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case LT_OQ:
      xa_->fcmlt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case LE_OQ:
      xa_->fcmle(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NEQ_US:
      xa_->fcmne(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NLT_UQ:
      xa_->fcmge(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NLE_UQ:
      xa_->fcmgt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case EQ_US:
      xa_->fcmeq(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NGE_UQ:
      xa_->fcmlt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NGT_UQ:
      xa_->fcmle(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case NEQ_OS:
      xa_->fcmne(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case GE_OQ:
      xa_->fcmge(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;
    case GT_OQ:
      xa_->fcmgt(xa::PRegS(cmpDstIdx), xa::PReg(cmpMaskIdx) / xa::T_z,
                 xa::ZRegS(cmpSrcIdx), xa::ZRegS(cmpSrc2Idx));
      break;

    case UNORD_Q:
    case ORD_Q:
    case FALSE_OQ:
    case TRUE_UQ:
    case UNORD_S:
    case ORD_S:
    case FALSE_OS:
    case TRUE_US:
    default:
      xt_msg_err(__FILE__, __LINE__, "Unsupported compare mode");
      break;
      break;
    }
  }
  /* Col=AX119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true)) {
    switch (uimm) {
    case EQ_OQ:
      xa_->fcmeq(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      break;
    case LT_OS:
      xa_->fcmgt(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrc2Idx),
                 xa::VReg4S(cmpSrcIdx));
      break;
    case LE_OS:
      xa_->fcmge(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrc2Idx),
                 xa::VReg4S(cmpSrcIdx));
      break;
    case NEQ_UQ:
      xa_->fcmeq(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      xa_->not_(xa::VReg16B(cmpDstIdx), xa::VReg16B(cmpDstIdx));

      break;
    case NLT_US:
      xa_->fcmge(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      break;
    case NLE_US:
      xa_->fcmgt(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      break;
    case EQ_UQ:
      xa_->fcmeq(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      break;
    case NGE_US:
      xa_->fcmgt(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrc2Idx),
                 xa::VReg4S(cmpSrcIdx));
      break;
    case NGT_US:
      xa_->fcmge(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrc2Idx),
                 xa::VReg4S(cmpSrcIdx));
      break;
    case NEQ_OQ:
      xa_->fcmeq(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      xa_->not_(xa::VReg16B(cmpDstIdx), xa::VReg16B(cmpDstIdx));
      break;
    case GE_OS:
      xa_->fcmge(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      break;
    case GT_OS:
      xa_->fcmgt(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      break;
    case EQ_OS:
      xa_->fcmeq(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      break;
    case LT_OQ:
      xa_->fcmgt(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrc2Idx),
                 xa::VReg4S(cmpSrcIdx));
      break;
    case LE_OQ:
      xa_->fcmge(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrc2Idx),
                 xa::VReg4S(cmpSrcIdx));
      break;
    case NEQ_US:
      xa_->fcmeq(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      xa_->not_(xa::VReg16B(cmpDstIdx), xa::VReg16B(cmpDstIdx));
      break;
    case NLT_UQ:
      xa_->fcmge(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      break;
    case NLE_UQ:
      xa_->fcmgt(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      break;
    case EQ_US:
      xa_->fcmeq(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      break;
    case NGE_UQ:
      xa_->fcmgt(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrc2Idx),
                 xa::VReg4S(cmpSrcIdx));
      break;
    case NGT_UQ:
      xa_->fcmge(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrc2Idx),
                 xa::VReg4S(cmpSrcIdx));
      break;
    case NEQ_OS:
      xa_->fcmeq(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      xa_->not_(xa::VReg16B(cmpDstIdx), xa::VReg16B(cmpDstIdx));
      break;
    case GE_OQ:
      xa_->fcmge(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      break;
    case GT_OQ:
      xa_->fcmgt(xa::VReg4S(cmpDstIdx), xa::VReg4S(cmpSrcIdx),
                 xa::VReg4S(cmpSrc2Idx));
      break;

    case UNORD_Q:
    case ORD_Q:
    case FALSE_OQ:
    case TRUE_UQ:
    case UNORD_S:
    case ORD_S:
    case FALSE_OS:
    case TRUE_US:
    default:
      xt_msg_err(__FILE__, __LINE__, "Unsupported compare mode");
      break;
      break;
    }
  }
  /* Col=BC119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xa_->mov(xa::PRegB(dstIdx), xa::PReg(maskIdx) / xa::T_m,
             xa::PRegB(pTmpIdx));
  }
  /* Col=BD119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xa_->mov(xa::PRegB(dstIdx), xa::PReg(maskIdx) / xa::T_z,
             xa::PRegB(pTmpIdx));
  }
  /* Col=BE119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true)) {
    xa_->cpy(xa::ZRegS(dstIdx), xa::PReg(pTmpIdx) / xa::T_z, 255);
  }
  /* Col=BH119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xt_pop_zreg();
  }
  /* Col=BI119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    xt_pop_preg();
  }
  /* Col=BQ119*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[1].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
