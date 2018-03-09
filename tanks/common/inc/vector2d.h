#pragma once

#include <utils.h>
#include <cmath>

#define operators /* */
namespace common {
template <
        typename Coordinate,
        typename = typename std::enable_if<std::is_arithmetic<Coordinate>::value, Coordinate>::type // only allow arithmetic types
        >
class Vector2D_ final{
public:
    using value_type = Coordinate;

public:
    static Vector2D_ const One;
    static Vector2D_ const Zero;
public:
    Vector2D_(value_type x = value_type{}, value_type y = value_type{})
        : coordinates { std::make_pair(x, y) }
    {
    }

    Vector2D_(Vector2D_ const& rhs) = default;
    Vector2D_(Vector2D_ && rhs) = default;

    Vector2D_& operator=(Vector2D_ const& rhs) = default;
    Vector2D_& operator=(Vector2D_ && rhs) = default;

public:
    value_type getX() const { return coordinates.first; }
    value_type getY() const { return coordinates.second; }

    void setX(value_type x) { coordinates.first = x; }
    void setY(value_type y) { coordinates.second = y; }

    value_type magnitude() const {
        return std::sqrt(
                    std::pow(coordinates.first,2) + std::pow(coordinates.second, 2)
                    );
    }

    bool equals(Vector2D_ const& other) const {
        return this->coordinates.first == other.coordinates.first &&
                this->coordinates.second == other.coordinates.second;
    }

    Vector2D_ normalized() const {
        static_assert(std::is_floating_point<Coordinate>::value, "Normalized method can't work propely for integers");
        value_type mag { magnitude () };
        return Vector2D_(getX () / mag, getY() / mag );
    }

public operators:
    Vector2D_& operator+=(Vector2D_ const& rhs) {
        this->coordinates.first += rhs.getX ();
        this->coordinates.second += rhs.getY ();
        return *this;
    }
private:
    std::pair<value_type, value_type> coordinates;
};

using Vector2D = Vector2D_<float>;

template <typename T, typename I> Vector2D_<T, I> const Vector2D_<T, I>::One(1, 1);
template <typename T, typename I> Vector2D_<T, I> const Vector2D_<T, I>::Zero(0, 0);

bool operator==(Vector2D v1, Vector2D v2) {
    return v1.equals (v2);
}

Vector2D operator+(Vector2D v1, Vector2D v2) {
    Vector2D sum { v1.getX () + v2.getX (),
                v1.getY () + v2.getY () };
}

Vector2D operator-(Vector2D v1, Vector2D v2) {
    Vector2D dif { v1.getX () - v2.getX (),
                 v1.getY () - v2.getY ()};
}

} // common
