FROM ubuntu:24.04 AS builder

RUN apt-get update && apt-get install -y \
    libgl1 \
    libglib2.0-0 \
    libglu1-mesa-dev \
    libx11-dev \
    libxext-dev \
    libxrandr-dev \
    libxrender-dev \
    libxi-dev \
    libxfixes-dev \
    libxinerama-dev \
    libxcursor-dev \
    libfontconfig1-dev \
    python3-venv \
    python3-pip \
    cmake \
    build-essential


# Sanal ortam oluştur ve aktif et
RUN python3 -m venv /opt/venv
ENV PATH="/opt/venv/bin:$PATH"

RUN pip install --upgrade pip && pip install aqtinstall

ENV QT_INSTALL_DIR=/opt/Qt

# Qt 6.7.3 sürümünü indir ve kur
RUN python3 -m aqt install-qt linux desktop 6.7.3 linux_gcc_64 -m all --outputdir ${QT_INSTALL_DIR}

ENV PATH="${QT_INSTALL_DIR}/6.7.3/gcc_64/bin:$PATH"
ENV LD_LIBRARY_PATH="${QT_INSTALL_DIR}/6.7.3/gcc_64/lib:$LD_LIBRARY_PATH"

WORKDIR /app
COPY . /app

RUN cmake -B build -S . -DCMAKE_PREFIX_PATH=${QT_INSTALL_DIR}/6.7.3/gcc_64
RUN cmake --build build
