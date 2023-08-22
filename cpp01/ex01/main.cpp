#include "ZombieClass.hpp"


int main()
{
	Zombie *test = zombieHorde(-1, "greg");
	if (test == NULL)
		return (-1);
	for (int i = 0; i < 10; i++)
		test[i].announce();
	delete [] test;
}
