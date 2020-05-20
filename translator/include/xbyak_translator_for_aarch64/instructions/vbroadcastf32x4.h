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
void translateVBROADCASTF32X4(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/03/06 09:59 */
  /* Col=S103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
                a64.EVEXb == 1 && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=V103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 1 && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=W103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 1 && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ldr(xa::ZReg(a64.dstIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=Y103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 1 && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ptrue(xa::PRegD(a64.pTmpIdx), xa::VL2);
  }

  /* Col=AF103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 1 && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::splice(xa::ZRegD(a64.dstIdx), xa::PRegD(a64.pTmpIdx),
                                 xa::ZRegD(a64.dstIdx));
  }

  /* Col=AN103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 1 && a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_256 / xa::T_m, 0);
  }

  /* Col=AQ103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 1 && a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::ptrue(xa::PRegD(a64.pTmpIdx), xa::VL4);
  }

  /* Col=AS103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 1 && a64.srcType == A64_OP_MEM && true)) {
    CodeGeneratorAArch64::splice(xa::ZRegD(a64.dstIdx), xa::PRegD(a64.pTmpIdx),
                                 xa::ZRegD(a64.dstIdx));
  }

  /* Col=BB103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 1 && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.srcType == A64_OP_MEM && true)) {
    xt_pop_preg();
  }
}
