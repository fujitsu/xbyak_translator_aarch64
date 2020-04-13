
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

    /*    mov(rax, uint64_t(0x10)); //0
        mov(rbx, uint64_t(0x5)); //3
        mov(rcx, uint64_t(0x15)); //1
        mov(rdx, uint64_t(0x10)); //2
        mov(rdi, uint64_t(0x10)); //7
        mov(rsi, uint64_t(0x10)); //6
    */
    mov(r8, uint64_t(0x8));
    mov(r9, uint64_t(0x9));
    mov(r10, uint64_t(0x10));
    mov(r11, uint64_t(0x11));
    //    mov(r12, uint64_t(0x12));
    //    mov(r13, uint64_t(0x13));
    //    mov(r14, uint64_t(0x14));
    //    mov(r15, uint64_t(0x15));

    //    add(r9, r8);
    sub(r9, r8);
    //    cmp(r8, r9)
    cmovg(r11, r10);

    //    cmp(r12, r12);
    //    cmovg(r11, r10);

    //    cmovg(r9, r8);
    //    cmovg(r10, r8);
    //    cmovg(r11, r8);

    /*    cmovg(r12, int64_t(0xaaaaaaaaaaaaaaaa));
        cmovg(r13, int32_t(0xaaaaaaaa));
        cmovg(r14, int16_t(0xaaaa));
        cmovg(r15, int8_t(0xaa));

        cmovg(rax, int64_t(0x5555555555555555));
        cmovg(rcx, int32_t(0x55555555));
        cmovg(rdx, int16_t(0x5555));
        cmovg(rbx, int8_t(0x55));
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
