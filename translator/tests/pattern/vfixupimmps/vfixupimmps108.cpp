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
    setDumpZRegMode(SP_DT);

#define MOVE_SEED 800
    for (int i = 0; i < MOVE_SEED; i++) {
      getLfsr();
    }
#undef MOVE_SEED

    for (int j = 0; j < 32; j++) {
      for (int i = 0; i < 16; i++) {
        uint32_t exp, frac;
        uint32_t sign = (getLfsr() % 2) ? (uint64_t(1) << 63) : 0;

        switch (getLfsr() % 3) {
        case 0:
          exp = 0;
          break;
        case 1:
          exp = uint32_t((getLfsr() % 254) + 1) << 23;
          break;
        default:
          exp = uint32_t(255) << 23;
          break;
        }

        switch (getLfsr() % 2) {
        case 0:
          frac = 0;
          break;
        default:
          frac = (uint32_t(getLfsr() & 0x7) << 20) |
                 (uint32_t(getLfsr()) << 16) | (uint32_t(getLfsr()) << 12) |
                 (uint32_t(getLfsr()) << 8) | (uint32_t(getLfsr()) << 4) |
                 (uint32_t(getLfsr()) << 0);
        }

        inputZReg[j].us_dt[i] = sign | exp | frac;
      }
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    uint16_t flag = 0;

    while (flag != uint16_t(0xffff)) {
      uint16_t tmp0, tmp1, tmp2;

      /* Each register is used as destination only once. */
      do {
        tmp0 = getLfsr() % 16;
      } while (flag & uint16_t(1 << tmp0));

      tmp1 = getLfsr() % 16;
      tmp2 = getLfsr() % 16;

      vfixupimmps(Zmm(tmp0), Zmm(tmp1), Zmm(tmp2), 0);

      flag |= uint16_t(1 << tmp0);
    }
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
