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
/* 2020/03/17 15:01 */
#define CG64 CodeGeneratorAArch64
void translateVCVTPS2DQ(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
bool isValid = false;
xt_reg_idx_t dstIdx;
xt_reg_idx_t srcIdx;
xt_reg_idx_t zTmpIdx;

/* Col=W119*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[0].regClass==XED_REG_CLASS_XMM&&a64.operands[1].regClass==XED_REG_CLASS_MASK&&a64.operands[2].regClass==XED_REG_CLASS_XMM&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  zTmpIdx = xt_push_zreg(&a64);
}

/* Col=AD119*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[0].regClass==XED_REG_CLASS_XMM&&a64.operands[1].regClass==XED_REG_CLASS_MASK&&a64.operands[2].regClass==XED_REG_CLASS_XMM&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  dstIdx = a64.operands[0].regIdx;
}
/* Col=AE119*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[0].regClass==XED_REG_CLASS_XMM&&a64.operands[1].regClass==XED_REG_CLASS_MASK&&a64.operands[2].regClass==XED_REG_CLASS_XMM&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  srcIdx = a64.operands[2].regIdx;
}
/* Col=AK119*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[0].regClass==XED_REG_CLASS_XMM&&a64.operands[1].regClass==XED_REG_CLASS_MASK&&a64.operands[2].regClass==XED_REG_CLASS_XMM&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  CG64::sub(X_TMP_ADDR, xa::XReg(xt_sp_reg_idx), 64);
}
/* Col=AM119*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[0].regClass==XED_REG_CLASS_XMM&&a64.operands[1].regClass==XED_REG_CLASS_MASK&&a64.operands[2].regClass==XED_REG_CLASS_XMM&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  CG64::str(xa::ZReg(srcIdx), xa::ptr(X_TMP_ADDR));
}

/* Col=AR119*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[0].regClass==XED_REG_CLASS_XMM&&a64.operands[1].regClass==XED_REG_CLASS_MASK&&a64.operands[2].regClass==XED_REG_CLASS_XMM&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  for(int i=0; i<4; i++) {
  CG64::ldr(xa::VReg(zTmpIdx), xa::ptr(X_TMP_ADDR, i));
  CG64::frintn(xa::VReg(zTmpIdx), xa::VReg(zTmpIdx));
  CG64::str(xa::VReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
}
}


/* Col=BI119*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[0].regClass==XED_REG_CLASS_XMM&&a64.operands[1].regClass==XED_REG_CLASS_MASK&&a64.operands[2].regClass==XED_REG_CLASS_XMM&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  xt_pop_zreg();
}
/* Col=BK119*/
if(false ||(a64.operands[0].opName==XED_OPERAND_REG0&&a64.operands[1].opName==XED_OPERAND_REG1&&a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[0].regClass==XED_REG_CLASS_XMM&&a64.operands[1].regClass==XED_REG_CLASS_MASK&&a64.operands[2].regClass==XED_REG_CLASS_XMM&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  XT_VALID_CHECK;
}
XT_VALID_CHECK_IF;
}
#undef CG64
