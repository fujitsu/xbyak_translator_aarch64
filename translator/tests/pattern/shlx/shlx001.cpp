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

    for (int i = 0; i < 16; i++) {
      if (i != rsp.getIdx()) {
        inputGenReg[i] = inputZReg[i].ud_dt[0];
      }
    }

    inputGenReg[8] = 4;
    inputGenReg[9] = 7;
    inputGenReg[10] = 31;
    inputGenReg[11] = 32;
    inputGenReg[12] = 42;
    inputGenReg[13] = 63;
    inputGenReg[14] = 4 + 64;
    inputGenReg[15] = 42 + 64;
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* RAX, RCX, RDX, RBX, RSP, RBP, RSI, RDI,
       R8,  R9,  R10, R11, R12, R13, R14, R15 */

    size_t addr;
    addr = reinterpret_cast<size_t>(&(inputZReg[7].ud_dt[0]));
    mov(rdi, addr);

    shlx(rax, ptr[rdi], r8);
    shlx(rcx, ptr[rdi], r8);

    //    shlx(rbx, rbx, r8);
    shlx(rbp, ptr[rdi], rbp);
    //    shlx(rsi, rsi, rsi);

    shlx(r8, ptr[rdi], r8);
    shlx(r9, ptr[rdi], r9);
    shlx(r10, ptr[rdi], r10);
    shlx(r11, ptr[rdi], r11);
    shlx(r12, ptr[rdi], r12);
    shlx(r13, ptr[rdi], r13);
    shlx(r14, ptr[rdi], r14);
    shlx(r15, ptr[rdi], r15);

    mov(rdi,
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
