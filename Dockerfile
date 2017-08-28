# TODO:
# - Add Doxygen support
# - Inlude the dockerfile in CI pipeline

FROM ubuntu:zesty as builder

ARG c_compiler=gcc-7
ARG cxx_compiler=g++-7
ARG CC=/usr/bin/gcc-7
ARG CXX=/usr/bin/g++-7

RUN apt-get update &&\
    apt-get -y install software-properties-common &&\
    add-apt-repository ppa:ubuntu-toolchain-r/test &&\
    apt-get update &&\
    apt-get install -y --allow-downgrades --allow-remove-essential \
    --allow-change-held-packages \
    build-essential git wget apt-utils gcc-7 g++-7;

RUN wget "https://cmake.org/files/v3.9/cmake-3.9.1.tar.gz" &&\
    tar -xzvf cmake-3.9.1.tar.gz &&\
    cd cmake-3.9.1 &&\
    ./bootstrap &&\
    make -j 4 &&\
    make install

ADD . /cpp-seed


RUN cd /cpp-seed && \
    mkdir cmake-build-debug && \
    cd cmake-build-debug && \
    cmake .. -DCMAKE_CXX_COMPILER=${cxx_compiler} -DCMAKE_BUILD_TYPE=Debug && \
    make install-all && \
    make -j 4 && \
    ctest
