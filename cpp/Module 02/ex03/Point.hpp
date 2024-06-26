#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
        //addable
    
    public:
        Point();
        Point(const float num1, const float num2);
        Point(const Point &ref);
        ~Point();

        Point& operator=(const Point &ref);

        static Fixed getArea(Point const p, Point const a, Point const b);
        static int absoluteValue(int num);
};

#endif