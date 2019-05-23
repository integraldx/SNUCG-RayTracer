#include <iostream>
#include <png++/png.hpp>

#include "Scene.hpp"
#include "Object.hpp"

using namespace std;
using namespace snucg;

int main()
{
    png::image< png::rgb_pixel > image(1920, 1080);
    for (png::uint_32 y = 0; y < image.get_height(); ++y)
    {
        for (png::uint_32 x = 0; x < image.get_width(); ++x)
        {
            image[y][x] = png::rgb_pixel(x, y, x + y);
            // non-checking equivalent of image.set_pixel(x, y, ...);
        }
    }
    image.write("rgb.png");
    return 0;
}