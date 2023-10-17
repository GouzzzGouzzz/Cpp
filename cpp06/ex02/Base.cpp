#include "Base.hpp"
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
Base::~Base()
{
	std::cout << "Base class destructor called\n";
}

//FUNCTIONS

Base* Base::generate(void)
{
	static bool init = false;
	if (init)
	{
		srand(time(NULL));
		init = false;
	}
	int random = (rand() % 3) + 1;
	if (random == 1){
		std::cout << "Returning A\n";
		return new A();
	}
	else if (random == 2){
		std::cout << "Returning B\n";
		return new B();
	}
	else{
		std::cout << "Returning C\n";
		return new C();
	}
}

void Base::identify(Base *p)
{
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "*p identify: A\n";
	if (b)
		std::cout << "*p identify: B\n";
	if (c)
		std::cout << "*p identify: C\n";
}

void Base::identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "&p identify: A\n";
	}
	catch(const std::exception& e)
	{
		try
		{
			B b = dynamic_cast<B&>(p);
			std::cout << "&p identify: B\n";
		}
		catch(const std::exception& e)
		{
			std::cout << "&p identify: C\n";
		}

	}

}
