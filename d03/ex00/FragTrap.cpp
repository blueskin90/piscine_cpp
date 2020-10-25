#include "FragTrap.hpp"

FragTrap::FragTrap(void) : _hp(100), _ep(100), _level(1), _name("Unnamed"), _meleeDamage(30), _rangedDamage(20), _armorReduc(5)
{
	std::srand(time(NULL));
	std::cout << "unflavored FR4G-TP was born, now with 0% naming !" << std::endl ;
}

FragTrap::FragTrap(FragTrap const &src) : _hp(src.getHp()), _ep(src.getEp()), _level(src.getLevel()), _name(src.getName()), _meleeDamage(src.getMeleeDamage()), _rangedDamage(getRangedDamage()), _armorReduc(src.getArmorReduc())
{
	std::srand(time(NULL));
	std::cout << "FR4G-TP " << src.getName() << " was cloned ! Prepare for trouble, and make it double !" << std::endl ;
}

FragTrap::FragTrap(std::string name) : _hp(100), _ep(100), _level(1), _name(name), _meleeDamage(30), _rangedDamage(20), _armorReduc(5)
{
	std::srand(time(NULL));
	std::cout << "FR4G-TP " << name << " was born, fear him mere mortals, for he does not fear death !" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FR4G-TP " << this->_name << " met a staircase" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
	this->_name					= rhs.getName();
	this->_hp					= rhs.getHp();
	this->_ep					= rhs.getEp();
	this->_level				= rhs.getLevel();
	this->_meleeDamage			= rhs.getMeleeDamage();
	this->_rangedDamage			= rhs.getRangedDamage();
	this->_armorReduc			= rhs.getArmorReduc();
	return (*this);
}

void			FragTrap::rangedAttack(std::string const &target) const
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " from range, dealing " << this->_rangedDamage << " damages, legend says " << target << " can still feel it when it's rainy !"  << std::endl;
}

void			FragTrap::meleeAttack(std::string const &target) const
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " up close and personnal, dealing " << this->_meleeDamage << " vicious damages." << std::endl;
}

void			FragTrap::takeDamage(unsigned int amount)
{
	if (amount < this->_armorReduc)
	{
		std::cout << "FR4G-TP " << this->_name << " was hit with a hit so weak he didn't even notice" << std::endl ;  
		return ;
	}
	std::cout << "FR4G-TP " << this->_name << " was at " << this->_hp << " and took " << amount << " damages (minus armor : " << this->_armorReduc << ") which causes him to be at : ";  
	if (this->_hp < (amount - this->_armorReduc))
		this->_hp = 0;
	else
		this->_hp -= (amount - this->_armorReduc);
	std::cout << this->_hp << " HPs, nothing but a scratch, mere mortals !" << std::endl;
}

void			FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FR4G-TP " << this->_name << " was at " << this->_hp << " and repaired " << amount << " damages ! which causes him to be at : ";  
	if (amount > FragTrap::maxhp || (this->_hp + amount) > FragTrap::maxhp)
		this->_hp = 100;
	else
		this->_hp += amount;
	std::cout << this->_hp << " he is more powerful than ever, fly you fools !" << std::endl;
}

void			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string attacks[5] = { " Throws a Nokia 3310 at " + target, " Fart on "+ target, " Stab " + target + " with a pencil, John Wick style,", " empty its oil in " + target + " eyes", " dance like crazy in front of " + target};
	unsigned int damages[5] = { 100000, 1, 35, 15, 0};
	unsigned int rand;
   
	rand = std::rand() % 5;
	if (this->_ep < 25)
	{
		std::cout << "You don't have enough energy to operate an attack." << std::endl;
		return ;
	}
	this->_ep -= 25;
	std::cout << this->_name << ": \"Behold my MIGHTIEST ATTACK !\" ";
	std::cout << this->_name << attacks[rand] << " causing " << damages[rand] << " damages";
	if (rand == 4)
		std::cout << ", but looking so darn hot";
	std::cout << "." << std::endl;
}

unsigned int	FragTrap::getHp(void) const
{
	return (this->_hp);
}

unsigned int	FragTrap::getEp(void) const
{
	return (this->_ep);
}

unsigned int	FragTrap::getLevel(void) const
{
	return (this->_level);
}

std::string	const	&FragTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	FragTrap::getMeleeDamage(void) const
{
	return (this->_meleeDamage);
}

unsigned int	FragTrap::getRangedDamage(void) const
{
	return (this->_rangedDamage);
}

unsigned int	FragTrap::getArmorReduc(void) const
{
	return (this->_armorReduc);
}
