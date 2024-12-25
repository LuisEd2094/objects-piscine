#ifndef VECTOR2_HPP
#   define VECTOR2_HPP

#include <ostream>
typedef struct Vector2
{
    float points[2];
    Vector2(float x, float y)
    {
        points[0] = x;
        points[1] = y;
    };
} Vector2;

// Inline because it's a small function and I don't want to create a .cpp file for it
inline std::ostream &operator<<(std::ostream &os, const Vector2 &vec)
{
    os << "Vector2(" << vec.points[0] << ", " << vec.points[1] << ")";
    return os;
}

#endif