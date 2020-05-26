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
    // inputZReg[0].us_dt[0] = uint32_t(7);
    // inputZReg[4].us_dt[0] = uint32_t(7);

    inputPredReg[1] = (1 << 0) | (1 << 7); /* Both x86_64 and aarch64 */
    inputPredReg[2] = (1 << 0) | (1 << 7) | (1 << 8) |
                      (1 << 15); /* Both x86_64 and aarch64 */

    inputPredReg[7] = ~uint64_t(0);
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    vpmovsdb(Xmm(1) | k1 | T_z, Zmm(0));
    vpmovsdb(Xmm(3) | k2 | T_z, Zmm(2));
    vpmovsdb(Xmm(5) | k7 | T_z, Zmm(4));
    vpmovsdb(Xmm(7) | k1 | T_z, Ymm(6));
    vpmovsdb(Xmm(9) | k2 | T_z, Ymm(8));
    vpmovsdb(Xmm(11) | k7 | T_z, Ymm(10));
    vpmovsdb(Xmm(13) | k1 | T_z, Xmm(12));
    vpmovsdb(Xmm(15) | k2 | T_z, Xmm(14));
    vpmovsdb(Xmm(17) | k7 | T_z, Xmm(16));
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
