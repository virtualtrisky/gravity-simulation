#include "../core.hpp"

std::vector<std::shared_ptr<Object>> Engine::Core::objs = {};

Camera2D Engine::Core::camera = { 0 };

bool Engine::Core::create_window(cstr_ title, vec2 size)
{
    if (IsWindowReady()) return false;
    InitWindow(size.x, size.y, title);

    camera.target = (Vector2){0, 0};
    camera.offset = (Vector2){WIDTH/2, HEIGHT/2};
    camera.rotation = 0;
    camera.zoom = 0.01;
    SetTargetFPS(60);
    

    return true;
}

void Engine::Core::close_window()
{
    if (IsWindowReady()) CloseWindow();
}

void Engine::Core::run(void (*loop)())
{
    while (!WindowShouldClose())
    {
        camera.target = (Vector2){1000, HEIGHT/2};
        calculate();

        // draw
        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode2D(camera);
        DrawRectangle(50, 50, 100, 100, WHITE);

        for (std::weak_ptr obj : objs) {
            auto shared = obj.lock();
            vec2 position = shared->get_position();

            DrawCircle(position.x, position.y, shared->get_radius(), shared->get_color());
        }

        EndMode2D();
        


        std::weak_ptr Moon = objs[1];
        auto shared_moon = Moon.lock();
        
        vec2 moon_position = shared_moon->get_position();
        vec2 moon_speed = shared_moon->get_velocity();
        vec2 moon_acceleration = shared_moon->get_acceleration();

        std::string moon_position_text = "Moon position (" + std::to_string(moon_position.x) + ", " + std::to_string(moon_position.y) + ")";
        std::string moon_speed_text = "Moon speed (" + std::to_string(moon_speed.x) + ", " + std::to_string(moon_speed.y) + ")";
        std::string moon_acceleration_text = "Moon acceleration (" + std::to_string(moon_acceleration.x) + ", " + std::to_string(moon_acceleration.y) + ")";

        DrawText(moon_position_text.c_str(), 0, 0, 16, WHITE);
        DrawText(moon_speed_text.c_str(), 0, 20, 16, WHITE);
        DrawText(moon_acceleration_text.c_str(), 0, 40, 16, WHITE);

        EndDrawing();
    }
}

void Engine::Core::calculate() {
    if (objs.size() < 2) return;

    for (size_t i = 0; i < objs.size(); i++) {
        for (size_t j = 1; j < objs.size(); j++) {
            if (i == j) continue;

            std::weak_ptr obj_1 = objs[i];
            std::weak_ptr obj_2 = objs[j];

            auto shared_1 = obj_1.lock();
            auto shared_2 = obj_2.lock();

            const double cathetus_1 = shared_1->get_position().x - shared_2->get_position().x;
            const double cathetus_2 = shared_1->get_position().y - shared_2->get_position().y;
            const double distance = sqrt(pow(cathetus_1, 2) + pow(cathetus_2, 2));

            const double G = 5;

            const double F = (G * (shared_1->get_mass() * shared_2->get_mass()) / pow(distance, 2));

            // normalize direction
            const double direction_x = cathetus_1 / distance;
            const double direction_y = cathetus_2 / distance;

            // split the force into two components
            const double Force_x = F * direction_x;
            const double Force_y = F * direction_y;

            std::system("clear");
            printf("F: %f\nDirection: (%f, %f)\nForce: (%f, %f)\n", F, direction_x, direction_y , Force_x, Force_y);
            shared_2->set_acceleration(vec2(Force_x, Force_y));
            shared_2->update_speed();
            shared_2->move();
        }
    }
}

void Engine::Core::add_object(Object obj) {
    objs.push_back(std::make_shared<Object>(obj));
}