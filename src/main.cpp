#define WIDTH 900
#define HEIGHT 700

#include <iostream>

#include "engine/core.hpp"
#include "engine/e_types.hpp"


void loop() {

}

int main()
{
    if (!Engine::Core::create_window("Gravity", {WIDTH, HEIGHT})) return -1;
    
    Object Earth (2500, 2500, {0, 0},   {0, 0},  {0, 255, 0, 255});
    Object Moon  (1000, 1000, {15000, 0}, {0, 30}, {25, 25, 25, 255});
    Object Corpse(500,  500,  {10000, 50}, {0, 20}, {15, 14, 15, 255});

    Engine::Core::add_object(Earth);
    Engine::Core::add_object(Moon);


    Engine::Core::run(loop);

    Engine::Core::close_window();
}