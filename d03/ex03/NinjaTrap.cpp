#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap("unnamed", 60, 120, 1, 60, 5, 0)
{
	std::srand(time(NULL));
	std::cout << "unflavored N1NJ4-TP was born, now with 0% naming !" << std::endl ;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) : ClapTrap(src)
{
	std::srand(time(NULL));
	std::cout << "N1NJ4-TP " << src.getName() << " was cloned ! More shadows to come !" << std::endl ;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name, 60, 120, 1, 60, 5, 0)
{
	std::srand(time(NULL));
	std::cout << "N1N J4-TP " << name << " is born from the shadows." << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "N1NJ4-TP " << this->_name << " met a staircase" << std::endl;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs) {
	this->_name					= rhs.getName();
	this->_hp					= rhs.getHp();
	this->_ep					= rhs.getEp();
	this->_level				= rhs.getLevel();
	this->_meleeDamage			= rhs.getMeleeDamage();
	this->_rangedDamage			= rhs.getRangedDamage();
	this->_armorReduc			= rhs.getArmorReduc();
	return (*this);
}
		
void			NinjaTrap::ninjaShoebox(ScavTrap const &target) const
{
	std::cout << "N1NJ4-TP " << this->_name << " empty its trash on " << target.getName() << std::endl;
}

void			NinjaTrap::ninjaShoebox(FragTrap const &target) const
{
	std::cout << "N1NJ4-TP " << this->_name << " trades blows with " << target.getName() << std::endl;
}

void			NinjaTrap::ninjaShoebox(NinjaTrap const &target) const
{
	std::cout << "N1NJ4-TP " << this->_name << " trains for katana fight with " << target.getName() << std::endl;
}
