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

# Build ve .deb üretimi
RUN mkdir /build && \
    cmake -S /app -B /build -DCMAKE_BUILD_TYPE=Release && \
    cmake --build /build --parallel && \
    cmake --install /build --prefix /build/install && \
    cd /build && cpack -G DEB && \
    echo "--- Paketleme tamamlandı, mevcut .deb dosyaları:" && ls -lh /build/*.deb

# Paket adını dışa aktaran bir dosya oluştur (CI için)
# 'build' dizini /build'da olduğu için mutlak yol kullanıldı.
RUN ls /build/*.deb > /build/debfile.txt

# 2. Final stage - sadece runtime
FROM ubuntu:24.04 AS final

ENV DEBIAN_FRONTEND=noninteractive
WORKDIR /app

# .deb paketini kopyala
# debfile.txt dosyasını da kopyalamak isterseniz, buraya ekleyebilirsiniz:
# COPY --from=builder /build/debfile.txt ./
COPY --from=builder /build/*.deb ./

# Uygulamayı kur
RUN apt update && \
    dpkg -i ./*.deb || apt install -fy && \
    rm -rf /var/lib/apt/lists/*

# Uygulamanın giriş noktası
CMD ["/usr/bin/mte-toolbox"]
