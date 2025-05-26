# 1. Build stage
FROM ubuntu:24.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

# Add a retry mechanism for apt updates/installs
RUN apt update && apt install -y curl && \
    for i in $(seq 1 5); do \
        apt update && apt install -y \
        libicu74 libicu-dev cmake build-essential qt6-base-dev qt6-base-dev-tools qt6-base-private-dev qt6-tools-dev qt6-tools-dev-tools qt6-serialport-dev file dpkg-dev fakeroot lintian \
        && break || sleep 5; \
    done && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN mkdir -p build && cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    make -j$(nproc) && \
    make install DESTDIR=install && \
    ls -l install/usr/local/bin && \
    cpack -G DEB && \
    ls -l *.deb


# 2. Final stage (already provided and should be updated as discussed)
FROM ubuntu:24.04 AS final

ENV DEBIAN_FRONTEND=noninteractive

WORKDIR /app

COPY --from=builder /app/build/*.deb ./

RUN apt update && \
    dpkg -i mte-toolbox_*.deb || apt install -fy && \
    rm -rf /var/lib/apt/lists/*

CMD ["/usr/local/bin/mte-toolbox"]