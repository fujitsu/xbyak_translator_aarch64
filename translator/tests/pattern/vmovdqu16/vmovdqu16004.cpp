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
    //    setDumpZRegMode(SP_DT); // set float mode
    setInputZregAllRandomHex();

#if 0
    for(int j=0; j<32; j+=2) {
      for(int i=0; i<32; i++) {
	inputZReg[j].uh_dt[i] = 0xffff;
      }
    }
#endif

    /* elemet is 8 bits.
       Xmm:16 elements
       Ymm:32 elements
       Zmm:64 elements */

    // Xmm range
    inputPredReg[1] = (1 << 0) | (1 << 17)              /* x86_64 */
                      | (1 << 0) | (uint64_t(1) << 34); /* aarch64 */

    inputPredReg[2] = (1 << 0) | (1 << 17) | (1 << 19) | (1 << 25) /* x86_64 */
                      | (1 << 0) | (uint64_t(1) << 34) | (uint64_t(1) << 38) |
                      (uint64_t(1) << 50); /* aarch64 */

    // Ymm range
    inputPredReg[3] = (1 << 0) | (1 << 17) | (1 << 23) /* x86_64 */
                      | (1 << 0) | (uint64_t(1) << 34) |
                      (uint64_t(1) << 46); /* aarch64 */
    inputPredReg[4] = (1 << 0) | (1 << 17) | (1 << 23) |
                      (uint64_t(1) << 31) /* x86_64 */
                      | (1 << 0) | (uint64_t(1) << 34) | (uint64_t(1) << 46) |
                      (uint64_t(1) << 62); /* aarch64 */

    // Zmm range
    inputPredReg[5] = (1 << 0) | (1 << 17) | (1 << 23) |
                      (uint64_t(1) << 31) /* x86_64 */
                      | (1 << 0) | (uint64_t(1) << 34) | (uint64_t(1) << 46) |
                      (uint64_t(1) << 62); /* aarch64 */
    inputPredReg[6] = (1 << 0) | (1 << 17) | (1 << 23) | (uint64_t(1) << 29) |
                      (uint64_t(1) << 31) /* x86_64 */
                      | (1 << 0) | (uint64_t(1) << 34) | (uint64_t(1) << 46) |
                      (uint64_t(1) << 58) | (uint64_t(1) << 62); /* aarch64 */

    inputPredReg[7] = ~uint64_t(0);
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;

    /* Address is aligned */
    addr = reinterpret_cast<size_t>(&(inputZReg[31].sp_dt[0]));
    mov(rax, addr);

    vmovdqu16(ptr[rax] | k1, Xmm(0));
    vmovdqu16(Zmm(1), ptr[rax]);

    vmovdqu16(ptr[rax] | k2, Xmm(2));
    vmovdqu16(Zmm(3), ptr[rax]);

    vmovdqu16(ptr[rax] | k3, Xmm(4));
    vmovdqu16(Zmm(5), ptr[rax]);

    vmovdqu16(ptr[rax] | k4, Xmm(6));
    vmovdqu16(Zmm(7), ptr[rax]);

    vmovdqu16(ptr[rax] | k5, Xmm(8));
    vmovdqu16(Zmm(9), ptr[rax]);

    vmovdqu16(ptr[rax] | k6, Xmm(10));
    vmovdqu16(Zmm(11), ptr[rax]);

    vmovdqu16(ptr[rax] | k7, Xmm(12));
    vmovdqu16(Zmm(13), ptr[rax]);

    /* Address is unaligned */
    addr = reinterpret_cast<size_t>(&(inputZReg[30].sp_dt[0]) + 3);
    mov(rax, addr);

    vmovdqu16(ptr[rax] | k1, Xmm(14));
    vmovdqu16(Zmm(15), ptr[rax]);

    vmovdqu16(ptr[rax] | k2, Xmm(16));
    vmovdqu16(Zmm(17), ptr[rax]);

    vmovdqu16(ptr[rax] | k3, Xmm(18));
    vmovdqu16(Zmm(19), ptr[rax]);

    vmovdqu16(ptr[rax] | k4, Xmm(20));
    vmovdqu16(Zmm(21), ptr[rax]);

    vmovdqu16(ptr[rax] | k5, Xmm(22));
    vmovdqu16(Zmm(23), ptr[rax]);

    vmovdqu16(ptr[rax] | k6, Xmm(24));
    vmovdqu16(Zmm(25), ptr[rax]);

    vmovdqu16(ptr[rax] | k7, Xmm(26));
    vmovdqu16(Zmm(27), ptr[rax]);

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
