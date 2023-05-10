#include "ZombieClass.hpp"


Zombie::Zombie( std::string name)
{
	this->name = name;
	std::cout << "Constructor called by "<< this->name << std::endl;
}

Zombie::Zombie()
{
	std::cout << "Constructor called by a random zombie " << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destructor called by "<< this->name << std::endl;
}

std::string Zombie::get_name()
{
	return this->name;
}

void	Zombie::set_name( std::string name )
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
