#include <iostream>
#include <png++/png.hpp>

#include "Scene.hpp"
#include "Object.hpp"
#include "Sphere.hpp"
#include "Camera.hpp"
#include "PunctualLight.hpp"

using namespace std;
using namespace snucg;

int main()
{
    // png::image< png::rgb_pixel > image(1920, 1080);
    // for (png::uint_32 y = 0; y < image.get_height(); ++y)
    // {
    //     for (png::uint_32 x = 0; x < image.get_width(); ++x)
    //     {
    //         image[y][x] = png::rgb_pixel(x, y, x + y);
    //         // non-checking equivalent of image.set_pixel(x, y, ...);
    //     }
    // }
    // image.write("rgb.png");

    Scene sc;
    sc.objects.push_back(make_shared<Sphere>(1));
    sc.lights.push_back(make_shared<PunctualLight>());
    sc.lights[0]->setPosition({10, 10, 10});
    sc.lights[0]->setAmbient({1, 1, 1, 1});
    sc.lights[0]->setDiffuse({1, 1, 1, 1});
    sc.lights[0]->setSpecular({0.8, 0.8, 0.8, 1});
    Camera cam;
    cam.SetPosition({0, 0, 10});
    auto i = cam.evaluateImage(1920, 1080, sc);
    i.write("result.png");
    return 0;
}