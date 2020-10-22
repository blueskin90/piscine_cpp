#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
	srand(time(NULL));
	srand(rand());
}

ZombieEvent::~ZombieEvent(void)
{
}

void	ZombieEvent::setZombieType(std::string const &type)
{
	this->_type = type;
}

Zombie* ZombieEvent::newZombie(std::string const &name) const
{
	return (new Zombie(name, this->_type));
}

Zombie*	ZombieEvent::randomChump(void) const
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
	Zombie	*randomZombie;

	name = first_syllabs[rand() % 13] + second_syllab[rand() % 11];
	randomZombie = this->newZombie(name);
	randomZombie->announce();
	return(randomZombie);
}
