#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	public :
		ClapTrap & operator=(ClapTrap const &rhs);
		
		void				rangedAttack(std::string const &target) const;
		void				meleeAttack(std::string const &target) const;
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		unsigned int		getHp(void) const;
		unsigned int		getMaxHp(void) const;
		unsigned int		getEp(void) const;
		unsigned int		getMaxEp(void) const;
		unsigned int		getLevel(void) const;
		std::string const	&getName(void) const;
		unsigned int		getMeleeDamage(void) const;
		unsigned int		getRangedDamage(void) const;
		unsigned int		getArmorReduc(void) const;
	protected :
		ClapTrap(void);
		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);
		ClapTrap(std::string name, int maxhp, int maxep, unsigned int level, unsigned int meleeDamage, unsigned int rangedDamage, unsigned int armorReduc);

		unsigned int const	_maxhp;
		unsigned int const	_maxep;
		unsigned int		_hp;
		unsigned int		_ep;
		unsigned int		_level;
		std::string			_name;
		unsigned int		_meleeDamage;
		unsigned int		_rangedDamage;
		unsigned			_armorReduc;
};

#endif
