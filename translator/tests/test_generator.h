#pragma once
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
#define XBYAK64
#define XBYAK_NO_OP_NAMES
/* in order to make selinux happy memory that would be marked with X-bit should
 * be obtained with mmap */
#define XBYAK_USE_MMAP_ALLOCATOR

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

#include "xbyak.h"
#include "xbyak_util.h"

#ifdef DNNL_AARCH64_JIT_AARCH64
typedef uint32_t xbyak_code_ptr_t;
#else
typedef uint8_t xbyak_code_ptr_t;
#endif

#define NUM_INPUT_DATA 16
/* x86_64 has 16 gen registers. AArch64 has 32 gen registers. */
#define NUM_GEN_REG 16
/* x86_64 has 8 predicate registers. AArch64 has 16 predicate registers. */
#define NUM_PRED_REG 8
#define NUM_Z_REG 32

#define SP_REG_IDX_X86_64 4
#define SP_REG_IDX_AARCH64 31

using namespace Xbyak;

union ZReg_t {
  uint8_t b_dt[64];
  uint16_t h_dt[32];
  uint32_t s_dt[16];
  uint64_t d_dt[8];
};

class TestGenerator : public CodeGenerator {
private:
  unsigned char testData[16] = {
      0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
  };

  unsigned char inputData[NUM_INPUT_DATA];
  uint64_t inputGenReg[NUM_GEN_REG];
  uint64_t inputPredReg[NUM_PRED_REG];
  ZReg_t inputZReg[NUM_Z_REG];

  unsigned char outputData[NUM_INPUT_DATA];
  uint64_t outputGenReg[NUM_GEN_REG];
  uint64_t outputPredReg[NUM_PRED_REG];
  ZReg_t outputZReg[NUM_Z_REG];

  uint64_t expectGenReg[NUM_GEN_REG];
  uint64_t expectPredReg[NUM_PRED_REG];
  ZReg_t expectZReg[NUM_Z_REG];

  void _genJitPreamble() {
    int i;

#ifdef DNNL_AARCH64_JIT_AARCH64
    for (i = 0; i < NUM_GEN_REG; i += 2) {
      // sp address must be aligned by 16.
      stp__(Xbyak_aarch64::XReg(i), Xbyak_aarch64::XReg(i + 1),
            Xbyak_aarch64::pre_ptr(sp_, -16));
    }
#else
    for (i = 0; i < NUM_GEN_REG; i++) {
      if (i != SP_REG_IDX_X86_64) {
        push(Reg64(i));
      }
    }
#endif
  }

  void _genJitPostamble() {
    int i;

#ifdef DNNL_AARCH64_JIT_AARCH64
    for (i = NUM_GEN_REG - 1; i >= 0; i -= 2) {
      ldp__(Xbyak_aarch64::XReg(i), Xbyak_aarch64::XReg(i - 1),
            Xbyak_aarch64::post_ptr(sp_, 16));
    }
#else
    for (i = NUM_GEN_REG - 1; i >= 0; i--) {
      if (i != SP_REG_IDX_X86_64) {
        pop(Reg64(i));
      }
    }
#endif
    ret();
  }

  /* Load data from memory to all general purpose registers */
  void _genJitLoadGenReg() {
#ifdef DNNL_AARCH64_JIT_AARCH64
    /* x0 contains memory address. */
    mov_imm__(x0, reinterpret_cast<uint64_t>(inputGenReg) + 16, x1);
    for (int i = 2; i < NUM_GEN_REG; i++) {
      if (i != SP_REG_IDX_AARCH64) { /* Avoid overwriting stack pointer */
        ldr__(Xbyak_aarch64::XReg(i), Xbyak_aarch64::post_ptr(x0, 8));
      } else {
        add__(x0, x8, 8); /* Incremente address for next register. */
      }
    }
    mov_imm__(x0, reinterpret_cast<uint64_t>(inputGenReg), x1);
    ldp__(Xbyak_aarch64::XReg(0), Xbyak_aarch64::XReg(1),
          Xbyak_aarch64::ptr(x0));
#else  //#ifdef DNNL_AARCH64_JIT_AARCH64
    mov(rax, reinterpret_cast<uint64_t>(inputGenReg) + 8);

    for (int i = 1; i < NUM_GEN_REG; i++) {
      if (i != SP_REG_IDX_X86_64) { /* Avoid overwriting stack pointer */
        mov(Reg64(i), ptr[rax]);
      }
      add(rax, 8);
    }

    mov(rax, reinterpret_cast<uint64_t>(inputGenReg));
    mov(rax, ptr[rax]);
#endif //#ifdef DNNL_AARCH64_JIT_AARCH64
  }

  /* Store data from all general purpose registers to memory */
  void _genJitStoreGenReg() {
#ifdef DNNL_AARCH64_JIT_AARCH64
    /* x0 contains memory address. */
    stp__(x0, x1, Xbyak_aarch64::pre_ptr(sp_, -16)); // push data of x0 and x1

    mov_imm__(x0, reinterpret_cast<uint64_t>(outputGenReg) + 16, x1);
    for (int i = 2; i < NUM_GEN_REG; i++) {
      str__(Xbyak_aarch64::XReg(i), Xbyak_aarch64::post_ptr(x0, 8));
    }

    mov_imm__(x0, reinterpret_cast<uint64_t>(outputGenReg), x1);
    ldp__(Xbyak_aarch64::XReg(2), Xbyak_aarch64::XReg(3),
          Xbyak_aarch64::post_ptr(sp_, 16)); // pop data of x0, x1
    stp__(x2, x3, Xbyak_aarch64::ptr(x0));
#else  //#ifdef DNNL_AARCH64_JIT_AARCH64
    push(rax);
    mov(rax, reinterpret_cast<uint64_t>(outputGenReg) + 8);

    // r1 - r31
    for (int i = 1; i < NUM_GEN_REG; i++) {
      mov(ptr[rax], Reg64(i));
      add(rax, 8);
    }

    // r8
    mov(rax, reinterpret_cast<uint64_t>(outputGenReg));
    pop(rbx);
    mov(ptr[rax], rbx);
#endif //#ifdef DNNL_AARCH64_JIT_AARCH64
  }

  void _genJitLoadPredReg() {
#ifdef DNNL_AARCH64_JIT_AARCH64
    stp__(x0, x1, Xbyak_aarch64::pre_ptr(sp_, -16)); // push x0, x1

    mov_imm__(x0, reinterpret_cast<uint64_t>(inputPredReg), x1);

    for (int i = 0; i < NUM_PRED_REG; i++) {
      ldr__(Xbyak_aarch64::PReg(i), Xbyak_aarch64::ptr(x0, i));
    }

    ldp__(x0, x1, Xbyak_aarch64::post_ptr(sp_, 16)); // pop x0, x1
#else  //#ifdef DNNL_AARCH64_JIT_AARCH64
    push(r8);
    mov(r8, reinterpret_cast<uint64_t>(inputPredReg));

    for (int i = 0; i < NUM_PRED_REG; i++) {
      kmovq(Opmask(i), ptr[r8]);
      add(r8, 8);
    }

    pop(r8);
#endif //#ifdef DNNL_AARCH64_JIT_AARCH64
  }

  void _genJitStorePredReg() {
#ifdef DNNL_AARCH64_JIT_AARCH64
    stp__(x0, x1, Xbyak_aarch64::pre_ptr(sp_, -16)); // push x0, x1

    mov_imm__(x0, reinterpret_cast<uint64_t>(outputPredReg), x1);

    for (int i = 0; i < NUM_PRED_REG; i++) {
      str__(Xbyak_aarch64::PReg(i), Xbyak_aarch64::ptr(x0, i));
    }

    ldp__(x0, x1, Xbyak_aarch64::post_ptr(sp_, 16)); // pop x0, x1
#else  //#ifdef DNNL_AARCH64_JIT_AARCH64
    push(r8);
    mov(r8, reinterpret_cast<uint64_t>(outputPredReg));

    for (int i = 0; i < NUM_PRED_REG; i++) {
      kmovq(ptr[r8], Opmask(i));
      add(r8, 8);
    }

    pop(r8);
#endif //#ifdef DNNL_AARCH64_JIT_AARCH64
  }

  void _genJitLoadZReg() {
#ifdef DNNL_AARCH64_JIT_AARCH64
    stp__(x0, x1, Xbyak_aarch64::pre_ptr(sp_, -16)); // push x0, x1

    mov_imm__(x0, reinterpret_cast<uint64_t>(inputZReg), x1);

    for (int i = 0; i < NUM_Z_REG; i++) {
      ldr__(Xbyak_aarch64::ZReg(i), Xbyak_aarch64::ptr(x0, i));
    }

    ldp__(x0, x1, Xbyak_aarch64::post_ptr(sp_, 16)); // pop x0, x1
#else  //#ifdef DNNL_AARCH64_JIT_AARCH64
    push(r8);
    mov(r8, reinterpret_cast<uint64_t>(inputZReg));

    for (int i = 0; i < NUM_Z_REG; i++) {
      vmovdqu64(Zmm(i), ptr[r8]);
      add(r8, 512 / 8);
    }

    pop(r8);
#endif //#ifdef DNNL_AARCH64_JIT_AARCH64
  }

  void _genJitStoreZReg() {
#ifdef DNNL_AARCH64_JIT_AARCH64
    stp__(x0, x1, Xbyak_aarch64::pre_ptr(sp_, -16)); // push x0, x1

    mov_imm__(x0, reinterpret_cast<uint64_t>(outputZReg), x1);

    for (int i = 0; i < NUM_Z_REG; i++) {
      str__(Xbyak_aarch64::ZReg(i), Xbyak_aarch64::ptr(x0, i));
    }

    ldp__(x0, x1, Xbyak_aarch64::post_ptr(sp_, 16)); // pop x0, x1
#else  //#ifdef DNNL_AARCH64_JIT_AARCH64
    push(r8);
    mov(r8, reinterpret_cast<uint64_t>(outputZReg));

    for (int i = 0; i < NUM_Z_REG; i++) {
      vmovdqu64(ptr[r8], Zmm(i));
      add(r8, 512 / 8);
    }

    pop(r8);
#endif //#ifdef DNNL_AARCH64_JIT_AARCH64
  }

  void _genJitLoadAllReg() {
    _genJitLoadGenReg();
    _genJitLoadPredReg();
    _genJitLoadZReg();
  }

  void _genJitStoreAllReg() {
    _genJitStoreGenReg();
    _genJitStorePredReg();
    _genJitStoreZReg();
  }

  void _genJitClearGenReg() {
#ifdef DNNL_AARCH64_JIT_AARCH64
    for (int i = 0; i < NUM_GEN_REG; i++) {
      if (i != SP_REG_IDX_AARCH64) {
        Xbyak_aarch64::XReg xreg(i);
        eor__(xreg, xreg, xreg);
      }
    }
#else
    for (int i = 0; i < NUM_GEN_REG; i++) {
      if (i != SP_REG_IDX_X86_64) {
        Reg64 reg(i);
        xor_(reg, reg);
      }
    }
#endif
  }

  void _genJitClearPredReg() {
#ifdef DNNL_AARCH64_JIT_AARCH64
    for (int i = 0; i < NUM_PRED_REG; i++) {
      Xbyak_aarch64::PReg preg(i);
      eor__(preg.b, preg / Xbyak_aarch64::T_z, preg.b, preg.b);
    }
#else
    for (int i = 0; i < NUM_GEN_REG; i++) {
      Reg64 reg(i);
      xor_(reg, reg);
    }
#endif
  }

  void _genJitClearZReg() {
#ifdef DNNL_AARCH64_JIT_AARCH64
    for (int i = 0; i < NUM_Z_REG; i++) {
      Xbyak_aarch64::ZRegD zreg(i);
      eor__(zreg, zreg, zreg);
    }
#else
    for (int i = 0; i < NUM_Z_REG; i++) {
      Zmm zreg(i);
      vxorpd(zreg, zreg);
    }
#endif
  }

  template <class T>
  void _dumpReg(std::string msg, std::string reg, int num, T *ptr) {
    int width = sizeof(T);

    for (int i = 0; i < num; i++) {
      std::ios::fmtflags flagsSaved = std::cout.flags();

      std::cout << std::left << std::setw(6) << msg << ":" << reg << "["
                << std::right << std::setw(2) << i << "]:" << std::hex;

      char fillSaved = std::cout.fill('0');
      std::cout << std::setw(width) << ((ptr[i] >> 32) & 0xFFFFFFFF) << "_"
                << std::setw(width) << ((ptr[i] >> 0) & 0xFFFFFFFF) << std::dec
                << std::endl;

      std::cout.flags(flagsSaved);
      std::cout.fill(fillSaved);
    }
  }

  void _dumpZReg(std::string msg, std::string reg, int num, ZReg_t *ptr) {
    const int width = 8;

    for (int i = 0; i < num; i++) {
      std::ios::fmtflags flagsSaved = std::cout.flags();

      std::cout << std::left << std::setw(6) << msg << ":" << reg << "["
                << std::right << std::setw(2) << i << "]:" << std::hex;

      char fillSaved = std::cout.fill('0');
      for (int j = 0; j < 8; j++) {
        std::cout << std::setw(width) << (((ptr[i].d_dt[j]) >> 32) & 0xFFFFFFFF)
                  << "_" << std::setw(width)
                  << (((ptr[i].d_dt[j]) >> 0) & 0xFFFFFFFF);
        if (j != 7) {
          std::cout << "_";
        }

        if (j % 2 && j != 7) {
          std::cout << "_";
        }
      }

      std::cout << std::dec << std::endl;

      std::cout.flags(flagsSaved);
      std::cout.fill(fillSaved);
    }
  }

  void _dumpInputGenReg() {
    _dumpReg(std::string("Input"), std::string("G"), NUM_GEN_REG, inputGenReg);
  }

  void _dumpOutputGenReg() {
    _dumpReg(std::string("Output"), std::string("G"), NUM_GEN_REG,
             outputGenReg);
  }

  void _dumpInputPredReg() {
    _dumpReg(std::string("Input"), std::string("P"), NUM_PRED_REG,
             inputPredReg);
  }

  void _dumpOutputPredReg() {
    _dumpReg(std::string("Output"), std::string("P"), NUM_PRED_REG,
             outputPredReg);
  }

  void _dumpInputZReg() {
    _dumpZReg(std::string("Input"), std::string("Z"), NUM_Z_REG, inputZReg);
  }

  void _dumpOutputZReg() {
    _dumpZReg(std::string("Output"), std::string("Z"), NUM_Z_REG, outputZReg);
  }

public:
  TestGenerator() {}

  void clearInputReg() {
    int i, j;

    // General purpose reg
    for (i = 0; i < NUM_GEN_REG; i++) {
      inputGenReg[i] = 0;
    }

    // Predicate reg
    for (i = 0; i < NUM_PRED_REG; i++) {
      inputPredReg[i] = 0;
    }

    // Z reg (Zmm and ZReg)
    for (i = 0; i < NUM_Z_REG; i++) {
      for (j = 0; j < 8; j++) {
        inputZReg[i].d_dt[j] = 0;
      }
    }
  }

  void clearArrayForOutputReg() {
    int i, j;

    // General purpose reg
    for (i = 0; i < NUM_GEN_REG; i++) {
      outputGenReg[i] = 0;
    }

    // Predicate reg
    for (i = 0; i < NUM_PRED_REG; i++) {
      outputPredReg[i] = 0;
    }

    // Z reg (Zmm and ZReg)
    for (i = 0; i < NUM_Z_REG; i++) {
      for (j = 0; j < 8; j++) {
        outputZReg[i].d_dt[j] = 0;
      }
    }
  }

  void clearInputData() {
    int i;

    // Test data input
    for (i = 0; i < NUM_INPUT_DATA; i++) {
      inputData[i] = 0;
    }
  }

  template <class T> void clearData(int num, T *ptr) {
    for (int i = 0; i < num; i++) {
      ptr[i] = 0;
    }
  }

  void clearDataForZReg(int num, ZReg_t *ptr) {
    for (int i = 0; i < num; i++) {
      for (int j = 0; j < 8; j++) {
        ptr[i].d_dt[j] = 0;
      }
    }
  }

  template <class T> void setData(int num, T *ptr) {
    for (int i = 0; i < num; i++) {
      ptr[i] = std::numeric_limits<T>::max();
    }
  }

  void setDataForZReg(int num, ZReg_t *ptr) {
    for (int i = 0; i < num; i++) {
      for (int j = 0; j < 8; j++) {
        ptr[i].d_dt[j] = std::numeric_limits<uint64_t>::max();
      }
    }
  }

  void clearInputDataForGenReg() {
#if 1
    clearData(NUM_GEN_REG, inputGenReg);
#else
    inputGenReg[0] = 0x0001020304050607;
    inputGenReg[1] = 0x08090a0b0c0d0e0f;
    inputGenReg[2] = 0x1011121314151617;
    inputGenReg[3] = 0x18191a1b1c1d1e1f;
    inputGenReg[4] = 0x2021222324252627;
    inputGenReg[5] = 0x28292a2b2c2d2e2f;
    inputGenReg[6] = 0x3031323334353637;
    inputGenReg[7] = 0x38393a3b3c3d3e3f;
    inputGenReg[8] = 0x4041424344454647;
    inputGenReg[9] = 0x48494a4b4c4d4e4f;
    inputGenReg[10] = 0x5051525354555657;
    inputGenReg[11] = 0x58595a5b5c5d5e5f;
    inputGenReg[12] = 0x6061626364656667;
    inputGenReg[13] = 0x68696a6b6c6d6e6f;
    inputGenReg[14] = 0x7071727374757677;
    inputGenReg[15] = 0x78797a7b7c7d7e7f;
#endif
  }

  void clearInputDataForPredReg() {
#if 1
    clearData(NUM_PRED_REG, inputPredReg);
#else
    inputPredReg[0] = 0x0001020304050607;
    inputPredReg[1] = 0x08090a0b0c0d0e0f;
    inputPredReg[2] = 0x1011121314151617;
    inputPredReg[3] = 0x18191a1b1c1d1e1f;
    inputPredReg[4] = 0x2021222324252627;
    inputPredReg[5] = 0x28292a2b2c2d2e2f;
    inputPredReg[6] = 0x3031323334353637;
    inputPredReg[7] = 0x38393a3b3c3d3e3f;
    inputPredReg[8] = 0x4041424344454647;
    inputPredReg[9] = 0x48494a4b4c4d4e4f;
    inputPredReg[10] = 0x5051525354555657;
    inputPredReg[11] = 0x58595a5b5c5d5e5f;
    inputPredReg[12] = 0x6061626364656667;
    inputPredReg[13] = 0x68696a6b6c6d6e6f;
    inputPredReg[14] = 0x7071727374757677;
    inputPredReg[15] = 0x78797a7b7c7d7e7f;
#endif
  }

  void clearInputDataForZReg() {
#if 0
    clearDataForZReg(NUM_Z_REG, inputZReg);
#else
    for (int i = 0; i < NUM_Z_REG; i++) {
      for (int j = 0; j < 32; j++) {
        inputZReg[i].h_dt[j] = i * 32 + j;
      }
    }
#endif
  }

  void clearOutputDataForGenReg() { clearData(NUM_GEN_REG, outputGenReg); }

  void clearOutputDataForPredReg() { clearData(NUM_PRED_REG, outputPredReg); }

  void clearOutputDataForZReg() { clearDataForZReg(NUM_Z_REG, outputZReg); }

  void clearExpectDataForGenReg() { clearData(NUM_GEN_REG, expectGenReg); }

  void clearExpectDataForPredReg() { clearData(NUM_PRED_REG, expectPredReg); }

  void clearExpectDataForZReg() { clearDataForZReg(NUM_Z_REG, expectZReg); }

  void setExpectDataForGenReg() { setData(NUM_GEN_REG, expectGenReg); }

  void setExpectDataForPredReg() { setData(NUM_PRED_REG, expectPredReg); }

  void setExpectDataForZReg() { setDataForZReg(NUM_Z_REG, expectZReg); }

  void clearInputDataAll() {
    clearInputDataForGenReg();
    clearInputDataForPredReg();
    clearInputDataForZReg();
  }

  void clearOutputDataAll() {
    clearOutputDataForGenReg();
    clearOutputDataForPredReg();
    clearOutputDataForZReg();
  }

  void setExpectDataAll() {
    setExpectDataForGenReg();
    setExpectDataForPredReg();
    setExpectDataForZReg();
  }

  void dumpInputReg() {
    _dumpInputGenReg();
    _dumpInputPredReg();
    _dumpInputZReg();
  }

  void dumpOutputReg() {
    _dumpOutputGenReg();
    _dumpOutputPredReg();
    _dumpOutputZReg();
  }

  template <class T>
  void _dumpExpectReg(std::string msg, std::string reg, int num, T *ptr,
                      T *expPtr) {

    int width = sizeof(T);
    std::ios::fmtflags flagsSaved = std::cout.flags();

    for (int i = 0; i < num; i++) {
      char fillSaved;

      std::cout << std::left << std::setw(6) << msg << ":" << reg << "["
                << std::oct << std::right << std::setw(2) << i
                << "]:" << std::hex;

      fillSaved = std::cout.fill('0');

      for (int j = 15; j >= 0; j--) {
        unsigned tmpExp = (expPtr[i] >> (4 * j)) & 0xF;
        unsigned tmpData = (ptr[i] >> (4 * j)) & 0xF;

        assert(tmpExp == 0xF || tmpExp == 0);

        if (tmpExp) {
          std::cout << tmpData;
        } else {
          std::cout << ".";
        }

        if (j == 8) {
          std::cout << "_";
        }
      }

      std::cout << std::endl;
      std::cout.fill(fillSaved);
    }

    std::cout.flags(flagsSaved);
  }

  void _dumpExpectZReg(std::string msg, std::string reg, int num, ZReg_t *ptr,
                       ZReg_t *expPtr) {
    const int width = 8;

    for (int i = 0; i < num; i++) {
      std::ios::fmtflags flagsSaved = std::cout.flags();

      std::cout << std::left << std::setw(6) << msg << ":" << reg << "["
                << std::right << std::setw(2) << i << "]:" << std::hex;

      char fillSaved = std::cout.fill('0');
      for (int j = 0; j < 8; j++) {
        for (int k = 15; k >= 0; k--) {
          unsigned tmpExp = (expPtr[i].d_dt[j] >> (4 * k)) & 0xF;
          unsigned tmpData = (ptr[i].d_dt[j] >> (4 * k)) & 0xF;

          assert(tmpExp == 0xF || tmpExp == 0);

          if (tmpExp) {
            std::cout << tmpData;
          } else {
            std::cout << ".";
          }

          if (k % 8 == 0 && !(j == 7 && k == 0)) {
            std::cout << "_";
          }
        }

        if (j != 7) {
          std::cout << "_";
        }
      }

      std::cout << std::dec << std::endl;

      std::cout.flags(flagsSaved);
      std::cout.fill(fillSaved);
    }
  }

  void _dumpExpectGenReg() {
    _dumpExpectReg(std::string("Expect"), std::string("G"), NUM_GEN_REG,
                   outputGenReg, expectGenReg);
  }

  void _dumpExpectPredReg() {
    _dumpExpectReg(std::string("Expect"), std::string("P"), NUM_PRED_REG,
                   outputPredReg, expectPredReg);
  }

  void _dumpExpectZReg() {
    _dumpExpectZReg(std::string("Expect"), std::string("Z"), NUM_Z_REG,
                    outputZReg, expectZReg);
  }

  void dumpExpectReg() {
    _dumpExpectGenReg();
    _dumpExpectPredReg();
    _dumpExpectZReg();
  }

  virtual void genJitTestCode() = 0; // Pure virtual function.

  void setExpectGenReg(Reg64 &reg) { expectGenReg[reg.getIdx()] |= 0xFFFFFFFF; }

  void setExpectPredReg(Opmask &reg) {
    expectGenReg[reg.getIdx()] |= 0xFFFFFFFF;
  }

  void setExpectZReg(Zmm &reg) {
    for (int i = 0; i < 8; i++) {
      expectZReg[reg.getIdx()].d_dt[i] |= 0xFFFFFFFF;
    }
  }

  void clearExpectGenReg(Reg64 &reg) { expectGenReg[reg.getIdx()] = 0; }

  void clearExpectPredReg(Opmask &reg) { expectGenReg[reg.getIdx()] = 0; }

  void clearExpectZReg(Zmm &reg) {
    for (int i = 0; i < 8; i++) {
      expectZReg[reg.getIdx()].d_dt[i] = 0;
    }
  }

  const xbyak_code_ptr_t *gen() {
    _genJitPreamble();

    _genJitLoadGenReg();  // Generate jit code to set initial value to gen
                          // registers.
    _genJitLoadPredReg(); // Generate jit code to set initial value to pred
                          // registers.
    _genJitLoadZReg(); // Generate jit code to set initial value to z registers.

    genJitTestCode();

    _genJitStoreGenReg();  // Generate jit code to dump last value to gen
                           // registers.
    _genJitStorePredReg(); // Generate jit code to dump last value to gen
                           // registers.
    _genJitStoreZReg();    // Generate jit code to dump last value to gen
    // registers.

    _genJitPostamble();

    ready();
    return getCode();
  }

  void dump() {
    FILE *fp = fopen("hoge", "w");

#ifdef DNNL_AARCH64_JIT_AARCH64
    fwrite(CodeArrayAArch64::top_, CodeArrayAArch64::size_, 4, fp);
#else
    fwrite(top_, size_, 1, fp);
#endif
    fclose(fp);
  }
};
