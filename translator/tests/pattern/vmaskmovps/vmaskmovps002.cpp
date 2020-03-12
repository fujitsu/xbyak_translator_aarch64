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

    for (int i = 0; i < 8; i++) {
      inputZReg[7].us_dt[i * 2] = inputZReg[10].us_dt[i * 2] =
          inputZReg[13].us_dt[i * 2] = uint32_t(1) << 31;
      inputZReg[7].us_dt[i * 2 + 1] = inputZReg[10].us_dt[i * 2 + 1] =
          inputZReg[13].us_dt[i * 2 + 1] = 0;
      inputZReg[8].us_dt[i * 2] = inputZReg[11].us_dt[i * 2] =
          inputZReg[14].us_dt[i * 2] = uint32_t(0x7FFFFFFF);
      inputZReg[8].us_dt[i * 2 + 1] = inputZReg[11].us_dt[i * 2 + 1] =
          inputZReg[14].us_dt[i * 2 + 1] = ~uint32_t(0);
      inputZReg[9].us_dt[i * 2] = inputZReg[12].us_dt[i * 2] =
          inputZReg[15].us_dt[i * 2] = uint32_t(0);
      inputZReg[9].us_dt[i * 2 + 1] = inputZReg[12].us_dt[i * 2 + 1] =
          inputZReg[15].us_dt[i * 2 + 1] = ~uint32_t(0);
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;

    /* Address is aligned */
    addr = reinterpret_cast<size_t>(&(inputZReg[31].ud_dt[0]));
    mov(rax, addr);
    vmaskmovps(Xmm(0), Xmm(13), ptr[rax]);
    vmaskmovps(Xmm(1), Xmm(14), ptr[rax]);
    vmaskmovps(Xmm(2), Xmm(15), ptr[rax]);

    vmaskmovps(Ymm(3), Ymm(13), ptr[rax]);
    vmaskmovps(Ymm(4), Ymm(14), ptr[rax]);
    vmaskmovps(Ymm(5), Ymm(15), ptr[rax]);

    vmaskmovps(Ymm(7), Ymm(7), ptr[rax]);
    vmaskmovps(Ymm(8), Ymm(8), ptr[rax]);
    vmaskmovps(Ymm(9), Ymm(9), ptr[rax]);

    vmaskmovps(Ymm(10), Ymm(10), ptr[rax]);
    vmaskmovps(Ymm(11), Ymm(11), ptr[rax]);
    vmaskmovps(Ymm(12), Ymm(12), ptr[rax]);

    mov(rax,
        size_t(0x5)); // Clear RAX for diff check between x86_64 and aarch64
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
