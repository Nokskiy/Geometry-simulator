#pragma once
#include "raylib.h"
#include "vector"
#include "Settings.hpp"
using namespace std;

namespace Simulator
{
    static class Scene
    {
    private:
        inline static vector<Point> _points;
        inline static void RenderAll()
        {
            float posMult = Settings::ReadSettings("position_mult");
            for(const auto p : _points)
            {
                DrawCircle(int(p.position.x * posMult),int(p.position.y * posMult),15,WHITE);
            }
        }
        
    public:
        inline static void AddPoint(const Point &p)
        {
            _points.push_back(p);
        }
        inline static void SceneProcess()
        {
            RenderAll();
        }
    };
}
