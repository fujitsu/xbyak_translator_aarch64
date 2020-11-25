TARGET=../../lib/libxbyak_translator_aarch64.a
all: $(TARGET) 

XED_DIR=../third_party/build_xed_aarch64/kits/xed/

CFLAGS+=-std=c++11 -DNDEBUG -g -I ../../xbyak -I ../third_party/xbyak_aarch64/xbyak_aarch64/ -I ../include/xbyak_translator_for_aarch64/ -I $(XED_DIR)/include/
ifneq ($(DEBUG),1)
CFLAGS+=-O2
endif

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CFLAGS) -MMD -MP -MF $(@:.o=.d)

-include impl.d

$(TARGET): impl.o
	ar r $@ $<

clean:
	rm -rf *.o $(TARGET) *.d

.PHONY: clean

.SECONDARY: impl.o impl.d
