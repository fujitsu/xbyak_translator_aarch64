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
    inputPredReg[2] = (1 << 0) | (1 << 5) | (uint64_t(1) << 7) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 20) |
                      (uint64_t(1) << 28); /* aarch64 */
    inputPredReg[3] = (1 << 0) | (1 << 5) | (1 << 6) |
                      (uint64_t(1) << 7) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 20) | (uint64_t(1) << 24) |
                      (uint64_t(1) << 28); /* aarch64 */
    inputPredReg[4] = (1 << 0) | (1 << 5) | (1 << 6) | (1 << 7) |
                      (uint64_t(1) << 9) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 20) | (uint64_t(1) << 24) |
                      (uint64_t(1) << 28) | (uint64_t(1) << 36); /* aarch64 */
    inputPredReg[5] = (1 << 0) | (1 << 5) | (1 << 6) | (1 << 7) | (1 << 9) |
                      (uint64_t(1) << 11) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 20) | (uint64_t(1) << 24) |
                      (uint64_t(1) << 28) | (uint64_t(1) << 36) |
                      (uint64_t(1) << 44); /* aarch64 */
    inputPredReg[6] = (1 << 0) | (1 << 5) | (1 << 6) | (1 << 7) | (1 << 9) |
                      (uint64_t(1) << 11) | (uint64_t(1) << 13) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 20) | (uint64_t(1) << 24) |
                      (uint64_t(1) << 28) | (uint64_t(1) << 36) |
                      (uint64_t(1) << 44) | (uint64_t(1) << 52); /* aarch64 */
    inputPredReg[7] = ~uint64_t(0);
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

    int sel;

    sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
    vpshufd(Xmm(1) | k1 | T_z, ptr[rax], sel);
    sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
    vpshufd(Xmm(2) | k2 | T_z, ptr[rax], sel);
    sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
    vpshufd(Xmm(3) | k3 | T_z, ptr[rax], sel);
    sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
    vpshufd(Xmm(4) | k4 | T_z, ptr[rax], sel);
    sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
    vpshufd(Xmm(5) | k5 | T_z, ptr[rax], sel);
    sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
    vpshufd(Xmm(6) | k6 | T_z, ptr[rax], sel);
    sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
    vpshufd(Xmm(7) | k7 | T_z, ptr[rax], sel);

    sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
    vpshufd(Xmm(22) | k1 | T_z, ptr[rax], sel);
    sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
    vpshufd(Xmm(23) | k2 | T_z, ptr[rax], sel);
    sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
    vpshufd(Xmm(24) | k3 | T_z, ptr[rax], sel);
    sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
    vpshufd(Xmm(25) | k4 | T_z, ptr[rax], sel);
    sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
    vpshufd(Xmm(26) | k5 | T_z, ptr[rax], sel);
    sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
    vpshufd(Xmm(27) | k6 | T_z, ptr[rax], sel);
    sel = 0 + (int)(rand() * (255 - 0 + 1.0) / (1.0 + RAND_MAX));
    vpshufd(Xmm(28) | k7 | T_z, ptr[rax], sel);

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
