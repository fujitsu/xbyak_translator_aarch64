#!/bin/zsh
source ~/.zshrc.xbyak
INSTRUCTION=${1}

file_log=regression_${INSTRUCTION}.log
if [ -e ${file_log} ] ; then
    rm ${file_log}
fi

echo "log file:${file_log}"


for i in `ls pattern/${INSTRUCTION}/${INSTRUCTION}*.cpp` ; do
    PATTERN=`echo ${i} | sed -e "s/.\+\/${INSTRUCTION}//" | sed -e "s/\.cpp//"`
#    echo ${INSTRUCTION}${PATTERN}

    TE ${INSTRUCTION}${PATTERN} all | tee ${file_log} | grep ALLTEST
done
