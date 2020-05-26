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
    size_t addr0;
    size_t addr1;

    /* Address is unaligned */
    addr0 = reinterpret_cast<size_t>(&(inputZReg[10].ud_dt[0]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[20].ud_dt[0]));
    mov(rax, addr0);
    mov(rbx, addr1);

    movups(ptr[rax], Xmm(0));
    vmovups(Zmm(11), ptr[rax]);

    movups(ptr[rbx], Xmm(1));
    vmovups(Zmm(21), ptr[rbx]);

    movups(ptr[rax], Xmm(2));
    vmovups(Zmm(12), ptr[rax]);

    movups(ptr[rbx], Xmm(10));
    vmovups(Zmm(22), ptr[rbx]);

    movups(ptr[rax], Xmm(11));
    vmovups(Zmm(25), ptr[rax]);

    movups(ptr[rbx], Xmm(12));
    vmovups(Zmm(26), ptr[rbx]);

    mov(rax, 5);
    mov(rbx, 5);
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
