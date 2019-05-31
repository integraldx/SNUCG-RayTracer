#include "Texture.hpp"

using namespace std;
using namespace snucg;

Texture Texture::textureFromPng(string filePath)
{
    Texture t;
    t.image = png::image<png::rgb_pixel>(filePath);

    return t;
}

Vector4f Texture::getColorFromUV(float u, float v)
{
    int width = image.get_width();
    int height = image.get_height();
    int convertedHeight = (int)((1 - v) * height);
    if (convertedHeight >= height)
    {
        convertedHeight = height - 1;
    }
    else if (convertedHeight < 0)
    {
        convertedHeight = 0;
    }
    int convertedWidth = (int)(u * width);
    if (convertedWidth >= width)
    {
        convertedWidth = width - 1;
    }
    else if (convertedWidth < 0)
    {
        convertedWidth = 0;
    }
    auto pix = image[convertedHeight][convertedWidth];

    return Vector4f{(float)pix.red / 255, (float)pix.green / 255, (float)pix.blue / 255, 1};
}