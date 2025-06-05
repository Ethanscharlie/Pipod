//
// Created by ethanscharlie on 6/5/25.
//

#ifndef MENU_HPP
#define MENU_HPP
#include "../../model/MediaManager.hpp"
#include "../IO/DeviceIo.hpp"

namespace View {
namespace Menu {

class Menu {
protected:
    IO::DeviceIO* deviceIO = nullptr;
    Model::MediaManager* mediaManager = nullptr;

public:
    Menu(IO::DeviceIO* deviceIO, Model::MediaManager* mediaManager);

    virtual void render() = 0;
};

} // Menu
} // View

#endif //MENU_HPP
