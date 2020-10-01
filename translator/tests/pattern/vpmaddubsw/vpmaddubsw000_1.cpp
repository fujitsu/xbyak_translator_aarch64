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

    /* signed:   -128, 0, 127
       unsigned: 0, 255 */
    inputZReg[14].ub_dt[0] = 0xFF;
    inputZReg[14].ub_dt[1] = 0xFF;
    inputZReg[15].ub_dt[0] = 0xFF;
    inputZReg[15].ub_dt[1] = 0xFF;

    inputZReg[14].ub_dt[2] = 0xFF;
    inputZReg[14].ub_dt[3] = 0xFF;
    inputZReg[15].ub_dt[2] = 0x7F;
    inputZReg[15].ub_dt[3] = 0x7F;

    inputZReg[14].ub_dt[4] = 0x7F;
    inputZReg[14].ub_dt[5] = 0x7F;
    inputZReg[15].ub_dt[4] = 0xFF;
    inputZReg[15].ub_dt[5] = 0xFF;
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* VEX range */
    vpmaddubsw(Xmm(4), Xmm(14), Xmm(15));
    vpmaddubsw(Ymm(5), Ymm(14), Ymm(15));

    /* EVEX range */
    vpmaddubsw(Xmm(16), Xmm(14), Xmm(15));
    vpmaddubsw(Ymm(17), Ymm(14), Ymm(15));
    vpmaddubsw(Zmm(18), Zmm(14), Zmm(15));
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
