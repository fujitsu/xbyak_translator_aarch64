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
/* 2020/06/29 16:31 */

void translateVMOVMSKPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;

  /* Col=AE119*/
  if (false ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_XMM &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       isAvailAll1Preg0_7() == true && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }

  /* Col=AL119*/
  if (false ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_XMM &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       isAvailAll1Preg0_7() == true && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AO119*/
  if (false ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_XMM &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       isAvailAll1Preg0_7() == true && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AT119*/
  if (false ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_XMM &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->dup(xa::ZRegS(zTmpIdx), 0);
  }

  /* Col=AV119*/
  if (false ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_XMM &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->cmplt(P_TMP_0.s, P_ALL_ONE_0_7 / xa::T_z, xa::ZReg(srcIdx).s,
               xa::ZReg(zTmpIdx).s);
  }
  /* Col=AX119*/
  if (false ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_XMM &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->sub(X_TRANSLATOR_STACK, X_TRANSLATOR_STACK, 8);
  }
  /* Col=AY119*/
  if (false ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_XMM &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->str(P_TMP_0, xa::ptr(X_TRANSLATOR_STACK));
  }
  /* Col=AZ119*/
  if (false ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_XMM &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->ldr(X_TMP_0, xa::ptr(X_TRANSLATOR_STACK));
  }
  /* Col=BA119*/
  if (false ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_XMM &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->add(X_TRANSLATOR_STACK, X_TRANSLATOR_STACK, 8);
  }
  /* Col=BC119*/
  if (false ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_XMM &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::XReg(dstIdx), 0);
  }
  /* Col=BD119*/
  if (false || (a64_opt.operands[1].regClass == XED_REG_CLASS_XMM &&
                isAvailAll1Preg0_7() == true && true)) {
    for (int i = 0; i < 4; i++) {
      xa_->and_(X_TMP_1, X_TMP_0, uint64_t(1) << (4 * i));
      xa_->lsr(X_TMP_1, X_TMP_1, 3 * i);
      xa_->orr(xa::XReg(dstIdx), xa::XReg(dstIdx), X_TMP_1);
    }
  }
  /* Col=BE119*/
  if (false || (a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
                isAvailAll1Preg0_7() == true && true)) {
    for (int i = 0; i < 8; i++) {
      xa_->and_(X_TMP_1, X_TMP_0, uint64_t(1) << (4 * i));
      xa_->lsr(X_TMP_1, X_TMP_1, 3 * i);
      xa_->orr(xa::XReg(dstIdx), xa::XReg(dstIdx), X_TMP_1);
    }
  }

  /* Col=BF119*/
  if (false || (a64_opt.operands[1].regClass == XED_REG_CLASS_XMM &&
                isAvailAll1Preg0_7() == true && true)) {
    xa_->and_(xa::XReg(dstIdx), xa::XReg(dstIdx), 15);
  }
  /* Col=BG119*/
  if (false || (a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
                isAvailAll1Preg0_7() == true && true)) {
    xa_->and_(xa::XReg(dstIdx), xa::XReg(dstIdx), 255);
  }

  /* Col=BQ119*/
  if (false ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_XMM &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       isAvailAll1Preg0_7() == true && true)) {
    xt_pop_zreg();
  }
  /* Col=BY119*/
  if (false ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_XMM &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[1].regClass == XED_REG_CLASS_YMM &&
       isAvailAll1Preg0_7() == true && true)) {
    return;
  }

  /* Col=U119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=W119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }

  /* Col=AD119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AG119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AJ119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->movs(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=AL119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->dup(xa::ZRegS(zTmpIdx), 0);
  }

  /* Col=AN119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->cmplt(P_TMP_0.s, xa::PReg(pTmpIdx) / xa::T_z, xa::ZReg(srcIdx).s,
               xa::ZReg(zTmpIdx).s);
  }
  /* Col=AP119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->sub(X_TRANSLATOR_STACK, X_TRANSLATOR_STACK, 8);
  }
  /* Col=AQ119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->str(P_TMP_0, xa::ptr(X_TRANSLATOR_STACK));
  }
  /* Col=AR119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->ldr(X_TMP_0, xa::ptr(X_TRANSLATOR_STACK));
  }
  /* Col=AS119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->add(X_TRANSLATOR_STACK, X_TRANSLATOR_STACK, 8);
  }
  /* Col=AU119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->mov(xa::XReg(dstIdx), 0);
  }
  /* Col=AV119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true)) {
    for (int i = 0; i < 4; i++) {
      xa_->and_(X_TMP_1, X_TMP_0, uint64_t(1) << (4 * i));
      xa_->lsr(X_TMP_1, X_TMP_1, 3 * i);
      xa_->orr(xa::XReg(dstIdx), xa::XReg(dstIdx), X_TMP_1);
    }
  }
  /* Col=AW119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    for (int i = 0; i < 8; i++) {
      xa_->and_(X_TMP_1, X_TMP_0, uint64_t(1) << (4 * i));
      xa_->lsr(X_TMP_1, X_TMP_1, 3 * i);
      xa_->orr(xa::XReg(dstIdx), xa::XReg(dstIdx), X_TMP_1);
    }
  }

  /* Col=AX119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true)) {
    xa_->and_(xa::XReg(dstIdx), xa::XReg(dstIdx), 15);
  }
  /* Col=AY119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    xa_->and_(xa::XReg(dstIdx), xa::XReg(dstIdx), 255);
  }

  /* Col=BI119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    xt_pop_zreg();
  }
  /* Col=BJ119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    xt_pop_preg();
  }
  /* Col=BQ119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
