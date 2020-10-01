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
void translateMOVHLPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/09/17 15:35 */
  bool isValid = false;
#define CG64 CodeGeneratorAArch64

  /* Col=U143*/
  if (false || (a64.dstWidth == 64 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=Y143*/
  if (false || (a64.dstWidth == 64 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::uzp1(P_TMP_0.d, P_MSB_384.d, P_ALL_ONE.d);
  }
  /* Col=Z143*/
  if (false || (a64.dstWidth == 64 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::not_(P_TMP_0.b, P_ALL_ONE, P_TMP_0.b);
  }
  /* Col=AB143*/
  if (false || (a64.dstWidth == 64 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::ZRegB(a64.zTmpIdx), P_ALL_ONE,
                              xa::ZRegB(a64.srcIdx));
  }
  /* Col=AD143*/
  if (false || (a64.dstWidth == 64 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                              8);
  }
  /* Col=AF143*/
  if (false || (a64.dstWidth == 64 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::ZRegB(a64.dstIdx), P_TMP_0,
                              xa::ZRegB(a64.zTmpIdx));
  }
  /* Col=AW143*/
  if (false || (a64.dstWidth == 64 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    xt_pop_zreg();
  }
  /* Col=BP143*/
  if (false || (a64.dstWidth == 64 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
