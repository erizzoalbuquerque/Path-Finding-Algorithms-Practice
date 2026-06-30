#pragma once

namespace math
{
    class Vec2
    {
    public:
        
        float x,y;

        constexpr Vec2() : x{0}, y{0} {}
        constexpr Vec2(float x, float y) : x{x}, y{y} {}
        ~Vec2() = default;

        static float distance(const Vec2& a, const Vec2& b);

        float magnitude() const;
        Vec2 normalized() const;
        Vec2 operator+(const Vec2& other) const;
        Vec2 operator-(const Vec2& other) const;
        Vec2 operator*(const float scalar) const;
        Vec2 operator/(const float scalar) const;
    };

    namespace vec2
    {
        inline constexpr Vec2 zero  = {0, 0};
        inline constexpr Vec2 one   = {1, 1};
        inline constexpr Vec2 up    = {0, 1};
        inline constexpr Vec2 down  = {0, -1};
        inline constexpr Vec2 right = {1, 0};
        inline constexpr Vec2 left  = {-1, 0};
    }
}