#ifndef _ENGINE_TYPES_HPP
#define _ENGINE_TYPES_HPP

#include <vector>
#include <memory>

//const double G = 6.6743e-11;

typedef const char* cstr_; // C-style string type


struct vec2 {
    double x;
    double y;

    vec2(double x = 0.0f, double y = 0.0f) : x(x), y(y) {}

    vec2 operator+(const vec2& other) const {
        return vec2(x + other.x, y + other.y);
    }
    vec2 operator-(const vec2& other) const {
        return vec2(x - other.x, y - other.y);
    }
    vec2 operator*(float scalar) const {
        return vec2(x * scalar, y * scalar);
    }
    vec2 operator/(float scalar) const {
        if (scalar != 0.0f) {
            return vec2(x / scalar, y / scalar);
        }
        return vec2(0.0f, 0.0f); // Avoid division by zero
    }
};

typedef struct vec2 vec2;

#endif