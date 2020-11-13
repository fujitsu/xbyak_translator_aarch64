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
void translateCMP(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/21 19:26 */
  /* Col=S103*/
  if (false ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=T103*/
  if (false ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true)) {
    uint32_t uimm32 = static_cast<uint32_t>(a64.uimm & uint64_t(0xFFFFFFFF));
    xa_->mov_imm(W_TMP_0, uimm32);
  }
  /* Col=U103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true)) {
    xa_->mov_imm(X_TMP_0, a64.uimm);
  }

  /* Col=Y103*/
  if (false ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    xa_->ldr(W_TMP_2, xa::ptr(X_TMP_ADDR));
  }
  /* Col=Z103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    xa_->ldr(X_TMP_2, xa::ptr(X_TMP_ADDR));
  }

  /* Col=AQ103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_IMM && true)) {
    xa_->cmp(xa::WReg(a64.dstIdx), W_TMP_0);
  }
  /* Col=AR103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_IMM && true)) {
    xa_->cmp(xa::XReg(a64.dstIdx), X_TMP_0);
  }
  /* Col=AS103*/
  if (false ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    xa_->cmp(W_TMP_2, W_TMP_0);
  }
  /* Col=AT103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    xa_->cmp(X_TMP_2, X_TMP_0);
  }
  /* Col=AU103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    xa_->cmp(xa::WReg(a64.dstIdx), xa::WReg(a64.srcIdx));
  }
  /* Col=AV103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    xa_->cmp(xa::XReg(a64.dstIdx), xa::XReg(a64.srcIdx));
  }
  /* Col=AW103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    xa_->cmp(xa::WReg(a64.dstIdx), W_TMP_2);
  }
  /* Col=AX103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    xa_->cmp(xa::XReg(a64.dstIdx), X_TMP_2);
  }
  /* Col=AY103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_REG && true)) {
    xa_->cmp(W_TMP_2, xa::WReg(a64.srcIdx));
  }
  /* Col=AZ103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_REG && true)) {
    xa_->cmp(X_TMP_2, xa::XReg(a64.srcIdx));
  }
}
