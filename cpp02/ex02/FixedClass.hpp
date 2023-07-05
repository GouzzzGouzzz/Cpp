#ifndef FIXEDPOINT_HPP
# define FIXEDPOINT_HPP
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
	Fixed& operator=(const Fixed &copy);
	bool operator==(const Fixed &other);
	bool operator!=(const Fixed &other);
	bool operator<(const Fixed &other);
	bool operator>(const Fixed &other);
	bool operator>=(const Fixed &other);
	bool operator<=(const Fixed &other);
	Fixed operator+(const Fixed &other);
	Fixed operator-(const Fixed &other);
	Fixed operator/(const Fixed &other);
	Fixed operator*(const Fixed &other);
	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);
private:
	int _value;
	static const int _fracbits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
