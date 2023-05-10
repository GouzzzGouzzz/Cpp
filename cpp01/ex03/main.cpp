#include <iostream>
#include "HumanAClass.hpp"
#include "HumanBClass.hpp"

int main()
{
 	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		std::cout << club.getType() << std::endl;
		jim.attack();
	}
	return 0;
}
