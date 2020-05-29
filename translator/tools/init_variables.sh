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
	echo "format list file=${LIST_FILE} doesn't exist!"
	exit 1
    fi
}

format_files() {
    tmpfile=$(mktemp "/tmp/${0##*/}.tmp.XXXXXX")

    for i in ${LIST} ; do
	echo "formatting:${i}"
	if [ -f ${i} ] ; then
	    cat ${i} | sed -e "s/xt_reg_idx_t dstIdx\;/xt_reg_idx_t dstIdx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t vTmpIdx\;/xt_reg_idx_t vTmpIdx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t pTmpIdx\;/xt_reg_idx_t pTmpIdx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t pTmp2Idx\;/xt_reg_idx_t pTmp2Idx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t pTmp3Idx\;/xt_reg_idx_t pTmp3Idx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t zTmpIdx\;/xt_reg_idx_t zTmpIdx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t zTmp2Idx\;/xt_reg_idx_t zTmp2Idx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t zTmp3Idx\;/xt_reg_idx_t zTmp3Idx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t zTmp4Idx\;/xt_reg_idx_t zTmp4Idx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t srcIdx\;/xt_reg_idx_t srcIdx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t src2Idx\;/xt_reg_idx_t src2Idx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t src3Idx\;/xt_reg_idx_t src3Idx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t maskIdx\;/xt_reg_idx_t maskIdx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t offsetIdx\;/xt_reg_idx_t offsetIdx = XT_REG_INVALID\;/" \
		| sed -e "s/int64_t simm\;/int64_t simm = 0\;/" \
		| sed -e "s/xed_uint64_t uimm\;/xed_uint64_t uimm = 0\;/" \
		| sed -e "s/int uimm\;/int uimm = 0\;/" \
		| sed -e "s/uint64_t uimm\;/uint64_t uimm = 0\;/" \
		| sed -e "s/uint32_t sel\;/uint32_t sel = 0\;/" \
		| sed -e "s/int lsbElem\;/int lsbElem = 0\;/" \
		| sed -e "s/int msbElem\;/int msbElem = 0\;/" \
		| sed -e "s/xt_reg_idx_t cmpDstIdx\;/xt_reg_idx_t cmpDstIdx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t cmpMaskIdx\;/xt_reg_idx_t cmpMaskIdx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t cmpSrcIdx\;/xt_reg_idx_t cmpSrcIdx = XT_REG_INVALID\;/" \
		| sed -e "s/xt_reg_idx_t cmpSrc2Idx\;/xt_reg_idx_t cmpSrc2Idx = XT_REG_INVALID\;/" \
		| sed -e "s/uint32_t uimm\;/uint32_t uimm = 0\;/" \
		      > ${tmpfile}
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

