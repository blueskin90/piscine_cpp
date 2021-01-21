#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>

class ScavTrap {
	public :
		ScavTrap(void);
		ScavTrap(ScavTrap const &src);
		ScavTrap(std::string name);
		~ScavTrap(void);


		static unsigned int const	maxhp = 100;
		static unsigned int const	maxep = 100;

		ScavTrap & operator=(ScavTrap const &rhs);
		
		void				rangedAttack(std::string const &target) const;
		void				meleeAttack(std::string const &target) const;
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		void				challengeNewcomer(std::string const &target);

		unsigned int		getHp(void) const;
		unsigned int		getEp(void) const;
		unsigned int		getLevel(void) const;
		std::string const	&getName(void) const;
		unsigned int		getMeleeDamage(void) const;
		unsigned int		getRangedDamage(void) const;
		unsigned int		getArmorReduc(void) const;
	private :
		unsigned int		_hp;
		unsigned int		_ep;
		unsigned int		_level;
		std::string			_name;
		unsigned int		_meleeDamage;
		unsigned int		_rangedDamage;
		unsigned			_armorReduc;
};

#endif
