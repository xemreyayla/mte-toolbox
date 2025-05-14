FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    make \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-tools-dev-tools \
    qt6-serialport-dev \
    libdbus-1-dev \
    dh-make \
    fakeroot \
    lintian \
    dpkg-dev \
    && apt-get clean


WORKDIR /src

COPY . .
RUN mkdir build && cd build && cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local

RUN cd build && make 

RUN cd build && make install

RUN cd build && cpack

EXPOSE 8080

CMD ["/usr/local/bin/mte-toolbox"]
