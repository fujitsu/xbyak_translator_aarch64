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

    inputPredReg[1] = uint64_t(0); /* Both x86_64 and aarch64 */
    inputPredReg[2] = 0x100010001; /* Both x86_64 and aarch64 */
    inputPredReg[3] = 0x400040004; /* Both x86_64 and aarch64 */
    inputPredReg[4] = 0x1000100010; /* Both x86_64 and aarch64 */
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    mov(r8, 0xabcd);    
    mov(r9, 0x1234);
    mov(r10, 0x5678);    

    vpbroadcastb(Xmm(0) | k1 | T_z, Xmm(31));
    vpbroadcastb(Ymm(1) | k1 | T_z, Xmm(30));
    vpbroadcastb(Zmm(2) | k1 | T_z, Xmm(29));
    vpbroadcastb(Xmm(3) | k2 | T_z, Xmm(28));
    vpbroadcastb(Ymm(4) | k3 | T_z, Xmm(27));
    vpbroadcastb(Zmm(5) | k4 | T_z, Xmm(26));
    vpbroadcastb(Xmm(6) | k1 | T_z, r8b);
    vpbroadcastb(Ymm(7) | k1 | T_z, r9b);
    vpbroadcastb(Zmm(8) | k1 | T_z, r10b);
    vpbroadcastb(Xmm(9) | k4 | T_z, r8b);
    vpbroadcastb(Ymm(10) | k2 | T_z, r9b);
    vpbroadcastb(Zmm(11) | k3 | T_z, r10b);
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
