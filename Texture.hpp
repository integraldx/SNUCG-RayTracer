#pragma once

#include <png++/png.hpp>
#include <fstream>
#include "Vectorf.hpp"

using namespace std;

namespace snucg
{
    class Texture
    {
        private:
        png::image<png::rgb_pixel> image;

        public:
        static Texture textureFromPng(string filePath);

        Vector4f getColorFromUV(float u, float v);
    };
}