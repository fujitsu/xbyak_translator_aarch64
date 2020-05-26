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

# ex. $1 = pattern/mov/mov000.check
TP_TMP_BASE=$(basename $1)
TP_BASE=`echo ${TP_TMP_BASE} | sed -e "s/\.check//"`
TP_TMP_DIR=$(dirname $1)
TP_DIR=`echo ${TP_TMP_DIR} | sed -e "s/pattern/expected_value/"`
USER_NAME=`whoami`

if [ -f $1 ] ; then
    rm $1
fi

if [ -f $1.ng ] ; then
    rm $1.ng
fi

diff -y -W 300 /tmp/${TP_BASE}.jit_x86_64.exec_x86_64.${USER_NAME}.check.log /tmp/${TP_BASE}.jit_aarch64.exec_aarch64.${USER_NAME}.check.log > $1

LINE_NUM=`wc -l $1 | cut -f 1 -d " "`
DIFF_LINE_NUM=`grep "|" $1 | wc -l | cut -f 1 -d " "`

if [ "${LINE_NUM}" = 80 -a "${DIFF_LINE_NUM}" = 0 ] ; then
    echo "OK:${TP_BASE}" > $1
else
    echo "NG:${TP_BASE}" > $1
    mv $1 $1.ng
fi
