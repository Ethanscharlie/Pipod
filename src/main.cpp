#include <csignal>
#include <gtest/gtest.h>

#include "model/MediaManager.hpp"
#include "view/DeviceIo.hpp"
#include "view/Color.hpp"

#ifdef SIM
#include "view/SimIo.hpp"
#else
#include "view/PiIO.hpp"
#endif // SIM

View::Color getColorOfInputTest(bool isButtonDown) {
  if (isButtonDown) {
    return {0, 255, 0};
  }

  return {255, 0, 0};
}

void drawInputTest(View::DeviceIO *deviceIO) {
  const std::pair<int, int> size = {20, 20};
  View::Color color = {255, 255, 255};

  color = getColorOfInputTest(deviceIO->isButton1Down());
  deviceIO->drawRect({10, 10}, size, color);

  color = getColorOfInputTest(deviceIO->isButton2Down());
  deviceIO->drawRect({40, 10}, size, color);

  color = getColorOfInputTest(deviceIO->isButton3Down());
  deviceIO->drawRect({70, 10}, size, color);
}

int main(int argc, char **argv) {
  // testing::InitGoogleTest(&argc, argv);
  // return RUN_ALL_TESTS();

#ifdef SIM
  View::SimIO io = View::SimIO();
#else
  View::PiIO io = View::PiIO();
#endif // SIM

  View::DeviceIO *deviceIO = &io;

  while (true) {
    signal(SIGINT, [](int s) { std::exit(1); });

    deviceIO->setDisplayColor({255, 255, 255});

    drawInputTest(deviceIO);

    deviceIO->refreshDisplay();
  }
}
