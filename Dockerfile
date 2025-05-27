# --- Builder Aşaması ---
FROM ubuntu:24.04 AS builder

# Gerekli bağımlılıklar
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    python3-pip \
    p7zip-full \
    wget \
    git \
    && rm -rf /var/lib/apt/lists/*

# aqtinstall kurulumu
RUN pip install -U pip && pip install aqtinstall

# Qt kurulumu
ENV QT_INSTALL_DIR=/opt/Qt
RUN python3 -m aqt install-qt linux desktop 6.8.0 linux_gcc_64 -m all --outputdir ${QT_INSTALL_DIR}

# Qt binary yolunu ayarla
ENV PATH="${QT_INSTALL_DIR}/6.8.0/gcc_64/bin:$PATH"
ENV LD_LIBRARY_PATH="${QT_INSTALL_DIR}/6.8.0/gcc_64/lib:$LD_LIBRARY_PATH}"

# Proje klasörü ve derleme
WORKDIR /app
COPY . /app
RUN cmake -B build -S . -DCMAKE_PREFIX_PATH=${QT_INSTALL_DIR}/6.8.0/gcc_64
RUN cmake --build build

# --- Çalışma Zamanı Aşaması ---
FROM ubuntu:24.04

# Çalışma zamanı bağımlılıkları
RUN apt-get update && apt-get install -y --no-install-recommends \
    libgl1-mesa-glx \
    libxcb-xinerama0 \
    libxkbcommon-x11-0 \
    libfontconfig1 \
    libx11-6 \
    libxext6 \
    libxrender1 \
    libxcb-render0 \
    libxcb-shm0 \
    libxcb-image0 \
    libxcb-keysyms1 \
    libxcb-icccm4 \
    libxcb-sync1 \
    libxcb-xfixes0 \
    libxcb-randr0 \
    libxcb-shape0 \
    libxcb-util1 \
    libxcb-xkb1 \
    libxkbcommon0 \
    libxcomposite1 \
    libxdamage1 \
    libxfixes3 \
    libxrandr2 \
    libxcursor1 \
    libxi6 \
    libxinerama1 \
    libxkbfile1 \
    libxmuu1 \
    libxtst6 \
    libudev1 \
    libglib2.0-0 \
    libdbus-1-3 \
    libmd4c0 \
    zlib1g \
    libicu74 \
    libdouble-conversion3 \
    libb2-1 \
    libpcre2-16-0 \
    libzstd1 \
    libcap2 \
    libexpat1 \
    libpcre2-8-0 \
    libgraphite2-3 \
    libbz2-1.0 \
    libbrotli1 \
    libgomp1 \
    libsystemd0 \
    libbsd0 \
    libgcrypt20 \
    liblz4-1 \
    liblzma5 \
    libmd0 \
    libgpg-error0 \
    && rm -rf /var/lib/apt/lists/*

# Ortam değişkenleri
ENV QT_RUNTIME_DIR=/opt/Qt/6.8.0/gcc_64
ENV LD_LIBRARY_PATH="${QT_RUNTIME_DIR}/lib:$LD_LIBRARY_PATH"
ENV QT_QPA_PLATFORM_PLUGIN_PATH="${QT_RUNTIME_DIR}/plugins/platforms"
ENV QT_PLUGIN_PATH="${QT_RUNTIME_DIR}/plugins"

# Qt çalışma zamanı kütüphanelerini ve pluginlerini kopyala
COPY --from=builder ${QT_RUNTIME_DIR}/lib ${QT_RUNTIME_DIR}/lib
COPY --from=builder ${QT_RUNTIME_DIR}/plugins ${QT_RUNTIME_DIR}/plugins
COPY --from=builder ${QT_RUNTIME_DIR}/translations ${QT_RUNTIME_DIR}/translations
COPY --from=builder ${QT_RUNTIME_DIR}/qml ${QT_RUNTIME_DIR}/qml

# Derlenmiş uygulamayı kopyala
COPY --from=builder /app/build/mte-toolbox /usr/local/bin/mte-toolbox

# Başlatma komutu
CMD ["/usr/local/bin/mte-toolbox"]
