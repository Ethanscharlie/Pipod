//
// Created by ethanscharlie on 6/3/25.
//

#include "SimIo.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_video.h>

namespace View::IO {

bool SimIO::isThisButtonDown(SDL_Scancode scancode) {
  SDL_PumpEvents();
  const Uint8 *keyboardStateArray = SDL_GetKeyboardState(nullptr);
  return keyboardStateArray[scancode];
}

SimIO::SimIO() {
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("Pipod Simulator", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, DISPLAY_WIDTH,
                            DISPLAY_HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
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

bool SimIO::isButton1Down() {
  return isThisButtonDown(SDL_SCANCODE_J);
}

bool SimIO::isButton2Down() {
  return isThisButtonDown(SDL_SCANCODE_K);
}

bool SimIO::isButton3Down() {
  return isThisButtonDown(SDL_SCANCODE_L);
}

bool SimIO::isJoystickUpDown() {
  return isThisButtonDown(SDL_SCANCODE_W);
}

bool SimIO::isJoystickDownDown() {
  return isThisButtonDown(SDL_SCANCODE_S);
}

bool SimIO::isJoystickRightDown() {
  return isThisButtonDown(SDL_SCANCODE_D);
}

bool SimIO::isJoystickLeftDown() {
  return isThisButtonDown(SDL_SCANCODE_A);
}
} // namespace View
