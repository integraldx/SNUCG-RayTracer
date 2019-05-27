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
                        auto irradiance = dotProduct(normalize(lightPosition - res.position), res.normal);
                        if (irradiance < 0)
                        {
                            irradiance = 0;
                        }

                        color = color + Light::phongShade(irradiance, i->GetMaterial(0), j);
                    }
                }
            }
        }
        return Vector4f{color.x, color.y, color.z, 1};
    }
}