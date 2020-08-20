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
RUN apt-get install -y libbz2-dev libdb-dev libreadline-dev \
    libffi-dev libgdbm-dev liblzma-dev libncursesw5-dev libsqlite3-dev libssl-dev \
    zlib1g-dev uuid-dev tk-dev
RUN apt-get install -y sudo

RUN wget https://www.python.org/ftp/python/3.6.12/Python-3.6.12.tar.xz && \
    tar xJf Python-3.6.12.tar.xz && \
    cd Python-3.6.12 && \
    ./configure && \
#    sudo make && \
#    sudo make install && \
    make && \
    make install && \
    cd /usr/local/bin && ln -sf python3 python
#RUN which python
#RUN /usr/local/bin/python --version
    
RUN wget https://download.qemu.org/qemu-5.0.0.tar.xz && \
    tar Jxvf qemu-5.0.0.tar.xz && \
    cd qemu-5.0.0 && \
#    sudo chmod 777 configure && \
    ./configure --target-list=aarch64-linux-user --prefix=/local_qemu_5.0.0 --python=/usr/local/bin && \
#    sudo make
    make

#ENTRYPOINT ["/entrypoint.sh"]
