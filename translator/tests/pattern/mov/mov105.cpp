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
        inputGenReg[i] = ~uint64_t(0);
      }
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;

    /* Address is aligned */
    addr = reinterpret_cast<size_t>(&(inputZReg[0].ud_dt[0]));

    mov(rax, addr);

    /* mov m8, imm8 */
    mov(byte[rax + 64 * 0], uint8_t(0xaa));
    mov(r8, ptr[rax + 64 * 0]);

    mov(byte[rax + 64 * 1], uint8_t(0xbb));
    mov(r9, ptr[rax + 64 * 1]);

    /* mov m16, imm16 */
    mov(word[rax + 64 * 2], uint16_t(0x1234));
    mov(r10, ptr[rax + 64 * 2]);

    mov(word[rax + 64 * 3], uint16_t(0x5678));
    mov(r11, ptr[rax + 64 * 3]);

    mov(word[rax + 64 * 4], uint8_t(0xab));
    mov(r12, ptr[rax + 64 * 4]);

    mov(word[rax + 64 * 5], uint8_t(0xcd));
    mov(r13, ptr[rax + 64 * 5]);

    mov(rax, 0x5);
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
