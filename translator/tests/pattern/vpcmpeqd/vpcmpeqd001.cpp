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

    inputZReg[0].us_dt[0] = 0;
    inputZReg[1].us_dt[0] = 0;

    inputZReg[2].us_dt[0] = inputZReg[3].us_dt[0] = 1;
    inputZReg[2].us_dt[7] = inputZReg[3].us_dt[7] = 2;

    inputZReg[4].us_dt[0] = inputZReg[5].us_dt[0] = 3;
    inputZReg[4].us_dt[5] = inputZReg[5].us_dt[5] = 4;
    inputZReg[4].us_dt[7] = inputZReg[5].us_dt[7] = 5;

    inputZReg[6].us_dt[0] = uint32_t(0xffffffff);
    inputZReg[7].us_dt[0] = uint32_t(0xffffffff);

    inputZReg[6].us_dt[1] = uint32_t(0xffffffff);
    inputZReg[7].us_dt[1] = uint32_t(0x7fffffff);

    inputZReg[6].us_dt[2] = uint32_t(0x7fffffff);
    inputZReg[7].us_dt[2] = uint32_t(0xffffffff);

    inputZReg[6].us_dt[3] = uint32_t(0x7fffffff);
    inputZReg[7].us_dt[3] = uint32_t(0x7fffffff);

    inputZReg[6].us_dt[4] = uint32_t(0xffffffff);
    inputZReg[7].us_dt[4] = uint32_t(0x0);

    inputZReg[6].us_dt[5] = uint32_t(0x7fffffff);
    inputZReg[7].us_dt[5] = uint32_t(0x0);

    inputZReg[6].us_dt[6] = uint32_t(0x0);
    inputZReg[7].us_dt[6] = uint32_t(0xffffffff);

    inputZReg[6].us_dt[7] = uint32_t(0x0);
    inputZReg[7].us_dt[7] = uint32_t(0x7fffffff);

    inputZReg[12] = inputZReg[6];
    inputZReg[13] = inputZReg[7];
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    vpcmpeqd(Ymm(8), Ymm(0), Ymm(1));
    vpcmpeqd(Ymm(9), Ymm(2), Ymm(3));
    vpcmpeqd(Ymm(10), Ymm(4), Ymm(5));
    vpcmpeqd(Ymm(11), Ymm(6), Ymm(7));
    vpcmpeqd(Ymm(12), Ymm(12), Ymm(7));  /* dstIdx = srcIdx */
    vpcmpeqd(Ymm(13), Ymm(6), Ymm(13));  /* dstIdx = src2Idx */
    vpcmpeqd(Ymm(14), Ymm(14), Ymm(14)); /* dstIdx = srcIdx = src2Idx */
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
    gen.modifyPredReg(SS_DT);
#endif

    gen.dumpOutputReg(); /* Dump all register values */
    gen.dumpCheckReg();  /* Dump register values to be checked */
  }

  return 0;
}
