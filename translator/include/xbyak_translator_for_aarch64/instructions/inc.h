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
void translateINC(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/03/11 21:20 */
  bool isValid = false;

  /* Col=S103*/
  if (false || (a64.dstWidth == 8 && a64.dstType == A64_OP_REG && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_MEM && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=AA103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM && true)) {
    xa_->ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AB103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM && true)) {
    xa_->ldr(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }

  /* Col=AG103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG && true)) {
    xa_->add(xa::WReg(a64.dstIdx), xa::WReg(a64.dstIdx), 1);
  }
  /* Col=AH103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM && true)) {
    xa_->add(W_TMP_0, W_TMP_0, 1);
  }
  /* Col=AI103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG && true)) {
    xa_->add(xa::XReg(a64.dstIdx), xa::XReg(a64.dstIdx), 1);
  }
  /* Col=AJ103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM && true)) {
    xa_->add(X_TMP_0, X_TMP_0, 1);
  }

  /* Col=AN103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM && true)) {
    xa_->str(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AO103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM && true)) {
    xa_->str(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }

  /* Col=BC103*/
  if (false || (a64.dstWidth == 8 && a64.dstType == A64_OP_REG && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_MEM && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF
}
