#ifndef VECTOR2_HPP
#define VECTOR2_HPP

typedef struct Vector2
{
    float points[2];
    Vector2(float y, float x)
    {
        points[0] = y;
        points[1] = x;
    };
} Vector2;

#endif