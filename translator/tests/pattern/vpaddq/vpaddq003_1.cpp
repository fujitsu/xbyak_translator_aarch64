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
#if 0
    /*
    for (int i = 0; i < 16; i++) {
      inputZReg[0].us_dt[i] = ~uint64_t(0);
      inputZReg[3].us_dt[i] = ~uint64_t(0);
      inputZReg[6].us_dt[i] = ~uint64_t(0);
    }
    for (int i = 0; i < 16; i++) {
      inputZReg[1].us_dt[i] = uint32_t(0xFF00FF00AA55AA55);
      inputZReg[4].us_dt[i] = uint32_t(0xFF00FF00AA55AA55);
      inputZReg[7].us_dt[i] = uint32_t(0xFF00FF00AA55AA55);
    }
    */
#endif
    inputPredReg[1] = uint64_t(0);
    inputPredReg[2] = ~uint64_t(0);
    inputPredReg[3] = (1 << 0);
    inputPredReg[4] = (1 << 0) | (1 << 2) |                       /* x86_64 */
                      (1 << 0) | (1 << 16);                       /* aarch64 */
    inputPredReg[5] = (1 << 1) | (1 << 3) | (1 << 5) | (1 << 7) | /* x86_64 */
                      (1 << 8) | (1 << 24) | (uint64_t(1) << 40) |
                      (uint64_t(1) << 56); /* aarch64 */

    inputPredReg[6] = (1 << 0) | (1 << 1) | (1 << 6) | (1 << 7) | /* x86_64 */
                      (1 << 0) | (1 << 8) | (uint64_t(1) << 48) |
                      (uint64_t(1) << 56); /* aarch64 */

    inputPredReg[7] = (1 << 0) | (1 << 1) | (1 << 3) | (1 << 4) | (1 << 5) |
                      (1 << 7) | /* x86_64 */
                      (1 << 0) | (1 << 8) | (1 << 24) | (uint64_t(1) << 32) |
                      (uint64_t(1) << 40) | (uint64_t(1) << 56); /* aarch64 */
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */

    /* Register index is VEX range. */
    vpaddq(Zmm(1) | k1, Zmm(10), Zmm(11));
    vpaddq(Zmm(2) | k2, Zmm(10), Zmm(11));
    vpaddq(Zmm(3) | k3, Zmm(10), Zmm(11));
    vpaddq(Zmm(4) | k4, Zmm(10), Zmm(11));
    vpaddq(Zmm(5) | k5, Zmm(10), Zmm(11));
    vpaddq(Zmm(6) | k6, Zmm(10), Zmm(11));
    vpaddq(Zmm(7) | k7, Zmm(10), Zmm(11));
    vpaddq(Zmm(8) | k5, Zmm(8), Zmm(11));
    vpaddq(Zmm(9) | k6, Zmm(10), Zmm(9));
    vpaddq(Zmm(12) | k6, Zmm(10), Zmm(10));
    vpaddq(Zmm(0) | k7, Zmm(0), Zmm(0));

    /* Register index is EVEX range. */
    vpaddq(Zmm(21) | k1, Zmm(30), Zmm(31));
    vpaddq(Zmm(22) | k2, Zmm(30), Zmm(31));
    vpaddq(Zmm(23) | k3, Zmm(30), Zmm(31));
    vpaddq(Zmm(24) | k4, Zmm(30), Zmm(31));
    vpaddq(Zmm(25) | k5, Zmm(30), Zmm(31));
    vpaddq(Zmm(26) | k6, Zmm(30), Zmm(31));
    vpaddq(Zmm(27) | k7, Zmm(31), Zmm(31));
    vpaddq(Zmm(28) | k5, Zmm(28), Zmm(31));
    vpaddq(Zmm(29) | k6, Zmm(30), Zmm(29));
    vpaddq(Zmm(20) | k7, Zmm(20), Zmm(20));
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
