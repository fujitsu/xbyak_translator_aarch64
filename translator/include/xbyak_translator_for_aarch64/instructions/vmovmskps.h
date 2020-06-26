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
/* 2020/06/11 15:56 */
#define CG64 CodeGeneratorAArch64
void translateVMOVMSKPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;

  /* Col=Y119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=AA119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AH119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AK119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AN119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    CG64::movs(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=AP119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    CG64::dup(xa::ZRegS(zTmpIdx), 0);
  }
  /* Col=AR119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    CG64::cmplt(P_TMP_0.s, xa::PReg(pTmpIdx) / xa::T_z, xa::ZReg(srcIdx).s,
                xa::ZReg(zTmpIdx).s);
  }
  /* Col=AT119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    CG64::sub(X_TRANSLATOR_STACK, X_TRANSLATOR_STACK, 8);
  }
  /* Col=AU119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    CG64::str(P_TMP_0, xa::ptr(X_TRANSLATOR_STACK));
  }
  /* Col=AV119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    CG64::ldr(X_TMP_0, xa::ptr(X_TRANSLATOR_STACK));
  }
  /* Col=AW119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    CG64::add(X_TRANSLATOR_STACK, X_TRANSLATOR_STACK, 8);
  }
  /* Col=AY119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    CG64::mov(xa::XReg(dstIdx), 0);
  }
  /* Col=AZ119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true)) {
    for (int i = 0; i < 4; i++) {
      CG64::and_(X_TMP_1, X_TMP_0, uint64_t(1) << (4 * i));
      CG64::lsr(X_TMP_1, X_TMP_1, 3 * i);
      CG64::orr(xa::XReg(dstIdx), xa::XReg(dstIdx), X_TMP_1);
    }
  }
  /* Col=BA119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    for (int i = 0; i < 8; i++) {
      CG64::and_(X_TMP_1, X_TMP_0, uint64_t(1) << (4 * i));
      CG64::lsr(X_TMP_1, X_TMP_1, 3 * i);
      CG64::orr(xa::XReg(dstIdx), xa::XReg(dstIdx), X_TMP_1);
    }
  }
  /* Col=BB119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true)) {
    CG64::and_(xa::XReg(dstIdx), xa::XReg(dstIdx), 15);
  }
  /* Col=BC119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    CG64::and_(xa::XReg(dstIdx), xa::XReg(dstIdx), 255);
  }
  /* Col=BM119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    xt_pop_zreg();
  }
  /* Col=BN119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    xt_pop_preg();
  }
  /* Col=BO119*/
  if (false || (a64.operands[1].regClass == XED_REG_CLASS_XMM && true) ||
      (a64.operands[1].regClass == XED_REG_CLASS_YMM && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
