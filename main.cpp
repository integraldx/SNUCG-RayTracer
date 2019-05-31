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
    sc.objects.push_back(parseObj("Scene/Test/test.obj"));
    sc.objects[0]->SetPosition({-2, 0, 2});
    sc.objects[0]->SetRotation(expToQuat(M_PI * 0.75, {0, 1, 0}));
    // {
    //     vector<Polygon> pv;
    //     {
    //         pv.push_back(
    //             Polygon{
    //                 0,
    //                 Vertex{
    //                     Vector3f{-1, -1, 0},
    //                     Vector3f{0, 0, 1},
    //                     Vector2f{0, 0}
    //                 },
    //                 Vertex{
    //                     Vector3f{1, -1, 0},
    //                     Vector3f{0, 0, 1},
    //                     Vector2f{1, 0}
    //                 },
    //                 Vertex{
    //                     Vector3f{-1, 1, 0},
    //                     Vector3f{0, 0, 1},
    //                     Vector2f{0, 1}
    //                 },
    //             }
    //         );
    //         pv.push_back(
    //             Polygon{
    //                 0,
    //                 Vertex{
    //                     Vector3f{-1, 1, 0},
    //                     Vector3f{0, 0, 1},
    //                     Vector2f{0, 1}
    //                 },
    //                 Vertex{
    //                     Vector3f{1, -1.0, 0},
    //                     Vector3f{0, 0, 1},
    //                     Vector2f{1, 0}
    //                 },
    //                 Vertex{
    //                     Vector3f{1, 1, 0},
    //                     Vector3f{0, 0, 1},
    //                     Vector2f{1, 1}
    //                 },
    //             }
    //         );
    //     }
    //     auto obj = make_shared<MeshObject>(pv);
    //     Texture t = Texture::textureFromPng("/home/integraldx/Downloads/texture.png");
    //     obj->SetTexture(t);
    //     sc.objects.push_back(obj);
    //     sc.objects[0]->SetPosition({0, 0, 3});
    // }
    sc.objects.push_back(make_shared<Sphere>(1));
    sc.objects.push_back(make_shared<Sphere>(1));
    sc.objects.at(1)->SetPosition({1, 1, -1});
    dynamic_pointer_cast<Sphere>(sc.objects.at(2))->SetMaterial({{0.3, 0.3, 0.3, 1}, {0.8, 0.4, 0.4, 1}, {0.8, 0.8, 0.8, 1}, 10});
    sc.lights.push_back(make_shared<PunctualLight>());
    sc.lights[0]->setPosition({10, 10, 0});
    sc.lights[0]->setAmbient({0.3, 0.3, 0.3, 1});
    sc.lights[0]->setDiffuse({1, 1, 1, 1});
    sc.lights[0]->setSpecular({0.8, 0.8, 0.8, 1});
    sc.lights.push_back(make_shared<PunctualLight>());
    sc.lights[1]->setPosition({10, 10, 0});
    sc.lights[1]->setAmbient({0.3, 0.3, 0.3, 1});
    sc.lights[1]->setDiffuse({1, 1, 1, 1});
    sc.lights[1]->setSpecular({0.8, 0.8, 0.8, 1});
    Camera cam;
    cam.SetPosition({0, 0, 10});
    auto i = cam.evaluateImage(2000, 2000, sc);
    i.write("result.png");
    return 0;
}