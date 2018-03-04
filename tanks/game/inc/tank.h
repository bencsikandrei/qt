#pragma once

#include "eheading.h"
#include "vehicle.h"

class Tank : public Vehicle
{
public:
    Tank()
        : Vehicle()
    {}
    Tank(Vehicle::XPos xpos, Vehicle::YPos ypos)
        : Vehicle(xpos, ypos)
    {}
    Tank(Vehicle::Position initialPosition)
        : Vehicle(initialPosition)
    {}
    Tank(common::Name name, Vehicle::Position initialPosition, common::Health health)
        : Vehicle(name, initialPosition, health)
    {
    }
    Tank(Tank const& rhs) = delete;
    Tank(Tank && rhs) = delete;
    Tank& operator=(Tank const& rhs) = delete;
    Tank& operator=(Tank && rhs) = delete;

    virtual  ~Tank() {}

    void fire() const override;
    std::string toString() const override;

private:
};

