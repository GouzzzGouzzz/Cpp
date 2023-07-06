#include "FixedClass.hpp"

//CONSTRUCTOR

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = obj._value;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = (value << 8);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_fracbits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//FUNCTION

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int	Fixed::toInt( void ) const
{
	return (this->_value >> this->_fracbits);
}

float	Fixed::toFloat( void ) const
{
	return (this->_value / (float)(1 << this->_fracbits));
}

//OVERLOAD

bool Fixed::operator==(const Fixed &B)
{
	if (this->toFloat() == B.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &B)
{
	return (!operator==(B));
}

Fixed& Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = copy._value;
	return (*this);
}

bool Fixed::operator<(const Fixed &B)
{
	if (this->toFloat() < B.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator>(const Fixed &B)
{
	return (!operator<(B));
}

bool Fixed::operator<=(const Fixed &B)
{
	return (!operator>(B));
}

bool Fixed::operator>=(const Fixed &B)
{
	return (!operator<(B));
}

Fixed Fixed::operator-(const Fixed &B)
{
	Fixed tmp;
	tmp = (this->toFloat() - B.toFloat());
	return (tmp);
}

Fixed Fixed::operator+(const Fixed &B)
{
	Fixed tmp;
	tmp._value = (this->getRawBits() + B.getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &B)
{
	Fixed tmp;
	tmp._value = (this->getRawBits() * B.toFloat());
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &B)
{
	Fixed tmp;
	if (B.toFloat() == 0 || this->toFloat() == 0)
	{
		std::cout << "Cannot divide by 0, returning self value" << std::endl;
		tmp.setRawBits(this->getRawBits());
		return (tmp);
	}
	tmp._value = (this->getRawBits() / B.toFloat());
	return (tmp);
}

Fixed Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp;

	tmp._value = this->getRawBits();
	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp;

	tmp._value = this->getRawBits();
	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

//FUNCTIONS

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed &a,Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a,Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}
