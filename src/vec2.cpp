#include "../include/vec2.hpp"
#include <cmath>

using namespace math;

float Vec2::distance(const Vec2& a, const Vec2& b)
{
    return (a - b).magnitude();
}

float Vec2::magnitude() const
{
    return std::sqrt(x * x + y * y);
}

Vec2 Vec2::normalized() const
{
    float mag = magnitude();
    if (mag < 1e-6f)
        return Vec2(0,0);
    return Vec2(x / mag, y / mag);
}

Vec2 Vec2::operator+(const Vec2& other) const
{
    return Vec2( x + other.x , y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const
{
    return Vec2( x - other.x , y - other.y);
}

Vec2 Vec2::operator*(float scalar) const
{
    return Vec2( x * scalar, y * scalar);
}

Vec2 Vec2::operator/(float scalar) const
{
    return Vec2( x / scalar, y / scalar);
}