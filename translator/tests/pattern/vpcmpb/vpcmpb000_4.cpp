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

    inputZReg[0].ub_dt[0] = 0;
    inputZReg[1].ub_dt[0] = 0;

    inputZReg[2].ub_dt[0] = inputZReg[3].ub_dt[0] = 1;
    inputZReg[2].ub_dt[7] = inputZReg[3].ub_dt[7] = 2;

    inputZReg[4].ub_dt[0] = inputZReg[5].ub_dt[0] = 3;
    inputZReg[4].ub_dt[7] = inputZReg[5].ub_dt[7] = 4;
    inputZReg[4].ub_dt[15] = inputZReg[5].ub_dt[15] = 5;

    inputZReg[4].ub_dt[33] = 0xff;
    inputZReg[5].ub_dt[33] = 0xff;

    inputZReg[4].ub_dt[34] = 0xff;
    inputZReg[5].ub_dt[34] = 0x7f;

    inputZReg[4].ub_dt[35] = 0x7f;
    inputZReg[5].ub_dt[35] = 0xff;

    inputZReg[4].ub_dt[36] = 0x7f;
    inputZReg[5].ub_dt[36] = 0x7f;

    inputZReg[4].ub_dt[37] = 0xff;
    inputZReg[5].ub_dt[37] = 0x0;

    inputZReg[4].ub_dt[38] = 0x7f;
    inputZReg[5].ub_dt[38] = 0x0;

    inputZReg[4].ub_dt[39] = 0x0;
    inputZReg[5].ub_dt[39] = 0xff;

    inputZReg[4].ub_dt[40] = 0x0;
    inputZReg[5].ub_dt[40] = 0x7f;
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
/* Here write JIT code with x86_64 mnemonic function to be tested. */
#define UIMM 4
    vpcmpb(k1, Zmm(0), Zmm(1), UIMM);
    vpcmpb(k2, Zmm(2), Zmm(3), UIMM);
    vpcmpb(k3, Zmm(4), Zmm(5), UIMM);
    vpcmpb(k7, Zmm(31), Zmm(31), UIMM);
#undef UIMM
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
    gen.modifyPredReg(SB_DT);
#endif

    gen.dumpOutputReg(); /* Dump all register values */
    gen.dumpCheckReg();  /* Dump register values to be checked */
  }

  return 0;
}
