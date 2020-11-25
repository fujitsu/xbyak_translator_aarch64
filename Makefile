TARGET=lib/libxbyak_aarch64.a lib/libxbyak_translator_aarch64.a
all: $(TARGET)

translator/third_party/xbyak_aarch64/lib/libxbyak_aarch64.a:
	$(MAKE) -C translator/third_party/xbyak_aarch64

lib/libxbyak_aarch64.a: translator/third_party/xbyak_aarch64/lib/libxbyak_aarch64.a
	cp -a $< $@

lib/libxbyak_translator_aarch64.a:
	$(MAKE) -C translator/src

clean:
	\rm -rf $(TARGET)
	make -C translator/third_party/xbyak_aarch64 clean
	make -C translator/src clean

.PHONY: clean
