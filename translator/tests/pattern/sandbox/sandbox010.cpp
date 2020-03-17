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
#include <typeinfo>
#include "test_generator2.h"
#define CG64 CodeGeneratorAArch64
//#define CG64 Xbyak_aarch64

class TestPtnGenerator : public TestGenerator {
public:
  void setInitialRegValue() {
    /* Here modify arrays of inputGenReg, inputPredReg, inputZReg */
    setInputZregAllRandomHex();
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    std::cout << "hoge:" << typeid((CG64::z0, CG64::z3)).name() << std::endl;
    
    //    CG64::ld4((CG64::v0, CG64::v3).s4, Xbyak_aarch64::ptr(CG64::x8));
    //    CG64::ld4w((CG64::z0, CG64::z3, CG64::z5).s, CG64::p0, Xbyak_aarch64::ptr(CG64::x8));
    CG64::ld4((CG64::z0.b - CG64::z3.b), CG64::p0, Xbyak_aarch64::ptr(CG64::x8));


    //    CG64::ld4w((CG64::z0.s - CG64::z3.s), CG64::p0, Xbyak_aarch64::ptr(CG64::x8));
    //    CG64::ld4w((CG64::z0 - CG64::z3).s, CG64::p0, Xbyak_aarch64::ptr(CG64::x8));
    //    CG64::ld4w(CG64::z0.s, CG64::p0, Xbyak_aarch64::ptr(CG64::x8));
    //    CG64::ld4w((CG64::z0.s , CG64::z3.s), CG64::p0, Xbyak_aarch64::ptr(CG64::x8));
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
