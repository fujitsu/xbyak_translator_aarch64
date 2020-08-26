/*******************************************************************************
 * Copyright 2020 FUJITSU LIMITED
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
#include "test_generator2.h"

class TestPtnGenerator : public TestGenerator {
public:
  void setInitialRegValue() {
    /* Here modify arrays of inputGenReg, inputPredReg, inputZReg */
    setInputZregAllRandomHex();
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12,
       r13, r14, r15 */

    size_t addr;

    /* Address is aligned */
    addr = reinterpret_cast<size_t>(&(inputZReg[0].ud_dt[0]));
    std::cout << "Address is " << std::hex << addr << std::endl;

    mov(r15, std::numeric_limits<int64_t>::max());
    mov(r14, std::numeric_limits<int64_t>::min());
    xor_(r13, r13);
    mov(r12, std::numeric_limits<uint64_t>::max());
    mov(r11, std::numeric_limits<uint64_t>::min());

    std::vector<Reg64> regs = {r15, r14, r13, r12, r11};
    //    std::vector<Reg64> regs = {r15};
#ifdef XBYAK_TRANSLATE_AARCH64
    Xbyak_aarch64::XReg x_of{x7};
    Xbyak_aarch64::XReg x_sf{x6};
    Xbyak_aarch64::XReg x_zf{x5};
    Xbyak_aarch64::XReg x_cf{x3};
    Xbyak_aarch64::XReg x_addr{x2};
    Xbyak_aarch64::XReg x_tmpAddr{x1};
    Xbyak_aarch64::XReg x_tmpFlag{x0};
    Xbyak_aarch64::XReg x_dummyFlag{x10};

    xa_->mov_imm(x_of, 1 << 11);
    xa_->mov_imm(x_sf, 1 << 7);
    xa_->mov_imm(x_zf, 1 << 6);
    xa_->mov_imm(x_cf, 1 << 0);
    Reg64 r_addr{rdx};
    Reg64 r_tmpAddr{rcx};
#else  //#ifdef XBYAK_TRANSLATE_AARCH64
    Reg64 r_of{rdi};
    Reg64 r_sf{rsi};
    Reg64 r_zf{rbp};
    Reg64 r_cf{rbx};
    Reg64 r_addr{rdx};
    Reg64 r_tmpAddr{rcx};
    Reg64 r_tmpFlag{rax};
    Reg64 r_flagMask{r8};

    /* x86_64 eflags
       11:OF(overflow),
       7:SF(sign),
       6:ZF(zero),
       0:CF(carry) */
    mov(r_flagMask, 0x8c1);
    mov(r_of, 1 << 11);
    mov(r_sf, 1 << 7);
    mov(r_zf, 1 << 6);
    mov(r_cf, 1 << 0);
#endif //#ifdef XBYAK_TRANSLATE_AARCH64

    for (unsigned int j = 0; j < regs.size(); j++) {
      addr = reinterpret_cast<size_t>(&(inputZReg[j].ud_dt[0]));
      mov(r_addr, addr);
      mov(r_tmpAddr, r_addr);

      for (const auto &i : regs) {
        xor_(rax, rax); // clear rax
        test(regs[j], i);
#ifdef XBYAK_TRANSLATE_AARCH64
        mrs(x_tmpFlag, 0x3, 0x3, 0x4, 0x2, 0x0); // Read NZCV register
        lsr(x_tmpFlag, x_tmpFlag, 28);

#if 0
	xa_->mov(x_dummyFlag, x_tmpFlag);
#else
        /* aarch64 flag order
           Negative:sign,
           Zero,
           Carry (something differenct from x86_64 CF),
           oVerflow */

        Xbyak_aarch64::LabelAArch64 L0, L1, L2, L3, L4;

        xa_->mov(x_dummyFlag, 0);

        /* (x86_64's CF)
           aarch64's ((V==1 &&C==0) || (V==0 && C==0)) */
        xa_->and_(X_TMP_0, x_tmpFlag,
                                   0x2);         // extract C
        xa_->cmp(X_TMP_0, 0x2); // Check if C==1
        xa_->b(Xbyak_aarch64::NE, L0);
        xa_->orr(x_dummyFlag, x_dummyFlag,
                                  x_cf); // Set x86_64's CF flag
        L_aarch64(L0);

        xa_->and_(X_TMP_0, x_tmpFlag, 0x4); // extract Z flag
        xa_->cmp(X_TMP_0, 0x4);             // Check if (Z==1)
        xa_->b(Xbyak_aarch64::NE, L2);
        xa_->orr(x_dummyFlag, x_dummyFlag,
                                  x_zf); // Set x86_64's ZF flag
        L_aarch64(L2);

        xa_->and_(X_TMP_0, x_tmpFlag, 0x8); // extract N flag
        xa_->cmp(X_TMP_0, 0x8);             // Check if (N==1)
        xa_->b(Xbyak_aarch64::NE, L3);
        xa_->orr(x_dummyFlag, x_dummyFlag,
                                  x_sf); // Set x86_64's SF flag
        L_aarch64(L3);

        xa_->and_(X_TMP_0, x_tmpFlag, 0x1); // extract V flag
        xa_->cmp(X_TMP_0, 0x1);             // Check if (V==1)
        xa_->b(Xbyak_aarch64::NE, L4);
        xa_->orr(x_dummyFlag, x_dummyFlag,
                                  x_of); // Set x86_64's OF flag
        L_aarch64(L4);
#endif

        xa_->str(x_dummyFlag, Xbyak_aarch64::ptr(x_tmpAddr));
        xa_->add(x_tmpAddr, x_tmpAddr, 8);
#else  //#ifdef XBYAK_TRANSLATE_AARCH64
        pushf();        // eflags is stored on statck.
        pop(r_tmpFlag); // eflags is read from stack.
        and_(r_tmpFlag, r_flagMask);
        mov(ptr[r_tmpAddr], r_tmpFlag); // store eflags
        add(r_tmpAddr, 8);
#endif //#ifdef XBYAK_TRANSLATE_AARCH64
      }
#ifdef XBYAK_TRANSLATE_AARCH64
      ldr(Xbyak_aarch64::ZReg(j), Xbyak_aarch64::ptr(x_addr));
#else
      vmovdqu64(Zmm(j), ptr[r_addr]);
#endif
    }

    mov(rax, 5);
    mov(rcx, 5);
    mov(rdx, 5);
    mov(rbp, 5);
    mov(rsi, 5);
    mov(r8, 5);
    mov(r9, 5);
    mov(r10, 5);
  }
};

int main(int argc, char *argv[]) {
  /* Initializing arrays of inputData, inputGenReg, inputPredReg, inputZReg,
   * checkGenRegMode, checkPredRegMode,checkZRegMode */
  TestPtnGenerator gen;

  /* Set bool output_jit_on_, bool exec_jit_on_ = 0; */
  gen.parseArgs(argc, argv);

  /* Generate JIT code and get function pointer */
  void (*f)();
  if (gen.isOutputJitOn()) {
    f = (void (*)())gen.gen();
  }

  /* Dump generated JIT code to a binary file */
  gen.dumpJitCode();

  /* 1:Execute JIT code, 2:dump all register values, 3:dump register values to
   * be checked */
  if (gen.isExecJitOn()) {
    /* Before executing JIT code, dump inputData, inputGenReg, inputPredReg,
     * inputZReg. */
    gen.dumpInputReg();
    f();                 /* Execute JIT code */
    gen.dumpOutputReg(); /* Dump all register values */
    gen.dumpCheckReg();  /* Dump register values to be checked */
  }

  return 0;
}
