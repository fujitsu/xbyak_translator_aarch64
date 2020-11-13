perl -i -pe s'/void (\w)(.*)/void Xbyak::CodeGenerator::\1\2/' `find instructions/*.h`

