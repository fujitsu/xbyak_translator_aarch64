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
    vpunpckhwd(Zmm(0), Zmm(1), Zmm(2));
    vpunpckhwd(Zmm(3), Zmm(3), Zmm(4));
    vpunpckhwd(Zmm(5), Zmm(6), Zmm(5));
    vpunpckhwd(Zmm(7), Zmm(8), Zmm(8));
    vpunpckhwd(Zmm(9), Zmm(9), Zmm(9));

    vpunpckhwd(Zmm(10), Zmm(11), Zmm(12));
    vpunpckhwd(Zmm(13), Zmm(13), Zmm(14));
    vpunpckhwd(Zmm(15), Zmm(16), Zmm(15));
    vpunpckhwd(Zmm(17), Zmm(18), Zmm(18));
    vpunpckhwd(Zmm(19), Zmm(19), Zmm(19));

    vpunpckhwd(Zmm(20), Zmm(21), Zmm(22));
    vpunpckhwd(Zmm(23), Zmm(23), Zmm(24));
    vpunpckhwd(Zmm(25), Zmm(26), Zmm(25));
    vpunpckhwd(Zmm(27), Zmm(28), Zmm(28));
    vpunpckhwd(Zmm(29), Zmm(29), Zmm(29));
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
