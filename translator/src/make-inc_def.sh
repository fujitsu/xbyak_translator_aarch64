awk '/^void / {printf("void %s *p);\n", $2)}' instructions/*.h > ../include/xbyak_translator_for_aarch64/xbyak_translator_inc_def.h
