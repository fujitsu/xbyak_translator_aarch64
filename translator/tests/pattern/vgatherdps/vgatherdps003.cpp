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
#ifndef __ARM_ARCH /* x86_64 */
    inputPredReg[2] = (1 << 0) | (1 << 7);
    inputPredReg[3] = (1 << 0) | (1 << 7) | (1 << 11) | (uint64_t(1) << 15);
    inputPredReg[4] =
        (1 << 0) | (1 << 7) | (1 << 11) | (1 << 13) | (uint64_t(1) << 15);
    inputPredReg[5] = (1 << 0) | (1 << 9) | (1 << 11) | (1 << 13) | (1 << 14) |
                      (uint64_t(1) << 15);
    inputPredReg[6] = (1 << 0) | (1 << 9) | (1 << 10) | (1 << 11) | (1 << 13) |
                      (uint64_t(1) << 14) | (uint64_t(1) << 15);
    inputPredReg[7] = uint64_t(0xffff);
#else /* aarch64 */
    inputPredReg[2] = (1 << 0) | (uint64_t(1) << 28);
    inputPredReg[3] = (1 << 0) | (uint64_t(1) << 28) | (uint64_t(1) << 44) |
                      (uint64_t(1) << 60);
    inputPredReg[4] = (1 << 0) | (uint64_t(1) << 28) | (uint64_t(1) << 44) |
                      (uint64_t(1) << 52) | (uint64_t(1) << 60);
    inputPredReg[5] = (1 << 0) | (uint64_t(1) << 36) | (uint64_t(1) << 44) |
                      (uint64_t(1) << 52) | (uint64_t(1) << 56) |
                      (uint64_t(1) << 60);
    inputPredReg[6] = (1 << 0) | (uint64_t(1) << 36) | (uint64_t(1) << 40) |
                      (uint64_t(1) << 44) | (uint64_t(1) << 52) |
                      (uint64_t(1) << 56) | (uint64_t(1) << 60);
    inputPredReg[7] =
        (1 << 0) | (1 << 4) | (1 << 8) | (1 << 12) | (1 << 16) | (1 << 20) |
        (1 << 24) | (1 << 28) | (uint64_t(1) << 32) | (uint64_t(1) << 36) |
        (uint64_t(1) << 40) | (uint64_t(1) << 44) | (uint64_t(1) << 48) |
        (uint64_t(1) << 52) | (uint64_t(1) << 56) | (uint64_t(1) << 60);
#endif

    for (int i = 0; i < 8; i++) {
      inputZReg[21].us_dt[i] = i * 4;
      inputZReg[22].us_dt[i] = i * 4;
    }

    for (int i = 8; i < 10; i++) {
      inputZReg[21].us_dt[i] = 16;
      inputZReg[22].us_dt[i] = 16;
    }

    for (int i = 10; i < 12; i++) {
      inputZReg[21].us_dt[i] = -32;
      inputZReg[22].us_dt[i] = -32;
    }

    for (int i = 12; i < 16; i++) {
      inputZReg[21].us_dt[i] = -64;
      inputZReg[22].us_dt[i] = -64;
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;

    /* Address is aligned */
    addr = reinterpret_cast<size_t>(&(inputZReg[16].us_dt[0]));

    mov(rax, addr);

    /* Dest register index must be different from Index register index. */
    vgatherdps(Xmm(1) | k1, ptr[rax + Xmm(21) * 2 + 0x10]);
    vgatherdps(Xmm(2) | k2, ptr[rax + Xmm(21) * 2 - 0x10]);
    vgatherdps(Xmm(3) | k3, ptr[rax + Xmm(21) * 2]);
    vgatherdps(Xmm(4) | k4, ptr[rax + Xmm(21) * 2]);
    vgatherdps(Xmm(5) | k5, ptr[rax + Xmm(21) * 4]);
    vgatherdps(Xmm(6) | k6, ptr[rax + Xmm(22) * 4]);
    vgatherdps(Xmm(7) | k7, ptr[rax + Xmm(22) * 2]);
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
    f(); /* Execute JIT code */

#ifndef __ARM_ARCH
    // Adjust Pred reg values to x64's mask reg
    gen.modifyPredReg(US_DT);
#endif

    gen.dumpOutputReg(); /* Dump all register values */
    gen.dumpCheckReg();  /* Dump register values to be checked */
  }

  return 0;
}
