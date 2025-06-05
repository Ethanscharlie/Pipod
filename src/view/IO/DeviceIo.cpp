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

    void DeviceIO::drawBitmap(const bmp::Bitmap &bitmap, std::pair<int, int> position) {
        const std::pair<int, int> size = {bitmap.width(), bitmap.height()};
        for (int bitmapX = 0; bitmapX < size.first; bitmapX++) {
            for (int bitmapY = 0; bitmapY < size.second; bitmapY++) {
                const Color color = bitmap.get(bitmapX, bitmapY);
                const int x = position.first + bitmapX;
                const int y = position.second + bitmapY;
                setPixel({x, y}, color);
            }
        }
    }
} // View