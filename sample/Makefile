all: add.exe

XED_DIR=../translator/third_party/build_xed_aarch64/kits/xed/

CFLAGS+=-std=c++11 -DNDEBUG -g -I ../xbyak -I ../translator/third_party/xbyak_aarch64/xbyak_aarch64/ -I ../translator/include/xbyak_translator_for_aarch64/ -I $(XED_DIR)/include/
LDFLAGS+=-L $(XED_DIR)/lib/ -lxed

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CFLAGS)

%.exe: %.o
	$(CXX) $< -o $@ $(LDFLAGS)

test: add.exe
	env LD_LIBRARY_PATH=$(XED_DIR)/lib/ ./add.exe

clean:
	rm -rf *.exe

.PHONY: clean
