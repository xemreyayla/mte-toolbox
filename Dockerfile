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
    file \
    libxkbcommon-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src

COPY . /src

RUN echo "--- Listing contents of /src after COPY ---" && \
    ls -la /src/ && \
    echo "--- Verifying LICENSE.txt presence ---" && \
    if [ -f "/src/LICENSE.txt" ]; then echo "SUCCESS: LICENSE.txt IS in /src"; else echo "FAILURE: LICENSE.txt IS NOT in /src"; exit 1; fi

RUN mkdir build && cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    make -j$(nproc) && \
    make install && \
    cpack -G DEB

CMD ["/usr/local/bin/mte-toolbox"]
