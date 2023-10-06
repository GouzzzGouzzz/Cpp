#include "Bureaucrat.hpp"

//Constructor / destructor

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();

	this->grade = grade;
	std::cout << "A bureaucrat has been created\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A bureaucrat has been deleted\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->grade = copy.grade;
	return *this;
}

//Exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade is too high\n"; }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade is too low\n"; }
int	Bureaucrat::getGrade() {return (this->grade);}
std::string Bureaucrat::getName() { return (this->name);}

void Bureaucrat::increaseGrade()
{
	if (this->grade < 1)
		this->grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade()
{
	if (this->grade < 150)
		this->grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

// Additional overload

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
