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

    /* z31 - z29 are used as zTmpIdx - zTmp3Idx */

    for (int i = 0; i < 32; i++) {
      inputZReg[15].uh_dt[i] = i;
    }

    for (int i = 0; i < 32; i++) {
      inputZReg[8].uh_dt[i] = 32 - i;
    }
    for (int i = 0; i < 32; i++) {
      inputZReg[9].uh_dt[i] = 3;
    }
    for (int i = 0; i < 32; i++) {
      inputZReg[10].uh_dt[i] = 0xffe0;
    }
    for (int i = 0; i < 32; i++) {
      inputZReg[11].uh_dt[i] = (32 - i) | 0xffe0;
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;

    /* z31 - z29 are used as zTmpIdx - zTmp3Idx */
    addr = reinterpret_cast<size_t>(&(inputZReg[19].ud_dt[0]));
    mov(rcx, addr);
    vpermw(Xmm(1), Xmm(18), ptr[rcx]);
    vpermw(Xmm(2), Xmm(2), ptr[rcx]);

    addr = reinterpret_cast<size_t>(&(inputZReg[3].ud_dt[0]));
    mov(rcx, addr);
    vpermw(Xmm(3), Xmm(18), ptr[rcx]);

    addr = reinterpret_cast<size_t>(&(inputZReg[18].ud_dt[0]));
    mov(rcx, addr);
    vpermw(Xmm(4), Xmm(18), ptr[rcx]);

    addr = reinterpret_cast<size_t>(&(inputZReg[5].ud_dt[0]));
    mov(rcx, addr);
    vpermw(Xmm(5), Xmm(5), ptr[rcx]);

    addr = reinterpret_cast<size_t>(&(inputZReg[29].ud_dt[0]));
    mov(rcx, addr);
    vpermw(Xmm(29), Xmm(29), ptr[rcx]);

    addr = reinterpret_cast<size_t>(&(inputZReg[30].ud_dt[0]));
    mov(rcx, addr);
    vpermw(Xmm(30), Xmm(30), ptr[rcx]);

    addr = reinterpret_cast<size_t>(&(inputZReg[31].ud_dt[0]));
    mov(rcx, addr);
    vpermw(Xmm(31), Xmm(31), ptr[rcx]);

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
