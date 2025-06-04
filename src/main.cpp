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

    deviceIO->setDisplayColor({255, 255, 255});

    for (int x = 10; x < 20; x++) {
      for (int y = 10; y < 20; y++) {
        deviceIO->setPixel({x, y}, {0, 100, 255});
      }
    }

    deviceIO->refreshDisplay();
  }
}
