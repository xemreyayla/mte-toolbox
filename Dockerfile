# 1. Build stage
FROM ubuntu:24.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

# Gerekli paketleri kur
RUN apt update && \
    apt install -y curl libicu74 libicu-dev cmake build-essential \
    qt6-base-dev qt6-base-dev-tools qt6-base-private-dev \
    qt6-tools-dev qt6-tools-dev-tools qt6-serialport-dev \
    file dpkg-dev fakeroot lintian && \
    rm -rf /var/lib/apt/lists/*

# Proje dizinine geç
WORKDIR /app

# Proje dosyalarını konteynıra kopyala
COPY . .

# Build ve .deb paket üretimi
RUN mkdir -p build && cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    make -j$(nproc) && \
    make install DESTDIR=install && \
    cpack -G DEB && \
    echo "--- Paketleme tamamlandı, mevcut .deb dosyaları:" && \
    ls -lh *.deb

# Paket adını dışa aktaran bir dosya oluştur (CI için)
RUN cd build && \
    ls *.deb > /tmp/debfile.txt

# 2. Final stage - sadece runtime için (isteğe bağlı)
FROM ubuntu:24.04 AS final

ENV DEBIAN_FRONTEND=noninteractive
WORKDIR /app

# Build aşamasında üretilen .deb paketini kopyala
COPY --from=builder /app/build/*.deb ./

# Uygulamayı sisteme kur
RUN apt update && \
    dpkg -i ./*.deb || apt install -fy && \
    rm -rf /var/lib/apt/lists/*

# Uygulamanın giriş noktası
CMD ["/usr/bin/mte-toolbox"]
