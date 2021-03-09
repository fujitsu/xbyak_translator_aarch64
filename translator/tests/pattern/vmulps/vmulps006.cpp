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
    setDumpZRegMode(SP_DT);
    setInputZregAllRandomFloat();

    for (int i = 0; i < 16; i++) {
      inputZReg[0].sp_dt[i] = 0.5 + float(i);
      inputZReg[1].sp_dt[i] = float(2.0);
    }

    inputPredReg[2] = uint64_t(0x1);
    inputPredReg[3] = (0x1 << 0) | (0x1 << 1) | (0x1 << 4) | /* x86_64 */
                      (0x1 << 0) | (0x1 << 4) | (0x1 << 16); /* aarch64 */

    inputPredReg[4] =
      (0x1 << 0) | (0x1 << 1) | (0x1 << 4) | (0x1 << 5) | /* x86_64 */
      (0x1 << 0) | (0x1 << 4) | (0x1 << 16)| (0x1 << 20); /* aarch64 */

    inputPredReg[5] = (0x1 << 0) | (0x1 << 1) | (0x1 << 4) | (0x1 << 5) |
                      (0x1 << 7) | /* x86_64 */
                      (0x1 << 0) | (0x1 << 4) | (0x1 << 16) | (0x1 << 20) |
                      (0x1 << 28); /* aarch64 */

    inputPredReg[6] = (0x1 << 0) | (0x1 << 1) | (0x1 << 4) | (0x1 << 6) |
                      (0x1 << 7) | (0x1 << 9) | /* x86_64 */
                      (0x1 << 0) | (0x1 << 4) | (0x1 << 16) | (0x1 << 24) |
                      (uint64_t(0x1) << 28) | (uint64_t(0x1) << 36); /* aarch64 */

    inputPredReg[7] = (0x1 << 0) | (0x1 << 1) | (0x1 << 4) | (0x1 << 7) |
                      (0x1 << 9) | (0x1 << 11) | (0x1 << 15) | /* x86_64 */
                      (0x1 << 0) | (0x1 << 4) | (0x1 << 16) | (0x1 << 28) |
                      (uint64_t(0x1) << 36) | (uint64_t(0x1) << 44) |
                      (uint64_t(0x1) << 60); /* aarch64 */
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    mov(rax, reinterpret_cast<size_t>(&(inputZReg[0].sp_dt[0])));
    vmulps(Zmm(2), Zmm(1) | k2 | T_z, ptr[rax]);
    vmulps(Zmm(3), Zmm(1) | k3 | T_z, ptr[rax]);
    vmulps(Zmm(4), Zmm(1) | k4 | T_z, ptr[rax]);
    vmulps(Zmm(5), Zmm(1) | k5 | T_z, ptr[rax]);
    vmulps(Zmm(6), Zmm(1) | k6 | T_z, ptr[rax]);
    vmulps(Zmm(7), Zmm(1) | k7 | T_z, ptr[rax]);

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
