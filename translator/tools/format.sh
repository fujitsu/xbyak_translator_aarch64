#!/bin/bash
set -eu
unset tmpfile

CLANG_FORMAT=${CLANG_FORMAT:="clang-format"}
LIST_FILE=file_list_to_be_formatted.txt


atexit() {
    [[ -n ${tmpfile-} ]] && rm -f "$tmpfile"
}

clang_ver_check() {
    # clang-format version check
    ${CLANG_FORMAT} --version | grep "version 6.0.0" > /dev/null
    if [ $? != 0 ] ; then
	echo "clang-format version missmatch! Version 6.0.0 is required."
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
	clang-format -style=LLVM ${i} > ${tmpfile}
	mv ${tmpfile} ${i}
    done
}



trap atexit EXIT
trap 'rc=$?; trap - EXIT; atexit; exit $?' INT PIPE TERM

clang_ver_check
gen_format_file_list
format_files

