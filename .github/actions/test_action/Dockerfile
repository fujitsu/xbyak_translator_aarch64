FROM ubuntu:latest

COPY entrypoint.sh /entrypoint.sh

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update
RUN apt-get install -y tzdata
ENV TZ=Asia/Tokyo
RUN apt-get install -y binutils-aarch64-linux-gnu
RUN apt-get install -y cpp-8-aarch64-linux-gnu
RUN apt-get install -y cpp-aarch64-linux-gnu
RUN apt-get install -y g++-8-aarch64-linux-gnu
RUN apt-get install -y g++-aarch64-linux-gnu
RUN apt-get install -y gcc-8-aarch64-linux-gnu
RUN apt-get install -y gcc-8-aarch64-linux-gnu-base:amd64
RUN apt-get install -y gcc-aarch64-linux-gnu
RUN apt-get install -y pkg-config-aarch64-linux-gnu
RUN apt-get install -y build-essential
RUN apt-get install -y wget

RUN wget https://download.qemu.org/qemu-5.0.0.tar.xz
RUN tar Jxvf qemu-5.0.0.tar.xz
RUN cd qemu-5.0.0
RUN ./configure --target-list=aarch64-linux-user --prefix=/local_qemu_5.0.0
RUN make

ENTRYPOINT ["/entrypoint.sh"]
