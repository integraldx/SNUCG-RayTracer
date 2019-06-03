#pragma once

#include <png++/png.hpp>
#include <fstream>
#include "Vectorf.hpp"
#include "Material.hpp"

using namespace std;

namespace snucg
{
    class Texture
    {
        private:
        png::image<png::rgb_pixel> image;
        Vector4f ambient;
        Vector4f diffuse;
        Vector4f specular;
        float shininess;
        float ior = 0;

        public:
        static Texture textureFromPng(string filePath);

        Vector4f getColorFromUV(float u, float v);
        Material getMaterialFromUV(float u, float v);
        void setAmbient(Vector4f v);
        void setDiffuse(Vector4f v);
        void setSpecular(Vector4f v);
        void setShininess(float f);
        void setIor(float f);
    };
}