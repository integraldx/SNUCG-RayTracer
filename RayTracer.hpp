#pragma once
#include "Vectorf.hpp"

namespace snucg
{
    const float epsilon = 0.0001;

    struct Vertex
    {
        Vector3f position;
        Vector3f normal;
        Vector2f uv;
    };

    struct Polygon
    {
        Vertex first;
        Vertex second;
        Vertex third;
    };

    struct RayCastResult
    {
        bool collision;
        Vector3f position;
        Vector3f normal;
    };
}