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
void translateMOVDQA(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

/* 2020/03/06 20:33 */
#define CG64 CodeGeneratorAArch64

  /* Col=T103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=U103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=V103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    CG64::not_(P_TMP_0.b, P_ALL_ONE, P_MSB_384.b);
  }
  /* Col=W103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    CG64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, P_MSB_384.b);
  }
  /* Col=X103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    CG64::ld1b(xa::ZReg(a64.zTmpIdx).b, xa::PReg(a64.pTmpIdx) / xa::T_z,
               xa::ptr(X_TMP_ADDR));
  }
  /* Col=Y103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    CG64::mov(xa::ZRegB(a64.dstIdx), P_TMP_0 / xa::T_m, xa::ZRegB(a64.srcIdx));
  }

  /* Col=AA103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    CG64::mov(xa::ZRegB(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_m,
              xa::ZRegB(a64.zTmpIdx));
  }

  /* Col=AF103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_REG && true)) {
    CG64::str(xa::QReg(a64.srcIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AW103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    xt_pop_zreg();
  }
  /* Col=AX103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    xt_pop_preg();
  }

#undef CG64
}
