#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) : ClapTrap("unnamed", 100, 120, 1, 60, 20, 5)
{
	std::srand(time(NULL));
	std::cout << "unflavored SUP3R-TP was born, now with 0% naming !" << std::endl ;
}

SuperTrap::SuperTrap(SuperTrap const &src) : ClapTrap(src)
{
	std::srand(time(NULL));
	std::cout << "SUP3R-TP " << src.getName() << " was cloned ! Prepare for trouble, and make it double !" << std::endl ;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name, 100, 120, 1, 60, 20, 5)
{
	std::srand(time(NULL));
	std::cout << "SUP3R-TP " << name << " was born, fear him mere mortals, for he does not fear death !" << std::endl;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SUP3R-TP " << this->_name << " is dieing, and with it, humanity's hope :'(" << std::endl;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &rhs) {
	this->_name					= rhs.getName();
	this->_hp					= rhs.getHp();
	this->_ep					= rhs.getEp();
	this->_level				= rhs.getLevel();
	this->_meleeDamage			= rhs.getMeleeDamage();
	this->_rangedDamage			= rhs.getRangedDamage();
	this->_armorReduc			= rhs.getArmorReduc();
	return (*this);
}
