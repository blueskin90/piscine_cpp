#include <string>
#include <iostream>

int		main(void)
{
	std::string const s("HI THIS IS BRAIN");
	std::string const *s_ptr = &s;
	std::string const &s_ref = s;

	std::cout << *s_ptr << std::endl;
	std::cout << s_ref << std::endl;
	return (0);
}
