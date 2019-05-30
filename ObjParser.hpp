#pragma once

#include <fstream>
#include <memory>
#include <sstream>
#include "MeshObject.hpp"

using namespace std;
namespace snucg
{
    shared_ptr<MeshObject> parseObj(string filepath)
    {
        ifstream objFile(filepath);
        if(!objFile.is_open())
        {
            throw "Failed to open file";
        }

        vector<Vector3f> vertexV;
        vector<Vector2f> uvV;
        vector<Vector3f> normalV;

        vector<Polygon> polygonV;
        string line;
        while(getline(objFile, line))
        {
            stringstream ss(line);

            string command;
            ss >> command;

            if (command.compare("#") == 0)
            {
                continue;
            }
            else if (command.compare("v") == 0)
            {
                float x, y, z;
                ss >> x >> y >> z;
                vertexV.push_back({x, y, z});
            }
            else if (command.compare("vt") == 0)
            {
                float u, v;
                ss >> u >> v;
                uvV.push_back({u, v});
            }
            else if (command.compare("vn") == 0)
            {
                float x, y, z;
                ss >> x >> y >> z;
                normalV.push_back({x, y, z});
            }
            else if (command.compare("f") == 0)
            {
                Vertex v[3];
                for (int i = 0; i < 3; i++)
                {
                    int vertexIndex, uvIndex, normalIndex;
                    char trash;
                    ss >> vertexIndex >> trash >> uvIndex >> trash >> normalIndex;
                    v[i] = Vertex{vertexV[vertexIndex], normalV[normalIndex], uvV[uvIndex]};
                }
                polygonV.push_back({v[0], v[1], v[2]});
            }
        }
        cout << 
        vertexV.size() << endl << 
        uvV.size() << endl << 
        normalV.size() << endl << 
        polygonV.size() << endl;
        return make_shared<MeshObject>(polygonV);
    }
}