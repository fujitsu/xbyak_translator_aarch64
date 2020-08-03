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
#ifndef __ARM_ARCH
    inputPredReg[1] = (1 << 0) | (1 << 2) | (1 << 4) | (1 << 6);
    inputPredReg[2] = (1 << 1) | (1 << 3) | (1 << 5) | (1 << 7);
    inputPredReg[3] = ~uint64_t(0);
    inputPredReg[4] = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 6);
#else
    inputPredReg[1] = (1 << 0) | (1 << 16) | (uint64_t(1) << 32) | (uint64_t(1) << 48);
    inputPredReg[2] = (1 << 8) | (1 << 24) | (uint64_t(1) << 40) | (uint64_t(1) << 56);
    inputPredReg[3] = ~uint64_t(0);
    inputPredReg[4] = (1 << 8) | (1 << 24) | (uint64_t(1) << 32) | (uint64_t(1) << 48);
#endif
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    vpxorq(Xmm(2) | k1, Xmm(0), Xmm(1));
    vpxorq(Ymm(5) | k1, Ymm(3), Ymm(4));
    vpxorq(Zmm(8) | k1, Zmm(6), Zmm(7));

    vpxorq(Xmm(6) | k2, Xmm(7), Xmm(7));
    vpxorq(Xmm(8) | k3, Xmm(9), Xmm(8));
    vpxorq(Xmm(10) | k4, Xmm(10), Xmm(11));

    vpxorq(Ymm(13) | k2, Ymm(14), Ymm(14));
    vpxorq(Ymm(15) | k3, Ymm(16), Ymm(15));
    vpxorq(Ymm(17) | k4, Ymm(17), Ymm(18));

    vpxorq(Zmm(21) | k2, Zmm(22), Zmm(22));
    vpxorq(Zmm(23) | k3, Zmm(24), Zmm(23));
    vpxorq(Zmm(25) | k4, Zmm(25), Zmm(26));

    vpxorq(Xmm(29) | k1, Xmm(29), Xmm(29));
    vpxorq(Ymm(30) | k1, Ymm(30), Ymm(30));
    vpxorq(Zmm(31) | k1, Zmm(31), Zmm(31));

    mov(rax, 0x1);
#ifndef __ARM_ARCH
    kmovq(k1, rax);
    kmovq(k2, rax);
    kmovq(k3, rax);
    kmovq(k4, rax);
#else
    ptrue(p1.b, Xbyak_aarch64::VL1);
    ptrue(p2.b, Xbyak_aarch64::VL1);
    ptrue(p3.b, Xbyak_aarch64::VL1);
    ptrue(p4.b, Xbyak_aarch64::VL1);
#endif
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
