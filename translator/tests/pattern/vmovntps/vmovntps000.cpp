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

    inputZReg[0].ud_dt[0] = 0xAAAABBBBCCCCDDDD;
    inputZReg[0].ud_dt[1] = 0;
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr, addr1;

    /* Address is aligned */
    addr = reinterpret_cast<size_t>(&(inputZReg[27].ud_dt[0]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[28].ud_dt[8]));
    mov(rax, addr);
    mov(rcx, addr1);
    
    std::cout << "Address is " << std::hex << addr << std::endl;
    std::cout << "Address is " << std::hex << addr1 << std::endl;
    /* VEX encoding */
    vmovntps(ptr[rax], Xmm(0));
    vmovdqu8(Xmm(1), ptr[rax]);
    
    /* EVEX encoding */
    vmovntps(ptr[rcx], Xmm(16));
    vmovdqu8(Xmm(17), ptr[rcx]);

    /* VEX encoding */
    vmovntps(ptr[rax], Ymm(2));
    vmovdqu8(Ymm(3), ptr[rax]);
    
    /* EVEX encoding */
    vmovntps(ptr[rcx], Ymm(18));
    vmovdqu8(Ymm(19), ptr[rcx]);
    
    /* VEX encoding */
    vmovntps(ptr[rax], Zmm(4));
    vmovdqu8(Zmm(5), ptr[rax]);
    
    /* EVEX encoding */
    vmovntps(ptr[rcx], Zmm(20));
    vmovdqu8(Zmm(21), ptr[rcx]);

    
    mov(rax, 5);
    mov(rcx, 5);
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
