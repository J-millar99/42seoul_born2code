#include "Point.hpp"

int main(void)
{
	Point p1(2, 2);
	Point p2(4, 4);
	Point p3(p2);

	std::cout << (bsp(p1, p2, p3, Point(1, 3)) ? "true" : "false") << std::endl;
	return 0;
}