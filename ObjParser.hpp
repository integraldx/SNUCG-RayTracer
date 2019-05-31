#pragma once

#include <fstream>
#include <memory>
#include <sstream>
#include <map>
#include "MeshObject.hpp"

using namespace std;
namespace snucg
{
    pair<map<string, int>, vector<Texture>> parseMtl(string filepath)
    {
        string baseFolder = filepath.substr(0, filepath.find_last_of('/') + 1);
        ifstream mtlFile(filepath);
        if(!mtlFile.is_open())
        {
            throw "Failed to open file";
        }

        map<string, int> nameMap;
        vector<Texture> texVector;
        string line;
        string matName;
        while(getline(mtlFile, line))
        {
            stringstream ss(line);
            string command;
            ss >> command;
            if (command.compare("newmtl") == 0)
            {
                ss >> matName;
            }
            else if (command.compare("map_Kd") == 0)
            {
                string texName;
                ss >> texName;
                nameMap.insert(make_pair(matName, texVector.size()));
                texVector.push_back(Texture::textureFromPng(baseFolder + texName));
            }
            else if (command.compare("Ka") == 0)
            {
                float f[4];
                for (int i = 0; i < 4; i++)
                {
                    ss >> f[i];
                }
                texVector.at(nameMap.at(matName)).setAmbient({f[0], f[1], f[2], f[3]});
            }
            else if (command.compare("Kd") == 0)
            {
                float f[4];
                for (int i = 0; i < 4; i++)
                {
                    ss >> f[i];
                }
                texVector.at(nameMap.at(matName)).setDiffuse({f[0], f[1], f[2], f[3]});
            }
            else if (command.compare("Ks") == 0)
            {
                float f[4];
                for (int i = 0; i < 4; i++)
                {
                    ss >> f[i];
                }
                texVector.at(nameMap.at(matName)).setSpecular({f[0], f[1], f[2], f[3]});
            }
            else if (command.compare("Ns") == 0)
            {
                float f;
                ss >> f;
                texVector.at(nameMap.at(matName)).setShininess(f);
            }
        }
        return make_pair(nameMap, texVector);
    }

    shared_ptr<MeshObject> parseObj(string filepath)
    {
        string baseFolder = filepath.substr(0, filepath.find_last_of('/') + 1);
        ifstream objFile(filepath);
        if(!objFile.is_open())
        {
            throw "Failed to open file";
        }

        vector<Vector3f> vertexV;
        vector<Vector2f> uvV;
        vector<Vector3f> normalV;

        vector<Polygon> polygonV;
        pair<map<string, int>, vector<Texture>> texPair;
        string line;
        string currentMtlName;
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
                    v[i] = Vertex{vertexV.at(vertexIndex - 1), normalV.at(normalIndex - 1), uvV.at(uvIndex - 1)};
                }
                polygonV.push_back(Polygon{texPair.first.at(currentMtlName), v[0], v[1], v[2]});
            }
            else if (command.compare("mtllib") == 0)
            {
                string mtlPath;
                ss >> mtlPath;
                texPair = parseMtl(baseFolder + mtlPath);
            }
            else if (command.compare("usemtl") == 0)
            {
                ss >> currentMtlName;
            }
        }

        return make_shared<MeshObject>(polygonV, texPair.second);
    }
}