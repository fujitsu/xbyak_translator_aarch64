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

    inputPredReg[1] = (1 << 0);
    inputPredReg[2] = (1 << 0) | (1 << 2) |           /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 16); /* aarch64 */
    inputPredReg[3] = (1 << 0) | (1 << 1) | (1 << 6) |
                      (uint64_t(1) << 7) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 8) | (uint64_t(1) << 48) |
                      (uint64_t(1) << 56); /* aarch64 */
    inputPredReg[4] = (1 << 0) | (1 << 2) | (1 << 5) | (1 << 6) |
                      (uint64_t(1) << 7) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 16) | (uint64_t(1) << 40) |
                      (uint64_t(1) << 48) | (uint64_t(1) << 56); /* aarch64 */
    inputPredReg[5] = (1 << 0) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6) |
                      (uint64_t(1) << 7) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 24) | (uint64_t(1) << 32) |
                      (uint64_t(1) << 40) | (uint64_t(1) << 48) |
                      (uint64_t(1) << 56); /* aarch64 */
    inputPredReg[6] = (1 << 0) | (1 << 1) | (1 << 3) | (1 << 4) | (1 << 5) |
                      (uint64_t(1) << 6) | (uint64_t(1) << 7) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 8) | (uint64_t(1) << 24) |
                      (uint64_t(1) << 32) | (uint64_t(1) << 40) |
                      (uint64_t(1) << 48) | (uint64_t(1) << 56); /* aarch64 */
    inputPredReg[7] = ~uint64_t(0);
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    vpunpcklqdq(Xmm(1) | k1, Xmm(30), Xmm(31));
    vpunpcklqdq(Xmm(2) | k2, Xmm(2), Xmm(31));
    vpunpcklqdq(Xmm(3) | k3, Xmm(30), Xmm(30));
    vpunpcklqdq(Xmm(4) | k4, Xmm(30), Xmm(4));
    vpunpcklqdq(Xmm(5) | k5, Xmm(5), Xmm(5));
    vpunpcklqdq(Xmm(6) | k6, Xmm(30), Xmm(31));
    vpunpcklqdq(Xmm(7) | k7, Xmm(30), Xmm(31));
    /*
    vpunpcklqdq(Xmm(8) | k1, Xmm(8), Xmm(31));
    vpunpcklqdq(Xmm(9) | k2, Xmm(9), Xmm(31));
    vpunpcklqdq(Xmm(10) | k3, Xmm(10), Xmm(31));
    vpunpcklqdq(Xmm(11) | k4, Xmm(11), Xmm(31));
    vpunpcklqdq(Xmm(12) | k5, Xmm(12), Xmm(31));
    vpunpcklqdq(Xmm(13) | k6, Xmm(13), Xmm(31));
    vpunpcklqdq(Xmm(14) | k7, Xmm(14), Xmm(31));

    vpunpcklqdq(Xmm(15) | k1, Xmm(30), Xmm(15));
    vpunpcklqdq(Xmm(16) | k2, Xmm(30), Xmm(16));
    vpunpcklqdq(Xmm(17) | k3, Xmm(30), Xmm(17));
    vpunpcklqdq(Xmm(18) | k4, Xmm(30), Xmm(18));
    vpunpcklqdq(Xmm(19) | k5, Xmm(30), Xmm(19));
    vpunpcklqdq(Xmm(20) | k6, Xmm(30), Xmm(20));
    vpunpcklqdq(Xmm(21) | k7, Xmm(30), Xmm(21));
    */
    vpunpcklqdq(Xmm(22) | k1, Xmm(20), Xmm(21));
    vpunpcklqdq(Xmm(23) | k2, Xmm(23), Xmm(20));
    vpunpcklqdq(Xmm(24) | k3, Xmm(20), Xmm(20));
    vpunpcklqdq(Xmm(25) | k4, Xmm(20), Xmm(25));
    vpunpcklqdq(Xmm(26) | k5, Xmm(26), Xmm(26));
    vpunpcklqdq(Xmm(27) | k6, Xmm(27), Xmm(27));
    vpunpcklqdq(Xmm(28) | k7, Xmm(28), Xmm(28));
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
