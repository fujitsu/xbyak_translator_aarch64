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

    for (int i = 0; i < 64; i++) {
      inputZReg[14].ub_dt[i] = i;
      inputZReg[15].ub_dt[i] = i;
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* VEX range */
    vpmaddubsw(Xmm(0), Xmm(14), Xmm(15));
    vpmaddubsw(Xmm(1), Xmm(14), Xmm(15));

    vpmaddubsw(Ymm(2), Ymm(14), Ymm(15));
    vpmaddubsw(Ymm(3), Ymm(14), Ymm(15));

    vpmaddubsw(Xmm(4), Xmm(4), Xmm(15));
    vpmaddubsw(Xmm(5), Xmm(14), Xmm(5));
    vpmaddubsw(Xmm(6), Xmm(6), Xmm(6));

    vpmaddubsw(Ymm(7), Ymm(7), Ymm(15));
    vpmaddubsw(Ymm(8), Ymm(14), Ymm(8));
    vpmaddubsw(Ymm(9), Ymm(9), Ymm(9));

    
    /* EVEX range */
    vpmaddubsw(Xmm(16), Xmm(14), Xmm(15));
    vpmaddubsw(Xmm(17), Xmm(14), Xmm(15));

    vpmaddubsw(Ymm(18), Ymm(14), Ymm(15));
    vpmaddubsw(Ymm(19), Ymm(14), Ymm(15));

    vpmaddubsw(Zmm(20), Zmm(14), Zmm(15));
    vpmaddubsw(Zmm(21), Zmm(14), Zmm(15));

    vpmaddubsw(Xmm(22), Xmm(22), Xmm(15));
    vpmaddubsw(Xmm(23), Xmm(14), Xmm(23));
    vpmaddubsw(Xmm(24), Xmm(24), Xmm(24));

    vpmaddubsw(Ymm(25), Ymm(25), Ymm(15));
    vpmaddubsw(Ymm(26), Ymm(14), Ymm(26));
    vpmaddubsw(Ymm(27), Ymm(27), Ymm(27));

    vpmaddubsw(Zmm(28), Zmm(28), Zmm(15));
    vpmaddubsw(Zmm(29), Zmm(14), Zmm(29));
    vpmaddubsw(Zmm(30), Zmm(30), Zmm(30));
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
