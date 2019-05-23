#include "Object.hpp"

namespace snucg
{
    Object::Object()
    {

    }

    Object::~Object()
    {

    }

    void Object::SetPosition(Vector3f newPos)
    {
        position = newPos;
    }

    Vector3f Object::GetPosition()
    {
        return position;
    }

    void Object::SetRotation(Quaternion newRot)
    {
        rotation = newRot;
    }

    Quaternion Object::GetRotation()
    {
        return rotation;
    }

    void Object::SetScale(Vector3f newScale)
    {
        scale = newScale;
    }

    Vector3f Object::GetScale()
    {
        return scale;
    }
}