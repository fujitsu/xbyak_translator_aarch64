#!/bin/bash
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
# imitations under the License.
# *******************************************************************************/
DIR_ROOT=`pwd`

# Build QEMU
# QEMU must be build by native compiler
echo "##################################################"
echo "# Download and build QEMU"
echo "# Wait for a few minutes"
echo "##################################################"
.github/automation/qemu.sh &> /dev/null
qemu-aarch64 --version

# Set compiler
source .github/env/setenv-gcc-qemu

echo "##################################################"
echo "# Download git submodules"
echo "##################################################"
git submodule sync --recursive
git submodule update --init --recursive

# Build libxed
echo "##################################################"
echo "# Build Intel XED"
echo "# Wait for a few minutes"
echo "##################################################"
.github/automation/xed.sh -q > /dev/null

# Build libxbyak_aarch64
echo "##################################################"
echo "# Build Xbyak_aarch64"
echo "##################################################"
make -C ${DIR_ROOT}/translator/third_party/xbyak_aarch64

# Build libxbyak_translator_aarch64
echo "##################################################"
echo "# Build Xbyak_translator_aarch64"
echo "##################################################"
make

# Do tests
echo "##################################################"
echo "# Start CI"
echo "##################################################"
cd ${DIR_ROOT}/translator/tests
make -j$(nproc)
