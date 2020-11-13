TARGET=../../lib/libxbyak_translator_aarch64.a
all: $(TARGET) 

XED_DIR=../third_party/build_xed_aarch64/kits/xed/

CFLAGS+=-std=c++11 -DNDEBUG -O2 -g -I ../../xbyak -I ../third_party/xbyak_aarch64/xbyak_aarch64/ -I ../include/xbyak_translator_for_aarch64/ -I $(XED_DIR)/include/

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CFLAGS)

$(TARGET): impl.o
	ar r $@ $<

clean:
	rm -rf *.o $(TARGET)

.PHONY: clean
