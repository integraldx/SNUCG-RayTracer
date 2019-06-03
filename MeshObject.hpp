#pragma once

#include <vector>
#include <memory>

#include "Object.hpp"
#include "Vectorf.hpp"
#include "RayTracer.hpp"
#include "Texture.hpp"

using namespace std;
namespace snucg
{
    class MeshObject : public Object
    {
        private:
        std::vector<Polygon> mesh;
        float bubbleRadius = 9999999999;
        shared_ptr<vector<Texture>> textures;

        public:
        MeshObject();
        MeshObject(std::vector<Polygon> mesh, shared_ptr<std::vector<Texture>> textures);
        shared_ptr<vector<Texture>> GetTextures();
        Material GetMaterial(int index, float u, float v) override;
        RayCastResult GetRayCastResult(Vector3f origin, Vector3f direction, float minT) override;
        bool translucent = true;
    };
}