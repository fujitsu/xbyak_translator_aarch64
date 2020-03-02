void translateINC(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/03/02 18:54 */
  /* Col=S103*/
  if(false ||(a64.dstWidth==8&&a64.dstType==A64_OP_REG&&true)||(a64.dstWidth==8&&a64.dstType==A64_OP_MEM&&true)||(a64.dstWidth==16&&a64.dstType==A64_OP_REG&&true)||(a64.dstWidth==16&&a64.dstType==A64_OP_MEM&&true)) {
    XT_UNIMPLEMENTED;
  }







  /* Col=AA103*/
  if(false ||(a64.dstWidth==32&&a64.dstType==A64_OP_MEM&&true)) {
    CodeGeneratorAArch64::ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AB103*/
  if(false ||(a64.dstWidth==64&&a64.dstType==A64_OP_MEM&&true)) {
    CodeGeneratorAArch64::ldr(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }




  /* Col=AG103*/
  if(false ||(a64.dstWidth==32&&a64.dstType==A64_OP_REG&&true)) {
    CodeGeneratorAArch64::add(xa::WReg(a64.dstIdx), xa::WReg(a64.dstIdx), 1);
  }
  /* Col=AH103*/
  if(false ||(a64.dstWidth==32&&a64.dstType==A64_OP_MEM&&true)) {
    CodeGeneratorAArch64::add(W_TMP_0, W_TMP_0, 1);
  }
  /* Col=AI103*/
  if(false ||(a64.dstWidth==64&&a64.dstType==A64_OP_REG&&true)) {
    CodeGeneratorAArch64::add(xa::XReg(a64.dstIdx), xa::XReg(a64.dstIdx), 1);
  }
  /* Col=AJ103*/
  if(false ||(a64.dstWidth==64&&a64.dstType==A64_OP_MEM&&true)) {
    CodeGeneratorAArch64::add(X_TMP_0, X_TMP_0, 1);
  }



  /* Col=AN103*/
  if(false ||(a64.dstWidth==32&&a64.dstType==A64_OP_MEM&&true)) {
    CodeGeneratorAArch64::str(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AO103*/
  if(false ||(a64.dstWidth==64&&a64.dstType==A64_OP_MEM&&true)) {
    CodeGeneratorAArch64::str(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }

  
}
