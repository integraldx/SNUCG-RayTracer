#include "Vectorf.hpp"

namespace snucg
{
    Vector2f operator + (const Vector2f left, const Vector2f right)
    {
        return {left.x + right.x, left.y + right.y};
    }

    Vector2f operator * (const float f, const Vector2f v)
    {
        return {v.x * f, v.y * f};
    }

    Vector2f operator * (const Vector2f v, const float f)
    {
        return {v.x * f, v.y * f};
    }

    Vector3f operator * (const float mul, const Vector3f v)
    {
        return {v.x * mul, v.y * mul, v.z * mul};
    }

    Vector3f operator * (const Vector3f v, const float mul)
    {
        return {v.x * mul, v.y * mul, v.z * mul};
    }

    Vector3f operator * (const Vector3f left, const Vector3f right)
    {
        return {left.x * right.x, left.y * right.y, left.z * right.z};
    }

    float dotProduct(const Vector3f left, const Vector3f right)
    {
        return (left.x * right.x + left.y * right.y + left.z * right.z);
    }

    Vector3f crossProduct(const Vector3f left, const Vector3f right)
    {
        Vector3f result;
        result.x = left.y * right.z - left.z * right.y;
        result.y = left.z * right.x - left.x * right.z;
        result.z = left.x * right.y - left.y * right.x;

        return result;
    }

    Vector3f operator + (const Vector3f left, const Vector3f right)
    {
        return {left.x + right.x, left.y + right.y, left.z + right.z};
    }

    Vector3f operator - (const Vector3f left, const Vector3f right)
    {
        return {left.x - right.x, left.y - right.y, left.z - right.z};
    }

    float getScale(const Vector3f v)
    {
        return pow(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2), 0.5);
    }

    Vector3f normalize(const Vector3f v)
    {
        return v * (1 / getScale(v));
    }

    Vector4f operator * (const float mul, const Vector4f v)
    {
        return {mul * v.x, mul * v.y, mul * v.z, mul * v.w};
    }

    Vector4f operator * (const Vector4f v, const float mul)
    {
        return mul * v;
    }

    float dotProduct(const Vector4f left, const Vector4f right)
    {
        return left.x * right.x + left.y * right.y + left.z * right.z + left.w * right.w;
    }

    Vector4f operator + (const Vector4f left, const Vector4f right)
    {
        return {left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w};
    }

    Vector4f operator - (const Vector4f left, const Vector4f right)
    {
        return {left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w};
    }

    Vector4f operator * (const Vector4f left, const Vector4f right)
    {
        return {left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w};
    }

    float getScale(const Vector4f v)
    {
        return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.w, 2));
    }

    Vector4f normalize(const Vector4f v)
    {
        float scale = getScale(v);
        return {v.x / scale, v.y / scale, v.z / scale, v.w / scale};
    }
}