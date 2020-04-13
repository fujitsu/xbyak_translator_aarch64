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

    /* z31 - z29 are used as zTmpIdx - zTmp3Idx */

    inputPredReg[1] = (1 << 0);
    inputPredReg[2] = (1 << 0) | (1 << 9) | (uint64_t(1) << 18) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 18) |
                      (uint64_t(1) << 36); /* aarch64 */
    inputPredReg[3] = (1 << 0) | (1 << 9) | (uint64_t(1) << 18) | (1 << 19) |
                      (uint64_t(1) << 31) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 18) | (uint64_t(1) << 36) |
                      (uint64_t(1) << 38) | (uint64_t(1) << 62); /* aarch64 */
    inputPredReg[4] = (1 << 0) | (1 << 17) | (1 << 21) | (1 << 25) |
                      (uint64_t(1) << 31) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 34) | (uint64_t(1) << 42) |
                      (uint64_t(1) << 50) | (uint64_t(1) << 62); /* aarch64 */
    inputPredReg[5] = (1 << 0) | (1 << 17) | (1 << 21) | (1 << 25) | (1 << 27) |
                      (uint64_t(1) << 31) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 34) | (uint64_t(1) << 42) |
                      (uint64_t(1) << 50) | (uint64_t(1) << 54) |
                      (uint64_t(1) << 62); /* aarch64 */
    inputPredReg[6] = (1 << 0) | (1 << 17) | (1 << 21) | (1 << 23) | (1 << 25) |
                      (uint64_t(1) << 29) | (uint64_t(1) << 31) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 34) | (uint64_t(1) << 42) |
                      (uint64_t(1) << 46) | (uint64_t(1) << 50) |
                      (uint64_t(1) << 58) | (uint64_t(1) << 62); /* aarch64 */
    inputPredReg[7] = ~uint64_t(0);
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* z31 - z29 are used as zTmpIdx - zTmp3Idx */
    vpunpcklwd(Xmm(1) | k1 | T_z, Xmm(30), Xmm(31));
    vpunpcklwd(Xmm(2) | k2 | T_z, Xmm(30), Xmm(30));
    vpunpcklwd(Xmm(3) | k3 | T_z, Xmm(3), Xmm(31));
    vpunpcklwd(Xmm(4) | k4 | T_z, Xmm(30), Xmm(4));
    vpunpcklwd(Xmm(5) | k5 | T_z, Xmm(5), Xmm(5));
    vpunpcklwd(Xmm(6) | k6 | T_z, Xmm(30), Xmm(31));
    vpunpcklwd(Xmm(7) | k7 | T_z, Xmm(30), Xmm(31));
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
