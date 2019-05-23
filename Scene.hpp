#pragma once
// std, external library
#include <vector>
#include <memory>
// internal headers
#include "Object.hpp"
namespace snucg
{
    class Scene
    {
    private:
    public:  
        std::vector<std::shared_ptr<Object>> objects;
        std::vector<std::shared_ptr<Object>> lights;
    };
}