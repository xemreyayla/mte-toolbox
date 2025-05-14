cmake_minimum_required(VERSION 3.16)

project(mte-toolbox VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED
    COMPONENTS
    Core
    Gui
    Widgets
    SerialPort
    DBus
)


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

set_target_properties(mte-toolbox PROPERTIES
    WIN32_EXECUTABLE TRUE
)

# macOS özel durumlar
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

install(TARGETS mte-toolbox DESTINATION bin)

qt_finalize_executable(mte-toolbox)

include(InstallRequiredSystemLibraries)

# CPack ayarları
set(CPACK_PACKAGE_NAME "mte-toolbox")
set(CPACK_PACKAGE_VENDOR "Mehmet Emre Yayla")
set(CPACK_PACKAGE_CONTACT "mehmetemreyayla@gmail.com")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "mte-toolbox - Qt Based Serial Port Connection App")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)



if(WIN32)
    set(CPACK_GENERATOR "NSIS;ZIP")
    set(CPACK_NSIS_DISPLAY_NAME "mte-toolbox")
    set(CPACK_NSIS_PACKAGE_NAME "mte-toolbox Installer")
    set(CPACK_NSIS_EXECUTABLES_DIRECTORY ".")
    set(CPACK_NSIS_INSTALLED_ICON_NAME "bin\\mte-toolbox.exe")
else()
    set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Mehmet Emre Yayla")
    set(CPACK_GENERATOR "DEB")
endif()

include(CPack)