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
    auto alphaV = p.first.position - target;
    auto betaV = p.second.position - target;
    auto gammaV = p.third.position - target;

    float triangle = getScale(crossProduct(p.second.position - p.first.position, p.third.position - p.first.position));

    float alpha = getScale(crossProduct(betaV, gammaV)) / triangle;
    float beta = getScale(crossProduct(alphaV, gammaV)) / triangle;
    float gamma = getScale(crossProduct(alphaV, betaV)) / triangle;

    return {alpha, beta, gamma};
}