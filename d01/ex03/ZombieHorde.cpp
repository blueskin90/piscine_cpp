#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int value)
{

	srand(time(NULL));
	srand(rand());
	if (value <= 0)
	{
		std::cout << value << "is less than 1, defaulted to 1" << std::endl;
		value = 1;
	}
	this->_size = value;
	this->_zombies = new Zombie[value];
}

ZombieHorde::~ZombieHorde(void)
{
	delete[] this->_zombies;
}

void	ZombieHorde::announce(void) const
{
	for (int i = 0; i < this->_size; i++)
		this->_zombies[i].announce();
}
