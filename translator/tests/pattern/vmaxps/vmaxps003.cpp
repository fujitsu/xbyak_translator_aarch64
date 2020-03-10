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
    setDumpZRegMode(SP_DT);
    setInputZregAllRandomFloat();

    inputPredReg[1] = uint64_t(0x0);
    inputPredReg[2] = ~uint64_t(0x0);
    inputPredReg[3] = uint64_t(0x1);
    inputPredReg[4] = (0x1 << 0) | (0x1 << 1) | (0x1 << 4) | /* x86_64 */
                      (0x1 << 0) | (0x1 << 4) | (0x1 << 16); /* aarch64 */

    inputPredReg[5] =
        (0x1 << 0) | (0x1 << 1) | (0x1 << 4) | (0x1 << 7) |  /* x86_64 */
        (0x1 << 0) | (0x1 << 4) | (0x1 << 16) | (0x1 << 28); /* aarch64 */

    inputPredReg[6] = (0x1 << 0) | (0x1 << 1) | (0x1 << 4) | (0x1 << 7) |
                      (0x1 << 10) | /* x86_64 */
                      (0x1 << 0) | (0x1 << 4) | (0x1 << 16) |
                      (0x1 << 28);              /* aarch64 */
    inputPredReg[6] |= uint64_t(0x10000000000); /* aarch64 (0x1 << 40) */

    inputPredReg[7] = (0x1 << 0) | (0x1 << 1) | (0x1 << 4) | (0x1 << 7) |
                      (0x1 << 10) | (0x1 << 13) | /* x86_64 */
                      (0x1 << 0) | (0x1 << 4) | (0x1 << 16) |
                      (0x1 << 28); /* aarch64 */
    inputPredReg[7] |=
        uint64_t(0x10010000000000); /* aarch64 (0x1 << 40) | (0x1 << 52) */
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12, r13, r14,
     * r15 */
    size_t addr1;
    addr1 = reinterpret_cast<size_t>(&(inputZReg[16].sp_dt[0]));
    mov(rax, addr1);

    vmaxps(Zmm(0), Zmm(1) | k1, ptr[rax]);
    vmaxps(Zmm(2), Zmm(3) | k2, ptr[rax]);
    vmaxps(Zmm(4), Zmm(5) | k3, ptr[rax]);
    vmaxps(Zmm(6), Zmm(7) | k4, ptr[rax]);
    vmaxps(Zmm(8), Zmm(9) | k5, ptr[rax]);
    vmaxps(Zmm(10), Zmm(11) | k6, ptr[rax]);
    vmaxps(Zmm(12), Zmm(12) | k7, ptr[rax]);
    vmaxps(Zmm(14), Zmm(14) | k7, ptr[rax]); /* dstIdx = srcIdx */
    vmaxps(Zmm(15), Zmm(16) | k7, ptr[rax]); /* src = *i(addr1) */

    vmaxps(Zmm(21), Zmm(21) | k1, ptr[rax]);
    vmaxps(Zmm(22), Zmm(22) | k2, ptr[rax]);
    vmaxps(Zmm(23), Zmm(23) | k3, ptr[rax]);
    vmaxps(Zmm(24), Zmm(24) | k4, ptr[rax]);
    vmaxps(Zmm(25), Zmm(25) | k5, ptr[rax]);
    vmaxps(Zmm(26), Zmm(26) | k6, ptr[rax]);
    vmaxps(Zmm(27), Zmm(27) | k7, ptr[rax]);

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
