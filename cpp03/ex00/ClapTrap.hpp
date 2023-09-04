#pragma once
#include <iostream>

class ClapTrap
{
private:
	std::string  _Name;
	int			 _Hitpoints;
	int			 _Energy;
	unsigned int _Attack_dmg;
public:
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int	amount);
	ClapTrap(std::string);
	ClapTrap(const ClapTrap &copy);
	ClapTrap& operator=(const ClapTrap &cpy);
	~ClapTrap();
};
