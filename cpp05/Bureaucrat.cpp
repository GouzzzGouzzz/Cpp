#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException;
	this->grade = grade;
	std::cout << "A bureaucrat has been created\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A bureaucrat has been deleted\n";
}

int	Bureaucrat::getGrade() {return (this->grade);}
std::string Bureaucrat::getName() { return (this->name);}

void Bureaucrat::increaseGrade()
{
	if (this->grade < 1)
		this->grade--;
	else
		throw Bureaucrat::GradeTooHighException;
}

void Bureaucrat::decreaseGrade()
{
	if (this->grade < 150)
		this->grade++;
	else
		throw Bureaucrat::GradeTooLowException;
}

/*
Bureaucrat(const Bureaucrat &copy);
Bureaucrat &operator=(const Bureaucrat &copy); */
