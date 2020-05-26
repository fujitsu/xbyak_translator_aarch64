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
void translateMOVSS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

/* 2020/02/21 22:24 */
#define CG64 CodeGeneratorAArch64

  /* Col=T103*/
  if (false ||
      (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }

  /* Col=W103*/
  if (false ||
      (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    CG64::ptrue(xa::PRegS(a64.pTmpIdx), xa::VL1);
  }
  /* Col=X103*/
  if (false ||
      (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::ptrue(xa::PRegS(a64.pTmpIdx), xa::VL4);
  }

  /* Col=AI103*/
  if (false ||
      (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }

  /* Col=AK103*/
  if (false ||
      (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::mov(xa::ZRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_m, 0);
  }

  /* Col=AM103*/
  if (false ||
      (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::ptrue(xa::PRegS(a64.pTmpIdx), xa::VL1);
  }

  /* Col=AQ103*/
  if (false ||
      (a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    CG64::st1w(xa::ZRegS(a64.srcIdx), xa::PReg(a64.pTmpIdx),
               xa::ptr(X_TMP_ADDR));
  }

  /* Col=AS103*/
  if (false ||
      (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    CG64::mov(xa::ZRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_m,
              xa::ZRegS(a64.srcIdx));
  }

  /* Col=AU103*/
  if (false ||
      (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::mov(xa::ZRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_m, W_TMP_0);
  }

  /* Col=AW103*/
  if (false ||
      (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    xt_pop_preg();
  }

#undef CG64
}
