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

    for (int j = 0; j < 32; j++) {
      for (int i = 0; i < 16; i++) {
        inputZReg[j].us_dt[i] = (j << 16) + i;
      }
    }

    for (int i = 0; i < 16; i++) {
      inputZReg[31].us_dt[i] = 0x11111111 * i;
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  Xbyak_aarch64::VReg4S generateTransposeJitCode(uint32_t *matrixAddr) {
    size_t addr;
    addr = reinterpret_cast<size_t>(matrixAddr);
    CodeGeneratorAArch64::mov_imm(x0, addr, x1);

    for (int row = 0; row < 8; row++) {
      CodeGeneratorAArch64::ld1(Xbyak_aarch64::VReg4S(row),
                                Xbyak_aarch64::ptr(x0));
    }

    for (int row = 0; row < 4; row++) {
      for (int col = 0; col < 4; col++) {
        CodeGeneratorAArch64::mov(Xbyak_aarch64::VReg4S(col + 8)[row],
                                  Xbyak_aarch64::VReg4S(row)[col]);
      }
    }

    return Xbyak_aarch64::VReg4S(0);
  }

  void genJitTestCode() {
    uint32_t *matArray = (uint32_t *)std::malloc(8 * 8 * sizeof(uint32_t));
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    generateTransposeJitCode(matArray);
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
