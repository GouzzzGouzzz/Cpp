#ifndef FIXEDPOINT_HPP
# define FIXEDPOINT
# include <iostream>
# include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed(const int value);
	Fixed(const float value);
	float toFloat( void ) const;
	int toInt( void ) const;
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed& operator=(Fixed &copy);
	Fixed& operator<<(Fixed &copy);
private:
	int value;
	static const int fracbits = 8;
};

#endif
