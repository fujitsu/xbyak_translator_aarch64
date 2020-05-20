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
void translateVSHUFF32X4(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/03/12 10:09 */
  /* Col=S103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_MEM && true) ||
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
  /* Col=T103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=U103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=V103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    CodeGeneratorAArch64::ptrue(xa::PRegD(a64.pTmpIdx), xa::VL2);
  }
  /* Col=W103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 0) {
      CodeGeneratorAArch64::mov(xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.srcIdx));
      CodeGeneratorAArch64::splice(xa::ZRegD(a64.zTmpIdx),
                                   xa::PRegD(a64.pTmpIdx),
                                   xa::ZRegD(a64.src2Idx));
      CodeGeneratorAArch64::mov(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.zTmpIdx));
    }
  }
  /* Col=X103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 1) {
      CodeGeneratorAArch64::uzp1(xa::ZReg(a64.zTmpIdx).d,
                                 xa::ZReg(a64.srcIdx).d,
                                 xa::ZReg(a64.srcIdx).d);
      CodeGeneratorAArch64::sel(xa::ZRegD(a64.zTmpIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.srcIdx));
      CodeGeneratorAArch64::uzp2(xa::ZReg(a64.zTmpIdx).d,
                                 xa::ZReg(a64.zTmpIdx).d,
                                 xa::ZReg(a64.zTmpIdx).d);
      CodeGeneratorAArch64::splice(xa::ZRegD(a64.zTmpIdx),
                                   xa::PRegD(a64.pTmpIdx),
                                   xa::ZRegD(a64.src2Idx));
      CodeGeneratorAArch64::mov(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.zTmpIdx));
    }
  }
  /* Col=Y103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 2) {
      CodeGeneratorAArch64::sel(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegD(a64.srcIdx), xa::ZRegD(a64.src2Idx));
    }
  }
  /* Col=Z103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 3) {
      CodeGeneratorAArch64::uzp1(xa::ZReg(a64.zTmpIdx).d,
                                 xa::ZReg(a64.srcIdx).d,
                                 xa::ZReg(a64.srcIdx).d);
      CodeGeneratorAArch64::sel(xa::ZRegD(a64.zTmpIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.srcIdx));
      CodeGeneratorAArch64::uzp2(xa::ZReg(a64.zTmpIdx).d,
                                 xa::ZReg(a64.zTmpIdx).d,
                                 xa::ZReg(a64.zTmpIdx).d);
      CodeGeneratorAArch64::sel(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx),
                                xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.src2Idx));
    }
  }
  /* Col=AA103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).s, P_MSB_256 / xa::T_m, 0);
  }

  /* Col=AD103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.zTmpIdx).d, xa::PReg(15),
                              xa::ZReg(a64.srcIdx).d);
  }
  /* Col=AE103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 1) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                16);
    }
  }
  /* Col=AF103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 2) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                32);
    }
  }
  /* Col=AG103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x3) == 3) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                48);
    }
  }
  /* Col=AH103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc) / 4) == 0) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                16);
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.srcIdx),
                                48);
    }
  }
  /* Col=AI103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc) / 4) == 1) {
      CodeGeneratorAArch64::mov(xa::ZReg(a64.zTmpIdx).d, xa::PReg(14),
                                xa::ZReg(a64.srcIdx).d);
    }
  }
  /* Col=AJ103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc) / 4) == 2) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                48);
      CodeGeneratorAArch64::mov(xa::ZReg(a64.zTmpIdx).d, xa::PReg(13),
                                xa::ZReg(a64.srcIdx).d);
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                16);
    }
  }
  /* Col=AK103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc) / 4) == 3) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                32);
      CodeGeneratorAArch64::trn1(xa::PRegD(a64.pTmpIdx), xa::PRegD(12),
                                 xa::PRegD(13));
      CodeGeneratorAArch64::uzp2(xa::PRegD(a64.pTmpIdx), xa::PRegD(a64.pTmpIdx),
                                 xa::PRegD(a64.pTmpIdx));
      CodeGeneratorAArch64::and_(xa::PRegB(a64.pTmpIdx), xa::PReg(13),
                                 xa::PRegB(a64.pTmpIdx), xa::PRegB(13));
      CodeGeneratorAArch64::mov(xa::ZReg(a64.zTmpIdx).d, xa::PReg(a64.pTmpIdx),
                                xa::ZReg(a64.srcIdx).d);
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                32);
    }
  }
  /* Col=AL103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x30) / 16) == 0) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                32);
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.src2Idx),
                                32);
    }
  }
  /* Col=AM103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x30) / 16) == 1) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                16);
      CodeGeneratorAArch64::eor(xa::PReg(a64.pTmpIdx).b, xa::PReg(15),
                                xa::PReg(13).b, xa::PReg(14).b);
      CodeGeneratorAArch64::mov(xa::ZReg(a64.zTmpIdx).d, xa::PReg(a64.pTmpIdx),
                                xa::ZReg(a64.src2Idx).d);
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                48);
    }
  }
  /* Col=AN103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x30) / 16) == 2) {
      CodeGeneratorAArch64::mov(xa::ZReg(a64.zTmpIdx).d, xa::PReg(13),
                                xa::ZReg(a64.src2Idx).d);
    }
  }
  /* Col=AO103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0x30) / 16) == 3) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                48);
      CodeGeneratorAArch64::trn1(xa::PRegD(a64.pTmpIdx), xa::PRegD(12),
                                 xa::PRegD(13));
      CodeGeneratorAArch64::uzp2(xa::PRegD(a64.pTmpIdx), xa::PRegD(a64.pTmpIdx),
                                 xa::PRegD(a64.pTmpIdx));
      CodeGeneratorAArch64::and_(xa::PRegB(a64.pTmpIdx), xa::PReg(13),
                                 xa::PRegB(a64.pTmpIdx), xa::PRegB(13));
      CodeGeneratorAArch64::mov(xa::ZReg(a64.zTmpIdx).d, xa::PReg(a64.pTmpIdx),
                                xa::ZReg(a64.src2Idx).d);
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                16);
    }
  }
  /* Col=AP103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc0) / 64) == 0) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                48);
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.src2Idx),
                                16);
    }
  }
  /* Col=AQ103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc0) / 64) == 1) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                32);
      CodeGeneratorAArch64::eor(xa::PReg(a64.pTmpIdx).b, xa::PReg(15),
                                xa::PReg(13).b, xa::PReg(14).b);
      CodeGeneratorAArch64::mov(xa::ZReg(a64.zTmpIdx).d, xa::PReg(a64.pTmpIdx),
                                xa::ZReg(a64.src2Idx).d);
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                32);
    }
  }
  /* Col=AR103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc0) / 64) == 2) {
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                16);
      CodeGeneratorAArch64::trn1(xa::PRegD(a64.pTmpIdx), xa::PRegD(12),
                                 xa::PRegD(13));
      CodeGeneratorAArch64::uzp2(xa::PRegD(a64.pTmpIdx), xa::PRegD(a64.pTmpIdx),
                                 xa::PRegD(a64.pTmpIdx));
      CodeGeneratorAArch64::and_(xa::PRegB(a64.pTmpIdx), xa::PReg(13),
                                 xa::PRegB(a64.pTmpIdx), xa::PRegB(13));
      CodeGeneratorAArch64::eor(xa::PReg(a64.pTmpIdx).b, xa::PReg(15),
                                xa::PReg(a64.pTmpIdx).b, xa::PReg(13).b);
      CodeGeneratorAArch64::mov(xa::ZReg(a64.zTmpIdx).d, xa::PReg(a64.pTmpIdx),
                                xa::ZReg(a64.src2Idx).d);
      CodeGeneratorAArch64::ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx),
                                48);
    }
  }
  /* Col=AS103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    if (((a64.uimm & 0xc0) / 64) == 3) {
      CodeGeneratorAArch64::trn1(xa::PRegD(a64.pTmpIdx), xa::PRegD(12),
                                 xa::PRegD(13));
      CodeGeneratorAArch64::uzp2(xa::PRegD(a64.pTmpIdx), xa::PRegD(a64.pTmpIdx),
                                 xa::PRegD(a64.pTmpIdx));
      CodeGeneratorAArch64::and_(xa::PRegB(a64.pTmpIdx), xa::PReg(13),
                                 xa::PRegB(a64.pTmpIdx), xa::PRegB(13));
      CodeGeneratorAArch64::mov(xa::ZReg(a64.zTmpIdx).d, xa::PReg(a64.pTmpIdx),
                                xa::ZReg(a64.src2Idx).d);
    }
  }
  /* Col=AT103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).d, xa::PReg(15),
                              xa::ZReg(a64.zTmpIdx).d);
  }

  /* Col=BB103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    xt_pop_preg();
  }
  /* Col=BC103*/
  if (false || (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
                a64.EVEXb == 0 && a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO && a64.EVEXb == 0 &&
       a64.src2Type == A64_OP_REG && true)) {
    xt_pop_zreg();
  }
}
