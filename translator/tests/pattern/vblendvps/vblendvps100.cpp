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

    for (int i = 0; i < 15; i++) {
      inputZReg[11].us_dt[i] = inputZReg[8].us_dt[i] = 1 << 31;
      inputZReg[12].us_dt[i] = inputZReg[9].us_dt[i] = uint32_t(0x7FFFFFFF);
    }

    for (int i = 3; i < 12; i++) {
      inputZReg[11].us_dt[i] = inputZReg[8].us_dt[i] = 0;
      inputZReg[12].us_dt[i] = inputZReg[9].us_dt[i] = 1 << 31;
    }

    for (int i = 4; i < 16; i++) {
      inputZReg[13].us_dt[i] = inputZReg[10].us_dt[i] = ~uint32_t(0);
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    vblendvps(Xmm(2), Xmm(0), Xmm(1), Xmm(11));
    vblendvps(Xmm(3), Xmm(0), Xmm(1), Xmm(12));
    vblendvps(Xmm(4), Xmm(0), Xmm(1), Xmm(13));

    vblendvps(Xmm(5), Xmm(5), Xmm(1), Xmm(11));
    vblendvps(Xmm(6), Xmm(6), Xmm(1), Xmm(12));
    vblendvps(Xmm(7), Xmm(7), Xmm(1), Xmm(13));

    vblendvps(Xmm(8), Xmm(0), Xmm(8), Xmm(11));
    vblendvps(Xmm(9), Xmm(0), Xmm(9), Xmm(12));
    vblendvps(Xmm(10), Xmm(0), Xmm(10), Xmm(13));
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
