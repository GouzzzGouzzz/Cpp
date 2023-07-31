#include "ZombieClass.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;
	if (N < 0)
	{
		std::cout << "Negative value isn't supported\n";
		return NULL;
	}
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].set_name(name);
	return horde;
}
