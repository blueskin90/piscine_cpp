#ifndef ENERGYSWORD_HPP
#define ENERGYSWORD_HPP

#include "AWeapon.hpp"

class EnergySword : public AWeapon
{
	public:
		EnergySword(void);
		~EnergySword(void);

		void attack() const;
};


#endif /* ENERGYSWORD_HPP */
