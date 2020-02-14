void translateVMOVHLPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);
  static const uint64_t maskFF    = uint64_t(0xFF);
  static const uint64_t maskFF00  = uint64_t(0xFF00);
  /* 2020/02/14 09:54 */
  /* Col=S103*/
  if(false ||(a64.dstWidth==256&&true)||(a64.dstWidth==512&&true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=V103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CodeGeneratorAArch64::mov_imm(xa::XReg(16), (size_t)&maskFF, xa::XReg(17));
  }
  /* Col=W103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CodeGeneratorAArch64::mov_imm(xa::XReg(18), (size_t)&maskFF00, xa::XReg(19));
  }
  /* Col=X103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CodeGeneratorAArch64::ldr(xa::PReg(8), xa::ptr(xa::XReg(16)));
  }
  /* Col=Y103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CodeGeneratorAArch64::ldr(xa::PReg(9), xa::ptr(xa::XReg(18)));
  }
  /* Col=Z103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CodeGeneratorAArch64::eor(xa::ZReg(a64.dstIdx).d, xa::ZReg(a64.dstIdx).d, xa::ZReg(a64.dstIdx).d);
  }
  /* Col=AA103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).d, xa::PReg(9), xa::ZReg(a64.srcIdx).d);
  }
  /* Col=AB103*/
  if(false ||(a64.dstWidth==128&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
    CodeGeneratorAArch64::mov(xa::ZReg(a64.dstIdx).d, xa::PReg(8), xa::ZReg(a64.src2Idx).d);
  }
}
