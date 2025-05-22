cmake_minimum_required(VERSION 3.16)

project(mte-toolbox VERSION 1.0.4 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt6'yı bulur. Dockerfile'da ayarlanan CMAKE_PREFIX_PATH sayesinde doğru Qt 6.8.1 kurulumunu bulacaktır.
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets SerialPort DBus)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    utilities.cpp
    utilities.h
    utilities.ui
    configuration.cpp
    configuration.h
    configuration.ui
    deviceinfo.cpp
    deviceinfo.h
    deviceinfo.ui
)

qt_add_executable(mte-toolbox ${PROJECT_SOURCES} MANUAL_FINALIZATION)

target_link_libraries(mte-toolbox PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::SerialPort
    Qt6::DBus
)

set_target_properties(mte-toolbox PROPERTIES WIN32_EXECUTABLE TRUE)

if(APPLE AND Qt6Core_VERSION VERSION_LESS "6.1.0")
    set_target_properties(mte-toolbox PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER com.example.mte-toolbox
    )
endif()

set_target_properties(mte-toolbox PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
)

include(GNUInstallDirs)

install(TARGETS mte-toolbox
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Qt kütüphaneleri ve eklentileri Dockerfile'da manuel olarak kopyalandığı için
# burada ek bir install kuralına gerek yoktur.
# CPack, bu kopyalanan dosyaları paketleme sırasında otomatik olarak algılayacaktır.

qt_finalize_executable(mte-toolbox)

include(InstallRequiredSystemLibraries)

# CPack genel ayarları
set(CPACK_PACKAGE_NAME "mte-toolbox")
set(CPACK_PACKAGE_VENDOR "Mehmet Emre Yayla")
set(CPACK_PACKAGE_CONTACT "mehmetemreyayla@gmail.com")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "mte-toolbox - Qt Based Serial Port Connection App")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE.txt")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

# DEB üretimi için gerekli
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Mehmet Emre Yayla")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS OFF) # Otomatik bağımlılık algılamayı kapatın, çünkü Qt'yi biz kopyalıyoruz
# Sadece Qt dışındaki temel sistem bağımlılıklarını belirtin.
# Bu liste, uygulamanızın çalışması için kesinlikle gerekli olan ve Qt tarafından sağlanmayan kütüphanelerdir.
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6, libstdc++6, libgl1, libglx-mesa0, libegl1-mesa, libxkbcommon0, libfontconfig1, libx11-6, libglib2.0-0, libdbus-1-3, libfreetype6, libzstd1, libexpat1, libxcb1, libpcre2-8-0, libbz2-1.0, libpng16-16, libbrotli1, libsystemd0, libbsd0, libcap2, libgcrypt20, liblz4-1, liblzma5, libmd0, libgpg-error0")

include(CPack)