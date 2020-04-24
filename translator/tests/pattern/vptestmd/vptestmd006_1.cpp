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

    /* elemet is 32 bits.
       Xmm:4 elements
       Ymm:8 elements
       Zmm:16 elements */

    // Xmm Range
    inputPredReg[1] = (1 << 0);

    // Ymm Range
    inputPredReg[2] = (1 << 0) | (1 << 5) | (uint64_t(1) << 7) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 20) |
                      (uint64_t(1) << 28); /* aarch64 */

    // Zmm Range
    inputPredReg[3] = (1 << 0) | (1 << 6) | (uint64_t(1) << 7) | (1 << 13) |
                      (uint64_t(1) << 15) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 24) | (uint64_t(1) << 28) |
                      (uint64_t(1) << 52) | (uint64_t(1) << 60); /* aarch64 */

    // inputPredReg[7] = ~uint64_t(0);
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */

    /* z31 - z29 are used as zTmpIdx - zTmp3Idx */
    vptestmd(k4 | k1, Xmm(0), Xmm(0));
    vptestmd(k5 | k2, Xmm(2), Xmm(2));
    vptestmd(k6 | k3, Xmm(4), Xmm(4));

    vptestmd(k1 | k1, Xmm(6), Xmm(6));
    vptestmd(k2 | k2, Xmm(8), Xmm(8));
    vptestmd(k3 | k3, Xmm(10), Xmm(10));
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
    f(); /* Execute JIT code */

#ifndef XBYAK_TRANSLATE_AARCH64
    /* Bit order of mask registers are different from x86_64 and aarch64.
       In order to compare output values of mask registers by test script,
       Bit order of x86_64 mask register values is modified here. */
    gen.modifyPredReg(SP_DT);
#endif

    gen.dumpOutputReg(); /* Dump all register values */
    gen.dumpCheckReg();  /* Dump register values to be checked */
  }

  return 0;
}
