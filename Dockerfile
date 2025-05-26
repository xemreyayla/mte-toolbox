# 1. Build stage
FROM ubuntu:24.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && \
    apt install -y curl libicu74 libicu-dev cmake build-essential \
    qt6-base-dev qt6-base-dev-tools qt6-base-private-dev \
    qt6-tools-dev qt6-tools-dev-tools qt6-serialport-dev \
    file dpkg-dev fakeroot lintian && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

# CMake yapılandırma ve derleme
RUN mkdir -p build && cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    make -j$(nproc) && \
    make install DESTDIR=install && \
    echo "--- make install tamamlandı. 'install/' dizininin içeriği:" && \
    ls -lR install/ || echo "make install sonrası 'install/' dizini listelenemedi veya boş."

# CPack ile .deb paketi oluşturma
# Bu adım, bir önceki adımdan ayrıldı ki çıktıyı daha net görelim
RUN cd build && \
    echo "--- CPack DEB paketini oluşturuyor ---" && \
    cpack -G DEB && \
    echo "--- CPack sonrası /app/build/ dizininin içeriği (mevcut dizin) ---" && \
    ls -l || echo "CPack sonrası /app/build/ dizini listelenemedi veya boş." && \
    echo "--- TÜM SİSTEMDE '.deb' DOSYASI ARAMASI BAŞLIYOR ---" && \
    find / -name "mte-toolbox_*.deb" 2>/dev/null || echo "find komutu hata verdi veya .deb dosyası bulunamadı." && \
    echo "--- BUILD AŞAMASI HATA AYIKLAMA SONU ---"

# 2. Final stage (bu kısımda değişiklik yok, .deb dosyasının yolunu bulduktan sonra burayı düzelteceğiz)
FROM ubuntu:24.04 AS final

ENV DEBIAN_FRONTEND=noninteractive

WORKDIR /app

# .deb dosyasının yolunu bulduktan sonra burayı güncelleyeceğiz
COPY --from=builder /app/build/mte-toolbox_*.deb ./

RUN apt update && \
    dpkg -i mte-toolbox_*.deb || apt install -fy && \
    rm -rf /var/lib/apt/lists/*

CMD ["/usr/local/bin/mte-toolbox"]