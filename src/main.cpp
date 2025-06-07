#include <csignal>
#include <gtest/gtest.h>

#include "model/MediaManager.hpp"
#include "view/IO/DeviceIo.hpp"
#include "view/Color.hpp"
#include "view/FontRenderer.hpp"
#include "view/Menu/BmpAndMediaTestingMenu.hpp"
#include "view/Menu/IoTestingMenu.hpp"
#include "view/Menu/Menu.hpp"

#ifdef SIM
#include "view/IO/SimIo.hpp"
#else
#include "view/PiIO.hpp"
#endif // SIM

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

  View::Menu::IOTestingMenu ioTestingMenu(deviceIO, &mediaManager);
  View::Menu::BmpAndMediaTestingMenu bmpAndMediaTestingMenu(deviceIO, &mediaManager);
  View::Menu::Menu *currentMenu = &ioTestingMenu;

  while (true) {
    signal(SIGINT, [](int s) { std::exit(1); });
    currentMenu->render();
    deviceIO->refreshDisplay();
  }
#endif
}
