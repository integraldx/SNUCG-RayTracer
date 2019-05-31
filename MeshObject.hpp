#pragma once

#include <vector>

#include "Object.hpp"
#include "Vectorf.hpp"
#include "RayTracer.hpp"
#include "Texture.hpp"

namespace snucg
{
    class MeshObject : public Object
    {
        private:
        std::vector<Polygon> mesh;
        float bubbleRadius = 9999999999;
        Texture texture;

        public:
        MeshObject();
        MeshObject(std::vector<Polygon> mesh);
        Material GetMaterial(float u, float v) override;
        RayCastResult GetRayCastResult(Vector3f origin, Vector3f direction) override;
        void SetTexture(Texture t);
    };
}