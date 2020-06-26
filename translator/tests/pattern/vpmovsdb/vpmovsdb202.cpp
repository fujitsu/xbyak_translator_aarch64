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
    // inputZReg[0].us_dt[0] = uint32_t(7);
    // inputZReg[4].us_dt[0] = uint32_t(7);

    inputPredReg[1] = (1 << 0) | (1 << 2) | (1 << 7) | (1 << 8) |
                      (1 << 15) | (1 << 28) | (uint64_t(1) << 32) | (uint64_t(1) << 60); /* Both x86_64 and aarch64 */

    inputPredReg[7] = ~uint64_t(0);
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;
    size_t addr1;

/* Address is aligned */
#if 0
    addr = reinterpret_cast<size_t>(&(inputZReg[31].ud_dt[0]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[30].ud_dt[0]));
    addr2 = reinterpret_cast<size_t>(&(inputZReg[29].ud_dt[0]));
    mov(rax, addr);
    vpmovsdb(ptr[rax], Zmm(0) | k1);
    vmovdqu8(Zmm(1), ptr[rax]);
    mov(rbx, addr1);
    vpmovsdb(ptr[rbx], Zmm(2) | k2);
    vmovdqu8(Zmm(3), ptr[rbx]);
    mov(rbx, addr2);
    vpmovsdb(ptr[rbx], Zmm(4) | k7);
    vmovdqu8(Zmm(5), ptr[rbx]);

    addr = reinterpret_cast<size_t>(&(inputZReg[28].ud_dt[0]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[27].ud_dt[0]));
    addr2 = reinterpret_cast<size_t>(&(inputZReg[26].ud_dt[0]));
    mov(rax, addr);
    mov(rbx, addr1);
    mov(rbx, addr2);
    vpmovsdb(ptr[rax], Ymm(6) | k1);
    vmovdqu8(Zmm(7), ptr[rax]);
    vpmovsdb(ptr[rbx], Ymm(8) | k2);
    vmovdqu8(Zmm(9), ptr[rbx]);
    vpmovsdb(ptr[rbx], Ymm(10) | k7);
    vmovdqu8(Zmm(11), ptr[rbx]);

    addr = reinterpret_cast<size_t>(&(inputZReg[25].ud_dt[0]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[24].ud_dt[0]));
    addr2 = reinterpret_cast<size_t>(&(inputZReg[23].ud_dt[0]));
    mov(rax, addr);
    mov(rbx, addr1);
    mov(rbx, addr2);
    vpmovsdb(ptr[rax], Xmm(12) | k1);
    vmovdqu8(Zmm(13), ptr[rax]);
    vpmovsdb(ptr[rbx], Xmm(14) | k2);
    vmovdqu8(Zmm(15), ptr[rbx]);
    vpmovsdb(ptr[rbx], Xmm(16) | k7);
    vmovdqu8(Zmm(17), ptr[rbx]);

#endif

/* Address is unaligned */
#if 1
    addr = reinterpret_cast<size_t>(&(inputZReg[30].ud_dt[0])) + 5;
    addr1 = reinterpret_cast<size_t>(&(inputZReg[28].ud_dt[0])) + 3;
    mov(rax, addr);
    mov(rbx, addr1);
    vpmovsdb(ptr[rax], Zmm(0) | k1);
    vmovdqu8(Zmm(1), ptr[rax]);
    vpmovsdb(ptr[rbx], Zmm(4) | k7);
    vmovdqu8(Zmm(5), ptr[rbx]);

    addr = reinterpret_cast<size_t>(&(inputZReg[26].ud_dt[0])) + 5;
    addr1 = reinterpret_cast<size_t>(&(inputZReg[24].ud_dt[0])) + 3;
    mov(rax, addr);
    mov(rbx, addr1);
    vpmovsdb(ptr[rax], Ymm(6) | k1);
    vmovdqu8(Zmm(7), ptr[rax]);
    vpmovsdb(ptr[rbx], Ymm(10) | k7);
    vmovdqu8(Zmm(11), ptr[rbx]);

    addr = reinterpret_cast<size_t>(&(inputZReg[22].ud_dt[0])) + 5;
    addr1 = reinterpret_cast<size_t>(&(inputZReg[20].ud_dt[0])) + 3;
    mov(rax, addr);
    mov(rbx, addr1);
    vpmovsdb(ptr[rax], Xmm(12) | k1);
    vmovdqu8(Zmm(13), ptr[rax]);
    vpmovsdb(ptr[rbx], Xmm(16) | k7);
    vmovdqu8(Zmm(17), ptr[rbx]);
#endif

    mov(rax,
        size_t(0x5)); // Clear RAX for diff check between x86_64 and aarch64
    mov(rbx,
        size_t(0xf)); // Clear RBX for diff check between x86_64 and aarch64
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
