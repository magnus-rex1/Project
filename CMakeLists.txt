cmake_minimum_required(VERSION 3.30)
project(Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(APP_NAME ${PROJECT_NAME})

find_package(Qt6 REQUIRED COMPONENTS Core Gui UiTools Widgets)

qt_standard_project_setup()

set(SOURCES
    src/main.cpp
    # src/textfinder.cpp
    # src/textfinder.hpp
    src/songlist.cpp
    src/songlist.hpp
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
    Qt6::UiTools
    Qt6::Widgets
)

# Resources
set(text_finder_resource_files
    "forms/input.txt"
    "forms/textfinder.ui"
    "forms/songlist.ui"
    "forms/Darkeum/Darkeum.qss"
    "forms/Combinear/Combinear.qss"
    "forms/Takezo/Takezo.qss"
)

qt6_add_resources(${APP_NAME} "textfinder"
    PREFIX
        "/"
    FILES
        ${text_finder_resource_files}
)

# install(TARGETS ${APP_NAME})



