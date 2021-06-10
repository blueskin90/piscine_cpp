#include <iostream>
#include "Converter.hpp"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert argumentToConvert" << std::endl;
		return (1);
	}
	Converter converter(av[1]);
	converter.print();

	return (0);
}
