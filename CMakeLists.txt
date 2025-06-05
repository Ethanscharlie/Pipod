cmake_minimum_required(VERSION 3.18)
project(Pipod)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SIM ON)
set(TESTING OFF)

find_package(GTest REQUIRED)
enable_testing()

set(VLCLIB_LOC "/usr/lib/libvlc.so")
if (NOT ${SIM})
        set(VLCLIB_LOC "/usr/lib/arm-linux-gnueabihf/libvlc.so")
endif ()

set(testingFiles)
if (${TESTING})
set(testingFiles
  tests/model/MediaManager.cpp
        tests/model/MusicManager.cpp
)
endif ()


# Hardware not libs
set(codeFiles)
if (${SIM})
  set(codeFiles
          src/view/IO/SimIo.cpp
          src/view/IO/SimIo.hpp
  )
else()
  set(codeFiles
          src/view/IO/PiIO.cpp
          src/view/IO/PiIO.hpp
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
        src/view/IO/DeviceIo.cpp
        src/view/IO/DeviceIo.hpp
        src/view/Color.hpp
        src/model/MusicManager.cpp
        src/model/MusicManager.hpp
        src/view/Menu/Menu.cpp
        src/view/Menu/Menu.hpp
        src/view/Menu/IoTestingMenu.cpp
        src/view/Menu/IoTestingMenu.hpp
        ${testingFiles}
        ${codeFiles}
)

target_link_libraries(Pipod PRIVATE
        GTest::gtest_main
        ${VLCLIB_LOC}
)

target_include_directories(Pipod PRIVATE
        include/vlcpp
        include/bmpp
)
if (${TESTING})
  target_compile_definitions(Pipod PRIVATE
          -DTESTING
  )
endif()

# hardware specific libs and includes
if (${SIM})
find_package(SDL2 REQUIRED)
target_link_libraries(Pipod PRIVATE
        SDL2::SDL2
)

target_compile_definitions(Pipod PRIVATE 
  -DSIM 
)
else()
  target_link_libraries(Pipod PRIVATE 
    lgpio
  )

  target_compile_definitions(Pipod PRIVATE 
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

