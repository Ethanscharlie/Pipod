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


# Hardware not libs
set(hardwareFiles)
if (NOT ${SIM})
  set(hardwareFiles
    include/1n44/Config/DEV_Config.cpp
    include/1n44/Fonts/font12.cpp
    include/1n44/Fonts/font16.cpp
    include/1n44/Fonts/font20.cpp
    include/1n44/Fonts/font24.cpp
    include/1n44/Fonts/font48.cpp
    include/1n44/Fonts/font50.cpp
    include/1n44/Fonts/font8.cpp
    include/1n44/GUI/GUI_BMP.cpp
    include/1n44/GUI/GUI_Paint.cpp
    include/1n44/GUI/KEY_APP.cpp
    include/1n44/LCD/LCD_1in44.cpp
  )
endif()

add_executable(Pipod src/main.cpp
        src/model/MediaManager.cpp
        src/model/MediaManager.hpp
        src/view/DeviceIo.cpp
        src/view/DeviceIo.hpp
        src/view/Color.hpp
        src/view/SimIo.cpp
        src/view/SimIo.hpp
        ${testingFiles}
        ${hardwareFiles}
)

target_link_libraries(Pipod PRIVATE
        GTest::gtest_main
        ${VLCLIB_LOC}
)

target_include_directories(Pipod PRIVATE
        include/vlcpp
)

# hardware specific libs and includes
if (${SIM})
target_link_libraries(Pipod PRIVATE
        SDL2::SDL2
)
else()
  target_link_libraries(piphone PRIVATE 
    lgpio
  )

  target_compile_definitions(piphone PRIVATE 
    -DUSE_DEV_LIB 
  )

  target_include_directories(Pipod PRIVATE
    include/1n44/Config
    include/1n44/Fonts
    include/1n44/GUI
    include/1n44/LCD
  )
endif()


if (${TESTING})
  gtest_discover_tests(Pipod)
endif ()

