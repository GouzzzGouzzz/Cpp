#include "ShrubberyCreationForm.hpp"
#include <fstream>
//Constructor / destructor

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &obj) : AForm(obj.getName()+"_copy", 72, 45)
{
	std::cout << "ShrubberyCreationForm has been created(copy constructor)\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &obj)
{
	std::cout << "ShrubberyCreationForm has been created (copy assignement)\n";
	(void) obj;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

//Function

void ShrubberyCreationForm::exec() const
{
	std::string name = this->getName()+"_shrubbery";
	std::ofstream file(name.c_str());
	for (int i = 0; i < 3; i++)
	{
		file << "     ccee88oo\n"
			<< "  C0O0O0Q0PoOb o8oo\n"
			<< " dOB69QO8PdUOpugoO9bD\n"
			<< " CgggbU8OU qOp qOdoUOdcb\n"
			<< "	 6OuU  /p u gcoUodpP\n"
			<< "	  |--//  /douUP\n"
			<< "		|///\n"
			<< "  		||||\n"
			<< "  		||||\n"
			<< "  		||||\n"
			<<" .....//|||||....\n\n";
	}
	file.close();
	std::cout << "Shrubbery form execution finished !\n";
}
