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
    vpunpckhwd(Ymm(0), Ymm(1), Ymm(2));
    vpunpckhwd(Ymm(3), Ymm(3), Ymm(4));
    vpunpckhwd(Ymm(5), Ymm(6), Ymm(5));
    vpunpckhwd(Ymm(7), Ymm(8), Ymm(8));
    vpunpckhwd(Ymm(9), Ymm(9), Ymm(9));

    vpunpckhwd(Ymm(10), Ymm(11), Ymm(12));
    vpunpckhwd(Ymm(13), Ymm(13), Ymm(14));
    vpunpckhwd(Ymm(15), Ymm(16), Ymm(15));
    vpunpckhwd(Ymm(17), Ymm(18), Ymm(18));
    vpunpckhwd(Ymm(19), Ymm(19), Ymm(19));

    vpunpckhwd(Ymm(20), Ymm(21), Ymm(22));
    vpunpckhwd(Ymm(23), Ymm(23), Ymm(24));
    vpunpckhwd(Ymm(25), Ymm(26), Ymm(25));
    vpunpckhwd(Ymm(27), Ymm(28), Ymm(28));
    vpunpckhwd(Ymm(29), Ymm(29), Ymm(29));
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
