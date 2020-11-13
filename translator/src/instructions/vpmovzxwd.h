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
/* 2020/10/20 20:49 */
void Xbyak::CodeGenerator::translateVPMOVZXWD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t maskIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;

  /* Col=AC119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AD119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=AE119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AF119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AG119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AH119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AJ119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->ldr(xa::DReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AK119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->ldr(xa::QReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AL119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->ptrue(xa::PRegH(pTmpIdx), xa::VL16);
  }
  /* Col=AM119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->ld1h(xa::ZRegH(zTmpIdx), xa::PReg(pTmpIdx) / xa::T_z,
              xa::ptr(X_TMP_ADDR));
  }
  /* Col=AO119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->zip1(xa::ZReg(zTmpIdx).h, xa::ZReg(srcIdx).h, xa::ZReg(srcIdx).h);
  }
  /* Col=AP119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->zip1(xa::ZReg(zTmpIdx).h, xa::ZReg(zTmpIdx).h, xa::ZReg(zTmpIdx).h);
  }
  /* Col=AT119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->uxth(xa::ZReg(dstIdx).s, P_ALL_ONE_0_7 / xa::T_m, xa::ZReg(zTmpIdx).s);
  }

  /* Col=AZ119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZReg(dstIdx).s, P_MSB_256 / xa::T_m, 0);
  }
  /* Col=BA119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZReg(dstIdx).s, P_MSB_384 / xa::T_m, 0);
  }

  /* Col=BV119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xt_pop_preg();
  }
  /* Col=BW119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xt_pop_zreg();
  }
  /* Col=BY119*/
  if (false ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[2].opName == XED_OPERAND_INVALID &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_REG2 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[0].opName == XED_OPERAND_REG0 &&
       a64_opt.operands[1].opName == XED_OPERAND_REG1 &&
       a64_opt.operands[2].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    return;
  }

  /* Col=U119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=V119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=W119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=X119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=Y119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=Z119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AB119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->ldr(xa::DReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AC119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->ldr(xa::QReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AD119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->ptrue(xa::PRegH(pTmpIdx), xa::VL16);
  }
  /* Col=AE119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->ld1h(xa::ZRegH(zTmpIdx), xa::PReg(pTmpIdx) / xa::T_z,
              xa::ptr(X_TMP_ADDR));
  }
  /* Col=AG119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->zip1(xa::ZReg(zTmpIdx).h, xa::ZReg(srcIdx).h, xa::ZReg(srcIdx).h);
  }
  /* Col=AH119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->zip1(xa::ZReg(zTmpIdx).h, xa::ZReg(zTmpIdx).h, xa::ZReg(zTmpIdx).h);
  }
  /* Col=AK119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true)) {
    xa_->mov(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=AL119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true)) {
    xa_->uxth(xa::ZReg(dstIdx).s, xa::PReg(pTmpIdx) / xa::T_m,
              xa::ZReg(zTmpIdx).s);
  }
  /* Col=AM119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->uxth(xa::ZReg(dstIdx).s, xa::PReg(maskIdx) / xa::T_m,
              xa::ZReg(zTmpIdx).s);
  }

  /* Col=AO119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true)) {
    xa_->not_(xa::PRegB(pTmpIdx), P_ALL_ONE.b, xa::PRegB(maskIdx));
  }
  /* Col=AQ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true)) {
    xa_->mov(xa::ZReg(dstIdx).s, xa::PReg(pTmpIdx) / xa::T_m, 0);
  }
  /* Col=AR119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->mov(xa::ZReg(dstIdx).s, P_MSB_256 / xa::T_m, 0);
  }
  /* Col=AS119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->mov(xa::ZReg(dstIdx).s, P_MSB_384 / xa::T_m, 0);
  }

  /* Col=BN119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_preg();
  }
  /* Col=BO119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BQ119*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
