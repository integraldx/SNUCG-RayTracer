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
    // sc.objects.push_back(parseObj("/home/integraldx/AI/kizunaai/kizunaai.obj"));
    {
        vector<Polygon> pv;
        {
            pv.push_back(
                Polygon{
                    Vertex{
                        Vector3f{-1, 0, 0},
                        Vector3f{0, 0, 1},
                        Vector2f{0, 0}
                    },
                    Vertex{
                        Vector3f{0, 1.0, 0},
                        Vector3f{0, 0, 1},
                        Vector2f{0, 1}
                    },
                    Vertex{
                        Vector3f{1, 0, 0},
                        Vector3f{0, 0, 1},
                        Vector2f{1, 0}
                    },
                }
            );
        }
        sc.objects.push_back(make_shared<MeshObject>(pv));
        sc.objects[0]->SetPosition({0, 0, 3});
    }
    sc.objects.push_back(make_shared<Sphere>(1));
    sc.lights.push_back(make_shared<PunctualLight>());
    sc.lights[0]->setPosition({10, 10, 10});
    sc.lights[0]->setAmbient({1, 1, 1, 1});
    sc.lights[0]->setDiffuse({1, 1, 1, 1});
    sc.lights[0]->setSpecular({0.8, 0.8, 0.8, 1});
    Camera cam;
    cam.SetPosition({0, 0, 10});
    auto i = cam.evaluateImage(500, 500, sc);
    i.write("result.png");
    return 0;
}