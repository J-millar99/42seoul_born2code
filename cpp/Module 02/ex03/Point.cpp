#include "Point.hpp"

Point::Point() : x(0), y(0) { }

Point::Point(const float num1, const float num2) : x(num1), y(num2) { }

Point::Point(const Point &ref) : x(ref.x), y(ref.y) { }

Point::~Point() { }

Point &Point::operator=(const Point &ref)
{
    // this->x = ref.x;
    // this->y = ref.y;
    const_cast<Fixed&>(this->x) = ref.x.getRawBits();
    const_cast<Fixed&>(this->y) = ref.y.getRawBits();
	return (*this);
}

int Point::absoluteValue(int num)
{
    return (num < 0) ? -num : num;
}

Fixed Point::getArea(Point const a, Point const b, Point const c)
{
    Fixed ret((a.x.getRawBits() - c.x.getRawBits()) *
            (b.y.getRawBits() - c.y.getRawBits()) -
            (b.x.getRawBits() - c.x.getRawBits()) *
            (a.y.getRawBits() - c.y.getRawBits()));
    ret.setRawBits(absoluteValue(ret.getRawBits()) / 2);
    return ret;
}