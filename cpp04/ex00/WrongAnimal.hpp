#pragma once
#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	~WrongAnimal();
	void makeSound() const;
	void setType(std::string new_type);
	std::string getType() const;
	WrongAnimal& operator=(const WrongAnimal &copy);
	WrongAnimal(const WrongAnimal &copy);
};

