#include "Bureaucrat.hpp"
#include "Form.hpp"
//Constructor / destructor

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();

	this->_grade = grade;
	std::cout << "A bureaucrat has been created\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A bureaucrat has been deleted\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "A bureaucrat has been created (copy constructor)";
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "A bureaucrat has been created (copy assignement)";
	this->_grade = copy._grade;
	return *this;
}

//Exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade is too high\n"; }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade is too low\n"; }
int	Bureaucrat::getGrade() {return (this->_grade);}
std::string Bureaucrat::getName() { return (this->_name);}

//Functions

void Bureaucrat::increaseGrade()
{
	if (this->_grade < 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade()
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form &obj)
{
	if (obj.getSigned() == true)
		std::cout << this->_name << " couldn’t sign " << obj.getName()  << " because it is already signed\n";
	else
	{
		try
		{
			obj.beSigned(*this);
			std::cout << this->_name << " signed " << obj.getName() << "\n";
		}
		catch(std::exception &e)
		{
			std::cerr << this->_name << " couldn’t sign " << obj.getName()  << " because : ";
			std::cerr << e.what() << '\n';
		}
	}
}

// Additional overload

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "\n";
	return os;
}
