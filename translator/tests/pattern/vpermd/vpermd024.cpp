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

    for (int i = 0; i < 32; i++) {
      inputZReg[6].uh_dt[i] = 0xffff;
    }

    /* z31 - z29 are used as zTmpIdx - zTmp3Idx */
    inputPredReg[1] = (1 << 0);
    inputPredReg[2] = (1 << 0) | (1 << 6) | (uint64_t(1) << 15) | /* x86_64 */
                      (1 << 0) | (uint64_t(1) << 24) |
                      (uint64_t(1) << 60); /* aarch64 */
    inputPredReg[3] = inputPredReg[4] = inputPredReg[5] = inputPredReg[6] =
        inputPredReg[2];
    inputPredReg[7] = ~uint64_t(0);
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;
    addr = reinterpret_cast<size_t>(&(inputZReg[15].ud_dt[0]));
    std::cout << "Address is " << std::hex << addr << std::endl;
    mov(rcx, addr);

    /* z31 - z29 are used as zTmpIdx - zTmp3Idx */
    vpermd(Ymm(1) | k1 | T_z, Ymm(30), ptr[rcx]);
    vpermd(Ymm(2) | k2 | T_z, Ymm(30), ptr[rcx]);
    vpermd(Ymm(3) | k3 | T_z, Ymm(3), ptr[rcx]);
    vpermd(Ymm(4) | k4 | T_z, Ymm(30), ptr[rcx]);
    vpermd(Ymm(5) | k5 | T_z, Ymm(5), ptr[rcx]);
    vpermd(Ymm(6) | k6 | T_z, Ymm(30), ptr[rcx]);
    vpermd(Ymm(7) | k7 | T_z, Ymm(30), ptr[rcx]);

    mov(rcx, 0x5);
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
