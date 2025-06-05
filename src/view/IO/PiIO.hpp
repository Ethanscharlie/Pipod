//
// Created by ethanscharlie on 6/3/25.
//

#ifndef PIIO_HPP
#define PIIO_HPP
#include "DeviceIo.hpp"

#include "DEV_Config.h"
#include "GUI_Paint.h"
#include "LCD_1in44.h"

namespace View::IO {

class PiIO : public DeviceIO {
  UWORD *BlackImage;
  int gpioChip;

  unsigned short rgbToRgb565(unsigned char r, unsigned char g, unsigned char b);

public:
  PiIO();

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

} // namespace View

#endif // PIIO_HPP
