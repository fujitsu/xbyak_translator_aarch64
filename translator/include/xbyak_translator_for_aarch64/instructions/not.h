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
void translateNOT(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

/* 2020/02/26 23:20 */
#define CG64 CodeGeneratorAArch64
  /* Col=S103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 8 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 16 && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=W103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 32 && true)) {
    CG64::ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=X103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 64 && true)) {
    CG64::ldr(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }

  /* Col=Z103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[0].opWidth == 32 && true)) {
    CG64::mvn(xa::WReg(a64.operands[0].regIdx),
              xa::WReg(a64.operands[0].regIdx));
  }
  /* Col=AA103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[0].opWidth == 64 && true)) {
    CG64::mvn(xa::XReg(a64.operands[0].regIdx),
              xa::XReg(a64.operands[0].regIdx));
  }
  /* Col=AB103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 32 && true)) {
    CG64::mvn(W_TMP_0, W_TMP_0);
  }
  /* Col=AC103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 64 && true)) {
    CG64::mvn(X_TMP_0, X_TMP_0);
  }
  /* Col=AD103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 32 && true)) {
    CG64::str(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AE103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 64 && true)) {
    CG64::str(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }

#undef CG64
}
