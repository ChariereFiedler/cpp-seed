# TODO:
# - Add Doxygen support
# - Inlude the dockerfile in CI pipeline

FROM ubuntu:zesty as cmake

ARG c_compiler=gcc-7
ARG cxx_compiler=g++-7
ARG BUILD_TYPE=Debug
ARG CMAKE_CXX_COMPILER=${cxx_compiler}
ENV CC=/usr/bin/${c_compiler}
ENV CXX=/usr/bin/${cxx_compiler}


# GCC & G++ installation
RUN apt-get update &&\
    apt-get install -y --no-install-recommends --no-install-suggests \
     software-properties-common &&\
    add-apt-repository ppa:ubuntu-toolchain-r/test &&\
    apt-get remove -y software-properties-common --purge && \
    apt-get update &&\
    apt-get install --no-install-recommends  --no-install-suggests --allow-downgrades  -y \
    make cmake g++-7 gcc-7 git \
    && apt-get autoremove -y\
    && apt-get clean \


# CMake Installation

    && rm -rf /var/lib/apt/lists/* /var/log/* /tmp/*

ADD . /cpp-seed

RUN mkdir /cpp-seed/build && \
    mkdir /cpp-seed/build/cmake-build-${BUILD_TYPE} && \
    cd /cpp-seed/build/cmake-build-${BUILD_TYPE} && \
    cmake ../.. -DCMAKE_BUILD_TYPE=${BUILD_TYPE}
WORKDIR /cpp-seed/build/cmake-build-${BUILD_TYPE}

RUN make all