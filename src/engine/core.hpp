#ifndef _ENGINE_CORE_HPP
#define _ENGINE_CORE_HPP

#include <iostream>
#include <memory>
#include <raylib.h>

#include "e_types.hpp"
#include "objects.hpp"

namespace Engine
{
    class Core
    {
    public:
        static bool create_window(cstr_ title, vec2 size);
        static void close_window();

        static void run();
    };
}

#include "source/core.cpp"

#endif