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

    for (int j = 0; j < 32; j++) {
      for (int i = 0; i < 16; i++) {
        inputZReg[j].us_dt[i] = (j << 16) + i;
      }
    }

    for (int i = 0; i < 16; i++) {
      inputZReg[31].us_dt[i] = 0x11111111 * i;
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  template <typename U, typename T>
  void genJitTranspose4x4(U *srcMatrix, U *dstMatrix, T dummy) {
#define NUM_ROW_COL 4
#define SIMD_WIDTH 128
    size_t addrSrc, addrDst;
    addrSrc = reinterpret_cast<size_t>(srcMatrix);
    addrDst = reinterpret_cast<size_t>(dstMatrix);
    CodeGeneratorAArch64::mov_imm(x0, addrSrc, x16);
    CodeGeneratorAArch64::mov_imm(x1, addrDst, x16);

    size_t NUM_ROW = (sizeof(U) * 8 * NUM_ROW_COL) / SIMD_WIDTH;
    size_t NUM_ELEM_IN_SIMD = SIMD_WIDTH / (sizeof(U) * 8);

    for (size_t row = 0; row < NUM_ROW; row++) {
      CodeGeneratorAArch64::ld1(T(row), Xbyak_aarch64::ptr(x0));
    }

    for (size_t row = 0; row < NUM_ROW_COL; row++) {
      for (size_t col = 0; col < NUM_ROW_COL; col++) {
        size_t srcIndex = NUM_ROW_COL * row + col;
        size_t srcRow = srcIndex / NUM_ELEM_IN_SIMD;
        size_t srcCol = srcIndex % NUM_ELEM_IN_SIMD;
        size_t dstIndex = NUM_ROW_COL * col + row;
        size_t dstRow = 8 + dstIndex / NUM_ELEM_IN_SIMD;
        size_t dstCol = dstIndex % NUM_ELEM_IN_SIMD;

        CodeGeneratorAArch64::mov(T(dstRow)[dstCol], T(srcRow)[srcCol]);
      }
    }

    for (size_t row = 0; row < NUM_ROW; row++) {
      CodeGeneratorAArch64::st1(T(row), Xbyak_aarch64::ptr(x1));
    }
  }

  void genJitTestCode() {
    uint64_t *src64 = (uint64_t *)std::malloc(4 * 4 * sizeof(uint64_t));
    uint32_t *src32 = (uint32_t *)std::malloc(4 * 4 * sizeof(uint32_t));
    uint16_t *src16 = (uint16_t *)std::malloc(4 * 4 * sizeof(uint16_t));
    uint8_t *src8 = (uint8_t *)std::malloc(4 * 4 * sizeof(uint8_t));
    uint64_t *dst64 = (uint64_t *)std::malloc(4 * 4 * sizeof(uint64_t));
    uint32_t *dst32 = (uint32_t *)std::malloc(4 * 4 * sizeof(uint32_t));
    uint16_t *dst16 = (uint16_t *)std::malloc(4 * 4 * sizeof(uint16_t));
    uint8_t *dst8 = (uint8_t *)std::malloc(4 * 4 * sizeof(uint8_t));

    genJitTranspose4x4(src64, dst64, Xbyak_aarch64::VReg2D(0));
    genJitTranspose4x4(src32, dst32, Xbyak_aarch64::VReg4S(0));
    genJitTranspose4x4(src16, dst16, Xbyak_aarch64::VReg8H(0));
    genJitTranspose4x4(src8, dst8, Xbyak_aarch64::VReg16B(0));
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
