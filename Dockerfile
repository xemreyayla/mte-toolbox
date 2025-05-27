FROM ubuntu:24.04

# Gerekli temel paketler
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
    libxcb1-dev \
    libxcb-xkb-dev \
    libfontconfig1 \
    libfreetype6 \
    libxext6 \
    libxrender1 \
    libxrandr2 \
    libxi6 \
    libxcursor1 \
    libxcomposite1 \
    libxdamage1 \
    libxtst6 \
    libxfixes3 \
    unzip \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

# Qt kurulumu için klasör
ENV QT_VERSION=6.8.3
ENV QT_DIR=/opt/Qt

# Qt Online Installer indir
WORKDIR /tmp
RUN wget https://download.qt.io/official_releases/online_installers/qt-unified-linux-x64-online.run \
    && chmod +x qt-unified-linux-x64-online.run

# Sessiz kurulum scripti
COPY install-qt-noninteractive.qs /tmp/install-qt-noninteractive.qs

# Sessiz Qt kurulumu
RUN ./qt-unified-linux-x64-online.run --platform minimal --script install-qt-noninteractive.qs

ENV PATH="${QT_DIR}/${QT_VERSION}/gcc_64/bin:$PATH"
ENV LD_LIBRARY_PATH="${QT_DIR}/${QT_VERSION}/gcc_64/lib:$LD_LIBRARY_PATH"

# Projenin bulunduğu dizine geç
WORKDIR /project
COPY . .

# Qt ile derleme
RUN cmake -B build -S . -DCMAKE_PREFIX_PATH=${QT_DIR}/${QT_VERSION}/gcc_64
RUN cmake --build build
