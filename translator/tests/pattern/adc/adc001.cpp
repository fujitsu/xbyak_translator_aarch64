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
    mov(r8, std::numeric_limits<uint64_t>::max());
    mov(r9, std::numeric_limits<uint64_t>::max());
    mov(r10, std::numeric_limits<uint64_t>::max());
    mov(r11, std::numeric_limits<uint64_t>::max());
    mov(r12, std::numeric_limits<uint64_t>::max());
    mov(r13, std::numeric_limits<uint64_t>::max());
    mov(r14, std::numeric_limits<uint64_t>::max());
    mov(r15, std::numeric_limits<uint64_t>::max());

    mov(rax, ~uint64_t(0));
    mov(rcx, 1);
    add(rax, rcx); // initialize carry bit(set carry bit for x86)
    adc(r8, 1);

    mov(rax, ~uint64_t(0));
    mov(rcx, 1);
    add(rax, rcx); // initialize carry bit(set carry bit for x86)
    adc(r9, -1);

    mov(rax, ~uint64_t(0));
    mov(rcx, 1);
    add(rax, rcx); // initialize carry bit(set carry bit for x86)
    adc(r10, std::numeric_limits<uint32_t>::max());

    mov(rax, ~uint64_t(0));
    mov(rcx, 1);
    add(rax, rcx); // initialize carry bit(set carry bit for x86)
    adc(r11, 0);

    mov(rax, ~uint64_t(0));
    mov(rcx, 1);
    add(rax, rcx); // initialize carry bit(set carry bit for x86)
    adc(r12d, 1);

    mov(rax, ~uint64_t(0));
    mov(rcx, 1);
    add(rax, rcx); // initialize carry bit(set carry bit for x86)
    adc(r13d, -1);

    mov(rax, ~uint64_t(0));
    mov(rcx, 1);
    add(rax, rcx); // initialize carry bit(set carry bit for x86)
    adc(r14d, std::numeric_limits<uint32_t>::max());

    mov(rax, ~uint64_t(0));
    mov(rcx, 1);
    add(rax, rcx); // initialize carry bit(set carry bit for x86)
    adc(r15d, 0);
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
