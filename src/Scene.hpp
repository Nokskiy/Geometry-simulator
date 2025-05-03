#pragma once
#include "raylib.h"
#include "vector"
#include "Settings.hpp"
#include "Segment.hpp"
#include "Point.hpp"

using namespace std;

namespace Simulator
{
    static class Scene
    {
    private:
        inline static vector<Point*> _points;
        inline static vector<Segment*> _segments;

        inline static void RenderAll()
        {
            float posMult = Settings::ReadSettings("position_mult");
            float fontSize = Settings::ReadSettings("font_size");

#pragma region points
            for (const auto p : _points)
            {
                DrawCircle(int((p)->position.x * posMult), int((p)->position.y * posMult), 5, WHITE);
                DrawText((p)->name, (p)->position.x * posMult, (p)->position.y * posMult, fontSize, RED);
            }
#pragma endregion points
#pragma region segment
            for (const auto s : _segments)
            {
                DrawLineEx(Vector2{ ((s)->points[0])->position.x * posMult, ((s)->points[0])->position.y * posMult },
                    Vector2{ ((s)->points[1])->position.x * posMult, ((s)->points[1])->position.y * posMult }, 3, WHITE);
            }
#pragma endregion segment
        }

    public:
        inline static void AddPoint(Point* p)
        {
            _points.push_back(p);
        }
        inline static void AddSegment(Segment* s)
        {
            _segments.push_back(s);
        }
        inline static void SceneProcess()
        {
            RenderAll();
        }
    };
}
