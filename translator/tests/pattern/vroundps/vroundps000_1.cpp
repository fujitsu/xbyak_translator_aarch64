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
    setDumpZRegMode(SP_DT);
    setInputZregAllRandomFloat();

    inputZReg[0].sp_dt[0] = 0.0f;
    inputZReg[0].sp_dt[1] = 0.4f;
    inputZReg[0].sp_dt[2] = 0.5f;
    inputZReg[0].sp_dt[3] = 0.6f;

    inputZReg[1].sp_dt[0] = 1.4f;
    inputZReg[1].sp_dt[1] = 1.5f;
    inputZReg[1].sp_dt[2] = 1.6f;
    inputZReg[1].sp_dt[3] = 2.4f;
    inputZReg[2].sp_dt[0] = 2.5f;
    inputZReg[2].sp_dt[1] = 2.6f;
    inputZReg[2].sp_dt[2] = 3.5f;
    inputZReg[2].sp_dt[3] = 4.5f;
    inputZReg[3].sp_dt[0] = 5.5f;
    inputZReg[3].us_dt[1] = 0x4efffffd;
    inputZReg[3].us_dt[2] = 0x4efffffe;
    inputZReg[3].us_dt[3] =
        0x4effffff; /* max float number represented by int32_t */

    inputZReg[4].sp_dt[0] = 0.0f;
    inputZReg[4].sp_dt[1] = -0.4f;
    inputZReg[4].sp_dt[2] = -0.5f;
    inputZReg[4].sp_dt[3] = -0.6f;
    inputZReg[5].sp_dt[0] = -1.4f;
    inputZReg[5].sp_dt[1] = -1.5f;
    inputZReg[5].sp_dt[2] = -1.6f;
    inputZReg[5].sp_dt[3] = -2.4f;
    inputZReg[6].sp_dt[0] = -2.5f;
    inputZReg[6].sp_dt[1] = -2.6f;
    inputZReg[6].sp_dt[2] = -3.5f;
    inputZReg[6].sp_dt[3] = -4.5f;
    inputZReg[7].sp_dt[0] = -5.5f;
    inputZReg[7].us_dt[1] = 0xcefffffd;
    inputZReg[7].us_dt[2] = 0xcefffffe;
    inputZReg[7].us_dt[3] =
        0xceffffff; /* min float number represented by int32_t */
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12, r13, r14,
     * r15 */
    unsigned int rounding_direction = 1;

    /* Register index is VEX range. */
    vroundps(Xmm(8), Xmm(0), rounding_direction);
    vroundps(Xmm(9), Xmm(1), rounding_direction);
    vroundps(Xmm(10), Xmm(2), rounding_direction);
    vroundps(Xmm(11), Xmm(3), rounding_direction);
    vroundps(Xmm(12), Xmm(4), rounding_direction);
    vroundps(Xmm(13), Xmm(5), rounding_direction);
    vroundps(Xmm(14), Xmm(6), rounding_direction);
    vroundps(Xmm(15), Xmm(7), rounding_direction);
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
