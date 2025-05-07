#include "main_includes.hpp"

using namespace std;

#pragma region MCR

#pragma region WINDOW
#define BG_COLOR Color{47, 40, 69, 255}
#define WIDTH 900
#define HEIGHT 900
#define WINDOW_NAME "GEOMETRY SIMULATOR"
#pragma endregion WINDOW

#pragma region OBJS
#define POINT Simulator::Point
#define SPAWN_POINT Simulator::Scene::AddPoint

#define SEGMENT Simulator::Segment
#define SPAWN_SEGMENT Simulator::Scene::AddSegment

#pragma endregion OBJS

#define INIT_SETTINGS Simulator::Settings::Init()

#pragma endregion MCR

int main()
{
    INIT_SETTINGS;

    POINT p({1, 0}, "C");
    POINT p1({2, 50}, "D");

    SPAWN_POINT(&p);
    SPAWN_POINT(&p1);

    SEGMENT s(&p, &p1);
    SPAWN_SEGMENT(&s);

    SetTraceLogLevel(LOG_NONE);
    InitWindow(WIDTH, HEIGHT, WINDOW_NAME);

    Simulator::Camera camera = Simulator::Camera();
    Simulator::Scene::_camera = &camera;

    float t = 0;

    while (!WindowShouldClose())
    {
        t+=0.0001f;
        p1.position.x = (sin(t)) * 50;
        p1.position.y = (cos(t)) * 50;

        p.position.x = (sin(t + 10)) * 50;
        p.position.y = (cos(t + 10)) * 50;
        BeginDrawing();
        camera.Move();
        ClearBackground(BG_COLOR);
        Simulator::Scene::SceneProcess();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}