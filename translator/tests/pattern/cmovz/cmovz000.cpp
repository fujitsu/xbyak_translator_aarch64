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
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* RAX, RCX, RDX, RBX, RSP, RBP, RSI, RDI,
       R8,  R9,  R10, R11, R12, R13, R14, R15 */
#define CMOV cmovz
    
    mov(r8, ~uint64_t(0));
    mov(r9, ~uint64_t(0));
    mov(r10, ~uint64_t(0));
    mov(r11, ~uint64_t(0));
    mov(r12, ~uint64_t(0));
    mov(r13, ~uint64_t(0));
    mov(rbp, ~uint64_t(0));
    mov(rsi, ~uint64_t(0));
    mov(rdi, ~uint64_t(0));

    mov(r15, uint64_t(0xabcd0123456789ab));

    mov(rax, uint64_t(2));
    mov(rcx, uint64_t(1));

    // 64 bits
    // equal
    cmp(rax, rax);
    CMOV(r8, r15);

    // greater 
    cmp(rax, rcx);
    CMOV(r9, r15);

    // less
    cmp(rcx, rax);
    CMOV(r10, r15);

    // 32 bits
    // equal
    cmp(rax, rax);
    CMOV(r11d, r15d);

    // greater 
    cmp(rax, rcx);
    CMOV(r12d, r15d);

    // less
    cmp(rcx, rax);
    CMOV(r13d, r15d);

    // 16 bits
    // equal
    cmp(rax, rax);
    CMOV(bp, r15w);

    // greater 
    cmp(rax, rcx);
    CMOV(si, r15w);

    // less
    cmp(rcx, rax);
    CMOV(di, r15w);
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
