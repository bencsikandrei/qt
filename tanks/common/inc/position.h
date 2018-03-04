#pragma once
#include "utils.h"

namespace common {
// The values for X and Y were doubles, but I don't see how that can work (pixel values are
// unsigned ints. But for the purpose of making it work with doubles as well, let's make it
// a template
template<typename ValueType = size_t>
class Position final {
public:
    // TODO consider using StrongTypes ?
    // see: https://github.com/joboccara/NamedType
    using XPos = ValueType;
    using YPos = ValueType;
    // need a default ctor
    explicit Position(XPos x = {}, YPos y = {})
        : m_x { x }, m_y { y }
    {}
    Position(Position const& rhs) = default;
    Position(Position && rhs) = default;
    Position& operator=(Position const& rhs) = default;
    Position& operator=(Position && rhs) = default;

    ~Position() {}

    XPos getX() const { return m_x; }
    YPos getY() const { return m_y; }

    void setX(XPos newX) {m_x = newX; }
    void setY(YPos newY) { m_y = newY; }

    void reset(XPos newX, YPos newY) { m_x = newX; m_y = newY;}
    void reset(Position const& newPos) { reset(newPos.m_x, newPos.m_y);}
private:
    XPos m_x;
    YPos m_y;
};

template <typename ValueType>
inline bool operator==(Position<ValueType> const& p1, Position<ValueType> const& p2) {
    return p1.getX () == p2.getX () && p1.getY() == p2.getY ();
}

template <typename ValueType>
inline bool operator!=(Position<ValueType> const& p1, Position<ValueType> const& p2) {
    return !(p1 == p2);
}

template <typename ValueType>
std::ostream& operator<<(std::ostream& out, Position<ValueType> const& pos) {
    out << "(" << pos.getX () << ", " << pos.getY () << ")";
    return out;
}

} // common
