#include "tank.h"

void Tank::fire() const
{
    return;
}

std::string Tank::toString () const {
    std::ostringstream oss {};
    oss << "Tank: " << getName()
        << ", With: " << getHealth () << " lifepoints, "
        << "At: " << getPosition ();
    return oss.str();
}
