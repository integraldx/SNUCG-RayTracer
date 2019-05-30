#pragma once
// std, external library
#include <vector>
#include <memory>
// internal headers
#include "Object.hpp"
#include "RayTracer.hpp"
#include "Light.hpp"

namespace snucg
{
    class Scene
    {
    private:
    public:  
        std::vector<std::shared_ptr<Object>> objects;
        std::vector<std::shared_ptr<Light>> lights;

        Vector4f rayTrace(Vector3f origin, Vector3f direction, unsigned int recursionDepth) const;
    };
}