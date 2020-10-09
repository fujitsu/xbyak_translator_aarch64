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
/* 2020/09/14 17:28 */

void translateVGATHERDPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64, true, false);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t maskIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmp2Idx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;

  /* Col=X119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 512 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=Y119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AC119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 512 && true)) {
    maskIdx = a64.operands[1].regIdx;
  }

  /* Col=AF119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 512 && true)) {
    zTmp2Idx = a64.operands[2].memIndexIdx;
  }
  /* Col=AG119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    zTmp2Idx = a64.operands[1].memIndexIdx;
  }
  /* Col=AH119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 512 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=AJ119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    maskIdx = pTmpIdx;
  }
  /* Col=AK119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 && true)) {
    xa_->ptrue(xa::PRegS(pTmpIdx), xa::VL8);
  }
  /* Col=AL119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 128 && true)) {
    xa_->ptrue(xa::PRegS(pTmpIdx), xa::VL4);
  }
  /* Col=AM119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->cmplt(xa::PRegS(pTmpIdx), xa::PReg(pTmpIdx) / xa::T_z,
                xa::ZRegS(srcIdx), 0);
  }

  /* Col=AN119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 256 && true)) {
    // At last, VGATHERDPS destroies the mask register.
    xa_->bic(xa::PRegB(maskIdx), P_ALL_ONE / xa::T_z, xa::PRegB(maskIdx),
              P_MSB_256.b);
  }
  /* Col=AO119*/
  if (false || (a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 128 && true)) {
    // At last, VGATHERDPS destroies the mask register.
    xa_->bic(xa::PRegB(maskIdx), P_ALL_ONE / xa::T_z, xa::PRegB(maskIdx),
              P_MSB_384.b);
  }
  /* Col=AP119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 512 && true)) {
    xa_->mov(xa::ZRegD(zTmpIdx), xa::ZRegD(zTmp2Idx));
  }
  /* Col=AQ119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 512 && true)) {
    xa_->mul(xa::ZRegS(zTmpIdx), a64.operands[2].memScale);
  }
  /* Col=AR119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->mul(xa::ZRegS(zTmpIdx), a64.operands[1].memScale);
  }
  /* Col=AS119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 512 && true)) {
    xa_->ld1w(xa::ZRegS(zTmpIdx), xa::PReg(maskIdx) / xa::T_z,
               xa::ptr(X_TMP_ADDR, xa::ZRegS(zTmpIdx), xa::SXTW));
  }
  /* Col=AV119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 512 && true)) {
    xa_->mov(xa::ZRegS(dstIdx), xa::PReg(maskIdx) / xa::T_m,
              xa::ZRegS(zTmpIdx));
  }

  /* Col=BA119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 512 && true)) {
    xa_->pfalse(xa::PRegB(maskIdx));
  }
  /* Col=BB119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->mov(xa::ZRegS(srcIdx), 0);
  }
  /* Col=BC119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_MSB_256 / xa::T_m, 0);
  }
  /* Col=BD119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true)) {
    xa_->mov(xa::ZRegS(dstIdx), P_MSB_384 / xa::T_m, 0);
  }

  /* Col=BN119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true)) {
    xt_pop_preg();
  }
  /* Col=BO119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 512 && true)) {
    xt_pop_zreg();
  }
  /* Col=BQ119*/
  if (false ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 256 && true) ||
      (a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 512 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}

