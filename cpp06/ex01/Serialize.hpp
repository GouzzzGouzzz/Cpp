#pragma once
#include "Data.hpp"
#include <iostream>
 #include <stdint.h>

class Serialize
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
private:
	Serialize();
	Serialize(Serialize &copy);
	Serialize& operator=(const Serialize &copy);
	~Serialize();
};

