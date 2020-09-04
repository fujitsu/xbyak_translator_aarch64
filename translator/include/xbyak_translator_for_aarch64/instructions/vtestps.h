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
/* 2020/05/01 12:09 */

void translateVTESTPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  xa::Label L_zflag, L_cflag;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t src2Idx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmp2Idx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;

  /* Col=Y120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=AA120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AB120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }

  /* Col=AH120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    srcIdx = a64.operands[0].regIdx;
  }
  /* Col=AI120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true)) {
    src2Idx = a64.operands[1].regIdx;
  }
  /* Col=AJ120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    src2Idx = zTmp2Idx;
  }
  /* Col=AK120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true)) {
    xa_->ptrue(P_TMP.s, xa::VL4);
  }
  /* Col=AL120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->ptrue(P_TMP.s, xa::VL8);
  }
  /* Col=AN120*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 128 && true)) {
    xa_->ldr(xa::QReg(src2Idx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AO120*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 && true)) {
    xa_->ld1w(xa::ZRegS(src2Idx), xa::PReg(pTmpIdx) / xa::T_z,
               xa::ptr(X_TMP_ADDR));
  }
  /* Col=AQ120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->and_(xa::ZRegD(zTmpIdx), xa::ZRegD(src2Idx), xa::ZRegD(srcIdx));
  }

  /* Col=AR120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->cmplt(xa::PRegS(pTmpIdx), P_TMP / xa::T_z, xa::ZReg(zTmpIdx).s, 0);
  }
  /* Col=AS120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->cntp(X_TMP_0, P_TMP, xa::PRegS(pTmpIdx));
  }
  /* Col=AT120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->cmp(X_TMP_0, 0);
  }
  /* Col=AU120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->mov(X_TMP_0, 0);
  }
  /* Col=AV120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->b(xa::NE, L_zflag);
  }
  /* Col=AW120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->mov(W_TMP_0, uint32_t(1) << 30);
  }
  /* Col=AX120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    L(L_zflag);
  }
  /* Col=AZ120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->mrs(X_TMP_2, 0x3, 0x3, 0x4, 0x2, 0x0); // Read NZCV register
  }
  /* Col=BA120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->bic(xa::ZRegD(zTmpIdx), xa::ZRegD(src2Idx), xa::ZRegD(srcIdx));
  }

  /* Col=BB120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->cmplt(xa::PRegS(pTmpIdx), P_TMP / xa::T_z, xa::ZReg(zTmpIdx).s, 0);
  }
  /* Col=BC120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->cntp(X_TMP_1, P_TMP, xa::PRegS(pTmpIdx));
  }
  /* Col=BD120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->cmp(X_TMP_1, 0);
  }
  /* Col=BE120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->b(xa::NE, L_cflag);
  }
  /* Col=BF120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->orr(W_TMP_0, W_TMP_0, uint32_t(1) << 29);
  }
  /* Col=BG120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    L(L_cflag);
  }
  /* Col=BJ120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->and_(W_TMP_2, W_TMP_2, ~(uint32_t(0xf) << 28));
  }
  /* Col=BK120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->orr(W_TMP_2, W_TMP_2, W_TMP_0);
  }

  /* Col=BL120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->msr(0x3, 0x3, 0x4, 0x2, 0x0, X_TMP_2); // Write NZCV register
  }
  /* Col=BR120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xt_pop_zreg();
  }
  /* Col=BS120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xt_pop_zreg();
  }
  /* Col=BT120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xt_pop_preg();
  }
  /* Col=BU120*/
  if (false ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}

