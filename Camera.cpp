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
                auto castResult = rayCast(
                    position, 
                    normalize(rotateVector(rotation, Vector3f{
                        (float)(j - (width / 2)) * tanf(M_PI * fieldOfView / 360) / (width / 2),
                        (float)((height / 2) - i) * tanf(M_PI * fieldOfView / 360) / (width / 2),
                        -1})),
                    sc);
                resultImage[i][j] = png::rgb_pixel((int)(castResult.x * 255), (int)(castResult.y * 255), (int)(castResult.z * 255));
            }
        }

        return resultImage;
    }

    Vector3f Camera::rayCast(Vector3f position, Vector3f direction, Scene sc)
    {
        RayCastResult res = {false};
        for (auto a : sc.objects)
        {
            auto temp = a->GetRayCastResult(position, direction);
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
                }
            }
        }

        if (res.collision)
        {
            return Vector3f{1, 1, 1};
        }
        else
        {
            return Vector3f{0, 0, 0};
        }
    }
}