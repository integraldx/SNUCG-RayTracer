#pragma once
// std, external library
#include <vector>
// internal headers
#include "Vectorf.hpp"
#include "RayTracer.hpp"

namespace snucg
{

    class Object
    {
    private:
        std::vector<Vertex> vertices;
    public:
        RayCastResult getRayCastedPolygon();
    };
}