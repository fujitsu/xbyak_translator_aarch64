#!/bin/bash
set -u
unset tmpfile

LIST_KEYWORDS="uimm dstIdx srcIdx src2Idx src3Idx maskIdx zTmpIdx zTmp2Idx zTmp3Idx zTmp4Idx pTmpIdx pTmp2Idx"
FILE_IN=${1}

atexit() {
    [[ -n ${tmpfile-} ]] && rm -f "$tmpfile"
}


trap atexit EXIT
trap 'rc=$?; trap - EXIT; atexit; exit $?' INT PIPE TERM


echo "Remove unused varialbe:${FILE_IN}"


tmpfile=$(mktemp "/tmp/${0##*/}.tmp.XXXXXX")

for i in ${LIST_KEYWORDS} ; do
    num=`grep -ew \[:space:\]\+${i} ${FILE_IN} | grep -w ${i} | wc -l`
#    if [ ${num} -le 1 ] ; then
#	grep -evw "[:space:]\+${i}" ${FILE_IN} > ${tmpfile}
#	mv ${tmpfile} ${FILE_IN}
#    fi
done


