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
    // setInputZregAllRandomHex();

    for (int j = 0; j < 32; j++) {
      for (int i = 0; i < 8; i++) {
        inputZReg[j].ud_dt[i] = ~uint64_t(0);
      }
    }

    inputPredReg[1] = uint64_t(0xFFFF0000FFFF0000);
    inputPredReg[2] = uint64_t(0x0000FFFF0000FFFF);
    inputPredReg[3] = uint64_t(0x00AAAA0000AAAA00);
    inputPredReg[4] = uint64_t(0xAAAA0000AAAA0000);
    inputPredReg[5] = uint64_t(0xA0000AAAA0000AAA);
    inputPredReg[6] = uint64_t(0x5555555555555555);
    inputPredReg[7] = uint64_t(0x5050505050505050);
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */

    vandps(Xmm(2), Xmm(0) | k1, Xmm(1));
    vandps(Xmm(3), Xmm(0) | k2 | T_z, Xmm(1));
    vandps(Xmm(4), Xmm(0) | k3, Xmm(1));
    vandps(Xmm(5), Xmm(0) | k4 | T_z, Xmm(1));

    vandps(Ymm(6), Ymm(0) | k5, Xmm(1));
    vandps(Ymm(7), Ymm(0) | k6 | T_z, Xmm(1));
    vandps(Ymm(8), Ymm(0) | k7, Xmm(1));
    vandps(Ymm(9), Ymm(0) | k1 | T_z, Xmm(1));

    vandps(Zmm(10), Zmm(0) | k2, Xmm(1));
    vandps(Zmm(11), Zmm(0) | k3 | T_z, Xmm(1));
    vandps(Zmm(12), Zmm(0) | k4, Xmm(1));
    vandps(Zmm(13), Zmm(0) | k5 | T_z, Xmm(1));
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
