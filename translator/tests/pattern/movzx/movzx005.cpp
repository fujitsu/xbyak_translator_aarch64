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
    inputZReg[0].ud_dt[7] = uint64_t(0x000000000000007f);
    inputZReg[1].ud_dt[7] = uint64_t(0x0000000000000080);
    inputZReg[2].ud_dt[7] =  uint64_t(1);
    inputZReg[3].ud_dt[7] =  ~uint64_t(0);
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* RAX, RCX, RDX, RBX, RSP, RBP, RSI, RDI,
       R8,  R9,  R10, R11, R12, R13, R14, R15 */
    size_t addr0, addr1, addr2, addr3;
    addr0 = reinterpret_cast<size_t>(&(inputZReg[0].ud_dt[7]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[1].ud_dt[7]));
    addr2 = reinterpret_cast<size_t>(&(inputZReg[2].ud_dt[7]));
    addr3 = reinterpret_cast<size_t>(&(inputZReg[3].ud_dt[7]));
    
    mov(rax, addr0);
    mov(rcx, addr1);
    mov(rdx, addr2);
    mov(rbx, addr3);
    
    movzx(r12, byte[rax]);
    movzx(r13, byte[rcx]);
    movzx(r14, byte[rdx]);
    movzx(r15, byte[rbx]);

    mov(rax,
        size_t(0x5)); // Clear RAX for diff check between x86_64 and aarch64
    mov(rcx,
        size_t(0x5)); // Clear RAX for diff check between x86_64 and aarch64
    mov(rdx,
        size_t(0x5)); // Clear RAX for diff check between x86_64 and aarch64
    mov(rbx,
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
