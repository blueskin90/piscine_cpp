#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap : virtual public ClapTrap{
	public :
		NinjaTrap(void);
		NinjaTrap(NinjaTrap const &src);
		NinjaTrap(std::string name);
		~NinjaTrap(void);

		NinjaTrap & operator=(NinjaTrap const &rhs);
		
		void				rangedAttack(std::string const &target) const;
		void				meleeAttack(std::string const &target) const;
		void				ninjaShoebox(ScavTrap const &target) const;
		void				ninjaShoebox(FragTrap const &target) const;
		void				ninjaShoebox(NinjaTrap const &target) const;
		void				ninjaShoebox(ClapTrap const &target) const;
};

#endif
