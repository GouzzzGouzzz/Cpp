#include "ClapTrap.hpp"

//CONSTRUCTOR

ClapTrap::ClapTrap(std::string name) : _Name(name), _Hitpoints(10), _Energy(10), _Attack_dmg(0)
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called\n";
}

//FUNCTIONS

void	ClapTrap::attack(const std::string& target)
{
	if (this->_Hitpoints <= 0)
	{
		std::cout << this->_Name << " is already dead and can't attack !\n";
		return ;
	}
	if (this->_Energy <= 0)
	{
		std::cout << this->_Name << " is out of energy, couldn't attack\n";
		return ;
	}
	this->_Energy--;
	std::cout << this->_Name << " attacked " << target << " and deal " << this->_Attack_dmg << " damage\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_Hitpoints <= 0)
	{
		std::cout << this->_Name << " is already dead and can't take more damage !\n";
		return ;
	}
	this->_Hitpoints -= amount;
	std::cout << this->_Name << " has taken " << amount << " damage ! | Current hitpoints :" << this->_Hitpoints << "\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Hitpoints <= 0)
	{
		std::cout << this->_Name << " is already dead and can't repair himself !\n";
		return ;
	}
	if (this->_Energy <= 0)
	{
		std::cout << this->_Name << " is out of energy, couldn't repair\n";
		return ;
	}
	this->_Energy--;
	this->_Hitpoints += amount;
	if (this->_Hitpoints >= 10)
	{
		this->_Hitpoints = 10;
		std::cout << this->_Name << " has been fully repaired | Current Hithpoint:" << this->_Hitpoints << "\n";
	}
	else
		std::cout << this->_Name << " has been repaired by a total of "<< amount << " hitpoints | Current Hithpoint:" << this->_Hitpoints << "\n";
}
