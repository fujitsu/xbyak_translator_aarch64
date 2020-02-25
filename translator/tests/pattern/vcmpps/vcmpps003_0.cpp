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
    setInputZregAllRandomFloat();
    setDumpZRegMode(SP_DT);

    inputZReg[0].us_dt[0] = 0;
    inputZReg[1].us_dt[0] = 0;

    inputZReg[2].us_dt[0] = inputZReg[3].us_dt[0] = float(1.1);
    inputZReg[2].us_dt[7] = inputZReg[3].us_dt[7] = float(2.2);

    inputZReg[4].us_dt[0] = inputZReg[5].us_dt[0] = float(3.3);
    inputZReg[4].us_dt[7] = inputZReg[5].us_dt[7] = float(4.4);
    inputZReg[4].us_dt[15] =  inputZReg[5].us_dt[15] = float(5.5);

    inputZReg[6].us_dt[13] = inputZReg[7].us_dt[13] = float(6.6);
    inputZReg[6].us_dt[15] = inputZReg[7].us_dt[15] = float(7.7);

    inputPredReg[6] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) |
      (1 << 6) | (1 << 7) | (1<<8) | (1<<12) |(1<<15) |/* x86_64 */
                      (1 << 0) | (1 << 4) | (1 << 8) | (1 << 12) | (1 << 16) |
      (1 << 24) | (1 << 28) |(uint64_t(1)<<32)|(uint64_t(1)<<48)|(uint64_t(1)<<60); /* aarch64 */

    inputPredReg[1] = uint64_t(0x2);
    inputPredReg[2] = uint64_t(0x6);
    inputPredReg[3] = (1<<3) | (1<<15) | /* x86_64 */
      (1<<12) | (uint64_t(1<<64)); /* aarch64 */

    inputPredReg[5] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) |
      (1 << 6) | (1 << 7) | (1<<8) | (1<<12) |(1<<15) |/* x86_64 */
                      (1 << 0) | (1 << 4) | (1 << 8) | (1 << 12) | (1 << 16) |
      (1 << 24) | (1 << 28) |(uint64_t(1)<<32)|(uint64_t(1)<<48)|(uint64_t(1)<<60); /* aarch64 */
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    vcmpps(k1|k6, Zmm(0), Zmm(1), 0); // EQ_OQ
    vcmpps(k2|k6, Zmm(2), Zmm(3), 0); // EQ_OQ
    vcmpps(k3|k6, Zmm(4), Zmm(5), 0); // EQ_OQ
    vcmpps(k7|k6, Zmm(31), Zmm(31), 0); // EQ_OQ
    
    vcmpps(k6|k6, Zmm(6), Zmm(7), 0); // EQ_OQ
    vcmpps(k5|k5, Zmm(8), Zmm(8), 0); // EQ_OQ
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


#ifdef XBYAK_TRANSLATE_AARCH64
    gen.modifyPredRegAArch64(SP_DT);
#else //#ifdef XBYAK_TRANSLATE_AARCH64
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
