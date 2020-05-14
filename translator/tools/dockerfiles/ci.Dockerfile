FROM ubuntu:18.04

ENV http_proxy http://username:password@address:port/
ENV https_proxy https://username:password@address:port/
ENV HTTP_PROXY http://username:password@address:port/
ENV HTTPS_PROXY https://username:password@address:port/

# lib install
RUN apt-get update -y && apt-get install -y git cmake binutils-aarch64-linux-gnu cpp-8-aarch64-linux-gnu g++-8-aarch64-linux-gnu gcc-8-aarch64-linux-gnu gcc-8-aarch64-linux-gnu-base:amd64 pkg-config-aarch64-linux-gnu gcc-aarch64-linux-gnu g++-aarch64-linux-gnu libglib2.0-dev libpixman-1-dev python python-pip python3 python3-pip

# qemu build install
ADD qemu-3.1.1.1.with_patch.tar.xz /
RUN mkdir /qemu-3.1.1.1.with_patch/build
WORKDIR /qemu-3.1.1.1.with_patch/build
RUN ../configure --target-list=aarch64-linux-user
RUN make
RUN make install
