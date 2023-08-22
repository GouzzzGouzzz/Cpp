# include "HarlClass.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Need args\n";
		return 0;
	}
	Harl test;
	test.complain(argv[1]);
}
