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