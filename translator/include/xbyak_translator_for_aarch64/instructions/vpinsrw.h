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
void translateVPINSRW(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/17 14:22 */

  /* Col=V103*/
  if (false || (a64.src2Type == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }

  /* Col=X103*/
  if (false || (a64.src2Type == A64_OP_REG && true) ||
      (a64.src2Type == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::mov(xa::VReg(a64.dstIdx).b16,
                              xa::VReg(a64.srcIdx).b16);
  }

  /* Col=Z103*/
  if (false || (a64.src2Type == A64_OP_REG && true)) {
    CodeGeneratorAArch64::ins_(xa::VReg8H(a64.dstIdx)[a64.uimm],
                               xa::WReg(a64.src2Idx));
  }
  /* Col=AA103*/
  if (false || (a64.src2Type == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ins_(xa::VReg8H(a64.dstIdx)[a64.uimm], W_TMP_0);
  }
}
