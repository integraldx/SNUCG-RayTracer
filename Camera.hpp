#pragma once
// std, external library
#include <png++/png.hpp>
// internal headers
#include "Scene.hpp"
#include "Object.hpp"
#include "Vectorf.hpp"
#include "Quaternion.hpp"

namespace snucg
{
    class Camera
    {
    private:
        float fieldOfView;
        Vector3f position;
        Quaternion rotation;
    public:
        png::image<png::rgb_pixel> evaluateImage(int width, int height, Scene sc);
        Vector3f rayCast(Vector3f origin, Vector3f direction, Scene sc);
    };
}