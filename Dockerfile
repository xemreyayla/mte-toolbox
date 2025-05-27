# Dockerfile
FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

# Gerekli sistem bağımlılıkları
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    git \
    wget \
    unzip \
    libgl1-mesa-dev \
    libx11-dev \
    libudev-dev \
    libxcb1-dev \
    libxkbcommon-dev \
    libdbus-1-dev \
    libfreetype6-dev \
    libfontconfig1-dev \
    libxext-dev \
    libxrender-dev \
    libxrandr-dev \
    zlib1g-dev \
    qt6-base-dev \
    qt6-base-dev-tools \
    qt6-tools-dev \
    qt6-tools-dev-tools \
    qt6-l10n-tools \
    qt6-declarative-dev \
    qt6-serialport-dev

# Qt 6.8 yüklenecek dizin
ENV QT_VERSION=6.8.0
ENV QT_INSTALL_DIR=/opt/Qt/${QT_VERSION}/gcc_64

# Qt 6.8 indir ve kur
RUN wget -O qt.run https://download.qt.io/official_releases/qt/6.8/6.8.0/qt-opensource-linux-x64-6.8.0.run && \
    chmod +x qt.run && \
    ./qt.run --platform minimal --script install-qt-noninteractive.qs && \
    rm qt.run

# Qt yolunu sistem PATH'e ekle
ENV PATH="${QT_INSTALL_DIR}/bin:${PATH}"
ENV LD_LIBRARY_PATH="${QT_INSTALL_DIR}/lib:${LD_LIBRARY_PATH}"

WORKDIR /app
COPY . .

RUN mkdir -p build && cd build && cmake .. && make

CMD ["./build/mte-toolbox"]
