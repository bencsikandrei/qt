#pragma once

#include <position.h>

using Health = common::Health;
using Damage = common::Damage;

class Vehicle
{
public:
    using Position = common::Position<int>;
    using XPos = Position::XPos;
    using YPos = Position::YPos;

    virtual ~Vehicle() {}

    virtual Position move(Position newPos) {
        return move(newPos.getX (), newPos.getY ());
    }

    virtual Position move(XPos xpos, YPos ypos) {
        Position oldPosition = m_position;
        m_position.reset (xpos, ypos);
        return oldPosition;
    }

    virtual void fire() const = 0;

    virtual Health getHealth() const
    {
        return m_health;
    }

    virtual void receiveDamage(Damage /*dmg*/)
    {
        return;
    }
    virtual bool isAlive() const
    {
        return (m_health > 0);
    }

    virtual Position getPosition() const {
        return m_position;
    }

protected:
    Vehicle()
        : m_position { },
          m_health { common::DEFAULT_VEHICLE_HEALTH }
    {}

    Vehicle(XPos xpos, YPos ypos)
        : Vehicle{}
    {
        m_position.reset (xpos, ypos);
    }

    Vehicle(Position initialPosition)
         : Vehicle{}
    {
        m_position.reset (initialPosition);
    }


private:
    Position m_position;
    Health m_health;
};
