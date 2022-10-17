cmake_minimum_required(VERSION 3.5)

add_subdirectory(QCustomPlot-library-master)

project(calculator_oop VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#позволяет не указывать путь к файлам
include_directories(
  ${CMAKE_SOURCE_DIR}/controller
  ${CMAKE_SOURCE_DIR}/model
  ${CMAKE_SOURCE_DIR}/view
  ${CMAKE_SOURCE_DIR}/qcasomplot
)
set(CMAKE_AUTOUIC_SEARCH_PATHS forms)



find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)

set(CMAKE_PREFIX_PATH "/home/maksonaldo/Qt/6.4.0/gcc_64/lib/cmake")
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
set (ТОЛЬКО CMAKE_FIND_ROOT_PATH_MODE_PACKAGE)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        view/calculatorView.cpp
        view/calculatorView.h
        forms/calculatorView.ui
        controller/calculatorController.h
        controller/calculatorController.cpp
        model/calculatorModel.h
        model/calculatorModel.cpp
        model/calcCreditModel.h
        model/calcCreditModel.cpp
        view/graph.cpp
        view/graph.h
        forms/graph.ui
        qcasomplot/qcustomplot.cpp
        qcasomplot/qcustomplot.h
        view/calcCreditView.h
        view/calcCreditView.cpp
        forms/calcCreditView.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(calculator_oop
        view
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET calculator_oop APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(calculator_oop SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(calculator_oop
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(calculator_oop PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE qcustomplot)
target_compile_definitions(${PROJECT_NAME} PRIVATE QCUSTOMPLOT_USE_LIBRARY)

set_target_properties(calculator_oop PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(calculator_oop)
endif()
