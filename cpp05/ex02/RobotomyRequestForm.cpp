#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

//Constructor / destructor

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{
	std::cout << "RobotomyForm has been created\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &obj) : AForm(obj.getName()+"_copy", 72, 45)
{
	std::cout << "RobotomyForm has been created(copy constructor)\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &obj)
{
	std::cout << "RobotomyForm has been created (copy assignement)\n";
	(void) obj;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyForm has been destroyed\n";
}

//Functions

void RobotomyRequestForm::exec() const
{
	srand(time(NULL));
	if (rand() % 2 == 1)
		std::cout << this->getName() << " has been robotomized succesfully\n";
	else
		std::cout << this->getName() << " robotomy failed, sadly\n";
}
