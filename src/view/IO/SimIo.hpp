//
// Created by ethanscharlie on 6/3/25.
//

#ifndef SIMIO_HPP
#define SIMIO_HPP
#include "DeviceIo.hpp"
#include "SDL2/SDL.h"

namespace View {

class SimIO : public DeviceIO {
    SDL_Window* window;
    SDL_Renderer* renderer;

    bool isThisButtonDown(SDL_Scancode scancode);

public:
    SimIO();
    void refreshDisplay() override;
    void setDisplayColor(Color color) override;
    void setPixel(std::pair<int, int> position, Color color) override;

    bool isButton1Down() override;
    bool isButton2Down() override;
    bool isButton3Down() override;
    bool isJoystickUpDown() override;
    bool isJoystickDownDown() override;
    bool isJoystickRightDown() override;
    bool isJoystickLeftDown() override;
};

} // View

#endif //SIMIO_HPP
