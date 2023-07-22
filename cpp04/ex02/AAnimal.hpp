#pragma once
# include <iostream>

class AAnimal
{
protected:
	std::string _type;
public:
	AAnimal();
	AAnimal(const AAnimal &copy);
	virtual ~AAnimal();
	std::string getType() const;
	void setType(std::string new_type);
	virtual void makeSound() const = 0;
	AAnimal& operator=(const AAnimal &copy);
};
