//
// Creat ethanscharlie on 6/7/25.
//

#ifndef FONT_HPP
#define FONT_HPP
#include <future>
#include <map>
#include <vector>

#include "IO/DeviceIo.hpp"

namespace View {

class FontRenderer {
    static const int CHARPX_WIDTH = 5;
    static const int CHARPX_HEIGHT = 8;
    static const int CHAR_PAD = 1;
    static const char ALT_CHAR = '.';


    static std::map<char, std::vector<int>> fontData;

    std::pair<int, int> calculateCharacterPosition(int index);
    void render8BitColumn(int bits, int row, std::pair<int, int> characterPosition) const;
    void renderCharacterAtPosition(char c, std::pair<int, int> characterPosition);

public:
    IO::DeviceIO* deviceIO = nullptr;
    Color color = {0, 0, 0};
    std::pair<int, int> position = {0, 0};
    std::string text;

    FontRenderer(IO::DeviceIO* deviceIO);
    FontRenderer(IO::DeviceIO* deviceIO, const std::string& text, std::pair<int, int> position);

    static bool characterIsRenderable(char c);
    void renderText();
};

} // View

#endif //FONT_HPP
