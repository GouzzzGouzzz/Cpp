#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

//Constructo / destructor

Intern::Intern()
{
	std::cout << "Intern has been created\n";
}

Intern::Intern(Intern &obj)
{
	(void) obj;
	std::cout << "Intern has been created(copy constructor)\n";
	Intern();
}

Intern& Intern::operator=(Intern &obj)
{
	std::cout << "Intern has been created (copy assignement)\n";
	*this = obj;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern has been destroyed \n";
}

//Function

AForm* Intern::makeForm(std::string formName, std::string target) const
{
	int request = -1;
	std::string form[3] = {"robotomy request","presidential request","shrubbery request"};
	for(int i = 0; i < 3; i++)
		if (form[i] == formName)
			request = i+1;
	switch (request)
	{
	case 1:
		return (new RobotomyRequestForm(target));
		break;
	case 2:
		return (new PresidentialPardonForm(target));
		break;
	case 3:
		return (new ShrubberyCreationForm(target));
		break;
	default:
		std::cout << "Invalid request ! (returning NULL)\n";
		return NULL;
		break;
	}
}
