#include "raylib.h"

namespace Simulator
{
    class Camera
    {
    public:
        Vector2 position;

        void Move()
        {
            if (IsKeyDown(KEY_LEFT))
            {
                position.x -= 0.01;
            }
            if (IsKeyDown(KEY_RIGHT))
            {
                position.x += 0.01;
            }
            if (IsKeyDown(KEY_UP))
            {
                position.y += 0.01;
            }
            if (IsKeyDown(KEY_DOWN))
            {
                position.y -= 0.01;
            }
        }
    };
}