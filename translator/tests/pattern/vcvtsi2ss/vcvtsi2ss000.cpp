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
    //    setDumpZRegMode(SP_DT);
    setInputZregAllRandomFloat();

    inputZReg[0].sp_dt[0] = 0.0f;
    inputZReg[0].sp_dt[1] = 0.4f;
    inputZReg[0].sp_dt[2] = 0.5f;
    inputZReg[0].sp_dt[3] = 0.6f;
    inputZReg[0].sp_dt[4] = 1.4f;
    inputZReg[0].sp_dt[5] = 1.5f;
    inputZReg[0].sp_dt[6] = 1.6f;
    inputZReg[0].sp_dt[7] = 2.4f;
    inputZReg[0].sp_dt[8] = 2.5f;
    inputZReg[0].sp_dt[9] = 2.6f;
    inputZReg[0].sp_dt[10] = 3.5f;
    inputZReg[0].sp_dt[11] = 4.5f;
    inputZReg[0].sp_dt[12] = 5.5f;
    inputZReg[0].us_dt[13] = 0x4efffffd;
    inputZReg[0].us_dt[14] = 0x4efffffe;
    inputZReg[0].us_dt[15] =
        0x4effffff; /* max float number represented by int32_t */

    inputZReg[1].sp_dt[0] = 0.0f;
    inputZReg[1].sp_dt[1] = -0.4f;
    inputZReg[1].sp_dt[2] = -0.5f;
    inputZReg[1].sp_dt[3] = -0.6f;
    inputZReg[1].sp_dt[4] = -1.4f;
    inputZReg[1].sp_dt[5] = -1.5f;
    inputZReg[1].sp_dt[6] = -1.6f;
    inputZReg[1].sp_dt[7] = -2.4f;
    inputZReg[1].sp_dt[8] = -2.5f;
    inputZReg[1].sp_dt[9] = -2.6f;
    inputZReg[1].sp_dt[10] = -3.5f;
    inputZReg[1].sp_dt[11] = -4.5f;
    inputZReg[1].sp_dt[12] = -5.5f;
    inputZReg[1].us_dt[13] = 0xcefffffd;
    inputZReg[1].us_dt[14] = 0xcefffffe;
    inputZReg[1].us_dt[15] =
        0xceffffff; /* min float number represented by int32_t */

    for (int j = 2; j < 32; j++) {
      for (int i = 0; i < 16; i++) {
        while (inputZReg[j].sp_dt[i] < -2.14748352e+9 ||
               2.14748352e+9 < inputZReg[j].sp_dt[i]) {
          inputZReg[j].uh_dt[2 * i + 0] = getLfsr();
          inputZReg[j].uh_dt[2 * i + 1] = getLfsr();
        }
      }
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12, r13, r14,
     * r15 */
    //set_rnd_mode(mkldnn_round_nearest);

    mov(rax, ~uint64_t(0));
    mov(rcx, ~uint64_t(1));
    mov(rbx, uint64_t(0xFFFFFFFF));

    /* Register index is VEX range. */
    vcvtsi2ss(Xmm(1), Xmm(2), rax);
    vcvtsi2ss(Xmm(3), Xmm(3), rax);
    vcvtsi2ss(Xmm(4), Xmm(5), rcx);
    vcvtsi2ss(Xmm(6), Xmm(6), rcx);
    vcvtsi2ss(Xmm(7), Xmm(8), rbx);
    vcvtsi2ss(Xmm(9), Xmm(9), rbx);

    /* Register index is EVEX range. */
    vcvtsi2ss(Xmm(21), Xmm(22), rax);
    vcvtsi2ss(Xmm(23), Xmm(23), rax);
    vcvtsi2ss(Xmm(24), Xmm(25), rcx);
    vcvtsi2ss(Xmm(26), Xmm(26), rcx);
    vcvtsi2ss(Xmm(27), Xmm(28), rbx);
    vcvtsi2ss(Xmm(29), Xmm(29), rbx);
    
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
