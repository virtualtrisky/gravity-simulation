#include "../core.hpp"

bool Engine::Core::create_window(cstr_ title, vec2 size)
{
    if (IsWindowReady()) return false;

    InitWindow(size.x, size.y, title);
    SetTargetFPS(60);

    return true;
}

void Engine::Core::close_window()
{
    if (IsWindowReady()) CloseWindow();
}

void Engine::Core::run()
{
    while (!WindowShouldClose())
    {
        // draw
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
}