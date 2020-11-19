#! /bin/bash
#===============================================================================
# Copyright 2020 FUJITSU LIMITED
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

# Build xed
DIR_BUILD=translator/third_party/build_xed_aarch64
mkdir -p ${DIR_BUILD}
cd ${DIR_BUILD}

while getopts nq OPT
do
    case $OPT in
	q)
	    ../xed/mfile.py \
		--strip=/usr/bin/aarch64-linux-gnu-strip  \
		--cc=/usr/bin/aarch64-linux-gnu-gcc \
		--cxx=/usr/bin/aarch64-linux-gnu-g++ \
		--host-cpu=aarch64 \
		--shared examples install
	    ;;
	n)
	    ../xed/mfile.py \
	    --shared examples install
	    ;;
   esac
done
shift $((OPTIND - 1))

cd kits
ln -sf xed-install* xed

