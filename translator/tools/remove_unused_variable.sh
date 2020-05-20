#!/bin/bash
#/*******************************************************************************
# * Copyright 2020 FUJITSU LIMITED
# *
# * Licensed under the Apache License, Version 2.0 (the ""License"");
# * you may not use this file except in compliance with the License.
# * You may obtain a copy of the License at
# *
# *     http://www.apache.org/licenses/LICENSE-2.0
# *
# * Unless required by applicable law or agreed to in writing, software
# * distributed under the License is distributed on an ""AS IS"" BASIS,
# * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# * See the License for the specific language governing permissions and
# * limitations under the License.
# *******************************************************************************/
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


