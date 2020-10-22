#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *_weapon;
		std::string	const &_name;
	public:
		HumanB(std::string const &name);
		~HumanB(void);
		void attack(void) const;
		void setWeapon(Weapon &weapon);
};

#endif
