#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public :
		ScavTrap(void);
		ScavTrap(ScavTrap const &src);
		ScavTrap(std::string name);
		~ScavTrap(void);

		ScavTrap & operator=(ScavTrap const &rhs);
		
		void				challengeNewcomer(std::string const &target);
};

#endif
