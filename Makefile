XA=lib/libxbyak_aarch64.a
XTA=lib/libxbyak_translator_aarch64.a
TARGET=$(XA) $(XTA)
all: $(TARGET)

$(XA):
	$(MAKE) -C translator/third_party/xbyak_aarch64
	cp -a translator/third_party/xbyak_aarch64/lib/libxbyak_aarch64.a $@

$(XTA):
	$(MAKE) -C translator/src

clean:
	\rm -rf $(TARGET)
	make -C translator/third_party/xbyak_aarch64 clean
	make -C translator/src clean

.PHONY: clean $(XTA) $(XA)
