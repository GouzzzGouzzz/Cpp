#ifndef FIXEDPOINT_HPP
# define FIXEDPOINT
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
	int value;
	static const int fracbits = 8;
};

#endif
