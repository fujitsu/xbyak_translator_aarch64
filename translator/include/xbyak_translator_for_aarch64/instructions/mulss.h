void translateMULSS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);
  /* 2020/03/23 10:30 */
  bool isValid = false;
#define CG64 CodeGeneratorAArch64
  /* Col=S103*/
  if (false || (a64.srcType == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=U103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AP103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    CG64::fmul(xa::ZRegS(a64.zTmpIdx), xa::ZRegS(a64.dstIdx),
               xa::ZRegS(a64.srcIdx));
  }
  /* Col=AW103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    CG64::mov(xa::VReg(a64.dstIdx).s[0], xa::VReg(a64.zTmpIdx).s[0]);
  }
  /* Col=BN103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    xt_pop_zreg();
  }
  /* Col=BP103*/
  if (false || (a64.srcType == A64_OP_REG && true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF
#undef CG64
}
