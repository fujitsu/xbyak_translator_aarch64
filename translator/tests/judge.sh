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
NUM_TP=`find pattern -name "*.cpp" | wc -l | cut -f 1 -d " "`
#NUM_TP=`find pattern/mov -name "*.cpp" | wc -l | cut -f 1 -d " "`
NUM_OK=`grep OK regression.log | wc -l | cut -f 1 -d " "`

echo "TP pattern count:${NUM_TP}"
echo "OK pattern count:${NUM_OK}"

if [ ${NUM_TP:-5} = ${NUM_OK:-9} ] ; then
    echo "Congratulation!"
    exit 0
else
    echo "Something wrong!"
    exit 1
fi
