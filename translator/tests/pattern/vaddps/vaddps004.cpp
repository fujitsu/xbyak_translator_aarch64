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
    //    setDumpZRegMode(SP_DT); // set float mode

    for (int i = 0; i < 16; i++) {
      inputZReg[0].sp_dt[i] = float(i + 1);
      inputZReg[1].sp_dt[i] = float((i + 1) * 100);
      inputZReg[20].sp_dt[i] = float(i + 1);
      inputZReg[21].sp_dt[i] = float((i + 1) * 100);
    }

    inputPredReg[1] = uint64_t(0);
    inputPredReg[2] = ~uint64_t(0);
    inputPredReg[3] = (1 << 0);
    inputPredReg[4] = (1 << 0) | (1 << 1) | (1 << 4) | /* x86_64 */
                      (1 << 0) | (1 << 4) | (1 << 16); /* aarch64 */
    inputPredReg[5] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) |
                      (1 << 8) | (1 << 12) | /* x86_64 */
                      (1 << 0) | (1 << 4) | (1 << 8) | (1 << 12) | (1 << 16) |
                      (uint64_t(1) << 32) | (uint64_t(1) << 48); /* aarch64 */
    inputPredReg[6] = (1 << 5) | (1 << 7) | (1 << 10) | (1 << 13) |
                      (1 << 15) | /* x86_64 */
                      (1 << 20) | (1 << 28) | (uint64_t(1) << 40) |
                      (uint64_t(1) << 52) | (uint64_t(1) << 60); /* aarch64 */
    inputPredReg[7] = (1 << 6) | (1 << 9) | (1 << 11) | (1 << 14) | /* x86_64 */
                      (1 << 24) | (uint64_t(1) << 36) | (uint64_t(1) << 44) |
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
    vaddps(Zmm(2) | k1, Zmm(0), Zmm(1));
    vaddps(Zmm(3) | k2, Zmm(0), Zmm(1));
    vaddps(Zmm(4) | k3, Zmm(0), Zmm(1));
    vaddps(Zmm(5) | k4, Zmm(0), Zmm(1));
    vaddps(Zmm(6) | k5, Zmm(0), Zmm(1));
    vaddps(Zmm(7) | k6, Zmm(0), Zmm(1));
    vaddps(Zmm(8) | k7, Zmm(0), Zmm(1));
    vaddps(Zmm(9) | k5, Zmm(9), Zmm(1));    /* dstIdx = srcIdx */
    vaddps(Zmm(10) | k6, Zmm(0), Zmm(10));  /* dstIdx = src2Idx */
    vaddps(Zmm(11) | k7, Zmm(0), Zmm(0));   /* srcIdx = src2Idx */
    vaddps(Zmm(12) | k7, Zmm(12), Zmm(12)); /* dstIdx = srcIdx = src2Idx */

    /* Register index is EVEX range. */
    vaddps(Zmm(22) | k1, Zmm(20), Zmm(21));
    vaddps(Zmm(23) | k2, Zmm(20), Zmm(21));
    vaddps(Zmm(24) | k3, Zmm(20), Zmm(21));
    vaddps(Zmm(25) | k4, Zmm(20), Zmm(21));
    vaddps(Zmm(26) | k5, Zmm(20), Zmm(21));
    vaddps(Zmm(27) | k6, Zmm(20), Zmm(21));
    vaddps(Zmm(28) | k7, Zmm(20), Zmm(21));
    vaddps(Zmm(29) | k5, Zmm(29), Zmm(21)); /* dstIdx = srcIdx */
    vaddps(Zmm(30) | k6, Zmm(20), Zmm(30)); /* dstIdx = src2Idx */
    vaddps(Zmm(31) | k7, Zmm(20), Zmm(20)); /* srcIdx = src2Idx */
    vaddps(Zmm(19) | k7, Zmm(19), Zmm(19)); /* dstIdx = srcIdx = src2Idx */
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
