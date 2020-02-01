cmake_minimum_required(VERSION 3.15)
project(qt-layout)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(QTL_EXEC qt-layout)
set(QTL_SOURCES
    main.cpp
    )

add_executable(${QTL_EXEC} ${QTL_SOURCES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

if(MSVC)
    target_compile_options(${QTL_EXEC} PRIVATE /WX /W4)
else(MSVC)
    target_compile_options(${QTL_EXEC} PRIVATE -Werror -Wall -Wextra -Wpedantic)
endif(MSVC)

find_package(Qt5Widgets 5.7 CONFIG REQUIRED)
target_link_libraries(${QTL_EXEC} PUBLIC Qt5::Widgets)
