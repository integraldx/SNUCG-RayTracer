#pragma once

#include "Vectorf.hpp"

namespace snucg
{
    struct Material
    {
        Vector4f ambient;
        Vector4f diffuse;
        Vector4f specular;
        float shininess;
    };
}