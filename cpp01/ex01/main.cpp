#include "Zombie.hpp"

int main()
{
	Zombie *test = zombieHorde(10, "greg");
	for (int i = 0; i < 10; i++)
		test[i].announce();
	delete [] test;
}
