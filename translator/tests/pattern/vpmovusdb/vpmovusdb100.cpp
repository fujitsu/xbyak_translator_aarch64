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
#include <vector>

class TestPtnGenerator : public TestGenerator {
public:
  void setInitialRegValue() {
    /* Here modify arrays of inputGenReg, inputPredReg, inputZReg */
    setInputZregAllRandomHex();

    std::vector<int> pattern = {30, 31};

    for (auto i : pattern) {
      inputZReg[i].us_dt[0] = ~uint32_t(0);
      inputZReg[i].us_dt[1] = uint32_t(0x7FFFFFFF);
      inputZReg[i].us_dt[2] = uint32_t(0xFF);
      inputZReg[i].us_dt[3] = uint32_t(0x7F);
      inputZReg[i].us_dt[4] = uint32_t(0x1);
      inputZReg[i].us_dt[9] = ~uint32_t(0);
      inputZReg[i].us_dt[8] = uint32_t(0x7FFFFFFF);
      inputZReg[i].us_dt[7] = uint32_t(0xFF);
      inputZReg[i].us_dt[6] = uint32_t(0x7F);
      inputZReg[i].us_dt[5] = uint32_t(0x1);
      inputZReg[i].us_dt[10] = ~uint32_t(0);
      inputZReg[i].us_dt[11] = uint32_t(0x7FFFFFFF);
      inputZReg[i].us_dt[12] = uint32_t(0xFF);
      inputZReg[i].us_dt[13] = uint32_t(0x7F);
      inputZReg[i].us_dt[14] = uint32_t(0x1);
      inputZReg[i].us_dt[15] = ~uint32_t(0);
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* Dst=Xmm, src=Zmm */
    vpmovusdb(Xmm(0), Zmm(31));
    vpmovusdb(Xmm(1), Zmm(31));
    vpmovusdb(Xmm(30), Zmm(30));
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
