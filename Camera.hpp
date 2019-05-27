#pragma once
// std, external library
#include <png++/png.hpp>
// internal headers
#include "Scene.hpp"
#include "Object.hpp"
#include "Vectorf.hpp"
#include "Quaternion.hpp"
#include "RayTracer.hpp"

namespace snucg
{
    class Camera
    {
    private:
        float fieldOfView = 60;
        Vector3f position;
        Quaternion rotation = {1, 0, 0, 0};

    public:
        png::image<png::rgb_pixel> evaluateImage(int width, int height, Scene sc);

        void SetPosition(Vector3f newPos);

        Vector3f GetPosition();

        void SetRotation(Quaternion newRot);

        Quaternion GetRotation();
    };
}