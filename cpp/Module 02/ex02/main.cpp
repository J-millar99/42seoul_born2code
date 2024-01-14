#include "Fixed.hpp"

int main(void)
{
	std::cout << "*6 comparison operators*" << std::endl;
	std::cout << (Fixed(5.05f) > Fixed(2) ? "true" : "false") << std::endl;
	std::cout << (Fixed(5.05f) < Fixed(2) ? "true" : "false") << std::endl;
	std::cout << (Fixed(5.05f) <= Fixed(2) ? "true" : "false") << std::endl;
	std::cout << (Fixed(5.05f) >= Fixed(2) ? "true" : "false") << std::endl;
	std::cout << (Fixed(5.05f) == Fixed(2) ? "true" : "false") << std::endl;
	std::cout << (Fixed(5.05f) != Fixed(2) ? "true" : "false") << std::endl << std::endl;
	

	std::cout << "*4 arithmetic operators*" << std::endl;
	std::cout << Fixed(5.05f) + Fixed(2) << std::endl;
	std::cout << Fixed(5.05f) - Fixed(2) << std::endl;
	std::cout << Fixed(5.05f) * Fixed(0) << std::endl;
	std::cout << Fixed(0) / Fixed(0) << std::endl << std::endl; //acceptable that the program crashes!

	std::cout << "*4 increment/decrement operators*" << std::endl;
	Fixed a(1.1f);
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl << std::endl;

	std::cout << "*min, max*" << std::endl;
	std::cout << Fixed::min(Fixed(5.05f), Fixed(2)) << std::endl;
	std::cout << Fixed::max(Fixed(5.05f), Fixed(2)) << std::endl;
	return 0;
}