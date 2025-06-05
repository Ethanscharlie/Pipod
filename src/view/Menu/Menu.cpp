//
// Created by ethanscharlie on 6/5/25.
//

#include "Menu.hpp"

namespace View {
namespace Menu {
    Menu::Menu(IO::DeviceIO *deviceIO, Model::MediaManager *mediaManager): deviceIO(deviceIO), mediaManager(mediaManager) {}
} // Menu
} // View