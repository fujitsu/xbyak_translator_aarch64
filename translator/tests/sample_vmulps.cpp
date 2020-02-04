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
#include "test_generator.h"

const float testData[16] = {3.5, 4.6, 5.8, 100.0,
			    3.5, 4.6, 5.8, 100.0,
			    3.5, 4.6, 5.8, 100.0,
			    3.5, 4.6, 5.8, 100.0};

class TestPtnGenerator : public TestGenerator {
public:
  void genJitTestCode() {
    vmulps(Zmm(0), Zmm(1), Zmm(2));
  }
};


  
  
int main(int argc, char *argv[]) {
  TestPtnGenerator gen;
  gen.parseArgs(argc, argv);

  void (*f)();
  if (gen.isOutputJitOn()) {
    f = (void (*)())gen.gen(); // Generate JIT code
  }

  gen.dumpInputReg(); // Dump data for initializing registers.
  gen.dumpJitCode(); // Dump JIT code

  if (gen.isExecJitOn()) {
    f(); // Execute JIT code
    gen.dumpOutputReg(); // Dump register data.
    gen.dumpExpectReg(); // Dump register data for checking.
  }


  return 0;
}
