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

WORKDIR /app

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
        \
        # --- HATA AYIKLAMA BAŞLANGICI ---
        # CPack çalıştıktan sonra mevcut dizindeki dosyaları listele (burası /app/build olmalı)
        echo "--- DEBUG: Files in current directory (/app/build) after cpack ---" && \
        ls -l . && \
        \
        # CPack çıktısında belirtilen olası mutlak yolu kontrol et (/src/build)
        echo "--- DEBUG: Files in /src/build (absolute path from CPack output) ---" && \
        ls -l /src/build/ || true && \
        \
        # .deb dosyasını /app/ dizinine taşı (mevcut dizinden)
        mv mte-toolbox-1.0.4-Linux.deb /app/ && \
        \
        # Taşıma işleminden sonra /app/ dizinindeki dosyanın varlığını doğrula
        echo "--- DEBUG: Files in /app/ after mv ---" && \
        ls -l /app/mte-toolbox-1.0.4-Linux.deb && \
        # --- HATA AYIKLAMA SONU ---
        \
        true # Sadece son komutun her zaman başarılı olmasını sağlamak için
    
