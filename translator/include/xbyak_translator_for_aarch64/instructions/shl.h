void translateSHL(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);
  /* 2020/02/25 10:15 */
#define CG64 CodeGeneratorAArch64
/* Col=S103*/
  if(false ||(a64.dstWidth==8&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_IMM&&true)||(a64.dstWidth==8&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_IMM&&true)||(a64.dstWidth==8&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==8&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==16&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_IMM&&true)||(a64.dstWidth==16&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_IMM&&true)||(a64.dstWidth==16&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==16&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==32&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_IMM&&true)||(a64.dstWidth==32&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_IMM&&true)||(a64.dstWidth==32&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==32&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==64&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_IMM&&true)||(a64.dstWidth==64&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&true)||(a64.dstWidth==64&&a64.dstType==A64_OP_MEM&&a64.srcType==A64_OP_REG&&true)) {
  XT_UNIMPLEMENTED;
  }
  /* Col=Y103*/
  if(false ||(a64.dstWidth==64&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_IMM&&true)) {
    CG64::lsl(xa::XReg(a64.dstIdx), xa::XReg(a64.dstIdx), a64.uimm);
  }
#undef CG64
}
