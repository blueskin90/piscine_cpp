#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :_maxhp(80), _maxep(80), _hp(80), _ep(80), _level(1), _name("Unnamed"), _meleeDamage(30), _rangedDamage(20), _armorReduc(5)
{
	std::srand(time(NULL));
	std::cout << "unflavored FR4G-TP was born, now with 0% naming !" << std::endl ;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _maxhp(src.getMaxHp()), _maxep(src.getMaxEp()), _hp(src.getHp()), _ep(src.getEp()), _level(src.getLevel()), _name(src.getName()), _meleeDamage(src.getMeleeDamage()), _rangedDamage(getRangedDamage()), _armorReduc(src.getArmorReduc())
{
	std::srand(time(NULL));
	std::cout << "CL4P-TP " << src.getName() << " was cloned ! Prepare for trouble, and make it double !" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int maxhp, int maxep, unsigned int level, unsigned int meleeDamage, unsigned int rangedDamage, unsigned int armorReduc): _maxhp(maxhp), _maxep(maxep), _hp(maxhp), _ep(maxep), _level(level), _name(name), _meleeDamage(meleeDamage), _rangedDamage(rangedDamage), _armorReduc(armorReduc)
{
	std::srand(time(NULL));
	std::cout << "CL4P-TP " << name << " was born, fear him mere mortals, for he does not fear death !" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "CL4P-TP " << this->_name << " came back to mother factory." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	this->_name					= rhs.getName();
	this->_hp					= rhs.getHp();
	this->_ep					= rhs.getEp();
	this->_level				= rhs.getLevel();
	this->_meleeDamage			= rhs.getMeleeDamage();
	this->_rangedDamage			= rhs.getRangedDamage();
	this->_armorReduc			= rhs.getArmorReduc();
	return (*this);
}

void			ClapTrap::rangedAttack(std::string const &target) const
{
	std::cout << "CL4P-TP " << this->_name << " attacks " << target << " from range, dealing " << this->_rangedDamage << " damages, legend says " << target << " can still feel it when it's rainy !"  << std::endl;
}

void			ClapTrap::meleeAttack(std::string const &target) const
{
	std::cout << "CL4P-TP " << this->_name << " attacks " << target << " up close and personnal, dealing " << this->_meleeDamage << " vicious damages." << std::endl;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (amount < this->_armorReduc)
	{
		std::cout << "CL4P-TP " << this->_name << " was hit with a hit so weak he didn't even notice" << std::endl ;  
		return ;
	}
	std::cout << "CL4P-TP " << this->_name << " was at " << this->_hp << " and took " << amount << " damages (minus armor : " << this->_armorReduc << ") which causes him to be at : ";  
	if (this->_hp < (amount - this->_armorReduc))
		this->_hp = 0;
	else
		this->_hp -= (amount - this->_armorReduc);
	std::cout << this->_hp << " HPs, nothing but a scratch, mere mortals !" << std::endl;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "CL4P-TP " << this->_name << " was at " << this->_hp << " and repaired " << amount << " damages ! which causes him to be at : ";  
	if (amount > this->_maxhp || (this->_hp + amount) > this->_maxhp)
		this->_hp = 100;
	else
		this->_hp += amount;
	std::cout << this->_hp << " he is more powerful than ever, fly you fools !" << std::endl;
}

unsigned int	ClapTrap::getHp(void) const
{
	return (this->_hp);
}

unsigned int	ClapTrap::getEp(void) const
{
	return (this->_ep);
}

unsigned int	ClapTrap::getMaxHp(void) const
{
	return (this->_maxhp);
}

unsigned int	ClapTrap::getMaxEp(void) const
{
	return (this->_maxep);
}


unsigned int	ClapTrap::getLevel(void) const
{
	return (this->_level);
}

std::string	const	&ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getMeleeDamage(void) const
{
	return (this->_meleeDamage);
}

unsigned int	ClapTrap::getRangedDamage(void) const
{
	return (this->_rangedDamage);
}

unsigned int	ClapTrap::getArmorReduc(void) const
{
	return (this->_armorReduc);
}
