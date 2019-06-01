#pragma once
// std, external library
#include <png++/png.hpp>
#include <iostream>
#include <iomanip>
#include <thread>
#include <time.h>
#include <chrono>
#include <future>
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
        float fieldOfView = 75;
        Vector3f position;
        Quaternion rotation = {1, 0, 0, 0};

    public:
        png::image<png::rgb_pixel> evaluateImage(int width, int height, Scene sc);
        void writePixel(png::image<png::rgb_pixel>& image, int i, int j, const Scene& sc);

        void SetPosition(Vector3f newPos);

        Vector3f GetPosition();

        void SetRotation(Quaternion newRot);

        Quaternion GetRotation();
    };
}