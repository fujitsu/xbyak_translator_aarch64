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
    for (int j = 0; j < NUM_Z_REG; j++) {
      for (int i = 0; i < NUM_BYTES_Z_REG / sizeof(float); i++) {
        inputZReg[j].sp_dt[i] = float((0.5 + i) * (j));
      }
    }
    inputPredReg[1] = uint64_t(0);
    inputPredReg[2] = ~uint64_t(0);
    inputPredReg[3] =
        (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); /* Both x86_64 and aarch64 */
    inputPredReg[4] = (1 << 3) | (1 << 6);         /* Both x86_64 and aarch64 */
    inputPredReg[5] = (1 << 0) | (1 << 10) | (1 << 3) |
                      (1 << 6); /* Both x86_64 and aarch64 */
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;
    size_t addr1;
    size_t addr2;
    size_t addr3;
    size_t addr4;
    size_t addr5;
    size_t addr6;
    size_t addr7;
    size_t addr8;
    size_t addr9;

/* Address is aligned */
#if 1
    addr5 = reinterpret_cast<size_t>(&(inputZReg[18].ud_dt[0]));
    addr6 = reinterpret_cast<size_t>(&(inputZReg[20].ud_dt[0]));
    addr7 = reinterpret_cast<size_t>(&(inputZReg[21].ud_dt[0]));
    addr8 = reinterpret_cast<size_t>(&(inputZReg[23].ud_dt[0]));
    addr9 = reinterpret_cast<size_t>(&(inputZReg[24].ud_dt[0]));

    mov(rax, addr5);
    vfmadd213ps(Zmm(16) | k1, Zmm(17), ptr[rax]);
    mov(rax, addr6);
    vfmadd213ps(Zmm(19) | k2, Zmm(19), ptr[rax]);
    mov(rax, addr7);
    vfmadd213ps(Zmm(21) | k3, Zmm(22), ptr[rax]);
    mov(rax, addr8);
    vfmadd213ps(Zmm(22) | k4, Zmm(23), ptr[rax]);
    mov(rax, addr9);
    vfmadd213ps(Zmm(24) | k5, Zmm(24), ptr[rax]);
    mov(rax,
        size_t(0x5)); // Clear RAX for diff check between x86_64 and aarch64
    mov(rbx,
        size_t(0xf)); // Clear RAX for diff check between x86_64 and aarch64
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
