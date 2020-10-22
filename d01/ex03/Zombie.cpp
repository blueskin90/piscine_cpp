#include "Zombie.hpp"

Zombie::Zombie(void) : _type("Horde")
{
	std::string			name;
	std::string const	first_syllabs[13] = 
		{
			"Aba", "Cho", "Gob", "Kar", "Rul", "Pip", "Naz", "Az", "Rul", "Nok", "Dag", "Piz", "Zil" 
		};
	std::string const	second_syllab[11] =
		{
			"bis", "tal", "nik", "tip", "tog", "kol", "pit", "yap", "mat", "ham", "gub"
		};
	name = first_syllabs[rand() % 13] + second_syllab[rand() % 11];
	this->_name = name;
	std::cout << "<" << this->_name << " (" << this->_type << ")> Rises from the deads !" << std::endl;
}

Zombie::Zombie(std::string const &name, std::string const &type) : _name(name), _type(type)
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Rises from the deads !" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Returns to rest" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss ..." << std::endl;
}
