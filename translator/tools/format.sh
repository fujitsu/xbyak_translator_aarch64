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

CLANG_FORMAT=${CLANG_FORMAT:="clang-format"}
LIST_FILE=file_list_to_be_formatted.txt


atexit() {
    [[ -n ${tmpfile-} ]] && rm -f "$tmpfile"
}

clang_ver_check() {
    # clang-format version check
    ${CLANG_FORMAT} --version | grep "version 9.0.0" > /dev/null
    if [ $? != 0 ] ; then
	echo "clang-format version missmatch! Version 9.0.0 is required."
	exit
#    else
#	echo "clang-format version checko OK!"
    fi
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

    for i in ${LIST} ; do
	echo "formatting:${i}"
	if [ -f ${i} ] ; then
	    clang-format -style=LLVM ${i} > ${tmpfile}
	    mv ${tmpfile} ${i}
	else
	    echo "not found"
	fi
    done
}



trap atexit EXIT
trap 'rc=$?; trap - EXIT; atexit; exit $?' INT PIPE TERM

clang_ver_check
gen_format_file_list
format_files

