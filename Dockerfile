FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    make \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-tools-dev-tools \
    libqt6serialport6-dev \
    libdbus-1-dev \
    curl \
    git \
    fakeroot \
    rpm \
    ca-certificates \
    file \
    libxkbcommon-dev \
    lsb-release \
    dpkg-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src

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
    mv *.deb /src/mte-toolbox-1.0.4-Linux.deb

CMD ["/usr/local/bin/mte-toolbox"]
