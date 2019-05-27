#include "Camera.hpp"

namespace snucg
{
    void Camera::SetPosition(Vector3f newPos)
    {
        position = newPos;
    }
    png::image<png::rgb_pixel> Camera::evaluateImage(int width, int height, Scene sc)
    {
        png::image<png::rgb_pixel> resultImage(width, height);

        for (int i = 0; i < height; i += 1)
        {
            for (int j = 0; j < width; j += 1)
            {
                auto castResult = sc.rayTrace(
                    position, 
                    normalize(rotateVector(rotation, Vector3f{
                        (float)(j - (width / 2)) * tanf(M_PI * fieldOfView / 360) / (width / 2),
                        (float)((height / 2) - i) * tanf(M_PI * fieldOfView / 360) / (width / 2),
                        -1})),
                        0);
                resultImage[i][j] = png::rgb_pixel((int)(castResult.x * 255), (int)(castResult.y * 255), (int)(castResult.z * 255));
            }
        }

        return resultImage;
    }

    Vector3f Camera::rayCast(Vector3f position, Vector3f direction, Scene sc)
    {
        RayCastResult res = {false};
        Vector4f color = {0, 0, 0};
        for (auto i : sc.objects)
        {
            auto temp = i->GetRayCastResult(position, direction);
            if (temp.collision)
            {
                if (res.collision)
                {
                    if (dotProduct(res.position - temp.position, direction) > 0)
                    {
                        res = temp;
                    }
                }
                else
                {
                    res = temp;
                    for (auto j : sc.lights)
                    {
                        auto lightPosition = j->getPosition();
                        auto irradiance = dotProduct(normalize(lightPosition - res.position), res.normal);
                        if (irradiance < 0)
                        {
                            irradiance = 0;
                        }
                        color = i->GetMaterial(0).diffuse * irradiance;
                    }
                }
            }
        }

        return Vector3f{color.x, color.y, color.z};
    }
}