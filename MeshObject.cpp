#include "MeshObject.hpp"
#include <iostream>

using namespace snucg;

MeshObject::MeshObject()
{

}

MeshObject::MeshObject(std::vector<Polygon> mesh)
: mesh(mesh)
{
    // for (auto a : mesh)
    // {
    //     float temp;
    //     bubbleRadius = bubbleRadius > (temp = getScale(a.first.position)) ? temp : bubbleRadius;
    //     bubbleRadius = bubbleRadius > (temp = getScale(a.second.position)) ? temp : bubbleRadius;
    //     bubbleRadius = bubbleRadius > (temp = getScale(a.third.position)) ? temp : bubbleRadius;
    // }

    // printf("%f\n", bubbleRadius);
}

Material MeshObject::GetMaterial(int index)
{
    Material m;
    m.diffuse = {0.8, 0.8, 1, 1};
    m.specular = {1, 1, 1, 1};
    m.ambient = {0, 0, 0, 1};
    m.shininess = 10.0;

    return m;
}

RayCastResult MeshObject::GetRayCastResult(Vector3f origin, Vector3f direction)
{
    RayCastResult result = {false};
    float leastT = 9999999999999999;
    {
        float shortestT = dotProduct(GetPosition() - origin, direction) / getScale(direction);
        float distance = getScale(origin + (direction * shortestT) - GetPosition());
        if (distance > bubbleRadius)
        {
            return RayCastResult{false};
        }
    }
    for (Polygon p : mesh)
    {
        Vector3f polygonNormal = normalize(crossProduct(p.second.position - p.first.position, p.third.position - p.first.position));
        float t = dotProduct(polygonNormal, p.first.position - origin) / dotProduct(direction, polygonNormal);
        if (isnan(t) || t < epsilon || t > leastT)
        {
            continue;
        }
        Vector3f collisionPosition = origin + direction * t;
        Vector3f baryCentric = calculateBarycentric(p, collisionPosition);

        if (baryCentric.x < 0 || baryCentric.y < 0 || baryCentric.z < 0)
        {
            continue;
        }

        result.collision = true;
        result.position = collisionPosition;
        result.normal = p.first.normal * baryCentric.x + p.second.normal * baryCentric.y + p.third.normal * baryCentric.z;
        leastT = t;
    }

    return result;
}
