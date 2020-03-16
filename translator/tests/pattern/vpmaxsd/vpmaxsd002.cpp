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

    for (int i = 0; i < 8; i++) {
      inputZReg[14].us_dt[2 * i + 0] = inputZReg[30].us_dt[2 * i + 0] =
          0x8aaabbbb;
      inputZReg[14].us_dt[2 * i + 1] = inputZReg[30].us_dt[2 * i + 1] =
          0x7cccdddd;

      inputZReg[15].us_dt[2 * i + 1] = inputZReg[31].us_dt[2 * i + 1] =
          0x85554444;
      inputZReg[15].us_dt[2 * i + 0] = inputZReg[31].us_dt[2 * i + 0] =
          0x72221111;
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* VEX range */
    vpmaxsd(Zmm(0), Zmm(14), Zmm(15));
    vpmaxsd(Zmm(1), Zmm(14), Zmm(15));
    vpmaxsd(Zmm(2), Zmm(2), Zmm(15));
    vpmaxsd(Zmm(3), Zmm(14), Zmm(3));
    vpmaxsd(Zmm(4), Zmm(4), Zmm(4));

    /* EVEX range */
    vpmaxsd(Zmm(10), Zmm(30), Zmm(31));
    vpmaxsd(Zmm(11), Zmm(30), Zmm(31));
    vpmaxsd(Zmm(12), Zmm(12), Zmm(31));
    vpmaxsd(Zmm(13), Zmm(30), Zmm(13));
    vpmaxsd(Zmm(16), Zmm(16), Zmm(16));
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
