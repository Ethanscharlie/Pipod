//
// Created by ethanscharlie on 6/5/25.
//

#include "BmpAndMediaTestingMenu.hpp"

#include <iostream>

#include "BitmapPlusPlus.hpp"

namespace View {
namespace Menu {
    void BmpAndMediaTestingMenu::drawPausedIcon() {
        deviceIO->drawBitmap(playIconImage, ICON_POS);
    }

    void BmpAndMediaTestingMenu::drawPlayingIcon() {
        deviceIO->drawBitmap(pauseIconImage, ICON_POS);
    }

    void BmpAndMediaTestingMenu::drawIconBasedOnState() {
        if (mediaManager->isPlaying()) {
            drawPlayingIcon();
            return;
        }

        drawPausedIcon();
    }

    BmpAndMediaTestingMenu::BmpAndMediaTestingMenu(IO::DeviceIO *deviceIO, Model::MediaManager *mediaManager)
        : Menu(deviceIO, mediaManager), currentlyPlayingText(deviceIO) {

        playIconImage.load("../res/icons/PlayButton.bmp");
        pauseIconImage.load("../res/icons/PauseBotton.bmp");

        currentlyPlayingText.position = CURRENTLY_PLAYING_TEXT_POS;
        currentlyPlayingText.color = {255, 255, 255};
    }

    void BmpAndMediaTestingMenu::render() {
        if (deviceIO->isButton1Down()) {
            mediaManager->play();
        }

        else if (deviceIO->isButton2Down()) {
            mediaManager->pause();
        }

        drawIconBasedOnState();

        currentlyPlayingText.text = mediaManager->getCurrentlyPlaying();
        currentlyPlayingText.renderText();
    }
} // Menu
} // View