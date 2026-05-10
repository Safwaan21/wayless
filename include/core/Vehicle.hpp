#pragma once

#include "Pos2.hpp"
#include "Entity.hpp"
#include "Angle.hpp"
#include "AngularVelocity.hpp"
#include <stdexcept>
#include <cmath>
#include <utility>

class Vehicle : public Entity
{
friend class VehicleBuilder;
public:
    void update(float speed, Angle steeringAngle, float dt)
    {
        if (steeringAngle.radians() != 0.0f)
        {
            float R = wheelbase / std::tan(steeringAngle.radians()) + trackWidth / 2.0f;
            angularVelocity = AngularVelocity::fromRadiansPerSecond(speed / R);
            heading += angularVelocity * dt;
        }
        else
        {
            angularVelocity = AngularVelocity{};
        }
        pos = pos + Pos2(speed * std::cos(heading.radians()), speed * std::sin(heading.radians())) * dt;
    }
private:
    Angle heading;
    float speed{};
    AngularVelocity angularVelocity{};
    Angle steeringAngle{};
    float wheelbase;   // front-to-back distance between wheel-centres
    float trackWidth;  // left-to-right distance between wheel-centres
};

class VehicleBuilder
{
public:
    VehicleBuilder& withPos(Pos2 pos)
    {
        this->pos = std::move(pos);
        hasPos = true;
        return *this;
    }
    VehicleBuilder& withHeading(Angle heading)
    {
        this->heading = heading;
        hasHeading = true;
        return *this;
    }
    VehicleBuilder& withWheelbase(float wheelbase)
    {
        this->wheelbase = wheelbase;
        hasWheelbase = true;
        return *this;
    }
    VehicleBuilder& withTrackWidth(float trackWidth)
    {
        this->trackWidth = trackWidth;
        hasTrackWidth = true;
        return *this;
    }
    Vehicle build()
    {
        if (!hasPos)        throw std::invalid_argument("VehicleBuilder: pos is required");
        if (!hasHeading)    throw std::invalid_argument("VehicleBuilder: heading is required");
        if (!hasWheelbase)  throw std::invalid_argument("VehicleBuilder: wheelbase is required");
        if (!hasTrackWidth) throw std::invalid_argument("VehicleBuilder: trackWidth is required");

        Vehicle v;

        v.pos = this->pos;
        v.heading = this->heading;
        v.wheelbase = this->wheelbase;
        v.trackWidth = this->trackWidth;
        // TODO: implement remaining with functions for other optional params

        return v;
    }
private:
    Pos2 pos;
    Angle heading;
    float speed{};
    AngularVelocity angularVelocity{};
    Angle steeringAngle{};
    float wheelbase;
    float trackWidth;
    bool hasPos{};
    bool hasHeading{};
    bool hasWheelbase{};
    bool hasTrackWidth{};
};

