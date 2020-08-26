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
void translateMULPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);
  /* 2020/03/19 10:47 */
  bool isValid = false;
#define CG64 Xbyak_aarch64::CodeGenerator
  /* Col=S103*/
  if (false || (a64.srcType == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=T103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=U103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AB103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    CG64::mov(xa::PRegB(a64.pTmpIdx), P_MSB_384.b);
  }
  /* Col=AI103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    CG64::mov(xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.dstIdx));
  }
  /* Col=AP103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    CG64::fmul(xa::ZRegS(a64.dstIdx), xa::ZRegS(a64.dstIdx),
               xa::ZRegS(a64.srcIdx));
  }
  /* Col=AW103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    CG64::mov(xa::ZRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_m,
              xa::ZRegS(a64.zTmpIdx));
  }
  /* Col=BN103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    xt_pop_zreg();
  }
  /* Col=BO103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    xt_pop_preg();
  }
  /* Col=BP103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF
#undef CG64
}
