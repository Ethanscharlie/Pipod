cmake_minimum_required(VERSION 4.0)
project(Pipod)

set(CMAKE_CXX_STANDARD 20)

set(SIM ON)

find_package(GTest REQUIRED)
enable_testing()

set(VLCLIB_LOC "/usr/lib/libvlc.so")
if (NOT ${SIM})
        set(VLCLIB_LOC "/usr/lib/arm-linux-gnueabihf/libvlc.so")
endif ()

add_executable(Pipod src/main.cpp
        src/model/MediaManager.cpp
        src/model/MediaManager.hpp
        tests/model/MediaManager.cpp
        src/view/DeviceIo.cpp
        src/view/DeviceIo.hpp
        src/view/Color.hpp
)

target_link_libraries(Pipod PRIVATE
        GTest::gtest_main
        ${VLCLIB_LOC}
)

target_include_directories(Pipod PRIVATE
        include/vlcpp
)

gtest_discover_tests(Pipod)
