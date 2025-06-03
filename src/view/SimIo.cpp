//
// Created by ethanscharlie on 6/3/25.
//

#include "SimIo.hpp"

namespace View {
SimIO::SimIO() {
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("Pipod Simulator", 0, 0, DISPLAY_WIDTH,
                            DISPLAY_HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

bool SimIO::isButtonDown() { return false; }

void SimIO::refreshDisplay() { SDL_RenderPresent(renderer); }

void SimIO::setDisplayColor(Color color) {}
} // namespace View
