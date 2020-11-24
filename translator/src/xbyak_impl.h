void Xbyak::CodeGenerator::rex(const Operand &op1, const Operand &op2) {
  uint8 rex = 0;
  const Operand *p1 = &op1, *p2 = &op2;
  if (p1->isMEM())
    std::swap(p1, p2);
  if (p1->isMEM())
    throw Error(ERR_BAD_COMBINATION);
  if (p2->isMEM()) {
    const Address &addr = p2->getAddress();
    if (BIT == 64 && addr.is32bit())
      db(0x67);
    rex = addr.getRex() | p1->getReg().getRex();
  } else {
    // ModRM(reg, base);
    rex = op2.getReg().getRex(op1.getReg());
  }
  // except movsx(16bit, 32/64bit)
  if ((op1.isBit(16) && !op2.isBit(i32e)) ||
      (op2.isBit(16) && !op1.isBit(i32e)))
    db(0x66);
  if (rex)
    db(rex);
}
void Xbyak::CodeGenerator::vex(const Reg &reg, const Reg &base,
                               const Operand *v, int type, int code, bool x) {
  int w = (type & T_W1) ? 1 : 0;
  bool is256 = (type & T_L1) ? true : (type & T_L0) ? false : reg.isYMM();
  bool r = reg.isExtIdx();
  bool b = base.isExtIdx();
  int idx = v ? v->getIdx() : 0;
  if ((idx | reg.getIdx() | base.getIdx()) >= 16)
    throw Error(ERR_BAD_COMBINATION);
  uint32 pp = (type & T_66) ? 1 : (type & T_F3) ? 2 : (type & T_F2) ? 3 : 0;
  uint32 vvvv = (((~idx) & 15) << 3) | (is256 ? 4 : 0) | pp;
  if (!b && !x && !w && (type & T_0F)) {
    db(0xC5);
    db((r ? 0 : 0x80) | vvvv);
  } else {
    uint32 mmmm =
        (type & T_0F) ? 1 : (type & T_0F38) ? 2 : (type & T_0F3A) ? 3 : 0;
    db(0xC4);
    db((r ? 0 : 0x80) | (x ? 0 : 0x40) | (b ? 0 : 0x20) | mmmm);
    db((w << 7) | vvvv);
  }
  db(code);
}

int Xbyak::CodeGenerator::evex(const Reg &reg, const Reg &base,
                               const Operand *v, int type, int code, bool x,
                               bool b, int aaa, uint32 VL, bool Hi16Vidx) {
  if (!(type & (T_EVEX | T_MUST_EVEX)))
    throw Error(ERR_EVEX_IS_INVALID);
  int w = (type & T_EW1) ? 1 : 0;
  uint32 mm = (type & T_0F) ? 1 : (type & T_0F38) ? 2 : (type & T_0F3A) ? 3 : 0;
  uint32 pp = (type & T_66) ? 1 : (type & T_F3) ? 2 : (type & T_F2) ? 3 : 0;

  int idx = v ? v->getIdx() : 0;
  uint32 vvvv = ~idx;

  bool R = !reg.isExtIdx();
  bool X = x ? false : !base.isExtIdx2();
  bool B = !base.isExtIdx();
  bool Rp = !reg.isExtIdx2();
  int LL;
  int rounding =
      verifyDuplicate(reg.getRounding(), base.getRounding(),
                      v ? v->getRounding() : 0, ERR_ROUNDING_IS_ALREADY_SET);
  int disp8N = 1;
  if (rounding) {
    if (rounding == EvexModifierRounding::T_SAE) {
      verifySAE(base, type);
      LL = 0;
    } else {
      verifyER(base, type);
      LL = rounding - 1;
    }
    b = true;
  } else {
    if (v)
      VL = (std::max)(VL, v->getBit());
    VL = (std::max)((std::max)(reg.getBit(), base.getBit()), VL);
    LL = (VL == 512) ? 2 : (VL == 256) ? 1 : 0;
    if (b) {
      disp8N = (type & T_B32) ? 4 : 8;
    } else if (type & T_DUP) {
      disp8N = VL == 128 ? 8 : VL == 256 ? 32 : 64;
    } else {
      if ((type & (T_NX_MASK | T_N_VL)) == 0) {
        type |= T_N16 | T_N_VL; // default
      }
      int low = type & T_NX_MASK;
      if (low > 0) {
        disp8N = 1 << (low - 1);
        if (type & T_N_VL)
          disp8N *= (VL == 512 ? 4 : VL == 256 ? 2 : 1);
      }
    }
  }
  bool Vp = !((v ? v->isExtIdx2() : 0) | Hi16Vidx);
  bool z = reg.hasZero() || base.hasZero() || (v ? v->hasZero() : false);
  if (aaa == 0)
    aaa =
        verifyDuplicate(base.getOpmaskIdx(), reg.getOpmaskIdx(),
                        (v ? v->getOpmaskIdx() : 0), ERR_OPMASK_IS_ALREADY_SET);
  db(0x62);
  db((R ? 0x80 : 0) | (X ? 0x40 : 0) | (B ? 0x20 : 0) | (Rp ? 0x10 : 0) |
     (mm & 3));
  db((w == 1 ? 0x80 : 0) | ((vvvv & 15) << 3) | 4 | (pp & 3));
  db((z ? 0x80 : 0) | ((LL & 3) << 5) | (b ? 0x10 : 0) | (Vp ? 8 : 0) |
     (aaa & 7));
  db(code);
  return disp8N;
}

void Xbyak::CodeGenerator::setModRM(int mod, int r1, int r2) {
  db(static_cast<uint8>((mod << 6) | ((r1 & 7) << 3) | (r2 & 7)));
}

void Xbyak::CodeGenerator::opModR(const Reg &reg1, const Reg &reg2, int code0,
                                  int code1, int code2) {
  rex(reg2, reg1);
  db(code0 | (reg1.isBit(8) ? 0 : 1));
  if (code1 != NONE)
    db(code1);
  if (code2 != NONE)
    db(code2);
  setModRM(3, reg1.getIdx(), reg2.getIdx());
}

void Xbyak::CodeGenerator::opModM(const Address &addr, const Reg &reg,
                                  int code0, int code1, int code2,
                                  int immSize) {
  if (addr.is64bitDisp())
    throw Error(ERR_CANT_USE_64BIT_DISP);
  rex(addr, reg);
  db(code0 | (reg.isBit(8) ? 0 : 1));
  if (code1 != NONE)
    db(code1);
  if (code2 != NONE)
    db(code2);
  opAddr(addr, reg.getIdx(), immSize);
}
void Xbyak::CodeGenerator::opLoadSeg(const Address &addr, const Reg &reg,
                                     int code0, int code1) {
  if (addr.is64bitDisp())
    throw Error(ERR_CANT_USE_64BIT_DISP);
  if (reg.isBit(8))
    throw Error(ERR_BAD_SIZE_OF_REGISTER);
  rex(addr, reg);
  db(code0);
  if (code1 != NONE)
    db(code1);
  opAddr(addr, reg.getIdx());
}

void Xbyak::CodeGenerator::opMIB(const Address &addr, const Reg &reg, int code0,
                                 int code1) {
  if (addr.is64bitDisp())
    throw Error(ERR_CANT_USE_64BIT_DISP);
  if (addr.getMode() != Address::M_ModRM)
    throw Error(ERR_INVALID_MIB_ADDRESS);
  if (BIT == 64 && addr.is32bit())
    db(0x67);
  const RegExp &regExp = addr.getRegExp(false);
  uint8 rex = regExp.getRex();
  if (rex)
    db(rex);
  db(code0);
  db(code1);
  setSIB(regExp, reg.getIdx());
}
void Xbyak::CodeGenerator::makeJmp(uint32 disp,
                                   Xbyak::CodeGenerator::LabelType type,
                                   uint8 shortCode, uint8 longCode,
                                   uint8 longPref) {
  UNIMPLEMENTED2;
}

void Xbyak::CodeGenerator::putL_inner(const Label &label, bool relative,
                                      size_t disp) {
  UNIMPLEMENTED2;
}
void Xbyak::CodeGenerator::opMovxx(const Reg &reg, const Operand &op,
                                   uint8 code) {
  if (op.isBit(32))
    throw Error(ERR_BAD_COMBINATION);
  int w = op.isBit(16);
#ifdef XBYAK64
  if (op.isHigh8bit())
    throw Error(ERR_BAD_COMBINATION);
#endif
  bool cond = reg.isREG() && (reg.getBit() > op.getBit());
  opModRM(reg, op, cond && op.isREG(), cond && op.isMEM(), 0x0F, code | w);
}

void Xbyak::CodeGenerator::opFpuMem(const Address &addr, uint8 m16, uint8 m32,
                                    uint8 m64, uint8 ext, uint8 m64ext) {
  if (addr.is64bitDisp())
    throw Error(ERR_CANT_USE_64BIT_DISP);
  uint8 code =
      addr.isBit(16) ? m16 : addr.isBit(32) ? m32 : addr.isBit(64) ? m64 : 0;
  if (!code)
    throw Error(ERR_BAD_MEM_SIZE);
  if (m64ext && addr.isBit(64))
    ext = m64ext;

  rex(addr, st0);
  db(code);
  opAddr(addr, ext);
}

void Xbyak::CodeGenerator::opFpuFpu(const Fpu &reg1, const Fpu &reg2,
                                    uint32 code1, uint32 code2) {
  uint32 code = reg1.getIdx() == 0 ? code1 : reg2.getIdx() == 0 ? code2 : 0;
  if (!code)
    throw Error(ERR_BAD_ST_COMBINATION);
  db(uint8(code >> 8));
  db(uint8(code | (reg1.getIdx() | reg2.getIdx())));
}

void Xbyak::CodeGenerator::opAddr(const Address &addr, int reg, int immSize,
                                  int disp8N, bool permitVisb) {
  if (!permitVisb && addr.isVsib())
    throw Error(ERR_BAD_VSIB_ADDRESSING);
  if (addr.getMode() == Address::M_ModRM) {
    setSIB(addr.getRegExp(), reg, disp8N);
  } else if (addr.getMode() == Address::M_rip ||
             addr.getMode() == Address::M_ripAddr) {
    setModRM(0, reg, 5);
    if (addr.getLabel()) { // [rip + Label]
      putL_inner(*addr.getLabel(), true, addr.getDisp() - immSize);
    } else {
      size_t disp = addr.getDisp();
      if (addr.getMode() == Address::M_ripAddr) {
        if (isAutoGrow())
          throw Error(ERR_INVALID_RIP_IN_AUTO_GROW);
        disp -= (size_t)getCurr() + 4 + immSize;
      }
      Xbyak::CodeArray::dd(inner::VerifyInInt32(disp));
    }
  }
}

void Xbyak::CodeGenerator::opGen(const Operand &reg, const Operand &op,
                                 int code, int pref,
                                 bool isValid(const Operand &, const Operand &),
                                 int imm8, int preCode) {
  if (isValid && !isValid(reg, op))
    throw Error(ERR_BAD_COMBINATION);
  if (pref != NONE)
    db(pref);
  if (op.isMEM()) {
    opModM(op.getAddress(), reg.getReg(), 0x0F, preCode, code,
           (imm8 != NONE) ? 1 : 0);
  } else {
    opModR(reg.getReg(), op.getReg(), 0x0F, preCode, code);
  }
  if (imm8 != NONE)
    db(imm8);
}

void Xbyak::CodeGenerator::setSIB(const RegExp &e, int reg, int disp8N) {
  size_t disp64 = e.getDisp();
#ifdef XBYAK64
  size_t high = disp64 >> 32;
  if (high != 0 && high != 0xFFFFFFFF)
    throw Error(ERR_OFFSET_IS_TOO_BIG);
#endif
  uint32 disp = static_cast<uint32>(disp64);
  const Reg &base = e.getBase();
  const Reg &index = e.getIndex();
  const int baseIdx = base.getIdx();
  const int baseBit = base.getBit();
  const int indexBit = index.getBit();
  enum { mod00 = 0, mod01 = 1, mod10 = 2 };
  int mod = mod10; // disp32
  if (!baseBit || ((baseIdx & 7) != Operand::EBP && disp == 0)) {
    mod = mod00;
  } else {
    if (disp8N == 0) {
      if (inner::IsInDisp8(disp)) {
        mod = mod01;
      }
    } else {
      // disp must be casted to signed
      uint32 t = static_cast<uint32>(static_cast<int>(disp) / disp8N);
      if ((disp % disp8N) == 0 && inner::IsInDisp8(t)) {
        disp = t;
        mod = mod01;
      }
    }
  }
  const int newBaseIdx = baseBit ? (baseIdx & 7) : Operand::EBP;
  /* ModR/M = [2:3:3] = [Mod:reg/code:R/M] */
  bool hasSIB = indexBit || (baseIdx & 7) == Operand::ESP;
#ifdef XBYAK64
  if (!baseBit && !indexBit)
    hasSIB = true;
#endif
  if (hasSIB) {
    setModRM(mod, reg, Operand::ESP);
    /* SIB = [2:3:3] = [SS:index:base(=rm)] */
    const int idx = indexBit ? (index.getIdx() & 7) : Operand::ESP;
    const int scale = e.getScale();
    const int SS = (scale == 8) ? 3 : (scale == 4) ? 2 : (scale == 2) ? 1 : 0;
    setModRM(SS, idx, newBaseIdx);
  } else {
    setModRM(mod, reg, newBaseIdx);
  }
  if (mod == mod01) {
    db(disp);
  } else if (mod == mod10 || (mod == mod00 && !baseBit)) {
    Xbyak::CodeArray::dd(disp);
  }
}

void Xbyak::CodeGenerator::opJmpAbs(const void *addr,
                                    Xbyak::CodeGenerator::LabelType type,
                                    uint8 shortCode, uint8 longCode,
                                    uint8 longPref) {
  UNIMPLEMENTED;
}

void Xbyak::CodeGenerator::opFpu(const Fpu &reg, uint8 code1, uint8 code2) {
  UNIMPLEMENTED;
}

void Xbyak::CodeGenerator::opVex(const Reg &r, const Operand *p1,
                                 const Operand &op2, int type, int code,
                                 int imm8) {
  if (op2.isMEM()) {
    const Address &addr = op2.getAddress();
    const RegExp &regExp = addr.getRegExp();
    const Reg &base = regExp.getBase();
    const Reg &index = regExp.getIndex();
    if (BIT == 64 && addr.is32bit())
      db(0x67);
    int disp8N = 0;
    bool x = index.isExtIdx();
    if ((type & (T_MUST_EVEX | T_MEM_EVEX)) || r.hasEvex() ||
        (p1 && p1->hasEvex()) || addr.isBroadcast() || addr.getOpmaskIdx()) {
      int aaa = addr.getOpmaskIdx();
      if (aaa && !(type & T_M_K))
        throw Error(ERR_INVALID_OPMASK_WITH_MEMORY);
      bool b = false;
      if (addr.isBroadcast()) {
        if (!(type & (T_B32 | T_B64)))
          throw Error(ERR_INVALID_BROADCAST);
        b = true;
      }
      int VL = regExp.isVsib() ? index.getBit() : 0;
      disp8N = evex(r, base, p1, type, code, x, b, aaa, VL, index.isExtIdx2());
    } else {
      vex(r, base, p1, type, code, x);
    }
    opAddr(addr, r.getIdx(), (imm8 != NONE) ? 1 : 0, disp8N,
           (type & T_VSIB) != 0);
  } else {
    const Reg &base = op2.getReg();
    if ((type & T_MUST_EVEX) || r.hasEvex() || (p1 && p1->hasEvex()) ||
        base.hasEvex()) {
      evex(r, base, p1, type, code);
    } else {
      vex(r, base, p1, type, code);
    }
    setModRM(3, r.getIdx(), base.getIdx());
  }
  if (imm8 != NONE)
    db(imm8);
}

void Xbyak::CodeGenerator::opGpr(const Reg32e &r, const Operand &op1,
                                 const Operand &op2, int type, uint8 code,
                                 bool isR_R_RM, int imm8) {
  const Operand *p1 = &op1;
  const Operand *p2 = &op2;
  if (!isR_R_RM)
    std::swap(p1, p2);
  const unsigned int bit = r.getBit();
  if (p1->getBit() != bit || (p2->isREG() && p2->getBit() != bit))
    throw Error(ERR_BAD_COMBINATION);
  type |= (bit == 64) ? T_W1 : T_W0;
  opVex(r, p1, *p2, type, code, imm8);
}

void Xbyak::CodeGenerator::opAVX_X_X_XM(const Xmm &x1, const Operand &op1,
                                        const Operand &op2, int type, int code0,
                                        int imm8) {
  const Xmm *x2 = static_cast<const Xmm *>(&op1);
  const Operand *op = &op2;
  if (op2.isNone()) { // (x1, op1) -> (x1, x1, op1)
    x2 = &x1;
    op = &op1;
  }
  // (x1, x2, op)
  if (!((x1.isXMM() && x2->isXMM()) ||
        ((type & T_YMM) &&
         ((x1.isYMM() && x2->isYMM()) || (x1.isZMM() && x2->isZMM())))))
    throw Error(ERR_BAD_COMBINATION);
  opVex(x1, x2, *op, type, code0, imm8);
}

void Xbyak::CodeGenerator::jmp(std::string label, LabelType type) {
  UNIMPLEMENTED;
}

void Xbyak::CodeGenerator::call(std::string label) { UNIMPLEMENTED; }

void Xbyak::CodeGenerator::call(const Label &label) { UNIMPLEMENTED; }

void Xbyak::CodeGenerator::mov(const NativeReg &reg,
                               const char *label) // can't use std::string
{
  if (label == 0) {
    mov(static_cast<const Operand &>(reg), 0); // call imm
    return;
  }
  UNIMPLEMENTED;
}

void Xbyak::CodeGenerator::mov(const NativeReg &reg, const Label &label) {
  /* Unimplemented */
  xa_->adr(xa::XReg(reg.getIdx()), label);
}

void Xbyak::CodeGenerator::xchg(const Operand &op1, const Operand &op2) {
  const Operand *p1 = &op1, *p2 = &op2;
  if (p1->isMEM() || (p2->isREG(16 | i32e) && p2->getIdx() == 0)) {
    p1 = &op2;
    p2 = &op1;
  }
  if (p1->isMEM())
    throw Error(ERR_BAD_COMBINATION);
  if (p2->isREG() && (p1->isREG(16 | i32e) && p1->getIdx() == 0)
#ifdef XBYAK64
      && (p2->getIdx() != 0 || !p1->isREG(32))
#endif
  ) {
    rex(*p2, *p1);
    db(0x90 | (p2->getIdx() & 7));
    decodeAndTransToAArch64();
    return;
  }
  opModRM(*p1, *p2,
          (p1->isREG() && p2->isREG() && (p1->getBit() == p2->getBit())),
          p2->isMEM(), 0x86 | (p1->isBit(8) ? 0 : 1));
  decodeAndTransToAArch64();
}
