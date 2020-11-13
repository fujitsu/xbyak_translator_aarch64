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
/* 2020/04/26 10:47 */

void Xbyak::CodeGenerator::translateLEA(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;

  /* Col=X119*/
  if (false || (a64.operands[0].opWidth == 16 && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=AA119*/
  if (false || (a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opWidth == 64 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AD119*/
  if (false || (a64.operands[0].opWidth == 32 && true)) {
    xa_->mov(xa::WReg(dstIdx), xa::WReg(X_TMP_ADDR.getIdx()));
  }
  /* Col=AE119*/
  if (false || (a64.operands[0].opWidth == 64 && true)) {
    xa_->mov(xa::XReg(dstIdx), X_TMP_ADDR);
  }

  /* Col=BO119*/
  if (false || (a64.operands[0].opWidth == 16 && true) ||
      (a64.operands[0].opWidth == 32 && true) ||
      (a64.operands[0].opWidth == 64 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
