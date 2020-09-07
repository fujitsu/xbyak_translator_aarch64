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
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    vxorps(Xmm(2), Xmm(0), Xmm(1));
    vxorps(Ymm(5), Ymm(3), Ymm(4));
    vxorps(Zmm(1), Zmm(3), Zmm(4));

    vxorps(Xmm(6), Xmm(7), Xmm(7));
    vxorps(Xmm(8), Xmm(9), Xmm(8));
    vxorps(Xmm(10), Xmm(10), Xmm(11));
    vxorps(Xmm(12), Xmm(12), Xmm(1));

    vxorps(Ymm(13), Ymm(14), Ymm(14));
    vxorps(Ymm(15), Ymm(16), Ymm(15));
    vxorps(Ymm(17), Ymm(17), Ymm(18));
    vxorps(Ymm(19), Ymm(19), Ymm(20));

    vxorps(Zmm(21), Zmm(22), Zmm(22));
    vxorps(Zmm(23), Zmm(24), Zmm(23));
    vxorps(Zmm(25), Zmm(25), Zmm(26));
    vxorps(Zmm(27), Zmm(27), Zmm(28));

    vxorps(Xmm(29), Xmm(29), Xmm(29));
    vxorps(Ymm(30), Ymm(30), Ymm(30));
    vxorps(Zmm(31), Zmm(31), Zmm(31));
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
