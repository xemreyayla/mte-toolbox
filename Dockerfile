# Ubuntu 24.04 tabanlı bir imaj kullanın
FROM ubuntu:24.04

# Apt'nin etkileşimli olmayan modda çalışmasını sağlayın
ENV DEBIAN_FRONTEND=noninteractive

# Gerekli araçları ve Qt dışındaki sistem bağımlılıklarını kurun.
# Bu paketler, uygulamanızın veya Qt'nin kendisinin ihtiyaç duyduğu temel sistem kütüphaneleridir.
# 'p7zip-full' Qt arşivlerini açmak için gereklidir.
RUN apt update && apt upgrade -y && \
    apt install -y \
    build-essential \
    cmake \
    git \
    wget \
    tar \
    xz-utils \
    p7zip-full \
    libgl1 \
    libglx-mesa0 \
    libegl1-mesa \
    libxkbcommon0 \
    libfontconfig1 \
    libx11-6 \
    libglib2.0-0 \
    libdbus-1-3 \
    libfreetype6 \
    libzstd1 \
    libexpat1 \
    libxcb1 \
    libpcre2-8-0 \
    libbz2-1.0 \
    libpng16-16 \
    libbrotli1 \
    libsystemd0 \
    libbsd0 \
    libcap2 \
    libgcrypt20 \
    liblz4-1 \
    liblzma5 \
    libmd0 \
    libgpg-error0 && \
    rm -rf /var/lib/apt/lists/*

# Qt kurulumu için dizin oluşturun
RUN mkdir -p /opt/Qt/6.8.1/gcc_64

# Qt 6.8.1 modüllerini indirin ve çıkarın.
# Bu URL'ler, Qt 6.8.1'in (2024-05-09 tarihli gcc_64 anlık görüntüsü) doğrudan indirme bağlantılarıdır.
# Farklı bir anlık görüntü veya mimari kullanıyorsanız bu URL'leri ayarlamanız gerekebilir.
# '7z x -so -si -o' komutu, arşivi standart girdiden okuyup belirtilen dizine çıkarır.
RUN wget -qO- https://download.qt.io/online/qtsdkrepository/linux_x64/desktop/qt6_681/qt.qt6.681.gcc_64/qtbase-6.8.1-0-202405090740-gcc_64.7z | 7z x -so -si -o/opt/Qt/6.8.1/gcc_64 && \
    wget -qO- https://download.qt.io/online/qtsdkrepository/linux_x64/desktop/qt6_681/qt.qt6.681.gcc_64/qtserialport-6.8.1-0-202405090740-gcc_64.7z | 7z x -so -si -o/opt/Qt/6.8.1/gcc_64 && \
    wget -qO- https://download.qt.io/online/qtsdkrepository/linux_x64/desktop/qt6_681/qt.qt6.681.gcc_64/qttools-6.8.1-0-202405090740-gcc_64.7z | 7z x -so -si -o/opt/Qt/6.8.1/gcc_64

# Qt için ortam değişkenlerini ayarlayın.
# CMAKE_PREFIX_PATH, CMake'in Qt kurulumunu bulmasını sağlar.
# PATH, Qt araçlarının (qmake, moc, uic) bulunmasını sağlar.
# LD_LIBRARY_PATH, uygulamanın çalışma zamanında Qt kütüphanelerini bulmasını sağlar.
# QT_QPA_PLATFORM_PLUGIN_PATH, Qt'nin grafik arayüz eklentilerini bulmasını sağlar.
ENV QT_INSTALL_DIR=/opt/Qt/6.8.1/gcc_64
ENV CMAKE_PREFIX_PATH=$QT_INSTALL_DIR/lib/cmake
ENV PATH=$QT_INSTALL_DIR/bin:$PATH
ENV LD_LIBRARY_PATH=$QT_INSTALL_DIR/lib:$LD_LIBRARY_PATH
ENV QT_QPA_PLATFORM_PLUGIN_PATH=$QT_INSTALL_DIR/plugins/platforms

# Çalışma dizinini ayarlayın ve proje dosyalarını kopyalayın
WORKDIR /app
COPY . .

# LICENSE.txt dosyasının varlığını kontrol edin (önceki Dockerfile'ınızdan)
RUN echo "--- Checking LICENSE.txt ---" && \
    if [ -f "LICENSE.txt" ]; then echo "✅ LICENSE.txt bulundu."; else echo "❌ LICENSE.txt eksik!"; exit 1; fi

# Uygulamayı derleyin ve .deb paketini oluşturun
RUN mkdir -p build && \
    cd build && \
    # CMake'in özel Qt kurulumunu kullandığından emin olun
    cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH && \
    make -j$(nproc) && \
    make install DESTDIR=install && \
    \
    # Qt çalışma zamanı kütüphanelerini ve eklentilerini .deb paketine dahil etmek için kopyalayın.
    # Bu, .deb paketini Qt açısından kendi kendine yeterli hale getirir.
    # Kütüphaneler /usr/local/lib altına, eklentiler /usr/local/lib/qt6/plugins/platforms altına kopyalanır.
    cp -r $QT_INSTALL_DIR/lib/*.so* install/usr/local/lib/ && \
    mkdir -p install/usr/local/lib/qt6/plugins/platforms && \
    cp -r $QT_INSTALL_DIR/plugins/platforms/*.so install/usr/local/lib/qt6/plugins/platforms/ && \
    \
    # CPack'i çalıştırarak .deb paketini oluşturun. Kopyalanan Qt kütüphaneleri pakete dahil edilecektir.
    cpack -G DEB && \
    # Oluşturulan .deb dosyasını /app dizinine taşıyın
    mv mte-toolbox-1.0.4-Linux.deb /app/