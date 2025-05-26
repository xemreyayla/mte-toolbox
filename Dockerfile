# 1. Build stage
FROM ubuntu:24.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && \
    apt install -y libicu74 libicu-dev cmake build-essential qt6-base-dev qt6-base-dev-tools qt6-base-private-dev qt6-tools-dev qt6-tools-dev-tools qt6-serialport-dev file dpkg-dev fakeroot lintian && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN mkdir -p build && \
    cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    make -j$(nproc) && \
    make install DESTDIR=install && \
    cpack -G DEB

# 2. Final stage
FROM ubuntu:24.04 AS final

WORKDIR /app

# Builder aşamasından .deb dosyasını kopyala
COPY --from=builder /app/build/*.deb ./
