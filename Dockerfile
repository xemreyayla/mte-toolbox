FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    curl \
    ca-certificates \
    libqt6core6 \
    libqt6gui6 \
    libqt6widgets6 \
    libqt6serialport6 \
    libqt6dbus6 \
    qt6-base-dev \
    libqt6serialport6-dev \
    qt6-base-dev-tools \
    qt6-tools-dev-tools \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    mesa-common-dev \
    debhelper \
    fakeroot \
    dh-make \
    && apt-get clean

WORKDIR /build
COPY . .

RUN mkdir build && cd build && \
    cmake -DCMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu/cmake/Qt6 .. && \
    make && \
    make install DESTDIR=package && \
    cpack -G DEB


# DEB dosyasını dışarı kopyala
RUN find . -name "*.deb" -exec cp {} /build/ \;

CMD cp /build/build/*.deb /build/
