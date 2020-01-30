#!/bin/sh
CLANG_FORMAT=${CLANG_FORMAT:="clang-format"}
#list=`ls *.cpp *.h`
list="xbyak_translate.h xbyak_translate_inc.h"


# clang-format version check
${CLANG_FORMAT} --version | grep "version 6.0.0" > /dev/null
if [ $? != 0 ] ; then
    echo "clang-format version missmatch!"
    exit
fi


for i in ${list} ; do
    echo "formatting:${i}"
    clang-format -style=LLVM ${i} > hoge
    mv hoge ${i}
done
