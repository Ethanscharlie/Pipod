//
// Created by ethanscharlie on 6/3/25.
//

#include "SimIo.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_video.h>

namespace View {
SimIO::SimIO() {
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("Pipod Simulator", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, DISPLAY_WIDTH,
                            DISPLAY_HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

bool SimIO::isButtonDown() {
  SDL_PumpEvents();
  const Uint8 *keyboardStateArray = SDL_GetKeyboardState(nullptr);
  return keyboardStateArray[SDL_SCANCODE_SPACE];
}

void SimIO::refreshDisplay() { SDL_RenderPresent(renderer); }

void SimIO::setDisplayColor(Color color) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
  SDL_RenderClear(renderer);
}

void SimIO::setPixel(std::pair<int, int> position, Color color) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
  SDL_RenderDrawPoint(renderer, position.first, position.second);
}
} // namespace View
