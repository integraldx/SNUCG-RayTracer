#pragma once

#include "Light.hpp"

namespace snucg
{
    class PunctualLight : public Light
    {
        private:
        Vector3f position;
        Vector4f ambient;
        Vector4f diffuse;
        Vector4f specular;

        public:
        PunctualLight() = default;

        Vector3f getPosition() const override;
        void setPosition(const Vector3f& v) override;

        Vector4f getAmbient() const override;
        void setAmbient(const Vector4f& v) override;

        Vector4f getDiffuse() const override;
        void setDiffuse(const Vector4f& v) override;

        Vector4f getSpecular() const override;
        void setSpecular(const Vector4f& v) override;
    };
}