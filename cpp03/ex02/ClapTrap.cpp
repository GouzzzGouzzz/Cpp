#include "ClapTrap.hpp"

//CONSTRUCTOR

ClapTrap::ClapTrap(std::string name) : _Name(name), _Hitpoints(10), _Energy(10) ,_Max_hp(10), _Attack_dmg(0)
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_Attack_dmg = copy._Attack_dmg;
	this->_Energy = copy._Energy;
	this->_Hitpoints = copy._Hitpoints;
	this->_Name = copy._Name;
	return (*this);
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
	std::cout << this->_Name << " (ClapTrap) attacked " << target << " and deal " << this->_Attack_dmg << " damage\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_Hitpoints <= 0)
	{
		std::cout << this->_Name << " is already dead and can't take more damage !\n";
		return ;
	}
	this->_Hitpoints -= amount;
	if (this->_Hitpoints < 0)
		this->_Hitpoints = 0;
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
	if (this->_Hitpoints >= this->_Max_hp)
	{
		this->_Hitpoints = this->_Max_hp;
		std::cout << this->_Name << " has been fully repaired | Current Hithpoint:" << this->_Hitpoints << "\n";
	}
	else
		std::cout << this->_Name << " has been repaired by a total of "<< amount << " hitpoints | Current Hithpoint:" << this->_Hitpoints << "\n";
}
