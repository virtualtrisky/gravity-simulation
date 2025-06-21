#include <iostream>

#include "engine/core.hpp"

int main()
{
    if (!Engine::Core::create_window("Gravity", {800, 600})) return -1;

    Engine::Core::run();

    Engine::Core::close_window();
}