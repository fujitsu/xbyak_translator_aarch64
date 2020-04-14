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
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    uint32_t *matArray = (uint32_t *)std::malloc(8 * 8 * sizeof(uint32_t));
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    CodeGeneratorAArch64::trn1(Xbyak_aarch64::VReg4S(0),
                               Xbyak_aarch64::VReg4S(30),
                               Xbyak_aarch64::VReg4S(31));
    CodeGeneratorAArch64::trn2(Xbyak_aarch64::VReg4S(1),
                               Xbyak_aarch64::VReg4S(30),
                               Xbyak_aarch64::VReg4S(31));
    CodeGeneratorAArch64::zip1(Xbyak_aarch64::VReg4S(2),
                               Xbyak_aarch64::VReg4S(30),
                               Xbyak_aarch64::VReg4S(31));
    CodeGeneratorAArch64::zip2(Xbyak_aarch64::VReg4S(3),
                               Xbyak_aarch64::VReg4S(30),
                               Xbyak_aarch64::VReg4S(31));
    CodeGeneratorAArch64::uzp1(Xbyak_aarch64::VReg4S(4),
                               Xbyak_aarch64::VReg4S(30),
                               Xbyak_aarch64::VReg4S(31));
    CodeGeneratorAArch64::uzp2(Xbyak_aarch64::VReg4S(5),
                               Xbyak_aarch64::VReg4S(30),
                               Xbyak_aarch64::VReg4S(31));
    CodeGeneratorAArch64::xtn(Xbyak_aarch64::VReg2S(6),
                              Xbyak_aarch64::VReg2D(30));
    CodeGeneratorAArch64::xtn2(Xbyak_aarch64::VReg4S(7),
                               Xbyak_aarch64::VReg2D(30));
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
