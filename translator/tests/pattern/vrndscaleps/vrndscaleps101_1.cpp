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
#define MOVE_SEED 100
    for (int i = 0; i < MOVE_SEED; i++) {
      getLfsr();
    }
#undef MOVE_SEED

    setDumpZRegMode(SP_DT);
    setInputZregAllRandomFloat();

    for (int j = 0; j < 32; j++) {
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
    unsigned int rounding_direction = 1;

    /* Register index is VEX range. */
    vrndscaleps(Zmm(2), Zmm(0), 0x00 + rounding_direction);
    vrndscaleps(Zmm(3), Zmm(1), 0x00 + rounding_direction);
    vrndscaleps(Zmm(4), Zmm(0), 0x10 + rounding_direction);
    vrndscaleps(Zmm(5), Zmm(1), 0x10 + rounding_direction);
    vrndscaleps(Zmm(6), Zmm(0), 0x20 + rounding_direction);
    vrndscaleps(Zmm(7), Zmm(1), 0x20 + rounding_direction);
    vrndscaleps(Zmm(8), Zmm(0), 0x50 + rounding_direction);
    vrndscaleps(Zmm(9), Zmm(1), 0x50 + rounding_direction);
    vrndscaleps(Zmm(10), Zmm(0), 0xa0 + rounding_direction);
    vrndscaleps(Zmm(11), Zmm(1), 0xa0 + rounding_direction);
    vrndscaleps(Zmm(12), Zmm(0), 0xc0 + rounding_direction);
    vrndscaleps(Zmm(13), Zmm(1), 0xc0 + rounding_direction);
    vrndscaleps(Zmm(14), Zmm(0), 0xf0 + rounding_direction);
    vrndscaleps(Zmm(15), Zmm(1), 0xf0 + rounding_direction);

    /* Register index is EVEX range. */
    vrndscaleps(Zmm(16), Zmm(16),
                0x00 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(17), Zmm(17),
                0x10 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(18), Zmm(18),
                0x20 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(19), Zmm(19),
                0x30 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(20), Zmm(20),
                0x40 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(21), Zmm(21),
                0x50 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(22), Zmm(22),
                0x60 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(23), Zmm(23),
                0x70 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(24), Zmm(24),
                0x80 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(25), Zmm(25),
                0x90 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(26), Zmm(26),
                0xa0 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(27), Zmm(27),
                0xb0 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(28), Zmm(28),
                0xc0 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(29), Zmm(29),
                0xd0 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(30), Zmm(30),
                0xe0 + rounding_direction); /* dstIdx = srcIdx */
    vrndscaleps(Zmm(31), Zmm(31),
                0xf0 + rounding_direction); /* dstIdx = srcIdx */
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
