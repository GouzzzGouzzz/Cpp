#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("test", 150);
	std::cout << a.getGrade() << "    " << a.getName() << "\n";
	a.decreaseGrade();
	std::cout << a.getGrade() << "    " << a.getName() << "\n";
	a.increaseGrade();
	std::cout << a.getGrade() << "    " << a.getName() << "\n";
}
