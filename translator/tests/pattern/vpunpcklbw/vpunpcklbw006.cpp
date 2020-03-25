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
    inputPredReg[2] = (1 << 0) | (1 << 1) | (1 << 4); /* x86_64 */
    //                      (1 << 0) | (1 << 8) | (uint64_t(1) << 32);  /*
    //                      aarch64 */
    inputPredReg[3] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 4); /* x86_64 */
    //(1 << 0) | (1 << 8) | (1 << 16) |
    //              (uint64_t(1) << 32); /* aarch64 */
    inputPredReg[4] =
        (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4); /* x86_64 */
    //       (1 << 0) | (1 << 8) | (1 << 16) | (1 << 24) |
    //                (uint64_t(1) << 32); /* aarch64 */

    inputPredReg[5] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) |
                      (1 << 6); /* x86_64 */
    //       (1 << 0) | (1 << 8) | (1 << 16) | (1 << 24) |
    //                (uint64_t(1) << 32) | (uint64_t(1) << 48); /* aarch64 */
    inputPredReg[6] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) |
                      (1 << 6) | (1 << 7); /* x86_64 */
    //                      (1 << 0) | (1 << 8) | (1 << 16) | (1 << 24) |
    //                (uint64_t(1) << 32) | (uint64_t(1) << 48) |
    //                (uint64_t(1) << 56); /* aarch64 */
    inputPredReg[7] = ~uint64_t(0);
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    vpunpcklbw(Ymm(1) | k1, Ymm(30), Ymm(31));
    vpunpcklbw(Ymm(2) | k2, Ymm(30), Ymm(31));
    vpunpcklbw(Ymm(3) | k3, Ymm(30), Ymm(31));
    vpunpcklbw(Ymm(4) | k4, Ymm(30), Ymm(31));
    vpunpcklbw(Ymm(5) | k5, Ymm(30), Ymm(31));
    vpunpcklbw(Ymm(6) | k6, Ymm(30), Ymm(31));
    vpunpcklbw(Ymm(7) | k7, Ymm(30), Ymm(31));
    /*
    vpunpcklbw(Ymm(8) | k1, Ymm(8), Ymm(31));
    vpunpcklbw(Ymm(9) | k2, Ymm(9), Ymm(31));
    vpunpcklbw(Ymm(10) | k3, Ymm(10), Ymm(31));
    vpunpcklbw(Ymm(11) | k4, Ymm(11), Ymm(31));
    vpunpcklbw(Ymm(12) | k5, Ymm(12), Ymm(31));
    vpunpcklbw(Ymm(13) | k6, Ymm(13), Ymm(31));
    vpunpcklbw(Ymm(14) | k7, Ymm(14), Ymm(31));

    vpunpcklbw(Ymm(15) | k1, Ymm(30), Ymm(15));
    vpunpcklbw(Ymm(16) | k2, Ymm(30), Ymm(16));
    vpunpcklbw(Ymm(17) | k3, Ymm(30), Ymm(17));
    vpunpcklbw(Ymm(18) | k4, Ymm(30), Ymm(18));
    vpunpcklbw(Ymm(19) | k5, Ymm(30), Ymm(19));
    vpunpcklbw(Ymm(20) | k6, Ymm(30), Ymm(20));
    vpunpcklbw(Ymm(21) | k7, Ymm(30), Ymm(21));
    */
    vpunpcklbw(Ymm(22) | k1, Ymm(22), Ymm(22));
    vpunpcklbw(Ymm(23) | k2, Ymm(23), Ymm(23));
    vpunpcklbw(Ymm(24) | k3, Ymm(24), Ymm(24));
    vpunpcklbw(Ymm(25) | k4, Ymm(25), Ymm(25));
    vpunpcklbw(Ymm(26) | k5, Ymm(26), Ymm(26));
    vpunpcklbw(Ymm(27) | k6, Ymm(27), Ymm(27));
    vpunpcklbw(Ymm(28) | k7, Ymm(28), Ymm(28));
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
