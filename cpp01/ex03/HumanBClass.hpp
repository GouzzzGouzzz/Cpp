#ifndef HumanB_Class_HPP
# define HumanB_Class_HPP
# include <iostream>
# include "WeaponClass.hpp"

class HumanB
{
public:
	HumanB(const char*);
	~HumanB();
	void setWeapon(Weapon&);
	void attack(void);
private:
	std::string name;
	Weapon *weapon;
};

#endif
