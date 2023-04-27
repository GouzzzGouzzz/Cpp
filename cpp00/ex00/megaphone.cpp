#include <iostream>
#include <cstring>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	char *t = argv[1];
	for (int x = 0; x < strlen(t); x++)
		std::cout << (char)toupper(t[x]);
	std::cout << "\n";
	return (0);
}
