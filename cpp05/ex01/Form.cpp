#include "Form.hpp"
#include "Bureaucrat.hpp"
//Constructor / destructor

Form::Form(const std::string name, const int sign, const int exec) : _name(name), _is_signed(false), _grade_sign(sign), _grade_exec(exec)
{
	if (sign < 1 || exec < 1)
		throw Form::GradeTooHighException();
	if (sign > 150 || exec > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form has been created\n";
}

Form::Form(const Form &copy) : _name(copy._name), _is_signed(copy._is_signed), _grade_sign(copy._grade_sign), _grade_exec(copy._grade_exec)
{
	std::cout << "A form has been created (copy constructor)";
}

Form& Form::operator=(const Form &copy)
{
	this->_is_signed = copy._is_signed;
	std::cout << "A form has been created, only is_signe has been copied, other are constant (copy assignement)";
	return *this;
};


Form::~Form()
{
	std::cout << "Form has been deleted\n";
}
//Exception

const char *Form::GradeTooHighException::what() const throw() { return "(Form) Grade is too high\n"; }
const char *Form::GradeTooLowException::what() const throw() { return "(Form) Grade is too low\n"; }

//Getter

std::string Form::getName() { return this->_name; }
bool Form::getSigned() { return this->_is_signed; }
int Form::getExecGrade() {return this->_grade_exec; }
int Form::getSignGrade() {return this->_grade_sign; }

//Function

void Form::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() <= this->_grade_sign)
		this->_is_signed = true;
	else
		throw Form::GradeTooLowException();
}

//Additional Overload

std::ostream& operator<<(std::ostream& os, Form& obj)
{
	os << "Form : " << obj.getName() << "\n"
	<< "| executable at  : " << obj.getExecGrade() << "\n"
	<< "| can be sign at : " << obj.getSignGrade() << "\n"
	<< "| is signed      : " << obj.getSigned() << "\n";
	return os;
}
