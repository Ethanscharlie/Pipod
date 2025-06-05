//
// Created by ethanscharlie on 6/3/25.
//

#ifndef COLOR_HPP
#define COLOR_HPP

namespace View {

struct Color {
    float r;
    float g;
    float b;

    Color(float r, float g, float b) : r(r), g(g), b(b) {}
    Color(bmp::Pixel px) {
        r = px.r;
        g = px.g;
        b = px.b;
    }
};

} // View

#endif //COLOR_HPP
