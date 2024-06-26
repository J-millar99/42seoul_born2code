#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed subArea1, subArea2, subArea3;
    Fixed area;

    subArea1 = Point::getArea(point, a, b);
    subArea2 = Point::getArea(point, b, c);
    subArea3 = Point::getArea(point, c, a);
    area = Point::getArea(a, b, c);

    if (!subArea1.getRawBits() || !subArea2.getRawBits() || !subArea3.getRawBits())
        return false;
    return (subArea1 + subArea2 + subArea3 == area ? true : false);
}