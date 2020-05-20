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
void translateVPCMPB(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/03/23 22:48 */
  /* Col=S103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
                a64.srcWidth == 128 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 128 && a64.uimm == A64_CMP_NLE && true)) {
    XT_UNIMPLEMENTED;
  }

  /* 2020/03/23 22:48 */
  /* Col=S103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
                a64.srcWidth == 256 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 256 && a64.uimm == A64_CMP_NLE && true)) {
    XT_UNIMPLEMENTED;
  }

  /* 2020/03/09 11:08 */
  /* Col=S103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=U103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=V103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true)) {
    CodeGeneratorAArch64::mov(xa::PRegB(a64.pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=W103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=X103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true)) {
    CodeGeneratorAArch64::ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=Y103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true)) {
    CodeGeneratorAArch64::cmpeq(xa::PRegB(a64.dstIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.src2Idx));
  }
  /* Col=Z103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true)) {
    CodeGeneratorAArch64::cmplt(xa::PRegB(a64.dstIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.src2Idx));
  }
  /* Col=AA103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true)) {
    CodeGeneratorAArch64::cmple(xa::PRegB(a64.dstIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.src2Idx));
  }
  /* Col=AB103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true)) {
    CodeGeneratorAArch64::cmpne(xa::PRegB(a64.dstIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.src2Idx));
  }
  /* Col=AC103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true)) {
    CodeGeneratorAArch64::cmpeq(xa::PRegB(a64.dstIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.zTmpIdx));
  }
  /* Col=AD103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true)) {
    CodeGeneratorAArch64::cmplt(xa::PRegB(a64.dstIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.zTmpIdx));
  }
  /* Col=AE103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true)) {
    CodeGeneratorAArch64::cmple(xa::PRegB(a64.dstIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.zTmpIdx));
  }
  /* Col=AF103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true)) {
    CodeGeneratorAArch64::cmpne(xa::PRegB(a64.dstIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.zTmpIdx));
  }
  /* Col=AG103*/
  if (false || (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true)) {
    CodeGeneratorAArch64::cmpeq(xa::PRegB(a64.dstIdx), xa::PRegB(a64.mask2Idx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.src2Idx));
  }
  /* Col=AH103*/
  if (false || (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true)) {
    CodeGeneratorAArch64::cmplt(xa::PRegB(a64.dstIdx), xa::PRegB(a64.mask2Idx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.src2Idx));
  }
  /* Col=AI103*/
  if (false || (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true)) {
    CodeGeneratorAArch64::cmple(xa::PRegB(a64.dstIdx), xa::PRegB(a64.mask2Idx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.src2Idx));
  }
  /* Col=AJ103*/
  if (false || (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true)) {
    CodeGeneratorAArch64::cmpne(xa::PRegB(a64.dstIdx), xa::PRegB(a64.mask2Idx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.src2Idx));
  }
  /* Col=AK103*/
  if (false || (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true)) {
    CodeGeneratorAArch64::cmpeq(xa::PRegB(a64.dstIdx), xa::PRegB(a64.mask2Idx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.zTmpIdx));
  }
  /* Col=AL103*/
  if (false || (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true)) {
    CodeGeneratorAArch64::cmplt(xa::PRegB(a64.dstIdx), xa::PRegB(a64.mask2Idx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.zTmpIdx));
  }
  /* Col=AM103*/
  if (false || (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true)) {
    CodeGeneratorAArch64::cmple(xa::PRegB(a64.dstIdx), xa::PRegB(a64.mask2Idx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.zTmpIdx));
  }
  /* Col=AN103*/
  if (false || (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true)) {
    CodeGeneratorAArch64::cmpne(xa::PRegB(a64.dstIdx), xa::PRegB(a64.mask2Idx),
                                xa::ZRegB(a64.srcIdx), xa::ZRegB(a64.zTmpIdx));
  }

  /* Col=AR103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true)) {
    xt_pop_preg();
  }
  /* Col=AS103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_EQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_LE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NEQ && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true)) {
    xt_pop_zreg();
  }
  /* Col=AT103*/
  if (false || (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
                a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_NO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_REG &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLT && true) ||
      (a64.PredType == A64_PRED_ZERO && a64.src2Type == A64_OP_MEM &&
       a64.srcWidth == 512 && a64.uimm == A64_CMP_NLE && true)) {
    CodeGeneratorAArch64::not_(xa::PRegB(a64.dstIdx), P_ALL_ONE,
                               xa::PRegB(a64.dstIdx));
  }
}
