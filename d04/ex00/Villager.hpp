#ifndef VILLAGER_HPP
#define VILLAGER_HPP

#include <iostream>
#include "Victim.hpp"

class Villager : public Victim{
	public:
		Villager& operator=(Villager const &rhs);

		Villager(std::string const &name);
		Villager(Villager const &src);
		~Villager(void);

		void	getPolymorphed(void) const;
	private:
		Villager(void);

};


#endif /* VILLAGER_HPP */
