FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && \
    apt install -y \
    cmake \
    build-essential \
    qt6-base-dev \
    qt6-base-dev-tools \
    qt6-base-private-dev \
    qt6-tools-dev \
    qt6-tools-dev-tools \
    qt6-serialport-dev \
    file \
    dpkg-dev \
    fakeroot \
    lintian \
    && rm -rf /var/lib/apt/lists/*

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
