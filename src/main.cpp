#include <csignal>
#include <gtest/gtest.h>
#include <iostream>

#include "model/MediaManager.hpp"
#include "view/DeviceIo.hpp"
#include "view/SimIo.hpp"

int main(int argc, char **argv) {
  // testing::InitGoogleTest(&argc, argv);
  // return RUN_ALL_TESTS();

  View::SimIO simIO = View::SimIO();
  View::DeviceIO *deviceIO = &simIO;
  deviceIO->isButtonDown();

  while (true) {
    signal(SIGINT, [](int s) { std::exit(1); });
  }
}
