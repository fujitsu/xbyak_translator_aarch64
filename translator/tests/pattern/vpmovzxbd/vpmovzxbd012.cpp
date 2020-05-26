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
    vpmovzxbd(Xmm(1) | k1 | T_z, Xmm(0));
    vpmovzxbd(Xmm(2) | k2 | T_z, Xmm(0));
    vpmovzxbd(Xmm(3) | k3 | T_z, Xmm(0));
    vpmovzxbd(Xmm(4) | k4 | T_z, Xmm(0));
    vpmovzxbd(Xmm(5) | k5 | T_z, Xmm(0));
    vpmovzxbd(Xmm(6) | k6 | T_z, Xmm(0));
    vpmovzxbd(Xmm(7) | k7 | T_z, Xmm(0));

    vpmovzxbd(Xmm(8) | k1 | T_z, Xmm(8));
    vpmovzxbd(Xmm(9) | k2 | T_z, Xmm(9));
    vpmovzxbd(Xmm(10) | k3 | T_z, Xmm(10));
    vpmovzxbd(Xmm(11) | k4 | T_z, Xmm(11));
    vpmovzxbd(Xmm(12) | k5 | T_z, Xmm(12));
    vpmovzxbd(Xmm(13) | k6 | T_z, Xmm(13));
    vpmovzxbd(Xmm(14) | k7 | T_z, Xmm(14));

    /* Register index is EVEX range. */
    vpmovzxbd(Xmm(21) | k1 | T_z, Xmm(20));
    vpmovzxbd(Xmm(22) | k2 | T_z, Xmm(20));
    vpmovzxbd(Xmm(23) | k3 | T_z, Xmm(20));
    vpmovzxbd(Xmm(24) | k4 | T_z, Xmm(20));
    vpmovzxbd(Xmm(25) | k5 | T_z, Xmm(20));
    vpmovzxbd(Xmm(26) | k6 | T_z, Xmm(20));
    vpmovzxbd(Xmm(27) | k7 | T_z, Xmm(20));

    vpmovzxbd(Xmm(15) | k1 | T_z, Xmm(15));
    vpmovzxbd(Xmm(16) | k2 | T_z, Xmm(16));
    vpmovzxbd(Xmm(17) | k3 | T_z, Xmm(17));
    vpmovzxbd(Xmm(18) | k4 | T_z, Xmm(18));
    vpmovzxbd(Xmm(19) | k5 | T_z, Xmm(19));
    vpmovzxbd(Xmm(20) | k6 | T_z, Xmm(20));
    vpmovzxbd(Xmm(28) | k7 | T_z, Xmm(28));
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
