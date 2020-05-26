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
    vpunpcklbw(Xmm(0), Xmm(1), Xmm(2));
    vpunpcklbw(Xmm(3), Xmm(3), Xmm(4));
    vpunpcklbw(Xmm(5), Xmm(6), Xmm(5));
    vpunpcklbw(Xmm(7), Xmm(8), Xmm(8));
    vpunpcklbw(Xmm(9), Xmm(9), Xmm(9));

    vpunpcklbw(Xmm(10), Xmm(11), Xmm(12));
    vpunpcklbw(Xmm(13), Xmm(13), Xmm(14));
    vpunpcklbw(Xmm(15), Xmm(16), Xmm(15));
    vpunpcklbw(Xmm(17), Xmm(18), Xmm(18));
    vpunpcklbw(Xmm(19), Xmm(19), Xmm(19));

    vpunpcklbw(Xmm(20), Xmm(21), Xmm(22));
    vpunpcklbw(Xmm(23), Xmm(23), Xmm(24));
    vpunpcklbw(Xmm(25), Xmm(26), Xmm(25));
    vpunpcklbw(Xmm(27), Xmm(28), Xmm(28));
    vpunpcklbw(Xmm(29), Xmm(29), Xmm(29));
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
