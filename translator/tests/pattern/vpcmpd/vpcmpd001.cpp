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
    /*
    inputZReg[0].ud_dt[0] = 10; //a
    inputZReg[0].ud_dt[1] = 10; //a
    inputZReg[0].ud_dt[2] = 11; //b
    inputZReg[0].ud_dt[3] = 11; //b

    inputZReg[1].ud_dt[0] = 12; //c
    inputZReg[1].ud_dt[1] = 12; //c
    inputZReg[1].ud_dt[2] = 13; //d
    inputZReg[1].ud_dt[3] = 13; //d
    */
    /*
    for (int i = 0; i < 64; i++) {
      inputZReg[1].ud_dt[i] = i;
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
    */
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* z31 - z29 are used as zTmpIdx - zTmp3Idx */
    /*
    for(int i = 0; i < 7; i++){
      vpcmpb(k(i), Zmm(i), Zmm(i+1), i);
    }
    */

    vpcmpd(k1, Zmm(9), Zmm(8), 4);
    vpcmpd(k2, Zmm(11), Zmm(10), 5);
    vpcmpd(k3, Zmm(13), Zmm(12), 6);
    // vpcmpb(k4, Zmm(15), Zmm(14), 7); //not exist "true" pattern
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
    f(); /* Execute JIT code */

#ifndef XBYAK_TRANSLATE_AARCH64
    /* Bit order of mask registers are different from x86_64 and aarch64.
       In order to compare output values of mask registers by test script,
       Bit order of x86_64 mask register values is modified here. */
    gen.modifyPredReg(SP_DT);
#endif

    gen.dumpOutputReg(); /* Dump all register values */
    gen.dumpCheckReg();  /* Dump register values to be checked */
  }

  return 0;
}
