#pragma once

class Angle
{
public: 
    constexpr Angle() = default;
    static constexpr Angle fromRadians(float rad) noexcept { return Angle{rad}; }
    static constexpr Angle fromDegrees(float deg) noexcept { return Angle{deg * kDegToRad}; }
    
    constexpr float radians() const noexcept { return rad_; }
    constexpr float degrees() const noexcept { return rad_ * kRadToDeg; }

    constexpr Angle& operator+=(Angle other) noexcept
    {
        rad_ += other.rad_;
        return *this;
    }

private:
    float rad_{};
    
    // Explicit keyword is redundant under private access, but defensive
    constexpr explicit Angle(float rad) noexcept : rad_(rad) {}

    static constexpr float kPi = 3.14159265358979323846f;
    static constexpr float kDegToRad = kPi / 180.0f;
    static constexpr float kRadToDeg = 180.0f / kPi; 
};
