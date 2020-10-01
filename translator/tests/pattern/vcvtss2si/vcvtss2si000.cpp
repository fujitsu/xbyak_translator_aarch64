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
    setInputZregAllRandomFloat();

    for (int i = 0; i < 4; i++) {
      inputZReg[2 * i + 0].sp_dt[0] = 0.0f;
      inputZReg[2 * i + 0].sp_dt[1] = 0.4f;
      inputZReg[2 * i + 0].sp_dt[2] = 0.5f;
      inputZReg[2 * i + 0].sp_dt[3] = 0.6f;
      inputZReg[2 * i + 0].sp_dt[4] = 1.4f;
      inputZReg[2 * i + 0].sp_dt[5] = 1.5f;
      inputZReg[2 * i + 0].sp_dt[6] = 1.6f;
      inputZReg[2 * i + 0].sp_dt[7] = 2.4f;
      inputZReg[2 * i + 0].sp_dt[8] = 2.5f;
      inputZReg[2 * i + 0].sp_dt[9] = 2.6f;
      inputZReg[2 * i + 0].sp_dt[10] = 3.5f;
      inputZReg[2 * i + 0].sp_dt[11] = 4.5f;
      inputZReg[2 * i + 0].sp_dt[12] = 5.5f;
      inputZReg[2 * i + 0].us_dt[13] = 0x4efffffd;
      inputZReg[2 * i + 0].us_dt[14] = 0x4efffffe;
      inputZReg[2 * i + 0].us_dt[15] =
          0x4effffff; /* max float number represented by int32_t */

      inputZReg[2 * i + 1].sp_dt[0] = 0.0f;
      inputZReg[2 * i + 1].sp_dt[1] = -0.4f;
      inputZReg[2 * i + 1].sp_dt[2] = -0.5f;
      inputZReg[2 * i + 1].sp_dt[3] = -0.6f;
      inputZReg[2 * i + 1].sp_dt[4] = -1.4f;
      inputZReg[2 * i + 1].sp_dt[5] = -1.5f;
      inputZReg[2 * i + 1].sp_dt[6] = -1.6f;
      inputZReg[2 * i + 1].sp_dt[7] = -2.4f;
      inputZReg[2 * i + 1].sp_dt[8] = -2.5f;
      inputZReg[2 * i + 1].sp_dt[9] = -2.6f;
      inputZReg[2 * i + 1].sp_dt[10] = -3.5f;
      inputZReg[2 * i + 1].sp_dt[11] = -4.5f;
      inputZReg[2 * i + 1].sp_dt[12] = -5.5f;
      inputZReg[2 * i + 1].us_dt[13] = 0xcefffffd;
      inputZReg[2 * i + 1].us_dt[14] = 0xcefffffe;
      inputZReg[2 * i + 1].us_dt[15] =
          0xceffffff; /* min float number represented by int32_t */
    }

#if 0
    for (int j = 2; j < 32; j++) {
      for (int i = 0; i < 16; i++) {
        while (inputZReg[j].sp_dt[i] < -2.14748352e+9 ||
               2.14748352e+9 < inputZReg[j].sp_dt[i]) {
          inputZReg[j].uh_dt[2 * i + 0] = getLfsr();
          inputZReg[j].uh_dt[2 * i + 1] = getLfsr();
        }
      }
    }
#endif
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12, r13, r14,
     * r15 */

    size_t addr0, addr1, addr2, addr3;
    std::vector<mkldnn_round_mode_t> rmode = {
        mkldnn_round_nearest, mkldnn_round_down, mkldnn_round_up,
        mkldnn_round_zero};
    int j = 0;

    for (const auto &e : rmode) {
      set_rnd_mode(e);
      for (int i = 0; i < 16; i++) {
        addr0 = reinterpret_cast<size_t>(&(inputZReg[2 * j + 0].us_dt[i]));
        addr1 = reinterpret_cast<size_t>(&(inputZReg[2 * j + 1].us_dt[i]));

        addr2 = reinterpret_cast<size_t>(
            &(inputZReg[12 + 4 * j + int(i / 8) + 0].ud_dt[i % 8]));
        addr3 = reinterpret_cast<size_t>(
            &(inputZReg[12 + 4 * j + int(i / 8) + 2].ud_dt[i % 8]));

        mov(rcx, addr0);
        mov(rdx, addr1);

        vmovups(Xmm(8), ptr[rcx]);  /* Register index is VEX range. */
        vmovups(Xmm(31), ptr[rdx]); /* Register index is EVEX range. */

        vcvtss2si(rcx, Xmm(8));  /* Instruction under test */
        vcvtss2si(rdx, Xmm(31)); /* Instruction under test */

        mov(rbp, addr2);
        mov(rsi, addr3);
        mov(ptr[rbp], rcx);
        mov(ptr[rsi], rdx);
      }
      j++;
    }

    for (int i = 12; i < 12 + 8 * 2; i++) {
      addr0 = reinterpret_cast<size_t>(&(inputZReg[i].ud_dt[0]));
      mov(rcx, addr0);
      vmovups(Zmm(i), ptr[rcx]);
    }

    mov(rcx, 5);
    mov(rdx, 5);
    mov(rbp, 5);
    mov(rsi, 5);
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
