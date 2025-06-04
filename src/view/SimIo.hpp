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

public:
    SimIO();
    bool isButtonDown() override;
    void refreshDisplay() override;
    void setDisplayColor(Color color) override;
    void setPixel(std::pair<int, int> position, Color color) override;
};

} // View

#endif //SIMIO_HPP
