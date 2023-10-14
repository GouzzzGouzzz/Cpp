#pragma once
#include "Data.hpp"
#include <iostream>
 #include <stdint.h>

class Serialize
{
private:
	/* data */
public:
	Serialize(/* args */);
	Serialize(Serialize &copy);
	Serialize& operator=(const Serialize &copy);
	~Serialize();

	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};

