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

    for (int j = 0; j < 32; j++) {
      for (int i = 0; i < 16; i++) {
        inputZReg[j].us_dt[i] = (j << 16) + i;
      }
    }

    for (int i = 0; i < 16; i++) {
      inputZReg[31].us_dt[i] = 0x11111111 * i;
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */

    vshufps(Ymm(0), Ymm(0), Ymm(0), 0);
    vshufps(Ymm(1), Ymm(1), Ymm(1), 2);
    vshufps(Ymm(2), Ymm(2), Ymm(2), 10);
    vshufps(Ymm(3), Ymm(3), Ymm(3), 42);
    vshufps(Ymm(4), Ymm(4), Ymm(4), 170);
    vshufps(Ymm(5), Ymm(5), Ymm(5), 1);
    vshufps(Ymm(6), Ymm(6), Ymm(6), 5);
    vshufps(Ymm(7), Ymm(7), Ymm(7), 21);
    vshufps(Ymm(8), Ymm(8), Ymm(8), 170);
    vshufps(Ymm(9), Ymm(9), Ymm(9), 15);
    vshufps(Ymm(10), Ymm(10), Ymm(10), 240);
    vshufps(Ymm(11), Ymm(12), Ymm(13), 204);
    vshufps(Ymm(14), Ymm(15), Ymm(16), 51);
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
