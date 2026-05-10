#pragma once

#include "Angle.hpp"

/*
 *  You can argue we don't need this class.
 *  I think it's helpful to explicitly define the units and behaviour
 *  of the angular velocity in our engine.
 */
class AngularVelocity
{
public:
    constexpr AngularVelocity() = default;
    static constexpr AngularVelocity fromRadiansPerSecond(float rps) noexcept
    {
        return AngularVelocity{rps};
    }

    constexpr float radiansPerSecond() const noexcept { return rps_; }
    
    constexpr Angle operator*(float seconds) const noexcept
    {
        return Angle::fromRadians(rps_ * seconds);
    }

private:
    float rps_{};

    constexpr explicit AngularVelocity(float rps) noexcept : rps_(rps) {}
};
