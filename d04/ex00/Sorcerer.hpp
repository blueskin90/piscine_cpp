#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer {
	public:
		Sorcerer& operator=(Sorcerer const &rhs);

		Sorcerer(std::string const &name, std::string const &title);
		Sorcerer(Sorcerer const &src);
		~Sorcerer(void);

		void polymorph(Victim const & victim) const;
		std::string const getName(void) const;
		std::string const getTitle(void) const;
	private:
		Sorcerer(void);
		std::string const _name;
		std::string const _title;
};

std::ostream& operator<< (std::ostream &output, Sorcerer const &sorc);
#endif
