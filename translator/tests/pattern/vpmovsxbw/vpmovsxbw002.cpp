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

    inputPredReg[1] = uint64_t(0);
    inputPredReg[2] = ~uint64_t(0);
    inputPredReg[3] = (1 << 0);
    inputPredReg[4] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 4) | (1 << 8) |
                      (1 << 16) | /* x86_64 */
                      (1 << 0) | (1 << 2) | (1 << 4) | (1 << 8) | (1 << 16) |
                      (uint64_t(1) << 32); /* aarch64 */
    inputPredReg[5] = (1 << 0) | (1 << 3) | (1 << 6) | (1 << 12) | (1 << 19) |
                      (1 << 24) | /* x86_64 */
                      (1 << 0) | (1 << 6) | (1 << 12) | (1 << 24) |
                      (uint64_t(1) << 38) | (uint64_t(1) << 48); /* aarch64 */

    inputPredReg[6] = (1 << 19) | (1 << 21) | (1 << 25) | (1 << 27) |
                      (uint64_t(1) << 31) | /* x86_64 */
                      (uint64_t(1) << 38) | (uint64_t(1) << 42) |
                      (uint64_t(1) << 50) | (uint64_t(1) << 54) |
                      (uint64_t(1) << 62); /* aarch64 */

    inputPredReg[7] = (1 << 7) | (1 << 9) | (1 << 11) | (1 << 14) | (1 << 18) |
                      (1 << 22) | (1 << 28) | /* x86_64 */
                      (1 << 14) | (1 << 18) | (1 << 22) | (1 << 28) |
                      (uint64_t(1) << 36) | (uint64_t(1) << 44) |
                      (uint64_t(1) << 56); /* aarch64 */
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12, r13, r14,
     * r15 */

    /* Register index is VEX range. */
    vpmovsxbw(Zmm(1) | k1, Xmm(0));
    vpmovsxbw(Zmm(2) | k2, Xmm(0));
    vpmovsxbw(Zmm(3) | k3, Xmm(0));
    vpmovsxbw(Zmm(4) | k4, Xmm(0));
    vpmovsxbw(Zmm(5) | k5, Xmm(0));
    vpmovsxbw(Zmm(6) | k6, Xmm(0));
    vpmovsxbw(Zmm(7) | k7, Xmm(0));

    /* Register index is EVEX range. */
    vpmovsxbw(Zmm(21) | k1, Xmm(20));
    vpmovsxbw(Zmm(22) | k2, Xmm(20));
    vpmovsxbw(Zmm(23) | k3, Xmm(20));
    vpmovsxbw(Zmm(24) | k4, Xmm(20));
    vpmovsxbw(Zmm(25) | k5, Xmm(20));
    vpmovsxbw(Zmm(26) | k6, Xmm(20));
    vpmovsxbw(Zmm(27) | k7, Xmm(20));
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
