FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && \
    apt install -y \
    build-essential \
    cmake \
    qt6-base-dev \
    qt6-base-dev-tools \
    qt6-serialport-dev \
    qt6-tools-dev \
    libqt6core6 \
    libqt6gui6 \
    libqt6widgets6 \
    libqt6serialport6 \
    libqt6dbus6 \
    qt6-qpa-plugins \
    qt6-image-formats-plugins \
    libgl1-mesa-glx \
    libxkbcommon0 \
    libfontconfig1 \
    libx11-6 \
    libglib2.0-0 \
    libdbus-1-3 \
    libfreetype6 \
    libzstd1 \
    libexpat1 \
    libxcb1 \
    libpcre2-8-0 \
    libbz2-1.0 \
    libpng16-16 \
    libbrotlidec1 \
    libsystemd0 \
    libbsd0 \
    libcap2 \
    libgcrypt20 \
    liblz4-1 \
    liblzma5 \
    libmd0 \
    libgpg-error0 \
    libicu-dev && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN echo "--- Checking LICENSE.txt ---" && \
    if [ -f "LICENSE.txt" ]; then echo "✅ LICENSE.txt bulundu."; else echo "❌ LICENSE.txt eksik!"; exit 1; fi

# Build ve .deb üretimi
RUN mkdir -p build && \
    cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    make -j$(nproc) && \
    make install DESTDIR=install && \
    cpack -G DEB && \
    mv mte-toolbox-1.0.4-Linux.deb /app/
