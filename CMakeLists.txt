cmake_minimum_required(VERSION 3.16)

# Proje ve versiyon ayarları (git tag’den çekme)
execute_process(
    COMMAND git describe --tags --abbrev=0
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_TAG
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
)

if(GIT_TAG)
    message(STATUS "Git tag found: ${GIT_TAG}")
    string(REGEX REPLACE "^v" "" PROJECT_VERSION_STRING ${GIT_TAG})
else()
    message(STATUS "No git tag found, using default version 1.0.4")
    set(PROJECT_VERSION_STRING "1.0.4")
endif()

project(mte-toolbox VERSION ${PROJECT_VERSION_STRING} LANGUAGES CXX)

# C++ standart ve Qt otomatik işlemler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Eğer dışarıdan Qt'nin kurulu olduğu yol verilmezse uyarı ver
if(NOT DEFINED CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH tanımlı değil! Qt 6.8 kütüphaneleri bulunamayabilir.")
endif()

# Qt modüllerini bul
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets SerialPort DBus)

# Kaynak dosyalar
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

qt_add_executable(mte-toolbox MANUAL_FINALIZATION ${PROJECT_SOURCES})

# Kütüphaneler bağla
target_link_libraries(mte-toolbox PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::SerialPort
    Qt6::DBus
)

# version.h dosyasını oluştur ve include et
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/version.h
    @ONLY
)
target_include_directories(mte-toolbox PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# --- RPATH AYARLARI ---

# Qt'nin lib dizinine göre çalışma zamanı kütüphane arama yolunu ayarla
if(DEFINED Qt6_DIR)
    get_filename_component(QtLibDir "${Qt6_DIR}" DIRECTORY)  # bir üst dizin (cmake)
    get_filename_component(QtLibDir "${QtLibDir}" DIRECTORY) # iki üst dizin (lib)

    message(STATUS "RPATH olarak Qt lib dizini ayarlanıyor: ${QtLibDir}")

    set_target_properties(mte-toolbox PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "${QtLibDir}"
        INSTALL_RPATH_USE_LINK_PATH TRUE
    )
else()
    message(WARNING "Qt6_DIR tanımlı değil, RPATH ayarı yapılmadı!")
endif()

# Kurulum yolu
set(CMAKE_INSTALL_PREFIX /usr)
include(GNUInstallDirs)

install(TARGETS mte-toolbox
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# MacOS özel ayarları (Linux için etkisiz)
set_target_properties(mte-toolbox PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
)

# CPack ayarları (DEB paketi için)
include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "mte-toolbox")
set(CPACK_PACKAGE_VENDOR "Mehmet Emre Yayla")
set(CPACK_PACKAGE_CONTACT "mehmetemreyayla@gmail.com")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "mte-toolbox - Qt Based Serial Port Connection App")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE.txt")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Mehmet Emre Yayla")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqt6core6, libqt6gui6, libqt6widgets6, libqt6serialport6, libqt6dbus6")

include(CPack)

qt_finalize_executable(mte-toolbox)
