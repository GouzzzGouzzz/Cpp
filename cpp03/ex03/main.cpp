#include "DiamondTrap.hpp"

int main()
{
	if (0 == 1)
	{
		ClapTrap Joe("Joe");
		ClapTrap Bob("Bob");
		std::cout << "\nJoe is attacking bob :\n\n";
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


	ScavTrap Jack("Jack");
	ScavTrap Michel("Michel");

	std::cout << "\nJack is attacking Michel :\n\n";
	for (int i = 0; i < 3; i++)
	{
		Jack.attack("Michel");
		Michel.takeDamage(20);
	}
	std::cout << "\nMichel is reparing himself:\n\n";
	Michel.beRepaired(23);
	Michel.beRepaired(213123);
	std::cout << "\nMichel can't do anything when dead:\n\n";
	Michel.takeDamage(220);
	Michel.attack("Jack");
	Michel.beRepaired(23);
	Michel.guardGate();

	FragTrap machin("machin");

	machin.highFivesGuy();
	machin.attack("Bidule");
	machin.takeDamage(10);
	machin.beRepaired(5);
	machin.takeDamage(94);
	for(int i = 0; i < 101; i++)
		machin.beRepaired(1);
	}

	DiamondTrap Roucoups("Roucoups");

	Roucoups.whoAmI();
	Roucoups.guardGate();
	Roucoups.highFivesGuy();
	Roucoups.attack("Tiplouf");
	Roucoups.takeDamage(2);
	Roucoups.beRepaired(1);
}
