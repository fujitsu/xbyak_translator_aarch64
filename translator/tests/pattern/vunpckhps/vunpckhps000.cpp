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
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */

    /* Register index is inside VEX range. */
    vunpckhps(Xmm(0), Xmm(14), Xmm(15));
    vunpckhps(Xmm(1), Xmm(14), Xmm(15));
    vunpckhps(Xmm(2), Xmm(2), Xmm(15));
    vunpckhps(Xmm(3), Xmm(14), Xmm(3));
    vunpckhps(Xmm(4), Xmm(4), Xmm(4));

    vunpckhps(Ymm(5), Ymm(14), Ymm(15));
    vunpckhps(Ymm(6), Ymm(14), Ymm(15));
    vunpckhps(Ymm(7), Ymm(7), Ymm(15));
    vunpckhps(Ymm(8), Ymm(14), Ymm(8));
    vunpckhps(Ymm(9), Ymm(9), Ymm(9));

    /* Register index is inside EVEX range. */
    vunpckhps(Xmm(16), Xmm(14), Xmm(15));
    vunpckhps(Xmm(17), Xmm(14), Xmm(15));
    vunpckhps(Xmm(18), Xmm(18), Xmm(15));
    vunpckhps(Xmm(19), Xmm(14), Xmm(19));
    vunpckhps(Xmm(20), Xmm(20), Xmm(20));

    vunpckhps(Ymm(21), Ymm(14), Ymm(15));
    vunpckhps(Ymm(22), Ymm(14), Ymm(15));
    vunpckhps(Ymm(23), Ymm(23), Ymm(15));
    vunpckhps(Ymm(24), Ymm(14), Ymm(24));
    vunpckhps(Ymm(25), Ymm(25), Ymm(25));

    vunpckhps(Zmm(26), Zmm(14), Zmm(15));
    vunpckhps(Zmm(27), Zmm(14), Zmm(15));
    vunpckhps(Zmm(28), Zmm(28), Zmm(15));
    vunpckhps(Zmm(29), Zmm(14), Zmm(29));
    vunpckhps(Zmm(30), Zmm(30), Zmm(30));
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
