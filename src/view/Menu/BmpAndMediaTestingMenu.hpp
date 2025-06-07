//
// Created by ethanscharlie on 6/5/25.
//

#ifndef BMPANDMEDIATESTINGMENU_HPP
#define BMPANDMEDIATESTINGMENU_HPP
#include "BitmapPlusPlus.hpp"
#include "Menu.hpp"
#include "../FontRenderer.hpp"

namespace View {
namespace Menu {

class BmpAndMediaTestingMenu : public Menu {
    const std::pair<int, int> ICON_POS = {16, 16};
    const std::pair<int, int> ICON_SIZE = {16, 16};

    const std::pair<int, int> CURRENTLY_PLAYING_TEXT_POS = {16, 30};

    bmp::Bitmap playIconImage;
    bmp::Bitmap pauseIconImage;
    FontRenderer currentlyPlayingText;

    void drawPausedIcon();
    void drawPlayingIcon();
    void drawIconBasedOnState();

public:
    BmpAndMediaTestingMenu(IO::DeviceIO *deviceIO, Model::MediaManager *mediaManager);

    void render() override;
};

} // Menu
} // View

#endif //BMPANDMEDIATESTINGMENU_HPP
