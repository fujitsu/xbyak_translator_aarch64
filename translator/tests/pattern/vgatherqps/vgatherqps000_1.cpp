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

    inputPredReg[1] = (1 << 0);
    inputPredReg[2] = (1 << 0) | (1 << 7) |           /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 28); /* aarch64 */
    inputPredReg[3] = (1 << 0) | (1 << 7) | (1 << 11) |
                      (uint64_t(1) << 15) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 28) | (uint64_t(1) << 44) |
                      (uint64_t(1) << 60); /* aarch64 */
    inputPredReg[4] = (1 << 0) | (1 << 7) | (1 << 11) | (1 << 13) |
                      (uint64_t(1) << 15) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 28) | (uint64_t(1) << 44) |
                      (uint64_t(1) << 52) | (uint64_t(1) << 60); /* aarch64 */
    inputPredReg[5] = (1 << 0) | (1 << 9) | (1 << 11) | (1 << 13) | (1 << 14) |
                      (uint64_t(1) << 15) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 36) | (uint64_t(1) << 44) |
                      (uint64_t(1) << 52) | (uint64_t(1) << 56) |
                      (uint64_t(1) << 60); /* aarch64 */
    inputPredReg[6] = (1 << 0) | (1 << 9) | (1 << 10) | (1 << 11) | (1 << 13) |
                      (uint64_t(1) << 14) | (uint64_t(1) << 15) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 36) | (uint64_t(1) << 40) |
                      (uint64_t(1) << 44) | (uint64_t(1) << 52) |
                      (uint64_t(1) << 56) | (uint64_t(1) << 60); /* aarch64 */
    inputPredReg[7] = ~uint64_t(0);

    for (int i = 0; i < 8; i++) {
      // inputZReg[21].ud_dt[i] = i*64;
      inputZReg[21].ud_dt[i] = i * 4;
      inputZReg[4].ud_dt[i] = 0;
    }

    for (int i = 2; i < 4; i++) {
      // inputZReg[21].ud_dt[i] = i*64;
      inputZReg[21].ud_dt[i] = 15;
      inputZReg[4].ud_dt[i] = 0;
    }

    for (int i = 4; i < 6; i++) {
      // inputZReg[21].ud_dt[i] = i*64;
      inputZReg[21].ud_dt[i] = 23;
      inputZReg[4].ud_dt[i] = 0;
    }

    for (int i = 6; i < 8; i++) {
      // inputZReg[21].ud_dt[i] = i*64;
      inputZReg[21].ud_dt[i] = 121;
      inputZReg[4].ud_dt[i] = 0;
    }

    // setInputZregAllRandomFloat();
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;

    /* Address is aligned */
    addr = reinterpret_cast<size_t>(&(inputZReg[31].ud_dt[0]));

    mov(rax, addr);

    vgatherqps(Ymm(1) | k1, ptr[rax + Zmm(21) + 4]);
    vgatherqps(Ymm(2) | k2, ptr[rax + Zmm(21) + 5]);
    vgatherqps(Ymm(3) | k3, ptr[rax + Zmm(21) + 6]);
    vgatherqps(Ymm(4) | k4, ptr[rax + Zmm(21) + 7]);
    vgatherqps(Ymm(5) | k5, ptr[rax + Zmm(21) + 8]);
    vgatherqps(Ymm(6) | k6, ptr[rax + Zmm(21) - 9]);
    vgatherqps(Ymm(7) | k7, ptr[rax + Zmm(21) - 10]);

    mov(rax, 5);
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
