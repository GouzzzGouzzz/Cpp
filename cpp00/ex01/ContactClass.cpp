#include "ContactClass.hpp"
#include <iostream>

Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
}

void	Contact::set_firstname(std::string str)
{
	this->first_name = str;
}

void	Contact::set_lastname(std::string str)
{
	this->last_name = str;
}

void	Contact::set_nickname(std::string str)
{
	this->nickname = str;
}

void	Contact::set_phone(std::string str)
{
	this->phone = str;
}

void	Contact::set_secret(std::string str)
{
	this->secret = str;
}

std::string	Contact::get_firstname(void)
{
	return (this->first_name);
}

std::string	Contact::get_lastname(void)
{
	return (this->last_name);
}

std::string	Contact::get_nickname(void)
{
	return (this->nickname);
}

std::string	Contact::get_phone(void)
{
	return (this->phone);
}

std::string	Contact::get_secret(void)
{
	return (this->secret);
}
