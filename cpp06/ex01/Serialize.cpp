#include "Serialize.hpp"

//Constructor

Serialize::Serialize()
{
	std::cout << "Serialize constructor called\n";
}

Serialize::Serialize(Serialize &copy)
{
	std::cout << "Serialize constructor called (copy constructor)\n";
	(void) copy;
}

Serialize& Serialize::operator=(const Serialize &copy)
{
	std::cout << "Serialize constructor called (copy assignement)\n";
	(void)copy;
	return *this;
}

Serialize::~Serialize()
{
	std::cout << "Serialize destructor called\n";
}

//Functions

uintptr_t Serialize::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
