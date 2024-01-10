#include "BitcoinExchange.hpp"

int main(int ac, char **ag)
{
	if (ac != 2)
	{
		std::cout << "1 paramater is needed, not more, not less !\n";
		return -1;
	}
	BitcoinExchange truc;
	truc.operate(ag[1]);
}
