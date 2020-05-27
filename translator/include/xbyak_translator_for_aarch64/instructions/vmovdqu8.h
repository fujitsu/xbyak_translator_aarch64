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
void translateVMOVDQU8(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

/* 2020/05/26 23:26 */
#define CG64 CodeGeneratorAArch64

  /* Col=T103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=U103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=V103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    CG64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, P_MSB_256.b);
  }
  /* Col=W103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::ldr(xa::QReg(a64.dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=X103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::ldr(xa::QReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=Y103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=Z103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::ldr(xa::ZReg(a64.dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AA103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::ld1b(xa::ZRegB(a64.dstIdx), xa::PReg(a64.maskIdx),
               xa::ptr(X_TMP_ADDR));
  }
  /* Col=AB103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::ld1b(xa::ZRegB(a64.dstIdx), xa::PReg(a64.pTmpIdx),
               xa::ptr(X_TMP_ADDR));
  }
  /* Col=AC103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::ld1b(xa::ZRegB(a64.zTmpIdx), xa::PReg(a64.maskIdx),
               xa::ptr(X_TMP_ADDR));
  }
  /* Col=AD103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    CG64::bic(xa::PRegB(a64.pTmpIdx), P_ALL_ONE / xa::T_z,
              xa::PRegB(a64.maskIdx), P_MSB_384.b);
  }
  /* Col=AE103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    CG64::bic(xa::PRegB(a64.pTmpIdx), P_ALL_ONE / xa::T_z,
              xa::PRegB(a64.maskIdx), P_MSB_256.b);
  }
  /* Col=AF103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::orn(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, P_MSB_384.b,
              xa::PRegB(a64.maskIdx));
  }
  /* Col=AG103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::orn(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, P_MSB_256.b,
              xa::PRegB(a64.maskIdx));
  }
  /* Col=AH103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    CG64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE, xa::PRegB(a64.maskIdx));
  }

  /* Col=AK103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    CG64::mov(xa::VReg16B(a64.dstIdx), xa::VReg16B(a64.srcIdx));
  }

  /* Col=AN103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    CG64::mov(xa::ZRegB(a64.dstIdx), xa::PReg(a64.maskIdx) / xa::T_m,
              xa::ZRegB(a64.srcIdx));
  }
  /* Col=AO103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    CG64::mov(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.srcIdx));
  }
  /* Col=AP103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::mov(xa::ZRegB(a64.dstIdx), xa::PReg(a64.maskIdx) / xa::T_m,
              xa::ZRegB(a64.zTmpIdx));
  }

  /* Col=AR103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    CG64::mov(xa::ZRegB(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_m, 0);
  }
  /* Col=AS103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::mov(xa::ZRegB(a64.dstIdx), P_MSB_384 / xa::T_m, 0);
  }
  /* Col=AT103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    CG64::mov(xa::ZRegB(a64.dstIdx), P_MSB_256 / xa::T_m, 0);
  }

  /* Col=AV103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    CG64::str(xa::QReg(a64.srcIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AW103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    CG64::st1b(xa::ZRegB(a64.srcIdx), xa::PReg(a64.maskIdx),
               xa::ptr(X_TMP_ADDR));
  }
  /* Col=AX103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    CG64::st1b(xa::ZRegB(a64.srcIdx), xa::PReg(a64.pTmpIdx),
               xa::ptr(X_TMP_ADDR));
  }

  /* Col=BA103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    CG64::str(xa::ZReg(a64.srcIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=BB103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    xt_pop_preg();
  }
  /* Col=BC103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    xt_pop_zreg();
  }
#undef CG64
}
