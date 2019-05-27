#include "Scene.hpp"

namespace snucg
{
    Vector4f Scene::rayTrace(Vector3f origin, Vector3f direction, unsigned int recursionDepth)
    {
        RayCastResult res = {false};
        Vector4f color = {0, 0, 0};
        for (auto i : objects)
        {
            auto temp = i->GetRayCastResult(origin, direction);
            if (temp.collision)
            {
                if (res.collision)
                {
                    if (dotProduct(res.position - temp.position, direction) > 0)
                    {
                        res = temp;
                    }
                }
                else
                {
                    res = temp;
                    for (auto j : lights)
                    {
                        auto lightPosition = j->getPosition();
                        auto pointToOriginDirection = normalize(origin - res.position);
                        auto pointToLightDirection = normalize(lightPosition - res.position);

                        auto irradiance = dotProduct(normalize(lightPosition - res.position), res.normal);
                        auto reflectance = clampTo1(dotProduct(
                            pointToOriginDirection, 
                            2 * dotProduct(res.normal, pointToLightDirection) * res.normal - pointToLightDirection));
                        if (irradiance < 0)
                        {
                            irradiance = 0;
                        }

                        color = color + Light::phongShade(irradiance, reflectance, i->GetMaterial(0), j);
                    }
                }
            }
        }
        return Vector4f{color.x, color.y, color.z, 1};
    }
}