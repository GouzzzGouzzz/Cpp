#include <iostream>
#include <cstring>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	std::string c = "";
	i = 0;
	j = 0;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNHEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
 	while (i++ < argc)
	{
		c.append(argv[i]);
		std::cout << c << std::endl;
	}
	std::cout << c << std::endl;
	return (0);
}
