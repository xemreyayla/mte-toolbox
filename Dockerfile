# --- Builder Aşaması ---
# Uygulamanın derlenmesi için gerekli tüm araçları ve Qt bağımlılıklarını içerir.
FROM ubuntu:22.04 AS builder

# Gerekli sistem bağımlılıklarını ve aqtinstall için Python'ı kurun.
# p7zip-full, aqtinstall'ın Qt arşivlerini çıkarması için gereklidir.
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    python3-pip \
    p7zip-full \
    wget \
    git \
    && rm -rf /var/lib/apt/lists/*

# aqtinstall'ı kurun.
RUN pip install -U pip && pip install aqtinstall

# Qt kurulum dizinini tanımlayın.
ENV QT_INSTALL_DIR=/opt/Qt

# aqtinstall kullanarak belirli bir Qt sürümünü kurun.
# ldd çıktınızda Qt 6.8 bağımlılığı görüldüğü için 6.8.0 sürümü kullanılmıştır.
# Ubuntu 22.04 üzerinde Qt 6.8'in bazı ABI uyumsuzlukları yaşayabileceği unutulmamalıdır.
# Eğer sorun yaşarsanız, Ubuntu 24.04 gibi daha yeni bir temel imaja geçmeyi düşünebilirsiniz.
RUN python3 -m aqt install-qt linux desktop 6.8.0 linux_gcc_64 -m all --outputdir ${QT_INSTALL_DIR}

# Derleme için gerekli Qt ortam değişkenlerini ayarlayın.
ENV PATH="${QT_INSTALL_DIR}/6.8.0/gcc_64/bin:$PATH"
ENV LD_LIBRARY_PATH="${QT_INSTALL_DIR}/6.8.0/gcc_64/lib:$LD_LIBRARY_PATH"

# Uygulama kaynak kodunu kopyalayın ve derleyin.
# Projenizin kök dizininde bir CMakeLists.txt dosyası olduğunu varsayıyoruz.
WORKDIR /app
COPY . /app

# CMake ile derleme dizinini oluşturun ve uygulamayı derleyin.
# -DCMAKE_PREFIX_PATH, CMake'in Qt'yi bulmasını sağlar.
RUN cmake -B build -S. -DCMAKE_PREFIX_PATH=${QT_INSTALL_DIR}/6.8.0/gcc_64
RUN cmake --build build

# --- Çalışma Zamanı Aşaması ---
# Sadece uygulamanın çalışması için gerekli minimum bağımlılıkları içeren daha küçük bir imaj oluşturun.
FROM ubuntu:22.04

# ldd çıktınızdaki bağımlılıklara göre gerekli çalışma zamanı kütüphanelerini kurun.
# libicu74 yerine Ubuntu 22.04'te bulunan libicu70 kullanılmıştır.
# Eğer uygulamanız libicu74'e kesinlikle ihtiyaç duyuyorsa, Ubuntu 24.04 gibi daha yeni bir temel imaja geçmeniz gerekebilir.
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
    libicu70 \
    libdouble-conversion3 \
    libb2-1 \
    libpcre2-16-0 \
    libzstd1 \
    libcap2 \
    libexpat1 \
    libpcre2-8-0 \
    libgraphite2-3 \
    libbz2-1.0 \
    libbrotlidec1 \
    libbrotlicommon1 \
    libgomp1 \
    libsystemd0 \
    libbsd0 \
    libgcrypt20 \
    liblz4-1 \
    liblzma5 \
    libmd0 \
    libgpg-error0 \
    && rm -rf /var/lib/apt/lists/*

# Çalışma zamanı için gerekli Qt ortam değişkenlerini ayarlayın.
# Bu, uygulamanın Qt kütüphanelerini bulmasını sağlar.
ENV LD_LIBRARY_PATH="/opt/Qt/6.8.0/gcc_64/lib:$LD_LIBRARY_PATH"

# Builder aşamasından derlenmiş uygulama ikili dosyalarını ve gerekli Qt çalışma zamanı kütüphanelerini kopyalayın.
# 'mte-toolbox' sizin uygulamanızın çalıştırılabilir adıdır.
COPY --from=builder /opt/Qt/6.8.0/gcc_64/lib /opt/Qt/6.8.0/gcc_64/lib
COPY --from=builder /app/build/mte-toolbox /usr/local/bin/mte-toolbox

# Konteyner başlatıldığında uygulamanın nasıl çalıştırılacağını tanımlayın.
# 'mte-toolbox' sizin uygulamanızın çalıştırılabilir adıdır.
CMD ["/usr/local/bin/mte-toolbox"]