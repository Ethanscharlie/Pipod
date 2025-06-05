#include <csignal>
#include <gtest/gtest.h>

#include "model/MediaManager.hpp"
#include "view/IO/DeviceIo.hpp"
#include "view/Color.hpp"

#ifdef SIM
#include "view/IO/SimIo.hpp"
#else
#include "view/PiIO.hpp"
#endif // SIM

View::Color getColorOfInputTest(bool isButtonDown) {
  if (isButtonDown) {
    return {0, 255, 0};
  }

  return {255, 0, 0};
}

void drawInputTest(View::IO::DeviceIO *deviceIO) {
  const std::pair<int, int> size = {20, 20};
  View::Color color = {255, 255, 255};

  color = getColorOfInputTest(deviceIO->isJoystickUpDown());
  deviceIO->drawRect({30, 30}, size, color);

  color = getColorOfInputTest(deviceIO->isJoystickDownDown());
  deviceIO->drawRect({30, 80}, size, color);

  color = getColorOfInputTest(deviceIO->isJoystickRightDown());
  deviceIO->drawRect({50, 54}, size, color);

  color = getColorOfInputTest(deviceIO->isJoystickLeftDown());
  deviceIO->drawRect({10, 54}, size, color);

  color = getColorOfInputTest(deviceIO->isButton1Down());
  deviceIO->drawRect({40, 110}, size, color);

  color = getColorOfInputTest(deviceIO->isButton2Down());
  deviceIO->drawRect({70, 110}, size, color);

  color = getColorOfInputTest(deviceIO->isButton3Down());
  deviceIO->drawRect({100, 110}, size, color);
}

void playAnAudioFileForTesting(Model::MediaManager& mediaManager) {
  std::filesystem::path file = "../tests/res/audiotest.mp3";
  if (!std::filesystem::exists(file)) {
    throw std::logic_error("File does not exist");
  }

  mediaManager.loadFile(file);
  mediaManager.play();
}

int main(int argc, char **argv) {
#ifdef TESTING
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#else
#ifdef SIM
  View::IO::SimIO io = View::IO::SimIO();
#else
  View::PiIO io = View::PiIO();
#endif // SIM

  View::IO::DeviceIO *deviceIO = &io;
  Model::MediaManager mediaManager;
  playAnAudioFileForTesting(mediaManager);

  while (true) {
    signal(SIGINT, [](int s) { std::exit(1); });
    deviceIO->setDisplayColor({255, 255, 255});
    drawInputTest(deviceIO);
    deviceIO->refreshDisplay();
  }
#endif
}
