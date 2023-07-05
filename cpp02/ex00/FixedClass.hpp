#ifndef FIXEDPOINT_HPP
# define FIXEDPOINT_HPP
# include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &obj);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed& operator=(Fixed &copy);
private:
	int _value;
	static const int _fracbits = 8;
};

#endif
