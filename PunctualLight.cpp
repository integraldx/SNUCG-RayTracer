#include "PunctualLight.hpp"

using namespace snucg;

Vector3f PunctualLight::getPosition() const 
{
    return position;
}

void PunctualLight::setPosition(const Vector3f& v)
{
    position = v;
}

Vector4f PunctualLight::getAmbient() const
{
    return ambient;
}

void PunctualLight::setAmbient(const Vector4f& v)
{
    ambient = v;
}

Vector4f PunctualLight::getDiffuse() const
{
    return diffuse;
}

void PunctualLight::setDiffuse(const Vector4f& v)
{
    diffuse = v;
}

Vector4f PunctualLight::getSpecular() const
{
    return specular;
}

void PunctualLight::setSpecular(const Vector4f& v)
{
    specular = v;
}