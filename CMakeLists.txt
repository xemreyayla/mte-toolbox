cmake_minimum_required(VERSION 3.16)

# Git tag'den versiyon çekme bloğu buraya taşındı
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

# Proje tanımı tek bir kez ve dinamik versiyonla
project(mte-toolbox VERSION ${PROJECT_VERSION_STRING} LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INSTALL_PREFIX /usr)

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

qt_finalize_executable(mte-toolbox)

include(InstallRequiredSystemLibraries)

# --- version.h dosyası oluştur ---
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/version.h
  @ONLY
)

target_include_directories(mte-toolbox PRIVATE ${CMAKE_CURRENT_BINARY_DIR})


# CPack ile .deb paketi ayarları
set(CPACK_PACKAGE_NAME "mte-toolbox")
set(CPACK_PACKAGE_VENDOR "Mehmet Emre Yayla")
set(CPACK_PACKAGE_CONTACT "mehmetemreyayla@gmail.com")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "mte-toolbox - Qt Based Serial Port Connection App")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE.txt")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Mehmet Emre Yayla")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqt6core6, libqt6gui6, libqt6widgets6, libqt6serialport6")

include(InstallRequiredSystemLibraries)
include(CPack)

qt_finalize_executable(mte-toolbox)