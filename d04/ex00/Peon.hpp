#ifndef PEON_HPP
# define PEON_HPP
#include <iostream>
#include "Victim.hpp"

class Peon : public Victim{
	public:
		Peon& operator=(Peon const &rhs);

		Peon(std::string const &name);
		Peon(Peon const &src);
		~Peon(void);

		void	getPolymorphed(void) const;
	private:
		Peon(void);

};
#endif
