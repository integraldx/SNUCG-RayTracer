#include "Scene.hpp"

namespace snucg
{
    Vector4f Scene::rayTrace(Vector3f origin, Vector3f direction, unsigned int recursionDepth) const
    {
        if (recursionDepth > 10)
        {
            return {0, 0, 0, 1};
        }
        RayCastResult res = {false};
        Vector4f color = {0, 0, 0, 1};
        std::shared_ptr<Object> o;
        for (auto i : objects)
        {
            auto temp = i->GetRayCastResult(origin, direction, (res.collision ? res.t : 9999999));

            if (temp.collision)
            {
                res = temp;
                o = i;
            }
        }
        if (res.collision)
        {
            // color = {0.1, 0.1, 0.1, 1};
            auto pointToOriginDirection = normalize(origin - res.position);
            if (getScale(o->GetMaterial(res.materialIndex, res.uv.x, res.uv.y).specular) > 3 * epsilon)
            {
                auto refl = rayTrace(res.position, 2 * dotProduct(res.normal, pointToOriginDirection) * res.normal - pointToOriginDirection, recursionDepth + 1);
                color = color + (refl * o->GetMaterial(res.materialIndex, res.uv.x, res.uv.y).specular);
            }
            for (auto j : lights)
            {
                auto lightPosition = j->getPosition();
                auto pointToOriginDirection = normalize(origin - res.position);
                auto pointToLightDirection = normalize(lightPosition - res.position);

                auto irradiance = clampTo1(dotProduct(pointToLightDirection, res.normal));
                auto reflectance = clampTo1(dotProduct(
                    pointToOriginDirection, 
                    2 * dotProduct(res.normal, pointToLightDirection) * res.normal - pointToLightDirection));

                color = color + Light::phongShade(irradiance, reflectance, o->GetMaterial(res.materialIndex, res.uv.x, res.uv.y), j);
            }
        }
        return Vector4f{color.x, color.y, color.z, 1};
    }
}