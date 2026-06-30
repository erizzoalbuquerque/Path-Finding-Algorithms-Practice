#include <gtest/gtest.h>
#include "../include/vec2.hpp"

using namespace math;

TEST(Vec2, DefaultConstructor) {
    Vec2 v;
    EXPECT_FLOAT_EQ(v.x, 0.0f);
    EXPECT_FLOAT_EQ(v.y, 0.0f);
}

TEST(Vec2, ParameterizedConstructor) {
    Vec2 v(3.0f, 4.0f);
    EXPECT_FLOAT_EQ(v.x, 3.0f);
    EXPECT_FLOAT_EQ(v.y, 4.0f);
}

TEST(Vec2, Addition)
{
    Vec2 result = Vec2(1.f,2.f) + Vec2(3.f,4.f);
    EXPECT_FLOAT_EQ(result.x, 4.f);
    EXPECT_FLOAT_EQ(result.y,6.f);
}

TEST(Vec2, Subtraction)
{
    Vec2 result = Vec2(1.f,2.f) - Vec2(3.f,4.f);
    EXPECT_FLOAT_EQ(result.x, -2.f);
    EXPECT_FLOAT_EQ(result.y,-2.f);
}

TEST(Vec2, ScalarMultiplication)
{
    Vec2 result = Vec2(1.f,2.f) * 3.f;
    EXPECT_FLOAT_EQ(result.x, 3.f);
    EXPECT_FLOAT_EQ(result.y,6.f);
}

TEST(Vec2, ScalarDivision)
{
    Vec2 result = Vec2(6.f,8.f) / 2.f;
    EXPECT_FLOAT_EQ(result.x, 3.f);
    EXPECT_FLOAT_EQ(result.y,4.f);
}

TEST(Vec2, Magnitude)
{
    EXPECT_FLOAT_EQ(Vec2(3.f,4.f).magnitude(), 5.f);
    EXPECT_FLOAT_EQ(Vec2{}.magnitude(), 0.f);
}

TEST(Vec2Test, Normalized) {
    Vec2 n = Vec2{3.f, 4.f}.normalized();
    EXPECT_FLOAT_EQ(n.x, 0.6f);
    EXPECT_FLOAT_EQ(n.y, 0.8f);
}

TEST(Vec2Test, Distance) {
    EXPECT_FLOAT_EQ(Vec2::distance(Vec2{0.f, 0.f}, Vec2{3.f, 4.f}), 5.f);
}

TEST(Vec2Test, Constants) {
    EXPECT_FLOAT_EQ(vec2::zero.x, 0.f);
    EXPECT_FLOAT_EQ(vec2::up.y, 1.f);
    EXPECT_FLOAT_EQ(vec2::right.x, 1.f);
    EXPECT_FLOAT_EQ(vec2::left.x, -1.f);
    EXPECT_FLOAT_EQ(vec2::down.y, -1.f);
}