#ifndef _ENGINE_CORE_HPP
#define _ENGINE_CORE_HPP

#ifndef WIDTH
#define WIDTH 900
#endif

#ifndef HEIGHT
#define HEIGHT 700
#endif

#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include <raylib.h>

#include "e_types.hpp"
#include "objects.hpp"

namespace Engine
{
    class Core
    {
    private:
        static std::vector<std::shared_ptr<Object>> objs;
        static Camera2D camera;

    public:
        static bool create_window(cstr_ title, vec2 size);
        static void close_window();

        static void run(void (*loop)());

        static void calculate();

        static void add_object(Object);
        static std::vector<std::shared_ptr<Object>> get_objects() { return objs; }
    };
}

#include "source/core.cpp"

#endif