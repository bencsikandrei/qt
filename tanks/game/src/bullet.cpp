#include "bullet.h"

Bullet::Bullet(common::Position<int> const& initialPosition, eHeading const initialHeading, common::Speed speed,
               common::Damage damage)
    : m_position(initialPosition)
    , m_speed(speed)
    , m_damage(damage)
    , m_heading(initialHeading)
{
}

common::Position<int> Bullet::getPosition() const
{
    return m_position;
}

void Bullet::move()
{
    switch (m_heading)
    {
        case eHeading::North:
            m_position.moveOnY(-1);
            break;
        case eHeading::East:
            m_position.moveOnX(1);
            break;
        case eHeading::South:
            m_position.moveOnY(1);
            break;
        case eHeading::West:
            m_position.moveOnX(-1);
            break;
        default:
            break;
    }
}
