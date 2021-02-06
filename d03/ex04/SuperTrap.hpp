#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include <iostream>

#include "NinjaTrap.hpp"
#include "FragTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap{
	public :
		SuperTrap(void);
		SuperTrap(SuperTrap const &src);
		SuperTrap(std::string name);
		~SuperTrap(void);

		SuperTrap & operator=(SuperTrap const &rhs);	
		using FragTrap::rangedAttack;
		using NinjaTrap::meleeAttack;
};

#endif
