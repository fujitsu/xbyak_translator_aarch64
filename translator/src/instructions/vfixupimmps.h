/*******************************************************************************
 * Copyright 2020 FUJITSU LIMITED
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
/* 2020/05/14 16:15 */

void Xbyak::CodeGenerator::translateVFIXUPIMMPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  xa::Label l_exec, l_table;
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t src2Idx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmp2Idx = XT_REG_INVALID;
  xt_reg_idx_t zTmp3Idx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t pTmp2Idx = XT_REG_INVALID;

  /* Col=X120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=Y120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=Z120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    pTmp2Idx = xt_push_preg(&a64);
  }
  /* Col=AA120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AB120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=AC120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    zTmp3Idx = xt_push_zreg(&a64);
  }
  /* Col=AF120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AG120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    srcIdx = a64.operands[2].regIdx;
  }

  /* Col=AH120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AJ120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    b(l_exec);
    // gen table
    L(l_table);
    xa_->dd(0xFFFFFFFF); // dummy for dest[31:0]
    xa_->dd(0xFFFFFFFF); // dummy for tsrc[31:0]
    xa_->dd(0x7FC00000); // QNAN(tsrc[31:0])
    xa_->dd(0xFFC00000); // QNAN_Indefinite
    xa_->dd(0xFF800000); // -INF
    xa_->dd(0x7F800000); // +INF
    xa_->dd(0x7F800000); // dummy for tsrc.sign? -INF:+INF
    xa_->dd(0x80000000); // -0;
    xa_->dd(0x00000000); // +0;
    xa_->dd(0xBF800000); // -1;
    xa_->dd(0x3F800000); // +1;
    xa_->dd(0x3F000000); // 1/2;
    xa_->dd(0x42B40000); // 90.0
    xa_->dd(0x3FC90FDB); // PI/2
    xa_->dd(0x7F7FFFFF); // MAX_FLOAT
    xa_->dd(0xFF7FFFFF); // -MIN_FLOAT
    L(l_exec);
  }
  /* Col=AL120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegD(zTmpIdx), xa::ZRegD(srcIdx));
  }
  /* Col=AM120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegD(zTmp3Idx), 0);
  }

  /* Col=AT120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegS(zTmp2Idx), uint64_t(1) << 22);
  }
  /* Col=AV120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->ptrue(xa::PRegB(pTmpIdx));
  }
  /* Col=AW120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->adr(X_TMP_ADDR, l_table);
  }
  /* Col=AX120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    fcmuo(P_TMP_0.s, xa::PReg(pTmpIdx) / xa::T_z, xa::ZRegS(zTmpIdx),
          xa::ZRegS(zTmpIdx));
  }
  /* Col=AY120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->and_(xa::ZRegD(zTmp2Idx), xa::ZRegD(zTmpIdx), xa::ZRegD(zTmp2Idx));
  }
  /* Col=AZ120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->cmpeq(P_TMP_1.s, xa::PReg(pTmpIdx) / xa::T_z, xa::ZRegS(zTmp2Idx), 0);
  }
  /* Col=BA120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->and_(P_TMP_1.b, xa::PReg(pTmpIdx) / xa::T_z, P_TMP_0.b, P_TMP_1.b);
  }

  /* Col=BB120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegS(zTmp3Idx), P_TMP_1 / xa::T_m, 1);
  }
  /* Col=BC120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->bic(xa::PRegB(pTmpIdx), xa::PReg(pTmpIdx) / xa::T_z,
             xa::PReg(pTmpIdx).b, P_TMP_0.b);
  }
  /* Col=BD120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->fdup(xa::ZRegS(zTmp2Idx), float(1.0));
  }
  /* Col=BE120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->fcmeq(P_TMP_0.s, xa::PReg(pTmpIdx) / xa::T_z, xa::ZRegS(zTmpIdx),
               float(0.0));
  }
  /* Col=BF120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegS(zTmp3Idx), P_TMP_0 / xa::T_m, 2);
  }
  /* Col=BG120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->bic(xa::PRegB(pTmpIdx), xa::PReg(pTmpIdx) / xa::T_z,
             xa::PReg(pTmpIdx).b, P_TMP_0.b);
  }
  /* Col=BJ120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->fcmeq(P_TMP_0.s, xa::PReg(pTmpIdx) / xa::T_z, xa::ZRegS(zTmpIdx),
               xa::ZRegS(zTmp2Idx));
  }
  /* Col=BK120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->dupm(xa::ZRegS(zTmp2Idx), uint64_t(0xff800000));
  }

  /* Col=BL120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegS(zTmp3Idx), P_TMP_0 / xa::T_m, 3);
  }
  /* Col=BM120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->bic(xa::PRegB(pTmpIdx), xa::PReg(pTmpIdx) / xa::T_z,
             xa::PReg(pTmpIdx).b, P_TMP_0.b);
  }
  /* Col=BP120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->fcmeq(P_TMP_0.s, xa::PReg(pTmpIdx) / xa::T_z, xa::ZRegS(zTmpIdx),
               xa::ZRegS(zTmp2Idx));
  }
  /* Col=BQ120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->dupm(xa::ZRegS(zTmp2Idx), uint64_t(0x7f800000));
  }
  /* Col=BR120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegS(zTmp3Idx), P_TMP_0 / xa::T_m, 4);
  }
  /* Col=BS120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->bic(xa::PRegB(pTmpIdx), xa::PReg(pTmpIdx) / xa::T_z,
             xa::PReg(pTmpIdx).b, P_TMP_0.b);
  }

  /* Col=BV120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->fcmeq(P_TMP_0.s, xa::PReg(pTmpIdx) / xa::T_z, xa::ZRegS(zTmpIdx),
               xa::ZRegS(zTmp2Idx));
  }
  /* Col=BW120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegD(zTmp2Idx), xa::ZRegD(src2Idx));
  }
  /* Col=BX120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegS(zTmp3Idx), P_TMP_0 / xa::T_m, 5);
  }
  /* Col=BY120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->bic(xa::PRegB(pTmpIdx), xa::PReg(pTmpIdx) / xa::T_z,
             xa::PReg(pTmpIdx).b, P_TMP_0.b);
  }
  /* Col=CA120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->cmplt(P_TMP_0.s, xa::PReg(pTmpIdx) / xa::T_z, xa::ZRegS(zTmpIdx), 0);
  }
  /* Col=CB120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegS(zTmp3Idx), P_TMP_0 / xa::T_m, 6);
  }
  /* Col=CC120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->bic(xa::PRegB(pTmpIdx), xa::PReg(pTmpIdx) / xa::T_z,
             xa::PReg(pTmpIdx).b, P_TMP_0.b);
  }

  /* Col=CF120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegS(zTmp3Idx), xa::PReg(pTmpIdx) / xa::T_m, 7);
  }
  /* Col=CG120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->ptrue(xa::PRegB(pTmpIdx));
  }
  /* Col=CH120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->lsl(xa::ZRegS(zTmp3Idx), xa::ZRegS(zTmp3Idx), 2);
  }
  /* Col=CI120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->lsr(xa::ZRegS(zTmp2Idx), xa::PReg(pTmpIdx), xa::ZRegS(zTmp3Idx));
  }
  /* Col=CJ120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->and_(xa::ZRegS(zTmp2Idx), uint64_t(0xf));
  }
  /* Col=CK120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->cmpne(P_TMP_0.s, xa::PReg(pTmpIdx) / xa::T_z, xa::ZRegS(zTmp2Idx), 0);
  }
  /* Col=CL120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->ld1w(xa::ZRegS(zTmp3Idx), xa::PReg(pTmpIdx) / xa::T_z,
              xa::ptr(X_TMP_ADDR, xa::ZRegS(zTmp2Idx), xa::UXTW, 2));
  }
  /* Col=CN120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_TMP_0 / xa::T_m, xa::ZRegS(zTmp3Idx));
  }

  /* Col=DB120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->dupm(xa::ZRegS(zTmp3Idx), uint64_t(0x807fffff));
  }
  /* Col=DC120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->and_(xa::ZRegD(zTmp3Idx), xa::ZRegD(zTmp3Idx), xa::ZRegD(zTmpIdx));
  }
  /* Col=DF120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->cmpeq(P_TMP_0.s, xa::PReg(pTmpIdx) / xa::T_z, xa::ZRegS(zTmp2Idx), 1);
  }
  /* Col=DG120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_TMP_0 / xa::T_m, xa::ZRegS(zTmpIdx));
  }
  /* Col=DH120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->and_(xa::ZRegS(zTmpIdx), uint64_t(0x80000000));
  }
  /* Col=DI120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->cmpeq(xa::PRegS(pTmp2Idx), xa::PReg(pTmpIdx) / xa::T_z,
               xa::ZRegS(zTmp2Idx), 2);
  }

  /* Col=DJ120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->orr(xa::ZRegS(dstIdx), xa::PReg(pTmp2Idx) / xa::T_m,
             xa::ZRegS(zTmp3Idx));
  }
  /* Col=DM120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->cmpeq(xa::PRegS(pTmp2Idx), xa::PReg(pTmpIdx) / xa::T_z,
               xa::ZRegS(zTmp2Idx), 6);
  }
  /* Col=DN120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->orr(xa::ZRegS(dstIdx), xa::PReg(pTmp2Idx) / xa::T_m,
             xa::ZRegS(zTmpIdx));
  }

  /* Col=DT120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_zreg();
  }
  /* Col=DU120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_zreg();
  }
  /* Col=DV120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_zreg();
  }
  /* Col=DX120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_preg();
  }
  /* Col=DY120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xt_pop_preg();
  }
  /* Col=DZ120*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
