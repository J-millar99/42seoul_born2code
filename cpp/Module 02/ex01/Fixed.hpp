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

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		
};

std::ostream& operator<<(std::ostream& os, const Fixed &ref);