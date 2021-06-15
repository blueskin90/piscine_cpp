#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>

int		main(int ac, char **av)
{
	std::string str;
	double	d_value;
	float	f_value;
	char	c = 0;
	int		i_value = 0;

	if (ac != 2)
	{
		std::cout << "Usage: ./convert argumentToConvert" << std::endl;
		return (1);
	}
	str = av[1];
	if (str.length() == 1 && !(str[0] >= '0' && str[0] <= '9'))
		d_value = static_cast<double>(str[0]);
	else
		d_value = atof(av[1]);

	std::cout << "char: ";
	if (std::isfinite(d_value) && d_value >= CHAR_MIN && d_value <= CHAR_MAX)
	{
		c = static_cast<char>(d_value);
		if (isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
		
	
	std::cout << "int: ";
	if (std::isfinite(d_value) && d_value >= INT_MIN && d_value <= INT_MAX)
	{
		i_value = static_cast<int>(d_value);
		std::cout << i_value << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;

	f_value = static_cast<float>(d_value);
	std::cout << std::fixed << std::setprecision(1) << "float: " << f_value << "f" << std::endl;	

	std::cout << std::fixed << std::setprecision(1) << "double: " << d_value << std::endl;
	
	return (0);
}
