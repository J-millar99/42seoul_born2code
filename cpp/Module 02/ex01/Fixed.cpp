#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNum(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::Fixed(const int param)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPointNum = param * (1 << fractionalBit);
}

Fixed::Fixed(const float param)
{
	std::cout << "Float constructor called" << std::endl;
	fixedPointNum = param * (1 << fractionalBit);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return fixedPointNum;
}

void Fixed::setRawBits(int const raw)
{
	fixedPointNum = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)fixedPointNum / (1 << fractionalBit));
}

int Fixed::toInt(void) const
{
	return (int)(fixedPointNum / (1 << fractionalBit));
}

std::ostream& operator<<(std::ostream& os, const Fixed& ref)
{
	return os << ref.toFloat();
}

Fixed &Fixed::operator=(const Fixed &ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fixedPointNum = ref.getRawBits();
	return (*this);
}