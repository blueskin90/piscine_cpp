#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void): Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Break everything!" << std::endl;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
	damage -= 3;
	if (damage < 0)
		return;
	if (this->_hp <= damage)
		this->_hp = 0;
	else
		this->_hp -= damage;
}
