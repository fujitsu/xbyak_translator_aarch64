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
    //    setInputZregAllRandomHex();

    for (int i = 0; i < 4; i++) {
      inputZReg[30].ub_dt[0 + i] = 0x1;
      inputZReg[31].ub_dt[0 + i] = 0x1;

      inputZReg[30].ub_dt[4 + i] = 0x1;
      inputZReg[31].ub_dt[4 + i] = 0xff;

      inputZReg[30].ub_dt[8 + i] = 0xff;
      inputZReg[31].ub_dt[8 + i] = 0x1;

      inputZReg[30].ub_dt[12 + i] = 0x7f;
      inputZReg[31].ub_dt[12 + i] = 0x7f;

      inputZReg[30].ub_dt[16 + i] = 0xff;
      inputZReg[31].ub_dt[16 + i] = 0xff;

      inputZReg[30].ub_dt[20 + i] = 0xff;
      inputZReg[31].ub_dt[20 + i] = 0x7f;

      inputZReg[30].ub_dt[24 + i] = 0x7f;
      inputZReg[31].ub_dt[24 + i] = 0xff;
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

#ifdef __ARM_ARCH
  template <class T>
  void vpdpbusd(T vreg_0, T vreg_1, T vreg_2, T vreg_one, T vreg_tmp) {
    CodeGenerator::vpdpbusd(vreg_0, vreg_1, vreg_2);
  }
#else
  /* Test on no VNNI support CPU */
  template <class T>
  void vpdpbusd(T vreg_0, T vreg_1, T vreg_2, T vreg_one, T vreg_tmp) {
    vpmaddubsw(vreg_tmp, vreg_1, vreg_2);
    vpmaddwd(vreg_tmp, vreg_tmp, vreg_one);
    vpaddd(vreg_0, vreg_0, vreg_tmp);
  }
#endif

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    mov(r8, 0x1);
    vpbroadcastw(Zmm(29), r8w);

    //    vpdpbusd(Xmm(0), Xmm(30), Xmm(31), Xmm(29), Xmm(28));
    //    vpdpbusd(Xmm(1), Xmm(30), Xmm(31), Xmm(29), Xmm(28));
    vpdpbusd(Ymm(2), Ymm(30), Ymm(31), Ymm(29), Ymm(28));
    //    vpdpbusd(Ymm(3), Ymm(30), Ymm(31), Ymm(29), Ymm(28));
    //    vpdpbusd(Zmm(4), Zmm(30), Zmm(31), Zmm(29), Zmm(28));
    //    vpdpbusd(Zmm(5), Zmm(30), Zmm(31), Zmm(29), Zmm(28));

    //    vpdpbusd(Xmm(6), Xmm(6), Xmm(31), Xmm(29), Xmm(28));
    //    vpdpbusd(Xmm(7), Xmm(30), Xmm(7), Xmm(29), Xmm(28));
    //    vpdpbusd(Xmm(8), Xmm(30), Xmm(30), Xmm(29), Xmm(28));
    //    vpdpbusd(Xmm(9), Xmm(9), Xmm(9), Xmm(29), Xmm(28));

    //    vpdpbusd(Ymm(10), Ymm(10), Ymm(31), Ymm(29), Ymm(28));
    //    vpdpbusd(Ymm(11), Ymm(30), Ymm(11), Ymm(29), Ymm(28));
    //    vpdpbusd(Ymm(12), Ymm(30), Ymm(30), Ymm(29), Ymm(28));
    //    vpdpbusd(Ymm(13), Ymm(13), Ymm(13), Ymm(29), Ymm(28));

    //    vpdpbusd(Zmm(14), Zmm(14), Zmm(31), Zmm(29), Zmm(28));
    //    vpdpbusd(Zmm(15), Zmm(30), Zmm(15), Zmm(29), Zmm(28));
    //    vpdpbusd(Zmm(16), Zmm(30), Zmm(30), Zmm(29), Zmm(28));
    //    vpdpbusd(Zmm(17), Zmm(17), Zmm(17), Zmm(29), Zmm(28));

    vpbroadcastw(Zmm(28), r8w);
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
