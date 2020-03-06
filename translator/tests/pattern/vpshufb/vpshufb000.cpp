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

    for (int i = 0; i < 64; i++) {
      inputZReg[15].ub_dt[i] = i;
    }

    for (int i = 0; i < 64; i++) {
      inputZReg[8].sb_dt[i] = i;
    }
    for (int i = 0; i < 64; i++) {
      inputZReg[9].sb_dt[i] = 3;
    }
    for (int i = 0; i < 64; i++) {
      inputZReg[10].sb_dt[i] = 0x80;
    }
    for (int i = 0; i < 64; i++) {
      inputZReg[11].sb_dt[i] = 0xff;
    }
    for (int i = 0; i < 64; i++) {
      inputZReg[12].sb_dt[i] = 0x7f;
    }
    for (int i = 0; i < 64; i++) {
      inputZReg[13].sb_dt[i] = 0x74;
    }
    for (int i = 0; i < 64; i++) {
      inputZReg[14].sb_dt[i] = 0x40 | (i % 8);
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* z31 - z29 are used as zTmpIdx - zTmp3Idx */

    /* VEX */
    vpshufb(Ymm(0), Ymm(15), Ymm(8));
    vpshufb(Ymm(1), Ymm(15), Ymm(9));
    vpshufb(Ymm(2), Ymm(15), Ymm(10));
    vpshufb(Ymm(3), Ymm(15), Ymm(11));
    vpshufb(Ymm(4), Ymm(15), Ymm(12));
    vpshufb(Ymm(5), Ymm(15), Ymm(13));
    vpshufb(Ymm(6), Ymm(15), Ymm(14));
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
