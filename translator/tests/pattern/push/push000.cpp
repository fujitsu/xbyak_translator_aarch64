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
/* undef XT_TEST, XT_AARCH64_STACK_REG
    push/pop instruction add/sub 8 to value of stack pointer register.
    If SP(x31) register is used as address register on AArch64
    the access address must be aligned 16 bytes, otherwise exception is occured.
    To avoid exception in this test pattern, use x4 as a stack pointer.
 */
#undef XT_TEST
#undef XT_AARCH64_STACK_REG

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
    addr = reinterpret_cast<size_t>(&(inputZReg[0].ud_dt[7]));
    mov(rax, addr);
    mov(rbx, ptr[rax]);

#ifdef XBYAK_TRANSLATE_AARCH64
    CodeGeneratorAArch64::mov(X_TRANSLATOR_STACK, CodeGeneratorAArch64::sp);
    CodeGeneratorAArch64::mov(x8, X_TRANSLATOR_STACK);
#endif

    push(rbx);
    pop(rcx);

#ifdef XBYAK_TRANSLATE_AARCH64
    // Check if stack address is recovered
    CodeGeneratorAArch64::sub(X_TRANSLATOR_STACK, X_TRANSLATOR_STACK, x8);
#endif
    mov(rax, 5);
    mov(r8, 5); // clear temporary register
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
