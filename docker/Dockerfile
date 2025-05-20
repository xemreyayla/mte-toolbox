FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
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
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src

COPY . .

RUN mkdir build && cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    make -j$(nproc) && \
    make install && \
    cpack -G DEB

CMD ["ls", "-lh", "/src/build/"]
