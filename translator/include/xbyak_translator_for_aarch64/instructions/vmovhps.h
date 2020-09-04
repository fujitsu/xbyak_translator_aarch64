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
void translateVMOVHPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/20 11:08 */

  /* Col=U103*/
  if (false || (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
                a64.src2Type == A64_OP_MEM && true)) {
    xa_->ldr(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }

  /* Col=Y103*/
  if (false || (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
                a64.src2Type == A64_OP_MEM && true)) {
    xa_->mov(xa::VReg2D(a64.dstIdx)[0],
                              xa::VReg2D(a64.srcIdx)[0]);
  }

  /* Col=AH103*/
  if (false || (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
                a64.src2Type == A64_OP_MEM && true)) {
    xa_->mov(xa::VReg2D(a64.dstIdx)[1], X_TMP_0);
  }

  /* Col=AJ103*/
  if (false || (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG &&
                a64.src2Type == A64_OP_MEM && true)) {
    xa_->mov(xa::ZReg(a64.dstIdx).s, P_MSB_384 / xa::T_m, 0);
  }

  /* Col=AP103*/
  if (false ||
      (a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    xa_->st1(xa::VReg2D(a64.srcIdx)[1], xa::ptr(X_TMP_ADDR));
  }
}
