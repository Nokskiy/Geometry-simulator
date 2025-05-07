#pragma once

#include "raylib.h"
#include "math.h"

using namespace std;

namespace Simulator
{
    float Distance(Vector2 pos1, Vector2 pos2)
    {
        float xDist = fabs(pos1.x) > fabs(pos2.x) ? fabs(pos1.x) - fabs(pos2.x) : fabs(pos2.x) - fabs(pos1.x);
        float yDist = fabs(pos1.y) > fabs(pos2.y) ? fabs(pos1.y) - fabs(pos2.y) : fabs(pos2.y) - fabs(pos1.y);
        
        return xDist + yDist;
    }
}