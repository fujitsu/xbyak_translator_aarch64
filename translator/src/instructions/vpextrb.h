/*******************************************************************************
 * Copyright 2020 FUJITSU LIMITED
 *
 * Licensed under the Apache License, Version 2.0 (the   License  );
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an   AS IS   BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
/* 2020/05/26 12:05 */

void Xbyak::CodeGenerator::translateVPEXTRB(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;
  xed_uint64_t uimm = 0;

  /* Col=T119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=V119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=W119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=X119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true)) {
    uimm = a64.operands[2].uimm;
  }
  /* Col=Z119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=AA119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true)) {
    if ((uimm & 0xf) >= 8) {
      zTmpIdx = xt_push_zreg(&a64);
    }
  }

  /* Col=AD119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true)) {
    if ((uimm & 0xf) >= 8) {
      xa_->zip2(xa::VReg16B(zTmpIdx), xa::VReg16B(srcIdx), xa::VReg16B(srcIdx));
      xa_->uzp1(xa::VReg16B(zTmpIdx), xa::VReg16B(zTmpIdx),
                xa::VReg16B(zTmpIdx));
      xa_->ptrue(xa::PReg(pTmpIdx).b, xa::Pattern((uimm & 0xf) - 7));
      xa_->lastb(xa::WReg(dstIdx), xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx));
    } else {
      xa_->ptrue(xa::PReg(pTmpIdx).b, xa::Pattern((uimm & 0xf) + 1));
      xa_->lastb(xa::WReg(dstIdx), xa::PReg(pTmpIdx), xa::ZRegB(srcIdx));
    }
  }
  /* Col=AE119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true)) {
    if ((uimm & 0xf) >= 8) {
      xa_->zip2(xa::VReg16B(zTmpIdx), xa::VReg16B(srcIdx), xa::VReg16B(srcIdx));
      xa_->uzp1(xa::VReg16B(zTmpIdx), xa::VReg16B(zTmpIdx),
                xa::VReg16B(zTmpIdx));
      xa_->ptrue(xa::PReg(pTmpIdx).b, xa::Pattern((uimm & 0xf) - 7));
      xa_->lastb(W_TMP_0, xa::PReg(pTmpIdx), xa::ZRegB(zTmpIdx));
    } else {
      xa_->ptrue(xa::PReg(pTmpIdx).b, xa::Pattern((uimm & 0xf) + 1));
      xa_->lastb(W_TMP_0, xa::PReg(pTmpIdx), xa::ZRegB(srcIdx));
    }
  }
  /* Col=AG119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true)) {
    xa_->strb(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true)) {
    if ((uimm & 0xf) >= 8) {
      xt_pop_zreg();
    }
  }
  /* Col=AJ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_preg();
  }

  /* Col=BQ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 32 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 64 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_IMM0 &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 8 && a64.predType == A64_PRED_NO && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
