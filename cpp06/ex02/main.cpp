#include "Base.hpp"
#include <iostream>

int main()
{
	Base test;
	Base *a;
	std::cout << "\nTESTING GENERATION\n\n";
	for (int i = 0; i < 10; i++)
	{
		a = test.generate();
		delete a;
	}
	std::cout << "\nTESTING IDENTIFY WITH POINTERS\n\n";
	for (int i = 0; i < 10; i++)
	{
		a = test.generate();
		test.identify(a);
		delete a;
	}
	std::cout << "\nTESTING IDENTIFY WITH ADDRESS\n\n";
	for (int i = 0; i < 10; i++)
	{
		a = test.generate();
		test.identify((*a));
		delete a;
	}
}
