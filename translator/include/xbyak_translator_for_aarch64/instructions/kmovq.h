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
/* 2020/03/12 15:57 */
#define CG64 CodeGeneratorAArch64
void translateKMOVQ(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;

  /* Col=AD119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_GPR &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AG119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_GPR &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AJ119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    CG64::mov(xa::PRegB(dstIdx), xa::PRegB(srcIdx));
  }
  /* Col=AK119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_GPR &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
#ifdef XT_TEST
    CG64::sub(X_TMP_ADDR, CG64::sp, 8);
#else
    CG64::sub(X_TMP_ADDR, xa::XReg(SP_REG_IDX_X86_64), 8);
#endif
    CG64::str(xa::PReg(srcIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AL119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
#ifdef XT_TEST
    CG64::sub(X_TMP_ADDR, CG64::sp, 8);
#else
    CG64::sub(X_TMP_ADDR, xa::XReg(SP_REG_IDX_X86_64), 8);
#endif
    CG64::str(xa::XReg(srcIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AM119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_GPR &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    CG64::ldr(xa::XReg(dstIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AN119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true)) {
    CG64::ldr(xa::PReg(dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AO119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 &&
                a64.operands[1].opName == XED_OPERAND_REG0 &&
                a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    CG64::str(xa::PReg(srcIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=BK119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[0].regClass == XED_REG_CLASS_MASK &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_MASK &&
       a64.operands[1].regClass == XED_REG_CLASS_GPR && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[0].regClass == XED_REG_CLASS_GPR &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
