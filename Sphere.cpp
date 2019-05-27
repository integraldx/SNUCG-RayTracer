#include "Sphere.hpp"

namespace snucg
{
    Sphere::Sphere(float initialRadius)
    : m(
        {0.1, 0.1, 0.1, 1},
        {0.4, 0.4, 1, 1},
        {0.7, 0.7, 0.7, 1},
        {10}
    )
    {
        radius = initialRadius;
    }

    void Sphere::SetMaterial(Material newMaterial)
    {
        this->m = newMaterial;
    }

    Material Sphere::GetMaterial(int index)
    {
        return m;
    }

    RayCastResult Sphere::GetRayCastResult(Vector3f origin, Vector3f direction)
    {
        float shortestT = dotProduct(GetPosition() - origin, direction) / getScale(direction);
        float distance = getScale(origin + (direction * shortestT) - GetPosition());
        if (distance > radius)
        {
            return RayCastResult{false};
        }
        else
        {
            RayCastResult res;
            float interval = sqrt(::pow(radius, 2) - ::pow(distance, 2));
            float lessT = interval / getScale(direction);
            res.collision = true;
            res.position = origin + direction * (shortestT - lessT);
            res.normal = normalize(res.position - GetPosition());
            return res;
        }
    }
}