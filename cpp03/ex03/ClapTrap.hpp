#pragma once
#include <iostream>

class ClapTrap
{
protected:
	std::string  _Name;
	int			 _Hitpoints;
	int			 _Energy;
	int			 _Max_hp;
	unsigned int _Attack_dmg;
public:
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int	amount);
	ClapTrap(std::string);
	ClapTrap();
	~ClapTrap();
};
