#pragma once

#include <utils.h>
#include <cmath>

namespace common {
template <
        typename Coordinate,
        typename = typename std::enable_if<std::is_arithmetic<Coordinate>::value, Coordinate>::type // only allow arithmetic types
        >
class Vector2D_ final{
public:
    using value_type = Coordinate;
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

    Vector2D_ normalized() const {
        static_assert(std::is_floating_point<Coordinate>::value, "Normalized method can't work propely for integers");
        value_type mag { magnitude () };
        return Vector2D_(coordinates.first / mag, coordinates.second / mag );
    }
private:
    std::pair<value_type, value_type> coordinates;
};

namespace consts {
}

using Vector2D = Vector2D_<float>;

} // common
