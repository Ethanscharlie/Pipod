//
// Created by ethanscharlie on 6/3/25.
//

#ifndef DEVICEIO_HPP
#define DEVICEIO_HPP

#include <utility>

#include "../Color.hpp"

namespace View {

class DeviceIO {

public:
  const int DISPLAY_WIDTH = 128;
  const int DISPLAY_HEIGHT = 128;

  DeviceIO() {}
  void drawRect(std::pair<int, int> position, std::pair<int, int> size, Color color);

  virtual void refreshDisplay() = 0;
  virtual void setDisplayColor(Color color) = 0;
  virtual void setPixel(std::pair<int, int> position, Color color) = 0;

  virtual bool isButton1Down() = 0;
  virtual bool isButton2Down() = 0;
  virtual bool isButton3Down() = 0;
  virtual bool isJoystickUpDown() = 0;
  virtual bool isJoystickDownDown() = 0;
  virtual bool isJoystickRightDown() = 0;
  virtual bool isJoystickLeftDown() = 0;
};

} // namespace View

#endif // DEVICEIO_HPP
