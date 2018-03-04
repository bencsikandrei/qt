#include <vehicle.h>


Vehicle::Vehicle()
    : m_name { },
      m_position { },
      m_health { common::DEFAULT_VEHICLE_HEALTH }
{}

Vehicle::Vehicle(XPos xpos, YPos ypos)
    : Vehicle{}
{
    m_position.reset (xpos, ypos);
}

Vehicle::Vehicle(Position initialPosition)
    : Vehicle{}
{
    m_position.reset (initialPosition);
}


Vehicle::Vehicle(Name name, Position initialPosition, Health health)
    : m_name { name },
      m_position { initialPosition },
      m_health { health }
{
}

std::ostream& operator<<(std::ostream& out, Vehicle const& vehicle) {
    out << vehicle.toString();
    return out;
}

Vehicle::Position Vehicle::move(Position newPos) {
    return move(newPos.getX (), newPos.getY ());
}

Vehicle::Position Vehicle::move(XPos xpos, YPos ypos) {
    Position oldPosition = m_position;
    m_position.reset (xpos, ypos);
    return oldPosition;
}
