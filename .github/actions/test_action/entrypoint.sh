#!/bin/bash
#*******************************************************************************
# Copyright 2019 FUJITSU LIMITED 
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
# imitations under the License.
# *******************************************************************************/
git submodule sync --recursive
git submodule update --init --recursive
pwd
ls
cd translator/third_party/
mkdir build_xed_aarch64
cd build_xed_aarch64/
../xed/mfile.py --strip=/usr/bin/aarch64-linux-gnu-strip  --cc=/usr/bin/aarch64-linux-gnu-gcc --cxx=/usr/bin/aarch64-linux-gnu-g++ --host-cpu=aarch64 --shared examples install
cd kits/
XED=`ls | grep install`
ln -sf $XED xed
cd xed/bin/
CI_XED_PATH=`pwd`
#cd ../../../
#mkdir build_xed_aarch64
#cd build_xed_aarch64/
#../xed/mfile.py --host-cpu=x86_64 --shared examples install
#cd kits/
#XED=`ls | grep install`
#ln -sf $XED xed
#cd xed/bin/
#CI_XED_PATH=`pwd`
cd ../../../../../
source dot.zshrc.xbyak.ci
cd tests/
echo "display xed_lib_path"
aarch64-linux-gnu-objdump -a ../third_party/build_xed_aarch64/kits/xed/lib/libxed.so
aarch64-linux-gnu-objdump -a ../third_party/build_xed_aarch64/kits/xed/lib/libxed-ild.so
which aarch64-linux-gnu-g++
aarch64-linux-gnu-g++ --version
uname -m
export QEMU_AARCH64=/local_qemu_5.0.0/bin/qemu-aarch64
which qemu-aarch64
make -j2

