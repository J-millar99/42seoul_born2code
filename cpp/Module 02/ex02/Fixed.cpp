#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNum(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}
Fixed::Fixed(const int &param)
{
	// std::cout << "Int constructor called" << std::endl;
	fixedPointNum = param * (1 << fractionalBit);
}

Fixed::Fixed(const float &param)
{
	// std::cout << "Float constructor called" << std::endl;
	fixedPointNum = param * (1 << fractionalBit);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Fixed &ref)
{
	os << ref.toFloat();
	return (os);
}

Fixed &Fixed::operator=(const Fixed &ref)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	fixedPointNum = ref.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &ref)
{
	return this->fixedPointNum > ref.fixedPointNum;
}

bool Fixed::operator<(const Fixed &ref)
{
	return this->fixedPointNum < ref.fixedPointNum;
}

bool Fixed::operator>=(const Fixed &ref)
{
	return !(this->fixedPointNum < ref.fixedPointNum);
}

bool Fixed::operator<=(const Fixed &ref)
{
	return !(this->fixedPointNum > ref.fixedPointNum);
}

bool Fixed::operator==(const Fixed &ref)
{
	return this->fixedPointNum == ref.fixedPointNum;
}

bool Fixed::operator!=(const Fixed &ref)
{
	return !(this->fixedPointNum == ref.fixedPointNum);
}

Fixed Fixed::operator+(const Fixed &ref)
{
	return Fixed(this->toFloat() + ref.toFloat());
}

Fixed Fixed::operator-(const Fixed &ref)
{
	return Fixed(this->toFloat() - ref.toFloat());
}

Fixed Fixed::operator*(const Fixed &ref)
{
	return Fixed(this->toFloat() * ref.toFloat());
}

Fixed Fixed::operator/(const Fixed &ref)
{
	return Fixed(this->toFloat() / ref.toFloat());
}

Fixed &Fixed::operator++()
{
	fixedPointNum++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	fixedPointNum++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	fixedPointNum--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	fixedPointNum--;
	return (temp);
}

Fixed &Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1.toFloat() < ref2.toFloat())
		return ref1;
	else
		return ref2;
}

Fixed const &Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1.toFloat() < ref2.toFloat())
		return ref1;
	else
		return ref2;
}

Fixed &Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1.toFloat() > ref2.toFloat())
		return ref1;
	else
		return ref2;
}

Fixed const &Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1.toFloat() > ref2.toFloat())
		return ref1;
	else
		return ref2;
}
