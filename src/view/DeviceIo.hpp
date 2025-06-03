//
// Created by ethanscharlie on 6/3/25.
//

#ifndef DEVICEIO_HPP
#define DEVICEIO_HPP

#include "Color.hpp"

namespace View {

class DeviceIO {

public:
    virtual bool isButtonDown();
    virtual void setDisplayColor(Color color);
};

} // View

#endif //DEVICEIO_HPP
