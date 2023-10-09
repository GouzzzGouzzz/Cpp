#include "AForm.hpp"
#include "Bureaucrat.hpp"
//Constructor / destructor

AForm::AForm(const std::string name, const int sign, const int exec) : _name(name), _is_signed(false), _grade_sign(sign), _grade_exec(exec)
{
	if (sign < 1 || exec < 1)
		throw AForm::GradeTooHighException();
	if (sign > 150 || exec > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Form has been created\n";
}

AForm::AForm(const AForm &copy) : _name(copy._name), _is_signed(copy._is_signed), _grade_sign(copy._grade_sign), _grade_exec(copy._grade_exec)
{
	std::cout << "A form has been created (copy constructor)";
}

AForm& AForm::operator=(const AForm &copy)
{
	this->_is_signed = copy._is_signed;
	std::cout << "A form has been created, only is_signe has been copied, other are constant (copy assignement)";
	return *this;
};


AForm::~AForm()
{
	std::cout << "Form has been deleted\n";
}
//Exception

const char *AForm::GradeTooHighException::what() const throw() { return "(Form) Grade is too high\n"; }
const char *AForm::GradeTooLowException::what() const throw() { return "(Form) Grade is too low\n"; }
const char *AForm::NotSignedException::what() const throw() { return "(Form) Form is not signed\n"; }
//Getter

const std::string AForm::getName() const { return this->_name; }
bool AForm::getSigned() { return this->_is_signed; }
int AForm::getExecGrade() {return this->_grade_exec; }
int AForm::getSignGrade() {return this->_grade_sign; }

//Function

void AForm::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() <= this->_grade_sign)
		this->_is_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (this->_is_signed == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->_grade_exec)
		throw AForm::GradeTooLowException();
	this->exec();
}

//Additional Overload

std::ostream& operator<<(std::ostream& os, AForm& obj)
{
	os << "Form : " << obj.getName() << "\n"
	<< "| executable at  : " << obj.getExecGrade() << "\n"
	<< "| can be sign at : " << obj.getSignGrade() << "\n"
	<< "| is signed      : " << obj.getSigned() << "\n";
	return os;
}
