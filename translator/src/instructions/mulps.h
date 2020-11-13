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
void Xbyak::CodeGenerator::translateMULPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);
  /* 2020/09/17 21:30 */
  bool isValid = false;

  /* Col=S103*/
  if (false || (a64.srcType == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=U103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }

  /* Col=AI103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    xa_->mov(xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.dstIdx));
  }

  /* Col=AP103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    xa_->fmul(xa::ZRegS(a64.dstIdx), xa::ZRegS(a64.dstIdx),
              xa::ZRegS(a64.srcIdx));
  }

  /* Col=AW103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    xa_->mov(xa::ZRegS(a64.dstIdx), P_MSB_384 / xa::T_m,
             xa::ZRegS(a64.zTmpIdx));
  }

  /* Col=BN103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    xt_pop_zreg();
  }

  /* Col=BP103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF
}
