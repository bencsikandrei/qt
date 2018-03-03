#ifndef TANK_H
#define TANK_H

#include "eheading.h"
#include <position.h>

class Tank
{
public:
    using Position = common::Position_i;
    Tank(eHeading heading, Position position);

private:
    eHeading m_heading;
    Position m_position;
};

#endif
