FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive
ENV QT_VERSION=6.8.3
ENV QT_DIR=/home/emre/Qt

# Gerekli paketler
RUN apt update && apt install -y \
    build-essential \
    cmake \
    git \
    wget \
    curl \
    libgl1-mesa-dev \
    libxkbcommon-x11-0 \
    libdbus-1-dev \
    libx11-dev \
    p7zip-full \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-tools-dev-tools \
    qt6-base-dev-tools \
    qt6-declarative-dev \
    qt6-serialport-dev

# Qt 6.8.3'i indir ve aç
WORKDIR /tmp
RUN wget https://download.qt.io/development_releases/qt/6.8/6.8.3/qt6.8.3-linux-x64.7z \
    && 7z x qt6.8.3-linux-x64.7z -o${QT_DIR} \
    && rm qt6.8.3-linux-x64.7z

ENV PATH="${QT_DIR}/6.8.3/gcc_64/bin:$PATH"
ENV CMAKE_PREFIX_PATH="${QT_DIR}/6.8.3/gcc_64/lib/cmake"

# Projeyi kopyala ve build et
WORKDIR /app
COPY . .

RUN cmake -B build -S . -DCMAKE_BUILD_TYPE=Release \
    && cmake --build build --parallel $(nproc)

CMD ["/bin/bash"]
