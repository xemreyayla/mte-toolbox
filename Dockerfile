FROM ubuntu:24.04 AS builder

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    python3 \
    python3-pip \
    python3-venv \
    p7zip-full \
    wget \
    git \
    && rm -rf /var/lib/apt/lists/*

RUN python3 -m venv /opt/venv
ENV PATH="/opt/venv/bin:$PATH"

RUN pip install -U pip && pip install aqtinstall

ENV QT_INSTALL_DIR=/opt/Qt

RUN python3 -m aqt install-qt linux desktop 6.8.0 linux_gcc_64 -m all --outputdir ${QT_INSTALL_DIR}

ENV PATH="${QT_INSTALL_DIR}/6.8.0/gcc_64/bin:$PATH"
ENV LD_LIBRARY_PATH="${QT_INSTALL_DIR}/6.8.0/gcc_64/lib:$LD_LIBRARY_PATH"

WORKDIR /app
COPY . /app

RUN cmake -B build -S. -DCMAKE_PREFIX_PATH=${QT_INSTALL_DIR}/6.8.0/gcc_64
RUN cmake --build build
