#pragma once
#include "Vectorf.hpp"
#include "Material.hpp"

namespace snucg
{
    const float epsilon = 0.001;

    struct Vertex
    {
        Vector3f position;
        Vector3f normal;
        Vector2f uv;
    };

    struct Polygon
    {
        int materialIndex;
        Vertex first;
        Vertex second;
        Vertex third;
    };

    struct RayCastResult
    {
        bool collision;
        int materialIndex;
        float t;
        Vector3f position;
        Vector3f normal;
        Vector2f uv;
        Material mat;
    };

    int clampTo255(int i);

    float clampTo1(float f);

    Vector3f calculateBarycentric(const Polygon p, const Vector3f target);
}