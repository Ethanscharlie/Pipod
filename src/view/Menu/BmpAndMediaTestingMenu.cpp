//
// Created by ethanscharlie on 6/5/25.
//

#include "BmpAndMediaTestingMenu.hpp"

namespace View {
namespace Menu {
    void BmpAndMediaTestingMenu::drawPausedIcon() {
        deviceIO->drawRect(ICON_POS, ICON_SIZE, {255, 0, 0});
    }

    void BmpAndMediaTestingMenu::drawPlayingIcon() {
        deviceIO->drawRect(ICON_POS, ICON_SIZE, {0, 255, 0});
    }

    void BmpAndMediaTestingMenu::render() {
        drawPausedIcon();
    }
} // Menu
} // View