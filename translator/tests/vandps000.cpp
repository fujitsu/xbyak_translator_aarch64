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
#include "test_generator.h"

class TestPtnGenerator : public TestGenerator {
public:
  void setInitialRegValue() {
    /* Here modify arrays of inputGenReg, inputPredReg, inputZReg */
    //    for (int i=0; i<8 ;i++){
    //	inputZReg[0].ud_dt[i] = 0x0;
    //    }

    for (int i = 0; i < 8; i++) {
      inputZReg[0].ud_dt[i] = ~uint64_t(0);
      inputZReg[3].ud_dt[i] = ~uint64_t(0);
      inputZReg[6].ud_dt[i] = ~uint64_t(0);
    }

    for (int i = 0; i < 8; i++) {
      inputZReg[1].ud_dt[i] = uint32_t(0xFF00FF00AA55AA55);
      inputZReg[4].ud_dt[i] = uint32_t(0xFF00FF00AA55AA55);
      inputZReg[7].ud_dt[i] = uint32_t(0xFF00FF00AA55AA55);
    }

    //	inputZReg[31].ud_dt[0] = ~uint64_t(0);
    //	inputZReg[31].ud_dt[2] = ~uint64_t(0);

    //    for (int i=0; i< 8; i++){
    //	inputZReg[1].ud_dt[i] = 0xFFFFFFFFFFFFFFFF;
    //    }

    //    for (int i=0; i< 8; i++){
    //	inputZReg[2].ud_dt[i] = 0x12345;
    //    }

    //    for (int i=0; i< 15; i++){
    //    	inputPredReg[i] = 0xFFFFFFFFFFFFFFFF;
    //    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    //    static const uint64_t maskFF = uint64_t(0xFF);
    //    mov(rax, (size_t)&maskFF);
    //	size_t addr;
    //	addr = reinterpret_cast<size_t>(&(inputZReg[31].ud_dt[0]));

    //	mov(rax, addr);
    //	vandps(Ymm(2), Ymm(0), ptr[rax]);

    //	mov(rax, 5);

    //    vandps(Ymm(0), Ymm(1), ptr[rax]);

    vandps(Ymm(2), Ymm(0), Ymm(1));
  }

  //  struct xt_a64fx_operands_struct_t a64;
  //  xt_dump_a64fx_operands(&a64);
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

  /* Before executing JIT code, dump inputData, inputGenReg, inputPredReg,
   * inputZReg. */
  gen.dumpInputReg();

  /* Dump generated JIT code to a binary file */
  gen.dumpJitCode();

  /* 1:Execute JIT code, 2:dump all register values, 3:dump register values to
   * be checked */
  if (gen.isExecJitOn()) {
    f();                 /* Execute JIT code */
    gen.dumpOutputReg(); /* Dump all register values */
    gen.dumpCheckReg();  /* Dump register values to be checked */
  }

  return 0;
}
