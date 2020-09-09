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
    inputPredReg[4] = (1 << 0) | (1 << 7) | (1 << 11) | (1 << 13) | (uint64_t(1) << 15);
    inputPredReg[5] = (1 << 0) | (1 << 9) | (1 << 11) | (1 << 13) | (1 << 14) | (uint64_t(1) << 15);
    inputPredReg[6] = (1 << 0) | (1 << 9) | (1 << 10) | (1 << 11) | (1 << 13) |
      (uint64_t(1) << 14) | (uint64_t(1) << 15);

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
#endif
    
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */

    vpslld(Zmm(0) | k1 | T_z, Zmm(1), 1);
    vpslld(Zmm(2) | k2 | T_z, Zmm(3), 19);
    vpslld(Zmm(4) | k3 | T_z, Zmm(5), 31);
    vpslld(Zmm(6) | k4 | T_z, Zmm(6), 13);
    vpslld(Zmm(7) | k5 | T_z, Zmm(7), 24);
    vpslld(Zmm(8) | k6 | T_z, Zmm(8), 8);

    vpslld(Zmm(20) | k1 | T_z, Zmm(20), 1);
    vpslld(Zmm(21) | k2 | T_z, Zmm(21), 19);
    vpslld(Zmm(22) | k3 | T_z, Zmm(22), 31);
    vpslld(Zmm(23) | k4 | T_z, Zmm(24), 13);
    vpslld(Zmm(25) | k5 | T_z, Zmm(26), 24);
    vpslld(Zmm(27) | k6 | T_z, Zmm(28), 8);

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

#ifndef XBYAK_TRANSLATE_AARCH64
    /* Bit order of mask registers are different from x86_64 and aarch64.
       In order to compare output values of mask registers by test script,
       Bit order of x86_64 mask register values is modified here. */
    gen.modifyPredReg(SP_DT);
#endif
    
    gen.dumpOutputReg(); /* Dump all register values */
    gen.dumpCheckReg();  /* Dump register values to be checked */
  }

  return 0;
}
