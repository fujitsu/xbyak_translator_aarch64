SRC=add.cpp
OBJ=$(SRC:.cpp=.o)
EXE=$(SRC:.cpp=.exe)
all: $(EXE)

XED_DIR=../translator/third_party/build_xed_aarch64/kits/xed/

CFLAGS+=-std=c++11 -O2 -DNDEBUG -g -I ../xbyak -I ../translator/third_party/xbyak_aarch64/xbyak_aarch64/ -I ../translator/include/xbyak_translator_for_aarch64/ -I $(XED_DIR)/include/
LDFLAGS+=-L ../lib -lxbyak_translator_aarch64 -lxbyak_aarch64 -L $(XED_DIR)/lib/ -lxed

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CFLAGS)

%.exe: %.o
	$(CXX) $< -o $@ $(LDFLAGS)

test: add.exe
	env LD_LIBRARY_PATH=$(XED_DIR)/lib/ ./add.exe

clean:
	rm -rf $(EXE) $(OBJ)

.PHONY: clean

.SECONDARY: $(OBJ)
