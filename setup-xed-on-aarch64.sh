#!/bin/sh

git submodule update --init
cd translator/third_party
mkdir build_xed_aarch64
cd build_xed_aarch64
../xed/mfile.py --shared examples install  # Python3 is required.
cd kits/
ln -sf xed-install-base-* xed
