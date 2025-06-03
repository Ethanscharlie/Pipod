cmake_minimum_required(VERSION 4.0)
project(Pipod)

set(CMAKE_CXX_STANDARD 20)

set(SIM ON)
set(TESTING OFF)

find_package(GTest REQUIRED)
find_package(SDL2 REQUIRED)
enable_testing()

set(VLCLIB_LOC "/usr/lib/libvlc.so")
if (NOT ${SIM})
        set(VLCLIB_LOC "/usr/lib/arm-linux-gnueabihf/libvlc.so")
endif ()

set(testingFiles)
if (${TESTING})
set(testingFiles
  tests/model/MediaManager.cpp
)
endif ()

add_executable(Pipod src/main.cpp
        src/model/MediaManager.cpp
        src/model/MediaManager.hpp
        src/view/DeviceIo.cpp
        src/view/DeviceIo.hpp
        src/view/Color.hpp
        src/view/SimIo.cpp
        src/view/SimIo.hpp
        ${testingFiles}
)

target_link_libraries(Pipod PRIVATE
        GTest::gtest_main
        ${VLCLIB_LOC}
        SDL2::SDL2
)

target_include_directories(Pipod PRIVATE
        include/vlcpp
)


if (${TESTING})
  gtest_discover_tests(Pipod)
endif ()
