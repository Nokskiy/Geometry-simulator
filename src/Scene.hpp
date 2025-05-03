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
            float fontSize = Settings::ReadSettings("font_size");

            #pragma region points
            for(const auto p : _points)
            {
                DrawCircle(int(p.position.x * posMult),int(p.position.y * posMult),15,WHITE);
                DrawText(p.name,p.position.x,p.position.y,fontSize,RED);
            }
            #pragma endregion points
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
