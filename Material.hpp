#pragma once

#include "Vectorf.hpp"

namespace snucg
{
    class Material
    {
        public:
        Material();
        Material(
            Vector4f ambient,
            Vector4f diffuse,
            Vector4f specular,
            float roughness
        );
        ~Material();
        Vector4f diffuse;
        Vector4f specular;
        Vector4f ambient;
        float roughness;
    };
}