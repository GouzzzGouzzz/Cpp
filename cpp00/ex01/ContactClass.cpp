#include "ContactClass.hpp"
#include <iostream>

Contact::Contact(void)
{
	std::cout << "Constructur called" << std::endl;

}

Contact::~Contact(void)
{
	std::cout << "Destructor called" << std::endl;
}
