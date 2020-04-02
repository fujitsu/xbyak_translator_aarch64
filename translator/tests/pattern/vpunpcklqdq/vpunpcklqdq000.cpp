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

    vpunpcklqdq(Xmm(10), Xmm(11), Xmm(12));
    vpunpcklqdq(Xmm(13), Xmm(13), Xmm(14));
    vpunpcklqdq(Xmm(15), Xmm(16), Xmm(15));
    vpunpcklqdq(Xmm(17), Xmm(18), Xmm(18));
    vpunpcklqdq(Xmm(19), Xmm(19), Xmm(19));

    vpunpcklqdq(Xmm(20), Xmm(21), Xmm(22));
    vpunpcklqdq(Xmm(23), Xmm(23), Xmm(24));
    vpunpcklqdq(Xmm(25), Xmm(26), Xmm(25));
    vpunpcklqdq(Xmm(27), Xmm(28), Xmm(28));
    vpunpcklqdq(Xmm(29), Xmm(29), Xmm(29));
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
