#pragma once
#include <math.h>

namespace snucg
{
    struct Vector4f;

    struct Vector2f
    {
        float x;
        float y;
    };

    struct Vector3f
    {
        float x;
        float y;
        float z;

        operator Vector4f();
    };

    struct Vector4f
    {
        float x;
        float y;
        float z;
        float w;
    };

    Vector2f operator + (const Vector2f& left, const Vector2f& right);

    Vector2f operator - (const Vector2f& left, const Vector2f& right);

    Vector2f operator * (const float& mul, const Vector2f& v);

    Vector2f operator * (const Vector2f& v, const float& mul);

    float dotProduct(const Vector2f& left, const Vector2f& right);

    float getScale(const Vector2f& v);

    Vector2f normalize(const Vector2f& v);

    Vector3f operator * (const float& mul, const Vector3f& v);

    Vector3f operator * (const Vector3f& v, const float& mul);

    Vector3f operator * (const Vector3f& left, const Vector3f& right);

    float dotProduct(const Vector3f& left, const Vector3f& right);

    Vector3f crossProduct(const Vector3f& left, const Vector3f& right);

    Vector3f operator + (const Vector3f& left, const Vector3f& right);

    Vector3f operator - (const Vector3f& left, const Vector3f& right);

    float getScale(const Vector3f& v);

    Vector3f normalize(const Vector3f& v);

    Vector4f operator * (const float& mul, const Vector4f& v);

    Vector4f operator * (const Vector4f& v, const float& mul);

    Vector4f operator * (const Vector4f& left, const Vector4f& right);

    float dotProduct(const Vector4f& left, const Vector4f& right);

    Vector4f crossProduct(const Vector4f& left, const Vector4f& right);

    Vector4f operator + (const Vector4f& left, const Vector4f& right);

    Vector4f operator - (const Vector4f& left, const Vector4f& right);

    float getScale(const Vector4f& v);

    Vector4f normalize(Vector4f& v);
}