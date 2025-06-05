//
// Created by ethanscharlie on 6/5/25.
//

#ifndef IOTESTINGMENU_HPP
#define IOTESTINGMENU_HPP
#include "Menu.hpp"

namespace View {
namespace Menu {

class IOTestingMenu : public Menu {
    Color getColorOfInputTest(bool isButtonDown);
    void drawInputTest();

public:
    explicit IOTestingMenu(IO::DeviceIO *deviceIO, Model::MediaManager* mediaManager);

    void render() override;
};

} // Menu
} // View

#endif //IOTESTINGMENU_HPP
