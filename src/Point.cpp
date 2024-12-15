#include "Point.hpp"

namespace adas
{
Point::Point(const int x, const int y) noexcept : x(x), y(y)
{
}

Point::Point(const Point& rhs) noexcept : x(rhs.x), y(rhs.y)
{
}

Point& Point::operator=(const Point& rhs) noexcept
{
    x = rhs.x;
    y = rhs.y;
    return *this;
}

Point& Point::operator+=(const Point& rhs) noexcept
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Point& Point::operator-=(const Point& rhs) noexcept
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Point Point::operator-(const Point& rhs) const noexcept
{
    Point tmp(*this);
    tmp -= rhs;
    return tmp;
}

int Point::GetX(void) const noexcept
{
    return x;
}
int Point::GetY(void) const noexcept
{
    return y;
}

}  // namespace adas