#include "HumanB.hpp"

HumanB::HumanB(std::string const &name) : _weapon(NULL) ,_name(name)
{
}

HumanB::~HumanB(void)
{
}

void	HumanB::attack(void) const
{
	if  (this->_weapon != NULL)
		std::cout << this->_name << "attacks with his " << this->_weapon->getType() << std::endl;	
	else
		std::cout << this->_name << "attacks with his bare hands !" << std::endl;	
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
