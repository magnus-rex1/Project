cmake_minimum_required(VERSION 3.30)
project(Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(APP_NAME ${PROJECT_NAME})

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

set(SOURCES
    src/main.cpp
    src/calculatorform.cpp
    src/calculatorform.hpp
    src/mainwindow.ui
)

message(STATUS "source: ${CMAKE_CURRENT_SOURCE_DIR}")

qt_add_executable(
    ${APP_NAME}
    ${SOURCES}
)

set_target_properties(${APP_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(${APP_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

# install(TARGETS ${APP_NAME})



