//
// Created by ethanscharlie on 6/3/25.
//

#ifndef SIMIO_HPP
#define SIMIO_HPP
#include "DeviceIo.hpp"

namespace View {

class SimIO : public DeviceIO {
public:
    SimIO();
    bool isButtonDown() override;
    void setDisplayColor(Color color) override;
};

} // View

#endif //SIMIO_HPP
