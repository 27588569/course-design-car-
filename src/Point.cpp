#include "./Point.hpp"
namespace adas
{
Point::Point(const int x, const int y) noexcept : x(x), y(y)
{
}
Point& Point::operator+=(const Point& rhs) noexcept
{
    x += rhs.GetX();
    y += rhs.GetY();
    return *this;
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