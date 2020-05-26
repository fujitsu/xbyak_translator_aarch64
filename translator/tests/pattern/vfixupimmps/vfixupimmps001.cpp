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
    setInputZregAllRandomHex();
    for (int i = 0; i < 16; i++) {
      inputZReg[15].us_dt[i] = (i << 28) | (i << 24) | (i << 20) | (i << 16) |
                               (i << 12) | (i << 8) | (i << 4) | (i << 0);
    }

    for (int i = 0; i < 16; i++) {
      inputZReg[0].us_dt[i] = uint32_t(0x7f800001); // SNaN
      inputZReg[1].us_dt[i] = uint32_t(0x7fc00001); // QNaN
      inputZReg[2].sp_dt[i] = float(0.0);           // zero
      inputZReg[3].sp_dt[i] = float(1.0);           // pos_one
      inputZReg[4].us_dt[i] = uint32_t(0x7f800000); // neg_inf
      inputZReg[5].us_dt[i] = uint32_t(0xff800000); // pos_inf
      inputZReg[6].sp_dt[i] = float(-123.45);       // neg_value
      inputZReg[7].sp_dt[i] = float(123.45);        // pos_value
      inputZReg[8].us_dt[i] = uint32_t(0x00000001);
      inputZReg[9].us_dt[i] = uint32_t(0x80000001);
      inputZReg[10].us_dt[i] = uint32_t(0x7f800000);
      inputZReg[11].us_dt[i] = uint32_t(0xff800000);
      inputZReg[12].us_dt[i] = uint32_t(0xff800001); // SNaN
      inputZReg[13].us_dt[i] = uint32_t(0xffc00001); // QNaN
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    vfixupimmps(Zmm(16), Zmm(0), Zmm(15), 0);
    vfixupimmps(Zmm(17), Zmm(1), Zmm(15), 0);
    vfixupimmps(Zmm(18), Zmm(2), Zmm(15), 0);
    vfixupimmps(Zmm(19), Zmm(3), Zmm(15), 0);
    vfixupimmps(Zmm(20), Zmm(4), Zmm(15), 0);
    vfixupimmps(Zmm(21), Zmm(5), Zmm(15), 0);
    vfixupimmps(Zmm(22), Zmm(6), Zmm(15), 0);
    vfixupimmps(Zmm(23), Zmm(7), Zmm(15), 0);
    vfixupimmps(Zmm(24), Zmm(8), Zmm(15), 0);
    vfixupimmps(Zmm(25), Zmm(9), Zmm(15), 0);
    vfixupimmps(Zmm(26), Zmm(10), Zmm(15), 0);
    vfixupimmps(Zmm(27), Zmm(11), Zmm(15), 0);
    vfixupimmps(Zmm(28), Zmm(12), Zmm(15), 0);
    vfixupimmps(Zmm(29), Zmm(13), Zmm(15), 0);
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
