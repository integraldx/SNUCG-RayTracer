#pragma once

// Internal headers
#include "Object.hpp"
#include "RayTracer.hpp"
#include "Material.hpp"
#include "Texture.hpp"

namespace snucg
{
    class Sphere : public Object
    {
        private:
        float radius;
        Material m;

        public:
        Sphere(float initialRadius);
        void SetTexture(Texture t);
        void SetMaterial(Material m);
        Material GetMaterial(int index, float u, float v) override;
        RayCastResult GetRayCastResult(Vector3f origin, Vector3f direction, float minT) override;
    };
}