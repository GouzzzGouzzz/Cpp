#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
private:

public:
	Cat();
	~Cat();
	void makeSound() const;
	Cat& operator=(const Cat &copy);
	Cat(const Cat &copy);
};
