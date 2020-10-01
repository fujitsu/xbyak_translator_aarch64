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
      inputZReg[3].ub_dt[i] = uint8_t(i);
      inputZReg[31].ub_dt[i] = uint8_t(i);
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;
    size_t addr1;
    size_t addr2;

/* Address is aligned */
#if 1
    addr = reinterpret_cast<size_t>(&(inputZReg[15].ud_dt[0]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[13].ud_dt[0]));
    addr2 = reinterpret_cast<size_t>(&(inputZReg[11].ud_dt[0]));
    mov(rax, addr);
    vpextrb(ptr[rax], Xmm(3), 10);
    vmovdqu8(Xmm(4), ptr[rax]);
    mov(rax, addr1);
    vpextrb(ptr[rax], Xmm(3), 7);
    vmovdqu8(Xmm(5), ptr[rax]);
    mov(rax, addr2);
    vpextrb(ptr[rax], Xmm(3), 24);
    vmovdqu8(Xmm(6), ptr[rax]);

#endif

/* Address is unaligned */
#if 1
    addr = reinterpret_cast<size_t>(&(inputZReg[10].ud_dt[0])) + 4;
    addr1 = reinterpret_cast<size_t>(&(inputZReg[11].ud_dt[0])) + 8;
    addr2 = reinterpret_cast<size_t>(&(inputZReg[12].ud_dt[0])) + 12;
    mov(rax, addr);
    vpextrb(ptr[rax], Xmm(3), 0);
    vmovdqu8(Xmm(7), ptr[rax]);
    mov(rax, addr1);
    vpextrb(ptr[rax], Xmm(3), 15);
    vmovdqu8(Xmm(8), ptr[rax]);
    mov(rax, addr2);
    vpextrb(ptr[rax], Xmm(3), 16);
    vmovdqu8(Xmm(9), ptr[rax]);
#endif

/* Address is aligned */
#if 1
    addr = reinterpret_cast<size_t>(&(inputZReg[27].ud_dt[0]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[28].ud_dt[0]));
    addr2 = reinterpret_cast<size_t>(&(inputZReg[29].ud_dt[0]));
    mov(rax, addr);
    vpextrb(ptr[rax], Xmm(31), 10);
    vmovdqu8(Xmm(17), ptr[rax]);
    mov(rax, addr1);
    vpextrb(ptr[rax], Xmm(31), 7);
    vmovdqu8(Xmm(18), ptr[rax]);
    mov(rax, addr2);
    vpextrb(ptr[rax], Xmm(31), 24);
    vmovdqu8(Xmm(19), ptr[rax]);

#endif

/* Address is unaligned */
#if 1
    addr = reinterpret_cast<size_t>(&(inputZReg[24].ud_dt[0])) + 4;
    addr1 = reinterpret_cast<size_t>(&(inputZReg[25].ud_dt[0])) + 8;
    addr2 = reinterpret_cast<size_t>(&(inputZReg[26].ud_dt[0])) + 12;
    mov(rax, addr);
    vpextrb(ptr[rax], Xmm(31), 0);
    vmovdqu8(Xmm(20), ptr[rax]);
    mov(rax, addr1);
    vpextrb(ptr[rax], Xmm(31), 15);
    vmovdqu8(Xmm(21), ptr[rax]);
    mov(rax, addr2);
    vpextrb(ptr[rax], Xmm(31), 16);
    vmovdqu8(Xmm(22), ptr[rax]);
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
