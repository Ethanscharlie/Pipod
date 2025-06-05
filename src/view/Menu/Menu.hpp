//
// Created by ethanscharlie on 6/5/25.
//

#ifndef MENU_HPP
#define MENU_HPP
#include "../IO/DeviceIo.hpp"

namespace View {
namespace Menu {

class Menu {
protected:
    IO::DeviceIO* deviceIO = nullptr;
public:
    Menu(IO::DeviceIO* deviceIO) : deviceIO(deviceIO) {};

    virtual void render() = 0;
};

} // Menu
} // View

#endif //MENU_HPP
