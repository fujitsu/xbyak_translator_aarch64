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
    
    inputGenReg[8] = 0xabcdef012;
    inputGenReg[9] = 0x123456789a;
    inputGenReg[10] = 0x56789abcdef;

    inputPredReg[1] = uint64_t(0); /* Both x86_64 and aarch64 */
#ifndef __ARM_ARCH
    inputPredReg[2] = (1 << 0) | (1 << 4) | (1 << 8) | (1 << 12)
                     | (1 << 16) | (1 << 20) | (1 << 24) | (1 << 28);
    inputPredReg[3] = (1 << 2) | (1 << 6) | (1 << 10) | (1 << 14)
                     | (1 << 18) | (1 << 22) | (1 << 26) | (1 << 30);
    inputPredReg[4] = (1 << 3) | (1 << 7) | (1 << 11) | (1 << 15)
                     | (1 << 19) | (1 << 23) | (1 << 27) | (1 << 31);
#else
    inputPredReg[2] = (1 << 0) | (1 << 8) | (1 << 16) | (1 << 24)
                     | (uint64_t(1) << 32) | (uint64_t(1) << 40) | (uint64_t(1) << 48) | (uint64_t(1) << 56);
    inputPredReg[3] = (1 << 4) | (1 << 12) | (1 << 20) | (1 << 28)
                     | (uint64_t(1) << 36) | (uint64_t(1) << 44) | (uint64_t(1) << 52) | (uint64_t(1) << 60);
    inputPredReg[4] = (1 << 6) | (1 << 14) | (1 << 22) | (1 << 30) 
                     | (uint64_t(1) << 38) | (uint64_t(1) << 46) | (uint64_t(1) << 54) | (uint64_t(1) << 62);
#endif
    inputPredReg[7] = ~uint64_t(0); /* Both x86_64 and aarch64 */
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    size_t addr;
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    addr = reinterpret_cast<size_t>(&(inputZReg[0].sp_dt[7]));
    mov(rax, addr);

    vpbroadcastw(Xmm(0) | k1, ptr[rax]);
    vpbroadcastw(Ymm(1) | k1, ptr[rax]);
    vpbroadcastw(Zmm(2) | k1, ptr[rax]);
    vpbroadcastw(Xmm(3) | k2, ptr[rax]);
    vpbroadcastw(Ymm(4) | k3, ptr[rax]);
    vpbroadcastw(Zmm(5) | k4, ptr[rax]);
    vpbroadcastw(Xmm(6) | k3, ptr[rax]);
    vpbroadcastw(Ymm(7) | k4, ptr[rax]);
    vpbroadcastw(Zmm(8) | k2, ptr[rax]);
    vpbroadcastw(Xmm(9) | k4, ptr[rax]);
    vpbroadcastw(Ymm(10) | k2, ptr[rax]);
    vpbroadcastw(Zmm(11) | k3, ptr[rax]);
    vpbroadcastw(Xmm(12) | k7, ptr[rax]);
    vpbroadcastw(Ymm(13) | k7, ptr[rax]);
    vpbroadcastw(Zmm(14) | k7, ptr[rax]);

    mov(rax, 0x1);
#ifndef __ARM_ARCH
    kmovq(k2, rax);
    kmovq(k3, rax);
    kmovq(k4, rax);
#else
    ptrue(p2.b, Xbyak_aarch64::VL1);
    ptrue(p3.b, Xbyak_aarch64::VL1);
    ptrue(p4.b, Xbyak_aarch64::VL1);
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
