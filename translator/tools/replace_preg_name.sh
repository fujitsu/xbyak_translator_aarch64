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

LIST_FILE=file_list_to_be_formatted.txt

atexit() {
    [[ -n ${tmpfile-} ]] && rm -f "$tmpfile"
}

gen_format_file_list() {
    local TMP_LIST_FILE=$(dirname $0)/${LIST_FILE}
    if [ -f ${TMP_LIST_FILE} ] ; then
	LIST=`cat ${TMP_LIST_FILE}`
    else
	echo "replace list file=${LIST_FILE} doesn't exist!"
	exit 1
    fi
}

format_files() {
    tmpfile=$(mktemp "/tmp/${0##*/}.tmp.XXXXXX")

    for i in ${LIST} ; do
	echo "replacing:${i}"
	if [ -f ${i} ] ; then
	    cat ${i} | sed -e "s/xa::PReg(13)/P_MSB_256/" \
	       	| sed -e "s/xa::PRegB(13)/P_MSB_256.b/" \
                | sed -e "s/xa::PRegB(13)/P_MSB_256.b/" \
     		| sed -e "s/xa::PRegH(13)/P_MSB_256.h/" \
     		| sed -e "s/xa::PRegS(13)/P_MSB_256.s/" \
     		| sed -e "s/xa::PRegD(13)/P_MSB_256.d/" \
		| sed -e "s/xa::PReg(14)/P_MSB_384/" \
		| sed -e "s/xa::PRegB(14)/P_MSB_384.b/" \
     		| sed -e "s/xa::PRegH(14)/P_MSB_384.h/" \
     		| sed -e "s/xa::PRegS(14)/P_MSB_384.s/" \
     		| sed -e "s/xa::PRegD(14)/P_MSB_384.d/" \
		| sed -e "s/xa::PReg(15)/P_ALL_ONE/" \
		| sed -e "s/xa::PRegB(15)/P_ALL_ONE.b/" \
     		| sed -e "s/xa::PRegH(15)/P_ALL_ONE.h/" \
     		| sed -e "s/xa::PRegS(15)/P_ALL_ONE.s/" \
     		| sed -e "s/xa::PRegD(15)/P_ALL_ONE.d/" \
		      > ${tmpfile}
	    mv ${tmpfile} ${i}
	else
	    echo "not found"
	fi
    done
}



trap atexit EXIT
trap 'rc=$?; trap - EXIT; atexit; exit $?' INT PIPE TERM

gen_format_file_list
format_files
