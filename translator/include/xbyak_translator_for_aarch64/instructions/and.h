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
/* 2020/04/07 14:19 */

void translateAND(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xed_uint64_t uimm = 0;

  /* Col=T119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=W119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=X119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AB119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && true)) {
    uimm = a64.operands[1].uimm;
  }
  /* Col=AD119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_IMM0 &&
                a64.operands[0].opWidth == 32 && true)) {
    if (std::numeric_limits<uint32_t>::max() < uimm &&
        uimm < ~uint64_t(0xFFFFFFFF)) {
      xt_msg_err(__FILE__, __LINE__, "Invalid uimm=" + std::to_string(uimm));
    }
    xa_->and_(xa::WReg(dstIdx), xa::WReg(dstIdx), static_cast<uint32_t>(uimm));
  }
  /* Col=AE119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_IMM0 &&
                a64.operands[0].opWidth == 64 && true)) {
    xed_uint64_t mask = ~uint64_t(0xffffffff);
    unsigned bits = (mask & uimm) ? 64 : 32;
    xed_int64_t tmp = xed_sign_extend_arbitrary_to_64(uimm, bits);
    xa_->mov_imm(X_TMP_1, tmp);
    xa_->and_(xa::XReg(dstIdx), xa::XReg(dstIdx), X_TMP_1);
  }
  /* Col=AG119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true)) {
    if (std::numeric_limits<uint32_t>::max() < uimm &&
        uimm < ~uint64_t(0xFFFFFFFF)) {
      xt_msg_err(__FILE__, __LINE__, "Invalid uimm=" + std::to_string(uimm));
    }
    xed_int64_t tmp = uint64_t(0xFFFFFFFFFFFFFF00);
    xa_->mov_imm(X_TMP_1, tmp);
    xa_->orr(X_TMP_1, X_TMP_1, static_cast<uint32_t>(uimm));
    xa_->and_(xa::XReg(dstIdx), xa::XReg(dstIdx), X_TMP_1);
  }
  /* Col=AH119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && true)) {
    xa_->ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true)) {
    xa_->ldr(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AL119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_IMM0 &&
                a64.operands[0].opWidth == 32 && true)) {
    if (std::numeric_limits<uint32_t>::max() < uimm &&
        uimm < ~uint64_t(0xFFFFFFFF)) {
      xt_msg_err(__FILE__, __LINE__, "Invalid uimm=" + std::to_string(uimm));
    }
    xa_->and_(W_TMP_0, W_TMP_0, static_cast<uint32_t>(uimm));
  }
  /* Col=AM119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_IMM0 &&
                a64.operands[0].opWidth == 64 && true)) {
    xa_->and_(X_TMP_0, X_TMP_0, uimm);
  }
  /* Col=AP119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 32 && true)) {
    xa_->and_(xa::WReg(dstIdx), xa::WReg(dstIdx), xa::WReg(srcIdx));
  }
  /* Col=AQ119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 64 && true)) {
    xa_->and_(xa::XReg(dstIdx), xa::XReg(dstIdx), xa::XReg(srcIdx));
  }
  /* Col=AU119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[0].opWidth == 32 && true)) {
    xa_->and_(W_TMP_0, W_TMP_0, xa::WReg(srcIdx));
  }
  /* Col=AV119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[0].opWidth == 64 && true)) {
    xa_->and_(X_TMP_0, X_TMP_0, xa::XReg(srcIdx));
  }
  /* Col=BB119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 32 && true)) {
    xa_->and_(xa::WReg(dstIdx), xa::WReg(dstIdx), W_TMP_0);
  }
  /* Col=BC119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 64 && true)) {
    xa_->and_(xa::XReg(dstIdx), xa::XReg(dstIdx), X_TMP_0);
  }
  /* Col=BE119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 32 && true)) {
    xa_->str(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=BF119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 64 && true)) {
    xa_->str(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=BK119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_IMM0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 64 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 64 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
