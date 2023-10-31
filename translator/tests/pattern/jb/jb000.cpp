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
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12,
       r13, r14, r15 */

    size_t addr;

    /* Address is aligned */
    addr = reinterpret_cast<size_t>(&(inputZReg[0].ud_dt[0]));
    std::cout << "Address is " << std::hex << addr << std::endl;

    mov(r15, std::numeric_limits<int64_t>::max());
    mov(r14, std::numeric_limits<int64_t>::min());
    xor_(r13, r13);
    mov(r12, std::numeric_limits<uint64_t>::max());
    mov(r11, std::numeric_limits<uint64_t>::min());

    std::vector<Reg64> regs = {r15, r14, r13, r12, r11};
    Label L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15,
        L16, L17, L18, L19, L20, L21, L22, L23, L24;

    std::vector<Label> label_vec = {L0,  L1,  L2,  L3,  L4,  L5,  L6,  L7,  L8,
                                    L9,  L10, L11, L12, L13, L14, L15, L16, L17,
                                    L18, L19, L20, L21, L22, L23, L24};

    int n = 0;
    for (const auto &j : regs) {
      for (const auto &i : regs) {
        cmp(j, i);
        jb(label_vec[n]);
        add(rax, 1);
        L(label_vec[n]);
#ifdef XBYAK_TRANSLATE_AARCH64
        xa_->lsl(x0, x0, 1);
#else //#ifdef XBYAK_TRANSLATE_AARCH64
        shl(rax, 1);
#endif //#ifdef XBYAK_TRANSLATE_AARCH64
        n++;
      }
    }
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
