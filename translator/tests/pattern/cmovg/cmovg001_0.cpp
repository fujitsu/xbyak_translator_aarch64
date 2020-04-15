
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
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */

    mov(eax, int64_t(0x8));
    mov(ebx, int64_t(0x9));
    mov(ecx, int64_t(0x10));
    mov(edx, int64_t(0x11));

    //    mov(r11, int64_t(0x0));
    mov(r12, int64_t(0xFFFF000000000000));
    //    mov(r13, int64_t(0x0));
    mov(r14, int64_t(0x8000000000000000));
    mov(r15, int64_t(0x7FFF000000000000));

    cmp(r15, r15);

    /*
    #ifdef XBYAK_TRANSLATE_AARCH64
        Xbyak_aarch64::XReg x_tmpFlag{x0};
        mrs(x_tmpFlag, 0x3, 0x3, 0x4, 0x2, 0x0);
    #endif
    */
    cmovg(ebx, eax);

    cmp(r14, r15);

    cmovg(ecx, edx);

    //#ifdef XBYAK_TRANSLATE_AARCH64
    //      Xbyak_aarch64::XReg x_tmpFlag{x0};
    //      Xbyak_aarch64::XReg y_tmpFlag{x12};
    //      msr(0x3, 0x3, 0x4, 0x2, 0x0, y_tmpFlag);
    //      mrs(x_tmpFlag, 0x3, 0x3, 0x4, 0x2, 0x0);
    //#endif
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
