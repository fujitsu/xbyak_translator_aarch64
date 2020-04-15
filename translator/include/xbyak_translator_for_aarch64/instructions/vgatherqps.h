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
/* 2020/04/14 19:16 */
#define CG64 CodeGeneratorAArch64
void translateVGATHERQPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64, true);
  bool isValid = false;
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t maskIdx;
  xt_reg_idx_t zTmpIdx;
  xt_reg_idx_t zTmp2Idx;
  xt_reg_idx_t pTmpIdx;
  xt_reg_idx_t zTmp3Idx;
  xt_reg_idx_t offsetIdx;

  /* Col=X119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[2].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 128 &&
                a64.operands[1].vmIndexRegWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 &&
       a64.operands[1].vmIndexRegWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 &&
       a64.operands[2].vmIndexRegWidth == 128 && a64.predType == A64_PRED_NO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 &&
       a64.operands[2].vmIndexRegWidth == 128 &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 &&
       a64.operands[2].vmIndexRegWidth == 256 && a64.predType == A64_PRED_NO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 &&
       a64.operands[2].vmIndexRegWidth == 256 &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 &&
       a64.operands[2].vmIndexRegWidth == 512 && a64.predType == A64_PRED_NO &&
       true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=Y119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=Z119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AA119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=AB119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    zTmp3Idx = xt_push_zreg(&a64);
  }
  /* Col=AE119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AK119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AM119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    offsetIdx = a64.operands[2].vmIndexRegIdx;
  }
  /* Col=AQ119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    CG64::mov(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=AR119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    CG64::and_(xa::PRegB(pTmpIdx), xa::PReg(pTmpIdx), xa::PRegB(pTmpIdx),
               xa::PRegB(maskIdx));
  }
  /* Col=AS119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    CG64::ld1w(xa::ZRegS(zTmpIdx), xa::PReg(pTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AU119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    CG64::index(xa::ZRegS(zTmp2Idx), 0, 1);
  }
  /* Col=AX119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    for (int i = 0; i < 8; i++) {
      CG64::dup(xa::ZRegD(zTmpIdx), xa::ZReg(offsetIdx).d[i]);
      CG64::mov(X_TMP_0, xa::VReg(zTmpIdx).d[0]);
      CG64::add(X_TMP_0, X_TMP_0, X_TMP_ADDR);
      CG64::ld1w(xa::ZRegS(zTmpIdx), xa::PReg(pTmpIdx), xa::ptr(X_TMP_0));
      CG64::dup(xa::ZRegS(zTmp3Idx), xa::ZReg(zTmpIdx).s[0]);
      CG64::cmpeq(P_TMP_0.s, xa::PReg(pTmpIdx), xa::ZRegS(zTmp2Idx), i);
      CG64::mov(xa::ZRegS(dstIdx), P_TMP_0 / xa::T_m, xa::ZRegS(zTmp3Idx));
    }
  }
  /* Col=AY119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    CG64::mov(xa::ZRegS(dstIdx), P_MSB_256 / xa::T_m, 0);
  }
  /* Col=BA119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    CG64::not_(xa::PRegB(maskIdx), P_ALL_ONE, P_ALL_ONE.b);
  }
  /* Col=BK119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    xt_pop_zreg();
  }
  /* Col=BL119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    xt_pop_zreg();
  }
  /* Col=BM119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    xt_pop_zreg();
  }
  /* Col=BN119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.operands[2].vmIndexRegWidth == 512 &&
                a64.predType == A64_PRED_MERG && true)) {
    xt_pop_preg();
  }
  /* Col=BO119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[2].opName == XED_OPERAND_REG1 &&
                a64.operands[0].opWidth == 128 &&
                a64.operands[1].vmIndexRegWidth == 128 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[0].opWidth == 128 &&
       a64.operands[1].vmIndexRegWidth == 256 && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 &&
       a64.operands[2].vmIndexRegWidth == 128 && a64.predType == A64_PRED_NO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 &&
       a64.operands[2].vmIndexRegWidth == 128 &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 &&
       a64.operands[2].vmIndexRegWidth == 256 && a64.predType == A64_PRED_NO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 &&
       a64.operands[2].vmIndexRegWidth == 256 &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 &&
       a64.operands[2].vmIndexRegWidth == 512 && a64.predType == A64_PRED_NO &&
       true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 &&
       a64.operands[2].vmIndexRegWidth == 512 &&
       a64.predType == A64_PRED_MERG && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
