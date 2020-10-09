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
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>

#include "xbyak.h"
#include "xbyak_util.h"

typedef uint8_t xbyak_code_ptr_t;

#define NUM_INPUT_DATA 16
/* x86_64 has 16 gen registers. AArch64 has 32 gen registers. */
#define NUM_GEN_REG 32
#define NUM_GEN_REG_INTEL 16
/* x86_64 has 8 predicate registers. AArch64 has 16 predicate registers. */
#define NUM_PRED_REG 16
#define NUM_PRED_REG_INTEL 8
#define NUM_Z_REG 32
#define NUM_Z_REG_INTEL 32

#define SP_REG_IDX_X86_64 4
#define SP_REG_IDX_AARCH64 31
#define NUM_BYTES_GEN_REG 8
#define NUM_BYTES_PRED_REG 8
#define NUM_BYTES_Z_REG 64

using namespace Xbyak;

union ZReg_t {
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

#ifdef XBYAK_TRANSLATE_AARCH64
constexpr Xbyak_aarch64::Operand::Code callee_saved_gregs[] = {
    Xbyak_aarch64::Operand::Code::X19, Xbyak_aarch64::Operand::Code::X20,
    Xbyak_aarch64::Operand::Code::X21, Xbyak_aarch64::Operand::Code::X22,
    Xbyak_aarch64::Operand::Code::X23, Xbyak_aarch64::Operand::Code::X24,
    Xbyak_aarch64::Operand::Code::X25, Xbyak_aarch64::Operand::Code::X26,
    Xbyak_aarch64::Operand::Code::X27, Xbyak_aarch64::Operand::Code::X28,
};
#else  //#ifdef XBYAK_TRANSLATE_AARCH64
constexpr Xbyak::Operand::Code callee_saved_gregs[] = {
    Xbyak::Operand::R12, Xbyak::Operand::R13, Xbyak::Operand::R14,
    Xbyak::Operand::R15, Xbyak::Operand::RBX, Xbyak::Operand::RBP,
};
#endif //#ifdef XBYAK_TRANSLATE_AARCH64

class TestGenerator : public CodeGenerator {
private:
  bool output_jit_on_ = 0;
  bool exec_jit_on_ = 0;
  const std::string checkOK = "@@";
  const std::string checkNG = "!!";
  const std::string checkIgnore = "##";

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
    xa_->stp(x29, x30,
             Xbyak_aarch64::pre_ptr(
                 xa_->sp, -(static_cast<int64_t>(preserved_stack_size))));
    xa_->add(x29, xa_->sp, xreg_bytes * 2);
    if (num_vreg_to_preserve) {
      if (num_vreg_to_preserve != 8) {
        msg_err(__FILE__, __LINE__, "Unimplemented");
      }
      xa_->st4((Xbyak_aarch64::VReg2D(vreg_to_preserve_start) -
                Xbyak_aarch64::VReg2D(vreg_to_preserve_start + 3))[0],
               Xbyak_aarch64::post_ptr(x29, vreg_bytes_to_be_preserved * 4));
      xa_->st4((Xbyak_aarch64::VReg2D(vreg_to_preserve_start + 4) -
                Xbyak_aarch64::VReg2D(vreg_to_preserve_start + 7))[0],
               Xbyak_aarch64::post_ptr(x29, vreg_bytes_to_be_preserved * 4));
    }
    for (size_t i = 0; i < num_callee_saved_gregs; i += 2) {
      xa_->stp(Xbyak_aarch64::XReg(callee_saved_gregs[i]),
               Xbyak_aarch64::XReg(callee_saved_gregs[i + 1]),
               Xbyak_aarch64::post_ptr(x29, xreg_bytes * 2));
    }
#else
    for (int i = 0; i < num_callee_saved_gregs; i++) {
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
      xa_->ld4((Xbyak_aarch64::VReg2D(vreg_to_preserve_start) -
                Xbyak_aarch64::VReg2D(vreg_to_preserve_start + 3))[0],
               Xbyak_aarch64::post_ptr(x29, vreg_bytes_to_be_preserved * 4));
      xa_->ld4((Xbyak_aarch64::VReg2D(vreg_to_preserve_start + 4) -
                Xbyak_aarch64::VReg2D(vreg_to_preserve_start + 7))[0],
               Xbyak_aarch64::post_ptr(x29, vreg_bytes_to_be_preserved * 4));
    }
    for (size_t i = 0; i < num_callee_saved_gregs; i += 2) {
      xa_->ldp(Xbyak_aarch64::XReg(callee_saved_gregs[i]),
               Xbyak_aarch64::XReg(callee_saved_gregs[i + 1]),
               Xbyak_aarch64::post_ptr(x29, xreg_bytes * 2));
    }

    xa_->ldp(x29, x30,
             Xbyak_aarch64::post_ptr(
                 xa_->sp, static_cast<int64_t>(preserved_stack_size)));
#else
    for (int i = num_callee_saved_gregs - 1; i >= 0; i--) {
      pop(Reg64(callee_saved_gregs[i]));
    }
#endif
    ret();
  }

  /* Load data from memory to all general purpose registers,
     except x86_64's sp and aarch64 sp */
  void _genJitLoadGenReg() {
#ifdef XBYAK_TRANSLATE_AARCH64
    /* x0 contains memory address. */
    xa_->mov_imm(x0, reinterpret_cast<uint64_t>(inputGenReg) + 16);
    for (int i = 2; i < NUM_GEN_REG; i++) {
      if (i != SP_REG_IDX_AARCH64) { /* Avoid overwriting stack pointer */
        ldr(Xbyak_aarch64::XReg(i), Xbyak_aarch64::post_ptr(x0, 8));
      } else {
        xa_->add(x0, x8, 8); /* Incremente address for next register. */
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
    stp(x0, x1, Xbyak_aarch64::pre_ptr(xa_->sp,
                                       -16)); // push data of x0 and x1

    xa_->mov_imm(x0, reinterpret_cast<uint64_t>(outputGenReg) + 16);
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
    stp(x0, x1, Xbyak_aarch64::pre_ptr(xa_->sp, -16)); // push x0, x1

    xa_->mov_imm(x0, reinterpret_cast<uint64_t>(inputPredReg));

    for (int i = 0; i < NUM_PRED_REG; i++) {
      ldr(Xbyak_aarch64::PReg(i), Xbyak_aarch64::ptr(x0, i));
    }

    ldp(x0, x1, Xbyak_aarch64::post_ptr(xa_->sp, 16)); // pop x0, x1
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
    stp(x0, x1, Xbyak_aarch64::pre_ptr(xa_->sp, -16)); // push x0, x1

    xa_->mov_imm(x0, reinterpret_cast<uint64_t>(outputPredReg));

    for (int i = 0; i < NUM_PRED_REG; i++) {
      str(Xbyak_aarch64::PReg(i), Xbyak_aarch64::ptr(x0, i));
    }

    ldp(x0, x1, Xbyak_aarch64::post_ptr(xa_->sp, 16)); // pop x0, x1
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
    stp(x0, x1, Xbyak_aarch64::pre_ptr(xa_->sp, -16)); // push x0, x1

    xa_->mov_imm(x0, reinterpret_cast<uint64_t>(inputZReg));

    for (int i = 0; i < NUM_Z_REG; i++) {
      ldr(Xbyak_aarch64::ZReg(i), Xbyak_aarch64::ptr(x0, i));
    }

    ldp(x0, x1, Xbyak_aarch64::post_ptr(xa_->sp, 16)); // pop x0, x1
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
    stp(x0, x1, Xbyak_aarch64::pre_ptr(xa_->sp, -16)); // push x0, x1

    xa_->mov_imm(x0, reinterpret_cast<uint64_t>(outputZReg));

    for (int i = 0; i < NUM_Z_REG; i++) {
      str(Xbyak_aarch64::ZReg(i), Xbyak_aarch64::ptr(x0, i));
    }

    ldp(x0, x1, Xbyak_aarch64::post_ptr(xa_->sp, 16)); // pop x0, x1
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
  TestGenerator() {
    clearInputDataAll();
    clearOutputDataAll();
    initExpectModeAll();
  }

  enum DataType {
    B_DT,
    H_DT,
    S_DT,
    D_DT,
    SP_DT,
    DP_DT,
  };

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
    for (int j = 16; j <= 27; j++) {
      for (size_t i = 0; i < NUM_BYTES_GEN_REG; i++) {
        checkGenRegMode[j][i] = NO_CHECK;
      }
    }

    /* x29, x30: no use */
    for (size_t i = 0; i < NUM_BYTES_GEN_REG; i++) {
      checkGenRegMode[29][i] = CMP_INIT_VAL;
      checkGenRegMode[30][i] = CMP_INIT_VAL;
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

  void clearInputDataForGenReg() {
#if 1
    clearData(inputGenReg);
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
    //    clearData(NUM_PRED_REG, inputPredReg);
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

  template <class T> void clearData(T &ar) { memset(ar, 0, sizeof(ar)); }

  //  void clearExpectDataForGenReg() { clearExpectData(checkGenRegMode); }

  //  void clearExpectDataForPredReg() { clearData(NUM_PRED_REG,
  //  checkPredRegMode);
  //  }

  //  void clearExpectDataForZReg() { clearDataForZReg(NUM_Z_REG,
  //  checkZRegMode); }

  //  void setExpectDataForGenReg() { setData(NUM_GEN_REG, checkGenRegMode); }

  //  void setExpectDataForPredReg() { setData(NUM_PRED_REG, checkPredRegMode);
  //  }

  //  void setExpectDataForZReg() { setDataForZReg(NUM_Z_REG, checkZRegMode); }

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
      const uint64_t init_mskd_shftd = (initData >> (8 * c)) & 0xFF;
      CheckMode mode = checkMode[c];

      if (mode == CMP_INTEL) { /* Compare to x86_64's result */
        std::cout << std::hex << std::setw(2) << dut_mskd_shftd;
      } else if (mode == CMP_INIT_VAL) { /* Compare to own initial value */
#ifdef XBYAK_TRANSLATE_AARCH64
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
    for (int i = 0; i < num; i++) {
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

#if 0
#ifndef XBYAK_TRANSLATE_AARCH64
      if (r >= row_intel) {
	_dumpCheckRegOK(sizeof(T));
	std::cout.fill(fillSaved);
        continue;
      }
#endif //#ifndef XBYAK_TRANSLATE_AARCH64
#endif

      const size_t num64 = sizeof(T) / sizeof(uint64_t);
      for (int sub_r = num64 - 1; sub_r >= 0; sub_r--) {
        uint64_t dut;
        uint64_t initData;
        void *addrOut = &(output[r]);
        void *addrIn = &(input[r]);
        void *addrExp = &(expPtr[r]);
        std::memcpy(&dut, addrOut + sizeof(uint64_t) * sub_r, sizeof(uint64_t));
        std::memcpy(&initData, addrIn + sizeof(uint64_t) * sub_r,
                    sizeof(uint64_t));

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
    FILE *fp = fopen("hoge", "w");

    fwrite(CodeArray::top_, getSize(), 1, fp);
    fclose(fp);
  }
};
