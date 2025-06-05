//
// Created by ethanscharlie on 6/3/25.
//


#include "DeviceIo.hpp"

namespace View::IO {
    void DeviceIO::drawRect(std::pair<int, int> position, std::pair<int, int> size, Color color) {
        const int startingX = position.first;
        const int startingY = position.second;
        const int width = size.first;
        const int height = size.second;

        for (int x = startingX; x < startingX + width; x++) {
            for (int y = startingY; y < startingY + height; y++) {
                setPixel({x, y}, color);
            }
        }
    }
} // View