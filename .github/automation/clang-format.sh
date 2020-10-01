#! /bin/bash

#===============================================================================
# Copyright 2019-2020 Intel Corporation
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
#===============================================================================

echo "Using clang-format version: $(clang-format --version)"
echo "Starting format check..."

tmpfile=$(mktemp)
find "$(pwd)" -type f | grep -P ".*\.(c|cpp|h|hpp|cl)$" > ${tmpfile}
num_line=`wc -l ${tmpfile} | cut -f 1 -d " "`
count=0

while [ ${count} -lt ${num_line} ]
do
    i=0
    array=()
    while [ ${i} -lt 40 ]
    do
	echo "clang-format `sed -n $((${count}+1))p ${tmpfile}`"
	nohup clang-format -i -style=file `sed -n $((${count}+1))p ${tmpfile}` &
	array+=($!)
	count=$((${count}+1))
	i=$((${i}+1))

	if [ ${count} -ge ${num_line} ] ; then
	    break;
	fi
    done
    wait ${array[@]}
done

RETURN_CODE=0
echo $(git status) | grep "nothing to commit" > /dev/null

if [ $? -eq 1 ]; then
    echo "Clang-format check FAILED! Found not formatted files!"
    echo "$(git status)"
    RETURN_CODE=3
else
    echo "Clang-format check PASSED! Not formatted files not found..."
fi

exit ${RETURN_CODE}
