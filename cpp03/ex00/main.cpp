#include "ClapTrap.hpp"


int main()
{
	ClapTrap Joe("Joe");
	ClapTrap Bob("Bob");

	std::cout << "\nJoe is attacking Bob :\n\n";
	for (int i = 0; i < 3; i++)
	{
		Joe.attack("Bob");
		Bob.takeDamage(0);
	}

	std::cout << "\nBob will some take damage :\n\n";
	for (int i = 0; i < 6; i++)
		Bob.takeDamage(1);

	std::cout << "\nTrying to repair bob before he die: \n\n";
	Bob.beRepaired(3);
	Bob.beRepaired(10);

	std::cout << "\nBob will take damage until he die :\n\n";
	for (int i = 0; i < 11; i++)
		Bob.takeDamage(1);

	std::cout << "\nTrying to repair and attack with bob when he is dead: \n\n";
	Bob.beRepaired(10);
	Bob.attack("Joe");
}
