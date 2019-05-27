#pragma once
#include <memory>
#include "Vectorf.hpp"
#include "Material.hpp"


namespace snucg
{
    class Light
    {
        private:

        public:
        virtual Vector3f getPosition() const = 0;
        virtual void setPosition(const Vector3f& v) = 0;

        virtual Vector4f getDiffuse() const = 0;
        virtual void setDiffuse(const Vector4f& v) = 0;

        virtual Vector4f getAmbient() const = 0;
        virtual void setAmbient(const Vector4f& v) = 0;

        virtual Vector4f getSpecular() const = 0;
        virtual void setSpecular(const Vector4f& v) = 0;

        static Vector4f phongShade(const float f, const Material& m, const std::shared_ptr<Light> l)
        {
            Vector4f color = {0, 0, 0, 0};

            color = color + (m.ambient * l->getAmbient());
            color = color + f * (m.diffuse * l->getDiffuse());

            return color;
        }
    };
}
