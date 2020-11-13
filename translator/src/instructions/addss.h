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
void Xbyak::CodeGenerator::translateADDSS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/03/26 15:59 */
  bool isValid = false;

  /* Col=T143*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=U143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_MEM && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=W143*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    xa_->not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, P_ALL_ONE.b);
  }
  /* Col=X143*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    xa_->zip1(xa::PRegS(a64.pTmpIdx), P_ALL_ONE.s, xa::PRegS(a64.pTmpIdx));
  }
  /* Col=Y143*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    xa_->zip1(xa::PRegS(a64.pTmpIdx), xa::PRegS(a64.pTmpIdx), P_MSB_256.s);
  }
  /* Col=Z143*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    xa_->zip1(xa::PRegS(a64.pTmpIdx), xa::PRegS(a64.pTmpIdx), P_MSB_256.s);
  }
  /* Col=AA143*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    xa_->zip1(xa::PRegS(a64.pTmpIdx), xa::PRegS(a64.pTmpIdx), P_MSB_256.s);
  }

  /* Col=AG143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_MEM && true)) {
    xa_->ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AM143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    xa_->fadd(xa::ZRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx),
              xa::ZRegS(a64.srcIdx));
  }
  /* Col=AO143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_MEM && true)) {
    xa_->fadd(xa::ZRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx),
              xa::ZRegS(a64.zTmpIdx));
  }

  /* Col=AW143*/
  if (false || (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_MEM && true)) {
    xt_pop_zreg();
  }
  /* Col=AX143*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    xt_pop_preg();
  }

  /* Col=BP143*/
  if (false ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.srcType == A64_OP_MEM && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
