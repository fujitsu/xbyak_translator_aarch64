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
    setInputZregAllRandomFloat();
    setDumpZRegMode(SP_DT); // set float mode

    for (int j = 0; j < NUM_Z_REG; j++) {
      for (int i = 0; i < NUM_BYTES_Z_REG / sizeof(float); i++) {
        inputZReg[j].sp_dt[i] = float((0.5 + i) * (j));
      }
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12, r13, r14,
     * r15 */

    /* VEX encode */
    vfmadd132ps(Xmm(0), Xmm(1), Xmm(2));
    vfmadd132ps(Xmm(3), Xmm(3), Xmm(4));
    vfmadd132ps(Xmm(5), Xmm(6), Xmm(5));
    vfmadd132ps(Xmm(7), Xmm(8), Xmm(8));
    vfmadd132ps(Xmm(9), Xmm(9), Xmm(9));

    /* EVEX encode */
    vfmadd132ps(Xmm(20), Xmm(21), Xmm(22));
    vfmadd132ps(Xmm(23), Xmm(23), Xmm(24));
    vfmadd132ps(Xmm(25), Xmm(26), Xmm(25));
    vfmadd132ps(Xmm(27), Xmm(28), Xmm(28));
    vfmadd132ps(Xmm(29), Xmm(29), Xmm(29));
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
