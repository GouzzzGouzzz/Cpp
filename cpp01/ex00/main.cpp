#include "ZombieClass.hpp"


int main()
{
	Zombie truc("truc");
	truc.announce();
	Zombie *test;
	test = newZombie("test");
	test->announce();
	randomChump("bizarre");
	delete test;
}
