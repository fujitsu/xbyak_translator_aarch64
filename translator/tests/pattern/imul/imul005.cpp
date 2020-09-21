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
    int64_t *p = &(inputZReg[0].sd_dt[0]);
    *p++ = std::numeric_limits<int64_t>::max();
    *p++ = std::numeric_limits<int64_t>::max() - 1;
    *p++ = 0x10001;
    *p++ = 0xffffffff;
    *p++ = 7;
    *p++ = -7;
    *p++ = -65535;
    *p++ = -65536;
    *p++ = std::numeric_limits<int64_t>::min() + 1;
    *p++ = std::numeric_limits<int64_t>::min();
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12,
       r13, r14, r15 */
    size_t addr0, addr1;

    /* 10 elements are required. */
    std::vector<int8_t> ptn = {127, 126, 7, 1, 0, -1, -7, -61, -127, -128};

    /* Address is aligned */
    addr0 = reinterpret_cast<size_t>(&(inputZReg[0].ud_dt[0]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[16].ud_dt[0]));

    mov(rax, addr0);
    mov(rcx, addr1);

#define NUM_PTN 10
#define DATA_SIZE 8
    for (int j = 0; j < NUM_PTN; j++) {
      int i = 0;
      for (const auto &e : ptn) {
        mov(r9, ptr[rax + DATA_SIZE * j]);
        imul(r8, r9, e);
        mov(ptr[rcx + DATA_SIZE * NUM_PTN * j + DATA_SIZE * i], r8);
        i++;
      }
    }
#undef NUM_PTN
#undef DATA_SIZE

    for (int i = 16; i < 32; i++) {
      vmovdqu32(Zmm(i), ptr[rcx + 64 * (i - 16)]);
    }

    mov(rax, 5);
    mov(rcx, 5);
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
