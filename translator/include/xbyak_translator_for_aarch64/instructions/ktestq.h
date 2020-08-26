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
/* 2020/05/01 15:37 */

void translateKTESTQ(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  xa::Label L_zflag, L_cflag;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t src2Idx = XT_REG_INVALID;

  /* Col=AH120*/
  if (false || (true)) {
    srcIdx = a64.operands[0].regIdx;
  }
  /* Col=AI120*/
  if (false || (true)) {
    src2Idx = a64.operands[1].regIdx;
  }

  /* Col=AR120*/
  if (false || (true)) {
    xa_->and_(P_TMP.b, P_ALL_ONE / xa::T_z, xa::PRegB(src2Idx),
               xa::PRegB(srcIdx));
  }
  /* Col=AS120*/
  if (false || (true)) {
    xa_->cntp(X_TMP_0, P_ALL_ONE, P_TMP.b);
  }
  /* Col=AT120*/
  if (false || (true)) {
    xa_->cmp(X_TMP_0, 0);
  }
  /* Col=AU120*/
  if (false || (true)) {
    xa_->mov(X_TMP_0, 0);
  }
  /* Col=AV120*/
  if (false || (true)) {
    xa_->b(xa::NE, L_zflag);
  }
  /* Col=AW120*/
  if (false || (true)) {
    xa_->mov(W_TMP_0, uint32_t(1) << 30);
  }
  /* Col=AX120*/
  if (false || (true)) {
    L_aarch64(L_zflag);
  }
  /* Col=BA120*/
  if (false || (true)) {
    xa_->mrs(X_TMP_2, 0x3, 0x3, 0x4, 0x2, 0x0); // Read NZCV register
  }

  /* Col=BB120*/
  if (false || (true)) {
    xa_->bic(P_TMP.b, P_ALL_ONE / xa::T_z, xa::PRegB(src2Idx),
              xa::PRegB(srcIdx));
  }
  /* Col=BC120*/
  if (false || (true)) {
    xa_->cntp(X_TMP_1, P_ALL_ONE, P_TMP.b);
  }
  /* Col=BD120*/
  if (false || (true)) {
    xa_->cmp(X_TMP_1, 0);
  }
  /* Col=BE120*/
  if (false || (true)) {
    xa_->b(xa::NE, L_cflag);
  }
  /* Col=BF120*/
  if (false || (true)) {
    xa_->orr(W_TMP_0, W_TMP_0, uint32_t(1) << 29);
  }
  /* Col=BG120*/
  if (false || (true)) {
    L_aarch64(L_cflag);
  }
  /* Col=BJ120*/
  if (false || (true)) {
    xa_->and_(W_TMP_2, W_TMP_2, ~(uint32_t(0xf) << 28));
  }
  /* Col=BK120*/
  if (false || (true)) {
    xa_->orr(W_TMP_2, W_TMP_2, W_TMP_0);
  }

  /* Col=BL120*/
  if (false || (true)) {
    xa_->msr(0x3, 0x3, 0x4, 0x2, 0x0, X_TMP_2); // Write NZCV register
  }
  /* Col=BU120*/
  if (false || (true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}

