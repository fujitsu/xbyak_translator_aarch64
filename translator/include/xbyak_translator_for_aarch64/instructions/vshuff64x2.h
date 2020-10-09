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
void translateVSHUFF64X2(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/09/29 14:34 */
  bool isValid = false;


  /* Col=S143*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=V143*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=W143*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=X143*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    xa_->ptrue(xa::PRegD(a64.pTmpIdx), xa::VL2);
  }
  /* Col=Y143*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 0) {
      xa_->mov(xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.srcIdx));
      xa_->splice(xa::ZRegD(a64.zTmpIdx),
                                   xa::PRegD(a64.pTmpIdx),
                                   xa::ZRegD(a64.src2Idx));
      xa_->mov(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.zTmpIdx));
    }
  }
  /* Col=Z143*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 1) {
      xa_->uzp1(xa::ZReg(a64.zTmpIdx).d,
                                 xa::ZReg(a64.srcIdx).d,
                                 xa::ZReg(a64.srcIdx).d);
      xa_->sel(xa::ZRegD(a64.zTmpIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.srcIdx));
      xa_->uzp2(xa::ZReg(a64.zTmpIdx).d,
                                 xa::ZReg(a64.zTmpIdx).d,
                                 xa::ZReg(a64.zTmpIdx).d);
      xa_->splice(xa::ZRegD(a64.zTmpIdx),
                                   xa::PRegD(a64.pTmpIdx),
                                   xa::ZRegD(a64.src2Idx));
      xa_->mov(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.zTmpIdx));
    }
  }
  /* Col=AA143*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 2) {
      xa_->sel(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegD(a64.srcIdx), xa::ZRegD(a64.src2Idx));
    }
  }
  /* Col=AB143*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 3) {
      xa_->uzp1(xa::ZReg(a64.zTmpIdx).d,
                                 xa::ZReg(a64.srcIdx).d,
                                 xa::ZReg(a64.srcIdx).d);
      xa_->sel(xa::ZRegD(a64.zTmpIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.srcIdx));
      xa_->uzp2(xa::ZReg(a64.zTmpIdx).d,
                                 xa::ZReg(a64.zTmpIdx).d,
                                 xa::ZReg(a64.zTmpIdx).d);
      xa_->sel(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.src2Idx));
    }
  }
  /* Col=AC143*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    xa_->mov(xa::ZReg(a64.dstIdx).s, P_MSB_256 / xa::T_m, 0);
  }
  /* Col=AF143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    xa_->mov(xa::ZReg(a64.zTmpIdx).d, P_ALL_ONE,
                              xa::ZReg(a64.srcIdx).d);
  }
  /* Col=AG143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 1) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                16);
    }
  }
  /* Col=AH143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 2) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                32);
    }
  }
  /* Col=AI143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 3) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                48);
    }
  }
  /* Col=AJ143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc) / 4) == 0) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                16);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.srcIdx),
                                48);
    }
  }
  /* Col=AK143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc) / 4) == 1) {
      xa_->mov(xa::ZReg(a64.zTmpIdx).d, P_MSB_384,
                                xa::ZReg(a64.srcIdx).d);
    }
  }
  /* Col=AL143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc) / 4) == 2) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                48);
      xa_->mov(xa::ZReg(a64.zTmpIdx).d, P_MSB_256,
                                xa::ZReg(a64.srcIdx).d);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                16);
    }
  }
  /* Col=AM143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc) / 4) == 3) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                32);
      xa_->trn1(P_TMP_0.d, xa::PRegD(12), P_MSB_256.d);
      xa_->uzp2(P_TMP_0.d, P_TMP_0.d, P_TMP_0.d);
      xa_->and_(P_TMP_0.b, P_MSB_256, P_TMP_0.b, P_MSB_256.b);
      xa_->mov(xa::ZReg(a64.zTmpIdx).d, P_TMP_0.b,
                                xa::ZReg(a64.srcIdx).d);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                32);
    }
  }
  /* Col=AN143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x30) / 16) == 0) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                32);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.src2Idx),
                                32);
    }
  }
  /* Col=AO143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x30) / 16) == 1) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                16);
      xa_->eor(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_MSB_384.b);
      xa_->mov(xa::ZReg(a64.zTmpIdx).d, P_TMP_0,
                                xa::ZReg(a64.src2Idx).d);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                48);
    }
  }
  /* Col=AP143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x30) / 16) == 2) {
      xa_->mov(xa::ZReg(a64.zTmpIdx).d, P_MSB_256,
                                xa::ZReg(a64.src2Idx).d);
    }
  }
  /* Col=AQ143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x30) / 16) == 3) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                48);
      xa_->trn1(P_TMP_0.d, xa::PRegD(12), P_MSB_256.d);
      xa_->uzp2(P_TMP_0.d, P_TMP_0.d, P_TMP_0.d);
      xa_->and_(P_TMP_0.b, P_MSB_256, P_TMP_0.b, P_MSB_256.b);
      xa_->mov(xa::ZReg(a64.zTmpIdx).d, P_TMP_0,
                                xa::ZReg(a64.src2Idx).d);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                16);
    }
  }
  /* Col=AR143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc0) / 64) == 0) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                48);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.src2Idx),
                                16);
    }
  }
  /* Col=AS143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc0) / 64) == 1) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                32);
      xa_->eor(P_TMP_0.b, P_ALL_ONE, P_MSB_256.b, P_MSB_384.b);
      xa_->mov(xa::ZReg(a64.zTmpIdx).d, P_TMP_0,
                                xa::ZReg(a64.src2Idx).d);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                32);
    }
  }
  /* Col=AT143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc0) / 64) == 2) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                16);
      xa_->trn1(P_TMP_0.d, xa::PRegD(12), P_MSB_256.d);
      xa_->uzp2(P_TMP_0.d, P_TMP_0.d, P_TMP_0.d);
      xa_->and_(P_TMP_0.b, P_MSB_256, P_TMP_0.b, P_MSB_256.b);
      xa_->eor(P_TMP_0.b, P_ALL_ONE, P_TMP_0.b, P_MSB_256.b);
      xa_->mov(xa::ZReg(a64.zTmpIdx).d, P_TMP_0,
                                xa::ZReg(a64.src2Idx).d);
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                48);
    }
  }
  /* Col=AU143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc0) / 64) == 3) {
      xa_->trn1(P_TMP_0.d, xa::PRegD(12), P_MSB_256.d);
      xa_->uzp2(P_TMP_0.d, P_TMP_0.d, P_TMP_0.d);
      xa_->and_(P_TMP_0.b, P_MSB_256, P_TMP_0.b, P_MSB_256.b);
      xa_->mov(xa::ZReg(a64.zTmpIdx).d, P_TMP_0,
                                xa::ZReg(a64.src2Idx).d);
    }
  }
  /* Col=AV143*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    xa_->mov(xa::ZReg(a64.dstIdx).d, P_ALL_ONE,
                              xa::ZReg(a64.zTmpIdx).d);
  }
  /* Col=BD143*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    xt_pop_preg();
  }
  /* Col=BE143*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    xt_pop_zreg();
  }

  /* Col=BP143*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG && a64.EVEXb == 1 &&
       a64.src2Type == A64_OP_MEM && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}

