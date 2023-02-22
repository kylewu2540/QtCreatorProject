cmake_minimum_required(VERSION 3.5)

project(projectFive VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        homewindow.h homewindow.cpp homewindow.ui
        loginwindow.h loginwindow.cpp loginwindow.ui
        registerwindow.h registerwindow.cpp registerwindow.ui
        forgotpasswindow.h forgotpasswindow.cpp forgotpasswindow.ui
        resetpasswindow.h resetpasswindow.cpp resetpasswindow.ui
        user.h user.cpp
        Calculation.cpp
        Calculation.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(projectFive
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET projectFive APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(projectFive SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(projectFive
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(projectFive PRIVATE Qt${QT_VERSION_MAJOR}::Widgets  Qt6::Core
    Qt6::Sql
    ${MYSQL_LIBRARY})

set_target_properties(projectFive PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS projectFive
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(projectFive)
endif()

find_package(Qt6 COMPONENTS Core Sql REQUIRED)
find_package(Qt6Sql REQUIRED)
find_package(Qt6Core REQUIRED)

set(MYSQL_INCLUDE_DIR /usr/local/mysql/include)
set(MYSQL_LIBRARY /usr/local/mysql/lib/libmysqlclient.dylib)

target_include_directories(projectFive PRIVATE ${MYSQL_INCLUDE_DIR})
