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
void translateVMOVD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/21 14:56 */

  /* Col=V103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    xa_->bic(xa::VReg(a64.dstIdx).s4, 0);
  }

  /* Col=Z103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    xa_->fmov(xa::SReg(a64.dstIdx), xa::WReg(a64.srcIdx));
  }
  /* Col=AA103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    xa_->fmov(xa::WReg(a64.dstIdx), xa::SReg(a64.srcIdx));
  }

  /* Col=AC103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    xa_->ldr(xa::SReg(a64.dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AD103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_REG && true)) {
    xa_->str(xa::SReg(a64.srcIdx), xa::ptr(X_TMP_ADDR));
  }
}
