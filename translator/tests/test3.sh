#!/bin/bash -e
#*******************************************************************************
# Copyright 2019-2020 FUJITSU LIMITED
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#*******************************************************************************/

#*******************************************************************************
# Memo
#*******************************************************************************
# HOST_ARCH:Architecture of host computer, where this script is executed, x86_64 or aarch64.
# JIT_ARCH:Architectur of JIT code, x86_64 or aarch64.
# EXEC_ARCH:Architecture of execution file, x86_64 or aarch64.
#*******************************************************************************
# HOST_ARCH, JIT_ARCH, EXEC_ARCH, this script supports?
# x86_64   , x86_64  , x86_64   , OK
# x86_64   , x86_64  , aarch64  , OK (Executable on qemu)
# x86_64   , aarch64 , x86_64   , OK
# x86_64   , aarch64 , aarch64  , OK (Executable on qemu)
# aarch64  , x86_64  , x86_64   , NG
# aarch64  , x86_64  , aarch64  , NG
# aarch64  , aarch64 , x86_64   , NG
# aarch64  , aarch64 , aarch64  , OK (Executable on native environment)
#*******************************************************************************
QEMU_AARCH64_KAWAKAMI=/home/kawakami/local_xbyak/bin/qemu-aarch64

CXX=g++
OBJDUMP=objdump

CFLAGS=""
CFLAGS="${CFLAGS} -std=c++11"
CFLAGS="${CFLAGS} -g"
CFLAGS="${CFLAGS} -DDEBUG"
CFLAGS="${CFLAGS} -Wmaybe-uninitialized"
CFLAGS="${CFLAGS} -Wall"
CFLAGS="${CFLAGS} -I."
CFLAGS="${CFLAGS} -I../../xbyak"
CFLAGS="${CFLAGS} -I../third_party/xbyak_aarch64/xbyak_aarch64"
CFLAGS="${CFLAGS} -I../include/xbyak_translator_for_aarch64"

#*******************************************************************************
# Function definition
#*******************************************************************************
usage_exit() {
    echo "Usage: $0 (-a|-x) (-A|-X) (-e|-E) TEST_SOURCE_FILE"
    echo "export QEMU_AARCH64=PATH_TO_QEMU-AARCH64"
    echo "  -a  Select AArch64 as JIT code output"
    echo "  -x  Select x86_64 as JIT code output"
    echo "  -A  Select AArch64 as exec file type"
    echo "  -X  Select x86_64 as exec file type"
    echo "  -e  Execute exec file only to JIT code output part"
    echo "  -E  Execute exec file"
    exit 1
}

get_host_arch() {
    HOST_ARCH=`uname -m`
    HOST_ARCH=${HOST_ARCH:="unknown"}
}

bad_combination_exit() {
    echo "Bad architecture combination"
    usage_exit
    exit 1
}


check_option() {
    QEMU_ON=0
    TOOL_PREFIX=""
    DUMP_OPT="-m AArch64"
    DUMP_PREFIX=""
}

check_qemu_aarch64() {
    if [ ${QEMU_AARCH64:=${QEMU_AARCH64_KAWAKAMI}} = 0 ] ; then
	echo "set QEMU_AARCH64 environment variable"
	usage_exit
    fi

#    if [ ! -f ${QEMU_AARCH64} ] ; then
#	echo "qemu-aarch64=${QEMU_AARCH64} not found"
#	usage_exit
#    fi
}

gen_compile_option() {
    LIBXED_PATH="../third_party/build_xed_${EXEC_ARCH}/kits/xed/lib"

    if [ ${JIT_ARCH} = "aarch64" ] ; then
	CFLAGS="${CFLAGS} -DDNNL_AARCH64_JIT_AARCH64"
	CFLAGS="${CFLAGS} -DXBYAK_AARCH64_FOR_DNNL"
	CFLAGS="${CFLAGS} -DXBYAK_TRANSLATE_AARCH64"
	CFLAGS="${CFLAGS} -DXT_AARCH64_STACK_REG"
	CFLAGS="${CFLAGS} -DXT_DEBUG"
	CFLAGS="${CFLAGS} -I../include/xbyak_translator_for_aarch64"
	CFLAGS="${CFLAGS} -I../third_party/xbyak_aarch64/xbyak_aarch64"
	CFLAGS="${CFLAGS} -I../third_party/build_xed_${EXEC_ARCH}/kits/xed/include"
	CFLAGS="${CFLAGS} -L${LIBXED_PATH}"
	LIB_OPT="${LIB_OPT} -lxed"
    fi

    TP_NAME=`dirname $1`/`basename $1 .cpp`
    TP_NAME_ARCH=${TP_NAME}.jit_${JIT_ARCH}.exec_${EXEC_ARCH}
    LOG_NAME=`basename ${TP_NAME_ARCH}`
}

compile_test_file() {
    # Compile, execute, dissassemble
    ${TOOL_PREFIX:-""}${CXX} ${CFLAGS} -o ${TP_NAME_ARCH} ${TP_NAME}.cpp ${LIB_OPT}
    if [ ! $? -eq 0 ] ; then
	echo "compile error!"
	exit 1
    fi
}

exec_test() {
    if [ ${QEMU_LD_PREFIX:-0} != 0 ] ; then
	export QEMU_LD_PREFIX=/usr/aarch64-linux-gnu
    fi

    if [ ${QEMU_ON:-0} = 1 ] ; then
	export LD_LIBRARY_PATH=/usr/aarch64-linux-gnu/lib:${LD_LIBRARY_PATH}
    fi

    if [ ${LIBXED_PATH:-0} != 0 ] ; then
	export LD_LIBRARY_PATH="${LIBXED_PATH}:${LD_LIBRARY_PATH}"
    fi

    if [ ${QEMU_ON:-0} = 1 ] ; then
	env QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ${QEMU_AARCH64} ./${TP_NAME_ARCH} ${OUTPUT_JIT_ON} ${EXEC_JIT_ON} 2>&1 | tee ${LOG_NAME}.log
    else
	./${TP_NAME_ARCH} ${OUTPUT_JIT_ON} ${EXEC_JIT_ON} 2>&1 | tee ${LOG_NAME}.log
    fi

    RC=${PIPESTATUS[0]}
    if [ ${RC} -ne 0 ] ; then
	echo "exec error!"
	exit 1
    fi
}

dump_disassemble() {
    local BIN_FILE=${TP_NAME_ARCH}.bin
    local ASM_FILE=${LOG_NAME}.asm

    ${DUMP_PREFIX}${OBJDUMP} -D -b binary ${DUMP_OPT} ${BIN_FILE} > ${ASM_FILE}
}

extract_log() {
    tmpfile=/tmp/${LOG_NAME}.`whoami`.check.log
    grep -w Check ${LOG_NAME}.log > ${tmpfile}
}

debug_dump_option() {
    echo "HOST_ARCH=${HOST_ARCH}"
    echo "JIT_ARCH =${JIT_ARCH}"
    echo "EXEC_ARCH=${EXEC_ARCH}"
    echo "QEMU     =${QEMU_ON}"
    echo "DUMP_OPT =${DUMP_OPT}"
}

#echo "num of args=$#"
#echo "args=$@"

#*******************************************************************************
# Main routine
#*******************************************************************************
unset QEMU_ON
unset EXEC_ON
unset OUTPUT_JIT_ON
unset EXEC_JIT_ON

DATE_STR=`date +"%Y%m%d-%H%M%S"`

while getopts axAXeEhH OPT
do
    case $OPT in
	a) JIT_ARCH=aarch64
	   CFLAGS="${CFLAGS} ${CFLAGS_AARCH64}"
	   TP_NAME=${OPTARG%.*}
	   ;;
	x) JIT_ARCH=x86_64
	   TP_NAME=${OPTARG%.*}
	   ;;
	A) EXEC_ARCH=aarch64
	   ;;
	X) EXEC_ARCH=x86_64
	   ;;
	e) OUTPUT_JIT_ON=1
	   EXEC_JIT_ON=0
	   ;;
	E) OUTPUT_JIT_ON=1
	   EXEC_JIT_ON=1
	   ;;
	h) usage_exit
	   ;;
	H) usage_exit
	   ;;
	\?) usage_exit
	    ;;
    esac
done
shift $((OPTIND - 1))




#echo "num of args=$#"
if [ ! $# = 1 ] ; then
    usage_exit
fi
get_host_arch
check_option
check_qemu_aarch64
debug_dump_option
gen_compile_option $@
compile_test_file
if [ ${OUTPUT_JIT_ON:-0} = 1 ] ; then
    exec_test
fi
if [ ${OUTPUT_JIT_ON:-0} = 1 ] ; then
    dump_disassemble
fi
extract_log
