#include "Material.hpp"

namespace snucg
{
    Material::Material()
    {

    }

    Material::Material(
        Vector4f ambient,
        Vector4f diffuse,
        Vector4f specular,
        float shininess
    ) : ambient(ambient), diffuse(diffuse), specular(specular), shininess(shininess)
    {

    }

    Material::~Material()
    {

    }
}