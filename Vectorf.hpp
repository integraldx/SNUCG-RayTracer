#pragma once
#include <math.h>

namespace snucg
{
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
    };

    struct Vector4f
    {
        float x;
        float y;
        float z;
        float w;
    };

    Vector2f operator + (Vector2f left, Vector2f right);

    Vector2f operator - (Vector2f left, Vector2f right);

    Vector2f operator * (float mul, Vector2f v);

    Vector2f operator * (Vector2f v, float mul);

    float dotProduct(Vector2f left, Vector2f right);

    float getScale(Vector2f v);

    Vector2f normalize(Vector2f v);

    Vector3f operator * (float mul, Vector3f v);

    Vector3f operator * (Vector3f v, float mul);

    float dotProduct(Vector3f left, Vector3f right);

    Vector3f crossProduct(Vector3f left, Vector3f right);

    Vector3f operator + (Vector3f left, Vector3f right);

    Vector3f operator - (Vector3f left, Vector3f right);

    float getScale(Vector3f v);

    Vector3f normalize(Vector3f v);

    Vector4f operator * (float mul, Vector4f v);

    Vector4f operator * (Vector4f v, float mul);

    float dotProduct(Vector4f left, Vector4f right);

    Vector4f crossProduct(Vector4f left, Vector4f right);

    Vector4f operator + (Vector4f left, Vector4f right);

    Vector4f operator - (Vector4f left, Vector4f right);

    float getScale(Vector4f v);

    Vector4f normalize(Vector4f v);
}