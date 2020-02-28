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

    for(int i=0; i<8; i++) {
      inputZReg[7].us_dt[i*2]   =      inputZReg[10].us_dt[i*2]   = inputZReg[13].us_dt[i*2] = uint32_t(1) << 31;
      inputZReg[7].us_dt[i*2+1] =      inputZReg[10].us_dt[i*2+1] = inputZReg[13].us_dt[i*2+1] = 0;
      inputZReg[8].us_dt[i*2]   =      inputZReg[11].us_dt[i*2]   =      inputZReg[14].us_dt[i*2] = uint32_t(0x7FFFFFFF);
      inputZReg[8].us_dt[i*2+1] =      inputZReg[11].us_dt[i*2+1] =       inputZReg[14].us_dt[i*2+1] = ~uint32_t(0);
      inputZReg[9].us_dt[i*2]   =      inputZReg[12].us_dt[i*2]   =     inputZReg[15].us_dt[i*2] = uint32_t(0);
      inputZReg[9].us_dt[i*2+1] =      inputZReg[12].us_dt[i*2+1] =       inputZReg[15].us_dt[i*2+1] = ~uint32_t(0);
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;

    /* Address is aligned */
    addr = reinterpret_cast<size_t>(&(inputZReg[16].ud_dt[0]));
    mov(rax, addr);

    vmaskmovps(ptr[rax], Xmm(13),  Xmm(0));
    add(rax, 64);
    vmaskmovps(ptr[rax], Xmm(14),  Xmm(1));
    add(rax, 64);
    vmaskmovps(ptr[rax], Xmm(15),  Xmm(2));
    add(rax, 64);
	       	 		         
    vmaskmovps(ptr[rax], Ymm(13),  Ymm(3));
    add(rax, 64);
    vmaskmovps(ptr[rax], Ymm(14),  Ymm(4));
    add(rax, 64);
    vmaskmovps(ptr[rax], Ymm(15),  Ymm(5));
    add(rax, 64);
	       	 		         
    vmaskmovps(ptr[rax], Ymm(7),   Ymm(7));
    add(rax, 64);
    vmaskmovps(ptr[rax], Ymm(8),   Ymm(8));
    add(rax, 64);
    vmaskmovps(ptr[rax], Ymm(9),   Ymm(9));
    add(rax, 64);
	       	 		         
    vmaskmovps(ptr[rax], Ymm(10), Ymm(10));
    add(rax, 64);
    vmaskmovps(ptr[rax], Ymm(11), Ymm(11));
    add(rax, 64);
    vmaskmovps(ptr[rax], Ymm(12), Ymm(12));
    add(rax, 64);

    /* Check result */
    mov(rax, addr);
    vmovdqu8(Zmm(16), ptr[rax]);
    add(rax, 64);
    vmovdqu8(Zmm(17), ptr[rax]);
    add(rax, 64);
    vmovdqu8(Zmm(18), ptr[rax]);
    add(rax, 64);
    vmovdqu8(Zmm(19), ptr[rax]);
    add(rax, 64);
    vmovdqu8(Zmm(20), ptr[rax]);
    add(rax, 64);
    vmovdqu8(Zmm(21), ptr[rax]);
    add(rax, 64);
    vmovdqu8(Zmm(22), ptr[rax]);
    add(rax, 64);
    vmovdqu8(Zmm(23), ptr[rax]);
    add(rax, 64);
    vmovdqu8(Zmm(24), ptr[rax]);
    add(rax, 64);
    vmovdqu8(Zmm(25), ptr[rax]);
    add(rax, 64);
    vmovdqu8(Zmm(26), ptr[rax]);
    add(rax, 64);
    vmovdqu8(Zmm(27), ptr[rax]);
    add(rax, 64);
    
    mov(rax,
        size_t(0x5)); // Clear RAX for diff check between x86_64 and aarch64
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
