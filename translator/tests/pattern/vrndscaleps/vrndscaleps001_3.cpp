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

#if 1
    for (int j = 16; j < 32; j++) {
      for (int i = 0; i < 16; i++) {
        float scale = pow(2.0f, (float)(j - 16));
        inputZReg[j].sp_dt[i] /= scale;
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
    size_t addr1, addr2;
    addr1 = reinterpret_cast<size_t>(&(inputZReg[0].sp_dt[0]));
    addr2 = reinterpret_cast<size_t>(&(inputZReg[1].sp_dt[0]));
    mov(rax, addr1);
    mov(rcx, addr2);

    unsigned int rounding_direction = 3;

    /* Register index is VEX range. */
    vrndscaleps(Zmm(2), ptr[rax], 0x00 + rounding_direction);
    vrndscaleps(Zmm(3), ptr[rcx], 0x00 + rounding_direction);
    vrndscaleps(Zmm(4), ptr[rax], 0x10 + rounding_direction);
    vrndscaleps(Zmm(5), ptr[rcx], 0x10 + rounding_direction);
    vrndscaleps(Zmm(6), ptr[rax], 0x20 + rounding_direction);
    vrndscaleps(Zmm(7), ptr[rcx], 0x20 + rounding_direction);
    vrndscaleps(Zmm(8), ptr[rax], 0x50 + rounding_direction);
    vrndscaleps(Zmm(9), ptr[rcx], 0x50 + rounding_direction);
    vrndscaleps(Zmm(10), ptr[rax], 0xa0 + rounding_direction);
    vrndscaleps(Zmm(11), ptr[rcx], 0xa0 + rounding_direction);
    vrndscaleps(Zmm(12), ptr[rax], 0xc0 + rounding_direction);
    vrndscaleps(Zmm(13), ptr[rcx], 0xc0 + rounding_direction);
    vrndscaleps(Zmm(14), ptr[rax], 0xf0 + rounding_direction);
    vrndscaleps(Zmm(15), ptr[rcx], 0xf0 + rounding_direction);

    /* Register index is EVEX range. */
    addr1 = reinterpret_cast<size_t>(&(inputZReg[16].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(16), ptr[rax], 0x00 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[17].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(17), ptr[rax], 0x10 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[18].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(18), ptr[rax], 0x20 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[19].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(19), ptr[rax], 0x30 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[20].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(20), ptr[rax], 0x40 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[21].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(21), ptr[rax], 0x50 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[22].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(22), ptr[rax], 0x60 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[23].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(23), ptr[rax], 0x70 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[24].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(24), ptr[rax], 0x80 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[25].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(25), ptr[rax], 0x90 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[26].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(26), ptr[rax], 0xa0 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[27].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(27), ptr[rax], 0xb0 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[28].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(28), ptr[rax], 0xc0 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[29].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(29), ptr[rax], 0xd0 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[30].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(30), ptr[rax], 0xe0 + rounding_direction);

    addr1 = reinterpret_cast<size_t>(&(inputZReg[31].sp_dt[0]));
    mov(rax, addr1);
    vrndscaleps(Zmm(31), ptr[rax], 0xf0 + rounding_direction);

    mov(rax, 5);
    mov(rcx, 7);
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
