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
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>

#include "xbyak.h"
#include "xbyak_util.h"

typedef uint8_t xbyak_code_ptr_t;

/** Rounding mode */
typedef enum {
  /** Round nearest */
  mkldnn_round_nearest = 1,
  /** Round down */
  mkldnn_round_down = 2,
} mkldnn_round_mode_t;

using namespace Xbyak;

union __attribute__((aligned(64))) ZReg_t {
  uint8_t ub_dt[64];
  uint16_t uh_dt[32];
  uint32_t us_dt[16];
  uint64_t ud_dt[8];
  int8_t sb_dt[64];
  int16_t sh_dt[32];
  int32_t ss_dt[16];
  int64_t sd_dt[8];
  float sp_dt[16];
  double dp_dt[8];
};

enum DataType {
  UB_DT, /* uint8_t */
  UH_DT, /* uint16_t */
  US_DT, /* uint32_t */
  UD_DT, /* uint64_t */
  SB_DT, /* int8_t */
  SH_DT, /* int16_t */
  SS_DT, /* int32_t */
  SD_DT, /* int64_t */
  SP_DT, /* float */
  DP_DT, /* double */
};

#ifdef XBYAK_TRANSLATE_AARCH64
constexpr Xbyak_aarch64::Operand::Code callee_saved_gregs[] = {
    Xbyak::Xbyak_aarch64::Operand::Code::X19,
    Xbyak::Xbyak_aarch64::Operand::Code::X20,
    Xbyak::Xbyak_aarch64::Operand::Code::X21,
    Xbyak::Xbyak_aarch64::Operand::Code::X22,
    Xbyak::Xbyak_aarch64::Operand::Code::X23,
    Xbyak::Xbyak_aarch64::Operand::Code::X24,
    Xbyak::Xbyak_aarch64::Operand::Code::X25,
    Xbyak::Xbyak_aarch64::Operand::Code::X26,
    Xbyak::Xbyak_aarch64::Operand::Code::X27,
    Xbyak::Xbyak_aarch64::Operand::Code::X28,
};
#else  //#ifdef XBYAK_TRANSLATE_AARCH64
constexpr Xbyak::Operand::Code callee_saved_gregs[] = {
    Xbyak::Operand::R12, Xbyak::Operand::R13, Xbyak::Operand::R14,
    Xbyak::Operand::R15, Xbyak::Operand::RBX, Xbyak::Operand::RBP,
};
#endif //#ifdef XBYAK_TRANSLATE_AARCH64

#if defined(MKLDNN_X86_64)
unsigned int mxcsr_save;
#else
#if defined(__CLANG_FUJITSU) || defined(__FUJITSU)
unsigned long fpcr_save;
#else
unsigned int fpcr_save;
#endif
#endif

#if defined(__CLANG_FUJITSU) || defined(__FUJITSU)
#define _FPU_GETCW(fpcr) __asm__ __volatile__("mrs    %0, fpcr" : "=r"(fpcr))

#define _FPU_SETCW(fpcr) __asm__ __volatile__("msr    fpcr, %0" : : "r"(fpcr))
#endif

void set_rnd_mode(mkldnn_round_mode_t rnd_mode) {
#if defined(MKLDNN_X86_64)
  mxcsr_save = _mm_getcsr();
  unsigned int mxcsr = mxcsr_save & ~(3u << 13);
  switch (rnd_mode) {
  case mkldnn_round_nearest:
    mxcsr |= (0u << 13);
    break;
  case mkldnn_round_down:
    mxcsr |= (1u << 13);
    break;
  default:
    assert(!"unreachable");
  }
  if (mxcsr != mxcsr_save)
    _mm_setcsr(mxcsr);
#elif defined(__ARM_ARCH)
#if defined(__CLANG_FUJITSU) || defined(__FUJITSU)
  /* for FCC */
  _FPU_GETCW(fpcr_save);
  unsigned long fpcr = fpcr_save & ~(static_cast<unsigned long>(3u) << 22);
#else  //#if defined(__CLANG_FUJITSU) || defined(__FUJITSU)
  /* GCC aarch64 */
  fpcr_save = __builtin_aarch64_get_fpcr();
  unsigned int fpcr = fpcr_save & ~(3u << 22);
#endif //#if defined(__CLANG_FUJITSU) || defined(__FUJITSU)
  switch (rnd_mode) {
  case mkldnn_round_nearest:
    fpcr |= (0u << 22);
    break;
  case mkldnn_round_down:
    fpcr |= (2u << 22);
    break;
  default:
    assert(!"unreachable");
  }
  if (fpcr != fpcr_save)
#if defined(__CLANG_FUJITSU) || defined(__FUJITSU)
    _FPU_SETCW(fpcr);
#else  //#if defined(__CLANG_FUJITSU) || defined(__FUJITSU)
    __builtin_aarch64_set_fpcr(fpcr);
#endif //#if defined(__CLANG_FUJITSU) || defined(__FUJITSU)
#else
  UNUSED_PARAM(rnd_mode);
#endif
}

void restore_rnd_mode() {
#if defined(MKLDNN_X86_64)
  _mm_setcsr(mxcsr_save);
#elif defined(__ARM_ARCH)
#if defined(__CLANG_FUJITSU) || defined(__FUJITSU)
  _FPU_SETCW(fpcr_save);
#else
  __builtin_aarch64_set_fpcr(fpcr_save);
#endif
#endif
}

class TestGenerator : public CodeGenerator {
private:
  bool output_jit_on_ = 0;
  bool exec_jit_on_ = 0;
  std::string binFileName;
  const std::string checkOK = "@@";
  const std::string checkNG = "!!";
  const std::string checkIgnore = "##";
  uint16_t lfsr_ = 0xACE1u;
  DataType dumpZRegMode_ = UD_DT;

  enum CheckMode {
    NO_CHECK,     // No comparison is needed
    CMP_INTEL,    // Compare to Intel's result
    CMP_INIT_VAL, // Compare to initial value
  };

  unsigned char outputData[NUM_INPUT_DATA];
  uint64_t outputGenReg[NUM_GEN_REG];
  uint64_t outputPredReg[NUM_PRED_REG];
  ZReg_t outputZReg[NUM_Z_REG];

  std::array<const uint64_t, 3> rsvdPredIdx = {{13, 14, 15}};
#ifdef XBYAK_TRANSLATE_AARCH64
  const size_t xreg_bytes = 8;
  const size_t vreg_bytes_to_be_preserved = 8;
  const size_t vreg_to_preserve_start = 8;
  const size_t num_vreg_to_preserve = 8; // VREG8 - VREG15
  const size_t num_callee_saved_gregs =
      sizeof(callee_saved_gregs) / sizeof(Xbyak_aarch64::Operand::Code);
  const size_t preserved_stack_size =
      xreg_bytes * (2 + num_callee_saved_gregs) +
      vreg_bytes_to_be_preserved * num_vreg_to_preserve;
#else
  const size_t num_callee_saved_gregs =
      sizeof(callee_saved_gregs) / sizeof(Xbyak::Operand);
#endif

  void _genJitPreamble() {
#ifdef XBYAK_TRANSLATE_AARCH64
    if (num_callee_saved_gregs % 2) {
      /* Even number is assumed. If it's odd number,
         STR instruction should be used, because STP instruction requires
         16-byte-aligned address. */
      msg_err(__FILE__, __LINE__, "Unimplemented");
    }

    /* sp address must be aligned by 16. */
    xa_->stp(
        x29, x30,
        Xbyak_aarch64::pre_ptr(xa_->sp,
                               -(static_cast<int64_t>(preserved_stack_size))));
    xa_->add(x29, xa_->sp, xreg_bytes * 2);
    if (num_vreg_to_preserve) {
      if (num_vreg_to_preserve != 8) {
        msg_err(__FILE__, __LINE__, "Unimplemented");
      }
      xa_->st4(
          (Xbyak_aarch64::VReg2D(vreg_to_preserve_start) -
           Xbyak_aarch64::VReg2D(vreg_to_preserve_start + 3))[0],
          Xbyak_aarch64::post_ptr(x29, vreg_bytes_to_be_preserved * 4));
      xa_->st4(
          (Xbyak_aarch64::VReg2D(vreg_to_preserve_start + 4) -
           Xbyak_aarch64::VReg2D(vreg_to_preserve_start + 7))[0],
          Xbyak_aarch64::post_ptr(x29, vreg_bytes_to_be_preserved * 4));
    }
    for (size_t i = 0; i < num_callee_saved_gregs; i += 2) {
      xa_->stp(Xbyak_aarch64::XReg(callee_saved_gregs[i]),
                                Xbyak_aarch64::XReg(callee_saved_gregs[i + 1]),
                                Xbyak_aarch64::post_ptr(x29, xreg_bytes * 2));
    }
#else
    for (size_t i = 0; i < num_callee_saved_gregs; i++) {
      push(Reg64(callee_saved_gregs[i]));
    }
#endif
  }

  void _genJitPostamble() {
#ifdef XBYAK_TRANSLATE_AARCH64
    if (num_callee_saved_gregs % 2) {
      /* Even number is assumed. If it's odd number,
         STR instruction should be used, because STP instruction requires
         16-byte-aligned address. */
      msg_err(__FILE__, __LINE__, "Unimplemented");
    }

    xa_->add(x29, xa_->sp, xreg_bytes * 2);

    if (num_vreg_to_preserve) {
      if (num_vreg_to_preserve != 8) {
        msg_err(__FILE__, __LINE__, "Unimplemented");
      }
      xa_->ld4(
          (Xbyak_aarch64::VReg2D(vreg_to_preserve_start) -
           Xbyak_aarch64::VReg2D(vreg_to_preserve_start + 3))[0],
          Xbyak_aarch64::post_ptr(x29, vreg_bytes_to_be_preserved * 4));
      xa_->ld4(
          (Xbyak_aarch64::VReg2D(vreg_to_preserve_start + 4) -
           Xbyak_aarch64::VReg2D(vreg_to_preserve_start + 7))[0],
          Xbyak_aarch64::post_ptr(x29, vreg_bytes_to_be_preserved * 4));
    }
    for (size_t i = 0; i < num_callee_saved_gregs; i += 2) {
      xa_->ldp(Xbyak_aarch64::XReg(callee_saved_gregs[i]),
                                Xbyak_aarch64::XReg(callee_saved_gregs[i + 1]),
                                Xbyak_aarch64::post_ptr(x29, xreg_bytes * 2));
    }

    xa_->ldp(
        x29, x30,
        Xbyak_aarch64::post_ptr(xa_->sp,
                                static_cast<int64_t>(preserved_stack_size)));
#else
    for (int i = num_callee_saved_gregs - 1; i >= 0; i--) {
      pop(Reg64(callee_saved_gregs[i]));
    }
#endif

#ifdef XBYAK_TRANSLATE_AARCH64
    xa_->ret();
#else
    ret();
#endif
  }

  /* Load data from memory to all general purpose registers,
     except x86_64's sp and aarch64 sp */
  void _genJitLoadGenReg() {
#ifdef XBYAK_TRANSLATE_AARCH64
    /* x0 contains memory address. */
    xa_->mov_imm(x0,
                                  reinterpret_cast<uint64_t>(inputGenReg) + 16);
    for (int i = 2; i < NUM_GEN_REG; i++) {
      if (i != SP_REG_IDX_AARCH64) { /* Avoid overwriting stack pointer */
        ldr(Xbyak_aarch64::XReg(i), Xbyak_aarch64::post_ptr(x0, 8));
      } else {
        xa_->add(
            x0, x8, 8); /* Incremente address for next register. */
      }
    }
    xa_->mov_imm(x0, reinterpret_cast<uint64_t>(inputGenReg));
    ldp(Xbyak_aarch64::XReg(0), Xbyak_aarch64::XReg(1), Xbyak_aarch64::ptr(x0));
#else  //#ifdef XBYAK_TRANSLATE_AARCH64
    mov(rax, reinterpret_cast<uint64_t>(inputGenReg) + 8);

    for (int i = 1; i < NUM_GEN_REG_INTEL; i++) {
      if (i != SP_REG_IDX_X86_64) { /* Avoid overwriting stack pointer */
        mov(Reg64(i), ptr[rax]);
      }
      add(rax, 8);
    }

    mov(rax, reinterpret_cast<uint64_t>(inputGenReg));
    mov(rax, ptr[rax]);
#endif //#ifdef XBYAK_TRANSLATE_AARCH64
  }

  /* Store data from all general purpose registers to memory,
     except x86_64's sp and aarch64 sp */
  void _genJitStoreGenReg() {
#ifdef XBYAK_TRANSLATE_AARCH64
    /* x0 contains memory address. */
    stp(x0, x1,
        Xbyak_aarch64::pre_ptr(xa_->sp,
                               -16)); // push data of x0 and x1

    xa_->mov_imm(x0, reinterpret_cast<uint64_t>(outputGenReg) +
                                          16);
    for (int i = 2; i < NUM_GEN_REG; i++) {
      if (i != SP_REG_IDX_AARCH64) {
        str(Xbyak_aarch64::XReg(i), Xbyak_aarch64::post_ptr(x0, 8));
      }
    }

    xa_->mov_imm(x0, reinterpret_cast<uint64_t>(outputGenReg));
    ldp(Xbyak_aarch64::XReg(2), Xbyak_aarch64::XReg(3),
        Xbyak_aarch64::post_ptr(xa_->sp,
                                16)); // pop data of x0, x1
    stp(x2, x3, Xbyak_aarch64::ptr(x0));
#else  //#ifdef XBYAK_TRANSLATE_AARCH64
    push(rax);
    mov(rax, reinterpret_cast<uint64_t>(outputGenReg) + 8);

    // r1 - r31
    for (int i = 1; i < NUM_GEN_REG_INTEL; i++) {
      mov(ptr[rax], Reg64(i));
      add(rax, 8);
    }

    // r8
    mov(rax, reinterpret_cast<uint64_t>(outputGenReg));
    pop(rbx);
    mov(ptr[rax], rbx);
#endif //#ifdef XBYAK_TRANSLATE_AARCH64
  }

  void _genJitLoadPredReg() {
#ifdef XBYAK_TRANSLATE_AARCH64
    stp(x0, x1,
        Xbyak_aarch64::pre_ptr(xa_->sp, -16)); // push x0, x1

    xa_->mov_imm(x0, reinterpret_cast<uint64_t>(inputPredReg));

    for (int i = 0; i < NUM_PRED_REG; i++) {
      ldr(Xbyak_aarch64::PReg(i), Xbyak_aarch64::ptr(x0, i));
    }

    ldp(x0, x1,
        Xbyak_aarch64::post_ptr(xa_->sp, 16)); // pop x0, x1
#else  //#ifdef XBYAK_TRANSLATE_AARCH64
    push(r8);
    mov(r8, reinterpret_cast<uint64_t>(inputPredReg));

    for (int i = 0; i < NUM_PRED_REG_INTEL; i++) {
      kmovq(Opmask(i), ptr[r8]);
      add(r8, 8);
    }

    pop(r8);
#endif //#ifdef XBYAK_TRANSLATE_AARCH64
  }

  void _genJitStorePredReg() {
#ifdef XBYAK_TRANSLATE_AARCH64
    stp(x0, x1,
        Xbyak_aarch64::pre_ptr(xa_->sp, -16)); // push x0, x1

    xa_->mov_imm(x0,
                                  reinterpret_cast<uint64_t>(outputPredReg));

    for (int i = 0; i < NUM_PRED_REG; i++) {
      str(Xbyak_aarch64::PReg(i), Xbyak_aarch64::ptr(x0, i));
    }

    ldp(x0, x1,
        Xbyak_aarch64::post_ptr(xa_->sp, 16)); // pop x0, x1
#else  //#ifdef XBYAK_TRANSLATE_AARCH64
    push(r8);
    mov(r8, reinterpret_cast<uint64_t>(outputPredReg));

    for (int i = 0; i < NUM_PRED_REG_INTEL; i++) {
      kmovq(ptr[r8], Opmask(i));
      add(r8, 8);
    }

    pop(r8);
#endif //#ifdef XBYAK_TRANSLATE_AARCH64
  }

  void _genJitLoadZReg() {
#ifdef XBYAK_TRANSLATE_AARCH64
    stp(x0, x1,
        Xbyak_aarch64::pre_ptr(xa_->sp, -16)); // push x0, x1

    xa_->mov_imm(x0, reinterpret_cast<uint64_t>(inputZReg));

    for (int i = 0; i < NUM_Z_REG; i++) {
      ldr(Xbyak_aarch64::ZReg(i), Xbyak_aarch64::ptr(x0, i));
    }

    ldp(x0, x1,
        Xbyak_aarch64::post_ptr(xa_->sp, 16)); // pop x0, x1
#else  //#ifdef XBYAK_TRANSLATE_AARCH64
    push(r8);
    mov(r8, reinterpret_cast<uint64_t>(inputZReg));

    for (int i = 0; i < NUM_Z_REG; i++) {
      vmovdqu64(Zmm(i), ptr[r8]);
      add(r8, 512 / 8);
    }

    pop(r8);
#endif //#ifdef XBYAK_TRANSLATE_AARCH64
  }

  void _genJitStoreZReg() {
#ifdef XBYAK_TRANSLATE_AARCH64
    stp(x0, x1,
        Xbyak_aarch64::pre_ptr(xa_->sp, -16)); // push x0, x1

    xa_->mov_imm(x0, reinterpret_cast<uint64_t>(outputZReg));

    for (int i = 0; i < NUM_Z_REG; i++) {
      str(Xbyak_aarch64::ZReg(i), Xbyak_aarch64::ptr(x0, i));
    }

    ldp(x0, x1,
        Xbyak_aarch64::post_ptr(xa_->sp, 16)); // pop x0, x1
#else  //#ifdef XBYAK_TRANSLATE_AARCH64
    push(r8);
    mov(r8, reinterpret_cast<uint64_t>(outputZReg));

    for (int i = 0; i < NUM_Z_REG; i++) {
      vmovdqu64(ptr[r8], Zmm(i));
      add(r8, 512 / 8);
    }

    pop(r8);
#endif //#ifdef XBYAK_TRANSLATE_AARCH64
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
#ifdef XBYAK_TRANSLATE_AARCH64
    for (int i = 0; i < NUM_GEN_REG; i++) {
      if (i != SP_REG_IDX_AARCH64) {
        Xbyak_aarch64::XReg xreg(i);
        eor(xreg, xreg, xreg);
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
#ifdef XBYAK_TRANSLATE_AARCH64
    for (int i = 0; i < NUM_PRED_REG; i++) {
      Xbyak_aarch64::PReg preg(i);
      eor(preg.b, preg / Xbyak_aarch64::T_z, preg.b, preg.b);
    }
#else
    for (int i = 0; i < NUM_GEN_REG; i++) {
      Reg64 reg(i);
      xor_(reg, reg);
    }
#endif
  }

  void _genJitClearZReg() {
#ifdef XBYAK_TRANSLATE_AARCH64
    for (int i = 0; i < NUM_Z_REG; i++) {
      Xbyak_aarch64::ZRegD zreg(i);
      eor(zreg, zreg, zreg);
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
      for (int j = (sizeof(ZReg_t) / sizeof(uint64_t)) - 1; j >= 0; j--) {
        std::cout << std::setw(width)
                  << (((ptr[i].ud_dt[j]) >> 32) & 0xFFFFFFFF) << "_"
                  << std::setw(width)
                  << (((ptr[i].ud_dt[j]) >> 0) & 0xFFFFFFFF);
        if (j != 0) {
          std::cout << "_";
        }

        if ((j % 2 == 0) && (j != 0)) {
          std::cout << "_";
        }
      }

      std::cout << std::dec << std::endl;

      std::cout.flags(flagsSaved);
      std::cout.fill(fillSaved);
    }
  }

  void _dumpZRegFloat(std::string msg, std::string reg, int num, ZReg_t *ptr) {
    for (int i = 0; i < num; i++) {
      for (int line = 0; line < 4; line++) {
        std::ios::fmtflags flagsSaved = std::cout.flags();

        std::cout << std::left << std::setw(6) << msg << ":" << reg << "["
                  << std::right << std::setw(2) << i << "][" << line << "]:";
        std::cout << std::scientific << std::showpos;

        char fillSaved = std::cout.fill('0');
        int dt_per_line = sizeof(ZReg_t) / sizeof(float) / 4;
        for (int j = dt_per_line - 1; j >= 0; j--) {
          std::cout << std::setw(13) << ptr[i].sp_dt[dt_per_line * line + j]
                    << "_";

          if ((j % 4 == 0) && (j != 0)) {
            std::cout << "_";
          }
        }

        std::cout << std::dec << std::endl;

        std::cout.flags(flagsSaved);
        std::cout.fill(fillSaved);
      }
    }

    std::cout << std::noshowpos;
  }

  void _dumpZRegDouble(std::string msg, std::string reg, int num, ZReg_t *ptr) {
    for (int i = 0; i < num; i++) {
      std::ios::fmtflags flagsSaved = std::cout.flags();

      std::cout << std::left << std::setw(6) << msg << ":" << reg << "["
                << std::right << std::setw(2) << i << "]:";
      std::cout << std::scientific << std::showpos;

      char fillSaved = std::cout.fill('0');
      for (int j = (sizeof(ZReg_t) / sizeof(float)) - 1; j >= 0; j--) {
        std::cout << ptr[i].dp_dt[j] << "_";

        if ((j % 4 == 0) && (j != 0)) {
          std::cout << "_";
        }
      }

      std::cout << std::dec << std::endl;

      std::cout.flags(flagsSaved);
      std::cout.fill(fillSaved);
    }

    std::cout << std::noshowpos;
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
    switch (dumpZRegMode_) {
    case UB_DT:
    case UH_DT:
    case US_DT:
    case UD_DT:
    case SB_DT:
    case SH_DT:
    case SS_DT:
    case SD_DT:
      _dumpZReg(std::string("Input"), std::string("Z"), NUM_Z_REG, inputZReg);
      break;
    case SP_DT:
      _dumpZRegFloat(std::string("Input"), std::string("Z"), NUM_Z_REG,
                     inputZReg);
      break;
    case DP_DT:
      _dumpZRegDouble(std::string("Input"), std::string("Z"), NUM_Z_REG,
                      inputZReg);
      break;
    default:
      msg_err(__FILE__, __LINE__,
              std::string(":Invalid dumpZRegMode=") +
                  std::to_string(dumpZRegMode_));
      break;
    }
  }

  void _dumpOutputZReg() {
    switch (dumpZRegMode_) {
    case UB_DT:
    case UH_DT:
    case US_DT:
    case UD_DT:
    case SB_DT:
    case SH_DT:
    case SS_DT:
    case SD_DT:
      _dumpZReg(std::string("Output"), std::string("Z"), NUM_Z_REG, outputZReg);
      break;
    case SP_DT:
      _dumpZRegFloat(std::string("Output"), std::string("Z"), NUM_Z_REG,
                     outputZReg);
      break;
    case DP_DT:
      _dumpZRegDouble(std::string("Output"), std::string("Z"), NUM_Z_REG,
                      outputZReg);
      break;
    default:
      msg_err(__FILE__, __LINE__,
              std::string(":Invalid dumpZRegMode=") +
                  std::to_string(dumpZRegMode_));
      break;
    }
  }

public:
  TestGenerator(void *code_ptr = nullptr, size_t code_size = 1024 * 64)
      : CodeGenerator(code_size, code_ptr) {
    clearInputDataAll();
    clearOutputDataAll();
    initExpectModeAll();

    initInputDataForPredReg(); /* Preset p13, p14, p15 to initial value of
                                  translator framework */
  }

  unsigned char inputData[NUM_INPUT_DATA];
  uint64_t inputGenReg[NUM_GEN_REG];
  uint64_t inputPredReg[NUM_PRED_REG];
  ZReg_t inputZReg[NUM_Z_REG];

  CheckMode checkGenRegMode[NUM_GEN_REG][NUM_BYTES_GEN_REG];
  CheckMode checkPredRegMode[NUM_PRED_REG][NUM_BYTES_PRED_REG];
  CheckMode checkZRegMode[NUM_Z_REG][NUM_BYTES_Z_REG];

  void setExpectData(CheckMode *ar, size_t row, size_t col, CheckMode mode) {
    for (size_t r = 0; r < row; r++) {
      for (size_t c = 0; c < col; c++) {
        ar[col * r + c] = mode;
      }
    }
  }

  void initExpectModeAll() {
    /* Basically, compare to x86_64's value */
    setExpectData(&(checkGenRegMode[0][0]), NUM_GEN_REG, NUM_BYTES_GEN_REG,
                  CMP_INTEL);
    setExpectData(&(checkPredRegMode[0][0]), NUM_PRED_REG, NUM_BYTES_PRED_REG,
                  CMP_INTEL);
    setExpectData(&(checkZRegMode[0][0]), NUM_Z_REG, NUM_BYTES_Z_REG,
                  CMP_INTEL);

    /* AArch64's Stack Pointer */
    for (size_t i = 0; i < NUM_BYTES_GEN_REG; i++) {
      checkGenRegMode[SP_REG_IDX_AARCH64][i] = CMP_INIT_VAL;
    }

    /* x86_64's Stack Pointer
       This register's value will not change,
       because this register is not used by x86_64's JIT code */
    for (size_t i = 0; i < NUM_BYTES_GEN_REG; i++) {
      checkGenRegMode[SP_REG_IDX_X86_64][i] = CMP_INIT_VAL;
    }

    /* x16 - x27: temporary use
       x28:translator frame use */
    for (int j = 16; j <= 28; j++) {
      for (size_t i = 0; i < NUM_BYTES_GEN_REG; i++) {
        checkGenRegMode[j][i] = NO_CHECK;
      }
    }

    /* x29, x30: no use */
    for (size_t i = 0; i < NUM_BYTES_GEN_REG; i++) {
      checkGenRegMode[29][i] = CMP_INIT_VAL;
      checkGenRegMode[30][i] = CMP_INIT_VAL;
    }

    /* p0: temporary use */
    for (size_t i = 0; i < NUM_BYTES_PRED_REG; i++) {
      checkPredRegMode[0][i] = NO_CHECK;
    }

    /* p8 - p12: temporary use */
    for (int j = 8; j <= 12; j++) {
      for (size_t i = 0; i < NUM_BYTES_PRED_REG; i++) {
        checkPredRegMode[j][i] = NO_CHECK;
      }
    }

    /* p13, p14, p15 is used by xbyak_translator frame work.
     so that these are basically not changed. */
    for (auto &e : rsvdPredIdx) {
      for (size_t i = 0; i < NUM_BYTES_PRED_REG; i++) {
        checkPredRegMode[e][i] = CMP_INIT_VAL;
      }
    }
  }

  bool isOutputJitOn() { return output_jit_on_; }

  bool isExecJitOn() { return exec_jit_on_; }

  void msg_warn(const char *fileName, const int lineNum,
                const std::string &msg) {
    msg_warn(fileName, lineNum, msg.c_str());
  }

  void msg_warn(const char *fileName, const int lineNum, const char *msg) {
    std::cerr << "[WARN]:" << fileName << ":" << lineNum << ":" << msg
              << std::endl;
  }

  void msg_err(const char *fileName, const int lineNum,
               const std::string &msg) {
    msg_err(fileName, lineNum, msg.c_str());
  }

  void msg_err(const char *fileName, const int lineNum, const char *msg) {
    std::cerr << "[ERR ]:" << fileName << ":" << lineNum << ":" << msg
              << std::endl;
    assert(NULL);
    exit(1);
  }

  void parseArgs(int argc, char *argv[]) {
    switch (argc) {
    case 3:
      output_jit_on_ = std::stoi(argv[1]);
      exec_jit_on_ = std::stoi(argv[2]);
      break;
    case 2:
      msg_warn(__FILE__, __LINE__, "Invalid # of args=" + std::to_string(argc));
      output_jit_on_ = std::stoi(argv[1]);
      exec_jit_on_ = 1;
      break;
    case 1:
      msg_warn(__FILE__, __LINE__, "Invalid # of args=" + std::to_string(argc));
      output_jit_on_ = 1;
      exec_jit_on_ = 1;
      break;
    default:
      msg_warn(__FILE__, __LINE__, "Invalid # of args=" + std::to_string(argc));
      output_jit_on_ = 1;
      exec_jit_on_ = 1;
      break;
    }

    binFileName = argv[0];
    binFileName += ".bin";
  }

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
        inputZReg[i].ud_dt[j] = 0;
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
        outputZReg[i].ud_dt[j] = 0;
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

  void clearDataForZReg(int num, ZReg_t *ptr) {
    for (int i = 0; i < num; i++) {
      for (int j = 0; j < 8; j++) {
        ptr[i].ud_dt[j] = 0;
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
        ptr[i].ud_dt[j] = std::numeric_limits<uint64_t>::max();
      }
    }
  }

  void initInputDataForPredReg() {
    for (int i = 0; i < 13; i++) {
      inputPredReg[i] = 0;
    }

    inputPredReg[10] = 0;
    inputPredReg[13] = ~uint64_t(0xFFFFFFFF);
    inputPredReg[14] = ~uint64_t(0xFFFF);
    inputPredReg[15] = ~uint64_t(0);
  }

  template <class T> void clearData(T &ar) { memset(ar, 0, sizeof(ar)); }

  void clearInputDataAll() {
    clearData(inputGenReg);
    clearData(inputPredReg);
    clearData(inputZReg);
  }

  void clearOutputDataAll() {
    clearData(outputGenReg);
    clearData(outputPredReg);
    clearData(outputZReg);
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

  void _dumpCheckRegCore(uint64_t dut, uint64_t initData, CheckMode *checkMode,
                         bool isLast = false) {

    for (int c = sizeof(uint64_t) - 1; c >= 0; c--) {
      const uint64_t dut_mskd_shftd = (dut >> (8 * c)) & 0xFF;
      CheckMode mode = checkMode[c];

      if (mode == CMP_INTEL) { /* Compare to x86_64's result */
        std::cout << std::hex << std::setw(2) << dut_mskd_shftd;
      } else if (mode == CMP_INIT_VAL) { /* Compare to own initial value */
#ifdef XBYAK_TRANSLATE_AARCH64
        const uint64_t init_mskd_shftd = (initData >> (8 * c)) & 0xFF;
        if (dut_mskd_shftd == init_mskd_shftd) {
          std::cout << checkOK;
        } else {
          std::cout << checkNG;
        }
#else                                //#ifdef XBYAK_TRANSLATE_AARCH64
        std::cout << checkOK;
#endif                               //#ifdef XBYAK_TRANSLATE_AARCH64
      } else if (mode == NO_CHECK) { /* No need to compare */
        std::cout << checkIgnore;
      } else { /* Something wrong */
        msg_err(__FILE__, __LINE__,
                std::string(":Invalid CheckMode=") + std::to_string(mode));
      }

      /* Every 32 bits, except last */
      if (c % 4 == 0 && c != 0) {
        std::cout << "_";
      }
    }

    if (isLast) {
      std::cout << "_";
    }
  }

  void _dumpCheckRegOK(size_t num) {
    for (unsigned int i = 0; i < num; i++) {
      std::cout << checkOK;

      /* Every 32 bits, except last */
      if ((i + 1) % 4 == 0 && i + 1 != num) {
        std::cout << "_";
      }

      /* Every128 bits, except last */
      if ((i + 1) % 16 == 0 && i + 1 != num) {
        std::cout << "_";
      }
    }

    std::cout << std::endl;
  }

  template <class T>
  void _dumpCheckReg(std::string msg, std::string reg, const int row,
                     const int row_intel, const int col, T *output,
                     CheckMode *expPtr, T *input) {
    std::ios::fmtflags flagsSaved = std::cout.flags();

    /* It is assumed AArch64 has greater or equal num of registers. */
    if (row < row_intel) {
      msg_err(__FILE__, __LINE__, "Unimplemented");
    }
    /* It is assumed register size is aligned by 8 bytes. */
    if (sizeof(T) % sizeof(uint64_t)) {
      msg_err(__FILE__, __LINE__, "Unimplemented");
    }

    for (int r = 0; r < row; r++) {
      std::cout << std::dec << std::setw(6) << std::left << msg << ":" << reg
                << "[" << std::right << std::setw(2) << r << "]:";

      char fillSaved = std::cout.fill('0');

      if (sizeof(T) % sizeof(uint64_t)) {
        msg_err(__FILE__, __LINE__, "Unsupported data size");
      }

      const size_t num64 = sizeof(T) / sizeof(uint64_t);
      for (int sub_r = num64 - 1; sub_r >= 0; sub_r--) {
        uint64_t dut;
        uint64_t initData;
        uint64_t *addrOut = reinterpret_cast<uint64_t *>(&(output[r]));
        uint64_t *addrIn = reinterpret_cast<uint64_t *>(&(input[r]));
        std::memcpy(&dut, addrOut + sub_r, sizeof(uint64_t));
        std::memcpy(&initData, addrIn + sub_r, sizeof(uint64_t));

        _dumpCheckRegCore(dut, initData,
                          expPtr + sizeof(T) * r + sizeof(uint64_t) * sub_r,
                          sub_r != 0);

        if ((sub_r % 2 == 0) && (sub_r != 0)) {
          std::cout << "_";
        }
      }

      std::cout << std::endl;
      std::cout.fill(fillSaved);
    } //    for (int r = 0; r < row; r++) {

    std::cout.flags(flagsSaved);
  }

  void _dumpCheckGenReg() {
    _dumpCheckReg(std::string("Check "), std::string("G"), NUM_GEN_REG,
                  NUM_GEN_REG_INTEL, NUM_BYTES_GEN_REG, &(outputGenReg[0]),
                  &(checkGenRegMode[0][0]), &(inputGenReg[0]));
  }

  void _dumpCheckPredReg() {
    _dumpCheckReg(std::string("Check "), std::string("P"), NUM_PRED_REG,
                  NUM_PRED_REG_INTEL, NUM_BYTES_PRED_REG, &(outputPredReg[0]),
                  &(checkPredRegMode[0][0]), &(inputPredReg[0]));
  }

  void _dumpCheckZReg() {
    _dumpCheckReg(std::string("Check "), std::string("Z"), NUM_Z_REG,
                  NUM_Z_REG_INTEL, NUM_BYTES_Z_REG, &(outputZReg[0]),
                  &(checkZRegMode[0][0]), &(inputZReg[0]));
  }

  void dumpCheckReg() {
    _dumpCheckGenReg();
    _dumpCheckPredReg();
    _dumpCheckZReg();
  }

  void setInputZregRandomHex(int idx) {
    for (int i = 0; i < NUM_BYTES_Z_REG / 2; i++) {
      inputZReg[idx].uh_dt[i] = getLfsr();
    }
  }

  void setInputZregAllRandomHex() {
    for (int i = 0; i < NUM_Z_REG; i++) {
      setInputZregRandomHex(i);
    }
  }

  void setInputZregRandomFloat(int idx) {

    for (unsigned int i = 0; i < NUM_BYTES_Z_REG / sizeof(float); i++) {
      do {
        inputZReg[idx].uh_dt[i * 2 + 0] = getLfsr();
        inputZReg[idx].uh_dt[i * 2 + 1] = getLfsr();
        //	std::cout << "[" << idx << "]" << inputZReg[idx].sp_dt[i] <<
        // std::endl;
      } while (std::isinf(inputZReg[idx].sp_dt[i]) ||
               std::isnan(inputZReg[idx].sp_dt[i]));
    }
  }

  void setInputZregRandomDouble(int idx) {
    for (unsigned int i = 0; i < NUM_BYTES_Z_REG / sizeof(double); i++) {
      do {
        inputZReg[idx].uh_dt[i * 2 + 0] = getLfsr();
        inputZReg[idx].uh_dt[i * 2 + 1] = getLfsr();
        //	std::cout << "[" << idx << "]" << inputZReg[idx].sp_dt[i] <<
        // std::endl;
      } while (std::isinf(inputZReg[idx].sp_dt[i]) ||
               std::isnan(inputZReg[idx].sp_dt[i]));
    }
  }

  void setInputZregAllRandomFloat() {
    for (int i = 0; i < NUM_Z_REG; i++) {
      setInputZregRandomFloat(i);
    }
  }

  void setInputZregAllRandomDouble() {
    for (int i = 0; i < NUM_Z_REG; i++) {
      setInputZregRandomDouble(i);
    }
  }

  void setDumpZRegMode(DataType dt) { dumpZRegMode_ = dt; }

  DataType getDumpZRegMode() { return dumpZRegMode_; }

  uint16_t getLfsr() {
    lfsr_ = (lfsr_ >> 1) ^ (-(int16_t)(lfsr_ & 1u) & 0xB400u);

    return lfsr_;
  }

  void modifyPredRegAArch64(DataType dataType) {
    int elem_num = 0;
    int offset = 0;

    switch (dataType) {
    case UB_DT: /* uint8_t */
    case SB_DT: /* int8_t */
      elem_num = 64;
      offset = 1;
      break;
    case UH_DT: /* uint16_t */
    case SH_DT: /* int16_t */
      elem_num = 32;
      offset = 2;
      break;
    case US_DT: /* uint32_t */
    case SS_DT: /* int32_t */
    case SP_DT: /* float */
      elem_num = 16;
      offset = 4;
      break;
    case UD_DT: /* uint64_t */
    case SD_DT: /* int64_t */
    case DP_DT: /* double */
      elem_num = 8;
      offset = 8;
      break;
    default:
      msg_err(__FILE__, __LINE__, ":Unknown data type!");
      break;
    }

    for (int j = 1; j <= 7; j++) {
      uint64_t tmpPredData = 0;
      for (int i = 0; i < elem_num; i++) {
        uint64_t checkMask = uint64_t(1) << (offset * i);
        uint64_t addMask = uint64_t(1) << (offset * i);

        if (outputPredReg[j] & checkMask) {
          tmpPredData |= addMask;
        }
      }
      outputPredReg[j] = tmpPredData;
    }
  }

  void modifyPredReg(DataType dataType) {
    int elem_num = 0;
    int offset = 0;

    switch (dataType) {
    case UB_DT: /* uint8_t */
    case SB_DT: /* int8_t */
      elem_num = 64;
      offset = 1;
      break;
    case UH_DT: /* uint16_t */
    case SH_DT: /* int16_t */
      elem_num = 32;
      offset = 2;
      break;
    case US_DT: /* uint32_t */
    case SS_DT: /* int32_t */
    case SP_DT: /* float */
      elem_num = 16;
      offset = 4;
      break;
    case UD_DT: /* uint64_t */
    case SD_DT: /* int64_t */
    case DP_DT: /* double */
      elem_num = 8;
      offset = 8;
      break;
    default:
      msg_err(__FILE__, __LINE__, ":Unknown data type!");
      break;
    }

    for (int j = 1; j <= 7; j++) {
      uint64_t tmpPredData = 0;
      for (int i = 0; i < elem_num; i++) {
        uint64_t checkMask = uint64_t(1) << i;
        uint64_t addMask = uint64_t(1) << (offset * i);

        if (outputPredReg[j] & checkMask) {
          tmpPredData |= addMask;
        }
      }
      outputPredReg[j] = tmpPredData;
    }
  }

  virtual void genJitTestCode() = 0;     // Pure virtual function.
  virtual void setInitialRegValue() = 0; // Pure virtual function.
  virtual void setCheckRegFlagAll() = 0; // Pure virtual function.

  const xbyak_code_ptr_t *gen() {
    setInitialRegValue();
    setCheckRegFlagAll();

    /* Save values of callee saved registers */
    _genJitPreamble();

    /* Generate jit code to set initial value to GenReg, PredReg, ZReg,
       except x86_64's sp and aarch64 sp */
    _genJitLoadAllReg();

    /* Generate JIT code to be tested. */
    genJitTestCode();

    /* Generate jit code to store GenReg, PredReg, ZReg values to memory */
    _genJitStoreAllReg();

    /* Recover values of callee saved registers */
    _genJitPostamble();

    ready();
    return getCode();
  }

  void dumpJitCode() {
    FILE *fp = fopen(binFileName.c_str(), "w");

#ifdef XBYAK_TRANSLATE_AARCH64
    fwrite(CodeArrayAArch64::top_, CodeArrayAArch64::size_, 4, fp);
#else
    fwrite(CodeArray::top_, CodeArray::size_, 1, fp);
#endif
    fclose(fp);
  }
};
