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

    inputZReg[15].us_dt[0] = ~uint32_t(0);
    inputZReg[15].us_dt[1] = uint32_t(1) << 31;
    inputZReg[15].us_dt[2] = ~(uint32_t(1) << 31);
    inputZReg[15].us_dt[3] = 0;

    inputZReg[8].us_dt[0] = ~uint32_t(0);
    inputZReg[8].us_dt[1] = uint32_t(1) << 31;
    inputZReg[8].us_dt[2] = ~(uint32_t(1) << 31);
    inputZReg[8].us_dt[3] = 0;

    inputZReg[9].us_dt[1] = ~uint32_t(0);
    inputZReg[9].us_dt[2] = uint32_t(1) << 31;
    inputZReg[9].us_dt[3] = ~(uint32_t(1) << 31);
    inputZReg[9].us_dt[0] = 0;

    inputZReg[10].us_dt[2] = ~uint32_t(0);
    inputZReg[10].us_dt[3] = uint32_t(1) << 31;
    inputZReg[10].us_dt[0] = ~(uint32_t(1) << 31);
    inputZReg[10].us_dt[1] = 0;

    inputZReg[11].us_dt[3] = ~uint32_t(0);
    inputZReg[11].us_dt[1] = uint32_t(1) << 31;
    inputZReg[11].us_dt[2] = ~(uint32_t(1) << 31);
    inputZReg[11].us_dt[3] = 0;
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12, r13, r14,
     * r15 */
    unsigned int rounding_direction = 0;

    /* Register index is VEX range. */
    vpsignd(xmm8, xmm8, xmm15);
    vpsignd(xmm9, xmm9, xmm15);
    vpsignd(xmm9, xmm9, xmm15);
    vpsignd(xmm9, xmm9, xmm15);
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
