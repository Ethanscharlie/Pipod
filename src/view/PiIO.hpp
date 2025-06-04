//
// Created by ethanscharlie on 6/3/25.
//

#ifndef PIIO_HPP
#define PIIO_HPP
#include "DeviceIo.hpp"

#include "DEV_Config.h"
#include "GUI_Paint.h"
#include "LCD_1in44.h"

namespace View {

class PiIO : public DeviceIO {
  UWORD *BlackImage;
  int gpioChip;

  unsigned short rgbToRgb565(unsigned char r, unsigned char g, unsigned char b);

public:
  PiIO();
  bool isButtonDown() override;
  void refreshDisplay() override;
  void setDisplayColor(Color color) override;
  void setPixel(std::pair<int, int> position, Color color) override;
};

} // namespace View

#endif // PIIO_HPP
