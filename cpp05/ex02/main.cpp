#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	RobotomyRequestForm test("RobotomyTest");
	Bureaucrat bob("bob",50);
	ShrubberyCreationForm test2("ShrubTest");
	PresidentialPardonForm test3("PatronTest");
	std::cout << "\nException test for form\n\n";
	bob.executeForm(test);
	bob.signForm(test);
	bob.executeForm(test);
	for (int i = 0; i < 15; i++)
		bob.increaseGrade();
	bob.executeForm(test);
	bob.signForm(test2);
	bob.executeForm(test2);
	bob.signForm(test3);
	bob.executeForm(test3);
	for (int i = 0; i < 33; i++)
		bob.increaseGrade();
	std::cout << bob << "bob can now sign and execute the president form\n";
	bob.signForm(test3);
	bob.executeForm(test3);
	std::cout << "\nEND OF MAIN\n";
}
