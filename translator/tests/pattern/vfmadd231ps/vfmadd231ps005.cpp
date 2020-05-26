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
    inputPredReg[1] = uint64_t(0);
    inputPredReg[2] = ~uint64_t(0);
    inputPredReg[3] =
        (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); /* Both x86_64 and aarch64 */
    inputPredReg[4] = (1 << 3) | (1 << 6);         /* Both x86_64 and aarch64 */
    inputPredReg[5] = (1 << 0) | (1 << 10) | (1 << 3) |
                      (1 << 6); /* Both x86_64 and aarch64 */
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12, r13, r14,
     * r15 */

    /* VEX encode */
    vfmadd231ps(Xmm(0) | k1 | T_z, Xmm(1), Xmm(2));
    vfmadd231ps(Xmm(3) | k2 | T_z, Xmm(3), Xmm(4));
    vfmadd231ps(Xmm(5) | k3 | T_z, Xmm(6), Xmm(5));
    vfmadd231ps(Xmm(7) | k4 | T_z, Xmm(8), Xmm(8));
    vfmadd231ps(Xmm(9) | k5 | T_z, Xmm(9), Xmm(9));

    /* EVEX encode */
    vfmadd231ps(Xmm(10) | k1 | T_z, Xmm(11), Xmm(12));
    vfmadd231ps(Xmm(13) | k2 | T_z, Xmm(13), Xmm(14));
    vfmadd231ps(Xmm(15) | k3 | T_z, Xmm(16), Xmm(15));
    vfmadd231ps(Xmm(17) | k4 | T_z, Xmm(18), Xmm(18));
    vfmadd231ps(Xmm(19) | k5 | T_z, Xmm(19), Xmm(19));
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
