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
                resultImage[i][j] = png::rgb_pixel(clampTo255((int)(castResult.x * 255)), clampTo255((int)(castResult.y * 255)), clampTo255((int)(castResult.z * 255)));
            }
        }

        return resultImage;
    }
}