#pragma once
// std, external library
#include <vector>
// internal headers
#include "Vectorf.hpp"
#include "RayTracer.hpp"
#include "Quaternion.hpp"

namespace snucg
{
    class Object
    {
    private:
        Vector3f position = {0, 0, 0};
        Quaternion rotation = identityQuat();
        Vector3f scale = {1, 1, 1};

    protected:
        Object();
        ~Object();

    public:
        virtual RayCastResult GetRayCastResult(Vector3f origin, Vector3f direction) = 0;
        void SetPosition(Vector3f newPos);
        Vector3f GetPosition();
        void SetRotation(Quaternion newRot);
        Quaternion GetRotation();
        void SetScale(Vector3f newScale);
        Vector3f GetScale();
    };
}