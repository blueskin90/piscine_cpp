#include <iostream>

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert argumentToConvert" << std::endl;
		return (1);
	}
	(void)av;

	return (0);
}
