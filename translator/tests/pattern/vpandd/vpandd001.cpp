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
    addr = reinterpret_cast<size_t>(&(inputZReg[31].ud_dt[0]));

    mov(rax, addr);
    //    vandps(Xmm(1), Xmm(0), ptr[rax]);
    //    vandps(Ymm(2), Ymm(0), ptr[rax]);
    vpandd(Zmm(3), Zmm(0), ptr[rax]);

    //    vandps(Xmm(4), Xmm(0), ptr_b[rax]);
    //    vandps(Ymm(5), Ymm(0), ptr_b[rax]);
    //    vpandd(Zmm(6), Zmm(0), ptr_b[rax]);

    //    vandps(Xmm(7), Xmm(7), ptr[rax]);
    //    vandps(Ymm(8), Ymm(8), ptr[rax]);
    vpandd(Zmm(9), Zmm(9), ptr[rax]);

    //    vandps(Xmm(10), Xmm(10), ptr_b[rax]);
    //    vandps(Ymm(11), Ymm(11), ptr_b[rax]);
    //    vpandd(Zmm(12), Zmm(12), ptr_b[rax]);

    vpandd(Zmm(21), Zmm(22), ptr[rax]);

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
