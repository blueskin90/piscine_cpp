#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
	public :
		FragTrap(void);
		FragTrap(FragTrap const &src);
		FragTrap(std::string name);
		~FragTrap(void);

		FragTrap & operator=(FragTrap const &rhs);
		void				rangedAttack(std::string const &target) const;
		void				meleeAttack(std::string const &target) const;
		void				vaulthunter_dot_exe(std::string const &target);
};

#endif
