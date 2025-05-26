# 1. Build stage
FROM ubuntu:24.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

# `curl`'ı ekledim, bu genellikle işe yarar
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
    echo "--- make install sonrası 'install/' dizininin içeriği ---" && \
    ls -lR install/ || echo "install/ dizini boş veya hata var" && \
    echo "--- CPack DEB paketini oluşturuyor ---" && \
    cpack -G DEB || echo "CPack hata verdi, paket oluşturulamadı" && \
    echo "--- CPack sonrası /app/build/ dizininin içeriği (mevcut dizin) ---" && \
    ls -l || echo "/app/build/ dizini listelenemedi" && \
    echo "--- CPack sonrası /app/ dizininin içeriği (üst dizin) ---" && \
    ls -l ../ || echo "/app/ dizini listelenemedi" && \
    echo "--- TÜM SİSTEMDE '.deb' DOSYASI ARAMASI BAŞLIYOR ---" && \
    find / -name "*.deb" 2>/dev/null || echo "find komutu hata verdi veya .deb dosyası bulunamadı" && \
    echo "--- BUILD AŞAMASI HATA AYIKLAMA SONU ---"

# 2. Final stage (şimdilik olduğu gibi kalsın, .deb dosyasının yolunu bulduktan sonra düzeltiriz)
FROM ubuntu:24.04 AS final

ENV DEBIAN_FRONTEND=noninteractive

WORKDIR /app

COPY --from=builder /app/build/*.deb ./

RUN apt update && \
    dpkg -i mte-toolbox_*.deb || apt install -fy && \
    rm -rf /var/lib/apt/lists/*

CMD ["/usr/local/bin/mte-toolbox"]