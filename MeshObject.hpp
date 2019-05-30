#pragma once

#include <vector>

#include "Object.hpp"
#include "Vectorf.hpp"
#include "RayTracer.hpp"

namespace snucg
{
    class MeshObject : public Object
    {
        private:
        std::vector<Polygon> mesh;
        float bubbleRadius = 9999999999;

        public:
        MeshObject();
        MeshObject(std::vector<Polygon> mesh);
        Material GetMaterial(int index) override;
        RayCastResult GetRayCastResult(Vector3f origin, Vector3f direction) override;


    };
}