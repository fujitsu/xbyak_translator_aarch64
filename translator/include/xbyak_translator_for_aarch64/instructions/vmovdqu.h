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
void translateVMOVDQU(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/13 19:37 */

  /* Col=W103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::VReg16B(a64.dstIdx), xa::VReg16B(a64.srcIdx));
  }

  /* Col=AC103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldr(xa::QReg(a64.dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AD103*/
  if (false || (a64.dstWidth == 128 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::str(xa::QReg(a64.srcIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AH103*/
  if (false ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=AI103*/
  if (false || (a64.dstWidth == 256 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::movs(xa::PRegB(a64.pTmpIdx), P_MSB_256.b);
  }
  /* Col=AJ103*/
  if (false ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, P_MSB_256.b);
  }
  /* Col=AK103*/
  if (false || (a64.dstWidth == 256 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.srcIdx));
  }
  /* Col=AL103*/
  if (false || (a64.dstWidth == 256 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).b,
                              xa::PReg(a64.pTmpIdx) / xa::T_m, 0);
  }

  /* Col=AN103*/
  if (false || (a64.dstWidth == 256 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ld1b(xa::ZReg(a64.dstIdx).b,
                               xa::PReg(a64.pTmpIdx) / xa::T_z,
                               xa::ptr(X_TMP_ADDR));
  }
  /* Col=AO103*/
  if (false || (a64.dstWidth == 256 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::st1b(xa::ZReg(a64.srcIdx).b,
                               xa::PReg(a64.pTmpIdx) / xa::T_z,
                               xa::ptr(X_TMP_ADDR));
  }

  /* Col=AQ103*/
  if (false ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true)) {
    xt_pop_preg();
  }
}
