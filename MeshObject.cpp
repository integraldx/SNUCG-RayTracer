#include "MeshObject.hpp"
#include <iostream>

using namespace snucg;

MeshObject::MeshObject()
{

}

MeshObject::MeshObject(std::vector<Polygon> mesh, shared_ptr<vector<Texture>> textures)
: mesh(mesh), textures(textures)
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

Material MeshObject::GetMaterial(int index, float u, float v)
{
    Material m = textures->at(index).getMaterialFromUV(u, v);

    return m;
}

RayCastResult MeshObject::GetRayCastResult(Vector3f origin, Vector3f direction, float minT)
{
    Vector3f tempOrigin = rotateVector(inverse(GetRotation()), origin - GetPosition()) * Vector3f{1 / GetScale().x, 1 / GetScale().y, 1 / GetScale().z};
    Vector3f tempDirection = rotateVector(inverse(GetRotation()), direction);
    // Vector3f tempOrigin = origin;
    // Vector3f tempDirection = direction;
    RayCastResult result = {false};
    float leastT = minT;
    // {
    //     float shortestT = dotProduct(GetPosition() - origin, direction) / getScale(direction);
    //     float distance = getScale(origin + (direction * shortestT) - GetPosition());
    //     if (distance > bubbleRadius)
    //     {
    //         return RayCastResult{false};
    //     }
    // }
    for (Polygon p : mesh)
    {
        if (!translucent)
        {
            if (dotProduct(p.first.normal + p.second.normal + p.third.normal, tempDirection) >= 0)
            {
                continue;
            }
        }
        Vector3f polygonNormal = normalize(crossProduct(p.second.position - p.first.position, p.third.position - p.first.position));
        float t = dotProduct(p.first.position - tempOrigin, polygonNormal) / dotProduct(tempDirection, polygonNormal);
        if (epsilon < t && t < leastT)
        {
            Vector3f collisionPosition = tempOrigin + tempDirection * t;
            Vector3f baryCentric = calculateBarycentric(p, collisionPosition);

            if (abs(baryCentric.x + baryCentric.y + baryCentric.z - 1) < epsilon)
            {
                // if (getScale((p.first.position * baryCentric.x + p.second.position * baryCentric.y + p.third.position * baryCentric.z) - collisionPosition) > 0.001)
                // {
                //     printf("something's wrong\n");
                // }

                result.collision = true;
                // result.position = collisionPosition;
                // result.normal = p.first.normal * baryCentric.x + p.second.normal * baryCentric.y + p.third.normal * baryCentric.z;
                result.position = rotateVector(GetRotation(), collisionPosition * GetScale()) + GetPosition();
                result.normal = rotateVector(GetRotation(), p.first.normal * baryCentric.x + p.second.normal * baryCentric.y + p.third.normal * baryCentric.z);
                result.t = t * getScale(GetScale());
                result.materialIndex = p.materialIndex;
                result.uv = p.first.uv * baryCentric.x + p.second.uv * baryCentric.y + p.third.uv * baryCentric.z;
                leastT = t;
            }
        }
    }
    result.mat = GetMaterial(result.materialIndex, result.uv.x, result.uv.y);

    return result;
}

shared_ptr<vector<Texture>> MeshObject::GetTextures()
{
    return textures;
}
