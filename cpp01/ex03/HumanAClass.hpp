#ifndef HumanA_Class_HPP
# define HumanA_Class_HPP
# include <iostream>
# include "WeaponClass.hpp"

class HumanA
{
public:
	HumanA( const char*, Weapon&);
	~HumanA();
	void attack( void );
private:
	std::string name;
	Weapon	*weapon;
};

#endif
