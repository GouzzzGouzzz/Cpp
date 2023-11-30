#include "Array.hpp"

int main()
{
	Array<int> test;
	Array<int> test2(10);
	Array<int> test3;

	test = test2;
	test3 = test;
	Array<int> test4(test2);
	test[0] = 42;
	try
	{
		std::cout << "No exception will be thrown\n";
		test4[4] = test[0] + 42;
		std::cout << test4[4];
		test[3] = 42;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\n||| An exception will be thrown ||| \n";
		test[13] = 42;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << test[0] << "\n";
}
