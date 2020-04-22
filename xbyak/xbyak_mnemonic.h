/*******************************************************************************
* Copyright 2016-2019 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*******************************************************************************
* Copyright (c) 2007 MITSUNARI Shigeo
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this
* list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
* Neither the name of the copyright owner nor the names of its contributors may
* be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

const char *getVersionString() const { return "5.85"; }
void adc(const Operand& op, uint32 imm) { opRM_I(op, imm, 0x10, 2); decodeAndTransToAArch64(); }
void adc(const Operand& op1, const Operand& op2) { opRM_RM(op1, op2, 0x10); decodeAndTransToAArch64(); }
void adcx(const Reg32e& reg, const Operand& op) { opGen(reg, op, 0xF6, 0x66, isREG32_REG32orMEM, NONE, 0x38); UNIMPLEMENTED; }
void add(const Operand& op, uint32 imm) { opRM_I(op, imm, 0x00, 0); decodeAndTransToAArch64(); }
void add(const Operand& op1, const Operand& op2) { opRM_RM(op1, op2, 0x00); decodeAndTransToAArch64(); }
void addpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x58, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void addps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x58, 0x100, isXMM_XMMorMEM); decodeAndTransToAArch64(); }
void addsd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x58, 0xF2, isXMM_XMMorMEM); UNIMPLEMENTED; }
void addss(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x58, 0xF3, isXMM_XMMorMEM); decodeAndTransToAArch64(); }
void addsubpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xD0, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void addsubps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xD0, 0xF2, isXMM_XMMorMEM); UNIMPLEMENTED; }
void adox(const Reg32e& reg, const Operand& op) { opGen(reg, op, 0xF6, 0xF3, isREG32_REG32orMEM, NONE, 0x38); UNIMPLEMENTED; }
void aesdec(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xDE, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void aesdeclast(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xDF, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void aesenc(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xDC, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void aesenclast(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xDD, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void aesimc(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xDB, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void aeskeygenassist(const Xmm& xmm, const Operand& op, uint8 imm) { opGen(xmm, op, 0xDF, 0x66, isXMM_XMMorMEM, imm, 0x3A); UNIMPLEMENTED; }
void and_(const Operand& op, uint32 imm) { opRM_I(op, imm, 0x20, 4); decodeAndTransToAArch64(); }
void and_(const Operand& op1, const Operand& op2) { opRM_RM(op1, op2, 0x20); decodeAndTransToAArch64(); }
void andn(const Reg32e& r1, const Reg32e& r2, const Operand& op) { opGpr(r1, r2, op, T_0F38, 0xf2, true); UNIMPLEMENTED; }
void andnpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x55, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void andnps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x55, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void andpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x54, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void andps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x54, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void bextr(const Reg32e& r1, const Operand& op, const Reg32e& r2) { opGpr(r1, op, r2, T_0F38, 0xf7, false); UNIMPLEMENTED; }
void blendpd(const Xmm& xmm, const Operand& op, int imm) { opGen(xmm, op, 0x0D, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A); UNIMPLEMENTED; }
void blendps(const Xmm& xmm, const Operand& op, int imm) { opGen(xmm, op, 0x0C, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A); UNIMPLEMENTED; }
void blendvpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x15, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void blendvps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x14, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void blsi(const Reg32e& r, const Operand& op) { opGpr(Reg32e(3, r.getBit()), op, r, T_0F38, 0xf3, false); UNIMPLEMENTED; }
void blsmsk(const Reg32e& r, const Operand& op) { opGpr(Reg32e(2, r.getBit()), op, r, T_0F38, 0xf3, false); UNIMPLEMENTED; }
void blsr(const Reg32e& r, const Operand& op) { opGpr(Reg32e(1, r.getBit()), op, r, T_0F38, 0xf3, false); UNIMPLEMENTED; }
void bnd() { db(0xF2); UNIMPLEMENTED; }
void bndcl(const BoundsReg& bnd, const Operand& op) { db(0xF3); opR_ModM(op, i32e, bnd.getIdx(), 0x0F, 0x1A, NONE, !op.isMEM()); UNIMPLEMENTED; }
void bndcn(const BoundsReg& bnd, const Operand& op) { db(0xF2); opR_ModM(op, i32e, bnd.getIdx(), 0x0F, 0x1B, NONE, !op.isMEM()); UNIMPLEMENTED; }
void bndcu(const BoundsReg& bnd, const Operand& op) { db(0xF2); opR_ModM(op, i32e, bnd.getIdx(), 0x0F, 0x1A, NONE, !op.isMEM()); UNIMPLEMENTED; }
void bndldx(const BoundsReg& bnd, const Address& addr) { opMIB(addr, bnd, 0x0F, 0x1A); UNIMPLEMENTED; }
void bndmk(const BoundsReg& bnd, const Address& addr) { db(0xF3); opModM(addr, bnd, 0x0F, 0x1B); UNIMPLEMENTED; }
void bndmov(const Address& addr, const BoundsReg& bnd) { db(0x66); opModM(addr, bnd, 0x0F, 0x1B); UNIMPLEMENTED; }
void bndmov(const BoundsReg& bnd, const Operand& op) { db(0x66); opModRM(bnd, op, op.isBNDREG(), op.isMEM(), 0x0F, 0x1A); UNIMPLEMENTED; }
void bndstx(const Address& addr, const BoundsReg& bnd) { opMIB(addr, bnd, 0x0F, 0x1B); UNIMPLEMENTED; }
void bsf(const Reg&reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0xBC); UNIMPLEMENTED; }
void bsr(const Reg&reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0xBD); UNIMPLEMENTED; }
void bswap(const Reg32e& reg) { opModR(Reg32(1), reg, 0x0F); UNIMPLEMENTED; }
void bt(const Operand& op, const Reg& reg) { opModRM(reg, op, op.isREG(16|32|64) && op.getBit() == reg.getBit(), op.isMEM(), 0x0f, 0xA3); UNIMPLEMENTED; }
void bt(const Operand& op, uint8 imm) { opR_ModM(op, 16|32|64, 4, 0x0f, 0xba, NONE, false, 1); db(imm); UNIMPLEMENTED; }
void btc(const Operand& op, const Reg& reg) { opModRM(reg, op, op.isREG(16|32|64) && op.getBit() == reg.getBit(), op.isMEM(), 0x0f, 0xBB); UNIMPLEMENTED; }
void btc(const Operand& op, uint8 imm) { opR_ModM(op, 16|32|64, 7, 0x0f, 0xba, NONE, false, 1); db(imm); UNIMPLEMENTED; }
void btr(const Operand& op, const Reg& reg) { opModRM(reg, op, op.isREG(16|32|64) && op.getBit() == reg.getBit(), op.isMEM(), 0x0f, 0xB3); UNIMPLEMENTED; }
void btr(const Operand& op, uint8 imm) { opR_ModM(op, 16|32|64, 6, 0x0f, 0xba, NONE, false, 1); db(imm); UNIMPLEMENTED; }
void bts(const Operand& op, const Reg& reg) { opModRM(reg, op, op.isREG(16|32|64) && op.getBit() == reg.getBit(), op.isMEM(), 0x0f, 0xAB); UNIMPLEMENTED; }
void bts(const Operand& op, uint8 imm) { opR_ModM(op, 16|32|64, 5, 0x0f, 0xba, NONE, false, 1); db(imm); UNIMPLEMENTED; }
void bzhi(const Reg32e& r1, const Operand& op, const Reg32e& r2) { opGpr(r1, op, r2, T_0F38, 0xf5, false); UNIMPLEMENTED; }
void cbw() { db(0x66); db(0x98); UNIMPLEMENTED; }
void cdq() { db(0x99); UNIMPLEMENTED; }
void clc() { db(0xF8); UNIMPLEMENTED; }
void cld() { db(0xFC); UNIMPLEMENTED; }
void clflush(const Address& addr) { opModM(addr, Reg32(7), 0x0F, 0xAE); UNIMPLEMENTED; }
void clflushopt(const Address& addr) { db(0x66); opModM(addr, Reg32(7), 0x0F, 0xAE); UNIMPLEMENTED; }
void cli() { db(0xFA); UNIMPLEMENTED; }
void clzero() { db(0x0F); db(0x01); db(0xFC); UNIMPLEMENTED; }
void cmc() { db(0xF5); UNIMPLEMENTED; }
void cmova(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 7); UNIMPLEMENTED; }//-V524
void cmovae(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 3); UNIMPLEMENTED; }//-V524
void cmovb(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 2); UNIMPLEMENTED; }//-V524
void cmovbe(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 6); UNIMPLEMENTED; }//-V524
void cmovc(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 2); UNIMPLEMENTED; }//-V524
void cmove(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 4); UNIMPLEMENTED; }//-V524
void cmovg(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 15); decodeAndTransToAArch64(); }//-V524
void cmovge(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 13); UNIMPLEMENTED; }//-V524
void cmovl(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 12); UNIMPLEMENTED; }//-V524
void cmovle(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 14); UNIMPLEMENTED; }//-V524
void cmovna(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 6); UNIMPLEMENTED; }//-V524
void cmovnae(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 2); UNIMPLEMENTED; }//-V524
void cmovnb(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 3); UNIMPLEMENTED; }//-V524
void cmovnbe(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 7); UNIMPLEMENTED; }//-V524
void cmovnc(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 3); UNIMPLEMENTED; }//-V524
void cmovne(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 5); UNIMPLEMENTED; }//-V524
void cmovng(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 14); UNIMPLEMENTED; }//-V524
void cmovnge(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 12); UNIMPLEMENTED; }//-V524
void cmovnl(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 13); UNIMPLEMENTED; }//-V524
void cmovnle(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 15); UNIMPLEMENTED; }//-V524
void cmovno(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 1); UNIMPLEMENTED; }//-V524
void cmovnp(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 11); UNIMPLEMENTED; }//-V524
void cmovns(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 9); UNIMPLEMENTED; }//-V524
void cmovnz(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 5); UNIMPLEMENTED; }//-V524
void cmovo(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 0); UNIMPLEMENTED; }//-V524
void cmovp(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 10); UNIMPLEMENTED; }//-V524
void cmovpe(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 10); UNIMPLEMENTED; }//-V524
void cmovpo(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 11); UNIMPLEMENTED; }//-V524
void cmovs(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 8); UNIMPLEMENTED; }//-V524
void cmovz(const Reg& reg, const Operand& op) { opModRM(reg, op, op.isREG(16 | i32e), op.isMEM(), 0x0F, 0x40 | 4); UNIMPLEMENTED; }//-V524
void cmp(const Operand& op, uint32 imm) { opRM_I(op, imm, 0x38, 7); decodeAndTransToAArch64(); }
void cmp(const Operand& op1, const Operand& op2) { opRM_RM(op1, op2, 0x38); decodeAndTransToAArch64(); }
void cmpeqpd(const Xmm& x, const Operand& op) { cmppd(x, op, 0); UNIMPLEMENTED; }
void cmpeqps(const Xmm& x, const Operand& op) { cmpps(x, op, 0); UNIMPLEMENTED; }
void cmpeqsd(const Xmm& x, const Operand& op) { cmpsd(x, op, 0); UNIMPLEMENTED; }
void cmpeqss(const Xmm& x, const Operand& op) { cmpss(x, op, 0); UNIMPLEMENTED; }
void cmplepd(const Xmm& x, const Operand& op) { cmppd(x, op, 2); UNIMPLEMENTED; }
void cmpleps(const Xmm& x, const Operand& op) { cmpps(x, op, 2); UNIMPLEMENTED; }
void cmplesd(const Xmm& x, const Operand& op) { cmpsd(x, op, 2); UNIMPLEMENTED; }
void cmpless(const Xmm& x, const Operand& op) { cmpss(x, op, 2); UNIMPLEMENTED; }
void cmpltpd(const Xmm& x, const Operand& op) { cmppd(x, op, 1); UNIMPLEMENTED; }
void cmpltps(const Xmm& x, const Operand& op) { cmpps(x, op, 1); UNIMPLEMENTED; }
void cmpltsd(const Xmm& x, const Operand& op) { cmpsd(x, op, 1); UNIMPLEMENTED; }
void cmpltss(const Xmm& x, const Operand& op) { cmpss(x, op, 1); UNIMPLEMENTED; }
void cmpneqpd(const Xmm& x, const Operand& op) { cmppd(x, op, 4); UNIMPLEMENTED; }
void cmpneqps(const Xmm& x, const Operand& op) { cmpps(x, op, 4); UNIMPLEMENTED; }
void cmpneqsd(const Xmm& x, const Operand& op) { cmpsd(x, op, 4); UNIMPLEMENTED; }
void cmpneqss(const Xmm& x, const Operand& op) { cmpss(x, op, 4); UNIMPLEMENTED; }
void cmpnlepd(const Xmm& x, const Operand& op) { cmppd(x, op, 6); UNIMPLEMENTED; }
void cmpnleps(const Xmm& x, const Operand& op) { cmpps(x, op, 6); UNIMPLEMENTED; }
void cmpnlesd(const Xmm& x, const Operand& op) { cmpsd(x, op, 6); UNIMPLEMENTED; }
void cmpnless(const Xmm& x, const Operand& op) { cmpss(x, op, 6); UNIMPLEMENTED; }
void cmpnltpd(const Xmm& x, const Operand& op) { cmppd(x, op, 5); UNIMPLEMENTED; }
void cmpnltps(const Xmm& x, const Operand& op) { cmpps(x, op, 5); UNIMPLEMENTED; }
void cmpnltsd(const Xmm& x, const Operand& op) { cmpsd(x, op, 5); UNIMPLEMENTED; }
void cmpnltss(const Xmm& x, const Operand& op) { cmpss(x, op, 5); UNIMPLEMENTED; }
void cmpordpd(const Xmm& x, const Operand& op) { cmppd(x, op, 7); UNIMPLEMENTED; }
void cmpordps(const Xmm& x, const Operand& op) { cmpps(x, op, 7); UNIMPLEMENTED; }
void cmpordsd(const Xmm& x, const Operand& op) { cmpsd(x, op, 7); UNIMPLEMENTED; }
void cmpordss(const Xmm& x, const Operand& op) { cmpss(x, op, 7); UNIMPLEMENTED; }
void cmppd(const Xmm& xmm, const Operand& op, uint8 imm8) { opGen(xmm, op, 0xC2, 0x66, isXMM_XMMorMEM, imm8); UNIMPLEMENTED; }
void cmpps(const Xmm& xmm, const Operand& op, uint8 imm8) { opGen(xmm, op, 0xC2, 0x100, isXMM_XMMorMEM, imm8); UNIMPLEMENTED; }
void cmpsb() { db(0xA6); UNIMPLEMENTED; }
void cmpsd() { db(0xA7); UNIMPLEMENTED; }
void cmpsd(const Xmm& xmm, const Operand& op, uint8 imm8) { opGen(xmm, op, 0xC2, 0xF2, isXMM_XMMorMEM, imm8); UNIMPLEMENTED; }
void cmpss(const Xmm& xmm, const Operand& op, uint8 imm8) { opGen(xmm, op, 0xC2, 0xF3, isXMM_XMMorMEM, imm8); UNIMPLEMENTED; }
void cmpsw() { db(0x66); db(0xA7); UNIMPLEMENTED; }
void cmpunordpd(const Xmm& x, const Operand& op) { cmppd(x, op, 3); UNIMPLEMENTED; }
void cmpunordps(const Xmm& x, const Operand& op) { cmpps(x, op, 3); UNIMPLEMENTED; }
void cmpunordsd(const Xmm& x, const Operand& op) { cmpsd(x, op, 3); UNIMPLEMENTED; }
void cmpunordss(const Xmm& x, const Operand& op) { cmpss(x, op, 3); UNIMPLEMENTED; }
void cmpxchg(const Operand& op, const Reg& reg) { opModRM(reg, op, (op.isREG() && reg.isREG() && op.getBit() == reg.getBit()), op.isMEM(), 0x0F, 0xB0 | (reg.isBit(8) ? 0 : 1)); UNIMPLEMENTED; }
void cmpxchg8b(const Address& addr) { opModM(addr, Reg32(1), 0x0F, 0xC7); UNIMPLEMENTED; }
void comisd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x2F, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void comiss(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x2F, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void cpuid() { db(0x0F); db(0xA2); UNIMPLEMENTED; }
void crc32(const Reg32e& reg, const Operand& op) { if (reg.isBit(32) && op.isBit(16)) db(0x66); db(0xF2); opModRM(reg, op, op.isREG(), op.isMEM(), 0x0F, 0x38, 0xF0 | (op.isBit(8) ? 0 : 1)); UNIMPLEMENTED; }
void cvtdq2pd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xE6, 0xF3, isXMM_XMMorMEM); UNIMPLEMENTED; }
void cvtdq2ps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5B, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void cvtpd2dq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xE6, 0xF2, isXMM_XMMorMEM); UNIMPLEMENTED; }
void cvtpd2pi(const Operand& reg, const Operand& op) { opGen(reg, op, 0x2D, 0x66, isMMX_XMMorMEM); UNIMPLEMENTED; }
void cvtpd2ps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5A, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void cvtpi2pd(const Operand& reg, const Operand& op) { opGen(reg, op, 0x2A, 0x66, isXMM_MMXorMEM); UNIMPLEMENTED; }
void cvtpi2ps(const Operand& reg, const Operand& op) { opGen(reg, op, 0x2A, 0x100, isXMM_MMXorMEM); UNIMPLEMENTED; }
void cvtps2dq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5B, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void cvtps2pd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5A, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void cvtps2pi(const Operand& reg, const Operand& op) { opGen(reg, op, 0x2D, 0x100, isMMX_XMMorMEM); UNIMPLEMENTED; }
void cvtsd2si(const Operand& reg, const Operand& op) { opGen(reg, op, 0x2D, 0xF2, isREG32_XMMorMEM); UNIMPLEMENTED; }
void cvtsd2ss(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5A, 0xF2, isXMM_XMMorMEM); UNIMPLEMENTED; }
void cvtsi2sd(const Operand& reg, const Operand& op) { opGen(reg, op, 0x2A, 0xF2, isXMM_REG32orMEM); UNIMPLEMENTED; }
void cvtsi2ss(const Operand& reg, const Operand& op) { opGen(reg, op, 0x2A, 0xF3, isXMM_REG32orMEM); UNIMPLEMENTED; }
void cvtss2sd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5A, 0xF3, isXMM_XMMorMEM); UNIMPLEMENTED; }
void cvtss2si(const Operand& reg, const Operand& op) { opGen(reg, op, 0x2D, 0xF3, isREG32_XMMorMEM); UNIMPLEMENTED; }
void cvttpd2dq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xE6, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void cvttpd2pi(const Operand& reg, const Operand& op) { opGen(reg, op, 0x2C, 0x66, isMMX_XMMorMEM); UNIMPLEMENTED; }
void cvttps2dq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5B, 0xF3, isXMM_XMMorMEM); UNIMPLEMENTED; }
void cvttps2pi(const Operand& reg, const Operand& op) { opGen(reg, op, 0x2C, 0x100, isMMX_XMMorMEM); UNIMPLEMENTED; }
void cvttsd2si(const Operand& reg, const Operand& op) { opGen(reg, op, 0x2C, 0xF2, isREG32_XMMorMEM); UNIMPLEMENTED; }
void cvttss2si(const Operand& reg, const Operand& op) { opGen(reg, op, 0x2C, 0xF3, isREG32_XMMorMEM); UNIMPLEMENTED; }
void cwd() { db(0x66); db(0x99); UNIMPLEMENTED; }
void cwde() { db(0x98); UNIMPLEMENTED; }
void dec(const Operand& op) { opIncDec(op, 0x48, 1); decodeAndTransToAArch64(); }
void div(const Operand& op) { opR_ModM(op, 0, 6, 0xF6); UNIMPLEMENTED; }
void divpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5E, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void divps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5E, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void divsd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5E, 0xF2, isXMM_XMMorMEM); UNIMPLEMENTED; }
void divss(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5E, 0xF3, isXMM_XMMorMEM); UNIMPLEMENTED; }
void dppd(const Xmm& xmm, const Operand& op, int imm) { opGen(xmm, op, 0x41, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A); UNIMPLEMENTED; }
void dpps(const Xmm& xmm, const Operand& op, int imm) { opGen(xmm, op, 0x40, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A); UNIMPLEMENTED; }
void emms() { db(0x0F); db(0x77); UNIMPLEMENTED; }
void enter(uint16 x, uint8 y) { CodeArray::db(0xC8); CodeArray::dw(x); db(y); UNIMPLEMENTED; }
void extractps(const Operand& op, const Xmm& xmm, uint8 imm) { opExt(op, xmm, 0x17, imm); UNIMPLEMENTED; }
void f2xm1() { db(0xD9); db(0xF0); UNIMPLEMENTED; }
void fabs() { db(0xD9); db(0xE1); UNIMPLEMENTED; }
void fadd(const Address& addr) { opFpuMem(addr, 0x00, 0xD8, 0xDC, 0, 0); UNIMPLEMENTED; }
void fadd(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xD8C0, 0xDCC0); UNIMPLEMENTED; }
void fadd(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xD8C0, 0xDCC0); UNIMPLEMENTED; }
void faddp() { db(0xDE); db(0xC1); UNIMPLEMENTED; }
void faddp(const Fpu& reg1) { opFpuFpu(reg1, st0, 0x0000, 0xDEC0); UNIMPLEMENTED; }
void faddp(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0x0000, 0xDEC0); UNIMPLEMENTED; }
void fbld(const Address& addr) { opModM(addr, Reg32(4), 0xDF, 0x100); UNIMPLEMENTED; }
void fbstp(const Address& addr) { opModM(addr, Reg32(6), 0xDF, 0x100); UNIMPLEMENTED; }
void fchs() { db(0xD9); db(0xE0); UNIMPLEMENTED; }
void fclex() { db(0x9B); db(0xDB); db(0xE2); UNIMPLEMENTED; }
void fcmovb(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xDAC0, 0x00C0); UNIMPLEMENTED; }
void fcmovb(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xDAC0, 0x00C0); UNIMPLEMENTED; }
void fcmovbe(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xDAD0, 0x00D0); UNIMPLEMENTED; }
void fcmovbe(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xDAD0, 0x00D0); UNIMPLEMENTED; }
void fcmove(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xDAC8, 0x00C8); UNIMPLEMENTED; }
void fcmove(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xDAC8, 0x00C8); UNIMPLEMENTED; }
void fcmovnb(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xDBC0, 0x00C0); UNIMPLEMENTED; }
void fcmovnb(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xDBC0, 0x00C0); UNIMPLEMENTED; }
void fcmovnbe(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xDBD0, 0x00D0); UNIMPLEMENTED; }
void fcmovnbe(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xDBD0, 0x00D0); UNIMPLEMENTED; }
void fcmovne(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xDBC8, 0x00C8); UNIMPLEMENTED; }
void fcmovne(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xDBC8, 0x00C8); UNIMPLEMENTED; }
void fcmovnu(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xDBD8, 0x00D8); UNIMPLEMENTED; }
void fcmovnu(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xDBD8, 0x00D8); UNIMPLEMENTED; }
void fcmovu(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xDAD8, 0x00D8); UNIMPLEMENTED; }
void fcmovu(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xDAD8, 0x00D8); UNIMPLEMENTED; }
void fcom() { db(0xD8); db(0xD1); UNIMPLEMENTED; }
void fcom(const Address& addr) { opFpuMem(addr, 0x00, 0xD8, 0xDC, 2, 0); UNIMPLEMENTED; }
void fcom(const Fpu& reg) { opFpu(reg, 0xD8, 0xD0); UNIMPLEMENTED; }
void fcomi(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xDBF0, 0x00F0); UNIMPLEMENTED; }
void fcomi(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xDBF0, 0x00F0); UNIMPLEMENTED; }
void fcomip(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xDFF0, 0x00F0); UNIMPLEMENTED; }
void fcomip(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xDFF0, 0x00F0); UNIMPLEMENTED; }
void fcomp() { db(0xD8); db(0xD9); UNIMPLEMENTED; }
void fcomp(const Address& addr) { opFpuMem(addr, 0x00, 0xD8, 0xDC, 3, 0); UNIMPLEMENTED; }
void fcomp(const Fpu& reg) { opFpu(reg, 0xD8, 0xD8); UNIMPLEMENTED; }
void fcompp() { db(0xDE); db(0xD9); UNIMPLEMENTED; }
void fcos() { db(0xD9); db(0xFF); UNIMPLEMENTED; }
void fdecstp() { db(0xD9); db(0xF6); UNIMPLEMENTED; }
void fdiv(const Address& addr) { opFpuMem(addr, 0x00, 0xD8, 0xDC, 6, 0); UNIMPLEMENTED; }
void fdiv(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xD8F0, 0xDCF8); UNIMPLEMENTED; }
void fdiv(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xD8F0, 0xDCF8); UNIMPLEMENTED; }
void fdivp() { db(0xDE); db(0xF9); UNIMPLEMENTED; }
void fdivp(const Fpu& reg1) { opFpuFpu(reg1, st0, 0x0000, 0xDEF8); UNIMPLEMENTED; }
void fdivp(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0x0000, 0xDEF8); UNIMPLEMENTED; }
void fdivr(const Address& addr) { opFpuMem(addr, 0x00, 0xD8, 0xDC, 7, 0); UNIMPLEMENTED; }
void fdivr(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xD8F8, 0xDCF0); UNIMPLEMENTED; }
void fdivr(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xD8F8, 0xDCF0); UNIMPLEMENTED; }
void fdivrp() { db(0xDE); db(0xF1); UNIMPLEMENTED; }
void fdivrp(const Fpu& reg1) { opFpuFpu(reg1, st0, 0x0000, 0xDEF0); UNIMPLEMENTED; }
void fdivrp(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0x0000, 0xDEF0); UNIMPLEMENTED; }
void ffree(const Fpu& reg) { opFpu(reg, 0xDD, 0xC0); UNIMPLEMENTED; }
void fiadd(const Address& addr) { opFpuMem(addr, 0xDE, 0xDA, 0x00, 0, 0); UNIMPLEMENTED; }
void ficom(const Address& addr) { opFpuMem(addr, 0xDE, 0xDA, 0x00, 2, 0); UNIMPLEMENTED; }
void ficomp(const Address& addr) { opFpuMem(addr, 0xDE, 0xDA, 0x00, 3, 0); UNIMPLEMENTED; }
void fidiv(const Address& addr) { opFpuMem(addr, 0xDE, 0xDA, 0x00, 6, 0); UNIMPLEMENTED; }
void fidivr(const Address& addr) { opFpuMem(addr, 0xDE, 0xDA, 0x00, 7, 0); UNIMPLEMENTED; }
void fild(const Address& addr) { opFpuMem(addr, 0xDF, 0xDB, 0xDF, 0, 5); UNIMPLEMENTED; }
void fimul(const Address& addr) { opFpuMem(addr, 0xDE, 0xDA, 0x00, 1, 0); UNIMPLEMENTED; }
void fincstp() { db(0xD9); db(0xF7); UNIMPLEMENTED; }
void finit() { db(0x9B); db(0xDB); db(0xE3); UNIMPLEMENTED; }
void fist(const Address& addr) { opFpuMem(addr, 0xDF, 0xDB, 0x00, 2, 0); UNIMPLEMENTED; }
void fistp(const Address& addr) { opFpuMem(addr, 0xDF, 0xDB, 0xDF, 3, 7); UNIMPLEMENTED; }
void fisttp(const Address& addr) { opFpuMem(addr, 0xDF, 0xDB, 0xDD, 1, 0); UNIMPLEMENTED; }
void fisub(const Address& addr) { opFpuMem(addr, 0xDE, 0xDA, 0x00, 4, 0); UNIMPLEMENTED; }
void fisubr(const Address& addr) { opFpuMem(addr, 0xDE, 0xDA, 0x00, 5, 0); UNIMPLEMENTED; }
void fld(const Address& addr) { opFpuMem(addr, 0x00, 0xD9, 0xDD, 0, 0); UNIMPLEMENTED; }
void fld(const Fpu& reg) { opFpu(reg, 0xD9, 0xC0); UNIMPLEMENTED; }
void fld1() { db(0xD9); db(0xE8); UNIMPLEMENTED; }
void fldcw(const Address& addr) { opModM(addr, Reg32(5), 0xD9, 0x100); UNIMPLEMENTED; }
void fldenv(const Address& addr) { opModM(addr, Reg32(4), 0xD9, 0x100); UNIMPLEMENTED; }
void fldl2e() { db(0xD9); db(0xEA); UNIMPLEMENTED; }
void fldl2t() { db(0xD9); db(0xE9); UNIMPLEMENTED; }
void fldlg2() { db(0xD9); db(0xEC); UNIMPLEMENTED; }
void fldln2() { db(0xD9); db(0xED); UNIMPLEMENTED; }
void fldpi() { db(0xD9); db(0xEB); UNIMPLEMENTED; }
void fldz() { db(0xD9); db(0xEE); UNIMPLEMENTED; }
void fmul(const Address& addr) { opFpuMem(addr, 0x00, 0xD8, 0xDC, 1, 0); UNIMPLEMENTED; }
void fmul(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xD8C8, 0xDCC8); UNIMPLEMENTED; }
void fmul(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xD8C8, 0xDCC8); UNIMPLEMENTED; }
void fmulp() { db(0xDE); db(0xC9); UNIMPLEMENTED; }
void fmulp(const Fpu& reg1) { opFpuFpu(reg1, st0, 0x0000, 0xDEC8); UNIMPLEMENTED; }
void fmulp(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0x0000, 0xDEC8); UNIMPLEMENTED; }
void fnclex() { db(0xDB); db(0xE2); UNIMPLEMENTED; }
void fninit() { db(0xDB); db(0xE3); UNIMPLEMENTED; }
void fnop() { db(0xD9); db(0xD0); UNIMPLEMENTED; }
void fnsave(const Address& addr) { opModM(addr, Reg32(6), 0xDD, 0x100); UNIMPLEMENTED; }
void fnstcw(const Address& addr) { opModM(addr, Reg32(7), 0xD9, 0x100); UNIMPLEMENTED; }
void fnstenv(const Address& addr) { opModM(addr, Reg32(6), 0xD9, 0x100); UNIMPLEMENTED; }
void fnstsw(const Address& addr) { opModM(addr, Reg32(7), 0xDD, 0x100); UNIMPLEMENTED; }
void fnstsw(const Reg16& r) { if (r.getIdx() != Operand::AX) throw Error(ERR_BAD_PARAMETER); db(0xDF); db(0xE0); UNIMPLEMENTED; }
void fpatan() { db(0xD9); db(0xF3); UNIMPLEMENTED; }
void fprem() { db(0xD9); db(0xF8); UNIMPLEMENTED; }
void fprem1() { db(0xD9); db(0xF5); UNIMPLEMENTED; }
void fptan() { db(0xD9); db(0xF2); UNIMPLEMENTED; }
void frndint() { db(0xD9); db(0xFC); UNIMPLEMENTED; }
void frstor(const Address& addr) { opModM(addr, Reg32(4), 0xDD, 0x100); UNIMPLEMENTED; }
void fsave(const Address& addr) { db(0x9B); opModM(addr, Reg32(6), 0xDD, 0x100); UNIMPLEMENTED; }
void fscale() { db(0xD9); db(0xFD); UNIMPLEMENTED; }
void fsin() { db(0xD9); db(0xFE); UNIMPLEMENTED; }
void fsincos() { db(0xD9); db(0xFB); UNIMPLEMENTED; }
void fsqrt() { db(0xD9); db(0xFA); UNIMPLEMENTED; }
void fst(const Address& addr) { opFpuMem(addr, 0x00, 0xD9, 0xDD, 2, 0); UNIMPLEMENTED; }
void fst(const Fpu& reg) { opFpu(reg, 0xDD, 0xD0); UNIMPLEMENTED; }
void fstcw(const Address& addr) { db(0x9B); opModM(addr, Reg32(7), 0xD9, 0x100); UNIMPLEMENTED; }
void fstenv(const Address& addr) { db(0x9B); opModM(addr, Reg32(6), 0xD9, 0x100); UNIMPLEMENTED; }
void fstp(const Address& addr) { opFpuMem(addr, 0x00, 0xD9, 0xDD, 3, 0); UNIMPLEMENTED; }
void fstp(const Fpu& reg) { opFpu(reg, 0xDD, 0xD8); UNIMPLEMENTED; }
void fstsw(const Address& addr) { db(0x9B); opModM(addr, Reg32(7), 0xDD, 0x100); UNIMPLEMENTED; }
void fstsw(const Reg16& r) { if (r.getIdx() != Operand::AX) throw Error(ERR_BAD_PARAMETER); db(0x9B); db(0xDF); db(0xE0); UNIMPLEMENTED; }
void fsub(const Address& addr) { opFpuMem(addr, 0x00, 0xD8, 0xDC, 4, 0); UNIMPLEMENTED; }
void fsub(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xD8E0, 0xDCE8); UNIMPLEMENTED; }
void fsub(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xD8E0, 0xDCE8); UNIMPLEMENTED; }
void fsubp() { db(0xDE); db(0xE9); UNIMPLEMENTED; }
void fsubp(const Fpu& reg1) { opFpuFpu(reg1, st0, 0x0000, 0xDEE8); UNIMPLEMENTED; }
void fsubp(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0x0000, 0xDEE8); UNIMPLEMENTED; }
void fsubr(const Address& addr) { opFpuMem(addr, 0x00, 0xD8, 0xDC, 5, 0); UNIMPLEMENTED; }
void fsubr(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xD8E8, 0xDCE0); UNIMPLEMENTED; }
void fsubr(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xD8E8, 0xDCE0); UNIMPLEMENTED; }
void fsubrp() { db(0xDE); db(0xE1); UNIMPLEMENTED; }
void fsubrp(const Fpu& reg1) { opFpuFpu(reg1, st0, 0x0000, 0xDEE0); UNIMPLEMENTED; }
void fsubrp(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0x0000, 0xDEE0); UNIMPLEMENTED; }
void ftst() { db(0xD9); db(0xE4); UNIMPLEMENTED; }
void fucom() { db(0xDD); db(0xE1); UNIMPLEMENTED; }
void fucom(const Fpu& reg) { opFpu(reg, 0xDD, 0xE0); UNIMPLEMENTED; }
void fucomi(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xDBE8, 0x00E8); UNIMPLEMENTED; }
void fucomi(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xDBE8, 0x00E8); UNIMPLEMENTED; }
void fucomip(const Fpu& reg1) { opFpuFpu(st0, reg1, 0xDFE8, 0x00E8); UNIMPLEMENTED; }
void fucomip(const Fpu& reg1, const Fpu& reg2) { opFpuFpu(reg1, reg2, 0xDFE8, 0x00E8); UNIMPLEMENTED; }
void fucomp() { db(0xDD); db(0xE9); UNIMPLEMENTED; }
void fucomp(const Fpu& reg) { opFpu(reg, 0xDD, 0xE8); UNIMPLEMENTED; }
void fucompp() { db(0xDA); db(0xE9); UNIMPLEMENTED; }
void fwait() { db(0x9B); UNIMPLEMENTED; }
void fxam() { db(0xD9); db(0xE5); UNIMPLEMENTED; }
void fxch() { db(0xD9); db(0xC9); UNIMPLEMENTED; }
void fxch(const Fpu& reg) { opFpu(reg, 0xD9, 0xC8); UNIMPLEMENTED; }
void fxrstor(const Address& addr) { opModM(addr, Reg32(1), 0x0F, 0xAE); UNIMPLEMENTED; }
void fxtract() { db(0xD9); db(0xF4); UNIMPLEMENTED; }
void fyl2x() { db(0xD9); db(0xF1); UNIMPLEMENTED; }
void fyl2xp1() { db(0xD9); db(0xF9); UNIMPLEMENTED; }
void gf2p8affineinvqb(const Xmm& xmm, const Operand& op, int imm) { opGen(xmm, op, 0xCF, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A); UNIMPLEMENTED; }
void gf2p8affineqb(const Xmm& xmm, const Operand& op, int imm) { opGen(xmm, op, 0xCE, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A); UNIMPLEMENTED; }
void gf2p8mulb(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xCF, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void haddpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x7C, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void haddps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x7C, 0xF2, isXMM_XMMorMEM); UNIMPLEMENTED; }
void hsubpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x7D, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void hsubps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x7D, 0xF2, isXMM_XMMorMEM); UNIMPLEMENTED; }
void idiv(const Operand& op) { opR_ModM(op, 0, 7, 0xF6); UNIMPLEMENTED; }
void imul(const Operand& op) { opR_ModM(op, 0, 5, 0xF6); decodeAndTransToAArch64(); }
void in_(const Reg& a, const Reg& d) { opInOut(a, d, 0xEC); UNIMPLEMENTED; }
void in_(const Reg& a, uint8 v) { opInOut(a, 0xE4, v); UNIMPLEMENTED; }
void inc(const Operand& op) { opIncDec(op, 0x40, 0); decodeAndTransToAArch64(); }
void insertps(const Xmm& xmm, const Operand& op, uint8 imm) { opGen(xmm, op, 0x21, 0x66, isXMM_XMMorMEM, imm, 0x3A); UNIMPLEMENTED; }
void int3() { db(0xCC); UNIMPLEMENTED; }
void int_(uint8 x) { db(0xCD); db(x); UNIMPLEMENTED; }
#ifdef XBYAK_TRANSLATE_AARCH64
void ja(const Label& label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void ja(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void ja(const void *addr) { UNIMPLEMENTED; }
void ja(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jae(const Label& label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jae(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jae(const void *addr) { UNIMPLEMENTED; }
void jae(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jb(const Label& label, LabelType type = T_AUTO) { decodeAndTransToAArch64(X86_64_B, label); }
void jb(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jb(const void *addr) { UNIMPLEMENTED; }
void jb(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jbe(const Label& label, LabelType type = T_AUTO) { decodeAndTransToAArch64(X86_64_BE, label); }
void jbe(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jbe(const void *addr) { UNIMPLEMENTED; }
void jbe(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jc(const Label& label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jc(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jc(const void *addr) { UNIMPLEMENTED; }
void jc(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void je(const Label& label, LabelType type = T_AUTO) { b(Xbyak_aarch64::EQ, label); } 
void je(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void je(const void *addr) { UNIMPLEMENTED; }
void je(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jg(const Label& label, LabelType type = T_AUTO) { b(Xbyak_aarch64::GT, label); }
void jg(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jg(const void *addr) { UNIMPLEMENTED; }
void jg(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jge(const Label& label, LabelType type = T_AUTO) { b(Xbyak_aarch64::GE, label); }
void jge(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; } 
void jge(const void *addr) { UNIMPLEMENTED; }
void jge(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jl(const Label& label, LabelType type = T_AUTO) { b(Xbyak_aarch64::LT, label); }
void jl(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jl(const void *addr) { UNIMPLEMENTED; }
void jl(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jle(const Label& label, LabelType type = T_AUTO) { b(Xbyak_aarch64::LE, label); }
void jle(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jle(const void *addr) { UNIMPLEMENTED; }
void jle(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jna(const Label& label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jna(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jna(const void *addr) { UNIMPLEMENTED; }
void jna(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnae(const Label& label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnae(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnae(const void *addr) { UNIMPLEMENTED; }
void jnae(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnb(const Label& label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnb(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnb(const void *addr) { UNIMPLEMENTED; }
void jnb(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnbe(const Label& label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnbe(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnbe(const void *addr) { UNIMPLEMENTED; }
void jnbe(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnc(const Label& label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnc(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnc(const void *addr) { UNIMPLEMENTED; }
void jnc(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jne(const Label& label, LabelType type = T_AUTO) { b(Xbyak_aarch64::NE, label); }
void jne(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jne(const void *addr) { UNIMPLEMENTED; }
void jne(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jng(const Label& label, LabelType type = T_AUTO) { b(Xbyak_aarch64::LE, label); UNIMPLEMENTED; }
void jng(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jng(const void *addr) { UNIMPLEMENTED; }
void jng(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnge(const Label& label, LabelType type = T_AUTO) { b(Xbyak_aarch64::LT, label); UNIMPLEMENTED; }
void jnge(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnge(const void *addr) { UNIMPLEMENTED; }
void jnge(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnl(const Label& label, LabelType type = T_AUTO) { b(Xbyak_aarch64::GE, label); UNIMPLEMENTED; }
void jnl(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnl(const void *addr) { UNIMPLEMENTED; }
void jnl(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnle(const Label& label, LabelType type = T_AUTO) { b(Xbyak_aarch64::GT, label); UNIMPLEMENTED; }
void jnle(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnle(const void *addr) { UNIMPLEMENTED; }
void jnle(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jno(const Label& label, LabelType type = T_AUTO) { b(Xbyak_aarch64::VC, label); UNIMPLEMENTED; } 
void jno(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jno(const void *addr) { UNIMPLEMENTED; }
void jno(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnp(const Label& label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnp(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnp(const void *addr) { UNIMPLEMENTED; }
void jnp(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jns(const Label& label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jns(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jns(const void *addr) { UNIMPLEMENTED; }
void jns(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnz(const Label& label, LabelType type = T_AUTO) { b(Xbyak_aarch64::NE, label); }
void jnz(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jnz(const void *addr) { UNIMPLEMENTED; }
void jnz(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jo(const Label& label, LabelType type = T_AUTO) { b(Xbyak_aarch64::VS, label); UNIMPLEMENTED; }
void jo(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jo(const void *addr) { UNIMPLEMENTED; }
void jo(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
/* Does AArch64 has parity flag? */
void jp(const Label& label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jp(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jp(const void *addr) { UNIMPLEMENTED; }
void jp(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jpe(const Label& label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jpe(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jpe(const void *addr) { UNIMPLEMENTED; }
void jpe(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jpo(const Label& label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jpo(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jpo(const void *addr) { UNIMPLEMENTED; }
void jpo(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void js(const Label& label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void js(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void js(const void *addr) { UNIMPLEMENTED; }
void js(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
/* AArch64 CPU has no zero flag jmp instruction. */
void jz(const Label& label, LabelType type = T_AUTO) { b(Xbyak_aarch64::EQ, label); }
void jz(const char *label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
void jz(const void *addr) { UNIMPLEMENTED; }
void jz(std::string label, LabelType type = T_AUTO) { UNIMPLEMENTED; }
#else //#ifdef XBYAK_TRANSLATE_AARCH64
void ja(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x77, 0x87, 0x0F); UNIMPLEMENTED; }//-V524
void ja(const char *label, LabelType type = T_AUTO) { ja(std::string(label), type); UNIMPLEMENTED; }//-V524
void ja(const void *addr) { opJmpAbs(addr, T_NEAR, 0x77, 0x87, 0x0F); UNIMPLEMENTED; }//-V524
void ja(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x77, 0x87, 0x0F); UNIMPLEMENTED; }//-V524
void jae(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x73, 0x83, 0x0F); UNIMPLEMENTED; }//-V524
void jae(const char *label, LabelType type = T_AUTO) { jae(std::string(label), type); UNIMPLEMENTED; }//-V524
void jae(const void *addr) { opJmpAbs(addr, T_NEAR, 0x73, 0x83, 0x0F); UNIMPLEMENTED; }//-V524
void jae(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x73, 0x83, 0x0F); UNIMPLEMENTED; }//-V524
void jb(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x72, 0x82, 0x0F); UNIMPLEMENTED; }//-V524
void jb(const char *label, LabelType type = T_AUTO) { jb(std::string(label), type); UNIMPLEMENTED; }//-V524
void jb(const void *addr) { opJmpAbs(addr, T_NEAR, 0x72, 0x82, 0x0F); UNIMPLEMENTED; }//-V524
void jb(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x72, 0x82, 0x0F); UNIMPLEMENTED; }//-V524
void jbe(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x76, 0x86, 0x0F); UNIMPLEMENTED; }//-V524
void jbe(const char *label, LabelType type = T_AUTO) { jbe(std::string(label), type); UNIMPLEMENTED; }//-V524
void jbe(const void *addr) { opJmpAbs(addr, T_NEAR, 0x76, 0x86, 0x0F); UNIMPLEMENTED; }//-V524
void jbe(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x76, 0x86, 0x0F); UNIMPLEMENTED; }//-V524
void jc(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x72, 0x82, 0x0F); UNIMPLEMENTED; }//-V524
void jc(const char *label, LabelType type = T_AUTO) { jc(std::string(label), type); UNIMPLEMENTED; }//-V524
void jc(const void *addr) { opJmpAbs(addr, T_NEAR, 0x72, 0x82, 0x0F); UNIMPLEMENTED; }//-V524
void jc(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x72, 0x82, 0x0F); UNIMPLEMENTED; }//-V524
void je(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x74, 0x84, 0x0F); UNIMPLEMENTED; }//-V524
void je(const char *label, LabelType type = T_AUTO) { je(std::string(label), type); UNIMPLEMENTED; }//-V524
void je(const void *addr) { opJmpAbs(addr, T_NEAR, 0x74, 0x84, 0x0F); UNIMPLEMENTED; }//-V524
void je(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x74, 0x84, 0x0F); UNIMPLEMENTED; }//-V524
void jg(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x7F, 0x8F, 0x0F); UNIMPLEMENTED; }//-V524
void jg(const char *label, LabelType type = T_AUTO) { jg(std::string(label), type); UNIMPLEMENTED; }//-V524
void jg(const void *addr) { opJmpAbs(addr, T_NEAR, 0x7F, 0x8F, 0x0F); UNIMPLEMENTED; }//-V524
void jg(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x7F, 0x8F, 0x0F); UNIMPLEMENTED; }//-V524
void jge(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x7D, 0x8D, 0x0F); UNIMPLEMENTED; }//-V524
void jge(const char *label, LabelType type = T_AUTO) { jge(std::string(label), type); UNIMPLEMENTED; }//-V524
void jge(const void *addr) { opJmpAbs(addr, T_NEAR, 0x7D, 0x8D, 0x0F); UNIMPLEMENTED; }//-V524
void jge(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x7D, 0x8D, 0x0F); UNIMPLEMENTED; }//-V524
void jl(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x7C, 0x8C, 0x0F); UNIMPLEMENTED; }//-V524
void jl(const char *label, LabelType type = T_AUTO) { jl(std::string(label), type); UNIMPLEMENTED; }//-V524
void jl(const void *addr) { opJmpAbs(addr, T_NEAR, 0x7C, 0x8C, 0x0F); UNIMPLEMENTED; }//-V524
void jl(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x7C, 0x8C, 0x0F); UNIMPLEMENTED; }//-V524
void jle(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x7E, 0x8E, 0x0F); UNIMPLEMENTED; }//-V524
void jle(const char *label, LabelType type = T_AUTO) { jle(std::string(label), type); UNIMPLEMENTED; }//-V524
void jle(const void *addr) { opJmpAbs(addr, T_NEAR, 0x7E, 0x8E, 0x0F); UNIMPLEMENTED; }//-V524
void jle(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x7E, 0x8E, 0x0F); UNIMPLEMENTED; }//-V524
void jna(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x76, 0x86, 0x0F); UNIMPLEMENTED; }//-V524
void jna(const char *label, LabelType type = T_AUTO) { jna(std::string(label), type); UNIMPLEMENTED; }//-V524
void jna(const void *addr) { opJmpAbs(addr, T_NEAR, 0x76, 0x86, 0x0F); UNIMPLEMENTED; }//-V524
void jna(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x76, 0x86, 0x0F); UNIMPLEMENTED; }//-V524
void jnae(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x72, 0x82, 0x0F); UNIMPLEMENTED; }//-V524
void jnae(const char *label, LabelType type = T_AUTO) { jnae(std::string(label), type); UNIMPLEMENTED; }//-V524
void jnae(const void *addr) { opJmpAbs(addr, T_NEAR, 0x72, 0x82, 0x0F); UNIMPLEMENTED; }//-V524
void jnae(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x72, 0x82, 0x0F); UNIMPLEMENTED; }//-V524
void jnb(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x73, 0x83, 0x0F); UNIMPLEMENTED; }//-V524
void jnb(const char *label, LabelType type = T_AUTO) { jnb(std::string(label), type); UNIMPLEMENTED; }//-V524
void jnb(const void *addr) { opJmpAbs(addr, T_NEAR, 0x73, 0x83, 0x0F); UNIMPLEMENTED; }//-V524
void jnb(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x73, 0x83, 0x0F); UNIMPLEMENTED; }//-V524
void jnbe(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x77, 0x87, 0x0F); UNIMPLEMENTED; }//-V524
void jnbe(const char *label, LabelType type = T_AUTO) { jnbe(std::string(label), type); UNIMPLEMENTED; }//-V524
void jnbe(const void *addr) { opJmpAbs(addr, T_NEAR, 0x77, 0x87, 0x0F); UNIMPLEMENTED; }//-V524
void jnbe(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x77, 0x87, 0x0F); UNIMPLEMENTED; }//-V524
void jnc(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x73, 0x83, 0x0F); UNIMPLEMENTED; }//-V524
void jnc(const char *label, LabelType type = T_AUTO) { jnc(std::string(label), type); UNIMPLEMENTED; }//-V524
void jnc(const void *addr) { opJmpAbs(addr, T_NEAR, 0x73, 0x83, 0x0F); UNIMPLEMENTED; }//-V524
void jnc(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x73, 0x83, 0x0F); UNIMPLEMENTED; }//-V524
void jne(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x75, 0x85, 0x0F); UNIMPLEMENTED; }//-V524
void jne(const char *label, LabelType type = T_AUTO) { jne(std::string(label), type); UNIMPLEMENTED; }//-V524
void jne(const void *addr) { opJmpAbs(addr, T_NEAR, 0x75, 0x85, 0x0F); UNIMPLEMENTED; }//-V524
void jne(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x75, 0x85, 0x0F); UNIMPLEMENTED; }//-V524
void jng(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x7E, 0x8E, 0x0F); UNIMPLEMENTED; }//-V524
void jng(const char *label, LabelType type = T_AUTO) { jng(std::string(label), type); UNIMPLEMENTED; }//-V524
void jng(const void *addr) { opJmpAbs(addr, T_NEAR, 0x7E, 0x8E, 0x0F); UNIMPLEMENTED; }//-V524
void jng(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x7E, 0x8E, 0x0F); UNIMPLEMENTED; }//-V524
void jnge(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x7C, 0x8C, 0x0F); UNIMPLEMENTED; }//-V524
void jnge(const char *label, LabelType type = T_AUTO) { jnge(std::string(label), type); UNIMPLEMENTED; }//-V524
void jnge(const void *addr) { opJmpAbs(addr, T_NEAR, 0x7C, 0x8C, 0x0F); UNIMPLEMENTED; }//-V524
void jnge(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x7C, 0x8C, 0x0F); UNIMPLEMENTED; }//-V524
void jnl(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x7D, 0x8D, 0x0F); UNIMPLEMENTED; }//-V524
void jnl(const char *label, LabelType type = T_AUTO) { jnl(std::string(label), type); UNIMPLEMENTED; }//-V524
void jnl(const void *addr) { opJmpAbs(addr, T_NEAR, 0x7D, 0x8D, 0x0F); UNIMPLEMENTED; }//-V524
void jnl(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x7D, 0x8D, 0x0F); UNIMPLEMENTED; }//-V524
void jnle(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x7F, 0x8F, 0x0F); UNIMPLEMENTED; }//-V524
void jnle(const char *label, LabelType type = T_AUTO) { jnle(std::string(label), type); UNIMPLEMENTED; }//-V524
void jnle(const void *addr) { opJmpAbs(addr, T_NEAR, 0x7F, 0x8F, 0x0F); UNIMPLEMENTED; }//-V524
void jnle(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x7F, 0x8F, 0x0F); UNIMPLEMENTED; }//-V524
void jno(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x71, 0x81, 0x0F); UNIMPLEMENTED; }//-V524
void jno(const char *label, LabelType type = T_AUTO) { jno(std::string(label), type); UNIMPLEMENTED; }//-V524
void jno(const void *addr) { opJmpAbs(addr, T_NEAR, 0x71, 0x81, 0x0F); UNIMPLEMENTED; }//-V524
void jno(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x71, 0x81, 0x0F); UNIMPLEMENTED; }//-V524
void jnp(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x7B, 0x8B, 0x0F); UNIMPLEMENTED; }//-V524
void jnp(const char *label, LabelType type = T_AUTO) { jnp(std::string(label), type); UNIMPLEMENTED; }//-V524
void jnp(const void *addr) { opJmpAbs(addr, T_NEAR, 0x7B, 0x8B, 0x0F); UNIMPLEMENTED; }//-V524
void jnp(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x7B, 0x8B, 0x0F); UNIMPLEMENTED; }//-V524
void jns(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x79, 0x89, 0x0F); UNIMPLEMENTED; }//-V524
void jns(const char *label, LabelType type = T_AUTO) { jns(std::string(label), type); UNIMPLEMENTED; }//-V524
void jns(const void *addr) { opJmpAbs(addr, T_NEAR, 0x79, 0x89, 0x0F); UNIMPLEMENTED; }//-V524
void jns(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x79, 0x89, 0x0F); UNIMPLEMENTED; }//-V524
void jnz(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x75, 0x85, 0x0F); UNIMPLEMENTED; }//-V524
void jnz(const char *label, LabelType type = T_AUTO) { jnz(std::string(label), type); UNIMPLEMENTED; }//-V524
void jnz(const void *addr) { opJmpAbs(addr, T_NEAR, 0x75, 0x85, 0x0F); UNIMPLEMENTED; }//-V524
void jnz(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x75, 0x85, 0x0F); UNIMPLEMENTED; }//-V524
void jo(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x70, 0x80, 0x0F); UNIMPLEMENTED; }//-V524
void jo(const char *label, LabelType type = T_AUTO) { jo(std::string(label), type); UNIMPLEMENTED; }//-V524
void jo(const void *addr) { opJmpAbs(addr, T_NEAR, 0x70, 0x80, 0x0F); UNIMPLEMENTED; }//-V524
void jo(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x70, 0x80, 0x0F); UNIMPLEMENTED; }//-V524
void jp(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x7A, 0x8A, 0x0F); UNIMPLEMENTED; }//-V524
void jp(const char *label, LabelType type = T_AUTO) { jp(std::string(label), type); UNIMPLEMENTED; }//-V524
void jp(const void *addr) { opJmpAbs(addr, T_NEAR, 0x7A, 0x8A, 0x0F); UNIMPLEMENTED; }//-V524
void jp(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x7A, 0x8A, 0x0F); UNIMPLEMENTED; }//-V524
void jpe(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x7A, 0x8A, 0x0F); UNIMPLEMENTED; }//-V524
void jpe(const char *label, LabelType type = T_AUTO) { jpe(std::string(label), type); UNIMPLEMENTED; }//-V524
void jpe(const void *addr) { opJmpAbs(addr, T_NEAR, 0x7A, 0x8A, 0x0F); UNIMPLEMENTED; }//-V524
void jpe(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x7A, 0x8A, 0x0F); UNIMPLEMENTED; }//-V524
void jpo(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x7B, 0x8B, 0x0F); UNIMPLEMENTED; }//-V524
void jpo(const char *label, LabelType type = T_AUTO) { jpo(std::string(label), type); UNIMPLEMENTED; }//-V524
void jpo(const void *addr) { opJmpAbs(addr, T_NEAR, 0x7B, 0x8B, 0x0F); UNIMPLEMENTED; }//-V524
void jpo(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x7B, 0x8B, 0x0F); UNIMPLEMENTED; }//-V524
void js(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x78, 0x88, 0x0F); UNIMPLEMENTED; }//-V524
void js(const char *label, LabelType type = T_AUTO) { js(std::string(label), type); UNIMPLEMENTED; }//-V524
void js(const void *addr) { opJmpAbs(addr, T_NEAR, 0x78, 0x88, 0x0F); UNIMPLEMENTED; }//-V524
void js(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x78, 0x88, 0x0F); UNIMPLEMENTED; }//-V524
void jz(const Label& label, LabelType type = T_AUTO) { opJmp(label, type, 0x74, 0x84, 0x0F); UNIMPLEMENTED; }//-V524
void jz(const char *label, LabelType type = T_AUTO) { jz(std::string(label), type); UNIMPLEMENTED; }//-V524
void jz(const void *addr) { opJmpAbs(addr, T_NEAR, 0x74, 0x84, 0x0F); UNIMPLEMENTED; }//-V524
void jz(std::string label, LabelType type = T_AUTO) { opJmp(label, type, 0x74, 0x84, 0x0F); UNIMPLEMENTED; }//-V524
#endif //#ifdef XBYAK_TRANSLATE_AARCH64
void lahf() { db(0x9F); std::cerr << "No support for LAHF instruction" << std::endl; }
void lddqu(const Xmm& xmm, const Address& addr) { db(0xF2); opModM(addr, xmm, 0x0F, 0xF0); UNIMPLEMENTED; }
void ldmxcsr(const Address& addr) { opModM(addr, Reg32(2), 0x0F, 0xAE); UNIMPLEMENTED; }
void lea(const Reg& reg, const Address& addr) { if (!reg.isBit(16 | i32e)) throw Error(ERR_BAD_SIZE_OF_REGISTER); opModM(addr, reg, 0x8D); decodeAndTransToAArch64(); }
void leave() { db(0xC9); UNIMPLEMENTED; }
void lfence() { db(0x0F); db(0xAE); db(0xE8); UNIMPLEMENTED; }
void lfs(const Reg& reg, const Address& addr) { opLoadSeg(addr, reg, 0x0F, 0xB4); UNIMPLEMENTED; }
void lgs(const Reg& reg, const Address& addr) { opLoadSeg(addr, reg, 0x0F, 0xB5); UNIMPLEMENTED; }
void lock() { db(0xF0); /* lock instruction is translated with the next instruction. */ }
void lodsb() { db(0xAC); UNIMPLEMENTED; }
void lodsd() { db(0xAD); UNIMPLEMENTED; }
void lodsw() { db(0x66); db(0xAD); UNIMPLEMENTED; }
#ifdef XBYAK_TRANSLATE_AARCH64
void loop(const Label& label) { UNIMPLEMENTED; }
void loop(const char *label) { UNIMPLEMENTED; }
void loop(std::string label) { UNIMPLEMENTED; }
void loope(const Label& label) { UNIMPLEMENTED; }
void loope(const char *label) { UNIMPLEMENTED; }
void loope(std::string label) { UNIMPLEMENTED; }
void loopne(const Label& label) { UNIMPLEMENTED; }
void loopne(const char *label) { UNIMPLEMENTED; }
void loopne(std::string label) { UNIMPLEMENTED; }
#else //#ifdef XBYAK_TRANSLATE_AARCH64
void loop(const Label& label) { opJmp(label, T_SHORT, 0xE2, 0, 0); UNIMPLEMENTED; }
void loop(const char *label) { loop(std::string(label)); UNIMPLEMENTED; }
void loop(std::string label) { opJmp(label, T_SHORT, 0xE2, 0, 0); UNIMPLEMENTED; }
void loope(const Label& label) { opJmp(label, T_SHORT, 0xE1, 0, 0); UNIMPLEMENTED; }
void loope(const char *label) { loope(std::string(label)); UNIMPLEMENTED; }
void loope(std::string label) { opJmp(label, T_SHORT, 0xE1, 0, 0); UNIMPLEMENTED; }
void loopne(const Label& label) { opJmp(label, T_SHORT, 0xE0, 0, 0); UNIMPLEMENTED; }
void loopne(const char *label) { loopne(std::string(label)); UNIMPLEMENTED; }
void loopne(std::string label) { opJmp(label, T_SHORT, 0xE0, 0, 0); UNIMPLEMENTED; }
#endif
void lss(const Reg& reg, const Address& addr) { opLoadSeg(addr, reg, 0x0F, 0xB2); UNIMPLEMENTED; }
void lzcnt(const Reg&reg, const Operand& op) { opSp1(reg, op, 0xF3, 0x0F, 0xBD); UNIMPLEMENTED; }
void maskmovdqu(const Xmm& reg1, const Xmm& reg2) { db(0x66);  opModR(reg1, reg2, 0x0F, 0xF7); UNIMPLEMENTED; }
void maskmovq(const Mmx& reg1, const Mmx& reg2) { if (!reg1.isMMX() || !reg2.isMMX()) throw Error(ERR_BAD_COMBINATION); opModR(reg1, reg2, 0x0F, 0xF7); UNIMPLEMENTED; }
void maxpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5F, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void maxps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5F, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void maxsd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5F, 0xF2, isXMM_XMMorMEM); UNIMPLEMENTED; }
void maxss(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5F, 0xF3, isXMM_XMMorMEM); UNIMPLEMENTED; }
void mfence() { db(0x0F); db(0xAE); db(0xF0); UNIMPLEMENTED; }
void minpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5D, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void minps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5D, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void minsd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5D, 0xF2, isXMM_XMMorMEM); UNIMPLEMENTED; }
void minss(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5D, 0xF3, isXMM_XMMorMEM); UNIMPLEMENTED; }
void monitor() { db(0x0F); db(0x01); db(0xC8); UNIMPLEMENTED; }
void monitorx() { db(0x0F); db(0x01); db(0xFA); UNIMPLEMENTED; }
void movapd(const Address& addr, const Xmm& xmm) { db(0x66); opModM(addr, xmm, 0x0F, 0x29); UNIMPLEMENTED; }
void movapd(const Xmm& xmm, const Operand& op) { opMMX(xmm, op, 0x28, 0x66); UNIMPLEMENTED; }
void movaps(const Address& addr, const Xmm& xmm) { opModM(addr, xmm, 0x0F, 0x29); UNIMPLEMENTED; }
void movaps(const Xmm& xmm, const Operand& op) { opMMX(xmm, op, 0x28, 0x100); UNIMPLEMENTED; }
void movbe(const Address& addr, const Reg& reg) { opModM(addr, reg, 0x0F, 0x38, 0xF1); UNIMPLEMENTED; }
void movbe(const Reg& reg, const Address& addr) { opModM(addr, reg, 0x0F, 0x38, 0xF0); UNIMPLEMENTED; }
void movd(const Address& addr, const Mmx& mmx) { if (mmx.isXMM()) db(0x66); opModM(addr, mmx, 0x0F, 0x7E); decodeAndTransToAArch64(); }
void movd(const Mmx& mmx, const Address& addr) { if (mmx.isXMM()) db(0x66); opModM(addr, mmx, 0x0F, 0x6E); decodeAndTransToAArch64(); }
void movd(const Mmx& mmx, const Reg32& reg) { if (mmx.isXMM()) db(0x66); opModR(mmx, reg, 0x0F, 0x6E); decodeAndTransToAArch64(); }
void movd(const Reg32& reg, const Mmx& mmx) { if (mmx.isXMM()) db(0x66); opModR(mmx, reg, 0x0F, 0x7E); decodeAndTransToAArch64(); }
void movddup(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x12, 0xF2, isXMM_XMMorMEM, NONE, NONE); UNIMPLEMENTED; }
void movdq2q(const Mmx& mmx, const Xmm& xmm) { db(0xF2); opModR(mmx, xmm, 0x0F, 0xD6); UNIMPLEMENTED; }
void movdqa(const Address& addr, const Xmm& xmm) { db(0x66); opModM(addr, xmm, 0x0F, 0x7F); decodeAndTransToAArch64(); }
void movdqa(const Xmm& xmm, const Operand& op) { opMMX(xmm, op, 0x6F, 0x66); decodeAndTransToAArch64(); }
void movdqu(const Address& addr, const Xmm& xmm) { db(0xF3); opModM(addr, xmm, 0x0F, 0x7F); decodeAndTransToAArch64(); }
void movdqu(const Xmm& xmm, const Operand& op) { opMMX(xmm, op, 0x6F, 0xF3); decodeAndTransToAArch64(); }
void movhlps(const Xmm& reg1, const Xmm& reg2) {  opModR(reg1, reg2, 0x0F, 0x12); decodeAndTransToAArch64(); }
void movhpd(const Operand& op1, const Operand& op2) { opMovXMM(op1, op2, 0x16, 0x66); UNIMPLEMENTED; }
void movhps(const Operand& op1, const Operand& op2) { opMovXMM(op1, op2, 0x16, 0x100); UNIMPLEMENTED; }
void movlhps(const Xmm& reg1, const Xmm& reg2) {  opModR(reg1, reg2, 0x0F, 0x16); UNIMPLEMENTED; }
void movlpd(const Operand& op1, const Operand& op2) { opMovXMM(op1, op2, 0x12, 0x66); UNIMPLEMENTED; }
void movlps(const Operand& op1, const Operand& op2) { opMovXMM(op1, op2, 0x12, 0x100); UNIMPLEMENTED; }
void movmskpd(const Reg32e& reg, const Xmm& xmm) { db(0x66); movmskps(reg, xmm); UNIMPLEMENTED; }
void movmskps(const Reg32e& reg, const Xmm& xmm) { opModR(reg, xmm, 0x0F, 0x50); UNIMPLEMENTED; }
void movntdq(const Address& addr, const Xmm& reg) { opModM(addr, Reg16(reg.getIdx()), 0x0F, 0xE7); UNIMPLEMENTED; }
void movntdqa(const Xmm& xmm, const Address& addr) { db(0x66); opModM(addr, xmm, 0x0F, 0x38, 0x2A); UNIMPLEMENTED; }
void movnti(const Address& addr, const Reg32e& reg) { opModM(addr, reg, 0x0F, 0xC3); UNIMPLEMENTED; }
void movntpd(const Address& addr, const Xmm& reg) { opModM(addr, Reg16(reg.getIdx()), 0x0F, 0x2B); UNIMPLEMENTED; }
void movntps(const Address& addr, const Xmm& xmm) { opModM(addr, Mmx(xmm.getIdx()), 0x0F, 0x2B); UNIMPLEMENTED; }
void movntq(const Address& addr, const Mmx& mmx) { if (!mmx.isMMX()) throw Error(ERR_BAD_COMBINATION); opModM(addr, mmx, 0x0F, 0xE7); UNIMPLEMENTED; }
void movq(const Address& addr, const Mmx& mmx) { if (mmx.isXMM()) db(0x66); opModM(addr, mmx, 0x0F, mmx.isXMM() ? 0xD6 : 0x7F); decodeAndTransToAArch64(); }
void movq(const Mmx& mmx, const Operand& op) { if (mmx.isXMM()) db(0xF3); opModRM(mmx, op, (mmx.getKind() == op.getKind()), op.isMEM(), 0x0F, mmx.isXMM() ? 0x7E : 0x6F); decodeAndTransToAArch64(); }
void movq2dq(const Xmm& xmm, const Mmx& mmx) { db(0xF3); opModR(xmm, mmx, 0x0F, 0xD6); UNIMPLEMENTED; }
void movsb() { db(0xA4); UNIMPLEMENTED; }
void movsd() { db(0xA5); decodeAndTransToAArch64(); }
void movsd(const Address& addr, const Xmm& xmm) { db(0xF2); opModM(addr, xmm, 0x0F, 0x11); decodeAndTransToAArch64(); }
void movsd(const Xmm& xmm, const Operand& op) { opMMX(xmm, op, 0x10, 0xF2); decodeAndTransToAArch64(); }
void movshdup(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x16, 0xF3, isXMM_XMMorMEM, NONE, NONE); UNIMPLEMENTED; }
void movsldup(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x12, 0xF3, isXMM_XMMorMEM, NONE, NONE); UNIMPLEMENTED; }
void movss(const Address& addr, const Xmm& xmm) { db(0xF3); opModM(addr, xmm, 0x0F, 0x11); decodeAndTransToAArch64(); }
void movss(const Xmm& xmm, const Operand& op) { opMMX(xmm, op, 0x10, 0xF3); decodeAndTransToAArch64(); }
void movsw() { db(0x66); db(0xA5); UNIMPLEMENTED; }
void movsx(const Reg& reg, const Operand& op) { opMovxx(reg, op, 0xBE); UNIMPLEMENTED; }
void movupd(const Address& addr, const Xmm& xmm) { db(0x66); opModM(addr, xmm, 0x0F, 0x11); UNIMPLEMENTED; }
void movupd(const Xmm& xmm, const Operand& op) { opMMX(xmm, op, 0x10, 0x66); UNIMPLEMENTED; }
void movups(const Address& addr, const Xmm& xmm) { opModM(addr, xmm, 0x0F, 0x11); decodeAndTransToAArch64(); }
void movups(const Xmm& xmm, const Operand& op) { opMMX(xmm, op, 0x10, 0x100); decodeAndTransToAArch64(); }
void movzx(const Reg& reg, const Operand& op) { opMovxx(reg, op, 0xB6); UNIMPLEMENTED; }
void mpsadbw(const Xmm& xmm, const Operand& op, int imm) { opGen(xmm, op, 0x42, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A); UNIMPLEMENTED; }
void mul(const Operand& op) { opR_ModM(op, 0, 4, 0xF6); UNIMPLEMENTED; }
void mulpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x59, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void mulps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x59, 0x100, isXMM_XMMorMEM); decodeAndTransToAArch64(); }
void mulsd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x59, 0xF2, isXMM_XMMorMEM); UNIMPLEMENTED; }
void mulss(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x59, 0xF3, isXMM_XMMorMEM); decodeAndTransToAArch64(); }
void mulx(const Reg32e& r1, const Reg32e& r2, const Operand& op) { opGpr(r1, r2, op, T_F2 | T_0F38, 0xf6, true); UNIMPLEMENTED; }
void mwait() { db(0x0F); db(0x01); db(0xC9); UNIMPLEMENTED; }
void mwaitx() { db(0x0F); db(0x01); db(0xFB); UNIMPLEMENTED; }
void neg(const Operand& op) { opR_ModM(op, 0, 3, 0xF6); UNIMPLEMENTED; }
void not_(const Operand& op) { opR_ModM(op, 0, 2, 0xF6); decodeAndTransToAArch64(); }
void or_(const Operand& op, uint32 imm) { opRM_I(op, imm, 0x08, 1); decodeAndTransToAArch64(); }
void or_(const Operand& op1, const Operand& op2) { opRM_RM(op1, op2, 0x08); decodeAndTransToAArch64(); }
void orpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x56, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void orps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x56, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void out_(const Reg& d, const Reg& a) { opInOut(a, d, 0xEE); UNIMPLEMENTED; }
void out_(uint8 v, const Reg& a) { opInOut(a, 0xE6, v); UNIMPLEMENTED; }
void outsb() { db(0x6E); UNIMPLEMENTED; }
void outsd() { db(0x6F); UNIMPLEMENTED; }
void outsw() { db(0x66); db(0x6F); UNIMPLEMENTED; }
void pabsb(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x1C, 0x66, NONE, 0x38); UNIMPLEMENTED; }
void pabsd(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x1E, 0x66, NONE, 0x38); UNIMPLEMENTED; }
void pabsw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x1D, 0x66, NONE, 0x38); UNIMPLEMENTED; }
void packssdw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x6B); UNIMPLEMENTED; }
void packsswb(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x63); UNIMPLEMENTED; }
void packusdw(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x2B, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void packuswb(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x67); UNIMPLEMENTED; }
void paddb(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xFC); UNIMPLEMENTED; }
void paddd(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xFE); decodeAndTransToAArch64(); }
void paddq(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xD4); UNIMPLEMENTED; }
void paddsb(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xEC); UNIMPLEMENTED; }
void paddsw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xED); UNIMPLEMENTED; }
void paddusb(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xDC); UNIMPLEMENTED; }
void paddusw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xDD); UNIMPLEMENTED; }
void paddw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xFD); UNIMPLEMENTED; }
void palignr(const Mmx& mmx, const Operand& op, int imm) { opMMX(mmx, op, 0x0f, 0x66, static_cast<uint8>(imm), 0x3a); UNIMPLEMENTED; }
void pand(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xDB); UNIMPLEMENTED; }
void pandn(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xDF); UNIMPLEMENTED; }
void pause() { db(0xF3); db(0x90);   decodeAndTransToAArch64(); }
void pavgb(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xE0); UNIMPLEMENTED; }
void pavgw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xE3); UNIMPLEMENTED; }
void pblendvb(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x10, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pblendw(const Xmm& xmm, const Operand& op, int imm) { opGen(xmm, op, 0x0E, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A); UNIMPLEMENTED; }
void pclmulhqhdq(const Xmm& xmm, const Operand& op) { pclmulqdq(xmm, op, 0x11); UNIMPLEMENTED; }
void pclmulhqlqdq(const Xmm& xmm, const Operand& op) { pclmulqdq(xmm, op, 0x01); UNIMPLEMENTED; }
void pclmullqhdq(const Xmm& xmm, const Operand& op) { pclmulqdq(xmm, op, 0x10); UNIMPLEMENTED; }
void pclmullqlqdq(const Xmm& xmm, const Operand& op) { pclmulqdq(xmm, op, 0x00); UNIMPLEMENTED; }
void pclmulqdq(const Xmm& xmm, const Operand& op, int imm) { opGen(xmm, op, 0x44, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A); UNIMPLEMENTED; }
void pcmpeqb(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x74); UNIMPLEMENTED; }
void pcmpeqd(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x76); UNIMPLEMENTED; }
void pcmpeqq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x29, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pcmpeqw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x75); UNIMPLEMENTED; }
void pcmpestri(const Xmm& xmm, const Operand& op, uint8 imm) { opGen(xmm, op, 0x61, 0x66, isXMM_XMMorMEM, imm, 0x3A); UNIMPLEMENTED; }
void pcmpestrm(const Xmm& xmm, const Operand& op, uint8 imm) { opGen(xmm, op, 0x60, 0x66, isXMM_XMMorMEM, imm, 0x3A); UNIMPLEMENTED; }
void pcmpgtb(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x64); UNIMPLEMENTED; }
void pcmpgtd(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x66); UNIMPLEMENTED; }
void pcmpgtq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x37, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pcmpgtw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x65); UNIMPLEMENTED; }
void pcmpistri(const Xmm& xmm, const Operand& op, uint8 imm) { opGen(xmm, op, 0x63, 0x66, isXMM_XMMorMEM, imm, 0x3A); UNIMPLEMENTED; }
void pcmpistrm(const Xmm& xmm, const Operand& op, uint8 imm) { opGen(xmm, op, 0x62, 0x66, isXMM_XMMorMEM, imm, 0x3A); UNIMPLEMENTED; }
void pdep(const Reg32e& r1, const Reg32e& r2, const Operand& op) { opGpr(r1, r2, op, T_F2 | T_0F38, 0xf5, true); UNIMPLEMENTED; }
void pext(const Reg32e& r1, const Reg32e& r2, const Operand& op) { opGpr(r1, r2, op, T_F3 | T_0F38, 0xf5, true); UNIMPLEMENTED; }
void pextrb(const Operand& op, const Xmm& xmm, uint8 imm) { opExt(op, xmm, 0x14, imm); UNIMPLEMENTED; }
void pextrd(const Operand& op, const Xmm& xmm, uint8 imm) { opExt(op, xmm, 0x16, imm); decodeAndTransToAArch64(); }
void pextrw(const Operand& op, const Mmx& xmm, uint8 imm) { opExt(op, xmm, 0x15, imm, true); UNIMPLEMENTED; }
void phaddd(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x02, 0x66, NONE, 0x38); UNIMPLEMENTED; }
void phaddsw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x03, 0x66, NONE, 0x38); UNIMPLEMENTED; }
void phaddw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x01, 0x66, NONE, 0x38); decodeAndTransToAArch64(); }
void phminposuw(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x41, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void phsubd(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x06, 0x66, NONE, 0x38); UNIMPLEMENTED; }
void phsubsw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x07, 0x66, NONE, 0x38); UNIMPLEMENTED; }
void phsubw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x05, 0x66, NONE, 0x38); UNIMPLEMENTED; }
void pinsrb(const Xmm& xmm, const Operand& op, uint8 imm) { opGen(xmm, op, 0x20, 0x66, isXMM_REG32orMEM, imm, 0x3A); decodeAndTransToAArch64();}
void pinsrd(const Xmm& xmm, const Operand& op, uint8 imm) { opGen(xmm, op, 0x22, 0x66, isXMM_REG32orMEM, imm, 0x3A); decodeAndTransToAArch64(); }
void pinsrw(const Mmx& mmx, const Operand& op, int imm) { if (!op.isREG(32) && !op.isMEM()) throw Error(ERR_BAD_COMBINATION); opGen(mmx, op, 0xC4, mmx.isXMM() ? 0x66 : NONE, 0, imm); decodeAndTransToAArch64(); }
void pmaddubsw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x04, 0x66, NONE, 0x38); UNIMPLEMENTED; }
void pmaddwd(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xF5); UNIMPLEMENTED; }
void pmaxsb(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x3C, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pmaxsd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x3D, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pmaxsw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xEE); UNIMPLEMENTED; }
void pmaxub(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xDE); UNIMPLEMENTED; }
void pmaxud(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x3F, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pmaxuw(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x3E, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pminsb(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x38, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pminsd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x39, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pminsw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xEA); UNIMPLEMENTED; }
void pminub(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xDA); UNIMPLEMENTED; }
void pminud(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x3B, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pminuw(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x3A, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pmovmskb(const Reg32e& reg, const Mmx& mmx) { if (mmx.isXMM()) db(0x66); opModR(reg, mmx, 0x0F, 0xD7); UNIMPLEMENTED; }
void pmovsxbd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x21, 0x66, isXMM_XMMorMEM, NONE, 0x38); decodeAndTransToAArch64(); }
void pmovsxbq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x22, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pmovsxbw(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x20, 0x66, isXMM_XMMorMEM, NONE, 0x38); decodeAndTransToAArch64(); }
void pmovsxdq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x25, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pmovsxwd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x23, 0x66, isXMM_XMMorMEM, NONE, 0x38); decodeAndTransToAArch64(); }
void pmovsxwq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x24, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pmovzxbd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x31, 0x66, isXMM_XMMorMEM, NONE, 0x38); decodeAndTransToAArch64(); }
void pmovzxbq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x32, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pmovzxbw(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x30, 0x66, isXMM_XMMorMEM, NONE, 0x38); decodeAndTransToAArch64(); }
void pmovzxdq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x35, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pmovzxwd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x33, 0x66, isXMM_XMMorMEM, NONE, 0x38); decodeAndTransToAArch64(); }
void pmovzxwq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x34, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pmuldq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x28, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pmulhrsw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x0B, 0x66, NONE, 0x38); UNIMPLEMENTED; }
void pmulhuw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xE4); UNIMPLEMENTED; }
void pmulhw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xE5); UNIMPLEMENTED; }
void pmulld(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x40, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void pmullw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xD5); UNIMPLEMENTED; }
void pmuludq(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xF4); UNIMPLEMENTED; }
void popcnt(const Reg&reg, const Operand& op) { opSp1(reg, op, 0xF3, 0x0F, 0xB8); UNIMPLEMENTED; }
void popf() { db(0x9D); UNIMPLEMENTED; }
void por(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xEB); UNIMPLEMENTED; }
void prefetchnta(const Address& addr) { opModM(addr, Reg32(0), 0x0F, 0x18); UNIMPLEMENTED; }
void prefetcht0(const Address& addr) { opModM(addr, Reg32(1), 0x0F, 0x18); decodeAndTransToAArch64(); }
void prefetcht1(const Address& addr) { opModM(addr, Reg32(2), 0x0F, 0x18); decodeAndTransToAArch64(); }
void prefetcht2(const Address& addr) { opModM(addr, Reg32(3), 0x0F, 0x18); decodeAndTransToAArch64(); }
void prefetchw(const Address& addr) { opModM(addr, Reg32(1), 0x0F, 0x0D); UNIMPLEMENTED; }
void prefetchwt1(const Address& addr) { opModM(addr, Reg32(2), 0x0F, 0x0D); UNIMPLEMENTED; }
void psadbw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xF6); UNIMPLEMENTED; }
void pshufb(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x00, 0x66, NONE, 0x38); UNIMPLEMENTED; }
void pshufd(const Mmx& mmx, const Operand& op, uint8 imm8) { opMMX(mmx, op, 0x70, 0x66, imm8); decodeAndTransToAArch64(); }
void pshufhw(const Mmx& mmx, const Operand& op, uint8 imm8) { opMMX(mmx, op, 0x70, 0xF3, imm8); UNIMPLEMENTED; }
void pshuflw(const Mmx& mmx, const Operand& op, uint8 imm8) { opMMX(mmx, op, 0x70, 0xF2, imm8); UNIMPLEMENTED; }
void pshufw(const Mmx& mmx, const Operand& op, uint8 imm8) { opMMX(mmx, op, 0x70, 0x00, imm8); UNIMPLEMENTED; }
void psignb(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x08, 0x66, NONE, 0x38); UNIMPLEMENTED; }
void psignd(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x0A, 0x66, NONE, 0x38); UNIMPLEMENTED; }
void psignw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x09, 0x66, NONE, 0x38); UNIMPLEMENTED; }
void pslld(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xF2); UNIMPLEMENTED; }
void pslld(const Mmx& mmx, int imm8) { opMMX_IMM(mmx, imm8, 0x72, 6); UNIMPLEMENTED; }
void pslldq(const Xmm& xmm, int imm8) { opMMX_IMM(xmm, imm8, 0x73, 7); UNIMPLEMENTED; }
void psllq(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xF3); UNIMPLEMENTED; }
void psllq(const Mmx& mmx, int imm8) { opMMX_IMM(mmx, imm8, 0x73, 6); UNIMPLEMENTED; }
void psllw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xF1); UNIMPLEMENTED; }
void psllw(const Mmx& mmx, int imm8) { opMMX_IMM(mmx, imm8, 0x71, 6); UNIMPLEMENTED; }
void psrad(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xE2); UNIMPLEMENTED; }
void psrad(const Mmx& mmx, int imm8) { opMMX_IMM(mmx, imm8, 0x72, 4); UNIMPLEMENTED; }
void psraw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xE1); UNIMPLEMENTED; }
void psraw(const Mmx& mmx, int imm8) { opMMX_IMM(mmx, imm8, 0x71, 4); UNIMPLEMENTED; }
void psrld(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xD2); UNIMPLEMENTED; }
void psrld(const Mmx& mmx, int imm8) { opMMX_IMM(mmx, imm8, 0x72, 2); UNIMPLEMENTED; }
void psrldq(const Xmm& xmm, int imm8) { opMMX_IMM(xmm, imm8, 0x73, 3); UNIMPLEMENTED; }
void psrlq(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xD3); UNIMPLEMENTED; }
void psrlq(const Mmx& mmx, int imm8) { opMMX_IMM(mmx, imm8, 0x73, 2); UNIMPLEMENTED; }
void psrlw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xD1); UNIMPLEMENTED; }
void psrlw(const Mmx& mmx, int imm8) { opMMX_IMM(mmx, imm8, 0x71, 2); UNIMPLEMENTED; }
void psubb(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xF8); UNIMPLEMENTED; }
void psubd(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xFA); UNIMPLEMENTED; }
void psubq(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xFB); UNIMPLEMENTED; }
void psubsb(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xE8); UNIMPLEMENTED; }
void psubsw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xE9); UNIMPLEMENTED; }
void psubusb(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xD8); UNIMPLEMENTED; }
void psubusw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xD9); UNIMPLEMENTED; }
void psubw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xF9); UNIMPLEMENTED; }
void ptest(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x17, 0x66, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void punpckhbw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x68); decodeAndTransToAArch64(); }
void punpckhdq(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x6A); decodeAndTransToAArch64(); }
void punpckhqdq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x6D, 0x66, isXMM_XMMorMEM); decodeAndTransToAArch64(); }
void punpckhwd(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x69); decodeAndTransToAArch64(); }
void punpcklbw(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x60); decodeAndTransToAArch64(); }
void punpckldq(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x62); decodeAndTransToAArch64(); }
void punpcklqdq(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x6C, 0x66, isXMM_XMMorMEM); decodeAndTransToAArch64(); }
void punpcklwd(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0x61); decodeAndTransToAArch64(); }
void pushf() { db(0x9C); std::cerr << "No support for PUSHF instruction" << std::endl; }
void pxor(const Mmx& mmx, const Operand& op) { opMMX(mmx, op, 0xEF); decodeAndTransToAArch64(); }
void rcl(const Operand& op, const Reg8& _cl) { opShift(op, _cl, 2); UNIMPLEMENTED; }
void rcl(const Operand& op, int imm) { opShift(op, imm, 2); UNIMPLEMENTED; }
void rcpps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x53, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void rcpss(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x53, 0xF3, isXMM_XMMorMEM); UNIMPLEMENTED; }
void rcr(const Operand& op, const Reg8& _cl) { opShift(op, _cl, 3); UNIMPLEMENTED; }
void rcr(const Operand& op, int imm) { opShift(op, imm, 3); UNIMPLEMENTED; }
void rdmsr() { db(0x0F); db(0x32); UNIMPLEMENTED; }
void rdpmc() { db(0x0F); db(0x33); UNIMPLEMENTED; }
void rdrand(const Reg& r) { if (r.isBit(8)) throw Error(ERR_BAD_SIZE_OF_REGISTER); opModR(Reg(6, Operand::REG, r.getBit()), r, 0x0F, 0xC7); UNIMPLEMENTED; }
void rdseed(const Reg& r) { if (r.isBit(8)) throw Error(ERR_BAD_SIZE_OF_REGISTER); opModR(Reg(7, Operand::REG, r.getBit()), r, 0x0F, 0xC7); UNIMPLEMENTED; }
void rdtsc() { db(0x0F); db(0x31); UNIMPLEMENTED; }
void rdtscp() { db(0x0F); db(0x01); db(0xF9); UNIMPLEMENTED; }
void rep() { db(0xF3); UNIMPLEMENTED; }
void repe() { db(0xF3); UNIMPLEMENTED; }
void repne() { db(0xF2); UNIMPLEMENTED; }
void repnz() { db(0xF2); UNIMPLEMENTED; }
void repz() { db(0xF3); UNIMPLEMENTED; }
void ret(int imm = 0) { if (imm) { db(0xC2); CodeArray::dw(imm); } else { db(0xC3); }
#ifdef XBYAK_TRANSLATE_AARCH64
  std::cerr << "RET instruction is generated." << std::endl;
#endif
  decodeAndTransToAArch64(); }
void rol(const Operand& op, const Reg8& _cl) { opShift(op, _cl, 0); UNIMPLEMENTED; }
void rol(const Operand& op, int imm) { opShift(op, imm, 0); UNIMPLEMENTED; }
void ror(const Operand& op, const Reg8& _cl) { opShift(op, _cl, 1); UNIMPLEMENTED; }
void ror(const Operand& op, int imm) { opShift(op, imm, 1); UNIMPLEMENTED; }
void rorx(const Reg32e& r, const Operand& op, uint8 imm) { opGpr(r, op, Reg32e(0, r.getBit()), T_0F3A | T_F2, 0xF0, false, imm); UNIMPLEMENTED; }
void roundpd(const Xmm& xmm, const Operand& op, uint8 imm) { opGen(xmm, op, 0x09, 0x66, isXMM_XMMorMEM, imm, 0x3A); UNIMPLEMENTED; }
void roundps(const Xmm& xmm, const Operand& op, uint8 imm) { opGen(xmm, op, 0x08, 0x66, isXMM_XMMorMEM, imm, 0x3A); UNIMPLEMENTED; }
void roundsd(const Xmm& xmm, const Operand& op, int imm) { opGen(xmm, op, 0x0B, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A); UNIMPLEMENTED; }
void roundss(const Xmm& xmm, const Operand& op, int imm) { opGen(xmm, op, 0x0A, 0x66, isXMM_XMMorMEM, static_cast<uint8>(imm), 0x3A); UNIMPLEMENTED; }
void rsqrtps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x52, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void rsqrtss(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x52, 0xF3, isXMM_XMMorMEM); UNIMPLEMENTED; }
void sahf() { db(0x9E); UNIMPLEMENTED; }
void sal(const Operand& op, const Reg8& _cl) { opShift(op, _cl, 4); UNIMPLEMENTED; }
void sal(const Operand& op, int imm) { opShift(op, imm, 4); decodeAndTransToAArch64(); }
void sar(const Operand& op, const Reg8& _cl) { opShift(op, _cl, 7); decodeAndTransToAArch64(); }
void sar(const Operand& op, int imm) { opShift(op, imm, 7); decodeAndTransToAArch64(); }
void sarx(const Reg32e& r1, const Operand& op, const Reg32e& r2) { opGpr(r1, op, r2, T_F3 | T_0F38, 0xf7, false); UNIMPLEMENTED; }
void sbb(const Operand& op, uint32 imm) { opRM_I(op, imm, 0x18, 3); UNIMPLEMENTED; }
void sbb(const Operand& op1, const Operand& op2) { opRM_RM(op1, op2, 0x18); UNIMPLEMENTED; }
void scasb() { db(0xAE); UNIMPLEMENTED; }
void scasd() { db(0xAF); UNIMPLEMENTED; }
void scasw() { db(0x66); db(0xAF); UNIMPLEMENTED; }
void seta(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 7); UNIMPLEMENTED; }//-V524
void setae(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 3); UNIMPLEMENTED; }//-V524
void setb(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 2); UNIMPLEMENTED; }//-V524
void setbe(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 6); UNIMPLEMENTED; }//-V524
void setc(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 2); UNIMPLEMENTED; }//-V524
void sete(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 4); UNIMPLEMENTED; }//-V524
void setg(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 15); UNIMPLEMENTED; }//-V524
void setge(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 13); UNIMPLEMENTED; }//-V524
void setl(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 12); UNIMPLEMENTED; }//-V524
void setle(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 14); UNIMPLEMENTED; }//-V524
void setna(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 6); UNIMPLEMENTED; }//-V524
void setnae(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 2); UNIMPLEMENTED; }//-V524
void setnb(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 3); UNIMPLEMENTED; }//-V524
void setnbe(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 7); UNIMPLEMENTED; }//-V524
void setnc(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 3); UNIMPLEMENTED; }//-V524
void setne(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 5); UNIMPLEMENTED; }//-V524
void setng(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 14); UNIMPLEMENTED; }//-V524
void setnge(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 12); UNIMPLEMENTED; }//-V524
void setnl(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 13); UNIMPLEMENTED; }//-V524
void setnle(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 15); UNIMPLEMENTED; }//-V524
void setno(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 1); UNIMPLEMENTED; }//-V524
void setnp(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 11); UNIMPLEMENTED; }//-V524
void setns(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 9); UNIMPLEMENTED; }//-V524
void setnz(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 5); UNIMPLEMENTED; }//-V524
void seto(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 0); UNIMPLEMENTED; }//-V524
void setp(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 10); UNIMPLEMENTED; }//-V524
void setpe(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 10); UNIMPLEMENTED; }//-V524
void setpo(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 11); UNIMPLEMENTED; }//-V524
void sets(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 8); UNIMPLEMENTED; }//-V524
void setz(const Operand& op) { opR_ModM(op, 8, 0, 0x0F, 0x90 | 4); UNIMPLEMENTED; }//-V524
void sfence() { db(0x0F); db(0xAE); db(0xF8); UNIMPLEMENTED; }
void sha1msg1(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xC9, NONE, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void sha1msg2(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xCA, NONE, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void sha1nexte(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xC8, NONE, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void sha1rnds4(const Xmm& xmm, const Operand& op, uint8 imm) { opGen(xmm, op, 0xCC, NONE, isXMM_XMMorMEM, imm, 0x3A); UNIMPLEMENTED; }
void sha256msg1(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xCC, NONE, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void sha256msg2(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xCD, NONE, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void sha256rnds2(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0xCB, NONE, isXMM_XMMorMEM, NONE, 0x38); UNIMPLEMENTED; }
void shl(const Operand& op, const Reg8& _cl) { opShift(op, _cl, 4); decodeAndTransToAArch64(); }
void shl(const Operand& op, int imm) { opShift(op, imm, 4); decodeAndTransToAArch64(); }
void shld(const Operand& op, const Reg& reg, const Reg8& _cl) { opShxd(op, reg, 0, 0xA4, &_cl); UNIMPLEMENTED; }
void shld(const Operand& op, const Reg& reg, uint8 imm) { opShxd(op, reg, imm, 0xA4); UNIMPLEMENTED; }
void shlx(const Reg32e& r1, const Operand& op, const Reg32e& r2) { opGpr(r1, op, r2, T_66 | T_0F38, 0xf7, false); UNIMPLEMENTED; }
void shr(const Operand& op, const Reg8& _cl) { opShift(op, _cl, 5); UNIMPLEMENTED; }
void shr(const Operand& op, int imm) { opShift(op, imm, 5); UNIMPLEMENTED; }
void shrd(const Operand& op, const Reg& reg, const Reg8& _cl) { opShxd(op, reg, 0, 0xAC, &_cl); UNIMPLEMENTED; }
void shrd(const Operand& op, const Reg& reg, uint8 imm) { opShxd(op, reg, imm, 0xAC); UNIMPLEMENTED; }
void shrx(const Reg32e& r1, const Operand& op, const Reg32e& r2) { opGpr(r1, op, r2, T_F2 | T_0F38, 0xf7, false); UNIMPLEMENTED; }
void shufpd(const Xmm& xmm, const Operand& op, uint8 imm8) { opGen(xmm, op, 0xC6, 0x66, isXMM_XMMorMEM, imm8); UNIMPLEMENTED; }
void shufps(const Xmm& xmm, const Operand& op, uint8 imm8) { opGen(xmm, op, 0xC6, 0x100, isXMM_XMMorMEM, imm8); decodeAndTransToAArch64(); }
void sqrtpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x51, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void sqrtps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x51, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void sqrtsd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x51, 0xF2, isXMM_XMMorMEM); UNIMPLEMENTED; }
void sqrtss(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x51, 0xF3, isXMM_XMMorMEM); UNIMPLEMENTED; }
void stac() { db(0x0F); db(0x01); db(0xCB); UNIMPLEMENTED; }
void stc() { db(0xF9); UNIMPLEMENTED; }
void std() { db(0xFD); UNIMPLEMENTED; }
void sti() { db(0xFB); UNIMPLEMENTED; }
void stmxcsr(const Address& addr) { opModM(addr, Reg32(3), 0x0F, 0xAE); UNIMPLEMENTED; }
void stosb() { db(0xAA); UNIMPLEMENTED; }
void stosd() { db(0xAB); UNIMPLEMENTED; }
void stosw() { db(0x66); db(0xAB); UNIMPLEMENTED; }
void sub(const Operand& op, uint32 imm) { opRM_I(op, imm, 0x28, 5); decodeAndTransToAArch64(); }
void sub(const Operand& op1, const Operand& op2) { opRM_RM(op1, op2, 0x28); decodeAndTransToAArch64(); }
void subpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5C, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void subps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5C, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void subsd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5C, 0xF2, isXMM_XMMorMEM); UNIMPLEMENTED; }
void subss(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x5C, 0xF3, isXMM_XMMorMEM); UNIMPLEMENTED; }
void sysenter() { db(0x0F); db(0x34); UNIMPLEMENTED; }
void sysexit() { db(0x0F); db(0x35); UNIMPLEMENTED; }
void tzcnt(const Reg&reg, const Operand& op) { opSp1(reg, op, 0xF3, 0x0F, 0xBC); UNIMPLEMENTED; }
void ucomisd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x2E, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void ucomiss(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x2E, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void ud2() { db(0x0F); db(0x0B); UNIMPLEMENTED; }
void unpckhpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x15, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void unpckhps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x15, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void unpcklpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x14, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void unpcklps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x14, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
void vaddpd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x58); UNIMPLEMENTED; }
void vaddps(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x58); decodeAndTransToAArch64(); }
void vaddsd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F2 | T_EW1 | T_EVEX | T_ER_Z | T_N8, 0x58); UNIMPLEMENTED; }
void vaddss(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F3 | T_EW0 | T_EVEX | T_ER_Z | T_N4, 0x58); decodeAndTransToAArch64(); }
void vaddsubpd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_66 | T_0F | T_YMM, 0xD0); UNIMPLEMENTED; }
void vaddsubps(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_F2 | T_0F | T_YMM, 0xD0); UNIMPLEMENTED; }
void vaesdec(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_66 | T_0F38 | T_YMM | T_EVEX, 0xDE); UNIMPLEMENTED; }
void vaesdeclast(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_66 | T_0F38 | T_YMM | T_EVEX, 0xDF); UNIMPLEMENTED; }
void vaesenc(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_66 | T_0F38 | T_YMM | T_EVEX, 0xDC); UNIMPLEMENTED; }
void vaesenclast(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_66 | T_0F38 | T_YMM | T_EVEX, 0xDD); UNIMPLEMENTED; }
void vaesimc(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F38 | T_W0, 0xDB); UNIMPLEMENTED; }
void vaeskeygenassist(const Xmm& xm, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A, 0xDF, imm); UNIMPLEMENTED; }
void vandnpd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x55); UNIMPLEMENTED; }
void vandnps(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x55); UNIMPLEMENTED; }
void vandpd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x54); UNIMPLEMENTED; }
void vandps(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x54); decodeAndTransToAArch64(); }
void vblendpd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0 | T_YMM, 0x0D, imm); UNIMPLEMENTED; }
void vblendps(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0 | T_YMM, 0x0C, imm); UNIMPLEMENTED; }
void vblendvpd(const Xmm& x1, const Xmm& x2, const Operand& op, const Xmm& x4) { opAVX_X_X_XM(x1, x2, op, T_0F3A | T_66 | T_YMM, 0x4B, x4.getIdx() << 4); UNIMPLEMENTED; }
void vblendvps(const Xmm& x1, const Xmm& x2, const Operand& op, const Xmm& x4) { opAVX_X_X_XM(x1, x2, op, T_0F3A | T_66 | T_YMM, 0x4A, x4.getIdx() << 4); decodeAndTransToAArch64(); }
void vbroadcastf128(const Ymm& y, const Address& addr) { opAVX_X_XM_IMM(y, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x1A); UNIMPLEMENTED; }
void vbroadcasti128(const Ymm& y, const Address& addr) { opAVX_X_XM_IMM(y, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x5A); UNIMPLEMENTED; }
void vbroadcastsd(const Ymm& y, const Operand& op) { if (!op.isMEM() && !(y.isYMM() && op.isXMM()) && !(y.isZMM() && op.isXMM())) throw Error(ERR_BAD_COMBINATION); opAVX_X_XM_IMM(y, op, T_0F38 | T_66 | T_W0 | T_YMM | T_EVEX | T_EW1 | T_N8, 0x19); decodeAndTransToAArch64(); }
void vbroadcastss(const Xmm& x, const Operand& op) { if (!(op.isXMM() || op.isMEM())) throw Error(ERR_BAD_COMBINATION); opAVX_X_XM_IMM(x, op, T_N4 | T_66 | T_0F38 | T_W0 | T_YMM | T_EVEX, 0x18); decodeAndTransToAArch64(); }
void vcmpeq_ospd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 16); UNIMPLEMENTED; }
void vcmpeq_osps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 16); }
void vcmpeq_ossd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 16); UNIMPLEMENTED; }
void vcmpeq_osss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 16); UNIMPLEMENTED; }
void vcmpeq_uqpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 8); UNIMPLEMENTED; }
void vcmpeq_uqps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 8); }
void vcmpeq_uqsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 8); UNIMPLEMENTED; }
void vcmpeq_uqss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 8); UNIMPLEMENTED; }
void vcmpeq_uspd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 24); UNIMPLEMENTED; }
void vcmpeq_usps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 24); }
void vcmpeq_ussd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 24); UNIMPLEMENTED; }
void vcmpeq_usss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 24); UNIMPLEMENTED; }
void vcmpeqpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 0); UNIMPLEMENTED; }
void vcmpeqps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 0); }
void vcmpeqsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 0); UNIMPLEMENTED; }
void vcmpeqss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 0); UNIMPLEMENTED; }
void vcmpfalse_ospd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 27); UNIMPLEMENTED; }
void vcmpfalse_osps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 27); }
void vcmpfalse_ossd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 27); UNIMPLEMENTED; }
void vcmpfalse_osss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 27); UNIMPLEMENTED; }
void vcmpfalsepd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 11); UNIMPLEMENTED; }
void vcmpfalseps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 11); }
void vcmpfalsesd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 11); UNIMPLEMENTED; }
void vcmpfalsess(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 11); UNIMPLEMENTED; }
void vcmpge_oqpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 29); UNIMPLEMENTED; }
void vcmpge_oqps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 29); }
void vcmpge_oqsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 29); UNIMPLEMENTED; }
void vcmpge_oqss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 29); UNIMPLEMENTED; }
void vcmpgepd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 13); UNIMPLEMENTED; }
void vcmpgeps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 13); }
void vcmpgesd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 13); UNIMPLEMENTED; }
void vcmpgess(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 13); UNIMPLEMENTED; }
void vcmpgt_oqpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 30); UNIMPLEMENTED; }
void vcmpgt_oqps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 30); }
void vcmpgt_oqsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 30); UNIMPLEMENTED; }
void vcmpgt_oqss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 30); UNIMPLEMENTED; }
void vcmpgtpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 14); UNIMPLEMENTED; }
void vcmpgtps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 14); }
void vcmpgtsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 14); UNIMPLEMENTED; }
void vcmpgtss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 14); UNIMPLEMENTED; }
void vcmple_oqpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 18); UNIMPLEMENTED; }
void vcmple_oqps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 18); }
void vcmple_oqsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 18); UNIMPLEMENTED; }
void vcmple_oqss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 18); UNIMPLEMENTED; }
void vcmplepd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 2); UNIMPLEMENTED; }
void vcmpleps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 2); }
void vcmplesd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 2); UNIMPLEMENTED; }
void vcmpless(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 2); UNIMPLEMENTED; }
void vcmplt_oqpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 17); UNIMPLEMENTED; }
void vcmplt_oqps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 17); }
void vcmplt_oqsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 17); UNIMPLEMENTED; }
void vcmplt_oqss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 17); UNIMPLEMENTED; }
void vcmpltpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 1); UNIMPLEMENTED; }
void vcmpltps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 1); }
void vcmpltsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 1); UNIMPLEMENTED; }
void vcmpltss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 1); UNIMPLEMENTED; }
void vcmpneq_oqpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 12); UNIMPLEMENTED; }
void vcmpneq_oqps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 12); }
void vcmpneq_oqsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 12); UNIMPLEMENTED; }
void vcmpneq_oqss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 12); UNIMPLEMENTED; }
void vcmpneq_ospd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 28); UNIMPLEMENTED; }
void vcmpneq_osps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 28); }
void vcmpneq_ossd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 28); UNIMPLEMENTED; }
void vcmpneq_osss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 28); UNIMPLEMENTED; }
void vcmpneq_uspd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 20); UNIMPLEMENTED; }
void vcmpneq_usps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 20); }
void vcmpneq_ussd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 20); UNIMPLEMENTED; }
void vcmpneq_usss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 20); UNIMPLEMENTED; }
void vcmpneqpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 4); UNIMPLEMENTED; }
void vcmpneqps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 4); }
void vcmpneqsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 4); UNIMPLEMENTED; }
void vcmpneqss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 4); UNIMPLEMENTED; }
void vcmpnge_uqpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 25); UNIMPLEMENTED; }
void vcmpnge_uqps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 25); }
void vcmpnge_uqsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 25); UNIMPLEMENTED; }
void vcmpnge_uqss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 25); UNIMPLEMENTED; }
void vcmpngepd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 9); UNIMPLEMENTED; }
void vcmpngeps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 9); }
void vcmpngesd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 9); UNIMPLEMENTED; }
void vcmpngess(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 9); UNIMPLEMENTED; }
void vcmpngt_uqpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 26); UNIMPLEMENTED; }
void vcmpngt_uqps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 26); }
void vcmpngt_uqsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 26); UNIMPLEMENTED; }
void vcmpngt_uqss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 26); UNIMPLEMENTED; }
void vcmpngtpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 10); UNIMPLEMENTED; }
void vcmpngtps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 10); }
void vcmpngtsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 10); UNIMPLEMENTED; }
void vcmpngtss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 10); UNIMPLEMENTED; }
void vcmpnle_uqpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 22); UNIMPLEMENTED; }
void vcmpnle_uqps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 22); }
void vcmpnle_uqsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 22); UNIMPLEMENTED; }
void vcmpnle_uqss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 22); UNIMPLEMENTED; }
void vcmpnlepd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 6); UNIMPLEMENTED; }
void vcmpnleps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 6); }
void vcmpnlesd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 6); UNIMPLEMENTED; }
void vcmpnless(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 6); UNIMPLEMENTED; }
void vcmpnlt_uqpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 21); UNIMPLEMENTED; }
void vcmpnlt_uqps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 21); }
void vcmpnlt_uqsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 21); UNIMPLEMENTED; }
void vcmpnlt_uqss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 21); UNIMPLEMENTED; }
void vcmpnltpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 5); UNIMPLEMENTED; }
void vcmpnltps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 5); }
void vcmpnltsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 5); UNIMPLEMENTED; }
void vcmpnltss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 5); UNIMPLEMENTED; }
void vcmpord_spd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 23); UNIMPLEMENTED; }
void vcmpord_sps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 23); }
void vcmpord_ssd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 23); UNIMPLEMENTED; }
void vcmpord_sss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 23); UNIMPLEMENTED; }
void vcmpordpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 7); UNIMPLEMENTED; }
void vcmpordps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 7);}
void vcmpordsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 7); UNIMPLEMENTED; }
void vcmpordss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 7); UNIMPLEMENTED; }
void vcmppd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0xC2, imm); UNIMPLEMENTED; }
void vcmpps(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_0F | T_YMM, 0xC2, imm); decodeAndTransToAArch64(); }
void vcmpsd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_F2 | T_0F, 0xC2, imm); UNIMPLEMENTED; }
void vcmpss(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_F3 | T_0F, 0xC2, imm); UNIMPLEMENTED; }
void vcmptrue_uspd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 31); UNIMPLEMENTED; }
void vcmptrue_usps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 31); }
void vcmptrue_ussd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 31); UNIMPLEMENTED; }
void vcmptrue_usss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 31); UNIMPLEMENTED; }
void vcmptruepd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 15); UNIMPLEMENTED; }
void vcmptrueps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 15); }
void vcmptruesd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 15); UNIMPLEMENTED; }
void vcmptruess(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 15); UNIMPLEMENTED; }
void vcmpunord_spd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 19); UNIMPLEMENTED; }
void vcmpunord_sps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 19); }
void vcmpunord_ssd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 19); UNIMPLEMENTED; }
void vcmpunord_sss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 19); UNIMPLEMENTED; }
void vcmpunordpd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmppd(x1, x2, op, 3); UNIMPLEMENTED; }
void vcmpunordps(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpps(x1, x2, op, 3); }
void vcmpunordsd(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpsd(x1, x2, op, 3); UNIMPLEMENTED; }
void vcmpunordss(const Xmm& x1, const Xmm& x2, const Operand& op) { vcmpss(x1, x2, op, 3); UNIMPLEMENTED; }
void vcomisd(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N8 | T_66 | T_0F | T_EW1 | T_EVEX | T_SAE_X, 0x2F); UNIMPLEMENTED; }
void vcomiss(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N4 | T_0F | T_EW0 | T_EVEX | T_SAE_X, 0x2F); UNIMPLEMENTED; }
void vcvtdq2pd(const Xmm& x, const Operand& op) { checkCvt1(x, op); opVex(x, 0, op, T_0F | T_F3 | T_YMM | T_EVEX | T_EW0 | T_B32 | T_N8 | T_N_VL, 0xE6); UNIMPLEMENTED; }
void vcvtdq2ps(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x5B); decodeAndTransToAArch64(); }
void vcvtpd2dq(const Xmm& x, const Operand& op) { opCvt2(x, op, T_0F | T_F2 | T_YMM | T_EVEX | T_EW1 | T_B64 | T_ER_Z, 0xE6); UNIMPLEMENTED; }
void vcvtpd2ps(const Xmm& x, const Operand& op) { opCvt2(x, op, T_0F | T_66 | T_YMM | T_EVEX | T_EW1 | T_B64 | T_ER_Z, 0x5A); UNIMPLEMENTED; }
void vcvtph2ps(const Xmm& x, const Operand& op) { checkCvt1(x, op); opVex(x, 0, op, T_0F38 | T_66 | T_W0 | T_EVEX | T_EW0 | T_N8 | T_N_VL | T_SAE_Y, 0x13); UNIMPLEMENTED; }
void vcvtps2dq(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x5B); decodeAndTransToAArch64(); }
void vcvtps2pd(const Xmm& x, const Operand& op) { checkCvt1(x, op); opVex(x, 0, op, T_0F | T_YMM | T_EVEX | T_EW0 | T_B32 | T_N8 | T_N_VL | T_SAE_Y, 0x5A); UNIMPLEMENTED; }
void vcvtps2ph(const Operand& op, const Xmm& x, uint8 imm) { checkCvt1(x, op); opVex(x, 0, op, T_0F3A | T_66 | T_W0 | T_EVEX | T_EW0 | T_N8 | T_N_VL | T_SAE_Y, 0x1D, imm); UNIMPLEMENTED; }
void vcvtsd2si(const Reg32& r, const Operand& op) { opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, T_0F | T_F2 | T_W0 | T_EVEX | T_EW0 | T_N4 | T_ER_X, 0x2D); UNIMPLEMENTED; }
void vcvtsd2ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_F2 | T_0F | T_EW1 | T_EVEX | T_ER_X, 0x5A); UNIMPLEMENTED; }
void vcvtsi2sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opCvt3(x1, x2, op, T_0F | T_F2 | T_EVEX, T_W1 | T_EW1 | T_ER_X | T_N8, T_W0 | T_EW0 | T_N4, 0x2A); UNIMPLEMENTED; }
void vcvtsi2ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opCvt3(x1, x2, op, T_0F | T_F3 | T_EVEX | T_ER_X, T_W1 | T_EW1 | T_N8, T_W0 | T_EW0 | T_N4, 0x2A); UNIMPLEMENTED; }
void vcvtss2sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_F3 | T_0F | T_EW0 | T_EVEX | T_SAE_X, 0x5A); UNIMPLEMENTED; }
void vcvtss2si(const Reg32& r, const Operand& op) { opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, T_0F | T_F3 | T_W0 | T_EVEX | T_EW0 | T_ER_X | T_N8, 0x2D); UNIMPLEMENTED; }
void vcvttpd2dq(const Xmm& x, const Operand& op) { opCvt2(x, op, T_66 | T_0F | T_YMM | T_EVEX |T_EW1 | T_B64 | T_ER_Z, 0xE6); UNIMPLEMENTED; }
void vcvttps2dq(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_F3 | T_0F | T_EW0 | T_YMM | T_EVEX | T_SAE_Z | T_B32, 0x5B); UNIMPLEMENTED; }
void vcvttsd2si(const Reg32& r, const Operand& op) { opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, T_0F | T_F2 | T_W0 | T_EVEX | T_EW0 | T_N4 | T_SAE_X, 0x2C); UNIMPLEMENTED; }
void vcvttss2si(const Reg32& r, const Operand& op) { opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, T_0F | T_F3 | T_W0 | T_EVEX | T_EW0 | T_SAE_X | T_N8, 0x2C); UNIMPLEMENTED; }
void vdivpd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x5E); UNIMPLEMENTED; }
void vdivps(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x5E); decodeAndTransToAArch64(); }
void vdivsd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F2 | T_EW1 | T_EVEX | T_ER_Z | T_N8, 0x5E); UNIMPLEMENTED; }
void vdivss(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F3 | T_EW0 | T_EVEX | T_ER_Z | T_N4, 0x5E); UNIMPLEMENTED; }
void vdppd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0, 0x41, imm); UNIMPLEMENTED; }
void vdpps(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0 | T_YMM, 0x40, imm); UNIMPLEMENTED; }
void vextractf128(const Operand& op, const Ymm& y, uint8 imm) { if (!(op.isXMEM() && y.isYMM())) throw Error(ERR_BAD_COMBINATION); opVex(y, 0, op, T_0F3A | T_66 | T_W0 | T_YMM, 0x19, imm); UNIMPLEMENTED; }
void vextracti128(const Operand& op, const Ymm& y, uint8 imm) { if (!(op.isXMEM() && y.isYMM())) throw Error(ERR_BAD_COMBINATION); opVex(y, 0, op, T_0F3A | T_66 | T_W0 | T_YMM, 0x39, imm); UNIMPLEMENTED; }
void vextractps(const Operand& op, const Xmm& x, uint8 imm) { if (!((op.isREG(32) || op.isMEM()) && x.isXMM())) throw Error(ERR_BAD_COMBINATION); opVex(x, 0, op, T_0F3A | T_66 | T_W0 | T_EVEX | T_N4, 0x17, imm); UNIMPLEMENTED; }
void vfmadd132pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x98); UNIMPLEMENTED; }
void vfmadd132ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x98); decodeAndTransToAArch64(); }
void vfmadd132sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0x99); UNIMPLEMENTED; }
void vfmadd132ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0x99); UNIMPLEMENTED; }
void vfmadd213pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xA8); UNIMPLEMENTED; }
void vfmadd213ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xA8); decodeAndTransToAArch64(); }
void vfmadd213sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xA9); UNIMPLEMENTED; }
void vfmadd213ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xA9); UNIMPLEMENTED; }
void vfmadd231pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xB8); UNIMPLEMENTED; }
void vfmadd231ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xB8); decodeAndTransToAArch64(); }
void vfmadd231sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xB9); UNIMPLEMENTED; }
void vfmadd231ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xB9); UNIMPLEMENTED; }
void vfmaddsub132pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x96); UNIMPLEMENTED; }
void vfmaddsub132ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x96); UNIMPLEMENTED; }
void vfmaddsub213pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xA6); UNIMPLEMENTED; }
void vfmaddsub213ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xA6); UNIMPLEMENTED; }
void vfmaddsub231pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xB6); UNIMPLEMENTED; }
void vfmaddsub231ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xB6); UNIMPLEMENTED; }
void vfmsub132pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x9A); UNIMPLEMENTED; }
void vfmsub132ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x9A); UNIMPLEMENTED; }
void vfmsub132sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0x9B); UNIMPLEMENTED; }
void vfmsub132ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0x9B); UNIMPLEMENTED; }
void vfmsub213pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xAA); UNIMPLEMENTED; }
void vfmsub213ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xAA); UNIMPLEMENTED; }
void vfmsub213sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xAB); UNIMPLEMENTED; }
void vfmsub213ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xAB); UNIMPLEMENTED; }
void vfmsub231pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xBA); UNIMPLEMENTED; }
void vfmsub231ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xBA); UNIMPLEMENTED; }
void vfmsub231sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xBB); UNIMPLEMENTED; }
void vfmsub231ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xBB); UNIMPLEMENTED; }
void vfmsubadd132pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x97); UNIMPLEMENTED; }
void vfmsubadd132ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x97); UNIMPLEMENTED; }
void vfmsubadd213pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xA7); UNIMPLEMENTED; }
void vfmsubadd213ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xA7); UNIMPLEMENTED; }
void vfmsubadd231pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xB7); UNIMPLEMENTED; }
void vfmsubadd231ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xB7); UNIMPLEMENTED; }
void vfnmadd132pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x9C); UNIMPLEMENTED; }
void vfnmadd132ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x9C); UNIMPLEMENTED; }
void vfnmadd132sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0x9D); UNIMPLEMENTED; }
void vfnmadd132ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0x9D); UNIMPLEMENTED; }
void vfnmadd213pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xAC); UNIMPLEMENTED; }
void vfnmadd213ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xAC); UNIMPLEMENTED; }
void vfnmadd213sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xAD); UNIMPLEMENTED; }
void vfnmadd213ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xAD); UNIMPLEMENTED; }
void vfnmadd231pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xBC); UNIMPLEMENTED; }
void vfnmadd231ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xBC); decodeAndTransToAArch64(); }
void vfnmadd231sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xBD); UNIMPLEMENTED; }
void vfnmadd231ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xBD); UNIMPLEMENTED; }
void vfnmsub132pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x9E); UNIMPLEMENTED; }
void vfnmsub132ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x9E); UNIMPLEMENTED; }
void vfnmsub132sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0x9F); UNIMPLEMENTED; }
void vfnmsub132ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0x9F); UNIMPLEMENTED; }
void vfnmsub213pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xAE); UNIMPLEMENTED; }
void vfnmsub213ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xAE); UNIMPLEMENTED; }
void vfnmsub213sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xAF); UNIMPLEMENTED; }
void vfnmsub213ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xAF); UNIMPLEMENTED; }
void vfnmsub231pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0xBE); UNIMPLEMENTED; }
void vfnmsub231ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0xBE); UNIMPLEMENTED; }
void vfnmsub231sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_W1 | T_EW1 | T_EVEX | T_ER_X, 0xBF); UNIMPLEMENTED; }
void vfnmsub231ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_W0 | T_EW0 | T_EVEX | T_ER_X, 0xBF); UNIMPLEMENTED; }
void vgatherdpd(const Xmm& x1, const Address& addr, const Xmm& x2) { opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W1, 0x92, 0); UNIMPLEMENTED; }
void vgatherdps(const Xmm& x1, const Address& addr, const Xmm& x2) { opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W0, 0x92, 1); UNIMPLEMENTED; }
void vgatherqpd(const Xmm& x1, const Address& addr, const Xmm& x2) { opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W1, 0x93, 1); UNIMPLEMENTED; }
void vgatherqps(const Xmm& x1, const Address& addr, const Xmm& x2) { opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W0, 0x93, 2); decodeAndTransToAArch64(); }
void vgf2p8affineinvqb(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W1 | T_EW1 | T_YMM | T_EVEX | T_SAE_Z | T_B64, 0xCF, imm); UNIMPLEMENTED; }
void vgf2p8affineqb(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W1 | T_EW1 | T_YMM | T_EVEX | T_SAE_Z | T_B64, 0xCE, imm); UNIMPLEMENTED; }
void vgf2p8mulb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_SAE_Z, 0xCF); UNIMPLEMENTED; }
void vhaddpd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_66 | T_0F | T_YMM, 0x7C); UNIMPLEMENTED; }
void vhaddps(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_F2 | T_0F | T_YMM, 0x7C); UNIMPLEMENTED; }
void vhsubpd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_66 | T_0F | T_YMM, 0x7D); UNIMPLEMENTED; }
void vhsubps(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_F2 | T_0F | T_YMM, 0x7D); UNIMPLEMENTED; }
void vinsertf128(const Ymm& y1, const Ymm& y2, const Operand& op, uint8 imm) { if (!(y1.isYMM() && y2.isYMM() && op.isXMEM())) throw Error(ERR_BAD_COMBINATION); opVex(y1, &y2, op, T_0F3A | T_66 | T_W0 | T_YMM, 0x18, imm); decodeAndTransToAArch64(); }
void vinserti128(const Ymm& y1, const Ymm& y2, const Operand& op, uint8 imm) { if (!(y1.isYMM() && y2.isYMM() && op.isXMEM())) throw Error(ERR_BAD_COMBINATION); opVex(y1, &y2, op, T_0F3A | T_66 | T_W0 | T_YMM, 0x38, imm); UNIMPLEMENTED; }
void vinsertps(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F3A | T_W0 | T_EW0 | T_EVEX, 0x21, imm); UNIMPLEMENTED; }
void vlddqu(const Xmm& x, const Address& addr) { opAVX_X_X_XM(x, cvtIdx0(x), addr, T_0F | T_F2 | T_W0 | T_YMM, 0xF0); UNIMPLEMENTED; }
void vldmxcsr(const Address& addr) { opAVX_X_X_XM(xm2, xm0, addr, T_0F, 0xAE); UNIMPLEMENTED; }
void vmaskmovdqu(const Xmm& x1, const Xmm& x2) { opAVX_X_X_XM(x1, xm0, x2, T_0F | T_66, 0xF7); UNIMPLEMENTED; }
void vmaskmovpd(const Address& addr, const Xmm& x1, const Xmm& x2) { opAVX_X_X_XM(x2, x1, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x2F); UNIMPLEMENTED; }
void vmaskmovpd(const Xmm& x1, const Xmm& x2, const Address& addr) { opAVX_X_X_XM(x1, x2, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x2D); UNIMPLEMENTED; }
void vmaskmovps(const Address& addr, const Xmm& x1, const Xmm& x2) { opAVX_X_X_XM(x2, x1, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x2E); decodeAndTransToAArch64(); }
void vmaskmovps(const Xmm& x1, const Xmm& x2, const Address& addr) { opAVX_X_X_XM(x1, x2, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x2C); decodeAndTransToAArch64(); }
void vmaxpd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x5F); UNIMPLEMENTED; }
void vmaxps(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x5F); decodeAndTransToAArch64(); }
void vmaxsd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F2 | T_EW1 | T_EVEX | T_ER_Z | T_N8, 0x5F); UNIMPLEMENTED; }
void vmaxss(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F3 | T_EW0 | T_EVEX | T_ER_Z | T_N4, 0x5F); UNIMPLEMENTED; }
void vminpd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x5D); UNIMPLEMENTED; }
void vminps(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x5D); decodeAndTransToAArch64(); }
void vminsd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F2 | T_EW1 | T_EVEX | T_ER_Z | T_N8, 0x5D); UNIMPLEMENTED; }
void vminss(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F3 | T_EW0 | T_EVEX | T_ER_Z | T_N4, 0x5D); UNIMPLEMENTED; }
void vmovapd(const Address& addr, const Xmm& xmm) { opAVX_X_XM_IMM(xmm, addr, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_M_K, 0x29); UNIMPLEMENTED; }
void vmovapd(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX, 0x28); UNIMPLEMENTED; }
void vmovaps(const Address& addr, const Xmm& xmm) { opAVX_X_XM_IMM(xmm, addr, T_0F | T_EW0 | T_YMM | T_EVEX | T_M_K, 0x29); UNIMPLEMENTED; }
void vmovaps(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_0F | T_EW0 | T_YMM | T_EVEX, 0x28); decodeAndTransToAArch64(); }
void vmovd(const Operand& op, const Xmm& x) { if (!op.isREG(32) && !op.isMEM()) throw Error(ERR_BAD_COMBINATION); opAVX_X_X_XM(x, xm0, op, T_0F | T_66 | T_W0 | T_EVEX | T_N4, 0x7E); decodeAndTransToAArch64(); }
void vmovd(const Xmm& x, const Operand& op) { if (!op.isREG(32) && !op.isMEM()) throw Error(ERR_BAD_COMBINATION); opAVX_X_X_XM(x, xm0, op, T_0F | T_66 | T_W0 | T_EVEX | T_N4, 0x6E); decodeAndTransToAArch64(); }
void vmovddup(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_DUP | T_F2 | T_0F | T_EW1 | T_YMM | T_EVEX | T_ER_X | T_ER_Y | T_ER_Z, 0x12); UNIMPLEMENTED; }
void vmovdqa(const Address& addr, const Xmm& xmm) { opAVX_X_XM_IMM(xmm, addr, T_66 | T_0F | T_YMM, 0x7F); UNIMPLEMENTED; }
void vmovdqa(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F | T_YMM, 0x6F); UNIMPLEMENTED; }
void vmovdqu(const Address& addr, const Xmm& xmm) { opAVX_X_XM_IMM(xmm, addr, T_F3 | T_0F | T_YMM, 0x7F); decodeAndTransToAArch64(); }
void vmovdqu(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_F3 | T_0F | T_YMM, 0x6F); decodeAndTransToAArch64(); }
void vmovhlps(const Xmm& x1, const Xmm& x2, const Operand& op = Operand()) { if (!op.isNone() && !op.isXMM()) throw Error(ERR_BAD_COMBINATION); opAVX_X_X_XM(x1, x2, op, T_0F | T_EVEX | T_EW0, 0x12); decodeAndTransToAArch64(); }
void vmovhpd(const Address& addr, const Xmm& x) { opAVX_X_X_XM(x, xm0, addr, T_0F | T_66 | T_EVEX | T_EW1 | T_N8, 0x17); UNIMPLEMENTED; }
void vmovhpd(const Xmm& x, const Operand& op1, const Operand& op2 = Operand()) { if (!op2.isNone() && !op2.isMEM()) throw Error(ERR_BAD_COMBINATION); opAVX_X_X_XM(x, op1, op2, T_0F | T_66 | T_EVEX | T_EW1 | T_N8, 0x16); UNIMPLEMENTED; }
void vmovhps(const Address& addr, const Xmm& x) { opAVX_X_X_XM(x, xm0, addr, T_0F | T_EVEX | T_EW0 | T_N8, 0x17); decodeAndTransToAArch64(); }
void vmovhps(const Xmm& x, const Operand& op1, const Operand& op2 = Operand()) { if (!op2.isNone() && !op2.isMEM()) throw Error(ERR_BAD_COMBINATION); opAVX_X_X_XM(x, op1, op2, T_0F | T_EVEX | T_EW0 | T_N8, 0x16); decodeAndTransToAArch64(); }
void vmovlhps(const Xmm& x1, const Xmm& x2, const Operand& op = Operand()) { if (!op.isNone() && !op.isXMM()) throw Error(ERR_BAD_COMBINATION); opAVX_X_X_XM(x1, x2, op, T_0F | T_EVEX | T_EW0, 0x16); UNIMPLEMENTED; }
void vmovlpd(const Address& addr, const Xmm& x) { opAVX_X_X_XM(x, xm0, addr, T_0F | T_66 | T_EVEX | T_EW1 | T_N8, 0x13); UNIMPLEMENTED; }
void vmovlpd(const Xmm& x, const Operand& op1, const Operand& op2 = Operand()) { if (!op2.isNone() && !op2.isMEM()) throw Error(ERR_BAD_COMBINATION); opAVX_X_X_XM(x, op1, op2, T_0F | T_66 | T_EVEX | T_EW1 | T_N8, 0x12); UNIMPLEMENTED; }
void vmovlps(const Address& addr, const Xmm& x) { opAVX_X_X_XM(x, xm0, addr, T_0F | T_EVEX | T_EW0 | T_N8, 0x13); decodeAndTransToAArch64(); }
void vmovlps(const Xmm& x, const Operand& op1, const Operand& op2 = Operand()) { if (!op2.isNone() && !op2.isMEM()) throw Error(ERR_BAD_COMBINATION); opAVX_X_X_XM(x, op1, op2, T_0F | T_EVEX | T_EW0 | T_N8, 0x12); decodeAndTransToAArch64(); }
void vmovmskpd(const Reg& r, const Xmm& x) { if (!r.isBit(i32e)) throw Error(ERR_BAD_COMBINATION); opAVX_X_X_XM(x.isXMM() ? Xmm(r.getIdx()) : Ymm(r.getIdx()), cvtIdx0(x), x, T_0F | T_66 | T_W0 | T_YMM, 0x50); UNIMPLEMENTED; }
void vmovmskps(const Reg& r, const Xmm& x) { if (!r.isBit(i32e)) throw Error(ERR_BAD_COMBINATION); opAVX_X_X_XM(x.isXMM() ? Xmm(r.getIdx()) : Ymm(r.getIdx()), cvtIdx0(x), x, T_0F | T_W0 | T_YMM, 0x50); UNIMPLEMENTED; }
void vmovntdq(const Address& addr, const Xmm& x) { opVex(x, 0, addr, T_0F | T_66 | T_YMM | T_EVEX | T_EW0, 0xE7); UNIMPLEMENTED; }
void vmovntdqa(const Xmm& x, const Address& addr) { opVex(x, 0, addr, T_0F38 | T_66 | T_YMM | T_EVEX | T_EW0, 0x2A); UNIMPLEMENTED; }
void vmovntpd(const Address& addr, const Xmm& x) { opVex(x, 0, addr, T_0F | T_66 | T_YMM | T_EVEX | T_EW1, 0x2B); UNIMPLEMENTED; }
void vmovntps(const Address& addr, const Xmm& x) { opVex(x, 0, addr, T_0F | T_YMM | T_EVEX | T_EW0, 0x2B); decodeAndTransToAArch64(); }
void vmovq(const Address& addr, const Xmm& x) { opAVX_X_X_XM(x, xm0, addr, T_0F | T_66 | T_EVEX | T_EW1 | T_N8, x.getIdx() < 16 ? 0xD6 : 0x7E); decodeAndTransToAArch64(); }
void vmovq(const Xmm& x, const Address& addr) { int type, code; if (x.getIdx() < 16) { type = T_0F | T_F3; code = 0x7E; /*decodeAndTransToAArch64();*/ } else { type = T_0F | T_66 | T_EVEX | T_EW1 | T_N8; code = 0x6E; /*UNIMPLEMENTED;*/ } opAVX_X_X_XM(x, xm0, addr, type, code); decodeAndTransToAArch64(); }
void vmovq(const Xmm& x1, const Xmm& x2) { opAVX_X_X_XM(x1, xm0, x2, T_0F | T_F3 | T_EVEX | T_EW1 | T_N8, 0x7E); decodeAndTransToAArch64(); }
void vmovsd(const Address& addr, const Xmm& x) { opAVX_X_X_XM(x, xm0, addr, T_N8 | T_F2 | T_0F | T_EW1 | T_EVEX | T_M_K, 0x11); decodeAndTransToAArch64(); }
void vmovsd(const Xmm& x, const Address& addr) { opAVX_X_X_XM(x, xm0, addr, T_N8 | T_F2 | T_0F | T_EW1 | T_EVEX, 0x10); decodeAndTransToAArch64(); }
void vmovsd(const Xmm& x1, const Xmm& x2, const Operand& op = Operand()) { if (!op.isNone() && !op.isXMM()) throw Error(ERR_BAD_COMBINATION); opAVX_X_X_XM(x1, x2, op, T_N8 | T_F2 | T_0F | T_EW1 | T_EVEX, 0x10); decodeAndTransToAArch64(); }
void vmovshdup(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_F3 | T_0F | T_EW0 | T_YMM | T_EVEX, 0x16); UNIMPLEMENTED; }
void vmovsldup(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_F3 | T_0F | T_EW0 | T_YMM | T_EVEX, 0x12); UNIMPLEMENTED; }
void vmovss(const Address& addr, const Xmm& x) { opAVX_X_X_XM(x, xm0, addr, T_N4 | T_F3 | T_0F | T_EW0 | T_EVEX | T_M_K, 0x11); decodeAndTransToAArch64(); }
void vmovss(const Xmm& x, const Address& addr) { opAVX_X_X_XM(x, xm0, addr, T_N4 | T_F3 | T_0F | T_EW0 | T_EVEX, 0x10); decodeAndTransToAArch64(); }
void vmovss(const Xmm& x1, const Xmm& x2, const Operand& op = Operand()) { if (!op.isNone() && !op.isXMM()) throw Error(ERR_BAD_COMBINATION); opAVX_X_X_XM(x1, x2, op, T_N4 | T_F3 | T_0F | T_EW0 | T_EVEX, 0x10); decodeAndTransToAArch64(); }
void vmovupd(const Address& addr, const Xmm& xmm) { opAVX_X_XM_IMM(xmm, addr, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_M_K, 0x11); UNIMPLEMENTED; }
void vmovupd(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX, 0x10); UNIMPLEMENTED; }
void vmovups(const Address& addr, const Xmm& xmm) { opAVX_X_XM_IMM(xmm, addr, T_0F | T_EW0 | T_YMM | T_EVEX | T_M_K, 0x11); decodeAndTransToAArch64(); }
void vmovups(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_0F | T_EW0 | T_YMM | T_EVEX, 0x10); decodeAndTransToAArch64(); }
void vmpsadbw(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0 | T_YMM, 0x42, imm); UNIMPLEMENTED; }
void vmulpd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x59); UNIMPLEMENTED; }
void vmulps(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x59); decodeAndTransToAArch64(); }
void vmulsd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F2 | T_EW1 | T_EVEX | T_ER_Z | T_N8, 0x59); UNIMPLEMENTED; }
void vmulss(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F3 | T_EW0 | T_EVEX | T_ER_Z | T_N4, 0x59); UNIMPLEMENTED; }
void vorpd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x56); UNIMPLEMENTED; }
void vorps(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x56); decodeAndTransToAArch64(); }
void vpabsb(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x1C); UNIMPLEMENTED; }
void vpabsd(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x1E); UNIMPLEMENTED; }
void vpabsw(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x1D); UNIMPLEMENTED; }
void vpackssdw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0x6B); UNIMPLEMENTED; }
void vpacksswb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0x63); UNIMPLEMENTED; }
void vpackusdw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x2B); UNIMPLEMENTED; }
void vpackuswb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0x67); UNIMPLEMENTED; }
void vpaddb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xFC); decodeAndTransToAArch64(); }
void vpaddd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0xFE); decodeAndTransToAArch64(); }
void vpaddq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0xD4); decodeAndTransToAArch64(); }
void vpaddsb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xEC); UNIMPLEMENTED; }
void vpaddsw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xED); UNIMPLEMENTED; }
void vpaddusb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xDC); UNIMPLEMENTED; }
void vpaddusw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xDD); UNIMPLEMENTED; }
void vpaddw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xFD); UNIMPLEMENTED; }
void vpalignr(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_YMM | T_EVEX, 0x0F, imm); UNIMPLEMENTED; }
void vpand(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0xDB); UNIMPLEMENTED; }
void vpandn(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0xDF); UNIMPLEMENTED; }
void vpavgb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xE0); UNIMPLEMENTED; }
void vpavgw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xE3); UNIMPLEMENTED; }
void vpblendd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0 | T_YMM, 0x02, imm); UNIMPLEMENTED; }
void vpblendvb(const Xmm& x1, const Xmm& x2, const Operand& op, const Xmm& x4) { opAVX_X_X_XM(x1, x2, op, T_0F3A | T_66 | T_YMM, 0x4C, x4.getIdx() << 4); UNIMPLEMENTED; }
void vpblendw(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0 | T_YMM, 0x0E, imm); UNIMPLEMENTED; }
void vpbroadcastb(const Xmm& x, const Operand& op) { if (!(op.isXMM() || op.isMEM())) throw Error(ERR_BAD_COMBINATION); opAVX_X_XM_IMM(x, op, T_N1 | T_66 | T_0F38 | T_W0 | T_YMM | T_EVEX, 0x78); decodeAndTransToAArch64(); }
void vpbroadcastd(const Xmm& x, const Operand& op) { if (!(op.isXMM() || op.isMEM())) throw Error(ERR_BAD_COMBINATION); opAVX_X_XM_IMM(x, op, T_N4 | T_66 | T_0F38 | T_W0 | T_YMM | T_EVEX, 0x58); decodeAndTransToAArch64(); }
void vpbroadcastq(const Xmm& x, const Operand& op) { if (!(op.isXMM() || op.isMEM())) throw Error(ERR_BAD_COMBINATION); opAVX_X_XM_IMM(x, op, T_N8 | T_66 | T_0F38 | T_W0 | T_EW1 | T_YMM | T_EVEX, 0x59); decodeAndTransToAArch64(); }
void vpbroadcastw(const Xmm& x, const Operand& op) { if (!(op.isXMM() || op.isMEM())) throw Error(ERR_BAD_COMBINATION); opAVX_X_XM_IMM(x, op, T_N2 | T_66 | T_0F38 | T_W0 | T_YMM | T_EVEX, 0x79); decodeAndTransToAArch64(); }
void vpclmulqdq(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0 | T_YMM | T_EVEX, 0x44, imm); UNIMPLEMENTED; }
void vpcmpeqb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0x74); decodeAndTransToAArch64(); }
void vpcmpeqd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0x76); decodeAndTransToAArch64(); }
void vpcmpeqq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x29); UNIMPLEMENTED; }
void vpcmpeqw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0x75); UNIMPLEMENTED; }
void vpcmpestri(const Xmm& xm, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A, 0x61, imm); UNIMPLEMENTED; }
void vpcmpestrm(const Xmm& xm, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A, 0x60, imm); UNIMPLEMENTED; }
void vpcmpgtb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0x64); UNIMPLEMENTED; }
void vpcmpgtd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0x66); UNIMPLEMENTED; }
void vpcmpgtq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x37); UNIMPLEMENTED; }
void vpcmpgtw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0x65); UNIMPLEMENTED; }
void vpcmpistri(const Xmm& xm, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A, 0x63, imm); UNIMPLEMENTED; }
void vpcmpistrm(const Xmm& xm, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A, 0x62, imm); UNIMPLEMENTED; }
void vperm2f128(const Ymm& y1, const Ymm& y2, const Operand& op, uint8 imm) { if (!(y1.isYMM() && y2.isYMM() && op.isYMEM())) throw Error(ERR_BAD_COMBINATION); opVex(y1, &y2, op, T_0F3A | T_66 | T_W0 | T_YMM, 0x06, imm); decodeAndTransToAArch64(); }
void vperm2i128(const Ymm& y1, const Ymm& y2, const Operand& op, uint8 imm) { if (!(y1.isYMM() && y2.isYMM() && op.isYMEM())) throw Error(ERR_BAD_COMBINATION); opVex(y1, &y2, op, T_0F3A | T_66 | T_W0 | T_YMM, 0x46, imm); decodeAndTransToAArch64(); }
void vpermd(const Ymm& y1, const Ymm& y2, const Operand& op) { opAVX_X_X_XM(y1, y2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x36); decodeAndTransToAArch64(); }
void vpermilpd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x0D); UNIMPLEMENTED; }
void vpermilpd(const Xmm& xm, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_EVEX | T_B64, 0x05, imm); UNIMPLEMENTED; }
void vpermilps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x0C); UNIMPLEMENTED; }
void vpermilps(const Xmm& xm, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_EVEX | T_B32, 0x04, imm); UNIMPLEMENTED; }
void vpermpd(const Ymm& y, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(y, op, T_66 | T_0F3A | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x01, imm); UNIMPLEMENTED; }
void vpermpd(const Ymm& y1, const Ymm& y2, const Operand& op) { opAVX_X_X_XM(y1, y2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x16); UNIMPLEMENTED; }
void vpermps(const Ymm& y1, const Ymm& y2, const Operand& op) { opAVX_X_X_XM(y1, y2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x16); UNIMPLEMENTED; }
void vpermq(const Ymm& y, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(y, op, T_66 | T_0F3A | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x00, imm); UNIMPLEMENTED; }
void vpermq(const Ymm& y1, const Ymm& y2, const Operand& op) { opAVX_X_X_XM(y1, y2, op, T_66 | T_0F38 | T_W0 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x36); UNIMPLEMENTED; }
void vpextrb(const Operand& op, const Xmm& x, uint8 imm) { if (!((op.isREG(8|16|i32e) || op.isMEM()) && x.isXMM())) throw Error(ERR_BAD_COMBINATION); opVex(x, 0, op, T_0F3A | T_66 | T_EVEX | T_N1, 0x14, imm); decodeAndTransToAArch64(); }
void vpextrd(const Operand& op, const Xmm& x, uint8 imm) { if (!((op.isREG(32) || op.isMEM()) && x.isXMM())) throw Error(ERR_BAD_COMBINATION); opVex(x, 0, op, T_0F3A | T_66 | T_W0 | T_EVEX | T_EW0 | T_N4, 0x16, imm); UNIMPLEMENTED; }
void vpextrq(const Operand& op, const Xmm& x, uint8 imm) { if (!((op.isREG(64) || op.isMEM()) && x.isXMM())) throw Error(ERR_BAD_COMBINATION); opVex(x, 0, op, T_0F3A | T_66 | T_W1 | T_EVEX | T_EW1 | T_N8, 0x16, imm); UNIMPLEMENTED; }
void vpextrw(const Operand& op, const Xmm& x, uint8 imm) { if (!((op.isREG(16|i32e) || op.isMEM()) && x.isXMM())) throw Error(ERR_BAD_COMBINATION); if (op.isREG() && x.getIdx() < 16) { opAVX_X_X_XM(Xmm(op.getIdx()), xm0, x, T_0F | T_66, 0xC5, imm); UNIMPLEMENTED; } else { opVex(x, 0, op, T_0F3A | T_66 | T_EVEX | T_N2, 0x15, imm); UNIMPLEMENTED; } UNIMPLEMENTED; }
void vpgatherdd(const Xmm& x1, const Address& addr, const Xmm& x2) { opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W0, 0x90, 1); UNIMPLEMENTED; }
void vpgatherdq(const Xmm& x1, const Address& addr, const Xmm& x2) { opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W1, 0x90, 0); UNIMPLEMENTED; }
void vpgatherqd(const Xmm& x1, const Address& addr, const Xmm& x2) { opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W0, 0x91, 2); UNIMPLEMENTED; }
void vpgatherqq(const Xmm& x1, const Address& addr, const Xmm& x2) { opGather(x1, addr, x2, T_0F38 | T_66 | T_YMM | T_VSIB | T_W1, 0x91, 1); UNIMPLEMENTED; }
void vphaddd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x02); decodeAndTransToAArch64(); }
void vphaddsw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x03); UNIMPLEMENTED; }
void vphaddw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x01); decodeAndTransToAArch64(); }
void vphminposuw(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F38, 0x41); UNIMPLEMENTED; }
void vphsubd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x06); UNIMPLEMENTED; }
void vphsubsw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x07); UNIMPLEMENTED; }
void vphsubw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x05); UNIMPLEMENTED; }
void vpinsrb(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { if (!(x1.isXMM() && x2.isXMM() && (op.isREG(32) || op.isMEM()))) throw Error(ERR_BAD_COMBINATION); opVex(x1, &x2, op, T_0F3A | T_66 | T_EVEX | T_N1, 0x20, imm); decodeAndTransToAArch64(); }
void vpinsrd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { if (!(x1.isXMM() && x2.isXMM() && (op.isREG(32) || op.isMEM()))) throw Error(ERR_BAD_COMBINATION); opVex(x1, &x2, op, T_0F3A | T_66 | T_W0 | T_EVEX | T_EW0 | T_N4, 0x22, imm); UNIMPLEMENTED; }
void vpinsrq(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { if (!(x1.isXMM() && x2.isXMM() && (op.isREG(64) || op.isMEM()))) throw Error(ERR_BAD_COMBINATION); opVex(x1, &x2, op, T_0F3A | T_66 | T_W1 | T_EVEX | T_EW1 | T_N8, 0x22, imm); decodeAndTransToAArch64(); }
void vpinsrw(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { if (!(x1.isXMM() && x2.isXMM() && (op.isREG(32) || op.isMEM()))) throw Error(ERR_BAD_COMBINATION); opVex(x1, &x2, op, T_0F | T_66 | T_EVEX | T_N2, 0xC4, imm); decodeAndTransToAArch64(); }
void vpmaddubsw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x04); UNIMPLEMENTED; }
void vpmaddwd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xF5); UNIMPLEMENTED; }
void vpmaskmovd(const Address& addr, const Xmm& x1, const Xmm& x2) { opAVX_X_X_XM(x2, x1, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x8E); UNIMPLEMENTED; }
void vpmaskmovd(const Xmm& x1, const Xmm& x2, const Address& addr) { opAVX_X_X_XM(x1, x2, addr, T_0F38 | T_66 | T_W0 | T_YMM, 0x8C); UNIMPLEMENTED; }
void vpmaskmovq(const Address& addr, const Xmm& x1, const Xmm& x2) { opAVX_X_X_XM(x2, x1, addr, T_0F38 | T_66 | T_W1 | T_YMM, 0x8E); UNIMPLEMENTED; }
void vpmaskmovq(const Xmm& x1, const Xmm& x2, const Address& addr) { opAVX_X_X_XM(x1, x2, addr, T_0F38 | T_66 | T_W1 | T_YMM, 0x8C); UNIMPLEMENTED; }
void vpmaxsb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x3C); UNIMPLEMENTED; }
void vpmaxsd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x3D); decodeAndTransToAArch64(); }
void vpmaxsw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xEE); UNIMPLEMENTED; }
void vpmaxub(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xDE); UNIMPLEMENTED; }
void vpmaxud(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x3F); UNIMPLEMENTED; }
void vpmaxuw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x3E); UNIMPLEMENTED; }
void vpminsb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x38); UNIMPLEMENTED; }
void vpminsd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x39); UNIMPLEMENTED; }
void vpminsw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xEA); UNIMPLEMENTED; }
void vpminub(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xDA); UNIMPLEMENTED; }
void vpminud(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x3B); UNIMPLEMENTED; }
void vpminuw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x3A); UNIMPLEMENTED; }
void vpmovmskb(const Reg32e& r, const Xmm& x) { if (!x.is(Operand::XMM | Operand::YMM)) throw Error(ERR_BAD_COMBINATION); opVex(x.isYMM() ? Ymm(r.getIdx()) : Xmm(r.getIdx()), 0, x, T_0F | T_66 | T_YMM, 0xD7); UNIMPLEMENTED; }
void vpmovsxbd(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N4 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x21); decodeAndTransToAArch64(); }
void vpmovsxbq(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N2 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x22); UNIMPLEMENTED; }
void vpmovsxbw(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N8 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x20); decodeAndTransToAArch64(); }
void vpmovsxdq(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N8 | T_N_VL | T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX, 0x25); UNIMPLEMENTED; }
void vpmovsxwd(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N8 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x23); decodeAndTransToAArch64(); }
void vpmovsxwq(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N4 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x24); UNIMPLEMENTED; }
void vpmovzxbd(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N4 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x31); decodeAndTransToAArch64(); }
void vpmovzxbq(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N2 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x32); UNIMPLEMENTED; }
void vpmovzxbw(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N8 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x30); UNIMPLEMENTED; }
void vpmovzxdq(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N8 | T_N_VL | T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX, 0x35); UNIMPLEMENTED; }
void vpmovzxwd(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N8 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x33); decodeAndTransToAArch64(); }
void vpmovzxwq(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N4 | T_N_VL | T_66 | T_0F38 | T_YMM | T_EVEX, 0x34); UNIMPLEMENTED; }
void vpmuldq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x28); UNIMPLEMENTED; }
void vpmulhrsw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x0B); UNIMPLEMENTED; }
void vpmulhuw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xE4); UNIMPLEMENTED; }
void vpmulhw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xE5); UNIMPLEMENTED; }
void vpmulld(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x40); UNIMPLEMENTED; }
void vpmullw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xD5); UNIMPLEMENTED; }
void vpmuludq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0xF4); UNIMPLEMENTED; }
void vpor(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0xEB); UNIMPLEMENTED; }
void vpsadbw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xF6); UNIMPLEMENTED; }
void vpshufb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM | T_EVEX, 0x00); decodeAndTransToAArch64(); }
void vpshufd(const Xmm& xm, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0x70, imm); decodeAndTransToAArch64(); }
void vpshufhw(const Xmm& xm, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(xm, op, T_F3 | T_0F | T_YMM | T_EVEX, 0x70, imm); UNIMPLEMENTED; }
void vpshuflw(const Xmm& xm, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(xm, op, T_F2 | T_0F | T_YMM | T_EVEX, 0x70, imm); UNIMPLEMENTED; }
void vpsignb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x08); UNIMPLEMENTED; }
void vpsignd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x0A); UNIMPLEMENTED; }
void vpsignw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_YMM, 0x09); UNIMPLEMENTED; }
void vpslld(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 6), x, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32 | T_MEM_EVEX, 0x72, imm); decodeAndTransToAArch64(); }
void vpslld(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_EW0 | T_YMM | T_EVEX, 0xF2); UNIMPLEMENTED; }
void vpslldq(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 7), x, op, T_66 | T_0F | T_YMM | T_EVEX | T_MEM_EVEX, 0x73, imm); UNIMPLEMENTED; }
void vpsllq(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 6), x, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64 | T_MEM_EVEX, 0x73, imm); UNIMPLEMENTED; }
void vpsllq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_EW1 | T_YMM | T_EVEX, 0xF3); UNIMPLEMENTED; }
void vpsllvd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x47); UNIMPLEMENTED; }
void vpsllvq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x47); UNIMPLEMENTED; }
void vpsllw(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 6), x, op, T_66 | T_0F | T_YMM | T_EVEX | T_MEM_EVEX, 0x71, imm); UNIMPLEMENTED; }
void vpsllw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_YMM | T_EVEX, 0xF1); UNIMPLEMENTED; }
void vpsrad(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 4), x, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32 | T_MEM_EVEX, 0x72, imm); decodeAndTransToAArch64(); }
void vpsrad(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_EW0 | T_YMM | T_EVEX, 0xE2); decodeAndTransToAArch64(); }
void vpsravd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x46); UNIMPLEMENTED; }
void vpsraw(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 4), x, op, T_66 | T_0F | T_YMM | T_EVEX | T_MEM_EVEX, 0x71, imm); UNIMPLEMENTED; }
void vpsraw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_YMM | T_EVEX, 0xE1); UNIMPLEMENTED; }
void vpsrld(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 2), x, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32 | T_MEM_EVEX, 0x72, imm); decodeAndTransToAArch64(); }
void vpsrld(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_EW0 | T_YMM | T_EVEX, 0xD2); UNIMPLEMENTED; }
void vpsrldq(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 3), x, op, T_66 | T_0F | T_YMM | T_EVEX | T_MEM_EVEX, 0x73, imm); UNIMPLEMENTED; }
void vpsrlq(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 2), x, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64 | T_MEM_EVEX, 0x73, imm); UNIMPLEMENTED; }
void vpsrlq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_EW1 | T_YMM | T_EVEX, 0xD3); UNIMPLEMENTED; }
void vpsrlvd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W0 | T_EW0 | T_YMM | T_EVEX | T_B32, 0x45); UNIMPLEMENTED; }
void vpsrlvq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_W1 | T_EW1 | T_YMM | T_EVEX | T_B64, 0x45); UNIMPLEMENTED; }
void vpsrlw(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 2), x, op, T_66 | T_0F | T_YMM | T_EVEX | T_MEM_EVEX, 0x71, imm); UNIMPLEMENTED; }
void vpsrlw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_YMM | T_EVEX, 0xD1); UNIMPLEMENTED; }
void vpsubb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xF8); UNIMPLEMENTED; }
void vpsubd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0xFA); UNIMPLEMENTED; }
void vpsubq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0xFB); UNIMPLEMENTED; }
void vpsubsb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xE8); UNIMPLEMENTED; }
void vpsubsw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xE9); UNIMPLEMENTED; }
void vpsubusb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xD8); UNIMPLEMENTED; }
void vpsubusw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xD9); UNIMPLEMENTED; }
void vpsubw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0xF9); UNIMPLEMENTED; }
void vptest(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F38 | T_YMM, 0x17); UNIMPLEMENTED; }
void vpunpckhbw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0x68); decodeAndTransToAArch64(); }
void vpunpckhdq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0x6A); UNIMPLEMENTED; }
void vpunpckhqdq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0x6D); decodeAndTransToAArch64(); }
void vpunpckhwd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0x69); decodeAndTransToAArch64(); }
void vpunpcklbw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0x60); decodeAndTransToAArch64(); }
void vpunpckldq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0x62); decodeAndTransToAArch64(); }
void vpunpcklqdq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0x6C); decodeAndTransToAArch64(); }
void vpunpcklwd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM | T_EVEX, 0x61); decodeAndTransToAArch64(); }
void vpxor(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_YMM, 0xEF); decodeAndTransToAArch64(); }
void vrcpps(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_0F | T_YMM, 0x53); UNIMPLEMENTED; }
void vrcpss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_F3 | T_0F, 0x53); UNIMPLEMENTED; }
void vroundpd(const Xmm& xm, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A | T_YMM, 0x09, imm); UNIMPLEMENTED; }
void vroundps(const Xmm& xm, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F3A | T_YMM, 0x08, imm); UNIMPLEMENTED; }
void vroundsd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0, 0x0B, imm); UNIMPLEMENTED; }
void vroundss(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_W0, 0x0A, imm); UNIMPLEMENTED; }
void vrsqrtps(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_0F | T_YMM, 0x52); UNIMPLEMENTED; }
void vrsqrtss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_F3 | T_0F, 0x52); UNIMPLEMENTED; }
void vshufpd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0xC6, imm); decodeAndTransToAArch64(); }
void vshufps(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0xC6, imm); decodeAndTransToAArch64() ; }
void vsqrtpd(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x51); UNIMPLEMENTED; }
void vsqrtps(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x51); decodeAndTransToAArch64(); }
void vsqrtsd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_F2 | T_0F | T_EW1 | T_EVEX | T_ER_X, 0x51); UNIMPLEMENTED; }
void vsqrtss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_F3 | T_0F | T_EW0 | T_EVEX | T_ER_X, 0x51); UNIMPLEMENTED; }
void vstmxcsr(const Address& addr) { opAVX_X_X_XM(xm3, xm0, addr, T_0F, 0xAE); UNIMPLEMENTED; }
void vsubpd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x5C); UNIMPLEMENTED; }
void vsubps(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x5C); decodeAndTransToAArch64(); }
void vsubsd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F2 | T_EW1 | T_EVEX | T_ER_Z | T_N8, 0x5C); UNIMPLEMENTED; }
void vsubss(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_F3 | T_EW0 | T_EVEX | T_ER_Z | T_N4, 0x5C); UNIMPLEMENTED; }
void vtestpd(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F38 | T_YMM, 0x0F); UNIMPLEMENTED; }
void vtestps(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_66 | T_0F38 | T_YMM, 0x0E); UNIMPLEMENTED; }
void vucomisd(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N8 | T_66 | T_0F | T_EW1 | T_EVEX | T_SAE_X, 0x2E); UNIMPLEMENTED; }
void vucomiss(const Xmm& xm, const Operand& op) { opAVX_X_XM_IMM(xm, op, T_N4 | T_0F | T_EW0 | T_EVEX | T_SAE_X, 0x2E); UNIMPLEMENTED; }
void vunpckhpd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0x15); decodeAndTransToAArch64(); }
void vunpckhps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0x15); decodeAndTransToAArch64(); }
void vunpcklpd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_EVEX | T_B64, 0x14); decodeAndTransToAArch64(); }
void vunpcklps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_0F | T_EW0 | T_YMM | T_EVEX | T_B32, 0x14); decodeAndTransToAArch64(); }
void vxorpd(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_66 | T_EW1 | T_YMM | T_EVEX | T_ER_Z | T_B64, 0x57); UNIMPLEMENTED; }
void vxorps(const Xmm& xmm, const Operand& op1, const Operand& op2 = Operand()) { opAVX_X_X_XM(xmm, op1, op2, T_0F | T_EW0 | T_YMM | T_EVEX | T_ER_Z | T_B32, 0x57); decodeAndTransToAArch64(); }
void vzeroall() { db(0xC5); db(0xFC); db(0x77); UNIMPLEMENTED; }
void vzeroupper() { db(0xC5); db(0xF8); db(0x77); decodeAndTransToAArch64(); }
void wait() { db(0x9B); UNIMPLEMENTED; }
void wbinvd() { db(0x0F); db(0x09); UNIMPLEMENTED; }
void wrmsr() { db(0x0F); db(0x30); UNIMPLEMENTED; }
void xadd(const Operand& op, const Reg& reg) { opModRM(reg, op, (op.isREG() && reg.isREG() && op.getBit() == reg.getBit()), op.isMEM(), 0x0F, 0xC0 | (reg.isBit(8) ? 0 : 1)); decodeAndTransToAArch64(); }
void xgetbv() { db(0x0F); db(0x01); db(0xD0); UNIMPLEMENTED; }
void xlatb() { db(0xD7); UNIMPLEMENTED; }
void xor_(const Operand& op, uint32 imm) { opRM_I(op, imm, 0x30, 6); decodeAndTransToAArch64(); }
void xor_(const Operand& op1, const Operand& op2) { opRM_RM(op1, op2, 0x30); decodeAndTransToAArch64(); }
void xorpd(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x57, 0x66, isXMM_XMMorMEM); UNIMPLEMENTED; }
void xorps(const Xmm& xmm, const Operand& op) { opGen(xmm, op, 0x57, 0x100, isXMM_XMMorMEM); UNIMPLEMENTED; }
#ifdef XBYAK_ENABLE_OMITTED_OPERAND
void vblendpd(const Xmm& x, const Operand& op, uint8 imm) { vblendpd(x, x, op, imm); UNIMPLEMENTED; }
void vblendps(const Xmm& x, const Operand& op, uint8 imm) { vblendps(x, x, op, imm); UNIMPLEMENTED; }
void vblendvpd(const Xmm& x1, const Operand& op, const Xmm& x4) { vblendvpd(x1, x1, op, x4); UNIMPLEMENTED; }
void vblendvps(const Xmm& x1, const Operand& op, const Xmm& x4) { vblendvps(x1, x1, op, x4); /*decodeAndTransToAArch64();*/ }
void vcmpeq_ospd(const Xmm& x, const Operand& op) { vcmpeq_ospd(x, x, op); UNIMPLEMENTED; }
void vcmpeq_osps(const Xmm& x, const Operand& op) { vcmpeq_osps(x, x, op); decodeAndTransToAArch64(); }
void vcmpeq_ossd(const Xmm& x, const Operand& op) { vcmpeq_ossd(x, x, op); UNIMPLEMENTED; }
void vcmpeq_osss(const Xmm& x, const Operand& op) { vcmpeq_osss(x, x, op); UNIMPLEMENTED; }
void vcmpeq_uqpd(const Xmm& x, const Operand& op) { vcmpeq_uqpd(x, x, op); UNIMPLEMENTED; }
void vcmpeq_uqps(const Xmm& x, const Operand& op) { vcmpeq_uqps(x, x, op); decodeAndTransToAArch64(); }
void vcmpeq_uqsd(const Xmm& x, const Operand& op) { vcmpeq_uqsd(x, x, op); UNIMPLEMENTED; }
void vcmpeq_uqss(const Xmm& x, const Operand& op) { vcmpeq_uqss(x, x, op); UNIMPLEMENTED; }
void vcmpeq_uspd(const Xmm& x, const Operand& op) { vcmpeq_uspd(x, x, op); UNIMPLEMENTED; }
void vcmpeq_usps(const Xmm& x, const Operand& op) { vcmpeq_usps(x, x, op); decodeAndTransToAArch64(); }
void vcmpeq_ussd(const Xmm& x, const Operand& op) { vcmpeq_ussd(x, x, op); UNIMPLEMENTED; }
void vcmpeq_usss(const Xmm& x, const Operand& op) { vcmpeq_usss(x, x, op); UNIMPLEMENTED; }
void vcmpeqpd(const Xmm& x, const Operand& op) { vcmpeqpd(x, x, op); UNIMPLEMENTED; }
void vcmpeqps(const Xmm& x, const Operand& op) { vcmpeqps(x, x, op); decodeAndTransToAArch64(); }
void vcmpeqsd(const Xmm& x, const Operand& op) { vcmpeqsd(x, x, op); UNIMPLEMENTED; }
void vcmpeqss(const Xmm& x, const Operand& op) { vcmpeqss(x, x, op); UNIMPLEMENTED; }
void vcmpfalse_ospd(const Xmm& x, const Operand& op) { vcmpfalse_ospd(x, x, op); UNIMPLEMENTED; }
void vcmpfalse_osps(const Xmm& x, const Operand& op) { vcmpfalse_osps(x, x, op); decodeAndTransToAArch64(); }
void vcmpfalse_ossd(const Xmm& x, const Operand& op) { vcmpfalse_ossd(x, x, op); UNIMPLEMENTED; }
void vcmpfalse_osss(const Xmm& x, const Operand& op) { vcmpfalse_osss(x, x, op); UNIMPLEMENTED; }
void vcmpfalsepd(const Xmm& x, const Operand& op) { vcmpfalsepd(x, x, op); UNIMPLEMENTED; }
void vcmpfalseps(const Xmm& x, const Operand& op) { vcmpfalseps(x, x, op); decodeAndTransToAArch64(); }
void vcmpfalsesd(const Xmm& x, const Operand& op) { vcmpfalsesd(x, x, op); UNIMPLEMENTED; }
void vcmpfalsess(const Xmm& x, const Operand& op) { vcmpfalsess(x, x, op); UNIMPLEMENTED; }
void vcmpge_oqpd(const Xmm& x, const Operand& op) { vcmpge_oqpd(x, x, op); UNIMPLEMENTED; }
void vcmpge_oqps(const Xmm& x, const Operand& op) { vcmpge_oqps(x, x, op); decodeAndTransToAArch64(); }
void vcmpge_oqsd(const Xmm& x, const Operand& op) { vcmpge_oqsd(x, x, op); UNIMPLEMENTED; }
void vcmpge_oqss(const Xmm& x, const Operand& op) { vcmpge_oqss(x, x, op); UNIMPLEMENTED; }
void vcmpgepd(const Xmm& x, const Operand& op) { vcmpgepd(x, x, op); UNIMPLEMENTED; }
void vcmpgeps(const Xmm& x, const Operand& op) { vcmpgeps(x, x, op); decodeAndTransToAArch64(); }
void vcmpgesd(const Xmm& x, const Operand& op) { vcmpgesd(x, x, op); UNIMPLEMENTED; }
void vcmpgess(const Xmm& x, const Operand& op) { vcmpgess(x, x, op); UNIMPLEMENTED; }
void vcmpgt_oqpd(const Xmm& x, const Operand& op) { vcmpgt_oqpd(x, x, op); UNIMPLEMENTED; }
void vcmpgt_oqps(const Xmm& x, const Operand& op) { vcmpgt_oqps(x, x, op); decodeAndTransToAArch64(); }
void vcmpgt_oqsd(const Xmm& x, const Operand& op) { vcmpgt_oqsd(x, x, op); UNIMPLEMENTED; }
void vcmpgt_oqss(const Xmm& x, const Operand& op) { vcmpgt_oqss(x, x, op); UNIMPLEMENTED; }
void vcmpgtpd(const Xmm& x, const Operand& op) { vcmpgtpd(x, x, op); UNIMPLEMENTED; }
void vcmpgtps(const Xmm& x, const Operand& op) { vcmpgtps(x, x, op); decodeAndTransToAArch64(); }
void vcmpgtsd(const Xmm& x, const Operand& op) { vcmpgtsd(x, x, op); UNIMPLEMENTED; }
void vcmpgtss(const Xmm& x, const Operand& op) { vcmpgtss(x, x, op); UNIMPLEMENTED; }
void vcmple_oqpd(const Xmm& x, const Operand& op) { vcmple_oqpd(x, x, op); UNIMPLEMENTED; }
void vcmple_oqps(const Xmm& x, const Operand& op) { vcmple_oqps(x, x, op); decodeAndTransToAArch64(); }
void vcmple_oqsd(const Xmm& x, const Operand& op) { vcmple_oqsd(x, x, op); UNIMPLEMENTED; }
void vcmple_oqss(const Xmm& x, const Operand& op) { vcmple_oqss(x, x, op); UNIMPLEMENTED; }
void vcmplepd(const Xmm& x, const Operand& op) { vcmplepd(x, x, op); UNIMPLEMENTED; }
void vcmpleps(const Xmm& x, const Operand& op) { vcmpleps(x, x, op); decodeAndTransToAArch64(); }
void vcmplesd(const Xmm& x, const Operand& op) { vcmplesd(x, x, op); UNIMPLEMENTED; }
void vcmpless(const Xmm& x, const Operand& op) { vcmpless(x, x, op); UNIMPLEMENTED; }
void vcmplt_oqpd(const Xmm& x, const Operand& op) { vcmplt_oqpd(x, x, op); UNIMPLEMENTED; }
void vcmplt_oqps(const Xmm& x, const Operand& op) { vcmplt_oqps(x, x, op); decodeAndTransToAArch64(); }
void vcmplt_oqsd(const Xmm& x, const Operand& op) { vcmplt_oqsd(x, x, op); UNIMPLEMENTED; }
void vcmplt_oqss(const Xmm& x, const Operand& op) { vcmplt_oqss(x, x, op); UNIMPLEMENTED; }
void vcmpltpd(const Xmm& x, const Operand& op) { vcmpltpd(x, x, op); UNIMPLEMENTED; }
void vcmpltps(const Xmm& x, const Operand& op) { vcmpltps(x, x, op); decodeAndTransToAArch64(); }
void vcmpltsd(const Xmm& x, const Operand& op) { vcmpltsd(x, x, op); UNIMPLEMENTED; }
void vcmpltss(const Xmm& x, const Operand& op) { vcmpltss(x, x, op); UNIMPLEMENTED; }
void vcmpneq_oqpd(const Xmm& x, const Operand& op) { vcmpneq_oqpd(x, x, op); UNIMPLEMENTED; }
void vcmpneq_oqps(const Xmm& x, const Operand& op) { vcmpneq_oqps(x, x, op); decodeAndTransToAArch64(); }
void vcmpneq_oqsd(const Xmm& x, const Operand& op) { vcmpneq_oqsd(x, x, op); UNIMPLEMENTED; }
void vcmpneq_oqss(const Xmm& x, const Operand& op) { vcmpneq_oqss(x, x, op); UNIMPLEMENTED; }
void vcmpneq_ospd(const Xmm& x, const Operand& op) { vcmpneq_ospd(x, x, op); UNIMPLEMENTED; }
void vcmpneq_osps(const Xmm& x, const Operand& op) { vcmpneq_osps(x, x, op); decodeAndTransToAArch64(); }
void vcmpneq_ossd(const Xmm& x, const Operand& op) { vcmpneq_ossd(x, x, op); UNIMPLEMENTED; }
void vcmpneq_osss(const Xmm& x, const Operand& op) { vcmpneq_osss(x, x, op); UNIMPLEMENTED; }
void vcmpneq_uspd(const Xmm& x, const Operand& op) { vcmpneq_uspd(x, x, op); UNIMPLEMENTED; }
void vcmpneq_usps(const Xmm& x, const Operand& op) { vcmpneq_usps(x, x, op); decodeAndTransToAArch64(); }
void vcmpneq_ussd(const Xmm& x, const Operand& op) { vcmpneq_ussd(x, x, op); UNIMPLEMENTED; }
void vcmpneq_usss(const Xmm& x, const Operand& op) { vcmpneq_usss(x, x, op); UNIMPLEMENTED; }
void vcmpneqpd(const Xmm& x, const Operand& op) { vcmpneqpd(x, x, op); UNIMPLEMENTED; }
void vcmpneqps(const Xmm& x, const Operand& op) { vcmpneqps(x, x, op); decodeAndTransToAArch64(); }
void vcmpneqsd(const Xmm& x, const Operand& op) { vcmpneqsd(x, x, op); UNIMPLEMENTED; }
void vcmpneqss(const Xmm& x, const Operand& op) { vcmpneqss(x, x, op); UNIMPLEMENTED; }
void vcmpnge_uqpd(const Xmm& x, const Operand& op) { vcmpnge_uqpd(x, x, op); UNIMPLEMENTED; }
void vcmpnge_uqps(const Xmm& x, const Operand& op) { vcmpnge_uqps(x, x, op); decodeAndTransToAArch64(); }
void vcmpnge_uqsd(const Xmm& x, const Operand& op) { vcmpnge_uqsd(x, x, op); UNIMPLEMENTED; }
void vcmpnge_uqss(const Xmm& x, const Operand& op) { vcmpnge_uqss(x, x, op); UNIMPLEMENTED; }
void vcmpngepd(const Xmm& x, const Operand& op) { vcmpngepd(x, x, op); UNIMPLEMENTED; }
void vcmpngeps(const Xmm& x, const Operand& op) { vcmpngeps(x, x, op); decodeAndTransToAArch64(); }
void vcmpngesd(const Xmm& x, const Operand& op) { vcmpngesd(x, x, op); UNIMPLEMENTED; }
void vcmpngess(const Xmm& x, const Operand& op) { vcmpngess(x, x, op); UNIMPLEMENTED; }
void vcmpngt_uqpd(const Xmm& x, const Operand& op) { vcmpngt_uqpd(x, x, op); UNIMPLEMENTED; }
void vcmpngt_uqps(const Xmm& x, const Operand& op) { vcmpngt_uqps(x, x, op); decodeAndTransToAArch64(); }
void vcmpngt_uqsd(const Xmm& x, const Operand& op) { vcmpngt_uqsd(x, x, op); UNIMPLEMENTED; }
void vcmpngt_uqss(const Xmm& x, const Operand& op) { vcmpngt_uqss(x, x, op); UNIMPLEMENTED; }
void vcmpngtpd(const Xmm& x, const Operand& op) { vcmpngtpd(x, x, op); UNIMPLEMENTED; }
void vcmpngtps(const Xmm& x, const Operand& op) { vcmpngtps(x, x, op); decodeAndTransToAArch64(); }
void vcmpngtsd(const Xmm& x, const Operand& op) { vcmpngtsd(x, x, op); UNIMPLEMENTED; }
void vcmpngtss(const Xmm& x, const Operand& op) { vcmpngtss(x, x, op); UNIMPLEMENTED; }
void vcmpnle_uqpd(const Xmm& x, const Operand& op) { vcmpnle_uqpd(x, x, op); UNIMPLEMENTED; }
void vcmpnle_uqps(const Xmm& x, const Operand& op) { vcmpnle_uqps(x, x, op); decodeAndTransToAArch64(); }
void vcmpnle_uqsd(const Xmm& x, const Operand& op) { vcmpnle_uqsd(x, x, op); UNIMPLEMENTED; }
void vcmpnle_uqss(const Xmm& x, const Operand& op) { vcmpnle_uqss(x, x, op); UNIMPLEMENTED; }
void vcmpnlepd(const Xmm& x, const Operand& op) { vcmpnlepd(x, x, op); UNIMPLEMENTED; }
void vcmpnleps(const Xmm& x, const Operand& op) { vcmpnleps(x, x, op); decodeAndTransToAArch64(); }
void vcmpnlesd(const Xmm& x, const Operand& op) { vcmpnlesd(x, x, op); UNIMPLEMENTED; }
void vcmpnless(const Xmm& x, const Operand& op) { vcmpnless(x, x, op); UNIMPLEMENTED; }
void vcmpnlt_uqpd(const Xmm& x, const Operand& op) { vcmpnlt_uqpd(x, x, op); UNIMPLEMENTED; }
void vcmpnlt_uqps(const Xmm& x, const Operand& op) { vcmpnlt_uqps(x, x, op); decodeAndTransToAArch64(); }
void vcmpnlt_uqsd(const Xmm& x, const Operand& op) { vcmpnlt_uqsd(x, x, op); UNIMPLEMENTED; }
void vcmpnlt_uqss(const Xmm& x, const Operand& op) { vcmpnlt_uqss(x, x, op); UNIMPLEMENTED; }
void vcmpnltpd(const Xmm& x, const Operand& op) { vcmpnltpd(x, x, op); UNIMPLEMENTED; }
void vcmpnltps(const Xmm& x, const Operand& op) { vcmpnltps(x, x, op); decodeAndTransToAArch64(); }
void vcmpnltsd(const Xmm& x, const Operand& op) { vcmpnltsd(x, x, op); UNIMPLEMENTED; }
void vcmpnltss(const Xmm& x, const Operand& op) { vcmpnltss(x, x, op); UNIMPLEMENTED; }
void vcmpord_spd(const Xmm& x, const Operand& op) { vcmpord_spd(x, x, op); UNIMPLEMENTED; }
void vcmpord_sps(const Xmm& x, const Operand& op) { vcmpord_sps(x, x, op); decodeAndTransToAArch64(); }
void vcmpord_ssd(const Xmm& x, const Operand& op) { vcmpord_ssd(x, x, op); UNIMPLEMENTED; }
void vcmpord_sss(const Xmm& x, const Operand& op) { vcmpord_sss(x, x, op); UNIMPLEMENTED; }
void vcmpordpd(const Xmm& x, const Operand& op) { vcmpordpd(x, x, op); UNIMPLEMENTED; }
void vcmpordps(const Xmm& x, const Operand& op) { vcmpordps(x, x, op); decodeAndTransToAArch64(); }
void vcmpordsd(const Xmm& x, const Operand& op) { vcmpordsd(x, x, op); UNIMPLEMENTED; }
void vcmpordss(const Xmm& x, const Operand& op) { vcmpordss(x, x, op); UNIMPLEMENTED; }
void vcmppd(const Xmm& x, const Operand& op, uint8 imm) { vcmppd(x, x, op, imm); UNIMPLEMENTED; }
void vcmpps(const Xmm& x, const Operand& op, uint8 imm) { vcmpps(x, x, op, imm); }
void vcmpsd(const Xmm& x, const Operand& op, uint8 imm) { vcmpsd(x, x, op, imm); UNIMPLEMENTED; }
void vcmpss(const Xmm& x, const Operand& op, uint8 imm) { vcmpss(x, x, op, imm); UNIMPLEMENTED; }
void vcmptrue_uspd(const Xmm& x, const Operand& op) { vcmptrue_uspd(x, x, op); UNIMPLEMENTED; }
void vcmptrue_usps(const Xmm& x, const Operand& op) { vcmptrue_usps(x, x, op); decodeAndTransToAArch64(); }
void vcmptrue_ussd(const Xmm& x, const Operand& op) { vcmptrue_ussd(x, x, op); UNIMPLEMENTED; }
void vcmptrue_usss(const Xmm& x, const Operand& op) { vcmptrue_usss(x, x, op); UNIMPLEMENTED; }
void vcmptruepd(const Xmm& x, const Operand& op) { vcmptruepd(x, x, op); UNIMPLEMENTED; }
void vcmptrueps(const Xmm& x, const Operand& op) { vcmptrueps(x, x, op); decodeAndTransToAArch64(); }
void vcmptruesd(const Xmm& x, const Operand& op) { vcmptruesd(x, x, op); UNIMPLEMENTED; }
void vcmptruess(const Xmm& x, const Operand& op) { vcmptruess(x, x, op); UNIMPLEMENTED; }
void vcmpunord_spd(const Xmm& x, const Operand& op) { vcmpunord_spd(x, x, op); UNIMPLEMENTED; }
void vcmpunord_sps(const Xmm& x, const Operand& op) { vcmpunord_sps(x, x, op); decodeAndTransToAArch64(); }
void vcmpunord_ssd(const Xmm& x, const Operand& op) { vcmpunord_ssd(x, x, op); UNIMPLEMENTED; }
void vcmpunord_sss(const Xmm& x, const Operand& op) { vcmpunord_sss(x, x, op); UNIMPLEMENTED; }
void vcmpunordpd(const Xmm& x, const Operand& op) { vcmpunordpd(x, x, op); UNIMPLEMENTED; }
void vcmpunordps(const Xmm& x, const Operand& op) { vcmpunordps(x, x, op); decodeAndTransToAArch64(); }
void vcmpunordsd(const Xmm& x, const Operand& op) { vcmpunordsd(x, x, op); UNIMPLEMENTED; }
void vcmpunordss(const Xmm& x, const Operand& op) { vcmpunordss(x, x, op); UNIMPLEMENTED; }
void vcvtsd2ss(const Xmm& x, const Operand& op) { vcvtsd2ss(x, x, op); UNIMPLEMENTED; }
void vcvtsi2sd(const Xmm& x, const Operand& op) { vcvtsi2sd(x, x, op); UNIMPLEMENTED; }
void vcvtsi2ss(const Xmm& x, const Operand& op) { vcvtsi2ss(x, x, op); UNIMPLEMENTED; }
void vcvtss2sd(const Xmm& x, const Operand& op) { vcvtss2sd(x, x, op); UNIMPLEMENTED; }
void vdppd(const Xmm& x, const Operand& op, uint8 imm) { vdppd(x, x, op, imm); UNIMPLEMENTED; }
void vdpps(const Xmm& x, const Operand& op, uint8 imm) { vdpps(x, x, op, imm); UNIMPLEMENTED; }
void vinsertps(const Xmm& x, const Operand& op, uint8 imm) { vinsertps(x, x, op, imm); UNIMPLEMENTED; }
void vmpsadbw(const Xmm& x, const Operand& op, uint8 imm) { vmpsadbw(x, x, op, imm); UNIMPLEMENTED; }
void vpackssdw(const Xmm& x, const Operand& op) { vpackssdw(x, x, op); UNIMPLEMENTED; }
void vpacksswb(const Xmm& x, const Operand& op) { vpacksswb(x, x, op); UNIMPLEMENTED; }
void vpackusdw(const Xmm& x, const Operand& op) { vpackusdw(x, x, op); UNIMPLEMENTED; }
void vpackuswb(const Xmm& x, const Operand& op) { vpackuswb(x, x, op); UNIMPLEMENTED; }
void vpaddb(const Xmm& x, const Operand& op) { vpaddb(x, x, op); decodeAndTransToAArch64(); }
void vpaddd(const Xmm& x, const Operand& op) { vpaddd(x, x, op);  }
void vpaddq(const Xmm& x, const Operand& op) { vpaddq(x, x, op); decodeAndTransToAArch64(); }
void vpaddsb(const Xmm& x, const Operand& op) { vpaddsb(x, x, op); UNIMPLEMENTED; }
void vpaddsw(const Xmm& x, const Operand& op) { vpaddsw(x, x, op); UNIMPLEMENTED; }
void vpaddusb(const Xmm& x, const Operand& op) { vpaddusb(x, x, op); UNIMPLEMENTED; }
void vpaddusw(const Xmm& x, const Operand& op) { vpaddusw(x, x, op); UNIMPLEMENTED; }
void vpaddw(const Xmm& x, const Operand& op) { vpaddw(x, x, op); UNIMPLEMENTED; }
void vpalignr(const Xmm& x, const Operand& op, uint8 imm) { vpalignr(x, x, op, imm); UNIMPLEMENTED; }
void vpand(const Xmm& x, const Operand& op) { vpand(x, x, op); UNIMPLEMENTED; }
void vpandn(const Xmm& x, const Operand& op) { vpandn(x, x, op); UNIMPLEMENTED; }
void vpavgb(const Xmm& x, const Operand& op) { vpavgb(x, x, op); UNIMPLEMENTED; }
void vpavgw(const Xmm& x, const Operand& op) { vpavgw(x, x, op); UNIMPLEMENTED; }
void vpblendd(const Xmm& x, const Operand& op, uint8 imm) { vpblendd(x, x, op, imm); UNIMPLEMENTED; }
void vpblendvb(const Xmm& x1, const Operand& op, const Xmm& x4) { vpblendvb(x1, x1, op, x4); UNIMPLEMENTED; }
void vpblendw(const Xmm& x, const Operand& op, uint8 imm) { vpblendw(x, x, op, imm); UNIMPLEMENTED; }
void vpclmulqdq(const Xmm& x, const Operand& op, uint8 imm) { vpclmulqdq(x, x, op, imm); UNIMPLEMENTED; }
void vpcmpeqb(const Xmm& x, const Operand& op) { vpcmpeqb(x, x, op); UNIMPLEMENTED; }
void vpcmpeqd(const Xmm& x, const Operand& op) { vpcmpeqd(x, x, op); decodeAndTransToAArch64(); }
void vpcmpeqq(const Xmm& x, const Operand& op) { vpcmpeqq(x, x, op); UNIMPLEMENTED; }
void vpcmpeqw(const Xmm& x, const Operand& op) { vpcmpeqw(x, x, op); UNIMPLEMENTED; }
void vpcmpgtb(const Xmm& x, const Operand& op) { vpcmpgtb(x, x, op); UNIMPLEMENTED; }
void vpcmpgtd(const Xmm& x, const Operand& op) { vpcmpgtd(x, x, op); UNIMPLEMENTED; }
void vpcmpgtq(const Xmm& x, const Operand& op) { vpcmpgtq(x, x, op); UNIMPLEMENTED; }
void vpcmpgtw(const Xmm& x, const Operand& op) { vpcmpgtw(x, x, op); UNIMPLEMENTED; }
void vphaddd(const Xmm& x, const Operand& op) { vphaddd(x, x, op); UNIMPLEMENTED; }
void vphaddsw(const Xmm& x, const Operand& op) { vphaddsw(x, x, op); UNIMPLEMENTED; }
void vphaddw(const Xmm& x, const Operand& op) { vphaddw(x, x, op); UNIMPLEMENTED; }
void vphsubd(const Xmm& x, const Operand& op) { vphsubd(x, x, op); UNIMPLEMENTED; }
void vphsubsw(const Xmm& x, const Operand& op) { vphsubsw(x, x, op); UNIMPLEMENTED; }
void vphsubw(const Xmm& x, const Operand& op) { vphsubw(x, x, op); UNIMPLEMENTED; }
void vpinsrb(const Xmm& x, const Operand& op, uint8 imm) { vpinsrb(x, x, op, imm); UNIMPLEMENTED; }
void vpinsrd(const Xmm& x, const Operand& op, uint8 imm) { vpinsrd(x, x, op, imm); UNIMPLEMENTED; }
void vpinsrq(const Xmm& x, const Operand& op, uint8 imm) { vpinsrq(x, x, op, imm); UNIMPLEMENTED; }
void vpinsrw(const Xmm& x, const Operand& op, uint8 imm) { vpinsrw(x, x, op, imm); UNIMPLEMENTED; }
void vpmaddubsw(const Xmm& x, const Operand& op) { vpmaddubsw(x, x, op); UNIMPLEMENTED; }
void vpmaddwd(const Xmm& x, const Operand& op) { vpmaddwd(x, x, op); UNIMPLEMENTED; }
void vpmaxsb(const Xmm& x, const Operand& op) { vpmaxsb(x, x, op); UNIMPLEMENTED; }
void vpmaxsd(const Xmm& x, const Operand& op) { vpmaxsd(x, x, op);  }
void vpmaxsw(const Xmm& x, const Operand& op) { vpmaxsw(x, x, op); UNIMPLEMENTED; }
void vpmaxub(const Xmm& x, const Operand& op) { vpmaxub(x, x, op); UNIMPLEMENTED; }
void vpmaxud(const Xmm& x, const Operand& op) { vpmaxud(x, x, op); UNIMPLEMENTED; }
void vpmaxuw(const Xmm& x, const Operand& op) { vpmaxuw(x, x, op); UNIMPLEMENTED; }
void vpminsb(const Xmm& x, const Operand& op) { vpminsb(x, x, op); UNIMPLEMENTED; }
void vpminsd(const Xmm& x, const Operand& op) { vpminsd(x, x, op); UNIMPLEMENTED; }
void vpminsw(const Xmm& x, const Operand& op) { vpminsw(x, x, op); UNIMPLEMENTED; }
void vpminub(const Xmm& x, const Operand& op) { vpminub(x, x, op); UNIMPLEMENTED; }
void vpminud(const Xmm& x, const Operand& op) { vpminud(x, x, op); UNIMPLEMENTED; }
void vpminuw(const Xmm& x, const Operand& op) { vpminuw(x, x, op); UNIMPLEMENTED; }
void vpmuldq(const Xmm& x, const Operand& op) { vpmuldq(x, x, op); UNIMPLEMENTED; }
void vpmulhrsw(const Xmm& x, const Operand& op) { vpmulhrsw(x, x, op); UNIMPLEMENTED; }
void vpmulhuw(const Xmm& x, const Operand& op) { vpmulhuw(x, x, op); UNIMPLEMENTED; }
void vpmulhw(const Xmm& x, const Operand& op) { vpmulhw(x, x, op); UNIMPLEMENTED; }
void vpmulld(const Xmm& x, const Operand& op) { vpmulld(x, x, op); UNIMPLEMENTED; }
void vpmullw(const Xmm& x, const Operand& op) { vpmullw(x, x, op); UNIMPLEMENTED; }
void vpmuludq(const Xmm& x, const Operand& op) { vpmuludq(x, x, op); UNIMPLEMENTED; }
void vpor(const Xmm& x, const Operand& op) { vpor(x, x, op); UNIMPLEMENTED; }
void vpsadbw(const Xmm& x, const Operand& op) { vpsadbw(x, x, op); UNIMPLEMENTED; }
void vpsignb(const Xmm& x, const Operand& op) { vpsignb(x, x, op); UNIMPLEMENTED; }
void vpsignd(const Xmm& x, const Operand& op) { vpsignd(x, x, op); UNIMPLEMENTED; }
void vpsignw(const Xmm& x, const Operand& op) { vpsignw(x, x, op); UNIMPLEMENTED; }
void vpslld(const Xmm& x, const Operand& op) { vpslld(x, x, op); UNIMPLEMENTED; }
void vpslld(const Xmm& x, uint8 imm) { vpslld(x, x, imm); UNIMPLEMENTED; }
void vpslldq(const Xmm& x, uint8 imm) { vpslldq(x, x, imm); UNIMPLEMENTED; }
void vpsllq(const Xmm& x, const Operand& op) { vpsllq(x, x, op); UNIMPLEMENTED; }
void vpsllq(const Xmm& x, uint8 imm) { vpsllq(x, x, imm); UNIMPLEMENTED; }
void vpsllw(const Xmm& x, const Operand& op) { vpsllw(x, x, op); UNIMPLEMENTED; }
void vpsllw(const Xmm& x, uint8 imm) { vpsllw(x, x, imm); UNIMPLEMENTED; }
void vpsrad(const Xmm& x, const Operand& op) { vpsrad(x, x, op); UNIMPLEMENTED; }
void vpsrad(const Xmm& x, uint8 imm) { vpsrad(x, x, imm); UNIMPLEMENTED; }
void vpsraw(const Xmm& x, const Operand& op) { vpsraw(x, x, op); UNIMPLEMENTED; }
void vpsraw(const Xmm& x, uint8 imm) { vpsraw(x, x, imm); UNIMPLEMENTED; }
void vpsrld(const Xmm& x, const Operand& op) { vpsrld(x, x, op); UNIMPLEMENTED; }
void vpsrld(const Xmm& x, uint8 imm) { vpsrld(x, x, imm); UNIMPLEMENTED; }
void vpsrldq(const Xmm& x, uint8 imm) { vpsrldq(x, x, imm); UNIMPLEMENTED; }
void vpsrlq(const Xmm& x, const Operand& op) { vpsrlq(x, x, op); UNIMPLEMENTED; }
void vpsrlq(const Xmm& x, uint8 imm) { vpsrlq(x, x, imm); UNIMPLEMENTED; }
void vpsrlw(const Xmm& x, const Operand& op) { vpsrlw(x, x, op); UNIMPLEMENTED; }
void vpsrlw(const Xmm& x, uint8 imm) { vpsrlw(x, x, imm); UNIMPLEMENTED; }
void vpsubb(const Xmm& x, const Operand& op) { vpsubb(x, x, op); UNIMPLEMENTED; }
void vpsubd(const Xmm& x, const Operand& op) { vpsubd(x, x, op); UNIMPLEMENTED; }
void vpsubq(const Xmm& x, const Operand& op) { vpsubq(x, x, op); UNIMPLEMENTED; }
void vpsubsb(const Xmm& x, const Operand& op) { vpsubsb(x, x, op); UNIMPLEMENTED; }
void vpsubsw(const Xmm& x, const Operand& op) { vpsubsw(x, x, op); UNIMPLEMENTED; }
void vpsubusb(const Xmm& x, const Operand& op) { vpsubusb(x, x, op); UNIMPLEMENTED; }
void vpsubusw(const Xmm& x, const Operand& op) { vpsubusw(x, x, op); UNIMPLEMENTED; }
void vpsubw(const Xmm& x, const Operand& op) { vpsubw(x, x, op); UNIMPLEMENTED; }
void vpunpckhbw(const Xmm& x, const Operand& op) { vpunpckhbw(x, x, op); /*UNIMPLEMENTED;*/ }
void vpunpckhdq(const Xmm& x, const Operand& op) { vpunpckhdq(x, x, op); UNIMPLEMENTED; }
void vpunpckhqdq(const Xmm& x, const Operand& op) { vpunpckhqdq(x, x, op); /*UNIMPLEMENTED;*/ }
void vpunpckhwd(const Xmm& x, const Operand& op) { vpunpckhwd(x, x, op); /*UNIMPLEMENTED;*/ }
void vpunpcklbw(const Xmm& x, const Operand& op) { vpunpcklbw(x, x, op); /*UNIMPLEMENTED;*/ }
void vpunpckldq(const Xmm& x, const Operand& op) { vpunpckldq(x, x, op); /*UNIMPLEMENTED;*/ }
void vpunpcklqdq(const Xmm& x, const Operand& op) { vpunpcklqdq(x, x, op); /*UNIMPLEMENTED;*/ }
void vpunpcklwd(const Xmm& x, const Operand& op) { vpunpcklwd(x, x, op); /*UNIMPLEMENTED;*/ }
void vpxor(const Xmm& x, const Operand& op) { vpxor(x, x, op); UNIMPLEMENTED; }
void vrcpss(const Xmm& x, const Operand& op) { vrcpss(x, x, op); UNIMPLEMENTED; }
void vroundsd(const Xmm& x, const Operand& op, uint8 imm) { vroundsd(x, x, op, imm); UNIMPLEMENTED; }
void vroundss(const Xmm& x, const Operand& op, uint8 imm) { vroundss(x, x, op, imm); UNIMPLEMENTED; }
void vrsqrtss(const Xmm& x, const Operand& op) { vrsqrtss(x, x, op); UNIMPLEMENTED; }
void vshufpd(const Xmm& x, const Operand& op, uint8 imm) { vshufpd(x, x, op, imm); UNIMPLEMENTED; }
void vshufps(const Xmm& x, const Operand& op, uint8 imm) { vshufps(x, x, op, imm); UNIMPLEMENTED; }
void vsqrtsd(const Xmm& x, const Operand& op) { vsqrtsd(x, x, op); UNIMPLEMENTED; }
void vsqrtss(const Xmm& x, const Operand& op) { vsqrtss(x, x, op); UNIMPLEMENTED; }
void vunpckhpd(const Xmm& x, const Operand& op) { vunpckhpd(x, x, op); UNIMPLEMENTED; }
void vunpckhps(const Xmm& x, const Operand& op) { vunpckhps(x, x, op); UNIMPLEMENTED; }
void vunpcklpd(const Xmm& x, const Operand& op) { vunpcklpd(x, x, op); UNIMPLEMENTED; }
void vunpcklps(const Xmm& x, const Operand& op) { vunpcklps(x, x, op); UNIMPLEMENTED; }
#endif
#ifdef XBYAK64
#ifdef XBYAK_TRANSLATE_AARCH64
void jecxz(std::string label) { UNIMPLEMENTED; }
void jecxz(const Label& label) { UNIMPLEMENTED; }
void jrcxz(std::string label) { UNIMPLEMENTED; }
void jrcxz(const Label& label) { UNIMPLEMENTED; }
#else //#ifdef XBYAK_TRANSLATE_AARCH64
void jecxz(std::string label) { db(0x67); opJmp(label, T_SHORT, 0xe3, 0, 0); UNIMPLEMENTED; }
void jecxz(const Label& label) { db(0x67); opJmp(label, T_SHORT, 0xe3, 0, 0); UNIMPLEMENTED; }
void jrcxz(std::string label) { opJmp(label, T_SHORT, 0xe3, 0, 0); UNIMPLEMENTED; }
void jrcxz(const Label& label) { opJmp(label, T_SHORT, 0xe3, 0, 0); UNIMPLEMENTED; }
#endif //#ifdef XBYAK_TRANSLATE_AARCH64
void cdqe() { db(0x48); db(0x98); UNIMPLEMENTED; }
void cqo() { db(0x48); db(0x99); UNIMPLEMENTED; }
void cmpsq() { db(0x48); db(0xA7); UNIMPLEMENTED; }
void popfq() { db(0x9D); UNIMPLEMENTED; }
void pushfq() { db(0x9C); UNIMPLEMENTED; }
void lodsq() { db(0x48); db(0xAD); UNIMPLEMENTED; }
void movsq() { db(0x48); db(0xA5); UNIMPLEMENTED; }
void scasq() { db(0x48); db(0xAF); UNIMPLEMENTED; }
void stosq() { db(0x48); db(0xAB); UNIMPLEMENTED; }
void syscall() { db(0x0F); db(0x05); UNIMPLEMENTED; }
void sysret() { db(0x0F); db(0x07); UNIMPLEMENTED; }
void cmpxchg16b(const Address& addr) { opModM(addr, Reg64(1), 0x0F, 0xC7); UNIMPLEMENTED; }
void fxrstor64(const Address& addr) { opModM(addr, Reg64(1), 0x0F, 0xAE); UNIMPLEMENTED; }
void movq(const Reg64& reg, const Mmx& mmx) { if (mmx.isXMM()) db(0x66); opModR(mmx, reg, 0x0F, 0x7E); decodeAndTransToAArch64(); }
void movq(const Mmx& mmx, const Reg64& reg) { if (mmx.isXMM()) db(0x66); opModR(mmx, reg, 0x0F, 0x6E); decodeAndTransToAArch64(); }
void movsxd(const Reg64& reg, const Operand& op) { if (!op.isBit(32)) throw Error(ERR_BAD_COMBINATION); opModRM(reg, op, op.isREG(), op.isMEM(), 0x63); UNIMPLEMENTED; }
void pextrq(const Operand& op, const Xmm& xmm, uint8 imm) { if (!op.isREG(64) && !op.isMEM()) throw Error(ERR_BAD_COMBINATION); opGen(Reg64(xmm.getIdx()), op, 0x16, 0x66, 0, imm, 0x3A); UNIMPLEMENTED; }
void pinsrq(const Xmm& xmm, const Operand& op, uint8 imm) { if (!op.isREG(64) && !op.isMEM()) throw Error(ERR_BAD_COMBINATION); opGen(Reg64(xmm.getIdx()), op, 0x22, 0x66, 0, imm, 0x3A); UNIMPLEMENTED; }
void vcvtss2si(const Reg64& r, const Operand& op) { opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, T_0F | T_F3 | T_W1 | T_EVEX | T_EW1 | T_ER_X | T_N8, 0x2D); UNIMPLEMENTED; }
void vcvttss2si(const Reg64& r, const Operand& op) { opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, T_0F | T_F3 | T_W1 | T_EVEX | T_EW1 | T_SAE_X | T_N8, 0x2C); UNIMPLEMENTED; }
void vcvtsd2si(const Reg64& r, const Operand& op) { opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, T_0F | T_F2 | T_W1 | T_EVEX | T_EW1 | T_N4 | T_ER_X, 0x2D); UNIMPLEMENTED; }
void vcvttsd2si(const Reg64& r, const Operand& op) { opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, T_0F | T_F2 | T_W1 | T_EVEX | T_EW1 | T_N4 | T_SAE_X, 0x2C); UNIMPLEMENTED; }
void vmovq(const Xmm& x, const Reg64& r) { opAVX_X_X_XM(x, xm0, Xmm(r.getIdx()), T_66 | T_0F | T_W1 | T_EVEX | T_EW1, 0x6E); decodeAndTransToAArch64(); }
void vmovq(const Reg64& r, const Xmm& x) { opAVX_X_X_XM(x, xm0, Xmm(r.getIdx()), T_66 | T_0F | T_W1 | T_EVEX | T_EW1, 0x7E); decodeAndTransToAArch64(); }
#else
void jcxz(std::string label) { db(0x67); opJmp(label, T_SHORT, 0xe3, 0, 0); UNIMPLEMENTED; }
void jcxz(const Label& label) { db(0x67); opJmp(label, T_SHORT, 0xe3, 0, 0); UNIMPLEMENTED; }
void jecxz(std::string label) { opJmp(label, T_SHORT, 0xe3, 0, 0); UNIMPLEMENTED; }
void jecxz(const Label& label) { opJmp(label, T_SHORT, 0xe3, 0, 0); UNIMPLEMENTED; }
void aaa() { db(0x37); UNIMPLEMENTED; }
void aad() { db(0xD5); db(0x0A); UNIMPLEMENTED; }
void aam() { db(0xD4); db(0x0A); UNIMPLEMENTED; }
void aas() { db(0x3F); UNIMPLEMENTED; }
void daa() { db(0x27); UNIMPLEMENTED; }
void das() { db(0x2F); UNIMPLEMENTED; }
void into() { db(0xCE); UNIMPLEMENTED; }
void popad() { db(0x61); UNIMPLEMENTED; }
void popfd() { db(0x9D); UNIMPLEMENTED; }
void pusha() { db(0x60); UNIMPLEMENTED; }
void pushad() { db(0x60); UNIMPLEMENTED; }
void pushfd() { db(0x9C); std::cerr << "No support for PUSHFD instruction" << std::endl; }
void popa() { db(0x61); UNIMPLEMENTED; }
void lds(const Reg& reg, const Address& addr) { opLoadSeg(addr, reg, 0xC5, 0x100); UNIMPLEMENTED; }
void les(const Reg& reg, const Address& addr) { opLoadSeg(addr, reg, 0xC4, 0x100); UNIMPLEMENTED; }
#endif
#ifndef XBYAK_NO_OP_NAMES
void and(const Operand& op1, const Operand& op2) { and_(op1, op2); UNIMPLEMENTED; }
void and(const Operand& op, uint32 imm) { and_(op, imm); UNIMPLEMENTED; }
void or(const Operand& op1, const Operand& op2) { or_(op1, op2); UNIMPLEMENTED; }
void or(const Operand& op, uint32 imm) { or_(op, imm); UNIMPLEMENTED; }
void xor(const Operand& op1, const Operand& op2) { xor_(op1, op2); decodeAndTransToAArch64(); }
void xor(const Operand& op, uint32 imm) { xor_(op, imm); decodeAndTransToAArch64(); }
void not(const Operand& op) { not_(op); decodeAndTransToAArch64(); }
#endif
#ifndef XBYAK_DISABLE_AVX512
void kaddb(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W0, 0x4A); UNIMPLEMENTED; }
void kaddd(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W1, 0x4A); UNIMPLEMENTED; }
void kaddq(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_W1, 0x4A); UNIMPLEMENTED; }
void kaddw(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_W0, 0x4A); UNIMPLEMENTED; }
void kandb(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W0, 0x41); UNIMPLEMENTED; }
void kandd(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W1, 0x41); UNIMPLEMENTED; }
void kandnb(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W0, 0x42); UNIMPLEMENTED; }
void kandnd(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W1, 0x42); UNIMPLEMENTED; }
void kandnq(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_W1, 0x42); UNIMPLEMENTED; }
void kandnw(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_W0, 0x42); UNIMPLEMENTED; }
void kandq(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_W1, 0x41); UNIMPLEMENTED; }
void kandw(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_W0, 0x41); UNIMPLEMENTED; }
void kmovb(const Address& addr, const Opmask& k) { opVex(k, 0, addr, T_L0 | T_0F | T_66 | T_W0, 0x91); UNIMPLEMENTED; }
void kmovb(const Opmask& k, const Operand& op) { opVex(k, 0, op, T_L0 | T_0F | T_66 | T_W0, 0x90); UNIMPLEMENTED; }
void kmovb(const Opmask& k, const Reg32& r) { opVex(k, 0, r, T_L0 | T_0F | T_66 | T_W0, 0x92); UNIMPLEMENTED; }
void kmovb(const Reg32& r, const Opmask& k) { opVex(r, 0, k, T_L0 | T_0F | T_66 | T_W0, 0x93); UNIMPLEMENTED; }
void kmovd(const Address& addr, const Opmask& k) { opVex(k, 0, addr, T_L0 | T_0F | T_66 | T_W1, 0x91); decodeAndTransToAArch64(); }
void kmovd(const Opmask& k, const Operand& op) { opVex(k, 0, op, T_L0 | T_0F | T_66 | T_W1, 0x90); decodeAndTransToAArch64(); }
void kmovd(const Opmask& k, const Reg32& r) { opVex(k, 0, r, T_L0 | T_0F | T_F2 | T_W0, 0x92); decodeAndTransToAArch64(); }
void kmovd(const Reg32& r, const Opmask& k) { opVex(r, 0, k, T_L0 | T_0F | T_F2 | T_W0, 0x93); decodeAndTransToAArch64(); }
void kmovq(const Address& addr, const Opmask& k) { opVex(k, 0, addr, T_L0 | T_0F | T_W1, 0x91); decodeAndTransToAArch64(); }
void kmovq(const Opmask& k, const Operand& op) { opVex(k, 0, op, T_L0 | T_0F | T_W1, 0x90); decodeAndTransToAArch64(); }
void kmovw(const Address& addr, const Opmask& k) { opVex(k, 0, addr, T_L0 | T_0F | T_W0, 0x91); decodeAndTransToAArch64(); }
void kmovw(const Opmask& k, const Operand& op) { opVex(k, 0, op, T_L0 | T_0F | T_W0, 0x90); decodeAndTransToAArch64(); }
void kmovw(const Opmask& k, const Reg32& r) { opVex(k, 0, r, T_L0 | T_0F | T_W0, 0x92); decodeAndTransToAArch64(); }
void kmovw(const Reg32& r, const Opmask& k) { opVex(r, 0, k, T_L0 | T_0F | T_W0, 0x93); decodeAndTransToAArch64(); }
void knotb(const Opmask& r1, const Opmask& r2) { opVex(r1, 0, r2, T_0F | T_66 | T_W0, 0x44); UNIMPLEMENTED; }
void knotd(const Opmask& r1, const Opmask& r2) { opVex(r1, 0, r2, T_0F | T_66 | T_W1, 0x44); UNIMPLEMENTED; }
void knotq(const Opmask& r1, const Opmask& r2) { opVex(r1, 0, r2, T_0F | T_W1, 0x44); UNIMPLEMENTED; }
void knotw(const Opmask& r1, const Opmask& r2) { opVex(r1, 0, r2, T_0F | T_W0, 0x44); UNIMPLEMENTED; }
void korb(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W0, 0x45); UNIMPLEMENTED; }
void kord(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W1, 0x45); UNIMPLEMENTED; }
void korq(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_W1, 0x45); UNIMPLEMENTED; }
void kortestb(const Opmask& r1, const Opmask& r2) { opVex(r1, 0, r2, T_0F | T_66 | T_W0, 0x98); UNIMPLEMENTED; }
void kortestd(const Opmask& r1, const Opmask& r2) { opVex(r1, 0, r2, T_0F | T_66 | T_W1, 0x98); UNIMPLEMENTED; }
void kortestq(const Opmask& r1, const Opmask& r2) { opVex(r1, 0, r2, T_0F | T_W1, 0x98); UNIMPLEMENTED; }
void kortestw(const Opmask& r1, const Opmask& r2) { opVex(r1, 0, r2, T_0F | T_W0, 0x98); decodeAndTransToAArch64(); }
void korw(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_W0, 0x45); UNIMPLEMENTED; }
void kshiftlb(const Opmask& r1, const Opmask& r2, uint8 imm) { opVex(r1, 0, r2, T_66 | T_0F3A | T_W0, 0x32, imm); UNIMPLEMENTED; }
void kshiftld(const Opmask& r1, const Opmask& r2, uint8 imm) { opVex(r1, 0, r2, T_66 | T_0F3A | T_W0, 0x33, imm); UNIMPLEMENTED; }
void kshiftlq(const Opmask& r1, const Opmask& r2, uint8 imm) { opVex(r1, 0, r2, T_66 | T_0F3A | T_W1, 0x33, imm); UNIMPLEMENTED; }
void kshiftlw(const Opmask& r1, const Opmask& r2, uint8 imm) { opVex(r1, 0, r2, T_66 | T_0F3A | T_W1, 0x32, imm); UNIMPLEMENTED; }
void kshiftrb(const Opmask& r1, const Opmask& r2, uint8 imm) { opVex(r1, 0, r2, T_66 | T_0F3A | T_W0, 0x30, imm); UNIMPLEMENTED; }
void kshiftrd(const Opmask& r1, const Opmask& r2, uint8 imm) { opVex(r1, 0, r2, T_66 | T_0F3A | T_W0, 0x31, imm); UNIMPLEMENTED; }
void kshiftrq(const Opmask& r1, const Opmask& r2, uint8 imm) { opVex(r1, 0, r2, T_66 | T_0F3A | T_W1, 0x31, imm); UNIMPLEMENTED; }
void kshiftrw(const Opmask& r1, const Opmask& r2, uint8 imm) { opVex(r1, 0, r2, T_66 | T_0F3A | T_W1, 0x30, imm); UNIMPLEMENTED; }
void ktestb(const Opmask& r1, const Opmask& r2) { opVex(r1, 0, r2, T_0F | T_66 | T_W0, 0x99); UNIMPLEMENTED; }
void ktestd(const Opmask& r1, const Opmask& r2) { opVex(r1, 0, r2, T_0F | T_66 | T_W1, 0x99); UNIMPLEMENTED; }
void ktestq(const Opmask& r1, const Opmask& r2) { opVex(r1, 0, r2, T_0F | T_W1, 0x99); UNIMPLEMENTED; }
void ktestw(const Opmask& r1, const Opmask& r2) { opVex(r1, 0, r2, T_0F | T_W0, 0x99); UNIMPLEMENTED; }
void kunpckbw(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W0, 0x4B); UNIMPLEMENTED; }
void kunpckdq(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_W1, 0x4B); UNIMPLEMENTED; }
void kunpckwd(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_W0, 0x4B); UNIMPLEMENTED; }
void kxnorb(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W0, 0x46); UNIMPLEMENTED; }
void kxnord(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W1, 0x46); UNIMPLEMENTED; }
void kxnorq(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_W1, 0x46); UNIMPLEMENTED; }
void kxnorw(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_W0, 0x46); UNIMPLEMENTED; }
void kxorb(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W0, 0x47); UNIMPLEMENTED; }
void kxord(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_66 | T_W1, 0x47); UNIMPLEMENTED; }
void kxorq(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_W1, 0x47); UNIMPLEMENTED; }
void kxorw(const Opmask& r1, const Opmask& r2, const Opmask& r3) { opVex(r1, &r2, r3, T_L1 | T_0F | T_W0, 0x47); UNIMPLEMENTED; }
void v4fmaddps(const Zmm& z1, const Zmm& z2, const Address& addr) { opAVX_X_X_XM(z1, z2, addr, T_0F38 | T_F2 | T_EW0 | T_YMM | T_MUST_EVEX | T_N16, 0x9A); UNIMPLEMENTED; }
void v4fmaddss(const Xmm& x1, const Xmm& x2, const Address& addr) { opAVX_X_X_XM(x1, x2, addr, T_0F38 | T_F2 | T_EW0 | T_MUST_EVEX | T_N16, 0x9B); UNIMPLEMENTED; }
void v4fnmaddps(const Zmm& z1, const Zmm& z2, const Address& addr) { opAVX_X_X_XM(z1, z2, addr, T_0F38 | T_F2 | T_EW0 | T_YMM | T_MUST_EVEX | T_N16, 0xAA); UNIMPLEMENTED; }
void v4fnmaddss(const Xmm& x1, const Xmm& x2, const Address& addr) { opAVX_X_X_XM(x1, x2, addr, T_0F38 | T_F2 | T_EW0 | T_MUST_EVEX | T_N16, 0xAB); UNIMPLEMENTED; }
void valignd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x03, imm); UNIMPLEMENTED; }
void valignq(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x03, imm); UNIMPLEMENTED; }
void vblendmpd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x65); UNIMPLEMENTED; }
void vblendmps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x65); decodeAndTransToAArch64(); }
void vbroadcastf32x2(const Ymm& y, const Operand& op) { opAVX_X_XM_IMM(y, op, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW0 | T_N8, 0x19); UNIMPLEMENTED; }
void vbroadcastf32x4(const Ymm& y, const Address& addr) { opAVX_X_XM_IMM(y, addr, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW0 | T_N16, 0x1A); decodeAndTransToAArch64(); }
void vbroadcastf32x8(const Zmm& y, const Address& addr) { opAVX_X_XM_IMM(y, addr, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW0 | T_N32, 0x1B); UNIMPLEMENTED; }
void vbroadcastf64x2(const Ymm& y, const Address& addr) { opAVX_X_XM_IMM(y, addr, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW1 | T_N16, 0x1A); UNIMPLEMENTED; }
void vbroadcastf64x4(const Zmm& y, const Address& addr) { opAVX_X_XM_IMM(y, addr, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW1 | T_N32, 0x1B); decodeAndTransToAArch64(); }
void vbroadcasti32x2(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW0 | T_N8, 0x59); UNIMPLEMENTED; }
void vbroadcasti32x4(const Ymm& y, const Operand& op) { opAVX_X_XM_IMM(y, op, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW0 | T_N16, 0x5A); decodeAndTransToAArch64(); }
void vbroadcasti32x8(const Zmm& z, const Operand& op) { opAVX_X_XM_IMM(z, op, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW0 | T_N32, 0x5B); UNIMPLEMENTED; }
void vbroadcasti64x2(const Ymm& y, const Operand& op) { opAVX_X_XM_IMM(y, op, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW1 | T_N16, 0x5A); UNIMPLEMENTED; }
void vbroadcasti64x4(const Zmm& z, const Operand& op) { opAVX_X_XM_IMM(z, op, T_66 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW1 | T_N32, 0x5B); decodeAndTransToAArch64(); }
void vcmppd(const Opmask& k, const Xmm& x, const Operand& op, uint8 imm) { opAVX_K_X_XM(k, x, op, T_66 | T_0F | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0xC2, imm); UNIMPLEMENTED; }
void vcmpps(const Opmask& k, const Xmm& x, const Operand& op, uint8 imm) { opAVX_K_X_XM(k, x, op, T_0F | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0xC2, imm); decodeAndTransToAArch64(); }
void vcmpsd(const Opmask& k, const Xmm& x, const Operand& op, uint8 imm) { opAVX_K_X_XM(k, x, op, T_N8 | T_F2 | T_0F | T_EW1 | T_SAE_Z | T_MUST_EVEX, 0xC2, imm); UNIMPLEMENTED; }
void vcmpss(const Opmask& k, const Xmm& x, const Operand& op, uint8 imm) { opAVX_K_X_XM(k, x, op, T_N4 | T_F3 | T_0F | T_EW0 | T_SAE_Z | T_MUST_EVEX, 0xC2, imm); UNIMPLEMENTED; }
void vcompressb(const Operand& op, const Xmm& x) { opAVX_X_XM_IMM(x, op, T_N1 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x63); UNIMPLEMENTED; }
void vcompresspd(const Operand& op, const Xmm& x) { opAVX_X_XM_IMM(x, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x8A); UNIMPLEMENTED; }
void vcompressps(const Operand& op, const Xmm& x) { opAVX_X_XM_IMM(x, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x8A); UNIMPLEMENTED; }
void vcompressw(const Operand& op, const Xmm& x) { opAVX_X_XM_IMM(x, op, T_N2 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x63); UNIMPLEMENTED; }
void vcvtne2ps2bf16(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_F2 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x72); UNIMPLEMENTED; }
void vcvtneps2bf16(const Xmm& x, const Operand& op) { opCvt2(x, op, T_F3 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x72); UNIMPLEMENTED; }
void vcvtpd2qq(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F | T_EW1 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B64, 0x7B); UNIMPLEMENTED; }
void vcvtpd2udq(const Xmm& x, const Operand& op) { opCvt2(x, op, T_0F | T_YMM | T_MUST_EVEX | T_EW1 | T_B64 | T_ER_Z, 0x79); UNIMPLEMENTED; }
void vcvtpd2uqq(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F | T_EW1 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B64, 0x79); UNIMPLEMENTED; }
void vcvtps2qq(const Xmm& x, const Operand& op) { checkCvt1(x, op); opVex(x, 0, op, T_66 | T_0F | T_YMM | T_MUST_EVEX | T_EW0 | T_B32 | T_N8 | T_N_VL | T_ER_Y, 0x7B); UNIMPLEMENTED; }
void vcvtps2udq(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_0F | T_EW0 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B32, 0x79); UNIMPLEMENTED; }
void vcvtps2uqq(const Xmm& x, const Operand& op) { checkCvt1(x, op); opVex(x, 0, op, T_66 | T_0F | T_YMM | T_MUST_EVEX | T_EW0 | T_B32 | T_N8 | T_N_VL | T_ER_Y, 0x79); UNIMPLEMENTED; }
void vcvtqq2pd(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_F3 | T_0F | T_EW1 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B64, 0xE6); UNIMPLEMENTED; }
void vcvtqq2ps(const Xmm& x, const Operand& op) { opCvt2(x, op, T_0F | T_YMM | T_MUST_EVEX | T_EW1 | T_B64 | T_ER_Z, 0x5B); UNIMPLEMENTED; }
void vcvtsd2usi(const Reg32e& r, const Operand& op) { int type = (T_F2 | T_0F | T_MUST_EVEX | T_N8 | T_ER_X) | (r.isREG(64) ? T_EW1 : T_EW0); opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, type, 0x79); UNIMPLEMENTED; }
void vcvtss2usi(const Reg32e& r, const Operand& op) { int type = (T_F3 | T_0F | T_MUST_EVEX | T_N4 | T_ER_X) | (r.isREG(64) ? T_EW1 : T_EW0); opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, type, 0x79); UNIMPLEMENTED; }
void vcvttpd2qq(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0x7A); UNIMPLEMENTED; }
void vcvttpd2udq(const Xmm& x, const Operand& op) { opCvt2(x, op, T_0F | T_YMM | T_MUST_EVEX | T_EW1 | T_B64 | T_SAE_Z, 0x78); UNIMPLEMENTED; }
void vcvttpd2uqq(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0x78); UNIMPLEMENTED; }
void vcvttps2qq(const Xmm& x, const Operand& op) { checkCvt1(x, op); opVex(x, 0, op, T_66 | T_0F | T_YMM | T_MUST_EVEX | T_EW0 | T_B32 | T_N8 | T_N_VL | T_SAE_Y, 0x7A); UNIMPLEMENTED; }
void vcvttps2udq(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_0F | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x78); UNIMPLEMENTED; }
void vcvttps2uqq(const Xmm& x, const Operand& op) { checkCvt1(x, op); opVex(x, 0, op, T_66 | T_0F | T_YMM | T_MUST_EVEX | T_EW0 | T_B32 | T_N8 | T_N_VL | T_SAE_Y, 0x78); UNIMPLEMENTED; }
void vcvttsd2usi(const Reg32e& r, const Operand& op) { int type = (T_F2 | T_0F | T_MUST_EVEX | T_N8 | T_SAE_X) | (r.isREG(64) ? T_EW1 : T_EW0); opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, type, 0x78); UNIMPLEMENTED; }
void vcvttss2usi(const Reg32e& r, const Operand& op) { int type = (T_F3 | T_0F | T_MUST_EVEX | T_N4 | T_SAE_X) | (r.isREG(64) ? T_EW1 : T_EW0); opAVX_X_X_XM(Xmm(r.getIdx()), xm0, op, type, 0x78); UNIMPLEMENTED; }
void vcvtudq2pd(const Xmm& x, const Operand& op) { checkCvt1(x, op); opVex(x, 0, op, T_F3 | T_0F | T_YMM | T_MUST_EVEX | T_EW0 | T_B32 | T_N8 | T_N_VL, 0x7A); UNIMPLEMENTED; }
void vcvtudq2ps(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_F2 | T_0F | T_EW0 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B32, 0x7A); UNIMPLEMENTED; }
void vcvtuqq2pd(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_F3 | T_0F | T_EW1 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B64, 0x7A); UNIMPLEMENTED; }
void vcvtuqq2ps(const Xmm& x, const Operand& op) { opCvt2(x, op, T_F2 | T_0F | T_YMM | T_MUST_EVEX | T_EW1 | T_B64 | T_ER_Z, 0x7A); UNIMPLEMENTED; }
void vcvtusi2sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opCvt3(x1, x2, op, T_F2 | T_0F | T_MUST_EVEX, T_W1 | T_EW1 | T_ER_X | T_N8, T_W0 | T_EW0 | T_N4, 0x7B); UNIMPLEMENTED; }
void vcvtusi2ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opCvt3(x1, x2, op, T_F3 | T_0F | T_MUST_EVEX | T_ER_X, T_W1 | T_EW1 | T_N8, T_W0 | T_EW0 | T_N4, 0x7B); UNIMPLEMENTED; }
void vdbpsadbw(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x42, imm); UNIMPLEMENTED; }
void vdpbf16ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_F3 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x52); UNIMPLEMENTED; }
void vexp2pd(const Zmm& z, const Operand& op) { opAVX_X_XM_IMM(z, op, T_66 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW1 | T_B64 | T_SAE_Z, 0xC8); UNIMPLEMENTED; }
void vexp2ps(const Zmm& z, const Operand& op) { opAVX_X_XM_IMM(z, op, T_66 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW0 | T_B32 | T_SAE_Z, 0xC8); UNIMPLEMENTED; }
void vexpandpd(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x88); UNIMPLEMENTED; }
void vexpandps(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x88); UNIMPLEMENTED; }
void vextractf32x4(const Operand& op, const Ymm& r, uint8 imm) { if (!op.is(Operand::MEM | Operand::XMM)) throw Error(ERR_BAD_COMBINATION); opVex(r, 0, op, T_N16 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x19, imm); UNIMPLEMENTED; }
void vextractf32x8(const Operand& op, const Zmm& r, uint8 imm) { if (!op.is(Operand::MEM | Operand::YMM)) throw Error(ERR_BAD_COMBINATION); opVex(r, 0, op, T_N32 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x1B, imm); UNIMPLEMENTED; }
void vextractf64x2(const Operand& op, const Ymm& r, uint8 imm) { if (!op.is(Operand::MEM | Operand::XMM)) throw Error(ERR_BAD_COMBINATION); opVex(r, 0, op, T_N16 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x19, imm); UNIMPLEMENTED; }
void vextractf64x4(const Operand& op, const Zmm& r, uint8 imm) { if (!op.is(Operand::MEM | Operand::YMM)) throw Error(ERR_BAD_COMBINATION); opVex(r, 0, op, T_N32 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x1B, imm); decodeAndTransToAArch64(); }
void vextracti32x4(const Operand& op, const Ymm& r, uint8 imm) { if (!op.is(Operand::MEM | Operand::XMM)) throw Error(ERR_BAD_COMBINATION); opVex(r, 0, op, T_N16 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x39, imm); UNIMPLEMENTED; }
void vextracti32x8(const Operand& op, const Zmm& r, uint8 imm) { if (!op.is(Operand::MEM | Operand::YMM)) throw Error(ERR_BAD_COMBINATION); opVex(r, 0, op, T_N32 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x3B, imm); decodeAndTransToAArch64(); }
void vextracti64x2(const Operand& op, const Ymm& r, uint8 imm) { if (!op.is(Operand::MEM | Operand::XMM)) throw Error(ERR_BAD_COMBINATION); opVex(r, 0, op, T_N16 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x39, imm); UNIMPLEMENTED; }
void vextracti64x4(const Operand& op, const Zmm& r, uint8 imm) { if (!op.is(Operand::MEM | Operand::YMM)) throw Error(ERR_BAD_COMBINATION); opVex(r, 0, op, T_N32 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x3B, imm); UNIMPLEMENTED; }
void vfixupimmpd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0x54, imm); UNIMPLEMENTED; }
void vfixupimmps(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x54, imm); UNIMPLEMENTED; }
void vfixupimmsd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F3A | T_EW1 | T_SAE_Z | T_MUST_EVEX, 0x55, imm); UNIMPLEMENTED; }
void vfixupimmss(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F3A | T_EW0 | T_SAE_Z | T_MUST_EVEX, 0x55, imm); UNIMPLEMENTED; }
void vfpclasspd(const Opmask& k, const Operand& op, uint8 imm) { if (!op.isBit(128|256|512)) throw Error(ERR_BAD_MEM_SIZE); opVex(k.changeBit(op.getBit()), 0, op, T_66 | T_0F3A | T_MUST_EVEX | T_YMM | T_EW1 | T_B64, 0x66, imm); UNIMPLEMENTED; }
void vfpclassps(const Opmask& k, const Operand& op, uint8 imm) { if (!op.isBit(128|256|512)) throw Error(ERR_BAD_MEM_SIZE); opVex(k.changeBit(op.getBit()), 0, op, T_66 | T_0F3A | T_MUST_EVEX | T_YMM | T_EW0 | T_B32, 0x66, imm); UNIMPLEMENTED; }
void vfpclasssd(const Opmask& k, const Operand& op, uint8 imm) { if (!op.isXMEM()) throw Error(ERR_BAD_MEM_SIZE); opVex(k, 0, op, T_66 | T_0F3A | T_MUST_EVEX | T_EW1 | T_N8, 0x67, imm); UNIMPLEMENTED; }
void vfpclassss(const Opmask& k, const Operand& op, uint8 imm) { if (!op.isXMEM()) throw Error(ERR_BAD_MEM_SIZE); opVex(k, 0, op, T_66 | T_0F3A | T_MUST_EVEX | T_EW0 | T_N4, 0x67, imm); UNIMPLEMENTED; }
void vgatherdpd(const Xmm& x, const Address& addr) { opGather2(x, addr, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_VSIB, 0x92, 1); UNIMPLEMENTED; }
void vgatherdps(const Xmm& x, const Address& addr) { opGather2(x, addr, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_VSIB, 0x92, 0); UNIMPLEMENTED; }
void vgatherpf0dpd(const Address& addr) { opGatherFetch(addr, zm1, T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC6, Operand::YMM); UNIMPLEMENTED; }
void vgatherpf0dps(const Address& addr) { opGatherFetch(addr, zm1, T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC6, Operand::ZMM); UNIMPLEMENTED; }
void vgatherpf0qpd(const Address& addr) { opGatherFetch(addr, zm1, T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC7, Operand::ZMM); UNIMPLEMENTED; }
void vgatherpf0qps(const Address& addr) { opGatherFetch(addr, zm1, T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC7, Operand::ZMM); UNIMPLEMENTED; }
void vgatherpf1dpd(const Address& addr) { opGatherFetch(addr, zm2, T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC6, Operand::YMM); UNIMPLEMENTED; }
void vgatherpf1dps(const Address& addr) { opGatherFetch(addr, zm2, T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC6, Operand::ZMM); UNIMPLEMENTED; }
void vgatherpf1qpd(const Address& addr) { opGatherFetch(addr, zm2, T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC7, Operand::ZMM); UNIMPLEMENTED; }
void vgatherpf1qps(const Address& addr) { opGatherFetch(addr, zm2, T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC7, Operand::ZMM); UNIMPLEMENTED; }
void vgatherqpd(const Xmm& x, const Address& addr) { opGather2(x, addr, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_VSIB, 0x93, 0); UNIMPLEMENTED; }
void vgatherqps(const Xmm& x, const Address& addr) { opGather2(x, addr, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_VSIB, 0x93, 2); decodeAndTransToAArch64(); }
void vgetexppd(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0x42); UNIMPLEMENTED; }
void vgetexpps(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x42); UNIMPLEMENTED; }
void vgetexpsd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_SAE_X | T_MUST_EVEX, 0x43); UNIMPLEMENTED; }
void vgetexpss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_SAE_X | T_MUST_EVEX, 0x43); UNIMPLEMENTED; }
void vgetmantpd(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(x, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0x26, imm); UNIMPLEMENTED; }
void vgetmantps(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(x, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x26, imm); UNIMPLEMENTED; }
void vgetmantsd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F3A | T_EW1 | T_SAE_X | T_MUST_EVEX, 0x27, imm); UNIMPLEMENTED; }
void vgetmantss(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F3A | T_EW0 | T_SAE_X | T_MUST_EVEX, 0x27, imm); UNIMPLEMENTED; }
void vinsertf32x4(const Ymm& r1, const Ymm& r2, const Operand& op, uint8 imm) {if (!(r1.getKind() == r2.getKind() && op.is(Operand::MEM | Operand::XMM))) throw Error(ERR_BAD_COMBINATION); opVex(r1, &r2, op, T_N16 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x18, imm); UNIMPLEMENTED; }
void vinsertf32x8(const Zmm& r1, const Zmm& r2, const Operand& op, uint8 imm) {if (!op.is(Operand::MEM | Operand::YMM)) throw Error(ERR_BAD_COMBINATION); opVex(r1, &r2, op, T_N32 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x1A, imm); UNIMPLEMENTED; }
void vinsertf64x2(const Ymm& r1, const Ymm& r2, const Operand& op, uint8 imm) {if (!(r1.getKind() == r2.getKind() && op.is(Operand::MEM | Operand::XMM))) throw Error(ERR_BAD_COMBINATION); opVex(r1, &r2, op, T_N16 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x18, imm); UNIMPLEMENTED; }
void vinsertf64x4(const Zmm& r1, const Zmm& r2, const Operand& op, uint8 imm) {if (!op.is(Operand::MEM | Operand::YMM)) throw Error(ERR_BAD_COMBINATION); opVex(r1, &r2, op, T_N32 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x1A, imm); decodeAndTransToAArch64(); }
void vinserti32x4(const Ymm& r1, const Ymm& r2, const Operand& op, uint8 imm) {if (!(r1.getKind() == r2.getKind() && op.is(Operand::MEM | Operand::XMM))) throw Error(ERR_BAD_COMBINATION); opVex(r1, &r2, op, T_N16 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x38, imm); decodeAndTransToAArch64(); }
void vinserti32x8(const Zmm& r1, const Zmm& r2, const Operand& op, uint8 imm) {if (!op.is(Operand::MEM | Operand::YMM)) throw Error(ERR_BAD_COMBINATION); opVex(r1, &r2, op, T_N32 | T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x3A, imm); UNIMPLEMENTED; }
void vinserti64x2(const Ymm& r1, const Ymm& r2, const Operand& op, uint8 imm) {if (!(r1.getKind() == r2.getKind() && op.is(Operand::MEM | Operand::XMM))) throw Error(ERR_BAD_COMBINATION); opVex(r1, &r2, op, T_N16 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x38, imm); UNIMPLEMENTED; }
void vinserti64x4(const Zmm& r1, const Zmm& r2, const Operand& op, uint8 imm) {if (!op.is(Operand::MEM | Operand::YMM)) throw Error(ERR_BAD_COMBINATION); opVex(r1, &r2, op, T_N32 | T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x3A, imm); decodeAndTransToAArch64(); }
void vmovdqa32(const Address& addr, const Xmm& x) { opAVX_X_XM_IMM(x, addr, T_66 | T_0F | T_EW0 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z | T_MUST_EVEX | T_M_K, 0x7F); UNIMPLEMENTED; }
void vmovdqa32(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F | T_EW0 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z | T_MUST_EVEX, 0x6F); UNIMPLEMENTED; }
void vmovdqa64(const Address& addr, const Xmm& x) { opAVX_X_XM_IMM(x, addr, T_66 | T_0F | T_EW1 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z | T_MUST_EVEX | T_M_K, 0x7F); UNIMPLEMENTED; }
void vmovdqa64(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F | T_EW1 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z | T_MUST_EVEX, 0x6F); UNIMPLEMENTED; }
void vmovdqu16(const Address& addr, const Xmm& x) { opAVX_X_XM_IMM(x, addr, T_F2 | T_0F | T_EW1 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z | T_MUST_EVEX | T_M_K, 0x7F); decodeAndTransToAArch64(); }
void vmovdqu16(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_F2 | T_0F | T_EW1 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z | T_MUST_EVEX, 0x6F); decodeAndTransToAArch64(); }
void vmovdqu32(const Address& addr, const Xmm& x) { opAVX_X_XM_IMM(x, addr, T_F3 | T_0F | T_EW0 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z | T_MUST_EVEX | T_M_K, 0x7F); decodeAndTransToAArch64(); }
void vmovdqu32(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_F3 | T_0F | T_EW0 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z | T_MUST_EVEX, 0x6F); decodeAndTransToAArch64(); }
void vmovdqu64(const Address& addr, const Xmm& x) { opAVX_X_XM_IMM(x, addr, T_F3 | T_0F | T_EW1 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z | T_MUST_EVEX | T_M_K, 0x7F); UNIMPLEMENTED; }
void vmovdqu64(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_F3 | T_0F | T_EW1 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z | T_MUST_EVEX, 0x6F); UNIMPLEMENTED; }
void vmovdqu8(const Address& addr, const Xmm& x) { opAVX_X_XM_IMM(x, addr, T_F2 | T_0F | T_EW0 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z | T_MUST_EVEX | T_M_K, 0x7F); decodeAndTransToAArch64(); }
void vmovdqu8(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_F2 | T_0F | T_EW0 | T_YMM | T_ER_X | T_ER_Y | T_ER_Z | T_MUST_EVEX, 0x6F); decodeAndTransToAArch64(); }
void vp2intersectd(const Opmask& k, const Xmm& x, const Operand& op) { if (k.getOpmaskIdx() != 0) throw Error(ERR_OPMASK_IS_ALREADY_SET); opAVX_K_X_XM(k, x, op, T_F2 | T_0F38 | T_YMM | T_EVEX | T_EW0 | T_B32, 0x68); UNIMPLEMENTED; }
void vp2intersectq(const Opmask& k, const Xmm& x, const Operand& op) { if (k.getOpmaskIdx() != 0) throw Error(ERR_OPMASK_IS_ALREADY_SET); opAVX_K_X_XM(k, x, op, T_F2 | T_0F38 | T_YMM | T_EVEX | T_EW1 | T_B64, 0x68); UNIMPLEMENTED; }
void vp4dpwssd(const Zmm& z1, const Zmm& z2, const Address& addr) { opAVX_X_X_XM(z1, z2, addr, T_0F38 | T_F2 | T_EW0 | T_YMM | T_MUST_EVEX | T_N16, 0x52); UNIMPLEMENTED; }
void vp4dpwssds(const Zmm& z1, const Zmm& z2, const Address& addr) { opAVX_X_X_XM(z1, z2, addr, T_0F38 | T_F2 | T_EW0 | T_YMM | T_MUST_EVEX | T_N16, 0x53); UNIMPLEMENTED; }
void vpabsq(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_MUST_EVEX | T_EW1 | T_B64 | T_YMM, 0x1F); UNIMPLEMENTED; }
void vpandd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0xDB); decodeAndTransToAArch64(); }
void vpandnd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0xDF); UNIMPLEMENTED; }
void vpandnq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0xDF); UNIMPLEMENTED; }
void vpandq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0xDB); UNIMPLEMENTED; }
void vpblendmb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x66); decodeAndTransToAArch64(); }
void vpblendmd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x64); decodeAndTransToAArch64(); }
void vpblendmq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x64); UNIMPLEMENTED; }
void vpblendmw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x66); UNIMPLEMENTED; }
void vpbroadcastb(const Xmm& x, const Reg8& r) { opVex(x, 0, r, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x7A); decodeAndTransToAArch64(); }
void vpbroadcastd(const Xmm& x, const Reg32& r) { opVex(x, 0, r, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x7C); decodeAndTransToAArch64(); }
void vpbroadcastmb2q(const Xmm& x, const Opmask& k) { opVex(x, 0, k, T_F3 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW1, 0x2A); UNIMPLEMENTED; }
void vpbroadcastmw2d(const Xmm& x, const Opmask& k) { opVex(x, 0, k, T_F3 | T_0F38 | T_YMM | T_MUST_EVEX | T_EW0, 0x3A); UNIMPLEMENTED; }
void vpbroadcastw(const Xmm& x, const Reg16& r) { opVex(x, 0, r, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x7B); decodeAndTransToAArch64(); }
void vpcmpb(const Opmask& k, const Xmm& x, const Operand& op, uint8 imm) { opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x3F, imm); decodeAndTransToAArch64(); }
void vpcmpd(const Opmask& k, const Xmm& x, const Operand& op, uint8 imm) { opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x1F, imm); decodeAndTransToAArch64(); }
void vpcmpeqb(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_66 | T_0F | T_YMM | T_MUST_EVEX, 0x74); UNIMPLEMENTED; }
void vpcmpeqd(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_66 | T_0F | T_YMM | T_MUST_EVEX | T_B32, 0x76); decodeAndTransToAArch64(); }
void vpcmpeqq(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x29); UNIMPLEMENTED; }
void vpcmpeqw(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_66 | T_0F | T_YMM | T_MUST_EVEX, 0x75); UNIMPLEMENTED; }
void vpcmpgtb(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_66 | T_0F | T_YMM | T_MUST_EVEX, 0x64); UNIMPLEMENTED; }
void vpcmpgtd(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_66 | T_0F | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x66); UNIMPLEMENTED; }
void vpcmpgtq(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x37); UNIMPLEMENTED; }
void vpcmpgtw(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_66 | T_0F | T_YMM | T_MUST_EVEX, 0x65); UNIMPLEMENTED; }
void vpcmpq(const Opmask& k, const Xmm& x, const Operand& op, uint8 imm) { opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x1F, imm); UNIMPLEMENTED; }
void vpcmpub(const Opmask& k, const Xmm& x, const Operand& op, uint8 imm) { opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX, 0x3E, imm); decodeAndTransToAArch64(); }
void vpcmpud(const Opmask& k, const Xmm& x, const Operand& op, uint8 imm) { opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x1E, imm); UNIMPLEMENTED; }
void vpcmpuq(const Opmask& k, const Xmm& x, const Operand& op, uint8 imm) { opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x1E, imm); UNIMPLEMENTED; }
void vpcmpuw(const Opmask& k, const Xmm& x, const Operand& op, uint8 imm) { opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x3E, imm); UNIMPLEMENTED; }
void vpcmpw(const Opmask& k, const Xmm& x, const Operand& op, uint8 imm) { opAVX_K_X_XM(k, x, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX, 0x3F, imm); UNIMPLEMENTED; }
void vpcompressd(const Operand& op, const Xmm& x) { opAVX_X_XM_IMM(x, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x8B); UNIMPLEMENTED; }
void vpcompressq(const Operand& op, const Xmm& x) { opAVX_X_XM_IMM(x, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x8B); UNIMPLEMENTED; }
void vpconflictd(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0xC4); UNIMPLEMENTED; }
void vpconflictq(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0xC4); UNIMPLEMENTED; }
void vpdpbusd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x50); UNIMPLEMENTED; }
void vpdpbusds(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x51); UNIMPLEMENTED; }
void vpdpwssd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x52); UNIMPLEMENTED; }
void vpdpwssds(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x53); UNIMPLEMENTED; }
void vpermb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x8D); UNIMPLEMENTED; }
void vpermi2b(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x75); UNIMPLEMENTED; }
void vpermi2d(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x76); UNIMPLEMENTED; }
void vpermi2pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x77); UNIMPLEMENTED; }
void vpermi2ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x77); UNIMPLEMENTED; }
void vpermi2q(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x76); UNIMPLEMENTED; }
void vpermi2w(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x75); UNIMPLEMENTED; }
void vpermt2b(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x7D); UNIMPLEMENTED; }
void vpermt2d(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x7E); UNIMPLEMENTED; }
void vpermt2pd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x7F); UNIMPLEMENTED; }
void vpermt2ps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x7F); UNIMPLEMENTED; }
void vpermt2q(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x7E); UNIMPLEMENTED; }
void vpermt2w(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x7D); UNIMPLEMENTED; }
void vpermw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x8D); decodeAndTransToAArch64(); }
void vpexpandb(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_N1 | T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX, 0x62); UNIMPLEMENTED; }
void vpexpandd(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x89); UNIMPLEMENTED; }
void vpexpandq(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x89); UNIMPLEMENTED; }
void vpexpandw(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_N2 | T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX, 0x62); UNIMPLEMENTED; }
void vpgatherdd(const Xmm& x, const Address& addr) { opGather2(x, addr, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_VSIB, 0x90, 0); UNIMPLEMENTED; }
void vpgatherdq(const Xmm& x, const Address& addr) { opGather2(x, addr, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_VSIB, 0x90, 1); UNIMPLEMENTED; }
void vpgatherqd(const Xmm& x, const Address& addr) { opGather2(x, addr, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_VSIB, 0x91, 2); UNIMPLEMENTED; }
void vpgatherqq(const Xmm& x, const Address& addr) { opGather2(x, addr, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_VSIB, 0x91, 0); UNIMPLEMENTED; }
void vplzcntd(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x44); UNIMPLEMENTED; }
void vplzcntq(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x44); UNIMPLEMENTED; }
void vpmadd52huq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0xB5); UNIMPLEMENTED; }
void vpmadd52luq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0xB4); UNIMPLEMENTED; }
void vpmaxsq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x3D); UNIMPLEMENTED; }
void vpmaxuq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x3F); UNIMPLEMENTED; }
void vpminsq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x39); UNIMPLEMENTED; }
void vpminuq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x3B); UNIMPLEMENTED; }
void vpmovb2m(const Opmask& k, const Xmm& x) { opVex(k, 0, x, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW0, 0x29); UNIMPLEMENTED; }
void vpmovd2m(const Opmask& k, const Xmm& x) { opVex(k, 0, x, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW0, 0x39); UNIMPLEMENTED; }
void vpmovdb(const Operand& op, const Xmm& x) { opVmov(op, x, T_N4 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x31, false); decodeAndTransToAArch64(); }
void vpmovdw(const Operand& op, const Xmm& x) { opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x33, true); decodeAndTransToAArch64(); }
void vpmovm2b(const Xmm& x, const Opmask& k) { opVex(x, 0, k, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW0, 0x28); UNIMPLEMENTED; }
void vpmovm2d(const Xmm& x, const Opmask& k) { opVex(x, 0, k, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW0, 0x38); UNIMPLEMENTED; }
void vpmovm2q(const Xmm& x, const Opmask& k) { opVex(x, 0, k, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW1, 0x38); UNIMPLEMENTED; }
void vpmovm2w(const Xmm& x, const Opmask& k) { opVex(x, 0, k, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW1, 0x28); UNIMPLEMENTED; }
void vpmovq2m(const Opmask& k, const Xmm& x) { opVex(k, 0, x, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW1, 0x39); UNIMPLEMENTED; }
void vpmovqb(const Operand& op, const Xmm& x) { opVmov(op, x, T_N2 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x32, false); UNIMPLEMENTED; }
void vpmovqd(const Operand& op, const Xmm& x) { opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x35, true); UNIMPLEMENTED; }
void vpmovqw(const Operand& op, const Xmm& x) { opVmov(op, x, T_N4 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x34, false); UNIMPLEMENTED; }
void vpmovsdb(const Operand& op, const Xmm& x) { opVmov(op, x, T_N4 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x21, false); decodeAndTransToAArch64(); }
void vpmovsdw(const Operand& op, const Xmm& x) { opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x23, true); UNIMPLEMENTED; }
void vpmovsqb(const Operand& op, const Xmm& x) { opVmov(op, x, T_N2 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x22, false); UNIMPLEMENTED; }
void vpmovsqd(const Operand& op, const Xmm& x) { opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x25, true); UNIMPLEMENTED; }
void vpmovsqw(const Operand& op, const Xmm& x) { opVmov(op, x, T_N4 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x24, false); UNIMPLEMENTED; }
void vpmovswb(const Operand& op, const Xmm& x) { opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x20, true); UNIMPLEMENTED; }
void vpmovusdb(const Operand& op, const Xmm& x) { opVmov(op, x, T_N4 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x11, false); decodeAndTransToAArch64(); }
void vpmovusdw(const Operand& op, const Xmm& x) { opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x13, true); UNIMPLEMENTED; }
void vpmovusqb(const Operand& op, const Xmm& x) { opVmov(op, x, T_N2 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x12, false); UNIMPLEMENTED; }
void vpmovusqd(const Operand& op, const Xmm& x) { opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x15, true); UNIMPLEMENTED; }
void vpmovusqw(const Operand& op, const Xmm& x) { opVmov(op, x, T_N4 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x14, false); UNIMPLEMENTED; }
void vpmovuswb(const Operand& op, const Xmm& x) { opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x10, true); UNIMPLEMENTED; }
void vpmovw2m(const Opmask& k, const Xmm& x) { opVex(k, 0, x, T_F3 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW1, 0x29); UNIMPLEMENTED; }
void vpmovwb(const Operand& op, const Xmm& x) { opVmov(op, x, T_N8 | T_N_VL | T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x30, true); UNIMPLEMENTED; }
void vpmullq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x40); UNIMPLEMENTED; }
void vpmultishiftqb(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x83); UNIMPLEMENTED; }
void vpopcntb(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX, 0x54); UNIMPLEMENTED; }
void vpopcntd(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x55); UNIMPLEMENTED; }
void vpopcntq(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0x55); UNIMPLEMENTED; }
void vpopcntw(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX, 0x54); UNIMPLEMENTED; }
void vpord(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0xEB); decodeAndTransToAArch64(); }
void vporq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0xEB); UNIMPLEMENTED; }
void vprold(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 1), x, op, T_66 | T_0F | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x72, imm); UNIMPLEMENTED; }
void vprolq(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 1), x, op, T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x72, imm); UNIMPLEMENTED; }
void vprolvd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x15); UNIMPLEMENTED; }
void vprolvq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x15); UNIMPLEMENTED; }
void vprord(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 0), x, op, T_66 | T_0F | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x72, imm); UNIMPLEMENTED; }
void vprorq(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 0), x, op, T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x72, imm); UNIMPLEMENTED; }
void vprorvd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x14); UNIMPLEMENTED; }
void vprorvq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x14); UNIMPLEMENTED; }
void vpscatterdd(const Address& addr, const Xmm& x) { opGather2(x, addr, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB, 0xA0, 0); UNIMPLEMENTED; }
void vpscatterdq(const Address& addr, const Xmm& x) { opGather2(x, addr, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB, 0xA0, 1); UNIMPLEMENTED; }
void vpscatterqd(const Address& addr, const Xmm& x) { opGather2(x, addr, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB, 0xA1, 2); UNIMPLEMENTED; }
void vpscatterqq(const Address& addr, const Xmm& x) { opGather2(x, addr, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB, 0xA1, 0); UNIMPLEMENTED; }
void vpshldd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x71, imm); UNIMPLEMENTED; }
void vpshldq(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0x71, imm); UNIMPLEMENTED; }
void vpshldvd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x71); UNIMPLEMENTED; }
void vpshldvq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0x71); UNIMPLEMENTED; }
void vpshldvw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX, 0x70); UNIMPLEMENTED; }
void vpshldw(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX, 0x70, imm); UNIMPLEMENTED; }
void vpshrdd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x73, imm); UNIMPLEMENTED; }
void vpshrdq(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0x73, imm); UNIMPLEMENTED; }
void vpshrdvd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x73); UNIMPLEMENTED; }
void vpshrdvq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0x73); UNIMPLEMENTED; }
void vpshrdvw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX, 0x72); UNIMPLEMENTED; }
void vpshrdw(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX, 0x72, imm); UNIMPLEMENTED; }
void vpshufbitqmb(const Opmask& k, const Xmm& x, const Operand& op) { opVex(k, &x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x8F); UNIMPLEMENTED; }
void vpsllvw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x12); UNIMPLEMENTED; }
void vpsraq(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_X_XM(Xmm(x.getKind(), 4), x, op, T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x72, imm); UNIMPLEMENTED; }
void vpsraq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N16 | T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX, 0xE2); UNIMPLEMENTED; }
void vpsravq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x46); UNIMPLEMENTED; }
void vpsravw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x11); UNIMPLEMENTED; }
void vpsrlvw(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x10); UNIMPLEMENTED; }
void vpternlogd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x25, imm); UNIMPLEMENTED; }
void vpternlogq(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x25, imm); UNIMPLEMENTED; }
void vptestmb(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x26); UNIMPLEMENTED; }
void vptestmd(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x27); UNIMPLEMENTED; }
void vptestmq(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x27); UNIMPLEMENTED; }
void vptestmw(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x26); UNIMPLEMENTED; }
void vptestnmb(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x26); UNIMPLEMENTED; }
void vptestnmd(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_F3 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x27); UNIMPLEMENTED; }
void vptestnmq(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_F3 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x27); UNIMPLEMENTED; }
void vptestnmw(const Opmask& k, const Xmm& x, const Operand& op) { opAVX_K_X_XM(k, x, op, T_F3 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x26); UNIMPLEMENTED; }
void vpxord(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0xEF); decodeAndTransToAArch64(); }
void vpxorq(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0xEF); decodeAndTransToAArch64(); }
void vrangepd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0x50, imm); UNIMPLEMENTED; }
void vrangeps(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x50, imm); UNIMPLEMENTED; }
void vrangesd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F3A | T_EW1 | T_SAE_X | T_MUST_EVEX, 0x51, imm); UNIMPLEMENTED; }
void vrangess(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F3A | T_EW0 | T_SAE_X | T_MUST_EVEX, 0x51, imm); UNIMPLEMENTED; }
void vrcp14pd(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x4C); UNIMPLEMENTED; }
void vrcp14ps(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x4C); UNIMPLEMENTED; }
void vrcp14sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX, 0x4D); UNIMPLEMENTED; }
void vrcp14ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX, 0x4D); UNIMPLEMENTED; }
void vrcp28pd(const Zmm& z, const Operand& op) { opAVX_X_XM_IMM(z, op, T_66 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW1 | T_B64 | T_SAE_Z, 0xCA); UNIMPLEMENTED; }
void vrcp28ps(const Zmm& z, const Operand& op) { opAVX_X_XM_IMM(z, op, T_66 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW0 | T_B32 | T_SAE_Z, 0xCA); UNIMPLEMENTED; }
void vrcp28sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_SAE_X | T_MUST_EVEX, 0xCB); UNIMPLEMENTED; }
void vrcp28ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_SAE_X | T_MUST_EVEX, 0xCB); UNIMPLEMENTED; }
void vreducepd(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(x, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B64, 0x56, imm); UNIMPLEMENTED; }
void vreduceps(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(x, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_SAE_Z | T_MUST_EVEX | T_B32, 0x56, imm); UNIMPLEMENTED; }
void vreducesd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F3A | T_EW1 | T_SAE_X | T_MUST_EVEX, 0x57, imm); UNIMPLEMENTED; }
void vreducess(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F3A | T_EW0 | T_SAE_X | T_MUST_EVEX, 0x57, imm); UNIMPLEMENTED; }
void vrndscalepd(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(x, op, T_66 | T_0F3A | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x09, imm); UNIMPLEMENTED; }
void vrndscaleps(const Xmm& x, const Operand& op, uint8 imm) { opAVX_X_XM_IMM(x, op, T_66 | T_0F3A | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x08, imm); UNIMPLEMENTED; }
void vrndscalesd(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F3A | T_EW1 | T_MUST_EVEX, 0x0B, imm); UNIMPLEMENTED; }
void vrndscaless(const Xmm& x1, const Xmm& x2, const Operand& op, uint8 imm) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F3A | T_EW0 | T_MUST_EVEX, 0x0A, imm); UNIMPLEMENTED; }
void vrsqrt14pd(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_B64, 0x4E); UNIMPLEMENTED; }
void vrsqrt14ps(const Xmm& x, const Operand& op) { opAVX_X_XM_IMM(x, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_B32, 0x4E); UNIMPLEMENTED; }
void vrsqrt14sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x4F); UNIMPLEMENTED; }
void vrsqrt14ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX, 0x4F); UNIMPLEMENTED; }
void vrsqrt28pd(const Zmm& z, const Operand& op) { opAVX_X_XM_IMM(z, op, T_66 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW1 | T_B64 | T_SAE_Z, 0xCC); UNIMPLEMENTED; }
void vrsqrt28ps(const Zmm& z, const Operand& op) { opAVX_X_XM_IMM(z, op, T_66 | T_0F38 | T_MUST_EVEX | T_YMM | T_EW0 | T_B32 | T_SAE_Z, 0xCC); UNIMPLEMENTED; }
void vrsqrt28sd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_SAE_X | T_MUST_EVEX, 0xCD); UNIMPLEMENTED; }
void vrsqrt28ss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_SAE_X | T_MUST_EVEX, 0xCD); UNIMPLEMENTED; }
void vscalefpd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW1 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B64, 0x2C); UNIMPLEMENTED; }
void vscalefps(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_66 | T_0F38 | T_EW0 | T_YMM | T_ER_Z | T_MUST_EVEX | T_B32, 0x2C); UNIMPLEMENTED; }
void vscalefsd(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N8 | T_66 | T_0F38 | T_EW1 | T_ER_X | T_MUST_EVEX, 0x2D); UNIMPLEMENTED; }
void vscalefss(const Xmm& x1, const Xmm& x2, const Operand& op) { opAVX_X_X_XM(x1, x2, op, T_N4 | T_66 | T_0F38 | T_EW0 | T_ER_X | T_MUST_EVEX, 0x2D); UNIMPLEMENTED; }
void vscatterdpd(const Address& addr, const Xmm& x) { opGather2(x, addr, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB, 0xA2, 1); UNIMPLEMENTED; }
void vscatterdps(const Address& addr, const Xmm& x) { opGather2(x, addr, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB, 0xA2, 0); UNIMPLEMENTED; }
void vscatterpf0dpd(const Address& addr) { opGatherFetch(addr, zm5, T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC6, Operand::YMM); UNIMPLEMENTED; }
void vscatterpf0dps(const Address& addr) { opGatherFetch(addr, zm5, T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC6, Operand::ZMM); UNIMPLEMENTED; }
void vscatterpf0qpd(const Address& addr) { opGatherFetch(addr, zm5, T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC7, Operand::ZMM); UNIMPLEMENTED; }
void vscatterpf0qps(const Address& addr) { opGatherFetch(addr, zm5, T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC7, Operand::ZMM); UNIMPLEMENTED; }
void vscatterpf1dpd(const Address& addr) { opGatherFetch(addr, zm6, T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC6, Operand::YMM); UNIMPLEMENTED; }
void vscatterpf1dps(const Address& addr) { opGatherFetch(addr, zm6, T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC6, Operand::ZMM); UNIMPLEMENTED; }
void vscatterpf1qpd(const Address& addr) { opGatherFetch(addr, zm6, T_N8 | T_66 | T_0F38 | T_EW1 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC7, Operand::ZMM); UNIMPLEMENTED; }
void vscatterpf1qps(const Address& addr) { opGatherFetch(addr, zm6, T_N4 | T_66 | T_0F38 | T_EW0 | T_MUST_EVEX | T_M_K | T_VSIB, 0xC7, Operand::ZMM); UNIMPLEMENTED; }
void vscatterqpd(const Address& addr, const Xmm& x) { opGather2(x, addr, T_N8 | T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB, 0xA3, 0); UNIMPLEMENTED; }
void vscatterqps(const Address& addr, const Xmm& x) { opGather2(x, addr, T_N4 | T_66 | T_0F38 | T_EW0 | T_YMM | T_MUST_EVEX | T_M_K | T_VSIB, 0xA3, 2); UNIMPLEMENTED; }
void vshuff32x4(const Ymm& y1, const Ymm& y2, const Operand& op, uint8 imm) { opAVX_X_X_XM(y1, y2, op, T_66 | T_0F3A | T_YMM | T_MUST_EVEX | T_EW0 | T_B32, 0x23, imm);decodeAndTransToAArch64(); }
void vshuff64x2(const Ymm& y1, const Ymm& y2, const Operand& op, uint8 imm) { opAVX_X_X_XM(y1, y2, op, T_66 | T_0F3A | T_YMM | T_MUST_EVEX | T_EW1 | T_B64, 0x23, imm); decodeAndTransToAArch64(); }
void vshufi32x4(const Ymm& y1, const Ymm& y2, const Operand& op, uint8 imm) { opAVX_X_X_XM(y1, y2, op, T_66 | T_0F3A | T_YMM | T_MUST_EVEX | T_EW0 | T_B32, 0x43, imm); decodeAndTransToAArch64(); }
void vshufi64x2(const Ymm& y1, const Ymm& y2, const Operand& op, uint8 imm) { opAVX_X_X_XM(y1, y2, op, T_66 | T_0F3A | T_YMM | T_MUST_EVEX | T_EW1 | T_B64, 0x43, imm); UNIMPLEMENTED; }
#ifdef XBYAK64
void kmovq(const Opmask& k, const Reg64& r) { opVex(k, 0, r, T_L0 | T_0F | T_F2 | T_W1, 0x92); decodeAndTransToAArch64();}
void kmovq(const Reg64& r, const Opmask& k) { opVex(r, 0, k, T_L0 | T_0F | T_F2 | T_W1, 0x93); decodeAndTransToAArch64(); }
void vpbroadcastq(const Xmm& x, const Reg64& r) { opVex(x, 0, r, T_66 | T_0F38 | T_EW1 | T_YMM | T_MUST_EVEX, 0x7C); decodeAndTransToAArch64(); }
#endif
#endif
