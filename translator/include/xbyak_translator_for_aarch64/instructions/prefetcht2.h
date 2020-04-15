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
/* 2020/04/14 04:24 */
#define CG64 CodeGeneratorAArch64
void translatePREFETCHT2(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;

  /* Col=X119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 && true)) {
    CG64::prfm(xa::PLDL3KEEP, xa::ptr(X_TMP_ADDR));
  }

  /* Col=BK119*/
  if (false || (a64.operands[0].opName == XED_OPERAND_MEM0 && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}
#undef CG64
