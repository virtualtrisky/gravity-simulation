#ifndef _ENGINE_OBJECTS_HPP
#define _ENGINE_OBJECTS_HPP

#include <iostream>

#include "e_types.hpp"

namespace Engine
{
    struct Object
    {
    private:
        float radius;
        float mass;
        vec2 position;
        vec2 velocity;
        vec2 acceleration;
        Color color;

    public:
        Object(float _radius, float _mass, vec2 _position, vec2 _acceleration, Color _color)
            : radius(_radius), mass(_mass), position(_position), acceleration(_acceleration), color(_color) {}

        float get_radius()      const { return radius; }
        float get_mass()        const { return mass; }
        vec2 get_velocity()     const { return velocity; }
        vec2 get_acceleration() const { return acceleration; }
        Color get_color()       const { return color; }
        
        vec2 get_position() const { return position; }
        void add_position(vec2 new_pos) { position = position + new_pos; }

        void move();
        void update_speed();
        void set_acceleration(vec2);
    };
}

typedef Engine::Object Object;

#include "source/objects.cpp"

#endif