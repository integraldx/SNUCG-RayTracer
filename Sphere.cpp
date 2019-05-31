#include "Sphere.hpp"
#include <iostream>

namespace snucg
{
    Sphere::Sphere(float initialRadius)
    {
        m = {{0.3, 0.3, 0.3, 1},
            {0.3, 0.3, 0.3, 1},
            {0.5, 0.5, 0.5, 1},
            10};
        radius = initialRadius;
    }

    void Sphere::SetMaterial(Material newMaterial)
    {
        m = newMaterial;
    }

    Material Sphere::GetMaterial(int index, float u, float v)
    {
        return m;
    }

    RayCastResult Sphere::GetRayCastResult(Vector3f origin, Vector3f direction)
    {
        auto newOrigin = origin;
        auto newDirection = direction;
        float shortestT = dotProduct(GetPosition() - newOrigin, newDirection);
        float distance = getScale(newOrigin + (newDirection * shortestT) - GetPosition());
        float interval = ::pow(::pow(radius, 2) - ::pow(distance, 2), 0.5);
        float t = shortestT - interval;
        if (distance > radius || t < epsilon)
        {
            return RayCastResult{false};
        }
        else
        {
            RayCastResult res;
            res.collision = true;
            res.materialIndex = 0;
            res.position = origin + direction * t;
            res.normal = normalize(res.position - GetPosition());
            // ::std::cout << res.normal.x << ", " << res.normal.y << ", " << res.normal.z << ::std::endl;
            res.uv = {0, 0};
            return res;
        }
    }
}