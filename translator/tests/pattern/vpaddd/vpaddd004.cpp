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
    //    inputPredReg[1] = (1 << 0) | (1 << 7); /* Both x86_64 and aarch64 */
    //    inputPredReg[2] = (1 << 1) | (1 << 10); /* Both x86_64 and aarch64 */
    //    inputPredReg[3] = (1 << 2) | (1 << 7); /* Both x86_64 and aarch64 */
    //    inputPredReg[4] = (1 << 3) | (1 << 15); /* Both x86_64 and aarch64 */
    //    inputPredReg[5] = (1 << 0) | (1 << 3); /* Both x86_64 and aarch64 */
    //    inputPredReg[6] = (1 << 1) | (1 << 7); /* Both x86_64 and aarch64 */
    inputPredReg[1] = uint64_t(0); /* Both x86_64 and aarch64 */
#ifndef __ARM_ARCH
    inputPredReg[2] = (1 << 0) | (1 << 2) | (1 << 4);
    inputPredReg[3] = (1 << 1) | (1 << 3) | (1 << 5);
    inputPredReg[4] = (1 << 0) | (1 << 7) | (1 << 10) | (1 << 15);
#else
    inputPredReg[2] = (1 << 0) | (1 << 8) | (1 << 16);
    inputPredReg[3] = (1 << 4) | (1 << 12) | (1 << 20);
    inputPredReg[4] =
        (1 << 0) | (1 << 28) | (uint64_t(1) << 40) | (uint64_t(1) << 60);
#endif
    inputPredReg[7] = ~uint64_t(0); /* Both x86_64 and aarch64 */

#if 0
    /*
    for (int i = 0; i < 8; i++) {
      inputZReg[0].ud_dt[i] = ~uint64_t(0);
      inputZReg[3].ud_dt[i] = ~uint64_t(0);
      inputZReg[6].ud_dt[i] = ~uint64_t(0);
    }
    for (int i = 0; i < 8; i++) {
      inputZReg[1].ud_dt[i] = uint32_t(0xFF00FF00AA55AA55);
      inputZReg[4].ud_dt[i] = uint32_t(0xFF00FF00AA55AA55);
      inputZReg[7].ud_dt[i] = uint32_t(0xFF00FF00AA55AA55);
    }
    */
#endif
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;

    /* Address is aligned */
    addr = reinterpret_cast<size_t>(&(inputZReg[0].ud_dt[7]));
    std::cout << "Address is " << std::hex << addr << std::endl;
    mov(rax, addr);

    //    vpaddd(Ymm(0) | k1 | T_z, Ymm(1), ptr[rax]);
    //    vpaddd(Ymm(2) | k2 | T_z, Ymm(2), ptr[rax]);
    //
    //    vpaddd(Zmm(3) | k3 | T_z, Zmm(4), ptr[rax]);
    //    vpaddd(Zmm(5) | k4 | T_z, Zmm(5), ptr[rax]);
    //
    //    vpaddd(Xmm(6) | k5 | T_z, Xmm(7), ptr[rax]);
    //    vpaddd(Xmm(8) | k6 | T_z, Xmm(8), ptr[rax]);
    //
    //    mov(rax, 5);

    /* VEX */
    vpaddd(Xmm(2) | k1 | T_z, Xmm(0), ptr[rax]);
    vpaddd(Xmm(3) | k2 | T_z, Xmm(0), ptr[rax]);
    vpaddd(Xmm(4) | k3 | T_z, Xmm(0), ptr[rax]);
    vpaddd(Xmm(5) | k4 | T_z, Xmm(0), ptr[rax]);
    vpaddd(Xmm(6) | k7 | T_z, Xmm(0), ptr[rax]);

    vpaddd(Ymm(7) | k1 | T_z, Ymm(0), ptr[rax]);
    vpaddd(Ymm(8) | k2 | T_z, Ymm(0), ptr[rax]);
    vpaddd(Ymm(9) | k3 | T_z, Ymm(0), ptr[rax]);
    vpaddd(Ymm(10) | k4 | T_z, Ymm(0), ptr[rax]);
    vpaddd(Ymm(11) | k7 | T_z, Ymm(0), ptr[rax]);

    /* EVEX */
    vpaddd(Xmm(16) | k1 | T_z, Xmm(30), ptr[rax]);
    vpaddd(Xmm(17) | k2 | T_z, Xmm(30), ptr[rax]);
    vpaddd(Xmm(18) | k3 | T_z, Xmm(30), ptr[rax]);
    vpaddd(Xmm(19) | k4 | T_z, Xmm(30), ptr[rax]);
    vpaddd(Xmm(20) | k7 | T_z, Xmm(30), ptr[rax]);

    vpaddd(Ymm(21) | k1 | T_z, Ymm(30), ptr[rax]);
    vpaddd(Ymm(22) | k2 | T_z, Ymm(30), ptr[rax]);
    vpaddd(Ymm(23) | k3 | T_z, Ymm(30), ptr[rax]);
    vpaddd(Ymm(24) | k4 | T_z, Ymm(30), ptr[rax]);
    vpaddd(Ymm(25) | k7 | T_z, Ymm(30), ptr[rax]);

    vpaddd(Zmm(26) | k1 | T_z, Zmm(30), ptr[rax]);
    vpaddd(Zmm(27) | k2 | T_z, Zmm(30), ptr[rax]);
    vpaddd(Zmm(28) | k3 | T_z, Zmm(30), ptr[rax]);
    vpaddd(Zmm(29) | k4 | T_z, Zmm(30), ptr[rax]);
    vpaddd(Zmm(30) | k7 | T_z, Zmm(30), ptr[rax]);

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
