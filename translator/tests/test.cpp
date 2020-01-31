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

class TestPtnGenerator : public TestGenerator {
public:
  void genJitTestCode() {
    for(int i=0; i<31; i++) {
      vmulps(Zmm(i), Zmm((i+1)%32), Zmm((i+2)%32));
    }

    //vmulps(zmm0, zmm1, zmm2);
  }
};

int main() {
  TestPtnGenerator gen;

  gen.clearInputDataAll();  // Clear memory storing initial data for register.
  gen.clearOutputDataAll(); // Clear memory region for register data dump.
  gen.setExpectDataAll();

  void (*f)() = (void (*)())gen.gen();

  gen.dumpInputReg(); // Dump data for initializing registers.
  gen.dump();

  f();

  gen.dumpOutputReg(); // Dump register data.
  gen.dumpExpectReg(); // Dump register data for checking.

  return 0;
}
