#pragma once

#include "position.h"
#include "eheading.h"

class Bullet
{
public:
    explicit Bullet(common::Position const& initialPosition = common::Position(),
                    eHeading const initialHeading = eHeading::North, common::Speed const = common::Speed{},
                    common::Damage damage = common::Damage{});

    Bullet(Bullet const& rhs) = default;

    Bullet(Bullet&& rhs) = default;

    Bullet& operator=(Bullet const& rhs) = default;

    Bullet& operator=(Bullet&& rhs) = default;

    common::Position getPosition() const;

    void move();

private:
    common::Position m_position;
    common::Speed         m_speed;
    common::Damage        m_damage;
    eHeading              m_heading;
};
