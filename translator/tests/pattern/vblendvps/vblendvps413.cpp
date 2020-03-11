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
    

    for(int i=1; i<=2; i++) {
      inputZReg[i].us_dt[0] = uint32_t(0x55555555);
      inputZReg[i].us_dt[1] = uint32_t(0x7FFFFFFF);
      inputZReg[i].us_dt[2] = uint32_t(0x0);
      inputZReg[i].us_dt[3] = uint32_t(0x80000000);
      inputZReg[i].us_dt[4] = uint32_t(0x55555555);
      inputZReg[i].us_dt[5] = uint32_t(0x7FFFFFFF);
      inputZReg[i].us_dt[6] = uint32_t(0x0);
      inputZReg[i].us_dt[7] = uint32_t(0x80000000);
    }
      
    inputZReg[9].us_dt[0] = uint32_t(0x55555555);
    inputZReg[9].us_dt[1] = uint32_t(0x7FFFFFFF);
    inputZReg[9].us_dt[2] = uint32_t(0x0);
    inputZReg[9].us_dt[3] = uint32_t(0x80000000);
    inputZReg[9].us_dt[4] = uint32_t(0x55555555);
    inputZReg[9].us_dt[5] = uint32_t(0x7FFFFFFF);
    inputZReg[9].us_dt[6] = uint32_t(0x0);
    inputZReg[9].us_dt[7] = uint32_t(0x80000000);

    inputZReg[10].us_dt[2] = uint32_t(0x55555555);
    inputZReg[10].us_dt[3] = uint32_t(0x7FFFFFFF);
    inputZReg[10].us_dt[0] = uint32_t(0x0);
    inputZReg[10].us_dt[1] = uint32_t(0x80000000);
    inputZReg[10].us_dt[4] = uint32_t(0x55555555);
    inputZReg[10].us_dt[5] = uint32_t(0x7FFFFFFF);
    inputZReg[10].us_dt[6] = uint32_t(0x0);
    inputZReg[10].us_dt[7] = uint32_t(0x80000000);
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;
    addr = reinterpret_cast<size_t>(&(inputZReg[8].ud_dt[0]));
    mov(rax, addr);
    vblendvps(Ymm(1), Ymm(1), ptr[rax], Ymm(9));
    vblendvps(Ymm(2), Ymm(2), ptr[rax], Ymm(10));
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
