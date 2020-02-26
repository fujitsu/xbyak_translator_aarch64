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
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;
    size_t addr1;

    /* Address is aligned */
#if 1
    addr = reinterpret_cast<size_t>(&(inputZReg[6].ud_dt[0]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[7].ud_dt[0]));
    mov(rax, addr);
    mov(rbx, addr);
    vmovdqu8(Xmm(0), ptr[rax]);
    vmovdqu8(ptr[rbx], Xmm(0));
    vmovdqu8(Zmm(1), ptr[rbx]);
#endif

#if 1
    addr = reinterpret_cast<size_t>(&(inputZReg[8].ud_dt[0]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[9].ud_dt[0]));
    mov(rax, addr);
    mov(rbx, addr);
    vmovdqu8(Ymm(2), ptr[rax]);
    vmovdqu8(ptr[rbx], Ymm(2));
    vmovdqu8(Zmm(3), ptr[rbx]);
#endif

#if 1
    addr = reinterpret_cast<size_t>(&(inputZReg[10].ud_dt[0]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[11].ud_dt[0]));
    mov(rax, addr);
    mov(rbx, addr);
    vmovdqu8(Zmm(4), ptr[rax]);
    vmovdqu8(ptr[rbx], Zmm(4));
    vmovdqu8(Zmm(5), ptr[rbx]);
#endif

    /* Address is unaligned */
#if 1
    addr = reinterpret_cast<size_t>(&(inputZReg[18].ud_dt[0])) + 3;
    addr1 = reinterpret_cast<size_t>(&(inputZReg[19].ud_dt[0])) + 5;
    mov(rax, addr);
    mov(rbx, addr);
    vmovdqu8(Xmm(12), ptr[rax]);
    vmovdqu8(ptr[rbx], Xmm(12));
    vmovdqu8(Zmm(13), ptr[rbx]);
#endif

#if 1
    addr = reinterpret_cast<size_t>(&(inputZReg[20].ud_dt[0])) + 1;
    addr1 = reinterpret_cast<size_t>(&(inputZReg[21].ud_dt[0])) + 7;
    mov(rax, addr);
    mov(rbx, addr);
    vmovdqu8(Ymm(14), ptr[rax]);
    vmovdqu8(ptr[rbx], Ymm(14));
    vmovdqu8(Zmm(15), ptr[rbx]);
#endif

#if 1
    addr = reinterpret_cast<size_t>(&(inputZReg[22].ud_dt[0])) + 1;
    addr1 = reinterpret_cast<size_t>(&(inputZReg[23].ud_dt[0])) + 7;
    mov(rax, addr);
    mov(rbx, addr);
    vmovdqu8(Zmm(16), ptr[rax]);
    vmovdqu8(ptr[rbx], Zmm(16));
    vmovdqu8(Zmm(17), ptr[rbx]);
#endif

    mov(rax,
        size_t(0x5)); // Clear RAX for diff check between x86_64 and aarch64
    mov(rbx,
        size_t(0xf)); // Clear RAX for diff check between x86_64 and aarch64
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
