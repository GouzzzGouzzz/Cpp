#include <iostream>
#include <cstring>

int	main(int argc, char **argv)
{
	int	i;
	std::string c = "";
	i = 0;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
 	while (i++ < argc - 1)
		c.append(argv[i]);
	for (int j = 0; j < c.length(); j++)
		std::cout << (char)toupper(c[j]);
	std::cout << std::endl;
	return (0);
}
