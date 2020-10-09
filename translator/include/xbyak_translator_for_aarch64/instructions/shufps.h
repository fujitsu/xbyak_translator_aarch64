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
void translateSHUFPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/09/17 22:21 */
  /* Col=S103*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=U103*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }

  /* Col=X103*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_ALL_ONE,
                              xa::ZReg(a64.dstIdx).s);
    if ((a64.uimm & 0x3) == 1) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
    if ((a64.uimm & 0x3) == 2) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
    }
    if ((a64.uimm & 0x3) == 3) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                12);
    }
  }
  /* Col=Y103*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc) / 4) == 0) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.dstIdx),
                                60);
    }
    if (((a64.uimm & 0xc) / 4) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.dstIdx).s);
    }
    if (((a64.uimm & 0xc) / 4) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_384.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.dstIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
    if (((a64.uimm & 0xc) / 4) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.dstIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
    }
  }
  /* Col=Z103*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    if (((a64.uimm & 0x30) / 16) == 0) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.srcIdx),
                                56);
    }
    if (((a64.uimm & 0x30) / 16) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
    }
    if (((a64.uimm & 0x30) / 16) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
    }
    if (((a64.uimm & 0x30) / 16) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
    }
  }
  /* Col=AA103*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc0) / 64) == 0) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                12);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.srcIdx),
                                52);
    }
    if (((a64.uimm & 0xc0) / 64) == 1) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_ALL_ONE.s, P_TMP_0.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                8);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                56);
    }
    if (((a64.uimm & 0xc0) / 64) == 2) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_MSB_256.s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                4);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                60);
    }
    if (((a64.uimm & 0xc0) / 64) == 3) {
      xa_->not_(P_TMP_0.b, P_ALL_ONE, P_ALL_ONE.b);
      xa_->zip1(P_TMP_0.s, P_TMP_0.s, P_ALL_ONE.s);
      xa_->zip1(P_TMP_0.s, P_MSB_256.s, P_TMP_0.s);
      xa_->mov(xa::ZReg(a64.zTmpIdx).s, P_TMP_0,
                                xa::ZReg(a64.srcIdx).s);
    }
  }

  /* Col=AS103*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    xa_->not_(P_TMP_0.b, P_ALL_ONE, P_MSB_384.b);
  }

  /* Col=AU103*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    xa_->mov(xa::ZRegB(a64.dstIdx), P_TMP_0,
                              xa::ZRegB(a64.zTmpIdx));
  }

  /* Col=AS103*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    xa_->not_(P_TMP_0.b, P_ALL_ONE, P_MSB_384.b);
  }

  /* Col=AU103*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    xa_->mov(xa::ZRegB(a64.dstIdx), P_TMP_0,
                              xa::ZRegB(a64.zTmpIdx));
  }

  /* Col=BC103*/
  if (false || (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.srcType == A64_OP_REG && true)) {
    xt_pop_zreg();
  }
}
