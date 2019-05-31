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

Material MeshObject::GetMaterial(float u, float v)
{
    printf("%f, %f\n", u, v);
    Material m;
    m.diffuse = texture.getColorFromUV(u, v);
    printf("%f, %f, %f, %f\n", m.diffuse.x, m.diffuse.y, m.diffuse.z, m.diffuse.w);
    m.specular = {0.1, 0.1, 0.1, 1};
    m.ambient = {0, 0, 0, 1};
    m.shininess = 10.0;

    return m;
}

RayCastResult MeshObject::GetRayCastResult(Vector3f origin, Vector3f direction)
{
    origin = rotateVector(inverse(GetRotation()), origin - GetPosition()) * Vector3f{1 / GetScale().x, 1 / GetScale().y, 1 / GetScale().z};
    direction = rotateVector(inverse(GetRotation()), direction);
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
        result.position = rotateVector(GetRotation(), collisionPosition * GetScale()) + GetPosition();
        result.normal = p.first.normal * baryCentric.x + p.second.normal * baryCentric.y + p.third.normal * baryCentric.z;
        result.uv = p.first.uv * baryCentric.x + p.second.uv * baryCentric.y + p.third.uv * baryCentric.z;
        leastT = t;
    }

    return result;
}

void MeshObject::SetTexture(Texture t)
{
    texture = t;
}
