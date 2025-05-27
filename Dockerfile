FROM ubuntu:22.04

# Temel bağımlılıkları kur
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



# Qt 6.8 kurulumu için kendi yolunu buraya ekleyebilirsin
# Eğer Qt 6.8 sistemde yoksa, alternatif olarak
# Qt'yi elle indirip kurman gerekebilir.

WORKDIR /build

# Proje dosyalarını kopyala
COPY . /build

RUN mkdir build && cd build && \
    cmake -DCMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu/cmake/Qt6 .. && \
    make && \
    cpack -G DEB
