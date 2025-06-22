#include "../objects.hpp"

void Engine::Object::move() {
    position = position + velocity;
}

void Engine::Object::update_speed() {
    velocity = acceleration;
}

void Engine::Object::set_acceleration(vec2 acc) {
    acceleration = acceleration + acc;
}