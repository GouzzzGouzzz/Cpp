#include "iter.hpp"

int main()
{
	int tab[] = {0,1,2,3,4,5,6,7,8,9};
	int len = 10;
	std::string tab2[] = {"This", "is", "an", "array", "of","strings"};
	iter(tab,len, &print);
	std::cout << std::endl;
	iter(tab2,6, &print);
	std::cout << std::endl;
}
