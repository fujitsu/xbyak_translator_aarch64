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

    vshuff32x4(Zmm(0), Zmm(30), Zmm(31), 0);
    vshuff32x4(Zmm(1), Zmm(30), Zmm(31), 1);
    vshuff32x4(Zmm(2), Zmm(30), Zmm(31), 2);
    vshuff32x4(Zmm(3), Zmm(30), Zmm(31), 4);
    vshuff32x4(Zmm(4), Zmm(30), Zmm(31), 8);
    vshuff32x4(Zmm(5), Zmm(30), Zmm(31), 16);
    vshuff32x4(Zmm(6), Zmm(30), Zmm(31), 32);
    vshuff32x4(Zmm(7), Zmm(30), Zmm(31), 64);
    vshuff32x4(Zmm(8), Zmm(30), Zmm(31), 128);

    vshuff32x4(Zmm(9), Zmm(9), Zmm(31), 8);
    vshuff32x4(Zmm(10), Zmm(30), Zmm(10), 16);
    vshuff32x4(Zmm(11), Zmm(30), Zmm(30), 16);
    vshuff32x4(Zmm(12), Zmm(12), Zmm(12), 16);
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