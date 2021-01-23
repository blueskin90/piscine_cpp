#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap : public ClapTrap{
	public :
		NinjaTrap(void);
		NinjaTrap(NinjaTrap const &src);
		NinjaTrap(std::string name);
		~NinjaTrap(void);

		NinjaTrap & operator=(NinjaTrap const &rhs);
		
		void				ninjaShoebox(ScavTrap const &target) const;
		void				ninjaShoebox(FragTrap const &target) const;
		void				ninjaShoebox(NinjaTrap const &target) const;
};

#endif
