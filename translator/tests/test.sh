#!/bin/bash
CXX=g++
OBJDUMP=objdump


CFLAGS=""
CFLAGS="${CFLAGS} -std=c++11"
CFLAGS="${CFLAGS} -g"
CFLAGS="${CFLAGS} -DDEBUG"
CFLAGS="${CFLAGS} -I../../xbyak -I../third_party/xbyak_aarch64/xbyak_aarch64"
#CFLAGS="${CFLAGS} -fstack-usage"


CFLAGS_AARCH64=""
CFLAGS_AARCH64="${CFLAGS_AARCH64} -DDNNL_AARCH64_JIT_AARCH64"
CFLAGS_AARCH64="${CFLAGS_AARCH64} -I../xed/build_xed/kits/xed/include"
CFLAGS_AARCH64="${CFLAGS_AARCH64} -L../xed/build_xed/kits/xed/lib"
#CFLAGS_AARCH64="${CLFAGS_AARCH64} -mstrict-align"
#CFLAGS="${CFLAGS} ${CFLAGS_AARCH64}"



usage_exit() {
    echo "Usage: $0 (-a|-x) (-e) TEST_SOURCE_FILE"
    echo "  -a  Generate JIT code for AArch64"
    echo "  -x  Generate JIT code for x86_64"
    echo "  -e  Execute  JIT code"
    exit 1
}


while getopts a:x:h OPT
do
    case $OPT in
	a) JIT_TYPE=AARCH64
	   CFLAGS="${CFLAGS} ${CFLAGS_AARCH64}"
	   TP_NAME=${OPTARG%.*}
	   ;;
	x) JIT_TYPE=X86_64
	   TP_NAME=${OPTARG%.*}
	   ;;
	h) usage_exit
	   ;;
	\?) usage_exit
	    ;;
    esac
done
shift $((OPTIND - 1))


if [ ${JIT_TYPE:-0} = 0 ] ; then
    usage_exit
fi

ARCH=$(uname -m)

if [ ${ARCH:-unknown} = "x86_64" -a ${JIT_TYPE} = "X86_64" ] ; then
    echo "Env=x86_64, Jit=x86_64"
    DUMP_TYPE="i386:x86-64"
elif [ ${ARCH:-unknown} = "x86_64" -a ${JIT_TYPE} = "AARCH64" ] ; then
    echo "Env=x86_64, Jit=AArch64"
    TOOL_PREFIX="aarch64-linux-gnu-"
    LIB_OPT="-lxed"
    USE_QEMU=1
    DUMP_TYPE="AARch64"
elif [ ${ARCH:-unknown} = "aarch64" -a ${JIT_TYPE} = "AARCH64" ] ; then
    echo "Env=AArch64, Jit=AArch64"
    LIB_OPT="-lxed"
    DUMP_TYPE="AARch64"
fi



# Compile, execute, dissassemble
${TOOL_PREFIX:-""}${CXX} ${CFLAGS} -o ${TP_NAME} ${TP_NAME}.cpp ${LIB_OPT}
if [ $? -eq 0 ] ; then
    if [ ${USE_QEMU:-0} = 1 ] ; then
	env QEMU_LD_PREFIX=/usr/aarch64-linux-gnu qemu-aarch64 ./${TP_NAME}
    else
	./${TP_NAME}
    fi

    if [ -f hoge ] ; then
	${TOOL_PREFIX}${OBJDUMP} -D -b binary -m ${DUMP_TYPE} -M intel hoge > hoge.asm
    fi
fi

