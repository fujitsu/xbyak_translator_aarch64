void Xbyak::CodeGenerator::adc(const Operand &op, uint32 imm) {
  opRM_I(op, imm, 0x10, 2);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::adc(const Operand &op1, const Operand &op2) {
  opRM_RM(op1, op2, 0x10);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::adcx(const Reg32e &reg, const Operand &op) {
  opGen(reg, op, 0xF6, 0x66, isREG32_REG32orMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::add(const Operand &op, uint32 imm) {
  opRM_I(op, imm, 0x00, 0);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::add(const Operand &op1, const Operand &op2) {
  opRM_RM(op1, op2, 0x00);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::addpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x58, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::addps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x58, 0x100, isXMM_XMMorMEM);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::addsd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x58, 0xF2, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::addss(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x58, 0xF3, isXMM_XMMorMEM);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::addsubpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xD0, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::addsubps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xD0, 0xF2, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::adox(const Reg32e &reg, const Operand &op) {
  opGen(reg, op, 0xF6, 0xF3, isREG32_REG32orMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::aesdec(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xDE, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::aesdeclast(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xDF, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::aesenc(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xDC, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::aesenclast(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xDD, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::aesimc(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xDB, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::aeskeygenassist(const Xmm &xmm, const Operand &op,
                                           uint8 imm) {
  opGen(xmm, op, 0xDF, 0x66, isXMM_XMMorMEM, imm, 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::and_(const Operand &op, uint32 imm) {
  opRM_I(op, imm, 0x20, 4);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::and_(const Operand &op1, const Operand &op2) {
  opRM_RM(op1, op2, 0x20);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::andn(const Reg32e &r1, const Reg32e &r2,
                                const Operand &op) {
  opGpr(r1, r2, op, T_0F38, 0xf2, true);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::andnpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x55, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::andnps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x55, 0x100, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::andpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x54, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::andps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x54, 0x100, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bextr(const Reg32e &r1, const Operand &op,
                                 const Reg32e &r2) {
  opGpr(r1, op, r2, T_0F38, 0xf7, false);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::blendpd(const Xmm &xmm, const Operand &op, int imm) {
  opGen(xmm, op, 0x0D, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::blendps(const Xmm &xmm, const Operand &op, int imm) {
  opGen(xmm, op, 0x0C, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::blendvpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x15, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::blendvps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x14, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::blsi(const Reg32e &r, const Operand &op) {
  opGpr(Reg32e(3, r.getBit()), op, r, T_0F38, 0xf3, false);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::blsmsk(const Reg32e &r, const Operand &op) {
  opGpr(Reg32e(2, r.getBit()), op, r, T_0F38, 0xf3, false);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::blsr(const Reg32e &r, const Operand &op) {
  opGpr(Reg32e(1, r.getBit()), op, r, T_0F38, 0xf3, false);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bnd() {
  db(0xF2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bndcl(const BoundsReg &bnd, const Operand &op) {
  db(0xF3);
  opR_ModM(op, i32e, bnd.getIdx(), 0x0F, 0x1A, NONE, !op.isMEM());
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bndcn(const BoundsReg &bnd, const Operand &op) {
  db(0xF2);
  opR_ModM(op, i32e, bnd.getIdx(), 0x0F, 0x1B, NONE, !op.isMEM());
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bndcu(const BoundsReg &bnd, const Operand &op) {
  db(0xF2);
  opR_ModM(op, i32e, bnd.getIdx(), 0x0F, 0x1A, NONE, !op.isMEM());
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bndldx(const BoundsReg &bnd, const Address &addr) {
  opMIB(addr, bnd, 0x0F, 0x1A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bndmk(const BoundsReg &bnd, const Address &addr) {
  db(0xF3);
  opModM(addr, bnd, 0x0F, 0x1B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bndmov(const Address &addr, const BoundsReg &bnd) {
  db(0x66);
  opModM(addr, bnd, 0x0F, 0x1B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bndmov(const BoundsReg &bnd, const Operand &op) {
  db(0x66);
  opModRM(bnd, op, op.isBNDREG(), op.isMEM(), 0x0F, 0x1A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bndstx(const Address &addr, const BoundsReg &bnd) {
  opMIB(addr, bnd, 0x0F, 0x1B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bsf(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0xBC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bsr(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0xBD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bswap(const Reg32e &reg) {
  opModR(Reg32(1), reg, 0x0F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bt(const Operand &op, const Reg &reg) {
  opModRM(reg, op, op.isREG(16 | 32 | 64) && op.getBit() == reg.getBit(),
          op.isMEM(), 0x0f, 0xA3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bt(const Operand &op, uint8 imm) {
  opR_ModM(op, 16 | 32 | 64, 4, 0x0f, 0xba, NONE, false, 1);
  db(imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::btc(const Operand &op, const Reg &reg) {
  opModRM(reg, op, op.isREG(16 | 32 | 64) && op.getBit() == reg.getBit(),
          op.isMEM(), 0x0f, 0xBB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::btc(const Operand &op, uint8 imm) {
  opR_ModM(op, 16 | 32 | 64, 7, 0x0f, 0xba, NONE, false, 1);
  db(imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::btr(const Operand &op, const Reg &reg) {
  opModRM(reg, op, op.isREG(16 | 32 | 64) && op.getBit() == reg.getBit(),
          op.isMEM(), 0x0f, 0xB3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::btr(const Operand &op, uint8 imm) {
  opR_ModM(op, 16 | 32 | 64, 6, 0x0f, 0xba, NONE, false, 1);
  db(imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bts(const Operand &op, const Reg &reg) {
  opModRM(reg, op, op.isREG(16 | 32 | 64) && op.getBit() == reg.getBit(),
          op.isMEM(), 0x0f, 0xAB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bts(const Operand &op, uint8 imm) {
  opR_ModM(op, 16 | 32 | 64, 5, 0x0f, 0xba, NONE, false, 1);
  db(imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::bzhi(const Reg32e &r1, const Operand &op,
                                const Reg32e &r2) {
  opGpr(r1, op, r2, T_0F38, 0xf5, false);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cbw() {
  db(0x66);
  db(0x98);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cdq() {
  db(0x99);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::clc() {
  db(0xF8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cld() {
  db(0xFC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::clflush(const Address &addr) {
  opModM(addr, Reg32(7), 0x0F, 0xAE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::clflushopt(const Address &addr) {
  db(0x66);
  opModM(addr, Reg32(7), 0x0F, 0xAE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cli() {
  db(0xFA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::clzero() {
  db(0x0F);
  db(0x01);
  db(0xFC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmc() {
  db(0xF5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmova(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 7);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovae(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 3);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovb(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 2);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovbe(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 6);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovc(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 2);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmove(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 4);
  decodeAndTransToAArch64();
} //-V524
void Xbyak::CodeGenerator::cmovg(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 15);
  decodeAndTransToAArch64();
} //-V524
void Xbyak::CodeGenerator::cmovge(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 13);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovl(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 12);
  decodeAndTransToAArch64();
} //-V524
void Xbyak::CodeGenerator::cmovle(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 14);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovna(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 6);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovnae(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 2);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovnb(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 3);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovnbe(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 7);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovnc(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 3);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovne(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 5);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovng(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 14);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovnge(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 12);
  decodeAndTransToAArch64();
} //-V524
void Xbyak::CodeGenerator::cmovnl(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 13);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovnle(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 15);
  decodeAndTransToAArch64();
} //-V524
void Xbyak::CodeGenerator::cmovno(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 1);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovnp(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 11);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovns(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 9);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovnz(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 5);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovo(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 0);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovp(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 10);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovpe(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 10);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovpo(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 11);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovs(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 8);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::cmovz(const Reg &reg, const Operand &op) {
  opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 4);
  decodeAndTransToAArch64();
} //-V524
void Xbyak::CodeGenerator::cmp(const Operand &op, uint32 imm) {
  opRM_I(op, imm, 0x38, 7);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::cmp(const Operand &op1, const Operand &op2) {
  opRM_RM(op1, op2, 0x38);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::cmpeqpd(const Xmm &x, const Operand &op) {
  cmppd(x, op, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpeqps(const Xmm &x, const Operand &op) {
  cmpps(x, op, 0); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::cmpeqsd(const Xmm &x, const Operand &op) {
  cmpsd(x, op, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpeqss(const Xmm &x, const Operand &op) {
  cmpss(x, op, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmplepd(const Xmm &x, const Operand &op) {
  cmppd(x, op, 2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpleps(const Xmm &x, const Operand &op) {
  cmpps(x, op, 2); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::cmplesd(const Xmm &x, const Operand &op) {
  cmpsd(x, op, 2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpless(const Xmm &x, const Operand &op) {
  cmpss(x, op, 2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpltpd(const Xmm &x, const Operand &op) {
  cmppd(x, op, 1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpltps(const Xmm &x, const Operand &op) {
  cmpps(x, op, 1); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::cmpltsd(const Xmm &x, const Operand &op) {
  cmpsd(x, op, 1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpltss(const Xmm &x, const Operand &op) {
  cmpss(x, op, 1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpneqpd(const Xmm &x, const Operand &op) {
  cmppd(x, op, 4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpneqps(const Xmm &x, const Operand &op) {
  cmpps(x, op, 4); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::cmpneqsd(const Xmm &x, const Operand &op) {
  cmpsd(x, op, 4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpneqss(const Xmm &x, const Operand &op) {
  cmpss(x, op, 4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpnlepd(const Xmm &x, const Operand &op) {
  cmppd(x, op, 6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpnleps(const Xmm &x, const Operand &op) {
  cmpps(x, op, 6); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::cmpnlesd(const Xmm &x, const Operand &op) {
  cmpsd(x, op, 6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpnless(const Xmm &x, const Operand &op) {
  cmpss(x, op, 6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpnltpd(const Xmm &x, const Operand &op) {
  cmppd(x, op, 5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpnltps(const Xmm &x, const Operand &op) {
  cmpps(x, op, 5); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::cmpnltsd(const Xmm &x, const Operand &op) {
  cmpsd(x, op, 5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpnltss(const Xmm &x, const Operand &op) {
  cmpss(x, op, 5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpordpd(const Xmm &x, const Operand &op) {
  cmppd(x, op, 7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpordps(const Xmm &x, const Operand &op) {
  cmpps(x, op, 7); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::cmpordsd(const Xmm &x, const Operand &op) {
  cmpsd(x, op, 7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpordss(const Xmm &x, const Operand &op) {
  cmpss(x, op, 7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmppd(const Xmm &xmm, const Operand &op,
                                 uint8 imm8) {
  opGen(xmm, op, 0xC2, 0x66, isXMM_XMMorMEM, imm8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpps(const Xmm &xmm, const Operand &op,
                                 uint8 imm8) {
  opGen(xmm, op, 0xC2, 0x100, isXMM_XMMorMEM, imm8);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::cmpsb() {
  db(0xA6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpsd() {
  db(0xA7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpsd(const Xmm &xmm, const Operand &op,
                                 uint8 imm8) {
  opGen(xmm, op, 0xC2, 0xF2, isXMM_XMMorMEM, imm8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpss(const Xmm &xmm, const Operand &op,
                                 uint8 imm8) {
  opGen(xmm, op, 0xC2, 0xF3, isXMM_XMMorMEM, imm8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpsw() {
  db(0x66);
  db(0xA7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpunordpd(const Xmm &x, const Operand &op) {
  cmppd(x, op, 3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpunordps(const Xmm &x, const Operand &op) {
  cmpps(x, op, 3); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::cmpunordsd(const Xmm &x, const Operand &op) {
  cmpsd(x, op, 3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpunordss(const Xmm &x, const Operand &op) {
  cmpss(x, op, 3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpxchg(const Operand &op, const Reg &reg) {
  opModRM(reg, op, (op.isREG() && reg.isREG() && op.getBit() == reg.getBit()),
          op.isMEM(), 0x0F, 0xB0 | (reg.isBit(8) ? 0 : 1));
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpxchg8b(const Address &addr) {
  opModM(addr, Reg32(1), 0x0F, 0xC7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::comisd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x2F, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::comiss(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x2F, 0x100, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cpuid() {
  db(0x0F);
  db(0xA2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::crc32(const Reg32e &reg, const Operand &op) {
  if (reg.isBit(32) && op.isBit(16))
    db(0x66);
  db(0xF2);
  opModRM(reg, op, op.isREG(), op.isMEM(), 0x0F, 0x38,
          0xF0 | (op.isBit(8) ? 0 : 1));
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvtdq2pd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xE6, 0xF3, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvtdq2ps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5B, 0x100, isXMM_XMMorMEM);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::cvtpd2dq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xE6, 0xF2, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvtpd2pi(const Operand &reg, const Operand &op) {
  opGen(reg, op, 0x2D, 0x66, isMMX_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvtpd2ps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5A, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvtpi2pd(const Operand &reg, const Operand &op) {
  opGen(reg, op, 0x2A, 0x66, isXMM_MMXorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvtpi2ps(const Operand &reg, const Operand &op) {
  opGen(reg, op, 0x2A, 0x100, isXMM_MMXorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvtps2dq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5B, 0x66, isXMM_XMMorMEM);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::cvtps2pd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5A, 0x100, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvtps2pi(const Operand &reg, const Operand &op) {
  opGen(reg, op, 0x2D, 0x100, isMMX_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvtsd2si(const Operand &reg, const Operand &op) {
  opGen(reg, op, 0x2D, 0xF2, isREG32_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvtsd2ss(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5A, 0xF2, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvtsi2sd(const Operand &reg, const Operand &op) {
  opGen(reg, op, 0x2A, 0xF2, isXMM_REG32orMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvtsi2ss(const Operand &reg, const Operand &op) {
  opGen(reg, op, 0x2A, 0xF3, isXMM_REG32orMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvtss2sd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5A, 0xF3, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvtss2si(const Operand &reg, const Operand &op) {
  opGen(reg, op, 0x2D, 0xF3, isREG32_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvttpd2dq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xE6, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvttpd2pi(const Operand &reg, const Operand &op) {
  opGen(reg, op, 0x2C, 0x66, isMMX_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvttps2dq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5B, 0xF3, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvttps2pi(const Operand &reg, const Operand &op) {
  opGen(reg, op, 0x2C, 0x100, isMMX_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvttsd2si(const Operand &reg, const Operand &op) {
  opGen(reg, op, 0x2C, 0xF2, isREG32_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cvttss2si(const Operand &reg, const Operand &op) {
  opGen(reg, op, 0x2C, 0xF3, isREG32_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cwd() {
  db(0x66);
  db(0x99);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cwde() {
  db(0x98);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::dec(const Operand &op) {
  opIncDec(op, 0x48, 1);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::div(const Operand &op) {
  opR_ModM(op, 0, 6, 0xF6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::divpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5E, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::divps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5E, 0x100, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::divsd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5E, 0xF2, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::divss(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5E, 0xF3, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::dppd(const Xmm &xmm, const Operand &op, int imm) {
  opGen(xmm, op, 0x41, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::dpps(const Xmm &xmm, const Operand &op, int imm) {
  opGen(xmm, op, 0x40, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::emms() {
  db(0x0F);
  db(0x77);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::enter(uint16 x, uint8 y) {
  Xbyak::CodeArray::db(0xC8);
  Xbyak::CodeArray::dw(x);
  Xbyak::CodeArray::db(y);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::extractps(const Operand &op, const Xmm &xmm,
                                     uint8 imm) {
  opExt(op, xmm, 0x17, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::f2xm1() {
  db(0xD9);
  db(0xF0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fabs() {
  db(0xD9);
  db(0xE1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fadd(const Address &addr) {
  opFpuMem(addr, 0x00, 0xD8, 0xDC, 0, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fadd(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xD8C0, 0xDCC0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fadd(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xD8C0, 0xDCC0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::faddp() {
  db(0xDE);
  db(0xC1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::faddp(const Fpu &reg1) {
  opFpuFpu(reg1, st0, 0x0000, 0xDEC0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::faddp(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0x0000, 0xDEC0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fbld(const Address &addr) {
  opModM(addr, Reg32(4), 0xDF, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fbstp(const Address &addr) {
  opModM(addr, Reg32(6), 0xDF, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fchs() {
  db(0xD9);
  db(0xE0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fclex() {
  db(0x9B);
  db(0xDB);
  db(0xE2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmovb(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xDAC0, 0x00C0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmovb(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xDAC0, 0x00C0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmovbe(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xDAD0, 0x00D0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmovbe(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xDAD0, 0x00D0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmove(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xDAC8, 0x00C8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmove(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xDAC8, 0x00C8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmovnb(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xDBC0, 0x00C0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmovnb(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xDBC0, 0x00C0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmovnbe(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xDBD0, 0x00D0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmovnbe(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xDBD0, 0x00D0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmovne(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xDBC8, 0x00C8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmovne(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xDBC8, 0x00C8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmovnu(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xDBD8, 0x00D8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmovnu(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xDBD8, 0x00D8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmovu(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xDAD8, 0x00D8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcmovu(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xDAD8, 0x00D8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcom() {
  db(0xD8);
  db(0xD1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcom(const Address &addr) {
  opFpuMem(addr, 0x00, 0xD8, 0xDC, 2, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcom(const Fpu &reg) {
  opFpu(reg, 0xD8, 0xD0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcomi(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xDBF0, 0x00F0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcomi(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xDBF0, 0x00F0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcomip(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xDFF0, 0x00F0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcomip(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xDFF0, 0x00F0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcomp() {
  db(0xD8);
  db(0xD9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcomp(const Address &addr) {
  opFpuMem(addr, 0x00, 0xD8, 0xDC, 3, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcomp(const Fpu &reg) {
  opFpu(reg, 0xD8, 0xD8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcompp() {
  db(0xDE);
  db(0xD9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fcos() {
  db(0xD9);
  db(0xFF);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fdecstp() {
  db(0xD9);
  db(0xF6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fdiv(const Address &addr) {
  opFpuMem(addr, 0x00, 0xD8, 0xDC, 6, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fdiv(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xD8F0, 0xDCF8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fdiv(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xD8F0, 0xDCF8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fdivp() {
  db(0xDE);
  db(0xF9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fdivp(const Fpu &reg1) {
  opFpuFpu(reg1, st0, 0x0000, 0xDEF8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fdivp(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0x0000, 0xDEF8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fdivr(const Address &addr) {
  opFpuMem(addr, 0x00, 0xD8, 0xDC, 7, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fdivr(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xD8F8, 0xDCF0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fdivr(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xD8F8, 0xDCF0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fdivrp() {
  db(0xDE);
  db(0xF1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fdivrp(const Fpu &reg1) {
  opFpuFpu(reg1, st0, 0x0000, 0xDEF0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fdivrp(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0x0000, 0xDEF0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ffree(const Fpu &reg) {
  opFpu(reg, 0xDD, 0xC0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fiadd(const Address &addr) {
  opFpuMem(addr, 0xDE, 0xDA, 0x00, 0, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ficom(const Address &addr) {
  opFpuMem(addr, 0xDE, 0xDA, 0x00, 2, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ficomp(const Address &addr) {
  opFpuMem(addr, 0xDE, 0xDA, 0x00, 3, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fidiv(const Address &addr) {
  opFpuMem(addr, 0xDE, 0xDA, 0x00, 6, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fidivr(const Address &addr) {
  opFpuMem(addr, 0xDE, 0xDA, 0x00, 7, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fild(const Address &addr) {
  opFpuMem(addr, 0xDF, 0xDB, 0xDF, 0, 5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fimul(const Address &addr) {
  opFpuMem(addr, 0xDE, 0xDA, 0x00, 1, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fincstp() {
  db(0xD9);
  db(0xF7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::finit() {
  db(0x9B);
  db(0xDB);
  db(0xE3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fist(const Address &addr) {
  opFpuMem(addr, 0xDF, 0xDB, 0x00, 2, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fistp(const Address &addr) {
  opFpuMem(addr, 0xDF, 0xDB, 0xDF, 3, 7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fisttp(const Address &addr) {
  opFpuMem(addr, 0xDF, 0xDB, 0xDD, 1, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fisub(const Address &addr) {
  opFpuMem(addr, 0xDE, 0xDA, 0x00, 4, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fisubr(const Address &addr) {
  opFpuMem(addr, 0xDE, 0xDA, 0x00, 5, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fld(const Address &addr) {
  opFpuMem(addr, 0x00, 0xD9, 0xDD, 0, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fld(const Fpu &reg) {
  opFpu(reg, 0xD9, 0xC0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fld1() {
  db(0xD9);
  db(0xE8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fldcw(const Address &addr) {
  opModM(addr, Reg32(5), 0xD9, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fldenv(const Address &addr) {
  opModM(addr, Reg32(4), 0xD9, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fldl2e() {
  db(0xD9);
  db(0xEA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fldl2t() {
  db(0xD9);
  db(0xE9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fldlg2() {
  db(0xD9);
  db(0xEC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fldln2() {
  db(0xD9);
  db(0xED);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fldpi() {
  db(0xD9);
  db(0xEB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fldz() {
  db(0xD9);
  db(0xEE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fmul(const Address &addr) {
  opFpuMem(addr, 0x00, 0xD8, 0xDC, 1, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fmul(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xD8C8, 0xDCC8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fmul(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xD8C8, 0xDCC8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fmulp() {
  db(0xDE);
  db(0xC9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fmulp(const Fpu &reg1) {
  opFpuFpu(reg1, st0, 0x0000, 0xDEC8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fmulp(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0x0000, 0xDEC8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fnclex() {
  db(0xDB);
  db(0xE2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fninit() {
  db(0xDB);
  db(0xE3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fnop() {
  db(0xD9);
  db(0xD0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fnsave(const Address &addr) {
  opModM(addr, Reg32(6), 0xDD, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fnstcw(const Address &addr) {
  opModM(addr, Reg32(7), 0xD9, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fnstenv(const Address &addr) {
  opModM(addr, Reg32(6), 0xD9, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fnstsw(const Address &addr) {
  opModM(addr, Reg32(7), 0xDD, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fnstsw(const Reg16 &r) {
  if (r.getIdx() != Operand::AX)
    throw Error(ERR_BAD_PARAMETER);
  db(0xDF);
  db(0xE0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fpatan() {
  db(0xD9);
  db(0xF3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fprem() {
  db(0xD9);
  db(0xF8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fprem1() {
  db(0xD9);
  db(0xF5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fptan() {
  db(0xD9);
  db(0xF2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::frndint() {
  db(0xD9);
  db(0xFC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::frstor(const Address &addr) {
  opModM(addr, Reg32(4), 0xDD, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsave(const Address &addr) {
  db(0x9B);
  opModM(addr, Reg32(6), 0xDD, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fscale() {
  db(0xD9);
  db(0xFD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsin() {
  db(0xD9);
  db(0xFE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsincos() {
  db(0xD9);
  db(0xFB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsqrt() {
  db(0xD9);
  db(0xFA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fst(const Address &addr) {
  opFpuMem(addr, 0x00, 0xD9, 0xDD, 2, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fst(const Fpu &reg) {
  opFpu(reg, 0xDD, 0xD0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fstcw(const Address &addr) {
  db(0x9B);
  opModM(addr, Reg32(7), 0xD9, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fstenv(const Address &addr) {
  db(0x9B);
  opModM(addr, Reg32(6), 0xD9, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fstp(const Address &addr) {
  opFpuMem(addr, 0x00, 0xD9, 0xDD, 3, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fstp(const Fpu &reg) {
  opFpu(reg, 0xDD, 0xD8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fstsw(const Address &addr) {
  db(0x9B);
  opModM(addr, Reg32(7), 0xDD, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fstsw(const Reg16 &r) {
  if (r.getIdx() != Operand::AX)
    throw Error(ERR_BAD_PARAMETER);
  db(0x9B);
  db(0xDF);
  db(0xE0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsub(const Address &addr) {
  opFpuMem(addr, 0x00, 0xD8, 0xDC, 4, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsub(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xD8E0, 0xDCE8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsub(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xD8E0, 0xDCE8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsubp() {
  db(0xDE);
  db(0xE9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsubp(const Fpu &reg1) {
  opFpuFpu(reg1, st0, 0x0000, 0xDEE8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsubp(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0x0000, 0xDEE8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsubr(const Address &addr) {
  opFpuMem(addr, 0x00, 0xD8, 0xDC, 5, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsubr(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xD8E8, 0xDCE0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsubr(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xD8E8, 0xDCE0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsubrp() {
  db(0xDE);
  db(0xE1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsubrp(const Fpu &reg1) {
  opFpuFpu(reg1, st0, 0x0000, 0xDEE0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fsubrp(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0x0000, 0xDEE0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ftst() {
  db(0xD9);
  db(0xE4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fucom() {
  db(0xDD);
  db(0xE1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fucom(const Fpu &reg) {
  opFpu(reg, 0xDD, 0xE0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fucomi(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xDBE8, 0x00E8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fucomi(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xDBE8, 0x00E8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fucomip(const Fpu &reg1) {
  opFpuFpu(st0, reg1, 0xDFE8, 0x00E8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fucomip(const Fpu &reg1, const Fpu &reg2) {
  opFpuFpu(reg1, reg2, 0xDFE8, 0x00E8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fucomp() {
  db(0xDD);
  db(0xE9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fucomp(const Fpu &reg) {
  opFpu(reg, 0xDD, 0xE8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fucompp() {
  db(0xDA);
  db(0xE9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fwait() {
  db(0x9B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fxam() {
  db(0xD9);
  db(0xE5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fxch() {
  db(0xD9);
  db(0xC9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fxch(const Fpu &reg) {
  opFpu(reg, 0xD9, 0xC8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fxrstor(const Address &addr) {
  opModM(addr, Reg32(1), 0x0F, 0xAE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fxtract() {
  db(0xD9);
  db(0xF4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fyl2x() {
  db(0xD9);
  db(0xF1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fyl2xp1() {
  db(0xD9);
  db(0xF9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::gf2p8affineinvqb(const Xmm &xmm, const Operand &op,
                                            int imm) {
  opGen(xmm, op, 0xCF, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::gf2p8affineqb(const Xmm &xmm, const Operand &op,
                                         int imm) {
  opGen(xmm, op, 0xCE, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::gf2p8mulb(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xCF, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::haddpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x7C, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::haddps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x7C, 0xF2, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::hsubpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x7D, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::hsubps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x7D, 0xF2, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::idiv(const Operand &op) {
  opR_ModM(op, 0, 7, 0xF6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::imul(const Operand &op) {
  opR_ModM(op, 0, 5, 0xF6);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::in_(const Reg &a, const Reg &d) {
  opInOut(a, d, 0xEC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::in_(const Reg &a, uint8 v) {
  opInOut(a, 0xE4, v);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::inc(const Operand &op) {
  opIncDec(op, 0x40, 0);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::insertps(const Xmm &xmm, const Operand &op,
                                    uint8 imm) {
  opGen(xmm, op, 0x21, 0x66, isXMM_XMMorMEM, imm, 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::int3() {
  db(0xCC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::int_(uint8 x) {
  db(0xCD);
  db(x);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ja(const Label &label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ja(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ja(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::ja(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jae(const Label &label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jae(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jae(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jae(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jb(const Label &label, LabelType type) {
  decodeAndTransToAArch64(X86_64_B, label);
}
void Xbyak::CodeGenerator::jb(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jb(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jb(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jbe(const Label &label, LabelType type) {
  decodeAndTransToAArch64(X86_64_BE, label);
}
void Xbyak::CodeGenerator::jbe(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jbe(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jbe(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jc(const Label &label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jc(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jc(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jc(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::je(const Label &label, LabelType type) {
  b(Xbyak_aarch64::EQ, label);
}
void Xbyak::CodeGenerator::je(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::je(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::je(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jg(const Label &label, LabelType type) {
  b(Xbyak_aarch64::GT, label);
}
void Xbyak::CodeGenerator::jg(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jg(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jg(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jge(const Label &label, LabelType type) {
  b(Xbyak_aarch64::GE, label);
}
void Xbyak::CodeGenerator::jge(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jge(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jge(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jl(const Label &label, LabelType type) {
  b(Xbyak_aarch64::LT, label);
}
void Xbyak::CodeGenerator::jl(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jl(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jl(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jle(const Label &label, LabelType type) {
  b(Xbyak_aarch64::LE, label);
}
void Xbyak::CodeGenerator::jle(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jle(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jle(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jna(const Label &label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jna(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jna(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jna(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnae(const Label &label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnae(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnae(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jnae(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnb(const Label &label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnb(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnb(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jnb(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnbe(const Label &label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnbe(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnbe(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jnbe(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnc(const Label &label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnc(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnc(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jnc(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jne(const Label &label, LabelType type) {
  b(Xbyak_aarch64::NE, label);
}
void Xbyak::CodeGenerator::jne(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jne(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jne(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jng(const Label &label, LabelType type) {
  b(Xbyak_aarch64::LE, label);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jng(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jng(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jng(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnge(const Label &label, LabelType type) {
  b(Xbyak_aarch64::LT, label);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnge(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnge(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jnge(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnl(const Label &label, LabelType type) {
  b(Xbyak_aarch64::GE, label);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnl(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnl(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jnl(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnle(const Label &label, LabelType type) {
  b(Xbyak_aarch64::GT, label);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnle(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnle(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jnle(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jno(const Label &label, LabelType type) {
  b(Xbyak_aarch64::VC, label);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jno(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jno(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jno(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnp(const Label &label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnp(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnp(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jnp(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jns(const Label &label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jns(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jns(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jns(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnz(const Label &label, LabelType type) {
  b(Xbyak_aarch64::NE, label);
}
void Xbyak::CodeGenerator::jnz(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jnz(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jnz(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jo(const Label &label, LabelType type) {
  b(Xbyak_aarch64::VS, label);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jo(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jo(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jo(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
/* Does AArch64 has parity flag? */
void Xbyak::CodeGenerator::jp(const Label &label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jp(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jp(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jp(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jpe(const Label &label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jpe(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jpe(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jpe(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jpo(const Label &label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jpo(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jpo(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jpo(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::js(const Label &label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::js(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::js(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::js(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
/* AArch64 CPU has no zero flag jmp instruction. */
void Xbyak::CodeGenerator::jz(const Label &label, LabelType type) {
  b(Xbyak_aarch64::EQ, label);
}
void Xbyak::CodeGenerator::jz(const char *label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jz(const void *addr) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jz(std::string label, LabelType type) {
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::lahf() {
  db(0x9F);
  std::cerr << "No support for LAHF instruction" << std::endl;
}
void Xbyak::CodeGenerator::lddqu(const Xmm &xmm, const Address &addr) {
  db(0xF2);
  opModM(addr, xmm, 0x0F, 0xF0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ldmxcsr(const Address &addr) {
  opModM(addr, Reg32(2), 0x0F, 0xAE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::lea(const Reg &reg, const Address &addr) {
  if (!reg.isBit(16 | i32e))
    throw Error(ERR_BAD_SIZE_OF_REGISTER);
  opModM(addr, reg, 0x8D);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::leave() {
  db(0xC9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::lfence() {
  db(0x0F);
  db(0xAE);
  db(0xE8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::lfs(const Reg &reg, const Address &addr) {
  opLoadSeg(addr, reg, 0x0F, 0xB4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::lgs(const Reg &reg, const Address &addr) {
  opLoadSeg(addr, reg, 0x0F, 0xB5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::lock() {
  db(0xF0); /* lock instruction is translated with the next instruction. */
}
void Xbyak::CodeGenerator::lodsb() {
  db(0xAC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::lodsd() {
  db(0xAD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::lodsw() {
  db(0x66);
  db(0xAD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::loop(const Label &label) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::loop(const char *label) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::loop(std::string label) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::loope(const Label &label) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::loope(const char *label) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::loope(std::string label) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::loopne(const Label &label) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::loopne(const char *label) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::loopne(std::string label) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::lss(const Reg &reg, const Address &addr) {
  opLoadSeg(addr, reg, 0x0F, 0xB2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::lzcnt(const Reg &reg, const Operand &op) {
  opSp1(reg, op, 0xF3, 0x0F, 0xBD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::maskmovdqu(const Xmm &reg1, const Xmm &reg2) {
  db(0x66);
  opModR(reg1, reg2, 0x0F, 0xF7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::maskmovq(const Mmx &reg1, const Mmx &reg2) {
  if (!reg1.isMMX() || !reg2.isMMX())
    throw Error(ERR_BAD_COMBINATION);
  opModR(reg1, reg2, 0x0F, 0xF7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::maxpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5F, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::maxps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5F, 0x100, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::maxsd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5F, 0xF2, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::maxss(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5F, 0xF3, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::mfence() {
  db(0x0F);
  db(0xAE);
  db(0xF0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::minpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5D, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::minps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5D, 0x100, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::minsd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5D, 0xF2, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::minss(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5D, 0xF3, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::monitor() {
  db(0x0F);
  db(0x01);
  db(0xC8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::monitorx() {
  db(0x0F);
  db(0x01);
  db(0xFA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movapd(const Address &addr, const Xmm &xmm) {
  db(0x66);
  opModM(addr, xmm, 0x0F, 0x29);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movapd(const Xmm &xmm, const Operand &op) {
  opMMX(xmm, op, 0x28, 0x66);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movaps(const Address &addr, const Xmm &xmm) {
  opModM(addr, xmm, 0x0F, 0x29);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movaps(const Xmm &xmm, const Operand &op) {
  opMMX(xmm, op, 0x28, 0x100);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movbe(const Address &addr, const Reg &reg) {
  opModM(addr, reg, 0x0F, 0x38, 0xF1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movbe(const Reg &reg, const Address &addr) {
  opModM(addr, reg, 0x0F, 0x38, 0xF0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movd(const Address &addr, const Mmx &mmx) {
  if (mmx.isXMM())
    db(0x66);
  opModM(addr, mmx, 0x0F, 0x7E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movd(const Mmx &mmx, const Address &addr) {
  if (mmx.isXMM())
    db(0x66);
  opModM(addr, mmx, 0x0F, 0x6E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movd(const Mmx &mmx, const Reg32 &reg) {
  if (mmx.isXMM())
    db(0x66);
  opModR(mmx, reg, 0x0F, 0x6E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movd(const Reg32 &reg, const Mmx &mmx) {
  if (mmx.isXMM())
    db(0x66);
  opModR(mmx, reg, 0x0F, 0x7E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movddup(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x12, 0xF2, isXMM_XMMorMEM, NONE, NONE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movdq2q(const Mmx &mmx, const Xmm &xmm) {
  db(0xF2);
  opModR(mmx, xmm, 0x0F, 0xD6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movdqa(const Address &addr, const Xmm &xmm) {
  db(0x66);
  opModM(addr, xmm, 0x0F, 0x7F);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movdqa(const Xmm &xmm, const Operand &op) {
  opMMX(xmm, op, 0x6F, 0x66);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movdqu(const Address &addr, const Xmm &xmm) {
  db(0xF3);
  opModM(addr, xmm, 0x0F, 0x7F);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movdqu(const Xmm &xmm, const Operand &op) {
  opMMX(xmm, op, 0x6F, 0xF3);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movhlps(const Xmm &reg1, const Xmm &reg2) {
  opModR(reg1, reg2, 0x0F, 0x12);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movhpd(const Operand &op1, const Operand &op2) {
  opMovXMM(op1, op2, 0x16, 0x66);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movhps(const Operand &op1, const Operand &op2) {
  opMovXMM(op1, op2, 0x16, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movlhps(const Xmm &reg1, const Xmm &reg2) {
  opModR(reg1, reg2, 0x0F, 0x16);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movlpd(const Operand &op1, const Operand &op2) {
  opMovXMM(op1, op2, 0x12, 0x66);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movlps(const Operand &op1, const Operand &op2) {
  opMovXMM(op1, op2, 0x12, 0x100);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movmskpd(const Reg32e &reg, const Xmm &xmm) {
  db(0x66);
  movmskps(reg, xmm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movmskps(const Reg32e &reg, const Xmm &xmm) {
  opModR(reg, xmm, 0x0F, 0x50);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movntdq(const Address &addr, const Xmm &reg) {
  opModM(addr, Reg16(reg.getIdx()), 0x0F, 0xE7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movntdqa(const Xmm &xmm, const Address &addr) {
  db(0x66);
  opModM(addr, xmm, 0x0F, 0x38, 0x2A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movnti(const Address &addr, const Reg32e &reg) {
  opModM(addr, reg, 0x0F, 0xC3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movntpd(const Address &addr, const Xmm &reg) {
  opModM(addr, Reg16(reg.getIdx()), 0x0F, 0x2B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movntps(const Address &addr, const Xmm &xmm) {
  opModM(addr, Mmx(xmm.getIdx()), 0x0F, 0x2B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movntq(const Address &addr, const Mmx &mmx) {
  if (!mmx.isMMX())
    throw Error(ERR_BAD_COMBINATION);
  opModM(addr, mmx, 0x0F, 0xE7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movq(const Address &addr, const Mmx &mmx) {
  if (mmx.isXMM())
    db(0x66);
  opModM(addr, mmx, 0x0F, mmx.isXMM() ? 0xD6 : 0x7F);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movq(const Mmx &mmx, const Operand &op) {
  if (mmx.isXMM())
    db(0xF3);
  opModRM(mmx, op, (mmx.getKind() == op.getKind()), op.isMEM(), 0x0F,
          mmx.isXMM() ? 0x7E : 0x6F);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movq2dq(const Xmm &xmm, const Mmx &mmx) {
  db(0xF3);
  opModR(xmm, mmx, 0x0F, 0xD6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movsb() {
  db(0xA4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movsd() {
  db(0xA5);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movsd(const Address &addr, const Xmm &xmm) {
  db(0xF2);
  opModM(addr, xmm, 0x0F, 0x11);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movsd(const Xmm &xmm, const Operand &op) {
  opMMX(xmm, op, 0x10, 0xF2);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movshdup(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x16, 0xF3, isXMM_XMMorMEM, NONE, NONE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movsldup(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x12, 0xF3, isXMM_XMMorMEM, NONE, NONE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movss(const Address &addr, const Xmm &xmm) {
  db(0xF3);
  opModM(addr, xmm, 0x0F, 0x11);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movss(const Xmm &xmm, const Operand &op) {
  opMMX(xmm, op, 0x10, 0xF3);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movsw() {
  db(0x66);
  db(0xA5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movsx(const Reg &reg, const Operand &op) {
  opMovxx(reg, op, 0xBE);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movupd(const Address &addr, const Xmm &xmm) {
  db(0x66);
  opModM(addr, xmm, 0x0F, 0x11);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movupd(const Xmm &xmm, const Operand &op) {
  opMMX(xmm, op, 0x10, 0x66);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movups(const Address &addr, const Xmm &xmm) {
  opModM(addr, xmm, 0x0F, 0x11);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movups(const Xmm &xmm, const Operand &op) {
  opMMX(xmm, op, 0x10, 0x100);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movzx(const Reg &reg, const Operand &op) {
  opMovxx(reg, op, 0xB6);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::mpsadbw(const Xmm &xmm, const Operand &op, int imm) {
  opGen(xmm, op, 0x42, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::mul(const Operand &op) {
  opR_ModM(op, 0, 4, 0xF6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::mulpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x59, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::mulps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x59, 0x100, isXMM_XMMorMEM);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::mulsd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x59, 0xF2, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::mulss(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x59, 0xF3, isXMM_XMMorMEM);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::mulx(const Reg32e &r1, const Reg32e &r2,
                                const Operand &op) {
  opGpr(r1, r2, op, T_F2 | T_0F38, 0xf6, true);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::mwait() {
  db(0x0F);
  db(0x01);
  db(0xC9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::mwaitx() {
  db(0x0F);
  db(0x01);
  db(0xFB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::neg(const Operand &op) {
  opR_ModM(op, 0, 3, 0xF6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::not_(const Operand &op) {
  opR_ModM(op, 0, 2, 0xF6);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::or_(const Operand &op, uint32 imm) {
  opRM_I(op, imm, 0x08, 1);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::or_(const Operand &op1, const Operand &op2) {
  opRM_RM(op1, op2, 0x08);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::orpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x56, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::orps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x56, 0x100, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::out_(const Reg &d, const Reg &a) {
  opInOut(a, d, 0xEE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::out_(uint8 v, const Reg &a) {
  opInOut(a, 0xE6, v);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::outsb() {
  db(0x6E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::outsd() {
  db(0x6F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::outsw() {
  db(0x66);
  db(0x6F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pabsb(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x1C, 0x66, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pabsd(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x1E, 0x66, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pabsw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x1D, 0x66, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::packssdw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x6B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::packsswb(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x63);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::packusdw(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x2B, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::packuswb(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x67);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::paddb(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xFC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::paddd(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xFE);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::paddq(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xD4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::paddsb(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xEC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::paddsw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xED);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::paddusb(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xDC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::paddusw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xDD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::paddw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xFD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::palignr(const Mmx &mmx, const Operand &op, int imm) {
  opMMX(mmx, op, 0x0f, 0x66, static_cast<uint8>(imm), 0x3a);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pand(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xDB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pandn(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xDF);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pause() {
  db(0xF3);
  db(0x90);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::pavgb(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xE0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pavgw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xE3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pblendvb(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x10, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pblendw(const Xmm &xmm, const Operand &op, int imm) {
  opGen(xmm, op, 0x0E, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pclmulhqhdq(const Xmm &xmm, const Operand &op) {
  pclmulqdq(xmm, op, 0x11);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pclmulhqlqdq(const Xmm &xmm, const Operand &op) {
  pclmulqdq(xmm, op, 0x01);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pclmullqhdq(const Xmm &xmm, const Operand &op) {
  pclmulqdq(xmm, op, 0x10);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pclmullqlqdq(const Xmm &xmm, const Operand &op) {
  pclmulqdq(xmm, op, 0x00);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pclmulqdq(const Xmm &xmm, const Operand &op,
                                     int imm) {
  opGen(xmm, op, 0x44, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pcmpeqb(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x74);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pcmpeqd(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x76);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pcmpeqq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x29, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pcmpeqw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x75);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pcmpestri(const Xmm &xmm, const Operand &op,
                                     uint8 imm) {
  opGen(xmm, op, 0x61, 0x66, isXMM_XMMorMEM, imm, 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pcmpestrm(const Xmm &xmm, const Operand &op,
                                     uint8 imm) {
  opGen(xmm, op, 0x60, 0x66, isXMM_XMMorMEM, imm, 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pcmpgtb(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x64);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pcmpgtd(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x66);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pcmpgtq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x37, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pcmpgtw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x65);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pcmpistri(const Xmm &xmm, const Operand &op,
                                     uint8 imm) {
  opGen(xmm, op, 0x63, 0x66, isXMM_XMMorMEM, imm, 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pcmpistrm(const Xmm &xmm, const Operand &op,
                                     uint8 imm) {
  opGen(xmm, op, 0x62, 0x66, isXMM_XMMorMEM, imm, 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pdep(const Reg32e &r1, const Reg32e &r2,
                                const Operand &op) {
  opGpr(r1, r2, op, T_F2 | T_0F38, 0xf5, true);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pext(const Reg32e &r1, const Reg32e &r2,
                                const Operand &op) {
  opGpr(r1, r2, op, T_F3 | T_0F38, 0xf5, true);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pextrb(const Operand &op, const Xmm &xmm,
                                  uint8 imm) {
  opExt(op, xmm, 0x14, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::pextrd(const Operand &op, const Xmm &xmm,
                                  uint8 imm) {
  opExt(op, xmm, 0x16, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::pextrw(const Operand &op, const Mmx &xmm,
                                  uint8 imm) {
  opExt(op, xmm, 0x15, imm, true);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::phaddd(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x02, 0x66, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::phaddsw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x03, 0x66, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::phaddw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x01, 0x66, NONE, 0x38);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::phminposuw(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x41, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::phsubd(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x06, 0x66, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::phsubsw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x07, 0x66, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::phsubw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x05, 0x66, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pinsrb(const Xmm &xmm, const Operand &op,
                                  uint8 imm) {
  opGen(xmm, op, 0x20, 0x66, isXMM_REG32orMEM, imm, 0x3A);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::pinsrd(const Xmm &xmm, const Operand &op,
                                  uint8 imm) {
  opGen(xmm, op, 0x22, 0x66, isXMM_REG32orMEM, imm, 0x3A);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::pinsrw(const Mmx &mmx, const Operand &op, int imm) {
  if (!op.isREG(32) && !op.isMEM())
    throw Error(ERR_BAD_COMBINATION);
  opGen(mmx, op, 0xC4, mmx.isXMM() ? 0x66 : NONE, 0, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::pmaddubsw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x04, 0x66, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmaddwd(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xF5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmaxsb(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x3C, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmaxsd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x3D, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmaxsw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xEE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmaxub(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xDE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmaxud(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x3F, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmaxuw(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x3E, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pminsb(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x38, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pminsd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x39, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pminsw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xEA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pminub(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xDA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pminud(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x3B, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pminuw(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x3A, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmovmskb(const Reg32e &reg, const Mmx &mmx) {
  if (mmx.isXMM())
    db(0x66);
  opModR(reg, mmx, 0x0F, 0xD7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmovsxbd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x21, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::pmovsxbq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x22, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmovsxbw(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x20, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::pmovsxdq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x25, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmovsxwd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x23, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::pmovsxwq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x24, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmovzxbd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x31, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::pmovzxbq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x32, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmovzxbw(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x30, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::pmovzxdq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x35, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmovzxwd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x33, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::pmovzxwq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x34, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmuldq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x28, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmulhrsw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x0B, 0x66, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmulhuw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xE4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmulhw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xE5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmulld(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x40, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmullw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xD5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pmuludq(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xF4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::popcnt(const Reg &reg, const Operand &op) {
  opSp1(reg, op, 0xF3, 0x0F, 0xB8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::popf() {
  db(0x9D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::por(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xEB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::prefetchnta(const Address &addr) {
  opModM(addr, Reg32(0), 0x0F, 0x18);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::prefetcht0(const Address &addr) {
  opModM(addr, Reg32(1), 0x0F, 0x18);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::prefetcht1(const Address &addr) {
  opModM(addr, Reg32(2), 0x0F, 0x18);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::prefetcht2(const Address &addr) {
  opModM(addr, Reg32(3), 0x0F, 0x18);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::prefetchw(const Address &addr) {
  opModM(addr, Reg32(1), 0x0F, 0x0D);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::prefetchwt1(const Address &addr) {
  opModM(addr, Reg32(2), 0x0F, 0x0D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psadbw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xF6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pshufb(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x00, 0x66, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pshufd(const Mmx &mmx, const Operand &op,
                                  uint8 imm8) {
  opMMX(mmx, op, 0x70, 0x66, imm8);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::pshufhw(const Mmx &mmx, const Operand &op,
                                   uint8 imm8) {
  opMMX(mmx, op, 0x70, 0xF3, imm8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pshuflw(const Mmx &mmx, const Operand &op,
                                   uint8 imm8) {
  opMMX(mmx, op, 0x70, 0xF2, imm8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pshufw(const Mmx &mmx, const Operand &op,
                                  uint8 imm8) {
  opMMX(mmx, op, 0x70, 0x00, imm8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psignb(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x08, 0x66, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psignd(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x0A, 0x66, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psignw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x09, 0x66, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pslld(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xF2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pslld(const Mmx &mmx, int imm8) {
  opMMX_IMM(mmx, imm8, 0x72, 6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pslldq(const Xmm &xmm, int imm8) {
  opMMX_IMM(xmm, imm8, 0x73, 7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psllq(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xF3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psllq(const Mmx &mmx, int imm8) {
  opMMX_IMM(mmx, imm8, 0x73, 6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psllw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xF1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psllw(const Mmx &mmx, int imm8) {
  opMMX_IMM(mmx, imm8, 0x71, 6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psrad(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xE2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psrad(const Mmx &mmx, int imm8) {
  opMMX_IMM(mmx, imm8, 0x72, 4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psraw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xE1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psraw(const Mmx &mmx, int imm8) {
  opMMX_IMM(mmx, imm8, 0x71, 4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psrld(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xD2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psrld(const Mmx &mmx, int imm8) {
  opMMX_IMM(mmx, imm8, 0x72, 2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psrldq(const Xmm &xmm, int imm8) {
  opMMX_IMM(xmm, imm8, 0x73, 3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psrlq(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xD3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psrlq(const Mmx &mmx, int imm8) {
  opMMX_IMM(mmx, imm8, 0x73, 2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psrlw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xD1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psrlw(const Mmx &mmx, int imm8) {
  opMMX_IMM(mmx, imm8, 0x71, 2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psubb(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xF8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psubd(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xFA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psubq(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xFB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psubsb(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xE8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psubsw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xE9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psubusb(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xD8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psubusw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xD9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::psubw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xF9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ptest(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x17, 0x66, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::punpckhbw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x68);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::punpckhdq(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x6A);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::punpckhqdq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x6D, 0x66, isXMM_XMMorMEM);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::punpckhwd(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x69);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::punpcklbw(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x60);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::punpckldq(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x62);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::punpcklqdq(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x6C, 0x66, isXMM_XMMorMEM);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::punpcklwd(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0x61);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::pushf() {
  db(0x9C);
  std::cerr << "No support for PUSHF instruction" << std::endl;
}
void Xbyak::CodeGenerator::pxor(const Mmx &mmx, const Operand &op) {
  opMMX(mmx, op, 0xEF);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::rcl(const Operand &op, const Reg8 &_cl) {
  opShift(op, _cl, 2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rcl(const Operand &op, int imm) {
  opShift(op, imm, 2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rcpps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x53, 0x100, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rcpss(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x53, 0xF3, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rcr(const Operand &op, const Reg8 &_cl) {
  opShift(op, _cl, 3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rcr(const Operand &op, int imm) {
  opShift(op, imm, 3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rdmsr() {
  db(0x0F);
  db(0x32);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rdpmc() {
  db(0x0F);
  db(0x33);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rdrand(const Reg &r) {
  if (r.isBit(8))
    throw Error(ERR_BAD_SIZE_OF_REGISTER);
  opModR(Reg(6, Operand::REG, r.getBit()), r, 0x0F, 0xC7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rdseed(const Reg &r) {
  if (r.isBit(8))
    throw Error(ERR_BAD_SIZE_OF_REGISTER);
  opModR(Reg(7, Operand::REG, r.getBit()), r, 0x0F, 0xC7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rdtsc() {
  db(0x0F);
  db(0x31);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rdtscp() {
  db(0x0F);
  db(0x01);
  db(0xF9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rep() {
  db(0xF3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::repe() {
  db(0xF3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::repne() {
  db(0xF2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::repnz() {
  db(0xF2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::repz() {
  db(0xF3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ret(int imm) {
  if (imm) {
    UNIMPLEMENTED;
  } else {
    db(0xC3);
    decodeAndTransToAArch64();
  }
}
void Xbyak::CodeGenerator::rol(const Operand &op, const Reg8 &_cl) {
  opShift(op, _cl, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rol(const Operand &op, int imm) {
  opShift(op, imm, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ror(const Operand &op, const Reg8 &_cl) {
  opShift(op, _cl, 1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ror(const Operand &op, int imm) {
  opShift(op, imm, 1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rorx(const Reg32e &r, const Operand &op, uint8 imm) {
  opGpr(r, op, Reg32e(0, r.getBit()), T_0F3A | T_F2, 0xF0, false, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::roundpd(const Xmm &xmm, const Operand &op,
                                   uint8 imm) {
  opGen(xmm, op, 0x09, 0x66, isXMM_XMMorMEM, imm, 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::roundps(const Xmm &xmm, const Operand &op,
                                   uint8 imm) {
  opGen(xmm, op, 0x08, 0x66, isXMM_XMMorMEM, imm, 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::roundsd(const Xmm &xmm, const Operand &op, int imm) {
  opGen(xmm, op, 0x0B, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::roundss(const Xmm &xmm, const Operand &op, int imm) {
  opGen(xmm, op, 0x0A, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rsqrtps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x52, 0x100, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::rsqrtss(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x52, 0xF3, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sahf() {
  db(0x9E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sal(const Operand &op, const Reg8 &_cl) {
  opShift(op, _cl, 4);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::sal(const Operand &op, int imm) {
  opShift(op, imm, 4);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::sar(const Operand &op, const Reg8 &_cl) {
  opShift(op, _cl, 7);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::sar(const Operand &op, int imm) {
  opShift(op, imm, 7);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::sarx(const Reg32e &r1, const Operand &op,
                                const Reg32e &r2) {
  opGpr(r1, op, r2, T_F3 | T_0F38, 0xf7, false);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sbb(const Operand &op, uint32 imm) {
  opRM_I(op, imm, 0x18, 3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sbb(const Operand &op1, const Operand &op2) {
  opRM_RM(op1, op2, 0x18);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::scasb() {
  db(0xAE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::scasd() {
  db(0xAF);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::scasw() {
  db(0x66);
  db(0xAF);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::seta(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 7);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setae(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 3);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setb(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 2);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setbe(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 6);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setc(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 2);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::sete(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 4);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setg(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 15);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setge(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 13);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setl(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 12);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setle(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 14);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setna(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 6);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setnae(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 2);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setnb(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 3);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setnbe(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 7);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setnc(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 3);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setne(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 5);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setng(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 14);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setnge(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 12);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setnl(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 13);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setnle(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 15);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setno(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 1);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setnp(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 11);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setns(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 9);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setnz(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 5);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::seto(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 0);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setp(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 10);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setpe(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 10);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setpo(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 11);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::sets(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 8);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::setz(const Operand &op) {
  opR_ModM(op, 8, 0, 0x0F, 0x90 | 4);
  UNIMPLEMENTED;
} //-V524
void Xbyak::CodeGenerator::sfence() {
  db(0x0F);
  db(0xAE);
  db(0xF8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sha1msg1(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xC9, NONE, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sha1msg2(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xCA, NONE, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sha1nexte(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xC8, NONE, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sha1rnds4(const Xmm &xmm, const Operand &op,
                                     uint8 imm) {
  opGen(xmm, op, 0xCC, NONE, isXMM_XMMorMEM, imm, 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sha256msg1(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xCC, NONE, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sha256msg2(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xCD, NONE, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sha256rnds2(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0xCB, NONE, isXMM_XMMorMEM, NONE, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::shl(const Operand &op, const Reg8 &_cl) {
  opShift(op, _cl, 4);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::shl(const Operand &op, int imm) {
  opShift(op, imm, 4);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::shld(const Operand &op, const Reg &reg,
                                const Reg8 &_cl) {
  opShxd(op, reg, 0, 0xA4, &_cl);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::shld(const Operand &op, const Reg &reg, uint8 imm) {
  opShxd(op, reg, imm, 0xA4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::shlx(const Reg32e &r1, const Operand &op,
                                const Reg32e &r2) {
  opGpr(r1, op, r2, T_66 | T_0F38, 0xf7, false);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::shr(const Operand &op, const Reg8 &_cl) {
  opShift(op, _cl, 5);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::shr(const Operand &op, int imm) {
  opShift(op, imm, 5);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::shrd(const Operand &op, const Reg &reg,
                                const Reg8 &_cl) {
  opShxd(op, reg, 0, 0xAC, &_cl);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::shrd(const Operand &op, const Reg &reg, uint8 imm) {
  opShxd(op, reg, imm, 0xAC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::shrx(const Reg32e &r1, const Operand &op,
                                const Reg32e &r2) {
  opGpr(r1, op, r2, T_F2 | T_0F38, 0xf7, false);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::shufpd(const Xmm &xmm, const Operand &op,
                                  uint8 imm8) {
  opGen(xmm, op, 0xC6, 0x66, isXMM_XMMorMEM, imm8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::shufps(const Xmm &xmm, const Operand &op,
                                  uint8 imm8) {
  opGen(xmm, op, 0xC6, 0x100, isXMM_XMMorMEM, imm8);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::sqrtpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x51, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sqrtps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x51, 0x100, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sqrtsd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x51, 0xF2, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sqrtss(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x51, 0xF3, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::stac() {
  db(0x0F);
  db(0x01);
  db(0xCB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::stc() {
  db(0xF9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::std() {
  db(0xFD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sti() {
  db(0xFB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::stmxcsr(const Address &addr) {
  opModM(addr, Reg32(3), 0x0F, 0xAE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::stosb() {
  db(0xAA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::stosd() {
  db(0xAB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::stosw() {
  db(0x66);
  db(0xAB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sub(const Operand &op, uint32 imm) {
  opRM_I(op, imm, 0x28, 5);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::sub(const Operand &op1, const Operand &op2) {
  opRM_RM(op1, op2, 0x28);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::subpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5C, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::subps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5C, 0x100, isXMM_XMMorMEM);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::subsd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5C, 0xF2, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::subss(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x5C, 0xF3, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sysenter() {
  db(0x0F);
  db(0x34);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sysexit() {
  db(0x0F);
  db(0x35);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::tzcnt(const Reg &reg, const Operand &op) {
  opSp1(reg, op, 0xF3, 0x0F, 0xBC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ucomisd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x2E, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ucomiss(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x2E, 0x100, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ud2() {
  db(0x0F);
  db(0x0B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::unpckhpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x15, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::unpckhps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x15, 0x100, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::unpcklpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x14, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::unpcklps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x14, 0x100, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vaddpd(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2,
               T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x58);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vaddps(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32,
               0x58);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vaddsd(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F2 | T_EW1 | T_EVEX | T_ER_Z | T_N8,
               0x58);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vaddss(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F3 | T_EW0 | T_EVEX | T_ER_Z | T_N4,
               0x58);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vaddsubpd(const Xmm &xmm, const Operand &op1,
                                     const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_66 | T_0F | T_YMM, 0xD0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vaddsubps(const Xmm &xmm, const Operand &op1,
                                     const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_F2 | T_0F | T_YMM, 0xD0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vaesdec(const Xmm &xmm, const Operand &op1,
                                   const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_66 | T_0F38 | T_YMM | T_EVEX, 0xDE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vaesdeclast(const Xmm &xmm, const Operand &op1,
                                       const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_66 | T_0F38 | T_YMM | T_EVEX, 0xDF);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vaesenc(const Xmm &xmm, const Operand &op1,
                                   const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_66 | T_0F38 | T_YMM | T_EVEX, 0xDC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vaesenclast(const Xmm &xmm, const Operand &op1,
                                       const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_66 | T_0F38 | T_YMM | T_EVEX, 0xDD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vaesimc(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F38 | T_W0, 0xDB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vaeskeygenassist(const Xmm &xm, const Operand &op,
                                            uint8 imm) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A, 0xDF, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vandnpd(const Xmm &xmm, const Operand &op1,
                                   const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2,
               T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x55);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vandnps(const Xmm &xmm, const Operand &op1,
                                   const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32,
               0x55);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vandpd(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2,
               T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x54);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vandps(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32,
               0x54);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vblendpd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0 | T_YMM, 0x0D, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vblendps(const Xmm &x1, const Xmm &x2,
                                    const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0 | T_YMM, 0x0C, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vblendvpd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op, const Xmm &x4) {
  opAVX_X_X_XM(x1, x2, op, T_0F3A | T_66 | T_YMM, 0x4B, x4.getIdx() << 4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vblendvps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op, const Xmm &x4) {
  opAVX_X_X_XM(x1, x2, op, T_0F3A | T_66 | T_YMM, 0x4A, x4.getIdx() << 4);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vbroadcastf128(const Ymm &y, const Address &addr) {
  opAVX_X_XM_IMM(y, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x1A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vbroadcasti128(const Ymm &y, const Address &addr) {
  opAVX_X_XM_IMM(y, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x5A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vbroadcastsd(const Ymm &y, const Operand &op) {
  if (!op.isMEM() && !(y.isYMM() && op.isXMM()) && !(y.isZMM() && op.isXMM()))
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_XM_IMM(y, op, T_0F38 | T_66 | T_W0 | T_YMM | T_EVEX | T_EW1 | T_N8,
                 0x19);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vbroadcastss(const Xmm &x, const Operand &op) {
  if (!(op.isXMM() || op.isMEM()))
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_XM_IMM(x, op, T_N4 | T_66 | T_0F38 | T_W0 | T_YMM | T_EVEX, 0x18);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpeq_ospd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmppd(x1, x2, op, 16);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_osps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpps(x1, x2, op, 16);
}
void Xbyak::CodeGenerator::vcmpeq_ossd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpsd(x1, x2, op, 16);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_osss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpss(x1, x2, op, 16);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_uqpd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmppd(x1, x2, op, 8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_uqps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpps(x1, x2, op, 8);
}
void Xbyak::CodeGenerator::vcmpeq_uqsd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpsd(x1, x2, op, 8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_uqss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpss(x1, x2, op, 8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_uspd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmppd(x1, x2, op, 24);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_usps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpps(x1, x2, op, 24);
}
void Xbyak::CodeGenerator::vcmpeq_ussd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpsd(x1, x2, op, 24);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_usss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpss(x1, x2, op, 24);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeqpd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmppd(x1, x2, op, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeqps(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpps(x1, x2, op, 0);
}
void Xbyak::CodeGenerator::vcmpeqsd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpsd(x1, x2, op, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeqss(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpss(x1, x2, op, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpfalse_ospd(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  vcmppd(x1, x2, op, 27);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpfalse_osps(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  vcmpps(x1, x2, op, 27);
}
void Xbyak::CodeGenerator::vcmpfalse_ossd(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  vcmpsd(x1, x2, op, 27);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpfalse_osss(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  vcmpss(x1, x2, op, 27);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpfalsepd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmppd(x1, x2, op, 11);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpfalseps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpps(x1, x2, op, 11);
}
void Xbyak::CodeGenerator::vcmpfalsesd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpsd(x1, x2, op, 11);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpfalsess(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpss(x1, x2, op, 11);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpge_oqpd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmppd(x1, x2, op, 29);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpge_oqps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpps(x1, x2, op, 29);
}
void Xbyak::CodeGenerator::vcmpge_oqsd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpsd(x1, x2, op, 29);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpge_oqss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpss(x1, x2, op, 29);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgepd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmppd(x1, x2, op, 13);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgeps(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpps(x1, x2, op, 13);
}
void Xbyak::CodeGenerator::vcmpgesd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpsd(x1, x2, op, 13);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgess(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpss(x1, x2, op, 13);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgt_oqpd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmppd(x1, x2, op, 30);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgt_oqps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpps(x1, x2, op, 30);
}
void Xbyak::CodeGenerator::vcmpgt_oqsd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpsd(x1, x2, op, 30);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgt_oqss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpss(x1, x2, op, 30);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgtpd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmppd(x1, x2, op, 14);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgtps(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpps(x1, x2, op, 14);
}
void Xbyak::CodeGenerator::vcmpgtsd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpsd(x1, x2, op, 14);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgtss(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpss(x1, x2, op, 14);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmple_oqpd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmppd(x1, x2, op, 18);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmple_oqps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpps(x1, x2, op, 18);
}
void Xbyak::CodeGenerator::vcmple_oqsd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpsd(x1, x2, op, 18);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmple_oqss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpss(x1, x2, op, 18);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmplepd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmppd(x1, x2, op, 2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpleps(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpps(x1, x2, op, 2);
}
void Xbyak::CodeGenerator::vcmplesd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpsd(x1, x2, op, 2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpless(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpss(x1, x2, op, 2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmplt_oqpd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmppd(x1, x2, op, 17);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmplt_oqps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpps(x1, x2, op, 17);
}
void Xbyak::CodeGenerator::vcmplt_oqsd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpsd(x1, x2, op, 17);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmplt_oqss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpss(x1, x2, op, 17);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpltpd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmppd(x1, x2, op, 1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpltps(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpps(x1, x2, op, 1);
}
void Xbyak::CodeGenerator::vcmpltsd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpsd(x1, x2, op, 1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpltss(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  vcmpss(x1, x2, op, 1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_oqpd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmppd(x1, x2, op, 12);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_oqps(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpps(x1, x2, op, 12);
}
void Xbyak::CodeGenerator::vcmpneq_oqsd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpsd(x1, x2, op, 12);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_oqss(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpss(x1, x2, op, 12);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_ospd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmppd(x1, x2, op, 28);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_osps(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpps(x1, x2, op, 28);
}
void Xbyak::CodeGenerator::vcmpneq_ossd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpsd(x1, x2, op, 28);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_osss(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpss(x1, x2, op, 28);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_uspd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmppd(x1, x2, op, 20);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_usps(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpps(x1, x2, op, 20);
}
void Xbyak::CodeGenerator::vcmpneq_ussd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpsd(x1, x2, op, 20);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_usss(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpss(x1, x2, op, 20);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneqpd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmppd(x1, x2, op, 4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneqps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpps(x1, x2, op, 4);
}
void Xbyak::CodeGenerator::vcmpneqsd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpsd(x1, x2, op, 4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneqss(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpss(x1, x2, op, 4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnge_uqpd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmppd(x1, x2, op, 25);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnge_uqps(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpps(x1, x2, op, 25);
}
void Xbyak::CodeGenerator::vcmpnge_uqsd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpsd(x1, x2, op, 25);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnge_uqss(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpss(x1, x2, op, 25);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngepd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmppd(x1, x2, op, 9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngeps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpps(x1, x2, op, 9);
}
void Xbyak::CodeGenerator::vcmpngesd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpsd(x1, x2, op, 9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngess(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpss(x1, x2, op, 9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngt_uqpd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmppd(x1, x2, op, 26);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngt_uqps(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpps(x1, x2, op, 26);
}
void Xbyak::CodeGenerator::vcmpngt_uqsd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpsd(x1, x2, op, 26);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngt_uqss(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpss(x1, x2, op, 26);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngtpd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmppd(x1, x2, op, 10);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngtps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpps(x1, x2, op, 10);
}
void Xbyak::CodeGenerator::vcmpngtsd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpsd(x1, x2, op, 10);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngtss(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpss(x1, x2, op, 10);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnle_uqpd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmppd(x1, x2, op, 22);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnle_uqps(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpps(x1, x2, op, 22);
}
void Xbyak::CodeGenerator::vcmpnle_uqsd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpsd(x1, x2, op, 22);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnle_uqss(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpss(x1, x2, op, 22);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnlepd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmppd(x1, x2, op, 6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnleps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpps(x1, x2, op, 6);
}
void Xbyak::CodeGenerator::vcmpnlesd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpsd(x1, x2, op, 6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnless(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpss(x1, x2, op, 6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnlt_uqpd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmppd(x1, x2, op, 21);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnlt_uqps(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpps(x1, x2, op, 21);
}
void Xbyak::CodeGenerator::vcmpnlt_uqsd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpsd(x1, x2, op, 21);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnlt_uqss(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  vcmpss(x1, x2, op, 21);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnltpd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmppd(x1, x2, op, 5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnltps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpps(x1, x2, op, 5);
}
void Xbyak::CodeGenerator::vcmpnltsd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpsd(x1, x2, op, 5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnltss(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpss(x1, x2, op, 5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpord_spd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmppd(x1, x2, op, 23);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpord_sps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpps(x1, x2, op, 23);
}
void Xbyak::CodeGenerator::vcmpord_ssd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpsd(x1, x2, op, 23);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpord_sss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpss(x1, x2, op, 23);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpordpd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmppd(x1, x2, op, 7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpordps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpps(x1, x2, op, 7);
}
void Xbyak::CodeGenerator::vcmpordsd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpsd(x1, x2, op, 7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpordss(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  vcmpss(x1, x2, op, 7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmppd(const Xmm &x1, const Xmm &x2,
                                  const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0xC2, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpps(const Xmm &x1, const Xmm &x2,
                                  const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_0F | T_YMM, 0xC2, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpsd(const Xmm &x1, const Xmm &x2,
                                  const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_F2 | T_0F, 0xC2, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpss(const Xmm &x1, const Xmm &x2,
                                  const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_F3 | T_0F, 0xC2, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmptrue_uspd(const Xmm &x1, const Xmm &x2,
                                         const Operand &op) {
  vcmppd(x1, x2, op, 31);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmptrue_usps(const Xmm &x1, const Xmm &x2,
                                         const Operand &op) {
  vcmpps(x1, x2, op, 31);
}
void Xbyak::CodeGenerator::vcmptrue_ussd(const Xmm &x1, const Xmm &x2,
                                         const Operand &op) {
  vcmpsd(x1, x2, op, 31);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmptrue_usss(const Xmm &x1, const Xmm &x2,
                                         const Operand &op) {
  vcmpss(x1, x2, op, 31);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmptruepd(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  vcmppd(x1, x2, op, 15);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmptrueps(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  vcmpps(x1, x2, op, 15);
}
void Xbyak::CodeGenerator::vcmptruesd(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  vcmpsd(x1, x2, op, 15);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmptruess(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  vcmpss(x1, x2, op, 15);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpunord_spd(const Xmm &x1, const Xmm &x2,
                                         const Operand &op) {
  vcmppd(x1, x2, op, 19);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpunord_sps(const Xmm &x1, const Xmm &x2,
                                         const Operand &op) {
  vcmpps(x1, x2, op, 19);
}
void Xbyak::CodeGenerator::vcmpunord_ssd(const Xmm &x1, const Xmm &x2,
                                         const Operand &op) {
  vcmpsd(x1, x2, op, 19);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpunord_sss(const Xmm &x1, const Xmm &x2,
                                         const Operand &op) {
  vcmpss(x1, x2, op, 19);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpunordpd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmppd(x1, x2, op, 3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpunordps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpps(x1, x2, op, 3);
}
void Xbyak::CodeGenerator::vcmpunordsd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpsd(x1, x2, op, 3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpunordss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  vcmpss(x1, x2, op, 3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcomisd(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N8 | T_66 | T_0F | T_EW1 | T_EVEX | T_SAE_X, 0x2F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcomiss(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N4 | T_0F | T_EW0 | T_EVEX | T_SAE_X, 0x2F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtdq2pd(const Xmm &x, const Operand &op) {
  checkCvt1(x, op);
  opVex(x, 0, op, T_0F | T_F3 | T_YMM | T_EVEX | T_EW0 | T_B32 | T_N8 | T_N_VL,
        0xE6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtdq2ps(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x5B);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcvtpd2dq(const Xmm &x, const Operand &op) {
  opCvt2(x, op, T_0F | T_F2 | T_YMM | T_EVEX | T_EW1 | T_B64 | T_ER_Z, 0xE6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtpd2ps(const Xmm &x, const Operand &op) {
  opCvt2(x, op, T_0F | T_66 | T_YMM | T_EVEX | T_EW1 | T_B64 | T_ER_Z, 0x5A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtph2ps(const Xmm &x, const Operand &op) {
  checkCvt1(x, op);
  opVex(x, 0, op,
        T_0F38 | T_66 | T_W0 | T_EVEX | T_EW0 | T_N8 | T_N_VL | T_SAE_Y, 0x13);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtps2dq(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32,
                 0x5B);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcvtps2pd(const Xmm &x, const Operand &op) {
  checkCvt1(x, op);
  opVex(x, 0, op,
        T_0F | T_YMM | T_EVEX | T_EW0 | T_B32 | T_N8 | T_N_VL | T_SAE_Y, 0x5A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtps2ph(const Operand &op, const Xmm &x,
                                     uint8 imm) {
  checkCvt1(x, op);
  opVex(x, 0, op,
        T_0F3A | T_66 | T_W0 | T_EVEX | T_EW0 | T_N8 | T_N_VL | T_SAE_Y, 0x1D,
        imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtsd2si(const Reg32 &r, const Operand &op) {
  opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op,
               T_0F | T_F2 | T_W0 | T_EVEX | T_EW0 | T_N4 | T_ER_X, 0x2D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtsd2ss(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N8 | T_F2 | T_0F | T_EW1 | T_EVEX | T_ER_X, 0x5A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtsi2sd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opCvt3(x1, x2, op, T_0F | T_F2 | T_EVEX, T_W1 | T_EW1 | T_ER_X | T_N8,
         T_W0 | T_EW0 | T_N4, 0x2A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtsi2ss(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opCvt3(x1, x2, op, T_0F | T_F3 | T_EVEX | T_ER_X, T_W1 | T_EW1 | T_N8,
         T_W0 | T_EW0 | T_N4, 0x2A);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcvtss2sd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_F3 | T_0F | T_EW0 | T_EVEX | T_SAE_X, 0x5A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtss2si(const Reg32 &r, const Operand &op) {
  opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op,
               T_0F | T_F3 | T_W0 | T_EVEX | T_EW0 | T_ER_X | T_N8, 0x2D);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcvttpd2dq(const Xmm &x, const Operand &op) {
  opCvt2(x, op, T_66 | T_0F | T_YMM | T_EVEX | T_EW1 | T_B64 | T_ER_Z, 0xE6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvttps2dq(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_F3 | T_0F | T_EW0 | T_YMM | T_EVEX | T_SAE_Z | T_B32,
                 0x5B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvttsd2si(const Reg32 &r, const Operand &op) {
  opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op,
               T_0F | T_F2 | T_W0 | T_EVEX | T_EW0 | T_N4 | T_SAE_X, 0x2C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvttss2si(const Reg32 &r, const Operand &op) {
  opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op,
               T_0F | T_F3 | T_W0 | T_EVEX | T_EW0 | T_SAE_X | T_N8, 0x2C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vdivpd(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2,
               T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x5E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vdivps(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32,
               0x5E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vdivsd(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F2 | T_EW1 | T_EVEX | T_ER_Z | T_N8,
               0x5E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vdivss(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F3 | T_EW0 | T_EVEX | T_ER_Z | T_N4,
               0x5E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vdppd(const Xmm &x1, const Xmm &x2,
                                 const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0, 0x41, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vdpps(const Xmm &x1, const Xmm &x2,
                                 const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0 | T_YMM, 0x40, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vextractf128(const Operand &op, const Ymm &y,
                                        uint8 imm) {
  if (!(op.isXMEM() && y.isYMM()))
    throw Error(ERR_BAD_COMBINATION);
  opVex(y, 0, op, T_0F3A | T_66 | T_W0 | T_YMM, 0x19, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vextracti128(const Operand &op, const Ymm &y,
                                        uint8 imm) {
  if (!(op.isXMEM() && y.isYMM()))
    throw Error(ERR_BAD_COMBINATION);
  opVex(y, 0, op, T_0F3A | T_66 | T_W0 | T_YMM, 0x39, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vextractps(const Operand &op, const Xmm &x,
                                      uint8 imm) {
  if (!((op.isREG(32) || op.isMEM()) && x.isXMM()))
    throw Error(ERR_BAD_COMBINATION);
  opVex(x, 0, op, T_0F3A | T_66 | T_W0 | T_EVEX | T_N4, 0x17, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmadd132pd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x98);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmadd132ps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x98);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vfmadd132sd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0x99);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmadd132ss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0x99);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmadd213pd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xA8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmadd213ps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xA8);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vfmadd213sd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xA9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmadd213ss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xA9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmadd231pd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xB8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmadd231ps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xB8);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vfmadd231sd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xB9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmadd231ss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xB9);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vfmaddsub132pd(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x96);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmaddsub132ps(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x96);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmaddsub213pd(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xA6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmaddsub213ps(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xA6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmaddsub231pd(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xB6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmaddsub231ps(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xB6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsub132pd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x9A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsub132ps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x9A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsub132sd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0x9B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsub132ss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0x9B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsub213pd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xAA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsub213ps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xAA);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vfmsub213sd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xAB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsub213ss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xAB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsub231pd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xBA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsub231ps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xBA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsub231sd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xBB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsub231ss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xBB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsubadd132pd(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x97);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsubadd132ps(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x97);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsubadd213pd(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xA7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsubadd213ps(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xA7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsubadd231pd(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xB7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfmsubadd231ps(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xB7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmadd132pd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x9C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmadd132ps(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x9C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmadd132sd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0x9D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmadd132ss(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0x9D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmadd213pd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xAC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmadd213ps(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xAC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmadd213sd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xAD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmadd213ss(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xAD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmadd231pd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xBC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmadd231ps(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xBC);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vfnmadd231sd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xBD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmadd231ss(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xBD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmsub132pd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x9E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmsub132ps(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x9E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmsub132sd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0x9F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmsub132ss(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0x9F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmsub213pd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xAE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmsub213ps(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xAE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmsub213sd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xAF);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmsub213ss(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xAF);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmsub231pd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xBE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmsub231ps(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xBE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmsub231sd(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xBF);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfnmsub231ss(const Xmm &x1, const Xmm &x2,
                                        const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xBF);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgatherdpd(const Xmm &x1, const Address &addr,
                                      const Xmm &x2) {
  opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W1, 0x92, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgatherdps(const Xmm &x1, const Address &addr,
                                      const Xmm &x2) {
  opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W0, 0x92, 1);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vgatherqpd(const Xmm &x1, const Address &addr,
                                      const Xmm &x2) {
  opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W1, 0x93, 1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgatherqps(const Xmm &x1, const Address &addr,
                                      const Xmm &x2) {
  opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W0, 0x93, 2);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vgf2p8affineinvqb(const Xmm &x1, const Xmm &x2,
                                             const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F3A | T_W1 | T_EW1 | T_YMM | T_EVEX | T_SAE_Z | T_B64,
               0xCF, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgf2p8affineqb(const Xmm &x1, const Xmm &x2,
                                          const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F3A | T_W1 | T_EW1 | T_YMM | T_EVEX | T_SAE_Z | T_B64,
               0xCE, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgf2p8mulb(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_SAE_Z, 0xCF);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vhaddpd(const Xmm &xmm, const Operand &op1,
                                   const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_66 | T_0F | T_YMM, 0x7C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vhaddps(const Xmm &xmm, const Operand &op1,
                                   const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_F2 | T_0F | T_YMM, 0x7C);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vhsubpd(const Xmm &xmm, const Operand &op1,
                                   const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_66 | T_0F | T_YMM, 0x7D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vhsubps(const Xmm &xmm, const Operand &op1,
                                   const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_F2 | T_0F | T_YMM, 0x7D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vinsertf128(const Ymm &y1, const Ymm &y2,
                                       const Operand &op, uint8 imm) {
  if (!(y1.isYMM() && y2.isYMM() && op.isXMEM()))
    throw Error(ERR_BAD_COMBINATION);
  opVex(y1, &y2, op, T_0F3A | T_66 | T_W0 | T_YMM, 0x18, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vinserti128(const Ymm &y1, const Ymm &y2,
                                       const Operand &op, uint8 imm) {
  if (!(y1.isYMM() && y2.isYMM() && op.isXMEM()))
    throw Error(ERR_BAD_COMBINATION);
  opVex(y1, &y2, op, T_0F3A | T_66 | T_W0 | T_YMM, 0x38, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vinsertps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F3A | T_W0 | T_EW0 | T_EVEX, 0x21,
               imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vlddqu(const Xmm &x, const Address &addr) {
  opAVX_X_X_XM(x, cvtIdx0(x), addr, T_0F | T_F2 | T_W0 | T_YMM, 0xF0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vldmxcsr(const Address &addr) {
  opAVX_X_X_XM(xm2, xm0, addr, T_0F, 0xAE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmaskmovdqu(const Xmm &x1, const Xmm &x2) {
  opAVX_X_X_XM(x1, xm0, x2, T_0F | T_66, 0xF7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmaskmovpd(const Address &addr, const Xmm &x1,
                                      const Xmm &x2) {
  opAVX_X_X_XM(x2, x1, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x2F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmaskmovpd(const Xmm &x1, const Xmm &x2,
                                      const Address &addr) {
  opAVX_X_X_XM(x1, x2, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x2D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmaskmovps(const Address &addr, const Xmm &x1,
                                      const Xmm &x2) {
  opAVX_X_X_XM(x2, x1, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x2E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmaskmovps(const Xmm &x1, const Xmm &x2,
                                      const Address &addr) {
  opAVX_X_X_XM(x1, x2, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x2C);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmaxpd(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2,
               T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x5F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmaxps(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32,
               0x5F);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmaxsd(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F2 | T_EW1 | T_EVEX | T_ER_Z | T_N8,
               0x5F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmaxss(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F3 | T_EW0 | T_EVEX | T_ER_Z | T_N4,
               0x5F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vminpd(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2,
               T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x5D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vminps(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32,
               0x5D);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vminsd(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F2 | T_EW1 | T_EVEX | T_ER_Z | T_N8,
               0x5D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vminss(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F3 | T_EW0 | T_EVEX | T_ER_Z | T_N4,
               0x5D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovapd(const Address &addr, const Xmm &xmm) {
  opAVX_X_XM_IMM(xmm, addr, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_M_K, 0x29);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovapd(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX, 0x28);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovaps(const Address &addr, const Xmm &xmm) {
  opAVX_X_XM_IMM(xmm, addr, T_0F | T_EW0 | T_YMM | T_EVEX | T_M_K, 0x29);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovaps(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_0F | T_EW0 | T_YMM | T_EVEX, 0x28);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovd(const Operand &op, const Xmm &x) {
  if (!op.isREG(32) && !op.isMEM())
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_X_XM(x, xm0, op, T_0F | T_66 | T_W0 | T_EVEX | T_N4, 0x7E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovd(const Xmm &x, const Operand &op) {
  if (!op.isREG(32) && !op.isMEM())
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_X_XM(x, xm0, op, T_0F | T_66 | T_W0 | T_EVEX | T_N4, 0x6E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovddup(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op,
                 T_DUP | T_F2 | T_0F | T_EW1 | T_YMM | T_EVEX | T_ER_X |
                     T_ER_Y | T_ER_Z,
                 0x12);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovdqa(const Address &addr, const Xmm &xmm) {
  opAVX_X_XM_IMM(xmm, addr, T_66 | T_0F | T_YMM, 0x7F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovdqa(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F | T_YMM, 0x6F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovdqu(const Address &addr, const Xmm &xmm) {
  opAVX_X_XM_IMM(xmm, addr, T_F3 | T_0F | T_YMM, 0x7F);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovdqu(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_F3 | T_0F | T_YMM, 0x6F);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovhlps(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  if (!op.isNone() && !op.isXMM())
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_X_XM(x1, x2, op, T_0F | T_EVEX | T_EW0, 0x12);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovhpd(const Address &addr, const Xmm &x) {
  opAVX_X_X_XM(x, xm0, addr, T_0F | T_66 | T_EVEX | T_EW1 | T_N8, 0x17);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovhpd(const Xmm &x, const Operand &op1,
                                   const Operand &op2) {
  if (!op2.isNone() && !op2.isMEM())
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_X_XM(x, op1, op2, T_0F | T_66 | T_EVEX | T_EW1 | T_N8, 0x16);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovhps(const Address &addr, const Xmm &x) {
  opAVX_X_X_XM(x, xm0, addr, T_0F | T_EVEX | T_EW0 | T_N8, 0x17);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovhps(const Xmm &x, const Operand &op1,
                                   const Operand &op2) {
  if (!op2.isNone() && !op2.isMEM())
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_X_XM(x, op1, op2, T_0F | T_EVEX | T_EW0 | T_N8, 0x16);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovlhps(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  if (!op.isNone() && !op.isXMM())
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_X_XM(x1, x2, op, T_0F | T_EVEX | T_EW0, 0x16);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovlpd(const Address &addr, const Xmm &x) {
  opAVX_X_X_XM(x, xm0, addr, T_0F | T_66 | T_EVEX | T_EW1 | T_N8, 0x13);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovlpd(const Xmm &x, const Operand &op1,
                                   const Operand &op2) {
  if (!op2.isNone() && !op2.isMEM())
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_X_XM(x, op1, op2, T_0F | T_66 | T_EVEX | T_EW1 | T_N8, 0x12);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovlps(const Address &addr, const Xmm &x) {
  opAVX_X_X_XM(x, xm0, addr, T_0F | T_EVEX | T_EW0 | T_N8, 0x13);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovlps(const Xmm &x, const Operand &op1,
                                   const Operand &op2) {
  if (!op2.isNone() && !op2.isMEM())
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_X_XM(x, op1, op2, T_0F | T_EVEX | T_EW0 | T_N8, 0x12);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovmskpd(const Reg &r, const Xmm &x) {
  if (!r.isBit(i32e))
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_X_XM(x.isXMM() ? Xmm(r.getIdx()) : Ymm(r.getIdx()), cvtIdx0(x), x,
               T_0F | T_66 | T_W0 | T_YMM, 0x50);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovmskps(const Reg &r, const Xmm &x) {
  if (!r.isBit(i32e))
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_X_XM(x.isXMM() ? Xmm(r.getIdx()) : Ymm(r.getIdx()), cvtIdx0(x), x,
               T_0F | T_W0 | T_YMM, 0x50);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovntdq(const Address &addr, const Xmm &x) {
  opVex(x, 0, addr, T_0F | T_66 | T_YMM | T_EVEX | T_EW0, 0xE7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovntdqa(const Xmm &x, const Address &addr) {
  opVex(x, 0, addr, T_0F38 | T_66 | T_YMM | T_EVEX | T_EW0, 0x2A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovntpd(const Address &addr, const Xmm &x) {
  opVex(x, 0, addr, T_0F | T_66 | T_YMM | T_EVEX | T_EW1, 0x2B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovntps(const Address &addr, const Xmm &x) {
  opVex(x, 0, addr, T_0F | T_YMM | T_EVEX | T_EW0, 0x2B);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovq(const Address &addr, const Xmm &x) {
  opAVX_X_X_XM(x, xm0, addr, T_0F | T_66 | T_EVEX | T_EW1 | T_N8,
               x.getIdx() < 16 ? 0xD6 : 0x7E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovq(const Xmm &x, const Address &addr) {
  int type, code;
  if (x.getIdx() < 16) {
    type = T_0F | T_F3;
    code = 0x7E; /*decodeAndTransToAArch64();*/
  } else {
    type = T_0F | T_66 | T_EVEX | T_EW1 | T_N8;
    code = 0x6E; /*UNIMPLEMENTED;*/
  }
  opAVX_X_X_XM(x, xm0, addr, type, code);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovq(const Xmm &x1, const Xmm &x2) {
  opAVX_X_X_XM(x1, xm0, x2, T_0F | T_F3 | T_EVEX | T_EW1 | T_N8, 0x7E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovsd(const Address &addr, const Xmm &x) {
  opAVX_X_X_XM(x, xm0, addr, T_N8 | T_F2 | T_0F | T_EW1 | T_EVEX | T_M_K, 0x11);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovsd(const Xmm &x, const Address &addr) {
  opAVX_X_X_XM(x, xm0, addr, T_N8 | T_F2 | T_0F | T_EW1 | T_EVEX, 0x10);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovsd(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  if (!op.isNone() && !op.isXMM())
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_X_XM(x1, x2, op, T_N8 | T_F2 | T_0F | T_EW1 | T_EVEX, 0x10);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovshdup(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_F3 | T_0F | T_EW0 | T_YMM | T_EVEX, 0x16);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovsldup(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_F3 | T_0F | T_EW0 | T_YMM | T_EVEX, 0x12);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovss(const Address &addr, const Xmm &x) {
  opAVX_X_X_XM(x, xm0, addr, T_N4 | T_F3 | T_0F | T_EW0 | T_EVEX | T_M_K, 0x11);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovss(const Xmm &x, const Address &addr) {
  opAVX_X_X_XM(x, xm0, addr, T_N4 | T_F3 | T_0F | T_EW0 | T_EVEX, 0x10);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovss(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  if (!op.isNone() && !op.isXMM())
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_F3 | T_0F | T_EW0 | T_EVEX, 0x10);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovupd(const Address &addr, const Xmm &xmm) {
  opAVX_X_XM_IMM(xmm, addr, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_M_K, 0x11);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovupd(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX, 0x10);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovups(const Address &addr, const Xmm &xmm) {
  opAVX_X_XM_IMM(xmm, addr, T_0F | T_EW0 | T_YMM | T_EVEX | T_M_K, 0x11);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovups(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_0F | T_EW0 | T_YMM | T_EVEX, 0x10);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmpsadbw(const Xmm &x1, const Xmm &x2,
                                    const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0 | T_YMM, 0x42, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmulpd(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2,
               T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x59);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmulps(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32,
               0x59);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmulsd(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F2 | T_EW1 | T_EVEX | T_ER_Z | T_N8,
               0x59);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmulss(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F3 | T_EW0 | T_EVEX | T_ER_Z | T_N4,
               0x59);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vorpd(const Xmm &xmm, const Operand &op1,
                                 const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2,
               T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x56);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vorps(const Xmm &xmm, const Operand &op1,
                                 const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32,
               0x56);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpabsb(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x1C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpabsd(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x1E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpabsw(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x1D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpackssdw(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0x6B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpacksswb(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0x63);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpackusdw(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX | T_B32,
               0x2B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpackuswb(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0x67);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpaddb(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xFC);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpaddd(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0xFE);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpaddq(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0xD4);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpaddsb(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xEC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpaddsw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xED);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpaddusb(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xDC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpaddusw(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xDD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpaddw(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xFD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpalignr(const Xmm &x1, const Xmm &x2,
                                    const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_YMM | T_EVEX, 0x0F, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpand(const Xmm &x1, const Xmm &x2,
                                 const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0xDB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpandn(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0xDF);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpavgb(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xE0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpavgw(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xE3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpblendd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0 | T_YMM, 0x02, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpblendvb(const Xmm &x1, const Xmm &x2,
                                     const Operand &op, const Xmm &x4) {
  opAVX_X_X_XM(x1, x2, op, T_0F3A | T_66 | T_YMM, 0x4C, x4.getIdx() << 4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpblendw(const Xmm &x1, const Xmm &x2,
                                    const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0 | T_YMM, 0x0E, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpbroadcastb(const Xmm &x, const Operand &op) {
  if (!(op.isXMM() || op.isMEM()))
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_XM_IMM(x, op, T_N1 | T_66 | T_0F38 | T_W0 | T_YMM | T_EVEX, 0x78);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpbroadcastd(const Xmm &x, const Operand &op) {
  if (!(op.isXMM() || op.isMEM()))
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_XM_IMM(x, op, T_N4 | T_66 | T_0F38 | T_W0 | T_YMM | T_EVEX, 0x58);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpbroadcastq(const Xmm &x, const Operand &op) {
  if (!(op.isXMM() || op.isMEM()))
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_XM_IMM(x, op, T_N8 | T_66 | T_0F38 | T_W0 | T_EW1 | T_YMM | T_EVEX,
                 0x59);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpbroadcastw(const Xmm &x, const Operand &op) {
  if (!(op.isXMM() || op.isMEM()))
    throw Error(ERR_BAD_COMBINATION);
  opAVX_X_XM_IMM(x, op, T_N2 | T_66 | T_0F38 | T_W0 | T_YMM | T_EVEX, 0x79);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpclmulqdq(const Xmm &x1, const Xmm &x2,
                                      const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0 | T_YMM | T_EVEX, 0x44, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpeqb(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0x74);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpcmpeqd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0x76);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpcmpeqq(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x29);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpeqw(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0x75);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpestri(const Xmm &xm, const Operand &op,
                                      uint8 imm) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A, 0x61, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpestrm(const Xmm &xm, const Operand &op,
                                      uint8 imm) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A, 0x60, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpgtb(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0x64);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpgtd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0x66);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpgtq(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x37);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpgtw(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0x65);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpistri(const Xmm &xm, const Operand &op,
                                      uint8 imm) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A, 0x63, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpistrm(const Xmm &xm, const Operand &op,
                                      uint8 imm) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A, 0x62, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vperm2f128(const Ymm &y1, const Ymm &y2,
                                      const Operand &op, uint8 imm) {
  if (!(y1.isYMM() && y2.isYMM() && op.isYMEM()))
    throw Error(ERR_BAD_COMBINATION);
  opVex(y1, &y2, op, T_0F3A | T_66 | T_W0 | T_YMM, 0x06, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vperm2i128(const Ymm &y1, const Ymm &y2,
                                      const Operand &op, uint8 imm) {
  if (!(y1.isYMM() && y2.isYMM() && op.isYMEM()))
    throw Error(ERR_BAD_COMBINATION);
  opVex(y1, &y2, op, T_0F3A | T_66 | T_W0 | T_YMM, 0x46, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpermd(const Ymm &y1, const Ymm &y2,
                                  const Operand &op) {
  opAVX_X_X_XM(y1, y2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x36);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpermilpd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x0D);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpermilpd(const Xmm &xm, const Operand &op,
                                     uint8 imm) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_EVEX | T_B64, 0x05,
                 imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpermilps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x0C);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpermilps(const Xmm &xm, const Operand &op,
                                     uint8 imm) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_EVEX | T_B32, 0x04,
                 imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpermpd(const Ymm &y, const Operand &op, uint8 imm) {
  opAVX_X_XM_IMM(y, op, T_66 | T_0F3A | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64,
                 0x01, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermpd(const Ymm &y1, const Ymm &y2,
                                   const Operand &op) {
  opAVX_X_X_XM(y1, y2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x16);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermps(const Ymm &y1, const Ymm &y2,
                                   const Operand &op) {
  opAVX_X_X_XM(y1, y2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x16);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermq(const Ymm &y, const Operand &op, uint8 imm) {
  opAVX_X_XM_IMM(y, op, T_66 | T_0F3A | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64,
                 0x00, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermq(const Ymm &y1, const Ymm &y2,
                                  const Operand &op) {
  opAVX_X_X_XM(y1, y2, op,
               T_66 | T_0F38 | T_W0 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x36);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpextrb(const Operand &op, const Xmm &x, uint8 imm) {
  if (!((op.isREG(8 | 16 | i32e) || op.isMEM()) && x.isXMM()))
    throw Error(ERR_BAD_COMBINATION);
  opVex(x, 0, op, T_0F3A | T_66 | T_EVEX | T_N1, 0x14, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpextrd(const Operand &op, const Xmm &x, uint8 imm) {
  if (!((op.isREG(32) || op.isMEM()) && x.isXMM()))
    throw Error(ERR_BAD_COMBINATION);
  opVex(x, 0, op, T_0F3A | T_66 | T_W0 | T_EVEX | T_EW0 | T_N4, 0x16, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpextrq(const Operand &op, const Xmm &x, uint8 imm) {
  if (!((op.isREG(64) || op.isMEM()) && x.isXMM()))
    throw Error(ERR_BAD_COMBINATION);
  opVex(x, 0, op, T_0F3A | T_66 | T_W1 | T_EVEX | T_EW1 | T_N8, 0x16, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpextrw(const Operand &op, const Xmm &x, uint8 imm) {
  if (!((op.isREG(16 | i32e) || op.isMEM()) && x.isXMM()))
    throw Error(ERR_BAD_COMBINATION);
  if (op.isREG() && x.getIdx() < 16) {
    opAVX_X_X_XM(Xmm(op.getIdx()), xm0, x, T_0F | T_66, 0xC5, imm);
    UNIMPLEMENTED;
  } else {
    opVex(x, 0, op, T_0F3A | T_66 | T_EVEX | T_N2, 0x15, imm);
    UNIMPLEMENTED;
  }
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpgatherdd(const Xmm &x1, const Address &addr,
                                      const Xmm &x2) {
  opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W0, 0x90, 1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpgatherdq(const Xmm &x1, const Address &addr,
                                      const Xmm &x2) {
  opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W1, 0x90, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpgatherqd(const Xmm &x1, const Address &addr,
                                      const Xmm &x2) {
  opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W0, 0x91, 2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpgatherqq(const Xmm &x1, const Address &addr,
                                      const Xmm &x2) {
  opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W1, 0x91, 1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vphaddd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x02);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vphaddsw(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x03);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vphaddw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x01);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vphminposuw(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F38, 0x41);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vphsubd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x06);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vphsubsw(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x07);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vphsubw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x05);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpinsrb(const Xmm &x1, const Xmm &x2,
                                   const Operand &op, uint8 imm) {
  if (!(x1.isXMM() && x2.isXMM() && (op.isREG(32) || op.isMEM())))
    throw Error(ERR_BAD_COMBINATION);
  opVex(x1, &x2, op, T_0F3A | T_66 | T_EVEX | T_N1, 0x20, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpinsrd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op, uint8 imm) {
  if (!(x1.isXMM() && x2.isXMM() && (op.isREG(32) || op.isMEM())))
    throw Error(ERR_BAD_COMBINATION);
  opVex(x1, &x2, op, T_0F3A | T_66 | T_W0 | T_EVEX | T_EW0 | T_N4, 0x22, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpinsrq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op, uint8 imm) {
  if (!(x1.isXMM() && x2.isXMM() && (op.isREG(64) || op.isMEM())))
    throw Error(ERR_BAD_COMBINATION);
  opVex(x1, &x2, op, T_0F3A | T_66 | T_W1 | T_EVEX | T_EW1 | T_N8, 0x22, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpinsrw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op, uint8 imm) {
  if (!(x1.isXMM() && x2.isXMM() && (op.isREG(32) || op.isMEM())))
    throw Error(ERR_BAD_COMBINATION);
  opVex(x1, &x2, op, T_0F | T_66 | T_EVEX | T_N2, 0xC4, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmaddubsw(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x04);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmaddwd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xF5);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmaskmovd(const Address &addr, const Xmm &x1,
                                      const Xmm &x2) {
  opAVX_X_X_XM(x2, x1, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x8E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmaskmovd(const Xmm &x1, const Xmm &x2,
                                      const Address &addr) {
  opAVX_X_X_XM(x1, x2, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x8C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmaskmovq(const Address &addr, const Xmm &x1,
                                      const Xmm &x2) {
  opAVX_X_X_XM(x2, x1, addr, T_0F38 | T_66 | T_W1 | T_YMM, 0x8E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmaskmovq(const Xmm &x1, const Xmm &x2,
                                      const Address &addr) {
  opAVX_X_X_XM(x1, x2, addr, T_0F38 | T_66 | T_W1 | T_YMM, 0x8C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmaxsb(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x3C);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmaxsd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX | T_B32,
               0x3D);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmaxsw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xEE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmaxub(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xDE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmaxud(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX | T_B32,
               0x3F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmaxuw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x3E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpminsb(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpminsd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX | T_B32,
               0x39);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpminsw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xEA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpminub(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xDA);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpminud(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX | T_B32,
               0x3B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpminuw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovmskb(const Reg32e &r, const Xmm &x) {
  if (!x.is(Operand::XMM | Operand::YMM))
    throw Error(ERR_BAD_COMBINATION);
  opVex(x.isYMM() ? Ymm(r.getIdx()) : Xmm(r.getIdx()), 0, x,
        T_0F | T_66 | T_YMM, 0xD7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovsxbd(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N4 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x21);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmovsxbq(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N2 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x22);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovsxbw(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N8 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x20);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmovsxdq(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N8 | T_N_VL | T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX,
                 0x25);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovsxwd(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N8 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x23);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmovsxwq(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N4 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x24);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovzxbd(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N4 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x31);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmovzxbq(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N2 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x32);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovzxbw(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N8 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x30);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovzxdq(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N8 | T_N_VL | T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX,
                 0x35);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovzxwd(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N8 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x33);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmovzxwq(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N4 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x34);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmuldq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_EVEX | T_B64,
               0x28);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmulhrsw(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x0B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmulhuw(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xE4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmulhw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xE5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmulld(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX | T_B32,
               0x40);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmullw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xD5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmuludq(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0xF4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpor(const Xmm &x1, const Xmm &x2,
                                const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0xEB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsadbw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xF6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshufb(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x00);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpshufd(const Xmm &xm, const Operand &op,
                                   uint8 imm) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0x70,
                 imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpshufhw(const Xmm &xm, const Operand &op,
                                    uint8 imm) {
  opAVX_X_XM_IMM(xm, op, T_F3 | T_0F | T_YMM | T_EVEX, 0x70, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshuflw(const Xmm &xm, const Operand &op,
                                    uint8 imm) {
  opAVX_X_XM_IMM(xm, op, T_F2 | T_0F | T_YMM | T_EVEX, 0x70, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsignb(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x08);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsignd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x0A);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpsignw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x09);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpslld(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 6), x, op,
               T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32 | T_MEM_EVEX, 0x72,
               imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpslld(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_EW0 | T_YMM | T_EVEX, 0xF2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpslldq(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 7), x, op,
               T_66 | T_0F | T_YMM | T_EVEX | T_MEM_EVEX, 0x73, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsllq(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 6), x, op,
               T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64 | T_MEM_EVEX, 0x73,
               imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsllq(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_EW1 | T_YMM | T_EVEX, 0xF3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsllvd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x47);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsllvq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x47);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsllw(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 6), x, op,
               T_66 | T_0F | T_YMM | T_EVEX | T_MEM_EVEX, 0x71, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsllw(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_YMM | T_EVEX, 0xF1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrad(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 4), x, op,
               T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32 | T_MEM_EVEX, 0x72,
               imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpsrad(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_EW0 | T_YMM | T_EVEX, 0xE2);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpsravd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x46);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsraw(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 4), x, op,
               T_66 | T_0F | T_YMM | T_EVEX | T_MEM_EVEX, 0x71, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsraw(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_YMM | T_EVEX, 0xE1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrld(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 2), x, op,
               T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32 | T_MEM_EVEX, 0x72,
               imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpsrld(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_EW0 | T_YMM | T_EVEX, 0xD2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrldq(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 3), x, op,
               T_66 | T_0F | T_YMM | T_EVEX | T_MEM_EVEX, 0x73, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrlq(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 2), x, op,
               T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64 | T_MEM_EVEX, 0x73,
               imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrlq(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_EW1 | T_YMM | T_EVEX, 0xD3);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrlvd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x45);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrlvq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x45);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrlw(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 2), x, op,
               T_66 | T_0F | T_YMM | T_EVEX | T_MEM_EVEX, 0x71, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrlw(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_YMM | T_EVEX, 0xD1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsubb(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xF8);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpsubd(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0xFA);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpsubq(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0xFB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsubsb(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xE8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsubsw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xE9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsubusb(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xD8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsubusw(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xD9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsubw(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xF9);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vptest(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F38 | T_YMM, 0x17);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpunpckhbw(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0x68);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpunpckhdq(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0x6A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpunpckhqdq(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0x6D);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpunpckhwd(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0x69);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpunpcklbw(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0x60);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpunpckldq(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0x62);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpunpcklqdq(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0x6C);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpunpcklwd(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0x61);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpxor(const Xmm &x1, const Xmm &x2,
                                 const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0xEF);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vrcpps(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_0F | T_YMM, 0x53);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrcpss(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_F3 | T_0F, 0x53);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vroundpd(const Xmm &xm, const Operand &op,
                                    uint8 imm) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A | T_YMM, 0x09, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vroundps(const Xmm &xm, const Operand &op,
                                    uint8 imm) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A | T_YMM, 0x08, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vroundsd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0, 0x0B, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vroundss(const Xmm &x1, const Xmm &x2,
                                    const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0, 0x0A, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrsqrtps(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_0F | T_YMM, 0x52);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrsqrtss(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_F3 | T_0F, 0x52);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vshufpd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0xC6,
               imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vshufps(const Xmm &x1, const Xmm &x2,
                                   const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0xC6, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vsqrtpd(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64,
                 0x51);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vsqrtps(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x51);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vsqrtsd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N8 | T_F2 | T_0F | T_EW1 | T_EVEX | T_ER_X, 0x51);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vsqrtss(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_F3 | T_0F | T_EW0 | T_EVEX | T_ER_X, 0x51);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vstmxcsr(const Address &addr) {
  opAVX_X_X_XM(xm3, xm0, addr, T_0F, 0xAE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vsubpd(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2,
               T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x5C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vsubps(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32,
               0x5C);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vsubsd(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F2 | T_EW1 | T_EVEX | T_ER_Z | T_N8,
               0x5C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vsubss(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F3 | T_EW0 | T_EVEX | T_ER_Z | T_N4,
               0x5C);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vtestpd(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F38 | T_YMM, 0x0F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vtestps(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_66 | T_0F38 | T_YMM, 0x0E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vucomisd(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N8 | T_66 | T_0F | T_EW1 | T_EVEX | T_SAE_X, 0x2E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vucomiss(const Xmm &xm, const Operand &op) {
  opAVX_X_XM_IMM(xm, op, T_N4 | T_0F | T_EW0 | T_EVEX | T_SAE_X, 0x2E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vunpckhpd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0x15);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vunpckhps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0x15);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vunpcklpd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0x14);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vunpcklps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0x14);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vxorpd(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2,
               T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x57);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vxorps(const Xmm &xmm, const Operand &op1,
                                  const Operand &op2) {
  opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32,
               0x57);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vzeroall() {
  db(0xC5);
  db(0xFC);
  db(0x77);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vzeroupper() {
  db(0xC5);
  db(0xF8);
  db(0x77);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::wait() {
  db(0x9B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::wbinvd() {
  db(0x0F);
  db(0x09);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::wrmsr() {
  db(0x0F);
  db(0x30);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::xadd(const Operand &op, const Reg &reg) {
  opModRM(reg, op, (op.isREG() && reg.isREG() && op.getBit() == reg.getBit()),
          op.isMEM(), 0x0F, 0xC0 | (reg.isBit(8) ? 0 : 1));
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::xgetbv() {
  db(0x0F);
  db(0x01);
  db(0xD0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::xlatb() {
  db(0xD7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::xor_(const Operand &op, uint32 imm) {
  opRM_I(op, imm, 0x30, 6);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::xor_(const Operand &op1, const Operand &op2) {
  opRM_RM(op1, op2, 0x30);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::xorpd(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x57, 0x66, isXMM_XMMorMEM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::xorps(const Xmm &xmm, const Operand &op) {
  opGen(xmm, op, 0x57, 0x100, isXMM_XMMorMEM);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vblendpd(const Xmm &x, const Operand &op,
                                    uint8 imm) {
  vblendpd(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vblendps(const Xmm &x, const Operand &op,
                                    uint8 imm) {
  vblendps(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vblendvpd(const Xmm &x1, const Operand &op,
                                     const Xmm &x4) {
  vblendvpd(x1, x1, op, x4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vblendvps(const Xmm &x1, const Operand &op,
                                     const Xmm &x4) {
  vblendvps(x1, x1, op, x4); /*decodeAndTransToAArch64();*/
}
void Xbyak::CodeGenerator::vcmpeq_ospd(const Xmm &x, const Operand &op) {
  vcmpeq_ospd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_osps(const Xmm &x, const Operand &op) {
  vcmpeq_osps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpeq_ossd(const Xmm &x, const Operand &op) {
  vcmpeq_ossd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_osss(const Xmm &x, const Operand &op) {
  vcmpeq_osss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_uqpd(const Xmm &x, const Operand &op) {
  vcmpeq_uqpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_uqps(const Xmm &x, const Operand &op) {
  vcmpeq_uqps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpeq_uqsd(const Xmm &x, const Operand &op) {
  vcmpeq_uqsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_uqss(const Xmm &x, const Operand &op) {
  vcmpeq_uqss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_uspd(const Xmm &x, const Operand &op) {
  vcmpeq_uspd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_usps(const Xmm &x, const Operand &op) {
  vcmpeq_usps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpeq_ussd(const Xmm &x, const Operand &op) {
  vcmpeq_ussd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeq_usss(const Xmm &x, const Operand &op) {
  vcmpeq_usss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeqpd(const Xmm &x, const Operand &op) {
  vcmpeqpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeqps(const Xmm &x, const Operand &op) {
  vcmpeqps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpeqsd(const Xmm &x, const Operand &op) {
  vcmpeqsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpeqss(const Xmm &x, const Operand &op) {
  vcmpeqss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpfalse_ospd(const Xmm &x, const Operand &op) {
  vcmpfalse_ospd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpfalse_osps(const Xmm &x, const Operand &op) {
  vcmpfalse_osps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpfalse_ossd(const Xmm &x, const Operand &op) {
  vcmpfalse_ossd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpfalse_osss(const Xmm &x, const Operand &op) {
  vcmpfalse_osss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpfalsepd(const Xmm &x, const Operand &op) {
  vcmpfalsepd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpfalseps(const Xmm &x, const Operand &op) {
  vcmpfalseps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpfalsesd(const Xmm &x, const Operand &op) {
  vcmpfalsesd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpfalsess(const Xmm &x, const Operand &op) {
  vcmpfalsess(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpge_oqpd(const Xmm &x, const Operand &op) {
  vcmpge_oqpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpge_oqps(const Xmm &x, const Operand &op) {
  vcmpge_oqps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpge_oqsd(const Xmm &x, const Operand &op) {
  vcmpge_oqsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpge_oqss(const Xmm &x, const Operand &op) {
  vcmpge_oqss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgepd(const Xmm &x, const Operand &op) {
  vcmpgepd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgeps(const Xmm &x, const Operand &op) {
  vcmpgeps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpgesd(const Xmm &x, const Operand &op) {
  vcmpgesd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgess(const Xmm &x, const Operand &op) {
  vcmpgess(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgt_oqpd(const Xmm &x, const Operand &op) {
  vcmpgt_oqpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgt_oqps(const Xmm &x, const Operand &op) {
  vcmpgt_oqps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpgt_oqsd(const Xmm &x, const Operand &op) {
  vcmpgt_oqsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgt_oqss(const Xmm &x, const Operand &op) {
  vcmpgt_oqss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgtpd(const Xmm &x, const Operand &op) {
  vcmpgtpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgtps(const Xmm &x, const Operand &op) {
  vcmpgtps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpgtsd(const Xmm &x, const Operand &op) {
  vcmpgtsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpgtss(const Xmm &x, const Operand &op) {
  vcmpgtss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmple_oqpd(const Xmm &x, const Operand &op) {
  vcmple_oqpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmple_oqps(const Xmm &x, const Operand &op) {
  vcmple_oqps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmple_oqsd(const Xmm &x, const Operand &op) {
  vcmple_oqsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmple_oqss(const Xmm &x, const Operand &op) {
  vcmple_oqss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmplepd(const Xmm &x, const Operand &op) {
  vcmplepd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpleps(const Xmm &x, const Operand &op) {
  vcmpleps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmplesd(const Xmm &x, const Operand &op) {
  vcmplesd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpless(const Xmm &x, const Operand &op) {
  vcmpless(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmplt_oqpd(const Xmm &x, const Operand &op) {
  vcmplt_oqpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmplt_oqps(const Xmm &x, const Operand &op) {
  vcmplt_oqps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmplt_oqsd(const Xmm &x, const Operand &op) {
  vcmplt_oqsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmplt_oqss(const Xmm &x, const Operand &op) {
  vcmplt_oqss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpltpd(const Xmm &x, const Operand &op) {
  vcmpltpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpltps(const Xmm &x, const Operand &op) {
  vcmpltps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpltsd(const Xmm &x, const Operand &op) {
  vcmpltsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpltss(const Xmm &x, const Operand &op) {
  vcmpltss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_oqpd(const Xmm &x, const Operand &op) {
  vcmpneq_oqpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_oqps(const Xmm &x, const Operand &op) {
  vcmpneq_oqps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpneq_oqsd(const Xmm &x, const Operand &op) {
  vcmpneq_oqsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_oqss(const Xmm &x, const Operand &op) {
  vcmpneq_oqss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_ospd(const Xmm &x, const Operand &op) {
  vcmpneq_ospd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_osps(const Xmm &x, const Operand &op) {
  vcmpneq_osps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpneq_ossd(const Xmm &x, const Operand &op) {
  vcmpneq_ossd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_osss(const Xmm &x, const Operand &op) {
  vcmpneq_osss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_uspd(const Xmm &x, const Operand &op) {
  vcmpneq_uspd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_usps(const Xmm &x, const Operand &op) {
  vcmpneq_usps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpneq_ussd(const Xmm &x, const Operand &op) {
  vcmpneq_ussd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneq_usss(const Xmm &x, const Operand &op) {
  vcmpneq_usss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneqpd(const Xmm &x, const Operand &op) {
  vcmpneqpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneqps(const Xmm &x, const Operand &op) {
  vcmpneqps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpneqsd(const Xmm &x, const Operand &op) {
  vcmpneqsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpneqss(const Xmm &x, const Operand &op) {
  vcmpneqss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnge_uqpd(const Xmm &x, const Operand &op) {
  vcmpnge_uqpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnge_uqps(const Xmm &x, const Operand &op) {
  vcmpnge_uqps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpnge_uqsd(const Xmm &x, const Operand &op) {
  vcmpnge_uqsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnge_uqss(const Xmm &x, const Operand &op) {
  vcmpnge_uqss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngepd(const Xmm &x, const Operand &op) {
  vcmpngepd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngeps(const Xmm &x, const Operand &op) {
  vcmpngeps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpngesd(const Xmm &x, const Operand &op) {
  vcmpngesd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngess(const Xmm &x, const Operand &op) {
  vcmpngess(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngt_uqpd(const Xmm &x, const Operand &op) {
  vcmpngt_uqpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngt_uqps(const Xmm &x, const Operand &op) {
  vcmpngt_uqps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpngt_uqsd(const Xmm &x, const Operand &op) {
  vcmpngt_uqsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngt_uqss(const Xmm &x, const Operand &op) {
  vcmpngt_uqss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngtpd(const Xmm &x, const Operand &op) {
  vcmpngtpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngtps(const Xmm &x, const Operand &op) {
  vcmpngtps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpngtsd(const Xmm &x, const Operand &op) {
  vcmpngtsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpngtss(const Xmm &x, const Operand &op) {
  vcmpngtss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnle_uqpd(const Xmm &x, const Operand &op) {
  vcmpnle_uqpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnle_uqps(const Xmm &x, const Operand &op) {
  vcmpnle_uqps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpnle_uqsd(const Xmm &x, const Operand &op) {
  vcmpnle_uqsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnle_uqss(const Xmm &x, const Operand &op) {
  vcmpnle_uqss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnlepd(const Xmm &x, const Operand &op) {
  vcmpnlepd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnleps(const Xmm &x, const Operand &op) {
  vcmpnleps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpnlesd(const Xmm &x, const Operand &op) {
  vcmpnlesd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnless(const Xmm &x, const Operand &op) {
  vcmpnless(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnlt_uqpd(const Xmm &x, const Operand &op) {
  vcmpnlt_uqpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnlt_uqps(const Xmm &x, const Operand &op) {
  vcmpnlt_uqps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpnlt_uqsd(const Xmm &x, const Operand &op) {
  vcmpnlt_uqsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnlt_uqss(const Xmm &x, const Operand &op) {
  vcmpnlt_uqss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnltpd(const Xmm &x, const Operand &op) {
  vcmpnltpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnltps(const Xmm &x, const Operand &op) {
  vcmpnltps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpnltsd(const Xmm &x, const Operand &op) {
  vcmpnltsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpnltss(const Xmm &x, const Operand &op) {
  vcmpnltss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpord_spd(const Xmm &x, const Operand &op) {
  vcmpord_spd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpord_sps(const Xmm &x, const Operand &op) {
  vcmpord_sps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpord_ssd(const Xmm &x, const Operand &op) {
  vcmpord_ssd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpord_sss(const Xmm &x, const Operand &op) {
  vcmpord_sss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpordpd(const Xmm &x, const Operand &op) {
  vcmpordpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpordps(const Xmm &x, const Operand &op) {
  vcmpordps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpordsd(const Xmm &x, const Operand &op) {
  vcmpordsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpordss(const Xmm &x, const Operand &op) {
  vcmpordss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmppd(const Xmm &x, const Operand &op, uint8 imm) {
  vcmppd(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpps(const Xmm &x, const Operand &op, uint8 imm) {
  vcmpps(x, x, op, imm);
}
void Xbyak::CodeGenerator::vcmpsd(const Xmm &x, const Operand &op, uint8 imm) {
  vcmpsd(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpss(const Xmm &x, const Operand &op, uint8 imm) {
  vcmpss(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmptrue_uspd(const Xmm &x, const Operand &op) {
  vcmptrue_uspd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmptrue_usps(const Xmm &x, const Operand &op) {
  vcmptrue_usps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmptrue_ussd(const Xmm &x, const Operand &op) {
  vcmptrue_ussd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmptrue_usss(const Xmm &x, const Operand &op) {
  vcmptrue_usss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmptruepd(const Xmm &x, const Operand &op) {
  vcmptruepd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmptrueps(const Xmm &x, const Operand &op) {
  vcmptrueps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmptruesd(const Xmm &x, const Operand &op) {
  vcmptruesd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmptruess(const Xmm &x, const Operand &op) {
  vcmptruess(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpunord_spd(const Xmm &x, const Operand &op) {
  vcmpunord_spd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpunord_sps(const Xmm &x, const Operand &op) {
  vcmpunord_sps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpunord_ssd(const Xmm &x, const Operand &op) {
  vcmpunord_ssd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpunord_sss(const Xmm &x, const Operand &op) {
  vcmpunord_sss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpunordpd(const Xmm &x, const Operand &op) {
  vcmpunordpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpunordps(const Xmm &x, const Operand &op) {
  vcmpunordps(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpunordsd(const Xmm &x, const Operand &op) {
  vcmpunordsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpunordss(const Xmm &x, const Operand &op) {
  vcmpunordss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtsd2ss(const Xmm &x, const Operand &op) {
  vcvtsd2ss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtsi2sd(const Xmm &x, const Operand &op) {
  vcvtsi2sd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtsi2ss(const Xmm &x, const Operand &op) {
  vcvtsi2ss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtss2sd(const Xmm &x, const Operand &op) {
  vcvtss2sd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vdppd(const Xmm &x, const Operand &op, uint8 imm) {
  vdppd(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vdpps(const Xmm &x, const Operand &op, uint8 imm) {
  vdpps(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vinsertps(const Xmm &x, const Operand &op,
                                     uint8 imm) {
  vinsertps(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmpsadbw(const Xmm &x, const Operand &op,
                                    uint8 imm) {
  vmpsadbw(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpackssdw(const Xmm &x, const Operand &op) {
  vpackssdw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpacksswb(const Xmm &x, const Operand &op) {
  vpacksswb(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpackusdw(const Xmm &x, const Operand &op) {
  vpackusdw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpackuswb(const Xmm &x, const Operand &op) {
  vpackuswb(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpaddb(const Xmm &x, const Operand &op) {
  vpaddb(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpaddd(const Xmm &x, const Operand &op) {
  vpaddd(x, x, op);
}
void Xbyak::CodeGenerator::vpaddq(const Xmm &x, const Operand &op) {
  vpaddq(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpaddsb(const Xmm &x, const Operand &op) {
  vpaddsb(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpaddsw(const Xmm &x, const Operand &op) {
  vpaddsw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpaddusb(const Xmm &x, const Operand &op) {
  vpaddusb(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpaddusw(const Xmm &x, const Operand &op) {
  vpaddusw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpaddw(const Xmm &x, const Operand &op) {
  vpaddw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpalignr(const Xmm &x, const Operand &op,
                                    uint8 imm) {
  vpalignr(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpand(const Xmm &x, const Operand &op) {
  vpand(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpandn(const Xmm &x, const Operand &op) {
  vpandn(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpavgb(const Xmm &x, const Operand &op) {
  vpavgb(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpavgw(const Xmm &x, const Operand &op) {
  vpavgw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpblendd(const Xmm &x, const Operand &op,
                                    uint8 imm) {
  vpblendd(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpblendvb(const Xmm &x1, const Operand &op,
                                     const Xmm &x4) {
  vpblendvb(x1, x1, op, x4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpblendw(const Xmm &x, const Operand &op,
                                    uint8 imm) {
  vpblendw(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpclmulqdq(const Xmm &x, const Operand &op,
                                      uint8 imm) {
  vpclmulqdq(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpeqb(const Xmm &x, const Operand &op) {
  vpcmpeqb(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpeqd(const Xmm &x, const Operand &op) {
  vpcmpeqd(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpcmpeqq(const Xmm &x, const Operand &op) {
  vpcmpeqq(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpeqw(const Xmm &x, const Operand &op) {
  vpcmpeqw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpgtb(const Xmm &x, const Operand &op) {
  vpcmpgtb(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpgtd(const Xmm &x, const Operand &op) {
  vpcmpgtd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpgtq(const Xmm &x, const Operand &op) {
  vpcmpgtq(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpgtw(const Xmm &x, const Operand &op) {
  vpcmpgtw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vphaddd(const Xmm &x, const Operand &op) {
  vphaddd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vphaddsw(const Xmm &x, const Operand &op) {
  vphaddsw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vphaddw(const Xmm &x, const Operand &op) {
  vphaddw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vphsubd(const Xmm &x, const Operand &op) {
  vphsubd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vphsubsw(const Xmm &x, const Operand &op) {
  vphsubsw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vphsubw(const Xmm &x, const Operand &op) {
  vphsubw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpinsrb(const Xmm &x, const Operand &op, uint8 imm) {
  vpinsrb(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpinsrd(const Xmm &x, const Operand &op, uint8 imm) {
  vpinsrd(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpinsrq(const Xmm &x, const Operand &op, uint8 imm) {
  vpinsrq(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpinsrw(const Xmm &x, const Operand &op, uint8 imm) {
  vpinsrw(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmaddubsw(const Xmm &x, const Operand &op) {
  vpmaddubsw(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmaddwd(const Xmm &x, const Operand &op) {
  vpmaddwd(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmaxsb(const Xmm &x, const Operand &op) {
  vpmaxsb(x, x, op);
}
void Xbyak::CodeGenerator::vpmaxsd(const Xmm &x, const Operand &op) {
  vpmaxsd(x, x, op);
}
void Xbyak::CodeGenerator::vpmaxsw(const Xmm &x, const Operand &op) {
  vpmaxsw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmaxub(const Xmm &x, const Operand &op) {
  vpmaxub(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmaxud(const Xmm &x, const Operand &op) {
  vpmaxud(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmaxuw(const Xmm &x, const Operand &op) {
  vpmaxuw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpminsb(const Xmm &x, const Operand &op) {
  vpminsb(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpminsd(const Xmm &x, const Operand &op) {
  vpminsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpminsw(const Xmm &x, const Operand &op) {
  vpminsw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpminub(const Xmm &x, const Operand &op) {
  vpminub(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpminud(const Xmm &x, const Operand &op) {
  vpminud(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpminuw(const Xmm &x, const Operand &op) {
  vpminuw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmuldq(const Xmm &x, const Operand &op) {
  vpmuldq(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmulhrsw(const Xmm &x, const Operand &op) {
  vpmulhrsw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmulhuw(const Xmm &x, const Operand &op) {
  vpmulhuw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmulhw(const Xmm &x, const Operand &op) {
  vpmulhw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmulld(const Xmm &x, const Operand &op) {
  vpmulld(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmullw(const Xmm &x, const Operand &op) {
  vpmullw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmuludq(const Xmm &x, const Operand &op) {
  vpmuludq(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpor(const Xmm &x, const Operand &op) {
  vpor(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsadbw(const Xmm &x, const Operand &op) {
  vpsadbw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsignb(const Xmm &x, const Operand &op) {
  vpsignb(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsignd(const Xmm &x, const Operand &op) {
  vpsignd(x, x, op);
}
void Xbyak::CodeGenerator::vpsignw(const Xmm &x, const Operand &op) {
  vpsignw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpslld(const Xmm &x, const Operand &op) {
  vpslld(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpslld(const Xmm &x, uint8 imm) {
  vpslld(x, x, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpslldq(const Xmm &x, uint8 imm) {
  vpslldq(x, x, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsllq(const Xmm &x, const Operand &op) {
  vpsllq(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsllq(const Xmm &x, uint8 imm) {
  vpsllq(x, x, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsllw(const Xmm &x, const Operand &op) {
  vpsllw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsllw(const Xmm &x, uint8 imm) {
  vpsllw(x, x, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrad(const Xmm &x, const Operand &op) {
  vpsrad(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrad(const Xmm &x, uint8 imm) {
  vpsrad(x, x, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsraw(const Xmm &x, const Operand &op) {
  vpsraw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsraw(const Xmm &x, uint8 imm) {
  vpsraw(x, x, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrld(const Xmm &x, const Operand &op) {
  vpsrld(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrld(const Xmm &x, uint8 imm) {
  vpsrld(x, x, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrldq(const Xmm &x, uint8 imm) {
  vpsrldq(x, x, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrlq(const Xmm &x, const Operand &op) {
  vpsrlq(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrlq(const Xmm &x, uint8 imm) {
  vpsrlq(x, x, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrlw(const Xmm &x, const Operand &op) {
  vpsrlw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrlw(const Xmm &x, uint8 imm) {
  vpsrlw(x, x, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsubb(const Xmm &x, const Operand &op) {
  vpsubb(x, x, op);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpsubd(const Xmm &x, const Operand &op) {
  vpsubd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsubq(const Xmm &x, const Operand &op) {
  vpsubq(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsubsb(const Xmm &x, const Operand &op) {
  vpsubsb(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsubsw(const Xmm &x, const Operand &op) {
  vpsubsw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsubusb(const Xmm &x, const Operand &op) {
  vpsubusb(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsubusw(const Xmm &x, const Operand &op) {
  vpsubusw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsubw(const Xmm &x, const Operand &op) {
  vpsubw(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpunpckhbw(const Xmm &x, const Operand &op) {
  vpunpckhbw(x, x, op); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::vpunpckhdq(const Xmm &x, const Operand &op) {
  vpunpckhdq(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpunpckhqdq(const Xmm &x, const Operand &op) {
  vpunpckhqdq(x, x, op); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::vpunpckhwd(const Xmm &x, const Operand &op) {
  vpunpckhwd(x, x, op); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::vpunpcklbw(const Xmm &x, const Operand &op) {
  vpunpcklbw(x, x, op); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::vpunpckldq(const Xmm &x, const Operand &op) {
  vpunpckldq(x, x, op); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::vpunpcklqdq(const Xmm &x, const Operand &op) {
  vpunpcklqdq(x, x, op); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::vpunpcklwd(const Xmm &x, const Operand &op) {
  vpunpcklwd(x, x, op); /*UNIMPLEMENTED;*/
}
void Xbyak::CodeGenerator::vpxor(const Xmm &x, const Operand &op) {
  vpxor(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrcpss(const Xmm &x, const Operand &op) {
  vrcpss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vroundsd(const Xmm &x, const Operand &op,
                                    uint8 imm) {
  vroundsd(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vroundss(const Xmm &x, const Operand &op,
                                    uint8 imm) {
  vroundss(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrsqrtss(const Xmm &x, const Operand &op) {
  vrsqrtss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vshufpd(const Xmm &x, const Operand &op, uint8 imm) {
  vshufpd(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vshufps(const Xmm &x, const Operand &op, uint8 imm) {
  vshufps(x, x, op, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vsqrtsd(const Xmm &x, const Operand &op) {
  vsqrtsd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vsqrtss(const Xmm &x, const Operand &op) {
  vsqrtss(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vunpckhpd(const Xmm &x, const Operand &op) {
  vunpckhpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vunpckhps(const Xmm &x, const Operand &op) {
  vunpckhps(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vunpcklpd(const Xmm &x, const Operand &op) {
  vunpcklpd(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vunpcklps(const Xmm &x, const Operand &op) {
  vunpcklps(x, x, op);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::jecxz(std::string label) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jecxz(const Label &label) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jrcxz(std::string label) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::jrcxz(const Label &label) { UNIMPLEMENTED; }
void Xbyak::CodeGenerator::cdqe() {
  db(0x48);
  db(0x98);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cqo() {
  db(0x48);
  db(0x99);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpsq() {
  db(0x48);
  db(0xA7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::popfq() {
  db(0x9D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pushfq() {
  db(0x9C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::lodsq() {
  db(0x48);
  db(0xAD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movsq() {
  db(0x48);
  db(0xA5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::scasq() {
  db(0x48);
  db(0xAF);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::stosq() {
  db(0x48);
  db(0xAB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::syscall() {
  db(0x0F);
  db(0x05);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::sysret() {
  db(0x0F);
  db(0x07);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::cmpxchg16b(const Address &addr) {
  opModM(addr, Reg64(1), 0x0F, 0xC7);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::fxrstor64(const Address &addr) {
  opModM(addr, Reg64(1), 0x0F, 0xAE);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::movq(const Reg64 &reg, const Mmx &mmx) {
  if (mmx.isXMM())
    db(0x66);
  opModR(mmx, reg, 0x0F, 0x7E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movq(const Mmx &mmx, const Reg64 &reg) {
  if (mmx.isXMM())
    db(0x66);
  opModR(mmx, reg, 0x0F, 0x6E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::movsxd(const Reg64 &reg, const Operand &op) {
  if (!op.isBit(32))
    throw Error(ERR_BAD_COMBINATION);
  opModRM(reg, op, op.isREG(), op.isMEM(), 0x63);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pextrq(const Operand &op, const Xmm &xmm,
                                  uint8 imm) {
  if (!op.isREG(64) && !op.isMEM())
    throw Error(ERR_BAD_COMBINATION);
  opGen(Reg64(xmm.getIdx()), op, 0x16, 0x66, 0, imm, 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::pinsrq(const Xmm &xmm, const Operand &op,
                                  uint8 imm) {
  if (!op.isREG(64) && !op.isMEM())
    throw Error(ERR_BAD_COMBINATION);
  opGen(Reg64(xmm.getIdx()), op, 0x22, 0x66, 0, imm, 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtss2si(const Reg64 &r, const Operand &op) {
  opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op,
               T_0F | T_F3 | T_W1 | T_EVEX | T_EW1 | T_ER_X | T_N8, 0x2D);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcvttss2si(const Reg64 &r, const Operand &op) {
  opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op,
               T_0F | T_F3 | T_W1 | T_EVEX | T_EW1 | T_SAE_X | T_N8, 0x2C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtsd2si(const Reg64 &r, const Operand &op) {
  opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op,
               T_0F | T_F2 | T_W1 | T_EVEX | T_EW1 | T_N4 | T_ER_X, 0x2D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvttsd2si(const Reg64 &r, const Operand &op) {
  opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op,
               T_0F | T_F2 | T_W1 | T_EVEX | T_EW1 | T_N4 | T_SAE_X, 0x2C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovq(const Xmm &x, const Reg64 &r) {
  opAVX_X_X_XM(x, xm0, Xmm(r.getIdx()), T_66 | T_0F | T_W1 | T_EVEX | T_EW1,
               0x6E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovq(const Reg64 &r, const Xmm &x) {
  opAVX_X_X_XM(x, xm0, Xmm(r.getIdx()), T_66 | T_0F | T_W1 | T_EVEX | T_EW1,
               0x7E);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::kaddb(const Opmask &r1, const Opmask &r2,
                                 const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W0, 0x4A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kaddd(const Opmask &r1, const Opmask &r2,
                                 const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W1, 0x4A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kaddq(const Opmask &r1, const Opmask &r2,
                                 const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_W1, 0x4A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kaddw(const Opmask &r1, const Opmask &r2,
                                 const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_W0, 0x4A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kandb(const Opmask &r1, const Opmask &r2,
                                 const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W0, 0x41);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kandd(const Opmask &r1, const Opmask &r2,
                                 const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W1, 0x41);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kandnb(const Opmask &r1, const Opmask &r2,
                                  const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W0, 0x42);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kandnd(const Opmask &r1, const Opmask &r2,
                                  const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W1, 0x42);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kandnq(const Opmask &r1, const Opmask &r2,
                                  const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_W1, 0x42);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kandnw(const Opmask &r1, const Opmask &r2,
                                  const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_W0, 0x42);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kandq(const Opmask &r1, const Opmask &r2,
                                 const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_W1, 0x41);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kandw(const Opmask &r1, const Opmask &r2,
                                 const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_W0, 0x41);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kmovb(const Address &addr, const Opmask &k) {
  opVex(k, 0, addr, T_L0 | T_0F | T_66 | T_W0, 0x91);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kmovb(const Opmask &k, const Operand &op) {
  opVex(k, 0, op, T_L0 | T_0F | T_66 | T_W0, 0x90);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kmovb(const Opmask &k, const Reg32 &r) {
  opVex(k, 0, r, T_L0 | T_0F | T_66 | T_W0, 0x92);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kmovb(const Reg32 &r, const Opmask &k) {
  opVex(r, 0, k, T_L0 | T_0F | T_66 | T_W0, 0x93);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kmovd(const Address &addr, const Opmask &k) {
  opVex(k, 0, addr, T_L0 | T_0F | T_66 | T_W1, 0x91);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::kmovd(const Opmask &k, const Operand &op) {
  opVex(k, 0, op, T_L0 | T_0F | T_66 | T_W1, 0x90);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::kmovd(const Opmask &k, const Reg32 &r) {
  opVex(k, 0, r, T_L0 | T_0F | T_F2 | T_W0, 0x92);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::kmovd(const Reg32 &r, const Opmask &k) {
  opVex(r, 0, k, T_L0 | T_0F | T_F2 | T_W0, 0x93);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::kmovq(const Address &addr, const Opmask &k) {
  opVex(k, 0, addr, T_L0 | T_0F | T_W1, 0x91);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::kmovq(const Opmask &k, const Operand &op) {
  opVex(k, 0, op, T_L0 | T_0F | T_W1, 0x90);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::kmovw(const Address &addr, const Opmask &k) {
  opVex(k, 0, addr, T_L0 | T_0F | T_W0, 0x91);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::kmovw(const Opmask &k, const Operand &op) {
  opVex(k, 0, op, T_L0 | T_0F | T_W0, 0x90);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::kmovw(const Opmask &k, const Reg32 &r) {
  opVex(k, 0, r, T_L0 | T_0F | T_W0, 0x92);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::kmovw(const Reg32 &r, const Opmask &k) {
  opVex(r, 0, k, T_L0 | T_0F | T_W0, 0x93);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::knotb(const Opmask &r1, const Opmask &r2) {
  opVex(r1, 0, r2, T_0F | T_66 | T_W0, 0x44);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::knotd(const Opmask &r1, const Opmask &r2) {
  opVex(r1, 0, r2, T_0F | T_66 | T_W1, 0x44);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::knotq(const Opmask &r1, const Opmask &r2) {
  opVex(r1, 0, r2, T_0F | T_W1, 0x44);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::knotw(const Opmask &r1, const Opmask &r2) {
  opVex(r1, 0, r2, T_0F | T_W0, 0x44);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::korb(const Opmask &r1, const Opmask &r2,
                                const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W0, 0x45);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kord(const Opmask &r1, const Opmask &r2,
                                const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W1, 0x45);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::korq(const Opmask &r1, const Opmask &r2,
                                const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_W1, 0x45);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kortestb(const Opmask &r1, const Opmask &r2) {
  opVex(r1, 0, r2, T_0F | T_66 | T_W0, 0x98);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kortestd(const Opmask &r1, const Opmask &r2) {
  opVex(r1, 0, r2, T_0F | T_66 | T_W1, 0x98);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kortestq(const Opmask &r1, const Opmask &r2) {
  opVex(r1, 0, r2, T_0F | T_W1, 0x98);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kortestw(const Opmask &r1, const Opmask &r2) {
  opVex(r1, 0, r2, T_0F | T_W0, 0x98);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::korw(const Opmask &r1, const Opmask &r2,
                                const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_W0, 0x45);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kshiftlb(const Opmask &r1, const Opmask &r2,
                                    uint8 imm) {
  opVex(r1, 0, r2, T_66 | T_0F3A | T_W0, 0x32, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kshiftld(const Opmask &r1, const Opmask &r2,
                                    uint8 imm) {
  opVex(r1, 0, r2, T_66 | T_0F3A | T_W0, 0x33, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kshiftlq(const Opmask &r1, const Opmask &r2,
                                    uint8 imm) {
  opVex(r1, 0, r2, T_66 | T_0F3A | T_W1, 0x33, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kshiftlw(const Opmask &r1, const Opmask &r2,
                                    uint8 imm) {
  opVex(r1, 0, r2, T_66 | T_0F3A | T_W1, 0x32, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kshiftrb(const Opmask &r1, const Opmask &r2,
                                    uint8 imm) {
  opVex(r1, 0, r2, T_66 | T_0F3A | T_W0, 0x30, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kshiftrd(const Opmask &r1, const Opmask &r2,
                                    uint8 imm) {
  opVex(r1, 0, r2, T_66 | T_0F3A | T_W0, 0x31, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kshiftrq(const Opmask &r1, const Opmask &r2,
                                    uint8 imm) {
  opVex(r1, 0, r2, T_66 | T_0F3A | T_W1, 0x31, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kshiftrw(const Opmask &r1, const Opmask &r2,
                                    uint8 imm) {
  opVex(r1, 0, r2, T_66 | T_0F3A | T_W1, 0x30, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ktestb(const Opmask &r1, const Opmask &r2) {
  opVex(r1, 0, r2, T_0F | T_66 | T_W0, 0x99);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ktestd(const Opmask &r1, const Opmask &r2) {
  opVex(r1, 0, r2, T_0F | T_66 | T_W1, 0x99);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::ktestq(const Opmask &r1, const Opmask &r2) {
  opVex(r1, 0, r2, T_0F | T_W1, 0x99);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::ktestw(const Opmask &r1, const Opmask &r2) {
  opVex(r1, 0, r2, T_0F | T_W0, 0x99);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kunpckbw(const Opmask &r1, const Opmask &r2,
                                    const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W0, 0x4B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kunpckdq(const Opmask &r1, const Opmask &r2,
                                    const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_W1, 0x4B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kunpckwd(const Opmask &r1, const Opmask &r2,
                                    const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_W0, 0x4B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kxnorb(const Opmask &r1, const Opmask &r2,
                                  const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W0, 0x46);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kxnord(const Opmask &r1, const Opmask &r2,
                                  const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W1, 0x46);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kxnorq(const Opmask &r1, const Opmask &r2,
                                  const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_W1, 0x46);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kxnorw(const Opmask &r1, const Opmask &r2,
                                  const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_W0, 0x46);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kxorb(const Opmask &r1, const Opmask &r2,
                                 const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W0, 0x47);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kxord(const Opmask &r1, const Opmask &r2,
                                 const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W1, 0x47);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kxorq(const Opmask &r1, const Opmask &r2,
                                 const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_W1, 0x47);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kxorw(const Opmask &r1, const Opmask &r2,
                                 const Opmask &r3) {
  opVex(r1, &r2, r3, T_L1 | T_0F | T_W0, 0x47);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::v4fmaddps(const Zmm &z1, const Zmm &z2,
                                     const Address &addr) {
  opAVX_X_X_XM(z1, z2, addr,
               T_0F38 | T_F2 | T_EW0 | T_YMM | T_MUST_EVEX | T_N16, 0x9A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::v4fmaddss(const Xmm &x1, const Xmm &x2,
                                     const Address &addr) {
  opAVX_X_X_XM(x1, x2, addr, T_0F38 | T_F2 | T_EW0 | T_MUST_EVEX | T_N16, 0x9B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::v4fnmaddps(const Zmm &z1, const Zmm &z2,
                                      const Address &addr) {
  opAVX_X_X_XM(z1, z2, addr,
               T_0F38 | T_F2 | T_EW0 | T_YMM | T_MUST_EVEX | T_N16, 0xAA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::v4fnmaddss(const Xmm &x1, const Xmm &x2,
                                      const Address &addr) {
  opAVX_X_X_XM(x1, x2, addr, T_0F38 | T_F2 | T_EW0 | T_MUST_EVEX | T_N16, 0xAB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::valignd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x03,
               imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::valignq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x03,
               imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vblendmpd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x65);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vblendmps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0x65);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vbroadcastf32x2(const Ymm &y, const Operand &op) {
  opAVX_X_XM_IMM(y, op, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW0 | T_N8,
                 0x19);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vbroadcastf32x4(const Ymm &y, const Address &addr) {
  opAVX_X_XM_IMM(y, addr, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW0 | T_N16,
                 0x1A);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vbroadcastf32x8(const Zmm &y, const Address &addr) {
  opAVX_X_XM_IMM(y, addr, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW0 | T_N32,
                 0x1B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vbroadcastf64x2(const Ymm &y, const Address &addr) {
  opAVX_X_XM_IMM(y, addr, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW1 | T_N16,
                 0x1A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vbroadcastf64x4(const Zmm &y, const Address &addr) {
  opAVX_X_XM_IMM(y, addr, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW1 | T_N32,
                 0x1B);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vbroadcasti32x2(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW0 | T_N8,
                 0x59);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vbroadcasti32x4(const Ymm &y, const Operand &op) {
  opAVX_X_XM_IMM(y, op, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW0 | T_N16,
                 0x5A);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vbroadcasti32x8(const Zmm &z, const Operand &op) {
  opAVX_X_XM_IMM(z, op, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW0 | T_N32,
                 0x5B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vbroadcasti64x2(const Ymm &y, const Operand &op) {
  opAVX_X_XM_IMM(y, op, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW1 | T_N16,
                 0x5A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vbroadcasti64x4(const Zmm &z, const Operand &op) {
  opAVX_X_XM_IMM(z, op, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW1 | T_N32,
                 0x5B);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmppd(const Opmask &k, const Xmm &x,
                                  const Operand &op, uint8 imm) {
  opAVX_K_X_XM(k, x, op,
               T_66 | T_0F | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64,
               0xC2, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpps(const Opmask &k, const Xmm &x,
                                  const Operand &op, uint8 imm) {
  opAVX_K_X_XM(k, x, op, T_0F | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
               0xC2, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vcmpsd(const Opmask &k, const Xmm &x,
                                  const Operand &op, uint8 imm) {
  opAVX_K_X_XM(k, x, op, T_N8 | T_F2 | T_0F | T_EW1 | T_SAE_Z | T_MUST_EVEX,
               0xC2, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcmpss(const Opmask &k, const Xmm &x,
                                  const Operand &op, uint8 imm) {
  opAVX_K_X_XM(k, x, op, T_N4 | T_F3 | T_0F | T_EW0 | T_SAE_Z | T_MUST_EVEX,
               0xC2, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcompressb(const Operand &op, const Xmm &x) {
  opAVX_X_XM_IMM(x, op, T_N1 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
                 0x63);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcompresspd(const Operand &op, const Xmm &x) {
  opAVX_X_XM_IMM(x, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX,
                 0x8A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcompressps(const Operand &op, const Xmm &x) {
  opAVX_X_XM_IMM(x, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
                 0x8A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcompressw(const Operand &op, const Xmm &x) {
  opAVX_X_XM_IMM(x, op, T_N2 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX,
                 0x63);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtne2ps2bf16(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_F2 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
               0x72);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtneps2bf16(const Xmm &x, const Operand &op) {
  opCvt2(x, op, T_F3 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
         0x72);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtpd2qq(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(
      x, op, T_66 | T_0F | T_EW1 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B64, 0x7B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtpd2udq(const Xmm &x, const Operand &op) {
  opCvt2(x, op, T_0F | T_YMM | T_MUST_EVEX | T_EW1 | T_B64 | T_ER_Z, 0x79);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtpd2uqq(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(
      x, op, T_66 | T_0F | T_EW1 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B64, 0x79);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtps2qq(const Xmm &x, const Operand &op) {
  checkCvt1(x, op);
  opVex(x, 0, op,
        T_66 | T_0F | T_YMM | T_MUST_EVEX | T_EW0 | T_B32 | T_N8 | T_N_VL |
            T_ER_Y,
        0x7B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtps2udq(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_0F | T_EW0 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B32,
                 0x79);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtps2uqq(const Xmm &x, const Operand &op) {
  checkCvt1(x, op);
  opVex(x, 0, op,
        T_66 | T_0F | T_YMM | T_MUST_EVEX | T_EW0 | T_B32 | T_N8 | T_N_VL |
            T_ER_Y,
        0x79);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtqq2pd(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(
      x, op, T_F3 | T_0F | T_EW1 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B64, 0xE6);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtqq2ps(const Xmm &x, const Operand &op) {
  opCvt2(x, op, T_0F | T_YMM | T_MUST_EVEX | T_EW1 | T_B64 | T_ER_Z, 0x5B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtsd2usi(const Reg32e &r, const Operand &op) {
  int type = (T_F2 | T_0F | T_MUST_EVEX | T_N8 | T_ER_X) |
             (r.isREG(64) ? T_EW1 : T_EW0);
  opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, type, 0x79);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtss2usi(const Reg32e &r, const Operand &op) {
  int type = (T_F3 | T_0F | T_MUST_EVEX | T_N4 | T_ER_X) |
             (r.isREG(64) ? T_EW1 : T_EW0);
  opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, type, 0x79);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvttpd2qq(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(
      x, op, T_66 | T_0F | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0x7A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvttpd2udq(const Xmm &x, const Operand &op) {
  opCvt2(x, op, T_0F | T_YMM | T_MUST_EVEX | T_EW1 | T_B64 | T_SAE_Z, 0x78);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvttpd2uqq(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(
      x, op, T_66 | T_0F | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0x78);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvttps2qq(const Xmm &x, const Operand &op) {
  checkCvt1(x, op);
  opVex(x, 0, op,
        T_66 | T_0F | T_YMM | T_MUST_EVEX | T_EW0 | T_B32 | T_N8 | T_N_VL |
            T_SAE_Y,
        0x7A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvttps2udq(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_0F | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
                 0x78);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvttps2uqq(const Xmm &x, const Operand &op) {
  checkCvt1(x, op);
  opVex(x, 0, op,
        T_66 | T_0F | T_YMM | T_MUST_EVEX | T_EW0 | T_B32 | T_N8 | T_N_VL |
            T_SAE_Y,
        0x78);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvttsd2usi(const Reg32e &r, const Operand &op) {
  int type = (T_F2 | T_0F | T_MUST_EVEX | T_N8 | T_SAE_X) |
             (r.isREG(64) ? T_EW1 : T_EW0);
  opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, type, 0x78);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvttss2usi(const Reg32e &r, const Operand &op) {
  int type = (T_F3 | T_0F | T_MUST_EVEX | T_N4 | T_SAE_X) |
             (r.isREG(64) ? T_EW1 : T_EW0);
  opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, type, 0x78);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtudq2pd(const Xmm &x, const Operand &op) {
  checkCvt1(x, op);
  opVex(x, 0, op,
        T_F3 | T_0F | T_YMM | T_MUST_EVEX | T_EW0 | T_B32 | T_N8 | T_N_VL,
        0x7A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtudq2ps(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(
      x, op, T_F2 | T_0F | T_EW0 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B32, 0x7A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtuqq2pd(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(
      x, op, T_F3 | T_0F | T_EW1 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B64, 0x7A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtuqq2ps(const Xmm &x, const Operand &op) {
  opCvt2(x, op, T_F2 | T_0F | T_YMM | T_MUST_EVEX | T_EW1 | T_B64 | T_ER_Z,
         0x7A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtusi2sd(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  opCvt3(x1, x2, op, T_F2 | T_0F | T_MUST_EVEX, T_W1 | T_EW1 | T_ER_X | T_N8,
         T_W0 | T_EW0 | T_N4, 0x7B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vcvtusi2ss(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  opCvt3(x1, x2, op, T_F3 | T_0F | T_MUST_EVEX | T_ER_X, T_W1 | T_EW1 | T_N8,
         T_W0 | T_EW0 | T_N4, 0x7B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vdbpsadbw(const Xmm &x1, const Xmm &x2,
                                     const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x42,
               imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vdpbf16ps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_F3 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
               0x52);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vexp2pd(const Zmm &z, const Operand &op) {
  opAVX_X_XM_IMM(z, op,
                 T_66 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW1 | T_B64 | T_SAE_Z,
                 0xC8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vexp2ps(const Zmm &z, const Operand &op) {
  opAVX_X_XM_IMM(z, op,
                 T_66 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW0 | T_B32 | T_SAE_Z,
                 0xC8);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vexpandpd(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX,
                 0x88);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vexpandps(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
                 0x88);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vextractf32x4(const Operand &op, const Ymm &r,
                                         uint8 imm) {
  if (!op.is(Operand::MEM | Operand::XMM))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r, 0, op, T_N16 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x19,
        imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vextractf32x8(const Operand &op, const Zmm &r,
                                         uint8 imm) {
  if (!op.is(Operand::MEM | Operand::YMM))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r, 0, op, T_N32 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x1B,
        imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vextractf64x2(const Operand &op, const Ymm &r,
                                         uint8 imm) {
  if (!op.is(Operand::MEM | Operand::XMM))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r, 0, op, T_N16 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x19,
        imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vextractf64x4(const Operand &op, const Zmm &r,
                                         uint8 imm) {
  if (!op.is(Operand::MEM | Operand::YMM))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r, 0, op, T_N32 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x1B,
        imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vextracti32x4(const Operand &op, const Ymm &r,
                                         uint8 imm) {
  if (!op.is(Operand::MEM | Operand::XMM))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r, 0, op, T_N16 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x39,
        imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vextracti32x8(const Operand &op, const Zmm &r,
                                         uint8 imm) {
  if (!op.is(Operand::MEM | Operand::YMM))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r, 0, op, T_N32 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x3B,
        imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vextracti64x2(const Operand &op, const Ymm &r,
                                         uint8 imm) {
  if (!op.is(Operand::MEM | Operand::XMM))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r, 0, op, T_N16 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x39,
        imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vextracti64x4(const Operand &op, const Zmm &r,
                                         uint8 imm) {
  if (!op.is(Operand::MEM | Operand::YMM))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r, 0, op, T_N32 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x3B,
        imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfixupimmpd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64,
               0x54, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfixupimmps(const Xmm &x1, const Xmm &x2,
                                       const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F3A | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
               0x54, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vfixupimmsd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F3A | T_EW1 | T_SAE_Z | T_MUST_EVEX,
               0x55, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfixupimmss(const Xmm &x1, const Xmm &x2,
                                       const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F3A | T_EW0 | T_SAE_Z | T_MUST_EVEX,
               0x55, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfpclasspd(const Opmask &k, const Operand &op,
                                      uint8 imm) {
  if (!op.isBit(128 | 256 | 512))
    throw Error(ERR_BAD_MEM_SIZE);
  opVex(k.changeBit(op.getBit()), 0, op,
        T_66 | T_0F3A | T_MUST_EVEX | T_YMM | T_EW1 | T_B64, 0x66, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfpclassps(const Opmask &k, const Operand &op,
                                      uint8 imm) {
  if (!op.isBit(128 | 256 | 512))
    throw Error(ERR_BAD_MEM_SIZE);
  opVex(k.changeBit(op.getBit()), 0, op,
        T_66 | T_0F3A | T_MUST_EVEX | T_YMM | T_EW0 | T_B32, 0x66, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfpclasssd(const Opmask &k, const Operand &op,
                                      uint8 imm) {
  if (!op.isXMEM())
    throw Error(ERR_BAD_MEM_SIZE);
  opVex(k, 0, op, T_66 | T_0F3A | T_MUST_EVEX | T_EW1 | T_N8, 0x67, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vfpclassss(const Opmask &k, const Operand &op,
                                      uint8 imm) {
  if (!op.isXMEM())
    throw Error(ERR_BAD_MEM_SIZE);
  opVex(k, 0, op, T_66 | T_0F3A | T_MUST_EVEX | T_EW0 | T_N4, 0x67, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgatherdpd(const Xmm &x, const Address &addr) {
  opGather2(x, addr,
            T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_VSIB, 0x92,
            1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgatherdps(const Xmm &x, const Address &addr) {
  opGather2(x, addr,
            T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_VSIB, 0x92,
            0);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vgatherpf0dpd(const Address &addr) {
  opGatherFetch(addr, zm1,
                T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC6, Operand::YMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgatherpf0dps(const Address &addr) {
  opGatherFetch(addr, zm1,
                T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC6, Operand::ZMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgatherpf0qpd(const Address &addr) {
  opGatherFetch(addr, zm1,
                T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC7, Operand::ZMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgatherpf0qps(const Address &addr) {
  opGatherFetch(addr, zm1,
                T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC7, Operand::ZMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgatherpf1dpd(const Address &addr) {
  opGatherFetch(addr, zm2,
                T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC6, Operand::YMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgatherpf1dps(const Address &addr) {
  opGatherFetch(addr, zm2,
                T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC6, Operand::ZMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgatherpf1qpd(const Address &addr) {
  opGatherFetch(addr, zm2,
                T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC7, Operand::ZMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgatherpf1qps(const Address &addr) {
  opGatherFetch(addr, zm2,
                T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC7, Operand::ZMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgatherqpd(const Xmm &x, const Address &addr) {
  opGather2(x, addr,
            T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_VSIB, 0x93,
            0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgatherqps(const Xmm &x, const Address &addr) {
  opGather2(x, addr,
            T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_VSIB, 0x93,
            2);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vgetexppd(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op,
                 T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64,
                 0x42);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgetexpps(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op,
                 T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
                 0x42);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgetexpsd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_SAE_X | T_MUST_EVEX,
               0x43);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgetexpss(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_SAE_X | T_MUST_EVEX,
               0x43);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgetmantpd(const Xmm &x, const Operand &op,
                                      uint8 imm) {
  opAVX_X_XM_IMM(x, op,
                 T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64,
                 0x26, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgetmantps(const Xmm &x, const Operand &op,
                                      uint8 imm) {
  opAVX_X_XM_IMM(x, op,
                 T_66 | T_0F3A | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
                 0x26, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgetmantsd(const Xmm &x1, const Xmm &x2,
                                      const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F3A | T_EW1 | T_SAE_X | T_MUST_EVEX,
               0x27, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vgetmantss(const Xmm &x1, const Xmm &x2,
                                      const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F3A | T_EW0 | T_SAE_X | T_MUST_EVEX,
               0x27, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vinsertf32x4(const Ymm &r1, const Ymm &r2,
                                        const Operand &op, uint8 imm) {
  if (!(r1.getKind() == r2.getKind() && op.is(Operand::MEM | Operand::XMM)))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r1, &r2, op, T_N16 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x18,
        imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vinsertf32x8(const Zmm &r1, const Zmm &r2,
                                        const Operand &op, uint8 imm) {
  if (!op.is(Operand::MEM | Operand::YMM))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r1, &r2, op, T_N32 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x1A,
        imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vinsertf64x2(const Ymm &r1, const Ymm &r2,
                                        const Operand &op, uint8 imm) {
  if (!(r1.getKind() == r2.getKind() && op.is(Operand::MEM | Operand::XMM)))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r1, &r2, op, T_N16 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x18,
        imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vinsertf64x4(const Zmm &r1, const Zmm &r2,
                                        const Operand &op, uint8 imm) {
  if (!op.is(Operand::MEM | Operand::YMM))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r1, &r2, op, T_N32 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x1A,
        imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vinserti32x4(const Ymm &r1, const Ymm &r2,
                                        const Operand &op, uint8 imm) {
  if (!(r1.getKind() == r2.getKind() && op.is(Operand::MEM | Operand::XMM)))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r1, &r2, op, T_N16 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x38,
        imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vinserti32x8(const Zmm &r1, const Zmm &r2,
                                        const Operand &op, uint8 imm) {
  if (!op.is(Operand::MEM | Operand::YMM))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r1, &r2, op, T_N32 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x3A,
        imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vinserti64x2(const Ymm &r1, const Ymm &r2,
                                        const Operand &op, uint8 imm) {
  if (!(r1.getKind() == r2.getKind() && op.is(Operand::MEM | Operand::XMM)))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r1, &r2, op, T_N16 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x38,
        imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vinserti64x4(const Zmm &r1, const Zmm &r2,
                                        const Operand &op, uint8 imm) {
  if (!op.is(Operand::MEM | Operand::YMM))
    throw Error(ERR_BAD_COMBINATION);
  opVex(r1, &r2, op, T_N32 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x3A,
        imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovdqa32(const Address &addr, const Xmm &x) {
  opAVX_X_XM_IMM(x, addr,
                 T_66 | T_0F | T_EW0 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z |
                     T_MUST_EVEX | T_M_K,
                 0x7F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovdqa32(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op,
                 T_66 | T_0F | T_EW0 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z |
                     T_MUST_EVEX,
                 0x6F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovdqa64(const Address &addr, const Xmm &x) {
  opAVX_X_XM_IMM(x, addr,
                 T_66 | T_0F | T_EW1 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z |
                     T_MUST_EVEX | T_M_K,
                 0x7F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovdqa64(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op,
                 T_66 | T_0F | T_EW1 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z |
                     T_MUST_EVEX,
                 0x6F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovdqu16(const Address &addr, const Xmm &x) {
  opAVX_X_XM_IMM(x, addr,
                 T_F2 | T_0F | T_EW1 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z |
                     T_MUST_EVEX | T_M_K,
                 0x7F);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovdqu16(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op,
                 T_F2 | T_0F | T_EW1 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z |
                     T_MUST_EVEX,
                 0x6F);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovdqu32(const Address &addr, const Xmm &x) {
  opAVX_X_XM_IMM(x, addr,
                 T_F3 | T_0F | T_EW0 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z |
                     T_MUST_EVEX | T_M_K,
                 0x7F);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovdqu32(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op,
                 T_F3 | T_0F | T_EW0 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z |
                     T_MUST_EVEX,
                 0x6F);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovdqu64(const Address &addr, const Xmm &x) {
  opAVX_X_XM_IMM(x, addr,
                 T_F3 | T_0F | T_EW1 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z |
                     T_MUST_EVEX | T_M_K,
                 0x7F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovdqu64(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op,
                 T_F3 | T_0F | T_EW1 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z |
                     T_MUST_EVEX,
                 0x6F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vmovdqu8(const Address &addr, const Xmm &x) {
  opAVX_X_XM_IMM(x, addr,
                 T_F2 | T_0F | T_EW0 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z |
                     T_MUST_EVEX | T_M_K,
                 0x7F);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vmovdqu8(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op,
                 T_F2 | T_0F | T_EW0 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z |
                     T_MUST_EVEX,
                 0x6F);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vp2intersectd(const Opmask &k, const Xmm &x,
                                         const Operand &op) {
  if (k.getOpmaskIdx() != 0)
    throw Error(ERR_OPMASK_IS_ALREADY_SET);
  opAVX_K_X_XM(k, x, op, T_F2 | T_0F38 | T_YMM | T_EVEX | T_EW0 | T_B32, 0x68);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vp2intersectq(const Opmask &k, const Xmm &x,
                                         const Operand &op) {
  if (k.getOpmaskIdx() != 0)
    throw Error(ERR_OPMASK_IS_ALREADY_SET);
  opAVX_K_X_XM(k, x, op, T_F2 | T_0F38 | T_YMM | T_EVEX | T_EW1 | T_B64, 0x68);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vp4dpwssd(const Zmm &z1, const Zmm &z2,
                                     const Address &addr) {
  opAVX_X_X_XM(z1, z2, addr,
               T_0F38 | T_F2 | T_EW0 | T_YMM | T_MUST_EVEX | T_N16, 0x52);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vp4dpwssds(const Zmm &z1, const Zmm &z2,
                                      const Address &addr) {
  opAVX_X_X_XM(z1, z2, addr,
               T_0F38 | T_F2 | T_EW0 | T_YMM | T_MUST_EVEX | T_N16, 0x53);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpabsq(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_MUST_EVEX | T_EW1 | T_B64 | T_YMM,
                 0x1F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpandd(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0xDB);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpandnd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0xDF);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpandnq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0xDF);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpandq(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0xDB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpblendmb(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x66);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpblendmd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0x64);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpblendmq(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x64);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpblendmw(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x66);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpbroadcastb(const Xmm &x, const Reg8 &r) {
  opVex(x, 0, r, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x7A);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpbroadcastd(const Xmm &x, const Reg32 &r) {
  opVex(x, 0, r, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x7C);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpbroadcastmb2q(const Xmm &x, const Opmask &k) {
  opVex(x, 0, k, T_F3 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW1, 0x2A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpbroadcastmw2d(const Xmm &x, const Opmask &k) {
  opVex(x, 0, k, T_F3 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW0, 0x3A);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpbroadcastw(const Xmm &x, const Reg16 &r) {
  opVex(x, 0, r, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x7B);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpcmpb(const Opmask &k, const Xmm &x,
                                  const Operand &op, uint8 imm) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x3F,
               imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpcmpd(const Opmask &k, const Xmm &x,
                                  const Operand &op, uint8 imm) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0x1F, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpcmpeqb(const Opmask &k, const Xmm &x,
                                    const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F | T_YMM | T_MUST_EVEX, 0x74);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpcmpeqd(const Opmask &k, const Xmm &x,
                                    const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F | T_YMM | T_MUST_EVEX | T_B32, 0x76);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpcmpeqq(const Opmask &k, const Xmm &x,
                                    const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x29);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpeqw(const Opmask &k, const Xmm &x,
                                    const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F | T_YMM | T_MUST_EVEX, 0x75);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpgtb(const Opmask &k, const Xmm &x,
                                    const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F | T_YMM | T_MUST_EVEX, 0x64);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpgtd(const Opmask &k, const Xmm &x,
                                    const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0x66);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpgtq(const Opmask &k, const Xmm &x,
                                    const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x37);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpgtw(const Opmask &k, const Xmm &x,
                                    const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F | T_YMM | T_MUST_EVEX, 0x65);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpq(const Opmask &k, const Xmm &x,
                                  const Operand &op, uint8 imm) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x1F, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpub(const Opmask &k, const Xmm &x,
                                   const Operand &op, uint8 imm) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x3E,
               imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpcmpud(const Opmask &k, const Xmm &x,
                                   const Operand &op, uint8 imm) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0x1E, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpuq(const Opmask &k, const Xmm &x,
                                   const Operand &op, uint8 imm) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x1E, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpuw(const Opmask &k, const Xmm &x,
                                   const Operand &op, uint8 imm) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x3E,
               imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcmpw(const Opmask &k, const Xmm &x,
                                  const Operand &op, uint8 imm) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x3F,
               imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcompressd(const Operand &op, const Xmm &x) {
  opAVX_X_XM_IMM(x, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
                 0x8B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpcompressq(const Operand &op, const Xmm &x) {
  opAVX_X_XM_IMM(x, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX,
                 0x8B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpconflictd(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
                 0xC4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpconflictq(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
                 0xC4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpdpbusd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
               0x50);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpdpbusds(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
               0x51);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpdpwssd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
               0x52);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpdpwssds(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
               0x53);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermb(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x8D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermi2b(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x75);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermi2d(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0x76);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermi2pd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x77);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermi2ps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0x77);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpermi2q(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x76);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermi2w(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x75);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermt2b(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x7D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermt2d(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0x7E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermt2pd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x7F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermt2ps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0x7F);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpermt2q(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x7E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermt2w(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x7D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpermw(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x8D);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpexpandb(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op,
                 T_N1 | T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX,
                 0x62);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpexpandd(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
                 0x89);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpexpandq(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX,
                 0x89);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpexpandw(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op,
                 T_N2 | T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX,
                 0x62);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpgatherdd(const Xmm &x, const Address &addr) {
  opGather2(x, addr,
            T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_VSIB, 0x90,
            0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpgatherdq(const Xmm &x, const Address &addr) {
  opGather2(x, addr,
            T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_VSIB, 0x90,
            1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpgatherqd(const Xmm &x, const Address &addr) {
  opGather2(x, addr,
            T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_VSIB, 0x91,
            2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpgatherqq(const Xmm &x, const Address &addr) {
  opGather2(x, addr,
            T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_VSIB, 0x91,
            0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vplzcntd(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
                 0x44);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vplzcntq(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
                 0x44);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmadd52huq(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0xB5);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmadd52luq(const Xmm &x1, const Xmm &x2,
                                       const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0xB4);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmaxsq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x3D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmaxuq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x3F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpminsq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x39);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpminuq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x3B);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovb2m(const Opmask &k, const Xmm &x) {
  opVex(k, 0, x, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW0, 0x29);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovd2m(const Opmask &k, const Xmm &x) {
  opVex(k, 0, x, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW0, 0x39);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovdb(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N4 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x31, false);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmovdw(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x33, true);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmovm2b(const Xmm &x, const Opmask &k) {
  opVex(x, 0, k, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW0, 0x28);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovm2d(const Xmm &x, const Opmask &k) {
  opVex(x, 0, k, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW0, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovm2q(const Xmm &x, const Opmask &k) {
  opVex(x, 0, k, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW1, 0x38);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovm2w(const Xmm &x, const Opmask &k) {
  opVex(x, 0, k, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW1, 0x28);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovq2m(const Opmask &k, const Xmm &x) {
  opVex(k, 0, x, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW1, 0x39);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovqb(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N2 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x32, false);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovqd(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x35, true);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovqw(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N4 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x34, false);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovsdb(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N4 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x21, false);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmovsdw(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x23, true);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovsqb(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N2 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x22, false);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovsqd(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x25, true);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovsqw(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N4 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x24, false);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovswb(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x20, true);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovusdb(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N4 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x11, false);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpmovusdw(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x13, true);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovusqb(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N2 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x12, false);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovusqd(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x15, true);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovusqw(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N4 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x14, false);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovuswb(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x10, true);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovw2m(const Opmask &k, const Xmm &x) {
  opVex(k, 0, x, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW1, 0x29);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmovwb(const Operand &op, const Xmm &x) {
  opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
         0x30, true);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmullq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x40);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpmultishiftqb(const Xmm &x1, const Xmm &x2,
                                          const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x83);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpopcntb(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX,
                 0x54);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpopcntd(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op,
                 T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
                 0x55);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpopcntq(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op,
                 T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64,
                 0x55);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpopcntw(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX,
                 0x54);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpord(const Xmm &x1, const Xmm &x2,
                                 const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0xEB);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vporq(const Xmm &x1, const Xmm &x2,
                                 const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0xEB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vprold(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 1), x, op,
               T_66 | T_0F | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x72, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vprolq(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 1), x, op,
               T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x72, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vprolvd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0x15);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vprolvq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x15);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vprord(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 0), x, op,
               T_66 | T_0F | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x72, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vprorq(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 0), x, op,
               T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x72, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vprorvd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0x14);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vprorvq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x14);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpscatterdd(const Address &addr, const Xmm &x) {
  opGather2(x, addr,
            T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB,
            0xA0, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpscatterdq(const Address &addr, const Xmm &x) {
  opGather2(x, addr,
            T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB,
            0xA0, 1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpscatterqd(const Address &addr, const Xmm &x) {
  opGather2(x, addr,
            T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB,
            0xA1, 2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpscatterqq(const Address &addr, const Xmm &x) {
  opGather2(x, addr,
            T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB,
            0xA1, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshldd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F3A | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
               0x71, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshldq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64,
               0x71, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshldvd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
               0x71);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshldvq(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64,
               0x71);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshldvw(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX, 0x70);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshldw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX, 0x70,
               imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshrdd(const Xmm &x1, const Xmm &x2,
                                   const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F3A | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
               0x73, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshrdq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64,
               0x73, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshrdvd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
               0x73);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshrdvq(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64,
               0x73);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshrdvw(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX, 0x72);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshrdw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX, 0x72,
               imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpshufbitqmb(const Opmask &k, const Xmm &x,
                                        const Operand &op) {
  opVex(k, &x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x8F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsllvw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x12);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsraq(const Xmm &x, const Operand &op, uint8 imm) {
  opAVX_X_X_XM(Xmm(x.getKind(), 4), x, op,
               T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x72, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsraq(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX,
               0xE2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsravq(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x46);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsravw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x11);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpsrlvw(const Xmm &x1, const Xmm &x2,
                                   const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x10);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpternlogd(const Xmm &x1, const Xmm &x2,
                                      const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0x25, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpternlogq(const Xmm &x1, const Xmm &x2,
                                      const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x25, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vptestmb(const Opmask &k, const Xmm &x,
                                    const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x26);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vptestmd(const Opmask &k, const Xmm &x,
                                    const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0x27);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vptestmq(const Opmask &k, const Xmm &x,
                                    const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x27);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vptestmw(const Opmask &k, const Xmm &x,
                                    const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x26);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vptestnmb(const Opmask &k, const Xmm &x,
                                     const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x26);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vptestnmd(const Opmask &k, const Xmm &x,
                                     const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0x27);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vptestnmq(const Opmask &k, const Xmm &x,
                                     const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_F3 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0x27);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vptestnmw(const Opmask &k, const Xmm &x,
                                     const Operand &op) {
  opAVX_K_X_XM(k, x, op, T_F3 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x26);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vpxord(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
               0xEF);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpxorq(const Xmm &x1, const Xmm &x2,
                                  const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
               0xEF);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vrangepd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64,
               0x50, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrangeps(const Xmm &x1, const Xmm &x2,
                                    const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F3A | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
               0x50, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrangesd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F3A | T_EW1 | T_SAE_X | T_MUST_EVEX,
               0x51, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrangess(const Xmm &x1, const Xmm &x2,
                                    const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F3A | T_EW0 | T_SAE_X | T_MUST_EVEX,
               0x51, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrcp14pd(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
                 0x4C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrcp14ps(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
                 0x4C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrcp14sd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX, 0x4D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrcp14ss(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX, 0x4D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrcp28pd(const Zmm &z, const Operand &op) {
  opAVX_X_XM_IMM(z, op,
                 T_66 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW1 | T_B64 | T_SAE_Z,
                 0xCA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrcp28ps(const Zmm &z, const Operand &op) {
  opAVX_X_XM_IMM(z, op,
                 T_66 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW0 | T_B32 | T_SAE_Z,
                 0xCA);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrcp28sd(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_SAE_X | T_MUST_EVEX,
               0xCB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrcp28ss(const Xmm &x1, const Xmm &x2,
                                    const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_SAE_X | T_MUST_EVEX,
               0xCB);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vreducepd(const Xmm &x, const Operand &op,
                                     uint8 imm) {
  opAVX_X_XM_IMM(x, op,
                 T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64,
                 0x56, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vreduceps(const Xmm &x, const Operand &op,
                                     uint8 imm) {
  opAVX_X_XM_IMM(x, op,
                 T_66 | T_0F3A | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32,
                 0x56, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vreducesd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F3A | T_EW1 | T_SAE_X | T_MUST_EVEX,
               0x57, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vreducess(const Xmm &x1, const Xmm &x2,
                                     const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F3A | T_EW0 | T_SAE_X | T_MUST_EVEX,
               0x57, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrndscalepd(const Xmm &x, const Operand &op,
                                       uint8 imm) {
  opAVX_X_XM_IMM(x, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
                 0x09, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrndscaleps(const Xmm &x, const Operand &op,
                                       uint8 imm) {
  opAVX_X_XM_IMM(x, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
                 0x08, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vrndscalesd(const Xmm &x1, const Xmm &x2,
                                       const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F3A | T_EW1 | T_MUST_EVEX, 0x0B,
               imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrndscaless(const Xmm &x1, const Xmm &x2,
                                       const Operand &op, uint8 imm) {
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F3A | T_EW0 | T_MUST_EVEX, 0x0A,
               imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrsqrt14pd(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64,
                 0x4E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrsqrt14ps(const Xmm &x, const Operand &op) {
  opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32,
                 0x4E);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrsqrt14sd(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX,
               0x4F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrsqrt14ss(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX,
               0x4F);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrsqrt28pd(const Zmm &z, const Operand &op) {
  opAVX_X_XM_IMM(z, op,
                 T_66 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW1 | T_B64 | T_SAE_Z,
                 0xCC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrsqrt28ps(const Zmm &z, const Operand &op) {
  opAVX_X_XM_IMM(z, op,
                 T_66 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW0 | T_B32 | T_SAE_Z,
                 0xCC);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrsqrt28sd(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_SAE_X | T_MUST_EVEX,
               0xCD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vrsqrt28ss(const Xmm &x1, const Xmm &x2,
                                      const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_SAE_X | T_MUST_EVEX,
               0xCD);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscalefpd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_EW1 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B64,
               0x2C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscalefps(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op,
               T_66 | T_0F38 | T_EW0 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B32,
               0x2C);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscalefsd(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_ER_X | T_MUST_EVEX,
               0x2D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscalefss(const Xmm &x1, const Xmm &x2,
                                     const Operand &op) {
  opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_ER_X | T_MUST_EVEX,
               0x2D);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscatterdpd(const Address &addr, const Xmm &x) {
  opGather2(x, addr,
            T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB,
            0xA2, 1);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscatterdps(const Address &addr, const Xmm &x) {
  opGather2(x, addr,
            T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB,
            0xA2, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscatterpf0dpd(const Address &addr) {
  opGatherFetch(addr, zm5,
                T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC6, Operand::YMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscatterpf0dps(const Address &addr) {
  opGatherFetch(addr, zm5,
                T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC6, Operand::ZMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscatterpf0qpd(const Address &addr) {
  opGatherFetch(addr, zm5,
                T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC7, Operand::ZMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscatterpf0qps(const Address &addr) {
  opGatherFetch(addr, zm5,
                T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC7, Operand::ZMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscatterpf1dpd(const Address &addr) {
  opGatherFetch(addr, zm6,
                T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC6, Operand::YMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscatterpf1dps(const Address &addr) {
  opGatherFetch(addr, zm6,
                T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC6, Operand::ZMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscatterpf1qpd(const Address &addr) {
  opGatherFetch(addr, zm6,
                T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC7, Operand::ZMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscatterpf1qps(const Address &addr) {
  opGatherFetch(addr, zm6,
                T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB,
                0xC7, Operand::ZMM);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscatterqpd(const Address &addr, const Xmm &x) {
  opGather2(x, addr,
            T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB,
            0xA3, 0);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vscatterqps(const Address &addr, const Xmm &x) {
  opGather2(x, addr,
            T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB,
            0xA3, 2);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::vshuff32x4(const Ymm &y1, const Ymm &y2,
                                      const Operand &op, uint8 imm) {
  opAVX_X_X_XM(y1, y2, op, T_66 | T_0F3A | T_YMM | T_MUST_EVEX | T_EW0 | T_B32,
               0x23, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vshuff64x2(const Ymm &y1, const Ymm &y2,
                                      const Operand &op, uint8 imm) {
  opAVX_X_X_XM(y1, y2, op, T_66 | T_0F3A | T_YMM | T_MUST_EVEX | T_EW1 | T_B64,
               0x23, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vshufi32x4(const Ymm &y1, const Ymm &y2,
                                      const Operand &op, uint8 imm) {
  opAVX_X_X_XM(y1, y2, op, T_66 | T_0F3A | T_YMM | T_MUST_EVEX | T_EW0 | T_B32,
               0x43, imm);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vshufi64x2(const Ymm &y1, const Ymm &y2,
                                      const Operand &op, uint8 imm) {
  opAVX_X_X_XM(y1, y2, op, T_66 | T_0F3A | T_YMM | T_MUST_EVEX | T_EW1 | T_B64,
               0x43, imm);
  UNIMPLEMENTED;
}
void Xbyak::CodeGenerator::kmovq(const Opmask &k, const Reg64 &r) {
  opVex(k, 0, r, T_L0 | T_0F | T_F2 | T_W1, 0x92);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::kmovq(const Reg64 &r, const Opmask &k) {
  opVex(r, 0, k, T_L0 | T_0F | T_F2 | T_W1, 0x93);
  decodeAndTransToAArch64();
}
void Xbyak::CodeGenerator::vpbroadcastq(const Xmm &x, const Reg64 &r) {
  opVex(x, 0, r, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x7C);
  decodeAndTransToAArch64();
}
