#include "Camera.hpp"

namespace snucg
{
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
                        (float)(j - (width / 2)) * tan(fieldOfView / 2) / (width / 2),
                        (float)((height / 2) - i) * tan(fieldOfView / 2) / (width / 2),
                        -1})),
                    sc);
                resultImage[i][j] = png::rgb_pixel();
            }
        }

        return resultImage;
    }

    Vector3f Camera::rayCast(Vector3f position, Vector3f direction, Scene sc)
    {
        for (auto a : sc.objects)
        {

        }

        return Vector3f{0, 0, 0};
    }
}