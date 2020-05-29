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
/* 2020/05/27 10:55 */
#define CG64 CodeGeneratorAArch64
void translateKORTESTW(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;

  /* Col=AH119*/
  if (false || (true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AK119*/
  if (false || (true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AO119*/
  if (false || (true)) {
    CG64::orr(P_TMP_0.b, P_ALL_ONE, xa::PRegB(dstIdx), xa::PRegB(srcIdx));
  }
  /* Col=AP119*/
  if (false || (true)) {
    CG64::cntp(X_TMP_0, P_ALL_ONE, P_TMP_0.s);
  }
  /* Col=AR119*/
  if (false || (true)) {
    CG64::mov(X_TMP_1, uint64_t(1));
  }
  /* Col=AT119*/
  if (false || (true)) {
    CG64::cmp(X_TMP_0, 16);
  }
  /* Col=AU119*/
  if (false || (true)) {
    CG64::b(xa::NE, 20);
  }
  /* Col=AV119*/
  if (false || (true)) {
    CG64::mov_imm(X_TMP_1, ~uint64_t(0), X_TMP_2);
  }
  /* Col=AW119*/
  if (false || (true)) {
    CG64::cmp(X_TMP_0, 0);
  }
  /* Col=AX119*/
  if (false || (true)) {
    CG64::b(xa::NE, 4 * (1 << 1));
  }
  /* Col=AY119*/
  if (false || (true)) {
    CG64::mov(X_TMP_1, uint64_t(0));
  }
  /* Col=AZ119*/
  if (false || (true)) {
    CG64::adds(X_TMP_1, X_TMP_0, X_TMP_1);
  }
  /* Col=BO119*/
  if (false || (true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
