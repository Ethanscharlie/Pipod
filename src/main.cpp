#include <csignal>
#include <gtest/gtest.h>
#include <iostream>

#include "model/MediaManager.hpp"
#include "view/DeviceIo.hpp"

#ifdef SIM
#include "view/SimIo.hpp"
#else
#include "view/PiIO.hpp"
#endif // SIM

int main(int argc, char **argv) {
  // testing::InitGoogleTest(&argc, argv);
  // return RUN_ALL_TESTS();

#ifdef SIM
  View::SimIO io = View::SimIO();
#else
  View::PiIO io = View::PiIO();
#endif // SIM

  View::DeviceIO *deviceIO = &io;
  deviceIO->isButtonDown();

  while (true) {
    signal(SIGINT, [](int s) { std::exit(1); });

    if (deviceIO->isButtonDown()) {
      deviceIO->setDisplayColor({255, 0, 0});
    } else {
      deviceIO->setDisplayColor({0, 255, 0});
    }

    deviceIO->refreshDisplay();
  }
}
