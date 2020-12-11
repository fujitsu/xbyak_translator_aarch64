SRC=add.cpp
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)
EXE=$(SRC:.cpp=.exe)
all: $(EXE)

XED_DIR=../translator/third_party/build_xed_aarch64/kits/xed/

CFLAGS+=-std=c++11 -DNDEBUG -g -I ../translator/third_party/xbyak_aarch64/ -I ../translator/include/ -I $(XED_DIR)/include/
ifneq ($(DEBUG),1)
CFLAGS+=-O2
endif
LDFLAGS+=-L ../lib -lxbyak_translator_aarch64 -lxbyak_aarch64 -L $(XED_DIR)/lib/ -lxed

-include $(DEP)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CFLAGS) -MMD -MP -MF $(@:.o=.d)

%.exe: %.o
	$(CXX) $< -o $@ $(LDFLAGS)

test: add.exe
	env LD_LIBRARY_PATH=$(XED_DIR)/lib/ ./add.exe

clean:
	rm -rf $(EXE) $(OBJ) $(DEP)

.PHONY: clean

.SECONDARY: $(OBJ)
