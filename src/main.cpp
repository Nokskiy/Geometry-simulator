#include "main_includes.hpp"

using namespace std;

#pragma region MCR

#pragma region WINDOW
#define BG_COLOR Color{ 47, 40, 69, 255 }
#define WIDTH 900
#define HEIGHT 900
#define WINDOW_NAME "GEOMETRY SIMULATOR"
#pragma endregion WINDOW

#pragma region OBJS
#define POINT Simulator::Point
#define SPAWN_POINT Simulator::Scene::AddPoint
#pragma endregion OBJS

#define INIT_SETTINGS Simulator::Settings::Init()

#pragma endregion MCR

int main()
{
    INIT_SETTINGS;

    POINT p({1,1},"С");
    POINT p1({50,50},"D");
    
    SPAWN_POINT(p);
    SPAWN_POINT(p1);

    SetTraceLogLevel(LOG_NONE);
    InitWindow(WIDTH,HEIGHT,WINDOW_NAME);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BG_COLOR);
        Simulator::Scene::SceneProcess();
        

        EndDrawing();
    }
    CloseWindow();

    return 0;
}