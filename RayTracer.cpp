#include "RayTracer.hpp"


int snucg::clampTo255(int i)
{
    if (i < 0)
    {
        i = 0;
    }
    else if (i > 255)
    {
        i = 255;
    }

    return i;
}

float snucg::clampTo1(float f)
{
    if (f > 1)
    {
        f = 1;
    }
    else if (f < 0)
    {
        f = 0;
    }
    return f;
}

snucg::Vector3f snucg::calculateBarycentric(const Polygon p, const Vector3f target)
{
    Vector3f second = p.second.position - p.first.position;
    Vector3f third = p.third.position - p.first.position;
    Vector3f newTarget = target - p.first.position;

    float beta;
    float gamma;

    if (abs(second.x * third.y - third.x * second.y) > epsilon)
    {
        if (abs(second.x) < epsilon)
        {
            gamma = newTarget.x / third.x;
            beta = (newTarget.y - third.y * gamma) / second.y;
        }
        else
        {
            float firstFactor = second.y / second.x;
            gamma = (newTarget.y - firstFactor * newTarget.x) / (third.y - firstFactor * third.x);
            beta = (newTarget.x - third.x * gamma) / second.x;
        }
    }
    else if (abs(second.x * third.z - third.x * second.z) > epsilon)
    {
        if (abs(second.x) < epsilon)
        {
            gamma = newTarget.x / third.x;
            beta = (newTarget.z - third.z * gamma) / second.z;
        }
        else
        {
            float firstFactor = second.z / second.x;
            gamma = (newTarget.z - firstFactor * newTarget.x) / (third.z - firstFactor * third.x);
            beta = (newTarget.x - third.x * gamma) / second.x;
        }
    }
    else
    {
        if (abs(second.y) < epsilon)
        {
            gamma = newTarget.y / third.y;
            beta = (newTarget.z - third.z * gamma) / second.z;
        }
        else
        {
            float firstFactor = second.z / second.y;
            gamma = (newTarget.z - firstFactor * newTarget.y) / (third.z - firstFactor * third.y);
            beta = (newTarget.y - third.y * gamma) / second.y;
        }
    }
    return Vector3f{1 - gamma - beta, beta, gamma};
}