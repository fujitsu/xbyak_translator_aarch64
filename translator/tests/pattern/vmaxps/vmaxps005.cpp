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
    //    setInputZregAllRandomHex();
    setDumpZRegMode(SP_DT);
    setInputZregAllRandomFloat();

    inputPredReg[1] = uint64_t(0x0);
    inputPredReg[2] = ~uint64_t(0x0);
    inputPredReg[3] = uint64_t(0x1);
#ifndef __ARM_ARCH /* x86_64 */
    inputPredReg[4] = (0x1 << 0) | (0x1 << 15);
    inputPredReg[5] = ~uint64_t(0xffff);
    inputPredReg[6] = uint64_t(0xffff);
#else /* AArch64 */
    inputPredReg[4] = (0x1 << 0) | (uint64_t(0x1) << 60);
    inputPredReg[5] = ~uint64_t(0x1111111111111111);
    inputPredReg[6] = uint64_t(0x1111111111111111);
#endif
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12, r13, r14,
     * r15 */
    size_t addr1;
    addr1 = reinterpret_cast<size_t>(&(inputZReg[16].sp_dt[0]));
    mov(rax, addr1);

    vmaxps(Zmm(1), Zmm(30) | k1, Zmm(31));
    vmaxps(Zmm(2), Zmm(30) | k2, Zmm(31));
    vmaxps(Zmm(3), Zmm(30) | k3, Zmm(31));
    vmaxps(Zmm(4), Zmm(30) | k4, Zmm(31));
    vmaxps(Zmm(5), Zmm(30) | k5, Zmm(31));
    vmaxps(Zmm(6), Zmm(30) | k6, Zmm(31));

    vmaxps(Zmm(8), Zmm(30) | k1, Zmm(30));
    vmaxps(Zmm(9), Zmm(30) | k2, Zmm(30));
    vmaxps(Zmm(10), Zmm(30) | k3, Zmm(30));
    vmaxps(Zmm(11), Zmm(30) | k4, Zmm(30));
    vmaxps(Zmm(12), Zmm(30) | k5, Zmm(30));
    vmaxps(Zmm(13), Zmm(30) | k6, Zmm(30));

    vmaxps(Zmm(15), Zmm(30) | k1, Zmm(15));
    vmaxps(Zmm(16), Zmm(30) | k2, Zmm(16));
    vmaxps(Zmm(17), Zmm(30) | k3, Zmm(17));
    vmaxps(Zmm(18), Zmm(30) | k4, Zmm(18));
    vmaxps(Zmm(19), Zmm(30) | k5, Zmm(19));
    vmaxps(Zmm(20), Zmm(30) | k6, Zmm(20));

    vmaxps(Zmm(22), Zmm(22) | k1, Zmm(31));
    vmaxps(Zmm(23), Zmm(23) | k2, Zmm(31));
    vmaxps(Zmm(24), Zmm(24) | k3, Zmm(31));
    vmaxps(Zmm(25), Zmm(25) | k4, Zmm(31));
    vmaxps(Zmm(26), Zmm(26) | k5, Zmm(31));
    vmaxps(Zmm(27), Zmm(27) | k6, Zmm(31));

    mov(rax, 0x1);
    for (int i = 1; i < 7; i++) {
#ifndef __ARM_ARCH
      kmovq(Opmask(i), rax);
#else
      ptrue(Xbyak_aarch64::PRegB(i), Xbyak_aarch64::VL1);
#endif
    }
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
