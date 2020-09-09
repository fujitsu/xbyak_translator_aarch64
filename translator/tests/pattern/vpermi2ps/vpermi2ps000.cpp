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

    /* z31 - z29 are used as zTmpIdx - zTmp3Idx */

    for (int i = 0; i < 16; i++) {
      inputZReg[16].us_dt[i] = i + 0x0fff0000;
      inputZReg[17].us_dt[i] = i + 0x1fff0000;
      inputZReg[18].us_dt[i] = i + 0x2fff0000;
      inputZReg[19].us_dt[i] = i + 0x3fff0000;
      inputZReg[20].us_dt[i] = i + 0x4fff0000;
      inputZReg[21].us_dt[i] = i + 0x5fff0000;
      inputZReg[22].us_dt[i] = i + 0x6fff0000;
      inputZReg[23].us_dt[i] = i + 0x7fff0000;
      inputZReg[31].us_dt[i] = i + 0xffff0000;
    }

    for (int i = 0; i < 16; i++) {
      inputZReg[0].us_dt[i] = 15 - i;
      inputZReg[4].us_dt[i] = (15 - i) | 0x10;
    }
    for (int i = 0; i < 16; i++) {
      inputZReg[1].us_dt[i] = 3;
      inputZReg[5].us_dt[i] = 3 | 0x10;
    }
    for (int i = 0; i < 16; i++) {
      inputZReg[2].us_dt[i] = 0xffe0;
      inputZReg[6].us_dt[i] = 0xffe0 | 0x10;
    }
    for (int i = 0; i < 16; i++) {
      inputZReg[3].us_dt[i] = (15 - i) | 0xffe0;
      inputZReg[7].us_dt[i] = (15 - i) | 0xffe0 | 0x10;
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* z31 - z29 are used as zTmpIdx - zTmp3Idx */
    vpermi2ps(Zmm(0), Zmm(16), Zmm(31));
    vpermi2ps(Zmm(1), Zmm(17), Zmm(31));
    vpermi2ps(Zmm(2), Zmm(18), Zmm(31));
    vpermi2ps(Zmm(3), Zmm(19), Zmm(31));
    
    vpermi2ps(Zmm(4), Zmm(20), Zmm(31));
    vpermi2ps(Zmm(5), Zmm(21), Zmm(31));
    vpermi2ps(Zmm(6), Zmm(22), Zmm(31));
    vpermi2ps(Zmm(7), Zmm(23), Zmm(31));
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
