#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon const &_weapon;
		std::string	const &_name;
	public:
		HumanA(std::string const &name, Weapon const &weapon);
		~HumanA(void);
		void attack(void) const;
};

#endif
