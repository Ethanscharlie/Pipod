//
// Created by ethanscharlie on 6/5/25.
//

#include "IoTestingMenu.hpp"

#include "../FontRenderer.hpp"

namespace View {
namespace Menu {

    Color IOTestingMenu::getColorOfInputTest(bool isButtonDown) {
        if (isButtonDown) {
            return {0, 255, 0};
        }

        return {255, 0, 0};
    }

    void IOTestingMenu::drawInputTest() {
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

    IOTestingMenu::IOTestingMenu(IO::DeviceIO *deviceIO, Model::MediaManager* mediaManager): Menu(deviceIO, mediaManager) {}

    void IOTestingMenu::render() {
        deviceIO->setDisplayColor({255, 255, 255});

        FontRenderer text = {deviceIO, "Hello World", {10, 10}};
        text.color = {100, 100, 0};
        text.renderText();

        drawInputTest();
    }
} // Menu
} // View