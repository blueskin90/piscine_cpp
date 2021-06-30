#include <iostream> 

void	findclosing(std::string str, int *i)
{
	int		counter = 0;

	while (str[*i] && *i > -1 && *i < 255)
	{
		if (str[*i] == '[')
			counter++;
		else if (str[*i] == ']')
			counter--;
		if (counter == 0)
			break;
		(*i)++;
	}
}

void	findopening(std::string str, int *i)
{
	int		counter = 0;

	while (str[*i] && *i > -1 && *i < 255)
	{
		if (str[*i] == ']')
			counter++;
		else if (str[*i] == '[')
			counter--;
		if (counter == 0)
			break;
		(*i)--;
	}
}

void	brainfuck(std::string str)
{
	int		i;
	char	mem[255];
	int		memptr;

	bzero(mem, 255 * sizeof(char));

	i = 0;
	memptr = 0;
	while (str[i])
	{
		if (str[i] == '>')
			memptr++;
		else if (str[i] == '<')
			memptr--;
		else if (str[i] == '+')
			mem[memptr]++;
		else if (str[i] == '-')
			mem[memptr]--;
		else if (str[i] == '.')
			std::cout << mem[memptr];
		else if (str[i] == ',')
			std::cin.get(mem + memptr, 1);
		else if (str[i] == '[' && mem[memptr] == 0)
			findclosing(str, &i);
		else if (str[i] == ']' && mem[memptr] != 0)
			findopening(str, &i);
		i++;
	}
}

int		main(void)
{
	std::string str = "++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>>.<---.>+++++++++++.-----------.+.<<++.>-.>+++++++++++++.-----------------.++++++++.+++++.--------.+++++++++++++++.------------------.++++++++.";
	brainfuck(str);
	return (1);
}
