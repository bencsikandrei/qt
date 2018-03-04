#pragma once

#include <position.h>

using Health = common::Health;
using Damage = common::Damage;
using Name = common::Name;

class Vehicle
{
public:
    using Position = common::Position<int>;
    using XPos = Position::XPos;
    using YPos = Position::YPos;

    virtual ~Vehicle() {}

    virtual Position move(Position newPos);

    virtual Position move(XPos xpos, YPos ypos);

    virtual void fire() const = 0;

    virtual void receiveDamage(Damage /*dmg*/) { return; }

    virtual Position getPosition() const { return m_position;}
    virtual Name getName() const { return m_name; }
    virtual Health getHealth() const { return m_health; }
    virtual bool isAlive() const { return (m_health > 0); }

    virtual std::string toString() const = 0;

protected:
    Vehicle();
    Vehicle(XPos xpos, YPos ypos);
    Vehicle(Position initialPosition);
    Vehicle(Name name, Position initialPosition, Health health);

private:
    Name m_name;
    Position m_position;
    Health m_health;
};

std::ostream& operator<<(std::ostream& out, Vehicle const& vehicle);
