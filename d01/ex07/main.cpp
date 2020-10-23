#include "sed.hpp"

void		usage(void)
{
	std::cout << "usage: ./replace inputfile string_to_replace_from string_to_replace_with" << std::endl;
}

bool		checkempty(char **av)
{
	bool	empty = false;

	for (int i = 1; i < 4; i++)
	{
		if (strlen(av[i]) == 0)
		{
			std::cout << (i == 1 ? "File path" : (i == 2 ? "String to replace from" : "String to replace with")) << " can't be empty !" << std::endl;
			empty = true;
		}
	}
	return (empty);
}

bool		get_file(char *filePath, std::string &dest)
{
	std::ifstream	file(filePath);
	char			*buffer;
	size_t			size;

	if (!file.is_open())
	{
		std::cout << "couldn't open file: " << filePath << std::endl;
		return (false);
	}
	file.seekg(0, file.end);
	size = file.tellg();
	file.seekg(0, file.beg);
	buffer = new char[size + 1];
	file.read(buffer, size);
	file.close();
	buffer[size] = '\0';
	dest = buffer;
	delete[] buffer;
	return (true);
}

void		write_to_file(std::string const &content, std::string const &filePath)
{
	std::ofstream	file(filePath);

	if (!file.is_open())
	{
		std::cout << "couldn't open file: " << filePath << " to write to.";
		return;
	}
	file << content;
	file.close();
}

void		replace(std::string &file_parsed, char* file_path, char* str1, char* str2)
{
	std::string s1(str1);
	std::string s2(str2);
	std::string	f_path(file_path);
	size_t		pos;
   
	pos	= file_parsed.find(s1, 0);
	while (pos != (size_t)-1 && pos != file_parsed.length())
	{
		file_parsed.replace(pos, s1.length(), s2);
		pos	= file_parsed.find(s1, pos + s2.length());
	}
	write_to_file(file_parsed, f_path + ".replace");
}

int			main(int ac, char **av)
{
	std::string my_file;

	if (ac != 4)
	{
		usage();
		return (1);
	}
	if (checkempty(av))
		return(-1);
	if (!get_file(av[1], my_file))
		return (-2);
	replace(my_file, av[1], av[2], av[3]);
	return (0);
}
