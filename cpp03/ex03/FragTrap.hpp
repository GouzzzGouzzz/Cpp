#pragma once
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap(std::string name);
	FragTrap();
	~FragTrap();
	void highFivesGuy(void);
	FragTrap(const FragTrap &copy);
	FragTrap& operator=(const FragTrap &cpy);
};


