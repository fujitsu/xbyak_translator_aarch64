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
    for (int j = 0; j < 32; j++) {
      for (int i = 0; i < 16; i++) {
        inputZReg[j].us_dt[i] = (j << 16) + i;
      }
    }

    for (int i = 0; i < 16; i++) {
      inputZReg[31].us_dt[i] = 0x11111111 * i;
    }
#endif
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */

    vshufps(Xmm(0), Xmm(30), Xmm(31), 0);
    vshufps(Xmm(1), Xmm(30), Xmm(31), 1);
    vshufps(Xmm(2), Xmm(30), Xmm(31), 2);
    vshufps(Xmm(3), Xmm(30), Xmm(31), 4);
    vshufps(Xmm(4), Xmm(30), Xmm(31), 8);
    vshufps(Xmm(5), Xmm(30), Xmm(31), 16);
    vshufps(Xmm(6), Xmm(30), Xmm(31), 32);
    vshufps(Xmm(7), Xmm(30), Xmm(31), 64);
    vshufps(Xmm(8), Xmm(30), Xmm(31), 128);

    vshufps(Xmm(9), Xmm(9), Xmm(31), 8);
    vshufps(Xmm(10), Xmm(30), Xmm(10), 16);
    vshufps(Xmm(11), Xmm(30), Xmm(30), 16);
    vshufps(Xmm(12), Xmm(12), Xmm(12), 16);
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
