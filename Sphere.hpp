#pragma once

// Internal headers
#include "Object.hpp"
#include "RayTracer.hpp"

namespace snucg
{
    class Sphere : public Object
    {
        private:
        float radius;
        public:
        Sphere(float initialRadius);
        RayCastResult GetRayCastResult(Vector3f origin, Vector3f direction);
    };
}