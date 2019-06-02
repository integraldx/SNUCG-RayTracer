#include <iostream>
#include <png++/png.hpp>

#include "Scene.hpp"
#include "Object.hpp"
#include "Sphere.hpp"
#include "Camera.hpp"
#include "PunctualLight.hpp"
#include "MeshObject.hpp"
#include "ObjParser.hpp"

using namespace std;
using namespace snucg;

int main()
{
    Scene sc;
    {
        auto o = parseObj("Scene/Test/grass.obj");
        o->SetPosition({0, -10, 0});
        o->SetScale({10, 10, 10});
        sc.objects.push_back(o);
    }
    // {
    //     auto o = parseObj("Scene/Test/test.obj");
    //     o->SetPosition({-10, 0, 0});
    //     o->SetRotation(expToQuat(M_PI * 0.5, {0, 1, 0}));
    //     o->SetScale({10, 10, 10});
    //     sc.objects.push_back(o);
    // }
    {
        auto o = parseObj("Scene/Test/test.obj");
        o->SetPosition({10, 0, 0});
        o->SetRotation(expToQuat(M_PI * 0.5, {0, -1, 0}));
        o->SetScale({10, 10, 10});
        sc.objects.push_back(o);
    }
    {
        auto o = parseObj("Scene/Test/test.obj");
        o->SetPosition({0, 0, -10});
        o->SetScale({10, 10, 10});
        sc.objects.push_back(o);
    }
    {
        auto o = make_shared<Sphere>(7);
        o->SetPosition({0, 0, -2});
        Material m = {
            {0, 0, 0, 0},
            {0.2, 0.2, 0.2, 0.3},
            {0.4, 0.4, 0.4, 1},
            10,
            0.6
        };
        o->SetMaterial(m);
        sc.objects.push_back(o);
    }
    sc.lights.push_back(make_shared<PunctualLight>());
    sc.lights[0]->setPosition({100, 100, 100});
    sc.lights[0]->setAmbient({0.1, 0.1, 0.1, 1});
    sc.lights[0]->setDiffuse({1, 1, 1, 1});
    sc.lights[0]->setSpecular({0.1, 0.1, 0.1, 1});
    sc.lights.push_back(make_shared<PunctualLight>());
    sc.lights[1]->setPosition({-100, 100, 100});
    sc.lights[1]->setAmbient({0.1, 0.1, 0.1, 1});
    sc.lights[1]->setDiffuse({1, 1, 1, 1});
    sc.lights[1]->setSpecular({0.1, 0.1, 0.1, 1});
    Camera cam;
    cam.SetPosition({0, 10, 20});
    cam.SetRotation(expToQuat(M_PI * 0.175, {-1, 0, 0}));
    auto i = cam.evaluateImage(3000, 3000, sc);
    i.write("result.png");
    return 0;
}