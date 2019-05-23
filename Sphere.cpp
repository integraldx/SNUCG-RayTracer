#include "Sphere.hpp"

namespace snucg
{
    Sphere::Sphere(float initialRadius)
    {
        radius = initialRadius;
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