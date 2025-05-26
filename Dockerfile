# 1. Build stage
FROM ubuntu:24.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

# Add curl for robustness (optional, but good practice)
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
    echo "--- Installed files list ---" && \
    ls -lR install/ && \
    echo "--- Running CPack ---" && \
    cpack -G DEB && \
    echo "--- Contents of /app/build/ after CPack ---" && \
    ls -l *.deb && \
    ls -l # Added to show all files in /app/build/
    

# 2. Final stage (with the previous fixes and a more robust copy)
FROM ubuntu:24.04 AS final

ENV DEBIAN_FRONTEND=noninteractive

WORKDIR /app

# Builder aşamasından .deb dosyasını kopyala
# DEB_FILE adının değişebileceğini düşünerek wildcard kullanmak önemli.
# CPack genellikle paket adını proje adından (mte-toolbox) ve versiyonundan oluşturur.
# `find` komutunu kullanarak dosyayı kesin bulalım.
COPY --from=builder /app/build/mte-toolbox_*.deb ./

# .deb paketini kur ve çalışma zamanı bağımlılıklarını yükle
# `apt install -fy` otomatik olarak bağımlılıkları çözer.
RUN apt update && \
    dpkg -i mte-toolbox_*.deb || apt install -fy && \
    rm -rf /var/lib/apt/lists/*

# Konteyner başlatıldığında çalışacak varsayılan komut
CMD ["/usr/local/bin/mte-toolbox"]