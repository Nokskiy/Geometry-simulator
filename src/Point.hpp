#pragma once
#include "raylib.h"
#include <string>
using namespace std;

namespace Simulator
{
    class Point
    {
    public:
        char* name;
        Vector2 position = {0,0};
        
        Point(Vector2 pos = {0,0},char* pName = "A")
        {
            name = pName;
            position = pos;
        }
    };
}   