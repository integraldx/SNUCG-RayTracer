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
        float roughness
    ) : ambient(ambient), diffuse(diffuse), specular(specular), roughness(roughness)
    {

    }

    Material::~Material()
    {

    }
}