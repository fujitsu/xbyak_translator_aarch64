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
LIST_FILE=file_list_to_be_formatted.txt


atexit() {
    [[ -n ${tmpfile-} ]] && rm -f "$tmpfile"
}

gen_format_file_list() {
    local TMP_LIST_FILE=$(dirname $0)/${LIST_FILE}
    if [ -f ${TMP_LIST_FILE} ] ; then
	LIST=`cat ${TMP_LIST_FILE}`
    else
	echo "format list file=${LIST_FILE} doesn't exist!"
	exit 1
    fi
}

format_files() {
    tmpfile=$(mktemp "/tmp/${0##*/}.tmp.XXXXXX")

    for k in ${LIST} ; do
	echo "removing unused variable:${k}"

	for i in ${LIST_KEYWORDS} ; do
	    num=`grep "[[:space:]]${i}" ${k} | wc -l | cut -f 1 -d " "`
	    num1=`grep "(${i}" ${k} | wc -l | cut -f 1 -d " "`
	    num=$((${num}+${num1}))

	    if [ ${num} -eq 1 ] ; then
		grep -vw "${i}" ${k} > ${tmpfile}
		mv ${tmpfile} ${k}
	    fi
	done

	num=`grep -w isValid ${k} | wc -l | cut -f 1 -d " "`
	num1=`grep -w XT_VALID_CHECK_IF ${k} | wc -l | cut -f 1 -d " "`
	if [ ${num} -eq 1 ] ; then
	    if [ ${num1} -eq 0 ] ; then
		grep -vw "isValid" ${k} > ${tmpfile}
		mv ${tmpfile} ${k}
	    fi
	fi
    done
}

trap atexit EXIT
trap 'rc=$?; trap - EXIT; atexit; exit $?' INT PIPE TERM

gen_format_file_list
format_files
