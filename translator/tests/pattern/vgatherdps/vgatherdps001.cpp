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

    for(int i=8; i<15; i++) {
      for(int j=0; j<16; j++) {
	inputZReg[i].us_dt[j]= 0x7fffffff;
      }
    }
    
    inputZReg[8].us_dt[0] = uint64_t(1) << 31;

    inputZReg[9].us_dt[0] = uint64_t(1) << 31;
    inputZReg[9].us_dt[7] = uint64_t(1) << 31;

    inputZReg[10].us_dt[0] = (1 << 31);
    inputZReg[10].us_dt[7] = (1 << 31);
    inputZReg[10].us_dt[11] = (1 << 31);
    inputZReg[10].us_dt[15] = (1 << 31);
    
    inputZReg[11].us_dt[0] = (1 << 31);
    inputZReg[11].us_dt[7] = (1 << 31);
    inputZReg[11].us_dt[11] = (1 << 31);
    inputZReg[11].us_dt[13] = (1 << 31);
    inputZReg[11].us_dt[15] = (1 << 31);

    inputZReg[12].us_dt[0] = (1 << 31);
    inputZReg[12].us_dt[9] = (1 << 31);
    inputZReg[12].us_dt[11] = (1 << 31);
    inputZReg[12].us_dt[13] = (1 << 31);
    inputZReg[12].us_dt[14] = (1 << 31);
    inputZReg[12].us_dt[15] = (1 << 31);

    inputZReg[13].us_dt[0] = (1 << 31);
    inputZReg[13].us_dt[9] = (1 << 31);
    inputZReg[13].us_dt[10] = (1 << 31);
    inputZReg[13].us_dt[11] = (1 << 31);
    inputZReg[13].us_dt[13] = (1 << 31);
    inputZReg[13].us_dt[14] = (1 << 31);
    inputZReg[13].us_dt[15] = (1 << 31);

    for(int i=0; i<16; i++) {
      inputZReg[14].us_dt[i] = (1 << 31);
    }


    /* Address index */
    for (int i = 0; i < 8; i++) {
      inputZReg[15].us_dt[i] = i * 4;
    }

    for (int i = 8; i < 10; i++) {
      inputZReg[15].us_dt[i] = 16;
    }

    for (int i = 10; i < 12; i++) {
      inputZReg[15].us_dt[i] = -32;
    }

    for (int i = 12; i < 16; i++) {
      inputZReg[15].us_dt[i] = -64;
    }

  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;

    /* Address is aligned */
    addr = reinterpret_cast<size_t>(&(inputZReg[16].us_dt[0]));

    mov(rax, addr);

    /* Indices of Dest, Index and Mask register must be different from each other. */
    vgatherdps(Ymm(1), ptr[rax + Ymm(15)*2 + 0x10], Ymm(8));
    vgatherdps(Ymm(2), ptr[rax + Ymm(15)*2 - 0x10], Ymm(9));
    vgatherdps(Ymm(3), ptr[rax + Ymm(15)*2], Ymm(10));
    vgatherdps(Ymm(4), ptr[rax + Ymm(15)*2], Ymm(11));
    vgatherdps(Ymm(5), ptr[rax + Ymm(15)*2], Ymm(12));
    vgatherdps(Ymm(6), ptr[rax + Ymm(15)*2], Ymm(13));
    vgatherdps(Ymm(7), ptr[rax + Ymm(15)*2], Ymm(14));
    mov(rax, 5);
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

#ifndef __ARM_ARCH
    // Adjust Pred reg values to x64's mask reg
    gen.modifyPredReg(US_DT);
#endif

    gen.dumpOutputReg(); /* Dump all register values */
    gen.dumpCheckReg();  /* Dump register values to be checked */
  }

  return 0;
}
