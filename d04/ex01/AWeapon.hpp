#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon
{
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const &src);
		virtual ~AWeapon(void);

		std::string getName(void) const;
		int getAPCost(void) const;
		int getDamage(void) const;

		virtual void attack() const = 0;

		AWeapon& operator=(AWeapon const &rhs);
	protected:
		AWeapon(void);

		int			_APcost;
		int			_damage;
		std::string	_name;
};

#endif
