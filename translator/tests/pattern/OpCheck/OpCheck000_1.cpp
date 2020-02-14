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
#include "test_generator_OpCheck000.h"
#include <sys/mman.h>

class TestPtnGenerator : public TestGenerator {
public:
  void setInitialRegValue() {
    /* Here modify arrays of inputGenReg, inputPredReg, inputZReg */
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    namespace xa = Xbyak_aarch64;

    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    //    size_t addr = reinterpret_cast<size_t>(&(inputZReg[31].ud_dt[4]));
    //    size_t addr = reinterpret_cast<size_t>(&(tmp[0]));
    //    std::cout << "Addr:" << std::hex << addr << std::endl;
    //    CodeGeneratorAArch64::mov_imm(x0, addr, X_TMP_0);
    //    CodeGeneratorAArch64::movs(p0.b, P_MSB_256/xa::T_z, P_MSB_256.b);
    //    CodeGeneratorAArch64::ldnf1d({xa::ZRegD(0)}, p0/xa::T_z, xa::ptr(x0));

    //    for(int i=0; i< 1000; i++) {
    //      CodeGeneratorAArch64::ldr({xa::ZReg(0)}, xa::ptr(x0));

    //    CodeGeneratorAArch64::sub(x0, x0, 8*4);
    CodeGeneratorAArch64::sub(x0, x0, 8 * 8);
#if 0
    CodeGeneratorAArch64::ldr({xa::ZReg(0)}, xa::ptr(x0));
#else
    CodeGeneratorAArch64::movs(p0.b, P_ALL_ONE / xa::T_z, P_MSB_256.b);
    //    CodeGeneratorAArch64::ldnf1d({xa::ZRegD(0)}, p0/xa::T_z, xa::ptr(x0));
    CodeGeneratorAArch64::stnt1d({xa::ZRegD(0)}, p0 / xa::T_z, xa::ptr(x0));
#endif

    //    CodeGeneratorAArch64::movs(p0.b, P_MSB_256/xa::T_z, P_MSB_256.b);
    //    CodeGeneratorAArch64::movs(p0.b, P_ALL_ONE/xa::T_z, P_MSB_256.b);
    //    CodeGeneratorAArch64::ldnf1d({xa::ZRegD(0)}, p0/xa::T_z, xa::ptr(x0));
    //      CodeGeneratorAArch64::add(x0, x0, 256);
    //    }
  }
};

int main(int argc, char *argv[]) {
  /* Initializing arrays of inputData, inputGenReg, inputPredReg, inputZReg,
   * checkGenRegMode, checkPredRegMode,checkZRegMode */
  TestPtnGenerator gen;
  size_t addr;

  /* Set bool output_jit_on_, bool exec_jit_on_ = 0; */
  gen.parseArgs(argc, argv);

  /* Generate JIT code and get function pointer */
  //  void (*f)(size_t);
  void (*f)();
  if (gen.isOutputJitOn()) {
    //    f = (void (*)(size_t))gen.gen();
    f = (void (*)())gen.gen();
    addr = reinterpret_cast<size_t>(f);
    std::cout << "func addr:" << std::hex << addr << std::endl;
  }

  /* Dump generated JIT code to a binary file */
  gen.dumpJitCode();

#if 1
  if (mprotect(reinterpret_cast<void *>(addr), 1024, PROT_EXEC | PROT_READ) !=
      0) {
    std::cout << "hoge" << std::endl;
    assert(NULL);
  }
#endif

  /* 1:Execute JIT code, 2:dump all register values, 3:dump register values to
   * be checked */
  if (gen.isExecJitOn()) {
    /* Before executing JIT code, dump inputData, inputGenReg, inputPredReg,
     * inputZReg. */
    gen.dumpInputReg();
    //    f(addr);                 /* Execute JIT code */
    f();                 /* Execute JIT code */
    gen.dumpOutputReg(); /* Dump all register values */
    gen.dumpCheckReg();  /* Dump register values to be checked */
  }

  return 0;
}
