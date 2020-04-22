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
    //    setInputZregAllRandomHex();
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12,
       r13, r14, r15 */

    mov(r8, uint64_t(0x7FFFFFFFF));
    adc(r10, r11);
    mov(r10, 2);
    imul(r8, r8);
    adc(r11, r10);

    // mov(edx, ~uint32_t(0));
    /* initialize carry bit (set carry bit for x86)*/
    /*
    mov(edx, ~uint32_t(0));
    mov(ebx, 1);
    add(edx, ebx);
    mov(edx, 1);
    mov(ebx, 1);
    adc(edx, ebx);

    mov(rbp, ~uint64_t(0));
    mov(rsi, ~uint64_t(0));
    add(rbp, rsi); // initialize carry bit(set carry bit for x86)
    mov(rbp, ~uint64_t(0));
    mov(rsi, ~uint64_t(0));
    adc(rbp, rsi);

    mov(edi, ~uint32_t(0));
    mov(r8d, ~uint32_t(0));
    add(edi, r8d); // initialize carry bit(set carry bit for x86)
    mov(edi, ~uint32_t(0));
    mov(r8d, ~uint32_t(0));
    adc(edi, r8d);

    mov(r9, ~uint64_t(0));
    mov(r10, ~uint64_t(0));
    add(r9d, r10d); // initialize carry bit(set carry bit for x86)
    mov(r9, ~uint64_t(0));
    mov(r10, ~uint64_t(0));
    adc(r9d, r10d);

    mov(r11, ~uint64_t(0));
    add(r11, r11); // initialize carry bit(set carry bit for x86)
    mov(r11, ~uint64_t(0));
    adc(r11, 0);

    mov(r12d, ~uint32_t(0));
    add(r12d, r12d); // initialize carry bit(set carry bit for x86)
    mov(r12d, ~uint32_t(0));
    adc(r12d, 0);
    */
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
