#include "FixedClass.hpp"

int main( void ) {
	Fixed a(2.2f);
	Fixed b(3);
	Fixed c(2.2f);
	Fixed d(0);

	std::cout << "\n\nTesting comparison operator :\n\n" <<std::endl;
	std::cout << (a > b) << "	(a>b)" << std::endl;		//0
	std::cout << (a < b) << "	(a<b)" << std::endl;		//1
	std::cout << (a == b)<< "	(a==b)"  << std::endl;		//0
	std::cout << (a == c)<< "	(a==c)"  << std::endl;		//1
	std::cout << (a != b)<< "	(a!=b)"  << std::endl;		//1
	std::cout << (a >= b)<< "	(a>=b)"  << std::endl;		//0
	std::cout << (a <= b)<< "	(a>=b)"  << std::endl;		//1
	std::cout << "\n\nTesting arithmetic operator :\n\n" <<std::endl;
	std::cout << (a + b) << "	(a+b)" << std::endl;					//5.2
	std::cout << (a - b) << "	(a-b)" <<std::endl;					//-0.8
	std::cout << (a * b) << "	(a*b)" <<std::endl;					//6.6
	std::cout << (a / b) << "	(a/b)" <<std::endl;					//0.7333
	std::cout << (a / 0) << "	(a/0)" << std::endl;					//--> display an error
	std::cout << (d / a) << "	(d/a) with d = 0" << std::endl;		//--> display an error
	std::cout << "\n\nTesting increment operator :\n\n" <<std::endl;
	std::cout << ++d << "	++d" << std::endl;
	std::cout << d << "	d" << std::endl;
	std::cout << d++ << "	d++" << std::endl;
	std::cout << --d << "	--d" << std::endl;
	std::cout << d-- << "	d--" << std::endl;
	std::cout << d << "		d" << std::endl;

	std::cout << "\n\nTesting function\n\n" << std::endl;
return 0;
}
