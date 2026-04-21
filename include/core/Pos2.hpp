#pragma once

struct Pos2
{
    float x{}, y{};

    // Initializes x,y with zero's.
    constexpr Pos2() = default;
    constexpr Pos2(float x_val, float y_val) noexcept : x(x_val), y(y_val) {}

    constexpr Pos2 operator+(const Pos2 &other) const noexcept
    {
        return {x + other.x, y + other.y};
    }
    constexpr Pos2 operator-(const Pos2 &other) const noexcept
    {
        return {x - other.x, y - other.y};
    }
    constexpr Pos2 operator*(float scalar) const noexcept
    {
        return {x * scalar, y * scalar};
    }
};