#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	private:
		int fixedPointNum;
		static const int fractionalBit = 8;

	public:
		Fixed();
		Fixed(const Fixed &ref);
		Fixed(const int &param);
		Fixed(const float &param);
		~Fixed();

		Fixed& operator=(const Fixed &ref);

		bool operator>(const Fixed &ref);
		bool operator<(const Fixed &ref);
		bool operator>=(const Fixed &ref);
		bool operator<=(const Fixed &ref);
		bool operator==(const Fixed &ref);
		bool operator!=(const Fixed &ref);

		Fixed operator+(const Fixed &ref);
		Fixed operator-(const Fixed &ref);
		Fixed operator*(const Fixed &ref);
		Fixed operator/(const Fixed &ref);
		
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		static Fixed& min(Fixed &ref1, Fixed &ref2);
		static const Fixed& min(const Fixed &ref1, const Fixed &ref2);
		static Fixed& max(Fixed &ref1, Fixed &ref2);
		static const Fixed& max(const Fixed &ref1, const Fixed &ref2);
		
};

std::ostream& operator<<(std::ostream& os, const Fixed &ref);

#endif