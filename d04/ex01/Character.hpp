#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	private:
			std::string const _name;
			int	const _APmax;
			int _AP;
			AWeapon	*_weapon;
			Character(void);
	public:
			Character& operator=(Character const &rhs);
			Character(std::string const & name);
			Character(Character const &src);
			~Character(void);

			void equip(AWeapon* weapon);
			void attack(Enemy* ennemy);
			void recoverAP(void);
			int getAP(void) const;
			std::string getName(void) const;
			AWeapon	*getWeapon(void) const;
};

std::ostream& operator<< (std::ostream &output, Character const &character);
#endif
