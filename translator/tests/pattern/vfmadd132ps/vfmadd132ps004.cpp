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
    setInputZregAllRandomFloat();
    setDumpZRegMode(SP_DT); // set float mode
    for (unsigned int j = 0; j < NUM_Z_REG; j++) {
      for (unsigned int i = 0; i < NUM_BYTES_Z_REG / sizeof(float); i++) {
        inputZReg[j].sp_dt[i] = float((0.5 + i) * (j));
      }
    }
    inputPredReg[1] = uint64_t(0);
    inputPredReg[2] = ~uint64_t(0);
#ifndef __ARM_ARCH
    inputPredReg[3] = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
    inputPredReg[4] = (1 << 3) | (1 << 6);
    inputPredReg[5] = (1 << 0) | (1 << 10) | (1 << 3) | (1 << 6);
#else
    inputPredReg[3] = (1 << 16) | (1 << 20) | (1 << 24) | (1 << 28);
    inputPredReg[4] = (1 << 12) | (1 << 24);
    inputPredReg[5] = (1 << 0) | (uint64_t(1) << 40) | (1 << 12) | (1 << 24);
#endif
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr5;
    size_t addr6;
    size_t addr7;
    size_t addr8;
    size_t addr9;

/* Address is aligned */
#if 1
    /*addr = reinterpret_cast<size_t>(&(inputZReg[2].ud_dt[0]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[4].ud_dt[0]));
    addr2 = reinterpret_cast<size_t>(&(inputZReg[5].ud_dt[0]));
    addr3 = reinterpret_cast<size_t>(&(inputZReg[8].ud_dt[0]));
    addr4 = reinterpret_cast<size_t>(&(inputZReg[9].ud_dt[0]));

    mov(rax, addr);
    vfmadd132ps(Zmm(0), Zmm(1), ptr[rax]);
    vmovdqu8(Zmm(10), ptr[rax]);
    mov(rax, addr1);
    vfmadd132ps(Zmm(3), Zmm(3), ptr[rax]);
    vmovdqu8(Zmm(11), ptr[rax]);
    mov(rax, addr2);
    vfmadd132ps(Zmm(5), Zmm(6), ptr[rax]);
    vmovdqu8(Zmm(12), ptr[rax]);
    mov(rax, addr3);
    vfmadd132ps(Zmm(7), Zmm(8), ptr[rax]);
    vmovdqu8(Zmm(13), ptr[rax]);
    mov(rax, addr4);
    vfmadd132ps(Zmm(9), Zmm(9), ptr[rax]);
    vmovdqu8(Zmm(14), ptr[rax]);*/

    addr5 = reinterpret_cast<size_t>(&(inputZReg[18].ud_dt[0]));
    addr6 = reinterpret_cast<size_t>(&(inputZReg[20].ud_dt[0]));
    addr7 = reinterpret_cast<size_t>(&(inputZReg[21].ud_dt[0]));
    addr8 = reinterpret_cast<size_t>(&(inputZReg[23].ud_dt[0]));
    addr9 = reinterpret_cast<size_t>(&(inputZReg[24].ud_dt[0]));

    mov(rax, addr5);
    vfmadd132ps(Zmm(16) | k1 | T_z, Zmm(17), ptr[rax]);
    vmovdqu8(Zmm(25), ptr[rax]);
    mov(rax, addr6);
    vfmadd132ps(Zmm(19) | k2 | T_z, Zmm(19), ptr[rax]);
    vmovdqu8(Zmm(26), ptr[rax]);
    mov(rax, addr7);
    vfmadd132ps(Zmm(21) | k3 | T_z, Zmm(22), ptr[rax]);
    vmovdqu8(Zmm(27), ptr[rax]);
    mov(rax, addr8);
    vfmadd132ps(Zmm(22) | k4 | T_z, Zmm(23), ptr[rax]);
    vmovdqu8(Zmm(28), ptr[rax]);
    mov(rax, addr9);
    vfmadd132ps(Zmm(24) | k5 | T_z, Zmm(24), ptr[rax]);
    vmovdqu8(Zmm(29), ptr[rax]);
    mov(rax,
        size_t(0x5)); // Clear RAX for diff check between x86_64 and aarch64
    mov(rbx,
        size_t(0xf)); // Clear RAX for diff check between x86_64 and aarch64
#endif

    mov(rax, 0x1);
#ifndef __ARM_ARCH
    kmovq(k3, rax);
    kmovq(k4, rax);
    kmovq(k5, rax);
#else
    ptrue(p3.b, Xbyak_aarch64::VL1);
    ptrue(p4.b, Xbyak_aarch64::VL1);
    ptrue(p5.b, Xbyak_aarch64::VL1);
#endif
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
