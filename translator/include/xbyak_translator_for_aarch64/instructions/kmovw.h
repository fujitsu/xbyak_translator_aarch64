void translateKMOVW(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV2_t a64;
  xt_construct_a64fx_operandsV2(p, &a64);

#define CG64 CodeGeneratorAArch64

  static uint64_t maskTbl[65536];
  static bool isInit = false;

#ifdef XT_KMOVS_DEBUG
  char fillSaved = std::cout.fill('0');
#endif
  if(isInit == false) {
    for(int j=0; j<65536; j++) {
      for(int i=0; i<16; i++) {
	if(j & (1<<i)) {
	  maskTbl[j] |= (uint64_t(1) << (i*4));
	}
      }
#ifdef XT_KMOVS_DEBUG
      std::cout << std::setw(16) << std::hex << maskTbl[j] << std::endl;
#endif
    }
    isInit = true;
  }
#ifdef XT_KMOVS_DEBUG
  std::cout.fill(fillSaved);
#endif

  /* Set table address */
  xa::XReg x_addr{xtDefaultAddrIdx};
  CG64::mov_imm(x_addr, reinterpret_cast<size_t>(&(maskTbl[0])), X_TMP_0);

  /* Adjust offset */
  CG64::add(x_addr, x_addr, xa::XReg(a64.operands[1].regIdx), xa::LSL, 3);
  
  
  CG64::ldr(xa::PReg(a64.operands[0].regIdx), xa::ptr(X_TMP_ADDR));

#undef CG64
}
