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

    int sel;

    for (int i = 0; i < 5; i++) {
      sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
      vpshufd(Xmm(i + 1), ptr[rax], sel);
    }

    for (int i = 6; i < 11; i++) {
      sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
      vpshufd(Ymm(i + 1), ptr[rax], sel);
    }

    for (int i = 12; i < 17; i++) {
      sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
      vpshufd(Xmm(i + 1), ptr[rax], sel);
    }

    for (int i = 17; i < 22; i++) {
      sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
      vpshufd(Ymm(i + 1), ptr[rax], sel);
    }

    for (int i = 22; i < 27; i++) {
      sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
      vpshufd(Zmm(i + 1), ptr[rax], sel);
    }

    for (int i = 27; i < 30; i++) {
      sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
      vpshufd(Xmm(i + 1), ptr[rax], sel);
    }

    mov(rax, 5);
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
