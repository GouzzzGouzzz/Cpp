#pragma once
#include <iostream>

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain();
	~Brain();
	Brain& operator=(const Brain &copy);
};
