#!/bin/zsh
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
source ~/.zshrc.xbyak
INSTRUCTION=${1}

file_log=regression_${INSTRUCTION}.log
if [ -e ${file_log} ] ; then
    rm ${file_log}
fi

echo "log file:${file_log}"


for i in `ls pattern/${INSTRUCTION}/${INSTRUCTION}*.cpp` ; do
    PATTERN=`echo ${i} | sed -e "s/.\+\/${INSTRUCTION}//" | sed -e "s/\.cpp//"`
#    echo ${INSTRUCTION}${PATTERN}

    TE ${INSTRUCTION}${PATTERN} all | tee ${file_log} | grep ALLTEST
done
