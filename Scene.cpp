#include "Scene.hpp"

namespace snucg
{
    Vector4f Scene::rayTrace(Vector3f origin, Vector3f direction, float ior, unsigned int recursionDepth) const
    {
        if (recursionDepth > 10)
        {
            return {0.1, 0.1, 0.1, 1};
        }
        RayCastResult res = {false};
        Vector4f color = {0.1, 0.1, 0.1, 1};
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
            auto mat = res.mat;
            // color = {0.1, 0.1, 0.1, 1};
            auto pointToOriginDirection = normalize(origin - res.position);
            if (getScale(mat.specular) > 3 * epsilon)
            {
                auto refl = rayTrace(res.position, 2 * dotProduct(res.normal, pointToOriginDirection) * res.normal - pointToOriginDirection, ior, recursionDepth + 1);
                color = color + (refl * mat.specular);
            }
            if (1 - mat.diffuse.w > epsilon)
            {
                float n1 = ior;
                float n2 = mat.iof;
                auto refl = dotProduct(-1 * direction, res.normal) > (n1 - n2);
                auto refr = rayTrace(res.position, normalize(direction - (n2 - n1) * res.normal), refl ? ior : mat.iof, recursionDepth + 1);
                color = color + (refr * (1 - mat.diffuse.w));
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

                color = color + Light::phongShade(irradiance, reflectance, mat, j);
            }
        }
        return Vector4f{color.x, color.y, color.z, 1};
    }
}