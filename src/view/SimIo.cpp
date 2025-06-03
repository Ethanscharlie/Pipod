//
// Created by ethanscharlie on 6/3/25.
//

#include "SimIo.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

namespace View {
SimIO::SimIO() {
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("Pipod Simulator", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, DISPLAY_WIDTH,
                            DISPLAY_HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

bool SimIO::isButtonDown() { return false; }

void SimIO::refreshDisplay() { SDL_RenderPresent(renderer); }

void SimIO::setDisplayColor(Color color) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
  SDL_RenderClear(renderer);
}
} // namespace View
