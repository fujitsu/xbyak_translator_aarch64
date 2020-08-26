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
void translateKORTESTQ(xed_decoded_inst_t *p) {
  unsigned int srcIdx1, srcIdx2;
  uint32_t zflag = 8;
  uint32_t cflag = 2;
  uint32_t zcond = 0;
  // uint32_t ccond = 65535;
  enum Xbyak::Xbyak_aarch64::Cond condEQ = Xbyak::Xbyak_aarch64::EQ;

  Xbyak_aarch64::PReg ptmp(8);
  Xbyak_aarch64::PReg condR(
      10); // PRegのand演算の条件レジスタ。いったん形だけ。なんか値を入れる必要あるはず。全部1?
  Xbyak_aarch64::XReg addrtmp(25);
  Xbyak_aarch64::XReg presult(26);
  Xbyak_aarch64::XReg comp(27);
  // Xbyak_aarch64::WReg presult(26);

  srcIdx1 = xed_get_register_index(p, 0);
  Xbyak_aarch64::PReg src1(srcIdx1);
  srcIdx2 = xed_get_register_index(p, 1);
  Xbyak_aarch64::PReg src2(srcIdx2);

  mov__(addrtmp, ALL1_BIT64_ADDRESS); //アドレスはいったん適当な値
  Xbyak_aarch64::AdrNoOfs adr_reg(addrtmp);
  ldr(condR, adr_reg);
  Xbyak_aarch64::xa_->AND_(
      ptmp.b, condR / Xbyak::Xbyak_aarch64::T_z, src1.b,
      src2.b); // get AND src1, src2

  // push result of "or k1, k2"
  mov__(addrtmp, sp_);
  Xbyak_aarch64::AdrNoOfs adr_sp(addrtmp);
  str(ptmp, adr_sp);
  sub__(addrtmp, addrtmp, 64);
  mov__(sp_, addrtmp);

  // pop result of "or k1, k2"
  ldr(presult, post_ptr(sp_, 64));
  ldr(comp, ALL1_BIT64_ADDRESS);
  // set Z or C flags
  // ccmn(presult, 0, 8, 0x0); // if presult == 0 then Z flag = 1. (0x0 means
  // EQ) ccmn(presult, 65535, 2,
  //       0x0); // if presult == 0xFFFF(65535) the  C flag = 1 (0x0 means EQ)
  ccmn(presult, zcond, zflag,
       condEQ); // if presult == 0 then Z flag = 1. (0x0 means EQ)
  ccmn(presult, comp, cflag,
       condEQ); // if presult == 0xFFFF(65535) the  C flag = 1 (0x0 means EQ)
}
