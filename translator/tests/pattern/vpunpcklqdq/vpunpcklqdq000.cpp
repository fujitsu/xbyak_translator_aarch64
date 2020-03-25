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
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    vpunpcklqdq(Xmm(0), Xmm(1), Xmm(2));
    vpunpcklqdq(Xmm(3), Xmm(3), Xmm(4));
    vpunpcklqdq(Xmm(5), Xmm(6), Xmm(5));
    vpunpcklqdq(Xmm(7), Xmm(8), Xmm(8));
    vpunpcklqdq(Xmm(9), Xmm(9), Xmm(9));

    vpunpcklqdq(Ymm(10), Ymm(11), Ymm(12));
    vpunpcklqdq(Ymm(13), Ymm(13), Ymm(14));
    vpunpcklqdq(Ymm(15), Ymm(16), Ymm(15));
    vpunpcklqdq(Ymm(17), Ymm(18), Ymm(18));
    vpunpcklqdq(Ymm(19), Ymm(19), Ymm(19));

    vpunpcklqdq(Zmm(20), Zmm(21), Zmm(22));
    vpunpcklqdq(Zmm(23), Zmm(23), Zmm(24));
    vpunpcklqdq(Zmm(25), Zmm(26), Zmm(25));
    vpunpcklqdq(Zmm(27), Zmm(28), Zmm(28));
    vpunpcklqdq(Zmm(29), Zmm(29), Zmm(29));
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
