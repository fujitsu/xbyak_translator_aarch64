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
    vpblendmb(Xmm(0), Xmm(30), Xmm(31));
    vpblendmb(Ymm(1), Ymm(30), Ymm(31));
    vpblendmb(Zmm(2), Zmm(30), Zmm(31));

    vpblendmb(Xmm(3), Xmm(3), Xmm(31));  /* dstIdx = srcIdx */
    vpblendmb(Ymm(4), Ymm(4), Ymm(31));  /* dstIdx = srcIdx */
    vpblendmb(Zmm(5), Zmm(5), Zmm(31));  /* dstIdx = srcIdx */

    vpblendmb(Xmm(6), Xmm(30), Xmm(6));  /* dstIdx = src2Idx */
    vpblendmb(Ymm(7), Ymm(30), Ymm(7));  /* dstIdx = src2Idx */
    vpblendmb(Zmm(8), Zmm(30), Zmm(8));  /* dstIdx = src2Idx */

    vpblendmb(Xmm(9), Xmm(9), Xmm(9));  /* dstIdx = srcIdx = src2Idx */
    vpblendmb(Ymm(10), Ymm(10), Ymm(10));  /* dstIdx = srcIdx = src2Idx */
    vpblendmb(Zmm(11), Zmm(11), Zmm(11));  /* dstIdx = srcIdx = src2Idx */
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
